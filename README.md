# 认识实习项目

## 作者：朱思源

## 题目：基于 STM32 的简易激光雷达

## 功能

<!-- * 能够扫描前方 `180°` 范围内的物体
* 将扫描结果以图像的形式显示在屏幕上 -->
* 控制舵机进行周期性 `180°` 旋转
* 将激光测距器搭载在舵机上，对左右 `180°` 的物体进行测距
* 将`测距结果`结合测距时发送给舵机的 `PWM 波占空比`（换算成`角度`）保存在单片机内部
* 将结果发送给一台 1.3 寸 `OLED 显示器`，以图像的形式展示扫描结果
* ~~对扫描物体进行运动学分析，同样显示在屏幕上~~

## 所用电子模块型号

* [单片机核心板 STM32F401CCU6 ￥19.5](https://item.taobao.com/item.htm?spm=a230r.1.14.1.414c49b9PCIWEk&id=673430906769&ns=1&abbucket=9&mt=)
* [舵机 ￥5.8](https://detail.tmall.com/item.htm?spm=a230r.1.14.51.598e7ffcO4JutW&id=628478684024&ns=1&abbucket=9)
* [激光测距模块（4米版本） ￥68.0](https://detail.tmall.com/item.htm?spm=a230r.1.14.16.2c593ce618qCLg&id=651558248343&ns=1&abbucket=9&skuId=4879795303518)
* [OLED显示屏1.3寸 ￥21.5](https://item.taobao.com/item.htm?spm=a230r.1.14.16.77a652684Hiazm&id=562145367495&ns=1&abbucket=9#detail)

## 大致成本

19.5 + 5.8 + 68.0 + 21.5 = 114.8 元

## 引脚分配

* USART1-**PA9**(TX)、**PA10**(RX)：接测距模块**RX**、**TX**
* IIC1-**PB6**(SCL)、**PB7**(SDA)：接OLED的**SCL**、**SDA**
* TIM10CH1-**PB8**(PWM)：接舵机的**信号线**

## 其他资料

![舵机占空比](./img/pwm.png)  
![传感器引脚](./img/sensor.png)  
