void F_1 ( struct V_1 * * V_2 , int V_3 )
{
int V_4 = 0 ;
while ( V_2 [ V_4 ] && V_3 -- ) {
F_2 ( V_2 [ V_4 ] ) ;
V_4 ++ ;
}
}
int F_3 ( char * V_5 , int V_6 )
{
unsigned long V_7 , V_8 ;
V_7 = ( unsigned long ) V_5 >> V_9 ;
V_8 = ( ( unsigned long ) V_5 + V_6 + V_10 - 1 ) >> V_9 ;
return V_8 - V_7 ;
}
int F_4 ( char * V_5 , int * V_3 , struct V_1 * * V_2 , int V_11 )
{
int V_12 ;
V_12 = F_5 ( ( unsigned long ) V_5 ,
* V_3 , V_11 , V_2 ) ;
if ( V_12 <= 0 )
return V_12 ;
* V_3 = V_12 ;
return 0 ;
}
