let oneArgument = (a: int) => a + 100;

Js.Unsafe.global##.jsOneArgument := Js.wrap_callback(oneArgument);

/* This will go to console.log */
print_string("Hello from Js_of_ocaml!\n");

let sayHi = () => print_string("Hi again!\n");

let t = ["fd", "bee", "cee", "dee"];

sayHi();
