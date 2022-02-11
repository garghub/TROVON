static int F_1 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_3 ) {
case 0 :
V_2 -> V_4 [ V_5 ] . V_6 = V_7 ;
V_2 -> V_4 [ V_5 ] . V_8 = L_1 ;
V_2 -> V_4 [ V_9 ] . V_6 = V_10 ;
V_2 -> V_4 [ V_9 ] . V_8 = L_2 ;
break;
default:
break;
}
F_2 ( L_3 , V_11 , V_2 -> V_3 , V_2 -> V_12 . V_13 ) ;
return 0 ;
}
static void F_3 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
unsigned short V_16 = 0 , V_17 ;
V_16 = F_4 () ;
V_17 = ( V_16 ^ V_18 [ V_2 -> V_3 ] ) &
V_19 ;
if ( V_17 ) {
V_18 [ V_2 -> V_3 ] = V_16 ;
if ( V_16 & V_20 ) {
} else {
}
}
switch ( V_2 -> V_3 ) {
case 0 :
V_15 -> V_21 = ( V_16 & V_20 ) ? 1 : 0 ;
V_15 -> V_22 = ( V_16 & V_23 ) ? 1 : 0 ;
V_15 -> V_24 = ( V_16 & V_25 ) ? 0 : 1 ;
V_15 -> V_26 = ( V_16 & V_27 ) ? 0 : 1 ;
break;
#ifndef F_5
case 1 :
V_15 -> V_28 = 0 ;
V_15 -> V_29 = 0 ;
V_15 -> V_21 = 0 ;
V_15 -> V_22 = 0 ;
V_15 -> V_24 = 0 ;
V_15 -> V_26 = 0 ;
break;
#endif
}
}
static int F_6 ( struct V_1 * V_2 ,
const T_1 * V_15 )
{
int V_30 = 0 ;
unsigned short V_31 = 0 ;
switch ( V_15 -> V_32 ) {
case 0 : V_31 &= 0xfc ; break;
case 33 : V_31 |= V_33 ; break;
case 50 :
F_7 ( L_4 , V_11 ) ;
break;
default:
F_7 ( L_5 , V_11 , V_15 -> V_32 ) ;
V_30 = - 1 ;
}
switch ( V_15 -> V_34 ) {
case 0 : V_31 &= 0xf3 ; break;
case 33 : V_31 |= V_35 ; break;
case 120 :
F_7 ( L_6 , V_11 ) ;
break;
default:
if ( V_15 -> V_34 != V_15 -> V_32 ) {
F_7 ( L_7 , V_11 , V_15 -> V_34 ) ;
V_30 = - 1 ;
}
}
switch ( V_2 -> V_3 ) {
case 0 :
F_8 ( V_31 ) ;
break;
#ifndef F_5
case 1 :
#endif
default:
break;
}
return V_30 ;
}
static void F_9 ( struct V_1 * V_2 )
{
F_8 ( 0x9 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
F_8 ( 0x0 ) ;
}
static int T_2 F_11 ( void )
{
int V_30 ;
if ( ! F_12 () && ! F_13 () )
return - V_36 ;
V_37 = F_14 ( L_8 , - 1 ) ;
if ( ! V_37 )
return - V_38 ;
V_30 = F_15 ( V_37 ,
& V_39 , sizeof( V_39 ) ) ;
if ( V_30 == 0 )
V_30 = F_16 ( V_37 ) ;
if ( V_30 )
F_17 ( V_37 ) ;
return V_30 ;
}
static void T_3 F_18 ( void )
{
F_19 ( V_37 ) ;
}
