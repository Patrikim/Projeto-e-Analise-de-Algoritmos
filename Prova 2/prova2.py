
class Point:
    def __init__(self,x: int, y: int):
        self.x = x
        self.y = y

def dijkstra(m, aux, source, dest):

    aux[source.x][source.y] = 0
    listapri=[]
    visited=[]

    listapri.append((0, (source.x, source.y)))
    aux[source.x][source.y] = 0
    
    while len(listapri) > 0:

        element = listapri.pop(0)
        dist = element[0]
        position = element[1]
        item = Point(position[0], position[1])
        dist=dist+1

        if(position not in visited):
            #guarda o ponto de cima e seta distancia
            if item.x > 0:
                if(aux[item.x - 1][item.y] > aux[item.x][item.y]) and aux[item.x - 1][item.y] != -1:
                    listapri.append(dist, (item.x - 1, item.y))
                    aux[item.x - 1][item.y] = dist
            #guarda o ponto de baixo e seta distancia
            if item.x < len(m) - 1:
                if(aux[item.x + 1][item.y] > aux[item.x][item.y]):
                    listapri.append((dist, (item.x + 1, item.y)))
                    aux[item.x + 1][item.y] = dist
            #guarda o ponto da esquerda e seta distancia
            if item.y > 0:
                if(aux[item.x][item.y - 1] > aux[item.x][item.y]):
                    listapri.append((dist, (item.x, item.y - 1)))
                    aux[item.x][item.y - 1] = dist
            #guarda o ponto da direita e seta distancia
            if item.y < len(m[0]) - 1:
                if(aux[item.x][item.y + 1] > aux[item.x][item.y]):
                    listapri.append((dist, (item.x, item.y + 1)))
                    aux[item.x][item.y + 1] = dist

            visited.append(position)
            print("visiteds")
            print(visited)
            print("postion")
            print(position)
            print(aux)

    return 0


def main():
    #m = [[0, 0, 0, 0 ],
    #    [0, 1, 1, 0 ],
    #    [1, 1, 0, 0 ],
    #    [0, 0, 0, 0 ],
    #    [0, 0, 1, 0 ]]

    #aux =[[9, 9, 9, 9 ],
    #    [9, 9, 9, 9 ],
    #   [9, 9, 9, 9 ],
    #   [9, 9, 9, 9 ],
    #    [9, 9, 9, 9 ]]

    m = [[0, 0, 0],
        [0, 0, 0],
        [0, 0, 0]
    ]

    aux = [[9, 9, 9],
        [9, 9, 9],
        [9, 9, 9]
    ]

    print(len(m), len(m[0]))
    
    source = Point(0, 0)
    dest = Point(4, 3)

    dijkstra(m, aux, source, dest)
      
main()
 