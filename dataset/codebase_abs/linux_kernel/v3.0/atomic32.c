int F_1 ( int V_1 , T_1 * V_2 )
{
int V_3 ;
unsigned long V_4 ;
F_2 ( F_3 ( V_2 ) , V_4 ) ;
V_3 = ( V_2 -> V_5 += V_1 ) ;
F_4 ( F_3 ( V_2 ) , V_4 ) ;
return V_3 ;
}
int F_5 ( T_1 * V_2 , int V_6 , int V_7 )
{
int V_3 ;
unsigned long V_4 ;
F_2 ( F_3 ( V_2 ) , V_4 ) ;
V_3 = V_2 -> V_5 ;
if ( F_6 ( V_3 == V_6 ) )
V_2 -> V_5 = V_7 ;
F_4 ( F_3 ( V_2 ) , V_4 ) ;
return V_3 ;
}
int F_7 ( T_1 * V_2 , int V_8 , int V_9 )
{
int V_3 ;
unsigned long V_4 ;
F_2 ( F_3 ( V_2 ) , V_4 ) ;
V_3 = V_2 -> V_5 ;
if ( V_3 != V_9 )
V_2 -> V_5 += V_8 ;
F_4 ( F_3 ( V_2 ) , V_4 ) ;
return V_3 != V_9 ;
}
void F_8 ( T_1 * V_2 , int V_1 )
{
unsigned long V_4 ;
F_2 ( F_3 ( V_2 ) , V_4 ) ;
V_2 -> V_5 = V_1 ;
F_4 ( F_3 ( V_2 ) , V_4 ) ;
}
unsigned long F_9 ( unsigned long * V_10 , unsigned long V_11 )
{
unsigned long V_6 , V_4 ;
F_2 ( F_3 ( V_10 ) , V_4 ) ;
V_6 = * V_10 ;
* V_10 = V_6 | V_11 ;
F_4 ( F_3 ( V_10 ) , V_4 ) ;
return V_6 & V_11 ;
}
unsigned long F_10 ( unsigned long * V_10 , unsigned long V_11 )
{
unsigned long V_6 , V_4 ;
F_2 ( F_3 ( V_10 ) , V_4 ) ;
V_6 = * V_10 ;
* V_10 = V_6 & ~ V_11 ;
F_4 ( F_3 ( V_10 ) , V_4 ) ;
return V_6 & V_11 ;
}
unsigned long F_11 ( unsigned long * V_10 , unsigned long V_11 )
{
unsigned long V_6 , V_4 ;
F_2 ( F_3 ( V_10 ) , V_4 ) ;
V_6 = * V_10 ;
* V_10 = V_6 ^ V_11 ;
F_4 ( F_3 ( V_10 ) , V_4 ) ;
return V_6 & V_11 ;
}
unsigned long F_12 ( volatile T_2 * V_12 , T_2 V_6 , T_2 V_7 )
{
unsigned long V_4 ;
T_2 V_13 ;
F_2 ( F_3 ( V_12 ) , V_4 ) ;
if ( ( V_13 = * V_12 ) == V_6 )
* V_12 = V_7 ;
F_4 ( F_3 ( V_12 ) , V_4 ) ;
return ( unsigned long ) V_13 ;
}
