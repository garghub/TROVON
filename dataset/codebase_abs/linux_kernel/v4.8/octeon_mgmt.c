static void F_1 ( struct V_1 * V_2 , int V_3 )
{
union V_4 V_5 ;
unsigned long V_6 ;
F_2 ( & V_2 -> V_7 , V_6 ) ;
V_5 . V_8 = F_3 ( V_2 -> V_9 + V_10 ) ;
V_5 . V_11 . V_12 = V_3 ? 1 : 0 ;
F_4 ( V_2 -> V_9 + V_10 , V_5 . V_8 ) ;
F_5 ( & V_2 -> V_7 , V_6 ) ;
}
static void F_6 ( struct V_1 * V_2 , int V_3 )
{
union V_4 V_5 ;
unsigned long V_6 ;
F_2 ( & V_2 -> V_7 , V_6 ) ;
V_5 . V_8 = F_3 ( V_2 -> V_9 + V_10 ) ;
V_5 . V_11 . V_13 = V_3 ? 1 : 0 ;
F_4 ( V_2 -> V_9 + V_10 , V_5 . V_8 ) ;
F_5 ( & V_2 -> V_7 , V_6 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
F_1 ( V_2 , 1 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
F_1 ( V_2 , 0 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
F_6 ( V_2 , 1 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
F_6 ( V_2 , 0 ) ;
}
static unsigned int F_11 ( unsigned int V_14 )
{
return V_14 - 8 ;
}
static unsigned int F_12 ( unsigned int V_14 )
{
return V_14 * sizeof( union V_15 ) ;
}
static void F_13 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_14 ( V_17 ) ;
while ( V_2 -> V_18 < F_11 ( V_19 ) ) {
unsigned int V_20 ;
union V_15 V_21 ;
struct V_22 * V_23 ;
V_20 = V_17 -> V_24 + V_25 + 8 + V_26 ;
V_23 = F_15 ( V_17 , V_20 ) ;
if ( ! V_23 )
break;
F_16 ( V_23 , V_26 ) ;
F_17 ( & V_2 -> V_27 , V_23 ) ;
V_21 . V_28 = 0 ;
V_21 . V_11 . V_29 = V_20 ;
V_21 . V_11 . V_30 = F_18 ( V_2 -> V_31 , V_23 -> V_32 ,
V_20 ,
V_33 ) ;
V_2 -> V_34 [ V_2 -> V_35 ] = V_21 . V_28 ;
F_19 ( V_2 -> V_31 , V_2 -> V_36 ,
F_12 ( V_19 ) ,
V_37 ) ;
V_2 -> V_35 =
( V_2 -> V_35 + 1 ) % V_19 ;
V_2 -> V_18 ++ ;
F_4 ( V_2 -> V_9 + V_38 , 1 ) ;
}
}
static void F_20 ( struct V_1 * V_2 )
{
union V_39 V_40 ;
union V_15 V_21 ;
struct V_22 * V_23 ;
int V_41 = 0 ;
unsigned long V_6 ;
V_40 . V_8 = F_3 ( V_2 -> V_9 + V_42 ) ;
while ( V_40 . V_11 . V_43 ) {
F_2 ( & V_2 -> V_44 . V_7 , V_6 ) ;
V_40 . V_8 = F_3 ( V_2 -> V_9 + V_42 ) ;
if ( V_40 . V_11 . V_43 == 0 ) {
F_5 ( & V_2 -> V_44 . V_7 , V_6 ) ;
break;
}
F_21 ( V_2 -> V_31 , V_2 -> V_45 ,
F_12 ( V_46 ) ,
V_37 ) ;
V_21 . V_28 = V_2 -> V_47 [ V_2 -> V_48 ] ;
V_2 -> V_48 =
( V_2 -> V_48 + 1 ) % V_46 ;
V_23 = F_22 ( & V_2 -> V_44 ) ;
V_40 . V_8 = 0 ;
V_40 . V_11 . V_43 = 1 ;
F_4 ( V_2 -> V_9 + V_42 , V_40 . V_8 ) ;
V_2 -> V_49 -- ;
F_5 ( & V_2 -> V_44 . V_7 , V_6 ) ;
F_23 ( V_2 -> V_31 , V_21 . V_11 . V_30 , V_21 . V_11 . V_29 ,
V_50 ) ;
if ( F_24 ( V_21 . V_11 . V_51 ) ) {
struct V_52 V_53 ;
V_8 V_54 ;
memset ( & V_53 , 0 , sizeof( V_53 ) ) ;
V_54 = F_3 ( F_25 ( V_2 -> V_55 ) ) ;
F_4 ( F_26 ( V_2 -> V_55 ) , 0 ) ;
V_53 . V_56 = F_27 ( V_54 ) ;
F_28 ( V_23 , & V_53 ) ;
}
F_29 ( V_23 ) ;
V_41 ++ ;
V_40 . V_8 = F_3 ( V_2 -> V_9 + V_42 ) ;
}
if ( V_41 && F_30 ( V_2 -> V_17 ) )
F_31 ( V_2 -> V_17 ) ;
}
static void F_32 ( unsigned long V_57 )
{
struct V_1 * V_2 = (struct V_1 * ) V_57 ;
F_20 ( V_2 ) ;
F_9 ( V_2 ) ;
}
static void F_33 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_14 ( V_17 ) ;
unsigned long V_6 ;
V_8 V_58 , V_59 ;
V_58 = F_3 ( V_2 -> V_60 + V_61 ) ;
V_59 = F_3 ( V_2 -> V_60 + V_62 ) ;
if ( V_58 || V_59 ) {
F_2 ( & V_2 -> V_7 , V_6 ) ;
V_17 -> V_63 . V_64 += V_59 ;
V_17 -> V_63 . V_65 += V_58 ;
F_5 ( & V_2 -> V_7 , V_6 ) ;
}
}
static void F_34 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_14 ( V_17 ) ;
unsigned long V_6 ;
union V_66 V_67 ;
union V_68 V_69 ;
V_67 . V_8 = F_3 ( V_2 -> V_60 + V_70 ) ;
V_69 . V_8 = F_3 ( V_2 -> V_60 + V_71 ) ;
if ( V_67 . V_11 . V_72 || V_67 . V_11 . V_73 || V_69 . V_11 . V_74 || V_69 . V_11 . V_75 ) {
F_2 ( & V_2 -> V_7 , V_6 ) ;
V_17 -> V_63 . V_76 += V_67 . V_11 . V_72 + V_67 . V_11 . V_73 ;
V_17 -> V_63 . V_77 += V_69 . V_11 . V_74 + V_69 . V_11 . V_75 ;
F_5 ( & V_2 -> V_7 , V_6 ) ;
}
}
static V_8 F_35 ( struct V_1 * V_2 ,
struct V_22 * * V_78 )
{
union V_15 V_21 ;
F_21 ( V_2 -> V_31 , V_2 -> V_36 ,
F_12 ( V_19 ) ,
V_37 ) ;
V_21 . V_28 = V_2 -> V_34 [ V_2 -> V_79 ] ;
V_2 -> V_79 = ( V_2 -> V_79 + 1 ) % V_19 ;
V_2 -> V_18 -- ;
* V_78 = F_22 ( & V_2 -> V_27 ) ;
F_23 ( V_2 -> V_31 , V_21 . V_11 . V_30 ,
V_80 + V_25 ,
V_33 ) ;
return V_21 . V_28 ;
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = V_2 -> V_17 ;
union V_81 V_82 ;
union V_15 V_21 ;
struct V_22 * V_23 ;
struct V_22 * V_83 ;
struct V_22 * V_84 ;
union V_15 V_85 ;
int V_86 = 1 ;
V_21 . V_28 = F_35 ( V_2 , & V_23 ) ;
if ( F_37 ( V_21 . V_11 . V_87 == V_88 ) ) {
F_38 ( V_23 , V_21 . V_11 . V_29 ) ;
V_89:
if ( V_2 -> V_90 ) {
V_8 V_54 = * ( V_8 * ) V_23 -> V_32 ;
struct V_52 * V_53 ;
V_53 = F_39 ( V_23 ) ;
V_53 -> V_56 = F_27 ( V_54 ) ;
F_40 ( V_23 , 8 ) ;
}
V_23 -> V_91 = F_41 ( V_23 , V_17 ) ;
V_17 -> V_63 . V_92 ++ ;
V_17 -> V_63 . V_93 += V_23 -> V_29 ;
F_42 ( V_23 ) ;
V_86 = 0 ;
} else if ( V_21 . V_11 . V_87 == V_94 ) {
F_38 ( V_23 , V_21 . V_11 . V_29 ) ;
do {
V_85 . V_28 = F_35 ( V_2 , & V_83 ) ;
if ( V_85 . V_11 . V_87 != V_94
&& V_85 . V_11 . V_87 != V_88 )
goto V_95;
F_38 ( V_83 , V_85 . V_11 . V_29 ) ;
V_84 = F_43 ( V_23 , 0 , V_83 -> V_29 ,
V_96 ) ;
if ( ! V_84 )
goto V_95;
if ( F_44 ( V_83 , 0 , F_45 ( V_84 ) ,
V_83 -> V_29 ) )
goto V_95;
F_38 ( V_84 , V_83 -> V_29 ) ;
F_29 ( V_23 ) ;
F_29 ( V_83 ) ;
V_23 = V_84 ;
} while ( V_85 . V_11 . V_87 == V_94 );
goto V_89;
} else {
F_29 ( V_23 ) ;
}
goto V_97;
V_95:
F_29 ( V_23 ) ;
F_29 ( V_83 ) ;
while ( V_85 . V_11 . V_87 == V_94 ) {
V_85 . V_28 = F_35 ( V_2 , & V_83 ) ;
F_29 ( V_83 ) ;
}
V_17 -> V_63 . V_64 ++ ;
V_97:
V_82 . V_8 = 0 ;
V_82 . V_11 . V_98 = 1 ;
F_4 ( V_2 -> V_9 + V_99 , V_82 . V_8 ) ;
return V_86 ;
}
static int F_46 ( struct V_1 * V_2 , int V_100 )
{
unsigned int V_101 = 0 ;
union V_81 V_82 ;
int V_86 ;
V_82 . V_8 = F_3 ( V_2 -> V_9 + V_99 ) ;
while ( V_101 < V_100 && V_82 . V_11 . V_98 ) {
V_86 = F_36 ( V_2 ) ;
if ( ! V_86 )
V_101 ++ ;
V_82 . V_8 = F_3 ( V_2 -> V_9 + V_99 ) ;
}
F_13 ( V_2 -> V_17 ) ;
return V_101 ;
}
static int F_47 ( struct V_102 * V_103 , int V_100 )
{
struct V_1 * V_2 = F_48 ( V_103 , struct V_1 , V_103 ) ;
struct V_16 * V_17 = V_2 -> V_17 ;
unsigned int V_101 = 0 ;
V_101 = F_46 ( V_2 , V_100 ) ;
if ( V_101 < V_100 ) {
F_49 ( V_103 ) ;
F_7 ( V_2 ) ;
}
F_33 ( V_17 ) ;
return V_101 ;
}
static void F_50 ( struct V_1 * V_2 )
{
union V_104 V_105 ;
union V_106 V_107 ;
union V_108 V_109 ;
V_105 . V_8 = 0 ;
F_4 ( V_2 -> V_9 + V_110 , V_105 . V_8 ) ;
do {
V_105 . V_8 = F_3 ( V_2 -> V_9 + V_110 ) ;
} while ( V_105 . V_11 . V_111 );
V_105 . V_11 . V_112 = 1 ;
F_4 ( V_2 -> V_9 + V_110 , V_105 . V_8 ) ;
F_3 ( V_2 -> V_9 + V_110 ) ;
F_51 ( 64 ) ;
V_107 . V_8 = F_3 ( V_2 -> V_9 + V_113 ) ;
if ( V_107 . V_8 )
F_52 ( V_2 -> V_31 , L_1 ,
( unsigned long long ) V_107 . V_8 ) ;
V_109 . V_8 = F_3 ( V_114 ) ;
if ( V_109 . V_8 )
F_52 ( V_2 -> V_31 , L_2 ,
( unsigned long long ) V_109 . V_8 ) ;
}
static void F_53 ( struct V_115 * V_116 ,
unsigned char * V_30 )
{
int V_117 ;
for ( V_117 = 0 ; V_117 < 6 ; V_117 ++ )
V_116 -> V_118 [ V_117 ] |= ( V_8 ) V_30 [ V_117 ] << ( 8 * ( V_116 -> V_119 ) ) ;
V_116 -> V_120 |= ( 1ULL << V_116 -> V_119 ) ;
V_116 -> V_119 ++ ;
}
static void F_54 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_14 ( V_17 ) ;
union V_121 V_122 ;
union V_123 V_124 ;
unsigned long V_6 ;
unsigned int V_125 ;
unsigned int V_126 = 1 ;
unsigned int V_127 = 1 ;
struct V_115 V_128 ;
struct V_129 * V_130 ;
int V_131 ;
memset ( & V_128 , 0 , sizeof( V_128 ) ) ;
if ( ( V_17 -> V_6 & V_132 ) || V_17 -> V_133 . V_134 > 7 ) {
V_126 = 0 ;
V_131 = 8 ;
} else {
V_131 = 7 - V_17 -> V_133 . V_134 ;
}
if ( V_17 -> V_6 & V_135 ) {
if ( V_126 == 0 || ( V_17 -> V_6 & V_136 ) ||
F_55 ( V_17 ) > V_131 )
V_127 = 2 ;
else
V_127 = 0 ;
}
if ( V_126 == 1 ) {
F_53 ( & V_128 , V_17 -> V_137 ) ;
F_56 (ha, netdev)
F_53 ( & V_128 , V_130 -> V_30 ) ;
}
if ( V_127 == 0 ) {
F_57 (ha, netdev)
F_53 ( & V_128 , V_130 -> V_30 ) ;
}
F_2 ( & V_2 -> V_7 , V_6 ) ;
V_124 . V_8 = F_3 ( V_2 -> V_60 + V_138 ) ;
V_125 = V_124 . V_11 . V_139 ;
V_124 . V_11 . V_139 = 0 ;
F_4 ( V_2 -> V_60 + V_138 , V_124 . V_8 ) ;
V_122 . V_8 = 0 ;
V_122 . V_11 . V_126 = V_126 ;
V_122 . V_11 . V_140 = V_127 ;
V_122 . V_11 . V_141 = 1 ;
F_4 ( V_2 -> V_60 + V_142 , V_122 . V_8 ) ;
F_4 ( V_2 -> V_60 + V_143 , V_128 . V_118 [ 0 ] ) ;
F_4 ( V_2 -> V_60 + V_144 , V_128 . V_118 [ 1 ] ) ;
F_4 ( V_2 -> V_60 + V_145 , V_128 . V_118 [ 2 ] ) ;
F_4 ( V_2 -> V_60 + V_146 , V_128 . V_118 [ 3 ] ) ;
F_4 ( V_2 -> V_60 + V_147 , V_128 . V_118 [ 4 ] ) ;
F_4 ( V_2 -> V_60 + V_148 , V_128 . V_118 [ 5 ] ) ;
F_4 ( V_2 -> V_60 + V_149 , V_128 . V_120 ) ;
V_124 . V_11 . V_139 = V_125 ;
F_4 ( V_2 -> V_60 + V_138 , V_124 . V_8 ) ;
F_5 ( & V_2 -> V_7 , V_6 ) ;
}
static int F_58 ( struct V_16 * V_17 , void * V_30 )
{
int V_150 = F_59 ( V_17 , V_30 ) ;
if ( V_150 )
return V_150 ;
F_54 ( V_17 ) ;
return 0 ;
}
static int F_60 ( struct V_16 * V_17 , int V_151 )
{
struct V_1 * V_2 = F_14 ( V_17 ) ;
int V_152 = V_151 + V_25 ;
if ( V_152 < 64 || V_152 > 16383 ) {
F_52 ( V_2 -> V_31 , L_3 ,
64 - V_25 ,
16383 - V_25 ) ;
return - V_153 ;
}
V_17 -> V_24 = V_151 ;
F_4 ( V_2 -> V_60 + V_154 , V_152 ) ;
F_4 ( V_2 -> V_60 + V_155 ,
( V_152 + 7 ) & 0xfff8 ) ;
return 0 ;
}
static T_1 F_61 ( int V_156 , void * V_157 )
{
struct V_16 * V_17 = V_157 ;
struct V_1 * V_2 = F_14 ( V_17 ) ;
union V_158 V_159 ;
V_159 . V_8 = F_3 ( V_2 -> V_9 + V_160 ) ;
F_4 ( V_2 -> V_9 + V_160 , V_159 . V_8 ) ;
F_3 ( V_2 -> V_9 + V_160 ) ;
if ( V_159 . V_11 . V_161 ) {
F_8 ( V_2 ) ;
F_62 ( & V_2 -> V_103 ) ;
}
if ( V_159 . V_11 . V_162 ) {
F_10 ( V_2 ) ;
F_63 ( & V_2 -> V_163 ) ;
}
return V_164 ;
}
static int F_64 ( struct V_16 * V_17 ,
struct V_165 * V_166 , int V_167 )
{
struct V_1 * V_2 = F_14 ( V_17 ) ;
struct V_168 V_169 ;
union V_170 V_171 ;
union V_172 V_173 ;
bool V_174 = false ;
if ( F_65 ( & V_169 , V_166 -> V_175 , sizeof( V_169 ) ) )
return - V_176 ;
if ( V_169 . V_6 )
return - V_153 ;
if ( F_66 ( V_177 ) ) {
V_171 . V_8 = F_3 ( V_178 ) ;
if ( ! V_171 . V_11 . V_179 ) {
V_8 V_180 = ( V_181 << 32 ) / F_67 () ;
if ( ! V_171 . V_11 . V_182 )
F_4 ( V_183 , V_180 ) ;
F_68 ( L_4 ,
( V_181 << 32 ) / V_180 ) ;
} else {
V_8 V_180 = F_3 ( V_183 ) ;
F_68 ( L_5 ,
V_171 . V_11 . V_184 ,
( V_181 << 32 ) / V_180 ) ;
}
if ( ! V_171 . V_11 . V_182 ) {
V_171 . V_11 . V_182 = 1 ;
F_4 ( V_178 , V_171 . V_8 ) ;
}
V_174 = true ;
}
if ( ! V_174 )
return - V_153 ;
switch ( V_169 . V_185 ) {
case V_186 :
case V_187 :
break;
default:
return - V_188 ;
}
switch ( V_169 . V_189 ) {
case V_190 :
V_2 -> V_90 = false ;
V_173 . V_8 = F_3 ( V_2 -> V_60 + V_191 ) ;
V_173 . V_11 . V_192 = 0 ;
F_4 ( V_2 -> V_60 + V_191 , V_173 . V_8 ) ;
break;
case V_193 :
case V_194 :
case V_195 :
case V_196 :
case V_197 :
case V_198 :
case V_199 :
case V_200 :
case V_201 :
case V_202 :
case V_203 :
case V_204 :
case V_205 :
case V_206 :
V_2 -> V_90 = V_174 ;
V_169 . V_189 = V_193 ;
if ( V_2 -> V_90 ) {
V_173 . V_8 = F_3 ( V_2 -> V_60 + V_191 ) ;
V_173 . V_11 . V_192 = 1 ;
F_4 ( V_2 -> V_60 + V_191 , V_173 . V_8 ) ;
}
break;
default:
return - V_188 ;
}
if ( F_69 ( V_166 -> V_175 , & V_169 , sizeof( V_169 ) ) )
return - V_176 ;
return 0 ;
}
static int F_70 ( struct V_16 * V_17 ,
struct V_165 * V_166 , int V_167 )
{
switch ( V_167 ) {
case V_207 :
return F_64 ( V_17 , V_166 , V_167 ) ;
default:
if ( V_17 -> V_208 )
return F_71 ( V_17 -> V_208 , V_166 , V_167 ) ;
return - V_153 ;
}
}
static void F_72 ( struct V_1 * V_2 )
{
union V_123 V_209 ;
V_209 . V_8 = F_3 ( V_2 -> V_60 + V_138 ) ;
V_209 . V_11 . V_139 = 0 ;
V_209 . V_11 . V_210 = 0 ;
V_209 . V_11 . V_211 = 0 ;
F_4 ( V_2 -> V_60 + V_138 , V_209 . V_8 ) ;
if ( F_66 ( V_177 ) ) {
int V_117 ;
for ( V_117 = 0 ; V_117 < 10 ; V_117 ++ ) {
V_209 . V_8 = F_3 ( V_2 -> V_60 + V_138 ) ;
if ( V_209 . V_11 . V_212 == 1 || V_209 . V_11 . V_213 == 1 )
break;
F_73 ( 1 ) ;
V_117 ++ ;
}
}
}
static void F_74 ( struct V_1 * V_2 )
{
union V_123 V_209 ;
V_209 . V_8 = F_3 ( V_2 -> V_60 + V_138 ) ;
V_209 . V_11 . V_210 = 1 ;
V_209 . V_11 . V_211 = 1 ;
V_209 . V_11 . V_139 = 1 ;
F_4 ( V_2 -> V_60 + V_138 , V_209 . V_8 ) ;
}
static void F_75 ( struct V_1 * V_2 )
{
struct V_16 * V_214 = V_2 -> V_17 ;
struct V_215 * V_208 = V_214 -> V_208 ;
union V_123 V_209 ;
V_209 . V_8 = F_3 ( V_2 -> V_60 + V_138 ) ;
if ( ! V_208 -> V_216 )
V_209 . V_11 . V_217 = 1 ;
else
V_209 . V_11 . V_217 = V_208 -> V_217 ;
switch ( V_208 -> V_218 ) {
case 10 :
V_209 . V_11 . V_218 = 0 ;
V_209 . V_11 . V_219 = 0 ;
if ( F_66 ( V_177 ) ) {
V_209 . V_11 . V_220 = 1 ;
V_209 . V_11 . V_221 = 1 ;
}
break;
case 100 :
V_209 . V_11 . V_218 = 0 ;
V_209 . V_11 . V_219 = 0 ;
if ( F_66 ( V_177 ) ) {
V_209 . V_11 . V_220 = 1 ;
V_209 . V_11 . V_221 = 0 ;
}
break;
case 1000 :
if ( F_66 ( V_177 ) ) {
V_209 . V_11 . V_218 = 1 ;
V_209 . V_11 . V_221 = 0 ;
V_209 . V_11 . V_219 = 1 ;
V_209 . V_11 . V_220 = V_208 -> V_217 ;
}
break;
case 0 :
default:
break;
}
F_4 ( V_2 -> V_60 + V_138 , V_209 . V_8 ) ;
V_209 . V_8 = F_3 ( V_2 -> V_60 + V_138 ) ;
if ( F_66 ( V_177 ) ) {
union V_222 V_223 ;
union V_224 V_225 ;
V_225 . V_8 = F_3 ( V_2 -> V_226 ) ;
V_223 . V_8 = F_3 ( V_2 -> V_60 + V_227 ) ;
V_223 . V_11 . V_228 = 1 ;
if ( V_225 . V_11 . V_229 == 0 ) {
if ( V_208 -> V_218 == 10 )
V_223 . V_11 . V_228 = 50 ;
else if ( V_208 -> V_218 == 100 )
V_223 . V_11 . V_228 = 5 ;
}
F_4 ( V_2 -> V_60 + V_227 , V_223 . V_8 ) ;
}
}
static void F_76 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_14 ( V_17 ) ;
struct V_215 * V_208 = V_17 -> V_208 ;
unsigned long V_6 ;
int V_230 = 0 ;
if ( ! V_208 )
return;
F_2 ( & V_2 -> V_7 , V_6 ) ;
if ( ! V_208 -> V_216 && V_2 -> V_231 )
V_230 = - 1 ;
if ( V_208 -> V_216 &&
( V_2 -> V_232 != V_208 -> V_217 ||
V_2 -> V_231 != V_208 -> V_216 ||
V_2 -> V_233 != V_208 -> V_218 ) ) {
F_72 ( V_2 ) ;
V_230 = 1 ;
F_75 ( V_2 ) ;
F_74 ( V_2 ) ;
}
V_2 -> V_231 = V_208 -> V_216 ;
V_2 -> V_233 = V_208 -> V_218 ;
V_2 -> V_232 = V_208 -> V_217 ;
F_5 ( & V_2 -> V_7 , V_6 ) ;
if ( V_230 != 0 ) {
if ( V_230 > 0 ) {
F_68 ( L_6 , V_17 -> V_234 ,
V_208 -> V_218 ,
V_208 -> V_217 == V_235 ?
L_7 : L_8 ) ;
} else {
F_68 ( L_9 , V_17 -> V_234 ) ;
}
}
}
static int F_77 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_14 ( V_17 ) ;
struct V_215 * V_208 = NULL ;
if ( F_78 () || V_2 -> V_236 == NULL ) {
F_79 ( V_17 ) ;
return 0 ;
}
V_208 = F_80 ( V_17 , V_2 -> V_236 ,
F_76 , 0 ,
V_237 ) ;
if ( ! V_208 )
return - V_238 ;
return 0 ;
}
static int F_81 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_14 ( V_17 ) ;
union V_104 V_105 ;
union V_239 V_240 ;
union V_241 V_242 ;
union V_243 V_244 ;
union V_172 V_173 ;
union V_245 V_246 ;
union V_247 V_248 ;
union V_4 V_5 ;
struct V_249 V_250 ;
V_2 -> V_47 = F_82 ( F_12 ( V_46 ) ,
V_251 ) ;
if ( ! V_2 -> V_47 )
return - V_252 ;
V_2 -> V_45 =
F_18 ( V_2 -> V_31 , V_2 -> V_47 ,
F_12 ( V_46 ) ,
V_37 ) ;
V_2 -> V_253 = 0 ;
V_2 -> V_48 = 0 ;
V_2 -> V_49 = 0 ;
V_2 -> V_34 = F_82 ( F_12 ( V_19 ) ,
V_251 ) ;
if ( ! V_2 -> V_34 )
goto V_254;
V_2 -> V_36 =
F_18 ( V_2 -> V_31 , V_2 -> V_34 ,
F_12 ( V_19 ) ,
V_37 ) ;
V_2 -> V_79 = 0 ;
V_2 -> V_35 = 0 ;
V_2 -> V_18 = 0 ;
F_50 ( V_2 ) ;
V_105 . V_8 = F_3 ( V_2 -> V_9 + V_110 ) ;
if ( V_105 . V_11 . V_112 ) {
V_105 . V_11 . V_112 = 0 ;
F_4 ( V_2 -> V_9 + V_110 , V_105 . V_8 ) ;
do {
V_105 . V_8 = F_3 ( V_2 -> V_9 + V_110 ) ;
} while ( V_105 . V_11 . V_112 );
}
if ( F_66 ( V_255 ) ) {
V_240 . V_8 = 0 ;
V_240 . V_11 . V_139 = 1 ;
F_4 ( V_256 , V_240 . V_8 ) ;
}
if ( F_66 ( V_257 )
|| F_66 ( V_258 ) ) {
union V_259 V_260 ;
V_260 . V_8 = F_3 ( V_261 ) ;
if ( V_2 -> V_55 ) {
V_260 . V_11 . V_262 = 1 ;
V_260 . V_11 . V_263 = 6 ;
V_260 . V_11 . V_264 = 6 ;
} else {
V_260 . V_11 . V_265 = 1 ;
V_260 . V_11 . V_266 = 6 ;
V_260 . V_11 . V_267 = 6 ;
}
F_4 ( V_261 , V_260 . V_8 ) ;
}
V_242 . V_8 = 0 ;
V_242 . V_11 . V_268 = V_2 -> V_45 >> 3 ;
V_242 . V_11 . V_269 = V_46 ;
F_4 ( V_2 -> V_9 + V_270 , V_242 . V_8 ) ;
V_244 . V_8 = 0 ;
V_244 . V_11 . V_271 = V_2 -> V_36 >> 3 ;
V_244 . V_11 . V_272 = V_19 ;
F_4 ( V_2 -> V_9 + V_273 , V_244 . V_8 ) ;
memcpy ( V_250 . V_274 , V_17 -> V_137 , V_275 ) ;
F_58 ( V_17 , & V_250 ) ;
F_60 ( V_17 , V_17 -> V_24 ) ;
V_105 . V_8 = 0 ;
V_105 . V_11 . V_276 = 1 ;
V_105 . V_11 . V_139 = 1 ;
V_105 . V_11 . V_277 = 0 ;
V_105 . V_11 . V_278 = 1 ;
#ifdef F_83
V_105 . V_11 . V_279 = 1 ;
#endif
F_4 ( V_2 -> V_9 + V_110 , V_105 . V_8 ) ;
if ( F_77 ( V_17 ) ) {
F_84 ( V_2 -> V_31 , L_10 , V_2 -> V_55 ) ;
goto V_280;
}
if ( F_66 ( V_177 ) && V_17 -> V_208 ) {
union V_224 V_281 ;
int V_282 = ( V_17 -> V_208 -> V_283 &
( V_284 | V_285 ) ) != 0 ;
V_281 . V_8 = F_3 ( V_2 -> V_226 ) ;
V_281 . V_11 . V_229 = V_282 ? 0 : 1 ;
F_4 ( V_2 -> V_226 , V_281 . V_8 ) ;
#define F_85 8
V_281 . V_8 = F_3 ( V_2 -> V_226 ) ;
V_281 . V_11 . V_286 = 0 ;
if ( V_282 ) {
V_281 . V_11 . V_287 = 0 ;
V_281 . V_11 . V_288 = 0 ;
}
F_4 ( V_2 -> V_226 , V_281 . V_8 ) ;
F_3 ( V_2 -> V_226 ) ;
F_86 ( 256 * F_85 ) ;
V_281 . V_8 = F_3 ( V_2 -> V_226 ) ;
V_281 . V_11 . V_3 = 1 ;
F_4 ( V_2 -> V_226 , V_281 . V_8 ) ;
V_281 . V_8 = F_3 ( V_2 -> V_226 ) ;
V_281 . V_11 . V_289 = 1 ;
V_281 . V_11 . V_290 = 0 ;
F_4 ( V_2 -> V_226 , V_281 . V_8 ) ;
F_3 ( V_2 -> V_226 ) ;
F_86 ( 1040 * F_85 ) ;
F_4 ( V_291 , 0xae ) ;
}
F_13 ( V_17 ) ;
F_4 ( V_2 -> V_60 + V_292 , 1 ) ;
F_4 ( V_2 -> V_60 + V_61 , 0 ) ;
F_4 ( V_2 -> V_60 + V_62 , 0 ) ;
F_4 ( V_2 -> V_60 + V_293 , 1 ) ;
F_4 ( V_2 -> V_60 + V_70 , 0 ) ;
F_4 ( V_2 -> V_60 + V_71 , 0 ) ;
F_4 ( V_2 -> V_9 + V_160 , F_3 ( V_2 -> V_9 + V_160 ) ) ;
if ( F_87 ( V_2 -> V_294 , F_61 , 0 , V_17 -> V_234 ,
V_17 ) ) {
F_84 ( V_2 -> V_31 , L_11 , V_2 -> V_294 ) ;
goto V_280;
}
V_246 . V_8 = 0 ;
V_246 . V_11 . V_295 = 0 ;
F_4 ( V_2 -> V_9 + V_296 , V_246 . V_8 ) ;
V_248 . V_8 = 0 ;
V_248 . V_11 . V_297 = 0 ;
F_4 ( V_2 -> V_9 + V_298 , V_248 . V_8 ) ;
V_5 . V_8 = 0 ;
V_5 . V_11 . V_12 = 1 ;
V_5 . V_11 . V_13 = 1 ;
F_4 ( V_2 -> V_9 + V_10 , V_5 . V_8 ) ;
V_173 . V_8 = 0 ;
V_173 . V_11 . V_192 = V_2 -> V_90 ? 1 : 0 ;
V_173 . V_11 . V_299 = 1 ;
V_173 . V_11 . V_300 = 1 ;
V_173 . V_11 . V_301 = 1 ;
V_173 . V_11 . V_302 = 1 ;
V_173 . V_11 . V_303 = 0 ;
V_173 . V_11 . V_304 = 1 ;
V_173 . V_11 . V_305 = 1 ;
V_173 . V_11 . V_306 = 1 ;
V_173 . V_11 . V_307 = 1 ;
V_173 . V_11 . V_308 = 1 ;
F_4 ( V_2 -> V_60 + V_191 , V_173 . V_8 ) ;
F_72 ( V_2 ) ;
if ( V_17 -> V_208 )
F_75 ( V_2 ) ;
F_74 ( V_2 ) ;
V_2 -> V_231 = 0 ;
V_2 -> V_233 = 0 ;
if ( V_17 -> V_208 ) {
F_88 ( V_17 ) ;
F_89 ( V_17 -> V_208 ) ;
}
F_31 ( V_17 ) ;
F_90 ( & V_2 -> V_103 ) ;
return 0 ;
V_280:
F_50 ( V_2 ) ;
F_23 ( V_2 -> V_31 , V_2 -> V_36 ,
F_12 ( V_19 ) ,
V_37 ) ;
F_91 ( V_2 -> V_34 ) ;
V_254:
F_23 ( V_2 -> V_31 , V_2 -> V_45 ,
F_12 ( V_46 ) ,
V_37 ) ;
F_91 ( V_2 -> V_47 ) ;
return - V_252 ;
}
static int F_92 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_14 ( V_17 ) ;
F_93 ( & V_2 -> V_103 ) ;
F_94 ( V_17 ) ;
if ( V_17 -> V_208 )
F_95 ( V_17 -> V_208 ) ;
F_88 ( V_17 ) ;
F_50 ( V_2 ) ;
F_96 ( V_2 -> V_294 , V_17 ) ;
F_97 ( & V_2 -> V_44 ) ;
F_97 ( & V_2 -> V_27 ) ;
F_23 ( V_2 -> V_31 , V_2 -> V_36 ,
F_12 ( V_19 ) ,
V_37 ) ;
F_91 ( V_2 -> V_34 ) ;
F_23 ( V_2 -> V_31 , V_2 -> V_45 ,
F_12 ( V_46 ) ,
V_37 ) ;
F_91 ( V_2 -> V_47 ) ;
return 0 ;
}
static int F_98 ( struct V_22 * V_23 , struct V_16 * V_17 )
{
struct V_1 * V_2 = F_14 ( V_17 ) ;
union V_15 V_21 ;
unsigned long V_6 ;
int V_309 = V_310 ;
V_21 . V_28 = 0 ;
V_21 . V_11 . V_51 = ( ( F_99 ( V_23 ) -> V_311 & V_312 ) != 0 ) ;
V_21 . V_11 . V_29 = V_23 -> V_29 ;
V_21 . V_11 . V_30 = F_18 ( V_2 -> V_31 , V_23 -> V_32 ,
V_23 -> V_29 ,
V_50 ) ;
F_2 ( & V_2 -> V_44 . V_7 , V_6 ) ;
if ( F_24 ( V_2 -> V_49 >= F_11 ( V_46 ) - 1 ) ) {
F_5 ( & V_2 -> V_44 . V_7 , V_6 ) ;
F_94 ( V_17 ) ;
F_2 ( & V_2 -> V_44 . V_7 , V_6 ) ;
}
if ( F_24 ( V_2 -> V_49 >=
F_11 ( V_46 ) ) ) {
F_5 ( & V_2 -> V_44 . V_7 , V_6 ) ;
F_23 ( V_2 -> V_31 , V_21 . V_11 . V_30 , V_21 . V_11 . V_29 ,
V_50 ) ;
goto V_313;
}
F_17 ( & V_2 -> V_44 , V_23 ) ;
V_2 -> V_47 [ V_2 -> V_253 ] = V_21 . V_28 ;
V_2 -> V_253 = ( V_2 -> V_253 + 1 ) % V_46 ;
V_2 -> V_49 ++ ;
F_5 ( & V_2 -> V_44 . V_7 , V_6 ) ;
F_19 ( V_2 -> V_31 , V_2 -> V_45 ,
F_12 ( V_46 ) ,
V_37 ) ;
V_17 -> V_63 . V_314 ++ ;
V_17 -> V_63 . V_315 += V_23 -> V_29 ;
F_4 ( V_2 -> V_9 + V_316 , 1 ) ;
F_100 ( V_17 ) ;
V_309 = V_317 ;
V_313:
F_34 ( V_17 ) ;
return V_309 ;
}
static void F_101 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_14 ( V_17 ) ;
F_46 ( V_2 , 16 ) ;
F_33 ( V_17 ) ;
}
static void F_102 ( struct V_16 * V_17 ,
struct V_318 * V_319 )
{
F_103 ( V_319 -> V_320 , V_321 , sizeof( V_319 -> V_320 ) ) ;
F_103 ( V_319 -> V_322 , V_323 , sizeof( V_319 -> V_322 ) ) ;
F_103 ( V_319 -> V_324 , L_12 , sizeof( V_319 -> V_324 ) ) ;
F_103 ( V_319 -> V_325 , L_12 , sizeof( V_319 -> V_325 ) ) ;
}
static int F_104 ( struct V_16 * V_31 )
{
if ( ! F_105 ( V_326 ) )
return - V_327 ;
if ( V_31 -> V_208 )
return F_89 ( V_31 -> V_208 ) ;
return - V_328 ;
}
static int F_106 ( struct V_329 * V_330 )
{
struct V_16 * V_17 ;
struct V_1 * V_2 ;
const T_2 * V_32 ;
const T_3 * V_331 ;
struct V_332 * V_333 ;
struct V_332 * V_334 ;
struct V_332 * V_335 ;
int V_29 ;
int V_336 ;
V_17 = F_107 ( sizeof( struct V_1 ) ) ;
if ( V_17 == NULL )
return - V_252 ;
F_108 ( V_17 , & V_330 -> V_31 ) ;
F_109 ( V_330 , V_17 ) ;
V_2 = F_14 ( V_17 ) ;
F_110 ( V_17 , & V_2 -> V_103 , F_47 ,
V_337 ) ;
V_2 -> V_17 = V_17 ;
V_2 -> V_31 = & V_330 -> V_31 ;
V_2 -> V_90 = false ;
V_32 = F_111 ( V_330 -> V_31 . V_338 , L_13 , & V_29 ) ;
if ( V_32 && V_29 == sizeof( * V_32 ) ) {
V_2 -> V_55 = F_112 ( V_32 ) ;
} else {
F_84 ( & V_330 -> V_31 , L_14 ) ;
V_336 = - V_339 ;
goto V_340;
}
snprintf ( V_17 -> V_234 , V_341 , L_15 , V_2 -> V_55 ) ;
V_336 = F_113 ( V_330 , 0 ) ;
if ( V_336 < 0 )
goto V_340;
V_2 -> V_294 = V_336 ;
V_333 = F_114 ( V_330 , V_342 , 0 ) ;
if ( V_333 == NULL ) {
F_84 ( & V_330 -> V_31 , L_16 ) ;
V_336 = - V_339 ;
goto V_340;
}
V_334 = F_114 ( V_330 , V_342 , 1 ) ;
if ( V_334 == NULL ) {
F_84 ( & V_330 -> V_31 , L_16 ) ;
V_336 = - V_339 ;
goto V_340;
}
V_335 = F_114 ( V_330 , V_342 , 3 ) ;
if ( V_335 == NULL ) {
F_84 ( & V_330 -> V_31 , L_16 ) ;
V_336 = - V_339 ;
goto V_340;
}
V_2 -> V_343 = V_333 -> V_344 ;
V_2 -> V_345 = F_115 ( V_333 ) ;
V_2 -> V_346 = V_334 -> V_344 ;
V_2 -> V_347 = F_115 ( V_334 ) ;
V_2 -> V_348 = V_335 -> V_344 ;
V_2 -> V_349 = F_115 ( V_335 ) ;
if ( ! F_116 ( & V_330 -> V_31 , V_2 -> V_343 , V_2 -> V_345 ,
V_333 -> V_234 ) ) {
F_84 ( & V_330 -> V_31 , L_17 ,
V_333 -> V_234 ) ;
V_336 = - V_339 ;
goto V_340;
}
if ( ! F_116 ( & V_330 -> V_31 , V_2 -> V_346 , V_2 -> V_347 ,
V_334 -> V_234 ) ) {
V_336 = - V_339 ;
F_84 ( & V_330 -> V_31 , L_17 ,
V_334 -> V_234 ) ;
goto V_340;
}
if ( ! F_116 ( & V_330 -> V_31 , V_2 -> V_348 ,
V_2 -> V_349 , V_335 -> V_234 ) ) {
V_336 = - V_339 ;
F_84 ( & V_330 -> V_31 , L_17 ,
V_335 -> V_234 ) ;
goto V_340;
}
V_2 -> V_9 = ( V_8 ) F_117 ( & V_330 -> V_31 , V_2 -> V_343 , V_2 -> V_345 ) ;
V_2 -> V_60 = ( V_8 ) F_117 ( & V_330 -> V_31 , V_2 -> V_346 , V_2 -> V_347 ) ;
V_2 -> V_226 = ( V_8 ) F_117 ( & V_330 -> V_31 , V_2 -> V_348 ,
V_2 -> V_349 ) ;
F_118 ( & V_2 -> V_7 ) ;
F_119 ( & V_2 -> V_44 ) ;
F_119 ( & V_2 -> V_27 ) ;
F_120 ( & V_2 -> V_163 ,
F_32 , ( unsigned long ) V_2 ) ;
V_17 -> V_350 |= V_351 ;
V_17 -> V_352 = & V_353 ;
V_17 -> V_354 = & V_355 ;
V_331 = F_121 ( V_330 -> V_31 . V_338 ) ;
if ( V_331 )
memcpy ( V_17 -> V_137 , V_331 , V_275 ) ;
else
F_122 ( V_17 ) ;
V_2 -> V_236 = F_123 ( V_330 -> V_31 . V_338 , L_18 , 0 ) ;
V_336 = F_124 ( & V_330 -> V_31 , F_125 ( 64 ) ) ;
if ( V_336 )
goto V_340;
F_88 ( V_17 ) ;
V_336 = F_126 ( V_17 ) ;
if ( V_336 )
goto V_340;
F_127 ( & V_330 -> V_31 , L_19 V_323 L_20 ) ;
return 0 ;
V_340:
F_128 ( V_2 -> V_236 ) ;
F_129 ( V_17 ) ;
return V_336 ;
}
static int F_130 ( struct V_329 * V_330 )
{
struct V_16 * V_17 = F_131 ( V_330 ) ;
struct V_1 * V_2 = F_14 ( V_17 ) ;
F_132 ( V_17 ) ;
F_128 ( V_2 -> V_236 ) ;
F_129 ( V_17 ) ;
return 0 ;
}
static int T_4 F_133 ( void )
{
F_134 () ;
return F_135 ( & V_356 ) ;
}
static void T_5 F_136 ( void )
{
F_137 ( & V_356 ) ;
}
