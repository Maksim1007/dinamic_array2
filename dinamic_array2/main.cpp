#include <iostream>

void print_dynamic_array(int* arr, int logical_size, int actual_size)
{
    std::cout << "Динамический массив: ";
    for (int i = 0; i < actual_size; ++i)
    {
        if (i < logical_size) 
        {
            std::cout << arr[i] << " ";
        }
        else
        {
            std::cout << "_ ";
        }
    }
    std::cout << std::endl;
}

int* remove_dynamic_array_head(int* arr, int& logical_size, int& actual_size)
{
    if (logical_size <= 0)
    {
        std::cout << "Невозможно удалить первый элемент, так как массив пустой." << std::endl;
        return arr;
    }

    if (logical_size - 1 > actual_size / 3) 
    {
        for (int i = 1; i < logical_size; ++i)
        {
            arr[i - 1] = arr[i];
        }
        logical_size--; 
        return arr;
    }
    else 
    {
        int new_actual_size = actual_size / 3;
        int* new_arr = new int[new_actual_size];

        for (int i = 1; i < logical_size; ++i)
        {
            new_arr[i - 1] = arr[i];
        }
        logical_size--; 

        delete[] arr;
        actual_size = new_actual_size;

        return new_arr;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int actual_size;
    std::cout << "Введите фактический размер массива: ";
    std::cin >> actual_size;

    int* arr = new int[actual_size]; 
    int logical_size;

    std::cout << "Введите логический размер массива: ";
    std::cin >> logical_size;

    if (logical_size > actual_size)
    {
        std::cout << "Ошибка! Логический размер не может превышать фактический размер." << std::endl;
        delete[] arr; 
        return 1; 
    }

    for (int i = 0; i < logical_size; ++i)
    {
        std::cout << "Введите arr[" << i << "]: ";
        std::cin >> arr[i];
    }

    print_dynamic_array(arr, logical_size, actual_size);

    while (true)
    {
        std::string response;
        std::cout << "Удалить первый элемент? (yes/no): ";
        std::cin >> response;

        if (response == "no") {
            std::cout << "Спасибо! Ваш массив: ";
            print_dynamic_array(arr, logical_size, actual_size);
            break;
        }
        else if (response == "yes")
        {
            arr = remove_dynamic_array_head(arr, logical_size, actual_size);
            print_dynamic_array(arr, logical_size, actual_size);
            if (logical_size == 0)
            {
                std::cout << "Невозможно удалить первый элемент, так как массив пустой. До свидания!" << std::endl;
                break;
            }
        }
        else
        {
            std::cout << "Некорректный ввод. Пожалуйста, введите 'yes' или 'no'." << std::endl;
        }
    }
    delete[] arr;

    return 0;
}
