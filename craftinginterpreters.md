# $1$ $Atguigu$语言

我们先来简单介绍一下$Atguigu$语言的用法。

## $1. 1$ $Hello, Atguigu$

我们来用$Atguigu$写一个$hello \; world$程序：

```js
// 第一个Atguigu程序
print("Hello, world!");
```

$Atguigu$语言是一门动态类型的语言，和$JavaScript$的语法非常相似，因为借鉴了很多$JS$中的语法。

## $1.2$ $Atguigu$语言中的数据类型

我们有以下几种内置的数据类型：

**布尔类型**：$Atguigu$语言中有两个布尔值，每个值都有一个字面量：

```c
true;  // Not false.
false; // Not *not* false.
```

**数值类型**：$Atguigu$只有一种数值类型：双精度浮点数。由于浮点数还可以表示各种各样的整数，因此可以覆盖很多领域，同时保持简单。

```c
1234;  // 整数数值
12.34; // 十进制数值
```

**字符串类型**：在第一个示例中，我们已经看到一个字符串字面量。与大多数语言一样，它们用双引号引起来：

```c
"I am a string";
"";    // 空字符串
"123"; // 字符串类型，不是数值类型
```

我们在实现它们时会看到，在这个无害的字符序列中隐藏了相当多的复杂性。

**空值类型**：在许多其他语言中称为$null$。在$Atguigu$语言中，我们将其拼写为`nil`。

## $1.4$ $Atguigu$中的表达式

### $1.4.1$ 算术运算

$Atguigu$借鉴了$JavaScript$中的基本算术运算符：

```c
add + me;      // 加法
subtract - me; // 减法
multiply * me; // 乘法
divide / me;   // 除法
```

运算符两边的子表达式都是 **操作数** 。因为有两个操作数，它们被称为 **二元** 运算符。由于运算符固定在操作数的中间，因此也称为 **中缀** 运算符，相对的，还有 **前缀** 运算符（运算符在操作数前面，例如`--i`）和 **后缀** 运算符（运算符在操作数后面，例如`i++`）。

有一个数学运算符既是中缀运算符也是前缀运算符，`-`运算符可以对数字取负：

```c
-negateMe;
```

所有这些操作符都是针对数字的，将任何其他类型操作数传递给它们都是错误的。唯一的例外是`+`运算符—你也可以传给它两个字符串将它们串接起来。

### $1.4.2$ 比较与相等运算

接下来，我们有几个返回布尔值的运算符。我们可以使用旧的比较运算符来比较数字（并且只能比较数字）：

```c
less < than;
lessThan <= orEqual;
greater > than;
greaterThan >= orEqual;
```

我们可以测试两个任意类型的值是否相等：

```c
1 == 2;         // false.
"cat" != "dog"; // true.
```

即使是不同类型也可以：

```c
314 == "pi"; // false.
```

不同类型的值 **永远不会** 相等：

```c
123 == "123"; // false.
```

$Atguigu$语言去掉了$JavaScript$中的隐式类型转换。在$JS$中：

```js
123 == "123"; // true
```



### $1.4.3$ 逻辑运算

取反运算符，是前缀运算符`!`，如果操作数是`true`，则返回`false`，反之亦然：

```c
!true;  // false.
!false; // true.
```

其他两个逻辑运算符实际上是表达式伪装下的控制流结构。`and`表达式用于确认两个操作数是否 **都是** `true`。如果左侧操作数是`false`，则返回左侧操作数，否则返回右侧操作数：

```c
true and false; // false.
true and true;  // true.
```

`or`表达式用于确认两个操作数中任意一个（或者都是）为`true`。如果左侧操作数为`true`，则返回左侧操作数，否则返回右侧操作数：

```c
false or false; // false.
true or false;  // true.
```

`and`和 `or`之所以像控制流结构，是因为它们会**短路**。如果左操作数为假，`and`不仅会返回左操作数，在这种情况下，它甚至不会计算右操作数。反过来，如果`or`的左操作数为真，右操作数就会被跳过。

### $1.4.4$ 优先级与括号

所有这些运算符都具有与$JS$语言相同的优先级和结合性。在优先级不满足要求的情况下，你可以使用`()`来分组：

```c
var average = (min + max) / 2;
```



## $1.5$ 语句

现在我们来看语句。表达式的主要作用是产生一个 **值** ，语句的主要作用是产生一个 **效果** 。由于根据定义，语句不求值，因此必须以某种方式改变世界（通常是修改某些状态，读取输入或产生输出）才能有用。

我们已经见过一个语句了，就是：

```js
print("hello, world!");
```

`print`语句计算单个表达式并将结果显示给用户。我们还会看到一些语句，例如：

```c
表达式;
1 + 2;
```

表达式后跟分号（`;`）可以将表达式提升为语句状态。这被称为 **表达式语句** 。

如果我们想将一系列语句打包成一个语句，那么可以将它们打包在一个块（$block$）中：

```c
{
  print("第一个语句");
  print("第二个语句");
}
```

块还会影响作用域，我们将在后面进行说明。

## $1.6$ 变量

我们可以使用`var`语句声明变量。如果你省略了初始化操作，变量的值默认为`nil`：

```c
var imAVariable = "变量语法";
var iAmNil;
```

一旦声明完成，我们就可以通过变量名对其进行访问和赋值：

```c
var name = "atguigu";
print(name); // "atguigu".
name = "zuoyuan";
print(name); // "zuoyuan".
```

## $1.7$ 控制流

`if`语句根据某些条件执行两条语句中的一条：

```c
if (condition) {
  print("yes");
} else {
  print ("no");
}
```

只要条件表达式的计算结果为`true`，`while`循环就会重复执行循环体：

```c
var a = 1;
while (a < 10) {
  print(a);
  a = a + 1;
}
```

最后，还有`for`循环：

```c
for (var a = 1; a < 10; a = a + 1) {
  print(a);
}
```

这个循环与之前的 `while` 循环做同样的事情。

## $1.8$ 函数

函数调用表达式与$JS$中的一样：

```c
add(1, 2);
```

我们也可以在不传递任何参数的情况下调用一个函数：

```c
moveFast();
```

在本例中括号是强制性的。如果你把它们去掉，就不会调用函数，只是指向该函数。

在$Atguigu$里，我们可以通过`function`关键字来定义函数：

```js
function add(a, b) {
  print(a + b);
  return a + b;
}
```

如果执行到达函数体的末尾而没有`return`语句，则会隐式返回`nil`。

### $1.8.1$ 闭包

在$Atguigu$中，函数是 **一等公民** ，这意味着它们都是真实的值，你可以对这些值进行引用、存储在变量中、传递等等。下面的代码是有效的：

```js
function addPair(a, b) {
  return a + b;
}

function identity(a) {
  return a;
}

print(identity(addPair)(1, 2)); // 打印 "3".
```

由于函数声明是语句，所以可以在另一个函数中声明局部函数：

```js
function outerFunction() {
  function localFunction() {
    print("I'm local!");
  }

  localFunction();
}
```

如果将局部函数、头等函数和块作用域组合在一起，就会遇到这种有趣的情况：

```js
function returnFunction() {
  var outside = "outside";

  function inner() {
    print(outside);
  }

  return inner;
}

var fn = returnFunction();
fn();
```

在这里，`inner()`访问了在其函数体外的外部函数中声明的局部变量。

要做到这一点，`inner()`必须“保留”对它使用的任何外部变量的引用，这样即使在外层函数返回之后，这些变量仍然存在。我们把能做到这一点的函数称为**闭包**。

可以想象，实现这些会增加一些复杂性，因为我们不能再假定变量作用域严格地像堆栈一样工作，在函数返回时局部变量就消失了。

# $2$ 词法分析

任何编译器或解释器的第一步都是扫描。扫描器以一系列字符的形式接收源代码，并将其分组成一系列的块，我们称之为$token$（词法单元）。这些是有意义的“单词”和“标点”，它们构成了语言的语法。

对于我们来说，扫描也是一个很好的起点，因为代码不是很难—相当于有很多分支的`switch`语句。这可以帮助我们在学习更后面有趣的部分之前进行热身。在本章结束时，我们将拥有一个功能齐全、速度快的扫描器，它可以接收任何一串$Atguigu$源代码，并产生$token$序列，我们将在下一章把这些标记输入到语法分析器中。

## $2.1$ 解释器框架

由于这是我们的第一个真正的章节，在我们开始实际扫描代码之前，我们需要先勾勒出我们的解释器的基本形态。在$Java$中，一切都是从一个类开始的。

> 创建新文件`Atguigu.java`

```java
package com.atguigu;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.List;

public class Atguigu {
  public static void main(String[] args) throws IOException {
    if (args.length > 1) {
      System.out.println("用法: atguigu [脚本文件]");
      System.exit(64); 
    } else if (args.length == 1) {
      runFile(args[0]);
    } else {
      runPrompt();
    }
  }
}
```

$Atguigu$是一种脚本语言，这意味着它直接从源代码执行。我们的解释器支持两种运行代码的方式。如果从命令行启动解释器并为其提供脚本文件的路径，它将读取该文件并执行。

> 在`Atguigu.java`中，添加到`main()`方法之后

```java
private static void runFile(String path) throws IOException {
  byte[] bytes = Files.readAllBytes(Paths.get(path));
  run(new String(bytes, Charset.defaultCharset()));
}
```

> 在`Atguigu.java`，添加到`runFile()`方法之后

```java
private static void runPrompt() throws IOException {
  InputStreamReader input = new InputStreamReader(System.in);
  BufferedReader reader = new BufferedReader(input);

  for (;;) { 
    System.out.print("atguigu> ");
    String line = reader.readLine();
    if (line == null) break;
    run(line);
  }
}
```

`readLine()`函数，顾名思义，读取用户在命令行上的一行输入，并返回结果。要终止交互式命令行应用程序，通常需要输入`Control-D`。这样做会向程序发出 **文件结束** 的信号。当这种情况发生时，`readLine()`就会返回`null`，所以我们检查一下是否存在`null`以退出循环。

交互式提示符和文件运行工具都是对这个核心函数的简单包装：

> 在`Atguigu.java`文件中，添加到`runPrompt()`之后

```java
  private static void run(String source) {
    Scanner scanner = new Scanner(source);
    List<Token> tokens = scanner.scanTokens();

    // 现在先打印token序列
    for (Token token : tokens) {
      System.out.println(token);
    }
  }
```

因为我们还没有写出解释器，所以这些代码还不是很有用，但这只是小步骤，你要明白？现在，它可以打印出我们即将完成的扫描器所返回的$token$序列，这样我们就可以看到我们的解析是否生效。

### $2.1.1$ 错误处理

当我们设置东西的时候，另一个关键的基础设施是错误处理。教科书有时会掩盖这一点，因为这更多的是一个实际问题，而不是一个正式的计算机科学问题。但是，如果你关心的是如何制作一个真正可用的语言，那么优雅地处理错误是至关重要的。

我们的语言提供的处理错误的工具构成了其用户界面的很大一部分。当用户的代码在工作时，他们根本不会考虑我们的语言—他们的脑子里都是他们的程序。通常只有当程序出现问题时，他们才会注意到我们的实现。

当这种情况发生时，我们就需要向用户提供他们所需要的所有信息，让他们了解哪里出了问题，并引导他们慢慢达到他们想要去的地方。要做好这一点，意味着从现在开始，在解释器的整个实现过程中都要考虑错误处理。

> 在`Atguigu.java`文件中，添加到`run()`方法之后

```java
static void error(int line, String message) {
    report(line, "", message);
  }

  private static void report(int line, String where,
                             String message) {
    System.err.println(
        "[line " + line + "] Error" + where + ": " + message);
    hadError = true;
  }
```

这个`error()`函数和其工具方法`report()`会告诉用户在某一行上发生了一些语法错误。这其实是最起码的，可以说你有错误报告功能。想象一下，如果你在某个函数调用中不小心留下了一个悬空的逗号，解释器就会打印出来：

```java
Error: Unexpected "," somewhere in your code. Good luck finding it!
```

我们在`Atguigu`主类中使用这个错误报告功能的主要原因就是因为那个`hadError`字段。它的定义在这里：

> 在`Atguigu.java`文件中，在`Atguigu`类中添加：

```java
public class Atguigu {
  static boolean hadError = false;
```

我们将以此来确保我们不会尝试执行有已知错误的代码。此外，它还能让我们像一个好的命令行工具那样，用一个非零的结束代码退出。

> 在`Atguigu.java`文件中，在`runFile()`中添加：

```java
    run(new String(bytes, Charset.defaultCharset()));
    
    // 通过退出码表示出错。
    if (hadError) System.exit(65);
  }
```

我们需要在交互式循环中重置此标志。如果用户输入有误，也不应终止整个会话。

> 在`Atguigu.java`文件中，在`runPrompt()`中添加：

```java
      run(line);
      hadError = false;
    }
```

我把错误报告拉出来，而不是把它塞进扫描器和其他可能发生错误的阶段，还有另一个原因，是为了提醒您，把产生错误的代码和报告错误的代码分开是一个很好的工程实践。

前端的各个阶段都会检测到错误，但是它们不需要知道如何向用户展示错误。再一个功能齐全的语言实现中，可能有多种方式展示错误信息：在$stderr$，在$IDE$的错误窗口中，记录到文件，等等。您肯定不希望扫描器和解释器中到处充斥着这类代码。

理想情况下，我们应该有一个实际的抽象，即传递给扫描程序和解析器的某种`ErrorReporter`接口，这样我们就可以交换不同的报告策略。对于我们这里的简单解释器，我没有那样做，但我至少将错误报告代码移到了一个不同的类中。

有了一些基本的错误处理，我们的应用程序外壳已经准备好了。一旦我们有了一个带有 `scanTokens()`方法的`Scanner`类，我们就可以开始运行它了。在我们开始之前，让我们更精确地了解什么是$tokens$。

## $2.2$ $token$（词法单元）

下面是一行$Atguigu$代码：

```js
var language = "atguigu";
```

在这里，`var`是声明变量的关键字。“v-a-r”这三个字符的序列是有意义的。但如果我们从`language`中间抽出三个字母，比如“g-u-a”，它们本身并没有任何意义。

这就是词法分析的意义所在。我们的工作是扫描字符列表，并将它们归纳为具有某些含义的最小序列。每一组字符都被称为词素。在示例代码行中，词素是：

```mermaid
graph LR
	A["var"] --> B["language"] --> C["="] --> D["#quot;atguigu#quot;"] --> E[";"]
```

词素只是源代码的原始子字符串。 但是，在将字符序列分组为词素的过程中，我们也会发现了一些其他有用的信息。 当我们获取词素并将其与其他数据捆绑在一起时，结果是一个$token$（词法单元）。它包含一些有用的内容，比如：

### $2.2.1$ $token$类型

关键词是语言语法的一部分，所以解析器经常会有这样的代码：“如果下一个$token$是`while`，那么就……” 。这意味着解析器想知道的不仅仅是它有某个标识符的词素，而是它得到一个**保留字**，以及它是**哪个**关键字。

解析器可以通过比较字符串对原始词素中的标记进行分类，但这样做很慢，而且有点难看。相反，在我们识别一个词素的时候，我们还要记住它代表的是哪种词素。我们为每个关键字、操作符、标点位和字面量都有不同的类型。

> 创建新文件`TokenType.java`

```java
package com.atguigu;

public enum TokenType {
  // 单字符标记
  LEFT_PAREN, RIGHT_PAREN, LEFT_BRACE, RIGHT_BRACE,
  COMMA, MINUS, PLUS, SEMICOLON, SLASH, STAR,

  // 单字符或者双字符标记
  BANG, BANG_EQUAL,
  EQUAL, EQUAL_EQUAL,
  GREATER, GREATER_EQUAL,
  LESS, LESS_EQUAL,

  // 字面量
  IDENTIFIER, STRING, NUMBER,

  // 关键字
  AND, ELSE, FALSE, FUNCTION, FOR, IF, NIL, OR,
  PRINT, RETURN, TRUE, VAR, WHILE,

  EOF
}
```

### $2.2.2$ 字面量

字面量有对应词素—数字和字符串等。由于扫描器必须遍历文字中的每个字符才能正确识别，所以它还可以将值的文本表示转换为运行时对象，解释器后续将使用该对象。

### $2.2.3$ 位置信息

在错误处理时，我们需要告诉用户错误发生在哪里。（用户）从这里开始定位问题。在我们的简易解释器中，我们只说明了$token$出现在哪一行上，但更复杂的实现中还应该包括列位置和长度。

我们将所有这些数据打包到一个类中。

> 创建新文件`Token.java`

```java
package com.atguigu;

public class Token {
  final TokenType type;
  final String lexeme;
  final Object literal;
  final int line; 

  public Token(TokenType type, String lexeme, Object literal, int line) {
    this.type = type;
    this.lexeme = lexeme;
    this.literal = literal;
    this.line = line;
  }

  public String toString() {
    return type + " " + lexeme + " " + literal;
  }
}
```

现在我们有了一个信息充分的对象，足以支撑解释器的所有后期阶段。

## $2.3$ 正则语言和表达式

既然我们已知道我们要输出的什么，那么，我们就开始吧。扫描器的核心是一个循环。从源码的第一个字符开始，扫描器计算出该字符属于哪个词素，并消费它和属于该词素的任何后续字符。当到达该词素的末尾时，扫描器会输出一个$token$。

然后再循环一次，它又循环回来，从源代码中的下一个字符开始再做一次。它一直这样做，吃掉字符，然后隔一会儿输出$token$，直到它到达输入的终点。

```mermaid
graph LR
	subgraph A["字符"]
		B["r"] --> C["a"] --> D["v"]
	end
	D --> E["扫描器"] --> F["var"]
```

在循环中，我们会查看一些字符，以确定它 **匹配** 的是哪种词素，这部分内容可能听起来很熟悉，但如果你知道正则表达式，你可以考虑为每一种词素定义一个$regex$，并使用这些$regex$来匹配字符。如果你了解正则表达式，你可以考虑为每一种词素定义一个$regex$，然后用来匹配字符。例如，$Atguigu$对标识符（变量名等）的规则与$JS$语言相同。下面的$regex$可以匹配一个标识符：

```js
[a-zA-Z_][a-zA-Z_0-9]*
```

如果你确实想到了正则表达式，那么你的直觉还是很深刻的。决定一门语言如何将字符分组为词素的规则被称为它的**词法语法**。在$Atguigu$中，和大多数编程语言一样，该语法的规则非常简单，可以将其归为**正则语言**。这里的正则和正则表达式中的 **正则** 是一样的含义。

如果你愿意，你可以非常精确地使用正则表达式来识别$Atguigu$的所有不同词组。由于我们的目标是了解扫描器是如何工作的，所以我们不会把这个任务交给正则表达式。我们要亲自动手实现。

## $2.4$ `Scanner`类

事不宜迟，我们先来建一个扫描器吧。

> 创建新文件`Scanner.java`

```java
package com.atguigu;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import static com.craftinginterpreters.lox.TokenType.*; 

public class Scanner {
  private final String source;
  private final List<Token> tokens = new ArrayList<>();

  Scanner(String source) {
    this.source = source;
  }
}
```

我们将原始的源代码存储为一个简单的字符串，并且我们已经准备了一个列表来保存扫描时产生的标记。前面提到的循环看起来类似于：

> 在`Scanner.java`文件中，方法`Scanner()`后添加

```java
  public List<Token> scanTokens() {
    while (!isAtEnd()) {
      // We are at the beginning of the next lexeme.
      start = current;
      scanToken();
    }

    tokens.add(new Token(EOF, "", null, line));
    return tokens;
  }
```

扫描器通过自己的方式遍历源代码，添加$token$，直到遍历完所有字符。然后，它在最后附加一个的 **end of file** 的$token$。严格意义上来说，这并不是必须的，但它可以使我们的解析器更加干净。

这个循环依赖于几个字段来跟踪扫描器在源代码中的位置。

> 在`Scanner.java`文件中，在`Scanner`类中添加

```java
  private final List<Token> tokens = new ArrayList<>();
// 添加下面三行代码
  private int start = 0;
  private int current = 0;
  private int line = 1;

  Scanner(String source) {
```

`start`和`current`字段是指向字符串的偏移量。`start`字段指向被扫描的词素中的第一个字符，`current`字段指向当前正在处理的字符。`line`字段跟踪的是`current`所在的源文件行数，这样我们产生的$token$就可以知道其位置。

然后，我们还有一个辅助函数，用来告诉我们是否已消费完所有字符。

> 在`Scanner.java`文件中，在`scanTokens()`方法之后添加

```java
  private boolean isAtEnd() {
    return current >= source.length();
  }
```

## $2.5$ 识别词素

在每一次循环中，我们会扫描一个$token$。这是扫描器真正的核心。让我们先从简单情况开始。想象一下，如果每个词素只有一个字符长。您所需要做的就是消费下一个字符并为其选择一个$token$类型。在$Atguigu$中有一些词素只包含一个字符，所有我们从这些词素开始。

> 在`Scanner.java`文件中，添加到`scanTokens()`方法之后

```java
private void scanToken() {
    char c = advance();
    switch (c) {
      case '(': addToken(LEFT_PAREN); break;
      case ')': addToken(RIGHT_PAREN); break;
      case '{': addToken(LEFT_BRACE); break;
      case '}': addToken(RIGHT_BRACE); break;
      case ',': addToken(COMMA); break;
      case '-': addToken(MINUS); break;
      case '+': addToken(PLUS); break;
      case ';': addToken(SEMICOLON); break;
      case '*': addToken(STAR); break; 
    }
  }
```

同样，我们也需要一些辅助方法。

> 在`Scanner.java`文件中，添加到`isAtEnd()`方法后

```java
  private char advance() {
    current++;
    return source.charAt(current - 1);
  }

  private void addToken(TokenType type) {
    addToken(type, null);
  }

  private void addToken(TokenType type, Object literal) {
    String text = source.substring(start, current);
    tokens.add(new Token(type, text, literal, line));
  }
```

`advance()`方法获取源文件中的下一个字符并返回它。`advance()`用于处理输入，`addToken()`则用于输出。该方法获取当前词素的文本并为其创建一个新$token$。我们马上会使用另一个重载方法来处理带有字面值的$token$。

### $2.5.1$ 词法错误

在我们深入探讨之前，我们先花一点时间考虑一下词法层面的错误。如果用户抛入解释器的源文件中包含一些$Atguigu$中不使用的字符—如`@#^`，会发生什么？现在，这些字符被默默抛弃了。它们没有被$Atguigu$语言使用，但是不意味着解释器可以假装它们不存在。相反，我们应该报告一个错误：

> 在`Scanner.java`文件中，在`scanToken()`方法中添加

```java
      case '*': addToken(STAR); break; 

      default:
        Atguigu.error(line, "未预期字符。");
        break;
    }
```

注意，错误的字符仍然会被前面调用的`advance()`方法消费。这一点很重要，这样我们就不会陷入无限循环了。

另请注意，我们一直在扫描。 程序稍后可能还会出现其他错误。 如果我们能够一次检测出尽可能多的错误，将为我们的用户带来更好的体验。 否则，他们会看到一个小错误并修复它，但是却出现下一个错误，不断重复这个过程。语法错误“打地鼠”一点也不好玩。

因为`hadError`进行了赋值，我们永远不会尝试执行任何代码，即使程序在继续运行并扫描代码文件的其余部分。

### $2.5.2$ 操作符

我们的单字符词素已经生效了，但是这不能涵盖$Atguigu$中的所有操作符。比如`!`，这是单字符，对吧？有时候是的，但是如果下一个字符是等号，那么我们应该改用`!=`词素。注意，这里的`!`和`=` **不是** 两个独立的操作符。在$Atguigu$中，你不能写`! =`来表示不等操作符。这就是为什么我们需要将`!=`作为单个词素进行扫描。同样地，`<`、`>`和`=`都可以与后面跟随的`=`来组合成其他相等和比较操作符。

对于所有这些情况，我们都需要查看第二个字符。

> 在`Scanner.java`文件中，在`scanToken()`方法中添加

```java
      case '*': addToken(STAR); break; 
      case '!':
        addToken(match('=') ? BANG_EQUAL : BANG);
        break;
      case '=':
        addToken(match('=') ? EQUAL_EQUAL : EQUAL);
        break;
      case '<':
        addToken(match('=') ? LESS_EQUAL : LESS);
        break;
      case '>':
        addToken(match('=') ? GREATER_EQUAL : GREATER);
        break;
      default:
```

这些分支中使用了下面的新方法：

> 在`Scanner.java`文件中，添加到`scanToken()`方法后

```java
  private boolean match(char expected) {
    if (isAtEnd()) return false;
    if (source.charAt(current) != expected) return false;

    current++;
    return true;
  }
```

这就像一个有条件的`advance()`。只有当前字符是我们正在寻找的字符时，我们才会消费。

使用`match()`，我们分两个阶段识别这些词素。例如，当我们得到`!`时，我们会跳转到它的`case`分支。这意味着我们知道这个词素是以`!`开始的。然后，我们查看下一个字符，以确认词素是一个`!=`还是仅仅是一个`!`。

## $2.6$ 更长的词素

我们还缺少一个操作符：表示除法的`/`。这个字符需要一些特殊处理，因为注释也是以斜线开头的。

> 在`Scanner.java`文件中，在`scanToken()`方法中添加

```java
      break;
      case '/':
        if (match('/')) {
          // A comment goes until the end of the line.
          while (peek() != '\n' && !isAtEnd()) advance();
        } else {
          addToken(SLASH);
        }
        break;
      default:
```

这与其它的双字符操作符是类似的，区别在于我们找到第二个`/`时，还没有结束本次$token$。相反，我们会继续消费字符直至行尾。

这是我们处理较长词素的一般策略。当我们检测到一个词素的开头后，我们会分流到一些特定于该词素的代码，这些代码会不断地消费字符，直到结尾。

我们又有了一个辅助函数：

> 在`Scanner.java`文件中，在`match()`方法后添加

```java
  private char peek() {
    if (isAtEnd()) return '\0';
    return source.charAt(current);
  }
```

这有点像`advance()`方法，只是不会消费字符。这就是所谓的**lookahead(前瞻)**。因为它只关注当前未消费的字符，所以我们有 **一个前瞻字符** 。一般来说，数字越小，扫描器运行速度就越快。词法语法的规则决定了我们需要前瞻多少字符。幸运的是，大多数广泛使用的语言只需要提前一到两个字符。

注释是词素，但是它们没有含义，而且解析器也不想要处理它们。所以，我们达到注释末尾后，**不会** 调用`addToken()`方法。当我们循环处理下一个词素时，`start`已经被重置了，注释的词素就消失了。

既然如此，现在正好可以跳过其它那些无意义的字符了：换行和空格。

> 在`Scanner.java`文件中，在`scanToken()`方法中添加

```java
      	break;
      case ' ':
      case '\r':
      case '\t':
        // Ignore whitespace.
        break;

      case '\n':
        line++;
        break;
      default:
        Lox.error(line, "Unexpected character.");
```

当遇到空白字符时，我们只需回到扫描循环的开头。这样就会在空白字符之后开始一个新的词素。对于换行符，我们做同样的事情，但我们也会递增行计数器。（这就是为什么我们使用`peek()`而不是`match()`来查找注释结尾的换行符。我们到这里希望能读取到换行符，这样我们就可以更新行数了）

我们的扫描器越来越聪明了。它可以处理相当自由形式的代码，如：

```java
// this is a comment
(( )){} // grouping stuff
!*+-/=<> <= == // operators
```

### $2.6.1$ 字符串字面量

现在我们对长词素已经很熟悉了，我们可以开始处理字面量了。我们先处理字符串，因为字符串总是以一个特定的字符`"`开头。

> 在`Scanner.java`文件中，在`scanToken()`方法中添加

```java
      	break;
      case '"': string(); break;
      default:
```

这里会调用：

> 在`Scanner.java`文件中，在`scanToken()`方法之后添加

```java
  private void string() {
    while (peek() != '"' && !isAtEnd()) {
      if (peek() == '\n') line++;
      advance();
    }

    if (isAtEnd()) {
      Atguigu.error(line, "字符串未终结。");
      return;
    }

    // The closing ".
    advance();

    // Trim the surrounding quotes.
    String value = source.substring(start + 1, current - 1);
    addToken(STRING, value);
  }
```

与注释类似，我们会一直消费字符，直到`"`结束该字符串。如果输入内容耗尽，我们也会进行优雅的处理，并报告一个对应的错误。

没有特别的原因，$Atguigu$支持多行字符串。这有利有弊，但禁止换行比允许换行更复杂一些，所以我把它们保留了下来。这意味着当我们在字符串内遇到新行时，我们也需要更新`line`值。

最后，还有一个有趣的地方就是当我们创建$token$时，我们也会产生实际的字符串值，该值稍后将被解释器使用。这里，值的转换只需要调用`substring()`剥离前后的引号。如果$Atguigu$支持转义序列，比如`\n`，我们会在这里取消转义。

### $2.6.2$ 数值字面量

在$Atguigu$中，所有的数字在运行时都是浮点数，但是同时支持整数和小数字面量。一个数字字面量就是一系列数位，后面可以跟一个`.`和一或多个尾数。

```java
1234
12.34
```

我们不允许小数点处于最开始或最末尾，所以下面的格式是不正确的：

```java
.1234
1234.
```

我们可以很容易地支持前者，但为了保持简单，我把它删掉了。如果我们要允许对数字进行方法调用，比如`123.sqrt()`，后者会变得很奇怪。

为了识别数字词素的开头，我们会寻找任何一位数字。为每个十进制数字添加`case`分支有点乏味，所以我们直接在默认分支中进行处理。

> 在`Scanner.java`文件中，在`scanToken()`方法中替换一行

```java
      default:
        // 替换部分开始
      	if (isDigit(c)) {
          number();
        } else {
          Atguigu.error(line, "Unexpected character.");
        }
        // 替换部分结束
        break;
```

这里依赖下面的小工具函数：

> 在`Scanner.java`文件中，在`peek()`方法之后添加

```java
  private boolean isDigit(char c) {
    return c >= '0' && c <= '9';
  } 
```

一旦我们知道当前在处理数字，我们就分支进入一个单独的方法消费剩余的字面量，跟字符串的处理类似。

> 在`Scanner.java`文件中，在`scanToken()`方法后添加

```java
  private void number() {
    while (isDigit(peek())) advance();

    // Look for a fractional part.
    if (peek() == '.' && isDigit(peekNext())) {
      // Consume the "."
      advance();

      while (isDigit(peek())) advance();
    }

    addToken(NUMBER,
        Double.parseDouble(source.substring(start, current)));
  }
```

我们在字面量的整数部分中尽可能多地获取数字。然后我们寻找小数部分，也就是一个小数点(`.`)后面至少跟一个数字。如果确实有小数部分，同样地，我们也尽可能多地获取数字。

在定位到小数点之后需要前瞻两个字符，因为我们只有确认其 **后** 有数字才会消费`.`。所以我们添加了：

> 在`Scanner.java`文件中，在`peek()`方法后添加

```java
  private char peekNext() {
    if (current + 1 >= source.length()) return '\0';
    return source.charAt(current + 1);
  }
```

最后，我们将词素转换为其对应的数值。我们的解释器使用$Java$的`Double`类型来表示数字，所以我们创建一个该类型的值。我们使用$Java$自带的解析方法将词素转换为真正的$Java$ 的`double`类型。我们可以自己实现，但是，说实话，除非你想为即将到来的编程面试做准备，否则不值得你花时间。

剩下的词素是`Boolean`和`nil`，但我们把它们作为关键字来处理，这样我们就来到了以下内容：

## $2.7$ 保留字和标识符

我们的扫描器基本完成了，词法语法中还需要实现的部分仅剩标识符及其近亲—保留字。你也许会想，我们可以采用与处理`<=`等多字符操作符时相同的方法来匹配关键字，如`or`。

```java
case 'o':
  if (peek() == 'r') {
    addToken(OR);
  }
  break;
```

考虑一下，如果用户将变量命名为`orchid`会发生什么？扫描器会先看到前面的两个字符，然后立刻生成一个`or`标记。这就涉及到了一个重要原则，叫作**maximal munch**（最长匹配）。当两个语法规则都能匹配扫描器正在处理的一大块代码时，**哪个规则相匹配的字符最多，就使用哪个规则** 。

该规则规定，如果我们可以将`orchid`匹配为一个标识符，也可以将`or`匹配为一个关键字，那就采用第一种结果。这也就是为什么我们在前面会默认为，`<=`应该识别为单一的`<=`标记，而不是`<`后面跟了一个`=`。

最大匹配原则意味着，我们只有扫描完一个可能是标识符的片段，才能确认是否一个保留字。毕竟，保留字也是一个标识符，只是一个已经被语言要求为自己所用的标识符。这也是**保留字**一词的由来。

所以我们首先假设任何以字母或下划线开头的词素都是一个标识符。

> 在`Scanner.java`文件中，在`scanToken()`中添加代码

```java
        default:
        if (isDigit(c)) {
          number();
				// 新增部分开始
        } else if (isAlpha(c)) {
          identifier();
        // 新增部分结束
        } else {
          Atguigu.error(line, "Unexpected character.");
        }
```

其它代码如下：

> 在`Scanner.java`文件中，在`scanToken()`方法之后添加

```java
  private void identifier() {
    while (isAlphaNumeric(peek())) advance();

    addToken(IDENTIFIER);
  }
```

通过以下辅助函数来定义：

> 在`Scanner.java`文件中，在`peekNext()`方法之后添加

```java
  private boolean isAlpha(char c) {
    return (c >= 'a' && c <= 'z') ||
           (c >= 'A' && c <= 'Z') ||
            c == '_';
  }

  private boolean isAlphaNumeric(char c) {
    return isAlpha(c) || isDigit(c);
  }
```

这样标识符就开始工作了。为了处理关键字，我们要查看标识符的词素是否是保留字之一。如果是，我们就使用该关键字特有的标记类型。我们在`Map`中定义保留字的集合。

> 在`Scanner.java`文件中，在`Scanner`类中添加

```java
  private static final Map<String, TokenType> keywords;

  static {
    keywords = new HashMap<>();
    keywords.put("and",      AND);
    keywords.put("else",     ELSE);
    keywords.put("false",    FALSE);
    keywords.put("for",      FOR);
    keywords.put("function", FUNCTION);
    keywords.put("if",       IF);
    keywords.put("nil",      NIL);
    keywords.put("or",       OR);
    keywords.put("print",    PRINT);
    keywords.put("return",   RETURN);
    keywords.put("true",     TRUE);
    keywords.put("var",      VAR);
    keywords.put("while",    WHILE);
  }
```

接下来，在我们扫描到标识符之后，要检查是否与`Map`中的某些项匹配。

> 在`Scanner.java`文件中，在`identifier()`方法中替换一行

```java
    while (isAlphaNumeric(peek())) advance();

    // 替换部分开始
    String text = source.substring(start, current);
    TokenType type = keywords.get(text);
    if (type == null) type = IDENTIFIER;
    addToken(type);
    // 替换部分结束
  }
```

如果匹配的话，就使用关键字的$token$类型。否则，就是一个普通的用户定义的标识符。

至此，我们就有了一个完整的扫描器，可以扫描整个$Atguigu$词法语法。启动$REPL$，输入一些有效和无效的代码。它是否产生了你所期望的词法单元？试着想出一些有趣的边界情况，看看它是否能正确地处理它们。

# $3$ 抽象语法树

> 抽象语法树：$Abstract \; Syntax \; Tree$，$AST$

## $3.1$ 四则运算表达式的抽象语法树

我们可以思考一下一个表达式`1 + 2 * 3 - 4`的计算过程，如果使用人脑来进行计算的话，我们会先计算乘法，然后再计算加法，然后再计算减法，因为我们知道运算符的优先级。其实我们可以把人脑中的计算过程，也就是运算符的优先级使用树形结构表达出来，怎么样表达呢？内部节点是运算符，叶子节点是操作数。下面就是表达式的树形结构：

```mermaid
graph TB
	A(("-")) --> B(("+"))
	A --> C(("4"))
	B --> D(("1"))
	B --> E(("*"))
	E --> F(("2"))
	E --> G(("3"))
```

可以看到，运算符优先级越高，那么运算符节点的位置就越低。要想计算一个算术节点，我们就需要知道它的子树的数值，所以我们必须先计算子树的结果。这意味着要从叶节点一直计算到根节点—也就是 **后序** 遍历。计算过程如下：

1. 首先计算`2 * 3`这个子树，计算完以后，树形结构变成了：

```mermaid
graph TB
	A(("-")) --> B(("+"))
	A --> C(("4"))
	B --> D(("1"))
	B --> E(("6"))
```

2. 接下来计算`1 + 6`这个子树，计算完以后，树形结构变成了：

```mermaid
graph TB
	A(("-")) --> B(("7"))
	A --> C(("4"))
```

3. 接下来计算`7 - 4`这个子树，计算完以后，树形结构变成了，也就是最终的计算结果。

```mermaid
graph LR
	A(("3"))
```

当我们看着抽象语法树计算表达式时，我们是自底向上计算的，因为越接近底部的运算符优先级就越高，所以是 **后序遍历** 。我们可以再看一些四则运算表达式的抽象语法树表示：

`1 + 2`

```mermaid
graph TB
    A(("+")) --> B(("1"))
    A --> C(("2"))
```

`1+2*3`

```mermaid
graph TB
    A(("+")) --> B(("1"))
    A --> C(("*"))
    C --> D(("2"))
    C --> E(("3"))
```

`(1+2)*3`

```mermaid
graph TB
    A(("*")) --> B(("+"))
    A --> C(("3"))
    B --> D(("1"))
    B --> E(("2"))
```

`1+2+3`

```mermaid
graph TB
	A(("+")) --> B(("+"))
	B --> C(("1"))
	B --> D(("2"))
	A --> E(("3"))
```

我们现在大致了解了抽象语法树的概念，那么我们应该怎么使用代码表示上面的抽象语法树，然后来进行计算呢？下面我们就使用$Java$代码来实现表达式的抽象语法树的求值，将人脑中的计算过程转化成代码：

> 创建新文件`Expr.java`

```java
package com.atguigu;

public abstract class Expr {
}
```

这是一个抽象类，用来表示表达式。而每种具体的表达式类型需要继承`Expr`类。下面我们再定义一个二元表达式的数据结构：

> 创建新文件`Binary.java`

```java
package com.atguigu;

public class Binary extends Expr {
    public final Expr left;      // 二元表达式左侧的表达式
    public final Token operator; // 运算符
    public final Expr right;     // 二元表达式右侧的表达式

    public Binary(Expr left, Token operator, Expr right) {
        this.left = left;
        this.operator = operator;
        this.right = right;
    }
}
```

这里要注意的一点是，二元运算符的左侧和右侧都是表达式，例如`(1 + 2) * 3`的`*`的左侧的表达式是`1 + 2`，右侧的表达式是`3`。

我们现在可以表示二元表达式，那么数值表达式，也就是`1`这样的表达式应该如何构建数据结构呢？

> 创建新文件`Literal.java`

```java
package com.atguigu;

public class Literal extends Expr {
    public final Object value;

    public Literal(Object value) {
        this.value = value;
    }
}
```

现在我们就可以使用以上定义的几个数据结构来表示四则运算的抽象语法树了。表示出抽象语法树，我们就可以对抽象语法树进行求值了。例如`(1+2)*3`的求值程序如下：

```java
package com.atguigu;

public class TestAstCalc {
    public static void main(String[] args) {
        // (1+2)*3
        Expr ast = new Binary(
                new Binary(
                        new Literal(1),
                        new Token(TokenType.PLUS, null, null, 0),
                        new Literal(2)
                ),
                new Token(TokenType.STAR, null, null, 0),
                new Literal(3)
        );

        System.out.println(evaluate(ast));
    }

    public static Integer evaluate(Expr node) {
        // 如果遍历到叶子节点，也就是数值，直接返回
        if (node instanceof Literal) {
            return (int) ((Literal) node).value;
        } else if (node instanceof Binary) {
            // 先遍历左子树
            Integer l = evaluate(((Binary) node).left);
            // 再遍历右子树
            Integer r = evaluate(((Binary) node).right);
            // 遍历根节点，判断根节点运算符的类型，并计算。
            if (((Binary) node).operator.type == TokenType.PLUS) {
                return l + r;
            } else if (((Binary) node).operator.type == TokenType.STAR) {
                return l * r;
            }
        }
        return null;
    }
}
```

注意，我们在代码中不能直接将`1+2`的左子树节点写成`1`,因为`1`也是树型结构中的节点，所以需要写成`new Literal(1)`。然后我们在求值时，对抽象语法树进行后序遍历，就可以求值出结果为`9`。

好，现在的问题来了。我们如何将已经生成的标记（$token$）序列，转换成抽象语法树呢？也就是如何将`(1+2)*3`的标记序列：

```mermaid
graph LR
	A["LEFT_PAREN"] --> B["1"] --> C["PLUS"] --> D["2"]
	D --> E["RIGHT_PAREN"] --> F["STAR"] --> G["3"]
```

转换成如下树形结构呢？

```mermaid
graph TB
	A(("*")) --> B(("+"))
	A --> C(("3"))
	B --> D(("1"))
	B --> F(("2"))
```

所以我们要开始介绍上下文无关文法了。

## $3.2$ 上下文无关文法

> 上下无关文法：$Context \; Free \; Grammar$，$CFG$

在上一章中，我们用来定义词法语法（字符如何被分组为词法标记的规则）的形式体系，被称为 **正则语言** 。这对于我们的词法分析器来说没什么问题，因为它输出的是一个扁平的词法标记序列。但正则语言还不够强大，无法处理可以任意深度嵌套的表达式。

> 例如，使用正则表达式无法检测括号匹配问题。

### $3.2.1$ 文法规则

我们还需要一个更强大的工具，就是 **上下文无关文法** 。不要被这个名词吓到，其实它并不难理解，就是定义了语言的语法规则而已。例如，我们可以举一个简单的例子，就是数字的加法的文法表示：

```js
expression = number "+" number ;
number     = "0" ... "9" ;
```

那么上面的文法就是规定了`1 + 2`，`5 + 8`这样的表达式的文法。

| `expression` | `number` | `+`  | `number` |
| ------------ | -------- | ---- | -------- |
| `1 + 2`      | `1`      | `+`  | `1`      |

那么多个数的加法的文法如何表示呢？例如：`1 + 2 + 3 + 4`。可以如下表示:

```js
expression = number ( "+" number )* ;
number     = "0"..."9" ;
```

文法中的`*`号是匹配`0`次或者`1`次或者多次的意思，也就是正则表达式的语法。

`1`这个数值表达式就是匹配$0$次的情况。`1+2`这个表达式就是匹配$1$次的情况。`1+2+3`这个表达式就是匹配$2$次的情况。

在学术上，`expression`叫做 **非终结符** 。因为`expression`右边的`number`还可以继续展开。而`number`就是 **终结符** 了，因为`number`的右边已经没有需要继续展开的符号了。

而以上描述语言的文法的方式叫做$EBNF$（扩展的巴克斯范式）。

我们现在来看一下如何使用$EBNF$来分析一个表达式`1+2+3`，由于`1+2+3`这个字符串显然无法匹配`number`规则，所以需要匹配`expression`非终结符。

```
   1 + 2 + 3
-> expression
-> "1" ( "+" number )*
-> "1" "+" "2" ( "+" number)*
-> "1" "+" "2" "+" "3"
```

这样展开，就匹配成功了，说明`1+2+3`表达式符合我们所定义的语法。而`1+2-3`就不符合我们的语法了。

### $3.2.2$ $EBNF$中的正则符号

我们引入了几个正则表达式中的符号，来方便编写语言的语法。

- `|`符号表示或者。下面的语法表示`digit`是`0`、`1`、`2`这三个字符中的一个。

  ```js
  digit = "0" | "1" | "2" ;
  ```

- 此外，我们允许用括号进行分组，然后在分组中可以用`|`表示从一系列生成式中选择一个。

  ```js
  number = ( "-" | "+" ) "1" ;
  ```

- 使用递归来支持符号的重复序列有一定的吸引力，但每次我们要循环的时候，都要创建一个单独的命名子规则，有点繁琐。所以，我们也使用后缀`*`来允许前一个符号或组重复零次或多次。以下是一般编程语言中标识符（变量名，函数名之类的）的语法规则，可以匹配`"a"`，`"a_1"`这样的标识符。

  ```js
  identifier = alpha ( alpha | number )* ;
  alpha      = "a" ... "z" | "A" ... "Z" | "_" ;
  number     = "0" ... "9" ;
  ```

- 后缀`+`与此类似，但要求前面的生成式至少出现一次。

  ```js
  crispiness → "really"+ ;
  ```

- 后缀`?`表示可选生成式，它之前的生成式可以出现零次或一次，但不能出现多次。以下的语法可以表示`1`、`-1`和`+1`这三个字符串。

  ```js
  number = ( "-" | "+" )? "1" ;
  ```



在本书的其余部分中，我们将使用这种表示法来精确地描述$Atguigu$的语法。当您使用编程语言时，您会发现上下文无关的语法（使用此语法或EBNF或其他一些符号）可以帮助您将非正式的语法设计思想具体化。

我们为$Atguigu$定义的规则和生成式也是我们将要实现的树数据结构（用于表示内存中的代码）的指南。在此之前，我们需要为$Atguigu$编写一个实际的语法，或者至少要有一个足够上手的语法。

### $3.2.3$ $Atguigu$表达式语法

在上一章中，我们一气呵成地完成了$Atguigu$的全部词汇语法，包括每一个关键词和标点符号。但句法语法的规模更大，如果在我们真正启动并运行解释器之前，就要把整个语法啃完，那就太无聊了。

相反，我们将在接下来的几章中摸索该语言的一个子集。一旦我们可以对这个迷你语言进行表示、解析和解释，那么在之后的章节中将逐步为它添加新的特性，包括新的语法。现在，我们只关心几个表达式：

- **字面量**。数字、字符串、布尔值以及`nil`。

- **一元表达式**。前缀`!`执行逻辑非运算，`-`对数字求反。

- **二元表达式**。我们已经知道的中缀算术符（`+`，`-`，`*`，`/`）和逻辑运算符（`==`，`!=`，`<`，`<=`，`>`，`>=`）。

- **括号**。表达式前后的一对`(`和`)`。

这已经为表达式提供了足够的语法，例如：

```
1 - (2 * 3) < 4 == false
```

使用我们的新符号，下面是语法的表示：

```js
expression     → literal
               | unary
               | binary
               | grouping ;

literal        → NUMBER | STRING | "true" | "false" | "nil" ;
grouping       → "(" expression ")" ;
unary          → ( "-" | "!" ) expression ;
binary         → expression operator expression ;
operator       → "==" | "!=" | "<" | "<=" | ">" | ">="
               | "+"  | "-"  | "*" | "/" ;
```

这里有一点额外的元语法。除了与精确词素相匹配的终止符会加引号外，我们还对表示单一词素的终止符进行 **大写化** ，这些词素的文本表示方式可能会有所不同。`NUMBER`是任何数字字面量，`STRING`是任何字符串字面量。稍后，我们将对`IDENTIFIER`进行同样的处理。

这个语法实际上是模棱两可的，我们在解析它时就会看到这一点。但现在这已经足够了。

## $3.2$ 实现语法树

最后，我们要写一些代码。这个小小的表达式语法就是我们的骨架。由于语法是递归的—请注意`grouping`，`unary`，和`binary`都是指回`expression`的—我们的数据结构将形成一棵树。因为这个结构代表了我们语言的语法，所以叫做**语法树**。

我们的扫描器使用一个单一的 `Token` 类来表示所有类型的词素。为了区分不同的种类—想想数字 `123` 和字符串 `"123"`—我们创建了一个简单的 `TokenType` 枚举。语法树并不是那么同质的。一元表达式只有一个操作数，二元表达式有两个操作数，而字面量则没有。

我们 **可以** 将所有这些内容整合到一个包含任意子类列表的 `Expression` 类中。有些编译器会这么做。但我希望充分利用$Java$的类型系统。所以我们将为表达式定义一个基类。然后，对于每一种表达式—`expression`下的每一个生成式—我们创建一个子类，这个子类有该规则所特有的非终止符字段。这样，如果试图访问一元表达式的第二个操作数，就会得到一个编译错误。

类似这样：

```java
package com.atguigu;

public abstract class Expr { 
  static class Binary extends Expr {
    Binary(Expr left, Token operator, Expr right) {
      this.left = left;
      this.operator = operator;
      this.right = right;
    }

    final Expr left;
    final Token operator;
    final Expr right;
  }

  // Other expressions...
}
```

`Expr`是所有表达式类继承的基类。从`Binary`中可以看到，子类都嵌套在它的内部。这在技术上没有必要，但它允许我们将所有类都塞进一个$Java$文件中。

### $3.2.1$ 非面向对象

你会注意到，（表达式类）像`Token`类一样，其中没有任何方法。这是一个很愚蠢的结构，巧妙的类型封装，但仅仅是一包数据。这在$Java$这样的面向对象语言中会有些奇怪，难道类不是应该**做一些事情**吗？

问题在于这些树类不属于任何单个的领域。树是在解析的时候创建的，难道类中应该有解析对应的方法？或者因为树结构在解释的时候被消费，其中是不是要提供解释相关的方法？树跨越了这些领域之间的边界，这意味着它们实际上不属于任何一方。

事实上，这些类型的存在是为了让语法分析器和解释器能够*进行交流*。这就适合于那些只是简单的数据而没有相关行为的类型。

### $3.2.2$ 节点树元编程

Java可以表达无行为的类，但很难说它特别擅长。用11行代码在一个对象中填充3个字段是相当乏味的，当我们全部完成后，我们将有21个这样的类。

我不想浪费你的时间或我的墨水把这些都写下来。真的，每个子类的本质是什么?一个名称和一个字段列表而已。我们是聪明的语言黑客，对吧?我们把它自动化。

与其繁琐地手写每个类的定义、字段声明、构造函数和初始化器，我们一起编写一个脚本来完成任务。 它具有每种树类型（名称和字段）的描述，并打印出定义具有该名称和状态的类所需的Java代码。

该脚本是一个微型Java命令行应用程序，它生成一个名为“ Expr.java”的文件：

*<u>tool/GenerateAst.java，创建新文件</u>*

```java
package com.craftinginterpreters.tool;

import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.List;

public class GenerateAst {
  public static void main(String[] args) throws IOException {
    if (args.length != 1) {
      System.err.println("Usage: generate_ast <output directory>");
      System.exit(64);
    }
    String outputDir = args[0];
  }
}
```

注意，这个文件在另一个包中，是`.tool`而不是`.lox`。这个脚本并不是解释器本身的一部分，它是一个工具，我们这种编写解释器的人，通过运行该脚本来生成语法树类。完成后，我们把“Expr.java”与实现中的其它文件进行相同的处理。我们只是自动化了文件的生成方式。

为了生成类，还需要对每种类型及其字段进行一些描述。

*<u>tool/GenerateAst.java，在 main()方法中添加</u>*

```java
    String outputDir = args[0];
    // 新增部分开发
    defineAst(outputDir, "Expr", Arrays.asList(
      "Binary   : Expr left, Token operator, Expr right",
      "Grouping : Expr expression",
      "Literal  : Object value",
      "Unary    : Token operator, Expr right"
    ));
    // 新增部分结束
  }
```

为简便起见，我将表达式类型的描述放入了字符串中。 每一项都包括类的名称，后跟`：`和以逗号分隔的字段列表。 每个字段都有一个类型和一个名称。

`defineAst()`需要做的第一件事是输出基类Expr。

*<u>tool/GenerateAst.java，在 main()方法后添加：</u>*

```java
  private static void defineAst(
      String outputDir, String baseName, List<String> types)
      throws IOException {
    String path = outputDir + "/" + baseName + ".java";
    PrintWriter writer = new PrintWriter(path, "UTF-8");

    writer.println("package com.craftinginterpreters.lox;");
    writer.println();
    writer.println("import java.util.List;");
    writer.println();
    writer.println("abstract class " + baseName + " {");

    writer.println("}");
    writer.close();
  }
```

我们调用这个函数时，`baseName`是“Expr”，它既是类的名称，也是它输出的文件的名称。我们将它作为参数传递，而不是对名称进行硬编码，因为稍后我们将为语句添加一个单独的类族。

在基类内部，我们定义每个子类。

*<u>tool/GenerateAst.java，在 defineAst()类中添加[^13]：</u>*

```java
    writer.println("abstract class " + baseName + " {");
    // 新增部分开始
    // The AST classes.
    for (String type : types) {
      String className = type.split(":")[0].trim();
      String fields = type.split(":")[1].trim(); 
      defineType(writer, baseName, className, fields);
    }
    // 新增部分结束
    writer.println("}");
```

这段代码依次调用：

*<u>tool/GenerateAst.java，在 defineAst()后面添加：</u>*

```java
  private static void defineType(
      PrintWriter writer, String baseName,
      String className, String fieldList) {
    writer.println("  static class " + className + " extends " +
        baseName + " {");

    // Constructor.
    writer.println("    " + className + "(" + fieldList + ") {");

    // Store parameters in fields.
    String[] fields = fieldList.split(", ");
    for (String field : fields) {
      String name = field.split(" ")[1];
      writer.println("      this." + name + " = " + name + ";");
    }

    writer.println("    }");

    // Fields.
    writer.println();
    for (String field : fields) {
      writer.println("    final " + field + ";");
    }

    writer.println("  }");
  }
```

好了。所有的Java模板都完成了。它在类体中声明了每个字段。它为类定义了一个构造函数，为每个字段提供参数，并在类体中对其初始化。

现在编译并运行这个Java程序，它会生成一个新的`.Java`文件，其中包含几十行代码。那份文件还会变得更长。

## 4.3 处理树结构

先想象一下吧。尽管我们还没有到那一步，但请考虑一下解释器将如何处理语法树。$Atguigu$中的每种表达式在运行时的行为都不一样。这意味着解释器需要选择不同的代码块来处理每种表达式类型。对于词法标记，我们可以简单地根据`TokenType`进行转换。但是我们并没有为语法树设置一个 "type "枚举，只是为每个语法树单独设置一个$Java$类。

我们可以编写一长串类型测试：

```java
if (expr instanceof Expr.Binary) {
  // ...
} else if (expr instanceof Expr.Grouping) {
  // ...
} else // ...
```

但所有这些顺序类型测试都很慢。类型名称按字母顺序排列在后面的表达式，执行起来会花费更多的时间，因为在找到正确的类型之前，它们会遇到更多的`if`情况。这不是我认为的优雅解决方案。

我们有一个类族，我们需要将一组行为与每个类关联起来。在Java这样的面向对象语言中，最自然的解决方案是将这些行为放入类本身的方法中。我们可以在Expr上添加一个抽象的`interpret()`方法，然后每个子类都要实现这个方法来解释自己。

这对于小型项目来说还行，但它的扩展性很差。就像我之前提到的，这些树类跨越了几个领域。至少，解析器和解释器都会对它们进行干扰。稍后您将看到，我们需要对它们进行名称解析。如果我们的语言是静态类型的，我们还需要做类型检查。

### 4.3.1 表达式问题

这个问题比起初看起来更基础。我们有一些类型，和一些高级操作，比如“解释”。对于每一对类型和操作，我们都需要一个特定的实现。画一个表：

![A table where rows are labeled with expression classes, and columns are function names.](5.表示代码/table.png)

行是类型，列是操作。每个单元格表示在该类型上实现该操作的唯一代码段。

像Java这样的面向对象的语言，假定一行中的所有代码都自然地挂在一起。它认为你对一个类型所做的所有事情都可能是相互关联的，而使用这类语言可以很容易将它们一起定义为同一个类里面的方法。

![The table split into rows for each class.](5.表示代码/rows.png)

这种情况下，向表中加入新行来扩展列表是很容易的，简单地定义一个新类即可，不需要修改现有的代码。但是，想象一下，如果你要添加一个新操作（新的一行）。在Java中，这意味着要拆开已有的那些类并向其中添加方法。

ML家族中的函数式范型反过来了。在这些语言中，没有带方法的类，类型和函数是完全独立的。要为许多不同类型实现一个操作，只需定义一个函数。在该函数体中，您可以使用*模式匹配*（某种基于类型的switch操作）在同一个函数中实现每个类型对应的操作。

这使得添加新操作非常简单—只需定义另一个与所有类型模式匹配的的函数即可。

![The table split into columns for each function.](5.表示代码/columns.png)

但是，反过来说，添加新类型是困难的。您必须回头向已有函数中的所有模式匹配添加一个新的case。

每种风格都有一定的 "纹路"。这就是范式名称的字面意思——面向对象的语言希望你按照类型的行来*组织*你的代码。而函数式语言则鼓励你把每一列的代码都归纳为一个*函数*。

一群聪明的语言迷注意到，这两种风格都不容易向表格中添加行和列。他们称这个困难为“表达式问题”[^17]。就像我们现在一样，他们是在试图找出在编译器中建模表达式语法树节点的最佳方法时，第一次遇到了该问题。

人们已经抛出了各种各样的语言特性、设计模式和编程技巧，试图解决这个问题，但还没有一种完美的语言能够解决它。与此同时，我们所能做的就是尽量选择一种与我们正在编写的程序的自然架构相匹配的语言。

面向对象在我们的解释器的许多部分都可以正常工作，但是这些树类与Java的本质背道而驰。 幸运的是，我们可以采用一种设计模式来解决这个问题。

### 4.3.2 访问者模式

**访问者模式**是所有*设计模式*中最容易被误解的模式，当您回顾过去几十年的软件架构泛滥状况时，会发现确实如此。

问题出在术语上。这个模式不是关于“visiting（访问）”，它的 “accept”方法也没有让人产生任何有用的想象。许多人认为这种模式与遍历树有关，但事实并非如此。我们确实要在一组树结构的类上使用它，但这只是一个巧合。如您所见，该模式在单个对象上也可以正常使用。

访问者模式实际上近似于OOP语言中的函数式。它让我们可以很容易地向表中添加新的列。我们可以在一个地方定义针对一组类型的新操作的所有行为，而不必触及类型本身。这与我们解决计算机科学中几乎所有问题的方式相同：添加中间层。

在将其应用到自动生成的Expr类之前，让我们先看一个更简单的例子。比方说我们有两种点心:Beignet(卷饼)和Cruller(油酥卷)。

```java
 abstract class Pastry {
  }

  class Beignet extends Pastry {
  }

  class Cruller extends Pastry {
  }
```

我们希望能够定义新的糕点操作（烹饪，食用，装饰等），而不必每次都向每个类添加新方法。我们是这样做的。首先，我们定义一个单独的接口[^18]。

```java
  interface PastryVisitor {
    void visitBeignet(Beignet beignet); 
    void visitCruller(Cruller cruller);
  }
```

可以对糕点执行的每个操作都是实现该接口的新类。 它对每种类型的糕点都有具体的方法。 这样一来，针对两种类型的操作代码都紧密地嵌套在一个类中。

给定一个糕点，我们如何根据其类型将其路由到访问者的正确方法？多态性拯救了我们！我们在Pastry中添加这个方法：

```java
  abstract class Pastry {
    abstract void accept(PastryVisitor visitor);
  }
```

每个子类都需要实现该方法：

```java
  class Beignet extends Pastry {
    @Override
    void accept(PastryVisitor visitor) {
      visitor.visitBeignet(this);
    }
  }
```

以及：

```java
  class Cruller extends Pastry {
    @Override
    void accept(PastryVisitor visitor) {
      visitor.visitCruller(this);
    }
  }
```

要对糕点执行一个操作，我们就调用它的`accept()`方法，并将我们要执行的操作vistor作为参数传入该方法。pastry类——特定子类对`accept()`的重写实现——会反过来，在visitor上调用合适的visit方法，并将*自身*作为参数传入。

这就是这个技巧的核心所在。它让我们可以在*pastry*类上使用多态派遣，在*visitor*类上选择合适的方法。对应在表格中，每个pastry类都是一行，但如果你看一个visitor的所有方法，它们就会形成一*列*。

![Now all of the cells for one operation are part of the same class, the visitor.](5.表示代码/visitor.png)

我们为每个类添加了一个`accept（）`方法，我们可以根据需要将其用于任意数量的访问者，而无需再次修改*pastry*类。 这是一个聪明的模式。

### 4.3.3 表达式访问者

好的，让我们将它编入表达式类中。我们还要对这个模式进行一下完善。在糕点的例子中，visit和`accept()`方法没有返回任何东西。在实践中，访问者通常希望定义能够产生值的操作。但`accept()`应该具有什么返回类型呢？我们不能假设每个访问者类都想产生相同的类型，所以我们将使用泛型来让每个实现类自行填充一个返回类型。

首先，我们定义访问者接口。同样，我们把它嵌套在基类中，以便将所有的内容都放在一个文件中。

*<u>tool/GenerateAst.java，在 defineAst()方法中添加：</u>*

```java
    writer.println("abstract class " + baseName + " {");
		// 新增部分开始
		defineVisitor(writer, baseName, types);
		// 新增部分结束
    // The AST classes.
```

这个函数会生成visitor接口。

*<u>tool/GenerateAst.java，在 defineAst()方法后添加：</u>*

```java
  private static void defineVisitor(
      PrintWriter writer, String baseName, List<String> types) {
    writer.println("  interface Visitor<R> {");

    for (String type : types) {
      String typeName = type.split(":")[0].trim();
      writer.println("    R visit" + typeName + baseName + "(" +
          typeName + " " + baseName.toLowerCase() + ");");
    }

    writer.println("  }");
  }
```

在这里，我们遍历所有的子类，并为每个子类声明一个visit方法。当我们以后定义新的表达式类型时，会自动包含这些内容。

在基类中，定义抽象 `accept()` 方法。

*<u>tool/GenerateAst.java，在 defineAst()方法中添加：</u>*

```java
    	defineType(writer, baseName, className, fields);
    }
    // 新增部分开始
    // The base accept() method.
    writer.println();
    writer.println("  abstract <R> R accept(Visitor<R> visitor);");
    // 新增部分结束
    writer.println("}");
```

最后，每个子类都实现该方法，并调用其类型对应的visit方法。

*<u>tool/GenerateAst.java，在 defineType()方法中添加：</u>*

```java
    writer.println("    }");
    // 新增部分开始
    // Visitor pattern.
    writer.println();
    writer.println("    @Override");
    writer.println("    <R> R accept(Visitor<R> visitor) {");
    writer.println("      return visitor.visit" +
        className + baseName + "(this);");
    writer.println("    }");
    // 新增部分结束
    // Fields.
```

这下好了。现在我们可以在表达式上定义操作，而且无需对类或生成器脚本进行修改。编译并运行这个生成器脚本，输出一个更新后的 "Expr.java "文件。该文件中包含一个生成的Visitor接口和一组使用该接口支持Visitor模式的表达式节点类。

在结束这一章的闲聊之前，我们先实现一下这个Visitor接口，看看这个模式的运行情况。

## 4.4 一个（不是很）漂亮的打印器

当我们调试解析器和解释器时，查看解析后的语法树并确保其与期望的结构一致通常是很有用的。我们可以在调试器中进行检查，但那可能有点难。

相反，我们需要一些代码，在给定语法树的情况下，生成一个明确的字符串表示。将语法树转换为字符串是解析器的逆向操作，当我们的目标是产生一个在源语言中语法有效的文本字符串时，通常被称为 "漂亮打印"。

这不是我们的目标。我们希望字符串非常明确地显示树的嵌套结构。如果我们要调试的是操作符的优先级是否处理正确，那么返回`1 + 2 * 3`的打印器并没有什么用，我们想知道`+`或`*`是否在语法树的顶部。

因此，我们生成的字符串表示形式不是Lox语法。相反，它看起来很像Lisp。每个表达式都被显式地括起来，并且它的所有子表达式和词法标记都包含在其中。

给定一个语法树，如：

![An example syntax tree.](5.表示代码/expression.png)

输出结果为：

```js
(* (- 123) (group 45.67))
```

不是很“漂亮”，但是它确实明确地展示了嵌套和分组。为了实现这一点，我们定义了一个新类。

*<u>lox/AstPrinter.java，创建新文件：</u>*

```java
package com.craftinginterpreters.lox;

class AstPrinter implements Expr.Visitor<String> {
  String print(Expr expr) {
    return expr.accept(this);
  }
}
```

如你所见，它实现了visitor接口。这意味着我们需要为我们目前拥有的每一种表达式类型提供visit方法。

*<u>lox/AstPrinter.java，在 print()方法后添加：</u>*

```java
  return expr.accept(this);
  }
	// 新增部分开始
	@Override
  public String visitBinaryExpr(Expr.Binary expr) {
    return parenthesize(expr.operator.lexeme,
                        expr.left, expr.right);
  }

  @Override
  public String visitGroupingExpr(Expr.Grouping expr) {
    return parenthesize("group", expr.expression);
  }

  @Override
  public String visitLiteralExpr(Expr.Literal expr) {
    if (expr.value == null) return "nil";
    return expr.value.toString();
  }

  @Override
  public String visitUnaryExpr(Expr.Unary expr) {
    return parenthesize(expr.operator.lexeme, expr.right);
  }
	// 新增部分结束
}
```

字面量表达式很简单——它们将值转换为一个字符串，并通过一个小检查用Java中的`null`代替Lox中的`nil`。其他表达式有子表达式，所以它们要使用`parenthesize()`这个辅助方法：

*<u>lox/AstPrinter.java，在 visitUnaryExpr()方法后添加：</u>*

```java
  private String parenthesize(String name, Expr... exprs) {
    StringBuilder builder = new StringBuilder();

    builder.append("(").append(name);
    for (Expr expr : exprs) {
      builder.append(" ");
      builder.append(expr.accept(this));
    }
    builder.append(")");

    return builder.toString();
  }
```

它接收一个名称和一组子表达式作为参数，将它们全部包装在圆括号中，并生成一个如下的字符串：

```
(+ 1 2)
```

请注意，它在每个子表达式上调用`accept()`并将自身传递进去。 这是递归步骤，可让我们打印整棵树。

我们还没有解析器，所以很难看到它的实际应用。现在，我们先使用一个`main()`方法来手动实例化一个树并打印它。

*<u>lox/AstPrinter.java，在 parenthesize()方法后添加：</u>*

```java
  public static void main(String[] args) {
    Expr expression = new Expr.Binary(
        new Expr.Unary(
            new Token(TokenType.MINUS, "-", null, 1),
            new Expr.Literal(123)),
        new Token(TokenType.STAR, "*", null, 1),
        new Expr.Grouping(
            new Expr.Literal(45.67)));

    System.out.println(new AstPrinter().print(expression));
  }
```

如果我们都做对了，它就会打印：

```js
(* (- 123) (group 45.67))
```

您可以继续删除这个方法，我们后面不再需要它了。另外，当我们添加新的语法树类型时，我不会在AstPrinter中展示它们对应的visit方法。如果你想这样做(并且希望Java编译器不会报错)，那么你可以自行添加这些方法。在下一章，当我们开始将Lox代码解析为语法树时，它将会派上用场。或者，如果你不想维护AstPrinter，可以随意删除它。我们不再需要它了。

# 5. 对表达式进行语法分析

本章是本书的第一个重要里程碑。我们中的许多人都曾将正则表达式和字符串操作的糅合在一起，以便从一堆文本中提取一些信息。这些代码可能充满了错误，而且很难维护。编写一个真正的解析器—具有良好的错误处理、一致的内部结构和能够健壮地分析复杂语法的能力—被认为是一种罕见的、令人印象深刻的技能。在这一章中，你将获得这种技能。

这比想象中要简单，部分是因为我们在上一章中提前完成了很多困难的工作。你已经对形式化语法了如指掌，也熟悉了语法树，而且我们有一些Java类来表示它们。唯一剩下的部分是解析—将一个标记序列转换成这些语法树中的一个。

## 5.1 歧义与解析游戏

在上一章中，我说过你可以像“玩”游戏一样使用上下文无关的语法来*生成*字符串。解析器则以相反的方式玩游戏。给定一个字符串(一系列语法标记)，我们将这些标记映射到语法中的终止符，以确定哪些规则可能生成该字符串。

"可能产生 "这部分很有意思。我们完全有可能创建一个*模棱两可*的语法，在这个语法中，不同的生成式可能会得到同一个字符串。当你使用该语法来*生成*字符串时，这一点不太重要。一旦你有了字符串，谁还会在乎你是怎么得到它的呢？

但是在解析时，歧义意味着解析器可能会误解用户的代码。当我们进行解析时，我们不仅要确定字符串是不是有效的Lox代码，还要记录哪些规则与代码的哪些部分相匹配，以便我们知道每个标记属于语言的哪一部分。下面是我们在上一章整理的Lox表达式语法：

```js
expression     → literal
               | unary
               | binary
               | grouping ;

literal        → NUMBER | STRING | "true" | "false" | "nil" ;
grouping       → "(" expression ")" ;
unary          → ( "-" | "!" ) expression ;
binary         → expression operator expression ;
operator       → "==" | "!=" | "<" | "<=" | ">" | ">="
               | "+"  | "-"  | "*" | "/" ;
```

下面是一个满足语法的有效字符串：

![6 / 3 - 1](6.解析表达式/tokens.png)

但是，有两种方式可以生成该字符串。其一是：

1. 从`expression`开始，选择`binary`。
2. 对于左边的`expression`，选择`NUMBER`，并且使用`6`。
3. 对于操作符，选择`/`。
4. 对于右边的`expression`，再次选择`binary`。
5. 在内层的`binary` 表达式中，选择`3-1`。

其二是：

1. 从`expression`开始，选择`binary`。
2. 对于左边的`expression`，再次选择`binary`。
3. 在内层的`binary` 表达式中，选择`6/3`。
4. 返回外层的`binary` ，对于操作符，选择`-`。
5. 对于右边的`expression`，选择`NUMBER`，并且使用`1`。

它们产生相同的字符串，但对应的是不同的*语法树*：

![Two valid syntax trees: (6 / 3) - 1 and 6 / (3 - 1)](6.解析表达式/syntax-trees.png)

换句话说，这个语法可以将该表达式看作是 `(6 / 3) - 1`或`6 / (3 - 1)`。`binary` 规则运行操作数以任意方式嵌套，这反过来又会影响解析数的计算结果。自从黑板被发明以来，数学家们解决这种模糊性的方法就是定义优先级和结合性规则。

- **优先级**决定了在一个包含不同运算符的混合表达式中，哪个运算符先被执行。优先级规则告诉我们，在上面的例子中，我们在`-`之前先计算`/`。优先级较高的运算符在优先级较低的运算符之前计算。同样，优先级较高的运算符被称为 "更严格的绑定"。

- **结合性**决定在一系列相同操作符中先计算哪个操作符。如果一个操作符是**左结合**的(可以认为是“从左到右”)时，左边的操作符在右边的操作符之前计算。因为`-`是左结合的，下面的表达式：

  ```java
  5 - 3 - 1
  ```

  等价于：

  ```java
  (5 - 3) - 1
  ```

  另一方面，赋值是**右结合**的。如：

  ```java
  a = b = c
  ```

  等价于：

  ```java
  a = (b = c)
  ```

如果没有明确定义的优先级和结合性，使用多个运算符的表达式可能就会变得有歧义——它可以被解析为不同的语法树，而这些语法树又可能会计算出不同的结果。我们在Lox中会解决这个问题，使用与C语言相同的优先级规则，从低到高分别是：

| Name              | Operators         | Associates    |
| ----------------- | ----------------- | ------------- |
| Equality  等于    | `==` `!=`         | Left  左结合  |
| Comparison  比较  | `>` `>=` `<` `<=` | Left  左结合  |
| Term  加减运算    | `-` `+`           | Left  左结合  |
| Factor   乘除运算 | `/` `*`           | Left  左结合  |
| Unary  一元运算符 | `!` `-`           | Right  右结合 |

现在，该语法将所有表达式类型都添加到一个 `expression`规则中。这条规则同样作用于操作数中的非终止符，这使得语法中可以接受任何类型的表达式作为子表达式，而不管优先级规则是否允许。

我们通过对语法进行分层来解决这个问题。我们为每个优先级定义一个单独的规则。

```js
expression     → ...
equality       → ...
comparison     → ...
term           → ...
factor         → ...
unary          → ...
primary        → ...
```

此处的每个规则仅匹配其当前优先级或更高优先级的表达式。 例如，`unary` 匹配一元表达式（如 `!negated`）或主表达式（如`1234`）。`term`可以匹配`1 + 2`，但也可以匹配`3 * 4 /5`。最后的`primary` 规则涵盖优先级最高的形式—字面量和括号表达式。

我们只需要填写每条规则的生成式。我们先从简单的开始。顶级的`expression` 规则可以匹配任何优先级的表达式。由于`equality`的优先级最低，只要我们匹配了它，就涵盖了一切。

```
expression     → equality
```

在优先级表的另一端，`primary`表达式包括所有的字面量和分组表达式。

```js
primary        → NUMBER | STRING | "true" | "false" | "nil"
               | "(" expression ")" ;
```

一元表达式以一元操作符开头，后跟操作数。因为一元操作符可以嵌套——`!!true`虽奇怪也是可用的表达式——这个操作数本身可以是一个一元表达式。递归规则可以很好地解决这个问题。

```js
unary          → ( "!" | "-" ) unary ;
```

但是这条规则有一个问题，它永远不会终止。

请记住，每个规则都需要匹配该优先级或更高优先级的表达式，因此我们还需要使其与主表达式匹配。

```js
unary          → ( "!" | "-" ) unary
               | primary ;
```

这样就可以了。

剩下的规则就是二元运算符。我们先从乘法和除法的规则开始。下面是第一次尝试：

```js
factor         → factor ( "/" | "*" ) unary
               | unary ;
```

该规则递归匹配左操作数，这样一来，就可以匹配一系列乘法和除法表达式，例如 `1 * 2 / 3`。将递归生成式放在左侧并将`unary` 放在右侧，可以使该规则具有左关联性和明确性[^6]。

所有这些都是正确的，但规则主体中的第一个符号与规则头部相同意味着这个生成式是**左递归**的。一些解析技术，包括我们将要使用的解析技术，在处理左递归时会遇到问题。(其他地方的递归，比如在`unary`中，以及在`primary`分组中的间接递归都不是问题。)

你可以定义很多符合同一种语言的语法。如何对某一特定语言进行建模，一部分是品味问题，一部分是实用主义问题。这个规则是正确的，但对于我们后续的解析来说它并不是最优的。我们将使用不同的规则来代替左递归规则。

```js
factor         → unary ( ( "/" | "*" ) unary )* ;
```

我们将因子表达式定义为乘法和除法的扁平*序列*。这与前面的规则语法相同，但更好地反映了我们将编写的解析Lox的代码。我们对其它二进制运算符的优先级使用相同的结构，从而得到下面这个完整的表达式语法：

```js
expression     → equality ;
equality       → comparison ( ( "!=" | "==" ) comparison )* ;
comparison     → term ( ( ">" | ">=" | "<" | "<=" ) term )* ;
term           → factor ( ( "-" | "+" ) factor )* ;
factor         → unary ( ( "/" | "*" ) unary )* ;
unary          → ( "!" | "-" ) unary
               | primary ;
primary        → NUMBER | STRING | "true" | "false" | "nil"
               | "(" expression ")" ;
```

这个语法比我们以前的那个更复杂，但反过来我们也消除了前一个语法定义中的歧义。这正是我们制作解析器时所需要的。

## 5.2 递归下降分析

递归下降是构建解析器最简单的方法，不需要使用复杂的解析器生成工具，如Yacc、Bison或ANTLR。你只需要直接手写代码。但是不要被它的简单性所欺骗，递归下降解析器速度快、健壮，并且可以支持复杂的错误处理。事实上，GCC、V8 (Chrome中的JavaScript VM)、Roslyn(用c#编写的c#编译器)和许多其他重量级产品语言实现都使用了递归下降技术。它很好用。

递归下降被认为是一种**自顶向下解析器**，因为它从最顶部或最外层的语法规则(这里是`expression`)开始，一直向下进入嵌套子表达式，最后到达语法树的叶子。这与LR等自下而上的解析器形成鲜明对比，后者从初级表达式(primary)开始，将其组成越来越大的语法块。

递归下降解析器是一种将语法规则直接翻译成命令式代码的文本翻译器。每个规则都会变成一个函数，规则主体翻译成代码大致是这样的：

| Grammar notation | Code representation    |
| ---------------- | ---------------------- |
| Terminal         | 匹配并消费一个语法标记 |
| Nonterminal      | 调用规则对应的函数     |
| `|`              | if或switch语句         |
| `*` or `+`       | while或for循环         |
| `?`              | if语句                 |

下降被“递归”修饰是因为，如果一个规则引用自身（直接或间接）就会变为递归的函数调用。

### 5.2.1 Parser类

每个语法规则都成为新类中的一个方法:

*<u>lox/Parser.java，创建新文件：</u>*

```java
package com.atguigu;

import java.util.List;

import static com.atguigu.TokenType.*;

class Parser {
  private final List<Token> tokens;
  private int current = 0;

  Parser(List<Token> tokens) {
    this.tokens = tokens;
  }
}
```

与扫描器一样，解析器也是消费一个扁平的输入序列，这是这次我们要读取的是语法标记而不是字符。我们会保存标记列表并使用`current`指向待解析的下一个标记。

我们现在要直接执行表达式语法，并将每一条规则翻译为Java代码。第一条规则`expression`，简单地展开为`equality`规则，所以很直接：

<u>*lox/Parser.java，在 Parser()方法添加：*</u>

```java
  private Expr expression() {
    return equality();
  }
```

每个解析语法规则的方法都会生成该规则对应的语法树，并将其返回给调用者。当规则主体中包含一个非终止符——对另一条规则的引用时，我们就会调用另一条规则对应的方法[^8]。

等式规则有一点复杂：

```js
equality       → comparison ( ( "!=" | "==" ) comparison )* ;
```

在Java中，这会变成：

*<u>lox/Parser.java，在 expression()后面添加：</u>*

```java
  private Expr equality() {
    Expr expr = comparison();

    while (match(BANG_EQUAL, EQUAL_EQUAL)) {
      Token operator = previous();
      Expr right = comparison();
      expr = new Expr.Binary(expr, operator, right);
    }

    return expr;
  }
```

让我们一步步来。规则体中的第一个`comparison`非终止符变成了方法中对 `comparison()`的第一次调用。我们获取结果并将其保存在一个局部变量中。

然后，规则中的`( ... )*`循环映射为一个`while`循环。我们需要知道何时退出这个循环。可以看到，在规则体中，我们必须先找到一个` !=` 或` == `标记。因此，如果我们*没有*看到其中任一标记，我们必须结束相等(不相等)运算符的序列。我们使用一个方便的`match()`方法来执行这个检查。

*<u>lox/Parser.java，在 equality()方法后添加：</u>*

```java
  private boolean match(TokenType... types) {
    for (TokenType type : types) {
      if (check(type)) {
        advance();
        return true;
      }
    }

    return false;
  }
```

这个检查会判断当前的标记是否属于给定的类型之一。如果是，则消费该标记并返回`true`；否则，就返回`false`并保留当前标记。`match()`方法是由两个更基本的操作来定义的。

如果当前标记属于给定类型，则`check()`方法返回`true`。与`match()`不同的是，它从不消费标记，只是读取。

*<u>lox/Parser.java，在 match()方法后添加：</u>*

```java
  private boolean check(TokenType type) {
    if (isAtEnd()) return false;
    return peek().type == type;
  }
```

`advance()`方法会消费当前的标记并返回它，类似于扫描器中对应方法处理字符的方式。

*<u>lox/Parser.java，在 check()方法后添加：</u>*

```java
  private Token advance() {
    if (!isAtEnd()) current++;
    return previous();
  }
```

这些方法最后都归结于几个基本操作。

*<u>lox/Parser.java，在 advance()后添加：</u>*

```java
  private boolean isAtEnd() {
    return peek().type == EOF;
  }

  private Token peek() {
    return tokens.get(current);
  }

  private Token previous() {
    return tokens.get(current - 1);
  }
```

`isAtEnd()`检查我们是否处理完了待解析的标记。`peek()`方法返回我们还未消费的当前标记，而`previous()`会返回最近消费的标记。后者让我们更容易使用`match()`，然后访问刚刚匹配的标记。

这就是我们需要的大部分解析基本工具。我们说到哪里了？对，如果我们在`equality()`的`while`循环中，也就能知道我们已经找到了一个`!=`或`==`操作符，并且一定是在解析一个等式表达式。

我们获取到匹配的操作符标记，这样就可以知道我们要处理哪一类等式表达式。之后，我们再次调用`comparison()`解析右边的操作数。我们将操作符和它的两个操作数组合成一个新的`Expr.Binary`语法树节点，然后开始循环。对于每一次迭代，我们都将结果表达式存储在同一个`expr`局部变量中。在对等式表达式序列进行压缩时，会创建一个由二元操作符节点组成的左结合嵌套树[^9]。

![The syntax tree created by parsing 'a == b == c == d == e'](6.解析表达式/sequence.png)

一旦解析器遇到一个不是等式操作符的标记，就会退出循环。最后，它会返回对应的表达式。请注意，如果解析器从未遇到过等式操作符，它就永远不会进入循环。在这种情况下，`equality()`方法有效地调用并返回`comparison()`。这样一来，这个方法就会匹配一个等式运算符或*任何更高优先级的表达式*。

继续看下一个规则。

```js
comparison     → term ( ( ">" | ">=" | "<" | "<=" ) term )* ;
```

翻译成Java：

*<u>lox/Parser.java，在 equality()方法后添加：</u>*

```java
  private Expr comparison() {
    Expr expr = term();

    while (match(GREATER, GREATER_EQUAL, LESS, LESS_EQUAL)) {
      Token operator = previous();
      Expr right = term();
      expr = new Expr.Binary(expr, operator, right);
    }

    return expr;
  }
```

语法规则与`equality`几乎完全相同，相应的代码也是如此。唯一的区别是匹配的操作符的标记类型，而且现在获取操作数时调用的方法是`term()`而不是`comparison()`。其余两个二元操作符规则遵循相同的模式。

按照优先级顺序，先做加减法：

*<u>lox/Parser.java，在 comparison()方法后添加：</u>*

```java
  private Expr term() {
    Expr expr = factor();

    while (match(MINUS, PLUS)) {
      Token operator = previous();
      Expr right = factor();
      expr = new Expr.Binary(expr, operator, right);
    }

    return expr;
  }
```

最后，是乘除法：

*<u>lox/Parser.java，在 term()方法后面添加：</u>*

```java
  private Expr factor() {
    Expr expr = unary();

    while (match(SLASH, STAR)) {
      Token operator = previous();
      Expr right = unary();
      expr = new Expr.Binary(expr, operator, right);
    }

    return expr;
  }
```

这就是所有的二进制运算符，已经按照正确的优先级和结合性进行了解析。接下来，按照优先级层级，我们要处理一元运算符了。

```js
unary          → ( "!" | "-" ) unary
               | primary ;
```

该规则对应的代码有些不同。

*<u>lox/Parser.java，在 factor()方法后添加：</u>*

```java
  private Expr unary() {
    if (match(BANG, MINUS)) {
      Token operator = previous();
      Expr right = unary();
      return new Expr.Unary(operator, right);
    }

    return primary();
  }
```

同样的，我们先检查当前的标记以确认要如何进行解析[^10]。如果是`!`或`-`，我们一定有一个一元表达式。在这种情况下，我们获取令牌，然后递归调用`unary()`来解析操作数。将所有这些都包装到一元表达式语法树中，我们就完成了。

否则，我们就达到了最高级别的优先级，即基本表达式。

```js
primary        → NUMBER | STRING | "true" | "false" | "nil"
               | "(" expression ")" ;
```

该规则中大部分都是终止符，可以直接进行解析。

*<u>lox/Parser.java，在 unary()方法后添加：</u>*

```java
  private Expr primary() {
    if (match(FALSE)) return new Expr.Literal(false);
    if (match(TRUE)) return new Expr.Literal(true);
    if (match(NIL)) return new Expr.Literal(null);

    if (match(NUMBER, STRING)) {
      return new Expr.Literal(previous().literal);
    }

    if (match(LEFT_PAREN)) {
      Expr expr = expression();
      consume(RIGHT_PAREN, "Expect ')' after expression.");
      return new Expr.Grouping(expr);
    }
  }
```

有趣的一点是处理括号的分支。当我们匹配了一个开头`(`并解析了里面的表达式后，我们必须找到一个`)`标记。如果没有找到，那就是一个错误。

## 5.3 语法错误

解析器实际上有两项工作：

1. 给定一个有效的标记序列，生成相应的语法树。

2. 给定一个*无效*的令牌序列，检测错误并告知用户。

不要低估第二项工作的重要性！在现代的IDE和编辑器中，为了语法高亮显示和支持自动补齐等功能，当用户还在编辑代码时，解析器就会不断地重新解析代码。这也意味着解析器*总是*会遇到不完整的、半错误状态的代码。

当用户没有意识到语法错误时，解析器要帮助引导他们回到正确的道路上。它报告错误的方式是你的语言的用户界面中很大的一部分。良好的语法错误处理是很难的。根据定义，代码并不是处于良好定义的状态，所以没有可靠的方法能够知道用户*想要*写什么。解析器无法读懂你的思想。

当解析器遇到语法错误时，有几个硬性要求。解析器必须能够：

- **检测并报告错误。**如果它没有检测到错误，并将由此产生的畸形语法树传递给解释器，就会出现各种可怕的情况。

- **避免崩溃或挂起。**语法错误是生活中不可避免的事实，面对语法错误，语言工具必须非常健壮。段错误或陷入无限循环是不允许的。虽然源代码可能不是有效的*代码*，但它仍然是*解析器的有效输入*，因为用户使用解析器来了解什么是允许的语法。

如果你想参与到解析器的游戏中来，这些就是桌面的筹码，但你真的想提高赌注，除了这些。一个像样的解析器还应该：

- **要快。**计算机的速度比最初发明解析器技术时快了几千倍。那种需要优化解析器，以便它能在喝咖啡的时候处理完整个源文件的日子已经一去不复返了。但是程序员的期望值也上升得同样快，甚至更快。他们希望他们的编辑器能在每次击键后的几毫秒内回复文件。

- **尽可能多地报告出不同的错误**。在第一个错误后中止是很容易实现的，但是如果每次当用户修复文件中的一个错误时，又出现了另一个新的错误，这对用户来说是很烦人的。他们希望一次看到所有的错误。

- **最小化*级联*错误**。一旦发现一个错误，解析器就不再能知道发生了什么。它会试图让自己回到正轨并继续工作，但如果它感到混乱，它可能会报告大量的幽灵错误，而这些错误并不表明代码中存在其它问题。当第一个错误被修正后，这些幽灵错误就消失了，因为它们只反映了解析器自身的混乱。级联错误很烦人，因为它们会让用户害怕，让用户认为自己的代码比实际情况更糟糕。

最后两点是相互矛盾的。我们希望尽可能多地报告单独的错误，但我们不想报告那些只是由早期错误的副作用导致的错误。

解析器对一个错误做出反应，并继续去寻找后面的错误的方式叫做**错误恢复**。这在60年代是一个热门的研究课题。那时，你需要把一叠穿孔卡片交给秘书，第二天再来看看编译器是否成功。在迭代循环如此缓慢的情况下，你真的会想在一次传递中找到代码中的每个错误。

如今，解析器在您甚至还没有完成输入之前就完成解析了，这不再是一个问题。 简单，快速的错误恢复就可以了。

### $5.3.1$ 恐慌模式错误恢复

在过去设计的所有恢复技术中，最能经受住时间考验的一种叫做**恐慌模式**（有点令人震惊）。一旦解析器检测到一个错误，它就会进入恐慌模式。它知道至少有一个token是没有意义的，因为它目前的状态是在一些语法生成式的堆栈中间。

在程序继续进行解析之前，它需要将自己的状态和即将到来的标记序列对齐，使下一个标记能够匹配正则解析的规则。这个过程称为**同步**。

为此，我们在语法中选择一些规则来标记同步点。解析器会跳出所有嵌套的生成式直到回退至该规则中，来修复其解析状态。然后，它会丢弃令牌，直到遇到一个可以匹配该规则的标记，以此来同步标记流。

这些被丢弃的标记中隐藏的其它真正的语法错误都不会被报告，但是这也意味着由初始错误引起的其它级联错误也不会被*错误地*报告出来，这是个不错的权衡。

语法中传统的要同步的地方是语句之间。我们还没有这些，所以我们不会在这一章中真正地同步，但我们会在以后把这些机制准备好。

### $5.3.2$ 进入恐慌模式

在我们讨论错误恢复之前，我们正在编写解析括号表达式的代码。在解析表达式之后，会调用`consume()`方法查找收尾的`)`。这里，终于可以实现那个方法了：

*<u>lox/Parser.java，在 match()方法后添加：</u>*

```java
  private Token consume(TokenType type, String message) {
    if (check(type)) return advance();

    throw error(peek(), message);
  }
```

它和 `match() `方法类似，检查下一个标记是否是预期的类型。如果是，它就会消费该标记，一切都很顺利。如果是其它的标记，那么我们就遇到了错误。我们通过调用下面的方法来报告错误：

*<u>lox/Parser.java，在 previous()方法后添加：</u>*

```java
  private ParseError error(Token token, String message) {
    Atguigu.error(token, message);
    return new ParseError();
  }
```

首先，通过调用下面的方法向用户展示错误信息：

*<u>lox/Lox.java，在 report()方法后添加：</u>*

```java
  static void error(Token token, String message) {
    if (token.type == TokenType.EOF) {
      report(token.line, " at end", message);
    } else {
      report(token.line, " at '" + token.lexeme + "'", message);
    }
  }
```

该方法会报告给定标记处的错误。它显示了标记的位置和标记本身。这在以后会派上用场，因为我们在整个解释器中使用标记来跟踪代码中的位置。

在我们报告错误后，用户知道了他们的错误，但接下来解析器要做什么呢？回到`error()`方法中，我们创建并返回了一个`ParseError`，是下面这个新类的实例:

*<u>lox/Parser.java，在 Parser中嵌入内部类：</u>*

```java
class Parser {  
  // 新增部分开始
	private static class ParseError extends RuntimeException {}
  // 新增部分结束
  private final List<Token> tokens;
```

这是一个简单的哨兵类，我们用它来帮助解析器摆脱错误。`error()`方法是*返回*错误而不是*抛出*错误，因为我们希望解析器内的调用方法决定是否要跳脱出该错误。有些解析错误发生在解析器不可能进入异常状态的地方，这时我们就不需要同步。在这些地方，我们只需要报告错误，然后继续解析。

例如，Lox限制了你可以传递给一个函数的参数数量。如果你传递的参数太多，解析器需要报告这个错误，但它可以而且应该继续解析额外的参数，而不是惊慌失措，进入恐慌模式[^11]。

但是，在我们的例子中，语法错误非常严重，以至于我们要进入恐慌模式并进行同步。丢弃标记非常简单，但是我们如何同步解析器自己的状态呢？

## $5.4$ 调整解析器

我们现在基本上已经完成了对表达式的解析。我们还需要在另一个地方添加一些错误处理。当解析器在每个语法规则的解析方法中下降时，它最终会进入`primary()`。如果该方法中的case都不匹配，就意味着我们正面对一个不是表达式开头的语法标记。我们也需要处理这个错误。

*<u>lox/Parser.java，在 primary()方法中添加：</u>*

```java
    if (match(LEFT_PAREN)) {
      Expr expr = expression();
      consume(RIGHT_PAREN, "表达式的后面应该是')'");
      return new Expr.Grouping(expr);
    }
    // 新增部分开头
    throw error(peek(), "这里应该是一个表达式。");
    // 新增部分结束
  }
```

这样，解析器中剩下的工作就是定义一个初始方法来启动它。这个方法自然应该叫做`parse()`。

*<u>lox/Parser.java，在 Parser()方法后添加：</u>*

```java
  Expr parse() {
    try {
      return expression();
    } catch (ParseError error) {
      return null;
    }
  }
```

稍后在向语言中添加语句时，我们将重新审视这个方法。目前，它只解析一个表达式并返回它。我们还有一些临时代码用于退出恐慌模式。语法错误恢复是解析器的工作，所以我们不希望ParseError异常逃逸到解释器的其它部分。

当确实出现语法错误时，该方法会返回`null`。这没关系。解析器承诺不会因为无效语法而崩溃或挂起，但它不承诺在发现错误时返回一个*可用的语法树*。一旦解析器报告错误，就会对`hadError`赋值，然后跳过后续阶段。

最后，我们可以将全新的解析器挂到Lox主类并进行试验。我们仍然还没有解释器，所以现在，我们将表达式解析为一个语法树，然后使用上一章中的AstPrinter类来显示它。

删除打印已扫描标记的旧代码，将其替换为：

> 在`Atguigu.java`文件中，在`run()`方法中，替换其中$5$行

```java
    List<Token> tokens = scanner.scanTokens();
    // 替换部分开始
    Parser parser = new Parser(tokens);
    Expr expression = parser.parse();

    // 如果停止，说明发生了语法错误。
    if (hadError) return;

    System.out.println(new AstPrinter().print(expression));
    // 替换部分结束
  }
```

祝贺你，你已经跨过了门槛!这就是手写解析器的全部内容。我们将在后面的章节中扩展赋值、语句和其它特性对应的语法，但这些都不会比我们本章处理的二元操作符更复杂。

启动解释器并输入一些表达式。查看它是如何正确处理优先级和结合性的?这对于不到200行代码来说已经很不错了。

# 6. 表达式求值

对于语言实现来说，有各种方式可以使计算机执行用户的源代码命令。它们可以将其编译为机器代码，将其翻译为另一种高级语言，或者将其还原为某种字节码格式，以便在虚拟机中执行。不过对于我们的第一个解释器，我们要选择最简单、最短的一条路，也就是执行语法树本身。

现在，我们的解释器只支持表达式。因此，为了“执行”代码，我们要计算一个表达式时并生成一个值。对于我们可以解析的每一种表达式语法——字面量，操作符等——我们都需要一个相应的代码块，该代码块知道如何计算该语法树并产生结果。这也就引出了两个问题：

1. 我们要生成什么类型的值？

2. 我们如何组织这些代码块？

让我们来逐个击破。

## 6.1 值描述

在$Atguigu$中，值由字面量创建，由表达式计算，并存储在变量中。用户将其视作$Atguigu$对象，但它们是用编写解释器的底层语言实现的。这意味着要在$Atguigu$的动态类型和$Java$的静态类型之间架起桥梁。$Atguigu$中的变量可以存储任何（$Atguigu$）类型的值，甚至可以在不同时间存储不同类型的值。我们可以用什么$Java$类型来表示？

给定一个具有该静态类型的$Java$变量，我们还必须能够在运行时确定它持有哪种类型的值。当解释器执行 `+`运算符时，它需要知道它是在将两个数字相加还是在拼接两个字符串。有没有一种$Java$类型可以容纳数字、字符串、布尔值等等？有没有一种类型可以告诉我们它的运行时类型是什么？有的！就是老牌的`java.lang.Object`。

在解释器中需要存储$Atguigu$值的地方，我们可以使用`Object`作为类型。$Java$已经将其基本类型的所有子类对象装箱了，因此我们可以将它们用作$Atguigu$的内置类型：

| $Atguigu$中的类型   | $Java$表示 |
| ------------------- | ---------- |
| 任意$Atguigu$中的值 | `Object`   |
| `nil`               | `null`     |
| Boolean             | `Boolean`  |
| number              | `Double`   |
| string              | `String`   |

给定一个静态类型为`Object`的值，我们可以使用$Java$内置的`instanceof`操作符来确定运行时的值是数字、字符串或其它什么。换句话说，$JVM$自己的对象表示方便地为我们提供了实现$Atguigu$内置类型所需的一切。当稍后添加$Atguigu$的函数、类和实例等概念时，我们还必须做更多的工作，但`Object`和基本类型的包装类足以满足我们现在的需要。

## 6.2 表达式求值

接下来，我们需要大量的代码实现我们可解析的每种表达式对应的求值逻辑。我们可以把这些代码放在语法树的类中，比如添加一个`interpret()`方法。然后，我们可以告诉每一个语法树节点“解释你自己”，这就是四人组的解释器模式。这是一个整洁的模式，但正如我前面提到的，如果我们将各种逻辑都塞进语法树类中，就会变得很混乱。

相反，我们将重用我们的访问者模式。在前面的章节中，我们创建了一个AstPrinter类。它接受一个语法树，并递归地遍历它，构建一个最终返回的字符串。这几乎就是一个真正的解释器所做的事情，只不过解释器不是连接字符串，而是计算值。

我们先创建一个新类。

> 创建新文件`Interpreter.java`

```java
package com.atguigu;

public class Interpreter {
}
```

这个类声明它是一个访问者。访问方法的返回类型将是Object，即我们在Java代码中用来引用Lox值的根类。为了实现Visitor接口，我们需要为解析器生成的四个表达式树类中分别定义访问方法。我们从最简单的开始…

### 6.2.1 字面量求值

一个表达式树的叶子节点（构成其它表达式的语法原子单位）是字面量。字面符号几乎已经是值了，但两者的区别很重要。字面量是产生一个值的语法单元。字面量总是出现在用户的源代码中的某个地方。而很多值是通过计算产生的，并不存在于代码中的任何地方，这些都不是字面量。字面量来自于解析器领域，而值是一个解释器的概念，是运行时世界的一部分。

因此，就像我们在解析器中将字面量*标记*转换为字面量*语法树节点*一样，现在我们将字面量树节点转换为运行时值。这其实很简单。

*<u>lox/Interpreter.java，在 Interpreter类中添加：</u>*

```java
  @Override
  public Object visitLiteralExpr(Expr.Literal expr) {
    return expr.value;
  }
```

我们早在扫描过程中就即时生成了运行时的值，并把它放进了语法标记中。解析器获取该值并将其插入字面量语法树节点中，所以要对字面量求值，我们只需把它存的值取出来。

### 6.2.2 括号求值

下一个要求值的节点是分组—在表达式中显式使用括号时产生的语法树节点。

*<u>lox/Interpreter.java，在 Interpreter类中添加：</u>*

```java
  @Override
  public Object visitGroupingExpr(Expr.Grouping expr) {
    return evaluate(expr.expression);
  }
```

一个分组节点中包含一个引用指向对应于括号内的表达式的内部节点。要想计算括号表达式，我们只需要递归地对子表达式求值并返回结果即可。

我们依赖于下面这个辅助方法，它只是将表达式发送回解释器的访问者实现中：

*<u>lox/Interpreter.java，在 Interpreter类中添加：</u>*

```java
  private Object evaluate(Expr expr) {
    return expr.accept(this);
```

### 6.2.3 一元表达式求值

像分组表达式一样，一元表达式也有一个必须先求值的子表达式。不同的是，一元表达式自身在完成求值之后还会做一些工作。

*<u>lox/Interpreter.java，在 visitLiteralExpr()方法后添加：</u>*

```java
  @Override
  public Object visitUnaryExpr(Expr.Unary expr) {
    Object right = evaluate(expr.right);

    switch (expr.operator.type) {
      case MINUS:
        return -(double)right;
    }

    // Unreachable.
    return null;
  }
```

首先，我们计算操作数表达式，然后我们将一元操作符作用于子表达式的结果。我们有两种不同的一元表达式，由操作符标记的类型来区分。

这里展示的是`-`，它会对子表达式的结构取负。子表达式结果必须是数字。因为我们在Java中无法*静态地*知道这一点，所以我们在执行操作之前先对其进行强制转换。这个类型转换是在运行时对`-`求值时发生的。这就是将语言动态类型化的核心所在。

你可以看到求值过程是如何递归遍历语法树的。在对一元操作符本身进行计算之前，我们必须先对其操作数子表达式求值。这表明，解释器正在进行**后序遍历**—每个节点在自己求值之前必须先对子节点求值。

另一个一元操作符是逻辑非。

*<u>lox/Interpreter.java，在visitUnaryExpr()方法中添加：</u>*

```java
		switch (expr.operator.type) { 
      // 新增部分开始  
			case BANG:
        return !isTruthy(right);
      // 新增部分结束
      case MINUS:
```

实现很简单，但是这里的“真实”指的是什么呢？我们需要简单地讨论一下西方哲学中的一个伟大问题：什么是真理？

### 6.2.4 真与假

好吧，我们不会真正深入这个普世的问题，但是至少在Lox的世界中，我们需要确定当您在逻辑运算（如`!`或其他任何需要布尔值的地方）中使用非`true`或`false`以外的东西时会发生什么？ 

我们*可以*说这是一个错误，因为我们没有使用隐式转换，但是大多数动态类型语言并不那么严格。相反，他们把所有类型的值分成两组，其中一组他们定义为“真”，其余为“假”。这种划分有些武断，在一些语言中会变得很奇怪[^5]。

Lox遵循Ruby的简单规则：`false`和`nil`是假的，其他都是真的。我们是这样实现的：

*<u>lox/Interpreter.java，在 visitUnaryExpr()方法后添加：</u>*

```java
  private boolean isTruthy(Object object) {
    if (object == null) return false;
    if (object instanceof Boolean) return (boolean)object;
    return true;
  }
```

### 6.2.5 二元操作符求值

来到最后的表达式树类——二元操作符，其中包含很多运算符，我们先从数学运算开始。

*<u>lox/Interpreter.java，在 evaluate()方法后添加[^6]：</u>*

```java
  @Override
  public Object visitBinaryExpr(Expr.Binary expr) {
    Object left = evaluate(expr.left);
    Object right = evaluate(expr.right); 

    switch (expr.operator.type) {
      case MINUS:
        return (double)left - (double)right;
      case SLASH:
        return (double)left / (double)right;
      case STAR:
        return (double)left * (double)right;
    }

    // Unreachable.
    return null;
  }
```

我想你能理解这里的实现。与一元取负运算符的主要区别是，我们有两个操作数要计算。

我漏掉了一个算术运算符，因为它有点特殊。

*<u>lox/Interpreter.java，在 visitBinaryExpr()方法中添加：</u>*

```java
    switch (expr.operator.type) {
      case MINUS:
        return (double)left - (double)right;
      // 新增部分开始
      case PLUS:
        if (left instanceof Double && right instanceof Double) {
          return (double)left + (double)right;
        } 

        if (left instanceof String && right instanceof String) {
          return (String)left + (String)right;
        }

        break;
      // 新增部分结束
      case SLASH:
```

`+`操作符也可以用来拼接两个字符串。为此，我们不能只是假设操作数是某种类型并将其强制转换，而是要动态地检查操作数类型并选择适当的操作。这就是为什么我们需要对象表示能支持`instanceof`。

接下来是比较操作符。

*<u>lox/Interpreter.java，在 visitBinaryExpr()方法中添加：</u>*

```java
    switch (expr.operator.type) {
			// 新增部分开始
      case GREATER:
        return (double)left > (double)right;
      case GREATER_EQUAL:
        return (double)left >= (double)right;
      case LESS:
        return (double)left < (double)right;
      case LESS_EQUAL:
        return (double)left <= (double)right;
      // 新增部分结束
      case MINUS:
```

它们基本上与算术运算符相同。唯一的区别是，算术运算符产生的值的类型与操作数（数字或字符串）相同，而比较运算符总是产生一个布尔值。

最后一对是等式运算符。

*<u>lox/Interpreter.java，在 visitBinaryExpr()方法中添加：</u>*

```java
      case BANG_EQUAL: return !isEqual(left, right);
      case EQUAL_EQUAL: return isEqual(left, right);
```

与需要数字的比较运算符不同，等式运算符支持任何类型的操作数，甚至是混合类型。你不能问Lox 3是否*小于*`"three"`，但你可以问它3是否等于`"three"`。

与真假判断一样，相等判断也被提取到了单独的方法中。

*<u>lox/Interpreter.java，在 isTruthy()方法后添加：</u>*

```java
  private boolean isEqual(Object a, Object b) {
    if (a == null && b == null) return true;
    if (a == null) return false;

    return a.equals(b);
  }
```

这是我们使用Java表示Lox对象的细节一角。我们需要正确地实现Lox的相等概念，这可能与Java中不同。

幸运的是，这两者很相似。Lox不会在等式中做隐式转换，Java也不会。我们必须对 `nil`/`null` 做特殊处理，这样就不会在对`null`调用`equals()`方法时抛出`NullPointerException`。其它情况下，都是没问题的。Java中的`.equals()`方法对Boolean、Double和 String的处理都符合Lox的要求。

就这样了！这就是我们要正确解释一个有效的Lox表达式所需要的全部代码。但是*无效的*表达式呢？尤其是，当一个子表达式的计算结果类型与待执行的操作不符时会发生什么？

## 6.3 运行时错误

每当子表达式产生一个对象，而运算符要求它是一个数字或字符串时，我都会轻率地插入强制类型转换。这些类型转换可能会失败。如果我们想做出一个可用的语言，即使用户的代码是错误的，我们也有责任优雅地处理这个错误。

现在是时候讨论**运行时错误**了。在前面的章节中，我花了很多笔墨讨论错误处理，但这些都是语法或静态错误。这些都是在代码执行之前进行检测和报告的。运行时错误是语言语义要求我们在程序运行时检测和报告的故障（因此得名）。

现在，如果操作数对于正在执行的操作来说是错误的类型，那么Java转换将失败，JVM将抛出一个ClassCastException。这将跳脱出整个调用堆栈并退出应用程序，然后向用户抛出Java堆栈跟踪信息。这可能不是我们想要的。Lox是用Java实现的这一事实应该是一个对用户隐藏的细节。相反，我们希望他们理解此时发生的是Lox运行时错误，并给他们一个与我们的语言和他们的程序相关的错误信息。

不过，Java的行为确实有一个优点。当错误发生时，它会正确地停止执行代码。比方说，用户输入了一些表达式，比如：

```java
2 * (3 / -"muffin")
```

你无法对"muffin"取负，所以我们需要在内部的`-`表达式中报告一个运行时错误。这又意味着我们无法计算`/`表达式，因为它的右操作数无意义，对于`*`表达式也是如此。因此，当某个表达式深处出现运行时错误时，我们需要一直跳出到最外层。

我们可以打印一个运行时错误，然后中止进程并完全退出应用程序。这有一点戏剧性，有点像编程语言解释器中的 "mic drop"。

尽管这种处理方式很诱人，我们或许应该做一些不那么灾难性的事情。虽然运行时错误需要停止对表达式的计算，但它不应该杀死解释器。如果用户正在运行REPL，并且在一行代码中出现了错误，他们应该仍然能够保持会话，并在之后继续输入更多的代码。

### 6.3.1 检测运行时错误

我们的树遍历型解释器通过递归方法调用计算嵌套的表达式，而且我们需要能够跳脱出所有的调用层。在Java中抛出异常是实现这一点的好方法。但是，我们不使用Java自己的转换失败错误，而是定义一个Lox专用的错误，这样我们就可以按照我们想要的方式处理它。

在进行强制转换之前，我们先自己检查对象的类型。因此，对于一元操作符`-`，我们需要添加代码：

*<u>lox/Interpreter.java，在visitUnaryExpr()方法中添加：</u>*

```java
      case MINUS:
        // 新增部分开始
       	checkNumberOperand(expr.operator, right);
       	// 新增部分结束
        return -(double)right;
```

检查操作数的代码如下：

*<u>lox/Interpreter.java，在 visitUnaryExpr()方法后添加：</u>*

```java
  private void checkNumberOperand(Token operator, Object operand) {
    if (operand instanceof Double) return;
    throw new RuntimeError(operator, "Operand must be a number.");
  }
```

当检查失败时，代码会抛出一个以下的错误：

*<u>lox/RuntimeError.java，新建源代码文件：</u>*

```java
package com.craftinginterpreters.lox;

class RuntimeError extends RuntimeException {
  final Token token;

  RuntimeError(Token token, String message) {
    super(message);
    this.token = token;
  }
}
```

与Java转换异常不同，我们的类会跟踪语法标记，可以指明用户代码中抛出运行时错误的位置[^9]。与静态错误一样，这有助于用户知道去哪里修复代码。

我们需要对二元运算符进行类似的检查。既然我答应了要展示实现解释器所需的每一行代码，那么我就把它们逐一介绍一遍。

大于：

*<u>lox/Interpreter.java，在 visitBinaryExpr()方法中添加：</u>*

```java
      case GREATER:  
				// 新增部分开始
        checkNumberOperands(expr.operator, left, right);
        // 新增部分结束
        return (double)left > (double)right;
```

大于等于：

*<u>lox/Interpreter.java，在 visitBinaryExpr()方法中添加：</u>*

```java
      case GREATER_EQUAL:  
				// 新增部分开始
        checkNumberOperands(expr.operator, left, right);
        // 新增部分结束
        return (double)left >= (double)right;
```

小于：

*<u>lox/Interpreter.java，在 visitBinaryExpr()方法中添加：</u>*

```java
      case LESS:  
				// 新增部分开始
        checkNumberOperands(expr.operator, left, right);
        // 新增部分结束
        return (double)left < (double)right;
```

小于等于：

*<u>lox/Interpreter.java，在 visitBinaryExpr()方法中添加：</u>*

```java
      case LESS_EQUAL:  
				// 新增部分开始
        checkNumberOperands(expr.operator, left, right);
        // 新增部分结束
        return (double)left <= (double)right;
```

减法：

*<u>lox/Interpreter.java，在 visitBinaryExpr()方法中添加：</u>*

```java
      case MINUS:  
				// 新增部分开始
        checkNumberOperands(expr.operator, left, right);
        // 新增部分结束
        return (double)left - (double)right;
```

除法：

*<u>lox/Interpreter.java，在 visitBinaryExpr()方法中添加：</u>*

```java
      case SLASH:  
				// 新增部分开始
        checkNumberOperands(expr.operator, left, right);
        // 新增部分结束
        return (double)left / (double)right;
```

乘法：

*<u>lox/Interpreter.java，在 visitBinaryExpr()方法中添加：</u>*

```java
      case STAR:  
				// 新增部分开始
        checkNumberOperands(expr.operator, left, right);
        // 新增部分结束
        return (double)left * (double)right;
```

所有这些都依赖于下面这个验证器，它实际上与一元验证器相同：

*<u>lox/Interpreter.java，在 checkNumberOperand()方法后添加：</u>*

```java
  private void checkNumberOperands(Token operator, Object left, Object right) {
    if (left instanceof Double && right instanceof Double) return;
    
    throw new RuntimeError(operator, "Operands must be numbers.");
  }
```

剩下的最后一个运算符，也是最奇怪的一个，就是加法。由于`+`已经对数字和字符串进行重载，其中已经有检查类型的代码。我们需要做的就是在这两种情况都不匹配时失败。 

*<u>lox/Interpreter.java，在 visitBinaryExpr()方法中替换一行：</u>*

```java
          return (String)left + (String)right;
        }
        // 替换部分开始
        throw new RuntimeError(expr.operator,
            "Operands must be two numbers or two strings.");
        // 替换部分结束
      case SLASH:
```

这样我们就可以在计算器的内部检测运行时错误。错误已经被抛出了。下一步就是编写能捕获这些错误的代码。为此，我们需要将Interpreter类连接到驱动它的Lox主类中。

## 7.4 连接解释器

visit方法是Interpreter类的核心部分，真正的工作是在这里进行的。我们需要给它们包上一层皮，以便与程序的其他部分对接。解释器的公共API只是一种方法。

*<u>lox/Interpreter.java，在 Interpreter类中添加：</u>*

```java
  void interpret(Expr expression) { 
    try {
      Object value = evaluate(expression);
      System.out.println(stringify(value));
    } catch (RuntimeError error) {
      Lox.runtimeError(error);
    }
  }
```

该方法会接收一个表达式对应的语法树，并对其进行计算。如果成功了，`evaluate()`方法会返回一个对象作为结果值。`interpret()`方法将结果转为字符串并展示给用户。要将Lox值转为字符串，我们要依赖下面的方法：

*<u>lox/Interpreter.java，在 isEqual()方法后添加：</u>*

```java
  private String stringify(Object object) {
    if (object == null) return "nil";

    if (object instanceof Double) {
      String text = object.toString();
      if (text.endsWith(".0")) {
        text = text.substring(0, text.length() - 2);
      }
      return text;
    }

    return object.toString();
  }
```

这是一段像`isTruthy()`一样的代码，它连接了Lox对象的用户视图和它们在Java中的内部表示。

这很简单。由于Lox的设计旨在使Java使用者熟悉，因此Boolean之类的东西在两种语言中看起来是一样的。只有两种边界情况是`nil`(我们用Java的`null`表示)和数字。

Lox即使对整数值也使用双精度数字。在这种情况下，打印时应该不带小数点。 由于Java同时具有浮点型和整型，它希望您知道正在使用的是哪一种类型。它通过在整数值的双数上添加一个明确的`.0`来告知用户。我们不关心这个，所以我们把它去掉。

### 7.4.1 报告运行时错误

如果在计算表达式时出现了运行时错误，`interpret()`方法会将其捕获。这样我们可以向用户报告这个错误，然后优雅地继续执行。我们现有的所有错误报告代码都在Lox类中，所以我们也把这个方法放在其中：

*<u>lox/Lox.java，在 error()方法后添加：</u>*

```java
  static void runtimeError(RuntimeError error) {
    System.err.println(error.getMessage() +
        "\n[line " + error.token.line + "]");
    hadRuntimeError = true;
  }
```

我们使用与RuntimeError关联的标记来告诉用户错误发生时正在执行哪一行代码。更好的做法是给用户一个完整的调用堆栈，来显示他们是如何执行该代码的。但我们目前还没有函数调用，所以我想我们不必担心这个问题。

展示错误之后，`runtimeError()`会设置以下字段：

<u>*lox/Lox.java，在 Lox类中添加：*</u>

```java
  static boolean hadError = false;
  // 新增部分开始
  static boolean hadRuntimeError = false;
  // 新增部分结束
  public static void main(String[] args) throws IOException {
```

这个字段担任着很小但很重要的角色。

*<u>lox/Lox.java，在 runFile()方法中添加：</u>*

```java
    run(new String(bytes, Charset.defaultCharset()));

    // Indicate an error in the exit code.
    if (hadError) System.exit(65);
    // 新增部分开始
    if (hadRuntimeError) System.exit(70);
    // 新增部分结束
  }
```

如果用户从文件中运行Lox脚本，并且发生了运行时错误，我们在进程退出时设置一个退出码，以便让调用进程知道。不是每个人都在乎shell的规矩，但我们在乎。

### 7.4.2 运行解释器

现在我们有了解释器，Lox类可以开始使用它了。

*<u>lox/Lox.java，在 Lox类中添加：</u>*

```java
public class Lox {
  // 新增部分开始
  private static final Interpreter interpreter = new Interpreter();
  // 新增部分结束
  static boolean hadError = false;
```

我们把这个字段设置为静态的，这样在一个REPL会话中连续调用`run()`时就会重复使用同一个解释器。目前这一点没有什么区别，但以后当解释器需要存储全局变量时就会有区别。这些全局变量应该在整个REPL会话中持续存在。

最后，我们删除上一章中用于打印语法树的那行临时代码，并将其替换为：

*<u>lox/Lox.java，在 run()方法中替换一行：</u>*

```java
    // Stop if there was a syntax error.
    if (hadError) return;
    // 替换部分开始
    interpreter.interpret(expression);
    // 替换部分结束
  }
```

我们现在有一个完整的语言管道：扫描、解析和执行。恭喜你，你现在有了你自己的算术计算器。

如您所见，这个解释器是非常简陋的。但是我们今天建立的解释器类和访问者模式构成了一个骨架，后面的章节中将填充入有趣的内容（变量，函数等）。现在，解释器的功能并不多，但它是活的!

![A skeleton waving hello.](7.表达式求值/skeleton.png)

# $7$ 语句和状态

到目前为止，我们提供解释器的感觉不太像是在使用一种真正的语言进行编程，更像是在计算器上按按钮。对我来说，"编程 "意味着用较小的部分构建出一个系统。我们目前还不支持这样做，因为我们还无法将一个名称绑定到某个数据或函数。我们不能在无法引用小片段的情况下编写软件。

为了支持绑定，我们的解释器需要保存内部状态。如果你在程序开始处定义了一个变量，并在结束处使用它，那么解释器必须在这期间保持该变量的值。所以在这一章中，我们会给解释器一个大脑，它不仅可以运算，而且可以*记忆*。

![A brain, presumably remembering stuff.](8.表达式和状态/brain.png)

状态和语句是相辅相成的。因为根据定义，语句不会计算出一个具体值，而是需要做一些事情来发挥作用。这些事情被称为**副作用(side effect)**。它可能意味着产生用户可见的输出，或者修改解释器中的一些状态，而这些状态后续可以被检测到。第二个特性使得语句非常适合于定义变量或其他命名实体。

在这一章中，我们会实现所有这些。我们会定义可以产生输出和创建状态的语句，然后会添加表达式来访问和赋值给这些变量，最后，我们会引入代码块和局部作用域。这一章要讲的内容太多了，但是我们会一点一点地把它们嚼碎。

## 8.1 语句

我们首先扩展Lox的语法以支持语句。 语句与表达式并没有很大的不同，我们从两种最简单的类型开始：

1. **表达式语句**可以让您将表达式放在需要语句的位置。它们的存在是为了计算有副作用的表达式。您可能没有注意到它们，但其实你在C、Java和其他语言中一直在使用表达式语句[^1]。如果你看到一个函数或方法调用后面跟着一个`;`，您看到的其实就是一个表达式语句。

2. **`print`语句**会计算一个表达式，并将结果展示给用户。我承认把`print`直接放进语言中，而不是把它变成一个库函数，这很奇怪。这样做是基于本书的编排策略的让步，即我们会以章节为单位逐步构建这个解释器，并希望能够在完成解释器的所有功能之前能够使用它。如果让`print`成为一个标准库函数，我们必须等到拥有了定义和调用函数的所有机制之后，才能看到它发挥作用。

新的词法意味着新的语法规则。在本章中，我们终于获得了解析整个Lox脚本的能力。由于Lox是一种命令式的、动态类型的语言，所以脚本的“顶层”也只是一组语句。新的规则如下：

```javascript
program        → statement* EOF ;

statement      → exprStmt
               | printStmt ;

exprStmt       → expression ";" ;
printStmt      → "print" expression ";" ;
```

现在第一条规则是`program`，这也是语法的起点，代表一个完整的Lox脚本或REPL输入项。程序是一个语句列表，后面跟着特殊的“文件结束”(EOF)标记。强制性的结束标记可以确保解析器能够消费所有输入内容，而不会默默地忽略脚本结尾处错误的、未消耗的标记。

目前，`statement`只有两种情况，分别对应于我们描述的两类语句。我们将在本章后面和接下来的章节中补充更多内容。接下来就是将这个语法转化为我们可以存储在内存中的东西——语法树。。

### $7.1.1$ 语句的抽象语法树

语法中没有地方既允许使用表达式，也允许使用语句。 操作符（如`+`）的操作数总是表达式，而不是语句。`while`循环的主体总是一个语句。

因为这两种语法是不相干的，所以我们不需要提供一个它们都继承的基类。将表达式和语句拆分为单独的类结构，可使Java编译器帮助我们发现一些愚蠢的错误，例如将语句传递给需要表达式的Java方法。

这意味着要为语句创建一个新的基类。正如我们的前辈那样，我们将使用“Stmt”这个隐秘的名字。我很有远见，在设计我们的AST元编程脚本时就已经预见到了这一点。这就是为什么我们把“Expr”作为参数传给了`defineAst()`。现在我们添加另一个方法调用来定义`Stmt`和它的子类。

*<u>tool/GenerateAst.java，在 main()方法中新增：</u>*

```java
      "Unary    : Token operator, Expr right"
    ));
    
    defineAst(outputDir, "Stmt", Arrays.asList(
      "Expression : Expr expression",
      "Print      : Expr expression"
    ));
  }
```

运行AST生成器脚本，查看生成的`Stmt.java`文件，其中包含表达式和`print`语句所需的语法树类。不要忘记将该文件添加到IDE项目或makefile或其他文件中。

### 8.1.2 解析语句

解析器的`parse()`方法会解析并返回一个表达式，这是一个临时方案，是为了让上一章的代码能启动并运行起来。现在，我们的语法已经有了正确的起始规则，即`program`，我们可以正式编写`parse()`方法了。

*<u>lox/Parser.java， parse()方法，替换7行：</u>*

```java
  List<Stmt> parse() {
    List<Stmt> statements = new ArrayList<>();
    while (!isAtEnd()) {
      statements.add(statement());
    }

    return statements; 
  }
```

该方法会尽可能多地解析一系列语句，直到命中输入内容的结尾为止。这是一种非常直接的将`program`规则转换为递归下降风格的方式。由于我们现在使用ArrayList，所以我们还必须向Java的冗长之神做一个小小的祈祷。

*<u>lox/Parser.java，新增代码：</u>*

```java
package com.craftinginterpreters.lox;
// 新增部分开始
import java.util.ArrayList;
// 新增部分结束
import java.util.List;
```

一个程序就是一系列的语句，而我们可以通过下面的方法解析每一条语句：

*<u>lox/Parser.java，在 expression()方法后添加：</u>*

```java
  private Stmt statement() {
    if (match(PRINT)) return printStatement();

    return expressionStatement();
  }
```

这是一个简单的框架，但是稍后我们将会填充更多的语句类型。我们通过查看当前标记来确定匹配哪条语句规则。`print`标记意味着它显然是一个`print`语句。

如果下一个标记看起来不像任何已知类型的语句，我们就认为它一定是一个表达式语句。这是解析语句时典型的最终失败分支，因为我们很难通过第一个标记主动识别出一个表达式。

每种语句类型都有自己的方法。首先是`print`：

*<u>lox/Parser.java，在 statement()方法后添加：</u>*

```java
  private Stmt printStatement() {
    Expr value = expression();
    consume(SEMICOLON, "Expect ';' after value.");
    return new Stmt.Print(value);
  }
```

因为我们已经匹配并消费了`print`令牌本身，所以这里不需要重复消费。我们先解析随后的表达式，消费表示语句终止的分号，并生成语法树。

如果我们没有匹配到`print`语句，那一定是一条下面的语句：

*<u>lox/Parser.java，在 printStatement()方法后添加：</u>*

```java
  private Stmt expressionStatement() {
    Expr expr = expression();
    consume(SEMICOLON, "Expect ';' after expression.");
    return new Stmt.Expression(expr);
  }
```

与前面的方法类似，我们解析一个后面带分号的表达式。我们将Expr封装在一个正确类型的Stmt中，并返回它。

### 8.1.3 执行语句

我们在前面几章一步一步地慢慢完成了解释器的前端工作。我们的解析器现在可以产生语句语法树，所以下一步，也是最后一步，就是对其进行解释。和表达式一样，我们使用的是Visitor模式，但是我们需要实现一个新的访问者接口`Stmt.Visitor`，因为语句有自己的基类。

我们将其添加到Interpreter实现的接口列表中。

*<u>lox/Interpreter.java，替换1行[^3]：</u>*

```java
// 替换部分开始
class Interpreter implements Expr.Visitor<Object>,
                             Stmt.Visitor<Void> {
// 替换部分结束
  void interpret(Expr expression) { 
```

与表达式不同，语句不会产生值，因此visit方法的返回类型是`Void`，而不是`Object`。我们有两种语句类型，每种类型都需要一个visit方法。最简单的是表达式语句：

*<u>lox/Interpreter.java，在 evaluate()方法后添加：</u>*

```java
  @Override
  public Void visitExpressionStmt(Stmt.Expression stmt) {
    evaluate(stmt.expression);
    return null;
  }
```

我们使用现有的`evaluate()`方法计算内部表达式，并丢弃其结果值。然后我们返回`null`，因为Java要求为特殊的大写Void返回类型返回该值。很奇怪，但你能有什么办法呢？

`print`语句的visit方法没有太大的不同。

*<u>lox/Interpreter.java，在 visitExpressionStmt()方法后添加：</u>*

```java
  @Override
  public Void visitPrintStmt(Stmt.Print stmt) {
    Object value = evaluate(stmt.expression);
    System.out.println(stringify(value));
    return null;
  }
```

在丢弃表达式的值之前，我们使用上一章引入的`stringify()`方法将其转换为字符串，然后将其输出到stdout。

我们的解释器现在可以处理语句了，但是我们还需要做一些工作将语句输入到解释器中。首先，修改Interpreter类中原有的`interpret()` 方法，让其能够接受一组语句——即一段程序。

*<u>lox/Interpreter.java，修改 interpret()方法，替换8行：</u>*

```java
  void interpret(List<Stmt> statements) {
    try {
      for (Stmt statement : statements) {
        execute(statement);
      }
    } catch (RuntimeError error) {
      Lox.runtimeError(error);
    }
  }
```

这段代码替换了原先处理单个表达式的旧代码。新代码依赖于下面的小辅助方法。

*<u>lox/Interpreter.java，在 evaluate()方法后添加：</u>*

```java
  private void execute(Stmt stmt) {
    stmt.accept(this);
  }
```

这类似于处理表达式的`evaluate()`方法，这是这里处理语句。因为我们要使用列表，所以我们需要在Java中引入一下。

<u>*lox/Interpreter.java*</u>

```java
package com.craftinginterpreters.lox;
// 新增部分开始
import java.util.List;
// 新增部分结束
class Interpreter implements Expr.Visitor<Object>,
```

Lox主类中仍然是只解析单个表达式并将其传给解释器。我们将其修正如下：

*<u>lox/Lox.java，在 run()方法中替换一行：</u>*

```java
    Parser parser = new Parser(tokens);
    // 替换部分开始
    List<Stmt> statements = parser.parse();
    // 替换部分结束
    // Stop if there was a syntax error.
```

然后将对解释器的调用替换如下：

*<u>lox/Lox.java，在 run()方法中替换一行：</u>*

```java
    if (hadError) return;
    // 替换部分开始
    interpreter.interpret(statements);
    // 替换部分结束
  }
```

基本就是对新语法进行遍历。 OK，启动解释器并测试一下。 现在有必要在文本文件中草拟一个小的Lox程序来作为脚本运行。 就像是：

```java
print "one";
print true;
print 2 + 1;
```

它看起来就像一个真实的程序！ 请注意，REPL现在也要求你输入完整的语句，而不是简单的表达式。 所以不要忘记后面的分号。

## $7.2$ 全局变量

现在我们已经有了语句，可以开始出了状态了。在深入探讨语法作用域的复杂性之前，我们先从最简单的变量（全局变量）开始。我们需要两个新的结构。

1. **变量声明**语句用于创建一个新变量。
   
   ```javascript
   var beverage = "espresso";
   ```
   
   该语句将创建一个新的绑定，将一个名称（这里是 `beverage`）和一个值（这里是字符串 `"espresso"`）关联起来。
   
2. 一旦声明完成，**变量表达式**就可以访问该绑定。当标识符“beverage”被用作一个表达式时，程序会查找与该名称绑定的值并返回。
   
   ```javascript
   print beverage; // "espresso".
   ```

稍后，我们会添加赋值和块作用域，但是这些已经足够继续后面的学习了。

### $7.2.1$ 变量语法

与前面一样，我们将从语法开始，从前到后依次完成实现。变量声明是一种语句，但它们不同于其他语句，我们把statement语法一分为二来处理该情况。这是因为语法要限制某个位置上哪些类型的语句是被允许的。

控制流语句中的子句——比如，`if`或`while`语句体中的`then`和`else`分支——都是一个语句。但是这个语句不应该是一个声明名称的语句。下面的代码是OK的：

```java
if (monday) print "Ugh, already?";
```

但是下面的代码不行：

```java
if (monday) var beverage = "espresso";
```

我们也*可以*允许后者，但是会令人困惑。 `beverage`变量的作用域是什么？`if`语句结束之后它是否还继续存在？如果存在的话，在其它条件下它的值是什么？这个变量是否在其它情形下也一直存在？

这样的代码有点奇怪，所以C、Java及类似语言中都不允许这种写法。语句就好像有两个“优先级”。有些允许语句的地方——比如在代码块内或程序顶层[^5]——可以允许任何类型的语句，包括变量声明。而其他地方只允许那些不声明名称的、优先级更高的语句。

为了适应这种区别，我们为声明名称的语句类型添加了另一条规则：

```javascript
program        → declaration* EOF ;

declaration    → varDecl
               | statement ;

statement      → exprStmt
               | printStmt ;
```

声明语句属于新的 `declaration`规则。目前，这里只有变量，但是后面还会包含函数和类。任何允许声明的地方都允许一个非声明式的语句，所以 `declaration` 规则会下降到`statement`。显然，你可以在脚本的顶层声明一些内容，所以`program`规则需要路由到新规则。

声明一个变量的规则如下：

```javascript
varDecl        → "var" IDENTIFIER ( "=" expression )? ";" ;
```

像大多数语句一样，它以一个前置关键字开头，这里是`var`。然后是一个标识符标记，作为声明变量的名称，后面是一个可选的初始化式表达式。最后，以一个分号作为结尾。

为了访问变量，我们还需要定义一个新类型的基本表达式：

```javascript
primary        → "true" | "false" | "nil"
               | NUMBER | STRING
               | "(" expression ")"
               | IDENTIFIER ;
```

 `IDENTIFIER` 子语句会匹配单个标识符标记，该标记会被理解为正在访问的变量的名称。

这些新的语法规则需要其相应的语法树。在AST生成器中，我们为变量声明添加一个新的语句树。

*<u>tool/GenerateAst.java，在 main()方法中添加一行，前一行需要加`,`：</u>*

```java
      "Expression : Expr expression",
      "Print      : Expr expression",
      // 新增部分开始
      "Var        : Token name, Expr initializer"
      // 新增部分结束
    ));
```

这里存储了名称标记，以便我们知道该语句声明了什么，此外还有初始化表达式（如果没有，字段就是`null`）。

然后我们添加一个表达式节点用于访问变量。

*<u>tool/GenerateAst.java，在 main()方法中添加一行，前一行需要加`,`：</u>*

```javascript
      "Literal  : Object value",
      "Unary    : Token operator, Expr right",
      // 新增部分开始
      "Variable : Token name"
      // 新增部分结束
    ));
```

这只是对变量名称标记的简单包装，就是这样。像往常一样，别忘了运行AST生成器脚本，这样你就能得到更新的 "Expr.java "和 "Stmt.java "文件。

### $7.2.2$ 解析变量

在解析变量语句之前，我们需要修改一些代码，为语法中的新规则`declaration`腾出一些空间。现在，程序的最顶层是声明语句的列表，所以解析器方法的入口需要更改：

> 在`Parser.java`文件中，在`parse()`方法中替换$1$行：

```java
    List<Stmt> parse() {
    List<Stmt> statements = new ArrayList<>();
    while (!isAtEnd()) {  
      // 替换部分开始
      statements.add(declaration());
      // 替换部分结束
    }

    return statements; 
  }
```

这里会调用下面的新方法：

> 在`Parser.java`文件中，在`expression()`方法后添加

```java
  private Stmt declaration() {
    try {
      if (match(VAR)) return varDeclaration();

      return statement();
    } catch (ParseError error) {
      synchronize();
      return null;
    }
  }
```

你还记得前面的章节中，我们建立了一个进行错误恢复的框架吗？现在我们终于可以用起来了。

当我们解析块或脚本中的 一系列语句时， `declaration()` 方法会被重复调用。因此当解析器进入恐慌模式时，它就是进行同步的正确位置。该方法的整个主体都封装在一个try块中，以捕获解析器开始错误恢复时抛出的异常。这样可以让解析器跳转到解析下一个语句或声明的开头。

真正的解析工作发生在try块中。首先，它通过查找前面的`var`关键字判断是否是变量声明语句。如果不是的话，就会进入已有的`statement()`方法中，解析`print`和语句表达式。

还记得 `statement()` 会在没有其它语句匹配时会尝试解析一个表达式语句吗？而`expression()`如果无法在当前语法标记处解析表达式，则会抛出一个语法错误？这一系列调用链可以保证在解析无效的声明或语句时会报告错误。

当解析器匹配到一个`var`标记时，它会跳转到：

> 在`Parser.java`文件中，在`printStatement()`方法后添加

```java
  private Stmt varDeclaration() {
    Token name = consume(IDENTIFIER, "Expect variable name.");

    Expr initializer = null;
    if (match(EQUAL)) {
      initializer = expression();
    }

    consume(SEMICOLON, "Expect ';' after variable declaration.");
    return new Stmt.Var(name, initializer);
  }
```

与之前一样，递归下降代码会遵循语法规则。解析器已经匹配了`var`标记，所以接下来要消费一个标识符标记作为变量的名称。

然后，如果找到`=`标记，解析器就知道后面有一个初始化表达式，并对其进行解析。否则，它会将初始器保持为`null`。最后，会消费语句末尾所需的分号。然后将所有这些都封装到一个Stmt.Var语法树节点中。

解析变量表达式甚至更简单。在`primary()`中，我们需要查找一个标识符标记。

> 在`Parser.java`文件中，在`primary()`方法中添加

```java
      return new Expr.Literal(previous().literal);
    }
    // 新增部分开始
    if (match(IDENTIFIER)) {
      return new Expr.Variable(previous());
    }
    // 新增部分开始
    if (match(LEFT_PAREN)) {
```

这为我们提供了声明和使用变量的可用前端，剩下的就是将其接入解释器中。在此之前，我们需要讨论变量在内存中的位置。

## $7.3$ 环境

变量与值之间的绑定关系需要保存在某个地方。自从Lisp发明圆括号以来，这种数据结构就被称为**环境**。

![An environment containing two bindings.](8.表达式和状态/environment-0971366.png)

你可以把它想象成一个映射，其中键是变量名称，值就是变量的值[^6]。实际上，这也就是我们在Java中采用的实现方式。我们可以直接在解释器中加入该映射及其管理代码，但是因为它形成了一个很好的概念，我们可以将其提取到单独的类中。

> 创建新文件`Environment.java`

```java
package com.atguigu;

import java.util.HashMap;
import java.util.Map;

public class Environment {
  private final Map<String, Object> values = new HashMap<>();
}
```

其中使用一个Java Map来保存绑定关系。这里使用原生字符串作为键，而不是使用标记。一个标记表示源文本中特定位置的一个代码单元，但是在查找变量时，具有相同名称的标识符标记都应该指向相同的变量（暂时忽略作用域）。使用原生字符串可以保证所有这些标记都会指向相同的映射键。

我们需要支持两个操作。首先，是变量定义操作，可以将一个新的名称与一个值进行绑定。

> 在`Environment.java`文件中，在`Environment`类中添加

```java
  public void define(String name, Object value) {
    values.put(name, value);
  }
```

不算困难，但是我们这里也做出了一个有趣的语义抉择。当我们向映射中添加键时，没有检查该键是否已存在。这意味着下面的代码是有效的：

```javascript
var a = "before";
print a; // "before".
var a = "after";
print a; // "after".
```

变量语句不仅可以定义一个新变量，也可以用于重新定义一个已有的变量。我们可以选择将其作为一个错误来处理。用户可能不打算重新定义已有的变量（如果他们想这样做，可能会使用赋值，而不是`var`），将重定义作为错误可以帮助用户发现这个问题。

然而，这样做与REPL的交互很差。在与REPL的交互中，最好是让用户不必在脑子记录已经定义了哪些变量。我们可以在REPL中允许重定义，在脚本中不允许。但是这样一来，用户就不得不学习两套规则，而且一种形式的代码复制粘贴到另一种形式后可能无法运行。

所以，为了保证两种模式的统一，我们选择允许重定义——至少对于全局变量如此。一旦一个变量存在，我们就需要可以查找该变量的方法。

> 在`Environment.java`文件中，在`Environment`类中添加

```java
public class Environment {
  private final Map<String, Object> values = new HashMap<>();
  // 新增部分开始
  public Object get(Token name) {
    if (values.containsKey(name.lexeme)) {
      return values.get(name.lexeme);
    }

    throw new RuntimeError(name,
        "Undefined variable '" + name.lexeme + "'.");
  }
  // 新增部分结束
  public void define(String name, Object value) {
```

这在语义上更有趣一些。如果找到了这个变量，只需要返回与之绑定的值。但如果没有找到呢？我们又需要做一个选择：

- 抛出语法错误

- 抛出运行时错误
  
- 允许该操作并返回默认值（如`nil`）

Lox是很宽松的，但最后一个选项对我来说有点过于宽松了。把它作为语法错误（一个编译时的错误）似乎是一个明智的选择。使用未定义的变量确实是一个错误，用户越早发现这个错误就越好。

问题在于，*使用*一个变量并不等同于*引用*它。如果代码块封装在函数中，则可以在代码块中引用变量，而不必立即对其求值。如果我们把引用未声明的变量当作一个静态错误，那么定义递归函数就变得更加困难了。

通过在检查函数体之前先声明函数名称，我们可以支持单一递归——调用自身的函数。但是，这无法处理互相调用的递归程序。考虑以下代码：

```js
function isOdd(n) {
  if (n == 0) return false;
  return isEven(n - 1);
}

function isEven(n) {
  if (n == 0) return true;
  return isOdd(n - 1);
}
```

当我们查看`isOdd()`方法时， `isEven()` 方法被调用的时候还没有被声明。如果我们交换着两个函数的顺序，那么在查看`isEven()`方法体时会发现`isOdd()`方法未被定义。

因为将其当作*静态*错误会使递归声明过于困难，因此我们把这个错误推迟到运行时。在一个变量被定义之前引用它是可以的，只要你不对引用进行*求值*。这样可以让前面的奇偶数代码正常工作。但是执行以下代码时，你会得到一个运行时错误：

```javascript
print a;
var a = "too late!";
```

与表达式计算代码中的类型错误一样，我们通过抛出一个异常来报告运行时错误。异常中包含变量的标记，以便我们告诉用户代码的什么位置出现了错误。

### $7.3.1$ 解释全局变量

`Interpreter`类会获取`Environment`类的一个实例。

*<u>lox/Interpreter.java，在 Interpreter类中添加：</u>*

```java
public class Interpreter {  
  // 添加部分开始                           
  private Environment environment = new Environment();
  // 添加部分结束                             
  public void interpret(List<Stmt> statements) {
```

我们直接将它作为一个字段存储在解释器中，这样，只要解释器仍在运行，变量就会留在内存中。

我们有两个新的语法树，所以这就是两个新的访问方法。第一个是关于声明语句的。

*<u>lox/Interpreter.java，在 visitPrintStmt()方法后添加：</u>*

```java
  @Override
  public Void visitVarStmt(Stmt.Var stmt) {
    Object value = null;
    if (stmt.initializer != null) {
      value = evaluate(stmt.initializer);
    }

    environment.define(stmt.name.lexeme, value);
    return null;
  }
```

如果该变量有初始化式，我们就对其求值。如果没有，我们就需要做一个选择。我们可以通过在解析器中*要求*初始化式令其成为一个语法错误。但是，大多数语言都不会这么做，所以在Lox中这样做感觉有点苛刻。

我们可以使其成为运行时错误。我们允许您定义一个未初始化的变量，但如果您在对其赋值之前访问它，就会发生运行时错误。这不是一个坏主意，但是大多数动态类型的语言都不会这样做。相反，我们使用最简单的方式。或者说，如果变量没有被显式初始化，Lox会将变量设置为`nil`。

```javascript
var a;
print a; // "nil".
```

因此，如果没有初始化式，我们将值设为`null`，这也是Lox中的`nil`值的Java表示形式。然后，我们告诉环境上下文将变量与该值进行绑定。

接下来，我们要对变量表达式求值。

*<u>lox/Interpreter.java，在 visitUnaryExpr()方法后添加：</u>*

```java
  @Override
  public Object visitVariableExpr(Expr.Variable expr) {
    return environment.get(expr.name);
  }
```

这里只是简单地将操作转发到环境上下文中，环境做了一些繁重的工作保证变量已被定义。这样，我们就可以支持基本的变量操作了。尝试以下代码：

```javascript
var a = 1;
var b = 2;
print a + b;
```

我们还不能复用代码，但是我们可以构建能够复用数据的程序。

## $7.4$ 赋值

你可以创建一种语言，其中有变量，但是不支持对该变量重新赋值（或更改）。Haskell就是一个例子。SML只支持可变引用和数组——变量不能被重新赋值。Rust则通过要求`mut`标识符开启赋值，从而引导用户远离可更改变量。

更改变量是一种副作用，顾名思义，一些语言专家认为副作用是肮脏或不优雅的。代码应该是纯粹的数学，它会产生值——纯净的、不变的值——就像上帝造物一样。而不是一些肮脏的自动机器，将数据块转换成各种形式，一次执行一条命令。

Lox没有这么严苛。Lox是一个命令式语言，可变性是与生俱来的，添加对赋值操作的支持并不需要太多工作。全局变量已经支持了重定义，所以该机制的大部分功能已经存在。主要的是，我们缺少显式的赋值符号。

### $7.4.1$ 赋值语法

这个小小的`=`语法比看起来要更复杂。像大多数C派生语言一样，赋值是一个表达式，而不是一个语句。和C语言中一样，它是优先级最低的表达式形式。这意味着该规则在语法中处于 `expression` 和`equality`（下一个优先级的表达式）之间。

```javascript
expression     → assignment ;
assignment     → IDENTIFIER "=" assignment
               | equality ;
```

这就是说，一个`assignment`（赋值式）要么是一个标识符，后跟一个`=`和一个对应值的表达式；要么是一个等式（也就是任何其它）表达式。稍后，当我们在对象中添加属性设置式时，赋值将会变得更加复杂，比如：

```java
instance.field = "value";
```

最简单的部分就是添加新的语法树节点。

*<u>tool/GenerateAst.java，在 main()方法中添加：</u>*

```java
    defineAst(outputDir, "Expr", Arrays.asList(
      // 新增部分开始
      "Assign   : Token name, Expr value",
      // 新增部分结束
      "Binary   : Expr left, Token operator, Expr right",
```

其中包含被赋值变量的标记，一个计算新值的表达式。运行AstGenerator得到新的`Expr.Assign`类之后，替换掉解析器中现有的`expression()`方法的方法体，以匹配最新的规则。

> 在`Parser.java`文件中，在`expression()`方法中替换$1$行

```java
  private Expr expression() {
    // 替换部分开始
    return assignment();
    // 替换部分结束
  }
```

这里开始变得棘手。单个标记前瞻递归下降解析器直到解析完左侧标记并且遇到`=`标记*之后*，才能判断出来正在解析的是赋值语句。你可能会想，为什么需要这样做？毕竟，我们也是完成左操作数的解析之后才知道正在解析的是`+`表达式。

区别在于，赋值表达式的左侧不是可以求值的表达式，而是一种伪表达式，计算出的是一个你可以赋值的“东西”。考虑以下代码：

```javascript
var a = "before";
a = "value";
```

在第二行中，我们不会对`a`进行求值（如果求值会返回“before”）。我们要弄清楚`a`指向的是什么变量，这样我们就知道该在哪里保存右侧表达式的值。这两个概念的经典术语是**左值**和**右值**。到目前为止，我们看到的所有产生值的表达式都是右值。左值"计算"会得到一个存储位置，你可以向其赋值。

我们希望语法树能够反映出左值不会像常规表达式那样计算。这也是为什么Expr.Assign节点的左侧是一个Token，而不是Expr。问题在于，解析器直到遇到`=`才知道正在解析一个左值。在一个复杂的左值中，可能在出现很多标记之后才能识别到。

```java
makeList().head.next = node;
```

我们只会前瞻一个标记，那我们该怎么办呢？我们使用一个小技巧，看起来像下面这样：

*<u>lox/Parser.java，在 expressionStatement()方法后添加：</u>*

```java
  private Expr assignment() {
    Expr expr = equality();

    if (match(EQUAL)) {
      Token equals = previous();
      Expr value = assignment();

      if (expr instanceof Expr.Variable) {
        Token name = ((Expr.Variable)expr).name;
        return new Expr.Assign(name, value);
      }

      error(equals, "Invalid assignment target."); 
    }

    return expr;
  }
```

解析赋值表达式的大部分代码看起来与解析其它二元运算符（如`+`）的代码类似。我们解析左边的内容，它可以是任何优先级更高的表达式。如果我们发现一个`=`，就解析右侧内容，并把它们封装到一个复杂表达式树节点中。

与二元运算符的一个细微差别在于，我们不会循环构建相同操作符的序列。因为赋值操作是右关联的，所以我们递归调用 `assignment()`来解析右侧的值。

诀窍在于，在创建赋值表达式节点之前，我们先查看左边的表达式，弄清楚它是什么类型的赋值目标。然后我们将右值表达式节点转换为左值的表示形式。

这种转换是有效的，因为事实证明，每个有效的赋值目标正好也是符合普通表达式的有效语法。考虑一个复杂的属性赋值操作，如下：

```java
newPoint(x + 2, 0).y = 3;
```

该赋值表达式的左侧也是一个有效的表达式。

```java
newPoint(x + 2, 0).y;
```

第一个例子设置该字段，第二个例子获取该字段。

这意味着，我们可以像解析表达式一样解析左侧内容，然后生成一个语法树，将其转换为赋值目标。如果左边的表达式不是一个有效的赋值目标，就会出现一个语法错误。这样可以确保在遇到类似下面的代码时会报告错误：

```java
a + b = c;
```

现在，唯一有效的赋值目标就是一个简单的变量表达式，但是我们后面会添加属性字段。这个技巧的最终结果是一个赋值表达式树节点，该节点知道要向什么赋值，并且有一个表达式子树用于计算要使用的值。所有这些都只用了一个前瞻标记，并且没有回溯。

### $7.4.2$ 赋值的语义

我们有了一个新的语法树节点，所以我们的解释器也需要一个新的访问方法。

*<u>lox/Interpreter.java，在 visitVarStmt()方法后添加：</u>*

```java
  @Override
  public Object visitAssignExpr(Expr.Assign expr) {
    Object value = evaluate(expr.value);
    environment.assign(expr.name, value);
    return value;
  }
```

很明显，这与变量声明很类似。首先，对右侧表达式运算以获取值，然后将其保存到命名变量中。这里不使用Environment中的 `define()`，而是调用下面的新方法：

*<u>lox/Environment.java，在 get()方法后添加：</u>*

```java
  void assign(Token name, Object value) {
    if (values.containsKey(name.lexeme)) {
      values.put(name.lexeme, value);
      return;
    }

    throw new RuntimeError(name,
        "Undefined variable '" + name.lexeme + "'.");
  }
```

赋值与定义的主要区别在于，赋值操作不允许创建新变量。就我们的实现而言，这意味着如果环境的变量映射中不存在变量的键，那就是一个运行时错误。

`visit()`方法做的最后一件事就是返回要赋给变量的值。这是因为赋值是一个表达式，可以嵌套在其他表达式里面，就像这样:

```javascript
var a = 1;
print a = 2; // "2".
```

我们的解释器现在可以创建、读取和修改变量。这和早期的BASICs一样复杂。全局变量很简单，但是在编写一个大型程序时，任何两块代码都可能不小心修改对方的状态，这就不好玩了。我们需要*局部*变量，这意味着是时候讨论*作用域*了。

## $7.5$ 作用域

**作用域**定义了名称映射到特定实体的一个区域。多个作用域允许同一个名称在不同的上下文中指向不同的内容。在我家，“Bob”通常指的是我自己，但是在你的身边，你可能人数另外一个Bob。相同的名字，基于你的所知所见指向了不同的人。

**词法作用域**（或者比较少见的**静态作用域**）是一种特殊的作用域定义方式，程序本身的文本显示了作用域的开始和结束位置。Lox，和大多数现代语言一样，变量在词法作用域内有效。当你看到使用了某些变量的表达式时，你通过静态地阅读代码就可以确定其指向的变量声明。

举例来说：

```javascript
{
  var a = "first";
  print a; // "first".
}

{
  var a = "second";
  print a; // "second".
}
```

这里，我们在两个块中都定义了一个变量`a`。我们可以从代码中看出，在第一个`print`语句中使用的`a`指的是第一个`a`，第二个语句指向的是第二个变量。

![An environment for each 'a'.](8.表达式和状态/blocks.png)

这与**动态作用域**形成了对比，在动态作用域中，直到执行代码时才知道名称指向的是什么。Lox没有动态作用域*变量*，但是对象上的方法和字段是动态作用域的。

```java
class Saxophone {
  play() {
    print "Careless Whisper";
  }
}

class GolfClub {
  play() {
    print "Fore!";
  }
}

fun playIt(thing) {
  thing.play();
}
```

当`playIt()`调用`thing.play()`时，我们不知道我们将要听到的是 "Careless Whisper "还是 "Fore!" 。这取决于你向函数传递的是Saxophone还是GolfClub，而我们在运行时才知道这一点。

作用域和环境是近亲，前者是理论概念，而后者是实现它的机制。当我们的解释器处理代码时，影响作用域的语法树节点会改变环境上下文。在像Lox这样的类C语言语法中，作用域是由花括号的块控制的。（这就是为什么我们称它为**块范围**）。

```java
{
  var a = "in block";
}
print a; // Error! No more "a".
```

块的开始引入了一个新的局部作用域，当执行通过结束的`}`时，这个作用域就结束了。块内声明的任何变量都会消失。

### $7.5.1$ 嵌套和遮蔽

实现块作用域的第一步可能是这样的：

1. 当访问块内的每个语句时，跟踪所有声明的变量。

2. 执行完最后一条语句后，告诉环境将这些变量全部删除。

这对前面的例子是可行的。但是请记住，局部作用域的一个目的是封装——程序中一个块内的代码，不应该干扰其他代码块。看看下面的例子：

```java
// How loud?
var volume = 11;

// Silence.
volume = 0;

// Calculate size of 3x4x5 cuboid.
{
  var volume = 3 * 4 * 5;
  print volume;
}
```

请看这个代码块，在这里我们声明了一个局部变量`volume`来计算长方体的体积。该代码块退出后，解释器将删除*全局*`volume`变量。这是不对的。当我们退出代码块时，我们应该删除在块内声明的所有变量，但是如果在代码块外声明了相同名称的变量，那就是一个不同的变量。它不应该被删除。

当局部变量与外围作用域中的变量具有相同的名称时，内部变量会遮蔽外部变量。代码块内部不能再看到外部变量——它被遮蔽在内部变量的阴影中——但它仍然是存在的。

当进入一个新的块作用域时，我们需要保留在外部作用域中定义的变量，这样当我们退出内部代码块时这些外部变量仍然存在。为此，我们为每个代码块定义一个新的环境，该环境只包含该作用域中定义的变量。当我们退出代码块时，我们将丢弃其环境并恢复前一个环境。

我们还需要处理没有被遮蔽的外围变量。

```javascript
var global = "outside";
{
  var local = "inside";
  print global + local;
}
```

这段代码中，`global`在外部全局环境中，`local`则在块环境中定义。在执行print`语句时，这两个变量都在作用域内。为了找到它们，解释器不仅要搜索当前最内层的环境，还必须搜索所以外围的环境。

我们通过将环境链接在一起来实现这一点。每个环境都有一个对直接外围作用域的环境的引用。当我们查找一个变量时，我们从最内层开始遍历环境链直到找到该变量。从内部作用域开始，就是我们使局部变量遮蔽外部变量的方式。

![Environments for each scope, linked together.](8.表达式和状态/chaining.png)

在我们添加块语法之前，我们要强化Environment类对这种嵌套的支持。首先，我们在每个环境中添加一个对其外围环境的引用。

*<u>lox/Environment.java，在 Environment类中添加：</u>*

```java
class Environment {
  // 新增部分开始
  final Environment enclosing;
  // 新增部分结束
  private final Map<String, Object> values = new HashMap<>();
```

这个字段需要初始化，所以我们添加两个构造函数。

*<u>lox/Environment.java，在 Environment类中添加：</u>*

```java
  Environment() {
    enclosing = null;
  }

  Environment(Environment enclosing) {
    this.enclosing = enclosing;
  }
```

无参构造函数用于全局作用域环境，它是环境链的结束点。另一个构造函数用来创建一个嵌套在给定外部作用域内的新的局部作用域。

我们不必修改`define()`方法——因为新变量总是在当前最内层的作用域中声明。但是变量的查找和赋值是结合已有的变量一起处理的，需要遍历环境链以找到它们。首先是查找操作：

*<u>lox/Environment.java，在 get()方法中添加：</u>*

```java
      return values.get(name.lexeme);
    }
    // 新增部分开始
    if (enclosing != null) return enclosing.get(name);
    // 新增部分结束
    throw new RuntimeError(name,
        "Undefined variable '" + name.lexeme + "'.");
```

如果当前环境中没有找到变量，就在外围环境中尝试。然后递归地重复该操作，最终会遍历完整个链路。如果我们到达了一个没有外围环境的环境，并且仍然没有找到这个变量，那我们就放弃，并且像之前一样报告一个错误。

赋值也是如此。

*<u>lox/Environment.java，在 assign()方法中添加：</u>*

```java
      values.put(name.lexeme, value);
      return;
    }
    // 新增部分开始
    if (enclosing != null) {
      enclosing.assign(name, value);
      return;
    }
    // 新增部分结束
    throw new RuntimeError(name,
```

同样，如果变量不在此环境中，它会递归地检查外围环境。

### $7.5.2$ 块语法和语义

现在环境已经嵌套了，我们就准备向语言中添加块了。请看以下语法：

```javascript
statement      → exprStmt
               | printStmt
               | block ;

block          → "{" declaration* "}" ;
```

块是由花括号包围的一系列语句或声明(可能是空的)。块本身就是一条语句，可以出现在任何允许语句的地方。语法树节点如下所示。

*<u>tool/GenerateAst.java，在 main()方法中添加：</u>*

```java
    defineAst(outputDir, "Stmt", Arrays.asList(
      // 新增部分开始
      "Block      : List<Stmt> statements",
      // 新增部分结束
      "Expression : Expr expression",
```

它包含块中语句的列表。解析很简单。与其他语句一样，我们通过块的前缀标记(在本例中是`{`)来检测块的开始。在`statement()`方法中，我们添加代码：

*<u>lox/Parser.java，在 statement()方法中添加：</u>*

```java
    if (match(PRINT)) return printStatement();
    // 新增部分开始
    if (match(LEFT_BRACE)) return new Stmt.Block(block());
    // 新增部分结束
    return expressionStatement();
```

真正的工作都在这里进行：

*<u>lox/Parser.java，在 expressionStatement()方法后添加：</u>*

```java
  private List<Stmt> block() {
    List<Stmt> statements = new ArrayList<>();

    while (!check(RIGHT_BRACE) && !isAtEnd()) {
      statements.add(declaration());
    }

    consume(RIGHT_BRACE, "Expect '}' after block.");
    return statements;
  }
```

我们先创建一个空列表，然后解析语句并将其放入列表中，直至遇到块的结尾（由`}`符号标识）。注意，该循环还有一个明确的`isAtEnd()`检查。我们必须小心避免无限循环，即使在解析无效代码时也是如此。如果用户忘记了结尾的`}`，解析器需要保证不能被阻塞。

语法到此为止。对于语义，我们要在Interpreter中添加另一个访问方法。

*<u>lox/Interpreter.java，在 execute()方法后添加：</u>*

```java
  @Override
  public Void visitBlockStmt(Stmt.Block stmt) {
    executeBlock(stmt.statements, new Environment(environment));
    return null;
  }
```

要执行一个块，我们先为该块作用域创建一个新的环境，然后将其传入下面这个方法：

*<u>lox/Interpreter.java，在execute()方法后添加：</u>*

```java
  void executeBlock(List<Stmt> statements,
                    Environment environment) {
    Environment previous = this.environment;
    try {
      this.environment = environment;

      for (Stmt statement : statements) {
        execute(statement);
      }
    } finally {
      this.environment = previous;
    }
  }
```

这个新方法会在给定的环境上下文中执行一系列语句。在此之前，解释器中的 `environment` 字段总是指向相同的环境——全局环境。现在，这个字段会指向*当前*环境，也就是与要执行的代码的最内层作用域相对应的环境。

为了在给定作用域内执行代码，该方法会先更新解释器的 `environment` 字段，执行所有的语句，然后恢复之前的环境。基于Java中一贯的优良传统，它使用`finally`子句来恢复先前的环境。这样一来，即使抛出了异常，环境也会被恢复。

出乎意料的是，这就是我们为了完全支持局部变量、嵌套和遮蔽所需要做的全部事情。试运行下面的代码：

```javascript
var a = "global a";
var b = "global b";
var c = "global c";
{
  var a = "outer a";
  var b = "outer b";
  {
    var a = "inner a";
    print a;
    print b;
    print c;
  }
  print a;
  print b;
  print c;
}
print a;
print b;
print c;
```

我们的小解释器现在可以记住东西了，我们举例全功能编程语言又近了一步。

# $8$ 控制流

现在，我们的解释器只不过是一个计算器而已。一个$Atguigu$程序在结束之前只能做固定的工作量。要想让它的运行时间延长一倍，你就必须让源代码的长度增加一倍。我们即将解决这个问题。在本章中，我们的解释器向编程语言大联盟迈出了一大步：图灵完备性。

## $8.1$ 图灵机（简介）

在上世纪初，数学家们陷入了一系列令人困惑的悖论之中，导致他们对自己工作所依赖的基础的稳定性产生怀疑。为了解决这一危机，他们又回到了原点。他们希望从少量的公理、逻辑和集合理论开始，在一个不透水的地基上重建数学。

他们想要严格地回答这样的问题：“所有真实的陈述都可以被证明吗？”，“我们可以计算我们能定义的所有函数吗？”，甚至是更一般性的问题，“当我们声称一个函数是'可计算的'时，代表什么意思？”

他们认为前两个问题的答案应该是“是”，剩下的就是去证明它。但事实证明这两个问题的答案都是“否”。而且令人惊讶的是，这两个问题是深深地交织在一起的。这是数学的一个迷人的角落，它触及了关于大脑能够做什么和宇宙如何运作的基本问题。我在这里说不清楚。

我想指出的是，在证明前两个问题的答案是 "否 "的过程中，艾伦·图灵和阿隆佐·邱奇为最后一个问题设计了一个精确的答案，即定义了什么样的函数是可计算的。他们各自设计了一个具有最小机械集的微型系统，该系统仍然强大到足以计算一个超大类函数中的任何一个。

这些现在被认为是“可计算函数”。图灵的系统被称为**图灵机**，邱奇的系统是**lambda演算**。这两种方法仍然被广泛用作计算模型的基础，事实上，许多现代函数式编程语言的核心都是lambda演算。

![A Turing machine.](9.控制流/turing-machine.png)

图灵机的知名度更高——目前还没有关于阿隆佐·邱奇的好莱坞电影，但这两种形式[在能力上是等价的](https://en.wikipedia.org/wiki/Church%E2%80%93Turing_thesis)。事实上，任何具有最低表达能力的编程语言都足以计算任何可计算函数。

你可以用自己的语言为图灵机编写一个模拟器来证明这一点。由于图灵证明了他的机器可以计算任何可计算函数，推而广之，这意味着你的语言也可以。你所需要做的就是把函数翻译成图灵机，然后在你的模拟器上运行它。

如果你的语言有足够的表达能力来做到这一点，它就被认为是**图灵完备**的。图灵机非常简单，所以它不需要太多的能力。您基本上只需要算术、一点控制流以及分配和使用(理论上)任意数量内存的能力。我们已经具备了第一个条件。在本章结束时，我们将具备第二个条件。

## $8.2$ 条件执行

说完了历史，现在让我们把语言优化一下。我们大致可以把控制流分为两类：

- **条件**或**分支控制流**是用来不执行某些代码的。意思是，你可以把它看作是跳过了代码的一个区域。

- **循环控制流**是用于多次执行一块代码的。它会 **向回** 跳转，从而能再次执行某些代码。用户通常不需要无限循环，所以一般也会有一些条件逻辑用于判断何时停止循环。

分支更简单一些，所以我们先从分支开始实现。C衍生语言中包含两个主要的条件执行功能，即`if`语句和“条件”运算符（`?:`）。`if`语句使你可以按条件执行语句，而条件运算符使你可以按条件执行表达式。

为了简单起见，Lox没有条件运算符，所以让我们直接开始`if`语句吧。我们的语句语法需要一个新的生成式。

```javascript
statement      → exprStmt
               | ifStmt
               | printStmt
               | block ;

ifStmt         → "if" "(" expression ")" statement
               ( "else" statement )? ;
```

if语句有一个表达式作为条件，然后是一个在条件为真时要执行的语句。另外，它还可以有一个`else`关键字和条件为假时要执行的语句。语法树节点中对语法的这三部分都有对应的字段。

*<u>tool/GenerateAst.java，在 main()方法中添加：</u>*

```java
      "Expression : Expr expression",
      // 新增部分开始
      "If         : Expr condition, Stmt thenBranch," +
                  " Stmt elseBranch",
      // 新增部分结束
      "Print      : Expr expression",
```

与其它语句类似，解析器通过开头的`if`关键字来识别`if`语句。

> 在`Parser.java`文件中，在`statement()`方法中添加

```java
  private Stmt statement() {
    // 新增部分开始
    if (match(IF)) return ifStatement();
    // 新增部分结束
    if (match(PRINT)) return printStatement();
```

如果发现了`if`关键字，就调用下面的新方法解析其余部分[^5]：

> 在`Parser.java`文件中，在`statement()`方法后添加

```java
  private Stmt ifStatement() {
    consume(LEFT_PAREN, "Expect '(' after 'if'.");
    Expr condition = expression();
    consume(RIGHT_PAREN, "Expect ')' after if condition."); 

    Stmt thenBranch = statement();
    Stmt elseBranch = null;
    if (match(ELSE)) {
      elseBranch = statement();
    }

    return new Stmt.If(condition, thenBranch, elseBranch);
  }
```

跟之前一样，解析代码严格遵循语法。它通过查找前面的`else`关键字来检测`else`子句。如果没有，语法树中的`elseBranch`字段为`null`。

实际上，这个看似无伤大雅的可选项在我们的语法中造成了歧义。考虑以下代码：

```java
if (first) if (second) whenTrue(); else whenFalse();
```

谜题是这样的:这里的`else`子句属于哪个`if`语句?这不仅仅是一个关于如何标注语法的理论问题。它实际上会影响代码的执行方式：

- 如果我们将`else`语句关联到第一个`if`语句，那么当`first`为假时，无论`second`的值是多少，都将调用`whenFalse()`。

- 如果我们将`else`语句关联到第二个`if`语句，那么只有当`first`为假并且`second`也为假时，才会调用`whenFalse()`。

由于`else`子句是可选的，而且没有明确的分隔符来标记`if`语句的结尾，所以当你以这种方式嵌套`if`时，语法是不明确的。这种典型的语法陷阱被称为悬空的else问题。

![Two ways the else can be interpreted.](9.控制流/dangling-else.png)

也可以定义一个上下文无关的语法来直接避免歧义，但是需要将大部分语句规则拆分成对，一个是允许带有`else`的`if`语句，另一个不允许。这很烦人。

相反，大多数语言和解析器都以一种特殊的方式避免了这个问题。不管他们用什么方法来解决这个问题，他们总是选择同样的解释——`else`与前面最近的`if`绑定在一起。

我们的解析器已经很方便地做到了这一点。因为 `ifStatement()`在返回之前会继续寻找一个`else`子句，连续嵌套的最内层调用在返回外部的`if`语句之前，会先为自己声明`else`语句。

语法就绪了，我们可以开始解释了。

*<u>lox/Interpreter.java，在 visitExpressionStmt()后添加：</u>*

```java
  @Override
  public Void visitIfStmt(Stmt.If stmt) {
    if (isTruthy(evaluate(stmt.condition))) {
      execute(stmt.thenBranch);
    } else if (stmt.elseBranch != null) {
      execute(stmt.elseBranch);
    }
    return null;
  }
```

解释器实现就是对相同的Java代码的简单包装。它首先对条件表达式进行求值。如果为真，则执行`then`分支。否则，如果有存在`else`分支，就执行该分支。

如果你把这段代码与解释器中我们已实现的处理其它语法的代码进行比较，会发现控制流中特殊的地方就在于Java的`if`语句。其它大多数语法树总是会对子树求值，但是这里，我们可能会不执行`then`语句或`else`语句。如果其中任何一个语句有副作用，那么选择不执行某条语句就是用户可见的。

## $8.3$ 逻辑操作符

由于我们没有条件运算符，你可能认为我们已经完成分支开发了，但其实还没有。虽然没有三元运算符，但是还有两个其它操作符在技术上是控制流结构——逻辑运算符`and`和`or`。

它们与其它二进制运算符不同，是因为它们会短路。如果在计算左操作数之后，我们已经确切知道逻辑表达式的结果，那么就不再计算右操作数。例如：

```java
false and sideEffect();
```

对于一个`and`表达式来说，两个操作数都必须是真，才能得到结果为真。我们只要看到左侧的`false`操作数，就知道结果不会是真，也就不需要对`sideEffect()`求值，会直接跳过它。

这就是为什么我们没有在实现其它二元运算符的时候一起实现逻辑运算符。现在我们已经准备好了。这两个新的运算符在优先级表中的位置很低，类似于C语言中的`||`和`&&`，它们都有各自的优先级，`or`低于`and`。我们把这两个运算符插入`assignment` 和 `equality`之间。

```javascript
expression     → assignment ;
assignment     → IDENTIFIER "=" assignment
               | logic_or ;
logic_or       → logic_and ( "or" logic_and )* ;
logic_and      → equality ( "and" equality )* ;
```

`assignment` 现在不是落到 `equality`，而是继续进入`logic_or`。两个新规则，`logic_or` 和 `logic_and`，与其它二元运算符类似。然后`logic_and`会调用`equality`计算其操作数，然后我们就链入了表达式规则的其它部分。

对于这两个新表达式，我们可以重用Expr.Binary类，因为他们具有相同的字段。但是这样的话，`visitBinaryExpr()` 方法中必须检查运算符是否是逻辑运算符，并且要使用不同的代码处理短路逻辑。我认为更整洁的方法是为这些运算符定义一个新类，这样它们就有了自己的`visit`方法。

*<u>tool/GenerateAst.java，在main()方法中添加：</u>*

```java
      "Literal  : Object value",
      // 新增部分开始
      "Logical  : Expr left, Token operator, Expr right",
      // 新增部分结束
      "Unary    : Token operator, Expr right",
```

为了将新的表达式加入到解析器中，我们首先将赋值操作的解析代码改为调用`or()`方法。

> 在`Parser.java`文件中，在`assignment()`方法中替换$1$行

```java
  private Expr assignment() {
    // 新增部分开始
    Expr expr = or();
    // 新增部分结束
    if (match(EQUAL)) {
```

解析一系列`or`语句的代码与其它二元运算符相似。

> 在`Parser.java`文件中，在`assignment()`方法后添加

```java
  private Expr or() {
    Expr expr = and();

    while (match(OR)) {
      Token operator = previous();
      Expr right = and();
      expr = new Expr.Logical(expr, operator, right);
    }

    return expr;
  }
```

它的操作数是位于下一优先级的新的`and`表达式。

> 在`Parser.java`文件中，在`or()`方法后添加

```java
  private Expr and() {
    Expr expr = equality();

    while (match(AND)) {
      Token operator = previous();
      Expr right = equality();
      expr = new Expr.Logical(expr, operator, right);
    }

    return expr;
  }
```

这里会调用 `equality()` 计算操作数，这样一来，表达式解析器又重新绑定到了一起。我们已经准备好进行解释了。

*<u>lox/Interpreter.java，在 visitLiteralExpr()方法后添加：</u>*

```java
  @Override
  public Object visitLogicalExpr(Expr.Logical expr) {
    Object left = evaluate(expr.left);

    if (expr.operator.type == TokenType.OR) {
      if (isTruthy(left)) return left;
    } else {
      if (!isTruthy(left)) return left;
    }

    return evaluate(expr.right);
  }
```

如果你把这个方法与前面章节的`visitBinaryExpr()`方法相比较，就可以看出其中的区别。这里，我们先计算左操作数。然后我们查看结果值，判断是否可以短路。当且仅当不能短路时，我们才计算右侧的操作数。

另一个有趣的部分是决定返回什么实际值。由于Lox是动态类型的，我们允许任何类型的操作数，并使用真实性来确定每个操作数代表什么。我们对结果采用类似的推理。逻辑运算符并不承诺会真正返回`true`或`false`，而只是保证它将返回一个具有适当真实性的值。

幸运的是，我们手边就有具有适当真实性的值——即操作数本身的结果，所以我们可以直接使用它们。如：

```javascript
print "hi" or 2; // "hi".
print nil or "yes"; // "yes".
```

在第一行，`“hi”`是真的，所以`or`短路并返回它。在第二行，`nil`是假的，因此它计算并返回第二个操作数`“yes”`。

这样就完成了Lox中的所有分支原语，我们准备实现循环吧。

## $8.4$ $while$循环

$Atguigu$有两种类型的循环控制流语句，分别是`while`和`for`。`while`循环更简单一点，我们先从它开始.

```javascript
statement      → exprStmt
               | ifStmt
               | printStmt
               | whileStmt
               | block ;

whileStmt      → "while" "(" expression ")" statement ;
```

我们在`statement`规则中添加一个子句，指向while对应的新规则`whileStmt`。该规则接收一个`while`关键字，后跟一个带括号的条件表达式，然后是循环体对应的语句。新语法规则需要定义新的语法树节点。

*<u>tool/GenerateAst.java,在 main()方法中新增，前一行后添加“,”</u>* 

```java
      "Print      : Expr expression",
      "Var        : Token name, Expr initializer",
      // 新增部分开始
      "While      : Expr condition, Stmt body"
      // 新增部分结束
    ));
```

该节点中保存了条件式和循环体。这里就可以看出来为什么表达式和语句最好要有单独的基类。字段声明清楚地表明了，条件是一个表达式，循环主体是一个语句。

在解析器中，我们遵循与`if`语句相同的处理步骤。首先，在 `statement()` 添加一个case分支检查并匹配开头的关键字。

> 在`Parser.java`文件中，在`statement()`方法中添加

```java
    if (match(PRINT)) return printStatement();
    // 新增部分开始
    if (match(WHILE)) return whileStatement();
    // 新增部分结束
    if (match(LEFT_BRACE)) return new Stmt.Block(block());
```

实际的工作委托给下面的方法：

> 在`Parser.java`文件中，在`varDeclaration()`方法后添加

```java
  private Stmt whileStatement() {
    consume(LEFT_PAREN, "Expect '(' after 'while'.");
    Expr condition = expression();
    consume(RIGHT_PAREN, "Expect ')' after condition.");
    Stmt body = statement();

    return new Stmt.While(condition, body);
  }
```

语法非常简单，这里将其直接翻译为Java。说到直接翻译成Java，下面是我们执行新语法的方式：

*<u>lox/Interpreter.java，在 visitVarStmt()方法后添加：</u>*

```java
  @Override
  public Void visitWhileStmt(Stmt.While stmt) {
    while (isTruthy(evaluate(stmt.condition))) {
      execute(stmt.body);
    }
    return null;
  }
```

和`if`的访问方法一样，这里的访问方法使用了相应的Java特性。这个方法并不复杂，但它使Lox变得更加强大。我们终于可以编写一个运行时间不受源代码长度严格限制的程序了。

## $8.5$ $for$循环

我们已经到了最后一个控制流结构，即$JS$语言风格`for`循环。我可能不需要提醒你，但还是要说它看起来是这样的： 

```java
for (var i = 0; i < 10; i = i + 1) print(i);
```

在语法中，是这样的：

```javascript
statement      → exprStmt
               | forStmt
               | ifStmt
               | printStmt
               | whileStmt
               | block ;

forStmt        → "for" "(" ( varDecl | exprStmt | ";" )
                 expression? ";"
                 expression? ")" statement ;
```

在括号内，有三个由分号分隔的子语句：

1. 第一个子句是*初始化式*。它只会在任何其它操作之前执行一次。它通常是一个表达式，但是为了便利，我们也允许一个变量声明。在这种情况下，变量的作用域就是`for`循环的其它部分——其余两个子式和循环体。

2. 接下来是*条件表达式*。与`while`循环一样，这个表达式控制了何时退出循环。它会在每次循环开始之前执行一次（包括第一次）。如果结果是真，就执行循环体；否则，就结束循环。

3. 最后一个子句是*增量式*。它是一个任意的表达式，会在每次循环结束的时候做一些工作。因为表达式的结果会被丢弃，所以它必须有副作用才能有用。在实践中，它通常会对变量进行递增。

这些子语句都可以忽略。在右括号之后是一个语句作为循环体，通常是一个代码块。

### $8.5.1$ 语法脱糖

这里包含了很多配件，但是请注意，它所做的任何事情中，没有一件是无法用已有的语句实现的。如果`for`循环不支持初始化子句，你可以在`for`语句之前加一条初始化表达式。如果没有增量子语句，你可以直接把增量表达式放在循环体的最后。

换句话说，$Atguigu$ **不需要** `for`循环，它们只是让一些常见的代码模式更容易编写。这类功能被称为**语法糖**。例如，前面的`for`循环可以改写成这样：

```javascript
{
  var i = 0;
  while (i < 10) {
    print i;
    i = i + 1;
  }
}
```

虽然这个脚本不太容易看懂，但这个脚本与之前那个语义完全相同。像Lox中的`for`循环这样的语法糖特性可以使语言编写起来更加愉快和高效。但是，特别是在复杂的语言实现中，每一个需要后端支持和优化的语言特性都是代价昂贵的。

我们可以通过**脱糖**来吃这个蛋糕。这个有趣的词描述了这样一个过程：前端接收使用了语法糖的代码，并将其转换成后端知道如何执行的更原始的形式。

我们将把`for`循环脱糖为`while`循环和其它解释器可处理的其它语句。在我们的简单解释器中，脱糖真的不能为我们节省很多工作，但它确实给了我一个契机来向你介绍这一技术。因此，与之前的语句不同，我们不会为`for`循环添加一个新的语法树节点。相反，我们会直接进行解析。首先，先引入一个我们要用到的依赖：

> 在`Parser.java`文件中，添加代码

```java
import java.util.ArrayList;
// 新增部分开始
import java.util.Arrays;
// 新增部分结束
import java.util.List;
```

像每个语句一样，我们通过匹配`for`关键字来解析循环。

> 在`Parser.java`文件中，在`statement()`方法中新增

```java
  private Stmt statement() {
    // 新增部分开始
    if (match(FOR)) return forStatement();
    // 新增部分结束
    if (match(IF)) return ifStatement();
```

接下来是有趣的部分，脱糖也是在这里发生的，所以我们会一点点构建这个方法，首先从子句之前的左括号开始。

> 在`Parser.java`文件中，在`statement()`方法后添加

```java
  private Stmt forStatement() {
    consume(LEFT_PAREN, "Expect '(' after 'for'.");

    // More here...
  }
```

接下来的第一个子句是初始化式。

> 在`Parser.java`文件中，在`forStatement()`方法中替换$1$行

```java
    consume(LEFT_PAREN, "Expect '(' after 'for'.");
    // 替换部分开始
    Stmt initializer;
    if (match(SEMICOLON)) {
      initializer = null;
    } else if (match(VAR)) {
      initializer = varDeclaration();
    } else {
      initializer = expressionStatement();
    }
    // 替换部分结束
  }
```

如果`(`后面的标记是分号，name初始化式就被省略了。否则，我们就检查`var`关键字，看它是否是一个变量声明。如果这两者都不符合，那么它一定是一个表达式。我们对其进行解析，并将其封装在一个表达式语句中，这样初始化器就必定属于Stmt类型。

接下来是条件表达式。

> 在`Parser.java`文件中，在`forStatement()`方法中添加代码

```java
      initializer = expressionStatement();
    }
    // 新增部分开始
    Expr condition = null;
    if (!check(SEMICOLON)) {
      condition = expression();
    }
    consume(SEMICOLON, "Expect ';' after loop condition.");
    // 新增部分结束
  }
```

同样，我们查找分号检查子句是否被忽略。最后一个子句是增量语句。

> 在`Parser.java`文件中，在`forStatement()`方法中添加

```java
    consume(SEMICOLON, "Expect ';' after loop condition.");
    // 新增部分开始
    Expr increment = null;
    if (!check(RIGHT_PAREN)) {
      increment = expression();
    }
    consume(RIGHT_PAREN, "Expect ')' after for clauses.");
    // 新增部分结束
  }
```

它类似于条件式子句，只是这个子句是由右括号终止的。剩下的就是循环主体了。

> 在`Parser.java`文件中，在`forStatement()`方法中添加代码

```java
    consume(RIGHT_PAREN, "Expect ')' after for clauses.");
    // 新增部分开始
    Stmt body = statement();

    return body;
    // 新增部分结束
  }
```

我们已经解析了`for`循环的所有部分，得到的AST节点也存储在一些Java本地变量中。这里也是脱糖开始的地方。我们利用这些变量来合成表示`for`循环语义的语法树节点，就像前面展示的手工脱糖的例子一样。

如果我们向后向前处理，代码会更简单一些，所以我们从增量子句开始。

> 在`Parser.java`文件中，在`forStatement()`方法中新增

```java
    Stmt body = statement();
    // 新增部分开始
    if (increment != null) {
      body = new Stmt.Block(
          Arrays.asList(
              body,
              new Stmt.Expression(increment)));
    }
    // 新增部分结束
    return body;
```

如果存在增量子句的话，会在循环的每个迭代中在循环体结束之后执行。我们用一个代码块来代替循环体，这个代码块中包含原始的循环体，后面跟一个执行增量子语句的表达式语句。

> 在`Parser.java`文件中，在`forStatement()`方法中新增代码

```java
    }
    // 新增部分开始
    if (condition == null) condition = new Expr.Literal(true);
    body = new Stmt.While(condition, body);
    // 新增部分结束
    return body;
```

接下来，我们获取条件式和循环体，并通过基本的`while`语句构建对应的循环。如果条件式被省略了，我们就使用`true`来创建一个无限循环。

> 在`Parser.java`文件中，在`forStatement()`方法中新增

```java
    body = new Stmt.While(condition, body);
    // 新增部分开始
    if (initializer != null) {
      body = new Stmt.Block(Arrays.asList(initializer, body));
    }
    // 新增部分结束
    return body;
```

最后，如果有初始化式，它会在整个循环之前运行一次。我们的做法是，再次用代码块来替换整个语句，该代码块中首先运行一个初始化式，然后执行循环。

就是这样。我们的解释器现在已经支持了C语言风格的`for`循环，而且我们根本不需要修改解释器类。因为我们通过脱糖将其转换为了解释器已经知道如何访问的节点，所以无需做其它的工作。

最后，Lox已强大到足以娱乐我们，至少几分钟。下面是一个打印斐波那契数列前21个元素的小程序：

```javascript
var a = 0;
var temp;

for (var b = 1; a < 10000; b = temp + b) {
  print(a);
  temp = a;
  a = b;
}
```

# $9$ 函数

这也是人类思维的运作方式——将旧的想法复合成为新结构，成为新的想法，而这些想法本身又可以被用于复合，循环往复，无休无止，越来越远离每一种语言赖以生存的基本的土壤。

这一章标志着很多艰苦工作的一个高潮。在前面的章节中，各自添加了一些有用的功能，但是每一章也都提供了一个拼图的碎片。我们整理这些碎片——表达式、语句、变量、控制流和词法作用域，再加上其它功能，并把他们组合起来，以支持真正的用户定义函数和函数调用。

## $9.1$ 函数调用

你肯定熟悉C语言风格的函数调用语法，但其语法可能比你意识到的更微妙。调用通常是指向命名的函数，例如：

```java
average(1, 2);
```

但是被调用函数的名称实际上并不是调用语法的一部分。被调用者（ **callee**）可以是计算结果为一个函数的任何表达式。(好吧，它必须是一个非常高优先级的表达式，但是圆括号可以解决这个问题。)例如：

```java
getCallback()();
```

这里有两个函数调用。第一对括号将`getCallback`作为其被调用者。但是第二对括号将整个`getCallback()` 表达式作为其被调用者。表达式后面的小括号表示函数调用，你可以把调用看作是一种以`(`开头的后缀运算符。

这个“运算符”比其它运算符（包括一元运算符）有更高的优先级。所以我们通过让`unary`规则跳转到新的`call`规则，将其添加到语法中。

```javascript
unary          → ( "!" | "-" ) unary | call ;
call           → primary ( "(" arguments? ")" )* ;
```

该规则匹配一个基本表达式，后面跟着0个或多个函数调用。如果没有括号，则解析一个简单的基本表达式。否则，每一对圆括号都表示一个函数调用，圆括号内有一个可选的参数列表。参数列表语法是：

```javascript
arguments      → expression ( "," expression )* ;
```

这个规则要求至少有一个参数表达式，后面可以跟0个或多个其它表达式，每两个表达式之间用`,`分隔。为了处理无参调用，`call`规则本身认为整个`arguments`生成式是可选的。

我承认，对于极其常见的 "零或多个逗号分隔的事物 "模式来说，这在语法上似乎比你想象的更难处理。有一些复杂的元语法可以更好地处理这个问题，但在我们的BNF和我见过的许多语言规范中，它就是如此的麻烦。

在我们的语法树生成器中，我们添加一个新节点。

*<u>tool/GenerateAst.java，在 main()方法中添加代码：</u>*

```
      "Binary   : Expr left, Token operator, Expr right",
      // 新增部分开始
      "Call     : Expr callee, Token paren, List<Expr> arguments",
      // 新增部分结束
      "Grouping : Expr expression",
```

它存储了被调用者表达式和参数表达式列表，同时也保存了右括号标记。当我们报告由函数调用引起的运行时错误时，会使用该标记的位置。

打开解析器，原来`unary()`直接跳转到`primary()`方法，将其修改为调用`call()`。

> 在`Parser.java`文件中，在`unary()`方法中替换一行

```java
      return new Expr.Unary(operator, right);
    }
    // 替换部分开始
    return call();
    // 替换部分结束
  }
```

该方法定义为：

> 在`Parser.java`文件中，在`unary()`方法后添加

```java
  private Expr call() {
    Expr expr = primary();

    while (true) { 
      if (match(LEFT_PAREN)) {
        expr = finishCall(expr);
      } else {
        break;
      }
    }

    return expr;
  }
```

这里的代码与语法规则并非完全一致。为了保持代码简洁，我调整了一些东西——这是我们手写解析器的优点之一。但它与我们解析中缀运算符的方式类似。首先，我们解析一个基本表达式，即调用的左操作数。然后，每次看到`(`，我们就调用`finishCall()`解析调用表达式，并使用之前解析出的表达式作为被调用者。返回的表达式成为新的`expr`，我们循环检查其结果是否被调用。

解析参数列表的代码在下面的工具方法中：

> 在`Parser.java`文件中，在`unary()`方法后添加

```java
  private Expr finishCall(Expr callee) {
    List<Expr> arguments = new ArrayList<>();
    if (!check(RIGHT_PAREN)) {
      do {
        arguments.add(expression());
      } while (match(COMMA));
    }

    Token paren = consume(RIGHT_PAREN,
                          "Expect ')' after arguments.");

    return new Expr.Call(callee, paren, arguments);
  }
```

这或多或少是`arguments` 语法规则翻译成代码的结果，除了我们这里还处理了无参情况。我们首先判断下一个标记是否`)`来检查这种情况。如果是，我们就不会尝试解析任何参数。

如果不是，我们就解析一个表达式，然后寻找逗号（表明后面还有一个参数）。只要我们在表达式后面发现逗号，就会继续解析表达式。当我们找不到逗号时，说明参数列表已经结束，我们继续消费预期的右括号。最终，我们将被调用者和这些参数封装成一个函数调用的AST节点。

### $9.1.1$ 最大参数数量

现在，我们解析参数的循环是没有边界的。如果你想调用一个函数并向其传递一百万个参数，解析器不会有任何问题。我们要对此进行限制吗？

其它语言采用了不同的策略。C语言标准要求在符合标准的实现中，一个函数至少要支持127个参数，但是没有指定任何上限。Java规范规定一个方法可以接受不超过255个参数。

> 在`Parser.java`文件中，在`finishCall()`方法中添加

```java
      do {
        // 新增部分开始
        if (arguments.size() >= 255) {
          error(peek(), "Can't have more than 255 arguments.");
        }
        // 新增部分结束
        arguments.add(expression());
```

请注意，如果发现参数过多，这里的代码会*报告*一个错误，但是不会*抛出*该错误。抛出错误是进入恐慌模式的方法，如果解析器处于混乱状态，不知道自己在语法中处于什么位置，那这就是我们想要的。但是在这里，解析器仍然处于完全有效的状态，只是发现了太多的参数。所以它会报告这个错误，并继续执行解析。

### $9.1.2$ 解释函数调用

我们还没有任何可以调用的函数，所以先实现函数调用似乎有点奇怪，但是这个问题我们后面再考虑。首先，我们的解释器需要引入一个新依赖。

<u>lox/Interpreter.java</u>

```java
import java.util.ArrayList;
import java.util.List;
```

跟之前一样，解释工作从新的调用表达式节点对应的新的visit方法开始[^4]。

*<u>lox/Interpreter.java，在 visitBinaryExpr()方法后添加：</u>*

```java
  @Override
  public Object visitCallExpr(Expr.Call expr) {
    Object callee = evaluate(expr.callee);

    List<Object> arguments = new ArrayList<>();
    for (Expr argument : expr.arguments) { 
      arguments.add(evaluate(argument));
    }

    LoxCallable function = (LoxCallable)callee;
    return function.call(this, arguments);
  }
```

首先，对被调用者的表达式求值。通常情况下，这个表达式只是一个标识符，可以通过它的名字来查找函数。但它可以是任何东西。然后，我们依次对每个参数表达式求值，并将结果值存储在一个列表中。

一旦我们准备好被调用者和参数，剩下的就是执行函数调用。我们将被调用者转换为LoxCallable，然后对其调用`call()`方法来实现。任何可以像函数一样被调用的Lox对象的Java表示都要实现这个接口。这自然包括用户定义的函数，但也包括类对象，因为类会被 "调用 "来创建新的实例。稍后我们还将把它用于另一个目的。

这个新接口中没有太多内容。

> 创建新文件`AtguiguCallable.java`

```java
package com.atguigu;

import java.util.List;

public interface LoxCallable {
  Object call(Interpreter interpreter, List<Object> arguments);
}
```

我们会传入解释器，以防实现`call()`方法的类会需要它。我们也会提供已求值的参数值列表。接口实现者的任务就是返回调用表达式产生的值。

### $9.1.3$ 调用类型错误

Before we get to implementing LoxCallable, we need to make the visit method a little more robust. It currently ignores a couple of failure modes that we can’t pretend won’t occur. First, what happens if the callee isn’t actually something you can call? What if you try to do this:

```
"totally not a function"();
```

Strings aren’t callable in Lox. The runtime representation of a Lox string is a Java string, so when we cast that to LoxCallable, the JVM will throw a ClassCastException. We don’t want our interpreter to vomit out some nasty Java stack trace and die. Instead, we need to check the type ourselves first.

```
    }
```

*lox/Interpreter.java*
in *visitCallExpr*()

```
    if (!(callee instanceof LoxCallable)) {
      throw new RuntimeError(expr.paren,
          "Can only call functions and classes.");
    }
    LoxCallable function = (LoxCallable)callee;
```

We still throw an exception, but now we’re throwing our own exception type, one that the interpreter knows to catch and report gracefully.

### 10.1.4 检查元数

另一个问题与函数的**元数**有关。元数是一个花哨的术语，指一个函数或操作所期望的参数数量。一元运算符的元数是1，二元运算符是2，等等。对于函数来说，元数由函数声明的参数数量决定。

```java
fun add(a, b, c) {
  print a + b + c;
}
```

这个函数定义了三个形参，`a` 、`b` 和`c`，所以它的元数是3，而且它期望有3个参数。那么如果你用下面的方式调用该函数会怎样：

```java
add(1, 2, 3, 4); // Too many.
add(1, 2);       // Too few.
```

不同的语言对这个问题采用了不同的方法。当然，大多数静态类型的语言在编译时都会检查这个问题，如果实参与函数元数不匹配，则拒绝编译代码。JavaScript会丢弃你传递的所有多余参数。如果你没有传入的参数数量不足，它就会用神奇的与`null`类似但并不相同的值`undefined`来填补缺少的参数。Python更严格。如果参数列表太短或太长，它会引发一个运行时错误。

我认为后者是一种更好的方法。传递错误的参数数量几乎总是一个错误，这也是我在实践中确实犯的一个错误。有鉴于此，语言实现能越早引起用户的注意就越好。所以对于Lox，我们将采取Python的方法。在执行可调用方法之前，我们检查参数列表的长度是否与可调用方法的元数相符。

*<u>lox/Interpreter.java，在 visitCallExpr()方法中添加代码：</u>*

```java
    LoxCallable function = (LoxCallable)callee;
    // 新增部分开始
    if (arguments.size() != function.arity()) {
      throw new RuntimeError(expr.paren, "Expected " +
          function.arity() + " arguments but got " +
          arguments.size() + ".");
    }
    // 新增部分结束
    return function.call(this, arguments);
```

这就需要在`LoxCallable`接口中增加一个新方法来查询函数的元数。

> 在`AtguiguCallable.java`文件中，在`AtguiguCallable`接口中新增

```java
public interface LoxCallable {
  // 新增部分开始
  int arity();
  // 新增部分结束
  Object call(Interpreter interpreter, List<Object> arguments);
```

我们可以在`call()`方法的具体实现中做元数检查。但是，由于我们会有多个实现`AtguiguCallable`的类，这将导致冗余的验证分散在多个类中。把它提升到访问方法中，这样我们可以在一个地方完成该功能。

## $9.2$ 内置函数

理论上我们可以调用函数了，但是我们还没有可供调用的函数。在我们实现用户自定义函数之前，现在正好可以介绍语言实现中一个重要但经常被忽视的方面——**原生函数（本地函数）**。这些函数是解释器向用户代码公开的，但它们是用宿主语言(在我们的例子中是Java)实现的，而不是正在实现的语言(Lox)。

有时这些函数也被称为**原语**、**外部函数**或**外来函数**。由于这些函数可以在用户程序运行的时候被调用，因此它们构成了语言运行时的一部分。许多编程语言书籍都掩盖了这些内容，因为它们在概念上并不有趣。它们主要是一些比较繁重的工作。

但是说到让你的语言真正擅长做有用的事情，语言提供的本地函数是关键。本地函数提供了对基础服务的访问，所有的程序都是根据这些服务来定义的。如果你不提供访问文件系统的本地函数，那么用户在写一个读取和显示文件的程序时就会有很大的困难。

许多语言还允许用户提供自己的本地函数。这样的机制称为**外来函数接口(FFI)**、**本机扩展**、**本机接口**或类似的东西。这些机制很好，因为它们使语言实现者无需提供对底层平台所支持的每一项功能的访问。我们不会为 jlox 定义一个 FFI，但我们会添加一个本地函数，让你知道它是什么样子。

### 10.2.1 报时

当我们进入第三部分，开始着手开发更有效的Lox实现时，我们就会非常关心性能。性能需要测量，这也就意味着需要**基准测试**。这些代码就是用于测量解释器执行某些代码时所花费的时间。

我们可以测量启动解释器、运行基准测试代码并退出所消耗的时间，但是这其中包括很多时间开销——JVM启动时间，操作系统欺诈等等。当然，这些东西确实很重要，但如果您只是试图验证对解释器某个部分的优化，你肯定不希望这些多余的时间开销掩盖你的结果。

一个更好的解决方案是让基准脚本本身度量代码中两个点之间的时间间隔。要做到这一点，Lox程序需要能够报时。现在没有办法做到这一点——如果不访问计算机上的底层时钟，就无法从头实现一个可用的时钟。

所以我们要添加`clock()`，这是一个本地函数，用于返回自某个固定时间点以来所经过的秒数。两次连续调用之间的差值可用告诉你两次调用之间经过了多少时间。这个函数被定义在全局作用域内，以确保解释器能够访问这个函数。

*<u>lox/Interpreter.java，在 Interpreter类中，替换一行：</u>*

```java
class Interpreter implements Expr.Visitor<Object>,
                             Stmt.Visitor<Void> {
  // 替换部分开始                           
  final Environment globals = new Environment();
  private Environment environment = globals;
  // 替换部分结束
  void interpret(List<Stmt> statements) {
```

解释器中的`environment`字段会随着进入和退出局部作用域而改变，它会跟随当前环境。新加的`globals`字段则固定指向最外层的全局作用域。

当我们实例化一个解释器时，我们将全局作用域中添加本地函数。

*<u>lox/Interpreter.java，在 Interpreter类中新增：</u>*

```java
  private Environment environment = globals;
  // 新增部分开始
  Interpreter() {
    globals.define("clock", new LoxCallable() {
      @Override
      public int arity() { return 0; }

      @Override
      public Object call(Interpreter interpreter,
                         List<Object> arguments) {
        return (double)System.currentTimeMillis() / 1000.0;
      }

      @Override
      public String toString() { return "<native fn>"; }
    });
  }
  // 新增部分结束
  void interpret(List<Stmt> statements) {
```

这里有一个名为`clock`的变量，它的值是一个实现LoxCallable接口的Java匿名类。这里的`clock()`函数不接受参数，所以其元数为0。`call()`方法的实现是直接调用Java函数并将结果转换为以秒为单位的double值。

如果我们想要添加其它本地函数——读取用户输入，处理文件等等——我们可以依次为它们提供实现LoxCallable接口的匿名类。但是在本书中，这个函数足以满足需要。

让我们从函数定义的事务中解脱出来，由用户来接管吧。

## $9.3$ 函数声明

我们终于可以在添加变量时就引入的`declaration`规则中添加产生式了。就像变量一样，函数声明也会绑定一个新的名称。这意味中它们只能出现在允许声明的地方。

```
declaration    → funDecl
               | varDecl
               | statement ;
```

> The updated `declaration` rule references this new rule:

更新后的`declaration`引用了下面的新规则：

```
funDecl        → "fun" function ;
function       → IDENTIFIER "(" parameters? ")" block ;
```

主要的`funDecl`规则使用了一个单独的辅助规则`function`。函数*声明语句*是`fun`关键字后跟实际的函数体内容。等到我们实现类的时候，将会复用`function`规则来声明方法。这些方法与函数声明类似，但是前面没有`fun`。

函数本身是一个名称，后跟带括号的参数列表和函数体。函数体是一个带花括号的块，可以使用与块语句相同的语法。参数列表则使用以下规则：

```
parameters     → IDENTIFIER ( "," IDENTIFIER )* ;
```

这就类似于前面的`arguments` 规则，区别在于参数是一个标识符，而不是一个表达式。这对于解析器来说是很多要处理的新语法，但是生成的AST节点没这么复杂。

*<u>tool/GenerateAst.java，在 main()方法中添加：</u>*

```java
      "Expression : Expr expression",
      // 新增部分开始
      "Function   : Token name, List<Token> params," +
                  " List<Stmt> body",
      // 新增部分结束           
      "If         : Expr condition, Stmt thenBranch," +
```

函数节点有一个名称、一个参数列表(参数的名称)，然后是函数主体。我们将函数主体存储为包含在花括号中的语句列表。

在解析器中，我们把新的声明添加进去。

> 在`Parser.java`文件中，在`declaration()`方法中添加

```java
    try {
      // 新增部分开始
      if (match(FUN)) return function("function");
      // 新增部分结束
      if (match(VAR)) return varDeclaration();
```

像其它语句一样，函数是通过前面的关键字来识别的。当我们遇到`fun`时，我们就调用`function`。这步操作对应于`function`语法规则，因为我们已经匹配并消费了`fun`关键字。我们会一步步构建这个方法，首先从下面的代码开始：

*<u>lox/Parser.java，在 expressionStatement()方法后添加：</u>*

```java
  private Stmt.Function function(String kind) {
    Token name = consume(IDENTIFIER, "Expect " + kind + " name.");
  }
```

现在，它只是消费了标识符标记作为函数名称。你可能会对这里的`kind`参数感到疑惑。就像我们复用语法规则一样，稍后我们也会复用`function()`方法来解析类中的方法。到时候，我们会在`kind`参数中传入 "method"，这样错误信息就会针对被解析的声明类型来展示。

接下来，我们要解析参数列表和包裹着它们的一对小括号。

*<u>lox/Parser.java，在 function()方法中添加：</u>*

```java
    Token name = consume(IDENTIFIER, "Expect " + kind + " name.");
    // 新增部分开始
    consume(LEFT_PAREN, "Expect '(' after " + kind + " name.");
    List<Token> parameters = new ArrayList<>();
    if (!check(RIGHT_PAREN)) {
      do {
        if (parameters.size() >= 255) {
          error(peek(), "Can't have more than 255 parameters.");
        }

        parameters.add(
            consume(IDENTIFIER, "Expect parameter name."));
      } while (match(COMMA));
    }
    consume(RIGHT_PAREN, "Expect ')' after parameters.");
    // 新增部分结束
  }
```

这就像在函数调用中处理参数的代码一样，只是没有拆分到一个辅助方法中。外部的`if`语句用于处理零参数的情况，内部的`while`会循环解析参数，只要能找到分隔参数的逗号。其结果是包含每个参数名称的标记列表。

就像我们处理函数调用的参数一样，我们在解析时验证是否超过了一个函数所允许的最大参数数。

最后，我们解析函数主体，并将其封装为一个函数节点。

*<u>lox/Parser.java，在 function()方法中添加：</u>*

```java
    consume(RIGHT_PAREN, "Expect ')' after parameters.");
    // 新增部分开始
    consume(LEFT_BRACE, "Expect '{' before " + kind + " body.");
    List<Stmt> body = block();
    return new Stmt.Function(name, parameters, body);
    // 新增部分结束
  }
```

请注意，在调用`block()`方法之前，我们已经消费了函数体开头的`{`。这是因为`block()`方法假定大括号标记已经匹配了。在这里消费该标记可以让我们在找不到`{`的情况下报告一个更精确的错误信息，因为我们知道当前是在一个函数声明的上下文中。

## $9.4$ 函数对象

我们已经解析了一些语法，通常我们要开始准备解释了，但是我们首先需要思考一下，在$Java$中如何表示一个$Atguigu$函数。我们需要跟踪形参，以便在函数被调用时可以将形参与实参值进行绑定。当然，我们也要保留函数体的代码，以便我们可以执行它。

这基本上就是`Function`的内容。我们可以用这个吗？差不多，但还不够。我们还需要一个实现`AtguiguCallable`的类，以便我们可以调用它。我们不希望解释器的运行时阶段渗入到前端语法类中，所以我们不希望使用`Function`本身来实现它。相反，我们将它包装在一个新类中。

> 创建新文件`AtguiguFunction.java`

```java
package com.atguigu;

import java.util.List;

public class AtguiguFunction implements AtguiguCallable {
  private final Function declaration;
  public AtguiguFunction(Function declaration) {
    this.declaration = declaration;
  }
}
```

使用如下方式实现LoxCallable的`call()`方法：

*<u>lox/LoxFunction.java，在 LoxFunction()方法后添加：</u>*

```java
  @Override
  public Object call(Interpreter interpreter,
                     List<Object> arguments) {
    Environment environment = new Environment(interpreter.globals);
    for (int i = 0; i < declaration.params.size(); i++) {
      environment.define(declaration.params.get(i).lexeme,
          arguments.get(i));
    }

    interpreter.executeBlock(declaration.body, environment);
    return null;
  }
```

这几行代码是我们的解释器中最基本、最强大的部分之一。正如我们在上一章中所看到的，管理名称环境是语言实现中的核心部分。函数与此紧密相关。

参数是函数的核心，尤其是考虑到函数*封装*了其参数——函数之外的代码看不到这些参数。这意味着每个函数都会维护自己的环境，其中存储着那些变量。

此外，这个环境必须是动态创建的。每次函数*调用*都会获得自己的环境，否则，递归就会中断。如果在同一时刻对相同的函数有多次调用，那么每个调用都需要自身的环境，即便它们都是对相同函数的调用。

举例来说，下面是一个计数到3的复杂方法：

```js
fun count(n) {
  if (n > 1) count(n - 1);
  print n;
}

count(3);
```

假设一下，如果我们在最内层的嵌套调用中即将打印1的时候暂停了解释器。打印2和3的外部调用还没有打印出它们的值，所以在内存的某个地方一定有环境仍然存储着这样的数据：n在一个上下文中被绑定到3，在另一个上下文中被绑定到2，而在最内层调用中绑定为1，比如：

![A separate environment for each recursive call.](10.函数/recursion.png)

这就是为什么我们在每次*调用*时创建一个新的环境，而不是在函数声明时创建。我们前面看到的`call()`方法就是这样做的。在调用开始的时候，它创建了一个新环境。然后它以同步的方式遍历形参和实参列表。对于每一对参数，它用形参的名字创建一个新的变量，并将其与实参的值绑定。

所以，对于类似下面这样的代码：

```java
fun add(a, b, c) {
  print a + b + c;
}

add(1, 2, 3);
```

在调用`add()`时，解释器会创建类似下面这样的内容：

![Binding arguments to their parameters.](10.函数/binding.png)

然后`call()`会告诉解释器在这个新的函数局部环境中执行函数体。在此之前，当前环境是函数被调用的位置所处的环境。现在，我们转入了为函数创建的新的参数空间中。

这就是将数据传入函数所需的全部内容。通过在执行函数主体时使用不同的环境，用同样的代码调用相同的函数可以产生不同的结果。

一旦函数的主体执行完毕，`executeBlock()`就会丢弃该函数的本地环境，并恢复调用该函数前的活跃环境。最后，`call()`方法会返回`null`，它向调用者返回`nil`。（我们会在稍后添加返回值）

从机制上讲，这段代码是非常简单的。遍历几个列表，绑定一些新变量，调用一个方法。但这就是将代码块变成有生命力的调用执行的地方。这是我在整本书中最喜欢的片段之一。如果你愿意的话，可以花点时间好好思考一下。

完成了吗？好的。注意当我们绑定参数时，我们假设参数和参数列表具有相同的长度。这是安全的，因为`visitCallExpr()`在调用`call()`之前会检查元数。它依靠报告其元数的函数来做到这一点。

*<u>lox/LoxFunction.java，在 LoxFunction()方法后添加：</u>*

```java
  @Override
  public int arity() {
    return declaration.params.size();
  }
```

这基本就是我们的函数对象表示了。既然已经到了这一步，我们也可以实现toString()。

*<u>lox/LoxFunction.java，在 LoxFunction()方法后添加：</u>*

```java
  @Override
  public String toString() {
    return "<fn " + declaration.name.lexeme + ">";
  }
```

如果用户要打印函数的值，该方法能提供一个更漂亮的输出值。

```javascript
fun add(a, b) {
  print a + b;
}

print add; // "<fn add>".
```

### 10.4.1 解释函数声明

我们很快就会回头来完善LoxFunction，但是现在已足够开始进行解释了。现在，我们可以访问函数声明节点了。

*<u>lox/Interpreter.java，在 visitExpressionStmt()方法后添加：</u>*

```java
  @Override
  public Void visitFunctionStmt(Stmt.Function stmt) {
    LoxFunction function = new LoxFunction(stmt);
    environment.define(stmt.name.lexeme, function);
    return null;
  }
```

这类似于我们介绍其它文本表达式的方式。我们会接收一个函数*语法*节点——函数的编译时表示形式——然后将其转换为运行时表示形式。在这里就是一个封装了语法节点的LoxFunction实例。

函数声明与其它文本节点的不同之处在于，声明还会将结果对象绑定到一个新的变量。因此，在创建LoxFunction之后，我们在当前环境中创建一个新的绑定，并在其中保存对该函数的引用。

这样，我们就可以在Lox中定义和调用我们自己的函数。试一下：

```javascript
fun sayHi(first, last) {
  print "Hi, " + first + " " + last + "!";
}

sayHi("Dear", "Reader");
```

我不知道你怎么想的，但对我来说，这看起来像是一种虔诚的编程语言。

## $9.5$ $return$语句

我们可以通过传递参数将数据输入函数中，但是我们没有办法将结果 **传出来** 。所以我们需要`return`语句。

```
statement      → exprStmt
               | forStmt
               | ifStmt
               | printStmt
               | returnStmt
               | whileStmt
               | block ;

returnStmt     → "return" expression? ";" ;
```

我们又得到一个`statement`规则下的新产生式（实际上也是最后一个）。一个`return`语句就是一个`return`关键字，后跟一个可选的表达式，并以一个分号结尾。

返回值是可选的，用以支持从一个不返回有效值的函数中提前退出。在静态类型语言中，void函数不返回值，而非void函数返回值。由于Lox是动态类型的，所以没有真正的void函数。在调用一个不包含`return`语句的函数时，编译器没有办法阻止你获取其结果值。

```javascript
fun procedure() {
  print("don't return anything");
}

var result = procedure();
print(result); // ?
```

这意味着每个Lox函数都要返回一些内容，即使其中根本不包含`return`语句。我们使用`nil`，这就是为什么LoxFunction的`call()`实现在最后返回`null`。同样，如果你省略了`return `语句中的值，我们将其视为等价于：

```java
return nil;
```

在AST生成器中，添加一个新节点。

*<u>tool/GenerateAst.java，在 main()方法中添加：</u>*

```java
      "Print      : Expr expression",
      // 新增部分开始
      "Return     : Token keyword, Expr value",
      // 新增部分结束
      "Var        : Token name, Expr initializer",
```

其中保留了`return`关键字标记（这样我们可以使用该标记的位置来报告错误），以及返回的值（如果有的话）。我们像解析其它语句一样来解析它，首先识别起始的关键字。

*<u>lox/Parser.java，在 statement()方法中添加：</u>*

```java
    if (match(PRINT)) return printStatement();
    // 新增部分开始
    if (match(RETURN)) return returnStatement();
    // 新增部分结束
    if (match(WHILE)) return whileStatement();
```

分支会跳转到：

*<u>lox/Parser.java，在 printStatement()方法后添加：</u>*

```java
  private Stmt returnStatement() {
    Token keyword = previous();
    Expr value = null;
    if (!check(SEMICOLON)) {
      value = expression();
    }

    consume(SEMICOLON, "Expect ';' after return value.");
    return new Stmt.Return(keyword, value);
  }
```

在捕获先前消耗的`return`关键字之后，我们会寻找一个值表达式。因为很多不同的标记都可以引出一个表达式，所以很难判断是否存在返回值。相反，我们检查它是否不存在。因为分号不能作为表达式的开始，如果下一个标记是分号，我们就知道一定没有返回值。

### $9.5.1$ 从函数调用中返回

解释`return`语句是很棘手的。你可以从函数体中的任何位置返回，甚至是深深嵌套在其它语句中的位置。当返回语句被执行时，解释器需要完全跳出当前所在的上下文，完成函数调用，就像某种顶层的控制流结构。

举例来说，假设我们正在运行下面的代码，并且我们即将执行`return`语句：

```java
fun count(n) {
  while (n < 100) {
    if (n == 3) return n; // <--
    print n;
    n = n + 1;
  }
}

count(1);
```

Java调用栈目前看起来大致如下所示：

```java
Interpreter.visitReturnStmt()
Interpreter.visitIfStmt()
Interpreter.executeBlock()
Interpreter.visitBlockStmt()
Interpreter.visitWhileStmt()
Interpreter.executeBlock()
LoxFunction.call()
Interpreter.visitCallExpr()
```

我们需要从栈顶一直回退到`call()`。我不知道你怎么想，但是对我来说，这听起来很像是异常。当我们执行`return`语句时，我们会使用一个异常来解开解释器，经过所有函数内含语句的visit方法，一直回退到开始执行函数体的代码。

新的AST节点的visit方法如下所示：

*<u>lox/Interpreter.java，在 visitPrintStmt()方法后添加：</u>*

```java
  @Override
  public Void visitReturnStmt(Stmt.Return stmt) {
    Object value = null;
    if (stmt.value != null) value = evaluate(stmt.value);

    throw new Return(value);
  }
```

如果我们有返回值，就对其求值，否则就使用`nil`。然后我们取这个值并将其封装在一个自定义的异常类中，并抛出该异常。

*<u>lox/Return.java，创建新文件：</u>*

```java
package com.craftinginterpreters.lox;

class Return extends RuntimeException {
  final Object value;

  Return(Object value) {
    super(null, null, false, false);
    this.value = value;
  }
}
```

这个类使用Java运行时异常类来封装返回值。其中那个奇怪的带有`null`和`false`的父类构造器方法，禁用了一些我们不需要的JVM机制。因为我们只是使用该异常类来控制流，而不是真正的错误处理，所以我们不需要像堆栈跟踪这样的开销。

我们希望可以一直跳出到函数调用开始的地方，也就是LoxFunction中的`call()`方法。

*<u>lox/LoxFunction.java，在 call()方法中替换一行：</u>*

```java
         arguments.get(i));
    }
    // 替换部分开始
    try {
      interpreter.executeBlock(declaration.body, environment);
    } catch (Return returnValue) {
      return returnValue.value;
    }
    // 替换部分结束
    return null;
```

我们将对`executeBlock()`的调用封装在一个try-catch块中。当捕获一个返回异常时，它会取出其中的值并将其作为`call()`方法的返回值。如果没有捕获任何异常，意味着函数到达了函数体的末尾，而且没有遇到`return`语句。在这种情况下，隐式地返回`nil`。

我们来试一下。我们终于有能力支持这个经典的例子——递归函数计算Fibonacci数：

```java
fun fib(n) {
  if (n <= 1) return n;
  return fib(n - 2) + fib(n - 1);
}

for (var i = 0; i < 20; i = i + 1) {
  print fib(i);
}
```

这个小程序练习了我们在过去几章中实现的几乎所有语言特性，包括表达式、算术运算、分支、循环、变量、函数、函数调用、参数绑定和返回。

## $9.6$ 局部函数和闭包

我们的函数功能已经相当全面了，但是还有一个漏洞需要修补。实际上，这是一个很大的问题，我们将会在下一章中花费大部分时间来修补它，但是我们可以从这里开始。

LoxFunction中的`call()`实现创建了一个新的环境，并在其中绑定了函数的参数。当我向你展示这段代码时，我忽略了一个重要的问题：这个环境的父类是什么？

目前，它始终是`globals`，即顶级的全局环境。这样，如果一个标识符不是在函数体内部定义的，解释器可以在函数外部的全局作用域中查找它。在Fibonacci的例子中，这就是解释器如何能够在函数体中实现对`fib`的递归调用——`fib`是一个全局变量。

但请记住，在Lox中，允许在可以绑定名字的*任何地方*进行函数声明。其中包括Lox脚本的顶层，但也包括块或其他函数的内部。Lox支持在另一个函数内定义或在一个块内嵌套的**局部函数**。

考虑下面这个经典的例子：

```java
fun makeCounter() {
  var i = 0;
  fun count() {
    i = i + 1;
    print i;
  }

  return count;
}

var counter = makeCounter();
counter(); // "1".
counter(); // "2".
```

这个例子中，`count()`使用了`i`，它是在该函数外部的 `makeCounter()`声明的。`makeCounter()` 返回对`count()`函数的引用，然后它的函数体就执行完成了。

同时，顶层代码调用了返回的`count()`函数。这就执行了`count()`函数的主体，它会对`i`赋值并读取`i`，尽管定义`i`的函数已经退出。

如果你以前从未遇到过带有嵌套函数的语言，那么这可能看起来很疯狂，但用户确实希望它能工作。唉，如果你现在运行它，当`count()`的函数体试图查找`i`时，会在对`counter()`的调用中得到一个未定义的变量错误，这是因为当前的环境链看起来像是这样的：

![The environment chain from count()'s body to the global scope.](10.函数/global.png)

当我们调用`count()`时（通过`counter`中保存的引用），我们会为函数体创建一个新的空环境，它的父环境就是全局环境。我们丢失了`i`所在的`makeCounter()`环境。

我们把时间往回拨一点。我们在`makeCounter()`的函数体中声明`count()`时，环境链的样子是下面这样：

![The environment chain inside the body of makeCounter().](10.函数/body.png)

所以，在函数声明的地方，我们可以看到`i`。但是当我们从 `makeCounter()` 返回并退出其主体时，解释器会丢弃这个环境。因为解释器不会保留`count()` 外围的环境，所以要靠函数对象本身来保存它。

这种数据结构被称为**闭包**，因为它 "封闭 "并保留着函数声明的外围变量。闭包早在Lisp时代就已经存在了，语言黑客们想出了各种方法来实现闭包。在jlox中，我们将采用最简单的方式。在LoxFunction中，我们添加一个字段来存储环境。

*<u>lox/LoxFunction.java，在 LoxFunction类中添加：</u>*

```java
  private final Stmt.Function declaration;
  // 新增部分开始
  private final Environment closure;
  // 新增部分结束
  LoxFunction(Stmt.Function declaration) {
```

我们在构造函数中对其初始化。

*<u>lox/LoxFunction.java，在 LoxFunction()构造方法中替换一行：</u>*

```java
  //替换部分开始
  LoxFunction(Stmt.Function declaration, Environment closure) {
    this.closure = closure;
    // 替换部分结束
    this.declaration = declaration;
```

当我们创建LoxFunction时，我们会捕获当前环境。

*<u>lox/Interpreter.java，在 visitFunctionStmt()方法中替换一行：</u>*

```java
    public Void visitFunctionStmt(Stmt.Function stmt) {
      // 替换部分开始
      LoxFunction function = new LoxFunction(stmt, environment);
      // 替换部分结束
      environment.define(stmt.name.lexeme, function);
```

这是函数声明时生效的环境，而不是函数被调用时的环境，这正是我们想要的。它代表了函数声明时的词法作用域。最后，当我们调用函数时，我们使用该环境作为调用的父环境，而不是直接使用`globals`。

*<u>lox/LoxFunction.java，在 call()方法中替换一行：</u>*

```java
                      List<Object> arguments) {
    // 替换部分开始                  
    Environment environment = new Environment(closure);
    // 替换部分结束
    for (int i = 0; i < declaration.params.size(); i++) {
```

这样就创建了一个环境链，从函数体开始，经过函数被声明的环境，然后到全局作用域。运行时环境链与源代码的文本嵌套相匹配，跟我们想要的一致。当我们调用该函数时，最终的结果是这样的：

![The environment chain with the closure.](10.函数/closure.png)

如你所见，现在解释器可以在需要的时候找到`i`，因为它在环境链中。现在尝试运行makeCounter()的例子，起作用了！ 

函数让我们对代码进行抽象、重用和编排。Lox比之前的初级算术计算器要强大得多。唉，在我们匆匆忙忙支持闭包时，已经让一小部分动态作用域泄露到解释器中了。在下一章中，我们将深入探索词法作用域，堵住这个漏洞。

# $10$ 解析和绑定

你也许偶尔会发现自己处于一种奇怪的情况。你曾以最自然的方式逐渐进入其中，但当你身处其中时，你会突然感到惊讶，并问自己这一切到底是怎么发生的。

哦，不! 我们的语言实现正在进水! 在我们刚添加变量和代码块时，我们把作用域控制的很好很严密。但是当我们后来添加闭包之后，我们以前防水的解释器上就出现了一个洞。大多数真正的程序都不可能从这个洞里溜走，但是作为语言实现者，我们要立下神圣的誓言，即使在语义的最深处、最潮湿的角落里也要关心正确性。【译者注：这一段好中二，其实原文中有很多地方都有类似的中二之魂燃烧瞬间】

我们将用整整一章的时间来探索这个漏洞，然后小心翼翼地把它补上。在这个过程中，我们将对Lox和其他C语言传统中使用的词法范围有一个更严格的理解。我们还将有机会学习语义分析——这是一种强大的技术，用于从用户的源代码中提取语义而无需运行它。

## $10.1$ 静态作用域

快速复习一下：Lox和大多数现代语言一样，使用词法作用域。这意味着你可以通过阅读代码文本找到变量名字指向的是哪个声明。例如：

```java
var a = "outer";
{
  var a = "inner";
  print a;
}
```

这里，我们知道打印的`a`是上一行声明的变量，而不是全局变量。运行代码并不会（也不能）影响这一点。作用域规则是语言的静态语义的一部分，这也就是为什么它们被称为静态作用域。

我还没有详细说明这些作用域规则，但是现在是时候详细说明一下了：

**变量指向的是使用变量的表达式外围环境中，前面具有相同名称的最内层作用域中的变量声明。**

其中有很多东西需要解读：

- 我说的是“变量使用”而不是“变量表达式”，是为了涵盖变量表达式和赋值两种情况。类似于“使用变量的表达式”。

- “前面”意味着出现在*程序文本*之前。

  ```java
  var a = "outer";
  {
    print a;
    var a = "inner";
  }
  ```

  这里，打印的`a`是外层的，因为它在使用该变量的`print`语句之前。在大多数情况下，在单行代码中，文本中靠前的变量声明在时间上也先于变量使用。但并不总是如此。正如我们将看到的，函数可以推迟代码块，以使其动态执行的时间不受静态文本顺序的约束。

- “最内层”是因为我们的好朋友——变量遮蔽。在外围作用域中可能存在多个具有给定名称的变量。如：
  
  ```java
  var a = "outer";
  {
    var a = "inner";
    print a;
  }
  ```
  
  我们的规则规则最内层作用域优先级最高来消除这种歧义。

由于这条规则没有提及任何运行时行为，它意味着一个变量表达式在程序的整个执行过程中总是指向同一声明。到目前为止，我们的解释器基本正确实现了这一规则。但是当我们添加了闭包后，一个错误悄悄出现了。

```java
var a = "global";
{
  fun showA() {
    print a;
  }

  showA();
  var a = "block";
  showA();
}
```

在你执行这段代码之前，先思考一下它*应该*输出什么[^3]。

好的……清楚了吗？如果你熟悉其它语言中的闭包，你们你可能期望会输出两次“global”。对 `showA() `的第一次调用肯定会打印 “global”，因为我们甚至还没有执行到内部变量 `a` 的声明。而根据我们的规则，一个变量表达式总数解析为同一个变量，这意味着对 `showA() `的第二次调用也应该打印出同样的内容。

唉，它输出的是：

```
global
block
```

我要强调一下，这个代码中从未重新分配任何变量，并且只包含一个`print`语句。然而，不知何故，对于这个从未分配过的变量，`print`语句在不同的时间点上打印了两个不同的值。我们肯定在什么地方出了问题。

### $10.1.1$ 作用域和可变环境

在我们的解释器中，环境是静态作用域的动态表现。这两者大多情况下保持同步——当我们进入一个新的作用域时，我们会创建一个新的环境，当我们离开这个作用域时，我们会丢弃它。在环境中还有一个可执行的操作：在环境中绑定一个变量。这就是我们的问题所在。

让我们通过这个有问题的例子，看看每一步的环境是什么样的。首先，我们在全局作用域内声明`a`。

![The global environment with 'a' defined in it.](11.解析和绑定/environment-1.png)

这为我们提供了一个环境，其中只有一个变量。然后我们进入代码块，并执行`showA()`的声明。

![A block environment linking to the global one.](11.解析和绑定/environment-2.png)

我们得到一个对应该代码块的新环境。在这个环境中，我们声明了一个名称`showA`，它绑定到为表示函数而创建的LoxFunction对象。该对象中有一个`closure`字段，用于捕获函数声明时的环境，因此它有一个指向该代码块环境的引用。

现在我们调用`showA()`。

![An empty environment for showA()'s body linking to the previous two. 'a' is resolved in the global environment.](11.解析和绑定/environment-3.png)

解释器为showA()的函数体动态地创建了一个新环境。它是空的，因为该函数没有声明任何变量。该环境的父环境是该函数的闭包——外部的代码块环境。

在`showA()`函数体中，输出`a`的值。解释器通过遍历环境链来查找这个值。它会一直到达全局环境，在其中找到变量`a`并打印“global”。太好了。

接下来，我们声明第二个`a`，这次是在代码块内。

![The block environment has both 'a' and 'showA' now.](11.解析和绑定/environment-4.png)

它和`showA()`在同一个代码块中——同一个作用域，所以它进入了同一个环境，也就是`showA()`的闭包所指向的环境。这就是有趣的地方了。我们再次调用`showA()`。

![An empty environment for showA()'s body linking to the previous two. 'a' is resolved in the block environment.](11.解析和绑定/environment-5.png)

我们再次为`showA()`的函数体创建了一个新的空环境，将其连接到该闭包，并运行函数体。当解释器遍历环境链去查找`a`时，它会发现代码块环境中新的变量`a`。

我选择了一种实现环境的方式，希望它能够与您对作用域的非正式直觉相一致。我们倾向于认为一个块中的所有代码在同一个作用域中，所以我们的解释器使用了一个环境来表示它。每个环境都是一个可变的hash表。当一个新的局部变量被声明时，它会被加入该作用域的现有环境中。

就像生活中的很多直觉一样，这种直觉并不完全正确。一个代码块并不一定都是同一个作用域。考虑一下：

```javascript
{
  var a;
  // 1.
  var b;
  // 2.
}
```

在标记的第一行，作用域中只有`a`。在第二行时，`a`和`b`都在其中。如果将作用域定义为一组声明，那么它们显然不是相同的作用域——它们不包含相同的声明。这就好像是`var`语句将代码块分割成了两个独立的作用域，变量声明前的作用域和包含新变量的作用域[^4]。

但是在我们的实现中，环境确实表现得像整个代码块是一个作用域，只是这个作用域会随时间变化。而闭包不是这样的。当函数被声明时，它会捕获一个指向当前环境的引用。函数*应该*捕获一个冻结的环境快照，就像它存在于函数被声明的那一瞬间。但是事实上，在Java代码中，它引用的是一个实际可变的环境对象。当后续在该环境所对应的作用域内声明一个变量时，闭包会看到该变量，即使变量声明*没有*出现在函数之前。

### 11.1.2 持久环境

有一种编程风格，使用所谓的**持久性数据结构**。与你在命令式编程中所熟悉的模糊的数据结构不同，持久化数据结构永远不能被直接修改。相应地，对现有结构的任何 "修改 "都会产生一个全新的对象，其中包含所有的原始数据和新的修改。而原有的对象则保持不变。

如果我们将这一技术应用于环境，那么每次你声明一个变量时，都会返回一个新的环境，其中包含所有先前声明的变量和一个新名称。声明一个变量会执行隐式分割，在声明变量之前与之后都有一个环境：

![Separate environments before and after the variable is declared.](http://craftinginterpreters.com/image/resolving-and-binding/split.png)

当函数被声明时，闭包保留对正在运行的Environment实例的引用。由于该代码块中后续的任何声明都会生成新的Environment对象，闭包就不会看到新的变量，我们的问题也得到修复。

这是解决该问题的合法方式，也是在Scheme解释器中实现变量环境的经典方式。对于Lox，我们可以这样做，但是这意味着要回头修改一大堆现有的代码。

我不会把你拖下水的。我们将保持表示环境的方式不变。我们不会让数据变得更加静态结构化，而是将静态解析嵌入访问操作本身。

## $10.2$ 语义分析

我们的解释器每次对变量表达式求值时，都会**解析**变量——追踪它所指向的声明。如果这个变量被包在一个运行1000次的循环中，那么该变量就会被重复解析1000次。

我们知道静态作用域意味着一个变量的使用总是解析到同一个声明，而且可以通过查看文本来确定。既然如此，我们为什么每次都要动态地解析呢？这样做不仅仅导致了这个恼人的bug，而且也造成了不必要的低效。

一个更好的解决方案是一次性解析每个变量的使用。编写一段代码，检查用户的程序，找到所提到的每个变量，并找出每个变量引用的是哪个声明。这个过程是**语义分析**的一个例子。解析器只告诉程序在语法上是否正确(语法分析)，而语义分析则更进一步，开始弄清楚程序的各个部分的实际含义。在这种情况下，我们的分析将解决变量绑定的问题。我们不仅要知道一个表达式是一个变量，还要知道它是哪个变量。

有很多方法可以存储变量及其声明直接的绑定关系。当我们使用Lox的C解释器时，我们将有一种更有效的方式来存储和访问局部变量。但是对于jlox来说，我想尽量减少对现有代码库的附带损害。我不希望扔掉一堆基本上都很好的代码。

相对地，我们将以最充分利用现有Environment类的方式来存储解析结果。回想一下，在有问题的例子中，`a`的访问是如何被解释的。

![An empty environment for showA()'s body linking to the previous two. 'a' is resolved in the global environment.](http://craftinginterpreters.com/image/resolving-and-binding/environment-3.png)

在第一次（正确的）求值中，我们会检查链中的环境，并找到`a`的全局声明。然后，当内部的`a`在块作用域中声明时，它会遮蔽全局的变量`a`。

![An empty environment for showA()'s body linking to the previous two. 'a' is resolved in the block environment.](http://craftinginterpreters.com/image/resolving-and-binding/environment-5.png)

下一次查找会遍历环境链，在第二个环境中找到`a`并停止。每个环境都对应于一个声明变量的词法作用域。如果我们能够保证变量查找总是在环境链上遍历相同数量的链接，也就可以保证每次都可以在相同的作用域中找到相同的变量。

要“解析”一个变量使用，我们只需要计算声明的变量在环境链中有多少“跳”。有趣的问题是在什么时候进行这个计算——或者换句话说，在解释器的实现中，这段代码要添加到什么地方？

因为我们是根据源代码的结构来计算一个静态属性，所以答案显然是在解析器中。那是传统的选择，也是我们以后在 clox 中实现它的地方。在这里同样也适用，但是我想给你展示另一种技巧。我们会单独写一个解析器。

### 11.2.1 变量解析过程

在解析器生成语法树之后，解释器执行语法树之前，我们会对语法树再进行一次遍历，以解析其中包含的变量。在解析和执行之间的额外遍历是很常见的。如果Lox中有静态类型，我们可以插入一个类型检查器。优化也经常是在类似单独的遍历过程中实现的。基本上，任何不依赖与运行时状态的工作都可以通过这种方式完成。

我们的变量解析工作就像一个小型的解释器。它会遍历整棵树，访问每个节点，但是静态分析与动态执行还是不同的：

- **没有副作用**。当静态分析处理一个`print`语句时，它并不会打印任何东西。对本地函数或其它与外部世界联系的操作也会被终止，并且没有任何影响。

- **没有控制流**。循环只会被处理一次，`if`语句中的两个分支都会处理，逻辑操作符也不会做短路处理[^6]。

## 11.3 Resolver类

与$Java$中的所有内容一样，我们将变量解析处理也放在一个类中。

> 创建新文件`Resolver.java`

```java
package com.atguigu;

import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Stack;

public class Resolver implements Expr.Visitor<Void>, Stmt.Visitor<Void> {
  private final Interpreter interpreter;

  public Resolver(Interpreter interpreter) {
    this.interpreter = interpreter;
  }
}
```

因为解析器需要处理语法树中的每个节点，所以它实现了我们已有的访问者抽象。在解析变量时，有几个节点是比较特殊的：

- 块语句为它所包含的语句引入了一个新的作用域。

- 函数声明为其函数体引入了一个新的作用域，并在该作用域中绑定了它的形参。

- 变量声明将一个新变量加入到当前作用域中。

- 变量定义和赋值表达式需要解析它们的变量值。

其余的节点不做任何特别的事情，但是我们仍然需要为它们实现visit方法，以遍历其子树。尽管`+`表达式本身没有任何变量需要解析，但是它的任一操作数都可能需要。

### 11.3.1 解析代码块

我们从块语法开始，因为它们创建了局部作用域——魔法出现的地方。

*<u>lox/Resolver.java，在 Resolver()方法后添加：</u>*

```java
  @Override
  public Void visitBlockStmt(Stmt.Block stmt) {
    beginScope();
    resolve(stmt.statements);
    endScope();
    return null;
  }
```

这里会开始一个新的作用域，遍历块中的语句，然后丢弃该作用域。有趣的部分都在这些辅助方法中。我们先看一个简单的。

*<u>lox/Resolver.java，在 Resolver()方法后添加：</u>*

```java
  void resolve(List<Stmt> statements) {
    for (Stmt statement : statements) {
      resolve(statement);
    }
  }
```

它会遍历语句列表，并解析其中每一条语句。它会进一步调用：

*<u>lox/Resolver.java，在 visitBlockStmt()方法后添加：</u>*

```java
  private void resolve(Stmt stmt) {
    stmt.accept(this);
  }
```

在此过程中，让我们添加一个后续解析表达式时会用到的重载方法。

*<u>lox/Resolver.java，在 resolve(Stmt stmt)方法后添加：</u>*

```java
  private void resolve(Expr expr) {
    expr.accept(this);
  }
```

这些方法与解释器中的 `evaluate()`和`execute()`方法类似——它们会反过来将访问者模式应用到语法树节点。

真正有趣的部分是围绕作用域的。一个新的块作用域是这样创建的：

*<u>lox/Resolver.java，在 resolve()方法后添加：</u>*

```java
  private void beginScope() {
    scopes.push(new HashMap<String, Boolean>());
  }
```

词法作用域在解释器和解析器中都有使用。它们的行为像一个栈。解释器是使用链表（Environment对象组成的链）来实现栈的，在解析器中，我们使用一个真正的Java Stack。

*<u>lox/Resolver.java，在 Resolver类中添加：</u>*

```java
  private final Interpreter interpreter;
  // 新增部分开始
  private final Stack<Map<String, Boolean>> scopes = new Stack<>();
  // 新增部分结束
  Resolver(Interpreter interpreter) {
```

这个字段会记录当前作用域内的栈。栈中的每个元素是代表一个块作用域的Map。与Environment中一样，键是变量名。值是布尔值，原因我很快会解释。

作用域栈只用于局部块作用域。解析器不会跟踪在全局作用域的顶层声明的变量，因为它们在Lox中是更动态的。当解析一个变量时，如果我们在本地作用域栈中找不到它，我们就认为它一定是全局的。

由于作用域被存储在一个显式的栈中，退出作用域很简单。

<u>*lox/Resolver.java，在 beginScope()方法后添加：*</u>

```java
  private void endScope() {
    scopes.pop();
  }
```

现在我们可以在一个栈中压入和弹出一个空作用域，接下来我们往里面放些内容。

### 11.3.2 解析变量声明

解析一个变量声明，会在当前最内层的作用域map中添加一个新的条目。这看起来很简单，但是我们需要做一些小动作。

*<u>lox/Resolver.java，在 visitBlockStmt()方法后添加：</u>*

```java
  @Override
  public Void visitVarStmt(Stmt.Var stmt) {
    declare(stmt.name);
    if (stmt.initializer != null) {
      resolve(stmt.initializer);
    }
    define(stmt.name);
    return null;
  }
```

我们将绑定分为两个步骤，先声明，然后定义，以便处理类似下面这样的边界情况：

```javascript
var a = "outer";
{
  var a = a;
}
```

当局部变量的初始化式指向一个与当前声明变量名称相同的变量时，会发生什么？我们有几个选择：

1. **运行初始化式，然后将新的变量放入作用域中**。在这个例子中，新的局部变量`a`会使用“outer”（全局变量`a`的值）初始化。换句话说，前面的声明脱糖后如下：

   ```javascript
   var temp = a; // Run the initializer.
   var a;        // Declare the variable.
   a = temp;     // Initialize it.
   ```

2. **将新的变量放入作用域中，然后运行初始化式。**这意味着你可以在变量被初始化之前观察到它，所以我们需要计算出它的值。可能是`nil`。这意味着新的局部变量`a`将被重新初始化为它自己的隐式初始化值`nil`。现在，脱糖后的结果如下：

   ```javascript
   var a; // Define the variable.
   a = a; // Run the initializer.
   ```

3. **在初始化式中引用一个变量是错误的。**如果初始化式使用了要初始化的变量，则解释器在编译时或运行时都会失败。

前两个选项中是否有用户真正*想要*的？变量遮蔽很少见，而且通常是一个错误，所以根据被遮蔽的变量值来初始化一个遮蔽的变量，似乎不太可能是有意为之。

第二个选项就更没用了。新变量的值总是`nil`。通过名称来引用没有任何意义。你可以使用一个隐式的`nil`来代替。

由于前两个选项可能会掩盖用户的错误，我们将采用第三个选项。此外，我们要将其作为一个编译错误而不是运行时错误。这样一来，在代码运行之前，用户就会收到该问题的警报。

要做到这一点，当我们访问表达式时，我们需要知道当前是否在某个变量的初始化式中。我们通过将绑定拆分为两步来实现。首先是**声明**。

*<u>lox/Resolver.java，在 endScope()方法后添加：</u>*

```java
  private void declare(Token name) {
    if (scopes.isEmpty()) return;

    Map<String, Boolean> scope = scopes.peek();
    scope.put(name.lexeme, false);
  }
```

声明将变量添加到最内层的作用域，这样它就会遮蔽任何外层作用域，我们也就知道了这个变量的存在。我们通过在作用域map中将其名称绑定到`false`来表明该变量“尚未就绪”。作用域map中与key相关联的值代表的是我们是否已经结束了对变量初始化式的解析。

在声明完变量后，我们在变量当前存在但是不可用的作用域中解析变量的初始化表达式。一旦初始化表达式完成，变量也就绪了。我们通过**define**来实现。

*<u>lox/Resolver.java，在 declare()方法后添加：</u>*

```java
  private void define(Token name) {
    if (scopes.isEmpty()) return;
    scopes.peek().put(name.lexeme, true);
  }
```

我们在作用域map中将变量的值置为`true`，以标记它已完全初始化并可使用。它有了生命！

### 11.3.3 解析变量表达式

变量声明——以及我们即将讨论的函数声明——会向作用域map中写数据。在我们解析变量表达式时，需要读取这些map。

*<u>lox/Resolver.java，在 visitVarStmt()方法后添加：</u>*

```java
  @Override
  public Void visitVariableExpr(Expr.Variable expr) {
    if (!scopes.isEmpty() &&
        scopes.peek().get(expr.name.lexeme) == Boolean.FALSE) {
      Lox.error(expr.name,
          "Can't read local variable in its own initializer.");
    }

    resolveLocal(expr, expr.name);
    return null;
  }
```

首先，我们要检查变量是否在其自身的初始化式中被访问。这也就是作用域map中的值发挥作用的地方。如果当前作用域中存在该变量，但是它的值是`false`，意味着我们已经声明了它，但是还没有定义它。我们会报告一个错误出来。

在检查之后，我们实际上使用了这个辅助方法来解析变量：

*<u>lox/Resolver.java，在 define()方法后添加：</u>*

```java
  private void resolveLocal(Expr expr, Token name) {
    for (int i = scopes.size() - 1; i >= 0; i--) {
      if (scopes.get(i).containsKey(name.lexeme)) {
        interpreter.resolve(expr, scopes.size() - 1 - i);
        return;
      }
    }
  }
```

这看起来很像是Environment中对变量求值的代码。我们从最内层的作用域开始，向外扩展，在每个map中寻找一个可以匹配的名称。如果我们找到了这个变量，我们就对其解析，传入当前最内层作用域和变量所在作用域之间的作用域的数量。所以，如果变量在当前作用域中找到该变量，则传入0；如果在紧邻的外网作用域中找到，则传1。明白了吧。

如果我们遍历了所有的作用域也没有找到这个变量，我们就不解析它，并假定它是一个全局变量。稍后我们将讨论`resolve()`方法的实现。现在，让我们继续浏览其他语法节点。

### 11.3.4 解析赋值表达式

另一个引用变量的表达式就是赋值表达式。解析方法如下：

*<u>lox/Resolver.java，在 visitVarStmt()方法后添加：</u>*

```
  @Override
  public Void visitAssignExpr(Expr.Assign expr) {
    resolve(expr.value);
    resolveLocal(expr, expr.name);
    return null;
  }
```

首先，我们解析右值的表达式，以防它还包含对其它变量的引用。然后使用现有的 `resolveLocal()` 方法解析待赋值的变量。

### 11.3.5 解析函数声明

最后是函数。函数既绑定名称又引入了作用域。函数本身的名称被绑定在函数声明时所在的作用域中。当我们进入函数体时，我们还需要将其参数绑定到函数内部作用域中。

*<u>lox/Resolver.java，在 visitBlockStmt()方法后添加：</u>*

```java
  @Override
  public Void visitFunctionStmt(Stmt.Function stmt) {
    declare(stmt.name);
    define(stmt.name);

    resolveFunction(stmt);
    return null;
  }
```

与`visitVariableStmt()`类似，我们在当前作用域中声明并定义函数的名称。与变量不同的是，我们在解析函数体之前，就急切地定义了这个名称。这样函数就可以在自己的函数体中递归地使用自身。

那么我们可以使用下面的方法来解析函数体：

*<u>lox/Resolver.java，在 resolve()方法后添加：</u>*

```java
  private void resolveFunction(Stmt.Function function) {
    beginScope();
    for (Token param : function.params) {
      declare(param);
      define(param);
    }
    resolve(function.body);
    endScope();
  }
```

这是一个单独的方法，因为我们以后添加类时，还需要使用它来解析Lox方法。它为函数体创建一个新的作用域，然后为函数的每个参数绑定变量。

一旦就绪，它就会在这个作用域中解析函数体。这与解释器处理函数声明的方式不同。在*运行时*，声明一个函数不会对函数体做任何处理。直到后续函数被调用时，才会触及主体。在*静态*分析中，我们会立即遍历函数体。

### 11.3.6 解析其它语法树节点

这涵盖了语法中很多有趣的部分。我们处理了声明、读取、写入遍历，创建、销毁作用域的部分。虽然其它部分不受遍历解析的影响，我们也需要为其它语法树节点提供visit方法，以便递归到它们的子树。抱歉，这部分内容很枯燥，但请耐心听我讲。我们采用“自上而下”的方式，从语句开始。

一个表达式语句中包含一个需要遍历的表达式。

*<u>lox/Resolver.java，在 visitBlockStmt()方法后添加：</u>*

```java
  @Override
  public Void visitExpressionStmt(Stmt.Expression stmt) {
    resolve(stmt.expression);
    return null;
  }
```

`if`语句包含一个条件表达式，以及一个或两个分支语句。

*<u>lox/Resolver.java，在 visitFunctionStmt()方法后添加：</u>*

```java
  @Override
  public Void visitIfStmt(Stmt.If stmt) {
    resolve(stmt.condition);
    resolve(stmt.thenBranch);
    if (stmt.elseBranch != null) resolve(stmt.elseBranch);
    return null;
  }
```

在这里，我们可以看到解析与解释是不同的。当我们解析`if`语句时，没有控制流。我们会解析条件表达式和两个分支表达式。动态执行则只会进入*正在执行*的分支，而静态分析是保守的——它会分析所有*可能执行*的分支。因为任何一个分支在运行时都可能被触及，所以我们要对两者都进行解析。

与表达式语句类似，`print`语句也包含一个子表达式。

*<u>lox/Resolver.java，在 visitIfStmt()方法后添加：</u>*

```java
  @Override
  public Void visitPrintStmt(Stmt.Print stmt) {
    resolve(stmt.expression);
    return null;
  }
```

> Same deal for return.

`return`语句也是相同的。

*<u>lox/Resolver.java，在 visitPrintStmt()方法后添加：</u>*

```java
  @Override
  public Void visitReturnStmt(Stmt.Return stmt) {
    if (stmt.value != null) {
      resolve(stmt.value);
    }

    return null;
  }
```

与`if`语句一样，对于`while`语句，我们会解析其条件，并解析一次循环体。

*<u>lox/Resolver.java，在 visitVarStmt()方法后添加：</u>*

```java
  @Override
  public Void visitWhileStmt(Stmt.While stmt) {
    resolve(stmt.condition);
    resolve(stmt.body);
    return null;
  }
```

这样就涵盖了所有的语句。接下来是表达式……

我们的老朋友二元表达式。我们要遍历并解析两个操作数。

*<u>lox/Resolver.java，在 visitAssignExpr()方法后添加：</u>*

```java
  @Override
  public Void visitBinaryExpr(Expr.Binary expr) {
    resolve(expr.left);
    resolve(expr.right);
    return null;
  }
```

调用也是类似的——我们遍历参数列表并解析它们。被调用的对象也是一个表达式（通常是一个变量表达式），所以它也会被解析。

*<u>lox/Resolver.java，在 visitBinaryExpr()方法后添加：</u>*

```java
  @Override
  public Void visitCallExpr(Expr.Call expr) {
    resolve(expr.callee);

    for (Expr argument : expr.arguments) {
      resolve(argument);
    }

    return null;
  }
```

括号表达式比较简单。

*<u>lox/Resolver.java，在 visitCallExpr()方法后添加：</u>*

```java
  @Override
  public Void visitGroupingExpr(Expr.Grouping expr) {
    resolve(expr.expression);
    return null;
  }
```

字面量表达式是最简单的。

*<u>lox/Resolver.java，在 visitGroupingExpr()方法后添加：</u>*

```java
  @Override
  public Void visitLiteralExpr(Expr.Literal expr) {
    return null;
  }
```

字面表达式中没有使用任何变量，也不包含任何子表达式，所以也不需要做任何事情。

因为静态分析没有控制流或短路处理，逻辑表达式与其它的二元运算符是一样的。

*<u>lox/Resolver.java，在 visitLiteralExpr()方法后添加：</u>*

```java
  @Override
  public Void visitLogicalExpr(Expr.Logical expr) {
    resolve(expr.left);
    resolve(expr.right);
    return null;
  }
```

接下来是最后一个节点，我们解析它的一个操作数。

*<u>lox/Resolver.java，在 visitLogicalExpr()方法后添加：</u>*

```java
  @Override
  public Void visitUnaryExpr(Expr.Unary expr) {
    resolve(expr.right);
    return null;
  }
```

有了这些visit方法，Java编译器应该会认为Resolver完全实现了Stmt.Visitor 和 Expr.Visitor。现在是时候休息一下了。

## 11.4 解释已解析的变量

让我们看看解析器有什么用处。每次访问一个变量时，它都会告诉解释器，在当前作用域和变量定义的作用域之间隔着多少层作用域。在运行时，这正好对应于当前环境与解释器可以找到变量值的外围环境之间的*environments*数量。解析器通过调用下面的方法将这个数字传递给解释器：

*<u>lox/Interpreter.java，在 execute()方法后添加：</u>*

```java
  void resolve(Expr expr, int depth) {
    locals.put(expr, depth);
  }
```

我们要把解析信息存储在某个地方，这样在执行变量表达式和赋值表达式时就可以使用它，但是要存在哪里呢？一个明显的位置就是语法树节点本身。这是一个很好的方法，许多编译器都是在这里存储类似的分析结果的。

我们可以这样做，但是需要对我们的语法树生成器进行修改。相反，我们会采用另一种常见的方法，将其存储在一个map中，将每个语法树节点与其解析的数据关联起来。

像IDE这种的交互式工具经常会增量地对用户的部分代码进行重新分析和解析。当这些状态隐藏在语法树的枝叶中时，可能很难找到所有需要重新计算的状态。将这些数据存储在节点之外的好处之一就是，可以很容易地丢弃这部分数据——只需要清除map即可。

*lox/Interpreter.java*，在 *Interpreter*类中添加

```java
  private Environment environment = globals;
  // 新增部分开始
  private final Map<Expr, Integer> locals = new HashMap<>();
  // 新增部分结束
  Interpreter() {
```

你可能认为我们需要某种嵌套的树状结构，以避免在有多个表达式引用同一个变量时出现混乱，但是每个表达式节点都有其对应的Java对象，具有唯一性标识。一个简单的map就足以将它们全部区分开来。

与之前一样，使用集合需要先引入一些包名称。

*<u>lox/Interpreter.java，添加：</u>*

```java
import java.util.ArrayList;
// 新增部分开始
import java.util.HashMap;
// 新增部分结束
import java.util.List;
```

还有：

*<u>lox/Interpreter.java，添加：</u>*

```java
import java.util.List;
// 新增部分开始
import java.util.Map;
// 新增部分结束
class Interpreter implements Expr.Visitor<Object>,
```

### 11.4.1 访问已解析的变量

我们的解释器现在可以访问每个变量的解析位置。最后，我们可以利用这一点了，将变量表达式的visit方法替换如下：

*<u>lox/Interpreter.java，在 visitVariableExpr()方法中替换一行：</u>*

```java
  public Object visitVariableExpr(Expr.Variable expr) {
    // 替换部分开始
    return lookUpVariable(expr.name, expr);
    // 替换部分结束
  }
```

这里引用了：

*<u>lox/Interpreter.java，在 visitVariableExpr()方法后添加：</u>*

```java
  private Object lookUpVariable(Token name, Expr expr) {
    Integer distance = locals.get(expr);
    if (distance != null) {
      return environment.getAt(distance, name.lexeme);
    } else {
      return globals.get(name);
    }
  }
```

这里有几件事要做。首先，我们在map中查找已解析的距离值。要记住，我们只解析了本地变量。全局变量被特殊处理了，不会出现了map中（所以它的名字叫`locals`）。所以，如果我们没有在map中找到变量对应的距离值，它一定是全局变量。在这种情况下，我们直接在全局environment中查找。如果变量没有被定义，就会产生一个运行时错误。

如果我们*确实*查到了一个距离值，那这就是个局部变量，我们可以利用静态分析的结果。我们不会调用`get()`方法，而是调用下面这个Environment中的新方法：

*<u>lox/Environment.java，在 define()方法后添加：</u>*

```java
  Object getAt(int distance, String name) {
    return ancestor(distance).values.get(name);
  }
```

原先的`get()`方法会动态遍历外围的环境链，搜索每一个环境，查看变量是否包含在其中。但是现在我们明确知道链路中的哪个环境中会包含该变量。我们使用下面的辅助方法直达这个环境：

*<u>lox/Environment.java，在 define()方法后添加：</u>*

```java
  Environment ancestor(int distance) {
    Environment environment = this;
    for (int i = 0; i < distance; i++) {
      environment = environment.enclosing; 
    }

    return environment;
  }
```

该方法在环境链中经过确定的跳数之后，返回对应的环境。一旦我们有了环境，`getAt()`方法就可以直接返回对应环境map中的变量值。甚至不需要检查变量是否存在——我们知道它是存在的，因为解析器之前已经确认过了。

### 11.4.2 赋值已解析的变量

我们也可以通过赋值来使用一个变量。赋值表达式对应的visit方法的修改也是类似的。

*<u>lox/Interpreter.java，在 visitAssignExpr()方法中替换一行：</u>*

```java
  public Object visitAssignExpr(Expr.Assign expr) {
    Object value = evaluate(expr.value);  
    // 替换部分开始
    Integer distance = locals.get(expr);
    if (distance != null) {
      environment.assignAt(distance, expr.name, value);
    } else {
      globals.assign(expr.name, value);
    }
    // 替换部分结束
    return value;
```

又一次，我们要查找变量的作用域距离。如果没有找到，我们就假定它是全局变量并采用跟之前一样的方式来处理；否则，我们使用下面的新方法：

*<u>lox/Environment.java，在 getAt()方法后添加：</u>*

```java
  void assignAt(int distance, Token name, Object value) {
    ancestor(distance).values.put(name.lexeme, value);
  }
```

正如`getAt()` 与`get()`的关系，`assignAt()` 对应于`assign()`。它会遍历固定数量的环境，然后在其map中塞入新的值。

解释器就只需要做这些调整。这也就是为什么我为解析数据选择了一种侵入性最小的表示方法。其余所有节点都跟之前一样，甚至连修改环境的代码也没有改动。

### 11.4.3 运行解析器

不过，我们确实需要*运行*解析器。我们在解析器完成工作之后插入一次解析器处理。

*<u>lox/Lox.java，在 run()方法中添加代码：</u>*

```java
    // Stop if there was a syntax error.
    if (hadError) return;
    // 新增部分开始
    Resolver resolver = new Resolver(interpreter);
    resolver.resolve(statements);
    // 新增部分结束
    interpreter.interpret(statements);
```

如果前面的分析中存在任何错误，我们都不会运行解析器。如果代码有语法错误，它就不会运行，所以解析它的价值不大。如果语法是干净的，我们就告诉解析器做该做的事。解析器中有一个对解释器的引用，当它遍历变量时，会将解析数据直接放入解释器中。解释器后续运行时，它就具备了所需的一切数据。

退一步讲，如果解析器成功了，这么说就是对的。但是如果解析过程中出现错误会怎么办？

## 11.5 解析错误

由于我们正在进行语义分析，因此我们有机会使Lox 的语义更加精确，以帮助用户在执行代码之前及早发现错误。看一下下面这个坏代码：

```javascript
fun bad() {
  var a = "first";
  var a = "second";
}
```

我们确实允许在*全局*作用域内声明多个同名的变量，但在局部作用域内这样做可能是错误的。如果用户知道变量已经存在，就应该使用赋值操作而不是`var`。如果他们不知道变量的存在，他们可能并不想覆盖之前的变量。

我们可以在解析的时候静态地检测到这个错误。

*<u>lox/Resolver.java，在 declare()方法中添加：</u>*

```java
    Map<String, Boolean> scope = scopes.peek();
    // 新增部分开始
    if (scope.containsKey(name.lexeme)) {
      Lox.error(name,
          "Already variable with this name in this scope.");
    }
    // 新增部分结束
    scope.put(name.lexeme, false);
```

当我们在局部作用域中声明一个变量时，我们已经知道了之前在同一作用域中声明的每个变量的名字。如果我们看到有冲突，我们就报告一个错误。

### 11.5.1 无效返回错误

这是另一个讨人厌的小脚本：

```java
return "at top level";
```

这里执行了一个`return`语句，但它甚至根本不在函数内部。这是一个顶层代码。我不知道用户认为会发生什么，但是我认为我们不希望Lox允许这种做法。

我们可以对解析器进行扩展来静态检测这种错误。就像我们遍历语法树时跟踪作用域一样，我们也可以跟踪当前访问的代码是否在一个函数声明内部。

*<u>lox/Resolver.java，在 Resolver类中添加代码：</u>*

```java
  private final Stack<Map<String, Boolean>> scopes = new Stack<>();
  // 新增部分开始
  private FunctionType currentFunction = FunctionType.NONE;
  // 新增部分结束
  Resolver(Interpreter interpreter) {
```

我们不是使用一个简单的Boolean值，而是使用下面这个有趣的枚举：

*<u>lox/Resolver.java，在 Resolver()方法后添加：</u>*

```
  private enum FunctionType {
    NONE,
    FUNCTION
  }
```

现在看来又得蠢，但是我们稍后会添加更多案例，到时候它将更有意义。当我们解析函数声明时，将其作为参数传入。

*<u>lox/Resolver.java，在 visitFunctionStmt()方法中，替换一行：</u>*

```java
    define(stmt.name);
    // 替换部分开始
    resolveFunction(stmt, FunctionType.FUNCTION);
    // 替换部分结束
    return null;
```

在`resolveFunction()`中，我们接受该参数，并在解析函数体之前将其保存在字段中。

*<u>lox/Resolver.java，在 resolveFunction()方法中替换一行：</u>*

```java
  // 替换部分开始
	private void resolveFunction(
      Stmt.Function function, FunctionType type) {
    FunctionType enclosingFunction = currentFunction;
    currentFunction = type;
    // 替换部分结束
    beginScope();
```

我们先把该字段的旧值存在一个局部变量中。记住，Lox中有局部函数，所以你可以任意深度地嵌套函数声明。我们不仅需要跟踪是否在一个函数内部，还要记录我们在*多少*函数内部。

我们可以使用一个显式的FunctionType值堆栈来进行记录，但我们会借助JVM的力量。我们将前一个值保存在Java堆栈中的一个局部变量。当我们完成函数体的解析之后，我们将该字段恢复为之前的值。

*<u>lox/Resolver.java，在 resolveFunction()方法中添加代码：</u>*

```java
    endScope();
    // 新增部分开始
    currentFunction = enclosingFunction;
    // 新增部分结束
  }
```

既然我们能知道是否在一个函数声明中，那我们就可以在解析`return`语句时进行检查。

*<u>lox/Resolver.java，在 visitReturnStmt()方法中添加代码：</u>*

```java
  public Void visitReturnStmt(Stmt.Return stmt) {
    // 新增部分开始
    if (currentFunction == FunctionType.NONE) {
      Lox.error(stmt.keyword, "Can't return from top-level code.");
    }
    // 新增部分结束
    if (stmt.value != null) {
```

很简洁，对吧？

还有一件事。回到将所有部分整合到一起的主类Lox中，我们很小心，如果遇到任何解析错误就不会运行解释器。这个检查是在解析器*之前*运行的，这样我们就不需要再去尝试解析语法无效的代码。

但是如果在解析变量时存在错误，也需要跳过解释器，所以我们添加*另一个*检查。

*<u>lox/Lox.java，在 run()方法中添加代码：</u>*

```java
    resolver.resolve(statements);
    // 新增部分开始
    // Stop if there was a resolution error.
    if (hadError) return;
    // 新增部分结束
    interpreter.interpret(statements);
```

你可以想象在这里做很多其它分析。例如，我们在Lox中添加了`break`语句，而我们可能想确保它只能在循环体中使用。

我们还可以更进一步，对那些不一定是错误但可能没有用的代码提出警告。举例来说，如果在`return`语句后有不可触及的代码，很多IDE都会发出警告，或者是一个局部变量的值从没有被使用过。所有这些都可以很简单地添加到我们的静态分析过程中，或者作为单独的分析过程。

但是，就目前而言，我们会坚持这种有限的分析。重要的是，我们修复了一个奇怪又烦人的边界情况bug，尽管花费了这么多精力可能有些令人意外。