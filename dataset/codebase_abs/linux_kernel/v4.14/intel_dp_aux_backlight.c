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
static bool F_11 ( struct V_9 * V_10 )
{
struct V_20 * V_21 = F_12 ( V_10 -> V_12 . V_22 ) ;
struct V_1 * V_1 = F_6 ( & V_10 -> V_11 -> V_12 ) ;
int V_23 , V_24 , V_25 , V_26 , V_27 , V_28 = 1 ;
T_5 V_29 , V_30 , V_31 ;
V_23 = V_21 -> V_32 . V_33 . V_34 ;
F_3 ( L_6 , V_23 ) ;
if ( ! V_23 ) {
F_3 ( L_7 ) ;
return false ;
}
V_24 = F_13 ( F_14 ( V_35 ) , V_23 ) ;
if ( F_2 ( & V_1 -> V_6 ,
V_36 , & V_30 ) != 1 ) {
F_3 ( L_8 ) ;
return false ;
}
if ( F_2 ( & V_1 -> V_6 ,
V_37 , & V_31 ) != 1 ) {
F_3 ( L_9 ) ;
return false ;
}
V_30 &= V_38 ;
V_31 &= V_38 ;
V_25 = F_13 ( V_24 * 3 , 4 ) ;
V_26 = F_13 ( V_24 * 5 , 4 ) ;
if ( V_25 < ( 1 << V_30 ) || ( 255 << V_31 ) < V_26 ) {
F_3 ( L_10 ) ;
return false ;
}
for ( V_29 = V_31 ; V_29 >= V_30 ; V_29 -- ) {
V_28 = F_15 ( F_13 ( V_24 , 1 << V_29 ) , 1 , 255 ) ;
V_27 = V_28 << V_29 ;
if ( V_25 <= V_27 && V_27 <= V_26 )
break;
}
if ( F_4 ( & V_1 -> V_6 ,
V_39 , V_29 ) < 0 ) {
F_3 ( L_11 ) ;
return false ;
}
if ( F_4 ( & V_1 -> V_6 ,
V_40 , ( T_5 ) V_28 ) < 0 ) {
F_3 ( L_12 ) ;
return false ;
}
return true ;
}
static void F_16 ( const struct V_41 * V_42 ,
const struct V_17 * V_18 )
{
struct V_9 * V_10 = F_9 ( V_18 -> V_10 ) ;
struct V_1 * V_1 = F_6 ( & V_10 -> V_11 -> V_12 ) ;
T_1 V_43 , V_44 , V_45 ;
if ( F_2 ( & V_1 -> V_6 ,
V_46 , & V_43 ) != 1 ) {
F_3 ( L_1 ,
V_46 ) ;
return;
}
V_44 = V_43 ;
V_45 = V_43 & V_47 ;
switch ( V_45 ) {
case V_48 :
case V_49 :
case V_50 :
V_44 &= ~ V_47 ;
V_44 |= V_51 ;
break;
case V_51 :
default:
break;
}
if ( V_1 -> V_4 [ 2 ] & V_52 )
if ( F_11 ( V_10 ) )
V_44 |= V_53 ;
if ( V_44 != V_43 ) {
if ( F_4 ( & V_1 -> V_6 ,
V_46 , V_44 ) < 0 ) {
F_3 ( L_13 ) ;
}
}
F_1 ( V_1 , true ) ;
F_8 ( V_18 , V_10 -> V_54 . V_33 . V_14 ) ;
}
static void F_17 ( const struct V_17 * V_55 )
{
F_1 ( F_6 ( V_55 -> V_56 ) , false ) ;
}
static int F_18 ( struct V_9 * V_10 ,
enum V_57 V_57 )
{
struct V_1 * V_1 = F_6 ( & V_10 -> V_11 -> V_12 ) ;
struct V_58 * V_54 = & V_10 -> V_54 ;
if ( V_1 -> V_4 [ 2 ] & V_16 )
V_54 -> V_33 . V_59 = 0xFFFF ;
else
V_54 -> V_33 . V_59 = 0xFF ;
V_54 -> V_33 . V_60 = 0 ;
V_54 -> V_33 . V_14 = F_5 ( V_10 ) ;
V_54 -> V_33 . V_61 = V_54 -> V_33 . V_14 != 0 ;
return 0 ;
}
static bool
F_19 ( struct V_9 * V_10 )
{
struct V_1 * V_1 = F_6 ( & V_10 -> V_11 -> V_12 ) ;
if ( V_1 -> V_4 [ 1 ] & V_62 &&
( V_1 -> V_4 [ 2 ] & V_63 ) &&
! ( V_1 -> V_4 [ 2 ] & V_64 ) ) {
F_3 ( L_14 ) ;
return true ;
}
return false ;
}
int F_20 ( struct V_9 * V_9 )
{
struct V_58 * V_54 = & V_9 -> V_54 ;
if ( ! V_65 . V_66 )
return - V_67 ;
if ( ! F_19 ( V_9 ) )
return - V_67 ;
V_54 -> V_33 . V_68 = F_18 ;
V_54 -> V_33 . V_2 = F_16 ;
V_54 -> V_33 . V_69 = F_17 ;
V_54 -> V_33 . V_70 = F_8 ;
V_54 -> V_33 . V_71 = F_5 ;
return 0 ;
}
