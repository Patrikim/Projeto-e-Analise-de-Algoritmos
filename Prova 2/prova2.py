import numpy as np



class Point:
    def __init__(self,x: int, y: int):
        self.x = x
        self.y = y

def calc_dist(m, aux, source, dest):

    # Seta a distancia do nó inicial como 0 na matriz de distancias
    aux[source.x][source.y] = 0
    # Lista de prioridade para processamento das células
    list_prior=[]
    # Adiciona o nó inicial na lista para ser processado
    list_prior.append((0, (source.x, source.y)))

    cont = 0

    # Enquanto tiver células na lista para processar
    while len(list_prior) > 0 :

        print(list_prior)
        # Tira a célula da lista
        element = list_prior.pop(0)
        position = element[1]
        dist = element[0]
        item = Point(position[0], position[1])
        # Incrementa a distância para alocar nos vizinhos  
        dist = dist + 1

        # Verifica se a posição ainda não foi visitada
    
        # Verifica se a célula acima da posição atual é válida para calcular a distância
        if item.x > 0:
            # Verifica se o valor da célula acimaé maior que o da atual e se é caminho
            if aux[item.x - 1][item.y] > aux[item.x][item.y] + 1 and m[item.x - 1][item.y] != 1:
                # Adiciona o nó e a sua distância do início na lista
                list_prior.append(dist, (item.x - 1, item.y))
                # Seta a distância da célula na matrix de distancias
                aux[item.x - 1][item.y] = dist
        # Verifica se a célula abaixo da posição atual é válida para calcular a distância
        if item.x < len(m) - 1:
            # Verifica se o valor da célula abaixo é maior que o da atual e se é caminho
            if aux[item.x + 1][item.y] > aux[item.x][item.y] + 1 and m[item.x + 1][item.y] != 1:
                # Adiciona o nó e a sua distância do início na lista
                list_prior.append((dist, (item.x + 1, item.y)))
                # Seta a distância da célula na matrix de distancias
                aux[item.x + 1][item.y] = dist
        # Verifica se a célula esquerda da posição atual é válida para calcular a distância
        if item.y > 0:
            # Verifica se o valor da célula a esquerda é maior que o da atual e se é caminho
            if aux[item.x][item.y - 1] > aux[item.x][item.y] + 1 and m[item.x][item.y - 1] != 1:
                # Adiciona o nó e a sua distância do início na lista
                list_prior.append((dist, (item.x, item.y - 1)))
                # Seta a distância da célula na matrix de distancias
                aux[item.x][item.y - 1] = dist
        # Verifica se a célula direita da posição atual é válida para calcular a distância
        if item.y < len(m[0]) - 1:
            # Verifica se o valor da célula a direita é maior que o da atual e se é caminho
            if aux[item.x][item.y + 1] > aux[item.x][item.y] + 1 and m[item.x][item.y + 1] != 1:
                # Adiciona o nó e a sua distância do início na lista
                list_prior.append((dist, (item.x, item.y + 1)))
                # Seta a distçkkância da célula na matrix de distancias
                aux[item.x][item.y + 1] = dist
        # Marca a posição como visitada
        cont+=1

    print(cont)

    shortPath(aux, dest, source)

def shortPath(aux, dest, source):
    
    # Seta o ponto atual com o destino (segue o caminho reverso para achar o menor caminho)
    now = Point(dest.x, dest.y)

    # Lista que guarda o caminho até o destino
    list_way=[]
    list_way.append((now.x, now.y))

    if aux[now.x][now.y] != 999:

        while (now.x, now.y) != (source.x, source.y):

            # Guarda a informação se foi encontrado um valor vizinho menor para se mover
            find = False
    
            # Move pra cima se o valor é menor 
            if now.x > 0 and not find:
                if(aux[now.x - 1][now.y] < aux[now.x][now.y]):
                    now = Point(now.x - 1, now.y)
                    list_way.append((now.x, now.y))
                    find = True
            # Move pra baixo se o valor é menor
            if now.x < len(aux) - 1 and not find:
                if(aux[now.x + 1][now.y] < aux[now.x][now.y]):
                    now = Point(now.x + 1, now.y)
                    list_way.append((now.x, now.y))
                    find = True
            # Move pra esquerda se o valor é menor
            if now.y > 0 and not find:
                if(aux[now.x][now.y - 1] < aux[now.x][now.y]):
                    now = Point(now.x, now.y - 1)
                    list_way.append((now.x, now.y))
                    find = True
            # Move pra direita se o valor é menor
            if now.y < len(aux[0]) - 1 and not find:
                if(aux[now.x][now.y + 1] < aux[now.x][now.y]):
                    now = Point(now.x, now.y + 1)
                    list_way.append((now.x, now.y))
                    find = True
            # Se não encontrou nenhum valor vizinho menor que a célula atual não há caminho
            if(find == False):
                res = "NÃO TEM CAMINHO PARA O DESTINO"
                break
            else:
                res = "O MENOR CAMINHO PARA O DESTINO E:"
    
        print(res)
        print(list_way) 
        print("==================================================")
    else:
        print("O PONTO DE DESTINO É INVÁLIDO")

def main():
    m = [[0, 0, 0, 0 ],
        [0, 1, 1, 0 ],
        [1, 1, 0, 0 ],
        [0, 0, 0, 0 ],
        [0, 0, 1, 0 ]]

    aux =[[999, 999, 999, 999 ],
        [999, 999, 999, 999 ],      
        [999, 999, 999, 999 ],
        [999, 999, 999, 999 ],
        [999, 999, 999, 999 ]]

    #m = [[0, 0, 0],
    ##    [0, 0, 0],
    #    [0, 0, 0]
    #]

    #aux = [[9, 9, 9],
    #    [9, 9, 9],
    #    [9, 9, 9]
    #]

    source = Point(0, 0)
    dest = Point(4, 3)

    calc_dist(m, aux, source, dest)

    for row in aux:
        print(row)
      
main()
 