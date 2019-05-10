# led-matrix-connector
Reverse engineering byte codes and setting up rich connector library<br/>
Matrix model name: `Led Matrix V1.0 2016-07-05` (bought from aliexpress, so that's all the information I'll ever get<br/>¯\\_(ツ)_/¯)


## TODO, code:
* Gotta make better names for `cancelFunc`/`exitFunc` for better understanding and structure
* Animations:
  * Add special mode for displaying text
  * Deal with sending chunks of unspecified size, add timeout between frames to config
  * `LedAnimationPlay(...)` - async?
* Add more coloring options:
  * Add 2 non-animated renderer functions - monochromatic and multi-color
  * Add support for multi-color rendering, sending an array of 64 chars/ints to renderer
  * Add other 6 colors to `LedRenderMonochrome(...)`


## TODO, repository:
* Move examples to a specific folder and make them more consistent
* Remove excesssive examples
* Add documentation for matrix - clear connecton between color/masking and bytecode sent
* wiki?
