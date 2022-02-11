static int F_1 ( char * V_1 , const struct V_2 * V_3 )
{
int V_4 = * ( int * ) V_3 -> V_5 ;
if ( V_4 >= 0 )
return sprintf ( V_1 , L_1 , V_4 ) ;
else
return sprintf ( V_1 , L_2 ) ;
}
static int F_2 ( const char * V_6 , const struct V_2 * V_3 )
{
int V_4 , V_7 ;
if ( strncmp ( V_6 , L_2 , 3 ) != 0 ) {
V_7 = F_3 ( V_6 , 0 , & V_4 ) ;
if ( V_7 )
goto V_8;
} else {
V_4 = - 1 ;
}
if ( V_3 -> V_5 == & V_9 )
V_7 = F_4 ( V_4 , V_10 ,
V_11 ) ;
else if ( V_3 -> V_5 == & V_10 )
V_7 = F_4 ( V_9 , V_4 , V_11 ) ;
else
V_7 = F_4 ( V_9 , V_10 ,
V_4 ) ;
if ( V_7 )
goto V_8;
* ( int * ) V_3 -> V_5 = V_4 ;
V_8:
return V_7 ;
}
static inline struct V_12 * F_5 ( struct V_13 * V_14 )
{
return (struct V_12 * ) V_14 -> V_15 ;
}
static const char * F_6 ( struct V_13 * V_14 )
{
return F_5 ( V_14 ) -> V_16 ;
}
static int F_7 ( struct V_12 * V_17 )
{
static const T_1 V_18 [ 3 ] = { 0x00 , 0x05 , 0xad } ;
static const T_1 V_19 [ 3 ] = { 0x00 , 0x1b , 0x0d } ;
return V_20 &&
( ! memcmp ( & V_17 -> V_21 , V_18 , sizeof V_18 ) ||
! memcmp ( & V_17 -> V_21 , V_19 , sizeof V_19 ) ) ;
}
static struct V_22 * F_8 ( struct V_23 * V_14 , T_2 V_24 ,
T_3 V_25 ,
enum V_26 V_27 )
{
struct V_22 * V_28 ;
V_28 = F_9 ( sizeof *V_28 , V_25 ) ;
if ( ! V_28 )
goto V_8;
V_28 -> V_29 = F_10 ( V_24 , V_25 ) ;
if ( ! V_28 -> V_29 )
goto V_30;
V_28 -> V_31 = F_11 ( V_14 -> V_32 -> V_33 , V_28 -> V_29 , V_24 ,
V_27 ) ;
if ( F_12 ( V_14 -> V_32 -> V_33 , V_28 -> V_31 ) )
goto V_34;
V_28 -> V_24 = V_24 ;
V_28 -> V_27 = V_27 ;
return V_28 ;
V_34:
F_13 ( V_28 -> V_29 ) ;
V_30:
F_13 ( V_28 ) ;
V_8:
return NULL ;
}
static void F_14 ( struct V_23 * V_14 , struct V_22 * V_28 )
{
if ( ! V_28 )
return;
F_15 ( V_14 -> V_32 -> V_33 , V_28 -> V_31 , V_28 -> V_24 ,
V_28 -> V_27 ) ;
F_13 ( V_28 -> V_29 ) ;
F_13 ( V_28 ) ;
}
static void F_16 ( struct V_35 * V_36 , void * V_37 )
{
F_17 ( L_3 , V_36 -> V_36 ) ;
}
static int F_18 ( struct V_12 * V_17 ,
struct V_38 * V_39 )
{
struct V_40 * V_41 ;
int V_42 ;
V_41 = F_9 ( sizeof *V_41 , V_43 ) ;
if ( ! V_41 )
return - V_44 ;
V_42 = F_19 ( V_17 -> V_23 -> V_32 -> V_33 ,
V_17 -> V_23 -> V_45 ,
F_20 ( V_17 -> V_46 . V_47 ) ,
& V_41 -> V_48 ) ;
if ( V_42 )
goto V_8;
V_41 -> V_49 = V_50 ;
V_41 -> V_51 = ( V_52 |
V_53 ) ;
V_41 -> V_54 = V_17 -> V_23 -> V_45 ;
V_42 = F_21 ( V_39 , V_41 ,
V_55 |
V_56 |
V_57 |
V_58 ) ;
V_8:
F_13 ( V_41 ) ;
return V_42 ;
}
static int F_22 ( struct V_12 * V_17 )
{
struct V_59 * V_60 ;
V_60 = F_23 ( V_17 -> V_23 -> V_32 -> V_33 ,
V_61 , V_17 ) ;
if ( F_24 ( V_60 ) )
return F_25 ( V_60 ) ;
if ( V_17 -> V_62 )
F_26 ( V_17 -> V_62 ) ;
V_17 -> V_62 = V_60 ;
return 0 ;
}
static int F_27 ( struct V_12 * V_17 )
{
struct V_63 * V_64 ;
struct V_65 * V_66 , * V_67 ;
struct V_38 * V_39 ;
int V_42 ;
V_64 = F_10 ( sizeof *V_64 , V_43 ) ;
if ( ! V_64 )
return - V_44 ;
V_66 = F_28 ( V_17 -> V_23 -> V_32 -> V_33 ,
V_68 , NULL , V_17 ,
V_17 -> V_69 , V_17 -> V_70 ) ;
if ( F_24 ( V_66 ) ) {
V_42 = F_25 ( V_66 ) ;
goto V_71;
}
V_67 = F_28 ( V_17 -> V_23 -> V_32 -> V_33 ,
V_72 , NULL , V_17 ,
V_17 -> V_69 , V_17 -> V_70 ) ;
if ( F_24 ( V_67 ) ) {
V_42 = F_25 ( V_67 ) ;
goto V_73;
}
F_29 ( V_66 , V_74 ) ;
V_64 -> V_75 = F_16 ;
V_64 -> V_76 . V_77 = V_17 -> V_69 ;
V_64 -> V_76 . V_78 = V_17 -> V_69 ;
V_64 -> V_76 . V_79 = 1 ;
V_64 -> V_76 . V_80 = 1 ;
V_64 -> V_81 = V_82 ;
V_64 -> V_83 = V_84 ;
V_64 -> V_67 = V_67 ;
V_64 -> V_66 = V_66 ;
V_39 = F_30 ( V_17 -> V_23 -> V_32 -> V_85 , V_64 ) ;
if ( F_24 ( V_39 ) ) {
V_42 = F_25 ( V_39 ) ;
goto V_86;
}
V_42 = F_18 ( V_17 , V_39 ) ;
if ( V_42 )
goto V_87;
if ( V_17 -> V_39 )
F_31 ( V_17 -> V_39 ) ;
if ( V_17 -> V_66 )
F_32 ( V_17 -> V_66 ) ;
if ( V_17 -> V_67 )
F_32 ( V_17 -> V_67 ) ;
V_17 -> V_39 = V_39 ;
V_17 -> V_66 = V_66 ;
V_17 -> V_67 = V_67 ;
F_13 ( V_64 ) ;
return 0 ;
V_87:
F_31 ( V_39 ) ;
V_86:
F_32 ( V_67 ) ;
V_73:
F_32 ( V_66 ) ;
V_71:
F_13 ( V_64 ) ;
return V_42 ;
}
static void F_33 ( struct V_12 * V_17 )
{
int V_88 ;
F_31 ( V_17 -> V_39 ) ;
F_32 ( V_17 -> V_67 ) ;
F_32 ( V_17 -> V_66 ) ;
V_17 -> V_39 = NULL ;
V_17 -> V_67 = V_17 -> V_66 = NULL ;
if ( V_17 -> V_89 ) {
for ( V_88 = 0 ; V_88 < V_17 -> V_69 ; ++ V_88 )
F_14 ( V_17 -> V_23 , V_17 -> V_89 [ V_88 ] ) ;
F_13 ( V_17 -> V_89 ) ;
V_17 -> V_89 = NULL ;
}
if ( V_17 -> V_90 ) {
for ( V_88 = 0 ; V_88 < V_17 -> V_69 ; ++ V_88 )
F_14 ( V_17 -> V_23 , V_17 -> V_90 [ V_88 ] ) ;
F_13 ( V_17 -> V_90 ) ;
V_17 -> V_90 = NULL ;
}
}
static void F_34 ( int V_91 ,
struct V_92 * V_93 ,
void * V_94 )
{
struct V_12 * V_17 = V_94 ;
V_17 -> V_91 = V_91 ;
if ( V_91 )
F_35 ( V_95 , V_17 -> V_96 ,
V_97 L_4 , V_91 ) ;
else
V_17 -> V_46 = * V_93 ;
F_36 ( & V_17 -> V_98 ) ;
}
static int F_37 ( struct V_12 * V_17 )
{
int V_42 ;
V_17 -> V_46 . V_99 = 1 ;
F_38 ( & V_17 -> V_98 ) ;
V_17 -> V_100 = F_39 ( & V_101 ,
V_17 -> V_23 -> V_32 -> V_33 ,
V_17 -> V_23 -> V_45 ,
& V_17 -> V_46 ,
V_102 |
V_103 |
V_104 |
V_105 |
V_106 ,
V_107 ,
V_43 ,
F_34 ,
V_17 , & V_17 -> V_108 ) ;
if ( V_17 -> V_100 < 0 )
return V_17 -> V_100 ;
V_42 = F_40 ( & V_17 -> V_98 ) ;
if ( V_42 < 0 )
return V_42 ;
if ( V_17 -> V_91 < 0 )
F_35 ( V_109 , V_17 -> V_96 ,
V_97 L_5 ) ;
return V_17 -> V_91 ;
}
static int F_41 ( struct V_12 * V_17 )
{
struct {
struct V_110 V_111 ;
struct V_112 V_113 ;
} * V_114 = NULL ;
int V_91 ;
V_114 = F_10 ( sizeof *V_114 , V_43 ) ;
if ( ! V_114 )
return - V_44 ;
V_114 -> V_111 . V_115 = & V_17 -> V_46 ;
V_114 -> V_111 . V_116 = NULL ;
V_114 -> V_111 . V_117 = V_17 -> V_117 ;
V_114 -> V_111 . V_118 = V_17 -> V_39 -> V_118 ;
V_114 -> V_111 . V_83 = V_17 -> V_39 -> V_83 ;
V_114 -> V_111 . V_119 = & V_114 -> V_113 ;
V_114 -> V_111 . V_120 = sizeof V_114 -> V_113 ;
V_114 -> V_111 . V_121 = 1 ;
F_42 ( & V_114 -> V_111 . V_122 , 4 ) ;
V_114 -> V_111 . V_122 &= 0xffffff ;
V_114 -> V_111 . V_123 = 4 ;
V_114 -> V_111 . V_124 = 20 ;
V_114 -> V_111 . V_125 = 20 ;
V_114 -> V_111 . V_126 = V_17 -> V_127 ;
V_114 -> V_111 . V_128 = 7 ;
V_114 -> V_111 . V_129 = 15 ;
V_114 -> V_113 . V_130 = V_131 ;
V_114 -> V_113 . V_132 = 0 ;
V_114 -> V_113 . V_133 = F_43 ( V_17 -> V_134 ) ;
V_114 -> V_113 . V_135 = F_44 ( V_136 |
V_137 ) ;
if ( V_17 -> V_138 == V_139 ) {
memcpy ( V_114 -> V_113 . V_140 ,
& V_17 -> V_46 . V_141 . V_142 . V_143 , 8 ) ;
memcpy ( V_114 -> V_113 . V_140 + 8 ,
& V_17 -> V_144 , 8 ) ;
memcpy ( V_114 -> V_113 . V_145 , & V_17 -> V_21 , 8 ) ;
memcpy ( V_114 -> V_113 . V_145 + 8 , & V_17 -> V_146 , 8 ) ;
} else {
memcpy ( V_114 -> V_113 . V_140 ,
& V_17 -> V_144 , 8 ) ;
memcpy ( V_114 -> V_113 . V_140 + 8 ,
& V_17 -> V_46 . V_141 . V_142 . V_143 , 8 ) ;
memcpy ( V_114 -> V_113 . V_145 , & V_17 -> V_146 , 8 ) ;
memcpy ( V_114 -> V_113 . V_145 + 8 , & V_17 -> V_21 , 8 ) ;
}
if ( F_7 ( V_17 ) ) {
F_35 ( V_147 , V_17 -> V_96 ,
V_97 L_6
L_7 ,
( unsigned long long ) F_45 ( V_17 -> V_21 ) ) ;
memset ( V_114 -> V_113 . V_140 , 0 , 8 ) ;
memcpy ( V_114 -> V_113 . V_140 + 8 ,
& V_17 -> V_23 -> V_32 -> V_33 -> V_148 , 8 ) ;
}
V_91 = F_46 ( V_17 -> V_62 , & V_114 -> V_111 ) ;
F_13 ( V_114 ) ;
return V_91 ;
}
static bool F_47 ( struct V_12 * V_17 )
{
bool V_149 = false ;
F_48 ( & V_17 -> V_150 ) ;
if ( V_17 -> V_151 != V_152 ) {
V_17 -> V_151 = V_152 ;
V_149 = true ;
}
F_49 ( & V_17 -> V_150 ) ;
if ( V_149 )
F_50 ( V_153 , & V_17 -> V_154 ) ;
return V_149 ;
}
static bool F_51 ( struct V_12 * V_17 ,
bool V_155 )
{
bool V_149 = false ;
F_48 ( & V_17 -> V_150 ) ;
if ( V_17 -> V_155 != V_155 ) {
V_17 -> V_155 = V_155 ;
V_149 = true ;
}
F_49 ( & V_17 -> V_150 ) ;
return V_149 ;
}
static void F_52 ( struct V_12 * V_17 )
{
if ( F_51 ( V_17 , false ) ) {
if ( F_53 ( V_17 -> V_62 , NULL , 0 ) ) {
F_35 ( V_147 , V_17 -> V_96 ,
V_97 L_8 ) ;
}
}
}
static void F_54 ( struct V_12 * V_17 )
{
struct V_156 * V_157 = V_17 -> V_23 -> V_32 -> V_33 ;
struct V_158 * V_114 ;
int V_88 ;
if ( ! V_17 -> V_159 )
return;
for ( V_88 = 0 ; V_88 < V_17 -> V_160 ; ++ V_88 ) {
V_114 = & V_17 -> V_159 [ V_88 ] ;
F_13 ( V_114 -> V_161 ) ;
F_13 ( V_114 -> V_162 ) ;
if ( V_114 -> V_163 ) {
F_15 ( V_157 , V_114 -> V_163 ,
V_17 -> V_164 ,
V_165 ) ;
}
F_13 ( V_114 -> V_166 ) ;
}
F_13 ( V_17 -> V_159 ) ;
V_17 -> V_159 = NULL ;
}
static int F_55 ( struct V_12 * V_17 )
{
struct V_167 * V_32 = V_17 -> V_23 -> V_32 ;
struct V_156 * V_157 = V_32 -> V_33 ;
struct V_158 * V_114 ;
T_4 V_168 ;
int V_88 , V_42 = - V_44 ;
F_56 ( & V_17 -> V_169 ) ;
V_17 -> V_159 = F_10 ( V_17 -> V_160 *
sizeof( * V_17 -> V_159 ) , V_43 ) ;
if ( ! V_17 -> V_159 )
goto V_8;
for ( V_88 = 0 ; V_88 < V_17 -> V_160 ; ++ V_88 ) {
V_114 = & V_17 -> V_159 [ V_88 ] ;
V_114 -> V_161 = F_9 ( V_17 -> V_170 * sizeof( void * ) ,
V_43 ) ;
V_114 -> V_162 = F_9 ( V_171 * sizeof( void * ) ,
V_43 ) ;
V_114 -> V_166 = F_9 ( V_17 -> V_164 , V_43 ) ;
if ( ! V_114 -> V_161 || ! V_114 -> V_162 || ! V_114 -> V_166 )
goto V_8;
V_168 = F_11 ( V_157 , V_114 -> V_166 ,
V_17 -> V_164 ,
V_165 ) ;
if ( F_12 ( V_157 , V_168 ) )
goto V_8;
V_114 -> V_163 = V_168 ;
V_114 -> V_172 = V_88 ;
F_57 ( & V_114 -> V_173 , & V_17 -> V_169 ) ;
}
V_42 = 0 ;
V_8:
return V_42 ;
}
static void F_58 ( struct V_13 * V_174 )
{
struct V_175 * * V_41 ;
for ( V_41 = V_174 -> V_176 -> V_177 ; V_41 && * V_41 ; ++ V_41 )
F_59 ( & V_174 -> V_178 , * V_41 ) ;
}
static void F_60 ( struct V_12 * V_17 )
{
F_61 ( V_17 -> V_151 != V_152 ) ;
F_58 ( V_17 -> V_96 ) ;
F_62 ( V_17 -> V_179 ) ;
F_63 ( V_17 -> V_96 ) ;
F_64 ( V_17 -> V_96 ) ;
F_65 ( V_17 -> V_179 ) ;
F_52 ( V_17 ) ;
F_26 ( V_17 -> V_62 ) ;
F_33 ( V_17 ) ;
F_66 ( & V_17 -> V_180 ) ;
F_67 ( V_17 -> V_179 ) ;
F_54 ( V_17 ) ;
F_68 ( & V_17 -> V_23 -> V_181 ) ;
F_69 ( & V_17 -> V_173 ) ;
F_70 ( & V_17 -> V_23 -> V_181 ) ;
F_71 ( V_17 -> V_96 ) ;
}
static void F_72 ( struct V_182 * V_183 )
{
struct V_12 * V_17 =
F_73 ( V_183 , struct V_12 , V_154 ) ;
F_61 ( V_17 -> V_151 != V_152 ) ;
F_60 ( V_17 ) ;
}
static void F_74 ( struct V_184 * V_179 )
{
struct V_12 * V_17 = V_179 -> V_185 ;
F_47 ( V_17 ) ;
}
static int F_75 ( struct V_12 * V_17 )
{
int V_186 = 3 ;
int V_42 ;
F_61 ( V_17 -> V_155 ) ;
V_17 -> V_187 = false ;
V_42 = F_37 ( V_17 ) ;
if ( V_42 )
return V_42 ;
while ( 1 ) {
F_38 ( & V_17 -> V_98 ) ;
V_42 = F_41 ( V_17 ) ;
if ( V_42 )
return V_42 ;
V_42 = F_40 ( & V_17 -> V_98 ) ;
if ( V_42 < 0 )
return V_42 ;
switch ( V_17 -> V_91 ) {
case 0 :
F_51 ( V_17 , true ) ;
return 0 ;
case V_188 :
V_42 = F_37 ( V_17 ) ;
if ( V_42 )
return V_42 ;
break;
case V_189 :
break;
case V_190 :
if ( ! V_186 -- || F_22 ( V_17 ) ) {
F_35 ( V_95 , V_17 -> V_96 , V_97
L_9 ) ;
V_17 -> V_91 = - V_191 ;
return V_17 -> V_91 ;
}
F_35 ( V_95 , V_17 -> V_96 , V_97
L_10 ) ;
break;
default:
return V_17 -> V_91 ;
}
}
}
static void F_76 ( struct V_192 * V_193 ,
struct V_12 * V_17 ,
struct V_158 * V_114 )
{
struct V_156 * V_157 = V_17 -> V_23 -> V_32 -> V_33 ;
struct V_194 * * V_195 ;
if ( ! F_77 ( V_193 ) ||
( V_193 -> V_196 != V_165 &&
V_193 -> V_196 != V_197 ) )
return;
V_195 = V_114 -> V_161 ;
while ( V_114 -> V_198 -- )
F_78 ( * V_195 ++ ) ;
F_79 ( V_157 , F_77 ( V_193 ) , F_80 ( V_193 ) ,
V_193 -> V_196 ) ;
}
static struct V_192 * F_81 ( struct V_12 * V_17 ,
struct V_158 * V_114 ,
struct V_199 * V_200 ,
struct V_192 * V_193 )
{
unsigned long V_201 ;
F_82 ( & V_17 -> V_150 , V_201 ) ;
if ( V_114 -> V_193 &&
( ! V_200 || V_114 -> V_193 -> V_202 == V_200 ) &&
( ! V_193 || V_114 -> V_193 == V_193 ) ) {
V_193 = V_114 -> V_193 ;
V_114 -> V_193 = NULL ;
} else {
V_193 = NULL ;
}
F_83 ( & V_17 -> V_150 , V_201 ) ;
return V_193 ;
}
static void F_84 ( struct V_12 * V_17 ,
struct V_158 * V_114 , struct V_192 * V_193 ,
T_5 V_203 )
{
unsigned long V_201 ;
F_76 ( V_193 , V_17 , V_114 ) ;
F_82 ( & V_17 -> V_150 , V_201 ) ;
V_17 -> V_204 += V_203 ;
F_57 ( & V_114 -> V_173 , & V_17 -> V_169 ) ;
F_83 ( & V_17 -> V_150 , V_201 ) ;
}
static void F_85 ( struct V_12 * V_17 ,
struct V_158 * V_114 , struct V_199 * V_200 ,
int V_205 )
{
struct V_192 * V_193 = F_81 ( V_17 , V_114 , V_200 , NULL ) ;
if ( V_193 ) {
F_84 ( V_17 , V_114 , V_193 , 0 ) ;
V_193 -> V_205 = V_205 ;
V_193 -> V_206 ( V_193 ) ;
}
}
static void F_86 ( struct V_184 * V_179 )
{
struct V_12 * V_17 = V_179 -> V_185 ;
struct V_13 * V_174 = V_17 -> V_96 ;
struct V_199 * V_200 ;
int V_88 ;
F_87 (sdev, shost)
F_61 ( V_200 -> V_207 -> V_208 ) ;
for ( V_88 = 0 ; V_88 < V_17 -> V_160 ; ++ V_88 ) {
struct V_158 * V_114 = & V_17 -> V_159 [ V_88 ] ;
F_85 ( V_17 , V_114 , NULL , V_209 << 16 ) ;
}
}
static int F_88 ( struct V_184 * V_179 )
{
struct V_12 * V_17 = V_179 -> V_185 ;
int V_88 , V_42 ;
F_52 ( V_17 ) ;
V_42 = F_22 ( V_17 ) ;
if ( V_42 == 0 )
V_42 = F_27 ( V_17 ) ;
else
F_27 ( V_17 ) ;
for ( V_88 = 0 ; V_88 < V_17 -> V_160 ; ++ V_88 ) {
struct V_158 * V_114 = & V_17 -> V_159 [ V_88 ] ;
F_85 ( V_17 , V_114 , NULL , V_210 << 16 ) ;
}
F_56 ( & V_17 -> V_211 ) ;
for ( V_88 = 0 ; V_88 < V_17 -> V_69 ; ++ V_88 )
F_89 ( & V_17 -> V_90 [ V_88 ] -> V_173 , & V_17 -> V_211 ) ;
if ( V_42 == 0 )
V_42 = F_75 ( V_17 ) ;
if ( V_42 == 0 )
F_35 ( V_212 , V_17 -> V_96 ,
V_97 L_11 ) ;
return V_42 ;
}
static void F_90 ( struct V_213 * V_151 , T_4 V_168 ,
unsigned int V_214 , T_6 V_215 )
{
struct V_216 * V_217 = V_151 -> V_217 ;
V_217 -> V_218 = F_91 ( V_168 ) ;
V_217 -> V_219 = F_43 ( V_215 ) ;
V_217 -> V_220 = F_43 ( V_214 ) ;
V_151 -> V_221 += V_214 ;
V_151 -> V_217 ++ ;
V_151 -> V_222 ++ ;
}
static int F_92 ( struct V_213 * V_151 ,
struct V_12 * V_17 )
{
struct V_167 * V_33 = V_17 -> V_23 -> V_32 ;
struct V_194 * V_223 ;
T_7 V_224 = 0 ;
if ( ! V_151 -> V_225 )
return 0 ;
if ( V_151 -> V_225 == 1 ) {
F_90 ( V_151 , V_151 -> V_226 , V_151 -> V_227 ,
V_17 -> V_215 ) ;
V_151 -> V_225 = V_151 -> V_227 = 0 ;
return 0 ;
}
V_223 = F_93 ( V_33 -> V_228 , V_151 -> V_229 ,
V_151 -> V_225 , V_224 ) ;
if ( F_24 ( V_223 ) )
return F_25 ( V_223 ) ;
* V_151 -> V_230 ++ = V_223 ;
V_151 -> V_198 ++ ;
F_90 ( V_151 , 0 , V_151 -> V_227 , V_223 -> V_223 -> V_215 ) ;
V_151 -> V_225 = V_151 -> V_227 = 0 ;
return 0 ;
}
static void F_94 ( struct V_213 * V_151 ,
struct V_231 * V_232 , int V_233 ,
T_4 V_168 )
{
V_151 -> V_234 = V_232 ;
V_151 -> V_235 = V_233 ;
V_151 -> V_236 = V_168 ;
}
static int F_95 ( struct V_213 * V_151 ,
struct V_12 * V_17 ,
struct V_231 * V_232 , int V_233 ,
int V_237 )
{
struct V_167 * V_33 = V_17 -> V_23 -> V_32 ;
struct V_156 * V_157 = V_33 -> V_33 ;
T_4 V_168 = F_96 ( V_157 , V_232 ) ;
unsigned int V_214 = F_97 ( V_157 , V_232 ) ;
unsigned int V_220 ;
int V_42 ;
if ( ! V_214 )
return 0 ;
if ( V_237 == V_238 ) {
F_90 ( V_151 , V_168 , V_214 , V_17 -> V_215 ) ;
return 0 ;
}
if ( V_168 & ~ V_33 -> V_239 || V_214 > V_33 -> V_240 ) {
V_42 = F_92 ( V_151 , V_17 ) ;
if ( V_42 )
return V_42 ;
F_90 ( V_151 , V_168 , V_214 , V_17 -> V_215 ) ;
F_94 ( V_151 , NULL , 0 , 0 ) ;
return 0 ;
}
if ( ! V_151 -> V_234 )
F_94 ( V_151 , V_232 , V_233 , V_168 ) ;
while ( V_214 ) {
if ( V_151 -> V_225 == V_171 ) {
V_42 = F_92 ( V_151 , V_17 ) ;
if ( V_42 )
return V_42 ;
F_94 ( V_151 , V_232 , V_233 , V_168 ) ;
}
V_220 = F_98 (unsigned int, dma_len, dev->fmr_page_size) ;
if ( ! V_151 -> V_225 )
V_151 -> V_226 = V_168 ;
V_151 -> V_229 [ V_151 -> V_225 ++ ] = V_168 ;
V_151 -> V_227 += V_220 ;
V_168 += V_220 ;
V_214 -= V_220 ;
}
V_42 = 0 ;
if ( V_220 != V_33 -> V_241 ) {
V_42 = F_92 ( V_151 , V_17 ) ;
if ( ! V_42 )
F_94 ( V_151 , NULL , 0 , 0 ) ;
}
return V_42 ;
}
static int F_99 ( struct V_192 * V_193 , struct V_12 * V_17 ,
struct V_158 * V_114 )
{
struct V_231 * V_242 , * V_232 ;
struct V_243 * V_244 = V_114 -> V_244 -> V_29 ;
int V_88 , V_220 , V_245 , V_246 , V_237 ;
struct V_167 * V_33 ;
struct V_156 * V_157 ;
struct V_213 V_151 ;
struct V_247 * V_248 ;
T_6 V_249 ;
T_1 V_250 ;
if ( ! F_77 ( V_193 ) || V_193 -> V_196 == V_251 )
return sizeof ( struct V_243 ) ;
if ( V_193 -> V_196 != V_197 &&
V_193 -> V_196 != V_165 ) {
F_35 ( V_109 , V_17 -> V_96 ,
V_97 L_12 ,
V_193 -> V_196 ) ;
return - V_252 ;
}
V_245 = F_80 ( V_193 ) ;
V_242 = F_77 ( V_193 ) ;
V_33 = V_17 -> V_23 -> V_32 ;
V_157 = V_33 -> V_33 ;
V_246 = F_100 ( V_157 , V_242 , V_245 , V_193 -> V_196 ) ;
if ( F_101 ( V_246 == 0 ) )
return - V_253 ;
V_250 = V_254 ;
V_220 = sizeof ( struct V_243 ) + sizeof ( struct V_216 ) ;
if ( V_246 == 1 ) {
struct V_216 * V_29 = ( void * ) V_244 -> V_255 ;
V_29 -> V_218 = F_91 ( F_96 ( V_157 , V_242 ) ) ;
V_29 -> V_219 = F_43 ( V_17 -> V_215 ) ;
V_29 -> V_220 = F_43 ( F_97 ( V_157 , V_242 ) ) ;
V_114 -> V_198 = 0 ;
goto V_256;
}
V_248 = ( void * ) V_244 -> V_255 ;
F_102 ( V_157 , V_114 -> V_163 ,
V_17 -> V_164 , V_165 ) ;
memset ( & V_151 , 0 , sizeof( V_151 ) ) ;
V_151 . V_217 = V_114 -> V_166 ;
V_151 . V_229 = V_114 -> V_162 ;
V_151 . V_230 = V_114 -> V_161 ;
V_237 = V_33 -> V_228 ? V_257 : V_238 ;
F_103 (scat, sg, count, i) {
if ( F_95 ( & V_151 , V_17 , V_232 , V_88 , V_237 ) ) {
T_4 V_168 ;
unsigned int V_214 ;
V_258:
V_232 = V_151 . V_234 ;
V_88 = V_151 . V_235 ;
V_168 = F_96 ( V_157 , V_232 ) ;
V_214 = F_97 ( V_157 , V_232 ) ;
V_214 -= ( V_151 . V_236 - V_168 ) ;
V_168 = V_151 . V_236 ;
V_237 = V_238 ;
F_90 ( & V_151 , V_168 , V_214 , V_17 -> V_215 ) ;
}
}
if ( V_237 == V_257 && F_92 ( & V_151 , V_17 ) )
goto V_258;
V_114 -> V_198 = V_151 . V_198 ;
if ( V_151 . V_222 == 1 ) {
struct V_216 * V_29 = ( void * ) V_244 -> V_255 ;
* V_29 = V_114 -> V_166 [ 0 ] ;
goto V_256;
}
if ( F_101 ( V_17 -> V_170 < V_151 . V_222 &&
! V_17 -> V_259 ) ) {
F_35 ( V_95 , V_17 -> V_96 ,
L_13 ) ;
return - V_253 ;
}
V_246 = F_104 ( V_151 . V_222 , V_17 -> V_170 ) ;
V_249 = V_151 . V_222 * sizeof ( struct V_216 ) ;
V_250 = V_260 ;
V_220 = sizeof( struct V_243 ) + sizeof ( struct V_247 ) ;
V_220 += V_246 * sizeof ( struct V_216 ) ;
memcpy ( V_248 -> V_261 , V_114 -> V_166 ,
V_246 * sizeof ( struct V_216 ) ) ;
V_248 -> V_262 . V_218 = F_91 ( V_114 -> V_163 ) ;
V_248 -> V_262 . V_219 = F_43 ( V_17 -> V_215 ) ;
V_248 -> V_262 . V_220 = F_43 ( V_249 ) ;
V_248 -> V_220 = F_43 ( V_151 . V_221 ) ;
if ( V_193 -> V_196 == V_165 )
V_244 -> V_263 = V_246 ;
else
V_244 -> V_264 = V_246 ;
F_105 ( V_157 , V_114 -> V_163 , V_249 ,
V_165 ) ;
V_256:
if ( V_193 -> V_196 == V_165 )
V_244 -> V_265 = V_250 << 4 ;
else
V_244 -> V_265 = V_250 ;
return V_220 ;
}
static void F_106 ( struct V_12 * V_17 , struct V_22 * V_28 ,
enum V_266 V_267 )
{
unsigned long V_201 ;
F_82 ( & V_17 -> V_150 , V_201 ) ;
F_89 ( & V_28 -> V_173 , & V_17 -> V_211 ) ;
if ( V_267 != V_268 )
++ V_17 -> V_204 ;
F_83 ( & V_17 -> V_150 , V_201 ) ;
}
static struct V_22 * F_107 ( struct V_12 * V_17 ,
enum V_266 V_267 )
{
T_5 V_269 = ( V_267 == V_270 ) ? 0 : V_271 ;
struct V_22 * V_28 ;
V_72 ( V_17 -> V_67 , V_17 ) ;
if ( F_108 ( & V_17 -> V_211 ) )
return NULL ;
if ( V_267 != V_268 ) {
if ( V_17 -> V_204 <= V_269 ) {
++ V_17 -> V_272 ;
return NULL ;
}
-- V_17 -> V_204 ;
}
V_28 = F_109 ( & V_17 -> V_211 , struct V_22 , V_173 ) ;
F_69 ( & V_28 -> V_173 ) ;
return V_28 ;
}
static int F_110 ( struct V_12 * V_17 ,
struct V_22 * V_28 , int V_220 )
{
struct V_273 V_173 ;
struct V_274 V_275 , * V_276 ;
V_173 . V_277 = V_28 -> V_31 ;
V_173 . V_278 = V_220 ;
V_173 . V_279 = V_17 -> V_279 ;
V_275 . V_280 = NULL ;
V_275 . V_281 = ( V_282 ) V_28 ;
V_275 . V_283 = & V_173 ;
V_275 . V_284 = 1 ;
V_275 . V_130 = V_285 ;
V_275 . V_286 = V_287 ;
return F_111 ( V_17 -> V_39 , & V_275 , & V_276 ) ;
}
static int F_112 ( struct V_12 * V_17 , struct V_22 * V_28 )
{
struct V_288 V_275 , * V_276 ;
struct V_273 V_173 ;
V_173 . V_277 = V_28 -> V_31 ;
V_173 . V_278 = V_28 -> V_24 ;
V_173 . V_279 = V_17 -> V_279 ;
V_275 . V_280 = NULL ;
V_275 . V_281 = ( V_282 ) V_28 ;
V_275 . V_283 = & V_173 ;
V_275 . V_284 = 1 ;
return F_113 ( V_17 -> V_39 , & V_275 , & V_276 ) ;
}
static void F_114 ( struct V_12 * V_17 , struct V_289 * V_290 )
{
struct V_158 * V_114 ;
struct V_192 * V_193 ;
unsigned long V_201 ;
if ( F_101 ( V_290 -> V_132 & V_291 ) ) {
F_82 ( & V_17 -> V_150 , V_201 ) ;
V_17 -> V_204 += F_115 ( V_290 -> V_203 ) ;
F_83 ( & V_17 -> V_150 , V_201 ) ;
V_17 -> V_292 = - 1 ;
if ( F_115 ( V_290 -> V_293 ) >= 4 )
V_17 -> V_292 = V_290 -> V_294 [ 3 ] ;
F_36 ( & V_17 -> V_295 ) ;
} else {
V_114 = & V_17 -> V_159 [ V_290 -> V_132 ] ;
V_193 = F_81 ( V_17 , V_114 , NULL , NULL ) ;
if ( ! V_193 ) {
F_35 ( V_95 , V_17 -> V_96 ,
L_14 ,
( unsigned long long ) V_290 -> V_132 ) ;
F_82 ( & V_17 -> V_150 , V_201 ) ;
V_17 -> V_204 += F_115 ( V_290 -> V_203 ) ;
F_83 ( & V_17 -> V_150 , V_201 ) ;
return;
}
V_193 -> V_205 = V_290 -> V_91 ;
if ( V_290 -> V_201 & V_296 ) {
memcpy ( V_193 -> V_297 , V_290 -> V_294 +
F_115 ( V_290 -> V_293 ) ,
F_98 ( int , F_115 ( V_290 -> V_298 ) ,
V_299 ) ) ;
}
if ( V_290 -> V_201 & ( V_300 | V_301 ) )
F_116 ( V_193 , F_115 ( V_290 -> V_302 ) ) ;
else if ( V_290 -> V_201 & ( V_303 | V_304 ) )
F_116 ( V_193 , F_115 ( V_290 -> V_305 ) ) ;
F_84 ( V_17 , V_114 , V_193 ,
F_115 ( V_290 -> V_203 ) ) ;
V_193 -> V_306 = NULL ;
V_193 -> V_206 ( V_193 ) ;
}
}
static int F_117 ( struct V_12 * V_17 , T_5 V_307 ,
void * V_290 , int V_220 )
{
struct V_156 * V_33 = V_17 -> V_23 -> V_32 -> V_33 ;
unsigned long V_201 ;
struct V_22 * V_28 ;
int V_71 ;
F_82 ( & V_17 -> V_150 , V_201 ) ;
V_17 -> V_204 += V_307 ;
V_28 = F_107 ( V_17 , V_268 ) ;
F_83 ( & V_17 -> V_150 , V_201 ) ;
if ( ! V_28 ) {
F_35 ( V_95 , V_17 -> V_96 , V_97
L_15 ) ;
return 1 ;
}
F_102 ( V_33 , V_28 -> V_31 , V_220 , V_165 ) ;
memcpy ( V_28 -> V_29 , V_290 , V_220 ) ;
F_105 ( V_33 , V_28 -> V_31 , V_220 , V_165 ) ;
V_71 = F_110 ( V_17 , V_28 , V_220 ) ;
if ( V_71 ) {
F_35 ( V_95 , V_17 -> V_96 , V_97
L_16 , V_71 ) ;
F_106 ( V_17 , V_28 , V_268 ) ;
}
return V_71 ;
}
static void F_118 ( struct V_12 * V_17 ,
struct V_308 * V_114 )
{
struct V_309 V_290 = {
. V_130 = V_310 ,
. V_132 = V_114 -> V_132 ,
} ;
T_5 V_311 = F_115 ( V_114 -> V_203 ) ;
if ( F_117 ( V_17 , V_311 , & V_290 , sizeof V_290 ) )
F_35 ( V_95 , V_17 -> V_96 , V_97
L_17 ) ;
}
static void F_119 ( struct V_12 * V_17 ,
struct V_312 * V_114 )
{
struct V_313 V_290 = {
. V_130 = V_314 ,
. V_132 = V_114 -> V_132 ,
} ;
T_5 V_311 = F_115 ( V_114 -> V_203 ) ;
F_35 ( V_95 , V_17 -> V_96 , V_97
L_18 , F_45 ( V_114 -> V_315 ) ) ;
if ( F_117 ( V_17 , V_311 , & V_290 , sizeof V_290 ) )
F_35 ( V_95 , V_17 -> V_96 , V_97
L_19 ) ;
}
static void F_120 ( struct V_12 * V_17 , struct V_316 * V_317 )
{
struct V_156 * V_33 = V_17 -> V_23 -> V_32 -> V_33 ;
struct V_22 * V_28 = (struct V_22 * ) ( V_282 ) V_317 -> V_281 ;
int V_7 ;
T_1 V_130 ;
F_102 ( V_33 , V_28 -> V_31 , V_17 -> V_318 ,
V_197 ) ;
V_130 = * ( T_1 * ) V_28 -> V_29 ;
if ( 0 ) {
F_35 ( V_95 , V_17 -> V_96 ,
V_97 L_20 , V_130 ) ;
F_121 ( V_95 , L_21 , V_319 , 8 , 1 ,
V_28 -> V_29 , V_317 -> V_320 , true ) ;
}
switch ( V_130 ) {
case V_321 :
F_114 ( V_17 , V_28 -> V_29 ) ;
break;
case V_322 :
F_118 ( V_17 , V_28 -> V_29 ) ;
break;
case V_323 :
F_119 ( V_17 , V_28 -> V_29 ) ;
break;
case V_324 :
F_35 ( V_109 , V_17 -> V_96 ,
V_97 L_22 ) ;
break;
default:
F_35 ( V_109 , V_17 -> V_96 ,
V_97 L_23 , V_130 ) ;
break;
}
F_105 ( V_33 , V_28 -> V_31 , V_17 -> V_318 ,
V_197 ) ;
V_7 = F_112 ( V_17 , V_28 ) ;
if ( V_7 != 0 )
F_35 ( V_95 , V_17 -> V_96 ,
V_97 L_24 , V_7 ) ;
}
static void F_122 ( struct V_182 * V_183 )
{
struct V_12 * V_17 ;
V_17 = F_73 ( V_183 , struct V_12 , V_180 ) ;
if ( V_17 -> V_179 )
F_123 ( V_17 -> V_179 ) ;
}
static void F_124 ( enum V_325 V_326 , bool V_327 ,
struct V_12 * V_17 )
{
if ( V_17 -> V_155 && ! V_17 -> V_187 ) {
F_35 ( V_95 , V_17 -> V_96 ,
V_97 L_25 ,
V_327 ? L_26 : L_27 ,
V_326 ) ;
F_50 ( V_153 , & V_17 -> V_180 ) ;
}
V_17 -> V_187 = true ;
}
static void V_68 ( struct V_65 * V_328 , void * V_94 )
{
struct V_12 * V_17 = V_94 ;
struct V_316 V_317 ;
F_29 ( V_328 , V_74 ) ;
while ( F_125 ( V_328 , 1 , & V_317 ) > 0 ) {
if ( F_126 ( V_317 . V_91 == V_329 ) ) {
F_120 ( V_17 , & V_317 ) ;
} else {
F_124 ( V_317 . V_91 , false , V_17 ) ;
}
}
}
static void V_72 ( struct V_65 * V_328 , void * V_94 )
{
struct V_12 * V_17 = V_94 ;
struct V_316 V_317 ;
struct V_22 * V_28 ;
while ( F_125 ( V_328 , 1 , & V_317 ) > 0 ) {
if ( F_126 ( V_317 . V_91 == V_329 ) ) {
V_28 = (struct V_22 * ) ( V_282 ) V_317 . V_281 ;
F_89 ( & V_28 -> V_173 , & V_17 -> V_211 ) ;
} else {
F_124 ( V_317 . V_91 , true , V_17 ) ;
}
}
}
static int F_127 ( struct V_13 * V_174 , struct V_192 * V_193 )
{
struct V_12 * V_17 = F_5 ( V_174 ) ;
struct V_184 * V_179 = V_17 -> V_179 ;
struct V_158 * V_114 ;
struct V_22 * V_28 ;
struct V_243 * V_244 ;
struct V_156 * V_33 ;
unsigned long V_201 ;
int V_220 , V_205 ;
const bool V_330 = ! F_128 () && V_331 == V_174 -> V_332 ;
if ( V_330 )
F_129 ( & V_179 -> V_333 ) ;
V_205 = F_130 ( V_17 -> V_179 ) ;
if ( F_101 ( V_205 ) ) {
V_193 -> V_205 = V_205 ;
V_193 -> V_206 ( V_193 ) ;
goto V_334;
}
F_82 ( & V_17 -> V_150 , V_201 ) ;
V_28 = F_107 ( V_17 , V_335 ) ;
if ( ! V_28 )
goto V_336;
V_114 = F_109 ( & V_17 -> V_169 , struct V_158 , V_173 ) ;
F_69 ( & V_114 -> V_173 ) ;
F_83 ( & V_17 -> V_150 , V_201 ) ;
V_33 = V_17 -> V_23 -> V_32 -> V_33 ;
F_102 ( V_33 , V_28 -> V_31 , V_17 -> V_134 ,
V_165 ) ;
V_193 -> V_205 = 0 ;
V_193 -> V_306 = ( void * ) V_114 ;
V_244 = V_28 -> V_29 ;
memset ( V_244 , 0 , sizeof *V_244 ) ;
V_244 -> V_130 = V_337 ;
V_244 -> V_315 = F_91 ( ( T_7 ) V_193 -> V_202 -> V_315 << 48 ) ;
V_244 -> V_132 = V_114 -> V_172 ;
memcpy ( V_244 -> V_338 , V_193 -> V_339 , V_193 -> V_340 ) ;
V_114 -> V_193 = V_193 ;
V_114 -> V_244 = V_28 ;
V_220 = F_99 ( V_193 , V_17 , V_114 ) ;
if ( V_220 < 0 ) {
F_35 ( V_95 , V_17 -> V_96 ,
V_97 L_28 ) ;
goto V_341;
}
F_105 ( V_33 , V_28 -> V_31 , V_17 -> V_134 ,
V_165 ) ;
if ( F_110 ( V_17 , V_28 , V_220 ) ) {
F_35 ( V_95 , V_17 -> V_96 , V_97 L_29 ) ;
goto V_342;
}
V_334:
if ( V_330 )
F_131 ( & V_179 -> V_333 ) ;
return 0 ;
V_342:
F_76 ( V_193 , V_17 , V_114 ) ;
V_341:
F_106 ( V_17 , V_28 , V_335 ) ;
F_82 ( & V_17 -> V_150 , V_201 ) ;
F_89 ( & V_114 -> V_173 , & V_17 -> V_169 ) ;
V_336:
F_83 ( & V_17 -> V_150 , V_201 ) ;
if ( V_330 )
F_131 ( & V_179 -> V_333 ) ;
return V_343 ;
}
static int F_132 ( struct V_12 * V_17 )
{
int V_88 ;
V_17 -> V_89 = F_10 ( V_17 -> V_69 * sizeof( * V_17 -> V_89 ) ,
V_43 ) ;
if ( ! V_17 -> V_89 )
goto V_344;
V_17 -> V_90 = F_10 ( V_17 -> V_69 * sizeof( * V_17 -> V_90 ) ,
V_43 ) ;
if ( ! V_17 -> V_90 )
goto V_344;
for ( V_88 = 0 ; V_88 < V_17 -> V_69 ; ++ V_88 ) {
V_17 -> V_89 [ V_88 ] = F_8 ( V_17 -> V_23 ,
V_17 -> V_318 ,
V_43 , V_197 ) ;
if ( ! V_17 -> V_89 [ V_88 ] )
goto V_71;
}
for ( V_88 = 0 ; V_88 < V_17 -> V_69 ; ++ V_88 ) {
V_17 -> V_90 [ V_88 ] = F_8 ( V_17 -> V_23 ,
V_17 -> V_134 ,
V_43 , V_165 ) ;
if ( ! V_17 -> V_90 [ V_88 ] )
goto V_71;
F_89 ( & V_17 -> V_90 [ V_88 ] -> V_173 , & V_17 -> V_211 ) ;
}
return 0 ;
V_71:
for ( V_88 = 0 ; V_88 < V_17 -> V_69 ; ++ V_88 ) {
F_14 ( V_17 -> V_23 , V_17 -> V_89 [ V_88 ] ) ;
F_14 ( V_17 -> V_23 , V_17 -> V_90 [ V_88 ] ) ;
}
V_344:
F_13 ( V_17 -> V_90 ) ;
V_17 -> V_90 = NULL ;
F_13 ( V_17 -> V_89 ) ;
V_17 -> V_89 = NULL ;
return - V_44 ;
}
static T_8 F_133 ( struct V_40 * V_345 , int V_346 )
{
T_9 V_347 , V_348 ;
T_8 V_349 ;
F_61 ( ( V_346 & ( V_350 | V_351 ) ) !=
( V_350 | V_351 ) ) ;
V_347 = 4096 * ( 1ULL << V_345 -> V_352 ) ;
V_348 = V_345 -> V_353 * 4 * V_347 ;
F_134 ( V_348 , V_354 ) ;
V_349 = F_135 ( V_348 + 1000 ) ;
return V_349 ;
}
static void F_136 ( struct V_59 * V_62 ,
struct V_355 * V_356 ,
struct V_12 * V_17 )
{
struct V_40 * V_345 = NULL ;
int V_346 = 0 ;
int V_42 ;
int V_88 ;
if ( V_356 -> V_130 == V_357 ) {
V_17 -> V_318 = F_115 ( V_356 -> V_318 ) ;
V_17 -> V_204 = F_115 ( V_356 -> V_203 ) ;
V_17 -> V_96 -> V_358
= F_104 ( V_17 -> V_204 - V_271 ,
V_17 -> V_96 -> V_358 ) ;
V_17 -> V_96 -> V_359
= F_98 ( int , V_17 -> V_96 -> V_358 ,
V_17 -> V_96 -> V_359 ) ;
} else {
F_35 ( V_109 , V_17 -> V_96 ,
V_97 L_30 , V_356 -> V_130 ) ;
V_42 = - V_191 ;
goto error;
}
if ( ! V_17 -> V_89 ) {
V_42 = F_132 ( V_17 ) ;
if ( V_42 )
goto error;
}
V_42 = - V_44 ;
V_345 = F_9 ( sizeof *V_345 , V_43 ) ;
if ( ! V_345 )
goto error;
V_345 -> V_49 = V_360 ;
V_42 = F_137 ( V_62 , V_345 , & V_346 ) ;
if ( V_42 )
goto V_361;
V_42 = F_21 ( V_17 -> V_39 , V_345 , V_346 ) ;
if ( V_42 )
goto V_361;
for ( V_88 = 0 ; V_88 < V_17 -> V_69 ; V_88 ++ ) {
struct V_22 * V_28 = V_17 -> V_89 [ V_88 ] ;
V_42 = F_112 ( V_17 , V_28 ) ;
if ( V_42 )
goto V_361;
}
V_345 -> V_49 = V_362 ;
V_42 = F_137 ( V_62 , V_345 , & V_346 ) ;
if ( V_42 )
goto V_361;
V_17 -> V_349 = F_133 ( V_345 , V_346 ) ;
V_42 = F_21 ( V_17 -> V_39 , V_345 , V_346 ) ;
if ( V_42 )
goto V_361;
V_42 = F_138 ( V_62 , NULL , 0 ) ;
V_361:
F_13 ( V_345 ) ;
error:
V_17 -> V_91 = V_42 ;
}
static void F_139 ( struct V_59 * V_62 ,
struct V_363 * V_36 ,
struct V_12 * V_17 )
{
struct V_13 * V_174 = V_17 -> V_96 ;
struct V_364 * V_365 ;
int V_130 ;
switch ( V_36 -> V_111 . V_366 . V_367 ) {
case V_368 :
V_365 = V_36 -> V_111 . V_366 . V_369 ;
V_17 -> V_46 . V_370 = V_365 -> V_371 ;
V_17 -> V_46 . V_47 = V_365 -> V_372 ;
V_62 -> V_373 = F_115 ( V_365 -> V_374 ) & 0x00ffffff ;
memcpy ( V_17 -> V_46 . V_375 . V_376 , V_365 -> V_377 , 16 ) ;
V_17 -> V_91 = V_17 -> V_46 . V_370 ?
V_189 : V_188 ;
break;
case V_378 :
if ( F_7 ( V_17 ) ) {
memcpy ( V_17 -> V_46 . V_375 . V_376 ,
V_36 -> V_111 . V_366 . V_369 , 16 ) ;
F_35 ( V_147 , V_174 ,
V_97 L_31 ,
( unsigned long long ) F_45 ( V_17 -> V_46 . V_375 . V_142 . V_379 ) ,
( unsigned long long ) F_45 ( V_17 -> V_46 . V_375 . V_142 . V_143 ) ) ;
V_17 -> V_91 = V_188 ;
} else {
F_35 ( V_109 , V_174 ,
L_32 ) ;
V_17 -> V_91 = - V_191 ;
}
break;
case V_380 :
F_35 ( V_109 , V_174 ,
L_33 ) ;
V_17 -> V_91 = - V_191 ;
break;
case V_381 :
V_130 = * ( T_1 * ) V_36 -> V_119 ;
if ( V_130 == V_382 ) {
struct V_383 * V_384 = V_36 -> V_119 ;
T_6 V_367 = F_115 ( V_384 -> V_367 ) ;
if ( V_367 == V_385 )
F_35 ( V_109 , V_174 ,
V_97 L_34 ) ;
else
F_35 ( V_109 , V_174 , V_97
L_35 ,
V_17 -> V_46 . V_141 . V_376 ,
V_17 -> V_386 , V_367 ) ;
} else
F_35 ( V_109 , V_174 ,
L_36
L_37 , V_130 ) ;
V_17 -> V_91 = - V_191 ;
break;
case V_387 :
F_35 ( V_109 , V_174 , L_38 ) ;
V_17 -> V_91 = V_190 ;
break;
default:
F_35 ( V_109 , V_174 , L_39 ,
V_36 -> V_111 . V_366 . V_367 ) ;
V_17 -> V_91 = - V_191 ;
}
}
static int V_61 ( struct V_59 * V_62 , struct V_363 * V_36 )
{
struct V_12 * V_17 = V_62 -> V_37 ;
int V_388 = 0 ;
switch ( V_36 -> V_36 ) {
case V_389 :
F_35 ( V_147 , V_17 -> V_96 ,
V_97 L_40 ) ;
V_388 = 1 ;
V_17 -> V_91 = - V_191 ;
break;
case V_390 :
V_388 = 1 ;
F_136 ( V_62 , V_36 -> V_119 , V_17 ) ;
break;
case V_391 :
F_35 ( V_147 , V_17 -> V_96 , V_97 L_41 ) ;
V_388 = 1 ;
F_139 ( V_62 , V_36 , V_17 ) ;
break;
case V_392 :
F_35 ( V_109 , V_17 -> V_96 ,
V_97 L_42 ) ;
F_51 ( V_17 , false ) ;
if ( F_140 ( V_62 , NULL , 0 ) )
F_35 ( V_95 , V_17 -> V_96 ,
V_97 L_43 ) ;
F_50 ( V_153 , & V_17 -> V_180 ) ;
break;
case V_393 :
F_35 ( V_95 , V_17 -> V_96 ,
V_97 L_44 ) ;
V_388 = 1 ;
V_17 -> V_91 = 0 ;
break;
case V_394 :
case V_395 :
case V_396 :
break;
default:
F_35 ( V_109 , V_17 -> V_96 ,
V_97 L_45 , V_36 -> V_36 ) ;
break;
}
if ( V_388 )
F_36 ( & V_17 -> V_98 ) ;
return 0 ;
}
static int
F_141 ( struct V_199 * V_200 , int V_397 )
{
if ( V_200 -> V_398 ) {
F_142 ( V_200 , V_397 ) ;
if ( V_397 )
F_143 ( V_200 , V_200 -> V_399 ) ;
else
F_144 ( V_200 , V_200 -> V_399 ) ;
} else
V_397 = 0 ;
return V_397 ;
}
static int
F_145 ( struct V_199 * V_200 , int V_400 , int V_367 )
{
struct V_13 * V_174 = V_200 -> V_14 ;
int V_401 ;
if ( V_367 == V_402 || V_367 == V_403 ) {
V_401 = V_174 -> V_358 ;
if ( ! V_200 -> V_398 )
V_401 = 1 ;
if ( V_400 > V_401 )
V_400 = V_401 ;
F_146 ( V_200 , F_147 ( V_200 ) , V_400 ) ;
} else if ( V_367 == V_404 )
F_148 ( V_200 , V_400 ) ;
else
return - V_405 ;
return V_200 -> V_399 ;
}
static int F_149 ( struct V_12 * V_17 ,
T_7 V_406 , unsigned int V_315 , T_1 V_407 )
{
struct V_184 * V_179 = V_17 -> V_179 ;
struct V_156 * V_33 = V_17 -> V_23 -> V_32 -> V_33 ;
struct V_22 * V_28 ;
struct V_408 * V_409 ;
if ( ! V_17 -> V_155 || V_17 -> V_187 )
return - 1 ;
F_38 ( & V_17 -> V_295 ) ;
F_129 ( & V_179 -> V_333 ) ;
F_48 ( & V_17 -> V_150 ) ;
V_28 = F_107 ( V_17 , V_270 ) ;
F_49 ( & V_17 -> V_150 ) ;
if ( ! V_28 ) {
F_131 ( & V_179 -> V_333 ) ;
return - 1 ;
}
F_102 ( V_33 , V_28 -> V_31 , sizeof *V_409 ,
V_165 ) ;
V_409 = V_28 -> V_29 ;
memset ( V_409 , 0 , sizeof *V_409 ) ;
V_409 -> V_130 = V_410 ;
V_409 -> V_315 = F_91 ( ( T_7 ) V_315 << 48 ) ;
V_409 -> V_132 = V_406 | V_291 ;
V_409 -> V_411 = V_407 ;
V_409 -> V_412 = V_406 ;
F_105 ( V_33 , V_28 -> V_31 , sizeof *V_409 ,
V_165 ) ;
if ( F_110 ( V_17 , V_28 , sizeof *V_409 ) ) {
F_106 ( V_17 , V_28 , V_270 ) ;
F_131 ( & V_179 -> V_333 ) ;
return - 1 ;
}
F_131 ( & V_179 -> V_333 ) ;
if ( ! F_150 ( & V_17 -> V_295 ,
F_135 ( V_413 ) ) )
return - 1 ;
return 0 ;
}
static int F_151 ( struct V_192 * V_193 )
{
struct V_12 * V_17 = F_5 ( V_193 -> V_202 -> V_14 ) ;
struct V_158 * V_114 = (struct V_158 * ) V_193 -> V_306 ;
int V_42 ;
F_35 ( V_95 , V_17 -> V_96 , L_46 ) ;
if ( ! V_114 || ! F_81 ( V_17 , V_114 , NULL , V_193 ) )
return V_414 ;
if ( F_149 ( V_17 , V_114 -> V_172 , V_193 -> V_202 -> V_315 ,
V_415 ) == 0 )
V_42 = V_414 ;
else if ( V_17 -> V_179 -> V_151 == V_416 )
V_42 = V_417 ;
else
V_42 = V_418 ;
F_84 ( V_17 , V_114 , V_193 , 0 ) ;
V_193 -> V_205 = V_419 << 16 ;
V_193 -> V_206 ( V_193 ) ;
return V_42 ;
}
static int F_152 ( struct V_192 * V_193 )
{
struct V_12 * V_17 = F_5 ( V_193 -> V_202 -> V_14 ) ;
int V_88 ;
F_35 ( V_95 , V_17 -> V_96 , L_47 ) ;
if ( F_149 ( V_17 , V_420 , V_193 -> V_202 -> V_315 ,
V_421 ) )
return V_418 ;
if ( V_17 -> V_292 )
return V_418 ;
for ( V_88 = 0 ; V_88 < V_17 -> V_160 ; ++ V_88 ) {
struct V_158 * V_114 = & V_17 -> V_159 [ V_88 ] ;
F_85 ( V_17 , V_114 , V_193 -> V_202 , V_210 << 16 ) ;
}
return V_414 ;
}
static int F_153 ( struct V_192 * V_193 )
{
struct V_12 * V_17 = F_5 ( V_193 -> V_202 -> V_14 ) ;
F_35 ( V_95 , V_17 -> V_96 , V_97 L_48 ) ;
return F_154 ( V_17 -> V_179 ) == 0 ? V_414 : V_418 ;
}
static int F_155 ( struct V_199 * V_200 )
{
struct V_13 * V_174 = V_200 -> V_14 ;
struct V_12 * V_17 = F_5 ( V_174 ) ;
struct V_207 * V_422 = V_200 -> V_207 ;
unsigned long V_352 ;
if ( V_200 -> type == V_423 ) {
V_352 = F_156 ( unsigned , 30 * V_424 , V_17 -> V_349 ) ;
F_157 ( V_422 , V_352 ) ;
}
return 0 ;
}
static T_10 F_158 ( struct V_202 * V_33 , struct V_175 * V_41 ,
char * V_29 )
{
struct V_12 * V_17 = F_5 ( F_159 ( V_33 ) ) ;
return sprintf ( V_29 , L_49 ,
( unsigned long long ) F_45 ( V_17 -> V_146 ) ) ;
}
static T_10 F_160 ( struct V_202 * V_33 , struct V_175 * V_41 ,
char * V_29 )
{
struct V_12 * V_17 = F_5 ( F_159 ( V_33 ) ) ;
return sprintf ( V_29 , L_49 ,
( unsigned long long ) F_45 ( V_17 -> V_21 ) ) ;
}
static T_10 F_161 ( struct V_202 * V_33 ,
struct V_175 * V_41 , char * V_29 )
{
struct V_12 * V_17 = F_5 ( F_159 ( V_33 ) ) ;
return sprintf ( V_29 , L_49 ,
( unsigned long long ) F_45 ( V_17 -> V_117 ) ) ;
}
static T_10 F_162 ( struct V_202 * V_33 , struct V_175 * V_41 ,
char * V_29 )
{
struct V_12 * V_17 = F_5 ( F_159 ( V_33 ) ) ;
return sprintf ( V_29 , L_50 , F_20 ( V_17 -> V_46 . V_47 ) ) ;
}
static T_10 F_163 ( struct V_202 * V_33 , struct V_175 * V_41 ,
char * V_29 )
{
struct V_12 * V_17 = F_5 ( F_159 ( V_33 ) ) ;
return sprintf ( V_29 , L_51 , V_17 -> V_46 . V_141 . V_376 ) ;
}
static T_10 F_164 ( struct V_202 * V_33 , struct V_175 * V_41 ,
char * V_29 )
{
struct V_12 * V_17 = F_5 ( F_159 ( V_33 ) ) ;
return sprintf ( V_29 , L_51 , V_17 -> V_46 . V_375 . V_376 ) ;
}
static T_10 F_165 ( struct V_202 * V_33 ,
struct V_175 * V_41 , char * V_29 )
{
struct V_12 * V_17 = F_5 ( F_159 ( V_33 ) ) ;
return sprintf ( V_29 , L_51 , V_17 -> V_386 ) ;
}
static T_10 F_166 ( struct V_202 * V_33 ,
struct V_175 * V_41 , char * V_29 )
{
struct V_12 * V_17 = F_5 ( F_159 ( V_33 ) ) ;
return sprintf ( V_29 , L_52 , V_17 -> V_204 ) ;
}
static T_10 F_167 ( struct V_202 * V_33 ,
struct V_175 * V_41 , char * V_29 )
{
struct V_12 * V_17 = F_5 ( F_159 ( V_33 ) ) ;
return sprintf ( V_29 , L_52 , V_17 -> V_272 ) ;
}
static T_10 F_168 ( struct V_202 * V_33 ,
struct V_175 * V_41 , char * V_29 )
{
struct V_12 * V_17 = F_5 ( F_159 ( V_33 ) ) ;
return sprintf ( V_29 , L_52 , V_17 -> V_23 -> V_45 ) ;
}
static T_10 F_169 ( struct V_202 * V_33 ,
struct V_175 * V_41 , char * V_29 )
{
struct V_12 * V_17 = F_5 ( F_159 ( V_33 ) ) ;
return sprintf ( V_29 , L_53 , V_17 -> V_23 -> V_32 -> V_33 -> V_425 ) ;
}
static T_10 F_170 ( struct V_202 * V_33 ,
struct V_175 * V_41 , char * V_29 )
{
struct V_12 * V_17 = F_5 ( F_159 ( V_33 ) ) ;
return sprintf ( V_29 , L_52 , V_17 -> V_70 ) ;
}
static T_10 F_171 ( struct V_202 * V_33 ,
struct V_175 * V_41 , char * V_29 )
{
struct V_12 * V_17 = F_5 ( F_159 ( V_33 ) ) ;
return sprintf ( V_29 , L_52 , V_17 -> V_127 ) ;
}
static T_10 F_172 ( struct V_202 * V_33 ,
struct V_175 * V_41 , char * V_29 )
{
struct V_12 * V_17 = F_5 ( F_159 ( V_33 ) ) ;
return sprintf ( V_29 , L_54 , V_17 -> V_170 ) ;
}
static T_10 F_173 ( struct V_202 * V_33 ,
struct V_175 * V_41 , char * V_29 )
{
struct V_12 * V_17 = F_5 ( F_159 ( V_33 ) ) ;
return sprintf ( V_29 , L_53 , V_17 -> V_259 ? L_55 : L_56 ) ;
}
static int F_174 ( struct V_23 * V_14 , struct V_12 * V_17 )
{
struct V_426 V_427 ;
struct V_184 * V_179 ;
sprintf ( V_17 -> V_16 , L_57 ,
( unsigned long long ) F_45 ( V_17 -> V_146 ) ) ;
if ( F_175 ( V_17 -> V_96 , V_14 -> V_32 -> V_33 -> V_428 ) )
return - V_429 ;
memcpy ( V_427 . V_430 , & V_17 -> V_146 , 8 ) ;
memcpy ( V_427 . V_430 + 8 , & V_17 -> V_21 , 8 ) ;
V_427 . V_431 = V_432 ;
V_179 = F_176 ( V_17 -> V_96 , & V_427 ) ;
if ( F_24 ( V_179 ) ) {
F_64 ( V_17 -> V_96 ) ;
return F_25 ( V_179 ) ;
}
V_179 -> V_185 = V_17 ;
V_17 -> V_179 = V_179 ;
F_68 ( & V_14 -> V_181 ) ;
F_57 ( & V_17 -> V_173 , & V_14 -> V_433 ) ;
F_70 ( & V_14 -> V_181 ) ;
V_17 -> V_151 = V_434 ;
F_177 ( & V_17 -> V_96 -> V_435 ,
0 , V_17 -> V_436 , V_437 , 0 ) ;
return 0 ;
}
static void F_178 ( struct V_202 * V_33 )
{
struct V_23 * V_14 =
F_73 ( V_33 , struct V_23 , V_33 ) ;
F_36 ( & V_14 -> V_438 ) ;
}
static bool F_179 ( struct V_23 * V_14 ,
struct V_12 * V_17 )
{
struct V_12 * V_439 ;
bool V_42 = false ;
if ( V_17 -> V_151 == V_152 )
goto V_8;
V_42 = true ;
F_68 ( & V_14 -> V_181 ) ;
F_180 (t, &host->target_list, list) {
if ( V_439 != V_17 &&
V_17 -> V_146 == V_439 -> V_146 &&
V_17 -> V_21 == V_439 -> V_21 &&
V_17 -> V_144 == V_439 -> V_144 ) {
V_42 = false ;
break;
}
}
F_70 ( & V_14 -> V_181 ) ;
V_8:
return V_42 ;
}
static int F_181 ( const char * V_29 , struct V_12 * V_17 )
{
char * V_440 , * V_441 ;
char * V_442 ;
char V_375 [ 3 ] ;
T_11 args [ V_443 ] ;
int V_444 = 0 ;
int V_445 ;
int V_42 = - V_252 ;
int V_88 ;
V_440 = F_182 ( V_29 , V_43 ) ;
if ( ! V_440 )
return - V_44 ;
V_441 = V_440 ;
while ( ( V_442 = F_183 ( & V_441 , L_58 ) ) != NULL ) {
if ( ! * V_442 )
continue;
V_445 = F_184 ( V_442 , V_446 , args ) ;
V_444 |= V_445 ;
switch ( V_445 ) {
case V_447 :
V_442 = F_185 ( args ) ;
if ( ! V_442 ) {
V_42 = - V_44 ;
goto V_8;
}
V_17 -> V_146 = F_91 ( F_186 ( V_442 , NULL , 16 ) ) ;
F_13 ( V_442 ) ;
break;
case V_448 :
V_442 = F_185 ( args ) ;
if ( ! V_442 ) {
V_42 = - V_44 ;
goto V_8;
}
V_17 -> V_21 = F_91 ( F_186 ( V_442 , NULL , 16 ) ) ;
F_13 ( V_442 ) ;
break;
case V_449 :
V_442 = F_185 ( args ) ;
if ( ! V_442 ) {
V_42 = - V_44 ;
goto V_8;
}
if ( strlen ( V_442 ) != 32 ) {
F_187 ( L_59 , V_442 ) ;
F_13 ( V_442 ) ;
goto V_8;
}
for ( V_88 = 0 ; V_88 < 16 ; ++ V_88 ) {
F_188 ( V_375 , V_442 + V_88 * 2 , 3 ) ;
V_17 -> V_46 . V_375 . V_376 [ V_88 ] = F_189 ( V_375 , NULL , 16 ) ;
}
F_13 ( V_442 ) ;
memcpy ( V_17 -> V_386 , V_17 -> V_46 . V_375 . V_376 , 16 ) ;
break;
case V_450 :
if ( F_190 ( args , & V_445 ) ) {
F_187 ( L_60 , V_442 ) ;
goto V_8;
}
V_17 -> V_46 . V_47 = F_44 ( V_445 ) ;
break;
case V_451 :
V_442 = F_185 ( args ) ;
if ( ! V_442 ) {
V_42 = - V_44 ;
goto V_8;
}
V_17 -> V_117 = F_91 ( F_186 ( V_442 , NULL , 16 ) ) ;
V_17 -> V_46 . V_117 = V_17 -> V_117 ;
F_13 ( V_442 ) ;
break;
case V_452 :
if ( F_191 ( args , & V_445 ) ) {
F_187 ( L_61 , V_442 ) ;
goto V_8;
}
V_17 -> V_96 -> V_453 = V_445 ;
break;
case V_454 :
if ( F_191 ( args , & V_445 ) || V_445 < 1 ) {
F_187 ( L_62 , V_442 ) ;
goto V_8;
}
V_17 -> V_96 -> V_358 = V_445 ;
V_17 -> V_69 = V_445 + V_455 +
V_271 ;
if ( ! ( V_444 & V_456 ) )
V_17 -> V_96 -> V_359 = V_445 ;
break;
case V_456 :
if ( F_191 ( args , & V_445 ) || V_445 < 1 ) {
F_187 ( L_63 ,
V_442 ) ;
goto V_8;
}
V_17 -> V_96 -> V_359 = V_445 ;
break;
case V_457 :
if ( F_190 ( args , & V_445 ) ) {
F_187 ( L_64 , V_442 ) ;
goto V_8;
}
if ( V_445 != V_139 &&
V_445 != V_458 ) {
F_187 ( L_65 ,
V_445 , V_139 ,
V_458 ) ;
goto V_8;
}
V_17 -> V_138 = V_445 ;
break;
case V_459 :
V_442 = F_185 ( args ) ;
if ( ! V_442 ) {
V_42 = - V_44 ;
goto V_8;
}
V_17 -> V_144 = F_91 ( F_186 ( V_442 , NULL , 16 ) ) ;
F_13 ( V_442 ) ;
break;
case V_460 :
if ( F_191 ( args , & V_445 ) || V_445 < 1 || V_445 > 255 ) {
F_187 ( L_66 ,
V_442 ) ;
goto V_8;
}
V_17 -> V_170 = V_445 ;
break;
case V_461 :
if ( F_191 ( args , & V_445 ) ) {
F_187 ( L_67 , V_442 ) ;
goto V_8;
}
V_17 -> V_259 = ! ! V_445 ;
break;
case V_462 :
if ( F_191 ( args , & V_445 ) || V_445 < 1 ||
V_445 > V_463 ) {
F_187 ( L_68 ,
V_442 ) ;
goto V_8;
}
V_17 -> V_464 = V_445 ;
break;
case V_465 :
if ( F_191 ( args , & V_445 ) || V_445 < 0 ) {
F_187 ( L_69 , V_442 ) ;
goto V_8;
}
V_17 -> V_70 = V_445 ;
break;
case V_466 :
if ( F_191 ( args , & V_445 ) || V_445 < 2 || V_445 > 7 ) {
F_187 ( L_70 ,
V_442 ) ;
goto V_8;
}
V_17 -> V_127 = V_445 ;
break;
default:
F_187 ( L_71 ,
V_442 ) ;
goto V_8;
}
}
if ( ( V_444 & V_467 ) == V_467 )
V_42 = 0 ;
else
for ( V_88 = 0 ; V_88 < F_192 ( V_446 ) ; ++ V_88 )
if ( ( V_446 [ V_88 ] . V_445 & V_467 ) &&
! ( V_446 [ V_88 ] . V_445 & V_444 ) )
F_187 ( L_72 ,
V_446 [ V_88 ] . V_468 ) ;
if ( V_17 -> V_96 -> V_359 > V_17 -> V_96 -> V_358
&& ( V_444 & V_456 ) )
F_187 ( L_73 ,
V_17 -> V_96 -> V_359 ,
V_17 -> V_96 -> V_358 ) ;
V_8:
F_13 ( V_440 ) ;
return V_42 ;
}
static T_10 F_193 ( struct V_202 * V_33 ,
struct V_175 * V_41 ,
const char * V_29 , T_2 V_246 )
{
struct V_23 * V_14 =
F_73 ( V_33 , struct V_23 , V_33 ) ;
struct V_13 * V_469 ;
struct V_12 * V_17 ;
struct V_156 * V_157 = V_14 -> V_32 -> V_33 ;
int V_42 ;
V_469 = F_194 ( & V_470 ,
sizeof ( struct V_12 ) ) ;
if ( ! V_469 )
return - V_44 ;
V_469 -> V_471 = V_472 ;
V_469 -> V_473 = 0 ;
V_469 -> V_474 = 1 ;
V_469 -> V_475 = V_476 ;
V_469 -> V_477 = sizeof ( (struct V_243 * ) ( void * ) 0L ) -> V_338 ;
V_17 = F_5 ( V_469 ) ;
V_17 -> V_138 = V_458 ;
V_17 -> V_96 = V_469 ;
V_17 -> V_23 = V_14 ;
V_17 -> V_279 = V_14 -> V_32 -> V_478 -> V_279 ;
V_17 -> V_215 = V_14 -> V_32 -> V_478 -> V_215 ;
V_17 -> V_170 = V_479 ;
V_17 -> V_464 = V_480 ? : V_479 ;
V_17 -> V_259 = V_259 ;
V_17 -> V_127 = 7 ;
V_17 -> V_69 = V_481 ;
F_129 ( & V_14 -> V_482 ) ;
V_42 = F_181 ( V_29 , V_17 ) ;
if ( V_42 )
goto V_71;
V_17 -> V_160 = V_17 -> V_69 - V_271 ;
if ( ! F_179 ( V_17 -> V_23 , V_17 ) ) {
F_35 ( V_212 , V_17 -> V_96 ,
V_97 L_74 ,
F_45 ( V_17 -> V_146 ) ,
F_45 ( V_17 -> V_21 ) ,
F_45 ( V_17 -> V_144 ) ) ;
V_42 = - V_483 ;
goto V_71;
}
if ( ! V_14 -> V_32 -> V_228 && ! V_17 -> V_259 &&
V_17 -> V_170 < V_17 -> V_464 ) {
F_187 ( L_75 ) ;
V_17 -> V_464 = V_17 -> V_170 ;
}
V_469 -> V_464 = V_17 -> V_464 ;
V_17 -> V_164 = V_17 -> V_464 *
sizeof ( struct V_216 ) ;
V_17 -> V_134 = sizeof ( struct V_243 ) +
sizeof ( struct V_247 ) +
V_17 -> V_170 * sizeof ( struct V_216 ) ;
F_195 ( & V_17 -> V_180 , F_122 ) ;
F_195 ( & V_17 -> V_154 , F_72 ) ;
F_196 ( & V_17 -> V_150 ) ;
F_56 ( & V_17 -> V_211 ) ;
V_42 = F_55 ( V_17 ) ;
if ( V_42 )
goto V_484;
V_42 = F_197 ( V_157 , V_14 -> V_45 , 0 , & V_17 -> V_46 . V_141 ) ;
if ( V_42 )
goto V_484;
V_42 = F_27 ( V_17 ) ;
if ( V_42 )
goto V_484;
V_42 = F_22 ( V_17 ) ;
if ( V_42 )
goto V_485;
V_42 = F_75 ( V_17 ) ;
if ( V_42 ) {
F_35 ( V_95 , V_17 -> V_96 ,
V_97 L_76 ) ;
goto V_486;
}
V_42 = F_174 ( V_14 , V_17 ) ;
if ( V_42 )
goto V_487;
F_35 ( V_147 , V_17 -> V_96 , V_97
L_77 ,
F_45 ( V_17 -> V_146 ) ,
F_45 ( V_17 -> V_21 ) ,
F_20 ( V_17 -> V_46 . V_47 ) ,
F_45 ( V_17 -> V_117 ) ,
V_17 -> V_46 . V_141 . V_376 , V_17 -> V_46 . V_375 . V_376 ) ;
V_42 = V_246 ;
V_8:
F_131 ( & V_14 -> V_482 ) ;
return V_42 ;
V_487:
F_52 ( V_17 ) ;
V_486:
F_26 ( V_17 -> V_62 ) ;
V_485:
F_33 ( V_17 ) ;
V_484:
F_54 ( V_17 ) ;
V_71:
F_71 ( V_469 ) ;
goto V_8;
}
static T_10 F_198 ( struct V_202 * V_33 , struct V_175 * V_41 ,
char * V_29 )
{
struct V_23 * V_14 = F_73 ( V_33 , struct V_23 , V_33 ) ;
return sprintf ( V_29 , L_53 , V_14 -> V_32 -> V_33 -> V_425 ) ;
}
static T_10 F_199 ( struct V_202 * V_33 , struct V_175 * V_41 ,
char * V_29 )
{
struct V_23 * V_14 = F_73 ( V_33 , struct V_23 , V_33 ) ;
return sprintf ( V_29 , L_52 , V_14 -> V_45 ) ;
}
static struct V_23 * F_200 ( struct V_167 * V_202 , T_1 V_45 )
{
struct V_23 * V_14 ;
V_14 = F_10 ( sizeof *V_14 , V_43 ) ;
if ( ! V_14 )
return NULL ;
F_56 ( & V_14 -> V_433 ) ;
F_196 ( & V_14 -> V_181 ) ;
F_38 ( & V_14 -> V_438 ) ;
F_201 ( & V_14 -> V_482 ) ;
V_14 -> V_32 = V_202 ;
V_14 -> V_45 = V_45 ;
V_14 -> V_33 . V_488 = & V_489 ;
V_14 -> V_33 . V_490 = V_202 -> V_33 -> V_428 ;
F_202 ( & V_14 -> V_33 , L_78 , V_202 -> V_33 -> V_425 , V_45 ) ;
if ( F_203 ( & V_14 -> V_33 ) )
goto V_491;
if ( F_204 ( & V_14 -> V_33 , & V_492 ) )
goto V_493;
if ( F_204 ( & V_14 -> V_33 , & V_494 ) )
goto V_493;
if ( F_204 ( & V_14 -> V_33 , & V_495 ) )
goto V_493;
return V_14 ;
V_493:
F_205 ( & V_14 -> V_33 ) ;
V_491:
F_13 ( V_14 ) ;
return NULL ;
}
static void F_206 ( struct V_156 * V_202 )
{
struct V_167 * V_32 ;
struct V_496 * V_497 ;
struct V_498 V_499 ;
struct V_23 * V_14 ;
int V_500 , V_501 , V_502 , V_503 , V_442 ;
V_497 = F_9 ( sizeof *V_497 , V_43 ) ;
if ( ! V_497 )
return;
if ( F_207 ( V_202 , V_497 ) ) {
F_187 ( L_79 , V_202 -> V_425 ) ;
goto V_504;
}
V_32 = F_9 ( sizeof *V_32 , V_43 ) ;
if ( ! V_32 )
goto V_504;
V_501 = F_208 ( 12 , F_209 ( V_497 -> V_505 ) - 1 ) ;
V_32 -> V_241 = 1 << V_501 ;
V_32 -> V_239 = ~ ( ( T_7 ) V_32 -> V_241 - 1 ) ;
V_32 -> V_240 = V_32 -> V_241 * V_171 ;
F_56 ( & V_32 -> V_506 ) ;
V_32 -> V_33 = V_202 ;
V_32 -> V_85 = F_210 ( V_202 ) ;
if ( F_24 ( V_32 -> V_85 ) )
goto V_507;
V_32 -> V_478 = F_211 ( V_32 -> V_85 ,
V_508 |
V_52 |
V_53 ) ;
if ( F_24 ( V_32 -> V_478 ) )
goto V_509;
for ( V_500 = V_171 ;
V_500 >= V_510 ;
V_500 /= 2 , V_32 -> V_240 /= 2 ) {
memset ( & V_499 , 0 , sizeof V_499 ) ;
V_499 . V_511 = V_512 ;
V_499 . V_513 = V_514 ;
V_499 . V_515 = 1 ;
V_499 . V_500 = V_500 ;
V_499 . V_516 = V_501 ;
V_499 . V_517 = ( V_508 |
V_53 |
V_52 ) ;
V_32 -> V_228 = F_212 ( V_32 -> V_85 , & V_499 ) ;
if ( ! F_24 ( V_32 -> V_228 ) )
break;
}
if ( F_24 ( V_32 -> V_228 ) )
V_32 -> V_228 = NULL ;
if ( V_202 -> V_518 == V_519 ) {
V_502 = 0 ;
V_503 = 0 ;
} else {
V_502 = 1 ;
V_503 = V_202 -> V_520 ;
}
for ( V_442 = V_502 ; V_442 <= V_503 ; ++ V_442 ) {
V_14 = F_200 ( V_32 , V_442 ) ;
if ( V_14 )
F_57 ( & V_14 -> V_173 , & V_32 -> V_506 ) ;
}
F_213 ( V_202 , & V_521 , V_32 ) ;
goto V_504;
V_509:
F_214 ( V_32 -> V_85 ) ;
V_507:
F_13 ( V_32 ) ;
V_504:
F_13 ( V_497 ) ;
}
static void F_215 ( struct V_156 * V_202 )
{
struct V_167 * V_32 ;
struct V_23 * V_14 , * V_522 ;
struct V_12 * V_17 ;
V_32 = F_216 ( V_202 , & V_521 ) ;
if ( ! V_32 )
return;
F_217 (host, tmp_host, &srp_dev->dev_list, list) {
F_205 ( & V_14 -> V_33 ) ;
F_218 ( & V_14 -> V_438 ) ;
F_68 ( & V_14 -> V_181 ) ;
F_180 (target, &host->target_list, list)
F_47 ( V_17 ) ;
F_70 ( & V_14 -> V_181 ) ;
F_219 ( V_153 ) ;
F_13 ( V_14 ) ;
}
if ( V_32 -> V_228 )
F_220 ( V_32 -> V_228 ) ;
F_221 ( V_32 -> V_478 ) ;
F_214 ( V_32 -> V_85 ) ;
F_13 ( V_32 ) ;
}
static int T_12 F_222 ( void )
{
int V_42 ;
F_223 ( F_224 ( struct V_316 , V_281 ) < sizeof( void * ) ) ;
if ( V_523 ) {
F_187 ( L_80 ) ;
if ( ! V_479 )
V_479 = V_523 ;
}
if ( ! V_479 )
V_479 = V_524 ;
if ( V_479 > 255 ) {
F_187 ( L_81 ) ;
V_479 = 255 ;
}
if ( ! V_480 )
V_480 = V_479 ;
else if ( V_480 < V_479 ) {
F_187 ( L_82 ,
V_479 ) ;
V_480 = V_479 ;
}
V_472 =
F_225 ( & V_525 ) ;
if ( ! V_472 )
return - V_44 ;
V_42 = F_226 ( & V_489 ) ;
if ( V_42 ) {
F_227 ( L_83 ) ;
F_228 ( V_472 ) ;
return V_42 ;
}
F_229 ( & V_101 ) ;
V_42 = F_230 ( & V_521 ) ;
if ( V_42 ) {
F_227 ( L_84 ) ;
F_228 ( V_472 ) ;
F_231 ( & V_101 ) ;
F_232 ( & V_489 ) ;
return V_42 ;
}
return 0 ;
}
static void T_13 F_233 ( void )
{
F_234 ( & V_521 ) ;
F_231 ( & V_101 ) ;
F_232 ( & V_489 ) ;
F_228 ( V_472 ) ;
}
