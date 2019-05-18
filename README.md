# led-matrix-connector
Reverse engineering byte codes and setting up rich connector library<br/>
Matrix model name: `Led Matrix V1.0 2016-07-05` (bought from aliexpress, so that's all the information I'll ever get<br/>¯\\_(ツ)_/¯)


## TODO, code:
* Gotta make better names for `cancelFunc`/`exitFunc` for better understanding and structure
* Animations:
  * Add special mode for displaying Morse code
  * ? Add special mode for "drawing" symbols from top to bottom
  * Deal with sending chunks of unspecified size, add timeout between frames to config
  * `LedAnimationPlay(...)` - async?
* Add more coloring options:
  * Add non-animated multi-color renderer function
  * Add support for multi-color rendering, sending an array of 64 chars/ints to renderer
  * Add 3 supplementary colors to `LedRenderMonochrome(...)`
   * Add layered `LedRenderMonochrome(...)` functions to emulate default variables
* Dictionaries:
  * Add a Morse code dictionary
  * Add a braile alphabet dictionary
  

## TODO, repository:
* Move examples to a specific folder and make them more consistent
* Remove excesssive examples
* Add documentation for matrix - clear connecton between color/masking and bytecode sent
* wiki?
