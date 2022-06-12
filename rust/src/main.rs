use std::collections::HashMap;
use std::env;


fn filter_map(input: HashMap<String,i32>,amount:i32) -> HashMap<String,i32> {
    /*
    Filters the hashmap based off the argument amount
    */
    let mut ret_map = HashMap::new();
    for (k,v) in input {
        if v <= amount {
            ret_map.insert(k,v);
        }
    }
    
    return ret_map;
}

fn print_map(map: HashMap<String,i32>) {
    for (k,v) in map.iter() {
        if *v > 0 {
            println!("{}: {}",k,v)
        }
    }
}

fn select_max(input: HashMap<String,i32>,amount:i32) -> (String,i32) {

    let filtered_map = filter_map(input,amount);
    // let mut ret_map = HashMap::new();
    let mut key:String = String::from("");
    let mut val:i32 = 0;
    for (k,v) in filtered_map {
        if v >= val {
            key = k;
            val = v;
        }

    }
    // ret_map.insert(key,val);
    return (key,val);
}


fn make_change(amt:i32) -> HashMap<String,i32> {
    // The main driver for the program, this will find the optimal amount of change using a greedy method
    let mut value_map: HashMap<String,i32> = HashMap::new();
    value_map.insert(String::from("Penny"),1);
    value_map.insert(String::from("Nickel"),5);
    value_map.insert(String::from("Dime"),10);
    value_map.insert(String::from("Quarter"),25);
    value_map.insert(String::from("Dollar1"),100);
    value_map.insert(String::from("Dollar5"),500);
    value_map.insert(String::from("Dollar10"),1000);
    value_map.insert(String::from("Dollar20"),2000);
    value_map.insert(String::from("Dollar50"),5000);
    value_map.insert(String::from("Dollar100"),10000);

    let mut change_counter: HashMap<String,i32> = HashMap::new();
    change_counter.insert(String::from("Penny"), 0);
    change_counter.insert(String::from("Nickel"),0);
    change_counter.insert(String::from("Dime"),0);
    change_counter.insert(String::from("Quarter"),0);
    change_counter.insert(String::from("Dollar1"),0);
    change_counter.insert(String::from("Dollar5"),0);
    change_counter.insert(String::from("Dollar10"),0);
    change_counter.insert(String::from("Dollar20"),0);
    change_counter.insert(String::from("Dollar50"),0);
    change_counter.insert(String::from("Dollar100"),0);

    let mut change_amt:i32 = 0;
    let mut delta:i32 = amt - change_amt;
    while delta > 0 {
        let filtered_map = filter_map(value_map.clone(),delta);
        let max_val = select_max(filtered_map,delta);

        let ky = max_val.0; // get the key
        let v = max_val.1; // get the value
        let change_val = change_counter[&ky]; // get the value from the change counter
        change_counter.insert(ky,change_val+1); // update the value
        change_amt += v; 
        delta = amt - change_amt;
    }
    return change_counter;
}

fn main() {
    let args: std::vec::Vec<_> = env::args().collect();
    if args.len() > 2 {
        println!("Error: Please only enter one value, not multiple");
        return;
    }

    if args.len() == 1 {
        println!("Error: Please enter a value to find the optimal value of change in USD");
        return;
    }

    let amt = &args[1]; // get the amount as a str type
    let new_amt:f32 = amt.parse().unwrap(); // convert amount to a float
    let amt_int:i32 = (new_amt * 100.00) as i32;  // convert to int and to cents

    let result = make_change(amt_int);
    print_map(result);
}
