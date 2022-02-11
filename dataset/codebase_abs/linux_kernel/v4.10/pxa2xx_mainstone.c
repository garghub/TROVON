static int F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 == 0 ) {
V_2 -> V_4 . V_5 = V_6 ;
V_2 -> V_7 [ V_8 ] . V_9 = V_10 ;
V_2 -> V_7 [ V_8 ] . V_11 = L_1 ;
V_2 -> V_7 [ V_12 ] . V_9 = V_13 ;
V_2 -> V_7 [ V_12 ] . V_11 = L_2 ;
} else {
V_2 -> V_4 . V_5 = V_14 ;
V_2 -> V_7 [ V_8 ] . V_9 = V_15 ;
V_2 -> V_7 [ V_8 ] . V_11 = L_3 ;
V_2 -> V_7 [ V_12 ] . V_9 = V_16 ;
V_2 -> V_7 [ V_12 ] . V_11 = L_4 ;
}
return 0 ;
}
static void F_2 ( struct V_1 * V_2 ,
struct V_17 * V_18 )
{
unsigned long V_19 , V_20 ;
V_19 = ( V_2 -> V_3 == 0 ) ? V_21 : V_22 ;
V_20 = ( V_19 ^ V_23 [ V_2 -> V_3 ] ) & V_24 ;
if ( V_20 ) {
V_23 [ V_2 -> V_3 ] = V_19 ;
if ( V_19 & V_24 )
F_3 ( ( V_2 -> V_3 == 0 ) ? V_13
: V_16 ) ;
else
F_4 ( ( V_2 -> V_3 == 0 ) ? V_13
: V_16 ) ;
}
V_18 -> V_25 = ( V_19 & V_26 ) ? 0 : 1 ;
V_18 -> V_27 = ( V_19 & V_28 ) ? 1 : 0 ;
V_18 -> V_29 = ( V_19 & V_24 ) ? 1 : 0 ;
V_18 -> V_30 = ( V_19 & V_31 ) ? 1 : 0 ;
V_18 -> V_32 = ( V_19 & V_33 ) ? 0 : 1 ;
V_18 -> V_34 = ( V_19 & V_35 ) ? 0 : 1 ;
}
static int F_5 ( struct V_1 * V_2 ,
const T_1 * V_18 )
{
unsigned long V_36 = 0 ;
int V_37 = 0 ;
switch ( V_18 -> V_38 ) {
case 0 : V_36 |= V_39 ; break;
case 33 : V_36 |= V_40 ; break;
case 50 : V_36 |= V_41 ; break;
default:
F_6 ( V_42 L_5 ,
V_43 , V_18 -> V_38 ) ;
V_37 = - 1 ;
}
switch ( V_18 -> V_44 ) {
case 0 : V_36 |= V_45 ; break;
case 120 : V_36 |= V_46 ; break;
default:
if( V_18 -> V_44 == V_18 -> V_38 ) {
V_36 |= V_47 ;
} else {
F_6 ( V_42 L_6 ,
V_43 , V_18 -> V_44 ) ;
V_37 = - 1 ;
}
}
if ( V_18 -> V_48 & V_49 )
V_36 |= V_50 ;
switch ( V_2 -> V_3 ) {
case 0 : V_21 = V_36 ; break;
case 1 : V_22 = V_36 ; break;
default: V_37 = - 1 ;
}
return V_37 ;
}
static int T_2 F_7 ( void )
{
int V_37 ;
if ( ! F_8 () )
return - V_51 ;
V_52 = F_9 ( L_7 , - 1 ) ;
if ( ! V_52 )
return - V_53 ;
V_37 = F_10 ( V_52 , & V_54 ,
sizeof( V_54 ) ) ;
if ( V_37 == 0 )
V_37 = F_11 ( V_52 ) ;
if ( V_37 )
F_12 ( V_52 ) ;
return V_37 ;
}
static void T_3 F_13 ( void )
{
F_14 ( V_52 ) ;
}
