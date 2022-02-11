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
static bool F_26 ( struct V_52 * V_53 , T_2 V_2 )
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
static inline void F_27 ( struct V_52 * V_53 , T_2 V_2 )
{
T_1 V_60 = V_2 >> 8 ;
if ( V_53 -> V_60 != V_60 ) {
F_28 ( V_61 , V_53 -> V_62 + V_63 ) ;
F_28 ( V_60 , V_53 -> V_62 + V_64 ) ;
V_53 -> V_60 = V_60 ;
}
}
static T_2 F_29 ( struct V_52 * V_53 , T_2 V_2 )
{
int V_65 , V_66 = F_26 ( V_53 , V_2 ) ;
F_27 ( V_53 , V_2 ) ;
F_28 ( V_2 & 0xff , V_53 -> V_62 + V_63 ) ;
V_65 = F_30 ( V_53 -> V_62 + V_64 ) ;
if ( V_66 ) {
F_28 ( ( V_2 & 0xff ) + 1 ,
V_53 -> V_62 + V_63 ) ;
V_65 = ( V_65 << 8 ) + F_30 ( V_53 -> V_62 + V_64 ) ;
}
return V_65 ;
}
static int F_31 ( struct V_52 * V_53 , T_2 V_2 , T_2 V_67 )
{
int V_66 = F_26 ( V_53 , V_2 ) ;
F_27 ( V_53 , V_2 ) ;
F_28 ( V_2 & 0xff , V_53 -> V_62 + V_63 ) ;
if ( V_66 ) {
F_28 ( V_67 >> 8 , V_53 -> V_62 + V_64 ) ;
F_28 ( ( V_2 & 0xff ) + 1 ,
V_53 -> V_62 + V_63 ) ;
}
F_28 ( V_67 & 0xff , V_53 -> V_62 + V_64 ) ;
return 0 ;
}
static T_2 F_32 ( struct V_52 * V_53 , T_2 V_2 )
{
T_2 V_65 ;
V_65 = F_29 ( V_53 , V_2 ) ;
if ( ! F_26 ( V_53 , V_2 ) )
V_65 <<= 8 ;
return V_65 ;
}
static int F_33 ( struct V_52 * V_53 , T_2 V_2 , T_2 V_67 )
{
if ( ! F_26 ( V_53 , V_2 ) )
V_67 >>= 8 ;
return F_31 ( V_53 , V_2 , V_67 ) ;
}
static void F_34 ( struct V_52 * V_53 , int V_15 )
{
T_1 V_2 ;
switch ( V_15 ) {
case 0 :
V_2 = ( F_29 ( V_53 , V_68 ) & 0x70 )
| ( V_53 -> V_69 [ 0 ] & 0x7 ) ;
F_31 ( V_53 , V_68 , V_2 ) ;
break;
case 1 :
V_2 = ( F_29 ( V_53 , V_68 ) & 0x7 )
| ( ( V_53 -> V_69 [ 1 ] << 4 ) & 0x70 ) ;
F_31 ( V_53 , V_68 , V_2 ) ;
break;
case 2 :
V_2 = ( F_29 ( V_53 , V_70 ) & 0x70 )
| ( V_53 -> V_69 [ 2 ] & 0x7 ) ;
F_31 ( V_53 , V_70 , V_2 ) ;
break;
case 3 :
V_2 = ( F_29 ( V_53 , V_70 ) & 0x7 )
| ( ( V_53 -> V_69 [ 3 ] << 4 ) & 0x70 ) ;
F_31 ( V_53 , V_70 , V_2 ) ;
break;
}
}
static void F_35 ( struct V_52 * V_53 , int V_15 )
{
if ( V_53 -> V_54 == V_56 )
F_34 ( V_53 , V_15 ) ;
}
static void F_36 ( struct V_52 * V_53 )
{
T_1 V_34 ;
V_34 = F_29 ( V_53 , V_68 ) ;
V_53 -> V_69 [ 0 ] = V_34 & 0x7 ;
V_53 -> V_69 [ 1 ] = ( V_34 & 0x70 ) >> 4 ;
V_34 = F_29 ( V_53 , V_70 ) ;
V_53 -> V_69 [ 2 ] = V_34 & 0x7 ;
if ( V_53 -> V_71 & ( 1 << 3 ) )
V_53 -> V_69 [ 3 ] = ( V_34 & 0x70 ) >> 4 ;
}
static void F_37 ( struct V_52 * V_53 )
{
if ( V_53 -> V_54 == V_56 )
F_36 ( V_53 ) ;
}
static void F_38 ( struct V_52 * V_53 )
{
int V_34 ;
F_37 ( V_53 ) ;
for ( V_34 = 0 ; V_34 < F_39 ( V_53 -> V_69 ) ; V_34 ++ ) {
if ( ! ( V_53 -> V_71 & ( 1 << V_34 ) ) )
continue;
if ( V_53 -> V_69 [ V_34 ] == 0 ) {
V_53 -> V_69 [ V_34 ] = 7 ;
F_35 ( V_53 , V_34 ) ;
}
}
}
static void F_40 ( struct V_18 * V_19 ,
struct V_52 * V_53 )
{
int V_34 ;
T_1 V_2 ;
if ( V_53 -> V_72 )
F_38 ( V_53 ) ;
for ( V_34 = 0 ; V_34 < F_39 ( V_53 -> V_73 ) ; V_34 ++ ) {
if ( V_53 -> V_74 & ( 1 << V_34 ) ) {
V_2 = F_29 ( V_53 , V_53 -> V_75 [ V_34 ] ) ;
if ( ! V_2 )
F_31 ( V_53 , V_53 -> V_75 [ V_34 ] ,
V_53 -> V_72 ? 0xff
: 0xff1f ) ;
}
}
}
static void F_41 ( struct V_18 * V_19 ,
struct V_52 * V_53 , int V_15 , T_2 V_2 )
{
T_1 V_69 = V_53 -> V_69 [ V_15 ] ;
T_2 V_73 ;
if ( ! V_53 -> V_72 )
return;
if ( V_2 == 0x00 && V_69 < 0x07 )
V_69 ++ ;
else if ( V_2 != 0x00 && V_2 < 0x30 && V_69 > 0 )
V_69 -- ;
if ( V_69 != V_53 -> V_69 [ V_15 ] ) {
F_42 ( V_19 , L_1 ,
V_15 + 1 , F_19 ( V_53 -> V_69 [ V_15 ] ) ,
F_19 ( V_69 ) ) ;
if ( V_53 -> V_74 & ( 1 << V_15 ) ) {
V_73 = V_53 -> V_73 [ V_15 ] ;
if ( V_69 > V_53 -> V_69 [ V_15 ] ) {
if ( V_73 != 255 && V_73 > 1 )
V_73 >>= 1 ;
} else {
if ( V_73 != 255 ) {
V_73 <<= 1 ;
if ( V_73 > 254 )
V_73 = 254 ;
}
}
if ( V_73 != V_53 -> V_73 [ V_15 ] ) {
V_53 -> V_73 [ V_15 ] = V_73 ;
F_31 ( V_53 , V_53 -> V_75 [ V_15 ] ,
V_73 ) ;
}
}
V_53 -> V_69 [ V_15 ] = V_69 ;
F_35 ( V_53 , V_15 ) ;
}
}
static void F_43 ( struct V_18 * V_19 )
{
struct V_52 * V_53 = F_44 ( V_19 ) ;
int V_34 , V_76 ;
int V_77 , V_2 ;
bool V_78 ;
for ( V_34 = 0 ; V_34 < V_53 -> V_79 ; V_34 ++ ) {
if ( ! ( V_53 -> V_80 & ( 1 << V_34 ) ) )
continue;
V_78 = V_53 -> V_81 [ V_34 ] &&
( F_29 ( V_53 , V_53 -> V_81 [ V_34 ] )
& V_53 -> V_82 [ V_34 ] ) ;
V_53 -> V_83 [ V_34 ] = V_78 ;
V_77 = F_29 ( V_53 , V_53 -> V_84 [ V_34 ] ) ;
for ( V_76 = 0 ; V_76 < F_39 ( V_53 -> V_85 ) ; V_76 ++ ) {
if ( V_53 -> V_85 [ V_76 ] && V_53 -> V_85 [ V_76 ] [ V_34 ] ) {
V_53 -> V_9 [ V_76 ] [ V_34 ]
= F_29 ( V_53 ,
V_53 -> V_85 [ V_76 ] [ V_34 ] ) ;
}
}
V_53 -> V_8 [ V_34 ] = F_10 ( V_53 -> V_9 [ 0 ] [ V_34 ] ,
( V_77 >> 4 ) & 7 ) ;
if ( ! V_53 -> V_86 [ 0 ] [ V_34 ] ||
V_53 -> V_8 [ V_34 ] != V_87 )
V_53 -> V_86 [ 0 ] [ V_34 ] = V_77 & 0x0f ;
if ( ! V_53 -> V_88 [ V_34 ] ||
V_53 -> V_8 [ V_34 ] == V_87 ) {
T_1 V_33 = V_77 & 0x0f ;
if ( V_53 -> V_89 ) {
V_33 |= ( F_29 ( V_53 ,
V_53 -> V_89 [ V_34 ] ) & 0x70 ) >> 1 ;
}
V_53 -> V_88 [ V_34 ] = V_33 ;
}
V_53 -> V_86 [ 1 ] [ V_34 ] =
F_29 ( V_53 ,
V_53 -> V_90 [ V_34 ] ) ;
V_2 = F_29 ( V_53 , V_53 -> V_91 [ V_34 ] ) ;
V_53 -> V_92 [ V_34 ] = V_2 & 0x1f ;
if ( V_2 & 0x80 )
V_53 -> V_9 [ 2 ] [ V_34 ] = 0 ;
if ( ! V_53 -> V_93 [ V_34 ] )
continue;
V_2 = F_29 ( V_53 , V_53 -> V_93 [ V_34 ] ) ;
V_53 -> V_94 [ V_34 ] = V_2 & 0x1f ;
if ( V_76 == 1 && ! ( V_2 & 0x80 ) )
V_53 -> V_94 [ V_34 ] = 0 ;
for ( V_76 = 0 ; V_76 < F_39 ( V_53 -> V_95 ) ; V_76 ++ ) {
V_53 -> V_95 [ V_76 ] [ V_34 ]
= F_29 ( V_53 ,
V_53 -> V_96 [ V_76 ] [ V_34 ] ) ;
}
}
}
static void F_45 ( struct V_18 * V_19 )
{
struct V_52 * V_53 = F_44 ( V_19 ) ;
int V_34 , V_76 ;
T_1 V_2 ;
T_2 V_97 ;
for ( V_34 = 0 ; V_34 < V_53 -> V_79 ; V_34 ++ ) {
if ( ! ( V_53 -> V_80 & ( 1 << V_34 ) ) )
continue;
for ( V_76 = 0 ; V_76 < F_39 ( V_53 -> V_98 ) ; V_76 ++ ) {
V_53 -> V_98 [ V_76 ] [ V_34 ] =
F_29 ( V_53 , V_53 -> V_99 [ V_76 ] [ V_34 ] ) ;
}
V_97 = F_29 ( V_53 , V_53 -> V_100 [ V_34 ] ) ;
if ( ! V_53 -> V_101 [ V_34 ] ||
V_53 -> V_8 [ V_34 ] == V_102 )
V_53 -> V_101 [ V_34 ] = V_97 & V_53 -> V_103 ;
if ( ! V_53 -> V_104 [ V_34 ] ||
V_53 -> V_8 [ V_34 ] == V_87 ) {
if ( V_53 -> V_89 ) {
V_97 |= ( F_29 ( V_53 ,
V_53 -> V_89 [ V_34 ] ) & 0x0f ) << 8 ;
}
V_53 -> V_104 [ V_34 ] = V_97 ;
}
for ( V_76 = 0 ; V_76 < V_53 -> V_105 ; V_76 ++ ) {
V_53 -> V_106 [ V_34 ] [ V_76 ] =
F_29 ( V_53 ,
F_46 ( V_53 , V_34 , V_76 ) ) ;
V_53 -> V_107 [ V_34 ] [ V_76 ] =
F_29 ( V_53 ,
F_47 ( V_53 , V_34 , V_76 ) ) ;
}
V_53 -> V_107 [ V_34 ] [ V_53 -> V_105 ] =
F_29 ( V_53 , V_53 -> V_108 [ V_34 ] ) ;
switch ( V_53 -> V_54 ) {
case V_56 :
V_2 = F_29 ( V_53 ,
V_109 [ V_34 ] ) ;
V_53 -> V_106 [ V_34 ] [ V_53 -> V_105 ] =
( V_2 & 0x02 ) ? 0xff : 0x00 ;
break;
case V_57 :
V_53 -> V_106 [ V_34 ] [ V_53 -> V_105 ] = 0xff ;
break;
case V_55 :
case V_58 :
case V_59 :
V_2 = F_29 ( V_53 ,
V_53 -> V_110 [ V_34 ] ) ;
if ( V_2 & V_53 -> V_111 )
V_2 = F_29 ( V_53 ,
V_53 -> V_112 [ V_34 ] ) ;
else
V_2 = 0xff ;
V_53 -> V_106 [ V_34 ] [ V_53 -> V_105 ] = V_2 ;
break;
}
}
}
static struct V_52 * F_48 ( struct V_18 * V_19 )
{
struct V_52 * V_53 = F_44 ( V_19 ) ;
int V_34 , V_76 ;
F_49 ( & V_53 -> V_113 ) ;
if ( F_50 ( V_114 , V_53 -> V_115 + V_116 + V_116 / 2 )
|| ! V_53 -> V_117 ) {
F_37 ( V_53 ) ;
for ( V_34 = 0 ; V_34 < V_53 -> V_118 ; V_34 ++ ) {
if ( ! ( V_53 -> V_119 & ( 1 << V_34 ) ) )
continue;
V_53 -> V_120 [ V_34 ] [ 0 ] = F_29 ( V_53 ,
V_53 -> V_121 [ V_34 ] ) ;
V_53 -> V_120 [ V_34 ] [ 1 ] = F_29 ( V_53 ,
V_53 -> V_122 [ 0 ] [ V_34 ] ) ;
V_53 -> V_120 [ V_34 ] [ 2 ] = F_29 ( V_53 ,
V_53 -> V_122 [ 1 ] [ V_34 ] ) ;
}
for ( V_34 = 0 ; V_34 < F_39 ( V_53 -> V_123 ) ; V_34 ++ ) {
T_2 V_2 ;
if ( ! ( V_53 -> V_71 & ( 1 << V_34 ) ) )
continue;
V_2 = F_29 ( V_53 , V_53 -> V_124 [ V_34 ] ) ;
V_53 -> V_123 [ V_34 ] = V_53 -> V_125 ( V_2 ,
V_53 -> V_69 [ V_34 ] ) ;
if ( V_53 -> V_74 & ( 1 << V_34 ) )
V_53 -> V_73 [ V_34 ] = F_29 ( V_53 ,
V_53 -> V_75 [ V_34 ] ) ;
V_53 -> V_126 [ V_34 ] =
( F_29 ( V_53 , V_53 -> V_127 [ V_34 ] )
>> V_53 -> V_128 [ V_34 ] ) & 0x03 ;
F_41 ( V_19 , V_53 , V_34 , V_2 ) ;
}
F_43 ( V_19 ) ;
F_45 ( V_19 ) ;
for ( V_34 = 0 ; V_34 < V_129 ; V_34 ++ ) {
if ( ! ( V_53 -> V_130 & ( 1 << V_34 ) ) )
continue;
for ( V_76 = 0 ; V_76 < F_39 ( V_53 -> V_131 ) ; V_76 ++ ) {
if ( V_53 -> V_131 [ V_76 ] [ V_34 ] )
V_53 -> V_132 [ V_76 ] [ V_34 ]
= F_32 ( V_53 ,
V_53 -> V_131 [ V_76 ] [ V_34 ] ) ;
}
if ( V_34 >= V_133 ||
! ( V_53 -> V_134 & ( 1 << V_34 ) ) )
continue;
V_53 -> V_135 [ V_34 ]
= F_29 ( V_53 , V_53 -> V_136 [ V_34 ] ) ;
}
V_53 -> V_137 = 0 ;
for ( V_34 = 0 ; V_34 < V_138 ; V_34 ++ ) {
T_1 V_139 ;
if ( ! V_53 -> V_140 [ V_34 ] )
continue;
V_139 = F_29 ( V_53 , V_53 -> V_140 [ V_34 ] ) ;
V_53 -> V_137 |= ( ( V_141 ) V_139 ) << ( V_34 << 3 ) ;
}
V_53 -> V_142 = 0 ;
for ( V_34 = 0 ; V_34 < V_143 ; V_34 ++ ) {
T_1 V_144 ;
if ( ! V_53 -> V_145 [ V_34 ] )
continue;
V_144 = F_29 ( V_53 , V_53 -> V_145 [ V_34 ] ) ;
V_53 -> V_142 |= ( ( V_141 ) V_144 ) << ( V_34 << 3 ) ;
}
V_53 -> V_115 = V_114 ;
V_53 -> V_117 = true ;
}
F_51 ( & V_53 -> V_113 ) ;
return V_53 ;
}
static T_4
F_52 ( struct V_18 * V_19 , struct V_146 * V_43 , char * V_147 )
{
struct V_52 * V_53 = F_48 ( V_19 ) ;
struct V_28 * V_148 = F_53 ( V_43 ) ;
int V_15 = V_148 -> V_15 ;
int V_48 = V_148 -> V_48 ;
return sprintf ( V_147 , L_2 , F_20 ( V_53 -> V_120 [ V_15 ] [ V_48 ] , V_15 ) ) ;
}
static T_4
F_54 ( struct V_18 * V_19 , struct V_146 * V_43 , const char * V_147 ,
T_5 V_35 )
{
struct V_52 * V_53 = F_44 ( V_19 ) ;
struct V_28 * V_148 = F_53 ( V_43 ) ;
int V_15 = V_148 -> V_15 ;
int V_48 = V_148 -> V_48 ;
unsigned long V_3 ;
int V_149 = F_55 ( V_147 , 10 , & V_3 ) ;
if ( V_149 < 0 )
return V_149 ;
F_49 ( & V_53 -> V_113 ) ;
V_53 -> V_120 [ V_15 ] [ V_48 ] = F_22 ( V_3 , V_15 ) ;
F_31 ( V_53 , V_53 -> V_122 [ V_48 - 1 ] [ V_15 ] ,
V_53 -> V_120 [ V_15 ] [ V_48 ] ) ;
F_51 ( & V_53 -> V_113 ) ;
return V_35 ;
}
static T_4
F_56 ( struct V_18 * V_19 , struct V_146 * V_43 , char * V_147 )
{
struct V_52 * V_53 = F_48 ( V_19 ) ;
struct V_26 * V_148 = F_57 ( V_43 ) ;
int V_15 = V_53 -> V_150 [ V_148 -> V_48 ] ;
return sprintf ( V_147 , L_3 ,
( unsigned int ) ( ( V_53 -> V_137 >> V_15 ) & 0x01 ) ) ;
}
static int F_58 ( struct V_52 * V_53 , int V_48 , int V_35 )
{
int V_151 = V_53 -> V_152 [ V_48 ] ;
int V_15 ;
for ( V_15 = 0 ; V_15 < V_35 ; V_15 ++ ) {
int V_153 ;
V_153 = F_29 ( V_53 ,
V_53 -> V_154 [ V_15 ] ) & 0x1f ;
if ( V_153 == V_151 )
return V_15 ;
}
return - V_155 ;
}
static T_4
F_59 ( struct V_18 * V_19 , struct V_146 * V_43 , char * V_147 )
{
struct V_26 * V_148 = F_57 ( V_43 ) ;
struct V_52 * V_53 = F_48 ( V_19 ) ;
unsigned int V_139 = 0 ;
int V_15 ;
V_15 = F_58 ( V_53 , V_148 -> V_48 , V_53 -> V_156 ) ;
if ( V_15 >= 0 ) {
int V_157 = V_53 -> V_150 [ V_15 + V_158 ] ;
V_139 = ( V_53 -> V_137 >> V_157 ) & 0x01 ;
}
return sprintf ( V_147 , L_3 , V_139 ) ;
}
static T_4
F_60 ( struct V_18 * V_19 , struct V_146 * V_43 , char * V_147 )
{
struct V_26 * V_148 = F_57 ( V_43 ) ;
struct V_52 * V_53 = F_48 ( V_19 ) ;
int V_15 = V_53 -> V_159 [ V_148 -> V_48 ] ;
return sprintf ( V_147 , L_3 ,
( unsigned int ) ( ( V_53 -> V_142 >> V_15 ) & 0x01 ) ) ;
}
static T_4
F_61 ( struct V_18 * V_19 , struct V_146 * V_43 , const char * V_147 ,
T_5 V_35 )
{
struct V_28 * V_148 = F_53 ( V_43 ) ;
struct V_52 * V_53 = F_44 ( V_19 ) ;
int V_15 = V_53 -> V_159 [ V_148 -> V_48 ] ;
int V_160 = V_15 >> 3 ;
unsigned long V_3 ;
int V_149 = F_55 ( V_147 , 10 , & V_3 ) ;
if ( V_149 < 0 )
return V_149 ;
if ( V_3 > 1 )
return - V_36 ;
F_49 ( & V_53 -> V_113 ) ;
if ( V_3 )
V_53 -> V_142 |= ( 1ULL << V_15 ) ;
else
V_53 -> V_142 &= ~ ( 1ULL << V_15 ) ;
F_31 ( V_53 , V_53 -> V_145 [ V_160 ] ,
( V_53 -> V_142 >> ( V_160 << 3 ) ) & 0xff ) ;
F_51 ( & V_53 -> V_113 ) ;
return V_35 ;
}
static T_4
F_62 ( struct V_18 * V_19 , struct V_146 * V_43 , char * V_147 )
{
struct V_26 * V_148 = F_57 ( V_43 ) ;
struct V_52 * V_53 = F_48 ( V_19 ) ;
unsigned int V_144 = 0 ;
int V_15 ;
V_15 = F_58 ( V_53 , V_148 -> V_48 , V_53 -> V_161 ) ;
if ( V_15 >= 0 ) {
int V_157 = V_53 -> V_159 [ V_15 + V_158 ] ;
V_144 = ( V_53 -> V_142 >> V_157 ) & 0x01 ;
}
return sprintf ( V_147 , L_3 , V_144 ) ;
}
static T_4
F_63 ( struct V_18 * V_19 , struct V_146 * V_43 ,
const char * V_147 , T_5 V_35 )
{
struct V_28 * V_148 = F_53 ( V_43 ) ;
struct V_52 * V_53 = F_44 ( V_19 ) ;
int V_15 , V_157 , V_160 ;
unsigned long V_3 ;
int V_149 = F_55 ( V_147 , 10 , & V_3 ) ;
if ( V_149 < 0 )
return V_149 ;
if ( V_3 > 1 )
return - V_36 ;
V_15 = F_58 ( V_53 , V_148 -> V_48 , V_53 -> V_161 ) ;
if ( V_15 < 0 )
return V_15 ;
V_157 = V_53 -> V_159 [ V_15 + V_158 ] ;
V_160 = V_157 >> 3 ;
F_49 ( & V_53 -> V_113 ) ;
if ( V_3 )
V_53 -> V_142 |= ( 1ULL << V_157 ) ;
else
V_53 -> V_142 &= ~ ( 1ULL << V_157 ) ;
F_31 ( V_53 , V_53 -> V_145 [ V_160 ] ,
( V_53 -> V_142 >> ( V_160 << 3 ) ) & 0xff ) ;
F_51 ( & V_53 -> V_113 ) ;
return V_35 ;
}
static T_6 F_64 ( struct V_162 * V_163 ,
struct V_30 * V_43 , int V_48 )
{
struct V_18 * V_19 = F_65 ( V_163 , struct V_18 , V_163 ) ;
struct V_52 * V_53 = F_44 ( V_19 ) ;
int V_120 = V_48 / 5 ;
if ( ! ( V_53 -> V_119 & ( 1 << V_120 ) ) )
return 0 ;
return V_43 -> V_10 ;
}
static T_4
F_66 ( struct V_18 * V_19 , struct V_146 * V_43 , char * V_147 )
{
struct V_52 * V_53 = F_48 ( V_19 ) ;
struct V_26 * V_148 = F_57 ( V_43 ) ;
int V_15 = V_148 -> V_48 ;
return sprintf ( V_147 , L_4 , V_53 -> V_123 [ V_15 ] ) ;
}
static T_4
F_67 ( struct V_18 * V_19 , struct V_146 * V_43 , char * V_147 )
{
struct V_52 * V_53 = F_48 ( V_19 ) ;
struct V_26 * V_148 = F_57 ( V_43 ) ;
int V_15 = V_148 -> V_48 ;
return sprintf ( V_147 , L_4 ,
V_53 -> V_164 ( V_53 -> V_73 [ V_15 ] ,
V_53 -> V_69 [ V_15 ] ) ) ;
}
static T_4
F_68 ( struct V_18 * V_19 , struct V_146 * V_43 , char * V_147 )
{
struct V_52 * V_53 = F_48 ( V_19 ) ;
struct V_26 * V_148 = F_57 ( V_43 ) ;
int V_15 = V_148 -> V_48 ;
return sprintf ( V_147 , L_3 , F_19 ( V_53 -> V_69 [ V_15 ] ) ) ;
}
static T_4
F_69 ( struct V_18 * V_19 , struct V_146 * V_43 ,
const char * V_147 , T_5 V_35 )
{
struct V_52 * V_53 = F_44 ( V_19 ) ;
struct V_26 * V_148 = F_57 ( V_43 ) ;
int V_15 = V_148 -> V_48 ;
unsigned long V_3 ;
int V_149 ;
unsigned int V_2 ;
T_1 V_165 ;
V_149 = F_55 ( V_147 , 10 , & V_3 ) ;
if ( V_149 < 0 )
return V_149 ;
F_49 ( & V_53 -> V_113 ) ;
if ( ! V_53 -> V_72 ) {
if ( ! V_3 ) {
V_3 = 0xff1f ;
} else {
if ( V_3 > 1350000U )
V_3 = 135000U ;
V_3 = 1350000U / V_3 ;
V_3 = ( V_3 & 0x1f ) | ( ( V_3 << 3 ) & 0xff00 ) ;
}
V_53 -> V_73 [ V_15 ] = V_3 ;
goto V_166;
}
if ( ! V_3 ) {
V_53 -> V_73 [ V_15 ] = 255 ;
V_165 = V_53 -> V_69 [ V_15 ] ;
F_70 ( V_19 , L_5 , V_15 + 1 ) ;
goto V_167;
}
V_2 = 1350000U / V_3 ;
if ( V_2 >= 128 * 255 ) {
V_53 -> V_73 [ V_15 ] = 254 ;
V_165 = 7 ;
F_71 ( V_19 ,
L_6 ,
V_15 + 1 , V_3 , V_53 -> V_164 ( 254 , 7 ) ) ;
} else if ( ! V_2 ) {
V_53 -> V_73 [ V_15 ] = 1 ;
V_165 = 0 ;
F_71 ( V_19 ,
L_7 ,
V_15 + 1 , V_3 , V_53 -> V_164 ( 1 , 0 ) ) ;
} else {
V_165 = 0 ;
while ( V_2 > 192 && V_165 < 7 ) {
V_2 >>= 1 ;
V_165 ++ ;
}
V_53 -> V_73 [ V_15 ] = V_2 ;
}
V_167:
if ( V_165 != V_53 -> V_69 [ V_15 ] ) {
F_42 ( V_19 , L_8 ,
V_15 + 1 , F_19 ( V_53 -> V_69 [ V_15 ] ) ,
F_19 ( V_165 ) ) ;
V_53 -> V_69 [ V_15 ] = V_165 ;
F_35 ( V_53 , V_15 ) ;
V_53 -> V_115 = V_114 ;
}
V_166:
F_31 ( V_53 , V_53 -> V_75 [ V_15 ] , V_53 -> V_73 [ V_15 ] ) ;
F_51 ( & V_53 -> V_113 ) ;
return V_35 ;
}
static T_4
F_72 ( struct V_18 * V_19 , struct V_146 * V_43 , char * V_147 )
{
struct V_52 * V_53 = F_48 ( V_19 ) ;
struct V_26 * V_148 = F_57 ( V_43 ) ;
int V_168 = V_53 -> V_126 [ V_148 -> V_48 ] ;
return sprintf ( V_147 , L_4 , V_168 ? : 4 ) ;
}
static T_4
F_73 ( struct V_18 * V_19 , struct V_146 * V_43 ,
const char * V_147 , T_5 V_35 )
{
struct V_52 * V_53 = F_44 ( V_19 ) ;
struct V_26 * V_148 = F_57 ( V_43 ) ;
int V_15 = V_148 -> V_48 ;
unsigned long V_3 ;
int V_149 ;
T_1 V_2 ;
V_149 = F_55 ( V_147 , 10 , & V_3 ) ;
if ( V_149 < 0 )
return V_149 ;
if ( V_3 > 4 )
return - V_36 ;
F_49 ( & V_53 -> V_113 ) ;
V_53 -> V_126 [ V_15 ] = V_3 & 3 ;
V_2 = F_29 ( V_53 , V_53 -> V_127 [ V_15 ] ) ;
V_2 &= ~ ( 0x03 << V_53 -> V_128 [ V_15 ] ) ;
V_2 |= ( V_3 & 3 ) << V_53 -> V_128 [ V_15 ] ;
F_31 ( V_53 , V_53 -> V_127 [ V_15 ] , V_2 ) ;
F_51 ( & V_53 -> V_113 ) ;
return V_35 ;
}
static T_6 F_74 ( struct V_162 * V_163 ,
struct V_30 * V_43 , int V_48 )
{
struct V_18 * V_19 = F_65 ( V_163 , struct V_18 , V_163 ) ;
struct V_52 * V_53 = F_44 ( V_19 ) ;
int V_14 = V_48 / 6 ;
int V_15 = V_48 % 6 ;
if ( ! ( V_53 -> V_71 & ( 1 << V_14 ) ) )
return 0 ;
if ( V_15 == 1 && V_53 -> V_150 [ V_169 + V_14 ] == - 1 )
return 0 ;
if ( V_15 == 2 && V_53 -> V_159 [ V_169 + V_14 ] == - 1 )
return 0 ;
if ( V_15 == 4 && ! ( V_53 -> V_74 & ( 1 << V_14 ) ) )
return 0 ;
if ( V_15 == 5 && V_53 -> V_54 != V_56 )
return 0 ;
return V_43 -> V_10 ;
}
static T_4
F_75 ( struct V_18 * V_19 , struct V_146 * V_43 , char * V_147 )
{
struct V_52 * V_53 = F_48 ( V_19 ) ;
struct V_26 * V_148 = F_57 ( V_43 ) ;
int V_15 = V_148 -> V_48 ;
return sprintf ( V_147 , L_9 , V_53 -> V_170 [ V_53 -> V_152 [ V_15 ] ] ) ;
}
static T_4
F_76 ( struct V_18 * V_19 , struct V_146 * V_43 , char * V_147 )
{
struct V_52 * V_53 = F_48 ( V_19 ) ;
struct V_28 * V_148 = F_53 ( V_43 ) ;
int V_15 = V_148 -> V_15 ;
int V_48 = V_148 -> V_48 ;
return sprintf ( V_147 , L_4 , F_77 ( V_53 -> V_132 [ V_48 ] [ V_15 ] ) ) ;
}
static T_4
F_78 ( struct V_18 * V_19 , struct V_146 * V_43 , const char * V_147 ,
T_5 V_35 )
{
struct V_52 * V_53 = F_44 ( V_19 ) ;
struct V_28 * V_148 = F_53 ( V_43 ) ;
int V_15 = V_148 -> V_15 ;
int V_48 = V_148 -> V_48 ;
int V_149 ;
long V_3 ;
V_149 = F_79 ( V_147 , 10 , & V_3 ) ;
if ( V_149 < 0 )
return V_149 ;
F_49 ( & V_53 -> V_113 ) ;
V_53 -> V_132 [ V_48 ] [ V_15 ] = F_80 ( V_3 ) ;
F_33 ( V_53 , V_53 -> V_131 [ V_48 ] [ V_15 ] ,
V_53 -> V_132 [ V_48 ] [ V_15 ] ) ;
F_51 ( & V_53 -> V_113 ) ;
return V_35 ;
}
static T_4
F_81 ( struct V_18 * V_19 , struct V_146 * V_43 , char * V_147 )
{
struct V_52 * V_53 = F_48 ( V_19 ) ;
struct V_26 * V_148 = F_57 ( V_43 ) ;
return sprintf ( V_147 , L_4 , V_53 -> V_135 [ V_148 -> V_48 ] * 1000 ) ;
}
static T_4
F_82 ( struct V_18 * V_19 , struct V_146 * V_43 ,
const char * V_147 , T_5 V_35 )
{
struct V_52 * V_53 = F_44 ( V_19 ) ;
struct V_26 * V_148 = F_57 ( V_43 ) ;
int V_15 = V_148 -> V_48 ;
long V_3 ;
int V_149 ;
V_149 = F_79 ( V_147 , 10 , & V_3 ) ;
if ( V_149 < 0 )
return V_149 ;
V_3 = F_14 ( F_21 ( V_3 , 1000 ) , - 128 , 127 ) ;
F_49 ( & V_53 -> V_113 ) ;
V_53 -> V_135 [ V_15 ] = V_3 ;
F_31 ( V_53 , V_53 -> V_136 [ V_15 ] , V_3 ) ;
F_51 ( & V_53 -> V_113 ) ;
return V_35 ;
}
static T_4
F_83 ( struct V_18 * V_19 , struct V_146 * V_43 , char * V_147 )
{
struct V_52 * V_53 = F_48 ( V_19 ) ;
struct V_26 * V_148 = F_57 ( V_43 ) ;
int V_15 = V_148 -> V_48 ;
return sprintf ( V_147 , L_4 , ( int ) V_53 -> V_171 [ V_15 ] ) ;
}
static T_4
F_84 ( struct V_18 * V_19 , struct V_146 * V_43 ,
const char * V_147 , T_5 V_35 )
{
struct V_52 * V_53 = F_48 ( V_19 ) ;
struct V_26 * V_148 = F_57 ( V_43 ) ;
int V_15 = V_148 -> V_48 ;
unsigned long V_3 ;
int V_149 ;
T_1 V_172 , V_173 , V_174 , V_175 ;
V_149 = F_55 ( V_147 , 10 , & V_3 ) ;
if ( V_149 < 0 )
return V_149 ;
if ( V_3 != 1 && V_3 != 3 && V_3 != 4 )
return - V_36 ;
F_49 ( & V_53 -> V_113 ) ;
V_53 -> V_171 [ V_15 ] = V_3 ;
V_174 = 0x02 << V_15 ;
V_175 = V_53 -> V_176 << V_15 ;
V_172 = F_29 ( V_53 , V_53 -> V_177 ) & ~ V_174 ;
V_173 = F_29 ( V_53 , V_53 -> V_178 ) & ~ V_175 ;
switch ( V_3 ) {
case 1 :
V_172 |= V_174 ;
V_173 |= V_175 ;
break;
case 3 :
V_172 |= V_175 ;
break;
case 4 :
break;
}
F_31 ( V_53 , V_53 -> V_177 , V_172 ) ;
F_31 ( V_53 , V_53 -> V_178 , V_173 ) ;
F_51 ( & V_53 -> V_113 ) ;
return V_35 ;
}
static T_6 F_85 ( struct V_162 * V_163 ,
struct V_30 * V_43 , int V_48 )
{
struct V_18 * V_19 = F_65 ( V_163 , struct V_18 , V_163 ) ;
struct V_52 * V_53 = F_44 ( V_19 ) ;
int V_132 = V_48 / 10 ;
int V_15 = V_48 % 10 ;
if ( ! ( V_53 -> V_130 & ( 1 << V_132 ) ) )
return 0 ;
if ( V_15 == 2 && F_58 ( V_53 , V_132 , V_53 -> V_156 ) < 0 )
return 0 ;
if ( V_15 == 3 && F_58 ( V_53 , V_132 , V_53 -> V_161 ) < 0 )
return 0 ;
if ( V_15 == 4 && ! V_53 -> V_131 [ 1 ] [ V_132 ] )
return 0 ;
if ( V_15 == 5 && ! V_53 -> V_131 [ 2 ] [ V_132 ] )
return 0 ;
if ( V_15 == 6 && ! V_53 -> V_131 [ 3 ] [ V_132 ] )
return 0 ;
if ( V_15 == 7 && ! V_53 -> V_131 [ 4 ] [ V_132 ] )
return 0 ;
if ( V_15 > 7 && ! ( V_53 -> V_134 & ( 1 << V_132 ) ) )
return 0 ;
return V_43 -> V_10 ;
}
static T_4
F_86 ( struct V_18 * V_19 , struct V_146 * V_43 , char * V_147 )
{
struct V_52 * V_53 = F_48 ( V_19 ) ;
struct V_26 * V_148 = F_57 ( V_43 ) ;
return sprintf ( V_147 , L_4 , ! V_53 -> V_83 [ V_148 -> V_48 ] ) ;
}
static T_4
F_87 ( struct V_18 * V_19 , struct V_146 * V_43 ,
const char * V_147 , T_5 V_35 )
{
struct V_52 * V_53 = F_44 ( V_19 ) ;
struct V_26 * V_148 = F_57 ( V_43 ) ;
int V_15 = V_148 -> V_48 ;
unsigned long V_3 ;
int V_149 ;
T_1 V_2 ;
V_149 = F_55 ( V_147 , 10 , & V_3 ) ;
if ( V_149 < 0 )
return V_149 ;
if ( V_3 > 1 )
return - V_36 ;
if ( V_53 -> V_81 [ V_15 ] == 0 ) {
if ( V_3 )
return - V_36 ;
return V_35 ;
}
F_49 ( & V_53 -> V_113 ) ;
V_53 -> V_83 [ V_15 ] = V_3 ;
V_2 = F_29 ( V_53 , V_53 -> V_81 [ V_15 ] ) ;
V_2 &= ~ V_53 -> V_82 [ V_15 ] ;
if ( V_3 )
V_2 |= V_53 -> V_82 [ V_15 ] ;
F_31 ( V_53 , V_53 -> V_81 [ V_15 ] , V_2 ) ;
F_51 ( & V_53 -> V_113 ) ;
return V_35 ;
}
static T_4
F_88 ( struct V_18 * V_19 , struct V_146 * V_43 , char * V_147 )
{
struct V_52 * V_53 = F_48 ( V_19 ) ;
struct V_28 * V_148 = F_53 ( V_43 ) ;
int V_15 = V_148 -> V_15 ;
int V_48 = V_148 -> V_48 ;
int V_9 ;
if ( V_48 == 0 && V_53 -> V_8 [ V_15 ] > V_179 )
V_9 = F_29 ( V_53 , V_53 -> V_180 [ V_15 ] ) ;
else
V_9 = V_53 -> V_9 [ V_48 ] [ V_15 ] ;
return sprintf ( V_147 , L_4 , V_9 ) ;
}
static T_4
F_89 ( struct V_18 * V_19 , struct V_146 * V_43 , const char * V_147 ,
T_5 V_35 )
{
struct V_52 * V_53 = F_44 ( V_19 ) ;
struct V_28 * V_148 = F_53 ( V_43 ) ;
int V_15 = V_148 -> V_15 ;
int V_48 = V_148 -> V_48 ;
unsigned long V_3 ;
int V_181 [ 7 ] = { 0 , 1 , 1 , V_53 -> V_9 [ 2 ] [ V_15 ] , 0 , 0 , 0 } ;
int V_182 [ 7 ]
= { 255 , 255 , V_53 -> V_9 [ 3 ] [ V_15 ] ? : 255 , 255 , 255 , 255 , 255 } ;
int V_149 ;
T_1 V_2 ;
V_149 = F_55 ( V_147 , 10 , & V_3 ) ;
if ( V_149 < 0 )
return V_149 ;
V_3 = F_14 ( V_3 , V_181 [ V_48 ] , V_182 [ V_48 ] ) ;
F_49 ( & V_53 -> V_113 ) ;
V_53 -> V_9 [ V_48 ] [ V_15 ] = V_3 ;
F_31 ( V_53 , V_53 -> V_85 [ V_48 ] [ V_15 ] , V_3 ) ;
if ( V_48 == 2 ) {
V_2 = F_29 ( V_53 , V_53 -> V_91 [ V_15 ] ) ;
V_2 &= 0x7f ;
if ( V_3 )
V_2 |= 0x80 ;
F_31 ( V_53 , V_53 -> V_91 [ V_15 ] , V_2 ) ;
}
F_51 ( & V_53 -> V_113 ) ;
return V_35 ;
}
static int F_90 ( struct V_52 * V_53 , int V_15 )
{
int V_34 ;
for ( V_34 = 0 ; V_34 < V_53 -> V_105 - 1 ; V_34 ++ ) {
if ( V_53 -> V_107 [ V_15 ] [ V_34 ] > V_53 -> V_107 [ V_15 ] [ V_34 + 1 ] )
return - V_36 ;
}
for ( V_34 = 0 ; V_34 < V_53 -> V_105 - 1 ; V_34 ++ ) {
if ( V_53 -> V_106 [ V_15 ] [ V_34 ] > V_53 -> V_106 [ V_15 ] [ V_34 + 1 ] )
return - V_36 ;
}
if ( V_53 -> V_106 [ V_15 ] [ V_53 -> V_105 ] ) {
if ( V_53 -> V_107 [ V_15 ] [ V_53 -> V_105 - 1 ] >
V_53 -> V_107 [ V_15 ] [ V_53 -> V_105 ] ||
V_53 -> V_106 [ V_15 ] [ V_53 -> V_105 - 1 ] >
V_53 -> V_106 [ V_15 ] [ V_53 -> V_105 ] )
return - V_36 ;
}
return 0 ;
}
static void F_91 ( struct V_52 * V_53 , int V_15 )
{
T_1 V_2 ;
switch ( V_53 -> V_8 [ V_15 ] ) {
case V_11 :
case V_179 :
break;
case V_87 :
V_2 = F_29 ( V_53 , V_53 -> V_84 [ V_15 ] ) ;
V_2 = ( V_2 & ~ V_53 -> V_183 ) |
( V_53 -> V_88 [ V_15 ] & V_53 -> V_183 ) ;
F_31 ( V_53 , V_53 -> V_84 [ V_15 ] , V_2 ) ;
F_31 ( V_53 , V_53 -> V_100 [ V_15 ] ,
V_53 -> V_104 [ V_15 ] & 0xff ) ;
if ( V_53 -> V_89 ) {
V_2 = ( V_53 -> V_104 [ V_15 ] >> 8 ) & 0x0f ;
V_2 |= ( V_53 -> V_88 [ V_15 ] & 0x38 ) << 1 ;
F_31 ( V_53 ,
V_53 -> V_89 [ V_15 ] ,
V_2 ) ;
}
break;
case V_102 :
F_31 ( V_53 , V_53 -> V_100 [ V_15 ] ,
V_53 -> V_101 [ V_15 ] ) ;
default:
V_2 = F_29 ( V_53 , V_53 -> V_84 [ V_15 ] ) ;
V_2 = ( V_2 & ~ V_53 -> V_183 ) |
V_53 -> V_86 [ 0 ] [ V_15 ] ;
F_31 ( V_53 , V_53 -> V_84 [ V_15 ] , V_2 ) ;
break;
}
}
static T_4
F_92 ( struct V_18 * V_19 , struct V_146 * V_43 , char * V_147 )
{
struct V_52 * V_53 = F_48 ( V_19 ) ;
struct V_26 * V_148 = F_57 ( V_43 ) ;
return sprintf ( V_147 , L_4 , V_53 -> V_8 [ V_148 -> V_48 ] ) ;
}
static T_4
F_93 ( struct V_18 * V_19 , struct V_146 * V_43 ,
const char * V_147 , T_5 V_35 )
{
struct V_52 * V_53 = F_44 ( V_19 ) ;
struct V_26 * V_148 = F_57 ( V_43 ) ;
int V_15 = V_148 -> V_48 ;
unsigned long V_3 ;
int V_149 ;
T_2 V_2 ;
V_149 = F_55 ( V_147 , 10 , & V_3 ) ;
if ( V_149 < 0 )
return V_149 ;
if ( V_3 > V_184 )
return - V_36 ;
if ( V_3 == V_185 && V_53 -> V_54 != V_56 )
return - V_36 ;
if ( V_3 == V_184 && F_90 ( V_53 , V_15 ) ) {
F_94 ( V_19 , L_10 ) ;
F_94 ( V_19 , L_11 ) ;
return - V_36 ;
}
F_49 ( & V_53 -> V_113 ) ;
V_53 -> V_8 [ V_15 ] = V_3 ;
if ( V_3 == V_11 ) {
V_53 -> V_9 [ 0 ] [ V_15 ] = 255 ;
F_31 ( V_53 , V_53 -> V_85 [ 0 ] [ V_15 ] , 255 ) ;
}
F_91 ( V_53 , V_15 ) ;
V_2 = F_29 ( V_53 , V_53 -> V_84 [ V_15 ] ) ;
V_2 &= 0x0f ;
V_2 |= F_11 ( V_3 ) << 4 ;
F_31 ( V_53 , V_53 -> V_84 [ V_15 ] , V_2 ) ;
F_51 ( & V_53 -> V_113 ) ;
return V_35 ;
}
static T_4
F_95 ( struct V_52 * V_53 , char * V_147 , int V_153 )
{
int V_34 , V_186 = 0 ;
for ( V_34 = 0 ; V_34 < V_129 ; V_34 ++ ) {
if ( ! ( V_53 -> V_130 & ( 1 << V_34 ) ) )
continue;
if ( V_153 == V_53 -> V_152 [ V_34 ] ) {
V_186 = V_34 + 1 ;
break;
}
}
return sprintf ( V_147 , L_4 , V_186 ) ;
}
static T_4
F_96 ( struct V_18 * V_19 , struct V_146 * V_43 , char * V_147 )
{
struct V_52 * V_53 = F_48 ( V_19 ) ;
struct V_26 * V_148 = F_57 ( V_43 ) ;
int V_48 = V_148 -> V_48 ;
return F_95 ( V_53 , V_147 , V_53 -> V_92 [ V_48 ] ) ;
}
static T_4
F_97 ( struct V_18 * V_19 , struct V_146 * V_43 ,
const char * V_147 , T_5 V_35 )
{
struct V_52 * V_53 = F_48 ( V_19 ) ;
struct V_26 * V_148 = F_57 ( V_43 ) ;
int V_15 = V_148 -> V_48 ;
unsigned long V_3 ;
int V_149 , V_2 , V_153 ;
V_149 = F_55 ( V_147 , 10 , & V_3 ) ;
if ( V_149 < 0 )
return V_149 ;
if ( V_3 == 0 || V_3 > V_129 )
return - V_36 ;
if ( ! ( V_53 -> V_130 & ( 1 << ( V_3 - 1 ) ) ) || ! V_53 -> V_152 [ V_3 - 1 ] )
return - V_36 ;
F_49 ( & V_53 -> V_113 ) ;
V_153 = V_53 -> V_152 [ V_3 - 1 ] ;
V_53 -> V_92 [ V_15 ] = V_153 ;
V_2 = F_29 ( V_53 , V_53 -> V_91 [ V_15 ] ) ;
V_2 &= 0xe0 ;
V_2 |= V_153 ;
F_31 ( V_53 , V_53 -> V_91 [ V_15 ] , V_2 ) ;
F_51 ( & V_53 -> V_113 ) ;
return V_35 ;
}
static T_4
F_98 ( struct V_18 * V_19 , struct V_146 * V_43 ,
char * V_147 )
{
struct V_52 * V_53 = F_48 ( V_19 ) ;
struct V_26 * V_148 = F_57 ( V_43 ) ;
int V_48 = V_148 -> V_48 ;
return F_95 ( V_53 , V_147 ,
V_53 -> V_94 [ V_48 ] ) ;
}
static T_4
F_99 ( struct V_18 * V_19 , struct V_146 * V_43 ,
const char * V_147 , T_5 V_35 )
{
struct V_52 * V_53 = F_48 ( V_19 ) ;
struct V_26 * V_148 = F_57 ( V_43 ) ;
int V_15 = V_148 -> V_48 ;
unsigned long V_3 ;
int V_149 , V_2 , V_153 ;
V_149 = F_55 ( V_147 , 10 , & V_3 ) ;
if ( V_149 < 0 )
return V_149 ;
if ( V_3 > V_129 )
return - V_36 ;
if ( V_3 && ( ! ( V_53 -> V_130 & ( 1 << ( V_3 - 1 ) ) ) ||
! V_53 -> V_152 [ V_3 - 1 ] ) )
return - V_36 ;
F_49 ( & V_53 -> V_113 ) ;
if ( V_3 ) {
V_153 = V_53 -> V_152 [ V_3 - 1 ] ;
V_53 -> V_94 [ V_15 ] = V_153 ;
V_2 = F_29 ( V_53 , V_53 -> V_93 [ V_15 ] ) ;
V_2 &= 0xe0 ;
V_2 |= ( V_153 | 0x80 ) ;
F_31 ( V_53 , V_53 -> V_93 [ V_15 ] , V_2 ) ;
} else {
V_53 -> V_94 [ V_15 ] = 0 ;
V_2 = F_29 ( V_53 , V_53 -> V_93 [ V_15 ] ) ;
V_2 &= 0x7f ;
F_31 ( V_53 , V_53 -> V_93 [ V_15 ] , V_2 ) ;
}
F_51 ( & V_53 -> V_113 ) ;
return V_35 ;
}
static T_4
F_100 ( struct V_18 * V_19 , struct V_146 * V_43 , char * V_147 )
{
struct V_52 * V_53 = F_48 ( V_19 ) ;
struct V_26 * V_148 = F_57 ( V_43 ) ;
return sprintf ( V_147 , L_4 , V_53 -> V_101 [ V_148 -> V_48 ] * 1000 ) ;
}
static T_4
F_101 ( struct V_18 * V_19 , struct V_146 * V_43 ,
const char * V_147 , T_5 V_35 )
{
struct V_52 * V_53 = F_44 ( V_19 ) ;
struct V_26 * V_148 = F_57 ( V_43 ) ;
int V_15 = V_148 -> V_48 ;
unsigned long V_3 ;
int V_149 ;
V_149 = F_55 ( V_147 , 10 , & V_3 ) ;
if ( V_149 < 0 )
return V_149 ;
V_3 = F_14 ( F_21 ( V_3 , 1000 ) , 0 ,
V_53 -> V_103 ) ;
F_49 ( & V_53 -> V_113 ) ;
V_53 -> V_101 [ V_15 ] = V_3 ;
F_91 ( V_53 , V_15 ) ;
F_51 ( & V_53 -> V_113 ) ;
return V_35 ;
}
static T_4
F_102 ( struct V_18 * V_19 , struct V_146 * V_43 , char * V_147 )
{
struct V_52 * V_53 = F_48 ( V_19 ) ;
struct V_26 * V_148 = F_57 ( V_43 ) ;
int V_15 = V_148 -> V_48 ;
return sprintf ( V_147 , L_4 ,
F_17 ( V_53 -> V_104 [ V_15 ] ,
V_53 -> V_69 [ V_15 ] ) ) ;
}
static T_4
F_103 ( struct V_18 * V_19 , struct V_146 * V_43 ,
const char * V_147 , T_5 V_35 )
{
struct V_52 * V_53 = F_44 ( V_19 ) ;
struct V_26 * V_148 = F_57 ( V_43 ) ;
int V_15 = V_148 -> V_48 ;
unsigned long V_3 ;
int V_149 ;
T_2 V_187 ;
V_149 = F_55 ( V_147 , 10 , & V_3 ) ;
if ( V_149 < 0 )
return V_149 ;
V_3 = F_14 ( V_3 , 0 , 1350000U ) ;
V_187 = F_18 ( V_3 , V_53 -> V_69 [ V_15 ] ) ;
F_49 ( & V_53 -> V_113 ) ;
V_53 -> V_104 [ V_15 ] = V_187 ;
F_91 ( V_53 , V_15 ) ;
F_51 ( & V_53 -> V_113 ) ;
return V_35 ;
}
static T_4
F_104 ( struct V_18 * V_19 , struct V_146 * V_43 ,
char * V_147 )
{
struct V_52 * V_53 = F_48 ( V_19 ) ;
struct V_28 * V_148 = F_53 ( V_43 ) ;
int V_15 = V_148 -> V_15 ;
int V_48 = V_148 -> V_48 ;
return sprintf ( V_147 , L_4 , V_53 -> V_86 [ V_48 ] [ V_15 ] * 1000 ) ;
}
static T_4
F_105 ( struct V_18 * V_19 , struct V_146 * V_43 ,
const char * V_147 , T_5 V_35 )
{
struct V_52 * V_53 = F_44 ( V_19 ) ;
struct V_28 * V_148 = F_53 ( V_43 ) ;
int V_15 = V_148 -> V_15 ;
int V_48 = V_148 -> V_48 ;
unsigned long V_3 ;
int V_149 ;
V_149 = F_55 ( V_147 , 10 , & V_3 ) ;
if ( V_149 < 0 )
return V_149 ;
V_3 = F_14 ( F_21 ( V_3 , 1000 ) , 0 , V_53 -> V_183 ) ;
F_49 ( & V_53 -> V_113 ) ;
V_53 -> V_86 [ V_48 ] [ V_15 ] = V_3 ;
if ( V_48 )
F_91 ( V_53 , V_15 ) ;
else
F_31 ( V_53 ,
V_53 -> V_90 [ V_15 ] ,
V_3 ) ;
F_51 ( & V_53 -> V_113 ) ;
return V_35 ;
}
static T_4
F_106 ( struct V_18 * V_19 , struct V_146 * V_43 ,
char * V_147 )
{
struct V_52 * V_53 = F_48 ( V_19 ) ;
struct V_26 * V_148 = F_57 ( V_43 ) ;
int V_15 = V_148 -> V_48 ;
int V_188 = V_53 -> V_104 [ V_15 ] - V_53 -> V_88 [ V_15 ] ;
int V_189 = V_53 -> V_104 [ V_15 ] + V_53 -> V_88 [ V_15 ] ;
int V_190 ;
if ( V_188 <= 0 )
V_188 = 1 ;
if ( V_189 > 0xffff )
V_189 = 0xffff ;
if ( V_189 < V_188 )
V_189 = V_188 ;
V_190 = ( F_17 ( V_188 , V_53 -> V_69 [ V_15 ] )
- F_17 ( V_189 , V_53 -> V_69 [ V_15 ] ) ) / 2 ;
return sprintf ( V_147 , L_4 , V_190 ) ;
}
static T_4
F_107 ( struct V_18 * V_19 , struct V_146 * V_43 ,
const char * V_147 , T_5 V_35 )
{
struct V_52 * V_53 = F_44 ( V_19 ) ;
struct V_26 * V_148 = F_57 ( V_43 ) ;
int V_15 = V_148 -> V_48 ;
unsigned long V_3 ;
int V_149 ;
int V_188 , V_189 ;
V_149 = F_55 ( V_147 , 10 , & V_3 ) ;
if ( V_149 < 0 )
return V_149 ;
V_189 = F_17 ( V_53 -> V_104 [ V_15 ] ,
V_53 -> V_69 [ V_15 ] ) + V_3 ;
V_188 = F_17 ( V_53 -> V_104 [ V_15 ] ,
V_53 -> V_69 [ V_15 ] ) - V_3 ;
if ( V_188 <= 0 )
V_188 = 1 ;
if ( V_189 < V_188 )
V_189 = V_188 ;
V_3 = ( F_18 ( V_188 , V_53 -> V_69 [ V_15 ] ) -
F_18 ( V_189 , V_53 -> V_69 [ V_15 ] ) ) / 2 ;
V_3 = F_14 ( V_3 , 0 , V_53 -> V_191 ) ;
F_49 ( & V_53 -> V_113 ) ;
V_53 -> V_88 [ V_15 ] = V_3 ;
F_91 ( V_53 , V_15 ) ;
F_51 ( & V_53 -> V_113 ) ;
return V_35 ;
}
static T_4
F_108 ( struct V_18 * V_19 , struct V_146 * V_43 , char * V_147 )
{
struct V_52 * V_53 = F_48 ( V_19 ) ;
struct V_28 * V_148 = F_53 ( V_43 ) ;
int V_15 = V_148 -> V_15 ;
int V_48 = V_148 -> V_48 ;
return sprintf ( V_147 , L_4 , V_53 -> V_95 [ V_48 ] [ V_15 ] * 1000 ) ;
}
static T_4
F_109 ( struct V_18 * V_19 , struct V_146 * V_43 ,
const char * V_147 , T_5 V_35 )
{
struct V_52 * V_53 = F_44 ( V_19 ) ;
struct V_28 * V_148 = F_53 ( V_43 ) ;
int V_15 = V_148 -> V_15 ;
int V_48 = V_148 -> V_48 ;
unsigned long V_3 ;
int V_149 ;
V_149 = F_55 ( V_147 , 10 , & V_3 ) ;
if ( V_149 < 0 )
return V_149 ;
V_3 = F_14 ( F_21 ( V_3 , 1000 ) , 0 , 255 ) ;
F_49 ( & V_53 -> V_113 ) ;
V_53 -> V_95 [ V_48 ] [ V_15 ] = V_3 ;
F_31 ( V_53 , V_53 -> V_96 [ V_48 ] [ V_15 ] , V_3 ) ;
F_51 ( & V_53 -> V_113 ) ;
return V_35 ;
}
static T_4
F_110 ( struct V_18 * V_19 , struct V_146 * V_43 , char * V_147 )
{
struct V_52 * V_53 = F_48 ( V_19 ) ;
struct V_28 * V_148 = F_53 ( V_43 ) ;
int V_15 = V_148 -> V_15 ;
int V_48 = V_148 -> V_48 ;
return sprintf ( V_147 , L_4 ,
F_12 ( V_53 -> V_98 [ V_48 ] [ V_15 ] ,
V_53 -> V_83 [ V_15 ] ) ) ;
}
static T_4
F_111 ( struct V_18 * V_19 , struct V_146 * V_43 ,
const char * V_147 , T_5 V_35 )
{
struct V_52 * V_53 = F_44 ( V_19 ) ;
struct V_28 * V_148 = F_53 ( V_43 ) ;
int V_15 = V_148 -> V_15 ;
int V_48 = V_148 -> V_48 ;
unsigned long V_3 ;
int V_149 ;
V_149 = F_55 ( V_147 , 10 , & V_3 ) ;
if ( V_149 < 0 )
return V_149 ;
V_3 = F_13 ( V_3 , V_53 -> V_83 [ V_15 ] ) ;
F_49 ( & V_53 -> V_113 ) ;
V_53 -> V_98 [ V_48 ] [ V_15 ] = V_3 ;
F_31 ( V_53 , V_53 -> V_99 [ V_48 ] [ V_15 ] , V_3 ) ;
F_51 ( & V_53 -> V_113 ) ;
return V_35 ;
}
static T_4
F_112 ( struct V_18 * V_19 , struct V_146 * V_43 , char * V_147 )
{
struct V_52 * V_53 = F_48 ( V_19 ) ;
struct V_28 * V_148 = F_53 ( V_43 ) ;
return sprintf ( V_147 , L_4 , V_53 -> V_106 [ V_148 -> V_15 ] [ V_148 -> V_48 ] ) ;
}
static T_4
F_113 ( struct V_18 * V_19 , struct V_146 * V_43 ,
const char * V_147 , T_5 V_35 )
{
struct V_52 * V_53 = F_44 ( V_19 ) ;
struct V_28 * V_148 = F_53 ( V_43 ) ;
int V_15 = V_148 -> V_15 ;
int V_192 = V_148 -> V_48 ;
unsigned long V_3 ;
int V_149 ;
T_1 V_2 ;
V_149 = F_55 ( V_147 , 10 , & V_3 ) ;
if ( V_149 < 0 )
return V_149 ;
if ( V_3 > 255 )
return - V_36 ;
if ( V_192 == V_53 -> V_105 ) {
if ( V_53 -> V_54 != V_56 && ! V_3 )
return - V_36 ;
if ( V_53 -> V_54 != V_58 && V_3 )
V_3 = 0xff ;
}
F_49 ( & V_53 -> V_113 ) ;
V_53 -> V_106 [ V_15 ] [ V_192 ] = V_3 ;
if ( V_192 < V_53 -> V_105 ) {
F_31 ( V_53 ,
F_46 ( V_53 , V_15 , V_192 ) ,
V_53 -> V_106 [ V_15 ] [ V_192 ] ) ;
} else {
switch ( V_53 -> V_54 ) {
case V_56 :
V_2 = F_29 ( V_53 ,
V_109 [ V_15 ] ) ;
if ( V_3 )
V_2 |= 0x02 ;
else
V_2 &= ~ 0x02 ;
F_31 ( V_53 , V_109 [ V_15 ] ,
V_2 ) ;
break;
case V_57 :
break;
case V_55 :
case V_58 :
case V_59 :
F_31 ( V_53 , V_53 -> V_112 [ V_15 ] ,
V_3 ) ;
V_2 = F_29 ( V_53 ,
V_53 -> V_110 [ V_15 ] ) ;
if ( V_3 == 255 )
V_2 &= ~ V_53 -> V_111 ;
else
V_2 |= V_53 -> V_111 ;
F_31 ( V_53 ,
V_53 -> V_110 [ V_15 ] ,
V_2 ) ;
break;
}
}
F_51 ( & V_53 -> V_113 ) ;
return V_35 ;
}
static T_4
F_114 ( struct V_18 * V_19 , struct V_146 * V_43 , char * V_147 )
{
struct V_52 * V_53 = F_48 ( V_19 ) ;
struct V_28 * V_148 = F_53 ( V_43 ) ;
int V_15 = V_148 -> V_15 ;
int V_192 = V_148 -> V_48 ;
return sprintf ( V_147 , L_4 , V_53 -> V_107 [ V_15 ] [ V_192 ] * 1000 ) ;
}
static T_4
F_115 ( struct V_18 * V_19 , struct V_146 * V_43 ,
const char * V_147 , T_5 V_35 )
{
struct V_52 * V_53 = F_44 ( V_19 ) ;
struct V_28 * V_148 = F_53 ( V_43 ) ;
int V_15 = V_148 -> V_15 ;
int V_192 = V_148 -> V_48 ;
unsigned long V_3 ;
int V_149 ;
V_149 = F_55 ( V_147 , 10 , & V_3 ) ;
if ( V_149 )
return V_149 ;
if ( V_3 > 255000 )
return - V_36 ;
F_49 ( & V_53 -> V_113 ) ;
V_53 -> V_107 [ V_15 ] [ V_192 ] = F_21 ( V_3 , 1000 ) ;
if ( V_192 < V_53 -> V_105 ) {
F_31 ( V_53 ,
F_47 ( V_53 , V_15 , V_192 ) ,
V_53 -> V_107 [ V_15 ] [ V_192 ] ) ;
} else {
F_31 ( V_53 , V_53 -> V_108 [ V_15 ] ,
V_53 -> V_107 [ V_15 ] [ V_192 ] ) ;
}
F_51 ( & V_53 -> V_113 ) ;
return V_35 ;
}
static T_6 F_116 ( struct V_162 * V_163 ,
struct V_30 * V_43 , int V_48 )
{
struct V_18 * V_19 = F_65 ( V_163 , struct V_18 , V_163 ) ;
struct V_52 * V_53 = F_44 ( V_19 ) ;
int V_9 = V_48 / 36 ;
int V_15 = V_48 % 36 ;
if ( ! ( V_53 -> V_80 & ( 1 << V_9 ) ) )
return 0 ;
if ( ( V_15 >= 14 && V_15 <= 18 ) || V_15 == 21 )
if ( ! V_53 -> V_93 [ V_9 ] )
return 0 ;
if ( V_15 == 19 && V_53 -> V_85 [ 3 ] == NULL )
return 0 ;
if ( V_15 == 20 && V_53 -> V_85 [ 4 ] == NULL )
return 0 ;
if ( V_15 == 21 && V_53 -> V_85 [ 6 ] == NULL )
return 0 ;
if ( V_15 >= 22 && V_15 <= 35 ) {
int V_193 = ( V_15 - 22 ) / 2 ;
if ( V_193 > V_53 -> V_105 )
return 0 ;
}
return V_43 -> V_10 ;
}
static T_4
F_117 ( struct V_18 * V_19 , struct V_146 * V_43 , char * V_147 )
{
struct V_52 * V_53 = F_44 ( V_19 ) ;
return sprintf ( V_147 , L_4 , F_118 ( V_53 -> V_194 , V_53 -> V_195 ) ) ;
}
static T_4
F_119 ( struct V_18 * V_19 , struct V_146 * V_43 ,
const char * V_147 , T_5 V_35 )
{
struct V_52 * V_53 = F_44 ( V_19 ) ;
int V_15 = F_57 ( V_43 ) -> V_48 - V_196 ;
unsigned long V_3 ;
T_1 V_2 ;
int V_197 ;
if ( F_55 ( V_147 , 10 , & V_3 ) || V_3 != 0 )
return - V_36 ;
F_49 ( & V_53 -> V_113 ) ;
V_197 = F_6 ( V_53 -> V_198 ) ;
if ( V_197 ) {
V_35 = V_197 ;
goto error;
}
F_5 ( V_53 -> V_198 , V_199 ) ;
V_2 = F_3 ( V_53 -> V_198 , V_200 [ V_15 ] ) ;
V_2 |= V_201 [ V_15 ] ;
F_1 ( V_53 -> V_198 , V_200 [ V_15 ] , V_2 ) ;
V_2 &= ~ V_201 [ V_15 ] ;
F_1 ( V_53 -> V_198 , V_200 [ V_15 ] , V_2 ) ;
F_8 ( V_53 -> V_198 ) ;
V_53 -> V_117 = false ;
error:
F_51 ( & V_53 -> V_113 ) ;
return V_35 ;
}
static T_6 F_120 ( struct V_162 * V_163 ,
struct V_30 * V_43 , int V_48 )
{
struct V_18 * V_19 = F_65 ( V_163 , struct V_18 , V_163 ) ;
struct V_52 * V_53 = F_44 ( V_19 ) ;
if ( V_48 == 0 && ! V_53 -> V_202 )
return 0 ;
if ( V_48 == 1 || V_48 == 2 ) {
if ( V_53 -> V_150 [ V_196 + V_48 - 1 ] < 0 )
return 0 ;
}
if ( V_48 == 3 || V_48 == 4 ) {
if ( V_53 -> V_159 [ V_196 + V_48 - 3 ] < 0 )
return 0 ;
}
return V_43 -> V_10 ;
}
static inline void F_121 ( struct V_52 * V_53 )
{
int V_34 ;
T_1 V_203 , V_173 ;
if ( V_53 -> V_204 ) {
V_203 = F_29 ( V_53 , V_53 -> V_204 ) ;
if ( ! ( V_203 & 0x01 ) )
F_31 ( V_53 , V_53 -> V_204 , V_203 | 0x01 ) ;
}
for ( V_34 = 0 ; V_34 < V_129 ; V_34 ++ ) {
if ( ! ( V_53 -> V_130 & ( 1 << V_34 ) ) )
continue;
if ( ! V_53 -> V_205 [ V_34 ] )
continue;
V_203 = F_29 ( V_53 , V_53 -> V_205 [ V_34 ] ) ;
if ( V_203 & 0x01 )
F_31 ( V_53 , V_53 -> V_205 [ V_34 ] ,
V_203 & 0xfe ) ;
}
V_203 = F_29 ( V_53 , V_53 -> V_177 ) ;
if ( ! ( V_203 & 0x01 ) )
F_31 ( V_53 , V_53 -> V_177 , V_203 | 0x01 ) ;
V_173 = F_29 ( V_53 , V_53 -> V_178 ) ;
for ( V_34 = 0 ; V_34 < V_53 -> V_206 ; V_34 ++ ) {
if ( ! ( V_53 -> V_134 & ( 1 << V_34 ) ) )
continue;
if ( ( V_203 & ( V_53 -> V_176 << V_34 ) ) )
V_53 -> V_171 [ V_34 ]
= 3 - ( ( V_173 >> V_34 ) & V_53 -> V_176 ) ;
else
V_53 -> V_171 [ V_34 ] = 4 ;
}
}
static void
F_122 ( struct V_52 * V_53 )
{
bool V_207 , V_208 , V_209 , V_210 , V_211 ;
bool V_212 , V_213 , V_214 , V_215 ;
int V_198 = V_53 -> V_198 ;
int V_216 ;
if ( V_53 -> V_54 == V_56 ) {
V_216 = F_3 ( V_198 , 0x2c ) ;
V_207 = V_216 & ( 1 << 6 ) ;
V_212 = V_216 & ( 1 << 7 ) ;
V_208 = ! ( F_3 ( V_198 , 0x2A ) & 0x80 ) ;
V_209 = false ;
V_210 = false ;
V_211 = false ;
V_213 = false ;
V_214 = false ;
V_215 = false ;
} else if ( V_53 -> V_54 == V_57 ) {
bool V_217 = F_3 ( V_198 , 0x27 ) & 0x80 ;
F_5 ( V_198 , V_218 ) ;
V_216 = F_3 ( V_198 , V_219 ) ;
if ( V_216 & 0x80 )
V_207 = V_217 ;
else
V_207 = ! ( F_3 ( V_198 , 0x24 ) & 0x40 ) ;
if ( V_216 & 0x40 )
V_208 = V_217 ;
else
V_208 = F_3 ( V_198 , 0x1C ) & 0x01 ;
if ( V_216 & 0x20 )
V_210 = V_217 ;
else
V_210 = F_3 ( V_198 , 0x1C ) & 0x02 ;
V_209 = V_208 ;
V_211 = false ;
V_212 = V_207 ;
V_213 = false ;
V_214 = false ;
V_215 = false ;
} else if ( V_53 -> V_54 == V_55 ) {
V_216 = F_3 ( V_198 , 0x24 ) ;
V_207 = ! ( V_216 & 0x80 ) ;
V_212 = V_216 & 0x08 ;
V_208 = false ;
V_209 = false ;
V_210 = false ;
V_211 = false ;
V_213 = false ;
V_214 = false ;
V_215 = false ;
} else {
V_216 = F_3 ( V_198 , 0x1c ) ;
V_207 = ! ( V_216 & ( 1 << 5 ) ) ;
V_208 = ! ( V_216 & ( 1 << 6 ) ) ;
V_210 = ! ( V_216 & ( 1 << 7 ) ) ;
V_212 = ! ( V_216 & ( 1 << 0 ) ) ;
V_213 = ! ( V_216 & ( 1 << 1 ) ) ;
V_214 = ! ( V_216 & ( 1 << 2 ) ) ;
V_209 = V_208 ;
if ( V_53 -> V_54 == V_59 ) {
V_216 = F_3 ( V_198 , 0x2d ) ;
V_211 = ( V_216 & ( 1 << 1 ) ) ;
V_215 = ( V_216 & ( 1 << 0 ) ) ;
} else {
V_211 = false ;
V_215 = false ;
}
}
V_53 -> V_71 = 0x03 | ( V_207 << 2 ) | ( V_208 << 3 ) |
( V_210 << 4 ) | ( V_211 << 5 ) ;
V_53 -> V_74 = 0x03 | ( V_207 << 2 ) | ( V_209 << 3 ) |
( V_210 << 4 ) ;
V_53 -> V_80 = 0x03 | ( V_212 << 2 ) | ( V_213 << 3 ) |
( V_214 << 4 ) | ( V_215 << 5 ) ;
}
static void F_123 ( struct V_52 * V_53 , const T_2 * V_220 ,
int * V_221 , int * V_222 )
{
int V_34 ;
T_1 V_153 ;
for ( V_34 = 0 ; V_34 < V_53 -> V_79 && * V_221 ; V_34 ++ ) {
int V_48 ;
if ( ! V_220 [ V_34 ] )
continue;
V_153 = F_29 ( V_53 , V_220 [ V_34 ] ) ;
V_153 &= 0x1f ;
if ( ! V_153 || ( * V_222 & ( 1 << V_153 ) ) )
continue;
if ( V_153 >= V_53 -> V_223 ||
! strlen ( V_53 -> V_170 [ V_153 ] ) )
continue;
V_48 = F_124 ( * V_221 ) ;
F_31 ( V_53 , V_53 -> V_154 [ V_48 ] , V_153 ) ;
* V_221 &= ~ ( 1 << V_48 ) ;
* V_222 |= 1 << V_153 ;
}
}
static int F_125 ( struct V_224 * V_225 )
{
struct V_18 * V_19 = & V_225 -> V_19 ;
struct V_226 * V_227 = F_126 ( V_19 ) ;
struct V_52 * V_53 ;
struct V_228 * V_65 ;
int V_34 , V_47 , V_149 = 0 ;
int V_153 , V_222 , V_221 ;
const T_2 * V_131 , * V_229 , * V_230 , * V_205 ;
const T_2 * V_231 , * V_232 , * V_233 ;
const T_2 * V_234 = NULL , * V_235 = NULL ;
int V_236 , V_237 ;
T_1 V_238 ;
struct V_17 * V_23 ;
struct V_18 * V_239 ;
V_65 = F_127 ( V_225 , V_240 , 0 ) ;
if ( ! F_128 ( & V_225 -> V_19 , V_65 -> V_241 , V_242 ,
V_6 ) )
return - V_7 ;
V_53 = F_25 ( & V_225 -> V_19 , sizeof( struct V_52 ) ,
V_38 ) ;
if ( ! V_53 )
return - V_39 ;
V_53 -> V_54 = V_227 -> V_54 ;
V_53 -> V_198 = V_227 -> V_198 ;
V_53 -> V_62 = V_65 -> V_241 ;
F_129 ( & V_53 -> V_113 ) ;
V_53 -> V_41 = V_243 [ V_53 -> V_54 ] ;
V_53 -> V_60 = 0xff ;
F_130 ( V_225 , V_53 ) ;
switch ( V_53 -> V_54 ) {
case V_55 :
V_53 -> V_118 = 9 ;
V_53 -> V_79 = 3 ;
V_53 -> V_105 = 4 ;
V_53 -> V_206 = 3 ;
V_53 -> V_156 = 6 ;
V_53 -> V_161 = 6 ;
V_53 -> V_125 = F_16 ;
V_53 -> V_164 = F_16 ;
V_53 -> V_170 = V_244 ;
V_53 -> V_223 = F_39 ( V_244 ) ;
V_53 -> V_177 = V_245 ;
V_53 -> V_178 = V_246 ;
V_53 -> V_176 = V_247 ;
V_53 -> V_121 = V_248 ;
V_53 -> V_122 [ 0 ] = V_249 ;
V_53 -> V_122 [ 1 ] = V_250 ;
V_53 -> V_100 = V_251 ;
V_53 -> V_124 = V_252 ;
V_53 -> V_84 = V_253 ;
V_53 -> V_75 = V_254 ;
V_53 -> V_127 = V_255 ;
V_53 -> V_128 = V_256 ;
V_53 -> V_99 [ 0 ] = V_257 ;
V_53 -> V_99 [ 1 ] = V_258 ;
V_53 -> V_99 [ 2 ] = V_259 ;
V_53 -> V_85 [ 0 ] = V_260 ;
V_53 -> V_85 [ 1 ] = V_261 ;
V_53 -> V_85 [ 2 ] = V_262 ;
V_53 -> V_85 [ 5 ] = V_263 ;
V_53 -> V_85 [ 6 ] = V_264 ;
V_53 -> V_180 = V_265 ;
V_53 -> V_81 = V_266 ;
V_53 -> V_82 = V_267 ;
V_53 -> V_268 = V_269 ;
V_53 -> V_270 = V_271 ;
V_53 -> V_108 = V_272 ;
V_53 -> V_90
= V_273 ;
V_53 -> V_110 = V_274 ;
V_53 -> V_111
= V_275 ;
V_53 -> V_112 = V_276 ;
V_53 -> V_136 = V_277 ;
V_53 -> V_154 = V_278 ;
V_53 -> V_91 = V_279 ;
V_53 -> V_93 = V_280 ;
V_53 -> V_96 [ 0 ] = V_281 ;
V_53 -> V_96 [ 1 ] = V_282 ;
V_53 -> V_96 [ 2 ] = V_283 ;
V_53 -> V_140 = V_284 ;
V_53 -> V_150 = V_285 ;
V_53 -> V_145 = V_286 ;
V_53 -> V_159 = V_287 ;
V_131 = V_288 ;
V_231 = V_289 ;
V_236 = F_39 ( V_288 ) ;
V_237 = F_39 ( V_289 ) ;
V_229 = V_290 ;
V_230 = V_291 ;
V_205 = V_292 ;
V_232 = V_293 ;
V_233 = V_294 ;
V_234 = V_295 ;
V_235 = V_296 ;
break;
case V_56 :
V_53 -> V_118 = 9 ;
V_53 -> V_79 = 3 ;
V_53 -> V_105 = 6 ;
V_53 -> V_72 = true ;
V_53 -> V_206 = 3 ;
V_53 -> V_156 = 3 ;
V_53 -> V_161 = 3 ;
V_53 -> V_150 = V_297 ;
V_53 -> V_159 = V_298 ;
V_53 -> V_125 = F_17 ;
V_53 -> V_164 = F_15 ;
V_53 -> V_103 = 0x7f ;
V_53 -> V_183 = 0x0f ;
V_53 -> V_191 = 15 ;
V_53 -> V_170 = V_299 ;
V_53 -> V_223 = F_39 ( V_299 ) ;
V_53 -> V_204 = V_300 ;
V_53 -> V_177 = V_301 ;
V_53 -> V_178 = V_302 ;
V_53 -> V_176 = V_303 ;
V_53 -> V_121 = V_304 ;
V_53 -> V_122 [ 0 ] = V_305 ;
V_53 -> V_122 [ 1 ] = V_306 ;
V_53 -> V_100 = V_307 ;
V_53 -> V_124 = V_308 ;
V_53 -> V_84 = V_309 ;
V_53 -> V_75 = V_310 ;
V_53 -> V_127 = V_311 ;
V_53 -> V_128 = V_312 ;
V_53 -> V_99 [ 0 ] = V_313 ;
V_53 -> V_99 [ 1 ] = V_314 ;
V_53 -> V_99 [ 2 ] = V_315 ;
V_53 -> V_85 [ 0 ] = V_316 ;
V_53 -> V_85 [ 1 ] = V_317 ;
V_53 -> V_85 [ 2 ] = V_318 ;
V_53 -> V_85 [ 3 ] = V_319 ;
V_53 -> V_85 [ 4 ] = V_320 ;
V_53 -> V_85 [ 5 ] = V_321 ;
V_53 -> V_180 = V_322 ;
V_53 -> V_81 = V_323 ;
V_53 -> V_82 = V_324 ;
V_53 -> V_268 = V_325 ;
V_53 -> V_270 = V_326 ;
V_53 -> V_108 = V_327 ;
V_53 -> V_90
= V_328 ;
V_53 -> V_136 = V_329 ;
V_53 -> V_154 = V_330 ;
V_53 -> V_91 = V_331 ;
V_53 -> V_93 = V_332 ;
V_53 -> V_96 [ 0 ] = V_333 ;
V_53 -> V_96 [ 1 ] = V_334 ;
V_53 -> V_96 [ 2 ] = V_335 ;
V_53 -> V_140 = V_336 ;
V_53 -> V_145 = V_337 ;
V_131 = V_338 ;
V_231 = V_339 ;
V_236 = F_39 ( V_338 ) ;
V_237 = F_39 ( V_339 ) ;
V_229 = V_340 ;
V_230 = V_341 ;
V_205 = V_342 ;
V_232 = V_343 ;
V_233 = V_344 ;
break;
case V_57 :
V_53 -> V_118 = 9 ;
V_53 -> V_79 = 3 ;
V_53 -> V_105 = 4 ;
V_53 -> V_72 = false ;
V_53 -> V_206 = 3 ;
V_53 -> V_156 = 3 ;
V_53 -> V_161 = 6 ;
V_53 -> V_150 = V_345 ;
V_53 -> V_159 = V_346 ;
V_53 -> V_125 = F_16 ;
V_53 -> V_164 = F_16 ;
V_53 -> V_103 = 0xff ;
V_53 -> V_183 = 0x07 ;
V_53 -> V_191 = 63 ;
V_53 -> V_170 = V_244 ;
V_53 -> V_223 = F_39 ( V_244 ) ;
V_53 -> V_204 = V_300 ;
V_53 -> V_177 = V_301 ;
V_53 -> V_178 = V_302 ;
V_53 -> V_176 = V_303 ;
V_53 -> V_121 = V_304 ;
V_53 -> V_122 [ 0 ] = V_305 ;
V_53 -> V_122 [ 1 ] = V_306 ;
V_53 -> V_100 = V_307 ;
V_53 -> V_124 = V_308 ;
V_53 -> V_84 = V_309 ;
V_53 -> V_75 = V_347 ;
V_53 -> V_127 = V_348 ;
V_53 -> V_128 = V_312 ;
V_53 -> V_99 [ 0 ] = V_313 ;
V_53 -> V_99 [ 1 ] = V_314 ;
V_53 -> V_99 [ 2 ] = V_315 ;
V_53 -> V_89 = V_349 ;
V_53 -> V_85 [ 0 ] = V_316 ;
V_53 -> V_85 [ 1 ] = V_317 ;
V_53 -> V_85 [ 2 ] = V_318 ;
V_53 -> V_85 [ 5 ] = V_321 ;
V_53 -> V_85 [ 6 ] = V_350 ;
V_53 -> V_180 = V_322 ;
V_53 -> V_81 = V_351 ;
V_53 -> V_82 = V_352 ;
V_53 -> V_268 = V_325 ;
V_53 -> V_270 = V_326 ;
V_53 -> V_108 = V_327 ;
V_53 -> V_90
= V_328 ;
V_53 -> V_136 = V_329 ;
V_53 -> V_154 = V_330 ;
V_53 -> V_91 = V_331 ;
V_53 -> V_93 = V_332 ;
V_53 -> V_96 [ 0 ] = V_333 ;
V_53 -> V_96 [ 1 ] = V_334 ;
V_53 -> V_96 [ 2 ] = V_335 ;
V_53 -> V_140 = V_336 ;
V_53 -> V_145 = V_353 ;
V_131 = V_338 ;
V_231 = V_339 ;
V_236 = F_39 ( V_338 ) ;
V_237 = F_39 ( V_339 ) ;
V_229 = V_340 ;
V_230 = V_341 ;
V_205 = V_354 ;
V_232 = V_355 ;
V_233 = V_356 ;
break;
case V_58 :
V_53 -> V_118 = 15 ;
V_53 -> V_79 = 5 ;
V_53 -> V_105 = 4 ;
V_53 -> V_72 = false ;
V_53 -> V_206 = 6 ;
V_53 -> V_156 = 2 ;
V_53 -> V_161 = 2 ;
V_53 -> V_150 = V_357 ;
V_53 -> V_159 = V_358 ;
V_53 -> V_125 = F_16 ;
V_53 -> V_164 = F_16 ;
V_53 -> V_103 = 0xff ;
V_53 -> V_183 = 0x07 ;
V_53 -> V_191 = 63 ;
V_53 -> V_170 = V_359 ;
V_53 -> V_223 = F_39 ( V_359 ) ;
V_53 -> V_204 = V_300 ;
V_53 -> V_177 = V_301 ;
V_53 -> V_178 = V_302 ;
V_53 -> V_176 = V_303 ;
V_53 -> V_121 = V_360 ;
V_53 -> V_122 [ 0 ] = V_305 ;
V_53 -> V_122 [ 1 ] = V_306 ;
V_53 -> V_100 = V_307 ;
V_53 -> V_124 = V_361 ;
V_53 -> V_84 = V_309 ;
V_53 -> V_75 = V_347 ;
V_53 -> V_127 = V_362 ;
V_53 -> V_128 = V_312 ;
V_53 -> V_99 [ 0 ] = V_313 ;
V_53 -> V_99 [ 1 ] = V_314 ;
V_53 -> V_99 [ 2 ] = V_315 ;
V_53 -> V_89 = V_349 ;
V_53 -> V_85 [ 0 ] = V_316 ;
V_53 -> V_85 [ 1 ] = V_317 ;
V_53 -> V_85 [ 2 ] = V_318 ;
V_53 -> V_85 [ 5 ] = V_321 ;
V_53 -> V_85 [ 6 ] = V_350 ;
V_53 -> V_180 = V_322 ;
V_53 -> V_81 = V_351 ;
V_53 -> V_82 = V_352 ;
V_53 -> V_268 = V_325 ;
V_53 -> V_270 = V_326 ;
V_53 -> V_108 = V_327 ;
V_53 -> V_90
= V_328 ;
V_53 -> V_110 = V_363 ;
V_53 -> V_111
= V_364 ;
V_53 -> V_112 = V_365 ;
V_53 -> V_136 = V_366 ;
V_53 -> V_154 = V_330 ;
V_53 -> V_91 = V_331 ;
V_53 -> V_93 = V_332 ;
V_53 -> V_96 [ 0 ] = V_333 ;
V_53 -> V_96 [ 1 ] = V_334 ;
V_53 -> V_96 [ 2 ] = V_335 ;
V_53 -> V_140 = V_367 ;
V_53 -> V_145 = V_353 ;
V_131 = V_368 ;
V_231 = V_369 ;
V_236 = F_39 ( V_368 ) ;
V_237 = F_39 ( V_369 ) ;
V_229 = V_370 ;
V_230 = V_371 ;
V_205 = V_372 ;
V_232 = V_373 ;
V_233 = V_374 ;
break;
case V_59 :
V_53 -> V_118 = 15 ;
V_53 -> V_79 = 6 ;
V_53 -> V_105 = 4 ;
V_53 -> V_72 = false ;
V_53 -> V_206 = 6 ;
V_53 -> V_156 = 2 ;
V_53 -> V_161 = 2 ;
V_53 -> V_150 = V_375 ;
V_53 -> V_159 = V_358 ;
V_53 -> V_125 = F_16 ;
V_53 -> V_164 = F_16 ;
V_53 -> V_103 = 0xff ;
V_53 -> V_183 = 0x07 ;
V_53 -> V_191 = 63 ;
V_53 -> V_170 = V_359 ;
V_53 -> V_223 = F_39 ( V_359 ) ;
V_53 -> V_204 = V_300 ;
V_53 -> V_177 = V_301 ;
V_53 -> V_178 = V_302 ;
V_53 -> V_176 = V_303 ;
V_53 -> V_121 = V_360 ;
V_53 -> V_122 [ 0 ] = V_305 ;
V_53 -> V_122 [ 1 ] = V_306 ;
V_53 -> V_100 = V_307 ;
V_53 -> V_124 = V_361 ;
V_53 -> V_84 = V_309 ;
V_53 -> V_75 = V_347 ;
V_53 -> V_127 = V_362 ;
V_53 -> V_128 = V_312 ;
V_53 -> V_99 [ 0 ] = V_313 ;
V_53 -> V_99 [ 1 ] = V_314 ;
V_53 -> V_99 [ 2 ] = V_315 ;
V_53 -> V_89 = V_349 ;
V_53 -> V_85 [ 0 ] = V_316 ;
V_53 -> V_85 [ 1 ] = V_317 ;
V_53 -> V_85 [ 2 ] = V_318 ;
V_53 -> V_85 [ 5 ] = V_376 ;
V_53 -> V_85 [ 6 ] = V_377 ;
V_53 -> V_180 = V_322 ;
V_53 -> V_81 = V_351 ;
V_53 -> V_82 = V_352 ;
V_53 -> V_268 = V_325 ;
V_53 -> V_270 = V_326 ;
V_53 -> V_108 = V_327 ;
V_53 -> V_90
= V_328 ;
V_53 -> V_110 = V_363 ;
V_53 -> V_111
= V_364 ;
V_53 -> V_112 = V_365 ;
V_53 -> V_136 = V_366 ;
V_53 -> V_154 = V_330 ;
V_53 -> V_91 = V_331 ;
V_53 -> V_93 = V_378 ;
V_53 -> V_96 [ 0 ] = V_379 ;
V_53 -> V_96 [ 1 ] = V_380 ;
V_53 -> V_96 [ 2 ] = V_381 ;
V_53 -> V_140 = V_382 ;
V_53 -> V_145 = V_353 ;
V_131 = V_368 ;
V_231 = V_369 ;
V_236 = F_39 ( V_368 ) ;
V_237 = F_39 ( V_369 ) ;
V_229 = V_370 ;
V_230 = V_371 ;
V_205 = V_372 ;
V_232 = V_373 ;
V_233 = V_374 ;
break;
default:
return - V_155 ;
}
V_53 -> V_119 = ( 1 << V_53 -> V_118 ) - 1 ;
V_53 -> V_130 = 0 ;
V_222 = 0 ;
V_221 = 0 ;
for ( V_34 = 0 ; V_34 < V_236 ; V_34 ++ ) {
if ( V_131 [ V_34 ] == 0 )
continue;
V_153 = F_29 ( V_53 , V_53 -> V_154 [ V_34 ] ) & 0x1f ;
if ( ! V_153 || ( V_222 & ( 1 << V_153 ) ) )
V_221 |= 1 << V_34 ;
V_222 |= 1 << V_153 ;
}
F_123 ( V_53 , V_53 -> V_91 , & V_221 , & V_222 ) ;
F_123 ( V_53 , V_53 -> V_93 , & V_221 , & V_222 ) ;
V_222 = 0 ;
V_47 = V_133 ;
for ( V_34 = 0 ; V_34 < V_236 ; V_34 ++ ) {
if ( V_131 [ V_34 ] == 0 )
continue;
V_153 = F_29 ( V_53 , V_53 -> V_154 [ V_34 ] ) & 0x1f ;
if ( ! V_153 || ( V_222 & ( 1 << V_153 ) ) )
continue;
if ( V_153 >= V_53 -> V_223 ||
! strlen ( V_53 -> V_170 [ V_153 ] ) ) {
F_70 ( V_19 ,
L_12 ,
V_153 , V_34 , V_53 -> V_154 [ V_34 ] , V_131 [ V_34 ] ) ;
continue;
}
V_222 |= 1 << V_153 ;
if ( V_153 <= V_53 -> V_206 ) {
V_53 -> V_130 |= 1 << ( V_153 - 1 ) ;
V_53 -> V_134 |= 1 << ( V_153 - 1 ) ;
V_53 -> V_131 [ 0 ] [ V_153 - 1 ] = V_131 [ V_34 ] ;
V_53 -> V_131 [ 1 ] [ V_153 - 1 ] = V_229 [ V_34 ] ;
V_53 -> V_131 [ 2 ] [ V_153 - 1 ] = V_230 [ V_34 ] ;
if ( V_235 && V_235 [ V_34 ] )
V_53 -> V_131 [ 3 ] [ V_153 - 1 ] = V_235 [ V_34 ] ;
else if ( V_233 [ V_153 - 1 ] )
V_53 -> V_131 [ 3 ] [ V_153 - 1 ]
= V_233 [ V_153 - 1 ] ;
if ( V_234 && V_234 [ V_34 ] )
V_53 -> V_131 [ 4 ] [ V_153 - 1 ] = V_234 [ V_34 ] ;
V_53 -> V_205 [ V_153 - 1 ] = V_205 [ V_34 ] ;
V_53 -> V_152 [ V_153 - 1 ] = V_153 ;
continue;
}
if ( V_47 >= V_129 )
continue;
V_53 -> V_130 |= 1 << V_47 ;
V_53 -> V_131 [ 0 ] [ V_47 ] = V_131 [ V_34 ] ;
V_53 -> V_131 [ 1 ] [ V_47 ] = V_229 [ V_34 ] ;
V_53 -> V_131 [ 2 ] [ V_47 ] = V_230 [ V_34 ] ;
V_53 -> V_205 [ V_47 ] = V_205 [ V_34 ] ;
if ( V_235 && V_235 [ V_34 ] )
V_53 -> V_131 [ 3 ] [ V_47 ] = V_235 [ V_34 ] ;
else if ( V_233 [ V_153 - 1 ] )
V_53 -> V_131 [ 3 ] [ V_47 ] = V_233 [ V_153 - 1 ] ;
if ( V_234 && V_234 [ V_34 ] )
V_53 -> V_131 [ 4 ] [ V_47 ] = V_234 [ V_34 ] ;
V_53 -> V_152 [ V_47 ] = V_153 ;
V_47 ++ ;
}
for ( V_34 = 0 ; V_34 < V_237 ; V_34 ++ ) {
if ( V_231 [ V_34 ] == 0 )
continue;
V_153 = F_29 ( V_53 , V_53 -> V_91 [ V_34 ] ) & 0x1f ;
if ( ! V_153 || ( V_222 & ( 1 << V_153 ) ) )
continue;
if ( V_153 >= V_53 -> V_223 ||
! strlen ( V_53 -> V_170 [ V_153 ] ) ) {
F_70 ( V_19 ,
L_12 ,
V_153 , V_34 , V_53 -> V_91 [ V_34 ] ,
V_231 [ V_34 ] ) ;
continue;
}
V_222 |= 1 << V_153 ;
if ( V_153 <= V_53 -> V_206 ) {
if ( V_53 -> V_130 & ( 1 << ( V_153 - 1 ) ) )
continue;
V_53 -> V_130 |= 1 << ( V_153 - 1 ) ;
V_53 -> V_134 |= 1 << ( V_153 - 1 ) ;
V_53 -> V_131 [ 0 ] [ V_153 - 1 ] = V_231 [ V_34 ] ;
V_53 -> V_152 [ V_153 - 1 ] = V_153 ;
continue;
}
if ( V_47 >= V_129 )
continue;
V_53 -> V_130 |= 1 << V_47 ;
V_53 -> V_131 [ 0 ] [ V_47 ] = V_231 [ V_34 ] ;
V_53 -> V_152 [ V_47 ] = V_153 ;
V_47 ++ ;
}
#ifdef F_131
for ( V_34 = 0 ; V_34 < V_53 -> V_223 - 1 ; V_34 ++ ) {
if ( ! V_232 [ V_34 ] )
continue;
if ( V_222 & ( 1 << ( V_34 + 1 ) ) )
continue;
if ( V_34 < V_53 -> V_206 ) {
if ( V_53 -> V_130 & ( 1 << V_34 ) )
continue;
V_53 -> V_130 |= 1 << V_34 ;
V_53 -> V_134 |= 1 << V_34 ;
V_53 -> V_131 [ 0 ] [ V_34 ] = V_232 [ V_34 ] ;
if ( V_34 < V_236 ) {
V_53 -> V_131 [ 1 ] [ V_34 ] = V_229 [ V_34 ] ;
V_53 -> V_131 [ 2 ] [ V_34 ] = V_230 [ V_34 ] ;
}
V_53 -> V_152 [ V_34 ] = V_34 + 1 ;
continue;
}
if ( V_47 >= V_129 )
break;
V_53 -> V_130 |= 1 << V_47 ;
V_53 -> V_131 [ 0 ] [ V_47 ] = V_232 [ V_34 ] ;
V_53 -> V_152 [ V_47 ] = V_34 + 1 ;
V_47 ++ ;
}
#endif
F_121 ( V_53 ) ;
V_149 = F_6 ( V_227 -> V_198 ) ;
if ( V_149 )
return V_149 ;
V_238 = F_3 ( V_227 -> V_198 , 0x2a ) ;
switch ( V_53 -> V_54 ) {
case V_56 :
V_53 -> V_202 = ( V_238 & 0x40 ) ;
break;
case V_57 :
V_53 -> V_202 = ( V_238 & 0x60 ) == 0x40 ;
break;
case V_55 :
case V_58 :
case V_59 :
break;
}
if ( V_53 -> V_202 ) {
F_5 ( V_227 -> V_198 , V_383 ) ;
V_53 -> V_194 = F_3 ( V_227 -> V_198 , 0xe3 ) ;
V_53 -> V_195 = F_132 () ;
}
if ( V_384 ) {
T_1 V_203 ;
F_5 ( V_227 -> V_198 , V_218 ) ;
V_203 = F_3 ( V_227 -> V_198 ,
V_385 ) ;
switch ( V_53 -> V_54 ) {
case V_55 :
V_203 |= 0xe0 ;
break;
case V_56 :
V_203 |= 0x1e ;
break;
case V_57 :
case V_58 :
V_203 |= 0x3e ;
break;
case V_59 :
V_203 |= 0x7e ;
break;
}
F_1 ( V_227 -> V_198 , V_385 ,
V_203 ) ;
F_70 ( & V_225 -> V_19 , L_13 ,
V_53 -> V_41 ) ;
}
F_122 ( V_53 ) ;
F_8 ( V_227 -> V_198 ) ;
F_40 ( V_19 , V_53 ) ;
V_23 = F_23 ( V_19 , & V_386 ,
V_53 -> V_79 ) ;
if ( F_133 ( V_23 ) )
return F_134 ( V_23 ) ;
V_53 -> V_387 [ V_53 -> V_388 ++ ] = V_23 ;
V_23 = F_23 ( V_19 , & V_389 ,
F_135 ( V_53 -> V_119 ) ) ;
if ( F_133 ( V_23 ) )
return F_134 ( V_23 ) ;
V_53 -> V_387 [ V_53 -> V_388 ++ ] = V_23 ;
V_23 = F_23 ( V_19 , & V_390 ,
F_135 ( V_53 -> V_71 ) ) ;
if ( F_133 ( V_23 ) )
return F_134 ( V_23 ) ;
V_53 -> V_387 [ V_53 -> V_388 ++ ] = V_23 ;
V_23 = F_23 ( V_19 , & V_391 ,
F_135 ( V_53 -> V_130 ) ) ;
if ( F_133 ( V_23 ) )
return F_134 ( V_23 ) ;
V_53 -> V_387 [ V_53 -> V_388 ++ ] = V_23 ;
V_53 -> V_387 [ V_53 -> V_388 ++ ] = & V_392 ;
V_239 = F_136 ( V_19 , V_53 -> V_41 ,
V_53 , V_53 -> V_387 ) ;
return F_137 ( V_239 ) ;
}
static int F_138 ( struct V_18 * V_19 )
{
struct V_52 * V_53 = F_48 ( V_19 ) ;
F_49 ( & V_53 -> V_113 ) ;
V_53 -> V_172 = F_29 ( V_53 , V_53 -> V_177 ) ;
if ( V_53 -> V_54 == V_56 ) {
V_53 -> V_393 = F_29 ( V_53 , V_68 ) ;
V_53 -> V_394 = F_29 ( V_53 , V_70 ) ;
}
F_51 ( & V_53 -> V_113 ) ;
return 0 ;
}
static int F_139 ( struct V_18 * V_19 )
{
struct V_52 * V_53 = F_44 ( V_19 ) ;
int V_34 , V_76 ;
F_49 ( & V_53 -> V_113 ) ;
V_53 -> V_60 = 0xff ;
for ( V_34 = 0 ; V_34 < V_53 -> V_118 ; V_34 ++ ) {
if ( ! ( V_53 -> V_119 & ( 1 << V_34 ) ) )
continue;
F_31 ( V_53 , V_53 -> V_122 [ 0 ] [ V_34 ] ,
V_53 -> V_120 [ V_34 ] [ 1 ] ) ;
F_31 ( V_53 , V_53 -> V_122 [ 1 ] [ V_34 ] ,
V_53 -> V_120 [ V_34 ] [ 2 ] ) ;
}
for ( V_34 = 0 ; V_34 < F_39 ( V_53 -> V_73 ) ; V_34 ++ ) {
if ( ! ( V_53 -> V_74 & ( 1 << V_34 ) ) )
continue;
F_31 ( V_53 , V_53 -> V_75 [ V_34 ] ,
V_53 -> V_73 [ V_34 ] ) ;
}
for ( V_34 = 0 ; V_34 < V_129 ; V_34 ++ ) {
if ( ! ( V_53 -> V_130 & ( 1 << V_34 ) ) )
continue;
for ( V_76 = 1 ; V_76 < F_39 ( V_53 -> V_131 ) ; V_76 ++ )
if ( V_53 -> V_131 [ V_76 ] [ V_34 ] )
F_33 ( V_53 , V_53 -> V_131 [ V_76 ] [ V_34 ] ,
V_53 -> V_132 [ V_76 ] [ V_34 ] ) ;
}
F_31 ( V_53 , V_53 -> V_177 , V_53 -> V_172 ) ;
if ( V_53 -> V_54 == V_56 ) {
F_31 ( V_53 , V_68 , V_53 -> V_393 ) ;
F_31 ( V_53 , V_70 , V_53 -> V_394 ) ;
}
V_53 -> V_117 = false ;
F_51 ( & V_53 -> V_113 ) ;
return 0 ;
}
static int T_7 F_140 ( int V_395 , struct V_226 * V_227 )
{
T_2 V_3 ;
int V_149 ;
int V_62 ;
V_149 = F_6 ( V_395 ) ;
if ( V_149 )
return V_149 ;
if ( V_396 )
V_3 = V_396 ;
else
V_3 = ( F_3 ( V_395 , V_397 ) << 8 )
| F_3 ( V_395 , V_397 + 1 ) ;
switch ( V_3 & V_398 ) {
case V_399 :
V_227 -> V_54 = V_55 ;
break;
case V_400 :
V_227 -> V_54 = V_56 ;
break;
case V_401 :
V_227 -> V_54 = V_57 ;
break;
case V_402 :
V_227 -> V_54 = V_58 ;
break;
case V_403 :
V_227 -> V_54 = V_59 ;
break;
default:
if ( V_3 != 0xffff )
F_141 ( L_14 , V_3 ) ;
F_8 ( V_395 ) ;
return - V_155 ;
}
F_5 ( V_395 , V_218 ) ;
V_3 = ( F_3 ( V_395 , V_404 ) << 8 )
| F_3 ( V_395 , V_404 + 1 ) ;
V_62 = V_3 & V_405 ;
if ( V_62 == 0 ) {
F_142 ( L_15 ) ;
F_8 ( V_395 ) ;
return - V_155 ;
}
V_3 = F_3 ( V_395 , V_219 ) ;
if ( ! ( V_3 & 0x01 ) ) {
F_143 ( L_16 ) ;
F_1 ( V_395 , V_219 , V_3 | 0x01 ) ;
}
if ( V_227 -> V_54 == V_59 ) {
V_3 = F_3 ( V_395 , V_406 ) ;
if ( V_3 & 0x10 ) {
F_144 ( L_17 ) ;
F_1 ( V_395 ,
V_406 ,
V_3 & ~ 0x10 ) ;
}
}
F_8 ( V_395 ) ;
F_144 ( L_18 ,
V_407 [ V_227 -> V_54 ] , V_395 , V_62 ) ;
V_227 -> V_198 = V_395 ;
return V_62 ;
}
static int T_7 F_145 ( void )
{
int V_34 , V_149 ;
bool V_408 = false ;
int V_409 ;
struct V_228 V_65 ;
struct V_226 V_227 ;
int V_395 [ 2 ] = { 0x2e , 0x4e } ;
V_149 = F_146 ( & V_410 ) ;
if ( V_149 )
return V_149 ;
for ( V_34 = 0 ; V_34 < F_39 ( V_225 ) ; V_34 ++ ) {
V_409 = F_140 ( V_395 [ V_34 ] , & V_227 ) ;
if ( V_409 <= 0 )
continue;
V_408 = true ;
V_225 [ V_34 ] = F_147 ( V_6 , V_409 ) ;
if ( ! V_225 [ V_34 ] ) {
V_149 = - V_39 ;
goto V_411;
}
V_149 = F_148 ( V_225 [ V_34 ] , & V_227 ,
sizeof( struct V_226 ) ) ;
if ( V_149 )
goto V_411;
memset ( & V_65 , 0 , sizeof( V_65 ) ) ;
V_65 . V_41 = V_6 ;
V_65 . V_241 = V_409 + V_412 ;
V_65 . V_413 = V_409 + V_412 + V_242 - 1 ;
V_65 . V_414 = V_240 ;
V_149 = F_149 ( & V_65 ) ;
if ( V_149 ) {
F_150 ( V_225 [ V_34 ] ) ;
V_225 [ V_34 ] = NULL ;
continue;
}
V_149 = F_151 ( V_225 [ V_34 ] , & V_65 , 1 ) ;
if ( V_149 )
goto V_411;
V_149 = F_152 ( V_225 [ V_34 ] ) ;
if ( V_149 )
goto V_411;
}
if ( ! V_408 ) {
V_149 = - V_155 ;
goto V_415;
}
return 0 ;
V_411:
for ( V_34 = 0 ; V_34 < F_39 ( V_225 ) ; V_34 ++ ) {
if ( V_225 [ V_34 ] )
F_150 ( V_225 [ V_34 ] ) ;
}
V_415:
F_153 ( & V_410 ) ;
return V_149 ;
}
static void T_8 F_154 ( void )
{
int V_34 ;
for ( V_34 = 0 ; V_34 < F_39 ( V_225 ) ; V_34 ++ ) {
if ( V_225 [ V_34 ] )
F_155 ( V_225 [ V_34 ] ) ;
}
F_153 ( & V_410 ) ;
}
