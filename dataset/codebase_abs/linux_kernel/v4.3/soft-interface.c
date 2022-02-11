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
T_2 V_45 = F_24 ( V_46 ) ;
static const T_1 V_47 [ V_27 ] = { 0x01 , 0x80 , 0xC2 , 0x00 ,
0x00 , 0x00 } ;
static const T_1 V_48 [ V_27 ] = { 0xCF , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 } ;
enum V_49 V_50 = V_51 ;
T_1 * V_52 = NULL , V_53 [ V_27 ] ;
struct V_54 * V_55 ;
unsigned int V_56 = 0 ;
int V_57 = V_2 -> V_3 , V_58 ;
unsigned long V_59 = 1 ;
bool V_60 = false , V_61 ;
unsigned short V_33 ;
T_3 V_62 ;
int V_63 ;
enum V_64 V_65 ;
struct V_66 * V_67 = NULL ;
int V_68 = V_69 ;
if ( F_14 ( & V_9 -> V_31 ) != V_32 )
goto V_70;
V_39 -> V_71 = V_72 ;
V_33 = F_25 ( V_2 , 0 ) ;
V_40 = F_26 ( V_2 ) ;
switch ( F_27 ( V_40 -> V_73 ) ) {
case V_74 :
V_55 = F_28 ( V_2 ) ;
if ( V_55 -> V_75 != V_45 ) {
V_68 += V_76 ;
break;
}
case V_46 :
goto V_70;
}
F_29 ( V_2 , V_68 ) ;
if ( F_30 ( V_9 , V_2 , V_33 ) )
goto V_70;
V_40 = F_26 ( V_2 ) ;
if ( ! F_31 ( V_40 -> V_77 ) ) {
V_61 = F_18 ( V_39 , V_40 -> V_77 ,
V_33 , V_2 -> V_78 ,
V_2 -> V_79 ) ;
if ( ! V_61 )
goto V_70;
}
if ( F_32 ( V_40 -> V_80 , V_47 ) )
goto V_70;
if ( F_32 ( V_40 -> V_80 , V_48 ) )
goto V_70;
V_63 = F_14 ( & V_9 -> V_63 ) ;
if ( F_31 ( V_40 -> V_80 ) ) {
if ( V_63 == V_81 ) {
V_60 = true ;
goto V_82;
}
V_50 = F_33 ( V_2 , & V_56 ,
V_53 ) ;
V_40 = F_26 ( V_2 ) ;
if ( V_50 == V_51 ) {
V_60 = true ;
goto V_82;
}
if ( V_50 == V_83 )
V_52 = V_53 ;
else if ( ( V_63 == V_84 ) &&
( V_50 == V_85 ) )
goto V_70;
V_82:
if ( V_60 && ! F_34 ( V_40 -> V_80 ) ) {
V_65 = F_35 ( V_9 , V_2 ,
& V_67 ) ;
if ( V_65 == V_86 )
goto V_70;
if ( V_65 == V_87 )
V_60 = false ;
}
}
F_36 ( V_2 , 0 ) ;
if ( V_60 ) {
V_42 = F_37 ( V_9 ) ;
if ( ! V_42 )
goto V_70;
if ( F_38 ( V_9 , V_2 ) )
V_59 = F_39 ( V_88 ) ;
if ( F_1 ( V_2 , sizeof( * V_44 ) ) < 0 )
goto V_70;
V_44 = (struct V_43 * ) V_2 -> V_89 ;
V_44 -> V_90 = V_91 ;
V_44 -> V_92 = V_93 ;
V_44 -> V_94 = V_95 ;
V_44 -> V_96 = 0 ;
F_13 ( V_44 -> V_97 ,
V_42 -> V_98 -> V_30 ) ;
V_62 = F_40 ( & V_9 -> V_99 ) ;
V_44 -> V_62 = F_41 ( V_62 ) ;
F_42 ( V_9 , V_2 , V_59 ) ;
F_43 ( V_2 ) ;
} else {
if ( V_50 == V_85 ) {
V_58 = F_44 ( V_9 , V_2 ) ;
if ( V_58 )
goto V_70;
V_58 = F_45 ( V_9 , V_2 , V_33 ) ;
} else if ( V_67 ) {
V_58 = F_46 ( V_9 , V_2 ,
V_100 , 0 ,
V_67 , V_33 ) ;
} else {
if ( F_38 ( V_9 ,
V_2 ) )
goto V_70;
F_47 ( V_9 , V_2 ) ;
V_58 = F_48 ( V_9 , V_2 , V_52 ,
V_33 ) ;
}
if ( V_58 == V_101 )
goto V_102;
}
F_49 ( V_9 , V_12 ) ;
F_50 ( V_9 , V_14 , V_57 ) ;
goto V_103;
V_70:
F_43 ( V_2 ) ;
V_102:
F_49 ( V_9 , V_16 ) ;
V_103:
if ( V_42 )
F_51 ( V_42 ) ;
return V_104 ;
}
void F_52 ( struct V_5 * V_39 ,
struct V_1 * V_2 , struct V_41 * V_105 ,
int V_106 , struct V_66 * V_107 )
{
struct V_43 * V_43 ;
struct V_8 * V_9 = F_9 ( V_39 ) ;
T_2 V_45 = F_24 ( V_46 ) ;
struct V_54 * V_55 ;
struct V_40 * V_40 ;
unsigned short V_33 ;
bool V_108 ;
V_43 = (struct V_43 * ) V_2 -> V_89 ;
V_108 = ( V_43 -> V_94 == V_95 ) ;
if ( ! F_53 ( V_2 , V_106 ) )
goto V_70;
F_54 ( V_2 , V_106 ) ;
F_55 ( V_2 ) ;
F_56 ( V_2 ) ;
V_33 = F_25 ( V_2 , 0 ) ;
V_40 = F_26 ( V_2 ) ;
switch ( F_27 ( V_40 -> V_73 ) ) {
case V_74 :
V_55 = (struct V_54 * ) V_2 -> V_89 ;
if ( V_55 -> V_75 != V_45 )
break;
case V_46 :
goto V_70;
}
if ( F_57 ( ! F_53 ( V_2 , V_69 ) ) )
goto V_70;
V_2 -> V_109 = F_58 ( V_2 , V_39 ) ;
F_49 ( V_9 , V_18 ) ;
F_50 ( V_9 , V_20 ,
V_2 -> V_3 + V_69 ) ;
V_39 -> V_110 = V_72 ;
if ( F_59 ( V_9 , V_2 , V_33 , V_108 ) )
goto V_111;
if ( V_107 )
F_60 ( V_9 , V_107 ,
V_40 -> V_77 , V_33 ) ;
if ( F_31 ( V_40 -> V_80 ) ) {
if ( F_61 ( V_9 , V_33 ) &&
F_62 ( V_9 , V_40 -> V_77 ,
V_33 ) ) {
V_2 -> V_79 &= ~ V_9 -> V_112 ;
V_2 -> V_79 |= V_9 -> V_113 ;
}
} else if ( F_63 ( V_9 , V_40 -> V_77 ,
V_40 -> V_80 , V_33 ) ) {
goto V_70;
}
F_64 ( V_2 ) ;
goto V_111;
V_70:
F_43 ( V_2 ) ;
V_111:
return;
}
void F_65 ( struct V_22 * V_23 )
{
if ( ! V_23 )
return;
if ( F_66 ( & V_23 -> V_114 ) ) {
F_67 ( & V_23 -> V_9 -> V_115 ) ;
F_68 ( & V_23 -> V_116 ) ;
F_69 ( & V_23 -> V_9 -> V_115 ) ;
F_70 ( V_23 , V_117 ) ;
}
}
struct V_22 * F_71 ( struct V_8 * V_9 ,
unsigned short V_33 )
{
struct V_22 * V_118 , * V_23 = NULL ;
F_15 () ;
F_16 (vlan_tmp, &bat_priv->softif_vlan_list, list) {
if ( V_118 -> V_33 != V_33 )
continue;
if ( ! F_72 ( & V_118 -> V_114 ) )
continue;
V_23 = V_118 ;
break;
}
F_19 () ;
return V_23 ;
}
int F_73 ( struct V_8 * V_9 , unsigned short V_33 )
{
struct V_22 * V_23 ;
int V_119 ;
V_23 = F_71 ( V_9 , V_33 ) ;
if ( V_23 ) {
F_65 ( V_23 ) ;
return - V_120 ;
}
V_23 = F_74 ( sizeof( * V_23 ) , V_121 ) ;
if ( ! V_23 )
return - V_122 ;
V_23 -> V_9 = V_9 ;
V_23 -> V_33 = V_33 ;
F_75 ( & V_23 -> V_114 , 1 ) ;
F_75 ( & V_23 -> V_123 , 0 ) ;
V_119 = F_76 ( V_9 -> V_39 , V_23 ) ;
if ( V_119 ) {
F_77 ( V_23 ) ;
return V_119 ;
}
F_67 ( & V_9 -> V_115 ) ;
F_78 ( & V_23 -> V_116 , & V_9 -> V_124 ) ;
F_69 ( & V_9 -> V_115 ) ;
F_18 ( V_9 -> V_39 ,
V_9 -> V_39 -> V_30 , V_33 ,
V_34 , V_35 ) ;
return 0 ;
}
static void F_79 ( struct V_8 * V_9 ,
struct V_22 * V_23 )
{
F_17 ( V_9 , V_9 -> V_39 -> V_30 ,
V_23 -> V_33 , L_2 , false ) ;
F_80 ( V_9 , V_23 ) ;
F_65 ( V_23 ) ;
}
static int F_81 ( struct V_5 * V_6 , T_2 V_125 ,
unsigned short V_33 )
{
struct V_8 * V_9 = F_9 ( V_6 ) ;
struct V_22 * V_23 ;
int V_58 ;
if ( V_125 != F_24 ( V_74 ) )
return - V_37 ;
V_33 |= V_126 ;
V_23 = F_71 ( V_9 , V_33 ) ;
if ( ! V_23 )
return F_73 ( V_9 , V_33 ) ;
if ( ! V_23 -> V_127 ) {
V_58 = F_76 ( V_9 -> V_39 , V_23 ) ;
if ( V_58 ) {
F_65 ( V_23 ) ;
return V_58 ;
}
}
F_18 ( V_9 -> V_39 ,
V_9 -> V_39 -> V_30 , V_33 ,
V_34 , V_35 ) ;
return 0 ;
}
static int F_82 ( struct V_5 * V_6 , T_2 V_125 ,
unsigned short V_33 )
{
struct V_8 * V_9 = F_9 ( V_6 ) ;
struct V_22 * V_23 ;
if ( V_125 != F_24 ( V_74 ) )
return - V_37 ;
V_23 = F_71 ( V_9 , V_33 | V_126 ) ;
if ( ! V_23 )
return - V_128 ;
F_79 ( V_9 , V_23 ) ;
F_65 ( V_23 ) ;
return 0 ;
}
static void F_83 ( struct V_5 * V_6 ,
struct V_129 * V_130 ,
void * V_131 )
{
F_84 ( & V_130 -> V_132 , & V_133 ) ;
}
static void F_85 ( struct V_5 * V_6 )
{
F_84 ( & V_6 -> V_134 , & V_135 ) ;
F_86 ( V_6 , F_83 , NULL ) ;
}
static void F_87 ( struct V_136 * V_137 )
{
struct V_22 * V_23 ;
struct V_8 * V_9 ;
struct V_5 * V_39 ;
V_9 = F_88 ( V_137 , struct V_8 ,
V_138 ) ;
V_39 = V_9 -> V_39 ;
V_23 = F_71 ( V_9 , V_139 ) ;
if ( V_23 ) {
F_79 ( V_9 , V_23 ) ;
F_65 ( V_23 ) ;
}
F_89 ( V_39 ) ;
F_90 ( V_39 ) ;
}
static int F_91 ( struct V_5 * V_6 )
{
struct V_8 * V_9 ;
T_3 V_140 ;
int V_58 ;
T_4 V_141 = sizeof( V_142 ) * V_143 ;
F_85 ( V_6 ) ;
V_9 = F_9 ( V_6 ) ;
V_9 -> V_39 = V_6 ;
F_92 ( & V_9 -> V_138 , F_87 ) ;
V_9 -> V_144 = F_93 ( V_141 , F_94 ( V_142 ) ) ;
if ( ! V_9 -> V_144 )
return - V_122 ;
F_75 ( & V_9 -> V_145 , 1 ) ;
F_75 ( & V_9 -> V_146 , 0 ) ;
#ifdef F_95
F_75 ( & V_9 -> V_147 , 1 ) ;
#endif
#ifdef F_96
F_75 ( & V_9 -> V_148 , 1 ) ;
#endif
#ifdef F_97
V_9 -> V_149 . V_150 = V_139 ;
F_75 ( & V_9 -> V_151 , 1 ) ;
F_75 ( & V_9 -> V_149 . V_152 , 0 ) ;
F_75 ( & V_9 -> V_149 . V_153 , 0 ) ;
F_75 ( & V_9 -> V_149 . V_154 , 0 ) ;
F_75 ( & V_9 -> V_149 . V_155 , 0 ) ;
#endif
F_75 ( & V_9 -> V_63 , V_81 ) ;
F_75 ( & V_9 -> V_156 , 20 ) ;
F_75 ( & V_9 -> V_157 . V_158 , 100 ) ;
F_75 ( & V_9 -> V_157 . V_159 , 20 ) ;
F_75 ( & V_9 -> V_160 , 1000 ) ;
F_75 ( & V_9 -> V_161 , 30 ) ;
#ifdef F_98
F_75 ( & V_9 -> V_162 , 0 ) ;
#endif
F_75 ( & V_9 -> V_163 , 1 ) ;
F_75 ( & V_9 -> V_164 , V_165 ) ;
F_75 ( & V_9 -> V_166 , V_167 ) ;
F_75 ( & V_9 -> V_168 , V_169 ) ;
F_75 ( & V_9 -> V_31 , V_170 ) ;
F_75 ( & V_9 -> V_99 , 1 ) ;
F_75 ( & V_9 -> V_171 . V_172 , 0 ) ;
F_75 ( & V_9 -> V_171 . V_173 , 0 ) ;
F_75 ( & V_9 -> V_171 . V_174 , 0 ) ;
#ifdef F_95
F_75 ( & V_9 -> V_175 . V_176 , 0 ) ;
#endif
V_9 -> V_171 . V_177 = NULL ;
V_9 -> V_171 . V_178 = 0 ;
V_9 -> V_113 = 0 ;
V_9 -> V_112 = 0 ;
F_99 ( & V_140 , sizeof( V_140 ) ) ;
F_75 ( & V_9 -> V_179 , V_140 ) ;
V_9 -> V_42 = NULL ;
V_9 -> V_180 = 0 ;
F_100 ( V_9 ) ;
V_58 = F_101 ( V_9 , V_181 ) ;
if ( V_58 < 0 )
goto V_182;
V_58 = F_102 ( V_6 ) ;
if ( V_58 < 0 )
goto V_182;
V_58 = F_103 ( V_6 ) ;
if ( V_58 < 0 )
goto V_183;
return 0 ;
V_183:
F_104 ( V_6 ) ;
V_182:
F_105 ( V_9 -> V_144 ) ;
V_9 -> V_144 = NULL ;
return V_58 ;
}
static int F_106 ( struct V_5 * V_6 ,
struct V_5 * V_184 )
{
struct V_41 * V_185 ;
int V_58 = - V_37 ;
V_185 = F_107 ( V_184 ) ;
if ( ! V_185 || V_185 -> V_39 )
goto V_111;
V_58 = F_108 ( V_185 , V_6 -> V_186 ) ;
V_111:
if ( V_185 )
F_51 ( V_185 ) ;
return V_58 ;
}
static int F_109 ( struct V_5 * V_6 ,
struct V_5 * V_184 )
{
struct V_41 * V_185 ;
int V_58 = - V_37 ;
V_185 = F_107 ( V_184 ) ;
if ( ! V_185 || V_185 -> V_39 != V_6 )
goto V_111;
F_110 ( V_185 , V_187 ) ;
V_58 = 0 ;
V_111:
if ( V_185 )
F_51 ( V_185 ) ;
return V_58 ;
}
static void F_111 ( struct V_5 * V_6 )
{
F_104 ( V_6 ) ;
F_112 ( V_6 ) ;
F_113 () ;
F_114 ( V_6 ) ;
}
static void F_115 ( struct V_5 * V_6 )
{
struct V_8 * V_188 = F_9 ( V_6 ) ;
F_116 ( V_6 ) ;
V_6 -> V_189 = & V_190 ;
V_6 -> V_191 = F_111 ;
V_6 -> V_192 |= V_193 ;
V_6 -> V_194 |= V_195 ;
V_6 -> V_38 = V_165 ;
F_117 ( V_6 ) ;
V_6 -> V_196 = & V_197 ;
memset ( V_188 , 0 , sizeof( * V_188 ) ) ;
}
struct V_5 * F_118 ( const char * V_186 )
{
struct V_5 * V_39 ;
int V_58 ;
V_39 = F_119 ( sizeof( struct V_8 ) , V_186 ,
V_198 , F_115 ) ;
if ( ! V_39 )
return NULL ;
V_39 -> V_199 = & V_200 ;
V_58 = F_120 ( V_39 ) ;
if ( V_58 < 0 ) {
F_121 ( L_3 ,
V_186 , V_58 ) ;
F_114 ( V_39 ) ;
return NULL ;
}
return V_39 ;
}
void F_122 ( struct V_5 * V_39 )
{
struct V_8 * V_9 = F_9 ( V_39 ) ;
F_123 ( V_201 , & V_9 -> V_138 ) ;
}
static void F_124 ( struct V_5 * V_39 ,
struct V_202 * V_203 )
{
struct V_41 * V_185 ;
F_125 (hard_iface, &batadv_hardif_list, list) {
if ( V_185 -> V_39 == V_39 )
F_110 ( V_185 ,
V_187 ) ;
}
F_89 ( V_39 ) ;
F_126 ( V_39 , V_203 ) ;
}
int F_127 ( const struct V_5 * V_98 )
{
if ( V_98 -> V_189 -> V_204 == F_23 )
return 1 ;
return 0 ;
}
static int F_128 ( struct V_5 * V_6 , struct V_205 * V_206 )
{
V_206 -> V_207 = 0 ;
V_206 -> V_208 = 0 ;
F_129 ( V_206 , V_209 ) ;
V_206 -> V_210 = V_211 ;
V_206 -> V_212 = V_213 ;
V_206 -> V_214 = 0 ;
V_206 -> V_215 = V_216 ;
V_206 -> V_217 = V_218 ;
V_206 -> V_219 = 0 ;
V_206 -> V_220 = 0 ;
return 0 ;
}
static void F_130 ( struct V_5 * V_6 ,
struct V_221 * V_222 )
{
F_131 ( V_222 -> V_223 , L_4 , sizeof( V_222 -> V_223 ) ) ;
F_131 ( V_222 -> V_90 , V_224 , sizeof( V_222 -> V_90 ) ) ;
F_131 ( V_222 -> V_225 , L_5 , sizeof( V_222 -> V_225 ) ) ;
F_131 ( V_222 -> V_226 , L_6 , sizeof( V_222 -> V_226 ) ) ;
}
static T_3 F_132 ( struct V_5 * V_6 )
{
return - V_227 ;
}
static void F_133 ( struct V_5 * V_6 , T_3 V_228 )
{
}
static T_3 F_134 ( struct V_5 * V_6 )
{
return 1 ;
}
static void F_135 ( struct V_5 * V_6 , T_3 V_229 , T_1 * V_89 )
{
if ( V_229 == V_230 )
memcpy ( V_89 , V_231 ,
sizeof( V_231 ) ) ;
}
static void F_136 ( struct V_5 * V_6 ,
struct V_232 * V_10 , V_142 * V_89 )
{
struct V_8 * V_9 = F_9 ( V_6 ) ;
int V_233 ;
for ( V_233 = 0 ; V_233 < V_143 ; V_233 ++ )
V_89 [ V_233 ] = F_10 ( V_9 , V_233 ) ;
}
static int F_137 ( struct V_5 * V_6 , int V_229 )
{
if ( V_229 == V_230 )
return V_143 ;
return - V_227 ;
}
