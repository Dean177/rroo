let map = (f, opt) =>
  switch (opt) {
  | Some(s) => Some(f(s))
  | None => None
  };

module FancyButton = {
  [@react.component]
  let make =
    React.forwardRef(ref => {
      let console = Js_of_ocaml.Firebug.console;
      console##log("FancyButton got ref");
      console##log(ref);
      <button ref=?{map(ReactDOM.Ref.domRef, ref)} className="FancyButton">
        {"Click me!" |> React.string}
      </button>;
    });
};

[@react.component]
let make = () => {
  // You can now get a ref directly to the DOM button:
  let ref = React.createRef();
  <FancyButton ref />;
};
