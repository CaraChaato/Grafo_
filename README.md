## Mestre e Discentes

- Professor: [Kennedy Reurison Lopes](https://github.com/kennedyufersa).<br />
- Desenvolvedor Principal: [Pedro Vinícius de Andrade Queiroz](https://github.com/CaraChaato).<br /> (Aka Chato)
- Desenvolvedor Principal: [Karlos Wiliam da Rocha Marques](https://github.com/AtakyRevolts).<br /> (Aka Will)
- Analista Principal e Desenvolvedora: [Lavínia Dantas de Mesquita](https://github.com/LilPuppet).<br /> (Aka Lava)
- Desenvolvedora e Boneco de Testes: [Antônia Sabrina Marinho Marcolino](https://github.com/httpsk1b0).<br />
- Densenvolvedor e Boneco de Testes: [Kauê](Coloque seu link aqui kauê).<br />


## Grafos (O Estado do Rio Grande do Norte)
>A vizinhança entre cidades pode ser definida pelo motivo das cidades terem uma fronteira
em comum, ou não. Mas apesar disto, outras cidades são influenciadas ou influenciam entre si.

>Sabendo disso, a proposta desse roteiro é definir uma nova medida de vizinhança baseado
na distância entre as cidades. Nosso princípio será o seguinte: Duas cidades serão consideradas vizinhas (ou influentes) se estiverem a uma distância mínima D entre elas.

Nosso projeto usa da Matriz de Inciência para organizar e relacionar as informações das cidades, suas vizinhas e a distância entre elas, contendo:
- Uma função que cria todas as matrizes com base na distância mínima escolhida para que sejam vizinhas
- Uma função que indica a cidade com mais vizinhos e a quantidade de vizinhos entre sí.
- Uma função que indica as cidades que não possuem nenhum vizinho.
- Uma função que determina a menor distância para que todas as cidades sejam vizinhas.

## Cria Vizinhos.
- Declaração de Variáveis:

Primeiro, declaramos duas variaveis auxiliares, chamadas de i e de j. Depois, criamos uma matriz do tipo float com alocação adequada em todos os seus espaços.

- Preenchimento das Variaveis:

Primeiro, criamos dois FORs, que esvaziam a matriz, ou seja, iniciam ela. 

Após iniciar, criamos mais dois FORs, eles percorrem toda a matriz: Se os auxiliares forem iguais, o que significa que ambos correspondem a mesma cidade, definimos como -1, já que ela não pode ser vizinha de si mesma. 

Senão, usamos a função disponibilizada pelo nosso orientador para definir a distância de tal combinação de cidades. Se for menor ou igual a distância limite, eles armazenam o valor da distância entre os dois. Senão, se forem vazias, -1.

Por fim, retorna a matriz.

## Print Mais Vizinhos
- Declaração de Variáveis:

Criamos mini inteiros, variaveis do tipo size_t. Uma é uma variável temporária chamada tmp, um vetor chamado highest, que possui dois espaços (Um para guardar um contador e outro para guardar tmp no final)

- Procedimento Principal:

Primeiro, criamos dois FORs, eles percorrem toda a matriz: Se o arquivo temporário for menor do que a variável armazenada anteriormente em quesito quantidade de vizinhos, ele refefine a variável temporária para por a cidade usada na comparação.

Ao recorrer das verificações, obtemos a cidade com mais vizinhos e imprimimos ela e a quantidade de vizinhos dela.

## Print Sem Vizinhos
- Declaração de Variáveis:

Criamos mini inteiros, variaveis do tipo size_t. Uma é uma variável temporária chamada tmp, e os contadores i e y.

- Procedimento Principal:

Primeiro, criamos dois FORs, eles percorrem toda a matriz: Se a função achar um número positivo (um vizinho), ele dá break e passa pra próxima repetição.

Se ele percorrer toda a matriz sem achar nenhum número positivo, ele encontrou uma cidade sem vizinhos, portanto, o nome dela será impresso, várias serão impressas conforme o looping é percorrido.

## Imprimir Para Arquivo
- Declaração de Variáveis:

Criamos um char chamado tmp, um mini inteiro chamado length e um arquivo chamado file.

- Procedimento Principal:
Basicamente, usa dois FORs para percorrer as informações e imprime a relação de vizinhos usando a fórmula para poder armazenar no arquivo!

## Print Mat

- Procedimento Principal:
Ela quem imprime as matrizes criadas, só isso mesmo!



