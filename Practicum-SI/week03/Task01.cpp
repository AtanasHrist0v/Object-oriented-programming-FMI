#include <iostream>
#include <fstream>

struct Example {
	int data;
	char buff[8];
};

void ReadExample(Example& example) {
	std::cin >> example.data;
	std::cin.ignore();
	std::cin.getline(example.buff, sizeof(example.buff));
}

void SaveExamplesToFile(const char* filePath, const Example* array, int arraySize) {
	if (filePath == nullptr || array == nullptr) {
		return;
	}

	std::ofstream ofs(filePath, std::ios::out | std::ios::binary | std::ios::app);

	if (!ofs.is_open()) {
		return;
	}
		
	ofs.write((const char*)array, sizeof(Example) * arraySize);
	ofs.close();
}

int main() {
	int n = 0;
	std::cin >> n;
	std::cin.ignore();

	Example* array = new Example[n]{};

	for (size_t i = 0; i < n; i++) {
		ReadExample(array[i]);
	}
	
	char filePath[1024]{};
	std::cin.getline(filePath, 1024);

	SaveExamplesToFile(filePath, array, n);

	delete[] array;
	return 0;
}