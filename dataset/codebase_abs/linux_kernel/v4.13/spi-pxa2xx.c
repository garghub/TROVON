static inline const struct V_1
* F_1 ( const struct V_2 * V_3 )
{
return & V_4 [ V_3 -> V_5 - V_6 ] ;
}
static bool F_2 ( const struct V_2 * V_3 )
{
switch ( V_3 -> V_5 ) {
case V_6 :
case V_7 :
case V_8 :
case V_9 :
case V_10 :
case V_11 :
return true ;
default:
return false ;
}
}
static bool F_3 ( const struct V_2 * V_3 )
{
return V_3 -> V_5 == V_12 ;
}
static T_1 F_4 ( const struct V_2 * V_3 )
{
switch ( V_3 -> V_5 ) {
case V_12 :
return V_13 ;
case V_14 :
return V_15 ;
default:
return V_16 ;
}
}
static T_1
F_5 ( const struct V_2 * V_3 )
{
switch ( V_3 -> V_5 ) {
case V_12 :
return V_17 ;
case V_14 :
return V_18 ;
default:
return V_19 ;
}
}
static bool F_6 ( const struct V_2 * V_3 )
{
T_1 V_20 ;
switch ( V_3 -> V_5 ) {
case V_12 :
V_20 = V_21 ;
break;
case V_14 :
V_20 = V_22 ;
break;
default:
V_20 = V_23 ;
break;
}
return ( F_7 ( V_3 , V_24 ) & V_20 ) == V_20 ;
}
static void F_8 ( const struct V_2 * V_3 ,
T_1 * V_25 )
{
T_1 V_20 ;
switch ( V_3 -> V_5 ) {
case V_12 :
V_20 = V_26 ;
break;
case V_14 :
V_20 = V_27 ;
break;
default:
V_20 = V_28 ;
break;
}
* V_25 &= ~ V_20 ;
}
static void F_9 ( const struct V_2 * V_3 ,
T_1 * V_25 , T_1 V_29 )
{
switch ( V_3 -> V_5 ) {
case V_12 :
* V_25 |= F_10 ( V_29 ) ;
break;
case V_14 :
* V_25 |= F_11 ( V_29 ) ;
break;
default:
* V_25 |= F_12 ( V_29 ) ;
break;
}
}
static T_1 F_13 ( const struct V_2 * V_3 ,
T_1 V_30 , T_2 V_31 )
{
switch ( V_3 -> V_5 ) {
case V_12 :
return V_30
| V_32
| F_14 ( V_31 > 32 ? 8 : V_31 )
| V_33 ;
default:
return V_30
| V_34
| F_15 ( V_31 > 16 ? V_31 - 16 : V_31 )
| V_33
| ( V_31 > 16 ? V_35 : 0 ) ;
}
}
static T_1 F_16 ( struct V_2 * V_3 , unsigned V_36 )
{
F_17 ( ! V_3 -> V_37 ) ;
return F_18 ( V_3 -> V_37 + V_36 ) ;
}
static void F_19 ( struct V_2 * V_3 ,
unsigned V_36 , T_1 V_38 )
{
F_17 ( ! V_3 -> V_37 ) ;
F_20 ( V_38 , V_3 -> V_37 + V_36 ) ;
}
static void F_21 ( struct V_2 * V_3 )
{
const struct V_1 * V_39 ;
T_1 V_38 ;
V_39 = F_1 ( V_3 ) ;
V_3 -> V_37 = V_3 -> V_40 + V_39 -> V_36 ;
V_38 = F_16 ( V_3 , V_39 -> V_41 ) ;
V_38 &= ~ ( V_42 | V_43 ) ;
V_38 |= V_42 | V_43 ;
F_19 ( V_3 , V_39 -> V_41 , V_38 ) ;
if ( V_3 -> V_44 -> V_45 ) {
F_19 ( V_3 , V_39 -> V_46 , 1 ) ;
if ( V_39 -> V_47 >= 0 ) {
V_38 = F_16 ( V_3 ,
V_39 -> V_47 ) ;
V_38 |= V_48 ;
F_19 ( V_3 ,
V_39 -> V_47 , V_38 ) ;
}
}
}
static void F_22 ( struct V_2 * V_3 ,
const struct V_1 * V_39 )
{
T_1 V_38 , V_49 ;
if ( ! V_39 -> V_50 )
return;
V_38 = F_16 ( V_3 , V_39 -> V_41 ) ;
V_49 = V_3 -> V_51 -> V_52 -> V_53 -> V_54 ;
V_49 <<= V_39 -> V_55 ;
if ( V_49 != ( V_38 & V_39 -> V_50 ) ) {
V_38 &= ~ V_39 -> V_50 ;
V_38 |= V_49 ;
F_19 ( V_3 ,
V_39 -> V_41 , V_38 ) ;
F_23 ( 1000000000 /
( V_3 -> V_51 -> V_56 / 2 ) ) ;
}
}
static void F_24 ( struct V_2 * V_3 , bool V_57 )
{
const struct V_1 * V_39 ;
T_1 V_38 ;
V_39 = F_1 ( V_3 ) ;
if ( V_57 )
F_22 ( V_3 , V_39 ) ;
V_38 = F_16 ( V_3 , V_39 -> V_41 ) ;
if ( V_57 )
V_38 &= ~ V_43 ;
else
V_38 |= V_43 ;
F_19 ( V_3 , V_39 -> V_41 , V_38 ) ;
}
static void F_25 ( struct V_2 * V_3 )
{
struct V_58 * V_59 =
F_26 ( V_3 -> V_51 -> V_52 -> V_53 ) ;
if ( V_3 -> V_5 == V_14 ) {
F_27 ( V_3 , V_24 , V_59 -> V_60 ) ;
return;
}
if ( V_59 -> V_61 ) {
V_59 -> V_61 ( V_62 ) ;
return;
}
if ( F_28 ( V_59 -> V_63 ) ) {
F_29 ( V_59 -> V_63 , V_59 -> V_64 ) ;
return;
}
if ( F_2 ( V_3 ) )
F_24 ( V_3 , true ) ;
}
static void F_30 ( struct V_2 * V_3 )
{
struct V_58 * V_59 =
F_26 ( V_3 -> V_51 -> V_52 -> V_53 ) ;
if ( V_3 -> V_5 == V_14 )
return;
if ( V_59 -> V_61 ) {
V_59 -> V_61 ( V_65 ) ;
return;
}
if ( F_28 ( V_59 -> V_63 ) ) {
F_29 ( V_59 -> V_63 , ! V_59 -> V_64 ) ;
return;
}
if ( F_2 ( V_3 ) )
F_24 ( V_3 , false ) ;
}
int F_31 ( struct V_2 * V_3 )
{
unsigned long V_66 = V_67 << 1 ;
do {
while ( F_7 ( V_3 , V_24 ) & V_68 )
F_7 ( V_3 , V_69 ) ;
} while ( ( F_7 ( V_3 , V_24 ) & V_70 ) && -- V_66 );
F_32 ( V_3 , V_71 ) ;
return V_66 ;
}
static int F_33 ( struct V_2 * V_3 )
{
T_2 V_72 = V_3 -> V_72 ;
if ( F_6 ( V_3 )
|| ( V_3 -> V_73 == V_3 -> V_74 ) )
return 0 ;
F_27 ( V_3 , V_69 , 0 ) ;
V_3 -> V_73 += V_72 ;
return 1 ;
}
static int F_34 ( struct V_2 * V_3 )
{
T_2 V_72 = V_3 -> V_72 ;
while ( ( F_7 ( V_3 , V_24 ) & V_68 )
&& ( V_3 -> V_75 < V_3 -> V_76 ) ) {
F_7 ( V_3 , V_69 ) ;
V_3 -> V_75 += V_72 ;
}
return V_3 -> V_75 == V_3 -> V_76 ;
}
static int F_35 ( struct V_2 * V_3 )
{
if ( F_6 ( V_3 )
|| ( V_3 -> V_73 == V_3 -> V_74 ) )
return 0 ;
F_27 ( V_3 , V_69 , * ( T_2 * ) ( V_3 -> V_73 ) ) ;
++ V_3 -> V_73 ;
return 1 ;
}
static int F_36 ( struct V_2 * V_3 )
{
while ( ( F_7 ( V_3 , V_24 ) & V_68 )
&& ( V_3 -> V_75 < V_3 -> V_76 ) ) {
* ( T_2 * ) ( V_3 -> V_75 ) = F_7 ( V_3 , V_69 ) ;
++ V_3 -> V_75 ;
}
return V_3 -> V_75 == V_3 -> V_76 ;
}
static int F_37 ( struct V_2 * V_3 )
{
if ( F_6 ( V_3 )
|| ( V_3 -> V_73 == V_3 -> V_74 ) )
return 0 ;
F_27 ( V_3 , V_69 , * ( V_77 * ) ( V_3 -> V_73 ) ) ;
V_3 -> V_73 += 2 ;
return 1 ;
}
static int F_38 ( struct V_2 * V_3 )
{
while ( ( F_7 ( V_3 , V_24 ) & V_68 )
&& ( V_3 -> V_75 < V_3 -> V_76 ) ) {
* ( V_77 * ) ( V_3 -> V_75 ) = F_7 ( V_3 , V_69 ) ;
V_3 -> V_75 += 2 ;
}
return V_3 -> V_75 == V_3 -> V_76 ;
}
static int F_39 ( struct V_2 * V_3 )
{
if ( F_6 ( V_3 )
|| ( V_3 -> V_73 == V_3 -> V_74 ) )
return 0 ;
F_27 ( V_3 , V_69 , * ( T_1 * ) ( V_3 -> V_73 ) ) ;
V_3 -> V_73 += 4 ;
return 1 ;
}
static int F_40 ( struct V_2 * V_3 )
{
while ( ( F_7 ( V_3 , V_24 ) & V_68 )
&& ( V_3 -> V_75 < V_3 -> V_76 ) ) {
* ( T_1 * ) ( V_3 -> V_75 ) = F_7 ( V_3 , V_69 ) ;
V_3 -> V_75 += 4 ;
}
return V_3 -> V_75 == V_3 -> V_76 ;
}
void * F_41 ( struct V_2 * V_3 )
{
struct V_78 * V_79 = V_3 -> V_51 -> V_52 ;
struct V_80 * V_81 = V_3 -> V_82 ;
if ( V_81 -> V_83 . V_84 != & V_79 -> V_85 ) {
V_3 -> V_82 =
F_42 ( V_81 -> V_83 . V_84 ,
struct V_80 ,
V_83 ) ;
return V_86 ;
} else
return V_87 ;
}
static void F_43 ( struct V_2 * V_3 )
{
struct V_80 * V_88 ;
struct V_78 * V_79 ;
unsigned long V_89 ;
V_79 = V_3 -> V_51 -> V_52 ;
V_3 -> V_82 = NULL ;
V_88 = F_44 ( & V_79 -> V_85 , struct V_80 ,
V_83 ) ;
if ( V_88 -> V_90 )
F_45 ( V_88 -> V_90 ) ;
V_89 = V_91 + F_46 ( 10 ) ;
while ( F_7 ( V_3 , V_24 ) & V_70 &&
! F_47 ( V_91 , V_89 ) )
F_48 () ;
if ( ! V_88 -> V_92 )
F_30 ( V_3 ) ;
else {
struct V_78 * V_93 ;
V_93 = F_49 ( V_3 -> V_51 ) ;
if ( ( V_93 && V_93 -> V_53 != V_79 -> V_53 ) ||
V_79 -> V_94 == V_95 )
F_30 ( V_3 ) ;
}
F_50 ( V_3 -> V_51 ) ;
}
static void F_51 ( struct V_2 * V_3 )
{
struct V_58 * V_59 =
F_26 ( V_3 -> V_51 -> V_52 -> V_53 ) ;
T_1 V_25 ;
V_25 = F_7 ( V_3 , V_96 ) & ~ V_3 -> V_97 ;
switch ( V_3 -> V_5 ) {
case V_12 :
V_25 &= ~ V_26 ;
break;
case V_14 :
V_25 &= ~ V_27 ;
break;
default:
V_25 &= ~ V_28 ;
break;
}
V_25 |= V_59 -> V_29 ;
F_27 ( V_3 , V_96 , V_25 ) ;
}
static void F_52 ( struct V_2 * V_3 , const char * V_79 )
{
F_32 ( V_3 , V_3 -> V_98 ) ;
F_51 ( V_3 ) ;
if ( ! F_53 ( V_3 ) )
F_27 ( V_3 , V_99 , 0 ) ;
F_31 ( V_3 ) ;
F_27 ( V_3 , V_100 ,
F_7 ( V_3 , V_100 ) & ~ V_33 ) ;
F_54 ( & V_3 -> V_101 -> V_102 , L_1 , V_79 ) ;
V_3 -> V_51 -> V_52 -> V_94 = V_95 ;
F_55 ( & V_3 -> V_103 ) ;
}
static void F_56 ( struct V_2 * V_3 )
{
F_32 ( V_3 , V_3 -> V_98 ) ;
F_51 ( V_3 ) ;
if ( ! F_53 ( V_3 ) )
F_27 ( V_3 , V_99 , 0 ) ;
V_3 -> V_51 -> V_52 -> V_104 += V_3 -> V_105 -
( V_3 -> V_76 - V_3 -> V_75 ) ;
V_3 -> V_51 -> V_52 -> V_94 = F_41 ( V_3 ) ;
F_55 ( & V_3 -> V_103 ) ;
}
static T_3 F_57 ( struct V_2 * V_3 )
{
T_1 V_106 = ( F_7 ( V_3 , V_96 ) & V_107 ) ?
V_3 -> V_108 : V_3 -> V_108 & ~ V_109 ;
T_1 V_110 = F_7 ( V_3 , V_24 ) & V_106 ;
if ( V_110 & V_71 ) {
F_52 ( V_3 , L_2 ) ;
return V_111 ;
}
if ( V_110 & V_112 ) {
F_27 ( V_3 , V_24 , V_112 ) ;
if ( V_3 -> V_113 ( V_3 ) ) {
F_56 ( V_3 ) ;
return V_111 ;
}
}
do {
if ( V_3 -> V_113 ( V_3 ) ) {
F_56 ( V_3 ) ;
return V_111 ;
}
} while ( V_3 -> V_114 ( V_3 ) );
if ( V_3 -> V_113 ( V_3 ) ) {
F_56 ( V_3 ) ;
return V_111 ;
}
if ( V_3 -> V_73 == V_3 -> V_74 ) {
T_1 V_115 ;
T_1 V_25 ;
V_25 = F_7 ( V_3 , V_96 ) ;
V_25 &= ~ V_107 ;
if ( F_53 ( V_3 ) ) {
T_1 V_116 ;
F_8 ( V_3 , & V_25 ) ;
V_115 = V_3 -> V_76 - V_3 -> V_75 ;
switch ( V_3 -> V_72 ) {
case 4 :
V_115 >>= 1 ;
case 2 :
V_115 >>= 1 ;
}
V_116 = F_5 ( V_3 ) ;
if ( V_116 > V_115 )
V_116 = V_115 ;
F_9 ( V_3 , & V_25 , V_116 ) ;
}
F_27 ( V_3 , V_96 , V_25 ) ;
}
return V_111 ;
}
static void F_58 ( struct V_2 * V_3 )
{
F_27 ( V_3 , V_100 ,
F_7 ( V_3 , V_100 ) & ~ V_33 ) ;
F_27 ( V_3 , V_96 ,
F_7 ( V_3 , V_96 ) & ~ V_3 -> V_97 ) ;
if ( ! F_53 ( V_3 ) )
F_27 ( V_3 , V_99 , 0 ) ;
F_32 ( V_3 , V_3 -> V_98 ) ;
F_54 ( & V_3 -> V_101 -> V_102 ,
L_3 ) ;
}
static T_3 F_59 ( int V_117 , void * V_118 )
{
struct V_2 * V_3 = V_118 ;
T_1 V_25 ;
T_1 V_20 = V_3 -> V_108 ;
T_1 V_119 ;
if ( F_60 ( & V_3 -> V_101 -> V_102 ) )
return V_120 ;
V_119 = F_7 ( V_3 , V_24 ) ;
if ( V_119 == ~ 0 )
return V_120 ;
V_25 = F_7 ( V_3 , V_96 ) ;
if ( ! ( V_25 & V_107 ) )
V_20 &= ~ V_109 ;
if ( ! ( V_25 & V_121 ) )
V_20 &= ~ V_112 ;
if ( ! ( V_119 & V_20 ) )
return V_120 ;
F_27 ( V_3 , V_96 , V_25 & ~ V_3 -> V_97 ) ;
F_27 ( V_3 , V_96 , V_25 ) ;
if ( ! V_3 -> V_51 -> V_52 ) {
F_58 ( V_3 ) ;
return V_111 ;
}
return V_3 -> V_122 ( V_3 ) ;
}
static unsigned int F_61 ( int V_123 , T_1 * V_124 )
{
unsigned long V_125 = 200000000 ;
unsigned long V_126 = V_125 / 2 ;
unsigned long V_127 = V_126 / 2 ;
unsigned long V_128 = V_126 * 2 / 5 ;
unsigned long V_129 ;
unsigned long V_130 , V_131 , V_132 ;
long V_133 , V_134 , V_135 ;
T_1 V_136 ;
V_136 = ( 1 << 24 ) >> 1 ;
V_131 = F_62 ( V_127 , V_123 ) ;
if ( V_131 > 256 ) {
V_129 = F_63 ( V_131 - 1 ) ;
if ( V_129 > 9 ) {
V_131 >>= V_129 - 9 ;
V_136 >>= V_129 - 9 ;
}
V_131 += V_131 & 1 ;
}
V_129 = F_64 ( V_131 ) ;
V_131 >>= V_129 ;
V_136 >>= V_129 ;
V_134 = abs ( V_127 / ( 1 << ( 24 - F_63 ( V_136 ) ) ) / V_131 - V_123 ) ;
V_132 = F_62 ( V_128 , V_123 ) ;
V_135 = abs ( V_128 / V_132 - V_123 ) ;
if ( V_135 >= V_134 || V_132 > 256 ) {
V_133 = V_134 ;
V_130 = V_131 ;
} else {
V_133 = V_135 ;
V_130 = V_132 ;
V_136 = ( 1 << 24 ) * 2 / 5 ;
}
if ( V_126 / V_123 >= 80 ) {
T_4 V_137 ;
T_1 V_138 ;
V_131 = F_62 ( V_126 , V_123 ) ;
V_138 = ( 1 << 24 ) / V_131 ;
V_137 = ( T_4 ) V_126 * V_138 ;
F_65 ( V_137 , 1 << 24 ) ;
V_134 = abs ( V_137 - V_123 ) ;
if ( V_134 < V_133 ) {
V_130 = 1 ;
V_136 = V_138 ;
}
}
* V_124 = V_136 ;
return V_130 - 1 ;
}
static unsigned int F_66 ( struct V_2 * V_3 , int V_123 )
{
unsigned long V_139 = V_3 -> V_51 -> V_56 ;
const struct V_140 * V_141 = V_3 -> V_141 ;
V_123 = F_67 ( int , V_139 , V_123 ) ;
if ( V_141 -> type == V_142 || V_141 -> type == V_14 )
return ( V_139 / ( 2 * V_123 ) - 1 ) & 0xff ;
else
return ( V_139 / V_123 - 1 ) & 0xfff ;
}
static unsigned int F_68 ( struct V_2 * V_3 ,
int V_123 )
{
struct V_58 * V_59 =
F_26 ( V_3 -> V_51 -> V_52 -> V_53 ) ;
unsigned int V_30 ;
switch ( V_3 -> V_5 ) {
case V_12 :
V_30 = F_61 ( V_123 , & V_59 -> V_143 ) ;
break;
default:
V_30 = F_66 ( V_3 , V_123 ) ;
break;
}
return V_30 << 8 ;
}
static bool F_69 ( struct V_144 * V_51 ,
struct V_145 * V_53 ,
struct V_80 * V_146 )
{
struct V_58 * V_59 = F_26 ( V_53 ) ;
return V_59 -> V_45 &&
V_146 -> V_105 <= V_147 &&
V_146 -> V_105 >= V_59 -> V_148 ;
}
static void V_103 ( unsigned long V_149 )
{
struct V_2 * V_3 = (struct V_2 * ) V_149 ;
struct V_144 * V_51 = V_3 -> V_51 ;
struct V_78 * V_150 = V_51 -> V_52 ;
struct V_58 * V_59 = F_26 ( V_150 -> V_53 ) ;
T_1 V_151 = V_59 -> V_152 ;
T_1 V_153 = V_59 -> V_148 ;
T_1 V_154 = F_4 ( V_3 ) ;
struct V_80 * V_155 ;
struct V_80 * V_156 ;
T_1 V_30 ;
T_2 V_31 ;
T_1 V_157 ;
T_1 V_158 ;
T_1 V_159 ;
int V_160 ;
int V_161 ;
V_155 = V_3 -> V_82 ;
if ( V_150 -> V_94 == V_95 ) {
V_150 -> V_119 = - V_162 ;
F_43 ( V_3 ) ;
return;
}
if ( V_150 -> V_94 == V_87 ) {
V_150 -> V_119 = 0 ;
F_43 ( V_3 ) ;
return;
}
if ( V_150 -> V_94 == V_86 ) {
V_156 = F_42 ( V_155 -> V_83 . V_163 ,
struct V_80 ,
V_83 ) ;
if ( V_156 -> V_90 )
F_45 ( V_156 -> V_90 ) ;
if ( V_156 -> V_92 )
F_30 ( V_3 ) ;
}
if ( V_155 -> V_105 > V_147 && V_59 -> V_45 ) {
if ( V_150 -> V_164
|| V_155 -> V_165 || V_155 -> V_166 ) {
F_54 ( & V_3 -> V_101 -> V_102 ,
L_4
L_5 ,
V_155 -> V_105 , V_147 ) ;
V_150 -> V_119 = - V_167 ;
F_43 ( V_3 ) ;
return;
}
F_70 ( & V_150 -> V_53 -> V_102 ,
L_6
L_7 ,
( long ) V_3 -> V_105 , V_147 ) ;
}
if ( F_31 ( V_3 ) == 0 ) {
F_54 ( & V_3 -> V_101 -> V_102 , L_8 ) ;
V_150 -> V_119 = - V_162 ;
F_43 ( V_3 ) ;
return;
}
V_3 -> V_72 = V_59 -> V_72 ;
V_3 -> V_73 = ( void * ) V_155 -> V_168 ;
V_3 -> V_74 = V_3 -> V_73 + V_155 -> V_105 ;
V_3 -> V_75 = V_155 -> V_169 ;
V_3 -> V_76 = V_3 -> V_75 + V_155 -> V_105 ;
V_3 -> V_105 = V_155 -> V_105 ;
V_3 -> V_114 = V_3 -> V_73 ? V_59 -> V_114 : F_33 ;
V_3 -> V_113 = V_3 -> V_75 ? V_59 -> V_113 : F_34 ;
V_31 = V_155 -> V_170 ;
V_157 = V_155 -> V_171 ;
V_30 = F_68 ( V_3 , V_157 ) ;
if ( V_31 <= 8 ) {
V_3 -> V_72 = 1 ;
V_3 -> V_113 = V_3 -> V_113 != F_34 ?
F_36 : F_34 ;
V_3 -> V_114 = V_3 -> V_114 != F_33 ?
F_35 : F_33 ;
} else if ( V_31 <= 16 ) {
V_3 -> V_72 = 2 ;
V_3 -> V_113 = V_3 -> V_113 != F_34 ?
F_38 : F_34 ;
V_3 -> V_114 = V_3 -> V_114 != F_33 ?
F_37 : F_33 ;
} else if ( V_31 <= 32 ) {
V_3 -> V_72 = 4 ;
V_3 -> V_113 = V_3 -> V_113 != F_34 ?
F_40 : F_34 ;
V_3 -> V_114 = V_3 -> V_114 != F_33 ?
F_39 : F_33 ;
}
if ( V_59 -> V_45 ) {
if ( F_71 ( V_59 ,
V_150 -> V_53 ,
V_31 , & V_153 ,
& V_151 ) )
F_70 ( & V_150 -> V_53 -> V_102 ,
L_9 ) ;
}
V_150 -> V_94 = V_86 ;
V_161 = V_51 -> V_172 &&
V_51 -> V_172 ( V_51 , V_150 -> V_53 , V_155 ) &&
V_51 -> V_173 ;
if ( V_161 ) {
V_3 -> V_122 = V_174 ;
V_160 = F_72 ( V_3 , V_153 ) ;
if ( V_160 ) {
V_150 -> V_119 = V_160 ;
F_43 ( V_3 ) ;
return;
}
V_159 = V_59 -> V_159 | V_151 | V_3 -> V_175 ;
F_27 ( V_3 , V_24 , V_3 -> V_98 ) ;
F_73 ( V_3 ) ;
} else {
V_3 -> V_122 = F_57 ;
V_159 = V_59 -> V_159 | V_59 -> V_29 | V_3 -> V_97 ;
F_32 ( V_3 , V_3 -> V_98 ) ;
}
V_158 = F_13 ( V_3 , V_30 , V_31 ) ;
if ( ! F_53 ( V_3 ) )
F_74 ( & V_150 -> V_53 -> V_102 , L_10 ,
V_51 -> V_56
/ ( 1 + ( ( V_158 & F_75 ( 0xfff ) ) >> 8 ) ) ,
V_161 ? L_11 : L_12 ) ;
else
F_74 ( & V_150 -> V_53 -> V_102 , L_10 ,
V_51 -> V_56 / 2
/ ( 1 + ( ( V_158 & F_75 ( 0x0ff ) ) >> 8 ) ) ,
V_161 ? L_11 : L_12 ) ;
if ( F_2 ( V_3 ) ) {
if ( ( F_7 ( V_3 , V_176 ) & 0xff )
!= V_59 -> V_177 )
F_27 ( V_3 , V_176 ,
V_59 -> V_177 ) ;
if ( ( F_7 ( V_3 , V_178 ) & 0xffff )
!= V_59 -> V_179 )
F_27 ( V_3 , V_178 ,
V_59 -> V_179 ) ;
}
if ( F_3 ( V_3 ) &&
( F_7 ( V_3 , V_180 ) != V_59 -> V_143 ) )
F_27 ( V_3 , V_180 , V_59 -> V_143 ) ;
if ( ( F_7 ( V_3 , V_100 ) != V_158 )
|| ( F_7 ( V_3 , V_96 ) & V_154 )
!= ( V_159 & V_154 ) ) {
F_27 ( V_3 , V_100 , V_158 & ~ V_33 ) ;
if ( ! F_53 ( V_3 ) )
F_27 ( V_3 , V_99 , V_59 -> V_89 ) ;
F_27 ( V_3 , V_96 , V_159 & V_154 ) ;
F_27 ( V_3 , V_100 , V_158 ) ;
} else {
if ( ! F_53 ( V_3 ) )
F_27 ( V_3 , V_99 , V_59 -> V_89 ) ;
}
F_25 ( V_3 ) ;
F_27 ( V_3 , V_96 , V_159 ) ;
}
static int F_76 ( struct V_144 * V_51 ,
struct V_78 * V_79 )
{
struct V_2 * V_3 = F_77 ( V_51 ) ;
V_79 -> V_94 = V_181 ;
V_3 -> V_82 = F_42 ( V_79 -> V_85 . V_84 ,
struct V_80 ,
V_83 ) ;
F_55 ( & V_3 -> V_103 ) ;
return 0 ;
}
static int F_78 ( struct V_144 * V_51 )
{
struct V_2 * V_3 = F_77 ( V_51 ) ;
F_27 ( V_3 , V_100 ,
F_7 ( V_3 , V_100 ) & ~ V_33 ) ;
return 0 ;
}
static int F_79 ( struct V_145 * V_53 , struct V_58 * V_59 ,
struct V_182 * V_183 )
{
struct V_2 * V_3 = F_77 ( V_53 -> V_51 ) ;
int V_160 = 0 ;
if ( V_59 == NULL )
return 0 ;
if ( V_3 -> V_184 ) {
struct V_185 * V_186 ;
V_186 = V_3 -> V_184 [ V_53 -> V_54 ] ;
if ( V_186 ) {
V_59 -> V_63 = F_80 ( V_186 ) ;
V_59 -> V_64 = V_53 -> V_187 & V_188 ;
F_81 ( V_186 , V_59 -> V_64 ) ;
}
return 0 ;
}
if ( V_183 == NULL )
return 0 ;
if ( F_28 ( V_59 -> V_63 ) )
F_82 ( V_59 -> V_63 ) ;
if ( V_183 -> V_61 ) {
V_59 -> V_61 = V_183 -> V_61 ;
return 0 ;
}
if ( F_28 ( V_183 -> V_63 ) ) {
V_160 = F_83 ( V_183 -> V_63 , L_13 ) ;
if ( V_160 ) {
F_54 ( & V_53 -> V_102 , L_14 ,
V_183 -> V_63 ) ;
return V_160 ;
}
V_59 -> V_63 = V_183 -> V_63 ;
V_59 -> V_64 = V_53 -> V_187 & V_188 ;
V_160 = F_84 ( V_59 -> V_63 ,
! V_59 -> V_64 ) ;
}
return V_160 ;
}
static int F_85 ( struct V_145 * V_53 )
{
struct V_182 * V_183 ;
struct V_58 * V_59 ;
const struct V_1 * V_39 ;
struct V_2 * V_3 = F_77 ( V_53 -> V_51 ) ;
T_5 V_189 , V_190 , V_191 ;
switch ( V_3 -> V_5 ) {
case V_12 :
V_189 = V_192 ;
V_190 = 0 ;
V_191 = V_17 ;
break;
case V_14 :
V_189 = V_193 ;
V_190 = 0 ;
V_191 = V_18 ;
break;
case V_6 :
case V_7 :
case V_8 :
case V_9 :
case V_10 :
case V_11 :
V_39 = F_1 ( V_3 ) ;
V_189 = V_39 -> V_194 ;
V_190 = V_39 -> V_195 ;
V_191 = V_39 -> V_196 ;
break;
default:
V_189 = V_197 ;
V_190 = 0 ;
V_191 = V_19 ;
break;
}
V_59 = F_26 ( V_53 ) ;
if ( ! V_59 ) {
V_59 = F_86 ( sizeof( struct V_58 ) , V_198 ) ;
if ( ! V_59 )
return - V_199 ;
if ( V_3 -> V_5 == V_14 ) {
if ( V_53 -> V_54 > 4 ) {
F_54 ( & V_53 -> V_102 ,
L_15 ) ;
F_87 ( V_59 ) ;
return - V_167 ;
}
V_59 -> V_60 = V_53 -> V_54 ;
} else
V_59 -> V_63 = - 1 ;
V_59 -> V_45 = V_3 -> V_44 -> V_45 ;
V_59 -> V_89 = V_200 ;
}
V_183 = V_53 -> V_201 ;
V_59 -> V_159 = 0 ;
if ( V_183 ) {
if ( V_183 -> V_89 )
V_59 -> V_89 = V_183 -> V_89 ;
if ( V_183 -> V_202 )
V_189 = V_183 -> V_202 ;
if ( V_183 -> V_203 )
V_190 = V_183 -> V_203 ;
if ( V_183 -> V_196 )
V_191 = V_183 -> V_196 ;
V_59 -> V_152 = 0 ;
if ( V_183 -> V_204 )
V_59 -> V_159 = V_205 ;
}
V_59 -> V_177 = F_88 ( V_191 ) ;
V_59 -> V_179 = F_89 ( V_189 )
| F_90 ( V_190 ) ;
if ( V_59 -> V_45 ) {
if ( F_71 ( V_59 , V_53 ,
V_53 -> V_170 ,
& V_59 -> V_148 ,
& V_59 -> V_152 ) ) {
F_91 ( & V_53 -> V_102 ,
L_16 ) ;
}
}
switch ( V_3 -> V_5 ) {
case V_12 :
V_59 -> V_29 = ( F_10 ( V_191 )
& V_26 )
| ( F_92 ( V_189 )
& V_206 ) ;
break;
case V_14 :
V_59 -> V_29 = ( F_11 ( V_191 ) & V_27 ) |
( F_93 ( V_189 ) & V_207 ) ;
break;
default:
V_59 -> V_29 = ( F_12 ( V_191 ) & V_28 ) |
( F_94 ( V_189 ) & V_208 ) ;
break;
}
V_59 -> V_159 &= ~ ( V_209 | V_210 ) ;
V_59 -> V_159 |= ( ( ( V_53 -> V_187 & V_211 ) != 0 ) ? V_210 : 0 )
| ( ( ( V_53 -> V_187 & V_212 ) != 0 ) ? V_209 : 0 ) ;
if ( V_53 -> V_187 & V_213 )
V_59 -> V_159 |= V_205 ;
if ( V_53 -> V_170 <= 8 ) {
V_59 -> V_72 = 1 ;
V_59 -> V_113 = F_36 ;
V_59 -> V_114 = F_35 ;
} else if ( V_53 -> V_170 <= 16 ) {
V_59 -> V_72 = 2 ;
V_59 -> V_113 = F_38 ;
V_59 -> V_114 = F_37 ;
} else if ( V_53 -> V_170 <= 32 ) {
V_59 -> V_72 = 4 ;
V_59 -> V_113 = F_40 ;
V_59 -> V_114 = F_39 ;
}
F_95 ( V_53 , V_59 ) ;
if ( V_3 -> V_5 == V_14 )
return 0 ;
return F_79 ( V_53 , V_59 , V_183 ) ;
}
static void F_96 ( struct V_145 * V_53 )
{
struct V_58 * V_59 = F_26 ( V_53 ) ;
struct V_2 * V_3 = F_77 ( V_53 -> V_51 ) ;
if ( ! V_59 )
return;
if ( V_3 -> V_5 != V_14 && ! V_3 -> V_184 &&
F_28 ( V_59 -> V_63 ) )
F_82 ( V_59 -> V_63 ) ;
F_87 ( V_59 ) ;
}
static int F_97 ( struct V_214 * V_215 )
{
unsigned int V_216 ;
int V_217 = - 1 ;
if ( V_215 && V_215 -> V_218 . V_219 &&
! F_98 ( V_215 -> V_218 . V_219 , 0 , & V_216 ) )
V_217 = V_216 ;
return V_217 ;
}
static int F_97 ( struct V_214 * V_215 )
{
return - 1 ;
}
static bool F_99 ( struct V_220 * V_221 , void * V_222 )
{
struct V_223 * V_102 = V_222 ;
if ( V_102 != V_221 -> V_223 -> V_102 -> V_224 )
return false ;
return true ;
}
static struct V_225 *
F_100 ( struct V_226 * V_101 )
{
struct V_225 * V_227 ;
struct V_214 * V_215 ;
struct V_140 * V_141 ;
struct V_228 * V_229 ;
const struct V_230 * V_231 = NULL ;
const struct V_232 * V_233 = NULL ;
int type ;
V_215 = F_101 ( & V_101 -> V_102 ) ;
if ( F_102 ( V_101 -> V_102 . V_224 ) )
V_233 = F_103 ( V_234 ,
F_104 ( V_101 -> V_102 . V_224 ) ) ;
else if ( V_215 )
V_231 = F_105 ( V_101 -> V_102 . V_235 -> V_236 ,
& V_101 -> V_102 ) ;
else
return NULL ;
if ( V_231 )
type = ( int ) V_231 -> V_2 ;
else if ( V_233 )
type = ( int ) V_233 -> V_2 ;
else
return NULL ;
V_227 = F_106 ( & V_101 -> V_102 , sizeof( * V_227 ) , V_198 ) ;
if ( ! V_227 )
return NULL ;
V_229 = F_107 ( V_101 , V_237 , 0 ) ;
if ( ! V_229 )
return NULL ;
V_141 = & V_227 -> V_141 ;
V_141 -> V_238 = V_229 -> V_239 ;
V_141 -> V_240 = F_108 ( & V_101 -> V_102 , V_229 ) ;
if ( F_109 ( V_141 -> V_240 ) )
return NULL ;
if ( V_233 ) {
V_227 -> V_241 = V_101 -> V_102 . V_224 ;
V_227 -> V_242 = V_101 -> V_102 . V_224 ;
V_227 -> V_243 = F_99 ;
}
V_141 -> V_244 = F_110 ( & V_101 -> V_102 , NULL ) ;
V_141 -> V_117 = F_111 ( V_101 , 0 ) ;
V_141 -> type = type ;
V_141 -> V_101 = V_101 ;
V_141 -> V_217 = F_97 ( V_215 ) ;
V_227 -> V_245 = 1 ;
V_227 -> V_45 = true ;
return V_227 ;
}
static inline struct V_225 *
F_100 ( struct V_226 * V_101 )
{
return NULL ;
}
static int F_112 ( struct V_144 * V_51 , unsigned V_49 )
{
struct V_2 * V_3 = F_77 ( V_51 ) ;
if ( F_113 ( & V_3 -> V_101 -> V_102 ) ) {
switch ( V_3 -> V_5 ) {
case V_7 :
case V_8 :
return V_49 - 1 ;
default:
break;
}
}
return V_49 ;
}
static int F_114 ( struct V_226 * V_101 )
{
struct V_223 * V_102 = & V_101 -> V_102 ;
struct V_225 * V_246 ;
struct V_144 * V_51 ;
struct V_2 * V_3 ;
struct V_140 * V_141 ;
const struct V_1 * V_39 ;
int V_119 , V_247 ;
T_1 V_248 ;
V_246 = F_115 ( V_102 ) ;
if ( ! V_246 ) {
V_246 = F_100 ( V_101 ) ;
if ( ! V_246 ) {
F_54 ( & V_101 -> V_102 , L_17 ) ;
return - V_249 ;
}
}
V_141 = F_116 ( V_101 -> V_250 , V_101 -> V_251 ) ;
if ( ! V_141 )
V_141 = & V_246 -> V_141 ;
if ( ! V_141 -> V_240 ) {
F_54 ( & V_101 -> V_102 , L_18 ) ;
return - V_249 ;
}
V_51 = F_117 ( V_102 , sizeof( struct V_2 ) ) ;
if ( ! V_51 ) {
F_54 ( & V_101 -> V_102 , L_19 ) ;
F_118 ( V_141 ) ;
return - V_199 ;
}
V_3 = F_77 ( V_51 ) ;
V_3 -> V_51 = V_51 ;
V_3 -> V_44 = V_246 ;
V_3 -> V_101 = V_101 ;
V_3 -> V_141 = V_141 ;
V_51 -> V_102 . V_252 = V_101 -> V_102 . V_252 ;
V_51 -> V_253 = V_212 | V_211 | V_188 | V_213 ;
V_51 -> V_254 = V_141 -> V_217 ;
V_51 -> V_255 = V_256 ;
V_51 -> F_96 = F_96 ;
V_51 -> F_85 = F_85 ;
V_51 -> V_257 = F_76 ;
V_51 -> V_258 = F_78 ;
V_51 -> V_259 = F_112 ;
V_51 -> V_260 = true ;
V_51 -> V_261 = V_262 | V_263 ;
V_3 -> V_5 = V_141 -> type ;
V_3 -> V_40 = V_141 -> V_240 ;
V_3 -> V_264 = V_141 -> V_238 + V_69 ;
if ( F_53 ( V_3 ) ) {
switch ( V_3 -> V_5 ) {
case V_12 :
V_51 -> V_265 = F_119 ( 4 , 32 ) ;
break;
default:
V_51 -> V_265 = F_119 ( 4 , 16 ) ;
break;
}
V_3 -> V_97 = V_107 | V_266 ;
V_3 -> V_175 = 0 ;
V_3 -> V_98 = V_71 ;
V_3 -> V_108 = V_267 | V_109 | V_71 ;
} else {
V_51 -> V_265 = F_119 ( 4 , 32 ) ;
V_3 -> V_97 = V_107 | V_266 | V_121 ;
V_3 -> V_175 = V_268 ;
V_3 -> V_98 = V_71 | V_112 ;
V_3 -> V_108 = V_112 | V_267 | V_109 | V_71 ;
}
V_119 = F_120 ( V_141 -> V_117 , F_59 , V_269 , F_121 ( V_102 ) ,
V_3 ) ;
if ( V_119 < 0 ) {
F_54 ( & V_101 -> V_102 , L_20 , V_141 -> V_117 ) ;
goto V_270;
}
if ( V_246 -> V_45 ) {
V_119 = F_122 ( V_3 ) ;
if ( V_119 ) {
F_74 ( V_102 , L_21 ) ;
V_246 -> V_45 = false ;
} else {
V_51 -> V_172 = F_69 ;
}
}
F_123 ( V_141 -> V_244 ) ;
V_51 -> V_56 = F_124 ( V_141 -> V_244 ) ;
F_27 ( V_3 , V_100 , 0 ) ;
switch ( V_3 -> V_5 ) {
case V_12 :
V_248 = F_10 ( V_17 ) |
F_92 ( V_192 ) ;
F_27 ( V_3 , V_96 , V_248 ) ;
V_248 = V_32 | F_14 ( 8 ) ;
F_27 ( V_3 , V_100 , V_248 ) ;
break;
case V_14 :
V_248 = F_11 ( V_18 ) |
F_93 ( V_193 ) ;
F_27 ( V_3 , V_96 , V_248 ) ;
V_248 = F_75 ( 2 ) | V_34 | F_15 ( 8 ) ;
F_27 ( V_3 , V_100 , V_248 ) ;
break;
default:
V_248 = F_12 ( V_19 ) |
F_94 ( V_197 ) ;
F_27 ( V_3 , V_96 , V_248 ) ;
V_248 = F_75 ( 2 ) | V_34 | F_15 ( 8 ) ;
F_27 ( V_3 , V_100 , V_248 ) ;
break;
}
if ( ! F_53 ( V_3 ) )
F_27 ( V_3 , V_99 , 0 ) ;
if ( ! F_3 ( V_3 ) )
F_27 ( V_3 , V_271 , 0 ) ;
if ( F_2 ( V_3 ) ) {
F_21 ( V_3 ) ;
V_39 = F_1 ( V_3 ) ;
if ( V_39 -> V_272 >= 0 ) {
V_248 = F_16 ( V_3 ,
V_39 -> V_272 ) ;
V_248 &= V_273 ;
V_248 >>= V_274 ;
V_246 -> V_245 = F_125 ( V_248 ) ;
} else if ( V_39 -> V_275 ) {
V_246 -> V_245 = V_39 -> V_275 ;
}
}
V_51 -> V_245 = V_246 -> V_245 ;
V_247 = F_126 ( & V_101 -> V_102 , L_22 ) ;
if ( V_247 > 0 ) {
int V_276 ;
V_51 -> V_245 = F_127 ( int , V_247 ,
V_51 -> V_245 ) ;
V_3 -> V_184 = F_128 ( & V_101 -> V_102 ,
V_51 -> V_245 , sizeof( struct V_185 * ) ,
V_198 ) ;
if ( ! V_3 -> V_184 ) {
V_119 = - V_199 ;
goto V_277;
}
for ( V_276 = 0 ; V_276 < V_51 -> V_245 ; V_276 ++ ) {
struct V_185 * V_186 ;
V_186 = F_129 ( V_102 , L_22 , V_276 ,
V_278 ) ;
if ( F_109 ( V_186 ) ) {
if ( F_130 ( V_186 ) == - V_279 )
continue;
V_119 = ( int ) F_130 ( V_186 ) ;
goto V_277;
} else {
V_3 -> V_184 [ V_276 ] = V_186 ;
}
}
}
F_131 ( & V_3 -> V_103 , V_103 ,
( unsigned long ) V_3 ) ;
F_132 ( & V_101 -> V_102 , 50 ) ;
F_133 ( & V_101 -> V_102 ) ;
F_134 ( & V_101 -> V_102 ) ;
F_135 ( & V_101 -> V_102 ) ;
F_136 ( V_101 , V_3 ) ;
V_119 = F_137 ( & V_101 -> V_102 , V_51 ) ;
if ( V_119 != 0 ) {
F_54 ( & V_101 -> V_102 , L_23 ) ;
goto V_277;
}
return V_119 ;
V_277:
F_138 ( V_141 -> V_244 ) ;
F_139 ( V_3 ) ;
F_140 ( V_141 -> V_117 , V_3 ) ;
V_270:
F_141 ( V_51 ) ;
F_118 ( V_141 ) ;
return V_119 ;
}
static int F_142 ( struct V_226 * V_101 )
{
struct V_2 * V_3 = F_143 ( V_101 ) ;
struct V_140 * V_141 ;
if ( ! V_3 )
return 0 ;
V_141 = V_3 -> V_141 ;
F_144 ( & V_101 -> V_102 ) ;
F_27 ( V_3 , V_100 , 0 ) ;
F_138 ( V_141 -> V_244 ) ;
if ( V_3 -> V_44 -> V_45 )
F_139 ( V_3 ) ;
F_145 ( & V_101 -> V_102 ) ;
F_146 ( & V_101 -> V_102 ) ;
F_140 ( V_141 -> V_117 , V_3 ) ;
F_118 ( V_141 ) ;
return 0 ;
}
static void F_147 ( struct V_226 * V_101 )
{
int V_119 = 0 ;
if ( ( V_119 = F_142 ( V_101 ) ) != 0 )
F_54 ( & V_101 -> V_102 , L_24 , V_119 ) ;
}
static int F_148 ( struct V_223 * V_102 )
{
struct V_2 * V_3 = F_149 ( V_102 ) ;
struct V_140 * V_141 = V_3 -> V_141 ;
int V_119 ;
V_119 = F_150 ( V_3 -> V_51 ) ;
if ( V_119 != 0 )
return V_119 ;
F_27 ( V_3 , V_100 , 0 ) ;
if ( ! F_60 ( V_102 ) )
F_138 ( V_141 -> V_244 ) ;
return 0 ;
}
static int F_151 ( struct V_223 * V_102 )
{
struct V_2 * V_3 = F_149 ( V_102 ) ;
struct V_140 * V_141 = V_3 -> V_141 ;
int V_119 ;
if ( ! F_60 ( V_102 ) )
F_123 ( V_141 -> V_244 ) ;
if ( F_2 ( V_3 ) )
F_21 ( V_3 ) ;
V_119 = F_152 ( V_3 -> V_51 ) ;
if ( V_119 != 0 ) {
F_54 ( V_102 , L_25 , V_119 ) ;
return V_119 ;
}
return 0 ;
}
static int F_153 ( struct V_223 * V_102 )
{
struct V_2 * V_3 = F_149 ( V_102 ) ;
F_138 ( V_3 -> V_141 -> V_244 ) ;
return 0 ;
}
static int F_154 ( struct V_223 * V_102 )
{
struct V_2 * V_3 = F_149 ( V_102 ) ;
F_123 ( V_3 -> V_141 -> V_244 ) ;
return 0 ;
}
static int T_6 F_155 ( void )
{
return F_156 ( & V_235 ) ;
}
static void T_7 F_157 ( void )
{
F_158 ( & V_235 ) ;
}
