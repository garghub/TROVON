static void T_1 F_1 ( void )
{
F_2 ( 200000000 ) ;
}
void T_1 F_3 ( void )
{
F_4 () ;
F_5 ( V_1 , F_6 ( V_1 ) ) ;
}
static int T_1
F_7 ( const struct V_2 * V_3 , T_2 V_4 , T_2 V_5 )
{
int V_6 ;
if ( ( V_4 == 2 || V_4 == 6 ) && V_5 == 1 ) {
V_6 = V_7 ;
} else if ( ( V_4 == 2 || V_4 == 6 ) && V_5 == 2 ) {
V_6 = V_8 ;
} else if ( ( V_4 == 2 || V_4 == 6 ) && V_5 == 3 ) {
V_6 = V_9 ;
} else if ( ( V_4 == 2 || V_4 == 6 ) && V_5 == 4 ) {
V_6 = V_10 ;
} else if ( V_4 == 4 || V_4 == 8 ) {
V_6 = V_9 ;
} else {
F_8 ( V_11 L_1
L_2 , V_3 -> V_12 -> V_13 ,
F_9 ( V_3 -> V_14 ) , F_10 ( V_3 -> V_14 ) ) ;
V_6 = - 1 ;
}
return V_6 ;
}
static int T_1 F_11 ( void )
{
if ( ( F_12 () == V_15 ) &&
F_13 () )
F_14 ( & V_16 ) ;
return 0 ;
}
static void T_1 F_15 ( void )
{
F_16 () ;
F_17 ( & V_17 ) ;
F_17 ( & V_18 ) ;
F_17 ( & V_19 ) ;
F_17 ( & V_20 ) ;
F_17 ( & V_21 ) ;
F_17 ( & V_22 ) ;
F_17 ( & V_23 ) ;
}
