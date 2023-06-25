use std::collections::HashMap;
use std::vec;
mod money;
fn main() {
    let v = vec![money::Money::Dollar100, money::Money::Dollar50, money::Money::Dollar20, 
        money::Money::Dollar10, money::Money::Dollar5,money::Money::Dollar1, money::Money::Quarter,
        money::Money::Dime, money::Money::Nickel, money::Money::Penny];


    let penny = money::Money::Penny;
    let val = penny.get_value();
    let name = penny.get_string();
    println!("Value is {} and it is a {}", val, name);
    
}
