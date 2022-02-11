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
void F_7 ( void )
{
F_3 ( V_4 , V_13 ,
V_14
| V_15 ) ;
F_3 ( V_4 , V_16 ,
V_14 |
V_15 ) ;
}
T_1 F_8 ( void )
{
struct V_17 * V_18 ;
void T_2 * V_19 ;
static T_1 V_20 ;
if ( V_20 )
return V_20 ;
V_18 = F_9 ( NULL , NULL , L_1 ) ;
V_19 = F_10 ( V_18 , 0 ) ;
F_11 ( ! V_19 ) ;
V_20 = F_12 ( V_19 + V_21 ) ;
return V_20 ;
}
void T_3 F_13 ( void )
{
V_4 = F_14 ( L_1 ) ;
if ( F_15 ( V_4 ) ) {
F_16 ( L_2 , V_22 ) ;
return;
}
}
