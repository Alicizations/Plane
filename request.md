
### 游戏的开发，可以简单的分为：

#### 1.交互层(V), 也就是游戏UI的设计以及实现

#### 2.控制层(C), 函数接口调用、逻辑控制等

#### 3.模型层(M)，游戏精灵设计、地图模板等

一个object类(抽象类)

```
class object
{
private:
  //level  可用于object的后续发展, 或者是boss.
  //exp    控制object升级.
  //HP     object的血量, 可以HP = i + level*k.
  //attack object的攻击力.
  int level, exp, HP, attack;
  //       object的坐标
  COORD position;
  //       单字符作为object的模型, 或者可以再升级.
  char model;
public:
  //       移动object
  virtual void move(/* argument */);
  //       在屏幕上打印object
  virtual void print();
  object();
  virtual ~object();
};
```

几个游戏精灵:

```
class plane : public object
{
public:
  //  飞机可进行发射炮弹操作
  void shoot();
  plane();
  ~plane();
};

class shell : public object
{
private:
  //  存储发射该炮弹的飞机
  plane *thisPlane;
public:
  //  炮弹和敌机相撞的后续行为
  void crash();
  //  返回经验值
  void getExp();
  shell();
  ~shell();
};

class stone : public object
{
//  地图障碍
public:
  stone();
  ~stone();
};
```


-----

基础要求：

团队开发，分工明确，优秀的代码管理, 3-4人。
基本测试，这也就意味着你的代码需要有基本的异常处理
游戏应当至少有一个用户控制的UI以及N个系统自定义行为UI同时存在