###IG-500A

思路大概是，把IG-500A通信代码和数据处理代码封装进入MFC中

在IG-500A程序中起定时器，不断处理数据(0.1秒一调)，获取数据使用SDK自带的接口进行COM通信

mfc使用开源绘图库进行绘制，自己定制了一部分，一次打开6个窗口，每个窗口的数据源通过dataType进行确定

over.