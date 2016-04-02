// RUN: mkdir -p %T/Inputs/
// RUN: clang-typegrind %s --
// RUN: sed -i 's/\/\/.*//' %T/Inputs/array_new.cpp 
// RUN: FileCheck -input-file=%T/Inputs/array_new.cpp %s

int main(void)
{
  // CHECK: int* pT = TYPEGRIND_LOG_NEW_ARRAY("{{.*}}/clang-typegrind/test/array_new.cpp:9", "int", "int", sizeof(int), 53, new int[53]);
  int* pT = new int[53];
  return 0;
}
