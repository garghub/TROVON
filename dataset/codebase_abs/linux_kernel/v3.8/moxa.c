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
if ( ! V_59 )
V_44 . V_65 = V_45 -> V_65 ;
else
V_44 . V_65 = V_59 -> V_66 . V_67 ;
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
unsigned int V_46 , V_200 ;
int V_12 ;
V_78 -> V_50 = F_48 ( V_51 , sizeof( * V_78 -> V_50 ) ,
V_201 ) ;
if ( V_78 -> V_50 == NULL ) {
F_36 ( V_99 L_17 ) ;
V_12 = - V_202 ;
goto V_83;
}
for ( V_46 = 0 , V_45 = V_78 -> V_50 ; V_46 < V_51 ; V_46 ++ , V_45 ++ ) {
F_49 ( & V_45 -> V_64 ) ;
V_45 -> V_64 . V_203 = & V_204 ;
V_45 -> type = V_205 ;
V_45 -> V_65 = V_206 | V_207 | V_208 | V_209 | V_210 ;
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
goto V_211;
}
V_12 = F_42 ( V_78 , V_183 ) ;
F_51 ( V_183 ) ;
if ( V_12 )
goto V_211;
F_15 ( & V_52 ) ;
V_78 -> V_53 = 1 ;
if ( ! F_52 ( & V_212 ) )
F_53 ( & V_212 , V_3 + V_213 / 50 ) ;
F_18 ( & V_52 ) ;
V_200 = ( V_78 - V_49 ) * V_51 ;
for ( V_46 = 0 ; V_46 < V_78 -> V_130 ; V_46 ++ )
F_54 ( & V_78 -> V_50 [ V_46 ] . V_64 , V_214 ,
V_200 + V_46 , V_198 ) ;
return 0 ;
V_211:
for ( V_46 = 0 ; V_46 < V_51 ; V_46 ++ )
F_55 ( & V_78 -> V_50 [ V_46 ] . V_64 ) ;
F_56 ( V_78 -> V_50 ) ;
V_83:
return V_12 ;
}
static void F_57 ( struct V_77 * V_78 )
{
unsigned int V_187 , V_215 , V_200 ;
F_23 ( & V_216 ) ;
F_15 ( & V_52 ) ;
V_78 -> V_53 = 0 ;
F_18 ( & V_52 ) ;
for ( V_187 = 0 ; V_187 < V_78 -> V_130 ; V_187 ++ )
if ( V_78 -> V_50 [ V_187 ] . V_64 . V_9 & V_217 ) {
struct V_24 * V_25 = F_21 (
& V_78 -> V_50 [ V_187 ] . V_64 ) ;
if ( V_25 ) {
F_58 ( V_25 ) ;
F_22 ( V_25 ) ;
}
}
for ( V_187 = 0 ; V_187 < V_51 ; V_187 ++ )
F_55 ( & V_78 -> V_50 [ V_187 ] . V_64 ) ;
while ( 1 ) {
V_215 = 0 ;
for ( V_187 = 0 ; V_187 < V_78 -> V_130 ; V_187 ++ )
if ( V_78 -> V_50 [ V_187 ] . V_64 . V_9 & V_217 )
V_215 ++ ;
F_25 ( & V_216 ) ;
if ( ! V_215 )
break;
F_33 ( 50 ) ;
F_23 ( & V_216 ) ;
}
V_200 = ( V_78 - V_49 ) * V_51 ;
for ( V_187 = 0 ; V_187 < V_78 -> V_130 ; V_187 ++ )
F_59 ( V_214 , V_200 + V_187 ) ;
F_60 ( V_78 -> V_89 ) ;
V_78 -> V_89 = NULL ;
F_56 ( V_78 -> V_50 ) ;
}
static int F_61 ( struct V_218 * V_219 ,
const struct V_220 * V_221 )
{
struct V_77 * V_139 ;
unsigned int V_46 ;
int V_222 = V_221 -> V_28 ;
int V_138 ;
V_138 = F_62 ( V_219 ) ;
if ( V_138 ) {
F_63 ( & V_219 -> V_198 , L_24 ) ;
goto V_83;
}
for ( V_46 = 0 ; V_46 < V_48 ; V_46 ++ )
if ( V_49 [ V_46 ] . V_89 == NULL )
break;
V_138 = - V_37 ;
if ( V_46 >= V_48 ) {
F_64 ( & V_219 -> V_198 , L_25
L_26 , V_48 ) ;
goto V_83;
}
V_139 = & V_49 [ V_46 ] ;
V_138 = F_65 ( V_219 , 2 , L_27 ) ;
if ( V_138 ) {
F_63 ( & V_219 -> V_198 , L_28 ) ;
goto V_83;
}
V_139 -> V_89 = F_66 ( F_67 ( V_219 , 2 ) , 0x4000 ) ;
if ( V_139 -> V_89 == NULL ) {
F_63 ( & V_219 -> V_198 , L_29 ) ;
V_138 = - V_202 ;
goto V_223;
}
V_139 -> V_80 = V_222 ;
switch ( V_222 ) {
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
V_138 = F_47 ( V_139 , & V_219 -> V_198 ) ;
if ( V_138 )
goto V_224;
F_68 ( V_219 , V_139 ) ;
F_69 ( & V_219 -> V_198 , L_30 ,
V_225 [ V_222 - 1 ] , V_139 -> V_130 ) ;
return 0 ;
V_224:
F_60 ( V_139 -> V_89 ) ;
V_139 -> V_89 = NULL ;
V_223:
F_70 ( V_219 , 2 ) ;
V_83:
return V_138 ;
}
static void F_71 ( struct V_218 * V_219 )
{
struct V_77 * V_78 = F_72 ( V_219 ) ;
F_57 ( V_78 ) ;
F_70 ( V_219 , 2 ) ;
}
static int T_8 F_73 ( void )
{
unsigned int V_226 = 0 ;
int V_138 = 0 ;
struct V_77 * V_78 = V_49 ;
unsigned int V_46 ;
F_36 ( V_227 L_31 ,
V_228 ) ;
F_49 ( & V_229 ) ;
V_214 = F_74 ( V_32 + 1 ,
V_230 |
V_231 ) ;
if ( F_75 ( V_214 ) )
return F_76 ( V_214 ) ;
V_214 -> V_232 = L_32 ;
V_214 -> V_233 = V_234 ;
V_214 -> V_235 = 0 ;
V_214 -> type = V_236 ;
V_214 -> V_237 = V_238 ;
V_214 -> V_239 = V_240 ;
V_214 -> V_239 . V_67 = V_206 | V_207 | V_208 | V_209 | V_210 ;
V_214 -> V_239 . V_241 = 9600 ;
V_214 -> V_239 . V_242 = 9600 ;
F_77 ( V_214 , & V_243 ) ;
F_78 ( & V_229 , V_214 , V_32 ) ;
if ( F_79 ( V_214 ) ) {
F_36 ( V_99 L_33 ) ;
F_80 ( V_214 ) ;
return - 1 ;
}
for ( V_46 = 0 ; V_46 < V_48 ; V_46 ++ ) {
if ( ! V_244 [ V_46 ] )
break;
if ( type [ V_46 ] == V_81 ||
type [ V_46 ] == V_245 ) {
F_81 ( L_34 ,
V_226 + 1 , V_225 [ type [ V_46 ] - 1 ] ,
V_244 [ V_46 ] ) ;
V_78 -> V_80 = type [ V_46 ] ;
V_78 -> V_130 = type [ V_46 ] == V_81 ? 8 :
V_246 [ V_46 ] ;
V_78 -> V_123 = V_247 ;
V_78 -> V_89 = F_66 ( V_244 [ V_46 ] , 0x4000 ) ;
if ( ! V_78 -> V_89 ) {
F_36 ( V_99 L_35 ,
V_244 [ V_46 ] ) ;
continue;
}
if ( F_47 ( V_78 , NULL ) ) {
F_60 ( V_78 -> V_89 ) ;
V_78 -> V_89 = NULL ;
continue;
}
F_36 ( V_227 L_36
L_37 ,
V_244 [ V_46 ] , V_78 -> V_130 ) ;
V_78 ++ ;
V_226 ++ ;
}
}
#ifdef F_82
V_138 = F_83 ( & V_248 ) ;
if ( V_138 ) {
F_36 ( V_99 L_38 ) ;
if ( V_226 )
V_138 = 0 ;
}
#endif
return V_138 ;
}
static void T_9 F_84 ( void )
{
unsigned int V_46 ;
#ifdef F_82
F_85 ( & V_248 ) ;
#endif
for ( V_46 = 0 ; V_46 < V_48 ; V_46 ++ )
if ( V_49 [ V_46 ] . V_53 )
F_57 ( & V_49 [ V_46 ] ) ;
F_86 ( & V_212 ) ;
if ( F_87 ( V_214 ) )
F_36 ( V_99 L_39
L_40 ) ;
F_80 ( V_214 ) ;
}
static void F_88 ( struct V_249 * V_64 )
{
struct V_26 * V_27 = F_89 ( V_64 , struct V_26 , V_64 ) ;
F_90 ( V_27 ) ;
F_14 ( V_27 , 2 ) ;
}
static int F_91 ( struct V_249 * V_64 )
{
struct V_26 * V_27 = F_89 ( V_64 , struct V_26 , V_64 ) ;
int V_63 ;
F_92 ( & V_64 -> V_250 ) ;
V_63 = V_27 -> V_140 ;
F_93 ( & V_64 -> V_250 ) ;
return V_63 ;
}
static void F_94 ( struct V_249 * V_64 , int V_251 )
{
struct V_26 * V_27 = F_89 ( V_64 , struct V_26 , V_64 ) ;
F_95 ( V_27 , V_251 , V_251 ) ;
}
static int F_96 ( struct V_24 * V_25 , struct V_199 * V_252 )
{
struct V_77 * V_78 ;
struct V_26 * V_27 ;
int V_64 ;
V_64 = V_25 -> V_31 ;
if ( V_64 == V_32 ) {
return F_97 ( V_253 ) ? 0 : - V_254 ;
}
if ( F_98 ( & V_216 ) )
return - V_255 ;
V_78 = & V_49 [ V_64 / V_51 ] ;
if ( ! V_78 -> V_53 ) {
F_25 ( & V_216 ) ;
return - V_37 ;
}
if ( V_64 % V_51 >= V_78 -> V_130 ) {
F_25 ( & V_216 ) ;
return - V_37 ;
}
V_27 = & V_78 -> V_50 [ V_64 % V_51 ] ;
V_27 -> V_64 . V_256 ++ ;
V_25 -> V_28 = V_27 ;
F_99 ( & V_27 -> V_64 , V_25 ) ;
F_23 ( & V_27 -> V_64 . V_69 ) ;
if ( ! ( V_27 -> V_64 . V_9 & V_217 ) ) {
V_27 -> V_257 = 0 ;
F_100 ( V_25 , & V_25 -> V_66 ) ;
F_95 ( V_27 , 1 , 1 ) ;
F_101 ( V_27 ) ;
F_102 ( V_27 , V_27 -> type == V_205 ) ;
V_27 -> V_64 . V_9 |= V_217 ;
}
F_25 ( & V_27 -> V_64 . V_69 ) ;
F_25 ( & V_216 ) ;
return F_103 ( & V_27 -> V_64 , V_25 , V_252 ) ;
}
static void F_104 ( struct V_24 * V_25 , struct V_199 * V_252 )
{
struct V_26 * V_27 = V_25 -> V_28 ;
V_27 -> V_65 = V_25 -> V_66 . V_67 ;
F_105 ( & V_27 -> V_64 , V_25 , V_252 ) ;
}
static int F_106 ( struct V_24 * V_25 ,
const unsigned char * V_87 , int V_256 )
{
struct V_26 * V_27 = V_25 -> V_28 ;
unsigned long V_9 ;
int V_16 ;
if ( V_27 == NULL )
return 0 ;
F_6 ( & V_52 , V_9 ) ;
V_16 = F_107 ( V_25 , V_87 , V_256 ) ;
F_8 ( & V_52 , V_9 ) ;
F_108 ( V_258 , & V_27 -> V_257 ) ;
return V_16 ;
}
static int F_109 ( struct V_24 * V_25 )
{
struct V_26 * V_27 ;
if ( V_25 -> V_259 )
return 0 ;
V_27 = V_25 -> V_28 ;
if ( V_27 == NULL )
return 0 ;
return F_110 ( V_27 ) ;
}
static void F_111 ( struct V_24 * V_25 )
{
struct V_26 * V_27 = V_25 -> V_28 ;
if ( V_27 == NULL )
return;
F_14 ( V_27 , 1 ) ;
F_112 ( V_25 ) ;
}
static int F_113 ( struct V_24 * V_25 )
{
struct V_26 * V_27 = V_25 -> V_28 ;
int V_260 ;
V_260 = F_17 ( V_27 ) ;
if ( V_260 )
F_108 ( V_261 , & V_27 -> V_257 ) ;
return V_260 ;
}
static int F_114 ( struct V_24 * V_25 )
{
struct V_26 * V_27 = V_25 -> V_28 ;
int V_262 = 0 , V_263 , V_264 ;
F_115 ( V_27 , & V_263 , & V_264 ) ;
if ( V_263 )
V_262 |= V_265 ;
if ( V_264 )
V_262 |= V_266 ;
V_263 = F_20 ( V_27 ) ;
if ( V_263 & 1 )
V_262 |= V_267 ;
if ( V_263 & 2 )
V_262 |= V_268 ;
if ( V_263 & 4 )
V_262 |= V_269 ;
return V_262 ;
}
static int F_116 ( struct V_24 * V_25 ,
unsigned int V_270 , unsigned int V_271 )
{
struct V_26 * V_27 ;
int V_263 , V_264 ;
F_23 ( & V_216 ) ;
V_27 = V_25 -> V_28 ;
if ( ! V_27 ) {
F_25 ( & V_216 ) ;
return - V_36 ;
}
F_115 ( V_27 , & V_263 , & V_264 ) ;
if ( V_270 & V_266 )
V_264 = 1 ;
if ( V_270 & V_265 )
V_263 = 1 ;
if ( V_271 & V_266 )
V_264 = 0 ;
if ( V_271 & V_265 )
V_263 = 0 ;
F_95 ( V_27 , V_263 , V_264 ) ;
F_25 ( & V_216 ) ;
return 0 ;
}
static void F_117 ( struct V_24 * V_25 ,
struct V_272 * V_273 )
{
struct V_26 * V_27 = V_25 -> V_28 ;
if ( V_27 == NULL )
return;
F_100 ( V_25 , V_273 ) ;
if ( ! ( V_273 -> V_67 & V_209 ) && F_118 ( V_25 ) )
F_119 ( & V_27 -> V_64 . V_274 ) ;
}
static void F_120 ( struct V_24 * V_25 )
{
struct V_26 * V_27 = V_25 -> V_28 ;
if ( V_27 == NULL )
return;
F_121 ( V_27 ) ;
F_108 ( V_275 , & V_27 -> V_257 ) ;
}
static void F_122 ( struct V_24 * V_25 )
{
struct V_26 * V_27 = V_25 -> V_28 ;
if ( V_27 == NULL )
return;
if ( ! F_123 ( V_275 , & V_27 -> V_257 ) )
return;
F_124 ( V_27 ) ;
F_125 ( V_275 , & V_27 -> V_257 ) ;
}
static void F_126 ( struct V_24 * V_25 )
{
struct V_26 * V_27 = V_25 -> V_28 ;
F_127 ( & V_27 -> V_64 ) ;
}
static void F_128 ( struct V_26 * V_45 , T_4 V_63 )
{
struct V_24 * V_25 ;
unsigned long V_9 ;
V_63 = ! ! V_63 ;
F_6 ( & V_45 -> V_64 . V_250 , V_9 ) ;
if ( V_63 != V_45 -> V_140 ) {
V_45 -> V_140 = V_63 ;
F_8 ( & V_45 -> V_64 . V_250 , V_9 ) ;
V_25 = F_21 ( & V_45 -> V_64 ) ;
if ( V_25 && ! F_118 ( V_25 ) && ! V_63 )
F_58 ( V_25 ) ;
F_22 ( V_25 ) ;
}
else
F_8 ( & V_45 -> V_64 . V_250 , V_9 ) ;
}
static int F_129 ( struct V_26 * V_45 , unsigned int V_276 ,
T_2 T_1 * V_277 )
{
struct V_24 * V_25 = F_21 ( & V_45 -> V_64 ) ;
void T_1 * V_1 ;
unsigned int V_278 = V_45 -> V_64 . V_9 & V_217 ;
T_2 V_279 ;
if ( V_25 ) {
if ( F_123 ( V_261 , & V_45 -> V_257 ) &&
F_17 ( V_45 ) == 0 ) {
F_125 ( V_261 , & V_45 -> V_257 ) ;
F_112 ( V_25 ) ;
}
if ( F_123 ( V_258 , & V_45 -> V_257 ) && ! V_25 -> V_259 &&
F_17 ( V_45 ) <= V_280 ) {
F_125 ( V_258 , & V_45 -> V_257 ) ;
F_112 ( V_25 ) ;
}
if ( V_278 && ! F_123 ( V_281 , & V_25 -> V_9 ) &&
F_16 ( V_45 ) > 0 ) {
F_130 ( V_45 ) ;
F_131 ( V_25 ) ;
}
} else {
F_125 ( V_261 , & V_45 -> V_257 ) ;
F_14 ( V_45 , 0 ) ;
}
if ( ! V_276 )
goto V_282;
V_279 = F_2 ( V_277 ) ;
if ( V_279 == 0 )
goto V_282;
F_7 ( 0 , V_277 ) ;
V_1 = V_45 -> V_73 ;
if ( V_279 & V_283 )
F_7 ( F_2 ( V_1 + V_284 ) & ~ V_285 ,
V_1 + V_284 ) ;
if ( ! V_278 )
goto V_282;
if ( V_25 && ( V_279 & V_286 ) && ! F_132 ( V_25 ) ) {
F_133 ( V_25 , 0 , V_287 ) ;
F_131 ( V_25 ) ;
}
if ( V_279 & V_288 )
F_128 ( V_45 , F_11 ( V_1 + V_17 ) & V_289 ) ;
V_282:
F_22 ( V_25 ) ;
return 0 ;
}
static void F_134 ( unsigned long V_290 )
{
struct V_77 * V_78 ;
T_2 T_1 * V_277 ;
unsigned int V_291 , V_64 , V_292 = 0 ;
F_135 ( & V_52 ) ;
for ( V_291 = 0 ; V_291 < V_48 ; V_291 ++ ) {
V_78 = & V_49 [ V_291 ] ;
if ( ! V_78 -> V_53 )
continue;
V_292 ++ ;
V_277 = NULL ;
if ( F_11 ( V_78 -> V_134 ) == 0xff )
V_277 = V_78 -> V_136 + F_11 ( V_78 -> V_132 ) ;
for ( V_64 = 0 ; V_64 < V_78 -> V_130 ; V_64 ++ )
F_129 ( & V_78 -> V_50 [ V_64 ] , ! ! V_277 , V_277 + V_64 ) ;
if ( V_277 )
F_32 ( 0 , V_78 -> V_134 ) ;
if ( V_293 ) {
struct V_26 * V_45 = V_78 -> V_50 ;
for ( V_64 = 0 ; V_64 < V_78 -> V_130 ; V_64 ++ , V_45 ++ )
if ( V_45 -> V_294 ) {
V_45 -> V_294 = 0 ;
F_10 ( V_45 -> V_73 ) ;
}
}
}
V_293 = 0 ;
if ( V_292 )
F_53 ( & V_212 , V_3 + V_213 / 50 ) ;
F_136 ( & V_52 ) ;
}
static void F_100 ( struct V_24 * V_25 , struct V_272 * V_273 )
{
register struct V_272 * V_295 = & V_25 -> V_66 ;
struct V_26 * V_27 = V_25 -> V_28 ;
int V_264 , V_61 , V_296 , V_297 , V_298 , V_299 ;
V_264 = V_61 = V_296 = V_297 = V_298 = 0 ;
if ( V_295 -> V_67 & V_300 )
V_264 = V_61 = 1 ;
if ( V_295 -> V_301 & V_302 )
V_296 = 1 ;
if ( V_295 -> V_301 & V_303 )
V_297 = 1 ;
if ( V_295 -> V_301 & V_304 )
V_298 = 1 ;
V_295 -> V_67 &= ~ V_305 ;
F_137 ( V_27 , V_264 , V_61 , V_296 , V_297 , V_298 ) ;
V_299 = F_138 ( V_27 , V_295 , F_139 ( V_25 ) ) ;
if ( V_299 == - 1 )
V_299 = F_140 ( V_273 ) ;
F_141 ( V_25 , V_299 , V_299 ) ;
}
static void F_14 ( struct V_26 * V_64 , int V_306 )
{
void T_1 * V_1 ;
if ( V_306 < 0 || V_306 > 2 )
return;
V_1 = V_64 -> V_73 ;
F_5 ( V_1 , V_307 , V_306 ) ;
if ( V_306 != 1 ) {
V_64 -> V_294 = 0 ;
F_10 ( V_1 ) ;
}
}
static void F_101 ( struct V_26 * V_64 )
{
void T_1 * V_1 ;
T_2 V_308 = 512 ;
V_1 = V_64 -> V_73 ;
F_7 ( V_308 , V_1 + V_22 ) ;
if ( F_40 ( V_64 -> V_139 ) )
F_5 ( V_1 , V_309 , 0 ) ;
else
F_7 ( F_2 ( V_1 + V_284 ) | V_310 ,
V_1 + V_284 ) ;
F_5 ( V_1 , V_311 , V_76 ) ;
F_5 ( V_1 , V_307 , 2 ) ;
F_5 ( V_1 , V_312 , V_76 ) ;
F_20 ( V_64 ) ;
}
static void F_90 ( struct V_26 * V_64 )
{
void T_1 * V_1 = V_64 -> V_73 ;
F_5 ( V_1 , V_313 , 0 ) ;
F_5 ( V_1 , V_314 , V_76 ) ;
F_7 ( 0 , V_1 + V_284 ) ;
F_5 ( V_1 , V_315 , V_76 ) ;
}
static T_10 F_142 ( struct V_26 * V_64 , T_10 V_299 )
{
void T_1 * V_1 = V_64 -> V_73 ;
unsigned int clock , V_316 ;
T_10 V_317 ;
V_317 = F_40 ( V_64 -> V_139 ) ? 460800 : 921600 ;
if ( V_299 < 50 )
return 0 ;
if ( V_299 > V_317 )
V_299 = V_317 ;
clock = 921600 ;
V_316 = clock / V_299 ;
F_5 ( V_1 , V_318 , V_316 ) ;
V_299 = clock / V_316 ;
return V_299 ;
}
static int F_138 ( struct V_26 * V_64 , struct V_272 * V_319 ,
T_10 V_299 )
{
void T_1 * V_1 ;
T_11 V_306 = 0 ;
V_1 = V_64 -> V_73 ;
V_306 = V_319 -> V_67 & V_320 ;
if ( V_306 == V_321 )
V_306 = V_322 ;
else if ( V_306 == V_323 )
V_306 = V_324 ;
else if ( V_306 == V_325 )
V_306 = V_326 ;
else if ( V_306 == V_207 )
V_306 = V_327 ;
if ( V_319 -> V_67 & V_328 ) {
if ( V_306 == V_322 )
V_306 |= V_329 ;
else
V_306 |= V_330 ;
} else
V_306 |= V_331 ;
if ( V_319 -> V_67 & V_332 ) {
if ( V_319 -> V_67 & V_333 )
V_306 |= V_334 ;
else
V_306 |= V_335 ;
} else
V_306 |= V_336 ;
F_5 ( V_1 , V_337 , ( T_2 ) V_306 ) ;
if ( F_40 ( V_64 -> V_139 ) && V_299 >= 921600 )
return - 1 ;
V_299 = F_142 ( V_64 , V_299 ) ;
if ( V_319 -> V_301 & ( V_302 | V_303 | V_304 ) ) {
F_92 ( & V_10 ) ;
F_32 ( V_319 -> V_338 [ V_339 ] , V_1 + V_11 ) ;
F_32 ( V_319 -> V_338 [ V_340 ] , V_1 + V_341 ) ;
F_32 ( V_342 , V_1 + V_5 ) ;
F_1 ( V_1 ) ;
F_93 ( & V_10 ) ;
}
return V_299 ;
}
static int F_115 ( struct V_26 * V_64 , int * V_343 ,
int * V_344 )
{
if ( V_343 )
* V_343 = ! ! ( V_64 -> V_345 & V_346 ) ;
if ( V_344 )
* V_344 = ! ! ( V_64 -> V_345 & V_347 ) ;
return 0 ;
}
static void F_95 ( struct V_26 * V_64 , int V_263 , int V_264 )
{
T_4 V_306 = 0 ;
if ( V_263 )
V_306 |= V_346 ;
if ( V_264 )
V_306 |= V_347 ;
V_64 -> V_345 = V_306 ;
F_5 ( V_64 -> V_73 , V_348 , V_306 ) ;
}
static void F_137 ( struct V_26 * V_64 , int V_264 , int V_61 ,
int V_296 , int V_297 , int V_349 )
{
int V_306 = 0 ;
if ( V_264 )
V_306 |= V_350 ;
if ( V_61 )
V_306 |= V_351 ;
if ( V_296 )
V_306 |= V_352 ;
if ( V_297 )
V_306 |= V_353 ;
if ( V_349 )
V_306 |= V_354 ;
F_5 ( V_64 -> V_73 , V_313 , V_306 ) ;
}
static int F_20 ( struct V_26 * V_64 )
{
void T_1 * V_1 ;
int V_316 ;
V_1 = V_64 -> V_73 ;
if ( F_40 ( V_64 -> V_139 ) )
V_316 = F_9 ( V_1 , V_355 , 0 ) ;
else
V_316 = F_2 ( V_1 + V_17 ) >> 4 ;
V_316 &= 0x0B ;
if ( V_316 & 8 )
V_316 |= 4 ;
F_128 ( V_64 , V_316 & 8 ) ;
V_316 &= 7 ;
return V_316 ;
}
static int F_107 ( struct V_24 * V_25 ,
const unsigned char * V_356 , int V_16 )
{
struct V_26 * V_64 = V_25 -> V_28 ;
void T_1 * V_88 , * V_1 , * V_357 ;
unsigned int V_358 , V_359 ;
T_2 V_360 , V_361 , V_362 , V_363 , V_364 ;
T_2 V_365 , V_366 , V_367 ;
V_1 = V_64 -> V_73 ;
V_88 = V_64 -> V_139 -> V_89 ;
V_362 = F_2 ( V_1 + V_145 ) ;
V_363 = F_2 ( V_1 + V_152 ) ;
V_364 = F_2 ( V_1 + V_154 ) ;
V_361 = F_2 ( V_1 + V_368 ) ;
V_360 = F_2 ( V_1 + V_369 ) ;
V_358 = ( V_360 > V_361 ) ? ( V_360 - V_361 - 1 ) : ( V_360 - V_361 + V_362 ) ;
if ( V_358 > V_16 )
V_358 = V_16 ;
V_38 . V_370 [ V_64 -> V_64 . V_25 -> V_31 ] += V_358 ;
V_359 = V_358 ;
if ( V_363 == V_364 ) {
V_367 = F_2 ( V_1 + V_178 ) ;
F_7 ( V_363 , V_88 + V_91 ) ;
while ( V_358 > 0 ) {
if ( V_360 > V_361 )
V_16 = V_360 - V_361 - 1 ;
else
V_16 = V_362 + 1 - V_361 ;
V_16 = ( V_358 > V_16 ) ? V_16 : V_358 ;
V_357 = V_88 + V_102 + V_367 + V_361 ;
F_35 ( V_357 , V_356 , V_16 ) ;
V_356 += V_16 ;
V_361 = ( V_361 + V_16 ) & V_362 ;
V_358 -= V_16 ;
}
} else {
V_365 = V_363 + ( V_361 >> 13 ) ;
V_366 = V_361 & V_371 ;
while ( V_358 > 0 ) {
V_16 = V_372 - V_366 ;
if ( V_16 > V_358 )
V_16 = V_358 ;
F_32 ( V_365 , V_88 + V_91 ) ;
V_357 = V_88 + V_102 + V_366 ;
F_35 ( V_357 , V_356 , V_16 ) ;
V_356 += V_16 ;
if ( ++ V_365 == V_364 )
V_365 = V_363 ;
V_366 = 0 ;
V_358 -= V_16 ;
}
V_361 = ( V_361 + V_359 ) & V_362 ;
}
F_7 ( V_361 , V_1 + V_368 ) ;
F_32 ( 1 , V_1 + V_373 ) ;
return V_359 ;
}
static int F_130 ( struct V_26 * V_64 )
{
struct V_24 * V_25 = V_64 -> V_64 . V_25 ;
unsigned char * V_374 ;
void T_1 * V_88 , * V_1 , * V_357 ;
unsigned int V_256 , V_16 , V_359 ;
T_2 V_361 , V_375 , V_363 , V_364 ;
T_2 V_365 , V_366 , V_367 , V_360 ;
V_1 = V_64 -> V_73 ;
V_88 = V_64 -> V_139 -> V_89 ;
V_360 = F_2 ( V_1 + V_19 ) ;
V_361 = F_2 ( V_1 + V_20 ) ;
V_375 = F_2 ( V_1 + V_21 ) ;
V_363 = F_2 ( V_1 + V_148 ) ;
V_364 = F_2 ( V_1 + V_150 ) ;
V_256 = ( V_361 >= V_360 ) ? ( V_361 - V_360 ) : ( V_361 - V_360 + V_375 + 1 ) ;
if ( V_256 == 0 )
return 0 ;
V_359 = V_256 ;
V_38 . V_376 [ V_25 -> V_31 ] += V_359 ;
if ( V_363 == V_364 ) {
V_367 = F_2 ( V_1 + V_377 ) ;
F_7 ( V_363 , V_88 + V_91 ) ;
while ( V_256 > 0 ) {
V_357 = V_88 + V_102 + V_367 + V_360 ;
V_16 = ( V_361 >= V_360 ) ? ( V_361 - V_360 ) :
( V_375 + 1 - V_360 ) ;
V_16 = F_143 ( V_25 , & V_374 ,
F_144 ( V_16 , V_256 ) ) ;
F_145 ( V_374 , V_357 , V_16 ) ;
V_360 = ( V_360 + V_16 ) & V_375 ;
V_256 -= V_16 ;
}
} else {
V_365 = V_363 + ( V_360 >> 13 ) ;
V_366 = V_360 & V_371 ;
while ( V_256 > 0 ) {
F_7 ( V_365 , V_88 + V_91 ) ;
V_357 = V_88 + V_102 + V_366 ;
V_16 = F_143 ( V_25 , & V_374 ,
F_144 ( V_372 - V_366 , V_256 ) ) ;
F_145 ( V_374 , V_357 , V_16 ) ;
V_256 -= V_16 ;
V_366 = ( V_366 + V_16 ) & V_371 ;
if ( V_366 == 0 && ++ V_365 == V_364 )
V_365 = V_363 ;
}
V_360 = ( V_360 + V_359 ) & V_375 ;
}
F_7 ( V_360 , V_1 + V_19 ) ;
if ( F_11 ( V_1 + V_17 ) & V_18 ) {
V_293 = 1 ;
V_64 -> V_294 = 1 ;
}
return V_359 ;
}
static int F_17 ( struct V_26 * V_64 )
{
void T_1 * V_1 = V_64 -> V_73 ;
T_2 V_13 , V_14 , V_15 ;
V_13 = F_2 ( V_1 + V_369 ) ;
V_14 = F_2 ( V_1 + V_368 ) ;
V_15 = F_2 ( V_1 + V_145 ) ;
return ( V_14 - V_13 ) & V_15 ;
}
static int F_110 ( struct V_26 * V_64 )
{
void T_1 * V_1 = V_64 -> V_73 ;
T_2 V_13 , V_14 , V_15 ;
V_13 = F_2 ( V_1 + V_369 ) ;
V_14 = F_2 ( V_1 + V_368 ) ;
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
static void F_121 ( struct V_26 * V_64 )
{
F_5 ( V_64 -> V_73 , V_378 , V_76 ) ;
}
static void F_124 ( struct V_26 * V_64 )
{
F_5 ( V_64 -> V_73 , V_379 , V_76 ) ;
}
static int F_24 ( struct V_26 * V_380 ,
struct V_381 T_3 * V_382 )
{
struct V_381 V_44 = {
. type = V_380 -> type ,
. line = V_380 -> V_64 . V_25 -> V_31 ,
. V_9 = V_380 -> V_64 . V_9 ,
. V_383 = 921600 ,
. V_384 = V_380 -> V_64 . V_384
} ;
return F_13 ( V_382 , & V_44 , sizeof( * V_382 ) ) ? - V_40 : 0 ;
}
static int F_26 ( struct V_26 * V_380 ,
struct V_381 T_3 * V_385 )
{
struct V_381 V_386 ;
if ( F_146 ( & V_386 , V_385 , sizeof( V_386 ) ) )
return - V_40 ;
if ( V_386 . V_387 != 0 || V_386 . V_64 != 0 ||
V_386 . V_388 != 0 ||
V_386 . V_383 != 921600 )
return - V_254 ;
if ( ! F_97 ( V_253 ) ) {
if ( ( ( V_386 . V_9 & ~ V_389 ) !=
( V_380 -> V_64 . V_9 & ~ V_389 ) ) )
return - V_254 ;
} else
V_380 -> V_64 . V_384 = V_386 . V_384 * V_213 / 100 ;
V_386 . V_9 = ( V_386 . V_9 & ~ V_390 ) ;
V_386 . V_9 |= ( V_380 -> V_64 . V_9 & V_390 ) ;
F_102 ( V_380 , V_386 . type == V_205 ) ;
V_380 -> type = V_386 . type ;
return 0 ;
}
static void F_102 ( struct V_26 * V_64 , int V_391 )
{
void T_1 * V_1 = V_64 -> V_73 ;
if ( ! V_391 ) {
F_5 ( V_1 , V_392 , 0 ) ;
F_5 ( V_1 , V_393 , 1 ) ;
} else {
F_5 ( V_1 , V_392 , 3 ) ;
F_5 ( V_1 , V_393 , 16 ) ;
}
}
