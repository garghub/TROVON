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
return true ;
default:
return false ;
}
}
static bool F_3 ( const struct V_2 * V_3 )
{
return V_3 -> V_5 == V_11 ;
}
static T_1 F_4 ( const struct V_2 * V_3 )
{
switch ( V_3 -> V_5 ) {
case V_11 :
return V_12 ;
case V_13 :
return V_14 ;
default:
return V_15 ;
}
}
static T_1
F_5 ( const struct V_2 * V_3 )
{
switch ( V_3 -> V_5 ) {
case V_11 :
return V_16 ;
case V_13 :
return V_17 ;
default:
return V_18 ;
}
}
static bool F_6 ( const struct V_2 * V_3 )
{
T_1 V_19 ;
switch ( V_3 -> V_5 ) {
case V_11 :
V_19 = V_20 ;
break;
case V_13 :
V_19 = V_21 ;
break;
default:
V_19 = V_22 ;
break;
}
return ( F_7 ( V_3 , V_23 ) & V_19 ) == V_19 ;
}
static void F_8 ( const struct V_2 * V_3 ,
T_1 * V_24 )
{
T_1 V_19 ;
switch ( V_3 -> V_5 ) {
case V_11 :
V_19 = V_25 ;
break;
case V_13 :
V_19 = V_26 ;
break;
default:
V_19 = V_27 ;
break;
}
* V_24 &= ~ V_19 ;
}
static void F_9 ( const struct V_2 * V_3 ,
T_1 * V_24 , T_1 V_28 )
{
switch ( V_3 -> V_5 ) {
case V_11 :
* V_24 |= F_10 ( V_28 ) ;
break;
case V_13 :
* V_24 |= F_11 ( V_28 ) ;
break;
default:
* V_24 |= F_12 ( V_28 ) ;
break;
}
}
static T_1 F_13 ( const struct V_2 * V_3 ,
T_1 V_29 , T_2 V_30 )
{
switch ( V_3 -> V_5 ) {
case V_11 :
return V_29
| V_31
| F_14 ( V_30 > 32 ? 8 : V_30 )
| V_32 ;
default:
return V_29
| V_33
| F_15 ( V_30 > 16 ? V_30 - 16 : V_30 )
| V_32
| ( V_30 > 16 ? V_34 : 0 ) ;
}
}
static T_1 F_16 ( struct V_2 * V_3 , unsigned V_35 )
{
F_17 ( ! V_3 -> V_36 ) ;
return F_18 ( V_3 -> V_36 + V_35 ) ;
}
static void F_19 ( struct V_2 * V_3 ,
unsigned V_35 , T_1 V_37 )
{
F_17 ( ! V_3 -> V_36 ) ;
F_20 ( V_37 , V_3 -> V_36 + V_35 ) ;
}
static void F_21 ( struct V_2 * V_3 )
{
const struct V_1 * V_38 ;
T_1 V_37 ;
V_38 = F_1 ( V_3 ) ;
V_3 -> V_36 = V_3 -> V_39 + V_38 -> V_35 ;
V_37 = F_16 ( V_3 , V_38 -> V_40 ) ;
V_37 &= ~ ( V_41 | V_42 ) ;
V_37 |= V_41 | V_42 ;
F_19 ( V_3 , V_38 -> V_40 , V_37 ) ;
if ( V_3 -> V_43 -> V_44 ) {
F_19 ( V_3 , V_38 -> V_45 , 1 ) ;
if ( V_38 -> V_46 >= 0 ) {
V_37 = F_16 ( V_3 ,
V_38 -> V_46 ) ;
V_37 |= V_47 ;
F_19 ( V_3 ,
V_38 -> V_46 , V_37 ) ;
}
}
}
static void F_22 ( struct V_2 * V_3 ,
const struct V_1 * V_38 )
{
T_1 V_37 , V_48 ;
if ( ! V_38 -> V_49 )
return;
V_37 = F_16 ( V_3 , V_38 -> V_40 ) ;
V_48 = V_3 -> V_50 -> V_51 -> V_52 -> V_53 ;
V_48 <<= V_38 -> V_54 ;
if ( V_48 != ( V_37 & V_38 -> V_49 ) ) {
V_37 &= ~ V_38 -> V_49 ;
V_37 |= V_48 ;
F_19 ( V_3 ,
V_38 -> V_40 , V_37 ) ;
F_23 ( 1000000000 /
( V_3 -> V_50 -> V_55 / 2 ) ) ;
}
}
static void F_24 ( struct V_2 * V_3 , bool V_56 )
{
const struct V_1 * V_38 ;
T_1 V_37 ;
V_38 = F_1 ( V_3 ) ;
if ( V_56 )
F_22 ( V_3 , V_38 ) ;
V_37 = F_16 ( V_3 , V_38 -> V_40 ) ;
if ( V_56 )
V_37 &= ~ V_42 ;
else
V_37 |= V_42 ;
F_19 ( V_3 , V_38 -> V_40 , V_37 ) ;
}
static void F_25 ( struct V_2 * V_3 )
{
struct V_57 * V_58 =
F_26 ( V_3 -> V_50 -> V_51 -> V_52 ) ;
if ( V_3 -> V_5 == V_13 ) {
F_27 ( V_3 , V_23 , V_58 -> V_59 ) ;
return;
}
if ( V_58 -> V_60 ) {
V_58 -> V_60 ( V_61 ) ;
return;
}
if ( F_28 ( V_58 -> V_62 ) ) {
F_29 ( V_58 -> V_62 , V_58 -> V_63 ) ;
return;
}
if ( F_2 ( V_3 ) )
F_24 ( V_3 , true ) ;
}
static void F_30 ( struct V_2 * V_3 )
{
struct V_57 * V_58 =
F_26 ( V_3 -> V_50 -> V_51 -> V_52 ) ;
if ( V_3 -> V_5 == V_13 )
return;
if ( V_58 -> V_60 ) {
V_58 -> V_60 ( V_64 ) ;
return;
}
if ( F_28 ( V_58 -> V_62 ) ) {
F_29 ( V_58 -> V_62 , ! V_58 -> V_63 ) ;
return;
}
if ( F_2 ( V_3 ) )
F_24 ( V_3 , false ) ;
}
int F_31 ( struct V_2 * V_3 )
{
unsigned long V_65 = V_66 << 1 ;
do {
while ( F_7 ( V_3 , V_23 ) & V_67 )
F_7 ( V_3 , V_68 ) ;
} while ( ( F_7 ( V_3 , V_23 ) & V_69 ) && -- V_65 );
F_32 ( V_3 , V_70 ) ;
return V_65 ;
}
static int F_33 ( struct V_2 * V_3 )
{
T_2 V_71 = V_3 -> V_71 ;
if ( F_6 ( V_3 )
|| ( V_3 -> V_72 == V_3 -> V_73 ) )
return 0 ;
F_27 ( V_3 , V_68 , 0 ) ;
V_3 -> V_72 += V_71 ;
return 1 ;
}
static int F_34 ( struct V_2 * V_3 )
{
T_2 V_71 = V_3 -> V_71 ;
while ( ( F_7 ( V_3 , V_23 ) & V_67 )
&& ( V_3 -> V_74 < V_3 -> V_75 ) ) {
F_7 ( V_3 , V_68 ) ;
V_3 -> V_74 += V_71 ;
}
return V_3 -> V_74 == V_3 -> V_75 ;
}
static int F_35 ( struct V_2 * V_3 )
{
if ( F_6 ( V_3 )
|| ( V_3 -> V_72 == V_3 -> V_73 ) )
return 0 ;
F_27 ( V_3 , V_68 , * ( T_2 * ) ( V_3 -> V_72 ) ) ;
++ V_3 -> V_72 ;
return 1 ;
}
static int F_36 ( struct V_2 * V_3 )
{
while ( ( F_7 ( V_3 , V_23 ) & V_67 )
&& ( V_3 -> V_74 < V_3 -> V_75 ) ) {
* ( T_2 * ) ( V_3 -> V_74 ) = F_7 ( V_3 , V_68 ) ;
++ V_3 -> V_74 ;
}
return V_3 -> V_74 == V_3 -> V_75 ;
}
static int F_37 ( struct V_2 * V_3 )
{
if ( F_6 ( V_3 )
|| ( V_3 -> V_72 == V_3 -> V_73 ) )
return 0 ;
F_27 ( V_3 , V_68 , * ( V_76 * ) ( V_3 -> V_72 ) ) ;
V_3 -> V_72 += 2 ;
return 1 ;
}
static int F_38 ( struct V_2 * V_3 )
{
while ( ( F_7 ( V_3 , V_23 ) & V_67 )
&& ( V_3 -> V_74 < V_3 -> V_75 ) ) {
* ( V_76 * ) ( V_3 -> V_74 ) = F_7 ( V_3 , V_68 ) ;
V_3 -> V_74 += 2 ;
}
return V_3 -> V_74 == V_3 -> V_75 ;
}
static int F_39 ( struct V_2 * V_3 )
{
if ( F_6 ( V_3 )
|| ( V_3 -> V_72 == V_3 -> V_73 ) )
return 0 ;
F_27 ( V_3 , V_68 , * ( T_1 * ) ( V_3 -> V_72 ) ) ;
V_3 -> V_72 += 4 ;
return 1 ;
}
static int F_40 ( struct V_2 * V_3 )
{
while ( ( F_7 ( V_3 , V_23 ) & V_67 )
&& ( V_3 -> V_74 < V_3 -> V_75 ) ) {
* ( T_1 * ) ( V_3 -> V_74 ) = F_7 ( V_3 , V_68 ) ;
V_3 -> V_74 += 4 ;
}
return V_3 -> V_74 == V_3 -> V_75 ;
}
void * F_41 ( struct V_2 * V_3 )
{
struct V_77 * V_78 = V_3 -> V_50 -> V_51 ;
struct V_79 * V_80 = V_3 -> V_81 ;
if ( V_80 -> V_82 . V_83 != & V_78 -> V_84 ) {
V_3 -> V_81 =
F_42 ( V_80 -> V_82 . V_83 ,
struct V_79 ,
V_82 ) ;
return V_85 ;
} else
return V_86 ;
}
static void F_43 ( struct V_2 * V_3 )
{
struct V_79 * V_87 ;
struct V_77 * V_78 ;
unsigned long V_88 ;
V_78 = V_3 -> V_50 -> V_51 ;
V_3 -> V_81 = NULL ;
V_87 = F_44 ( & V_78 -> V_84 , struct V_79 ,
V_82 ) ;
if ( V_87 -> V_89 )
F_45 ( V_87 -> V_89 ) ;
V_88 = V_90 + F_46 ( 10 ) ;
while ( F_7 ( V_3 , V_23 ) & V_69 &&
! F_47 ( V_90 , V_88 ) )
F_48 () ;
if ( ! V_87 -> V_91 )
F_30 ( V_3 ) ;
else {
struct V_77 * V_92 ;
V_92 = F_49 ( V_3 -> V_50 ) ;
if ( ( V_92 && V_92 -> V_52 != V_78 -> V_52 ) ||
V_78 -> V_93 == V_94 )
F_30 ( V_3 ) ;
}
F_50 ( V_3 -> V_50 ) ;
}
static void F_51 ( struct V_2 * V_3 )
{
struct V_57 * V_58 =
F_26 ( V_3 -> V_50 -> V_51 -> V_52 ) ;
T_1 V_24 ;
V_24 = F_7 ( V_3 , V_95 ) & ~ V_3 -> V_96 ;
switch ( V_3 -> V_5 ) {
case V_11 :
V_24 &= ~ V_25 ;
break;
case V_13 :
V_24 &= ~ V_26 ;
break;
default:
V_24 &= ~ V_27 ;
break;
}
V_24 |= V_58 -> V_28 ;
F_27 ( V_3 , V_95 , V_24 ) ;
}
static void F_52 ( struct V_2 * V_3 , const char * V_78 )
{
F_32 ( V_3 , V_3 -> V_97 ) ;
F_51 ( V_3 ) ;
if ( ! F_53 ( V_3 ) )
F_27 ( V_3 , V_98 , 0 ) ;
F_31 ( V_3 ) ;
F_27 ( V_3 , V_99 ,
F_7 ( V_3 , V_99 ) & ~ V_32 ) ;
F_54 ( & V_3 -> V_100 -> V_101 , L_1 , V_78 ) ;
V_3 -> V_50 -> V_51 -> V_93 = V_94 ;
F_55 ( & V_3 -> V_102 ) ;
}
static void F_56 ( struct V_2 * V_3 )
{
F_32 ( V_3 , V_3 -> V_97 ) ;
F_51 ( V_3 ) ;
if ( ! F_53 ( V_3 ) )
F_27 ( V_3 , V_98 , 0 ) ;
V_3 -> V_50 -> V_51 -> V_103 += V_3 -> V_104 -
( V_3 -> V_75 - V_3 -> V_74 ) ;
V_3 -> V_50 -> V_51 -> V_93 = F_41 ( V_3 ) ;
F_55 ( & V_3 -> V_102 ) ;
}
static T_3 F_57 ( struct V_2 * V_3 )
{
T_1 V_105 = ( F_7 ( V_3 , V_95 ) & V_106 ) ?
V_3 -> V_107 : V_3 -> V_107 & ~ V_108 ;
T_1 V_109 = F_7 ( V_3 , V_23 ) & V_105 ;
if ( V_109 & V_70 ) {
F_52 ( V_3 , L_2 ) ;
return V_110 ;
}
if ( V_109 & V_111 ) {
F_27 ( V_3 , V_23 , V_111 ) ;
if ( V_3 -> V_112 ( V_3 ) ) {
F_56 ( V_3 ) ;
return V_110 ;
}
}
do {
if ( V_3 -> V_112 ( V_3 ) ) {
F_56 ( V_3 ) ;
return V_110 ;
}
} while ( V_3 -> V_113 ( V_3 ) );
if ( V_3 -> V_112 ( V_3 ) ) {
F_56 ( V_3 ) ;
return V_110 ;
}
if ( V_3 -> V_72 == V_3 -> V_73 ) {
T_1 V_114 ;
T_1 V_24 ;
V_24 = F_7 ( V_3 , V_95 ) ;
V_24 &= ~ V_106 ;
if ( F_53 ( V_3 ) ) {
T_1 V_115 ;
F_8 ( V_3 , & V_24 ) ;
V_114 = V_3 -> V_75 - V_3 -> V_74 ;
switch ( V_3 -> V_71 ) {
case 4 :
V_114 >>= 1 ;
case 2 :
V_114 >>= 1 ;
}
V_115 = F_5 ( V_3 ) ;
if ( V_115 > V_114 )
V_115 = V_114 ;
F_9 ( V_3 , & V_24 , V_115 ) ;
}
F_27 ( V_3 , V_95 , V_24 ) ;
}
return V_110 ;
}
static void F_58 ( struct V_2 * V_3 )
{
F_27 ( V_3 , V_99 ,
F_7 ( V_3 , V_99 ) & ~ V_32 ) ;
F_27 ( V_3 , V_95 ,
F_7 ( V_3 , V_95 ) & ~ V_3 -> V_96 ) ;
if ( ! F_53 ( V_3 ) )
F_27 ( V_3 , V_98 , 0 ) ;
F_32 ( V_3 , V_3 -> V_97 ) ;
F_54 ( & V_3 -> V_100 -> V_101 ,
L_3 ) ;
}
static T_3 F_59 ( int V_116 , void * V_117 )
{
struct V_2 * V_3 = V_117 ;
T_1 V_24 ;
T_1 V_19 = V_3 -> V_107 ;
T_1 V_118 ;
if ( F_60 ( & V_3 -> V_100 -> V_101 ) )
return V_119 ;
V_118 = F_7 ( V_3 , V_23 ) ;
if ( V_118 == ~ 0 )
return V_119 ;
V_24 = F_7 ( V_3 , V_95 ) ;
if ( ! ( V_24 & V_106 ) )
V_19 &= ~ V_108 ;
if ( ! ( V_24 & V_120 ) )
V_19 &= ~ V_111 ;
if ( ! ( V_118 & V_19 ) )
return V_119 ;
F_27 ( V_3 , V_95 , V_24 & ~ V_3 -> V_96 ) ;
F_27 ( V_3 , V_95 , V_24 ) ;
if ( ! V_3 -> V_50 -> V_51 ) {
F_58 ( V_3 ) ;
return V_110 ;
}
return V_3 -> V_121 ( V_3 ) ;
}
static unsigned int F_61 ( int V_122 , T_1 * V_123 )
{
unsigned long V_124 = 200000000 ;
unsigned long V_125 = V_124 / 2 ;
unsigned long V_126 = V_125 / 2 ;
unsigned long V_127 = V_125 * 2 / 5 ;
unsigned long V_128 ;
unsigned long V_129 , V_130 , V_131 ;
long V_132 , V_133 , V_134 ;
T_1 V_135 ;
V_135 = ( 1 << 24 ) >> 1 ;
V_130 = F_62 ( V_126 , V_122 ) ;
if ( V_130 > 256 ) {
V_128 = F_63 ( V_130 - 1 ) ;
if ( V_128 > 9 ) {
V_130 >>= V_128 - 9 ;
V_135 >>= V_128 - 9 ;
}
V_130 += V_130 & 1 ;
}
V_128 = F_64 ( V_130 ) ;
V_130 >>= V_128 ;
V_135 >>= V_128 ;
V_133 = abs ( V_126 / ( 1 << ( 24 - F_63 ( V_135 ) ) ) / V_130 - V_122 ) ;
V_131 = F_62 ( V_127 , V_122 ) ;
V_134 = abs ( V_127 / V_131 - V_122 ) ;
if ( V_134 >= V_133 || V_131 > 256 ) {
V_132 = V_133 ;
V_129 = V_130 ;
} else {
V_132 = V_134 ;
V_129 = V_131 ;
V_135 = ( 1 << 24 ) * 2 / 5 ;
}
if ( V_125 / V_122 >= 80 ) {
T_4 V_136 ;
T_1 V_137 ;
V_130 = F_62 ( V_125 , V_122 ) ;
V_137 = ( 1 << 24 ) / V_130 ;
V_136 = ( T_4 ) V_125 * V_137 ;
F_65 ( V_136 , 1 << 24 ) ;
V_133 = abs ( V_136 - V_122 ) ;
if ( V_133 < V_132 ) {
V_129 = 1 ;
V_135 = V_137 ;
}
}
* V_123 = V_135 ;
return V_129 - 1 ;
}
static unsigned int F_66 ( struct V_2 * V_3 , int V_122 )
{
unsigned long V_138 = V_3 -> V_50 -> V_55 ;
const struct V_139 * V_140 = V_3 -> V_140 ;
V_122 = F_67 ( int , V_138 , V_122 ) ;
if ( V_140 -> type == V_141 || V_140 -> type == V_13 )
return ( V_138 / ( 2 * V_122 ) - 1 ) & 0xff ;
else
return ( V_138 / V_122 - 1 ) & 0xfff ;
}
static unsigned int F_68 ( struct V_2 * V_3 ,
int V_122 )
{
struct V_57 * V_58 =
F_26 ( V_3 -> V_50 -> V_51 -> V_52 ) ;
unsigned int V_29 ;
switch ( V_3 -> V_5 ) {
case V_11 :
V_29 = F_61 ( V_122 , & V_58 -> V_142 ) ;
break;
default:
V_29 = F_66 ( V_3 , V_122 ) ;
break;
}
return V_29 << 8 ;
}
static bool F_69 ( struct V_143 * V_50 ,
struct V_144 * V_52 ,
struct V_79 * V_145 )
{
struct V_57 * V_58 = F_26 ( V_52 ) ;
return V_58 -> V_44 &&
V_145 -> V_104 <= V_146 &&
V_145 -> V_104 >= V_58 -> V_147 ;
}
static void V_102 ( unsigned long V_148 )
{
struct V_2 * V_3 = (struct V_2 * ) V_148 ;
struct V_143 * V_50 = V_3 -> V_50 ;
struct V_77 * V_149 = V_50 -> V_51 ;
struct V_57 * V_58 = F_26 ( V_149 -> V_52 ) ;
T_1 V_150 = V_58 -> V_151 ;
T_1 V_152 = V_58 -> V_147 ;
T_1 V_153 = F_4 ( V_3 ) ;
struct V_79 * V_154 ;
struct V_79 * V_155 ;
T_1 V_29 ;
T_2 V_30 ;
T_1 V_156 ;
T_1 V_157 ;
T_1 V_158 ;
int V_159 ;
int V_160 ;
V_154 = V_3 -> V_81 ;
if ( V_149 -> V_93 == V_94 ) {
V_149 -> V_118 = - V_161 ;
F_43 ( V_3 ) ;
return;
}
if ( V_149 -> V_93 == V_86 ) {
V_149 -> V_118 = 0 ;
F_43 ( V_3 ) ;
return;
}
if ( V_149 -> V_93 == V_85 ) {
V_155 = F_42 ( V_154 -> V_82 . V_162 ,
struct V_79 ,
V_82 ) ;
if ( V_155 -> V_89 )
F_45 ( V_155 -> V_89 ) ;
if ( V_155 -> V_91 )
F_30 ( V_3 ) ;
}
if ( V_154 -> V_104 > V_146 && V_58 -> V_44 ) {
if ( V_149 -> V_163
|| V_154 -> V_164 || V_154 -> V_165 ) {
F_54 ( & V_3 -> V_100 -> V_101 ,
L_4
L_5 ,
V_154 -> V_104 , V_146 ) ;
V_149 -> V_118 = - V_166 ;
F_43 ( V_3 ) ;
return;
}
F_70 ( & V_149 -> V_52 -> V_101 ,
L_6
L_7 ,
( long ) V_3 -> V_104 , V_146 ) ;
}
if ( F_31 ( V_3 ) == 0 ) {
F_54 ( & V_3 -> V_100 -> V_101 , L_8 ) ;
V_149 -> V_118 = - V_161 ;
F_43 ( V_3 ) ;
return;
}
V_3 -> V_71 = V_58 -> V_71 ;
V_3 -> V_72 = ( void * ) V_154 -> V_167 ;
V_3 -> V_73 = V_3 -> V_72 + V_154 -> V_104 ;
V_3 -> V_74 = V_154 -> V_168 ;
V_3 -> V_75 = V_3 -> V_74 + V_154 -> V_104 ;
V_3 -> V_104 = V_154 -> V_104 ;
V_3 -> V_113 = V_3 -> V_72 ? V_58 -> V_113 : F_33 ;
V_3 -> V_112 = V_3 -> V_74 ? V_58 -> V_112 : F_34 ;
V_30 = V_154 -> V_169 ;
V_156 = V_154 -> V_170 ;
V_29 = F_68 ( V_3 , V_156 ) ;
if ( V_30 <= 8 ) {
V_3 -> V_71 = 1 ;
V_3 -> V_112 = V_3 -> V_112 != F_34 ?
F_36 : F_34 ;
V_3 -> V_113 = V_3 -> V_113 != F_33 ?
F_35 : F_33 ;
} else if ( V_30 <= 16 ) {
V_3 -> V_71 = 2 ;
V_3 -> V_112 = V_3 -> V_112 != F_34 ?
F_38 : F_34 ;
V_3 -> V_113 = V_3 -> V_113 != F_33 ?
F_37 : F_33 ;
} else if ( V_30 <= 32 ) {
V_3 -> V_71 = 4 ;
V_3 -> V_112 = V_3 -> V_112 != F_34 ?
F_40 : F_34 ;
V_3 -> V_113 = V_3 -> V_113 != F_33 ?
F_39 : F_33 ;
}
if ( V_58 -> V_44 ) {
if ( F_71 ( V_58 ,
V_149 -> V_52 ,
V_30 , & V_152 ,
& V_150 ) )
F_70 ( & V_149 -> V_52 -> V_101 ,
L_9 ) ;
}
V_149 -> V_93 = V_85 ;
V_160 = V_50 -> V_171 &&
V_50 -> V_171 ( V_50 , V_149 -> V_52 , V_154 ) &&
V_50 -> V_172 ;
if ( V_160 ) {
V_3 -> V_121 = V_173 ;
V_159 = F_72 ( V_3 , V_152 ) ;
if ( V_159 ) {
V_149 -> V_118 = V_159 ;
F_43 ( V_3 ) ;
return;
}
V_158 = V_58 -> V_158 | V_150 | V_3 -> V_174 ;
F_27 ( V_3 , V_23 , V_3 -> V_97 ) ;
F_73 ( V_3 ) ;
} else {
V_3 -> V_121 = F_57 ;
V_158 = V_58 -> V_158 | V_58 -> V_28 | V_3 -> V_96 ;
F_32 ( V_3 , V_3 -> V_97 ) ;
}
V_157 = F_13 ( V_3 , V_29 , V_30 ) ;
if ( ! F_53 ( V_3 ) )
F_74 ( & V_149 -> V_52 -> V_101 , L_10 ,
V_50 -> V_55
/ ( 1 + ( ( V_157 & F_75 ( 0xfff ) ) >> 8 ) ) ,
V_160 ? L_11 : L_12 ) ;
else
F_74 ( & V_149 -> V_52 -> V_101 , L_10 ,
V_50 -> V_55 / 2
/ ( 1 + ( ( V_157 & F_75 ( 0x0ff ) ) >> 8 ) ) ,
V_160 ? L_11 : L_12 ) ;
if ( F_2 ( V_3 ) ) {
if ( ( F_7 ( V_3 , V_175 ) & 0xff )
!= V_58 -> V_176 )
F_27 ( V_3 , V_175 ,
V_58 -> V_176 ) ;
if ( ( F_7 ( V_3 , V_177 ) & 0xffff )
!= V_58 -> V_178 )
F_27 ( V_3 , V_177 ,
V_58 -> V_178 ) ;
}
if ( F_3 ( V_3 ) &&
( F_7 ( V_3 , V_179 ) != V_58 -> V_142 ) )
F_27 ( V_3 , V_179 , V_58 -> V_142 ) ;
if ( ( F_7 ( V_3 , V_99 ) != V_157 )
|| ( F_7 ( V_3 , V_95 ) & V_153 )
!= ( V_158 & V_153 ) ) {
F_27 ( V_3 , V_99 , V_157 & ~ V_32 ) ;
if ( ! F_53 ( V_3 ) )
F_27 ( V_3 , V_98 , V_58 -> V_88 ) ;
F_27 ( V_3 , V_95 , V_158 & V_153 ) ;
F_27 ( V_3 , V_99 , V_157 ) ;
} else {
if ( ! F_53 ( V_3 ) )
F_27 ( V_3 , V_98 , V_58 -> V_88 ) ;
}
F_25 ( V_3 ) ;
F_27 ( V_3 , V_95 , V_158 ) ;
}
static int F_76 ( struct V_143 * V_50 ,
struct V_77 * V_78 )
{
struct V_2 * V_3 = F_77 ( V_50 ) ;
V_78 -> V_93 = V_180 ;
V_3 -> V_81 = F_42 ( V_78 -> V_84 . V_83 ,
struct V_79 ,
V_82 ) ;
F_55 ( & V_3 -> V_102 ) ;
return 0 ;
}
static int F_78 ( struct V_143 * V_50 )
{
struct V_2 * V_3 = F_77 ( V_50 ) ;
F_27 ( V_3 , V_99 ,
F_7 ( V_3 , V_99 ) & ~ V_32 ) ;
return 0 ;
}
static int F_79 ( struct V_144 * V_52 , struct V_57 * V_58 ,
struct V_181 * V_182 )
{
struct V_2 * V_3 = F_77 ( V_52 -> V_50 ) ;
int V_159 = 0 ;
if ( V_58 == NULL )
return 0 ;
if ( V_3 -> V_183 ) {
struct V_184 * V_185 ;
V_185 = V_3 -> V_183 [ V_52 -> V_53 ] ;
if ( V_185 ) {
V_58 -> V_62 = F_80 ( V_185 ) ;
V_58 -> V_63 = V_52 -> V_186 & V_187 ;
F_81 ( V_185 , V_58 -> V_63 ) ;
}
return 0 ;
}
if ( V_182 == NULL )
return 0 ;
if ( F_28 ( V_58 -> V_62 ) )
F_82 ( V_58 -> V_62 ) ;
if ( V_182 -> V_60 ) {
V_58 -> V_60 = V_182 -> V_60 ;
return 0 ;
}
if ( F_28 ( V_182 -> V_62 ) ) {
V_159 = F_83 ( V_182 -> V_62 , L_13 ) ;
if ( V_159 ) {
F_54 ( & V_52 -> V_101 , L_14 ,
V_182 -> V_62 ) ;
return V_159 ;
}
V_58 -> V_62 = V_182 -> V_62 ;
V_58 -> V_63 = V_52 -> V_186 & V_187 ;
V_159 = F_84 ( V_58 -> V_62 ,
! V_58 -> V_63 ) ;
}
return V_159 ;
}
static int F_85 ( struct V_144 * V_52 )
{
struct V_181 * V_182 ;
struct V_57 * V_58 ;
const struct V_1 * V_38 ;
struct V_2 * V_3 = F_77 ( V_52 -> V_50 ) ;
T_5 V_188 , V_189 , V_190 ;
switch ( V_3 -> V_5 ) {
case V_11 :
V_188 = V_191 ;
V_189 = 0 ;
V_190 = V_16 ;
break;
case V_13 :
V_188 = V_192 ;
V_189 = 0 ;
V_190 = V_17 ;
break;
case V_6 :
case V_7 :
case V_8 :
case V_9 :
case V_10 :
V_38 = F_1 ( V_3 ) ;
V_188 = V_38 -> V_193 ;
V_189 = V_38 -> V_194 ;
V_190 = V_38 -> V_195 ;
break;
default:
V_188 = V_196 ;
V_189 = 0 ;
V_190 = V_18 ;
break;
}
V_58 = F_26 ( V_52 ) ;
if ( ! V_58 ) {
V_58 = F_86 ( sizeof( struct V_57 ) , V_197 ) ;
if ( ! V_58 )
return - V_198 ;
if ( V_3 -> V_5 == V_13 ) {
if ( V_52 -> V_53 > 4 ) {
F_54 ( & V_52 -> V_101 ,
L_15 ) ;
F_87 ( V_58 ) ;
return - V_166 ;
}
V_58 -> V_59 = V_52 -> V_53 ;
} else
V_58 -> V_62 = - 1 ;
V_58 -> V_44 = V_3 -> V_43 -> V_44 ;
V_58 -> V_88 = V_199 ;
}
V_182 = V_52 -> V_200 ;
V_58 -> V_158 = 0 ;
if ( V_182 ) {
if ( V_182 -> V_88 )
V_58 -> V_88 = V_182 -> V_88 ;
if ( V_182 -> V_201 )
V_188 = V_182 -> V_201 ;
if ( V_182 -> V_202 )
V_189 = V_182 -> V_202 ;
if ( V_182 -> V_195 )
V_190 = V_182 -> V_195 ;
V_58 -> V_151 = 0 ;
if ( V_182 -> V_203 )
V_58 -> V_158 = V_204 ;
}
V_58 -> V_176 = F_88 ( V_190 ) ;
V_58 -> V_178 = F_89 ( V_188 )
| F_90 ( V_189 ) ;
if ( V_58 -> V_44 ) {
if ( F_71 ( V_58 , V_52 ,
V_52 -> V_169 ,
& V_58 -> V_147 ,
& V_58 -> V_151 ) ) {
F_91 ( & V_52 -> V_101 ,
L_16 ) ;
}
}
switch ( V_3 -> V_5 ) {
case V_11 :
V_58 -> V_28 = ( F_10 ( V_190 )
& V_25 )
| ( F_92 ( V_188 )
& V_205 ) ;
break;
case V_13 :
V_58 -> V_28 = ( F_11 ( V_190 ) & V_26 ) |
( F_93 ( V_188 ) & V_206 ) ;
break;
default:
V_58 -> V_28 = ( F_12 ( V_190 ) & V_27 ) |
( F_94 ( V_188 ) & V_207 ) ;
break;
}
V_58 -> V_158 &= ~ ( V_208 | V_209 ) ;
V_58 -> V_158 |= ( ( ( V_52 -> V_186 & V_210 ) != 0 ) ? V_209 : 0 )
| ( ( ( V_52 -> V_186 & V_211 ) != 0 ) ? V_208 : 0 ) ;
if ( V_52 -> V_186 & V_212 )
V_58 -> V_158 |= V_204 ;
if ( V_52 -> V_169 <= 8 ) {
V_58 -> V_71 = 1 ;
V_58 -> V_112 = F_36 ;
V_58 -> V_113 = F_35 ;
} else if ( V_52 -> V_169 <= 16 ) {
V_58 -> V_71 = 2 ;
V_58 -> V_112 = F_38 ;
V_58 -> V_113 = F_37 ;
} else if ( V_52 -> V_169 <= 32 ) {
V_58 -> V_71 = 4 ;
V_58 -> V_112 = F_40 ;
V_58 -> V_113 = F_39 ;
}
F_95 ( V_52 , V_58 ) ;
if ( V_3 -> V_5 == V_13 )
return 0 ;
return F_79 ( V_52 , V_58 , V_182 ) ;
}
static void F_96 ( struct V_144 * V_52 )
{
struct V_57 * V_58 = F_26 ( V_52 ) ;
struct V_2 * V_3 = F_77 ( V_52 -> V_50 ) ;
if ( ! V_58 )
return;
if ( V_3 -> V_5 != V_13 && ! V_3 -> V_183 &&
F_28 ( V_58 -> V_62 ) )
F_82 ( V_58 -> V_62 ) ;
F_87 ( V_58 ) ;
}
static int F_97 ( struct V_213 * V_214 )
{
unsigned int V_215 ;
int V_216 = - 1 ;
if ( V_214 && V_214 -> V_217 . V_218 &&
! F_98 ( V_214 -> V_217 . V_218 , 0 , & V_215 ) )
V_216 = V_215 ;
return V_216 ;
}
static int F_97 ( struct V_213 * V_214 )
{
return - 1 ;
}
static bool F_99 ( struct V_219 * V_220 , void * V_221 )
{
struct V_222 * V_101 = V_221 ;
if ( V_101 != V_220 -> V_222 -> V_101 -> V_223 )
return false ;
return true ;
}
static struct V_224 *
F_100 ( struct V_225 * V_100 )
{
struct V_224 * V_226 ;
struct V_213 * V_214 ;
struct V_139 * V_140 ;
struct V_227 * V_228 ;
const struct V_229 * V_230 = NULL ;
const struct V_231 * V_232 = NULL ;
int type ;
V_214 = F_101 ( & V_100 -> V_101 ) ;
if ( F_102 ( V_100 -> V_101 . V_223 ) )
V_232 = F_103 ( V_233 ,
F_104 ( V_100 -> V_101 . V_223 ) ) ;
else if ( V_214 )
V_230 = F_105 ( V_100 -> V_101 . V_234 -> V_235 ,
& V_100 -> V_101 ) ;
else
return NULL ;
if ( V_230 )
type = ( int ) V_230 -> V_2 ;
else if ( V_232 )
type = ( int ) V_232 -> V_2 ;
else
return NULL ;
V_226 = F_106 ( & V_100 -> V_101 , sizeof( * V_226 ) , V_197 ) ;
if ( ! V_226 )
return NULL ;
V_228 = F_107 ( V_100 , V_236 , 0 ) ;
if ( ! V_228 )
return NULL ;
V_140 = & V_226 -> V_140 ;
V_140 -> V_237 = V_228 -> V_238 ;
V_140 -> V_239 = F_108 ( & V_100 -> V_101 , V_228 ) ;
if ( F_109 ( V_140 -> V_239 ) )
return NULL ;
if ( V_232 ) {
V_226 -> V_240 = V_100 -> V_101 . V_223 ;
V_226 -> V_241 = V_100 -> V_101 . V_223 ;
V_226 -> V_242 = F_99 ;
}
V_140 -> V_243 = F_110 ( & V_100 -> V_101 , NULL ) ;
V_140 -> V_116 = F_111 ( V_100 , 0 ) ;
V_140 -> type = type ;
V_140 -> V_100 = V_100 ;
V_140 -> V_216 = F_97 ( V_214 ) ;
V_226 -> V_244 = 1 ;
V_226 -> V_44 = true ;
return V_226 ;
}
static inline struct V_224 *
F_100 ( struct V_225 * V_100 )
{
return NULL ;
}
static int F_112 ( struct V_143 * V_50 , unsigned V_48 )
{
struct V_2 * V_3 = F_77 ( V_50 ) ;
if ( F_113 ( & V_3 -> V_100 -> V_101 ) ) {
switch ( V_3 -> V_5 ) {
case V_7 :
case V_8 :
return V_48 - 1 ;
default:
break;
}
}
return V_48 ;
}
static int F_114 ( struct V_225 * V_100 )
{
struct V_222 * V_101 = & V_100 -> V_101 ;
struct V_224 * V_245 ;
struct V_143 * V_50 ;
struct V_2 * V_3 ;
struct V_139 * V_140 ;
const struct V_1 * V_38 ;
int V_118 , V_246 ;
T_1 V_247 ;
V_245 = F_115 ( V_101 ) ;
if ( ! V_245 ) {
V_245 = F_100 ( V_100 ) ;
if ( ! V_245 ) {
F_54 ( & V_100 -> V_101 , L_17 ) ;
return - V_248 ;
}
}
V_140 = F_116 ( V_100 -> V_249 , V_100 -> V_250 ) ;
if ( ! V_140 )
V_140 = & V_245 -> V_140 ;
if ( ! V_140 -> V_239 ) {
F_54 ( & V_100 -> V_101 , L_18 ) ;
return - V_248 ;
}
V_50 = F_117 ( V_101 , sizeof( struct V_2 ) ) ;
if ( ! V_50 ) {
F_54 ( & V_100 -> V_101 , L_19 ) ;
F_118 ( V_140 ) ;
return - V_198 ;
}
V_3 = F_77 ( V_50 ) ;
V_3 -> V_50 = V_50 ;
V_3 -> V_43 = V_245 ;
V_3 -> V_100 = V_100 ;
V_3 -> V_140 = V_140 ;
V_50 -> V_101 . V_251 = V_100 -> V_101 . V_251 ;
V_50 -> V_252 = V_211 | V_210 | V_187 | V_212 ;
V_50 -> V_253 = V_140 -> V_216 ;
V_50 -> V_254 = V_255 ;
V_50 -> F_96 = F_96 ;
V_50 -> F_85 = F_85 ;
V_50 -> V_256 = F_76 ;
V_50 -> V_257 = F_78 ;
V_50 -> V_258 = F_112 ;
V_50 -> V_259 = true ;
V_50 -> V_260 = V_261 | V_262 ;
V_3 -> V_5 = V_140 -> type ;
V_3 -> V_39 = V_140 -> V_239 ;
V_3 -> V_263 = V_140 -> V_237 + V_68 ;
if ( F_53 ( V_3 ) ) {
switch ( V_3 -> V_5 ) {
case V_11 :
V_50 -> V_264 = F_119 ( 4 , 32 ) ;
break;
default:
V_50 -> V_264 = F_119 ( 4 , 16 ) ;
break;
}
V_3 -> V_96 = V_106 | V_265 ;
V_3 -> V_174 = 0 ;
V_3 -> V_97 = V_70 ;
V_3 -> V_107 = V_266 | V_108 | V_70 ;
} else {
V_50 -> V_264 = F_119 ( 4 , 32 ) ;
V_3 -> V_96 = V_106 | V_265 | V_120 ;
V_3 -> V_174 = V_267 ;
V_3 -> V_97 = V_70 | V_111 ;
V_3 -> V_107 = V_111 | V_266 | V_108 | V_70 ;
}
V_118 = F_120 ( V_140 -> V_116 , F_59 , V_268 , F_121 ( V_101 ) ,
V_3 ) ;
if ( V_118 < 0 ) {
F_54 ( & V_100 -> V_101 , L_20 , V_140 -> V_116 ) ;
goto V_269;
}
if ( V_245 -> V_44 ) {
V_118 = F_122 ( V_3 ) ;
if ( V_118 ) {
F_74 ( V_101 , L_21 ) ;
V_245 -> V_44 = false ;
} else {
V_50 -> V_171 = F_69 ;
}
}
F_123 ( V_140 -> V_243 ) ;
V_50 -> V_55 = F_124 ( V_140 -> V_243 ) ;
F_27 ( V_3 , V_99 , 0 ) ;
switch ( V_3 -> V_5 ) {
case V_11 :
V_247 = F_10 ( V_16 ) |
F_92 ( V_191 ) ;
F_27 ( V_3 , V_95 , V_247 ) ;
V_247 = V_31 | F_14 ( 8 ) ;
F_27 ( V_3 , V_99 , V_247 ) ;
break;
case V_13 :
V_247 = F_11 ( V_17 ) |
F_93 ( V_192 ) ;
F_27 ( V_3 , V_95 , V_247 ) ;
V_247 = F_75 ( 2 ) | V_33 | F_15 ( 8 ) ;
F_27 ( V_3 , V_99 , V_247 ) ;
break;
default:
V_247 = F_12 ( V_18 ) |
F_94 ( V_196 ) ;
F_27 ( V_3 , V_95 , V_247 ) ;
V_247 = F_75 ( 2 ) | V_33 | F_15 ( 8 ) ;
F_27 ( V_3 , V_99 , V_247 ) ;
break;
}
if ( ! F_53 ( V_3 ) )
F_27 ( V_3 , V_98 , 0 ) ;
if ( ! F_3 ( V_3 ) )
F_27 ( V_3 , V_270 , 0 ) ;
if ( F_2 ( V_3 ) ) {
F_21 ( V_3 ) ;
V_38 = F_1 ( V_3 ) ;
if ( V_38 -> V_271 >= 0 ) {
V_247 = F_16 ( V_3 ,
V_38 -> V_271 ) ;
V_247 &= V_272 ;
V_247 >>= V_273 ;
V_245 -> V_244 = F_125 ( V_247 ) ;
} else if ( V_38 -> V_274 ) {
V_245 -> V_244 = V_38 -> V_274 ;
}
}
V_50 -> V_244 = V_245 -> V_244 ;
V_246 = F_126 ( & V_100 -> V_101 , L_22 ) ;
if ( V_246 > 0 ) {
int V_275 ;
V_50 -> V_244 = F_127 ( int , V_246 ,
V_50 -> V_244 ) ;
V_3 -> V_183 = F_128 ( & V_100 -> V_101 ,
V_50 -> V_244 , sizeof( struct V_184 * ) ,
V_197 ) ;
if ( ! V_3 -> V_183 ) {
V_118 = - V_198 ;
goto V_276;
}
for ( V_275 = 0 ; V_275 < V_50 -> V_244 ; V_275 ++ ) {
struct V_184 * V_185 ;
V_185 = F_129 ( V_101 , L_22 , V_275 ,
V_277 ) ;
if ( F_109 ( V_185 ) ) {
if ( F_130 ( V_185 ) == - V_278 )
continue;
V_118 = ( int ) F_130 ( V_185 ) ;
goto V_276;
} else {
V_3 -> V_183 [ V_275 ] = V_185 ;
}
}
}
F_131 ( & V_3 -> V_102 , V_102 ,
( unsigned long ) V_3 ) ;
F_132 ( & V_100 -> V_101 , 50 ) ;
F_133 ( & V_100 -> V_101 ) ;
F_134 ( & V_100 -> V_101 ) ;
F_135 ( & V_100 -> V_101 ) ;
F_136 ( V_100 , V_3 ) ;
V_118 = F_137 ( & V_100 -> V_101 , V_50 ) ;
if ( V_118 != 0 ) {
F_54 ( & V_100 -> V_101 , L_23 ) ;
goto V_276;
}
return V_118 ;
V_276:
F_138 ( V_140 -> V_243 ) ;
F_139 ( V_3 ) ;
F_140 ( V_140 -> V_116 , V_3 ) ;
V_269:
F_141 ( V_50 ) ;
F_118 ( V_140 ) ;
return V_118 ;
}
static int F_142 ( struct V_225 * V_100 )
{
struct V_2 * V_3 = F_143 ( V_100 ) ;
struct V_139 * V_140 ;
if ( ! V_3 )
return 0 ;
V_140 = V_3 -> V_140 ;
F_144 ( & V_100 -> V_101 ) ;
F_27 ( V_3 , V_99 , 0 ) ;
F_138 ( V_140 -> V_243 ) ;
if ( V_3 -> V_43 -> V_44 )
F_139 ( V_3 ) ;
F_145 ( & V_100 -> V_101 ) ;
F_146 ( & V_100 -> V_101 ) ;
F_140 ( V_140 -> V_116 , V_3 ) ;
F_118 ( V_140 ) ;
return 0 ;
}
static void F_147 ( struct V_225 * V_100 )
{
int V_118 = 0 ;
if ( ( V_118 = F_142 ( V_100 ) ) != 0 )
F_54 ( & V_100 -> V_101 , L_24 , V_118 ) ;
}
static int F_148 ( struct V_222 * V_101 )
{
struct V_2 * V_3 = F_149 ( V_101 ) ;
struct V_139 * V_140 = V_3 -> V_140 ;
int V_118 ;
V_118 = F_150 ( V_3 -> V_50 ) ;
if ( V_118 != 0 )
return V_118 ;
F_27 ( V_3 , V_99 , 0 ) ;
if ( ! F_60 ( V_101 ) )
F_138 ( V_140 -> V_243 ) ;
return 0 ;
}
static int F_151 ( struct V_222 * V_101 )
{
struct V_2 * V_3 = F_149 ( V_101 ) ;
struct V_139 * V_140 = V_3 -> V_140 ;
int V_118 ;
if ( ! F_60 ( V_101 ) )
F_123 ( V_140 -> V_243 ) ;
if ( F_2 ( V_3 ) )
F_21 ( V_3 ) ;
V_118 = F_152 ( V_3 -> V_50 ) ;
if ( V_118 != 0 ) {
F_54 ( V_101 , L_25 , V_118 ) ;
return V_118 ;
}
return 0 ;
}
static int F_153 ( struct V_222 * V_101 )
{
struct V_2 * V_3 = F_149 ( V_101 ) ;
F_138 ( V_3 -> V_140 -> V_243 ) ;
return 0 ;
}
static int F_154 ( struct V_222 * V_101 )
{
struct V_2 * V_3 = F_149 ( V_101 ) ;
F_123 ( V_3 -> V_140 -> V_243 ) ;
return 0 ;
}
static int T_6 F_155 ( void )
{
return F_156 ( & V_234 ) ;
}
static void T_7 F_157 ( void )
{
F_158 ( & V_234 ) ;
}
