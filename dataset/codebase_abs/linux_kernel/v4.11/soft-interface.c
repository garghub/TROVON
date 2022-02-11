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
static T_1 F_8 ( struct V_7 * V_8 , T_2 V_9 )
{
T_1 * V_10 , V_11 = 0 ;
int V_12 ;
F_9 (cpu) {
V_10 = F_10 ( V_8 -> V_13 , V_12 ) ;
V_11 += V_10 [ V_9 ] ;
}
return V_11 ;
}
static struct V_14 * F_11 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_12 ( V_6 ) ;
struct V_14 * V_15 = & V_8 -> V_15 ;
V_15 -> V_16 = F_8 ( V_8 , V_17 ) ;
V_15 -> V_18 = F_8 ( V_8 , V_19 ) ;
V_15 -> V_20 = F_8 ( V_8 , V_21 ) ;
V_15 -> V_22 = F_8 ( V_8 , V_23 ) ;
V_15 -> V_24 = F_8 ( V_8 , V_25 ) ;
return V_15 ;
}
static int F_13 ( struct V_5 * V_6 , void * V_26 )
{
struct V_7 * V_8 = F_12 ( V_6 ) ;
struct V_27 * V_28 ;
struct V_29 * V_30 = V_26 ;
T_3 V_31 [ V_32 ] ;
if ( ! F_14 ( V_30 -> V_33 ) )
return - V_34 ;
F_15 ( V_31 , V_6 -> V_35 ) ;
F_15 ( V_6 -> V_35 , V_30 -> V_33 ) ;
if ( F_16 ( & V_8 -> V_36 ) != V_37 )
return 0 ;
F_17 () ;
F_18 (vlan, &bat_priv->softif_vlan_list, list) {
F_19 ( V_8 , V_31 , V_28 -> V_38 ,
L_1 , false ) ;
F_20 ( V_6 , V_30 -> V_33 , V_28 -> V_38 ,
V_39 , V_40 ) ;
}
F_21 () ;
return 0 ;
}
static int F_22 ( struct V_5 * V_6 , int V_41 )
{
if ( ( V_41 < 68 ) || ( V_41 > F_23 ( V_6 ) ) )
return - V_42 ;
V_6 -> V_43 = V_41 ;
return 0 ;
}
static void F_24 ( struct V_5 * V_6 )
{
}
static int F_25 ( struct V_1 * V_2 ,
struct V_5 * V_44 )
{
struct V_45 * V_45 ;
struct V_7 * V_8 = F_12 ( V_44 ) ;
struct V_46 * V_47 = NULL ;
struct V_48 * V_49 ;
static const T_3 V_50 [ V_32 ] = { 0x01 , 0x80 , 0xC2 , 0x00 ,
0x00 , 0x00 } ;
static const T_3 V_51 [ V_32 ] = { 0xCF , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 } ;
enum V_52 V_53 = V_54 ;
T_3 * V_55 = NULL , V_56 [ V_32 ] ;
struct V_57 * V_58 ;
unsigned int V_59 = 0 ;
int V_60 = V_2 -> V_3 , V_61 ;
unsigned long V_62 = 1 ;
bool V_63 = false , V_64 ;
unsigned short V_38 ;
T_4 V_65 ;
int V_66 ;
enum V_67 V_68 ;
struct V_69 * V_70 = NULL ;
int V_71 = V_72 ;
if ( F_16 ( & V_8 -> V_36 ) != V_37 )
goto V_73;
F_26 ( V_44 ) ;
V_38 = F_27 ( V_2 , 0 ) ;
V_45 = F_28 ( V_2 ) ;
switch ( F_29 ( V_45 -> V_74 ) ) {
case V_75 :
V_58 = F_30 ( V_2 ) ;
if ( V_58 -> V_76 != F_31 ( V_77 ) ) {
V_71 += V_78 ;
break;
}
case V_77 :
goto V_73;
}
F_32 ( V_2 , V_71 ) ;
if ( F_33 ( V_8 , V_2 , V_38 ) )
goto V_73;
V_45 = F_28 ( V_2 ) ;
if ( ! F_34 ( V_45 -> V_79 ) &&
! F_35 ( V_45 -> V_79 ) ) {
V_64 = F_20 ( V_44 , V_45 -> V_79 ,
V_38 , V_2 -> V_80 ,
V_2 -> V_81 ) ;
if ( ! V_64 )
goto V_73;
}
if ( F_36 ( V_45 -> V_82 , V_50 ) )
goto V_73;
if ( F_36 ( V_45 -> V_82 , V_51 ) )
goto V_73;
V_66 = F_16 ( & V_8 -> V_83 . V_84 ) ;
if ( F_34 ( V_45 -> V_82 ) ) {
if ( V_66 == V_85 ) {
V_63 = true ;
goto V_86;
}
V_53 = F_37 ( V_2 , & V_59 ,
V_56 ) ;
V_45 = F_28 ( V_2 ) ;
if ( V_53 == V_54 ) {
V_63 = true ;
goto V_86;
}
if ( V_53 == V_87 )
V_55 = V_56 ;
else if ( ( V_66 == V_88 ) &&
( V_53 == V_89 ) )
goto V_73;
V_86:
if ( V_63 && ! F_38 ( V_45 -> V_82 ) ) {
V_68 = F_39 ( V_8 , V_2 ,
& V_70 ) ;
if ( V_68 == V_90 )
goto V_73;
if ( V_68 == V_91 )
V_63 = false ;
}
}
F_40 ( V_2 , 0 ) ;
if ( V_63 ) {
V_47 = F_41 ( V_8 ) ;
if ( ! V_47 )
goto V_73;
if ( F_42 ( V_8 , V_2 ) )
V_62 = F_43 ( V_92 ) ;
if ( F_1 ( V_2 , sizeof( * V_49 ) ) < 0 )
goto V_73;
V_49 = (struct V_48 * ) V_2 -> V_93 ;
V_49 -> V_94 = V_95 ;
V_49 -> V_96 = V_97 ;
V_49 -> V_98 = V_99 ;
V_49 -> V_100 = 0 ;
F_15 ( V_49 -> V_101 ,
V_47 -> V_102 -> V_35 ) ;
V_65 = F_44 ( & V_8 -> V_103 ) ;
V_49 -> V_65 = F_45 ( V_65 ) ;
F_46 ( V_8 , V_2 , V_62 , true ) ;
F_47 ( V_2 ) ;
} else {
if ( V_53 == V_89 ) {
V_61 = F_48 ( V_8 , V_2 ) ;
if ( V_61 )
goto V_73;
V_61 = F_49 ( V_8 , V_2 , V_38 ) ;
} else if ( V_70 ) {
V_61 = F_50 ( V_8 , V_2 ,
V_104 , 0 ,
V_70 , V_38 ) ;
} else {
if ( F_42 ( V_8 ,
V_2 ) )
goto V_73;
F_51 ( V_8 , V_2 ) ;
V_61 = F_52 ( V_8 , V_2 , V_55 ,
V_38 ) ;
}
if ( V_61 != V_105 )
goto V_106;
}
F_53 ( V_8 , V_17 ) ;
F_54 ( V_8 , V_19 , V_60 ) ;
goto V_107;
V_73:
F_55 ( V_2 ) ;
V_106:
F_53 ( V_8 , V_21 ) ;
V_107:
if ( V_70 )
F_56 ( V_70 ) ;
if ( V_47 )
F_57 ( V_47 ) ;
return V_108 ;
}
void F_58 ( struct V_5 * V_44 ,
struct V_1 * V_2 , int V_109 ,
struct V_69 * V_110 )
{
struct V_48 * V_48 ;
struct V_7 * V_8 = F_12 ( V_44 ) ;
struct V_57 * V_58 ;
struct V_45 * V_45 ;
unsigned short V_38 ;
bool V_111 ;
V_48 = (struct V_48 * ) V_2 -> V_93 ;
V_111 = ( V_48 -> V_98 == V_99 ) ;
F_59 ( V_2 , V_109 ) ;
F_60 ( V_2 ) ;
F_61 ( V_2 ) ;
if ( F_62 ( ! F_63 ( V_2 , V_72 ) ) )
goto V_73;
V_38 = F_27 ( V_2 , 0 ) ;
V_45 = F_28 ( V_2 ) ;
switch ( F_29 ( V_45 -> V_74 ) ) {
case V_75 :
if ( ! F_63 ( V_2 , V_112 ) )
goto V_73;
V_58 = (struct V_57 * ) V_2 -> V_93 ;
if ( V_58 -> V_76 != F_31 ( V_77 ) )
break;
case V_77 :
goto V_73;
}
V_2 -> V_113 = F_64 ( V_2 , V_44 ) ;
F_53 ( V_8 , V_23 ) ;
F_54 ( V_8 , V_25 ,
V_2 -> V_3 + V_72 ) ;
if ( F_65 ( V_8 , V_2 , V_38 , V_111 ) )
goto V_114;
if ( V_110 )
F_66 ( V_8 , V_110 ,
V_45 -> V_79 , V_38 ) ;
if ( F_34 ( V_45 -> V_82 ) ) {
if ( F_67 ( V_8 , V_38 ) &&
F_68 ( V_8 , V_45 -> V_79 ,
V_38 ) ) {
V_2 -> V_81 &= ~ V_8 -> V_115 ;
V_2 -> V_81 |= V_8 -> V_116 ;
}
} else if ( F_69 ( V_8 , V_45 -> V_79 ,
V_45 -> V_82 , V_38 ) ) {
goto V_73;
}
F_70 ( V_2 ) ;
goto V_114;
V_73:
F_55 ( V_2 ) ;
V_114:
return;
}
static void F_71 ( struct V_117 * V_118 )
{
struct V_27 * V_28 ;
V_28 = F_72 ( V_118 , struct V_27 , V_119 ) ;
F_73 ( & V_28 -> V_8 -> V_120 ) ;
F_74 ( & V_28 -> V_121 ) ;
F_75 ( & V_28 -> V_8 -> V_120 ) ;
F_76 ( V_28 , V_122 ) ;
}
void F_77 ( struct V_27 * V_28 )
{
if ( ! V_28 )
return;
F_78 ( & V_28 -> V_119 , F_71 ) ;
}
struct V_27 * F_79 ( struct V_7 * V_8 ,
unsigned short V_38 )
{
struct V_27 * V_123 , * V_28 = NULL ;
F_17 () ;
F_18 (vlan_tmp, &bat_priv->softif_vlan_list, list) {
if ( V_123 -> V_38 != V_38 )
continue;
if ( ! F_80 ( & V_123 -> V_119 ) )
continue;
V_28 = V_123 ;
break;
}
F_21 () ;
return V_28 ;
}
int F_81 ( struct V_7 * V_8 , unsigned short V_38 )
{
struct V_27 * V_28 ;
int V_124 ;
V_28 = F_79 ( V_8 , V_38 ) ;
if ( V_28 ) {
F_77 ( V_28 ) ;
return - V_125 ;
}
V_28 = F_82 ( sizeof( * V_28 ) , V_126 ) ;
if ( ! V_28 )
return - V_127 ;
V_28 -> V_8 = V_8 ;
V_28 -> V_38 = V_38 ;
F_83 ( & V_28 -> V_119 ) ;
F_84 ( & V_28 -> V_128 , 0 ) ;
V_124 = F_85 ( V_8 -> V_44 , V_28 ) ;
if ( V_124 ) {
F_86 ( V_28 ) ;
return V_124 ;
}
F_73 ( & V_8 -> V_120 ) ;
F_87 ( & V_28 -> V_119 ) ;
F_88 ( & V_28 -> V_121 , & V_8 -> V_129 ) ;
F_75 ( & V_8 -> V_120 ) ;
F_20 ( V_8 -> V_44 ,
V_8 -> V_44 -> V_35 , V_38 ,
V_39 , V_40 ) ;
F_77 ( V_28 ) ;
return 0 ;
}
static void F_89 ( struct V_7 * V_8 ,
struct V_27 * V_28 )
{
F_19 ( V_8 , V_8 -> V_44 -> V_35 ,
V_28 -> V_38 , L_2 , false ) ;
F_90 ( V_8 , V_28 ) ;
F_77 ( V_28 ) ;
}
static int F_91 ( struct V_5 * V_6 , T_5 V_130 ,
unsigned short V_38 )
{
struct V_7 * V_8 = F_12 ( V_6 ) ;
struct V_27 * V_28 ;
int V_61 ;
if ( V_130 != F_31 ( V_75 ) )
return - V_42 ;
V_38 |= V_131 ;
V_28 = F_79 ( V_8 , V_38 ) ;
if ( ! V_28 )
return F_81 ( V_8 , V_38 ) ;
if ( ! V_28 -> V_132 ) {
V_61 = F_85 ( V_8 -> V_44 , V_28 ) ;
if ( V_61 ) {
F_77 ( V_28 ) ;
return V_61 ;
}
}
F_20 ( V_8 -> V_44 ,
V_8 -> V_44 -> V_35 , V_38 ,
V_39 , V_40 ) ;
return 0 ;
}
static int F_92 ( struct V_5 * V_6 , T_5 V_130 ,
unsigned short V_38 )
{
struct V_7 * V_8 = F_12 ( V_6 ) ;
struct V_27 * V_28 ;
if ( V_130 != F_31 ( V_75 ) )
return - V_42 ;
V_28 = F_79 ( V_8 , V_38 | V_131 ) ;
if ( ! V_28 )
return - V_133 ;
F_89 ( V_8 , V_28 ) ;
F_77 ( V_28 ) ;
return 0 ;
}
static void F_93 ( struct V_5 * V_6 ,
struct V_134 * V_135 ,
void * V_136 )
{
F_94 ( & V_135 -> V_137 , & V_138 ) ;
}
static void F_95 ( struct V_5 * V_6 )
{
F_94 ( & V_6 -> V_139 , & V_140 ) ;
F_96 ( V_6 , F_93 , NULL ) ;
}
static int F_97 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
T_4 V_141 ;
int V_61 ;
T_2 V_142 = sizeof( T_1 ) * V_143 ;
F_95 ( V_6 ) ;
V_8 = F_12 ( V_6 ) ;
V_8 -> V_44 = V_6 ;
V_8 -> V_13 = F_98 ( V_142 , F_99 ( T_1 ) ) ;
if ( ! V_8 -> V_13 )
return - V_127 ;
F_84 ( & V_8 -> V_144 , 1 ) ;
F_84 ( & V_8 -> V_145 , 0 ) ;
#ifdef F_100
F_84 ( & V_8 -> V_146 , 1 ) ;
#endif
#ifdef F_101
F_84 ( & V_8 -> V_147 , 1 ) ;
#endif
#ifdef F_102
V_8 -> V_148 . V_149 . V_150 = false ;
V_8 -> V_148 . V_149 . V_151 = false ;
V_8 -> V_148 . V_152 . V_150 = false ;
V_8 -> V_148 . V_152 . V_151 = false ;
V_8 -> V_148 . V_153 = V_154 ;
F_84 ( & V_8 -> V_155 , 1 ) ;
F_84 ( & V_8 -> V_148 . V_156 , 0 ) ;
F_84 ( & V_8 -> V_148 . V_157 , 0 ) ;
F_84 ( & V_8 -> V_148 . V_158 , 0 ) ;
F_84 ( & V_8 -> V_148 . V_159 , 0 ) ;
#endif
F_84 ( & V_8 -> V_83 . V_84 , V_85 ) ;
F_84 ( & V_8 -> V_83 . V_160 , 100 ) ;
F_84 ( & V_8 -> V_83 . V_161 , 20 ) ;
F_84 ( & V_8 -> V_162 , 1000 ) ;
F_84 ( & V_8 -> V_163 , 30 ) ;
#ifdef F_103
F_84 ( & V_8 -> V_164 , 0 ) ;
#endif
F_84 ( & V_8 -> V_165 , 1 ) ;
F_84 ( & V_8 -> V_166 , V_167 ) ;
F_84 ( & V_8 -> V_168 , V_169 ) ;
F_84 ( & V_8 -> V_170 , V_171 ) ;
F_84 ( & V_8 -> V_36 , V_172 ) ;
F_84 ( & V_8 -> V_103 , 1 ) ;
F_84 ( & V_8 -> V_173 . V_174 , 0 ) ;
F_84 ( & V_8 -> V_173 . V_175 , 0 ) ;
F_84 ( & V_8 -> V_173 . V_176 , 0 ) ;
#ifdef F_100
F_84 ( & V_8 -> V_177 . V_178 , 0 ) ;
#endif
F_84 ( & V_8 -> V_179 , 0 ) ;
V_8 -> V_173 . V_180 = NULL ;
V_8 -> V_173 . V_181 = 0 ;
V_8 -> V_116 = 0 ;
V_8 -> V_115 = 0 ;
F_104 ( & V_141 , sizeof( V_141 ) ) ;
F_84 ( & V_8 -> V_182 , V_141 ) ;
V_8 -> V_47 = NULL ;
V_8 -> V_183 = 0 ;
F_105 ( V_8 ) ;
V_61 = F_106 ( V_8 , V_184 ) ;
if ( V_61 < 0 )
goto V_185;
V_61 = F_107 ( V_6 ) ;
if ( V_61 < 0 )
goto V_185;
V_61 = F_108 ( V_6 ) ;
if ( V_61 < 0 )
goto V_186;
return 0 ;
V_186:
F_109 ( V_6 ) ;
V_185:
F_110 ( V_8 -> V_13 ) ;
V_8 -> V_13 = NULL ;
return V_61 ;
}
static int F_111 ( struct V_5 * V_6 ,
struct V_5 * V_187 )
{
struct V_46 * V_188 ;
struct V_189 * V_189 = F_112 ( V_6 ) ;
int V_61 = - V_42 ;
V_188 = F_113 ( V_187 ) ;
if ( ! V_188 || V_188 -> V_44 )
goto V_114;
V_61 = F_114 ( V_188 , V_189 , V_6 -> V_190 ) ;
V_114:
if ( V_188 )
F_57 ( V_188 ) ;
return V_61 ;
}
static int F_115 ( struct V_5 * V_6 ,
struct V_5 * V_187 )
{
struct V_46 * V_188 ;
int V_61 = - V_42 ;
V_188 = F_113 ( V_187 ) ;
if ( ! V_188 || V_188 -> V_44 != V_6 )
goto V_114;
F_116 ( V_188 , V_191 ) ;
V_61 = 0 ;
V_114:
if ( V_188 )
F_57 ( V_188 ) ;
return V_61 ;
}
static void F_117 ( struct V_5 * V_6 )
{
F_109 ( V_6 ) ;
F_118 ( V_6 ) ;
F_119 () ;
F_120 ( V_6 ) ;
}
static void F_121 ( struct V_5 * V_6 )
{
struct V_7 * V_192 = F_12 ( V_6 ) ;
F_122 ( V_6 ) ;
V_6 -> V_193 = & V_194 ;
V_6 -> V_195 = F_117 ;
V_6 -> V_196 |= V_197 | V_198 ;
V_6 -> V_199 |= V_200 ;
V_6 -> V_43 = V_167 ;
F_123 ( V_6 ) ;
V_6 -> V_201 = & V_202 ;
memset ( V_192 , 0 , sizeof( * V_192 ) ) ;
}
struct V_5 * F_124 ( struct V_189 * V_189 , const char * V_190 )
{
struct V_5 * V_44 ;
int V_61 ;
V_44 = F_125 ( sizeof( struct V_7 ) , V_190 ,
V_203 , F_121 ) ;
if ( ! V_44 )
return NULL ;
F_126 ( V_44 , V_189 ) ;
V_44 -> V_204 = & V_205 ;
V_61 = F_127 ( V_44 ) ;
if ( V_61 < 0 ) {
F_128 ( L_3 ,
V_190 , V_61 ) ;
F_120 ( V_44 ) ;
return NULL ;
}
return V_44 ;
}
void F_129 ( struct V_5 * V_44 )
{
struct V_7 * V_8 = F_12 ( V_44 ) ;
struct V_27 * V_28 ;
F_130 () ;
V_28 = F_79 ( V_8 , V_154 ) ;
if ( V_28 ) {
F_89 ( V_8 , V_28 ) ;
F_77 ( V_28 ) ;
}
F_131 ( V_44 ) ;
F_132 ( V_44 ) ;
}
static void F_133 ( struct V_5 * V_44 ,
struct V_206 * V_207 )
{
struct V_7 * V_8 = F_12 ( V_44 ) ;
struct V_46 * V_188 ;
struct V_27 * V_28 ;
F_134 (hard_iface, &batadv_hardif_list, list) {
if ( V_188 -> V_44 == V_44 )
F_116 ( V_188 ,
V_191 ) ;
}
V_28 = F_79 ( V_8 , V_154 ) ;
if ( V_28 ) {
F_89 ( V_8 , V_28 ) ;
F_77 ( V_28 ) ;
}
F_131 ( V_44 ) ;
F_135 ( V_44 , V_207 ) ;
}
bool F_136 ( const struct V_5 * V_102 )
{
if ( V_102 -> V_193 -> V_208 == F_25 )
return true ;
return false ;
}
static int F_137 ( struct V_5 * V_6 , struct V_209 * V_210 )
{
V_210 -> V_211 = 0 ;
V_210 -> V_212 = 0 ;
F_138 ( V_210 , V_213 ) ;
V_210 -> V_214 = V_215 ;
V_210 -> V_216 = V_217 ;
V_210 -> V_218 = 0 ;
V_210 -> V_219 = V_220 ;
V_210 -> V_221 = V_222 ;
V_210 -> V_223 = 0 ;
V_210 -> V_224 = 0 ;
return 0 ;
}
static void F_139 ( struct V_5 * V_6 ,
struct V_225 * V_226 )
{
F_140 ( V_226 -> V_227 , L_4 , sizeof( V_226 -> V_227 ) ) ;
F_140 ( V_226 -> V_94 , V_228 , sizeof( V_226 -> V_94 ) ) ;
F_140 ( V_226 -> V_229 , L_5 , sizeof( V_226 -> V_229 ) ) ;
F_140 ( V_226 -> V_230 , L_6 , sizeof( V_226 -> V_230 ) ) ;
}
static T_4 F_141 ( struct V_5 * V_6 )
{
return - V_231 ;
}
static void F_142 ( struct V_5 * V_6 , T_4 V_232 )
{
}
static T_4 F_143 ( struct V_5 * V_6 )
{
return 1 ;
}
static void F_144 ( struct V_5 * V_6 , T_4 V_233 , T_3 * V_93 )
{
if ( V_233 == V_234 )
memcpy ( V_93 , V_235 ,
sizeof( V_235 ) ) ;
}
static void F_145 ( struct V_5 * V_6 ,
struct V_236 * V_15 , T_1 * V_93 )
{
struct V_7 * V_8 = F_12 ( V_6 ) ;
int V_237 ;
for ( V_237 = 0 ; V_237 < V_143 ; V_237 ++ )
V_93 [ V_237 ] = F_8 ( V_8 , V_237 ) ;
}
static int F_146 ( struct V_5 * V_6 , int V_233 )
{
if ( V_233 == V_234 )
return V_143 ;
return - V_231 ;
}
