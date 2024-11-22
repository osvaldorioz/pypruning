Pruning: Es una técnica para simplificar cálculos eliminando valores insignificantes (como pesos pequeños en matrices o redes neuronales), reduciendo el costo computacional y almacenamiento 
sin afectar significativamente la precisión.

Multiplicación de Matriz por Vector: Es la operación donde cada elemento del resultado es una combinación lineal de las filas de la matriz y los valores del vector. Sirve en álgebra lineal, 
gráficos, y aprendizaje automático.

En pruning aplicado a multiplicación, solo se consideran los valores de la matriz que superan un umbral determinado para optimizar el rendimiento.

Explicación del Código

    Entrada:
        matrix: Una matriz bidimensional representada como un vector de vectores.
        vector: Un vector unidimensional.
        threshold: Umbral de pruning. Los valores absolutos menores a este umbral se ignoran.

    Operación de Pruning:
        Se realiza una comparación (std::abs(matrix[i][j]) > threshold) para filtrar los valores insignificantes.

    Multiplicación:
        La multiplicación se realiza únicamente para los valores que no han sido eliminados por el pruning.
