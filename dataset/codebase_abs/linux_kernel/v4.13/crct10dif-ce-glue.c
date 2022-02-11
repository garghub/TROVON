static int F_1 ( struct V_1 * V_2 )
{
T_1 * V_3 = F_2 ( V_2 ) ;
* V_3 = 0 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 , const T_2 * V_4 ,
unsigned int V_5 )
{
T_1 * V_3 = F_2 ( V_2 ) ;
unsigned int V_6 ;
if ( F_4 ( ( V_7 ) V_4 % V_8 ) ) {
V_6 = F_5 ( V_9 , V_5 , V_8 -
( ( V_7 ) V_4 % V_8 ) ) ;
* V_3 = F_6 ( * V_3 , V_4 , V_6 ) ;
V_5 -= V_6 ;
V_4 += V_6 ;
}
if ( V_5 > 0 ) {
F_7 ( 14 ) ;
* V_3 = F_8 ( * V_3 , V_4 , V_5 ) ;
F_9 () ;
}
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , T_2 * V_10 )
{
T_1 * V_3 = F_2 ( V_2 ) ;
* ( T_1 * ) V_10 = * V_3 ;
return 0 ;
}
static int T_3 F_11 ( void )
{
return F_12 ( & V_11 ) ;
}
static void T_4 F_13 ( void )
{
F_14 ( & V_11 ) ;
}
