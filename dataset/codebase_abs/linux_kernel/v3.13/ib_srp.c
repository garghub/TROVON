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
F_40 ( & V_17 -> V_98 ) ;
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
F_52 ( V_17 ) ;
F_26 ( V_17 -> V_62 ) ;
F_33 ( V_17 ) ;
F_65 ( & V_17 -> V_180 ) ;
F_66 ( V_17 -> V_179 ) ;
F_54 ( V_17 ) ;
F_67 ( & V_17 -> V_23 -> V_181 ) ;
F_68 ( & V_17 -> V_173 ) ;
F_69 ( & V_17 -> V_23 -> V_181 ) ;
F_70 ( V_17 -> V_96 ) ;
}
static void F_71 ( struct V_182 * V_183 )
{
struct V_12 * V_17 =
F_72 ( V_183 , struct V_12 , V_154 ) ;
F_61 ( V_17 -> V_151 != V_152 ) ;
F_60 ( V_17 ) ;
}
static void F_73 ( struct V_184 * V_179 )
{
struct V_12 * V_17 = V_179 -> V_185 ;
F_47 ( V_17 ) ;
}
static int F_74 ( struct V_12 * V_17 )
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
F_40 ( & V_17 -> V_98 ) ;
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
static void F_75 ( struct V_192 * V_193 ,
struct V_12 * V_17 ,
struct V_158 * V_114 )
{
struct V_156 * V_157 = V_17 -> V_23 -> V_32 -> V_33 ;
struct V_194 * * V_195 ;
if ( ! F_76 ( V_193 ) ||
( V_193 -> V_196 != V_165 &&
V_193 -> V_196 != V_197 ) )
return;
V_195 = V_114 -> V_161 ;
while ( V_114 -> V_198 -- )
F_77 ( * V_195 ++ ) ;
F_78 ( V_157 , F_76 ( V_193 ) , F_79 ( V_193 ) ,
V_193 -> V_196 ) ;
}
static struct V_192 * F_80 ( struct V_12 * V_17 ,
struct V_158 * V_114 ,
struct V_192 * V_193 )
{
unsigned long V_199 ;
F_81 ( & V_17 -> V_150 , V_199 ) ;
if ( ! V_193 ) {
V_193 = V_114 -> V_193 ;
V_114 -> V_193 = NULL ;
} else if ( V_114 -> V_193 == V_193 ) {
V_114 -> V_193 = NULL ;
} else {
V_193 = NULL ;
}
F_82 ( & V_17 -> V_150 , V_199 ) ;
return V_193 ;
}
static void F_83 ( struct V_12 * V_17 ,
struct V_158 * V_114 , struct V_192 * V_193 ,
T_5 V_200 )
{
unsigned long V_199 ;
F_75 ( V_193 , V_17 , V_114 ) ;
F_81 ( & V_17 -> V_150 , V_199 ) ;
V_17 -> V_201 += V_200 ;
F_57 ( & V_114 -> V_173 , & V_17 -> V_169 ) ;
F_82 ( & V_17 -> V_150 , V_199 ) ;
}
static void F_84 ( struct V_12 * V_17 ,
struct V_158 * V_114 , int V_202 )
{
struct V_192 * V_193 = F_80 ( V_17 , V_114 , NULL ) ;
if ( V_193 ) {
F_83 ( V_17 , V_114 , V_193 , 0 ) ;
V_193 -> V_202 = V_202 ;
V_193 -> V_203 ( V_193 ) ;
}
}
static void F_85 ( struct V_184 * V_179 )
{
struct V_12 * V_17 = V_179 -> V_185 ;
int V_88 ;
for ( V_88 = 0 ; V_88 < V_17 -> V_160 ; ++ V_88 ) {
struct V_158 * V_114 = & V_17 -> V_159 [ V_88 ] ;
F_84 ( V_17 , V_114 , V_204 << 16 ) ;
}
}
static int F_86 ( struct V_184 * V_179 )
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
F_84 ( V_17 , V_114 , V_205 << 16 ) ;
}
F_56 ( & V_17 -> V_206 ) ;
for ( V_88 = 0 ; V_88 < V_17 -> V_69 ; ++ V_88 )
F_87 ( & V_17 -> V_90 [ V_88 ] -> V_173 , & V_17 -> V_206 ) ;
if ( V_42 == 0 )
V_42 = F_74 ( V_17 ) ;
if ( V_42 == 0 )
F_35 ( V_207 , V_17 -> V_96 ,
V_97 L_11 ) ;
return V_42 ;
}
static void F_88 ( struct V_208 * V_151 , T_4 V_168 ,
unsigned int V_209 , T_6 V_210 )
{
struct V_211 * V_212 = V_151 -> V_212 ;
V_212 -> V_213 = F_89 ( V_168 ) ;
V_212 -> V_214 = F_43 ( V_210 ) ;
V_212 -> V_215 = F_43 ( V_209 ) ;
V_151 -> V_216 += V_209 ;
V_151 -> V_212 ++ ;
V_151 -> V_217 ++ ;
}
static int F_90 ( struct V_208 * V_151 ,
struct V_12 * V_17 )
{
struct V_167 * V_33 = V_17 -> V_23 -> V_32 ;
struct V_194 * V_218 ;
T_7 V_219 = 0 ;
if ( ! V_151 -> V_220 )
return 0 ;
if ( V_151 -> V_220 == 1 ) {
F_88 ( V_151 , V_151 -> V_221 , V_151 -> V_222 ,
V_17 -> V_210 ) ;
V_151 -> V_220 = V_151 -> V_222 = 0 ;
return 0 ;
}
V_218 = F_91 ( V_33 -> V_223 , V_151 -> V_224 ,
V_151 -> V_220 , V_219 ) ;
if ( F_24 ( V_218 ) )
return F_25 ( V_218 ) ;
* V_151 -> V_225 ++ = V_218 ;
V_151 -> V_198 ++ ;
F_88 ( V_151 , 0 , V_151 -> V_222 , V_218 -> V_218 -> V_210 ) ;
V_151 -> V_220 = V_151 -> V_222 = 0 ;
return 0 ;
}
static void F_92 ( struct V_208 * V_151 ,
struct V_226 * V_227 , int V_228 ,
T_4 V_168 )
{
V_151 -> V_229 = V_227 ;
V_151 -> V_230 = V_228 ;
V_151 -> V_231 = V_168 ;
}
static int F_93 ( struct V_208 * V_151 ,
struct V_12 * V_17 ,
struct V_226 * V_227 , int V_228 ,
int V_232 )
{
struct V_167 * V_33 = V_17 -> V_23 -> V_32 ;
struct V_156 * V_157 = V_33 -> V_33 ;
T_4 V_168 = F_94 ( V_157 , V_227 ) ;
unsigned int V_209 = F_95 ( V_157 , V_227 ) ;
unsigned int V_215 ;
int V_42 ;
if ( ! V_209 )
return 0 ;
if ( V_232 == V_233 ) {
F_88 ( V_151 , V_168 , V_209 , V_17 -> V_210 ) ;
return 0 ;
}
if ( V_168 & ~ V_33 -> V_234 || V_209 > V_33 -> V_235 ) {
V_42 = F_90 ( V_151 , V_17 ) ;
if ( V_42 )
return V_42 ;
F_88 ( V_151 , V_168 , V_209 , V_17 -> V_210 ) ;
F_92 ( V_151 , NULL , 0 , 0 ) ;
return 0 ;
}
if ( ! V_151 -> V_229 )
F_92 ( V_151 , V_227 , V_228 , V_168 ) ;
while ( V_209 ) {
if ( V_151 -> V_220 == V_171 ) {
V_42 = F_90 ( V_151 , V_17 ) ;
if ( V_42 )
return V_42 ;
F_92 ( V_151 , V_227 , V_228 , V_168 ) ;
}
V_215 = F_96 (unsigned int, dma_len, dev->fmr_page_size) ;
if ( ! V_151 -> V_220 )
V_151 -> V_221 = V_168 ;
V_151 -> V_224 [ V_151 -> V_220 ++ ] = V_168 ;
V_151 -> V_222 += V_215 ;
V_168 += V_215 ;
V_209 -= V_215 ;
}
V_42 = 0 ;
if ( V_215 != V_33 -> V_236 ) {
V_42 = F_90 ( V_151 , V_17 ) ;
if ( ! V_42 )
F_92 ( V_151 , NULL , 0 , 0 ) ;
}
return V_42 ;
}
static int F_97 ( struct V_192 * V_193 , struct V_12 * V_17 ,
struct V_158 * V_114 )
{
struct V_226 * V_237 , * V_227 ;
struct V_238 * V_239 = V_114 -> V_239 -> V_29 ;
int V_88 , V_215 , V_240 , V_241 , V_232 ;
struct V_167 * V_33 ;
struct V_156 * V_157 ;
struct V_208 V_151 ;
struct V_242 * V_243 ;
T_6 V_244 ;
T_1 V_245 ;
if ( ! F_76 ( V_193 ) || V_193 -> V_196 == V_246 )
return sizeof ( struct V_238 ) ;
if ( V_193 -> V_196 != V_197 &&
V_193 -> V_196 != V_165 ) {
F_35 ( V_109 , V_17 -> V_96 ,
V_97 L_12 ,
V_193 -> V_196 ) ;
return - V_247 ;
}
V_240 = F_79 ( V_193 ) ;
V_237 = F_76 ( V_193 ) ;
V_33 = V_17 -> V_23 -> V_32 ;
V_157 = V_33 -> V_33 ;
V_241 = F_98 ( V_157 , V_237 , V_240 , V_193 -> V_196 ) ;
if ( F_99 ( V_241 == 0 ) )
return - V_248 ;
V_245 = V_249 ;
V_215 = sizeof ( struct V_238 ) + sizeof ( struct V_211 ) ;
if ( V_241 == 1 ) {
struct V_211 * V_29 = ( void * ) V_239 -> V_250 ;
V_29 -> V_213 = F_89 ( F_94 ( V_157 , V_237 ) ) ;
V_29 -> V_214 = F_43 ( V_17 -> V_210 ) ;
V_29 -> V_215 = F_43 ( F_95 ( V_157 , V_237 ) ) ;
V_114 -> V_198 = 0 ;
goto V_251;
}
V_243 = ( void * ) V_239 -> V_250 ;
F_100 ( V_157 , V_114 -> V_163 ,
V_17 -> V_164 , V_165 ) ;
memset ( & V_151 , 0 , sizeof( V_151 ) ) ;
V_151 . V_212 = V_114 -> V_166 ;
V_151 . V_224 = V_114 -> V_162 ;
V_151 . V_225 = V_114 -> V_161 ;
V_232 = V_33 -> V_223 ? V_252 : V_233 ;
F_101 (scat, sg, count, i) {
if ( F_93 ( & V_151 , V_17 , V_227 , V_88 , V_232 ) ) {
T_4 V_168 ;
unsigned int V_209 ;
V_253:
V_227 = V_151 . V_229 ;
V_88 = V_151 . V_230 ;
V_168 = F_94 ( V_157 , V_227 ) ;
V_209 = F_95 ( V_157 , V_227 ) ;
V_209 -= ( V_151 . V_231 - V_168 ) ;
V_168 = V_151 . V_231 ;
V_232 = V_233 ;
F_88 ( & V_151 , V_168 , V_209 , V_17 -> V_210 ) ;
}
}
if ( V_232 == V_252 && F_90 ( & V_151 , V_17 ) )
goto V_253;
V_114 -> V_198 = V_151 . V_198 ;
if ( V_151 . V_217 == 1 ) {
struct V_211 * V_29 = ( void * ) V_239 -> V_250 ;
* V_29 = V_114 -> V_166 [ 0 ] ;
goto V_251;
}
if ( F_99 ( V_17 -> V_170 < V_151 . V_217 &&
! V_17 -> V_254 ) ) {
F_35 ( V_95 , V_17 -> V_96 ,
L_13 ) ;
return - V_248 ;
}
V_241 = F_102 ( V_151 . V_217 , V_17 -> V_170 ) ;
V_244 = V_151 . V_217 * sizeof ( struct V_211 ) ;
V_245 = V_255 ;
V_215 = sizeof( struct V_238 ) + sizeof ( struct V_242 ) ;
V_215 += V_241 * sizeof ( struct V_211 ) ;
memcpy ( V_243 -> V_256 , V_114 -> V_166 ,
V_241 * sizeof ( struct V_211 ) ) ;
V_243 -> V_257 . V_213 = F_89 ( V_114 -> V_163 ) ;
V_243 -> V_257 . V_214 = F_43 ( V_17 -> V_210 ) ;
V_243 -> V_257 . V_215 = F_43 ( V_244 ) ;
V_243 -> V_215 = F_43 ( V_151 . V_216 ) ;
if ( V_193 -> V_196 == V_165 )
V_239 -> V_258 = V_241 ;
else
V_239 -> V_259 = V_241 ;
F_103 ( V_157 , V_114 -> V_163 , V_244 ,
V_165 ) ;
V_251:
if ( V_193 -> V_196 == V_165 )
V_239 -> V_260 = V_245 << 4 ;
else
V_239 -> V_260 = V_245 ;
return V_215 ;
}
static void F_104 ( struct V_12 * V_17 , struct V_22 * V_28 ,
enum V_261 V_262 )
{
unsigned long V_199 ;
F_81 ( & V_17 -> V_150 , V_199 ) ;
F_87 ( & V_28 -> V_173 , & V_17 -> V_206 ) ;
if ( V_262 != V_263 )
++ V_17 -> V_201 ;
F_82 ( & V_17 -> V_150 , V_199 ) ;
}
static struct V_22 * F_105 ( struct V_12 * V_17 ,
enum V_261 V_262 )
{
T_5 V_264 = ( V_262 == V_265 ) ? 0 : V_266 ;
struct V_22 * V_28 ;
V_72 ( V_17 -> V_67 , V_17 ) ;
if ( F_106 ( & V_17 -> V_206 ) )
return NULL ;
if ( V_262 != V_263 ) {
if ( V_17 -> V_201 <= V_264 ) {
++ V_17 -> V_267 ;
return NULL ;
}
-- V_17 -> V_201 ;
}
V_28 = F_107 ( & V_17 -> V_206 , struct V_22 , V_173 ) ;
F_68 ( & V_28 -> V_173 ) ;
return V_28 ;
}
static int F_108 ( struct V_12 * V_17 ,
struct V_22 * V_28 , int V_215 )
{
struct V_268 V_173 ;
struct V_269 V_270 , * V_271 ;
V_173 . V_272 = V_28 -> V_31 ;
V_173 . V_273 = V_215 ;
V_173 . V_274 = V_17 -> V_274 ;
V_270 . V_275 = NULL ;
V_270 . V_276 = ( V_277 ) V_28 ;
V_270 . V_278 = & V_173 ;
V_270 . V_279 = 1 ;
V_270 . V_130 = V_280 ;
V_270 . V_281 = V_282 ;
return F_109 ( V_17 -> V_39 , & V_270 , & V_271 ) ;
}
static int F_110 ( struct V_12 * V_17 , struct V_22 * V_28 )
{
struct V_283 V_270 , * V_271 ;
struct V_268 V_173 ;
V_173 . V_272 = V_28 -> V_31 ;
V_173 . V_273 = V_28 -> V_24 ;
V_173 . V_274 = V_17 -> V_274 ;
V_270 . V_275 = NULL ;
V_270 . V_276 = ( V_277 ) V_28 ;
V_270 . V_278 = & V_173 ;
V_270 . V_279 = 1 ;
return F_111 ( V_17 -> V_39 , & V_270 , & V_271 ) ;
}
static void F_112 ( struct V_12 * V_17 , struct V_284 * V_285 )
{
struct V_158 * V_114 ;
struct V_192 * V_193 ;
unsigned long V_199 ;
if ( F_99 ( V_285 -> V_132 & V_286 ) ) {
F_81 ( & V_17 -> V_150 , V_199 ) ;
V_17 -> V_201 += F_113 ( V_285 -> V_200 ) ;
F_82 ( & V_17 -> V_150 , V_199 ) ;
V_17 -> V_287 = - 1 ;
if ( F_113 ( V_285 -> V_288 ) >= 4 )
V_17 -> V_287 = V_285 -> V_289 [ 3 ] ;
F_36 ( & V_17 -> V_290 ) ;
} else {
V_114 = & V_17 -> V_159 [ V_285 -> V_132 ] ;
V_193 = F_80 ( V_17 , V_114 , NULL ) ;
if ( ! V_193 ) {
F_35 ( V_95 , V_17 -> V_96 ,
L_14 ,
( unsigned long long ) V_285 -> V_132 ) ;
F_81 ( & V_17 -> V_150 , V_199 ) ;
V_17 -> V_201 += F_113 ( V_285 -> V_200 ) ;
F_82 ( & V_17 -> V_150 , V_199 ) ;
return;
}
V_193 -> V_202 = V_285 -> V_91 ;
if ( V_285 -> V_199 & V_291 ) {
memcpy ( V_193 -> V_292 , V_285 -> V_289 +
F_113 ( V_285 -> V_288 ) ,
F_96 ( int , F_113 ( V_285 -> V_293 ) ,
V_294 ) ) ;
}
if ( V_285 -> V_199 & ( V_295 | V_296 ) )
F_114 ( V_193 , F_113 ( V_285 -> V_297 ) ) ;
else if ( V_285 -> V_199 & ( V_298 | V_299 ) )
F_114 ( V_193 , F_113 ( V_285 -> V_300 ) ) ;
F_83 ( V_17 , V_114 , V_193 ,
F_113 ( V_285 -> V_200 ) ) ;
V_193 -> V_301 = NULL ;
V_193 -> V_203 ( V_193 ) ;
}
}
static int F_115 ( struct V_12 * V_17 , T_5 V_302 ,
void * V_285 , int V_215 )
{
struct V_156 * V_33 = V_17 -> V_23 -> V_32 -> V_33 ;
unsigned long V_199 ;
struct V_22 * V_28 ;
int V_71 ;
F_81 ( & V_17 -> V_150 , V_199 ) ;
V_17 -> V_201 += V_302 ;
V_28 = F_105 ( V_17 , V_263 ) ;
F_82 ( & V_17 -> V_150 , V_199 ) ;
if ( ! V_28 ) {
F_35 ( V_95 , V_17 -> V_96 , V_97
L_15 ) ;
return 1 ;
}
F_100 ( V_33 , V_28 -> V_31 , V_215 , V_165 ) ;
memcpy ( V_28 -> V_29 , V_285 , V_215 ) ;
F_103 ( V_33 , V_28 -> V_31 , V_215 , V_165 ) ;
V_71 = F_108 ( V_17 , V_28 , V_215 ) ;
if ( V_71 ) {
F_35 ( V_95 , V_17 -> V_96 , V_97
L_16 , V_71 ) ;
F_104 ( V_17 , V_28 , V_263 ) ;
}
return V_71 ;
}
static void F_116 ( struct V_12 * V_17 ,
struct V_303 * V_114 )
{
struct V_304 V_285 = {
. V_130 = V_305 ,
. V_132 = V_114 -> V_132 ,
} ;
T_5 V_306 = F_113 ( V_114 -> V_200 ) ;
if ( F_115 ( V_17 , V_306 , & V_285 , sizeof V_285 ) )
F_35 ( V_95 , V_17 -> V_96 , V_97
L_17 ) ;
}
static void F_117 ( struct V_12 * V_17 ,
struct V_307 * V_114 )
{
struct V_308 V_285 = {
. V_130 = V_309 ,
. V_132 = V_114 -> V_132 ,
} ;
T_5 V_306 = F_113 ( V_114 -> V_200 ) ;
F_35 ( V_95 , V_17 -> V_96 , V_97
L_18 , F_45 ( V_114 -> V_310 ) ) ;
if ( F_115 ( V_17 , V_306 , & V_285 , sizeof V_285 ) )
F_35 ( V_95 , V_17 -> V_96 , V_97
L_19 ) ;
}
static void F_118 ( struct V_12 * V_17 , struct V_311 * V_312 )
{
struct V_156 * V_33 = V_17 -> V_23 -> V_32 -> V_33 ;
struct V_22 * V_28 = (struct V_22 * ) ( V_277 ) V_312 -> V_276 ;
int V_7 ;
T_1 V_130 ;
F_100 ( V_33 , V_28 -> V_31 , V_17 -> V_313 ,
V_197 ) ;
V_130 = * ( T_1 * ) V_28 -> V_29 ;
if ( 0 ) {
F_35 ( V_95 , V_17 -> V_96 ,
V_97 L_20 , V_130 ) ;
F_119 ( V_95 , L_21 , V_314 , 8 , 1 ,
V_28 -> V_29 , V_312 -> V_315 , true ) ;
}
switch ( V_130 ) {
case V_316 :
F_112 ( V_17 , V_28 -> V_29 ) ;
break;
case V_317 :
F_116 ( V_17 , V_28 -> V_29 ) ;
break;
case V_318 :
F_117 ( V_17 , V_28 -> V_29 ) ;
break;
case V_319 :
F_35 ( V_109 , V_17 -> V_96 ,
V_97 L_22 ) ;
break;
default:
F_35 ( V_109 , V_17 -> V_96 ,
V_97 L_23 , V_130 ) ;
break;
}
F_103 ( V_33 , V_28 -> V_31 , V_17 -> V_313 ,
V_197 ) ;
V_7 = F_110 ( V_17 , V_28 ) ;
if ( V_7 != 0 )
F_35 ( V_95 , V_17 -> V_96 ,
V_97 L_24 , V_7 ) ;
}
static void F_120 ( struct V_182 * V_183 )
{
struct V_12 * V_17 ;
V_17 = F_72 ( V_183 , struct V_12 , V_180 ) ;
if ( V_17 -> V_179 )
F_121 ( V_17 -> V_179 ) ;
}
static void F_122 ( enum V_320 V_321 , bool V_322 ,
struct V_12 * V_17 )
{
if ( V_17 -> V_155 && ! V_17 -> V_187 ) {
F_35 ( V_95 , V_17 -> V_96 ,
V_97 L_25 ,
V_322 ? L_26 : L_27 ,
V_321 ) ;
F_50 ( V_153 , & V_17 -> V_180 ) ;
}
V_17 -> V_187 = true ;
}
static void V_68 ( struct V_65 * V_323 , void * V_94 )
{
struct V_12 * V_17 = V_94 ;
struct V_311 V_312 ;
F_29 ( V_323 , V_74 ) ;
while ( F_123 ( V_323 , 1 , & V_312 ) > 0 ) {
if ( F_124 ( V_312 . V_91 == V_324 ) ) {
F_118 ( V_17 , & V_312 ) ;
} else {
F_122 ( V_312 . V_91 , false , V_17 ) ;
}
}
}
static void V_72 ( struct V_65 * V_323 , void * V_94 )
{
struct V_12 * V_17 = V_94 ;
struct V_311 V_312 ;
struct V_22 * V_28 ;
while ( F_123 ( V_323 , 1 , & V_312 ) > 0 ) {
if ( F_124 ( V_312 . V_91 == V_324 ) ) {
V_28 = (struct V_22 * ) ( V_277 ) V_312 . V_276 ;
F_87 ( & V_28 -> V_173 , & V_17 -> V_206 ) ;
} else {
F_122 ( V_312 . V_91 , true , V_17 ) ;
}
}
}
static int F_125 ( struct V_13 * V_174 , struct V_192 * V_193 )
{
struct V_12 * V_17 = F_5 ( V_174 ) ;
struct V_184 * V_179 = V_17 -> V_179 ;
struct V_158 * V_114 ;
struct V_22 * V_28 ;
struct V_238 * V_239 ;
struct V_156 * V_33 ;
unsigned long V_199 ;
int V_215 , V_202 ;
const bool V_325 = ! F_126 () && V_326 == V_174 -> V_327 ;
if ( V_325 )
F_127 ( & V_179 -> V_328 ) ;
V_202 = F_128 ( V_17 -> V_179 ) ;
if ( F_99 ( V_202 ) ) {
V_193 -> V_202 = V_202 ;
V_193 -> V_203 ( V_193 ) ;
goto V_329;
}
F_81 ( & V_17 -> V_150 , V_199 ) ;
V_28 = F_105 ( V_17 , V_330 ) ;
if ( ! V_28 )
goto V_331;
V_114 = F_107 ( & V_17 -> V_169 , struct V_158 , V_173 ) ;
F_68 ( & V_114 -> V_173 ) ;
F_82 ( & V_17 -> V_150 , V_199 ) ;
V_33 = V_17 -> V_23 -> V_32 -> V_33 ;
F_100 ( V_33 , V_28 -> V_31 , V_17 -> V_134 ,
V_165 ) ;
V_193 -> V_202 = 0 ;
V_193 -> V_301 = ( void * ) V_114 ;
V_239 = V_28 -> V_29 ;
memset ( V_239 , 0 , sizeof *V_239 ) ;
V_239 -> V_130 = V_332 ;
V_239 -> V_310 = F_89 ( ( T_7 ) V_193 -> V_333 -> V_310 << 48 ) ;
V_239 -> V_132 = V_114 -> V_172 ;
memcpy ( V_239 -> V_334 , V_193 -> V_335 , V_193 -> V_336 ) ;
V_114 -> V_193 = V_193 ;
V_114 -> V_239 = V_28 ;
V_215 = F_97 ( V_193 , V_17 , V_114 ) ;
if ( V_215 < 0 ) {
F_35 ( V_95 , V_17 -> V_96 ,
V_97 L_28 ) ;
goto V_337;
}
F_103 ( V_33 , V_28 -> V_31 , V_17 -> V_134 ,
V_165 ) ;
if ( F_108 ( V_17 , V_28 , V_215 ) ) {
F_35 ( V_95 , V_17 -> V_96 , V_97 L_29 ) ;
goto V_338;
}
V_329:
if ( V_325 )
F_129 ( & V_179 -> V_328 ) ;
return 0 ;
V_338:
F_75 ( V_193 , V_17 , V_114 ) ;
V_337:
F_104 ( V_17 , V_28 , V_330 ) ;
F_81 ( & V_17 -> V_150 , V_199 ) ;
F_87 ( & V_114 -> V_173 , & V_17 -> V_169 ) ;
V_331:
F_82 ( & V_17 -> V_150 , V_199 ) ;
if ( V_325 )
F_129 ( & V_179 -> V_328 ) ;
return V_339 ;
}
static int F_130 ( struct V_12 * V_17 )
{
int V_88 ;
V_17 -> V_89 = F_10 ( V_17 -> V_69 * sizeof( * V_17 -> V_89 ) ,
V_43 ) ;
if ( ! V_17 -> V_89 )
goto V_340;
V_17 -> V_90 = F_10 ( V_17 -> V_69 * sizeof( * V_17 -> V_90 ) ,
V_43 ) ;
if ( ! V_17 -> V_90 )
goto V_340;
for ( V_88 = 0 ; V_88 < V_17 -> V_69 ; ++ V_88 ) {
V_17 -> V_89 [ V_88 ] = F_8 ( V_17 -> V_23 ,
V_17 -> V_313 ,
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
F_87 ( & V_17 -> V_90 [ V_88 ] -> V_173 , & V_17 -> V_206 ) ;
}
return 0 ;
V_71:
for ( V_88 = 0 ; V_88 < V_17 -> V_69 ; ++ V_88 ) {
F_14 ( V_17 -> V_23 , V_17 -> V_89 [ V_88 ] ) ;
F_14 ( V_17 -> V_23 , V_17 -> V_90 [ V_88 ] ) ;
}
V_340:
F_13 ( V_17 -> V_90 ) ;
V_17 -> V_90 = NULL ;
F_13 ( V_17 -> V_89 ) ;
V_17 -> V_89 = NULL ;
return - V_44 ;
}
static T_8 F_131 ( struct V_40 * V_341 , int V_342 )
{
T_9 V_343 , V_344 ;
T_8 V_345 ;
F_61 ( ( V_342 & ( V_346 | V_347 ) ) !=
( V_346 | V_347 ) ) ;
V_343 = 4096 * ( 1ULL << V_341 -> V_348 ) ;
V_344 = V_341 -> V_349 * 4 * V_343 ;
F_132 ( V_344 , V_350 ) ;
V_345 = F_133 ( V_344 + 1000 ) ;
return V_345 ;
}
static void F_134 ( struct V_59 * V_62 ,
struct V_351 * V_352 ,
struct V_12 * V_17 )
{
struct V_40 * V_341 = NULL ;
int V_342 = 0 ;
int V_42 ;
int V_88 ;
if ( V_352 -> V_130 == V_353 ) {
V_17 -> V_313 = F_113 ( V_352 -> V_313 ) ;
V_17 -> V_201 = F_113 ( V_352 -> V_200 ) ;
V_17 -> V_96 -> V_354
= F_102 ( V_17 -> V_201 - V_266 ,
V_17 -> V_96 -> V_354 ) ;
V_17 -> V_96 -> V_355
= F_96 ( int , V_17 -> V_96 -> V_354 ,
V_17 -> V_96 -> V_355 ) ;
} else {
F_35 ( V_109 , V_17 -> V_96 ,
V_97 L_30 , V_352 -> V_130 ) ;
V_42 = - V_191 ;
goto error;
}
if ( ! V_17 -> V_89 ) {
V_42 = F_130 ( V_17 ) ;
if ( V_42 )
goto error;
}
V_42 = - V_44 ;
V_341 = F_9 ( sizeof *V_341 , V_43 ) ;
if ( ! V_341 )
goto error;
V_341 -> V_49 = V_356 ;
V_42 = F_135 ( V_62 , V_341 , & V_342 ) ;
if ( V_42 )
goto V_357;
V_42 = F_21 ( V_17 -> V_39 , V_341 , V_342 ) ;
if ( V_42 )
goto V_357;
for ( V_88 = 0 ; V_88 < V_17 -> V_69 ; V_88 ++ ) {
struct V_22 * V_28 = V_17 -> V_89 [ V_88 ] ;
V_42 = F_110 ( V_17 , V_28 ) ;
if ( V_42 )
goto V_357;
}
V_341 -> V_49 = V_358 ;
V_42 = F_135 ( V_62 , V_341 , & V_342 ) ;
if ( V_42 )
goto V_357;
V_17 -> V_345 = F_131 ( V_341 , V_342 ) ;
V_42 = F_21 ( V_17 -> V_39 , V_341 , V_342 ) ;
if ( V_42 )
goto V_357;
V_42 = F_136 ( V_62 , NULL , 0 ) ;
V_357:
F_13 ( V_341 ) ;
error:
V_17 -> V_91 = V_42 ;
}
static void F_137 ( struct V_59 * V_62 ,
struct V_359 * V_36 ,
struct V_12 * V_17 )
{
struct V_13 * V_174 = V_17 -> V_96 ;
struct V_360 * V_361 ;
int V_130 ;
switch ( V_36 -> V_111 . V_362 . V_363 ) {
case V_364 :
V_361 = V_36 -> V_111 . V_362 . V_365 ;
V_17 -> V_46 . V_366 = V_361 -> V_367 ;
V_17 -> V_46 . V_47 = V_361 -> V_368 ;
V_62 -> V_369 = F_113 ( V_361 -> V_370 ) & 0x00ffffff ;
memcpy ( V_17 -> V_46 . V_371 . V_372 , V_361 -> V_373 , 16 ) ;
V_17 -> V_91 = V_17 -> V_46 . V_366 ?
V_189 : V_188 ;
break;
case V_374 :
if ( F_7 ( V_17 ) ) {
memcpy ( V_17 -> V_46 . V_371 . V_372 ,
V_36 -> V_111 . V_362 . V_365 , 16 ) ;
F_35 ( V_147 , V_174 ,
V_97 L_31 ,
( unsigned long long ) F_45 ( V_17 -> V_46 . V_371 . V_142 . V_375 ) ,
( unsigned long long ) F_45 ( V_17 -> V_46 . V_371 . V_142 . V_143 ) ) ;
V_17 -> V_91 = V_188 ;
} else {
F_35 ( V_109 , V_174 ,
L_32 ) ;
V_17 -> V_91 = - V_191 ;
}
break;
case V_376 :
F_35 ( V_109 , V_174 ,
L_33 ) ;
V_17 -> V_91 = - V_191 ;
break;
case V_377 :
V_130 = * ( T_1 * ) V_36 -> V_119 ;
if ( V_130 == V_378 ) {
struct V_379 * V_380 = V_36 -> V_119 ;
T_6 V_363 = F_113 ( V_380 -> V_363 ) ;
if ( V_363 == V_381 )
F_35 ( V_109 , V_174 ,
V_97 L_34 ) ;
else
F_35 ( V_109 , V_174 ,
V_97 L_35 , V_363 ) ;
} else
F_35 ( V_109 , V_174 ,
L_36
L_37 , V_130 ) ;
V_17 -> V_91 = - V_191 ;
break;
case V_382 :
F_35 ( V_109 , V_174 , L_38 ) ;
V_17 -> V_91 = V_190 ;
break;
default:
F_35 ( V_109 , V_174 , L_39 ,
V_36 -> V_111 . V_362 . V_363 ) ;
V_17 -> V_91 = - V_191 ;
}
}
static int V_61 ( struct V_59 * V_62 , struct V_359 * V_36 )
{
struct V_12 * V_17 = V_62 -> V_37 ;
int V_383 = 0 ;
switch ( V_36 -> V_36 ) {
case V_384 :
F_35 ( V_147 , V_17 -> V_96 ,
V_97 L_40 ) ;
V_383 = 1 ;
V_17 -> V_91 = - V_191 ;
break;
case V_385 :
V_383 = 1 ;
F_134 ( V_62 , V_36 -> V_119 , V_17 ) ;
break;
case V_386 :
F_35 ( V_147 , V_17 -> V_96 , V_97 L_41 ) ;
V_383 = 1 ;
F_137 ( V_62 , V_36 , V_17 ) ;
break;
case V_387 :
F_35 ( V_109 , V_17 -> V_96 ,
V_97 L_42 ) ;
F_51 ( V_17 , false ) ;
if ( F_138 ( V_62 , NULL , 0 ) )
F_35 ( V_95 , V_17 -> V_96 ,
V_97 L_43 ) ;
F_50 ( V_153 , & V_17 -> V_180 ) ;
break;
case V_388 :
F_35 ( V_95 , V_17 -> V_96 ,
V_97 L_44 ) ;
V_17 -> V_91 = 0 ;
break;
case V_389 :
case V_390 :
case V_391 :
break;
default:
F_35 ( V_109 , V_17 -> V_96 ,
V_97 L_45 , V_36 -> V_36 ) ;
break;
}
if ( V_383 )
F_36 ( & V_17 -> V_98 ) ;
return 0 ;
}
static int
F_139 ( struct V_392 * V_393 , int V_394 )
{
if ( V_393 -> V_395 ) {
F_140 ( V_393 , V_394 ) ;
if ( V_394 )
F_141 ( V_393 , V_393 -> V_396 ) ;
else
F_142 ( V_393 , V_393 -> V_396 ) ;
} else
V_394 = 0 ;
return V_394 ;
}
static int
F_143 ( struct V_392 * V_393 , int V_397 , int V_363 )
{
struct V_13 * V_174 = V_393 -> V_14 ;
int V_398 ;
if ( V_363 == V_399 || V_363 == V_400 ) {
V_398 = V_174 -> V_354 ;
if ( ! V_393 -> V_395 )
V_398 = 1 ;
if ( V_397 > V_398 )
V_397 = V_398 ;
F_144 ( V_393 , F_145 ( V_393 ) , V_397 ) ;
} else if ( V_363 == V_401 )
F_146 ( V_393 , V_397 ) ;
else
return - V_402 ;
return V_393 -> V_396 ;
}
static int F_147 ( struct V_12 * V_17 ,
T_7 V_403 , unsigned int V_310 , T_1 V_404 )
{
struct V_184 * V_179 = V_17 -> V_179 ;
struct V_156 * V_33 = V_17 -> V_23 -> V_32 -> V_33 ;
struct V_22 * V_28 ;
struct V_405 * V_406 ;
if ( ! V_17 -> V_155 || V_17 -> V_187 )
return - 1 ;
F_38 ( & V_17 -> V_290 ) ;
F_127 ( & V_179 -> V_328 ) ;
F_48 ( & V_17 -> V_150 ) ;
V_28 = F_105 ( V_17 , V_265 ) ;
F_49 ( & V_17 -> V_150 ) ;
if ( ! V_28 ) {
F_129 ( & V_179 -> V_328 ) ;
return - 1 ;
}
F_100 ( V_33 , V_28 -> V_31 , sizeof *V_406 ,
V_165 ) ;
V_406 = V_28 -> V_29 ;
memset ( V_406 , 0 , sizeof *V_406 ) ;
V_406 -> V_130 = V_407 ;
V_406 -> V_310 = F_89 ( ( T_7 ) V_310 << 48 ) ;
V_406 -> V_132 = V_403 | V_286 ;
V_406 -> V_408 = V_404 ;
V_406 -> V_409 = V_403 ;
F_103 ( V_33 , V_28 -> V_31 , sizeof *V_406 ,
V_165 ) ;
if ( F_108 ( V_17 , V_28 , sizeof *V_406 ) ) {
F_104 ( V_17 , V_28 , V_265 ) ;
F_129 ( & V_179 -> V_328 ) ;
return - 1 ;
}
F_129 ( & V_179 -> V_328 ) ;
if ( ! F_148 ( & V_17 -> V_290 ,
F_133 ( V_410 ) ) )
return - 1 ;
return 0 ;
}
static int F_149 ( struct V_192 * V_193 )
{
struct V_12 * V_17 = F_5 ( V_193 -> V_333 -> V_14 ) ;
struct V_158 * V_114 = (struct V_158 * ) V_193 -> V_301 ;
int V_42 ;
F_35 ( V_95 , V_17 -> V_96 , L_46 ) ;
if ( ! V_114 || ! F_80 ( V_17 , V_114 , V_193 ) )
return V_411 ;
if ( F_147 ( V_17 , V_114 -> V_172 , V_193 -> V_333 -> V_310 ,
V_412 ) == 0 )
V_42 = V_411 ;
else if ( V_17 -> V_179 -> V_151 == V_413 )
V_42 = V_414 ;
else
V_42 = V_415 ;
F_83 ( V_17 , V_114 , V_193 , 0 ) ;
V_193 -> V_202 = V_416 << 16 ;
V_193 -> V_203 ( V_193 ) ;
return V_42 ;
}
static int F_150 ( struct V_192 * V_193 )
{
struct V_12 * V_17 = F_5 ( V_193 -> V_333 -> V_14 ) ;
int V_88 ;
F_35 ( V_95 , V_17 -> V_96 , L_47 ) ;
if ( F_147 ( V_17 , V_417 , V_193 -> V_333 -> V_310 ,
V_418 ) )
return V_415 ;
if ( V_17 -> V_287 )
return V_415 ;
for ( V_88 = 0 ; V_88 < V_17 -> V_160 ; ++ V_88 ) {
struct V_158 * V_114 = & V_17 -> V_159 [ V_88 ] ;
if ( V_114 -> V_193 && V_114 -> V_193 -> V_333 == V_193 -> V_333 )
F_84 ( V_17 , V_114 , V_205 << 16 ) ;
}
return V_411 ;
}
static int F_151 ( struct V_192 * V_193 )
{
struct V_12 * V_17 = F_5 ( V_193 -> V_333 -> V_14 ) ;
F_35 ( V_95 , V_17 -> V_96 , V_97 L_48 ) ;
return F_152 ( V_17 -> V_179 ) == 0 ? V_411 : V_415 ;
}
static int F_153 ( struct V_392 * V_393 )
{
struct V_13 * V_174 = V_393 -> V_14 ;
struct V_12 * V_17 = F_5 ( V_174 ) ;
struct V_419 * V_420 = V_393 -> V_419 ;
unsigned long V_348 ;
if ( V_393 -> type == V_421 ) {
V_348 = F_154 ( unsigned , 30 * V_422 , V_17 -> V_345 ) ;
F_155 ( V_420 , V_348 ) ;
}
return 0 ;
}
static T_10 F_156 ( struct V_333 * V_33 , struct V_175 * V_41 ,
char * V_29 )
{
struct V_12 * V_17 = F_5 ( F_157 ( V_33 ) ) ;
return sprintf ( V_29 , L_49 ,
( unsigned long long ) F_45 ( V_17 -> V_146 ) ) ;
}
static T_10 F_158 ( struct V_333 * V_33 , struct V_175 * V_41 ,
char * V_29 )
{
struct V_12 * V_17 = F_5 ( F_157 ( V_33 ) ) ;
return sprintf ( V_29 , L_49 ,
( unsigned long long ) F_45 ( V_17 -> V_21 ) ) ;
}
static T_10 F_159 ( struct V_333 * V_33 ,
struct V_175 * V_41 , char * V_29 )
{
struct V_12 * V_17 = F_5 ( F_157 ( V_33 ) ) ;
return sprintf ( V_29 , L_49 ,
( unsigned long long ) F_45 ( V_17 -> V_117 ) ) ;
}
static T_10 F_160 ( struct V_333 * V_33 , struct V_175 * V_41 ,
char * V_29 )
{
struct V_12 * V_17 = F_5 ( F_157 ( V_33 ) ) ;
return sprintf ( V_29 , L_50 , F_20 ( V_17 -> V_46 . V_47 ) ) ;
}
static T_10 F_161 ( struct V_333 * V_33 , struct V_175 * V_41 ,
char * V_29 )
{
struct V_12 * V_17 = F_5 ( F_157 ( V_33 ) ) ;
return sprintf ( V_29 , L_51 , V_17 -> V_46 . V_141 . V_372 ) ;
}
static T_10 F_162 ( struct V_333 * V_33 , struct V_175 * V_41 ,
char * V_29 )
{
struct V_12 * V_17 = F_5 ( F_157 ( V_33 ) ) ;
return sprintf ( V_29 , L_51 , V_17 -> V_46 . V_371 . V_372 ) ;
}
static T_10 F_163 ( struct V_333 * V_33 ,
struct V_175 * V_41 , char * V_29 )
{
struct V_12 * V_17 = F_5 ( F_157 ( V_33 ) ) ;
return sprintf ( V_29 , L_51 , V_17 -> V_423 ) ;
}
static T_10 F_164 ( struct V_333 * V_33 ,
struct V_175 * V_41 , char * V_29 )
{
struct V_12 * V_17 = F_5 ( F_157 ( V_33 ) ) ;
return sprintf ( V_29 , L_52 , V_17 -> V_201 ) ;
}
static T_10 F_165 ( struct V_333 * V_33 ,
struct V_175 * V_41 , char * V_29 )
{
struct V_12 * V_17 = F_5 ( F_157 ( V_33 ) ) ;
return sprintf ( V_29 , L_52 , V_17 -> V_267 ) ;
}
static T_10 F_166 ( struct V_333 * V_33 ,
struct V_175 * V_41 , char * V_29 )
{
struct V_12 * V_17 = F_5 ( F_157 ( V_33 ) ) ;
return sprintf ( V_29 , L_52 , V_17 -> V_23 -> V_45 ) ;
}
static T_10 F_167 ( struct V_333 * V_33 ,
struct V_175 * V_41 , char * V_29 )
{
struct V_12 * V_17 = F_5 ( F_157 ( V_33 ) ) ;
return sprintf ( V_29 , L_53 , V_17 -> V_23 -> V_32 -> V_33 -> V_424 ) ;
}
static T_10 F_168 ( struct V_333 * V_33 ,
struct V_175 * V_41 , char * V_29 )
{
struct V_12 * V_17 = F_5 ( F_157 ( V_33 ) ) ;
return sprintf ( V_29 , L_52 , V_17 -> V_70 ) ;
}
static T_10 F_169 ( struct V_333 * V_33 ,
struct V_175 * V_41 , char * V_29 )
{
struct V_12 * V_17 = F_5 ( F_157 ( V_33 ) ) ;
return sprintf ( V_29 , L_52 , V_17 -> V_127 ) ;
}
static T_10 F_170 ( struct V_333 * V_33 ,
struct V_175 * V_41 , char * V_29 )
{
struct V_12 * V_17 = F_5 ( F_157 ( V_33 ) ) ;
return sprintf ( V_29 , L_54 , V_17 -> V_170 ) ;
}
static T_10 F_171 ( struct V_333 * V_33 ,
struct V_175 * V_41 , char * V_29 )
{
struct V_12 * V_17 = F_5 ( F_157 ( V_33 ) ) ;
return sprintf ( V_29 , L_53 , V_17 -> V_254 ? L_55 : L_56 ) ;
}
static int F_172 ( struct V_23 * V_14 , struct V_12 * V_17 )
{
struct V_425 V_426 ;
struct V_184 * V_179 ;
sprintf ( V_17 -> V_16 , L_57 ,
( unsigned long long ) F_45 ( V_17 -> V_146 ) ) ;
if ( F_173 ( V_17 -> V_96 , V_14 -> V_32 -> V_33 -> V_427 ) )
return - V_428 ;
memcpy ( V_426 . V_429 , & V_17 -> V_146 , 8 ) ;
memcpy ( V_426 . V_429 + 8 , & V_17 -> V_21 , 8 ) ;
V_426 . V_430 = V_431 ;
V_179 = F_174 ( V_17 -> V_96 , & V_426 ) ;
if ( F_24 ( V_179 ) ) {
F_64 ( V_17 -> V_96 ) ;
return F_25 ( V_179 ) ;
}
V_179 -> V_185 = V_17 ;
V_17 -> V_179 = V_179 ;
F_67 ( & V_14 -> V_181 ) ;
F_57 ( & V_17 -> V_173 , & V_14 -> V_432 ) ;
F_69 ( & V_14 -> V_181 ) ;
V_17 -> V_151 = V_433 ;
F_175 ( & V_17 -> V_96 -> V_434 ,
0 , V_17 -> V_435 , V_436 , 0 ) ;
return 0 ;
}
static void F_176 ( struct V_333 * V_33 )
{
struct V_23 * V_14 =
F_72 ( V_33 , struct V_23 , V_33 ) ;
F_36 ( & V_14 -> V_437 ) ;
}
static bool F_177 ( struct V_23 * V_14 ,
struct V_12 * V_17 )
{
struct V_12 * V_438 ;
bool V_42 = false ;
if ( V_17 -> V_151 == V_152 )
goto V_8;
V_42 = true ;
F_67 ( & V_14 -> V_181 ) ;
F_178 (t, &host->target_list, list) {
if ( V_438 != V_17 &&
V_17 -> V_146 == V_438 -> V_146 &&
V_17 -> V_21 == V_438 -> V_21 &&
V_17 -> V_144 == V_438 -> V_144 ) {
V_42 = false ;
break;
}
}
F_69 ( & V_14 -> V_181 ) ;
V_8:
return V_42 ;
}
static int F_179 ( const char * V_29 , struct V_12 * V_17 )
{
char * V_439 , * V_440 ;
char * V_441 ;
char V_371 [ 3 ] ;
T_11 args [ V_442 ] ;
int V_443 = 0 ;
int V_444 ;
int V_42 = - V_247 ;
int V_88 ;
V_439 = F_180 ( V_29 , V_43 ) ;
if ( ! V_439 )
return - V_44 ;
V_440 = V_439 ;
while ( ( V_441 = F_181 ( & V_440 , L_58 ) ) != NULL ) {
if ( ! * V_441 )
continue;
V_444 = F_182 ( V_441 , V_445 , args ) ;
V_443 |= V_444 ;
switch ( V_444 ) {
case V_446 :
V_441 = F_183 ( args ) ;
if ( ! V_441 ) {
V_42 = - V_44 ;
goto V_8;
}
V_17 -> V_146 = F_89 ( F_184 ( V_441 , NULL , 16 ) ) ;
F_13 ( V_441 ) ;
break;
case V_447 :
V_441 = F_183 ( args ) ;
if ( ! V_441 ) {
V_42 = - V_44 ;
goto V_8;
}
V_17 -> V_21 = F_89 ( F_184 ( V_441 , NULL , 16 ) ) ;
F_13 ( V_441 ) ;
break;
case V_448 :
V_441 = F_183 ( args ) ;
if ( ! V_441 ) {
V_42 = - V_44 ;
goto V_8;
}
if ( strlen ( V_441 ) != 32 ) {
F_185 ( L_59 , V_441 ) ;
F_13 ( V_441 ) ;
goto V_8;
}
for ( V_88 = 0 ; V_88 < 16 ; ++ V_88 ) {
F_186 ( V_371 , V_441 + V_88 * 2 , 3 ) ;
V_17 -> V_46 . V_371 . V_372 [ V_88 ] = F_187 ( V_371 , NULL , 16 ) ;
}
F_13 ( V_441 ) ;
memcpy ( V_17 -> V_423 , V_17 -> V_46 . V_371 . V_372 , 16 ) ;
break;
case V_449 :
if ( F_188 ( args , & V_444 ) ) {
F_185 ( L_60 , V_441 ) ;
goto V_8;
}
V_17 -> V_46 . V_47 = F_44 ( V_444 ) ;
break;
case V_450 :
V_441 = F_183 ( args ) ;
if ( ! V_441 ) {
V_42 = - V_44 ;
goto V_8;
}
V_17 -> V_117 = F_89 ( F_184 ( V_441 , NULL , 16 ) ) ;
V_17 -> V_46 . V_117 = V_17 -> V_117 ;
F_13 ( V_441 ) ;
break;
case V_451 :
if ( F_189 ( args , & V_444 ) ) {
F_185 ( L_61 , V_441 ) ;
goto V_8;
}
V_17 -> V_96 -> V_452 = V_444 ;
break;
case V_453 :
if ( F_189 ( args , & V_444 ) || V_444 < 1 ) {
F_185 ( L_62 , V_441 ) ;
goto V_8;
}
V_17 -> V_96 -> V_354 = V_444 ;
V_17 -> V_69 = V_444 + V_454 +
V_266 ;
if ( ! ( V_443 & V_455 ) )
V_17 -> V_96 -> V_355 = V_444 ;
break;
case V_455 :
if ( F_189 ( args , & V_444 ) || V_444 < 1 ) {
F_185 ( L_63 ,
V_441 ) ;
goto V_8;
}
V_17 -> V_96 -> V_355 = V_444 ;
break;
case V_456 :
if ( F_188 ( args , & V_444 ) ) {
F_185 ( L_64 , V_441 ) ;
goto V_8;
}
if ( V_444 != V_139 &&
V_444 != V_457 ) {
F_185 ( L_65 ,
V_444 , V_139 ,
V_457 ) ;
goto V_8;
}
V_17 -> V_138 = V_444 ;
break;
case V_458 :
V_441 = F_183 ( args ) ;
if ( ! V_441 ) {
V_42 = - V_44 ;
goto V_8;
}
V_17 -> V_144 = F_89 ( F_184 ( V_441 , NULL , 16 ) ) ;
F_13 ( V_441 ) ;
break;
case V_459 :
if ( F_189 ( args , & V_444 ) || V_444 < 1 || V_444 > 255 ) {
F_185 ( L_66 ,
V_441 ) ;
goto V_8;
}
V_17 -> V_170 = V_444 ;
break;
case V_460 :
if ( F_189 ( args , & V_444 ) ) {
F_185 ( L_67 , V_441 ) ;
goto V_8;
}
V_17 -> V_254 = ! ! V_444 ;
break;
case V_461 :
if ( F_189 ( args , & V_444 ) || V_444 < 1 ||
V_444 > V_462 ) {
F_185 ( L_68 ,
V_441 ) ;
goto V_8;
}
V_17 -> V_463 = V_444 ;
break;
case V_464 :
if ( F_189 ( args , & V_444 ) || V_444 < 0 ) {
F_185 ( L_69 , V_441 ) ;
goto V_8;
}
V_17 -> V_70 = V_444 ;
break;
case V_465 :
if ( F_189 ( args , & V_444 ) || V_444 < 2 || V_444 > 7 ) {
F_185 ( L_70 ,
V_441 ) ;
goto V_8;
}
V_17 -> V_127 = V_444 ;
break;
default:
F_185 ( L_71 ,
V_441 ) ;
goto V_8;
}
}
if ( ( V_443 & V_466 ) == V_466 )
V_42 = 0 ;
else
for ( V_88 = 0 ; V_88 < F_190 ( V_445 ) ; ++ V_88 )
if ( ( V_445 [ V_88 ] . V_444 & V_466 ) &&
! ( V_445 [ V_88 ] . V_444 & V_443 ) )
F_185 ( L_72 ,
V_445 [ V_88 ] . V_467 ) ;
if ( V_17 -> V_96 -> V_355 > V_17 -> V_96 -> V_354
&& ( V_443 & V_455 ) )
F_185 ( L_73 ,
V_17 -> V_96 -> V_355 ,
V_17 -> V_96 -> V_354 ) ;
V_8:
F_13 ( V_439 ) ;
return V_42 ;
}
static T_10 F_191 ( struct V_333 * V_33 ,
struct V_175 * V_41 ,
const char * V_29 , T_2 V_241 )
{
struct V_23 * V_14 =
F_72 ( V_33 , struct V_23 , V_33 ) ;
struct V_13 * V_468 ;
struct V_12 * V_17 ;
struct V_156 * V_157 = V_14 -> V_32 -> V_33 ;
int V_42 ;
V_468 = F_192 ( & V_469 ,
sizeof ( struct V_12 ) ) ;
if ( ! V_468 )
return - V_44 ;
V_468 -> V_470 = V_471 ;
V_468 -> V_472 = 0 ;
V_468 -> V_473 = 1 ;
V_468 -> V_474 = V_475 ;
V_468 -> V_476 = sizeof ( (struct V_238 * ) ( void * ) 0L ) -> V_334 ;
V_17 = F_5 ( V_468 ) ;
V_17 -> V_138 = V_457 ;
V_17 -> V_96 = V_468 ;
V_17 -> V_23 = V_14 ;
V_17 -> V_274 = V_14 -> V_32 -> V_477 -> V_274 ;
V_17 -> V_210 = V_14 -> V_32 -> V_477 -> V_210 ;
V_17 -> V_170 = V_478 ;
V_17 -> V_463 = V_479 ? : V_478 ;
V_17 -> V_254 = V_254 ;
V_17 -> V_127 = 7 ;
V_17 -> V_69 = V_480 ;
V_42 = F_179 ( V_29 , V_17 ) ;
if ( V_42 )
goto V_71;
V_17 -> V_160 = V_17 -> V_69 - V_266 ;
if ( ! F_177 ( V_17 -> V_23 , V_17 ) ) {
F_35 ( V_207 , V_17 -> V_96 ,
V_97 L_74 ,
F_45 ( V_17 -> V_146 ) ,
F_45 ( V_17 -> V_21 ) ,
F_45 ( V_17 -> V_144 ) ) ;
V_42 = - V_481 ;
goto V_71;
}
if ( ! V_14 -> V_32 -> V_223 && ! V_17 -> V_254 &&
V_17 -> V_170 < V_17 -> V_463 ) {
F_185 ( L_75 ) ;
V_17 -> V_463 = V_17 -> V_170 ;
}
V_468 -> V_463 = V_17 -> V_463 ;
V_17 -> V_164 = V_17 -> V_463 *
sizeof ( struct V_211 ) ;
V_17 -> V_134 = sizeof ( struct V_238 ) +
sizeof ( struct V_242 ) +
V_17 -> V_170 * sizeof ( struct V_211 ) ;
F_193 ( & V_17 -> V_180 , F_120 ) ;
F_193 ( & V_17 -> V_154 , F_71 ) ;
F_194 ( & V_17 -> V_150 ) ;
F_56 ( & V_17 -> V_206 ) ;
V_42 = F_55 ( V_17 ) ;
if ( V_42 )
goto V_482;
F_195 ( V_157 , V_14 -> V_45 , 0 , & V_17 -> V_46 . V_141 ) ;
F_35 ( V_147 , V_17 -> V_96 , V_97
L_76
L_77 ,
( unsigned long long ) F_45 ( V_17 -> V_146 ) ,
( unsigned long long ) F_45 ( V_17 -> V_21 ) ,
F_20 ( V_17 -> V_46 . V_47 ) ,
( unsigned long long ) F_45 ( V_17 -> V_117 ) ,
V_17 -> V_46 . V_371 . V_372 ) ;
V_42 = F_27 ( V_17 ) ;
if ( V_42 )
goto V_482;
V_42 = F_22 ( V_17 ) ;
if ( V_42 )
goto V_483;
V_42 = F_74 ( V_17 ) ;
if ( V_42 ) {
F_35 ( V_95 , V_17 -> V_96 ,
V_97 L_78 ) ;
goto V_484;
}
V_42 = F_172 ( V_14 , V_17 ) ;
if ( V_42 )
goto V_485;
return V_241 ;
V_485:
F_52 ( V_17 ) ;
V_484:
F_26 ( V_17 -> V_62 ) ;
V_483:
F_33 ( V_17 ) ;
V_482:
F_54 ( V_17 ) ;
V_71:
F_70 ( V_468 ) ;
return V_42 ;
}
static T_10 F_196 ( struct V_333 * V_33 , struct V_175 * V_41 ,
char * V_29 )
{
struct V_23 * V_14 = F_72 ( V_33 , struct V_23 , V_33 ) ;
return sprintf ( V_29 , L_53 , V_14 -> V_32 -> V_33 -> V_424 ) ;
}
static T_10 F_197 ( struct V_333 * V_33 , struct V_175 * V_41 ,
char * V_29 )
{
struct V_23 * V_14 = F_72 ( V_33 , struct V_23 , V_33 ) ;
return sprintf ( V_29 , L_52 , V_14 -> V_45 ) ;
}
static struct V_23 * F_198 ( struct V_167 * V_333 , T_1 V_45 )
{
struct V_23 * V_14 ;
V_14 = F_10 ( sizeof *V_14 , V_43 ) ;
if ( ! V_14 )
return NULL ;
F_56 ( & V_14 -> V_432 ) ;
F_194 ( & V_14 -> V_181 ) ;
F_38 ( & V_14 -> V_437 ) ;
V_14 -> V_32 = V_333 ;
V_14 -> V_45 = V_45 ;
V_14 -> V_33 . V_486 = & V_487 ;
V_14 -> V_33 . V_488 = V_333 -> V_33 -> V_427 ;
F_199 ( & V_14 -> V_33 , L_79 , V_333 -> V_33 -> V_424 , V_45 ) ;
if ( F_200 ( & V_14 -> V_33 ) )
goto V_489;
if ( F_201 ( & V_14 -> V_33 , & V_490 ) )
goto V_491;
if ( F_201 ( & V_14 -> V_33 , & V_492 ) )
goto V_491;
if ( F_201 ( & V_14 -> V_33 , & V_493 ) )
goto V_491;
return V_14 ;
V_491:
F_202 ( & V_14 -> V_33 ) ;
V_489:
F_13 ( V_14 ) ;
return NULL ;
}
static void F_203 ( struct V_156 * V_333 )
{
struct V_167 * V_32 ;
struct V_494 * V_495 ;
struct V_496 V_497 ;
struct V_23 * V_14 ;
int V_498 , V_499 , V_500 , V_501 , V_441 ;
V_495 = F_9 ( sizeof *V_495 , V_43 ) ;
if ( ! V_495 )
return;
if ( F_204 ( V_333 , V_495 ) ) {
F_185 ( L_80 , V_333 -> V_424 ) ;
goto V_502;
}
V_32 = F_9 ( sizeof *V_32 , V_43 ) ;
if ( ! V_32 )
goto V_502;
V_499 = F_205 ( 12 , F_206 ( V_495 -> V_503 ) - 1 ) ;
V_32 -> V_236 = 1 << V_499 ;
V_32 -> V_234 = ~ ( ( T_7 ) V_32 -> V_236 - 1 ) ;
V_32 -> V_235 = V_32 -> V_236 * V_171 ;
F_56 ( & V_32 -> V_504 ) ;
V_32 -> V_33 = V_333 ;
V_32 -> V_85 = F_207 ( V_333 ) ;
if ( F_24 ( V_32 -> V_85 ) )
goto V_505;
V_32 -> V_477 = F_208 ( V_32 -> V_85 ,
V_506 |
V_52 |
V_53 ) ;
if ( F_24 ( V_32 -> V_477 ) )
goto V_507;
for ( V_498 = V_171 ;
V_498 >= V_508 ;
V_498 /= 2 , V_32 -> V_235 /= 2 ) {
memset ( & V_497 , 0 , sizeof V_497 ) ;
V_497 . V_509 = V_510 ;
V_497 . V_511 = V_512 ;
V_497 . V_513 = 1 ;
V_497 . V_498 = V_498 ;
V_497 . V_514 = V_499 ;
V_497 . V_515 = ( V_506 |
V_53 |
V_52 ) ;
V_32 -> V_223 = F_209 ( V_32 -> V_85 , & V_497 ) ;
if ( ! F_24 ( V_32 -> V_223 ) )
break;
}
if ( F_24 ( V_32 -> V_223 ) )
V_32 -> V_223 = NULL ;
if ( V_333 -> V_516 == V_517 ) {
V_500 = 0 ;
V_501 = 0 ;
} else {
V_500 = 1 ;
V_501 = V_333 -> V_518 ;
}
for ( V_441 = V_500 ; V_441 <= V_501 ; ++ V_441 ) {
V_14 = F_198 ( V_32 , V_441 ) ;
if ( V_14 )
F_57 ( & V_14 -> V_173 , & V_32 -> V_504 ) ;
}
F_210 ( V_333 , & V_519 , V_32 ) ;
goto V_502;
V_507:
F_211 ( V_32 -> V_85 ) ;
V_505:
F_13 ( V_32 ) ;
V_502:
F_13 ( V_495 ) ;
}
static void F_212 ( struct V_156 * V_333 )
{
struct V_167 * V_32 ;
struct V_23 * V_14 , * V_520 ;
struct V_12 * V_17 ;
V_32 = F_213 ( V_333 , & V_519 ) ;
if ( ! V_32 )
return;
F_214 (host, tmp_host, &srp_dev->dev_list, list) {
F_202 ( & V_14 -> V_33 ) ;
F_40 ( & V_14 -> V_437 ) ;
F_67 ( & V_14 -> V_181 ) ;
F_178 (target, &host->target_list, list)
F_47 ( V_17 ) ;
F_69 ( & V_14 -> V_181 ) ;
F_215 ( V_153 ) ;
F_13 ( V_14 ) ;
}
if ( V_32 -> V_223 )
F_216 ( V_32 -> V_223 ) ;
F_217 ( V_32 -> V_477 ) ;
F_211 ( V_32 -> V_85 ) ;
F_13 ( V_32 ) ;
}
static int T_12 F_218 ( void )
{
int V_42 ;
F_219 ( F_220 ( struct V_311 , V_276 ) < sizeof( void * ) ) ;
if ( V_521 ) {
F_185 ( L_81 ) ;
if ( ! V_478 )
V_478 = V_521 ;
}
if ( ! V_478 )
V_478 = V_522 ;
if ( V_478 > 255 ) {
F_185 ( L_82 ) ;
V_478 = 255 ;
}
if ( ! V_479 )
V_479 = V_478 ;
else if ( V_479 < V_478 ) {
F_185 ( L_83 ,
V_478 ) ;
V_479 = V_478 ;
}
V_471 =
F_221 ( & V_523 ) ;
if ( ! V_471 )
return - V_44 ;
V_42 = F_222 ( & V_487 ) ;
if ( V_42 ) {
F_223 ( L_84 ) ;
F_224 ( V_471 ) ;
return V_42 ;
}
F_225 ( & V_101 ) ;
V_42 = F_226 ( & V_519 ) ;
if ( V_42 ) {
F_223 ( L_85 ) ;
F_224 ( V_471 ) ;
F_227 ( & V_101 ) ;
F_228 ( & V_487 ) ;
return V_42 ;
}
return 0 ;
}
static void T_13 F_229 ( void )
{
F_230 ( & V_519 ) ;
F_227 ( & V_101 ) ;
F_228 ( & V_487 ) ;
F_224 ( V_471 ) ;
}
