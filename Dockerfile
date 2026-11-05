# --- ЭТАП 1: Сборка ---
FROM ubuntu:22.04 AS builder

# Устанавливаем компилятор и CMake
RUN apt-get update && apt-get install -y cmake g++ && rm -rf /var/lib/apt/lists/*

WORKDIR /app
COPY . .

# ВАЖНО: Собираем только исполняемый файл программы, 
# игнорируя тесты (чтобы не требовать GTest)
RUN cmake -B build -DCMAKE_BUILD_TYPE=Release && cmake --build build --target matrix_calculator

# --- ЭТАП 2: Запуск ---
FROM ubuntu:22.04

WORKDIR /app
COPY --from=builder /app/build/matrix_calculator .

CMD ["./matrix_calculator"]