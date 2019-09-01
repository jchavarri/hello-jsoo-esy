# hello-jsoo-esy

A project that includes the minimum configuration for a [js_of_ocaml](http://ocsigen.org/js_of_ocaml/) project using Reason and [Esy](https://github.com/esy-ocaml/esy).

It also includes an example showing how to integrate existing js_of_ocaml bindings: [`jsoo-is-sorted`](https://github.com/jchavarri/jsoo-is-sorted).

## Usage

You need Esy, you can install the beta using [npm](https://nodejs.org/en/download/):

```sh
npm install -g esy
```

Install the project dependencies and build the project:

```sh
esy # ocaml dependencies
yarn # js dependencies (can use npm too)
```

```sh
esy build:watch
# in another tab
yarn webpack
```

After you see the webpack compilation succeed (the `yarn webpack` step), open up `build/index.html` (no server needed!). Then modify `Hello.re` file in `src` and refresh the page to see the changes.

## Run Project with Server

To run with the webpack development server run `yarn server` and view in the browser at http://localhost:8000. Running in this environment provides hot reloading and support for routing; just edit and save the file and the browser will automatically refresh.

To use a port other than 8000 set the `PORT` environment variable (`PORT=8080 yarn server`).

## Build for Production

```sh
yarn clean
esy build:prod # without sourcemaps, minified
yarn webpack:production
```

This will replace the development artifact `build/Index.js` for an optimized version as well as copy `src/index.html` into `build/`. You can then deploy the contents of the `build` directory (`index.html` and `Index.js`).
