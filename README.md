# Programming

Biblioteca de estruturas de dados em C++ e resoluções de exercícios de diferentes plataformas.

## Organização

```text
include/ds/          Cabeçalhos públicos da biblioteca
src/ds/              Implementações da biblioteca que precisam de .cpp
exercises/leetcode/  Uma pasta por problema, com solution.cpp
exercises/beecrowd/  Exercícios do beecrowd
exercises/codeforces/ Exercícios do Codeforces
support/leetcode/    Tipos fornecidos pela plataforma, para compilação local
build/               Arquivos gerados pelo CMake, ignorados pelo Git
```

As estruturas reutilizáveis devem usar o namespace `ds` e ser incluídas como
`#include <ds/stack.hpp>`, por exemplo, quando esse cabeçalho for implementado.
Implementações com templates normalmente ficam nos próprios cabeçalhos.
As pastas da biblioteca estão preparadas; nenhuma estrutura nova foi implementada.

O alvo `ds` começa como uma biblioteca de cabeçalhos (`INTERFACE`). Quando houver
implementações em `src/ds/`, altere-o para uma biblioteca compilada e registre seus
arquivos `.cpp`, mantendo o diretório `include` como inclusão pública.

## Compilação

Requisitos: CMake 3.16 ou superior e compilador com suporte a C++17.

```sh
cmake -S . -B build
cmake --build build
```

Para compilar e executar apenas um exercício:

```sh
cmake --build build --target leetcode_0001_two_sum
./build/leetcode_0001_two_sum
```

Cada exercício tem seu próprio alvo, evitando conflitos entre funções `main()`
e classes `Solution`. As soluções sem `main()` são compiladas como bibliotecas
de objetos e não geram executáveis. Nenhum teste é criado por esta configuração.

## Novos exercícios

Crie `exercises/leetcode/NNNN_nome_do_problema/solution.cpp` e registre-o no
`CMakeLists.txt` com `add_leetcode_exercise(NNNN_nome_do_problema)`.
Acrescente `OBJECT` quando a solução não tiver `main()`.
Para outras plataformas, crie alvos independentes com `add_executable` e vincule
a biblioteca usando `target_link_libraries(nome_do_alvo PRIVATE ds)`.

## Submissão nas plataformas

O cabeçalho `<leetcode/list_node.hpp>` permite compilar localmente soluções que
usam `ListNode`. Remova esse include ao submeter ao LeetCode, que fornece o tipo.
Remova também o `main()` local quando a plataforma solicitar apenas `Solution`.
Se usar estruturas da biblioteca em uma submissão, inclua o código necessário
no arquivo enviado: os sites não têm acesso aos cabeçalhos deste repositório.
