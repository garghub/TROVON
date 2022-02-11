static int F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 . V_4 = ( V_2 -> V_5 == 0 ) ? V_6 : V_7 ;
return F_2 ( V_2 , V_8 , F_3 ( V_8 ) ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
F_5 ( V_2 , V_8 , F_3 ( V_8 ) ) ;
}
static void F_6 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
unsigned long V_11 , V_12 ;
V_11 = ( V_2 -> V_5 == 0 ) ? V_13 : V_14 ;
V_12 = ( V_11 ^ V_15 [ V_2 -> V_5 ] ) & V_16 ;
if ( V_12 ) {
V_15 [ V_2 -> V_5 ] = V_11 ;
if ( V_11 & V_16 )
F_7 ( ( V_2 -> V_5 == 0 ) ? V_17
: V_18 ) ;
else
F_8 ( ( V_2 -> V_5 == 0 ) ? V_17
: V_18 ) ;
}
V_10 -> V_19 = ( V_11 & V_20 ) ? 0 : 1 ;
V_10 -> V_21 = ( V_11 & V_22 ) ? 1 : 0 ;
V_10 -> V_23 = ( V_11 & V_16 ) ? 1 : 0 ;
V_10 -> V_24 = ( V_11 & V_25 ) ? 1 : 0 ;
V_10 -> V_26 = ( V_11 & V_27 ) ? 0 : 1 ;
V_10 -> V_28 = ( V_11 & V_29 ) ? 0 : 1 ;
V_10 -> V_30 = 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
const T_1 * V_10 )
{
unsigned long V_31 = 0 ;
int V_32 = 0 ;
switch ( V_10 -> V_33 ) {
case 0 : V_31 |= V_34 ; break;
case 33 : V_31 |= V_35 ; break;
case 50 : V_31 |= V_36 ; break;
default:
F_10 ( V_37 L_1 ,
V_38 , V_10 -> V_33 ) ;
V_32 = - 1 ;
}
switch ( V_10 -> V_39 ) {
case 0 : V_31 |= V_40 ; break;
case 120 : V_31 |= V_41 ; break;
default:
if( V_10 -> V_39 == V_10 -> V_33 ) {
V_31 |= V_42 ;
} else {
F_10 ( V_37 L_2 ,
V_38 , V_10 -> V_39 ) ;
V_32 = - 1 ;
}
}
if ( V_10 -> V_43 & V_44 )
V_31 |= V_45 ;
switch ( V_2 -> V_5 ) {
case 0 : V_13 = V_31 ; break;
case 1 : V_14 = V_31 ; break;
default: V_32 = - 1 ;
}
return V_32 ;
}
static void F_11 ( struct V_1 * V_2 )
{
}
static void F_12 ( struct V_1 * V_2 )
{
}
static int T_2 F_13 ( void )
{
int V_32 ;
if ( ! F_14 () )
return - V_46 ;
V_47 = F_15 ( L_3 , - 1 ) ;
if ( ! V_47 )
return - V_48 ;
V_32 = F_16 ( V_47 , & V_49 ,
sizeof( V_49 ) ) ;
if ( V_32 == 0 )
V_32 = F_17 ( V_47 ) ;
if ( V_32 )
F_18 ( V_47 ) ;
return V_32 ;
}
static void T_3 F_19 ( void )
{
F_20 ( V_47 ) ;
}
