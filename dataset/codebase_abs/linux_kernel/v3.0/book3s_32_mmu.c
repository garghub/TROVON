static inline bool F_1 ( struct V_1 * V_2 )
{
#ifdef F_2
return V_2 -> V_3 . V_4 == F_2 ;
#else
return true ;
#endif
}
static inline T_1 F_3 ( T_1 V_5 )
{
return V_5 & 0x0fffffff ;
}
static inline bool F_4 ( T_1 V_5 )
{
return ( V_5 & 0x80000000 ) ? false : true ;
}
static inline bool F_5 ( T_1 V_5 )
{
return ( V_5 & 0x40000000 ) ? true : false ;
}
static inline bool F_6 ( T_1 V_5 )
{
return ( V_5 & 0x20000000 ) ? true : false ;
}
static inline bool F_7 ( T_1 V_5 )
{
return ( V_5 & 0x10000000 ) ? true : false ;
}
static T_1 F_8 ( struct V_1 * V_2 , T_2 V_6 )
{
return V_2 -> V_3 . V_7 -> V_8 [ ( V_6 >> 28 ) & 0xf ] ;
}
static T_3 F_9 ( struct V_1 * V_2 , T_2 V_6 ,
bool V_9 )
{
T_3 V_10 ;
struct V_11 V_12 ;
if ( ! F_10 ( V_2 , V_6 , & V_12 , V_9 ) )
return V_12 . V_13 ;
F_11 ( V_2 , V_6 >> V_14 , & V_10 ) ;
return ( ( ( T_3 ) V_6 >> 12 ) & 0xffff ) | ( V_10 << 16 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
F_13 ( V_2 , 0 ) ;
}
static T_4 F_14 ( struct V_15 * V_16 ,
T_1 V_17 , T_2 V_6 ,
bool V_18 )
{
T_1 V_19 , V_20 , V_21 , V_22 ;
T_4 V_23 ;
V_19 = ( V_6 & 0x0FFFFFFF ) >> 12 ;
V_22 = ( ( V_16 -> V_24 & 0x1FF ) << 16 ) | 0xFFC0 ;
V_20 = ( ( F_3 ( V_17 ) ^ V_19 ) << 6 ) ;
if ( ! V_18 )
V_20 = ~ V_20 ;
V_20 &= V_22 ;
V_21 = ( V_16 -> V_24 & 0xffff0000 ) | V_20 ;
F_15 ( L_1 ,
F_16 ( & V_16 -> V_2 ) , V_6 , V_16 -> V_24 , V_21 ,
F_3 ( V_17 ) ) ;
V_23 = F_17 ( V_16 -> V_2 . V_25 , V_21 >> V_26 ) ;
if ( F_18 ( V_23 ) )
return V_23 ;
return V_23 | ( V_21 & ~ V_27 ) ;
}
static T_1 F_19 ( T_1 V_17 , T_2 V_6 , bool V_18 )
{
return ( ( V_6 & 0x0fffffff ) >> 22 ) | ( F_3 ( V_17 ) << 7 ) |
( V_18 ? 0 : 0x40 ) | 0x80000000 ;
}
static int F_10 ( struct V_1 * V_2 , T_2 V_6 ,
struct V_11 * V_12 , bool V_9 )
{
struct V_15 * V_16 = F_20 ( V_2 ) ;
struct V_28 * V_29 ;
int V_30 ;
for ( V_30 = 0 ; V_30 < 8 ; V_30 ++ ) {
if ( V_9 )
V_29 = & V_16 -> V_31 [ V_30 ] ;
else
V_29 = & V_16 -> V_32 [ V_30 ] ;
if ( V_2 -> V_3 . V_7 -> V_33 & V_34 ) {
if ( ! V_29 -> V_35 )
continue;
} else {
if ( ! V_29 -> V_36 )
continue;
}
if ( F_1 ( V_2 ) )
{
F_21 ( L_2 ,
V_9 ? 'd' : 'i' , V_30 , V_6 , V_29 -> V_37 ,
V_29 -> V_38 ) ;
}
if ( ( V_6 & V_29 -> V_38 ) == V_29 -> V_37 ) {
T_3 V_10 ;
F_11 ( V_2 ,
V_6 >> V_14 , & V_10 ) ;
V_10 <<= 16 ;
V_12 -> V_13 = ( ( ( T_3 ) V_6 >> 12 ) & 0xffff ) | V_10 ;
V_12 -> V_39 = V_29 -> V_40 | ( V_6 & ~ V_29 -> V_38 ) ;
V_12 -> V_41 = V_29 -> V_42 ;
V_12 -> V_43 = V_29 -> V_42 > 1 ;
V_12 -> V_44 = true ;
if ( ! V_12 -> V_41 ) {
F_22 ( V_45 L_3 ) ;
continue;
}
if ( ! V_12 -> V_43 ) {
F_21 ( L_4 ) ;
continue;
}
return 0 ;
}
}
return - V_46 ;
}
static int F_23 ( struct V_1 * V_2 , T_2 V_6 ,
struct V_11 * V_12 , bool V_9 ,
bool V_18 )
{
struct V_15 * V_16 = F_20 ( V_2 ) ;
T_1 V_17 ;
T_4 V_47 ;
T_1 V_21 [ 16 ] ;
T_1 V_48 = 0 ;
int V_30 ;
int V_49 = 0 ;
V_17 = F_8 ( V_2 , V_6 ) ;
F_21 ( L_5 , V_6 >> 28 ,
F_3 ( V_17 ) , V_17 ) ;
V_12 -> V_13 = F_9 ( V_2 , V_6 , V_9 ) ;
V_47 = F_14 ( V_16 , V_17 , V_6 , V_18 ) ;
if ( F_18 ( V_47 ) ) {
F_22 ( V_45 L_6 ) ;
goto V_50;
}
V_48 = F_19 ( V_17 , V_6 , V_18 ) ;
if( F_24 ( V_21 , ( void V_51 * ) V_47 , sizeof( V_21 ) ) ) {
F_22 ( V_52 L_7 , V_47 ) ;
goto V_50;
}
for ( V_30 = 0 ; V_30 < 16 ; V_30 += 2 ) {
if ( V_48 == V_21 [ V_30 ] ) {
T_5 V_42 ;
V_12 -> V_39 = ( V_21 [ V_30 + 1 ] & ~ ( 0xFFFULL ) ) | ( V_6 & 0xFFF ) ;
V_42 = V_21 [ V_30 + 1 ] & 3 ;
if ( ( F_6 ( V_17 ) && ( V_2 -> V_3 . V_7 -> V_33 & V_34 ) ) ||
( F_5 ( V_17 ) && ! ( V_2 -> V_3 . V_7 -> V_33 & V_34 ) ) )
V_42 |= 4 ;
V_12 -> V_43 = false ;
V_12 -> V_41 = false ;
V_12 -> V_44 = true ;
switch ( V_42 ) {
case 0 :
case 1 :
case 2 :
case 6 :
V_12 -> V_43 = true ;
case 3 :
case 5 :
case 7 :
V_12 -> V_41 = true ;
break;
}
if ( ! V_12 -> V_41 )
continue;
F_21 ( L_8 ,
V_21 [ V_30 ] , V_21 [ V_30 + 1 ] , V_42 ) ;
V_49 = 1 ;
break;
}
}
if ( V_49 ) {
T_1 V_53 = V_21 [ V_30 + 1 ] ;
if ( V_12 -> V_41 )
V_21 [ V_30 + 1 ] |= V_54 ;
if ( V_12 -> V_43 )
V_21 [ V_30 + 1 ] |= V_55 ;
else
F_21 ( L_9 ) ;
if ( V_21 [ V_30 + 1 ] != V_53 )
F_25 ( ( void V_51 * ) V_47 , V_21 , sizeof( V_21 ) ) ;
return 0 ;
}
V_50:
if ( F_1 ( V_2 ) ) {
F_21 ( L_10 ,
F_20 ( V_2 ) -> V_24 , V_47 ) ;
for ( V_30 = 0 ; V_30 < 16 ; V_30 += 2 ) {
F_21 ( L_11 ,
V_30 , V_21 [ V_30 ] , V_21 [ V_30 + 1 ] , V_48 ) ;
}
}
return - V_46 ;
}
static int F_26 ( struct V_1 * V_2 , T_2 V_6 ,
struct V_11 * V_12 , bool V_9 )
{
int V_23 ;
T_6 V_56 = V_2 -> V_3 . V_57 ;
V_12 -> V_6 = V_6 ;
if ( F_27 ( V_56 ) &&
F_27 ( ( V_6 & ~ 0xfffULL ) == ( V_56 & ~ 0xfffULL ) ) &&
! ( V_2 -> V_3 . V_7 -> V_33 & V_34 ) ) {
V_12 -> V_13 = F_9 ( V_2 , V_6 , V_9 ) ;
V_12 -> V_39 = V_2 -> V_3 . V_58 | ( V_12 -> V_39 & 0xfff ) ;
V_12 -> V_39 &= V_59 ;
V_12 -> V_44 = true ;
V_12 -> V_41 = true ;
V_12 -> V_43 = true ;
return 0 ;
}
V_23 = F_10 ( V_2 , V_6 , V_12 , V_9 ) ;
if ( V_23 < 0 )
V_23 = F_23 ( V_2 , V_6 , V_12 , V_9 , true ) ;
if ( V_23 < 0 )
V_23 = F_23 ( V_2 , V_6 , V_12 , V_9 , false ) ;
return V_23 ;
}
static T_1 F_28 ( struct V_1 * V_2 , T_1 V_60 )
{
return V_2 -> V_3 . V_7 -> V_8 [ V_60 ] ;
}
static void F_29 ( struct V_1 * V_2 , T_1 V_60 ,
T_6 V_61 )
{
V_2 -> V_3 . V_7 -> V_8 [ V_60 ] = V_61 ;
F_30 ( V_2 , V_60 << V_14 ) ;
}
static void F_31 ( struct V_1 * V_2 , T_6 V_62 , bool V_63 )
{
F_32 ( V_2 , V_62 , 0x0FFFF000 ) ;
}
static int F_11 ( struct V_1 * V_2 , T_6 V_64 ,
T_3 * V_10 )
{
T_6 V_62 = V_64 << V_14 ;
T_1 V_8 ;
T_3 V_65 = V_64 ;
if ( V_2 -> V_3 . V_7 -> V_33 & ( V_66 | V_67 ) ) {
V_8 = F_8 ( V_2 , V_62 ) ;
if ( F_4 ( V_8 ) )
V_65 = F_3 ( V_8 ) ;
}
switch ( V_2 -> V_3 . V_7 -> V_33 & ( V_66 | V_67 ) ) {
case 0 :
* V_10 = V_68 | V_64 ;
break;
case V_67 :
* V_10 = V_69 | V_65 ;
break;
case V_66 :
* V_10 = V_70 | V_65 ;
break;
case V_66 | V_67 :
if ( F_4 ( V_8 ) )
* V_10 = F_3 ( V_8 ) ;
else
* V_10 = V_71 | V_65 ;
break;
default:
F_33 () ;
}
if ( V_2 -> V_3 . V_7 -> V_33 & V_34 )
* V_10 |= V_72 ;
return 0 ;
}
static bool F_34 ( struct V_1 * V_2 )
{
return true ;
}
void F_35 ( struct V_1 * V_2 )
{
struct V_73 * V_74 = & V_2 -> V_3 . V_74 ;
V_74 -> V_75 = F_29 ;
V_74 -> V_76 = F_28 ;
V_74 -> V_77 = F_26 ;
V_74 -> V_78 = F_12 ;
V_74 -> V_79 = F_31 ;
V_74 -> V_80 = F_11 ;
V_74 -> V_81 = F_9 ;
V_74 -> V_82 = F_34 ;
V_74 -> V_83 = NULL ;
V_74 -> V_84 = NULL ;
V_74 -> V_85 = NULL ;
V_74 -> V_86 = NULL ;
V_74 -> V_87 = NULL ;
}
