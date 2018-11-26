let oneArgument = (a: int) => a + 100;

/* Making Reason functions available in JavaScript */
Js.Unsafe.global##.jsOneArgument := Js.wrap_callback(oneArgument);

/* This will go to console.log */
print_string("Hello from Js_of_ocaml!\n");

let sayHi = () => print_string("Hi again!\n");

sayHi();

let requireModule = s =>
  Js.Unsafe.fun_call(
    Js.Unsafe.js_expr("require"),
    [|Js.Unsafe.inject(Js.string(s))|],
  );

/* Using JavaScript functions from Reason */
let log = (title, data) =>
  Js.Unsafe.fun_call(
    Js.Unsafe.js_expr("console.log"),
    [|title |> Js.string |> Js.Unsafe.inject, data |> Js.Unsafe.inject|],
  );

/* Compiled to nested array with [0, value1, [0, value2, [0, value3, 0]]] */
let list = [1, 2, 3, 4, 5];
/* Compiled to array but with an additional `0` added at the first position*/
let array = [|6, 7, 8, 9|];

/* Reason strings get compiled to an object `{c, l, t}`. `c` is the string itself, `l` the length */
let string = "hey";
/* Compiled to 1 or 0 */
let bool = true;
/* Compiled to a number (no transformation) */
let int = 2;
/* Compiled to a number (no transformation) */
let float = 13.3;
/* Compiled to an array with an additional `0` added at the first position */
let tuple = (13, 22);

let func = a => if (a) {2} else {4};

/* Defining JavaScript object types */
type obj = {
  .
  "x": Js.readonly_prop(Js.t(Js.js_string)),
  "y": Js.prop(int),
};

/* Declaring JavaScript objects (optional annotation) */
let obj: obj = [%js
  {
    val x = Js.string("2"); /* read-only prop */
    val mutable y = 4 /* read/write prop */
  }
];
/* Mutating objects */
obj##.y := 2;
/* Reading object properties */
let dataProp = obj##.x;

log("list", list);
log("array", array);
log("string", string);
log("bool", bool);
log("int", int);
log("float", float);
log("tuple", tuple);
log("function", func);
log("obj", obj);
log("obj property", dataProp);

/* Using a JavaScript library */
let isSorted = IsSorted.sorted([|2, 3, 14|]);
log("isSorted", isSorted);
