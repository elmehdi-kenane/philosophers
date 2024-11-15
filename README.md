# 🧘 Philosophers Problem - 42 Project

Welcome to the **Philosophers Problem** project! This project implements the classical _Dining Philosophers Problem_ 🥢 in C, showcasing synchronization techniques and multithreading.

<p align="center">
    <img title="a title" alt="Alt text" src="./DIAGRAM-philosopher.jpeg">
</p>


## ⚡ Quick Start

_*To compile and manage the project, a `Makefile` is provided._

1. Clone the repository.
   ```bash
   git clone git@github.com:elmehdi-kenane/philosophers.git
   ```
2. Enter to the project and Compile it:
   ```bash
   cd philosophers/mandatory
   make
   ```
3. Run the simulation:
   ```bash
   ./philo
   ```


### Commands

1. **Build the project**:

    - **`all`**: Builds the executable `philo` 🚀.
        ```bash
        make all
        ```

2. **Clean up object files**:

    - **`clean`**: Removes all object files 🧹.
        ```bash
        make clean
        ```

3. **Clean everything (object files + executable)**:

    - **`fclean`**: Cleans up object files and the `philo` executable 🔥.
        ```bash
        make fclean
        ```

4. **Rebuild the project from scratch**:
    - **`re`**: Performs a full rebuild by running `fclean` and then `all` 🔄.
        ```bash
        make re
        ```

## 🧵 Problem Overview

The Dining Philosophers Problem simulates philosophers who alternate between eating 🍴, thinking 🤔, and sleeping 🛌. Philosophers need forks to eat, but adjacent philosophers share forks, leading to potential deadlock situations.

### Key Challenges:

1. Avoiding **deadlock** 🛑.
2. Ensuring **fairness** among philosophers.
3. Managing **thread synchronization** ⚙️.

## 💡 Features

- **Efficient multithreading**: Uses threads for each philosopher.
- **Deadlock prevention**: Implements strategies to ensure smooth simulation.
- **Input validation**: Checks for correct arguments and values.

## 🌟 Contributing

Feel free to fork this project, raise issues, or submit pull requests. Contributions to enhance the project are always welcome! 🛠️

## 📜 resources

### articles

- [Mutex vs Semaphore](https://www.geeksforgeeks.org/mutex-vs-semaphore/)
- [Introduction to C Threads](https://www.cs.cornell.edu/courses/cs2022/2011sp/lectures/lect11.pdf)
- [Chapter 10 Threads](http://www.compsci.hunter.cuny.edu/~sweiss/course_materials/unix_lecture_notes/chapter_10.pdf)
- [Multithreading](https://beej.us/guide/bgc/html/split/multithreading.html)
- [Philosophers visualizer](https://nafuka11.github.io/philosophers-visualizer/)
- [Threads](https://www.personal.kent.edu/~rmuhamma/OpSystems/Myos/threads.htm)
- [Concurrency vs Parallelism](https://freecontent.manning.com/concurrency-vs-parallelism/)
- [Multithreaded Programming (POSIX pthreads Tutorial)](https://randu.org/tutorials/threads/)
- [An Application of Pthreads and Mutexes](http://files.kipr.org/gcer/2009/proceedings/Myers_ApplicationPthreads.pdf)
- [ThreadMentor: The Dining Philosophers Problem](https://pages.mtu.edu/~shene/NSF-3/e-Book/MUTEX/TM-example-philos-1.html)
- [Solutions to the Dining Philosopher problem](https://www.stolaf.edu/people/rab/pdc/text/dpsolns.html)
- [The Dining Philosophers Problem](https://medium.com/science-journal/the-dining-philosophers-problem-fded861c37ed)
- [readme](https://github.com/TommyJD93/Philosophers/tree/master)

### notion pages

- [page 1](https://www.notion.so/Philosophers-2b872948598e4f0cba91c66d8b5ba821)
- [page 2](https://www.notion.so/Philosophers-1f8ab111b1684177995a97b73c1d1193)
- [page 3](https://grizzly-muenster-737.notion.site/Philosophers-55c385e0a6224d629c86231821e3ce10)

### videos

- [Lec31 Synchronization among Threads (Arif Butt @ PUCIT)](https://www.youtube.com/watch?v=SvFr7rPWI3g&list=PL7B2bn3G_wfC-mRpG7cxJMnGWdPAQTViW&index=47)
- [Lec23 Multi Threaded Programming (Arif Butt @ PUCIT)](https://www.youtube.com/watch?v=OgnLaXwLC8Y&list=PL7B2bn3G_wfC-mRpG7cxJMnGWdPAQTViW&index=36)
- [playlist CODE VAULT](https://www.youtube.com/watch?v=d9s_d28yJq0&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2)
- [playlist Jacob](https://www.youtube.com/watch?v=uA8X5zNOGw8&list=PL9IEJIKnBJjFZxuqyJ9JqVYmuFZHr7CFM)
- [The Dining Philosophers Problem - Neso](https://www.youtube.com/watch?v=FYUi-u7UWgw)
- [Introduction To Threads (pthreads) | C Programming Tutorial](https://www.youtube.com/watch?v=ldJ8WGZVXZk)

