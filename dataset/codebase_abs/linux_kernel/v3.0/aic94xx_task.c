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
memcpy ( & V_77 -> V_81 [ 0 ] , V_64 + 16 , 24 ) ;
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
T_4 V_82 = V_49 -> V_82 ;
F_1 ( V_14 -> V_16 , 1 ) ;
V_83:
switch ( V_82 ) {
case V_84 :
V_51 -> V_77 = V_85 ;
V_51 -> V_86 = V_87 ;
break;
case V_88 :
V_51 -> V_77 = V_85 ;
V_51 -> V_86 = V_89 ;
V_51 -> V_73 = F_23 ( * ( V_74 * ) V_49 -> V_59 ) ;
break;
case V_90 :
V_51 -> V_77 = V_85 ;
V_51 -> V_86 = V_91 ;
V_51 -> V_73 = 0 ;
break;
case V_92 :
case V_93 :
V_51 -> V_77 = V_85 ;
V_51 -> V_86 = V_94 ;
F_19 ( V_14 , V_49 ) ;
break;
case V_95 :
V_51 -> V_77 = V_96 ;
V_51 -> V_86 = V_97 ;
if ( V_49 -> V_59 [ 1 ] & 2 )
V_51 -> V_98 = 1 + V_49 -> V_59 [ 2 ] ;
else if ( V_49 -> V_59 [ 1 ] & 1 )
V_51 -> V_98 = ( V_49 -> V_59 [ 2 ] >> 4 ) + 10 ;
else
V_51 -> V_98 = V_99 ;
break;
case V_100 :
V_51 -> V_77 = V_96 ;
V_51 -> V_86 = V_101 ;
break;
case V_102 :
case V_103 :
V_51 -> V_77 = V_96 ;
V_51 -> V_86 = V_104 ;
break;
case V_105 :
V_51 -> V_77 = V_85 ;
V_51 -> V_86 = V_104 ;
break;
case V_106 :
case V_107 :
case V_108 :
case V_109 :
case V_110 :
case V_111 :
V_51 -> V_77 = V_85 ;
V_51 -> V_86 = V_112 ;
break;
case V_113 :
case V_114 :
case V_115 :
case V_116 :
V_51 -> V_77 = V_96 ;
V_51 -> V_86 = V_117 ;
break;
case V_118 :
V_51 -> V_77 = V_85 ;
V_51 -> V_86 = V_119 ;
break;
case V_120 :
V_82 = V_49 -> V_59 [ 0 ] ;
goto V_83;
break;
case V_121 :
V_51 -> V_77 = V_96 ;
V_51 -> V_86 = V_122 ;
break;
case V_123 :
V_51 -> V_77 = V_96 ;
V_51 -> V_86 = V_124 ;
break;
case V_125 :
case V_126 :
V_51 -> V_77 = V_85 ;
V_51 -> V_86 = V_127 ;
break;
case V_128 :
case V_129 :
case V_130 :
case V_131 :
case V_132 :
case V_133 :
case V_134 :
case V_135 :
case V_136 :
V_51 -> V_77 = V_96 ;
V_51 -> V_86 = V_117 ;
break;
case V_137 :
case V_138 :
case V_139 :
case V_140 :
default:
F_22 ( L_2 , V_141 , V_82 ) ;
break;
}
switch ( V_9 -> V_33 ) {
case V_142 :
case V_47 :
F_27 ( V_14 ) ;
break;
case V_143 :
F_28 ( V_14 ) ;
break;
case V_69 :
F_29 ( V_14 ) ;
default:
break;
}
F_2 ( & V_9 -> V_144 , V_4 ) ;
V_9 -> V_145 &= ~ V_146 ;
V_9 -> V_145 &= ~ V_147 ;
V_9 -> V_145 |= V_148 ;
if ( F_30 ( ( V_9 -> V_145 & V_149 ) ) ) {
struct V_150 * V_150 = V_14 -> V_150 ;
F_3 ( & V_9 -> V_144 , V_4 ) ;
F_22 ( L_3
L_4 ,
V_9 , V_82 , V_51 -> V_77 , V_51 -> V_86 ) ;
if ( V_150 )
F_31 ( V_150 ) ;
} else {
F_3 ( & V_9 -> V_144 , V_4 ) ;
V_9 -> V_15 = NULL ;
F_32 ( V_14 ) ;
F_33 () ;
V_9 -> V_151 ( V_9 ) ;
}
}
static int F_34 ( struct V_13 * V_14 , struct V_8 * V_9 ,
T_1 V_12 )
{
struct V_152 * V_75 = V_9 -> V_75 ;
struct V_44 * V_44 ;
T_4 V_4 ;
int V_20 = 0 ;
V_44 = V_14 -> V_44 ;
if ( F_30 ( V_9 -> V_153 . V_154 ) )
V_44 -> V_155 . V_82 = V_156 ;
else if ( V_75 -> V_157 . V_158 == V_159 )
V_44 -> V_155 . V_82 = V_160 ;
else
V_44 -> V_155 . V_82 = V_161 ;
V_44 -> V_153 . V_162 = ( 1 << 5 ) ;
if ( V_75 -> V_163 -> V_164 == V_165 )
V_44 -> V_153 . V_162 |= V_75 -> V_166 ;
V_44 -> V_153 . V_28 = F_7 ( V_9 -> V_28 ) ;
V_44 -> V_153 . V_167 = V_9 -> V_153 . V_167 ;
if ( F_35 ( ! V_9 -> V_153 . V_154 ) )
V_44 -> V_153 . V_167 . V_4 |= 0x80 ;
V_44 -> V_153 . V_167 . V_4 &= 0xF0 ;
if ( V_75 -> V_157 . V_158 == V_168 )
memcpy ( V_44 -> V_153 . V_169 , V_9 -> V_153 . V_169 ,
16 ) ;
V_44 -> V_153 . V_170 = F_36 ( 0xFFFF ) ;
V_44 -> V_153 . V_171 = F_36 (
( V_172 ) ( unsigned long ) V_75 -> V_173 ) ;
if ( F_35 ( ! V_9 -> V_153 . V_154 ) ) {
V_4 = 0 ;
if ( V_9 -> V_153 . V_174 )
V_4 |= V_175 ;
if ( V_9 -> V_153 . V_176 &&
V_75 -> V_157 . V_158 != V_168 )
V_4 |= V_177 ;
V_4 |= V_178 [ V_9 -> V_21 ] ;
V_44 -> V_153 . V_179 = V_4 ;
V_44 -> V_153 . V_180 = V_9 -> V_153 . V_180 ;
V_4 = 0 ;
if ( V_9 -> V_153 . V_181 )
V_4 |= V_182 ;
if ( V_9 -> V_153 . V_183 )
V_4 |= V_184 ;
V_44 -> V_153 . V_4 = V_4 ;
}
V_14 -> V_185 = F_26 ;
if ( F_35 ( ! V_9 -> V_153 . V_154 ) )
V_20 = F_4 ( V_9 , V_44 -> V_153 . V_46 ,
V_12 ) ;
return V_20 ;
}
static void F_27 ( struct V_13 * V_186 )
{
F_15 ( V_186 ) ;
}
static int F_37 ( struct V_13 * V_14 , struct V_8 * V_9 ,
T_1 V_12 )
{
struct V_1 * V_2 = V_14 -> V_16 ;
struct V_152 * V_75 = V_9 -> V_75 ;
struct V_44 * V_44 ;
F_9 ( V_2 -> V_27 , & V_9 -> V_187 . V_188 , 1 ,
V_189 ) ;
F_9 ( V_2 -> V_27 , & V_9 -> V_187 . V_190 , 1 ,
V_191 ) ;
V_44 = V_14 -> V_44 ;
V_44 -> V_155 . V_82 = V_192 ;
V_44 -> V_187 . V_162 = V_75 -> V_166 ;
V_44 -> V_187 . V_188 . V_29 =
F_6 ( ( V_30 ) F_12 ( & V_9 -> V_187 . V_188 ) ) ;
V_44 -> V_187 . V_188 . V_31 =
F_7 ( ( V_39 ) F_13 ( & V_9 -> V_187 . V_188 ) - 4 ) ;
V_44 -> V_187 . V_190 . V_29 =
F_6 ( ( V_30 ) F_12 ( & V_9 -> V_187 . V_190 ) ) ;
V_44 -> V_187 . V_190 . V_31 =
F_7 ( ( V_39 ) F_13 ( & V_9 -> V_187 . V_190 ) - 4 ) ;
V_44 -> V_187 . V_170 = F_36 ( 0xFFFF ) ;
V_44 -> V_187 . V_171 = F_36 ( ( V_172 )
( unsigned long ) V_75 -> V_173 ) ;
V_14 -> V_185 = F_26 ;
return 0 ;
}
static void F_28 ( struct V_13 * V_186 )
{
struct V_8 * V_9 = V_186 -> V_43 ;
F_38 ( ! V_9 ) ;
F_14 ( V_186 -> V_16 -> V_27 , & V_9 -> V_187 . V_188 , 1 ,
V_189 ) ;
F_14 ( V_186 -> V_16 -> V_27 , & V_9 -> V_187 . V_190 , 1 ,
V_191 ) ;
}
static int F_39 ( struct V_13 * V_14 , struct V_8 * V_9 ,
T_1 V_12 )
{
struct V_152 * V_75 = V_9 -> V_75 ;
struct V_44 * V_44 ;
int V_20 = 0 ;
V_44 = V_14 -> V_44 ;
V_44 -> V_155 . V_82 = V_193 ;
V_44 -> V_45 . V_162 = ( 1 << 4 ) ;
V_44 -> V_45 . V_162 |= V_75 -> V_166 ;
V_44 -> V_45 . V_28 = F_7 ( V_9 -> V_28 ) ;
V_44 -> V_45 . V_194 . V_195 = V_196 ;
memcpy ( V_44 -> V_45 . V_194 . V_197 , V_75 -> V_198 ,
V_199 ) ;
memcpy ( V_44 -> V_45 . V_194 . V_200 ,
V_75 -> V_163 -> V_16 -> V_198 , V_199 ) ;
V_44 -> V_45 . V_194 . V_201 = F_40 ( 0xFFFF ) ;
memcpy ( V_44 -> V_45 . V_202 . V_203 , V_9 -> V_45 . V_204 , 8 ) ;
if ( V_9 -> V_45 . V_205 )
V_44 -> V_45 . V_202 . V_206 |= V_207 ;
V_44 -> V_45 . V_202 . V_206 |= ( V_9 -> V_45 . V_208 << 3 ) ;
V_44 -> V_45 . V_202 . V_206 |= ( V_9 -> V_45 . V_209 & 7 ) ;
memcpy ( V_44 -> V_45 . V_202 . V_210 , V_9 -> V_45 . V_210 , 16 ) ;
V_44 -> V_45 . V_170 = F_36 ( 0xFFFF ) ;
V_44 -> V_45 . V_171 = F_36 (
( V_172 ) ( unsigned long ) V_75 -> V_173 ) ;
V_44 -> V_45 . V_21 = V_178 [ V_9 -> V_21 ] ;
V_44 -> V_45 . V_180 = V_44 -> V_45 . V_180 ;
V_14 -> V_185 = F_26 ;
V_20 = F_4 ( V_9 , V_44 -> V_45 . V_46 , V_12 ) ;
return V_20 ;
}
static void F_29 ( struct V_13 * V_186 )
{
F_15 ( V_186 ) ;
}
static int F_41 ( struct V_1 * V_2 , int V_3 )
{
int V_20 = 0 ;
unsigned long V_4 ;
F_2 ( & V_2 -> V_5 . V_6 , V_4 ) ;
if ( ( V_2 -> V_5 . V_7 - V_3 ) < 0 )
V_20 = - V_211 ;
else
V_2 -> V_5 . V_7 -= V_3 ;
F_3 ( & V_2 -> V_5 . V_6 , V_4 ) ;
return V_20 ;
}
int F_42 ( struct V_8 * V_9 , const int V_3 ,
T_1 V_12 )
{
int V_20 = 0 ;
F_43 ( V_212 ) ;
struct V_8 * V_213 = V_9 ;
struct V_13 * V_14 = NULL , * V_186 ;
struct V_1 * V_2 = V_9 -> V_75 -> V_163 -> V_16 -> V_214 ;
unsigned long V_4 ;
V_20 = F_41 ( V_2 , V_3 ) ;
if ( V_20 )
return V_20 ;
V_20 = V_3 ;
V_14 = F_44 ( V_2 , & V_20 , V_12 ) ;
if ( V_20 ) {
V_20 = - V_34 ;
goto V_215;
}
F_45 ( & V_212 , V_14 -> V_216 . V_217 , & V_14 -> V_216 ) ;
F_46 (a, &alist, list) {
V_186 -> V_43 = V_213 ;
V_213 -> V_15 = V_186 ;
V_213 = F_47 ( V_213 -> V_216 . V_218 , struct V_8 , V_216 ) ;
}
F_46 (a, &alist, list) {
V_213 = V_186 -> V_43 ;
V_186 -> V_219 = 1 ;
if ( V_213 -> V_33 & V_47 )
V_213 -> V_33 = V_47 ;
switch ( V_213 -> V_33 ) {
case V_142 :
case V_47 :
V_20 = F_34 ( V_186 , V_213 , V_12 ) ;
break;
case V_143 :
V_20 = F_37 ( V_186 , V_213 , V_12 ) ;
break;
case V_69 :
V_20 = F_39 ( V_186 , V_213 , V_12 ) ;
break;
default:
F_48 ( L_5 ,
V_213 -> V_33 ) ;
V_20 = - V_34 ;
break;
}
if ( V_20 )
goto V_220;
F_2 ( & V_213 -> V_144 , V_4 ) ;
V_213 -> V_145 |= V_147 ;
F_3 ( & V_213 -> V_144 , V_4 ) ;
}
F_49 ( & V_212 ) ;
V_20 = F_50 ( V_2 , V_14 , V_3 ) ;
if ( F_30 ( V_20 ) ) {
V_186 = NULL ;
F_45 ( & V_212 , V_14 -> V_216 . V_217 , & V_14 -> V_216 ) ;
goto V_220;
}
return 0 ;
V_220:
{
struct V_13 * V_221 = V_186 ;
F_46 (a, &alist, list) {
if ( V_186 == V_221 )
break;
V_213 = V_186 -> V_43 ;
F_2 ( & V_213 -> V_144 , V_4 ) ;
V_213 -> V_145 &= ~ V_147 ;
F_3 ( & V_213 -> V_144 , V_4 ) ;
switch ( V_213 -> V_33 ) {
case V_142 :
case V_47 :
F_27 ( V_186 ) ;
break;
case V_143 :
F_28 ( V_186 ) ;
break;
case V_69 :
F_29 ( V_186 ) ;
default:
break;
}
V_213 -> V_15 = NULL ;
}
}
F_49 ( & V_212 ) ;
V_215:
if ( V_14 )
F_51 ( V_14 ) ;
F_1 ( V_2 , V_3 ) ;
return V_20 ;
}
