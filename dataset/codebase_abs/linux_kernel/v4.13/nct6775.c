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
return F_20 ( V_2 ) ;
}
static inline long F_21 ( T_1 V_2 , T_1 V_15 )
{
return F_22 ( V_2 * V_16 [ V_15 ] , 100 ) ;
}
static inline T_1 F_23 ( T_3 V_3 , T_1 V_15 )
{
return F_14 ( F_22 ( V_3 * 100 , V_16 [ V_15 ] ) , 0 , 255 ) ;
}
static struct V_17 *
F_24 ( struct V_18 * V_19 ,
const struct V_20 * V_21 ,
int V_22 )
{
struct V_17 * V_23 ;
struct V_24 * V_25 ;
struct V_26 * V_27 ;
struct V_28 * V_29 ;
struct V_30 * * V_31 ;
struct V_32 * * V_33 ;
int V_34 , V_35 ;
if ( V_22 <= 0 )
return F_25 ( - V_36 ) ;
V_33 = V_21 -> V_37 ;
for ( V_35 = 0 ; * V_33 ; V_33 ++ , V_35 ++ )
;
if ( V_35 == 0 )
return F_25 ( - V_36 ) ;
V_23 = F_26 ( V_19 , sizeof( * V_23 ) , V_38 ) ;
if ( V_23 == NULL )
return F_25 ( - V_39 ) ;
V_31 = F_26 ( V_19 , sizeof( * V_31 ) * ( V_22 * V_35 + 1 ) ,
V_38 ) ;
if ( V_31 == NULL )
return F_25 ( - V_39 ) ;
V_25 = F_26 ( V_19 , sizeof( * V_25 ) * V_22 * V_35 ,
V_38 ) ;
if ( V_25 == NULL )
return F_25 ( - V_39 ) ;
V_23 -> V_31 = V_31 ;
V_23 -> V_40 = V_21 -> V_40 ;
for ( V_34 = 0 ; V_34 < V_22 ; V_34 ++ ) {
V_33 = V_21 -> V_37 ;
while ( * V_33 != NULL ) {
snprintf ( V_25 -> V_41 , sizeof( V_25 -> V_41 ) ,
( * V_33 ) -> V_42 . V_43 . V_41 , V_21 -> V_44 + V_34 ) ;
if ( ( * V_33 ) -> V_45 ) {
V_29 = & V_25 -> V_46 . V_29 ;
F_27 ( & V_29 -> V_42 . V_43 ) ;
V_29 -> V_42 . V_43 . V_41 = V_25 -> V_41 ;
V_29 -> V_15 = ( * V_33 ) -> V_46 . V_47 . V_15 + V_34 ;
V_29 -> V_48 = ( * V_33 ) -> V_46 . V_47 . V_48 ;
V_29 -> V_42 . V_43 . V_10 =
( * V_33 ) -> V_42 . V_43 . V_10 ;
V_29 -> V_42 . V_49 = ( * V_33 ) -> V_42 . V_49 ;
V_29 -> V_42 . V_50 = ( * V_33 ) -> V_42 . V_50 ;
* V_31 = & V_29 -> V_42 . V_43 ;
} else {
V_27 = & V_25 -> V_46 . V_51 ;
F_27 ( & V_27 -> V_42 . V_43 ) ;
V_27 -> V_42 . V_43 . V_41 = V_25 -> V_41 ;
V_27 -> V_48 = ( * V_33 ) -> V_46 . V_48 + V_34 ;
V_27 -> V_42 . V_43 . V_10 =
( * V_33 ) -> V_42 . V_43 . V_10 ;
V_27 -> V_42 . V_49 = ( * V_33 ) -> V_42 . V_49 ;
V_27 -> V_42 . V_50 = ( * V_33 ) -> V_42 . V_50 ;
* V_31 = & V_27 -> V_42 . V_43 ;
}
V_31 ++ ;
V_25 ++ ;
V_33 ++ ;
}
}
return V_23 ;
}
static bool F_28 ( struct V_52 * V_53 , T_2 V_2 )
{
switch ( V_53 -> V_54 ) {
case V_55 :
return V_2 == 0x20 || V_2 == 0x22 || V_2 == 0x24 ||
V_2 == 0xe0 || V_2 == 0xe2 || V_2 == 0xe4 ||
V_2 == 0x111 || V_2 == 0x121 || V_2 == 0x131 ;
case V_56 :
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
case V_57 :
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
case V_58 :
case V_59 :
case V_60 :
case V_61 :
case V_62 :
return V_2 == 0x150 || V_2 == 0x153 || V_2 == 0x155 ||
( ( V_2 & 0xfff0 ) == 0x4b0 && ( V_2 & 0x000f ) < 0x0b ) ||
V_2 == 0x402 ||
V_2 == 0x63a || V_2 == 0x63c || V_2 == 0x63e ||
V_2 == 0x640 || V_2 == 0x642 ||
V_2 == 0x73 || V_2 == 0x75 || V_2 == 0x77 || V_2 == 0x79 ||
V_2 == 0x7b || V_2 == 0x7d ;
}
return false ;
}
static inline void F_29 ( struct V_52 * V_53 , T_2 V_2 )
{
T_1 V_63 = V_2 >> 8 ;
if ( V_53 -> V_63 != V_63 ) {
F_30 ( V_64 , V_53 -> V_65 + V_66 ) ;
F_30 ( V_63 , V_53 -> V_65 + V_67 ) ;
V_53 -> V_63 = V_63 ;
}
}
static T_2 F_31 ( struct V_52 * V_53 , T_2 V_2 )
{
int V_68 , V_69 = F_28 ( V_53 , V_2 ) ;
F_29 ( V_53 , V_2 ) ;
F_30 ( V_2 & 0xff , V_53 -> V_65 + V_66 ) ;
V_68 = F_32 ( V_53 -> V_65 + V_67 ) ;
if ( V_69 ) {
F_30 ( ( V_2 & 0xff ) + 1 ,
V_53 -> V_65 + V_66 ) ;
V_68 = ( V_68 << 8 ) + F_32 ( V_53 -> V_65 + V_67 ) ;
}
return V_68 ;
}
static int F_33 ( struct V_52 * V_53 , T_2 V_2 , T_2 V_70 )
{
int V_69 = F_28 ( V_53 , V_2 ) ;
F_29 ( V_53 , V_2 ) ;
F_30 ( V_2 & 0xff , V_53 -> V_65 + V_66 ) ;
if ( V_69 ) {
F_30 ( V_70 >> 8 , V_53 -> V_65 + V_67 ) ;
F_30 ( ( V_2 & 0xff ) + 1 ,
V_53 -> V_65 + V_66 ) ;
}
F_30 ( V_70 & 0xff , V_53 -> V_65 + V_67 ) ;
return 0 ;
}
static T_2 F_34 ( struct V_52 * V_53 , T_2 V_2 )
{
T_2 V_68 ;
V_68 = F_31 ( V_53 , V_2 ) ;
if ( ! F_28 ( V_53 , V_2 ) )
V_68 <<= 8 ;
return V_68 ;
}
static int F_35 ( struct V_52 * V_53 , T_2 V_2 , T_2 V_70 )
{
if ( ! F_28 ( V_53 , V_2 ) )
V_70 >>= 8 ;
return F_33 ( V_53 , V_2 , V_70 ) ;
}
static void F_36 ( struct V_52 * V_53 , int V_15 )
{
T_1 V_2 ;
switch ( V_15 ) {
case 0 :
V_2 = ( F_31 ( V_53 , V_71 ) & 0x70 )
| ( V_53 -> V_72 [ 0 ] & 0x7 ) ;
F_33 ( V_53 , V_71 , V_2 ) ;
break;
case 1 :
V_2 = ( F_31 ( V_53 , V_71 ) & 0x7 )
| ( ( V_53 -> V_72 [ 1 ] << 4 ) & 0x70 ) ;
F_33 ( V_53 , V_71 , V_2 ) ;
break;
case 2 :
V_2 = ( F_31 ( V_53 , V_73 ) & 0x70 )
| ( V_53 -> V_72 [ 2 ] & 0x7 ) ;
F_33 ( V_53 , V_73 , V_2 ) ;
break;
case 3 :
V_2 = ( F_31 ( V_53 , V_73 ) & 0x7 )
| ( ( V_53 -> V_72 [ 3 ] << 4 ) & 0x70 ) ;
F_33 ( V_53 , V_73 , V_2 ) ;
break;
}
}
static void F_37 ( struct V_52 * V_53 , int V_15 )
{
if ( V_53 -> V_54 == V_56 )
F_36 ( V_53 , V_15 ) ;
}
static void F_38 ( struct V_52 * V_53 )
{
T_1 V_34 ;
V_34 = F_31 ( V_53 , V_71 ) ;
V_53 -> V_72 [ 0 ] = V_34 & 0x7 ;
V_53 -> V_72 [ 1 ] = ( V_34 & 0x70 ) >> 4 ;
V_34 = F_31 ( V_53 , V_73 ) ;
V_53 -> V_72 [ 2 ] = V_34 & 0x7 ;
if ( V_53 -> V_74 & F_20 ( 3 ) )
V_53 -> V_72 [ 3 ] = ( V_34 & 0x70 ) >> 4 ;
}
static void F_39 ( struct V_52 * V_53 )
{
if ( V_53 -> V_54 == V_56 )
F_38 ( V_53 ) ;
}
static void F_40 ( struct V_52 * V_53 )
{
int V_34 ;
F_39 ( V_53 ) ;
for ( V_34 = 0 ; V_34 < F_41 ( V_53 -> V_72 ) ; V_34 ++ ) {
if ( ! ( V_53 -> V_74 & F_20 ( V_34 ) ) )
continue;
if ( V_53 -> V_72 [ V_34 ] == 0 ) {
V_53 -> V_72 [ V_34 ] = 7 ;
F_37 ( V_53 , V_34 ) ;
}
}
}
static void F_42 ( struct V_18 * V_19 ,
struct V_52 * V_53 )
{
int V_34 ;
T_1 V_2 ;
if ( V_53 -> V_75 )
F_40 ( V_53 ) ;
for ( V_34 = 0 ; V_34 < F_41 ( V_53 -> V_76 ) ; V_34 ++ ) {
if ( V_53 -> V_77 & F_20 ( V_34 ) ) {
V_2 = F_31 ( V_53 , V_53 -> V_78 [ V_34 ] ) ;
if ( ! V_2 )
F_33 ( V_53 , V_53 -> V_78 [ V_34 ] ,
V_53 -> V_75 ? 0xff
: 0xff1f ) ;
}
}
}
static void F_43 ( struct V_18 * V_19 ,
struct V_52 * V_53 , int V_15 , T_2 V_2 )
{
T_1 V_72 = V_53 -> V_72 [ V_15 ] ;
T_2 V_76 ;
if ( ! V_53 -> V_75 )
return;
if ( V_2 == 0x00 && V_72 < 0x07 )
V_72 ++ ;
else if ( V_2 != 0x00 && V_2 < 0x30 && V_72 > 0 )
V_72 -- ;
if ( V_72 != V_53 -> V_72 [ V_15 ] ) {
F_44 ( V_19 , L_1 ,
V_15 + 1 , F_19 ( V_53 -> V_72 [ V_15 ] ) ,
F_19 ( V_72 ) ) ;
if ( V_53 -> V_77 & F_20 ( V_15 ) ) {
V_76 = V_53 -> V_76 [ V_15 ] ;
if ( V_72 > V_53 -> V_72 [ V_15 ] ) {
if ( V_76 != 255 && V_76 > 1 )
V_76 >>= 1 ;
} else {
if ( V_76 != 255 ) {
V_76 <<= 1 ;
if ( V_76 > 254 )
V_76 = 254 ;
}
}
if ( V_76 != V_53 -> V_76 [ V_15 ] ) {
V_53 -> V_76 [ V_15 ] = V_76 ;
F_33 ( V_53 , V_53 -> V_78 [ V_15 ] ,
V_76 ) ;
}
}
V_53 -> V_72 [ V_15 ] = V_72 ;
F_37 ( V_53 , V_15 ) ;
}
}
static void F_45 ( struct V_18 * V_19 )
{
struct V_52 * V_53 = F_46 ( V_19 ) ;
int V_34 , V_79 ;
int V_80 , V_2 ;
bool V_81 ;
for ( V_34 = 0 ; V_34 < V_53 -> V_82 ; V_34 ++ ) {
if ( ! ( V_53 -> V_83 & F_20 ( V_34 ) ) )
continue;
V_81 = V_53 -> V_84 [ V_34 ] &&
( F_31 ( V_53 , V_53 -> V_84 [ V_34 ] )
& V_53 -> V_85 [ V_34 ] ) ;
V_53 -> V_86 [ V_34 ] = V_81 ;
V_80 = F_31 ( V_53 , V_53 -> V_87 [ V_34 ] ) ;
for ( V_79 = 0 ; V_79 < F_41 ( V_53 -> V_88 ) ; V_79 ++ ) {
if ( V_53 -> V_88 [ V_79 ] && V_53 -> V_88 [ V_79 ] [ V_34 ] ) {
V_53 -> V_9 [ V_79 ] [ V_34 ]
= F_31 ( V_53 ,
V_53 -> V_88 [ V_79 ] [ V_34 ] ) ;
}
}
V_53 -> V_8 [ V_34 ] = F_10 ( V_53 -> V_9 [ 0 ] [ V_34 ] ,
( V_80 >> 4 ) & 7 ) ;
if ( ! V_53 -> V_89 [ 0 ] [ V_34 ] ||
V_53 -> V_8 [ V_34 ] != V_90 )
V_53 -> V_89 [ 0 ] [ V_34 ] = V_80 & 0x0f ;
if ( ! V_53 -> V_91 [ V_34 ] ||
V_53 -> V_8 [ V_34 ] == V_90 ) {
T_1 V_33 = V_80 & 0x0f ;
if ( V_53 -> V_92 ) {
V_33 |= ( F_31 ( V_53 ,
V_53 -> V_92 [ V_34 ] ) & 0x70 ) >> 1 ;
}
V_53 -> V_91 [ V_34 ] = V_33 ;
}
V_53 -> V_89 [ 1 ] [ V_34 ] =
F_31 ( V_53 ,
V_53 -> V_93 [ V_34 ] ) ;
V_2 = F_31 ( V_53 , V_53 -> V_94 [ V_34 ] ) ;
V_53 -> V_95 [ V_34 ] = V_2 & 0x1f ;
if ( V_2 & 0x80 )
V_53 -> V_9 [ 2 ] [ V_34 ] = 0 ;
if ( ! V_53 -> V_96 [ V_34 ] )
continue;
V_2 = F_31 ( V_53 , V_53 -> V_96 [ V_34 ] ) ;
V_53 -> V_97 [ V_34 ] = V_2 & 0x1f ;
if ( V_79 == 1 && ! ( V_2 & 0x80 ) )
V_53 -> V_97 [ V_34 ] = 0 ;
for ( V_79 = 0 ; V_79 < F_41 ( V_53 -> V_98 ) ; V_79 ++ ) {
V_53 -> V_98 [ V_79 ] [ V_34 ]
= F_31 ( V_53 ,
V_53 -> V_99 [ V_79 ] [ V_34 ] ) ;
}
}
}
static void F_47 ( struct V_18 * V_19 )
{
struct V_52 * V_53 = F_46 ( V_19 ) ;
int V_34 , V_79 ;
T_1 V_2 ;
T_2 V_100 ;
for ( V_34 = 0 ; V_34 < V_53 -> V_82 ; V_34 ++ ) {
if ( ! ( V_53 -> V_83 & F_20 ( V_34 ) ) )
continue;
for ( V_79 = 0 ; V_79 < F_41 ( V_53 -> V_101 ) ; V_79 ++ ) {
V_53 -> V_101 [ V_79 ] [ V_34 ] =
F_31 ( V_53 , V_53 -> V_102 [ V_79 ] [ V_34 ] ) ;
}
V_100 = F_31 ( V_53 , V_53 -> V_103 [ V_34 ] ) ;
if ( ! V_53 -> V_104 [ V_34 ] ||
V_53 -> V_8 [ V_34 ] == V_105 )
V_53 -> V_104 [ V_34 ] = V_100 & V_53 -> V_106 ;
if ( ! V_53 -> V_107 [ V_34 ] ||
V_53 -> V_8 [ V_34 ] == V_90 ) {
if ( V_53 -> V_92 ) {
V_100 |= ( F_31 ( V_53 ,
V_53 -> V_92 [ V_34 ] ) & 0x0f ) << 8 ;
}
V_53 -> V_107 [ V_34 ] = V_100 ;
}
for ( V_79 = 0 ; V_79 < V_53 -> V_108 ; V_79 ++ ) {
V_53 -> V_109 [ V_34 ] [ V_79 ] =
F_31 ( V_53 ,
F_48 ( V_53 , V_34 , V_79 ) ) ;
V_53 -> V_110 [ V_34 ] [ V_79 ] =
F_31 ( V_53 ,
F_49 ( V_53 , V_34 , V_79 ) ) ;
}
V_53 -> V_110 [ V_34 ] [ V_53 -> V_108 ] =
F_31 ( V_53 , V_53 -> V_111 [ V_34 ] ) ;
switch ( V_53 -> V_54 ) {
case V_56 :
V_2 = F_31 ( V_53 ,
V_112 [ V_34 ] ) ;
V_53 -> V_109 [ V_34 ] [ V_53 -> V_108 ] =
( V_2 & 0x02 ) ? 0xff : 0x00 ;
break;
case V_57 :
V_53 -> V_109 [ V_34 ] [ V_53 -> V_108 ] = 0xff ;
break;
case V_55 :
case V_58 :
case V_59 :
case V_60 :
case V_61 :
case V_62 :
V_2 = F_31 ( V_53 ,
V_53 -> V_113 [ V_34 ] ) ;
if ( V_2 & V_53 -> V_114 )
V_2 = F_31 ( V_53 ,
V_53 -> V_115 [ V_34 ] ) ;
else
V_2 = 0xff ;
V_53 -> V_109 [ V_34 ] [ V_53 -> V_108 ] = V_2 ;
break;
}
}
}
static struct V_52 * F_50 ( struct V_18 * V_19 )
{
struct V_52 * V_53 = F_46 ( V_19 ) ;
int V_34 , V_79 ;
F_51 ( & V_53 -> V_116 ) ;
if ( F_52 ( V_117 , V_53 -> V_118 + V_119 + V_119 / 2 )
|| ! V_53 -> V_120 ) {
F_39 ( V_53 ) ;
for ( V_34 = 0 ; V_34 < V_53 -> V_121 ; V_34 ++ ) {
if ( ! ( V_53 -> V_122 & F_20 ( V_34 ) ) )
continue;
V_53 -> V_123 [ V_34 ] [ 0 ] = F_31 ( V_53 ,
V_53 -> V_124 [ V_34 ] ) ;
V_53 -> V_123 [ V_34 ] [ 1 ] = F_31 ( V_53 ,
V_53 -> V_125 [ 0 ] [ V_34 ] ) ;
V_53 -> V_123 [ V_34 ] [ 2 ] = F_31 ( V_53 ,
V_53 -> V_125 [ 1 ] [ V_34 ] ) ;
}
for ( V_34 = 0 ; V_34 < F_41 ( V_53 -> V_126 ) ; V_34 ++ ) {
T_2 V_2 ;
if ( ! ( V_53 -> V_74 & F_20 ( V_34 ) ) )
continue;
V_2 = F_31 ( V_53 , V_53 -> V_127 [ V_34 ] ) ;
V_53 -> V_126 [ V_34 ] = V_53 -> V_128 ( V_2 ,
V_53 -> V_72 [ V_34 ] ) ;
if ( V_53 -> V_77 & F_20 ( V_34 ) )
V_53 -> V_76 [ V_34 ] = F_31 ( V_53 ,
V_53 -> V_78 [ V_34 ] ) ;
V_53 -> V_129 [ V_34 ] =
( F_31 ( V_53 , V_53 -> V_130 [ V_34 ] )
>> V_53 -> V_131 [ V_34 ] ) & 0x03 ;
F_43 ( V_19 , V_53 , V_34 , V_2 ) ;
}
F_45 ( V_19 ) ;
F_47 ( V_19 ) ;
for ( V_34 = 0 ; V_34 < V_132 ; V_34 ++ ) {
if ( ! ( V_53 -> V_133 & F_20 ( V_34 ) ) )
continue;
for ( V_79 = 0 ; V_79 < F_41 ( V_53 -> V_134 ) ; V_79 ++ ) {
if ( V_53 -> V_134 [ V_79 ] [ V_34 ] )
V_53 -> V_135 [ V_79 ] [ V_34 ]
= F_34 ( V_53 ,
V_53 -> V_134 [ V_79 ] [ V_34 ] ) ;
}
if ( V_34 >= V_136 ||
! ( V_53 -> V_137 & F_20 ( V_34 ) ) )
continue;
V_53 -> V_138 [ V_34 ]
= F_31 ( V_53 , V_53 -> V_139 [ V_34 ] ) ;
}
V_53 -> V_140 = 0 ;
for ( V_34 = 0 ; V_34 < V_141 ; V_34 ++ ) {
T_1 V_142 ;
if ( ! V_53 -> V_143 [ V_34 ] )
continue;
V_142 = F_31 ( V_53 , V_53 -> V_143 [ V_34 ] ) ;
V_53 -> V_140 |= ( ( V_144 ) V_142 ) << ( V_34 << 3 ) ;
}
V_53 -> V_145 = 0 ;
for ( V_34 = 0 ; V_34 < V_146 ; V_34 ++ ) {
T_1 V_147 ;
if ( ! V_53 -> V_148 [ V_34 ] )
continue;
V_147 = F_31 ( V_53 , V_53 -> V_148 [ V_34 ] ) ;
V_53 -> V_145 |= ( ( V_144 ) V_147 ) << ( V_34 << 3 ) ;
}
V_53 -> V_118 = V_117 ;
V_53 -> V_120 = true ;
}
F_53 ( & V_53 -> V_116 ) ;
return V_53 ;
}
static T_4
F_54 ( struct V_18 * V_19 , struct V_149 * V_43 , char * V_150 )
{
struct V_52 * V_53 = F_50 ( V_19 ) ;
struct V_28 * V_151 = F_55 ( V_43 ) ;
int V_48 = V_151 -> V_48 ;
int V_15 = V_151 -> V_15 ;
return sprintf ( V_150 , L_2 , F_21 ( V_53 -> V_123 [ V_15 ] [ V_48 ] , V_15 ) ) ;
}
static T_4
F_56 ( struct V_18 * V_19 , struct V_149 * V_43 , const char * V_150 ,
T_5 V_35 )
{
struct V_52 * V_53 = F_46 ( V_19 ) ;
struct V_28 * V_151 = F_55 ( V_43 ) ;
int V_48 = V_151 -> V_48 ;
int V_15 = V_151 -> V_15 ;
unsigned long V_3 ;
int V_152 ;
V_152 = F_57 ( V_150 , 10 , & V_3 ) ;
if ( V_152 < 0 )
return V_152 ;
F_51 ( & V_53 -> V_116 ) ;
V_53 -> V_123 [ V_15 ] [ V_48 ] = F_23 ( V_3 , V_15 ) ;
F_33 ( V_53 , V_53 -> V_125 [ V_48 - 1 ] [ V_15 ] ,
V_53 -> V_123 [ V_15 ] [ V_48 ] ) ;
F_53 ( & V_53 -> V_116 ) ;
return V_35 ;
}
static T_4
F_58 ( struct V_18 * V_19 , struct V_149 * V_43 , char * V_150 )
{
struct V_52 * V_53 = F_50 ( V_19 ) ;
struct V_26 * V_151 = F_59 ( V_43 ) ;
int V_15 = V_53 -> V_153 [ V_151 -> V_48 ] ;
return sprintf ( V_150 , L_3 ,
( unsigned int ) ( ( V_53 -> V_140 >> V_15 ) & 0x01 ) ) ;
}
static int F_60 ( struct V_52 * V_53 , int V_48 , int V_35 )
{
int V_154 = V_53 -> V_155 [ V_48 ] ;
int V_15 ;
for ( V_15 = 0 ; V_15 < V_35 ; V_15 ++ ) {
int V_156 ;
V_156 = F_31 ( V_53 ,
V_53 -> V_157 [ V_15 ] ) & 0x1f ;
if ( V_156 == V_154 )
return V_15 ;
}
return - V_158 ;
}
static T_4
F_61 ( struct V_18 * V_19 , struct V_149 * V_43 , char * V_150 )
{
struct V_26 * V_151 = F_59 ( V_43 ) ;
struct V_52 * V_53 = F_50 ( V_19 ) ;
unsigned int V_142 = 0 ;
int V_15 ;
V_15 = F_60 ( V_53 , V_151 -> V_48 , V_53 -> V_159 ) ;
if ( V_15 >= 0 ) {
int V_160 = V_53 -> V_153 [ V_15 + V_161 ] ;
V_142 = ( V_53 -> V_140 >> V_160 ) & 0x01 ;
}
return sprintf ( V_150 , L_3 , V_142 ) ;
}
static T_4
F_62 ( struct V_18 * V_19 , struct V_149 * V_43 , char * V_150 )
{
struct V_26 * V_151 = F_59 ( V_43 ) ;
struct V_52 * V_53 = F_50 ( V_19 ) ;
int V_15 = V_53 -> V_162 [ V_151 -> V_48 ] ;
return sprintf ( V_150 , L_3 ,
( unsigned int ) ( ( V_53 -> V_145 >> V_15 ) & 0x01 ) ) ;
}
static T_4
F_63 ( struct V_18 * V_19 , struct V_149 * V_43 , const char * V_150 ,
T_5 V_35 )
{
struct V_28 * V_151 = F_55 ( V_43 ) ;
struct V_52 * V_53 = F_46 ( V_19 ) ;
int V_15 = V_53 -> V_162 [ V_151 -> V_48 ] ;
int V_163 = V_15 >> 3 ;
unsigned long V_3 ;
int V_152 ;
V_152 = F_57 ( V_150 , 10 , & V_3 ) ;
if ( V_152 < 0 )
return V_152 ;
if ( V_3 > 1 )
return - V_36 ;
F_51 ( & V_53 -> V_116 ) ;
if ( V_3 )
V_53 -> V_145 |= ( 1ULL << V_15 ) ;
else
V_53 -> V_145 &= ~ ( 1ULL << V_15 ) ;
F_33 ( V_53 , V_53 -> V_148 [ V_163 ] ,
( V_53 -> V_145 >> ( V_163 << 3 ) ) & 0xff ) ;
F_53 ( & V_53 -> V_116 ) ;
return V_35 ;
}
static T_4
F_64 ( struct V_18 * V_19 , struct V_149 * V_43 , char * V_150 )
{
struct V_26 * V_151 = F_59 ( V_43 ) ;
struct V_52 * V_53 = F_50 ( V_19 ) ;
unsigned int V_147 = 0 ;
int V_15 ;
V_15 = F_60 ( V_53 , V_151 -> V_48 , V_53 -> V_164 ) ;
if ( V_15 >= 0 ) {
int V_160 = V_53 -> V_162 [ V_15 + V_161 ] ;
V_147 = ( V_53 -> V_145 >> V_160 ) & 0x01 ;
}
return sprintf ( V_150 , L_3 , V_147 ) ;
}
static T_4
F_65 ( struct V_18 * V_19 , struct V_149 * V_43 ,
const char * V_150 , T_5 V_35 )
{
struct V_28 * V_151 = F_55 ( V_43 ) ;
struct V_52 * V_53 = F_46 ( V_19 ) ;
int V_15 , V_160 , V_163 ;
unsigned long V_3 ;
int V_152 ;
V_152 = F_57 ( V_150 , 10 , & V_3 ) ;
if ( V_152 < 0 )
return V_152 ;
if ( V_3 > 1 )
return - V_36 ;
V_15 = F_60 ( V_53 , V_151 -> V_48 , V_53 -> V_164 ) ;
if ( V_15 < 0 )
return V_15 ;
V_160 = V_53 -> V_162 [ V_15 + V_161 ] ;
V_163 = V_160 >> 3 ;
F_51 ( & V_53 -> V_116 ) ;
if ( V_3 )
V_53 -> V_145 |= ( 1ULL << V_160 ) ;
else
V_53 -> V_145 &= ~ ( 1ULL << V_160 ) ;
F_33 ( V_53 , V_53 -> V_148 [ V_163 ] ,
( V_53 -> V_145 >> ( V_163 << 3 ) ) & 0xff ) ;
F_53 ( & V_53 -> V_116 ) ;
return V_35 ;
}
static T_6 F_66 ( struct V_165 * V_166 ,
struct V_30 * V_43 , int V_48 )
{
struct V_18 * V_19 = F_67 ( V_166 , struct V_18 , V_166 ) ;
struct V_52 * V_53 = F_46 ( V_19 ) ;
int V_123 = V_48 / 5 ;
if ( ! ( V_53 -> V_122 & F_20 ( V_123 ) ) )
return 0 ;
return V_43 -> V_10 ;
}
static T_4
F_68 ( struct V_18 * V_19 , struct V_149 * V_43 , char * V_150 )
{
struct V_52 * V_53 = F_50 ( V_19 ) ;
struct V_26 * V_151 = F_59 ( V_43 ) ;
int V_15 = V_151 -> V_48 ;
return sprintf ( V_150 , L_4 , V_53 -> V_126 [ V_15 ] ) ;
}
static T_4
F_69 ( struct V_18 * V_19 , struct V_149 * V_43 , char * V_150 )
{
struct V_52 * V_53 = F_50 ( V_19 ) ;
struct V_26 * V_151 = F_59 ( V_43 ) ;
int V_15 = V_151 -> V_48 ;
return sprintf ( V_150 , L_4 ,
V_53 -> V_167 ( V_53 -> V_76 [ V_15 ] ,
V_53 -> V_72 [ V_15 ] ) ) ;
}
static T_4
F_70 ( struct V_18 * V_19 , struct V_149 * V_43 , char * V_150 )
{
struct V_52 * V_53 = F_50 ( V_19 ) ;
struct V_26 * V_151 = F_59 ( V_43 ) ;
int V_15 = V_151 -> V_48 ;
return sprintf ( V_150 , L_3 , F_19 ( V_53 -> V_72 [ V_15 ] ) ) ;
}
static T_4
F_71 ( struct V_18 * V_19 , struct V_149 * V_43 ,
const char * V_150 , T_5 V_35 )
{
struct V_52 * V_53 = F_46 ( V_19 ) ;
struct V_26 * V_151 = F_59 ( V_43 ) ;
int V_15 = V_151 -> V_48 ;
unsigned long V_3 ;
unsigned int V_2 ;
T_1 V_168 ;
int V_152 ;
V_152 = F_57 ( V_150 , 10 , & V_3 ) ;
if ( V_152 < 0 )
return V_152 ;
F_51 ( & V_53 -> V_116 ) ;
if ( ! V_53 -> V_75 ) {
if ( ! V_3 ) {
V_3 = 0xff1f ;
} else {
if ( V_3 > 1350000U )
V_3 = 135000U ;
V_3 = 1350000U / V_3 ;
V_3 = ( V_3 & 0x1f ) | ( ( V_3 << 3 ) & 0xff00 ) ;
}
V_53 -> V_76 [ V_15 ] = V_3 ;
goto V_169;
}
if ( ! V_3 ) {
V_53 -> V_76 [ V_15 ] = 255 ;
V_168 = V_53 -> V_72 [ V_15 ] ;
F_72 ( V_19 , L_5 , V_15 + 1 ) ;
goto V_170;
}
V_2 = 1350000U / V_3 ;
if ( V_2 >= 128 * 255 ) {
V_53 -> V_76 [ V_15 ] = 254 ;
V_168 = 7 ;
F_73 ( V_19 ,
L_6 ,
V_15 + 1 , V_3 , V_53 -> V_167 ( 254 , 7 ) ) ;
} else if ( ! V_2 ) {
V_53 -> V_76 [ V_15 ] = 1 ;
V_168 = 0 ;
F_73 ( V_19 ,
L_7 ,
V_15 + 1 , V_3 , V_53 -> V_167 ( 1 , 0 ) ) ;
} else {
V_168 = 0 ;
while ( V_2 > 192 && V_168 < 7 ) {
V_2 >>= 1 ;
V_168 ++ ;
}
V_53 -> V_76 [ V_15 ] = V_2 ;
}
V_170:
if ( V_168 != V_53 -> V_72 [ V_15 ] ) {
F_44 ( V_19 , L_8 ,
V_15 + 1 , F_19 ( V_53 -> V_72 [ V_15 ] ) ,
F_19 ( V_168 ) ) ;
V_53 -> V_72 [ V_15 ] = V_168 ;
F_37 ( V_53 , V_15 ) ;
V_53 -> V_118 = V_117 ;
}
V_169:
F_33 ( V_53 , V_53 -> V_78 [ V_15 ] , V_53 -> V_76 [ V_15 ] ) ;
F_53 ( & V_53 -> V_116 ) ;
return V_35 ;
}
static T_4
F_74 ( struct V_18 * V_19 , struct V_149 * V_43 , char * V_150 )
{
struct V_52 * V_53 = F_50 ( V_19 ) ;
struct V_26 * V_151 = F_59 ( V_43 ) ;
int V_171 = V_53 -> V_129 [ V_151 -> V_48 ] ;
return sprintf ( V_150 , L_4 , V_171 ? : 4 ) ;
}
static T_4
F_75 ( struct V_18 * V_19 , struct V_149 * V_43 ,
const char * V_150 , T_5 V_35 )
{
struct V_52 * V_53 = F_46 ( V_19 ) ;
struct V_26 * V_151 = F_59 ( V_43 ) ;
int V_15 = V_151 -> V_48 ;
unsigned long V_3 ;
int V_152 ;
T_1 V_2 ;
V_152 = F_57 ( V_150 , 10 , & V_3 ) ;
if ( V_152 < 0 )
return V_152 ;
if ( V_3 > 4 )
return - V_36 ;
F_51 ( & V_53 -> V_116 ) ;
V_53 -> V_129 [ V_15 ] = V_3 & 3 ;
V_2 = F_31 ( V_53 , V_53 -> V_130 [ V_15 ] ) ;
V_2 &= ~ ( 0x03 << V_53 -> V_131 [ V_15 ] ) ;
V_2 |= ( V_3 & 3 ) << V_53 -> V_131 [ V_15 ] ;
F_33 ( V_53 , V_53 -> V_130 [ V_15 ] , V_2 ) ;
F_53 ( & V_53 -> V_116 ) ;
return V_35 ;
}
static T_6 F_76 ( struct V_165 * V_166 ,
struct V_30 * V_43 , int V_48 )
{
struct V_18 * V_19 = F_67 ( V_166 , struct V_18 , V_166 ) ;
struct V_52 * V_53 = F_46 ( V_19 ) ;
int V_14 = V_48 / 6 ;
int V_15 = V_48 % 6 ;
if ( ! ( V_53 -> V_74 & F_20 ( V_14 ) ) )
return 0 ;
if ( V_15 == 1 && V_53 -> V_153 [ V_172 + V_14 ] == - 1 )
return 0 ;
if ( V_15 == 2 && V_53 -> V_162 [ V_172 + V_14 ] == - 1 )
return 0 ;
if ( V_15 == 4 && ! ( V_53 -> V_77 & F_20 ( V_14 ) ) )
return 0 ;
if ( V_15 == 5 && V_53 -> V_54 != V_56 )
return 0 ;
return V_43 -> V_10 ;
}
static T_4
F_77 ( struct V_18 * V_19 , struct V_149 * V_43 , char * V_150 )
{
struct V_52 * V_53 = F_50 ( V_19 ) ;
struct V_26 * V_151 = F_59 ( V_43 ) ;
int V_15 = V_151 -> V_48 ;
return sprintf ( V_150 , L_9 , V_53 -> V_173 [ V_53 -> V_155 [ V_15 ] ] ) ;
}
static T_4
F_78 ( struct V_18 * V_19 , struct V_149 * V_43 , char * V_150 )
{
struct V_52 * V_53 = F_50 ( V_19 ) ;
struct V_28 * V_151 = F_55 ( V_43 ) ;
int V_15 = V_151 -> V_15 ;
int V_48 = V_151 -> V_48 ;
return sprintf ( V_150 , L_4 , F_79 ( V_53 -> V_135 [ V_48 ] [ V_15 ] ) ) ;
}
static T_4
F_80 ( struct V_18 * V_19 , struct V_149 * V_43 , const char * V_150 ,
T_5 V_35 )
{
struct V_52 * V_53 = F_46 ( V_19 ) ;
struct V_28 * V_151 = F_55 ( V_43 ) ;
int V_15 = V_151 -> V_15 ;
int V_48 = V_151 -> V_48 ;
int V_152 ;
long V_3 ;
V_152 = F_81 ( V_150 , 10 , & V_3 ) ;
if ( V_152 < 0 )
return V_152 ;
F_51 ( & V_53 -> V_116 ) ;
V_53 -> V_135 [ V_48 ] [ V_15 ] = F_82 ( V_3 ) ;
F_35 ( V_53 , V_53 -> V_134 [ V_48 ] [ V_15 ] ,
V_53 -> V_135 [ V_48 ] [ V_15 ] ) ;
F_53 ( & V_53 -> V_116 ) ;
return V_35 ;
}
static T_4
F_83 ( struct V_18 * V_19 , struct V_149 * V_43 , char * V_150 )
{
struct V_52 * V_53 = F_50 ( V_19 ) ;
struct V_26 * V_151 = F_59 ( V_43 ) ;
return sprintf ( V_150 , L_4 , V_53 -> V_138 [ V_151 -> V_48 ] * 1000 ) ;
}
static T_4
F_84 ( struct V_18 * V_19 , struct V_149 * V_43 ,
const char * V_150 , T_5 V_35 )
{
struct V_52 * V_53 = F_46 ( V_19 ) ;
struct V_26 * V_151 = F_59 ( V_43 ) ;
int V_15 = V_151 -> V_48 ;
long V_3 ;
int V_152 ;
V_152 = F_81 ( V_150 , 10 , & V_3 ) ;
if ( V_152 < 0 )
return V_152 ;
V_3 = F_14 ( F_22 ( V_3 , 1000 ) , - 128 , 127 ) ;
F_51 ( & V_53 -> V_116 ) ;
V_53 -> V_138 [ V_15 ] = V_3 ;
F_33 ( V_53 , V_53 -> V_139 [ V_15 ] , V_3 ) ;
F_53 ( & V_53 -> V_116 ) ;
return V_35 ;
}
static T_4
F_85 ( struct V_18 * V_19 , struct V_149 * V_43 , char * V_150 )
{
struct V_52 * V_53 = F_50 ( V_19 ) ;
struct V_26 * V_151 = F_59 ( V_43 ) ;
int V_15 = V_151 -> V_48 ;
return sprintf ( V_150 , L_4 , ( int ) V_53 -> V_174 [ V_15 ] ) ;
}
static T_4
F_86 ( struct V_18 * V_19 , struct V_149 * V_43 ,
const char * V_150 , T_5 V_35 )
{
struct V_52 * V_53 = F_50 ( V_19 ) ;
struct V_26 * V_151 = F_59 ( V_43 ) ;
int V_15 = V_151 -> V_48 ;
unsigned long V_3 ;
int V_152 ;
T_1 V_175 , V_176 , V_177 , V_178 ;
V_152 = F_57 ( V_150 , 10 , & V_3 ) ;
if ( V_152 < 0 )
return V_152 ;
if ( V_3 != 1 && V_3 != 3 && V_3 != 4 )
return - V_36 ;
F_51 ( & V_53 -> V_116 ) ;
V_53 -> V_174 [ V_15 ] = V_3 ;
V_177 = 0x02 << V_15 ;
V_178 = V_53 -> V_179 << V_15 ;
V_175 = F_31 ( V_53 , V_53 -> V_180 ) & ~ V_177 ;
V_176 = F_31 ( V_53 , V_53 -> V_181 ) & ~ V_178 ;
switch ( V_3 ) {
case 1 :
V_175 |= V_177 ;
V_176 |= V_178 ;
break;
case 3 :
V_175 |= V_178 ;
break;
case 4 :
break;
}
F_33 ( V_53 , V_53 -> V_180 , V_175 ) ;
F_33 ( V_53 , V_53 -> V_181 , V_176 ) ;
F_53 ( & V_53 -> V_116 ) ;
return V_35 ;
}
static T_6 F_87 ( struct V_165 * V_166 ,
struct V_30 * V_43 , int V_48 )
{
struct V_18 * V_19 = F_67 ( V_166 , struct V_18 , V_166 ) ;
struct V_52 * V_53 = F_46 ( V_19 ) ;
int V_135 = V_48 / 10 ;
int V_15 = V_48 % 10 ;
if ( ! ( V_53 -> V_133 & F_20 ( V_135 ) ) )
return 0 ;
if ( V_15 == 1 && ! V_53 -> V_173 )
return 0 ;
if ( V_15 == 2 && F_60 ( V_53 , V_135 , V_53 -> V_159 ) < 0 )
return 0 ;
if ( V_15 == 3 && F_60 ( V_53 , V_135 , V_53 -> V_164 ) < 0 )
return 0 ;
if ( V_15 == 4 && ! V_53 -> V_134 [ 1 ] [ V_135 ] )
return 0 ;
if ( V_15 == 5 && ! V_53 -> V_134 [ 2 ] [ V_135 ] )
return 0 ;
if ( V_15 == 6 && ! V_53 -> V_134 [ 3 ] [ V_135 ] )
return 0 ;
if ( V_15 == 7 && ! V_53 -> V_134 [ 4 ] [ V_135 ] )
return 0 ;
if ( V_15 > 7 && ! ( V_53 -> V_137 & F_20 ( V_135 ) ) )
return 0 ;
return V_43 -> V_10 ;
}
static T_4
F_88 ( struct V_18 * V_19 , struct V_149 * V_43 , char * V_150 )
{
struct V_52 * V_53 = F_50 ( V_19 ) ;
struct V_26 * V_151 = F_59 ( V_43 ) ;
return sprintf ( V_150 , L_4 , ! V_53 -> V_86 [ V_151 -> V_48 ] ) ;
}
static T_4
F_89 ( struct V_18 * V_19 , struct V_149 * V_43 ,
const char * V_150 , T_5 V_35 )
{
struct V_52 * V_53 = F_46 ( V_19 ) ;
struct V_26 * V_151 = F_59 ( V_43 ) ;
int V_15 = V_151 -> V_48 ;
unsigned long V_3 ;
int V_152 ;
T_1 V_2 ;
V_152 = F_57 ( V_150 , 10 , & V_3 ) ;
if ( V_152 < 0 )
return V_152 ;
if ( V_3 > 1 )
return - V_36 ;
if ( V_53 -> V_84 [ V_15 ] == 0 ) {
if ( V_3 )
return - V_36 ;
return V_35 ;
}
F_51 ( & V_53 -> V_116 ) ;
V_53 -> V_86 [ V_15 ] = V_3 ;
V_2 = F_31 ( V_53 , V_53 -> V_84 [ V_15 ] ) ;
V_2 &= ~ V_53 -> V_85 [ V_15 ] ;
if ( V_3 )
V_2 |= V_53 -> V_85 [ V_15 ] ;
F_33 ( V_53 , V_53 -> V_84 [ V_15 ] , V_2 ) ;
F_53 ( & V_53 -> V_116 ) ;
return V_35 ;
}
static T_4
F_90 ( struct V_18 * V_19 , struct V_149 * V_43 , char * V_150 )
{
struct V_52 * V_53 = F_50 ( V_19 ) ;
struct V_28 * V_151 = F_55 ( V_43 ) ;
int V_15 = V_151 -> V_15 ;
int V_48 = V_151 -> V_48 ;
int V_9 ;
if ( V_48 == 0 && V_53 -> V_8 [ V_15 ] > V_182 )
V_9 = F_31 ( V_53 , V_53 -> V_183 [ V_15 ] ) ;
else
V_9 = V_53 -> V_9 [ V_48 ] [ V_15 ] ;
return sprintf ( V_150 , L_4 , V_9 ) ;
}
static T_4
F_91 ( struct V_18 * V_19 , struct V_149 * V_43 , const char * V_150 ,
T_5 V_35 )
{
struct V_52 * V_53 = F_46 ( V_19 ) ;
struct V_28 * V_151 = F_55 ( V_43 ) ;
int V_15 = V_151 -> V_15 ;
int V_48 = V_151 -> V_48 ;
unsigned long V_3 ;
int V_184 [ 7 ] = { 0 , 1 , 1 , V_53 -> V_9 [ 2 ] [ V_15 ] , 0 , 0 , 0 } ;
int V_185 [ 7 ]
= { 255 , 255 , V_53 -> V_9 [ 3 ] [ V_15 ] ? : 255 , 255 , 255 , 255 , 255 } ;
int V_152 ;
T_1 V_2 ;
V_152 = F_57 ( V_150 , 10 , & V_3 ) ;
if ( V_152 < 0 )
return V_152 ;
V_3 = F_14 ( V_3 , V_184 [ V_48 ] , V_185 [ V_48 ] ) ;
F_51 ( & V_53 -> V_116 ) ;
V_53 -> V_9 [ V_48 ] [ V_15 ] = V_3 ;
F_33 ( V_53 , V_53 -> V_88 [ V_48 ] [ V_15 ] , V_3 ) ;
if ( V_48 == 2 ) {
V_2 = F_31 ( V_53 , V_53 -> V_94 [ V_15 ] ) ;
V_2 &= 0x7f ;
if ( V_3 )
V_2 |= 0x80 ;
F_33 ( V_53 , V_53 -> V_94 [ V_15 ] , V_2 ) ;
}
F_53 ( & V_53 -> V_116 ) ;
return V_35 ;
}
static int F_92 ( struct V_52 * V_53 , int V_15 )
{
int V_34 ;
for ( V_34 = 0 ; V_34 < V_53 -> V_108 - 1 ; V_34 ++ ) {
if ( V_53 -> V_110 [ V_15 ] [ V_34 ] > V_53 -> V_110 [ V_15 ] [ V_34 + 1 ] )
return - V_36 ;
}
for ( V_34 = 0 ; V_34 < V_53 -> V_108 - 1 ; V_34 ++ ) {
if ( V_53 -> V_109 [ V_15 ] [ V_34 ] > V_53 -> V_109 [ V_15 ] [ V_34 + 1 ] )
return - V_36 ;
}
if ( V_53 -> V_109 [ V_15 ] [ V_53 -> V_108 ] ) {
if ( V_53 -> V_110 [ V_15 ] [ V_53 -> V_108 - 1 ] >
V_53 -> V_110 [ V_15 ] [ V_53 -> V_108 ] ||
V_53 -> V_109 [ V_15 ] [ V_53 -> V_108 - 1 ] >
V_53 -> V_109 [ V_15 ] [ V_53 -> V_108 ] )
return - V_36 ;
}
return 0 ;
}
static void F_93 ( struct V_52 * V_53 , int V_15 )
{
T_1 V_2 ;
switch ( V_53 -> V_8 [ V_15 ] ) {
case V_11 :
case V_182 :
break;
case V_90 :
V_2 = F_31 ( V_53 , V_53 -> V_87 [ V_15 ] ) ;
V_2 = ( V_2 & ~ V_53 -> V_186 ) |
( V_53 -> V_91 [ V_15 ] & V_53 -> V_186 ) ;
F_33 ( V_53 , V_53 -> V_87 [ V_15 ] , V_2 ) ;
F_33 ( V_53 , V_53 -> V_103 [ V_15 ] ,
V_53 -> V_107 [ V_15 ] & 0xff ) ;
if ( V_53 -> V_92 ) {
V_2 = ( V_53 -> V_107 [ V_15 ] >> 8 ) & 0x0f ;
V_2 |= ( V_53 -> V_91 [ V_15 ] & 0x38 ) << 1 ;
F_33 ( V_53 ,
V_53 -> V_92 [ V_15 ] ,
V_2 ) ;
}
break;
case V_105 :
F_33 ( V_53 , V_53 -> V_103 [ V_15 ] ,
V_53 -> V_104 [ V_15 ] ) ;
default:
V_2 = F_31 ( V_53 , V_53 -> V_87 [ V_15 ] ) ;
V_2 = ( V_2 & ~ V_53 -> V_186 ) |
V_53 -> V_89 [ 0 ] [ V_15 ] ;
F_33 ( V_53 , V_53 -> V_87 [ V_15 ] , V_2 ) ;
break;
}
}
static T_4
F_94 ( struct V_18 * V_19 , struct V_149 * V_43 , char * V_150 )
{
struct V_52 * V_53 = F_50 ( V_19 ) ;
struct V_26 * V_151 = F_59 ( V_43 ) ;
return sprintf ( V_150 , L_4 , V_53 -> V_8 [ V_151 -> V_48 ] ) ;
}
static T_4
F_95 ( struct V_18 * V_19 , struct V_149 * V_43 ,
const char * V_150 , T_5 V_35 )
{
struct V_52 * V_53 = F_46 ( V_19 ) ;
struct V_26 * V_151 = F_59 ( V_43 ) ;
int V_15 = V_151 -> V_48 ;
unsigned long V_3 ;
int V_152 ;
T_2 V_2 ;
V_152 = F_57 ( V_150 , 10 , & V_3 ) ;
if ( V_152 < 0 )
return V_152 ;
if ( V_3 > V_187 )
return - V_36 ;
if ( V_3 == V_188 && V_53 -> V_54 != V_56 )
return - V_36 ;
if ( V_3 == V_187 && F_92 ( V_53 , V_15 ) ) {
F_96 ( V_19 , L_10 ) ;
F_96 ( V_19 , L_11 ) ;
return - V_36 ;
}
F_51 ( & V_53 -> V_116 ) ;
V_53 -> V_8 [ V_15 ] = V_3 ;
if ( V_3 == V_11 ) {
V_53 -> V_9 [ 0 ] [ V_15 ] = 255 ;
F_33 ( V_53 , V_53 -> V_88 [ 0 ] [ V_15 ] , 255 ) ;
}
F_93 ( V_53 , V_15 ) ;
V_2 = F_31 ( V_53 , V_53 -> V_87 [ V_15 ] ) ;
V_2 &= 0x0f ;
V_2 |= F_11 ( V_3 ) << 4 ;
F_33 ( V_53 , V_53 -> V_87 [ V_15 ] , V_2 ) ;
F_53 ( & V_53 -> V_116 ) ;
return V_35 ;
}
static T_4
F_97 ( struct V_52 * V_53 , char * V_150 , int V_156 )
{
int V_34 , V_189 = 0 ;
for ( V_34 = 0 ; V_34 < V_132 ; V_34 ++ ) {
if ( ! ( V_53 -> V_133 & F_20 ( V_34 ) ) )
continue;
if ( V_156 == V_53 -> V_155 [ V_34 ] ) {
V_189 = V_34 + 1 ;
break;
}
}
return sprintf ( V_150 , L_4 , V_189 ) ;
}
static T_4
F_98 ( struct V_18 * V_19 , struct V_149 * V_43 , char * V_150 )
{
struct V_52 * V_53 = F_50 ( V_19 ) ;
struct V_26 * V_151 = F_59 ( V_43 ) ;
int V_48 = V_151 -> V_48 ;
return F_97 ( V_53 , V_150 , V_53 -> V_95 [ V_48 ] ) ;
}
static T_4
F_99 ( struct V_18 * V_19 , struct V_149 * V_43 ,
const char * V_150 , T_5 V_35 )
{
struct V_52 * V_53 = F_50 ( V_19 ) ;
struct V_26 * V_151 = F_59 ( V_43 ) ;
int V_15 = V_151 -> V_48 ;
unsigned long V_3 ;
int V_152 , V_2 , V_156 ;
V_152 = F_57 ( V_150 , 10 , & V_3 ) ;
if ( V_152 < 0 )
return V_152 ;
if ( V_3 == 0 || V_3 > V_132 )
return - V_36 ;
if ( ! ( V_53 -> V_133 & F_20 ( V_3 - 1 ) ) || ! V_53 -> V_155 [ V_3 - 1 ] )
return - V_36 ;
F_51 ( & V_53 -> V_116 ) ;
V_156 = V_53 -> V_155 [ V_3 - 1 ] ;
V_53 -> V_95 [ V_15 ] = V_156 ;
V_2 = F_31 ( V_53 , V_53 -> V_94 [ V_15 ] ) ;
V_2 &= 0xe0 ;
V_2 |= V_156 ;
F_33 ( V_53 , V_53 -> V_94 [ V_15 ] , V_2 ) ;
F_53 ( & V_53 -> V_116 ) ;
return V_35 ;
}
static T_4
F_100 ( struct V_18 * V_19 , struct V_149 * V_43 ,
char * V_150 )
{
struct V_52 * V_53 = F_50 ( V_19 ) ;
struct V_26 * V_151 = F_59 ( V_43 ) ;
int V_48 = V_151 -> V_48 ;
return F_97 ( V_53 , V_150 ,
V_53 -> V_97 [ V_48 ] ) ;
}
static T_4
F_101 ( struct V_18 * V_19 , struct V_149 * V_43 ,
const char * V_150 , T_5 V_35 )
{
struct V_52 * V_53 = F_50 ( V_19 ) ;
struct V_26 * V_151 = F_59 ( V_43 ) ;
int V_15 = V_151 -> V_48 ;
unsigned long V_3 ;
int V_152 , V_2 , V_156 ;
V_152 = F_57 ( V_150 , 10 , & V_3 ) ;
if ( V_152 < 0 )
return V_152 ;
if ( V_3 > V_132 )
return - V_36 ;
if ( V_3 && ( ! ( V_53 -> V_133 & F_20 ( V_3 - 1 ) ) ||
! V_53 -> V_155 [ V_3 - 1 ] ) )
return - V_36 ;
F_51 ( & V_53 -> V_116 ) ;
if ( V_3 ) {
V_156 = V_53 -> V_155 [ V_3 - 1 ] ;
V_53 -> V_97 [ V_15 ] = V_156 ;
V_2 = F_31 ( V_53 , V_53 -> V_96 [ V_15 ] ) ;
V_2 &= 0xe0 ;
V_2 |= ( V_156 | 0x80 ) ;
F_33 ( V_53 , V_53 -> V_96 [ V_15 ] , V_2 ) ;
} else {
V_53 -> V_97 [ V_15 ] = 0 ;
V_2 = F_31 ( V_53 , V_53 -> V_96 [ V_15 ] ) ;
V_2 &= 0x7f ;
F_33 ( V_53 , V_53 -> V_96 [ V_15 ] , V_2 ) ;
}
F_53 ( & V_53 -> V_116 ) ;
return V_35 ;
}
static T_4
F_102 ( struct V_18 * V_19 , struct V_149 * V_43 , char * V_150 )
{
struct V_52 * V_53 = F_50 ( V_19 ) ;
struct V_26 * V_151 = F_59 ( V_43 ) ;
return sprintf ( V_150 , L_4 , V_53 -> V_104 [ V_151 -> V_48 ] * 1000 ) ;
}
static T_4
F_103 ( struct V_18 * V_19 , struct V_149 * V_43 ,
const char * V_150 , T_5 V_35 )
{
struct V_52 * V_53 = F_46 ( V_19 ) ;
struct V_26 * V_151 = F_59 ( V_43 ) ;
int V_15 = V_151 -> V_48 ;
unsigned long V_3 ;
int V_152 ;
V_152 = F_57 ( V_150 , 10 , & V_3 ) ;
if ( V_152 < 0 )
return V_152 ;
V_3 = F_14 ( F_22 ( V_3 , 1000 ) , 0 ,
V_53 -> V_106 ) ;
F_51 ( & V_53 -> V_116 ) ;
V_53 -> V_104 [ V_15 ] = V_3 ;
F_93 ( V_53 , V_15 ) ;
F_53 ( & V_53 -> V_116 ) ;
return V_35 ;
}
static T_4
F_104 ( struct V_18 * V_19 , struct V_149 * V_43 , char * V_150 )
{
struct V_52 * V_53 = F_50 ( V_19 ) ;
struct V_26 * V_151 = F_59 ( V_43 ) ;
int V_15 = V_151 -> V_48 ;
return sprintf ( V_150 , L_4 ,
F_17 ( V_53 -> V_107 [ V_15 ] ,
V_53 -> V_72 [ V_15 ] ) ) ;
}
static T_4
F_105 ( struct V_18 * V_19 , struct V_149 * V_43 ,
const char * V_150 , T_5 V_35 )
{
struct V_52 * V_53 = F_46 ( V_19 ) ;
struct V_26 * V_151 = F_59 ( V_43 ) ;
int V_15 = V_151 -> V_48 ;
unsigned long V_3 ;
int V_152 ;
T_2 V_190 ;
V_152 = F_57 ( V_150 , 10 , & V_3 ) ;
if ( V_152 < 0 )
return V_152 ;
V_3 = F_14 ( V_3 , 0 , 1350000U ) ;
V_190 = F_18 ( V_3 , V_53 -> V_72 [ V_15 ] ) ;
F_51 ( & V_53 -> V_116 ) ;
V_53 -> V_107 [ V_15 ] = V_190 ;
F_93 ( V_53 , V_15 ) ;
F_53 ( & V_53 -> V_116 ) ;
return V_35 ;
}
static T_4
F_106 ( struct V_18 * V_19 , struct V_149 * V_43 ,
char * V_150 )
{
struct V_52 * V_53 = F_50 ( V_19 ) ;
struct V_28 * V_151 = F_55 ( V_43 ) ;
int V_15 = V_151 -> V_15 ;
int V_48 = V_151 -> V_48 ;
return sprintf ( V_150 , L_4 , V_53 -> V_89 [ V_48 ] [ V_15 ] * 1000 ) ;
}
static T_4
F_107 ( struct V_18 * V_19 , struct V_149 * V_43 ,
const char * V_150 , T_5 V_35 )
{
struct V_52 * V_53 = F_46 ( V_19 ) ;
struct V_28 * V_151 = F_55 ( V_43 ) ;
int V_15 = V_151 -> V_15 ;
int V_48 = V_151 -> V_48 ;
unsigned long V_3 ;
int V_152 ;
V_152 = F_57 ( V_150 , 10 , & V_3 ) ;
if ( V_152 < 0 )
return V_152 ;
V_3 = F_14 ( F_22 ( V_3 , 1000 ) , 0 , V_53 -> V_186 ) ;
F_51 ( & V_53 -> V_116 ) ;
V_53 -> V_89 [ V_48 ] [ V_15 ] = V_3 ;
if ( V_48 )
F_93 ( V_53 , V_15 ) ;
else
F_33 ( V_53 ,
V_53 -> V_93 [ V_15 ] ,
V_3 ) ;
F_53 ( & V_53 -> V_116 ) ;
return V_35 ;
}
static T_4
F_108 ( struct V_18 * V_19 , struct V_149 * V_43 ,
char * V_150 )
{
struct V_52 * V_53 = F_50 ( V_19 ) ;
struct V_26 * V_151 = F_59 ( V_43 ) ;
int V_15 = V_151 -> V_48 ;
int V_191 = V_53 -> V_107 [ V_15 ] - V_53 -> V_91 [ V_15 ] ;
int V_192 = V_53 -> V_107 [ V_15 ] + V_53 -> V_91 [ V_15 ] ;
int V_193 ;
if ( V_191 <= 0 )
V_191 = 1 ;
if ( V_192 > 0xffff )
V_192 = 0xffff ;
if ( V_192 < V_191 )
V_192 = V_191 ;
V_193 = ( F_17 ( V_191 , V_53 -> V_72 [ V_15 ] )
- F_17 ( V_192 , V_53 -> V_72 [ V_15 ] ) ) / 2 ;
return sprintf ( V_150 , L_4 , V_193 ) ;
}
static T_4
F_109 ( struct V_18 * V_19 , struct V_149 * V_43 ,
const char * V_150 , T_5 V_35 )
{
struct V_52 * V_53 = F_46 ( V_19 ) ;
struct V_26 * V_151 = F_59 ( V_43 ) ;
int V_15 = V_151 -> V_48 ;
unsigned long V_3 ;
int V_152 ;
int V_191 , V_192 ;
V_152 = F_57 ( V_150 , 10 , & V_3 ) ;
if ( V_152 < 0 )
return V_152 ;
V_192 = F_17 ( V_53 -> V_107 [ V_15 ] ,
V_53 -> V_72 [ V_15 ] ) + V_3 ;
V_191 = F_17 ( V_53 -> V_107 [ V_15 ] ,
V_53 -> V_72 [ V_15 ] ) - V_3 ;
if ( V_191 <= 0 )
V_191 = 1 ;
if ( V_192 < V_191 )
V_192 = V_191 ;
V_3 = ( F_18 ( V_191 , V_53 -> V_72 [ V_15 ] ) -
F_18 ( V_192 , V_53 -> V_72 [ V_15 ] ) ) / 2 ;
V_3 = F_14 ( V_3 , 0 , V_53 -> V_194 ) ;
F_51 ( & V_53 -> V_116 ) ;
V_53 -> V_91 [ V_15 ] = V_3 ;
F_93 ( V_53 , V_15 ) ;
F_53 ( & V_53 -> V_116 ) ;
return V_35 ;
}
static T_4
F_110 ( struct V_18 * V_19 , struct V_149 * V_43 , char * V_150 )
{
struct V_52 * V_53 = F_50 ( V_19 ) ;
struct V_28 * V_151 = F_55 ( V_43 ) ;
int V_15 = V_151 -> V_15 ;
int V_48 = V_151 -> V_48 ;
return sprintf ( V_150 , L_4 , V_53 -> V_98 [ V_48 ] [ V_15 ] * 1000 ) ;
}
static T_4
F_111 ( struct V_18 * V_19 , struct V_149 * V_43 ,
const char * V_150 , T_5 V_35 )
{
struct V_52 * V_53 = F_46 ( V_19 ) ;
struct V_28 * V_151 = F_55 ( V_43 ) ;
int V_15 = V_151 -> V_15 ;
int V_48 = V_151 -> V_48 ;
unsigned long V_3 ;
int V_152 ;
V_152 = F_57 ( V_150 , 10 , & V_3 ) ;
if ( V_152 < 0 )
return V_152 ;
V_3 = F_14 ( F_22 ( V_3 , 1000 ) , 0 , 255 ) ;
F_51 ( & V_53 -> V_116 ) ;
V_53 -> V_98 [ V_48 ] [ V_15 ] = V_3 ;
F_33 ( V_53 , V_53 -> V_99 [ V_48 ] [ V_15 ] , V_3 ) ;
F_53 ( & V_53 -> V_116 ) ;
return V_35 ;
}
static T_4
F_112 ( struct V_18 * V_19 , struct V_149 * V_43 , char * V_150 )
{
struct V_52 * V_53 = F_50 ( V_19 ) ;
struct V_28 * V_151 = F_55 ( V_43 ) ;
int V_15 = V_151 -> V_15 ;
int V_48 = V_151 -> V_48 ;
return sprintf ( V_150 , L_4 ,
F_12 ( V_53 -> V_101 [ V_48 ] [ V_15 ] ,
V_53 -> V_86 [ V_15 ] ) ) ;
}
static T_4
F_113 ( struct V_18 * V_19 , struct V_149 * V_43 ,
const char * V_150 , T_5 V_35 )
{
struct V_52 * V_53 = F_46 ( V_19 ) ;
struct V_28 * V_151 = F_55 ( V_43 ) ;
int V_15 = V_151 -> V_15 ;
int V_48 = V_151 -> V_48 ;
unsigned long V_3 ;
int V_152 ;
V_152 = F_57 ( V_150 , 10 , & V_3 ) ;
if ( V_152 < 0 )
return V_152 ;
V_3 = F_13 ( V_3 , V_53 -> V_86 [ V_15 ] ) ;
F_51 ( & V_53 -> V_116 ) ;
V_53 -> V_101 [ V_48 ] [ V_15 ] = V_3 ;
F_33 ( V_53 , V_53 -> V_102 [ V_48 ] [ V_15 ] , V_3 ) ;
F_53 ( & V_53 -> V_116 ) ;
return V_35 ;
}
static T_4
F_114 ( struct V_18 * V_19 , struct V_149 * V_43 , char * V_150 )
{
struct V_52 * V_53 = F_50 ( V_19 ) ;
struct V_28 * V_151 = F_55 ( V_43 ) ;
return sprintf ( V_150 , L_4 , V_53 -> V_109 [ V_151 -> V_15 ] [ V_151 -> V_48 ] ) ;
}
static T_4
F_115 ( struct V_18 * V_19 , struct V_149 * V_43 ,
const char * V_150 , T_5 V_35 )
{
struct V_52 * V_53 = F_46 ( V_19 ) ;
struct V_28 * V_151 = F_55 ( V_43 ) ;
int V_15 = V_151 -> V_15 ;
int V_195 = V_151 -> V_48 ;
unsigned long V_3 ;
int V_152 ;
T_1 V_2 ;
V_152 = F_57 ( V_150 , 10 , & V_3 ) ;
if ( V_152 < 0 )
return V_152 ;
if ( V_3 > 255 )
return - V_36 ;
if ( V_195 == V_53 -> V_108 ) {
if ( V_53 -> V_54 != V_56 && ! V_3 )
return - V_36 ;
if ( V_53 -> V_54 != V_58 && V_3 )
V_3 = 0xff ;
}
F_51 ( & V_53 -> V_116 ) ;
V_53 -> V_109 [ V_15 ] [ V_195 ] = V_3 ;
if ( V_195 < V_53 -> V_108 ) {
F_33 ( V_53 ,
F_48 ( V_53 , V_15 , V_195 ) ,
V_53 -> V_109 [ V_15 ] [ V_195 ] ) ;
} else {
switch ( V_53 -> V_54 ) {
case V_56 :
V_2 = F_31 ( V_53 ,
V_112 [ V_15 ] ) ;
if ( V_3 )
V_2 |= 0x02 ;
else
V_2 &= ~ 0x02 ;
F_33 ( V_53 , V_112 [ V_15 ] ,
V_2 ) ;
break;
case V_57 :
break;
case V_55 :
case V_58 :
case V_59 :
case V_60 :
case V_61 :
case V_62 :
F_33 ( V_53 , V_53 -> V_115 [ V_15 ] ,
V_3 ) ;
V_2 = F_31 ( V_53 ,
V_53 -> V_113 [ V_15 ] ) ;
if ( V_3 == 255 )
V_2 &= ~ V_53 -> V_114 ;
else
V_2 |= V_53 -> V_114 ;
F_33 ( V_53 ,
V_53 -> V_113 [ V_15 ] ,
V_2 ) ;
break;
}
}
F_53 ( & V_53 -> V_116 ) ;
return V_35 ;
}
static T_4
F_116 ( struct V_18 * V_19 , struct V_149 * V_43 , char * V_150 )
{
struct V_52 * V_53 = F_50 ( V_19 ) ;
struct V_28 * V_151 = F_55 ( V_43 ) ;
int V_15 = V_151 -> V_15 ;
int V_195 = V_151 -> V_48 ;
return sprintf ( V_150 , L_4 , V_53 -> V_110 [ V_15 ] [ V_195 ] * 1000 ) ;
}
static T_4
F_117 ( struct V_18 * V_19 , struct V_149 * V_43 ,
const char * V_150 , T_5 V_35 )
{
struct V_52 * V_53 = F_46 ( V_19 ) ;
struct V_28 * V_151 = F_55 ( V_43 ) ;
int V_15 = V_151 -> V_15 ;
int V_195 = V_151 -> V_48 ;
unsigned long V_3 ;
int V_152 ;
V_152 = F_57 ( V_150 , 10 , & V_3 ) ;
if ( V_152 )
return V_152 ;
if ( V_3 > 255000 )
return - V_36 ;
F_51 ( & V_53 -> V_116 ) ;
V_53 -> V_110 [ V_15 ] [ V_195 ] = F_22 ( V_3 , 1000 ) ;
if ( V_195 < V_53 -> V_108 ) {
F_33 ( V_53 ,
F_49 ( V_53 , V_15 , V_195 ) ,
V_53 -> V_110 [ V_15 ] [ V_195 ] ) ;
} else {
F_33 ( V_53 , V_53 -> V_111 [ V_15 ] ,
V_53 -> V_110 [ V_15 ] [ V_195 ] ) ;
}
F_53 ( & V_53 -> V_116 ) ;
return V_35 ;
}
static T_6 F_118 ( struct V_165 * V_166 ,
struct V_30 * V_43 , int V_48 )
{
struct V_18 * V_19 = F_67 ( V_166 , struct V_18 , V_166 ) ;
struct V_52 * V_53 = F_46 ( V_19 ) ;
int V_9 = V_48 / 36 ;
int V_15 = V_48 % 36 ;
if ( ! ( V_53 -> V_83 & F_20 ( V_9 ) ) )
return 0 ;
if ( ( V_15 >= 14 && V_15 <= 18 ) || V_15 == 21 )
if ( ! V_53 -> V_96 [ V_9 ] )
return 0 ;
if ( V_15 == 19 && V_53 -> V_88 [ 3 ] == NULL )
return 0 ;
if ( V_15 == 20 && V_53 -> V_88 [ 4 ] == NULL )
return 0 ;
if ( V_15 == 21 && V_53 -> V_88 [ 6 ] == NULL )
return 0 ;
if ( V_15 >= 22 && V_15 <= 35 ) {
int V_196 = ( V_15 - 22 ) / 2 ;
if ( V_196 > V_53 -> V_108 )
return 0 ;
}
return V_43 -> V_10 ;
}
static T_4
F_119 ( struct V_18 * V_19 , struct V_149 * V_43 , char * V_150 )
{
struct V_52 * V_53 = F_46 ( V_19 ) ;
return sprintf ( V_150 , L_4 , F_120 ( V_53 -> V_197 , V_53 -> V_198 ) ) ;
}
static T_4
F_121 ( struct V_18 * V_19 , struct V_149 * V_43 ,
const char * V_150 , T_5 V_35 )
{
struct V_52 * V_53 = F_46 ( V_19 ) ;
int V_15 = F_59 ( V_43 ) -> V_48 - V_199 ;
unsigned long V_3 ;
T_1 V_2 ;
int V_200 ;
if ( F_57 ( V_150 , 10 , & V_3 ) || V_3 != 0 )
return - V_36 ;
F_51 ( & V_53 -> V_116 ) ;
V_200 = F_6 ( V_53 -> V_201 ) ;
if ( V_200 ) {
V_35 = V_200 ;
goto error;
}
F_5 ( V_53 -> V_201 , V_202 ) ;
V_2 = F_3 ( V_53 -> V_201 , V_203 [ V_15 ] ) ;
V_2 |= V_204 [ V_15 ] ;
F_1 ( V_53 -> V_201 , V_203 [ V_15 ] , V_2 ) ;
V_2 &= ~ V_204 [ V_15 ] ;
F_1 ( V_53 -> V_201 , V_203 [ V_15 ] , V_2 ) ;
F_8 ( V_53 -> V_201 ) ;
V_53 -> V_120 = false ;
error:
F_53 ( & V_53 -> V_116 ) ;
return V_35 ;
}
static T_6 F_122 ( struct V_165 * V_166 ,
struct V_30 * V_43 , int V_48 )
{
struct V_18 * V_19 = F_67 ( V_166 , struct V_18 , V_166 ) ;
struct V_52 * V_53 = F_46 ( V_19 ) ;
if ( V_48 == 0 && ! V_53 -> V_205 )
return 0 ;
if ( V_48 == 1 || V_48 == 2 ) {
if ( V_53 -> V_153 [ V_199 + V_48 - 1 ] < 0 )
return 0 ;
}
if ( V_48 == 3 || V_48 == 4 ) {
if ( V_53 -> V_162 [ V_199 + V_48 - 3 ] < 0 )
return 0 ;
}
return V_43 -> V_10 ;
}
static inline void F_123 ( struct V_52 * V_53 )
{
int V_34 ;
T_1 V_206 , V_176 ;
if ( V_53 -> V_207 ) {
V_206 = F_31 ( V_53 , V_53 -> V_207 ) ;
if ( ! ( V_206 & 0x01 ) )
F_33 ( V_53 , V_53 -> V_207 , V_206 | 0x01 ) ;
}
for ( V_34 = 0 ; V_34 < V_132 ; V_34 ++ ) {
if ( ! ( V_53 -> V_133 & F_20 ( V_34 ) ) )
continue;
if ( ! V_53 -> V_208 [ V_34 ] )
continue;
V_206 = F_31 ( V_53 , V_53 -> V_208 [ V_34 ] ) ;
if ( V_206 & 0x01 )
F_33 ( V_53 , V_53 -> V_208 [ V_34 ] ,
V_206 & 0xfe ) ;
}
V_206 = F_31 ( V_53 , V_53 -> V_180 ) ;
if ( ! ( V_206 & 0x01 ) )
F_33 ( V_53 , V_53 -> V_180 , V_206 | 0x01 ) ;
V_176 = F_31 ( V_53 , V_53 -> V_181 ) ;
for ( V_34 = 0 ; V_34 < V_53 -> V_209 ; V_34 ++ ) {
if ( ! ( V_53 -> V_137 & F_20 ( V_34 ) ) )
continue;
if ( ( V_206 & ( V_53 -> V_179 << V_34 ) ) )
V_53 -> V_174 [ V_34 ]
= 3 - ( ( V_176 >> V_34 ) & V_53 -> V_179 ) ;
else
V_53 -> V_174 [ V_34 ] = 4 ;
}
}
static void
F_124 ( struct V_52 * V_53 )
{
bool V_210 , V_211 , V_212 , V_213 , V_214 ;
bool V_215 , V_216 , V_217 , V_218 ;
int V_201 = V_53 -> V_201 ;
int V_219 ;
F_5 ( V_201 , V_220 ) ;
V_53 -> V_221 = F_3 ( V_201 , V_222 ) ;
if ( V_53 -> V_54 == V_56 ) {
V_219 = F_3 ( V_201 , 0x2c ) ;
V_210 = V_219 & F_20 ( 6 ) ;
V_215 = V_219 & F_20 ( 7 ) ;
V_211 = ! ( F_3 ( V_201 , 0x2A ) & 0x80 ) ;
V_212 = false ;
V_213 = false ;
V_214 = false ;
V_216 = false ;
V_217 = false ;
V_218 = false ;
} else if ( V_53 -> V_54 == V_57 ) {
bool V_223 = F_3 ( V_201 , 0x27 ) & 0x80 ;
const char * V_224 , * V_225 ;
V_224 = F_125 ( V_226 ) ;
V_225 = F_125 ( V_227 ) ;
if ( V_225 && V_224 &&
! strcmp ( V_224 , L_12 ) ) {
if ( ! strcmp ( V_225 , L_13 ) ) {
if ( ( V_53 -> V_221 & 0xe0 ) != 0xe0 ) {
V_53 -> V_221 |= 0xe0 ;
F_1 ( V_201 , V_222 ,
V_53 -> V_221 ) ;
}
}
}
if ( V_53 -> V_221 & 0x80 )
V_210 = V_223 ;
else
V_210 = ! ( F_3 ( V_201 , 0x24 ) & 0x40 ) ;
if ( V_53 -> V_221 & 0x40 )
V_211 = V_223 ;
else
V_211 = F_3 ( V_201 , 0x1C ) & 0x01 ;
if ( V_53 -> V_221 & 0x20 )
V_213 = V_223 ;
else
V_213 = F_3 ( V_201 , 0x1C ) & 0x02 ;
V_212 = V_211 ;
V_214 = false ;
V_215 = V_210 ;
V_216 = false ;
V_217 = false ;
V_218 = false ;
} else if ( V_53 -> V_54 == V_55 ) {
V_219 = F_3 ( V_201 , 0x24 ) ;
V_210 = ! ( V_219 & 0x80 ) ;
V_215 = V_219 & 0x08 ;
V_211 = false ;
V_212 = false ;
V_213 = false ;
V_214 = false ;
V_216 = false ;
V_217 = false ;
V_218 = false ;
} else {
int V_228 , V_229 , V_230 ;
V_219 = F_3 ( V_201 , 0x1c ) ;
V_210 = ! ( V_219 & F_20 ( 5 ) ) ;
V_211 = ! ( V_219 & F_20 ( 6 ) ) ;
V_213 = ! ( V_219 & F_20 ( 7 ) ) ;
V_215 = ! ( V_219 & F_20 ( 0 ) ) ;
V_216 = ! ( V_219 & F_20 ( 1 ) ) ;
V_217 = ! ( V_219 & F_20 ( 2 ) ) ;
V_219 = F_3 ( V_201 , 0x2d ) ;
switch ( V_53 -> V_54 ) {
case V_59 :
case V_60 :
V_214 = V_219 & F_20 ( 1 ) ;
V_218 = V_219 & F_20 ( 0 ) ;
break;
case V_61 :
case V_62 :
V_228 = F_3 ( V_201 , 0x1b ) ;
V_229 = F_3 ( V_201 , 0x2a ) ;
if ( ! V_217 )
V_217 = V_219 & F_20 ( 7 ) ;
V_214 = V_219 & F_20 ( 1 ) ;
V_218 = V_219 & F_20 ( 0 ) ;
if ( ! V_213 )
V_213 = V_228 & F_20 ( 5 ) ;
F_5 ( V_201 , V_231 ) ;
V_230 = F_3 ( V_201 , 0xeb ) ;
if ( ! V_213 )
V_213 = V_230 & F_20 ( 5 ) ;
if ( ! V_217 )
V_217 = ( V_230 & F_20 ( 4 ) ) &&
! ( V_229 & F_20 ( 0 ) ) ;
if ( ! V_214 )
V_214 = V_230 & F_20 ( 3 ) ;
if ( ! V_218 )
V_218 = V_230 & F_20 ( 2 ) ;
break;
default:
V_214 = false ;
V_218 = false ;
break;
}
V_212 = V_211 ;
}
V_53 -> V_74 = 0x03 | ( V_210 << 2 ) | ( V_211 << 3 ) |
( V_213 << 4 ) | ( V_214 << 5 ) ;
V_53 -> V_77 = 0x03 | ( V_210 << 2 ) | ( V_212 << 3 ) |
( V_213 << 4 ) ;
V_53 -> V_83 = 0x03 | ( V_215 << 2 ) | ( V_216 << 3 ) |
( V_217 << 4 ) | ( V_218 << 5 ) ;
}
static void F_126 ( struct V_52 * V_53 , const T_2 * V_232 ,
int * V_233 , int * V_234 )
{
int V_34 ;
T_1 V_156 ;
for ( V_34 = 0 ; V_34 < V_53 -> V_82 && * V_233 ; V_34 ++ ) {
int V_48 ;
if ( ! V_232 [ V_34 ] )
continue;
V_156 = F_31 ( V_53 , V_232 [ V_34 ] ) ;
V_156 &= 0x1f ;
if ( ! V_156 || ( * V_234 & F_20 ( V_156 ) ) )
continue;
if ( ! ( V_53 -> V_235 & F_20 ( V_156 ) ) )
continue;
V_48 = F_127 ( * V_233 ) ;
F_33 ( V_53 , V_53 -> V_157 [ V_48 ] , V_156 ) ;
* V_233 &= ~ F_20 ( V_48 ) ;
* V_234 |= F_20 ( V_156 ) ;
}
}
static int F_128 ( struct V_236 * V_237 )
{
struct V_18 * V_19 = & V_237 -> V_19 ;
struct V_238 * V_239 = F_129 ( V_19 ) ;
struct V_52 * V_53 ;
struct V_240 * V_68 ;
int V_34 , V_47 , V_152 = 0 ;
int V_156 , V_234 , V_233 ;
const T_2 * V_134 , * V_241 , * V_242 , * V_208 ;
const T_2 * V_243 , * V_244 , * V_245 ;
const T_2 * V_246 = NULL , * V_247 = NULL ;
int V_248 , V_249 ;
T_1 V_250 ;
struct V_17 * V_23 ;
struct V_18 * V_251 ;
int V_252 = 0 ;
V_68 = F_130 ( V_237 , V_253 , 0 ) ;
if ( ! F_131 ( & V_237 -> V_19 , V_68 -> V_254 , V_255 ,
V_6 ) )
return - V_7 ;
V_53 = F_26 ( & V_237 -> V_19 , sizeof( struct V_52 ) ,
V_38 ) ;
if ( ! V_53 )
return - V_39 ;
V_53 -> V_54 = V_239 -> V_54 ;
V_53 -> V_201 = V_239 -> V_201 ;
V_53 -> V_65 = V_68 -> V_254 ;
F_132 ( & V_53 -> V_116 ) ;
V_53 -> V_41 = V_256 [ V_53 -> V_54 ] ;
V_53 -> V_63 = 0xff ;
F_133 ( V_237 , V_53 ) ;
switch ( V_53 -> V_54 ) {
case V_55 :
V_53 -> V_121 = 9 ;
V_53 -> V_82 = 3 ;
V_53 -> V_108 = 4 ;
V_53 -> V_209 = 3 ;
V_53 -> V_159 = 6 ;
V_53 -> V_164 = 6 ;
V_53 -> V_128 = F_16 ;
V_53 -> V_167 = F_16 ;
V_53 -> V_173 = V_257 ;
V_53 -> V_235 = V_258 ;
V_53 -> V_180 = V_259 ;
V_53 -> V_181 = V_260 ;
V_53 -> V_179 = V_261 ;
V_53 -> V_124 = V_262 ;
V_53 -> V_125 [ 0 ] = V_263 ;
V_53 -> V_125 [ 1 ] = V_264 ;
V_53 -> V_103 = V_265 ;
V_53 -> V_127 = V_266 ;
V_53 -> V_87 = V_267 ;
V_53 -> V_78 = V_268 ;
V_53 -> V_130 = V_269 ;
V_53 -> V_131 = V_270 ;
V_53 -> V_102 [ 0 ] = V_271 ;
V_53 -> V_102 [ 1 ] = V_272 ;
V_53 -> V_102 [ 2 ] = V_273 ;
V_53 -> V_88 [ 0 ] = V_274 ;
V_53 -> V_88 [ 1 ] = V_275 ;
V_53 -> V_88 [ 2 ] = V_276 ;
V_53 -> V_88 [ 5 ] = V_277 ;
V_53 -> V_88 [ 6 ] = V_278 ;
V_53 -> V_183 = V_279 ;
V_53 -> V_84 = V_280 ;
V_53 -> V_85 = V_281 ;
V_53 -> V_282 = V_283 ;
V_53 -> V_284 = V_285 ;
V_53 -> V_111 = V_286 ;
V_53 -> V_93
= V_287 ;
V_53 -> V_113 = V_288 ;
V_53 -> V_114
= V_289 ;
V_53 -> V_115 = V_290 ;
V_53 -> V_139 = V_291 ;
V_53 -> V_157 = V_292 ;
V_53 -> V_94 = V_293 ;
V_53 -> V_96 = V_294 ;
V_53 -> V_99 [ 0 ] = V_295 ;
V_53 -> V_99 [ 1 ] = V_296 ;
V_53 -> V_99 [ 2 ] = V_297 ;
V_53 -> V_143 = V_298 ;
V_53 -> V_153 = V_299 ;
V_53 -> V_148 = V_300 ;
V_53 -> V_162 = V_301 ;
V_134 = V_302 ;
V_243 = V_303 ;
V_248 = F_41 ( V_302 ) ;
V_249 = F_41 ( V_303 ) ;
V_241 = V_304 ;
V_242 = V_305 ;
V_208 = V_306 ;
V_244 = V_307 ;
V_245 = V_308 ;
V_246 = V_309 ;
V_247 = V_310 ;
break;
case V_56 :
V_53 -> V_121 = 9 ;
V_53 -> V_82 = 3 ;
V_53 -> V_108 = 6 ;
V_53 -> V_75 = true ;
V_53 -> V_209 = 3 ;
V_53 -> V_159 = 3 ;
V_53 -> V_164 = 3 ;
V_53 -> V_153 = V_311 ;
V_53 -> V_162 = V_312 ;
V_53 -> V_128 = F_17 ;
V_53 -> V_167 = F_15 ;
V_53 -> V_106 = 0x7f ;
V_53 -> V_186 = 0x0f ;
V_53 -> V_194 = 15 ;
V_53 -> V_173 = V_313 ;
V_53 -> V_235 = V_314 ;
V_53 -> V_207 = V_315 ;
V_53 -> V_180 = V_316 ;
V_53 -> V_181 = V_317 ;
V_53 -> V_179 = V_318 ;
V_53 -> V_124 = V_319 ;
V_53 -> V_125 [ 0 ] = V_320 ;
V_53 -> V_125 [ 1 ] = V_321 ;
V_53 -> V_103 = V_322 ;
V_53 -> V_127 = V_323 ;
V_53 -> V_87 = V_324 ;
V_53 -> V_78 = V_325 ;
V_53 -> V_130 = V_326 ;
V_53 -> V_131 = V_327 ;
V_53 -> V_102 [ 0 ] = V_328 ;
V_53 -> V_102 [ 1 ] = V_329 ;
V_53 -> V_102 [ 2 ] = V_330 ;
V_53 -> V_88 [ 0 ] = V_331 ;
V_53 -> V_88 [ 1 ] = V_332 ;
V_53 -> V_88 [ 2 ] = V_333 ;
V_53 -> V_88 [ 3 ] = V_334 ;
V_53 -> V_88 [ 4 ] = V_335 ;
V_53 -> V_88 [ 5 ] = V_336 ;
V_53 -> V_183 = V_337 ;
V_53 -> V_84 = V_338 ;
V_53 -> V_85 = V_339 ;
V_53 -> V_282 = V_340 ;
V_53 -> V_284 = V_341 ;
V_53 -> V_111 = V_342 ;
V_53 -> V_93
= V_343 ;
V_53 -> V_139 = V_344 ;
V_53 -> V_157 = V_345 ;
V_53 -> V_94 = V_346 ;
V_53 -> V_96 = V_347 ;
V_53 -> V_99 [ 0 ] = V_348 ;
V_53 -> V_99 [ 1 ] = V_349 ;
V_53 -> V_99 [ 2 ] = V_350 ;
V_53 -> V_143 = V_351 ;
V_53 -> V_148 = V_352 ;
V_134 = V_353 ;
V_243 = V_354 ;
V_248 = F_41 ( V_353 ) ;
V_249 = F_41 ( V_354 ) ;
V_241 = V_355 ;
V_242 = V_356 ;
V_208 = V_357 ;
V_244 = V_358 ;
V_245 = V_359 ;
break;
case V_57 :
V_53 -> V_121 = 9 ;
V_53 -> V_82 = 3 ;
V_53 -> V_108 = 4 ;
V_53 -> V_75 = false ;
V_53 -> V_209 = 3 ;
V_53 -> V_159 = 3 ;
V_53 -> V_164 = 6 ;
V_53 -> V_153 = V_360 ;
V_53 -> V_162 = V_361 ;
V_53 -> V_128 = F_16 ;
V_53 -> V_167 = F_16 ;
V_53 -> V_106 = 0xff ;
V_53 -> V_186 = 0x07 ;
V_53 -> V_194 = 63 ;
V_53 -> V_173 = V_257 ;
V_53 -> V_235 = V_258 ;
V_53 -> V_207 = V_315 ;
V_53 -> V_180 = V_316 ;
V_53 -> V_181 = V_317 ;
V_53 -> V_179 = V_318 ;
V_53 -> V_124 = V_319 ;
V_53 -> V_125 [ 0 ] = V_320 ;
V_53 -> V_125 [ 1 ] = V_321 ;
V_53 -> V_103 = V_322 ;
V_53 -> V_127 = V_323 ;
V_53 -> V_87 = V_324 ;
V_53 -> V_78 = V_362 ;
V_53 -> V_130 = V_363 ;
V_53 -> V_131 = V_327 ;
V_53 -> V_102 [ 0 ] = V_328 ;
V_53 -> V_102 [ 1 ] = V_364 ;
V_53 -> V_102 [ 2 ] = V_365 ;
V_53 -> V_92 = V_366 ;
V_53 -> V_88 [ 0 ] = V_331 ;
V_53 -> V_88 [ 1 ] = V_332 ;
V_53 -> V_88 [ 2 ] = V_333 ;
V_53 -> V_88 [ 5 ] = V_336 ;
V_53 -> V_88 [ 6 ] = V_367 ;
V_53 -> V_183 = V_337 ;
V_53 -> V_84 = V_368 ;
V_53 -> V_85 = V_369 ;
V_53 -> V_282 = V_340 ;
V_53 -> V_284 = V_341 ;
V_53 -> V_111 = V_342 ;
V_53 -> V_93
= V_343 ;
V_53 -> V_139 = V_344 ;
V_53 -> V_157 = V_345 ;
V_53 -> V_94 = V_346 ;
V_53 -> V_96 = V_347 ;
V_53 -> V_99 [ 0 ] = V_348 ;
V_53 -> V_99 [ 1 ] = V_349 ;
V_53 -> V_99 [ 2 ] = V_350 ;
V_53 -> V_143 = V_351 ;
V_53 -> V_148 = V_370 ;
V_134 = V_353 ;
V_243 = V_354 ;
V_248 = F_41 ( V_353 ) ;
V_249 = F_41 ( V_354 ) ;
V_241 = V_355 ;
V_242 = V_356 ;
V_208 = V_371 ;
V_244 = V_372 ;
V_245 = V_373 ;
break;
case V_58 :
V_53 -> V_121 = 15 ;
V_53 -> V_82 = 5 ;
V_53 -> V_108 = 4 ;
V_53 -> V_75 = false ;
V_53 -> V_209 = 6 ;
V_53 -> V_159 = 2 ;
V_53 -> V_164 = 2 ;
V_53 -> V_153 = V_374 ;
V_53 -> V_162 = V_375 ;
V_53 -> V_128 = F_16 ;
V_53 -> V_167 = F_16 ;
V_53 -> V_106 = 0xff ;
V_53 -> V_186 = 0x07 ;
V_53 -> V_194 = 63 ;
V_53 -> V_173 = V_376 ;
V_53 -> V_235 = V_377 ;
V_53 -> V_207 = V_315 ;
V_53 -> V_180 = V_316 ;
V_53 -> V_181 = V_317 ;
V_53 -> V_179 = V_318 ;
V_53 -> V_124 = V_378 ;
V_53 -> V_125 [ 0 ] = V_320 ;
V_53 -> V_125 [ 1 ] = V_321 ;
V_53 -> V_103 = V_322 ;
V_53 -> V_127 = V_379 ;
V_53 -> V_87 = V_324 ;
V_53 -> V_78 = V_362 ;
V_53 -> V_130 = V_380 ;
V_53 -> V_131 = V_327 ;
V_53 -> V_102 [ 0 ] = V_328 ;
V_53 -> V_102 [ 1 ] = V_364 ;
V_53 -> V_102 [ 2 ] = V_365 ;
V_53 -> V_92 = V_366 ;
V_53 -> V_88 [ 0 ] = V_331 ;
V_53 -> V_88 [ 1 ] = V_332 ;
V_53 -> V_88 [ 2 ] = V_333 ;
V_53 -> V_88 [ 5 ] = V_336 ;
V_53 -> V_88 [ 6 ] = V_367 ;
V_53 -> V_183 = V_337 ;
V_53 -> V_84 = V_368 ;
V_53 -> V_85 = V_369 ;
V_53 -> V_282 = V_340 ;
V_53 -> V_284 = V_341 ;
V_53 -> V_111 = V_342 ;
V_53 -> V_93
= V_343 ;
V_53 -> V_113 = V_381 ;
V_53 -> V_114
= V_382 ;
V_53 -> V_115 = V_383 ;
V_53 -> V_139 = V_384 ;
V_53 -> V_157 = V_345 ;
V_53 -> V_94 = V_346 ;
V_53 -> V_96 = V_347 ;
V_53 -> V_99 [ 0 ] = V_348 ;
V_53 -> V_99 [ 1 ] = V_349 ;
V_53 -> V_99 [ 2 ] = V_350 ;
V_53 -> V_143 = V_385 ;
V_53 -> V_148 = V_370 ;
V_134 = V_386 ;
V_243 = V_387 ;
V_248 = F_41 ( V_386 ) ;
V_249 = F_41 ( V_387 ) ;
V_241 = V_388 ;
V_242 = V_389 ;
V_208 = V_390 ;
V_244 = V_391 ;
V_245 = V_392 ;
break;
case V_59 :
case V_60 :
case V_61 :
case V_62 :
V_53 -> V_121 = 15 ;
V_53 -> V_82 = 6 ;
V_53 -> V_108 = 4 ;
V_53 -> V_75 = false ;
V_53 -> V_209 = 6 ;
V_53 -> V_159 = 2 ;
V_53 -> V_164 = 2 ;
V_53 -> V_153 = V_393 ;
V_53 -> V_162 = V_375 ;
V_53 -> V_128 = F_16 ;
V_53 -> V_167 = F_16 ;
V_53 -> V_106 = 0xff ;
V_53 -> V_186 = 0x07 ;
V_53 -> V_194 = 63 ;
switch ( V_53 -> V_54 ) {
default:
case V_59 :
V_53 -> V_173 = V_376 ;
V_53 -> V_235 = V_394 ;
break;
case V_60 :
V_53 -> V_173 = V_395 ;
V_53 -> V_235 = V_396 ;
break;
case V_61 :
V_53 -> V_173 = V_397 ;
V_53 -> V_235 = V_398 ;
break;
case V_62 :
V_53 -> V_173 = V_399 ;
V_53 -> V_235 = V_400 ;
break;
}
V_53 -> V_207 = V_315 ;
V_53 -> V_180 = V_316 ;
V_53 -> V_181 = V_317 ;
V_53 -> V_179 = V_318 ;
V_53 -> V_124 = V_378 ;
V_53 -> V_125 [ 0 ] = V_320 ;
V_53 -> V_125 [ 1 ] = V_321 ;
V_53 -> V_103 = V_322 ;
V_53 -> V_127 = V_379 ;
V_53 -> V_87 = V_324 ;
V_53 -> V_78 = V_362 ;
V_53 -> V_130 = V_380 ;
V_53 -> V_131 = V_327 ;
V_53 -> V_102 [ 0 ] = V_328 ;
V_53 -> V_102 [ 1 ] = V_364 ;
V_53 -> V_102 [ 2 ] = V_365 ;
V_53 -> V_92 = V_366 ;
V_53 -> V_88 [ 0 ] = V_331 ;
V_53 -> V_88 [ 1 ] = V_332 ;
V_53 -> V_88 [ 2 ] = V_333 ;
V_53 -> V_88 [ 5 ] = V_401 ;
V_53 -> V_88 [ 6 ] = V_402 ;
V_53 -> V_183 = V_337 ;
V_53 -> V_84 = V_368 ;
V_53 -> V_85 = V_369 ;
V_53 -> V_282 = V_340 ;
V_53 -> V_284 = V_341 ;
V_53 -> V_111 = V_342 ;
V_53 -> V_93
= V_343 ;
V_53 -> V_113 = V_381 ;
V_53 -> V_114
= V_382 ;
V_53 -> V_115 = V_383 ;
V_53 -> V_139 = V_384 ;
V_53 -> V_157 = V_345 ;
V_53 -> V_94 = V_346 ;
V_53 -> V_96 = V_403 ;
V_53 -> V_99 [ 0 ] = V_404 ;
V_53 -> V_99 [ 1 ] = V_405 ;
V_53 -> V_99 [ 2 ] = V_406 ;
V_53 -> V_143 = V_407 ;
if ( V_53 -> V_54 == V_59 )
V_53 -> V_148 = V_370 ;
else
V_53 -> V_148 = V_408 ;
V_134 = V_386 ;
V_248 = F_41 ( V_386 ) ;
if ( V_53 -> V_54 == V_59 ) {
V_243 = V_387 ;
V_249 = F_41 ( V_387 ) ;
} else {
V_243 = V_409 ;
V_249 = F_41 ( V_409 ) ;
}
V_241 = V_388 ;
V_242 = V_389 ;
V_208 = V_390 ;
V_244 = V_391 ;
V_245 = V_392 ;
break;
default:
return - V_158 ;
}
V_53 -> V_122 = F_20 ( V_53 -> V_121 ) - 1 ;
V_53 -> V_133 = 0 ;
V_234 = 0 ;
V_233 = 0 ;
for ( V_34 = 0 ; V_34 < V_248 ; V_34 ++ ) {
if ( V_134 [ V_34 ] == 0 )
continue;
V_156 = F_31 ( V_53 , V_53 -> V_157 [ V_34 ] ) & 0x1f ;
if ( ! V_156 || ( V_234 & F_20 ( V_156 ) ) )
V_233 |= F_20 ( V_34 ) ;
V_234 |= F_20 ( V_156 ) ;
}
F_126 ( V_53 , V_53 -> V_94 , & V_233 , & V_234 ) ;
F_126 ( V_53 , V_53 -> V_96 , & V_233 , & V_234 ) ;
V_234 = 0 ;
V_47 = V_136 ;
for ( V_34 = 0 ; V_34 < V_248 ; V_34 ++ ) {
if ( V_134 [ V_34 ] == 0 )
continue;
V_156 = F_31 ( V_53 , V_53 -> V_157 [ V_34 ] ) & 0x1f ;
if ( ! V_156 || ( V_234 & F_20 ( V_156 ) ) )
continue;
if ( ! ( V_53 -> V_235 & F_20 ( V_156 ) ) ) {
F_72 ( V_19 ,
L_14 ,
V_156 , V_34 , V_53 -> V_157 [ V_34 ] , V_134 [ V_34 ] ) ;
continue;
}
V_234 |= F_20 ( V_156 ) ;
if ( V_156 <= V_53 -> V_209 ) {
V_53 -> V_133 |= F_20 ( V_156 - 1 ) ;
V_53 -> V_137 |= F_20 ( V_156 - 1 ) ;
V_53 -> V_134 [ 0 ] [ V_156 - 1 ] = V_134 [ V_34 ] ;
V_53 -> V_134 [ 1 ] [ V_156 - 1 ] = V_241 [ V_34 ] ;
V_53 -> V_134 [ 2 ] [ V_156 - 1 ] = V_242 [ V_34 ] ;
if ( V_247 && V_247 [ V_34 ] )
V_53 -> V_134 [ 3 ] [ V_156 - 1 ] = V_247 [ V_34 ] ;
else if ( V_245 [ V_156 - 1 ] )
V_53 -> V_134 [ 3 ] [ V_156 - 1 ]
= V_245 [ V_156 - 1 ] ;
if ( V_246 && V_246 [ V_34 ] )
V_53 -> V_134 [ 4 ] [ V_156 - 1 ] = V_246 [ V_34 ] ;
V_53 -> V_208 [ V_156 - 1 ] = V_208 [ V_34 ] ;
V_53 -> V_155 [ V_156 - 1 ] = V_156 ;
continue;
}
if ( V_47 >= V_132 )
continue;
V_53 -> V_133 |= F_20 ( V_47 ) ;
V_53 -> V_134 [ 0 ] [ V_47 ] = V_134 [ V_34 ] ;
V_53 -> V_134 [ 1 ] [ V_47 ] = V_241 [ V_34 ] ;
V_53 -> V_134 [ 2 ] [ V_47 ] = V_242 [ V_34 ] ;
V_53 -> V_208 [ V_47 ] = V_208 [ V_34 ] ;
if ( V_247 && V_247 [ V_34 ] )
V_53 -> V_134 [ 3 ] [ V_47 ] = V_247 [ V_34 ] ;
else if ( V_245 [ V_156 - 1 ] )
V_53 -> V_134 [ 3 ] [ V_47 ] = V_245 [ V_156 - 1 ] ;
if ( V_246 && V_246 [ V_34 ] )
V_53 -> V_134 [ 4 ] [ V_47 ] = V_246 [ V_34 ] ;
V_53 -> V_155 [ V_47 ] = V_156 ;
V_47 ++ ;
}
for ( V_34 = 0 ; V_34 < V_249 ; V_34 ++ ) {
if ( V_243 [ V_34 ] == 0 )
continue;
V_156 = F_31 ( V_53 , V_53 -> V_94 [ V_34 ] ) & 0x1f ;
if ( ! V_156 )
continue;
if ( ! ( V_53 -> V_235 & F_20 ( V_156 ) ) ) {
F_72 ( V_19 ,
L_14 ,
V_156 , V_34 , V_53 -> V_94 [ V_34 ] ,
V_243 [ V_34 ] ) ;
continue;
}
if ( V_156 != V_410 ) {
if ( V_234 & F_20 ( V_156 ) )
continue;
V_234 |= F_20 ( V_156 ) ;
}
if ( V_156 <= V_53 -> V_209 ) {
if ( V_53 -> V_133 & F_20 ( V_156 - 1 ) )
continue;
V_53 -> V_133 |= F_20 ( V_156 - 1 ) ;
V_53 -> V_137 |= F_20 ( V_156 - 1 ) ;
V_53 -> V_134 [ 0 ] [ V_156 - 1 ] = V_243 [ V_34 ] ;
V_53 -> V_155 [ V_156 - 1 ] = V_156 ;
continue;
}
if ( V_47 >= V_132 )
continue;
V_53 -> V_133 |= F_20 ( V_47 ) ;
V_53 -> V_134 [ 0 ] [ V_47 ] = V_243 [ V_34 ] ;
V_53 -> V_155 [ V_47 ] = V_156 ;
V_47 ++ ;
}
#ifdef F_134
for ( V_34 = 0 ; V_34 < 32 ; V_34 ++ ) {
if ( ! ( V_53 -> V_235 & F_20 ( V_34 + 1 ) ) )
continue;
if ( ! V_244 [ V_34 ] )
continue;
if ( V_234 & F_20 ( V_34 + 1 ) )
continue;
if ( V_34 < V_53 -> V_209 ) {
if ( V_53 -> V_133 & F_20 ( V_34 ) )
continue;
V_53 -> V_133 |= F_20 ( V_34 ) ;
V_53 -> V_137 |= F_20 ( V_34 ) ;
V_53 -> V_134 [ 0 ] [ V_34 ] = V_244 [ V_34 ] ;
if ( V_34 < V_248 ) {
V_53 -> V_134 [ 1 ] [ V_34 ] = V_241 [ V_34 ] ;
V_53 -> V_134 [ 2 ] [ V_34 ] = V_242 [ V_34 ] ;
}
V_53 -> V_155 [ V_34 ] = V_34 + 1 ;
continue;
}
if ( V_47 >= V_132 )
break;
V_53 -> V_133 |= F_20 ( V_47 ) ;
V_53 -> V_134 [ 0 ] [ V_47 ] = V_244 [ V_34 ] ;
V_53 -> V_155 [ V_47 ] = V_34 + 1 ;
V_47 ++ ;
}
#endif
F_123 ( V_53 ) ;
V_152 = F_6 ( V_239 -> V_201 ) ;
if ( V_152 )
return V_152 ;
V_250 = F_3 ( V_239 -> V_201 , 0x2a ) ;
switch ( V_53 -> V_54 ) {
case V_56 :
V_53 -> V_205 = ( V_250 & 0x40 ) ;
break;
case V_57 :
V_53 -> V_205 = ( V_250 & 0x60 ) == 0x40 ;
break;
case V_55 :
case V_58 :
case V_59 :
case V_60 :
case V_61 :
case V_62 :
break;
}
if ( V_53 -> V_205 ) {
F_5 ( V_239 -> V_201 , V_411 ) ;
V_53 -> V_197 = F_3 ( V_239 -> V_201 , 0xe3 ) ;
V_53 -> V_198 = F_135 () ;
}
if ( V_412 ) {
T_1 V_206 ;
F_5 ( V_239 -> V_201 , V_220 ) ;
V_206 = F_3 ( V_239 -> V_201 ,
V_413 ) ;
switch ( V_53 -> V_54 ) {
case V_55 :
V_206 |= 0xe0 ;
break;
case V_56 :
V_206 |= 0x1e ;
break;
case V_57 :
case V_58 :
V_206 |= 0x3e ;
break;
case V_59 :
case V_60 :
case V_61 :
case V_62 :
V_206 |= 0x7e ;
break;
}
F_1 ( V_239 -> V_201 , V_413 ,
V_206 ) ;
F_72 ( & V_237 -> V_19 , L_15 ,
V_53 -> V_41 ) ;
}
F_124 ( V_53 ) ;
F_8 ( V_239 -> V_201 ) ;
F_42 ( V_19 , V_53 ) ;
V_23 = F_24 ( V_19 , & V_414 ,
V_53 -> V_82 ) ;
if ( F_136 ( V_23 ) )
return F_137 ( V_23 ) ;
V_53 -> V_415 [ V_252 ++ ] = V_23 ;
V_23 = F_24 ( V_19 , & V_416 ,
F_138 ( V_53 -> V_122 ) ) ;
if ( F_136 ( V_23 ) )
return F_137 ( V_23 ) ;
V_53 -> V_415 [ V_252 ++ ] = V_23 ;
V_23 = F_24 ( V_19 , & V_417 ,
F_138 ( V_53 -> V_74 ) ) ;
if ( F_136 ( V_23 ) )
return F_137 ( V_23 ) ;
V_53 -> V_415 [ V_252 ++ ] = V_23 ;
V_23 = F_24 ( V_19 , & V_418 ,
F_138 ( V_53 -> V_133 ) ) ;
if ( F_136 ( V_23 ) )
return F_137 ( V_23 ) ;
V_53 -> V_415 [ V_252 ++ ] = V_23 ;
V_53 -> V_415 [ V_252 ++ ] = & V_419 ;
V_251 = F_139 ( V_19 , V_53 -> V_41 ,
V_53 , V_53 -> V_415 ) ;
return F_140 ( V_251 ) ;
}
static void F_141 ( int V_420 )
{
int V_3 ;
V_3 = F_3 ( V_420 , V_421 ) ;
if ( V_3 & 0x10 ) {
F_142 ( L_16 ) ;
F_1 ( V_420 , V_421 ,
V_3 & ~ 0x10 ) ;
}
}
static int T_7 F_143 ( struct V_18 * V_19 )
{
struct V_52 * V_53 = F_50 ( V_19 ) ;
F_51 ( & V_53 -> V_116 ) ;
V_53 -> V_175 = F_31 ( V_53 , V_53 -> V_180 ) ;
if ( V_53 -> V_54 == V_56 ) {
V_53 -> V_422 = F_31 ( V_53 , V_71 ) ;
V_53 -> V_423 = F_31 ( V_53 , V_73 ) ;
}
F_53 ( & V_53 -> V_116 ) ;
return 0 ;
}
static int T_7 F_144 ( struct V_18 * V_19 )
{
struct V_52 * V_53 = F_46 ( V_19 ) ;
int V_201 = V_53 -> V_201 ;
int V_34 , V_79 , V_152 = 0 ;
T_1 V_2 ;
F_51 ( & V_53 -> V_116 ) ;
V_53 -> V_63 = 0xff ;
V_152 = F_6 ( V_201 ) ;
if ( V_152 )
goto abort;
F_5 ( V_201 , V_220 ) ;
V_2 = F_3 ( V_201 , V_222 ) ;
if ( V_2 != V_53 -> V_221 )
F_1 ( V_201 , V_222 , V_53 -> V_221 ) ;
if ( V_53 -> V_54 == V_59 || V_53 -> V_54 == V_60 ||
V_53 -> V_54 == V_61 || V_53 -> V_54 == V_62 )
F_141 ( V_201 ) ;
F_8 ( V_201 ) ;
for ( V_34 = 0 ; V_34 < V_53 -> V_121 ; V_34 ++ ) {
if ( ! ( V_53 -> V_122 & F_20 ( V_34 ) ) )
continue;
F_33 ( V_53 , V_53 -> V_125 [ 0 ] [ V_34 ] ,
V_53 -> V_123 [ V_34 ] [ 1 ] ) ;
F_33 ( V_53 , V_53 -> V_125 [ 1 ] [ V_34 ] ,
V_53 -> V_123 [ V_34 ] [ 2 ] ) ;
}
for ( V_34 = 0 ; V_34 < F_41 ( V_53 -> V_76 ) ; V_34 ++ ) {
if ( ! ( V_53 -> V_77 & F_20 ( V_34 ) ) )
continue;
F_33 ( V_53 , V_53 -> V_78 [ V_34 ] ,
V_53 -> V_76 [ V_34 ] ) ;
}
for ( V_34 = 0 ; V_34 < V_132 ; V_34 ++ ) {
if ( ! ( V_53 -> V_133 & F_20 ( V_34 ) ) )
continue;
for ( V_79 = 1 ; V_79 < F_41 ( V_53 -> V_134 ) ; V_79 ++ )
if ( V_53 -> V_134 [ V_79 ] [ V_34 ] )
F_35 ( V_53 , V_53 -> V_134 [ V_79 ] [ V_34 ] ,
V_53 -> V_135 [ V_79 ] [ V_34 ] ) ;
}
F_33 ( V_53 , V_53 -> V_180 , V_53 -> V_175 ) ;
if ( V_53 -> V_54 == V_56 ) {
F_33 ( V_53 , V_71 , V_53 -> V_422 ) ;
F_33 ( V_53 , V_73 , V_53 -> V_423 ) ;
}
abort:
V_53 -> V_120 = false ;
F_53 ( & V_53 -> V_116 ) ;
return V_152 ;
}
static int T_8 F_145 ( int V_420 , struct V_238 * V_239 )
{
T_2 V_3 ;
int V_152 ;
int V_65 ;
V_152 = F_6 ( V_420 ) ;
if ( V_152 )
return V_152 ;
V_3 = ( F_3 ( V_420 , V_424 ) << 8 ) |
F_3 ( V_420 , V_424 + 1 ) ;
if ( V_425 && V_3 != 0xffff )
V_3 = V_425 ;
switch ( V_3 & V_426 ) {
case V_427 :
V_239 -> V_54 = V_55 ;
break;
case V_428 :
V_239 -> V_54 = V_56 ;
break;
case V_429 :
V_239 -> V_54 = V_57 ;
break;
case V_430 :
V_239 -> V_54 = V_58 ;
break;
case V_431 :
V_239 -> V_54 = V_59 ;
break;
case V_432 :
V_239 -> V_54 = V_60 ;
break;
case V_433 :
V_239 -> V_54 = V_61 ;
break;
case V_434 :
V_239 -> V_54 = V_62 ;
break;
default:
if ( V_3 != 0xffff )
F_146 ( L_17 , V_3 ) ;
F_8 ( V_420 ) ;
return - V_158 ;
}
F_5 ( V_420 , V_220 ) ;
V_3 = ( F_3 ( V_420 , V_435 ) << 8 )
| F_3 ( V_420 , V_435 + 1 ) ;
V_65 = V_3 & V_436 ;
if ( V_65 == 0 ) {
F_147 ( L_18 ) ;
F_8 ( V_420 ) ;
return - V_158 ;
}
V_3 = F_3 ( V_420 , V_222 ) ;
if ( ! ( V_3 & 0x01 ) ) {
F_148 ( L_19 ) ;
F_1 ( V_420 , V_222 , V_3 | 0x01 ) ;
}
if ( V_239 -> V_54 == V_59 || V_239 -> V_54 == V_60 ||
V_239 -> V_54 == V_61 || V_239 -> V_54 == V_62 )
F_141 ( V_420 ) ;
F_8 ( V_420 ) ;
F_142 ( L_20 ,
V_437 [ V_239 -> V_54 ] , V_420 , V_65 ) ;
V_239 -> V_201 = V_420 ;
return V_65 ;
}
static int T_8 F_149 ( void )
{
int V_34 , V_152 ;
bool V_438 = false ;
int V_439 ;
struct V_240 V_68 ;
struct V_238 V_239 ;
int V_420 [ 2 ] = { 0x2e , 0x4e } ;
V_152 = F_150 ( & V_440 ) ;
if ( V_152 )
return V_152 ;
for ( V_34 = 0 ; V_34 < F_41 ( V_237 ) ; V_34 ++ ) {
V_439 = F_145 ( V_420 [ V_34 ] , & V_239 ) ;
if ( V_439 <= 0 )
continue;
V_438 = true ;
V_237 [ V_34 ] = F_151 ( V_6 , V_439 ) ;
if ( ! V_237 [ V_34 ] ) {
V_152 = - V_39 ;
goto V_441;
}
V_152 = F_152 ( V_237 [ V_34 ] , & V_239 ,
sizeof( struct V_238 ) ) ;
if ( V_152 )
goto V_442;
memset ( & V_68 , 0 , sizeof( V_68 ) ) ;
V_68 . V_41 = V_6 ;
V_68 . V_254 = V_439 + V_443 ;
V_68 . V_444 = V_439 + V_443 + V_255 - 1 ;
V_68 . V_445 = V_253 ;
V_152 = F_153 ( & V_68 ) ;
if ( V_152 ) {
F_154 ( V_237 [ V_34 ] ) ;
V_237 [ V_34 ] = NULL ;
continue;
}
V_152 = F_155 ( V_237 [ V_34 ] , & V_68 , 1 ) ;
if ( V_152 )
goto V_442;
V_152 = F_156 ( V_237 [ V_34 ] ) ;
if ( V_152 )
goto V_442;
}
if ( ! V_438 ) {
V_152 = - V_158 ;
goto V_446;
}
return 0 ;
V_442:
F_154 ( V_237 [ V_34 ] ) ;
V_441:
while ( -- V_34 >= 0 ) {
if ( V_237 [ V_34 ] )
F_157 ( V_237 [ V_34 ] ) ;
}
V_446:
F_158 ( & V_440 ) ;
return V_152 ;
}
static void T_9 F_159 ( void )
{
int V_34 ;
for ( V_34 = 0 ; V_34 < F_41 ( V_237 ) ; V_34 ++ ) {
if ( V_237 [ V_34 ] )
F_157 ( V_237 [ V_34 ] ) ;
}
F_158 ( & V_440 ) ;
}
