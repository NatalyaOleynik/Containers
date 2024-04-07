## Основные контейнеры

### List

<details>
  <summary>Общая информация</summary>
<br />

List (список) - это последовательный контейнер, хранящий набор элементов произвольного размера в виде узлов, последовательно связанных указателями. Каждый узел хранит значение, соответствующее элементу списка, и указатель на следующий элемент. Такое устройство контейнера позволяет уйти от жестко фиксированного рамера, как, например, в статическом массиве, и делает более интуитивно понятным процесс добавления нового элемента в контейнер. 

![](../misc/images/list_01.png)

Выше представлен пример списка из четырех элементов. Каждый из элементов списка представлен в виде структуры с двумя полями: значение узла и указатель на следующий элемент списка. Последний элемент списка ни на что не указывает. 

![](../misc/images/list_02.png)

Подобное устройство списка позволяет простым образом (без каскадного сдвига) добавлять как в конец, так и в середину списка. При добавлении элемента в конкретную позицию списка создается новый узел, указывающий на следующий после данной позиции элемент, после чего указатель предыдущего элемента перемещается на новый.

![](../misc/images/list_03.png)

При удалении элемента из списка, соответствующий узел освобождается, а указатели соседних элементов меняют значение: предыдущий элемент перемещает указатель на следующий после удаленного элемент.

Списки бывают односвязные или двусвязные. Односвязный список - это список, каждый узел которого хранит только один указатель: на следующий элемент списка (пример, приведенный выше). В двусвязном списке каждый узел хранит дополнительный указатель и на предыдущий элемент. Стандартная реализация контейнера list в С++ использует двусвязный список. 

В объекте класса контейнера хранятся указатели на "голову" и "хвост" списка, указывающие на первый и последний элементы списка. Контейнер List предоставляет прямой доступ только к "голове" и "хвосту", но позволяет добавлять и удалять элементы в любой части списка.
</details>

<details>
  <summary>Спецификация</summary>
<br />

*List Member type*

В этой таблице перечислены внутриклассовые переопределения типов (типичные для стандартной библиотеки STL), принятые для удобства восприятия кода класса:

| Member type            | definition                                                                             |
|------------------------|----------------------------------------------------------------------------------------|
| `value_type`             | `T` defines the type of an element (T is template parameter)                                  |
| `reference`              | `T &` defines the type of the reference to an element                                                             |
| `const_reference`        | `const T &` defines the type of the constant reference                                         |
| `iterator`               | internal class `ListIterator<T>` defines the type for iterating through the container                                                 |
| `const_iterator`         | internal class `ListConstIterator<T>` defines the constant type for iterating through the container                                           |
| `size_type`              | `size_t` defines the type of the container size (standard type is size_t) |

*List Functions*

В этой таблице перечислены основные публичные методы для взаимодействия с классом:

| Functions      | Definition                                      |
|----------------|-------------------------------------------------|
| `list()`  | default constructor, creates empty list                                  |
| `list(size_type n)`  | parameterized constructor, creates the list of size n                                 |
| `list(std::initializer_list<value_type> const &items)`  | initializer list constructor, creates list initizialized using std::initializer_list<T>    |
| `list(const list &l)`  | copy constructor  |
| `list(list &&l)`  | move constructor  |
| `~list()`  | destructor  |
| `operator=(list &&l)`      | assignment operator overload for moving object                                |

*List Element access*

В этой таблице перечислены публичные методы для доступа к элементам класса:

| Element access | Definition                                      |
|----------------|-------------------------------------------------|
| `const_reference front()`          | access the first element                        |
| `const_reference back()`           | access the last element                         |

*List Iterators*

В этой таблице перечислены публичные методы для итерирования по элементам класса (доступ к итераторам):

| Iterators      | Definition                                      |
|----------------|-------------------------------------------------|
| `iterator begin()`    | returns an iterator to the beginning            |
| `iterator end()`        | returns an iterator to the end                  |

*List Capacity*

В этой таблице перечислены публичные методы для доступа к информации о наполнении контейнера:

| Capacity       | Definition                                      |
|----------------|-------------------------------------------------|
| `bool empty()`          | checks whether the container is empty           |
| `size_type size()`           | returns the number of elements                  |
| `size_type max_size()`       | returns the maximum possible number of elements |

*List Modifiers*

В этой таблице перечислены публичные методы для изменения контейнера:

| Modifiers      | Definition                                      |
|----------------|-------------------------------------------------|
| `void clear()`          | clears the contents                             |
| `iterator insert(iterator pos, const_reference value)`         | inserts element into concrete pos and returns the iterator that points to the new element     |
| `void erase(iterator pos)`          | erases element at pos                                 |
| `void push_back(const_reference value)`      | adds an element to the end                      |
| `void pop_back()`   | removes the last element        |
| `void push_front(const_reference value)`      | adds an element to the head                      |
| `void pop_front()`   | removes the first element        |
| `void swap(list& other)`                   | swaps the contents                                                                     |
| `void merge(list& other)`                   | merges two sorted lists                                                                      |
| `void splice(const_iterator pos, list& other)`                   | transfers elements from list other starting from pos             |
| `void reverse()`                   | reverses the order of the elements              |
| `void unique()`                   | removes consecutive duplicate elements               |
| `void sort()`                   | sorts the elements                |

</details>

### Queue

<details>
  <summary>Общая информация</summary>
<br />

Queue (очередь) - это контейнер с элементами, организованными по принцнипу FIFO (First-In, First-Out). Так же как список, объект контейнерного класса очереди содержит в себе указатели на "хвост" и "голову" очереди, однако удаление производится строго из "головы", а запись, то есть добавление новых элементов, строго в "хвост". Очередь удобно представлять как своего рода трубу, в один конец которой попадают элементы, и убывают с другого конца.

![](../misc/images/queue01.png)

</details>

<details>
  <summary>Спецификация</summary>
<br />

*Queue Member type*

В этой таблице перечислены внутриклассовые переопределения типов (типичные для стандартной библиотеки STL), принятые для удобства восприятия кода класса:

| Member type      | Definition                                       |
|------------------|--------------------------------------------------|
| `value_type`       | `T` the template parameter T                   |
| `reference`              | `T &` defines the type of the reference to an element                                                             |
| `const_reference`        | `const T &` defines the type of the constant reference                                         |
| `size_type`        | `size_t` defines the type of the container size (standard type is size_t) |

*Queue Member functions*

В этой таблице перечислены основные публичные методы для взаимодействия с классом:

| Functions      | Definition                                      |
|----------------|-------------------------------------------------|
| `queue()`  | default constructor, creates empty queue                                 |
| `queue(std::initializer_list<value_type> const &items)`  | initializer list constructor, creates queue initizialized using std::initializer_list<T>    |
| `queue(const queue &q)`  | copy constructor  |
| `queue(queue &&q)`  | move constructor  |
| `~queue()`  | destructor  |
| `operator=(queue &&q)`      | assignment operator overload for moving object                                |

*Queue Element access*

В этой таблице перечислены публичные методы для доступа к элементам класса:

| Element access | Definition                                      |
|----------------|-------------------------------------------------|
| `const_reference front()`          | access the first element                        |
| `const_reference back()`           | access the last element                         |

*Queue Capacity*

В этой таблице перечислены публичные методы для доступа к информации о наполнении контейнера:

| Capacity       | Definition                                      |
|----------------|-------------------------------------------------|
| `bool empty()`          | checks whether the container is empty           |
| `size_type size()`           | returns the number of elements                  |

*Queue Modifiers*

В этой таблице перечислены публичные методы для изменения контейнера:

| Modifiers        | Definition                                       |
|------------------|--------------------------------------------------|
| `void push(const_reference value)`             | inserts element at the end                       |
| `void pop()`              | removes the first element                        |
| `void swap(queue& other)`             | swaps the contents                               |

</details>

### Stack

<details>
  <summary>Общая ифнормация</summary>
<br />

Stack (стек) - это контейнер с элементами, организованными по принцнипу LIFO (Last-In, First-Out). Объект контейнерного класса стека содержит в себе указатели на "голову" стека, удаление и добавление элементов производится строго из "головы". Стек удобно представлять как стакан или трубу с одним запаянным концом: для того чтобы добраться до элемента, помещенного в контейнер первым, требуется сначала вынуть все элементы, находящиеся сверху.

![](../misc/images/stack01.png)

</details>

<details>
  <summary>Спецификация</summary>
<br />

*Stack Member type*

В этой таблице перечислены внутриклассовые переопределения типов (типичные для стандартной библиотеки STL), принятые для удобства восприятия кода класса:

| Member type      | Definition                                       |
|------------------|--------------------------------------------------|
| `value_type`       | `T` the template parameter T                   |
| `reference`              | `T &` defines the type of the reference to an element                                                             |
| `const_reference`        | `const T &` defines the type of the constant reference                                         |
| `size_type`        | `size_t` defines the type of the container size (standard type is size_t) |

*Stack Member functions*

В этой таблице перечислены основные публичные методы для взаимодействия с классом:

| Functions      | Definition                                      |
|----------------|-------------------------------------------------|
| `stack()`  | default constructor, creates empty stack                                 |
| `stack(std::initializer_list<value_type> const &items)`  | initializer list constructor, creates stack initizialized using std::initializer_list<T>    |
| `stack(const stack &s)`  | copy constructor  |
| `stack(stack &&s)`  | move constructor  |
| `~stack()`  | destructor  |
| `operator=(stack &&s)`      | assignment operator overload for moving object                                |

*Stack Element access*   

В этой таблице перечислены публичные методы для доступа к элементам класса:

| Element access   | Definition                                       |
|------------------|--------------------------------------------------|
| `const_reference top()`              | accesses the top element                         |

*Stack Capacity*   

В этой таблице перечислены публичные методы для доступа к информации о наполнении контейнера:

| Capacity       | Definition                                      |
|----------------|-------------------------------------------------|
| `bool empty()`          | checks whether the container is empty           |
| `size_type size()`           | returns the number of elements                  |

*Stack Modifiers*        

В этой таблице перечислены публичные методы для изменения контейнера:

| Modifiers        | Definition                                       |
|------------------|--------------------------------------------------|
| `void push(const_reference value)`             | inserts element at the top                       |
| `void pop()`              | removes the top element                        |
| `void swap(stack& other)`             | swaps the contents                               |

</details>
