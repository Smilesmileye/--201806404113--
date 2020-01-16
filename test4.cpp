public class FirstKElements
{
	public static TreeSet<Integer>getFirstKElements(int arr[],int k)
	{
		TreeSet<Integer>set=new TreeSet<Iterable>();
		int len=arr.length;
		k=k%len;
		int i=0;
		int num=0;
		for(i=0;i<k;i++)
			set.add(arr[i]);
		for(i=k;i<len;i++)
		{
			set.add(arr[i]);
			num=set.last();
			set.remove(num);
		}
		return set;
	}
	public static void main(String[] args)
	{
		int arr[]={9,7,5,4,2,1,3,6,8};
		System.out.println(FirstKElements.getFirstKElements(arr,4));
	}
}
