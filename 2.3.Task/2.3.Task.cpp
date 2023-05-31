#include <cstdlib>
#include <iostream>
#define N 8

using namespace std;

//матрица смежности для графа #1
int G[N][N] =
{
{0, 1, 0, 0, 0, 0, 0, 1},
{1, 0, 1, 0, 0, 1, 0, 0},
{0, 1, 0, 1, 0, 1, 0, 0},
{0, 0, 1, 0, 0, 0, 1, 0},
{0, 0, 0, 0, 0, 0, 1, 0},
{0, 1, 1, 0, 0, 0, 0, 1},
{0, 0, 0, 1, 1, 0, 0, 1},
{1, 0, 0, 0, 0, 1, 1, 0},
};

////матрица смежности для графа #2
//int G[N][N] =
//{
//{0, 1, 0, 0, 1, 0, 0, 0},
//{1, 0, 1, 0, 1, 0, 0, 0},
//{0, 1, 0, 1, 0, 0, 0, 0},
//{0, 0, 1, 0, 0, 0, 0, 0},
//{1, 1, 0, 0, 0, 0, 0, 0},
//{0, 0, 0, 0, 0, 0, 1, 1},
//{0, 0, 0, 0, 0, 1, 0, 1},
//{0, 0, 0, 0, 0, 1, 1, 0},
//};
bool visited[N];//массив посещенных вершин 
int start = 0, vihod = 0;//точки старта и  выхода

bool dfs(int u, int prev) {
    
    cout << u << " ";
    if (u == vihod)//если вершина равна выходу
    {
        return true;
    }
    if (visited[u])//если попали в цикл 
    {
        return false;
    }
    visited[u] = true;
    for (int i = 0; i < N; i++) {

        if (G[u][i] && i != prev)//если есть смежная и она не является предыдушей
        {
            if (!dfs(i, u))
            {
                return false;
            }
            else
            {
                return true;
            }
        }
    }
    return false;
}


int next (int i, int cur)
{
    cur++;
    while (cur<N && !G[i][cur]) cur++;
    if (cur<N) return cur;
    return -1;
}

bool DFSR (int u, int prev)
{
	int y;
    cout << u << " ";
    if (u == vihod)//если вершина равна выходу
    {
        return true;
    }
    if (visited[u])//если попали в цикл 
    {
        return false;
    }
    visited[u] = true;


	y = next (u, -1);
    while (y != -1)  //пока есть смежные вершины
	{
        if(y != prev)
        {
            if (!DFSR(y, u))
            {
                return false;
            }
            else
            {
                return true;
            }
        }
       
        y = next (u, y); //переходим к следующей вершине
    }
    return false;
}

int check_value()
{
    int x = 0;
    while (!(std::cin >> x) || x < 0 || x > N-1)
    {
        std::cout << "Вы ввели некорректное значение! Попробуйте еще раз:\n->";
        std::cin.clear();
        while (std::cin.get() != '\n');
    }
    return x;
}

int main()
{
    setlocale(LC_ALL, "rus");
    cout << "Введите точку начала пути:\n->";
    start = check_value();
    cout << "Введите точку конца пути:\n->";
    vihod = check_value();
    std::cout << "Путь:\n";
    if (dfs(start, -1))
    {
        std::cout << "\nДиггер вышел из пишеры!\n";
    }
    else
    {
        std::cout << "\nДиггер не смог выйти из пищеры :(\n";
    }
   
    return 0;
}
