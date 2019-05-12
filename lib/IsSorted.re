let sorted: array('a) => bool =
  a =>
    Js.to_bool(
      Js.Unsafe.fun_call(
        Js.Unsafe.global##.IsSorted,
        [|Js.Unsafe.inject(Js.array(a))|],
      ),
    );
