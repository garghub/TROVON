static int F_1 ( struct V_1 * V_2 )
{
F_2 ( V_3 , V_4 ) ;
F_3 ( V_3 , V_5 , V_6 ) ;
F_3 ( V_3 , V_7 , 0 ) ;
F_3 ( V_3 , V_8 ,
V_2 -> V_9 -> V_10 -> V_10 ) ;
F_3 ( V_3 , V_11 , V_2 -> V_9 -> V_12 ) ;
return F_4 ( V_2 , V_13 , V_3 , sizeof( V_3 ) ,
NULL , 0 , NULL ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
F_2 ( V_3 , V_14 ) ;
F_3 ( V_3 , V_5 , V_15 ) ;
F_3 ( V_3 , V_7 , 0 ) ;
return F_4 ( V_2 , V_13 , V_3 , sizeof( V_3 ) ,
NULL , 0 , NULL ) ;
}
static void F_6 ( struct V_16 * V_17 )
{
struct V_18 * V_19 ;
while ( ( V_19 = F_7 ( V_17 ) ) ) {
F_8 () ;
F_9 ( V_19 ) ;
F_10 () ;
}
}
static void F_11 ( struct V_1 * V_2 )
{
F_12 ( V_2 , V_20 , V_2 -> V_21 ,
L_1
L_2 ) ;
}
static void F_13 ( struct V_1 * V_2 ,
struct V_22 * V_23 )
{
struct V_22 V_24 ;
struct V_25 V_26 ;
struct V_27 * V_28 = V_2 -> V_9 ;
struct V_25 V_29 ;
int * V_30 = V_28 -> V_29 . V_31 ;
F_14 ( & V_24 ) ;
V_29 = V_24 . V_32 ;
V_26 = V_24 . V_32 ;
F_15 ( & V_26 , V_33 ) ;
while ( ( F_16 ( & V_24 . V_32 , & V_26 ) < 0 ) &&
F_17 ( * V_30 ) ) {
struct V_25 V_34 ;
unsigned int V_35 ;
V_34 = V_24 . V_32 ;
F_15 ( & V_34 , V_36 ) ;
do {
F_14 ( & V_24 ) ;
} while ( ( F_16 ( & V_24 . V_32 , & V_34 ) < 0 ) &&
F_17 ( * V_30 ) );
V_35 = ( V_24 . V_32 . V_37 << V_38 |
V_24 . V_32 . V_39 ) ;
V_2 -> type -> V_40 ( V_2 , V_35 ) ;
}
* V_23 = V_24 ;
}
static int F_18 ( struct V_1 * V_2 , unsigned int V_41 )
{
struct V_27 * V_28 = V_2 -> V_9 ;
F_2 ( V_42 , V_43 ) ;
T_1 V_44 ;
int V_45 ;
unsigned long V_46 ;
struct V_22 V_23 = {} ;
unsigned int V_47 = 0 ;
int * V_29 = V_28 -> V_29 . V_31 ;
F_3 ( V_42 , V_5 , V_48 ) ;
F_3 ( V_42 , V_7 , 0 ) ;
F_3 ( V_42 , V_49 ,
V_41 ) ;
F_19 ( V_42 , V_50 ,
V_28 -> V_29 . V_51 ) ;
F_17 ( * V_29 ) = 0 ;
V_45 = F_20 ( V_2 , V_13 , V_42 ,
V_52 ) ;
F_21 ( V_45 ) ;
V_46 = V_53 + F_22 ( V_54 ) ;
while ( ! F_17 ( * V_29 ) && ( F_23 ( V_53 , V_46 ) ) ) {
F_24 ( 20 ) ;
V_47 ++ ;
}
if ( F_17 ( * V_29 ) )
F_13 ( V_2 , & V_23 ) ;
V_45 = F_25 ( V_2 , V_13 ,
V_52 ,
V_42 , sizeof( V_42 ) ,
& V_44 ) ;
if ( V_45 == 0 )
V_45 = F_26 ( V_2 , V_42 , V_44 ,
& V_23 ) ;
return V_45 ;
}
static int F_27 ( struct V_1 * V_2 , struct V_18 * V_19 )
{
struct V_27 * V_9 = V_2 -> V_9 ;
struct V_55 V_56 ;
int V_45 = - V_57 ;
F_2 ( V_58 , V_59 ) ;
T_1 V_60 ;
F_3 ( V_9 -> V_61 , V_5 , V_62 ) ;
F_3 ( V_9 -> V_61 , V_7 , 0 ) ;
F_3 ( V_9 -> V_61 , V_63 , V_19 -> V_60 ) ;
if ( F_28 ( V_19 ) -> V_64 != 0 ) {
V_45 = F_29 ( V_19 ) ;
if ( V_45 != 0 )
goto V_65;
}
if ( V_19 -> V_66 == V_67 ) {
V_45 = F_30 ( V_19 ) ;
if ( V_45 != 0 )
goto V_65;
}
F_31 ( V_19 ,
F_32 ( V_9 -> V_61 ,
V_68 ) ,
V_19 -> V_60 ) ;
V_45 = F_4 ( V_2 , V_13 ,
V_9 -> V_61 , F_33 ( V_19 -> V_60 ) ,
V_58 , sizeof( V_58 ) , & V_60 ) ;
if ( V_45 != 0 )
goto V_65;
memset ( & V_56 , 0 , sizeof( V_56 ) ) ;
V_56 . V_69 = F_34 (
F_35 ( V_58 , V_70 ) ,
F_35 ( V_58 , V_71 ) ) ;
F_36 ( V_19 , & V_56 ) ;
V_45 = 0 ;
V_65:
F_37 ( V_19 ) ;
return V_45 ;
}
static void F_38 ( struct V_1 * V_2 )
{
struct V_27 * V_28 = V_2 -> V_9 ;
struct V_72 * V_73 ;
struct V_72 * V_74 ;
F_39 ( & V_28 -> V_75 ) ;
if ( ! F_40 ( & V_28 -> V_76 ) ) {
F_41 (cursor, next, &ptp->evt_list) {
struct V_77 * V_78 ;
V_78 = F_42 ( V_73 , struct V_77 ,
V_79 ) ;
if ( F_43 ( V_53 , V_78 -> V_80 ) ) {
F_44 ( & V_78 -> V_79 , & V_28 -> V_81 ) ;
F_45 ( V_2 , V_82 , V_2 -> V_21 ,
L_3 ) ;
}
}
}
F_46 ( & V_28 -> V_75 ) ;
}
static enum V_83 F_47 ( struct V_1 * V_2 ,
struct V_18 * V_19 )
{
struct V_27 * V_28 = V_2 -> V_9 ;
bool V_84 ;
struct V_72 * V_73 ;
struct V_72 * V_74 ;
struct V_85 * V_86 ;
enum V_83 V_45 = V_87 ;
F_39 ( & V_28 -> V_75 ) ;
V_84 = ! F_40 ( & V_28 -> V_76 ) ;
F_46 ( & V_28 -> V_75 ) ;
if ( ! V_84 )
return V_87 ;
V_86 = (struct V_85 * ) V_19 -> V_88 ;
F_39 ( & V_28 -> V_75 ) ;
F_41 (cursor, next, &ptp->evt_list) {
struct V_77 * V_78 ;
V_78 = F_42 ( V_73 , struct V_77 , V_79 ) ;
if ( ( V_78 -> V_89 == V_86 -> V_90 [ 0 ] ) &&
( V_78 -> V_91 == V_86 -> V_90 [ 1 ] ) ) {
struct V_55 * V_56 ;
V_56 = F_48 ( V_19 ) ;
V_56 -> V_69 = V_78 -> V_92 ;
V_86 -> V_93 = V_94 ;
V_45 = V_94 ;
F_44 ( & V_78 -> V_79 , & V_28 -> V_81 ) ;
break;
}
}
F_46 ( & V_28 -> V_75 ) ;
return V_45 ;
}
static bool F_49 ( struct V_1 * V_2 , struct V_16 * V_17 )
{
struct V_27 * V_28 = V_2 -> V_9 ;
bool V_45 = false ;
struct V_18 * V_19 ;
while ( ( V_19 = F_7 ( & V_28 -> V_95 ) ) ) {
struct V_85 * V_86 ;
V_86 = (struct V_85 * ) V_19 -> V_88 ;
if ( V_86 -> V_93 == V_96 ) {
F_50 ( V_17 , V_19 ) ;
} else if ( F_47 ( V_2 , V_19 ) ==
V_94 ) {
V_45 = true ;
F_50 ( V_17 , V_19 ) ;
} else if ( F_43 ( V_53 , V_86 -> V_80 ) ) {
V_86 -> V_93 = V_97 ;
F_45 ( V_2 , V_98 , V_2 -> V_21 ,
L_4 ) ;
F_50 ( V_17 , V_19 ) ;
} else {
F_51 ( & V_28 -> V_95 , V_19 ) ;
break;
}
}
return V_45 ;
}
static inline void F_52 ( struct V_1 * V_2 , struct V_18 * V_19 )
{
F_8 () ;
F_9 ( V_19 ) ;
F_10 () ;
}
static int F_53 ( struct V_1 * V_2 )
{
struct V_27 * V_28 = V_2 -> V_9 ;
struct V_99 V_100 ;
int V_45 ;
V_28 -> V_101 = false ;
F_54 ( & V_100 , V_102 , 0 ,
F_55 (
F_56 ( V_28 -> V_10 ) ) ) ;
V_45 = F_57 ( & V_100 , V_103 ,
F_58 ( V_104 ) ,
F_59 ( V_105 ) ) ;
if ( V_45 != 0 )
return V_45 ;
V_45 = F_60 ( V_2 , & V_100 , true ) ;
if ( V_45 < 0 )
return V_45 ;
V_28 -> V_106 = V_45 ;
F_54 ( & V_100 , V_102 , 0 ,
F_55 (
F_56 ( V_28 -> V_10 ) ) ) ;
V_45 = F_57 ( & V_100 , V_103 ,
F_58 ( V_104 ) ,
F_59 ( V_107 ) ) ;
if ( V_45 != 0 )
goto V_65;
V_45 = F_60 ( V_2 , & V_100 , true ) ;
if ( V_45 < 0 )
goto V_65;
V_28 -> V_108 = V_45 ;
V_45 = F_1 ( V_2 ) ;
if ( V_45 != 0 )
goto V_109;
V_28 -> V_110 = 0 ;
V_28 -> V_111 = 0 ;
V_28 -> V_112 = true ;
return 0 ;
V_109:
F_61 ( V_2 , V_102 ,
V_28 -> V_108 ) ;
V_65:
F_61 ( V_2 , V_102 ,
V_28 -> V_106 ) ;
return V_45 ;
}
static int F_62 ( struct V_1 * V_2 )
{
struct V_27 * V_28 = V_2 -> V_9 ;
int V_45 = F_5 ( V_2 ) ;
struct V_72 * V_73 ;
struct V_72 * V_74 ;
if ( V_28 -> V_112 ) {
F_61 ( V_2 , V_102 ,
V_28 -> V_108 ) ;
F_61 ( V_2 , V_102 ,
V_28 -> V_106 ) ;
V_28 -> V_112 = false ;
}
F_6 ( & V_2 -> V_9 -> V_95 ) ;
F_63 ( & V_2 -> V_9 -> V_113 ) ;
F_39 ( & V_2 -> V_9 -> V_75 ) ;
F_41 (cursor, next, &efx->ptp_data->evt_list) {
F_44 ( V_73 , & V_2 -> V_9 -> V_81 ) ;
}
F_46 ( & V_2 -> V_9 -> V_75 ) ;
return V_45 ;
}
static void F_64 ( struct V_114 * V_115 )
{
struct V_27 * V_28 =
F_65 ( V_115 , struct V_27 , V_116 ) ;
struct V_1 * V_2 = V_28 -> V_10 -> V_2 ;
struct V_117 V_118 ;
if ( F_18 ( V_2 , V_119 ) )
return;
V_118 . type = V_120 ;
V_118 . V_121 = V_28 -> V_122 ;
V_117 ( V_28 -> V_123 , & V_118 ) ;
}
static void F_66 ( struct V_114 * V_115 )
{
struct V_27 * V_9 =
F_65 ( V_115 , struct V_27 , V_115 ) ;
struct V_1 * V_2 = V_9 -> V_10 -> V_2 ;
struct V_18 * V_19 ;
struct V_16 V_124 ;
if ( V_9 -> V_101 ) {
F_62 ( V_2 ) ;
F_53 ( V_2 ) ;
return;
}
F_38 ( V_2 ) ;
F_67 ( & V_124 ) ;
if ( F_49 ( V_2 , & V_124 ) ||
! F_68 ( & V_9 -> V_113 ) ) {
while ( ( V_19 = F_7 ( & V_9 -> V_113 ) ) )
F_27 ( V_2 , V_19 ) ;
}
while ( ( V_19 = F_69 ( & V_124 ) ) )
F_52 ( V_2 , V_19 ) ;
}
static int F_70 ( struct V_125 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_27 * V_28 ;
int V_45 = 0 ;
unsigned int V_126 ;
V_10 -> V_127 = 0 ;
V_10 -> V_128 . V_129 = 0 ;
V_28 = F_71 ( sizeof( struct V_27 ) , V_130 ) ;
V_2 -> V_9 = V_28 ;
if ( ! V_2 -> V_9 )
return - V_131 ;
V_45 = F_72 ( V_2 , & V_28 -> V_29 , sizeof( int ) , V_130 ) ;
if ( V_45 != 0 )
goto V_132;
V_28 -> V_10 = V_10 ;
F_73 ( & V_28 -> V_95 ) ;
F_73 ( & V_28 -> V_113 ) ;
V_28 -> V_133 = F_74 ( L_5 ) ;
if ( ! V_28 -> V_133 ) {
V_45 = - V_131 ;
goto V_109;
}
F_75 ( & V_28 -> V_115 , F_66 ) ;
V_28 -> V_134 . V_135 = 0 ;
V_28 -> V_134 . V_136 = V_137 ;
V_28 -> V_134 . V_138 = V_139 ;
F_76 ( & V_28 -> V_76 ) ;
F_76 ( & V_28 -> V_81 ) ;
F_77 ( & V_28 -> V_75 ) ;
for ( V_126 = 0 ; V_126 < V_140 ; V_126 ++ )
F_78 ( & V_28 -> V_141 [ V_126 ] . V_79 , & V_28 -> V_81 ) ;
V_28 -> V_142 . V_143 = V_144 ;
snprintf ( V_28 -> V_142 . V_145 ,
sizeof( V_28 -> V_142 . V_145 ) ,
L_6 , V_2 -> V_21 -> V_146 ) ;
V_28 -> V_142 . V_147 = V_148 ;
V_28 -> V_142 . V_149 = 0 ;
V_28 -> V_142 . V_150 = 0 ;
V_28 -> V_142 . V_151 = 0 ;
V_28 -> V_142 . V_152 = 1 ;
V_28 -> V_142 . V_153 = V_154 ;
V_28 -> V_142 . V_155 = V_156 ;
V_28 -> V_142 . V_157 = V_158 ;
V_28 -> V_142 . V_159 = V_160 ;
V_28 -> V_142 . V_161 = V_162 ;
V_28 -> V_123 = F_79 ( & V_28 -> V_142 ,
& V_2 -> V_163 -> V_164 ) ;
if ( F_80 ( V_28 -> V_123 ) ) {
V_45 = F_81 ( V_28 -> V_123 ) ;
goto V_165;
}
F_75 ( & V_28 -> V_116 , F_64 ) ;
V_28 -> V_166 = F_74 ( L_7 ) ;
if ( ! V_28 -> V_166 ) {
V_45 = - V_131 ;
goto V_167;
}
V_28 -> V_168 = false ;
return 0 ;
V_167:
F_82 ( V_2 -> V_9 -> V_123 ) ;
V_165:
F_83 ( V_2 -> V_9 -> V_133 ) ;
V_109:
F_84 ( V_2 , & V_28 -> V_29 ) ;
V_132:
F_85 ( V_2 -> V_9 ) ;
V_2 -> V_9 = NULL ;
return V_45 ;
}
static void F_86 ( struct V_125 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
if ( ! V_2 -> V_9 )
return;
( void ) F_5 ( V_10 -> V_2 ) ;
F_87 ( & V_2 -> V_9 -> V_115 ) ;
F_87 ( & V_2 -> V_9 -> V_116 ) ;
F_63 ( & V_2 -> V_9 -> V_95 ) ;
F_63 ( & V_2 -> V_9 -> V_113 ) ;
F_82 ( V_2 -> V_9 -> V_123 ) ;
F_83 ( V_2 -> V_9 -> V_133 ) ;
F_83 ( V_2 -> V_9 -> V_166 ) ;
F_84 ( V_2 , & V_2 -> V_9 -> V_29 ) ;
F_85 ( V_2 -> V_9 ) ;
}
static void F_88 ( struct V_125 * V_10 ,
char * V_169 , T_1 V_60 )
{
snprintf ( V_169 , V_60 , L_8 , V_10 -> V_2 -> V_145 ) ;
}
bool F_89 ( struct V_1 * V_2 , struct V_18 * V_19 )
{
return V_2 -> V_9 &&
V_2 -> V_9 -> V_170 &&
V_19 -> V_60 >= V_171 &&
V_19 -> V_60 <= V_172 &&
F_90 ( V_19 -> V_173 == F_59 ( V_174 ) ) &&
F_91 ( V_19 ) -> V_173 == V_103 &&
F_92 ( V_19 ) -> V_175 == F_59 ( V_105 ) ;
}
static bool F_93 ( struct V_125 * V_10 , struct V_18 * V_19 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_27 * V_28 = V_2 -> V_9 ;
struct V_85 * V_86 = (struct V_85 * ) V_19 -> V_88 ;
T_2 * V_176 , * V_177 ;
unsigned int V_178 ;
V_86 -> V_80 = V_53 + F_22 ( V_179 ) ;
if ( V_28 -> V_12 == V_180 ) {
if ( ! F_94 ( V_19 , V_181 ) ) {
return false ;
}
V_178 = F_95 ( * ( V_182 * ) & V_19 -> V_183 [ V_184 ] ) ;
if ( V_178 != V_185 ) {
return false ;
}
V_176 = V_19 -> V_183 + V_186 ;
V_177 = V_19 -> V_183 + V_186 + 3 ;
} else {
if ( ! F_94 ( V_19 , V_187 ) ) {
return false ;
}
V_178 = V_19 -> V_183 [ V_188 ] ;
if ( ( V_178 & V_189 ) != V_190 ) {
return false ;
}
V_177 = V_19 -> V_183 + V_191 + 5 ;
if ( V_28 -> V_12 == V_192 ) {
V_176 = V_19 -> V_183 + V_191 + 2 ;
} else {
V_176 = V_19 -> V_183 + V_191 + 0 ;
F_96 ( V_28 -> V_12 != V_193 ) ;
}
}
if ( F_95 ( * ( V_182 * ) & V_19 -> V_183 [ V_194 ] ) == V_105 ) {
struct V_55 * V_56 ;
V_86 -> V_93 = V_87 ;
V_56 = F_48 ( V_19 ) ;
memset ( V_56 , 0 , sizeof( * V_56 ) ) ;
F_97 ( V_195 != V_196 ) ;
F_97 ( V_197 != V_198 ) ;
V_86 -> V_90 [ 0 ] = ( V_176 [ 0 ] |
( V_176 [ 1 ] << 8 ) |
( V_176 [ 2 ] << 16 ) |
( V_177 [ 0 ] << 24 ) ) ;
V_86 -> V_90 [ 1 ] = ( V_177 [ 1 ] |
( V_177 [ 2 ] << 8 ) |
( V_19 -> V_183 [ V_195 +
V_197 - 1 ] <<
16 ) ) ;
} else {
V_86 -> V_93 = V_96 ;
}
F_98 ( & V_28 -> V_95 , V_19 ) ;
F_99 ( V_28 -> V_133 , & V_28 -> V_115 ) ;
return true ;
}
int F_100 ( struct V_1 * V_2 , struct V_18 * V_19 )
{
struct V_27 * V_28 = V_2 -> V_9 ;
F_98 ( & V_28 -> V_113 , V_19 ) ;
if ( ( F_92 ( V_19 ) -> V_175 == F_59 ( V_105 ) ) &&
( V_19 -> V_60 <= V_172 ) )
F_101 ( V_19 ) ;
F_99 ( V_28 -> V_133 , & V_28 -> V_115 ) ;
return V_199 ;
}
static int F_102 ( struct V_1 * V_2 , bool V_200 ,
unsigned int V_201 )
{
if ( ( V_200 != V_2 -> V_9 -> V_170 ) ||
( V_200 && ( V_2 -> V_9 -> V_12 != V_201 ) ) ) {
int V_45 ;
if ( V_200 ) {
if ( V_2 -> V_9 -> V_170 &&
( V_2 -> V_9 -> V_12 != V_201 ) ) {
V_2 -> V_9 -> V_170 = false ;
V_45 = F_62 ( V_2 ) ;
if ( V_45 != 0 )
return V_45 ;
}
V_2 -> V_9 -> V_12 = V_201 ;
V_45 = F_53 ( V_2 ) ;
if ( V_45 == 0 ) {
V_45 = F_18 ( V_2 ,
V_119 * 2 ) ;
if ( V_45 != 0 )
F_62 ( V_2 ) ;
}
} else {
V_45 = F_62 ( V_2 ) ;
}
if ( V_45 != 0 )
return V_45 ;
V_2 -> V_9 -> V_170 = V_200 ;
}
return 0 ;
}
static int F_103 ( struct V_1 * V_2 , struct V_202 * V_203 )
{
bool V_200 = false ;
unsigned int V_201 ;
int V_45 ;
if ( V_203 -> V_135 )
return - V_204 ;
if ( ( V_203 -> V_136 != V_137 ) &&
( V_203 -> V_136 != V_205 ) )
return - V_206 ;
V_201 = V_2 -> V_9 -> V_12 ;
switch ( V_203 -> V_138 ) {
case V_139 :
break;
case V_207 :
case V_208 :
case V_209 :
V_203 -> V_138 = V_207 ;
V_201 = V_180 ;
V_200 = true ;
break;
case V_210 :
case V_211 :
case V_212 :
V_203 -> V_138 = V_210 ;
V_201 = V_193 ;
V_200 = true ;
break;
case V_213 :
case V_214 :
case V_215 :
case V_216 :
case V_217 :
case V_218 :
return - V_206 ;
break;
default:
return - V_206 ;
}
if ( V_203 -> V_136 != V_137 )
V_200 = true ;
V_45 = F_102 ( V_2 , V_200 , V_201 ) ;
if ( ( V_45 != 0 ) && ( V_201 == V_193 ) )
V_45 = F_102 ( V_2 , V_200 , V_192 ) ;
if ( V_45 != 0 )
return V_45 ;
V_2 -> V_9 -> V_134 = * V_203 ;
return 0 ;
}
void F_104 ( struct V_1 * V_2 , struct V_219 * V_220 )
{
struct V_27 * V_28 = V_2 -> V_9 ;
if ( ! V_28 )
return;
V_220 -> V_221 |= ( V_222 |
V_223 |
V_224 ) ;
V_220 -> V_225 = F_105 ( V_28 -> V_123 ) ;
V_220 -> V_226 = 1 << V_137 | 1 << V_205 ;
V_220 -> V_227 = ( 1 << V_139 |
1 << V_207 |
1 << V_208 |
1 << V_209 |
1 << V_210 |
1 << V_211 |
1 << V_212 ) ;
}
int F_106 ( struct V_1 * V_2 , struct V_228 * V_229 , int V_230 )
{
struct V_202 V_134 ;
int V_45 ;
if ( ! V_2 -> V_9 )
return - V_231 ;
if ( F_107 ( & V_134 , V_229 -> V_232 , sizeof( V_134 ) ) )
return - V_233 ;
V_45 = F_103 ( V_2 , & V_134 ) ;
if ( V_45 != 0 )
return V_45 ;
return F_108 ( V_229 -> V_232 , & V_134 , sizeof( V_134 ) )
? - V_233 : 0 ;
}
static void F_109 ( struct V_1 * V_2 , int V_234 )
{
struct V_27 * V_28 = V_2 -> V_9 ;
F_12 ( V_2 , V_82 , V_2 -> V_21 ,
L_9 ,
V_28 -> V_110 , V_234 ) ;
V_28 -> V_101 = true ;
F_99 ( V_28 -> V_133 , & V_28 -> V_115 ) ;
}
static void F_110 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
struct V_77 * V_78 = NULL ;
if ( V_28 -> V_110 != 3 ) {
F_109 ( V_2 , 3 ) ;
return;
}
F_39 ( & V_28 -> V_75 ) ;
if ( ! F_40 ( & V_28 -> V_81 ) ) {
V_78 = F_111 ( & V_28 -> V_81 ,
struct V_77 , V_79 ) ;
F_112 ( & V_78 -> V_79 ) ;
V_78 -> V_89 = F_113 ( V_28 -> V_235 [ 2 ] , V_236 ) ;
V_78 -> V_91 = ( F_113 ( V_28 -> V_235 [ 2 ] ,
V_237 ) |
( F_113 ( V_28 -> V_235 [ 1 ] ,
V_237 ) << 8 ) |
( F_113 ( V_28 -> V_235 [ 0 ] ,
V_237 ) << 16 ) ) ;
V_78 -> V_92 = F_34 (
F_113 ( V_28 -> V_235 [ 0 ] , V_236 ) ,
F_113 ( V_28 -> V_235 [ 1 ] , V_236 ) ) ;
V_78 -> V_80 = V_53 + F_22 ( V_179 ) ;
F_114 ( & V_78 -> V_79 , & V_28 -> V_76 ) ;
F_99 ( V_28 -> V_133 , & V_28 -> V_115 ) ;
} else {
F_12 ( V_2 , V_98 , V_2 -> V_21 , L_10 ) ;
}
F_46 ( & V_28 -> V_75 ) ;
}
static void F_115 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
int V_238 = F_113 ( V_28 -> V_235 [ 0 ] , V_236 ) ;
if ( V_28 -> V_110 != 1 ) {
F_109 ( V_2 , 1 ) ;
return;
}
F_12 ( V_2 , V_82 , V_2 -> V_21 , L_11 , V_238 ) ;
}
static void F_116 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
if ( V_28 -> V_168 )
F_99 ( V_28 -> V_166 , & V_28 -> V_116 ) ;
}
void F_117 ( struct V_1 * V_2 , T_3 * V_239 )
{
struct V_27 * V_28 = V_2 -> V_9 ;
int V_238 = F_113 ( * V_239 , V_240 ) ;
if ( ! V_28 -> V_170 )
return;
if ( V_28 -> V_110 == 0 ) {
V_28 -> V_241 = V_238 ;
} else if ( V_28 -> V_241 != V_238 ) {
F_12 ( V_2 , V_82 , V_2 -> V_21 ,
L_12 , V_238 ) ;
V_28 -> V_110 = 0 ;
}
V_28 -> V_235 [ V_28 -> V_110 ++ ] = * V_239 ;
if ( ! F_118 ( * V_239 , V_242 ) ) {
switch ( V_238 ) {
case V_243 :
F_110 ( V_2 , V_28 ) ;
break;
case V_244 :
F_115 ( V_2 , V_28 ) ;
break;
case V_245 :
F_116 ( V_2 , V_28 ) ;
break;
default:
F_12 ( V_2 , V_82 , V_2 -> V_21 ,
L_13 , V_238 ) ;
break;
}
V_28 -> V_110 = 0 ;
} else if ( V_246 == V_28 -> V_110 ) {
F_12 ( V_2 , V_82 , V_2 -> V_21 ,
L_14 ) ;
V_28 -> V_110 = 0 ;
}
}
static int V_154 ( struct V_247 * V_28 , T_4 V_248 )
{
struct V_27 * V_9 = F_65 ( V_28 ,
struct V_27 ,
V_142 ) ;
struct V_1 * V_2 = V_9 -> V_10 -> V_2 ;
F_2 ( V_249 , V_250 ) ;
T_5 V_251 ;
int V_45 ;
if ( V_248 > V_148 )
V_248 = V_148 ;
else if ( V_248 < - V_148 )
V_248 = - V_148 ;
V_251 = ( ( ( T_5 ) V_248 * V_252 ) >>
( V_253 + V_254 ) ) ;
F_3 ( V_249 , V_5 , V_255 ) ;
F_3 ( V_249 , V_7 , 0 ) ;
F_19 ( V_249 , V_256 , V_251 ) ;
F_3 ( V_249 , V_257 , 0 ) ;
F_3 ( V_249 , V_258 , 0 ) ;
V_45 = F_4 ( V_2 , V_13 , V_249 , sizeof( V_249 ) ,
NULL , 0 , NULL ) ;
if ( V_45 != 0 )
return V_45 ;
V_9 -> V_111 = V_248 ;
return 0 ;
}
static int V_156 ( struct V_247 * V_28 , T_5 V_248 )
{
struct V_27 * V_9 = F_65 ( V_28 ,
struct V_27 ,
V_142 ) ;
struct V_1 * V_2 = V_9 -> V_10 -> V_2 ;
struct V_25 V_259 = F_119 ( V_248 ) ;
F_2 ( V_3 , V_250 ) ;
F_3 ( V_3 , V_5 , V_255 ) ;
F_3 ( V_3 , V_7 , 0 ) ;
F_19 ( V_3 , V_256 , 0 ) ;
F_3 ( V_3 , V_257 , ( V_260 ) V_259 . V_37 ) ;
F_3 ( V_3 , V_258 , ( V_260 ) V_259 . V_39 ) ;
return F_4 ( V_2 , V_13 , V_3 , sizeof( V_3 ) ,
NULL , 0 , NULL ) ;
}
static int V_158 ( struct V_247 * V_28 , struct V_25 * V_261 )
{
struct V_27 * V_9 = F_65 ( V_28 ,
struct V_27 ,
V_142 ) ;
struct V_1 * V_2 = V_9 -> V_10 -> V_2 ;
F_2 ( V_3 , V_262 ) ;
F_2 ( V_263 , V_264 ) ;
int V_45 ;
F_3 ( V_3 , V_5 , V_265 ) ;
F_3 ( V_3 , V_7 , 0 ) ;
V_45 = F_4 ( V_2 , V_13 , V_3 , sizeof( V_3 ) ,
V_263 , sizeof( V_263 ) , NULL ) ;
if ( V_45 != 0 )
return V_45 ;
V_261 -> V_37 = F_35 ( V_263 , V_266 ) ;
V_261 -> V_39 = F_35 ( V_263 , V_267 ) ;
return 0 ;
}
static int V_160 ( struct V_247 * V_28 ,
const struct V_25 * V_268 )
{
int V_45 ;
struct V_25 V_269 ;
struct V_25 V_248 ;
V_45 = V_158 ( V_28 , & V_269 ) ;
if ( V_45 != 0 )
return V_45 ;
V_248 = F_120 ( * V_268 , V_269 ) ;
V_45 = V_156 ( V_28 , F_121 ( & V_248 ) ) ;
if ( V_45 != 0 )
return V_45 ;
return 0 ;
}
static int V_162 ( struct V_247 * V_28 ,
struct V_270 * V_271 ,
int V_161 )
{
struct V_27 * V_9 = F_65 ( V_28 ,
struct V_27 ,
V_142 ) ;
if ( V_271 -> type != V_272 )
return - V_231 ;
V_9 -> V_168 = ! ! V_161 ;
return 0 ;
}
void F_122 ( struct V_1 * V_2 )
{
if ( F_5 ( V_2 ) == 0 )
V_2 -> V_273 [ V_274 ] =
& V_275 ;
}
