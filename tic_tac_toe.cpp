#include <iostream>
using namespace std;

int board[9] = {2, 2, 2, 2, 2, 2, 2, 2, 2};

void display()
{
    for (int i = 1; i <= 9; i++)
    {
        if (board[i - 1] == 2)
            cout << "_ ";
        else if (board[i - 1] == 3)
            cout << "X ";
        else if (board[i - 1] == 5)
            cout << "O ";

        if (i % 3 == 0)
            cout << endl;
    }
    cout << endl;
} 
int make2()
{
   if (board[4] == 2)
        return 4;
    else if (board[1] == 2)
        return 1;
    else if (board[3] == 2)
        return 3;
    else if (board[5] == 2)
        return 5;
    else if (board[7] == 2)
        return 7;
    else
        return -1;
}

int poswin(int n)
{
    int a;

    if (n == 1)
        a = 18;
    else if (n == 0)
        a = 50;

    for (int i = 1; i <= 3; i++)
    {
        int b = i * 3;
        if (board[b - 3] * board[b - 2] * board[b - 1] == a)
        {
            if (board[b - 3] == 2)
                return b - 3;
            else if (board[b - 2] == 2)
                return b - 2;
            else
                return b - 1;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        if (board[i] * board[i + 3] * board[i + 6] == a)
        {
            if (board[i] == 2)
                return i;
            else if (board[i + 3] == 2)
                return i + 3;
            else
                return i + 6;
        }
    }

    if (board[0] * board[4] * board[8] == a)
    {
        if (board[0] == 2)
            return 0;
        else if (board[4] == 2)
            return 4;
        else
            return 8;
    }
    else if (board[2] * board[4] * board[6] == a)
    {
        if (board[2] == 2)
            return 2;
        else if (board[4] == 2)
            return 4;
        else
            return 6;
    }
    else
        return -1;
}

int checkwin(int n)
{
    int a;

    if (n == 1)
        a = 27;
    else if (n == 0)
        a = 125;

    for (int i = 1; i <= 3; i++)
    {
        int b = i * 3;
        if (board[b - 3] * board[b - 2] * board[b - 1] == a)
            return a;
    }

    for (int i = 0; i < 3; i++)
    {
        if (board[i] * board[i + 3] * board[i + 6] == a)
            return a;
    }

    if (board[0] * board[4] * board[8] == a)
        return a;
    else if (board[2] * board[4] * board[6] == a)
        return a;
    else
        return -1;
}

void go(int i, int turn)
{
    if (turn % 2 == 0)
        board[i] = 5;
    else
        board[i] = 3;
}

void computer(int turn)
{
    switch (turn)
    {
    case 1:
        go(0,1);
        break;

    case 2:
        if (board[4] == 2)
            go(4,2);
        else
            go(0,2);
        break;

    case 3:
        if (board[8] == 2)
            go(8,3);
        else
            go(2,3);
        break;

    case 4:
        if (poswin(1) != -1)
            go(poswin(1), 4);
        else
            go(make2(), 4);
        break;

    case 5:
        if (poswin(1) != -1)
            go(poswin(1), 5);
        else if (poswin(0) != -1)
            go(poswin('o'), 5);
        else if (board[6] == 2)
            go(6, 5);
        else
            go(2, 5);
        break;

    case 6:
        if (poswin(0) != -1)
            go(poswin(0), 6);
        else if (poswin(1) != -1)
            go(poswin(1), 6);
        else
            go(make2(), 6);
        break;

    case 7:
        if (poswin(1) != -1)
            go(poswin(1), 7);
        else if (poswin(0) != -1)
            go(poswin(0), 7);
        else
        {
            for (int i = 0; i < 9; i++)
            {
                if (board[i] == 2)
                {
                    go(i, 7);
                    break;
                }
            }
        }
        break;
        
    case 8:
        if (poswin(0) != -1)
            go(poswin(0), 8);
        else if (poswin(1) != -1)
            go(poswin(1), 8);
        else
        {
            for (int i = 0; i < 9; i++)
            {
                if (board[i] == 2)
                {
                    go(i, 8);
                    break;
                }
            }
        }
        break;

    case 9:
        if (poswin(1) != -1)
            go(poswin(1), 9);
        else if (poswin(0) != -1)
            go(poswin(0), 9);
        else
        {
            for (int i = 0; i < 9; i++)
            {
                if (board[i] == 2)
                {
                    go(i, 9);
                    break;
                }
            }
        }
        break;
    }
}

void user(int turn)
{
    cout << "Enter the box number: " << endl;
    int num;
    cin >> num;
    cout << endl;

    if (board[num - 1] != 2)
    {
        cout << "Invalid box" << endl;
        user(turn);
    }
    else
        go(num - 1, turn);
}

int main()
{
    int turn = 1;

    int choice = 1;
   

    display();

    if (choice == 0)
    {
        while (turn <= 9 && checkwin(1) == -1 && checkwin(0) == -1)
        {
            computer(turn);
            display();

            if (checkwin(1) != -1)
                break;
            cout << endl;
            turn++;

            if (turn >= 9)
                break;
            cout << endl;

            if (turn >= 9)
                break;

            user(turn);
            turn++;

            display();
            cout << endl;
        }
    }
    else if (choice == 1)
    {
        while (turn <= 9 && checkwin(1) == -1 && checkwin(0) == -1)
        {
            user(turn);
            display();

            if (checkwin(1) != -1)
                break;
            cout << endl;
            turn++;
            cout << endl;

            computer(turn);
            if (checkwin(0) != -1)
                break;
            turn++;
            display();

            cout << endl;
        }
    }
    else
    {
        cout << "Invalid Choice";
        return 0;
    }

    if (checkwin(0) == 125)
    {
        if (choice == 0)
            cout << "User Wins!!!" << endl;
        else
            cout << "Computer Wins!!!" << endl;
    }
    else if (checkwin(1) == 27)
    {
        if (choice == 0)
            cout << "Computer Wins!!!" << endl;
        else
            cout << "User Wins!!!" << endl;
    }
    else
        cout << "Draw!!!" << endl;

    return 0;
}