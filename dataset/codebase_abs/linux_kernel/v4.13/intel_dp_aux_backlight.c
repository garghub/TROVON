static void F_1 ( struct V_1 * V_1 , bool V_2 )
{
T_1 V_3 = 0 ;
if ( ! ( V_1 -> V_4 [ 1 ] & V_5 ) )
return;
if ( F_2 ( & V_1 -> V_6 , V_7 ,
& V_3 ) < 0 ) {
F_3 ( L_1 ,
V_7 ) ;
return;
}
if ( V_2 )
V_3 |= V_8 ;
else
V_3 &= ~ ( V_8 ) ;
if ( F_4 ( & V_1 -> V_6 , V_7 ,
V_3 ) != 1 ) {
F_3 ( L_2 ,
V_2 ? L_3 : L_4 ) ;
}
}
static T_2 F_5 ( struct V_9 * V_10 )
{
struct V_1 * V_1 = F_6 ( & V_10 -> V_11 -> V_12 ) ;
T_1 V_13 [ 2 ] = { 0x0 } ;
T_3 V_14 = 0 ;
if ( F_7 ( & V_1 -> V_6 , V_15 ,
& V_13 , sizeof( V_13 ) ) < 0 ) {
F_3 ( L_1 ,
V_15 ) ;
return 0 ;
}
V_14 = V_13 [ 0 ] ;
if ( V_1 -> V_4 [ 2 ] & V_16 )
V_14 = ( V_13 [ 0 ] << 8 | V_13 [ 1 ] ) ;
return V_14 ;
}
static void
F_8 ( const struct V_17 * V_18 , T_4 V_14 )
{
struct V_9 * V_10 = F_9 ( V_18 -> V_10 ) ;
struct V_1 * V_1 = F_6 ( & V_10 -> V_11 -> V_12 ) ;
T_1 V_19 [ 2 ] = { 0x0 } ;
V_19 [ 0 ] = V_14 ;
if ( V_1 -> V_4 [ 2 ] & V_16 ) {
V_19 [ 0 ] = ( V_14 & 0xFF00 ) >> 8 ;
V_19 [ 1 ] = ( V_14 & 0xFF ) ;
}
if ( F_10 ( & V_1 -> V_6 , V_15 ,
V_19 , sizeof( V_19 ) ) < 0 ) {
F_3 ( L_5 ) ;
return;
}
}
static void F_11 ( const struct V_20 * V_21 ,
const struct V_17 * V_18 )
{
struct V_9 * V_10 = F_9 ( V_18 -> V_10 ) ;
struct V_1 * V_1 = F_6 ( & V_10 -> V_11 -> V_12 ) ;
T_1 V_22 = 0 ;
T_1 V_23 = 0 ;
if ( F_2 ( & V_1 -> V_6 ,
V_24 , & V_22 ) != 1 ) {
F_3 ( L_1 ,
V_24 ) ;
return;
}
V_23 = V_22 & V_25 ;
switch ( V_23 ) {
case V_26 :
case V_27 :
case V_28 :
V_22 &= ~ V_25 ;
V_22 |= V_29 ;
if ( F_4 ( & V_1 -> V_6 ,
V_24 , V_22 ) < 0 ) {
F_3 ( L_6 ) ;
}
break;
case V_29 :
default:
break;
}
F_1 ( V_1 , true ) ;
F_8 ( V_18 , V_10 -> V_30 . V_31 . V_14 ) ;
}
static void F_12 ( const struct V_17 * V_32 )
{
F_1 ( F_6 ( V_32 -> V_33 ) , false ) ;
}
static int F_13 ( struct V_9 * V_10 ,
enum V_34 V_34 )
{
struct V_1 * V_1 = F_6 ( & V_10 -> V_11 -> V_12 ) ;
struct V_35 * V_30 = & V_10 -> V_30 ;
if ( V_1 -> V_4 [ 2 ] & V_16 )
V_30 -> V_31 . V_36 = 0xFFFF ;
else
V_30 -> V_31 . V_36 = 0xFF ;
V_30 -> V_31 . V_37 = 0 ;
V_30 -> V_31 . V_14 = F_5 ( V_10 ) ;
V_30 -> V_31 . V_38 = V_30 -> V_31 . V_14 != 0 ;
return 0 ;
}
static bool
F_14 ( struct V_9 * V_10 )
{
struct V_1 * V_1 = F_6 ( & V_10 -> V_11 -> V_12 ) ;
if ( V_1 -> V_4 [ 1 ] & V_39 &&
( V_1 -> V_4 [ 2 ] & V_40 ) &&
! ( V_1 -> V_4 [ 2 ] & V_41 ) ) {
F_3 ( L_7 ) ;
return true ;
}
return false ;
}
int F_15 ( struct V_9 * V_9 )
{
struct V_35 * V_30 = & V_9 -> V_30 ;
if ( ! V_42 . V_43 )
return - V_44 ;
if ( ! F_14 ( V_9 ) )
return - V_44 ;
V_30 -> V_31 . V_45 = F_13 ;
V_30 -> V_31 . V_2 = F_11 ;
V_30 -> V_31 . V_46 = F_12 ;
V_30 -> V_31 . V_47 = F_8 ;
V_30 -> V_31 . V_48 = F_5 ;
return 0 ;
}
