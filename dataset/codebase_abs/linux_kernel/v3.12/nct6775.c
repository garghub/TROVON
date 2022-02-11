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
static struct V_17 *
F_23 ( struct V_18 * V_19 , struct V_20 * V_21 ,
int V_22 )
{
struct V_17 * V_23 ;
struct V_24 * V_25 ;
struct V_26 * V_27 ;
struct V_28 * V_29 ;
struct V_30 * * V_31 ;
struct V_32 * * V_33 ;
int V_34 , V_35 , V_36 , V_37 ;
if ( V_22 <= 0 )
return F_24 ( - V_38 ) ;
V_33 = V_21 -> V_39 ;
for ( V_37 = 0 ; * V_33 ; V_33 ++ , V_37 ++ )
;
if ( V_37 == 0 )
return F_24 ( - V_38 ) ;
V_23 = F_25 ( V_19 , sizeof( * V_23 ) , V_40 ) ;
if ( V_23 == NULL )
return F_24 ( - V_41 ) ;
V_31 = F_25 ( V_19 , sizeof( * V_31 ) * ( V_22 * V_37 + 1 ) ,
V_40 ) ;
if ( V_31 == NULL )
return F_24 ( - V_41 ) ;
V_25 = F_25 ( V_19 , sizeof( * V_25 ) * V_22 * V_37 ,
V_40 ) ;
if ( V_25 == NULL )
return F_24 ( - V_41 ) ;
V_23 -> V_31 = V_31 ;
V_23 -> V_42 = V_21 -> V_42 ;
for ( V_35 = 0 ; V_35 < V_22 ; V_35 ++ ) {
V_33 = V_21 -> V_39 ;
for ( V_36 = 0 ; * V_33 != NULL ; V_36 ++ ) {
snprintf ( V_25 -> V_43 , sizeof( V_25 -> V_43 ) ,
( * V_33 ) -> V_44 . V_45 . V_43 , V_21 -> V_46 + V_35 ) ;
if ( ( * V_33 ) -> V_47 ) {
V_29 = & V_25 -> V_48 . V_29 ;
V_29 -> V_44 . V_45 . V_43 = V_25 -> V_43 ;
V_29 -> V_15 = ( * V_33 ) -> V_48 . V_49 . V_15 + V_35 ;
V_29 -> V_50 = ( * V_33 ) -> V_48 . V_49 . V_50 ;
V_29 -> V_44 . V_45 . V_10 =
( * V_33 ) -> V_44 . V_45 . V_10 ;
V_29 -> V_44 . V_51 = ( * V_33 ) -> V_44 . V_51 ;
V_29 -> V_44 . V_52 = ( * V_33 ) -> V_44 . V_52 ;
* V_31 = & V_29 -> V_44 . V_45 ;
} else {
V_27 = & V_25 -> V_48 . V_53 ;
V_27 -> V_44 . V_45 . V_43 = V_25 -> V_43 ;
V_27 -> V_50 = ( * V_33 ) -> V_48 . V_50 + V_35 ;
V_27 -> V_44 . V_45 . V_10 =
( * V_33 ) -> V_44 . V_45 . V_10 ;
V_27 -> V_44 . V_51 = ( * V_33 ) -> V_44 . V_51 ;
V_27 -> V_44 . V_52 = ( * V_33 ) -> V_44 . V_52 ;
* V_31 = & V_27 -> V_44 . V_45 ;
}
V_31 ++ ;
V_25 ++ ;
V_33 ++ ;
}
}
V_34 = F_26 ( & V_19 -> V_54 , V_23 ) ;
if ( V_34 )
return F_24 ( - V_41 ) ;
return V_23 ;
}
static bool F_27 ( struct V_55 * V_56 , T_2 V_2 )
{
switch ( V_56 -> V_57 ) {
case V_58 :
return V_2 == 0x20 || V_2 == 0x22 || V_2 == 0x24 ||
V_2 == 0xe0 || V_2 == 0xe2 || V_2 == 0xe4 ||
V_2 == 0x111 || V_2 == 0x121 || V_2 == 0x131 ;
case V_59 :
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
case V_60 :
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
case V_61 :
case V_62 :
return V_2 == 0x150 || V_2 == 0x153 || V_2 == 0x155 ||
( ( V_2 & 0xfff0 ) == 0x4b0 && ( V_2 & 0x000f ) < 0x0b ) ||
V_2 == 0x402 ||
V_2 == 0x63a || V_2 == 0x63c || V_2 == 0x63e ||
V_2 == 0x640 || V_2 == 0x642 ||
V_2 == 0x73 || V_2 == 0x75 || V_2 == 0x77 || V_2 == 0x79 ||
V_2 == 0x7b ;
}
return false ;
}
static inline void F_28 ( struct V_55 * V_56 , T_2 V_2 )
{
T_1 V_63 = V_2 >> 8 ;
if ( V_56 -> V_63 != V_63 ) {
F_29 ( V_64 , V_56 -> V_65 + V_66 ) ;
F_29 ( V_63 , V_56 -> V_65 + V_67 ) ;
V_56 -> V_63 = V_63 ;
}
}
static T_2 F_30 ( struct V_55 * V_56 , T_2 V_2 )
{
int V_68 , V_69 = F_27 ( V_56 , V_2 ) ;
F_28 ( V_56 , V_2 ) ;
F_29 ( V_2 & 0xff , V_56 -> V_65 + V_66 ) ;
V_68 = F_31 ( V_56 -> V_65 + V_67 ) ;
if ( V_69 ) {
F_29 ( ( V_2 & 0xff ) + 1 ,
V_56 -> V_65 + V_66 ) ;
V_68 = ( V_68 << 8 ) + F_31 ( V_56 -> V_65 + V_67 ) ;
}
return V_68 ;
}
static int F_32 ( struct V_55 * V_56 , T_2 V_2 , T_2 V_70 )
{
int V_69 = F_27 ( V_56 , V_2 ) ;
F_28 ( V_56 , V_2 ) ;
F_29 ( V_2 & 0xff , V_56 -> V_65 + V_66 ) ;
if ( V_69 ) {
F_29 ( V_70 >> 8 , V_56 -> V_65 + V_67 ) ;
F_29 ( ( V_2 & 0xff ) + 1 ,
V_56 -> V_65 + V_66 ) ;
}
F_29 ( V_70 & 0xff , V_56 -> V_65 + V_67 ) ;
return 0 ;
}
static T_2 F_33 ( struct V_55 * V_56 , T_2 V_2 )
{
T_2 V_68 ;
V_68 = F_30 ( V_56 , V_2 ) ;
if ( ! F_27 ( V_56 , V_2 ) )
V_68 <<= 8 ;
return V_68 ;
}
static int F_34 ( struct V_55 * V_56 , T_2 V_2 , T_2 V_70 )
{
if ( ! F_27 ( V_56 , V_2 ) )
V_70 >>= 8 ;
return F_32 ( V_56 , V_2 , V_70 ) ;
}
static void F_35 ( struct V_55 * V_56 , int V_15 )
{
T_1 V_2 ;
switch ( V_15 ) {
case 0 :
V_2 = ( F_30 ( V_56 , V_71 ) & 0x70 )
| ( V_56 -> V_72 [ 0 ] & 0x7 ) ;
F_32 ( V_56 , V_71 , V_2 ) ;
break;
case 1 :
V_2 = ( F_30 ( V_56 , V_71 ) & 0x7 )
| ( ( V_56 -> V_72 [ 1 ] << 4 ) & 0x70 ) ;
F_32 ( V_56 , V_71 , V_2 ) ;
break;
case 2 :
V_2 = ( F_30 ( V_56 , V_73 ) & 0x70 )
| ( V_56 -> V_72 [ 2 ] & 0x7 ) ;
F_32 ( V_56 , V_73 , V_2 ) ;
break;
case 3 :
V_2 = ( F_30 ( V_56 , V_73 ) & 0x7 )
| ( ( V_56 -> V_72 [ 3 ] << 4 ) & 0x70 ) ;
F_32 ( V_56 , V_73 , V_2 ) ;
break;
}
}
static void F_36 ( struct V_55 * V_56 , int V_15 )
{
if ( V_56 -> V_57 == V_59 )
F_35 ( V_56 , V_15 ) ;
}
static void F_37 ( struct V_55 * V_56 )
{
T_1 V_35 ;
V_35 = F_30 ( V_56 , V_71 ) ;
V_56 -> V_72 [ 0 ] = V_35 & 0x7 ;
V_56 -> V_72 [ 1 ] = ( V_35 & 0x70 ) >> 4 ;
V_35 = F_30 ( V_56 , V_73 ) ;
V_56 -> V_72 [ 2 ] = V_35 & 0x7 ;
if ( V_56 -> V_74 & ( 1 << 3 ) )
V_56 -> V_72 [ 3 ] = ( V_35 & 0x70 ) >> 4 ;
}
static void F_38 ( struct V_55 * V_56 )
{
if ( V_56 -> V_57 == V_59 )
F_37 ( V_56 ) ;
}
static void F_39 ( struct V_55 * V_56 )
{
int V_35 ;
F_38 ( V_56 ) ;
for ( V_35 = 0 ; V_35 < F_40 ( V_56 -> V_72 ) ; V_35 ++ ) {
if ( ! ( V_56 -> V_74 & ( 1 << V_35 ) ) )
continue;
if ( V_56 -> V_72 [ V_35 ] == 0 ) {
V_56 -> V_72 [ V_35 ] = 7 ;
F_36 ( V_56 , V_35 ) ;
}
}
}
static void F_41 ( struct V_18 * V_19 ,
struct V_55 * V_56 )
{
int V_35 ;
T_1 V_2 ;
if ( V_56 -> V_75 )
F_39 ( V_56 ) ;
for ( V_35 = 0 ; V_35 < F_40 ( V_56 -> V_76 ) ; V_35 ++ ) {
if ( V_56 -> V_77 & ( 1 << V_35 ) ) {
V_2 = F_30 ( V_56 , V_56 -> V_78 [ V_35 ] ) ;
if ( ! V_2 )
F_32 ( V_56 , V_56 -> V_78 [ V_35 ] ,
V_56 -> V_75 ? 0xff
: 0xff1f ) ;
}
}
}
static void F_42 ( struct V_18 * V_19 ,
struct V_55 * V_56 , int V_15 , T_2 V_2 )
{
T_1 V_72 = V_56 -> V_72 [ V_15 ] ;
T_2 V_76 ;
if ( ! V_56 -> V_75 )
return;
if ( V_2 == 0x00 && V_72 < 0x07 )
V_72 ++ ;
else if ( V_2 != 0x00 && V_2 < 0x30 && V_72 > 0 )
V_72 -- ;
if ( V_72 != V_56 -> V_72 [ V_15 ] ) {
F_43 ( V_19 , L_1 ,
V_15 + 1 , F_19 ( V_56 -> V_72 [ V_15 ] ) ,
F_19 ( V_72 ) ) ;
if ( V_56 -> V_77 & ( 1 << V_15 ) ) {
V_76 = V_56 -> V_76 [ V_15 ] ;
if ( V_72 > V_56 -> V_72 [ V_15 ] ) {
if ( V_76 != 255 && V_76 > 1 )
V_76 >>= 1 ;
} else {
if ( V_76 != 255 ) {
V_76 <<= 1 ;
if ( V_76 > 254 )
V_76 = 254 ;
}
}
if ( V_76 != V_56 -> V_76 [ V_15 ] ) {
V_56 -> V_76 [ V_15 ] = V_76 ;
F_32 ( V_56 , V_56 -> V_78 [ V_15 ] ,
V_76 ) ;
}
}
V_56 -> V_72 [ V_15 ] = V_72 ;
F_36 ( V_56 , V_15 ) ;
}
}
static void F_44 ( struct V_18 * V_19 )
{
struct V_55 * V_56 = F_45 ( V_19 ) ;
int V_35 , V_36 ;
int V_79 , V_2 ;
bool V_80 ;
for ( V_35 = 0 ; V_35 < V_56 -> V_81 ; V_35 ++ ) {
if ( ! ( V_56 -> V_82 & ( 1 << V_35 ) ) )
continue;
V_80 = V_56 -> V_83 [ V_35 ] &&
( F_30 ( V_56 , V_56 -> V_83 [ V_35 ] )
& V_56 -> V_84 [ V_35 ] ) ;
V_56 -> V_85 [ V_35 ] = V_80 ;
V_79 = F_30 ( V_56 , V_56 -> V_86 [ V_35 ] ) ;
for ( V_36 = 0 ; V_36 < F_40 ( V_56 -> V_87 ) ; V_36 ++ ) {
if ( V_56 -> V_87 [ V_36 ] && V_56 -> V_87 [ V_36 ] [ V_35 ] ) {
V_56 -> V_9 [ V_36 ] [ V_35 ]
= F_30 ( V_56 ,
V_56 -> V_87 [ V_36 ] [ V_35 ] ) ;
}
}
V_56 -> V_8 [ V_35 ] = F_10 ( V_56 -> V_9 [ 0 ] [ V_35 ] ,
( V_79 >> 4 ) & 7 ) ;
if ( ! V_56 -> V_88 [ 0 ] [ V_35 ] ||
V_56 -> V_8 [ V_35 ] != V_89 )
V_56 -> V_88 [ 0 ] [ V_35 ] = V_79 & 0x0f ;
if ( ! V_56 -> V_90 [ V_35 ] ||
V_56 -> V_8 [ V_35 ] == V_89 ) {
T_1 V_33 = V_79 & 0x0f ;
if ( V_56 -> V_91 ) {
V_33 |= ( F_30 ( V_56 ,
V_56 -> V_91 [ V_35 ] ) & 0x70 ) >> 1 ;
}
V_56 -> V_90 [ V_35 ] = V_33 ;
}
V_56 -> V_88 [ 1 ] [ V_35 ] =
F_30 ( V_56 ,
V_56 -> V_92 [ V_35 ] ) ;
V_2 = F_30 ( V_56 , V_56 -> V_93 [ V_35 ] ) ;
V_56 -> V_94 [ V_35 ] = V_2 & 0x1f ;
if ( V_2 & 0x80 )
V_56 -> V_9 [ 2 ] [ V_35 ] = 0 ;
V_2 = F_30 ( V_56 , V_56 -> V_95 [ V_35 ] ) ;
V_56 -> V_96 [ V_35 ] = V_2 & 0x1f ;
if ( V_36 == 1 && ! ( V_2 & 0x80 ) )
V_56 -> V_96 [ V_35 ] = 0 ;
for ( V_36 = 0 ; V_36 < F_40 ( V_56 -> V_97 ) ; V_36 ++ ) {
V_56 -> V_97 [ V_36 ] [ V_35 ]
= F_30 ( V_56 ,
V_56 -> V_98 [ V_36 ] [ V_35 ] ) ;
}
}
}
static void F_46 ( struct V_18 * V_19 )
{
struct V_55 * V_56 = F_45 ( V_19 ) ;
int V_35 , V_36 ;
T_1 V_2 ;
T_2 V_99 ;
for ( V_35 = 0 ; V_35 < V_56 -> V_81 ; V_35 ++ ) {
if ( ! ( V_56 -> V_82 & ( 1 << V_35 ) ) )
continue;
for ( V_36 = 0 ; V_36 < F_40 ( V_56 -> V_100 ) ; V_36 ++ ) {
V_56 -> V_100 [ V_36 ] [ V_35 ] =
F_30 ( V_56 , V_56 -> V_101 [ V_36 ] [ V_35 ] ) ;
}
V_99 = F_30 ( V_56 , V_56 -> V_102 [ V_35 ] ) ;
if ( ! V_56 -> V_103 [ V_35 ] ||
V_56 -> V_8 [ V_35 ] == V_104 )
V_56 -> V_103 [ V_35 ] = V_99 & V_56 -> V_105 ;
if ( ! V_56 -> V_106 [ V_35 ] ||
V_56 -> V_8 [ V_35 ] == V_89 ) {
if ( V_56 -> V_91 ) {
V_99 |= ( F_30 ( V_56 ,
V_56 -> V_91 [ V_35 ] ) & 0x0f ) << 8 ;
}
V_56 -> V_106 [ V_35 ] = V_99 ;
}
for ( V_36 = 0 ; V_36 < V_56 -> V_107 ; V_36 ++ ) {
V_56 -> V_108 [ V_35 ] [ V_36 ] =
F_30 ( V_56 ,
F_47 ( V_56 , V_35 , V_36 ) ) ;
V_56 -> V_109 [ V_35 ] [ V_36 ] =
F_30 ( V_56 ,
F_48 ( V_56 , V_35 , V_36 ) ) ;
}
V_56 -> V_109 [ V_35 ] [ V_56 -> V_107 ] =
F_30 ( V_56 , V_56 -> V_110 [ V_35 ] ) ;
switch ( V_56 -> V_57 ) {
case V_59 :
V_2 = F_30 ( V_56 ,
V_111 [ V_35 ] ) ;
V_56 -> V_108 [ V_35 ] [ V_56 -> V_107 ] =
( V_2 & 0x02 ) ? 0xff : 0x00 ;
break;
case V_60 :
V_56 -> V_108 [ V_35 ] [ V_56 -> V_107 ] = 0xff ;
break;
case V_58 :
case V_61 :
case V_62 :
V_2 = F_30 ( V_56 ,
V_56 -> V_112 [ V_35 ] ) ;
if ( V_2 & V_56 -> V_113 )
V_2 = F_30 ( V_56 ,
V_56 -> V_114 [ V_35 ] ) ;
else
V_2 = 0xff ;
V_56 -> V_108 [ V_35 ] [ V_56 -> V_107 ] = V_2 ;
break;
}
}
}
static struct V_55 * F_49 ( struct V_18 * V_19 )
{
struct V_55 * V_56 = F_45 ( V_19 ) ;
int V_35 , V_36 ;
F_50 ( & V_56 -> V_115 ) ;
if ( F_51 ( V_116 , V_56 -> V_117 + V_118 + V_118 / 2 )
|| ! V_56 -> V_119 ) {
F_38 ( V_56 ) ;
for ( V_35 = 0 ; V_35 < V_56 -> V_120 ; V_35 ++ ) {
if ( ! ( V_56 -> V_121 & ( 1 << V_35 ) ) )
continue;
V_56 -> V_122 [ V_35 ] [ 0 ] = F_30 ( V_56 ,
V_56 -> V_123 [ V_35 ] ) ;
V_56 -> V_122 [ V_35 ] [ 1 ] = F_30 ( V_56 ,
V_56 -> V_124 [ 0 ] [ V_35 ] ) ;
V_56 -> V_122 [ V_35 ] [ 2 ] = F_30 ( V_56 ,
V_56 -> V_124 [ 1 ] [ V_35 ] ) ;
}
for ( V_35 = 0 ; V_35 < F_40 ( V_56 -> V_125 ) ; V_35 ++ ) {
T_2 V_2 ;
if ( ! ( V_56 -> V_74 & ( 1 << V_35 ) ) )
continue;
V_2 = F_30 ( V_56 , V_56 -> V_126 [ V_35 ] ) ;
V_56 -> V_125 [ V_35 ] = V_56 -> V_127 ( V_2 ,
V_56 -> V_72 [ V_35 ] ) ;
if ( V_56 -> V_77 & ( 1 << V_35 ) )
V_56 -> V_76 [ V_35 ] = F_30 ( V_56 ,
V_56 -> V_78 [ V_35 ] ) ;
V_56 -> V_128 [ V_35 ] =
( F_30 ( V_56 , V_56 -> V_129 [ V_35 ] )
>> V_56 -> V_130 [ V_35 ] ) & 0x03 ;
F_42 ( V_19 , V_56 , V_35 , V_2 ) ;
}
F_44 ( V_19 ) ;
F_46 ( V_19 ) ;
for ( V_35 = 0 ; V_35 < V_131 ; V_35 ++ ) {
if ( ! ( V_56 -> V_132 & ( 1 << V_35 ) ) )
continue;
for ( V_36 = 0 ; V_36 < F_40 ( V_56 -> V_133 ) ; V_36 ++ ) {
if ( V_56 -> V_133 [ V_36 ] [ V_35 ] )
V_56 -> V_134 [ V_36 ] [ V_35 ]
= F_33 ( V_56 ,
V_56 -> V_133 [ V_36 ] [ V_35 ] ) ;
}
if ( ! ( V_56 -> V_135 & ( 1 << V_35 ) ) )
continue;
V_56 -> V_136 [ V_35 ]
= F_30 ( V_56 , V_56 -> V_137 [ V_35 ] ) ;
}
V_56 -> V_138 = 0 ;
for ( V_35 = 0 ; V_35 < V_139 ; V_35 ++ ) {
T_1 V_140 ;
if ( ! V_56 -> V_141 [ V_35 ] )
continue;
V_140 = F_30 ( V_56 , V_56 -> V_141 [ V_35 ] ) ;
V_56 -> V_138 |= ( ( V_142 ) V_140 ) << ( V_35 << 3 ) ;
}
V_56 -> V_143 = 0 ;
for ( V_35 = 0 ; V_35 < V_144 ; V_35 ++ ) {
T_1 V_145 ;
if ( ! V_56 -> V_146 [ V_35 ] )
continue;
V_145 = F_30 ( V_56 , V_56 -> V_146 [ V_35 ] ) ;
V_56 -> V_143 |= ( ( V_142 ) V_145 ) << ( V_35 << 3 ) ;
}
V_56 -> V_117 = V_116 ;
V_56 -> V_119 = true ;
}
F_52 ( & V_56 -> V_115 ) ;
return V_56 ;
}
static T_4
F_53 ( struct V_18 * V_19 , struct V_147 * V_45 , char * V_148 )
{
struct V_55 * V_56 = F_49 ( V_19 ) ;
struct V_28 * V_149 = F_54 ( V_45 ) ;
int V_15 = V_149 -> V_15 ;
int V_50 = V_149 -> V_50 ;
return sprintf ( V_148 , L_2 , F_20 ( V_56 -> V_122 [ V_15 ] [ V_50 ] , V_15 ) ) ;
}
static T_4
F_55 ( struct V_18 * V_19 , struct V_147 * V_45 , const char * V_148 ,
T_5 V_37 )
{
struct V_55 * V_56 = F_45 ( V_19 ) ;
struct V_28 * V_149 = F_54 ( V_45 ) ;
int V_15 = V_149 -> V_15 ;
int V_50 = V_149 -> V_50 ;
unsigned long V_3 ;
int V_34 = F_56 ( V_148 , 10 , & V_3 ) ;
if ( V_34 < 0 )
return V_34 ;
F_50 ( & V_56 -> V_115 ) ;
V_56 -> V_122 [ V_15 ] [ V_50 ] = F_22 ( V_3 , V_15 ) ;
F_32 ( V_56 , V_56 -> V_124 [ V_50 - 1 ] [ V_15 ] ,
V_56 -> V_122 [ V_15 ] [ V_50 ] ) ;
F_52 ( & V_56 -> V_115 ) ;
return V_37 ;
}
static T_4
F_57 ( struct V_18 * V_19 , struct V_147 * V_45 , char * V_148 )
{
struct V_55 * V_56 = F_49 ( V_19 ) ;
struct V_26 * V_149 = F_58 ( V_45 ) ;
int V_15 = V_56 -> V_150 [ V_149 -> V_50 ] ;
return sprintf ( V_148 , L_3 ,
( unsigned int ) ( ( V_56 -> V_138 >> V_15 ) & 0x01 ) ) ;
}
static int F_59 ( struct V_55 * V_56 , int V_50 , int V_37 )
{
int V_151 = V_56 -> V_152 [ V_50 ] ;
int V_15 ;
for ( V_15 = 0 ; V_15 < V_37 ; V_15 ++ ) {
int V_153 ;
V_153 = F_30 ( V_56 ,
V_56 -> V_154 [ V_15 ] ) & 0x1f ;
if ( V_153 == V_151 )
return V_15 ;
}
return - 1 ;
}
static T_4
F_60 ( struct V_18 * V_19 , struct V_147 * V_45 , char * V_148 )
{
struct V_26 * V_149 = F_58 ( V_45 ) ;
struct V_55 * V_56 = F_49 ( V_19 ) ;
unsigned int V_140 = 0 ;
int V_15 ;
V_15 = F_59 ( V_56 , V_149 -> V_50 , V_56 -> V_155 ) ;
if ( V_15 >= 0 ) {
int V_156 = V_56 -> V_150 [ V_15 + V_157 ] ;
V_140 = ( V_56 -> V_138 >> V_156 ) & 0x01 ;
}
return sprintf ( V_148 , L_3 , V_140 ) ;
}
static T_4
F_61 ( struct V_18 * V_19 , struct V_147 * V_45 , char * V_148 )
{
struct V_26 * V_149 = F_58 ( V_45 ) ;
struct V_55 * V_56 = F_49 ( V_19 ) ;
int V_15 = V_56 -> V_158 [ V_149 -> V_50 ] ;
return sprintf ( V_148 , L_3 ,
( unsigned int ) ( ( V_56 -> V_143 >> V_15 ) & 0x01 ) ) ;
}
static T_4
F_62 ( struct V_18 * V_19 , struct V_147 * V_45 , const char * V_148 ,
T_5 V_37 )
{
struct V_28 * V_149 = F_54 ( V_45 ) ;
struct V_55 * V_56 = F_45 ( V_19 ) ;
int V_15 = V_56 -> V_158 [ V_149 -> V_50 ] ;
int V_159 = V_15 >> 3 ;
unsigned long V_3 ;
int V_34 = F_56 ( V_148 , 10 , & V_3 ) ;
if ( V_34 < 0 )
return V_34 ;
if ( V_3 > 1 )
return - V_38 ;
F_50 ( & V_56 -> V_115 ) ;
if ( V_3 )
V_56 -> V_143 |= ( 1ULL << V_15 ) ;
else
V_56 -> V_143 &= ~ ( 1ULL << V_15 ) ;
F_32 ( V_56 , V_56 -> V_146 [ V_159 ] ,
( V_56 -> V_143 >> ( V_159 << 3 ) ) & 0xff ) ;
F_52 ( & V_56 -> V_115 ) ;
return V_37 ;
}
static T_4
F_63 ( struct V_18 * V_19 , struct V_147 * V_45 , char * V_148 )
{
struct V_26 * V_149 = F_58 ( V_45 ) ;
struct V_55 * V_56 = F_49 ( V_19 ) ;
unsigned int V_145 = 0 ;
int V_15 ;
V_15 = F_59 ( V_56 , V_149 -> V_50 , V_56 -> V_160 ) ;
if ( V_15 >= 0 ) {
int V_156 = V_56 -> V_158 [ V_15 + V_157 ] ;
V_145 = ( V_56 -> V_143 >> V_156 ) & 0x01 ;
}
return sprintf ( V_148 , L_3 , V_145 ) ;
}
static T_4
F_64 ( struct V_18 * V_19 , struct V_147 * V_45 ,
const char * V_148 , T_5 V_37 )
{
struct V_28 * V_149 = F_54 ( V_45 ) ;
struct V_55 * V_56 = F_45 ( V_19 ) ;
int V_15 , V_156 , V_159 ;
unsigned long V_3 ;
int V_34 = F_56 ( V_148 , 10 , & V_3 ) ;
if ( V_34 < 0 )
return V_34 ;
if ( V_3 > 1 )
return - V_38 ;
V_15 = F_59 ( V_56 , V_149 -> V_50 , V_56 -> V_160 ) ;
if ( V_15 < 0 )
return - V_161 ;
V_156 = V_56 -> V_158 [ V_15 + V_157 ] ;
V_159 = V_156 >> 3 ;
F_50 ( & V_56 -> V_115 ) ;
if ( V_3 )
V_56 -> V_143 |= ( 1ULL << V_156 ) ;
else
V_56 -> V_143 &= ~ ( 1ULL << V_156 ) ;
F_32 ( V_56 , V_56 -> V_146 [ V_159 ] ,
( V_56 -> V_143 >> ( V_159 << 3 ) ) & 0xff ) ;
F_52 ( & V_56 -> V_115 ) ;
return V_37 ;
}
static T_6 F_65 ( struct V_162 * V_54 ,
struct V_30 * V_45 , int V_50 )
{
struct V_18 * V_19 = F_66 ( V_54 , struct V_18 , V_54 ) ;
struct V_55 * V_56 = F_45 ( V_19 ) ;
int V_122 = V_50 / 5 ;
if ( ! ( V_56 -> V_121 & ( 1 << V_122 ) ) )
return 0 ;
return V_45 -> V_10 ;
}
static T_4
F_67 ( struct V_18 * V_19 , struct V_147 * V_45 , char * V_148 )
{
struct V_55 * V_56 = F_49 ( V_19 ) ;
struct V_26 * V_149 = F_58 ( V_45 ) ;
int V_15 = V_149 -> V_50 ;
return sprintf ( V_148 , L_4 , V_56 -> V_125 [ V_15 ] ) ;
}
static T_4
F_68 ( struct V_18 * V_19 , struct V_147 * V_45 , char * V_148 )
{
struct V_55 * V_56 = F_49 ( V_19 ) ;
struct V_26 * V_149 = F_58 ( V_45 ) ;
int V_15 = V_149 -> V_50 ;
return sprintf ( V_148 , L_4 ,
V_56 -> V_163 ( V_56 -> V_76 [ V_15 ] ,
V_56 -> V_72 [ V_15 ] ) ) ;
}
static T_4
F_69 ( struct V_18 * V_19 , struct V_147 * V_45 , char * V_148 )
{
struct V_55 * V_56 = F_49 ( V_19 ) ;
struct V_26 * V_149 = F_58 ( V_45 ) ;
int V_15 = V_149 -> V_50 ;
return sprintf ( V_148 , L_3 , F_19 ( V_56 -> V_72 [ V_15 ] ) ) ;
}
static T_4
F_70 ( struct V_18 * V_19 , struct V_147 * V_45 ,
const char * V_148 , T_5 V_37 )
{
struct V_55 * V_56 = F_45 ( V_19 ) ;
struct V_26 * V_149 = F_58 ( V_45 ) ;
int V_15 = V_149 -> V_50 ;
unsigned long V_3 ;
int V_34 ;
unsigned int V_2 ;
T_1 V_164 ;
V_34 = F_56 ( V_148 , 10 , & V_3 ) ;
if ( V_34 < 0 )
return V_34 ;
F_50 ( & V_56 -> V_115 ) ;
if ( ! V_56 -> V_75 ) {
if ( ! V_3 ) {
V_3 = 0xff1f ;
} else {
if ( V_3 > 1350000U )
V_3 = 135000U ;
V_3 = 1350000U / V_3 ;
V_3 = ( V_3 & 0x1f ) | ( ( V_3 << 3 ) & 0xff00 ) ;
}
V_56 -> V_76 [ V_15 ] = V_3 ;
goto V_165;
}
if ( ! V_3 ) {
V_56 -> V_76 [ V_15 ] = 255 ;
V_164 = V_56 -> V_72 [ V_15 ] ;
F_71 ( V_19 , L_5 , V_15 + 1 ) ;
goto V_166;
}
V_2 = 1350000U / V_3 ;
if ( V_2 >= 128 * 255 ) {
V_56 -> V_76 [ V_15 ] = 254 ;
V_164 = 7 ;
F_72 ( V_19 ,
L_6 ,
V_15 + 1 , V_3 , V_56 -> V_163 ( 254 , 7 ) ) ;
} else if ( ! V_2 ) {
V_56 -> V_76 [ V_15 ] = 1 ;
V_164 = 0 ;
F_72 ( V_19 ,
L_7 ,
V_15 + 1 , V_3 , V_56 -> V_163 ( 1 , 0 ) ) ;
} else {
V_164 = 0 ;
while ( V_2 > 192 && V_164 < 7 ) {
V_2 >>= 1 ;
V_164 ++ ;
}
V_56 -> V_76 [ V_15 ] = V_2 ;
}
V_166:
if ( V_164 != V_56 -> V_72 [ V_15 ] ) {
F_43 ( V_19 , L_8 ,
V_15 + 1 , F_19 ( V_56 -> V_72 [ V_15 ] ) ,
F_19 ( V_164 ) ) ;
V_56 -> V_72 [ V_15 ] = V_164 ;
F_36 ( V_56 , V_15 ) ;
V_56 -> V_117 = V_116 ;
}
V_165:
F_32 ( V_56 , V_56 -> V_78 [ V_15 ] , V_56 -> V_76 [ V_15 ] ) ;
F_52 ( & V_56 -> V_115 ) ;
return V_37 ;
}
static T_4
F_73 ( struct V_18 * V_19 , struct V_147 * V_45 , char * V_148 )
{
struct V_55 * V_56 = F_49 ( V_19 ) ;
struct V_26 * V_149 = F_58 ( V_45 ) ;
int V_167 = V_56 -> V_128 [ V_149 -> V_50 ] ;
return sprintf ( V_148 , L_4 , V_167 ? : 4 ) ;
}
static T_4
F_74 ( struct V_18 * V_19 , struct V_147 * V_45 ,
const char * V_148 , T_5 V_37 )
{
struct V_55 * V_56 = F_45 ( V_19 ) ;
struct V_26 * V_149 = F_58 ( V_45 ) ;
int V_15 = V_149 -> V_50 ;
unsigned long V_3 ;
int V_34 ;
T_1 V_2 ;
V_34 = F_56 ( V_148 , 10 , & V_3 ) ;
if ( V_34 < 0 )
return V_34 ;
if ( V_3 > 4 )
return - V_38 ;
F_50 ( & V_56 -> V_115 ) ;
V_56 -> V_128 [ V_15 ] = V_3 & 3 ;
V_2 = F_30 ( V_56 , V_56 -> V_129 [ V_15 ] ) ;
V_2 &= ~ ( 0x03 << V_56 -> V_130 [ V_15 ] ) ;
V_2 |= ( V_3 & 3 ) << V_56 -> V_130 [ V_15 ] ;
F_32 ( V_56 , V_56 -> V_129 [ V_15 ] , V_2 ) ;
F_52 ( & V_56 -> V_115 ) ;
return V_37 ;
}
static T_6 F_75 ( struct V_162 * V_54 ,
struct V_30 * V_45 , int V_50 )
{
struct V_18 * V_19 = F_66 ( V_54 , struct V_18 , V_54 ) ;
struct V_55 * V_56 = F_45 ( V_19 ) ;
int V_14 = V_50 / 6 ;
int V_15 = V_50 % 6 ;
if ( ! ( V_56 -> V_74 & ( 1 << V_14 ) ) )
return 0 ;
if ( V_15 == 1 && V_56 -> V_150 [ V_168 + V_14 ] == - 1 )
return 0 ;
if ( V_15 == 2 && V_56 -> V_158 [ V_168 + V_14 ] == - 1 )
return 0 ;
if ( V_15 == 4 && ! ( V_56 -> V_77 & ( 1 << V_14 ) ) )
return 0 ;
if ( V_15 == 5 && V_56 -> V_57 != V_59 )
return 0 ;
return V_45 -> V_10 ;
}
static T_4
F_76 ( struct V_18 * V_19 , struct V_147 * V_45 , char * V_148 )
{
struct V_55 * V_56 = F_49 ( V_19 ) ;
struct V_26 * V_149 = F_58 ( V_45 ) ;
int V_15 = V_149 -> V_50 ;
return sprintf ( V_148 , L_9 , V_56 -> V_169 [ V_56 -> V_152 [ V_15 ] ] ) ;
}
static T_4
F_77 ( struct V_18 * V_19 , struct V_147 * V_45 , char * V_148 )
{
struct V_55 * V_56 = F_49 ( V_19 ) ;
struct V_28 * V_149 = F_54 ( V_45 ) ;
int V_15 = V_149 -> V_15 ;
int V_50 = V_149 -> V_50 ;
return sprintf ( V_148 , L_4 , F_78 ( V_56 -> V_134 [ V_50 ] [ V_15 ] ) ) ;
}
static T_4
F_79 ( struct V_18 * V_19 , struct V_147 * V_45 , const char * V_148 ,
T_5 V_37 )
{
struct V_55 * V_56 = F_45 ( V_19 ) ;
struct V_28 * V_149 = F_54 ( V_45 ) ;
int V_15 = V_149 -> V_15 ;
int V_50 = V_149 -> V_50 ;
int V_34 ;
long V_3 ;
V_34 = F_80 ( V_148 , 10 , & V_3 ) ;
if ( V_34 < 0 )
return V_34 ;
F_50 ( & V_56 -> V_115 ) ;
V_56 -> V_134 [ V_50 ] [ V_15 ] = F_81 ( V_3 ) ;
F_34 ( V_56 , V_56 -> V_133 [ V_50 ] [ V_15 ] ,
V_56 -> V_134 [ V_50 ] [ V_15 ] ) ;
F_52 ( & V_56 -> V_115 ) ;
return V_37 ;
}
static T_4
F_82 ( struct V_18 * V_19 , struct V_147 * V_45 , char * V_148 )
{
struct V_55 * V_56 = F_49 ( V_19 ) ;
struct V_26 * V_149 = F_58 ( V_45 ) ;
return sprintf ( V_148 , L_4 , V_56 -> V_136 [ V_149 -> V_50 ] * 1000 ) ;
}
static T_4
F_83 ( struct V_18 * V_19 , struct V_147 * V_45 ,
const char * V_148 , T_5 V_37 )
{
struct V_55 * V_56 = F_45 ( V_19 ) ;
struct V_26 * V_149 = F_58 ( V_45 ) ;
int V_15 = V_149 -> V_50 ;
long V_3 ;
int V_34 ;
V_34 = F_80 ( V_148 , 10 , & V_3 ) ;
if ( V_34 < 0 )
return V_34 ;
V_3 = F_14 ( F_21 ( V_3 , 1000 ) , - 128 , 127 ) ;
F_50 ( & V_56 -> V_115 ) ;
V_56 -> V_136 [ V_15 ] = V_3 ;
F_32 ( V_56 , V_56 -> V_137 [ V_15 ] , V_3 ) ;
F_52 ( & V_56 -> V_115 ) ;
return V_37 ;
}
static T_4
F_84 ( struct V_18 * V_19 , struct V_147 * V_45 , char * V_148 )
{
struct V_55 * V_56 = F_49 ( V_19 ) ;
struct V_26 * V_149 = F_58 ( V_45 ) ;
int V_15 = V_149 -> V_50 ;
return sprintf ( V_148 , L_4 , ( int ) V_56 -> V_170 [ V_15 ] ) ;
}
static T_4
F_85 ( struct V_18 * V_19 , struct V_147 * V_45 ,
const char * V_148 , T_5 V_37 )
{
struct V_55 * V_56 = F_49 ( V_19 ) ;
struct V_26 * V_149 = F_58 ( V_45 ) ;
int V_15 = V_149 -> V_50 ;
unsigned long V_3 ;
int V_34 ;
T_1 V_171 , V_172 , V_173 , V_174 ;
V_34 = F_56 ( V_148 , 10 , & V_3 ) ;
if ( V_34 < 0 )
return V_34 ;
if ( V_3 != 1 && V_3 != 3 && V_3 != 4 )
return - V_38 ;
F_50 ( & V_56 -> V_115 ) ;
V_56 -> V_170 [ V_15 ] = V_3 ;
V_173 = 0x02 << V_15 ;
V_174 = V_56 -> V_175 << V_15 ;
V_171 = F_30 ( V_56 , V_56 -> V_176 ) & ~ V_173 ;
V_172 = F_30 ( V_56 , V_56 -> V_177 ) & ~ V_174 ;
switch ( V_3 ) {
case 1 :
V_171 |= V_173 ;
V_172 |= V_174 ;
break;
case 3 :
V_171 |= V_174 ;
break;
case 4 :
break;
}
F_32 ( V_56 , V_56 -> V_176 , V_171 ) ;
F_32 ( V_56 , V_56 -> V_177 , V_172 ) ;
F_52 ( & V_56 -> V_115 ) ;
return V_37 ;
}
static T_6 F_86 ( struct V_162 * V_54 ,
struct V_30 * V_45 , int V_50 )
{
struct V_18 * V_19 = F_66 ( V_54 , struct V_18 , V_54 ) ;
struct V_55 * V_56 = F_45 ( V_19 ) ;
int V_134 = V_50 / 10 ;
int V_15 = V_50 % 10 ;
if ( ! ( V_56 -> V_132 & ( 1 << V_134 ) ) )
return 0 ;
if ( V_15 == 2 && F_59 ( V_56 , V_134 , V_56 -> V_155 ) < 0 )
return 0 ;
if ( V_15 == 3 && F_59 ( V_56 , V_134 , V_56 -> V_160 ) < 0 )
return 0 ;
if ( V_15 == 4 && ! V_56 -> V_133 [ 1 ] [ V_134 ] )
return 0 ;
if ( V_15 == 5 && ! V_56 -> V_133 [ 2 ] [ V_134 ] )
return 0 ;
if ( V_15 == 6 && ! V_56 -> V_133 [ 3 ] [ V_134 ] )
return 0 ;
if ( V_15 == 7 && ! V_56 -> V_133 [ 4 ] [ V_134 ] )
return 0 ;
if ( V_15 > 7 && ! ( V_56 -> V_135 & ( 1 << V_134 ) ) )
return 0 ;
return V_45 -> V_10 ;
}
static T_4
F_87 ( struct V_18 * V_19 , struct V_147 * V_45 , char * V_148 )
{
struct V_55 * V_56 = F_49 ( V_19 ) ;
struct V_26 * V_149 = F_58 ( V_45 ) ;
return sprintf ( V_148 , L_4 , ! V_56 -> V_85 [ V_149 -> V_50 ] ) ;
}
static T_4
F_88 ( struct V_18 * V_19 , struct V_147 * V_45 ,
const char * V_148 , T_5 V_37 )
{
struct V_55 * V_56 = F_45 ( V_19 ) ;
struct V_26 * V_149 = F_58 ( V_45 ) ;
int V_15 = V_149 -> V_50 ;
unsigned long V_3 ;
int V_34 ;
T_1 V_2 ;
V_34 = F_56 ( V_148 , 10 , & V_3 ) ;
if ( V_34 < 0 )
return V_34 ;
if ( V_3 > 1 )
return - V_38 ;
if ( V_56 -> V_83 [ V_15 ] == 0 ) {
if ( V_3 )
return - V_38 ;
return V_37 ;
}
F_50 ( & V_56 -> V_115 ) ;
V_56 -> V_85 [ V_15 ] = V_3 ;
V_2 = F_30 ( V_56 , V_56 -> V_83 [ V_15 ] ) ;
V_2 &= ~ V_56 -> V_84 [ V_15 ] ;
if ( V_3 )
V_2 |= V_56 -> V_84 [ V_15 ] ;
F_32 ( V_56 , V_56 -> V_83 [ V_15 ] , V_2 ) ;
F_52 ( & V_56 -> V_115 ) ;
return V_37 ;
}
static T_4
F_89 ( struct V_18 * V_19 , struct V_147 * V_45 , char * V_148 )
{
struct V_55 * V_56 = F_49 ( V_19 ) ;
struct V_28 * V_149 = F_54 ( V_45 ) ;
int V_15 = V_149 -> V_15 ;
int V_50 = V_149 -> V_50 ;
int V_9 ;
if ( V_50 == 0 && V_56 -> V_8 [ V_15 ] > V_178 )
V_9 = F_30 ( V_56 , V_56 -> V_179 [ V_15 ] ) ;
else
V_9 = V_56 -> V_9 [ V_50 ] [ V_15 ] ;
return sprintf ( V_148 , L_4 , V_9 ) ;
}
static T_4
F_90 ( struct V_18 * V_19 , struct V_147 * V_45 , const char * V_148 ,
T_5 V_37 )
{
struct V_55 * V_56 = F_45 ( V_19 ) ;
struct V_28 * V_149 = F_54 ( V_45 ) ;
int V_15 = V_149 -> V_15 ;
int V_50 = V_149 -> V_50 ;
unsigned long V_3 ;
int V_180 [ 7 ] = { 0 , 1 , 1 , V_56 -> V_9 [ 2 ] [ V_15 ] , 0 , 0 , 0 } ;
int V_181 [ 7 ]
= { 255 , 255 , V_56 -> V_9 [ 3 ] [ V_15 ] ? : 255 , 255 , 255 , 255 , 255 } ;
int V_34 ;
T_1 V_2 ;
V_34 = F_56 ( V_148 , 10 , & V_3 ) ;
if ( V_34 < 0 )
return V_34 ;
V_3 = F_14 ( V_3 , V_180 [ V_50 ] , V_181 [ V_50 ] ) ;
F_50 ( & V_56 -> V_115 ) ;
V_56 -> V_9 [ V_50 ] [ V_15 ] = V_3 ;
F_32 ( V_56 , V_56 -> V_87 [ V_50 ] [ V_15 ] , V_3 ) ;
if ( V_50 == 2 ) {
V_2 = F_30 ( V_56 , V_56 -> V_93 [ V_15 ] ) ;
V_2 &= 0x7f ;
if ( V_3 )
V_2 |= 0x80 ;
F_32 ( V_56 , V_56 -> V_93 [ V_15 ] , V_2 ) ;
}
F_52 ( & V_56 -> V_115 ) ;
return V_37 ;
}
static int F_91 ( struct V_55 * V_56 , int V_15 )
{
int V_35 ;
for ( V_35 = 0 ; V_35 < V_56 -> V_107 - 1 ; V_35 ++ ) {
if ( V_56 -> V_109 [ V_15 ] [ V_35 ] > V_56 -> V_109 [ V_15 ] [ V_35 + 1 ] )
return - V_38 ;
}
for ( V_35 = 0 ; V_35 < V_56 -> V_107 - 1 ; V_35 ++ ) {
if ( V_56 -> V_108 [ V_15 ] [ V_35 ] > V_56 -> V_108 [ V_15 ] [ V_35 + 1 ] )
return - V_38 ;
}
if ( V_56 -> V_108 [ V_15 ] [ V_56 -> V_107 ] ) {
if ( V_56 -> V_109 [ V_15 ] [ V_56 -> V_107 - 1 ] >
V_56 -> V_109 [ V_15 ] [ V_56 -> V_107 ] ||
V_56 -> V_108 [ V_15 ] [ V_56 -> V_107 - 1 ] >
V_56 -> V_108 [ V_15 ] [ V_56 -> V_107 ] )
return - V_38 ;
}
return 0 ;
}
static void F_92 ( struct V_55 * V_56 , int V_15 )
{
T_1 V_2 ;
switch ( V_56 -> V_8 [ V_15 ] ) {
case V_11 :
case V_178 :
break;
case V_89 :
V_2 = F_30 ( V_56 , V_56 -> V_86 [ V_15 ] ) ;
V_2 = ( V_2 & ~ V_56 -> V_182 ) |
( V_56 -> V_90 [ V_15 ] & V_56 -> V_182 ) ;
F_32 ( V_56 , V_56 -> V_86 [ V_15 ] , V_2 ) ;
F_32 ( V_56 , V_56 -> V_102 [ V_15 ] ,
V_56 -> V_106 [ V_15 ] & 0xff ) ;
if ( V_56 -> V_91 ) {
V_2 = ( V_56 -> V_106 [ V_15 ] >> 8 ) & 0x0f ;
V_2 |= ( V_56 -> V_90 [ V_15 ] & 0x38 ) << 1 ;
F_32 ( V_56 ,
V_56 -> V_91 [ V_15 ] ,
V_2 ) ;
}
break;
case V_104 :
F_32 ( V_56 , V_56 -> V_102 [ V_15 ] ,
V_56 -> V_103 [ V_15 ] ) ;
default:
V_2 = F_30 ( V_56 , V_56 -> V_86 [ V_15 ] ) ;
V_2 = ( V_2 & ~ V_56 -> V_182 ) |
V_56 -> V_88 [ 0 ] [ V_15 ] ;
F_32 ( V_56 , V_56 -> V_86 [ V_15 ] , V_2 ) ;
break;
}
}
static T_4
F_93 ( struct V_18 * V_19 , struct V_147 * V_45 , char * V_148 )
{
struct V_55 * V_56 = F_49 ( V_19 ) ;
struct V_26 * V_149 = F_58 ( V_45 ) ;
return sprintf ( V_148 , L_4 , V_56 -> V_8 [ V_149 -> V_50 ] ) ;
}
static T_4
F_94 ( struct V_18 * V_19 , struct V_147 * V_45 ,
const char * V_148 , T_5 V_37 )
{
struct V_55 * V_56 = F_45 ( V_19 ) ;
struct V_26 * V_149 = F_58 ( V_45 ) ;
int V_15 = V_149 -> V_50 ;
unsigned long V_3 ;
int V_34 ;
T_2 V_2 ;
V_34 = F_56 ( V_148 , 10 , & V_3 ) ;
if ( V_34 < 0 )
return V_34 ;
if ( V_3 > V_183 )
return - V_38 ;
if ( V_3 == V_184 && V_56 -> V_57 != V_59 )
return - V_38 ;
if ( V_3 == V_183 && F_91 ( V_56 , V_15 ) ) {
F_95 ( V_19 , L_10 ) ;
F_95 ( V_19 , L_11 ) ;
return - V_38 ;
}
F_50 ( & V_56 -> V_115 ) ;
V_56 -> V_8 [ V_15 ] = V_3 ;
if ( V_3 == V_11 ) {
V_56 -> V_9 [ 0 ] [ V_15 ] = 255 ;
F_32 ( V_56 , V_56 -> V_87 [ 0 ] [ V_15 ] , 255 ) ;
}
F_92 ( V_56 , V_15 ) ;
V_2 = F_30 ( V_56 , V_56 -> V_86 [ V_15 ] ) ;
V_2 &= 0x0f ;
V_2 |= F_11 ( V_3 ) << 4 ;
F_32 ( V_56 , V_56 -> V_86 [ V_15 ] , V_2 ) ;
F_52 ( & V_56 -> V_115 ) ;
return V_37 ;
}
static T_4
F_96 ( struct V_55 * V_56 , char * V_148 , int V_153 )
{
int V_35 , V_185 = 0 ;
for ( V_35 = 0 ; V_35 < V_131 ; V_35 ++ ) {
if ( ! ( V_56 -> V_132 & ( 1 << V_35 ) ) )
continue;
if ( V_153 == V_56 -> V_152 [ V_35 ] ) {
V_185 = V_35 + 1 ;
break;
}
}
return sprintf ( V_148 , L_4 , V_185 ) ;
}
static T_4
F_97 ( struct V_18 * V_19 , struct V_147 * V_45 , char * V_148 )
{
struct V_55 * V_56 = F_49 ( V_19 ) ;
struct V_26 * V_149 = F_58 ( V_45 ) ;
int V_50 = V_149 -> V_50 ;
return F_96 ( V_56 , V_148 , V_56 -> V_94 [ V_50 ] ) ;
}
static T_4
F_98 ( struct V_18 * V_19 , struct V_147 * V_45 ,
const char * V_148 , T_5 V_37 )
{
struct V_55 * V_56 = F_49 ( V_19 ) ;
struct V_26 * V_149 = F_58 ( V_45 ) ;
int V_15 = V_149 -> V_50 ;
unsigned long V_3 ;
int V_34 , V_2 , V_153 ;
V_34 = F_56 ( V_148 , 10 , & V_3 ) ;
if ( V_34 < 0 )
return V_34 ;
if ( V_3 == 0 || V_3 > V_131 )
return - V_38 ;
if ( ! ( V_56 -> V_132 & ( 1 << ( V_3 - 1 ) ) ) || ! V_56 -> V_152 [ V_3 - 1 ] )
return - V_38 ;
F_50 ( & V_56 -> V_115 ) ;
V_153 = V_56 -> V_152 [ V_3 - 1 ] ;
V_56 -> V_94 [ V_15 ] = V_153 ;
V_2 = F_30 ( V_56 , V_56 -> V_93 [ V_15 ] ) ;
V_2 &= 0xe0 ;
V_2 |= V_153 ;
F_32 ( V_56 , V_56 -> V_93 [ V_15 ] , V_2 ) ;
F_52 ( & V_56 -> V_115 ) ;
return V_37 ;
}
static T_4
F_99 ( struct V_18 * V_19 , struct V_147 * V_45 ,
char * V_148 )
{
struct V_55 * V_56 = F_49 ( V_19 ) ;
struct V_26 * V_149 = F_58 ( V_45 ) ;
int V_50 = V_149 -> V_50 ;
return F_96 ( V_56 , V_148 ,
V_56 -> V_96 [ V_50 ] ) ;
}
static T_4
F_100 ( struct V_18 * V_19 , struct V_147 * V_45 ,
const char * V_148 , T_5 V_37 )
{
struct V_55 * V_56 = F_49 ( V_19 ) ;
struct V_26 * V_149 = F_58 ( V_45 ) ;
int V_15 = V_149 -> V_50 ;
unsigned long V_3 ;
int V_34 , V_2 , V_153 ;
V_34 = F_56 ( V_148 , 10 , & V_3 ) ;
if ( V_34 < 0 )
return V_34 ;
if ( V_3 > V_131 )
return - V_38 ;
if ( V_3 && ( ! ( V_56 -> V_132 & ( 1 << ( V_3 - 1 ) ) ) ||
! V_56 -> V_152 [ V_3 - 1 ] ) )
return - V_38 ;
F_50 ( & V_56 -> V_115 ) ;
if ( V_3 ) {
V_153 = V_56 -> V_152 [ V_3 - 1 ] ;
V_56 -> V_96 [ V_15 ] = V_153 ;
V_2 = F_30 ( V_56 , V_56 -> V_95 [ V_15 ] ) ;
V_2 &= 0xe0 ;
V_2 |= ( V_153 | 0x80 ) ;
F_32 ( V_56 , V_56 -> V_95 [ V_15 ] , V_2 ) ;
} else {
V_56 -> V_96 [ V_15 ] = 0 ;
V_2 = F_30 ( V_56 , V_56 -> V_95 [ V_15 ] ) ;
V_2 &= 0x7f ;
F_32 ( V_56 , V_56 -> V_95 [ V_15 ] , V_2 ) ;
}
F_52 ( & V_56 -> V_115 ) ;
return V_37 ;
}
static T_4
F_101 ( struct V_18 * V_19 , struct V_147 * V_45 , char * V_148 )
{
struct V_55 * V_56 = F_49 ( V_19 ) ;
struct V_26 * V_149 = F_58 ( V_45 ) ;
return sprintf ( V_148 , L_4 , V_56 -> V_103 [ V_149 -> V_50 ] * 1000 ) ;
}
static T_4
F_102 ( struct V_18 * V_19 , struct V_147 * V_45 ,
const char * V_148 , T_5 V_37 )
{
struct V_55 * V_56 = F_45 ( V_19 ) ;
struct V_26 * V_149 = F_58 ( V_45 ) ;
int V_15 = V_149 -> V_50 ;
unsigned long V_3 ;
int V_34 ;
V_34 = F_56 ( V_148 , 10 , & V_3 ) ;
if ( V_34 < 0 )
return V_34 ;
V_3 = F_14 ( F_21 ( V_3 , 1000 ) , 0 ,
V_56 -> V_105 ) ;
F_50 ( & V_56 -> V_115 ) ;
V_56 -> V_103 [ V_15 ] = V_3 ;
F_92 ( V_56 , V_15 ) ;
F_52 ( & V_56 -> V_115 ) ;
return V_37 ;
}
static T_4
F_103 ( struct V_18 * V_19 , struct V_147 * V_45 , char * V_148 )
{
struct V_55 * V_56 = F_49 ( V_19 ) ;
struct V_26 * V_149 = F_58 ( V_45 ) ;
int V_15 = V_149 -> V_50 ;
return sprintf ( V_148 , L_4 ,
F_17 ( V_56 -> V_106 [ V_15 ] ,
V_56 -> V_72 [ V_15 ] ) ) ;
}
static T_4
F_104 ( struct V_18 * V_19 , struct V_147 * V_45 ,
const char * V_148 , T_5 V_37 )
{
struct V_55 * V_56 = F_45 ( V_19 ) ;
struct V_26 * V_149 = F_58 ( V_45 ) ;
int V_15 = V_149 -> V_50 ;
unsigned long V_3 ;
int V_34 ;
T_2 V_186 ;
V_34 = F_56 ( V_148 , 10 , & V_3 ) ;
if ( V_34 < 0 )
return V_34 ;
V_3 = F_14 ( V_3 , 0 , 1350000U ) ;
V_186 = F_18 ( V_3 , V_56 -> V_72 [ V_15 ] ) ;
F_50 ( & V_56 -> V_115 ) ;
V_56 -> V_106 [ V_15 ] = V_186 ;
F_92 ( V_56 , V_15 ) ;
F_52 ( & V_56 -> V_115 ) ;
return V_37 ;
}
static T_4
F_105 ( struct V_18 * V_19 , struct V_147 * V_45 ,
char * V_148 )
{
struct V_55 * V_56 = F_49 ( V_19 ) ;
struct V_28 * V_149 = F_54 ( V_45 ) ;
int V_15 = V_149 -> V_15 ;
int V_50 = V_149 -> V_50 ;
return sprintf ( V_148 , L_4 , V_56 -> V_88 [ V_50 ] [ V_15 ] * 1000 ) ;
}
static T_4
F_106 ( struct V_18 * V_19 , struct V_147 * V_45 ,
const char * V_148 , T_5 V_37 )
{
struct V_55 * V_56 = F_45 ( V_19 ) ;
struct V_28 * V_149 = F_54 ( V_45 ) ;
int V_15 = V_149 -> V_15 ;
int V_50 = V_149 -> V_50 ;
unsigned long V_3 ;
int V_34 ;
V_34 = F_56 ( V_148 , 10 , & V_3 ) ;
if ( V_34 < 0 )
return V_34 ;
V_3 = F_14 ( F_21 ( V_3 , 1000 ) , 0 , V_56 -> V_182 ) ;
F_50 ( & V_56 -> V_115 ) ;
V_56 -> V_88 [ V_50 ] [ V_15 ] = V_3 ;
if ( V_50 )
F_92 ( V_56 , V_15 ) ;
else
F_32 ( V_56 ,
V_56 -> V_92 [ V_15 ] ,
V_3 ) ;
F_52 ( & V_56 -> V_115 ) ;
return V_37 ;
}
static T_4
F_107 ( struct V_18 * V_19 , struct V_147 * V_45 ,
char * V_148 )
{
struct V_55 * V_56 = F_49 ( V_19 ) ;
struct V_26 * V_149 = F_58 ( V_45 ) ;
int V_15 = V_149 -> V_50 ;
int V_187 = V_56 -> V_106 [ V_15 ] - V_56 -> V_90 [ V_15 ] ;
int V_188 = V_56 -> V_106 [ V_15 ] + V_56 -> V_90 [ V_15 ] ;
int V_189 ;
if ( V_187 <= 0 )
V_187 = 1 ;
if ( V_188 > 0xffff )
V_188 = 0xffff ;
if ( V_188 < V_187 )
V_188 = V_187 ;
V_189 = ( F_17 ( V_187 , V_56 -> V_72 [ V_15 ] )
- F_17 ( V_188 , V_56 -> V_72 [ V_15 ] ) ) / 2 ;
return sprintf ( V_148 , L_4 , V_189 ) ;
}
static T_4
F_108 ( struct V_18 * V_19 , struct V_147 * V_45 ,
const char * V_148 , T_5 V_37 )
{
struct V_55 * V_56 = F_45 ( V_19 ) ;
struct V_26 * V_149 = F_58 ( V_45 ) ;
int V_15 = V_149 -> V_50 ;
unsigned long V_3 ;
int V_34 ;
int V_187 , V_188 ;
V_34 = F_56 ( V_148 , 10 , & V_3 ) ;
if ( V_34 < 0 )
return V_34 ;
V_188 = F_17 ( V_56 -> V_106 [ V_15 ] ,
V_56 -> V_72 [ V_15 ] ) + V_3 ;
V_187 = F_17 ( V_56 -> V_106 [ V_15 ] ,
V_56 -> V_72 [ V_15 ] ) - V_3 ;
if ( V_187 <= 0 )
V_187 = 1 ;
if ( V_188 < V_187 )
V_188 = V_187 ;
V_3 = ( F_18 ( V_187 , V_56 -> V_72 [ V_15 ] ) -
F_18 ( V_188 , V_56 -> V_72 [ V_15 ] ) ) / 2 ;
V_3 = F_14 ( V_3 , 0 , V_56 -> V_190 ) ;
F_50 ( & V_56 -> V_115 ) ;
V_56 -> V_90 [ V_15 ] = V_3 ;
F_92 ( V_56 , V_15 ) ;
F_52 ( & V_56 -> V_115 ) ;
return V_37 ;
}
static T_4
F_109 ( struct V_18 * V_19 , struct V_147 * V_45 , char * V_148 )
{
struct V_55 * V_56 = F_49 ( V_19 ) ;
struct V_28 * V_149 = F_54 ( V_45 ) ;
int V_15 = V_149 -> V_15 ;
int V_50 = V_149 -> V_50 ;
return sprintf ( V_148 , L_4 , V_56 -> V_97 [ V_50 ] [ V_15 ] * 1000 ) ;
}
static T_4
F_110 ( struct V_18 * V_19 , struct V_147 * V_45 ,
const char * V_148 , T_5 V_37 )
{
struct V_55 * V_56 = F_45 ( V_19 ) ;
struct V_28 * V_149 = F_54 ( V_45 ) ;
int V_15 = V_149 -> V_15 ;
int V_50 = V_149 -> V_50 ;
unsigned long V_3 ;
int V_34 ;
V_34 = F_56 ( V_148 , 10 , & V_3 ) ;
if ( V_34 < 0 )
return V_34 ;
V_3 = F_14 ( F_21 ( V_3 , 1000 ) , 0 , 255 ) ;
F_50 ( & V_56 -> V_115 ) ;
V_56 -> V_97 [ V_50 ] [ V_15 ] = V_3 ;
F_32 ( V_56 , V_56 -> V_98 [ V_50 ] [ V_15 ] , V_3 ) ;
F_52 ( & V_56 -> V_115 ) ;
return V_37 ;
}
static T_4
F_111 ( struct V_18 * V_19 , struct V_147 * V_45 , char * V_148 )
{
struct V_55 * V_56 = F_49 ( V_19 ) ;
struct V_28 * V_149 = F_54 ( V_45 ) ;
int V_15 = V_149 -> V_15 ;
int V_50 = V_149 -> V_50 ;
return sprintf ( V_148 , L_4 ,
F_12 ( V_56 -> V_100 [ V_50 ] [ V_15 ] ,
V_56 -> V_85 [ V_15 ] ) ) ;
}
static T_4
F_112 ( struct V_18 * V_19 , struct V_147 * V_45 ,
const char * V_148 , T_5 V_37 )
{
struct V_55 * V_56 = F_45 ( V_19 ) ;
struct V_28 * V_149 = F_54 ( V_45 ) ;
int V_15 = V_149 -> V_15 ;
int V_50 = V_149 -> V_50 ;
unsigned long V_3 ;
int V_34 ;
V_34 = F_56 ( V_148 , 10 , & V_3 ) ;
if ( V_34 < 0 )
return V_34 ;
V_3 = F_13 ( V_3 , V_56 -> V_85 [ V_15 ] ) ;
F_50 ( & V_56 -> V_115 ) ;
V_56 -> V_100 [ V_50 ] [ V_15 ] = V_3 ;
F_32 ( V_56 , V_56 -> V_101 [ V_50 ] [ V_15 ] , V_3 ) ;
F_52 ( & V_56 -> V_115 ) ;
return V_37 ;
}
static T_4
F_113 ( struct V_18 * V_19 , struct V_147 * V_45 , char * V_148 )
{
struct V_55 * V_56 = F_45 ( V_19 ) ;
return sprintf ( V_148 , L_9 , V_56 -> V_43 ) ;
}
static T_4
F_114 ( struct V_18 * V_19 , struct V_147 * V_45 , char * V_148 )
{
struct V_55 * V_56 = F_49 ( V_19 ) ;
struct V_28 * V_149 = F_54 ( V_45 ) ;
return sprintf ( V_148 , L_4 , V_56 -> V_108 [ V_149 -> V_15 ] [ V_149 -> V_50 ] ) ;
}
static T_4
F_115 ( struct V_18 * V_19 , struct V_147 * V_45 ,
const char * V_148 , T_5 V_37 )
{
struct V_55 * V_56 = F_45 ( V_19 ) ;
struct V_28 * V_149 = F_54 ( V_45 ) ;
int V_15 = V_149 -> V_15 ;
int V_191 = V_149 -> V_50 ;
unsigned long V_3 ;
int V_34 ;
T_1 V_2 ;
V_34 = F_56 ( V_148 , 10 , & V_3 ) ;
if ( V_34 < 0 )
return V_34 ;
if ( V_3 > 255 )
return - V_38 ;
if ( V_191 == V_56 -> V_107 ) {
if ( V_56 -> V_57 != V_59 && ! V_3 )
return - V_38 ;
if ( V_56 -> V_57 != V_61 && V_3 )
V_3 = 0xff ;
}
F_50 ( & V_56 -> V_115 ) ;
V_56 -> V_108 [ V_15 ] [ V_191 ] = V_3 ;
if ( V_191 < V_56 -> V_107 ) {
F_32 ( V_56 ,
F_47 ( V_56 , V_15 , V_191 ) ,
V_56 -> V_108 [ V_15 ] [ V_191 ] ) ;
} else {
switch ( V_56 -> V_57 ) {
case V_59 :
V_2 = F_30 ( V_56 ,
V_111 [ V_15 ] ) ;
if ( V_3 )
V_2 |= 0x02 ;
else
V_2 &= ~ 0x02 ;
F_32 ( V_56 , V_111 [ V_15 ] ,
V_2 ) ;
break;
case V_60 :
break;
case V_58 :
case V_61 :
case V_62 :
F_32 ( V_56 , V_56 -> V_114 [ V_15 ] ,
V_3 ) ;
V_2 = F_30 ( V_56 ,
V_56 -> V_112 [ V_15 ] ) ;
if ( V_3 == 255 )
V_2 &= ~ V_56 -> V_113 ;
else
V_2 |= V_56 -> V_113 ;
F_32 ( V_56 ,
V_56 -> V_112 [ V_15 ] ,
V_2 ) ;
break;
}
}
F_52 ( & V_56 -> V_115 ) ;
return V_37 ;
}
static T_4
F_116 ( struct V_18 * V_19 , struct V_147 * V_45 , char * V_148 )
{
struct V_55 * V_56 = F_49 ( V_19 ) ;
struct V_28 * V_149 = F_54 ( V_45 ) ;
int V_15 = V_149 -> V_15 ;
int V_191 = V_149 -> V_50 ;
return sprintf ( V_148 , L_4 , V_56 -> V_109 [ V_15 ] [ V_191 ] * 1000 ) ;
}
static T_4
F_117 ( struct V_18 * V_19 , struct V_147 * V_45 ,
const char * V_148 , T_5 V_37 )
{
struct V_55 * V_56 = F_45 ( V_19 ) ;
struct V_28 * V_149 = F_54 ( V_45 ) ;
int V_15 = V_149 -> V_15 ;
int V_191 = V_149 -> V_50 ;
unsigned long V_3 ;
int V_34 ;
V_34 = F_56 ( V_148 , 10 , & V_3 ) ;
if ( V_34 )
return V_34 ;
if ( V_3 > 255000 )
return - V_38 ;
F_50 ( & V_56 -> V_115 ) ;
V_56 -> V_109 [ V_15 ] [ V_191 ] = F_21 ( V_3 , 1000 ) ;
if ( V_191 < V_56 -> V_107 ) {
F_32 ( V_56 ,
F_48 ( V_56 , V_15 , V_191 ) ,
V_56 -> V_109 [ V_15 ] [ V_191 ] ) ;
} else {
F_32 ( V_56 , V_56 -> V_110 [ V_15 ] ,
V_56 -> V_109 [ V_15 ] [ V_191 ] ) ;
}
F_52 ( & V_56 -> V_115 ) ;
return V_37 ;
}
static T_6 F_118 ( struct V_162 * V_54 ,
struct V_30 * V_45 , int V_50 )
{
struct V_18 * V_19 = F_66 ( V_54 , struct V_18 , V_54 ) ;
struct V_55 * V_56 = F_45 ( V_19 ) ;
int V_9 = V_50 / 36 ;
int V_15 = V_50 % 36 ;
if ( ! ( V_56 -> V_82 & ( 1 << V_9 ) ) )
return 0 ;
if ( V_15 == 19 && V_56 -> V_87 [ 3 ] == NULL )
return 0 ;
if ( V_15 == 20 && V_56 -> V_87 [ 4 ] == NULL )
return 0 ;
if ( V_15 == 21 && V_56 -> V_87 [ 6 ] == NULL )
return 0 ;
if ( V_15 >= 22 && V_15 <= 35 ) {
int V_192 = ( V_15 - 22 ) / 2 ;
if ( V_192 > V_56 -> V_107 )
return 0 ;
}
return V_45 -> V_10 ;
}
static T_4
F_119 ( struct V_18 * V_19 , struct V_147 * V_45 , char * V_148 )
{
struct V_55 * V_56 = F_45 ( V_19 ) ;
return sprintf ( V_148 , L_4 , F_120 ( V_56 -> V_193 , V_56 -> V_194 ) ) ;
}
static T_4
F_121 ( struct V_18 * V_19 , struct V_147 * V_45 ,
const char * V_148 , T_5 V_37 )
{
struct V_55 * V_56 = F_45 ( V_19 ) ;
int V_15 = F_58 ( V_45 ) -> V_50 - V_195 ;
unsigned long V_3 ;
T_1 V_2 ;
int V_196 ;
if ( F_56 ( V_148 , 10 , & V_3 ) || V_3 != 0 )
return - V_38 ;
F_50 ( & V_56 -> V_115 ) ;
V_196 = F_6 ( V_56 -> V_197 ) ;
if ( V_196 ) {
V_37 = V_196 ;
goto error;
}
F_5 ( V_56 -> V_197 , V_198 ) ;
V_2 = F_3 ( V_56 -> V_197 , V_199 [ V_15 ] ) ;
V_2 |= V_200 [ V_15 ] ;
F_1 ( V_56 -> V_197 , V_199 [ V_15 ] , V_2 ) ;
V_2 &= ~ V_200 [ V_15 ] ;
F_1 ( V_56 -> V_197 , V_199 [ V_15 ] , V_2 ) ;
F_8 ( V_56 -> V_197 ) ;
V_56 -> V_119 = false ;
error:
F_52 ( & V_56 -> V_115 ) ;
return V_37 ;
}
static T_6 F_122 ( struct V_162 * V_54 ,
struct V_30 * V_45 , int V_50 )
{
struct V_18 * V_19 = F_66 ( V_54 , struct V_18 , V_54 ) ;
struct V_55 * V_56 = F_45 ( V_19 ) ;
if ( V_50 == 1 && ! V_56 -> V_201 )
return 0 ;
if ( V_50 == 2 || V_50 == 3 ) {
if ( V_56 -> V_150 [ V_195 + V_50 - 2 ] < 0 )
return 0 ;
}
if ( V_50 == 4 || V_50 == 5 ) {
if ( V_56 -> V_158 [ V_195 + V_50 - 4 ] < 0 )
return 0 ;
}
return V_45 -> V_10 ;
}
static void F_123 ( struct V_18 * V_19 )
{
struct V_55 * V_56 = F_45 ( V_19 ) ;
if ( V_56 -> V_202 )
F_124 ( & V_19 -> V_54 , V_56 -> V_202 ) ;
if ( V_56 -> V_203 )
F_124 ( & V_19 -> V_54 , V_56 -> V_203 ) ;
if ( V_56 -> V_204 )
F_124 ( & V_19 -> V_54 , V_56 -> V_204 ) ;
if ( V_56 -> V_205 )
F_124 ( & V_19 -> V_54 , V_56 -> V_205 ) ;
F_124 ( & V_19 -> V_54 , & V_206 ) ;
}
static inline void F_125 ( struct V_55 * V_56 )
{
int V_35 ;
T_1 V_207 , V_172 ;
if ( V_56 -> V_208 ) {
V_207 = F_30 ( V_56 , V_56 -> V_208 ) ;
if ( ! ( V_207 & 0x01 ) )
F_32 ( V_56 , V_56 -> V_208 , V_207 | 0x01 ) ;
}
for ( V_35 = 0 ; V_35 < V_131 ; V_35 ++ ) {
if ( ! ( V_56 -> V_132 & ( 1 << V_35 ) ) )
continue;
if ( ! V_56 -> V_209 [ V_35 ] )
continue;
V_207 = F_30 ( V_56 , V_56 -> V_209 [ V_35 ] ) ;
if ( V_207 & 0x01 )
F_32 ( V_56 , V_56 -> V_209 [ V_35 ] ,
V_207 & 0xfe ) ;
}
V_207 = F_30 ( V_56 , V_56 -> V_176 ) ;
if ( ! ( V_207 & 0x01 ) )
F_32 ( V_56 , V_56 -> V_176 , V_207 | 0x01 ) ;
V_172 = F_30 ( V_56 , V_56 -> V_177 ) ;
for ( V_35 = 0 ; V_35 < V_56 -> V_210 ; V_35 ++ ) {
if ( ! ( V_56 -> V_135 & ( 1 << V_35 ) ) )
continue;
if ( ( V_207 & ( V_56 -> V_175 << V_35 ) ) )
V_56 -> V_170 [ V_35 ]
= 3 - ( ( V_172 >> V_35 ) & V_56 -> V_175 ) ;
else
V_56 -> V_170 [ V_35 ] = 4 ;
}
}
static void
F_126 ( struct V_55 * V_56 )
{
bool V_211 , V_212 , V_213 , V_214 , V_215 ;
bool V_216 , V_217 , V_218 , V_219 ;
int V_197 = V_56 -> V_197 ;
int V_220 ;
if ( V_56 -> V_57 == V_59 ) {
V_220 = F_3 ( V_197 , 0x2c ) ;
V_211 = V_220 & ( 1 << 6 ) ;
V_216 = V_220 & ( 1 << 7 ) ;
V_212 = ! ( F_3 ( V_197 , 0x2A ) & 0x80 ) ;
V_213 = false ;
V_214 = false ;
V_215 = false ;
V_217 = false ;
V_218 = false ;
V_219 = false ;
} else if ( V_56 -> V_57 == V_60 ) {
bool V_221 = F_3 ( V_197 , 0x27 ) & 0x80 ;
F_5 ( V_197 , V_222 ) ;
V_220 = F_3 ( V_197 , V_223 ) ;
if ( V_220 & 0x80 )
V_211 = V_221 ;
else
V_211 = ! ( F_3 ( V_197 , 0x24 ) & 0x40 ) ;
if ( V_220 & 0x40 )
V_212 = V_221 ;
else
V_212 = F_3 ( V_197 , 0x1C ) & 0x01 ;
if ( V_220 & 0x20 )
V_214 = V_221 ;
else
V_214 = F_3 ( V_197 , 0x1C ) & 0x02 ;
V_213 = V_212 ;
V_215 = false ;
V_216 = V_211 ;
V_217 = false ;
V_218 = false ;
V_219 = false ;
} else if ( V_56 -> V_57 == V_58 ) {
V_220 = F_3 ( V_197 , 0x24 ) ;
V_211 = ! ( V_220 & 0x80 ) ;
V_216 = V_220 & 0x08 ;
V_212 = false ;
V_213 = false ;
V_214 = false ;
V_215 = false ;
V_217 = false ;
V_218 = false ;
V_219 = false ;
} else {
V_220 = F_3 ( V_197 , 0x1c ) ;
V_211 = ! ( V_220 & ( 1 << 5 ) ) ;
V_212 = ! ( V_220 & ( 1 << 6 ) ) ;
V_214 = ! ( V_220 & ( 1 << 7 ) ) ;
V_216 = ! ( V_220 & ( 1 << 0 ) ) ;
V_217 = ! ( V_220 & ( 1 << 1 ) ) ;
V_218 = ! ( V_220 & ( 1 << 2 ) ) ;
V_213 = V_212 ;
if ( V_56 -> V_57 == V_62 ) {
V_220 = F_3 ( V_197 , 0x2d ) ;
V_215 = ( V_220 & ( 1 << 1 ) ) ;
V_219 = ( V_220 & ( 1 << 0 ) ) ;
} else {
V_215 = false ;
V_219 = false ;
}
}
V_56 -> V_74 = 0x03 | ( V_211 << 2 ) | ( V_212 << 3 ) |
( V_214 << 4 ) | ( V_215 << 5 ) ;
V_56 -> V_77 = 0x03 | ( V_211 << 2 ) | ( V_213 << 3 ) |
( V_214 << 4 ) ;
V_56 -> V_82 = 0x03 | ( V_216 << 2 ) | ( V_217 << 3 ) |
( V_218 << 4 ) | ( V_219 << 5 ) ;
}
static void F_127 ( struct V_55 * V_56 , const T_2 * V_224 ,
int * V_225 , int * V_226 )
{
int V_35 ;
T_1 V_153 ;
for ( V_35 = 0 ; V_35 < V_56 -> V_81 && * V_225 ; V_35 ++ ) {
int V_50 ;
if ( ! V_224 [ V_35 ] )
continue;
V_153 = F_30 ( V_56 , V_224 [ V_35 ] ) ;
V_153 &= 0x1f ;
if ( ! V_153 || ( * V_226 & ( 1 << V_153 ) ) )
continue;
if ( V_153 >= V_56 -> V_227 ||
! strlen ( V_56 -> V_169 [ V_153 ] ) )
continue;
V_50 = F_128 ( * V_225 ) ;
F_32 ( V_56 , V_56 -> V_154 [ V_50 ] , V_153 ) ;
* V_225 &= ~ ( 1 << V_50 ) ;
* V_226 |= 1 << V_153 ;
}
}
static int F_129 ( struct V_228 * V_229 )
{
struct V_18 * V_19 = & V_229 -> V_19 ;
struct V_230 * V_231 = F_130 ( V_19 ) ;
struct V_55 * V_56 ;
struct V_232 * V_68 ;
int V_35 , V_49 , V_34 = 0 ;
int V_153 , V_226 , V_225 ;
const T_2 * V_133 , * V_233 , * V_234 , * V_209 ;
const T_2 * V_235 , * V_236 ;
const T_2 * V_237 = NULL , * V_238 = NULL ;
int V_239 ;
T_1 V_240 ;
struct V_17 * V_23 ;
V_68 = F_131 ( V_229 , V_241 , 0 ) ;
if ( ! F_132 ( & V_229 -> V_19 , V_68 -> V_242 , V_243 ,
V_6 ) )
return - V_7 ;
V_56 = F_25 ( & V_229 -> V_19 , sizeof( struct V_55 ) ,
V_40 ) ;
if ( ! V_56 )
return - V_41 ;
V_56 -> V_57 = V_231 -> V_57 ;
V_56 -> V_197 = V_231 -> V_197 ;
V_56 -> V_65 = V_68 -> V_242 ;
F_133 ( & V_56 -> V_115 ) ;
V_56 -> V_43 = V_244 [ V_56 -> V_57 ] ;
V_56 -> V_63 = 0xff ;
F_134 ( V_229 , V_56 ) ;
switch ( V_56 -> V_57 ) {
case V_58 :
V_56 -> V_120 = 9 ;
V_56 -> V_81 = 3 ;
V_56 -> V_107 = 4 ;
V_56 -> V_210 = 3 ;
V_56 -> V_155 = 6 ;
V_56 -> V_160 = 6 ;
V_56 -> V_127 = F_16 ;
V_56 -> V_163 = F_16 ;
V_56 -> V_169 = V_245 ;
V_56 -> V_227 = F_40 ( V_245 ) ;
V_56 -> V_176 = V_246 ;
V_56 -> V_177 = V_247 ;
V_56 -> V_175 = V_248 ;
V_56 -> V_123 = V_249 ;
V_56 -> V_124 [ 0 ] = V_250 ;
V_56 -> V_124 [ 1 ] = V_251 ;
V_56 -> V_102 = V_252 ;
V_56 -> V_126 = V_253 ;
V_56 -> V_86 = V_254 ;
V_56 -> V_78 = V_255 ;
V_56 -> V_129 = V_256 ;
V_56 -> V_130 = V_257 ;
V_56 -> V_101 [ 0 ] = V_258 ;
V_56 -> V_101 [ 1 ] = V_259 ;
V_56 -> V_101 [ 2 ] = V_260 ;
V_56 -> V_87 [ 0 ] = V_261 ;
V_56 -> V_87 [ 1 ] = V_262 ;
V_56 -> V_87 [ 2 ] = V_263 ;
V_56 -> V_87 [ 5 ] = V_264 ;
V_56 -> V_87 [ 6 ] = V_265 ;
V_56 -> V_179 = V_266 ;
V_56 -> V_83 = V_267 ;
V_56 -> V_84 = V_268 ;
V_56 -> V_269 = V_270 ;
V_56 -> V_271 = V_272 ;
V_56 -> V_110 = V_273 ;
V_56 -> V_92
= V_274 ;
V_56 -> V_112 = V_275 ;
V_56 -> V_113
= V_276 ;
V_56 -> V_114 = V_277 ;
V_56 -> V_137 = V_278 ;
V_56 -> V_154 = V_279 ;
V_56 -> V_93 = V_280 ;
V_56 -> V_95 = V_281 ;
V_56 -> V_98 [ 0 ] = V_282 ;
V_56 -> V_98 [ 1 ] = V_283 ;
V_56 -> V_98 [ 2 ] = V_284 ;
V_56 -> V_141 = V_285 ;
V_56 -> V_150 = V_286 ;
V_56 -> V_146 = V_287 ;
V_56 -> V_158 = V_288 ;
V_133 = V_289 ;
V_239 = F_40 ( V_289 ) ;
V_233 = V_290 ;
V_234 = V_291 ;
V_209 = V_292 ;
V_235 = V_293 ;
V_236 = V_294 ;
V_237 = V_295 ;
V_238 = V_296 ;
break;
case V_59 :
V_56 -> V_120 = 9 ;
V_56 -> V_81 = 3 ;
V_56 -> V_107 = 6 ;
V_56 -> V_75 = true ;
V_56 -> V_210 = 3 ;
V_56 -> V_155 = 3 ;
V_56 -> V_160 = 3 ;
V_56 -> V_150 = V_297 ;
V_56 -> V_158 = V_298 ;
V_56 -> V_127 = F_17 ;
V_56 -> V_163 = F_15 ;
V_56 -> V_105 = 0x7f ;
V_56 -> V_182 = 0x0f ;
V_56 -> V_190 = 15 ;
V_56 -> V_169 = V_299 ;
V_56 -> V_227 = F_40 ( V_299 ) ;
V_56 -> V_208 = V_300 ;
V_56 -> V_176 = V_301 ;
V_56 -> V_177 = V_302 ;
V_56 -> V_175 = V_303 ;
V_56 -> V_123 = V_304 ;
V_56 -> V_124 [ 0 ] = V_305 ;
V_56 -> V_124 [ 1 ] = V_306 ;
V_56 -> V_102 = V_307 ;
V_56 -> V_126 = V_308 ;
V_56 -> V_86 = V_309 ;
V_56 -> V_78 = V_310 ;
V_56 -> V_129 = V_311 ;
V_56 -> V_130 = V_312 ;
V_56 -> V_101 [ 0 ] = V_313 ;
V_56 -> V_101 [ 1 ] = V_314 ;
V_56 -> V_101 [ 2 ] = V_315 ;
V_56 -> V_87 [ 0 ] = V_316 ;
V_56 -> V_87 [ 1 ] = V_317 ;
V_56 -> V_87 [ 2 ] = V_318 ;
V_56 -> V_87 [ 3 ] = V_319 ;
V_56 -> V_87 [ 4 ] = V_320 ;
V_56 -> V_87 [ 5 ] = V_321 ;
V_56 -> V_179 = V_322 ;
V_56 -> V_83 = V_323 ;
V_56 -> V_84 = V_324 ;
V_56 -> V_269 = V_325 ;
V_56 -> V_271 = V_326 ;
V_56 -> V_110 = V_327 ;
V_56 -> V_92
= V_328 ;
V_56 -> V_137 = V_329 ;
V_56 -> V_154 = V_330 ;
V_56 -> V_93 = V_331 ;
V_56 -> V_95 = V_332 ;
V_56 -> V_98 [ 0 ] = V_333 ;
V_56 -> V_98 [ 1 ] = V_334 ;
V_56 -> V_98 [ 2 ] = V_335 ;
V_56 -> V_141 = V_336 ;
V_56 -> V_146 = V_337 ;
V_133 = V_338 ;
V_239 = F_40 ( V_338 ) ;
V_233 = V_339 ;
V_234 = V_340 ;
V_209 = V_341 ;
V_235 = V_342 ;
V_236 = V_343 ;
break;
case V_60 :
V_56 -> V_120 = 9 ;
V_56 -> V_81 = 3 ;
V_56 -> V_107 = 4 ;
V_56 -> V_75 = false ;
V_56 -> V_210 = 3 ;
V_56 -> V_155 = 3 ;
V_56 -> V_160 = 6 ;
V_56 -> V_150 = V_344 ;
V_56 -> V_158 = V_345 ;
V_56 -> V_127 = F_16 ;
V_56 -> V_163 = F_16 ;
V_56 -> V_105 = 0xff ;
V_56 -> V_182 = 0x07 ;
V_56 -> V_190 = 63 ;
V_56 -> V_169 = V_245 ;
V_56 -> V_227 = F_40 ( V_245 ) ;
V_56 -> V_208 = V_300 ;
V_56 -> V_176 = V_301 ;
V_56 -> V_177 = V_302 ;
V_56 -> V_175 = V_303 ;
V_56 -> V_123 = V_304 ;
V_56 -> V_124 [ 0 ] = V_305 ;
V_56 -> V_124 [ 1 ] = V_306 ;
V_56 -> V_102 = V_307 ;
V_56 -> V_126 = V_308 ;
V_56 -> V_86 = V_309 ;
V_56 -> V_78 = V_346 ;
V_56 -> V_129 = V_347 ;
V_56 -> V_130 = V_312 ;
V_56 -> V_101 [ 0 ] = V_313 ;
V_56 -> V_101 [ 1 ] = V_314 ;
V_56 -> V_101 [ 2 ] = V_315 ;
V_56 -> V_91 = V_348 ;
V_56 -> V_87 [ 0 ] = V_316 ;
V_56 -> V_87 [ 1 ] = V_317 ;
V_56 -> V_87 [ 2 ] = V_318 ;
V_56 -> V_87 [ 5 ] = V_321 ;
V_56 -> V_87 [ 6 ] = V_349 ;
V_56 -> V_179 = V_322 ;
V_56 -> V_83 = V_350 ;
V_56 -> V_84 = V_351 ;
V_56 -> V_269 = V_325 ;
V_56 -> V_271 = V_326 ;
V_56 -> V_110 = V_327 ;
V_56 -> V_92
= V_328 ;
V_56 -> V_137 = V_329 ;
V_56 -> V_154 = V_330 ;
V_56 -> V_93 = V_331 ;
V_56 -> V_95 = V_332 ;
V_56 -> V_98 [ 0 ] = V_333 ;
V_56 -> V_98 [ 1 ] = V_334 ;
V_56 -> V_98 [ 2 ] = V_335 ;
V_56 -> V_141 = V_336 ;
V_56 -> V_146 = V_352 ;
V_133 = V_338 ;
V_239 = F_40 ( V_338 ) ;
V_233 = V_339 ;
V_234 = V_340 ;
V_209 = V_353 ;
V_235 = V_354 ;
V_236 = V_355 ;
break;
case V_61 :
V_56 -> V_120 = 15 ;
V_56 -> V_81 = 5 ;
V_56 -> V_107 = 4 ;
V_56 -> V_75 = false ;
V_56 -> V_210 = 6 ;
V_56 -> V_155 = 2 ;
V_56 -> V_160 = 2 ;
V_56 -> V_150 = V_356 ;
V_56 -> V_158 = V_357 ;
V_56 -> V_127 = F_16 ;
V_56 -> V_163 = F_16 ;
V_56 -> V_105 = 0xff ;
V_56 -> V_182 = 0x07 ;
V_56 -> V_190 = 63 ;
V_56 -> V_169 = V_358 ;
V_56 -> V_227 = F_40 ( V_358 ) ;
V_56 -> V_208 = V_300 ;
V_56 -> V_176 = V_301 ;
V_56 -> V_177 = V_302 ;
V_56 -> V_175 = V_303 ;
V_56 -> V_123 = V_359 ;
V_56 -> V_124 [ 0 ] = V_305 ;
V_56 -> V_124 [ 1 ] = V_306 ;
V_56 -> V_102 = V_307 ;
V_56 -> V_126 = V_360 ;
V_56 -> V_86 = V_309 ;
V_56 -> V_78 = V_346 ;
V_56 -> V_129 = V_361 ;
V_56 -> V_130 = V_312 ;
V_56 -> V_101 [ 0 ] = V_313 ;
V_56 -> V_101 [ 1 ] = V_314 ;
V_56 -> V_101 [ 2 ] = V_315 ;
V_56 -> V_91 = V_348 ;
V_56 -> V_87 [ 0 ] = V_316 ;
V_56 -> V_87 [ 1 ] = V_317 ;
V_56 -> V_87 [ 2 ] = V_318 ;
V_56 -> V_87 [ 5 ] = V_321 ;
V_56 -> V_87 [ 6 ] = V_349 ;
V_56 -> V_179 = V_322 ;
V_56 -> V_83 = V_350 ;
V_56 -> V_84 = V_351 ;
V_56 -> V_269 = V_325 ;
V_56 -> V_271 = V_326 ;
V_56 -> V_110 = V_327 ;
V_56 -> V_92
= V_328 ;
V_56 -> V_112 = V_362 ;
V_56 -> V_113
= V_363 ;
V_56 -> V_114 = V_364 ;
V_56 -> V_137 = V_365 ;
V_56 -> V_154 = V_330 ;
V_56 -> V_93 = V_331 ;
V_56 -> V_95 = V_332 ;
V_56 -> V_98 [ 0 ] = V_333 ;
V_56 -> V_98 [ 1 ] = V_334 ;
V_56 -> V_98 [ 2 ] = V_335 ;
V_56 -> V_141 = V_366 ;
V_56 -> V_146 = V_352 ;
V_133 = V_367 ;
V_239 = F_40 ( V_367 ) ;
V_233 = V_368 ;
V_234 = V_369 ;
V_209 = V_370 ;
V_235 = V_371 ;
V_236 = V_372 ;
break;
case V_62 :
V_56 -> V_120 = 15 ;
V_56 -> V_81 = 6 ;
V_56 -> V_107 = 4 ;
V_56 -> V_75 = false ;
V_56 -> V_210 = 6 ;
V_56 -> V_155 = 2 ;
V_56 -> V_160 = 2 ;
V_56 -> V_150 = V_373 ;
V_56 -> V_158 = V_357 ;
V_56 -> V_127 = F_16 ;
V_56 -> V_163 = F_16 ;
V_56 -> V_105 = 0xff ;
V_56 -> V_182 = 0x07 ;
V_56 -> V_190 = 63 ;
V_56 -> V_169 = V_358 ;
V_56 -> V_227 = F_40 ( V_358 ) ;
V_56 -> V_208 = V_300 ;
V_56 -> V_176 = V_301 ;
V_56 -> V_177 = V_302 ;
V_56 -> V_175 = V_303 ;
V_56 -> V_123 = V_359 ;
V_56 -> V_124 [ 0 ] = V_305 ;
V_56 -> V_124 [ 1 ] = V_306 ;
V_56 -> V_102 = V_307 ;
V_56 -> V_126 = V_360 ;
V_56 -> V_86 = V_309 ;
V_56 -> V_78 = V_346 ;
V_56 -> V_129 = V_361 ;
V_56 -> V_130 = V_312 ;
V_56 -> V_101 [ 0 ] = V_313 ;
V_56 -> V_101 [ 1 ] = V_314 ;
V_56 -> V_101 [ 2 ] = V_315 ;
V_56 -> V_91 = V_348 ;
V_56 -> V_87 [ 0 ] = V_316 ;
V_56 -> V_87 [ 1 ] = V_317 ;
V_56 -> V_87 [ 2 ] = V_318 ;
V_56 -> V_87 [ 5 ] = V_321 ;
V_56 -> V_87 [ 6 ] = V_349 ;
V_56 -> V_179 = V_322 ;
V_56 -> V_83 = V_350 ;
V_56 -> V_84 = V_351 ;
V_56 -> V_269 = V_325 ;
V_56 -> V_271 = V_326 ;
V_56 -> V_110 = V_327 ;
V_56 -> V_92
= V_328 ;
V_56 -> V_112 = V_362 ;
V_56 -> V_113
= V_363 ;
V_56 -> V_114 = V_364 ;
V_56 -> V_137 = V_365 ;
V_56 -> V_154 = V_330 ;
V_56 -> V_93 = V_331 ;
V_56 -> V_95 = V_332 ;
V_56 -> V_98 [ 0 ] = V_333 ;
V_56 -> V_98 [ 1 ] = V_334 ;
V_56 -> V_98 [ 2 ] = V_335 ;
V_56 -> V_141 = V_374 ;
V_56 -> V_146 = V_352 ;
V_133 = V_367 ;
V_239 = F_40 ( V_367 ) ;
V_233 = V_368 ;
V_234 = V_369 ;
V_209 = V_370 ;
V_235 = V_371 ;
V_236 = V_372 ;
break;
default:
return - V_161 ;
}
V_56 -> V_121 = ( 1 << V_56 -> V_120 ) - 1 ;
V_56 -> V_132 = 0 ;
V_226 = 0 ;
V_225 = 0 ;
for ( V_35 = 0 ; V_35 < V_239 ; V_35 ++ ) {
if ( V_133 [ V_35 ] == 0 )
continue;
V_153 = F_30 ( V_56 , V_56 -> V_154 [ V_35 ] ) & 0x1f ;
if ( ! V_153 || ( V_226 & ( 1 << V_153 ) ) )
V_225 |= 1 << V_35 ;
V_226 |= 1 << V_153 ;
}
F_127 ( V_56 , V_56 -> V_93 , & V_225 , & V_226 ) ;
F_127 ( V_56 , V_56 -> V_95 , & V_225 , & V_226 ) ;
V_226 = 0 ;
V_49 = V_375 ;
for ( V_35 = 0 ; V_35 < V_239 ; V_35 ++ ) {
if ( V_133 [ V_35 ] == 0 )
continue;
V_153 = F_30 ( V_56 , V_56 -> V_154 [ V_35 ] ) & 0x1f ;
if ( ! V_153 || ( V_226 & ( 1 << V_153 ) ) )
continue;
if ( V_153 >= V_56 -> V_227 ||
! strlen ( V_56 -> V_169 [ V_153 ] ) ) {
F_71 ( V_19 ,
L_12 ,
V_153 , V_35 , V_56 -> V_154 [ V_35 ] , V_133 [ V_35 ] ) ;
continue;
}
V_226 |= 1 << V_153 ;
if ( V_153 <= V_56 -> V_210 ) {
V_56 -> V_132 |= 1 << ( V_153 - 1 ) ;
V_56 -> V_135 |= 1 << ( V_153 - 1 ) ;
V_56 -> V_133 [ 0 ] [ V_153 - 1 ] = V_133 [ V_35 ] ;
V_56 -> V_133 [ 1 ] [ V_153 - 1 ] = V_233 [ V_35 ] ;
V_56 -> V_133 [ 2 ] [ V_153 - 1 ] = V_234 [ V_35 ] ;
if ( V_238 && V_238 [ V_35 ] )
V_56 -> V_133 [ 3 ] [ V_153 - 1 ] = V_238 [ V_35 ] ;
else if ( V_236 [ V_153 - 1 ] )
V_56 -> V_133 [ 3 ] [ V_153 - 1 ]
= V_236 [ V_153 - 1 ] ;
if ( V_237 && V_237 [ V_35 ] )
V_56 -> V_133 [ 4 ] [ V_153 - 1 ] = V_237 [ V_35 ] ;
V_56 -> V_209 [ V_153 - 1 ] = V_209 [ V_35 ] ;
V_56 -> V_152 [ V_153 - 1 ] = V_153 ;
continue;
}
if ( V_49 >= V_131 )
continue;
V_56 -> V_132 |= 1 << V_49 ;
V_56 -> V_133 [ 0 ] [ V_49 ] = V_133 [ V_35 ] ;
V_56 -> V_133 [ 1 ] [ V_49 ] = V_233 [ V_35 ] ;
V_56 -> V_133 [ 2 ] [ V_49 ] = V_234 [ V_35 ] ;
V_56 -> V_209 [ V_49 ] = V_209 [ V_35 ] ;
if ( V_238 && V_238 [ V_35 ] )
V_56 -> V_133 [ 3 ] [ V_49 ] = V_238 [ V_35 ] ;
else if ( V_236 [ V_153 - 1 ] )
V_56 -> V_133 [ 3 ] [ V_49 ] = V_236 [ V_153 - 1 ] ;
if ( V_237 && V_237 [ V_35 ] )
V_56 -> V_133 [ 4 ] [ V_49 ] = V_237 [ V_35 ] ;
V_56 -> V_152 [ V_49 ] = V_153 ;
V_49 ++ ;
}
#ifdef F_135
for ( V_35 = 0 ; V_35 < V_56 -> V_227 - 1 ; V_35 ++ ) {
if ( ! V_235 [ V_35 ] )
continue;
if ( V_226 & ( 1 << ( V_35 + 1 ) ) )
continue;
if ( V_35 < V_56 -> V_210 ) {
if ( V_56 -> V_132 & ( 1 << V_35 ) )
continue;
V_56 -> V_132 |= 1 << V_35 ;
V_56 -> V_135 |= 1 << V_35 ;
V_56 -> V_133 [ 0 ] [ V_35 ] = V_235 [ V_35 ] ;
if ( V_35 < V_239 ) {
V_56 -> V_133 [ 1 ] [ V_35 ] = V_233 [ V_35 ] ;
V_56 -> V_133 [ 2 ] [ V_35 ] = V_234 [ V_35 ] ;
}
V_56 -> V_152 [ V_35 ] = V_35 + 1 ;
continue;
}
if ( V_49 >= V_131 )
break;
V_56 -> V_132 |= 1 << V_49 ;
V_56 -> V_133 [ 0 ] [ V_49 ] = V_235 [ V_35 ] ;
V_56 -> V_152 [ V_49 ] = V_35 + 1 ;
V_49 ++ ;
}
#endif
F_125 ( V_56 ) ;
V_34 = F_6 ( V_231 -> V_197 ) ;
if ( V_34 )
return V_34 ;
V_240 = F_3 ( V_231 -> V_197 , 0x2a ) ;
switch ( V_56 -> V_57 ) {
case V_59 :
V_56 -> V_201 = ( V_240 & 0x40 ) ;
break;
case V_60 :
V_56 -> V_201 = ( V_240 & 0x60 ) == 0x40 ;
break;
case V_58 :
case V_61 :
case V_62 :
break;
}
if ( V_56 -> V_201 ) {
F_5 ( V_231 -> V_197 , V_376 ) ;
V_56 -> V_193 = F_3 ( V_231 -> V_197 , 0xe3 ) ;
V_56 -> V_194 = F_136 () ;
}
if ( V_377 ) {
T_1 V_207 ;
F_5 ( V_231 -> V_197 , V_222 ) ;
V_207 = F_3 ( V_231 -> V_197 ,
V_378 ) ;
switch ( V_56 -> V_57 ) {
case V_58 :
V_207 |= 0xe0 ;
break;
case V_59 :
V_207 |= 0x1e ;
break;
case V_60 :
case V_61 :
V_207 |= 0x3e ;
break;
case V_62 :
V_207 |= 0x7e ;
break;
}
F_1 ( V_231 -> V_197 , V_378 ,
V_207 ) ;
F_71 ( & V_229 -> V_19 , L_13 ,
V_56 -> V_43 ) ;
}
F_126 ( V_56 ) ;
F_8 ( V_231 -> V_197 ) ;
F_41 ( V_19 , V_56 ) ;
V_23 = F_23 ( V_19 , & V_379 ,
V_56 -> V_81 ) ;
if ( F_137 ( V_23 ) ) {
V_34 = F_138 ( V_23 ) ;
goto V_380;
}
V_56 -> V_202 = V_23 ;
V_23 = F_23 ( V_19 , & V_381 ,
F_139 ( V_56 -> V_121 ) ) ;
if ( F_137 ( V_23 ) ) {
V_34 = F_138 ( V_23 ) ;
goto V_380;
}
V_56 -> V_203 = V_23 ;
V_23 = F_23 ( V_19 , & V_382 ,
F_139 ( V_56 -> V_74 ) ) ;
if ( F_137 ( V_23 ) ) {
V_34 = F_138 ( V_23 ) ;
goto V_380;
}
V_56 -> V_204 = V_23 ;
V_23 = F_23 ( V_19 , & V_383 ,
F_139 ( V_56 -> V_132 ) ) ;
if ( F_137 ( V_23 ) ) {
V_34 = F_138 ( V_23 ) ;
goto V_380;
}
V_56 -> V_205 = V_23 ;
V_34 = F_26 ( & V_19 -> V_54 , & V_206 ) ;
if ( V_34 )
goto V_380;
V_56 -> V_384 = F_140 ( V_19 ) ;
if ( F_137 ( V_56 -> V_384 ) ) {
V_34 = F_138 ( V_56 -> V_384 ) ;
goto V_380;
}
return 0 ;
V_380:
F_123 ( V_19 ) ;
return V_34 ;
}
static int F_141 ( struct V_228 * V_229 )
{
struct V_55 * V_56 = F_142 ( V_229 ) ;
F_143 ( V_56 -> V_384 ) ;
F_123 ( & V_229 -> V_19 ) ;
return 0 ;
}
static int F_144 ( struct V_18 * V_19 )
{
struct V_55 * V_56 = F_49 ( V_19 ) ;
F_50 ( & V_56 -> V_115 ) ;
V_56 -> V_171 = F_30 ( V_56 , V_56 -> V_176 ) ;
if ( V_56 -> V_57 == V_59 ) {
V_56 -> V_385 = F_30 ( V_56 , V_71 ) ;
V_56 -> V_386 = F_30 ( V_56 , V_73 ) ;
}
F_52 ( & V_56 -> V_115 ) ;
return 0 ;
}
static int F_145 ( struct V_18 * V_19 )
{
struct V_55 * V_56 = F_45 ( V_19 ) ;
int V_35 , V_36 ;
F_50 ( & V_56 -> V_115 ) ;
V_56 -> V_63 = 0xff ;
for ( V_35 = 0 ; V_35 < V_56 -> V_120 ; V_35 ++ ) {
if ( ! ( V_56 -> V_121 & ( 1 << V_35 ) ) )
continue;
F_32 ( V_56 , V_56 -> V_124 [ 0 ] [ V_35 ] ,
V_56 -> V_122 [ V_35 ] [ 1 ] ) ;
F_32 ( V_56 , V_56 -> V_124 [ 1 ] [ V_35 ] ,
V_56 -> V_122 [ V_35 ] [ 2 ] ) ;
}
for ( V_35 = 0 ; V_35 < F_40 ( V_56 -> V_76 ) ; V_35 ++ ) {
if ( ! ( V_56 -> V_77 & ( 1 << V_35 ) ) )
continue;
F_32 ( V_56 , V_56 -> V_78 [ V_35 ] ,
V_56 -> V_76 [ V_35 ] ) ;
}
for ( V_35 = 0 ; V_35 < V_131 ; V_35 ++ ) {
if ( ! ( V_56 -> V_132 & ( 1 << V_35 ) ) )
continue;
for ( V_36 = 1 ; V_36 < F_40 ( V_56 -> V_133 ) ; V_36 ++ )
if ( V_56 -> V_133 [ V_36 ] [ V_35 ] )
F_34 ( V_56 , V_56 -> V_133 [ V_36 ] [ V_35 ] ,
V_56 -> V_134 [ V_36 ] [ V_35 ] ) ;
}
F_32 ( V_56 , V_56 -> V_176 , V_56 -> V_171 ) ;
if ( V_56 -> V_57 == V_59 ) {
F_32 ( V_56 , V_71 , V_56 -> V_385 ) ;
F_32 ( V_56 , V_73 , V_56 -> V_386 ) ;
}
V_56 -> V_119 = false ;
F_52 ( & V_56 -> V_115 ) ;
return 0 ;
}
static int T_7 F_146 ( int V_387 , struct V_230 * V_231 )
{
T_2 V_3 ;
int V_34 ;
int V_65 ;
V_34 = F_6 ( V_387 ) ;
if ( V_34 )
return V_34 ;
if ( V_388 )
V_3 = V_388 ;
else
V_3 = ( F_3 ( V_387 , V_389 ) << 8 )
| F_3 ( V_387 , V_389 + 1 ) ;
switch ( V_3 & V_390 ) {
case V_391 :
V_231 -> V_57 = V_58 ;
break;
case V_392 :
V_231 -> V_57 = V_59 ;
break;
case V_393 :
V_231 -> V_57 = V_60 ;
break;
case V_394 :
V_231 -> V_57 = V_61 ;
break;
case V_395 :
V_231 -> V_57 = V_62 ;
break;
default:
if ( V_3 != 0xffff )
F_147 ( L_14 , V_3 ) ;
F_8 ( V_387 ) ;
return - V_161 ;
}
F_5 ( V_387 , V_222 ) ;
V_3 = ( F_3 ( V_387 , V_396 ) << 8 )
| F_3 ( V_387 , V_396 + 1 ) ;
V_65 = V_3 & V_397 ;
if ( V_65 == 0 ) {
F_148 ( L_15 ) ;
F_8 ( V_387 ) ;
return - V_161 ;
}
V_3 = F_3 ( V_387 , V_223 ) ;
if ( ! ( V_3 & 0x01 ) ) {
F_149 ( L_16 ) ;
F_1 ( V_387 , V_223 , V_3 | 0x01 ) ;
}
if ( V_231 -> V_57 == V_62 ) {
V_3 = F_3 ( V_387 , V_398 ) ;
if ( V_3 & 0x10 ) {
F_150 ( L_17 ) ;
F_1 ( V_387 ,
V_398 ,
V_3 & ~ 0x10 ) ;
}
}
F_8 ( V_387 ) ;
F_150 ( L_18 ,
V_399 [ V_231 -> V_57 ] , V_387 , V_65 ) ;
V_231 -> V_197 = V_387 ;
return V_65 ;
}
static int T_7 F_151 ( void )
{
int V_35 , V_34 ;
bool V_400 = false ;
int V_401 ;
struct V_232 V_68 ;
struct V_230 V_231 ;
int V_387 [ 2 ] = { 0x2e , 0x4e } ;
V_34 = F_152 ( & V_402 ) ;
if ( V_34 )
return V_34 ;
for ( V_35 = 0 ; V_35 < F_40 ( V_229 ) ; V_35 ++ ) {
V_401 = F_146 ( V_387 [ V_35 ] , & V_231 ) ;
if ( V_401 <= 0 )
continue;
V_400 = true ;
V_229 [ V_35 ] = F_153 ( V_6 , V_401 ) ;
if ( ! V_229 [ V_35 ] ) {
V_34 = - V_41 ;
goto V_403;
}
V_34 = F_154 ( V_229 [ V_35 ] , & V_231 ,
sizeof( struct V_230 ) ) ;
if ( V_34 )
goto V_403;
memset ( & V_68 , 0 , sizeof( V_68 ) ) ;
V_68 . V_43 = V_6 ;
V_68 . V_242 = V_401 + V_404 ;
V_68 . V_405 = V_401 + V_404 + V_243 - 1 ;
V_68 . V_406 = V_241 ;
V_34 = F_155 ( & V_68 ) ;
if ( V_34 ) {
F_156 ( V_229 [ V_35 ] ) ;
V_229 [ V_35 ] = NULL ;
continue;
}
V_34 = F_157 ( V_229 [ V_35 ] , & V_68 , 1 ) ;
if ( V_34 )
goto V_403;
V_34 = F_158 ( V_229 [ V_35 ] ) ;
if ( V_34 )
goto V_403;
}
if ( ! V_400 ) {
V_34 = - V_161 ;
goto V_407;
}
return 0 ;
V_403:
for ( V_35 = 0 ; V_35 < F_40 ( V_229 ) ; V_35 ++ ) {
if ( V_229 [ V_35 ] )
F_156 ( V_229 [ V_35 ] ) ;
}
V_407:
F_159 ( & V_402 ) ;
return V_34 ;
}
static void T_8 F_160 ( void )
{
int V_35 ;
for ( V_35 = 0 ; V_35 < F_40 ( V_229 ) ; V_35 ++ ) {
if ( V_229 [ V_35 ] )
F_161 ( V_229 [ V_35 ] ) ;
}
F_159 ( & V_402 ) ;
}
