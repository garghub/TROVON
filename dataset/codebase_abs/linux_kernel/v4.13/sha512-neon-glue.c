static int F_1 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! F_3 () ||
( V_6 -> V_7 [ 0 ] % V_8 ) + V_4 < V_8 )
return F_4 ( V_2 , V_3 , V_4 ) ;
F_5 () ;
F_6 ( V_2 , V_3 , V_4 ,
( V_9 * ) V_10 ) ;
F_7 () ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 , T_1 * V_11 )
{
if ( ! F_3 () )
return F_9 ( V_2 , V_3 , V_4 , V_11 ) ;
F_5 () ;
if ( V_4 )
F_6 ( V_2 , V_3 , V_4 ,
( V_9 * ) V_10 ) ;
F_10 ( V_2 ,
( V_9 * ) V_10 ) ;
F_7 () ;
return F_11 ( V_2 , V_11 ) ;
}
static int F_12 ( struct V_1 * V_2 , T_1 * V_11 )
{
return F_8 ( V_2 , NULL , 0 , V_11 ) ;
}
