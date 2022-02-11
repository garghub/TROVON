static void F_1 ( struct V_1 * V_2 , int V_3 )
{
unsigned long V_4 ;
F_2 ( & V_2 -> V_5 . V_6 , V_4 ) ;
V_2 -> V_5 . V_7 += V_3 ;
F_3 ( & V_2 -> V_5 . V_6 , V_4 ) ;
}
static int F_4 ( struct V_8 * V_9 ,
struct V_10 * V_11 ,
T_1 V_12 )
{
struct V_13 * V_14 = V_9 -> V_15 ;
struct V_1 * V_2 = V_14 -> V_16 ;
struct V_17 * V_18 ;
int V_19 , V_20 ;
if ( V_9 -> V_21 == V_22 )
return 0 ;
if ( V_9 -> V_23 == 0 ) {
void * V_24 = V_9 -> V_25 ;
T_2 V_26 = F_5 ( V_2 -> V_27 , V_24 ,
V_9 -> V_28 ,
V_9 -> V_21 ) ;
V_11 [ 0 ] . V_29 = F_6 ( ( V_30 ) V_26 ) ;
V_11 [ 0 ] . V_31 = F_7 ( V_9 -> V_28 ) ;
V_11 [ 0 ] . V_4 |= V_32 ;
return 0 ;
}
if ( F_8 ( V_9 -> V_33 ) )
V_19 = V_9 -> V_23 ;
else
V_19 = F_9 ( V_2 -> V_27 , V_9 -> V_25 ,
V_9 -> V_23 , V_9 -> V_21 ) ;
if ( V_19 == 0 )
return - V_34 ;
if ( V_19 > 3 ) {
int V_35 ;
V_14 -> V_11 = F_10 ( V_2 ,
V_19 * sizeof( struct V_10 ) ,
V_12 ) ;
if ( ! V_14 -> V_11 ) {
V_20 = - V_34 ;
goto V_36;
}
F_11 (task->scatter, sc, num_sg, i) {
struct V_10 * V_37 =
& ( (struct V_10 * ) V_14 -> V_11 -> V_38 ) [ V_35 ] ;
V_37 -> V_29 = F_6 ( ( V_30 ) F_12 ( V_18 ) ) ;
V_37 -> V_31 = F_7 ( ( V_39 ) F_13 ( V_18 ) ) ;
if ( V_35 == V_19 - 1 )
V_37 -> V_4 |= V_32 ;
}
F_11 (task->scatter, sc, 2 , i) {
V_11 [ V_35 ] . V_29 =
F_6 ( ( V_30 ) F_12 ( V_18 ) ) ;
V_11 [ V_35 ] . V_31 = F_7 ( ( V_39 ) F_13 ( V_18 ) ) ;
}
V_11 [ 1 ] . V_40 = 2 * sizeof( * V_11 ) ;
V_11 [ 1 ] . V_4 |= V_41 ;
memset ( & V_11 [ 2 ] , 0 , sizeof( * V_11 ) ) ;
V_11 [ 2 ] . V_29 = F_6 ( ( V_30 ) V_14 -> V_11 -> V_42 ) ;
} else {
int V_35 ;
F_11 (task->scatter, sc, num_sg, i) {
V_11 [ V_35 ] . V_29 =
F_6 ( ( V_30 ) F_12 ( V_18 ) ) ;
V_11 [ V_35 ] . V_31 = F_7 ( ( V_39 ) F_13 ( V_18 ) ) ;
}
V_11 [ V_35 - 1 ] . V_4 |= V_32 ;
}
return 0 ;
V_36:
if ( F_8 ( V_9 -> V_33 ) )
F_14 ( V_2 -> V_27 , V_9 -> V_25 , V_9 -> V_23 ,
V_9 -> V_21 ) ;
return V_20 ;
}
static void F_15 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_16 ;
struct V_8 * V_9 = V_14 -> V_43 ;
if ( V_9 -> V_21 == V_22 )
return;
if ( V_9 -> V_23 == 0 ) {
T_2 V_26 = ( T_2 )
F_16 ( V_14 -> V_44 -> V_45 . V_46 [ 0 ] . V_29 ) ;
F_17 ( V_14 -> V_16 -> V_27 , V_26 , V_9 -> V_28 ,
V_9 -> V_21 ) ;
return;
}
F_18 ( V_2 , V_14 -> V_11 ) ;
if ( V_9 -> V_33 != V_47 )
F_14 ( V_2 -> V_27 , V_9 -> V_25 , V_9 -> V_23 ,
V_9 -> V_21 ) ;
}
static void F_19 ( struct V_13 * V_14 ,
struct V_48 * V_49 )
{
struct V_1 * V_2 = V_14 -> V_16 ;
struct V_8 * V_9 = V_14 -> V_43 ;
struct V_50 * V_51 = & V_9 -> V_52 ;
unsigned long V_4 ;
struct V_53 {
T_3 V_54 ;
T_4 V_55 ;
T_4 V_4 ;
} V_56 ( ( V_57 ) ) * V_58 = ( void * ) V_49 -> V_59 ;
int V_60 = ( ( V_58 -> V_4 & 0x70 ) >> 4 ) - 1 ;
struct V_13 * V_61 ;
struct V_62 * V_63 ;
void * V_64 ;
F_2 ( & V_2 -> V_5 . V_65 , V_4 ) ;
V_61 = F_20 ( & V_2 -> V_5 ,
( int ) F_21 ( V_58 -> V_54 ) ) ;
F_3 ( & V_2 -> V_5 . V_65 , V_4 ) ;
if ( ! V_61 ) {
F_22 ( L_1 ) ;
return;
}
V_51 -> V_66 = 0 ;
V_63 = V_2 -> V_5 . V_67 [ V_60 + V_61 -> V_68 ] ;
V_64 = V_63 -> V_38 ;
if ( V_9 -> V_33 == V_69 ) {
struct V_70 * V_71 =
V_64 + 16 + sizeof( struct V_72 ) ;
V_51 -> V_73 = F_23 ( * ( V_74 * ) V_64 ) ;
F_24 ( & V_2 -> V_27 -> V_75 , V_9 , V_71 ) ;
} else {
struct V_76 * V_77 = ( void * ) & V_51 -> V_78 [ 0 ] ;
V_51 -> V_73 = F_23 ( * ( V_74 * ) V_64 ) ;
if ( V_79 >= sizeof( * V_77 ) ) {
V_77 -> V_80 = F_21 ( * ( T_3 * ) ( V_64 + 6 ) ) ;
memcpy ( & V_77 -> V_81 [ 0 ] , V_64 + 16 , V_82 ) ;
V_51 -> V_66 = sizeof( * V_77 ) ;
}
}
F_25 ( V_61 , V_60 ) ;
}
static void F_26 ( struct V_13 * V_14 ,
struct V_48 * V_49 )
{
struct V_8 * V_9 = V_14 -> V_43 ;
struct V_50 * V_51 = & V_9 -> V_52 ;
unsigned long V_4 ;
T_4 V_83 = V_49 -> V_83 ;
F_1 ( V_14 -> V_16 , 1 ) ;
V_84:
switch ( V_83 ) {
case V_85 :
V_51 -> V_77 = V_86 ;
V_51 -> V_87 = V_88 ;
break;
case V_89 :
V_51 -> V_77 = V_86 ;
V_51 -> V_87 = V_90 ;
V_51 -> V_73 = F_23 ( * ( V_74 * ) V_49 -> V_59 ) ;
break;
case V_91 :
V_51 -> V_77 = V_86 ;
V_51 -> V_87 = V_92 ;
V_51 -> V_73 = 0 ;
break;
case V_93 :
case V_94 :
V_51 -> V_77 = V_86 ;
V_51 -> V_87 = V_95 ;
F_19 ( V_14 , V_49 ) ;
break;
case V_96 :
V_51 -> V_77 = V_97 ;
V_51 -> V_87 = V_98 ;
if ( V_49 -> V_59 [ 1 ] & 2 )
V_51 -> V_99 = 1 + V_49 -> V_59 [ 2 ] ;
else if ( V_49 -> V_59 [ 1 ] & 1 )
V_51 -> V_99 = ( V_49 -> V_59 [ 2 ] >> 4 ) + 10 ;
else
V_51 -> V_99 = V_100 ;
break;
case V_101 :
V_51 -> V_77 = V_97 ;
V_51 -> V_87 = V_102 ;
break;
case V_103 :
case V_104 :
V_51 -> V_77 = V_97 ;
V_51 -> V_87 = V_105 ;
break;
case V_106 :
V_51 -> V_77 = V_86 ;
V_51 -> V_87 = V_105 ;
break;
case V_107 :
case V_108 :
case V_109 :
case V_110 :
case V_111 :
case V_112 :
V_51 -> V_77 = V_86 ;
V_51 -> V_87 = V_113 ;
break;
case V_114 :
case V_115 :
case V_116 :
case V_117 :
V_51 -> V_77 = V_97 ;
V_51 -> V_87 = V_118 ;
break;
case V_119 :
V_51 -> V_77 = V_86 ;
V_51 -> V_87 = V_120 ;
break;
case V_121 :
V_83 = V_49 -> V_59 [ 0 ] ;
goto V_84;
break;
case V_122 :
V_51 -> V_77 = V_97 ;
V_51 -> V_87 = V_123 ;
break;
case V_124 :
V_51 -> V_77 = V_97 ;
V_51 -> V_87 = V_125 ;
break;
case V_126 :
case V_127 :
V_51 -> V_77 = V_86 ;
V_51 -> V_87 = V_128 ;
break;
case V_129 :
case V_130 :
case V_131 :
case V_132 :
case V_133 :
case V_134 :
case V_135 :
case V_136 :
case V_137 :
V_51 -> V_77 = V_97 ;
V_51 -> V_87 = V_118 ;
break;
case V_138 :
case V_139 :
case V_140 :
case V_141 :
default:
F_22 ( L_2 , V_142 , V_83 ) ;
break;
}
switch ( V_9 -> V_33 ) {
case V_143 :
case V_47 :
F_27 ( V_14 ) ;
break;
case V_144 :
F_28 ( V_14 ) ;
break;
case V_69 :
F_29 ( V_14 ) ;
default:
break;
}
F_2 ( & V_9 -> V_145 , V_4 ) ;
V_9 -> V_146 &= ~ V_147 ;
V_9 -> V_146 &= ~ V_148 ;
V_9 -> V_146 |= V_149 ;
if ( F_30 ( ( V_9 -> V_146 & V_150 ) ) ) {
struct V_151 * V_151 = V_14 -> V_151 ;
F_3 ( & V_9 -> V_145 , V_4 ) ;
F_22 ( L_3
L_4 ,
V_9 , V_83 , V_51 -> V_77 , V_51 -> V_87 ) ;
if ( V_151 )
F_31 ( V_151 ) ;
} else {
F_3 ( & V_9 -> V_145 , V_4 ) ;
V_9 -> V_15 = NULL ;
F_32 ( V_14 ) ;
F_33 () ;
V_9 -> V_152 ( V_9 ) ;
}
}
static int F_34 ( struct V_13 * V_14 , struct V_8 * V_9 ,
T_1 V_12 )
{
struct V_153 * V_75 = V_9 -> V_75 ;
struct V_44 * V_44 ;
T_4 V_4 ;
int V_20 = 0 ;
V_44 = V_14 -> V_44 ;
if ( F_30 ( V_9 -> V_154 . V_155 ) )
V_44 -> V_156 . V_83 = V_157 ;
else if ( V_75 -> V_158 . V_159 == V_160 )
V_44 -> V_156 . V_83 = V_161 ;
else
V_44 -> V_156 . V_83 = V_162 ;
V_44 -> V_154 . V_163 = ( 1 << 5 ) ;
if ( V_75 -> V_164 -> V_165 == V_166 )
V_44 -> V_154 . V_163 |= V_75 -> V_167 ;
V_44 -> V_154 . V_28 = F_7 ( V_9 -> V_28 ) ;
V_44 -> V_154 . V_168 = V_9 -> V_154 . V_168 ;
if ( F_35 ( ! V_9 -> V_154 . V_155 ) )
V_44 -> V_154 . V_168 . V_4 |= 0x80 ;
V_44 -> V_154 . V_168 . V_4 &= 0xF0 ;
if ( V_75 -> V_158 . V_159 == V_169 )
memcpy ( V_44 -> V_154 . V_170 , V_9 -> V_154 . V_170 ,
16 ) ;
V_44 -> V_154 . V_171 = F_36 ( 0xFFFF ) ;
V_44 -> V_154 . V_172 = F_36 (
( V_173 ) ( unsigned long ) V_75 -> V_174 ) ;
if ( F_35 ( ! V_9 -> V_154 . V_155 ) ) {
V_4 = 0 ;
if ( V_9 -> V_154 . V_175 )
V_4 |= V_176 ;
if ( V_9 -> V_154 . V_177 &&
V_75 -> V_158 . V_159 != V_169 )
V_4 |= V_178 ;
V_4 |= V_179 [ V_9 -> V_21 ] ;
V_44 -> V_154 . V_180 = V_4 ;
V_44 -> V_154 . V_181 = V_9 -> V_154 . V_181 ;
V_4 = 0 ;
if ( V_9 -> V_154 . V_182 )
V_4 |= V_183 ;
if ( V_9 -> V_154 . V_184 )
V_4 |= V_185 ;
V_44 -> V_154 . V_4 = V_4 ;
}
V_14 -> V_186 = F_26 ;
if ( F_35 ( ! V_9 -> V_154 . V_155 ) )
V_20 = F_4 ( V_9 , V_44 -> V_154 . V_46 ,
V_12 ) ;
return V_20 ;
}
static void F_27 ( struct V_13 * V_187 )
{
F_15 ( V_187 ) ;
}
static int F_37 ( struct V_13 * V_14 , struct V_8 * V_9 ,
T_1 V_12 )
{
struct V_1 * V_2 = V_14 -> V_16 ;
struct V_153 * V_75 = V_9 -> V_75 ;
struct V_44 * V_44 ;
F_9 ( V_2 -> V_27 , & V_9 -> V_188 . V_189 , 1 ,
V_190 ) ;
F_9 ( V_2 -> V_27 , & V_9 -> V_188 . V_191 , 1 ,
V_192 ) ;
V_44 = V_14 -> V_44 ;
V_44 -> V_156 . V_83 = V_193 ;
V_44 -> V_188 . V_163 = V_75 -> V_167 ;
V_44 -> V_188 . V_189 . V_29 =
F_6 ( ( V_30 ) F_12 ( & V_9 -> V_188 . V_189 ) ) ;
V_44 -> V_188 . V_189 . V_31 =
F_7 ( ( V_39 ) F_13 ( & V_9 -> V_188 . V_189 ) - 4 ) ;
V_44 -> V_188 . V_191 . V_29 =
F_6 ( ( V_30 ) F_12 ( & V_9 -> V_188 . V_191 ) ) ;
V_44 -> V_188 . V_191 . V_31 =
F_7 ( ( V_39 ) F_13 ( & V_9 -> V_188 . V_191 ) - 4 ) ;
V_44 -> V_188 . V_171 = F_36 ( 0xFFFF ) ;
V_44 -> V_188 . V_172 = F_36 ( ( V_173 )
( unsigned long ) V_75 -> V_174 ) ;
V_14 -> V_186 = F_26 ;
return 0 ;
}
static void F_28 ( struct V_13 * V_187 )
{
struct V_8 * V_9 = V_187 -> V_43 ;
F_38 ( ! V_9 ) ;
F_14 ( V_187 -> V_16 -> V_27 , & V_9 -> V_188 . V_189 , 1 ,
V_190 ) ;
F_14 ( V_187 -> V_16 -> V_27 , & V_9 -> V_188 . V_191 , 1 ,
V_192 ) ;
}
static int F_39 ( struct V_13 * V_14 , struct V_8 * V_9 ,
T_1 V_12 )
{
struct V_153 * V_75 = V_9 -> V_75 ;
struct V_44 * V_44 ;
int V_20 = 0 ;
V_44 = V_14 -> V_44 ;
V_44 -> V_156 . V_83 = V_194 ;
V_44 -> V_45 . V_163 = ( 1 << 4 ) ;
V_44 -> V_45 . V_163 |= V_75 -> V_167 ;
V_44 -> V_45 . V_28 = F_7 ( V_9 -> V_28 ) ;
V_44 -> V_45 . V_195 . V_196 = V_197 ;
memcpy ( V_44 -> V_45 . V_195 . V_198 , V_75 -> V_199 ,
V_200 ) ;
memcpy ( V_44 -> V_45 . V_195 . V_201 ,
V_75 -> V_164 -> V_16 -> V_199 , V_200 ) ;
V_44 -> V_45 . V_195 . V_202 = F_40 ( 0xFFFF ) ;
memcpy ( V_44 -> V_45 . V_203 . V_204 , V_9 -> V_45 . V_205 , 8 ) ;
if ( V_9 -> V_45 . V_206 )
V_44 -> V_45 . V_203 . V_207 |= V_208 ;
V_44 -> V_45 . V_203 . V_207 |= ( V_9 -> V_45 . V_209 << 3 ) ;
V_44 -> V_45 . V_203 . V_207 |= ( V_9 -> V_45 . V_210 & 7 ) ;
memcpy ( V_44 -> V_45 . V_203 . V_211 , V_9 -> V_45 . V_212 -> V_213 ,
V_9 -> V_45 . V_212 -> V_214 ) ;
V_44 -> V_45 . V_171 = F_36 ( 0xFFFF ) ;
V_44 -> V_45 . V_172 = F_36 (
( V_173 ) ( unsigned long ) V_75 -> V_174 ) ;
V_44 -> V_45 . V_21 = V_179 [ V_9 -> V_21 ] ;
V_44 -> V_45 . V_181 = V_44 -> V_45 . V_181 ;
V_14 -> V_186 = F_26 ;
V_20 = F_4 ( V_9 , V_44 -> V_45 . V_46 , V_12 ) ;
return V_20 ;
}
static void F_29 ( struct V_13 * V_187 )
{
F_15 ( V_187 ) ;
}
static int F_41 ( struct V_1 * V_2 , int V_3 )
{
int V_20 = 0 ;
unsigned long V_4 ;
F_2 ( & V_2 -> V_5 . V_6 , V_4 ) ;
if ( ( V_2 -> V_5 . V_7 - V_3 ) < 0 )
V_20 = - V_215 ;
else
V_2 -> V_5 . V_7 -= V_3 ;
F_3 ( & V_2 -> V_5 . V_6 , V_4 ) ;
return V_20 ;
}
int F_42 ( struct V_8 * V_9 , const int V_3 ,
T_1 V_12 )
{
int V_20 = 0 ;
F_43 ( V_216 ) ;
struct V_8 * V_217 = V_9 ;
struct V_13 * V_14 = NULL , * V_187 ;
struct V_1 * V_2 = V_9 -> V_75 -> V_164 -> V_16 -> V_218 ;
unsigned long V_4 ;
V_20 = F_41 ( V_2 , V_3 ) ;
if ( V_20 )
return V_20 ;
V_20 = V_3 ;
V_14 = F_44 ( V_2 , & V_20 , V_12 ) ;
if ( V_20 ) {
V_20 = - V_34 ;
goto V_219;
}
F_45 ( & V_216 , V_14 -> V_220 . V_221 , & V_14 -> V_220 ) ;
F_46 (a, &alist, list) {
V_187 -> V_43 = V_217 ;
V_217 -> V_15 = V_187 ;
V_217 = F_47 ( V_217 -> V_220 . V_222 , struct V_8 , V_220 ) ;
}
F_46 (a, &alist, list) {
V_217 = V_187 -> V_43 ;
V_187 -> V_223 = 1 ;
if ( V_217 -> V_33 & V_47 )
V_217 -> V_33 = V_47 ;
switch ( V_217 -> V_33 ) {
case V_143 :
case V_47 :
V_20 = F_34 ( V_187 , V_217 , V_12 ) ;
break;
case V_144 :
V_20 = F_37 ( V_187 , V_217 , V_12 ) ;
break;
case V_69 :
V_20 = F_39 ( V_187 , V_217 , V_12 ) ;
break;
default:
F_48 ( L_5 ,
V_217 -> V_33 ) ;
V_20 = - V_34 ;
break;
}
if ( V_20 )
goto V_224;
F_2 ( & V_217 -> V_145 , V_4 ) ;
V_217 -> V_146 |= V_148 ;
F_3 ( & V_217 -> V_145 , V_4 ) ;
}
F_49 ( & V_216 ) ;
V_20 = F_50 ( V_2 , V_14 , V_3 ) ;
if ( F_30 ( V_20 ) ) {
V_187 = NULL ;
F_45 ( & V_216 , V_14 -> V_220 . V_221 , & V_14 -> V_220 ) ;
goto V_224;
}
return 0 ;
V_224:
{
struct V_13 * V_225 = V_187 ;
F_46 (a, &alist, list) {
if ( V_187 == V_225 )
break;
V_217 = V_187 -> V_43 ;
F_2 ( & V_217 -> V_145 , V_4 ) ;
V_217 -> V_146 &= ~ V_148 ;
F_3 ( & V_217 -> V_145 , V_4 ) ;
switch ( V_217 -> V_33 ) {
case V_143 :
case V_47 :
F_27 ( V_187 ) ;
break;
case V_144 :
F_28 ( V_187 ) ;
break;
case V_69 :
F_29 ( V_187 ) ;
default:
break;
}
V_217 -> V_15 = NULL ;
}
}
F_49 ( & V_216 ) ;
V_219:
if ( V_14 )
F_51 ( V_14 ) ;
F_1 ( V_2 , V_3 ) ;
return V_20 ;
}
