const path = require('path');
const HtmlWebpackPlugin = require('html-webpack-plugin');
const outputDir = path.join(__dirname, 'build/');
const PnpWebpackPlugin = require(`pnp-webpack-plugin`);

const isProd = process.env.NODE_ENV === 'production';

module.exports = {
  entry: path.join(process.env.cur__target_dir, 'default/src/Hello.bc.js'),
  mode: isProd ? 'production' : 'development',
  output: {
    path: outputDir,
    filename: 'Hello.js'
  },
  plugins: [
    new HtmlWebpackPlugin({
      template: 'src/index.html',
      inject: false
    })
  ],
  devServer: {
    compress: true,
    contentBase: outputDir,
    port: process.env.PORT || 8000,
    historyApiFallback: true
  },
  node: {
    fs: 'empty',
    'child_process': 'empty'
  },
  resolve: {
    plugins: [
      PnpWebpackPlugin,
    ],
  },
  resolveLoader: {
    plugins: [
      PnpWebpackPlugin.moduleLoader(module),
    ],
  },
};
