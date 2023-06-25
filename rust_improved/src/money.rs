use std::{collections::HashMap, hash::Hasher};
use derivative::Derivative;
#[derive(Debug, Eq, Derivative)]
#[derive(PartialEq,Hash)]
pub enum Money {
    Penny,
    Nickel,
    Dime,
    Quarter,
    Dollar1,
    Dollar5,
    Dollar10,
    Dollar20,
    Dollar50,
    Dollar100
}


impl Money {
    pub fn get_value(&self) -> i32 {

        match *self {
            Money::Penny => 1,
            Money::Nickel => 5,
            Money::Dime => 10, 
            Money::Quarter => 25,
            Money::Dollar1 => 100,
            Money::Dollar5 => 500,
            Money::Dollar10 => 1000,
            Money::Dollar20 => 2000,
            Money::Dollar50 => 5000,
            Money::Dollar100 => 10000
        }
    }

    pub fn get_string(&self) -> &str {
        match *self {
            Money::Penny => "Penny",
            Money::Nickel => "Nickel", 
            Money::Dime => "Dime",
            Money::Quarter => "Quarter",
            Money::Dollar1 => "Dollar 1",
            Money::Dollar5 => "Dollar 5",
            Money::Dollar10 =>  "Dollar 10", 
            Money::Dollar20 => "Dollar 20", 
            Money::Dollar50 => "Dollar 50", 
            Money::Dollar100 => "Dollar 100"
        }


    }
}

// need to implement hashing for the Money Enum
// impl Hash for Money {
//     fn hash<H: Hasher>(&self, state: &mut H) {
//         match self {
//             Money::get_value() 
//
//         }
//
//     }
//     
//
// }

// need to implement PartialEq for the Money Enum
// impl PartialEq for Money {}

#[derive(Debug)]
pub struct Counter {
    values: HashMap<Money, i32>
}

impl Counter {
    pub fn new(&self) {
        let mut tmp_map = HashMap::new();
        tmp_map.insert(Money::Penny, 0);
        tmp_map.insert(Money::Nickel, 0);
        tmp_map.insert(Money::Dime, 0);
        tmp_map.insert(Money::Quarter, 0); 
        tmp_map.insert(Money::Dollar1, 0);
        tmp_map.insert(Money::Dollar5, 0);
        tmp_map.insert(Money::Dollar10, 0);
        tmp_map.insert(Money::Dollar20, 0);
        tmp_map.insert(Money::Dollar50, 0);
        tmp_map.insert(Money::Dollar100, 0);
    }
}


