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
if ( ! F_10 ( V_2 , V_6 , & V_12 , V_9 , false ) )
return V_12 . V_13 ;
F_11 ( V_2 , V_6 >> V_14 , & V_10 ) ;
return ( ( ( T_3 ) V_6 >> 12 ) & 0xffff ) | ( V_10 << 16 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
F_13 ( V_2 , 0 ) ;
}
static T_4 F_14 ( struct V_1 * V_2 ,
T_1 V_15 , T_2 V_6 ,
bool V_16 )
{
struct V_17 * V_18 = F_15 ( V_2 ) ;
T_1 V_19 , V_20 , V_21 , V_22 ;
T_4 V_23 ;
V_19 = ( V_6 & 0x0FFFFFFF ) >> 12 ;
V_22 = ( ( V_18 -> V_24 & 0x1FF ) << 16 ) | 0xFFC0 ;
V_20 = ( ( F_3 ( V_15 ) ^ V_19 ) << 6 ) ;
if ( ! V_16 )
V_20 = ~ V_20 ;
V_20 &= V_22 ;
V_21 = ( V_18 -> V_24 & 0xffff0000 ) | V_20 ;
F_16 ( L_1 ,
F_17 ( & V_18 -> V_2 ) , V_6 , V_18 -> V_24 , V_21 ,
F_3 ( V_15 ) ) ;
V_23 = F_18 ( V_2 -> V_25 , V_21 >> V_26 ) ;
if ( F_19 ( V_23 ) )
return V_23 ;
return V_23 | ( V_21 & ~ V_27 ) ;
}
static T_1 F_20 ( T_1 V_15 , T_2 V_6 , bool V_16 )
{
return ( ( V_6 & 0x0fffffff ) >> 22 ) | ( F_3 ( V_15 ) << 7 ) |
( V_16 ? 0 : 0x40 ) | 0x80000000 ;
}
static int F_10 ( struct V_1 * V_2 , T_2 V_6 ,
struct V_11 * V_12 , bool V_9 ,
bool V_28 )
{
struct V_17 * V_18 = F_15 ( V_2 ) ;
struct V_29 * V_30 ;
int V_31 ;
for ( V_31 = 0 ; V_31 < 8 ; V_31 ++ ) {
if ( V_9 )
V_30 = & V_18 -> V_32 [ V_31 ] ;
else
V_30 = & V_18 -> V_33 [ V_31 ] ;
if ( V_2 -> V_3 . V_7 -> V_34 & V_35 ) {
if ( ! V_30 -> V_36 )
continue;
} else {
if ( ! V_30 -> V_37 )
continue;
}
if ( F_1 ( V_2 ) )
{
F_21 ( L_2 ,
V_9 ? 'd' : 'i' , V_31 , V_6 , V_30 -> V_38 ,
V_30 -> V_39 ) ;
}
if ( ( V_6 & V_30 -> V_39 ) == V_30 -> V_38 ) {
T_3 V_10 ;
F_11 ( V_2 ,
V_6 >> V_14 , & V_10 ) ;
V_10 <<= 16 ;
V_12 -> V_13 = ( ( ( T_3 ) V_6 >> 12 ) & 0xffff ) | V_10 ;
V_12 -> V_40 = V_30 -> V_41 | ( V_6 & ~ V_30 -> V_39 ) ;
V_12 -> V_42 = V_30 -> V_43 ;
V_12 -> V_44 = V_30 -> V_43 > 1 ;
V_12 -> V_45 = true ;
if ( ! V_12 -> V_42 ) {
F_22 ( V_46 L_3 ) ;
continue;
}
if ( V_28 && ! V_12 -> V_44 ) {
F_21 ( L_4 ) ;
continue;
}
return 0 ;
}
}
return - V_47 ;
}
static int F_23 ( struct V_1 * V_2 , T_2 V_6 ,
struct V_11 * V_12 , bool V_9 ,
bool V_28 , bool V_16 )
{
T_1 V_15 ;
T_4 V_48 ;
T_1 V_21 [ 16 ] ;
T_1 V_49 = 0 ;
int V_31 ;
int V_50 = 0 ;
V_15 = F_8 ( V_2 , V_6 ) ;
F_21 ( L_5 , V_6 >> 28 ,
F_3 ( V_15 ) , V_15 ) ;
V_12 -> V_13 = F_9 ( V_2 , V_6 , V_9 ) ;
V_48 = F_14 ( V_2 , V_15 , V_6 , V_16 ) ;
if ( F_19 ( V_48 ) ) {
F_22 ( V_46 L_6 ) ;
goto V_51;
}
V_49 = F_20 ( V_15 , V_6 , V_16 ) ;
if( F_24 ( V_21 , ( void V_52 * ) V_48 , sizeof( V_21 ) ) ) {
F_22 ( V_53 L_7 , V_48 ) ;
goto V_51;
}
for ( V_31 = 0 ; V_31 < 16 ; V_31 += 2 ) {
if ( V_49 == V_21 [ V_31 ] ) {
T_5 V_43 ;
V_12 -> V_40 = ( V_21 [ V_31 + 1 ] & ~ ( 0xFFFULL ) ) | ( V_6 & 0xFFF ) ;
V_43 = V_21 [ V_31 + 1 ] & 3 ;
if ( ( F_6 ( V_15 ) && ( V_2 -> V_3 . V_7 -> V_34 & V_35 ) ) ||
( F_5 ( V_15 ) && ! ( V_2 -> V_3 . V_7 -> V_34 & V_35 ) ) )
V_43 |= 4 ;
V_12 -> V_44 = false ;
V_12 -> V_42 = false ;
V_12 -> V_45 = true ;
switch ( V_43 ) {
case 0 :
case 1 :
case 2 :
case 6 :
V_12 -> V_44 = true ;
case 3 :
case 5 :
case 7 :
V_12 -> V_42 = true ;
break;
}
F_21 ( L_8 ,
V_21 [ V_31 ] , V_21 [ V_31 + 1 ] , V_43 ) ;
V_50 = 1 ;
break;
}
}
if ( V_50 ) {
T_1 V_54 = V_21 [ V_31 + 1 ] ;
char V_52 * V_55 = ( char V_52 * ) & V_21 [ V_31 + 1 ] ;
if ( V_12 -> V_42 && ! ( V_54 & V_56 ) ) {
V_54 |= V_56 ;
F_25 ( V_54 >> 8 , V_55 + 2 ) ;
}
if ( V_28 && V_12 -> V_44 && ! ( V_54 & V_57 ) ) {
V_54 |= V_57 ;
F_25 ( V_54 , V_55 + 3 ) ;
}
if ( ! V_12 -> V_42 || ( V_28 && ! V_12 -> V_44 ) )
return - V_58 ;
return 0 ;
}
V_51:
if ( F_1 ( V_2 ) ) {
F_21 ( L_9 ,
F_15 ( V_2 ) -> V_24 , V_48 ) ;
for ( V_31 = 0 ; V_31 < 16 ; V_31 += 2 ) {
F_21 ( L_10 ,
V_31 , V_21 [ V_31 ] , V_21 [ V_31 + 1 ] , V_49 ) ;
}
}
return - V_47 ;
}
static int F_26 ( struct V_1 * V_2 , T_2 V_6 ,
struct V_11 * V_12 , bool V_9 ,
bool V_28 )
{
int V_23 ;
T_6 V_59 = V_2 -> V_3 . V_60 ;
V_12 -> V_6 = V_6 ;
V_12 -> V_61 = V_62 ;
if ( F_27 ( V_59 ) &&
F_27 ( ( V_6 & ~ 0xfffULL ) == ( V_59 & ~ 0xfffULL ) ) &&
! ( V_2 -> V_3 . V_7 -> V_34 & V_35 ) ) {
V_12 -> V_13 = F_9 ( V_2 , V_6 , V_9 ) ;
V_12 -> V_40 = V_2 -> V_3 . V_63 | ( V_12 -> V_40 & 0xfff ) ;
V_12 -> V_40 &= V_64 ;
V_12 -> V_45 = true ;
V_12 -> V_42 = true ;
V_12 -> V_44 = true ;
return 0 ;
}
V_23 = F_10 ( V_2 , V_6 , V_12 , V_9 , V_28 ) ;
if ( V_23 < 0 )
V_23 = F_23 ( V_2 , V_6 , V_12 ,
V_9 , V_28 , true ) ;
if ( V_23 < 0 )
V_23 = F_23 ( V_2 , V_6 , V_12 ,
V_9 , V_28 , false ) ;
return V_23 ;
}
static T_1 F_28 ( struct V_1 * V_2 , T_1 V_65 )
{
return V_2 -> V_3 . V_7 -> V_8 [ V_65 ] ;
}
static void F_29 ( struct V_1 * V_2 , T_1 V_65 ,
T_6 V_66 )
{
V_2 -> V_3 . V_7 -> V_8 [ V_65 ] = V_66 ;
F_30 ( V_2 , V_65 << V_14 ) ;
}
static void F_31 ( struct V_1 * V_2 , T_6 V_67 , bool V_68 )
{
int V_31 ;
struct V_1 * V_69 ;
F_32 (i, v, vcpu->kvm)
F_33 ( V_69 , V_67 , 0x0FFFF000 ) ;
}
static int F_11 ( struct V_1 * V_2 , T_6 V_70 ,
T_3 * V_10 )
{
T_6 V_67 = V_70 << V_14 ;
T_1 V_8 ;
T_3 V_71 = V_70 ;
if ( V_2 -> V_3 . V_7 -> V_34 & ( V_72 | V_73 ) ) {
V_8 = F_8 ( V_2 , V_67 ) ;
if ( F_4 ( V_8 ) )
V_71 = F_3 ( V_8 ) ;
}
switch ( V_2 -> V_3 . V_7 -> V_34 & ( V_72 | V_73 ) ) {
case 0 :
* V_10 = V_74 | V_70 ;
break;
case V_73 :
* V_10 = V_75 | V_71 ;
break;
case V_72 :
* V_10 = V_76 | V_71 ;
break;
case V_72 | V_73 :
if ( F_4 ( V_8 ) )
* V_10 = F_3 ( V_8 ) ;
else
* V_10 = V_77 | V_71 ;
break;
default:
F_34 () ;
}
if ( V_2 -> V_3 . V_7 -> V_34 & V_35 )
* V_10 |= V_78 ;
return 0 ;
}
static bool F_35 ( struct V_1 * V_2 )
{
return true ;
}
void F_36 ( struct V_1 * V_2 )
{
struct V_79 * V_80 = & V_2 -> V_3 . V_80 ;
V_80 -> V_81 = F_29 ;
V_80 -> V_82 = F_28 ;
V_80 -> V_83 = F_26 ;
V_80 -> V_84 = F_12 ;
V_80 -> V_85 = F_31 ;
V_80 -> V_86 = F_11 ;
V_80 -> V_87 = F_9 ;
V_80 -> V_88 = F_35 ;
V_80 -> V_89 = NULL ;
V_80 -> V_90 = NULL ;
V_80 -> V_91 = NULL ;
V_80 -> V_92 = NULL ;
V_80 -> V_93 = NULL ;
}
