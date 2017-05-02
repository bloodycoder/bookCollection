### 声明

该处改为xml后上传至blog.

---

### 智能指针

[click me](https://github.com/bloodycoder/bookCollection/blob/master/notes/elements/智能指针.md)

### RAII守则

[click me](https://github.com/bloodycoder/bookCollection/blob/master/notes/elements/RAII%E5%AE%88%E5%88%99.md)

### explicit 

[click me](https://github.com/bloodycoder/bookCollection/blob/master/notes/elements/cpp_explicit.md)

### 为什么运算符重载的时候，都要加const

比如一个类的名字Test

    Test operator+(const Test &t2){
        pass;
    }

这样的代码是可以通过编译的。但学c++的时候，我们当时课本上一直都是:

    const Test operator+(const Test &t2){
        pass;
    }
    
当时始终不能理解。原来是因为担心，把`t1+t2 == t3`写成`t1+t2=t3`。

如果不加const，那么写错了是不会报错的。

当重载`=`的时候，还要加`&`。因为你必须返回这个对象。从而让`a=b=c`这样的代码可以执行。

### 为什么传递参数的时候，最好选择引用传递

分为俩种

- 内置类型和STL

- 自建的类

如果是前者，那么可以用值传递。

但如果是后者，务必用引用传递+const。如果使用值传递，你会调用复制构造函数，如果你的类很大，这样花费会比较大。加const是为了让客户无法修改你的值。

用值传递第二个问题是slicing问题。就是，你的方法的局部变量可能是一个基类型，但传入的是子类型。那么只会调用基类的构造函数。但如果你用const+&。就不会有这个问题。

### 在返回值的时候，务必返回值传递

你在返回值，如果用引用传递，那块内存无非是在stack或者heap上。stack上的，会在函数体结束后消失，这会造成引用了一个未定义的值。如果在heap上，用户很可能不会记得删这块内存。所以务必要用返回值传递。

### 切记将成员变量声明为private

这是封装的一部分。

###　用non-member代替member函数

这可能与常识相悖。但我看书后了解到。其实这样做是为了封装，如果一件事能用类提供的public方法来做，那么就没有必要把它放到类里面。因为把他放到类里，就意味着多了一个函数体能够访问private对象，如果你要找bug，就多了一部分劳动。

然后运算符重载会定义在外边。比如有理数类Rational.

重载加法的时候。如果你定义成

    const Rational operator+(const Rational &T){
        return Rational(this.x+T.x,this.y+T.y);
    }

这样你会发现`R+2`这样的语句能编译。但`2+R`却不行。因为`R+2`实际上是先用构造函数，把2转成了Rational对象。但2+R，这样的话，是把R转为int。很明显会报错。

所以这种重载都应该放在外面。

    const Rational operator+(const Rational &T1,const Rational &T2){
        return Rational(T1.x+T2.x,T1.y+T2.y);
    } 
