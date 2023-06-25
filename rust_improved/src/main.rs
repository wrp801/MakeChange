use std::collections::HashMap;
use std::vec;
mod money;
fn main() {
    let v = vec![money::Money::Dollar100, money::Money::Dollar50, money::Money::Dollar20, 
        money::Money::Dollar10, money::Money::Dollar5,money::Money::Dollar1, money::Money::Quarter,
        money::Money::Dime, money::Money::Nickel, money::Money::Penny];


    // let penny = money::Money::Penny;
    // let val = penny.get_value();
    // let name = penny.get_string();
    // println!("Value is {} and it is a {}", val, name);
    
    let mut counter = money::Counter::new();
    // counter.increase(money::Money::Dollar1);
    let cash_val = 1001;
    let mut counted_value:i32 = 0;
    let mut delta = cash_val - counted_value;


    while delta != 0 {
        let money = v.get(0).unwrap();
        if let mv = money.get_value() < cash_val {
            counter.increase(*money); // count the type of money used
            counted_value = counted_value + mv;
        } else {
            v.remove(0);
        }

    }
    println!("{:?}",counter.values);
}
