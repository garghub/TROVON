static struct V_1 *
F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
unsigned long V_5 ;
F_2 ( & V_3 -> V_6 , V_5 ) ;
V_4 = V_3 -> V_7 . V_4 ;
if ( V_4 )
V_3 -> V_7 . V_8 ++ ;
F_3 ( & V_3 -> V_6 , V_5 ) ;
return V_4 ;
}
static void F_4 ( struct V_2 * V_3 )
{
unsigned long V_5 ;
F_2 ( & V_3 -> V_6 , V_5 ) ;
V_3 -> V_7 . V_8 -- ;
F_3 ( & V_3 -> V_6 , V_5 ) ;
}
static T_1 F_5 ( int V_9 )
{
switch ( V_9 ) {
default:
case 0 :
return V_10 ;
case 1 :
return V_11 ;
case 2 :
return V_12 ;
}
}
static T_1 F_6 ( struct V_13 * V_14 ,
int V_9 , T_1 V_15 )
{
return F_7 ( V_14 -> V_16 + F_5 ( V_9 ) + V_15 ) ;
}
static void F_8 ( struct V_13 * V_14 ,
int V_9 , T_1 V_15 , T_1 V_17 )
{
F_9 ( V_17 , V_14 -> V_16 + F_5 ( V_9 ) + V_15 ) ;
}
static void F_10 ( struct V_2 * V_18 , T_1 V_15 , T_1 * V_17 )
{
if ( ! V_18 -> V_19 )
* V_17 = 0 ;
else
* V_17 = F_6 ( V_18 -> V_14 , V_18 -> V_9 , V_15 ) ;
}
static void F_11 ( struct V_2 * V_18 , T_1 V_15 , T_1 V_17 )
{
if ( V_18 -> V_19 )
F_8 ( V_18 -> V_14 , V_18 -> V_9 , V_15 , V_17 ) ;
}
static void F_12 ( struct V_2 * V_3 ,
bool V_20 )
{
V_3 -> V_21 . V_22 . V_23 = V_20 ;
F_11 ( V_3 , V_24 ,
V_3 -> V_21 . V_25 ) ;
}
static void F_13 ( struct V_2 * V_18 )
{
T_1 V_26 ;
if ( ! V_18 -> V_19 )
return;
F_10 ( V_18 , V_27 , & V_26 ) ;
V_26 |= V_28 | V_29 ;
F_11 ( V_18 , V_27 , V_26 ) ;
F_10 ( V_18 , V_27 , & V_26 ) ;
}
static void F_14 ( struct V_2 * V_3 )
{
F_11 ( V_3 , V_27 ,
V_30 ) ;
F_11 ( V_3 , V_27 , 0 ) ;
}
static int F_15 ( struct V_1 * V_4 ,
struct V_2 * V_3 )
{
union V_31 V_32 = { . V_25 = 0 } ;
union V_33 V_34 = { . V_25 = 0 } ;
union V_35 V_36 = { . V_25 = 0 } ;
V_34 . V_22 . V_37 = ( V_3 -> V_38 &
V_39 ) >> 1 ;
V_34 . V_22 . V_40 = ( V_3 -> V_38 &
V_41 ) >> 4 ;
V_32 . V_22 . V_42 = V_34 . V_22 . V_37 ;
switch ( V_4 -> V_43 -> V_44 ) {
case V_45 :
V_34 . V_22 . V_46 = V_47 ;
break;
case V_48 :
V_34 . V_22 . V_46 = V_49 ;
break;
case V_50 :
V_34 . V_22 . V_46 = V_51 ;
break;
case V_52 :
V_34 . V_22 . V_46 = V_53 ;
break;
case V_54 :
V_34 . V_22 . V_46 = V_55 ;
break;
case V_56 :
V_34 . V_22 . V_46 = V_57 ;
break;
case V_58 :
V_34 . V_22 . V_46 = V_59 ;
break;
default:
return - V_60 ;
}
F_11 ( V_3 ,
V_61 , V_34 . V_25 ) ;
switch ( V_4 -> V_43 -> V_62 ) {
case V_63 :
V_36 . V_22 . V_64 = V_65 ;
V_36 . V_22 . V_66 = V_67 ;
break;
case V_68 :
case V_69 :
V_36 . V_22 . V_64 = V_70 ;
V_36 . V_22 . V_66 = V_71 ;
break;
default:
return - V_60 ;
}
F_11 ( V_3 ,
V_72 , V_36 . V_25 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_4 ,
struct V_2 * V_3 )
{
union V_31 V_32 = { . V_25 = 0 } ;
union V_73 V_74 = { . V_25 = 0 } ;
T_2 V_75 ;
F_15 ( V_4 , V_3 ) ;
V_74 . V_22 . V_76 = V_77 ;
V_74 . V_22 . V_78 = V_79 ;
V_74 . V_22 . V_80 = 0 ;
F_11 ( V_3 , V_81 , V_74 . V_25 ) ;
V_75 = V_4 -> V_43 -> V_75 ;
V_32 . V_22 . V_82 = V_75 - 2 ;
if ( V_75 <= 2 )
V_32 . V_22 . V_83 = V_84 ;
else
V_32 . V_22 . V_83 = V_85 ;
if ( V_4 -> V_43 -> V_62 == V_63 )
V_32 . V_22 . V_86 = 1 ;
if ( V_4 -> V_43 -> V_62 == V_69 )
V_32 . V_22 . V_87 = 1 ;
V_32 . V_22 . V_42 = 1 ;
if ( V_3 -> V_88 ) {
V_32 . V_22 . V_89 = 1 ;
V_32 . V_22 . V_90 = 1 ;
}
F_11 ( V_3 , V_24 , V_32 . V_25 ) ;
V_3 -> V_21 = V_32 ;
return 0 ;
}
static void F_17 ( void )
{
int V_91 , V_92 ;
struct V_93 * V_94 ;
for ( V_91 = 0 ; V_91 < F_18 ( V_95 ) ; V_91 ++ ) {
V_94 = V_95 + V_91 ;
V_94 -> V_75 = 0 ;
V_94 -> V_96 = 0 ;
for ( V_92 = 0 ; V_92 < F_18 ( V_94 -> V_97 ) ; V_92 ++ )
if ( V_94 -> V_97 [ V_92 ] ) {
V_94 -> V_75 ++ ;
V_94 -> V_96 |= V_94 -> V_97 [ V_92 ] ;
}
}
}
static int F_19 ( struct V_2 * V_3 ,
int V_75 )
{
int V_91 ;
int V_98 = 0 ;
int V_96 = 0 ;
if ( V_75 <= 2 )
return 0 ;
for ( V_91 = 0 ; V_91 < F_18 ( V_99 ) ; V_91 ++ ) {
if ( V_3 -> V_100 [ V_101 ] & ( 1 << V_91 ) )
V_96 |= V_99 [ V_91 ] ;
}
for ( V_91 = 0 ; V_91 < F_18 ( V_95 ) ; V_91 ++ ) {
if ( V_75 == V_95 [ V_91 ] . V_75 &&
( V_96 & V_95 [ V_91 ] . V_96 ) ==
V_95 [ V_91 ] . V_96 ) {
V_98 = V_95 [ V_91 ] . V_102 ;
break;
}
}
F_20 ( V_3 -> V_103 , L_1 , V_98 , V_75 ) ;
return V_98 ;
}
static int F_21 ( int V_104 )
{
const struct V_105 * V_106 = V_107 ;
for (; V_106 -> V_108 ; V_106 ++ ) {
if ( V_106 -> V_96 == V_104 )
return V_106 -> V_108 ;
}
return 0 ;
}
static void F_22 ( struct V_2 * V_3 )
{
int V_91 , V_109 ;
int V_96 = 0 ;
struct V_110 * V_111 ;
T_2 V_112 , V_113 = 0xF0 ;
T_2 V_114 ;
F_23 ( V_3 -> V_111 -> V_111 ) ;
V_3 -> V_111 -> V_111 = NULL ;
V_111 = F_24 ( sizeof( * V_111 ) , V_115 ) ;
if ( ! V_111 )
return;
F_20 ( V_3 -> V_103 , L_2 ,
V_3 -> V_100 [ V_101 ] ) ;
V_112 = V_3 -> V_100 [ V_101 ] & V_113 ;
if ( ( V_112 & ( V_112 - 1 ) ) && ( V_112 > 0x1F ) ) {
for ( V_91 = 1 ; V_91 < 4 ; V_91 ++ ) {
V_114 = V_112 & ( 0x80 >> V_91 ) ;
if ( V_114 ) {
V_3 -> V_100 [ V_101 ] &=
V_114 | 0xF ;
break;
}
}
}
for ( V_91 = 0 ; V_91 < F_18 ( V_99 ) ; V_91 ++ ) {
if ( V_3 -> V_100 [ V_101 ] & ( 1 << V_91 ) )
V_96 |= V_99 [ V_91 ] ;
}
for ( V_91 = 0 ; V_91 < F_18 ( V_95 ) ; V_91 ++ ) {
if ( V_96 == V_95 [ V_91 ] . V_96 ) {
for ( V_109 = 0 ; V_109 < V_95 [ V_91 ] . V_75 ; V_109 ++ ) {
V_111 -> V_108 [ V_109 ] = F_21 (
V_95 [ V_91 ] . V_97 [
( V_116 - 1 ) - V_109 ] ) ;
}
V_111 -> V_75 = V_95 [ V_91 ] . V_75 ;
V_3 -> V_111 -> V_111 = V_111 ;
break;
}
}
if ( V_91 >= F_18 ( V_95 ) )
F_23 ( V_111 ) ;
}
static int F_25 ( struct V_117 * V_118 ,
struct V_119 * V_120 )
{
V_120 -> type = V_121 ;
V_120 -> V_122 = V_123 ;
V_120 -> V_124 . integer . V_125 = 0 ;
V_120 -> V_124 . integer . V_126 = V_127 ;
return 0 ;
}
static int F_26 ( struct V_117 * V_118 ,
struct V_128 * V_129 )
{
struct V_130 * V_131 = F_27 ( V_118 ) ;
struct V_2 * V_3 = V_131 -> V_132 ;
int V_91 ;
const struct V_110 * V_111 ;
memset ( V_129 -> V_124 . integer . V_124 , 0 ,
sizeof( long ) * V_123 ) ;
F_28 ( & V_3 -> V_133 ) ;
if ( ! V_3 -> V_111 -> V_111 ) {
F_29 ( & V_3 -> V_133 ) ;
return 0 ;
}
V_111 = V_3 -> V_111 -> V_111 ;
for ( V_91 = 0 ; V_91 < V_111 -> V_75 ; V_91 ++ )
V_129 -> V_124 . integer . V_124 [ V_91 ] = V_111 -> V_108 [ V_91 ] ;
F_29 ( & V_3 -> V_133 ) ;
return 0 ;
}
static int F_30 ( struct V_2 * V_3 ,
struct V_134 * V_135 )
{
int V_136 ;
V_136 = F_31 ( V_135 , V_137 ,
NULL , 0 , ( unsigned long ) V_3 ,
& V_3 -> V_111 ) ;
if ( V_136 < 0 )
return V_136 ;
V_3 -> V_111 -> V_132 = V_3 ;
V_3 -> V_111 -> V_138 -> V_131 = F_25 ;
V_3 -> V_111 -> V_138 -> V_139 = F_26 ;
V_3 -> V_111 -> V_111 = NULL ;
return 0 ;
}
static void F_32 ( struct V_1 * V_4 ,
struct V_2 * V_3 )
{
int V_91 ;
union V_140 V_141 = { . V_25 = 0 } ;
union V_142 V_143 = { . V_25 = 0 } ;
union V_144 V_145 = { . V_25 = 0 } ;
T_2 V_146 = 0 ;
T_1 V_147 ;
int V_75 ;
int V_98 ;
V_75 = V_4 -> V_43 -> V_75 ;
F_11 ( V_3 , V_148 , V_141 . V_25 ) ;
V_98 = F_19 ( V_3 , V_75 ) ;
if ( V_3 -> V_88 ) {
V_147 = V_149 ;
V_143 . V_25 = ( V_4 -> V_43 -> V_75 - 1 ) | ( V_98 << 24 ) ;
} else {
V_147 = V_150 ;
V_143 . V_22 . V_151 = V_4 -> V_43 -> V_75 - 1 ;
V_145 . V_22 . V_152 = V_98 ;
for ( V_91 = 0 ; V_91 < V_153 ; V_91 ++ )
V_146 += ( V_147 >> ( V_91 * 8 ) ) & 0xff ;
for ( V_91 = 0 ; V_91 < V_153 ; V_91 ++ )
V_146 += ( V_143 . V_25 >> ( V_91 * 8 ) ) & 0xff ;
for ( V_91 = 0 ; V_91 < V_153 ; V_91 ++ )
V_146 += ( V_145 . V_25 >> ( V_91 * 8 ) ) & 0xff ;
V_143 . V_22 . V_154 = - ( V_146 ) ;
}
F_11 ( V_3 , V_155 , V_147 ) ;
F_11 ( V_3 , V_155 , V_143 . V_25 ) ;
F_11 ( V_3 , V_155 , V_145 . V_25 ) ;
for ( V_91 = 0 ; V_91 < V_156 - V_157 ; V_91 ++ )
F_11 ( V_3 , V_155 , 0x0 ) ;
V_141 . V_22 . V_158 = 1 ;
V_141 . V_22 . V_159 = 1 ;
F_11 ( V_3 , V_148 , V_141 . V_25 ) ;
}
static int F_33 ( T_1 V_160 , T_1 V_161 )
{
T_1 V_162 ;
if ( V_161 == V_163 ) {
switch ( V_160 ) {
case V_45 :
V_162 = V_164 ;
break;
case V_48 :
V_162 = V_165 ;
break;
case V_50 :
V_162 = V_166 ;
break;
case V_52 :
V_162 = V_167 ;
break;
case V_54 :
V_162 = V_168 ;
break;
case V_56 :
V_162 = V_169 ;
break;
case V_170 :
V_162 = V_171 ;
break;
default:
V_162 = - V_60 ;
break;
}
} else if ( V_161 == V_172 ) {
switch ( V_160 ) {
case V_45 :
V_162 = V_173 ;
break;
case V_48 :
V_162 = V_174 ;
break;
case V_50 :
V_162 = V_175 ;
break;
case V_52 :
V_162 = V_176 ;
break;
case V_54 :
V_162 = V_177 ;
break;
case V_56 :
V_162 = V_178 ;
break;
case V_170 :
V_162 = V_179 ;
break;
default:
V_162 = - V_60 ;
break;
}
} else
V_162 = - V_60 ;
return V_162 ;
}
static void F_34 ( T_1 V_160 , T_1 V_180 , T_1 V_161 ,
T_1 V_181 , struct V_2 * V_3 )
{
T_1 V_182 ;
T_3 V_183 , V_184 ;
if ( V_3 -> V_88 ) {
V_182 = F_33 ( V_160 , V_161 ) ;
} else {
V_183 = ( T_3 ) V_180 * V_181 * 1000 ;
V_184 = 128 * V_160 ;
V_182 = F_35 ( V_183 , V_184 ) ;
}
F_20 ( V_3 -> V_103 , L_3 ,
V_180 , V_181 , V_182 ) ;
F_11 ( V_3 , V_185 , ( F_36 ( 24 ) | V_182 ) ) ;
}
static int F_37 ( T_1 V_160 )
{
int V_186 ;
switch ( V_160 ) {
case V_45 :
V_186 = 4096 ;
break;
case V_48 :
V_186 = 6272 ;
break;
case V_50 :
V_186 = 6144 ;
break;
case V_52 :
V_186 = 12544 ;
break;
case V_54 :
V_186 = 12288 ;
break;
case V_56 :
V_186 = 25088 ;
break;
case V_170 :
V_186 = 24576 ;
break;
default:
V_186 = - V_60 ;
break;
}
return V_186 ;
}
static int F_38 ( T_1 V_160 , T_1 * V_181 ,
struct V_2 * V_3 )
{
int V_186 ;
if ( V_3 -> V_88 ) {
V_186 = V_187 ;
} else
V_186 = F_37 ( V_160 ) ;
if ( V_186 < 0 )
return V_186 ;
F_11 ( V_3 , V_188 , ( F_36 ( 24 ) | V_186 ) ) ;
* V_181 = V_186 ;
return 0 ;
}
static void F_39 ( struct V_1 * V_4 ,
struct V_2 * V_3 )
{
int V_189 = V_3 -> V_190 ;
int V_191 = V_3 -> V_192 * V_3 -> V_193 ;
T_1 V_194 = V_4 -> V_43 -> V_195 + V_191 ;
V_194 |= V_196 ;
if ( ! V_4 -> V_43 -> V_197 )
V_194 |= V_198 ;
F_11 ( V_3 , F_40 ( V_189 ) , V_194 ) ;
F_11 ( V_3 , F_41 ( V_189 ) ,
V_3 -> V_193 ) ;
V_3 -> V_190 ++ ;
V_3 -> V_190 %= V_3 -> V_199 ;
V_3 -> V_192 ++ ;
V_3 -> V_192 %= V_4 -> V_43 -> V_200 ;
}
static void F_42 ( struct V_2 * V_3 ,
int V_189 )
{
F_11 ( V_3 , F_40 ( V_189 ) , 0 ) ;
F_11 ( V_3 , F_41 ( V_189 ) , 0 ) ;
}
static void F_43 ( struct V_1 * V_4 ,
struct V_2 * V_3 )
{
struct V_201 * V_43 = V_4 -> V_43 ;
int V_91 , V_202 ;
V_202 = V_43 -> V_200 ;
V_3 -> V_199 = V_125 ( V_202 , V_203 ) ;
V_3 -> V_199 = V_126 ( V_3 -> V_199 , 2U ) ;
V_3 -> V_193 =
F_44 ( V_43 , V_43 -> V_204 ) ;
F_45 ( V_3 -> V_193 & 0x3f ) ;
V_3 -> V_190 = 0 ;
V_3 -> V_205 = 0 ;
V_3 -> V_192 = 0 ;
for ( V_91 = 0 ; V_91 < V_203 ; V_91 ++ ) {
if ( V_91 < V_3 -> V_199 )
F_39 ( V_4 , V_3 ) ;
else
F_42 ( V_3 , V_91 ) ;
}
V_3 -> V_190 = 0 ;
}
static void F_46 ( struct V_1 * V_4 ,
struct V_2 * V_3 )
{
int V_202 = V_4 -> V_43 -> V_200 ;
F_39 ( V_4 , V_3 ) ;
V_3 -> V_205 ++ ;
V_3 -> V_205 %= V_202 ;
}
static int F_47 ( struct V_1 * V_4 ,
struct V_2 * V_3 )
{
int V_206 , V_207 ;
unsigned long V_5 ;
V_207 = 0 ;
F_2 ( & V_3 -> V_6 , V_5 ) ;
for (; ; ) {
F_10 ( V_3 ,
F_41 ( V_3 -> V_190 ) ,
& V_206 ) ;
if ( V_206 < 0 || V_206 > V_3 -> V_193 ) {
F_20 ( V_3 -> V_103 , L_4 ,
V_206 ) ;
V_206 = - V_208 ;
goto V_209;
}
if ( V_206 > 0 )
break;
if ( ++ V_207 >= V_3 -> V_199 ) {
V_206 = - V_208 ;
goto V_209;
}
F_46 ( V_4 , V_3 ) ;
}
V_206 = V_3 -> V_193 - V_206 ;
V_206 += V_3 -> V_193 * V_3 -> V_205 ;
V_209:
F_3 ( & V_3 -> V_6 , V_5 ) ;
return V_206 ;
}
static void F_48 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 )
return;
if ( ! V_3 -> V_19 ) {
F_49 ( V_4 ) ;
goto V_209;
}
if ( F_47 ( V_4 , V_3 ) < 0 )
F_49 ( V_4 ) ;
else
F_50 ( V_4 ) ;
V_209:
F_4 ( V_3 ) ;
}
static void F_51 ( struct V_2 * V_3 )
{
int V_91 ;
T_1 V_17 ;
for ( V_91 = 0 ; V_91 < 100 ; V_91 ++ ) {
F_10 ( V_3 , V_27 , & V_17 ) ;
if ( ! ( V_17 & V_210 ) )
return;
F_52 ( 100 ) ;
F_53 () ;
F_11 ( V_3 , V_27 , V_17 ) ;
}
F_54 ( V_3 -> V_103 , L_5 ) ;
}
static void F_55 ( struct V_2 * V_3 )
{
if ( ! V_3 -> V_211 || ! V_3 -> V_19 )
return;
F_14 ( V_3 ) ;
F_51 ( V_3 ) ;
V_3 -> V_211 = false ;
}
static void F_56 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 ) {
F_49 ( V_4 ) ;
F_4 ( V_3 ) ;
}
V_3 -> V_211 = true ;
}
static int F_57 ( struct V_1 * V_4 )
{
struct V_2 * V_3 ;
struct V_201 * V_43 ;
int V_212 ;
V_3 = F_58 ( V_4 ) ;
V_43 = V_4 -> V_43 ;
F_59 ( V_3 -> V_103 ) ;
V_43 -> V_213 = V_214 ;
V_212 = F_60 ( V_43 ,
V_215 ) ;
if ( V_212 < 0 )
goto error;
V_212 = F_61 ( V_4 -> V_43 , 0 ,
V_216 , 64 ) ;
if ( V_212 < 0 )
goto error;
V_212 = F_62 ( V_43 , 0 , 32 , 24 ) ;
if ( V_212 < 0 )
goto error;
F_63 ( & V_3 -> V_6 ) ;
V_3 -> V_7 . V_4 = V_4 ;
V_3 -> V_7 . V_8 ++ ;
F_64 ( & V_3 -> V_6 ) ;
return V_212 ;
error:
F_65 ( V_3 -> V_103 ) ;
F_66 ( V_3 -> V_103 ) ;
return V_212 ;
}
static int F_67 ( struct V_1 * V_4 )
{
struct V_2 * V_3 ;
V_3 = F_58 ( V_4 ) ;
F_63 ( & V_3 -> V_6 ) ;
V_3 -> V_7 . V_4 = NULL ;
V_3 -> V_7 . V_8 -- ;
while ( V_3 -> V_7 . V_8 > 0 ) {
F_64 ( & V_3 -> V_6 ) ;
F_68 () ;
F_63 ( & V_3 -> V_6 ) ;
}
F_64 ( & V_3 -> V_6 ) ;
F_65 ( V_3 -> V_103 ) ;
F_66 ( V_3 -> V_103 ) ;
return 0 ;
}
static int F_69 ( struct V_1 * V_4 ,
struct V_217 * V_218 )
{
struct V_2 * V_3 ;
unsigned long V_194 ;
int V_219 , V_220 , V_212 ;
V_3 = F_58 ( V_4 ) ;
V_220 = F_70 ( V_218 ) ;
V_212 = F_71 ( V_4 , V_220 ) ;
if ( V_212 < 0 )
return V_212 ;
F_20 ( V_3 -> V_103 , L_6 ,
V_221 , V_220 ) ;
V_194 = ( unsigned long ) V_4 -> V_43 -> V_222 ;
V_219 = ( V_4 -> V_43 -> V_223 + V_224 - 1 ) / V_224 ;
V_212 = F_72 ( V_194 , V_219 ) ;
if ( V_212 ) {
F_54 ( V_3 -> V_103 , L_7 ,
V_212 ) ;
return V_212 ;
}
memset ( V_4 -> V_43 -> V_222 , 0 , V_220 ) ;
return V_212 ;
}
static int F_73 ( struct V_1 * V_4 )
{
struct V_2 * V_3 ;
unsigned long V_194 ;
T_1 V_219 ;
V_3 = F_58 ( V_4 ) ;
F_55 ( V_3 ) ;
if ( V_4 -> V_43 -> V_222 != NULL ) {
V_194 = ( unsigned long ) V_4 -> V_43 -> V_222 ;
V_219 = ( V_4 -> V_43 -> V_223 + V_224 - 1 ) /
V_224 ;
F_74 ( V_194 , V_219 ) ;
return F_75 ( V_4 ) ;
}
return 0 ;
}
static int F_76 ( struct V_1 * V_4 , int V_225 )
{
int V_212 = 0 ;
struct V_2 * V_3 ;
V_3 = F_58 ( V_4 ) ;
F_77 ( & V_3 -> V_6 ) ;
switch ( V_225 ) {
case V_226 :
case V_227 :
case V_228 :
F_13 ( V_3 ) ;
F_12 ( V_3 , true ) ;
break;
case V_229 :
case V_230 :
F_12 ( V_3 , false ) ;
V_3 -> V_211 = true ;
break;
default:
V_212 = - V_60 ;
}
F_78 ( & V_3 -> V_6 ) ;
return V_212 ;
}
static int F_79 ( struct V_1 * V_4 )
{
int V_212 ;
T_1 V_231 , V_181 ;
T_1 V_161 = 0 ;
struct V_2 * V_3 ;
struct V_201 * V_43 ;
V_3 = F_58 ( V_4 ) ;
V_43 = V_4 -> V_43 ;
F_20 ( V_3 -> V_103 , L_8 ,
( int ) F_44 ( V_43 , V_43 -> V_204 ) ) ;
F_20 ( V_3 -> V_103 , L_9 , V_43 -> V_200 ) ;
F_20 ( V_3 -> V_103 , L_10 ,
( int ) F_80 ( V_4 ) ) ;
F_20 ( V_3 -> V_103 , L_11 , V_43 -> V_44 ) ;
F_20 ( V_3 -> V_103 , L_12 , V_43 -> V_75 ) ;
F_55 ( V_3 ) ;
V_231 = V_3 -> V_232 ;
V_212 = F_38 ( V_4 -> V_43 -> V_44 , & V_181 , V_3 ) ;
if ( V_212 ) {
F_54 ( V_3 -> V_103 ,
L_13 , V_212 ) ;
goto V_233;
}
if ( V_3 -> V_88 )
V_161 = V_3 -> V_161 ;
F_34 ( V_4 -> V_43 -> V_44 , V_231 , V_161 ,
V_181 , V_3 ) ;
F_32 ( V_4 , V_3 ) ;
V_212 = F_16 ( V_4 , V_3 ) ;
F_43 ( V_4 , V_3 ) ;
F_11 ( V_3 , V_234 , V_235 ) ;
V_233:
return V_212 ;
}
static T_4 F_81 ( struct V_1 * V_4 )
{
struct V_2 * V_3 ;
int V_206 ;
V_3 = F_58 ( V_4 ) ;
if ( ! V_3 -> V_19 )
return V_236 ;
V_206 = F_47 ( V_4 , V_3 ) ;
if ( V_206 < 0 )
return V_236 ;
V_206 = F_82 ( V_4 -> V_43 , V_206 ) ;
V_206 %= V_4 -> V_43 -> V_237 ;
return V_206 ;
}
static int F_83 ( struct V_1 * V_4 ,
struct V_238 * V_239 )
{
V_239 -> V_240 = F_84 ( V_239 -> V_240 ) ;
return F_85 ( V_239 , V_239 -> V_241 ,
V_4 -> V_242 . V_194 >> V_243 ,
V_239 -> V_244 - V_239 -> V_241 , V_239 -> V_240 ) ;
}
static int F_86 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_212 = 0 ;
T_1 V_231 , V_181 ;
T_1 V_161 = 0 ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 )
return 0 ;
F_12 ( V_3 , false ) ;
V_231 = V_3 -> V_232 ;
V_212 = F_38 ( V_4 -> V_43 -> V_44 , & V_181 , V_3 ) ;
if ( V_212 ) {
F_54 ( V_3 -> V_103 ,
L_13 , V_212 ) ;
goto V_209;
}
if ( V_3 -> V_88 )
V_161 = V_3 -> V_161 ;
F_34 ( V_4 -> V_43 -> V_44 , V_231 , V_161 ,
V_181 , V_3 ) ;
F_12 ( V_3 , true ) ;
V_209:
F_4 ( V_3 ) ;
return V_212 ;
}
static void F_87 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
F_63 ( & V_3 -> V_6 ) ;
if ( V_3 -> V_19 ) {
F_20 ( V_3 -> V_103 , L_14 ) ;
F_64 ( & V_3 -> V_6 ) ;
return;
}
F_12 ( V_3 , false ) ;
V_3 -> V_19 = true ;
F_20 ( V_3 -> V_103 ,
L_15 ,
V_221 , __LINE__ ) ;
F_64 ( & V_3 -> V_6 ) ;
F_22 ( V_3 ) ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 ) {
F_49 ( V_4 ) ;
F_4 ( V_3 ) ;
}
F_88 ( V_3 -> V_245 , V_246 ) ;
}
static void F_89 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
F_63 ( & V_3 -> V_6 ) ;
if ( ! V_3 -> V_19 ) {
F_20 ( V_3 -> V_103 , L_16 ) ;
F_64 ( & V_3 -> V_6 ) ;
return;
}
F_12 ( V_3 , false ) ;
V_3 -> V_19 = false ;
F_20 ( V_3 -> V_103 ,
L_17 ,
V_221 , __LINE__ ) ;
F_64 ( & V_3 -> V_6 ) ;
F_23 ( V_3 -> V_111 -> V_111 ) ;
V_3 -> V_111 -> V_111 = NULL ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 ) {
F_49 ( V_4 ) ;
F_4 ( V_3 ) ;
}
F_88 ( V_3 -> V_245 , 0 ) ;
}
static int F_90 ( struct V_117 * V_118 ,
struct V_119 * V_120 )
{
V_120 -> type = V_247 ;
V_120 -> V_122 = 1 ;
return 0 ;
}
static int F_91 ( struct V_117 * V_118 ,
struct V_128 * V_129 )
{
struct V_2 * V_3 = F_27 ( V_118 ) ;
F_28 ( & V_3 -> V_133 ) ;
V_129 -> V_124 . V_248 . V_249 [ 0 ] = ( V_3 -> V_38 >> 0 ) & 0xff ;
V_129 -> V_124 . V_248 . V_249 [ 1 ] = ( V_3 -> V_38 >> 8 ) & 0xff ;
V_129 -> V_124 . V_248 . V_249 [ 2 ] =
( V_3 -> V_38 >> 16 ) & 0xff ;
V_129 -> V_124 . V_248 . V_249 [ 3 ] =
( V_3 -> V_38 >> 24 ) & 0xff ;
F_29 ( & V_3 -> V_133 ) ;
return 0 ;
}
static int F_92 ( struct V_117 * V_118 ,
struct V_128 * V_129 )
{
V_129 -> V_124 . V_248 . V_249 [ 0 ] = 0xff ;
V_129 -> V_124 . V_248 . V_249 [ 1 ] = 0xff ;
V_129 -> V_124 . V_248 . V_249 [ 2 ] = 0xff ;
V_129 -> V_124 . V_248 . V_249 [ 3 ] = 0xff ;
return 0 ;
}
static int F_93 ( struct V_117 * V_118 ,
struct V_128 * V_129 )
{
unsigned int V_17 ;
struct V_2 * V_3 = F_27 ( V_118 ) ;
int V_250 = 0 ;
V_17 = ( V_129 -> V_124 . V_248 . V_249 [ 0 ] << 0 ) |
( V_129 -> V_124 . V_248 . V_249 [ 1 ] << 8 ) |
( V_129 -> V_124 . V_248 . V_249 [ 2 ] << 16 ) |
( V_129 -> V_124 . V_248 . V_249 [ 3 ] << 24 ) ;
F_28 ( & V_3 -> V_133 ) ;
if ( V_3 -> V_38 != V_17 ) {
V_3 -> V_38 = V_17 ;
V_250 = 1 ;
}
F_29 ( & V_3 -> V_133 ) ;
return V_250 ;
}
static int F_94 ( struct V_117 * V_118 ,
struct V_119 * V_120 )
{
V_120 -> type = V_251 ;
V_120 -> V_122 = V_252 ;
return 0 ;
}
static int F_95 ( struct V_117 * V_118 ,
struct V_128 * V_129 )
{
struct V_2 * V_3 = F_27 ( V_118 ) ;
F_28 ( & V_3 -> V_133 ) ;
memcpy ( V_129 -> V_124 . V_253 . V_254 , V_3 -> V_100 ,
V_252 ) ;
F_29 ( & V_3 -> V_133 ) ;
return 0 ;
}
static T_5 F_96 ( int V_255 , void * V_256 )
{
struct V_13 * V_14 = V_256 ;
T_1 V_257 [ 3 ] = {} ;
int V_9 , V_258 ;
F_97 (card_ctx, pipe) {
V_257 [ V_9 ] = F_6 ( V_14 , V_9 ,
V_27 ) &
( V_29 | V_28 ) ;
if ( V_257 [ V_9 ] )
F_8 ( V_14 , V_9 ,
V_27 , V_257 [ V_9 ] ) ;
}
F_98 (card_ctx, port) {
struct V_2 * V_18 = & V_14 -> V_259 [ V_258 ] ;
int V_9 = V_18 -> V_9 ;
if ( V_9 < 0 )
continue;
if ( V_257 [ V_9 ] & V_28 )
F_48 ( V_18 ) ;
if ( V_257 [ V_9 ] & V_29 )
F_56 ( V_18 ) ;
}
return V_260 ;
}
static void F_99 ( struct V_261 * V_262 , int V_258 )
{
struct V_13 * V_14 = F_100 ( V_262 ) ;
struct V_2 * V_18 = & V_14 -> V_259 [ V_258 ] ;
F_101 ( & V_18 -> V_263 ) ;
}
static void F_102 ( struct V_264 * V_265 )
{
struct V_2 * V_18 =
F_103 ( V_265 , struct V_2 , V_263 ) ;
struct V_266 * V_267 = V_18 -> V_103 -> V_268 ;
struct V_269 * V_270 = & V_267 -> V_258 [ V_18 -> V_258 ] ;
F_59 ( V_18 -> V_103 ) ;
F_28 ( & V_18 -> V_133 ) ;
if ( V_270 -> V_9 < 0 ) {
F_20 ( V_18 -> V_103 , L_18 ,
V_221 , V_18 -> V_258 ) ;
memset ( V_18 -> V_100 , 0 , sizeof( V_18 -> V_100 ) ) ;
V_18 -> V_88 = false ;
V_18 -> V_232 = 0 ;
V_18 -> V_161 = 0 ;
F_89 ( V_18 ) ;
V_18 -> V_9 = - 1 ;
} else {
F_20 ( V_18 -> V_103 , L_19 ,
V_221 , V_18 -> V_258 , V_270 -> V_271 ) ;
memcpy ( V_18 -> V_100 , V_270 -> V_100 , sizeof( V_18 -> V_100 ) ) ;
V_18 -> V_88 = V_270 -> V_88 ;
if ( V_18 -> V_88 ) {
V_18 -> V_232 = 0 ;
V_18 -> V_161 = V_270 -> V_271 ;
} else {
V_18 -> V_232 = V_270 -> V_271 ;
V_18 -> V_161 = 0 ;
}
F_87 ( V_18 ) ;
V_18 -> V_9 = V_270 -> V_9 ;
F_86 ( V_18 ) ;
}
F_29 ( & V_18 -> V_133 ) ;
F_65 ( V_18 -> V_103 ) ;
F_66 ( V_18 -> V_103 ) ;
}
static int F_104 ( struct V_2 * V_18 ,
struct V_134 * V_135 )
{
char V_272 [ 32 ] ;
int V_136 ;
snprintf ( V_272 , sizeof( V_272 ) ,
L_20 , V_135 -> V_273 ) ;
V_136 = F_105 ( V_18 -> V_14 -> V_274 , V_272 ,
V_246 , & V_18 -> V_245 ,
true , false ) ;
if ( V_136 < 0 )
return V_136 ;
V_18 -> V_245 -> V_132 = V_18 ;
return 0 ;
}
static int F_106 ( struct V_273 * V_103 )
{
struct V_13 * V_14 = F_107 ( V_103 ) ;
int V_258 ;
F_98 (card_ctx, port) {
struct V_2 * V_18 = & V_14 -> V_259 [ V_258 ] ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_18 ) ;
if ( V_4 ) {
F_108 ( V_4 ) ;
F_4 ( V_18 ) ;
}
}
return 0 ;
}
static int T_6 F_109 ( struct V_273 * V_103 )
{
struct V_13 * V_14 = F_107 ( V_103 ) ;
int V_136 ;
V_136 = F_106 ( V_103 ) ;
if ( ! V_136 )
F_110 ( V_14 -> V_274 , V_275 ) ;
return V_136 ;
}
static int F_111 ( struct V_273 * V_103 )
{
F_65 ( V_103 ) ;
return 0 ;
}
static int T_6 F_112 ( struct V_273 * V_103 )
{
struct V_13 * V_14 = F_107 ( V_103 ) ;
F_111 ( V_103 ) ;
F_110 ( V_14 -> V_274 , V_276 ) ;
return 0 ;
}
static void F_113 ( struct V_277 * V_274 )
{
struct V_13 * V_14 = V_274 -> V_132 ;
struct V_266 * V_267 = V_14 -> V_103 -> V_268 ;
int V_258 ;
F_63 ( & V_267 -> V_278 ) ;
V_267 -> F_99 = NULL ;
F_64 ( & V_267 -> V_278 ) ;
F_98 (card_ctx, port) {
struct V_2 * V_18 = & V_14 -> V_259 [ V_258 ] ;
F_114 ( & V_18 -> V_263 ) ;
}
if ( V_14 -> V_16 )
F_115 ( V_14 -> V_16 ) ;
if ( V_14 -> V_255 >= 0 )
F_116 ( V_14 -> V_255 , V_14 ) ;
}
static int F_117 ( struct V_261 * V_262 )
{
struct V_277 * V_274 ;
struct V_13 * V_14 ;
struct V_134 * V_135 ;
struct V_266 * V_267 ;
int V_255 ;
struct V_279 * V_280 ;
int V_258 , V_281 ;
V_267 = V_262 -> V_103 . V_268 ;
if ( ! V_267 ) {
F_54 ( & V_262 -> V_103 , L_21 , V_221 ) ;
return - V_60 ;
}
V_255 = F_118 ( V_262 , 0 ) ;
if ( V_255 < 0 ) {
F_54 ( & V_262 -> V_103 , L_22 , V_255 ) ;
return V_255 ;
}
V_280 = F_119 ( V_262 , V_282 , 0 ) ;
if ( ! V_280 ) {
F_54 ( & V_262 -> V_103 , L_23 ) ;
return - V_283 ;
}
V_281 = F_120 ( & V_262 -> V_103 , V_284 , V_285 ,
V_286 , sizeof( * V_14 ) , & V_274 ) ;
if ( V_281 )
return V_281 ;
V_14 = V_274 -> V_132 ;
V_14 -> V_103 = & V_262 -> V_103 ;
V_14 -> V_274 = V_274 ;
strcpy ( V_274 -> V_287 , V_288 ) ;
strcpy ( V_274 -> V_289 , L_24 ) ;
strcpy ( V_274 -> V_290 , L_24 ) ;
V_14 -> V_255 = - 1 ;
V_274 -> V_291 = F_113 ;
F_121 ( V_262 , V_14 ) ;
F_20 ( & V_262 -> V_103 , L_25 ,
V_221 , ( unsigned int ) V_280 -> V_292 ,
( unsigned int ) V_280 -> V_293 ) ;
V_14 -> V_16 = F_122 ( V_280 -> V_292 ,
( V_294 ) ( F_123 ( V_280 ) ) ) ;
if ( ! V_14 -> V_16 ) {
F_54 ( & V_262 -> V_103 , L_26 ) ;
V_281 = - V_295 ;
goto V_136;
}
V_281 = F_124 ( V_255 , F_96 , 0 ,
V_262 -> V_296 , V_14 ) ;
if ( V_281 < 0 ) {
F_54 ( & V_262 -> V_103 , L_27 ) ;
goto V_136;
}
V_14 -> V_255 = V_255 ;
F_125 ( & V_262 -> V_103 , F_126 ( 32 ) ) ;
F_127 ( & V_262 -> V_103 , F_126 ( 32 ) ) ;
F_17 () ;
V_14 -> V_297 = V_267 -> V_297 ;
V_14 -> V_298 = V_267 -> V_298 ;
F_98 (card_ctx, port) {
struct V_2 * V_18 = & V_14 -> V_259 [ V_258 ] ;
int V_91 ;
V_18 -> V_14 = V_14 ;
V_18 -> V_103 = V_14 -> V_103 ;
V_18 -> V_258 = V_258 ;
V_18 -> V_9 = - 1 ;
F_128 ( & V_18 -> V_263 , F_102 ) ;
V_281 = F_129 ( V_274 , V_288 , V_258 , V_299 ,
V_300 , & V_135 ) ;
if ( V_281 )
goto V_136;
V_135 -> V_132 = V_18 ;
V_135 -> V_301 = 0 ;
strncpy ( V_135 -> V_296 , V_274 -> V_289 , strlen ( V_274 -> V_289 ) ) ;
F_130 ( V_135 , V_137 , & V_302 ) ;
F_131 ( V_135 ,
V_303 , NULL ,
V_304 , V_305 ) ;
for ( V_91 = 0 ; V_91 < F_18 ( V_306 ) ; V_91 ++ ) {
struct V_117 * V_138 ;
V_138 = F_132 ( & V_306 [ V_91 ] , V_18 ) ;
if ( ! V_138 ) {
V_281 = - V_307 ;
goto V_136;
}
V_138 -> V_308 . V_273 = V_135 -> V_273 ;
V_281 = F_133 ( V_274 , V_138 ) ;
if ( V_281 < 0 )
goto V_136;
}
V_281 = F_30 ( V_18 , V_135 ) ;
if ( V_281 < 0 )
goto V_136;
V_281 = F_104 ( V_18 , V_135 ) ;
if ( V_281 < 0 )
goto V_136;
}
V_281 = F_134 ( V_274 ) ;
if ( V_281 )
goto V_136;
F_63 ( & V_267 -> V_278 ) ;
V_267 -> F_99 = F_99 ;
F_64 ( & V_267 -> V_278 ) ;
F_135 ( & V_262 -> V_103 ) ;
F_65 ( & V_262 -> V_103 ) ;
F_136 ( & V_262 -> V_103 ) ;
F_20 ( & V_262 -> V_103 , L_28 , V_221 ) ;
F_98 (card_ctx, port) {
struct V_2 * V_18 = & V_14 -> V_259 [ V_258 ] ;
F_101 ( & V_18 -> V_263 ) ;
}
return 0 ;
V_136:
F_137 ( V_274 ) ;
return V_281 ;
}
static int F_138 ( struct V_261 * V_262 )
{
struct V_13 * V_14 = F_100 ( V_262 ) ;
F_137 ( V_14 -> V_274 ) ;
return 0 ;
}
