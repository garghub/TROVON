void T_1 * F_1 ( void )
{
return V_1 ;
}
void T_2 F_2 ( unsigned int V_2 )
{
if ( F_3 () && ( F_4 () != V_3 ) )
F_5 ( V_4 ,
4 , 0 , 0 , 0 , 0 , 0 ) ;
F_6 ( 0 ) ;
F_7 ( & V_5 ) ;
F_8 ( & V_5 ) ;
}
int T_2 F_9 ( unsigned int V_2 , struct V_6 * V_7 )
{
static struct V_8 * V_9 ;
static bool V_10 ;
F_7 ( & V_5 ) ;
F_10 ( 0x200 , 0xfffffdff ) ;
F_11 () ;
F_12 () ;
if ( ! V_9 )
V_9 = F_13 ( L_1 ) ;
if ( V_10 ) {
F_14 ( V_9 ) ;
F_15 ( V_9 ) ;
} else {
F_16 () ;
V_10 = true ;
}
F_17 ( F_18 ( V_2 ) , 1 ) ;
F_8 ( & V_5 ) ;
return 0 ;
}
static void T_3 F_19 ( void )
{
F_20 ( F_21 ( V_11 ) ) ;
F_12 () ;
F_16 () ;
F_22 () ;
}
void T_3 F_23 ( void )
{
unsigned int V_12 , V_13 ;
V_1 = F_24 ( V_14 ) ;
F_25 ( ! V_1 ) ;
V_13 = F_26 ( V_1 ) ;
if ( V_13 > V_15 ) {
F_27 ( L_2 ,
V_13 , V_15 ) ;
V_13 = V_15 ;
}
for ( V_12 = 0 ; V_12 < V_13 ; V_12 ++ )
F_28 ( V_12 , true ) ;
F_29 ( F_17 ) ;
}
void T_3 F_30 ( unsigned int V_16 )
{
F_31 ( V_1 ) ;
F_19 () ;
}
