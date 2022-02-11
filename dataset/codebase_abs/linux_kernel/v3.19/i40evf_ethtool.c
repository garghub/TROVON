static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_4 -> V_5 = 0 ;
V_4 -> V_6 = V_7 ;
V_4 -> V_8 = V_9 ;
V_4 -> V_10 = V_11 ;
return 0 ;
}
static int F_2 ( struct V_1 * V_2 , int V_12 )
{
if ( V_12 == V_13 )
return F_3 ( V_2 ) ;
else
return - V_14 ;
}
static void F_4 ( struct V_1 * V_2 ,
struct V_15 * V_16 , T_1 * V_17 )
{
struct V_18 * V_19 = F_5 ( V_2 ) ;
int V_20 , V_21 ;
char * V_22 ;
for ( V_20 = 0 ; V_20 < V_23 ; V_20 ++ ) {
V_22 = ( char * ) V_19 + V_24 [ V_20 ] . V_25 ;
V_17 [ V_20 ] = * ( T_1 * ) V_22 ;
}
for ( V_21 = 0 ; V_21 < V_19 -> V_26 ; V_21 ++ ) {
V_17 [ V_20 ++ ] = V_19 -> V_27 [ V_21 ] -> V_16 . V_28 ;
V_17 [ V_20 ++ ] = V_19 -> V_27 [ V_21 ] -> V_16 . V_29 ;
}
for ( V_21 = 0 ; V_21 < V_19 -> V_26 ; V_21 ++ ) {
V_17 [ V_20 ++ ] = V_19 -> V_30 [ V_21 ] -> V_16 . V_28 ;
V_17 [ V_20 ++ ] = V_19 -> V_30 [ V_21 ] -> V_16 . V_29 ;
}
}
static void F_6 ( struct V_1 * V_2 , T_2 V_12 , T_3 * V_17 )
{
struct V_18 * V_19 = F_5 ( V_2 ) ;
T_3 * V_22 = V_17 ;
int V_20 ;
if ( V_12 == V_13 ) {
for ( V_20 = 0 ; V_20 < V_23 ; V_20 ++ ) {
memcpy ( V_22 , V_24 [ V_20 ] . V_31 ,
V_32 ) ;
V_22 += V_32 ;
}
for ( V_20 = 0 ; V_20 < V_19 -> V_26 ; V_20 ++ ) {
snprintf ( V_22 , V_32 , L_1 , V_20 ) ;
V_22 += V_32 ;
snprintf ( V_22 , V_32 , L_2 , V_20 ) ;
V_22 += V_32 ;
}
for ( V_20 = 0 ; V_20 < V_19 -> V_26 ; V_20 ++ ) {
snprintf ( V_22 , V_32 , L_3 , V_20 ) ;
V_22 += V_32 ;
snprintf ( V_22 , V_32 , L_4 , V_20 ) ;
V_22 += V_32 ;
}
}
}
static T_2 F_7 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = F_5 ( V_2 ) ;
return V_19 -> V_33 ;
}
static void F_8 ( struct V_1 * V_2 , T_2 V_17 )
{
struct V_18 * V_19 = F_5 ( V_2 ) ;
V_19 -> V_33 = V_17 ;
}
static void F_9 ( struct V_1 * V_2 ,
struct V_34 * V_35 )
{
struct V_18 * V_19 = F_5 ( V_2 ) ;
F_10 ( V_35 -> V_36 , V_37 , 32 ) ;
F_10 ( V_35 -> V_38 , V_39 , 32 ) ;
F_10 ( V_35 -> V_40 , F_11 ( V_19 -> V_41 ) , 32 ) ;
}
static void F_12 ( struct V_1 * V_2 ,
struct V_42 * V_43 )
{
struct V_18 * V_19 = F_5 ( V_2 ) ;
V_43 -> V_44 = V_45 ;
V_43 -> V_46 = V_47 ;
V_43 -> V_48 = V_19 -> V_49 ;
V_43 -> V_50 = V_19 -> V_51 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_42 * V_43 )
{
struct V_18 * V_19 = F_5 ( V_2 ) ;
T_2 V_52 , V_53 ;
if ( ( V_43 -> V_54 ) || ( V_43 -> V_55 ) )
return - V_14 ;
V_53 = F_14 ( T_2 , V_43 -> V_50 ,
V_56 ,
V_47 ) ;
V_53 = F_15 ( V_53 , V_57 ) ;
V_52 = F_14 ( T_2 , V_43 -> V_48 ,
V_58 ,
V_45 ) ;
V_52 = F_15 ( V_52 , V_57 ) ;
if ( ( V_53 == V_19 -> V_51 ) &&
( V_52 == V_19 -> V_49 ) )
return 0 ;
V_19 -> V_51 = V_53 ;
V_19 -> V_49 = V_52 ;
if ( F_16 ( V_2 ) )
F_17 ( V_19 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_59 * V_60 )
{
struct V_18 * V_19 = F_5 ( V_2 ) ;
struct V_61 * V_62 = & V_19 -> V_62 ;
V_60 -> V_63 = V_62 -> V_64 ;
V_60 -> V_65 = V_62 -> V_64 ;
if ( F_19 ( V_62 -> V_66 ) )
V_60 -> V_67 = 1 ;
if ( F_19 ( V_62 -> V_68 ) )
V_60 -> V_69 = 1 ;
V_60 -> V_70 = V_62 -> V_66 & ~ V_71 ;
V_60 -> V_72 = V_62 -> V_68 & ~ V_71 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_59 * V_60 )
{
struct V_18 * V_19 = F_5 ( V_2 ) ;
struct V_73 * V_74 = & V_19 -> V_74 ;
struct V_61 * V_62 = & V_19 -> V_62 ;
struct V_75 * V_76 ;
int V_20 ;
if ( V_60 -> V_77 || V_60 -> V_78 )
V_62 -> V_64 = V_60 -> V_77 ;
if ( ( V_60 -> V_70 >= ( V_79 << 1 ) ) &&
( V_60 -> V_70 <= ( V_80 << 1 ) ) )
V_62 -> V_66 = V_60 -> V_70 ;
else
return - V_14 ;
if ( ( V_60 -> V_72 >= ( V_79 << 1 ) ) &&
( V_60 -> V_72 <= ( V_80 << 1 ) ) )
V_62 -> V_68 = V_60 -> V_72 ;
else if ( V_60 -> V_69 )
V_62 -> V_68 = ( V_71 |
F_21 ( V_81 ) ) ;
else
return - V_14 ;
if ( V_60 -> V_67 )
V_62 -> V_66 |= V_71 ;
else
V_62 -> V_66 &= ~ V_71 ;
if ( V_60 -> V_69 )
V_62 -> V_68 |= V_71 ;
else
V_62 -> V_68 &= ~ V_71 ;
for ( V_20 = 0 ; V_20 < V_19 -> V_82 - V_83 ; V_20 ++ ) {
V_76 = V_19 -> V_76 [ V_20 ] ;
V_76 -> V_84 . V_85 = F_22 ( V_62 -> V_66 ) ;
F_23 ( V_74 , F_24 ( 0 , V_20 ) , V_76 -> V_84 . V_85 ) ;
V_76 -> V_86 . V_85 = F_22 ( V_62 -> V_68 ) ;
F_23 ( V_74 , F_24 ( 1 , V_20 ) , V_76 -> V_86 . V_85 ) ;
F_25 ( V_74 ) ;
}
return 0 ;
}
static int F_26 ( struct V_18 * V_19 ,
struct V_87 * V_88 )
{
struct V_73 * V_74 = & V_19 -> V_74 ;
T_1 V_89 = ( T_1 ) F_27 ( V_74 , F_28 ( 0 ) ) |
( ( T_1 ) F_27 ( V_74 , F_28 ( 1 ) ) << 32 ) ;
V_88 -> V_17 = V_90 | V_91 ;
switch ( V_88 -> V_92 ) {
case V_93 :
if ( V_89 & ( ( T_1 ) 1 << V_94 ) )
V_88 -> V_17 |= V_95 | V_96 ;
break;
case V_97 :
if ( V_89 & ( ( T_1 ) 1 << V_98 ) )
V_88 -> V_17 |= V_95 | V_96 ;
break;
case V_99 :
case V_100 :
case V_101 :
case V_102 :
case V_103 :
break;
case V_104 :
if ( V_89 & ( ( T_1 ) 1 << V_105 ) )
V_88 -> V_17 |= V_95 | V_96 ;
break;
case V_106 :
if ( V_89 & ( ( T_1 ) 1 << V_107 ) )
V_88 -> V_17 |= V_95 | V_96 ;
break;
case V_108 :
case V_109 :
case V_110 :
case V_111 :
case V_112 :
break;
default:
V_88 -> V_17 = 0 ;
return - V_14 ;
}
return 0 ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_87 * V_88 ,
T_2 * V_113 )
{
struct V_18 * V_19 = F_5 ( V_2 ) ;
int V_114 = - V_115 ;
switch ( V_88 -> V_88 ) {
case V_116 :
V_88 -> V_17 = V_19 -> V_26 ;
V_114 = 0 ;
break;
case V_117 :
V_114 = F_26 ( V_19 , V_88 ) ;
break;
default:
break;
}
return V_114 ;
}
static int F_30 ( struct V_18 * V_19 ,
struct V_87 * V_118 )
{
struct V_73 * V_74 = & V_19 -> V_74 ;
T_1 V_89 = ( T_1 ) F_27 ( V_74 , F_28 ( 0 ) ) |
( ( T_1 ) F_27 ( V_74 , F_28 ( 1 ) ) << 32 ) ;
if ( V_118 -> V_17 & ~ ( V_90 | V_91 |
V_95 | V_96 ) )
return - V_14 ;
if ( ! ( V_118 -> V_17 & V_90 ) ||
! ( V_118 -> V_17 & V_91 ) )
return - V_14 ;
switch ( V_118 -> V_92 ) {
case V_93 :
switch ( V_118 -> V_17 & ( V_95 | V_96 ) ) {
case 0 :
V_89 &= ~ ( ( T_1 ) 1 << V_94 ) ;
break;
case ( V_95 | V_96 ) :
V_89 |= ( ( T_1 ) 1 << V_94 ) ;
break;
default:
return - V_14 ;
}
break;
case V_104 :
switch ( V_118 -> V_17 & ( V_95 | V_96 ) ) {
case 0 :
V_89 &= ~ ( ( T_1 ) 1 << V_105 ) ;
break;
case ( V_95 | V_96 ) :
V_89 |= ( ( T_1 ) 1 << V_105 ) ;
break;
default:
return - V_14 ;
}
break;
case V_97 :
switch ( V_118 -> V_17 & ( V_95 | V_96 ) ) {
case 0 :
V_89 &= ~ ( ( ( T_1 ) 1 << V_98 ) |
( ( T_1 ) 1 << V_119 ) ) ;
break;
case ( V_95 | V_96 ) :
V_89 |= ( ( ( T_1 ) 1 << V_98 ) |
( ( T_1 ) 1 << V_119 ) ) ;
break;
default:
return - V_14 ;
}
break;
case V_106 :
switch ( V_118 -> V_17 & ( V_95 | V_96 ) ) {
case 0 :
V_89 &= ~ ( ( ( T_1 ) 1 << V_107 ) |
( ( T_1 ) 1 << V_120 ) ) ;
break;
case ( V_95 | V_96 ) :
V_89 |= ( ( ( T_1 ) 1 << V_107 ) |
( ( T_1 ) 1 << V_120 ) ) ;
break;
default:
return - V_14 ;
}
break;
case V_100 :
case V_101 :
case V_102 :
case V_99 :
if ( ( V_118 -> V_17 & V_95 ) ||
( V_118 -> V_17 & V_96 ) )
return - V_14 ;
V_89 |= ( ( T_1 ) 1 << V_121 ) ;
break;
case V_109 :
case V_110 :
case V_111 :
case V_108 :
if ( ( V_118 -> V_17 & V_95 ) ||
( V_118 -> V_17 & V_96 ) )
return - V_14 ;
V_89 |= ( ( T_1 ) 1 << V_122 ) ;
break;
case V_103 :
V_89 |= ( ( T_1 ) 1 << V_121 ) |
( ( T_1 ) 1 << V_119 ) ;
break;
case V_112 :
V_89 |= ( ( T_1 ) 1 << V_122 ) |
( ( T_1 ) 1 << V_120 ) ;
break;
default:
return - V_14 ;
}
F_23 ( V_74 , F_28 ( 0 ) , ( T_2 ) V_89 ) ;
F_23 ( V_74 , F_28 ( 1 ) , ( T_2 ) ( V_89 >> 32 ) ) ;
F_25 ( V_74 ) ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_87 * V_88 )
{
struct V_18 * V_19 = F_5 ( V_2 ) ;
int V_114 = - V_115 ;
switch ( V_88 -> V_88 ) {
case V_123 :
V_114 = F_30 ( V_19 , V_88 ) ;
break;
default:
break;
}
return V_114 ;
}
static void F_32 ( struct V_1 * V_2 ,
struct V_124 * V_125 )
{
struct V_18 * V_19 = F_5 ( V_2 ) ;
V_125 -> V_126 = V_19 -> V_26 ;
V_125 -> V_127 = V_83 ;
V_125 -> V_128 = V_83 ;
V_125 -> V_129 = V_19 -> V_26 ;
}
static T_2 F_33 ( struct V_1 * V_2 )
{
return ( V_130 + 1 ) * 4 ;
}
static int F_34 ( struct V_1 * V_2 , T_2 * V_131 , T_3 * V_132 ,
T_3 * V_133 )
{
struct V_18 * V_19 = F_5 ( V_2 ) ;
struct V_73 * V_74 = & V_19 -> V_74 ;
T_2 V_134 ;
int V_20 , V_21 ;
if ( V_133 )
* V_133 = V_135 ;
if ( ! V_131 )
return 0 ;
for ( V_20 = 0 , V_21 = 0 ; V_20 <= V_130 ; V_20 ++ ) {
V_134 = F_27 ( V_74 , F_35 ( V_20 ) ) ;
V_131 [ V_21 ++ ] = V_134 & 0xff ;
V_131 [ V_21 ++ ] = ( V_134 >> 8 ) & 0xff ;
V_131 [ V_21 ++ ] = ( V_134 >> 16 ) & 0xff ;
V_131 [ V_21 ++ ] = ( V_134 >> 24 ) & 0xff ;
}
return 0 ;
}
static int F_36 ( struct V_1 * V_2 , const T_2 * V_131 ,
const T_3 * V_132 , const T_3 V_133 )
{
struct V_18 * V_19 = F_5 ( V_2 ) ;
struct V_73 * V_74 = & V_19 -> V_74 ;
T_2 V_134 ;
int V_20 , V_21 ;
if ( V_132 ||
( V_133 != V_136 && V_133 != V_135 ) )
return - V_115 ;
if ( ! V_131 )
return 0 ;
for ( V_20 = 0 , V_21 = 0 ; V_20 <= V_130 ; V_20 ++ ) {
V_134 = V_131 [ V_21 ++ ] ;
V_134 |= V_131 [ V_21 ++ ] << 8 ;
V_134 |= V_131 [ V_21 ++ ] << 16 ;
V_134 |= V_131 [ V_21 ++ ] << 24 ;
F_23 ( V_74 , F_35 ( V_20 ) , V_134 ) ;
}
return 0 ;
}
void F_37 ( struct V_1 * V_2 )
{
V_2 -> V_137 = & V_138 ;
}
