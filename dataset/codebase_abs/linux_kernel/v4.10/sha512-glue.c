int F_1 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 )
{
return F_2 ( V_2 , V_3 , V_4 ,
( V_5 * ) V_6 ) ;
}
int F_3 ( struct V_1 * V_2 , T_1 * V_7 )
{
F_4 ( V_2 ,
( V_5 * ) V_6 ) ;
return F_5 ( V_2 , V_7 ) ;
}
int F_6 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 , T_1 * V_7 )
{
F_2 ( V_2 , V_3 , V_4 ,
( V_5 * ) V_6 ) ;
return F_3 ( V_2 , V_7 ) ;
}
static int T_2 F_7 ( void )
{
int V_8 ;
V_8 = F_8 ( V_9 ,
F_9 ( V_9 ) ) ;
if ( V_8 )
return V_8 ;
if ( F_10 ( V_10 ) && F_11 () ) {
V_8 = F_8 ( V_11 ,
F_9 ( V_11 ) ) ;
if ( V_8 )
goto V_12;
}
return 0 ;
V_12:
F_12 ( V_9 ,
F_9 ( V_9 ) ) ;
return V_8 ;
}
static void T_3 F_13 ( void )
{
F_12 ( V_9 ,
F_9 ( V_9 ) ) ;
if ( F_10 ( V_10 ) && F_11 () )
F_12 ( V_11 ,
F_9 ( V_11 ) ) ;
}
