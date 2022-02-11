static void F_1 ( struct V_1 * V_1 , bool V_2 )
{
T_1 V_3 = 0 ;
if ( F_2 ( & V_1 -> V_4 , V_5 ,
& V_3 ) < 0 ) {
F_3 ( L_1 ,
V_5 ) ;
return;
}
if ( V_2 )
V_3 |= V_6 ;
else
V_3 &= ~ ( V_6 ) ;
if ( F_4 ( & V_1 -> V_4 , V_5 ,
V_3 ) != 1 ) {
F_3 ( L_2 ,
V_2 ? L_3 : L_4 ) ;
}
}
static T_2 F_5 ( struct V_7 * V_8 )
{
struct V_1 * V_1 = F_6 ( & V_8 -> V_9 -> V_10 ) ;
T_1 V_11 [ 2 ] = { 0x0 } ;
T_3 V_12 = 0 ;
if ( F_7 ( & V_1 -> V_4 , V_13 ,
& V_11 , sizeof( V_11 ) ) < 0 ) {
F_3 ( L_1 ,
V_13 ) ;
return 0 ;
}
V_12 = V_11 [ 0 ] ;
if ( V_1 -> V_14 [ 2 ] & V_15 )
V_12 = ( V_11 [ 0 ] << 8 | V_11 [ 1 ] ) ;
return V_12 ;
}
static void
F_8 ( struct V_7 * V_8 , T_4 V_12 )
{
struct V_1 * V_1 = F_6 ( & V_8 -> V_9 -> V_10 ) ;
T_1 V_16 [ 2 ] = { 0x0 } ;
V_16 [ 0 ] = V_12 ;
if ( V_1 -> V_14 [ 2 ] & V_15 ) {
V_16 [ 0 ] = ( V_12 & 0xFF00 ) >> 8 ;
V_16 [ 1 ] = ( V_12 & 0xFF ) ;
}
if ( F_9 ( & V_1 -> V_4 , V_13 ,
V_16 , sizeof( V_16 ) ) < 0 ) {
F_3 ( L_5 ) ;
return;
}
}
static void F_10 ( struct V_7 * V_8 )
{
struct V_1 * V_1 = F_6 ( & V_8 -> V_9 -> V_10 ) ;
T_1 V_17 = 0 ;
F_1 ( V_1 , true ) ;
if ( ( F_2 ( & V_1 -> V_4 ,
V_18 , & V_17 ) == 1 ) &&
( ( V_17 & V_19 ) ==
V_20 ) )
F_4 ( & V_1 -> V_4 , V_18 ,
( V_17 | V_21 ) ) ;
}
static void F_11 ( struct V_7 * V_8 )
{
F_1 ( F_6 ( & V_8 -> V_9 -> V_10 ) , false ) ;
}
static int F_12 ( struct V_7 * V_8 ,
enum V_22 V_22 )
{
struct V_1 * V_1 = F_6 ( & V_8 -> V_9 -> V_10 ) ;
struct V_23 * V_24 = & V_8 -> V_24 ;
F_10 ( V_8 ) ;
if ( V_1 -> V_14 [ 2 ] & V_15 )
V_24 -> V_25 . V_26 = 0xFFFF ;
else
V_24 -> V_25 . V_26 = 0xFF ;
V_24 -> V_25 . V_27 = 0 ;
V_24 -> V_25 . V_12 = F_5 ( V_8 ) ;
V_24 -> V_25 . V_28 = V_24 -> V_25 . V_12 != 0 ;
return 0 ;
}
static bool
F_13 ( struct V_7 * V_8 )
{
struct V_1 * V_1 = F_6 ( & V_8 -> V_9 -> V_10 ) ;
if ( V_1 -> V_14 [ 1 ] & V_29 &&
( V_1 -> V_14 [ 1 ] & V_30 ) &&
! ( ( V_1 -> V_14 [ 1 ] & V_31 ) ||
( V_1 -> V_14 [ 2 ] & V_32 ) ) ) {
F_3 ( L_6 ) ;
return true ;
}
return false ;
}
int F_14 ( struct V_7 * V_7 )
{
struct V_23 * V_24 = & V_7 -> V_24 ;
if ( ! V_33 . V_34 )
return - V_35 ;
if ( ! F_13 ( V_7 ) )
return - V_35 ;
V_24 -> V_25 . V_36 = F_12 ;
V_24 -> V_25 . V_2 = F_10 ;
V_24 -> V_25 . V_37 = F_11 ;
V_24 -> V_25 . V_38 = F_8 ;
V_24 -> V_25 . V_39 = F_5 ;
return 0 ;
}
