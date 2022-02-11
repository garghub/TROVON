static void F_1 ( struct V_1 * V_2 ,
struct V_3 * * V_4 )
{
struct V_5 * V_3 ;
long V_6 ;
if ( * V_4 == NULL )
return;
V_3 = F_2 ( * V_4 ) ;
if ( V_3 ) {
V_6 = F_3 ( & V_3 -> V_7 , false ) ;
if ( V_6 == - V_8 )
V_6 = F_4 ( V_2 ) ;
} else
V_6 = F_3 ( * V_4 , false ) ;
if ( V_6 )
F_5 ( L_1 , V_6 ) ;
F_6 ( * V_4 ) ;
* V_4 = NULL ;
}
static void F_7 ( struct V_9 * V_10 )
{
struct V_11 * V_12 =
F_8 ( V_10 , struct V_11 , V_13 ) ;
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_14 * V_15 = V_2 -> V_16 . V_17 [ V_12 -> V_18 ] ;
struct V_19 * V_20 = & V_15 -> V_7 ;
unsigned long V_21 ;
unsigned V_22 ;
int V_23 , V_24 , V_25 , V_26 ;
struct V_27 * V_28 = & V_20 -> V_29 -> V_28 [ V_12 -> V_18 ] ;
F_1 ( V_2 , & V_12 -> V_30 ) ;
for ( V_22 = 0 ; V_22 < V_12 -> V_31 ; ++ V_22 )
F_1 ( V_2 , & V_12 -> V_32 [ V_22 ] ) ;
F_9 ( & V_20 -> V_29 -> V_33 , V_21 ) ;
for (; ; ) {
V_25 = F_10 ( V_2 -> V_34 , V_12 -> V_18 ,
V_35 ,
& V_23 , & V_24 , NULL , NULL ,
& V_20 -> V_36 ) ;
if ( ( V_25 & ( V_37 | V_38 ) ) !=
( V_37 | V_38 ) ||
! ( V_23 >= 0 && V_24 <= 0 ) )
break;
F_11 ( & V_20 -> V_29 -> V_33 , V_21 ) ;
V_26 = ( - V_24 + 1 ) * F_12 ( V_28 -> V_39 / 1000 , 5 ) ;
F_13 ( V_26 , 2 * V_26 ) ;
F_9 ( & V_20 -> V_29 -> V_33 , V_21 ) ;
} ;
V_2 -> V_16 . V_40 -> V_41 ( V_2 , V_12 -> V_18 , V_12 -> V_7 ) ;
V_15 -> V_42 = V_43 ;
F_11 ( & V_20 -> V_29 -> V_33 , V_21 ) ;
}
static void F_14 ( struct V_9 * V_10 )
{
struct V_11 * V_12 =
F_8 ( V_10 , struct V_11 , V_44 ) ;
int V_6 ;
V_6 = F_15 ( V_12 -> V_45 , false ) ;
if ( F_16 ( V_6 == 0 ) ) {
V_6 = F_17 ( V_12 -> V_45 ) ;
if ( F_18 ( V_6 != 0 ) ) {
F_5 ( L_2 ) ;
}
F_19 ( V_12 -> V_45 ) ;
} else
F_5 ( L_3 ) ;
F_20 ( & V_12 -> V_45 ) ;
F_21 ( V_12 -> V_32 ) ;
F_21 ( V_12 ) ;
}
int F_22 ( struct V_19 * V_20 ,
struct V_46 * V_47 ,
struct V_48 * V_49 ,
T_1 V_50 )
{
struct V_51 * V_29 = V_20 -> V_29 ;
struct V_1 * V_2 = V_29 -> V_52 ;
struct V_14 * V_14 = F_23 ( V_20 ) ;
struct V_53 * V_54 ;
struct V_53 * V_55 ;
struct V_56 * V_57 ;
struct V_11 * V_12 ;
struct V_58 * V_59 ;
unsigned long V_21 ;
T_2 V_60 ;
T_2 V_7 ;
int V_22 , V_6 ;
V_12 = F_24 ( sizeof *V_12 , V_61 ) ;
if ( V_12 == NULL )
return - V_62 ;
F_25 ( & V_12 -> V_13 , F_7 ) ;
F_25 ( & V_12 -> V_44 , F_14 ) ;
V_12 -> V_49 = V_49 ;
V_12 -> V_2 = V_2 ;
V_12 -> V_18 = V_14 -> V_18 ;
V_54 = F_26 ( V_20 -> V_63 -> V_47 ) ;
V_57 = V_54 -> V_57 ;
V_12 -> V_45 = F_27 ( V_57 ) ;
F_28 ( V_12 -> V_45 ) ;
V_55 = F_26 ( V_47 ) ;
V_57 = V_55 -> V_57 ;
V_59 = F_27 ( V_57 ) ;
V_6 = F_15 ( V_59 , false ) ;
if ( F_18 ( V_6 != 0 ) ) {
F_5 ( L_4 ) ;
goto V_64;
}
V_6 = F_29 ( V_59 , V_65 , 0 , 0 , & V_7 ) ;
if ( F_18 ( V_6 != 0 ) ) {
F_19 ( V_59 ) ;
V_6 = - V_66 ;
F_5 ( L_5 ) ;
goto V_64;
}
V_6 = F_30 ( V_59 -> V_67 . V_68 , & V_12 -> V_30 ,
& V_12 -> V_31 ,
& V_12 -> V_32 ) ;
if ( F_18 ( V_6 != 0 ) ) {
F_19 ( V_59 ) ;
F_5 ( L_6 ) ;
goto V_64;
}
F_31 ( V_59 , & V_60 ) ;
F_19 ( V_59 ) ;
V_12 -> V_7 = V_7 ;
V_6 = F_32 ( V_20 -> V_29 , V_14 -> V_18 ) ;
if ( V_6 ) {
F_5 ( L_7 ) ;
goto V_69;
}
F_9 ( & V_20 -> V_29 -> V_33 , V_21 ) ;
if ( V_14 -> V_42 != V_70 ) {
F_33 ( L_8 ) ;
F_11 ( & V_20 -> V_29 -> V_33 , V_21 ) ;
V_6 = - V_71 ;
goto V_72;
}
V_14 -> V_42 = V_73 ;
V_14 -> V_74 = V_12 ;
V_20 -> V_63 -> V_47 = V_47 ;
F_11 ( & V_20 -> V_29 -> V_33 , V_21 ) ;
F_34 ( V_14 -> V_75 , & V_12 -> V_13 ) ;
return 0 ;
V_72:
F_35 ( V_20 -> V_29 , V_14 -> V_18 ) ;
V_69:
if ( F_18 ( F_15 ( V_59 , false ) != 0 ) ) {
F_5 ( L_9 ) ;
goto V_64;
}
if ( F_18 ( F_17 ( V_59 ) != 0 ) ) {
F_5 ( L_10 ) ;
}
F_19 ( V_59 ) ;
V_64:
F_20 ( & V_12 -> V_45 ) ;
F_6 ( V_12 -> V_30 ) ;
for ( V_22 = 0 ; V_22 < V_12 -> V_31 ; ++ V_22 )
F_6 ( V_12 -> V_32 [ V_22 ] ) ;
F_21 ( V_12 -> V_32 ) ;
F_21 ( V_12 ) ;
return V_6 ;
}
int F_36 ( struct V_76 * V_77 )
{
struct V_51 * V_29 ;
struct V_1 * V_2 ;
struct V_19 * V_20 ;
bool V_78 = false ;
int V_79 ;
if ( ! V_77 || ! V_77 -> V_20 )
return - V_66 ;
V_29 = V_77 -> V_20 -> V_29 ;
V_79 = F_37 ( V_29 -> V_29 ) ;
if ( V_79 < 0 )
return V_79 ;
V_79 = F_38 ( V_77 ) ;
F_39 (crtc, &dev->mode_config.crtc_list, head)
if ( V_20 -> V_80 )
V_78 = true ;
F_40 ( V_29 -> V_29 ) ;
V_2 = V_29 -> V_52 ;
if ( V_78 && ! V_2 -> V_81 ) {
V_2 -> V_81 = true ;
return V_79 ;
}
if ( ! V_78 && V_2 -> V_81 ) {
F_41 ( V_29 -> V_29 ) ;
V_2 -> V_81 = false ;
}
F_41 ( V_29 -> V_29 ) ;
return V_79 ;
}
void F_42 ( struct V_51 * V_29 )
{
struct V_82 * V_83 ;
struct V_84 * V_84 ;
struct V_85 * V_86 ;
struct V_87 * V_87 ;
T_1 V_88 ;
int V_22 = 0 ;
F_43 ( L_11 ) ;
F_39 (connector, &dev->mode_config.connector_list, head) {
V_84 = F_44 ( V_83 ) ;
F_43 ( L_12 , V_22 ) ;
F_43 ( L_13 , V_83 -> V_89 ) ;
if ( V_84 -> V_90 . V_90 != V_91 )
F_43 ( L_13 , V_92 [ V_84 -> V_90 . V_90 ] ) ;
if ( V_84 -> V_93 ) {
F_43 ( L_14 ,
V_84 -> V_93 -> V_94 . V_95 ,
V_84 -> V_93 -> V_94 . V_96 ,
V_84 -> V_93 -> V_94 . V_97 ,
V_84 -> V_93 -> V_94 . V_98 ,
V_84 -> V_93 -> V_94 . V_99 ,
V_84 -> V_93 -> V_94 . V_100 ,
V_84 -> V_93 -> V_94 . V_101 ,
V_84 -> V_93 -> V_94 . V_102 ) ;
if ( V_84 -> V_103 . V_104 )
F_43 ( L_15 ,
V_84 -> V_103 . V_105 ,
V_84 -> V_103 . V_106 ) ;
if ( V_84 -> V_103 . V_107 )
F_43 ( L_16 ,
V_84 -> V_103 . V_108 ,
V_84 -> V_103 . V_109 ) ;
} else {
if ( V_83 -> V_110 == V_111 ||
V_83 -> V_110 == V_112 ||
V_83 -> V_110 == V_113 ||
V_83 -> V_110 == V_114 ||
V_83 -> V_110 == V_115 ||
V_83 -> V_110 == V_116 )
F_43 ( L_17 ) ;
}
F_43 ( L_18 ) ;
F_39 (encoder, &dev->mode_config.encoder_list, head) {
V_87 = F_45 ( V_86 ) ;
V_88 = V_87 -> V_88 & V_84 -> V_88 ;
if ( V_88 ) {
if ( V_88 & V_117 )
F_43 ( L_19 , V_118 [ V_87 -> V_119 ] ) ;
if ( V_88 & V_120 )
F_43 ( L_20 , V_118 [ V_87 -> V_119 ] ) ;
if ( V_88 & V_121 )
F_43 ( L_21 , V_118 [ V_87 -> V_119 ] ) ;
if ( V_88 & V_122 )
F_43 ( L_22 , V_118 [ V_87 -> V_119 ] ) ;
if ( V_88 & V_123 )
F_43 ( L_23 , V_118 [ V_87 -> V_119 ] ) ;
if ( V_88 & V_124 )
F_43 ( L_24 , V_118 [ V_87 -> V_119 ] ) ;
if ( V_88 & V_125 )
F_43 ( L_25 , V_118 [ V_87 -> V_119 ] ) ;
if ( V_88 & V_126 )
F_43 ( L_26 , V_118 [ V_87 -> V_119 ] ) ;
if ( V_88 & V_127 )
F_43 ( L_27 , V_118 [ V_87 -> V_119 ] ) ;
if ( V_88 & V_128 )
F_43 ( L_28 , V_118 [ V_87 -> V_119 ] ) ;
if ( V_88 & V_129 )
F_43 ( L_29 , V_118 [ V_87 -> V_119 ] ) ;
}
}
V_22 ++ ;
}
}
bool F_46 ( struct V_84 * V_84 ,
bool V_130 )
{
T_3 V_131 = 0x0 ;
T_3 V_132 [ 8 ] ;
int V_79 ;
struct V_133 V_134 [] = {
{
. V_135 = V_136 ,
. V_21 = 0 ,
. V_137 = 1 ,
. V_132 = & V_131 ,
} ,
{
. V_135 = V_136 ,
. V_21 = V_138 ,
. V_137 = 8 ,
. V_132 = V_132 ,
}
} ;
if ( V_84 -> V_103 . V_104 )
F_47 ( V_84 ) ;
if ( V_130 ) {
V_79 = F_48 ( & V_84 -> V_93 -> V_139 . V_140 , V_134 , 2 ) ;
} else {
V_79 = F_48 ( & V_84 -> V_93 -> V_141 , V_134 , 2 ) ;
}
if ( V_79 != 2 )
return false ;
if ( F_49 ( V_132 ) < 6 ) {
return false ;
}
return true ;
}
static void F_50 ( struct V_46 * V_47 )
{
struct V_53 * V_142 = F_26 ( V_47 ) ;
if ( V_142 -> V_57 ) {
F_51 ( V_142 -> V_57 ) ;
}
F_52 ( V_47 ) ;
F_21 ( V_142 ) ;
}
static int F_53 ( struct V_46 * V_47 ,
struct V_143 * V_144 ,
unsigned int * V_145 )
{
struct V_53 * V_142 = F_26 ( V_47 ) ;
return F_54 ( V_144 , V_142 -> V_57 , V_145 ) ;
}
int
F_55 ( struct V_51 * V_29 ,
struct V_53 * V_146 ,
struct V_147 * V_148 ,
struct V_56 * V_57 )
{
int V_79 ;
V_146 -> V_57 = V_57 ;
F_56 ( & V_146 -> V_7 , V_148 ) ;
V_79 = F_57 ( V_29 , & V_146 -> V_7 , & V_149 ) ;
if ( V_79 ) {
V_146 -> V_57 = NULL ;
return V_79 ;
}
return 0 ;
}
static struct V_46 *
F_58 ( struct V_51 * V_29 ,
struct V_143 * V_144 ,
struct V_147 * V_148 )
{
struct V_56 * V_57 ;
struct V_53 * V_142 ;
int V_79 ;
V_57 = F_59 ( V_29 , V_144 , V_148 -> V_150 [ 0 ] ) ;
if ( V_57 == NULL ) {
F_60 ( & V_29 -> V_151 -> V_29 , L_30
L_31 , V_148 -> V_150 [ 0 ] ) ;
return F_61 ( - V_152 ) ;
}
V_142 = F_24 ( sizeof( * V_142 ) , V_61 ) ;
if ( V_142 == NULL ) {
F_51 ( V_57 ) ;
return F_61 ( - V_62 ) ;
}
V_79 = F_55 ( V_29 , V_142 , V_148 , V_57 ) ;
if ( V_79 ) {
F_21 ( V_142 ) ;
F_51 ( V_57 ) ;
return F_61 ( V_79 ) ;
}
return & V_142 -> V_7 ;
}
static void F_62 ( struct V_51 * V_29 )
{
struct V_1 * V_2 = V_29 -> V_52 ;
F_63 ( V_2 ) ;
}
int F_64 ( struct V_1 * V_2 )
{
int V_153 ;
if ( V_2 -> V_154 ) {
V_2 -> V_16 . V_155 =
F_65 ( V_2 -> V_34 , 0 , L_32 , 0 , 1 ) ;
if ( ! V_2 -> V_16 . V_155 )
return - V_62 ;
}
V_2 -> V_16 . V_156 =
F_65 ( V_2 -> V_34 , 0 , L_33 , 0 , 1 ) ;
if ( ! V_2 -> V_16 . V_156 )
return - V_62 ;
F_66 ( V_2 -> V_34 ) ;
V_153 = F_67 ( V_157 ) ;
V_2 -> V_16 . V_158 =
F_68 ( V_2 -> V_34 , 0 ,
L_34 ,
V_157 , V_153 ) ;
V_2 -> V_16 . V_159 =
F_65 ( V_2 -> V_34 , 0 ,
L_35 , 0 , 128 ) ;
if ( ! V_2 -> V_16 . V_159 )
return - V_62 ;
V_2 -> V_16 . V_160 =
F_65 ( V_2 -> V_34 , 0 ,
L_36 , 0 , 128 ) ;
if ( ! V_2 -> V_16 . V_160 )
return - V_62 ;
V_153 = F_67 ( V_161 ) ;
V_2 -> V_16 . V_162 =
F_68 ( V_2 -> V_34 , 0 ,
L_37 ,
V_161 , V_153 ) ;
V_153 = F_67 ( V_163 ) ;
V_2 -> V_16 . V_164 =
F_68 ( V_2 -> V_34 , 0 ,
L_38 ,
V_163 , V_153 ) ;
return 0 ;
}
void F_69 ( struct V_1 * V_2 )
{
if ( ( V_165 == 0 ) || ( V_165 > 2 ) )
V_2 -> V_16 . V_166 = 0 ;
else
V_2 -> V_16 . V_166 = V_165 ;
}
static bool F_70 ( const struct V_167 * V_168 )
{
if ( ( V_168 -> V_169 == 480 && V_168 -> V_170 == 720 ) ||
( V_168 -> V_169 == 576 ) ||
( V_168 -> V_169 == 720 ) ||
( V_168 -> V_169 == 1080 ) )
return true ;
else
return false ;
}
bool F_71 ( struct V_19 * V_20 ,
const struct V_167 * V_168 ,
struct V_167 * V_171 )
{
struct V_51 * V_29 = V_20 -> V_29 ;
struct V_85 * V_86 ;
struct V_14 * V_14 = F_23 ( V_20 ) ;
struct V_87 * V_87 ;
struct V_82 * V_83 ;
struct V_84 * V_84 ;
T_4 V_172 = 1 , V_173 = 1 ;
T_4 V_174 = 1 , V_175 = 1 ;
V_14 -> V_176 = 0 ;
V_14 -> V_177 = 0 ;
F_39 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_86 -> V_20 != V_20 )
continue;
V_87 = F_45 ( V_86 ) ;
V_83 = F_72 ( V_86 ) ;
V_84 = F_44 ( V_83 ) ;
if ( V_87 -> V_178 == V_179 )
V_14 -> V_178 = V_179 ;
else if ( V_168 -> V_170 < V_87 -> V_180 . V_170 ||
V_168 -> V_169 < V_87 -> V_180 . V_169 )
V_14 -> V_178 = V_87 -> V_178 ;
else
V_14 -> V_178 = V_179 ;
memcpy ( & V_14 -> V_180 ,
& V_87 -> V_180 ,
sizeof( struct V_167 ) ) ;
V_172 = V_20 -> V_168 . V_169 ;
V_173 = V_14 -> V_180 . V_169 ;
V_174 = V_20 -> V_168 . V_170 ;
V_175 = V_14 -> V_180 . V_170 ;
if ( ( ! ( V_168 -> V_21 & V_181 ) ) &&
( ( V_87 -> V_182 == V_183 ) ||
( ( V_87 -> V_182 == V_184 ) &&
F_73 ( F_74 ( V_83 ) ) &&
F_70 ( V_168 ) ) ) ) {
if ( V_87 -> V_185 != 0 )
V_14 -> V_176 = V_87 -> V_185 ;
else
V_14 -> V_176 = ( V_168 -> V_170 >> 5 ) + 16 ;
if ( V_87 -> V_186 != 0 )
V_14 -> V_177 = V_87 -> V_186 ;
else
V_14 -> V_177 = ( V_168 -> V_169 >> 5 ) + 16 ;
V_14 -> V_178 = V_187 ;
V_172 = V_20 -> V_168 . V_169 ;
V_173 = V_20 -> V_168 . V_169 - ( V_14 -> V_177 * 2 ) ;
V_174 = V_20 -> V_168 . V_170 ;
V_175 = V_20 -> V_168 . V_170 - ( V_14 -> V_176 * 2 ) ;
}
}
if ( V_14 -> V_178 != V_179 ) {
T_5 V_188 , V_189 ;
V_188 . V_190 = F_75 ( V_172 ) ;
V_189 . V_190 = F_75 ( V_173 ) ;
V_14 -> V_191 . V_190 = F_76 ( V_188 , V_189 ) ;
V_188 . V_190 = F_75 ( V_174 ) ;
V_189 . V_190 = F_75 ( V_175 ) ;
V_14 -> V_192 . V_190 = F_76 ( V_188 , V_189 ) ;
} else {
V_14 -> V_191 . V_190 = F_75 ( 1 ) ;
V_14 -> V_192 . V_190 = F_75 ( 1 ) ;
}
return true ;
}
int F_10 ( struct V_51 * V_29 , unsigned int V_193 ,
unsigned int V_21 , int * V_23 , int * V_24 ,
T_6 * V_194 , T_6 * V_195 ,
const struct V_167 * V_168 )
{
T_4 V_196 = 0 , V_197 = 0 ;
int V_198 , V_199 , V_200 , V_79 = 0 ;
bool V_201 = true ;
struct V_1 * V_2 = V_29 -> V_52 ;
if ( V_194 )
* V_194 = F_77 () ;
if ( F_78 ( V_2 , V_193 , & V_196 , & V_197 ) == 0 )
V_79 |= V_37 ;
if ( V_195 )
* V_195 = F_77 () ;
* V_23 = V_197 & 0x1fff ;
* V_24 = ( V_197 >> 16 ) & 0x1fff ;
if ( V_196 > 0 ) {
V_79 |= V_38 ;
V_198 = V_196 & 0x1fff ;
V_199 = ( V_196 >> 16 ) & 0x1fff ;
}
else {
V_198 = V_168 -> V_202 ;
V_199 = 0 ;
}
if ( V_21 & V_35 ) {
* V_24 = * V_23 - V_198 ;
}
if ( ! ( V_21 & V_203 ) )
V_198 -= V_2 -> V_16 . V_17 [ V_193 ] -> V_204 ;
if ( ( * V_23 < V_198 ) && ( * V_23 >= V_199 ) )
V_201 = false ;
if ( V_201 )
V_79 |= V_205 ;
if ( V_21 & V_35 ) {
* V_23 -= V_198 ;
return V_79 ;
}
if ( V_201 && ( * V_23 >= V_198 ) ) {
V_200 = V_168 -> V_206 ;
* V_23 = * V_23 - V_200 ;
}
* V_23 = * V_23 - V_199 ;
return V_79 ;
}
int F_79 ( struct V_1 * V_2 , int V_20 )
{
if ( V_20 < 0 || V_20 >= V_2 -> V_16 . V_207 )
return V_208 ;
switch ( V_20 ) {
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
