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
} ;
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
F_20 ( V_63 ) ;
V_48 = - V_71 ;
F_19 ( L_8 ) ;
goto V_69;
}
V_48 = F_31 ( V_63 -> V_72 . V_73 , & V_6 -> V_30 ,
& V_6 -> V_31 ,
& V_6 -> V_32 ) ;
if ( F_18 ( V_48 != 0 ) ) {
F_20 ( V_63 ) ;
F_19 ( L_9 ) ;
goto V_69;
}
F_32 ( V_63 , & V_64 ) ;
F_20 ( V_63 ) ;
V_6 -> V_19 = V_19 ;
V_48 = F_33 ( V_18 -> V_29 , V_12 -> V_16 ) ;
if ( V_48 ) {
F_19 ( L_10 ) ;
goto V_74;
}
F_8 ( & V_18 -> V_29 -> V_33 , V_20 ) ;
if ( V_12 -> V_45 != V_75 ) {
F_13 ( L_11 ) ;
F_11 ( & V_18 -> V_29 -> V_33 , V_20 ) ;
V_48 = - V_76 ;
goto V_77;
}
V_12 -> V_45 = V_78 ;
V_12 -> V_79 = V_6 ;
F_13 ( L_12 ,
V_12 -> V_16 , V_12 , V_6 ) ;
V_18 -> V_68 -> V_51 = V_51 ;
F_11 ( & V_18 -> V_29 -> V_33 , V_20 ) ;
F_7 ( & V_6 -> V_7 ) ;
return 0 ;
V_77:
F_34 ( V_18 -> V_29 , V_12 -> V_16 ) ;
V_74:
if ( F_18 ( F_15 ( V_63 , false ) != 0 ) ) {
F_19 ( L_13 ) ;
goto V_69;
}
if ( F_18 ( F_17 ( V_63 ) != 0 ) ) {
F_19 ( L_14 ) ;
}
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
int F_35 ( struct V_80 * V_81 )
{
struct V_55 * V_29 ;
struct V_10 * V_11 ;
struct V_17 * V_18 ;
bool V_82 = false ;
int V_83 ;
if ( ! V_81 || ! V_81 -> V_18 )
return - V_71 ;
V_29 = V_81 -> V_18 -> V_29 ;
V_83 = F_36 ( V_29 -> V_29 ) ;
if ( V_83 < 0 )
return V_83 ;
V_83 = F_37 ( V_81 ) ;
F_38 (crtc, &dev->mode_config.crtc_list, head)
if ( V_18 -> V_34 )
V_82 = true ;
F_39 ( V_29 -> V_29 ) ;
V_11 = V_29 -> V_56 ;
if ( V_82 && ! V_11 -> V_84 ) {
V_11 -> V_84 = true ;
return V_83 ;
}
if ( ! V_82 && V_11 -> V_84 ) {
F_40 ( V_29 -> V_29 ) ;
V_11 -> V_84 = false ;
}
F_40 ( V_29 -> V_29 ) ;
return V_83 ;
}
void F_41 ( struct V_55 * V_29 )
{
struct V_85 * V_86 ;
struct V_87 * V_87 ;
struct V_88 * V_89 ;
struct V_90 * V_90 ;
T_1 V_91 ;
int V_21 = 0 ;
F_42 ( L_15 ) ;
F_38 (connector, &dev->mode_config.connector_list, head) {
V_87 = F_43 ( V_86 ) ;
F_42 ( L_16 , V_21 ) ;
F_42 ( L_17 , V_86 -> V_92 ) ;
if ( V_87 -> V_93 . V_93 != V_94 )
F_42 ( L_17 , V_95 [ V_87 -> V_93 . V_93 ] ) ;
if ( V_87 -> V_96 ) {
F_42 ( L_18 ,
V_87 -> V_96 -> V_97 . V_98 ,
V_87 -> V_96 -> V_97 . V_99 ,
V_87 -> V_96 -> V_97 . V_100 ,
V_87 -> V_96 -> V_97 . V_101 ,
V_87 -> V_96 -> V_97 . V_102 ,
V_87 -> V_96 -> V_97 . V_103 ,
V_87 -> V_96 -> V_97 . V_104 ,
V_87 -> V_96 -> V_97 . V_105 ) ;
if ( V_87 -> V_106 . V_107 )
F_42 ( L_19 ,
V_87 -> V_106 . V_108 ,
V_87 -> V_106 . V_109 ) ;
if ( V_87 -> V_106 . V_110 )
F_42 ( L_20 ,
V_87 -> V_106 . V_111 ,
V_87 -> V_106 . V_112 ) ;
} else {
if ( V_86 -> V_113 == V_114 ||
V_86 -> V_113 == V_115 ||
V_86 -> V_113 == V_116 ||
V_86 -> V_113 == V_117 ||
V_86 -> V_113 == V_118 ||
V_86 -> V_113 == V_119 )
F_42 ( L_21 ) ;
}
F_42 ( L_22 ) ;
F_38 (encoder, &dev->mode_config.encoder_list, head) {
V_90 = F_44 ( V_89 ) ;
V_91 = V_90 -> V_91 & V_87 -> V_91 ;
if ( V_91 ) {
if ( V_91 & V_120 )
F_42 ( L_23 , V_121 [ V_90 -> V_122 ] ) ;
if ( V_91 & V_123 )
F_42 ( L_24 , V_121 [ V_90 -> V_122 ] ) ;
if ( V_91 & V_124 )
F_42 ( L_25 , V_121 [ V_90 -> V_122 ] ) ;
if ( V_91 & V_125 )
F_42 ( L_26 , V_121 [ V_90 -> V_122 ] ) ;
if ( V_91 & V_126 )
F_42 ( L_27 , V_121 [ V_90 -> V_122 ] ) ;
if ( V_91 & V_127 )
F_42 ( L_28 , V_121 [ V_90 -> V_122 ] ) ;
if ( V_91 & V_128 )
F_42 ( L_29 , V_121 [ V_90 -> V_122 ] ) ;
if ( V_91 & V_129 )
F_42 ( L_30 , V_121 [ V_90 -> V_122 ] ) ;
if ( V_91 & V_130 )
F_42 ( L_31 , V_121 [ V_90 -> V_122 ] ) ;
if ( V_91 & V_131 )
F_42 ( L_32 , V_121 [ V_90 -> V_122 ] ) ;
if ( V_91 & V_132 )
F_42 ( L_33 , V_121 [ V_90 -> V_122 ] ) ;
}
}
V_21 ++ ;
}
}
bool F_45 ( struct V_87 * V_87 ,
bool V_133 )
{
T_3 V_134 = 0x0 ;
T_3 V_135 [ 8 ] ;
int V_83 ;
struct V_136 V_137 [] = {
{
. V_138 = V_139 ,
. V_20 = 0 ,
. V_140 = 1 ,
. V_135 = & V_134 ,
} ,
{
. V_138 = V_139 ,
. V_20 = V_141 ,
. V_140 = 8 ,
. V_135 = V_135 ,
}
} ;
if ( V_87 -> V_106 . V_107 )
F_46 ( V_87 ) ;
if ( V_133 ) {
V_83 = F_47 ( & V_87 -> V_96 -> V_142 . V_143 , V_137 , 2 ) ;
} else {
V_83 = F_47 ( & V_87 -> V_96 -> V_144 , V_137 , 2 ) ;
}
if ( V_83 != 2 )
return false ;
if ( F_48 ( V_135 ) < 6 ) {
return false ;
}
return true ;
}
static void F_49 ( struct V_50 * V_51 )
{
struct V_57 * V_145 = F_27 ( V_51 ) ;
if ( V_145 -> V_61 ) {
F_50 ( V_145 -> V_61 ) ;
}
F_51 ( V_51 ) ;
F_22 ( V_145 ) ;
}
static int F_52 ( struct V_50 * V_51 ,
struct V_146 * V_147 ,
unsigned int * V_148 )
{
struct V_57 * V_145 = F_27 ( V_51 ) ;
return F_53 ( V_147 , V_145 -> V_61 , V_148 ) ;
}
int
F_54 ( struct V_55 * V_29 ,
struct V_57 * V_149 ,
const struct V_150 * V_151 ,
struct V_60 * V_61 )
{
int V_83 ;
V_149 -> V_61 = V_61 ;
F_55 ( & V_149 -> V_19 , V_151 ) ;
V_83 = F_56 ( V_29 , & V_149 -> V_19 , & V_152 ) ;
if ( V_83 ) {
V_149 -> V_61 = NULL ;
return V_83 ;
}
return 0 ;
}
static struct V_50 *
F_57 ( struct V_55 * V_29 ,
struct V_146 * V_147 ,
const struct V_150 * V_151 )
{
struct V_60 * V_61 ;
struct V_57 * V_145 ;
int V_83 ;
V_61 = F_58 ( V_147 , V_151 -> V_153 [ 0 ] ) ;
if ( V_61 == NULL ) {
F_59 ( & V_29 -> V_154 -> V_29 , L_34
L_35 , V_151 -> V_153 [ 0 ] ) ;
return F_60 ( - V_155 ) ;
}
V_145 = F_25 ( sizeof( * V_145 ) , V_65 ) ;
if ( V_145 == NULL ) {
F_50 ( V_61 ) ;
return F_60 ( - V_66 ) ;
}
V_83 = F_54 ( V_29 , V_145 , V_151 , V_61 ) ;
if ( V_83 ) {
F_22 ( V_145 ) ;
F_50 ( V_61 ) ;
return F_60 ( V_83 ) ;
}
return & V_145 -> V_19 ;
}
static void F_61 ( struct V_55 * V_29 )
{
struct V_10 * V_11 = V_29 -> V_56 ;
F_62 ( V_11 ) ;
}
int F_63 ( struct V_10 * V_11 )
{
int V_156 ;
if ( V_11 -> V_157 ) {
V_11 -> V_14 . V_158 =
F_64 ( V_11 -> V_35 , 0 , L_36 , 0 , 1 ) ;
if ( ! V_11 -> V_14 . V_158 )
return - V_66 ;
}
V_11 -> V_14 . V_159 =
F_64 ( V_11 -> V_35 , 0 , L_37 , 0 , 1 ) ;
if ( ! V_11 -> V_14 . V_159 )
return - V_66 ;
F_65 ( V_11 -> V_35 ) ;
V_156 = F_66 ( V_160 ) ;
V_11 -> V_14 . V_161 =
F_67 ( V_11 -> V_35 , 0 ,
L_38 ,
V_160 , V_156 ) ;
V_11 -> V_14 . V_162 =
F_64 ( V_11 -> V_35 , 0 ,
L_39 , 0 , 128 ) ;
if ( ! V_11 -> V_14 . V_162 )
return - V_66 ;
V_11 -> V_14 . V_163 =
F_64 ( V_11 -> V_35 , 0 ,
L_40 , 0 , 128 ) ;
if ( ! V_11 -> V_14 . V_163 )
return - V_66 ;
V_156 = F_66 ( V_164 ) ;
V_11 -> V_14 . V_165 =
F_67 ( V_11 -> V_35 , 0 ,
L_41 ,
V_164 , V_156 ) ;
V_156 = F_66 ( V_166 ) ;
V_11 -> V_14 . V_167 =
F_67 ( V_11 -> V_35 , 0 ,
L_42 ,
V_166 , V_156 ) ;
return 0 ;
}
void F_68 ( struct V_10 * V_11 )
{
if ( ( V_168 == 0 ) || ( V_168 > 2 ) )
V_11 -> V_14 . V_169 = 0 ;
else
V_11 -> V_14 . V_169 = V_168 ;
}
static bool F_69 ( const struct V_170 * V_171 )
{
if ( ( V_171 -> V_172 == 480 && V_171 -> V_173 == 720 ) ||
( V_171 -> V_172 == 576 ) ||
( V_171 -> V_172 == 720 ) ||
( V_171 -> V_172 == 1080 ) )
return true ;
else
return false ;
}
bool F_70 ( struct V_17 * V_18 ,
const struct V_170 * V_171 ,
struct V_170 * V_174 )
{
struct V_55 * V_29 = V_18 -> V_29 ;
struct V_88 * V_89 ;
struct V_12 * V_12 = F_24 ( V_18 ) ;
struct V_90 * V_90 ;
struct V_85 * V_86 ;
struct V_87 * V_87 ;
T_4 V_175 = 1 , V_176 = 1 ;
T_4 V_177 = 1 , V_178 = 1 ;
V_12 -> V_179 = 0 ;
V_12 -> V_180 = 0 ;
F_38 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_89 -> V_18 != V_18 )
continue;
V_90 = F_44 ( V_89 ) ;
V_86 = F_71 ( V_89 ) ;
V_87 = F_43 ( V_86 ) ;
if ( V_90 -> V_181 == V_182 )
V_12 -> V_181 = V_182 ;
else if ( V_171 -> V_173 < V_90 -> V_183 . V_173 ||
V_171 -> V_172 < V_90 -> V_183 . V_172 )
V_12 -> V_181 = V_90 -> V_181 ;
else
V_12 -> V_181 = V_182 ;
memcpy ( & V_12 -> V_183 ,
& V_90 -> V_183 ,
sizeof( struct V_170 ) ) ;
V_175 = V_18 -> V_171 . V_172 ;
V_176 = V_12 -> V_183 . V_172 ;
V_177 = V_18 -> V_171 . V_173 ;
V_178 = V_12 -> V_183 . V_173 ;
if ( ( ! ( V_171 -> V_20 & V_184 ) ) &&
( ( V_90 -> V_185 == V_186 ) ||
( ( V_90 -> V_185 == V_187 ) &&
F_72 ( F_73 ( V_86 ) ) &&
F_69 ( V_171 ) ) ) ) {
if ( V_90 -> V_188 != 0 )
V_12 -> V_179 = V_90 -> V_188 ;
else
V_12 -> V_179 = ( V_171 -> V_173 >> 5 ) + 16 ;
if ( V_90 -> V_189 != 0 )
V_12 -> V_180 = V_90 -> V_189 ;
else
V_12 -> V_180 = ( V_171 -> V_172 >> 5 ) + 16 ;
V_12 -> V_181 = V_190 ;
V_175 = V_18 -> V_171 . V_172 ;
V_176 = V_18 -> V_171 . V_172 - ( V_12 -> V_180 * 2 ) ;
V_177 = V_18 -> V_171 . V_173 ;
V_178 = V_18 -> V_171 . V_173 - ( V_12 -> V_179 * 2 ) ;
}
}
if ( V_12 -> V_181 != V_182 ) {
T_5 V_191 , V_192 ;
V_191 . V_193 = F_74 ( V_175 ) ;
V_192 . V_193 = F_74 ( V_176 ) ;
V_12 -> V_194 . V_193 = F_75 ( V_191 , V_192 ) ;
V_191 . V_193 = F_74 ( V_177 ) ;
V_192 . V_193 = F_74 ( V_178 ) ;
V_12 -> V_195 . V_193 = F_75 ( V_191 , V_192 ) ;
} else {
V_12 -> V_194 . V_193 = F_74 ( 1 ) ;
V_12 -> V_195 . V_193 = F_74 ( 1 ) ;
}
return true ;
}
int F_9 ( struct V_55 * V_29 , unsigned int V_196 ,
unsigned int V_20 , int * V_23 , int * V_24 ,
T_6 * V_197 , T_6 * V_198 ,
const struct V_170 * V_171 )
{
T_4 V_199 = 0 , V_200 = 0 ;
int V_201 , V_202 , V_203 , V_83 = 0 ;
bool V_204 = true ;
struct V_10 * V_11 = V_29 -> V_56 ;
if ( V_197 )
* V_197 = F_76 () ;
if ( F_77 ( V_11 , V_196 , & V_199 , & V_200 ) == 0 )
V_83 |= V_38 ;
if ( V_198 )
* V_198 = F_76 () ;
* V_23 = V_200 & 0x1fff ;
* V_24 = ( V_200 >> 16 ) & 0x1fff ;
if ( V_199 > 0 ) {
V_83 |= V_39 ;
V_201 = V_199 & 0x1fff ;
V_202 = ( V_199 >> 16 ) & 0x1fff ;
}
else {
V_201 = V_171 -> V_205 ;
V_202 = 0 ;
}
if ( V_20 & V_36 ) {
* V_24 = * V_23 - V_201 ;
}
if ( ! ( V_20 & V_206 ) )
V_201 -= V_11 -> V_14 . V_15 [ V_196 ] -> V_207 ;
if ( ( * V_23 < V_201 ) && ( * V_23 >= V_202 ) )
V_204 = false ;
if ( V_204 )
V_83 |= V_208 ;
if ( V_20 & V_36 ) {
* V_23 -= V_201 ;
return V_83 ;
}
if ( V_204 && ( * V_23 >= V_201 ) ) {
V_203 = V_171 -> V_209 ;
* V_23 = * V_23 - V_203 ;
}
* V_23 = * V_23 - V_202 ;
return V_83 ;
}
int F_78 ( struct V_10 * V_11 , int V_18 )
{
if ( V_18 < 0 || V_18 >= V_11 -> V_14 . V_210 )
return V_211 ;
switch ( V_18 ) {
case 0 :
return V_212 ;
case 1 :
return V_213 ;
case 2 :
return V_214 ;
case 3 :
return V_215 ;
case 4 :
return V_216 ;
case 5 :
return V_217 ;
default:
return V_211 ;
}
}
