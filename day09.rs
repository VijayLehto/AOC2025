use std::fs;
use itertools::Itertools;

fn f (s : &str) -> [i64;2] {
	let mut words = s.split(",");
	let num1 : i64 = words.next().unwrap().parse().unwrap();
	let num2 : i64 = words.next().unwrap().parse().unwrap();
	
	[num1,num2]
}

fn area (p1 : [i64;2], p2 : [i64;2]) -> i64 {
	((p1[0]-p2[0]+1)*(p1[1]-p2[1]+1)).abs()
}

fn main() {
	let file_path = "input09.txt";
	let contents = fs::read_to_string(file_path).expect("Womp womp");
	let points = contents.split("\n").map(f);
	
	let it = points.cartesian_product(points);
}
