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
F_16 ( V_2 -> V_46 -> V_47 ,
L_1 ,
V_37 & V_48 , V_38 ) ;
else {
F_16 ( V_2 -> V_46 -> V_47 ,
L_2 ) ;
V_2 -> V_49 ++ ;
if ( V_2 -> V_49 > 20 ) {
F_16 ( V_2 -> V_46 -> V_47 ,
L_3 ) ;
F_16 ( V_2 -> V_46 -> V_47 ,
L_4 ) ;
F_16 ( V_2 -> V_46 -> V_47 ,
L_5 ) ;
F_16 ( V_2 -> V_46 -> V_47 ,
L_6 ) ;
V_2 -> V_50 &= ~ ( V_51 | V_52 ) ;
F_3 ( V_2 , V_53 , V_2 -> V_50 ) ;
}
}
}
static T_3 F_17 ( int V_54 , void * V_55 )
{
struct V_1 * V_2 = V_55 ;
unsigned int V_37 , V_56 ;
V_37 = F_1 ( V_2 , V_57 ) ;
V_56 = V_37 & V_2 -> V_50 ;
if ( ! V_56 )
return V_58 ;
F_3 ( V_2 , V_57 , V_56 ) ;
if ( V_56 & V_48 ) {
if ( V_56 & ( V_59 | V_60 ) )
F_18 ( V_2 -> V_46 -> V_47 ,
L_7 , V_37 ) ;
if ( V_56 & V_61 )
F_16 ( V_2 -> V_46 -> V_47 ,
L_8 , V_37 ) ;
if ( V_56 & ( V_51 | V_52 | V_62 ) )
F_13 ( V_2 , V_56 ) ;
}
if ( ( V_56 & V_63 ) && ( V_2 -> V_64 & V_65 ) ) {
int V_66 , V_67 ;
V_2 -> V_68 = ( V_2 -> V_68 + 1 ) % V_2 -> V_36 ;
V_66 = V_2 -> V_68 * 16 / V_2 -> V_36 ;
V_67 = V_37 >> V_69 ;
if ( V_66 != V_67 )
V_2 -> V_68 = ( V_67 * V_2 -> V_36 + 15 ) / 16 ;
F_19 ( V_2 -> V_7 ) ;
}
return V_70 ;
}
static int F_20 ( struct V_1 * V_2 , struct V_71 * V_72 )
{
V_2 -> V_64 |= V_73 | V_74 ;
V_72 -> V_75 = V_76 ;
V_72 -> V_75 . V_77 = F_21 ( V_2 -> V_78 . V_79 ) ;
V_72 -> V_75 . V_80 = V_2 -> V_78 . V_79 ;
V_72 -> V_75 . V_81 = V_2 -> V_78 . V_79 ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 , struct V_71 * V_72 )
{
static const struct V_82 V_83 = {
. V_84 = V_85 ,
. V_86 = V_87 ,
. V_88 = V_89 ,
. V_90 = 1
} ;
static const struct V_91 V_92 = {
. V_93 = 1 ,
. V_94 = & V_83
} ;
V_2 -> V_64 &= ~ ( V_73 | V_74 ) ;
V_72 -> V_75 = V_95 ;
return V_91 ( V_72 , 0 , V_96 ,
& V_92 ) ;
}
static int F_23 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_24 ( V_7 ) ;
struct V_71 * V_72 = V_7 -> V_72 ;
int V_97 ;
if ( F_25 ( 0 , & V_2 -> V_98 ) )
return - V_99 ;
if ( V_7 -> V_100 -> V_101 == V_102 )
V_97 = F_20 ( V_2 , V_72 ) ;
else
V_97 = F_22 ( V_2 , V_72 ) ;
if ( V_97 < 0 )
goto V_103;
V_97 = F_26 ( V_72 , V_104 ) ;
if ( V_97 < 0 )
goto V_103;
V_2 -> V_7 = V_7 ;
return 0 ;
V_103:
F_27 ( 0 , & V_2 -> V_98 ) ;
F_28 () ;
return V_97 ;
}
static int F_29 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_24 ( V_7 ) ;
F_30 ( & V_2 -> V_105 ) ;
V_2 -> V_64 |= V_74 ;
F_3 ( V_2 , V_106 , V_2 -> V_64 ) ;
F_31 ( & V_2 -> V_105 ) ;
V_2 -> V_7 = NULL ;
F_27 ( 0 , & V_2 -> V_98 ) ;
F_28 () ;
return 0 ;
}
static int F_32 ( struct V_6 * V_7 ,
struct V_107 * V_108 )
{
struct V_1 * V_2 = F_24 ( V_7 ) ;
int V_97 ;
V_97 = F_33 ( V_7 ,
F_34 ( V_108 ) ) ;
if ( V_97 < 0 )
return V_97 ;
return F_5 ( V_2 , V_7 ,
F_35 ( V_108 ) ,
F_36 ( V_108 ) ) ;
}
static int F_37 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_24 ( V_7 ) ;
F_11 ( V_2 ) ;
F_38 ( V_7 ) ;
return 0 ;
}
static int F_39 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_24 ( V_7 ) ;
struct V_71 * V_72 = V_7 -> V_72 ;
int V_109 ;
F_30 ( & V_2 -> V_105 ) ;
V_2 -> V_64 &= ~ ( V_110 | V_111 ) ;
V_109 = ( V_85 + V_72 -> V_112 / 4 ) / V_72 -> V_112 ;
V_2 -> V_64 |= V_109 << V_113 ;
if ( V_72 -> V_114 == V_115 )
V_2 -> V_64 |= V_111 ;
F_3 ( V_2 , V_106 , V_2 -> V_64 ) ;
F_31 ( & V_2 -> V_105 ) ;
return 0 ;
}
static int F_40 ( struct V_1 * V_2 )
{
F_41 ( & V_2 -> V_105 ) ;
V_2 -> V_68 = 0 ;
V_2 -> V_64 |= V_116 | V_117 | V_65 ;
F_3 ( V_2 , V_118 , V_2 -> V_13 . V_24 ) ;
F_3 ( V_2 , V_119 ,
V_2 -> V_35 | ( V_2 -> V_36 << 16 ) ) ;
F_3 ( V_2 , V_53 , V_2 -> V_50 ) ;
F_3 ( V_2 , V_106 , V_2 -> V_64 ) ;
F_42 ( & V_2 -> V_105 ) ;
return 0 ;
}
static int F_43 ( struct V_1 * V_2 )
{
F_41 ( & V_2 -> V_105 ) ;
V_2 -> V_64 &= ~ ( V_116 | V_117 | V_65 ) ;
F_3 ( V_2 , V_106 , V_2 -> V_64 ) ;
F_3 ( V_2 , V_53 , 0 ) ;
F_3 ( V_2 , V_57 , V_120 ) ;
F_42 ( & V_2 -> V_105 ) ;
return 0 ;
}
static int F_44 ( struct V_6 * V_7 , int V_22 )
{
struct V_1 * V_2 = F_24 ( V_7 ) ;
switch ( V_22 ) {
case V_121 :
return F_40 ( V_2 ) ;
case V_122 :
return F_43 ( V_2 ) ;
default:
return - V_123 ;
}
}
static T_4 F_45 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_24 ( V_7 ) ;
struct V_71 * V_72 = V_7 -> V_72 ;
return ( T_4 ) F_46 ( V_72 , V_2 -> V_68 * V_2 -> V_35 ) ;
}
static int F_47 ( struct V_124 * V_125 ,
struct V_126 * V_127 )
{
V_127 -> type = V_128 ;
V_127 -> V_129 = 1 ;
V_127 -> V_5 . integer . V_130 = 0 ;
V_127 -> V_5 . integer . V_131 = 15 ;
return 0 ;
}
static int F_48 ( struct V_124 * V_125 ,
struct V_132 * V_5 )
{
struct V_1 * V_2 = F_49 ( V_125 ) ;
V_5 -> V_5 . integer . V_5 [ 0 ] = ( V_2 -> V_64 & V_133 ) >> V_134 ;
return 0 ;
}
static int F_50 ( struct V_124 * V_125 ,
struct V_132 * V_5 )
{
struct V_1 * V_2 = F_49 ( V_125 ) ;
T_1 V_135 ;
int V_136 ;
F_30 ( & V_2 -> V_105 ) ;
V_135 = V_2 -> V_64 ;
V_2 -> V_64 = ( V_2 -> V_64 & ~ V_133 )
| ( V_5 -> V_5 . integer . V_5 [ 0 ] << V_134 ) ;
F_3 ( V_2 , V_106 , V_2 -> V_64 ) ;
V_136 = V_135 != V_2 -> V_64 ;
F_31 ( & V_2 -> V_105 ) ;
return V_136 ;
}
static int F_51 ( struct V_124 * V_125 ,
struct V_132 * V_5 )
{
struct V_1 * V_2 = F_49 ( V_125 ) ;
V_5 -> V_5 . integer . V_5 [ 0 ] = ! ! ( V_2 -> V_64 & V_137 ) ;
return 0 ;
}
static int F_52 ( struct V_124 * V_125 ,
struct V_132 * V_5 )
{
struct V_1 * V_2 = F_49 ( V_125 ) ;
T_1 V_135 ;
int V_136 ;
F_30 ( & V_2 -> V_105 ) ;
V_135 = V_2 -> V_64 ;
V_2 -> V_64 = ( V_2 -> V_64 & ~ V_137 )
| ( V_5 -> V_5 . integer . V_5 [ 0 ] ? V_137 : 0 ) ;
F_3 ( V_2 , V_106 , V_2 -> V_64 ) ;
V_136 = V_2 -> V_64 != V_135 ;
F_31 ( & V_2 -> V_105 ) ;
return V_136 ;
}
static int F_53 ( struct V_124 * V_125 ,
struct V_126 * V_127 )
{
static const char * const V_138 [ 3 ] = { L_9 , L_10 , L_11 } ;
return F_54 ( V_127 , 1 , 3 , V_138 ) ;
}
static int F_55 ( struct V_124 * V_125 ,
struct V_132 * V_5 )
{
struct V_1 * V_2 = F_49 ( V_125 ) ;
V_5 -> V_5 . V_139 . V_140 [ 0 ] = ( V_2 -> V_64 & V_141 ) >> V_142 ;
return 0 ;
}
static int F_56 ( struct V_124 * V_125 ,
struct V_132 * V_5 )
{
struct V_1 * V_2 = F_49 ( V_125 ) ;
T_1 V_135 ;
int V_136 ;
F_30 ( & V_2 -> V_105 ) ;
V_135 = V_2 -> V_64 ;
V_2 -> V_64 = ( V_2 -> V_64 & ~ V_141 )
| ( V_5 -> V_5 . V_139 . V_140 [ 0 ] << V_142 ) ;
F_3 ( V_2 , V_106 , V_2 -> V_64 ) ;
V_136 = V_2 -> V_64 != V_135 ;
F_31 ( & V_2 -> V_105 ) ;
return V_136 ;
}
static int F_57 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 )
F_43 ( V_2 ) ;
if ( V_2 -> V_54 >= 0 )
F_58 ( V_2 -> V_54 , V_2 ) ;
F_59 ( V_2 -> V_4 ) ;
F_60 ( V_2 -> V_16 ) ;
F_61 ( V_2 -> V_16 ) ;
F_62 ( V_2 ) ;
return 0 ;
}
static int F_63 ( struct V_143 * V_101 )
{
struct V_1 * V_2 = V_101 -> V_144 ;
return F_57 ( V_2 ) ;
}
static int F_64 ( struct V_1 * V_2 , int V_101 , char * V_145 )
{
int V_97 ;
struct V_146 * V_100 ;
V_97 = F_65 ( V_2 -> V_46 , V_145 , V_101 , 0 , 1 , & V_100 ) ;
if ( V_97 < 0 )
return V_97 ;
V_100 -> V_147 = V_2 ;
strcpy ( V_100 -> V_145 , V_145 ) ;
F_66 ( V_100 , V_148 , & V_149 ) ;
return F_67 ( V_100 ,
V_150 ,
F_7 ( V_2 -> V_16 ) ,
128 * 1024 ,
F_68 ( 255 * 4092 , 1024 ) ) ;
}
static int F_69 ( struct V_151 * V_46 ,
struct V_152 * V_16 ,
struct V_1 * * V_153 )
{
struct V_1 * V_2 ;
int V_97 ;
static struct V_154 V_155 = {
. V_156 = F_63
} ;
* V_153 = NULL ;
V_97 = F_70 ( V_16 ) ;
if ( V_97 < 0 )
return V_97 ;
V_2 = F_71 ( sizeof( * V_2 ) , V_157 ) ;
if ( ! V_2 ) {
F_61 ( V_16 ) ;
return - V_18 ;
}
V_2 -> V_46 = V_46 ;
V_2 -> V_16 = V_16 ;
V_2 -> V_54 = - 1 ;
F_72 ( & V_2 -> V_105 ) ;
if ( ( V_97 = F_73 ( V_16 , L_12 ) ) < 0 ) {
F_62 ( V_2 ) ;
F_61 ( V_16 ) ;
return V_97 ;
}
V_2 -> V_4 = F_74 ( V_16 , 0 ) ;
if ( ! V_2 -> V_4 ) {
F_16 ( V_46 -> V_47 , L_13 ) ;
V_97 = - V_18 ;
goto V_158;
}
V_2 -> V_64 = V_74 | V_159 |
V_160 | ( 15 << V_113 ) ;
V_2 -> V_50 = V_120 ;
F_3 ( V_2 , V_106 , V_2 -> V_64 ) ;
F_3 ( V_2 , V_53 , 0 ) ;
F_3 ( V_2 , V_57 , V_120 ) ;
V_97 = F_75 ( V_16 -> V_54 , F_17 , V_161 ,
V_162 , V_2 ) ;
if ( V_97 < 0 ) {
F_16 ( V_46 -> V_47 , L_14 , V_16 -> V_54 ) ;
goto V_158;
}
V_2 -> V_54 = V_16 -> V_54 ;
F_76 ( V_16 ) ;
F_77 ( V_2 -> V_54 ) ;
V_97 = F_78 ( V_46 , V_163 , V_2 , & V_155 ) ;
if ( V_97 < 0 )
goto V_158;
* V_153 = V_2 ;
return 0 ;
V_158:
F_57 ( V_2 ) ;
return V_97 ;
}
static int F_79 ( struct V_152 * V_16 )
{
int V_10 ;
const struct V_164 * V_165 ;
V_165 = F_80 ( V_166 , V_16 ) ;
if ( V_165 && V_165 -> V_167 > 0 )
return V_165 -> V_167 ;
for ( V_10 = 0 ; V_10 < F_81 ( V_168 ) ; ++ V_10 )
if ( V_168 [ V_10 ] . V_169 == V_16 -> V_170 &&
V_168 [ V_10 ] . V_171 == V_16 -> V_172 ) {
F_82 ( & V_16 -> V_47 ,
L_15 ,
V_16 -> V_101 , V_16 -> V_170 , V_16 -> V_172 ) ;
return - V_99 ;
}
F_83 ( & V_16 -> V_47 , L_16 ,
V_16 -> V_101 , V_16 -> V_170 , V_16 -> V_172 ) ;
F_83 ( & V_16 -> V_47 , L_17
L_18
L_19 ) ;
return V_173 ;
}
static int F_84 ( struct V_152 * V_16 ,
const struct V_164 * V_174 )
{
static int V_47 ;
struct V_151 * V_46 ;
struct V_1 * V_2 ;
int V_97 ;
enum V_175 V_176 ;
if ( ! V_174 -> V_167 ) {
V_97 = F_79 ( V_16 ) ;
if ( V_97 < 0 )
return - V_177 ;
V_176 = V_97 ;
} else
V_176 = V_174 -> V_167 ;
if ( V_47 >= V_178 )
return - V_177 ;
if ( ! V_179 [ V_47 ] ) {
++ V_47 ;
return - V_180 ;
}
V_97 = F_85 ( & V_16 -> V_47 , V_181 [ V_47 ] , V_182 [ V_47 ] , V_183 ,
0 , & V_46 ) ;
if ( V_97 < 0 )
return V_97 ;
V_97 = F_69 ( V_46 , V_16 , & V_2 ) ;
if ( V_97 < 0 )
goto V_103;
memcpy ( & V_2 -> V_78 , & V_184 [ V_176 ] , sizeof( V_2 -> V_78 ) ) ;
if ( ! V_2 -> V_78 . V_185 ) {
if ( V_186 [ V_47 ] > 0 )
V_2 -> V_78 . V_79 = V_186 [ V_47 ] ;
V_2 -> V_64 |= V_2 -> V_78 . V_187 ;
V_97 = F_64 ( V_2 , V_102 , L_20 ) ;
if ( V_97 < 0 )
goto V_103;
}
if ( ! V_2 -> V_78 . V_188 ) {
V_97 = F_64 ( V_2 , V_189 , L_21 ) ;
if ( V_97 < 0 )
goto V_103;
V_97 = F_86 ( V_46 , F_87 (
& V_190 , V_2 ) ) ;
if ( V_97 < 0 )
goto V_103;
V_97 = F_86 ( V_46 , F_87 (
& V_191 , V_2 ) ) ;
if ( V_97 < 0 )
goto V_103;
V_97 = F_86 ( V_46 , F_87 (
& V_192 , V_2 ) ) ;
if ( V_97 < 0 )
goto V_103;
}
F_83 ( V_46 -> V_47 , L_22
L_23 , V_47 , V_176 ,
V_2 -> V_78 . V_188 ? L_24 : L_25 ,
V_2 -> V_78 . V_185 ? L_24 : L_25 , V_2 -> V_78 . V_79 ) ;
strcpy ( V_46 -> V_193 , L_26 ) ;
sprintf ( V_46 -> V_194 , L_27 , V_16 -> V_101 ) ;
sprintf ( V_46 -> V_195 , L_28 ,
V_46 -> V_194 , ( unsigned long long ) F_88 ( V_16 , 0 ) ,
V_2 -> V_54 ) ;
strcpy ( V_46 -> V_196 , L_26 ) ;
V_97 = F_89 ( V_46 ) ;
if ( V_97 < 0 )
goto V_103;
F_90 ( V_16 , V_46 ) ;
++ V_47 ;
return 0 ;
V_103:
F_91 ( V_46 ) ;
return V_97 ;
}
static void F_92 ( struct V_152 * V_16 )
{
F_91 ( F_93 ( V_16 ) ) ;
}
static int T_5 F_94 ( void )
{
if ( V_197 )
V_193 . V_198 = V_199 ;
return F_95 ( & V_193 ) ;
}
static void T_6 F_96 ( void )
{
F_97 ( & V_193 ) ;
}
