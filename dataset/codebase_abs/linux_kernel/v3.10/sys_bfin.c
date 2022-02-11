T_1 void * F_1 ( T_2 V_1 , unsigned long V_2 )
{
return F_2 ( V_1 , V_2 ) ;
}
T_1 int F_3 ( const void * V_3 )
{
return F_4 ( V_3 ) ;
}
T_1 void * F_5 ( void * V_4 , const void * V_5 , T_2 V_6 )
{
return F_6 ( V_4 , V_5 , V_6 ) ;
}
unsigned long F_7 ( struct V_7 * V_8 , unsigned long V_9 ,
unsigned long V_6 , unsigned long V_10 , unsigned long V_2 )
{
struct V_11 * V_12 = V_8 -> V_13 ;
return ( unsigned long ) V_12 -> V_14 ;
}
T_1 int F_8 ( int * V_15 )
{
int V_16 , V_17 = 0 ;
F_9 ( & V_18 ) ;
V_16 = F_10 ( V_17 , V_15 ) ;
if ( F_11 ( V_16 == 0 ) ) {
if ( F_12 ( V_17 ) )
V_16 = 1 ;
else
F_13 ( 1 , V_15 ) ;
}
F_14 ( & V_18 ) ;
return V_16 ;
}
