static int F_1 ( struct V_1 * V_1 , unsigned int V_2 ,
unsigned long V_3 )
{
struct V_4 V_5 ;
T_1 T_2 * V_6 ;
if ( F_2 ( & V_5 , ( void T_2 * ) V_3 , sizeof( V_5 ) ) )
return - V_7 ;
V_6 = F_3 ( sizeof( * V_6 ) ) ;
if ( ! F_4 ( V_8 , V_6 , sizeof( * V_6 ) )
|| F_5 ( V_5 . V_9 , & V_6 -> V_9 )
|| F_5 ( ( void T_2 * ) ( unsigned long ) V_5 . V_10 ,
& V_6 -> V_10 ) )
return - V_7 ;
return F_6 ( V_1 , V_11 ,
( unsigned long ) V_6 ) ;
}
long F_7 ( struct V_1 * V_12 , unsigned int V_2 , unsigned long V_3 )
{
unsigned int V_13 = F_8 ( V_2 ) ;
T_3 * V_14 = NULL ;
int V_15 ;
if ( V_13 < V_16 || V_13 >= V_17 )
return F_9 ( V_12 , V_2 , V_3 ) ;
if ( V_13 < V_16 + F_10 ( V_18 ) )
V_14 = V_18 [ V_13 - V_16 ] ;
if ( V_14 != NULL )
V_15 = (* V_14) ( V_12 , V_2 , V_3 ) ;
else
V_15 = F_6 ( V_12 , V_2 , V_3 ) ;
return V_15 ;
}
