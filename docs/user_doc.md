# User documentation
## How to use the demonstrator ?
Upon launch of the `demo` executable, the following interface pops up:

![general view of the interface](assets/screen_demonstrator_1.png "general view of the interface")


On the right-hand side, you have a fully fonctionnal Potree interface with a pointcloud already loaded. You can change the camera view using the mouse : the left click enables you to rotate and the right click to pan.

On the left-hand side, a button says "Pick a point":
![pick a point button](assets/button_pick_point.png "pick a point button")

If you click it, you'll be able to select a point by passing your mouse over :

![selecting a point](assets/selecting_point.png "selecting a point")

As soon as you click, data will be send from Potree to the C++ code. It will be printed on the left in the dedicated area:

![data received](assets/data_received.png "data received")

That's it !