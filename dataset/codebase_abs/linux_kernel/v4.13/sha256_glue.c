int F_1 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 )
{
F_2 ( F_3 ( struct V_5 , V_6 ) != 0 ) ;
return F_4 ( V_2 , V_3 , V_4 ,
( V_7 * ) V_8 ) ;
}
static int F_5 ( struct V_1 * V_2 , T_1 * V_9 )
{
F_6 ( V_2 ,
( V_7 * ) V_8 ) ;
return F_7 ( V_2 , V_9 ) ;
}
int F_8 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 , T_1 * V_9 )
{
F_4 ( V_2 , V_3 , V_4 ,
( V_7 * ) V_8 ) ;
return F_5 ( V_2 , V_9 ) ;
}
static int T_2 F_9 ( void )
{
int V_10 = F_10 ( V_11 , F_11 ( V_11 ) ) ;
if ( V_10 < 0 )
return V_10 ;
if ( F_12 ( V_12 ) && F_13 () ) {
V_10 = F_10 ( V_13 ,
F_11 ( V_13 ) ) ;
if ( V_10 < 0 )
F_14 ( V_11 , F_11 ( V_11 ) ) ;
}
return V_10 ;
}
static void T_3 F_15 ( void )
{
F_14 ( V_11 , F_11 ( V_11 ) ) ;
if ( F_12 ( V_12 ) && F_13 () )
F_14 ( V_13 ,
F_11 ( V_13 ) ) ;
}
