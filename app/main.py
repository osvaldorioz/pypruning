from fastapi import FastAPI
import pruning_matvec
import time
from pydantic import BaseModel
from typing import List
import json

app = FastAPI()

# Definir el modelo para la matriz
class Matrix(BaseModel):
    matrix: List[List[float]]

# Definir el modelo para el vector
class VectorF(BaseModel):
    vector: List[float]

# Definir el modelo para el vector
class VectorI(BaseModel):
    vector: List[int]

@app.post("/pruning")
async def matvec(m: Matrix,
                    v: VectorF,
                    threshold: float):
    start = time.time()
    
    # Multiplicar matriz por vector con pruning
    result = pruning_matvec.pruned_matrix_vector_multiplication(m.matrix, 
                                                                v.vector, 
                                                                threshold)
    
    end = time.time()

    var1 = end - start

    j1 = {
        "Time taken in seconds": var1,
        "Matriz ": m.matrix,
        "Vector ": v.vector,
        "resultado": result
    }
    jj = json.dumps(j1)

    return jj