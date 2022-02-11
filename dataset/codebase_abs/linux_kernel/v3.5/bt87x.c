static inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static int F_5 ( struct V_1 * V_2 , struct V_6 * V_7 ,
unsigned int V_8 , unsigned int V_9 )
{
unsigned int V_10 , V_11 ;
T_1 * V_12 ;
if ( V_2 -> V_13 . V_14 == NULL ) {
if ( F_6 ( V_15 , F_7 ( V_2 -> V_16 ) ,
F_8 ( V_17 ) , & V_2 -> V_13 ) < 0 )
return - V_18 ;
}
V_12 = ( T_1 * ) V_2 -> V_13 . V_14 ;
V_11 = 0 ;
* V_12 ++ = F_9 ( V_19 | V_20 ) ;
* V_12 ++ = F_9 ( 0 ) ;
for ( V_10 = 0 ; V_10 < V_8 ; ++ V_10 ) {
T_1 V_21 ;
V_21 = V_9 ;
do {
T_1 V_22 , V_23 ;
unsigned int V_24 ;
V_23 = V_25 - ( V_11 % V_25 ) ;
if ( V_23 > V_21 )
V_23 = V_21 ;
V_22 = V_26 | V_23 ;
if ( V_21 == V_9 ) {
T_1 V_27 = V_10 * 16 / V_8 ;
V_22 |= V_28 ;
V_22 |= V_27 << V_29 ;
V_22 |= ( ~ V_27 & 0xf ) << V_30 ;
}
if ( V_23 == V_21 )
V_22 |= V_31 | V_32 ;
* V_12 ++ = F_9 ( V_22 ) ;
V_24 = F_10 ( V_7 , V_11 ) ;
* V_12 ++ = F_9 ( V_24 ) ;
V_11 += V_23 ;
V_21 -= V_23 ;
} while ( V_21 > 0 );
}
* V_12 ++ = F_9 ( V_19 | V_33 ) ;
* V_12 ++ = F_9 ( 0 ) ;
* V_12 ++ = F_9 ( V_34 ) ;
* V_12 ++ = F_9 ( V_2 -> V_13 . V_24 ) ;
V_2 -> V_35 = V_9 ;
V_2 -> V_36 = V_8 ;
return 0 ;
}
static void F_11 ( struct V_1 * V_2 )
{
if ( V_2 -> V_13 . V_14 ) {
F_12 ( & V_2 -> V_13 ) ;
V_2 -> V_13 . V_14 = NULL ;
}
}
static void F_13 ( struct V_1 * V_2 , unsigned int V_37 )
{
T_2 V_38 ;
F_14 ( V_2 -> V_16 , V_39 , & V_38 ) ;
V_38 &= V_40 | V_41 |
V_42 | V_43 |
V_44 | V_45 ;
F_15 ( V_2 -> V_16 , V_39 , V_38 ) ;
if ( V_38 != V_45 )
F_16 ( V_46 L_1 ,
V_37 & V_47 , V_38 ) ;
else {
F_16 ( V_46 L_2 ) ;
V_2 -> V_48 ++ ;
if ( V_2 -> V_48 > 20 ) {
F_16 ( V_46 L_3 ) ;
F_16 ( V_46 L_4 ) ;
F_16 ( V_46 L_5 ) ;
F_16 ( V_46 L_6 ) ;
V_2 -> V_49 &= ~ ( V_50 | V_51 ) ;
F_3 ( V_2 , V_52 , V_2 -> V_49 ) ;
}
}
}
static T_3 F_17 ( int V_53 , void * V_54 )
{
struct V_1 * V_2 = V_54 ;
unsigned int V_37 , V_55 ;
V_37 = F_1 ( V_2 , V_56 ) ;
V_55 = V_37 & V_2 -> V_49 ;
if ( ! V_55 )
return V_57 ;
F_3 ( V_2 , V_56 , V_55 ) ;
if ( V_55 & V_47 ) {
if ( V_55 & ( V_58 | V_59 ) )
F_16 ( V_60 L_7 , V_37 ) ;
if ( V_55 & V_61 )
F_16 ( V_46 L_8 , V_37 ) ;
if ( V_55 & ( V_50 | V_51 | V_62 ) )
F_13 ( V_2 , V_55 ) ;
}
if ( ( V_55 & V_63 ) && ( V_2 -> V_64 & V_65 ) ) {
int V_66 , V_67 ;
V_2 -> V_68 = ( V_2 -> V_68 + 1 ) % V_2 -> V_36 ;
V_66 = V_2 -> V_68 * 16 / V_2 -> V_36 ;
V_67 = V_37 >> V_69 ;
if ( V_66 != V_67 )
V_2 -> V_68 = ( V_67 * V_2 -> V_36 + 15 ) / 16 ;
F_18 ( V_2 -> V_7 ) ;
}
return V_70 ;
}
static int F_19 ( struct V_1 * V_2 , struct V_71 * V_72 )
{
V_2 -> V_64 |= V_73 | V_74 ;
V_72 -> V_75 = V_76 ;
V_72 -> V_75 . V_77 = F_20 ( V_2 -> V_78 . V_79 ) ;
V_72 -> V_75 . V_80 = V_2 -> V_78 . V_79 ;
V_72 -> V_75 . V_81 = V_2 -> V_78 . V_79 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 , struct V_71 * V_72 )
{
static struct V_82 V_83 = {
. V_84 = V_85 ,
. V_86 = V_87 ,
. V_88 = V_89 ,
. V_90 = 1
} ;
static struct V_91 V_92 = {
. V_93 = 1 ,
. V_94 = & V_83
} ;
V_2 -> V_64 &= ~ ( V_73 | V_74 ) ;
V_72 -> V_75 = V_95 ;
return V_91 ( V_72 , 0 , V_96 ,
& V_92 ) ;
}
static int F_22 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_23 ( V_7 ) ;
struct V_71 * V_72 = V_7 -> V_72 ;
int V_97 ;
if ( F_24 ( 0 , & V_2 -> V_98 ) )
return - V_99 ;
if ( V_7 -> V_100 -> V_101 == V_102 )
V_97 = F_19 ( V_2 , V_72 ) ;
else
V_97 = F_21 ( V_2 , V_72 ) ;
if ( V_97 < 0 )
goto V_103;
V_97 = F_25 ( V_72 , V_104 ) ;
if ( V_97 < 0 )
goto V_103;
V_2 -> V_7 = V_7 ;
return 0 ;
V_103:
F_26 ( 0 , & V_2 -> V_98 ) ;
F_27 () ;
return V_97 ;
}
static int F_28 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_23 ( V_7 ) ;
F_29 ( & V_2 -> V_105 ) ;
V_2 -> V_64 |= V_74 ;
F_3 ( V_2 , V_106 , V_2 -> V_64 ) ;
F_30 ( & V_2 -> V_105 ) ;
V_2 -> V_7 = NULL ;
F_26 ( 0 , & V_2 -> V_98 ) ;
F_27 () ;
return 0 ;
}
static int F_31 ( struct V_6 * V_7 ,
struct V_107 * V_108 )
{
struct V_1 * V_2 = F_23 ( V_7 ) ;
int V_97 ;
V_97 = F_32 ( V_7 ,
F_33 ( V_108 ) ) ;
if ( V_97 < 0 )
return V_97 ;
return F_5 ( V_2 , V_7 ,
F_34 ( V_108 ) ,
F_35 ( V_108 ) ) ;
}
static int F_36 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_23 ( V_7 ) ;
F_11 ( V_2 ) ;
F_37 ( V_7 ) ;
return 0 ;
}
static int F_38 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_23 ( V_7 ) ;
struct V_71 * V_72 = V_7 -> V_72 ;
int V_109 ;
F_29 ( & V_2 -> V_105 ) ;
V_2 -> V_64 &= ~ ( V_110 | V_111 ) ;
V_109 = ( V_85 + V_72 -> V_112 / 4 ) / V_72 -> V_112 ;
V_2 -> V_64 |= V_109 << V_113 ;
if ( V_72 -> V_114 == V_115 )
V_2 -> V_64 |= V_111 ;
F_3 ( V_2 , V_106 , V_2 -> V_64 ) ;
F_30 ( & V_2 -> V_105 ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 )
{
F_40 ( & V_2 -> V_105 ) ;
V_2 -> V_68 = 0 ;
V_2 -> V_64 |= V_116 | V_117 | V_65 ;
F_3 ( V_2 , V_118 , V_2 -> V_13 . V_24 ) ;
F_3 ( V_2 , V_119 ,
V_2 -> V_35 | ( V_2 -> V_36 << 16 ) ) ;
F_3 ( V_2 , V_52 , V_2 -> V_49 ) ;
F_3 ( V_2 , V_106 , V_2 -> V_64 ) ;
F_41 ( & V_2 -> V_105 ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 )
{
F_40 ( & V_2 -> V_105 ) ;
V_2 -> V_64 &= ~ ( V_116 | V_117 | V_65 ) ;
F_3 ( V_2 , V_106 , V_2 -> V_64 ) ;
F_3 ( V_2 , V_52 , 0 ) ;
F_3 ( V_2 , V_56 , V_120 ) ;
F_41 ( & V_2 -> V_105 ) ;
return 0 ;
}
static int F_43 ( struct V_6 * V_7 , int V_22 )
{
struct V_1 * V_2 = F_23 ( V_7 ) ;
switch ( V_22 ) {
case V_121 :
return F_39 ( V_2 ) ;
case V_122 :
return F_42 ( V_2 ) ;
default:
return - V_123 ;
}
}
static T_4 F_44 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_23 ( V_7 ) ;
struct V_71 * V_72 = V_7 -> V_72 ;
return ( T_4 ) F_45 ( V_72 , V_2 -> V_68 * V_2 -> V_35 ) ;
}
static int F_46 ( struct V_124 * V_125 ,
struct V_126 * V_127 )
{
V_127 -> type = V_128 ;
V_127 -> V_129 = 1 ;
V_127 -> V_5 . integer . V_130 = 0 ;
V_127 -> V_5 . integer . V_131 = 15 ;
return 0 ;
}
static int F_47 ( struct V_124 * V_125 ,
struct V_132 * V_5 )
{
struct V_1 * V_2 = F_48 ( V_125 ) ;
V_5 -> V_5 . integer . V_5 [ 0 ] = ( V_2 -> V_64 & V_133 ) >> V_134 ;
return 0 ;
}
static int F_49 ( struct V_124 * V_125 ,
struct V_132 * V_5 )
{
struct V_1 * V_2 = F_48 ( V_125 ) ;
T_1 V_135 ;
int V_136 ;
F_29 ( & V_2 -> V_105 ) ;
V_135 = V_2 -> V_64 ;
V_2 -> V_64 = ( V_2 -> V_64 & ~ V_133 )
| ( V_5 -> V_5 . integer . V_5 [ 0 ] << V_134 ) ;
F_3 ( V_2 , V_106 , V_2 -> V_64 ) ;
V_136 = V_135 != V_2 -> V_64 ;
F_30 ( & V_2 -> V_105 ) ;
return V_136 ;
}
static int F_50 ( struct V_124 * V_125 ,
struct V_132 * V_5 )
{
struct V_1 * V_2 = F_48 ( V_125 ) ;
V_5 -> V_5 . integer . V_5 [ 0 ] = ! ! ( V_2 -> V_64 & V_137 ) ;
return 0 ;
}
static int F_51 ( struct V_124 * V_125 ,
struct V_132 * V_5 )
{
struct V_1 * V_2 = F_48 ( V_125 ) ;
T_1 V_135 ;
int V_136 ;
F_29 ( & V_2 -> V_105 ) ;
V_135 = V_2 -> V_64 ;
V_2 -> V_64 = ( V_2 -> V_64 & ~ V_137 )
| ( V_5 -> V_5 . integer . V_5 [ 0 ] ? V_137 : 0 ) ;
F_3 ( V_2 , V_106 , V_2 -> V_64 ) ;
V_136 = V_2 -> V_64 != V_135 ;
F_30 ( & V_2 -> V_105 ) ;
return V_136 ;
}
static int F_52 ( struct V_124 * V_125 ,
struct V_126 * V_127 )
{
static const char * const V_138 [ 3 ] = { L_9 , L_10 , L_11 } ;
return F_53 ( V_127 , 1 , 3 , V_138 ) ;
}
static int F_54 ( struct V_124 * V_125 ,
struct V_132 * V_5 )
{
struct V_1 * V_2 = F_48 ( V_125 ) ;
V_5 -> V_5 . V_139 . V_140 [ 0 ] = ( V_2 -> V_64 & V_141 ) >> V_142 ;
return 0 ;
}
static int F_55 ( struct V_124 * V_125 ,
struct V_132 * V_5 )
{
struct V_1 * V_2 = F_48 ( V_125 ) ;
T_1 V_135 ;
int V_136 ;
F_29 ( & V_2 -> V_105 ) ;
V_135 = V_2 -> V_64 ;
V_2 -> V_64 = ( V_2 -> V_64 & ~ V_141 )
| ( V_5 -> V_5 . V_139 . V_140 [ 0 ] << V_142 ) ;
F_3 ( V_2 , V_106 , V_2 -> V_64 ) ;
V_136 = V_2 -> V_64 != V_135 ;
F_30 ( & V_2 -> V_105 ) ;
return V_136 ;
}
static int F_56 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 )
F_42 ( V_2 ) ;
if ( V_2 -> V_53 >= 0 )
F_57 ( V_2 -> V_53 , V_2 ) ;
if ( V_2 -> V_4 )
F_58 ( V_2 -> V_4 ) ;
F_59 ( V_2 -> V_16 ) ;
F_60 ( V_2 -> V_16 ) ;
F_61 ( V_2 ) ;
return 0 ;
}
static int F_62 ( struct V_143 * V_101 )
{
struct V_1 * V_2 = V_101 -> V_144 ;
return F_56 ( V_2 ) ;
}
static int T_5 F_63 ( struct V_1 * V_2 , int V_101 , char * V_145 )
{
int V_97 ;
struct V_146 * V_100 ;
V_97 = F_64 ( V_2 -> V_147 , V_145 , V_101 , 0 , 1 , & V_100 ) ;
if ( V_97 < 0 )
return V_97 ;
V_100 -> V_148 = V_2 ;
strcpy ( V_100 -> V_145 , V_145 ) ;
F_65 ( V_100 , V_149 , & V_150 ) ;
return F_66 ( V_100 ,
V_151 ,
F_7 ( V_2 -> V_16 ) ,
128 * 1024 ,
F_67 ( 255 * 4092 , 1024 ) ) ;
}
static int T_5 F_68 ( struct V_152 * V_147 ,
struct V_153 * V_16 ,
struct V_1 * * V_154 )
{
struct V_1 * V_2 ;
int V_97 ;
static struct V_155 V_156 = {
. V_157 = F_62
} ;
* V_154 = NULL ;
V_97 = F_69 ( V_16 ) ;
if ( V_97 < 0 )
return V_97 ;
V_2 = F_70 ( sizeof( * V_2 ) , V_158 ) ;
if ( ! V_2 ) {
F_60 ( V_16 ) ;
return - V_18 ;
}
V_2 -> V_147 = V_147 ;
V_2 -> V_16 = V_16 ;
V_2 -> V_53 = - 1 ;
F_71 ( & V_2 -> V_105 ) ;
if ( ( V_97 = F_72 ( V_16 , L_12 ) ) < 0 ) {
F_61 ( V_2 ) ;
F_60 ( V_16 ) ;
return V_97 ;
}
V_2 -> V_4 = F_73 ( V_16 , 0 ) ;
if ( ! V_2 -> V_4 ) {
F_16 ( V_46 L_13 ) ;
V_97 = - V_18 ;
goto V_159;
}
V_2 -> V_64 = V_74 | V_160 |
V_161 | ( 15 << V_113 ) ;
V_2 -> V_49 = V_120 ;
F_3 ( V_2 , V_106 , V_2 -> V_64 ) ;
F_3 ( V_2 , V_52 , 0 ) ;
F_3 ( V_2 , V_56 , V_120 ) ;
V_97 = F_74 ( V_16 -> V_53 , F_17 , V_162 ,
V_163 , V_2 ) ;
if ( V_97 < 0 ) {
F_16 ( V_46 L_14 , V_16 -> V_53 ) ;
goto V_159;
}
V_2 -> V_53 = V_16 -> V_53 ;
F_75 ( V_16 ) ;
F_76 ( V_2 -> V_53 ) ;
V_97 = F_77 ( V_147 , V_164 , V_2 , & V_156 ) ;
if ( V_97 < 0 )
goto V_159;
F_78 ( V_147 , & V_16 -> V_165 ) ;
* V_154 = V_2 ;
return 0 ;
V_159:
F_56 ( V_2 ) ;
return V_97 ;
}
static int T_5 F_79 ( struct V_153 * V_16 )
{
int V_10 ;
const struct V_166 * V_167 ;
V_167 = F_80 ( V_168 , V_16 ) ;
if ( V_167 && V_167 -> V_169 > 0 )
return V_167 -> V_169 ;
for ( V_10 = 0 ; V_10 < F_81 ( V_170 ) ; ++ V_10 )
if ( V_170 [ V_10 ] . V_171 == V_16 -> V_172 &&
V_170 [ V_10 ] . V_173 == V_16 -> V_174 ) {
F_82 ( V_175 L_15 ,
V_16 -> V_101 , V_16 -> V_172 , V_16 -> V_174 ) ;
return - V_99 ;
}
F_16 ( V_175 L_16 ,
V_16 -> V_101 , V_16 -> V_172 , V_16 -> V_174 ) ;
F_16 ( V_176 L_17
L_18
L_19 ) ;
return V_177 ;
}
static int T_5 F_83 ( struct V_153 * V_16 ,
const struct V_166 * V_178 )
{
static int V_165 ;
struct V_152 * V_147 ;
struct V_1 * V_2 ;
int V_97 ;
enum V_179 V_180 ;
if ( ! V_178 -> V_169 ) {
V_97 = F_79 ( V_16 ) ;
if ( V_97 < 0 )
return - V_181 ;
V_180 = V_97 ;
} else
V_180 = V_178 -> V_169 ;
if ( V_165 >= V_182 )
return - V_181 ;
if ( ! V_183 [ V_165 ] ) {
++ V_165 ;
return - V_184 ;
}
V_97 = F_84 ( V_185 [ V_165 ] , V_186 [ V_165 ] , V_187 , 0 , & V_147 ) ;
if ( V_97 < 0 )
return V_97 ;
V_97 = F_68 ( V_147 , V_16 , & V_2 ) ;
if ( V_97 < 0 )
goto V_103;
memcpy ( & V_2 -> V_78 , & V_188 [ V_180 ] , sizeof( V_2 -> V_78 ) ) ;
if ( ! V_2 -> V_78 . V_189 ) {
if ( V_190 [ V_165 ] > 0 )
V_2 -> V_78 . V_79 = V_190 [ V_165 ] ;
V_2 -> V_64 |= V_2 -> V_78 . V_191 ;
V_97 = F_63 ( V_2 , V_102 , L_20 ) ;
if ( V_97 < 0 )
goto V_103;
}
if ( ! V_2 -> V_78 . V_192 ) {
V_97 = F_63 ( V_2 , V_193 , L_21 ) ;
if ( V_97 < 0 )
goto V_103;
V_97 = F_85 ( V_147 , F_86 (
& V_194 , V_2 ) ) ;
if ( V_97 < 0 )
goto V_103;
V_97 = F_85 ( V_147 , F_86 (
& V_195 , V_2 ) ) ;
if ( V_97 < 0 )
goto V_103;
V_97 = F_85 ( V_147 , F_86 (
& V_196 , V_2 ) ) ;
if ( V_97 < 0 )
goto V_103;
}
F_16 ( V_175 L_22
L_23 , V_165 , V_180 ,
V_2 -> V_78 . V_192 ? L_24 : L_25 ,
V_2 -> V_78 . V_189 ? L_24 : L_25 , V_2 -> V_78 . V_79 ) ;
strcpy ( V_147 -> V_197 , L_26 ) ;
sprintf ( V_147 -> V_198 , L_27 , V_16 -> V_101 ) ;
sprintf ( V_147 -> V_199 , L_28 ,
V_147 -> V_198 , ( unsigned long long ) F_87 ( V_16 , 0 ) ,
V_2 -> V_53 ) ;
strcpy ( V_147 -> V_200 , L_26 ) ;
V_97 = F_88 ( V_147 ) ;
if ( V_97 < 0 )
goto V_103;
F_89 ( V_16 , V_147 ) ;
++ V_165 ;
return 0 ;
V_103:
F_90 ( V_147 ) ;
return V_97 ;
}
static void T_6 F_91 ( struct V_153 * V_16 )
{
F_90 ( F_92 ( V_16 ) ) ;
F_89 ( V_16 , NULL ) ;
}
