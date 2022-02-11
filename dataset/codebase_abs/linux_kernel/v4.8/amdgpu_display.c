static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 =
F_2 ( V_4 , struct V_5 , V_4 ) ;
F_3 ( V_2 ) ;
F_4 ( & V_6 -> V_7 ) ;
}
static bool F_5 ( struct V_5 * V_6 ,
struct V_1 * * V_2 )
{
struct V_1 * V_1 = * V_2 ;
if ( V_1 == NULL )
return false ;
* V_2 = NULL ;
if ( ! F_6 ( V_1 , & V_6 -> V_4 , F_1 ) )
return true ;
F_3 ( V_1 ) ;
return false ;
}
static void F_7 ( struct V_8 * V_9 )
{
struct V_5 * V_6 =
F_2 ( V_9 , struct V_5 , V_7 ) ;
struct V_10 * V_11 = V_6 -> V_11 ;
struct V_12 * V_13 = V_11 -> V_14 . V_15 [ V_6 -> V_16 ] ;
struct V_17 * V_18 = & V_13 -> V_19 ;
unsigned long V_20 ;
unsigned V_21 , V_22 = 4 ;
int V_23 , V_24 , V_25 , V_26 = 0 ;
struct V_27 * V_28 = & V_18 -> V_29 -> V_28 [ V_6 -> V_16 ] ;
if ( F_5 ( V_6 , & V_6 -> V_30 ) )
return;
for ( V_21 = 0 ; V_21 < V_6 -> V_31 ; ++ V_21 )
if ( F_5 ( V_6 , & V_6 -> V_32 [ V_21 ] ) )
return;
F_8 ( & V_18 -> V_29 -> V_33 , V_20 ) ;
while ( V_13 -> V_34 && -- V_22 ) {
V_25 = F_9 ( V_11 -> V_35 , V_6 -> V_16 ,
V_36 ,
& V_23 , & V_24 , NULL , NULL ,
& V_18 -> V_37 ) ;
if ( ( V_25 & ( V_38 | V_39 ) ) !=
( V_38 | V_39 ) ||
! ( V_23 >= 0 && V_24 <= 0 ) )
break;
V_26 = ( - V_24 + 1 ) * F_10 ( V_28 -> V_40 / 1000 , 5 ) ;
if ( V_26 > V_28 -> V_41 / 2000 ) {
V_22 = 0 ;
break;
}
F_11 ( & V_18 -> V_29 -> V_33 , V_20 ) ;
F_12 ( V_26 , 2 * V_26 ) ;
F_8 ( & V_18 -> V_29 -> V_33 , V_20 ) ;
}
if ( ! V_22 )
F_13 ( L_1
L_2
L_3 , V_6 -> V_16 , V_26 ,
V_28 -> V_41 / 1000 ,
V_28 -> V_40 / 1000 , V_25 , V_23 , V_24 ) ;
V_11 -> V_14 . V_42 -> V_43 ( V_11 , V_6 -> V_16 , V_6 -> V_19 , V_6 -> V_44 ) ;
V_13 -> V_45 = V_46 ;
F_11 ( & V_18 -> V_29 -> V_33 , V_20 ) ;
F_13 ( L_4 ,
V_13 -> V_16 , V_13 , V_6 ) ;
}
static void F_14 ( struct V_8 * V_9 )
{
struct V_5 * V_6 =
F_2 ( V_9 , struct V_5 , V_47 ) ;
int V_48 ;
V_48 = F_15 ( V_6 -> V_49 , false ) ;
if ( F_16 ( V_48 == 0 ) ) {
V_48 = F_17 ( V_6 -> V_49 ) ;
if ( F_18 ( V_48 != 0 ) ) {
F_19 ( L_5 ) ;
}
F_20 ( V_6 -> V_49 ) ;
} else
F_19 ( L_6 ) ;
F_21 ( & V_6 -> V_49 ) ;
F_22 ( V_6 -> V_32 ) ;
F_22 ( V_6 ) ;
}
int F_23 ( struct V_17 * V_18 ,
struct V_50 * V_51 ,
struct V_52 * V_53 ,
T_1 V_54 )
{
struct V_55 * V_29 = V_18 -> V_29 ;
struct V_10 * V_11 = V_29 -> V_56 ;
struct V_12 * V_12 = F_24 ( V_18 ) ;
struct V_57 * V_58 ;
struct V_57 * V_59 ;
struct V_60 * V_61 ;
struct V_5 * V_6 ;
struct V_62 * V_63 ;
unsigned long V_20 ;
T_2 V_64 ;
T_2 V_19 ;
int V_21 , V_48 ;
V_6 = F_25 ( sizeof *V_6 , V_65 ) ;
if ( V_6 == NULL )
return - V_66 ;
F_26 ( & V_6 -> V_7 , F_7 ) ;
F_26 ( & V_6 -> V_47 , F_14 ) ;
V_6 -> V_53 = V_53 ;
V_6 -> V_11 = V_11 ;
V_6 -> V_16 = V_12 -> V_16 ;
V_6 -> V_44 = ( V_54 & V_67 ) != 0 ;
V_58 = F_27 ( V_18 -> V_68 -> V_51 ) ;
V_61 = V_58 -> V_61 ;
V_6 -> V_49 = F_28 ( V_61 ) ;
F_29 ( V_6 -> V_49 ) ;
V_59 = F_27 ( V_51 ) ;
V_61 = V_59 -> V_61 ;
V_63 = F_28 ( V_61 ) ;
V_48 = F_15 ( V_63 , false ) ;
if ( F_18 ( V_48 != 0 ) ) {
F_19 ( L_7 ) ;
goto V_69;
}
V_48 = F_30 ( V_63 , V_70 , 0 , 0 , & V_19 ) ;
if ( F_18 ( V_48 != 0 ) ) {
V_48 = - V_71 ;
F_19 ( L_8 ) ;
goto V_72;
}
V_48 = F_31 ( V_63 -> V_73 . V_74 , & V_6 -> V_30 ,
& V_6 -> V_31 ,
& V_6 -> V_32 ) ;
if ( F_18 ( V_48 != 0 ) ) {
F_19 ( L_9 ) ;
goto V_75;
}
F_32 ( V_63 , & V_64 ) ;
F_20 ( V_63 ) ;
V_6 -> V_19 = V_19 ;
V_48 = F_33 ( V_18 ) ;
if ( V_48 ) {
F_19 ( L_10 ) ;
goto V_76;
}
F_8 ( & V_18 -> V_29 -> V_33 , V_20 ) ;
if ( V_12 -> V_45 != V_77 ) {
F_13 ( L_11 ) ;
F_11 ( & V_18 -> V_29 -> V_33 , V_20 ) ;
V_48 = - V_78 ;
goto V_79;
}
V_12 -> V_45 = V_80 ;
V_12 -> V_81 = V_6 ;
F_13 ( L_12 ,
V_12 -> V_16 , V_12 , V_6 ) ;
V_18 -> V_68 -> V_51 = V_51 ;
F_11 ( & V_18 -> V_29 -> V_33 , V_20 ) ;
F_7 ( & V_6 -> V_7 ) ;
return 0 ;
V_79:
F_34 ( V_18 ) ;
V_76:
if ( F_18 ( F_15 ( V_63 , false ) != 0 ) ) {
F_19 ( L_13 ) ;
goto V_69;
}
V_75:
if ( F_18 ( F_17 ( V_63 ) != 0 ) ) {
F_19 ( L_14 ) ;
}
V_72:
F_20 ( V_63 ) ;
V_69:
F_21 ( & V_6 -> V_49 ) ;
F_3 ( V_6 -> V_30 ) ;
for ( V_21 = 0 ; V_21 < V_6 -> V_31 ; ++ V_21 )
F_3 ( V_6 -> V_32 [ V_21 ] ) ;
F_22 ( V_6 -> V_32 ) ;
F_22 ( V_6 ) ;
return V_48 ;
}
int F_35 ( struct V_82 * V_83 )
{
struct V_55 * V_29 ;
struct V_10 * V_11 ;
struct V_17 * V_18 ;
bool V_84 = false ;
int V_85 ;
if ( ! V_83 || ! V_83 -> V_18 )
return - V_71 ;
V_29 = V_83 -> V_18 -> V_29 ;
V_85 = F_36 ( V_29 -> V_29 ) ;
if ( V_85 < 0 )
return V_85 ;
V_85 = F_37 ( V_83 ) ;
F_38 (crtc, &dev->mode_config.crtc_list, head)
if ( V_18 -> V_34 )
V_84 = true ;
F_39 ( V_29 -> V_29 ) ;
V_11 = V_29 -> V_56 ;
if ( V_84 && ! V_11 -> V_86 ) {
V_11 -> V_86 = true ;
return V_85 ;
}
if ( ! V_84 && V_11 -> V_86 ) {
F_40 ( V_29 -> V_29 ) ;
V_11 -> V_86 = false ;
}
F_40 ( V_29 -> V_29 ) ;
return V_85 ;
}
void F_41 ( struct V_55 * V_29 )
{
struct V_87 * V_88 ;
struct V_89 * V_89 ;
struct V_90 * V_91 ;
struct V_92 * V_92 ;
T_1 V_93 ;
int V_21 = 0 ;
F_42 ( L_15 ) ;
F_38 (connector, &dev->mode_config.connector_list, head) {
V_89 = F_43 ( V_88 ) ;
F_42 ( L_16 , V_21 ) ;
F_42 ( L_17 , V_88 -> V_94 ) ;
if ( V_89 -> V_95 . V_95 != V_96 )
F_42 ( L_17 , V_97 [ V_89 -> V_95 . V_95 ] ) ;
if ( V_89 -> V_98 ) {
F_42 ( L_18 ,
V_89 -> V_98 -> V_99 . V_100 ,
V_89 -> V_98 -> V_99 . V_101 ,
V_89 -> V_98 -> V_99 . V_102 ,
V_89 -> V_98 -> V_99 . V_103 ,
V_89 -> V_98 -> V_99 . V_104 ,
V_89 -> V_98 -> V_99 . V_105 ,
V_89 -> V_98 -> V_99 . V_106 ,
V_89 -> V_98 -> V_99 . V_107 ) ;
if ( V_89 -> V_108 . V_109 )
F_42 ( L_19 ,
V_89 -> V_108 . V_110 ,
V_89 -> V_108 . V_111 ) ;
if ( V_89 -> V_108 . V_112 )
F_42 ( L_20 ,
V_89 -> V_108 . V_113 ,
V_89 -> V_108 . V_114 ) ;
} else {
if ( V_88 -> V_115 == V_116 ||
V_88 -> V_115 == V_117 ||
V_88 -> V_115 == V_118 ||
V_88 -> V_115 == V_119 ||
V_88 -> V_115 == V_120 ||
V_88 -> V_115 == V_121 )
F_42 ( L_21 ) ;
}
F_42 ( L_22 ) ;
F_38 (encoder, &dev->mode_config.encoder_list, head) {
V_92 = F_44 ( V_91 ) ;
V_93 = V_92 -> V_93 & V_89 -> V_93 ;
if ( V_93 ) {
if ( V_93 & V_122 )
F_42 ( L_23 , V_123 [ V_92 -> V_124 ] ) ;
if ( V_93 & V_125 )
F_42 ( L_24 , V_123 [ V_92 -> V_124 ] ) ;
if ( V_93 & V_126 )
F_42 ( L_25 , V_123 [ V_92 -> V_124 ] ) ;
if ( V_93 & V_127 )
F_42 ( L_26 , V_123 [ V_92 -> V_124 ] ) ;
if ( V_93 & V_128 )
F_42 ( L_27 , V_123 [ V_92 -> V_124 ] ) ;
if ( V_93 & V_129 )
F_42 ( L_28 , V_123 [ V_92 -> V_124 ] ) ;
if ( V_93 & V_130 )
F_42 ( L_29 , V_123 [ V_92 -> V_124 ] ) ;
if ( V_93 & V_131 )
F_42 ( L_30 , V_123 [ V_92 -> V_124 ] ) ;
if ( V_93 & V_132 )
F_42 ( L_31 , V_123 [ V_92 -> V_124 ] ) ;
if ( V_93 & V_133 )
F_42 ( L_32 , V_123 [ V_92 -> V_124 ] ) ;
if ( V_93 & V_134 )
F_42 ( L_33 , V_123 [ V_92 -> V_124 ] ) ;
}
}
V_21 ++ ;
}
}
bool F_45 ( struct V_89 * V_89 ,
bool V_135 )
{
T_3 V_136 = 0x0 ;
T_3 V_137 [ 8 ] ;
int V_85 ;
struct V_138 V_139 [] = {
{
. V_140 = V_141 ,
. V_20 = 0 ,
. V_142 = 1 ,
. V_137 = & V_136 ,
} ,
{
. V_140 = V_141 ,
. V_20 = V_143 ,
. V_142 = 8 ,
. V_137 = V_137 ,
}
} ;
if ( V_89 -> V_108 . V_109 )
F_46 ( V_89 ) ;
if ( V_135 ) {
V_85 = F_47 ( & V_89 -> V_98 -> V_144 . V_145 , V_139 , 2 ) ;
} else {
V_85 = F_47 ( & V_89 -> V_98 -> V_146 , V_139 , 2 ) ;
}
if ( V_85 != 2 )
return false ;
if ( F_48 ( V_137 ) < 6 ) {
return false ;
}
return true ;
}
static void F_49 ( struct V_50 * V_51 )
{
struct V_57 * V_147 = F_27 ( V_51 ) ;
F_50 ( V_147 -> V_61 ) ;
F_51 ( V_51 ) ;
F_22 ( V_147 ) ;
}
static int F_52 ( struct V_50 * V_51 ,
struct V_148 * V_149 ,
unsigned int * V_150 )
{
struct V_57 * V_147 = F_27 ( V_51 ) ;
return F_53 ( V_149 , V_147 -> V_61 , V_150 ) ;
}
int
F_54 ( struct V_55 * V_29 ,
struct V_57 * V_151 ,
const struct V_152 * V_153 ,
struct V_60 * V_61 )
{
int V_85 ;
V_151 -> V_61 = V_61 ;
F_55 ( & V_151 -> V_19 , V_153 ) ;
V_85 = F_56 ( V_29 , & V_151 -> V_19 , & V_154 ) ;
if ( V_85 ) {
V_151 -> V_61 = NULL ;
return V_85 ;
}
return 0 ;
}
static struct V_50 *
F_57 ( struct V_55 * V_29 ,
struct V_148 * V_149 ,
const struct V_152 * V_153 )
{
struct V_60 * V_61 ;
struct V_57 * V_147 ;
int V_85 ;
V_61 = F_58 ( V_149 , V_153 -> V_155 [ 0 ] ) ;
if ( V_61 == NULL ) {
F_59 ( & V_29 -> V_156 -> V_29 , L_34
L_35 , V_153 -> V_155 [ 0 ] ) ;
return F_60 ( - V_157 ) ;
}
V_147 = F_25 ( sizeof( * V_147 ) , V_65 ) ;
if ( V_147 == NULL ) {
F_50 ( V_61 ) ;
return F_60 ( - V_66 ) ;
}
V_85 = F_54 ( V_29 , V_147 , V_153 , V_61 ) ;
if ( V_85 ) {
F_22 ( V_147 ) ;
F_50 ( V_61 ) ;
return F_60 ( V_85 ) ;
}
return & V_147 -> V_19 ;
}
static void F_61 ( struct V_55 * V_29 )
{
struct V_10 * V_11 = V_29 -> V_56 ;
F_62 ( V_11 ) ;
}
int F_63 ( struct V_10 * V_11 )
{
int V_158 ;
if ( V_11 -> V_159 ) {
V_11 -> V_14 . V_160 =
F_64 ( V_11 -> V_35 , 0 , L_36 , 0 , 1 ) ;
if ( ! V_11 -> V_14 . V_160 )
return - V_66 ;
}
V_11 -> V_14 . V_161 =
F_64 ( V_11 -> V_35 , 0 , L_37 , 0 , 1 ) ;
if ( ! V_11 -> V_14 . V_161 )
return - V_66 ;
F_65 ( V_11 -> V_35 ) ;
V_158 = F_66 ( V_162 ) ;
V_11 -> V_14 . V_163 =
F_67 ( V_11 -> V_35 , 0 ,
L_38 ,
V_162 , V_158 ) ;
V_11 -> V_14 . V_164 =
F_64 ( V_11 -> V_35 , 0 ,
L_39 , 0 , 128 ) ;
if ( ! V_11 -> V_14 . V_164 )
return - V_66 ;
V_11 -> V_14 . V_165 =
F_64 ( V_11 -> V_35 , 0 ,
L_40 , 0 , 128 ) ;
if ( ! V_11 -> V_14 . V_165 )
return - V_66 ;
V_158 = F_66 ( V_166 ) ;
V_11 -> V_14 . V_167 =
F_67 ( V_11 -> V_35 , 0 ,
L_41 ,
V_166 , V_158 ) ;
V_158 = F_66 ( V_168 ) ;
V_11 -> V_14 . V_169 =
F_67 ( V_11 -> V_35 , 0 ,
L_42 ,
V_168 , V_158 ) ;
return 0 ;
}
void F_68 ( struct V_10 * V_11 )
{
if ( ( V_170 == 0 ) || ( V_170 > 2 ) )
V_11 -> V_14 . V_171 = 0 ;
else
V_11 -> V_14 . V_171 = V_170 ;
}
static bool F_69 ( const struct V_172 * V_173 )
{
if ( ( V_173 -> V_174 == 480 && V_173 -> V_175 == 720 ) ||
( V_173 -> V_174 == 576 ) ||
( V_173 -> V_174 == 720 ) ||
( V_173 -> V_174 == 1080 ) )
return true ;
else
return false ;
}
bool F_70 ( struct V_17 * V_18 ,
const struct V_172 * V_173 ,
struct V_172 * V_176 )
{
struct V_55 * V_29 = V_18 -> V_29 ;
struct V_90 * V_91 ;
struct V_12 * V_12 = F_24 ( V_18 ) ;
struct V_92 * V_92 ;
struct V_87 * V_88 ;
struct V_89 * V_89 ;
T_4 V_177 = 1 , V_178 = 1 ;
T_4 V_179 = 1 , V_180 = 1 ;
V_12 -> V_181 = 0 ;
V_12 -> V_182 = 0 ;
F_38 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_91 -> V_18 != V_18 )
continue;
V_92 = F_44 ( V_91 ) ;
V_88 = F_71 ( V_91 ) ;
V_89 = F_43 ( V_88 ) ;
if ( V_92 -> V_183 == V_184 )
V_12 -> V_183 = V_184 ;
else if ( V_173 -> V_175 < V_92 -> V_185 . V_175 ||
V_173 -> V_174 < V_92 -> V_185 . V_174 )
V_12 -> V_183 = V_92 -> V_183 ;
else
V_12 -> V_183 = V_184 ;
memcpy ( & V_12 -> V_185 ,
& V_92 -> V_185 ,
sizeof( struct V_172 ) ) ;
V_177 = V_18 -> V_173 . V_174 ;
V_178 = V_12 -> V_185 . V_174 ;
V_179 = V_18 -> V_173 . V_175 ;
V_180 = V_12 -> V_185 . V_175 ;
if ( ( ! ( V_173 -> V_20 & V_186 ) ) &&
( ( V_92 -> V_187 == V_188 ) ||
( ( V_92 -> V_187 == V_189 ) &&
F_72 ( F_73 ( V_88 ) ) &&
F_69 ( V_173 ) ) ) ) {
if ( V_92 -> V_190 != 0 )
V_12 -> V_181 = V_92 -> V_190 ;
else
V_12 -> V_181 = ( V_173 -> V_175 >> 5 ) + 16 ;
if ( V_92 -> V_191 != 0 )
V_12 -> V_182 = V_92 -> V_191 ;
else
V_12 -> V_182 = ( V_173 -> V_174 >> 5 ) + 16 ;
V_12 -> V_183 = V_192 ;
V_177 = V_18 -> V_173 . V_174 ;
V_178 = V_18 -> V_173 . V_174 - ( V_12 -> V_182 * 2 ) ;
V_179 = V_18 -> V_173 . V_175 ;
V_180 = V_18 -> V_173 . V_175 - ( V_12 -> V_181 * 2 ) ;
}
}
if ( V_12 -> V_183 != V_184 ) {
T_5 V_193 , V_194 ;
V_193 . V_195 = F_74 ( V_177 ) ;
V_194 . V_195 = F_74 ( V_178 ) ;
V_12 -> V_196 . V_195 = F_75 ( V_193 , V_194 ) ;
V_193 . V_195 = F_74 ( V_179 ) ;
V_194 . V_195 = F_74 ( V_180 ) ;
V_12 -> V_197 . V_195 = F_75 ( V_193 , V_194 ) ;
} else {
V_12 -> V_196 . V_195 = F_74 ( 1 ) ;
V_12 -> V_197 . V_195 = F_74 ( 1 ) ;
}
return true ;
}
int F_9 ( struct V_55 * V_29 , unsigned int V_198 ,
unsigned int V_20 , int * V_23 , int * V_24 ,
T_6 * V_199 , T_6 * V_200 ,
const struct V_172 * V_173 )
{
T_4 V_201 = 0 , V_202 = 0 ;
int V_203 , V_204 , V_205 , V_85 = 0 ;
bool V_206 = true ;
struct V_10 * V_11 = V_29 -> V_56 ;
if ( V_199 )
* V_199 = F_76 () ;
if ( F_77 ( V_11 , V_198 , & V_201 , & V_202 ) == 0 )
V_85 |= V_38 ;
if ( V_200 )
* V_200 = F_76 () ;
* V_23 = V_202 & 0x1fff ;
* V_24 = ( V_202 >> 16 ) & 0x1fff ;
if ( V_201 > 0 ) {
V_85 |= V_39 ;
V_203 = V_201 & 0x1fff ;
V_204 = ( V_201 >> 16 ) & 0x1fff ;
}
else {
V_203 = V_173 -> V_207 ;
V_204 = 0 ;
}
if ( V_20 & V_36 ) {
* V_24 = * V_23 - V_203 ;
}
if ( ! ( V_20 & V_208 ) )
V_203 -= V_11 -> V_14 . V_15 [ V_198 ] -> V_209 ;
if ( ( * V_23 < V_203 ) && ( * V_23 >= V_204 ) )
V_206 = false ;
if ( V_206 )
V_85 |= V_210 ;
if ( V_20 & V_36 ) {
* V_23 -= V_203 ;
return V_85 ;
}
if ( V_206 && ( * V_23 >= V_203 ) ) {
V_205 = V_173 -> V_211 ;
* V_23 = * V_23 - V_205 ;
}
* V_23 = * V_23 - V_204 ;
return V_85 ;
}
int F_78 ( struct V_10 * V_11 , int V_18 )
{
if ( V_18 < 0 || V_18 >= V_11 -> V_14 . V_212 )
return V_213 ;
switch ( V_18 ) {
case 0 :
return V_214 ;
case 1 :
return V_215 ;
case 2 :
return V_216 ;
case 3 :
return V_217 ;
case 4 :
return V_218 ;
case 5 :
return V_219 ;
default:
return V_213 ;
}
}
