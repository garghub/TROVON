static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 =
F_2 ( V_4 , struct V_5 , V_4 ) ;
F_3 ( V_2 ) ;
F_4 ( & V_6 -> V_7 . V_6 ) ;
}
static bool F_5 ( struct V_5 * V_6 ,
struct V_1 * * V_2 )
{
struct V_1 * V_8 = * V_2 ;
if ( V_8 == NULL )
return false ;
* V_2 = NULL ;
if ( ! F_6 ( V_8 , & V_6 -> V_4 , F_1 ) )
return true ;
F_3 ( V_8 ) ;
return false ;
}
static void F_7 ( struct V_9 * V_10 )
{
struct V_11 * V_11 =
F_2 ( V_10 , struct V_11 , V_6 ) ;
struct V_5 * V_6 =
F_2 ( V_11 , struct V_5 , V_7 ) ;
struct V_12 * V_13 = V_6 -> V_13 ;
struct V_14 * V_14 = V_13 -> V_15 . V_16 [ V_6 -> V_17 ] ;
struct V_18 * V_19 = & V_14 -> V_20 ;
unsigned long V_21 ;
unsigned V_22 ;
int V_23 , V_24 ;
if ( F_5 ( V_6 , & V_6 -> V_25 ) )
return;
for ( V_22 = 0 ; V_22 < V_6 -> V_26 ; ++ V_22 )
if ( F_5 ( V_6 , & V_6 -> V_27 [ V_22 ] ) )
return;
if ( V_14 -> V_28 &&
( F_8 ( V_13 -> V_29 , V_6 -> V_17 , 0 ,
& V_23 , & V_24 , NULL , NULL ,
& V_19 -> V_30 )
& ( V_31 | V_32 ) ) ==
( V_31 | V_32 ) &&
( int ) ( V_6 -> V_33 -
F_9 ( V_13 -> V_29 , V_14 -> V_17 ) ) > 0 ) {
F_10 ( & V_6 -> V_7 , F_11 ( 1000 ) ) ;
return;
}
F_12 ( & V_19 -> V_34 -> V_35 , V_21 ) ;
V_13 -> V_15 . V_36 -> V_37 ( V_13 , V_6 -> V_17 , V_6 -> V_20 , V_6 -> V_38 ) ;
V_14 -> V_39 = V_40 ;
F_13 ( & V_19 -> V_34 -> V_35 , V_21 ) ;
F_14 ( L_1 ,
V_14 -> V_17 , V_14 , V_6 ) ;
}
static void F_15 ( struct V_9 * V_10 )
{
struct V_5 * V_6 =
F_2 ( V_10 , struct V_5 , V_41 ) ;
int V_42 ;
V_42 = F_16 ( V_6 -> V_43 , true ) ;
if ( F_17 ( V_42 == 0 ) ) {
V_42 = F_18 ( V_6 -> V_43 ) ;
if ( F_19 ( V_42 != 0 ) ) {
F_20 ( L_2 ) ;
}
F_21 ( V_6 -> V_43 ) ;
} else
F_20 ( L_3 ) ;
F_22 ( & V_6 -> V_43 ) ;
F_23 ( V_6 -> V_27 ) ;
F_23 ( V_6 ) ;
}
int F_24 ( struct V_18 * V_19 ,
struct V_44 * V_45 ,
struct V_46 * V_47 ,
T_1 V_48 , T_1 V_49 ,
struct V_50 * V_51 )
{
struct V_52 * V_34 = V_19 -> V_34 ;
struct V_12 * V_13 = V_34 -> V_53 ;
struct V_14 * V_14 = F_25 ( V_19 ) ;
struct V_54 * V_55 ;
struct V_54 * V_56 ;
struct V_57 * V_58 ;
struct V_5 * V_6 ;
struct V_59 * V_60 ;
unsigned long V_21 ;
T_2 V_61 ;
T_2 V_20 ;
int V_22 , V_42 ;
V_6 = F_26 ( sizeof *V_6 , V_62 ) ;
if ( V_6 == NULL )
return - V_63 ;
F_27 ( & V_6 -> V_7 , F_7 ) ;
F_28 ( & V_6 -> V_41 , F_15 ) ;
V_6 -> V_47 = V_47 ;
V_6 -> V_13 = V_13 ;
V_6 -> V_17 = V_14 -> V_17 ;
V_6 -> V_38 = ( V_48 & V_64 ) != 0 ;
V_55 = F_29 ( V_19 -> V_65 -> V_45 ) ;
V_58 = V_55 -> V_58 ;
V_6 -> V_43 = F_30 ( V_58 ) ;
F_31 ( V_6 -> V_43 ) ;
V_56 = F_29 ( V_45 ) ;
V_58 = V_56 -> V_58 ;
V_60 = F_30 ( V_58 ) ;
V_42 = F_16 ( V_60 , false ) ;
if ( F_19 ( V_42 != 0 ) ) {
F_20 ( L_4 ) ;
goto V_66;
}
V_42 = F_32 ( V_60 , V_67 , & V_20 ) ;
if ( F_19 ( V_42 != 0 ) ) {
F_20 ( L_5 ) ;
goto V_68;
}
V_42 = F_33 ( V_60 -> V_69 . V_70 , & V_6 -> V_25 ,
& V_6 -> V_26 ,
& V_6 -> V_27 ) ;
if ( F_19 ( V_42 != 0 ) ) {
F_20 ( L_6 ) ;
goto V_71;
}
F_34 ( V_60 , & V_61 ) ;
F_21 ( V_60 ) ;
V_6 -> V_20 = V_20 ;
V_6 -> V_33 = V_49 - F_35 ( V_19 ) +
F_9 ( V_34 , V_6 -> V_17 ) ;
F_12 ( & V_19 -> V_34 -> V_35 , V_21 ) ;
if ( V_14 -> V_39 != V_72 ) {
F_14 ( L_7 ) ;
F_13 ( & V_19 -> V_34 -> V_35 , V_21 ) ;
V_42 = - V_73 ;
goto V_74;
}
V_14 -> V_39 = V_75 ;
V_14 -> V_76 = V_6 ;
F_14 ( L_8 ,
V_14 -> V_17 , V_14 , V_6 ) ;
V_19 -> V_65 -> V_45 = V_45 ;
F_13 ( & V_19 -> V_34 -> V_35 , V_21 ) ;
F_7 ( & V_6 -> V_7 . V_6 ) ;
return 0 ;
V_74:
if ( F_19 ( F_16 ( V_60 , false ) != 0 ) ) {
F_20 ( L_9 ) ;
goto V_66;
}
V_71:
if ( F_19 ( F_18 ( V_60 ) != 0 ) ) {
F_20 ( L_10 ) ;
}
V_68:
F_21 ( V_60 ) ;
V_66:
F_22 ( & V_6 -> V_43 ) ;
F_3 ( V_6 -> V_25 ) ;
for ( V_22 = 0 ; V_22 < V_6 -> V_26 ; ++ V_22 )
F_3 ( V_6 -> V_27 [ V_22 ] ) ;
F_23 ( V_6 -> V_27 ) ;
F_23 ( V_6 ) ;
return V_42 ;
}
int F_36 ( struct V_77 * V_78 ,
struct V_50 * V_51 )
{
struct V_52 * V_34 ;
struct V_12 * V_13 ;
struct V_18 * V_19 ;
bool V_79 = false ;
int V_80 ;
if ( ! V_78 || ! V_78 -> V_19 )
return - V_81 ;
V_34 = V_78 -> V_19 -> V_34 ;
V_80 = F_37 ( V_34 -> V_34 ) ;
if ( V_80 < 0 )
return V_80 ;
V_80 = F_38 ( V_78 , V_51 ) ;
F_39 (crtc, &dev->mode_config.crtc_list, head)
if ( V_19 -> V_28 )
V_79 = true ;
F_40 ( V_34 -> V_34 ) ;
V_13 = V_34 -> V_53 ;
if ( V_79 && ! V_13 -> V_82 ) {
V_13 -> V_82 = true ;
return V_80 ;
}
if ( ! V_79 && V_13 -> V_82 ) {
F_41 ( V_34 -> V_34 ) ;
V_13 -> V_82 = false ;
}
F_41 ( V_34 -> V_34 ) ;
return V_80 ;
}
void F_42 ( struct V_52 * V_34 )
{
struct V_83 * V_84 ;
struct V_85 * V_85 ;
struct V_86 * V_87 ;
struct V_88 * V_88 ;
T_1 V_89 ;
int V_22 = 0 ;
F_43 ( L_11 ) ;
F_39 (connector, &dev->mode_config.connector_list, head) {
V_85 = F_44 ( V_84 ) ;
F_43 ( L_12 , V_22 ) ;
F_43 ( L_13 , V_84 -> V_90 ) ;
if ( V_85 -> V_91 . V_91 != V_92 )
F_43 ( L_13 , V_93 [ V_85 -> V_91 . V_91 ] ) ;
if ( V_85 -> V_94 ) {
F_43 ( L_14 ,
V_85 -> V_94 -> V_95 . V_96 ,
V_85 -> V_94 -> V_95 . V_97 ,
V_85 -> V_94 -> V_95 . V_98 ,
V_85 -> V_94 -> V_95 . V_99 ,
V_85 -> V_94 -> V_95 . V_100 ,
V_85 -> V_94 -> V_95 . V_101 ,
V_85 -> V_94 -> V_95 . V_102 ,
V_85 -> V_94 -> V_95 . V_103 ) ;
if ( V_85 -> V_104 . V_105 )
F_43 ( L_15 ,
V_85 -> V_104 . V_106 ,
V_85 -> V_104 . V_107 ) ;
if ( V_85 -> V_104 . V_108 )
F_43 ( L_16 ,
V_85 -> V_104 . V_109 ,
V_85 -> V_104 . V_110 ) ;
} else {
if ( V_84 -> V_111 == V_112 ||
V_84 -> V_111 == V_113 ||
V_84 -> V_111 == V_114 ||
V_84 -> V_111 == V_115 ||
V_84 -> V_111 == V_116 ||
V_84 -> V_111 == V_117 )
F_43 ( L_17 ) ;
}
F_43 ( L_18 ) ;
F_39 (encoder, &dev->mode_config.encoder_list, head) {
V_88 = F_45 ( V_87 ) ;
V_89 = V_88 -> V_89 & V_85 -> V_89 ;
if ( V_89 ) {
if ( V_89 & V_118 )
F_43 ( L_19 , V_119 [ V_88 -> V_120 ] ) ;
if ( V_89 & V_121 )
F_43 ( L_20 , V_119 [ V_88 -> V_120 ] ) ;
if ( V_89 & V_122 )
F_43 ( L_21 , V_119 [ V_88 -> V_120 ] ) ;
if ( V_89 & V_123 )
F_43 ( L_22 , V_119 [ V_88 -> V_120 ] ) ;
if ( V_89 & V_124 )
F_43 ( L_23 , V_119 [ V_88 -> V_120 ] ) ;
if ( V_89 & V_125 )
F_43 ( L_24 , V_119 [ V_88 -> V_120 ] ) ;
if ( V_89 & V_126 )
F_43 ( L_25 , V_119 [ V_88 -> V_120 ] ) ;
if ( V_89 & V_127 )
F_43 ( L_26 , V_119 [ V_88 -> V_120 ] ) ;
if ( V_89 & V_128 )
F_43 ( L_27 , V_119 [ V_88 -> V_120 ] ) ;
if ( V_89 & V_129 )
F_43 ( L_28 , V_119 [ V_88 -> V_120 ] ) ;
if ( V_89 & V_130 )
F_43 ( L_29 , V_119 [ V_88 -> V_120 ] ) ;
}
}
V_22 ++ ;
}
}
bool F_46 ( struct V_85 * V_85 ,
bool V_131 )
{
T_3 V_132 = 0x0 ;
T_3 V_133 [ 8 ] ;
int V_80 ;
struct V_134 V_135 [] = {
{
. V_136 = V_137 ,
. V_21 = 0 ,
. V_138 = 1 ,
. V_133 = & V_132 ,
} ,
{
. V_136 = V_137 ,
. V_21 = V_139 ,
. V_138 = 8 ,
. V_133 = V_133 ,
}
} ;
if ( V_85 -> V_104 . V_105 )
F_47 ( V_85 ) ;
if ( V_131 ) {
V_80 = F_48 ( & V_85 -> V_94 -> V_140 . V_141 , V_135 , 2 ) ;
} else {
V_80 = F_48 ( & V_85 -> V_94 -> V_142 , V_135 , 2 ) ;
}
if ( V_80 != 2 )
return false ;
if ( F_49 ( V_133 ) < 6 ) {
return false ;
}
return true ;
}
static void F_50 ( struct V_44 * V_45 )
{
struct V_54 * V_143 = F_29 ( V_45 ) ;
F_51 ( V_143 -> V_58 ) ;
F_52 ( V_45 ) ;
F_23 ( V_143 ) ;
}
static int F_53 ( struct V_44 * V_45 ,
struct V_144 * V_145 ,
unsigned int * V_146 )
{
struct V_54 * V_143 = F_29 ( V_45 ) ;
return F_54 ( V_145 , V_143 -> V_58 , V_146 ) ;
}
int
F_55 ( struct V_52 * V_34 ,
struct V_54 * V_147 ,
const struct V_148 * V_149 ,
struct V_57 * V_58 )
{
int V_80 ;
V_147 -> V_58 = V_58 ;
F_56 ( V_34 , & V_147 -> V_20 , V_149 ) ;
V_80 = F_57 ( V_34 , & V_147 -> V_20 , & V_150 ) ;
if ( V_80 ) {
V_147 -> V_58 = NULL ;
return V_80 ;
}
return 0 ;
}
static struct V_44 *
F_58 ( struct V_52 * V_34 ,
struct V_144 * V_145 ,
const struct V_148 * V_149 )
{
struct V_57 * V_58 ;
struct V_54 * V_143 ;
int V_80 ;
V_58 = F_59 ( V_145 , V_149 -> V_151 [ 0 ] ) ;
if ( V_58 == NULL ) {
F_60 ( & V_34 -> V_152 -> V_34 , L_30
L_31 , V_149 -> V_151 [ 0 ] ) ;
return F_61 ( - V_153 ) ;
}
if ( V_58 -> V_154 ) {
F_62 ( L_32 ) ;
return F_61 ( - V_81 ) ;
}
V_143 = F_26 ( sizeof( * V_143 ) , V_62 ) ;
if ( V_143 == NULL ) {
F_51 ( V_58 ) ;
return F_61 ( - V_63 ) ;
}
V_80 = F_55 ( V_34 , V_143 , V_149 , V_58 ) ;
if ( V_80 ) {
F_23 ( V_143 ) ;
F_51 ( V_58 ) ;
return F_61 ( V_80 ) ;
}
return & V_143 -> V_20 ;
}
static void F_63 ( struct V_52 * V_34 )
{
struct V_12 * V_13 = V_34 -> V_53 ;
F_64 ( V_13 ) ;
}
int F_65 ( struct V_12 * V_13 )
{
int V_155 ;
V_13 -> V_15 . V_156 =
F_66 ( V_13 -> V_29 , 0 , L_33 , 0 , 1 ) ;
if ( ! V_13 -> V_15 . V_156 )
return - V_63 ;
V_13 -> V_15 . V_157 =
F_66 ( V_13 -> V_29 , 0 , L_34 , 0 , 1 ) ;
if ( ! V_13 -> V_15 . V_157 )
return - V_63 ;
F_67 ( V_13 -> V_29 ) ;
V_155 = F_68 ( V_158 ) ;
V_13 -> V_15 . V_159 =
F_69 ( V_13 -> V_29 , 0 ,
L_35 ,
V_158 , V_155 ) ;
V_13 -> V_15 . V_160 =
F_66 ( V_13 -> V_29 , 0 ,
L_36 , 0 , 128 ) ;
if ( ! V_13 -> V_15 . V_160 )
return - V_63 ;
V_13 -> V_15 . V_161 =
F_66 ( V_13 -> V_29 , 0 ,
L_37 , 0 , 128 ) ;
if ( ! V_13 -> V_15 . V_161 )
return - V_63 ;
V_155 = F_68 ( V_162 ) ;
V_13 -> V_15 . V_163 =
F_69 ( V_13 -> V_29 , 0 ,
L_38 ,
V_162 , V_155 ) ;
V_155 = F_68 ( V_164 ) ;
V_13 -> V_15 . V_165 =
F_69 ( V_13 -> V_29 , 0 ,
L_39 ,
V_164 , V_155 ) ;
return 0 ;
}
void F_70 ( struct V_12 * V_13 )
{
if ( ( V_166 == 0 ) || ( V_166 > 2 ) )
V_13 -> V_15 . V_167 = 0 ;
else
V_13 -> V_15 . V_167 = V_166 ;
}
static bool F_71 ( const struct V_168 * V_169 )
{
if ( ( V_169 -> V_170 == 480 && V_169 -> V_171 == 720 ) ||
( V_169 -> V_170 == 576 ) ||
( V_169 -> V_170 == 720 ) ||
( V_169 -> V_170 == 1080 ) )
return true ;
else
return false ;
}
bool F_72 ( struct V_18 * V_19 ,
const struct V_168 * V_169 ,
struct V_168 * V_172 )
{
struct V_52 * V_34 = V_19 -> V_34 ;
struct V_86 * V_87 ;
struct V_14 * V_14 = F_25 ( V_19 ) ;
struct V_88 * V_88 ;
struct V_83 * V_84 ;
struct V_85 * V_85 ;
T_4 V_173 = 1 , V_174 = 1 ;
T_4 V_175 = 1 , V_176 = 1 ;
V_14 -> V_177 = 0 ;
V_14 -> V_178 = 0 ;
F_39 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_87 -> V_19 != V_19 )
continue;
V_88 = F_45 ( V_87 ) ;
V_84 = F_73 ( V_87 ) ;
V_85 = F_44 ( V_84 ) ;
if ( V_88 -> V_179 == V_180 )
V_14 -> V_179 = V_180 ;
else if ( V_169 -> V_171 < V_88 -> V_181 . V_171 ||
V_169 -> V_170 < V_88 -> V_181 . V_170 )
V_14 -> V_179 = V_88 -> V_179 ;
else
V_14 -> V_179 = V_180 ;
memcpy ( & V_14 -> V_181 ,
& V_88 -> V_181 ,
sizeof( struct V_168 ) ) ;
V_173 = V_19 -> V_169 . V_170 ;
V_174 = V_14 -> V_181 . V_170 ;
V_175 = V_19 -> V_169 . V_171 ;
V_176 = V_14 -> V_181 . V_171 ;
if ( ( ! ( V_169 -> V_21 & V_182 ) ) &&
( ( V_88 -> V_183 == V_184 ) ||
( ( V_88 -> V_183 == V_185 ) &&
F_74 ( F_75 ( V_84 ) ) &&
F_71 ( V_169 ) ) ) ) {
if ( V_88 -> V_186 != 0 )
V_14 -> V_177 = V_88 -> V_186 ;
else
V_14 -> V_177 = ( V_169 -> V_171 >> 5 ) + 16 ;
if ( V_88 -> V_187 != 0 )
V_14 -> V_178 = V_88 -> V_187 ;
else
V_14 -> V_178 = ( V_169 -> V_170 >> 5 ) + 16 ;
V_14 -> V_179 = V_188 ;
V_173 = V_19 -> V_169 . V_170 ;
V_174 = V_19 -> V_169 . V_170 - ( V_14 -> V_178 * 2 ) ;
V_175 = V_19 -> V_169 . V_171 ;
V_176 = V_19 -> V_169 . V_171 - ( V_14 -> V_177 * 2 ) ;
}
}
if ( V_14 -> V_179 != V_180 ) {
T_5 V_189 , V_190 ;
V_189 . V_191 = F_76 ( V_173 ) ;
V_190 . V_191 = F_76 ( V_174 ) ;
V_14 -> V_192 . V_191 = F_77 ( V_189 , V_190 ) ;
V_189 . V_191 = F_76 ( V_175 ) ;
V_190 . V_191 = F_76 ( V_176 ) ;
V_14 -> V_193 . V_191 = F_77 ( V_189 , V_190 ) ;
} else {
V_14 -> V_192 . V_191 = F_76 ( 1 ) ;
V_14 -> V_193 . V_191 = F_76 ( 1 ) ;
}
return true ;
}
int F_8 ( struct V_52 * V_34 , unsigned int V_194 ,
unsigned int V_21 , int * V_23 , int * V_24 ,
T_6 * V_195 , T_6 * V_196 ,
const struct V_168 * V_169 )
{
T_4 V_197 = 0 , V_198 = 0 ;
int V_199 , V_200 , V_201 , V_80 = 0 ;
bool V_202 = true ;
struct V_12 * V_13 = V_34 -> V_53 ;
if ( V_195 )
* V_195 = F_78 () ;
if ( F_79 ( V_13 , V_194 , & V_197 , & V_198 ) == 0 )
V_80 |= V_31 ;
if ( V_196 )
* V_196 = F_78 () ;
* V_23 = V_198 & 0x1fff ;
* V_24 = ( V_198 >> 16 ) & 0x1fff ;
if ( V_197 > 0 ) {
V_80 |= V_203 ;
V_199 = V_197 & 0x1fff ;
V_200 = ( V_197 >> 16 ) & 0x1fff ;
}
else {
V_199 = V_169 -> V_204 ;
V_200 = 0 ;
}
if ( V_21 & V_205 ) {
* V_24 = * V_23 - V_199 ;
}
if ( ! ( V_21 & V_206 ) )
V_199 -= V_13 -> V_15 . V_16 [ V_194 ] -> V_207 ;
if ( ( * V_23 < V_199 ) && ( * V_23 >= V_200 ) )
V_202 = false ;
if ( V_202 )
V_80 |= V_32 ;
if ( V_21 & V_205 ) {
* V_23 -= V_199 ;
return V_80 ;
}
if ( V_202 && ( * V_23 >= V_199 ) ) {
V_201 = V_169 -> V_208 ;
* V_23 = * V_23 - V_201 ;
}
* V_23 = * V_23 - V_200 ;
return V_80 ;
}
int F_80 ( struct V_12 * V_13 , int V_19 )
{
if ( V_19 < 0 || V_19 >= V_13 -> V_15 . V_209 )
return V_210 ;
switch ( V_19 ) {
case 0 :
return V_211 ;
case 1 :
return V_212 ;
case 2 :
return V_213 ;
case 3 :
return V_214 ;
case 4 :
return V_215 ;
case 5 :
return V_216 ;
default:
return V_210 ;
}
}
