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
for ( V_21 = 0 ; V_21 < V_19 -> V_26 -> V_27 ; V_21 ++ ) {
V_17 [ V_20 ++ ] = V_19 -> V_28 [ V_21 ] -> V_16 . V_29 ;
V_17 [ V_20 ++ ] = V_19 -> V_28 [ V_21 ] -> V_16 . V_30 ;
}
for ( V_21 = 0 ; V_21 < V_19 -> V_26 -> V_27 ; V_21 ++ ) {
V_17 [ V_20 ++ ] = V_19 -> V_31 [ V_21 ] -> V_16 . V_29 ;
V_17 [ V_20 ++ ] = V_19 -> V_31 [ V_21 ] -> V_16 . V_30 ;
}
}
static void F_6 ( struct V_1 * V_2 , T_2 V_12 , T_3 * V_17 )
{
struct V_18 * V_19 = F_5 ( V_2 ) ;
T_3 * V_22 = V_17 ;
int V_20 ;
if ( V_12 == V_13 ) {
for ( V_20 = 0 ; V_20 < V_23 ; V_20 ++ ) {
memcpy ( V_22 , V_24 [ V_20 ] . V_32 ,
V_33 ) ;
V_22 += V_33 ;
}
for ( V_20 = 0 ; V_20 < V_19 -> V_26 -> V_27 ; V_20 ++ ) {
snprintf ( V_22 , V_33 , L_1 , V_20 ) ;
V_22 += V_33 ;
snprintf ( V_22 , V_33 , L_2 , V_20 ) ;
V_22 += V_33 ;
}
for ( V_20 = 0 ; V_20 < V_19 -> V_26 -> V_27 ; V_20 ++ ) {
snprintf ( V_22 , V_33 , L_3 , V_20 ) ;
V_22 += V_33 ;
snprintf ( V_22 , V_33 , L_4 , V_20 ) ;
V_22 += V_33 ;
}
}
}
static T_2 F_7 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = F_5 ( V_2 ) ;
return V_19 -> V_34 ;
}
static void F_8 ( struct V_1 * V_2 , T_2 V_17 )
{
struct V_18 * V_19 = F_5 ( V_2 ) ;
V_19 -> V_34 = V_17 ;
}
static void F_9 ( struct V_1 * V_2 ,
struct V_35 * V_36 )
{
struct V_18 * V_19 = F_5 ( V_2 ) ;
F_10 ( V_36 -> V_37 , V_38 , 32 ) ;
F_10 ( V_36 -> V_39 , V_40 , 32 ) ;
F_10 ( V_36 -> V_41 , F_11 ( V_19 -> V_42 ) , 32 ) ;
}
static void F_12 ( struct V_1 * V_2 ,
struct V_43 * V_44 )
{
struct V_18 * V_19 = F_5 ( V_2 ) ;
V_44 -> V_45 = V_46 ;
V_44 -> V_47 = V_48 ;
V_44 -> V_49 = V_19 -> V_50 ;
V_44 -> V_51 = V_19 -> V_52 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_43 * V_44 )
{
struct V_18 * V_19 = F_5 ( V_2 ) ;
T_2 V_53 , V_54 ;
if ( ( V_44 -> V_55 ) || ( V_44 -> V_56 ) )
return - V_14 ;
V_54 = F_14 ( T_2 , V_44 -> V_51 ,
V_57 ,
V_48 ) ;
V_54 = F_15 ( V_54 , V_58 ) ;
V_53 = F_14 ( T_2 , V_44 -> V_49 ,
V_59 ,
V_46 ) ;
V_53 = F_15 ( V_53 , V_58 ) ;
if ( ( V_54 == V_19 -> V_52 ) &&
( V_53 == V_19 -> V_50 ) )
return 0 ;
V_19 -> V_52 = V_54 ;
V_19 -> V_50 = V_53 ;
if ( F_16 ( V_2 ) )
F_17 ( V_19 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_60 * V_61 )
{
struct V_18 * V_19 = F_5 ( V_2 ) ;
struct V_62 * V_63 = & V_19 -> V_63 ;
V_61 -> V_64 = V_63 -> V_65 ;
V_61 -> V_66 = V_63 -> V_65 ;
if ( F_19 ( V_63 -> V_67 ) )
V_61 -> V_68 = 1 ;
if ( F_19 ( V_63 -> V_69 ) )
V_61 -> V_70 = 1 ;
V_61 -> V_71 = V_63 -> V_67 & ~ V_72 ;
V_61 -> V_73 = V_63 -> V_69 & ~ V_72 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_60 * V_61 )
{
struct V_18 * V_19 = F_5 ( V_2 ) ;
struct V_74 * V_75 = & V_19 -> V_75 ;
struct V_62 * V_63 = & V_19 -> V_63 ;
struct V_76 * V_77 ;
int V_20 ;
if ( V_61 -> V_78 || V_61 -> V_79 )
V_63 -> V_65 = V_61 -> V_78 ;
if ( ( V_61 -> V_71 >= ( V_80 << 1 ) ) &&
( V_61 -> V_71 <= ( V_81 << 1 ) ) )
V_63 -> V_67 = V_61 -> V_71 ;
else
return - V_14 ;
if ( ( V_61 -> V_73 >= ( V_80 << 1 ) ) &&
( V_61 -> V_73 <= ( V_81 << 1 ) ) )
V_63 -> V_69 = V_61 -> V_73 ;
else if ( V_61 -> V_70 )
V_63 -> V_69 = ( V_72 |
F_21 ( V_82 ) ) ;
else
return - V_14 ;
if ( V_61 -> V_68 )
V_63 -> V_67 |= V_72 ;
else
V_63 -> V_67 &= ~ V_72 ;
if ( V_61 -> V_70 )
V_63 -> V_69 |= V_72 ;
else
V_63 -> V_69 &= ~ V_72 ;
for ( V_20 = 0 ; V_20 < V_19 -> V_83 - V_84 ; V_20 ++ ) {
V_77 = V_19 -> V_77 [ V_20 ] ;
V_77 -> V_85 . V_86 = F_22 ( V_63 -> V_67 ) ;
F_23 ( V_75 , F_24 ( 0 , V_20 ) , V_77 -> V_85 . V_86 ) ;
V_77 -> V_87 . V_86 = F_22 ( V_63 -> V_69 ) ;
F_23 ( V_75 , F_24 ( 1 , V_20 ) , V_77 -> V_87 . V_86 ) ;
F_25 ( V_75 ) ;
}
return 0 ;
}
static int F_26 ( struct V_18 * V_19 ,
struct V_88 * V_89 )
{
struct V_74 * V_75 = & V_19 -> V_75 ;
T_1 V_90 = ( T_1 ) F_27 ( V_75 , F_28 ( 0 ) ) |
( ( T_1 ) F_27 ( V_75 , F_28 ( 1 ) ) << 32 ) ;
V_89 -> V_17 = V_91 | V_92 ;
switch ( V_89 -> V_93 ) {
case V_94 :
if ( V_90 & ( ( T_1 ) 1 << V_95 ) )
V_89 -> V_17 |= V_96 | V_97 ;
break;
case V_98 :
if ( V_90 & ( ( T_1 ) 1 << V_99 ) )
V_89 -> V_17 |= V_96 | V_97 ;
break;
case V_100 :
case V_101 :
case V_102 :
case V_103 :
case V_104 :
break;
case V_105 :
if ( V_90 & ( ( T_1 ) 1 << V_106 ) )
V_89 -> V_17 |= V_96 | V_97 ;
break;
case V_107 :
if ( V_90 & ( ( T_1 ) 1 << V_108 ) )
V_89 -> V_17 |= V_96 | V_97 ;
break;
case V_109 :
case V_110 :
case V_111 :
case V_112 :
case V_113 :
break;
default:
V_89 -> V_17 = 0 ;
return - V_14 ;
}
return 0 ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_88 * V_89 ,
T_2 * V_114 )
{
struct V_18 * V_19 = F_5 ( V_2 ) ;
int V_115 = - V_116 ;
switch ( V_89 -> V_89 ) {
case V_117 :
V_89 -> V_17 = V_19 -> V_26 -> V_27 ;
V_115 = 0 ;
break;
case V_118 :
V_115 = F_26 ( V_19 , V_89 ) ;
break;
default:
break;
}
return V_115 ;
}
static int F_30 ( struct V_18 * V_19 ,
struct V_88 * V_119 )
{
struct V_74 * V_75 = & V_19 -> V_75 ;
T_1 V_90 = ( T_1 ) F_27 ( V_75 , F_28 ( 0 ) ) |
( ( T_1 ) F_27 ( V_75 , F_28 ( 1 ) ) << 32 ) ;
if ( V_119 -> V_17 & ~ ( V_91 | V_92 |
V_96 | V_97 ) )
return - V_14 ;
if ( ! ( V_119 -> V_17 & V_91 ) ||
! ( V_119 -> V_17 & V_92 ) )
return - V_14 ;
switch ( V_119 -> V_93 ) {
case V_94 :
switch ( V_119 -> V_17 & ( V_96 | V_97 ) ) {
case 0 :
V_90 &= ~ ( ( T_1 ) 1 << V_95 ) ;
break;
case ( V_96 | V_97 ) :
V_90 |= ( ( T_1 ) 1 << V_95 ) ;
break;
default:
return - V_14 ;
}
break;
case V_105 :
switch ( V_119 -> V_17 & ( V_96 | V_97 ) ) {
case 0 :
V_90 &= ~ ( ( T_1 ) 1 << V_106 ) ;
break;
case ( V_96 | V_97 ) :
V_90 |= ( ( T_1 ) 1 << V_106 ) ;
break;
default:
return - V_14 ;
}
break;
case V_98 :
switch ( V_119 -> V_17 & ( V_96 | V_97 ) ) {
case 0 :
V_90 &= ~ ( ( ( T_1 ) 1 << V_99 ) |
( ( T_1 ) 1 << V_120 ) ) ;
break;
case ( V_96 | V_97 ) :
V_90 |= ( ( ( T_1 ) 1 << V_99 ) |
( ( T_1 ) 1 << V_120 ) ) ;
break;
default:
return - V_14 ;
}
break;
case V_107 :
switch ( V_119 -> V_17 & ( V_96 | V_97 ) ) {
case 0 :
V_90 &= ~ ( ( ( T_1 ) 1 << V_108 ) |
( ( T_1 ) 1 << V_121 ) ) ;
break;
case ( V_96 | V_97 ) :
V_90 |= ( ( ( T_1 ) 1 << V_108 ) |
( ( T_1 ) 1 << V_121 ) ) ;
break;
default:
return - V_14 ;
}
break;
case V_101 :
case V_102 :
case V_103 :
case V_100 :
if ( ( V_119 -> V_17 & V_96 ) ||
( V_119 -> V_17 & V_97 ) )
return - V_14 ;
V_90 |= ( ( T_1 ) 1 << V_122 ) ;
break;
case V_110 :
case V_111 :
case V_112 :
case V_109 :
if ( ( V_119 -> V_17 & V_96 ) ||
( V_119 -> V_17 & V_97 ) )
return - V_14 ;
V_90 |= ( ( T_1 ) 1 << V_123 ) ;
break;
case V_104 :
V_90 |= ( ( T_1 ) 1 << V_122 ) |
( ( T_1 ) 1 << V_120 ) ;
break;
case V_113 :
V_90 |= ( ( T_1 ) 1 << V_123 ) |
( ( T_1 ) 1 << V_121 ) ;
break;
default:
return - V_14 ;
}
F_23 ( V_75 , F_28 ( 0 ) , ( T_2 ) V_90 ) ;
F_23 ( V_75 , F_28 ( 1 ) , ( T_2 ) ( V_90 >> 32 ) ) ;
F_25 ( V_75 ) ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_88 * V_89 )
{
struct V_18 * V_19 = F_5 ( V_2 ) ;
int V_115 = - V_116 ;
switch ( V_89 -> V_89 ) {
case V_124 :
V_115 = F_30 ( V_19 , V_89 ) ;
break;
default:
break;
}
return V_115 ;
}
static void F_32 ( struct V_1 * V_2 ,
struct V_125 * V_126 )
{
struct V_18 * V_19 = F_5 ( V_2 ) ;
V_126 -> V_127 = V_19 -> V_26 -> V_27 ;
V_126 -> V_128 = V_84 ;
V_126 -> V_129 = V_84 ;
V_126 -> V_130 = V_19 -> V_26 -> V_27 ;
}
static T_2 F_33 ( struct V_1 * V_2 )
{
return ( V_131 + 1 ) * 4 ;
}
static int F_34 ( struct V_1 * V_2 , T_2 * V_132 , T_3 * V_133 )
{
struct V_18 * V_19 = F_5 ( V_2 ) ;
struct V_74 * V_75 = & V_19 -> V_75 ;
T_2 V_134 ;
int V_20 , V_21 ;
for ( V_20 = 0 , V_21 = 0 ; V_20 <= V_131 ; V_20 ++ ) {
V_134 = F_27 ( V_75 , F_35 ( V_20 ) ) ;
V_132 [ V_21 ++ ] = V_134 & 0xff ;
V_132 [ V_21 ++ ] = ( V_134 >> 8 ) & 0xff ;
V_132 [ V_21 ++ ] = ( V_134 >> 16 ) & 0xff ;
V_132 [ V_21 ++ ] = ( V_134 >> 24 ) & 0xff ;
}
return 0 ;
}
static int F_36 ( struct V_1 * V_2 , const T_2 * V_132 ,
const T_3 * V_133 )
{
struct V_18 * V_19 = F_5 ( V_2 ) ;
struct V_74 * V_75 = & V_19 -> V_75 ;
T_2 V_134 ;
int V_20 , V_21 ;
for ( V_20 = 0 , V_21 = 0 ; V_20 <= V_131 ; V_20 ++ ) {
V_134 = V_132 [ V_21 ++ ] ;
V_134 |= V_132 [ V_21 ++ ] << 8 ;
V_134 |= V_132 [ V_21 ++ ] << 16 ;
V_134 |= V_132 [ V_21 ++ ] << 24 ;
F_23 ( V_75 , F_35 ( V_20 ) , V_134 ) ;
}
return 0 ;
}
void F_37 ( struct V_1 * V_2 )
{
V_2 -> V_135 = & V_136 ;
}
