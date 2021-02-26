#include "MyForm.h"
using namespace System::Windows::Forms;

int main() {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	Application::Run(gcnew QueensGame::MyForm);
}