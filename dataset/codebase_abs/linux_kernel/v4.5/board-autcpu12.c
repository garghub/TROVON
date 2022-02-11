static void T_1 F_1 ( struct V_1 * V_2 ,
T_2 V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
break;
case V_6 :
case V_7 :
V_2 -> V_8 [ 0 ] . V_9 = V_4 ;
break;
default:
F_2 ( L_1 , V_3 ) ;
break;
}
}
static void T_1 F_3 ( void )
{
void T_3 * V_10 ;
unsigned int V_11 [ 2 ] ;
T_4 V_12 = V_13 ;
V_10 = F_4 ( V_14 [ 0 ] . V_15 , V_13 ) ;
if ( V_10 ) {
V_11 [ 0 ] = F_5 ( V_10 + 0 ) ;
V_11 [ 1 ] = F_5 ( V_10 + V_16 ) ;
F_6 ( ~ V_11 [ 0 ] , V_10 + V_16 ) ;
if ( F_5 ( V_10 + 0 ) != V_11 [ 0 ] ) {
F_6 ( V_11 [ 0 ] , V_10 + 0 ) ;
V_12 = V_17 ;
} else
F_6 ( V_11 [ 1 ] , V_10 + V_16 ) ;
F_7 ( V_10 ) ;
V_14 [ 0 ] . V_18 =
V_14 [ 0 ] . V_15 + V_12 - 1 ;
F_8 ( & V_19 ) ;
} else
F_9 ( L_2 ) ;
}
static void T_1 F_10 ( void )
{
F_11 () ;
F_8 ( & V_20 ) ;
F_12 ( L_3 , 0 , NULL , 0 ) ;
F_12 ( L_4 , 0 , V_21 ,
F_13 ( V_21 ) ) ;
F_8 ( & V_22 ) ;
F_3 () ;
}
static void T_1 F_14 ( void )
{
F_15 ( V_23 , F_13 ( V_23 ) ) ;
F_8 ( & V_24 ) ;
}
