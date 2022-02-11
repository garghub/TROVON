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
if ( V_34 & V_17 )
V_19 -> V_35 . V_36 = V_17 ;
V_19 -> V_33 = V_17 ;
}
static void F_9 ( struct V_1 * V_2 ,
struct V_37 * V_38 )
{
struct V_18 * V_19 = F_5 ( V_2 ) ;
F_10 ( V_38 -> V_39 , V_40 , 32 ) ;
F_10 ( V_38 -> V_41 , V_42 , 32 ) ;
F_10 ( V_38 -> V_43 , L_5 , 4 ) ;
F_10 ( V_38 -> V_44 , F_11 ( V_19 -> V_45 ) , 32 ) ;
}
static void F_12 ( struct V_1 * V_2 ,
struct V_46 * V_47 )
{
struct V_18 * V_19 = F_5 ( V_2 ) ;
V_47 -> V_48 = V_49 ;
V_47 -> V_50 = V_51 ;
V_47 -> V_52 = V_19 -> V_53 ;
V_47 -> V_54 = V_19 -> V_55 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_46 * V_47 )
{
struct V_18 * V_19 = F_5 ( V_2 ) ;
T_2 V_56 , V_57 ;
if ( ( V_47 -> V_58 ) || ( V_47 -> V_59 ) )
return - V_14 ;
V_57 = F_14 ( T_2 , V_47 -> V_54 ,
V_60 ,
V_51 ) ;
V_57 = F_15 ( V_57 , V_61 ) ;
V_56 = F_14 ( T_2 , V_47 -> V_52 ,
V_62 ,
V_49 ) ;
V_56 = F_15 ( V_56 , V_61 ) ;
if ( ( V_57 == V_19 -> V_55 ) &&
( V_56 == V_19 -> V_53 ) )
return 0 ;
V_19 -> V_55 = V_57 ;
V_19 -> V_53 = V_56 ;
if ( F_16 ( V_2 ) )
F_17 ( V_19 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_63 * V_64 )
{
struct V_18 * V_19 = F_5 ( V_2 ) ;
struct V_65 * V_66 = & V_19 -> V_66 ;
V_64 -> V_67 = V_66 -> V_68 ;
V_64 -> V_69 = V_66 -> V_68 ;
if ( F_19 ( V_66 -> V_70 ) )
V_64 -> V_71 = 1 ;
if ( F_19 ( V_66 -> V_72 ) )
V_64 -> V_73 = 1 ;
V_64 -> V_74 = V_66 -> V_70 & ~ V_75 ;
V_64 -> V_76 = V_66 -> V_72 & ~ V_75 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_63 * V_64 )
{
struct V_18 * V_19 = F_5 ( V_2 ) ;
struct V_77 * V_35 = & V_19 -> V_35 ;
struct V_65 * V_66 = & V_19 -> V_66 ;
struct V_78 * V_79 ;
int V_20 ;
if ( V_64 -> V_80 || V_64 -> V_81 )
V_66 -> V_68 = V_64 -> V_80 ;
if ( ( V_64 -> V_74 >= ( V_82 << 1 ) ) &&
( V_64 -> V_74 <= ( V_83 << 1 ) ) )
V_66 -> V_70 = V_64 -> V_74 ;
else
return - V_14 ;
if ( ( V_64 -> V_76 >= ( V_82 << 1 ) ) &&
( V_64 -> V_76 <= ( V_83 << 1 ) ) )
V_66 -> V_72 = V_64 -> V_76 ;
else if ( V_64 -> V_73 )
V_66 -> V_72 = ( V_75 |
F_21 ( V_84 ) ) ;
else
return - V_14 ;
if ( V_64 -> V_71 )
V_66 -> V_70 |= V_75 ;
else
V_66 -> V_70 &= ~ V_75 ;
if ( V_64 -> V_73 )
V_66 -> V_72 |= V_75 ;
else
V_66 -> V_72 &= ~ V_75 ;
for ( V_20 = 0 ; V_20 < V_19 -> V_85 - V_86 ; V_20 ++ ) {
V_79 = V_19 -> V_79 [ V_20 ] ;
V_79 -> V_87 . V_88 = F_22 ( V_66 -> V_70 ) ;
F_23 ( V_35 , F_24 ( 0 , V_20 ) , V_79 -> V_87 . V_88 ) ;
V_79 -> V_89 . V_88 = F_22 ( V_66 -> V_72 ) ;
F_23 ( V_35 , F_24 ( 1 , V_20 ) , V_79 -> V_89 . V_88 ) ;
F_25 ( V_35 ) ;
}
return 0 ;
}
static int F_26 ( struct V_18 * V_19 ,
struct V_90 * V_91 )
{
struct V_77 * V_35 = & V_19 -> V_35 ;
T_1 V_92 = ( T_1 ) F_27 ( V_35 , F_28 ( 0 ) ) |
( ( T_1 ) F_27 ( V_35 , F_28 ( 1 ) ) << 32 ) ;
V_91 -> V_17 = V_93 | V_94 ;
switch ( V_91 -> V_95 ) {
case V_96 :
if ( V_92 & ( ( T_1 ) 1 << V_97 ) )
V_91 -> V_17 |= V_98 | V_99 ;
break;
case V_100 :
if ( V_92 & ( ( T_1 ) 1 << V_101 ) )
V_91 -> V_17 |= V_98 | V_99 ;
break;
case V_102 :
case V_103 :
case V_104 :
case V_105 :
case V_106 :
break;
case V_107 :
if ( V_92 & ( ( T_1 ) 1 << V_108 ) )
V_91 -> V_17 |= V_98 | V_99 ;
break;
case V_109 :
if ( V_92 & ( ( T_1 ) 1 << V_110 ) )
V_91 -> V_17 |= V_98 | V_99 ;
break;
case V_111 :
case V_112 :
case V_113 :
case V_114 :
case V_115 :
break;
default:
V_91 -> V_17 = 0 ;
return - V_14 ;
}
return 0 ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_90 * V_91 ,
T_2 * V_116 )
{
struct V_18 * V_19 = F_5 ( V_2 ) ;
int V_117 = - V_118 ;
switch ( V_91 -> V_91 ) {
case V_119 :
V_91 -> V_17 = V_19 -> V_26 ;
V_117 = 0 ;
break;
case V_120 :
V_117 = F_26 ( V_19 , V_91 ) ;
break;
default:
break;
}
return V_117 ;
}
static int F_30 ( struct V_18 * V_19 ,
struct V_90 * V_121 )
{
struct V_77 * V_35 = & V_19 -> V_35 ;
T_1 V_92 = ( T_1 ) F_27 ( V_35 , F_28 ( 0 ) ) |
( ( T_1 ) F_27 ( V_35 , F_28 ( 1 ) ) << 32 ) ;
if ( V_121 -> V_17 & ~ ( V_93 | V_94 |
V_98 | V_99 ) )
return - V_14 ;
if ( ! ( V_121 -> V_17 & V_93 ) ||
! ( V_121 -> V_17 & V_94 ) )
return - V_14 ;
switch ( V_121 -> V_95 ) {
case V_96 :
switch ( V_121 -> V_17 & ( V_98 | V_99 ) ) {
case 0 :
V_92 &= ~ ( ( T_1 ) 1 << V_97 ) ;
break;
case ( V_98 | V_99 ) :
V_92 |= ( ( T_1 ) 1 << V_97 ) ;
break;
default:
return - V_14 ;
}
break;
case V_107 :
switch ( V_121 -> V_17 & ( V_98 | V_99 ) ) {
case 0 :
V_92 &= ~ ( ( T_1 ) 1 << V_108 ) ;
break;
case ( V_98 | V_99 ) :
V_92 |= ( ( T_1 ) 1 << V_108 ) ;
break;
default:
return - V_14 ;
}
break;
case V_100 :
switch ( V_121 -> V_17 & ( V_98 | V_99 ) ) {
case 0 :
V_92 &= ~ ( ( ( T_1 ) 1 << V_101 ) |
( ( T_1 ) 1 << V_122 ) ) ;
break;
case ( V_98 | V_99 ) :
V_92 |= ( ( ( T_1 ) 1 << V_101 ) |
( ( T_1 ) 1 << V_122 ) ) ;
break;
default:
return - V_14 ;
}
break;
case V_109 :
switch ( V_121 -> V_17 & ( V_98 | V_99 ) ) {
case 0 :
V_92 &= ~ ( ( ( T_1 ) 1 << V_110 ) |
( ( T_1 ) 1 << V_123 ) ) ;
break;
case ( V_98 | V_99 ) :
V_92 |= ( ( ( T_1 ) 1 << V_110 ) |
( ( T_1 ) 1 << V_123 ) ) ;
break;
default:
return - V_14 ;
}
break;
case V_103 :
case V_104 :
case V_105 :
case V_102 :
if ( ( V_121 -> V_17 & V_98 ) ||
( V_121 -> V_17 & V_99 ) )
return - V_14 ;
V_92 |= ( ( T_1 ) 1 << V_124 ) ;
break;
case V_112 :
case V_113 :
case V_114 :
case V_111 :
if ( ( V_121 -> V_17 & V_98 ) ||
( V_121 -> V_17 & V_99 ) )
return - V_14 ;
V_92 |= ( ( T_1 ) 1 << V_125 ) ;
break;
case V_106 :
V_92 |= ( ( T_1 ) 1 << V_124 ) |
( ( T_1 ) 1 << V_122 ) ;
break;
case V_115 :
V_92 |= ( ( T_1 ) 1 << V_125 ) |
( ( T_1 ) 1 << V_123 ) ;
break;
default:
return - V_14 ;
}
F_23 ( V_35 , F_28 ( 0 ) , ( T_2 ) V_92 ) ;
F_23 ( V_35 , F_28 ( 1 ) , ( T_2 ) ( V_92 >> 32 ) ) ;
F_25 ( V_35 ) ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_90 * V_91 )
{
struct V_18 * V_19 = F_5 ( V_2 ) ;
int V_117 = - V_118 ;
switch ( V_91 -> V_91 ) {
case V_126 :
V_117 = F_30 ( V_19 , V_91 ) ;
break;
default:
break;
}
return V_117 ;
}
static void F_32 ( struct V_1 * V_2 ,
struct V_127 * V_128 )
{
struct V_18 * V_19 = F_5 ( V_2 ) ;
V_128 -> V_129 = V_19 -> V_26 ;
V_128 -> V_130 = V_86 ;
V_128 -> V_131 = V_86 ;
V_128 -> V_132 = V_19 -> V_26 ;
}
static T_2 F_33 ( struct V_1 * V_2 )
{
return ( V_133 + 1 ) * 4 ;
}
static int F_34 ( struct V_1 * V_2 , T_2 * V_134 , T_3 * V_135 ,
T_3 * V_136 )
{
struct V_18 * V_19 = F_5 ( V_2 ) ;
struct V_77 * V_35 = & V_19 -> V_35 ;
T_2 V_137 ;
int V_20 , V_21 ;
if ( V_136 )
* V_136 = V_138 ;
if ( ! V_134 )
return 0 ;
if ( V_134 ) {
for ( V_20 = 0 , V_21 = 0 ; V_20 <= V_133 ; V_20 ++ ) {
V_137 = F_27 ( V_35 , F_35 ( V_20 ) ) ;
V_134 [ V_21 ++ ] = V_137 & 0xff ;
V_134 [ V_21 ++ ] = ( V_137 >> 8 ) & 0xff ;
V_134 [ V_21 ++ ] = ( V_137 >> 16 ) & 0xff ;
V_134 [ V_21 ++ ] = ( V_137 >> 24 ) & 0xff ;
}
}
return 0 ;
}
static int F_36 ( struct V_1 * V_2 , const T_2 * V_134 ,
const T_3 * V_135 , const T_3 V_136 )
{
struct V_18 * V_19 = F_5 ( V_2 ) ;
struct V_77 * V_35 = & V_19 -> V_35 ;
T_2 V_137 ;
int V_20 , V_21 ;
if ( V_135 ||
( V_136 != V_139 && V_136 != V_138 ) )
return - V_118 ;
if ( ! V_134 )
return 0 ;
for ( V_20 = 0 , V_21 = 0 ; V_20 <= V_133 ; V_20 ++ ) {
V_137 = V_134 [ V_21 ++ ] ;
V_137 |= V_134 [ V_21 ++ ] << 8 ;
V_137 |= V_134 [ V_21 ++ ] << 16 ;
V_137 |= V_134 [ V_21 ++ ] << 24 ;
F_23 ( V_35 , F_35 ( V_20 ) , V_137 ) ;
}
return 0 ;
}
void F_37 ( struct V_1 * V_2 )
{
V_2 -> V_140 = & V_141 ;
}
