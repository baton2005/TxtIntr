#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

void printUsage() {
    std::cout << "Использование: calculator -o <operation> <operand1> <operand2> <operand3> [<operand4>] [<operand5>]\n";
    std::cout << "Поддерживаемые операции:\n";
    std::cout << "  summa - сложение\n";
    std::cout << "  minus - вычитание (из первого операнда всех остальных)\n";
    std::cout << "Количество операндов: от 3 до 5.\n";
}

double sum(const std::vector<double>& operands) {
    double result = 0;
    for (double num : operands) {
        result += num;
    }
    return result;
}

double subtract(const std::vector<double>& operands) {
    double result = operands[0];
    for (size_t i = 1; i < operands.size(); ++i) {
        result -= operands[i];
    }
    return result;
}

int main(int argc, char* argv[]) {
    if (argc < 6) { // Минимум 6 аргументов: программа, операция и три операнда
        printUsage();
        return 1;
    }

    std::string operation;
    std::vector<double> operands;

    for (int i = 1; i < argc; ++i) {
        if (std::string(argv[i]) == "-o" || std::string(argv[i]) == "--operation") {
            if (i + 1 < argc) {
                operation = argv[++i];
            } else {
                printUsage();
                return 1;
            }
        } else {
            // Преобразуем аргументы в числа и добавляем в вектор
            double operand = std::atof(argv[i]);
            operands.push_back(operand);
        }
    }

    // Проверка количества операндов
    if (operands.size() < 3 || operands.size() > 5) {
        printUsage();
        return 1;
    }

    double result;

    if (operation == "summa") {
        result = sum(operands);
        std::cout << "Результат сложения: " << result << std::endl;
    } else if (operation == "minus") {
        result = subtract(operands);
        std::cout << "Результат вычитания: " << result << std::endl;
    } else {
        printUsage();
        return 1;
    }

    return 0;
}
