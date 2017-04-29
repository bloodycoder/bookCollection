### LSTM

#### 核心部分

核心就是一个`cell state`。lstm就是用这个来记忆信息。

#### 关于门

总共有三个门，看图你也知道。(`+``*`)的就是门。门的作用是增删`cell state`的值。

- forget gate
- input gate 
- output gate 

至于公式，看图你就明白了。

![lstm](./lstm-peepholes.png)
