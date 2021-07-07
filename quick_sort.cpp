#include <iostream>

void QuickSort(int * input_array, int start, int end) {
	// input_array���� start���� end���� �������ִ� �ڵ�

	if (start >= end) {
		// ���Ұ� 1���̰ų� ������ ���� �׳� ����
		return;
	}

	int pivot = start;
	int find_big = start + 1;
	int find_small = end;

	while (true)
	{
		while (find_big <= end && input_array[find_big] < input_array[pivot])
		{
			// input_array[pivot]���� ū ���Ҹ� ���ʿ��� ���������� �̵��ϸ� ã�´�
			find_big++;
		}

		while (find_small > start && input_array[find_small] > input_array[pivot])
		{
			// input_array[pivot]���� ���� ���Ҹ� �����ʿ��� �������� �̵��ϸ� ã�´�
			find_small--;
		}

		if (find_big < find_small) {
			// find_big�� find_small�� �������� �ʾ��� ��쿡�� ���� ���ϴ� ���� ã�� ���̹Ƿ� ���� �ٲ�
			int temp = input_array[find_big];
			input_array[find_big] = input_array[find_small];
			input_array[find_small] = temp;
		}
		else {
			// ���� �������� ��쿡�� �ݺ��� ���ͼ� pivot�̶� find_small �ٲ��ֱ�
			break;
		}
	}

	// pivot�� find_small�ٲ���
	int temp = input_array[pivot];
	input_array[pivot] = input_array[find_small];
	input_array[find_small] = temp;


	// ���� pivot ��ġ �������� ���ʿ� ���� ��������� ������ ����
	QuickSort(input_array, start, find_small - 1);
	QuickSort(input_array, find_small + 1, end);
}

int main(void) {
	int input[9] = { 2,1,6,33,28,18,9,46,4 };
	QuickSort(input,0,8);
	return 0;
}