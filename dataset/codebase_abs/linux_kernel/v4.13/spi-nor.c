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
else
return ! ( V_75 & V_76 ) ;
}
static inline int F_20 ( struct V_1 * V_2 )
{
int V_77 = F_3 ( V_2 ) ;
if ( V_77 < 0 )
return V_77 ;
else
return V_77 & V_78 ;
}
static int F_21 ( struct V_1 * V_2 )
{
int V_75 , V_77 ;
if ( V_2 -> V_79 & V_80 )
V_75 = F_18 ( V_2 ) ;
else
V_75 = F_19 ( V_2 ) ;
if ( V_75 < 0 )
return V_75 ;
V_77 = V_2 -> V_79 & V_81 ? F_20 ( V_2 ) : 1 ;
if ( V_77 < 0 )
return V_77 ;
return V_75 && V_77 ;
}
static int F_22 ( struct V_1 * V_2 ,
unsigned long V_82 )
{
unsigned long V_83 ;
int V_84 = 0 , V_3 ;
V_83 = V_85 + V_82 ;
while ( ! V_84 ) {
if ( F_23 ( V_85 , V_83 ) )
V_84 = 1 ;
V_3 = F_21 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_3 )
return 0 ;
F_24 () ;
}
F_5 ( V_2 -> V_9 , L_5 ) ;
return - V_86 ;
}
static int F_25 ( struct V_1 * V_2 )
{
return F_22 ( V_2 ,
V_87 ) ;
}
static int F_26 ( struct V_1 * V_2 )
{
F_27 ( V_2 -> V_9 , L_6 , ( long long ) ( V_2 -> V_16 . V_20 >> 10 ) ) ;
return V_2 -> V_11 ( V_2 , V_88 , NULL , 0 ) ;
}
static int F_28 ( struct V_1 * V_2 , enum V_89 V_90 )
{
int V_3 = 0 ;
F_29 ( & V_2 -> V_91 ) ;
if ( V_2 -> V_92 ) {
V_3 = V_2 -> V_92 ( V_2 , V_90 ) ;
if ( V_3 ) {
F_5 ( V_2 -> V_9 , L_7 ) ;
F_30 ( & V_2 -> V_91 ) ;
return V_3 ;
}
}
return V_3 ;
}
static void F_31 ( struct V_1 * V_2 , enum V_89 V_90 )
{
if ( V_2 -> V_93 )
V_2 -> V_93 ( V_2 , V_90 ) ;
F_30 ( & V_2 -> V_91 ) ;
}
static T_3 F_32 ( struct V_1 * V_2 , unsigned int V_94 )
{
unsigned int V_95 ;
unsigned int V_96 ;
V_95 = V_94 % V_2 -> V_97 ;
V_96 = V_94 / V_2 -> V_97 ;
V_96 <<= ( V_2 -> V_97 > 512 ) ? 10 : 9 ;
return V_96 | V_95 ;
}
static int F_33 ( struct V_1 * V_2 , T_4 V_94 )
{
T_1 V_98 [ V_99 ] ;
int V_21 ;
if ( V_2 -> V_79 & V_100 )
V_94 = F_32 ( V_2 , V_94 ) ;
if ( V_2 -> V_101 )
return V_2 -> V_101 ( V_2 , V_94 ) ;
for ( V_21 = V_2 -> V_102 - 1 ; V_21 >= 0 ; V_21 -- ) {
V_98 [ V_21 ] = V_94 & 0xff ;
V_94 >>= 8 ;
}
return V_2 -> V_11 ( V_2 , V_2 -> V_58 , V_98 , V_2 -> V_102 ) ;
}
static int F_34 ( struct V_15 * V_16 , struct V_103 * V_104 )
{
struct V_1 * V_2 = F_9 ( V_16 ) ;
T_4 V_94 , V_105 ;
T_5 V_106 ;
int V_3 ;
F_27 ( V_2 -> V_9 , L_8 , ( long long ) V_104 -> V_94 ,
( long long ) V_104 -> V_105 ) ;
F_35 ( V_104 -> V_105 , V_16 -> V_59 , & V_106 ) ;
if ( V_106 )
return - V_107 ;
V_94 = V_104 -> V_94 ;
V_105 = V_104 -> V_105 ;
V_3 = F_28 ( V_2 , V_108 ) ;
if ( V_3 )
return V_3 ;
if ( V_105 == V_16 -> V_20 && ! ( V_2 -> V_79 & V_109 ) ) {
unsigned long V_84 ;
F_7 ( V_2 ) ;
if ( F_26 ( V_2 ) ) {
V_3 = - V_110 ;
goto V_111;
}
V_84 = F_36 ( V_112 ,
V_112 *
( unsigned long ) ( V_16 -> V_20 / V_113 ) ) ;
V_3 = F_22 ( V_2 , V_84 ) ;
if ( V_3 )
goto V_111;
} else {
while ( V_105 ) {
F_7 ( V_2 ) ;
V_3 = F_33 ( V_2 , V_94 ) ;
if ( V_3 )
goto V_111;
V_94 += V_16 -> V_59 ;
V_105 -= V_16 -> V_59 ;
V_3 = F_25 ( V_2 ) ;
if ( V_3 )
goto V_111;
}
}
F_8 ( V_2 ) ;
V_111:
F_31 ( V_2 , V_108 ) ;
V_104 -> V_114 = V_3 ? V_115 : V_116 ;
F_37 ( V_104 ) ;
return V_3 ;
}
static void F_38 ( struct V_1 * V_2 , T_1 V_75 , T_3 * V_117 ,
T_6 * V_105 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
T_1 V_118 = V_119 | V_120 | V_121 ;
int V_122 = F_39 ( V_118 ) - 1 ;
int pow ;
if ( ! ( V_75 & V_118 ) ) {
* V_117 = 0 ;
* V_105 = 0 ;
} else {
pow = ( ( V_75 & V_118 ) ^ V_118 ) >> V_122 ;
* V_105 = V_16 -> V_20 >> pow ;
if ( V_2 -> V_79 & V_123 && V_75 & V_124 )
* V_117 = 0 ;
else
* V_117 = V_16 -> V_20 - * V_105 ;
}
}
static int F_40 ( struct V_1 * V_2 , T_3 V_117 , T_6 V_105 ,
T_1 V_75 , bool V_125 )
{
T_3 V_126 ;
T_6 V_127 ;
if ( ! V_105 )
return 1 ;
F_38 ( V_2 , V_75 , & V_126 , & V_127 ) ;
if ( V_125 )
return ( V_117 + V_105 <= V_126 + V_127 ) && ( V_117 >= V_126 ) ;
else
return ( V_117 >= V_126 + V_127 ) || ( V_117 + V_105 <= V_126 ) ;
}
static int F_41 ( struct V_1 * V_2 , T_3 V_117 , T_6 V_105 ,
T_1 V_75 )
{
return F_40 ( V_2 , V_117 , V_105 , V_75 , true ) ;
}
static int F_42 ( struct V_1 * V_2 , T_3 V_117 , T_6 V_105 ,
T_1 V_75 )
{
return F_40 ( V_2 , V_117 , V_105 , V_75 , false ) ;
}
static int F_43 ( struct V_1 * V_2 , T_3 V_117 , T_6 V_105 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
int V_128 , V_129 ;
T_1 V_118 = V_119 | V_120 | V_121 ;
T_1 V_122 = F_39 ( V_118 ) - 1 , pow , V_4 ;
T_3 V_127 ;
bool V_130 = true , V_131 = V_2 -> V_79 & V_123 ;
bool V_132 ;
int V_3 ;
V_128 = F_1 ( V_2 ) ;
if ( V_128 < 0 )
return V_128 ;
if ( F_41 ( V_2 , V_117 , V_105 , V_128 ) )
return 0 ;
if ( ! F_41 ( V_2 , 0 , V_117 , V_128 ) )
V_131 = false ;
if ( ! F_41 ( V_2 , V_117 + V_105 , V_16 -> V_20 - ( V_117 + V_105 ) ,
V_128 ) )
V_130 = false ;
if ( ! V_131 && ! V_130 )
return - V_107 ;
V_132 = V_130 ;
if ( V_132 )
V_127 = V_16 -> V_20 - V_117 ;
else
V_127 = V_117 + V_105 ;
pow = F_44 ( V_16 -> V_20 ) - F_44 ( V_127 ) ;
V_4 = V_118 - ( pow << V_122 ) ;
if ( V_4 & ~ V_118 )
return - V_107 ;
if ( ! ( V_4 & V_118 ) )
return - V_107 ;
V_129 = ( V_128 & ~ V_118 & ~ V_124 ) | V_4 ;
V_129 |= V_133 ;
if ( ! V_132 )
V_129 |= V_124 ;
if ( V_129 == V_128 )
return 0 ;
if ( ( V_129 & V_118 ) < ( V_128 & V_118 ) )
return - V_107 ;
F_7 ( V_2 ) ;
V_3 = F_6 ( V_2 , V_129 ) ;
if ( V_3 )
return V_3 ;
return F_25 ( V_2 ) ;
}
static int F_45 ( struct V_1 * V_2 , T_3 V_117 , T_6 V_105 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
int V_128 , V_129 ;
T_1 V_118 = V_119 | V_120 | V_121 ;
T_1 V_122 = F_39 ( V_118 ) - 1 , pow , V_4 ;
T_3 V_127 ;
bool V_130 = true , V_131 = V_2 -> V_79 & V_123 ;
bool V_132 ;
int V_3 ;
V_128 = F_1 ( V_2 ) ;
if ( V_128 < 0 )
return V_128 ;
if ( F_42 ( V_2 , V_117 , V_105 , V_128 ) )
return 0 ;
if ( ! F_42 ( V_2 , 0 , V_117 , V_128 ) )
V_130 = false ;
if ( ! F_42 ( V_2 , V_117 + V_105 , V_16 -> V_20 - ( V_117 + V_105 ) ,
V_128 ) )
V_131 = false ;
if ( ! V_131 && ! V_130 )
return - V_107 ;
V_132 = V_130 ;
if ( V_132 )
V_127 = V_16 -> V_20 - ( V_117 + V_105 ) ;
else
V_127 = V_117 ;
pow = F_44 ( V_16 -> V_20 ) - F_46 ( V_127 ) ;
if ( V_127 == 0 ) {
V_4 = 0 ;
} else {
V_4 = V_118 - ( pow << V_122 ) ;
if ( V_4 & ~ V_118 )
return - V_107 ;
}
V_129 = ( V_128 & ~ V_118 & ~ V_124 ) | V_4 ;
if ( V_127 == 0 )
V_129 &= ~ V_133 ;
if ( ! V_132 )
V_129 |= V_124 ;
if ( V_129 == V_128 )
return 0 ;
if ( ( V_129 & V_118 ) > ( V_128 & V_118 ) )
return - V_107 ;
F_7 ( V_2 ) ;
V_3 = F_6 ( V_2 , V_129 ) ;
if ( V_3 )
return V_3 ;
return F_25 ( V_2 ) ;
}
static int F_47 ( struct V_1 * V_2 , T_3 V_117 , T_6 V_105 )
{
int V_64 ;
V_64 = F_1 ( V_2 ) ;
if ( V_64 < 0 )
return V_64 ;
return F_41 ( V_2 , V_117 , V_105 , V_64 ) ;
}
static int F_48 ( struct V_15 * V_16 , T_3 V_117 , T_6 V_105 )
{
struct V_1 * V_2 = F_9 ( V_16 ) ;
int V_3 ;
V_3 = F_28 ( V_2 , V_134 ) ;
if ( V_3 )
return V_3 ;
V_3 = V_2 -> V_135 ( V_2 , V_117 , V_105 ) ;
F_31 ( V_2 , V_136 ) ;
return V_3 ;
}
static int F_49 ( struct V_15 * V_16 , T_3 V_117 , T_6 V_105 )
{
struct V_1 * V_2 = F_9 ( V_16 ) ;
int V_3 ;
V_3 = F_28 ( V_2 , V_136 ) ;
if ( V_3 )
return V_3 ;
V_3 = V_2 -> V_137 ( V_2 , V_117 , V_105 ) ;
F_31 ( V_2 , V_134 ) ;
return V_3 ;
}
static int F_50 ( struct V_15 * V_16 , T_3 V_117 , T_6 V_105 )
{
struct V_1 * V_2 = F_9 ( V_16 ) ;
int V_3 ;
V_3 = F_28 ( V_2 , V_136 ) ;
if ( V_3 )
return V_3 ;
V_3 = V_2 -> V_138 ( V_2 , V_117 , V_105 ) ;
F_31 ( V_2 , V_134 ) ;
return V_3 ;
}
static const struct V_55 * F_51 ( struct V_1 * V_2 )
{
int V_139 ;
T_1 V_140 [ V_141 ] ;
const struct V_55 * V_56 ;
V_139 = V_2 -> V_5 ( V_2 , V_142 , V_140 , V_141 ) ;
if ( V_139 < 0 ) {
F_27 ( V_2 -> V_9 , L_9 , V_139 ) ;
return F_52 ( V_139 ) ;
}
for ( V_139 = 0 ; V_139 < F_12 ( V_143 ) - 1 ; V_139 ++ ) {
V_56 = & V_143 [ V_139 ] ;
if ( V_56 -> V_144 ) {
if ( ! memcmp ( V_56 -> V_140 , V_140 , V_56 -> V_144 ) )
return & V_143 [ V_139 ] ;
}
}
F_5 ( V_2 -> V_9 , L_10 ,
V_140 [ 0 ] , V_140 [ 1 ] , V_140 [ 2 ] ) ;
return F_52 ( - V_145 ) ;
}
static int F_53 ( struct V_15 * V_16 , T_3 V_146 , T_2 V_105 ,
T_2 * V_147 , T_7 * V_98 )
{
struct V_1 * V_2 = F_9 ( V_16 ) ;
int V_3 ;
F_27 ( V_2 -> V_9 , L_11 , ( T_4 ) V_146 , V_105 ) ;
V_3 = F_28 ( V_2 , V_148 ) ;
if ( V_3 )
return V_3 ;
while ( V_105 ) {
T_3 V_94 = V_146 ;
if ( V_2 -> V_79 & V_100 )
V_94 = F_32 ( V_2 , V_94 ) ;
V_3 = V_2 -> V_149 ( V_2 , V_94 , V_105 , V_98 ) ;
if ( V_3 == 0 ) {
V_3 = - V_110 ;
goto V_150;
}
if ( V_3 < 0 )
goto V_150;
F_54 ( V_3 > V_105 ) ;
* V_147 += V_3 ;
V_98 += V_3 ;
V_146 += V_3 ;
V_105 -= V_3 ;
}
V_3 = 0 ;
V_150:
F_31 ( V_2 , V_148 ) ;
return V_3 ;
}
static int F_55 ( struct V_15 * V_16 , T_3 V_151 , T_2 V_105 ,
T_2 * V_147 , const T_7 * V_98 )
{
struct V_1 * V_2 = F_9 ( V_16 ) ;
T_2 V_152 ;
int V_3 ;
F_27 ( V_2 -> V_9 , L_12 , ( T_4 ) V_151 , V_105 ) ;
V_3 = F_28 ( V_2 , V_153 ) ;
if ( V_3 )
return V_3 ;
F_7 ( V_2 ) ;
V_2 -> V_154 = false ;
V_152 = V_151 % 2 ;
if ( V_152 ) {
V_2 -> V_62 = V_155 ;
V_3 = V_2 -> V_156 ( V_2 , V_151 , 1 , V_98 ) ;
if ( V_3 < 0 )
goto V_157;
F_56 ( V_3 != 1 , L_13 ,
( int ) V_3 ) ;
V_3 = F_25 ( V_2 ) ;
if ( V_3 )
goto V_157;
}
V_151 += V_152 ;
for (; V_152 < V_105 - 1 ; V_152 += 2 ) {
V_2 -> V_62 = V_158 ;
V_3 = V_2 -> V_156 ( V_2 , V_151 , 2 , V_98 + V_152 ) ;
if ( V_3 < 0 )
goto V_157;
F_56 ( V_3 != 2 , L_14 ,
( int ) V_3 ) ;
V_3 = F_25 ( V_2 ) ;
if ( V_3 )
goto V_157;
V_151 += 2 ;
V_2 -> V_154 = true ;
}
V_2 -> V_154 = false ;
F_8 ( V_2 ) ;
V_3 = F_25 ( V_2 ) ;
if ( V_3 )
goto V_157;
if ( V_152 != V_105 ) {
F_7 ( V_2 ) ;
V_2 -> V_62 = V_155 ;
V_3 = V_2 -> V_156 ( V_2 , V_151 , 1 , V_98 + V_152 ) ;
if ( V_3 < 0 )
goto V_157;
F_56 ( V_3 != 1 , L_13 ,
( int ) V_3 ) ;
V_3 = F_25 ( V_2 ) ;
if ( V_3 )
goto V_157;
F_8 ( V_2 ) ;
V_152 += 1 ;
}
V_157:
* V_147 += V_152 ;
F_31 ( V_2 , V_153 ) ;
return V_3 ;
}
static int F_57 ( struct V_15 * V_16 , T_3 V_151 , T_2 V_105 ,
T_2 * V_147 , const T_7 * V_98 )
{
struct V_1 * V_2 = F_9 ( V_16 ) ;
T_2 V_159 , V_160 , V_21 ;
T_8 V_3 ;
F_27 ( V_2 -> V_9 , L_12 , ( T_4 ) V_151 , V_105 ) ;
V_3 = F_28 ( V_2 , V_153 ) ;
if ( V_3 )
return V_3 ;
for ( V_21 = 0 ; V_21 < V_105 ; ) {
T_8 V_161 ;
T_3 V_94 = V_151 + V_21 ;
if ( F_58 ( V_2 -> V_97 ) == 1 ) {
V_159 = V_94 & ( V_2 -> V_97 - 1 ) ;
} else {
T_6 V_162 = V_94 ;
V_159 = F_59 ( V_162 , V_2 -> V_97 ) ;
}
V_160 = F_60 ( T_2 ,
V_2 -> V_97 - V_159 , V_105 - V_21 ) ;
if ( V_2 -> V_79 & V_100 )
V_94 = F_32 ( V_2 , V_94 ) ;
F_7 ( V_2 ) ;
V_3 = V_2 -> V_156 ( V_2 , V_94 , V_160 , V_98 + V_21 ) ;
if ( V_3 < 0 )
goto V_163;
V_161 = V_3 ;
V_3 = F_25 ( V_2 ) ;
if ( V_3 )
goto V_163;
* V_147 += V_161 ;
V_21 += V_161 ;
if ( V_161 != V_160 ) {
F_5 ( V_2 -> V_9 ,
L_15 ,
V_160 , V_161 ) ;
V_3 = - V_110 ;
goto V_163;
}
}
V_163:
F_31 ( V_2 , V_153 ) ;
return V_3 ;
}
static int F_61 ( struct V_1 * V_2 )
{
int V_3 , V_4 ;
V_4 = F_1 ( V_2 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( V_4 & V_164 )
return 0 ;
F_7 ( V_2 ) ;
F_6 ( V_2 , V_4 | V_164 ) ;
V_3 = F_25 ( V_2 ) ;
if ( V_3 )
return V_3 ;
V_3 = F_1 ( V_2 ) ;
if ( ! ( V_3 > 0 && ( V_3 & V_164 ) ) ) {
F_5 ( V_2 -> V_9 , L_16 ) ;
return - V_107 ;
}
return 0 ;
}
static int F_62 ( struct V_1 * V_2 , T_9 V_4 )
{
V_2 -> V_10 [ 0 ] = V_4 & 0xff ;
V_2 -> V_10 [ 1 ] = ( V_4 >> 8 ) ;
return V_2 -> V_11 ( V_2 , V_12 , V_2 -> V_10 , 2 ) ;
}
static int F_63 ( struct V_1 * V_2 )
{
int V_3 ;
int V_165 = V_166 << 8 ;
F_7 ( V_2 ) ;
V_3 = F_62 ( V_2 , V_165 ) ;
if ( V_3 < 0 ) {
F_5 ( V_2 -> V_9 ,
L_17 ) ;
return - V_107 ;
}
V_3 = F_25 ( V_2 ) ;
if ( V_3 ) {
F_5 ( V_2 -> V_9 ,
L_18 ) ;
return V_3 ;
}
V_3 = F_4 ( V_2 ) ;
if ( ! ( V_3 > 0 && ( V_3 & V_166 ) ) ) {
F_5 ( V_2 -> V_9 , L_19 ) ;
return - V_107 ;
}
return 0 ;
}
static int F_64 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_9 || ! V_2 -> V_149 || ! V_2 -> V_156 ||
! V_2 -> V_5 || ! V_2 -> V_11 ) {
F_2 ( L_20 ) ;
return - V_107 ;
}
return 0 ;
}
static int F_65 ( const struct V_55 * V_56 , struct V_1 * V_2 )
{
int V_3 ;
T_1 V_4 ;
V_3 = V_2 -> V_5 ( V_2 , V_73 , & V_4 , 1 ) ;
if ( V_3 < 0 ) {
F_5 ( V_2 -> V_9 , L_4 , ( int ) V_3 ) ;
return V_3 ;
}
V_2 -> V_58 = V_167 ;
V_2 -> V_62 = V_168 ;
V_2 -> V_61 = V_23 ;
V_2 -> V_79 |= V_109 ;
if ( V_4 & V_169 ) {
V_2 -> V_97 = ( V_2 -> V_97 == 264 ) ? 256 : 512 ;
V_2 -> V_16 . V_170 = V_2 -> V_97 ;
V_2 -> V_16 . V_20 = 8 * V_2 -> V_97 * V_56 -> V_171 ;
V_2 -> V_16 . V_59 = 8 * V_2 -> V_97 ;
} else {
V_2 -> V_79 |= V_100 ;
}
return 0 ;
}
static void
F_66 ( struct V_172 * V_149 ,
T_1 V_173 ,
T_1 V_174 ,
T_1 V_18 ,
enum V_175 V_176 )
{
V_149 -> V_173 = V_173 ;
V_149 -> V_174 = V_174 ;
V_149 -> V_18 = V_18 ;
V_149 -> V_176 = V_176 ;
}
static void
F_67 ( struct V_177 * V_178 ,
T_1 V_18 ,
enum V_175 V_176 )
{
V_178 -> V_18 = V_18 ;
V_178 -> V_176 = V_176 ;
}
static int F_68 ( struct V_1 * V_2 ,
const struct V_55 * V_56 ,
struct V_179 * V_180 )
{
memset ( V_180 , 0 , sizeof( * V_180 ) ) ;
V_180 -> V_20 = V_56 -> V_60 * V_56 -> V_171 ;
V_180 -> V_97 = V_56 -> V_97 ;
V_180 -> V_181 . V_118 |= V_182 ;
F_66 ( & V_180 -> V_183 [ V_184 ] ,
0 , 0 , V_23 ,
V_185 ) ;
if ( ! ( V_56 -> V_79 & V_186 ) ) {
V_180 -> V_181 . V_118 |= V_187 ;
F_66 ( & V_180 -> V_183 [ V_188 ] ,
0 , 8 , V_25 ,
V_185 ) ;
}
if ( V_56 -> V_79 & V_189 ) {
V_180 -> V_181 . V_118 |= V_190 ;
F_66 ( & V_180 -> V_183 [ V_191 ] ,
0 , 8 , V_27 ,
V_192 ) ;
}
if ( V_56 -> V_79 & V_193 ) {
V_180 -> V_181 . V_118 |= V_194 ;
F_66 ( & V_180 -> V_183 [ V_195 ] ,
0 , 8 , V_31 ,
V_196 ) ;
}
V_180 -> V_181 . V_118 |= V_197 ;
F_67 ( & V_180 -> V_198 [ V_199 ] ,
V_42 , V_185 ) ;
if ( V_180 -> V_181 . V_118 & ( V_200 |
V_201 ) ) {
switch ( F_16 ( V_56 ) ) {
case V_68 :
V_180 -> V_202 = F_61 ;
break;
case V_67 :
break;
default:
V_180 -> V_202 = F_63 ;
break;
}
}
return 0 ;
}
static int F_69 ( T_4 V_181 , const int V_19 [] [ 2 ] , T_2 V_20 )
{
T_2 V_21 ;
for ( V_21 = 0 ; V_21 < V_20 ; V_21 ++ )
if ( V_19 [ V_21 ] [ 0 ] == ( int ) V_181 )
return V_19 [ V_21 ] [ 1 ] ;
return - V_107 ;
}
static int F_70 ( T_4 V_181 )
{
static const int V_203 [] [ 2 ] = {
{ V_182 , V_184 } ,
{ V_187 , V_188 } ,
{ V_204 , V_205 } ,
{ V_190 , V_191 } ,
{ V_206 , V_207 } ,
{ V_208 , V_209 } ,
{ V_210 , V_211 } ,
{ V_194 , V_195 } ,
{ V_212 , V_213 } ,
{ V_214 , V_215 } ,
{ V_216 , V_217 } ,
{ V_218 , V_219 } ,
{ V_220 , V_221 } ,
{ V_222 , V_223 } ,
{ V_224 , V_225 } ,
} ;
return F_69 ( V_181 , V_203 ,
F_12 ( V_203 ) ) ;
}
static int F_71 ( T_4 V_181 )
{
static const int V_226 [] [ 2 ] = {
{ V_197 , V_199 } ,
{ V_227 , V_228 } ,
{ V_229 , V_230 } ,
{ V_231 , V_232 } ,
{ V_233 , V_234 } ,
{ V_235 , V_236 } ,
{ V_237 , V_238 } ,
} ;
return F_69 ( V_181 , V_226 ,
F_12 ( V_226 ) ) ;
}
static int F_72 ( struct V_1 * V_2 ,
const struct V_179 * V_180 ,
T_4 V_239 )
{
int V_66 , V_240 = F_73 ( V_239 & V_241 ) - 1 ;
const struct V_172 * V_149 ;
if ( V_240 < 0 )
return - V_107 ;
V_66 = F_70 ( F_74 ( V_240 ) ) ;
if ( V_66 < 0 )
return - V_107 ;
V_149 = & V_180 -> V_183 [ V_66 ] ;
V_2 -> V_61 = V_149 -> V_18 ;
V_2 -> V_242 = V_149 -> V_176 ;
V_2 -> V_243 = V_149 -> V_173 + V_149 -> V_174 ;
return 0 ;
}
static int F_75 ( struct V_1 * V_2 ,
const struct V_179 * V_180 ,
T_4 V_239 )
{
int V_66 , V_240 = F_73 ( V_239 & V_244 ) - 1 ;
const struct V_177 * V_178 ;
if ( V_240 < 0 )
return - V_107 ;
V_66 = F_71 ( F_74 ( V_240 ) ) ;
if ( V_66 < 0 )
return - V_107 ;
V_178 = & V_180 -> V_198 [ V_66 ] ;
V_2 -> V_62 = V_178 -> V_18 ;
V_2 -> V_245 = V_178 -> V_176 ;
return 0 ;
}
static int F_76 ( struct V_1 * V_2 ,
const struct V_55 * V_56 )
{
struct V_15 * V_16 = & V_2 -> V_16 ;
#ifdef F_77
if ( V_56 -> V_79 & V_246 ) {
V_2 -> V_58 = V_49 ;
V_16 -> V_59 = 4096 ;
} else if ( V_56 -> V_79 & V_247 ) {
V_2 -> V_58 = V_248 ;
V_16 -> V_59 = 4096 ;
} else
#endif
{
V_2 -> V_58 = V_53 ;
V_16 -> V_59 = V_56 -> V_60 ;
}
return 0 ;
}
static int F_78 ( struct V_1 * V_2 , const struct V_55 * V_56 ,
const struct V_179 * V_180 ,
const struct V_249 * V_181 )
{
T_4 V_250 , V_251 ;
bool V_252 ;
int V_253 ;
V_251 = V_181 -> V_118 & V_180 -> V_181 . V_118 ;
V_250 = ( V_208 |
V_214 |
V_222 |
V_231 |
V_237 ) ;
if ( V_251 & V_250 ) {
F_27 ( V_2 -> V_9 ,
L_21 ) ;
V_251 &= ~ V_250 ;
}
V_253 = F_72 ( V_2 , V_180 , V_251 ) ;
if ( V_253 ) {
F_5 ( V_2 -> V_9 ,
L_22 ) ;
return V_253 ;
}
V_253 = F_75 ( V_2 , V_180 , V_251 ) ;
if ( V_253 ) {
F_5 ( V_2 -> V_9 ,
L_23 ) ;
return V_253 ;
}
V_253 = F_76 ( V_2 , V_56 ) ;
if ( V_253 ) {
F_5 ( V_2 -> V_9 ,
L_24 ) ;
return V_253 ;
}
V_252 = ( F_79 ( V_2 -> V_242 ) == 4 ||
F_79 ( V_2 -> V_245 ) == 4 ) ;
if ( V_252 && V_180 -> V_202 ) {
V_253 = V_180 -> V_202 ( V_2 ) ;
if ( V_253 ) {
F_5 ( V_2 -> V_9 , L_25 ) ;
return V_253 ;
}
}
return 0 ;
}
int F_80 ( struct V_1 * V_2 , const char * V_254 ,
const struct V_249 * V_181 )
{
struct V_179 V_180 ;
const struct V_55 * V_56 = NULL ;
struct V_255 * V_9 = V_2 -> V_9 ;
struct V_15 * V_16 = & V_2 -> V_16 ;
struct V_256 * V_257 = F_81 ( V_2 ) ;
int V_3 ;
int V_21 ;
V_3 = F_64 ( V_2 ) ;
if ( V_3 )
return V_3 ;
V_2 -> V_258 = V_185 ;
V_2 -> V_242 = V_185 ;
V_2 -> V_245 = V_185 ;
if ( V_254 )
V_56 = F_82 ( V_254 ) ;
if ( ! V_56 )
V_56 = F_51 ( V_2 ) ;
if ( F_83 ( V_56 ) )
return - V_259 ;
if ( V_254 && V_56 -> V_144 ) {
const struct V_55 * V_260 ;
V_260 = F_51 ( V_2 ) ;
if ( F_84 ( V_260 ) ) {
return F_85 ( V_260 ) ;
} else if ( V_260 != V_56 ) {
F_86 ( V_9 , L_26 ,
V_260 -> V_254 , V_56 -> V_254 ) ;
V_56 = V_260 ;
}
}
F_87 ( & V_2 -> V_91 ) ;
if ( V_56 -> V_79 & V_261 )
V_2 -> V_79 |= V_80 ;
V_3 = F_68 ( V_2 , V_56 , & V_180 ) ;
if ( V_3 )
return V_3 ;
if ( F_16 ( V_56 ) == V_262 ||
F_16 ( V_56 ) == V_263 ||
F_16 ( V_56 ) == V_264 ||
V_56 -> V_79 & V_265 ) {
F_7 ( V_2 ) ;
F_6 ( V_2 , 0 ) ;
F_25 ( V_2 ) ;
}
if ( ! V_16 -> V_254 )
V_16 -> V_254 = F_88 ( V_9 ) ;
V_16 -> V_17 = V_2 ;
V_16 -> type = V_266 ;
V_16 -> V_267 = 1 ;
V_16 -> V_79 = V_268 ;
V_16 -> V_20 = V_180 . V_20 ;
V_16 -> V_269 = F_34 ;
V_16 -> V_270 = F_53 ;
if ( F_16 ( V_56 ) == V_67 ||
V_56 -> V_79 & V_265 ) {
V_2 -> V_135 = F_43 ;
V_2 -> V_137 = F_45 ;
V_2 -> V_138 = F_47 ;
}
if ( V_2 -> V_135 && V_2 -> V_137 && V_2 -> V_138 ) {
V_16 -> V_271 = F_48 ;
V_16 -> V_272 = F_49 ;
V_16 -> V_273 = F_50 ;
}
if ( V_56 -> V_79 & V_274 )
V_16 -> V_275 = F_55 ;
else
V_16 -> V_275 = F_57 ;
if ( V_56 -> V_79 & V_276 )
V_2 -> V_79 |= V_81 ;
if ( V_56 -> V_79 & V_277 )
V_2 -> V_79 |= V_123 ;
if ( V_56 -> V_79 & V_278 )
V_2 -> V_79 |= V_109 ;
if ( V_56 -> V_79 & V_279 )
V_16 -> V_79 |= V_280 ;
V_16 -> V_9 . V_281 = V_9 ;
V_2 -> V_97 = V_180 . V_97 ;
V_16 -> V_170 = V_2 -> V_97 ;
if ( V_257 ) {
if ( F_89 ( V_257 , L_27 ) )
V_180 . V_181 . V_118 |= V_187 ;
else
V_180 . V_181 . V_118 &= ~ V_187 ;
} else {
V_180 . V_181 . V_118 |= V_187 ;
}
if ( V_56 -> V_79 & V_186 )
V_180 . V_181 . V_118 &= ~ V_187 ;
V_3 = F_78 ( V_2 , V_56 , & V_180 , V_181 ) ;
if ( V_3 )
return V_3 ;
if ( V_56 -> V_102 )
V_2 -> V_102 = V_56 -> V_102 ;
else if ( V_16 -> V_20 > 0x1000000 ) {
V_2 -> V_102 = 4 ;
if ( F_16 ( V_56 ) == V_57 ||
V_56 -> V_79 & V_282 )
F_15 ( V_2 , V_56 ) ;
else
F_17 ( V_2 , V_56 , 1 ) ;
} else {
V_2 -> V_102 = 3 ;
}
if ( V_2 -> V_102 > V_99 ) {
F_5 ( V_9 , L_28 ,
V_2 -> V_102 ) ;
return - V_107 ;
}
if ( V_56 -> V_79 & V_261 ) {
V_3 = F_65 ( V_56 , V_2 ) ;
if ( V_3 )
return V_3 ;
}
F_90 ( V_9 , L_29 , V_56 -> V_254 ,
( long long ) V_16 -> V_20 >> 10 ) ;
F_27 ( V_9 ,
L_30
L_31 ,
V_16 -> V_254 , ( long long ) V_16 -> V_20 , ( long long ) ( V_16 -> V_20 >> 20 ) ,
V_16 -> V_59 , V_16 -> V_59 / 1024 , V_16 -> V_283 ) ;
if ( V_16 -> V_283 )
for ( V_21 = 0 ; V_21 < V_16 -> V_283 ; V_21 ++ )
F_27 ( V_9 ,
L_32
L_33
L_34 ,
V_21 , ( long long ) V_16 -> V_284 [ V_21 ] . V_95 ,
V_16 -> V_284 [ V_21 ] . V_59 ,
V_16 -> V_284 [ V_21 ] . V_59 / 1024 ,
V_16 -> V_284 [ V_21 ] . V_285 ) ;
return 0 ;
}
static const struct V_55 * F_82 ( const char * V_254 )
{
const struct V_55 * V_140 = V_143 ;
while ( V_140 -> V_254 ) {
if ( ! strcmp ( V_254 , V_140 -> V_254 ) )
return V_140 ;
V_140 ++ ;
}
return NULL ;
}
