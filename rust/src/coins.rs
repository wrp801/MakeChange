
#[derive(Debug)]
enum MoneyKind {
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

#[derive(Debug)]
struct Money {
    kind: MoneyKind,
    value: i32
}

impl Money {

    fn kind(&self) -> MoneyKind {
        &self.kind
    }

    fn value(&self) -> i32 {
        &self.value
        
    }

}



