static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , struct V_7 * V_8 ,
unsigned long * * V_9 , int * V_10 )
{
unsigned long V_11 = ( unsigned long ) F_2 ( V_2 ) ;
if ( ( V_8 -> V_12 & V_13 ) != V_14 ||
! ( V_11 & V_15 ) )
return 0 ;
switch ( V_8 -> V_12 & V_16 ) {
case 0x03a : F_3 ( V_17 ) ; break;
case 0x03b : F_3 ( V_18 ) ; break;
case 0x03c : F_3 ( V_19 ) ; break;
default:
return 0 ;
}
return 1 ;
}
static int F_4 ( struct V_1 * V_2 , const struct V_20 * V_21 )
{
unsigned long V_11 = V_21 -> V_22 ;
int V_23 ;
F_5 ( V_2 , ( void * ) V_11 ) ;
V_23 = F_6 ( V_2 ) ;
if ( V_23 ) {
F_7 ( V_2 , L_1 ) ;
goto V_24;
}
V_23 = F_8 ( V_2 , V_25 |
( ( V_11 & V_26 ) ? V_27 : 0 ) ) ;
if ( V_23 ) {
F_7 ( V_2 , L_2 ) ;
goto V_24;
}
return 0 ;
V_24:
return V_23 ;
}
static int T_1 F_9 ( void )
{
return F_10 ( & V_28 ) ;
}
static void T_2 F_11 ( void )
{
F_12 ( & V_28 ) ;
}
