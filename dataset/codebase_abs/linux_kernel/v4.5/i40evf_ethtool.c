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
V_17 [ V_20 ++ ] = V_19 -> V_27 [ V_21 ] . V_16 . V_28 ;
V_17 [ V_20 ++ ] = V_19 -> V_27 [ V_21 ] . V_16 . V_29 ;
}
for ( V_21 = 0 ; V_21 < V_19 -> V_26 ; V_21 ++ ) {
V_17 [ V_20 ++ ] = V_19 -> V_30 [ V_21 ] . V_16 . V_28 ;
V_17 [ V_20 ++ ] = V_19 -> V_30 [ V_21 ] . V_16 . V_29 ;
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
if ( F_16 ( V_2 ) ) {
V_19 -> V_63 |= V_64 ;
F_17 ( & V_19 -> V_65 ) ;
}
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_66 * V_67 )
{
struct V_18 * V_19 = F_5 ( V_2 ) ;
struct V_68 * V_69 = & V_19 -> V_69 ;
V_67 -> V_70 = V_69 -> V_71 ;
V_67 -> V_72 = V_69 -> V_71 ;
if ( F_19 ( V_69 -> V_73 ) )
V_67 -> V_74 = 1 ;
if ( F_19 ( V_69 -> V_75 ) )
V_67 -> V_76 = 1 ;
V_67 -> V_77 = V_69 -> V_73 & ~ V_78 ;
V_67 -> V_79 = V_69 -> V_75 & ~ V_78 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_66 * V_67 )
{
struct V_18 * V_19 = F_5 ( V_2 ) ;
struct V_80 * V_35 = & V_19 -> V_35 ;
struct V_68 * V_69 = & V_19 -> V_69 ;
struct V_81 * V_82 ;
int V_20 ;
if ( V_67 -> V_83 || V_67 -> V_84 )
V_69 -> V_71 = V_67 -> V_83 ;
if ( ( V_67 -> V_77 >= ( V_85 << 1 ) ) &&
( V_67 -> V_77 <= ( V_86 << 1 ) ) )
V_69 -> V_73 = V_67 -> V_77 ;
else
return - V_14 ;
if ( ( V_67 -> V_79 >= ( V_85 << 1 ) ) &&
( V_67 -> V_79 <= ( V_86 << 1 ) ) )
V_69 -> V_75 = V_67 -> V_79 ;
else if ( V_67 -> V_76 )
V_69 -> V_75 = ( V_78 |
F_21 ( V_87 ) ) ;
else
return - V_14 ;
if ( V_67 -> V_74 )
V_69 -> V_73 |= V_78 ;
else
V_69 -> V_73 &= ~ V_78 ;
if ( V_67 -> V_76 )
V_69 -> V_75 |= V_78 ;
else
V_69 -> V_75 &= ~ V_78 ;
for ( V_20 = 0 ; V_20 < V_19 -> V_88 - V_89 ; V_20 ++ ) {
V_82 = & V_19 -> V_90 [ V_20 ] ;
V_82 -> V_91 . V_92 = F_22 ( V_69 -> V_73 ) ;
F_23 ( V_35 , F_24 ( 0 , V_20 ) , V_82 -> V_91 . V_92 ) ;
V_82 -> V_93 . V_92 = F_22 ( V_69 -> V_75 ) ;
F_23 ( V_35 , F_24 ( 1 , V_20 ) , V_82 -> V_93 . V_92 ) ;
F_25 ( V_35 ) ;
}
return 0 ;
}
static int F_26 ( struct V_18 * V_19 ,
struct V_94 * V_95 )
{
struct V_80 * V_35 = & V_19 -> V_35 ;
T_1 V_96 = ( T_1 ) F_27 ( V_35 , F_28 ( 0 ) ) |
( ( T_1 ) F_27 ( V_35 , F_28 ( 1 ) ) << 32 ) ;
V_95 -> V_17 = V_97 | V_98 ;
switch ( V_95 -> V_99 ) {
case V_100 :
if ( V_96 & F_29 ( V_101 ) )
V_95 -> V_17 |= V_102 | V_103 ;
break;
case V_104 :
if ( V_96 & F_29 ( V_105 ) )
V_95 -> V_17 |= V_102 | V_103 ;
break;
case V_106 :
case V_107 :
case V_108 :
case V_109 :
case V_110 :
break;
case V_111 :
if ( V_96 & F_29 ( V_112 ) )
V_95 -> V_17 |= V_102 | V_103 ;
break;
case V_113 :
if ( V_96 & F_29 ( V_114 ) )
V_95 -> V_17 |= V_102 | V_103 ;
break;
case V_115 :
case V_116 :
case V_117 :
case V_118 :
case V_119 :
break;
default:
V_95 -> V_17 = 0 ;
return - V_14 ;
}
return 0 ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_94 * V_95 ,
T_2 * V_120 )
{
struct V_18 * V_19 = F_5 ( V_2 ) ;
int V_121 = - V_122 ;
switch ( V_95 -> V_95 ) {
case V_123 :
V_95 -> V_17 = V_19 -> V_26 ;
V_121 = 0 ;
break;
case V_124 :
V_121 = F_26 ( V_19 , V_95 ) ;
break;
default:
break;
}
return V_121 ;
}
static int F_31 ( struct V_18 * V_19 ,
struct V_94 * V_125 )
{
struct V_80 * V_35 = & V_19 -> V_35 ;
T_1 V_96 = ( T_1 ) F_27 ( V_35 , F_28 ( 0 ) ) |
( ( T_1 ) F_27 ( V_35 , F_28 ( 1 ) ) << 32 ) ;
if ( V_125 -> V_17 & ~ ( V_97 | V_98 |
V_102 | V_103 ) )
return - V_14 ;
if ( ! ( V_125 -> V_17 & V_97 ) ||
! ( V_125 -> V_17 & V_98 ) )
return - V_14 ;
switch ( V_125 -> V_99 ) {
case V_100 :
switch ( V_125 -> V_17 & ( V_102 | V_103 ) ) {
case 0 :
V_96 &= ~ F_29 ( V_101 ) ;
break;
case ( V_102 | V_103 ) :
V_96 |= F_29 ( V_101 ) ;
break;
default:
return - V_14 ;
}
break;
case V_111 :
switch ( V_125 -> V_17 & ( V_102 | V_103 ) ) {
case 0 :
V_96 &= ~ F_29 ( V_112 ) ;
break;
case ( V_102 | V_103 ) :
V_96 |= F_29 ( V_112 ) ;
break;
default:
return - V_14 ;
}
break;
case V_104 :
switch ( V_125 -> V_17 & ( V_102 | V_103 ) ) {
case 0 :
V_96 &= ~ ( F_29 ( V_105 ) |
F_29 ( V_126 ) ) ;
break;
case ( V_102 | V_103 ) :
V_96 |= ( F_29 ( V_105 ) |
F_29 ( V_126 ) ) ;
break;
default:
return - V_14 ;
}
break;
case V_113 :
switch ( V_125 -> V_17 & ( V_102 | V_103 ) ) {
case 0 :
V_96 &= ~ ( F_29 ( V_114 ) |
F_29 ( V_127 ) ) ;
break;
case ( V_102 | V_103 ) :
V_96 |= ( F_29 ( V_114 ) |
F_29 ( V_127 ) ) ;
break;
default:
return - V_14 ;
}
break;
case V_107 :
case V_108 :
case V_109 :
case V_106 :
if ( ( V_125 -> V_17 & V_102 ) ||
( V_125 -> V_17 & V_103 ) )
return - V_14 ;
V_96 |= F_29 ( V_128 ) ;
break;
case V_116 :
case V_117 :
case V_118 :
case V_115 :
if ( ( V_125 -> V_17 & V_102 ) ||
( V_125 -> V_17 & V_103 ) )
return - V_14 ;
V_96 |= F_29 ( V_129 ) ;
break;
case V_110 :
V_96 |= ( F_29 ( V_128 ) |
F_29 ( V_126 ) ) ;
break;
case V_119 :
V_96 |= ( F_29 ( V_129 ) |
F_29 ( V_127 ) ) ;
break;
default:
return - V_14 ;
}
F_23 ( V_35 , F_28 ( 0 ) , ( T_2 ) V_96 ) ;
F_23 ( V_35 , F_28 ( 1 ) , ( T_2 ) ( V_96 >> 32 ) ) ;
F_25 ( V_35 ) ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_94 * V_95 )
{
struct V_18 * V_19 = F_5 ( V_2 ) ;
int V_121 = - V_122 ;
switch ( V_95 -> V_95 ) {
case V_130 :
V_121 = F_31 ( V_19 , V_95 ) ;
break;
default:
break;
}
return V_121 ;
}
static void F_33 ( struct V_1 * V_2 ,
struct V_131 * V_132 )
{
struct V_18 * V_19 = F_5 ( V_2 ) ;
V_132 -> V_133 = V_19 -> V_26 ;
V_132 -> V_134 = V_89 ;
V_132 -> V_135 = V_89 ;
V_132 -> V_136 = V_19 -> V_26 ;
}
static T_2 F_34 ( struct V_1 * V_2 )
{
return ( V_137 + 1 ) * 4 ;
}
static int F_35 ( struct V_1 * V_2 , T_2 * V_138 , T_3 * V_139 ,
T_3 * V_140 )
{
struct V_18 * V_19 = F_5 ( V_2 ) ;
struct V_68 * V_69 = & V_19 -> V_69 ;
T_3 * V_141 = NULL , * V_142 ;
int V_121 ;
T_4 V_20 ;
if ( V_140 )
* V_140 = V_143 ;
if ( ! V_138 )
return 0 ;
V_141 = V_139 ;
V_142 = F_36 ( V_144 , V_145 ) ;
if ( ! V_142 )
return - V_146 ;
V_121 = F_37 ( V_69 , V_141 , V_142 , V_144 ) ;
if ( V_121 )
goto V_147;
for ( V_20 = 0 ; V_20 < V_144 ; V_20 ++ )
V_138 [ V_20 ] = ( T_2 ) V_142 [ V_20 ] ;
V_147:
F_38 ( V_142 ) ;
return V_121 ;
}
static int F_39 ( struct V_1 * V_2 , const T_2 * V_138 ,
const T_3 * V_139 , const T_3 V_140 )
{
struct V_18 * V_19 = F_5 ( V_2 ) ;
struct V_68 * V_69 = & V_19 -> V_69 ;
T_3 * V_141 = NULL ;
T_4 V_20 ;
if ( V_139 ||
( V_140 != V_148 && V_140 != V_143 ) )
return - V_122 ;
if ( ! V_138 )
return 0 ;
if ( V_139 ) {
if ( ! V_69 -> V_149 ) {
V_69 -> V_149 = F_36 ( V_150 ,
V_145 ) ;
if ( ! V_69 -> V_149 )
return - V_146 ;
}
memcpy ( V_69 -> V_149 , V_139 , V_150 ) ;
V_141 = V_69 -> V_149 ;
}
if ( ! V_69 -> V_151 ) {
V_69 -> V_151 = F_36 ( V_144 ,
V_145 ) ;
if ( ! V_69 -> V_151 )
return - V_146 ;
}
for ( V_20 = 0 ; V_20 < V_144 ; V_20 ++ )
V_69 -> V_151 [ V_20 ] = ( T_3 ) ( V_138 [ V_20 ] ) ;
return F_40 ( V_69 , V_141 , V_69 -> V_151 ,
V_144 ) ;
}
void F_41 ( struct V_1 * V_2 )
{
V_2 -> V_152 = & V_153 ;
}
