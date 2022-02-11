static void F_1 ( unsigned long V_1 , T_1 * V_2 , T_1 * V_3 )
{
T_1 V_4 , V_5 ;
V_4 = 0 ;
V_5 = 0 ;
if ( V_1 ) {
while ( ! ( V_1 & 0x1 ) ) {
V_1 = V_1 >> 1 ;
V_4 ++ ;
}
while ( V_1 & 0x1 ) {
V_1 = V_1 >> 1 ;
V_5 ++ ;
}
}
* V_2 = V_4 ;
* V_3 = V_5 ;
}
static T_2 F_2 ( struct V_6 * V_7 )
{
T_3 * V_8 ;
T_2 V_9 ;
void * * V_10 ;
T_4 V_11 = V_12 ;
unsigned long V_13 , V_3 = 0 ;
int V_14 ;
struct V_15 * V_16 ;
V_16 = (struct V_15 * ) ( unsigned long ) V_7 -> V_17 . V_15 ;
while ( V_16 && V_16 -> V_18 )
V_16 = (struct V_15 * ) ( unsigned long ) V_16 -> V_18 ;
V_9 = F_3 ( V_19 -> V_20 -> V_21 ,
V_22 , & V_11 ,
NULL , & V_3 , V_10 ) ;
if ( V_9 == V_23 ) {
V_9 = F_4 ( V_19 -> V_20 -> V_24 ,
V_25 , V_3 , & V_10 ) ;
if ( V_9 != V_26 )
return V_9 ;
V_9 = F_3 ( V_19 -> V_20 -> V_21 ,
V_22 , & V_11 ,
NULL , & V_3 , V_10 ) ;
}
if ( V_9 != V_26 )
goto V_27;
V_13 = V_3 / sizeof( void * ) ;
for ( V_14 = 0 ; V_14 < V_13 ; V_14 ++ ) {
void * V_28 = V_10 [ V_14 ] ;
T_5 V_29 ;
struct V_30 * V_31 ;
V_9 = F_4 ( V_19 -> V_20 -> V_32 ,
V_28 , & V_11 , & V_8 ) ;
if ( V_9 != V_26 )
continue;
if ( ! V_8 )
continue;
#ifdef F_5
V_9 = F_6 ( V_8 -> V_29 , V_8 ,
V_33 , 0 ,
& V_29 ) ;
#else
V_9 = F_3 ( V_8 -> V_29 , V_8 ,
V_33 , 0 , 0 ,
& V_29 ) ;
#endif
if ( V_9 != V_26 )
continue;
if ( ! V_8 -> V_34 || ! V_8 -> V_35 )
continue;
V_3 = V_8 -> V_35 + sizeof( * V_31 ) ;
V_9 = F_4 ( V_19 -> V_20 -> V_24 ,
V_25 , V_3 , & V_31 ) ;
if ( V_9 != V_26 )
continue;
V_31 -> V_16 . type = V_36 ;
V_31 -> V_16 . V_5 = V_3 - sizeof( struct V_15 ) ;
V_31 -> V_16 . V_18 = 0 ;
V_31 -> V_37 = V_8 -> V_35 ;
V_9 = F_3 ( V_8 -> V_8 . V_38 , V_8 ,
V_39 , V_40 ,
1 , & ( V_31 -> V_41 ) ) ;
if ( V_9 != V_26 )
goto V_42;
V_9 = F_3 ( V_8 -> V_8 . V_38 , V_8 ,
V_39 , V_43 ,
1 , & ( V_31 -> V_44 ) ) ;
if ( V_9 != V_26 )
goto V_42;
V_9 = F_3 ( V_8 -> V_45 , V_8 ,
& ( V_31 -> V_46 ) , & ( V_31 -> V_47 ) ,
& ( V_31 -> V_48 ) , & ( V_31 -> V_49 ) ) ;
if ( V_9 != V_26 )
goto V_42;
memcpy ( V_31 -> V_50 , V_8 -> V_34 , V_8 -> V_35 ) ;
if ( V_16 )
V_16 -> V_18 = ( unsigned long ) V_31 ;
else
V_7 -> V_17 . V_15 = ( unsigned long ) V_31 ;
V_16 = (struct V_15 * ) V_31 ;
continue;
V_42:
F_7 ( V_19 -> V_20 -> V_51 , V_31 ) ;
}
V_27:
F_7 ( V_19 -> V_20 -> V_51 , V_10 ) ;
return V_9 ;
}
static T_2 F_8 ( struct V_52 * V_53 , T_4 * V_54 ,
unsigned long V_3 )
{
struct V_55 * V_56 , * V_57 ;
struct V_58 V_59 ;
unsigned long V_60 ;
T_2 V_9 ;
void * * V_61 ;
T_6 V_62 , V_63 ;
T_7 V_64 , V_65 ;
T_7 V_66 ;
int V_67 ;
int V_14 ;
V_9 = F_4 ( V_19 -> V_20 -> V_24 ,
V_25 , V_3 , & V_61 ) ;
if ( V_9 != V_26 )
return V_9 ;
V_9 = F_3 ( V_19 -> V_20 -> V_21 ,
V_22 , V_54 ,
NULL , & V_3 , V_61 ) ;
if ( V_9 != V_26 )
goto V_27;
V_57 = NULL ;
V_60 = V_3 / sizeof( void * ) ;
for ( V_14 = 0 ; V_14 < V_60 ; V_14 ++ ) {
struct V_68 * V_69 ;
T_4 V_70 = V_71 ;
bool V_72 = false ;
void * V_73 ;
void * V_28 = V_61 [ V_14 ] ;
V_9 = F_4 ( V_19 -> V_20 -> V_32 ,
V_28 , V_54 , & V_56 ) ;
if ( V_9 != V_26 )
continue;
V_9 = F_4 ( V_19 -> V_20 -> V_32 ,
V_28 , & V_70 , & V_73 ) ;
if ( V_9 == V_26 )
V_72 = true ;
V_9 = F_6 ( V_56 -> V_74 , V_56 ,
V_56 -> V_75 -> V_75 , & V_3 , & V_69 ) ;
if ( V_9 == V_26 && ( ! V_57 || V_72 ) ) {
V_62 = V_69 -> V_76 ;
V_63 = V_69 -> V_77 ;
V_64 = V_56 -> V_75 -> V_78 ;
V_65 = V_56 -> V_75 -> V_79 ;
V_67 = V_69 -> V_67 ;
V_59 = V_69 -> V_80 ;
V_66 = V_69 -> V_66 ;
V_57 = V_56 ;
if ( V_72 )
break;
}
}
if ( ! V_57 )
goto V_27;
V_53 -> V_81 = V_82 ;
V_53 -> V_83 = V_62 ;
V_53 -> V_84 = V_63 ;
V_53 -> V_85 = V_64 ;
V_53 -> V_86 = 1 ;
if ( V_67 == V_87 ) {
V_53 -> V_88 = 32 ;
V_53 -> V_89 = V_66 * 4 ;
V_53 -> V_90 = 8 ;
V_53 -> V_91 = 0 ;
V_53 -> V_92 = 8 ;
V_53 -> V_93 = 8 ;
V_53 -> V_94 = 8 ;
V_53 -> V_95 = 16 ;
V_53 -> V_96 = 8 ;
V_53 -> V_97 = 24 ;
} else if ( V_67 == V_98 ) {
V_53 -> V_88 = 32 ;
V_53 -> V_89 = V_66 * 4 ;
V_53 -> V_90 = 8 ;
V_53 -> V_91 = 16 ;
V_53 -> V_92 = 8 ;
V_53 -> V_93 = 8 ;
V_53 -> V_94 = 8 ;
V_53 -> V_95 = 0 ;
V_53 -> V_96 = 8 ;
V_53 -> V_97 = 24 ;
} else if ( V_67 == V_99 ) {
F_1 ( V_59 . V_100 , & V_53 -> V_91 , & V_53 -> V_90 ) ;
F_1 ( V_59 . V_101 , & V_53 -> V_93 ,
& V_53 -> V_92 ) ;
F_1 ( V_59 . V_102 , & V_53 -> V_95 , & V_53 -> V_94 ) ;
F_1 ( V_59 . V_103 , & V_53 -> V_97 ,
& V_53 -> V_96 ) ;
V_53 -> V_88 = V_53 -> V_90 + V_53 -> V_92 +
V_53 -> V_94 + V_53 -> V_96 ;
V_53 -> V_89 = ( V_66 * V_53 -> V_88 ) / 8 ;
} else {
V_53 -> V_88 = 4 ;
V_53 -> V_89 = V_53 -> V_83 / 2 ;
V_53 -> V_90 = 0 ;
V_53 -> V_91 = 0 ;
V_53 -> V_92 = 0 ;
V_53 -> V_93 = 0 ;
V_53 -> V_94 = 0 ;
V_53 -> V_95 = 0 ;
V_53 -> V_96 = 0 ;
V_53 -> V_97 = 0 ;
}
V_53 -> V_104 = V_53 -> V_89 * V_53 -> V_84 ;
V_53 -> V_105 |= V_106 ;
V_27:
F_7 ( V_19 -> V_20 -> V_51 , V_61 ) ;
return V_9 ;
}
static T_2 F_9 ( struct V_52 * V_53 , T_4 * V_107 ,
unsigned long V_3 )
{
struct V_108 * V_109 , * V_110 ;
unsigned long V_111 ;
T_2 V_9 ;
T_7 V_62 , V_63 ;
void * * V_112 = NULL ;
int V_14 ;
V_9 = F_4 ( V_19 -> V_20 -> V_24 ,
V_25 , V_3 , & V_112 ) ;
if ( V_9 != V_26 )
return V_9 ;
V_9 = F_3 ( V_19 -> V_20 -> V_21 ,
V_22 , V_107 ,
NULL , & V_3 , V_112 ) ;
if ( V_9 != V_26 )
goto V_27;
V_110 = NULL ;
V_111 = V_3 / sizeof( void * ) ;
for ( V_14 = 0 ; V_14 < V_111 ; V_14 ++ ) {
T_4 V_113 = V_12 ;
void * V_114 = V_112 [ V_14 ] ;
T_7 V_115 , V_28 , V_116 , V_117 ;
void * V_118 ;
V_9 = F_4 ( V_19 -> V_20 -> V_32 ,
V_114 , V_107 , & V_109 ) ;
if ( V_9 != V_26 )
continue;
F_4 ( V_19 -> V_20 -> V_32 ,
V_114 , & V_113 , & V_118 ) ;
V_9 = F_3 ( V_109 -> V_119 , V_109 , & V_115 , & V_28 ,
& V_116 , & V_117 ) ;
if ( V_9 == V_26 && ( ! V_110 || V_118 ) ) {
V_62 = V_115 ;
V_63 = V_28 ;
if ( V_118 )
break;
V_110 = V_109 ;
}
}
if ( ! V_110 )
goto V_27;
V_53 -> V_81 = V_82 ;
V_53 -> V_88 = 32 ;
V_53 -> V_83 = V_62 ;
V_53 -> V_84 = V_63 ;
V_53 -> V_90 = 8 ;
V_53 -> V_91 = 16 ;
V_53 -> V_92 = 8 ;
V_53 -> V_93 = 8 ;
V_53 -> V_94 = 8 ;
V_53 -> V_95 = 0 ;
V_53 -> V_96 = 8 ;
V_53 -> V_97 = 24 ;
V_27:
F_7 ( V_19 -> V_20 -> V_51 , V_112 ) ;
return V_9 ;
}
void F_10 ( struct V_6 * V_6 )
{
T_4 V_120 = V_121 ;
struct V_52 * V_53 ;
T_4 V_107 = V_122 ;
T_2 V_9 ;
unsigned long V_3 ;
void * * V_61 = NULL ;
void * * V_112 = NULL ;
V_53 = & V_6 -> V_52 ;
memset ( V_53 , 0 , sizeof( * V_53 ) ) ;
V_3 = 0 ;
V_9 = F_3 ( V_19 -> V_20 -> V_21 ,
V_22 , & V_120 ,
NULL , & V_3 , V_61 ) ;
if ( V_9 == V_23 )
V_9 = F_8 ( V_53 , & V_120 , V_3 ) ;
if ( V_9 != V_26 ) {
V_3 = 0 ;
V_9 = F_3 ( V_19 -> V_20 -> V_21 ,
V_22 , & V_107 ,
NULL , & V_3 , V_112 ) ;
if ( V_9 == V_23 )
F_9 ( V_53 , & V_107 , V_3 ) ;
}
}
struct V_6 * F_11 ( void * V_114 , T_8 * V_123 )
{
struct V_6 * V_6 ;
struct V_124 * V_125 ;
struct V_126 * V_127 ;
struct V_128 * V_17 ;
struct V_129 * V_130 ;
T_9 * V_131 ;
void * V_132 ;
T_4 V_54 = V_133 ;
int V_134 = 0 ;
T_2 V_9 ;
char * V_135 ;
T_6 * V_136 ;
T_1 * V_137 ;
int V_14 ;
unsigned long V_138 ;
unsigned long V_139 ;
V_19 = V_123 ;
if ( V_19 -> V_17 . V_140 != V_141 )
return NULL ;
V_9 = F_4 ( V_19 -> V_20 -> V_32 ,
V_114 , & V_54 , ( void * ) & V_131 ) ;
if ( V_9 != V_26 ) {
F_12 ( V_19 , L_1 ) ;
return NULL ;
}
V_9 = F_13 ( V_19 , 0x4000 , 1 ,
( unsigned long * ) & V_6 ) ;
if ( V_9 != V_26 ) {
F_12 ( V_19 , L_2 ) ;
return NULL ;
}
memset ( V_6 , 0x0 , 0x4000 ) ;
V_17 = & V_6 -> V_17 ;
V_130 = & V_6 -> V_129 ;
V_127 = & V_6 -> V_126 ;
V_125 = & V_6 -> V_124 ;
memcpy ( & V_17 -> V_142 , V_131 -> V_143 + 512 , 512 ) ;
V_17 -> V_144 = 1 ;
V_17 -> V_145 = 0xffff ;
V_17 -> V_146 = 0xAA55 ;
V_17 -> V_147 = ( V_148 ) ( unsigned long ) V_131 -> V_143 ;
V_17 -> V_149 = 0x21 ;
V_135 = F_14 ( V_19 , V_131 ,
& V_134 ) ;
if ( ! V_135 )
goto V_150;
V_17 -> V_151 = ( unsigned long ) V_135 ;
V_17 -> V_152 = 0 ;
V_17 -> V_139 = 0 ;
memset ( V_127 , 0 , sizeof( * V_127 ) ) ;
memset ( V_125 , 0 , sizeof( * V_125 ) ) ;
V_9 = F_15 ( V_19 , V_131 ,
( char * ) ( unsigned long ) V_17 -> V_151 ,
L_3 , V_17 -> V_153 ,
& V_138 , & V_139 ) ;
if ( V_9 != V_26 )
goto V_154;
V_17 -> V_152 = V_138 ;
V_17 -> V_139 = V_139 ;
return V_6 ;
V_154:
F_16 ( V_19 , V_134 , V_17 -> V_151 ) ;
V_150:
F_16 ( V_19 , 0x4000 , ( unsigned long ) V_6 ) ;
return NULL ;
}
static void F_17 ( struct V_6 * V_7 ,
struct V_15 * V_155 , T_7 V_156 )
{
struct V_15 * V_16 ;
T_2 V_9 ;
unsigned long V_3 ;
V_155 -> type = V_157 ;
V_155 -> V_5 = V_156 * sizeof( struct V_158 ) ;
V_155 -> V_18 = 0 ;
V_16 = (struct V_15 * ) ( unsigned long ) V_7 -> V_17 . V_15 ;
while ( V_16 && V_16 -> V_18 )
V_16 = (struct V_15 * ) ( unsigned long ) V_16 -> V_18 ;
if ( V_16 )
V_16 -> V_18 = ( unsigned long ) V_155 ;
else
V_7 -> V_17 . V_15 = ( unsigned long ) V_155 ;
}
static T_2 F_18 ( struct V_6 * V_7 ,
struct V_15 * V_155 , T_7 V_159 )
{
struct V_158 * V_160 = & V_7 -> V_160 [ 0 ] ;
struct V_129 * V_130 = & V_7 -> V_129 ;
struct V_158 * V_161 = NULL ;
T_7 V_156 ;
T_7 V_162 ;
int V_14 ;
V_156 = 0 ;
V_162 = V_130 -> V_163 / V_130 -> V_164 ;
for ( V_14 = 0 ; V_14 < V_162 ; V_14 ++ ) {
T_10 * V_165 ;
unsigned int V_166 = 0 ;
unsigned long V_167 = V_130 -> V_168 ;
V_165 = ( T_10 * ) ( V_167 + ( V_14 * V_130 -> V_164 ) ) ;
switch ( V_165 -> type ) {
case V_169 :
case V_170 :
case V_171 :
case V_172 :
case V_173 :
case V_174 :
V_166 = V_175 ;
break;
case V_176 :
V_166 = V_177 ;
break;
case V_178 :
V_166 = V_179 ;
break;
case V_180 :
case V_25 :
case V_181 :
case V_182 :
case V_183 :
V_166 = V_184 ;
break;
case V_185 :
V_166 = V_186 ;
break;
default:
continue;
}
if ( V_161 && V_161 -> type == V_166 &&
( V_161 -> V_187 + V_161 -> V_3 ) == V_165 -> V_188 ) {
V_161 -> V_3 += V_165 -> V_189 << 12 ;
continue;
}
if ( V_156 == F_19 ( V_7 -> V_160 ) ) {
T_7 V_190 = ( V_162 - V_14 ) * sizeof( struct V_158 ) +
sizeof( struct V_15 ) ;
if ( ! V_155 || V_159 < V_190 )
return V_23 ;
V_160 = (struct V_158 * ) V_155 -> V_16 ;
}
V_160 -> V_187 = V_165 -> V_188 ;
V_160 -> V_3 = V_165 -> V_189 << V_191 ;
V_160 -> type = V_166 ;
V_161 = V_160 ++ ;
V_156 ++ ;
}
if ( V_156 > F_19 ( V_7 -> V_160 ) ) {
T_7 V_192 = V_156 - F_19 ( V_7 -> V_160 ) ;
F_17 ( V_7 , V_155 , V_192 ) ;
V_156 -= V_192 ;
}
V_7 -> V_193 = ( T_1 ) V_156 ;
return V_26 ;
}
static T_2 F_20 ( T_7 V_162 , struct V_15 * * V_155 ,
T_7 * V_159 )
{
T_2 V_9 ;
unsigned long V_3 ;
V_3 = sizeof( struct V_15 ) +
sizeof( struct V_158 ) * V_162 ;
if ( * V_155 ) {
F_7 ( V_19 -> V_20 -> V_51 , * V_155 ) ;
* V_155 = NULL ;
* V_159 = 0 ;
}
V_9 = F_4 ( V_19 -> V_20 -> V_24 ,
V_25 , V_3 , V_155 ) ;
if ( V_9 == V_26 )
* V_159 = V_3 ;
return V_9 ;
}
static T_2 F_21 ( struct V_6 * V_6 ,
void * V_114 )
{
struct V_129 * V_130 = & V_6 -> V_129 ;
unsigned long V_194 , V_195 , V_196 ;
T_10 * V_197 ;
struct V_15 * V_155 ;
T_11 V_159 ;
T_11 V_162 , V_198 ;
T_2 V_9 ;
T_11 V_199 ;
bool V_200 = false ;
T_1 V_156 ;
int V_14 ;
V_162 = 0 ;
V_155 = NULL ;
V_159 = 0 ;
V_201:
V_9 = F_22 ( V_19 , & V_197 , & V_194 , & V_196 ,
& V_199 , & V_195 ) ;
if ( V_9 != V_26 )
return V_9 ;
V_198 = V_162 ;
V_162 = V_194 / V_196 ;
if ( V_162 > V_198 &&
V_162 > F_19 ( V_6 -> V_160 ) ) {
T_7 V_192 = V_162 - F_19 ( V_6 -> V_160 ) ;
V_9 = F_20 ( V_192 , & V_155 , & V_159 ) ;
if ( V_9 != V_26 )
goto V_202;
F_7 ( V_19 -> V_20 -> V_51 , V_197 ) ;
goto V_201;
}
memcpy ( & V_130 -> V_203 , V_204 , sizeof( T_11 ) ) ;
V_130 -> V_205 = ( unsigned long ) V_19 ;
V_130 -> V_164 = V_196 ;
V_130 -> V_206 = V_199 ;
V_130 -> V_168 = ( unsigned long ) V_197 ;
V_130 -> V_163 = V_194 ;
#ifdef F_5
V_130 -> V_207 = ( unsigned long ) V_19 >> 32 ;
V_130 -> V_208 = ( unsigned long ) V_197 >> 32 ;
#endif
V_9 = F_23 ( V_19 -> V_20 -> V_209 ,
V_114 , V_195 ) ;
if ( V_9 != V_26 ) {
if ( V_200 )
goto V_202;
V_200 = true ;
F_7 ( V_19 -> V_20 -> V_51 , V_197 ) ;
goto V_201;
}
V_6 -> V_210 = 32 * 1024 ;
V_9 = F_18 ( V_6 , V_155 , V_159 ) ;
if ( V_9 != V_26 )
return V_9 ;
return V_26 ;
V_202:
F_7 ( V_19 -> V_20 -> V_51 , V_197 ) ;
return V_9 ;
}
struct V_6 * F_24 ( void * V_114 , T_8 * V_123 ,
struct V_6 * V_6 )
{
struct V_211 * V_212 ;
T_9 * V_131 ;
struct V_128 * V_17 = & V_6 -> V_17 ;
T_2 V_9 ;
struct V_213 * V_214 ;
V_19 = V_123 ;
if ( V_19 -> V_17 . V_140 != V_141 )
goto V_150;
F_10 ( V_6 ) ;
F_2 ( V_6 ) ;
V_9 = F_4 ( V_19 -> V_20 -> V_24 ,
V_25 , sizeof( * V_212 ) ,
( void * * ) & V_212 ) ;
if ( V_9 != V_26 ) {
F_12 ( V_19 , L_4 ) ;
goto V_150;
}
V_212 -> V_3 = 0x800 ;
V_9 = F_13 ( V_19 , V_212 -> V_3 , 8 ,
( unsigned long * ) & V_212 -> V_215 ) ;
if ( V_9 != V_26 ) {
F_12 ( V_19 , L_5 ) ;
goto V_150;
}
if ( V_17 -> V_216 != V_17 -> V_147 ) {
unsigned long V_217 = V_17 -> V_147 ;
V_9 = F_25 ( V_19 , & V_217 ,
V_17 -> V_218 , V_17 -> V_218 ,
V_17 -> V_216 ,
V_17 -> V_219 ) ;
if ( V_9 != V_26 )
goto V_150;
V_17 -> V_216 = V_17 -> V_147 ;
V_17 -> V_147 = V_217 ;
}
V_9 = F_21 ( V_6 , V_114 ) ;
if ( V_9 != V_26 )
goto V_150;
memset ( ( char * ) V_212 -> V_215 , 0x0 , V_212 -> V_3 ) ;
V_214 = (struct V_213 * ) V_212 -> V_215 ;
V_214 += 2 ;
V_214 -> V_220 = 0xffff ;
V_214 -> V_221 = 0x0000 ;
V_214 -> V_222 = 0x0000 ;
V_214 -> type = V_223 | V_224 ;
V_214 -> V_225 = V_226 ;
V_214 -> V_227 = 0 ;
V_214 -> V_228 = 1 ;
V_214 -> V_229 = 0xf ;
V_214 -> V_230 = 0 ;
V_214 -> V_231 = 0 ;
V_214 -> V_165 = V_232 ;
V_214 -> V_233 = V_234 ;
V_214 -> V_235 = 0x00 ;
V_214 ++ ;
V_214 -> V_220 = 0xffff ;
V_214 -> V_221 = 0x0000 ;
V_214 -> V_222 = 0x0000 ;
V_214 -> type = V_236 | V_237 ;
V_214 -> V_225 = V_226 ;
V_214 -> V_227 = 0 ;
V_214 -> V_228 = 1 ;
V_214 -> V_229 = 0xf ;
V_214 -> V_230 = 0 ;
V_214 -> V_231 = 0 ;
V_214 -> V_165 = V_232 ;
V_214 -> V_233 = V_234 ;
V_214 -> V_235 = 0x00 ;
#ifdef F_5
V_214 ++ ;
V_214 -> V_220 = 0x0000 ;
V_214 -> V_221 = 0x0000 ;
V_214 -> V_222 = 0x0000 ;
V_214 -> type = V_238 ;
V_214 -> V_225 = 0 ;
V_214 -> V_227 = 0 ;
V_214 -> V_228 = 1 ;
V_214 -> V_229 = 0x0 ;
V_214 -> V_230 = 0 ;
V_214 -> V_231 = 0 ;
V_214 -> V_165 = 0 ;
V_214 -> V_233 = V_234 ;
V_214 -> V_235 = 0x00 ;
#endif
asm volatile("cli");
asm volatile ("lgdt %0" : : "m" (*gdt));
return V_6 ;
V_150:
return NULL ;
}
