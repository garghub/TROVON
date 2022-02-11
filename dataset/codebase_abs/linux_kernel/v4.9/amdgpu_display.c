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
struct V_10 * V_10 =
F_2 ( V_9 , struct V_10 , V_6 ) ;
struct V_5 * V_6 =
F_2 ( V_10 , struct V_5 , V_7 ) ;
struct V_11 * V_12 = V_6 -> V_12 ;
struct V_13 * V_14 = V_12 -> V_15 . V_16 [ V_6 -> V_17 ] ;
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
( F_8 ( V_12 -> V_29 , V_6 -> V_17 , 0 ,
& V_23 , & V_24 , NULL , NULL ,
& V_19 -> V_30 )
& ( V_31 | V_32 ) ) ==
( V_31 | V_32 ) &&
( int ) ( V_6 -> V_33 -
F_9 ( V_12 -> V_29 , V_14 -> V_17 ) ) > 0 ) {
F_10 ( & V_6 -> V_7 , F_11 ( 1000 ) ) ;
return;
}
F_12 ( & V_19 -> V_34 -> V_35 , V_21 ) ;
V_12 -> V_15 . V_36 -> V_37 ( V_12 , V_6 -> V_17 , V_6 -> V_20 , V_6 -> V_38 ) ;
V_14 -> V_39 = V_40 ;
F_13 ( & V_19 -> V_34 -> V_35 , V_21 ) ;
F_14 ( L_1 ,
V_14 -> V_17 , V_14 , V_6 ) ;
}
static void F_15 ( struct V_8 * V_9 )
{
struct V_5 * V_6 =
F_2 ( V_9 , struct V_5 , V_41 ) ;
int V_42 ;
V_42 = F_16 ( V_6 -> V_43 , false ) ;
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
T_1 V_48 , T_1 V_49 )
{
struct V_50 * V_34 = V_19 -> V_34 ;
struct V_11 * V_12 = V_34 -> V_51 ;
struct V_13 * V_13 = F_25 ( V_19 ) ;
struct V_52 * V_53 ;
struct V_52 * V_54 ;
struct V_55 * V_56 ;
struct V_5 * V_6 ;
struct V_57 * V_58 ;
unsigned long V_21 ;
T_2 V_59 ;
T_2 V_20 ;
int V_22 , V_42 ;
V_6 = F_26 ( sizeof *V_6 , V_60 ) ;
if ( V_6 == NULL )
return - V_61 ;
F_27 ( & V_6 -> V_7 , F_7 ) ;
F_28 ( & V_6 -> V_41 , F_15 ) ;
V_6 -> V_47 = V_47 ;
V_6 -> V_12 = V_12 ;
V_6 -> V_17 = V_13 -> V_17 ;
V_6 -> V_38 = ( V_48 & V_62 ) != 0 ;
V_53 = F_29 ( V_19 -> V_63 -> V_45 ) ;
V_56 = V_53 -> V_56 ;
V_6 -> V_43 = F_30 ( V_56 ) ;
F_31 ( V_6 -> V_43 ) ;
V_54 = F_29 ( V_45 ) ;
V_56 = V_54 -> V_56 ;
V_58 = F_30 ( V_56 ) ;
V_42 = F_16 ( V_58 , false ) ;
if ( F_19 ( V_42 != 0 ) ) {
F_20 ( L_4 ) ;
goto V_64;
}
V_42 = F_32 ( V_58 , V_65 , 0 , 0 , & V_20 ) ;
if ( F_19 ( V_42 != 0 ) ) {
V_42 = - V_66 ;
F_20 ( L_5 ) ;
goto V_67;
}
V_42 = F_33 ( V_58 -> V_68 . V_69 , & V_6 -> V_25 ,
& V_6 -> V_26 ,
& V_6 -> V_27 ) ;
if ( F_19 ( V_42 != 0 ) ) {
F_20 ( L_6 ) ;
goto V_70;
}
F_34 ( V_58 , & V_59 ) ;
F_21 ( V_58 ) ;
V_6 -> V_20 = V_20 ;
V_6 -> V_33 = V_49 - F_35 ( V_19 ) +
F_9 ( V_34 , V_6 -> V_17 ) ;
F_12 ( & V_19 -> V_34 -> V_35 , V_21 ) ;
if ( V_13 -> V_39 != V_71 ) {
F_14 ( L_7 ) ;
F_13 ( & V_19 -> V_34 -> V_35 , V_21 ) ;
V_42 = - V_72 ;
goto V_73;
}
V_13 -> V_39 = V_74 ;
V_13 -> V_75 = V_6 ;
F_14 ( L_8 ,
V_13 -> V_17 , V_13 , V_6 ) ;
V_19 -> V_63 -> V_45 = V_45 ;
F_13 ( & V_19 -> V_34 -> V_35 , V_21 ) ;
F_7 ( & V_6 -> V_7 . V_6 ) ;
return 0 ;
V_73:
if ( F_19 ( F_16 ( V_58 , false ) != 0 ) ) {
F_20 ( L_9 ) ;
goto V_64;
}
V_70:
if ( F_19 ( F_18 ( V_58 ) != 0 ) ) {
F_20 ( L_10 ) ;
}
V_67:
F_21 ( V_58 ) ;
V_64:
F_22 ( & V_6 -> V_43 ) ;
F_3 ( V_6 -> V_25 ) ;
for ( V_22 = 0 ; V_22 < V_6 -> V_26 ; ++ V_22 )
F_3 ( V_6 -> V_27 [ V_22 ] ) ;
F_23 ( V_6 -> V_27 ) ;
F_23 ( V_6 ) ;
return V_42 ;
}
int F_36 ( struct V_76 * V_77 )
{
struct V_50 * V_34 ;
struct V_11 * V_12 ;
struct V_18 * V_19 ;
bool V_78 = false ;
int V_79 ;
if ( ! V_77 || ! V_77 -> V_19 )
return - V_66 ;
V_34 = V_77 -> V_19 -> V_34 ;
V_79 = F_37 ( V_34 -> V_34 ) ;
if ( V_79 < 0 )
return V_79 ;
V_79 = F_38 ( V_77 ) ;
F_39 (crtc, &dev->mode_config.crtc_list, head)
if ( V_19 -> V_28 )
V_78 = true ;
F_40 ( V_34 -> V_34 ) ;
V_12 = V_34 -> V_51 ;
if ( V_78 && ! V_12 -> V_80 ) {
V_12 -> V_80 = true ;
return V_79 ;
}
if ( ! V_78 && V_12 -> V_80 ) {
F_41 ( V_34 -> V_34 ) ;
V_12 -> V_80 = false ;
}
F_41 ( V_34 -> V_34 ) ;
return V_79 ;
}
void F_42 ( struct V_50 * V_34 )
{
struct V_81 * V_82 ;
struct V_83 * V_83 ;
struct V_84 * V_85 ;
struct V_86 * V_86 ;
T_1 V_87 ;
int V_22 = 0 ;
F_43 ( L_11 ) ;
F_39 (connector, &dev->mode_config.connector_list, head) {
V_83 = F_44 ( V_82 ) ;
F_43 ( L_12 , V_22 ) ;
F_43 ( L_13 , V_82 -> V_88 ) ;
if ( V_83 -> V_89 . V_89 != V_90 )
F_43 ( L_13 , V_91 [ V_83 -> V_89 . V_89 ] ) ;
if ( V_83 -> V_92 ) {
F_43 ( L_14 ,
V_83 -> V_92 -> V_93 . V_94 ,
V_83 -> V_92 -> V_93 . V_95 ,
V_83 -> V_92 -> V_93 . V_96 ,
V_83 -> V_92 -> V_93 . V_97 ,
V_83 -> V_92 -> V_93 . V_98 ,
V_83 -> V_92 -> V_93 . V_99 ,
V_83 -> V_92 -> V_93 . V_100 ,
V_83 -> V_92 -> V_93 . V_101 ) ;
if ( V_83 -> V_102 . V_103 )
F_43 ( L_15 ,
V_83 -> V_102 . V_104 ,
V_83 -> V_102 . V_105 ) ;
if ( V_83 -> V_102 . V_106 )
F_43 ( L_16 ,
V_83 -> V_102 . V_107 ,
V_83 -> V_102 . V_108 ) ;
} else {
if ( V_82 -> V_109 == V_110 ||
V_82 -> V_109 == V_111 ||
V_82 -> V_109 == V_112 ||
V_82 -> V_109 == V_113 ||
V_82 -> V_109 == V_114 ||
V_82 -> V_109 == V_115 )
F_43 ( L_17 ) ;
}
F_43 ( L_18 ) ;
F_39 (encoder, &dev->mode_config.encoder_list, head) {
V_86 = F_45 ( V_85 ) ;
V_87 = V_86 -> V_87 & V_83 -> V_87 ;
if ( V_87 ) {
if ( V_87 & V_116 )
F_43 ( L_19 , V_117 [ V_86 -> V_118 ] ) ;
if ( V_87 & V_119 )
F_43 ( L_20 , V_117 [ V_86 -> V_118 ] ) ;
if ( V_87 & V_120 )
F_43 ( L_21 , V_117 [ V_86 -> V_118 ] ) ;
if ( V_87 & V_121 )
F_43 ( L_22 , V_117 [ V_86 -> V_118 ] ) ;
if ( V_87 & V_122 )
F_43 ( L_23 , V_117 [ V_86 -> V_118 ] ) ;
if ( V_87 & V_123 )
F_43 ( L_24 , V_117 [ V_86 -> V_118 ] ) ;
if ( V_87 & V_124 )
F_43 ( L_25 , V_117 [ V_86 -> V_118 ] ) ;
if ( V_87 & V_125 )
F_43 ( L_26 , V_117 [ V_86 -> V_118 ] ) ;
if ( V_87 & V_126 )
F_43 ( L_27 , V_117 [ V_86 -> V_118 ] ) ;
if ( V_87 & V_127 )
F_43 ( L_28 , V_117 [ V_86 -> V_118 ] ) ;
if ( V_87 & V_128 )
F_43 ( L_29 , V_117 [ V_86 -> V_118 ] ) ;
}
}
V_22 ++ ;
}
}
bool F_46 ( struct V_83 * V_83 ,
bool V_129 )
{
T_3 V_130 = 0x0 ;
T_3 V_131 [ 8 ] ;
int V_79 ;
struct V_132 V_133 [] = {
{
. V_134 = V_135 ,
. V_21 = 0 ,
. V_136 = 1 ,
. V_131 = & V_130 ,
} ,
{
. V_134 = V_135 ,
. V_21 = V_137 ,
. V_136 = 8 ,
. V_131 = V_131 ,
}
} ;
if ( V_83 -> V_102 . V_103 )
F_47 ( V_83 ) ;
if ( V_129 ) {
V_79 = F_48 ( & V_83 -> V_92 -> V_138 . V_139 , V_133 , 2 ) ;
} else {
V_79 = F_48 ( & V_83 -> V_92 -> V_140 , V_133 , 2 ) ;
}
if ( V_79 != 2 )
return false ;
if ( F_49 ( V_131 ) < 6 ) {
return false ;
}
return true ;
}
static void F_50 ( struct V_44 * V_45 )
{
struct V_52 * V_141 = F_29 ( V_45 ) ;
F_51 ( V_141 -> V_56 ) ;
F_52 ( V_45 ) ;
F_23 ( V_141 ) ;
}
static int F_53 ( struct V_44 * V_45 ,
struct V_142 * V_143 ,
unsigned int * V_144 )
{
struct V_52 * V_141 = F_29 ( V_45 ) ;
return F_54 ( V_143 , V_141 -> V_56 , V_144 ) ;
}
int
F_55 ( struct V_50 * V_34 ,
struct V_52 * V_145 ,
const struct V_146 * V_147 ,
struct V_55 * V_56 )
{
int V_79 ;
V_145 -> V_56 = V_56 ;
F_56 ( & V_145 -> V_20 , V_147 ) ;
V_79 = F_57 ( V_34 , & V_145 -> V_20 , & V_148 ) ;
if ( V_79 ) {
V_145 -> V_56 = NULL ;
return V_79 ;
}
return 0 ;
}
static struct V_44 *
F_58 ( struct V_50 * V_34 ,
struct V_142 * V_143 ,
const struct V_146 * V_147 )
{
struct V_55 * V_56 ;
struct V_52 * V_141 ;
int V_79 ;
V_56 = F_59 ( V_143 , V_147 -> V_149 [ 0 ] ) ;
if ( V_56 == NULL ) {
F_60 ( & V_34 -> V_150 -> V_34 , L_30
L_31 , V_147 -> V_149 [ 0 ] ) ;
return F_61 ( - V_151 ) ;
}
V_141 = F_26 ( sizeof( * V_141 ) , V_60 ) ;
if ( V_141 == NULL ) {
F_51 ( V_56 ) ;
return F_61 ( - V_61 ) ;
}
V_79 = F_55 ( V_34 , V_141 , V_147 , V_56 ) ;
if ( V_79 ) {
F_23 ( V_141 ) ;
F_51 ( V_56 ) ;
return F_61 ( V_79 ) ;
}
return & V_141 -> V_20 ;
}
static void F_62 ( struct V_50 * V_34 )
{
struct V_11 * V_12 = V_34 -> V_51 ;
F_63 ( V_12 ) ;
}
int F_64 ( struct V_11 * V_12 )
{
int V_152 ;
if ( V_12 -> V_153 ) {
V_12 -> V_15 . V_154 =
F_65 ( V_12 -> V_29 , 0 , L_32 , 0 , 1 ) ;
if ( ! V_12 -> V_15 . V_154 )
return - V_61 ;
}
V_12 -> V_15 . V_155 =
F_65 ( V_12 -> V_29 , 0 , L_33 , 0 , 1 ) ;
if ( ! V_12 -> V_15 . V_155 )
return - V_61 ;
F_66 ( V_12 -> V_29 ) ;
V_152 = F_67 ( V_156 ) ;
V_12 -> V_15 . V_157 =
F_68 ( V_12 -> V_29 , 0 ,
L_34 ,
V_156 , V_152 ) ;
V_12 -> V_15 . V_158 =
F_65 ( V_12 -> V_29 , 0 ,
L_35 , 0 , 128 ) ;
if ( ! V_12 -> V_15 . V_158 )
return - V_61 ;
V_12 -> V_15 . V_159 =
F_65 ( V_12 -> V_29 , 0 ,
L_36 , 0 , 128 ) ;
if ( ! V_12 -> V_15 . V_159 )
return - V_61 ;
V_152 = F_67 ( V_160 ) ;
V_12 -> V_15 . V_161 =
F_68 ( V_12 -> V_29 , 0 ,
L_37 ,
V_160 , V_152 ) ;
V_152 = F_67 ( V_162 ) ;
V_12 -> V_15 . V_163 =
F_68 ( V_12 -> V_29 , 0 ,
L_38 ,
V_162 , V_152 ) ;
return 0 ;
}
void F_69 ( struct V_11 * V_12 )
{
if ( ( V_164 == 0 ) || ( V_164 > 2 ) )
V_12 -> V_15 . V_165 = 0 ;
else
V_12 -> V_15 . V_165 = V_164 ;
}
static bool F_70 ( const struct V_166 * V_167 )
{
if ( ( V_167 -> V_168 == 480 && V_167 -> V_169 == 720 ) ||
( V_167 -> V_168 == 576 ) ||
( V_167 -> V_168 == 720 ) ||
( V_167 -> V_168 == 1080 ) )
return true ;
else
return false ;
}
bool F_71 ( struct V_18 * V_19 ,
const struct V_166 * V_167 ,
struct V_166 * V_170 )
{
struct V_50 * V_34 = V_19 -> V_34 ;
struct V_84 * V_85 ;
struct V_13 * V_13 = F_25 ( V_19 ) ;
struct V_86 * V_86 ;
struct V_81 * V_82 ;
struct V_83 * V_83 ;
T_4 V_171 = 1 , V_172 = 1 ;
T_4 V_173 = 1 , V_174 = 1 ;
V_13 -> V_175 = 0 ;
V_13 -> V_176 = 0 ;
F_39 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_85 -> V_19 != V_19 )
continue;
V_86 = F_45 ( V_85 ) ;
V_82 = F_72 ( V_85 ) ;
V_83 = F_44 ( V_82 ) ;
if ( V_86 -> V_177 == V_178 )
V_13 -> V_177 = V_178 ;
else if ( V_167 -> V_169 < V_86 -> V_179 . V_169 ||
V_167 -> V_168 < V_86 -> V_179 . V_168 )
V_13 -> V_177 = V_86 -> V_177 ;
else
V_13 -> V_177 = V_178 ;
memcpy ( & V_13 -> V_179 ,
& V_86 -> V_179 ,
sizeof( struct V_166 ) ) ;
V_171 = V_19 -> V_167 . V_168 ;
V_172 = V_13 -> V_179 . V_168 ;
V_173 = V_19 -> V_167 . V_169 ;
V_174 = V_13 -> V_179 . V_169 ;
if ( ( ! ( V_167 -> V_21 & V_180 ) ) &&
( ( V_86 -> V_181 == V_182 ) ||
( ( V_86 -> V_181 == V_183 ) &&
F_73 ( F_74 ( V_82 ) ) &&
F_70 ( V_167 ) ) ) ) {
if ( V_86 -> V_184 != 0 )
V_13 -> V_175 = V_86 -> V_184 ;
else
V_13 -> V_175 = ( V_167 -> V_169 >> 5 ) + 16 ;
if ( V_86 -> V_185 != 0 )
V_13 -> V_176 = V_86 -> V_185 ;
else
V_13 -> V_176 = ( V_167 -> V_168 >> 5 ) + 16 ;
V_13 -> V_177 = V_186 ;
V_171 = V_19 -> V_167 . V_168 ;
V_172 = V_19 -> V_167 . V_168 - ( V_13 -> V_176 * 2 ) ;
V_173 = V_19 -> V_167 . V_169 ;
V_174 = V_19 -> V_167 . V_169 - ( V_13 -> V_175 * 2 ) ;
}
}
if ( V_13 -> V_177 != V_178 ) {
T_5 V_187 , V_188 ;
V_187 . V_189 = F_75 ( V_171 ) ;
V_188 . V_189 = F_75 ( V_172 ) ;
V_13 -> V_190 . V_189 = F_76 ( V_187 , V_188 ) ;
V_187 . V_189 = F_75 ( V_173 ) ;
V_188 . V_189 = F_75 ( V_174 ) ;
V_13 -> V_191 . V_189 = F_76 ( V_187 , V_188 ) ;
} else {
V_13 -> V_190 . V_189 = F_75 ( 1 ) ;
V_13 -> V_191 . V_189 = F_75 ( 1 ) ;
}
return true ;
}
int F_8 ( struct V_50 * V_34 , unsigned int V_192 ,
unsigned int V_21 , int * V_23 , int * V_24 ,
T_6 * V_193 , T_6 * V_194 ,
const struct V_166 * V_167 )
{
T_4 V_195 = 0 , V_196 = 0 ;
int V_197 , V_198 , V_199 , V_79 = 0 ;
bool V_200 = true ;
struct V_11 * V_12 = V_34 -> V_51 ;
if ( V_193 )
* V_193 = F_77 () ;
if ( F_78 ( V_12 , V_192 , & V_195 , & V_196 ) == 0 )
V_79 |= V_31 ;
if ( V_194 )
* V_194 = F_77 () ;
* V_23 = V_196 & 0x1fff ;
* V_24 = ( V_196 >> 16 ) & 0x1fff ;
if ( V_195 > 0 ) {
V_79 |= V_201 ;
V_197 = V_195 & 0x1fff ;
V_198 = ( V_195 >> 16 ) & 0x1fff ;
}
else {
V_197 = V_167 -> V_202 ;
V_198 = 0 ;
}
if ( V_21 & V_203 ) {
* V_24 = * V_23 - V_197 ;
}
if ( ! ( V_21 & V_204 ) )
V_197 -= V_12 -> V_15 . V_16 [ V_192 ] -> V_205 ;
if ( ( * V_23 < V_197 ) && ( * V_23 >= V_198 ) )
V_200 = false ;
if ( V_200 )
V_79 |= V_32 ;
if ( V_21 & V_203 ) {
* V_23 -= V_197 ;
return V_79 ;
}
if ( V_200 && ( * V_23 >= V_197 ) ) {
V_199 = V_167 -> V_206 ;
* V_23 = * V_23 - V_199 ;
}
* V_23 = * V_23 - V_198 ;
return V_79 ;
}
int F_79 ( struct V_11 * V_12 , int V_19 )
{
if ( V_19 < 0 || V_19 >= V_12 -> V_15 . V_207 )
return V_208 ;
switch ( V_19 ) {
case 0 :
return V_209 ;
case 1 :
return V_210 ;
case 2 :
return V_211 ;
case 3 :
return V_212 ;
case 4 :
return V_213 ;
case 5 :
return V_214 ;
default:
return V_208 ;
}
}
