# DATA STRUCTURE LIBRARY

This is my own implementation of various Data Structures in C language.

## Usage

1. Download .zip from this repository
2. Go to your project directory
```
cd your-project/
```
3. Unzip the files into your project directory
```
unzip ~/Downloads/datastrlib-main.zip
```
4. Create main.c and add these header files:
```
#include <stdbool.h>
#include "datastrlib-main/include/queues.h"
#include "datastrlib-main/include/stacks.h"
```
5. Compile with gcc
```
gcc -o user-project main.c -I datastrlib-main/include -L datastrlib-main/build -l:datastrlib.a
```
## Contributing
If you want to contribute to a project and make it better, your help is very welcome. Here is few guidelines to follow:

### How to make a clean pull request

1. Create a personal fork of the project on Github.
2. Clone the fork on your local machine.
3. Add the original repository as a remote called `upstream`.
4. Create a new branch to work on!
```
git checkout -b feature origin/feature
```
6. Develop feature
- If you are developing feature, create src/feature.c and include/feature.h. Those 2 files must be clean and containing only code related to feature
- You can use custom main.c for testing your feature and don't forget to add that file inside .gitignore
- Compile your changes
```
make clean
make
```
- Compile test program
```
gcc -o user-project main.c -I include -L build -l:datastrlib.a
```
7. Create test cases
- Inside of tests/unit directory, create test cases for your work. After doing that run:
```
make test
```
8. Make changes
- If your tests passed, you can make changes:
```
git add .
git commit -m "Feature/Bugfix" -m "- Your meaningful commit message"
git push origin feature-or-fix-name
```
9. Create pull request
- Before submitting the pull request, ensure your fork is in sync with the upstream
10. Code rewiew
  - Wait for code review and happy codding!
  
## License
This project is licensed under the MIT License. See the LICENSE file for details.
