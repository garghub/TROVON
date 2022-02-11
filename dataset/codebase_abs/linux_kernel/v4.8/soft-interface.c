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
V_61 = F_14 ( & V_9 -> V_78 . V_79 ) ;
if ( F_32 ( V_40 -> V_77 ) ) {
if ( V_61 == V_80 ) {
V_58 = true ;
goto V_81;
}
V_48 = F_34 ( V_2 , & V_54 ,
V_51 ) ;
V_40 = F_26 ( V_2 ) ;
if ( V_48 == V_49 ) {
V_58 = true ;
goto V_81;
}
if ( V_48 == V_82 )
V_50 = V_51 ;
else if ( ( V_61 == V_83 ) &&
( V_48 == V_84 ) )
goto V_68;
V_81:
if ( V_58 && ! F_35 ( V_40 -> V_77 ) ) {
V_63 = F_36 ( V_9 , V_2 ,
& V_65 ) ;
if ( V_63 == V_85 )
goto V_68;
if ( V_63 == V_86 )
V_58 = false ;
}
}
F_37 ( V_2 , 0 ) ;
if ( V_58 ) {
V_42 = F_38 ( V_9 ) ;
if ( ! V_42 )
goto V_68;
if ( F_39 ( V_9 , V_2 ) )
V_57 = F_40 ( V_87 ) ;
if ( F_1 ( V_2 , sizeof( * V_44 ) ) < 0 )
goto V_68;
V_44 = (struct V_43 * ) V_2 -> V_88 ;
V_44 -> V_89 = V_90 ;
V_44 -> V_91 = V_92 ;
V_44 -> V_93 = V_94 ;
V_44 -> V_95 = 0 ;
F_13 ( V_44 -> V_96 ,
V_42 -> V_97 -> V_30 ) ;
V_60 = F_41 ( & V_9 -> V_98 ) ;
V_44 -> V_60 = F_42 ( V_60 ) ;
F_43 ( V_9 , V_2 , V_57 ) ;
F_44 ( V_2 ) ;
} else {
if ( V_48 == V_84 ) {
V_56 = F_45 ( V_9 , V_2 ) ;
if ( V_56 )
goto V_68;
V_56 = F_46 ( V_9 , V_2 , V_33 ) ;
} else if ( V_65 ) {
V_56 = F_47 ( V_9 , V_2 ,
V_99 , 0 ,
V_65 , V_33 ) ;
} else {
if ( F_39 ( V_9 ,
V_2 ) )
goto V_68;
F_48 ( V_9 , V_2 ) ;
V_56 = F_49 ( V_9 , V_2 , V_50 ,
V_33 ) ;
}
if ( V_56 == V_100 )
goto V_101;
}
F_50 ( V_9 , V_12 ) ;
F_51 ( V_9 , V_14 , V_55 ) ;
goto V_102;
V_68:
F_44 ( V_2 ) ;
V_101:
F_50 ( V_9 , V_16 ) ;
V_102:
if ( V_42 )
F_52 ( V_42 ) ;
return V_103 ;
}
void F_53 ( struct V_5 * V_39 ,
struct V_1 * V_2 , int V_104 ,
struct V_64 * V_105 )
{
struct V_43 * V_43 ;
struct V_8 * V_9 = F_9 ( V_39 ) ;
struct V_52 * V_53 ;
struct V_40 * V_40 ;
unsigned short V_33 ;
bool V_106 ;
V_43 = (struct V_43 * ) V_2 -> V_88 ;
V_106 = ( V_43 -> V_93 == V_94 ) ;
F_54 ( V_2 , V_104 ) ;
F_55 ( V_2 ) ;
F_56 ( V_2 ) ;
if ( F_57 ( ! F_58 ( V_2 , V_67 ) ) )
goto V_68;
V_33 = F_25 ( V_2 , 0 ) ;
V_40 = F_26 ( V_2 ) ;
switch ( F_27 ( V_40 -> V_69 ) ) {
case V_70 :
if ( ! F_58 ( V_2 , V_107 ) )
goto V_68;
V_53 = (struct V_52 * ) V_2 -> V_88 ;
if ( V_53 -> V_71 != F_29 ( V_72 ) )
break;
case V_72 :
goto V_68;
}
V_2 -> V_108 = F_59 ( V_2 , V_39 ) ;
F_50 ( V_9 , V_18 ) ;
F_51 ( V_9 , V_20 ,
V_2 -> V_3 + V_67 ) ;
V_39 -> V_109 = V_110 ;
if ( F_60 ( V_9 , V_2 , V_33 , V_106 ) )
goto V_111;
if ( V_105 )
F_61 ( V_9 , V_105 ,
V_40 -> V_74 , V_33 ) ;
if ( F_32 ( V_40 -> V_77 ) ) {
if ( F_62 ( V_9 , V_33 ) &&
F_63 ( V_9 , V_40 -> V_74 ,
V_33 ) ) {
V_2 -> V_76 &= ~ V_9 -> V_112 ;
V_2 -> V_76 |= V_9 -> V_113 ;
}
} else if ( F_64 ( V_9 , V_40 -> V_74 ,
V_40 -> V_77 , V_33 ) ) {
goto V_68;
}
F_65 ( V_2 ) ;
goto V_111;
V_68:
F_44 ( V_2 ) ;
V_111:
return;
}
static void F_66 ( struct V_114 * V_115 )
{
struct V_22 * V_23 ;
V_23 = F_67 ( V_115 , struct V_22 , V_116 ) ;
F_68 ( & V_23 -> V_9 -> V_117 ) ;
F_69 ( & V_23 -> V_118 ) ;
F_70 ( & V_23 -> V_9 -> V_117 ) ;
F_71 ( V_23 , V_119 ) ;
}
void F_72 ( struct V_22 * V_23 )
{
if ( ! V_23 )
return;
F_73 ( & V_23 -> V_116 , F_66 ) ;
}
struct V_22 * F_74 ( struct V_8 * V_9 ,
unsigned short V_33 )
{
struct V_22 * V_120 , * V_23 = NULL ;
F_15 () ;
F_16 (vlan_tmp, &bat_priv->softif_vlan_list, list) {
if ( V_120 -> V_33 != V_33 )
continue;
if ( ! F_75 ( & V_120 -> V_116 ) )
continue;
V_23 = V_120 ;
break;
}
F_19 () ;
return V_23 ;
}
int F_76 ( struct V_8 * V_9 , unsigned short V_33 )
{
struct V_22 * V_23 ;
int V_121 ;
V_23 = F_74 ( V_9 , V_33 ) ;
if ( V_23 ) {
F_72 ( V_23 ) ;
return - V_122 ;
}
V_23 = F_77 ( sizeof( * V_23 ) , V_123 ) ;
if ( ! V_23 )
return - V_124 ;
V_23 -> V_9 = V_9 ;
V_23 -> V_33 = V_33 ;
F_78 ( & V_23 -> V_116 ) ;
F_79 ( & V_23 -> V_125 , 0 ) ;
V_121 = F_80 ( V_9 -> V_39 , V_23 ) ;
if ( V_121 ) {
F_81 ( V_23 ) ;
return V_121 ;
}
F_68 ( & V_9 -> V_117 ) ;
F_82 ( & V_23 -> V_118 , & V_9 -> V_126 ) ;
F_70 ( & V_9 -> V_117 ) ;
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
static int F_85 ( struct V_5 * V_6 , T_3 V_127 ,
unsigned short V_33 )
{
struct V_8 * V_9 = F_9 ( V_6 ) ;
struct V_22 * V_23 ;
int V_56 ;
if ( V_127 != F_29 ( V_70 ) )
return - V_37 ;
V_33 |= V_128 ;
V_23 = F_74 ( V_9 , V_33 ) ;
if ( ! V_23 )
return F_76 ( V_9 , V_33 ) ;
if ( ! V_23 -> V_129 ) {
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
static int F_86 ( struct V_5 * V_6 , T_3 V_127 ,
unsigned short V_33 )
{
struct V_8 * V_9 = F_9 ( V_6 ) ;
struct V_22 * V_23 ;
if ( V_127 != F_29 ( V_70 ) )
return - V_37 ;
V_23 = F_74 ( V_9 , V_33 | V_128 ) ;
if ( ! V_23 )
return - V_130 ;
F_83 ( V_9 , V_23 ) ;
F_72 ( V_23 ) ;
return 0 ;
}
static void F_87 ( struct V_5 * V_6 ,
struct V_131 * V_132 ,
void * V_133 )
{
F_88 ( & V_132 -> V_134 , & V_135 ) ;
}
static void F_89 ( struct V_5 * V_6 )
{
F_88 ( & V_6 -> V_136 , & V_137 ) ;
F_90 ( V_6 , F_87 , NULL ) ;
}
static void F_91 ( struct V_138 * V_139 )
{
struct V_22 * V_23 ;
struct V_8 * V_9 ;
struct V_5 * V_39 ;
V_9 = F_67 ( V_139 , struct V_8 ,
V_140 ) ;
V_39 = V_9 -> V_39 ;
V_23 = F_74 ( V_9 , V_141 ) ;
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
T_2 V_142 ;
int V_56 ;
T_4 V_143 = sizeof( V_144 ) * V_145 ;
F_89 ( V_6 ) ;
V_9 = F_9 ( V_6 ) ;
V_9 -> V_39 = V_6 ;
F_95 ( & V_9 -> V_140 , F_91 ) ;
V_9 -> V_146 = F_96 ( V_143 , F_97 ( V_144 ) ) ;
if ( ! V_9 -> V_146 )
return - V_124 ;
F_79 ( & V_9 -> V_147 , 1 ) ;
F_79 ( & V_9 -> V_148 , 0 ) ;
#ifdef F_98
F_79 ( & V_9 -> V_149 , 1 ) ;
#endif
#ifdef F_99
F_79 ( & V_9 -> V_150 , 1 ) ;
#endif
#ifdef F_100
V_9 -> V_151 . V_152 . V_153 = false ;
V_9 -> V_151 . V_152 . V_154 = false ;
V_9 -> V_151 . V_155 . V_153 = false ;
V_9 -> V_151 . V_155 . V_154 = false ;
V_9 -> V_151 . V_156 = V_141 ;
F_79 ( & V_9 -> V_157 , 1 ) ;
F_79 ( & V_9 -> V_151 . V_158 , 0 ) ;
F_79 ( & V_9 -> V_151 . V_159 , 0 ) ;
F_79 ( & V_9 -> V_151 . V_160 , 0 ) ;
F_79 ( & V_9 -> V_151 . V_161 , 0 ) ;
#endif
F_79 ( & V_9 -> V_78 . V_79 , V_80 ) ;
F_79 ( & V_9 -> V_78 . V_162 , 20 ) ;
F_79 ( & V_9 -> V_78 . V_163 , 100 ) ;
F_79 ( & V_9 -> V_78 . V_164 , 20 ) ;
F_79 ( & V_9 -> V_165 , 1000 ) ;
F_79 ( & V_9 -> V_166 , 30 ) ;
#ifdef F_101
F_79 ( & V_9 -> V_167 , 0 ) ;
#endif
F_79 ( & V_9 -> V_168 , 1 ) ;
F_79 ( & V_9 -> V_169 , V_170 ) ;
F_79 ( & V_9 -> V_171 , V_172 ) ;
F_79 ( & V_9 -> V_173 , V_174 ) ;
F_79 ( & V_9 -> V_31 , V_175 ) ;
F_79 ( & V_9 -> V_98 , 1 ) ;
F_79 ( & V_9 -> V_176 . V_177 , 0 ) ;
F_79 ( & V_9 -> V_176 . V_178 , 0 ) ;
F_79 ( & V_9 -> V_176 . V_179 , 0 ) ;
#ifdef F_98
F_79 ( & V_9 -> V_180 . V_181 , 0 ) ;
#endif
F_79 ( & V_9 -> V_182 , 0 ) ;
V_9 -> V_176 . V_183 = NULL ;
V_9 -> V_176 . V_184 = 0 ;
V_9 -> V_113 = 0 ;
V_9 -> V_112 = 0 ;
F_102 ( & V_142 , sizeof( V_142 ) ) ;
F_79 ( & V_9 -> V_185 , V_142 ) ;
V_9 -> V_42 = NULL ;
V_9 -> V_186 = 0 ;
F_103 ( V_9 ) ;
V_56 = F_104 ( V_9 , V_187 ) ;
if ( V_56 < 0 )
goto V_188;
V_56 = F_105 ( V_6 ) ;
if ( V_56 < 0 )
goto V_188;
V_56 = F_106 ( V_6 ) ;
if ( V_56 < 0 )
goto V_189;
return 0 ;
V_189:
F_107 ( V_6 ) ;
V_188:
F_108 ( V_9 -> V_146 ) ;
V_9 -> V_146 = NULL ;
return V_56 ;
}
static int F_109 ( struct V_5 * V_6 ,
struct V_5 * V_190 )
{
struct V_41 * V_191 ;
struct V_192 * V_192 = F_110 ( V_6 ) ;
int V_56 = - V_37 ;
V_191 = F_111 ( V_190 ) ;
if ( ! V_191 || V_191 -> V_39 )
goto V_111;
V_56 = F_112 ( V_191 , V_192 , V_6 -> V_193 ) ;
V_111:
if ( V_191 )
F_52 ( V_191 ) ;
return V_56 ;
}
static int F_113 ( struct V_5 * V_6 ,
struct V_5 * V_190 )
{
struct V_41 * V_191 ;
int V_56 = - V_37 ;
V_191 = F_111 ( V_190 ) ;
if ( ! V_191 || V_191 -> V_39 != V_6 )
goto V_111;
F_114 ( V_191 , V_194 ) ;
V_56 = 0 ;
V_111:
if ( V_191 )
F_52 ( V_191 ) ;
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
struct V_8 * V_195 = F_9 ( V_6 ) ;
F_120 ( V_6 ) ;
V_6 -> V_196 = & V_197 ;
V_6 -> V_198 = F_115 ;
V_6 -> V_199 |= V_200 | V_201 ;
V_6 -> V_202 |= V_203 ;
V_6 -> V_38 = V_170 ;
F_121 ( V_6 ) ;
V_6 -> V_204 = & V_205 ;
memset ( V_195 , 0 , sizeof( * V_195 ) ) ;
}
struct V_5 * F_122 ( struct V_192 * V_192 , const char * V_193 )
{
struct V_5 * V_39 ;
int V_56 ;
V_39 = F_123 ( sizeof( struct V_8 ) , V_193 ,
V_206 , F_119 ) ;
if ( ! V_39 )
return NULL ;
F_124 ( V_39 , V_192 ) ;
V_39 -> V_207 = & V_208 ;
V_56 = F_125 ( V_39 ) ;
if ( V_56 < 0 ) {
F_126 ( L_3 ,
V_193 , V_56 ) ;
F_118 ( V_39 ) ;
return NULL ;
}
return V_39 ;
}
void F_127 ( struct V_5 * V_39 )
{
struct V_8 * V_9 = F_9 ( V_39 ) ;
F_128 ( V_209 , & V_9 -> V_140 ) ;
}
static void F_129 ( struct V_5 * V_39 ,
struct V_210 * V_211 )
{
struct V_8 * V_9 = F_9 ( V_39 ) ;
struct V_41 * V_191 ;
struct V_22 * V_23 ;
F_130 (hard_iface, &batadv_hardif_list, list) {
if ( V_191 -> V_39 == V_39 )
F_114 ( V_191 ,
V_194 ) ;
}
V_23 = F_74 ( V_9 , V_141 ) ;
if ( V_23 ) {
F_83 ( V_9 , V_23 ) ;
F_72 ( V_23 ) ;
}
F_92 ( V_39 ) ;
F_131 ( V_39 , V_211 ) ;
}
bool F_132 ( const struct V_5 * V_97 )
{
if ( V_97 -> V_196 -> V_212 == F_23 )
return true ;
return false ;
}
static int F_133 ( struct V_5 * V_6 , struct V_213 * V_214 )
{
V_214 -> V_215 = 0 ;
V_214 -> V_216 = 0 ;
F_134 ( V_214 , V_217 ) ;
V_214 -> V_218 = V_219 ;
V_214 -> V_220 = V_221 ;
V_214 -> V_222 = 0 ;
V_214 -> V_223 = V_224 ;
V_214 -> V_225 = V_226 ;
V_214 -> V_227 = 0 ;
V_214 -> V_228 = 0 ;
return 0 ;
}
static void F_135 ( struct V_5 * V_6 ,
struct V_229 * V_230 )
{
F_136 ( V_230 -> V_231 , L_4 , sizeof( V_230 -> V_231 ) ) ;
F_136 ( V_230 -> V_89 , V_232 , sizeof( V_230 -> V_89 ) ) ;
F_136 ( V_230 -> V_233 , L_5 , sizeof( V_230 -> V_233 ) ) ;
F_136 ( V_230 -> V_234 , L_6 , sizeof( V_230 -> V_234 ) ) ;
}
static T_2 F_137 ( struct V_5 * V_6 )
{
return - V_235 ;
}
static void F_138 ( struct V_5 * V_6 , T_2 V_236 )
{
}
static T_2 F_139 ( struct V_5 * V_6 )
{
return 1 ;
}
static void F_140 ( struct V_5 * V_6 , T_2 V_237 , T_1 * V_88 )
{
if ( V_237 == V_238 )
memcpy ( V_88 , V_239 ,
sizeof( V_239 ) ) ;
}
static void F_141 ( struct V_5 * V_6 ,
struct V_240 * V_10 , V_144 * V_88 )
{
struct V_8 * V_9 = F_9 ( V_6 ) ;
int V_241 ;
for ( V_241 = 0 ; V_241 < V_145 ; V_241 ++ )
V_88 [ V_241 ] = F_10 ( V_9 , V_241 ) ;
}
static int F_142 ( struct V_5 * V_6 , int V_237 )
{
if ( V_237 == V_238 )
return V_145 ;
return - V_235 ;
}
