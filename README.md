# hello-jsoo-esy

A project that includes the minimum configuration for a [js_of_ocaml](http://ocsigen.org/js_of_ocaml/) project using Reason and [Esy](https://github.com/esy-ocaml/esy).

## Usage

You need Esy, you can install the beta using [npm](https://nodejs.org/en/download/):

    % npm install -g esy

Then you can install the project dependencies using:

    % esy install

Then build the project dependencies along with the project itself:

    % esy build

And test the compiled JS executable, open `index.html` in your browser.

To generate the production build (without sourcemaps, and minified) run:

    % esy run build:prod
