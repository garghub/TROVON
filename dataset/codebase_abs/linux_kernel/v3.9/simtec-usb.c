static void
F_1 ( int V_1 , int V_2 )
{
F_2 ( L_1 , V_1 , V_2 ) ;
V_3 [ V_1 ] = V_2 ;
if ( V_3 [ 0 ] && V_3 [ 1 ] )
F_3 ( F_4 ( 4 ) , 0 ) ;
else
F_3 ( F_4 ( 4 ) , 1 ) ;
}
static T_1
F_5 ( int V_4 , void * V_5 )
{
struct V_6 * V_7 = V_5 ;
if ( F_6 ( F_7 ( 10 ) ) == 0 ) {
F_2 ( L_2 ) ;
F_8 ( V_7 , 3 ) ;
} else {
F_2 ( L_3 ) ;
F_8 ( V_7 , 0 ) ;
}
return V_8 ;
}
static void F_9 ( struct V_6 * V_7 , int V_9 )
{
int V_10 ;
if ( V_9 ) {
V_10 = F_10 ( V_11 , F_5 ,
V_12 | V_13 |
V_14 ,
L_4 , V_7 ) ;
if ( V_10 != 0 ) {
F_11 ( V_15 L_5 ) ;
}
} else {
F_12 ( V_11 , V_7 ) ;
}
}
int T_2 F_13 ( void )
{
int V_10 ;
F_11 ( L_6 ) ;
V_10 = F_14 ( F_4 ( 4 ) , L_7 ) ;
if ( V_10 < 0 ) {
F_15 ( L_8 , V_16 ) ;
return V_10 ;
}
V_10 = F_14 ( F_7 ( 10 ) , L_9 ) ;
if ( V_10 < 0 ) {
F_15 ( L_10 , V_16 ) ;
F_16 ( F_4 ( 4 ) ) ;
return V_10 ;
}
F_17 ( F_4 ( 4 ) , 1 ) ;
F_18 ( F_7 ( 10 ) ) ;
F_19 ( & V_17 ) ;
return 0 ;
}
