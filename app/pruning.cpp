#include <vector>
#include <stdexcept>
#include <cmath>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

//c++ -O2 -shared -std=c++20 -fPIC $(python3.12 -m pybind11 --includes) pruning.cpp -o pruning_matvec$(python3.12-config --extension-suffix)

namespace py = pybind11;

// Función para multiplicar una matriz por un vector, con pruning
std::vector<double> pruned_matrix_vector_multiplication(
    const std::vector<std::vector<double>>& matrix,
    const std::vector<double>& vector,
    double threshold) 
{
    size_t rows = matrix.size();
    if (rows == 0) {
        throw std::invalid_argument("Matrix cannot be empty");
    }

    size_t cols = matrix[0].size();
    if (vector.size() != cols) {
        throw std::invalid_argument("Matrix column count must match vector size");
    }

    std::vector<double> result(rows, 0.0);

    // Realizar multiplicación con pruning
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            // Aplicar pruning: ignorar valores absolutos menores al umbral
            if (std::abs(matrix[i][j]) > threshold) {
                result[i] += matrix[i][j] * vector[j];
            }
        }
    }

    return result;
}

// Vincular la función usando pybind11
PYBIND11_MODULE(pruning_matvec, m) {
    m.doc() = "Pruned matrix-vector multiplication example with pybind11";
    m.def(
        "pruned_matrix_vector_multiplication",
        &pruned_matrix_vector_multiplication,
        py::arg("matrix"),
        py::arg("vector"),
        py::arg("threshold"),
        "Multiply a matrix and vector with pruning (ignoring small values)"
    );
}
