static void F_1 ( void T_1 * V_1 )
{
unsigned long V_2 = V_3 + V_4 ;
while ( F_2 ( V_1 + V_5 ) != 0 )
if ( F_3 ( V_3 , V_2 ) )
return;
if ( F_2 ( V_1 + V_5 ) != 0 && F_4 () )
F_5 ( V_6 L_1 ) ;
}
static void F_6 ( void T_1 * V_1 , T_2 V_7 , T_2 V_8 )
{
unsigned long V_9 ;
F_7 ( & V_10 , V_9 ) ;
F_8 ( V_8 , V_1 + V_11 ) ;
F_8 ( V_7 , V_1 + V_5 ) ;
F_1 ( V_1 ) ;
F_9 ( & V_10 , V_9 ) ;
}
static int F_10 ( void T_1 * V_1 , T_2 V_7 , T_2 V_8 )
{
unsigned long V_9 ;
T_2 V_12 ;
F_7 ( & V_10 , V_9 ) ;
F_8 ( V_8 , V_1 + V_11 ) ;
F_8 ( V_7 , V_1 + V_5 ) ;
F_1 ( V_1 ) ;
V_12 = F_2 ( V_1 + V_11 ) ;
F_9 ( & V_10 , V_9 ) ;
return V_12 ;
}
static void F_11 ( void T_1 * V_1 )
{
T_2 V_13 , V_14 , V_15 , V_16 ;
if ( F_12 ( V_1 + V_17 ) & V_18 ) {
V_13 = F_2 ( V_1 + V_19 ) ;
V_14 = F_2 ( V_1 + V_20 ) ;
V_15 = F_2 ( V_1 + V_21 ) ;
V_16 = ( V_14 - V_13 ) & V_15 ;
if ( V_16 <= V_22 )
F_6 ( V_1 , V_23 , 0 ) ;
}
}
static int F_13 ( struct V_24 * V_25 ,
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
if ( F_14 ( V_29 , & V_38 , sizeof( V_38 ) ) )
V_12 = - V_40 ;
break;
case V_41 :
F_15 ( V_27 , V_8 ) ;
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
F_16 ( & V_52 ) ;
if ( V_49 [ V_46 ] . V_53 ) {
V_44 . V_54 = F_17 ( V_45 ) ;
V_44 . V_55 = F_18 ( V_45 ) ;
}
F_19 ( & V_52 ) ;
if ( F_14 ( V_43 , & V_44 , sizeof( V_44 ) ) )
return - V_40 ;
}
}
break;
} case V_56 :
V_30 = F_18 ( V_27 ) ;
V_12 = F_20 ( V_30 , ( unsigned long T_3 * ) V_29 ) ;
break;
case V_57 :
V_30 = F_17 ( V_27 ) ;
V_12 = F_20 ( V_30 , ( unsigned long T_3 * ) V_29 ) ;
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
F_16 ( & V_52 ) ;
if ( ! V_49 [ V_46 ] . V_53 ) {
F_19 ( & V_52 ) ;
goto V_60;
}
V_30 = F_21 ( V_45 ) ;
F_19 ( & V_52 ) ;
if ( V_30 & 1 )
V_44 . V_61 = 1 ;
if ( V_30 & 2 )
V_44 . V_62 = 1 ;
if ( V_30 & 4 )
V_44 . V_63 = 1 ;
V_59 = F_22 ( & V_45 -> V_64 ) ;
if ( ! V_59 || ! V_59 -> V_65 )
V_44 . V_66 = V_45 -> V_66 ;
else
V_44 . V_66 = V_59 -> V_65 -> V_67 ;
F_23 ( V_59 ) ;
V_60:
if ( F_14 ( V_43 , & V_44 , sizeof( V_44 ) ) )
return - V_40 ;
}
}
break;
}
case V_68 :
F_24 ( & V_27 -> V_64 . V_69 ) ;
V_12 = F_25 ( V_27 , V_29 ) ;
F_26 ( & V_27 -> V_64 . V_69 ) ;
break;
case V_70 :
F_24 ( & V_27 -> V_64 . V_69 ) ;
V_12 = F_27 ( V_27 , V_29 ) ;
F_26 ( & V_27 -> V_64 . V_69 ) ;
break;
default:
V_12 = - V_71 ;
}
return V_12 ;
}
static int F_28 ( struct V_24 * V_25 , int V_72 )
{
struct V_26 * V_64 = V_25 -> V_28 ;
F_6 ( V_64 -> V_73 , V_72 ? V_74 : V_75 ,
V_76 ) ;
return 0 ;
}
static int F_29 ( struct V_77 * V_78 , T_4 V_79 )
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
static int F_30 ( const void * V_85 )
{
const T_5 * V_86 = V_85 ;
if ( * V_86 != F_31 ( 0x7980 ) )
return - V_36 ;
return 0 ;
}
static int F_32 ( struct V_77 * V_78 , const T_4 * V_87 ,
T_6 V_16 )
{
void T_1 * V_88 = V_78 -> V_89 ;
T_2 V_44 ;
F_33 ( V_90 , V_88 + V_91 ) ;
F_34 ( 10 ) ;
F_35 ( V_88 , 0 , 4096 ) ;
F_36 ( V_88 , V_87 , V_16 ) ;
F_33 ( 0 , V_88 + V_91 ) ;
F_34 ( 2000 ) ;
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
F_5 ( V_99 L_2
L_3 ) ;
return - V_100 ;
}
break;
}
return 0 ;
V_83:
F_5 ( V_99 L_4 ) ;
return - V_100 ;
}
static int F_37 ( struct V_77 * V_78 , const T_4 * V_85 ,
T_6 V_16 )
{
void T_1 * V_88 = V_78 -> V_89 ;
if ( V_16 < 7168 ) {
F_5 ( V_99 L_5 ) ;
return - V_36 ;
}
F_8 ( V_16 - 7168 - 2 , V_88 + V_101 ) ;
F_33 ( 1 , V_88 + V_91 ) ;
F_36 ( V_88 + V_102 , V_85 , 7168 ) ;
F_33 ( 2 , V_88 + V_91 ) ;
F_36 ( V_88 + V_102 , V_85 + 7168 , V_16 - 7168 ) ;
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
F_36 ( V_88 + V_107 , V_85 + V_47 , V_105 << 1 ) ;
V_47 += V_105 << 1 ;
F_8 ( V_105 , V_88 + V_108 ) ;
F_8 ( 0 , V_88 + V_106 ) ;
for ( V_46 = 0 ; V_46 < 100 ; V_46 ++ ) {
if ( F_2 ( V_88 + V_106 ) == V_113 )
break;
F_34 ( 10 ) ;
}
if ( F_2 ( V_88 + V_106 ) != V_113 )
return - V_100 ;
}
F_8 ( 0 , V_88 + V_108 ) ;
F_8 ( V_112 , V_88 + V_109 ) ;
F_8 ( 0 , V_88 + V_106 ) ;
for ( V_46 = 0 ; V_46 < 100 ; V_46 ++ ) {
if ( F_2 ( V_88 + V_106 ) == V_113 )
break;
F_34 ( 10 ) ;
}
V_111 ++ ;
} while ( ( F_12 ( V_88 + V_110 ) != 1 ) && ( V_111 < 3 ) );
if ( F_12 ( V_88 + V_110 ) != 1 )
return - V_100 ;
F_8 ( 0 , V_88 + V_106 ) ;
for ( V_46 = 0 ; V_46 < 600 ; V_46 ++ ) {
if ( F_2 ( V_88 + V_122 ) == V_76 )
break;
F_34 ( 10 ) ;
}
if ( F_2 ( V_88 + V_122 ) != V_76 )
return - V_100 ;
if ( F_40 ( V_78 ) ) {
if ( V_78 -> V_123 == V_124 ) {
F_8 ( 0x3800 , V_88 + V_125 ) ;
F_8 ( 0x3900 , V_88 + V_126 ) ;
F_8 ( 28499 , V_88 + V_127 ) ;
} else {
F_8 ( 0x3200 , V_88 + V_125 ) ;
F_8 ( 0x3400 , V_88 + V_126 ) ;
F_8 ( 19999 , V_88 + V_127 ) ;
}
}
F_8 ( 1 , V_88 + V_128 ) ;
F_8 ( 0 , V_88 + V_122 ) ;
for ( V_46 = 0 ; V_46 < 500 ; V_46 ++ ) {
if ( F_2 ( V_88 + V_122 ) == V_76 )
break;
F_34 ( 10 ) ;
}
if ( F_2 ( V_88 + V_122 ) != V_76 )
return - V_100 ;
if ( F_40 ( V_78 ) ) {
V_47 = F_2 ( V_88 + V_129 ) ;
if ( V_47 <= 0 )
return - V_100 ;
V_78 -> V_130 = V_47 * 8 ;
F_8 ( V_47 , V_88 + V_131 ) ;
F_8 ( 0 , V_88 + V_122 ) ;
for ( V_46 = 0 ; V_46 < 600 ; V_46 ++ ) {
if ( F_2 ( V_88 + V_122 ) == V_76 )
break;
F_34 ( 10 ) ;
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
F_5 ( V_99 L_6 ) ;
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
F_8 ( V_143 , V_1 + V_21 ) ;
F_8 ( V_144 , V_1 + V_145 ) ;
F_8 ( V_146 + V_46 * V_147 , V_1 + V_148 ) ;
F_8 ( F_2 ( V_1 + V_148 ) + V_149 , V_1 + V_150 ) ;
F_8 ( V_151 + V_46 * V_147 , V_1 + V_152 ) ;
F_8 ( F_2 ( V_1 + V_152 ) + V_153 , V_1 + V_154 ) ;
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
F_8 ( V_155 , V_1 + V_21 ) ;
F_8 ( V_156 , V_1 + V_145 ) ;
F_8 ( V_157 + V_46 * V_158 , V_1 + V_148 ) ;
F_8 ( F_2 ( V_1 + V_148 ) + V_159 , V_1 + V_150 ) ;
F_8 ( V_160 + V_46 * V_158 , V_1 + V_152 ) ;
F_8 ( F_2 ( V_1 + V_152 ) + V_161 , V_1 + V_154 ) ;
break;
case 16 :
F_8 ( V_162 , V_1 + V_21 ) ;
F_8 ( V_163 , V_1 + V_145 ) ;
F_8 ( V_164 + V_46 * V_165 , V_1 + V_148 ) ;
F_8 ( F_2 ( V_1 + V_148 ) + V_166 , V_1 + V_150 ) ;
F_8 ( V_167 + V_46 * V_165 , V_1 + V_152 ) ;
F_8 ( F_2 ( V_1 + V_152 ) + V_168 , V_1 + V_154 ) ;
break;
case 24 :
F_8 ( V_169 , V_1 + V_21 ) ;
F_8 ( V_170 , V_1 + V_145 ) ;
F_8 ( V_171 + V_46 * V_172 , V_1 + V_148 ) ;
F_8 ( F_2 ( V_1 + V_148 ) + V_173 , V_1 + V_150 ) ;
F_8 ( V_174 + V_46 * V_172 , V_1 + V_152 ) ;
F_8 ( F_2 ( V_1 + V_152 ) , V_1 + V_154 ) ;
break;
case 32 :
F_8 ( V_175 , V_1 + V_21 ) ;
F_8 ( V_176 , V_1 + V_145 ) ;
F_8 ( V_177 , V_1 + V_178 ) ;
F_8 ( V_179 + V_46 * V_180 , V_1 + V_148 ) ;
F_8 ( F_12 ( V_1 + V_148 ) , V_1 + V_150 ) ;
F_8 ( V_181 + V_46 * V_180 , V_1 + V_152 ) ;
F_8 ( F_2 ( V_1 + V_152 ) , V_1 + V_154 ) ;
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
if ( F_29 ( V_78 , V_193 -> V_79 ) ) {
sprintf ( V_185 , L_10 , V_193 -> V_79 ) ;
goto V_83;
}
V_16 = V_195 ;
V_189 = V_193 -> V_79 == 2 ? 5 : 3 ;
for ( V_187 = 0 ; V_187 < F_44 ( V_186 ) ; V_187 ++ ) {
V_186 [ V_187 ] = F_39 ( V_193 -> V_16 [ V_187 ] ) ;
if ( V_186 [ V_187 ] && V_16 + V_186 [ V_187 ] <= V_183 -> V_194 &&
F_30 ( & V_183 -> V_184 [ V_16 ] ) )
F_5 ( V_6 L_11
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
V_12 = F_32 ( V_78 , V_85 , V_186 [ V_188 ] ) ;
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
F_5 ( V_99 L_16 , V_185 ) ;
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
F_5 ( V_99 L_17 ) ;
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
F_5 ( V_99 L_21
L_22
L_23 ,
V_199 ) ;
goto V_210;
}
V_12 = F_42 ( V_78 , V_183 ) ;
F_51 ( V_183 ) ;
if ( V_12 )
goto V_210;
F_16 ( & V_52 ) ;
V_78 -> V_53 = 1 ;
if ( ! F_52 ( & V_211 ) )
F_53 ( & V_211 , V_3 + V_212 / 50 ) ;
F_19 ( & V_52 ) ;
return 0 ;
V_210:
F_54 ( V_78 -> V_50 ) ;
V_83:
return V_12 ;
}
static void F_55 ( struct V_77 * V_78 )
{
unsigned int V_187 , V_213 ;
F_24 ( & V_214 ) ;
F_16 ( & V_52 ) ;
V_78 -> V_53 = 0 ;
F_19 ( & V_52 ) ;
for ( V_187 = 0 ; V_187 < V_78 -> V_130 ; V_187 ++ )
if ( V_78 -> V_50 [ V_187 ] . V_64 . V_9 & V_215 ) {
struct V_24 * V_25 = F_22 (
& V_78 -> V_50 [ V_187 ] . V_64 ) ;
if ( V_25 ) {
F_56 ( V_25 ) ;
F_23 ( V_25 ) ;
}
}
while ( 1 ) {
V_213 = 0 ;
for ( V_187 = 0 ; V_187 < V_78 -> V_130 ; V_187 ++ )
if ( V_78 -> V_50 [ V_187 ] . V_64 . V_9 & V_215 )
V_213 ++ ;
F_26 ( & V_214 ) ;
if ( ! V_213 )
break;
F_34 ( 50 ) ;
F_24 ( & V_214 ) ;
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
F_5 ( V_225 L_31 ,
V_226 ) ;
V_227 = F_71 ( V_32 + 1 ) ;
if ( ! V_227 )
return - V_201 ;
V_227 -> V_228 = V_229 ;
V_227 -> V_230 = L_32 ;
V_227 -> V_231 = V_232 ;
V_227 -> V_233 = 0 ;
V_227 -> type = V_234 ;
V_227 -> V_235 = V_236 ;
V_227 -> V_237 = V_238 ;
V_227 -> V_237 . V_67 = V_205 | V_206 | V_207 | V_208 | V_209 ;
V_227 -> V_237 . V_239 = 9600 ;
V_227 -> V_237 . V_240 = 9600 ;
V_227 -> V_9 = V_241 ;
F_72 ( V_227 , & V_242 ) ;
if ( F_73 ( V_227 ) ) {
F_5 ( V_99 L_33 ) ;
F_74 ( V_227 ) ;
return - 1 ;
}
for ( V_46 = 0 ; V_46 < V_48 ; V_46 ++ ) {
if ( ! V_243 [ V_46 ] )
break;
if ( type [ V_46 ] == V_81 ||
type [ V_46 ] == V_244 ) {
F_75 ( L_34 ,
V_224 + 1 , V_223 [ type [ V_46 ] - 1 ] ,
V_243 [ V_46 ] ) ;
V_78 -> V_80 = type [ V_46 ] ;
V_78 -> V_130 = type [ V_46 ] == V_81 ? 8 :
V_245 [ V_46 ] ;
V_78 -> V_123 = V_246 ;
V_78 -> V_89 = F_63 ( V_243 [ V_46 ] , 0x4000 ) ;
if ( ! V_78 -> V_89 ) {
F_5 ( V_99 L_35 ,
V_243 [ V_46 ] ) ;
continue;
}
if ( F_47 ( V_78 , NULL ) ) {
F_57 ( V_78 -> V_89 ) ;
V_78 -> V_89 = NULL ;
continue;
}
F_5 ( V_225 L_36
L_37 ,
V_243 [ V_46 ] , V_78 -> V_130 ) ;
V_78 ++ ;
V_224 ++ ;
}
}
#ifdef F_76
V_138 = F_77 ( & V_247 ) ;
if ( V_138 ) {
F_5 ( V_99 L_38 ) ;
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
F_79 ( & V_247 ) ;
#endif
for ( V_46 = 0 ; V_46 < V_48 ; V_46 ++ )
if ( V_49 [ V_46 ] . V_53 )
F_55 ( & V_49 [ V_46 ] ) ;
F_80 ( & V_211 ) ;
if ( F_81 ( V_227 ) )
F_5 ( V_99 L_39
L_40 ) ;
F_74 ( V_227 ) ;
}
static void F_82 ( struct V_248 * V_64 )
{
struct V_26 * V_27 = F_83 ( V_64 , struct V_26 , V_64 ) ;
F_84 ( V_27 ) ;
F_15 ( V_27 , 2 ) ;
}
static int F_85 ( struct V_248 * V_64 )
{
struct V_26 * V_27 = F_83 ( V_64 , struct V_26 , V_64 ) ;
int V_63 ;
F_86 ( & V_64 -> V_249 ) ;
V_63 = V_27 -> V_140 ;
F_87 ( & V_64 -> V_249 ) ;
return V_63 ;
}
static void F_88 ( struct V_248 * V_64 , int V_250 )
{
struct V_26 * V_27 = F_83 ( V_64 , struct V_26 , V_64 ) ;
F_89 ( V_27 , V_250 , V_250 ) ;
}
static int F_90 ( struct V_24 * V_25 , struct V_199 * V_251 )
{
struct V_77 * V_78 ;
struct V_26 * V_27 ;
int V_64 ;
V_64 = V_25 -> V_31 ;
if ( V_64 == V_32 ) {
return F_91 ( V_252 ) ? 0 : - V_253 ;
}
if ( F_92 ( & V_214 ) )
return - V_254 ;
V_78 = & V_49 [ V_64 / V_51 ] ;
if ( ! V_78 -> V_53 ) {
F_26 ( & V_214 ) ;
return - V_37 ;
}
if ( V_64 % V_51 >= V_78 -> V_130 ) {
F_26 ( & V_214 ) ;
return - V_37 ;
}
V_27 = & V_78 -> V_50 [ V_64 % V_51 ] ;
V_27 -> V_64 . V_255 ++ ;
V_25 -> V_28 = V_27 ;
F_93 ( & V_27 -> V_64 , V_25 ) ;
F_24 ( & V_27 -> V_64 . V_69 ) ;
if ( ! ( V_27 -> V_64 . V_9 & V_215 ) ) {
V_27 -> V_256 = 0 ;
F_94 ( V_25 , V_25 -> V_65 ) ;
F_89 ( V_27 , 1 , 1 ) ;
F_95 ( V_27 ) ;
F_96 ( V_27 , V_27 -> type == V_204 ) ;
V_27 -> V_64 . V_9 |= V_215 ;
}
F_26 ( & V_27 -> V_64 . V_69 ) ;
F_26 ( & V_214 ) ;
return F_97 ( & V_27 -> V_64 , V_25 , V_251 ) ;
}
static void F_98 ( struct V_24 * V_25 , struct V_199 * V_251 )
{
struct V_26 * V_27 = V_25 -> V_28 ;
V_27 -> V_66 = V_25 -> V_65 -> V_67 ;
F_99 ( & V_27 -> V_64 , V_25 , V_251 ) ;
}
static int F_100 ( struct V_24 * V_25 ,
const unsigned char * V_87 , int V_255 )
{
struct V_26 * V_27 = V_25 -> V_28 ;
unsigned long V_9 ;
int V_16 ;
if ( V_27 == NULL )
return 0 ;
F_7 ( & V_52 , V_9 ) ;
V_16 = F_101 ( V_25 , V_87 , V_255 ) ;
F_9 ( & V_52 , V_9 ) ;
F_102 ( V_257 , & V_27 -> V_256 ) ;
return V_16 ;
}
static int F_103 ( struct V_24 * V_25 )
{
struct V_26 * V_27 ;
if ( V_25 -> V_258 )
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
F_15 ( V_27 , 1 ) ;
F_106 ( V_25 ) ;
}
static int F_107 ( struct V_24 * V_25 )
{
struct V_26 * V_27 = V_25 -> V_28 ;
int V_259 ;
V_259 = F_18 ( V_27 ) ;
if ( V_259 )
F_102 ( V_260 , & V_27 -> V_256 ) ;
return V_259 ;
}
static int F_108 ( struct V_24 * V_25 )
{
struct V_26 * V_27 = V_25 -> V_28 ;
int V_261 = 0 , V_262 , V_263 ;
F_109 ( V_27 , & V_262 , & V_263 ) ;
if ( V_262 )
V_261 |= V_264 ;
if ( V_263 )
V_261 |= V_265 ;
V_262 = F_21 ( V_27 ) ;
if ( V_262 & 1 )
V_261 |= V_266 ;
if ( V_262 & 2 )
V_261 |= V_267 ;
if ( V_262 & 4 )
V_261 |= V_268 ;
return V_261 ;
}
static int F_110 ( struct V_24 * V_25 ,
unsigned int V_269 , unsigned int V_270 )
{
struct V_26 * V_27 ;
int V_262 , V_263 ;
F_24 ( & V_214 ) ;
V_27 = V_25 -> V_28 ;
if ( ! V_27 ) {
F_26 ( & V_214 ) ;
return - V_36 ;
}
F_109 ( V_27 , & V_262 , & V_263 ) ;
if ( V_269 & V_265 )
V_263 = 1 ;
if ( V_269 & V_264 )
V_262 = 1 ;
if ( V_270 & V_265 )
V_263 = 0 ;
if ( V_270 & V_264 )
V_262 = 0 ;
F_89 ( V_27 , V_262 , V_263 ) ;
F_26 ( & V_214 ) ;
return 0 ;
}
static void F_111 ( struct V_24 * V_25 ,
struct V_271 * V_272 )
{
struct V_26 * V_27 = V_25 -> V_28 ;
if ( V_27 == NULL )
return;
F_94 ( V_25 , V_272 ) ;
if ( ! ( V_272 -> V_67 & V_208 ) && F_112 ( V_25 ) )
F_113 ( & V_27 -> V_64 . V_273 ) ;
}
static void F_114 ( struct V_24 * V_25 )
{
struct V_26 * V_27 = V_25 -> V_28 ;
if ( V_27 == NULL )
return;
F_115 ( V_27 ) ;
F_102 ( V_274 , & V_27 -> V_256 ) ;
}
static void F_116 ( struct V_24 * V_25 )
{
struct V_26 * V_27 = V_25 -> V_28 ;
if ( V_27 == NULL )
return;
if ( ! ( V_27 -> V_256 & V_274 ) )
return;
F_117 ( V_27 ) ;
F_118 ( V_274 , & V_27 -> V_256 ) ;
}
static void F_119 ( struct V_24 * V_25 )
{
struct V_26 * V_27 = V_25 -> V_28 ;
F_120 ( & V_27 -> V_64 ) ;
}
static void F_121 ( struct V_26 * V_45 , T_4 V_63 )
{
struct V_24 * V_25 ;
unsigned long V_9 ;
V_63 = ! ! V_63 ;
F_7 ( & V_45 -> V_64 . V_249 , V_9 ) ;
if ( V_63 != V_45 -> V_140 ) {
V_45 -> V_140 = V_63 ;
F_9 ( & V_45 -> V_64 . V_249 , V_9 ) ;
V_25 = F_22 ( & V_45 -> V_64 ) ;
if ( V_25 && F_112 ( V_25 ) && ! V_63 )
F_56 ( V_25 ) ;
F_23 ( V_25 ) ;
}
else
F_9 ( & V_45 -> V_64 . V_249 , V_9 ) ;
}
static int F_122 ( struct V_26 * V_45 , unsigned int V_275 ,
T_2 T_1 * V_276 )
{
struct V_24 * V_25 = F_22 ( & V_45 -> V_64 ) ;
void T_1 * V_1 ;
unsigned int V_277 = V_45 -> V_64 . V_9 & V_215 ;
T_2 V_278 ;
if ( V_25 ) {
if ( F_123 ( V_260 , & V_45 -> V_256 ) &&
F_18 ( V_45 ) == 0 ) {
F_118 ( V_260 , & V_45 -> V_256 ) ;
F_106 ( V_25 ) ;
}
if ( F_123 ( V_257 , & V_45 -> V_256 ) && ! V_25 -> V_258 &&
F_18 ( V_45 ) <= V_279 ) {
F_118 ( V_257 , & V_45 -> V_256 ) ;
F_106 ( V_25 ) ;
}
if ( V_277 && ! F_123 ( V_280 , & V_25 -> V_9 ) &&
F_17 ( V_45 ) > 0 ) {
F_124 ( V_45 ) ;
F_125 ( V_25 ) ;
}
} else {
F_118 ( V_260 , & V_45 -> V_256 ) ;
F_15 ( V_45 , 0 ) ;
}
if ( ! V_275 )
goto V_281;
V_278 = F_2 ( V_276 ) ;
if ( V_278 == 0 )
goto V_281;
F_8 ( 0 , V_276 ) ;
V_1 = V_45 -> V_73 ;
if ( V_278 & V_282 )
F_8 ( F_2 ( V_1 + V_283 ) & ~ V_284 ,
V_1 + V_283 ) ;
if ( ! V_277 )
goto V_281;
if ( V_25 && ( V_278 & V_285 ) && ! F_126 ( V_25 ) ) {
F_127 ( V_25 , 0 , V_286 ) ;
F_125 ( V_25 ) ;
}
if ( V_278 & V_287 )
F_121 ( V_45 , F_12 ( V_1 + V_17 ) & V_288 ) ;
V_281:
F_23 ( V_25 ) ;
return 0 ;
}
static void F_128 ( unsigned long V_289 )
{
struct V_77 * V_78 ;
T_2 T_1 * V_276 ;
unsigned int V_290 , V_64 , V_291 = 0 ;
F_129 ( & V_52 ) ;
for ( V_290 = 0 ; V_290 < V_48 ; V_290 ++ ) {
V_78 = & V_49 [ V_290 ] ;
if ( ! V_78 -> V_53 )
continue;
V_291 ++ ;
V_276 = NULL ;
if ( F_12 ( V_78 -> V_134 ) == 0xff )
V_276 = V_78 -> V_136 + F_12 ( V_78 -> V_132 ) ;
for ( V_64 = 0 ; V_64 < V_78 -> V_130 ; V_64 ++ )
F_122 ( & V_78 -> V_50 [ V_64 ] , ! ! V_276 , V_276 + V_64 ) ;
if ( V_276 )
F_33 ( 0 , V_78 -> V_134 ) ;
if ( V_292 ) {
struct V_26 * V_45 = V_78 -> V_50 ;
for ( V_64 = 0 ; V_64 < V_78 -> V_130 ; V_64 ++ , V_45 ++ )
if ( V_45 -> V_293 ) {
V_45 -> V_293 = 0 ;
F_11 ( V_45 -> V_73 ) ;
}
}
}
V_292 = 0 ;
if ( V_291 )
F_53 ( & V_211 , V_3 + V_212 / 50 ) ;
F_130 ( & V_52 ) ;
}
static void F_94 ( struct V_24 * V_25 , struct V_271 * V_272 )
{
register struct V_271 * V_294 = V_25 -> V_65 ;
struct V_26 * V_27 = V_25 -> V_28 ;
int V_263 , V_61 , V_295 , V_296 , V_297 , V_298 ;
V_263 = V_61 = V_295 = V_296 = V_297 = 0 ;
if ( V_294 -> V_67 & V_299 )
V_263 = V_61 = 1 ;
if ( V_294 -> V_300 & V_301 )
V_295 = 1 ;
if ( V_294 -> V_300 & V_302 )
V_296 = 1 ;
if ( V_294 -> V_300 & V_303 )
V_297 = 1 ;
V_294 -> V_67 &= ~ V_304 ;
F_131 ( V_27 , V_263 , V_61 , V_295 , V_296 , V_297 ) ;
V_298 = F_132 ( V_27 , V_294 , F_133 ( V_25 ) ) ;
if ( V_298 == - 1 )
V_298 = F_134 ( V_272 ) ;
F_135 ( V_25 , V_298 , V_298 ) ;
}
static void F_15 ( struct V_26 * V_64 , int V_305 )
{
void T_1 * V_1 ;
if ( V_305 < 0 || V_305 > 2 )
return;
V_1 = V_64 -> V_73 ;
F_6 ( V_1 , V_306 , V_305 ) ;
if ( V_305 != 1 ) {
V_64 -> V_293 = 0 ;
F_11 ( V_1 ) ;
}
}
static void F_95 ( struct V_26 * V_64 )
{
void T_1 * V_1 ;
T_2 V_307 = 512 ;
V_1 = V_64 -> V_73 ;
F_8 ( V_307 , V_1 + V_22 ) ;
if ( F_40 ( V_64 -> V_139 ) )
F_6 ( V_1 , V_308 , 0 ) ;
else
F_8 ( F_2 ( V_1 + V_283 ) | V_309 ,
V_1 + V_283 ) ;
F_6 ( V_1 , V_310 , V_76 ) ;
F_6 ( V_1 , V_306 , 2 ) ;
F_6 ( V_1 , V_311 , V_76 ) ;
F_21 ( V_64 ) ;
}
static void F_84 ( struct V_26 * V_64 )
{
void T_1 * V_1 = V_64 -> V_73 ;
F_6 ( V_1 , V_312 , 0 ) ;
F_6 ( V_1 , V_313 , V_76 ) ;
F_8 ( 0 , V_1 + V_283 ) ;
F_6 ( V_1 , V_314 , V_76 ) ;
}
static T_12 F_136 ( struct V_26 * V_64 , T_12 V_298 )
{
void T_1 * V_1 = V_64 -> V_73 ;
unsigned int clock , V_315 ;
T_12 V_316 ;
V_316 = F_40 ( V_64 -> V_139 ) ? 460800 : 921600 ;
if ( V_298 < 50 )
return 0 ;
if ( V_298 > V_316 )
V_298 = V_316 ;
clock = 921600 ;
V_315 = clock / V_298 ;
F_6 ( V_1 , V_317 , V_315 ) ;
V_298 = clock / V_315 ;
return V_298 ;
}
static int F_132 ( struct V_26 * V_64 , struct V_271 * V_318 ,
T_12 V_298 )
{
void T_1 * V_1 ;
T_13 V_305 = 0 ;
V_1 = V_64 -> V_73 ;
V_305 = V_318 -> V_67 & V_319 ;
if ( V_305 == V_320 )
V_305 = V_321 ;
else if ( V_305 == V_322 )
V_305 = V_323 ;
else if ( V_305 == V_324 )
V_305 = V_325 ;
else if ( V_305 == V_206 )
V_305 = V_326 ;
if ( V_318 -> V_67 & V_327 ) {
if ( V_305 == V_321 )
V_305 |= V_328 ;
else
V_305 |= V_329 ;
} else
V_305 |= V_330 ;
if ( V_318 -> V_67 & V_331 ) {
if ( V_318 -> V_67 & V_332 )
V_305 |= V_333 ;
else
V_305 |= V_334 ;
} else
V_305 |= V_335 ;
F_6 ( V_1 , V_336 , ( T_2 ) V_305 ) ;
if ( F_40 ( V_64 -> V_139 ) && V_298 >= 921600 )
return - 1 ;
V_298 = F_136 ( V_64 , V_298 ) ;
if ( V_318 -> V_300 & ( V_301 | V_302 | V_303 ) ) {
F_86 ( & V_10 ) ;
F_33 ( V_318 -> V_337 [ V_338 ] , V_1 + V_11 ) ;
F_33 ( V_318 -> V_337 [ V_339 ] , V_1 + V_340 ) ;
F_33 ( V_341 , V_1 + V_5 ) ;
F_1 ( V_1 ) ;
F_87 ( & V_10 ) ;
}
return V_298 ;
}
static int F_109 ( struct V_26 * V_64 , int * V_342 ,
int * V_343 )
{
if ( V_342 )
* V_342 = ! ! ( V_64 -> V_344 & V_345 ) ;
if ( V_343 )
* V_343 = ! ! ( V_64 -> V_344 & V_346 ) ;
return 0 ;
}
static void F_89 ( struct V_26 * V_64 , int V_262 , int V_263 )
{
T_4 V_305 = 0 ;
if ( V_262 )
V_305 |= V_345 ;
if ( V_263 )
V_305 |= V_346 ;
V_64 -> V_344 = V_305 ;
F_6 ( V_64 -> V_73 , V_347 , V_305 ) ;
}
static void F_131 ( struct V_26 * V_64 , int V_263 , int V_61 ,
int V_295 , int V_296 , int V_348 )
{
int V_305 = 0 ;
if ( V_263 )
V_305 |= V_349 ;
if ( V_61 )
V_305 |= V_350 ;
if ( V_295 )
V_305 |= V_351 ;
if ( V_296 )
V_305 |= V_352 ;
if ( V_348 )
V_305 |= V_353 ;
F_6 ( V_64 -> V_73 , V_312 , V_305 ) ;
}
static int F_21 ( struct V_26 * V_64 )
{
void T_1 * V_1 ;
int V_315 ;
V_1 = V_64 -> V_73 ;
if ( F_40 ( V_64 -> V_139 ) )
V_315 = F_10 ( V_1 , V_354 , 0 ) ;
else
V_315 = F_2 ( V_1 + V_17 ) >> 4 ;
V_315 &= 0x0B ;
if ( V_315 & 8 )
V_315 |= 4 ;
F_121 ( V_64 , V_315 & 8 ) ;
V_315 &= 7 ;
return V_315 ;
}
static int F_101 ( struct V_24 * V_25 ,
const unsigned char * V_355 , int V_16 )
{
struct V_26 * V_64 = V_25 -> V_28 ;
void T_1 * V_88 , * V_1 , * V_356 ;
unsigned int V_357 , V_358 ;
T_2 V_359 , V_360 , V_361 , V_362 , V_363 ;
T_2 V_364 , V_365 , V_366 ;
V_1 = V_64 -> V_73 ;
V_88 = V_64 -> V_139 -> V_89 ;
V_361 = F_2 ( V_1 + V_145 ) ;
V_362 = F_2 ( V_1 + V_152 ) ;
V_363 = F_2 ( V_1 + V_154 ) ;
V_360 = F_2 ( V_1 + V_367 ) ;
V_359 = F_2 ( V_1 + V_368 ) ;
V_357 = ( V_359 > V_360 ) ? ( V_359 - V_360 - 1 ) : ( V_359 - V_360 + V_361 ) ;
if ( V_357 > V_16 )
V_357 = V_16 ;
V_38 . V_369 [ V_64 -> V_64 . V_25 -> V_31 ] += V_357 ;
V_358 = V_357 ;
if ( V_362 == V_363 ) {
V_366 = F_2 ( V_1 + V_178 ) ;
F_8 ( V_362 , V_88 + V_91 ) ;
while ( V_357 > 0 ) {
if ( V_359 > V_360 )
V_16 = V_359 - V_360 - 1 ;
else
V_16 = V_361 + 1 - V_360 ;
V_16 = ( V_357 > V_16 ) ? V_16 : V_357 ;
V_356 = V_88 + V_102 + V_366 + V_360 ;
F_36 ( V_356 , V_355 , V_16 ) ;
V_355 += V_16 ;
V_360 = ( V_360 + V_16 ) & V_361 ;
V_357 -= V_16 ;
}
} else {
V_364 = V_362 + ( V_360 >> 13 ) ;
V_365 = V_360 & V_370 ;
while ( V_357 > 0 ) {
V_16 = V_371 - V_365 ;
if ( V_16 > V_357 )
V_16 = V_357 ;
F_33 ( V_364 , V_88 + V_91 ) ;
V_356 = V_88 + V_102 + V_365 ;
F_36 ( V_356 , V_355 , V_16 ) ;
V_355 += V_16 ;
if ( ++ V_364 == V_363 )
V_364 = V_362 ;
V_365 = 0 ;
V_357 -= V_16 ;
}
V_360 = ( V_360 + V_358 ) & V_361 ;
}
F_8 ( V_360 , V_1 + V_367 ) ;
F_33 ( 1 , V_1 + V_372 ) ;
return V_358 ;
}
static int F_124 ( struct V_26 * V_64 )
{
struct V_24 * V_25 = V_64 -> V_64 . V_25 ;
unsigned char * V_373 ;
void T_1 * V_88 , * V_1 , * V_356 ;
unsigned int V_255 , V_16 , V_358 ;
T_2 V_360 , V_374 , V_362 , V_363 ;
T_2 V_364 , V_365 , V_366 , V_359 ;
V_1 = V_64 -> V_73 ;
V_88 = V_64 -> V_139 -> V_89 ;
V_359 = F_2 ( V_1 + V_19 ) ;
V_360 = F_2 ( V_1 + V_20 ) ;
V_374 = F_2 ( V_1 + V_21 ) ;
V_362 = F_2 ( V_1 + V_148 ) ;
V_363 = F_2 ( V_1 + V_150 ) ;
V_255 = ( V_360 >= V_359 ) ? ( V_360 - V_359 ) : ( V_360 - V_359 + V_374 + 1 ) ;
if ( V_255 == 0 )
return 0 ;
V_358 = V_255 ;
V_38 . V_375 [ V_25 -> V_31 ] += V_358 ;
if ( V_362 == V_363 ) {
V_366 = F_2 ( V_1 + V_376 ) ;
F_8 ( V_362 , V_88 + V_91 ) ;
while ( V_255 > 0 ) {
V_356 = V_88 + V_102 + V_366 + V_359 ;
V_16 = ( V_360 >= V_359 ) ? ( V_360 - V_359 ) :
( V_374 + 1 - V_359 ) ;
V_16 = F_137 ( V_25 , & V_373 ,
F_138 ( V_16 , V_255 ) ) ;
F_139 ( V_373 , V_356 , V_16 ) ;
V_359 = ( V_359 + V_16 ) & V_374 ;
V_255 -= V_16 ;
}
} else {
V_364 = V_362 + ( V_359 >> 13 ) ;
V_365 = V_359 & V_370 ;
while ( V_255 > 0 ) {
F_8 ( V_364 , V_88 + V_91 ) ;
V_356 = V_88 + V_102 + V_365 ;
V_16 = F_137 ( V_25 , & V_373 ,
F_138 ( V_371 - V_365 , V_255 ) ) ;
F_139 ( V_373 , V_356 , V_16 ) ;
V_255 -= V_16 ;
V_365 = ( V_365 + V_16 ) & V_370 ;
if ( V_365 == 0 && ++ V_364 == V_363 )
V_364 = V_362 ;
}
V_359 = ( V_359 + V_358 ) & V_374 ;
}
F_8 ( V_359 , V_1 + V_19 ) ;
if ( F_12 ( V_1 + V_17 ) & V_18 ) {
V_292 = 1 ;
V_64 -> V_293 = 1 ;
}
return V_358 ;
}
static int F_18 ( struct V_26 * V_64 )
{
void T_1 * V_1 = V_64 -> V_73 ;
T_2 V_13 , V_14 , V_15 ;
V_13 = F_2 ( V_1 + V_368 ) ;
V_14 = F_2 ( V_1 + V_367 ) ;
V_15 = F_2 ( V_1 + V_145 ) ;
return ( V_14 - V_13 ) & V_15 ;
}
static int F_104 ( struct V_26 * V_64 )
{
void T_1 * V_1 = V_64 -> V_73 ;
T_2 V_13 , V_14 , V_15 ;
V_13 = F_2 ( V_1 + V_368 ) ;
V_14 = F_2 ( V_1 + V_367 ) ;
V_15 = F_2 ( V_1 + V_145 ) ;
return V_15 - ( ( V_14 - V_13 ) & V_15 ) ;
}
static int F_17 ( struct V_26 * V_64 )
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
F_6 ( V_64 -> V_73 , V_377 , V_76 ) ;
}
static void F_117 ( struct V_26 * V_64 )
{
F_6 ( V_64 -> V_73 , V_378 , V_76 ) ;
}
static int F_25 ( struct V_26 * V_379 ,
struct V_380 T_3 * V_381 )
{
struct V_380 V_44 = {
. type = V_379 -> type ,
. line = V_379 -> V_64 . V_25 -> V_31 ,
. V_9 = V_379 -> V_64 . V_9 ,
. V_382 = 921600 ,
. V_383 = V_379 -> V_64 . V_383
} ;
return F_14 ( V_381 , & V_44 , sizeof( * V_381 ) ) ? - V_40 : 0 ;
}
static int F_27 ( struct V_26 * V_379 ,
struct V_380 T_3 * V_384 )
{
struct V_380 V_385 ;
if ( F_140 ( & V_385 , V_384 , sizeof( V_385 ) ) )
return - V_40 ;
if ( V_385 . V_386 != 0 || V_385 . V_64 != 0 ||
V_385 . V_387 != 0 ||
V_385 . V_382 != 921600 )
return - V_253 ;
if ( ! F_91 ( V_252 ) ) {
if ( ( ( V_385 . V_9 & ~ V_388 ) !=
( V_379 -> V_64 . V_9 & ~ V_388 ) ) )
return - V_253 ;
} else
V_379 -> V_64 . V_383 = V_385 . V_383 * V_212 / 100 ;
V_385 . V_9 = ( V_385 . V_9 & ~ V_389 ) ;
V_385 . V_9 |= ( V_379 -> V_64 . V_9 & V_389 ) ;
F_96 ( V_379 , V_385 . type == V_204 ) ;
V_379 -> type = V_385 . type ;
return 0 ;
}
static void F_96 ( struct V_26 * V_64 , int V_390 )
{
void T_1 * V_1 = V_64 -> V_73 ;
if ( ! V_390 ) {
F_6 ( V_1 , V_391 , 0 ) ;
F_6 ( V_1 , V_392 , 1 ) ;
} else {
F_6 ( V_1 , V_391 , 3 ) ;
F_6 ( V_1 , V_392 , 16 ) ;
}
}
