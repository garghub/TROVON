static void F_1 ( void T_1 * V_1 )
{
unsigned long V_2 = V_3 + V_4 ;
while ( F_2 ( V_1 + V_5 ) != 0 )
if ( F_3 ( V_3 , V_2 ) )
return;
if ( F_2 ( V_1 + V_5 ) != 0 )
F_4 ( V_6 L_1 ) ;
}
static void F_5 ( void T_1 * V_1 , T_2 V_7 , T_2 V_8 )
{
unsigned long V_9 ;
F_6 ( & V_10 , V_9 ) ;
F_7 ( V_8 , V_1 + V_11 ) ;
F_7 ( V_7 , V_1 + V_5 ) ;
F_1 ( V_1 ) ;
F_8 ( & V_10 , V_9 ) ;
}
static int F_9 ( void T_1 * V_1 , T_2 V_7 , T_2 V_8 )
{
unsigned long V_9 ;
T_2 V_12 ;
F_6 ( & V_10 , V_9 ) ;
F_7 ( V_8 , V_1 + V_11 ) ;
F_7 ( V_7 , V_1 + V_5 ) ;
F_1 ( V_1 ) ;
V_12 = F_2 ( V_1 + V_11 ) ;
F_8 ( & V_10 , V_9 ) ;
return V_12 ;
}
static void F_10 ( void T_1 * V_1 )
{
T_2 V_13 , V_14 , V_15 , V_16 ;
if ( F_11 ( V_1 + V_17 ) & V_18 ) {
V_13 = F_2 ( V_1 + V_19 ) ;
V_14 = F_2 ( V_1 + V_20 ) ;
V_15 = F_2 ( V_1 + V_21 ) ;
V_16 = ( V_14 - V_13 ) & V_15 ;
if ( V_16 <= V_22 )
F_5 ( V_1 , V_23 , 0 ) ;
}
}
static int F_12 ( struct V_24 * V_25 ,
unsigned int V_7 , unsigned long V_8 )
{
struct V_26 * V_27 = V_25 -> V_28 ;
void T_3 * V_29 = ( void T_3 * ) V_8 ;
int V_30 , V_12 = 0 ;
if ( V_25 -> V_31 == V_32 ) {
if ( V_7 != V_33 && V_7 != V_34 &&
V_7 != V_35 )
return - V_36 ;
} else if ( ! V_27 )
return - V_37 ;
switch ( V_7 ) {
case V_33 :
V_38 . V_39 = V_3 ;
if ( F_13 ( V_29 , & V_38 , sizeof( V_38 ) ) )
V_12 = - V_40 ;
break;
case V_41 :
F_14 ( V_27 , V_8 ) ;
break;
case V_34 : {
struct V_42 T_3 * V_43 = V_29 ;
struct V_42 V_44 ;
struct V_26 * V_45 ;
unsigned int V_46 , V_47 ;
for ( V_46 = 0 ; V_46 < V_48 ; V_46 ++ ) {
V_45 = V_49 [ V_46 ] . V_50 ;
for ( V_47 = 0 ; V_47 < V_51 ; V_47 ++ , V_45 ++ , V_43 ++ ) {
memset ( & V_44 , 0 , sizeof( V_44 ) ) ;
F_15 ( & V_52 ) ;
if ( V_49 [ V_46 ] . V_53 ) {
V_44 . V_54 = F_16 ( V_45 ) ;
V_44 . V_55 = F_17 ( V_45 ) ;
}
F_18 ( & V_52 ) ;
if ( F_13 ( V_43 , & V_44 , sizeof( V_44 ) ) )
return - V_40 ;
}
}
break;
} case V_56 :
V_30 = F_17 ( V_27 ) ;
V_12 = F_19 ( V_30 , ( unsigned long T_3 * ) V_29 ) ;
break;
case V_57 :
V_30 = F_16 ( V_27 ) ;
V_12 = F_19 ( V_30 , ( unsigned long T_3 * ) V_29 ) ;
break;
case V_35 : {
struct V_58 T_3 * V_43 = V_29 ;
struct V_58 V_44 ;
struct V_26 * V_45 ;
unsigned int V_46 , V_47 ;
for ( V_46 = 0 ; V_46 < V_48 ; V_46 ++ ) {
V_45 = V_49 [ V_46 ] . V_50 ;
for ( V_47 = 0 ; V_47 < V_51 ; V_47 ++ , V_45 ++ , V_43 ++ ) {
struct V_24 * V_59 ;
memset ( & V_44 , 0 , sizeof( V_44 ) ) ;
F_15 ( & V_52 ) ;
if ( ! V_49 [ V_46 ] . V_53 ) {
F_18 ( & V_52 ) ;
goto V_60;
}
V_30 = F_20 ( V_45 ) ;
F_18 ( & V_52 ) ;
if ( V_30 & 1 )
V_44 . V_61 = 1 ;
if ( V_30 & 2 )
V_44 . V_62 = 1 ;
if ( V_30 & 4 )
V_44 . V_63 = 1 ;
V_59 = F_21 ( & V_45 -> V_64 ) ;
if ( ! V_59 || ! V_59 -> V_65 )
V_44 . V_66 = V_45 -> V_66 ;
else
V_44 . V_66 = V_59 -> V_65 -> V_67 ;
F_22 ( V_59 ) ;
V_60:
if ( F_13 ( V_43 , & V_44 , sizeof( V_44 ) ) )
return - V_40 ;
}
}
break;
}
case V_68 :
F_23 ( & V_27 -> V_64 . V_69 ) ;
V_12 = F_24 ( V_27 , V_29 ) ;
F_25 ( & V_27 -> V_64 . V_69 ) ;
break;
case V_70 :
F_23 ( & V_27 -> V_64 . V_69 ) ;
V_12 = F_26 ( V_27 , V_29 ) ;
F_25 ( & V_27 -> V_64 . V_69 ) ;
break;
default:
V_12 = - V_71 ;
}
return V_12 ;
}
static int F_27 ( struct V_24 * V_25 , int V_72 )
{
struct V_26 * V_64 = V_25 -> V_28 ;
F_5 ( V_64 -> V_73 , V_72 ? V_74 : V_75 ,
V_76 ) ;
return 0 ;
}
static int F_28 ( struct V_77 * V_78 , T_4 V_79 )
{
switch ( V_78 -> V_80 ) {
case V_81 :
case V_82 :
if ( V_79 != 1 )
goto V_83;
break;
case V_84 :
if ( V_79 != 3 )
goto V_83;
break;
default:
if ( V_79 != 2 )
goto V_83;
break;
}
return 0 ;
V_83:
return - V_36 ;
}
static int F_29 ( const void * V_85 )
{
const T_5 * V_86 = V_85 ;
if ( * V_86 != F_30 ( 0x7980 ) )
return - V_36 ;
return 0 ;
}
static int F_31 ( struct V_77 * V_78 , const T_4 * V_87 ,
T_6 V_16 )
{
void T_1 * V_88 = V_78 -> V_89 ;
T_2 V_44 ;
F_32 ( V_90 , V_88 + V_91 ) ;
F_33 ( 10 ) ;
F_34 ( V_88 , 0 , 4096 ) ;
F_35 ( V_88 , V_87 , V_16 ) ;
F_32 ( 0 , V_88 + V_91 ) ;
F_33 ( 2000 ) ;
switch ( V_78 -> V_80 ) {
case V_81 :
case V_82 :
V_44 = F_2 ( V_88 + V_92 ) ;
if ( V_44 != V_93 )
goto V_83;
break;
case V_84 :
V_44 = F_2 ( V_88 + V_92 ) ;
if ( V_44 != V_94 )
goto V_83;
break;
default:
V_44 = F_2 ( V_88 + V_95 ) ;
if ( V_44 != V_96 )
goto V_83;
V_44 = F_2 ( V_88 + V_97 ) ;
if ( V_44 != V_98 ) {
F_36 ( V_99 L_2
L_3 ) ;
return - V_100 ;
}
break;
}
return 0 ;
V_83:
F_36 ( V_99 L_4 ) ;
return - V_100 ;
}
static int F_37 ( struct V_77 * V_78 , const T_4 * V_85 ,
T_6 V_16 )
{
void T_1 * V_88 = V_78 -> V_89 ;
if ( V_16 < 7168 ) {
F_36 ( V_99 L_5 ) ;
return - V_36 ;
}
F_7 ( V_16 - 7168 - 2 , V_88 + V_101 ) ;
F_32 ( 1 , V_88 + V_91 ) ;
F_35 ( V_88 + V_102 , V_85 , 7168 ) ;
F_32 ( 2 , V_88 + V_91 ) ;
F_35 ( V_88 + V_102 , V_85 + 7168 , V_16 - 7168 ) ;
return 0 ;
}
static int F_38 ( struct V_77 * V_78 , const void * V_85 ,
T_6 V_16 )
{
void T_1 * V_88 = V_78 -> V_89 ;
const T_5 * V_103 = V_85 ;
T_6 V_104 , V_105 , V_47 ;
unsigned long V_106 , V_107 , V_108 , V_109 , V_110 ;
unsigned int V_46 , V_111 ;
T_2 V_112 , V_113 ;
V_113 = ( V_78 -> V_80 == V_84 ) ? V_94 :
V_93 ;
switch ( V_78 -> V_80 ) {
case V_84 :
case V_81 :
case V_82 :
V_106 = V_92 ;
V_107 = V_114 ;
V_108 = V_115 ;
V_109 = V_116 ;
V_110 = V_117 ;
break;
default:
V_106 = V_95 ;
V_113 = V_96 ;
V_107 = V_118 ;
V_108 = V_119 ;
V_109 = V_120 ;
V_110 = V_121 ;
break;
}
V_112 = 0 ;
V_104 = V_16 >> 1 ;
for ( V_46 = 0 ; V_46 < V_104 ; V_46 ++ )
V_112 += F_39 ( V_103 [ V_46 ] ) ;
V_111 = 0 ;
do {
V_104 = V_16 >> 1 ;
V_47 = 0 ;
while ( V_104 ) {
V_105 = ( V_104 > 2048 ) ? 2048 : V_104 ;
V_104 -= V_105 ;
F_35 ( V_88 + V_107 , V_85 + V_47 , V_105 << 1 ) ;
V_47 += V_105 << 1 ;
F_7 ( V_105 , V_88 + V_108 ) ;
F_7 ( 0 , V_88 + V_106 ) ;
for ( V_46 = 0 ; V_46 < 100 ; V_46 ++ ) {
if ( F_2 ( V_88 + V_106 ) == V_113 )
break;
F_33 ( 10 ) ;
}
if ( F_2 ( V_88 + V_106 ) != V_113 )
return - V_100 ;
}
F_7 ( 0 , V_88 + V_108 ) ;
F_7 ( V_112 , V_88 + V_109 ) ;
F_7 ( 0 , V_88 + V_106 ) ;
for ( V_46 = 0 ; V_46 < 100 ; V_46 ++ ) {
if ( F_2 ( V_88 + V_106 ) == V_113 )
break;
F_33 ( 10 ) ;
}
V_111 ++ ;
} while ( ( F_11 ( V_88 + V_110 ) != 1 ) && ( V_111 < 3 ) );
if ( F_11 ( V_88 + V_110 ) != 1 )
return - V_100 ;
F_7 ( 0 , V_88 + V_106 ) ;
for ( V_46 = 0 ; V_46 < 600 ; V_46 ++ ) {
if ( F_2 ( V_88 + V_122 ) == V_76 )
break;
F_33 ( 10 ) ;
}
if ( F_2 ( V_88 + V_122 ) != V_76 )
return - V_100 ;
if ( F_40 ( V_78 ) ) {
if ( V_78 -> V_123 == V_124 ) {
F_7 ( 0x3800 , V_88 + V_125 ) ;
F_7 ( 0x3900 , V_88 + V_126 ) ;
F_7 ( 28499 , V_88 + V_127 ) ;
} else {
F_7 ( 0x3200 , V_88 + V_125 ) ;
F_7 ( 0x3400 , V_88 + V_126 ) ;
F_7 ( 19999 , V_88 + V_127 ) ;
}
}
F_7 ( 1 , V_88 + V_128 ) ;
F_7 ( 0 , V_88 + V_122 ) ;
for ( V_46 = 0 ; V_46 < 500 ; V_46 ++ ) {
if ( F_2 ( V_88 + V_122 ) == V_76 )
break;
F_33 ( 10 ) ;
}
if ( F_2 ( V_88 + V_122 ) != V_76 )
return - V_100 ;
if ( F_40 ( V_78 ) ) {
V_47 = F_2 ( V_88 + V_129 ) ;
if ( V_47 <= 0 )
return - V_100 ;
V_78 -> V_130 = V_47 * 8 ;
F_7 ( V_47 , V_88 + V_131 ) ;
F_7 ( 0 , V_88 + V_122 ) ;
for ( V_46 = 0 ; V_46 < 600 ; V_46 ++ ) {
if ( F_2 ( V_88 + V_122 ) == V_76 )
break;
F_33 ( 10 ) ;
}
if ( F_2 ( V_88 + V_122 ) != V_76 )
return - V_100 ;
}
V_78 -> V_132 = V_88 + V_133 ;
V_78 -> V_134 = V_88 + V_135 ;
V_78 -> V_136 = V_88 + V_137 ;
return 0 ;
}
static int F_41 ( struct V_77 * V_78 , const void * V_85 ,
T_6 V_16 )
{
void T_1 * V_1 , * V_88 = V_78 -> V_89 ;
struct V_26 * V_64 ;
int V_138 , V_46 ;
if ( V_16 % 2 ) {
F_36 ( V_99 L_6 ) ;
return - V_36 ;
}
V_138 = F_38 ( V_78 , V_85 , V_16 ) ;
if ( V_138 )
return V_138 ;
switch ( V_78 -> V_80 ) {
case V_81 :
case V_82 :
case V_84 :
V_64 = V_78 -> V_50 ;
for ( V_46 = 0 ; V_46 < V_78 -> V_130 ; V_46 ++ , V_64 ++ ) {
V_64 -> V_139 = V_78 ;
V_64 -> V_140 = 0 ;
V_64 -> V_73 = V_88 + V_141 +
V_142 * V_46 ;
V_1 = V_64 -> V_73 ;
F_7 ( V_143 , V_1 + V_21 ) ;
F_7 ( V_144 , V_1 + V_145 ) ;
F_7 ( V_146 + V_46 * V_147 , V_1 + V_148 ) ;
F_7 ( F_2 ( V_1 + V_148 ) + V_149 , V_1 + V_150 ) ;
F_7 ( V_151 + V_46 * V_147 , V_1 + V_152 ) ;
F_7 ( F_2 ( V_1 + V_152 ) + V_153 , V_1 + V_154 ) ;
}
break;
default:
V_64 = V_78 -> V_50 ;
for ( V_46 = 0 ; V_46 < V_78 -> V_130 ; V_46 ++ , V_64 ++ ) {
V_64 -> V_139 = V_78 ;
V_64 -> V_140 = 0 ;
V_64 -> V_73 = V_88 + V_141 +
V_142 * V_46 ;
V_1 = V_64 -> V_73 ;
switch ( V_78 -> V_130 ) {
case 8 :
F_7 ( V_155 , V_1 + V_21 ) ;
F_7 ( V_156 , V_1 + V_145 ) ;
F_7 ( V_157 + V_46 * V_158 , V_1 + V_148 ) ;
F_7 ( F_2 ( V_1 + V_148 ) + V_159 , V_1 + V_150 ) ;
F_7 ( V_160 + V_46 * V_158 , V_1 + V_152 ) ;
F_7 ( F_2 ( V_1 + V_152 ) + V_161 , V_1 + V_154 ) ;
break;
case 16 :
F_7 ( V_162 , V_1 + V_21 ) ;
F_7 ( V_163 , V_1 + V_145 ) ;
F_7 ( V_164 + V_46 * V_165 , V_1 + V_148 ) ;
F_7 ( F_2 ( V_1 + V_148 ) + V_166 , V_1 + V_150 ) ;
F_7 ( V_167 + V_46 * V_165 , V_1 + V_152 ) ;
F_7 ( F_2 ( V_1 + V_152 ) + V_168 , V_1 + V_154 ) ;
break;
case 24 :
F_7 ( V_169 , V_1 + V_21 ) ;
F_7 ( V_170 , V_1 + V_145 ) ;
F_7 ( V_171 + V_46 * V_172 , V_1 + V_148 ) ;
F_7 ( F_2 ( V_1 + V_148 ) + V_173 , V_1 + V_150 ) ;
F_7 ( V_174 + V_46 * V_172 , V_1 + V_152 ) ;
F_7 ( F_2 ( V_1 + V_152 ) , V_1 + V_154 ) ;
break;
case 32 :
F_7 ( V_175 , V_1 + V_21 ) ;
F_7 ( V_176 , V_1 + V_145 ) ;
F_7 ( V_177 , V_1 + V_178 ) ;
F_7 ( V_179 + V_46 * V_180 , V_1 + V_148 ) ;
F_7 ( F_11 ( V_1 + V_148 ) , V_1 + V_150 ) ;
F_7 ( V_181 + V_46 * V_180 , V_1 + V_152 ) ;
F_7 ( F_2 ( V_1 + V_152 ) , V_1 + V_154 ) ;
break;
}
}
break;
}
return 0 ;
}
static int F_42 ( struct V_77 * V_78 , const struct V_182 * V_183 )
{
const void * V_85 = V_183 -> V_184 ;
char V_185 [ 64 ] ;
T_2 V_186 [ 5 ] ;
T_6 V_16 ;
unsigned int V_187 , V_188 , V_189 ;
int V_12 = - V_36 ;
struct {
T_7 V_190 ;
T_4 V_191 [ 2 ] ;
T_4 type ;
T_4 V_79 ;
T_4 V_192 [ 8 ] ;
T_5 V_16 [ 5 ] ;
} const * V_193 = V_85 ;
F_43 ( F_44 ( V_193 -> V_16 ) != F_44 ( V_186 ) ) ;
if ( V_183 -> V_194 < V_195 ) {
strcpy ( V_185 , L_7 ) ;
goto V_83;
}
if ( V_193 -> V_190 != F_45 ( 0x30343034 ) ) {
sprintf ( V_185 , L_8 , F_46 ( V_193 -> V_190 ) ) ;
goto V_83;
}
if ( V_193 -> type != 3 ) {
sprintf ( V_185 , L_9 , V_193 -> type ) ;
goto V_83;
}
if ( F_28 ( V_78 , V_193 -> V_79 ) ) {
sprintf ( V_185 , L_10 , V_193 -> V_79 ) ;
goto V_83;
}
V_16 = V_195 ;
V_189 = V_193 -> V_79 == 2 ? 5 : 3 ;
for ( V_187 = 0 ; V_187 < F_44 ( V_186 ) ; V_187 ++ ) {
V_186 [ V_187 ] = F_39 ( V_193 -> V_16 [ V_187 ] ) ;
if ( V_186 [ V_187 ] && V_16 + V_186 [ V_187 ] <= V_183 -> V_194 &&
F_29 ( & V_183 -> V_184 [ V_16 ] ) )
F_36 ( V_6 L_11
L_12 , ( V_196 ) V_16 ) ;
if ( ! V_186 [ V_187 ] && V_187 < V_189 ) {
sprintf ( V_185 , L_13 ) ;
goto V_83;
}
V_16 += V_186 [ V_187 ] ;
}
if ( V_16 != V_183 -> V_194 ) {
sprintf ( V_185 , L_14 , ( V_196 ) V_183 -> V_194 ,
( V_196 ) V_16 ) ;
goto V_83;
}
V_85 += V_195 ;
V_188 = 0 ;
strcpy ( V_185 , L_15 ) ;
V_12 = F_31 ( V_78 , V_85 , V_186 [ V_188 ] ) ;
if ( V_12 )
goto V_83;
V_85 += V_186 [ V_188 ] + V_186 [ V_188 + 1 ] ;
V_188 += 2 ;
if ( V_193 -> V_79 == 2 ) {
V_12 = F_37 ( V_78 , V_85 , V_186 [ V_188 ] ) ;
if ( V_12 )
goto V_83;
V_85 += V_186 [ V_188 ] + V_186 [ V_188 + 1 ] ;
V_188 += 2 ;
}
V_12 = F_41 ( V_78 , V_85 , V_186 [ V_188 ] ) ;
if ( V_12 )
goto V_83;
return 0 ;
V_83:
F_36 ( V_99 L_16 , V_185 ) ;
return V_12 ;
}
static int F_47 ( struct V_77 * V_78 , struct V_197 * V_198 )
{
const struct V_182 * V_183 ;
const char * V_199 ;
struct V_26 * V_45 ;
unsigned int V_46 ;
int V_12 ;
V_78 -> V_50 = F_48 ( V_51 , sizeof( * V_78 -> V_50 ) ,
V_200 ) ;
if ( V_78 -> V_50 == NULL ) {
F_36 ( V_99 L_17 ) ;
V_12 = - V_201 ;
goto V_83;
}
for ( V_46 = 0 , V_45 = V_78 -> V_50 ; V_46 < V_51 ; V_46 ++ , V_45 ++ ) {
F_49 ( & V_45 -> V_64 ) ;
V_45 -> V_64 . V_202 = & V_203 ;
V_45 -> type = V_204 ;
V_45 -> V_66 = V_205 | V_206 | V_207 | V_208 | V_209 ;
}
switch ( V_78 -> V_80 ) {
case V_81 :
case V_82 :
V_199 = L_18 ;
break;
case V_84 :
V_199 = L_19 ;
break;
default:
V_199 = L_20 ;
break;
}
V_12 = F_50 ( & V_183 , V_199 , V_198 ) ;
if ( V_12 ) {
F_36 ( V_99 L_21
L_22
L_23 ,
V_199 ) ;
goto V_210;
}
V_12 = F_42 ( V_78 , V_183 ) ;
F_51 ( V_183 ) ;
if ( V_12 )
goto V_210;
F_15 ( & V_52 ) ;
V_78 -> V_53 = 1 ;
if ( ! F_52 ( & V_211 ) )
F_53 ( & V_211 , V_3 + V_212 / 50 ) ;
F_18 ( & V_52 ) ;
return 0 ;
V_210:
F_54 ( V_78 -> V_50 ) ;
V_83:
return V_12 ;
}
static void F_55 ( struct V_77 * V_78 )
{
unsigned int V_187 , V_213 ;
F_23 ( & V_214 ) ;
F_15 ( & V_52 ) ;
V_78 -> V_53 = 0 ;
F_18 ( & V_52 ) ;
for ( V_187 = 0 ; V_187 < V_78 -> V_130 ; V_187 ++ )
if ( V_78 -> V_50 [ V_187 ] . V_64 . V_9 & V_215 ) {
struct V_24 * V_25 = F_21 (
& V_78 -> V_50 [ V_187 ] . V_64 ) ;
if ( V_25 ) {
F_56 ( V_25 ) ;
F_22 ( V_25 ) ;
}
}
while ( 1 ) {
V_213 = 0 ;
for ( V_187 = 0 ; V_187 < V_78 -> V_130 ; V_187 ++ )
if ( V_78 -> V_50 [ V_187 ] . V_64 . V_9 & V_215 )
V_213 ++ ;
F_25 ( & V_214 ) ;
if ( ! V_213 )
break;
F_33 ( 50 ) ;
F_23 ( & V_214 ) ;
}
F_57 ( V_78 -> V_89 ) ;
V_78 -> V_89 = NULL ;
F_54 ( V_78 -> V_50 ) ;
}
static int T_8 F_58 ( struct V_216 * V_217 ,
const struct V_218 * V_219 )
{
struct V_77 * V_139 ;
unsigned int V_46 ;
int V_220 = V_219 -> V_28 ;
int V_138 ;
V_138 = F_59 ( V_217 ) ;
if ( V_138 ) {
F_60 ( & V_217 -> V_198 , L_24 ) ;
goto V_83;
}
for ( V_46 = 0 ; V_46 < V_48 ; V_46 ++ )
if ( V_49 [ V_46 ] . V_89 == NULL )
break;
V_138 = - V_37 ;
if ( V_46 >= V_48 ) {
F_61 ( & V_217 -> V_198 , L_25
L_26 , V_48 ) ;
goto V_83;
}
V_139 = & V_49 [ V_46 ] ;
V_138 = F_62 ( V_217 , 2 , L_27 ) ;
if ( V_138 ) {
F_60 ( & V_217 -> V_198 , L_28 ) ;
goto V_83;
}
V_139 -> V_89 = F_63 ( F_64 ( V_217 , 2 ) , 0x4000 ) ;
if ( V_139 -> V_89 == NULL ) {
F_60 ( & V_217 -> V_198 , L_29 ) ;
goto V_221;
}
V_139 -> V_80 = V_220 ;
switch ( V_220 ) {
case V_81 :
case V_82 :
V_139 -> V_130 = 8 ;
break;
case V_84 :
V_139 -> V_130 = 4 ;
break;
default:
V_139 -> V_130 = 0 ;
break;
}
V_139 -> V_123 = V_124 ;
V_138 = F_47 ( V_139 , & V_217 -> V_198 ) ;
if ( V_138 )
goto V_222;
F_65 ( V_217 , V_139 ) ;
F_66 ( & V_217 -> V_198 , L_30 ,
V_223 [ V_220 - 1 ] , V_139 -> V_130 ) ;
return 0 ;
V_222:
F_57 ( V_139 -> V_89 ) ;
V_139 -> V_89 = NULL ;
V_221:
F_67 ( V_217 , 2 ) ;
V_83:
return V_138 ;
}
static void T_9 F_68 ( struct V_216 * V_217 )
{
struct V_77 * V_78 = F_69 ( V_217 ) ;
F_55 ( V_78 ) ;
F_67 ( V_217 , 2 ) ;
}
static int T_10 F_70 ( void )
{
unsigned int V_224 = 0 ;
int V_138 = 0 ;
struct V_77 * V_78 = V_49 ;
unsigned int V_46 ;
F_36 ( V_225 L_31 ,
V_226 ) ;
V_227 = F_71 ( V_32 + 1 ) ;
if ( ! V_227 )
return - V_201 ;
V_227 -> V_228 = L_32 ;
V_227 -> V_229 = V_230 ;
V_227 -> V_231 = 0 ;
V_227 -> type = V_232 ;
V_227 -> V_233 = V_234 ;
V_227 -> V_235 = V_236 ;
V_227 -> V_235 . V_67 = V_205 | V_206 | V_207 | V_208 | V_209 ;
V_227 -> V_235 . V_237 = 9600 ;
V_227 -> V_235 . V_238 = 9600 ;
V_227 -> V_9 = V_239 ;
F_72 ( V_227 , & V_240 ) ;
if ( F_73 ( V_227 ) ) {
F_36 ( V_99 L_33 ) ;
F_74 ( V_227 ) ;
return - 1 ;
}
for ( V_46 = 0 ; V_46 < V_48 ; V_46 ++ ) {
if ( ! V_241 [ V_46 ] )
break;
if ( type [ V_46 ] == V_81 ||
type [ V_46 ] == V_242 ) {
F_75 ( L_34 ,
V_224 + 1 , V_223 [ type [ V_46 ] - 1 ] ,
V_241 [ V_46 ] ) ;
V_78 -> V_80 = type [ V_46 ] ;
V_78 -> V_130 = type [ V_46 ] == V_81 ? 8 :
V_243 [ V_46 ] ;
V_78 -> V_123 = V_244 ;
V_78 -> V_89 = F_63 ( V_241 [ V_46 ] , 0x4000 ) ;
if ( ! V_78 -> V_89 ) {
F_36 ( V_99 L_35 ,
V_241 [ V_46 ] ) ;
continue;
}
if ( F_47 ( V_78 , NULL ) ) {
F_57 ( V_78 -> V_89 ) ;
V_78 -> V_89 = NULL ;
continue;
}
F_36 ( V_225 L_36
L_37 ,
V_241 [ V_46 ] , V_78 -> V_130 ) ;
V_78 ++ ;
V_224 ++ ;
}
}
#ifdef F_76
V_138 = F_77 ( & V_245 ) ;
if ( V_138 ) {
F_36 ( V_99 L_38 ) ;
if ( V_224 )
V_138 = 0 ;
}
#endif
return V_138 ;
}
static void T_11 F_78 ( void )
{
unsigned int V_46 ;
#ifdef F_76
F_79 ( & V_245 ) ;
#endif
for ( V_46 = 0 ; V_46 < V_48 ; V_46 ++ )
if ( V_49 [ V_46 ] . V_53 )
F_55 ( & V_49 [ V_46 ] ) ;
F_80 ( & V_211 ) ;
if ( F_81 ( V_227 ) )
F_36 ( V_99 L_39
L_40 ) ;
F_74 ( V_227 ) ;
}
static void F_82 ( struct V_246 * V_64 )
{
struct V_26 * V_27 = F_83 ( V_64 , struct V_26 , V_64 ) ;
F_84 ( V_27 ) ;
F_14 ( V_27 , 2 ) ;
}
static int F_85 ( struct V_246 * V_64 )
{
struct V_26 * V_27 = F_83 ( V_64 , struct V_26 , V_64 ) ;
int V_63 ;
F_86 ( & V_64 -> V_247 ) ;
V_63 = V_27 -> V_140 ;
F_87 ( & V_64 -> V_247 ) ;
return V_63 ;
}
static void F_88 ( struct V_246 * V_64 , int V_248 )
{
struct V_26 * V_27 = F_83 ( V_64 , struct V_26 , V_64 ) ;
F_89 ( V_27 , V_248 , V_248 ) ;
}
static int F_90 ( struct V_24 * V_25 , struct V_199 * V_249 )
{
struct V_77 * V_78 ;
struct V_26 * V_27 ;
int V_64 ;
V_64 = V_25 -> V_31 ;
if ( V_64 == V_32 ) {
return F_91 ( V_250 ) ? 0 : - V_251 ;
}
if ( F_92 ( & V_214 ) )
return - V_252 ;
V_78 = & V_49 [ V_64 / V_51 ] ;
if ( ! V_78 -> V_53 ) {
F_25 ( & V_214 ) ;
return - V_37 ;
}
if ( V_64 % V_51 >= V_78 -> V_130 ) {
F_25 ( & V_214 ) ;
return - V_37 ;
}
V_27 = & V_78 -> V_50 [ V_64 % V_51 ] ;
V_27 -> V_64 . V_253 ++ ;
V_25 -> V_28 = V_27 ;
F_93 ( & V_27 -> V_64 , V_25 ) ;
F_23 ( & V_27 -> V_64 . V_69 ) ;
if ( ! ( V_27 -> V_64 . V_9 & V_215 ) ) {
V_27 -> V_254 = 0 ;
F_94 ( V_25 , V_25 -> V_65 ) ;
F_89 ( V_27 , 1 , 1 ) ;
F_95 ( V_27 ) ;
F_96 ( V_27 , V_27 -> type == V_204 ) ;
V_27 -> V_64 . V_9 |= V_215 ;
}
F_25 ( & V_27 -> V_64 . V_69 ) ;
F_25 ( & V_214 ) ;
return F_97 ( & V_27 -> V_64 , V_25 , V_249 ) ;
}
static void F_98 ( struct V_24 * V_25 , struct V_199 * V_249 )
{
struct V_26 * V_27 = V_25 -> V_28 ;
V_27 -> V_66 = V_25 -> V_65 -> V_67 ;
F_99 ( & V_27 -> V_64 , V_25 , V_249 ) ;
}
static int F_100 ( struct V_24 * V_25 ,
const unsigned char * V_87 , int V_253 )
{
struct V_26 * V_27 = V_25 -> V_28 ;
unsigned long V_9 ;
int V_16 ;
if ( V_27 == NULL )
return 0 ;
F_6 ( & V_52 , V_9 ) ;
V_16 = F_101 ( V_25 , V_87 , V_253 ) ;
F_8 ( & V_52 , V_9 ) ;
F_102 ( V_255 , & V_27 -> V_254 ) ;
return V_16 ;
}
static int F_103 ( struct V_24 * V_25 )
{
struct V_26 * V_27 ;
if ( V_25 -> V_256 )
return 0 ;
V_27 = V_25 -> V_28 ;
if ( V_27 == NULL )
return 0 ;
return F_104 ( V_27 ) ;
}
static void F_105 ( struct V_24 * V_25 )
{
struct V_26 * V_27 = V_25 -> V_28 ;
if ( V_27 == NULL )
return;
F_14 ( V_27 , 1 ) ;
F_106 ( V_25 ) ;
}
static int F_107 ( struct V_24 * V_25 )
{
struct V_26 * V_27 = V_25 -> V_28 ;
int V_257 ;
V_257 = F_17 ( V_27 ) ;
if ( V_257 )
F_102 ( V_258 , & V_27 -> V_254 ) ;
return V_257 ;
}
static int F_108 ( struct V_24 * V_25 )
{
struct V_26 * V_27 = V_25 -> V_28 ;
int V_259 = 0 , V_260 , V_261 ;
F_109 ( V_27 , & V_260 , & V_261 ) ;
if ( V_260 )
V_259 |= V_262 ;
if ( V_261 )
V_259 |= V_263 ;
V_260 = F_20 ( V_27 ) ;
if ( V_260 & 1 )
V_259 |= V_264 ;
if ( V_260 & 2 )
V_259 |= V_265 ;
if ( V_260 & 4 )
V_259 |= V_266 ;
return V_259 ;
}
static int F_110 ( struct V_24 * V_25 ,
unsigned int V_267 , unsigned int V_268 )
{
struct V_26 * V_27 ;
int V_260 , V_261 ;
F_23 ( & V_214 ) ;
V_27 = V_25 -> V_28 ;
if ( ! V_27 ) {
F_25 ( & V_214 ) ;
return - V_36 ;
}
F_109 ( V_27 , & V_260 , & V_261 ) ;
if ( V_267 & V_263 )
V_261 = 1 ;
if ( V_267 & V_262 )
V_260 = 1 ;
if ( V_268 & V_263 )
V_261 = 0 ;
if ( V_268 & V_262 )
V_260 = 0 ;
F_89 ( V_27 , V_260 , V_261 ) ;
F_25 ( & V_214 ) ;
return 0 ;
}
static void F_111 ( struct V_24 * V_25 ,
struct V_269 * V_270 )
{
struct V_26 * V_27 = V_25 -> V_28 ;
if ( V_27 == NULL )
return;
F_94 ( V_25 , V_270 ) ;
if ( ! ( V_270 -> V_67 & V_208 ) && F_112 ( V_25 ) )
F_113 ( & V_27 -> V_64 . V_271 ) ;
}
static void F_114 ( struct V_24 * V_25 )
{
struct V_26 * V_27 = V_25 -> V_28 ;
if ( V_27 == NULL )
return;
F_115 ( V_27 ) ;
F_102 ( V_272 , & V_27 -> V_254 ) ;
}
static void F_116 ( struct V_24 * V_25 )
{
struct V_26 * V_27 = V_25 -> V_28 ;
if ( V_27 == NULL )
return;
if ( ! F_117 ( V_272 , & V_27 -> V_254 ) )
return;
F_118 ( V_27 ) ;
F_119 ( V_272 , & V_27 -> V_254 ) ;
}
static void F_120 ( struct V_24 * V_25 )
{
struct V_26 * V_27 = V_25 -> V_28 ;
F_121 ( & V_27 -> V_64 ) ;
}
static void F_122 ( struct V_26 * V_45 , T_4 V_63 )
{
struct V_24 * V_25 ;
unsigned long V_9 ;
V_63 = ! ! V_63 ;
F_6 ( & V_45 -> V_64 . V_247 , V_9 ) ;
if ( V_63 != V_45 -> V_140 ) {
V_45 -> V_140 = V_63 ;
F_8 ( & V_45 -> V_64 . V_247 , V_9 ) ;
V_25 = F_21 ( & V_45 -> V_64 ) ;
if ( V_25 && F_112 ( V_25 ) && ! V_63 )
F_56 ( V_25 ) ;
F_22 ( V_25 ) ;
}
else
F_8 ( & V_45 -> V_64 . V_247 , V_9 ) ;
}
static int F_123 ( struct V_26 * V_45 , unsigned int V_273 ,
T_2 T_1 * V_274 )
{
struct V_24 * V_25 = F_21 ( & V_45 -> V_64 ) ;
void T_1 * V_1 ;
unsigned int V_275 = V_45 -> V_64 . V_9 & V_215 ;
T_2 V_276 ;
if ( V_25 ) {
if ( F_117 ( V_258 , & V_45 -> V_254 ) &&
F_17 ( V_45 ) == 0 ) {
F_119 ( V_258 , & V_45 -> V_254 ) ;
F_106 ( V_25 ) ;
}
if ( F_117 ( V_255 , & V_45 -> V_254 ) && ! V_25 -> V_256 &&
F_17 ( V_45 ) <= V_277 ) {
F_119 ( V_255 , & V_45 -> V_254 ) ;
F_106 ( V_25 ) ;
}
if ( V_275 && ! F_117 ( V_278 , & V_25 -> V_9 ) &&
F_16 ( V_45 ) > 0 ) {
F_124 ( V_45 ) ;
F_125 ( V_25 ) ;
}
} else {
F_119 ( V_258 , & V_45 -> V_254 ) ;
F_14 ( V_45 , 0 ) ;
}
if ( ! V_273 )
goto V_279;
V_276 = F_2 ( V_274 ) ;
if ( V_276 == 0 )
goto V_279;
F_7 ( 0 , V_274 ) ;
V_1 = V_45 -> V_73 ;
if ( V_276 & V_280 )
F_7 ( F_2 ( V_1 + V_281 ) & ~ V_282 ,
V_1 + V_281 ) ;
if ( ! V_275 )
goto V_279;
if ( V_25 && ( V_276 & V_283 ) && ! F_126 ( V_25 ) ) {
F_127 ( V_25 , 0 , V_284 ) ;
F_125 ( V_25 ) ;
}
if ( V_276 & V_285 )
F_122 ( V_45 , F_11 ( V_1 + V_17 ) & V_286 ) ;
V_279:
F_22 ( V_25 ) ;
return 0 ;
}
static void F_128 ( unsigned long V_287 )
{
struct V_77 * V_78 ;
T_2 T_1 * V_274 ;
unsigned int V_288 , V_64 , V_289 = 0 ;
F_129 ( & V_52 ) ;
for ( V_288 = 0 ; V_288 < V_48 ; V_288 ++ ) {
V_78 = & V_49 [ V_288 ] ;
if ( ! V_78 -> V_53 )
continue;
V_289 ++ ;
V_274 = NULL ;
if ( F_11 ( V_78 -> V_134 ) == 0xff )
V_274 = V_78 -> V_136 + F_11 ( V_78 -> V_132 ) ;
for ( V_64 = 0 ; V_64 < V_78 -> V_130 ; V_64 ++ )
F_123 ( & V_78 -> V_50 [ V_64 ] , ! ! V_274 , V_274 + V_64 ) ;
if ( V_274 )
F_32 ( 0 , V_78 -> V_134 ) ;
if ( V_290 ) {
struct V_26 * V_45 = V_78 -> V_50 ;
for ( V_64 = 0 ; V_64 < V_78 -> V_130 ; V_64 ++ , V_45 ++ )
if ( V_45 -> V_291 ) {
V_45 -> V_291 = 0 ;
F_10 ( V_45 -> V_73 ) ;
}
}
}
V_290 = 0 ;
if ( V_289 )
F_53 ( & V_211 , V_3 + V_212 / 50 ) ;
F_130 ( & V_52 ) ;
}
static void F_94 ( struct V_24 * V_25 , struct V_269 * V_270 )
{
register struct V_269 * V_292 = V_25 -> V_65 ;
struct V_26 * V_27 = V_25 -> V_28 ;
int V_261 , V_61 , V_293 , V_294 , V_295 , V_296 ;
V_261 = V_61 = V_293 = V_294 = V_295 = 0 ;
if ( V_292 -> V_67 & V_297 )
V_261 = V_61 = 1 ;
if ( V_292 -> V_298 & V_299 )
V_293 = 1 ;
if ( V_292 -> V_298 & V_300 )
V_294 = 1 ;
if ( V_292 -> V_298 & V_301 )
V_295 = 1 ;
V_292 -> V_67 &= ~ V_302 ;
F_131 ( V_27 , V_261 , V_61 , V_293 , V_294 , V_295 ) ;
V_296 = F_132 ( V_27 , V_292 , F_133 ( V_25 ) ) ;
if ( V_296 == - 1 )
V_296 = F_134 ( V_270 ) ;
F_135 ( V_25 , V_296 , V_296 ) ;
}
static void F_14 ( struct V_26 * V_64 , int V_303 )
{
void T_1 * V_1 ;
if ( V_303 < 0 || V_303 > 2 )
return;
V_1 = V_64 -> V_73 ;
F_5 ( V_1 , V_304 , V_303 ) ;
if ( V_303 != 1 ) {
V_64 -> V_291 = 0 ;
F_10 ( V_1 ) ;
}
}
static void F_95 ( struct V_26 * V_64 )
{
void T_1 * V_1 ;
T_2 V_305 = 512 ;
V_1 = V_64 -> V_73 ;
F_7 ( V_305 , V_1 + V_22 ) ;
if ( F_40 ( V_64 -> V_139 ) )
F_5 ( V_1 , V_306 , 0 ) ;
else
F_7 ( F_2 ( V_1 + V_281 ) | V_307 ,
V_1 + V_281 ) ;
F_5 ( V_1 , V_308 , V_76 ) ;
F_5 ( V_1 , V_304 , 2 ) ;
F_5 ( V_1 , V_309 , V_76 ) ;
F_20 ( V_64 ) ;
}
static void F_84 ( struct V_26 * V_64 )
{
void T_1 * V_1 = V_64 -> V_73 ;
F_5 ( V_1 , V_310 , 0 ) ;
F_5 ( V_1 , V_311 , V_76 ) ;
F_7 ( 0 , V_1 + V_281 ) ;
F_5 ( V_1 , V_312 , V_76 ) ;
}
static T_12 F_136 ( struct V_26 * V_64 , T_12 V_296 )
{
void T_1 * V_1 = V_64 -> V_73 ;
unsigned int clock , V_313 ;
T_12 V_314 ;
V_314 = F_40 ( V_64 -> V_139 ) ? 460800 : 921600 ;
if ( V_296 < 50 )
return 0 ;
if ( V_296 > V_314 )
V_296 = V_314 ;
clock = 921600 ;
V_313 = clock / V_296 ;
F_5 ( V_1 , V_315 , V_313 ) ;
V_296 = clock / V_313 ;
return V_296 ;
}
static int F_132 ( struct V_26 * V_64 , struct V_269 * V_316 ,
T_12 V_296 )
{
void T_1 * V_1 ;
T_13 V_303 = 0 ;
V_1 = V_64 -> V_73 ;
V_303 = V_316 -> V_67 & V_317 ;
if ( V_303 == V_318 )
V_303 = V_319 ;
else if ( V_303 == V_320 )
V_303 = V_321 ;
else if ( V_303 == V_322 )
V_303 = V_323 ;
else if ( V_303 == V_206 )
V_303 = V_324 ;
if ( V_316 -> V_67 & V_325 ) {
if ( V_303 == V_319 )
V_303 |= V_326 ;
else
V_303 |= V_327 ;
} else
V_303 |= V_328 ;
if ( V_316 -> V_67 & V_329 ) {
if ( V_316 -> V_67 & V_330 )
V_303 |= V_331 ;
else
V_303 |= V_332 ;
} else
V_303 |= V_333 ;
F_5 ( V_1 , V_334 , ( T_2 ) V_303 ) ;
if ( F_40 ( V_64 -> V_139 ) && V_296 >= 921600 )
return - 1 ;
V_296 = F_136 ( V_64 , V_296 ) ;
if ( V_316 -> V_298 & ( V_299 | V_300 | V_301 ) ) {
F_86 ( & V_10 ) ;
F_32 ( V_316 -> V_335 [ V_336 ] , V_1 + V_11 ) ;
F_32 ( V_316 -> V_335 [ V_337 ] , V_1 + V_338 ) ;
F_32 ( V_339 , V_1 + V_5 ) ;
F_1 ( V_1 ) ;
F_87 ( & V_10 ) ;
}
return V_296 ;
}
static int F_109 ( struct V_26 * V_64 , int * V_340 ,
int * V_341 )
{
if ( V_340 )
* V_340 = ! ! ( V_64 -> V_342 & V_343 ) ;
if ( V_341 )
* V_341 = ! ! ( V_64 -> V_342 & V_344 ) ;
return 0 ;
}
static void F_89 ( struct V_26 * V_64 , int V_260 , int V_261 )
{
T_4 V_303 = 0 ;
if ( V_260 )
V_303 |= V_343 ;
if ( V_261 )
V_303 |= V_344 ;
V_64 -> V_342 = V_303 ;
F_5 ( V_64 -> V_73 , V_345 , V_303 ) ;
}
static void F_131 ( struct V_26 * V_64 , int V_261 , int V_61 ,
int V_293 , int V_294 , int V_346 )
{
int V_303 = 0 ;
if ( V_261 )
V_303 |= V_347 ;
if ( V_61 )
V_303 |= V_348 ;
if ( V_293 )
V_303 |= V_349 ;
if ( V_294 )
V_303 |= V_350 ;
if ( V_346 )
V_303 |= V_351 ;
F_5 ( V_64 -> V_73 , V_310 , V_303 ) ;
}
static int F_20 ( struct V_26 * V_64 )
{
void T_1 * V_1 ;
int V_313 ;
V_1 = V_64 -> V_73 ;
if ( F_40 ( V_64 -> V_139 ) )
V_313 = F_9 ( V_1 , V_352 , 0 ) ;
else
V_313 = F_2 ( V_1 + V_17 ) >> 4 ;
V_313 &= 0x0B ;
if ( V_313 & 8 )
V_313 |= 4 ;
F_122 ( V_64 , V_313 & 8 ) ;
V_313 &= 7 ;
return V_313 ;
}
static int F_101 ( struct V_24 * V_25 ,
const unsigned char * V_353 , int V_16 )
{
struct V_26 * V_64 = V_25 -> V_28 ;
void T_1 * V_88 , * V_1 , * V_354 ;
unsigned int V_355 , V_356 ;
T_2 V_357 , V_358 , V_359 , V_360 , V_361 ;
T_2 V_362 , V_363 , V_364 ;
V_1 = V_64 -> V_73 ;
V_88 = V_64 -> V_139 -> V_89 ;
V_359 = F_2 ( V_1 + V_145 ) ;
V_360 = F_2 ( V_1 + V_152 ) ;
V_361 = F_2 ( V_1 + V_154 ) ;
V_358 = F_2 ( V_1 + V_365 ) ;
V_357 = F_2 ( V_1 + V_366 ) ;
V_355 = ( V_357 > V_358 ) ? ( V_357 - V_358 - 1 ) : ( V_357 - V_358 + V_359 ) ;
if ( V_355 > V_16 )
V_355 = V_16 ;
V_38 . V_367 [ V_64 -> V_64 . V_25 -> V_31 ] += V_355 ;
V_356 = V_355 ;
if ( V_360 == V_361 ) {
V_364 = F_2 ( V_1 + V_178 ) ;
F_7 ( V_360 , V_88 + V_91 ) ;
while ( V_355 > 0 ) {
if ( V_357 > V_358 )
V_16 = V_357 - V_358 - 1 ;
else
V_16 = V_359 + 1 - V_358 ;
V_16 = ( V_355 > V_16 ) ? V_16 : V_355 ;
V_354 = V_88 + V_102 + V_364 + V_358 ;
F_35 ( V_354 , V_353 , V_16 ) ;
V_353 += V_16 ;
V_358 = ( V_358 + V_16 ) & V_359 ;
V_355 -= V_16 ;
}
} else {
V_362 = V_360 + ( V_358 >> 13 ) ;
V_363 = V_358 & V_368 ;
while ( V_355 > 0 ) {
V_16 = V_369 - V_363 ;
if ( V_16 > V_355 )
V_16 = V_355 ;
F_32 ( V_362 , V_88 + V_91 ) ;
V_354 = V_88 + V_102 + V_363 ;
F_35 ( V_354 , V_353 , V_16 ) ;
V_353 += V_16 ;
if ( ++ V_362 == V_361 )
V_362 = V_360 ;
V_363 = 0 ;
V_355 -= V_16 ;
}
V_358 = ( V_358 + V_356 ) & V_359 ;
}
F_7 ( V_358 , V_1 + V_365 ) ;
F_32 ( 1 , V_1 + V_370 ) ;
return V_356 ;
}
static int F_124 ( struct V_26 * V_64 )
{
struct V_24 * V_25 = V_64 -> V_64 . V_25 ;
unsigned char * V_371 ;
void T_1 * V_88 , * V_1 , * V_354 ;
unsigned int V_253 , V_16 , V_356 ;
T_2 V_358 , V_372 , V_360 , V_361 ;
T_2 V_362 , V_363 , V_364 , V_357 ;
V_1 = V_64 -> V_73 ;
V_88 = V_64 -> V_139 -> V_89 ;
V_357 = F_2 ( V_1 + V_19 ) ;
V_358 = F_2 ( V_1 + V_20 ) ;
V_372 = F_2 ( V_1 + V_21 ) ;
V_360 = F_2 ( V_1 + V_148 ) ;
V_361 = F_2 ( V_1 + V_150 ) ;
V_253 = ( V_358 >= V_357 ) ? ( V_358 - V_357 ) : ( V_358 - V_357 + V_372 + 1 ) ;
if ( V_253 == 0 )
return 0 ;
V_356 = V_253 ;
V_38 . V_373 [ V_25 -> V_31 ] += V_356 ;
if ( V_360 == V_361 ) {
V_364 = F_2 ( V_1 + V_374 ) ;
F_7 ( V_360 , V_88 + V_91 ) ;
while ( V_253 > 0 ) {
V_354 = V_88 + V_102 + V_364 + V_357 ;
V_16 = ( V_358 >= V_357 ) ? ( V_358 - V_357 ) :
( V_372 + 1 - V_357 ) ;
V_16 = F_137 ( V_25 , & V_371 ,
F_138 ( V_16 , V_253 ) ) ;
F_139 ( V_371 , V_354 , V_16 ) ;
V_357 = ( V_357 + V_16 ) & V_372 ;
V_253 -= V_16 ;
}
} else {
V_362 = V_360 + ( V_357 >> 13 ) ;
V_363 = V_357 & V_368 ;
while ( V_253 > 0 ) {
F_7 ( V_362 , V_88 + V_91 ) ;
V_354 = V_88 + V_102 + V_363 ;
V_16 = F_137 ( V_25 , & V_371 ,
F_138 ( V_369 - V_363 , V_253 ) ) ;
F_139 ( V_371 , V_354 , V_16 ) ;
V_253 -= V_16 ;
V_363 = ( V_363 + V_16 ) & V_368 ;
if ( V_363 == 0 && ++ V_362 == V_361 )
V_362 = V_360 ;
}
V_357 = ( V_357 + V_356 ) & V_372 ;
}
F_7 ( V_357 , V_1 + V_19 ) ;
if ( F_11 ( V_1 + V_17 ) & V_18 ) {
V_290 = 1 ;
V_64 -> V_291 = 1 ;
}
return V_356 ;
}
static int F_17 ( struct V_26 * V_64 )
{
void T_1 * V_1 = V_64 -> V_73 ;
T_2 V_13 , V_14 , V_15 ;
V_13 = F_2 ( V_1 + V_366 ) ;
V_14 = F_2 ( V_1 + V_365 ) ;
V_15 = F_2 ( V_1 + V_145 ) ;
return ( V_14 - V_13 ) & V_15 ;
}
static int F_104 ( struct V_26 * V_64 )
{
void T_1 * V_1 = V_64 -> V_73 ;
T_2 V_13 , V_14 , V_15 ;
V_13 = F_2 ( V_1 + V_366 ) ;
V_14 = F_2 ( V_1 + V_365 ) ;
V_15 = F_2 ( V_1 + V_145 ) ;
return V_15 - ( ( V_14 - V_13 ) & V_15 ) ;
}
static int F_16 ( struct V_26 * V_64 )
{
void T_1 * V_1 = V_64 -> V_73 ;
T_2 V_13 , V_14 , V_15 ;
V_13 = F_2 ( V_1 + V_19 ) ;
V_14 = F_2 ( V_1 + V_20 ) ;
V_15 = F_2 ( V_1 + V_21 ) ;
return ( V_14 - V_13 ) & V_15 ;
}
static void F_115 ( struct V_26 * V_64 )
{
F_5 ( V_64 -> V_73 , V_375 , V_76 ) ;
}
static void F_118 ( struct V_26 * V_64 )
{
F_5 ( V_64 -> V_73 , V_376 , V_76 ) ;
}
static int F_24 ( struct V_26 * V_377 ,
struct V_378 T_3 * V_379 )
{
struct V_378 V_44 = {
. type = V_377 -> type ,
. line = V_377 -> V_64 . V_25 -> V_31 ,
. V_9 = V_377 -> V_64 . V_9 ,
. V_380 = 921600 ,
. V_381 = V_377 -> V_64 . V_381
} ;
return F_13 ( V_379 , & V_44 , sizeof( * V_379 ) ) ? - V_40 : 0 ;
}
static int F_26 ( struct V_26 * V_377 ,
struct V_378 T_3 * V_382 )
{
struct V_378 V_383 ;
if ( F_140 ( & V_383 , V_382 , sizeof( V_383 ) ) )
return - V_40 ;
if ( V_383 . V_384 != 0 || V_383 . V_64 != 0 ||
V_383 . V_385 != 0 ||
V_383 . V_380 != 921600 )
return - V_251 ;
if ( ! F_91 ( V_250 ) ) {
if ( ( ( V_383 . V_9 & ~ V_386 ) !=
( V_377 -> V_64 . V_9 & ~ V_386 ) ) )
return - V_251 ;
} else
V_377 -> V_64 . V_381 = V_383 . V_381 * V_212 / 100 ;
V_383 . V_9 = ( V_383 . V_9 & ~ V_387 ) ;
V_383 . V_9 |= ( V_377 -> V_64 . V_9 & V_387 ) ;
F_96 ( V_377 , V_383 . type == V_204 ) ;
V_377 -> type = V_383 . type ;
return 0 ;
}
static void F_96 ( struct V_26 * V_64 , int V_388 )
{
void T_1 * V_1 = V_64 -> V_73 ;
if ( ! V_388 ) {
F_5 ( V_1 , V_389 , 0 ) ;
F_5 ( V_1 , V_390 , 1 ) ;
} else {
F_5 ( V_1 , V_389 , 3 ) ;
F_5 ( V_1 , V_390 , 16 ) ;
}
}
