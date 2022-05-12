### NOTE 18.01 and 17.49 are 2 identified failing arguments
from sys import argv
# AMT = 99.99
def get_max_val(dict_to_search:dict) -> str:
    """
    Returns the key of the max value of a dict
    """
    return max(dict_to_search,key = dict_to_search.get,default = 0) 

def print_map(dict_to_print:dict) -> None:
    d = {k:v for k,v in dict_to_print.items() if v != 0}
    print(d)

def change(amt:float):
    """
    This will make the optimal amount of change given the amount. The amount is represented in terms of dollars
    """
    mapping = {
        'penny': 1,
        'nickel': 5,
        'dime': 10,
        'quarter': 25,
        'dollar1': 100,
        'dollar5': 500,
        'dollar10': 1000,
        'dollar20': 2000,
        'dollar50': 5000,
        'dollar100': 10000
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
    
    print_map(change_map)
    return change_amt

if __name__  == '__main__':
    amt = float(argv[1]) ## convert command line args to float
    amt = round(amt * 100,0) ## convert the value to cents, and round just in case of floating point errors 
    change(amt)

