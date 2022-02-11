void T_1 F_1 ( unsigned int V_1 )
{
F_2 ( 0 ) ;
F_3 ( & V_2 ) ;
F_4 ( & V_2 ) ;
}
int T_1 F_5 ( unsigned int V_1 , struct V_3 * V_4 )
{
F_3 ( & V_2 ) ;
F_6 ( 0x200 , 0xfffffdff ) ;
F_7 () ;
F_8 () ;
F_9 ( F_10 ( V_1 ) , 1 ) ;
F_4 ( & V_2 ) ;
return 0 ;
}
static void T_2 F_11 ( void )
{
F_12 ( F_13 ( V_5 ) ) ;
F_8 () ;
F_14 () ;
F_15 () ;
}
void T_2 F_16 ( void )
{
unsigned int V_6 , V_7 ;
V_8 = F_17 ( V_9 , V_10 ) ;
F_18 ( ! V_8 ) ;
V_7 = F_19 ( V_8 ) ;
if ( V_7 > V_11 ) {
F_20 ( V_12
L_1
L_2 ,
V_7 , V_11 ) ;
V_7 = V_11 ;
}
for ( V_6 = 0 ; V_6 < V_7 ; V_6 ++ )
F_21 ( V_6 , true ) ;
F_22 ( F_9 ) ;
}
void T_2 F_23 ( unsigned int V_13 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_13 ; V_6 ++ )
F_24 ( V_6 , true ) ;
F_25 ( V_8 ) ;
F_11 () ;
}
