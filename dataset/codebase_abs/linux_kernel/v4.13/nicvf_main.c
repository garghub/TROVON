static inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( V_2 -> V_4 )
return V_3 + ( ( V_2 -> V_5 + 1 ) * V_6 ) ;
else
return V_3 ;
}
void F_2 ( struct V_1 * V_2 , T_2 V_7 , T_2 V_8 )
{
F_3 ( V_8 , V_2 -> V_9 + V_7 ) ;
}
T_2 F_4 ( struct V_1 * V_2 , T_2 V_7 )
{
return F_5 ( V_2 -> V_9 + V_7 ) ;
}
void F_6 ( struct V_1 * V_2 , T_2 V_7 ,
T_2 V_3 , T_2 V_8 )
{
void T_3 * V_10 = V_2 -> V_9 + V_7 ;
F_3 ( V_8 , V_10 + ( V_3 << V_11 ) ) ;
}
T_2 F_7 ( struct V_1 * V_2 , T_2 V_7 , T_2 V_3 )
{
void T_3 * V_10 = V_2 -> V_9 + V_7 ;
return F_5 ( V_10 + ( V_3 << V_11 ) ) ;
}
static void F_8 ( struct V_1 * V_2 , union V_12 * V_13 )
{
T_2 * V_14 = ( T_2 * ) V_13 ;
F_2 ( V_2 , V_15 + 0 , V_14 [ 0 ] ) ;
F_2 ( V_2 , V_15 + 8 , V_14 [ 1 ] ) ;
}
int F_9 ( struct V_1 * V_2 , union V_12 * V_13 )
{
int V_16 = V_17 ;
int V_18 = 10 ;
V_2 -> V_19 = false ;
V_2 -> V_20 = false ;
F_8 ( V_2 , V_13 ) ;
while ( ! V_2 -> V_19 ) {
if ( V_2 -> V_20 ) {
F_10 ( V_2 -> V_21 ,
L_1 ,
( V_13 -> V_14 . V_14 & 0xFF ) , V_2 -> V_22 ) ;
return - V_23 ;
}
F_11 ( V_18 ) ;
if ( V_2 -> V_19 )
break;
V_16 -= V_18 ;
if ( ! V_16 ) {
F_10 ( V_2 -> V_21 ,
L_2 ,
( V_13 -> V_14 . V_14 & 0xFF ) , V_2 -> V_22 ) ;
return - V_24 ;
}
}
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
union V_12 V_13 = {} ;
V_13 . V_14 . V_14 = V_25 ;
if ( F_9 ( V_2 , & V_13 ) ) {
F_10 ( V_2 -> V_21 ,
L_3 ) ;
return 0 ;
}
return 1 ;
}
static void F_13 ( struct V_1 * V_2 , struct V_26 * V_27 )
{
if ( V_27 -> V_28 )
V_2 -> V_29 . V_30 [ V_27 -> V_31 ] = V_27 -> V_32 ;
else
V_2 -> V_29 . V_33 [ V_27 -> V_31 ] = V_27 -> V_32 ;
}
static void F_14 ( struct V_1 * V_2 )
{
union V_12 V_13 = {} ;
T_2 * V_34 ;
T_2 V_35 ;
int V_36 ;
V_35 = V_15 ;
V_34 = ( T_2 * ) & V_13 ;
for ( V_36 = 0 ; V_36 < V_37 ; V_36 ++ ) {
* V_34 = F_4 ( V_2 , V_35 ) ;
V_34 ++ ;
V_35 += sizeof( T_2 ) ;
}
F_15 ( V_2 -> V_21 , L_4 , V_13 . V_14 . V_14 ) ;
switch ( V_13 . V_14 . V_14 ) {
case V_25 :
V_2 -> V_19 = true ;
V_2 -> V_22 = V_13 . V_38 . V_22 & 0x7F ;
V_2 -> V_39 = V_13 . V_38 . V_39 & 0x7F ;
V_2 -> V_40 = V_13 . V_38 . V_41 ;
if ( ! V_2 -> V_42 )
F_16 ( V_2 -> V_21 -> V_43 ,
V_13 . V_38 . V_44 ) ;
V_2 -> V_4 = V_13 . V_38 . V_4 ;
V_2 -> V_45 = V_13 . V_38 . V_45 ;
V_2 -> V_46 = false ;
V_2 -> V_47 = 0 ;
V_2 -> V_48 = 0 ;
break;
case V_49 :
V_2 -> V_19 = true ;
break;
case V_50 :
V_2 -> V_20 = true ;
break;
case V_51 :
V_2 -> V_52 . V_53 = V_13 . V_53 . V_54 ;
V_2 -> V_19 = true ;
break;
case V_55 :
F_13 ( V_2 , & V_13 . V_29 ) ;
V_2 -> V_19 = true ;
break;
case V_56 :
V_2 -> V_19 = true ;
V_2 -> V_46 = V_13 . V_57 . V_46 ;
V_2 -> V_47 = V_13 . V_57 . V_47 ;
V_2 -> V_48 = V_13 . V_57 . V_48 ;
V_2 -> V_58 = V_13 . V_57 . V_58 ;
if ( V_2 -> V_46 ) {
F_17 ( V_2 -> V_21 , L_5 ,
V_2 -> V_48 ,
V_2 -> V_47 == V_59 ?
L_6 : L_7 ) ;
F_18 ( V_2 -> V_21 ) ;
F_19 ( V_2 -> V_21 ) ;
} else {
F_17 ( V_2 -> V_21 , L_8 ) ;
F_20 ( V_2 -> V_21 ) ;
F_21 ( V_2 -> V_21 ) ;
}
break;
case V_60 :
V_2 -> V_61 = V_13 . V_62 . V_63 ;
V_2 -> V_19 = true ;
break;
case V_64 :
V_2 -> V_65 [ V_13 . V_1 . V_5 ] =
(struct V_1 * ) V_13 . V_1 . V_1 ;
V_2 -> V_19 = true ;
break;
case V_66 :
V_2 -> V_67 = (struct V_1 * ) V_13 . V_1 . V_1 ;
V_2 -> V_19 = true ;
break;
case V_68 :
V_2 -> V_69 . V_70 = V_13 . V_69 . V_70 ;
V_2 -> V_69 . V_71 = V_13 . V_69 . V_71 ;
V_2 -> V_69 . V_72 = V_13 . V_69 . V_72 ;
V_2 -> V_19 = true ;
break;
default:
F_10 ( V_2 -> V_21 ,
L_9 , V_13 . V_14 . V_14 ) ;
break;
}
F_22 ( V_2 , V_73 , 0 ) ;
}
static int F_23 ( struct V_1 * V_2 , struct V_74 * V_21 )
{
union V_12 V_13 = {} ;
V_13 . V_75 . V_14 = V_76 ;
V_13 . V_75 . V_22 = V_2 -> V_22 ;
F_16 ( V_13 . V_75 . V_44 , V_21 -> V_43 ) ;
return F_9 ( V_2 , & V_13 ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
union V_12 V_13 = {} ;
V_13 . V_77 . V_14 = V_78 ;
V_13 . V_77 . V_22 = V_2 -> V_22 ;
V_13 . V_77 . V_79 = V_2 -> V_79 ;
V_13 . V_77 . V_80 = V_2 -> V_81 -> V_80 ;
F_9 ( V_2 , & V_13 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
union V_12 V_13 = {} ;
V_13 . V_53 . V_14 = V_51 ;
V_13 . V_53 . V_22 = V_2 -> V_22 ;
F_9 ( V_2 , & V_13 ) ;
}
void F_26 ( struct V_1 * V_2 )
{
union V_12 V_13 = {} ;
struct V_82 * V_83 = & V_2 -> V_52 ;
int V_84 = V_83 -> V_53 ;
int V_36 , V_85 = 0 ;
V_13 . V_86 . V_22 = V_2 -> V_22 ;
V_13 . V_86 . V_87 = V_83 -> V_87 ;
while ( V_84 ) {
V_13 . V_86 . V_88 = V_85 ;
V_13 . V_86 . V_89 = F_27 ( V_84 ,
V_90 ) ;
V_13 . V_86 . V_14 = V_13 . V_86 . V_88 ?
V_91 : V_92 ;
for ( V_36 = 0 ; V_36 < V_13 . V_86 . V_89 ; V_36 ++ )
V_13 . V_86 . V_93 [ V_36 ] = V_83 -> V_93 [ V_85 ++ ] ;
F_9 ( V_2 , & V_13 ) ;
V_84 -= V_13 . V_86 . V_89 ;
}
}
void F_28 ( struct V_1 * V_2 )
{
struct V_82 * V_83 = & V_2 -> V_52 ;
T_2 V_94 = V_95 ;
int V_31 ;
for ( V_31 = 0 ; V_31 < V_96 ; V_31 ++ ) {
F_2 ( V_2 , V_94 , V_83 -> V_97 [ V_31 ] ) ;
V_94 += sizeof( T_2 ) ;
}
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_82 * V_83 = & V_2 -> V_52 ;
int V_31 ;
F_25 ( V_2 ) ;
if ( V_79 != V_98 ) {
V_83 -> V_99 = false ;
V_83 -> V_87 = 0 ;
return 0 ;
}
V_83 -> V_99 = true ;
F_30 ( V_83 -> V_97 , V_96 * sizeof( T_2 ) ) ;
F_28 ( V_2 ) ;
V_83 -> V_100 = V_101 | V_102 | V_103 ;
F_2 ( V_2 , V_104 , V_83 -> V_100 ) ;
V_83 -> V_87 = F_31 ( F_32 ( V_83 -> V_53 ) ) ;
for ( V_31 = 0 ; V_31 < V_83 -> V_53 ; V_31 ++ )
V_83 -> V_93 [ V_31 ] = F_33 ( V_31 ,
V_2 -> V_105 ) ;
F_26 ( V_2 ) ;
return 1 ;
}
static void F_34 ( struct V_1 * V_2 )
{
union V_12 V_13 = {} ;
int V_106 ;
int V_61 = V_2 -> V_61 ;
int V_105 = 0 , V_107 = 0 ;
if ( V_2 -> V_4 || ! V_2 -> V_61 )
return;
V_13 . V_62 . V_14 = V_60 ;
V_13 . V_62 . V_22 = V_2 -> V_22 ;
V_13 . V_62 . V_63 = V_2 -> V_61 ;
if ( F_9 ( V_2 , & V_13 ) ) {
V_2 -> V_61 = 0 ;
return;
}
if ( ! V_2 -> V_61 )
return;
if ( V_2 -> V_105 > V_108 )
V_105 = V_2 -> V_105 - V_108 ;
V_107 = V_2 -> V_107 + V_2 -> V_109 ;
if ( V_107 > V_110 )
V_107 = V_107 - V_110 ;
for ( V_106 = 0 ; V_106 < V_2 -> V_61 ; V_106 ++ ) {
V_13 . V_1 . V_14 = V_64 ;
V_13 . V_1 . V_22 = V_2 -> V_22 ;
V_13 . V_1 . V_5 = V_106 ;
F_9 ( V_2 , & V_13 ) ;
V_2 -> V_65 [ V_106 ] -> V_5 = V_106 ;
if ( V_105 > V_108 ) {
V_2 -> V_65 [ V_106 ] -> V_81 -> V_80 = V_108 ;
V_105 -= V_108 ;
} else {
V_2 -> V_65 [ V_106 ] -> V_81 -> V_80 = V_105 ;
V_105 = 0 ;
}
if ( V_107 > V_110 ) {
V_2 -> V_65 [ V_106 ] -> V_81 -> V_111 = V_110 ;
V_107 -= V_110 ;
} else {
V_2 -> V_65 [ V_106 ] -> V_81 -> V_111 = V_107 ;
V_107 = 0 ;
}
V_2 -> V_65 [ V_106 ] -> V_81 -> V_112 =
F_35 ( V_2 -> V_65 [ V_106 ] -> V_81 -> V_80 , V_2 -> V_65 [ V_106 ] -> V_81 -> V_111 ) ;
F_36 ( V_2 -> V_65 [ V_106 ] -> V_21 ) ;
}
if ( V_61 != V_2 -> V_61 )
F_37 ( V_2 -> V_21 ,
V_2 -> V_107 , V_2 -> V_105 ) ;
}
static void F_38 ( struct V_1 * V_2 )
{
union V_12 V_13 = {} ;
V_13 . V_1 . V_14 = V_113 ;
V_13 . V_1 . V_4 = V_2 -> V_4 ;
V_13 . V_1 . V_1 = ( T_2 ) V_2 ;
F_9 ( V_2 , & V_13 ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
union V_12 V_13 = {} ;
V_13 . V_1 . V_14 = V_66 ;
F_9 ( V_2 , & V_13 ) ;
}
int F_37 ( struct V_74 * V_21 ,
int V_107 , int V_105 )
{
int V_114 = 0 ;
V_114 = F_40 ( V_21 , V_107 ) ;
if ( V_114 ) {
F_10 ( V_21 ,
L_10 , V_107 ) ;
return V_114 ;
}
V_114 = F_41 ( V_21 , V_105 ) ;
if ( V_114 )
F_10 ( V_21 ,
L_11 , V_105 ) ;
return V_114 ;
}
static int F_42 ( struct V_1 * V_2 )
{
int V_114 ;
F_43 ( V_2 , true ) ;
V_114 = F_44 ( V_2 , true ) ;
if ( V_114 ) {
F_10 ( V_2 -> V_21 ,
L_12 ) ;
return V_114 ;
}
return 0 ;
}
static inline bool F_45 ( struct V_1 * V_2 , struct V_115 * V_116 ,
struct V_117 * V_118 , struct V_119 * V_120 ,
struct V_121 * * V_122 )
{
struct V_123 V_124 ;
struct V_125 * V_125 ;
T_4 V_126 ;
T_5 V_127 , V_7 = 0 ;
T_2 V_128 , V_129 ;
void * V_130 ;
V_127 = * ( ( T_5 * ) ( ( void * ) V_118 + ( 3 * sizeof( T_2 ) ) ) ) ;
V_128 = * ( ( T_2 * ) ( ( void * ) V_118 + ( 7 * sizeof( T_2 ) ) ) ) ;
V_129 = F_46 ( V_2 , V_128 ) ;
if ( ! V_129 )
return false ;
V_129 = ( T_2 ) F_47 ( V_129 ) ;
V_125 = F_48 ( ( void * ) V_129 ) ;
V_124 . V_131 = F_49 ( V_125 ) ;
V_124 . V_132 = ( void * ) V_129 ;
V_124 . V_133 = V_124 . V_132 + V_127 ;
V_130 = V_124 . V_132 ;
F_50 () ;
V_126 = F_51 ( V_116 , & V_124 ) ;
F_52 () ;
if ( V_130 != V_124 . V_132 ) {
V_127 = V_124 . V_133 - V_124 . V_132 ;
V_7 = V_130 - V_124 . V_132 ;
V_128 -= V_7 ;
}
switch ( V_126 ) {
case V_134 :
if ( F_53 ( V_125 ) == 1 ) {
V_128 &= V_135 ;
F_54 ( & V_2 -> V_136 -> V_137 , V_128 ,
V_138 + V_139 ,
V_140 ,
V_141 ) ;
}
* V_122 = F_55 ( V_124 . V_132 ,
V_138 - V_118 -> V_142 + V_7 ) ;
if ( ! * V_122 )
F_56 ( V_125 ) ;
else
F_57 ( * V_122 , V_127 ) ;
return false ;
case V_143 :
F_58 ( V_2 , V_120 , ( T_2 ) V_124 . V_132 , V_128 , V_127 ) ;
return true ;
default:
F_59 ( V_126 ) ;
case V_144 :
F_60 ( V_2 -> V_21 , V_116 , V_126 ) ;
case V_145 :
if ( F_53 ( V_125 ) == 1 ) {
V_128 &= V_135 ;
F_54 ( & V_2 -> V_136 -> V_137 , V_128 ,
V_138 + V_139 ,
V_140 ,
V_141 ) ;
}
F_56 ( V_125 ) ;
return true ;
}
return false ;
}
static void F_61 ( struct V_74 * V_21 ,
struct V_146 * V_147 ,
int V_148 , int * V_149 ,
unsigned int * V_150 , unsigned int * V_151 )
{
struct V_121 * V_122 = NULL ;
struct V_125 * V_125 ;
struct V_1 * V_2 = F_62 ( V_21 ) ;
struct V_119 * V_120 ;
struct V_152 * V_153 ;
struct V_152 * V_154 ;
V_120 = & V_2 -> V_81 -> V_120 [ V_147 -> V_155 ] ;
V_153 = (struct V_152 * ) F_63 ( V_120 , V_147 -> V_156 ) ;
if ( V_153 -> V_157 != V_158 )
return;
if ( V_147 -> V_159 )
F_64 ( V_2 -> V_67 , V_147 ) ;
if ( V_120 -> V_160 ) {
V_125 = (struct V_125 * ) V_120 -> V_161 [ V_147 -> V_156 ] ;
if ( V_125 && ( F_53 ( V_125 ) == 1 ) )
F_65 ( V_2 , V_120 , V_147 -> V_156 ,
V_153 -> V_149 ) ;
if ( V_125 )
F_56 ( V_125 ) ;
V_120 -> V_161 [ V_147 -> V_156 ] = ( T_2 ) NULL ;
* V_149 += V_153 -> V_149 + 1 ;
return;
}
V_122 = (struct V_121 * ) V_120 -> V_162 [ V_147 -> V_156 ] ;
if ( V_122 ) {
if ( V_153 -> V_163 ) {
V_154 =
(struct V_152 * ) F_63 ( V_120 , V_153 -> V_164 ) ;
F_65 ( V_2 , V_120 , V_153 -> V_164 ,
V_154 -> V_149 ) ;
* V_149 += V_154 -> V_149 + 1 ;
} else {
F_65 ( V_2 , V_120 , V_147 -> V_156 ,
V_153 -> V_149 ) ;
}
* V_149 += V_153 -> V_149 + 1 ;
F_66 ( V_122 ) ;
( * V_150 ) ++ ;
* V_151 += V_122 -> V_127 ;
F_67 ( V_122 , V_148 ) ;
V_120 -> V_162 [ V_147 -> V_156 ] = ( T_2 ) NULL ;
} else {
if ( ! V_2 -> V_165 )
* V_149 += V_153 -> V_149 + 1 ;
}
}
static inline void F_68 ( struct V_74 * V_21 ,
struct V_117 * V_118 ,
struct V_121 * V_122 )
{
T_1 V_166 ;
T_4 V_167 ;
if ( ! ( V_21 -> V_168 & V_169 ) )
return;
switch ( V_118 -> V_170 ) {
case V_171 :
case V_172 :
V_166 = V_173 ;
V_167 = V_118 -> V_174 ;
break;
case V_175 :
V_166 = V_176 ;
V_167 = V_118 -> V_174 ;
break;
default:
V_166 = V_177 ;
V_167 = 0 ;
}
F_69 ( V_122 , V_167 , V_166 ) ;
}
static void F_70 ( struct V_74 * V_21 ,
struct V_178 * V_179 ,
struct V_117 * V_118 , struct V_119 * V_120 )
{
struct V_121 * V_122 = NULL ;
struct V_1 * V_2 = F_62 ( V_21 ) ;
struct V_1 * V_180 = V_2 ;
int V_114 = 0 ;
int V_181 ;
V_181 = F_1 ( V_2 , V_118 -> V_181 ) ;
if ( V_2 -> V_4 ) {
V_2 = V_2 -> V_67 ;
V_21 = V_2 -> V_21 ;
}
if ( V_118 -> V_182 || V_118 -> V_183 ) {
V_114 = F_71 ( V_2 , V_118 ) ;
if ( V_114 && ! V_118 -> V_184 )
return;
}
if ( V_2 -> V_185 && ( V_118 -> V_184 == 1 ) ) {
if ( F_45 ( V_180 , V_2 -> V_185 , V_118 , V_120 , & V_122 ) )
return;
} else {
V_122 = F_72 ( V_180 , V_118 ,
V_2 -> V_185 ? true : false ) ;
}
if ( ! V_122 )
return;
if ( F_73 ( V_2 ) ) {
F_17 ( V_2 -> V_21 , L_13 , V_122 , V_122 -> V_127 ) ;
F_74 ( V_186 , L_14 , V_187 , 16 , 1 ,
V_122 -> V_132 , V_122 -> V_127 , true ) ;
}
if ( V_114 ) {
F_75 ( V_122 ) ;
return;
}
F_68 ( V_21 , V_118 , V_122 ) ;
F_76 ( V_122 , V_181 ) ;
if ( V_21 -> V_188 & V_189 ) {
V_122 -> V_190 = V_191 ;
} else {
F_77 ( V_122 ) ;
}
V_122 -> V_192 = F_78 ( V_122 , V_21 ) ;
if ( V_118 -> V_193 && V_118 -> V_194 )
F_79 ( V_122 , F_80 ( V_195 ) ,
F_81 ( ( V_196 V_197 ) V_118 -> V_198 ) ) ;
if ( V_179 && ( V_21 -> V_168 & V_199 ) )
F_82 ( V_179 , V_122 ) ;
else
F_83 ( V_122 ) ;
}
static int F_84 ( struct V_74 * V_21 , T_1 V_200 ,
struct V_178 * V_179 , int V_148 )
{
int V_201 , V_202 = 0 , V_203 = 0 ;
int V_204 , V_205 ;
int V_149 = 0 ;
struct V_1 * V_2 = F_62 ( V_21 ) ;
struct V_206 * V_81 = V_2 -> V_81 ;
struct V_207 * V_208 = & V_81 -> V_208 [ V_200 ] ;
struct V_117 * V_209 ;
struct V_210 * V_211 ;
struct V_119 * V_120 = & V_81 -> V_120 [ V_200 ] ;
unsigned int V_150 = 0 , V_151 = 0 , V_212 ;
F_85 ( & V_208 -> V_213 ) ;
V_214:
V_201 = 0 ;
V_204 = F_7 ( V_2 , V_215 , V_200 ) ;
V_204 &= V_216 ;
if ( ! V_204 )
goto V_217;
V_205 = F_7 ( V_2 , V_218 , V_200 ) >> 9 ;
V_205 &= 0xFFFF ;
while ( V_201 < V_204 ) {
V_209 = (struct V_117 * ) F_86 ( V_208 , V_205 ) ;
V_205 ++ ;
V_205 &= ( V_208 -> V_219 . V_220 - 1 ) ;
F_66 ( (struct V_117 * ) F_86 ( V_208 , V_205 ) ) ;
if ( ( V_202 >= V_148 ) && V_179 &&
( V_209 -> V_221 != V_222 ) ) {
break;
}
switch ( V_209 -> V_221 ) {
case V_223 :
F_70 ( V_21 , V_179 , V_209 , V_120 ) ;
V_202 ++ ;
break;
case V_222 :
F_61 ( V_21 , ( void * ) V_209 ,
V_148 , & V_149 ,
& V_150 , & V_151 ) ;
V_203 ++ ;
break;
case V_224 :
case V_225 :
case V_226 :
case V_227 :
break;
}
V_201 ++ ;
}
F_6 ( V_2 , V_228 ,
V_200 , V_201 ) ;
if ( ( V_202 < V_148 ) && V_179 )
goto V_214;
V_217:
if ( V_149 )
F_87 ( V_120 , V_149 ) ;
V_212 = F_1 ( V_2 , V_200 ) ;
if ( V_2 -> V_67 -> V_185 ) {
if ( V_212 < V_2 -> V_67 -> V_109 ) {
F_88 ( V_2 , V_120 , V_200 ) ;
goto V_229;
}
V_2 = V_2 -> V_67 ;
V_212 -= V_2 -> V_67 -> V_109 ;
}
if ( V_203 ||
( F_89 ( & V_120 -> V_230 ) >= V_231 ) ) {
V_21 = V_2 -> V_67 -> V_21 ;
V_211 = F_90 ( V_21 , V_212 ) ;
if ( V_150 )
F_91 ( V_211 , V_150 , V_151 ) ;
F_92 () ;
if ( F_93 ( V_211 ) && F_94 ( V_21 ) ) {
F_95 ( V_211 ) ;
V_2 = V_2 -> V_67 ;
F_96 ( V_2 -> V_232 -> V_233 ) ;
F_97 ( V_2 , V_234 , V_21 ,
L_15 , V_212 ) ;
}
}
V_229:
F_98 ( & V_208 -> V_213 ) ;
return V_202 ;
}
static int F_99 ( struct V_178 * V_179 , int V_148 )
{
T_2 V_235 ;
int V_202 = 0 ;
struct V_74 * V_21 = V_179 -> V_137 ;
struct V_1 * V_2 = F_62 ( V_21 ) ;
struct V_236 * V_208 ;
V_208 = F_100 ( V_179 , struct V_236 , V_179 ) ;
V_202 = F_84 ( V_21 , V_208 -> V_200 , V_179 , V_148 ) ;
if ( V_202 < V_148 ) {
F_101 ( V_179 , V_202 ) ;
V_235 = F_7 ( V_2 , V_218 ,
V_208 -> V_200 ) ;
F_22 ( V_2 , V_237 , V_208 -> V_200 ) ;
F_6 ( V_2 , V_218 ,
V_208 -> V_200 , V_235 ) ;
F_102 ( V_2 , V_237 , V_208 -> V_200 ) ;
}
return V_202 ;
}
static void F_103 ( unsigned long V_132 )
{
struct V_1 * V_2 = (struct V_1 * ) V_132 ;
struct V_206 * V_81 = V_2 -> V_81 ;
int V_3 ;
T_2 V_238 ;
F_104 ( V_2 -> V_21 ) ;
for ( V_3 = 0 ; V_3 < V_81 -> V_112 ; V_3 ++ ) {
V_238 = F_7 ( V_2 , V_215 ,
V_3 ) ;
if ( ! ( V_238 & V_239 ) )
continue;
F_105 ( V_2 , V_237 , V_3 ) ;
F_106 ( V_2 , V_3 ) ;
F_84 ( V_2 -> V_21 , V_3 , NULL , 0 ) ;
F_107 ( V_2 , V_81 , V_3 , true ) ;
F_108 ( V_2 -> V_21 , & V_81 -> V_120 [ V_3 ] , V_3 ) ;
F_109 ( V_2 , & V_81 -> V_120 [ V_3 ] , V_3 ) ;
F_102 ( V_2 , V_237 , V_3 ) ;
}
F_19 ( V_2 -> V_21 ) ;
F_102 ( V_2 , V_240 , 0 ) ;
}
static void F_110 ( struct V_1 * V_2 )
{
F_111 ( V_2 , V_241 , V_2 -> V_21 , L_16 ,
F_4 ( V_2 , V_242 ) ) ;
}
static T_6 F_112 ( int V_243 , void * V_244 )
{
struct V_1 * V_2 = (struct V_1 * ) V_244 ;
T_2 V_241 ;
F_110 ( V_2 ) ;
V_241 = F_4 ( V_2 , V_242 ) ;
if ( ! ( V_241 & V_245 ) )
return V_246 ;
F_14 ( V_2 ) ;
return V_246 ;
}
static T_6 F_113 ( int V_243 , void * V_247 )
{
struct V_236 * V_248 = (struct V_236 * ) V_247 ;
struct V_1 * V_2 = V_248 -> V_1 ;
int V_3 = V_248 -> V_200 ;
F_110 ( V_2 ) ;
F_105 ( V_2 , V_237 , V_3 ) ;
F_114 ( & V_248 -> V_179 ) ;
F_22 ( V_2 , V_237 , V_3 ) ;
return V_246 ;
}
static T_6 F_115 ( int V_243 , void * V_244 )
{
struct V_1 * V_2 = (struct V_1 * ) V_244 ;
T_1 V_3 ;
F_110 ( V_2 ) ;
for ( V_3 = 0 ; V_3 < V_2 -> V_81 -> V_249 ; V_3 ++ ) {
if ( ! F_116 ( V_2 , V_250 , V_3 ) )
continue;
F_105 ( V_2 , V_250 , V_3 ) ;
F_117 ( & V_2 -> V_251 ) ;
F_22 ( V_2 , V_250 , V_3 ) ;
}
return V_246 ;
}
static T_6 F_118 ( int V_243 , void * V_244 )
{
struct V_1 * V_2 = (struct V_1 * ) V_244 ;
F_110 ( V_2 ) ;
F_105 ( V_2 , V_240 , 0 ) ;
F_117 ( & V_2 -> V_252 ) ;
F_22 ( V_2 , V_240 , 0 ) ;
return V_246 ;
}
static void F_119 ( struct V_1 * V_2 )
{
int V_253 , V_254 ;
for ( V_253 = 0 ; V_253 < V_2 -> V_255 ; V_253 ++ ) {
if ( ! V_2 -> V_256 [ V_253 ] )
continue;
if ( ! F_120 ( & V_2 -> V_257 [ V_253 ] , V_258 ) )
return;
if ( V_253 < V_259 )
V_254 = F_1 ( V_2 , V_253 ) + 1 ;
else
V_254 = 0 ;
F_121 ( F_122 ( V_254 , V_2 -> V_40 ) ,
V_2 -> V_257 [ V_253 ] ) ;
F_123 ( F_124 ( V_2 -> V_136 , V_253 ) ,
V_2 -> V_257 [ V_253 ] ) ;
}
}
static int F_125 ( struct V_1 * V_2 )
{
int V_243 , V_260 = 0 ;
F_126 (irq)
sprintf ( V_2 -> V_261 [ V_243 ] , L_17 ,
V_2 -> V_67 -> V_21 -> V_262 ,
F_1 ( V_2 , V_243 ) ) ;
F_127 (irq)
sprintf ( V_2 -> V_261 [ V_243 ] , L_18 ,
V_2 -> V_67 -> V_21 -> V_262 ,
F_1 ( V_2 , V_243 - V_259 ) ) ;
F_128 (irq)
sprintf ( V_2 -> V_261 [ V_243 ] , L_19 ,
V_2 -> V_67 -> V_21 -> V_262 ,
V_2 -> V_4 ? ( V_2 -> V_5 + 1 ) : 0 ) ;
for ( V_243 = 0 ; V_243 < V_2 -> V_81 -> V_112 ; V_243 ++ ) {
V_260 = F_129 ( F_124 ( V_2 -> V_136 , V_243 ) ,
F_113 ,
0 , V_2 -> V_261 [ V_243 ] , V_2 -> V_179 [ V_243 ] ) ;
if ( V_260 )
goto V_114;
V_2 -> V_256 [ V_243 ] = true ;
}
for ( V_243 = V_263 ;
V_243 < ( V_263 + V_2 -> V_81 -> V_249 ) ; V_243 ++ ) {
V_260 = F_129 ( F_124 ( V_2 -> V_136 , V_243 ) ,
F_115 ,
0 , V_2 -> V_261 [ V_243 ] , V_2 ) ;
if ( V_260 )
goto V_114;
V_2 -> V_256 [ V_243 ] = true ;
}
sprintf ( V_2 -> V_261 [ V_264 ] , L_20 ,
V_2 -> V_67 -> V_21 -> V_262 ,
V_2 -> V_4 ? ( V_2 -> V_5 + 1 ) : 0 ) ;
V_243 = V_264 ;
V_260 = F_129 ( F_124 ( V_2 -> V_136 , V_243 ) ,
F_118 ,
0 , V_2 -> V_261 [ V_243 ] , V_2 ) ;
if ( V_260 )
goto V_114;
V_2 -> V_256 [ V_243 ] = true ;
F_119 ( V_2 ) ;
V_114:
if ( V_260 )
F_10 ( V_2 -> V_21 , L_21 , V_243 ) ;
return V_260 ;
}
static void F_130 ( struct V_1 * V_2 )
{
struct V_265 * V_136 = V_2 -> V_136 ;
int V_243 ;
for ( V_243 = 0 ; V_243 < V_2 -> V_255 ; V_243 ++ ) {
if ( ! V_2 -> V_256 [ V_243 ] )
continue;
F_123 ( F_124 ( V_136 , V_243 ) , NULL ) ;
F_131 ( V_2 -> V_257 [ V_243 ] ) ;
if ( V_243 < V_259 )
F_132 ( F_124 ( V_136 , V_243 ) , V_2 -> V_179 [ V_243 ] ) ;
else
F_132 ( F_124 ( V_136 , V_243 ) , V_2 ) ;
V_2 -> V_256 [ V_243 ] = false ;
}
F_133 ( V_136 ) ;
V_2 -> V_255 = 0 ;
}
static int F_134 ( struct V_1 * V_2 )
{
int V_260 = 0 ;
int V_243 = V_266 ;
if ( V_2 -> V_136 -> V_267 )
return 0 ;
V_2 -> V_255 = F_135 ( V_2 -> V_136 ) ;
V_260 = F_136 ( V_2 -> V_136 , V_2 -> V_255 , V_2 -> V_255 ,
V_268 ) ;
if ( V_260 < 0 ) {
F_10 ( V_2 -> V_21 ,
L_22 , V_2 -> V_255 ) ;
return 1 ;
}
sprintf ( V_2 -> V_261 [ V_243 ] , L_23 , L_24 ) ;
V_260 = F_129 ( F_124 ( V_2 -> V_136 , V_243 ) ,
F_112 , 0 , V_2 -> V_261 [ V_243 ] , V_2 ) ;
if ( V_260 )
return V_260 ;
V_2 -> V_256 [ V_243 ] = true ;
F_102 ( V_2 , V_73 , 0 ) ;
if ( ! F_12 ( V_2 ) ) {
F_105 ( V_2 , V_73 , 0 ) ;
F_130 ( V_2 ) ;
return 1 ;
}
return 0 ;
}
static T_7 F_137 ( struct V_121 * V_122 , struct V_74 * V_21 )
{
struct V_1 * V_2 = F_62 ( V_21 ) ;
int V_269 = F_138 ( V_122 ) ;
struct V_210 * V_211 = F_90 ( V_21 , V_269 ) ;
struct V_1 * V_180 ;
struct V_119 * V_120 ;
int V_270 ;
if ( V_122 -> V_127 <= V_271 ) {
F_139 ( V_122 ) ;
return V_272 ;
}
if ( V_2 -> V_185 )
V_269 += V_2 -> V_109 ;
V_180 = V_2 ;
if ( V_269 >= V_110 ) {
V_270 = V_269 / V_110 ;
V_180 = (struct V_1 * ) V_2 -> V_65 [ V_270 - 1 ] ;
if ( ! V_180 ) {
F_140 ( V_2 -> V_21 ,
L_25 ,
V_270 - 1 ) ;
F_139 ( V_122 ) ;
return V_272 ;
}
V_269 = V_269 % V_110 ;
}
V_120 = & V_180 -> V_81 -> V_120 [ V_269 ] ;
if ( ! F_93 ( V_211 ) &&
! F_141 ( V_180 , V_120 , V_122 , V_269 ) ) {
F_142 ( V_211 ) ;
F_92 () ;
if ( F_89 ( & V_120 -> V_230 ) > V_231 ) {
F_95 ( V_211 ) ;
} else {
F_96 ( V_2 -> V_232 -> V_273 ) ;
F_97 ( V_2 , V_234 , V_21 ,
L_26 , V_269 ) ;
}
return V_274 ;
}
return V_272 ;
}
static inline void F_143 ( struct V_1 * V_2 )
{
struct V_236 * V_248 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_81 -> V_112 ; V_3 ++ ) {
V_248 = V_2 -> V_179 [ V_3 ] ;
if ( ! V_248 )
continue;
V_2 -> V_179 [ V_3 ] = NULL ;
F_144 ( V_248 ) ;
}
}
int F_145 ( struct V_74 * V_21 )
{
int V_243 , V_3 ;
struct V_1 * V_2 = F_62 ( V_21 ) ;
struct V_206 * V_81 = V_2 -> V_81 ;
struct V_236 * V_248 = NULL ;
union V_12 V_13 = {} ;
V_13 . V_14 . V_14 = V_275 ;
F_9 ( V_2 , & V_13 ) ;
F_20 ( V_21 ) ;
F_21 ( V_2 -> V_21 ) ;
V_2 -> V_46 = false ;
if ( ! V_2 -> V_4 ) {
for ( V_3 = 0 ; V_3 < V_2 -> V_61 ; V_3 ++ ) {
if ( ! V_2 -> V_65 [ V_3 ] )
continue;
F_145 ( V_2 -> V_65 [ V_3 ] -> V_21 ) ;
V_2 -> V_65 [ V_3 ] = NULL ;
}
}
for ( V_3 = 0 ; V_3 < V_81 -> V_249 ; V_3 ++ ) {
F_105 ( V_2 , V_250 , V_3 ) ;
F_22 ( V_2 , V_250 , V_3 ) ;
}
F_105 ( V_2 , V_240 , 0 ) ;
F_22 ( V_2 , V_240 , 0 ) ;
for ( V_243 = 0 ; V_243 < V_2 -> V_255 ; V_243 ++ )
F_146 ( F_124 ( V_2 -> V_136 , V_243 ) ) ;
F_147 ( & V_2 -> V_251 ) ;
F_147 ( & V_2 -> V_252 ) ;
if ( V_2 -> V_276 )
F_148 ( & V_2 -> V_277 ) ;
for ( V_3 = 0 ; V_3 < V_2 -> V_81 -> V_112 ; V_3 ++ ) {
V_248 = V_2 -> V_179 [ V_3 ] ;
if ( ! V_248 )
continue;
F_149 ( & V_248 -> V_179 ) ;
F_105 ( V_2 , V_237 , V_3 ) ;
F_22 ( V_2 , V_237 , V_3 ) ;
F_150 ( & V_248 -> V_179 ) ;
F_151 ( & V_248 -> V_179 ) ;
}
F_104 ( V_21 ) ;
for ( V_3 = 0 ; V_3 < V_21 -> V_278 ; V_3 ++ )
F_152 ( F_90 ( V_21 , V_3 ) ) ;
F_44 ( V_2 , false ) ;
F_43 ( V_2 , false ) ;
F_105 ( V_2 , V_73 , 0 ) ;
F_130 ( V_2 ) ;
F_143 ( V_2 ) ;
V_2 -> V_67 = V_2 ;
return 0 ;
}
static int F_153 ( struct V_1 * V_2 , int V_279 )
{
union V_12 V_13 = {} ;
V_13 . V_280 . V_14 = V_281 ;
V_13 . V_280 . V_282 = V_279 ;
V_13 . V_280 . V_22 = V_2 -> V_22 ;
return F_9 ( V_2 , & V_13 ) ;
}
int F_36 ( struct V_74 * V_21 )
{
int V_254 , V_114 , V_3 ;
struct V_1 * V_2 = F_62 ( V_21 ) ;
struct V_206 * V_81 = V_2 -> V_81 ;
struct V_236 * V_248 = NULL ;
union V_12 V_13 = {} ;
F_20 ( V_21 ) ;
V_114 = F_134 ( V_2 ) ;
if ( V_114 )
return V_114 ;
for ( V_3 = 0 ; V_3 < V_81 -> V_112 ; V_3 ++ ) {
V_248 = F_154 ( sizeof( * V_248 ) , V_258 ) ;
if ( ! V_248 ) {
V_114 = - V_283 ;
goto V_284;
}
V_248 -> V_200 = V_3 ;
V_248 -> V_1 = V_2 ;
F_155 ( V_21 , & V_248 -> V_179 , F_99 ,
V_285 ) ;
F_156 ( & V_248 -> V_179 ) ;
V_2 -> V_179 [ V_3 ] = V_248 ;
}
if ( ! V_2 -> V_4 && F_157 ( V_21 -> V_43 ) ) {
F_158 ( V_21 ) ;
F_23 ( V_2 , V_21 ) ;
}
if ( V_2 -> V_42 ) {
V_2 -> V_42 = false ;
F_23 ( V_2 , V_21 ) ;
}
F_159 ( & V_2 -> V_252 , F_103 ,
( unsigned long ) V_2 ) ;
F_159 ( & V_2 -> V_251 , V_286 ,
( unsigned long ) V_2 ) ;
F_160 ( & V_2 -> V_277 , V_287 ) ;
V_2 -> V_79 = V_79 ;
if ( ! V_2 -> V_4 )
F_24 ( V_2 ) ;
F_34 ( V_2 ) ;
if ( V_2 -> V_4 )
F_39 ( V_2 ) ;
if ( ! V_2 -> V_4 ) {
F_29 ( V_2 ) ;
V_114 = F_153 ( V_2 , V_21 -> V_279 ) ;
if ( V_114 )
goto V_288;
F_161 (cpu)
memset ( F_162 ( V_2 -> V_232 , V_254 ) , 0 ,
sizeof( struct V_289 ) ) ;
}
V_114 = F_125 ( V_2 ) ;
if ( V_114 )
goto V_288;
V_114 = F_42 ( V_2 ) ;
if ( V_114 )
goto V_288;
F_163 () ;
F_2 ( V_2 , V_242 , - 1 ) ;
F_102 ( V_2 , V_240 , 0 ) ;
for ( V_3 = 0 ; V_3 < V_81 -> V_112 ; V_3 ++ )
F_102 ( V_2 , V_237 , V_3 ) ;
for ( V_3 = 0 ; V_3 < V_81 -> V_249 ; V_3 ++ )
F_102 ( V_2 , V_250 , V_3 ) ;
V_13 . V_14 . V_14 = V_290 ;
F_8 ( V_2 , & V_13 ) ;
return 0 ;
V_288:
F_105 ( V_2 , V_73 , 0 ) ;
F_130 ( V_2 ) ;
F_147 ( & V_2 -> V_252 ) ;
F_147 ( & V_2 -> V_251 ) ;
V_284:
for ( V_3 = 0 ; V_3 < V_81 -> V_112 ; V_3 ++ ) {
V_248 = V_2 -> V_179 [ V_3 ] ;
if ( ! V_248 )
continue;
F_150 ( & V_248 -> V_179 ) ;
F_151 ( & V_248 -> V_179 ) ;
}
F_143 ( V_2 ) ;
return V_114 ;
}
static int F_164 ( struct V_74 * V_21 , int V_291 )
{
struct V_1 * V_2 = F_62 ( V_21 ) ;
int V_292 = V_21 -> V_279 ;
V_21 -> V_279 = V_291 ;
if ( ! F_165 ( V_21 ) )
return 0 ;
if ( F_153 ( V_2 , V_291 ) ) {
V_21 -> V_279 = V_292 ;
return - V_23 ;
}
return 0 ;
}
static int F_166 ( struct V_74 * V_21 , void * V_293 )
{
struct V_294 * V_10 = V_293 ;
struct V_1 * V_2 = F_62 ( V_21 ) ;
if ( ! F_167 ( V_10 -> V_295 ) )
return - V_296 ;
memcpy ( V_21 -> V_43 , V_10 -> V_295 , V_21 -> V_297 ) ;
if ( V_2 -> V_136 -> V_267 ) {
if ( F_23 ( V_2 , V_21 ) )
return - V_24 ;
} else {
V_2 -> V_42 = true ;
}
return 0 ;
}
void F_168 ( struct V_1 * V_2 )
{
int V_298 = 0 ;
union V_12 V_13 = {} ;
if ( ! F_165 ( V_2 -> V_21 ) )
return;
V_13 . V_29 . V_14 = V_55 ;
V_13 . V_29 . V_22 = V_2 -> V_22 ;
V_13 . V_29 . V_28 = 1 ;
while ( V_298 < V_299 ) {
V_13 . V_29 . V_31 = V_298 ;
if ( F_9 ( V_2 , & V_13 ) )
return;
V_298 ++ ;
}
V_298 = 0 ;
V_13 . V_29 . V_28 = 0 ;
while ( V_298 < V_300 ) {
V_13 . V_29 . V_31 = V_298 ;
if ( F_9 ( V_2 , & V_13 ) )
return;
V_298 ++ ;
}
}
void F_169 ( struct V_1 * V_2 )
{
int V_3 , V_254 ;
T_2 V_301 = 0 ;
struct V_302 * V_32 = & V_2 -> V_303 ;
struct V_289 * V_232 ;
struct V_206 * V_81 = V_2 -> V_81 ;
#define F_170 ( T_8 ) \
nicvf_reg_read(nic, NIC_VNIC_RX_STAT_0_13 | (reg << 3))
#define F_171 ( T_8 ) \
nicvf_reg_read(nic, NIC_VNIC_TX_STAT_0_4 | (reg << 3))
V_32 -> V_304 = F_170 ( V_305 ) ;
V_32 -> V_306 = F_170 ( V_307 ) ;
V_32 -> V_308 = F_170 ( V_309 ) ;
V_32 -> V_310 = F_170 ( V_311 ) ;
V_32 -> V_312 = F_170 ( V_313 ) ;
V_32 -> V_314 = F_170 ( V_315 ) ;
V_32 -> V_316 = F_170 ( V_317 ) ;
V_32 -> V_318 = F_170 ( V_319 ) ;
V_32 -> V_320 = F_170 ( V_321 ) ;
V_32 -> V_322 = F_170 ( V_323 ) ;
V_32 -> V_324 = F_170 ( V_325 ) ;
V_32 -> V_326 = F_170 ( V_327 ) ;
V_32 -> V_328 = F_170 ( V_329 ) ;
V_32 -> V_330 = F_170 ( V_331 ) ;
V_32 -> V_151 = F_171 ( V_332 ) ;
V_32 -> V_333 = F_171 ( V_334 ) ;
V_32 -> V_335 = F_171 ( V_336 ) ;
V_32 -> V_337 = F_171 ( V_338 ) ;
V_32 -> V_339 = F_171 ( V_340 ) ;
if ( V_2 -> V_341 && V_2 -> V_165 ) {
F_161 (cpu) {
V_232 = F_162 ( V_2 -> V_232 , V_254 ) ;
V_301 += V_232 -> V_342 ;
}
V_32 -> V_339 = V_301 - V_32 -> V_339 ;
}
V_32 -> V_343 = V_32 -> V_333 +
V_32 -> V_335 +
V_32 -> V_337 ;
V_32 -> V_344 = V_32 -> V_306 +
V_32 -> V_308 +
V_32 -> V_310 ;
V_32 -> V_345 = V_32 -> V_316 +
V_32 -> V_320 ;
for ( V_3 = 0 ; V_3 < V_81 -> V_80 ; V_3 ++ )
F_172 ( V_2 , V_3 ) ;
for ( V_3 = 0 ; V_3 < V_81 -> V_111 ; V_3 ++ )
F_173 ( V_2 , V_3 ) ;
}
static void F_174 ( struct V_74 * V_21 ,
struct V_346 * V_32 )
{
struct V_1 * V_2 = F_62 ( V_21 ) ;
struct V_302 * V_303 = & V_2 -> V_303 ;
F_169 ( V_2 ) ;
V_32 -> V_304 = V_303 -> V_304 ;
V_32 -> V_347 = V_303 -> V_344 ;
V_32 -> V_348 = V_303 -> V_345 ;
V_32 -> V_349 = V_303 -> V_310 ;
V_32 -> V_151 = V_303 -> V_151 ;
V_32 -> V_350 = V_303 -> V_343 ;
V_32 -> V_351 = V_303 -> V_339 ;
}
static void F_175 ( struct V_74 * V_137 )
{
struct V_1 * V_2 = F_62 ( V_137 ) ;
F_97 ( V_2 , V_234 , V_137 , L_27 ) ;
F_96 ( V_2 -> V_232 -> V_352 ) ;
F_176 ( & V_2 -> V_353 ) ;
}
static void F_177 ( struct V_354 * V_355 )
{
struct V_1 * V_2 ;
V_2 = F_100 ( V_355 , struct V_1 , V_353 ) ;
if ( ! F_165 ( V_2 -> V_21 ) )
return;
F_145 ( V_2 -> V_21 ) ;
F_36 ( V_2 -> V_21 ) ;
F_178 ( V_2 -> V_21 ) ;
}
static int F_179 ( struct V_1 * V_2 ,
T_9 V_168 )
{
union V_12 V_13 = {} ;
V_13 . V_356 . V_14 = V_357 ;
V_13 . V_356 . V_22 = V_2 -> V_22 ;
V_13 . V_356 . V_99 = ( V_168 & V_358 ) != 0 ;
return F_9 ( V_2 , & V_13 ) ;
}
static T_9 F_180 ( struct V_74 * V_21 ,
T_9 V_168 )
{
struct V_1 * V_2 = F_62 ( V_21 ) ;
if ( ( V_168 & V_358 ) &&
F_165 ( V_21 ) && ! V_2 -> V_45 )
V_168 &= ~ V_358 ;
return V_168 ;
}
static int F_181 ( struct V_74 * V_21 ,
T_9 V_168 )
{
struct V_1 * V_2 = F_62 ( V_21 ) ;
T_9 V_359 = V_168 ^ V_21 -> V_168 ;
if ( V_359 & V_360 )
F_182 ( V_2 , V_168 ) ;
if ( ( V_359 & V_358 ) && F_165 ( V_21 ) )
return F_179 ( V_2 , V_168 ) ;
return 0 ;
}
static void F_183 ( struct V_1 * V_2 , bool V_361 )
{
T_1 V_362 , V_363 ;
if ( ! V_361 )
V_2 -> V_109 = 0 ;
else
V_2 -> V_109 = V_2 -> V_105 ;
V_363 = V_2 -> V_109 + V_2 -> V_107 ;
V_362 = F_35 ( V_2 -> V_105 , V_363 ) ;
if ( V_362 > V_6 ) {
V_2 -> V_61 = F_184 ( V_362 , V_6 ) ;
V_2 -> V_61 = ( V_2 -> V_61 / V_6 ) - 1 ;
} else {
V_2 -> V_61 = 0 ;
}
V_2 -> V_81 -> V_80 = F_185 ( T_1 , V_2 -> V_105 , V_108 ) ;
V_2 -> V_81 -> V_111 = F_185 ( T_1 , V_363 , V_110 ) ;
V_2 -> V_81 -> V_112 = F_186 ( T_1 , V_2 -> V_81 -> V_80 , V_2 -> V_81 -> V_111 ) ;
F_37 ( V_2 -> V_21 , V_2 -> V_107 , V_2 -> V_105 ) ;
}
static int F_187 ( struct V_1 * V_2 , struct V_115 * V_116 )
{
struct V_74 * V_137 = V_2 -> V_21 ;
bool V_364 = F_165 ( V_2 -> V_21 ) ;
struct V_115 * V_365 ;
bool V_361 = false ;
if ( V_116 && ( V_137 -> V_279 > 1500 ) ) {
F_140 ( V_137 , L_28 ,
V_137 -> V_279 ) ;
return - V_366 ;
}
if ( ( V_2 -> V_105 + V_2 -> V_107 ) > V_2 -> V_367 ) {
F_140 ( V_137 ,
L_29 ,
V_2 -> V_367 ) ;
return - V_283 ;
}
if ( V_364 )
F_145 ( V_2 -> V_21 ) ;
V_365 = F_188 ( & V_2 -> V_185 , V_116 ) ;
if ( V_365 )
F_189 ( V_365 ) ;
if ( V_2 -> V_185 ) {
V_2 -> V_185 = F_190 ( V_2 -> V_185 , V_2 -> V_105 - 1 ) ;
if ( ! F_191 ( V_2 -> V_185 ) )
V_361 = true ;
}
F_183 ( V_2 , V_361 ) ;
if ( V_364 ) {
F_36 ( V_2 -> V_21 ) ;
F_178 ( V_2 -> V_21 ) ;
}
return 0 ;
}
static int F_192 ( struct V_74 * V_21 , struct V_368 * V_124 )
{
struct V_1 * V_2 = F_62 ( V_21 ) ;
if ( F_193 ( V_2 -> V_136 ) )
return - V_366 ;
switch ( V_124 -> V_369 ) {
case V_370 :
return F_187 ( V_2 , V_124 -> V_116 ) ;
case V_371 :
V_124 -> V_372 = ! ! V_2 -> V_185 ;
V_124 -> V_373 = V_2 -> V_185 ? V_2 -> V_185 -> V_374 -> V_375 : 0 ;
return 0 ;
default:
return - V_23 ;
}
}
static int F_194 ( struct V_265 * V_136 , const struct V_376 * V_377 )
{
struct V_378 * V_137 = & V_136 -> V_137 ;
struct V_74 * V_21 ;
struct V_1 * V_2 ;
int V_114 , V_379 ;
T_5 V_380 ;
V_114 = F_195 ( V_136 ) ;
if ( V_114 ) {
F_196 ( V_137 , L_30 ) ;
return V_114 ;
}
V_114 = F_197 ( V_136 , V_381 ) ;
if ( V_114 ) {
F_196 ( V_137 , L_31 , V_114 ) ;
goto V_382;
}
V_114 = F_198 ( V_136 , F_199 ( 48 ) ) ;
if ( V_114 ) {
F_196 ( V_137 , L_32 ) ;
goto V_383;
}
V_114 = F_200 ( V_136 , F_199 ( 48 ) ) ;
if ( V_114 ) {
F_196 ( V_137 , L_33 ) ;
goto V_383;
}
V_379 = F_201 () ;
if ( V_136 -> V_384 ) {
V_379 = F_185 ( int , F_202 () ,
( V_385 + 1 ) * V_6 ) ;
}
V_21 = F_203 ( sizeof( struct V_1 ) , V_379 , V_379 ) ;
if ( ! V_21 ) {
V_114 = - V_283 ;
goto V_383;
}
F_204 ( V_136 , V_21 ) ;
F_205 ( V_21 , & V_136 -> V_137 ) ;
V_2 = F_62 ( V_21 ) ;
V_2 -> V_21 = V_21 ;
V_2 -> V_136 = V_136 ;
V_2 -> V_67 = V_2 ;
V_2 -> V_367 = V_379 ;
V_2 -> V_9 = F_206 ( V_136 , V_386 , 0 ) ;
if ( ! V_2 -> V_9 ) {
F_196 ( V_137 , L_34 ) ;
V_114 = - V_283 ;
goto V_387;
}
V_2 -> V_232 = F_207 ( struct V_289 ) ;
if ( ! V_2 -> V_232 ) {
V_114 = - V_283 ;
goto V_387;
}
V_114 = F_208 ( V_2 ) ;
if ( V_114 )
goto V_387;
V_114 = F_134 ( V_2 ) ;
if ( V_114 )
goto V_387;
F_38 ( V_2 ) ;
if ( ! F_193 ( V_2 -> V_136 ) )
V_2 -> V_165 = true ;
V_2 -> V_388 = F_209 ( V_137 ) ;
F_210 ( V_2 -> V_136 , V_389 , & V_380 ) ;
if ( V_380 == 0xA134 )
V_2 -> V_341 = true ;
if ( V_2 -> V_4 )
return 0 ;
V_114 = F_37 ( V_21 , V_2 -> V_107 , V_2 -> V_105 ) ;
if ( V_114 )
goto V_390;
V_21 -> V_188 = ( V_189 | V_391 |
V_392 | V_199 | V_393 |
V_394 | V_395 |
V_360 ) ;
V_21 -> V_188 |= V_169 ;
V_21 -> V_168 |= V_21 -> V_188 ;
V_21 -> V_188 |= V_358 ;
V_21 -> V_396 = V_391 | V_394 |
V_395 | V_392 | V_393 ;
V_21 -> V_397 = & V_398 ;
V_21 -> V_399 = V_400 ;
V_21 -> V_401 = V_402 ;
V_21 -> V_403 = V_404 ;
F_211 ( & V_2 -> V_353 , F_177 ) ;
V_114 = F_212 ( V_21 ) ;
if ( V_114 ) {
F_196 ( V_137 , L_35 ) ;
goto V_390;
}
V_2 -> V_405 = V_406 ;
F_213 ( V_21 ) ;
return 0 ;
V_390:
F_130 ( V_2 ) ;
V_387:
F_204 ( V_136 , NULL ) ;
if ( V_2 -> V_232 )
F_214 ( V_2 -> V_232 ) ;
F_215 ( V_21 ) ;
V_383:
F_216 ( V_136 ) ;
V_382:
F_217 ( V_136 ) ;
return V_114 ;
}
static void F_218 ( struct V_265 * V_136 )
{
struct V_74 * V_21 = F_219 ( V_136 ) ;
struct V_1 * V_2 ;
struct V_74 * V_407 ;
if ( ! V_21 )
return;
V_2 = F_62 ( V_21 ) ;
V_407 = V_2 -> V_67 -> V_21 ;
if ( V_407 && ( V_407 -> V_408 == V_409 ) )
F_220 ( V_407 ) ;
F_130 ( V_2 ) ;
F_204 ( V_136 , NULL ) ;
if ( V_2 -> V_232 )
F_214 ( V_2 -> V_232 ) ;
F_215 ( V_21 ) ;
F_216 ( V_136 ) ;
F_217 ( V_136 ) ;
}
static void F_221 ( struct V_265 * V_136 )
{
F_218 ( V_136 ) ;
}
static int T_10 F_222 ( void )
{
F_223 ( L_36 , V_381 , V_410 ) ;
return F_224 ( & V_411 ) ;
}
static void T_11 F_225 ( void )
{
F_226 ( & V_411 ) ;
}
