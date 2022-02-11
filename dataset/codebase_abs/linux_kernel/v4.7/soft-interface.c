int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
int V_4 ;
V_4 = F_2 ( V_2 , V_3 ) ;
if ( V_4 < 0 )
return V_4 ;
F_3 ( V_2 , V_3 ) ;
return 0 ;
}
static int F_4 ( struct V_5 * V_6 )
{
F_5 ( V_6 ) ;
return 0 ;
}
static int F_6 ( struct V_5 * V_6 )
{
F_7 ( V_6 ) ;
return 0 ;
}
static struct V_7 * F_8 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = F_9 ( V_6 ) ;
struct V_7 * V_10 = & V_9 -> V_10 ;
V_10 -> V_11 = F_10 ( V_9 , V_12 ) ;
V_10 -> V_13 = F_10 ( V_9 , V_14 ) ;
V_10 -> V_15 = F_10 ( V_9 , V_16 ) ;
V_10 -> V_17 = F_10 ( V_9 , V_18 ) ;
V_10 -> V_19 = F_10 ( V_9 , V_20 ) ;
return V_10 ;
}
static int F_11 ( struct V_5 * V_6 , void * V_21 )
{
struct V_8 * V_9 = F_9 ( V_6 ) ;
struct V_22 * V_23 ;
struct V_24 * V_25 = V_21 ;
T_1 V_26 [ V_27 ] ;
if ( ! F_12 ( V_25 -> V_28 ) )
return - V_29 ;
F_13 ( V_26 , V_6 -> V_30 ) ;
F_13 ( V_6 -> V_30 , V_25 -> V_28 ) ;
if ( F_14 ( & V_9 -> V_31 ) != V_32 )
return 0 ;
F_15 () ;
F_16 (vlan, &bat_priv->softif_vlan_list, list) {
F_17 ( V_9 , V_26 , V_23 -> V_33 ,
L_1 , false ) ;
F_18 ( V_6 , V_25 -> V_28 , V_23 -> V_33 ,
V_34 , V_35 ) ;
}
F_19 () ;
return 0 ;
}
static int F_20 ( struct V_5 * V_6 , int V_36 )
{
if ( ( V_36 < 68 ) || ( V_36 > F_21 ( V_6 ) ) )
return - V_37 ;
V_6 -> V_38 = V_36 ;
return 0 ;
}
static void F_22 ( struct V_5 * V_6 )
{
}
static int F_23 ( struct V_1 * V_2 ,
struct V_5 * V_39 )
{
struct V_40 * V_40 ;
struct V_8 * V_9 = F_9 ( V_39 ) ;
struct V_41 * V_42 = NULL ;
struct V_43 * V_44 ;
static const T_1 V_45 [ V_27 ] = { 0x01 , 0x80 , 0xC2 , 0x00 ,
0x00 , 0x00 } ;
static const T_1 V_46 [ V_27 ] = { 0xCF , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 } ;
enum V_47 V_48 = V_49 ;
T_1 * V_50 = NULL , V_51 [ V_27 ] ;
struct V_52 * V_53 ;
unsigned int V_54 = 0 ;
int V_55 = V_2 -> V_3 , V_56 ;
unsigned long V_57 = 1 ;
bool V_58 = false , V_59 ;
unsigned short V_33 ;
T_2 V_60 ;
int V_61 ;
enum V_62 V_63 ;
struct V_64 * V_65 = NULL ;
int V_66 = V_67 ;
if ( F_14 ( & V_9 -> V_31 ) != V_32 )
goto V_68;
F_24 ( V_39 ) ;
V_33 = F_25 ( V_2 , 0 ) ;
V_40 = F_26 ( V_2 ) ;
switch ( F_27 ( V_40 -> V_69 ) ) {
case V_70 :
V_53 = F_28 ( V_2 ) ;
if ( V_53 -> V_71 != F_29 ( V_72 ) ) {
V_66 += V_73 ;
break;
}
case V_72 :
goto V_68;
}
F_30 ( V_2 , V_66 ) ;
if ( F_31 ( V_9 , V_2 , V_33 ) )
goto V_68;
V_40 = F_26 ( V_2 ) ;
if ( ! F_32 ( V_40 -> V_74 ) ) {
V_59 = F_18 ( V_39 , V_40 -> V_74 ,
V_33 , V_2 -> V_75 ,
V_2 -> V_76 ) ;
if ( ! V_59 )
goto V_68;
}
if ( F_33 ( V_40 -> V_77 , V_45 ) )
goto V_68;
if ( F_33 ( V_40 -> V_77 , V_46 ) )
goto V_68;
V_61 = F_14 ( & V_9 -> V_61 ) ;
if ( F_32 ( V_40 -> V_77 ) ) {
if ( V_61 == V_78 ) {
V_58 = true ;
goto V_79;
}
V_48 = F_34 ( V_2 , & V_54 ,
V_51 ) ;
V_40 = F_26 ( V_2 ) ;
if ( V_48 == V_49 ) {
V_58 = true ;
goto V_79;
}
if ( V_48 == V_80 )
V_50 = V_51 ;
else if ( ( V_61 == V_81 ) &&
( V_48 == V_82 ) )
goto V_68;
V_79:
if ( V_58 && ! F_35 ( V_40 -> V_77 ) ) {
V_63 = F_36 ( V_9 , V_2 ,
& V_65 ) ;
if ( V_63 == V_83 )
goto V_68;
if ( V_63 == V_84 )
V_58 = false ;
}
}
F_37 ( V_2 , 0 ) ;
if ( V_58 ) {
V_42 = F_38 ( V_9 ) ;
if ( ! V_42 )
goto V_68;
if ( F_39 ( V_9 , V_2 ) )
V_57 = F_40 ( V_85 ) ;
if ( F_1 ( V_2 , sizeof( * V_44 ) ) < 0 )
goto V_68;
V_44 = (struct V_43 * ) V_2 -> V_86 ;
V_44 -> V_87 = V_88 ;
V_44 -> V_89 = V_90 ;
V_44 -> V_91 = V_92 ;
V_44 -> V_93 = 0 ;
F_13 ( V_44 -> V_94 ,
V_42 -> V_95 -> V_30 ) ;
V_60 = F_41 ( & V_9 -> V_96 ) ;
V_44 -> V_60 = F_42 ( V_60 ) ;
F_43 ( V_9 , V_2 , V_57 ) ;
F_44 ( V_2 ) ;
} else {
if ( V_48 == V_82 ) {
V_56 = F_45 ( V_9 , V_2 ) ;
if ( V_56 )
goto V_68;
V_56 = F_46 ( V_9 , V_2 , V_33 ) ;
} else if ( V_65 ) {
V_56 = F_47 ( V_9 , V_2 ,
V_97 , 0 ,
V_65 , V_33 ) ;
} else {
if ( F_39 ( V_9 ,
V_2 ) )
goto V_68;
F_48 ( V_9 , V_2 ) ;
V_56 = F_49 ( V_9 , V_2 , V_50 ,
V_33 ) ;
}
if ( V_56 == V_98 )
goto V_99;
}
F_50 ( V_9 , V_12 ) ;
F_51 ( V_9 , V_14 , V_55 ) ;
goto V_100;
V_68:
F_44 ( V_2 ) ;
V_99:
F_50 ( V_9 , V_16 ) ;
V_100:
if ( V_42 )
F_52 ( V_42 ) ;
return V_101 ;
}
void F_53 ( struct V_5 * V_39 ,
struct V_1 * V_2 , int V_102 ,
struct V_64 * V_103 )
{
struct V_43 * V_43 ;
struct V_8 * V_9 = F_9 ( V_39 ) ;
struct V_52 * V_53 ;
struct V_40 * V_40 ;
unsigned short V_33 ;
bool V_104 ;
V_43 = (struct V_43 * ) V_2 -> V_86 ;
V_104 = ( V_43 -> V_91 == V_92 ) ;
F_54 ( V_2 , V_102 ) ;
F_55 ( V_2 ) ;
F_56 ( V_2 ) ;
if ( F_57 ( ! F_58 ( V_2 , V_67 ) ) )
goto V_68;
V_33 = F_25 ( V_2 , 0 ) ;
V_40 = F_26 ( V_2 ) ;
switch ( F_27 ( V_40 -> V_69 ) ) {
case V_70 :
if ( ! F_58 ( V_2 , V_105 ) )
goto V_68;
V_53 = (struct V_52 * ) V_2 -> V_86 ;
if ( V_53 -> V_71 != F_29 ( V_72 ) )
break;
case V_72 :
goto V_68;
}
V_2 -> V_106 = F_59 ( V_2 , V_39 ) ;
F_50 ( V_9 , V_18 ) ;
F_51 ( V_9 , V_20 ,
V_2 -> V_3 + V_67 ) ;
V_39 -> V_107 = V_108 ;
if ( F_60 ( V_9 , V_2 , V_33 , V_104 ) )
goto V_109;
if ( V_103 )
F_61 ( V_9 , V_103 ,
V_40 -> V_74 , V_33 ) ;
if ( F_32 ( V_40 -> V_77 ) ) {
if ( F_62 ( V_9 , V_33 ) &&
F_63 ( V_9 , V_40 -> V_74 ,
V_33 ) ) {
V_2 -> V_76 &= ~ V_9 -> V_110 ;
V_2 -> V_76 |= V_9 -> V_111 ;
}
} else if ( F_64 ( V_9 , V_40 -> V_74 ,
V_40 -> V_77 , V_33 ) ) {
goto V_68;
}
F_65 ( V_2 ) ;
goto V_109;
V_68:
F_44 ( V_2 ) ;
V_109:
return;
}
static void F_66 ( struct V_112 * V_113 )
{
struct V_22 * V_23 ;
V_23 = F_67 ( V_113 , struct V_22 , V_114 ) ;
F_68 ( & V_23 -> V_9 -> V_115 ) ;
F_69 ( & V_23 -> V_116 ) ;
F_70 ( & V_23 -> V_9 -> V_115 ) ;
F_71 ( V_23 , V_117 ) ;
}
void F_72 ( struct V_22 * V_23 )
{
if ( ! V_23 )
return;
F_73 ( & V_23 -> V_114 , F_66 ) ;
}
struct V_22 * F_74 ( struct V_8 * V_9 ,
unsigned short V_33 )
{
struct V_22 * V_118 , * V_23 = NULL ;
F_15 () ;
F_16 (vlan_tmp, &bat_priv->softif_vlan_list, list) {
if ( V_118 -> V_33 != V_33 )
continue;
if ( ! F_75 ( & V_118 -> V_114 ) )
continue;
V_23 = V_118 ;
break;
}
F_19 () ;
return V_23 ;
}
int F_76 ( struct V_8 * V_9 , unsigned short V_33 )
{
struct V_22 * V_23 ;
int V_119 ;
V_23 = F_74 ( V_9 , V_33 ) ;
if ( V_23 ) {
F_72 ( V_23 ) ;
return - V_120 ;
}
V_23 = F_77 ( sizeof( * V_23 ) , V_121 ) ;
if ( ! V_23 )
return - V_122 ;
V_23 -> V_9 = V_9 ;
V_23 -> V_33 = V_33 ;
F_78 ( & V_23 -> V_114 ) ;
F_79 ( & V_23 -> V_123 , 0 ) ;
V_119 = F_80 ( V_9 -> V_39 , V_23 ) ;
if ( V_119 ) {
F_81 ( V_23 ) ;
return V_119 ;
}
F_68 ( & V_9 -> V_115 ) ;
F_82 ( & V_23 -> V_116 , & V_9 -> V_124 ) ;
F_70 ( & V_9 -> V_115 ) ;
F_18 ( V_9 -> V_39 ,
V_9 -> V_39 -> V_30 , V_33 ,
V_34 , V_35 ) ;
return 0 ;
}
static void F_83 ( struct V_8 * V_9 ,
struct V_22 * V_23 )
{
F_17 ( V_9 , V_9 -> V_39 -> V_30 ,
V_23 -> V_33 , L_2 , false ) ;
F_84 ( V_9 , V_23 ) ;
F_72 ( V_23 ) ;
}
static int F_85 ( struct V_5 * V_6 , T_3 V_125 ,
unsigned short V_33 )
{
struct V_8 * V_9 = F_9 ( V_6 ) ;
struct V_22 * V_23 ;
int V_56 ;
if ( V_125 != F_29 ( V_70 ) )
return - V_37 ;
V_33 |= V_126 ;
V_23 = F_74 ( V_9 , V_33 ) ;
if ( ! V_23 )
return F_76 ( V_9 , V_33 ) ;
if ( ! V_23 -> V_127 ) {
V_56 = F_80 ( V_9 -> V_39 , V_23 ) ;
if ( V_56 ) {
F_72 ( V_23 ) ;
return V_56 ;
}
}
F_18 ( V_9 -> V_39 ,
V_9 -> V_39 -> V_30 , V_33 ,
V_34 , V_35 ) ;
return 0 ;
}
static int F_86 ( struct V_5 * V_6 , T_3 V_125 ,
unsigned short V_33 )
{
struct V_8 * V_9 = F_9 ( V_6 ) ;
struct V_22 * V_23 ;
if ( V_125 != F_29 ( V_70 ) )
return - V_37 ;
V_23 = F_74 ( V_9 , V_33 | V_126 ) ;
if ( ! V_23 )
return - V_128 ;
F_83 ( V_9 , V_23 ) ;
F_72 ( V_23 ) ;
return 0 ;
}
static void F_87 ( struct V_5 * V_6 ,
struct V_129 * V_130 ,
void * V_131 )
{
F_88 ( & V_130 -> V_132 , & V_133 ) ;
}
static void F_89 ( struct V_5 * V_6 )
{
F_88 ( & V_6 -> V_134 , & V_135 ) ;
F_90 ( V_6 , F_87 , NULL ) ;
}
static void F_91 ( struct V_136 * V_137 )
{
struct V_22 * V_23 ;
struct V_8 * V_9 ;
struct V_5 * V_39 ;
V_9 = F_67 ( V_137 , struct V_8 ,
V_138 ) ;
V_39 = V_9 -> V_39 ;
V_23 = F_74 ( V_9 , V_139 ) ;
if ( V_23 ) {
F_83 ( V_9 , V_23 ) ;
F_72 ( V_23 ) ;
}
F_92 ( V_39 ) ;
F_93 ( V_39 ) ;
}
static int F_94 ( struct V_5 * V_6 )
{
struct V_8 * V_9 ;
T_2 V_140 ;
int V_56 ;
T_4 V_141 = sizeof( V_142 ) * V_143 ;
F_89 ( V_6 ) ;
V_9 = F_9 ( V_6 ) ;
V_9 -> V_39 = V_6 ;
F_95 ( & V_9 -> V_138 , F_91 ) ;
V_9 -> V_144 = F_96 ( V_141 , F_97 ( V_142 ) ) ;
if ( ! V_9 -> V_144 )
return - V_122 ;
F_79 ( & V_9 -> V_145 , 1 ) ;
F_79 ( & V_9 -> V_146 , 0 ) ;
#ifdef F_98
F_79 ( & V_9 -> V_147 , 1 ) ;
#endif
#ifdef F_99
F_79 ( & V_9 -> V_148 , 1 ) ;
#endif
#ifdef F_100
V_9 -> V_149 . V_150 = V_139 ;
F_79 ( & V_9 -> V_151 , 1 ) ;
F_79 ( & V_9 -> V_149 . V_152 , 0 ) ;
F_79 ( & V_9 -> V_149 . V_153 , 0 ) ;
F_79 ( & V_9 -> V_149 . V_154 , 0 ) ;
F_79 ( & V_9 -> V_149 . V_155 , 0 ) ;
#endif
F_79 ( & V_9 -> V_61 , V_78 ) ;
F_79 ( & V_9 -> V_156 , 20 ) ;
F_79 ( & V_9 -> V_157 . V_158 , 100 ) ;
F_79 ( & V_9 -> V_157 . V_159 , 20 ) ;
F_79 ( & V_9 -> V_160 , 1000 ) ;
F_79 ( & V_9 -> V_161 , 30 ) ;
#ifdef F_101
F_79 ( & V_9 -> V_162 , 0 ) ;
#endif
F_79 ( & V_9 -> V_163 , 1 ) ;
F_79 ( & V_9 -> V_164 , V_165 ) ;
F_79 ( & V_9 -> V_166 , V_167 ) ;
F_79 ( & V_9 -> V_168 , V_169 ) ;
F_79 ( & V_9 -> V_31 , V_170 ) ;
F_79 ( & V_9 -> V_96 , 1 ) ;
F_79 ( & V_9 -> V_171 . V_172 , 0 ) ;
F_79 ( & V_9 -> V_171 . V_173 , 0 ) ;
F_79 ( & V_9 -> V_171 . V_174 , 0 ) ;
#ifdef F_98
F_79 ( & V_9 -> V_175 . V_176 , 0 ) ;
#endif
V_9 -> V_171 . V_177 = NULL ;
V_9 -> V_171 . V_178 = 0 ;
V_9 -> V_111 = 0 ;
V_9 -> V_110 = 0 ;
F_102 ( & V_140 , sizeof( V_140 ) ) ;
F_79 ( & V_9 -> V_179 , V_140 ) ;
V_9 -> V_42 = NULL ;
V_9 -> V_180 = 0 ;
F_103 ( V_9 ) ;
V_56 = F_104 ( V_9 , V_181 ) ;
if ( V_56 < 0 )
goto V_182;
V_56 = F_105 ( V_6 ) ;
if ( V_56 < 0 )
goto V_182;
V_56 = F_106 ( V_6 ) ;
if ( V_56 < 0 )
goto V_183;
return 0 ;
V_183:
F_107 ( V_6 ) ;
V_182:
F_108 ( V_9 -> V_144 ) ;
V_9 -> V_144 = NULL ;
return V_56 ;
}
static int F_109 ( struct V_5 * V_6 ,
struct V_5 * V_184 )
{
struct V_41 * V_185 ;
struct V_186 * V_186 = F_110 ( V_6 ) ;
int V_56 = - V_37 ;
V_185 = F_111 ( V_184 ) ;
if ( ! V_185 || V_185 -> V_39 )
goto V_109;
V_56 = F_112 ( V_185 , V_186 , V_6 -> V_187 ) ;
V_109:
if ( V_185 )
F_52 ( V_185 ) ;
return V_56 ;
}
static int F_113 ( struct V_5 * V_6 ,
struct V_5 * V_184 )
{
struct V_41 * V_185 ;
int V_56 = - V_37 ;
V_185 = F_111 ( V_184 ) ;
if ( ! V_185 || V_185 -> V_39 != V_6 )
goto V_109;
F_114 ( V_185 , V_188 ) ;
V_56 = 0 ;
V_109:
if ( V_185 )
F_52 ( V_185 ) ;
return V_56 ;
}
static void F_115 ( struct V_5 * V_6 )
{
F_107 ( V_6 ) ;
F_116 ( V_6 ) ;
F_117 () ;
F_118 ( V_6 ) ;
}
static void F_119 ( struct V_5 * V_6 )
{
struct V_8 * V_189 = F_9 ( V_6 ) ;
F_120 ( V_6 ) ;
V_6 -> V_190 = & V_191 ;
V_6 -> V_192 = F_115 ;
V_6 -> V_193 |= V_194 | V_195 ;
V_6 -> V_196 |= V_197 ;
V_6 -> V_38 = V_165 ;
F_121 ( V_6 ) ;
V_6 -> V_198 = & V_199 ;
memset ( V_189 , 0 , sizeof( * V_189 ) ) ;
}
struct V_5 * F_122 ( struct V_186 * V_186 , const char * V_187 )
{
struct V_5 * V_39 ;
int V_56 ;
V_39 = F_123 ( sizeof( struct V_8 ) , V_187 ,
V_200 , F_119 ) ;
if ( ! V_39 )
return NULL ;
F_124 ( V_39 , V_186 ) ;
V_39 -> V_201 = & V_202 ;
V_56 = F_125 ( V_39 ) ;
if ( V_56 < 0 ) {
F_126 ( L_3 ,
V_187 , V_56 ) ;
F_118 ( V_39 ) ;
return NULL ;
}
return V_39 ;
}
void F_127 ( struct V_5 * V_39 )
{
struct V_8 * V_9 = F_9 ( V_39 ) ;
F_128 ( V_203 , & V_9 -> V_138 ) ;
}
static void F_129 ( struct V_5 * V_39 ,
struct V_204 * V_205 )
{
struct V_8 * V_9 = F_9 ( V_39 ) ;
struct V_41 * V_185 ;
struct V_22 * V_23 ;
F_130 (hard_iface, &batadv_hardif_list, list) {
if ( V_185 -> V_39 == V_39 )
F_114 ( V_185 ,
V_188 ) ;
}
V_23 = F_74 ( V_9 , V_139 ) ;
if ( V_23 ) {
F_83 ( V_9 , V_23 ) ;
F_72 ( V_23 ) ;
}
F_92 ( V_39 ) ;
F_131 ( V_39 , V_205 ) ;
}
bool F_132 ( const struct V_5 * V_95 )
{
if ( V_95 -> V_190 -> V_206 == F_23 )
return true ;
return false ;
}
static int F_133 ( struct V_5 * V_6 , struct V_207 * V_208 )
{
V_208 -> V_209 = 0 ;
V_208 -> V_210 = 0 ;
F_134 ( V_208 , V_211 ) ;
V_208 -> V_212 = V_213 ;
V_208 -> V_214 = V_215 ;
V_208 -> V_216 = 0 ;
V_208 -> V_217 = V_218 ;
V_208 -> V_219 = V_220 ;
V_208 -> V_221 = 0 ;
V_208 -> V_222 = 0 ;
return 0 ;
}
static void F_135 ( struct V_5 * V_6 ,
struct V_223 * V_224 )
{
F_136 ( V_224 -> V_225 , L_4 , sizeof( V_224 -> V_225 ) ) ;
F_136 ( V_224 -> V_87 , V_226 , sizeof( V_224 -> V_87 ) ) ;
F_136 ( V_224 -> V_227 , L_5 , sizeof( V_224 -> V_227 ) ) ;
F_136 ( V_224 -> V_228 , L_6 , sizeof( V_224 -> V_228 ) ) ;
}
static T_2 F_137 ( struct V_5 * V_6 )
{
return - V_229 ;
}
static void F_138 ( struct V_5 * V_6 , T_2 V_230 )
{
}
static T_2 F_139 ( struct V_5 * V_6 )
{
return 1 ;
}
static void F_140 ( struct V_5 * V_6 , T_2 V_231 , T_1 * V_86 )
{
if ( V_231 == V_232 )
memcpy ( V_86 , V_233 ,
sizeof( V_233 ) ) ;
}
static void F_141 ( struct V_5 * V_6 ,
struct V_234 * V_10 , V_142 * V_86 )
{
struct V_8 * V_9 = F_9 ( V_6 ) ;
int V_235 ;
for ( V_235 = 0 ; V_235 < V_143 ; V_235 ++ )
V_86 [ V_235 ] = F_10 ( V_9 , V_235 ) ;
}
static int F_142 ( struct V_5 * V_6 , int V_231 )
{
if ( V_231 == V_232 )
return V_143 ;
return - V_229 ;
}
