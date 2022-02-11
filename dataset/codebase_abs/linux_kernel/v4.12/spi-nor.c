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
static inline int F_6 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_10 ) {
case V_11 :
case V_12 :
case V_13 :
return 8 ;
case V_14 :
return 0 ;
}
return 0 ;
}
static inline int F_7 ( struct V_1 * V_2 , T_1 V_4 )
{
V_2 -> V_15 [ 0 ] = V_4 ;
return V_2 -> V_16 ( V_2 , V_17 , V_2 -> V_15 , 1 ) ;
}
static inline int F_8 ( struct V_1 * V_2 )
{
return V_2 -> V_16 ( V_2 , V_18 , NULL , 0 ) ;
}
static inline int F_9 ( struct V_1 * V_2 )
{
return V_2 -> V_16 ( V_2 , V_19 , NULL , 0 ) ;
}
static inline struct V_1 * F_10 ( struct V_20 * V_21 )
{
return V_21 -> V_22 ;
}
static T_1 F_11 ( T_1 V_23 , const T_1 V_24 [] [ 2 ] , T_2 V_25 )
{
T_2 V_26 ;
for ( V_26 = 0 ; V_26 < V_25 ; V_26 ++ )
if ( V_24 [ V_26 ] [ 0 ] == V_23 )
return V_24 [ V_26 ] [ 1 ] ;
return V_23 ;
}
static inline T_1 F_12 ( T_1 V_23 )
{
static const T_1 V_27 [] [ 2 ] = {
{ V_28 , V_29 } ,
{ V_30 , V_31 } ,
{ V_32 , V_33 } ,
{ V_34 , V_35 } ,
{ V_36 , V_37 } ,
{ V_38 , V_39 } ,
} ;
return F_11 ( V_23 , V_27 ,
F_13 ( V_27 ) ) ;
}
static inline T_1 F_14 ( T_1 V_23 )
{
static const T_1 V_40 [] [ 2 ] = {
{ V_41 , V_42 } ,
{ V_43 , V_44 } ,
{ V_45 , V_46 } ,
} ;
return F_11 ( V_23 , V_40 ,
F_13 ( V_40 ) ) ;
}
static inline T_1 F_15 ( T_1 V_23 )
{
static const T_1 V_47 [] [ 2 ] = {
{ V_48 , V_49 } ,
{ V_50 , V_51 } ,
{ V_52 , V_53 } ,
} ;
return F_11 ( V_23 , V_47 ,
F_13 ( V_47 ) ) ;
}
static void F_16 ( struct V_1 * V_2 ,
const struct V_54 * V_55 )
{
switch ( F_17 ( V_55 ) ) {
case V_56 :
V_2 -> V_57 = V_52 ;
V_2 -> V_21 . V_58 = V_55 -> V_59 ;
break;
default:
break;
}
V_2 -> V_60 = F_12 ( V_2 -> V_60 ) ;
V_2 -> V_61 = F_14 ( V_2 -> V_61 ) ;
V_2 -> V_57 = F_15 ( V_2 -> V_57 ) ;
}
static inline int F_18 ( struct V_1 * V_2 , const struct V_54 * V_55 ,
int V_62 )
{
int V_63 ;
bool V_64 = false ;
T_1 V_65 ;
switch ( F_17 ( V_55 ) ) {
case V_66 :
V_64 = true ;
case V_67 :
case V_68 :
if ( V_64 )
F_8 ( V_2 ) ;
V_65 = V_62 ? V_69 : V_70 ;
V_63 = V_2 -> V_16 ( V_2 , V_65 , NULL , 0 ) ;
if ( V_64 )
F_9 ( V_2 ) ;
return V_63 ;
default:
V_2 -> V_15 [ 0 ] = V_62 << 7 ;
return V_2 -> V_16 ( V_2 , V_71 , V_2 -> V_15 , 1 ) ;
}
}
static int F_19 ( struct V_1 * V_2 )
{
int V_3 ;
T_1 V_4 ;
V_3 = V_2 -> V_5 ( V_2 , V_72 , & V_4 , 1 ) ;
if ( V_3 < 0 ) {
F_5 ( V_2 -> V_9 , L_4 , ( int ) V_3 ) ;
return V_3 ;
}
return ! ! ( V_4 & V_73 ) ;
}
static inline int F_20 ( struct V_1 * V_2 )
{
int V_74 = F_1 ( V_2 ) ;
if ( V_74 < 0 )
return V_74 ;
else
return ! ( V_74 & V_75 ) ;
}
static inline int F_21 ( struct V_1 * V_2 )
{
int V_76 = F_3 ( V_2 ) ;
if ( V_76 < 0 )
return V_76 ;
else
return V_76 & V_77 ;
}
static int F_22 ( struct V_1 * V_2 )
{
int V_74 , V_76 ;
if ( V_2 -> V_78 & V_79 )
V_74 = F_19 ( V_2 ) ;
else
V_74 = F_20 ( V_2 ) ;
if ( V_74 < 0 )
return V_74 ;
V_76 = V_2 -> V_78 & V_80 ? F_21 ( V_2 ) : 1 ;
if ( V_76 < 0 )
return V_76 ;
return V_74 && V_76 ;
}
static int F_23 ( struct V_1 * V_2 ,
unsigned long V_81 )
{
unsigned long V_82 ;
int V_83 = 0 , V_3 ;
V_82 = V_84 + V_81 ;
while ( ! V_83 ) {
if ( F_24 ( V_84 , V_82 ) )
V_83 = 1 ;
V_3 = F_22 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_3 )
return 0 ;
F_25 () ;
}
F_5 ( V_2 -> V_9 , L_5 ) ;
return - V_85 ;
}
static int F_26 ( struct V_1 * V_2 )
{
return F_23 ( V_2 ,
V_86 ) ;
}
static int F_27 ( struct V_1 * V_2 )
{
F_28 ( V_2 -> V_9 , L_6 , ( long long ) ( V_2 -> V_21 . V_25 >> 10 ) ) ;
return V_2 -> V_16 ( V_2 , V_87 , NULL , 0 ) ;
}
static int F_29 ( struct V_1 * V_2 , enum V_88 V_89 )
{
int V_3 = 0 ;
F_30 ( & V_2 -> V_90 ) ;
if ( V_2 -> V_91 ) {
V_3 = V_2 -> V_91 ( V_2 , V_89 ) ;
if ( V_3 ) {
F_5 ( V_2 -> V_9 , L_7 ) ;
F_31 ( & V_2 -> V_90 ) ;
return V_3 ;
}
}
return V_3 ;
}
static void F_32 ( struct V_1 * V_2 , enum V_88 V_89 )
{
if ( V_2 -> V_92 )
V_2 -> V_92 ( V_2 , V_89 ) ;
F_31 ( & V_2 -> V_90 ) ;
}
static T_3 F_33 ( struct V_1 * V_2 , unsigned int V_93 )
{
unsigned int V_94 ;
unsigned int V_95 ;
V_94 = V_93 % V_2 -> V_96 ;
V_95 = V_93 / V_2 -> V_96 ;
V_95 <<= ( V_2 -> V_96 > 512 ) ? 10 : 9 ;
return V_95 | V_94 ;
}
static int F_34 ( struct V_1 * V_2 , T_4 V_93 )
{
T_1 V_97 [ V_98 ] ;
int V_26 ;
if ( V_2 -> V_78 & V_99 )
V_93 = F_33 ( V_2 , V_93 ) ;
if ( V_2 -> V_100 )
return V_2 -> V_100 ( V_2 , V_93 ) ;
for ( V_26 = V_2 -> V_101 - 1 ; V_26 >= 0 ; V_26 -- ) {
V_97 [ V_26 ] = V_93 & 0xff ;
V_93 >>= 8 ;
}
return V_2 -> V_16 ( V_2 , V_2 -> V_57 , V_97 , V_2 -> V_101 ) ;
}
static int F_35 ( struct V_20 * V_21 , struct V_102 * V_103 )
{
struct V_1 * V_2 = F_10 ( V_21 ) ;
T_4 V_93 , V_104 ;
T_5 V_105 ;
int V_3 ;
F_28 ( V_2 -> V_9 , L_8 , ( long long ) V_103 -> V_93 ,
( long long ) V_103 -> V_104 ) ;
F_36 ( V_103 -> V_104 , V_21 -> V_58 , & V_105 ) ;
if ( V_105 )
return - V_106 ;
V_93 = V_103 -> V_93 ;
V_104 = V_103 -> V_104 ;
V_3 = F_29 ( V_2 , V_107 ) ;
if ( V_3 )
return V_3 ;
if ( V_104 == V_21 -> V_25 && ! ( V_2 -> V_78 & V_108 ) ) {
unsigned long V_83 ;
F_8 ( V_2 ) ;
if ( F_27 ( V_2 ) ) {
V_3 = - V_109 ;
goto V_110;
}
V_83 = F_37 ( V_111 ,
V_111 *
( unsigned long ) ( V_21 -> V_25 / V_112 ) ) ;
V_3 = F_23 ( V_2 , V_83 ) ;
if ( V_3 )
goto V_110;
} else {
while ( V_104 ) {
F_8 ( V_2 ) ;
V_3 = F_34 ( V_2 , V_93 ) ;
if ( V_3 )
goto V_110;
V_93 += V_21 -> V_58 ;
V_104 -= V_21 -> V_58 ;
V_3 = F_26 ( V_2 ) ;
if ( V_3 )
goto V_110;
}
}
F_9 ( V_2 ) ;
V_110:
F_32 ( V_2 , V_107 ) ;
V_103 -> V_113 = V_3 ? V_114 : V_115 ;
F_38 ( V_103 ) ;
return V_3 ;
}
static void F_39 ( struct V_1 * V_2 , T_1 V_74 , T_3 * V_116 ,
T_6 * V_104 )
{
struct V_20 * V_21 = & V_2 -> V_21 ;
T_1 V_117 = V_118 | V_119 | V_120 ;
int V_121 = F_40 ( V_117 ) - 1 ;
int pow ;
if ( ! ( V_74 & V_117 ) ) {
* V_116 = 0 ;
* V_104 = 0 ;
} else {
pow = ( ( V_74 & V_117 ) ^ V_117 ) >> V_121 ;
* V_104 = V_21 -> V_25 >> pow ;
if ( V_2 -> V_78 & V_122 && V_74 & V_123 )
* V_116 = 0 ;
else
* V_116 = V_21 -> V_25 - * V_104 ;
}
}
static int F_41 ( struct V_1 * V_2 , T_3 V_116 , T_6 V_104 ,
T_1 V_74 , bool V_124 )
{
T_3 V_125 ;
T_6 V_126 ;
if ( ! V_104 )
return 1 ;
F_39 ( V_2 , V_74 , & V_125 , & V_126 ) ;
if ( V_124 )
return ( V_116 + V_104 <= V_125 + V_126 ) && ( V_116 >= V_125 ) ;
else
return ( V_116 >= V_125 + V_126 ) || ( V_116 + V_104 <= V_125 ) ;
}
static int F_42 ( struct V_1 * V_2 , T_3 V_116 , T_6 V_104 ,
T_1 V_74 )
{
return F_41 ( V_2 , V_116 , V_104 , V_74 , true ) ;
}
static int F_43 ( struct V_1 * V_2 , T_3 V_116 , T_6 V_104 ,
T_1 V_74 )
{
return F_41 ( V_2 , V_116 , V_104 , V_74 , false ) ;
}
static int F_44 ( struct V_1 * V_2 , T_3 V_116 , T_6 V_104 )
{
struct V_20 * V_21 = & V_2 -> V_21 ;
int V_127 , V_128 ;
T_1 V_117 = V_118 | V_119 | V_120 ;
T_1 V_121 = F_40 ( V_117 ) - 1 , pow , V_4 ;
T_3 V_126 ;
bool V_129 = true , V_130 = V_2 -> V_78 & V_122 ;
bool V_131 ;
int V_3 ;
V_127 = F_1 ( V_2 ) ;
if ( V_127 < 0 )
return V_127 ;
if ( F_42 ( V_2 , V_116 , V_104 , V_127 ) )
return 0 ;
if ( ! F_42 ( V_2 , 0 , V_116 , V_127 ) )
V_130 = false ;
if ( ! F_42 ( V_2 , V_116 + V_104 , V_21 -> V_25 - ( V_116 + V_104 ) ,
V_127 ) )
V_129 = false ;
if ( ! V_130 && ! V_129 )
return - V_106 ;
V_131 = V_129 ;
if ( V_131 )
V_126 = V_21 -> V_25 - V_116 ;
else
V_126 = V_116 + V_104 ;
pow = F_45 ( V_21 -> V_25 ) - F_45 ( V_126 ) ;
V_4 = V_117 - ( pow << V_121 ) ;
if ( V_4 & ~ V_117 )
return - V_106 ;
if ( ! ( V_4 & V_117 ) )
return - V_106 ;
V_128 = ( V_127 & ~ V_117 & ~ V_123 ) | V_4 ;
V_128 |= V_132 ;
if ( ! V_131 )
V_128 |= V_123 ;
if ( V_128 == V_127 )
return 0 ;
if ( ( V_128 & V_117 ) < ( V_127 & V_117 ) )
return - V_106 ;
F_8 ( V_2 ) ;
V_3 = F_7 ( V_2 , V_128 ) ;
if ( V_3 )
return V_3 ;
return F_26 ( V_2 ) ;
}
static int F_46 ( struct V_1 * V_2 , T_3 V_116 , T_6 V_104 )
{
struct V_20 * V_21 = & V_2 -> V_21 ;
int V_127 , V_128 ;
T_1 V_117 = V_118 | V_119 | V_120 ;
T_1 V_121 = F_40 ( V_117 ) - 1 , pow , V_4 ;
T_3 V_126 ;
bool V_129 = true , V_130 = V_2 -> V_78 & V_122 ;
bool V_131 ;
int V_3 ;
V_127 = F_1 ( V_2 ) ;
if ( V_127 < 0 )
return V_127 ;
if ( F_43 ( V_2 , V_116 , V_104 , V_127 ) )
return 0 ;
if ( ! F_43 ( V_2 , 0 , V_116 , V_127 ) )
V_129 = false ;
if ( ! F_43 ( V_2 , V_116 + V_104 , V_21 -> V_25 - ( V_116 + V_104 ) ,
V_127 ) )
V_130 = false ;
if ( ! V_130 && ! V_129 )
return - V_106 ;
V_131 = V_129 ;
if ( V_131 )
V_126 = V_21 -> V_25 - ( V_116 + V_104 ) ;
else
V_126 = V_116 ;
pow = F_45 ( V_21 -> V_25 ) - F_47 ( V_126 ) ;
if ( V_126 == 0 ) {
V_4 = 0 ;
} else {
V_4 = V_117 - ( pow << V_121 ) ;
if ( V_4 & ~ V_117 )
return - V_106 ;
}
V_128 = ( V_127 & ~ V_117 & ~ V_123 ) | V_4 ;
if ( V_126 == 0 )
V_128 &= ~ V_132 ;
if ( ! V_131 )
V_128 |= V_123 ;
if ( V_128 == V_127 )
return 0 ;
if ( ( V_128 & V_117 ) > ( V_127 & V_117 ) )
return - V_106 ;
F_8 ( V_2 ) ;
V_3 = F_7 ( V_2 , V_128 ) ;
if ( V_3 )
return V_3 ;
return F_26 ( V_2 ) ;
}
static int F_48 ( struct V_1 * V_2 , T_3 V_116 , T_6 V_104 )
{
int V_63 ;
V_63 = F_1 ( V_2 ) ;
if ( V_63 < 0 )
return V_63 ;
return F_42 ( V_2 , V_116 , V_104 , V_63 ) ;
}
static int F_49 ( struct V_20 * V_21 , T_3 V_116 , T_6 V_104 )
{
struct V_1 * V_2 = F_10 ( V_21 ) ;
int V_3 ;
V_3 = F_29 ( V_2 , V_133 ) ;
if ( V_3 )
return V_3 ;
V_3 = V_2 -> V_134 ( V_2 , V_116 , V_104 ) ;
F_32 ( V_2 , V_135 ) ;
return V_3 ;
}
static int F_50 ( struct V_20 * V_21 , T_3 V_116 , T_6 V_104 )
{
struct V_1 * V_2 = F_10 ( V_21 ) ;
int V_3 ;
V_3 = F_29 ( V_2 , V_135 ) ;
if ( V_3 )
return V_3 ;
V_3 = V_2 -> V_136 ( V_2 , V_116 , V_104 ) ;
F_32 ( V_2 , V_133 ) ;
return V_3 ;
}
static int F_51 ( struct V_20 * V_21 , T_3 V_116 , T_6 V_104 )
{
struct V_1 * V_2 = F_10 ( V_21 ) ;
int V_3 ;
V_3 = F_29 ( V_2 , V_135 ) ;
if ( V_3 )
return V_3 ;
V_3 = V_2 -> V_137 ( V_2 , V_116 , V_104 ) ;
F_32 ( V_2 , V_133 ) ;
return V_3 ;
}
static const struct V_54 * F_52 ( struct V_1 * V_2 )
{
int V_138 ;
T_1 V_139 [ V_140 ] ;
const struct V_54 * V_55 ;
V_138 = V_2 -> V_5 ( V_2 , V_141 , V_139 , V_140 ) ;
if ( V_138 < 0 ) {
F_28 ( V_2 -> V_9 , L_9 , V_138 ) ;
return F_53 ( V_138 ) ;
}
for ( V_138 = 0 ; V_138 < F_13 ( V_142 ) - 1 ; V_138 ++ ) {
V_55 = & V_142 [ V_138 ] ;
if ( V_55 -> V_143 ) {
if ( ! memcmp ( V_55 -> V_139 , V_139 , V_55 -> V_143 ) )
return & V_142 [ V_138 ] ;
}
}
F_5 ( V_2 -> V_9 , L_10 ,
V_139 [ 0 ] , V_139 [ 1 ] , V_139 [ 2 ] ) ;
return F_53 ( - V_144 ) ;
}
static int F_54 ( struct V_20 * V_21 , T_3 V_145 , T_2 V_104 ,
T_2 * V_146 , T_7 * V_97 )
{
struct V_1 * V_2 = F_10 ( V_21 ) ;
int V_3 ;
F_28 ( V_2 -> V_9 , L_11 , ( T_4 ) V_145 , V_104 ) ;
V_3 = F_29 ( V_2 , V_147 ) ;
if ( V_3 )
return V_3 ;
while ( V_104 ) {
T_3 V_93 = V_145 ;
if ( V_2 -> V_78 & V_99 )
V_93 = F_33 ( V_2 , V_93 ) ;
V_3 = V_2 -> V_148 ( V_2 , V_93 , V_104 , V_97 ) ;
if ( V_3 == 0 ) {
V_3 = - V_109 ;
goto V_149;
}
if ( V_3 < 0 )
goto V_149;
F_55 ( V_3 > V_104 ) ;
* V_146 += V_3 ;
V_97 += V_3 ;
V_145 += V_3 ;
V_104 -= V_3 ;
}
V_3 = 0 ;
V_149:
F_32 ( V_2 , V_147 ) ;
return V_3 ;
}
static int F_56 ( struct V_20 * V_21 , T_3 V_150 , T_2 V_104 ,
T_2 * V_146 , const T_7 * V_97 )
{
struct V_1 * V_2 = F_10 ( V_21 ) ;
T_2 V_151 ;
int V_3 ;
F_28 ( V_2 -> V_9 , L_12 , ( T_4 ) V_150 , V_104 ) ;
V_3 = F_29 ( V_2 , V_152 ) ;
if ( V_3 )
return V_3 ;
F_8 ( V_2 ) ;
V_2 -> V_153 = false ;
V_151 = V_150 % 2 ;
if ( V_151 ) {
V_2 -> V_61 = V_154 ;
V_3 = V_2 -> V_155 ( V_2 , V_150 , 1 , V_97 ) ;
if ( V_3 < 0 )
goto V_156;
F_57 ( V_3 != 1 , L_13 ,
( int ) V_3 ) ;
V_3 = F_26 ( V_2 ) ;
if ( V_3 )
goto V_156;
}
V_150 += V_151 ;
for (; V_151 < V_104 - 1 ; V_151 += 2 ) {
V_2 -> V_61 = V_157 ;
V_3 = V_2 -> V_155 ( V_2 , V_150 , 2 , V_97 + V_151 ) ;
if ( V_3 < 0 )
goto V_156;
F_57 ( V_3 != 2 , L_14 ,
( int ) V_3 ) ;
V_3 = F_26 ( V_2 ) ;
if ( V_3 )
goto V_156;
V_150 += 2 ;
V_2 -> V_153 = true ;
}
V_2 -> V_153 = false ;
F_9 ( V_2 ) ;
V_3 = F_26 ( V_2 ) ;
if ( V_3 )
goto V_156;
if ( V_151 != V_104 ) {
F_8 ( V_2 ) ;
V_2 -> V_61 = V_154 ;
V_3 = V_2 -> V_155 ( V_2 , V_150 , 1 , V_97 + V_151 ) ;
if ( V_3 < 0 )
goto V_156;
F_57 ( V_3 != 1 , L_13 ,
( int ) V_3 ) ;
V_3 = F_26 ( V_2 ) ;
if ( V_3 )
goto V_156;
F_9 ( V_2 ) ;
V_151 += 1 ;
}
V_156:
* V_146 += V_151 ;
F_32 ( V_2 , V_152 ) ;
return V_3 ;
}
static int F_58 ( struct V_20 * V_21 , T_3 V_150 , T_2 V_104 ,
T_2 * V_146 , const T_7 * V_97 )
{
struct V_1 * V_2 = F_10 ( V_21 ) ;
T_2 V_158 , V_159 , V_26 ;
T_8 V_3 ;
F_28 ( V_2 -> V_9 , L_12 , ( T_4 ) V_150 , V_104 ) ;
V_3 = F_29 ( V_2 , V_152 ) ;
if ( V_3 )
return V_3 ;
for ( V_26 = 0 ; V_26 < V_104 ; ) {
T_8 V_160 ;
T_3 V_93 = V_150 + V_26 ;
if ( F_59 ( V_2 -> V_96 ) == 1 ) {
V_158 = V_93 & ( V_2 -> V_96 - 1 ) ;
} else {
T_6 V_161 = V_93 ;
V_158 = F_60 ( V_161 , V_2 -> V_96 ) ;
}
V_159 = F_61 ( T_2 ,
V_2 -> V_96 - V_158 , V_104 - V_26 ) ;
if ( V_2 -> V_78 & V_99 )
V_93 = F_33 ( V_2 , V_93 ) ;
F_8 ( V_2 ) ;
V_3 = V_2 -> V_155 ( V_2 , V_93 , V_159 , V_97 + V_26 ) ;
if ( V_3 < 0 )
goto V_162;
V_160 = V_3 ;
V_3 = F_26 ( V_2 ) ;
if ( V_3 )
goto V_162;
* V_146 += V_160 ;
V_26 += V_160 ;
if ( V_160 != V_159 ) {
F_5 ( V_2 -> V_9 ,
L_15 ,
V_159 , V_160 ) ;
V_3 = - V_109 ;
goto V_162;
}
}
V_162:
F_32 ( V_2 , V_152 ) ;
return V_3 ;
}
static int F_62 ( struct V_1 * V_2 )
{
int V_3 , V_4 ;
V_4 = F_1 ( V_2 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( V_4 & V_163 )
return 0 ;
F_8 ( V_2 ) ;
F_7 ( V_2 , V_4 | V_163 ) ;
if ( F_26 ( V_2 ) )
return 1 ;
V_3 = F_1 ( V_2 ) ;
if ( ! ( V_3 > 0 && ( V_3 & V_163 ) ) ) {
F_5 ( V_2 -> V_9 , L_16 ) ;
return - V_106 ;
}
return 0 ;
}
static int F_63 ( struct V_1 * V_2 , T_9 V_4 )
{
V_2 -> V_15 [ 0 ] = V_4 & 0xff ;
V_2 -> V_15 [ 1 ] = ( V_4 >> 8 ) ;
return V_2 -> V_16 ( V_2 , V_17 , V_2 -> V_15 , 2 ) ;
}
static int F_64 ( struct V_1 * V_2 )
{
int V_3 ;
int V_164 = V_165 << 8 ;
F_8 ( V_2 ) ;
V_3 = F_63 ( V_2 , V_164 ) ;
if ( V_3 < 0 ) {
F_5 ( V_2 -> V_9 ,
L_17 ) ;
return - V_106 ;
}
V_3 = F_26 ( V_2 ) ;
if ( V_3 ) {
F_5 ( V_2 -> V_9 ,
L_18 ) ;
return V_3 ;
}
V_3 = F_4 ( V_2 ) ;
if ( ! ( V_3 > 0 && ( V_3 & V_165 ) ) ) {
F_5 ( V_2 -> V_9 , L_19 ) ;
return - V_106 ;
}
return 0 ;
}
static int F_65 ( struct V_1 * V_2 , const struct V_54 * V_55 )
{
int V_63 ;
switch ( F_17 ( V_55 ) ) {
case V_67 :
V_63 = F_62 ( V_2 ) ;
if ( V_63 ) {
F_5 ( V_2 -> V_9 , L_20 ) ;
return - V_106 ;
}
return V_63 ;
case V_66 :
return 0 ;
default:
V_63 = F_64 ( V_2 ) ;
if ( V_63 ) {
F_5 ( V_2 -> V_9 , L_21 ) ;
return - V_106 ;
}
return V_63 ;
}
}
static int F_66 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_9 || ! V_2 -> V_148 || ! V_2 -> V_155 ||
! V_2 -> V_5 || ! V_2 -> V_16 ) {
F_2 ( L_22 ) ;
return - V_106 ;
}
return 0 ;
}
static int F_67 ( const struct V_54 * V_55 , struct V_1 * V_2 )
{
int V_3 ;
T_1 V_4 ;
V_3 = V_2 -> V_5 ( V_2 , V_72 , & V_4 , 1 ) ;
if ( V_3 < 0 ) {
F_5 ( V_2 -> V_9 , L_4 , ( int ) V_3 ) ;
return V_3 ;
}
V_2 -> V_57 = V_166 ;
V_2 -> V_61 = V_167 ;
V_2 -> V_60 = V_28 ;
V_2 -> V_78 |= V_108 ;
if ( V_4 & V_168 ) {
V_2 -> V_96 = ( V_2 -> V_96 == 264 ) ? 256 : 512 ;
V_2 -> V_21 . V_169 = V_2 -> V_96 ;
V_2 -> V_21 . V_25 = 8 * V_2 -> V_96 * V_55 -> V_170 ;
V_2 -> V_21 . V_58 = 8 * V_2 -> V_96 ;
} else {
V_2 -> V_78 |= V_99 ;
}
return 0 ;
}
int F_68 ( struct V_1 * V_2 , const char * V_171 , enum V_172 V_173 )
{
const struct V_54 * V_55 = NULL ;
struct V_174 * V_9 = V_2 -> V_9 ;
struct V_20 * V_21 = & V_2 -> V_21 ;
struct V_175 * V_176 = F_69 ( V_2 ) ;
int V_3 ;
int V_26 ;
V_3 = F_66 ( V_2 ) ;
if ( V_3 )
return V_3 ;
if ( V_171 )
V_55 = F_70 ( V_171 ) ;
if ( ! V_55 )
V_55 = F_52 ( V_2 ) ;
if ( F_71 ( V_55 ) )
return - V_177 ;
if ( V_171 && V_55 -> V_143 ) {
const struct V_54 * V_178 ;
V_178 = F_52 ( V_2 ) ;
if ( F_72 ( V_178 ) ) {
return F_73 ( V_178 ) ;
} else if ( V_178 != V_55 ) {
F_74 ( V_9 , L_23 ,
V_178 -> V_171 , V_55 -> V_171 ) ;
V_55 = V_178 ;
}
}
F_75 ( & V_2 -> V_90 ) ;
if ( V_55 -> V_78 & V_179 )
V_2 -> V_78 |= V_79 ;
if ( F_17 ( V_55 ) == V_180 ||
F_17 ( V_55 ) == V_181 ||
F_17 ( V_55 ) == V_182 ||
V_55 -> V_78 & V_183 ) {
F_8 ( V_2 ) ;
F_7 ( V_2 , 0 ) ;
F_26 ( V_2 ) ;
}
if ( ! V_21 -> V_171 )
V_21 -> V_171 = F_76 ( V_9 ) ;
V_21 -> V_22 = V_2 ;
V_21 -> type = V_184 ;
V_21 -> V_185 = 1 ;
V_21 -> V_78 = V_186 ;
V_21 -> V_25 = V_55 -> V_59 * V_55 -> V_170 ;
V_21 -> V_187 = F_35 ;
V_21 -> V_188 = F_54 ;
if ( F_17 ( V_55 ) == V_66 ||
V_55 -> V_78 & V_183 ) {
V_2 -> V_134 = F_44 ;
V_2 -> V_136 = F_46 ;
V_2 -> V_137 = F_48 ;
}
if ( V_2 -> V_134 && V_2 -> V_136 && V_2 -> V_137 ) {
V_21 -> V_189 = F_49 ;
V_21 -> V_190 = F_50 ;
V_21 -> V_191 = F_51 ;
}
if ( V_55 -> V_78 & V_192 )
V_21 -> V_193 = F_56 ;
else
V_21 -> V_193 = F_58 ;
if ( V_55 -> V_78 & V_194 )
V_2 -> V_78 |= V_80 ;
if ( V_55 -> V_78 & V_195 )
V_2 -> V_78 |= V_122 ;
if ( V_55 -> V_78 & V_196 )
V_2 -> V_78 |= V_108 ;
#ifdef F_77
if ( V_55 -> V_78 & V_197 ) {
V_2 -> V_57 = V_48 ;
V_21 -> V_58 = 4096 ;
} else if ( V_55 -> V_78 & V_198 ) {
V_2 -> V_57 = V_199 ;
V_21 -> V_58 = 4096 ;
} else
#endif
{
V_2 -> V_57 = V_52 ;
V_21 -> V_58 = V_55 -> V_59 ;
}
if ( V_55 -> V_78 & V_200 )
V_21 -> V_78 |= V_201 ;
V_21 -> V_9 . V_202 = V_9 ;
V_2 -> V_96 = V_55 -> V_96 ;
V_21 -> V_169 = V_2 -> V_96 ;
if ( V_176 ) {
if ( F_78 ( V_176 , L_24 ) )
V_2 -> V_10 = V_11 ;
else
V_2 -> V_10 = V_14 ;
} else {
V_2 -> V_10 = V_11 ;
}
if ( V_55 -> V_78 & V_203 )
V_2 -> V_10 = V_14 ;
if ( V_173 == V_13 && V_55 -> V_78 & V_204 ) {
V_3 = F_65 ( V_2 , V_55 ) ;
if ( V_3 ) {
F_5 ( V_9 , L_25 ) ;
return V_3 ;
}
V_2 -> V_10 = V_13 ;
} else if ( V_173 == V_12 && V_55 -> V_78 & V_205 ) {
V_2 -> V_10 = V_12 ;
}
switch ( V_2 -> V_10 ) {
case V_13 :
V_2 -> V_60 = V_36 ;
break;
case V_12 :
V_2 -> V_60 = V_32 ;
break;
case V_11 :
V_2 -> V_60 = V_30 ;
break;
case V_14 :
V_2 -> V_60 = V_28 ;
break;
default:
F_5 ( V_9 , L_26 ) ;
return - V_106 ;
}
V_2 -> V_61 = V_41 ;
if ( V_55 -> V_101 )
V_2 -> V_101 = V_55 -> V_101 ;
else if ( V_21 -> V_25 > 0x1000000 ) {
V_2 -> V_101 = 4 ;
if ( F_17 ( V_55 ) == V_56 ||
V_55 -> V_78 & V_206 )
F_16 ( V_2 , V_55 ) ;
else
F_18 ( V_2 , V_55 , 1 ) ;
} else {
V_2 -> V_101 = 3 ;
}
if ( V_2 -> V_101 > V_98 ) {
F_5 ( V_9 , L_27 ,
V_2 -> V_101 ) ;
return - V_106 ;
}
V_2 -> V_207 = F_6 ( V_2 ) ;
if ( V_55 -> V_78 & V_179 ) {
V_3 = F_67 ( V_55 , V_2 ) ;
if ( V_3 )
return V_3 ;
}
F_79 ( V_9 , L_28 , V_55 -> V_171 ,
( long long ) V_21 -> V_25 >> 10 ) ;
F_28 ( V_9 ,
L_29
L_30 ,
V_21 -> V_171 , ( long long ) V_21 -> V_25 , ( long long ) ( V_21 -> V_25 >> 20 ) ,
V_21 -> V_58 , V_21 -> V_58 / 1024 , V_21 -> V_208 ) ;
if ( V_21 -> V_208 )
for ( V_26 = 0 ; V_26 < V_21 -> V_208 ; V_26 ++ )
F_28 ( V_9 ,
L_31
L_32
L_33 ,
V_26 , ( long long ) V_21 -> V_209 [ V_26 ] . V_94 ,
V_21 -> V_209 [ V_26 ] . V_58 ,
V_21 -> V_209 [ V_26 ] . V_58 / 1024 ,
V_21 -> V_209 [ V_26 ] . V_210 ) ;
return 0 ;
}
static const struct V_54 * F_70 ( const char * V_171 )
{
const struct V_54 * V_139 = V_142 ;
while ( V_139 -> V_171 ) {
if ( ! strcmp ( V_171 , V_139 -> V_171 ) )
return V_139 ;
V_139 ++ ;
}
return NULL ;
}
