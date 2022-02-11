static inline void
F_1 ( int V_1 , int V_2 , int V_3 )
{
F_2 ( V_2 , V_1 ) ;
F_2 ( V_3 , V_1 + 1 ) ;
}
static inline int
F_3 ( int V_1 , int V_2 )
{
F_2 ( V_2 , V_1 ) ;
return F_4 ( V_1 + 1 ) ;
}
static inline void
F_5 ( int V_1 , int V_4 )
{
F_2 ( V_5 , V_1 ) ;
F_2 ( V_4 , V_1 + 1 ) ;
}
static inline int
F_6 ( int V_1 )
{
if ( ! F_7 ( V_1 , 2 , V_6 ) )
return - V_7 ;
F_2 ( 0x87 , V_1 ) ;
F_2 ( 0x87 , V_1 ) ;
return 0 ;
}
static inline void
F_8 ( int V_1 )
{
F_2 ( 0xaa , V_1 ) ;
F_2 ( 0x02 , V_1 ) ;
F_2 ( 0x02 , V_1 + 1 ) ;
F_9 ( V_1 , 2 ) ;
}
static enum V_8 F_10 ( int V_9 , int V_10 )
{
if ( V_10 == 0 && V_9 == 255 )
return V_11 ;
return V_10 + 1 ;
}
static int F_11 ( enum V_8 V_10 )
{
if ( V_10 == V_11 )
return 0 ;
return V_10 - 1 ;
}
static unsigned int F_12 ( T_1 V_2 , T_1 V_10 )
{
return V_10 ? 400 * V_2 : 100 * V_2 ;
}
static T_1 F_13 ( unsigned int V_12 , T_1 V_10 )
{
return F_14 ( ( V_10 ? ( V_12 + 200 ) / 400 :
( V_12 + 50 ) / 100 ) , 1 , 255 ) ;
}
static unsigned int F_15 ( T_2 V_2 , unsigned int V_13 )
{
if ( V_2 == 0 || V_2 == 255 )
return 0 ;
return 1350000U / ( V_2 << V_13 ) ;
}
static unsigned int F_16 ( T_2 V_2 , unsigned int V_13 )
{
if ( ( V_2 & 0xff1f ) == 0xff1f )
return 0 ;
V_2 = ( V_2 & 0x1f ) | ( ( V_2 & 0xff00 ) >> 3 ) ;
if ( V_2 == 0 )
return 0 ;
return 1350000U / V_2 ;
}
static unsigned int F_17 ( T_2 V_2 , unsigned int V_13 )
{
if ( V_2 == 0 || V_2 == 0xffff )
return 0 ;
return 1350000U / ( V_2 << V_13 ) ;
}
static T_2 F_18 ( T_3 V_14 , unsigned int V_13 )
{
if ( ! V_14 )
return 0 ;
return ( 1350000U / V_14 ) >> V_13 ;
}
static inline unsigned int
F_19 ( T_1 V_2 )
{
return 1 << V_2 ;
}
static inline long F_20 ( T_1 V_2 , T_1 V_15 )
{
return F_21 ( V_2 * V_16 [ V_15 ] , 100 ) ;
}
static inline T_1 F_22 ( T_3 V_3 , T_1 V_15 )
{
return F_14 ( F_21 ( V_3 * 100 , V_16 [ V_15 ] ) , 0 , 255 ) ;
}
static bool F_23 ( struct V_17 * V_18 , T_2 V_2 )
{
switch ( V_18 -> V_19 ) {
case V_20 :
return ( ( ( V_2 & 0xff00 ) == 0x100 ||
( V_2 & 0xff00 ) == 0x200 ) &&
( ( V_2 & 0x00ff ) == 0x50 ||
( V_2 & 0x00ff ) == 0x53 ||
( V_2 & 0x00ff ) == 0x55 ) ) ||
( V_2 & 0xfff0 ) == 0x630 ||
V_2 == 0x640 || V_2 == 0x642 ||
V_2 == 0x662 ||
( ( V_2 & 0xfff0 ) == 0x650 && ( V_2 & 0x000f ) >= 0x06 ) ||
V_2 == 0x73 || V_2 == 0x75 || V_2 == 0x77 ;
case V_21 :
return ( ( ( V_2 & 0xff00 ) == 0x100 ||
( V_2 & 0xff00 ) == 0x200 ) &&
( ( V_2 & 0x00ff ) == 0x50 ||
( V_2 & 0x00ff ) == 0x53 ||
( V_2 & 0x00ff ) == 0x55 ) ) ||
( V_2 & 0xfff0 ) == 0x630 ||
V_2 == 0x402 ||
V_2 == 0x640 || V_2 == 0x642 ||
( ( V_2 & 0xfff0 ) == 0x650 && ( V_2 & 0x000f ) >= 0x06 ) ||
V_2 == 0x73 || V_2 == 0x75 || V_2 == 0x77 ;
case V_22 :
return V_2 == 0x150 || V_2 == 0x153 || V_2 == 0x155 ||
( ( V_2 & 0xfff0 ) == 0x4b0 && ( V_2 & 0x000f ) < 0x09 ) ||
V_2 == 0x402 ||
V_2 == 0x63a || V_2 == 0x63c || V_2 == 0x63e ||
V_2 == 0x640 || V_2 == 0x642 ||
V_2 == 0x73 || V_2 == 0x75 || V_2 == 0x77 || V_2 == 0x79 ||
V_2 == 0x7b ;
}
return false ;
}
static inline void F_24 ( struct V_17 * V_18 , T_2 V_2 )
{
T_1 V_23 = V_2 >> 8 ;
if ( V_18 -> V_23 != V_23 ) {
F_25 ( V_24 , V_18 -> V_25 + V_26 ) ;
F_25 ( V_23 , V_18 -> V_25 + V_27 ) ;
V_18 -> V_23 = V_23 ;
}
}
static T_2 F_26 ( struct V_17 * V_18 , T_2 V_2 )
{
int V_28 , V_29 = F_23 ( V_18 , V_2 ) ;
F_24 ( V_18 , V_2 ) ;
F_25 ( V_2 & 0xff , V_18 -> V_25 + V_26 ) ;
V_28 = F_27 ( V_18 -> V_25 + V_27 ) ;
if ( V_29 ) {
F_25 ( ( V_2 & 0xff ) + 1 ,
V_18 -> V_25 + V_26 ) ;
V_28 = ( V_28 << 8 ) + F_27 ( V_18 -> V_25 + V_27 ) ;
}
return V_28 ;
}
static int F_28 ( struct V_17 * V_18 , T_2 V_2 , T_2 V_30 )
{
int V_29 = F_23 ( V_18 , V_2 ) ;
F_24 ( V_18 , V_2 ) ;
F_25 ( V_2 & 0xff , V_18 -> V_25 + V_26 ) ;
if ( V_29 ) {
F_25 ( V_30 >> 8 , V_18 -> V_25 + V_27 ) ;
F_25 ( ( V_2 & 0xff ) + 1 ,
V_18 -> V_25 + V_26 ) ;
}
F_25 ( V_30 & 0xff , V_18 -> V_25 + V_27 ) ;
return 0 ;
}
static T_2 F_29 ( struct V_17 * V_18 , T_2 V_2 )
{
T_2 V_28 ;
V_28 = F_26 ( V_18 , V_2 ) ;
if ( ! F_23 ( V_18 , V_2 ) )
V_28 <<= 8 ;
return V_28 ;
}
static int F_30 ( struct V_17 * V_18 , T_2 V_2 , T_2 V_30 )
{
if ( ! F_23 ( V_18 , V_2 ) )
V_30 >>= 8 ;
return F_28 ( V_18 , V_2 , V_30 ) ;
}
static void F_31 ( struct V_17 * V_18 , int V_15 )
{
T_1 V_2 ;
switch ( V_15 ) {
case 0 :
V_2 = ( F_26 ( V_18 , V_31 ) & 0x70 )
| ( V_18 -> V_32 [ 0 ] & 0x7 ) ;
F_28 ( V_18 , V_31 , V_2 ) ;
break;
case 1 :
V_2 = ( F_26 ( V_18 , V_31 ) & 0x7 )
| ( ( V_18 -> V_32 [ 1 ] << 4 ) & 0x70 ) ;
F_28 ( V_18 , V_31 , V_2 ) ;
break;
case 2 :
V_2 = ( F_26 ( V_18 , V_33 ) & 0x70 )
| ( V_18 -> V_32 [ 2 ] & 0x7 ) ;
F_28 ( V_18 , V_33 , V_2 ) ;
break;
case 3 :
V_2 = ( F_26 ( V_18 , V_33 ) & 0x7 )
| ( ( V_18 -> V_32 [ 3 ] << 4 ) & 0x70 ) ;
F_28 ( V_18 , V_33 , V_2 ) ;
break;
}
}
static void F_32 ( struct V_17 * V_18 , int V_15 )
{
if ( V_18 -> V_19 == V_20 )
F_31 ( V_18 , V_15 ) ;
}
static void F_33 ( struct V_17 * V_18 )
{
T_1 V_34 ;
V_34 = F_26 ( V_18 , V_31 ) ;
V_18 -> V_32 [ 0 ] = V_34 & 0x7 ;
V_18 -> V_32 [ 1 ] = ( V_34 & 0x70 ) >> 4 ;
V_34 = F_26 ( V_18 , V_33 ) ;
V_18 -> V_32 [ 2 ] = V_34 & 0x7 ;
if ( V_18 -> V_35 & ( 1 << 3 ) )
V_18 -> V_32 [ 3 ] = ( V_34 & 0x70 ) >> 4 ;
}
static void F_34 ( struct V_17 * V_18 )
{
if ( V_18 -> V_19 == V_20 )
F_33 ( V_18 ) ;
}
static void F_35 ( struct V_17 * V_18 )
{
int V_34 ;
F_34 ( V_18 ) ;
for ( V_34 = 0 ; V_34 < F_36 ( V_18 -> V_32 ) ; V_34 ++ ) {
if ( ! ( V_18 -> V_35 & ( 1 << V_34 ) ) )
continue;
if ( V_18 -> V_32 [ V_34 ] == 0 ) {
V_18 -> V_32 [ V_34 ] = 7 ;
F_32 ( V_18 , V_34 ) ;
}
}
}
static void F_37 ( struct V_36 * V_37 ,
struct V_17 * V_18 )
{
int V_34 ;
T_1 V_2 ;
if ( V_18 -> V_38 )
F_35 ( V_18 ) ;
for ( V_34 = 0 ; V_34 < F_36 ( V_18 -> V_39 ) ; V_34 ++ ) {
if ( V_18 -> V_40 & ( 1 << V_34 ) ) {
V_2 = F_26 ( V_18 , V_18 -> V_41 [ V_34 ] ) ;
if ( ! V_2 )
F_28 ( V_18 , V_18 -> V_41 [ V_34 ] ,
V_18 -> V_38 ? 0xff
: 0xff1f ) ;
}
}
}
static void F_38 ( struct V_36 * V_37 ,
struct V_17 * V_18 , int V_15 , T_2 V_2 )
{
T_1 V_32 = V_18 -> V_32 [ V_15 ] ;
T_2 V_39 ;
if ( ! V_18 -> V_38 )
return;
if ( V_2 == 0x00 && V_32 < 0x07 )
V_32 ++ ;
else if ( V_2 != 0x00 && V_2 < 0x30 && V_32 > 0 )
V_32 -- ;
if ( V_32 != V_18 -> V_32 [ V_15 ] ) {
F_39 ( V_37 , L_1 ,
V_15 + 1 , F_19 ( V_18 -> V_32 [ V_15 ] ) ,
F_19 ( V_32 ) ) ;
if ( V_18 -> V_40 & ( 1 << V_15 ) ) {
V_39 = V_18 -> V_39 [ V_15 ] ;
if ( V_32 > V_18 -> V_32 [ V_15 ] ) {
if ( V_39 != 255 && V_39 > 1 )
V_39 >>= 1 ;
} else {
if ( V_39 != 255 ) {
V_39 <<= 1 ;
if ( V_39 > 254 )
V_39 = 254 ;
}
}
if ( V_39 != V_18 -> V_39 [ V_15 ] ) {
V_18 -> V_39 [ V_15 ] = V_39 ;
F_28 ( V_18 , V_18 -> V_41 [ V_15 ] ,
V_39 ) ;
}
}
V_18 -> V_32 [ V_15 ] = V_32 ;
F_32 ( V_18 , V_15 ) ;
}
}
static void F_40 ( struct V_36 * V_37 )
{
struct V_17 * V_18 = F_41 ( V_37 ) ;
int V_34 , V_42 ;
int V_43 , V_2 ;
bool V_44 ;
for ( V_34 = 0 ; V_34 < V_18 -> V_45 ; V_34 ++ ) {
if ( ! ( V_18 -> V_46 & ( 1 << V_34 ) ) )
continue;
V_44 = V_18 -> V_47 [ V_34 ] &&
( F_26 ( V_18 , V_18 -> V_47 [ V_34 ] )
& V_18 -> V_48 [ V_34 ] ) ;
V_18 -> V_49 [ V_34 ] = V_44 ;
V_43 = F_26 ( V_18 , V_18 -> V_50 [ V_34 ] ) ;
for ( V_42 = 0 ; V_42 < F_36 ( V_18 -> V_51 ) ; V_42 ++ ) {
if ( V_18 -> V_51 [ V_42 ] && V_18 -> V_51 [ V_42 ] [ V_34 ] ) {
V_18 -> V_9 [ V_42 ] [ V_34 ]
= F_26 ( V_18 ,
V_18 -> V_51 [ V_42 ] [ V_34 ] ) ;
}
}
V_18 -> V_8 [ V_34 ] = F_10 ( V_18 -> V_9 [ 0 ] [ V_34 ] ,
( V_43 >> 4 ) & 7 ) ;
if ( ! V_18 -> V_52 [ 0 ] [ V_34 ] ||
V_18 -> V_8 [ V_34 ] != V_53 )
V_18 -> V_52 [ 0 ] [ V_34 ] = V_43 & 0x0f ;
if ( ! V_18 -> V_54 [ V_34 ] ||
V_18 -> V_8 [ V_34 ] == V_53 ) {
T_1 V_55 = V_43 & 0x0f ;
if ( V_18 -> V_56 ) {
V_55 |= ( F_26 ( V_18 ,
V_18 -> V_56 [ V_34 ] ) & 0x70 ) >> 1 ;
}
V_18 -> V_54 [ V_34 ] = V_55 ;
}
V_18 -> V_52 [ 1 ] [ V_34 ] =
F_26 ( V_18 ,
V_18 -> V_57 [ V_34 ] ) ;
V_2 = F_26 ( V_18 , V_18 -> V_58 [ V_34 ] ) ;
V_18 -> V_59 [ V_34 ] = V_2 & 0x1f ;
if ( V_2 & 0x80 )
V_18 -> V_9 [ 2 ] [ V_34 ] = 0 ;
V_2 = F_26 ( V_18 , V_18 -> V_60 [ V_34 ] ) ;
V_18 -> V_61 [ V_34 ] = V_2 & 0x1f ;
if ( V_42 == 1 && ! ( V_2 & 0x80 ) )
V_18 -> V_61 [ V_34 ] = 0 ;
for ( V_42 = 0 ; V_42 < F_36 ( V_18 -> V_62 ) ; V_42 ++ ) {
V_18 -> V_62 [ V_42 ] [ V_34 ]
= F_26 ( V_18 ,
V_18 -> V_63 [ V_42 ] [ V_34 ] ) ;
}
}
}
static void F_42 ( struct V_36 * V_37 )
{
struct V_17 * V_18 = F_41 ( V_37 ) ;
int V_34 , V_42 ;
T_1 V_2 ;
T_2 V_64 ;
for ( V_34 = 0 ; V_34 < V_18 -> V_45 ; V_34 ++ ) {
if ( ! ( V_18 -> V_46 & ( 1 << V_34 ) ) )
continue;
for ( V_42 = 0 ; V_42 < F_36 ( V_18 -> V_65 ) ; V_42 ++ ) {
V_18 -> V_65 [ V_42 ] [ V_34 ] =
F_26 ( V_18 , V_18 -> V_66 [ V_42 ] [ V_34 ] ) ;
}
V_64 = F_26 ( V_18 , V_18 -> V_67 [ V_34 ] ) ;
if ( ! V_18 -> V_68 [ V_34 ] ||
V_18 -> V_8 [ V_34 ] == V_69 )
V_18 -> V_68 [ V_34 ] = V_64 & V_18 -> V_70 ;
if ( ! V_18 -> V_71 [ V_34 ] ||
V_18 -> V_8 [ V_34 ] == V_53 ) {
if ( V_18 -> V_56 ) {
V_64 |= ( F_26 ( V_18 ,
V_18 -> V_56 [ V_34 ] ) & 0x0f ) << 8 ;
}
V_18 -> V_71 [ V_34 ] = V_64 ;
}
for ( V_42 = 0 ; V_42 < V_18 -> V_72 ; V_42 ++ ) {
V_18 -> V_73 [ V_34 ] [ V_42 ] =
F_26 ( V_18 ,
F_43 ( V_18 , V_34 , V_42 ) ) ;
V_18 -> V_74 [ V_34 ] [ V_42 ] =
F_26 ( V_18 ,
F_44 ( V_18 , V_34 , V_42 ) ) ;
}
V_18 -> V_74 [ V_34 ] [ V_18 -> V_72 ] =
F_26 ( V_18 , V_18 -> V_75 [ V_34 ] ) ;
switch ( V_18 -> V_19 ) {
case V_20 :
V_2 = F_26 ( V_18 ,
V_76 [ V_34 ] ) ;
V_18 -> V_73 [ V_34 ] [ V_18 -> V_72 ] =
( V_2 & 0x02 ) ? 0xff : 0x00 ;
break;
case V_21 :
V_18 -> V_73 [ V_34 ] [ V_18 -> V_72 ] = 0xff ;
break;
case V_22 :
V_2 = F_26 ( V_18 ,
V_77 [ V_34 ] ) ;
if ( V_2 & 1 )
V_18 -> V_73 [ V_34 ] [ V_18 -> V_72 ] =
F_26 ( V_18 ,
V_78 [ V_34 ] ) ;
else
V_18 -> V_73 [ V_34 ] [ V_18 -> V_72 ] = 0xff ;
break;
}
}
}
static struct V_17 * F_45 ( struct V_36 * V_37 )
{
struct V_17 * V_18 = F_41 ( V_37 ) ;
int V_34 , V_42 ;
F_46 ( & V_18 -> V_79 ) ;
if ( F_47 ( V_80 , V_18 -> V_81 + V_82 + V_82 / 2 )
|| ! V_18 -> V_83 ) {
F_34 ( V_18 ) ;
for ( V_34 = 0 ; V_34 < V_18 -> V_84 ; V_34 ++ ) {
if ( ! ( V_18 -> V_85 & ( 1 << V_34 ) ) )
continue;
V_18 -> V_86 [ V_34 ] [ 0 ] = F_26 ( V_18 ,
V_18 -> V_87 [ V_34 ] ) ;
V_18 -> V_86 [ V_34 ] [ 1 ] = F_26 ( V_18 ,
V_18 -> V_88 [ 0 ] [ V_34 ] ) ;
V_18 -> V_86 [ V_34 ] [ 2 ] = F_26 ( V_18 ,
V_18 -> V_88 [ 1 ] [ V_34 ] ) ;
}
for ( V_34 = 0 ; V_34 < F_36 ( V_18 -> V_89 ) ; V_34 ++ ) {
T_2 V_2 ;
if ( ! ( V_18 -> V_35 & ( 1 << V_34 ) ) )
continue;
V_2 = F_26 ( V_18 , V_18 -> V_90 [ V_34 ] ) ;
V_18 -> V_89 [ V_34 ] = V_18 -> V_91 ( V_2 ,
V_18 -> V_32 [ V_34 ] ) ;
if ( V_18 -> V_40 & ( 1 << V_34 ) )
V_18 -> V_39 [ V_34 ] = F_26 ( V_18 ,
V_18 -> V_41 [ V_34 ] ) ;
V_18 -> V_92 [ V_34 ] =
F_26 ( V_18 , V_18 -> V_93 [ V_34 ] ) ;
F_38 ( V_37 , V_18 , V_34 , V_2 ) ;
}
F_40 ( V_37 ) ;
F_42 ( V_37 ) ;
for ( V_34 = 0 ; V_34 < V_94 ; V_34 ++ ) {
if ( ! ( V_18 -> V_95 & ( 1 << V_34 ) ) )
continue;
for ( V_42 = 0 ; V_42 < F_36 ( V_18 -> V_96 ) ; V_42 ++ ) {
if ( V_18 -> V_96 [ V_42 ] [ V_34 ] )
V_18 -> V_97 [ V_42 ] [ V_34 ]
= F_29 ( V_18 ,
V_18 -> V_96 [ V_42 ] [ V_34 ] ) ;
}
if ( ! ( V_18 -> V_98 & ( 1 << V_34 ) ) )
continue;
V_18 -> V_99 [ V_34 ]
= F_26 ( V_18 , V_18 -> V_100 [ V_34 ] ) ;
}
V_18 -> V_101 = 0 ;
for ( V_34 = 0 ; V_34 < V_102 ; V_34 ++ ) {
T_1 V_103 ;
if ( ! V_18 -> V_104 [ V_34 ] )
continue;
V_103 = F_26 ( V_18 , V_18 -> V_104 [ V_34 ] ) ;
V_18 -> V_101 |= ( ( V_105 ) V_103 ) << ( V_34 << 3 ) ;
}
V_18 -> V_81 = V_80 ;
V_18 -> V_83 = true ;
}
F_48 ( & V_18 -> V_79 ) ;
return V_18 ;
}
static T_4
F_49 ( struct V_36 * V_37 , struct V_106 * V_107 , char * V_108 )
{
struct V_17 * V_18 = F_45 ( V_37 ) ;
struct V_109 * V_110 = F_50 ( V_107 ) ;
int V_15 = V_110 -> V_15 ;
int V_111 = V_110 -> V_111 ;
return sprintf ( V_108 , L_2 , F_20 ( V_18 -> V_86 [ V_15 ] [ V_111 ] , V_15 ) ) ;
}
static T_4
F_51 ( struct V_36 * V_37 , struct V_106 * V_107 , const char * V_108 ,
T_5 V_112 )
{
struct V_17 * V_18 = F_41 ( V_37 ) ;
struct V_109 * V_110 = F_50 ( V_107 ) ;
int V_15 = V_110 -> V_15 ;
int V_111 = V_110 -> V_111 ;
unsigned long V_3 ;
int V_113 = F_52 ( V_108 , 10 , & V_3 ) ;
if ( V_113 < 0 )
return V_113 ;
F_46 ( & V_18 -> V_79 ) ;
V_18 -> V_86 [ V_15 ] [ V_111 ] = F_22 ( V_3 , V_15 ) ;
F_28 ( V_18 , V_18 -> V_88 [ V_111 - 1 ] [ V_15 ] ,
V_18 -> V_86 [ V_15 ] [ V_111 ] ) ;
F_48 ( & V_18 -> V_79 ) ;
return V_112 ;
}
static T_4
F_53 ( struct V_36 * V_37 , struct V_106 * V_107 , char * V_108 )
{
struct V_17 * V_18 = F_45 ( V_37 ) ;
struct V_114 * V_110 = F_54 ( V_107 ) ;
int V_15 = V_18 -> V_115 [ V_110 -> V_111 ] ;
return sprintf ( V_108 , L_3 ,
( unsigned int ) ( ( V_18 -> V_101 >> V_15 ) & 0x01 ) ) ;
}
static int F_55 ( struct V_17 * V_18 , int V_111 , int V_112 )
{
int V_116 = V_18 -> V_117 [ V_111 ] ;
int V_15 ;
for ( V_15 = 0 ; V_15 < V_112 ; V_15 ++ ) {
int V_118 ;
V_118 = F_26 ( V_18 ,
V_18 -> V_119 [ V_15 ] ) & 0x1f ;
if ( V_118 == V_116 )
return V_15 ;
}
return - 1 ;
}
static T_4
F_56 ( struct V_36 * V_37 , struct V_106 * V_107 , char * V_108 )
{
struct V_114 * V_110 = F_54 ( V_107 ) ;
struct V_17 * V_18 = F_45 ( V_37 ) ;
unsigned int V_103 = 0 ;
int V_15 ;
V_15 = F_55 ( V_18 , V_110 -> V_111 , V_18 -> V_120 ) ;
if ( V_15 >= 0 ) {
int V_121 = V_18 -> V_115 [ V_15 + V_122 ] ;
V_103 = ( V_18 -> V_101 >> V_121 ) & 0x01 ;
}
return sprintf ( V_108 , L_3 , V_103 ) ;
}
static T_4
F_57 ( struct V_36 * V_37 , struct V_106 * V_107 , char * V_108 )
{
struct V_17 * V_18 = F_45 ( V_37 ) ;
struct V_114 * V_110 = F_54 ( V_107 ) ;
int V_15 = V_110 -> V_111 ;
return sprintf ( V_108 , L_4 , V_18 -> V_89 [ V_15 ] ) ;
}
static T_4
F_58 ( struct V_36 * V_37 , struct V_106 * V_107 , char * V_108 )
{
struct V_17 * V_18 = F_45 ( V_37 ) ;
struct V_114 * V_110 = F_54 ( V_107 ) ;
int V_15 = V_110 -> V_111 ;
return sprintf ( V_108 , L_4 ,
V_18 -> V_123 ( V_18 -> V_39 [ V_15 ] ,
V_18 -> V_32 [ V_15 ] ) ) ;
}
static T_4
F_59 ( struct V_36 * V_37 , struct V_106 * V_107 , char * V_108 )
{
struct V_17 * V_18 = F_45 ( V_37 ) ;
struct V_114 * V_110 = F_54 ( V_107 ) ;
int V_15 = V_110 -> V_111 ;
return sprintf ( V_108 , L_3 , F_19 ( V_18 -> V_32 [ V_15 ] ) ) ;
}
static T_4
F_60 ( struct V_36 * V_37 , struct V_106 * V_107 ,
const char * V_108 , T_5 V_112 )
{
struct V_17 * V_18 = F_41 ( V_37 ) ;
struct V_114 * V_110 = F_54 ( V_107 ) ;
int V_15 = V_110 -> V_111 ;
unsigned long V_3 ;
int V_113 ;
unsigned int V_2 ;
T_1 V_124 ;
V_113 = F_52 ( V_108 , 10 , & V_3 ) ;
if ( V_113 < 0 )
return V_113 ;
F_46 ( & V_18 -> V_79 ) ;
if ( ! V_18 -> V_38 ) {
if ( ! V_3 ) {
V_3 = 0xff1f ;
} else {
if ( V_3 > 1350000U )
V_3 = 135000U ;
V_3 = 1350000U / V_3 ;
V_3 = ( V_3 & 0x1f ) | ( ( V_3 << 3 ) & 0xff00 ) ;
}
V_18 -> V_39 [ V_15 ] = V_3 ;
goto V_125;
}
if ( ! V_3 ) {
V_18 -> V_39 [ V_15 ] = 255 ;
V_124 = V_18 -> V_32 [ V_15 ] ;
F_61 ( V_37 , L_5 , V_15 + 1 ) ;
goto V_126;
}
V_2 = 1350000U / V_3 ;
if ( V_2 >= 128 * 255 ) {
V_18 -> V_39 [ V_15 ] = 254 ;
V_124 = 7 ;
F_62 ( V_37 ,
L_6 ,
V_15 + 1 , V_3 , V_18 -> V_123 ( 254 , 7 ) ) ;
} else if ( ! V_2 ) {
V_18 -> V_39 [ V_15 ] = 1 ;
V_124 = 0 ;
F_62 ( V_37 ,
L_7 ,
V_15 + 1 , V_3 , V_18 -> V_123 ( 1 , 0 ) ) ;
} else {
V_124 = 0 ;
while ( V_2 > 192 && V_124 < 7 ) {
V_2 >>= 1 ;
V_124 ++ ;
}
V_18 -> V_39 [ V_15 ] = V_2 ;
}
V_126:
if ( V_124 != V_18 -> V_32 [ V_15 ] ) {
F_39 ( V_37 , L_8 ,
V_15 + 1 , F_19 ( V_18 -> V_32 [ V_15 ] ) ,
F_19 ( V_124 ) ) ;
V_18 -> V_32 [ V_15 ] = V_124 ;
F_32 ( V_18 , V_15 ) ;
V_18 -> V_81 = V_80 ;
}
V_125:
F_28 ( V_18 , V_18 -> V_41 [ V_15 ] , V_18 -> V_39 [ V_15 ] ) ;
F_48 ( & V_18 -> V_79 ) ;
return V_112 ;
}
static T_4
F_63 ( struct V_36 * V_37 , struct V_106 * V_107 , char * V_108 )
{
struct V_17 * V_18 = F_45 ( V_37 ) ;
struct V_114 * V_110 = F_54 ( V_107 ) ;
int V_127 = V_18 -> V_92 [ V_110 -> V_111 ] ;
return sprintf ( V_108 , L_4 , V_127 ? : 4 ) ;
}
static T_4
F_64 ( struct V_36 * V_37 , struct V_106 * V_107 ,
const char * V_108 , T_5 V_112 )
{
struct V_17 * V_18 = F_41 ( V_37 ) ;
struct V_114 * V_110 = F_54 ( V_107 ) ;
int V_15 = V_110 -> V_111 ;
unsigned long V_3 ;
int V_113 ;
V_113 = F_52 ( V_108 , 10 , & V_3 ) ;
if ( V_113 < 0 )
return V_113 ;
if ( V_3 > 4 )
return - V_128 ;
F_46 ( & V_18 -> V_79 ) ;
V_18 -> V_92 [ V_15 ] = V_3 & 3 ;
F_28 ( V_18 , V_18 -> V_93 [ V_15 ] , V_3 & 3 ) ;
F_48 ( & V_18 -> V_79 ) ;
return V_112 ;
}
static T_4
F_65 ( struct V_36 * V_37 , struct V_106 * V_107 , char * V_108 )
{
struct V_17 * V_18 = F_45 ( V_37 ) ;
struct V_114 * V_110 = F_54 ( V_107 ) ;
int V_15 = V_110 -> V_111 ;
return sprintf ( V_108 , L_9 , V_18 -> V_129 [ V_18 -> V_117 [ V_15 ] ] ) ;
}
static T_4
F_66 ( struct V_36 * V_37 , struct V_106 * V_107 , char * V_108 )
{
struct V_17 * V_18 = F_45 ( V_37 ) ;
struct V_109 * V_110 = F_50 ( V_107 ) ;
int V_15 = V_110 -> V_15 ;
int V_111 = V_110 -> V_111 ;
return sprintf ( V_108 , L_4 , F_67 ( V_18 -> V_97 [ V_111 ] [ V_15 ] ) ) ;
}
static T_4
F_68 ( struct V_36 * V_37 , struct V_106 * V_107 , const char * V_108 ,
T_5 V_112 )
{
struct V_17 * V_18 = F_41 ( V_37 ) ;
struct V_109 * V_110 = F_50 ( V_107 ) ;
int V_15 = V_110 -> V_15 ;
int V_111 = V_110 -> V_111 ;
int V_113 ;
long V_3 ;
V_113 = F_69 ( V_108 , 10 , & V_3 ) ;
if ( V_113 < 0 )
return V_113 ;
F_46 ( & V_18 -> V_79 ) ;
V_18 -> V_97 [ V_111 ] [ V_15 ] = F_70 ( V_3 ) ;
F_30 ( V_18 , V_18 -> V_96 [ V_111 ] [ V_15 ] ,
V_18 -> V_97 [ V_111 ] [ V_15 ] ) ;
F_48 ( & V_18 -> V_79 ) ;
return V_112 ;
}
static T_4
F_71 ( struct V_36 * V_37 , struct V_106 * V_107 , char * V_108 )
{
struct V_17 * V_18 = F_45 ( V_37 ) ;
struct V_114 * V_110 = F_54 ( V_107 ) ;
return sprintf ( V_108 , L_4 , V_18 -> V_99 [ V_110 -> V_111 ] * 1000 ) ;
}
static T_4
F_72 ( struct V_36 * V_37 , struct V_106 * V_107 ,
const char * V_108 , T_5 V_112 )
{
struct V_17 * V_18 = F_41 ( V_37 ) ;
struct V_114 * V_110 = F_54 ( V_107 ) ;
int V_15 = V_110 -> V_111 ;
long V_3 ;
int V_113 ;
V_113 = F_69 ( V_108 , 10 , & V_3 ) ;
if ( V_113 < 0 )
return V_113 ;
V_3 = F_14 ( F_21 ( V_3 , 1000 ) , - 128 , 127 ) ;
F_46 ( & V_18 -> V_79 ) ;
V_18 -> V_99 [ V_15 ] = V_3 ;
F_28 ( V_18 , V_18 -> V_100 [ V_15 ] , V_3 ) ;
F_48 ( & V_18 -> V_79 ) ;
return V_112 ;
}
static T_4
F_73 ( struct V_36 * V_37 , struct V_106 * V_107 , char * V_108 )
{
struct V_17 * V_18 = F_45 ( V_37 ) ;
struct V_114 * V_110 = F_54 ( V_107 ) ;
int V_15 = V_110 -> V_111 ;
return sprintf ( V_108 , L_4 , ( int ) V_18 -> V_130 [ V_15 ] ) ;
}
static T_4
F_74 ( struct V_36 * V_37 , struct V_106 * V_107 ,
const char * V_108 , T_5 V_112 )
{
struct V_17 * V_18 = F_45 ( V_37 ) ;
struct V_114 * V_110 = F_54 ( V_107 ) ;
int V_15 = V_110 -> V_111 ;
unsigned long V_3 ;
int V_113 ;
T_1 V_131 , V_132 , V_121 ;
V_113 = F_52 ( V_108 , 10 , & V_3 ) ;
if ( V_113 < 0 )
return V_113 ;
if ( V_3 != 1 && V_3 != 3 && V_3 != 4 )
return - V_128 ;
F_46 ( & V_18 -> V_79 ) ;
V_18 -> V_130 [ V_15 ] = V_3 ;
V_131 = F_26 ( V_18 , V_18 -> V_133 ) & ~ ( 0x02 << V_15 ) ;
V_132 = F_26 ( V_18 , V_18 -> V_134 ) & ~ ( 0x02 << V_15 ) ;
V_121 = 0x02 << V_15 ;
switch ( V_3 ) {
case 1 :
V_131 |= V_121 ;
V_132 |= V_121 ;
break;
case 3 :
V_131 |= V_121 ;
break;
case 4 :
break;
}
F_28 ( V_18 , V_18 -> V_133 , V_131 ) ;
F_28 ( V_18 , V_18 -> V_134 , V_132 ) ;
F_48 ( & V_18 -> V_79 ) ;
return V_112 ;
}
static T_4
F_75 ( struct V_36 * V_37 , struct V_106 * V_107 , char * V_108 )
{
struct V_17 * V_18 = F_45 ( V_37 ) ;
struct V_114 * V_110 = F_54 ( V_107 ) ;
return sprintf ( V_108 , L_4 , ! V_18 -> V_49 [ V_110 -> V_111 ] ) ;
}
static T_4
F_76 ( struct V_36 * V_37 , struct V_106 * V_107 ,
const char * V_108 , T_5 V_112 )
{
struct V_17 * V_18 = F_41 ( V_37 ) ;
struct V_114 * V_110 = F_54 ( V_107 ) ;
int V_15 = V_110 -> V_111 ;
unsigned long V_3 ;
int V_113 ;
T_1 V_2 ;
V_113 = F_52 ( V_108 , 10 , & V_3 ) ;
if ( V_113 < 0 )
return V_113 ;
if ( V_3 > 1 )
return - V_128 ;
if ( V_18 -> V_47 [ V_15 ] == 0 ) {
if ( V_3 )
return - V_128 ;
return V_112 ;
}
F_46 ( & V_18 -> V_79 ) ;
V_18 -> V_49 [ V_15 ] = V_3 ;
V_2 = F_26 ( V_18 , V_18 -> V_47 [ V_15 ] ) ;
V_2 &= ~ V_18 -> V_48 [ V_15 ] ;
if ( V_3 )
V_2 |= V_18 -> V_48 [ V_15 ] ;
F_28 ( V_18 , V_18 -> V_47 [ V_15 ] , V_2 ) ;
F_48 ( & V_18 -> V_79 ) ;
return V_112 ;
}
static T_4
F_77 ( struct V_36 * V_37 , struct V_106 * V_107 , char * V_108 )
{
struct V_17 * V_18 = F_45 ( V_37 ) ;
struct V_109 * V_110 = F_50 ( V_107 ) ;
int V_15 = V_110 -> V_15 ;
int V_111 = V_110 -> V_111 ;
int V_9 ;
if ( V_111 == 0 && V_18 -> V_8 [ V_15 ] > V_135 )
V_9 = F_26 ( V_18 , V_18 -> V_136 [ V_15 ] ) ;
else
V_9 = V_18 -> V_9 [ V_111 ] [ V_15 ] ;
return sprintf ( V_108 , L_4 , V_9 ) ;
}
static T_4
F_78 ( struct V_36 * V_37 , struct V_106 * V_107 , const char * V_108 ,
T_5 V_112 )
{
struct V_17 * V_18 = F_41 ( V_37 ) ;
struct V_109 * V_110 = F_50 ( V_107 ) ;
int V_15 = V_110 -> V_15 ;
int V_111 = V_110 -> V_111 ;
unsigned long V_3 ;
int V_137 [ 7 ] = { 0 , 1 , 1 , V_18 -> V_9 [ 2 ] [ V_15 ] , 0 , 0 , 0 } ;
int V_138 [ 7 ]
= { 255 , 255 , V_18 -> V_9 [ 3 ] [ V_15 ] ? : 255 , 255 , 255 , 255 , 255 } ;
int V_113 ;
T_1 V_2 ;
V_113 = F_52 ( V_108 , 10 , & V_3 ) ;
if ( V_113 < 0 )
return V_113 ;
V_3 = F_14 ( V_3 , V_137 [ V_111 ] , V_138 [ V_111 ] ) ;
F_46 ( & V_18 -> V_79 ) ;
V_18 -> V_9 [ V_111 ] [ V_15 ] = V_3 ;
F_28 ( V_18 , V_18 -> V_51 [ V_111 ] [ V_15 ] , V_3 ) ;
if ( V_111 == 2 ) {
V_2 = F_26 ( V_18 , V_18 -> V_58 [ V_15 ] ) ;
V_2 &= 0x7f ;
if ( V_3 )
V_2 |= 0x80 ;
F_28 ( V_18 , V_18 -> V_58 [ V_15 ] , V_2 ) ;
}
F_48 ( & V_18 -> V_79 ) ;
return V_112 ;
}
static int F_79 ( struct V_17 * V_18 , int V_15 )
{
int V_34 ;
for ( V_34 = 0 ; V_34 < V_18 -> V_72 - 1 ; V_34 ++ ) {
if ( V_18 -> V_74 [ V_15 ] [ V_34 ] > V_18 -> V_74 [ V_15 ] [ V_34 + 1 ] )
return - V_128 ;
}
for ( V_34 = 0 ; V_34 < V_18 -> V_72 - 1 ; V_34 ++ ) {
if ( V_18 -> V_73 [ V_15 ] [ V_34 ] > V_18 -> V_73 [ V_15 ] [ V_34 + 1 ] )
return - V_128 ;
}
if ( V_18 -> V_73 [ V_15 ] [ V_18 -> V_72 ] ) {
if ( V_18 -> V_74 [ V_15 ] [ V_18 -> V_72 - 1 ] >
V_18 -> V_74 [ V_15 ] [ V_18 -> V_72 ] ||
V_18 -> V_73 [ V_15 ] [ V_18 -> V_72 - 1 ] >
V_18 -> V_73 [ V_15 ] [ V_18 -> V_72 ] )
return - V_128 ;
}
return 0 ;
}
static void F_80 ( struct V_17 * V_18 , int V_15 )
{
T_1 V_2 ;
switch ( V_18 -> V_8 [ V_15 ] ) {
case V_11 :
case V_135 :
break;
case V_53 :
V_2 = F_26 ( V_18 , V_18 -> V_50 [ V_15 ] ) ;
V_2 = ( V_2 & ~ V_18 -> V_139 ) |
( V_18 -> V_54 [ V_15 ] & V_18 -> V_139 ) ;
F_28 ( V_18 , V_18 -> V_50 [ V_15 ] , V_2 ) ;
F_28 ( V_18 , V_18 -> V_67 [ V_15 ] ,
V_18 -> V_71 [ V_15 ] & 0xff ) ;
if ( V_18 -> V_56 ) {
V_2 = ( V_18 -> V_71 [ V_15 ] >> 8 ) & 0x0f ;
V_2 |= ( V_18 -> V_54 [ V_15 ] & 0x38 ) << 1 ;
F_28 ( V_18 ,
V_18 -> V_56 [ V_15 ] ,
V_2 ) ;
}
break;
case V_69 :
F_28 ( V_18 , V_18 -> V_67 [ V_15 ] ,
V_18 -> V_68 [ V_15 ] ) ;
default:
V_2 = F_26 ( V_18 , V_18 -> V_50 [ V_15 ] ) ;
V_2 = ( V_2 & ~ V_18 -> V_139 ) |
V_18 -> V_52 [ 0 ] [ V_15 ] ;
F_28 ( V_18 , V_18 -> V_50 [ V_15 ] , V_2 ) ;
break;
}
}
static T_4
F_81 ( struct V_36 * V_37 , struct V_106 * V_107 , char * V_108 )
{
struct V_17 * V_18 = F_45 ( V_37 ) ;
struct V_114 * V_110 = F_54 ( V_107 ) ;
return sprintf ( V_108 , L_4 , V_18 -> V_8 [ V_110 -> V_111 ] ) ;
}
static T_4
F_82 ( struct V_36 * V_37 , struct V_106 * V_107 ,
const char * V_108 , T_5 V_112 )
{
struct V_17 * V_18 = F_41 ( V_37 ) ;
struct V_114 * V_110 = F_54 ( V_107 ) ;
int V_15 = V_110 -> V_111 ;
unsigned long V_3 ;
int V_113 ;
T_2 V_2 ;
V_113 = F_52 ( V_108 , 10 , & V_3 ) ;
if ( V_113 < 0 )
return V_113 ;
if ( V_3 > V_140 )
return - V_128 ;
if ( V_3 == V_141 && V_18 -> V_19 != V_20 )
return - V_128 ;
if ( V_3 == V_140 && F_79 ( V_18 , V_15 ) ) {
F_83 ( V_37 , L_10 ) ;
F_83 ( V_37 , L_11 ) ;
return - V_128 ;
}
F_46 ( & V_18 -> V_79 ) ;
V_18 -> V_8 [ V_15 ] = V_3 ;
if ( V_3 == V_11 ) {
V_18 -> V_9 [ 0 ] [ V_15 ] = 255 ;
F_28 ( V_18 , V_18 -> V_51 [ 0 ] [ V_15 ] , 255 ) ;
}
F_80 ( V_18 , V_15 ) ;
V_2 = F_26 ( V_18 , V_18 -> V_50 [ V_15 ] ) ;
V_2 &= 0x0f ;
V_2 |= F_11 ( V_3 ) << 4 ;
F_28 ( V_18 , V_18 -> V_50 [ V_15 ] , V_2 ) ;
F_48 ( & V_18 -> V_79 ) ;
return V_112 ;
}
static T_4
F_84 ( struct V_17 * V_18 , char * V_108 , int V_118 )
{
int V_34 , V_142 = 0 ;
for ( V_34 = 0 ; V_34 < V_94 ; V_34 ++ ) {
if ( ! ( V_18 -> V_95 & ( 1 << V_34 ) ) )
continue;
if ( V_118 == V_18 -> V_117 [ V_34 ] ) {
V_142 = V_34 + 1 ;
break;
}
}
return sprintf ( V_108 , L_4 , V_142 ) ;
}
static T_4
F_85 ( struct V_36 * V_37 , struct V_106 * V_107 , char * V_108 )
{
struct V_17 * V_18 = F_45 ( V_37 ) ;
struct V_114 * V_110 = F_54 ( V_107 ) ;
int V_111 = V_110 -> V_111 ;
return F_84 ( V_18 , V_108 , V_18 -> V_59 [ V_111 ] ) ;
}
static T_4
F_86 ( struct V_36 * V_37 , struct V_106 * V_107 ,
const char * V_108 , T_5 V_112 )
{
struct V_17 * V_18 = F_45 ( V_37 ) ;
struct V_114 * V_110 = F_54 ( V_107 ) ;
int V_15 = V_110 -> V_111 ;
unsigned long V_3 ;
int V_113 , V_2 , V_118 ;
V_113 = F_52 ( V_108 , 10 , & V_3 ) ;
if ( V_113 < 0 )
return V_113 ;
if ( V_3 == 0 || V_3 > V_94 )
return - V_128 ;
if ( ! ( V_18 -> V_95 & ( 1 << ( V_3 - 1 ) ) ) || ! V_18 -> V_117 [ V_3 - 1 ] )
return - V_128 ;
F_46 ( & V_18 -> V_79 ) ;
V_118 = V_18 -> V_117 [ V_3 - 1 ] ;
V_18 -> V_59 [ V_15 ] = V_118 ;
V_2 = F_26 ( V_18 , V_18 -> V_58 [ V_15 ] ) ;
V_2 &= 0xe0 ;
V_2 |= V_118 ;
F_28 ( V_18 , V_18 -> V_58 [ V_15 ] , V_2 ) ;
F_48 ( & V_18 -> V_79 ) ;
return V_112 ;
}
static T_4
F_87 ( struct V_36 * V_37 , struct V_106 * V_107 ,
char * V_108 )
{
struct V_17 * V_18 = F_45 ( V_37 ) ;
struct V_114 * V_110 = F_54 ( V_107 ) ;
int V_111 = V_110 -> V_111 ;
return F_84 ( V_18 , V_108 ,
V_18 -> V_61 [ V_111 ] ) ;
}
static T_4
F_88 ( struct V_36 * V_37 , struct V_106 * V_107 ,
const char * V_108 , T_5 V_112 )
{
struct V_17 * V_18 = F_45 ( V_37 ) ;
struct V_114 * V_110 = F_54 ( V_107 ) ;
int V_15 = V_110 -> V_111 ;
unsigned long V_3 ;
int V_113 , V_2 , V_118 ;
V_113 = F_52 ( V_108 , 10 , & V_3 ) ;
if ( V_113 < 0 )
return V_113 ;
if ( V_3 > V_94 )
return - V_128 ;
if ( V_3 && ( ! ( V_18 -> V_95 & ( 1 << ( V_3 - 1 ) ) ) ||
! V_18 -> V_117 [ V_3 - 1 ] ) )
return - V_128 ;
F_46 ( & V_18 -> V_79 ) ;
if ( V_3 ) {
V_118 = V_18 -> V_117 [ V_3 - 1 ] ;
V_18 -> V_61 [ V_15 ] = V_118 ;
V_2 = F_26 ( V_18 , V_18 -> V_60 [ V_15 ] ) ;
V_2 &= 0xe0 ;
V_2 |= ( V_118 | 0x80 ) ;
F_28 ( V_18 , V_18 -> V_60 [ V_15 ] , V_2 ) ;
} else {
V_18 -> V_61 [ V_15 ] = 0 ;
V_2 = F_26 ( V_18 , V_18 -> V_60 [ V_15 ] ) ;
V_2 &= 0x7f ;
F_28 ( V_18 , V_18 -> V_60 [ V_15 ] , V_2 ) ;
}
F_48 ( & V_18 -> V_79 ) ;
return V_112 ;
}
static T_4
F_89 ( struct V_36 * V_37 , struct V_106 * V_107 , char * V_108 )
{
struct V_17 * V_18 = F_45 ( V_37 ) ;
struct V_114 * V_110 = F_54 ( V_107 ) ;
return sprintf ( V_108 , L_4 , V_18 -> V_68 [ V_110 -> V_111 ] * 1000 ) ;
}
static T_4
F_90 ( struct V_36 * V_37 , struct V_106 * V_107 ,
const char * V_108 , T_5 V_112 )
{
struct V_17 * V_18 = F_41 ( V_37 ) ;
struct V_114 * V_110 = F_54 ( V_107 ) ;
int V_15 = V_110 -> V_111 ;
unsigned long V_3 ;
int V_113 ;
V_113 = F_52 ( V_108 , 10 , & V_3 ) ;
if ( V_113 < 0 )
return V_113 ;
V_3 = F_14 ( F_21 ( V_3 , 1000 ) , 0 ,
V_18 -> V_70 ) ;
F_46 ( & V_18 -> V_79 ) ;
V_18 -> V_68 [ V_15 ] = V_3 ;
F_80 ( V_18 , V_15 ) ;
F_48 ( & V_18 -> V_79 ) ;
return V_112 ;
}
static T_4
F_91 ( struct V_36 * V_37 , struct V_106 * V_107 , char * V_108 )
{
struct V_17 * V_18 = F_45 ( V_37 ) ;
struct V_114 * V_110 = F_54 ( V_107 ) ;
int V_15 = V_110 -> V_111 ;
return sprintf ( V_108 , L_4 ,
F_17 ( V_18 -> V_71 [ V_15 ] ,
V_18 -> V_32 [ V_15 ] ) ) ;
}
static T_4
F_92 ( struct V_36 * V_37 , struct V_106 * V_107 ,
const char * V_108 , T_5 V_112 )
{
struct V_17 * V_18 = F_41 ( V_37 ) ;
struct V_114 * V_110 = F_54 ( V_107 ) ;
int V_15 = V_110 -> V_111 ;
unsigned long V_3 ;
int V_113 ;
T_2 V_143 ;
V_113 = F_52 ( V_108 , 10 , & V_3 ) ;
if ( V_113 < 0 )
return V_113 ;
V_3 = F_14 ( V_3 , 0 , 1350000U ) ;
V_143 = F_18 ( V_3 , V_18 -> V_32 [ V_15 ] ) ;
F_46 ( & V_18 -> V_79 ) ;
V_18 -> V_71 [ V_15 ] = V_143 ;
F_80 ( V_18 , V_15 ) ;
F_48 ( & V_18 -> V_79 ) ;
return V_112 ;
}
static T_4
F_93 ( struct V_36 * V_37 , struct V_106 * V_107 ,
char * V_108 )
{
struct V_17 * V_18 = F_45 ( V_37 ) ;
struct V_109 * V_110 = F_50 ( V_107 ) ;
int V_15 = V_110 -> V_15 ;
int V_111 = V_110 -> V_111 ;
return sprintf ( V_108 , L_4 , V_18 -> V_52 [ V_111 ] [ V_15 ] * 1000 ) ;
}
static T_4
F_94 ( struct V_36 * V_37 , struct V_106 * V_107 ,
const char * V_108 , T_5 V_112 )
{
struct V_17 * V_18 = F_41 ( V_37 ) ;
struct V_109 * V_110 = F_50 ( V_107 ) ;
int V_15 = V_110 -> V_15 ;
int V_111 = V_110 -> V_111 ;
unsigned long V_3 ;
int V_113 ;
V_113 = F_52 ( V_108 , 10 , & V_3 ) ;
if ( V_113 < 0 )
return V_113 ;
V_3 = F_14 ( F_21 ( V_3 , 1000 ) , 0 , V_18 -> V_139 ) ;
F_46 ( & V_18 -> V_79 ) ;
V_18 -> V_52 [ V_111 ] [ V_15 ] = V_3 ;
if ( V_111 )
F_80 ( V_18 , V_15 ) ;
else
F_28 ( V_18 ,
V_18 -> V_57 [ V_15 ] ,
V_3 ) ;
F_48 ( & V_18 -> V_79 ) ;
return V_112 ;
}
static T_4
F_95 ( struct V_36 * V_37 , struct V_106 * V_107 ,
char * V_108 )
{
struct V_17 * V_18 = F_45 ( V_37 ) ;
struct V_114 * V_110 = F_54 ( V_107 ) ;
int V_15 = V_110 -> V_111 ;
int V_144 = V_18 -> V_71 [ V_15 ] - V_18 -> V_54 [ V_15 ] ;
int V_145 = V_18 -> V_71 [ V_15 ] + V_18 -> V_54 [ V_15 ] ;
int V_146 ;
if ( V_144 <= 0 )
V_144 = 1 ;
if ( V_145 > 0xffff )
V_145 = 0xffff ;
if ( V_145 < V_144 )
V_145 = V_144 ;
V_146 = ( F_17 ( V_144 , V_18 -> V_32 [ V_15 ] )
- F_17 ( V_145 , V_18 -> V_32 [ V_15 ] ) ) / 2 ;
return sprintf ( V_108 , L_4 , V_146 ) ;
}
static T_4
F_96 ( struct V_36 * V_37 , struct V_106 * V_107 ,
const char * V_108 , T_5 V_112 )
{
struct V_17 * V_18 = F_41 ( V_37 ) ;
struct V_114 * V_110 = F_54 ( V_107 ) ;
int V_15 = V_110 -> V_111 ;
unsigned long V_3 ;
int V_113 ;
int V_144 , V_145 ;
V_113 = F_52 ( V_108 , 10 , & V_3 ) ;
if ( V_113 < 0 )
return V_113 ;
V_145 = F_17 ( V_18 -> V_71 [ V_15 ] ,
V_18 -> V_32 [ V_15 ] ) + V_3 ;
V_144 = F_17 ( V_18 -> V_71 [ V_15 ] ,
V_18 -> V_32 [ V_15 ] ) - V_3 ;
if ( V_144 <= 0 )
V_144 = 1 ;
if ( V_145 < V_144 )
V_145 = V_144 ;
V_3 = ( F_18 ( V_144 , V_18 -> V_32 [ V_15 ] ) -
F_18 ( V_145 , V_18 -> V_32 [ V_15 ] ) ) / 2 ;
V_3 = F_14 ( V_3 , 0 , V_18 -> V_147 ) ;
F_46 ( & V_18 -> V_79 ) ;
V_18 -> V_54 [ V_15 ] = V_3 ;
F_80 ( V_18 , V_15 ) ;
F_48 ( & V_18 -> V_79 ) ;
return V_112 ;
}
static T_4
F_97 ( struct V_36 * V_37 , struct V_106 * V_107 , char * V_108 )
{
struct V_17 * V_18 = F_45 ( V_37 ) ;
struct V_109 * V_110 = F_50 ( V_107 ) ;
int V_15 = V_110 -> V_15 ;
int V_111 = V_110 -> V_111 ;
return sprintf ( V_108 , L_4 , V_18 -> V_62 [ V_111 ] [ V_15 ] * 1000 ) ;
}
static T_4
F_98 ( struct V_36 * V_37 , struct V_106 * V_107 ,
const char * V_108 , T_5 V_112 )
{
struct V_17 * V_18 = F_41 ( V_37 ) ;
struct V_109 * V_110 = F_50 ( V_107 ) ;
int V_15 = V_110 -> V_15 ;
int V_111 = V_110 -> V_111 ;
unsigned long V_3 ;
int V_113 ;
V_113 = F_52 ( V_108 , 10 , & V_3 ) ;
if ( V_113 < 0 )
return V_113 ;
V_3 = F_14 ( F_21 ( V_3 , 1000 ) , 0 , 255 ) ;
F_46 ( & V_18 -> V_79 ) ;
V_18 -> V_62 [ V_111 ] [ V_15 ] = V_3 ;
F_28 ( V_18 , V_18 -> V_63 [ V_111 ] [ V_15 ] , V_3 ) ;
F_48 ( & V_18 -> V_79 ) ;
return V_112 ;
}
static T_4
F_99 ( struct V_36 * V_37 , struct V_106 * V_107 , char * V_108 )
{
struct V_17 * V_18 = F_45 ( V_37 ) ;
struct V_109 * V_110 = F_50 ( V_107 ) ;
int V_15 = V_110 -> V_15 ;
int V_111 = V_110 -> V_111 ;
return sprintf ( V_108 , L_4 ,
F_12 ( V_18 -> V_65 [ V_111 ] [ V_15 ] ,
V_18 -> V_49 [ V_15 ] ) ) ;
}
static T_4
F_100 ( struct V_36 * V_37 , struct V_106 * V_107 ,
const char * V_108 , T_5 V_112 )
{
struct V_17 * V_18 = F_41 ( V_37 ) ;
struct V_109 * V_110 = F_50 ( V_107 ) ;
int V_15 = V_110 -> V_15 ;
int V_111 = V_110 -> V_111 ;
unsigned long V_3 ;
int V_113 ;
V_113 = F_52 ( V_108 , 10 , & V_3 ) ;
if ( V_113 < 0 )
return V_113 ;
V_3 = F_13 ( V_3 , V_18 -> V_49 [ V_15 ] ) ;
F_46 ( & V_18 -> V_79 ) ;
V_18 -> V_65 [ V_111 ] [ V_15 ] = V_3 ;
F_28 ( V_18 , V_18 -> V_66 [ V_111 ] [ V_15 ] , V_3 ) ;
F_48 ( & V_18 -> V_79 ) ;
return V_112 ;
}
static T_4
F_101 ( struct V_36 * V_37 , struct V_106 * V_107 , char * V_108 )
{
struct V_17 * V_18 = F_41 ( V_37 ) ;
return sprintf ( V_108 , L_9 , V_18 -> V_148 ) ;
}
static T_4
F_102 ( struct V_36 * V_37 , struct V_106 * V_107 , char * V_108 )
{
struct V_17 * V_18 = F_45 ( V_37 ) ;
struct V_109 * V_110 = F_50 ( V_107 ) ;
return sprintf ( V_108 , L_4 , V_18 -> V_73 [ V_110 -> V_15 ] [ V_110 -> V_111 ] ) ;
}
static T_4
F_103 ( struct V_36 * V_37 , struct V_106 * V_107 ,
const char * V_108 , T_5 V_112 )
{
struct V_17 * V_18 = F_41 ( V_37 ) ;
struct V_109 * V_110 = F_50 ( V_107 ) ;
int V_15 = V_110 -> V_15 ;
int V_149 = V_110 -> V_111 ;
unsigned long V_3 ;
int V_113 ;
T_1 V_2 ;
V_113 = F_52 ( V_108 , 10 , & V_3 ) ;
if ( V_113 < 0 )
return V_113 ;
if ( V_3 > 255 )
return - V_128 ;
if ( V_149 == V_18 -> V_72 ) {
if ( V_18 -> V_19 != V_20 && ! V_3 )
return - V_128 ;
if ( V_18 -> V_19 != V_22 && V_3 )
V_3 = 0xff ;
}
F_46 ( & V_18 -> V_79 ) ;
V_18 -> V_73 [ V_15 ] [ V_149 ] = V_3 ;
if ( V_149 < V_18 -> V_72 ) {
F_28 ( V_18 ,
F_43 ( V_18 , V_15 , V_149 ) ,
V_18 -> V_73 [ V_15 ] [ V_149 ] ) ;
} else {
switch ( V_18 -> V_19 ) {
case V_20 :
V_2 = F_26 ( V_18 ,
V_76 [ V_15 ] ) ;
if ( V_3 )
V_2 |= 0x02 ;
else
V_2 &= ~ 0x02 ;
F_28 ( V_18 , V_76 [ V_15 ] ,
V_2 ) ;
break;
case V_21 :
break;
case V_22 :
F_28 ( V_18 , V_78 [ V_15 ] ,
V_3 ) ;
V_2 = F_26 ( V_18 ,
V_77 [ V_15 ] ) ;
if ( V_3 == 255 )
V_2 &= ~ 0x01 ;
else
V_2 |= 0x01 ;
F_28 ( V_18 ,
V_77 [ V_15 ] ,
V_2 ) ;
break;
}
}
F_48 ( & V_18 -> V_79 ) ;
return V_112 ;
}
static T_4
F_104 ( struct V_36 * V_37 , struct V_106 * V_107 , char * V_108 )
{
struct V_17 * V_18 = F_45 ( V_37 ) ;
struct V_109 * V_110 = F_50 ( V_107 ) ;
int V_15 = V_110 -> V_15 ;
int V_149 = V_110 -> V_111 ;
return sprintf ( V_108 , L_4 , V_18 -> V_74 [ V_15 ] [ V_149 ] * 1000 ) ;
}
static T_4
F_105 ( struct V_36 * V_37 , struct V_106 * V_107 ,
const char * V_108 , T_5 V_112 )
{
struct V_17 * V_18 = F_41 ( V_37 ) ;
struct V_109 * V_110 = F_50 ( V_107 ) ;
int V_15 = V_110 -> V_15 ;
int V_149 = V_110 -> V_111 ;
unsigned long V_3 ;
int V_113 ;
V_113 = F_52 ( V_108 , 10 , & V_3 ) ;
if ( V_113 )
return V_113 ;
if ( V_3 > 255000 )
return - V_128 ;
F_46 ( & V_18 -> V_79 ) ;
V_18 -> V_74 [ V_15 ] [ V_149 ] = F_21 ( V_3 , 1000 ) ;
if ( V_149 < V_18 -> V_72 ) {
F_28 ( V_18 ,
F_44 ( V_18 , V_15 , V_149 ) ,
V_18 -> V_74 [ V_15 ] [ V_149 ] ) ;
} else {
F_28 ( V_18 , V_18 -> V_75 [ V_15 ] ,
V_18 -> V_74 [ V_15 ] [ V_149 ] ) ;
}
F_48 ( & V_18 -> V_79 ) ;
return V_112 ;
}
static T_4
F_106 ( struct V_36 * V_37 , struct V_106 * V_107 , char * V_108 )
{
struct V_17 * V_18 = F_41 ( V_37 ) ;
return sprintf ( V_108 , L_4 , F_107 ( V_18 -> V_150 , V_18 -> V_151 ) ) ;
}
static T_4
F_108 ( struct V_36 * V_37 , struct V_106 * V_107 ,
const char * V_108 , T_5 V_112 )
{
struct V_17 * V_18 = F_41 ( V_37 ) ;
struct V_152 * V_153 = V_37 -> V_154 ;
int V_15 = F_54 ( V_107 ) -> V_111 - V_155 ;
unsigned long V_3 ;
T_1 V_2 ;
int V_156 ;
if ( F_52 ( V_108 , 10 , & V_3 ) || V_3 != 0 )
return - V_128 ;
F_46 ( & V_18 -> V_79 ) ;
V_156 = F_6 ( V_153 -> V_157 ) ;
if ( V_156 ) {
V_112 = V_156 ;
goto error;
}
F_5 ( V_153 -> V_157 , V_158 ) ;
V_2 = F_3 ( V_153 -> V_157 , V_159 [ V_15 ] ) ;
V_2 |= V_160 [ V_15 ] ;
F_1 ( V_153 -> V_157 , V_159 [ V_15 ] , V_2 ) ;
V_2 &= ~ V_160 [ V_15 ] ;
F_1 ( V_153 -> V_157 , V_159 [ V_15 ] , V_2 ) ;
F_8 ( V_153 -> V_157 ) ;
V_18 -> V_83 = false ;
error:
F_48 ( & V_18 -> V_79 ) ;
return V_112 ;
}
static void F_109 ( struct V_36 * V_37 )
{
int V_34 ;
struct V_17 * V_18 = F_41 ( V_37 ) ;
for ( V_34 = 0 ; V_34 < V_18 -> V_45 ; V_34 ++ )
F_110 ( & V_37 -> V_161 , & V_162 [ V_34 ] ) ;
for ( V_34 = 0 ; V_34 < F_36 ( V_163 ) ; V_34 ++ )
F_111 ( V_37 , & V_163 [ V_34 ] . V_164 ) ;
for ( V_34 = 0 ; V_34 < F_36 ( V_165 ) ; V_34 ++ )
F_111 ( V_37 , & V_165 [ V_34 ] . V_164 ) ;
for ( V_34 = 0 ; V_34 < F_36 ( V_166 ) ; V_34 ++ )
F_111 ( V_37 , & V_166 [ V_34 ] . V_164 ) ;
for ( V_34 = 0 ; V_34 < F_36 ( V_167 ) ; V_34 ++ )
F_111 ( V_37 , & V_167 [ V_34 ] . V_164 ) ;
for ( V_34 = 0 ; V_34 < V_18 -> V_84 ; V_34 ++ )
F_110 ( & V_37 -> V_161 , & V_168 [ V_34 ] ) ;
for ( V_34 = 0 ; V_34 < 5 ; V_34 ++ ) {
F_111 ( V_37 , & V_169 [ V_34 ] . V_164 ) ;
F_111 ( V_37 , & V_170 [ V_34 ] . V_164 ) ;
F_111 ( V_37 , & V_171 [ V_34 ] . V_164 ) ;
F_111 ( V_37 , & V_172 [ V_34 ] . V_164 ) ;
F_111 ( V_37 , & V_173 [ V_34 ] . V_164 ) ;
}
for ( V_34 = 0 ; V_34 < V_94 ; V_34 ++ ) {
if ( ! ( V_18 -> V_95 & ( 1 << V_34 ) ) )
continue;
F_111 ( V_37 , & V_174 [ V_34 ] . V_164 ) ;
F_111 ( V_37 , & V_175 [ V_34 ] . V_164 ) ;
F_111 ( V_37 , & V_176 [ V_34 ] . V_164 ) ;
F_111 ( V_37 , & V_177 [ V_34 ] . V_164 ) ;
F_111 ( V_37 , & V_178 [ V_34 ] . V_164 ) ;
F_111 ( V_37 , & V_179 [ V_34 ] . V_164 ) ;
if ( ! ( V_18 -> V_98 & ( 1 << V_34 ) ) )
continue;
F_111 ( V_37 , & V_180 [ V_34 ] . V_164 ) ;
F_111 ( V_37 , & V_181 [ V_34 ] . V_164 ) ;
}
F_111 ( V_37 , & V_182 [ 0 ] . V_164 ) ;
F_111 ( V_37 , & V_182 [ 1 ] . V_164 ) ;
F_111 ( V_37 , & V_183 ) ;
F_111 ( V_37 , & V_184 ) ;
}
static inline void F_112 ( struct V_17 * V_18 )
{
int V_34 ;
T_1 V_185 , V_132 ;
if ( V_18 -> V_186 ) {
V_185 = F_26 ( V_18 , V_18 -> V_186 ) ;
if ( ! ( V_185 & 0x01 ) )
F_28 ( V_18 , V_18 -> V_186 , V_185 | 0x01 ) ;
}
for ( V_34 = 0 ; V_34 < V_94 ; V_34 ++ ) {
if ( ! ( V_18 -> V_95 & ( 1 << V_34 ) ) )
continue;
if ( ! V_18 -> V_187 [ V_34 ] )
continue;
V_185 = F_26 ( V_18 , V_18 -> V_187 [ V_34 ] ) ;
if ( V_185 & 0x01 )
F_28 ( V_18 , V_18 -> V_187 [ V_34 ] ,
V_185 & 0xfe ) ;
}
V_185 = F_26 ( V_18 , V_18 -> V_133 ) ;
if ( ! ( V_185 & 0x01 ) )
F_28 ( V_18 , V_18 -> V_133 , V_185 | 0x01 ) ;
V_132 = F_26 ( V_18 , V_18 -> V_134 ) ;
for ( V_34 = 0 ; V_34 < V_18 -> V_188 ; V_34 ++ ) {
if ( ! ( V_18 -> V_98 & ( 1 << V_34 ) ) )
continue;
if ( ( V_185 & ( 0x02 << V_34 ) ) )
V_18 -> V_130 [ V_34 ] = 3 - ( ( V_132 >> V_34 ) & 0x02 ) ;
else
V_18 -> V_130 [ V_34 ] = 4 ;
}
}
static int
F_113 ( const struct V_152 * V_153 ,
struct V_17 * V_18 )
{
int V_189 ;
bool V_190 , V_191 , V_192 , V_193 , V_194 ;
bool V_195 , V_196 , V_197 ;
int V_156 ;
V_156 = F_6 ( V_153 -> V_157 ) ;
if ( V_156 )
return V_156 ;
if ( V_18 -> V_19 == V_20 ) {
V_189 = F_3 ( V_153 -> V_157 , 0x2c ) ;
V_190 = V_189 & ( 1 << 6 ) ;
V_191 = V_190 ;
V_195 = V_189 & ( 1 << 7 ) ;
V_192 = ! ( F_3 ( V_153 -> V_157 , 0x2A ) & 0x80 ) ;
V_193 = 0 ;
V_194 = 0 ;
V_196 = 0 ;
V_197 = 0 ;
} else if ( V_18 -> V_19 == V_21 ) {
bool V_198 = F_3 ( V_153 -> V_157 , 0x27 ) & 0x80 ;
F_5 ( V_153 -> V_157 , V_199 ) ;
V_189 = F_3 ( V_153 -> V_157 , V_200 ) ;
if ( V_189 & 0x80 )
V_190 = V_198 ;
else
V_190 = ! ( F_3 ( V_153 -> V_157 , 0x24 ) & 0x40 ) ;
if ( V_189 & 0x40 )
V_192 = V_198 ;
else
V_192 = F_3 ( V_153 -> V_157 , 0x1C ) & 0x01 ;
if ( V_189 & 0x20 )
V_194 = V_198 ;
else
V_194 = F_3 ( V_153 -> V_157 , 0x1C ) & 0x02 ;
V_193 = V_192 ;
V_191 = V_190 ;
V_195 = V_190 ;
V_196 = 0 ;
V_197 = 0 ;
} else {
V_189 = F_3 ( V_153 -> V_157 , 0x1c ) ;
V_190 = ! ( V_189 & ( 1 << 5 ) ) ;
V_192 = ! ( V_189 & ( 1 << 6 ) ) ;
V_194 = ! ( V_189 & ( 1 << 7 ) ) ;
V_195 = ! ( V_189 & ( 1 << 0 ) ) ;
V_196 = ! ( V_189 & ( 1 << 1 ) ) ;
V_197 = ! ( V_189 & ( 1 << 2 ) ) ;
V_191 = V_190 ;
V_193 = V_192 ;
}
F_8 ( V_153 -> V_157 ) ;
V_18 -> V_35 = V_18 -> V_40 = 0x03 ;
V_18 -> V_35 |= V_190 << 2 ;
V_18 -> V_40 |= V_191 << 2 ;
V_18 -> V_35 |= ( V_192 << 3 ) | ( V_194 << 4 ) ;
V_18 -> V_40 |= ( V_193 << 3 ) | ( V_194 << 4 ) ;
V_18 -> V_46 = 0x03 | ( V_195 << 2 ) | ( V_196 << 3 ) | ( V_197 << 4 ) ;
return 0 ;
}
static void F_114 ( struct V_17 * V_18 , const T_2 * V_201 ,
int * V_202 , int * V_203 )
{
int V_34 ;
T_1 V_118 ;
for ( V_34 = 0 ; V_34 < V_18 -> V_45 && * V_202 ; V_34 ++ ) {
int V_111 ;
if ( ! V_201 [ V_34 ] )
continue;
V_118 = F_26 ( V_18 , V_201 [ V_34 ] ) ;
V_118 &= 0x1f ;
if ( ! V_118 || ( * V_203 & ( 1 << V_118 ) ) )
continue;
if ( V_118 >= V_18 -> V_204 ||
! strlen ( V_18 -> V_129 [ V_118 ] ) )
continue;
V_111 = F_115 ( * V_202 ) ;
F_28 ( V_18 , V_18 -> V_119 [ V_111 ] , V_118 ) ;
* V_202 &= ~ ( 1 << V_111 ) ;
* V_203 |= 1 << V_118 ;
}
}
static int F_116 ( struct V_205 * V_206 )
{
struct V_36 * V_37 = & V_206 -> V_37 ;
struct V_152 * V_153 = V_37 -> V_154 ;
struct V_17 * V_18 ;
struct V_207 * V_28 ;
int V_34 , V_208 , V_113 = 0 ;
int V_118 , V_203 , V_202 ;
const T_2 * V_96 , * V_209 , * V_210 , * V_187 ;
const T_2 * V_211 , * V_212 ;
int V_213 ;
bool V_214 = false ;
T_1 V_215 ;
V_28 = F_117 ( V_206 , V_216 , 0 ) ;
if ( ! F_118 ( & V_206 -> V_37 , V_28 -> V_217 , V_218 ,
V_6 ) )
return - V_7 ;
V_18 = F_119 ( & V_206 -> V_37 , sizeof( struct V_17 ) ,
V_219 ) ;
if ( ! V_18 )
return - V_220 ;
V_18 -> V_19 = V_153 -> V_19 ;
V_18 -> V_25 = V_28 -> V_217 ;
F_120 ( & V_18 -> V_79 ) ;
V_18 -> V_148 = V_221 [ V_18 -> V_19 ] ;
V_18 -> V_23 = 0xff ;
F_121 ( V_206 , V_18 ) ;
switch ( V_18 -> V_19 ) {
case V_20 :
V_18 -> V_84 = 9 ;
V_18 -> V_45 = 3 ;
V_18 -> V_72 = 6 ;
V_18 -> V_38 = true ;
V_18 -> V_188 = 3 ;
V_18 -> V_120 = 3 ;
V_18 -> V_115 = V_222 ;
V_18 -> V_91 = F_17 ;
V_18 -> V_123 = F_15 ;
V_18 -> V_70 = 0x7f ;
V_18 -> V_139 = 0x0f ;
V_18 -> V_147 = 15 ;
V_18 -> V_129 = V_223 ;
V_18 -> V_204 = F_36 ( V_223 ) ;
V_18 -> V_186 = V_224 ;
V_18 -> V_133 = V_225 ;
V_18 -> V_134 = V_226 ;
V_18 -> V_87 = V_227 ;
V_18 -> V_88 [ 0 ] = V_228 ;
V_18 -> V_88 [ 1 ] = V_229 ;
V_18 -> V_67 = V_230 ;
V_18 -> V_90 = V_231 ;
V_18 -> V_50 = V_232 ;
V_18 -> V_41 = V_233 ;
V_18 -> V_93 = V_234 ;
V_18 -> V_66 [ 0 ] = V_235 ;
V_18 -> V_66 [ 1 ] = V_236 ;
V_18 -> V_66 [ 2 ] = V_237 ;
V_18 -> V_51 [ 0 ] = V_238 ;
V_18 -> V_51 [ 1 ] = V_239 ;
V_18 -> V_51 [ 2 ] = V_240 ;
V_18 -> V_51 [ 3 ] = V_241 ;
V_18 -> V_51 [ 4 ] = V_242 ;
V_18 -> V_51 [ 5 ] = V_243 ;
V_18 -> V_136 = V_244 ;
V_18 -> V_47 = V_245 ;
V_18 -> V_48 = V_246 ;
V_18 -> V_247 = V_248 ;
V_18 -> V_249 = V_250 ;
V_18 -> V_75 = V_251 ;
V_18 -> V_57
= V_252 ;
V_18 -> V_100 = V_253 ;
V_18 -> V_119 = V_254 ;
V_18 -> V_58 = V_255 ;
V_18 -> V_60 = V_256 ;
V_18 -> V_63 [ 0 ] = V_257 ;
V_18 -> V_63 [ 1 ] = V_258 ;
V_18 -> V_63 [ 2 ] = V_259 ;
V_18 -> V_104 = V_260 ;
V_96 = V_261 ;
V_213 = F_36 ( V_261 ) ;
V_209 = V_262 ;
V_210 = V_263 ;
V_187 = V_264 ;
V_211 = V_265 ;
V_212 = V_266 ;
break;
case V_21 :
V_18 -> V_84 = 9 ;
V_18 -> V_45 = 3 ;
V_18 -> V_72 = 4 ;
V_18 -> V_38 = false ;
V_18 -> V_188 = 3 ;
V_18 -> V_120 = 3 ;
V_18 -> V_115 = V_267 ;
V_18 -> V_91 = F_16 ;
V_18 -> V_123 = F_16 ;
V_18 -> V_70 = 0xff ;
V_18 -> V_139 = 0x07 ;
V_18 -> V_147 = 63 ;
V_18 -> V_129 = V_268 ;
V_18 -> V_204 = F_36 ( V_268 ) ;
V_18 -> V_186 = V_224 ;
V_18 -> V_133 = V_225 ;
V_18 -> V_134 = V_226 ;
V_18 -> V_87 = V_227 ;
V_18 -> V_88 [ 0 ] = V_228 ;
V_18 -> V_88 [ 1 ] = V_229 ;
V_18 -> V_67 = V_230 ;
V_18 -> V_90 = V_231 ;
V_18 -> V_50 = V_232 ;
V_18 -> V_41 = V_269 ;
V_18 -> V_93 = V_270 ;
V_18 -> V_66 [ 0 ] = V_235 ;
V_18 -> V_66 [ 1 ] = V_236 ;
V_18 -> V_66 [ 2 ] = V_237 ;
V_18 -> V_56 = V_271 ;
V_18 -> V_51 [ 0 ] = V_238 ;
V_18 -> V_51 [ 1 ] = V_239 ;
V_18 -> V_51 [ 2 ] = V_240 ;
V_18 -> V_51 [ 5 ] = V_243 ;
V_18 -> V_51 [ 6 ] = V_272 ;
V_18 -> V_136 = V_244 ;
V_18 -> V_47 = V_273 ;
V_18 -> V_48 = V_274 ;
V_18 -> V_247 = V_248 ;
V_18 -> V_249 = V_250 ;
V_18 -> V_75 = V_251 ;
V_18 -> V_57
= V_252 ;
V_18 -> V_100 = V_253 ;
V_18 -> V_119 = V_254 ;
V_18 -> V_58 = V_255 ;
V_18 -> V_60 = V_256 ;
V_18 -> V_63 [ 0 ] = V_257 ;
V_18 -> V_63 [ 1 ] = V_258 ;
V_18 -> V_63 [ 2 ] = V_259 ;
V_18 -> V_104 = V_260 ;
V_96 = V_261 ;
V_213 = F_36 ( V_261 ) ;
V_209 = V_262 ;
V_210 = V_263 ;
V_187 = V_275 ;
V_211 = V_276 ;
V_212 = V_277 ;
break;
case V_22 :
V_18 -> V_84 = 15 ;
V_18 -> V_45 = 5 ;
V_18 -> V_72 = 4 ;
V_18 -> V_38 = false ;
V_18 -> V_188 = 6 ;
V_18 -> V_120 = 2 ;
V_18 -> V_115 = V_278 ;
V_18 -> V_91 = F_16 ;
V_18 -> V_123 = F_16 ;
V_18 -> V_70 = 0xff ;
V_18 -> V_139 = 0x07 ;
V_18 -> V_147 = 63 ;
V_18 -> V_129 = V_279 ;
V_18 -> V_204 = F_36 ( V_279 ) ;
V_18 -> V_186 = V_224 ;
V_18 -> V_133 = V_225 ;
V_18 -> V_134 = V_226 ;
V_18 -> V_87 = V_280 ;
V_18 -> V_88 [ 0 ] = V_228 ;
V_18 -> V_88 [ 1 ] = V_229 ;
V_18 -> V_67 = V_230 ;
V_18 -> V_90 = V_281 ;
V_18 -> V_50 = V_232 ;
V_18 -> V_41 = V_269 ;
V_18 -> V_93 = V_282 ;
V_18 -> V_66 [ 0 ] = V_235 ;
V_18 -> V_66 [ 1 ] = V_236 ;
V_18 -> V_66 [ 2 ] = V_237 ;
V_18 -> V_56 = V_271 ;
V_18 -> V_51 [ 0 ] = V_238 ;
V_18 -> V_51 [ 1 ] = V_239 ;
V_18 -> V_51 [ 2 ] = V_240 ;
V_18 -> V_51 [ 5 ] = V_243 ;
V_18 -> V_51 [ 6 ] = V_272 ;
V_18 -> V_136 = V_244 ;
V_18 -> V_47 = V_273 ;
V_18 -> V_48 = V_274 ;
V_18 -> V_247 = V_248 ;
V_18 -> V_249 = V_250 ;
V_18 -> V_75 = V_251 ;
V_18 -> V_57
= V_252 ;
V_18 -> V_100 = V_283 ;
V_18 -> V_119 = V_254 ;
V_18 -> V_58 = V_255 ;
V_18 -> V_60 = V_256 ;
V_18 -> V_63 [ 0 ] = V_257 ;
V_18 -> V_63 [ 1 ] = V_258 ;
V_18 -> V_63 [ 2 ] = V_259 ;
V_18 -> V_104 = V_284 ;
V_96 = V_285 ;
V_213 = F_36 ( V_285 ) ;
V_209 = V_286 ;
V_210 = V_287 ;
V_187 = V_288 ;
V_211 = V_289 ;
V_212 = V_290 ;
break;
default:
return - V_291 ;
}
V_18 -> V_85 = ( 1 << V_18 -> V_84 ) - 1 ;
V_18 -> V_95 = 0 ;
V_203 = 0 ;
V_202 = 0 ;
for ( V_34 = 0 ; V_34 < V_213 ; V_34 ++ ) {
if ( V_96 [ V_34 ] == 0 )
continue;
V_118 = F_26 ( V_18 , V_18 -> V_119 [ V_34 ] ) & 0x1f ;
if ( ! V_118 || ( V_203 & ( 1 << V_118 ) ) )
V_202 |= 1 << V_34 ;
V_203 |= 1 << V_118 ;
}
F_114 ( V_18 , V_18 -> V_58 , & V_202 , & V_203 ) ;
F_114 ( V_18 , V_18 -> V_60 , & V_202 , & V_203 ) ;
V_203 = 0 ;
V_208 = V_292 ;
for ( V_34 = 0 ; V_34 < V_213 ; V_34 ++ ) {
if ( V_96 [ V_34 ] == 0 )
continue;
V_118 = F_26 ( V_18 , V_18 -> V_119 [ V_34 ] ) & 0x1f ;
if ( ! V_118 || ( V_203 & ( 1 << V_118 ) ) )
continue;
if ( V_118 >= V_18 -> V_204 ||
! strlen ( V_18 -> V_129 [ V_118 ] ) ) {
F_61 ( V_37 ,
L_12 ,
V_118 , V_34 , V_18 -> V_119 [ V_34 ] , V_96 [ V_34 ] ) ;
continue;
}
V_203 |= 1 << V_118 ;
if ( V_118 <= V_18 -> V_188 ) {
V_18 -> V_95 |= 1 << ( V_118 - 1 ) ;
V_18 -> V_98 |= 1 << ( V_118 - 1 ) ;
V_18 -> V_96 [ 0 ] [ V_118 - 1 ] = V_96 [ V_34 ] ;
V_18 -> V_96 [ 1 ] [ V_118 - 1 ] = V_209 [ V_34 ] ;
V_18 -> V_96 [ 2 ] [ V_118 - 1 ] = V_210 [ V_34 ] ;
V_18 -> V_187 [ V_118 - 1 ] = V_187 [ V_34 ] ;
V_18 -> V_117 [ V_118 - 1 ] = V_118 ;
continue;
}
if ( V_208 >= V_94 )
continue;
V_18 -> V_95 |= 1 << V_208 ;
V_18 -> V_96 [ 0 ] [ V_208 ] = V_96 [ V_34 ] ;
V_18 -> V_96 [ 1 ] [ V_208 ] = V_209 [ V_34 ] ;
V_18 -> V_96 [ 2 ] [ V_208 ] = V_210 [ V_34 ] ;
V_18 -> V_187 [ V_208 ] = V_187 [ V_34 ] ;
if ( V_212 [ V_118 - 1 ] )
V_18 -> V_96 [ 3 ] [ V_208 ] = V_212 [ V_118 - 1 ] ;
V_18 -> V_117 [ V_208 ] = V_118 ;
V_208 ++ ;
}
#ifdef F_122
for ( V_34 = 0 ; V_34 < V_18 -> V_204 - 1 ; V_34 ++ ) {
if ( ! V_211 [ V_34 ] )
continue;
if ( V_203 & ( 1 << ( V_34 + 1 ) ) )
continue;
if ( V_34 < V_18 -> V_188 ) {
if ( V_18 -> V_95 & ( 1 << V_34 ) )
continue;
V_18 -> V_95 |= 1 << V_34 ;
V_18 -> V_98 |= 1 << V_34 ;
V_18 -> V_96 [ 0 ] [ V_34 ] = V_211 [ V_34 ] ;
if ( V_34 < V_213 ) {
V_18 -> V_96 [ 1 ] [ V_34 ] = V_209 [ V_34 ] ;
V_18 -> V_96 [ 2 ] [ V_34 ] = V_210 [ V_34 ] ;
}
V_18 -> V_117 [ V_34 ] = V_34 + 1 ;
continue;
}
if ( V_208 >= V_94 )
break;
V_18 -> V_95 |= 1 << V_208 ;
V_18 -> V_96 [ 0 ] [ V_208 ] = V_211 [ V_34 ] ;
V_18 -> V_117 [ V_208 ] = V_34 + 1 ;
V_208 ++ ;
}
#endif
F_112 ( V_18 ) ;
V_113 = F_6 ( V_153 -> V_157 ) ;
if ( V_113 )
return V_113 ;
V_215 = F_3 ( V_153 -> V_157 , 0x2a ) ;
switch ( V_18 -> V_19 ) {
case V_20 :
V_214 = ( V_215 & 0x40 ) ;
break;
case V_21 :
V_214 = ( V_215 & 0x60 ) == 0x40 ;
break;
case V_22 :
break;
}
if ( V_214 ) {
F_5 ( V_153 -> V_157 , V_293 ) ;
V_18 -> V_150 = F_3 ( V_153 -> V_157 , 0xe3 ) ;
V_18 -> V_151 = F_123 () ;
}
if ( V_294 ) {
T_1 V_185 ;
F_5 ( V_153 -> V_157 , V_199 ) ;
V_185 = F_3 ( V_153 -> V_157 ,
V_295 ) ;
switch ( V_18 -> V_19 ) {
case V_20 :
V_185 |= 0x1e ;
break;
case V_21 :
case V_22 :
V_185 |= 0x3e ;
break;
}
F_1 ( V_153 -> V_157 , V_295 ,
V_185 ) ;
F_61 ( & V_206 -> V_37 , L_13 ,
V_18 -> V_148 ) ;
}
F_8 ( V_153 -> V_157 ) ;
if ( V_214 ) {
V_113 = F_124 ( V_37 , & V_184 ) ;
if ( V_113 )
return V_113 ;
}
V_113 = F_113 ( V_153 , V_18 ) ;
if ( V_113 )
goto V_296;
F_37 ( V_37 , V_18 ) ;
for ( V_34 = 0 ; V_34 < V_18 -> V_45 ; V_34 ++ ) {
if ( ! ( V_18 -> V_46 & ( 1 << V_34 ) ) )
continue;
V_113 = F_125 ( & V_37 -> V_161 , & V_162 [ V_34 ] ) ;
if ( V_113 )
goto V_296;
if ( V_18 -> V_51 [ 3 ] ) {
V_113 = F_124 ( V_37 ,
& V_163 [ V_34 ] . V_164 ) ;
if ( V_113 )
goto V_296;
}
if ( V_18 -> V_51 [ 4 ] ) {
V_113 = F_124 ( V_37 ,
& V_165 [ V_34 ] . V_164 ) ;
if ( V_113 )
goto V_296;
}
if ( V_18 -> V_51 [ 6 ] ) {
V_113 = F_124 ( V_37 ,
& V_166 [ V_34 ] . V_164 ) ;
if ( V_113 )
goto V_296;
}
}
for ( V_34 = 0 ; V_34 < F_36 ( V_167 ) ; V_34 ++ ) {
struct V_109 * V_107 =
& V_167 [ V_34 ] ;
if ( ! ( V_18 -> V_46 & ( 1 << V_107 -> V_15 ) ) )
continue;
if ( V_107 -> V_111 > V_18 -> V_72 )
continue;
V_113 = F_124 ( V_37 , & V_107 -> V_164 ) ;
if ( V_113 )
goto V_296;
}
for ( V_34 = 0 ; V_34 < V_18 -> V_84 ; V_34 ++ ) {
if ( ! ( V_18 -> V_85 & ( 1 << V_34 ) ) )
continue;
V_113 = F_125 ( & V_37 -> V_161 , & V_168 [ V_34 ] ) ;
if ( V_113 )
goto V_296;
}
for ( V_34 = 0 ; V_34 < 5 ; V_34 ++ ) {
if ( V_18 -> V_35 & ( 1 << V_34 ) ) {
V_113 = F_124 ( V_37 ,
& V_169 [ V_34 ] . V_164 ) ;
if ( V_113 )
goto V_296;
if ( V_18 -> V_115 [ V_297 + V_34 ] >= 0 ) {
V_113 = F_124 ( V_37 ,
& V_170 [ V_34 ] . V_164 ) ;
if ( V_113 )
goto V_296;
}
if ( V_18 -> V_19 != V_21 &&
V_18 -> V_19 != V_22 ) {
V_113 = F_124 ( V_37 ,
& V_171 [ V_34 ] . V_164 ) ;
if ( V_113 )
goto V_296;
}
if ( V_18 -> V_40 & ( 1 << V_34 ) ) {
V_113 = F_124 ( V_37 ,
& V_172 [ V_34 ] . V_164 ) ;
if ( V_113 )
goto V_296;
}
V_113 = F_124 ( V_37 ,
& V_173 [ V_34 ] . V_164 ) ;
if ( V_113 )
goto V_296;
}
}
for ( V_34 = 0 ; V_34 < V_94 ; V_34 ++ ) {
if ( ! ( V_18 -> V_95 & ( 1 << V_34 ) ) )
continue;
V_113 = F_124 ( V_37 , & V_174 [ V_34 ] . V_164 ) ;
if ( V_113 )
goto V_296;
if ( V_18 -> V_129 ) {
V_113 = F_124 ( V_37 ,
& V_175 [ V_34 ] . V_164 ) ;
if ( V_113 )
goto V_296;
}
if ( V_18 -> V_96 [ 1 ] [ V_34 ] ) {
V_113 = F_124 ( V_37 ,
& V_176 [ V_34 ] . V_164 ) ;
if ( V_113 )
goto V_296;
}
if ( V_18 -> V_96 [ 2 ] [ V_34 ] ) {
V_113 = F_124 ( V_37 ,
& V_177 [ V_34 ] . V_164 ) ;
if ( V_113 )
goto V_296;
}
if ( V_18 -> V_96 [ 3 ] [ V_34 ] ) {
V_113 = F_124 ( V_37 ,
& V_178 [ V_34 ] . V_164 ) ;
if ( V_113 )
goto V_296;
}
if ( F_55 ( V_18 , V_34 , V_18 -> V_120 ) >= 0 ) {
V_113 = F_124 ( V_37 ,
& V_179 [ V_34 ] . V_164 ) ;
if ( V_113 )
goto V_296;
}
if ( ! ( V_18 -> V_98 & ( 1 << V_34 ) ) )
continue;
V_113 = F_124 ( V_37 , & V_180 [ V_34 ] . V_164 ) ;
if ( V_113 )
goto V_296;
V_113 = F_124 ( V_37 , & V_181 [ V_34 ] . V_164 ) ;
if ( V_113 )
goto V_296;
}
for ( V_34 = 0 ; V_34 < F_36 ( V_182 ) ; V_34 ++ ) {
if ( V_18 -> V_115 [ V_155 + V_34 ] < 0 )
continue;
V_113 = F_124 ( V_37 , & V_182 [ V_34 ] . V_164 ) ;
if ( V_113 )
goto V_296;
}
V_113 = F_124 ( V_37 , & V_183 ) ;
if ( V_113 )
goto V_296;
V_18 -> V_298 = F_126 ( V_37 ) ;
if ( F_127 ( V_18 -> V_298 ) ) {
V_113 = F_128 ( V_18 -> V_298 ) ;
goto V_296;
}
return 0 ;
V_296:
F_109 ( V_37 ) ;
return V_113 ;
}
static int F_129 ( struct V_205 * V_206 )
{
struct V_17 * V_18 = F_130 ( V_206 ) ;
F_131 ( V_18 -> V_298 ) ;
F_109 ( & V_206 -> V_37 ) ;
return 0 ;
}
static int F_132 ( struct V_36 * V_37 )
{
struct V_17 * V_18 = F_45 ( V_37 ) ;
struct V_152 * V_153 = V_37 -> V_154 ;
F_46 ( & V_18 -> V_79 ) ;
V_18 -> V_131 = F_26 ( V_18 , V_18 -> V_133 ) ;
if ( V_153 -> V_19 == V_20 ) {
V_18 -> V_299 = F_26 ( V_18 , V_31 ) ;
V_18 -> V_300 = F_26 ( V_18 , V_33 ) ;
}
F_48 ( & V_18 -> V_79 ) ;
return 0 ;
}
static int F_133 ( struct V_36 * V_37 )
{
struct V_17 * V_18 = F_41 ( V_37 ) ;
struct V_152 * V_153 = V_37 -> V_154 ;
int V_34 , V_42 ;
F_46 ( & V_18 -> V_79 ) ;
V_18 -> V_23 = 0xff ;
for ( V_34 = 0 ; V_34 < V_18 -> V_84 ; V_34 ++ ) {
if ( ! ( V_18 -> V_85 & ( 1 << V_34 ) ) )
continue;
F_28 ( V_18 , V_18 -> V_88 [ 0 ] [ V_34 ] ,
V_18 -> V_86 [ V_34 ] [ 1 ] ) ;
F_28 ( V_18 , V_18 -> V_88 [ 1 ] [ V_34 ] ,
V_18 -> V_86 [ V_34 ] [ 2 ] ) ;
}
for ( V_34 = 0 ; V_34 < F_36 ( V_18 -> V_39 ) ; V_34 ++ ) {
if ( ! ( V_18 -> V_40 & ( 1 << V_34 ) ) )
continue;
F_28 ( V_18 , V_18 -> V_41 [ V_34 ] ,
V_18 -> V_39 [ V_34 ] ) ;
}
for ( V_34 = 0 ; V_34 < V_94 ; V_34 ++ ) {
if ( ! ( V_18 -> V_95 & ( 1 << V_34 ) ) )
continue;
for ( V_42 = 1 ; V_42 < F_36 ( V_18 -> V_96 ) ; V_42 ++ )
if ( V_18 -> V_96 [ V_42 ] [ V_34 ] )
F_30 ( V_18 , V_18 -> V_96 [ V_42 ] [ V_34 ] ,
V_18 -> V_97 [ V_42 ] [ V_34 ] ) ;
}
F_28 ( V_18 , V_18 -> V_133 , V_18 -> V_131 ) ;
if ( V_153 -> V_19 == V_20 ) {
F_28 ( V_18 , V_31 , V_18 -> V_299 ) ;
F_28 ( V_18 , V_33 , V_18 -> V_300 ) ;
}
V_18 -> V_83 = false ;
F_48 ( & V_18 -> V_79 ) ;
return 0 ;
}
static int T_6 F_134 ( int V_301 , unsigned short * V_25 ,
struct V_152 * V_153 )
{
T_2 V_3 ;
int V_113 ;
V_113 = F_6 ( V_301 ) ;
if ( V_113 )
return V_113 ;
if ( V_302 )
V_3 = V_302 ;
else
V_3 = ( F_3 ( V_301 , V_303 ) << 8 )
| F_3 ( V_301 , V_303 + 1 ) ;
switch ( V_3 & V_304 ) {
case V_305 :
V_153 -> V_19 = V_20 ;
break;
case V_306 :
V_153 -> V_19 = V_21 ;
break;
case V_307 :
V_153 -> V_19 = V_22 ;
break;
default:
if ( V_3 != 0xffff )
F_135 ( L_14 , V_3 ) ;
F_8 ( V_301 ) ;
return - V_291 ;
}
F_5 ( V_301 , V_199 ) ;
V_3 = ( F_3 ( V_301 , V_308 ) << 8 )
| F_3 ( V_301 , V_308 + 1 ) ;
* V_25 = V_3 & V_309 ;
if ( * V_25 == 0 ) {
F_136 ( L_15 ) ;
F_8 ( V_301 ) ;
return - V_291 ;
}
V_3 = F_3 ( V_301 , V_200 ) ;
if ( ! ( V_3 & 0x01 ) ) {
F_137 ( L_16 ) ;
F_1 ( V_301 , V_200 , V_3 | 0x01 ) ;
}
F_8 ( V_301 ) ;
F_138 ( L_17 ,
V_310 [ V_153 -> V_19 ] , * V_25 ) ;
V_153 -> V_157 = V_301 ;
return 0 ;
}
static int T_6 F_139 ( void )
{
int V_113 ;
unsigned short V_311 ;
struct V_207 V_28 ;
struct V_152 V_153 ;
if ( F_134 ( 0x2e , & V_311 , & V_153 ) &&
F_134 ( 0x4e , & V_311 , & V_153 ) )
return - V_291 ;
V_113 = F_140 ( & V_312 ) ;
if ( V_113 )
goto exit;
V_206 = F_141 ( V_6 , V_311 ) ;
if ( ! V_206 ) {
V_113 = - V_220 ;
F_136 ( L_18 ) ;
goto V_313;
}
V_113 = F_142 ( V_206 , & V_153 ,
sizeof( struct V_152 ) ) ;
if ( V_113 ) {
F_136 ( L_19 ) ;
goto V_314;
}
memset ( & V_28 , 0 , sizeof( V_28 ) ) ;
V_28 . V_148 = V_6 ;
V_28 . V_217 = V_311 + V_315 ;
V_28 . V_316 = V_311 + V_315 + V_218 - 1 ;
V_28 . V_317 = V_216 ;
V_113 = F_143 ( & V_28 ) ;
if ( V_113 )
goto V_314;
V_113 = F_144 ( V_206 , & V_28 , 1 ) ;
if ( V_113 ) {
F_136 ( L_20 , V_113 ) ;
goto V_314;
}
V_113 = F_145 ( V_206 ) ;
if ( V_113 ) {
F_136 ( L_21 , V_113 ) ;
goto V_314;
}
return 0 ;
V_314:
F_146 ( V_206 ) ;
V_313:
F_147 ( & V_312 ) ;
exit:
return V_113 ;
}
static void T_7 F_148 ( void )
{
F_149 ( V_206 ) ;
F_147 ( & V_312 ) ;
}
