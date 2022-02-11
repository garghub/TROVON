static void F_1 ( int V_1 )
{
V_2 = V_1 ;
F_2 () ;
F_3 ( ( void * ) & V_2 , sizeof( V_2 ) ) ;
F_4 ( F_5 ( & V_2 ) , F_5 ( & V_2 + 1 ) ) ;
}
static void T_1 * F_6 ( void )
{
return ( void T_1 * ) ( V_3 ) ;
}
void T_2 F_7 ( unsigned int V_4 )
{
F_8 ( 0 ) ;
F_1 ( - 1 ) ;
F_9 ( & V_5 ) ;
F_10 ( & V_5 ) ;
}
int T_2 F_11 ( unsigned int V_4 , struct V_6 * V_7 )
{
unsigned long V_8 ;
F_9 ( & V_5 ) ;
F_1 ( V_4 ) ;
F_12 ( F_13 ( V_4 ) , 1 ) ;
V_8 = V_9 + ( 1 * V_10 ) ;
while ( F_14 ( V_9 , V_8 ) ) {
F_15 () ;
if ( V_2 == - 1 )
break;
F_16 ( 10 ) ;
}
F_10 ( & V_5 ) ;
return V_2 != - 1 ? - V_11 : 0 ;
}
void T_3 F_17 ( void )
{
void T_1 * V_12 = F_6 () ;
unsigned int V_13 , V_14 ;
V_14 = V_12 ? F_18 ( V_12 ) : 1 ;
if ( V_14 > V_15 ) {
F_19 ( V_16
L_1
L_2 ,
V_14 , V_15 ) ;
V_14 = V_15 ;
}
for ( V_13 = 0 ; V_13 < V_14 ; V_13 ++ )
F_20 ( V_13 , true ) ;
F_21 ( F_12 ) ;
}
void T_3 F_22 ( unsigned int V_17 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < V_17 ; V_13 ++ )
F_23 ( V_13 , true ) ;
F_24 ( F_6 () ) ;
F_25 ( F_26 ( F_27 ( V_18 ) ) , V_19 ) ;
}
