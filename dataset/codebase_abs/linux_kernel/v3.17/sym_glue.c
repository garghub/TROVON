static void F_1 ( void )
{
char * V_1 = V_2 ;
int V_3 = 0 ;
while ( V_1 && ( V_3 < 8 ) ) {
char * V_4 ;
int V_5 = ( int ) F_2 ( V_1 , & V_4 , 0 ) ;
V_6 . V_7 [ V_3 ++ ] = V_5 ;
V_1 = V_4 ;
}
if ( V_8 ) {
if ( * V_8 == 'y' ) {
V_6 . V_9 = 0 ;
V_6 . V_10 = 0 ;
V_6 . V_11 = 0 ;
V_6 . V_12 = 1 ;
V_6 . V_13 = 0 ;
V_6 . V_14 = 2 ;
V_6 . V_15 = 7 ;
V_6 . V_16 = 2 ;
V_6 . V_17 = 10 ;
V_6 . V_18 = 1 ;
} else if ( * V_8 != 'n' ) {
F_3 (KERN_WARNING NAME53C8XX L_1
L_2 , safe_string) ;
}
}
}
void F_4 ( struct V_19 * V_20 , struct V_21 * V_22 )
{
struct V_23 * V_24 = F_5 ( V_22 ) ;
F_6 ( sizeof( struct V_25 ) < sizeof( struct V_23 ) ) ;
if ( V_24 -> V_26 )
F_7 ( V_24 -> V_26 ) ;
F_8 ( V_22 ) ;
V_22 -> V_27 ( V_22 ) ;
}
void F_9 ( struct V_19 * V_20 )
{
F_10 ( L_3 , F_11 ( V_20 ) ) ;
V_20 -> V_28 . V_29 = V_30 + V_6 . V_17 * V_31 ;
V_20 -> V_28 . V_32 = 1 ;
if ( V_33 >= 2 )
F_12 ( L_4 ,
F_11 ( V_20 ) , V_6 . V_17 ) ;
}
static int F_13 ( int V_34 , int V_35 )
{
if ( V_35 ) {
if ( V_35 & V_36 )
V_34 = V_37 ;
else if ( V_35 & ( V_38 | V_39 | V_40 ) )
V_34 = V_41 ;
else if ( V_35 & V_42 )
V_34 = V_41 ;
else
V_34 = V_41 ;
}
return V_34 ;
}
void F_14 ( struct V_19 * V_20 , struct V_43 * V_44 , int V_45 )
{
struct V_21 * V_22 = V_44 -> V_22 ;
T_1 V_34 , V_46 , V_47 ;
V_47 = 0 ;
V_34 = V_48 ;
V_46 = V_44 -> V_49 ;
if ( V_44 -> V_50 & V_51 ) {
V_46 = V_44 -> V_52 ;
V_45 = V_44 -> V_53 ;
if ( V_33 && V_44 -> V_54 )
F_15 ( V_22 , V_44 -> V_54 ) ;
if ( V_44 -> V_55 == V_56 &&
V_44 -> V_49 == V_57 &&
V_44 -> V_58 == 0 ) {
V_34 = F_13 ( V_48 ,
V_44 -> V_54 ) ;
V_47 = V_59 ;
memset ( V_22 -> V_60 , 0 , V_61 ) ;
memcpy ( V_22 -> V_60 , V_44 -> V_62 ,
F_16 ( V_61 , V_63 ) ) ;
#if 0
if (1) {
u_char *p;
p = (u_char *) cmd->sense_data;
if (p[0]==0x70 && p[2]==0x6 && p[12]==0x29)
sym_clear_tasks(np, DID_ABORT,
cp->target,cp->lun, -1);
}
#endif
} else {
F_17 ( V_20 , V_22 -> V_64 -> V_65 ) ;
V_34 = V_41 ;
}
} else if ( V_44 -> V_55 == V_56 )
V_34 = V_48 ;
else if ( V_44 -> V_55 == V_66 )
V_34 = V_67 ;
else if ( V_44 -> V_55 == V_68 )
V_34 = V_41 ;
else {
if ( V_33 ) {
F_18 ( V_22 , L_5 ,
V_44 -> V_55 , V_44 -> V_49 ,
V_44 -> V_58 ) ;
}
V_34 = F_13 ( V_41 , V_44 -> V_58 ) ;
}
F_19 ( V_22 , V_45 ) ;
V_22 -> V_69 = ( V_47 << 24 ) + ( V_34 << 16 ) + V_46 ;
}
static int F_20 ( struct V_19 * V_20 , struct V_43 * V_44 , struct V_21 * V_22 )
{
int V_70 ;
int V_71 ;
V_44 -> V_72 = 0 ;
V_71 = F_21 ( V_22 ) ;
if ( V_71 > 0 ) {
struct V_73 * V_74 ;
struct V_75 * V_76 = & V_20 -> V_77 [ V_44 -> V_77 ] ;
struct V_78 * V_79 ;
if ( V_71 > V_80 ) {
F_8 ( V_22 ) ;
return - 1 ;
}
V_79 = & V_44 -> V_81 . V_79 [ V_80 - V_71 ] ;
F_22 (cmd, sg, use_sg, segment) {
T_2 V_82 = F_23 ( V_74 ) ;
unsigned int V_83 = F_24 ( V_74 ) ;
if ( ( V_83 & 1 ) && ( V_76 -> V_84 . V_85 & V_86 ) ) {
V_83 ++ ;
V_44 -> V_87 ++ ;
}
F_25 ( V_20 , & V_79 [ V_70 ] , V_82 , V_83 ) ;
V_44 -> V_72 += V_83 ;
}
} else {
V_70 = - 2 ;
}
return V_70 ;
}
static int F_26 ( struct V_19 * V_20 , struct V_21 * V_22 )
{
struct V_88 * V_89 = V_22 -> V_64 ;
struct V_75 * V_76 ;
struct V_90 * V_91 ;
struct V_43 * V_44 ;
int V_92 ;
V_76 = & V_20 -> V_77 [ V_89 -> V_65 ] ;
V_91 = F_27 ( V_76 , V_89 -> V_93 ) ;
V_92 = ( V_91 && V_91 -> V_28 . V_94 ) ? V_95 : 0 ;
V_44 = F_28 ( V_20 , V_22 , V_92 ) ;
if ( ! V_44 )
return 1 ;
F_29 ( V_20 , V_22 , V_44 ) ;
return 0 ;
}
static inline int F_30 ( struct V_19 * V_20 , struct V_21 * V_22 , struct V_43 * V_44 )
{
memcpy ( V_44 -> V_96 , V_22 -> V_97 , V_22 -> V_98 ) ;
V_44 -> V_81 . V_22 . V_99 = F_31 ( V_44 , V_96 [ 0 ] ) ;
V_44 -> V_81 . V_22 . V_100 = F_32 ( V_22 -> V_98 ) ;
return 0 ;
}
int F_33 ( struct V_19 * V_20 , struct V_21 * V_22 , struct V_43 * V_44 )
{
T_3 V_101 , V_102 ;
int V_103 ;
if ( F_30 ( V_20 , V_22 , V_44 ) )
goto V_104;
V_103 = V_22 -> V_105 ;
if ( V_103 != V_106 ) {
V_44 -> V_107 = F_20 ( V_20 , V_44 , V_22 ) ;
if ( V_44 -> V_107 < 0 ) {
F_34 ( V_22 , V_41 ) ;
goto V_104;
}
if ( ! V_44 -> V_107 )
V_103 = V_106 ;
} else {
V_44 -> V_72 = 0 ;
V_44 -> V_107 = 0 ;
}
switch ( V_103 ) {
case V_108 :
F_35 ( V_109 , V_22 , L_6 ) ;
F_34 ( V_22 , V_41 ) ;
goto V_104;
case V_110 :
V_102 = F_36 ( V_20 , V_111 ) + 8 ;
V_101 = V_102 - 8 - ( V_44 -> V_107 * ( 2 * 4 ) ) ;
break;
case V_112 :
V_44 -> V_50 |= V_113 ;
V_102 = F_36 ( V_20 , V_114 ) + 8 ;
V_101 = V_102 - 8 - ( V_44 -> V_107 * ( 2 * 4 ) ) ;
break;
case V_106 :
default:
V_101 = V_102 = F_37 ( V_20 , V_115 ) ;
break;
}
V_44 -> V_81 . V_84 . V_101 = F_32 ( V_101 ) ;
V_44 -> V_81 . V_84 . V_116 = F_32 ( V_101 ) ;
V_44 -> V_117 = V_44 -> V_81 . V_84 . V_116 ;
V_44 -> V_102 = F_32 ( V_102 ) ;
#if 0
switch (cp->cdb_buf[0]) {
case 0x0A: case 0x2A: case 0xAA:
panic("XXXXXXXXXXXXX WRITE NOT YET ALLOWED XXXXXXXXXXXXXX\n");
break;
default:
break;
}
#endif
F_38 ( V_20 , V_44 ) ;
return 0 ;
V_104:
F_39 ( V_20 , V_44 ) ;
F_4 ( V_20 , V_22 ) ;
return 0 ;
}
static void F_40 ( struct V_19 * V_20 )
{
unsigned long V_118 = V_30 ;
V_20 -> V_28 . V_119 . V_120 = V_118 + V_121 ;
F_41 ( & V_20 -> V_28 . V_119 ) ;
if ( V_20 -> V_28 . V_32 ) {
if ( F_42 ( V_20 -> V_28 . V_29 , V_118 ) ) {
if ( V_33 >= 2 )
F_3 ( L_7 ,
F_11 ( V_20 ) ) ;
V_20 -> V_28 . V_32 = 0 ;
}
return;
}
if ( V_20 -> V_28 . V_122 + 4 * V_31 < V_118 ) {
V_20 -> V_28 . V_122 = V_118 ;
}
#ifdef F_43
F_44 ( V_20 ) ;
#endif
}
void F_45 ( struct V_123 * V_124 )
{
struct V_125 * V_125 = F_46 ( V_124 ) ;
struct V_126 * V_127 = V_125 -> V_127 ;
unsigned short V_128 ;
F_47 ( V_127 , V_129 , & V_128 ) ;
if ( V_128 & 0xf900 ) {
F_48 ( V_127 , V_129 , V_128 ) ;
F_49 ( V_130 , V_124 ,
L_8 , V_128 & 0xf900 ) ;
}
}
static int F_50 ( struct V_21 * V_22 ,
void (* F_51)( struct V_21 * ) )
{
struct V_19 * V_20 = F_52 ( V_22 ) ;
struct V_23 * V_131 = F_5 ( V_22 ) ;
int V_132 = 0 ;
V_22 -> V_27 = F_51 ;
memset ( V_131 , 0 , sizeof( * V_131 ) ) ;
if ( V_20 -> V_28 . V_32 && V_22 -> V_133 -> V_134 ) {
unsigned long V_135 = V_30 + V_22 -> V_133 -> V_134 ;
V_135 -= V_121 * 2 ;
if ( F_53 ( V_20 -> V_28 . V_29 , V_135 ) ) {
V_20 -> V_28 . V_29 = V_135 ;
}
}
if ( V_20 -> V_28 . V_32 )
return V_136 ;
V_132 = F_26 ( V_20 , V_22 ) ;
if ( V_132 )
return V_136 ;
return 0 ;
}
void F_54 ( unsigned long V_137 )
{
struct V_19 * V_20 = (struct V_19 * ) V_137 ;
unsigned long V_138 ;
F_55 ( V_20 -> V_28 . V_139 -> V_140 , V_138 ) ;
F_40 ( V_20 ) ;
F_56 ( V_20 -> V_28 . V_139 -> V_140 , V_138 ) ;
}
static int F_57 ( int V_141 , char * V_142 , struct V_21 * V_22 )
{
struct V_23 * V_24 = F_5 ( V_22 ) ;
struct V_123 * V_124 = V_22 -> V_64 -> V_139 ;
struct V_125 * V_125 = F_46 ( V_124 ) ;
struct V_126 * V_127 = V_125 -> V_127 ;
struct V_19 * V_20 = V_125 -> V_143 ;
T_4 * V_144 ;
int V_145 = 0 ;
int V_132 = - 1 ;
struct V_146 V_26 ;
F_35 ( V_130 , V_22 , L_9 , V_142 ) ;
#define F_58 35
if ( F_59 ( V_127 ) ) {
int V_147 = 0 ;
F_60 ( & V_26 ) ;
F_61 ( V_124 -> V_140 ) ;
if ( F_59 ( V_127 ) ) {
F_62 ( V_125 -> V_148 ) ;
V_125 -> V_148 = & V_26 ;
} else {
V_147 = 1 ;
}
F_63 ( V_124 -> V_140 ) ;
if ( ! V_147 )
V_147 = F_64
( V_125 -> V_148 ,
F_58 * V_31 ) ;
F_61 ( V_124 -> V_140 ) ;
V_125 -> V_148 = NULL ;
F_63 ( V_124 -> V_140 ) ;
if ( ! V_147 )
return V_149 ;
}
F_61 ( V_124 -> V_140 ) ;
F_65 (&np->busy_ccbq, qp) {
struct V_43 * V_44 = F_66 ( V_144 , struct V_43 , V_150 ) ;
if ( V_44 -> V_22 == V_22 ) {
V_145 = 1 ;
break;
}
}
V_132 = - 1 ;
switch( V_141 ) {
case V_151 :
V_132 = F_67 ( V_20 , V_22 , 1 ) ;
break;
case V_152 :
V_132 = F_17 ( V_20 , V_22 -> V_64 -> V_65 ) ;
break;
case V_153 :
F_68 ( V_20 , 1 ) ;
V_132 = 0 ;
break;
case V_154 :
F_68 ( V_20 , 0 ) ;
F_69 ( V_124 , 1 ) ;
V_132 = 0 ;
break;
default:
break;
}
if ( V_132 )
V_145 = 0 ;
if ( V_145 ) {
F_60 ( & V_26 ) ;
V_24 -> V_26 = & V_26 ;
F_63 ( V_124 -> V_140 ) ;
if ( ! F_64 ( & V_26 , 5 * V_31 ) ) {
V_24 -> V_26 = NULL ;
V_132 = - 2 ;
}
} else {
F_63 ( V_124 -> V_140 ) ;
}
F_70 ( & V_22 -> V_64 -> V_155 , L_10 , V_142 ,
V_132 == 0 ? L_11 : V_132 == - 2 ? L_12 : L_13 ) ;
return V_132 ? V_149 : V_156 ;
}
static int F_71 ( struct V_21 * V_22 )
{
return F_57 ( V_151 , L_14 , V_22 ) ;
}
static int F_72 ( struct V_21 * V_22 )
{
return F_57 ( V_152 , L_15 , V_22 ) ;
}
static int F_73 ( struct V_21 * V_22 )
{
return F_57 ( V_153 , L_16 , V_22 ) ;
}
static int F_74 ( struct V_21 * V_22 )
{
return F_57 ( V_154 , L_17 , V_22 ) ;
}
static void F_75 ( struct V_75 * V_76 , int V_93 , T_5 V_94 )
{
struct V_90 * V_91 = F_27 ( V_76 , V_93 ) ;
T_5 V_157 ;
if ( ! V_91 )
return;
V_157 = V_91 -> V_28 . V_94 ;
if ( V_94 > V_91 -> V_28 . V_158 )
V_94 = V_91 -> V_28 . V_158 ;
V_91 -> V_28 . V_94 = V_94 ;
if ( V_94 != V_157 ) {
F_76 ( & V_76 -> V_159 -> V_160 ,
L_18 ,
V_91 -> V_28 . V_94 ? L_19 : L_20 , V_94 ) ;
}
}
static int F_77 ( struct V_88 * V_89 )
{
struct V_19 * V_20 = F_78 ( V_89 -> V_139 ) ;
struct V_75 * V_76 = & V_20 -> V_77 [ V_89 -> V_65 ] ;
struct V_90 * V_91 ;
unsigned long V_138 ;
int error ;
if ( V_89 -> V_65 >= V_161 || V_89 -> V_93 >= V_162 )
return - V_163 ;
F_55 ( V_20 -> V_28 . V_139 -> V_140 , V_138 ) ;
if ( V_76 -> V_164 & V_165 ) {
V_76 -> V_164 &= ~ V_165 ;
F_79 ( V_109 , V_89 -> V_166 ,
L_21 ) ;
error = - V_163 ;
goto V_167;
}
if ( V_76 -> V_164 & V_168 ) {
if ( V_89 -> V_93 != 0 ) {
error = - V_163 ;
goto V_167;
}
F_79 ( V_109 , V_89 -> V_166 ,
L_22 ) ;
}
V_91 = F_80 ( V_20 , V_89 -> V_65 , V_89 -> V_93 ) ;
if ( ! V_91 ) {
error = - V_169 ;
goto V_167;
}
if ( V_76 -> V_170 == 1 )
V_76 -> V_159 = V_89 -> V_166 ;
F_81 ( V_76 -> V_159 ) = V_76 -> V_171 ;
F_82 ( V_76 -> V_159 ) = V_76 -> V_172 ;
error = 0 ;
V_167:
F_56 ( V_20 -> V_28 . V_139 -> V_140 , V_138 ) ;
return error ;
}
static int F_83 ( struct V_88 * V_89 )
{
struct V_19 * V_20 = F_78 ( V_89 -> V_139 ) ;
struct V_75 * V_76 = & V_20 -> V_77 [ V_89 -> V_65 ] ;
struct V_90 * V_91 = F_27 ( V_76 , V_89 -> V_93 ) ;
int V_94 , V_173 ;
V_91 -> V_174 = V_91 -> V_175 ;
V_94 = V_6 . V_9 ;
if ( V_94 > V_76 -> V_176 )
V_94 = V_76 -> V_176 ;
if ( ! V_89 -> V_177 )
V_94 = 0 ;
if ( V_94 > V_178 )
V_94 = V_178 ;
V_173 = V_94 ? V_94 : 1 ;
F_84 ( V_89 ,
V_89 -> V_177 ? V_179 : 0 ,
V_173 ) ;
V_91 -> V_28 . V_158 = V_173 ;
F_75 ( V_76 , V_89 -> V_93 , V_94 ) ;
if ( ! F_85 ( V_89 -> V_166 ) )
F_86 ( V_89 ) ;
return 0 ;
}
static void F_87 ( struct V_88 * V_89 )
{
struct V_19 * V_20 = F_78 ( V_89 -> V_139 ) ;
struct V_75 * V_76 = & V_20 -> V_77 [ V_89 -> V_65 ] ;
struct V_90 * V_91 = F_27 ( V_76 , V_89 -> V_93 ) ;
unsigned long V_138 ;
if ( ! V_91 )
return;
F_55 ( V_20 -> V_28 . V_139 -> V_140 , V_138 ) ;
if ( V_91 -> V_180 || V_91 -> V_181 ) {
F_79 ( V_130 , V_76 -> V_159 ,
L_23 , ( V_182 ) V_89 -> V_93 ) ;
F_68 ( V_20 , 1 ) ;
}
if ( F_88 ( V_20 , V_89 -> V_65 , V_89 -> V_93 ) == 0 ) {
V_76 -> V_84 . V_183 = 0 ;
V_76 -> V_84 . V_85 = V_20 -> V_184 ;
V_76 -> V_84 . V_185 = 0 ;
V_76 -> V_186 . V_187 = 1 ;
V_76 -> V_159 = NULL ;
}
F_56 ( V_20 -> V_28 . V_139 -> V_140 , V_138 ) ;
}
static const char * F_89 ( struct V_123 * V_139 )
{
return V_188 ;
}
static void F_90 ( struct V_19 * V_20 , struct V_189 * V_190 )
{
struct V_75 * V_76 ;
int V_191 , V_192 ;
switch ( V_190 -> V_22 ) {
case 0 : return;
#ifdef F_91
case V_193 :
V_194 = V_190 -> V_79 ;
break;
#endif
case V_195 :
V_20 -> V_16 = V_190 -> V_79 ;
break;
default:
for ( V_191 = 0 ; V_191 < V_161 ; V_191 ++ ) {
if ( ! ( ( V_190 -> V_77 >> V_191 ) & 1 ) )
continue;
V_76 = & V_20 -> V_77 [ V_191 ] ;
if ( ! V_76 -> V_170 )
continue;
switch ( V_190 -> V_22 ) {
case V_196 :
if ( ! V_190 -> V_79 || V_190 -> V_79 >= 255 ) {
V_76 -> V_186 . V_197 = V_76 -> V_186 . V_198 =
V_76 -> V_186 . V_199 = 0 ;
V_76 -> V_186 . V_200 = 0 ;
} else if ( V_190 -> V_79 <= 9 && V_20 -> V_201 ) {
if ( V_190 -> V_79 < V_20 -> V_201 )
V_190 -> V_79 = V_20 -> V_201 ;
V_76 -> V_186 . V_197 = V_76 -> V_186 . V_198 =
V_76 -> V_186 . V_199 = 1 ;
V_76 -> V_186 . V_202 = 1 ;
V_76 -> V_186 . V_203 = V_190 -> V_79 ;
V_76 -> V_186 . V_200 = V_20 -> V_204 ;
} else {
if ( V_190 -> V_79 < V_20 -> V_205 )
V_190 -> V_79 = V_20 -> V_205 ;
V_76 -> V_186 . V_197 = V_76 -> V_186 . V_198 =
V_76 -> V_186 . V_199 = 0 ;
V_76 -> V_186 . V_203 = V_190 -> V_79 ;
V_76 -> V_186 . V_200 = V_20 -> V_206 ;
}
V_76 -> V_186 . V_187 = 1 ;
break;
case V_207 :
V_76 -> V_186 . V_202 = V_190 -> V_79 ? 1 : 0 ;
V_76 -> V_186 . V_187 = 1 ;
break;
case V_208 :
for ( V_192 = 0 ; V_192 < V_162 ; V_192 ++ )
F_75 ( V_76 , V_192 , V_190 -> V_79 ) ;
break;
case V_209 :
V_76 -> V_210 = 1 ;
V_20 -> V_211 = V_212 ;
F_92 ( V_20 , V_213 , V_214 | V_212 ) ;
break;
case V_215 :
for ( V_192 = 0 ; V_192 < V_162 ; V_192 ++ ) {
struct V_90 * V_91 = F_27 ( V_76 , V_192 ) ;
if ( V_91 ) V_91 -> V_216 = 1 ;
}
V_20 -> V_211 = V_212 ;
F_92 ( V_20 , V_213 , V_214 | V_212 ) ;
break;
case V_217 :
V_76 -> V_164 = V_190 -> V_79 ;
break;
}
}
break;
}
}
static int F_93 ( char * V_218 , int V_83 )
{
int V_219 , V_220 ;
for ( V_219 = V_83 ; V_219 > 0 && ( V_220 = * V_218 ++ ) && isspace ( V_220 ) ; V_219 -- ) ;
return ( V_83 - V_219 ) ;
}
static int F_94 ( char * V_218 , int V_83 , T_6 * V_221 )
{
char * V_222 ;
* V_221 = F_2 ( V_218 , & V_222 , 10 ) ;
return ( V_222 - V_218 ) ;
}
static int F_95 ( char * V_218 , int V_83 , char * V_223 )
{
int V_224 = strlen ( V_223 ) ;
if ( V_83 >= V_224 && ! memcmp ( V_223 , V_218 , V_224 ) )
return V_224 ;
else
return 0 ;
}
static int F_96 ( struct V_123 * V_124 , char * V_225 , int V_226 )
{
struct V_19 * V_20 = F_78 ( V_124 ) ;
char * V_218 = V_225 ;
int V_83 = V_226 ;
struct V_189 V_22 , * V_190 = & V_22 ;
int V_227 ;
T_6 V_77 ;
memset ( V_190 , 0 , sizeof( * V_190 ) ) ;
if ( V_83 > 0 && V_218 [ V_83 - 1 ] == '\n' )
-- V_83 ;
if ( ( V_227 = F_95 ( V_218 , V_83 , L_24 ) ) != 0 )
V_190 -> V_22 = V_196 ;
else if ( ( V_227 = F_95 ( V_218 , V_83 , L_25 ) ) != 0 )
V_190 -> V_22 = V_208 ;
else if ( ( V_227 = F_95 ( V_218 , V_83 , L_26 ) ) != 0 )
V_190 -> V_22 = V_195 ;
else if ( ( V_227 = F_95 ( V_218 , V_83 , L_27 ) ) != 0 )
V_190 -> V_22 = V_207 ;
#ifdef F_91
else if ( ( V_227 = F_95 ( V_218 , V_83 , L_28 ) ) != 0 )
V_190 -> V_22 = V_193 ;
#endif
else if ( ( V_227 = F_95 ( V_218 , V_83 , L_29 ) ) != 0 )
V_190 -> V_22 = V_217 ;
else if ( ( V_227 = F_95 ( V_218 , V_83 , L_30 ) ) != 0 )
V_190 -> V_22 = V_209 ;
else if ( ( V_227 = F_95 ( V_218 , V_83 , L_31 ) ) != 0 )
V_190 -> V_22 = V_215 ;
else
V_227 = 0 ;
#ifdef F_97
F_3 ( L_32 , V_227 , V_190 -> V_22 ) ;
#endif
if ( ! V_227 )
return - V_228 ;
V_218 += V_227 ; V_83 -= V_227 ;
switch( V_190 -> V_22 ) {
case V_196 :
case V_208 :
case V_207 :
case V_217 :
case V_209 :
case V_215 :
F_98 ( V_218 , V_83 ) ;
if ( ( V_227 = F_95 ( V_218 , V_83 , L_33 ) ) != 0 ) {
V_218 += V_227 ; V_83 -= V_227 ;
V_190 -> V_77 = ~ 0 ;
} else {
F_99 ( V_218 , V_83 , V_77 ) ;
V_190 -> V_77 = ( 1 << V_77 ) ;
#ifdef F_97
F_3 ( L_34 , V_77 ) ;
#endif
}
break;
}
switch( V_190 -> V_22 ) {
case V_195 :
case V_196 :
case V_208 :
case V_207 :
F_98 ( V_218 , V_83 ) ;
F_99 ( V_218 , V_83 , V_190 -> V_79 ) ;
#ifdef F_97
F_3 ( L_35 , V_190 -> V_79 ) ;
#endif
break;
#ifdef F_91
case V_193 :
while ( V_83 > 0 ) {
F_98 ( V_218 , V_83 ) ;
if ( ( V_227 = F_95 ( V_218 , V_83 , L_36 ) ) )
V_190 -> V_79 |= V_229 ;
else if ( ( V_227 = F_95 ( V_218 , V_83 , L_37 ) ) )
V_190 -> V_79 |= V_230 ;
else if ( ( V_227 = F_95 ( V_218 , V_83 , L_38 ) ) )
V_190 -> V_79 |= V_231 ;
else if ( ( V_227 = F_95 ( V_218 , V_83 , L_39 ) ) )
V_190 -> V_79 |= V_232 ;
else if ( ( V_227 = F_95 ( V_218 , V_83 , L_40 ) ) )
V_190 -> V_79 |= V_233 ;
else if ( ( V_227 = F_95 ( V_218 , V_83 , L_41 ) ) )
V_190 -> V_79 |= V_234 ;
else if ( ( V_227 = F_95 ( V_218 , V_83 , L_42 ) ) )
V_190 -> V_79 |= V_235 ;
else if ( ( V_227 = F_95 ( V_218 , V_83 , L_43 ) ) )
V_190 -> V_79 |= V_236 ;
else if ( ( V_227 = F_95 ( V_218 , V_83 , L_44 ) ) )
V_190 -> V_79 |= V_237 ;
else if ( ( V_227 = F_95 ( V_218 , V_83 , L_45 ) ) )
V_190 -> V_79 |= V_238 ;
else if ( ( V_227 = F_95 ( V_218 , V_83 , L_46 ) ) )
V_190 -> V_79 |= V_239 ;
else
return - V_228 ;
V_218 += V_227 ; V_83 -= V_227 ;
}
#ifdef F_97
F_3 ( L_35 , V_190 -> V_79 ) ;
#endif
break;
#endif
case V_217 :
while ( V_83 > 0 ) {
F_98 ( V_218 , V_83 ) ;
if ( ( V_227 = F_95 ( V_218 , V_83 , L_47 ) ) )
V_190 -> V_79 &= ~ V_240 ;
else
return - V_228 ;
V_218 += V_227 ; V_83 -= V_227 ;
}
break;
default:
break;
}
if ( V_83 )
return - V_228 ;
else {
unsigned long V_138 ;
F_55 ( V_124 -> V_140 , V_138 ) ;
F_90 ( V_20 , V_190 ) ;
F_56 ( V_124 -> V_140 , V_138 ) ;
}
return V_226 ;
}
static int F_100 ( struct V_241 * V_242 , struct V_123 * V_124 )
{
#ifdef F_101
struct V_125 * V_125 = F_46 ( V_124 ) ;
struct V_126 * V_127 = V_125 -> V_127 ;
struct V_19 * V_20 = V_125 -> V_143 ;
F_102 ( V_242 , L_48 V_243 L_49
L_50 , V_20 -> V_28 . V_244 ,
V_127 -> V_64 , V_127 -> V_245 ) ;
F_102 ( V_242 , L_51 ,
F_103 ( V_127 ) , V_127 -> V_246 ) ;
F_102 ( V_242 , L_52 ,
( int ) ( V_20 -> V_201 ? V_20 -> V_201 : V_20 -> V_205 ) ,
V_20 -> V_247 ? L_53 : L_54 ,
V_20 -> V_201 ? L_55 : L_56 ) ;
F_102 ( V_242 , L_57
L_58 ,
V_248 , V_178 ) ;
return 0 ;
#else
return - V_228 ;
#endif
}
static void F_104 ( struct V_249 * V_64 )
{
if ( V_64 -> V_28 . V_250 )
F_105 ( V_64 -> V_127 , V_64 -> V_28 . V_250 ) ;
if ( V_64 -> V_28 . V_251 )
F_105 ( V_64 -> V_127 , V_64 -> V_28 . V_251 ) ;
}
static void F_106 ( struct V_19 * V_20 , struct V_126 * V_127 ,
int V_252 )
{
if ( V_252 )
F_107 ( V_127 -> V_246 , V_20 -> V_28 . V_139 ) ;
if ( V_20 -> V_28 . V_250 )
F_105 ( V_127 , V_20 -> V_28 . V_250 ) ;
if ( V_20 -> V_28 . V_251 )
F_105 ( V_127 , V_20 -> V_28 . V_251 ) ;
F_108 ( V_20 ) ;
F_109 ( V_20 , sizeof( * V_20 ) , L_59 ) ;
}
static struct V_123 * F_110 ( struct V_253 * V_254 , int V_255 ,
struct V_249 * V_160 )
{
struct V_125 * V_125 ;
struct V_19 * V_20 = NULL ;
struct V_123 * V_124 = NULL ;
struct V_126 * V_127 = V_160 -> V_127 ;
unsigned long V_138 ;
struct V_256 * V_257 ;
int V_252 = 0 ;
F_3 ( V_109 L_60 ,
V_255 , V_160 -> V_258 . V_259 , V_127 -> V_245 , F_103 ( V_127 ) ,
V_127 -> V_246 ) ;
V_257 = F_111 ( & V_160 -> V_258 ) ;
if ( ! V_257 )
goto V_260;
V_124 = F_112 ( V_254 , sizeof( * V_125 ) ) ;
if ( ! V_124 )
goto V_260;
V_125 = F_46 ( V_124 ) ;
V_20 = F_113 ( & V_127 -> V_160 , sizeof( * V_20 ) , L_59 ) ;
if ( ! V_20 )
goto V_260;
V_20 -> V_261 = & V_127 -> V_160 ;
V_125 -> V_143 = V_20 ;
V_125 -> V_127 = V_127 ;
V_20 -> V_28 . V_139 = V_124 ;
F_114 ( V_127 , V_124 ) ;
V_20 -> V_262 = F_115 ( V_20 ) ;
V_20 -> V_16 = V_6 . V_16 ;
V_20 -> V_28 . V_255 = V_255 ;
V_20 -> V_263 = V_160 -> V_258 . V_263 ;
V_20 -> V_264 = V_160 -> V_258 . V_265 ;
V_20 -> V_206 = V_160 -> V_258 . V_266 ;
V_20 -> V_267 = V_160 -> V_258 . V_268 ;
V_20 -> V_269 = V_160 -> V_15 ;
V_20 -> V_270 = ( T_3 ) V_160 -> V_271 ;
V_20 -> V_272 = ( T_3 ) V_160 -> V_273 ;
V_20 -> V_28 . V_250 = V_160 -> V_28 . V_250 ;
V_20 -> V_28 . V_251 = V_160 -> V_28 . V_251 ;
F_116 ( V_20 -> V_28 . V_244 , V_160 -> V_258 . V_259 , sizeof( V_20 -> V_28 . V_244 ) ) ;
sprintf ( V_20 -> V_28 . V_274 , L_61 , V_20 -> V_28 . V_255 ) ;
if ( ( V_275 > 0 ) && ( V_20 -> V_263 & V_276 ) &&
! F_117 ( V_127 , V_277 ) ) {
F_118 ( V_20 ) ;
} else if ( F_117 ( V_127 , F_119 ( 32 ) ) ) {
F_120 ( L_62 , F_11 ( V_20 ) ) ;
goto V_260;
}
if ( F_121 ( V_124 , V_257 , V_160 -> V_278 ) )
goto V_260;
if ( F_122 ( V_127 -> V_246 , V_279 , V_280 , V_281 ,
V_124 ) ) {
F_123 ( L_63 ,
F_11 ( V_20 ) , V_127 -> V_246 ) ;
goto V_260;
}
V_252 = 1 ;
F_55 ( V_124 -> V_140 , V_138 ) ;
if ( F_68 ( V_20 , 0 ) )
goto V_282;
F_69 ( V_124 , 1 ) ;
F_124 ( & V_20 -> V_28 . V_119 ) ;
V_20 -> V_28 . V_119 . V_79 = ( unsigned long ) V_20 ;
V_20 -> V_28 . V_119 . V_283 = F_54 ;
V_20 -> V_28 . V_122 = 0 ;
F_40 ( V_20 ) ;
V_124 -> V_284 = 0 ;
V_124 -> V_285 = V_20 -> V_269 ;
V_124 -> V_286 = V_20 -> V_247 ? 16 : 8 ;
V_124 -> V_287 = V_162 ;
V_124 -> V_288 = F_125 ( V_127 , 0 ) ;
V_124 -> V_289 = V_178 ;
V_124 -> V_290 = ( V_248 - 2 ) ;
V_124 -> V_291 = V_80 ;
V_124 -> V_292 = 16 ;
F_62 ( V_293 == NULL ) ;
V_124 -> V_294 = V_293 ;
if ( V_127 -> V_64 == V_295 && V_127 -> V_245 < 2 )
V_124 -> V_296 = 0xFFFFFF ;
F_56 ( V_124 -> V_140 , V_138 ) ;
return V_124 ;
V_282:
F_123 ( L_64
L_65 , F_11 ( V_20 ) ) ;
F_56 ( V_124 -> V_140 , V_138 ) ;
V_260:
F_12 ( L_66 , V_255 ) ;
if ( V_20 )
F_106 ( V_20 , V_127 , V_252 ) ;
else
F_104 ( V_160 ) ;
if ( V_124 )
F_126 ( V_124 ) ;
return NULL ;
}
static void F_127 ( struct V_249 * V_297 , struct V_298 * V_299 )
{
V_297 -> V_278 = V_299 ;
V_299 -> type = 0 ;
F_128 ( V_297 , V_299 ) ;
}
static inline void F_127 ( struct V_249 * V_297 , struct V_298 * V_299 )
{
}
static int F_129 ( struct V_249 * V_64 )
{
struct V_300 * V_258 ;
struct V_126 * V_127 = V_64 -> V_127 ;
unsigned long V_301 = F_125 ( V_127 , 0 ) ;
int V_302 ;
if ( V_301 ) {
for ( V_302 = 0 ; V_302 < 8 ; V_302 ++ ) {
if ( V_6 . V_7 [ V_302 ] == V_301 )
return - V_303 ;
}
}
V_258 = F_130 ( V_127 -> V_64 , V_127 -> V_245 ) ;
if ( ! V_258 ) {
F_76 ( & V_127 -> V_160 , L_67 ) ;
return - V_303 ;
}
memcpy ( & V_64 -> V_258 , V_258 , sizeof( V_64 -> V_258 ) ) ;
return 0 ;
}
static int F_131 ( struct V_249 * V_64 )
{
unsigned int V_304 , V_305 ;
if ( ! V_64 -> V_28 . V_251 )
return 0 ;
if ( V_64 -> V_258 . V_263 & V_306 )
V_304 = 8192 ;
else
V_304 = 4096 ;
V_305 = F_132 ( V_64 -> V_28 . V_251 + V_304 - 16 ) ;
if ( V_305 != 0x52414944 )
return 0 ;
F_76 ( & V_64 -> V_127 -> V_160 ,
L_68 ) ;
return - V_303 ;
}
static int F_133 ( struct V_249 * V_64 )
{
struct V_300 * V_258 = & V_64 -> V_258 ;
struct V_126 * V_127 = V_64 -> V_127 ;
T_5 V_307 ;
if ( V_127 -> V_64 == V_295 && V_127 -> V_245 < 0x4 ) {
V_258 -> V_263 |= ( V_308 | V_309 ) ;
}
if ( V_258 -> V_263 & V_308 ) {
if ( F_134 ( V_127 ) )
return - V_303 ;
}
F_47 ( V_127 , V_129 , & V_307 ) ;
if ( V_258 -> V_263 & V_310 ) {
if ( ! ( V_307 & V_311 ) )
V_258 -> V_263 &= ~ V_310 ;
} else {
if ( V_307 & V_311 ) {
V_307 = V_311 ;
F_48 ( V_127 , V_129 , V_307 ) ;
F_47 ( V_127 , V_129 , & V_307 ) ;
}
}
return 0 ;
}
static int F_135 ( struct V_249 * V_64 )
{
struct V_126 * V_127 = V_64 -> V_127 ;
struct V_312 V_313 ;
int V_302 = 2 ;
F_136 ( V_127 -> V_314 , & V_313 , & V_127 -> V_315 [ 1 ] ) ;
V_64 -> V_271 = V_313 . V_316 ;
if ( V_64 -> V_258 . V_263 & V_317 ) {
if ( ! V_127 -> V_315 [ V_302 ] . V_138 )
V_302 ++ ;
F_136 ( V_127 -> V_314 , & V_313 ,
& V_127 -> V_315 [ V_302 ] ) ;
V_64 -> V_273 = V_313 . V_316 ;
}
#ifdef F_137
if ( V_64 -> V_271 )
V_64 -> V_28 . V_250 = F_138 ( V_127 , 1 ,
F_139 ( V_127 , 1 ) ) ;
#endif
if ( ! V_64 -> V_28 . V_250 )
V_64 -> V_28 . V_250 = F_138 ( V_127 , 0 ,
F_139 ( V_127 , 0 ) ) ;
if ( ! V_64 -> V_28 . V_250 ) {
F_140 ( & V_127 -> V_160 , L_69 ) ;
return - V_318 ;
}
if ( V_64 -> V_273 ) {
V_64 -> V_28 . V_251 = F_138 ( V_127 , V_302 ,
F_139 ( V_127 , V_302 ) ) ;
if ( ! V_64 -> V_28 . V_251 ) {
F_70 ( & V_127 -> V_160 ,
L_70 ) ;
V_64 -> V_273 = 0 ;
}
}
return 0 ;
}
static void F_141 ( struct V_126 * V_127 , struct V_249 * V_319 )
{
int V_320 ;
V_182 V_321 ;
for ( V_320 = 0 ; V_320 < 256 ; V_320 ++ ) {
struct V_126 * V_322 = F_142 ( V_127 -> V_314 , V_320 ) ;
if ( ! V_322 || V_322 -> V_323 != 0x101a || V_322 -> V_64 == 0x0009 ) {
F_143 ( V_322 ) ;
continue;
}
F_144 ( V_322 , 0x44 , & V_321 ) ;
if ( ( V_321 & 0x2 ) == 0 ) {
V_321 |= 0x2 ;
F_145 ( V_322 , 0x44 , V_321 ) ;
}
F_144 ( V_322 , 0x45 , & V_321 ) ;
if ( ( V_321 & 0x4 ) == 0 ) {
V_321 |= 0x4 ;
F_145 ( V_322 , 0x45 , V_321 ) ;
}
F_143 ( V_322 ) ;
break;
}
F_144 ( V_127 , 0x84 , & V_321 ) ;
V_319 -> V_15 = V_321 ;
}
static int F_146 ( struct V_123 * V_124 , struct V_126 * V_127 )
{
struct V_19 * V_20 = F_78 ( V_124 ) ;
F_3 ( L_71 , F_11 ( V_20 ) ) ;
F_147 ( & V_20 -> V_28 . V_119 ) ;
F_3 ( L_72 , F_11 ( V_20 ) ) ;
F_92 ( V_20 , V_213 , V_324 ) ;
F_148 ( V_20 , V_325 ) ;
F_149 ( 10 ) ;
F_92 ( V_20 , V_213 , 0 ) ;
F_106 ( V_20 , V_127 , 1 ) ;
F_126 ( V_124 ) ;
return 1 ;
}
static int F_150 ( struct V_126 * V_127 , const struct V_326 * V_327 )
{
struct V_249 V_319 ;
struct V_298 V_278 ;
struct V_123 * V_124 ;
int V_328 = 0 ;
int V_329 = 1 ;
memset ( & V_319 , 0 , sizeof( V_319 ) ) ;
memset ( & V_278 , 0 , sizeof( V_278 ) ) ;
V_319 . V_127 = V_127 ;
V_319 . V_15 = V_330 ;
if ( F_151 ( V_127 ) )
goto V_331;
F_152 ( V_127 ) ;
if ( F_153 ( V_127 , V_281 ) )
goto V_332;
if ( F_129 ( & V_319 ) )
goto free;
if ( F_135 ( & V_319 ) )
goto free;
V_328 = 1 ;
if ( F_131 ( & V_319 ) ) {
V_329 = 0 ;
goto free;
}
if ( F_133 ( & V_319 ) )
goto free;
F_141 ( V_127 , & V_319 ) ;
F_127 ( & V_319 , & V_278 ) ;
V_328 = 0 ;
V_124 = F_110 ( & V_333 , V_334 , & V_319 ) ;
if ( ! V_124 )
goto free;
if ( F_154 ( V_124 , & V_127 -> V_160 ) )
goto V_335;
F_155 ( V_124 ) ;
V_334 ++ ;
return 0 ;
V_335:
F_146 ( F_156 ( V_127 ) , V_127 ) ;
free:
if ( V_328 )
F_104 ( & V_319 ) ;
F_157 ( V_127 ) ;
V_332:
if ( V_329 )
F_158 ( V_127 ) ;
V_331:
return - V_303 ;
}
static void F_159 ( struct V_126 * V_127 )
{
struct V_123 * V_124 = F_156 ( V_127 ) ;
F_160 ( V_124 ) ;
F_146 ( V_124 , V_127 ) ;
F_157 ( V_127 ) ;
F_158 ( V_127 ) ;
V_334 -- ;
}
static T_7 F_161 ( struct V_126 * V_127 ,
enum V_336 V_337 )
{
if ( V_337 == V_338 ) {
F_159 ( V_127 ) ;
return V_339 ;
}
F_162 ( V_127 -> V_246 ) ;
F_158 ( V_127 ) ;
return V_340 ;
}
static T_7 F_163 ( struct V_126 * V_127 )
{
struct V_123 * V_124 = F_156 ( V_127 ) ;
F_164 ( V_124 ) ;
return V_341 ;
}
static void F_165 ( struct V_126 * V_127 )
{
T_5 V_307 ;
struct V_300 * V_258 ;
V_258 = F_130 ( V_127 -> V_64 , V_127 -> V_245 ) ;
F_47 ( V_127 , V_129 , & V_307 ) ;
if ( ! ( V_258 -> V_263 & V_310 ) && ( V_307 & V_311 ) ) {
V_307 = V_311 ;
F_48 ( V_127 , V_129 , V_307 ) ;
F_47 ( V_127 , V_129 , & V_307 ) ;
}
}
static T_7 F_166 ( struct V_126 * V_127 )
{
struct V_123 * V_124 = F_156 ( V_127 ) ;
struct V_19 * V_20 = F_78 ( V_124 ) ;
F_3 ( V_109 L_73 ,
F_11 ( V_20 ) ) ;
if ( F_151 ( V_127 ) ) {
F_3 ( V_342 L_74 ,
F_11 ( V_20 ) ) ;
return V_339 ;
}
F_152 ( V_127 ) ;
F_167 ( V_127 -> V_246 ) ;
if ( V_20 -> V_263 & V_308 ) {
if ( F_134 ( V_127 ) )
return V_339 ;
}
F_165 ( V_127 ) ;
if ( F_168 ( V_127 -> V_343 ) == 0 ) {
if ( F_68 ( V_20 , 0 ) ) {
F_3 ( V_342 L_75 ,
F_11 ( V_20 ) ) ;
return V_339 ;
}
F_69 ( V_124 , 1 ) ;
}
return V_344 ;
}
static void F_169 ( struct V_126 * V_127 )
{
struct V_123 * V_124 = F_156 ( V_127 ) ;
struct V_125 * V_125 = F_46 ( V_124 ) ;
F_61 ( V_124 -> V_140 ) ;
if ( V_125 -> V_148 )
F_170 ( V_125 -> V_148 ) ;
F_63 ( V_124 -> V_140 ) ;
}
static void F_171 ( struct V_123 * V_124 )
{
struct V_19 * V_20 = F_78 ( V_124 ) ;
enum V_345 type ;
switch ( V_20 -> V_346 ) {
case V_347 :
type = V_348 ;
break;
case V_349 :
type = V_350 ;
break;
case V_351 :
type = V_352 ;
break;
default:
type = V_353 ;
break;
}
F_172 ( V_124 ) = type ;
}
static void F_173 ( struct V_354 * V_159 , int V_200 )
{
struct V_123 * V_124 = F_174 ( V_159 -> V_160 . V_355 ) ;
struct V_19 * V_20 = F_78 ( V_124 ) ;
struct V_75 * V_76 = & V_20 -> V_77 [ V_159 -> V_65 ] ;
V_76 -> V_186 . V_200 = V_200 ;
V_76 -> V_186 . V_187 = 1 ;
}
static void F_175 ( struct V_354 * V_159 , int V_203 )
{
struct V_123 * V_124 = F_174 ( V_159 -> V_160 . V_355 ) ;
struct V_19 * V_20 = F_78 ( V_124 ) ;
struct V_75 * V_76 = & V_20 -> V_77 [ V_159 -> V_65 ] ;
if ( V_203 <= V_20 -> V_205 && F_176 ( V_159 ) )
V_76 -> V_186 . V_198 = 1 ;
V_76 -> V_186 . V_203 = V_203 ;
V_76 -> V_186 . V_187 = 1 ;
}
static void F_177 ( struct V_354 * V_159 , int V_202 )
{
struct V_123 * V_124 = F_174 ( V_159 -> V_160 . V_355 ) ;
struct V_19 * V_20 = F_78 ( V_124 ) ;
struct V_75 * V_76 = & V_20 -> V_77 [ V_159 -> V_65 ] ;
if ( V_202 == 0 )
V_76 -> V_186 . V_197 = V_76 -> V_186 . V_198 = V_76 -> V_186 . V_199 = 0 ;
V_76 -> V_186 . V_202 = V_202 ;
V_76 -> V_186 . V_187 = 1 ;
}
static void F_178 ( struct V_354 * V_159 , int V_198 )
{
struct V_123 * V_124 = F_174 ( V_159 -> V_160 . V_355 ) ;
struct V_19 * V_20 = F_78 ( V_124 ) ;
struct V_75 * V_76 = & V_20 -> V_77 [ V_159 -> V_65 ] ;
if ( V_198 )
V_76 -> V_186 . V_198 = 1 ;
else
V_76 -> V_186 . V_197 = V_76 -> V_186 . V_198 = V_76 -> V_186 . V_199 = 0 ;
V_76 -> V_186 . V_187 = 1 ;
}
static int T_8 F_179 ( void )
{
int error ;
F_1 () ;
V_293 = F_180 ( & V_356 ) ;
if ( ! V_293 )
return - V_303 ;
error = F_181 ( & V_357 ) ;
if ( error )
F_182 ( V_293 ) ;
return error ;
}
static void T_9 F_183 ( void )
{
F_184 ( & V_357 ) ;
F_182 ( V_293 ) ;
}
