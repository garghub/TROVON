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
static T_1 F_7 ( struct V_1 * V_2 , T_2 V_6 )
{
return F_8 ( V_2 , ( V_6 >> 28 ) & 0xf ) ;
}
static T_3 F_9 ( struct V_1 * V_2 , T_2 V_6 ,
bool V_7 )
{
T_3 V_8 ;
struct V_9 V_10 ;
if ( ! F_10 ( V_2 , V_6 , & V_10 , V_7 , false ) )
return V_10 . V_11 ;
F_11 ( V_2 , V_6 >> V_12 , & V_8 ) ;
return ( ( ( T_3 ) V_6 >> 12 ) & 0xffff ) | ( V_8 << 16 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
F_13 ( V_2 , 0 ) ;
}
static T_4 F_14 ( struct V_1 * V_2 ,
T_1 V_13 , T_2 V_6 ,
bool V_14 )
{
struct V_15 * V_16 = F_15 ( V_2 ) ;
T_1 V_17 , V_18 , V_19 , V_20 ;
T_4 V_21 ;
V_17 = ( V_6 & 0x0FFFFFFF ) >> 12 ;
V_20 = ( ( V_16 -> V_22 & 0x1FF ) << 16 ) | 0xFFC0 ;
V_18 = ( ( F_3 ( V_13 ) ^ V_17 ) << 6 ) ;
if ( ! V_14 )
V_18 = ~ V_18 ;
V_18 &= V_20 ;
V_19 = ( V_16 -> V_22 & 0xffff0000 ) | V_18 ;
F_16 ( L_1 ,
F_17 ( V_2 ) , V_6 , V_16 -> V_22 , V_19 ,
F_3 ( V_13 ) ) ;
V_21 = F_18 ( V_2 -> V_23 , V_19 >> V_24 ) ;
if ( F_19 ( V_21 ) )
return V_21 ;
return V_21 | ( V_19 & ~ V_25 ) ;
}
static T_1 F_20 ( T_1 V_13 , T_2 V_6 , bool V_14 )
{
return ( ( V_6 & 0x0fffffff ) >> 22 ) | ( F_3 ( V_13 ) << 7 ) |
( V_14 ? 0 : 0x40 ) | 0x80000000 ;
}
static int F_10 ( struct V_1 * V_2 , T_2 V_6 ,
struct V_9 * V_10 , bool V_7 ,
bool V_26 )
{
struct V_15 * V_16 = F_15 ( V_2 ) ;
struct V_27 * V_28 ;
int V_29 ;
for ( V_29 = 0 ; V_29 < 8 ; V_29 ++ ) {
if ( V_7 )
V_28 = & V_16 -> V_30 [ V_29 ] ;
else
V_28 = & V_16 -> V_31 [ V_29 ] ;
if ( F_21 ( V_2 ) & V_32 ) {
if ( ! V_28 -> V_33 )
continue;
} else {
if ( ! V_28 -> V_34 )
continue;
}
if ( F_1 ( V_2 ) )
{
F_22 ( L_2 ,
V_7 ? 'd' : 'i' , V_29 , V_6 , V_28 -> V_35 ,
V_28 -> V_36 ) ;
}
if ( ( V_6 & V_28 -> V_36 ) == V_28 -> V_35 ) {
T_3 V_8 ;
F_11 ( V_2 ,
V_6 >> V_12 , & V_8 ) ;
V_8 <<= 16 ;
V_10 -> V_11 = ( ( ( T_3 ) V_6 >> 12 ) & 0xffff ) | V_8 ;
V_10 -> V_37 = V_28 -> V_38 | ( V_6 & ~ V_28 -> V_36 ) ;
V_10 -> V_39 = V_28 -> V_40 ;
V_10 -> V_41 = V_28 -> V_40 > 1 ;
V_10 -> V_42 = true ;
if ( ! V_10 -> V_39 ) {
F_23 ( V_43 L_3 ) ;
continue;
}
if ( V_26 && ! V_10 -> V_41 ) {
F_22 ( L_4 ) ;
continue;
}
return 0 ;
}
}
return - V_44 ;
}
static int F_24 ( struct V_1 * V_2 , T_2 V_6 ,
struct V_9 * V_10 , bool V_7 ,
bool V_26 , bool V_14 )
{
T_1 V_13 ;
T_4 V_45 ;
T_1 V_19 [ 16 ] ;
T_1 V_46 , V_47 ;
T_1 V_48 = 0 ;
int V_29 ;
int V_49 = 0 ;
V_13 = F_7 ( V_2 , V_6 ) ;
F_22 ( L_5 , V_6 >> 28 ,
F_3 ( V_13 ) , V_13 ) ;
V_10 -> V_11 = F_9 ( V_2 , V_6 , V_7 ) ;
V_45 = F_14 ( V_2 , V_13 , V_6 , V_14 ) ;
if ( F_19 ( V_45 ) ) {
F_23 ( V_43 L_6 ) ;
goto V_50;
}
V_48 = F_20 ( V_13 , V_6 , V_14 ) ;
if( F_25 ( V_19 , ( void V_51 * ) V_45 , sizeof( V_19 ) ) ) {
F_23 ( V_52 L_7 , V_45 ) ;
goto V_50;
}
for ( V_29 = 0 ; V_29 < 16 ; V_29 += 2 ) {
V_46 = F_26 ( V_19 [ V_29 ] ) ;
V_47 = F_26 ( V_19 [ V_29 + 1 ] ) ;
if ( V_48 == V_46 ) {
T_5 V_40 ;
V_10 -> V_37 = ( V_47 & ~ ( 0xFFFULL ) ) | ( V_6 & 0xFFF ) ;
V_40 = V_47 & 3 ;
if ( ( F_6 ( V_13 ) && ( F_21 ( V_2 ) & V_32 ) ) ||
( F_5 ( V_13 ) && ! ( F_21 ( V_2 ) & V_32 ) ) )
V_40 |= 4 ;
V_10 -> V_41 = false ;
V_10 -> V_39 = false ;
V_10 -> V_42 = true ;
switch ( V_40 ) {
case 0 :
case 1 :
case 2 :
case 6 :
V_10 -> V_41 = true ;
case 3 :
case 5 :
case 7 :
V_10 -> V_39 = true ;
break;
}
F_22 ( L_8 ,
V_46 , V_47 , V_40 ) ;
V_49 = 1 ;
break;
}
}
if ( V_49 ) {
T_1 V_53 = V_47 ;
char V_51 * V_54 = ( char V_51 * ) ( V_45 + ( V_29 + 1 ) * sizeof( T_1 ) ) ;
if ( V_10 -> V_39 && ! ( V_53 & V_55 ) ) {
V_53 |= V_55 ;
F_27 ( V_53 >> 8 , V_54 + 2 ) ;
}
if ( V_26 && V_10 -> V_41 && ! ( V_53 & V_56 ) ) {
V_53 |= V_56 ;
F_27 ( V_53 , V_54 + 3 ) ;
}
if ( ! V_10 -> V_39 || ( V_26 && ! V_10 -> V_41 ) )
return - V_57 ;
return 0 ;
}
V_50:
if ( F_1 ( V_2 ) ) {
F_22 ( L_9 ,
F_15 ( V_2 ) -> V_22 , V_45 ) ;
for ( V_29 = 0 ; V_29 < 16 ; V_29 += 2 ) {
F_22 ( L_10 ,
V_29 , F_26 ( V_19 [ V_29 ] ) ,
F_26 ( V_19 [ V_29 + 1 ] ) , V_48 ) ;
}
}
return - V_44 ;
}
static int F_28 ( struct V_1 * V_2 , T_2 V_6 ,
struct V_9 * V_10 , bool V_7 ,
bool V_26 )
{
int V_21 ;
T_6 V_58 = V_2 -> V_3 . V_59 ;
V_10 -> V_6 = V_6 ;
V_10 -> V_60 = V_61 ;
if ( F_29 ( V_58 ) &&
F_29 ( ( V_6 & ~ 0xfffULL ) == ( V_58 & ~ 0xfffULL ) ) &&
! ( F_21 ( V_2 ) & V_32 ) ) {
V_10 -> V_11 = F_9 ( V_2 , V_6 , V_7 ) ;
V_10 -> V_37 = V_2 -> V_3 . V_62 | ( V_10 -> V_37 & 0xfff ) ;
V_10 -> V_37 &= V_63 ;
V_10 -> V_42 = true ;
V_10 -> V_39 = true ;
V_10 -> V_41 = true ;
return 0 ;
}
V_21 = F_10 ( V_2 , V_6 , V_10 , V_7 , V_26 ) ;
if ( V_21 < 0 )
V_21 = F_24 ( V_2 , V_6 , V_10 ,
V_7 , V_26 , true ) ;
if ( V_21 == - V_44 )
V_21 = F_24 ( V_2 , V_6 , V_10 ,
V_7 , V_26 , false ) ;
return V_21 ;
}
static T_1 F_30 ( struct V_1 * V_2 , T_1 V_64 )
{
return F_8 ( V_2 , V_64 ) ;
}
static void F_31 ( struct V_1 * V_2 , T_1 V_64 ,
T_6 V_65 )
{
F_32 ( V_2 , V_64 , V_65 ) ;
F_33 ( V_2 , V_64 << V_12 ) ;
}
static void F_34 ( struct V_1 * V_2 , T_6 V_66 , bool V_67 )
{
int V_29 ;
struct V_1 * V_68 ;
F_35 (i, v, vcpu->kvm)
F_36 ( V_68 , V_66 , 0x0FFFF000 ) ;
}
static int F_11 ( struct V_1 * V_2 , T_6 V_69 ,
T_3 * V_8 )
{
T_6 V_66 = V_69 << V_12 ;
T_1 V_70 ;
T_3 V_71 = V_69 ;
T_3 V_72 = F_21 ( V_2 ) ;
if ( V_72 & ( V_73 | V_74 ) ) {
V_70 = F_7 ( V_2 , V_66 ) ;
if ( F_4 ( V_70 ) )
V_71 = F_3 ( V_70 ) ;
}
switch ( V_72 & ( V_73 | V_74 ) ) {
case 0 :
* V_8 = V_75 | V_69 ;
break;
case V_74 :
* V_8 = V_76 | V_71 ;
break;
case V_73 :
* V_8 = V_77 | V_71 ;
break;
case V_73 | V_74 :
if ( F_4 ( V_70 ) )
* V_8 = F_3 ( V_70 ) ;
else
* V_8 = V_78 | V_71 ;
break;
default:
F_37 () ;
}
if ( V_72 & V_32 )
* V_8 |= V_79 ;
return 0 ;
}
static bool F_38 ( struct V_1 * V_2 )
{
return true ;
}
void F_39 ( struct V_1 * V_2 )
{
struct V_80 * V_81 = & V_2 -> V_3 . V_81 ;
V_81 -> V_82 = F_31 ;
V_81 -> V_83 = F_30 ;
V_81 -> V_84 = F_28 ;
V_81 -> V_85 = F_12 ;
V_81 -> V_86 = F_34 ;
V_81 -> V_87 = F_11 ;
V_81 -> V_88 = F_9 ;
V_81 -> V_89 = F_38 ;
V_81 -> V_90 = NULL ;
V_81 -> V_91 = NULL ;
V_81 -> V_92 = NULL ;
V_81 -> V_93 = NULL ;
V_81 -> V_94 = NULL ;
}
