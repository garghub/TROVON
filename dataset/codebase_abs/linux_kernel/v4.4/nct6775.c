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
int V_34 , V_35 ;
if ( V_22 <= 0 )
return F_24 ( - V_36 ) ;
V_33 = V_21 -> V_37 ;
for ( V_35 = 0 ; * V_33 ; V_33 ++ , V_35 ++ )
;
if ( V_35 == 0 )
return F_24 ( - V_36 ) ;
V_23 = F_25 ( V_19 , sizeof( * V_23 ) , V_38 ) ;
if ( V_23 == NULL )
return F_24 ( - V_39 ) ;
V_31 = F_25 ( V_19 , sizeof( * V_31 ) * ( V_22 * V_35 + 1 ) ,
V_38 ) ;
if ( V_31 == NULL )
return F_24 ( - V_39 ) ;
V_25 = F_25 ( V_19 , sizeof( * V_25 ) * V_22 * V_35 ,
V_38 ) ;
if ( V_25 == NULL )
return F_24 ( - V_39 ) ;
V_23 -> V_31 = V_31 ;
V_23 -> V_40 = V_21 -> V_40 ;
for ( V_34 = 0 ; V_34 < V_22 ; V_34 ++ ) {
V_33 = V_21 -> V_37 ;
while ( * V_33 != NULL ) {
snprintf ( V_25 -> V_41 , sizeof( V_25 -> V_41 ) ,
( * V_33 ) -> V_42 . V_43 . V_41 , V_21 -> V_44 + V_34 ) ;
if ( ( * V_33 ) -> V_45 ) {
V_29 = & V_25 -> V_46 . V_29 ;
F_26 ( & V_29 -> V_42 . V_43 ) ;
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
F_26 ( & V_27 -> V_42 . V_43 ) ;
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
static bool F_27 ( struct V_52 * V_53 , T_2 V_2 )
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
static inline void F_28 ( struct V_52 * V_53 , T_2 V_2 )
{
T_1 V_62 = V_2 >> 8 ;
if ( V_53 -> V_62 != V_62 ) {
F_29 ( V_63 , V_53 -> V_64 + V_65 ) ;
F_29 ( V_62 , V_53 -> V_64 + V_66 ) ;
V_53 -> V_62 = V_62 ;
}
}
static T_2 F_30 ( struct V_52 * V_53 , T_2 V_2 )
{
int V_67 , V_68 = F_27 ( V_53 , V_2 ) ;
F_28 ( V_53 , V_2 ) ;
F_29 ( V_2 & 0xff , V_53 -> V_64 + V_65 ) ;
V_67 = F_31 ( V_53 -> V_64 + V_66 ) ;
if ( V_68 ) {
F_29 ( ( V_2 & 0xff ) + 1 ,
V_53 -> V_64 + V_65 ) ;
V_67 = ( V_67 << 8 ) + F_31 ( V_53 -> V_64 + V_66 ) ;
}
return V_67 ;
}
static int F_32 ( struct V_52 * V_53 , T_2 V_2 , T_2 V_69 )
{
int V_68 = F_27 ( V_53 , V_2 ) ;
F_28 ( V_53 , V_2 ) ;
F_29 ( V_2 & 0xff , V_53 -> V_64 + V_65 ) ;
if ( V_68 ) {
F_29 ( V_69 >> 8 , V_53 -> V_64 + V_66 ) ;
F_29 ( ( V_2 & 0xff ) + 1 ,
V_53 -> V_64 + V_65 ) ;
}
F_29 ( V_69 & 0xff , V_53 -> V_64 + V_66 ) ;
return 0 ;
}
static T_2 F_33 ( struct V_52 * V_53 , T_2 V_2 )
{
T_2 V_67 ;
V_67 = F_30 ( V_53 , V_2 ) ;
if ( ! F_27 ( V_53 , V_2 ) )
V_67 <<= 8 ;
return V_67 ;
}
static int F_34 ( struct V_52 * V_53 , T_2 V_2 , T_2 V_69 )
{
if ( ! F_27 ( V_53 , V_2 ) )
V_69 >>= 8 ;
return F_32 ( V_53 , V_2 , V_69 ) ;
}
static void F_35 ( struct V_52 * V_53 , int V_15 )
{
T_1 V_2 ;
switch ( V_15 ) {
case 0 :
V_2 = ( F_30 ( V_53 , V_70 ) & 0x70 )
| ( V_53 -> V_71 [ 0 ] & 0x7 ) ;
F_32 ( V_53 , V_70 , V_2 ) ;
break;
case 1 :
V_2 = ( F_30 ( V_53 , V_70 ) & 0x7 )
| ( ( V_53 -> V_71 [ 1 ] << 4 ) & 0x70 ) ;
F_32 ( V_53 , V_70 , V_2 ) ;
break;
case 2 :
V_2 = ( F_30 ( V_53 , V_72 ) & 0x70 )
| ( V_53 -> V_71 [ 2 ] & 0x7 ) ;
F_32 ( V_53 , V_72 , V_2 ) ;
break;
case 3 :
V_2 = ( F_30 ( V_53 , V_72 ) & 0x7 )
| ( ( V_53 -> V_71 [ 3 ] << 4 ) & 0x70 ) ;
F_32 ( V_53 , V_72 , V_2 ) ;
break;
}
}
static void F_36 ( struct V_52 * V_53 , int V_15 )
{
if ( V_53 -> V_54 == V_56 )
F_35 ( V_53 , V_15 ) ;
}
static void F_37 ( struct V_52 * V_53 )
{
T_1 V_34 ;
V_34 = F_30 ( V_53 , V_70 ) ;
V_53 -> V_71 [ 0 ] = V_34 & 0x7 ;
V_53 -> V_71 [ 1 ] = ( V_34 & 0x70 ) >> 4 ;
V_34 = F_30 ( V_53 , V_72 ) ;
V_53 -> V_71 [ 2 ] = V_34 & 0x7 ;
if ( V_53 -> V_73 & ( 1 << 3 ) )
V_53 -> V_71 [ 3 ] = ( V_34 & 0x70 ) >> 4 ;
}
static void F_38 ( struct V_52 * V_53 )
{
if ( V_53 -> V_54 == V_56 )
F_37 ( V_53 ) ;
}
static void F_39 ( struct V_52 * V_53 )
{
int V_34 ;
F_38 ( V_53 ) ;
for ( V_34 = 0 ; V_34 < F_40 ( V_53 -> V_71 ) ; V_34 ++ ) {
if ( ! ( V_53 -> V_73 & ( 1 << V_34 ) ) )
continue;
if ( V_53 -> V_71 [ V_34 ] == 0 ) {
V_53 -> V_71 [ V_34 ] = 7 ;
F_36 ( V_53 , V_34 ) ;
}
}
}
static void F_41 ( struct V_18 * V_19 ,
struct V_52 * V_53 )
{
int V_34 ;
T_1 V_2 ;
if ( V_53 -> V_74 )
F_39 ( V_53 ) ;
for ( V_34 = 0 ; V_34 < F_40 ( V_53 -> V_75 ) ; V_34 ++ ) {
if ( V_53 -> V_76 & ( 1 << V_34 ) ) {
V_2 = F_30 ( V_53 , V_53 -> V_77 [ V_34 ] ) ;
if ( ! V_2 )
F_32 ( V_53 , V_53 -> V_77 [ V_34 ] ,
V_53 -> V_74 ? 0xff
: 0xff1f ) ;
}
}
}
static void F_42 ( struct V_18 * V_19 ,
struct V_52 * V_53 , int V_15 , T_2 V_2 )
{
T_1 V_71 = V_53 -> V_71 [ V_15 ] ;
T_2 V_75 ;
if ( ! V_53 -> V_74 )
return;
if ( V_2 == 0x00 && V_71 < 0x07 )
V_71 ++ ;
else if ( V_2 != 0x00 && V_2 < 0x30 && V_71 > 0 )
V_71 -- ;
if ( V_71 != V_53 -> V_71 [ V_15 ] ) {
F_43 ( V_19 , L_1 ,
V_15 + 1 , F_19 ( V_53 -> V_71 [ V_15 ] ) ,
F_19 ( V_71 ) ) ;
if ( V_53 -> V_76 & ( 1 << V_15 ) ) {
V_75 = V_53 -> V_75 [ V_15 ] ;
if ( V_71 > V_53 -> V_71 [ V_15 ] ) {
if ( V_75 != 255 && V_75 > 1 )
V_75 >>= 1 ;
} else {
if ( V_75 != 255 ) {
V_75 <<= 1 ;
if ( V_75 > 254 )
V_75 = 254 ;
}
}
if ( V_75 != V_53 -> V_75 [ V_15 ] ) {
V_53 -> V_75 [ V_15 ] = V_75 ;
F_32 ( V_53 , V_53 -> V_77 [ V_15 ] ,
V_75 ) ;
}
}
V_53 -> V_71 [ V_15 ] = V_71 ;
F_36 ( V_53 , V_15 ) ;
}
}
static void F_44 ( struct V_18 * V_19 )
{
struct V_52 * V_53 = F_45 ( V_19 ) ;
int V_34 , V_78 ;
int V_79 , V_2 ;
bool V_80 ;
for ( V_34 = 0 ; V_34 < V_53 -> V_81 ; V_34 ++ ) {
if ( ! ( V_53 -> V_82 & ( 1 << V_34 ) ) )
continue;
V_80 = V_53 -> V_83 [ V_34 ] &&
( F_30 ( V_53 , V_53 -> V_83 [ V_34 ] )
& V_53 -> V_84 [ V_34 ] ) ;
V_53 -> V_85 [ V_34 ] = V_80 ;
V_79 = F_30 ( V_53 , V_53 -> V_86 [ V_34 ] ) ;
for ( V_78 = 0 ; V_78 < F_40 ( V_53 -> V_87 ) ; V_78 ++ ) {
if ( V_53 -> V_87 [ V_78 ] && V_53 -> V_87 [ V_78 ] [ V_34 ] ) {
V_53 -> V_9 [ V_78 ] [ V_34 ]
= F_30 ( V_53 ,
V_53 -> V_87 [ V_78 ] [ V_34 ] ) ;
}
}
V_53 -> V_8 [ V_34 ] = F_10 ( V_53 -> V_9 [ 0 ] [ V_34 ] ,
( V_79 >> 4 ) & 7 ) ;
if ( ! V_53 -> V_88 [ 0 ] [ V_34 ] ||
V_53 -> V_8 [ V_34 ] != V_89 )
V_53 -> V_88 [ 0 ] [ V_34 ] = V_79 & 0x0f ;
if ( ! V_53 -> V_90 [ V_34 ] ||
V_53 -> V_8 [ V_34 ] == V_89 ) {
T_1 V_33 = V_79 & 0x0f ;
if ( V_53 -> V_91 ) {
V_33 |= ( F_30 ( V_53 ,
V_53 -> V_91 [ V_34 ] ) & 0x70 ) >> 1 ;
}
V_53 -> V_90 [ V_34 ] = V_33 ;
}
V_53 -> V_88 [ 1 ] [ V_34 ] =
F_30 ( V_53 ,
V_53 -> V_92 [ V_34 ] ) ;
V_2 = F_30 ( V_53 , V_53 -> V_93 [ V_34 ] ) ;
V_53 -> V_94 [ V_34 ] = V_2 & 0x1f ;
if ( V_2 & 0x80 )
V_53 -> V_9 [ 2 ] [ V_34 ] = 0 ;
if ( ! V_53 -> V_95 [ V_34 ] )
continue;
V_2 = F_30 ( V_53 , V_53 -> V_95 [ V_34 ] ) ;
V_53 -> V_96 [ V_34 ] = V_2 & 0x1f ;
if ( V_78 == 1 && ! ( V_2 & 0x80 ) )
V_53 -> V_96 [ V_34 ] = 0 ;
for ( V_78 = 0 ; V_78 < F_40 ( V_53 -> V_97 ) ; V_78 ++ ) {
V_53 -> V_97 [ V_78 ] [ V_34 ]
= F_30 ( V_53 ,
V_53 -> V_98 [ V_78 ] [ V_34 ] ) ;
}
}
}
static void F_46 ( struct V_18 * V_19 )
{
struct V_52 * V_53 = F_45 ( V_19 ) ;
int V_34 , V_78 ;
T_1 V_2 ;
T_2 V_99 ;
for ( V_34 = 0 ; V_34 < V_53 -> V_81 ; V_34 ++ ) {
if ( ! ( V_53 -> V_82 & ( 1 << V_34 ) ) )
continue;
for ( V_78 = 0 ; V_78 < F_40 ( V_53 -> V_100 ) ; V_78 ++ ) {
V_53 -> V_100 [ V_78 ] [ V_34 ] =
F_30 ( V_53 , V_53 -> V_101 [ V_78 ] [ V_34 ] ) ;
}
V_99 = F_30 ( V_53 , V_53 -> V_102 [ V_34 ] ) ;
if ( ! V_53 -> V_103 [ V_34 ] ||
V_53 -> V_8 [ V_34 ] == V_104 )
V_53 -> V_103 [ V_34 ] = V_99 & V_53 -> V_105 ;
if ( ! V_53 -> V_106 [ V_34 ] ||
V_53 -> V_8 [ V_34 ] == V_89 ) {
if ( V_53 -> V_91 ) {
V_99 |= ( F_30 ( V_53 ,
V_53 -> V_91 [ V_34 ] ) & 0x0f ) << 8 ;
}
V_53 -> V_106 [ V_34 ] = V_99 ;
}
for ( V_78 = 0 ; V_78 < V_53 -> V_107 ; V_78 ++ ) {
V_53 -> V_108 [ V_34 ] [ V_78 ] =
F_30 ( V_53 ,
F_47 ( V_53 , V_34 , V_78 ) ) ;
V_53 -> V_109 [ V_34 ] [ V_78 ] =
F_30 ( V_53 ,
F_48 ( V_53 , V_34 , V_78 ) ) ;
}
V_53 -> V_109 [ V_34 ] [ V_53 -> V_107 ] =
F_30 ( V_53 , V_53 -> V_110 [ V_34 ] ) ;
switch ( V_53 -> V_54 ) {
case V_56 :
V_2 = F_30 ( V_53 ,
V_111 [ V_34 ] ) ;
V_53 -> V_108 [ V_34 ] [ V_53 -> V_107 ] =
( V_2 & 0x02 ) ? 0xff : 0x00 ;
break;
case V_57 :
V_53 -> V_108 [ V_34 ] [ V_53 -> V_107 ] = 0xff ;
break;
case V_55 :
case V_58 :
case V_59 :
case V_60 :
case V_61 :
V_2 = F_30 ( V_53 ,
V_53 -> V_112 [ V_34 ] ) ;
if ( V_2 & V_53 -> V_113 )
V_2 = F_30 ( V_53 ,
V_53 -> V_114 [ V_34 ] ) ;
else
V_2 = 0xff ;
V_53 -> V_108 [ V_34 ] [ V_53 -> V_107 ] = V_2 ;
break;
}
}
}
static struct V_52 * F_49 ( struct V_18 * V_19 )
{
struct V_52 * V_53 = F_45 ( V_19 ) ;
int V_34 , V_78 ;
F_50 ( & V_53 -> V_115 ) ;
if ( F_51 ( V_116 , V_53 -> V_117 + V_118 + V_118 / 2 )
|| ! V_53 -> V_119 ) {
F_38 ( V_53 ) ;
for ( V_34 = 0 ; V_34 < V_53 -> V_120 ; V_34 ++ ) {
if ( ! ( V_53 -> V_121 & ( 1 << V_34 ) ) )
continue;
V_53 -> V_122 [ V_34 ] [ 0 ] = F_30 ( V_53 ,
V_53 -> V_123 [ V_34 ] ) ;
V_53 -> V_122 [ V_34 ] [ 1 ] = F_30 ( V_53 ,
V_53 -> V_124 [ 0 ] [ V_34 ] ) ;
V_53 -> V_122 [ V_34 ] [ 2 ] = F_30 ( V_53 ,
V_53 -> V_124 [ 1 ] [ V_34 ] ) ;
}
for ( V_34 = 0 ; V_34 < F_40 ( V_53 -> V_125 ) ; V_34 ++ ) {
T_2 V_2 ;
if ( ! ( V_53 -> V_73 & ( 1 << V_34 ) ) )
continue;
V_2 = F_30 ( V_53 , V_53 -> V_126 [ V_34 ] ) ;
V_53 -> V_125 [ V_34 ] = V_53 -> V_127 ( V_2 ,
V_53 -> V_71 [ V_34 ] ) ;
if ( V_53 -> V_76 & ( 1 << V_34 ) )
V_53 -> V_75 [ V_34 ] = F_30 ( V_53 ,
V_53 -> V_77 [ V_34 ] ) ;
V_53 -> V_128 [ V_34 ] =
( F_30 ( V_53 , V_53 -> V_129 [ V_34 ] )
>> V_53 -> V_130 [ V_34 ] ) & 0x03 ;
F_42 ( V_19 , V_53 , V_34 , V_2 ) ;
}
F_44 ( V_19 ) ;
F_46 ( V_19 ) ;
for ( V_34 = 0 ; V_34 < V_131 ; V_34 ++ ) {
if ( ! ( V_53 -> V_132 & ( 1 << V_34 ) ) )
continue;
for ( V_78 = 0 ; V_78 < F_40 ( V_53 -> V_133 ) ; V_78 ++ ) {
if ( V_53 -> V_133 [ V_78 ] [ V_34 ] )
V_53 -> V_134 [ V_78 ] [ V_34 ]
= F_33 ( V_53 ,
V_53 -> V_133 [ V_78 ] [ V_34 ] ) ;
}
if ( V_34 >= V_135 ||
! ( V_53 -> V_136 & ( 1 << V_34 ) ) )
continue;
V_53 -> V_137 [ V_34 ]
= F_30 ( V_53 , V_53 -> V_138 [ V_34 ] ) ;
}
V_53 -> V_139 = 0 ;
for ( V_34 = 0 ; V_34 < V_140 ; V_34 ++ ) {
T_1 V_141 ;
if ( ! V_53 -> V_142 [ V_34 ] )
continue;
V_141 = F_30 ( V_53 , V_53 -> V_142 [ V_34 ] ) ;
V_53 -> V_139 |= ( ( V_143 ) V_141 ) << ( V_34 << 3 ) ;
}
V_53 -> V_144 = 0 ;
for ( V_34 = 0 ; V_34 < V_145 ; V_34 ++ ) {
T_1 V_146 ;
if ( ! V_53 -> V_147 [ V_34 ] )
continue;
V_146 = F_30 ( V_53 , V_53 -> V_147 [ V_34 ] ) ;
V_53 -> V_144 |= ( ( V_143 ) V_146 ) << ( V_34 << 3 ) ;
}
V_53 -> V_117 = V_116 ;
V_53 -> V_119 = true ;
}
F_52 ( & V_53 -> V_115 ) ;
return V_53 ;
}
static T_4
F_53 ( struct V_18 * V_19 , struct V_148 * V_43 , char * V_149 )
{
struct V_52 * V_53 = F_49 ( V_19 ) ;
struct V_28 * V_150 = F_54 ( V_43 ) ;
int V_48 = V_150 -> V_48 ;
int V_15 = V_150 -> V_15 ;
return sprintf ( V_149 , L_2 , F_20 ( V_53 -> V_122 [ V_15 ] [ V_48 ] , V_15 ) ) ;
}
static T_4
F_55 ( struct V_18 * V_19 , struct V_148 * V_43 , const char * V_149 ,
T_5 V_35 )
{
struct V_52 * V_53 = F_45 ( V_19 ) ;
struct V_28 * V_150 = F_54 ( V_43 ) ;
int V_48 = V_150 -> V_48 ;
int V_15 = V_150 -> V_15 ;
unsigned long V_3 ;
int V_151 ;
V_151 = F_56 ( V_149 , 10 , & V_3 ) ;
if ( V_151 < 0 )
return V_151 ;
F_50 ( & V_53 -> V_115 ) ;
V_53 -> V_122 [ V_15 ] [ V_48 ] = F_22 ( V_3 , V_15 ) ;
F_32 ( V_53 , V_53 -> V_124 [ V_48 - 1 ] [ V_15 ] ,
V_53 -> V_122 [ V_15 ] [ V_48 ] ) ;
F_52 ( & V_53 -> V_115 ) ;
return V_35 ;
}
static T_4
F_57 ( struct V_18 * V_19 , struct V_148 * V_43 , char * V_149 )
{
struct V_52 * V_53 = F_49 ( V_19 ) ;
struct V_26 * V_150 = F_58 ( V_43 ) ;
int V_15 = V_53 -> V_152 [ V_150 -> V_48 ] ;
return sprintf ( V_149 , L_3 ,
( unsigned int ) ( ( V_53 -> V_139 >> V_15 ) & 0x01 ) ) ;
}
static int F_59 ( struct V_52 * V_53 , int V_48 , int V_35 )
{
int V_153 = V_53 -> V_154 [ V_48 ] ;
int V_15 ;
for ( V_15 = 0 ; V_15 < V_35 ; V_15 ++ ) {
int V_155 ;
V_155 = F_30 ( V_53 ,
V_53 -> V_156 [ V_15 ] ) & 0x1f ;
if ( V_155 == V_153 )
return V_15 ;
}
return - V_157 ;
}
static T_4
F_60 ( struct V_18 * V_19 , struct V_148 * V_43 , char * V_149 )
{
struct V_26 * V_150 = F_58 ( V_43 ) ;
struct V_52 * V_53 = F_49 ( V_19 ) ;
unsigned int V_141 = 0 ;
int V_15 ;
V_15 = F_59 ( V_53 , V_150 -> V_48 , V_53 -> V_158 ) ;
if ( V_15 >= 0 ) {
int V_159 = V_53 -> V_152 [ V_15 + V_160 ] ;
V_141 = ( V_53 -> V_139 >> V_159 ) & 0x01 ;
}
return sprintf ( V_149 , L_3 , V_141 ) ;
}
static T_4
F_61 ( struct V_18 * V_19 , struct V_148 * V_43 , char * V_149 )
{
struct V_26 * V_150 = F_58 ( V_43 ) ;
struct V_52 * V_53 = F_49 ( V_19 ) ;
int V_15 = V_53 -> V_161 [ V_150 -> V_48 ] ;
return sprintf ( V_149 , L_3 ,
( unsigned int ) ( ( V_53 -> V_144 >> V_15 ) & 0x01 ) ) ;
}
static T_4
F_62 ( struct V_18 * V_19 , struct V_148 * V_43 , const char * V_149 ,
T_5 V_35 )
{
struct V_28 * V_150 = F_54 ( V_43 ) ;
struct V_52 * V_53 = F_45 ( V_19 ) ;
int V_15 = V_53 -> V_161 [ V_150 -> V_48 ] ;
int V_162 = V_15 >> 3 ;
unsigned long V_3 ;
int V_151 ;
V_151 = F_56 ( V_149 , 10 , & V_3 ) ;
if ( V_151 < 0 )
return V_151 ;
if ( V_3 > 1 )
return - V_36 ;
F_50 ( & V_53 -> V_115 ) ;
if ( V_3 )
V_53 -> V_144 |= ( 1ULL << V_15 ) ;
else
V_53 -> V_144 &= ~ ( 1ULL << V_15 ) ;
F_32 ( V_53 , V_53 -> V_147 [ V_162 ] ,
( V_53 -> V_144 >> ( V_162 << 3 ) ) & 0xff ) ;
F_52 ( & V_53 -> V_115 ) ;
return V_35 ;
}
static T_4
F_63 ( struct V_18 * V_19 , struct V_148 * V_43 , char * V_149 )
{
struct V_26 * V_150 = F_58 ( V_43 ) ;
struct V_52 * V_53 = F_49 ( V_19 ) ;
unsigned int V_146 = 0 ;
int V_15 ;
V_15 = F_59 ( V_53 , V_150 -> V_48 , V_53 -> V_163 ) ;
if ( V_15 >= 0 ) {
int V_159 = V_53 -> V_161 [ V_15 + V_160 ] ;
V_146 = ( V_53 -> V_144 >> V_159 ) & 0x01 ;
}
return sprintf ( V_149 , L_3 , V_146 ) ;
}
static T_4
F_64 ( struct V_18 * V_19 , struct V_148 * V_43 ,
const char * V_149 , T_5 V_35 )
{
struct V_28 * V_150 = F_54 ( V_43 ) ;
struct V_52 * V_53 = F_45 ( V_19 ) ;
int V_15 , V_159 , V_162 ;
unsigned long V_3 ;
int V_151 ;
V_151 = F_56 ( V_149 , 10 , & V_3 ) ;
if ( V_151 < 0 )
return V_151 ;
if ( V_3 > 1 )
return - V_36 ;
V_15 = F_59 ( V_53 , V_150 -> V_48 , V_53 -> V_163 ) ;
if ( V_15 < 0 )
return V_15 ;
V_159 = V_53 -> V_161 [ V_15 + V_160 ] ;
V_162 = V_159 >> 3 ;
F_50 ( & V_53 -> V_115 ) ;
if ( V_3 )
V_53 -> V_144 |= ( 1ULL << V_159 ) ;
else
V_53 -> V_144 &= ~ ( 1ULL << V_159 ) ;
F_32 ( V_53 , V_53 -> V_147 [ V_162 ] ,
( V_53 -> V_144 >> ( V_162 << 3 ) ) & 0xff ) ;
F_52 ( & V_53 -> V_115 ) ;
return V_35 ;
}
static T_6 F_65 ( struct V_164 * V_165 ,
struct V_30 * V_43 , int V_48 )
{
struct V_18 * V_19 = F_66 ( V_165 , struct V_18 , V_165 ) ;
struct V_52 * V_53 = F_45 ( V_19 ) ;
int V_122 = V_48 / 5 ;
if ( ! ( V_53 -> V_121 & ( 1 << V_122 ) ) )
return 0 ;
return V_43 -> V_10 ;
}
static T_4
F_67 ( struct V_18 * V_19 , struct V_148 * V_43 , char * V_149 )
{
struct V_52 * V_53 = F_49 ( V_19 ) ;
struct V_26 * V_150 = F_58 ( V_43 ) ;
int V_15 = V_150 -> V_48 ;
return sprintf ( V_149 , L_4 , V_53 -> V_125 [ V_15 ] ) ;
}
static T_4
F_68 ( struct V_18 * V_19 , struct V_148 * V_43 , char * V_149 )
{
struct V_52 * V_53 = F_49 ( V_19 ) ;
struct V_26 * V_150 = F_58 ( V_43 ) ;
int V_15 = V_150 -> V_48 ;
return sprintf ( V_149 , L_4 ,
V_53 -> V_166 ( V_53 -> V_75 [ V_15 ] ,
V_53 -> V_71 [ V_15 ] ) ) ;
}
static T_4
F_69 ( struct V_18 * V_19 , struct V_148 * V_43 , char * V_149 )
{
struct V_52 * V_53 = F_49 ( V_19 ) ;
struct V_26 * V_150 = F_58 ( V_43 ) ;
int V_15 = V_150 -> V_48 ;
return sprintf ( V_149 , L_3 , F_19 ( V_53 -> V_71 [ V_15 ] ) ) ;
}
static T_4
F_70 ( struct V_18 * V_19 , struct V_148 * V_43 ,
const char * V_149 , T_5 V_35 )
{
struct V_52 * V_53 = F_45 ( V_19 ) ;
struct V_26 * V_150 = F_58 ( V_43 ) ;
int V_15 = V_150 -> V_48 ;
unsigned long V_3 ;
unsigned int V_2 ;
T_1 V_167 ;
int V_151 ;
V_151 = F_56 ( V_149 , 10 , & V_3 ) ;
if ( V_151 < 0 )
return V_151 ;
F_50 ( & V_53 -> V_115 ) ;
if ( ! V_53 -> V_74 ) {
if ( ! V_3 ) {
V_3 = 0xff1f ;
} else {
if ( V_3 > 1350000U )
V_3 = 135000U ;
V_3 = 1350000U / V_3 ;
V_3 = ( V_3 & 0x1f ) | ( ( V_3 << 3 ) & 0xff00 ) ;
}
V_53 -> V_75 [ V_15 ] = V_3 ;
goto V_168;
}
if ( ! V_3 ) {
V_53 -> V_75 [ V_15 ] = 255 ;
V_167 = V_53 -> V_71 [ V_15 ] ;
F_71 ( V_19 , L_5 , V_15 + 1 ) ;
goto V_169;
}
V_2 = 1350000U / V_3 ;
if ( V_2 >= 128 * 255 ) {
V_53 -> V_75 [ V_15 ] = 254 ;
V_167 = 7 ;
F_72 ( V_19 ,
L_6 ,
V_15 + 1 , V_3 , V_53 -> V_166 ( 254 , 7 ) ) ;
} else if ( ! V_2 ) {
V_53 -> V_75 [ V_15 ] = 1 ;
V_167 = 0 ;
F_72 ( V_19 ,
L_7 ,
V_15 + 1 , V_3 , V_53 -> V_166 ( 1 , 0 ) ) ;
} else {
V_167 = 0 ;
while ( V_2 > 192 && V_167 < 7 ) {
V_2 >>= 1 ;
V_167 ++ ;
}
V_53 -> V_75 [ V_15 ] = V_2 ;
}
V_169:
if ( V_167 != V_53 -> V_71 [ V_15 ] ) {
F_43 ( V_19 , L_8 ,
V_15 + 1 , F_19 ( V_53 -> V_71 [ V_15 ] ) ,
F_19 ( V_167 ) ) ;
V_53 -> V_71 [ V_15 ] = V_167 ;
F_36 ( V_53 , V_15 ) ;
V_53 -> V_117 = V_116 ;
}
V_168:
F_32 ( V_53 , V_53 -> V_77 [ V_15 ] , V_53 -> V_75 [ V_15 ] ) ;
F_52 ( & V_53 -> V_115 ) ;
return V_35 ;
}
static T_4
F_73 ( struct V_18 * V_19 , struct V_148 * V_43 , char * V_149 )
{
struct V_52 * V_53 = F_49 ( V_19 ) ;
struct V_26 * V_150 = F_58 ( V_43 ) ;
int V_170 = V_53 -> V_128 [ V_150 -> V_48 ] ;
return sprintf ( V_149 , L_4 , V_170 ? : 4 ) ;
}
static T_4
F_74 ( struct V_18 * V_19 , struct V_148 * V_43 ,
const char * V_149 , T_5 V_35 )
{
struct V_52 * V_53 = F_45 ( V_19 ) ;
struct V_26 * V_150 = F_58 ( V_43 ) ;
int V_15 = V_150 -> V_48 ;
unsigned long V_3 ;
int V_151 ;
T_1 V_2 ;
V_151 = F_56 ( V_149 , 10 , & V_3 ) ;
if ( V_151 < 0 )
return V_151 ;
if ( V_3 > 4 )
return - V_36 ;
F_50 ( & V_53 -> V_115 ) ;
V_53 -> V_128 [ V_15 ] = V_3 & 3 ;
V_2 = F_30 ( V_53 , V_53 -> V_129 [ V_15 ] ) ;
V_2 &= ~ ( 0x03 << V_53 -> V_130 [ V_15 ] ) ;
V_2 |= ( V_3 & 3 ) << V_53 -> V_130 [ V_15 ] ;
F_32 ( V_53 , V_53 -> V_129 [ V_15 ] , V_2 ) ;
F_52 ( & V_53 -> V_115 ) ;
return V_35 ;
}
static T_6 F_75 ( struct V_164 * V_165 ,
struct V_30 * V_43 , int V_48 )
{
struct V_18 * V_19 = F_66 ( V_165 , struct V_18 , V_165 ) ;
struct V_52 * V_53 = F_45 ( V_19 ) ;
int V_14 = V_48 / 6 ;
int V_15 = V_48 % 6 ;
if ( ! ( V_53 -> V_73 & ( 1 << V_14 ) ) )
return 0 ;
if ( V_15 == 1 && V_53 -> V_152 [ V_171 + V_14 ] == - 1 )
return 0 ;
if ( V_15 == 2 && V_53 -> V_161 [ V_171 + V_14 ] == - 1 )
return 0 ;
if ( V_15 == 4 && ! ( V_53 -> V_76 & ( 1 << V_14 ) ) )
return 0 ;
if ( V_15 == 5 && V_53 -> V_54 != V_56 )
return 0 ;
return V_43 -> V_10 ;
}
static T_4
F_76 ( struct V_18 * V_19 , struct V_148 * V_43 , char * V_149 )
{
struct V_52 * V_53 = F_49 ( V_19 ) ;
struct V_26 * V_150 = F_58 ( V_43 ) ;
int V_15 = V_150 -> V_48 ;
return sprintf ( V_149 , L_9 , V_53 -> V_172 [ V_53 -> V_154 [ V_15 ] ] ) ;
}
static T_4
F_77 ( struct V_18 * V_19 , struct V_148 * V_43 , char * V_149 )
{
struct V_52 * V_53 = F_49 ( V_19 ) ;
struct V_28 * V_150 = F_54 ( V_43 ) ;
int V_15 = V_150 -> V_15 ;
int V_48 = V_150 -> V_48 ;
return sprintf ( V_149 , L_4 , F_78 ( V_53 -> V_134 [ V_48 ] [ V_15 ] ) ) ;
}
static T_4
F_79 ( struct V_18 * V_19 , struct V_148 * V_43 , const char * V_149 ,
T_5 V_35 )
{
struct V_52 * V_53 = F_45 ( V_19 ) ;
struct V_28 * V_150 = F_54 ( V_43 ) ;
int V_15 = V_150 -> V_15 ;
int V_48 = V_150 -> V_48 ;
int V_151 ;
long V_3 ;
V_151 = F_80 ( V_149 , 10 , & V_3 ) ;
if ( V_151 < 0 )
return V_151 ;
F_50 ( & V_53 -> V_115 ) ;
V_53 -> V_134 [ V_48 ] [ V_15 ] = F_81 ( V_3 ) ;
F_34 ( V_53 , V_53 -> V_133 [ V_48 ] [ V_15 ] ,
V_53 -> V_134 [ V_48 ] [ V_15 ] ) ;
F_52 ( & V_53 -> V_115 ) ;
return V_35 ;
}
static T_4
F_82 ( struct V_18 * V_19 , struct V_148 * V_43 , char * V_149 )
{
struct V_52 * V_53 = F_49 ( V_19 ) ;
struct V_26 * V_150 = F_58 ( V_43 ) ;
return sprintf ( V_149 , L_4 , V_53 -> V_137 [ V_150 -> V_48 ] * 1000 ) ;
}
static T_4
F_83 ( struct V_18 * V_19 , struct V_148 * V_43 ,
const char * V_149 , T_5 V_35 )
{
struct V_52 * V_53 = F_45 ( V_19 ) ;
struct V_26 * V_150 = F_58 ( V_43 ) ;
int V_15 = V_150 -> V_48 ;
long V_3 ;
int V_151 ;
V_151 = F_80 ( V_149 , 10 , & V_3 ) ;
if ( V_151 < 0 )
return V_151 ;
V_3 = F_14 ( F_21 ( V_3 , 1000 ) , - 128 , 127 ) ;
F_50 ( & V_53 -> V_115 ) ;
V_53 -> V_137 [ V_15 ] = V_3 ;
F_32 ( V_53 , V_53 -> V_138 [ V_15 ] , V_3 ) ;
F_52 ( & V_53 -> V_115 ) ;
return V_35 ;
}
static T_4
F_84 ( struct V_18 * V_19 , struct V_148 * V_43 , char * V_149 )
{
struct V_52 * V_53 = F_49 ( V_19 ) ;
struct V_26 * V_150 = F_58 ( V_43 ) ;
int V_15 = V_150 -> V_48 ;
return sprintf ( V_149 , L_4 , ( int ) V_53 -> V_173 [ V_15 ] ) ;
}
static T_4
F_85 ( struct V_18 * V_19 , struct V_148 * V_43 ,
const char * V_149 , T_5 V_35 )
{
struct V_52 * V_53 = F_49 ( V_19 ) ;
struct V_26 * V_150 = F_58 ( V_43 ) ;
int V_15 = V_150 -> V_48 ;
unsigned long V_3 ;
int V_151 ;
T_1 V_174 , V_175 , V_176 , V_177 ;
V_151 = F_56 ( V_149 , 10 , & V_3 ) ;
if ( V_151 < 0 )
return V_151 ;
if ( V_3 != 1 && V_3 != 3 && V_3 != 4 )
return - V_36 ;
F_50 ( & V_53 -> V_115 ) ;
V_53 -> V_173 [ V_15 ] = V_3 ;
V_176 = 0x02 << V_15 ;
V_177 = V_53 -> V_178 << V_15 ;
V_174 = F_30 ( V_53 , V_53 -> V_179 ) & ~ V_176 ;
V_175 = F_30 ( V_53 , V_53 -> V_180 ) & ~ V_177 ;
switch ( V_3 ) {
case 1 :
V_174 |= V_176 ;
V_175 |= V_177 ;
break;
case 3 :
V_174 |= V_177 ;
break;
case 4 :
break;
}
F_32 ( V_53 , V_53 -> V_179 , V_174 ) ;
F_32 ( V_53 , V_53 -> V_180 , V_175 ) ;
F_52 ( & V_53 -> V_115 ) ;
return V_35 ;
}
static T_6 F_86 ( struct V_164 * V_165 ,
struct V_30 * V_43 , int V_48 )
{
struct V_18 * V_19 = F_66 ( V_165 , struct V_18 , V_165 ) ;
struct V_52 * V_53 = F_45 ( V_19 ) ;
int V_134 = V_48 / 10 ;
int V_15 = V_48 % 10 ;
if ( ! ( V_53 -> V_132 & ( 1 << V_134 ) ) )
return 0 ;
if ( V_15 == 2 && F_59 ( V_53 , V_134 , V_53 -> V_158 ) < 0 )
return 0 ;
if ( V_15 == 3 && F_59 ( V_53 , V_134 , V_53 -> V_163 ) < 0 )
return 0 ;
if ( V_15 == 4 && ! V_53 -> V_133 [ 1 ] [ V_134 ] )
return 0 ;
if ( V_15 == 5 && ! V_53 -> V_133 [ 2 ] [ V_134 ] )
return 0 ;
if ( V_15 == 6 && ! V_53 -> V_133 [ 3 ] [ V_134 ] )
return 0 ;
if ( V_15 == 7 && ! V_53 -> V_133 [ 4 ] [ V_134 ] )
return 0 ;
if ( V_15 > 7 && ! ( V_53 -> V_136 & ( 1 << V_134 ) ) )
return 0 ;
return V_43 -> V_10 ;
}
static T_4
F_87 ( struct V_18 * V_19 , struct V_148 * V_43 , char * V_149 )
{
struct V_52 * V_53 = F_49 ( V_19 ) ;
struct V_26 * V_150 = F_58 ( V_43 ) ;
return sprintf ( V_149 , L_4 , ! V_53 -> V_85 [ V_150 -> V_48 ] ) ;
}
static T_4
F_88 ( struct V_18 * V_19 , struct V_148 * V_43 ,
const char * V_149 , T_5 V_35 )
{
struct V_52 * V_53 = F_45 ( V_19 ) ;
struct V_26 * V_150 = F_58 ( V_43 ) ;
int V_15 = V_150 -> V_48 ;
unsigned long V_3 ;
int V_151 ;
T_1 V_2 ;
V_151 = F_56 ( V_149 , 10 , & V_3 ) ;
if ( V_151 < 0 )
return V_151 ;
if ( V_3 > 1 )
return - V_36 ;
if ( V_53 -> V_83 [ V_15 ] == 0 ) {
if ( V_3 )
return - V_36 ;
return V_35 ;
}
F_50 ( & V_53 -> V_115 ) ;
V_53 -> V_85 [ V_15 ] = V_3 ;
V_2 = F_30 ( V_53 , V_53 -> V_83 [ V_15 ] ) ;
V_2 &= ~ V_53 -> V_84 [ V_15 ] ;
if ( V_3 )
V_2 |= V_53 -> V_84 [ V_15 ] ;
F_32 ( V_53 , V_53 -> V_83 [ V_15 ] , V_2 ) ;
F_52 ( & V_53 -> V_115 ) ;
return V_35 ;
}
static T_4
F_89 ( struct V_18 * V_19 , struct V_148 * V_43 , char * V_149 )
{
struct V_52 * V_53 = F_49 ( V_19 ) ;
struct V_28 * V_150 = F_54 ( V_43 ) ;
int V_15 = V_150 -> V_15 ;
int V_48 = V_150 -> V_48 ;
int V_9 ;
if ( V_48 == 0 && V_53 -> V_8 [ V_15 ] > V_181 )
V_9 = F_30 ( V_53 , V_53 -> V_182 [ V_15 ] ) ;
else
V_9 = V_53 -> V_9 [ V_48 ] [ V_15 ] ;
return sprintf ( V_149 , L_4 , V_9 ) ;
}
static T_4
F_90 ( struct V_18 * V_19 , struct V_148 * V_43 , const char * V_149 ,
T_5 V_35 )
{
struct V_52 * V_53 = F_45 ( V_19 ) ;
struct V_28 * V_150 = F_54 ( V_43 ) ;
int V_15 = V_150 -> V_15 ;
int V_48 = V_150 -> V_48 ;
unsigned long V_3 ;
int V_183 [ 7 ] = { 0 , 1 , 1 , V_53 -> V_9 [ 2 ] [ V_15 ] , 0 , 0 , 0 } ;
int V_184 [ 7 ]
= { 255 , 255 , V_53 -> V_9 [ 3 ] [ V_15 ] ? : 255 , 255 , 255 , 255 , 255 } ;
int V_151 ;
T_1 V_2 ;
V_151 = F_56 ( V_149 , 10 , & V_3 ) ;
if ( V_151 < 0 )
return V_151 ;
V_3 = F_14 ( V_3 , V_183 [ V_48 ] , V_184 [ V_48 ] ) ;
F_50 ( & V_53 -> V_115 ) ;
V_53 -> V_9 [ V_48 ] [ V_15 ] = V_3 ;
F_32 ( V_53 , V_53 -> V_87 [ V_48 ] [ V_15 ] , V_3 ) ;
if ( V_48 == 2 ) {
V_2 = F_30 ( V_53 , V_53 -> V_93 [ V_15 ] ) ;
V_2 &= 0x7f ;
if ( V_3 )
V_2 |= 0x80 ;
F_32 ( V_53 , V_53 -> V_93 [ V_15 ] , V_2 ) ;
}
F_52 ( & V_53 -> V_115 ) ;
return V_35 ;
}
static int F_91 ( struct V_52 * V_53 , int V_15 )
{
int V_34 ;
for ( V_34 = 0 ; V_34 < V_53 -> V_107 - 1 ; V_34 ++ ) {
if ( V_53 -> V_109 [ V_15 ] [ V_34 ] > V_53 -> V_109 [ V_15 ] [ V_34 + 1 ] )
return - V_36 ;
}
for ( V_34 = 0 ; V_34 < V_53 -> V_107 - 1 ; V_34 ++ ) {
if ( V_53 -> V_108 [ V_15 ] [ V_34 ] > V_53 -> V_108 [ V_15 ] [ V_34 + 1 ] )
return - V_36 ;
}
if ( V_53 -> V_108 [ V_15 ] [ V_53 -> V_107 ] ) {
if ( V_53 -> V_109 [ V_15 ] [ V_53 -> V_107 - 1 ] >
V_53 -> V_109 [ V_15 ] [ V_53 -> V_107 ] ||
V_53 -> V_108 [ V_15 ] [ V_53 -> V_107 - 1 ] >
V_53 -> V_108 [ V_15 ] [ V_53 -> V_107 ] )
return - V_36 ;
}
return 0 ;
}
static void F_92 ( struct V_52 * V_53 , int V_15 )
{
T_1 V_2 ;
switch ( V_53 -> V_8 [ V_15 ] ) {
case V_11 :
case V_181 :
break;
case V_89 :
V_2 = F_30 ( V_53 , V_53 -> V_86 [ V_15 ] ) ;
V_2 = ( V_2 & ~ V_53 -> V_185 ) |
( V_53 -> V_90 [ V_15 ] & V_53 -> V_185 ) ;
F_32 ( V_53 , V_53 -> V_86 [ V_15 ] , V_2 ) ;
F_32 ( V_53 , V_53 -> V_102 [ V_15 ] ,
V_53 -> V_106 [ V_15 ] & 0xff ) ;
if ( V_53 -> V_91 ) {
V_2 = ( V_53 -> V_106 [ V_15 ] >> 8 ) & 0x0f ;
V_2 |= ( V_53 -> V_90 [ V_15 ] & 0x38 ) << 1 ;
F_32 ( V_53 ,
V_53 -> V_91 [ V_15 ] ,
V_2 ) ;
}
break;
case V_104 :
F_32 ( V_53 , V_53 -> V_102 [ V_15 ] ,
V_53 -> V_103 [ V_15 ] ) ;
default:
V_2 = F_30 ( V_53 , V_53 -> V_86 [ V_15 ] ) ;
V_2 = ( V_2 & ~ V_53 -> V_185 ) |
V_53 -> V_88 [ 0 ] [ V_15 ] ;
F_32 ( V_53 , V_53 -> V_86 [ V_15 ] , V_2 ) ;
break;
}
}
static T_4
F_93 ( struct V_18 * V_19 , struct V_148 * V_43 , char * V_149 )
{
struct V_52 * V_53 = F_49 ( V_19 ) ;
struct V_26 * V_150 = F_58 ( V_43 ) ;
return sprintf ( V_149 , L_4 , V_53 -> V_8 [ V_150 -> V_48 ] ) ;
}
static T_4
F_94 ( struct V_18 * V_19 , struct V_148 * V_43 ,
const char * V_149 , T_5 V_35 )
{
struct V_52 * V_53 = F_45 ( V_19 ) ;
struct V_26 * V_150 = F_58 ( V_43 ) ;
int V_15 = V_150 -> V_48 ;
unsigned long V_3 ;
int V_151 ;
T_2 V_2 ;
V_151 = F_56 ( V_149 , 10 , & V_3 ) ;
if ( V_151 < 0 )
return V_151 ;
if ( V_3 > V_186 )
return - V_36 ;
if ( V_3 == V_187 && V_53 -> V_54 != V_56 )
return - V_36 ;
if ( V_3 == V_186 && F_91 ( V_53 , V_15 ) ) {
F_95 ( V_19 , L_10 ) ;
F_95 ( V_19 , L_11 ) ;
return - V_36 ;
}
F_50 ( & V_53 -> V_115 ) ;
V_53 -> V_8 [ V_15 ] = V_3 ;
if ( V_3 == V_11 ) {
V_53 -> V_9 [ 0 ] [ V_15 ] = 255 ;
F_32 ( V_53 , V_53 -> V_87 [ 0 ] [ V_15 ] , 255 ) ;
}
F_92 ( V_53 , V_15 ) ;
V_2 = F_30 ( V_53 , V_53 -> V_86 [ V_15 ] ) ;
V_2 &= 0x0f ;
V_2 |= F_11 ( V_3 ) << 4 ;
F_32 ( V_53 , V_53 -> V_86 [ V_15 ] , V_2 ) ;
F_52 ( & V_53 -> V_115 ) ;
return V_35 ;
}
static T_4
F_96 ( struct V_52 * V_53 , char * V_149 , int V_155 )
{
int V_34 , V_188 = 0 ;
for ( V_34 = 0 ; V_34 < V_131 ; V_34 ++ ) {
if ( ! ( V_53 -> V_132 & ( 1 << V_34 ) ) )
continue;
if ( V_155 == V_53 -> V_154 [ V_34 ] ) {
V_188 = V_34 + 1 ;
break;
}
}
return sprintf ( V_149 , L_4 , V_188 ) ;
}
static T_4
F_97 ( struct V_18 * V_19 , struct V_148 * V_43 , char * V_149 )
{
struct V_52 * V_53 = F_49 ( V_19 ) ;
struct V_26 * V_150 = F_58 ( V_43 ) ;
int V_48 = V_150 -> V_48 ;
return F_96 ( V_53 , V_149 , V_53 -> V_94 [ V_48 ] ) ;
}
static T_4
F_98 ( struct V_18 * V_19 , struct V_148 * V_43 ,
const char * V_149 , T_5 V_35 )
{
struct V_52 * V_53 = F_49 ( V_19 ) ;
struct V_26 * V_150 = F_58 ( V_43 ) ;
int V_15 = V_150 -> V_48 ;
unsigned long V_3 ;
int V_151 , V_2 , V_155 ;
V_151 = F_56 ( V_149 , 10 , & V_3 ) ;
if ( V_151 < 0 )
return V_151 ;
if ( V_3 == 0 || V_3 > V_131 )
return - V_36 ;
if ( ! ( V_53 -> V_132 & ( 1 << ( V_3 - 1 ) ) ) || ! V_53 -> V_154 [ V_3 - 1 ] )
return - V_36 ;
F_50 ( & V_53 -> V_115 ) ;
V_155 = V_53 -> V_154 [ V_3 - 1 ] ;
V_53 -> V_94 [ V_15 ] = V_155 ;
V_2 = F_30 ( V_53 , V_53 -> V_93 [ V_15 ] ) ;
V_2 &= 0xe0 ;
V_2 |= V_155 ;
F_32 ( V_53 , V_53 -> V_93 [ V_15 ] , V_2 ) ;
F_52 ( & V_53 -> V_115 ) ;
return V_35 ;
}
static T_4
F_99 ( struct V_18 * V_19 , struct V_148 * V_43 ,
char * V_149 )
{
struct V_52 * V_53 = F_49 ( V_19 ) ;
struct V_26 * V_150 = F_58 ( V_43 ) ;
int V_48 = V_150 -> V_48 ;
return F_96 ( V_53 , V_149 ,
V_53 -> V_96 [ V_48 ] ) ;
}
static T_4
F_100 ( struct V_18 * V_19 , struct V_148 * V_43 ,
const char * V_149 , T_5 V_35 )
{
struct V_52 * V_53 = F_49 ( V_19 ) ;
struct V_26 * V_150 = F_58 ( V_43 ) ;
int V_15 = V_150 -> V_48 ;
unsigned long V_3 ;
int V_151 , V_2 , V_155 ;
V_151 = F_56 ( V_149 , 10 , & V_3 ) ;
if ( V_151 < 0 )
return V_151 ;
if ( V_3 > V_131 )
return - V_36 ;
if ( V_3 && ( ! ( V_53 -> V_132 & ( 1 << ( V_3 - 1 ) ) ) ||
! V_53 -> V_154 [ V_3 - 1 ] ) )
return - V_36 ;
F_50 ( & V_53 -> V_115 ) ;
if ( V_3 ) {
V_155 = V_53 -> V_154 [ V_3 - 1 ] ;
V_53 -> V_96 [ V_15 ] = V_155 ;
V_2 = F_30 ( V_53 , V_53 -> V_95 [ V_15 ] ) ;
V_2 &= 0xe0 ;
V_2 |= ( V_155 | 0x80 ) ;
F_32 ( V_53 , V_53 -> V_95 [ V_15 ] , V_2 ) ;
} else {
V_53 -> V_96 [ V_15 ] = 0 ;
V_2 = F_30 ( V_53 , V_53 -> V_95 [ V_15 ] ) ;
V_2 &= 0x7f ;
F_32 ( V_53 , V_53 -> V_95 [ V_15 ] , V_2 ) ;
}
F_52 ( & V_53 -> V_115 ) ;
return V_35 ;
}
static T_4
F_101 ( struct V_18 * V_19 , struct V_148 * V_43 , char * V_149 )
{
struct V_52 * V_53 = F_49 ( V_19 ) ;
struct V_26 * V_150 = F_58 ( V_43 ) ;
return sprintf ( V_149 , L_4 , V_53 -> V_103 [ V_150 -> V_48 ] * 1000 ) ;
}
static T_4
F_102 ( struct V_18 * V_19 , struct V_148 * V_43 ,
const char * V_149 , T_5 V_35 )
{
struct V_52 * V_53 = F_45 ( V_19 ) ;
struct V_26 * V_150 = F_58 ( V_43 ) ;
int V_15 = V_150 -> V_48 ;
unsigned long V_3 ;
int V_151 ;
V_151 = F_56 ( V_149 , 10 , & V_3 ) ;
if ( V_151 < 0 )
return V_151 ;
V_3 = F_14 ( F_21 ( V_3 , 1000 ) , 0 ,
V_53 -> V_105 ) ;
F_50 ( & V_53 -> V_115 ) ;
V_53 -> V_103 [ V_15 ] = V_3 ;
F_92 ( V_53 , V_15 ) ;
F_52 ( & V_53 -> V_115 ) ;
return V_35 ;
}
static T_4
F_103 ( struct V_18 * V_19 , struct V_148 * V_43 , char * V_149 )
{
struct V_52 * V_53 = F_49 ( V_19 ) ;
struct V_26 * V_150 = F_58 ( V_43 ) ;
int V_15 = V_150 -> V_48 ;
return sprintf ( V_149 , L_4 ,
F_17 ( V_53 -> V_106 [ V_15 ] ,
V_53 -> V_71 [ V_15 ] ) ) ;
}
static T_4
F_104 ( struct V_18 * V_19 , struct V_148 * V_43 ,
const char * V_149 , T_5 V_35 )
{
struct V_52 * V_53 = F_45 ( V_19 ) ;
struct V_26 * V_150 = F_58 ( V_43 ) ;
int V_15 = V_150 -> V_48 ;
unsigned long V_3 ;
int V_151 ;
T_2 V_189 ;
V_151 = F_56 ( V_149 , 10 , & V_3 ) ;
if ( V_151 < 0 )
return V_151 ;
V_3 = F_14 ( V_3 , 0 , 1350000U ) ;
V_189 = F_18 ( V_3 , V_53 -> V_71 [ V_15 ] ) ;
F_50 ( & V_53 -> V_115 ) ;
V_53 -> V_106 [ V_15 ] = V_189 ;
F_92 ( V_53 , V_15 ) ;
F_52 ( & V_53 -> V_115 ) ;
return V_35 ;
}
static T_4
F_105 ( struct V_18 * V_19 , struct V_148 * V_43 ,
char * V_149 )
{
struct V_52 * V_53 = F_49 ( V_19 ) ;
struct V_28 * V_150 = F_54 ( V_43 ) ;
int V_15 = V_150 -> V_15 ;
int V_48 = V_150 -> V_48 ;
return sprintf ( V_149 , L_4 , V_53 -> V_88 [ V_48 ] [ V_15 ] * 1000 ) ;
}
static T_4
F_106 ( struct V_18 * V_19 , struct V_148 * V_43 ,
const char * V_149 , T_5 V_35 )
{
struct V_52 * V_53 = F_45 ( V_19 ) ;
struct V_28 * V_150 = F_54 ( V_43 ) ;
int V_15 = V_150 -> V_15 ;
int V_48 = V_150 -> V_48 ;
unsigned long V_3 ;
int V_151 ;
V_151 = F_56 ( V_149 , 10 , & V_3 ) ;
if ( V_151 < 0 )
return V_151 ;
V_3 = F_14 ( F_21 ( V_3 , 1000 ) , 0 , V_53 -> V_185 ) ;
F_50 ( & V_53 -> V_115 ) ;
V_53 -> V_88 [ V_48 ] [ V_15 ] = V_3 ;
if ( V_48 )
F_92 ( V_53 , V_15 ) ;
else
F_32 ( V_53 ,
V_53 -> V_92 [ V_15 ] ,
V_3 ) ;
F_52 ( & V_53 -> V_115 ) ;
return V_35 ;
}
static T_4
F_107 ( struct V_18 * V_19 , struct V_148 * V_43 ,
char * V_149 )
{
struct V_52 * V_53 = F_49 ( V_19 ) ;
struct V_26 * V_150 = F_58 ( V_43 ) ;
int V_15 = V_150 -> V_48 ;
int V_190 = V_53 -> V_106 [ V_15 ] - V_53 -> V_90 [ V_15 ] ;
int V_191 = V_53 -> V_106 [ V_15 ] + V_53 -> V_90 [ V_15 ] ;
int V_192 ;
if ( V_190 <= 0 )
V_190 = 1 ;
if ( V_191 > 0xffff )
V_191 = 0xffff ;
if ( V_191 < V_190 )
V_191 = V_190 ;
V_192 = ( F_17 ( V_190 , V_53 -> V_71 [ V_15 ] )
- F_17 ( V_191 , V_53 -> V_71 [ V_15 ] ) ) / 2 ;
return sprintf ( V_149 , L_4 , V_192 ) ;
}
static T_4
F_108 ( struct V_18 * V_19 , struct V_148 * V_43 ,
const char * V_149 , T_5 V_35 )
{
struct V_52 * V_53 = F_45 ( V_19 ) ;
struct V_26 * V_150 = F_58 ( V_43 ) ;
int V_15 = V_150 -> V_48 ;
unsigned long V_3 ;
int V_151 ;
int V_190 , V_191 ;
V_151 = F_56 ( V_149 , 10 , & V_3 ) ;
if ( V_151 < 0 )
return V_151 ;
V_191 = F_17 ( V_53 -> V_106 [ V_15 ] ,
V_53 -> V_71 [ V_15 ] ) + V_3 ;
V_190 = F_17 ( V_53 -> V_106 [ V_15 ] ,
V_53 -> V_71 [ V_15 ] ) - V_3 ;
if ( V_190 <= 0 )
V_190 = 1 ;
if ( V_191 < V_190 )
V_191 = V_190 ;
V_3 = ( F_18 ( V_190 , V_53 -> V_71 [ V_15 ] ) -
F_18 ( V_191 , V_53 -> V_71 [ V_15 ] ) ) / 2 ;
V_3 = F_14 ( V_3 , 0 , V_53 -> V_193 ) ;
F_50 ( & V_53 -> V_115 ) ;
V_53 -> V_90 [ V_15 ] = V_3 ;
F_92 ( V_53 , V_15 ) ;
F_52 ( & V_53 -> V_115 ) ;
return V_35 ;
}
static T_4
F_109 ( struct V_18 * V_19 , struct V_148 * V_43 , char * V_149 )
{
struct V_52 * V_53 = F_49 ( V_19 ) ;
struct V_28 * V_150 = F_54 ( V_43 ) ;
int V_15 = V_150 -> V_15 ;
int V_48 = V_150 -> V_48 ;
return sprintf ( V_149 , L_4 , V_53 -> V_97 [ V_48 ] [ V_15 ] * 1000 ) ;
}
static T_4
F_110 ( struct V_18 * V_19 , struct V_148 * V_43 ,
const char * V_149 , T_5 V_35 )
{
struct V_52 * V_53 = F_45 ( V_19 ) ;
struct V_28 * V_150 = F_54 ( V_43 ) ;
int V_15 = V_150 -> V_15 ;
int V_48 = V_150 -> V_48 ;
unsigned long V_3 ;
int V_151 ;
V_151 = F_56 ( V_149 , 10 , & V_3 ) ;
if ( V_151 < 0 )
return V_151 ;
V_3 = F_14 ( F_21 ( V_3 , 1000 ) , 0 , 255 ) ;
F_50 ( & V_53 -> V_115 ) ;
V_53 -> V_97 [ V_48 ] [ V_15 ] = V_3 ;
F_32 ( V_53 , V_53 -> V_98 [ V_48 ] [ V_15 ] , V_3 ) ;
F_52 ( & V_53 -> V_115 ) ;
return V_35 ;
}
static T_4
F_111 ( struct V_18 * V_19 , struct V_148 * V_43 , char * V_149 )
{
struct V_52 * V_53 = F_49 ( V_19 ) ;
struct V_28 * V_150 = F_54 ( V_43 ) ;
int V_15 = V_150 -> V_15 ;
int V_48 = V_150 -> V_48 ;
return sprintf ( V_149 , L_4 ,
F_12 ( V_53 -> V_100 [ V_48 ] [ V_15 ] ,
V_53 -> V_85 [ V_15 ] ) ) ;
}
static T_4
F_112 ( struct V_18 * V_19 , struct V_148 * V_43 ,
const char * V_149 , T_5 V_35 )
{
struct V_52 * V_53 = F_45 ( V_19 ) ;
struct V_28 * V_150 = F_54 ( V_43 ) ;
int V_15 = V_150 -> V_15 ;
int V_48 = V_150 -> V_48 ;
unsigned long V_3 ;
int V_151 ;
V_151 = F_56 ( V_149 , 10 , & V_3 ) ;
if ( V_151 < 0 )
return V_151 ;
V_3 = F_13 ( V_3 , V_53 -> V_85 [ V_15 ] ) ;
F_50 ( & V_53 -> V_115 ) ;
V_53 -> V_100 [ V_48 ] [ V_15 ] = V_3 ;
F_32 ( V_53 , V_53 -> V_101 [ V_48 ] [ V_15 ] , V_3 ) ;
F_52 ( & V_53 -> V_115 ) ;
return V_35 ;
}
static T_4
F_113 ( struct V_18 * V_19 , struct V_148 * V_43 , char * V_149 )
{
struct V_52 * V_53 = F_49 ( V_19 ) ;
struct V_28 * V_150 = F_54 ( V_43 ) ;
return sprintf ( V_149 , L_4 , V_53 -> V_108 [ V_150 -> V_15 ] [ V_150 -> V_48 ] ) ;
}
static T_4
F_114 ( struct V_18 * V_19 , struct V_148 * V_43 ,
const char * V_149 , T_5 V_35 )
{
struct V_52 * V_53 = F_45 ( V_19 ) ;
struct V_28 * V_150 = F_54 ( V_43 ) ;
int V_15 = V_150 -> V_15 ;
int V_194 = V_150 -> V_48 ;
unsigned long V_3 ;
int V_151 ;
T_1 V_2 ;
V_151 = F_56 ( V_149 , 10 , & V_3 ) ;
if ( V_151 < 0 )
return V_151 ;
if ( V_3 > 255 )
return - V_36 ;
if ( V_194 == V_53 -> V_107 ) {
if ( V_53 -> V_54 != V_56 && ! V_3 )
return - V_36 ;
if ( V_53 -> V_54 != V_58 && V_3 )
V_3 = 0xff ;
}
F_50 ( & V_53 -> V_115 ) ;
V_53 -> V_108 [ V_15 ] [ V_194 ] = V_3 ;
if ( V_194 < V_53 -> V_107 ) {
F_32 ( V_53 ,
F_47 ( V_53 , V_15 , V_194 ) ,
V_53 -> V_108 [ V_15 ] [ V_194 ] ) ;
} else {
switch ( V_53 -> V_54 ) {
case V_56 :
V_2 = F_30 ( V_53 ,
V_111 [ V_15 ] ) ;
if ( V_3 )
V_2 |= 0x02 ;
else
V_2 &= ~ 0x02 ;
F_32 ( V_53 , V_111 [ V_15 ] ,
V_2 ) ;
break;
case V_57 :
break;
case V_55 :
case V_58 :
case V_59 :
case V_60 :
case V_61 :
F_32 ( V_53 , V_53 -> V_114 [ V_15 ] ,
V_3 ) ;
V_2 = F_30 ( V_53 ,
V_53 -> V_112 [ V_15 ] ) ;
if ( V_3 == 255 )
V_2 &= ~ V_53 -> V_113 ;
else
V_2 |= V_53 -> V_113 ;
F_32 ( V_53 ,
V_53 -> V_112 [ V_15 ] ,
V_2 ) ;
break;
}
}
F_52 ( & V_53 -> V_115 ) ;
return V_35 ;
}
static T_4
F_115 ( struct V_18 * V_19 , struct V_148 * V_43 , char * V_149 )
{
struct V_52 * V_53 = F_49 ( V_19 ) ;
struct V_28 * V_150 = F_54 ( V_43 ) ;
int V_15 = V_150 -> V_15 ;
int V_194 = V_150 -> V_48 ;
return sprintf ( V_149 , L_4 , V_53 -> V_109 [ V_15 ] [ V_194 ] * 1000 ) ;
}
static T_4
F_116 ( struct V_18 * V_19 , struct V_148 * V_43 ,
const char * V_149 , T_5 V_35 )
{
struct V_52 * V_53 = F_45 ( V_19 ) ;
struct V_28 * V_150 = F_54 ( V_43 ) ;
int V_15 = V_150 -> V_15 ;
int V_194 = V_150 -> V_48 ;
unsigned long V_3 ;
int V_151 ;
V_151 = F_56 ( V_149 , 10 , & V_3 ) ;
if ( V_151 )
return V_151 ;
if ( V_3 > 255000 )
return - V_36 ;
F_50 ( & V_53 -> V_115 ) ;
V_53 -> V_109 [ V_15 ] [ V_194 ] = F_21 ( V_3 , 1000 ) ;
if ( V_194 < V_53 -> V_107 ) {
F_32 ( V_53 ,
F_48 ( V_53 , V_15 , V_194 ) ,
V_53 -> V_109 [ V_15 ] [ V_194 ] ) ;
} else {
F_32 ( V_53 , V_53 -> V_110 [ V_15 ] ,
V_53 -> V_109 [ V_15 ] [ V_194 ] ) ;
}
F_52 ( & V_53 -> V_115 ) ;
return V_35 ;
}
static T_6 F_117 ( struct V_164 * V_165 ,
struct V_30 * V_43 , int V_48 )
{
struct V_18 * V_19 = F_66 ( V_165 , struct V_18 , V_165 ) ;
struct V_52 * V_53 = F_45 ( V_19 ) ;
int V_9 = V_48 / 36 ;
int V_15 = V_48 % 36 ;
if ( ! ( V_53 -> V_82 & ( 1 << V_9 ) ) )
return 0 ;
if ( ( V_15 >= 14 && V_15 <= 18 ) || V_15 == 21 )
if ( ! V_53 -> V_95 [ V_9 ] )
return 0 ;
if ( V_15 == 19 && V_53 -> V_87 [ 3 ] == NULL )
return 0 ;
if ( V_15 == 20 && V_53 -> V_87 [ 4 ] == NULL )
return 0 ;
if ( V_15 == 21 && V_53 -> V_87 [ 6 ] == NULL )
return 0 ;
if ( V_15 >= 22 && V_15 <= 35 ) {
int V_195 = ( V_15 - 22 ) / 2 ;
if ( V_195 > V_53 -> V_107 )
return 0 ;
}
return V_43 -> V_10 ;
}
static T_4
F_118 ( struct V_18 * V_19 , struct V_148 * V_43 , char * V_149 )
{
struct V_52 * V_53 = F_45 ( V_19 ) ;
return sprintf ( V_149 , L_4 , F_119 ( V_53 -> V_196 , V_53 -> V_197 ) ) ;
}
static T_4
F_120 ( struct V_18 * V_19 , struct V_148 * V_43 ,
const char * V_149 , T_5 V_35 )
{
struct V_52 * V_53 = F_45 ( V_19 ) ;
int V_15 = F_58 ( V_43 ) -> V_48 - V_198 ;
unsigned long V_3 ;
T_1 V_2 ;
int V_199 ;
if ( F_56 ( V_149 , 10 , & V_3 ) || V_3 != 0 )
return - V_36 ;
F_50 ( & V_53 -> V_115 ) ;
V_199 = F_6 ( V_53 -> V_200 ) ;
if ( V_199 ) {
V_35 = V_199 ;
goto error;
}
F_5 ( V_53 -> V_200 , V_201 ) ;
V_2 = F_3 ( V_53 -> V_200 , V_202 [ V_15 ] ) ;
V_2 |= V_203 [ V_15 ] ;
F_1 ( V_53 -> V_200 , V_202 [ V_15 ] , V_2 ) ;
V_2 &= ~ V_203 [ V_15 ] ;
F_1 ( V_53 -> V_200 , V_202 [ V_15 ] , V_2 ) ;
F_8 ( V_53 -> V_200 ) ;
V_53 -> V_119 = false ;
error:
F_52 ( & V_53 -> V_115 ) ;
return V_35 ;
}
static T_6 F_121 ( struct V_164 * V_165 ,
struct V_30 * V_43 , int V_48 )
{
struct V_18 * V_19 = F_66 ( V_165 , struct V_18 , V_165 ) ;
struct V_52 * V_53 = F_45 ( V_19 ) ;
if ( V_48 == 0 && ! V_53 -> V_204 )
return 0 ;
if ( V_48 == 1 || V_48 == 2 ) {
if ( V_53 -> V_152 [ V_198 + V_48 - 1 ] < 0 )
return 0 ;
}
if ( V_48 == 3 || V_48 == 4 ) {
if ( V_53 -> V_161 [ V_198 + V_48 - 3 ] < 0 )
return 0 ;
}
return V_43 -> V_10 ;
}
static inline void F_122 ( struct V_52 * V_53 )
{
int V_34 ;
T_1 V_205 , V_175 ;
if ( V_53 -> V_206 ) {
V_205 = F_30 ( V_53 , V_53 -> V_206 ) ;
if ( ! ( V_205 & 0x01 ) )
F_32 ( V_53 , V_53 -> V_206 , V_205 | 0x01 ) ;
}
for ( V_34 = 0 ; V_34 < V_131 ; V_34 ++ ) {
if ( ! ( V_53 -> V_132 & ( 1 << V_34 ) ) )
continue;
if ( ! V_53 -> V_207 [ V_34 ] )
continue;
V_205 = F_30 ( V_53 , V_53 -> V_207 [ V_34 ] ) ;
if ( V_205 & 0x01 )
F_32 ( V_53 , V_53 -> V_207 [ V_34 ] ,
V_205 & 0xfe ) ;
}
V_205 = F_30 ( V_53 , V_53 -> V_179 ) ;
if ( ! ( V_205 & 0x01 ) )
F_32 ( V_53 , V_53 -> V_179 , V_205 | 0x01 ) ;
V_175 = F_30 ( V_53 , V_53 -> V_180 ) ;
for ( V_34 = 0 ; V_34 < V_53 -> V_208 ; V_34 ++ ) {
if ( ! ( V_53 -> V_136 & ( 1 << V_34 ) ) )
continue;
if ( ( V_205 & ( V_53 -> V_178 << V_34 ) ) )
V_53 -> V_173 [ V_34 ]
= 3 - ( ( V_175 >> V_34 ) & V_53 -> V_178 ) ;
else
V_53 -> V_173 [ V_34 ] = 4 ;
}
}
static void
F_123 ( struct V_52 * V_53 )
{
bool V_209 , V_210 , V_211 , V_212 , V_213 ;
bool V_214 , V_215 , V_216 , V_217 ;
int V_200 = V_53 -> V_200 ;
int V_218 ;
F_5 ( V_200 , V_219 ) ;
V_53 -> V_220 = F_3 ( V_200 , V_221 ) ;
if ( V_53 -> V_54 == V_56 ) {
V_218 = F_3 ( V_200 , 0x2c ) ;
V_209 = V_218 & ( 1 << 6 ) ;
V_214 = V_218 & ( 1 << 7 ) ;
V_210 = ! ( F_3 ( V_200 , 0x2A ) & 0x80 ) ;
V_211 = false ;
V_212 = false ;
V_213 = false ;
V_215 = false ;
V_216 = false ;
V_217 = false ;
} else if ( V_53 -> V_54 == V_57 ) {
bool V_222 = F_3 ( V_200 , 0x27 ) & 0x80 ;
const char * V_223 , * V_224 ;
V_223 = F_124 ( V_225 ) ;
V_224 = F_124 ( V_226 ) ;
if ( V_224 && V_223 &&
! strcmp ( V_223 , L_12 ) ) {
if ( ! strcmp ( V_224 , L_13 ) ) {
if ( ( V_53 -> V_220 & 0xe0 ) != 0xe0 ) {
V_53 -> V_220 |= 0xe0 ;
F_1 ( V_200 , V_221 ,
V_53 -> V_220 ) ;
}
}
}
if ( V_53 -> V_220 & 0x80 )
V_209 = V_222 ;
else
V_209 = ! ( F_3 ( V_200 , 0x24 ) & 0x40 ) ;
if ( V_53 -> V_220 & 0x40 )
V_210 = V_222 ;
else
V_210 = F_3 ( V_200 , 0x1C ) & 0x01 ;
if ( V_53 -> V_220 & 0x20 )
V_212 = V_222 ;
else
V_212 = F_3 ( V_200 , 0x1C ) & 0x02 ;
V_211 = V_210 ;
V_213 = false ;
V_214 = V_209 ;
V_215 = false ;
V_216 = false ;
V_217 = false ;
} else if ( V_53 -> V_54 == V_55 ) {
V_218 = F_3 ( V_200 , 0x24 ) ;
V_209 = ! ( V_218 & 0x80 ) ;
V_214 = V_218 & 0x08 ;
V_210 = false ;
V_211 = false ;
V_212 = false ;
V_213 = false ;
V_215 = false ;
V_216 = false ;
V_217 = false ;
} else {
V_218 = F_3 ( V_200 , 0x1c ) ;
V_209 = ! ( V_218 & ( 1 << 5 ) ) ;
V_210 = ! ( V_218 & ( 1 << 6 ) ) ;
V_212 = ! ( V_218 & ( 1 << 7 ) ) ;
V_214 = ! ( V_218 & ( 1 << 0 ) ) ;
V_215 = ! ( V_218 & ( 1 << 1 ) ) ;
V_216 = ! ( V_218 & ( 1 << 2 ) ) ;
V_211 = V_210 ;
if ( V_53 -> V_54 == V_59 || V_53 -> V_54 == V_60 ||
V_53 -> V_54 == V_61 ) {
V_218 = F_3 ( V_200 , 0x2d ) ;
V_213 = ( V_218 & ( 1 << 1 ) ) ;
V_217 = ( V_218 & ( 1 << 0 ) ) ;
} else {
V_213 = false ;
V_217 = false ;
}
}
V_53 -> V_73 = 0x03 | ( V_209 << 2 ) | ( V_210 << 3 ) |
( V_212 << 4 ) | ( V_213 << 5 ) ;
V_53 -> V_76 = 0x03 | ( V_209 << 2 ) | ( V_211 << 3 ) |
( V_212 << 4 ) ;
V_53 -> V_82 = 0x03 | ( V_214 << 2 ) | ( V_215 << 3 ) |
( V_216 << 4 ) | ( V_217 << 5 ) ;
}
static void F_125 ( struct V_52 * V_53 , const T_2 * V_227 ,
int * V_228 , int * V_229 )
{
int V_34 ;
T_1 V_155 ;
for ( V_34 = 0 ; V_34 < V_53 -> V_81 && * V_228 ; V_34 ++ ) {
int V_48 ;
if ( ! V_227 [ V_34 ] )
continue;
V_155 = F_30 ( V_53 , V_227 [ V_34 ] ) ;
V_155 &= 0x1f ;
if ( ! V_155 || ( * V_229 & ( 1 << V_155 ) ) )
continue;
if ( V_155 >= V_53 -> V_230 ||
! strlen ( V_53 -> V_172 [ V_155 ] ) )
continue;
V_48 = F_126 ( * V_228 ) ;
F_32 ( V_53 , V_53 -> V_156 [ V_48 ] , V_155 ) ;
* V_228 &= ~ ( 1 << V_48 ) ;
* V_229 |= 1 << V_155 ;
}
}
static int F_127 ( struct V_231 * V_232 )
{
struct V_18 * V_19 = & V_232 -> V_19 ;
struct V_233 * V_234 = F_128 ( V_19 ) ;
struct V_52 * V_53 ;
struct V_235 * V_67 ;
int V_34 , V_47 , V_151 = 0 ;
int V_155 , V_229 , V_228 ;
const T_2 * V_133 , * V_236 , * V_237 , * V_207 ;
const T_2 * V_238 , * V_239 , * V_240 ;
const T_2 * V_241 = NULL , * V_242 = NULL ;
int V_243 , V_244 ;
T_1 V_245 ;
struct V_17 * V_23 ;
struct V_18 * V_246 ;
int V_247 = 0 ;
V_67 = F_129 ( V_232 , V_248 , 0 ) ;
if ( ! F_130 ( & V_232 -> V_19 , V_67 -> V_249 , V_250 ,
V_6 ) )
return - V_7 ;
V_53 = F_25 ( & V_232 -> V_19 , sizeof( struct V_52 ) ,
V_38 ) ;
if ( ! V_53 )
return - V_39 ;
V_53 -> V_54 = V_234 -> V_54 ;
V_53 -> V_200 = V_234 -> V_200 ;
V_53 -> V_64 = V_67 -> V_249 ;
F_131 ( & V_53 -> V_115 ) ;
V_53 -> V_41 = V_251 [ V_53 -> V_54 ] ;
V_53 -> V_62 = 0xff ;
F_132 ( V_232 , V_53 ) ;
switch ( V_53 -> V_54 ) {
case V_55 :
V_53 -> V_120 = 9 ;
V_53 -> V_81 = 3 ;
V_53 -> V_107 = 4 ;
V_53 -> V_208 = 3 ;
V_53 -> V_158 = 6 ;
V_53 -> V_163 = 6 ;
V_53 -> V_127 = F_16 ;
V_53 -> V_166 = F_16 ;
V_53 -> V_172 = V_252 ;
V_53 -> V_230 = F_40 ( V_252 ) ;
V_53 -> V_179 = V_253 ;
V_53 -> V_180 = V_254 ;
V_53 -> V_178 = V_255 ;
V_53 -> V_123 = V_256 ;
V_53 -> V_124 [ 0 ] = V_257 ;
V_53 -> V_124 [ 1 ] = V_258 ;
V_53 -> V_102 = V_259 ;
V_53 -> V_126 = V_260 ;
V_53 -> V_86 = V_261 ;
V_53 -> V_77 = V_262 ;
V_53 -> V_129 = V_263 ;
V_53 -> V_130 = V_264 ;
V_53 -> V_101 [ 0 ] = V_265 ;
V_53 -> V_101 [ 1 ] = V_266 ;
V_53 -> V_101 [ 2 ] = V_267 ;
V_53 -> V_87 [ 0 ] = V_268 ;
V_53 -> V_87 [ 1 ] = V_269 ;
V_53 -> V_87 [ 2 ] = V_270 ;
V_53 -> V_87 [ 5 ] = V_271 ;
V_53 -> V_87 [ 6 ] = V_272 ;
V_53 -> V_182 = V_273 ;
V_53 -> V_83 = V_274 ;
V_53 -> V_84 = V_275 ;
V_53 -> V_276 = V_277 ;
V_53 -> V_278 = V_279 ;
V_53 -> V_110 = V_280 ;
V_53 -> V_92
= V_281 ;
V_53 -> V_112 = V_282 ;
V_53 -> V_113
= V_283 ;
V_53 -> V_114 = V_284 ;
V_53 -> V_138 = V_285 ;
V_53 -> V_156 = V_286 ;
V_53 -> V_93 = V_287 ;
V_53 -> V_95 = V_288 ;
V_53 -> V_98 [ 0 ] = V_289 ;
V_53 -> V_98 [ 1 ] = V_290 ;
V_53 -> V_98 [ 2 ] = V_291 ;
V_53 -> V_142 = V_292 ;
V_53 -> V_152 = V_293 ;
V_53 -> V_147 = V_294 ;
V_53 -> V_161 = V_295 ;
V_133 = V_296 ;
V_238 = V_297 ;
V_243 = F_40 ( V_296 ) ;
V_244 = F_40 ( V_297 ) ;
V_236 = V_298 ;
V_237 = V_299 ;
V_207 = V_300 ;
V_239 = V_301 ;
V_240 = V_302 ;
V_241 = V_303 ;
V_242 = V_304 ;
break;
case V_56 :
V_53 -> V_120 = 9 ;
V_53 -> V_81 = 3 ;
V_53 -> V_107 = 6 ;
V_53 -> V_74 = true ;
V_53 -> V_208 = 3 ;
V_53 -> V_158 = 3 ;
V_53 -> V_163 = 3 ;
V_53 -> V_152 = V_305 ;
V_53 -> V_161 = V_306 ;
V_53 -> V_127 = F_17 ;
V_53 -> V_166 = F_15 ;
V_53 -> V_105 = 0x7f ;
V_53 -> V_185 = 0x0f ;
V_53 -> V_193 = 15 ;
V_53 -> V_172 = V_307 ;
V_53 -> V_230 = F_40 ( V_307 ) ;
V_53 -> V_206 = V_308 ;
V_53 -> V_179 = V_309 ;
V_53 -> V_180 = V_310 ;
V_53 -> V_178 = V_311 ;
V_53 -> V_123 = V_312 ;
V_53 -> V_124 [ 0 ] = V_313 ;
V_53 -> V_124 [ 1 ] = V_314 ;
V_53 -> V_102 = V_315 ;
V_53 -> V_126 = V_316 ;
V_53 -> V_86 = V_317 ;
V_53 -> V_77 = V_318 ;
V_53 -> V_129 = V_319 ;
V_53 -> V_130 = V_320 ;
V_53 -> V_101 [ 0 ] = V_321 ;
V_53 -> V_101 [ 1 ] = V_322 ;
V_53 -> V_101 [ 2 ] = V_323 ;
V_53 -> V_87 [ 0 ] = V_324 ;
V_53 -> V_87 [ 1 ] = V_325 ;
V_53 -> V_87 [ 2 ] = V_326 ;
V_53 -> V_87 [ 3 ] = V_327 ;
V_53 -> V_87 [ 4 ] = V_328 ;
V_53 -> V_87 [ 5 ] = V_329 ;
V_53 -> V_182 = V_330 ;
V_53 -> V_83 = V_331 ;
V_53 -> V_84 = V_332 ;
V_53 -> V_276 = V_333 ;
V_53 -> V_278 = V_334 ;
V_53 -> V_110 = V_335 ;
V_53 -> V_92
= V_336 ;
V_53 -> V_138 = V_337 ;
V_53 -> V_156 = V_338 ;
V_53 -> V_93 = V_339 ;
V_53 -> V_95 = V_340 ;
V_53 -> V_98 [ 0 ] = V_341 ;
V_53 -> V_98 [ 1 ] = V_342 ;
V_53 -> V_98 [ 2 ] = V_343 ;
V_53 -> V_142 = V_344 ;
V_53 -> V_147 = V_345 ;
V_133 = V_346 ;
V_238 = V_347 ;
V_243 = F_40 ( V_346 ) ;
V_244 = F_40 ( V_347 ) ;
V_236 = V_348 ;
V_237 = V_349 ;
V_207 = V_350 ;
V_239 = V_351 ;
V_240 = V_352 ;
break;
case V_57 :
V_53 -> V_120 = 9 ;
V_53 -> V_81 = 3 ;
V_53 -> V_107 = 4 ;
V_53 -> V_74 = false ;
V_53 -> V_208 = 3 ;
V_53 -> V_158 = 3 ;
V_53 -> V_163 = 6 ;
V_53 -> V_152 = V_353 ;
V_53 -> V_161 = V_354 ;
V_53 -> V_127 = F_16 ;
V_53 -> V_166 = F_16 ;
V_53 -> V_105 = 0xff ;
V_53 -> V_185 = 0x07 ;
V_53 -> V_193 = 63 ;
V_53 -> V_172 = V_252 ;
V_53 -> V_230 = F_40 ( V_252 ) ;
V_53 -> V_206 = V_308 ;
V_53 -> V_179 = V_309 ;
V_53 -> V_180 = V_310 ;
V_53 -> V_178 = V_311 ;
V_53 -> V_123 = V_312 ;
V_53 -> V_124 [ 0 ] = V_313 ;
V_53 -> V_124 [ 1 ] = V_314 ;
V_53 -> V_102 = V_315 ;
V_53 -> V_126 = V_316 ;
V_53 -> V_86 = V_317 ;
V_53 -> V_77 = V_355 ;
V_53 -> V_129 = V_356 ;
V_53 -> V_130 = V_320 ;
V_53 -> V_101 [ 0 ] = V_321 ;
V_53 -> V_101 [ 1 ] = V_357 ;
V_53 -> V_101 [ 2 ] = V_358 ;
V_53 -> V_91 = V_359 ;
V_53 -> V_87 [ 0 ] = V_324 ;
V_53 -> V_87 [ 1 ] = V_325 ;
V_53 -> V_87 [ 2 ] = V_326 ;
V_53 -> V_87 [ 5 ] = V_329 ;
V_53 -> V_87 [ 6 ] = V_360 ;
V_53 -> V_182 = V_330 ;
V_53 -> V_83 = V_361 ;
V_53 -> V_84 = V_362 ;
V_53 -> V_276 = V_333 ;
V_53 -> V_278 = V_334 ;
V_53 -> V_110 = V_335 ;
V_53 -> V_92
= V_336 ;
V_53 -> V_138 = V_337 ;
V_53 -> V_156 = V_338 ;
V_53 -> V_93 = V_339 ;
V_53 -> V_95 = V_340 ;
V_53 -> V_98 [ 0 ] = V_341 ;
V_53 -> V_98 [ 1 ] = V_342 ;
V_53 -> V_98 [ 2 ] = V_343 ;
V_53 -> V_142 = V_344 ;
V_53 -> V_147 = V_363 ;
V_133 = V_346 ;
V_238 = V_347 ;
V_243 = F_40 ( V_346 ) ;
V_244 = F_40 ( V_347 ) ;
V_236 = V_348 ;
V_237 = V_349 ;
V_207 = V_364 ;
V_239 = V_365 ;
V_240 = V_366 ;
break;
case V_58 :
V_53 -> V_120 = 15 ;
V_53 -> V_81 = 5 ;
V_53 -> V_107 = 4 ;
V_53 -> V_74 = false ;
V_53 -> V_208 = 6 ;
V_53 -> V_158 = 2 ;
V_53 -> V_163 = 2 ;
V_53 -> V_152 = V_367 ;
V_53 -> V_161 = V_368 ;
V_53 -> V_127 = F_16 ;
V_53 -> V_166 = F_16 ;
V_53 -> V_105 = 0xff ;
V_53 -> V_185 = 0x07 ;
V_53 -> V_193 = 63 ;
V_53 -> V_172 = V_369 ;
V_53 -> V_230 = V_370 ;
V_53 -> V_206 = V_308 ;
V_53 -> V_179 = V_309 ;
V_53 -> V_180 = V_310 ;
V_53 -> V_178 = V_311 ;
V_53 -> V_123 = V_371 ;
V_53 -> V_124 [ 0 ] = V_313 ;
V_53 -> V_124 [ 1 ] = V_314 ;
V_53 -> V_102 = V_315 ;
V_53 -> V_126 = V_372 ;
V_53 -> V_86 = V_317 ;
V_53 -> V_77 = V_355 ;
V_53 -> V_129 = V_373 ;
V_53 -> V_130 = V_320 ;
V_53 -> V_101 [ 0 ] = V_321 ;
V_53 -> V_101 [ 1 ] = V_357 ;
V_53 -> V_101 [ 2 ] = V_358 ;
V_53 -> V_91 = V_359 ;
V_53 -> V_87 [ 0 ] = V_324 ;
V_53 -> V_87 [ 1 ] = V_325 ;
V_53 -> V_87 [ 2 ] = V_326 ;
V_53 -> V_87 [ 5 ] = V_329 ;
V_53 -> V_87 [ 6 ] = V_360 ;
V_53 -> V_182 = V_330 ;
V_53 -> V_83 = V_361 ;
V_53 -> V_84 = V_362 ;
V_53 -> V_276 = V_333 ;
V_53 -> V_278 = V_334 ;
V_53 -> V_110 = V_335 ;
V_53 -> V_92
= V_336 ;
V_53 -> V_112 = V_374 ;
V_53 -> V_113
= V_375 ;
V_53 -> V_114 = V_376 ;
V_53 -> V_138 = V_377 ;
V_53 -> V_156 = V_338 ;
V_53 -> V_93 = V_339 ;
V_53 -> V_95 = V_340 ;
V_53 -> V_98 [ 0 ] = V_341 ;
V_53 -> V_98 [ 1 ] = V_342 ;
V_53 -> V_98 [ 2 ] = V_343 ;
V_53 -> V_142 = V_378 ;
V_53 -> V_147 = V_363 ;
V_133 = V_379 ;
V_238 = V_380 ;
V_243 = F_40 ( V_379 ) ;
V_244 = F_40 ( V_380 ) ;
V_236 = V_381 ;
V_237 = V_382 ;
V_207 = V_383 ;
V_239 = V_384 ;
V_240 = V_385 ;
break;
case V_59 :
case V_60 :
case V_61 :
V_53 -> V_120 = 15 ;
V_53 -> V_81 = 6 ;
V_53 -> V_107 = 4 ;
V_53 -> V_74 = false ;
V_53 -> V_208 = 6 ;
V_53 -> V_158 = 2 ;
V_53 -> V_163 = 2 ;
V_53 -> V_152 = V_386 ;
V_53 -> V_161 = V_368 ;
V_53 -> V_127 = F_16 ;
V_53 -> V_166 = F_16 ;
V_53 -> V_105 = 0xff ;
V_53 -> V_185 = 0x07 ;
V_53 -> V_193 = 63 ;
switch ( V_53 -> V_54 ) {
default:
case V_59 :
V_53 -> V_172 = V_369 ;
break;
case V_60 :
V_53 -> V_172 = V_387 ;
break;
case V_61 :
V_53 -> V_172 = V_388 ;
break;
}
V_53 -> V_230 = V_389 ;
V_53 -> V_206 = V_308 ;
V_53 -> V_179 = V_309 ;
V_53 -> V_180 = V_310 ;
V_53 -> V_178 = V_311 ;
V_53 -> V_123 = V_371 ;
V_53 -> V_124 [ 0 ] = V_313 ;
V_53 -> V_124 [ 1 ] = V_314 ;
V_53 -> V_102 = V_315 ;
V_53 -> V_126 = V_372 ;
V_53 -> V_86 = V_317 ;
V_53 -> V_77 = V_355 ;
V_53 -> V_129 = V_373 ;
V_53 -> V_130 = V_320 ;
V_53 -> V_101 [ 0 ] = V_321 ;
V_53 -> V_101 [ 1 ] = V_357 ;
V_53 -> V_101 [ 2 ] = V_358 ;
V_53 -> V_91 = V_359 ;
V_53 -> V_87 [ 0 ] = V_324 ;
V_53 -> V_87 [ 1 ] = V_325 ;
V_53 -> V_87 [ 2 ] = V_326 ;
V_53 -> V_87 [ 5 ] = V_390 ;
V_53 -> V_87 [ 6 ] = V_391 ;
V_53 -> V_182 = V_330 ;
V_53 -> V_83 = V_361 ;
V_53 -> V_84 = V_362 ;
V_53 -> V_276 = V_333 ;
V_53 -> V_278 = V_334 ;
V_53 -> V_110 = V_335 ;
V_53 -> V_92
= V_336 ;
V_53 -> V_112 = V_374 ;
V_53 -> V_113
= V_375 ;
V_53 -> V_114 = V_376 ;
V_53 -> V_138 = V_377 ;
V_53 -> V_156 = V_338 ;
V_53 -> V_93 = V_339 ;
V_53 -> V_95 = V_392 ;
V_53 -> V_98 [ 0 ] = V_393 ;
V_53 -> V_98 [ 1 ] = V_394 ;
V_53 -> V_98 [ 2 ] = V_395 ;
V_53 -> V_142 = V_396 ;
if ( V_53 -> V_54 == V_59 )
V_53 -> V_147 = V_363 ;
else
V_53 -> V_147 = V_397 ;
V_133 = V_379 ;
V_243 = F_40 ( V_379 ) ;
if ( V_53 -> V_54 == V_59 ) {
V_238 = V_380 ;
V_244 = F_40 ( V_380 ) ;
} else {
V_238 = V_398 ;
V_244 = F_40 ( V_398 ) ;
}
V_236 = V_381 ;
V_237 = V_382 ;
V_207 = V_383 ;
V_239 = V_384 ;
V_240 = V_385 ;
break;
default:
return - V_157 ;
}
V_53 -> V_121 = ( 1 << V_53 -> V_120 ) - 1 ;
V_53 -> V_132 = 0 ;
V_229 = 0 ;
V_228 = 0 ;
for ( V_34 = 0 ; V_34 < V_243 ; V_34 ++ ) {
if ( V_133 [ V_34 ] == 0 )
continue;
V_155 = F_30 ( V_53 , V_53 -> V_156 [ V_34 ] ) & 0x1f ;
if ( ! V_155 || ( V_229 & ( 1 << V_155 ) ) )
V_228 |= 1 << V_34 ;
V_229 |= 1 << V_155 ;
}
F_125 ( V_53 , V_53 -> V_93 , & V_228 , & V_229 ) ;
F_125 ( V_53 , V_53 -> V_95 , & V_228 , & V_229 ) ;
V_229 = 0 ;
V_47 = V_135 ;
for ( V_34 = 0 ; V_34 < V_243 ; V_34 ++ ) {
if ( V_133 [ V_34 ] == 0 )
continue;
V_155 = F_30 ( V_53 , V_53 -> V_156 [ V_34 ] ) & 0x1f ;
if ( ! V_155 || ( V_229 & ( 1 << V_155 ) ) )
continue;
if ( V_155 >= V_53 -> V_230 ||
! strlen ( V_53 -> V_172 [ V_155 ] ) ) {
F_71 ( V_19 ,
L_14 ,
V_155 , V_34 , V_53 -> V_156 [ V_34 ] , V_133 [ V_34 ] ) ;
continue;
}
V_229 |= 1 << V_155 ;
if ( V_155 <= V_53 -> V_208 ) {
V_53 -> V_132 |= 1 << ( V_155 - 1 ) ;
V_53 -> V_136 |= 1 << ( V_155 - 1 ) ;
V_53 -> V_133 [ 0 ] [ V_155 - 1 ] = V_133 [ V_34 ] ;
V_53 -> V_133 [ 1 ] [ V_155 - 1 ] = V_236 [ V_34 ] ;
V_53 -> V_133 [ 2 ] [ V_155 - 1 ] = V_237 [ V_34 ] ;
if ( V_242 && V_242 [ V_34 ] )
V_53 -> V_133 [ 3 ] [ V_155 - 1 ] = V_242 [ V_34 ] ;
else if ( V_240 [ V_155 - 1 ] )
V_53 -> V_133 [ 3 ] [ V_155 - 1 ]
= V_240 [ V_155 - 1 ] ;
if ( V_241 && V_241 [ V_34 ] )
V_53 -> V_133 [ 4 ] [ V_155 - 1 ] = V_241 [ V_34 ] ;
V_53 -> V_207 [ V_155 - 1 ] = V_207 [ V_34 ] ;
V_53 -> V_154 [ V_155 - 1 ] = V_155 ;
continue;
}
if ( V_47 >= V_131 )
continue;
V_53 -> V_132 |= 1 << V_47 ;
V_53 -> V_133 [ 0 ] [ V_47 ] = V_133 [ V_34 ] ;
V_53 -> V_133 [ 1 ] [ V_47 ] = V_236 [ V_34 ] ;
V_53 -> V_133 [ 2 ] [ V_47 ] = V_237 [ V_34 ] ;
V_53 -> V_207 [ V_47 ] = V_207 [ V_34 ] ;
if ( V_242 && V_242 [ V_34 ] )
V_53 -> V_133 [ 3 ] [ V_47 ] = V_242 [ V_34 ] ;
else if ( V_240 [ V_155 - 1 ] )
V_53 -> V_133 [ 3 ] [ V_47 ] = V_240 [ V_155 - 1 ] ;
if ( V_241 && V_241 [ V_34 ] )
V_53 -> V_133 [ 4 ] [ V_47 ] = V_241 [ V_34 ] ;
V_53 -> V_154 [ V_47 ] = V_155 ;
V_47 ++ ;
}
for ( V_34 = 0 ; V_34 < V_244 ; V_34 ++ ) {
if ( V_238 [ V_34 ] == 0 )
continue;
V_155 = F_30 ( V_53 , V_53 -> V_93 [ V_34 ] ) & 0x1f ;
if ( ! V_155 || ( V_229 & ( 1 << V_155 ) ) )
continue;
if ( V_155 >= V_53 -> V_230 ||
! strlen ( V_53 -> V_172 [ V_155 ] ) ) {
F_71 ( V_19 ,
L_14 ,
V_155 , V_34 , V_53 -> V_93 [ V_34 ] ,
V_238 [ V_34 ] ) ;
continue;
}
V_229 |= 1 << V_155 ;
if ( V_155 <= V_53 -> V_208 ) {
if ( V_53 -> V_132 & ( 1 << ( V_155 - 1 ) ) )
continue;
V_53 -> V_132 |= 1 << ( V_155 - 1 ) ;
V_53 -> V_136 |= 1 << ( V_155 - 1 ) ;
V_53 -> V_133 [ 0 ] [ V_155 - 1 ] = V_238 [ V_34 ] ;
V_53 -> V_154 [ V_155 - 1 ] = V_155 ;
continue;
}
if ( V_47 >= V_131 )
continue;
V_53 -> V_132 |= 1 << V_47 ;
V_53 -> V_133 [ 0 ] [ V_47 ] = V_238 [ V_34 ] ;
V_53 -> V_154 [ V_47 ] = V_155 ;
V_47 ++ ;
}
#ifdef F_133
for ( V_34 = 0 ; V_34 < V_53 -> V_230 - 1 ; V_34 ++ ) {
if ( ! V_239 [ V_34 ] )
continue;
if ( V_229 & ( 1 << ( V_34 + 1 ) ) )
continue;
if ( V_34 < V_53 -> V_208 ) {
if ( V_53 -> V_132 & ( 1 << V_34 ) )
continue;
V_53 -> V_132 |= 1 << V_34 ;
V_53 -> V_136 |= 1 << V_34 ;
V_53 -> V_133 [ 0 ] [ V_34 ] = V_239 [ V_34 ] ;
if ( V_34 < V_243 ) {
V_53 -> V_133 [ 1 ] [ V_34 ] = V_236 [ V_34 ] ;
V_53 -> V_133 [ 2 ] [ V_34 ] = V_237 [ V_34 ] ;
}
V_53 -> V_154 [ V_34 ] = V_34 + 1 ;
continue;
}
if ( V_47 >= V_131 )
break;
V_53 -> V_132 |= 1 << V_47 ;
V_53 -> V_133 [ 0 ] [ V_47 ] = V_239 [ V_34 ] ;
V_53 -> V_154 [ V_47 ] = V_34 + 1 ;
V_47 ++ ;
}
#endif
F_122 ( V_53 ) ;
V_151 = F_6 ( V_234 -> V_200 ) ;
if ( V_151 )
return V_151 ;
V_245 = F_3 ( V_234 -> V_200 , 0x2a ) ;
switch ( V_53 -> V_54 ) {
case V_56 :
V_53 -> V_204 = ( V_245 & 0x40 ) ;
break;
case V_57 :
V_53 -> V_204 = ( V_245 & 0x60 ) == 0x40 ;
break;
case V_55 :
case V_58 :
case V_59 :
case V_60 :
case V_61 :
break;
}
if ( V_53 -> V_204 ) {
F_5 ( V_234 -> V_200 , V_399 ) ;
V_53 -> V_196 = F_3 ( V_234 -> V_200 , 0xe3 ) ;
V_53 -> V_197 = F_134 () ;
}
if ( V_400 ) {
T_1 V_205 ;
F_5 ( V_234 -> V_200 , V_219 ) ;
V_205 = F_3 ( V_234 -> V_200 ,
V_401 ) ;
switch ( V_53 -> V_54 ) {
case V_55 :
V_205 |= 0xe0 ;
break;
case V_56 :
V_205 |= 0x1e ;
break;
case V_57 :
case V_58 :
V_205 |= 0x3e ;
break;
case V_59 :
case V_60 :
case V_61 :
V_205 |= 0x7e ;
break;
}
F_1 ( V_234 -> V_200 , V_401 ,
V_205 ) ;
F_71 ( & V_232 -> V_19 , L_15 ,
V_53 -> V_41 ) ;
}
F_123 ( V_53 ) ;
F_8 ( V_234 -> V_200 ) ;
F_41 ( V_19 , V_53 ) ;
V_23 = F_23 ( V_19 , & V_402 ,
V_53 -> V_81 ) ;
if ( F_135 ( V_23 ) )
return F_136 ( V_23 ) ;
V_53 -> V_403 [ V_247 ++ ] = V_23 ;
V_23 = F_23 ( V_19 , & V_404 ,
F_137 ( V_53 -> V_121 ) ) ;
if ( F_135 ( V_23 ) )
return F_136 ( V_23 ) ;
V_53 -> V_403 [ V_247 ++ ] = V_23 ;
V_23 = F_23 ( V_19 , & V_405 ,
F_137 ( V_53 -> V_73 ) ) ;
if ( F_135 ( V_23 ) )
return F_136 ( V_23 ) ;
V_53 -> V_403 [ V_247 ++ ] = V_23 ;
V_23 = F_23 ( V_19 , & V_406 ,
F_137 ( V_53 -> V_132 ) ) ;
if ( F_135 ( V_23 ) )
return F_136 ( V_23 ) ;
V_53 -> V_403 [ V_247 ++ ] = V_23 ;
V_53 -> V_403 [ V_247 ++ ] = & V_407 ;
V_246 = F_138 ( V_19 , V_53 -> V_41 ,
V_53 , V_53 -> V_403 ) ;
return F_139 ( V_246 ) ;
}
static void F_140 ( int V_408 )
{
int V_3 ;
V_3 = F_3 ( V_408 , V_409 ) ;
if ( V_3 & 0x10 ) {
F_141 ( L_16 ) ;
F_1 ( V_408 , V_409 ,
V_3 & ~ 0x10 ) ;
}
}
static int T_7 F_142 ( struct V_18 * V_19 )
{
struct V_52 * V_53 = F_49 ( V_19 ) ;
F_50 ( & V_53 -> V_115 ) ;
V_53 -> V_174 = F_30 ( V_53 , V_53 -> V_179 ) ;
if ( V_53 -> V_54 == V_56 ) {
V_53 -> V_410 = F_30 ( V_53 , V_70 ) ;
V_53 -> V_411 = F_30 ( V_53 , V_72 ) ;
}
F_52 ( & V_53 -> V_115 ) ;
return 0 ;
}
static int T_7 F_143 ( struct V_18 * V_19 )
{
struct V_52 * V_53 = F_45 ( V_19 ) ;
int V_200 = V_53 -> V_200 ;
int V_34 , V_78 , V_151 = 0 ;
T_1 V_2 ;
F_50 ( & V_53 -> V_115 ) ;
V_53 -> V_62 = 0xff ;
V_151 = F_6 ( V_200 ) ;
if ( V_151 )
goto abort;
F_5 ( V_200 , V_219 ) ;
V_2 = F_3 ( V_200 , V_221 ) ;
if ( V_2 != V_53 -> V_220 )
F_1 ( V_200 , V_221 , V_53 -> V_220 ) ;
if ( V_53 -> V_54 == V_59 || V_53 -> V_54 == V_60 ||
V_53 -> V_54 == V_61 )
F_140 ( V_200 ) ;
F_8 ( V_200 ) ;
for ( V_34 = 0 ; V_34 < V_53 -> V_120 ; V_34 ++ ) {
if ( ! ( V_53 -> V_121 & ( 1 << V_34 ) ) )
continue;
F_32 ( V_53 , V_53 -> V_124 [ 0 ] [ V_34 ] ,
V_53 -> V_122 [ V_34 ] [ 1 ] ) ;
F_32 ( V_53 , V_53 -> V_124 [ 1 ] [ V_34 ] ,
V_53 -> V_122 [ V_34 ] [ 2 ] ) ;
}
for ( V_34 = 0 ; V_34 < F_40 ( V_53 -> V_75 ) ; V_34 ++ ) {
if ( ! ( V_53 -> V_76 & ( 1 << V_34 ) ) )
continue;
F_32 ( V_53 , V_53 -> V_77 [ V_34 ] ,
V_53 -> V_75 [ V_34 ] ) ;
}
for ( V_34 = 0 ; V_34 < V_131 ; V_34 ++ ) {
if ( ! ( V_53 -> V_132 & ( 1 << V_34 ) ) )
continue;
for ( V_78 = 1 ; V_78 < F_40 ( V_53 -> V_133 ) ; V_78 ++ )
if ( V_53 -> V_133 [ V_78 ] [ V_34 ] )
F_34 ( V_53 , V_53 -> V_133 [ V_78 ] [ V_34 ] ,
V_53 -> V_134 [ V_78 ] [ V_34 ] ) ;
}
F_32 ( V_53 , V_53 -> V_179 , V_53 -> V_174 ) ;
if ( V_53 -> V_54 == V_56 ) {
F_32 ( V_53 , V_70 , V_53 -> V_410 ) ;
F_32 ( V_53 , V_72 , V_53 -> V_411 ) ;
}
abort:
V_53 -> V_119 = false ;
F_52 ( & V_53 -> V_115 ) ;
return V_151 ;
}
static int T_8 F_144 ( int V_408 , struct V_233 * V_234 )
{
T_2 V_3 ;
int V_151 ;
int V_64 ;
V_151 = F_6 ( V_408 ) ;
if ( V_151 )
return V_151 ;
if ( V_412 )
V_3 = V_412 ;
else
V_3 = ( F_3 ( V_408 , V_413 ) << 8 )
| F_3 ( V_408 , V_413 + 1 ) ;
switch ( V_3 & V_414 ) {
case V_415 :
V_234 -> V_54 = V_55 ;
break;
case V_416 :
V_234 -> V_54 = V_56 ;
break;
case V_417 :
V_234 -> V_54 = V_57 ;
break;
case V_418 :
V_234 -> V_54 = V_58 ;
break;
case V_419 :
V_234 -> V_54 = V_59 ;
break;
case V_420 :
V_234 -> V_54 = V_60 ;
break;
case V_421 :
V_234 -> V_54 = V_61 ;
break;
default:
if ( V_3 != 0xffff )
F_145 ( L_17 , V_3 ) ;
F_8 ( V_408 ) ;
return - V_157 ;
}
F_5 ( V_408 , V_219 ) ;
V_3 = ( F_3 ( V_408 , V_422 ) << 8 )
| F_3 ( V_408 , V_422 + 1 ) ;
V_64 = V_3 & V_423 ;
if ( V_64 == 0 ) {
F_146 ( L_18 ) ;
F_8 ( V_408 ) ;
return - V_157 ;
}
V_3 = F_3 ( V_408 , V_221 ) ;
if ( ! ( V_3 & 0x01 ) ) {
F_147 ( L_19 ) ;
F_1 ( V_408 , V_221 , V_3 | 0x01 ) ;
}
if ( V_234 -> V_54 == V_59 || V_234 -> V_54 == V_60 ||
V_234 -> V_54 == V_61 )
F_140 ( V_408 ) ;
F_8 ( V_408 ) ;
F_141 ( L_20 ,
V_424 [ V_234 -> V_54 ] , V_408 , V_64 ) ;
V_234 -> V_200 = V_408 ;
return V_64 ;
}
static int T_8 F_148 ( void )
{
int V_34 , V_151 ;
bool V_425 = false ;
int V_426 ;
struct V_235 V_67 ;
struct V_233 V_234 ;
int V_408 [ 2 ] = { 0x2e , 0x4e } ;
V_151 = F_149 ( & V_427 ) ;
if ( V_151 )
return V_151 ;
for ( V_34 = 0 ; V_34 < F_40 ( V_232 ) ; V_34 ++ ) {
V_426 = F_144 ( V_408 [ V_34 ] , & V_234 ) ;
if ( V_426 <= 0 )
continue;
V_425 = true ;
V_232 [ V_34 ] = F_150 ( V_6 , V_426 ) ;
if ( ! V_232 [ V_34 ] ) {
V_151 = - V_39 ;
goto V_428;
}
V_151 = F_151 ( V_232 [ V_34 ] , & V_234 ,
sizeof( struct V_233 ) ) ;
if ( V_151 )
goto V_429;
memset ( & V_67 , 0 , sizeof( V_67 ) ) ;
V_67 . V_41 = V_6 ;
V_67 . V_249 = V_426 + V_430 ;
V_67 . V_431 = V_426 + V_430 + V_250 - 1 ;
V_67 . V_432 = V_248 ;
V_151 = F_152 ( & V_67 ) ;
if ( V_151 ) {
F_153 ( V_232 [ V_34 ] ) ;
V_232 [ V_34 ] = NULL ;
continue;
}
V_151 = F_154 ( V_232 [ V_34 ] , & V_67 , 1 ) ;
if ( V_151 )
goto V_429;
V_151 = F_155 ( V_232 [ V_34 ] ) ;
if ( V_151 )
goto V_429;
}
if ( ! V_425 ) {
V_151 = - V_157 ;
goto V_433;
}
return 0 ;
V_429:
F_153 ( V_232 [ V_34 ] ) ;
V_428:
while ( -- V_34 >= 0 ) {
if ( V_232 [ V_34 ] )
F_156 ( V_232 [ V_34 ] ) ;
}
V_433:
F_157 ( & V_427 ) ;
return V_151 ;
}
static void T_9 F_158 ( void )
{
int V_34 ;
for ( V_34 = 0 ; V_34 < F_40 ( V_232 ) ; V_34 ++ ) {
if ( V_232 [ V_34 ] )
F_156 ( V_232 [ V_34 ] ) ;
}
F_157 ( & V_427 ) ;
}
