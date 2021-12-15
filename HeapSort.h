void siftDown(vector<int>& arr, int root, int bottom)
{
	int maxChild; 
	while (root * 2 < bottom)
	{
		if (root * 2 == bottom) {
			maxChild = root * 2;
		}
		else if (arr[root * 2] > arr[root * 2 + 1]) {
			maxChild = root * 2;
		}
		else
			maxChild = root * 2 + 1;
	
		if (arr[root] < arr[maxChild])
		{

			int temp = arr[root];
			arr[root] = arr[maxChild];
			arr[maxChild] = temp;
			root = maxChild;
		}
		else
			break;
	}
}
void heapSort(vector<int> &arr)
{
	for (int i = (arr.size() / 2) - 1; i >= 0; i--)
		siftDown(arr, i, arr.size());
	for (int i = arr.size() - 1; i >= 1; i--)
	{
		int temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		siftDown(arr, 0, i - 1);
	}
}