static void T_1 F_1 ( void )
{
if ( * V_1 >= 0xa || * V_2 == 0x374 )
F_2 ( 333000000 ) ;
else
F_2 ( 266000000 ) ;
}
static int T_1
F_3 ( const struct V_3 * V_4 , T_2 V_5 , T_2 V_6 )
{
int V_7 ;
if ( V_5 == 4 && V_6 == 1 ) {
V_7 = V_8 ;
} else if ( V_5 == 4 && V_6 == 2 ) {
V_7 = V_9 ;
} else if ( V_5 == 4 && V_6 == 3 ) {
V_7 = V_10 ;
} else if ( V_5 == 4 && V_6 == 4 ) {
V_7 = V_11 ;
} else if ( V_5 == 6 ) {
V_7 = V_10 ;
} else {
F_4 ( V_12 L_1
L_2 , V_4 -> V_13 -> V_14 ,
F_5 ( V_4 -> V_15 ) , F_6 ( V_4 -> V_15 ) ) ;
V_7 = - 1 ;
}
return V_7 ;
}
static int T_1 F_7 ( void )
{
if ( ( F_8 () == V_16 ) &&
F_9 () )
F_10 ( & V_17 ) ;
return 0 ;
}
static void T_1 F_11 ( void )
{
F_12 ( L_3 , 0 ,
V_18 ,
F_13 ( V_18 ) ) ;
F_14 ( & V_19 ) ;
F_14 ( & V_20 ) ;
F_14 ( & V_21 ) ;
F_14 ( & V_22 ) ;
F_14 ( & V_23 ) ;
F_14 ( & V_24 ) ;
F_14 ( & V_25 ) ;
F_14 ( & V_26 ) ;
}
