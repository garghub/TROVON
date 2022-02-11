static int F_1 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! F_3 () ||
( V_6 -> V_7 % V_8 ) + V_4 < V_8 )
return F_4 ( V_2 , V_3 , V_4 ) ;
F_5 () ;
F_6 ( V_2 , V_3 , V_4 , V_9 ) ;
F_7 () ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 , T_1 * V_10 )
{
if ( ! F_3 () )
return F_9 ( V_2 , V_3 , V_4 , V_10 ) ;
F_5 () ;
if ( V_4 )
F_6 ( V_2 , V_3 , V_4 , V_9 ) ;
F_10 ( V_2 , V_9 ) ;
F_7 () ;
return F_11 ( V_2 , V_10 ) ;
}
static int F_12 ( struct V_1 * V_2 , T_1 * V_10 )
{
return F_8 ( V_2 , NULL , 0 , V_10 ) ;
}
static int T_2 F_13 ( void )
{
if ( ! ( V_11 & V_12 ) )
return - V_13 ;
return F_14 ( & V_14 ) ;
}
static void T_3 F_15 ( void )
{
F_16 ( & V_14 ) ;
}
