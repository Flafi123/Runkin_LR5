#include "CUTE/cute/cute.h"
#include "CUTE/cute/cute_runner.h"
#include "CUTE/cute/ide_listener.h"

// подключение модуля с тестируемыми методами
#include "Runkin_MathTask.h"
using namespace std;

void testCalcRectangleArea() {
  // входные значения
  int a = 3;
  int b = 5;
  // ожидаемый результат
  int expected = 15;

  // получение значения с помощью тестируемого метода
  int actual = CalcRectangleArea(a, b);

  // сравнение ожидаемого результата с полученным
  ASSERT_EQUAL(expected, actual);
}

int main() {
  /**/ // Создаем тестовый набор
  cute::suite s;
  // Добавляем тестовую функцию в набор
  s.push_back(CUTE(testCalcRectangleArea));
  // Создаем listener и runner
  cute::ide_listener<> listener;
  makeRunner(listener)(s, "Test CalcRectangleArea");
  return 0;
}