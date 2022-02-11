static void T_1 F_1 ( void )
{
int V_1 , V_2 ;
int V_3 [] = { 2 , 4 , 8 , 16 , 1 , 2 , 4 , 8 } ;
V_1 = ( * ( V_4 ) & 0xFF ) * 2 ;
V_2 = V_3 [ ( * ( V_5 ) & 0x7 ) ] ;
F_2 ( ( ( 3125000 * V_1 ) / ( V_2 ) ) / 2 ) ;
}
void T_1 F_3 ( void )
{
F_4 ( V_6 , 0x00100000 ) ;
F_5 () ;
F_6 ( L_1 ) ;
}
int F_7 ( int V_7 , struct V_8 * V_9 )
{
V_9 -> V_10 = 0xe0000000 ;
F_8 ( V_7 , V_9 ) ;
return 1 ;
}
static int T_1 F_9 ( const struct V_11 * V_12 , T_2 V_13 ,
T_2 V_14 )
{
if ( F_10 () ) {
if( ! V_12 -> V_15 -> V_16 ) {
if( V_12 -> V_17 == V_18 )
return V_19 ;
return - 1 ;
}
if( V_12 -> V_15 -> V_16 -> V_17 == V_20 &&
V_12 -> V_15 -> V_21 -> V_16 -> V_17 == V_22 &&
! V_12 -> V_15 -> V_21 -> V_16 -> V_15 -> V_21 )
return V_23 ;
if( V_12 -> V_15 -> V_16 -> V_17 == V_22 ) {
switch( V_12 -> V_17 ) {
case V_24 :
return V_25 ;
case V_26 :
return V_27 ;
case V_28 :
return V_29 ;
case V_20 :
return V_23 ;
}
}
return - 1 ;
} else return V_30 ;
}
static void F_11 ( void )
{
struct V_11 * V_12 ;
if ( F_10 () ) {
V_12 = F_12 ( 1 , V_31 ) ;
F_13 ( V_12 ) ;
F_14 ( V_12 ) ;
} else {
V_12 = F_12 ( 1 , V_24 ) ;
F_13 ( V_12 ) ;
F_14 ( V_12 ) ;
F_15 () ;
}
}
int T_1 F_16 ( void )
{
if ( F_17 () )
F_18 ( & V_32 ) ;
return 0 ;
}
void T_1 F_19 ( void )
{
F_20 ( V_33 , V_34 , V_35 ) ;
}
