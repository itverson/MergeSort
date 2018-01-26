void MergeSort(int *arr, int left, int mid, int right, int *temp)
{
	int begin1 = left;
	int begin2 = mid + 1;
	int index = left;
	while (begin1 <= mid&&begin2 <= right)
	{
		if (arr[begin1] > arr[begin2])
			temp[index++] = arr[begin2++];
		else
			temp[index++] = arr[begin1++];
	}
	//����ѭ�������Ժ�֤����һ�������Ѿ������ˣ�Ӧ�û�ʣһ�飬��������ʣ������Ҳ�Ž�ȥ���������ǲ�֪��ʣ�����������Ծ�����whileѭ���ж�  
	while (begin1 <= mid)
	{
		temp[index++] = arr[begin1++];
	}
	while (begin2 <= right)
	{
		temp[index++] = arr[begin2++];
	}
	/*while (left <= right)//����1
	{
	arr[left] = temp[left++];
	}*/
	memcpy(arr + left, temp + left, sizeof(int)*(right - left + 1));//����2  
}
void Merge(int *arr, int left, int right, int *temp)
{
	if (left < right)
	{
		int mid = ((right - left) >> 1) + left;
		Merge(arr, left, mid, temp);
		Merge(arr, mid + 1, right, temp);
		MergeSort(arr, left, mid, right, temp);
	}
}
void MergeNor(int *arr, int left, int right, int *temp)
{
	int gap = 1;
	while (gap <= right)//�����ܵ�����  
	{
		for (int i = 0; i <right; i += 2 * gap)
		{
			int begin = i;
			int mid = i + gap - 1;
			int end = mid + gap;
			if (end>right)
			{
				end = right;
			}
			MergeSort(arr, begin, mid, end, temp);
		}
		gap = 2 * gap;
	}
}
int main()
{
	int arr[] = { 2, 6, 9, 4, 8, 7, 1, 3, 5 };
	int size = sizeof(arr) / sizeof(*arr);
	int *tmp = new int[size];
	//Merge(arr, 0, size - 1, tmp);  
	MergeNor(arr, 0, size - 1, tmp);
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "";
	}
	delete[] tmp;
	system("pause");
	return 0;
}