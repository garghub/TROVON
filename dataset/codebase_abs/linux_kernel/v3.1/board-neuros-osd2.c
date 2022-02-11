static void T_1 F_1 ( void )
{
F_2 () ;
}
static int F_3 ( void )
{
int V_1 ;
F_4 ( & V_2 ) ;
V_1 = F_5 ( V_3 , V_4 [ 0 ] . type ) ;
if ( V_1 == 0 ) {
V_1 = F_6 ( V_3 ) ;
if ( V_1 == 0 ) {
V_1 = F_7 ( V_3 ) ;
if ( V_1 > 0 ) {
V_4 [ 0 ] . V_5 = V_1 ;
F_8 ( 1 ,
V_4 ,
F_9 ( V_4 ) ) ;
}
}
}
return V_1 ;
}
static T_1 void F_10 ( void )
{
struct V_6 * V_7 ;
struct V_8 * V_9 = & V_8 ;
int V_1 ;
V_7 = F_11 ( NULL , L_1 ) ;
F_12 ( V_7 ) ;
if ( V_10 ) {
if ( V_11 )
F_13 ( L_2
L_3
L_4 ) ;
F_14 () ;
} else if ( V_11 ) {
F_15 ( V_12 ) ;
F_15 ( V_13 ) ;
if ( V_11 )
F_16 (
& V_14 ) ;
}
F_17 ( V_15 ,
F_9 ( V_15 ) ) ;
V_1 = F_3 () ;
if ( V_1 < 0 )
F_13 ( L_5
L_6 , V_1 ) ;
F_18 ( & V_16 ) ;
F_19 ( & V_17 ) ;
V_9 -> V_18 -> V_19 = V_20 ;
F_20 ( 1000 , 8 ) ;
F_15 ( V_21 ) ;
F_15 ( V_22 ) ;
F_15 ( V_23 ) ;
F_15 ( V_24 ) ;
F_15 ( V_25 ) ;
F_21 ( 0 , & V_26 ) ;
}
