static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
T_1 V_4 ;
V_3 = V_2 -> V_5 ( V_2 , V_6 , & V_4 , 1 ) ;
if ( V_3 < 0 ) {
F_2 ( L_1 , ( int ) V_3 ) ;
return V_3 ;
}
return V_4 ;
}
static int F_3 ( struct V_1 * V_2 )
{
int V_3 ;
T_1 V_4 ;
V_3 = V_2 -> V_5 ( V_2 , V_7 , & V_4 , 1 ) ;
if ( V_3 < 0 ) {
F_2 ( L_2 , V_3 ) ;
return V_3 ;
}
return V_4 ;
}
static int F_4 ( struct V_1 * V_2 )
{
int V_3 ;
T_1 V_4 ;
V_3 = V_2 -> V_5 ( V_2 , V_8 , & V_4 , 1 ) ;
if ( V_3 < 0 ) {
F_5 ( V_2 -> V_9 , L_3 , V_3 ) ;
return V_3 ;
}
return V_4 ;
}
static inline int F_6 ( struct V_1 * V_2 , T_1 V_4 )
{
V_2 -> V_10 [ 0 ] = V_4 ;
return V_2 -> V_11 ( V_2 , V_12 , V_2 -> V_10 , 1 ) ;
}
static inline int F_7 ( struct V_1 * V_2 )
{
return V_2 -> V_11 ( V_2 , V_13 , NULL , 0 ) ;
}
static inline int F_8 ( struct V_1 * V_2 )
{
return V_2 -> V_11 ( V_2 , V_14 , NULL , 0 ) ;
}
static inline struct V_1 * F_9 ( struct V_15 * V_16 )
{
return V_16 -> V_17 ;
}
static T_1 F_10 ( T_1 V_18 , const T_1 V_19 [] [ 2 ] , T_2 V_20 )
{
T_2 V_21 ;
for ( V_21 = 0 ; V_21 < V_20 ; V_21 ++ )
if ( V_19 [ V_21 ] [ 0 ] == V_18 )
return V_19 [ V_21 ] [ 1 ] ;
return V_18 ;
}
static inline T_1 F_11 ( T_1 V_18 )
{
static const T_1 V_22 [] [ 2 ] = {
{ V_23 , V_24 } ,
{ V_25 , V_26 } ,
{ V_27 , V_28 } ,
{ V_29 , V_30 } ,
{ V_31 , V_32 } ,
{ V_33 , V_34 } ,
{ V_35 , V_36 } ,
{ V_37 , V_38 } ,
{ V_39 , V_40 } ,
} ;
return F_10 ( V_18 , V_22 ,
F_12 ( V_22 ) ) ;
}
static inline T_1 F_13 ( T_1 V_18 )
{
static const T_1 V_41 [] [ 2 ] = {
{ V_42 , V_43 } ,
{ V_44 , V_45 } ,
{ V_46 , V_47 } ,
} ;
return F_10 ( V_18 , V_41 ,
F_12 ( V_41 ) ) ;
}
static inline T_1 F_14 ( T_1 V_18 )
{
static const T_1 V_48 [] [ 2 ] = {
{ V_49 , V_50 } ,
{ V_51 , V_52 } ,
{ V_53 , V_54 } ,
} ;
return F_10 ( V_18 , V_48 ,
F_12 ( V_48 ) ) ;
}
static void F_15 ( struct V_1 * V_2 ,
const struct V_55 * V_56 )
{
switch ( F_16 ( V_56 ) ) {
case V_57 :
V_2 -> V_58 = V_53 ;
V_2 -> V_16 . V_59 = V_56 -> V_60 ;
break;
default:
break;
}
V_2 -> V_61 = F_11 ( V_2 -> V_61 ) ;
V_2 -> V_62 = F_13 ( V_2 -> V_62 ) ;
V_2 -> V_58 = F_14 ( V_2 -> V_58 ) ;
}
static inline int F_17 ( struct V_1 * V_2 , const struct V_55 * V_56 ,
int V_63 )
{
int V_64 ;
bool V_65 = false ;
T_1 V_66 ;
switch ( F_16 ( V_56 ) ) {
case V_67 :
V_65 = true ;
case V_68 :
case V_69 :
if ( V_65 )
F_7 ( V_2 ) ;
V_66 = V_63 ? V_70 : V_71 ;
V_64 = V_2 -> V_11 ( V_2 , V_66 , NULL , 0 ) ;
if ( V_65 )
F_8 ( V_2 ) ;
return V_64 ;
default:
V_2 -> V_10 [ 0 ] = V_63 << 7 ;
return V_2 -> V_11 ( V_2 , V_72 , V_2 -> V_10 , 1 ) ;
}
}
static int F_18 ( struct V_1 * V_2 )
{
int V_3 ;
T_1 V_4 ;
V_3 = V_2 -> V_5 ( V_2 , V_73 , & V_4 , 1 ) ;
if ( V_3 < 0 ) {
F_5 ( V_2 -> V_9 , L_4 , ( int ) V_3 ) ;
return V_3 ;
}
return ! ! ( V_4 & V_74 ) ;
}
static inline int F_19 ( struct V_1 * V_2 )
{
int V_75 = F_1 ( V_2 ) ;
if ( V_75 < 0 )
return V_75 ;
if ( V_2 -> V_76 & V_77 && V_75 & ( V_78 | V_79 ) ) {
if ( V_75 & V_78 )
F_5 ( V_2 -> V_9 , L_5 ) ;
else
F_5 ( V_2 -> V_9 , L_6 ) ;
V_2 -> V_11 ( V_2 , V_80 , NULL , 0 ) ;
return - V_81 ;
}
return ! ( V_75 & V_82 ) ;
}
static inline int F_20 ( struct V_1 * V_2 )
{
int V_83 = F_3 ( V_2 ) ;
if ( V_83 < 0 )
return V_83 ;
else
return V_83 & V_84 ;
}
static int F_21 ( struct V_1 * V_2 )
{
int V_75 , V_83 ;
if ( V_2 -> V_76 & V_85 )
V_75 = F_18 ( V_2 ) ;
else
V_75 = F_19 ( V_2 ) ;
if ( V_75 < 0 )
return V_75 ;
V_83 = V_2 -> V_76 & V_86 ? F_20 ( V_2 ) : 1 ;
if ( V_83 < 0 )
return V_83 ;
return V_75 && V_83 ;
}
static int F_22 ( struct V_1 * V_2 ,
unsigned long V_87 )
{
unsigned long V_88 ;
int V_89 = 0 , V_3 ;
V_88 = V_90 + V_87 ;
while ( ! V_89 ) {
if ( F_23 ( V_90 , V_88 ) )
V_89 = 1 ;
V_3 = F_21 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_3 )
return 0 ;
F_24 () ;
}
F_5 ( V_2 -> V_9 , L_7 ) ;
return - V_91 ;
}
static int F_25 ( struct V_1 * V_2 )
{
return F_22 ( V_2 ,
V_92 ) ;
}
static int F_26 ( struct V_1 * V_2 )
{
F_27 ( V_2 -> V_9 , L_8 , ( long long ) ( V_2 -> V_16 . V_20 >> 10 ) ) ;
return V_2 -> V_11 ( V_2 , V_93 , NULL , 0 ) ;
}
static int F_28 ( struct V_1 * V_2 , enum V_94 V_95 )
{
int V_3 = 0 ;
F_29 ( & V_2 -> V_96 ) ;
if ( V_2 -> V_97 ) {
V_3 = V_2 -> V_97 ( V_2 , V_95 ) ;
if ( V_3 ) {
F_5 ( V_2 -> V_9 , L_9 ) ;
F_30 ( & V_2 -> V_96 ) ;
return V_3 ;
}
}
return V_3 ;
}
static void F_31 ( struct V_1 * V_2 , enum V_94 V_95 )
{
if ( V_2 -> V_98 )
V_2 -> V_98 ( V_2 , V_95 ) ;
F_30 ( & V_2 -> V_96 ) ;
}
static T_3 F_32 ( struct V_1 * V_2 , unsigned int V_99 )
{
unsigned int V_100 ;
unsigned int V_101 ;
V_100 = V_99 % V_2 -> V_102 ;
V_101 = V_99 / V_2 -> V_102 ;
V_101 <<= ( V_2 -> V_102 > 512 ) ? 10 : 9 ;
return V_101 | V_100 ;
}
static int F_33 ( struct V_1 * V_2 , T_4 V_99 )
{
T_1 V_103 [ V_104 ] ;
int V_21 ;
if ( V_2 -> V_76 & V_105 )
V_99 = F_32 ( V_2 , V_99 ) ;
if ( V_2 -> V_106 )
return V_2 -> V_106 ( V_2 , V_99 ) ;
for ( V_21 = V_2 -> V_107 - 1 ; V_21 >= 0 ; V_21 -- ) {
V_103 [ V_21 ] = V_99 & 0xff ;
V_99 >>= 8 ;
}
return V_2 -> V_11 ( V_2 , V_2 -> V_58 , V_103 , V_2 -> V_107 ) ;
}
static int F_34 ( struct V_15 * V_16 , struct V_108 * V_109 )
{
struct V_1 * V_2 = F_9 ( V_16 ) ;
T_4 V_99 , V_110 ;
T_5 V_111 ;
int V_3 ;
F_27 ( V_2 -> V_9 , L_10 , ( long long ) V_109 -> V_99 ,
( long long ) V_109 -> V_110 ) ;
F_35 ( V_109 -> V_110 , V_16 -> V_59 , & V_111 ) ;
if ( V_111 )
return - V_112 ;
V_99 = V_109 -> V_99 ;
V_110 = V_109 -> V_110 ;
V_3 = F_28 ( V_2 , V_113 ) ;
if ( V_3 )
return V_3 ;
if ( V_110 == V_16 -> V_20 && ! ( V_2 -> V_76 & V_114 ) ) {
unsigned long V_89 ;
F_7 ( V_2 ) ;
if ( F_26 ( V_2 ) ) {
V_3 = - V_81 ;
goto V_115;
}
V_89 = F_36 ( V_116 ,
V_116 *
( unsigned long ) ( V_16 -> V_20 / V_117 ) ) ;
V_3 = F_22 ( V_2 , V_89 ) ;
if ( V_3 )
goto V_115;
} else {
while ( V_110 ) {
F_7 ( V_2 ) ;
V_3 = F_33 ( V_2 , V_99 ) ;
if ( V_3 )
goto V_115;
V_99 += V_16 -> V_59 ;
V_110 -= V_16 -> V_59 ;
V_3 = F_25 ( V_2 ) ;
if ( V_3 )
goto V_115;
}
}
F_8 ( V_2 ) ;
V_115:
F_31 ( V_2 , V_113 ) ;
V_109 -> V_118 = V_3 ? V_119 : V_120 ;
F_37 ( V_109 ) ;
return V_3 ;
}
static void F_38 ( struct V_1 * V_2 , T_1 V_75 , T_3 * V_121 ,
T_6 * V_110 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
T_1 V_122 = V_123 | V_124 | V_125 ;
int V_126 = F_39 ( V_122 ) - 1 ;
int pow ;
if ( ! ( V_75 & V_122 ) ) {
* V_121 = 0 ;
* V_110 = 0 ;
} else {
pow = ( ( V_75 & V_122 ) ^ V_122 ) >> V_126 ;
* V_110 = V_16 -> V_20 >> pow ;
if ( V_2 -> V_76 & V_127 && V_75 & V_128 )
* V_121 = 0 ;
else
* V_121 = V_16 -> V_20 - * V_110 ;
}
}
static int F_40 ( struct V_1 * V_2 , T_3 V_121 , T_6 V_110 ,
T_1 V_75 , bool V_129 )
{
T_3 V_130 ;
T_6 V_131 ;
if ( ! V_110 )
return 1 ;
F_38 ( V_2 , V_75 , & V_130 , & V_131 ) ;
if ( V_129 )
return ( V_121 + V_110 <= V_130 + V_131 ) && ( V_121 >= V_130 ) ;
else
return ( V_121 >= V_130 + V_131 ) || ( V_121 + V_110 <= V_130 ) ;
}
static int F_41 ( struct V_1 * V_2 , T_3 V_121 , T_6 V_110 ,
T_1 V_75 )
{
return F_40 ( V_2 , V_121 , V_110 , V_75 , true ) ;
}
static int F_42 ( struct V_1 * V_2 , T_3 V_121 , T_6 V_110 ,
T_1 V_75 )
{
return F_40 ( V_2 , V_121 , V_110 , V_75 , false ) ;
}
static int F_43 ( struct V_1 * V_2 , T_3 V_121 , T_6 V_110 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
int V_132 , V_133 ;
T_1 V_122 = V_123 | V_124 | V_125 ;
T_1 V_126 = F_39 ( V_122 ) - 1 , pow , V_4 ;
T_3 V_131 ;
bool V_134 = true , V_135 = V_2 -> V_76 & V_127 ;
bool V_136 ;
int V_3 ;
V_132 = F_1 ( V_2 ) ;
if ( V_132 < 0 )
return V_132 ;
if ( F_41 ( V_2 , V_121 , V_110 , V_132 ) )
return 0 ;
if ( ! F_41 ( V_2 , 0 , V_121 , V_132 ) )
V_135 = false ;
if ( ! F_41 ( V_2 , V_121 + V_110 , V_16 -> V_20 - ( V_121 + V_110 ) ,
V_132 ) )
V_134 = false ;
if ( ! V_135 && ! V_134 )
return - V_112 ;
V_136 = V_134 ;
if ( V_136 )
V_131 = V_16 -> V_20 - V_121 ;
else
V_131 = V_121 + V_110 ;
pow = F_44 ( V_16 -> V_20 ) - F_44 ( V_131 ) ;
V_4 = V_122 - ( pow << V_126 ) ;
if ( V_4 & ~ V_122 )
return - V_112 ;
if ( ! ( V_4 & V_122 ) )
return - V_112 ;
V_133 = ( V_132 & ~ V_122 & ~ V_128 ) | V_4 ;
V_133 |= V_137 ;
if ( ! V_136 )
V_133 |= V_128 ;
if ( V_133 == V_132 )
return 0 ;
if ( ( V_133 & V_122 ) < ( V_132 & V_122 ) )
return - V_112 ;
F_7 ( V_2 ) ;
V_3 = F_6 ( V_2 , V_133 ) ;
if ( V_3 )
return V_3 ;
return F_25 ( V_2 ) ;
}
static int F_45 ( struct V_1 * V_2 , T_3 V_121 , T_6 V_110 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
int V_132 , V_133 ;
T_1 V_122 = V_123 | V_124 | V_125 ;
T_1 V_126 = F_39 ( V_122 ) - 1 , pow , V_4 ;
T_3 V_131 ;
bool V_134 = true , V_135 = V_2 -> V_76 & V_127 ;
bool V_136 ;
int V_3 ;
V_132 = F_1 ( V_2 ) ;
if ( V_132 < 0 )
return V_132 ;
if ( F_42 ( V_2 , V_121 , V_110 , V_132 ) )
return 0 ;
if ( ! F_42 ( V_2 , 0 , V_121 , V_132 ) )
V_134 = false ;
if ( ! F_42 ( V_2 , V_121 + V_110 , V_16 -> V_20 - ( V_121 + V_110 ) ,
V_132 ) )
V_135 = false ;
if ( ! V_135 && ! V_134 )
return - V_112 ;
V_136 = V_134 ;
if ( V_136 )
V_131 = V_16 -> V_20 - ( V_121 + V_110 ) ;
else
V_131 = V_121 ;
pow = F_44 ( V_16 -> V_20 ) - F_46 ( V_131 ) ;
if ( V_131 == 0 ) {
V_4 = 0 ;
} else {
V_4 = V_122 - ( pow << V_126 ) ;
if ( V_4 & ~ V_122 )
return - V_112 ;
}
V_133 = ( V_132 & ~ V_122 & ~ V_128 ) | V_4 ;
if ( V_131 == 0 )
V_133 &= ~ V_137 ;
if ( ! V_136 )
V_133 |= V_128 ;
if ( V_133 == V_132 )
return 0 ;
if ( ( V_133 & V_122 ) > ( V_132 & V_122 ) )
return - V_112 ;
F_7 ( V_2 ) ;
V_3 = F_6 ( V_2 , V_133 ) ;
if ( V_3 )
return V_3 ;
return F_25 ( V_2 ) ;
}
static int F_47 ( struct V_1 * V_2 , T_3 V_121 , T_6 V_110 )
{
int V_64 ;
V_64 = F_1 ( V_2 ) ;
if ( V_64 < 0 )
return V_64 ;
return F_41 ( V_2 , V_121 , V_110 , V_64 ) ;
}
static int F_48 ( struct V_15 * V_16 , T_3 V_121 , T_6 V_110 )
{
struct V_1 * V_2 = F_9 ( V_16 ) ;
int V_3 ;
V_3 = F_28 ( V_2 , V_138 ) ;
if ( V_3 )
return V_3 ;
V_3 = V_2 -> V_139 ( V_2 , V_121 , V_110 ) ;
F_31 ( V_2 , V_140 ) ;
return V_3 ;
}
static int F_49 ( struct V_15 * V_16 , T_3 V_121 , T_6 V_110 )
{
struct V_1 * V_2 = F_9 ( V_16 ) ;
int V_3 ;
V_3 = F_28 ( V_2 , V_140 ) ;
if ( V_3 )
return V_3 ;
V_3 = V_2 -> V_141 ( V_2 , V_121 , V_110 ) ;
F_31 ( V_2 , V_138 ) ;
return V_3 ;
}
static int F_50 ( struct V_15 * V_16 , T_3 V_121 , T_6 V_110 )
{
struct V_1 * V_2 = F_9 ( V_16 ) ;
int V_3 ;
V_3 = F_28 ( V_2 , V_140 ) ;
if ( V_3 )
return V_3 ;
V_3 = V_2 -> V_142 ( V_2 , V_121 , V_110 ) ;
F_31 ( V_2 , V_138 ) ;
return V_3 ;
}
static const struct V_55 * F_51 ( struct V_1 * V_2 )
{
int V_143 ;
T_1 V_144 [ V_145 ] ;
const struct V_55 * V_56 ;
V_143 = V_2 -> V_5 ( V_2 , V_146 , V_144 , V_145 ) ;
if ( V_143 < 0 ) {
F_27 ( V_2 -> V_9 , L_11 , V_143 ) ;
return F_52 ( V_143 ) ;
}
for ( V_143 = 0 ; V_143 < F_12 ( V_147 ) - 1 ; V_143 ++ ) {
V_56 = & V_147 [ V_143 ] ;
if ( V_56 -> V_148 ) {
if ( ! memcmp ( V_56 -> V_144 , V_144 , V_56 -> V_148 ) )
return & V_147 [ V_143 ] ;
}
}
F_5 ( V_2 -> V_9 , L_12 ,
V_144 [ 0 ] , V_144 [ 1 ] , V_144 [ 2 ] ) ;
return F_52 ( - V_149 ) ;
}
static int F_53 ( struct V_15 * V_16 , T_3 V_150 , T_2 V_110 ,
T_2 * V_151 , T_7 * V_103 )
{
struct V_1 * V_2 = F_9 ( V_16 ) ;
int V_3 ;
F_27 ( V_2 -> V_9 , L_13 , ( T_4 ) V_150 , V_110 ) ;
V_3 = F_28 ( V_2 , V_152 ) ;
if ( V_3 )
return V_3 ;
while ( V_110 ) {
T_3 V_99 = V_150 ;
if ( V_2 -> V_76 & V_105 )
V_99 = F_32 ( V_2 , V_99 ) ;
V_3 = V_2 -> V_153 ( V_2 , V_99 , V_110 , V_103 ) ;
if ( V_3 == 0 ) {
V_3 = - V_81 ;
goto V_154;
}
if ( V_3 < 0 )
goto V_154;
F_54 ( V_3 > V_110 ) ;
* V_151 += V_3 ;
V_103 += V_3 ;
V_150 += V_3 ;
V_110 -= V_3 ;
}
V_3 = 0 ;
V_154:
F_31 ( V_2 , V_152 ) ;
return V_3 ;
}
static int F_55 ( struct V_15 * V_16 , T_3 V_155 , T_2 V_110 ,
T_2 * V_151 , const T_7 * V_103 )
{
struct V_1 * V_2 = F_9 ( V_16 ) ;
T_2 V_156 ;
int V_3 ;
F_27 ( V_2 -> V_9 , L_14 , ( T_4 ) V_155 , V_110 ) ;
V_3 = F_28 ( V_2 , V_157 ) ;
if ( V_3 )
return V_3 ;
F_7 ( V_2 ) ;
V_2 -> V_158 = false ;
V_156 = V_155 % 2 ;
if ( V_156 ) {
V_2 -> V_62 = V_159 ;
V_3 = V_2 -> V_160 ( V_2 , V_155 , 1 , V_103 ) ;
if ( V_3 < 0 )
goto V_161;
F_56 ( V_3 != 1 , L_15 ,
( int ) V_3 ) ;
V_3 = F_25 ( V_2 ) ;
if ( V_3 )
goto V_161;
}
V_155 += V_156 ;
for (; V_156 < V_110 - 1 ; V_156 += 2 ) {
V_2 -> V_62 = V_162 ;
V_3 = V_2 -> V_160 ( V_2 , V_155 , 2 , V_103 + V_156 ) ;
if ( V_3 < 0 )
goto V_161;
F_56 ( V_3 != 2 , L_16 ,
( int ) V_3 ) ;
V_3 = F_25 ( V_2 ) ;
if ( V_3 )
goto V_161;
V_155 += 2 ;
V_2 -> V_158 = true ;
}
V_2 -> V_158 = false ;
F_8 ( V_2 ) ;
V_3 = F_25 ( V_2 ) ;
if ( V_3 )
goto V_161;
if ( V_156 != V_110 ) {
F_7 ( V_2 ) ;
V_2 -> V_62 = V_159 ;
V_3 = V_2 -> V_160 ( V_2 , V_155 , 1 , V_103 + V_156 ) ;
if ( V_3 < 0 )
goto V_161;
F_56 ( V_3 != 1 , L_15 ,
( int ) V_3 ) ;
V_3 = F_25 ( V_2 ) ;
if ( V_3 )
goto V_161;
F_8 ( V_2 ) ;
V_156 += 1 ;
}
V_161:
* V_151 += V_156 ;
F_31 ( V_2 , V_157 ) ;
return V_3 ;
}
static int F_57 ( struct V_15 * V_16 , T_3 V_155 , T_2 V_110 ,
T_2 * V_151 , const T_7 * V_103 )
{
struct V_1 * V_2 = F_9 ( V_16 ) ;
T_2 V_163 , V_164 , V_21 ;
T_8 V_3 ;
F_27 ( V_2 -> V_9 , L_14 , ( T_4 ) V_155 , V_110 ) ;
V_3 = F_28 ( V_2 , V_157 ) ;
if ( V_3 )
return V_3 ;
for ( V_21 = 0 ; V_21 < V_110 ; ) {
T_8 V_165 ;
T_3 V_99 = V_155 + V_21 ;
if ( F_58 ( V_2 -> V_102 ) == 1 ) {
V_163 = V_99 & ( V_2 -> V_102 - 1 ) ;
} else {
T_6 V_166 = V_99 ;
V_163 = F_59 ( V_166 , V_2 -> V_102 ) ;
}
V_164 = F_60 ( T_2 ,
V_2 -> V_102 - V_163 , V_110 - V_21 ) ;
if ( V_2 -> V_76 & V_105 )
V_99 = F_32 ( V_2 , V_99 ) ;
F_7 ( V_2 ) ;
V_3 = V_2 -> V_160 ( V_2 , V_99 , V_164 , V_103 + V_21 ) ;
if ( V_3 < 0 )
goto V_167;
V_165 = V_3 ;
V_3 = F_25 ( V_2 ) ;
if ( V_3 )
goto V_167;
* V_151 += V_165 ;
V_21 += V_165 ;
if ( V_165 != V_164 ) {
F_5 ( V_2 -> V_9 ,
L_17 ,
V_164 , V_165 ) ;
V_3 = - V_81 ;
goto V_167;
}
}
V_167:
F_31 ( V_2 , V_157 ) ;
return V_3 ;
}
static int F_61 ( struct V_1 * V_2 )
{
int V_3 , V_4 ;
V_4 = F_1 ( V_2 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( V_4 & V_168 )
return 0 ;
F_7 ( V_2 ) ;
F_6 ( V_2 , V_4 | V_168 ) ;
V_3 = F_25 ( V_2 ) ;
if ( V_3 )
return V_3 ;
V_3 = F_1 ( V_2 ) ;
if ( ! ( V_3 > 0 && ( V_3 & V_168 ) ) ) {
F_5 ( V_2 -> V_9 , L_18 ) ;
return - V_112 ;
}
return 0 ;
}
static int F_62 ( struct V_1 * V_2 , T_1 * V_169 )
{
int V_3 ;
F_7 ( V_2 ) ;
V_3 = V_2 -> V_11 ( V_2 , V_12 , V_169 , 2 ) ;
if ( V_3 < 0 ) {
F_5 ( V_2 -> V_9 ,
L_19 ) ;
return - V_112 ;
}
V_3 = F_25 ( V_2 ) ;
if ( V_3 ) {
F_5 ( V_2 -> V_9 ,
L_20 ) ;
return V_3 ;
}
return 0 ;
}
static int F_63 ( struct V_1 * V_2 )
{
T_1 V_169 [ 2 ] = { 0 , V_170 } ;
int V_3 ;
V_3 = F_62 ( V_2 , V_169 ) ;
if ( V_3 )
return V_3 ;
V_3 = F_4 ( V_2 ) ;
if ( ! ( V_3 > 0 && ( V_3 & V_170 ) ) ) {
F_5 ( V_2 -> V_9 , L_21 ) ;
return - V_112 ;
}
return 0 ;
}
static int F_64 ( struct V_1 * V_2 )
{
T_1 V_169 [ 2 ] ;
int V_3 ;
V_3 = F_1 ( V_2 ) ;
if ( V_3 < 0 ) {
F_5 ( V_2 -> V_9 , L_22 ) ;
return - V_112 ;
}
V_169 [ 0 ] = V_3 ;
V_169 [ 1 ] = V_170 ;
return F_62 ( V_2 , V_169 ) ;
}
static int F_65 ( struct V_1 * V_2 )
{
struct V_171 * V_9 = V_2 -> V_9 ;
T_1 V_169 [ 2 ] ;
int V_3 ;
V_3 = F_4 ( V_2 ) ;
if ( V_3 < 0 ) {
F_5 ( V_9 , L_23 ) ;
return - V_112 ;
}
if ( V_3 & V_170 )
return 0 ;
V_169 [ 1 ] = V_3 | V_170 ;
V_3 = F_1 ( V_2 ) ;
if ( V_3 < 0 ) {
F_5 ( V_9 , L_22 ) ;
return - V_112 ;
}
V_169 [ 0 ] = V_3 ;
V_3 = F_62 ( V_2 , V_169 ) ;
if ( V_3 )
return V_3 ;
V_3 = F_4 ( V_2 ) ;
if ( ! ( V_3 > 0 && ( V_3 & V_170 ) ) ) {
F_5 ( V_2 -> V_9 , L_21 ) ;
return - V_112 ;
}
return 0 ;
}
static int F_66 ( struct V_1 * V_2 )
{
T_1 V_172 ;
int V_3 ;
V_3 = V_2 -> V_5 ( V_2 , V_173 , & V_172 , 1 ) ;
if ( V_3 )
return V_3 ;
if ( V_172 & V_174 )
return 0 ;
V_172 |= V_174 ;
F_7 ( V_2 ) ;
V_3 = V_2 -> V_11 ( V_2 , V_175 , & V_172 , 1 ) ;
if ( V_3 < 0 ) {
F_5 ( V_2 -> V_9 , L_24 ) ;
return - V_112 ;
}
V_3 = F_25 ( V_2 ) ;
if ( V_3 < 0 ) {
F_5 ( V_2 -> V_9 , L_25 ) ;
return V_3 ;
}
V_3 = V_2 -> V_5 ( V_2 , V_173 , & V_172 , 1 ) ;
if ( ! ( V_3 > 0 && ( V_172 & V_174 ) ) ) {
F_5 ( V_2 -> V_9 , L_26 ) ;
return - V_112 ;
}
return 0 ;
}
static int F_67 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_9 || ! V_2 -> V_153 || ! V_2 -> V_160 ||
! V_2 -> V_5 || ! V_2 -> V_11 ) {
F_2 ( L_27 ) ;
return - V_112 ;
}
return 0 ;
}
static int F_68 ( const struct V_55 * V_56 , struct V_1 * V_2 )
{
int V_3 ;
T_1 V_4 ;
V_3 = V_2 -> V_5 ( V_2 , V_73 , & V_4 , 1 ) ;
if ( V_3 < 0 ) {
F_5 ( V_2 -> V_9 , L_4 , ( int ) V_3 ) ;
return V_3 ;
}
V_2 -> V_58 = V_176 ;
V_2 -> V_62 = V_177 ;
V_2 -> V_61 = V_23 ;
V_2 -> V_76 |= V_114 ;
if ( V_4 & V_178 ) {
V_2 -> V_102 = ( V_2 -> V_102 == 264 ) ? 256 : 512 ;
V_2 -> V_16 . V_179 = V_2 -> V_102 ;
V_2 -> V_16 . V_20 = 8 * V_2 -> V_102 * V_56 -> V_180 ;
V_2 -> V_16 . V_59 = 8 * V_2 -> V_102 ;
} else {
V_2 -> V_76 |= V_105 ;
}
return 0 ;
}
static void
F_69 ( struct V_181 * V_153 ,
T_1 V_182 ,
T_1 V_183 ,
T_1 V_18 ,
enum V_184 V_185 )
{
V_153 -> V_182 = V_182 ;
V_153 -> V_183 = V_183 ;
V_153 -> V_18 = V_18 ;
V_153 -> V_185 = V_185 ;
}
static void
F_70 ( struct V_186 * V_187 ,
T_1 V_18 ,
enum V_184 V_185 )
{
V_187 -> V_18 = V_18 ;
V_187 -> V_185 = V_185 ;
}
static int F_71 ( struct V_1 * V_2 , T_4 V_99 ,
T_2 V_110 , void * V_103 )
{
T_1 V_107 , V_61 , V_188 ;
int V_3 ;
V_61 = V_2 -> V_61 ;
V_107 = V_2 -> V_107 ;
V_188 = V_2 -> V_188 ;
V_2 -> V_61 = V_189 ;
V_2 -> V_107 = 3 ;
V_2 -> V_188 = 8 ;
while ( V_110 ) {
V_3 = V_2 -> V_153 ( V_2 , V_99 , V_110 , ( T_1 * ) V_103 ) ;
if ( ! V_3 || V_3 > V_110 ) {
V_3 = - V_81 ;
goto V_154;
}
if ( V_3 < 0 )
goto V_154;
V_103 += V_3 ;
V_99 += V_3 ;
V_110 -= V_3 ;
}
V_3 = 0 ;
V_154:
V_2 -> V_61 = V_61 ;
V_2 -> V_107 = V_107 ;
V_2 -> V_188 = V_188 ;
return V_3 ;
}
static int F_72 ( struct V_1 * V_2 , T_4 V_99 ,
T_2 V_110 , void * V_103 )
{
void * V_190 ;
int V_3 ;
V_190 = F_73 ( V_110 , V_191 ) ;
if ( ! V_190 )
return - V_192 ;
V_3 = F_71 ( V_2 , V_99 , V_110 , V_190 ) ;
memcpy ( V_103 , V_190 , V_110 ) ;
F_74 ( V_190 ) ;
return V_3 ;
}
static inline void
F_75 ( struct V_181 * V_153 ,
T_9 V_193 ,
enum V_184 V_185 )
{
V_153 -> V_182 = ( V_193 >> 5 ) & 0x07 ;
V_153 -> V_183 = ( V_193 >> 0 ) & 0x1f ;
V_153 -> V_18 = ( V_193 >> 8 ) & 0xff ;
V_153 -> V_185 = V_185 ;
}
static int F_76 ( struct V_1 * V_2 ,
const struct V_194 * V_195 ,
struct V_196 * V_197 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
struct V_198 V_199 ;
T_2 V_110 ;
int V_21 , V_66 , V_200 ;
T_4 V_99 ;
T_9 V_193 ;
if ( V_195 -> V_201 < V_202 )
return - V_112 ;
V_110 = F_60 ( T_2 , sizeof( V_199 ) ,
V_195 -> V_201 * sizeof( T_4 ) ) ;
V_99 = F_77 ( V_195 ) ;
memset ( & V_199 , 0 , sizeof( V_199 ) ) ;
V_200 = F_72 ( V_2 , V_99 , V_110 , & V_199 ) ;
if ( V_200 < 0 )
return V_200 ;
for ( V_21 = 0 ; V_21 < V_203 ; V_21 ++ )
V_199 . V_204 [ V_21 ] = F_78 ( V_199 . V_204 [ V_21 ] ) ;
switch ( V_199 . V_204 [ F_79 ( 1 ) ] & V_205 ) {
case V_206 :
V_2 -> V_107 = 3 ;
break;
case V_207 :
V_2 -> V_107 = 4 ;
break;
default:
break;
}
V_197 -> V_20 = V_199 . V_204 [ F_79 ( 2 ) ] ;
if ( V_197 -> V_20 & F_80 ( 31 ) ) {
V_197 -> V_20 &= ~ F_80 ( 31 ) ;
if ( V_197 -> V_20 > 63 )
return - V_112 ;
V_197 -> V_20 = 1ULL << V_197 -> V_20 ;
} else {
V_197 -> V_20 ++ ;
}
V_197 -> V_20 >>= 3 ;
for ( V_21 = 0 ; V_21 < F_12 ( V_208 ) ; V_21 ++ ) {
const struct V_209 * V_210 = & V_208 [ V_21 ] ;
struct V_181 * V_153 ;
if ( ! ( V_199 . V_204 [ V_210 -> V_211 ] & V_210 -> V_212 ) ) {
V_197 -> V_213 . V_122 &= ~ V_210 -> V_213 ;
continue;
}
V_197 -> V_213 . V_122 |= V_210 -> V_213 ;
V_66 = F_81 ( V_210 -> V_213 ) ;
V_153 = & V_197 -> V_214 [ V_66 ] ;
V_193 = V_199 . V_204 [ V_210 -> V_215 ] >> V_210 -> V_216 ;
F_75 ( V_153 , V_193 , V_210 -> V_185 ) ;
}
for ( V_21 = 0 ; V_21 < F_12 ( V_217 ) ; V_21 ++ ) {
const struct V_218 * V_219 = & V_217 [ V_21 ] ;
T_4 V_59 ;
T_1 V_18 ;
V_193 = V_199 . V_204 [ V_219 -> V_220 ] >> V_219 -> V_126 ;
V_59 = V_193 & 0xff ;
if ( ! V_59 )
continue;
V_59 = 1U << V_59 ;
V_18 = ( V_193 >> 8 ) & 0xff ;
#ifdef F_82
if ( V_59 == V_221 ) {
V_2 -> V_58 = V_18 ;
V_16 -> V_59 = V_59 ;
break;
}
#endif
if ( ! V_16 -> V_59 || V_16 -> V_59 < V_59 ) {
V_2 -> V_58 = V_18 ;
V_16 -> V_59 = V_59 ;
}
}
if ( V_195 -> V_201 < V_203 )
return 0 ;
V_197 -> V_102 = V_199 . V_204 [ F_79 ( 11 ) ] ;
V_197 -> V_102 &= V_222 ;
V_197 -> V_102 >>= V_223 ;
V_197 -> V_102 = 1U << V_197 -> V_102 ;
switch ( V_199 . V_204 [ F_79 ( 15 ) ] & V_224 ) {
case V_225 :
V_197 -> V_226 = NULL ;
break;
case V_227 :
case V_228 :
V_197 -> V_226 = F_64 ;
break;
case V_229 :
V_197 -> V_226 = F_61 ;
break;
case V_230 :
V_197 -> V_226 = F_66 ;
break;
case V_231 :
V_197 -> V_226 = F_65 ;
break;
default:
return - V_112 ;
}
return 0 ;
}
static int F_83 ( struct V_1 * V_2 ,
struct V_196 * V_197 )
{
const struct V_194 * V_232 , * V_195 ;
struct V_194 * V_233 = NULL ;
struct V_234 V_235 ;
struct V_171 * V_9 = V_2 -> V_9 ;
T_2 V_236 ;
int V_21 , V_200 ;
V_200 = F_72 ( V_2 , 0 , sizeof( V_235 ) , & V_235 ) ;
if ( V_200 < 0 )
return V_200 ;
if ( F_78 ( V_235 . V_237 ) != V_238 ||
V_235 . V_239 != V_240 ||
V_235 . V_241 < V_242 )
return - V_112 ;
V_195 = & V_235 . V_195 ;
if ( F_84 ( V_195 ) != V_243 ||
V_195 -> V_239 != V_240 )
return - V_112 ;
if ( V_235 . V_244 ) {
V_236 = V_235 . V_244 * sizeof( * V_233 ) ;
V_233 = F_73 ( V_236 , V_191 ) ;
if ( ! V_233 )
return - V_192 ;
V_200 = F_71 ( V_2 , sizeof( V_235 ) ,
V_236 , V_233 ) ;
if ( V_200 < 0 ) {
F_5 ( V_9 , L_28 ) ;
goto exit;
}
}
for ( V_21 = 0 ; V_21 < V_235 . V_244 ; V_21 ++ ) {
V_232 = & V_233 [ V_21 ] ;
if ( F_84 ( V_232 ) == V_243 &&
V_232 -> V_239 == V_240 &&
( V_232 -> V_241 > V_195 -> V_241 ||
( V_232 -> V_241 == V_195 -> V_241 &&
V_232 -> V_201 > V_195 -> V_201 ) ) )
V_195 = V_232 ;
}
V_200 = F_76 ( V_2 , V_195 , V_197 ) ;
if ( V_200 )
goto exit;
for ( V_21 = 0 ; V_21 < V_235 . V_244 ; V_21 ++ ) {
V_232 = & V_233 [ V_21 ] ;
switch ( F_84 ( V_232 ) ) {
case V_245 :
F_85 ( V_9 , L_29 ) ;
break;
default:
break;
}
if ( V_200 )
goto exit;
}
exit:
F_74 ( V_233 ) ;
return V_200 ;
}
static int F_86 ( struct V_1 * V_2 ,
const struct V_55 * V_56 ,
struct V_196 * V_197 )
{
memset ( V_197 , 0 , sizeof( * V_197 ) ) ;
V_197 -> V_20 = V_56 -> V_60 * V_56 -> V_180 ;
V_197 -> V_102 = V_56 -> V_102 ;
V_197 -> V_213 . V_122 |= V_246 ;
F_69 ( & V_197 -> V_214 [ V_247 ] ,
0 , 0 , V_23 ,
V_248 ) ;
if ( ! ( V_56 -> V_76 & V_249 ) ) {
V_197 -> V_213 . V_122 |= V_250 ;
F_69 ( & V_197 -> V_214 [ V_251 ] ,
0 , 8 , V_25 ,
V_248 ) ;
}
if ( V_56 -> V_76 & V_252 ) {
V_197 -> V_213 . V_122 |= V_253 ;
F_69 ( & V_197 -> V_214 [ V_254 ] ,
0 , 8 , V_27 ,
V_255 ) ;
}
if ( V_56 -> V_76 & V_256 ) {
V_197 -> V_213 . V_122 |= V_257 ;
F_69 ( & V_197 -> V_214 [ V_258 ] ,
0 , 8 , V_31 ,
V_259 ) ;
}
V_197 -> V_213 . V_122 |= V_260 ;
F_70 ( & V_197 -> V_261 [ V_262 ] ,
V_42 , V_248 ) ;
if ( V_197 -> V_213 . V_122 & ( V_263 |
V_264 ) ) {
switch ( F_16 ( V_56 ) ) {
case V_68 :
V_197 -> V_226 = F_61 ;
break;
case V_67 :
break;
default:
V_197 -> V_226 = F_63 ;
break;
}
}
V_2 -> V_107 = 0 ;
V_2 -> V_16 . V_59 = 0 ;
if ( ( V_56 -> V_76 & ( V_252 | V_256 ) ) &&
! ( V_56 -> V_76 & V_265 ) ) {
struct V_196 V_266 ;
memcpy ( & V_266 , V_197 , sizeof( V_266 ) ) ;
if ( F_83 ( V_2 , & V_266 ) ) {
V_2 -> V_107 = 0 ;
V_2 -> V_16 . V_59 = 0 ;
} else {
memcpy ( V_197 , & V_266 , sizeof( * V_197 ) ) ;
}
}
return 0 ;
}
static int F_87 ( T_4 V_213 , const int V_19 [] [ 2 ] , T_2 V_20 )
{
T_2 V_21 ;
for ( V_21 = 0 ; V_21 < V_20 ; V_21 ++ )
if ( V_19 [ V_21 ] [ 0 ] == ( int ) V_213 )
return V_19 [ V_21 ] [ 1 ] ;
return - V_112 ;
}
static int F_81 ( T_4 V_213 )
{
static const int V_267 [] [ 2 ] = {
{ V_246 , V_247 } ,
{ V_250 , V_251 } ,
{ V_268 , V_269 } ,
{ V_253 , V_254 } ,
{ V_270 , V_271 } ,
{ V_272 , V_273 } ,
{ V_274 , V_275 } ,
{ V_257 , V_258 } ,
{ V_276 , V_277 } ,
{ V_278 , V_279 } ,
{ V_280 , V_281 } ,
{ V_282 , V_283 } ,
{ V_284 , V_285 } ,
{ V_286 , V_287 } ,
{ V_288 , V_289 } ,
} ;
return F_87 ( V_213 , V_267 ,
F_12 ( V_267 ) ) ;
}
static int F_88 ( T_4 V_213 )
{
static const int V_290 [] [ 2 ] = {
{ V_260 , V_262 } ,
{ V_291 , V_292 } ,
{ V_293 , V_294 } ,
{ V_295 , V_296 } ,
{ V_297 , V_298 } ,
{ V_299 , V_300 } ,
{ V_301 , V_302 } ,
} ;
return F_87 ( V_213 , V_290 ,
F_12 ( V_290 ) ) ;
}
static int F_89 ( struct V_1 * V_2 ,
const struct V_196 * V_197 ,
T_4 V_303 )
{
int V_66 , V_304 = F_90 ( V_303 & V_305 ) - 1 ;
const struct V_181 * V_153 ;
if ( V_304 < 0 )
return - V_112 ;
V_66 = F_81 ( F_80 ( V_304 ) ) ;
if ( V_66 < 0 )
return - V_112 ;
V_153 = & V_197 -> V_214 [ V_66 ] ;
V_2 -> V_61 = V_153 -> V_18 ;
V_2 -> V_306 = V_153 -> V_185 ;
V_2 -> V_188 = V_153 -> V_182 + V_153 -> V_183 ;
return 0 ;
}
static int F_91 ( struct V_1 * V_2 ,
const struct V_196 * V_197 ,
T_4 V_303 )
{
int V_66 , V_304 = F_90 ( V_303 & V_307 ) - 1 ;
const struct V_186 * V_187 ;
if ( V_304 < 0 )
return - V_112 ;
V_66 = F_88 ( F_80 ( V_304 ) ) ;
if ( V_66 < 0 )
return - V_112 ;
V_187 = & V_197 -> V_261 [ V_66 ] ;
V_2 -> V_62 = V_187 -> V_18 ;
V_2 -> V_308 = V_187 -> V_185 ;
return 0 ;
}
static int F_92 ( struct V_1 * V_2 ,
const struct V_55 * V_56 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
if ( V_16 -> V_59 )
return 0 ;
#ifdef F_82
if ( V_56 -> V_76 & V_309 ) {
V_2 -> V_58 = V_49 ;
V_16 -> V_59 = 4096 ;
} else if ( V_56 -> V_76 & V_310 ) {
V_2 -> V_58 = V_311 ;
V_16 -> V_59 = 4096 ;
} else
#endif
{
V_2 -> V_58 = V_53 ;
V_16 -> V_59 = V_56 -> V_60 ;
}
return 0 ;
}
static int F_93 ( struct V_1 * V_2 , const struct V_55 * V_56 ,
const struct V_196 * V_197 ,
const struct V_312 * V_213 )
{
T_4 V_313 , V_314 ;
bool V_315 ;
int V_200 ;
V_314 = V_213 -> V_122 & V_197 -> V_213 . V_122 ;
V_313 = ( V_272 |
V_278 |
V_286 |
V_295 |
V_301 ) ;
if ( V_314 & V_313 ) {
F_27 ( V_2 -> V_9 ,
L_30 ) ;
V_314 &= ~ V_313 ;
}
V_200 = F_89 ( V_2 , V_197 , V_314 ) ;
if ( V_200 ) {
F_5 ( V_2 -> V_9 ,
L_31 ) ;
return V_200 ;
}
V_200 = F_91 ( V_2 , V_197 , V_314 ) ;
if ( V_200 ) {
F_5 ( V_2 -> V_9 ,
L_32 ) ;
return V_200 ;
}
V_200 = F_92 ( V_2 , V_56 ) ;
if ( V_200 ) {
F_5 ( V_2 -> V_9 ,
L_33 ) ;
return V_200 ;
}
V_315 = ( F_94 ( V_2 -> V_306 ) == 4 ||
F_94 ( V_2 -> V_308 ) == 4 ) ;
if ( V_315 && V_197 -> V_226 ) {
V_200 = V_197 -> V_226 ( V_2 ) ;
if ( V_200 ) {
F_5 ( V_2 -> V_9 , L_34 ) ;
return V_200 ;
}
}
return 0 ;
}
int F_95 ( struct V_1 * V_2 , const char * V_316 ,
const struct V_312 * V_213 )
{
struct V_196 V_197 ;
const struct V_55 * V_56 = NULL ;
struct V_171 * V_9 = V_2 -> V_9 ;
struct V_15 * V_16 = & V_2 -> V_16 ;
struct V_317 * V_318 = F_96 ( V_2 ) ;
int V_3 ;
int V_21 ;
V_3 = F_67 ( V_2 ) ;
if ( V_3 )
return V_3 ;
V_2 -> V_319 = V_248 ;
V_2 -> V_306 = V_248 ;
V_2 -> V_308 = V_248 ;
if ( V_316 )
V_56 = F_97 ( V_316 ) ;
if ( ! V_56 )
V_56 = F_51 ( V_2 ) ;
if ( F_98 ( V_56 ) )
return - V_320 ;
if ( V_316 && V_56 -> V_148 ) {
const struct V_55 * V_321 ;
V_321 = F_51 ( V_2 ) ;
if ( F_99 ( V_321 ) ) {
return F_100 ( V_321 ) ;
} else if ( V_321 != V_56 ) {
F_101 ( V_9 , L_35 ,
V_321 -> V_316 , V_56 -> V_316 ) ;
V_56 = V_321 ;
}
}
F_102 ( & V_2 -> V_96 ) ;
if ( V_56 -> V_76 & V_322 )
V_2 -> V_76 |= V_85 ;
V_3 = F_86 ( V_2 , V_56 , & V_197 ) ;
if ( V_3 )
return V_3 ;
if ( F_16 ( V_56 ) == V_323 ||
F_16 ( V_56 ) == V_324 ||
F_16 ( V_56 ) == V_325 ||
V_56 -> V_76 & V_326 ) {
F_7 ( V_2 ) ;
F_6 ( V_2 , 0 ) ;
F_25 ( V_2 ) ;
}
if ( ! V_16 -> V_316 )
V_16 -> V_316 = F_103 ( V_9 ) ;
V_16 -> V_17 = V_2 ;
V_16 -> type = V_327 ;
V_16 -> V_328 = 1 ;
V_16 -> V_76 = V_329 ;
V_16 -> V_20 = V_197 . V_20 ;
V_16 -> V_330 = F_34 ;
V_16 -> V_331 = F_53 ;
if ( F_16 ( V_56 ) == V_67 ||
V_56 -> V_76 & V_326 ) {
V_2 -> V_139 = F_43 ;
V_2 -> V_141 = F_45 ;
V_2 -> V_142 = F_47 ;
}
if ( V_2 -> V_139 && V_2 -> V_141 && V_2 -> V_142 ) {
V_16 -> V_332 = F_48 ;
V_16 -> V_333 = F_49 ;
V_16 -> V_334 = F_50 ;
}
if ( V_56 -> V_76 & V_335 )
V_16 -> V_336 = F_55 ;
else
V_16 -> V_336 = F_57 ;
if ( V_56 -> V_76 & V_337 )
V_2 -> V_76 |= V_86 ;
if ( V_56 -> V_76 & V_338 )
V_2 -> V_76 |= V_127 ;
if ( V_56 -> V_76 & V_339 )
V_2 -> V_76 |= V_114 ;
if ( V_56 -> V_76 & V_340 )
V_2 -> V_76 |= V_77 ;
if ( V_56 -> V_76 & V_341 )
V_16 -> V_76 |= V_342 ;
V_16 -> V_9 . V_343 = V_9 ;
V_2 -> V_102 = V_197 . V_102 ;
V_16 -> V_179 = V_2 -> V_102 ;
if ( V_318 ) {
if ( F_104 ( V_318 , L_36 ) )
V_197 . V_213 . V_122 |= V_250 ;
else
V_197 . V_213 . V_122 &= ~ V_250 ;
} else {
V_197 . V_213 . V_122 |= V_250 ;
}
if ( V_56 -> V_76 & V_249 )
V_197 . V_213 . V_122 &= ~ V_250 ;
V_3 = F_93 ( V_2 , V_56 , & V_197 , V_213 ) ;
if ( V_3 )
return V_3 ;
if ( V_2 -> V_107 ) {
} else if ( V_56 -> V_107 ) {
V_2 -> V_107 = V_56 -> V_107 ;
} else if ( V_16 -> V_20 > 0x1000000 ) {
V_2 -> V_107 = 4 ;
if ( F_16 ( V_56 ) == V_57 ||
V_56 -> V_76 & V_344 )
F_15 ( V_2 , V_56 ) ;
else
F_17 ( V_2 , V_56 , 1 ) ;
} else {
V_2 -> V_107 = 3 ;
}
if ( V_2 -> V_107 > V_104 ) {
F_5 ( V_9 , L_37 ,
V_2 -> V_107 ) ;
return - V_112 ;
}
if ( V_56 -> V_76 & V_322 ) {
V_3 = F_68 ( V_56 , V_2 ) ;
if ( V_3 )
return V_3 ;
}
F_85 ( V_9 , L_38 , V_56 -> V_316 ,
( long long ) V_16 -> V_20 >> 10 ) ;
F_27 ( V_9 ,
L_39
L_40 ,
V_16 -> V_316 , ( long long ) V_16 -> V_20 , ( long long ) ( V_16 -> V_20 >> 20 ) ,
V_16 -> V_59 , V_16 -> V_59 / 1024 , V_16 -> V_345 ) ;
if ( V_16 -> V_345 )
for ( V_21 = 0 ; V_21 < V_16 -> V_345 ; V_21 ++ )
F_27 ( V_9 ,
L_41
L_42
L_43 ,
V_21 , ( long long ) V_16 -> V_346 [ V_21 ] . V_100 ,
V_16 -> V_346 [ V_21 ] . V_59 ,
V_16 -> V_346 [ V_21 ] . V_59 / 1024 ,
V_16 -> V_346 [ V_21 ] . V_347 ) ;
return 0 ;
}
static const struct V_55 * F_97 ( const char * V_316 )
{
const struct V_55 * V_144 = V_147 ;
while ( V_144 -> V_316 ) {
if ( ! strcmp ( V_316 , V_144 -> V_316 ) )
return V_144 ;
V_144 ++ ;
}
return NULL ;
}
