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
struct V_14 * V_15 = & V_6 -> V_15 ;
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
memset ( V_2 -> V_74 , 0 , sizeof( struct V_75 ) ) ;
F_26 ( V_44 ) ;
V_38 = F_27 ( V_2 , 0 ) ;
V_45 = F_28 ( V_2 ) ;
switch ( F_29 ( V_45 -> V_76 ) ) {
case V_77 :
V_58 = F_30 ( V_2 ) ;
if ( V_58 -> V_78 != F_31 ( V_79 ) ) {
V_71 += V_80 ;
break;
}
case V_79 :
goto V_73;
}
F_32 ( V_2 , V_71 ) ;
if ( F_33 ( V_8 , V_2 , V_38 ) )
goto V_73;
V_45 = F_28 ( V_2 ) ;
if ( ! F_34 ( V_45 -> V_81 ) &&
! F_35 ( V_45 -> V_81 ) ) {
V_64 = F_20 ( V_44 , V_45 -> V_81 ,
V_38 , V_2 -> V_82 ,
V_2 -> V_83 ) ;
if ( ! V_64 )
goto V_73;
}
if ( F_36 ( V_45 -> V_84 , V_50 ) )
goto V_73;
if ( F_36 ( V_45 -> V_84 , V_51 ) )
goto V_73;
V_66 = F_16 ( & V_8 -> V_85 . V_86 ) ;
if ( F_34 ( V_45 -> V_84 ) ) {
if ( V_66 == V_87 ) {
V_63 = true ;
goto V_88;
}
V_53 = F_37 ( V_2 , & V_59 ,
V_56 ) ;
V_45 = F_28 ( V_2 ) ;
if ( V_53 == V_54 ) {
V_63 = true ;
goto V_88;
}
if ( V_53 == V_89 )
V_55 = V_56 ;
else if ( ( V_66 == V_90 ) &&
( V_53 == V_91 ) )
goto V_73;
V_88:
if ( V_63 && ! F_38 ( V_45 -> V_84 ) ) {
V_68 = F_39 ( V_8 , V_2 ,
& V_70 ) ;
if ( V_68 == V_92 )
goto V_73;
if ( V_68 == V_93 )
V_63 = false ;
}
}
F_40 ( V_2 , 0 ) ;
if ( V_63 ) {
V_47 = F_41 ( V_8 ) ;
if ( ! V_47 )
goto V_73;
if ( F_42 ( V_8 , V_2 ) )
V_62 = F_43 ( V_94 ) ;
if ( F_1 ( V_2 , sizeof( * V_49 ) ) < 0 )
goto V_73;
V_49 = (struct V_48 * ) V_2 -> V_95 ;
V_49 -> V_96 = V_97 ;
V_49 -> V_98 = V_99 ;
V_49 -> V_100 = V_101 ;
V_49 -> V_102 = 0 ;
F_15 ( V_49 -> V_103 ,
V_47 -> V_104 -> V_35 ) ;
V_65 = F_44 ( & V_8 -> V_105 ) ;
V_49 -> V_65 = F_45 ( V_65 ) ;
F_46 ( V_8 , V_2 , V_62 , true ) ;
F_47 ( V_2 ) ;
} else {
if ( V_53 == V_91 ) {
V_61 = F_48 ( V_8 , V_2 ) ;
if ( V_61 )
goto V_73;
V_61 = F_49 ( V_8 , V_2 , V_38 ) ;
} else if ( V_70 ) {
V_61 = F_50 ( V_8 , V_2 ,
V_106 , 0 ,
V_70 , V_38 ) ;
} else {
if ( F_42 ( V_8 ,
V_2 ) )
goto V_73;
F_51 ( V_8 , V_2 ) ;
V_61 = F_52 ( V_8 , V_2 , V_55 ,
V_38 ) ;
}
if ( V_61 != V_107 )
goto V_108;
}
F_53 ( V_8 , V_17 ) ;
F_54 ( V_8 , V_19 , V_60 ) ;
goto V_109;
V_73:
F_55 ( V_2 ) ;
V_108:
F_53 ( V_8 , V_21 ) ;
V_109:
if ( V_70 )
F_56 ( V_70 ) ;
if ( V_47 )
F_57 ( V_47 ) ;
return V_110 ;
}
void F_58 ( struct V_5 * V_44 ,
struct V_1 * V_2 , int V_111 ,
struct V_69 * V_112 )
{
struct V_48 * V_48 ;
struct V_7 * V_8 = F_12 ( V_44 ) ;
struct V_57 * V_58 ;
struct V_45 * V_45 ;
unsigned short V_38 ;
bool V_113 ;
V_48 = (struct V_48 * ) V_2 -> V_95 ;
V_113 = ( V_48 -> V_100 == V_101 ) ;
F_59 ( V_2 , V_111 ) ;
F_60 ( V_2 ) ;
F_61 ( V_2 ) ;
if ( F_62 ( ! F_63 ( V_2 , V_72 ) ) )
goto V_73;
V_38 = F_27 ( V_2 , 0 ) ;
V_45 = F_28 ( V_2 ) ;
switch ( F_29 ( V_45 -> V_76 ) ) {
case V_77 :
if ( ! F_63 ( V_2 , V_114 ) )
goto V_73;
V_58 = (struct V_57 * ) V_2 -> V_95 ;
if ( V_58 -> V_78 != F_31 ( V_79 ) )
break;
case V_79 :
goto V_73;
}
V_2 -> V_115 = F_64 ( V_2 , V_44 ) ;
F_53 ( V_8 , V_23 ) ;
F_54 ( V_8 , V_25 ,
V_2 -> V_3 + V_72 ) ;
if ( F_65 ( V_8 , V_2 , V_38 , V_113 ) )
goto V_116;
if ( V_112 )
F_66 ( V_8 , V_112 ,
V_45 -> V_81 , V_38 ) ;
if ( F_34 ( V_45 -> V_84 ) ) {
if ( F_67 ( V_8 , V_38 ) &&
F_68 ( V_8 , V_45 -> V_81 ,
V_38 ) ) {
V_2 -> V_83 &= ~ V_8 -> V_117 ;
V_2 -> V_83 |= V_8 -> V_118 ;
}
} else if ( F_69 ( V_8 , V_45 -> V_81 ,
V_45 -> V_84 , V_38 ) ) {
goto V_73;
}
F_70 ( V_2 ) ;
goto V_116;
V_73:
F_55 ( V_2 ) ;
V_116:
return;
}
static void F_71 ( struct V_119 * V_120 )
{
struct V_27 * V_28 ;
V_28 = F_72 ( V_120 , struct V_27 , V_121 ) ;
F_73 ( & V_28 -> V_8 -> V_122 ) ;
F_74 ( & V_28 -> V_123 ) ;
F_75 ( & V_28 -> V_8 -> V_122 ) ;
F_76 ( V_28 , V_124 ) ;
}
void F_77 ( struct V_27 * V_28 )
{
if ( ! V_28 )
return;
F_78 ( & V_28 -> V_121 , F_71 ) ;
}
struct V_27 * F_79 ( struct V_7 * V_8 ,
unsigned short V_38 )
{
struct V_27 * V_125 , * V_28 = NULL ;
F_17 () ;
F_18 (vlan_tmp, &bat_priv->softif_vlan_list, list) {
if ( V_125 -> V_38 != V_38 )
continue;
if ( ! F_80 ( & V_125 -> V_121 ) )
continue;
V_28 = V_125 ;
break;
}
F_21 () ;
return V_28 ;
}
int F_81 ( struct V_7 * V_8 , unsigned short V_38 )
{
struct V_27 * V_28 ;
int V_126 ;
V_28 = F_79 ( V_8 , V_38 ) ;
if ( V_28 ) {
F_77 ( V_28 ) ;
return - V_127 ;
}
V_28 = F_82 ( sizeof( * V_28 ) , V_128 ) ;
if ( ! V_28 )
return - V_129 ;
V_28 -> V_8 = V_8 ;
V_28 -> V_38 = V_38 ;
F_83 ( & V_28 -> V_121 ) ;
F_84 ( & V_28 -> V_130 , 0 ) ;
V_126 = F_85 ( V_8 -> V_44 , V_28 ) ;
if ( V_126 ) {
F_86 ( V_28 ) ;
return V_126 ;
}
F_73 ( & V_8 -> V_122 ) ;
F_87 ( & V_28 -> V_121 ) ;
F_88 ( & V_28 -> V_123 , & V_8 -> V_131 ) ;
F_75 ( & V_8 -> V_122 ) ;
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
static int F_91 ( struct V_5 * V_6 , T_5 V_132 ,
unsigned short V_38 )
{
struct V_7 * V_8 = F_12 ( V_6 ) ;
struct V_27 * V_28 ;
int V_61 ;
if ( V_132 != F_31 ( V_77 ) )
return - V_42 ;
V_38 |= V_133 ;
V_28 = F_79 ( V_8 , V_38 ) ;
if ( ! V_28 )
return F_81 ( V_8 , V_38 ) ;
if ( ! V_28 -> V_134 ) {
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
static int F_92 ( struct V_5 * V_6 , T_5 V_132 ,
unsigned short V_38 )
{
struct V_7 * V_8 = F_12 ( V_6 ) ;
struct V_27 * V_28 ;
if ( V_132 != F_31 ( V_77 ) )
return - V_42 ;
V_28 = F_79 ( V_8 , V_38 | V_133 ) ;
if ( ! V_28 )
return - V_135 ;
F_89 ( V_8 , V_28 ) ;
F_77 ( V_28 ) ;
return 0 ;
}
static void F_93 ( struct V_5 * V_6 ,
struct V_136 * V_137 ,
void * V_138 )
{
F_94 ( & V_137 -> V_139 , & V_140 ) ;
}
static void F_95 ( struct V_5 * V_6 )
{
F_94 ( & V_6 -> V_141 , & V_142 ) ;
F_96 ( V_6 , F_93 , NULL ) ;
}
static int F_97 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
T_4 V_143 ;
int V_61 ;
T_2 V_144 = sizeof( T_1 ) * V_145 ;
F_95 ( V_6 ) ;
V_8 = F_12 ( V_6 ) ;
V_8 -> V_44 = V_6 ;
V_8 -> V_13 = F_98 ( V_144 , F_99 ( T_1 ) ) ;
if ( ! V_8 -> V_13 )
return - V_129 ;
F_84 ( & V_8 -> V_146 , 1 ) ;
F_84 ( & V_8 -> V_147 , 0 ) ;
#ifdef F_100
F_84 ( & V_8 -> V_148 , 1 ) ;
#endif
#ifdef F_101
F_84 ( & V_8 -> V_149 , 1 ) ;
#endif
#ifdef F_102
V_8 -> V_150 . V_151 . V_152 = false ;
V_8 -> V_150 . V_151 . V_153 = false ;
V_8 -> V_150 . V_154 . V_152 = false ;
V_8 -> V_150 . V_154 . V_153 = false ;
V_8 -> V_150 . V_155 = V_156 ;
F_84 ( & V_8 -> V_157 , 1 ) ;
F_84 ( & V_8 -> V_150 . V_158 , 0 ) ;
F_84 ( & V_8 -> V_150 . V_159 , 0 ) ;
F_84 ( & V_8 -> V_150 . V_160 , 0 ) ;
F_84 ( & V_8 -> V_150 . V_161 , 0 ) ;
#endif
F_84 ( & V_8 -> V_85 . V_86 , V_87 ) ;
F_84 ( & V_8 -> V_85 . V_162 , 100 ) ;
F_84 ( & V_8 -> V_85 . V_163 , 20 ) ;
F_84 ( & V_8 -> V_164 , 1000 ) ;
F_84 ( & V_8 -> V_165 , 30 ) ;
#ifdef F_103
F_84 ( & V_8 -> V_166 , 0 ) ;
#endif
F_84 ( & V_8 -> V_167 , 1 ) ;
F_84 ( & V_8 -> V_168 , V_169 ) ;
F_84 ( & V_8 -> V_170 , V_171 ) ;
F_84 ( & V_8 -> V_172 , V_173 ) ;
F_84 ( & V_8 -> V_36 , V_174 ) ;
F_84 ( & V_8 -> V_105 , 1 ) ;
F_84 ( & V_8 -> V_175 . V_176 , 0 ) ;
F_84 ( & V_8 -> V_175 . V_177 , 0 ) ;
F_84 ( & V_8 -> V_175 . V_178 , 0 ) ;
#ifdef F_100
F_84 ( & V_8 -> V_179 . V_180 , 0 ) ;
#endif
F_84 ( & V_8 -> V_181 , 0 ) ;
V_8 -> V_175 . V_182 = NULL ;
V_8 -> V_175 . V_183 = 0 ;
V_8 -> V_118 = 0 ;
V_8 -> V_117 = 0 ;
F_104 ( & V_143 , sizeof( V_143 ) ) ;
F_84 ( & V_8 -> V_184 , V_143 ) ;
V_8 -> V_47 = NULL ;
V_8 -> V_185 = 0 ;
F_105 ( V_8 ) ;
V_61 = F_106 ( V_8 , V_186 ) ;
if ( V_61 < 0 )
goto V_187;
V_61 = F_107 ( V_6 ) ;
if ( V_61 < 0 )
goto V_187;
V_61 = F_108 ( V_6 ) ;
if ( V_61 < 0 )
goto V_188;
return 0 ;
V_188:
F_109 ( V_6 ) ;
V_187:
F_110 ( V_8 -> V_13 ) ;
V_8 -> V_13 = NULL ;
return V_61 ;
}
static int F_111 ( struct V_5 * V_6 ,
struct V_5 * V_189 )
{
struct V_46 * V_190 ;
struct V_191 * V_191 = F_112 ( V_6 ) ;
int V_61 = - V_42 ;
V_190 = F_113 ( V_189 ) ;
if ( ! V_190 || V_190 -> V_44 )
goto V_116;
V_61 = F_114 ( V_190 , V_191 , V_6 -> V_192 ) ;
V_116:
if ( V_190 )
F_57 ( V_190 ) ;
return V_61 ;
}
static int F_115 ( struct V_5 * V_6 ,
struct V_5 * V_189 )
{
struct V_46 * V_190 ;
int V_61 = - V_42 ;
V_190 = F_113 ( V_189 ) ;
if ( ! V_190 || V_190 -> V_44 != V_6 )
goto V_116;
F_116 ( V_190 , V_193 ) ;
V_61 = 0 ;
V_116:
if ( V_190 )
F_57 ( V_190 ) ;
return V_61 ;
}
static void F_117 ( struct V_5 * V_6 ,
struct V_194 * V_195 )
{
F_118 ( V_195 -> V_196 , L_3 , sizeof( V_195 -> V_196 ) ) ;
F_118 ( V_195 -> V_96 , V_197 , sizeof( V_195 -> V_96 ) ) ;
F_118 ( V_195 -> V_198 , L_4 , sizeof( V_195 -> V_198 ) ) ;
F_118 ( V_195 -> V_199 , L_5 , sizeof( V_195 -> V_199 ) ) ;
}
static void F_119 ( struct V_5 * V_6 , T_4 V_200 , T_3 * V_95 )
{
if ( V_200 == V_201 )
memcpy ( V_95 , V_202 ,
sizeof( V_202 ) ) ;
}
static void F_120 ( struct V_5 * V_6 ,
struct V_203 * V_15 , T_1 * V_95 )
{
struct V_7 * V_8 = F_12 ( V_6 ) ;
int V_204 ;
for ( V_204 = 0 ; V_204 < V_145 ; V_204 ++ )
V_95 [ V_204 ] = F_8 ( V_8 , V_204 ) ;
}
static int F_121 ( struct V_5 * V_6 , int V_200 )
{
if ( V_200 == V_201 )
return V_145 ;
return - V_205 ;
}
static void F_122 ( struct V_5 * V_6 )
{
F_109 ( V_6 ) ;
F_123 ( V_6 ) ;
F_124 () ;
}
static void F_125 ( struct V_5 * V_6 )
{
F_126 ( V_6 ) ;
V_6 -> V_206 = & V_207 ;
V_6 -> V_208 = true ;
V_6 -> V_209 = F_122 ;
V_6 -> V_210 |= V_211 | V_212 ;
V_6 -> V_213 |= V_214 ;
V_6 -> V_43 = V_169 ;
F_127 ( V_6 ) ;
V_6 -> V_215 = & V_216 ;
}
struct V_5 * F_128 ( struct V_191 * V_191 , const char * V_192 )
{
struct V_5 * V_44 ;
int V_61 ;
V_44 = F_129 ( sizeof( struct V_7 ) , V_192 ,
V_217 , F_125 ) ;
if ( ! V_44 )
return NULL ;
F_130 ( V_44 , V_191 ) ;
V_44 -> V_218 = & V_219 ;
V_61 = F_131 ( V_44 ) ;
if ( V_61 < 0 ) {
F_132 ( L_6 ,
V_192 , V_61 ) ;
F_133 ( V_44 ) ;
return NULL ;
}
return V_44 ;
}
void F_134 ( struct V_5 * V_44 )
{
struct V_7 * V_8 = F_12 ( V_44 ) ;
struct V_27 * V_28 ;
F_135 () ;
V_28 = F_79 ( V_8 , V_156 ) ;
if ( V_28 ) {
F_89 ( V_8 , V_28 ) ;
F_77 ( V_28 ) ;
}
F_136 ( V_44 ) ;
F_137 ( V_44 ) ;
}
static void F_138 ( struct V_5 * V_44 ,
struct V_220 * V_221 )
{
struct V_7 * V_8 = F_12 ( V_44 ) ;
struct V_46 * V_190 ;
struct V_27 * V_28 ;
F_139 (hard_iface, &batadv_hardif_list, list) {
if ( V_190 -> V_44 == V_44 )
F_116 ( V_190 ,
V_193 ) ;
}
V_28 = F_79 ( V_8 , V_156 ) ;
if ( V_28 ) {
F_89 ( V_8 , V_28 ) ;
F_77 ( V_28 ) ;
}
F_136 ( V_44 ) ;
F_140 ( V_44 , V_221 ) ;
}
bool F_141 ( const struct V_5 * V_104 )
{
if ( V_104 -> V_206 -> V_222 == F_25 )
return true ;
return false ;
}
