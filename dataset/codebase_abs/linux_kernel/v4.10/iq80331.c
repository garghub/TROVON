static void T_1 F_1 ( void )
{
if ( * V_1 >= 0xa )
F_2 ( 333000000 ) ;
else
F_2 ( 266000000 ) ;
}
static int T_1
F_3 ( const struct V_2 * V_3 , T_2 V_4 , T_2 V_5 )
{
int V_6 ;
if ( V_4 == 1 && V_5 == 1 ) {
V_6 = V_7 ;
} else if ( V_4 == 1 && V_5 == 2 ) {
V_6 = V_8 ;
} else if ( V_4 == 1 && V_5 == 3 ) {
V_6 = V_9 ;
} else if ( V_4 == 1 && V_5 == 4 ) {
V_6 = V_10 ;
} else if ( V_4 == 2 ) {
V_6 = V_8 ;
} else {
F_4 ( V_11 L_1
L_2 , V_3 -> V_12 -> V_13 ,
F_5 ( V_3 -> V_14 ) , F_6 ( V_3 -> V_14 ) ) ;
V_6 = - 1 ;
}
return V_6 ;
}
static int T_1 F_7 ( void )
{
if ( ( F_8 () == V_15 ) &&
F_9 () )
F_10 ( & V_16 ) ;
return 0 ;
}
static void T_1 F_11 ( void )
{
F_12 ( L_3 , 0 ,
V_17 ,
F_13 ( V_17 ) ) ;
F_14 ( & V_18 ) ;
F_14 ( & V_19 ) ;
F_14 ( & V_20 ) ;
F_14 ( & V_21 ) ;
F_14 ( & V_22 ) ;
F_14 ( & V_23 ) ;
F_14 ( & V_24 ) ;
F_14 ( & V_25 ) ;
}
