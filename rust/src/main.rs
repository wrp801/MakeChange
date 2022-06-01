use std::collections::HashMap;

// enum Money {
//     Penny,
//     Nickel,
//     Quarter,
//     Dollar1,
//     Dollar5,
//     Dollar10,
//     Dollar20,
//     Dollar50,
//     Dollar100
// }




// fn make_change() {

// }


fn main() {
    let mut value_map = HashMap::new();
    value_map.insert("Penny", 1);
    value_map.insert("Nickel",5);
    value_map.insert("Dime",10);
    value_map.insert("Quarter",25);
    value_map.insert("Dollar1",100);
    value_map.insert("Dollar5",500);
    value_map.insert("Dollar10",1000);
    value_map.insert("Dollar20",2000);
    value_map.insert("Dollar50",5000);
    value_map.insert("Dollar100",10000);

    // for (k,v) in value_map.iter() {
    //     println!("{} goes with {}",k,v)
    // }

}
