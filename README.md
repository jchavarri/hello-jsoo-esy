# hello-jsoo-esy

A project that includes the minimum configuration for a [js_of_ocaml](http://ocsigen.org/js_of_ocaml/) project using Reason and [Esy](https://github.com/esy-ocaml/esy).

## Usage

You need Esy, you can install the beta using [npm](https://nodejs.org/en/download/):

```sh
npm install -g esy
```

Then you can install the project dependencies using:

```sh
esy install
```

Then build the project dependencies along with the project itself:

```sh
esy build
```

And test the compiled JS executable, open `index.html` in your browser.

To generate the production build (without sourcemaps, and minified) run:

```sh
esy build:prod
```

## Building the bindings

The sample project include an example to show how to bind to a JavaScript library: `is-sorted`.

js_of_ocaml does not have a sophisticated way to bundle JavaScript libraries, so 
the packages is bundled inside a `.js` file that loads in the global `window` object
using Browserify.

To build these bindings, run:

```sh
cd ./lib && yarn && yarn build
```
