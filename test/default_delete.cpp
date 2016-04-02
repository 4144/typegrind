// RUN: mkdir -p %T/Inputs/
// RUN: clang-typegrind %s --
// RUN: sed -i 's/\/\/.*//' %T/Inputs/default_delete.cpp 
// RUN: FileCheck -input-file=%T/Inputs/default_delete.cpp %s

int main(void)
{
  int* pT = 0;
  // CHECK: delete TYPEGRIND_LOG_DELETE("{{.*}}/clang-typegrind/test/default_delete.cpp:10", "int", "int", pT);
  delete pT;
  return 0;
}
