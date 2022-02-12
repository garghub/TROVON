void func(a,b)
TYPE *a;
TYPE b;
{
printf("%ld -1 == %ld\n",a[0],b);
}
main()
{
TYPE data[5]={1L,2L,3L,4L,5L};
TYPE *p;
int i;
p=data;
for (i=0; i<4; i++)
{
func(p,*(p++));
}
}
