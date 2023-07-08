use std::collections::HashMap;
use std::vec;
mod money;
fn main() {
    let mut money_vec = vec![money::Money::Dollar100, money::Money::Dollar50, money::Money::Dollar20, 
        money::Money::Dollar10, money::Money::Dollar5,money::Money::Dollar1, money::Money::Quarter,
        money::Money::Dime, money::Money::Nickel, money::Money::Penny];


    let mut counter = money::Counter::new();
    // counter.increase(money::Money::Dollar1);
    let cash_val = 2532;
    let mut counted_value:i32 = 0;
    let mut delta = cash_val - counted_value;



    while delta != 0 {
        let money = &(money_vec[0]);
        if money.get_value() <= delta {
            counter.increase(*money); // count the type of money used
            let mv = money.get_value();
            counted_value = counted_value + mv;
            delta -= mv;
        } else {
            money_vec.remove(0);
        }

    }
    println!("{:?}",counter.values);
}
