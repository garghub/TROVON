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
case V_60 :
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
static inline void F_27 ( struct V_52 * V_53 , T_2 V_2 )
{
T_1 V_61 = V_2 >> 8 ;
if ( V_53 -> V_61 != V_61 ) {
F_28 ( V_62 , V_53 -> V_63 + V_64 ) ;
F_28 ( V_61 , V_53 -> V_63 + V_65 ) ;
V_53 -> V_61 = V_61 ;
}
}
static T_2 F_29 ( struct V_52 * V_53 , T_2 V_2 )
{
int V_66 , V_67 = F_26 ( V_53 , V_2 ) ;
F_27 ( V_53 , V_2 ) ;
F_28 ( V_2 & 0xff , V_53 -> V_63 + V_64 ) ;
V_66 = F_30 ( V_53 -> V_63 + V_65 ) ;
if ( V_67 ) {
F_28 ( ( V_2 & 0xff ) + 1 ,
V_53 -> V_63 + V_64 ) ;
V_66 = ( V_66 << 8 ) + F_30 ( V_53 -> V_63 + V_65 ) ;
}
return V_66 ;
}
static int F_31 ( struct V_52 * V_53 , T_2 V_2 , T_2 V_68 )
{
int V_67 = F_26 ( V_53 , V_2 ) ;
F_27 ( V_53 , V_2 ) ;
F_28 ( V_2 & 0xff , V_53 -> V_63 + V_64 ) ;
if ( V_67 ) {
F_28 ( V_68 >> 8 , V_53 -> V_63 + V_65 ) ;
F_28 ( ( V_2 & 0xff ) + 1 ,
V_53 -> V_63 + V_64 ) ;
}
F_28 ( V_68 & 0xff , V_53 -> V_63 + V_65 ) ;
return 0 ;
}
static T_2 F_32 ( struct V_52 * V_53 , T_2 V_2 )
{
T_2 V_66 ;
V_66 = F_29 ( V_53 , V_2 ) ;
if ( ! F_26 ( V_53 , V_2 ) )
V_66 <<= 8 ;
return V_66 ;
}
static int F_33 ( struct V_52 * V_53 , T_2 V_2 , T_2 V_68 )
{
if ( ! F_26 ( V_53 , V_2 ) )
V_68 >>= 8 ;
return F_31 ( V_53 , V_2 , V_68 ) ;
}
static void F_34 ( struct V_52 * V_53 , int V_15 )
{
T_1 V_2 ;
switch ( V_15 ) {
case 0 :
V_2 = ( F_29 ( V_53 , V_69 ) & 0x70 )
| ( V_53 -> V_70 [ 0 ] & 0x7 ) ;
F_31 ( V_53 , V_69 , V_2 ) ;
break;
case 1 :
V_2 = ( F_29 ( V_53 , V_69 ) & 0x7 )
| ( ( V_53 -> V_70 [ 1 ] << 4 ) & 0x70 ) ;
F_31 ( V_53 , V_69 , V_2 ) ;
break;
case 2 :
V_2 = ( F_29 ( V_53 , V_71 ) & 0x70 )
| ( V_53 -> V_70 [ 2 ] & 0x7 ) ;
F_31 ( V_53 , V_71 , V_2 ) ;
break;
case 3 :
V_2 = ( F_29 ( V_53 , V_71 ) & 0x7 )
| ( ( V_53 -> V_70 [ 3 ] << 4 ) & 0x70 ) ;
F_31 ( V_53 , V_71 , V_2 ) ;
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
V_34 = F_29 ( V_53 , V_69 ) ;
V_53 -> V_70 [ 0 ] = V_34 & 0x7 ;
V_53 -> V_70 [ 1 ] = ( V_34 & 0x70 ) >> 4 ;
V_34 = F_29 ( V_53 , V_71 ) ;
V_53 -> V_70 [ 2 ] = V_34 & 0x7 ;
if ( V_53 -> V_72 & ( 1 << 3 ) )
V_53 -> V_70 [ 3 ] = ( V_34 & 0x70 ) >> 4 ;
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
for ( V_34 = 0 ; V_34 < F_39 ( V_53 -> V_70 ) ; V_34 ++ ) {
if ( ! ( V_53 -> V_72 & ( 1 << V_34 ) ) )
continue;
if ( V_53 -> V_70 [ V_34 ] == 0 ) {
V_53 -> V_70 [ V_34 ] = 7 ;
F_35 ( V_53 , V_34 ) ;
}
}
}
static void F_40 ( struct V_18 * V_19 ,
struct V_52 * V_53 )
{
int V_34 ;
T_1 V_2 ;
if ( V_53 -> V_73 )
F_38 ( V_53 ) ;
for ( V_34 = 0 ; V_34 < F_39 ( V_53 -> V_74 ) ; V_34 ++ ) {
if ( V_53 -> V_75 & ( 1 << V_34 ) ) {
V_2 = F_29 ( V_53 , V_53 -> V_76 [ V_34 ] ) ;
if ( ! V_2 )
F_31 ( V_53 , V_53 -> V_76 [ V_34 ] ,
V_53 -> V_73 ? 0xff
: 0xff1f ) ;
}
}
}
static void F_41 ( struct V_18 * V_19 ,
struct V_52 * V_53 , int V_15 , T_2 V_2 )
{
T_1 V_70 = V_53 -> V_70 [ V_15 ] ;
T_2 V_74 ;
if ( ! V_53 -> V_73 )
return;
if ( V_2 == 0x00 && V_70 < 0x07 )
V_70 ++ ;
else if ( V_2 != 0x00 && V_2 < 0x30 && V_70 > 0 )
V_70 -- ;
if ( V_70 != V_53 -> V_70 [ V_15 ] ) {
F_42 ( V_19 , L_1 ,
V_15 + 1 , F_19 ( V_53 -> V_70 [ V_15 ] ) ,
F_19 ( V_70 ) ) ;
if ( V_53 -> V_75 & ( 1 << V_15 ) ) {
V_74 = V_53 -> V_74 [ V_15 ] ;
if ( V_70 > V_53 -> V_70 [ V_15 ] ) {
if ( V_74 != 255 && V_74 > 1 )
V_74 >>= 1 ;
} else {
if ( V_74 != 255 ) {
V_74 <<= 1 ;
if ( V_74 > 254 )
V_74 = 254 ;
}
}
if ( V_74 != V_53 -> V_74 [ V_15 ] ) {
V_53 -> V_74 [ V_15 ] = V_74 ;
F_31 ( V_53 , V_53 -> V_76 [ V_15 ] ,
V_74 ) ;
}
}
V_53 -> V_70 [ V_15 ] = V_70 ;
F_35 ( V_53 , V_15 ) ;
}
}
static void F_43 ( struct V_18 * V_19 )
{
struct V_52 * V_53 = F_44 ( V_19 ) ;
int V_34 , V_77 ;
int V_78 , V_2 ;
bool V_79 ;
for ( V_34 = 0 ; V_34 < V_53 -> V_80 ; V_34 ++ ) {
if ( ! ( V_53 -> V_81 & ( 1 << V_34 ) ) )
continue;
V_79 = V_53 -> V_82 [ V_34 ] &&
( F_29 ( V_53 , V_53 -> V_82 [ V_34 ] )
& V_53 -> V_83 [ V_34 ] ) ;
V_53 -> V_84 [ V_34 ] = V_79 ;
V_78 = F_29 ( V_53 , V_53 -> V_85 [ V_34 ] ) ;
for ( V_77 = 0 ; V_77 < F_39 ( V_53 -> V_86 ) ; V_77 ++ ) {
if ( V_53 -> V_86 [ V_77 ] && V_53 -> V_86 [ V_77 ] [ V_34 ] ) {
V_53 -> V_9 [ V_77 ] [ V_34 ]
= F_29 ( V_53 ,
V_53 -> V_86 [ V_77 ] [ V_34 ] ) ;
}
}
V_53 -> V_8 [ V_34 ] = F_10 ( V_53 -> V_9 [ 0 ] [ V_34 ] ,
( V_78 >> 4 ) & 7 ) ;
if ( ! V_53 -> V_87 [ 0 ] [ V_34 ] ||
V_53 -> V_8 [ V_34 ] != V_88 )
V_53 -> V_87 [ 0 ] [ V_34 ] = V_78 & 0x0f ;
if ( ! V_53 -> V_89 [ V_34 ] ||
V_53 -> V_8 [ V_34 ] == V_88 ) {
T_1 V_33 = V_78 & 0x0f ;
if ( V_53 -> V_90 ) {
V_33 |= ( F_29 ( V_53 ,
V_53 -> V_90 [ V_34 ] ) & 0x70 ) >> 1 ;
}
V_53 -> V_89 [ V_34 ] = V_33 ;
}
V_53 -> V_87 [ 1 ] [ V_34 ] =
F_29 ( V_53 ,
V_53 -> V_91 [ V_34 ] ) ;
V_2 = F_29 ( V_53 , V_53 -> V_92 [ V_34 ] ) ;
V_53 -> V_93 [ V_34 ] = V_2 & 0x1f ;
if ( V_2 & 0x80 )
V_53 -> V_9 [ 2 ] [ V_34 ] = 0 ;
if ( ! V_53 -> V_94 [ V_34 ] )
continue;
V_2 = F_29 ( V_53 , V_53 -> V_94 [ V_34 ] ) ;
V_53 -> V_95 [ V_34 ] = V_2 & 0x1f ;
if ( V_77 == 1 && ! ( V_2 & 0x80 ) )
V_53 -> V_95 [ V_34 ] = 0 ;
for ( V_77 = 0 ; V_77 < F_39 ( V_53 -> V_96 ) ; V_77 ++ ) {
V_53 -> V_96 [ V_77 ] [ V_34 ]
= F_29 ( V_53 ,
V_53 -> V_97 [ V_77 ] [ V_34 ] ) ;
}
}
}
static void F_45 ( struct V_18 * V_19 )
{
struct V_52 * V_53 = F_44 ( V_19 ) ;
int V_34 , V_77 ;
T_1 V_2 ;
T_2 V_98 ;
for ( V_34 = 0 ; V_34 < V_53 -> V_80 ; V_34 ++ ) {
if ( ! ( V_53 -> V_81 & ( 1 << V_34 ) ) )
continue;
for ( V_77 = 0 ; V_77 < F_39 ( V_53 -> V_99 ) ; V_77 ++ ) {
V_53 -> V_99 [ V_77 ] [ V_34 ] =
F_29 ( V_53 , V_53 -> V_100 [ V_77 ] [ V_34 ] ) ;
}
V_98 = F_29 ( V_53 , V_53 -> V_101 [ V_34 ] ) ;
if ( ! V_53 -> V_102 [ V_34 ] ||
V_53 -> V_8 [ V_34 ] == V_103 )
V_53 -> V_102 [ V_34 ] = V_98 & V_53 -> V_104 ;
if ( ! V_53 -> V_105 [ V_34 ] ||
V_53 -> V_8 [ V_34 ] == V_88 ) {
if ( V_53 -> V_90 ) {
V_98 |= ( F_29 ( V_53 ,
V_53 -> V_90 [ V_34 ] ) & 0x0f ) << 8 ;
}
V_53 -> V_105 [ V_34 ] = V_98 ;
}
for ( V_77 = 0 ; V_77 < V_53 -> V_106 ; V_77 ++ ) {
V_53 -> V_107 [ V_34 ] [ V_77 ] =
F_29 ( V_53 ,
F_46 ( V_53 , V_34 , V_77 ) ) ;
V_53 -> V_108 [ V_34 ] [ V_77 ] =
F_29 ( V_53 ,
F_47 ( V_53 , V_34 , V_77 ) ) ;
}
V_53 -> V_108 [ V_34 ] [ V_53 -> V_106 ] =
F_29 ( V_53 , V_53 -> V_109 [ V_34 ] ) ;
switch ( V_53 -> V_54 ) {
case V_56 :
V_2 = F_29 ( V_53 ,
V_110 [ V_34 ] ) ;
V_53 -> V_107 [ V_34 ] [ V_53 -> V_106 ] =
( V_2 & 0x02 ) ? 0xff : 0x00 ;
break;
case V_57 :
V_53 -> V_107 [ V_34 ] [ V_53 -> V_106 ] = 0xff ;
break;
case V_55 :
case V_58 :
case V_59 :
case V_60 :
V_2 = F_29 ( V_53 ,
V_53 -> V_111 [ V_34 ] ) ;
if ( V_2 & V_53 -> V_112 )
V_2 = F_29 ( V_53 ,
V_53 -> V_113 [ V_34 ] ) ;
else
V_2 = 0xff ;
V_53 -> V_107 [ V_34 ] [ V_53 -> V_106 ] = V_2 ;
break;
}
}
}
static struct V_52 * F_48 ( struct V_18 * V_19 )
{
struct V_52 * V_53 = F_44 ( V_19 ) ;
int V_34 , V_77 ;
F_49 ( & V_53 -> V_114 ) ;
if ( F_50 ( V_115 , V_53 -> V_116 + V_117 + V_117 / 2 )
|| ! V_53 -> V_118 ) {
F_37 ( V_53 ) ;
for ( V_34 = 0 ; V_34 < V_53 -> V_119 ; V_34 ++ ) {
if ( ! ( V_53 -> V_120 & ( 1 << V_34 ) ) )
continue;
V_53 -> V_121 [ V_34 ] [ 0 ] = F_29 ( V_53 ,
V_53 -> V_122 [ V_34 ] ) ;
V_53 -> V_121 [ V_34 ] [ 1 ] = F_29 ( V_53 ,
V_53 -> V_123 [ 0 ] [ V_34 ] ) ;
V_53 -> V_121 [ V_34 ] [ 2 ] = F_29 ( V_53 ,
V_53 -> V_123 [ 1 ] [ V_34 ] ) ;
}
for ( V_34 = 0 ; V_34 < F_39 ( V_53 -> V_124 ) ; V_34 ++ ) {
T_2 V_2 ;
if ( ! ( V_53 -> V_72 & ( 1 << V_34 ) ) )
continue;
V_2 = F_29 ( V_53 , V_53 -> V_125 [ V_34 ] ) ;
V_53 -> V_124 [ V_34 ] = V_53 -> V_126 ( V_2 ,
V_53 -> V_70 [ V_34 ] ) ;
if ( V_53 -> V_75 & ( 1 << V_34 ) )
V_53 -> V_74 [ V_34 ] = F_29 ( V_53 ,
V_53 -> V_76 [ V_34 ] ) ;
V_53 -> V_127 [ V_34 ] =
( F_29 ( V_53 , V_53 -> V_128 [ V_34 ] )
>> V_53 -> V_129 [ V_34 ] ) & 0x03 ;
F_41 ( V_19 , V_53 , V_34 , V_2 ) ;
}
F_43 ( V_19 ) ;
F_45 ( V_19 ) ;
for ( V_34 = 0 ; V_34 < V_130 ; V_34 ++ ) {
if ( ! ( V_53 -> V_131 & ( 1 << V_34 ) ) )
continue;
for ( V_77 = 0 ; V_77 < F_39 ( V_53 -> V_132 ) ; V_77 ++ ) {
if ( V_53 -> V_132 [ V_77 ] [ V_34 ] )
V_53 -> V_133 [ V_77 ] [ V_34 ]
= F_32 ( V_53 ,
V_53 -> V_132 [ V_77 ] [ V_34 ] ) ;
}
if ( V_34 >= V_134 ||
! ( V_53 -> V_135 & ( 1 << V_34 ) ) )
continue;
V_53 -> V_136 [ V_34 ]
= F_29 ( V_53 , V_53 -> V_137 [ V_34 ] ) ;
}
V_53 -> V_138 = 0 ;
for ( V_34 = 0 ; V_34 < V_139 ; V_34 ++ ) {
T_1 V_140 ;
if ( ! V_53 -> V_141 [ V_34 ] )
continue;
V_140 = F_29 ( V_53 , V_53 -> V_141 [ V_34 ] ) ;
V_53 -> V_138 |= ( ( V_142 ) V_140 ) << ( V_34 << 3 ) ;
}
V_53 -> V_143 = 0 ;
for ( V_34 = 0 ; V_34 < V_144 ; V_34 ++ ) {
T_1 V_145 ;
if ( ! V_53 -> V_146 [ V_34 ] )
continue;
V_145 = F_29 ( V_53 , V_53 -> V_146 [ V_34 ] ) ;
V_53 -> V_143 |= ( ( V_142 ) V_145 ) << ( V_34 << 3 ) ;
}
V_53 -> V_116 = V_115 ;
V_53 -> V_118 = true ;
}
F_51 ( & V_53 -> V_114 ) ;
return V_53 ;
}
static T_4
F_52 ( struct V_18 * V_19 , struct V_147 * V_43 , char * V_148 )
{
struct V_52 * V_53 = F_48 ( V_19 ) ;
struct V_28 * V_149 = F_53 ( V_43 ) ;
int V_48 = V_149 -> V_48 ;
int V_15 = V_149 -> V_15 ;
return sprintf ( V_148 , L_2 , F_20 ( V_53 -> V_121 [ V_15 ] [ V_48 ] , V_15 ) ) ;
}
static T_4
F_54 ( struct V_18 * V_19 , struct V_147 * V_43 , const char * V_148 ,
T_5 V_35 )
{
struct V_52 * V_53 = F_44 ( V_19 ) ;
struct V_28 * V_149 = F_53 ( V_43 ) ;
int V_48 = V_149 -> V_48 ;
int V_15 = V_149 -> V_15 ;
unsigned long V_3 ;
int V_150 ;
V_150 = F_55 ( V_148 , 10 , & V_3 ) ;
if ( V_150 < 0 )
return V_150 ;
F_49 ( & V_53 -> V_114 ) ;
V_53 -> V_121 [ V_15 ] [ V_48 ] = F_22 ( V_3 , V_15 ) ;
F_31 ( V_53 , V_53 -> V_123 [ V_48 - 1 ] [ V_15 ] ,
V_53 -> V_121 [ V_15 ] [ V_48 ] ) ;
F_51 ( & V_53 -> V_114 ) ;
return V_35 ;
}
static T_4
F_56 ( struct V_18 * V_19 , struct V_147 * V_43 , char * V_148 )
{
struct V_52 * V_53 = F_48 ( V_19 ) ;
struct V_26 * V_149 = F_57 ( V_43 ) ;
int V_15 = V_53 -> V_151 [ V_149 -> V_48 ] ;
return sprintf ( V_148 , L_3 ,
( unsigned int ) ( ( V_53 -> V_138 >> V_15 ) & 0x01 ) ) ;
}
static int F_58 ( struct V_52 * V_53 , int V_48 , int V_35 )
{
int V_152 = V_53 -> V_153 [ V_48 ] ;
int V_15 ;
for ( V_15 = 0 ; V_15 < V_35 ; V_15 ++ ) {
int V_154 ;
V_154 = F_29 ( V_53 ,
V_53 -> V_155 [ V_15 ] ) & 0x1f ;
if ( V_154 == V_152 )
return V_15 ;
}
return - V_156 ;
}
static T_4
F_59 ( struct V_18 * V_19 , struct V_147 * V_43 , char * V_148 )
{
struct V_26 * V_149 = F_57 ( V_43 ) ;
struct V_52 * V_53 = F_48 ( V_19 ) ;
unsigned int V_140 = 0 ;
int V_15 ;
V_15 = F_58 ( V_53 , V_149 -> V_48 , V_53 -> V_157 ) ;
if ( V_15 >= 0 ) {
int V_158 = V_53 -> V_151 [ V_15 + V_159 ] ;
V_140 = ( V_53 -> V_138 >> V_158 ) & 0x01 ;
}
return sprintf ( V_148 , L_3 , V_140 ) ;
}
static T_4
F_60 ( struct V_18 * V_19 , struct V_147 * V_43 , char * V_148 )
{
struct V_26 * V_149 = F_57 ( V_43 ) ;
struct V_52 * V_53 = F_48 ( V_19 ) ;
int V_15 = V_53 -> V_160 [ V_149 -> V_48 ] ;
return sprintf ( V_148 , L_3 ,
( unsigned int ) ( ( V_53 -> V_143 >> V_15 ) & 0x01 ) ) ;
}
static T_4
F_61 ( struct V_18 * V_19 , struct V_147 * V_43 , const char * V_148 ,
T_5 V_35 )
{
struct V_28 * V_149 = F_53 ( V_43 ) ;
struct V_52 * V_53 = F_44 ( V_19 ) ;
int V_15 = V_53 -> V_160 [ V_149 -> V_48 ] ;
int V_161 = V_15 >> 3 ;
unsigned long V_3 ;
int V_150 ;
V_150 = F_55 ( V_148 , 10 , & V_3 ) ;
if ( V_150 < 0 )
return V_150 ;
if ( V_3 > 1 )
return - V_36 ;
F_49 ( & V_53 -> V_114 ) ;
if ( V_3 )
V_53 -> V_143 |= ( 1ULL << V_15 ) ;
else
V_53 -> V_143 &= ~ ( 1ULL << V_15 ) ;
F_31 ( V_53 , V_53 -> V_146 [ V_161 ] ,
( V_53 -> V_143 >> ( V_161 << 3 ) ) & 0xff ) ;
F_51 ( & V_53 -> V_114 ) ;
return V_35 ;
}
static T_4
F_62 ( struct V_18 * V_19 , struct V_147 * V_43 , char * V_148 )
{
struct V_26 * V_149 = F_57 ( V_43 ) ;
struct V_52 * V_53 = F_48 ( V_19 ) ;
unsigned int V_145 = 0 ;
int V_15 ;
V_15 = F_58 ( V_53 , V_149 -> V_48 , V_53 -> V_162 ) ;
if ( V_15 >= 0 ) {
int V_158 = V_53 -> V_160 [ V_15 + V_159 ] ;
V_145 = ( V_53 -> V_143 >> V_158 ) & 0x01 ;
}
return sprintf ( V_148 , L_3 , V_145 ) ;
}
static T_4
F_63 ( struct V_18 * V_19 , struct V_147 * V_43 ,
const char * V_148 , T_5 V_35 )
{
struct V_28 * V_149 = F_53 ( V_43 ) ;
struct V_52 * V_53 = F_44 ( V_19 ) ;
int V_15 , V_158 , V_161 ;
unsigned long V_3 ;
int V_150 ;
V_150 = F_55 ( V_148 , 10 , & V_3 ) ;
if ( V_150 < 0 )
return V_150 ;
if ( V_3 > 1 )
return - V_36 ;
V_15 = F_58 ( V_53 , V_149 -> V_48 , V_53 -> V_162 ) ;
if ( V_15 < 0 )
return V_15 ;
V_158 = V_53 -> V_160 [ V_15 + V_159 ] ;
V_161 = V_158 >> 3 ;
F_49 ( & V_53 -> V_114 ) ;
if ( V_3 )
V_53 -> V_143 |= ( 1ULL << V_158 ) ;
else
V_53 -> V_143 &= ~ ( 1ULL << V_158 ) ;
F_31 ( V_53 , V_53 -> V_146 [ V_161 ] ,
( V_53 -> V_143 >> ( V_161 << 3 ) ) & 0xff ) ;
F_51 ( & V_53 -> V_114 ) ;
return V_35 ;
}
static T_6 F_64 ( struct V_163 * V_164 ,
struct V_30 * V_43 , int V_48 )
{
struct V_18 * V_19 = F_65 ( V_164 , struct V_18 , V_164 ) ;
struct V_52 * V_53 = F_44 ( V_19 ) ;
int V_121 = V_48 / 5 ;
if ( ! ( V_53 -> V_120 & ( 1 << V_121 ) ) )
return 0 ;
return V_43 -> V_10 ;
}
static T_4
F_66 ( struct V_18 * V_19 , struct V_147 * V_43 , char * V_148 )
{
struct V_52 * V_53 = F_48 ( V_19 ) ;
struct V_26 * V_149 = F_57 ( V_43 ) ;
int V_15 = V_149 -> V_48 ;
return sprintf ( V_148 , L_4 , V_53 -> V_124 [ V_15 ] ) ;
}
static T_4
F_67 ( struct V_18 * V_19 , struct V_147 * V_43 , char * V_148 )
{
struct V_52 * V_53 = F_48 ( V_19 ) ;
struct V_26 * V_149 = F_57 ( V_43 ) ;
int V_15 = V_149 -> V_48 ;
return sprintf ( V_148 , L_4 ,
V_53 -> V_165 ( V_53 -> V_74 [ V_15 ] ,
V_53 -> V_70 [ V_15 ] ) ) ;
}
static T_4
F_68 ( struct V_18 * V_19 , struct V_147 * V_43 , char * V_148 )
{
struct V_52 * V_53 = F_48 ( V_19 ) ;
struct V_26 * V_149 = F_57 ( V_43 ) ;
int V_15 = V_149 -> V_48 ;
return sprintf ( V_148 , L_3 , F_19 ( V_53 -> V_70 [ V_15 ] ) ) ;
}
static T_4
F_69 ( struct V_18 * V_19 , struct V_147 * V_43 ,
const char * V_148 , T_5 V_35 )
{
struct V_52 * V_53 = F_44 ( V_19 ) ;
struct V_26 * V_149 = F_57 ( V_43 ) ;
int V_15 = V_149 -> V_48 ;
unsigned long V_3 ;
unsigned int V_2 ;
T_1 V_166 ;
int V_150 ;
V_150 = F_55 ( V_148 , 10 , & V_3 ) ;
if ( V_150 < 0 )
return V_150 ;
F_49 ( & V_53 -> V_114 ) ;
if ( ! V_53 -> V_73 ) {
if ( ! V_3 ) {
V_3 = 0xff1f ;
} else {
if ( V_3 > 1350000U )
V_3 = 135000U ;
V_3 = 1350000U / V_3 ;
V_3 = ( V_3 & 0x1f ) | ( ( V_3 << 3 ) & 0xff00 ) ;
}
V_53 -> V_74 [ V_15 ] = V_3 ;
goto V_167;
}
if ( ! V_3 ) {
V_53 -> V_74 [ V_15 ] = 255 ;
V_166 = V_53 -> V_70 [ V_15 ] ;
F_70 ( V_19 , L_5 , V_15 + 1 ) ;
goto V_168;
}
V_2 = 1350000U / V_3 ;
if ( V_2 >= 128 * 255 ) {
V_53 -> V_74 [ V_15 ] = 254 ;
V_166 = 7 ;
F_71 ( V_19 ,
L_6 ,
V_15 + 1 , V_3 , V_53 -> V_165 ( 254 , 7 ) ) ;
} else if ( ! V_2 ) {
V_53 -> V_74 [ V_15 ] = 1 ;
V_166 = 0 ;
F_71 ( V_19 ,
L_7 ,
V_15 + 1 , V_3 , V_53 -> V_165 ( 1 , 0 ) ) ;
} else {
V_166 = 0 ;
while ( V_2 > 192 && V_166 < 7 ) {
V_2 >>= 1 ;
V_166 ++ ;
}
V_53 -> V_74 [ V_15 ] = V_2 ;
}
V_168:
if ( V_166 != V_53 -> V_70 [ V_15 ] ) {
F_42 ( V_19 , L_8 ,
V_15 + 1 , F_19 ( V_53 -> V_70 [ V_15 ] ) ,
F_19 ( V_166 ) ) ;
V_53 -> V_70 [ V_15 ] = V_166 ;
F_35 ( V_53 , V_15 ) ;
V_53 -> V_116 = V_115 ;
}
V_167:
F_31 ( V_53 , V_53 -> V_76 [ V_15 ] , V_53 -> V_74 [ V_15 ] ) ;
F_51 ( & V_53 -> V_114 ) ;
return V_35 ;
}
static T_4
F_72 ( struct V_18 * V_19 , struct V_147 * V_43 , char * V_148 )
{
struct V_52 * V_53 = F_48 ( V_19 ) ;
struct V_26 * V_149 = F_57 ( V_43 ) ;
int V_169 = V_53 -> V_127 [ V_149 -> V_48 ] ;
return sprintf ( V_148 , L_4 , V_169 ? : 4 ) ;
}
static T_4
F_73 ( struct V_18 * V_19 , struct V_147 * V_43 ,
const char * V_148 , T_5 V_35 )
{
struct V_52 * V_53 = F_44 ( V_19 ) ;
struct V_26 * V_149 = F_57 ( V_43 ) ;
int V_15 = V_149 -> V_48 ;
unsigned long V_3 ;
int V_150 ;
T_1 V_2 ;
V_150 = F_55 ( V_148 , 10 , & V_3 ) ;
if ( V_150 < 0 )
return V_150 ;
if ( V_3 > 4 )
return - V_36 ;
F_49 ( & V_53 -> V_114 ) ;
V_53 -> V_127 [ V_15 ] = V_3 & 3 ;
V_2 = F_29 ( V_53 , V_53 -> V_128 [ V_15 ] ) ;
V_2 &= ~ ( 0x03 << V_53 -> V_129 [ V_15 ] ) ;
V_2 |= ( V_3 & 3 ) << V_53 -> V_129 [ V_15 ] ;
F_31 ( V_53 , V_53 -> V_128 [ V_15 ] , V_2 ) ;
F_51 ( & V_53 -> V_114 ) ;
return V_35 ;
}
static T_6 F_74 ( struct V_163 * V_164 ,
struct V_30 * V_43 , int V_48 )
{
struct V_18 * V_19 = F_65 ( V_164 , struct V_18 , V_164 ) ;
struct V_52 * V_53 = F_44 ( V_19 ) ;
int V_14 = V_48 / 6 ;
int V_15 = V_48 % 6 ;
if ( ! ( V_53 -> V_72 & ( 1 << V_14 ) ) )
return 0 ;
if ( V_15 == 1 && V_53 -> V_151 [ V_170 + V_14 ] == - 1 )
return 0 ;
if ( V_15 == 2 && V_53 -> V_160 [ V_170 + V_14 ] == - 1 )
return 0 ;
if ( V_15 == 4 && ! ( V_53 -> V_75 & ( 1 << V_14 ) ) )
return 0 ;
if ( V_15 == 5 && V_53 -> V_54 != V_56 )
return 0 ;
return V_43 -> V_10 ;
}
static T_4
F_75 ( struct V_18 * V_19 , struct V_147 * V_43 , char * V_148 )
{
struct V_52 * V_53 = F_48 ( V_19 ) ;
struct V_26 * V_149 = F_57 ( V_43 ) ;
int V_15 = V_149 -> V_48 ;
return sprintf ( V_148 , L_9 , V_53 -> V_171 [ V_53 -> V_153 [ V_15 ] ] ) ;
}
static T_4
F_76 ( struct V_18 * V_19 , struct V_147 * V_43 , char * V_148 )
{
struct V_52 * V_53 = F_48 ( V_19 ) ;
struct V_28 * V_149 = F_53 ( V_43 ) ;
int V_15 = V_149 -> V_15 ;
int V_48 = V_149 -> V_48 ;
return sprintf ( V_148 , L_4 , F_77 ( V_53 -> V_133 [ V_48 ] [ V_15 ] ) ) ;
}
static T_4
F_78 ( struct V_18 * V_19 , struct V_147 * V_43 , const char * V_148 ,
T_5 V_35 )
{
struct V_52 * V_53 = F_44 ( V_19 ) ;
struct V_28 * V_149 = F_53 ( V_43 ) ;
int V_15 = V_149 -> V_15 ;
int V_48 = V_149 -> V_48 ;
int V_150 ;
long V_3 ;
V_150 = F_79 ( V_148 , 10 , & V_3 ) ;
if ( V_150 < 0 )
return V_150 ;
F_49 ( & V_53 -> V_114 ) ;
V_53 -> V_133 [ V_48 ] [ V_15 ] = F_80 ( V_3 ) ;
F_33 ( V_53 , V_53 -> V_132 [ V_48 ] [ V_15 ] ,
V_53 -> V_133 [ V_48 ] [ V_15 ] ) ;
F_51 ( & V_53 -> V_114 ) ;
return V_35 ;
}
static T_4
F_81 ( struct V_18 * V_19 , struct V_147 * V_43 , char * V_148 )
{
struct V_52 * V_53 = F_48 ( V_19 ) ;
struct V_26 * V_149 = F_57 ( V_43 ) ;
return sprintf ( V_148 , L_4 , V_53 -> V_136 [ V_149 -> V_48 ] * 1000 ) ;
}
static T_4
F_82 ( struct V_18 * V_19 , struct V_147 * V_43 ,
const char * V_148 , T_5 V_35 )
{
struct V_52 * V_53 = F_44 ( V_19 ) ;
struct V_26 * V_149 = F_57 ( V_43 ) ;
int V_15 = V_149 -> V_48 ;
long V_3 ;
int V_150 ;
V_150 = F_79 ( V_148 , 10 , & V_3 ) ;
if ( V_150 < 0 )
return V_150 ;
V_3 = F_14 ( F_21 ( V_3 , 1000 ) , - 128 , 127 ) ;
F_49 ( & V_53 -> V_114 ) ;
V_53 -> V_136 [ V_15 ] = V_3 ;
F_31 ( V_53 , V_53 -> V_137 [ V_15 ] , V_3 ) ;
F_51 ( & V_53 -> V_114 ) ;
return V_35 ;
}
static T_4
F_83 ( struct V_18 * V_19 , struct V_147 * V_43 , char * V_148 )
{
struct V_52 * V_53 = F_48 ( V_19 ) ;
struct V_26 * V_149 = F_57 ( V_43 ) ;
int V_15 = V_149 -> V_48 ;
return sprintf ( V_148 , L_4 , ( int ) V_53 -> V_172 [ V_15 ] ) ;
}
static T_4
F_84 ( struct V_18 * V_19 , struct V_147 * V_43 ,
const char * V_148 , T_5 V_35 )
{
struct V_52 * V_53 = F_48 ( V_19 ) ;
struct V_26 * V_149 = F_57 ( V_43 ) ;
int V_15 = V_149 -> V_48 ;
unsigned long V_3 ;
int V_150 ;
T_1 V_173 , V_174 , V_175 , V_176 ;
V_150 = F_55 ( V_148 , 10 , & V_3 ) ;
if ( V_150 < 0 )
return V_150 ;
if ( V_3 != 1 && V_3 != 3 && V_3 != 4 )
return - V_36 ;
F_49 ( & V_53 -> V_114 ) ;
V_53 -> V_172 [ V_15 ] = V_3 ;
V_175 = 0x02 << V_15 ;
V_176 = V_53 -> V_177 << V_15 ;
V_173 = F_29 ( V_53 , V_53 -> V_178 ) & ~ V_175 ;
V_174 = F_29 ( V_53 , V_53 -> V_179 ) & ~ V_176 ;
switch ( V_3 ) {
case 1 :
V_173 |= V_175 ;
V_174 |= V_176 ;
break;
case 3 :
V_173 |= V_176 ;
break;
case 4 :
break;
}
F_31 ( V_53 , V_53 -> V_178 , V_173 ) ;
F_31 ( V_53 , V_53 -> V_179 , V_174 ) ;
F_51 ( & V_53 -> V_114 ) ;
return V_35 ;
}
static T_6 F_85 ( struct V_163 * V_164 ,
struct V_30 * V_43 , int V_48 )
{
struct V_18 * V_19 = F_65 ( V_164 , struct V_18 , V_164 ) ;
struct V_52 * V_53 = F_44 ( V_19 ) ;
int V_133 = V_48 / 10 ;
int V_15 = V_48 % 10 ;
if ( ! ( V_53 -> V_131 & ( 1 << V_133 ) ) )
return 0 ;
if ( V_15 == 2 && F_58 ( V_53 , V_133 , V_53 -> V_157 ) < 0 )
return 0 ;
if ( V_15 == 3 && F_58 ( V_53 , V_133 , V_53 -> V_162 ) < 0 )
return 0 ;
if ( V_15 == 4 && ! V_53 -> V_132 [ 1 ] [ V_133 ] )
return 0 ;
if ( V_15 == 5 && ! V_53 -> V_132 [ 2 ] [ V_133 ] )
return 0 ;
if ( V_15 == 6 && ! V_53 -> V_132 [ 3 ] [ V_133 ] )
return 0 ;
if ( V_15 == 7 && ! V_53 -> V_132 [ 4 ] [ V_133 ] )
return 0 ;
if ( V_15 > 7 && ! ( V_53 -> V_135 & ( 1 << V_133 ) ) )
return 0 ;
return V_43 -> V_10 ;
}
static T_4
F_86 ( struct V_18 * V_19 , struct V_147 * V_43 , char * V_148 )
{
struct V_52 * V_53 = F_48 ( V_19 ) ;
struct V_26 * V_149 = F_57 ( V_43 ) ;
return sprintf ( V_148 , L_4 , ! V_53 -> V_84 [ V_149 -> V_48 ] ) ;
}
static T_4
F_87 ( struct V_18 * V_19 , struct V_147 * V_43 ,
const char * V_148 , T_5 V_35 )
{
struct V_52 * V_53 = F_44 ( V_19 ) ;
struct V_26 * V_149 = F_57 ( V_43 ) ;
int V_15 = V_149 -> V_48 ;
unsigned long V_3 ;
int V_150 ;
T_1 V_2 ;
V_150 = F_55 ( V_148 , 10 , & V_3 ) ;
if ( V_150 < 0 )
return V_150 ;
if ( V_3 > 1 )
return - V_36 ;
if ( V_53 -> V_82 [ V_15 ] == 0 ) {
if ( V_3 )
return - V_36 ;
return V_35 ;
}
F_49 ( & V_53 -> V_114 ) ;
V_53 -> V_84 [ V_15 ] = V_3 ;
V_2 = F_29 ( V_53 , V_53 -> V_82 [ V_15 ] ) ;
V_2 &= ~ V_53 -> V_83 [ V_15 ] ;
if ( V_3 )
V_2 |= V_53 -> V_83 [ V_15 ] ;
F_31 ( V_53 , V_53 -> V_82 [ V_15 ] , V_2 ) ;
F_51 ( & V_53 -> V_114 ) ;
return V_35 ;
}
static T_4
F_88 ( struct V_18 * V_19 , struct V_147 * V_43 , char * V_148 )
{
struct V_52 * V_53 = F_48 ( V_19 ) ;
struct V_28 * V_149 = F_53 ( V_43 ) ;
int V_15 = V_149 -> V_15 ;
int V_48 = V_149 -> V_48 ;
int V_9 ;
if ( V_48 == 0 && V_53 -> V_8 [ V_15 ] > V_180 )
V_9 = F_29 ( V_53 , V_53 -> V_181 [ V_15 ] ) ;
else
V_9 = V_53 -> V_9 [ V_48 ] [ V_15 ] ;
return sprintf ( V_148 , L_4 , V_9 ) ;
}
static T_4
F_89 ( struct V_18 * V_19 , struct V_147 * V_43 , const char * V_148 ,
T_5 V_35 )
{
struct V_52 * V_53 = F_44 ( V_19 ) ;
struct V_28 * V_149 = F_53 ( V_43 ) ;
int V_15 = V_149 -> V_15 ;
int V_48 = V_149 -> V_48 ;
unsigned long V_3 ;
int V_182 [ 7 ] = { 0 , 1 , 1 , V_53 -> V_9 [ 2 ] [ V_15 ] , 0 , 0 , 0 } ;
int V_183 [ 7 ]
= { 255 , 255 , V_53 -> V_9 [ 3 ] [ V_15 ] ? : 255 , 255 , 255 , 255 , 255 } ;
int V_150 ;
T_1 V_2 ;
V_150 = F_55 ( V_148 , 10 , & V_3 ) ;
if ( V_150 < 0 )
return V_150 ;
V_3 = F_14 ( V_3 , V_182 [ V_48 ] , V_183 [ V_48 ] ) ;
F_49 ( & V_53 -> V_114 ) ;
V_53 -> V_9 [ V_48 ] [ V_15 ] = V_3 ;
F_31 ( V_53 , V_53 -> V_86 [ V_48 ] [ V_15 ] , V_3 ) ;
if ( V_48 == 2 ) {
V_2 = F_29 ( V_53 , V_53 -> V_92 [ V_15 ] ) ;
V_2 &= 0x7f ;
if ( V_3 )
V_2 |= 0x80 ;
F_31 ( V_53 , V_53 -> V_92 [ V_15 ] , V_2 ) ;
}
F_51 ( & V_53 -> V_114 ) ;
return V_35 ;
}
static int F_90 ( struct V_52 * V_53 , int V_15 )
{
int V_34 ;
for ( V_34 = 0 ; V_34 < V_53 -> V_106 - 1 ; V_34 ++ ) {
if ( V_53 -> V_108 [ V_15 ] [ V_34 ] > V_53 -> V_108 [ V_15 ] [ V_34 + 1 ] )
return - V_36 ;
}
for ( V_34 = 0 ; V_34 < V_53 -> V_106 - 1 ; V_34 ++ ) {
if ( V_53 -> V_107 [ V_15 ] [ V_34 ] > V_53 -> V_107 [ V_15 ] [ V_34 + 1 ] )
return - V_36 ;
}
if ( V_53 -> V_107 [ V_15 ] [ V_53 -> V_106 ] ) {
if ( V_53 -> V_108 [ V_15 ] [ V_53 -> V_106 - 1 ] >
V_53 -> V_108 [ V_15 ] [ V_53 -> V_106 ] ||
V_53 -> V_107 [ V_15 ] [ V_53 -> V_106 - 1 ] >
V_53 -> V_107 [ V_15 ] [ V_53 -> V_106 ] )
return - V_36 ;
}
return 0 ;
}
static void F_91 ( struct V_52 * V_53 , int V_15 )
{
T_1 V_2 ;
switch ( V_53 -> V_8 [ V_15 ] ) {
case V_11 :
case V_180 :
break;
case V_88 :
V_2 = F_29 ( V_53 , V_53 -> V_85 [ V_15 ] ) ;
V_2 = ( V_2 & ~ V_53 -> V_184 ) |
( V_53 -> V_89 [ V_15 ] & V_53 -> V_184 ) ;
F_31 ( V_53 , V_53 -> V_85 [ V_15 ] , V_2 ) ;
F_31 ( V_53 , V_53 -> V_101 [ V_15 ] ,
V_53 -> V_105 [ V_15 ] & 0xff ) ;
if ( V_53 -> V_90 ) {
V_2 = ( V_53 -> V_105 [ V_15 ] >> 8 ) & 0x0f ;
V_2 |= ( V_53 -> V_89 [ V_15 ] & 0x38 ) << 1 ;
F_31 ( V_53 ,
V_53 -> V_90 [ V_15 ] ,
V_2 ) ;
}
break;
case V_103 :
F_31 ( V_53 , V_53 -> V_101 [ V_15 ] ,
V_53 -> V_102 [ V_15 ] ) ;
default:
V_2 = F_29 ( V_53 , V_53 -> V_85 [ V_15 ] ) ;
V_2 = ( V_2 & ~ V_53 -> V_184 ) |
V_53 -> V_87 [ 0 ] [ V_15 ] ;
F_31 ( V_53 , V_53 -> V_85 [ V_15 ] , V_2 ) ;
break;
}
}
static T_4
F_92 ( struct V_18 * V_19 , struct V_147 * V_43 , char * V_148 )
{
struct V_52 * V_53 = F_48 ( V_19 ) ;
struct V_26 * V_149 = F_57 ( V_43 ) ;
return sprintf ( V_148 , L_4 , V_53 -> V_8 [ V_149 -> V_48 ] ) ;
}
static T_4
F_93 ( struct V_18 * V_19 , struct V_147 * V_43 ,
const char * V_148 , T_5 V_35 )
{
struct V_52 * V_53 = F_44 ( V_19 ) ;
struct V_26 * V_149 = F_57 ( V_43 ) ;
int V_15 = V_149 -> V_48 ;
unsigned long V_3 ;
int V_150 ;
T_2 V_2 ;
V_150 = F_55 ( V_148 , 10 , & V_3 ) ;
if ( V_150 < 0 )
return V_150 ;
if ( V_3 > V_185 )
return - V_36 ;
if ( V_3 == V_186 && V_53 -> V_54 != V_56 )
return - V_36 ;
if ( V_3 == V_185 && F_90 ( V_53 , V_15 ) ) {
F_94 ( V_19 , L_10 ) ;
F_94 ( V_19 , L_11 ) ;
return - V_36 ;
}
F_49 ( & V_53 -> V_114 ) ;
V_53 -> V_8 [ V_15 ] = V_3 ;
if ( V_3 == V_11 ) {
V_53 -> V_9 [ 0 ] [ V_15 ] = 255 ;
F_31 ( V_53 , V_53 -> V_86 [ 0 ] [ V_15 ] , 255 ) ;
}
F_91 ( V_53 , V_15 ) ;
V_2 = F_29 ( V_53 , V_53 -> V_85 [ V_15 ] ) ;
V_2 &= 0x0f ;
V_2 |= F_11 ( V_3 ) << 4 ;
F_31 ( V_53 , V_53 -> V_85 [ V_15 ] , V_2 ) ;
F_51 ( & V_53 -> V_114 ) ;
return V_35 ;
}
static T_4
F_95 ( struct V_52 * V_53 , char * V_148 , int V_154 )
{
int V_34 , V_187 = 0 ;
for ( V_34 = 0 ; V_34 < V_130 ; V_34 ++ ) {
if ( ! ( V_53 -> V_131 & ( 1 << V_34 ) ) )
continue;
if ( V_154 == V_53 -> V_153 [ V_34 ] ) {
V_187 = V_34 + 1 ;
break;
}
}
return sprintf ( V_148 , L_4 , V_187 ) ;
}
static T_4
F_96 ( struct V_18 * V_19 , struct V_147 * V_43 , char * V_148 )
{
struct V_52 * V_53 = F_48 ( V_19 ) ;
struct V_26 * V_149 = F_57 ( V_43 ) ;
int V_48 = V_149 -> V_48 ;
return F_95 ( V_53 , V_148 , V_53 -> V_93 [ V_48 ] ) ;
}
static T_4
F_97 ( struct V_18 * V_19 , struct V_147 * V_43 ,
const char * V_148 , T_5 V_35 )
{
struct V_52 * V_53 = F_48 ( V_19 ) ;
struct V_26 * V_149 = F_57 ( V_43 ) ;
int V_15 = V_149 -> V_48 ;
unsigned long V_3 ;
int V_150 , V_2 , V_154 ;
V_150 = F_55 ( V_148 , 10 , & V_3 ) ;
if ( V_150 < 0 )
return V_150 ;
if ( V_3 == 0 || V_3 > V_130 )
return - V_36 ;
if ( ! ( V_53 -> V_131 & ( 1 << ( V_3 - 1 ) ) ) || ! V_53 -> V_153 [ V_3 - 1 ] )
return - V_36 ;
F_49 ( & V_53 -> V_114 ) ;
V_154 = V_53 -> V_153 [ V_3 - 1 ] ;
V_53 -> V_93 [ V_15 ] = V_154 ;
V_2 = F_29 ( V_53 , V_53 -> V_92 [ V_15 ] ) ;
V_2 &= 0xe0 ;
V_2 |= V_154 ;
F_31 ( V_53 , V_53 -> V_92 [ V_15 ] , V_2 ) ;
F_51 ( & V_53 -> V_114 ) ;
return V_35 ;
}
static T_4
F_98 ( struct V_18 * V_19 , struct V_147 * V_43 ,
char * V_148 )
{
struct V_52 * V_53 = F_48 ( V_19 ) ;
struct V_26 * V_149 = F_57 ( V_43 ) ;
int V_48 = V_149 -> V_48 ;
return F_95 ( V_53 , V_148 ,
V_53 -> V_95 [ V_48 ] ) ;
}
static T_4
F_99 ( struct V_18 * V_19 , struct V_147 * V_43 ,
const char * V_148 , T_5 V_35 )
{
struct V_52 * V_53 = F_48 ( V_19 ) ;
struct V_26 * V_149 = F_57 ( V_43 ) ;
int V_15 = V_149 -> V_48 ;
unsigned long V_3 ;
int V_150 , V_2 , V_154 ;
V_150 = F_55 ( V_148 , 10 , & V_3 ) ;
if ( V_150 < 0 )
return V_150 ;
if ( V_3 > V_130 )
return - V_36 ;
if ( V_3 && ( ! ( V_53 -> V_131 & ( 1 << ( V_3 - 1 ) ) ) ||
! V_53 -> V_153 [ V_3 - 1 ] ) )
return - V_36 ;
F_49 ( & V_53 -> V_114 ) ;
if ( V_3 ) {
V_154 = V_53 -> V_153 [ V_3 - 1 ] ;
V_53 -> V_95 [ V_15 ] = V_154 ;
V_2 = F_29 ( V_53 , V_53 -> V_94 [ V_15 ] ) ;
V_2 &= 0xe0 ;
V_2 |= ( V_154 | 0x80 ) ;
F_31 ( V_53 , V_53 -> V_94 [ V_15 ] , V_2 ) ;
} else {
V_53 -> V_95 [ V_15 ] = 0 ;
V_2 = F_29 ( V_53 , V_53 -> V_94 [ V_15 ] ) ;
V_2 &= 0x7f ;
F_31 ( V_53 , V_53 -> V_94 [ V_15 ] , V_2 ) ;
}
F_51 ( & V_53 -> V_114 ) ;
return V_35 ;
}
static T_4
F_100 ( struct V_18 * V_19 , struct V_147 * V_43 , char * V_148 )
{
struct V_52 * V_53 = F_48 ( V_19 ) ;
struct V_26 * V_149 = F_57 ( V_43 ) ;
return sprintf ( V_148 , L_4 , V_53 -> V_102 [ V_149 -> V_48 ] * 1000 ) ;
}
static T_4
F_101 ( struct V_18 * V_19 , struct V_147 * V_43 ,
const char * V_148 , T_5 V_35 )
{
struct V_52 * V_53 = F_44 ( V_19 ) ;
struct V_26 * V_149 = F_57 ( V_43 ) ;
int V_15 = V_149 -> V_48 ;
unsigned long V_3 ;
int V_150 ;
V_150 = F_55 ( V_148 , 10 , & V_3 ) ;
if ( V_150 < 0 )
return V_150 ;
V_3 = F_14 ( F_21 ( V_3 , 1000 ) , 0 ,
V_53 -> V_104 ) ;
F_49 ( & V_53 -> V_114 ) ;
V_53 -> V_102 [ V_15 ] = V_3 ;
F_91 ( V_53 , V_15 ) ;
F_51 ( & V_53 -> V_114 ) ;
return V_35 ;
}
static T_4
F_102 ( struct V_18 * V_19 , struct V_147 * V_43 , char * V_148 )
{
struct V_52 * V_53 = F_48 ( V_19 ) ;
struct V_26 * V_149 = F_57 ( V_43 ) ;
int V_15 = V_149 -> V_48 ;
return sprintf ( V_148 , L_4 ,
F_17 ( V_53 -> V_105 [ V_15 ] ,
V_53 -> V_70 [ V_15 ] ) ) ;
}
static T_4
F_103 ( struct V_18 * V_19 , struct V_147 * V_43 ,
const char * V_148 , T_5 V_35 )
{
struct V_52 * V_53 = F_44 ( V_19 ) ;
struct V_26 * V_149 = F_57 ( V_43 ) ;
int V_15 = V_149 -> V_48 ;
unsigned long V_3 ;
int V_150 ;
T_2 V_188 ;
V_150 = F_55 ( V_148 , 10 , & V_3 ) ;
if ( V_150 < 0 )
return V_150 ;
V_3 = F_14 ( V_3 , 0 , 1350000U ) ;
V_188 = F_18 ( V_3 , V_53 -> V_70 [ V_15 ] ) ;
F_49 ( & V_53 -> V_114 ) ;
V_53 -> V_105 [ V_15 ] = V_188 ;
F_91 ( V_53 , V_15 ) ;
F_51 ( & V_53 -> V_114 ) ;
return V_35 ;
}
static T_4
F_104 ( struct V_18 * V_19 , struct V_147 * V_43 ,
char * V_148 )
{
struct V_52 * V_53 = F_48 ( V_19 ) ;
struct V_28 * V_149 = F_53 ( V_43 ) ;
int V_15 = V_149 -> V_15 ;
int V_48 = V_149 -> V_48 ;
return sprintf ( V_148 , L_4 , V_53 -> V_87 [ V_48 ] [ V_15 ] * 1000 ) ;
}
static T_4
F_105 ( struct V_18 * V_19 , struct V_147 * V_43 ,
const char * V_148 , T_5 V_35 )
{
struct V_52 * V_53 = F_44 ( V_19 ) ;
struct V_28 * V_149 = F_53 ( V_43 ) ;
int V_15 = V_149 -> V_15 ;
int V_48 = V_149 -> V_48 ;
unsigned long V_3 ;
int V_150 ;
V_150 = F_55 ( V_148 , 10 , & V_3 ) ;
if ( V_150 < 0 )
return V_150 ;
V_3 = F_14 ( F_21 ( V_3 , 1000 ) , 0 , V_53 -> V_184 ) ;
F_49 ( & V_53 -> V_114 ) ;
V_53 -> V_87 [ V_48 ] [ V_15 ] = V_3 ;
if ( V_48 )
F_91 ( V_53 , V_15 ) ;
else
F_31 ( V_53 ,
V_53 -> V_91 [ V_15 ] ,
V_3 ) ;
F_51 ( & V_53 -> V_114 ) ;
return V_35 ;
}
static T_4
F_106 ( struct V_18 * V_19 , struct V_147 * V_43 ,
char * V_148 )
{
struct V_52 * V_53 = F_48 ( V_19 ) ;
struct V_26 * V_149 = F_57 ( V_43 ) ;
int V_15 = V_149 -> V_48 ;
int V_189 = V_53 -> V_105 [ V_15 ] - V_53 -> V_89 [ V_15 ] ;
int V_190 = V_53 -> V_105 [ V_15 ] + V_53 -> V_89 [ V_15 ] ;
int V_191 ;
if ( V_189 <= 0 )
V_189 = 1 ;
if ( V_190 > 0xffff )
V_190 = 0xffff ;
if ( V_190 < V_189 )
V_190 = V_189 ;
V_191 = ( F_17 ( V_189 , V_53 -> V_70 [ V_15 ] )
- F_17 ( V_190 , V_53 -> V_70 [ V_15 ] ) ) / 2 ;
return sprintf ( V_148 , L_4 , V_191 ) ;
}
static T_4
F_107 ( struct V_18 * V_19 , struct V_147 * V_43 ,
const char * V_148 , T_5 V_35 )
{
struct V_52 * V_53 = F_44 ( V_19 ) ;
struct V_26 * V_149 = F_57 ( V_43 ) ;
int V_15 = V_149 -> V_48 ;
unsigned long V_3 ;
int V_150 ;
int V_189 , V_190 ;
V_150 = F_55 ( V_148 , 10 , & V_3 ) ;
if ( V_150 < 0 )
return V_150 ;
V_190 = F_17 ( V_53 -> V_105 [ V_15 ] ,
V_53 -> V_70 [ V_15 ] ) + V_3 ;
V_189 = F_17 ( V_53 -> V_105 [ V_15 ] ,
V_53 -> V_70 [ V_15 ] ) - V_3 ;
if ( V_189 <= 0 )
V_189 = 1 ;
if ( V_190 < V_189 )
V_190 = V_189 ;
V_3 = ( F_18 ( V_189 , V_53 -> V_70 [ V_15 ] ) -
F_18 ( V_190 , V_53 -> V_70 [ V_15 ] ) ) / 2 ;
V_3 = F_14 ( V_3 , 0 , V_53 -> V_192 ) ;
F_49 ( & V_53 -> V_114 ) ;
V_53 -> V_89 [ V_15 ] = V_3 ;
F_91 ( V_53 , V_15 ) ;
F_51 ( & V_53 -> V_114 ) ;
return V_35 ;
}
static T_4
F_108 ( struct V_18 * V_19 , struct V_147 * V_43 , char * V_148 )
{
struct V_52 * V_53 = F_48 ( V_19 ) ;
struct V_28 * V_149 = F_53 ( V_43 ) ;
int V_15 = V_149 -> V_15 ;
int V_48 = V_149 -> V_48 ;
return sprintf ( V_148 , L_4 , V_53 -> V_96 [ V_48 ] [ V_15 ] * 1000 ) ;
}
static T_4
F_109 ( struct V_18 * V_19 , struct V_147 * V_43 ,
const char * V_148 , T_5 V_35 )
{
struct V_52 * V_53 = F_44 ( V_19 ) ;
struct V_28 * V_149 = F_53 ( V_43 ) ;
int V_15 = V_149 -> V_15 ;
int V_48 = V_149 -> V_48 ;
unsigned long V_3 ;
int V_150 ;
V_150 = F_55 ( V_148 , 10 , & V_3 ) ;
if ( V_150 < 0 )
return V_150 ;
V_3 = F_14 ( F_21 ( V_3 , 1000 ) , 0 , 255 ) ;
F_49 ( & V_53 -> V_114 ) ;
V_53 -> V_96 [ V_48 ] [ V_15 ] = V_3 ;
F_31 ( V_53 , V_53 -> V_97 [ V_48 ] [ V_15 ] , V_3 ) ;
F_51 ( & V_53 -> V_114 ) ;
return V_35 ;
}
static T_4
F_110 ( struct V_18 * V_19 , struct V_147 * V_43 , char * V_148 )
{
struct V_52 * V_53 = F_48 ( V_19 ) ;
struct V_28 * V_149 = F_53 ( V_43 ) ;
int V_15 = V_149 -> V_15 ;
int V_48 = V_149 -> V_48 ;
return sprintf ( V_148 , L_4 ,
F_12 ( V_53 -> V_99 [ V_48 ] [ V_15 ] ,
V_53 -> V_84 [ V_15 ] ) ) ;
}
static T_4
F_111 ( struct V_18 * V_19 , struct V_147 * V_43 ,
const char * V_148 , T_5 V_35 )
{
struct V_52 * V_53 = F_44 ( V_19 ) ;
struct V_28 * V_149 = F_53 ( V_43 ) ;
int V_15 = V_149 -> V_15 ;
int V_48 = V_149 -> V_48 ;
unsigned long V_3 ;
int V_150 ;
V_150 = F_55 ( V_148 , 10 , & V_3 ) ;
if ( V_150 < 0 )
return V_150 ;
V_3 = F_13 ( V_3 , V_53 -> V_84 [ V_15 ] ) ;
F_49 ( & V_53 -> V_114 ) ;
V_53 -> V_99 [ V_48 ] [ V_15 ] = V_3 ;
F_31 ( V_53 , V_53 -> V_100 [ V_48 ] [ V_15 ] , V_3 ) ;
F_51 ( & V_53 -> V_114 ) ;
return V_35 ;
}
static T_4
F_112 ( struct V_18 * V_19 , struct V_147 * V_43 , char * V_148 )
{
struct V_52 * V_53 = F_48 ( V_19 ) ;
struct V_28 * V_149 = F_53 ( V_43 ) ;
return sprintf ( V_148 , L_4 , V_53 -> V_107 [ V_149 -> V_15 ] [ V_149 -> V_48 ] ) ;
}
static T_4
F_113 ( struct V_18 * V_19 , struct V_147 * V_43 ,
const char * V_148 , T_5 V_35 )
{
struct V_52 * V_53 = F_44 ( V_19 ) ;
struct V_28 * V_149 = F_53 ( V_43 ) ;
int V_15 = V_149 -> V_15 ;
int V_193 = V_149 -> V_48 ;
unsigned long V_3 ;
int V_150 ;
T_1 V_2 ;
V_150 = F_55 ( V_148 , 10 , & V_3 ) ;
if ( V_150 < 0 )
return V_150 ;
if ( V_3 > 255 )
return - V_36 ;
if ( V_193 == V_53 -> V_106 ) {
if ( V_53 -> V_54 != V_56 && ! V_3 )
return - V_36 ;
if ( V_53 -> V_54 != V_58 && V_3 )
V_3 = 0xff ;
}
F_49 ( & V_53 -> V_114 ) ;
V_53 -> V_107 [ V_15 ] [ V_193 ] = V_3 ;
if ( V_193 < V_53 -> V_106 ) {
F_31 ( V_53 ,
F_46 ( V_53 , V_15 , V_193 ) ,
V_53 -> V_107 [ V_15 ] [ V_193 ] ) ;
} else {
switch ( V_53 -> V_54 ) {
case V_56 :
V_2 = F_29 ( V_53 ,
V_110 [ V_15 ] ) ;
if ( V_3 )
V_2 |= 0x02 ;
else
V_2 &= ~ 0x02 ;
F_31 ( V_53 , V_110 [ V_15 ] ,
V_2 ) ;
break;
case V_57 :
break;
case V_55 :
case V_58 :
case V_59 :
case V_60 :
F_31 ( V_53 , V_53 -> V_113 [ V_15 ] ,
V_3 ) ;
V_2 = F_29 ( V_53 ,
V_53 -> V_111 [ V_15 ] ) ;
if ( V_3 == 255 )
V_2 &= ~ V_53 -> V_112 ;
else
V_2 |= V_53 -> V_112 ;
F_31 ( V_53 ,
V_53 -> V_111 [ V_15 ] ,
V_2 ) ;
break;
}
}
F_51 ( & V_53 -> V_114 ) ;
return V_35 ;
}
static T_4
F_114 ( struct V_18 * V_19 , struct V_147 * V_43 , char * V_148 )
{
struct V_52 * V_53 = F_48 ( V_19 ) ;
struct V_28 * V_149 = F_53 ( V_43 ) ;
int V_15 = V_149 -> V_15 ;
int V_193 = V_149 -> V_48 ;
return sprintf ( V_148 , L_4 , V_53 -> V_108 [ V_15 ] [ V_193 ] * 1000 ) ;
}
static T_4
F_115 ( struct V_18 * V_19 , struct V_147 * V_43 ,
const char * V_148 , T_5 V_35 )
{
struct V_52 * V_53 = F_44 ( V_19 ) ;
struct V_28 * V_149 = F_53 ( V_43 ) ;
int V_15 = V_149 -> V_15 ;
int V_193 = V_149 -> V_48 ;
unsigned long V_3 ;
int V_150 ;
V_150 = F_55 ( V_148 , 10 , & V_3 ) ;
if ( V_150 )
return V_150 ;
if ( V_3 > 255000 )
return - V_36 ;
F_49 ( & V_53 -> V_114 ) ;
V_53 -> V_108 [ V_15 ] [ V_193 ] = F_21 ( V_3 , 1000 ) ;
if ( V_193 < V_53 -> V_106 ) {
F_31 ( V_53 ,
F_47 ( V_53 , V_15 , V_193 ) ,
V_53 -> V_108 [ V_15 ] [ V_193 ] ) ;
} else {
F_31 ( V_53 , V_53 -> V_109 [ V_15 ] ,
V_53 -> V_108 [ V_15 ] [ V_193 ] ) ;
}
F_51 ( & V_53 -> V_114 ) ;
return V_35 ;
}
static T_6 F_116 ( struct V_163 * V_164 ,
struct V_30 * V_43 , int V_48 )
{
struct V_18 * V_19 = F_65 ( V_164 , struct V_18 , V_164 ) ;
struct V_52 * V_53 = F_44 ( V_19 ) ;
int V_9 = V_48 / 36 ;
int V_15 = V_48 % 36 ;
if ( ! ( V_53 -> V_81 & ( 1 << V_9 ) ) )
return 0 ;
if ( ( V_15 >= 14 && V_15 <= 18 ) || V_15 == 21 )
if ( ! V_53 -> V_94 [ V_9 ] )
return 0 ;
if ( V_15 == 19 && V_53 -> V_86 [ 3 ] == NULL )
return 0 ;
if ( V_15 == 20 && V_53 -> V_86 [ 4 ] == NULL )
return 0 ;
if ( V_15 == 21 && V_53 -> V_86 [ 6 ] == NULL )
return 0 ;
if ( V_15 >= 22 && V_15 <= 35 ) {
int V_194 = ( V_15 - 22 ) / 2 ;
if ( V_194 > V_53 -> V_106 )
return 0 ;
}
return V_43 -> V_10 ;
}
static T_4
F_117 ( struct V_18 * V_19 , struct V_147 * V_43 , char * V_148 )
{
struct V_52 * V_53 = F_44 ( V_19 ) ;
return sprintf ( V_148 , L_4 , F_118 ( V_53 -> V_195 , V_53 -> V_196 ) ) ;
}
static T_4
F_119 ( struct V_18 * V_19 , struct V_147 * V_43 ,
const char * V_148 , T_5 V_35 )
{
struct V_52 * V_53 = F_44 ( V_19 ) ;
int V_15 = F_57 ( V_43 ) -> V_48 - V_197 ;
unsigned long V_3 ;
T_1 V_2 ;
int V_198 ;
if ( F_55 ( V_148 , 10 , & V_3 ) || V_3 != 0 )
return - V_36 ;
F_49 ( & V_53 -> V_114 ) ;
V_198 = F_6 ( V_53 -> V_199 ) ;
if ( V_198 ) {
V_35 = V_198 ;
goto error;
}
F_5 ( V_53 -> V_199 , V_200 ) ;
V_2 = F_3 ( V_53 -> V_199 , V_201 [ V_15 ] ) ;
V_2 |= V_202 [ V_15 ] ;
F_1 ( V_53 -> V_199 , V_201 [ V_15 ] , V_2 ) ;
V_2 &= ~ V_202 [ V_15 ] ;
F_1 ( V_53 -> V_199 , V_201 [ V_15 ] , V_2 ) ;
F_8 ( V_53 -> V_199 ) ;
V_53 -> V_118 = false ;
error:
F_51 ( & V_53 -> V_114 ) ;
return V_35 ;
}
static T_6 F_120 ( struct V_163 * V_164 ,
struct V_30 * V_43 , int V_48 )
{
struct V_18 * V_19 = F_65 ( V_164 , struct V_18 , V_164 ) ;
struct V_52 * V_53 = F_44 ( V_19 ) ;
if ( V_48 == 0 && ! V_53 -> V_203 )
return 0 ;
if ( V_48 == 1 || V_48 == 2 ) {
if ( V_53 -> V_151 [ V_197 + V_48 - 1 ] < 0 )
return 0 ;
}
if ( V_48 == 3 || V_48 == 4 ) {
if ( V_53 -> V_160 [ V_197 + V_48 - 3 ] < 0 )
return 0 ;
}
return V_43 -> V_10 ;
}
static inline void F_121 ( struct V_52 * V_53 )
{
int V_34 ;
T_1 V_204 , V_174 ;
if ( V_53 -> V_205 ) {
V_204 = F_29 ( V_53 , V_53 -> V_205 ) ;
if ( ! ( V_204 & 0x01 ) )
F_31 ( V_53 , V_53 -> V_205 , V_204 | 0x01 ) ;
}
for ( V_34 = 0 ; V_34 < V_130 ; V_34 ++ ) {
if ( ! ( V_53 -> V_131 & ( 1 << V_34 ) ) )
continue;
if ( ! V_53 -> V_206 [ V_34 ] )
continue;
V_204 = F_29 ( V_53 , V_53 -> V_206 [ V_34 ] ) ;
if ( V_204 & 0x01 )
F_31 ( V_53 , V_53 -> V_206 [ V_34 ] ,
V_204 & 0xfe ) ;
}
V_204 = F_29 ( V_53 , V_53 -> V_178 ) ;
if ( ! ( V_204 & 0x01 ) )
F_31 ( V_53 , V_53 -> V_178 , V_204 | 0x01 ) ;
V_174 = F_29 ( V_53 , V_53 -> V_179 ) ;
for ( V_34 = 0 ; V_34 < V_53 -> V_207 ; V_34 ++ ) {
if ( ! ( V_53 -> V_135 & ( 1 << V_34 ) ) )
continue;
if ( ( V_204 & ( V_53 -> V_177 << V_34 ) ) )
V_53 -> V_172 [ V_34 ]
= 3 - ( ( V_174 >> V_34 ) & V_53 -> V_177 ) ;
else
V_53 -> V_172 [ V_34 ] = 4 ;
}
}
static void
F_122 ( struct V_52 * V_53 )
{
bool V_208 , V_209 , V_210 , V_211 , V_212 ;
bool V_213 , V_214 , V_215 , V_216 ;
int V_199 = V_53 -> V_199 ;
int V_217 ;
if ( V_53 -> V_54 == V_56 ) {
V_217 = F_3 ( V_199 , 0x2c ) ;
V_208 = V_217 & ( 1 << 6 ) ;
V_213 = V_217 & ( 1 << 7 ) ;
V_209 = ! ( F_3 ( V_199 , 0x2A ) & 0x80 ) ;
V_210 = false ;
V_211 = false ;
V_212 = false ;
V_214 = false ;
V_215 = false ;
V_216 = false ;
} else if ( V_53 -> V_54 == V_57 ) {
bool V_218 = F_3 ( V_199 , 0x27 ) & 0x80 ;
F_5 ( V_199 , V_219 ) ;
V_217 = F_3 ( V_199 , V_220 ) ;
if ( V_217 & 0x80 )
V_208 = V_218 ;
else
V_208 = ! ( F_3 ( V_199 , 0x24 ) & 0x40 ) ;
if ( V_217 & 0x40 )
V_209 = V_218 ;
else
V_209 = F_3 ( V_199 , 0x1C ) & 0x01 ;
if ( V_217 & 0x20 )
V_211 = V_218 ;
else
V_211 = F_3 ( V_199 , 0x1C ) & 0x02 ;
V_210 = V_209 ;
V_212 = false ;
V_213 = V_208 ;
V_214 = false ;
V_215 = false ;
V_216 = false ;
} else if ( V_53 -> V_54 == V_55 ) {
V_217 = F_3 ( V_199 , 0x24 ) ;
V_208 = ! ( V_217 & 0x80 ) ;
V_213 = V_217 & 0x08 ;
V_209 = false ;
V_210 = false ;
V_211 = false ;
V_212 = false ;
V_214 = false ;
V_215 = false ;
V_216 = false ;
} else {
V_217 = F_3 ( V_199 , 0x1c ) ;
V_208 = ! ( V_217 & ( 1 << 5 ) ) ;
V_209 = ! ( V_217 & ( 1 << 6 ) ) ;
V_211 = ! ( V_217 & ( 1 << 7 ) ) ;
V_213 = ! ( V_217 & ( 1 << 0 ) ) ;
V_214 = ! ( V_217 & ( 1 << 1 ) ) ;
V_215 = ! ( V_217 & ( 1 << 2 ) ) ;
V_210 = V_209 ;
if ( V_53 -> V_54 == V_59 || V_53 -> V_54 == V_60 ) {
V_217 = F_3 ( V_199 , 0x2d ) ;
V_212 = ( V_217 & ( 1 << 1 ) ) ;
V_216 = ( V_217 & ( 1 << 0 ) ) ;
} else {
V_212 = false ;
V_216 = false ;
}
}
V_53 -> V_72 = 0x03 | ( V_208 << 2 ) | ( V_209 << 3 ) |
( V_211 << 4 ) | ( V_212 << 5 ) ;
V_53 -> V_75 = 0x03 | ( V_208 << 2 ) | ( V_210 << 3 ) |
( V_211 << 4 ) ;
V_53 -> V_81 = 0x03 | ( V_213 << 2 ) | ( V_214 << 3 ) |
( V_215 << 4 ) | ( V_216 << 5 ) ;
}
static void F_123 ( struct V_52 * V_53 , const T_2 * V_221 ,
int * V_222 , int * V_223 )
{
int V_34 ;
T_1 V_154 ;
for ( V_34 = 0 ; V_34 < V_53 -> V_80 && * V_222 ; V_34 ++ ) {
int V_48 ;
if ( ! V_221 [ V_34 ] )
continue;
V_154 = F_29 ( V_53 , V_221 [ V_34 ] ) ;
V_154 &= 0x1f ;
if ( ! V_154 || ( * V_223 & ( 1 << V_154 ) ) )
continue;
if ( V_154 >= V_53 -> V_224 ||
! strlen ( V_53 -> V_171 [ V_154 ] ) )
continue;
V_48 = F_124 ( * V_222 ) ;
F_31 ( V_53 , V_53 -> V_155 [ V_48 ] , V_154 ) ;
* V_222 &= ~ ( 1 << V_48 ) ;
* V_223 |= 1 << V_154 ;
}
}
static int F_125 ( struct V_225 * V_226 )
{
struct V_18 * V_19 = & V_226 -> V_19 ;
struct V_227 * V_228 = F_126 ( V_19 ) ;
struct V_52 * V_53 ;
struct V_229 * V_66 ;
int V_34 , V_47 , V_150 = 0 ;
int V_154 , V_223 , V_222 ;
const T_2 * V_132 , * V_230 , * V_231 , * V_206 ;
const T_2 * V_232 , * V_233 , * V_234 ;
const T_2 * V_235 = NULL , * V_236 = NULL ;
int V_237 , V_238 ;
T_1 V_239 ;
struct V_17 * V_23 ;
struct V_18 * V_240 ;
int V_241 = 0 ;
V_66 = F_127 ( V_226 , V_242 , 0 ) ;
if ( ! F_128 ( & V_226 -> V_19 , V_66 -> V_243 , V_244 ,
V_6 ) )
return - V_7 ;
V_53 = F_25 ( & V_226 -> V_19 , sizeof( struct V_52 ) ,
V_38 ) ;
if ( ! V_53 )
return - V_39 ;
V_53 -> V_54 = V_228 -> V_54 ;
V_53 -> V_199 = V_228 -> V_199 ;
V_53 -> V_63 = V_66 -> V_243 ;
F_129 ( & V_53 -> V_114 ) ;
V_53 -> V_41 = V_245 [ V_53 -> V_54 ] ;
V_53 -> V_61 = 0xff ;
F_130 ( V_226 , V_53 ) ;
switch ( V_53 -> V_54 ) {
case V_55 :
V_53 -> V_119 = 9 ;
V_53 -> V_80 = 3 ;
V_53 -> V_106 = 4 ;
V_53 -> V_207 = 3 ;
V_53 -> V_157 = 6 ;
V_53 -> V_162 = 6 ;
V_53 -> V_126 = F_16 ;
V_53 -> V_165 = F_16 ;
V_53 -> V_171 = V_246 ;
V_53 -> V_224 = F_39 ( V_246 ) ;
V_53 -> V_178 = V_247 ;
V_53 -> V_179 = V_248 ;
V_53 -> V_177 = V_249 ;
V_53 -> V_122 = V_250 ;
V_53 -> V_123 [ 0 ] = V_251 ;
V_53 -> V_123 [ 1 ] = V_252 ;
V_53 -> V_101 = V_253 ;
V_53 -> V_125 = V_254 ;
V_53 -> V_85 = V_255 ;
V_53 -> V_76 = V_256 ;
V_53 -> V_128 = V_257 ;
V_53 -> V_129 = V_258 ;
V_53 -> V_100 [ 0 ] = V_259 ;
V_53 -> V_100 [ 1 ] = V_260 ;
V_53 -> V_100 [ 2 ] = V_261 ;
V_53 -> V_86 [ 0 ] = V_262 ;
V_53 -> V_86 [ 1 ] = V_263 ;
V_53 -> V_86 [ 2 ] = V_264 ;
V_53 -> V_86 [ 5 ] = V_265 ;
V_53 -> V_86 [ 6 ] = V_266 ;
V_53 -> V_181 = V_267 ;
V_53 -> V_82 = V_268 ;
V_53 -> V_83 = V_269 ;
V_53 -> V_270 = V_271 ;
V_53 -> V_272 = V_273 ;
V_53 -> V_109 = V_274 ;
V_53 -> V_91
= V_275 ;
V_53 -> V_111 = V_276 ;
V_53 -> V_112
= V_277 ;
V_53 -> V_113 = V_278 ;
V_53 -> V_137 = V_279 ;
V_53 -> V_155 = V_280 ;
V_53 -> V_92 = V_281 ;
V_53 -> V_94 = V_282 ;
V_53 -> V_97 [ 0 ] = V_283 ;
V_53 -> V_97 [ 1 ] = V_284 ;
V_53 -> V_97 [ 2 ] = V_285 ;
V_53 -> V_141 = V_286 ;
V_53 -> V_151 = V_287 ;
V_53 -> V_146 = V_288 ;
V_53 -> V_160 = V_289 ;
V_132 = V_290 ;
V_232 = V_291 ;
V_237 = F_39 ( V_290 ) ;
V_238 = F_39 ( V_291 ) ;
V_230 = V_292 ;
V_231 = V_293 ;
V_206 = V_294 ;
V_233 = V_295 ;
V_234 = V_296 ;
V_235 = V_297 ;
V_236 = V_298 ;
break;
case V_56 :
V_53 -> V_119 = 9 ;
V_53 -> V_80 = 3 ;
V_53 -> V_106 = 6 ;
V_53 -> V_73 = true ;
V_53 -> V_207 = 3 ;
V_53 -> V_157 = 3 ;
V_53 -> V_162 = 3 ;
V_53 -> V_151 = V_299 ;
V_53 -> V_160 = V_300 ;
V_53 -> V_126 = F_17 ;
V_53 -> V_165 = F_15 ;
V_53 -> V_104 = 0x7f ;
V_53 -> V_184 = 0x0f ;
V_53 -> V_192 = 15 ;
V_53 -> V_171 = V_301 ;
V_53 -> V_224 = F_39 ( V_301 ) ;
V_53 -> V_205 = V_302 ;
V_53 -> V_178 = V_303 ;
V_53 -> V_179 = V_304 ;
V_53 -> V_177 = V_305 ;
V_53 -> V_122 = V_306 ;
V_53 -> V_123 [ 0 ] = V_307 ;
V_53 -> V_123 [ 1 ] = V_308 ;
V_53 -> V_101 = V_309 ;
V_53 -> V_125 = V_310 ;
V_53 -> V_85 = V_311 ;
V_53 -> V_76 = V_312 ;
V_53 -> V_128 = V_313 ;
V_53 -> V_129 = V_314 ;
V_53 -> V_100 [ 0 ] = V_315 ;
V_53 -> V_100 [ 1 ] = V_316 ;
V_53 -> V_100 [ 2 ] = V_317 ;
V_53 -> V_86 [ 0 ] = V_318 ;
V_53 -> V_86 [ 1 ] = V_319 ;
V_53 -> V_86 [ 2 ] = V_320 ;
V_53 -> V_86 [ 3 ] = V_321 ;
V_53 -> V_86 [ 4 ] = V_322 ;
V_53 -> V_86 [ 5 ] = V_323 ;
V_53 -> V_181 = V_324 ;
V_53 -> V_82 = V_325 ;
V_53 -> V_83 = V_326 ;
V_53 -> V_270 = V_327 ;
V_53 -> V_272 = V_328 ;
V_53 -> V_109 = V_329 ;
V_53 -> V_91
= V_330 ;
V_53 -> V_137 = V_331 ;
V_53 -> V_155 = V_332 ;
V_53 -> V_92 = V_333 ;
V_53 -> V_94 = V_334 ;
V_53 -> V_97 [ 0 ] = V_335 ;
V_53 -> V_97 [ 1 ] = V_336 ;
V_53 -> V_97 [ 2 ] = V_337 ;
V_53 -> V_141 = V_338 ;
V_53 -> V_146 = V_339 ;
V_132 = V_340 ;
V_232 = V_341 ;
V_237 = F_39 ( V_340 ) ;
V_238 = F_39 ( V_341 ) ;
V_230 = V_342 ;
V_231 = V_343 ;
V_206 = V_344 ;
V_233 = V_345 ;
V_234 = V_346 ;
break;
case V_57 :
V_53 -> V_119 = 9 ;
V_53 -> V_80 = 3 ;
V_53 -> V_106 = 4 ;
V_53 -> V_73 = false ;
V_53 -> V_207 = 3 ;
V_53 -> V_157 = 3 ;
V_53 -> V_162 = 6 ;
V_53 -> V_151 = V_347 ;
V_53 -> V_160 = V_348 ;
V_53 -> V_126 = F_16 ;
V_53 -> V_165 = F_16 ;
V_53 -> V_104 = 0xff ;
V_53 -> V_184 = 0x07 ;
V_53 -> V_192 = 63 ;
V_53 -> V_171 = V_246 ;
V_53 -> V_224 = F_39 ( V_246 ) ;
V_53 -> V_205 = V_302 ;
V_53 -> V_178 = V_303 ;
V_53 -> V_179 = V_304 ;
V_53 -> V_177 = V_305 ;
V_53 -> V_122 = V_306 ;
V_53 -> V_123 [ 0 ] = V_307 ;
V_53 -> V_123 [ 1 ] = V_308 ;
V_53 -> V_101 = V_309 ;
V_53 -> V_125 = V_310 ;
V_53 -> V_85 = V_311 ;
V_53 -> V_76 = V_349 ;
V_53 -> V_128 = V_350 ;
V_53 -> V_129 = V_314 ;
V_53 -> V_100 [ 0 ] = V_315 ;
V_53 -> V_100 [ 1 ] = V_316 ;
V_53 -> V_100 [ 2 ] = V_317 ;
V_53 -> V_90 = V_351 ;
V_53 -> V_86 [ 0 ] = V_318 ;
V_53 -> V_86 [ 1 ] = V_319 ;
V_53 -> V_86 [ 2 ] = V_320 ;
V_53 -> V_86 [ 5 ] = V_323 ;
V_53 -> V_86 [ 6 ] = V_352 ;
V_53 -> V_181 = V_324 ;
V_53 -> V_82 = V_353 ;
V_53 -> V_83 = V_354 ;
V_53 -> V_270 = V_327 ;
V_53 -> V_272 = V_328 ;
V_53 -> V_109 = V_329 ;
V_53 -> V_91
= V_330 ;
V_53 -> V_137 = V_331 ;
V_53 -> V_155 = V_332 ;
V_53 -> V_92 = V_333 ;
V_53 -> V_94 = V_334 ;
V_53 -> V_97 [ 0 ] = V_335 ;
V_53 -> V_97 [ 1 ] = V_336 ;
V_53 -> V_97 [ 2 ] = V_337 ;
V_53 -> V_141 = V_338 ;
V_53 -> V_146 = V_355 ;
V_132 = V_340 ;
V_232 = V_341 ;
V_237 = F_39 ( V_340 ) ;
V_238 = F_39 ( V_341 ) ;
V_230 = V_342 ;
V_231 = V_343 ;
V_206 = V_356 ;
V_233 = V_357 ;
V_234 = V_358 ;
break;
case V_58 :
V_53 -> V_119 = 15 ;
V_53 -> V_80 = 5 ;
V_53 -> V_106 = 4 ;
V_53 -> V_73 = false ;
V_53 -> V_207 = 6 ;
V_53 -> V_157 = 2 ;
V_53 -> V_162 = 2 ;
V_53 -> V_151 = V_359 ;
V_53 -> V_160 = V_360 ;
V_53 -> V_126 = F_16 ;
V_53 -> V_165 = F_16 ;
V_53 -> V_104 = 0xff ;
V_53 -> V_184 = 0x07 ;
V_53 -> V_192 = 63 ;
V_53 -> V_171 = V_361 ;
V_53 -> V_224 = F_39 ( V_361 ) ;
V_53 -> V_205 = V_302 ;
V_53 -> V_178 = V_303 ;
V_53 -> V_179 = V_304 ;
V_53 -> V_177 = V_305 ;
V_53 -> V_122 = V_362 ;
V_53 -> V_123 [ 0 ] = V_307 ;
V_53 -> V_123 [ 1 ] = V_308 ;
V_53 -> V_101 = V_309 ;
V_53 -> V_125 = V_363 ;
V_53 -> V_85 = V_311 ;
V_53 -> V_76 = V_349 ;
V_53 -> V_128 = V_364 ;
V_53 -> V_129 = V_314 ;
V_53 -> V_100 [ 0 ] = V_315 ;
V_53 -> V_100 [ 1 ] = V_316 ;
V_53 -> V_100 [ 2 ] = V_317 ;
V_53 -> V_90 = V_351 ;
V_53 -> V_86 [ 0 ] = V_318 ;
V_53 -> V_86 [ 1 ] = V_319 ;
V_53 -> V_86 [ 2 ] = V_320 ;
V_53 -> V_86 [ 5 ] = V_323 ;
V_53 -> V_86 [ 6 ] = V_352 ;
V_53 -> V_181 = V_324 ;
V_53 -> V_82 = V_353 ;
V_53 -> V_83 = V_354 ;
V_53 -> V_270 = V_327 ;
V_53 -> V_272 = V_328 ;
V_53 -> V_109 = V_329 ;
V_53 -> V_91
= V_330 ;
V_53 -> V_111 = V_365 ;
V_53 -> V_112
= V_366 ;
V_53 -> V_113 = V_367 ;
V_53 -> V_137 = V_368 ;
V_53 -> V_155 = V_332 ;
V_53 -> V_92 = V_333 ;
V_53 -> V_94 = V_334 ;
V_53 -> V_97 [ 0 ] = V_335 ;
V_53 -> V_97 [ 1 ] = V_336 ;
V_53 -> V_97 [ 2 ] = V_337 ;
V_53 -> V_141 = V_369 ;
V_53 -> V_146 = V_355 ;
V_132 = V_370 ;
V_232 = V_371 ;
V_237 = F_39 ( V_370 ) ;
V_238 = F_39 ( V_371 ) ;
V_230 = V_372 ;
V_231 = V_373 ;
V_206 = V_374 ;
V_233 = V_375 ;
V_234 = V_376 ;
break;
case V_59 :
case V_60 :
V_53 -> V_119 = 15 ;
V_53 -> V_80 = 6 ;
V_53 -> V_106 = 4 ;
V_53 -> V_73 = false ;
V_53 -> V_207 = 6 ;
V_53 -> V_157 = 2 ;
V_53 -> V_162 = 2 ;
V_53 -> V_151 = V_377 ;
V_53 -> V_160 = V_360 ;
V_53 -> V_126 = F_16 ;
V_53 -> V_165 = F_16 ;
V_53 -> V_104 = 0xff ;
V_53 -> V_184 = 0x07 ;
V_53 -> V_192 = 63 ;
V_53 -> V_171 = V_361 ;
V_53 -> V_224 = F_39 ( V_361 ) ;
V_53 -> V_205 = V_302 ;
V_53 -> V_178 = V_303 ;
V_53 -> V_179 = V_304 ;
V_53 -> V_177 = V_305 ;
V_53 -> V_122 = V_362 ;
V_53 -> V_123 [ 0 ] = V_307 ;
V_53 -> V_123 [ 1 ] = V_308 ;
V_53 -> V_101 = V_309 ;
V_53 -> V_125 = V_363 ;
V_53 -> V_85 = V_311 ;
V_53 -> V_76 = V_349 ;
V_53 -> V_128 = V_364 ;
V_53 -> V_129 = V_314 ;
V_53 -> V_100 [ 0 ] = V_315 ;
V_53 -> V_100 [ 1 ] = V_316 ;
V_53 -> V_100 [ 2 ] = V_317 ;
V_53 -> V_90 = V_351 ;
V_53 -> V_86 [ 0 ] = V_318 ;
V_53 -> V_86 [ 1 ] = V_319 ;
V_53 -> V_86 [ 2 ] = V_320 ;
V_53 -> V_86 [ 5 ] = V_378 ;
V_53 -> V_86 [ 6 ] = V_379 ;
V_53 -> V_181 = V_324 ;
V_53 -> V_82 = V_353 ;
V_53 -> V_83 = V_354 ;
V_53 -> V_270 = V_327 ;
V_53 -> V_272 = V_328 ;
V_53 -> V_109 = V_329 ;
V_53 -> V_91
= V_330 ;
V_53 -> V_111 = V_365 ;
V_53 -> V_112
= V_366 ;
V_53 -> V_113 = V_367 ;
V_53 -> V_137 = V_368 ;
V_53 -> V_155 = V_332 ;
V_53 -> V_92 = V_333 ;
V_53 -> V_94 = V_380 ;
V_53 -> V_97 [ 0 ] = V_381 ;
V_53 -> V_97 [ 1 ] = V_382 ;
V_53 -> V_97 [ 2 ] = V_383 ;
V_53 -> V_141 = V_384 ;
if ( V_53 -> V_54 == V_59 )
V_53 -> V_146 = V_355 ;
else
V_53 -> V_146 = V_385 ;
V_132 = V_370 ;
V_237 = F_39 ( V_370 ) ;
if ( V_53 -> V_54 == V_59 ) {
V_232 = V_371 ;
V_238 = F_39 ( V_371 ) ;
} else {
V_232 = V_386 ;
V_238 = F_39 ( V_386 ) ;
}
V_230 = V_372 ;
V_231 = V_373 ;
V_206 = V_374 ;
V_233 = V_375 ;
V_234 = V_376 ;
break;
default:
return - V_156 ;
}
V_53 -> V_120 = ( 1 << V_53 -> V_119 ) - 1 ;
V_53 -> V_131 = 0 ;
V_223 = 0 ;
V_222 = 0 ;
for ( V_34 = 0 ; V_34 < V_237 ; V_34 ++ ) {
if ( V_132 [ V_34 ] == 0 )
continue;
V_154 = F_29 ( V_53 , V_53 -> V_155 [ V_34 ] ) & 0x1f ;
if ( ! V_154 || ( V_223 & ( 1 << V_154 ) ) )
V_222 |= 1 << V_34 ;
V_223 |= 1 << V_154 ;
}
F_123 ( V_53 , V_53 -> V_92 , & V_222 , & V_223 ) ;
F_123 ( V_53 , V_53 -> V_94 , & V_222 , & V_223 ) ;
V_223 = 0 ;
V_47 = V_134 ;
for ( V_34 = 0 ; V_34 < V_237 ; V_34 ++ ) {
if ( V_132 [ V_34 ] == 0 )
continue;
V_154 = F_29 ( V_53 , V_53 -> V_155 [ V_34 ] ) & 0x1f ;
if ( ! V_154 || ( V_223 & ( 1 << V_154 ) ) )
continue;
if ( V_154 >= V_53 -> V_224 ||
! strlen ( V_53 -> V_171 [ V_154 ] ) ) {
F_70 ( V_19 ,
L_12 ,
V_154 , V_34 , V_53 -> V_155 [ V_34 ] , V_132 [ V_34 ] ) ;
continue;
}
V_223 |= 1 << V_154 ;
if ( V_154 <= V_53 -> V_207 ) {
V_53 -> V_131 |= 1 << ( V_154 - 1 ) ;
V_53 -> V_135 |= 1 << ( V_154 - 1 ) ;
V_53 -> V_132 [ 0 ] [ V_154 - 1 ] = V_132 [ V_34 ] ;
V_53 -> V_132 [ 1 ] [ V_154 - 1 ] = V_230 [ V_34 ] ;
V_53 -> V_132 [ 2 ] [ V_154 - 1 ] = V_231 [ V_34 ] ;
if ( V_236 && V_236 [ V_34 ] )
V_53 -> V_132 [ 3 ] [ V_154 - 1 ] = V_236 [ V_34 ] ;
else if ( V_234 [ V_154 - 1 ] )
V_53 -> V_132 [ 3 ] [ V_154 - 1 ]
= V_234 [ V_154 - 1 ] ;
if ( V_235 && V_235 [ V_34 ] )
V_53 -> V_132 [ 4 ] [ V_154 - 1 ] = V_235 [ V_34 ] ;
V_53 -> V_206 [ V_154 - 1 ] = V_206 [ V_34 ] ;
V_53 -> V_153 [ V_154 - 1 ] = V_154 ;
continue;
}
if ( V_47 >= V_130 )
continue;
V_53 -> V_131 |= 1 << V_47 ;
V_53 -> V_132 [ 0 ] [ V_47 ] = V_132 [ V_34 ] ;
V_53 -> V_132 [ 1 ] [ V_47 ] = V_230 [ V_34 ] ;
V_53 -> V_132 [ 2 ] [ V_47 ] = V_231 [ V_34 ] ;
V_53 -> V_206 [ V_47 ] = V_206 [ V_34 ] ;
if ( V_236 && V_236 [ V_34 ] )
V_53 -> V_132 [ 3 ] [ V_47 ] = V_236 [ V_34 ] ;
else if ( V_234 [ V_154 - 1 ] )
V_53 -> V_132 [ 3 ] [ V_47 ] = V_234 [ V_154 - 1 ] ;
if ( V_235 && V_235 [ V_34 ] )
V_53 -> V_132 [ 4 ] [ V_47 ] = V_235 [ V_34 ] ;
V_53 -> V_153 [ V_47 ] = V_154 ;
V_47 ++ ;
}
for ( V_34 = 0 ; V_34 < V_238 ; V_34 ++ ) {
if ( V_232 [ V_34 ] == 0 )
continue;
V_154 = F_29 ( V_53 , V_53 -> V_92 [ V_34 ] ) & 0x1f ;
if ( ! V_154 || ( V_223 & ( 1 << V_154 ) ) )
continue;
if ( V_154 >= V_53 -> V_224 ||
! strlen ( V_53 -> V_171 [ V_154 ] ) ) {
F_70 ( V_19 ,
L_12 ,
V_154 , V_34 , V_53 -> V_92 [ V_34 ] ,
V_232 [ V_34 ] ) ;
continue;
}
V_223 |= 1 << V_154 ;
if ( V_154 <= V_53 -> V_207 ) {
if ( V_53 -> V_131 & ( 1 << ( V_154 - 1 ) ) )
continue;
V_53 -> V_131 |= 1 << ( V_154 - 1 ) ;
V_53 -> V_135 |= 1 << ( V_154 - 1 ) ;
V_53 -> V_132 [ 0 ] [ V_154 - 1 ] = V_232 [ V_34 ] ;
V_53 -> V_153 [ V_154 - 1 ] = V_154 ;
continue;
}
if ( V_47 >= V_130 )
continue;
V_53 -> V_131 |= 1 << V_47 ;
V_53 -> V_132 [ 0 ] [ V_47 ] = V_232 [ V_34 ] ;
V_53 -> V_153 [ V_47 ] = V_154 ;
V_47 ++ ;
}
#ifdef F_131
for ( V_34 = 0 ; V_34 < V_53 -> V_224 - 1 ; V_34 ++ ) {
if ( ! V_233 [ V_34 ] )
continue;
if ( V_223 & ( 1 << ( V_34 + 1 ) ) )
continue;
if ( V_34 < V_53 -> V_207 ) {
if ( V_53 -> V_131 & ( 1 << V_34 ) )
continue;
V_53 -> V_131 |= 1 << V_34 ;
V_53 -> V_135 |= 1 << V_34 ;
V_53 -> V_132 [ 0 ] [ V_34 ] = V_233 [ V_34 ] ;
if ( V_34 < V_237 ) {
V_53 -> V_132 [ 1 ] [ V_34 ] = V_230 [ V_34 ] ;
V_53 -> V_132 [ 2 ] [ V_34 ] = V_231 [ V_34 ] ;
}
V_53 -> V_153 [ V_34 ] = V_34 + 1 ;
continue;
}
if ( V_47 >= V_130 )
break;
V_53 -> V_131 |= 1 << V_47 ;
V_53 -> V_132 [ 0 ] [ V_47 ] = V_233 [ V_34 ] ;
V_53 -> V_153 [ V_47 ] = V_34 + 1 ;
V_47 ++ ;
}
#endif
F_121 ( V_53 ) ;
V_150 = F_6 ( V_228 -> V_199 ) ;
if ( V_150 )
return V_150 ;
V_239 = F_3 ( V_228 -> V_199 , 0x2a ) ;
switch ( V_53 -> V_54 ) {
case V_56 :
V_53 -> V_203 = ( V_239 & 0x40 ) ;
break;
case V_57 :
V_53 -> V_203 = ( V_239 & 0x60 ) == 0x40 ;
break;
case V_55 :
case V_58 :
case V_59 :
case V_60 :
break;
}
if ( V_53 -> V_203 ) {
F_5 ( V_228 -> V_199 , V_387 ) ;
V_53 -> V_195 = F_3 ( V_228 -> V_199 , 0xe3 ) ;
V_53 -> V_196 = F_132 () ;
}
if ( V_388 ) {
T_1 V_204 ;
F_5 ( V_228 -> V_199 , V_219 ) ;
V_204 = F_3 ( V_228 -> V_199 ,
V_389 ) ;
switch ( V_53 -> V_54 ) {
case V_55 :
V_204 |= 0xe0 ;
break;
case V_56 :
V_204 |= 0x1e ;
break;
case V_57 :
case V_58 :
V_204 |= 0x3e ;
break;
case V_59 :
case V_60 :
V_204 |= 0x7e ;
break;
}
F_1 ( V_228 -> V_199 , V_389 ,
V_204 ) ;
F_70 ( & V_226 -> V_19 , L_13 ,
V_53 -> V_41 ) ;
}
F_122 ( V_53 ) ;
F_8 ( V_228 -> V_199 ) ;
F_40 ( V_19 , V_53 ) ;
V_23 = F_23 ( V_19 , & V_390 ,
V_53 -> V_80 ) ;
if ( F_133 ( V_23 ) )
return F_134 ( V_23 ) ;
V_53 -> V_391 [ V_241 ++ ] = V_23 ;
V_23 = F_23 ( V_19 , & V_392 ,
F_135 ( V_53 -> V_120 ) ) ;
if ( F_133 ( V_23 ) )
return F_134 ( V_23 ) ;
V_53 -> V_391 [ V_241 ++ ] = V_23 ;
V_23 = F_23 ( V_19 , & V_393 ,
F_135 ( V_53 -> V_72 ) ) ;
if ( F_133 ( V_23 ) )
return F_134 ( V_23 ) ;
V_53 -> V_391 [ V_241 ++ ] = V_23 ;
V_23 = F_23 ( V_19 , & V_394 ,
F_135 ( V_53 -> V_131 ) ) ;
if ( F_133 ( V_23 ) )
return F_134 ( V_23 ) ;
V_53 -> V_391 [ V_241 ++ ] = V_23 ;
V_53 -> V_391 [ V_241 ++ ] = & V_395 ;
V_240 = F_136 ( V_19 , V_53 -> V_41 ,
V_53 , V_53 -> V_391 ) ;
return F_137 ( V_240 ) ;
}
static void F_138 ( int V_396 )
{
int V_3 ;
V_3 = F_3 ( V_396 , V_397 ) ;
if ( V_3 & 0x10 ) {
F_139 ( L_14 ) ;
F_1 ( V_396 , V_397 ,
V_3 & ~ 0x10 ) ;
}
}
static int F_140 ( struct V_18 * V_19 )
{
struct V_52 * V_53 = F_48 ( V_19 ) ;
F_49 ( & V_53 -> V_114 ) ;
V_53 -> V_173 = F_29 ( V_53 , V_53 -> V_178 ) ;
if ( V_53 -> V_54 == V_56 ) {
V_53 -> V_398 = F_29 ( V_53 , V_69 ) ;
V_53 -> V_399 = F_29 ( V_53 , V_71 ) ;
}
F_51 ( & V_53 -> V_114 ) ;
return 0 ;
}
static int F_141 ( struct V_18 * V_19 )
{
struct V_52 * V_53 = F_44 ( V_19 ) ;
int V_34 , V_77 , V_150 = 0 ;
F_49 ( & V_53 -> V_114 ) ;
V_53 -> V_61 = 0xff ;
if ( V_53 -> V_54 == V_59 || V_53 -> V_54 == V_60 ) {
V_150 = F_6 ( V_53 -> V_199 ) ;
if ( V_150 )
goto abort;
F_138 ( V_53 -> V_199 ) ;
F_8 ( V_53 -> V_199 ) ;
}
for ( V_34 = 0 ; V_34 < V_53 -> V_119 ; V_34 ++ ) {
if ( ! ( V_53 -> V_120 & ( 1 << V_34 ) ) )
continue;
F_31 ( V_53 , V_53 -> V_123 [ 0 ] [ V_34 ] ,
V_53 -> V_121 [ V_34 ] [ 1 ] ) ;
F_31 ( V_53 , V_53 -> V_123 [ 1 ] [ V_34 ] ,
V_53 -> V_121 [ V_34 ] [ 2 ] ) ;
}
for ( V_34 = 0 ; V_34 < F_39 ( V_53 -> V_74 ) ; V_34 ++ ) {
if ( ! ( V_53 -> V_75 & ( 1 << V_34 ) ) )
continue;
F_31 ( V_53 , V_53 -> V_76 [ V_34 ] ,
V_53 -> V_74 [ V_34 ] ) ;
}
for ( V_34 = 0 ; V_34 < V_130 ; V_34 ++ ) {
if ( ! ( V_53 -> V_131 & ( 1 << V_34 ) ) )
continue;
for ( V_77 = 1 ; V_77 < F_39 ( V_53 -> V_132 ) ; V_77 ++ )
if ( V_53 -> V_132 [ V_77 ] [ V_34 ] )
F_33 ( V_53 , V_53 -> V_132 [ V_77 ] [ V_34 ] ,
V_53 -> V_133 [ V_77 ] [ V_34 ] ) ;
}
F_31 ( V_53 , V_53 -> V_178 , V_53 -> V_173 ) ;
if ( V_53 -> V_54 == V_56 ) {
F_31 ( V_53 , V_69 , V_53 -> V_398 ) ;
F_31 ( V_53 , V_71 , V_53 -> V_399 ) ;
}
abort:
V_53 -> V_118 = false ;
F_51 ( & V_53 -> V_114 ) ;
return V_150 ;
}
static int T_7 F_142 ( int V_396 , struct V_227 * V_228 )
{
T_2 V_3 ;
int V_150 ;
int V_63 ;
V_150 = F_6 ( V_396 ) ;
if ( V_150 )
return V_150 ;
if ( V_400 )
V_3 = V_400 ;
else
V_3 = ( F_3 ( V_396 , V_401 ) << 8 )
| F_3 ( V_396 , V_401 + 1 ) ;
switch ( V_3 & V_402 ) {
case V_403 :
V_228 -> V_54 = V_55 ;
break;
case V_404 :
V_228 -> V_54 = V_56 ;
break;
case V_405 :
V_228 -> V_54 = V_57 ;
break;
case V_406 :
V_228 -> V_54 = V_58 ;
break;
case V_407 :
V_228 -> V_54 = V_59 ;
break;
case V_408 :
V_228 -> V_54 = V_60 ;
break;
default:
if ( V_3 != 0xffff )
F_143 ( L_15 , V_3 ) ;
F_8 ( V_396 ) ;
return - V_156 ;
}
F_5 ( V_396 , V_219 ) ;
V_3 = ( F_3 ( V_396 , V_409 ) << 8 )
| F_3 ( V_396 , V_409 + 1 ) ;
V_63 = V_3 & V_410 ;
if ( V_63 == 0 ) {
F_144 ( L_16 ) ;
F_8 ( V_396 ) ;
return - V_156 ;
}
V_3 = F_3 ( V_396 , V_220 ) ;
if ( ! ( V_3 & 0x01 ) ) {
F_145 ( L_17 ) ;
F_1 ( V_396 , V_220 , V_3 | 0x01 ) ;
}
if ( V_228 -> V_54 == V_59 || V_228 -> V_54 == V_60 )
F_138 ( V_396 ) ;
F_8 ( V_396 ) ;
F_139 ( L_18 ,
V_411 [ V_228 -> V_54 ] , V_396 , V_63 ) ;
V_228 -> V_199 = V_396 ;
return V_63 ;
}
static int T_7 F_146 ( void )
{
int V_34 , V_150 ;
bool V_412 = false ;
int V_413 ;
struct V_229 V_66 ;
struct V_227 V_228 ;
int V_396 [ 2 ] = { 0x2e , 0x4e } ;
V_150 = F_147 ( & V_414 ) ;
if ( V_150 )
return V_150 ;
for ( V_34 = 0 ; V_34 < F_39 ( V_226 ) ; V_34 ++ ) {
V_413 = F_142 ( V_396 [ V_34 ] , & V_228 ) ;
if ( V_413 <= 0 )
continue;
V_412 = true ;
V_226 [ V_34 ] = F_148 ( V_6 , V_413 ) ;
if ( ! V_226 [ V_34 ] ) {
V_150 = - V_39 ;
goto V_415;
}
V_150 = F_149 ( V_226 [ V_34 ] , & V_228 ,
sizeof( struct V_227 ) ) ;
if ( V_150 )
goto V_416;
memset ( & V_66 , 0 , sizeof( V_66 ) ) ;
V_66 . V_41 = V_6 ;
V_66 . V_243 = V_413 + V_417 ;
V_66 . V_418 = V_413 + V_417 + V_244 - 1 ;
V_66 . V_419 = V_242 ;
V_150 = F_150 ( & V_66 ) ;
if ( V_150 ) {
F_151 ( V_226 [ V_34 ] ) ;
V_226 [ V_34 ] = NULL ;
continue;
}
V_150 = F_152 ( V_226 [ V_34 ] , & V_66 , 1 ) ;
if ( V_150 )
goto V_416;
V_150 = F_153 ( V_226 [ V_34 ] ) ;
if ( V_150 )
goto V_416;
}
if ( ! V_412 ) {
V_150 = - V_156 ;
goto V_420;
}
return 0 ;
V_416:
F_151 ( V_226 [ V_34 ] ) ;
V_415:
while ( -- V_34 >= 0 ) {
if ( V_226 [ V_34 ] )
F_154 ( V_226 [ V_34 ] ) ;
}
V_420:
F_155 ( & V_414 ) ;
return V_150 ;
}
static void T_8 F_156 ( void )
{
int V_34 ;
for ( V_34 = 0 ; V_34 < F_39 ( V_226 ) ; V_34 ++ ) {
if ( V_226 [ V_34 ] )
F_154 ( V_226 [ V_34 ] ) ;
}
F_155 ( & V_414 ) ;
}
