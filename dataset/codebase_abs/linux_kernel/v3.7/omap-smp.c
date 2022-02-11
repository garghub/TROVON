void T_1 * F_1 ( void )
{
return V_1 ;
}
static void T_2 F_2 ( unsigned int V_2 )
{
if ( F_3 () && ( F_4 () != V_3 ) )
F_5 ( V_4 ,
4 , 0 , 0 , 0 , 0 , 0 ) ;
F_6 ( 0 ) ;
F_7 ( & V_5 ) ;
F_8 ( & V_5 ) ;
}
static int T_2 F_9 ( unsigned int V_2 , struct V_6 * V_7 )
{
static struct V_8 * V_9 ;
static bool V_10 ;
void T_1 * V_11 = F_10 () ;
F_7 ( & V_5 ) ;
if ( F_11 () )
F_12 ( 0x200 , 0xfffffdff ) ;
else
F_13 ( 0x20 , V_11 + V_12 ) ;
F_14 () ;
F_15 () ;
if ( ! V_9 )
V_9 = F_16 ( L_1 ) ;
if ( V_10 ) {
F_17 ( V_9 ) ;
F_18 ( V_9 ) ;
} else {
F_19 () ;
V_10 = true ;
}
F_20 ( F_21 ( V_2 ) , 0 ) ;
F_8 ( & V_5 ) ;
return 0 ;
}
static void T_3 F_22 ( void )
{
void T_1 * V_11 = F_10 () ;
if ( F_11 () )
F_23 ( F_24 ( V_13 ) ) ;
else
F_13 ( F_24 ( V_14 ) ,
V_11 + V_15 ) ;
F_15 () ;
F_19 () ;
F_25 () ;
}
static void T_3 F_26 ( void )
{
unsigned int V_16 = 0 , V_17 = 1 , V_18 ;
V_18 = F_27 ( V_19 ) & V_20 ;
if ( V_18 == V_21 ) {
V_1 = F_28 ( V_22 ) ;
F_29 ( ! V_1 ) ;
V_17 = F_30 ( V_1 ) ;
} else if ( V_18 == V_23 ) {
V_17 = V_24 ;
}
if ( V_17 > V_25 ) {
F_31 ( L_2 ,
V_17 , V_25 ) ;
V_17 = V_25 ;
}
for ( V_16 = 0 ; V_16 < V_17 ; V_16 ++ )
F_32 ( V_16 , true ) ;
F_33 ( F_20 ) ;
}
static void T_3 F_34 ( unsigned int V_26 )
{
if ( V_1 )
F_35 ( V_1 ) ;
F_22 () ;
}
