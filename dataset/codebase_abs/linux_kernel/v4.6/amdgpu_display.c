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
V_13 -> V_42 = V_43 ;
F_11 ( & V_18 -> V_29 -> V_33 , V_20 ) ;
V_11 -> V_14 . V_44 -> V_45 ( V_11 , V_6 -> V_16 , V_6 -> V_19 ) ;
}
static void F_14 ( struct V_8 * V_9 )
{
struct V_5 * V_6 =
F_2 ( V_9 , struct V_5 , V_46 ) ;
int V_47 ;
V_47 = F_15 ( V_6 -> V_48 , false ) ;
if ( F_16 ( V_47 == 0 ) ) {
V_47 = F_17 ( V_6 -> V_48 ) ;
if ( F_18 ( V_47 != 0 ) ) {
F_19 ( L_4 ) ;
}
F_20 ( V_6 -> V_48 ) ;
} else
F_19 ( L_5 ) ;
F_21 ( & V_6 -> V_48 ) ;
F_22 ( V_6 -> V_32 ) ;
F_22 ( V_6 ) ;
}
int F_23 ( struct V_17 * V_18 ,
struct V_49 * V_50 ,
struct V_51 * V_52 ,
T_1 V_53 )
{
struct V_54 * V_29 = V_18 -> V_29 ;
struct V_10 * V_11 = V_29 -> V_55 ;
struct V_12 * V_12 = F_24 ( V_18 ) ;
struct V_56 * V_57 ;
struct V_56 * V_58 ;
struct V_59 * V_60 ;
struct V_5 * V_6 ;
struct V_61 * V_62 ;
unsigned long V_20 ;
T_2 V_63 ;
T_2 V_19 ;
int V_21 , V_47 ;
V_6 = F_25 ( sizeof *V_6 , V_64 ) ;
if ( V_6 == NULL )
return - V_65 ;
F_26 ( & V_6 -> V_7 , F_7 ) ;
F_26 ( & V_6 -> V_46 , F_14 ) ;
V_6 -> V_52 = V_52 ;
V_6 -> V_11 = V_11 ;
V_6 -> V_16 = V_12 -> V_16 ;
V_57 = F_27 ( V_18 -> V_66 -> V_50 ) ;
V_60 = V_57 -> V_60 ;
V_6 -> V_48 = F_28 ( V_60 ) ;
F_29 ( V_6 -> V_48 ) ;
V_58 = F_27 ( V_50 ) ;
V_60 = V_58 -> V_60 ;
V_62 = F_28 ( V_60 ) ;
V_47 = F_15 ( V_62 , false ) ;
if ( F_18 ( V_47 != 0 ) ) {
F_19 ( L_6 ) ;
goto V_67;
}
V_47 = F_30 ( V_62 , V_68 , 0 , 0 , & V_19 ) ;
if ( F_18 ( V_47 != 0 ) ) {
F_20 ( V_62 ) ;
V_47 = - V_69 ;
F_19 ( L_7 ) ;
goto V_67;
}
V_47 = F_31 ( V_62 -> V_70 . V_71 , & V_6 -> V_30 ,
& V_6 -> V_31 ,
& V_6 -> V_32 ) ;
if ( F_18 ( V_47 != 0 ) ) {
F_20 ( V_62 ) ;
F_19 ( L_8 ) ;
goto V_67;
}
F_32 ( V_62 , & V_63 ) ;
F_20 ( V_62 ) ;
V_6 -> V_19 = V_19 ;
V_47 = F_33 ( V_18 -> V_29 , V_12 -> V_16 ) ;
if ( V_47 ) {
F_19 ( L_9 ) ;
goto V_72;
}
F_8 ( & V_18 -> V_29 -> V_33 , V_20 ) ;
if ( V_12 -> V_42 != V_73 ) {
F_13 ( L_10 ) ;
F_11 ( & V_18 -> V_29 -> V_33 , V_20 ) ;
V_47 = - V_74 ;
goto V_75;
}
V_12 -> V_42 = V_76 ;
V_12 -> V_77 = V_6 ;
V_18 -> V_66 -> V_50 = V_50 ;
F_11 ( & V_18 -> V_29 -> V_33 , V_20 ) ;
F_7 ( & V_6 -> V_7 ) ;
return 0 ;
V_75:
F_34 ( V_18 -> V_29 , V_12 -> V_16 ) ;
V_72:
if ( F_18 ( F_15 ( V_62 , false ) != 0 ) ) {
F_19 ( L_11 ) ;
goto V_67;
}
if ( F_18 ( F_17 ( V_62 ) != 0 ) ) {
F_19 ( L_12 ) ;
}
F_20 ( V_62 ) ;
V_67:
F_21 ( & V_6 -> V_48 ) ;
F_3 ( V_6 -> V_30 ) ;
for ( V_21 = 0 ; V_21 < V_6 -> V_31 ; ++ V_21 )
F_3 ( V_6 -> V_32 [ V_21 ] ) ;
F_22 ( V_6 -> V_32 ) ;
F_22 ( V_6 ) ;
return V_47 ;
}
int F_35 ( struct V_78 * V_79 )
{
struct V_54 * V_29 ;
struct V_10 * V_11 ;
struct V_17 * V_18 ;
bool V_80 = false ;
int V_81 ;
if ( ! V_79 || ! V_79 -> V_18 )
return - V_69 ;
V_29 = V_79 -> V_18 -> V_29 ;
V_81 = F_36 ( V_29 -> V_29 ) ;
if ( V_81 < 0 )
return V_81 ;
V_81 = F_37 ( V_79 ) ;
F_38 (crtc, &dev->mode_config.crtc_list, head)
if ( V_18 -> V_34 )
V_80 = true ;
F_39 ( V_29 -> V_29 ) ;
V_11 = V_29 -> V_55 ;
if ( V_80 && ! V_11 -> V_82 ) {
V_11 -> V_82 = true ;
return V_81 ;
}
if ( ! V_80 && V_11 -> V_82 ) {
F_40 ( V_29 -> V_29 ) ;
V_11 -> V_82 = false ;
}
F_40 ( V_29 -> V_29 ) ;
return V_81 ;
}
void F_41 ( struct V_54 * V_29 )
{
struct V_83 * V_84 ;
struct V_85 * V_85 ;
struct V_86 * V_87 ;
struct V_88 * V_88 ;
T_1 V_89 ;
int V_21 = 0 ;
F_42 ( L_13 ) ;
F_38 (connector, &dev->mode_config.connector_list, head) {
V_85 = F_43 ( V_84 ) ;
F_42 ( L_14 , V_21 ) ;
F_42 ( L_15 , V_84 -> V_90 ) ;
if ( V_85 -> V_91 . V_91 != V_92 )
F_42 ( L_15 , V_93 [ V_85 -> V_91 . V_91 ] ) ;
if ( V_85 -> V_94 ) {
F_42 ( L_16 ,
V_85 -> V_94 -> V_95 . V_96 ,
V_85 -> V_94 -> V_95 . V_97 ,
V_85 -> V_94 -> V_95 . V_98 ,
V_85 -> V_94 -> V_95 . V_99 ,
V_85 -> V_94 -> V_95 . V_100 ,
V_85 -> V_94 -> V_95 . V_101 ,
V_85 -> V_94 -> V_95 . V_102 ,
V_85 -> V_94 -> V_95 . V_103 ) ;
if ( V_85 -> V_104 . V_105 )
F_42 ( L_17 ,
V_85 -> V_104 . V_106 ,
V_85 -> V_104 . V_107 ) ;
if ( V_85 -> V_104 . V_108 )
F_42 ( L_18 ,
V_85 -> V_104 . V_109 ,
V_85 -> V_104 . V_110 ) ;
} else {
if ( V_84 -> V_111 == V_112 ||
V_84 -> V_111 == V_113 ||
V_84 -> V_111 == V_114 ||
V_84 -> V_111 == V_115 ||
V_84 -> V_111 == V_116 ||
V_84 -> V_111 == V_117 )
F_42 ( L_19 ) ;
}
F_42 ( L_20 ) ;
F_38 (encoder, &dev->mode_config.encoder_list, head) {
V_88 = F_44 ( V_87 ) ;
V_89 = V_88 -> V_89 & V_85 -> V_89 ;
if ( V_89 ) {
if ( V_89 & V_118 )
F_42 ( L_21 , V_119 [ V_88 -> V_120 ] ) ;
if ( V_89 & V_121 )
F_42 ( L_22 , V_119 [ V_88 -> V_120 ] ) ;
if ( V_89 & V_122 )
F_42 ( L_23 , V_119 [ V_88 -> V_120 ] ) ;
if ( V_89 & V_123 )
F_42 ( L_24 , V_119 [ V_88 -> V_120 ] ) ;
if ( V_89 & V_124 )
F_42 ( L_25 , V_119 [ V_88 -> V_120 ] ) ;
if ( V_89 & V_125 )
F_42 ( L_26 , V_119 [ V_88 -> V_120 ] ) ;
if ( V_89 & V_126 )
F_42 ( L_27 , V_119 [ V_88 -> V_120 ] ) ;
if ( V_89 & V_127 )
F_42 ( L_28 , V_119 [ V_88 -> V_120 ] ) ;
if ( V_89 & V_128 )
F_42 ( L_29 , V_119 [ V_88 -> V_120 ] ) ;
if ( V_89 & V_129 )
F_42 ( L_30 , V_119 [ V_88 -> V_120 ] ) ;
if ( V_89 & V_130 )
F_42 ( L_31 , V_119 [ V_88 -> V_120 ] ) ;
}
}
V_21 ++ ;
}
}
bool F_45 ( struct V_85 * V_85 ,
bool V_131 )
{
T_3 V_132 = 0x0 ;
T_3 V_133 [ 8 ] ;
int V_81 ;
struct V_134 V_135 [] = {
{
. V_136 = V_137 ,
. V_20 = 0 ,
. V_138 = 1 ,
. V_133 = & V_132 ,
} ,
{
. V_136 = V_137 ,
. V_20 = V_139 ,
. V_138 = 8 ,
. V_133 = V_133 ,
}
} ;
if ( V_85 -> V_104 . V_105 )
F_46 ( V_85 ) ;
if ( V_131 ) {
V_81 = F_47 ( & V_85 -> V_94 -> V_140 . V_141 , V_135 , 2 ) ;
} else {
V_81 = F_47 ( & V_85 -> V_94 -> V_142 , V_135 , 2 ) ;
}
if ( V_81 != 2 )
return false ;
if ( F_48 ( V_133 ) < 6 ) {
return false ;
}
return true ;
}
static void F_49 ( struct V_49 * V_50 )
{
struct V_56 * V_143 = F_27 ( V_50 ) ;
if ( V_143 -> V_60 ) {
F_50 ( V_143 -> V_60 ) ;
}
F_51 ( V_50 ) ;
F_22 ( V_143 ) ;
}
static int F_52 ( struct V_49 * V_50 ,
struct V_144 * V_145 ,
unsigned int * V_146 )
{
struct V_56 * V_143 = F_27 ( V_50 ) ;
return F_53 ( V_145 , V_143 -> V_60 , V_146 ) ;
}
int
F_54 ( struct V_54 * V_29 ,
struct V_56 * V_147 ,
const struct V_148 * V_149 ,
struct V_59 * V_60 )
{
int V_81 ;
V_147 -> V_60 = V_60 ;
F_55 ( & V_147 -> V_19 , V_149 ) ;
V_81 = F_56 ( V_29 , & V_147 -> V_19 , & V_150 ) ;
if ( V_81 ) {
V_147 -> V_60 = NULL ;
return V_81 ;
}
return 0 ;
}
static struct V_49 *
F_57 ( struct V_54 * V_29 ,
struct V_144 * V_145 ,
const struct V_148 * V_149 )
{
struct V_59 * V_60 ;
struct V_56 * V_143 ;
int V_81 ;
V_60 = F_58 ( V_29 , V_145 , V_149 -> V_151 [ 0 ] ) ;
if ( V_60 == NULL ) {
F_59 ( & V_29 -> V_152 -> V_29 , L_32
L_33 , V_149 -> V_151 [ 0 ] ) ;
return F_60 ( - V_153 ) ;
}
V_143 = F_25 ( sizeof( * V_143 ) , V_64 ) ;
if ( V_143 == NULL ) {
F_50 ( V_60 ) ;
return F_60 ( - V_65 ) ;
}
V_81 = F_54 ( V_29 , V_143 , V_149 , V_60 ) ;
if ( V_81 ) {
F_22 ( V_143 ) ;
F_50 ( V_60 ) ;
return F_60 ( V_81 ) ;
}
return & V_143 -> V_19 ;
}
static void F_61 ( struct V_54 * V_29 )
{
struct V_10 * V_11 = V_29 -> V_55 ;
F_62 ( V_11 ) ;
}
int F_63 ( struct V_10 * V_11 )
{
int V_154 ;
if ( V_11 -> V_155 ) {
V_11 -> V_14 . V_156 =
F_64 ( V_11 -> V_35 , 0 , L_34 , 0 , 1 ) ;
if ( ! V_11 -> V_14 . V_156 )
return - V_65 ;
}
V_11 -> V_14 . V_157 =
F_64 ( V_11 -> V_35 , 0 , L_35 , 0 , 1 ) ;
if ( ! V_11 -> V_14 . V_157 )
return - V_65 ;
F_65 ( V_11 -> V_35 ) ;
V_154 = F_66 ( V_158 ) ;
V_11 -> V_14 . V_159 =
F_67 ( V_11 -> V_35 , 0 ,
L_36 ,
V_158 , V_154 ) ;
V_11 -> V_14 . V_160 =
F_64 ( V_11 -> V_35 , 0 ,
L_37 , 0 , 128 ) ;
if ( ! V_11 -> V_14 . V_160 )
return - V_65 ;
V_11 -> V_14 . V_161 =
F_64 ( V_11 -> V_35 , 0 ,
L_38 , 0 , 128 ) ;
if ( ! V_11 -> V_14 . V_161 )
return - V_65 ;
V_154 = F_66 ( V_162 ) ;
V_11 -> V_14 . V_163 =
F_67 ( V_11 -> V_35 , 0 ,
L_39 ,
V_162 , V_154 ) ;
V_154 = F_66 ( V_164 ) ;
V_11 -> V_14 . V_165 =
F_67 ( V_11 -> V_35 , 0 ,
L_40 ,
V_164 , V_154 ) ;
return 0 ;
}
void F_68 ( struct V_10 * V_11 )
{
if ( ( V_166 == 0 ) || ( V_166 > 2 ) )
V_11 -> V_14 . V_167 = 0 ;
else
V_11 -> V_14 . V_167 = V_166 ;
}
static bool F_69 ( const struct V_168 * V_169 )
{
if ( ( V_169 -> V_170 == 480 && V_169 -> V_171 == 720 ) ||
( V_169 -> V_170 == 576 ) ||
( V_169 -> V_170 == 720 ) ||
( V_169 -> V_170 == 1080 ) )
return true ;
else
return false ;
}
bool F_70 ( struct V_17 * V_18 ,
const struct V_168 * V_169 ,
struct V_168 * V_172 )
{
struct V_54 * V_29 = V_18 -> V_29 ;
struct V_86 * V_87 ;
struct V_12 * V_12 = F_24 ( V_18 ) ;
struct V_88 * V_88 ;
struct V_83 * V_84 ;
struct V_85 * V_85 ;
T_4 V_173 = 1 , V_174 = 1 ;
T_4 V_175 = 1 , V_176 = 1 ;
V_12 -> V_177 = 0 ;
V_12 -> V_178 = 0 ;
F_38 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_87 -> V_18 != V_18 )
continue;
V_88 = F_44 ( V_87 ) ;
V_84 = F_71 ( V_87 ) ;
V_85 = F_43 ( V_84 ) ;
if ( V_88 -> V_179 == V_180 )
V_12 -> V_179 = V_180 ;
else if ( V_169 -> V_171 < V_88 -> V_181 . V_171 ||
V_169 -> V_170 < V_88 -> V_181 . V_170 )
V_12 -> V_179 = V_88 -> V_179 ;
else
V_12 -> V_179 = V_180 ;
memcpy ( & V_12 -> V_181 ,
& V_88 -> V_181 ,
sizeof( struct V_168 ) ) ;
V_173 = V_18 -> V_169 . V_170 ;
V_174 = V_12 -> V_181 . V_170 ;
V_175 = V_18 -> V_169 . V_171 ;
V_176 = V_12 -> V_181 . V_171 ;
if ( ( ! ( V_169 -> V_20 & V_182 ) ) &&
( ( V_88 -> V_183 == V_184 ) ||
( ( V_88 -> V_183 == V_185 ) &&
F_72 ( F_73 ( V_84 ) ) &&
F_69 ( V_169 ) ) ) ) {
if ( V_88 -> V_186 != 0 )
V_12 -> V_177 = V_88 -> V_186 ;
else
V_12 -> V_177 = ( V_169 -> V_171 >> 5 ) + 16 ;
if ( V_88 -> V_187 != 0 )
V_12 -> V_178 = V_88 -> V_187 ;
else
V_12 -> V_178 = ( V_169 -> V_170 >> 5 ) + 16 ;
V_12 -> V_179 = V_188 ;
V_173 = V_18 -> V_169 . V_170 ;
V_174 = V_18 -> V_169 . V_170 - ( V_12 -> V_178 * 2 ) ;
V_175 = V_18 -> V_169 . V_171 ;
V_176 = V_18 -> V_169 . V_171 - ( V_12 -> V_177 * 2 ) ;
}
}
if ( V_12 -> V_179 != V_180 ) {
T_5 V_189 , V_190 ;
V_189 . V_191 = F_74 ( V_173 ) ;
V_190 . V_191 = F_74 ( V_174 ) ;
V_12 -> V_192 . V_191 = F_75 ( V_189 , V_190 ) ;
V_189 . V_191 = F_74 ( V_175 ) ;
V_190 . V_191 = F_74 ( V_176 ) ;
V_12 -> V_193 . V_191 = F_75 ( V_189 , V_190 ) ;
} else {
V_12 -> V_192 . V_191 = F_74 ( 1 ) ;
V_12 -> V_193 . V_191 = F_74 ( 1 ) ;
}
return true ;
}
int F_9 ( struct V_54 * V_29 , unsigned int V_194 ,
unsigned int V_20 , int * V_23 , int * V_24 ,
T_6 * V_195 , T_6 * V_196 ,
const struct V_168 * V_169 )
{
T_4 V_197 = 0 , V_198 = 0 ;
int V_199 , V_200 , V_201 , V_81 = 0 ;
bool V_202 = true ;
struct V_10 * V_11 = V_29 -> V_55 ;
if ( V_195 )
* V_195 = F_76 () ;
if ( F_77 ( V_11 , V_194 , & V_197 , & V_198 ) == 0 )
V_81 |= V_38 ;
if ( V_196 )
* V_196 = F_76 () ;
* V_23 = V_198 & 0x1fff ;
* V_24 = ( V_198 >> 16 ) & 0x1fff ;
if ( V_197 > 0 ) {
V_81 |= V_39 ;
V_199 = V_197 & 0x1fff ;
V_200 = ( V_197 >> 16 ) & 0x1fff ;
}
else {
V_199 = V_169 -> V_203 ;
V_200 = 0 ;
}
if ( V_20 & V_36 ) {
* V_24 = * V_23 - V_199 ;
}
if ( ! ( V_20 & V_204 ) )
V_199 -= V_11 -> V_14 . V_15 [ V_194 ] -> V_205 ;
if ( ( * V_23 < V_199 ) && ( * V_23 >= V_200 ) )
V_202 = false ;
if ( V_202 )
V_81 |= V_206 ;
if ( V_20 & V_36 ) {
* V_23 -= V_199 ;
return V_81 ;
}
if ( V_202 && ( * V_23 >= V_199 ) ) {
V_201 = V_169 -> V_207 ;
* V_23 = * V_23 - V_201 ;
}
* V_23 = * V_23 - V_200 ;
return V_81 ;
}
int F_78 ( struct V_10 * V_11 , int V_18 )
{
if ( V_18 < 0 || V_18 >= V_11 -> V_14 . V_208 )
return V_209 ;
switch ( V_18 ) {
case 0 :
return V_210 ;
case 1 :
return V_211 ;
case 2 :
return V_212 ;
case 3 :
return V_213 ;
case 4 :
return V_214 ;
case 5 :
return V_215 ;
default:
return V_209 ;
}
}
