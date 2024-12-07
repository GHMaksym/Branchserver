# Базовий образ
FROM gcc:latest

# Копіюємо проект до контейнера
WORKDIR /app
COPY . .

# Встановлюємо залежності та будуємо проект
RUN apt-get update && apt-get install -y libboost-all-dev
RUN g++ -std=c++17 -o http_server src/http_server.cpp src/MyClass.cpp

# Відкриваємо порт для HTTP-сервера
EXPOSE 8080

# Запускаємо сервер
CMD ["./http_server"]
