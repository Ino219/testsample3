#include "MyForm.h"

using namespace testsample3;

[STAThreadAttribute]
int main() {
	Application::Run(gcnew MyForm());
	return 0;
}
