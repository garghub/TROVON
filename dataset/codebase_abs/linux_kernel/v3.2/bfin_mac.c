static void F_1 ( void )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_5 ;
#if ! F_2 ( V_6 )
T_1 V_7 = 0 ;
#endif
if ( V_8 ) {
V_4 = V_9 ;
for ( V_5 = 0 ; V_5 < V_10 ; V_5 ++ ) {
if ( V_4 ) {
if ( V_4 -> V_11 ) {
F_3 ( V_4 -> V_11 ) ;
V_4 -> V_11 = NULL ;
}
V_4 = V_4 -> V_12 ;
}
}
F_4 ( V_7 , V_8 , V_10 ) ;
}
if ( V_13 ) {
V_2 = V_14 ;
for ( V_5 = 0 ; V_5 < V_15 ; V_5 ++ ) {
if ( V_2 ) {
if ( V_2 -> V_11 ) {
F_3 ( V_2 -> V_11 ) ;
V_2 -> V_11 = NULL ;
}
V_2 = V_2 -> V_12 ;
}
}
F_4 ( V_7 , V_13 , V_15 ) ;
}
}
static int F_5 ( void )
{
int V_5 ;
struct V_16 * V_17 ;
#if ! F_2 ( V_6 )
T_1 V_7 ;
#endif
V_8 = F_6 ( & V_7 ,
sizeof( struct V_3 ) ,
V_10 ) ;
if ( V_8 == NULL )
goto V_18;
V_13 = F_6 ( & V_7 ,
sizeof( struct V_1 ) ,
V_15 ) ;
if ( V_13 == NULL )
goto V_18;
V_9 = V_19 = V_8 ;
for ( V_5 = 0 ; V_5 < V_10 ; V_5 ++ ) {
struct V_3 * V_4 = V_8 + V_5 ;
struct V_20 * V_21 = & ( V_4 -> V_22 ) ;
struct V_20 * V_23 = & ( V_4 -> V_24 ) ;
V_21 -> V_25 = V_26 | V_27 | V_28 ;
V_21 -> V_29 = ( unsigned long ) V_4 -> V_30 ;
V_21 -> V_31 = 0 ;
V_21 -> V_32 = V_23 ;
V_23 -> V_25 = V_33 | V_34 | V_26 | V_27 | V_28 ;
V_23 -> V_29 = ( unsigned long ) ( & ( V_4 -> V_35 ) ) ;
V_23 -> V_31 = 0 ;
V_4 -> V_11 = NULL ;
V_19 -> V_24 . V_32 = V_21 ;
V_19 -> V_12 = V_4 ;
V_19 = V_4 ;
}
V_19 -> V_12 = V_9 ;
V_19 -> V_24 . V_32 = & ( V_9 -> V_22 ) ;
V_36 = V_9 ;
V_14 = V_37 = V_13 ;
for ( V_5 = 0 ; V_5 < V_15 ; V_5 ++ ) {
struct V_1 * V_2 = V_13 + V_5 ;
struct V_20 * V_21 = & ( V_2 -> V_22 ) ;
struct V_20 * V_23 = & ( V_2 -> V_24 ) ;
V_17 = F_7 ( V_38 + V_39 ) ;
if ( ! V_17 ) {
F_8 ( L_1 ) ;
goto V_18;
}
F_9 ( V_17 , V_39 ) ;
F_10 ( ( unsigned long ) V_17 -> V_40 ,
( unsigned long ) V_17 -> V_41 ) ;
V_2 -> V_11 = V_17 ;
V_21 -> V_25 = V_33 | V_34 | V_26 | V_27 | V_28 ;
V_21 -> V_29 = ( unsigned long ) V_17 -> V_42 - 2 ;
V_21 -> V_31 = 0 ;
V_21 -> V_32 = V_23 ;
V_23 -> V_25 = V_33 | V_34 | V_26 | V_43 |
V_27 | V_28 ;
V_23 -> V_29 = ( unsigned long ) ( & ( V_2 -> V_35 ) ) ;
V_23 -> V_31 = 0 ;
V_37 -> V_24 . V_32 = V_21 ;
V_37 -> V_12 = V_2 ;
V_37 = V_2 ;
}
V_37 -> V_12 = V_14 ;
V_37 -> V_24 . V_32 = & ( V_14 -> V_22 ) ;
V_44 = V_14 ;
return 0 ;
V_18:
F_1 () ;
F_11 ( L_2 ) ;
return - V_45 ;
}
static int F_12 ( void )
{
int V_46 = V_47 ;
while ( ( F_13 () ) & V_48 ) {
F_14 ( 1 ) ;
if ( V_46 -- < 0 ) {
F_11 ( L_3 ) ;
return - V_49 ;
}
}
return 0 ;
}
static int F_15 ( struct V_50 * V_51 , int V_52 , int V_53 )
{
int V_54 ;
V_54 = F_12 () ;
if ( V_54 )
return V_54 ;
F_16 ( F_17 ( ( V_55 ) V_52 ) |
F_18 ( ( V_55 ) V_53 ) |
V_48 ) ;
V_54 = F_12 () ;
if ( V_54 )
return V_54 ;
return ( int ) F_19 () ;
}
static int F_20 ( struct V_50 * V_51 , int V_52 , int V_53 ,
V_55 V_56 )
{
int V_54 ;
V_54 = F_12 () ;
if ( V_54 )
return V_54 ;
F_21 ( ( V_57 ) V_56 ) ;
F_16 ( F_17 ( ( V_55 ) V_52 ) |
F_18 ( ( V_55 ) V_53 ) |
V_58 |
V_48 ) ;
return F_12 () ;
}
static int F_22 ( struct V_50 * V_51 )
{
return 0 ;
}
static void F_23 ( struct V_59 * V_60 )
{
struct V_61 * V_62 = F_24 ( V_60 ) ;
struct V_63 * V_64 = V_62 -> V_64 ;
unsigned long V_65 ;
int V_66 = 0 ;
F_25 ( & V_62 -> V_67 , V_65 ) ;
if ( V_64 -> V_68 ) {
if ( V_64 -> V_69 != V_62 -> V_70 ) {
V_57 V_71 = F_26 () ;
V_66 = 1 ;
if ( V_64 -> V_69 )
V_71 |= V_72 ;
else
V_71 &= ~ ( V_72 ) ;
F_27 ( V_71 ) ;
V_62 -> V_70 = V_64 -> V_69 ;
}
if ( V_64 -> V_73 != V_62 -> V_74 ) {
if ( V_64 -> V_75 == V_76 ) {
V_57 V_71 = F_26 () ;
switch ( V_64 -> V_73 ) {
case 10 :
V_71 |= V_77 ;
break;
case 100 :
V_71 &= ~ V_77 ;
break;
default:
F_28 ( V_60 ,
L_4 ,
V_64 -> V_73 ) ;
break;
}
F_27 ( V_71 ) ;
}
V_66 = 1 ;
V_62 -> V_74 = V_64 -> V_73 ;
}
if ( ! V_62 -> V_78 ) {
V_66 = 1 ;
V_62 -> V_78 = 1 ;
}
} else if ( V_62 -> V_78 ) {
V_66 = 1 ;
V_62 -> V_78 = 0 ;
V_62 -> V_74 = 0 ;
V_62 -> V_70 = - 1 ;
}
if ( V_66 ) {
V_57 V_71 = F_26 () ;
F_29 ( V_64 ) ;
F_30 ( L_5 , V_71 ) ;
}
F_31 ( & V_62 -> V_67 , V_65 ) ;
}
static int F_32 ( struct V_59 * V_60 , int V_79 )
{
struct V_61 * V_62 = F_24 ( V_60 ) ;
struct V_63 * V_64 = NULL ;
unsigned short V_80 ;
int V_5 ;
V_57 V_81 , V_82 ;
if ( ! ( F_33 () & V_83 ) )
F_34 ( F_33 () | V_83 ) ;
V_81 = F_35 () ;
V_82 = ( ( V_81 / V_84 ) / 2 ) - 1 ;
V_80 = F_36 () ;
V_80 = ( V_80 & ~ V_85 ) | F_37 ( V_82 ) ;
F_38 ( V_80 ) ;
for ( V_5 = 0 ; V_5 < V_86 ; ++ V_5 ) {
struct V_63 * const V_87 = V_62 -> V_50 -> V_88 [ V_5 ] ;
if ( ! V_87 )
continue;
V_64 = V_87 ;
break;
}
if ( ! V_64 ) {
F_39 ( V_60 , L_6 ) ;
return - V_89 ;
}
if ( V_79 != V_76 &&
V_79 != V_90 ) {
F_39 ( V_60 , L_7 ) ;
return - V_91 ;
}
V_64 = F_40 ( V_60 , F_41 ( & V_64 -> V_60 ) , & F_23 ,
0 , V_79 ) ;
if ( F_42 ( V_64 ) ) {
F_39 ( V_60 , L_8 ) ;
return F_43 ( V_64 ) ;
}
V_64 -> V_92 &= ( V_93
| V_94
| V_95
| V_96
| V_97
| V_98 | V_99
| V_100
| V_101 ) ;
V_64 -> V_102 = V_64 -> V_92 ;
V_62 -> V_78 = 0 ;
V_62 -> V_74 = 0 ;
V_62 -> V_70 = - 1 ;
V_62 -> V_64 = V_64 ;
F_44 ( L_9
L_10 ,
V_64 -> V_103 -> V_104 , F_41 ( & V_64 -> V_60 ) , V_64 -> V_105 ,
V_84 , V_82 , V_81 / 1000000 ) ;
return 0 ;
}
static T_2 F_45 ( int V_105 , void * V_106 )
{
return V_107 ;
}
static int
F_46 ( struct V_59 * V_60 , struct V_108 * V_109 )
{
struct V_61 * V_62 = F_24 ( V_60 ) ;
if ( V_62 -> V_64 )
return F_47 ( V_62 -> V_64 , V_109 ) ;
return - V_91 ;
}
static int
F_48 ( struct V_59 * V_60 , struct V_108 * V_109 )
{
struct V_61 * V_62 = F_24 ( V_60 ) ;
if ( ! F_49 ( V_110 ) )
return - V_111 ;
if ( V_62 -> V_64 )
return F_50 ( V_62 -> V_64 , V_109 ) ;
return - V_91 ;
}
static void F_51 ( struct V_59 * V_60 ,
struct V_112 * V_113 )
{
strcpy ( V_113 -> V_114 , V_115 ) ;
strcpy ( V_113 -> V_116 , V_117 ) ;
strcpy ( V_113 -> V_118 , L_11 ) ;
strcpy ( V_113 -> V_119 , F_41 ( & V_60 -> V_60 ) ) ;
}
static void F_52 ( struct V_59 * V_60 ,
struct V_120 * V_121 )
{
struct V_61 * V_62 = F_24 ( V_60 ) ;
V_121 -> V_92 = V_122 ;
V_121 -> V_123 = V_62 -> V_124 ;
}
static int F_53 ( struct V_59 * V_60 ,
struct V_120 * V_121 )
{
struct V_61 * V_62 = F_24 ( V_60 ) ;
int V_125 ;
if ( V_121 -> V_123 & ( V_126 |
V_127 |
V_128 |
V_129 |
V_130 ) )
return - V_131 ;
V_62 -> V_124 = V_121 -> V_123 ;
if ( V_62 -> V_124 && ! V_62 -> V_132 ) {
V_125 = F_54 ( V_133 , F_45 ,
V_134 , L_12 , V_60 ) ;
if ( V_125 )
return V_125 ;
V_62 -> V_132 = true ;
}
if ( ! V_62 -> V_124 && V_62 -> V_132 ) {
F_55 ( V_133 , V_60 ) ;
V_62 -> V_132 = false ;
}
F_56 ( & V_60 -> V_60 , V_62 -> V_124 ) ;
return 0 ;
}
static void F_57 ( struct V_59 * V_60 )
{
struct V_61 * V_62 = F_24 ( V_60 ) ;
int V_5 ;
unsigned short V_80 ;
V_80 = F_36 () ;
for ( V_5 = 0 ; V_5 < V_86 ; ++ V_5 )
if ( V_62 -> V_50 -> V_105 [ V_5 ] != V_135 )
break;
if ( V_5 < V_86 )
V_80 |= V_136 ;
V_80 |= V_137 ;
#if F_2 ( V_138 )
V_80 |= V_139 ;
#else
V_80 &= ~ V_139 ;
#endif
F_38 ( V_80 ) ;
F_58 ( V_140 | V_141 ) ;
F_59 ( V_62 -> V_142 ) ;
F_60 ( V_62 -> V_143 ) ;
F_61 ( 0 ) ;
F_62 ( 4 ) ;
F_63 ( 0 ) ;
F_64 ( 0 ) ;
F_65 ( 0 ) ;
F_66 ( 4 ) ;
F_67 ( 0 ) ;
F_68 ( 0 ) ;
}
static void F_69 ( T_3 * V_144 )
{
V_57 V_145 = F_70 ( * ( V_146 * ) & V_144 [ 0 ] ) ;
V_55 V_147 = F_71 ( * ( V_148 * ) & V_144 [ 4 ] ) ;
F_72 ( V_145 ) ;
F_73 ( V_147 ) ;
}
static int F_74 ( struct V_59 * V_60 , void * V_149 )
{
struct V_150 * V_151 = V_149 ;
if ( F_75 ( V_60 ) )
return - V_152 ;
memcpy ( V_60 -> V_153 , V_151 -> V_154 , V_60 -> V_155 ) ;
F_69 ( V_60 -> V_153 ) ;
return 0 ;
}
static int F_76 ( struct V_59 * V_156 ,
struct V_157 * V_158 , int V_109 )
{
struct V_159 V_25 ;
struct V_61 * V_62 = F_24 ( V_156 ) ;
V_55 V_160 ;
V_57 V_161 , V_162 , V_163 , V_164 ;
if ( F_77 ( & V_25 , V_158 -> V_165 , sizeof( V_25 ) ) )
return - V_166 ;
F_30 ( L_13 ,
V_167 , V_25 . V_65 , V_25 . V_168 , V_25 . V_169 ) ;
if ( V_25 . V_65 )
return - V_91 ;
if ( ( V_25 . V_168 != V_170 ) &&
( V_25 . V_168 != V_171 ) )
return - V_172 ;
V_160 = F_78 () ;
switch ( V_25 . V_169 ) {
case V_173 :
V_163 = 0xFFFFFFFF ;
F_79 ( V_163 ) ;
break;
case V_174 :
case V_175 :
case V_176 :
V_160 &= ~ 0x1F00 ;
F_80 ( V_160 ) ;
V_164 = 0x4A24170C ;
F_81 ( V_164 ) ;
V_161 = 0x11040800 ;
F_82 ( V_161 ) ;
V_162 = 0x0140013F ;
F_83 ( V_162 ) ;
V_163 = 0xFFFFFFFC ;
F_79 ( V_163 ) ;
V_25 . V_169 = V_174 ;
break;
case V_177 :
case V_178 :
case V_179 :
V_160 &= ~ 0x1F00 ;
F_80 ( V_160 ) ;
V_164 = 0x2A24170C ;
F_81 ( V_164 ) ;
V_161 = 0x11040800 ;
F_82 ( V_161 ) ;
V_162 = 0x0140013F ;
F_83 ( V_162 ) ;
V_163 = 0xFFFFFFF0 ;
F_79 ( V_163 ) ;
V_25 . V_169 = V_177 ;
break;
case V_180 :
case V_181 :
case V_182 :
V_160 &= ~ 0x1100 ;
F_80 ( V_160 ) ;
V_164 = 0x0E24170C ;
F_81 ( V_164 ) ;
V_161 = 0x110488F7 ;
F_82 ( V_161 ) ;
V_162 = 0x0140013F ;
F_83 ( V_162 ) ;
V_163 = 0xFFFFFFF0 ;
F_79 ( V_163 ) ;
V_25 . V_169 = V_180 ;
break;
default:
return - V_172 ;
}
if ( V_25 . V_168 == V_170 &&
F_84 ( V_25 . V_169 ) ) {
V_160 &= ~ V_183 ;
F_80 ( V_160 ) ;
F_85 () ;
} else {
V_160 |= V_183 ;
F_80 ( V_160 ) ;
F_86 () ;
F_87 () ;
F_88 () ;
F_89 () ;
F_90 ( 0x00000000 ) ;
F_91 ( 0xFF800000 ) ;
F_85 () ;
V_62 -> V_184 . V_185 = 0 ;
F_92 ( & V_62 -> clock ,
& V_62 -> V_186 ,
F_93 ( F_94 () ) ) ;
F_95 ( & V_62 -> V_184 , 0 ) ;
}
V_62 -> V_187 = V_25 ;
return F_96 ( V_158 -> V_165 , & V_25 , sizeof( V_25 ) ) ?
- V_166 : 0 ;
}
static void F_97 ( char * V_188 , T_4 * V_189 , T_4 * V_190 , struct V_191 * V_192 )
{
T_4 V_193 = F_94 () ;
F_30 ( L_14 ,
V_167 , V_188 , V_189 -> V_194 . V_195 , V_189 -> V_194 . V_196 , V_190 -> V_194 . V_195 , V_190 -> V_194 . V_196 , V_193 . V_194 . V_195 ,
V_193 . V_194 . V_196 , V_192 -> V_197 , V_192 -> V_198 ) ;
}
static void F_98 ( struct V_59 * V_156 , struct V_16 * V_11 )
{
struct V_61 * V_62 = F_24 ( V_156 ) ;
if ( F_99 ( V_11 ) -> V_199 & V_200 ) {
int V_46 = V_47 ;
F_99 ( V_11 ) -> V_199 |= V_201 ;
while ( ( ! ( F_100 () & V_202 ) ) && ( -- V_46 ) )
F_14 ( 1 ) ;
if ( V_46 == 0 )
F_39 ( V_156 , L_15 ) ;
else {
struct V_203 V_204 ;
T_5 V_205 ;
T_5 V_206 ;
V_206 = F_88 () ;
V_206 |= ( T_5 ) F_89 () << 32 ;
memset ( & V_204 , 0 , sizeof( V_204 ) ) ;
V_205 = F_101 ( & V_62 -> clock ,
V_206 ) ;
F_95 ( & V_62 -> V_184 , V_205 ) ;
V_204 . V_207 = F_102 ( V_205 ) ;
V_204 . V_208 =
F_103 ( & V_62 -> V_184 , V_205 ) ;
F_104 ( V_11 , & V_204 ) ;
F_97 ( L_16 , & V_204 . V_207 , & V_204 . V_208 , & V_62 -> V_184 ) ;
}
}
}
static void F_105 ( struct V_59 * V_156 , struct V_16 * V_11 )
{
struct V_61 * V_62 = F_24 ( V_156 ) ;
V_57 V_209 ;
T_5 V_206 , V_205 ;
struct V_203 * V_204 ;
if ( F_84 ( V_62 -> V_187 . V_169 ) )
return;
V_209 = F_100 () & V_210 ;
if ( ! V_209 )
return;
V_204 = F_106 ( V_11 ) ;
V_206 = F_86 () ;
V_206 |= ( T_5 ) F_87 () << 32 ;
V_205 = F_101 ( & V_62 -> clock , V_206 ) ;
F_95 ( & V_62 -> V_184 , V_205 ) ;
memset ( V_204 , 0 , sizeof( * V_204 ) ) ;
V_204 -> V_207 = F_102 ( V_205 ) ;
V_204 -> V_208 = F_103 ( & V_62 -> V_184 , V_205 ) ;
F_97 ( L_17 , & V_204 -> V_207 , & V_204 -> V_208 , & V_62 -> V_184 ) ;
}
static T_6 F_107 ( const struct V_211 * V_212 )
{
T_5 V_213 ;
V_213 = F_108 () ;
V_213 |= ( T_5 ) F_109 () << 32ULL ;
return V_213 ;
}
static void F_110 ( struct V_59 * V_156 )
{
struct V_61 * V_62 = F_24 ( V_156 ) ;
T_5 V_214 ;
V_214 = V_215 * ( 1ULL << 32 ) ;
F_111 ( V_214 , F_35 () ) ;
F_112 ( ( V_57 ) V_214 ) ;
memset ( & V_62 -> V_186 , 0 , sizeof( V_62 -> V_186 ) ) ;
V_62 -> V_186 . V_216 = F_107 ;
V_62 -> V_186 . V_217 = F_113 ( 64 ) ;
V_62 -> V_186 . V_218 = 1000000000 / V_215 ;
V_62 -> V_186 . V_219 = 0 ;
memset ( & V_62 -> V_184 , 0 , sizeof( V_62 -> V_184 ) ) ;
V_62 -> V_184 . V_220 = & V_62 -> clock ;
V_62 -> V_184 . V_221 = F_94 ;
V_62 -> V_184 . V_222 = 10 ;
V_62 -> V_187 . V_169 = V_173 ;
V_62 -> V_187 . V_168 = V_170 ;
}
static inline void F_114 ( void )
{
do {
V_9 -> V_22 . V_25 &= ~ V_33 ;
V_9 -> V_35 . V_223 = 0 ;
if ( V_9 -> V_11 ) {
F_3 ( V_9 -> V_11 ) ;
V_9 -> V_11 = NULL ;
}
V_9 = V_9 -> V_12 ;
} while ( V_9 -> V_35 . V_223 != 0 );
}
static void F_115 ( struct V_61 * V_62 )
{
int V_46 = V_47 ;
if ( V_9 -> V_35 . V_223 != 0 )
F_114 () ;
if ( V_36 -> V_12 == V_9 ) {
while ( V_9 -> V_35 . V_223 == 0 ) {
F_14 ( 10 ) ;
if ( ! ( F_116 () & V_224 ) )
break;
if ( V_46 -- < 0 )
break;
}
if ( V_46 >= 0 )
F_114 () ;
else
F_117 ( V_62 -> V_225 ) ;
}
if ( V_36 -> V_12 != V_9 &&
F_118 ( V_62 -> V_225 ) )
F_119 ( V_62 -> V_225 ) ;
if ( V_9 != V_36 ) {
if ( F_118 ( V_62 -> V_225 ) )
V_62 -> V_226 . V_227 =
V_228 + ( V_229 >> 4 ) ;
else
V_62 -> V_226 . V_227 =
V_228 + V_229 ;
F_120 ( & V_62 -> V_226 ,
V_62 -> V_226 . V_227 ) ;
}
return;
}
static void F_121 ( unsigned long V_62 )
{
F_115 ( (struct V_61 * ) V_62 ) ;
}
static int F_122 ( struct V_16 * V_11 ,
struct V_59 * V_60 )
{
struct V_61 * V_62 = F_24 ( V_60 ) ;
V_55 * V_42 ;
V_57 V_230 = ( unsigned long ) ( V_11 -> V_42 ) & 0x3 ;
V_36 -> V_11 = V_11 ;
if ( V_230 == 0x2 ) {
V_42 = ( V_55 * ) ( V_11 -> V_42 ) - 1 ;
* V_42 = ( V_55 ) ( V_11 -> V_231 ) ;
if ( F_99 ( V_11 ) -> V_199 & V_200 )
* V_42 |= 0x1000 ;
V_36 -> V_22 . V_29 = ( V_57 ) V_42 ;
F_123 ( ( V_57 ) V_42 ,
( V_57 ) ( ( T_3 * ) V_42 + V_11 -> V_231 + 4 ) ) ;
} else {
* ( ( V_55 * ) ( V_36 -> V_30 ) ) = ( V_55 ) ( V_11 -> V_231 ) ;
if ( F_99 ( V_11 ) -> V_199 & V_200 )
* ( ( V_55 * ) ( V_36 -> V_30 ) ) |= 0x1000 ;
memcpy ( ( T_3 * ) ( V_36 -> V_30 + 2 ) , V_11 -> V_42 ,
V_11 -> V_231 ) ;
V_36 -> V_22 . V_29 =
( V_57 ) V_36 -> V_30 ;
F_123 (
( V_57 ) V_36 -> V_30 ,
( V_57 ) ( V_36 -> V_30 + V_11 -> V_231 + 2 ) ) ;
}
F_85 () ;
V_36 -> V_35 . V_223 = 0 ;
V_36 -> V_22 . V_25 |= V_33 ;
if ( F_116 () & V_224 )
goto V_232;
F_124 ( & ( V_36 -> V_22 ) ) ;
F_125 ( V_36 -> V_22 . V_25 ) ;
F_27 ( F_26 () | V_233 ) ;
V_232:
F_98 ( V_60 , V_11 ) ;
V_36 = V_36 -> V_12 ;
V_60 -> V_234 . V_235 ++ ;
V_60 -> V_234 . V_236 += ( V_11 -> V_231 ) ;
F_115 ( V_62 ) ;
return V_237 ;
}
static void F_126 ( struct V_59 * V_60 )
{
struct V_16 * V_11 , * V_17 ;
unsigned short V_231 ;
struct V_61 * V_62 V_238 = F_24 ( V_60 ) ;
#if F_2 ( V_138 )
unsigned int V_5 ;
unsigned char V_239 [ V_240 + 1 ] ;
#endif
if ( V_44 -> V_35 . V_223 & V_241 ) {
F_127 ( V_60 , L_18 ) ;
V_60 -> V_234 . V_242 ++ ;
goto V_232;
}
V_11 = V_44 -> V_11 ;
V_17 = F_7 ( V_38 + V_39 ) ;
if ( ! V_17 ) {
F_127 ( V_60 , L_19 ) ;
V_60 -> V_234 . V_242 ++ ;
goto V_232;
}
F_9 ( V_17 , V_39 ) ;
F_10 ( ( unsigned long ) V_17 -> V_40 ,
( unsigned long ) V_17 -> V_41 ) ;
V_44 -> V_11 = V_17 ;
V_44 -> V_22 . V_29 = ( unsigned long ) V_17 -> V_42 - 2 ;
V_231 = ( unsigned short ) ( ( V_44 -> V_35 . V_223 ) & V_243 ) ;
V_231 -= V_240 ;
F_128 ( V_11 , V_231 ) ;
V_11 -> V_244 = F_129 ( V_11 , V_60 ) ;
F_105 ( V_60 , V_11 ) ;
#if F_2 ( V_138 )
if ( V_11 -> V_42 [ V_245 ] == 0x45 ) {
V_11 -> V_246 = V_44 -> V_35 . V_247 ;
if ( V_11 -> V_231 % 2 ) {
V_239 [ 0 ] = 0 ;
for ( V_5 = 0 ; V_5 < V_240 ; V_5 ++ )
V_239 [ V_5 + 1 ] = ~ V_11 -> V_42 [ V_11 -> V_231 + V_5 ] ;
V_11 -> V_246 = F_130 ( V_239 , V_240 + 1 , V_11 -> V_246 ) ;
} else {
for ( V_5 = 0 ; V_5 < V_240 ; V_5 ++ )
V_239 [ V_5 ] = ~ V_11 -> V_42 [ V_11 -> V_231 + V_5 ] ;
V_11 -> V_246 = F_130 ( V_239 , V_240 , V_11 -> V_246 ) ;
}
V_11 -> V_248 = V_249 ;
}
#endif
F_131 ( V_11 ) ;
V_60 -> V_234 . V_250 ++ ;
V_60 -> V_234 . V_251 += V_231 ;
V_232:
V_44 -> V_35 . V_223 = 0x00000000 ;
V_44 = V_44 -> V_12 ;
}
static T_2 F_132 ( int V_105 , void * V_106 )
{
struct V_59 * V_60 = V_106 ;
int V_252 = 0 ;
V_253:
if ( V_44 -> V_35 . V_223 == 0 ) {
if ( V_252 == 0 ) {
if ( V_44 -> V_12 -> V_35 . V_223 != 0 ) {
V_44 = V_44 -> V_12 ;
goto V_254;
}
}
F_133 ( F_134 () |
V_255 | V_256 ) ;
return V_107 ;
}
V_254:
F_126 ( V_60 ) ;
V_252 ++ ;
goto V_253;
}
static void F_135 ( struct V_59 * V_60 )
{
struct V_61 * V_62 = F_24 ( V_60 ) ;
F_136 ( V_257 ) ;
F_132 ( V_257 , V_60 ) ;
F_115 ( V_62 ) ;
F_137 ( V_257 ) ;
}
static void F_138 ( void )
{
unsigned int V_71 ;
V_71 = F_26 () ;
V_71 &= ( ~ V_258 ) ;
V_71 &= ( ~ V_233 ) ;
F_27 ( V_71 ) ;
}
static int F_139 ( struct V_63 * V_64 )
{
int V_54 ;
V_57 V_71 ;
F_30 ( L_20 , V_167 ) ;
F_140 ( & ( V_14 -> V_22 ) ) ;
F_141 ( V_14 -> V_22 . V_25 ) ;
V_54 = F_12 () ;
if ( V_54 )
return V_54 ;
V_71 = F_26 () ;
if ( V_71 & V_72 )
V_71 |= V_259 ;
else
V_71 |= V_260 | V_261 | V_259 ;
V_71 |= V_258 ;
if ( V_64 -> V_75 == V_76 ) {
V_71 |= V_262 ;
#if F_2 ( V_263 ) || F_2 ( V_264 )
if ( V_265 < 3 ) {
V_71 |= V_233 ;
}
#endif
}
F_27 ( V_71 ) ;
return 0 ;
}
static void F_142 ( struct V_59 * V_60 )
{
struct V_61 * V_62 = F_24 ( V_60 ) ;
F_30 ( L_21 , V_60 -> V_104 , V_167 ) ;
F_138 () ;
F_143 ( & V_62 -> V_226 ) ;
while ( V_9 != V_36 ) {
V_9 -> V_22 . V_25 &= ~ V_33 ;
V_9 -> V_35 . V_223 = 0 ;
if ( V_9 -> V_11 ) {
F_3 ( V_9 -> V_11 ) ;
V_9 -> V_11 = NULL ;
}
V_9 = V_9 -> V_12 ;
}
if ( F_118 ( V_62 -> V_225 ) )
F_119 ( V_62 -> V_225 ) ;
F_139 ( V_62 -> V_64 ) ;
V_60 -> V_266 = V_228 ;
F_119 ( V_60 ) ;
}
static void F_144 ( struct V_59 * V_60 )
{
V_57 V_267 , V_268 ;
struct V_269 * V_270 ;
V_57 V_271 ;
V_267 = V_268 = 0 ;
F_145 (ha, dev) {
V_271 = F_146 ( V_272 , V_270 -> V_151 ) ;
V_271 >>= 26 ;
if ( V_271 & 0x20 )
V_267 |= 1 << ( V_271 & 0x1f ) ;
else
V_268 |= 1 << ( V_271 & 0x1f ) ;
}
F_147 ( V_267 ) ;
F_148 ( V_268 ) ;
}
static void F_149 ( struct V_59 * V_60 )
{
V_57 V_80 ;
if ( V_60 -> V_65 & V_273 ) {
F_150 ( V_60 , L_22 ) ;
V_80 = F_26 () ;
V_80 |= V_274 ;
F_27 ( V_80 ) ;
} else if ( V_60 -> V_65 & V_275 ) {
V_80 = F_26 () ;
V_80 |= V_276 ;
F_27 ( V_80 ) ;
} else if ( ! F_151 ( V_60 ) ) {
V_80 = F_26 () ;
V_80 |= V_277 ;
F_27 ( V_80 ) ;
F_144 ( V_60 ) ;
} else {
V_80 = F_26 () ;
V_80 &= ~ ( V_278 | V_276 ) ;
F_27 ( V_80 ) ;
}
}
static int F_152 ( struct V_59 * V_156 , struct V_157 * V_158 , int V_109 )
{
struct V_61 * V_62 = F_24 ( V_156 ) ;
if ( ! F_75 ( V_156 ) )
return - V_91 ;
switch ( V_109 ) {
case V_279 :
return F_76 ( V_156 , V_158 , V_109 ) ;
default:
if ( V_62 -> V_64 )
return F_153 ( V_62 -> V_64 , V_158 , V_109 ) ;
else
return - V_131 ;
}
}
static void F_154 ( struct V_59 * V_60 )
{
F_27 ( 0x00000000 ) ;
F_141 ( 0x0000 ) ;
F_125 ( 0x0000 ) ;
}
static int F_155 ( struct V_59 * V_60 )
{
struct V_61 * V_62 = F_24 ( V_60 ) ;
int V_54 ;
F_30 ( L_21 , V_60 -> V_104 , V_167 ) ;
if ( ! F_156 ( V_60 -> V_153 ) ) {
F_28 ( V_60 , L_23 ) ;
return - V_91 ;
}
V_54 = F_5 () ;
if ( V_54 )
return V_54 ;
F_157 ( V_62 -> V_64 ) ;
F_158 ( V_62 -> V_64 , V_280 , V_281 ) ;
F_57 ( V_60 ) ;
F_69 ( V_60 -> V_153 ) ;
F_138 () ;
V_54 = F_139 ( V_62 -> V_64 ) ;
if ( V_54 )
return V_54 ;
F_30 ( L_24 ) ;
F_159 ( V_60 ) ;
F_160 ( V_60 ) ;
return 0 ;
}
static int F_161 ( struct V_59 * V_60 )
{
struct V_61 * V_62 = F_24 ( V_60 ) ;
F_30 ( L_21 , V_60 -> V_104 , V_167 ) ;
F_117 ( V_60 ) ;
F_162 ( V_60 ) ;
F_163 ( V_62 -> V_64 ) ;
F_158 ( V_62 -> V_64 , V_280 , V_282 ) ;
F_154 ( V_60 ) ;
F_1 () ;
return 0 ;
}
static int T_7 F_164 ( struct V_283 * V_284 )
{
struct V_59 * V_225 ;
struct V_61 * V_62 ;
struct V_283 * V_285 ;
struct V_286 * V_287 ;
int V_125 ;
V_225 = F_165 ( sizeof( struct V_61 ) ) ;
if ( ! V_225 ) {
F_166 ( & V_284 -> V_60 , L_25 ) ;
return - V_45 ;
}
F_167 ( V_225 , & V_284 -> V_60 ) ;
F_168 ( V_284 , V_225 ) ;
V_62 = F_24 ( V_225 ) ;
V_62 -> V_225 = V_225 ;
* ( V_146 * ) ( & ( V_225 -> V_153 [ 0 ] ) ) = F_169 ( F_170 () ) ;
* ( V_148 * ) ( & ( V_225 -> V_153 [ 4 ] ) ) = F_171 ( ( V_55 ) F_172 () ) ;
F_72 ( 0x12345678 ) ;
if ( F_170 () != 0x12345678 ) {
F_166 ( & V_284 -> V_60 , L_26 ) ;
V_125 = - V_89 ;
goto V_288;
}
if ( ! F_156 ( V_225 -> V_153 ) )
F_173 ( V_225 -> V_153 ) ;
if ( ! F_156 ( V_225 -> V_153 ) )
F_174 ( V_225 -> V_153 ) ;
F_69 ( V_225 -> V_153 ) ;
if ( ! V_284 -> V_60 . V_289 ) {
F_166 ( & V_284 -> V_60 , L_27 ) ;
V_125 = - V_89 ;
goto V_288;
}
V_285 = V_284 -> V_60 . V_289 ;
V_62 -> V_50 = F_175 ( V_285 ) ;
if ( ! V_62 -> V_50 ) {
F_166 ( & V_284 -> V_60 , L_28 ) ;
V_125 = - V_89 ;
goto V_288;
}
V_62 -> V_50 -> V_290 = V_225 ;
V_287 = V_285 -> V_60 . V_289 ;
V_125 = F_32 ( V_225 , V_287 -> V_79 ) ;
if ( V_125 ) {
F_166 ( & V_284 -> V_60 , L_29 ) ;
goto V_291;
}
V_62 -> V_142 = V_292 | V_287 -> V_142 ;
V_62 -> V_143 = V_292 | V_287 -> V_143 ;
F_176 ( V_225 ) ;
V_225 -> V_293 = & V_294 ;
V_225 -> V_295 = & V_296 ;
F_177 ( & V_62 -> V_226 ) ;
V_62 -> V_226 . V_42 = ( unsigned long ) V_62 ;
V_62 -> V_226 . V_297 = F_121 ;
F_178 ( & V_62 -> V_67 ) ;
V_125 = F_54 ( V_257 , F_132 ,
V_134 , L_30 , V_225 ) ;
if ( V_125 ) {
F_166 ( & V_284 -> V_60 , L_31 ) ;
V_125 = - V_152 ;
goto V_298;
}
V_125 = F_179 ( V_225 ) ;
if ( V_125 ) {
F_166 ( & V_284 -> V_60 , L_32 ) ;
goto V_299;
}
F_110 ( V_225 ) ;
F_150 ( V_225 , L_33 , V_300 , V_117 ) ;
return 0 ;
V_299:
F_55 ( V_257 , V_225 ) ;
V_298:
V_291:
F_180 ( V_62 -> V_50 ) ;
F_181 ( V_62 -> V_50 ) ;
V_288:
F_168 ( V_284 , NULL ) ;
F_182 ( V_225 ) ;
return V_125 ;
}
static int T_8 F_183 ( struct V_283 * V_284 )
{
struct V_59 * V_225 = F_175 ( V_284 ) ;
struct V_61 * V_62 = F_24 ( V_225 ) ;
F_168 ( V_284 , NULL ) ;
V_62 -> V_50 -> V_290 = NULL ;
F_184 ( V_225 ) ;
F_55 ( V_257 , V_225 ) ;
F_182 ( V_225 ) ;
return 0 ;
}
static int F_185 ( struct V_283 * V_284 , T_9 V_301 )
{
struct V_59 * V_302 = F_175 ( V_284 ) ;
struct V_61 * V_62 = F_24 ( V_302 ) ;
if ( V_62 -> V_124 ) {
F_27 ( ( F_26 () & ~ V_233 ) | V_258 ) ;
F_186 ( V_303 ) ;
F_187 ( V_133 ) ;
} else {
if ( F_75 ( V_302 ) )
F_161 ( V_302 ) ;
}
return 0 ;
}
static int F_188 ( struct V_283 * V_284 )
{
struct V_59 * V_302 = F_175 ( V_284 ) ;
struct V_61 * V_62 = F_24 ( V_302 ) ;
if ( V_62 -> V_124 ) {
F_27 ( F_26 () | V_233 ) ;
F_186 ( 0 ) ;
F_189 ( V_133 ) ;
} else {
if ( F_75 ( V_302 ) )
F_155 ( V_302 ) ;
}
return 0 ;
}
static int T_7 F_190 ( struct V_283 * V_284 )
{
struct V_50 * V_304 ;
struct V_286 * V_305 ;
const unsigned short * V_306 ;
int V_125 , V_5 ;
V_305 = F_191 ( & V_284 -> V_60 ) ;
if ( ! V_305 ) {
F_166 ( & V_284 -> V_60 , L_34 ) ;
return - V_91 ;
}
V_306 = V_305 -> V_307 ;
V_125 = F_192 ( V_306 , V_115 ) ;
if ( V_125 ) {
F_166 ( & V_284 -> V_60 , L_35 ) ;
return V_125 ;
}
V_125 = - V_45 ;
V_304 = F_193 () ;
if ( V_304 == NULL )
goto V_308;
V_304 -> V_216 = F_15 ;
V_304 -> V_309 = F_20 ;
V_304 -> V_310 = F_22 ;
V_304 -> V_311 = & V_284 -> V_60 ;
V_304 -> V_104 = L_36 ;
V_304 -> V_312 = V_305 -> V_312 ;
snprintf ( V_304 -> V_313 , V_314 , L_37 ) ;
V_304 -> V_105 = F_194 ( sizeof( int ) * V_86 , V_315 ) ;
if ( ! V_304 -> V_105 )
goto V_316;
for ( V_5 = V_125 ; V_5 < V_86 ; ++ V_5 )
V_304 -> V_105 [ V_5 ] = V_135 ;
V_125 = F_195 ( V_305 -> V_317 , 0 , V_86 ) ;
if ( V_125 != V_305 -> V_317 )
F_166 ( & V_284 -> V_60 , L_38 ,
V_305 -> V_317 ) ;
for ( V_5 = 0 ; V_5 < V_125 ; ++ V_5 ) {
unsigned short V_318 = V_305 -> V_319 [ V_5 ] . V_151 ;
if ( V_318 < V_86 )
V_304 -> V_105 [ V_318 ] = V_305 -> V_319 [ V_5 ] . V_105 ;
else
F_166 ( & V_284 -> V_60 ,
L_39 ,
V_318 , V_5 ) ;
}
V_125 = F_196 ( V_304 ) ;
if ( V_125 ) {
F_166 ( & V_284 -> V_60 , L_40 ) ;
goto V_320;
}
F_168 ( V_284 , V_304 ) ;
return 0 ;
V_320:
F_197 ( V_304 -> V_105 ) ;
V_316:
F_181 ( V_304 ) ;
V_308:
F_198 ( V_306 ) ;
return V_125 ;
}
static int T_8 F_199 ( struct V_283 * V_284 )
{
struct V_50 * V_304 = F_175 ( V_284 ) ;
struct V_286 * V_305 =
F_191 ( & V_284 -> V_60 ) ;
F_168 ( V_284 , NULL ) ;
F_180 ( V_304 ) ;
F_197 ( V_304 -> V_105 ) ;
F_181 ( V_304 ) ;
F_198 ( V_305 -> V_307 ) ;
return 0 ;
}
static int T_10 F_200 ( void )
{
int V_54 ;
V_54 = F_201 ( & V_321 ) ;
if ( ! V_54 )
return F_201 ( & V_322 ) ;
return - V_89 ;
}
static void T_11 F_202 ( void )
{
F_203 ( & V_322 ) ;
F_203 ( & V_321 ) ;
}
