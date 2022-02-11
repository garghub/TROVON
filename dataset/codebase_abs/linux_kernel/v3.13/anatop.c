static void F_1 ( bool V_1 )
{
T_1 V_2 , V_3 ;
F_2 ( V_4 , V_5 , & V_3 ) ;
V_2 = V_6 ;
V_2 += ( V_1 && ( V_3 & V_7 ) == 0 ) ?
V_8 : V_9 ;
F_3 ( V_4 , V_2 , V_10 ) ;
}
static void F_4 ( bool V_1 )
{
F_3 ( V_4 , V_11 + ( V_1 ? V_8 : V_9 ) ,
V_12 ) ;
}
void F_5 ( void )
{
F_1 ( true ) ;
F_4 ( true ) ;
}
void F_6 ( void )
{
F_4 ( false ) ;
F_1 ( false ) ;
}
static void F_7 ( void )
{
F_3 ( V_4 , V_13 ,
V_14
| V_15 ) ;
F_3 ( V_4 , V_16 ,
V_14 |
V_15 ) ;
}
void T_2 F_8 ( void )
{
struct V_17 * V_18 ;
void T_3 * V_19 ;
unsigned int V_20 ;
T_1 V_21 ;
T_4 V_22 = V_23 ;
V_18 = F_9 ( NULL , NULL , L_1 ) ;
V_19 = F_10 ( V_18 , 0 ) ;
F_11 ( ! V_19 ) ;
if ( F_12 ( V_18 , L_2 ) )
V_22 = V_24 ;
V_21 = F_13 ( V_19 + V_22 ) ;
F_14 ( V_19 ) ;
switch ( V_21 & 0xff ) {
case 0 :
V_20 = V_25 ;
break;
case 1 :
V_20 = V_26 ;
break;
case 2 :
V_20 = V_27 ;
break;
default:
V_20 = V_28 ;
}
F_15 ( V_21 >> 16 & 0xff ) ;
F_16 ( V_20 ) ;
}
void T_2 F_17 ( void )
{
V_4 = F_18 ( L_1 ) ;
if ( F_19 ( V_4 ) ) {
F_20 ( L_3 , V_29 ) ;
return;
}
F_7 () ;
}
