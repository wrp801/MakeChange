import argparse
from sys import argv
from argparse import ArgumentParser
from datetime import datetime
def get_max_val(dict_to_search:dict) -> str:
    """
    Returns the key of the max value of a dict
    """
    return max(dict_to_search,key = dict_to_search.get,default = 0) 

def print_map(dict_to_print:dict) -> None:
    d = {k:v for k,v in dict_to_print.items() if v != 0}
    for k,v in d.items():
        print(f"\t{k}: {v}")
    

def change(amt:float,print_to_screen = True):
    """
    This will make the optimal amount of change given the amount. The amount is represented in terms of dollars
    """
    mapping = {
        'Penny': 1,
        'Nickel': 5,
        'Dime': 10,
        'Quarter': 25,
        'Dollar1': 100,
        'Dollar5': 500,
        'Dollar10': 1000,
        'Dollar20': 2000,
        'Dollar50': 5000,
        'Dollar100': 10000
    }
    cent_val = amt * 1 ## convert the amount to cents to match the mapping
    change_amt = 0 
    change_map = {x:0 for x in mapping.keys()}

    while change_amt < cent_val:
        delta_amt = cent_val - change_amt ## the remaining balance of change that is due
        filtered = {k:v for k,v in mapping.items() if v <= delta_amt}
        max_key = get_max_val(filtered) ## the key of the max
        change_amt += mapping[max_key]
        change_map[max_key] += 1
    
    if print_to_screen:
        print_map(change_map)
        print("====================================")
    return change_amt

def read_args(file:str) -> list:
    # ret_list = []
    with open(file,'r') as f:
        line = f.read().split('\n')
    ret_list = list(map(lambda x: round(float(x),2),line)) 

    return list(map(lambda x: round(x * 100,0),ret_list))

def write_output(args:list) -> None:
    begin_time = datetime.now()
    for arg in args:
        change(arg,False)
    end_time = datetime.now()

    print(f"Python took {end_time - begin_time} to run")
    
        

if __name__  == '__main__':
    parser = ArgumentParser()
    parser.add_argument('-c','--compare',
    help= 'Will read from the args.txt file instead of reading arguments from the command line',
    action = 'store_true')
    args = parser.parse_args()
    if args.compare:
        text_args = read_args('args.txt')
        write_output(text_args)
    else:
        for (i,arg) in enumerate(argv):
            if i == 0:
                continue
            amt = float(arg) ## convert command line args to float
            print(f"For ${amt}:")
            amt = round(amt * 100,0) ## convert the value to cents, and round just in case of floating point errors 
            change(amt)