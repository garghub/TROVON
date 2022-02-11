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
static T_1 F_5 ( struct V_2 * V_9 , T_1 V_10 )
{
return F_6 ( V_9 -> V_11 + V_9 -> V_12 + V_10 ) ;
}
static void F_7 ( struct V_2 * V_9 , T_1 V_10 , T_1 V_13 )
{
F_8 ( V_13 , V_9 -> V_11 + V_9 -> V_12 + V_10 ) ;
}
static void F_9 ( struct V_2 * V_9 , T_1 V_10 , T_1 * V_13 )
{
if ( ! V_9 -> V_14 )
* V_13 = 0 ;
else
* V_13 = F_5 ( V_9 , V_10 ) ;
}
static void F_10 ( struct V_2 * V_9 , T_1 V_10 , T_1 V_13 )
{
if ( V_9 -> V_14 )
F_7 ( V_9 , V_10 , V_13 ) ;
}
static void F_11 ( struct V_2 * V_3 ,
bool V_15 )
{
V_3 -> V_16 . V_17 . V_18 = V_15 ;
F_10 ( V_3 , V_19 ,
V_3 -> V_16 . V_20 ) ;
}
static void F_12 ( struct V_2 * V_9 )
{
T_1 V_21 ;
if ( ! V_9 -> V_14 )
return;
F_9 ( V_9 , V_22 , & V_21 ) ;
V_21 |= V_23 | V_24 ;
F_10 ( V_9 , V_22 , V_21 ) ;
F_9 ( V_9 , V_22 , & V_21 ) ;
}
static void F_13 ( struct V_2 * V_3 )
{
F_10 ( V_3 , V_22 ,
V_25 ) ;
F_10 ( V_3 , V_22 , 0 ) ;
}
static int F_14 ( struct V_1 * V_4 ,
struct V_2 * V_3 )
{
union V_26 V_27 = { . V_20 = 0 } ;
union V_28 V_29 = { . V_20 = 0 } ;
union V_30 V_31 = { . V_20 = 0 } ;
V_29 . V_17 . V_32 = ( V_3 -> V_33 &
V_34 ) >> 1 ;
V_29 . V_17 . V_35 = ( V_3 -> V_33 &
V_36 ) >> 4 ;
V_27 . V_17 . V_37 = V_29 . V_17 . V_32 ;
switch ( V_4 -> V_38 -> V_39 ) {
case V_40 :
V_29 . V_17 . V_41 = V_42 ;
break;
case V_43 :
V_29 . V_17 . V_41 = V_44 ;
break;
case V_45 :
V_29 . V_17 . V_41 = V_46 ;
break;
case V_47 :
V_29 . V_17 . V_41 = V_48 ;
break;
case V_49 :
V_29 . V_17 . V_41 = V_50 ;
break;
case V_51 :
V_29 . V_17 . V_41 = V_52 ;
break;
case V_53 :
V_29 . V_17 . V_41 = V_54 ;
break;
default:
return - V_55 ;
}
F_10 ( V_3 ,
V_56 , V_29 . V_20 ) ;
switch ( V_4 -> V_38 -> V_57 ) {
case V_58 :
V_31 . V_17 . V_59 = V_60 ;
V_31 . V_17 . V_61 = V_62 ;
break;
case V_63 :
case V_64 :
V_31 . V_17 . V_59 = V_65 ;
V_31 . V_17 . V_61 = V_66 ;
break;
default:
return - V_55 ;
}
F_10 ( V_3 ,
V_67 , V_31 . V_20 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_4 ,
struct V_2 * V_3 )
{
union V_26 V_27 = { . V_20 = 0 } ;
union V_68 V_69 = { . V_20 = 0 } ;
T_2 V_70 ;
F_14 ( V_4 , V_3 ) ;
V_69 . V_17 . V_71 = V_72 ;
V_69 . V_17 . V_73 = V_74 ;
V_69 . V_17 . V_75 = 0 ;
F_10 ( V_3 , V_76 , V_69 . V_20 ) ;
V_70 = V_4 -> V_38 -> V_70 ;
V_27 . V_17 . V_77 = V_70 - 2 ;
if ( V_70 <= 2 )
V_27 . V_17 . V_78 = V_79 ;
else
V_27 . V_17 . V_78 = V_80 ;
if ( V_4 -> V_38 -> V_57 == V_58 )
V_27 . V_17 . V_81 = 1 ;
if ( V_4 -> V_38 -> V_57 == V_64 )
V_27 . V_17 . V_82 = 1 ;
V_27 . V_17 . V_37 = 1 ;
if ( V_3 -> V_83 ) {
V_27 . V_17 . V_84 = 1 ;
V_27 . V_17 . V_85 = 1 ;
}
F_10 ( V_3 , V_19 , V_27 . V_20 ) ;
V_3 -> V_16 = V_27 ;
return 0 ;
}
static void F_16 ( void )
{
int V_86 , V_87 ;
struct V_88 * V_89 ;
for ( V_86 = 0 ; V_86 < F_17 ( V_90 ) ; V_86 ++ ) {
V_89 = V_90 + V_86 ;
V_89 -> V_70 = 0 ;
V_89 -> V_91 = 0 ;
for ( V_87 = 0 ; V_87 < F_17 ( V_89 -> V_92 ) ; V_87 ++ )
if ( V_89 -> V_92 [ V_87 ] ) {
V_89 -> V_70 ++ ;
V_89 -> V_91 |= V_89 -> V_92 [ V_87 ] ;
}
}
}
static int F_18 ( struct V_2 * V_3 ,
int V_70 )
{
int V_86 ;
int V_93 = 0 ;
int V_91 = 0 ;
if ( V_70 <= 2 )
return 0 ;
for ( V_86 = 0 ; V_86 < F_17 ( V_94 ) ; V_86 ++ ) {
if ( V_3 -> V_95 [ V_96 ] & ( 1 << V_86 ) )
V_91 |= V_94 [ V_86 ] ;
}
for ( V_86 = 0 ; V_86 < F_17 ( V_90 ) ; V_86 ++ ) {
if ( V_70 == V_90 [ V_86 ] . V_70 &&
( V_91 & V_90 [ V_86 ] . V_91 ) ==
V_90 [ V_86 ] . V_91 ) {
V_93 = V_90 [ V_86 ] . V_97 ;
break;
}
}
F_19 ( V_3 -> V_98 , L_1 , V_93 , V_70 ) ;
return V_93 ;
}
static int F_20 ( int V_99 )
{
const struct V_100 * V_101 = V_102 ;
for (; V_101 -> V_103 ; V_101 ++ ) {
if ( V_101 -> V_91 == V_99 )
return V_101 -> V_103 ;
}
return 0 ;
}
static void F_21 ( struct V_2 * V_3 )
{
int V_86 , V_104 ;
int V_91 = 0 ;
struct V_105 * V_106 ;
T_2 V_107 , V_108 = 0xF0 ;
T_2 V_109 ;
F_22 ( V_3 -> V_106 -> V_106 ) ;
V_3 -> V_106 -> V_106 = NULL ;
V_106 = F_23 ( sizeof( * V_106 ) , V_110 ) ;
if ( ! V_106 )
return;
F_19 ( V_3 -> V_98 , L_2 ,
V_3 -> V_95 [ V_96 ] ) ;
V_107 = V_3 -> V_95 [ V_96 ] & V_108 ;
if ( ( V_107 & ( V_107 - 1 ) ) && ( V_107 > 0x1F ) ) {
for ( V_86 = 1 ; V_86 < 4 ; V_86 ++ ) {
V_109 = V_107 & ( 0x80 >> V_86 ) ;
if ( V_109 ) {
V_3 -> V_95 [ V_96 ] &=
V_109 | 0xF ;
break;
}
}
}
for ( V_86 = 0 ; V_86 < F_17 ( V_94 ) ; V_86 ++ ) {
if ( V_3 -> V_95 [ V_96 ] & ( 1 << V_86 ) )
V_91 |= V_94 [ V_86 ] ;
}
for ( V_86 = 0 ; V_86 < F_17 ( V_90 ) ; V_86 ++ ) {
if ( V_91 == V_90 [ V_86 ] . V_91 ) {
for ( V_104 = 0 ; V_104 < V_90 [ V_86 ] . V_70 ; V_104 ++ ) {
V_106 -> V_103 [ V_104 ] = F_20 (
V_90 [ V_86 ] . V_92 [
( V_111 - 1 ) - V_104 ] ) ;
}
V_106 -> V_70 = V_90 [ V_86 ] . V_70 ;
V_3 -> V_106 -> V_106 = V_106 ;
break;
}
}
if ( V_86 >= F_17 ( V_90 ) )
F_22 ( V_106 ) ;
}
static int F_24 ( struct V_112 * V_113 ,
struct V_114 * V_115 )
{
V_115 -> type = V_116 ;
V_115 -> V_117 = V_118 ;
V_115 -> V_119 . integer . V_120 = 0 ;
V_115 -> V_119 . integer . V_121 = V_122 ;
return 0 ;
}
static int F_25 ( struct V_112 * V_113 ,
struct V_123 * V_124 )
{
struct V_125 * V_126 = F_26 ( V_113 ) ;
struct V_2 * V_3 = V_126 -> V_127 ;
int V_86 ;
const struct V_105 * V_106 ;
memset ( V_124 -> V_119 . integer . V_119 , 0 ,
sizeof( long ) * V_118 ) ;
F_27 ( & V_3 -> V_128 ) ;
if ( ! V_3 -> V_106 -> V_106 ) {
F_28 ( & V_3 -> V_128 ) ;
return 0 ;
}
V_106 = V_3 -> V_106 -> V_106 ;
for ( V_86 = 0 ; V_86 < V_106 -> V_70 ; V_86 ++ )
V_124 -> V_119 . integer . V_119 [ V_86 ] = V_106 -> V_103 [ V_86 ] ;
F_28 ( & V_3 -> V_128 ) ;
return 0 ;
}
static int F_29 ( struct V_2 * V_3 ,
struct V_129 * V_130 )
{
int V_131 ;
V_131 = F_30 ( V_130 , V_132 ,
NULL , 0 , ( unsigned long ) V_3 ,
& V_3 -> V_106 ) ;
if ( V_131 < 0 )
return V_131 ;
V_3 -> V_106 -> V_127 = V_3 ;
V_3 -> V_106 -> V_133 -> V_126 = F_24 ;
V_3 -> V_106 -> V_133 -> V_134 = F_25 ;
V_3 -> V_106 -> V_106 = NULL ;
return 0 ;
}
static void F_31 ( struct V_1 * V_4 ,
struct V_2 * V_3 )
{
int V_86 ;
union V_135 V_136 = { . V_20 = 0 } ;
union V_137 V_138 = { . V_20 = 0 } ;
union V_139 V_140 = { . V_20 = 0 } ;
T_2 V_141 = 0 ;
T_1 V_142 ;
int V_70 ;
int V_93 ;
V_70 = V_4 -> V_38 -> V_70 ;
F_10 ( V_3 , V_143 , V_136 . V_20 ) ;
V_93 = F_18 ( V_3 , V_70 ) ;
if ( V_3 -> V_83 ) {
V_142 = V_144 ;
V_138 . V_20 = ( V_4 -> V_38 -> V_70 - 1 ) | ( V_93 << 24 ) ;
} else {
V_142 = V_145 ;
V_138 . V_17 . V_146 = V_4 -> V_38 -> V_70 - 1 ;
V_140 . V_17 . V_147 = V_93 ;
for ( V_86 = 0 ; V_86 < V_148 ; V_86 ++ )
V_141 += ( V_142 >> ( V_86 * 8 ) ) & 0xff ;
for ( V_86 = 0 ; V_86 < V_148 ; V_86 ++ )
V_141 += ( V_138 . V_20 >> ( V_86 * 8 ) ) & 0xff ;
for ( V_86 = 0 ; V_86 < V_148 ; V_86 ++ )
V_141 += ( V_140 . V_20 >> ( V_86 * 8 ) ) & 0xff ;
V_138 . V_17 . V_149 = - ( V_141 ) ;
}
F_10 ( V_3 , V_150 , V_142 ) ;
F_10 ( V_3 , V_150 , V_138 . V_20 ) ;
F_10 ( V_3 , V_150 , V_140 . V_20 ) ;
for ( V_86 = 0 ; V_86 < V_151 - V_152 ; V_86 ++ )
F_10 ( V_3 , V_150 , 0x0 ) ;
V_136 . V_17 . V_153 = 1 ;
V_136 . V_17 . V_154 = 1 ;
F_10 ( V_3 , V_143 , V_136 . V_20 ) ;
}
static int F_32 ( T_1 V_155 , T_1 V_156 )
{
T_1 V_157 ;
if ( V_156 == V_158 ) {
switch ( V_155 ) {
case V_40 :
V_157 = V_159 ;
break;
case V_43 :
V_157 = V_160 ;
break;
case V_45 :
V_157 = V_161 ;
break;
case V_47 :
V_157 = V_162 ;
break;
case V_49 :
V_157 = V_163 ;
break;
case V_51 :
V_157 = V_164 ;
break;
case V_165 :
V_157 = V_166 ;
break;
default:
V_157 = - V_55 ;
break;
}
} else if ( V_156 == V_167 ) {
switch ( V_155 ) {
case V_40 :
V_157 = V_168 ;
break;
case V_43 :
V_157 = V_169 ;
break;
case V_45 :
V_157 = V_170 ;
break;
case V_47 :
V_157 = V_171 ;
break;
case V_49 :
V_157 = V_172 ;
break;
case V_51 :
V_157 = V_173 ;
break;
case V_165 :
V_157 = V_174 ;
break;
default:
V_157 = - V_55 ;
break;
}
} else
V_157 = - V_55 ;
return V_157 ;
}
static void F_33 ( T_1 V_155 , T_1 V_175 , T_1 V_156 ,
T_1 V_176 , struct V_2 * V_3 )
{
T_1 V_177 ;
T_3 V_178 , V_179 ;
if ( V_3 -> V_83 ) {
V_177 = F_32 ( V_155 , V_156 ) ;
} else {
V_178 = ( T_3 ) V_175 * V_176 * 1000 ;
V_179 = 128 * V_155 ;
V_177 = F_34 ( V_178 , V_179 ) ;
}
F_19 ( V_3 -> V_98 , L_3 ,
V_175 , V_176 , V_177 ) ;
F_10 ( V_3 , V_180 , ( F_35 ( 24 ) | V_177 ) ) ;
}
static int F_36 ( T_1 V_155 )
{
int V_181 ;
switch ( V_155 ) {
case V_40 :
V_181 = 4096 ;
break;
case V_43 :
V_181 = 6272 ;
break;
case V_45 :
V_181 = 6144 ;
break;
case V_47 :
V_181 = 12544 ;
break;
case V_49 :
V_181 = 12288 ;
break;
case V_51 :
V_181 = 25088 ;
break;
case V_165 :
V_181 = 24576 ;
break;
default:
V_181 = - V_55 ;
break;
}
return V_181 ;
}
static int F_37 ( T_1 V_155 , T_1 * V_176 ,
struct V_2 * V_3 )
{
int V_181 ;
if ( V_3 -> V_83 ) {
V_181 = V_182 ;
} else
V_181 = F_36 ( V_155 ) ;
if ( V_181 < 0 )
return V_181 ;
F_10 ( V_3 , V_183 , ( F_35 ( 24 ) | V_181 ) ) ;
* V_176 = V_181 ;
return 0 ;
}
static void F_38 ( struct V_1 * V_4 ,
struct V_2 * V_3 )
{
int V_184 = V_3 -> V_185 ;
int V_186 = V_3 -> V_187 * V_3 -> V_188 ;
T_1 V_189 = V_4 -> V_38 -> V_190 + V_186 ;
V_189 |= V_191 ;
if ( ! V_4 -> V_38 -> V_192 )
V_189 |= V_193 ;
F_10 ( V_3 , F_39 ( V_184 ) , V_189 ) ;
F_10 ( V_3 , F_40 ( V_184 ) ,
V_3 -> V_188 ) ;
V_3 -> V_185 ++ ;
V_3 -> V_185 %= V_3 -> V_194 ;
V_3 -> V_187 ++ ;
V_3 -> V_187 %= V_4 -> V_38 -> V_195 ;
}
static void F_41 ( struct V_2 * V_3 ,
int V_184 )
{
F_10 ( V_3 , F_39 ( V_184 ) , 0 ) ;
F_10 ( V_3 , F_40 ( V_184 ) , 0 ) ;
}
static void F_42 ( struct V_1 * V_4 ,
struct V_2 * V_3 )
{
struct V_196 * V_38 = V_4 -> V_38 ;
int V_86 , V_197 ;
V_197 = V_38 -> V_195 ;
V_3 -> V_194 = V_120 ( V_197 , V_198 ) ;
V_3 -> V_194 = V_121 ( V_3 -> V_194 , 2U ) ;
V_3 -> V_188 =
F_43 ( V_38 , V_38 -> V_199 ) ;
F_44 ( V_3 -> V_188 & 0x3f ) ;
V_3 -> V_185 = 0 ;
V_3 -> V_200 = 0 ;
V_3 -> V_187 = 0 ;
for ( V_86 = 0 ; V_86 < V_198 ; V_86 ++ ) {
if ( V_86 < V_3 -> V_194 )
F_38 ( V_4 , V_3 ) ;
else
F_41 ( V_3 , V_86 ) ;
}
V_3 -> V_185 = 0 ;
}
static void F_45 ( struct V_1 * V_4 ,
struct V_2 * V_3 )
{
int V_197 = V_4 -> V_38 -> V_195 ;
F_38 ( V_4 , V_3 ) ;
V_3 -> V_200 ++ ;
V_3 -> V_200 %= V_197 ;
}
static int F_46 ( struct V_1 * V_4 ,
struct V_2 * V_3 )
{
int V_201 , V_202 ;
unsigned long V_5 ;
V_202 = 0 ;
F_2 ( & V_3 -> V_6 , V_5 ) ;
for (; ; ) {
F_9 ( V_3 ,
F_40 ( V_3 -> V_185 ) ,
& V_201 ) ;
if ( V_201 < 0 || V_201 > V_3 -> V_188 ) {
F_19 ( V_3 -> V_98 , L_4 ,
V_201 ) ;
V_201 = - V_203 ;
goto V_204;
}
if ( V_201 > 0 )
break;
if ( ++ V_202 >= V_3 -> V_194 ) {
V_201 = - V_203 ;
goto V_204;
}
F_45 ( V_4 , V_3 ) ;
}
V_201 = V_3 -> V_188 - V_201 ;
V_201 += V_3 -> V_188 * V_3 -> V_200 ;
V_204:
F_3 ( & V_3 -> V_6 , V_5 ) ;
return V_201 ;
}
static void F_47 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 )
return;
if ( ! V_3 -> V_14 ) {
F_48 ( V_4 ) ;
goto V_204;
}
if ( F_46 ( V_4 , V_3 ) < 0 )
F_48 ( V_4 ) ;
else
F_49 ( V_4 ) ;
V_204:
F_4 ( V_3 ) ;
}
static void F_50 ( struct V_2 * V_3 )
{
int V_86 ;
T_1 V_13 ;
for ( V_86 = 0 ; V_86 < 100 ; V_86 ++ ) {
F_9 ( V_3 , V_22 , & V_13 ) ;
if ( ! ( V_13 & V_205 ) )
return;
F_51 ( 100 ) ;
F_52 () ;
F_10 ( V_3 , V_22 , V_13 ) ;
}
F_53 ( V_3 -> V_98 , L_5 ) ;
}
static void F_54 ( struct V_2 * V_3 )
{
if ( ! V_3 -> V_206 || ! V_3 -> V_14 )
return;
F_13 ( V_3 ) ;
F_50 ( V_3 ) ;
V_3 -> V_206 = false ;
}
static void F_55 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 ) {
F_48 ( V_4 ) ;
F_4 ( V_3 ) ;
}
V_3 -> V_206 = true ;
}
static int F_56 ( struct V_1 * V_4 )
{
struct V_2 * V_3 ;
struct V_196 * V_38 ;
int V_207 ;
V_3 = F_57 ( V_4 ) ;
V_38 = V_4 -> V_38 ;
F_58 ( V_3 -> V_98 ) ;
V_38 -> V_208 = V_209 ;
V_207 = F_59 ( V_38 ,
V_210 ) ;
if ( V_207 < 0 )
goto error;
V_207 = F_60 ( V_4 -> V_38 , 0 ,
V_211 , 64 ) ;
if ( V_207 < 0 )
goto error;
V_207 = F_61 ( V_38 , 0 , 32 , 24 ) ;
if ( V_207 < 0 )
goto error;
F_62 ( & V_3 -> V_6 ) ;
V_3 -> V_7 . V_4 = V_4 ;
V_3 -> V_7 . V_8 ++ ;
F_63 ( & V_3 -> V_6 ) ;
return V_207 ;
error:
F_64 ( V_3 -> V_98 ) ;
F_65 ( V_3 -> V_98 ) ;
return V_207 ;
}
static int F_66 ( struct V_1 * V_4 )
{
struct V_2 * V_3 ;
V_3 = F_57 ( V_4 ) ;
F_62 ( & V_3 -> V_6 ) ;
V_3 -> V_7 . V_4 = NULL ;
V_3 -> V_7 . V_8 -- ;
while ( V_3 -> V_7 . V_8 > 0 ) {
F_63 ( & V_3 -> V_6 ) ;
F_67 () ;
F_62 ( & V_3 -> V_6 ) ;
}
F_63 ( & V_3 -> V_6 ) ;
F_64 ( V_3 -> V_98 ) ;
F_65 ( V_3 -> V_98 ) ;
return 0 ;
}
static int F_68 ( struct V_1 * V_4 ,
struct V_212 * V_213 )
{
struct V_2 * V_3 ;
unsigned long V_189 ;
int V_214 , V_215 , V_207 ;
V_3 = F_57 ( V_4 ) ;
V_215 = F_69 ( V_213 ) ;
V_207 = F_70 ( V_4 , V_215 ) ;
if ( V_207 < 0 )
return V_207 ;
F_19 ( V_3 -> V_98 , L_6 ,
V_216 , V_215 ) ;
V_189 = ( unsigned long ) V_4 -> V_38 -> V_217 ;
V_214 = ( V_4 -> V_38 -> V_218 + V_219 - 1 ) / V_219 ;
V_207 = F_71 ( V_189 , V_214 ) ;
if ( V_207 ) {
F_53 ( V_3 -> V_98 , L_7 ,
V_207 ) ;
return V_207 ;
}
memset ( V_4 -> V_38 -> V_217 , 0 , V_215 ) ;
return V_207 ;
}
static int F_72 ( struct V_1 * V_4 )
{
struct V_2 * V_3 ;
unsigned long V_189 ;
T_1 V_214 ;
V_3 = F_57 ( V_4 ) ;
F_54 ( V_3 ) ;
if ( V_4 -> V_38 -> V_217 != NULL ) {
V_189 = ( unsigned long ) V_4 -> V_38 -> V_217 ;
V_214 = ( V_4 -> V_38 -> V_218 + V_219 - 1 ) /
V_219 ;
F_73 ( V_189 , V_214 ) ;
return F_74 ( V_4 ) ;
}
return 0 ;
}
static int F_75 ( struct V_1 * V_4 , int V_220 )
{
int V_207 = 0 ;
struct V_2 * V_3 ;
V_3 = F_57 ( V_4 ) ;
F_76 ( & V_3 -> V_6 ) ;
switch ( V_220 ) {
case V_221 :
case V_222 :
case V_223 :
F_12 ( V_3 ) ;
F_11 ( V_3 , true ) ;
break;
case V_224 :
case V_225 :
F_11 ( V_3 , false ) ;
V_3 -> V_206 = true ;
break;
default:
V_207 = - V_55 ;
}
F_77 ( & V_3 -> V_6 ) ;
return V_207 ;
}
static int F_78 ( struct V_1 * V_4 )
{
int V_207 ;
T_1 V_226 , V_176 ;
T_1 V_156 = 0 ;
struct V_2 * V_3 ;
struct V_196 * V_38 ;
V_3 = F_57 ( V_4 ) ;
V_38 = V_4 -> V_38 ;
F_19 ( V_3 -> V_98 , L_8 ,
( int ) F_43 ( V_38 , V_38 -> V_199 ) ) ;
F_19 ( V_3 -> V_98 , L_9 , V_38 -> V_195 ) ;
F_19 ( V_3 -> V_98 , L_10 ,
( int ) F_79 ( V_4 ) ) ;
F_19 ( V_3 -> V_98 , L_11 , V_38 -> V_39 ) ;
F_19 ( V_3 -> V_98 , L_12 , V_38 -> V_70 ) ;
F_54 ( V_3 ) ;
V_226 = V_3 -> V_227 ;
V_207 = F_37 ( V_4 -> V_38 -> V_39 , & V_176 , V_3 ) ;
if ( V_207 ) {
F_53 ( V_3 -> V_98 ,
L_13 , V_207 ) ;
goto V_228;
}
if ( V_3 -> V_83 )
V_156 = V_3 -> V_156 ;
F_33 ( V_4 -> V_38 -> V_39 , V_226 , V_156 ,
V_176 , V_3 ) ;
F_31 ( V_4 , V_3 ) ;
V_207 = F_15 ( V_4 , V_3 ) ;
F_42 ( V_4 , V_3 ) ;
F_10 ( V_3 , V_229 , V_230 ) ;
V_228:
return V_207 ;
}
static T_4 F_80 ( struct V_1 * V_4 )
{
struct V_2 * V_3 ;
int V_201 ;
V_3 = F_57 ( V_4 ) ;
if ( ! V_3 -> V_14 )
return V_231 ;
V_201 = F_46 ( V_4 , V_3 ) ;
if ( V_201 < 0 )
return V_231 ;
V_201 = F_81 ( V_4 -> V_38 , V_201 ) ;
V_201 %= V_4 -> V_38 -> V_232 ;
return V_201 ;
}
static int F_82 ( struct V_1 * V_4 ,
struct V_233 * V_234 )
{
V_234 -> V_235 = F_83 ( V_234 -> V_235 ) ;
return F_84 ( V_234 , V_234 -> V_236 ,
V_4 -> V_237 . V_189 >> V_238 ,
V_234 -> V_239 - V_234 -> V_236 , V_234 -> V_235 ) ;
}
static int F_85 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_207 = 0 ;
T_1 V_226 , V_176 ;
T_1 V_156 = 0 ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 )
return 0 ;
F_11 ( V_3 , false ) ;
V_226 = V_3 -> V_227 ;
V_207 = F_37 ( V_4 -> V_38 -> V_39 , & V_176 , V_3 ) ;
if ( V_207 ) {
F_53 ( V_3 -> V_98 ,
L_13 , V_207 ) ;
goto V_204;
}
if ( V_3 -> V_83 )
V_156 = V_3 -> V_156 ;
F_33 ( V_4 -> V_38 -> V_39 , V_226 , V_156 ,
V_176 , V_3 ) ;
F_11 ( V_3 , true ) ;
V_204:
F_4 ( V_3 ) ;
return V_207 ;
}
static void F_86 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
F_62 ( & V_3 -> V_6 ) ;
if ( V_3 -> V_14 ) {
F_19 ( V_3 -> V_98 , L_14 ) ;
F_63 ( & V_3 -> V_6 ) ;
return;
}
V_3 -> V_14 = true ;
F_19 ( V_3 -> V_98 ,
L_15 ,
V_216 , __LINE__ ) ;
F_63 ( & V_3 -> V_6 ) ;
F_21 ( V_3 ) ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 ) {
F_48 ( V_4 ) ;
F_4 ( V_3 ) ;
}
F_87 ( V_3 -> V_240 , V_241 ) ;
}
static void F_88 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
F_62 ( & V_3 -> V_6 ) ;
if ( ! V_3 -> V_14 ) {
F_19 ( V_3 -> V_98 , L_16 ) ;
F_63 ( & V_3 -> V_6 ) ;
return;
}
F_11 ( V_3 , false ) ;
V_3 -> V_14 = false ;
F_19 ( V_3 -> V_98 ,
L_17 ,
V_216 , __LINE__ ) ;
F_63 ( & V_3 -> V_6 ) ;
F_22 ( V_3 -> V_106 -> V_106 ) ;
V_3 -> V_106 -> V_106 = NULL ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 ) {
F_48 ( V_4 ) ;
F_4 ( V_3 ) ;
}
F_87 ( V_3 -> V_240 , 0 ) ;
}
static int F_89 ( struct V_112 * V_113 ,
struct V_114 * V_115 )
{
V_115 -> type = V_242 ;
V_115 -> V_117 = 1 ;
return 0 ;
}
static int F_90 ( struct V_112 * V_113 ,
struct V_123 * V_124 )
{
struct V_2 * V_3 = F_26 ( V_113 ) ;
F_27 ( & V_3 -> V_128 ) ;
V_124 -> V_119 . V_243 . V_244 [ 0 ] = ( V_3 -> V_33 >> 0 ) & 0xff ;
V_124 -> V_119 . V_243 . V_244 [ 1 ] = ( V_3 -> V_33 >> 8 ) & 0xff ;
V_124 -> V_119 . V_243 . V_244 [ 2 ] =
( V_3 -> V_33 >> 16 ) & 0xff ;
V_124 -> V_119 . V_243 . V_244 [ 3 ] =
( V_3 -> V_33 >> 24 ) & 0xff ;
F_28 ( & V_3 -> V_128 ) ;
return 0 ;
}
static int F_91 ( struct V_112 * V_113 ,
struct V_123 * V_124 )
{
V_124 -> V_119 . V_243 . V_244 [ 0 ] = 0xff ;
V_124 -> V_119 . V_243 . V_244 [ 1 ] = 0xff ;
V_124 -> V_119 . V_243 . V_244 [ 2 ] = 0xff ;
V_124 -> V_119 . V_243 . V_244 [ 3 ] = 0xff ;
return 0 ;
}
static int F_92 ( struct V_112 * V_113 ,
struct V_123 * V_124 )
{
unsigned int V_13 ;
struct V_2 * V_3 = F_26 ( V_113 ) ;
int V_245 = 0 ;
V_13 = ( V_124 -> V_119 . V_243 . V_244 [ 0 ] << 0 ) |
( V_124 -> V_119 . V_243 . V_244 [ 1 ] << 8 ) |
( V_124 -> V_119 . V_243 . V_244 [ 2 ] << 16 ) |
( V_124 -> V_119 . V_243 . V_244 [ 3 ] << 24 ) ;
F_27 ( & V_3 -> V_128 ) ;
if ( V_3 -> V_33 != V_13 ) {
V_3 -> V_33 = V_13 ;
V_245 = 1 ;
}
F_28 ( & V_3 -> V_128 ) ;
return V_245 ;
}
static int F_93 ( struct V_112 * V_113 ,
struct V_114 * V_115 )
{
V_115 -> type = V_246 ;
V_115 -> V_117 = V_247 ;
return 0 ;
}
static int F_94 ( struct V_112 * V_113 ,
struct V_123 * V_124 )
{
struct V_2 * V_3 = F_26 ( V_113 ) ;
F_27 ( & V_3 -> V_128 ) ;
memcpy ( V_124 -> V_119 . V_248 . V_249 , V_3 -> V_95 ,
V_247 ) ;
F_28 ( & V_3 -> V_128 ) ;
return 0 ;
}
static T_5 F_95 ( int V_250 , void * V_251 )
{
struct V_2 * V_9 = V_251 ;
T_1 V_252 ;
V_252 = F_5 ( V_9 , V_22 ) ;
if ( V_252 & V_24 ) {
F_7 ( V_9 , V_22 ,
V_24 ) ;
F_55 ( V_9 ) ;
}
if ( V_252 & V_23 ) {
F_7 ( V_9 , V_22 ,
V_23 ) ;
F_47 ( V_9 ) ;
}
return V_253 ;
}
static void F_96 ( struct V_254 * V_255 )
{
struct V_2 * V_9 = F_97 ( V_255 ) ;
F_98 ( & V_9 -> V_256 ) ;
}
static void F_99 ( struct V_257 * V_258 )
{
struct V_2 * V_9 =
F_100 ( V_258 , struct V_2 , V_256 ) ;
struct V_259 * V_260 = V_9 -> V_98 -> V_261 ;
F_58 ( V_9 -> V_98 ) ;
F_27 ( & V_9 -> V_128 ) ;
if ( ! V_260 -> V_262 ) {
F_19 ( V_9 -> V_98 , L_18 ,
V_216 ) ;
memset ( V_9 -> V_95 , 0 , sizeof( V_9 -> V_95 ) ) ;
F_88 ( V_9 ) ;
} else {
struct V_263 * V_95 = & V_260 -> V_95 ;
F_19 ( V_9 -> V_98 , L_19 ,
V_216 , V_95 -> V_264 , V_260 -> V_227 ) ;
switch ( V_95 -> V_265 ) {
case 0 :
V_9 -> V_12 = V_266 ;
break;
case 1 :
V_9 -> V_12 = V_267 ;
break;
case 2 :
V_9 -> V_12 = V_268 ;
break;
default:
F_19 ( V_9 -> V_98 , L_20 ,
V_95 -> V_265 ) ;
break;
}
memcpy ( V_9 -> V_95 , V_95 -> V_269 , sizeof( V_9 -> V_95 ) ) ;
V_9 -> V_83 = V_260 -> V_83 ;
V_9 -> V_227 = V_260 -> V_227 ;
V_9 -> V_156 = V_260 -> V_156 ;
F_86 ( V_9 ) ;
F_85 ( V_9 ) ;
}
F_28 ( & V_9 -> V_128 ) ;
F_64 ( V_9 -> V_98 ) ;
F_65 ( V_9 -> V_98 ) ;
}
static int F_101 ( struct V_2 * V_9 )
{
int V_131 ;
V_131 = F_102 ( V_9 -> V_270 , L_21 , V_241 , & V_9 -> V_240 ,
true , false ) ;
if ( V_131 < 0 )
return V_131 ;
V_9 -> V_240 -> V_127 = V_9 ;
return 0 ;
}
static int F_103 ( struct V_271 * V_98 )
{
struct V_2 * V_9 = F_104 ( V_98 ) ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_9 ) ;
if ( V_4 ) {
F_105 ( V_4 ) ;
F_4 ( V_9 ) ;
}
return 0 ;
}
static int T_6 F_106 ( struct V_271 * V_98 )
{
struct V_2 * V_9 = F_104 ( V_98 ) ;
int V_131 ;
V_131 = F_103 ( V_98 ) ;
if ( ! V_131 )
F_107 ( V_9 -> V_270 , V_272 ) ;
return V_131 ;
}
static int F_108 ( struct V_271 * V_98 )
{
F_64 ( V_98 ) ;
return 0 ;
}
static int T_6 F_109 ( struct V_271 * V_98 )
{
struct V_2 * V_9 = F_104 ( V_98 ) ;
F_108 ( V_98 ) ;
F_107 ( V_9 -> V_270 , V_273 ) ;
return 0 ;
}
static void F_110 ( struct V_274 * V_270 )
{
struct V_2 * V_9 = V_270 -> V_127 ;
F_111 ( & V_9 -> V_256 ) ;
if ( V_9 -> V_11 )
F_112 ( V_9 -> V_11 ) ;
if ( V_9 -> V_250 >= 0 )
F_113 ( V_9 -> V_250 , V_9 ) ;
}
static int F_114 ( struct V_254 * V_255 )
{
struct V_274 * V_270 ;
struct V_2 * V_9 ;
struct V_129 * V_130 ;
struct V_259 * V_260 ;
int V_250 ;
struct V_275 * V_276 ;
int V_86 , V_277 ;
V_260 = V_255 -> V_98 . V_261 ;
if ( ! V_260 ) {
F_53 ( & V_255 -> V_98 , L_22 , V_216 ) ;
return - V_55 ;
}
V_250 = F_115 ( V_255 , 0 ) ;
if ( V_250 < 0 ) {
F_53 ( & V_255 -> V_98 , L_23 ) ;
return - V_278 ;
}
V_276 = F_116 ( V_255 , V_279 , 0 ) ;
if ( ! V_276 ) {
F_53 ( & V_255 -> V_98 , L_24 ) ;
return - V_280 ;
}
V_277 = F_117 ( & V_255 -> V_98 , V_281 , V_282 ,
V_283 , sizeof( * V_9 ) , & V_270 ) ;
if ( V_277 )
return V_277 ;
V_9 = V_270 -> V_127 ;
F_118 ( & V_9 -> V_6 ) ;
F_119 ( & V_9 -> V_128 ) ;
V_9 -> V_14 = false ;
V_9 -> V_98 = & V_255 -> V_98 ;
V_9 -> V_270 = V_270 ;
V_9 -> V_33 = V_284 ;
strcpy ( V_270 -> V_285 , V_286 ) ;
strcpy ( V_270 -> V_287 , L_25 ) ;
strcpy ( V_270 -> V_288 , L_25 ) ;
V_9 -> V_250 = - 1 ;
V_9 -> V_227 = V_289 ;
F_120 ( & V_9 -> V_256 , F_99 ) ;
V_270 -> V_290 = F_110 ;
V_9 -> V_12 = V_266 ;
F_121 ( V_255 , V_9 ) ;
F_19 ( & V_255 -> V_98 , L_26 ,
V_216 , ( unsigned int ) V_276 -> V_291 ,
( unsigned int ) V_276 -> V_292 ) ;
V_9 -> V_11 = F_122 ( V_276 -> V_291 ,
( V_293 ) ( F_123 ( V_276 ) ) ) ;
if ( ! V_9 -> V_11 ) {
F_53 ( & V_255 -> V_98 , L_27 ) ;
V_277 = - V_294 ;
goto V_131;
}
V_277 = F_124 ( V_250 , F_95 , 0 ,
V_255 -> V_295 , V_9 ) ;
if ( V_277 < 0 ) {
F_53 ( & V_255 -> V_98 , L_28 ) ;
goto V_131;
}
V_9 -> V_250 = V_250 ;
V_277 = F_125 ( V_270 , V_286 , V_296 , V_297 ,
V_298 , & V_130 ) ;
if ( V_277 )
goto V_131;
V_130 -> V_127 = V_9 ;
V_130 -> V_299 = 0 ;
strncpy ( V_130 -> V_295 , V_270 -> V_287 , strlen ( V_270 -> V_287 ) ) ;
F_126 ( V_130 , V_132 , & V_300 ) ;
F_127 ( & V_255 -> V_98 , F_128 ( 32 ) ) ;
F_129 ( & V_255 -> V_98 , F_128 ( 32 ) ) ;
F_130 ( V_130 ,
V_301 , NULL ,
V_302 , V_303 ) ;
for ( V_86 = 0 ; V_86 < F_17 ( V_304 ) ; V_86 ++ ) {
V_277 = F_131 ( V_270 , F_132 ( & V_304 [ V_86 ] , V_9 ) ) ;
if ( V_277 < 0 )
goto V_131;
}
F_16 () ;
V_277 = F_29 ( V_9 , V_130 ) ;
if ( V_277 < 0 )
goto V_131;
V_277 = F_101 ( V_9 ) ;
if ( V_277 < 0 )
goto V_131;
V_277 = F_133 ( V_270 ) ;
if ( V_277 )
goto V_131;
F_62 ( & V_260 -> V_305 ) ;
V_260 -> F_96 = F_96 ;
V_260 -> V_306 = false ;
F_63 ( & V_260 -> V_305 ) ;
F_134 ( & V_255 -> V_98 ) ;
F_64 ( & V_255 -> V_98 ) ;
F_135 ( & V_255 -> V_98 ) ;
F_19 ( & V_255 -> V_98 , L_29 , V_216 ) ;
F_98 ( & V_9 -> V_256 ) ;
return 0 ;
V_131:
F_136 ( V_270 ) ;
return V_277 ;
}
static int F_137 ( struct V_254 * V_255 )
{
struct V_2 * V_9 = F_97 ( V_255 ) ;
F_136 ( V_9 -> V_270 ) ;
return 0 ;
}
