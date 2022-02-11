int F_1 ( struct V_1 * V_2 ,
T_1 * V_3 ,
bool V_4 ,
T_2 * V_5 ,
T_1 V_6 )
{
int V_7 ;
int V_8 ;
T_1 V_9 [ 4 ] ;
if ( V_4 ) {
memset ( V_9 , 0 , sizeof( V_9 ) ) ;
V_9 [ 0 ] = * V_3 ;
} else {
memcpy ( V_9 , V_3 , sizeof( V_9 ) ) ;
}
for ( V_7 = 0 ; ( T_1 ) V_7 < V_2 -> V_10 ; V_7 ++ )
if ( memcmp ( V_2 -> V_11 [ V_7 ] . V_3 , V_9 , sizeof( V_9 ) ) == 0 )
break;
switch ( V_6 ) {
case V_12 :
if ( V_7 != V_2 -> V_10 )
return - 1 ;
V_7 = 0 ;
V_8 = F_2 ( V_2 , V_2 -> V_13 ,
V_2 -> V_10 ,
( T_1 * ) & V_7 ,
& V_2 -> V_14 ) ;
if ( V_8 )
return V_8 ;
memcpy ( V_2 -> V_11 [ V_7 ] . V_3 , V_9 , sizeof( V_9 ) ) ;
F_3 ( V_2 -> V_11 [ V_7 ] . V_5 , V_5 ) ;
break;
case V_15 :
if ( V_7 == V_2 -> V_10 )
return - 1 ;
break;
case V_16 :
if ( V_7 == V_2 -> V_10 )
return - 1 ;
memset ( V_2 -> V_11 [ V_7 ] . V_3 , 0 ,
sizeof( V_2 -> V_11 [ V_7 ] . V_3 ) ) ;
F_4 ( V_2 -> V_11 [ V_7 ] . V_5 ) ;
F_5 ( V_2 , V_2 -> V_13 , V_7 ) ;
break;
default:
return - 1 ;
}
return V_7 ;
}
inline void F_6 ( struct V_17 * V_18 , T_1 V_19 , T_1 V_20 )
{
F_7 ( V_20 , V_18 -> V_21 + V_19 ) ;
}
inline T_1 F_8 ( struct V_17 * V_18 , T_1 V_19 )
{
return F_9 ( V_18 -> V_21 + V_19 ) ;
}
int F_10 ( struct V_22 * V_23 ,
unsigned long V_24 ,
void * V_25 )
{
struct V_26 * V_27 = V_25 ;
struct V_28 * V_29 = V_27 -> V_30 -> V_31 ;
struct V_28 * V_32 ;
struct V_28 * V_33 ;
struct V_1 * V_2 ;
struct V_34 * V_35 ;
T_1 V_36 ;
T_1 V_6 = V_12 ;
V_35 = F_11 ( V_29 ) ;
if ( ! V_35 )
return V_37 ;
V_2 = & V_35 -> V_38 ;
V_32 = V_2 -> V_39 -> V_32 ;
V_33 = F_12 ( V_32 ) ;
if ( V_32 != V_29 )
return V_37 ;
if ( V_33 )
V_36 = F_13 (
( (struct V_40 * ) V_33 -> V_41 ) -> V_42 -> V_43 ) ;
else
V_36 = F_13 ( V_27 -> V_43 ) ;
switch ( V_24 ) {
case V_44 :
V_6 = V_16 ;
case V_45 :
case V_46 :
F_14 ( V_2 ,
V_32 -> V_47 ,
& V_36 ,
true ,
V_6 ) ;
F_15 ( V_2 , V_32 , & V_36 , true ,
( V_6 == V_12 ) ? true : false ) ;
break;
default:
break;
}
return V_37 ;
}
int F_16 ( struct V_22 * V_23 ,
unsigned long V_24 ,
void * V_25 )
{
struct V_48 * V_27 = (struct V_48 * ) V_25 ;
struct V_28 * V_29 = V_27 -> V_49 -> V_31 ;
struct V_28 * V_32 ;
struct V_1 * V_2 ;
struct V_34 * V_35 ;
T_1 V_50 [ 4 ] ;
T_1 V_6 = V_12 ;
V_35 = F_11 ( V_29 ) ;
if ( ! V_35 )
return V_37 ;
V_2 = & V_35 -> V_38 ;
V_32 = V_2 -> V_39 -> V_32 ;
if ( V_32 != V_29 )
return V_37 ;
F_17 ( V_50 , V_27 -> V_51 . V_52 . V_53 ) ;
switch ( V_24 ) {
case V_44 :
V_6 = V_16 ;
case V_45 :
case V_46 :
F_14 ( V_2 ,
V_32 -> V_47 ,
V_50 ,
false ,
V_6 ) ;
F_15 ( V_2 , V_32 , V_50 , false ,
( V_6 == V_12 ) ? true : false ) ;
break;
default:
break;
}
return V_37 ;
}
int F_18 ( struct V_22 * V_23 , unsigned long V_24 , void * V_25 )
{
struct V_54 * V_55 = V_25 ;
struct V_1 * V_2 ;
struct V_34 * V_56 ;
T_3 * V_57 ;
T_1 V_36 [ 4 ] ;
switch ( V_24 ) {
case V_58 :
V_56 = F_11 ( (struct V_28 * ) V_55 -> V_31 ) ;
if ( ! V_56 )
return V_37 ;
V_2 = & V_56 -> V_38 ;
V_57 = ( T_3 * ) V_55 -> V_59 ;
F_17 ( V_36 , V_57 ) ;
if ( V_55 -> V_60 & V_61 ) {
F_14 ( V_2 ,
V_55 -> V_62 ,
V_36 ,
false ,
V_12 ) ;
} else {
F_14 ( V_2 ,
V_55 -> V_62 ,
V_36 ,
false ,
V_16 ) ;
}
break;
default:
break;
}
return V_37 ;
}
struct V_63 * F_19 ( struct V_64 * V_65 , bool V_66 )
{
struct V_63 * V_67 = NULL ;
unsigned long V_68 ;
F_20 ( & V_65 -> V_69 , V_68 ) ;
if ( ! F_21 ( & V_65 -> V_70 ) ) {
V_67 = F_22 ( V_65 -> V_70 . V_71 ,
struct V_63 , V_72 ) ;
F_23 ( & V_67 -> V_72 ) ;
}
F_24 ( & V_65 -> V_69 , V_68 ) ;
if ( ! V_67 ) {
V_67 = F_25 ( sizeof( * V_67 ) , V_73 ) ;
if ( V_67 ) {
V_67 -> V_74 = true ;
F_26 ( & V_67 -> V_72 ) ;
F_27 ( & V_67 -> V_75 ) ;
}
}
if ( ! V_67 ) {
F_28 ( L_1 ) ;
return NULL ;
}
if ( V_66 ) {
F_29 ( & V_67 -> V_76 , 2 ) ;
V_67 -> V_77 = true ;
} else {
F_29 ( & V_67 -> V_76 , 1 ) ;
}
return V_67 ;
}
void F_30 ( struct V_64 * V_65 , struct V_63 * V_67 )
{
unsigned long V_68 ;
if ( V_67 -> V_74 ) {
F_31 ( V_67 ) ;
} else {
V_67 -> V_78 = false ;
V_67 -> V_79 = NULL ;
V_67 -> V_77 = false ;
F_20 ( & V_65 -> V_69 , V_68 ) ;
F_32 ( & V_67 -> V_72 , & V_65 -> V_70 ) ;
F_24 ( & V_65 -> V_69 , V_68 ) ;
}
}
void F_33 ( struct V_64 * V_65 ,
struct V_63 * V_67 )
{
if ( F_34 ( & V_67 -> V_76 ) )
F_30 ( V_65 , V_67 ) ;
}
static void F_35 ( struct V_63 * V_67 , T_1 V_80 )
{
struct V_81 * V_82 = (struct V_81 * ) V_67 -> V_83 ;
struct V_84 * V_85 = (struct V_84 * ) V_82 -> V_86 ;
struct V_1 * V_2 ;
T_1 V_87 = V_85 -> V_88 . V_87 ;
V_2 = V_85 -> V_2 ;
F_36 ( V_85 -> V_89 , V_2 ) ;
F_37 ( V_2 , V_85 , V_87 ) ;
F_38 ( V_2 ) ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_63 * V_67 )
{
struct V_90 * V_91 = & V_67 -> V_91 ;
struct V_64 * V_92 = & V_2 -> V_65 ;
bool V_93 = false ;
int V_94 = 0 ;
int V_95 = 0 ;
V_95 = F_40 ( V_67 -> V_75 ,
V_67 -> V_78 ,
V_96 ) ;
if ( ! V_95 ) {
F_28 ( L_2 ,
V_91 -> V_97 , V_95 ) ;
V_94 = - V_98 ;
if ( ! V_2 -> V_99 ) {
V_2 -> V_99 = true ;
F_41 ( V_2 ) ;
}
goto V_100;
}
V_93 = V_67 -> V_101 . error ;
if ( V_93 ) {
F_28 ( L_3 ,
V_91 -> V_97 , V_67 -> V_101 . V_102 ,
V_67 -> V_101 . V_103 ) ;
V_94 = - V_104 ;
goto V_100;
}
V_100:
F_33 ( V_92 , V_67 ) ;
return V_94 ;
}
enum V_105 F_42 ( struct V_1 * V_2 ,
struct V_63
* V_67 )
{
struct V_106 * V_31 = & V_2 -> V_107 ;
enum V_105 V_108 ;
struct V_90 * V_91 = & V_67 -> V_91 ;
int V_94 = 0 ;
if ( V_2 -> V_99 ) {
F_30 ( & V_2 -> V_65 , V_67 ) ;
return V_109 ;
}
V_108 = F_43 ( V_31 , V_91 ) ;
if ( V_108 ) {
F_28 ( L_4 , V_91 -> V_97 ) ;
F_30 ( & V_2 -> V_65 , V_67 ) ;
return V_108 ;
}
if ( V_67 -> V_77 )
V_94 = F_39 ( V_2 , V_67 ) ;
if ( V_94 )
V_108 = V_109 ;
return V_108 ;
}
void F_44 ( struct V_1 * V_2 )
{
F_45 ( & V_2 -> V_110 ) ;
}
void F_38 ( struct V_1 * V_2 )
{
if ( ! F_46 ( & V_2 -> V_110 ) )
return;
F_47 ( & V_2 -> V_111 ) ;
}
void F_48 ( struct V_112 * V_89 )
{
F_49 ( & V_89 -> V_113 ) ;
}
void F_36 ( struct V_112 * V_89 , struct V_1 * V_2 )
{
if ( ! F_34 ( & V_89 -> V_113 ) )
return;
F_5 ( V_2 , V_2 -> V_114 , V_89 -> V_115 . V_116 ) ;
F_31 ( V_89 ) ;
}
void F_50 ( struct V_117 * V_88 )
{
struct V_84 * V_85 = (struct V_84 * ) V_88 ;
F_49 ( & V_85 -> V_76 ) ;
}
void F_51 ( struct V_117 * V_88 )
{
struct V_84 * V_85 ;
enum V_105 V_108 ;
struct V_63 * V_67 ;
struct V_90 * V_118 ;
struct V_1 * V_2 ;
T_1 V_87 ;
unsigned long V_68 ;
V_85 = F_52 ( V_88 ) ;
V_2 = V_85 -> V_2 ;
F_20 ( & V_2 -> V_119 , V_68 ) ;
if ( ! F_34 ( & V_85 -> V_76 ) ) {
F_24 ( & V_2 -> V_119 , V_68 ) ;
return;
}
V_87 = V_85 -> V_88 . V_87 ;
V_2 -> V_120 [ V_87 ] = NULL ;
F_24 ( & V_2 -> V_119 , V_68 ) ;
V_67 = F_19 ( & V_2 -> V_65 , false ) ;
if ( ! V_67 )
return;
V_67 -> V_79 = F_35 ;
V_67 -> V_83 = ( void * ) & V_85 -> V_121 ;
V_118 = & V_67 -> V_91 ;
V_118 -> V_97 = V_122 ;
V_118 -> V_123 = 1 ;
V_118 -> V_124 . V_125 . V_126 . V_82 = & V_85 -> V_121 ;
V_118 -> V_124 . V_125 . V_126 . V_127 = ( V_128 ) V_67 ;
V_118 -> V_124 . V_125 . V_126 . V_129 = true ;
V_108 = F_42 ( V_2 , V_67 ) ;
if ( V_108 )
F_28 ( L_5 ) ;
}
struct V_117 * F_53 ( struct V_130 * V_38 , int V_131 )
{
struct V_1 * V_2 = F_54 ( V_38 ) ;
if ( ( V_131 < V_132 ) || ( V_131 >= V_2 -> V_133 ) )
return NULL ;
return & V_2 -> V_120 [ V_131 ] -> V_88 ;
}
void F_55 ( struct V_106 * V_31 ,
enum V_134 V_135 ,
char * V_136 ,
T_4 * V_137 ,
T_1 V_138 )
{
T_1 V_139 ;
if ( ! ( V_31 -> V_140 & V_135 ) )
return;
F_56 ( V_31 , V_135 , L_6 , V_136 ) ;
F_56 ( V_31 , V_135 , L_7 , V_137 ,
( unsigned long long ) F_57 ( V_137 ) ) ;
for ( V_139 = 0 ; V_139 < V_138 ; V_139 += 8 )
F_56 ( V_31 , V_135 , L_8 , V_139 , V_137 [ V_139 / 8 ] ) ;
}
T_2 T_5 * F_58 ( void * V_141 )
{
struct V_106 * V_31 = (struct V_106 * ) V_141 ;
return V_31 -> V_18 -> V_21 ;
}
void * F_59 ( struct V_142 * V_72 )
{
struct V_142 * V_143 ;
if ( F_21 ( V_72 ) )
return NULL ;
V_143 = ( void * ) V_72 -> V_71 ;
F_60 ( V_143 ) ;
return ( void * ) V_143 ;
}
enum V_105 F_61 ( struct V_17 * V_18 ,
struct V_144 * V_145 ,
T_4 V_138 ,
T_1 V_146 )
{
struct V_147 * V_148 = (struct V_147 * ) V_18 -> V_149 ;
if ( ! V_145 )
return V_150 ;
V_145 -> V_138 = F_62 ( V_138 , V_146 ) ;
V_145 -> V_151 = F_63 ( & V_148 -> V_31 , V_145 -> V_138 ,
( V_152 * ) & V_145 -> V_153 , V_154 ) ;
if ( ! V_145 -> V_151 )
return V_155 ;
return 0 ;
}
void F_64 ( struct V_17 * V_18 , struct V_144 * V_145 )
{
struct V_147 * V_148 = (struct V_147 * ) V_18 -> V_149 ;
if ( ! V_145 || ! V_145 -> V_151 )
return;
F_65 ( & V_148 -> V_31 , V_145 -> V_138 ,
V_145 -> V_151 , ( V_152 ) V_145 -> V_153 ) ;
V_145 -> V_151 = NULL ;
}
enum V_105 F_66 ( struct V_17 * V_18 ,
struct V_156 * V_145 ,
T_1 V_138 )
{
if ( ! V_145 )
return V_150 ;
V_145 -> V_138 = V_138 ;
V_145 -> V_151 = F_25 ( V_138 , V_154 ) ;
if ( V_145 -> V_151 )
return 0 ;
else
return V_155 ;
}
enum V_105 F_67 ( struct V_17 * V_18 ,
struct V_156 * V_145 )
{
if ( ! V_145 )
return V_150 ;
F_31 ( V_145 -> V_151 ) ;
return 0 ;
}
enum V_105 F_68 ( struct V_106 * V_31 ,
struct V_157 * V_158 )
{
enum V_105 V_108 ;
struct V_63 * V_67 ;
struct V_90 * V_118 ;
struct V_1 * V_2 = (struct V_1 * ) V_31 -> V_159 ;
V_67 = F_19 ( & V_2 -> V_65 , true ) ;
if ( ! V_67 )
return V_155 ;
V_118 = & V_67 -> V_91 ;
memcpy ( & V_118 -> V_124 . V_125 . V_160 . V_91 , V_158 ,
sizeof( V_118 -> V_124 . V_125 . V_160 . V_91 ) ) ;
V_118 -> V_97 = V_161 ;
V_118 -> V_123 = 1 ;
V_118 -> V_124 . V_125 . V_160 . V_31 = V_31 ;
V_118 -> V_124 . V_125 . V_160 . V_127 = ( V_128 ) V_67 ;
V_108 = F_42 ( V_2 , V_67 ) ;
if ( V_108 )
F_28 ( L_9 ) ;
return V_108 ;
}
void F_69 ( struct V_106 * V_31 , struct V_81 * V_82 , bool V_162 )
{
struct V_1 * V_2 = (struct V_1 * ) V_31 -> V_159 ;
struct V_63 * V_67 ;
struct V_163 * V_65 = V_31 -> V_65 ;
struct V_90 * V_118 ;
enum V_105 V_108 ;
V_67 = F_19 ( & V_2 -> V_65 , false ) ;
if ( ! V_67 )
return;
V_118 = & V_67 -> V_91 ;
V_118 -> V_97 = ( V_162 ) ? V_164 : V_165 ;
V_118 -> V_124 . V_125 . V_166 . V_65 = V_65 ;
V_118 -> V_124 . V_125 . V_166 . V_82 = V_82 ;
V_118 -> V_124 . V_125 . V_166 . V_127 = ( V_128 ) V_67 ;
V_108 = F_42 ( V_2 , V_67 ) ;
if ( V_108 )
F_28 ( L_10 ) ;
}
void F_70 ( struct V_106 * V_31 , struct V_81 * V_82 )
{
struct V_1 * V_2 = (struct V_1 * ) V_31 -> V_159 ;
struct V_84 * V_85 = (struct V_84 * ) V_82 -> V_86 ;
struct V_167 V_91 ;
memset ( & V_91 , 0 , sizeof( V_91 ) ) ;
V_91 . V_168 = true ;
V_91 . V_169 = V_82 -> V_170 -> V_171 ;
F_71 ( V_2 , V_85 , & V_91 , false ) ;
}
void F_72 ( struct V_81 * V_82 , T_2 V_172 , T_2 V_173 , T_2 V_174 )
{
struct V_84 * V_85 ;
V_85 = (struct V_84 * ) V_82 -> V_86 ;
F_73 ( V_85 , V_172 , 0 , V_173 , V_174 ) ;
}
void F_74 ( struct V_81 * V_82 , int V_175 )
{
struct V_84 * V_85 ;
T_1 V_176 = V_177 ;
T_2 V_178 = 0 ;
bool V_179 ;
unsigned long V_68 ;
V_85 = (struct V_84 * ) V_82 -> V_86 ;
F_20 ( & V_85 -> V_180 , V_68 ) ;
if ( V_85 -> V_181 ) {
V_85 -> V_181 = 0 ;
V_178 = 1 ;
}
V_179 = ! ( V_82 -> V_182 & V_183 ) ;
V_82 -> V_182 |= V_183 ;
F_24 ( & V_85 -> V_180 , V_68 ) ;
if ( V_179 ) {
if ( ! V_175 )
F_75 ( V_82 ) ;
else
V_176 = V_184 ;
F_73 ( V_85 , V_176 , V_178 , 0 , 0 ) ;
F_76 ( V_85 ) ;
}
}
static void F_77 ( unsigned long V_185 )
{
struct V_84 * V_85 = (struct V_84 * ) V_185 ;
struct V_81 * V_82 = (struct V_81 * ) & V_85 -> V_121 ;
F_74 ( V_82 , 1 ) ;
F_51 ( & V_85 -> V_88 ) ;
}
void F_78 ( struct V_81 * V_82 )
{
struct V_84 * V_85 ;
V_85 = (struct V_84 * ) V_82 -> V_86 ;
F_50 ( & V_85 -> V_88 ) ;
F_79 ( & V_85 -> V_186 ) ;
V_85 -> V_186 . V_187 = F_77 ;
V_85 -> V_186 . V_188 = V_189 + V_190 ;
V_85 -> V_186 . V_191 = ( unsigned long ) V_85 ;
F_80 ( & V_85 -> V_186 ) ;
}
void F_75 ( struct V_81 * V_82 )
{
struct V_84 * V_85 ;
V_85 = (struct V_84 * ) V_82 -> V_86 ;
if ( F_81 ( & V_85 -> V_186 ) )
F_51 ( & V_85 -> V_88 ) ;
}
static void F_82 ( struct V_192 * V_193 )
{
struct V_194 * V_195 =
& ( (struct V_196 * ) V_193 ) -> V_195 ;
if ( V_195 -> V_197 )
V_195 -> V_79 ( V_195 -> V_197 ) ;
}
void F_83 ( struct V_106 * V_31 ,
struct V_194 * V_195 ,
T_1 V_198 )
{
struct V_196 * V_193 ;
struct V_1 * V_2 = (struct V_1 * ) V_31 -> V_159 ;
V_193 = & V_2 -> V_199 [ V_198 ] ;
memcpy ( & V_193 -> V_195 , V_195 , sizeof( * V_195 ) ) ;
F_84 ( & V_193 -> V_193 , F_82 ) ;
F_85 ( V_2 -> V_200 , & V_193 -> V_193 ) ;
}
static void F_86 ( struct V_192 * V_193 )
{
struct V_63 * V_67 =
( (struct V_196 * ) V_193 ) -> V_67 ;
struct V_201 V_202 ;
struct V_203 * V_204 =
& V_67 -> V_91 . V_124 . V_125 . V_205 . V_91 ;
struct V_1 * V_2 =
(struct V_1 * ) V_67 -> V_91 . V_124 . V_125 . V_205 . V_31 -> V_159 ;
V_202 . V_65 = NULL ;
V_202 . V_102 = V_67 -> V_101 . V_102 ;
V_202 . V_103 = V_67 -> V_101 . V_103 ;
V_202 . V_206 = V_67 -> V_101 . V_206 ;
V_202 . V_207 = V_67 -> V_101 . V_207 ;
V_202 . V_127 = 0 ;
V_202 . error = V_67 -> V_101 . error ;
V_204 -> V_79 ( V_67 -> V_91 . V_124 . V_125 . V_205 . V_31 ,
V_204 -> V_208 , & V_202 ) ;
F_33 ( & V_2 -> V_65 , V_67 ) ;
}
static void F_87 ( struct V_63 * V_67 ,
T_1 V_209 )
{
struct V_196 * V_193 ;
struct V_203 * V_204 =
& V_67 -> V_91 . V_124 . V_125 . V_205 . V_91 ;
struct V_1 * V_2 =
(struct V_1 * ) V_67 -> V_91 . V_124 . V_125 . V_205 . V_31 ->
V_159 ;
if ( V_204 && V_204 -> V_79 ) {
F_56 ( & V_2 -> V_107 , V_210 , L_11 , V_211 ) ;
F_49 ( & V_67 -> V_76 ) ;
V_193 = & V_2 -> V_199 [ V_204 -> V_198 ] ;
V_193 -> V_67 = V_67 ;
F_84 ( & V_193 -> V_193 , F_86 ) ;
F_85 ( V_2 -> V_200 , & V_193 -> V_193 ) ;
F_56 ( & V_2 -> V_107 , V_210 , L_12 , V_211 ) ;
} else {
F_56 ( & V_2 -> V_107 , V_210 , L_13 , V_211 ) ;
}
}
enum V_105 F_88 ( struct V_106 * V_31 ,
struct V_203 * V_204 )
{
enum V_105 V_108 ;
struct V_63 * V_67 ;
struct V_90 * V_118 ;
struct V_1 * V_2 = (struct V_1 * ) V_31 -> V_159 ;
F_56 ( & V_2 -> V_107 , V_210 , L_6 , V_211 ) ;
V_67 = F_19 ( & V_2 -> V_65 , false ) ;
if ( ! V_67 )
return V_155 ;
V_118 = & V_67 -> V_91 ;
V_67 -> V_79 = F_87 ;
V_67 -> V_83 = V_204 ;
memcpy ( & V_118 -> V_124 . V_125 . V_205 . V_91 , V_204 ,
sizeof( * V_204 ) ) ;
V_118 -> V_124 . V_125 . V_205 . V_31 = V_31 ;
V_118 -> V_97 = V_212 ;
V_118 -> V_123 = 1 ;
V_118 -> V_124 . V_125 . V_205 . V_127 = ( V_128 ) V_67 ;
V_108 = F_42 ( V_2 , V_67 ) ;
if ( V_108 )
F_28 ( L_14 ) ;
return V_108 ;
}
enum V_105 F_89 ( struct V_106 * V_31 ,
struct V_144 * V_213 ,
T_2 V_214 )
{
enum V_105 V_108 ;
struct V_63 * V_67 ;
struct V_90 * V_118 ;
struct V_1 * V_2 = (struct V_1 * ) V_31 -> V_159 ;
V_67 = F_19 ( & V_2 -> V_65 , true ) ;
if ( ! V_67 )
return V_155 ;
V_118 = & V_67 -> V_91 ;
V_67 -> V_83 = NULL ;
V_118 -> V_124 . V_125 . V_215 . V_65 = V_31 -> V_65 ;
V_118 -> V_124 . V_125 . V_215 . V_216 = V_213 -> V_153 ;
V_118 -> V_124 . V_125 . V_215 . V_217 = V_213 -> V_151 ;
V_118 -> V_124 . V_125 . V_215 . V_214 = V_214 ;
V_118 -> V_97 = V_218 ;
V_118 -> V_123 = 1 ;
V_118 -> V_124 . V_125 . V_215 . V_127 = ( V_128 ) V_67 ;
V_108 = F_42 ( V_2 , V_67 ) ;
if ( V_108 )
F_28 ( L_15 ) ;
return V_108 ;
}
enum V_105 F_90 ( struct V_106 * V_31 ,
struct V_144 * V_213 ,
T_2 V_214 )
{
enum V_105 V_108 ;
struct V_63 * V_67 ;
struct V_90 * V_118 ;
struct V_1 * V_2 = (struct V_1 * ) V_31 -> V_159 ;
V_67 = F_19 ( & V_2 -> V_65 , true ) ;
if ( ! V_67 )
return V_155 ;
V_118 = & V_67 -> V_91 ;
V_67 -> V_83 = NULL ;
V_118 -> V_124 . V_125 . V_219 . V_65 = V_31 -> V_65 ;
V_118 -> V_124 . V_125 . V_219 . V_216 = V_213 -> V_153 ;
V_118 -> V_124 . V_125 . V_219 . V_217 = V_213 -> V_151 ;
V_118 -> V_124 . V_125 . V_219 . V_214 = V_214 ;
V_118 -> V_97 = V_220 ;
V_118 -> V_123 = 1 ;
V_118 -> V_124 . V_125 . V_219 . V_127 = ( V_128 ) V_67 ;
V_108 = F_42 ( V_2 , V_67 ) ;
if ( V_108 )
F_28 ( L_16 ) ;
return V_108 ;
}
enum V_105 F_91 ( struct V_106 * V_31 )
{
struct V_1 * V_2 = V_31 -> V_159 ;
int V_95 ;
F_56 ( V_31 , V_221 , L_17 ,
V_211 , __LINE__ , V_31 , V_2 ) ;
F_29 ( & V_2 -> V_222 , 2 ) ;
V_95 = F_40 ( V_2 -> V_223 ,
( F_92 ( & V_2 -> V_222 ) == 1 ) ,
V_224 ) ;
F_93 ( & V_2 -> V_222 ) ;
if ( ! V_95 ) {
F_28 ( L_18 , V_95 ) ;
F_29 ( & V_2 -> V_222 , 0 ) ;
V_31 -> V_225 = false ;
return V_226 ;
}
F_47 ( & V_31 -> V_227 ) ;
return 0 ;
}
enum V_105 F_94 ( struct V_106 * V_31 ,
struct V_228 * V_229 )
{
struct V_1 * V_2 = (struct V_1 * ) V_31 -> V_159 ;
struct V_64 * V_92 = & V_2 -> V_65 ;
struct V_63 * V_67 ;
struct V_90 * V_118 ;
enum V_105 V_108 ;
V_67 = F_19 ( V_92 , true ) ;
if ( ! V_67 )
return V_155 ;
V_118 = & V_67 -> V_91 ;
V_118 -> V_97 = V_230 ;
V_118 -> V_123 = 1 ;
V_118 -> V_124 . V_125 . V_231 . V_229 = V_229 ;
V_118 -> V_124 . V_125 . V_231 . V_127 = ( V_128 ) V_67 ;
V_108 = F_42 ( V_2 , V_67 ) ;
if ( V_108 )
F_28 ( L_19 ) ;
return V_108 ;
}
enum V_105 F_95 ( struct V_106 * V_31 ,
struct V_81 * V_82 )
{
struct V_1 * V_2 = (struct V_1 * ) V_31 -> V_159 ;
struct V_64 * V_92 = & V_2 -> V_65 ;
struct V_63 * V_67 ;
struct V_90 * V_118 ;
struct V_232 * V_233 ;
enum V_105 V_108 ;
V_67 = F_19 ( V_92 , true ) ;
if ( ! V_67 )
return V_155 ;
V_118 = & V_67 -> V_91 ;
V_233 = & V_67 -> V_91 . V_124 . V_125 . V_234 . V_91 ;
memset ( V_233 , 0 , sizeof( * V_233 ) ) ;
V_233 -> V_235 = true ;
V_233 -> V_176 = V_236 ;
V_118 -> V_97 = V_237 ;
V_118 -> V_123 = 1 ;
V_118 -> V_124 . V_125 . V_234 . V_82 = V_82 ;
V_118 -> V_124 . V_125 . V_234 . V_127 = ( V_128 ) V_67 ;
V_108 = F_42 ( V_2 , V_67 ) ;
if ( V_108 )
F_28 ( L_20 ) ;
return V_108 ;
}
void F_96 ( struct V_106 * V_31 , struct V_228 * V_229 )
{
struct V_1 * V_2 = (struct V_1 * ) V_31 -> V_159 ;
F_97 ( V_2 , V_229 ) ;
}
void F_98 ( struct V_106 * V_31 , struct V_81 * V_82 )
{
struct V_1 * V_2 = (struct V_1 * ) V_31 -> V_159 ;
struct V_64 * V_92 = & V_2 -> V_65 ;
struct V_63 * V_67 ;
struct V_90 * V_118 ;
enum V_105 V_108 ;
V_67 = F_19 ( V_92 , true ) ;
if ( ! V_67 )
return;
V_118 = & V_67 -> V_91 ;
memset ( V_118 , 0 , sizeof( * V_118 ) ) ;
V_118 -> V_97 = V_122 ;
V_118 -> V_123 = 1 ;
V_118 -> V_124 . V_125 . V_126 . V_82 = V_82 ;
V_118 -> V_124 . V_125 . V_126 . V_127 = ( V_128 ) V_67 ;
V_118 -> V_124 . V_125 . V_126 . V_129 = true ;
V_108 = F_42 ( V_2 , V_67 ) ;
if ( V_108 )
F_28 ( L_21 ) ;
}
void F_99 ( struct V_106 * V_31 , struct V_81 * V_82 )
{
struct V_238 V_91 ;
struct V_1 * V_2 = (struct V_1 * ) V_31 -> V_159 ;
F_56 ( V_31 , V_239 , L_22 , V_211 ) ;
memset ( & V_91 , 0 , sizeof( V_91 ) ) ;
V_91 . V_240 = V_241 ;
V_91 . V_242 = true ;
V_91 . V_243 = 0x3 ;
( void ) F_100 ( V_2 , V_82 , & V_91 , false ) ;
}
enum V_105 F_101 ( struct V_244 * * V_136 )
{
struct V_245 * V_246 ;
struct V_244 * V_247 ;
V_246 = F_102 ( L_23 , 0 , 0 ) ;
if ( F_103 ( V_246 ) )
return V_248 ;
V_247 = F_25 ( sizeof( * V_247 ) + F_104 ( V_246 ) ,
V_154 ) ;
if ( ! V_247 ) {
F_105 ( V_246 ) ;
return V_248 ;
}
V_247 -> V_246 = V_246 ;
* V_136 = V_247 ;
return 0 ;
}
void F_106 ( struct V_244 * V_136 )
{
if ( V_136 ) {
F_105 ( V_136 -> V_246 ) ;
F_31 ( V_136 ) ;
}
}
enum V_105 F_107 ( struct V_106 * V_31 ,
struct V_144 * V_145 )
{
enum V_105 V_108 ;
struct V_1 * V_2 = (struct V_1 * ) V_31 -> V_159 ;
V_108 = F_108 ( V_2 , V_145 , V_249 ,
V_250 ) ;
return V_108 ;
}
enum V_105 F_109 ( struct V_244 * V_136 ,
void * V_51 ,
T_1 V_251 ,
T_1 V_20 )
{
T_1 V_252 = 0 ;
int V_253 ;
enum V_105 V_254 = 0 ;
F_110 ( V_136 ) ;
V_253 = F_111 ( V_136 , V_51 , V_251 ) ;
if ( ! V_253 )
F_112 ( V_136 , ( T_2 * ) & V_252 ) ;
if ( V_252 != V_20 ) {
F_28 ( L_24 ) ;
V_254 = V_248 ;
}
return V_254 ;
}
struct V_81 * F_113 ( struct V_106 * V_31 ,
struct V_255 * V_137 )
{
struct V_1 * V_2 = (struct V_1 * ) V_31 -> V_159 ;
struct V_84 * V_85 ;
struct V_256 * V_257 ;
T_1 V_258 [ 4 ] , V_259 [ 4 ] ;
T_6 V_260 , V_261 ;
struct V_262 * V_263 ;
struct V_264 * V_265 = (struct V_264 * ) V_137 -> V_265 ;
struct V_266 * V_267 = (struct V_266 * ) V_137 -> V_267 ;
if ( V_265 -> V_268 == 4 ) {
memset ( V_258 , 0 , sizeof( V_258 ) ) ;
V_258 [ 0 ] = F_13 ( V_265 -> V_269 ) ;
memset ( V_259 , 0 , sizeof( V_259 ) ) ;
V_259 [ 0 ] = F_13 ( V_265 -> V_270 ) ;
} else {
V_263 = (struct V_262 * ) V_137 -> V_265 ;
F_17 ( V_258 , V_263 -> V_269 . V_52 . V_53 ) ;
F_17 ( V_259 , V_263 -> V_270 . V_52 . V_53 ) ;
}
V_260 = F_114 ( V_267 -> V_271 ) ;
V_261 = F_114 ( V_267 -> V_272 ) ;
V_257 = F_115 ( & V_2 -> V_273 , V_261 , V_259 , V_260 ,
V_258 , false ) ;
if ( ! V_257 )
return NULL ;
V_85 = V_257 -> V_85 ;
return & V_85 -> V_121 ;
}
void F_116 ( struct V_255 * V_137 , T_6 V_251 , T_1 V_274 )
{
struct V_266 * V_267 ;
struct V_264 * V_265 ;
T_6 V_275 ;
T_6 V_276 ;
T_2 * V_51 = ( T_2 * ) V_137 -> V_145 . V_151 ;
V_275 = ( V_137 -> V_4 ) ? 20 : 40 ;
V_265 = (struct V_264 * ) ( V_51 + V_137 -> V_277 ) ;
V_267 = (struct V_266 * ) ( V_51 + V_137 -> V_277 + V_275 ) ;
V_276 = V_251 + V_137 -> V_278 + V_275 ;
V_265 -> V_279 = F_117 ( V_276 ) ;
V_267 -> V_280 = F_118 ( V_274 ) ;
}
enum V_105 F_119 ( struct V_281 * V_91 ,
struct V_255 * V_137 )
{
struct V_264 * V_265 ;
struct V_262 * V_263 ;
struct V_266 * V_267 ;
T_6 V_275 ;
T_6 V_282 ;
T_2 * V_145 = ( T_2 * ) V_137 -> V_145 . V_151 ;
struct V_283 * V_284 = (struct V_283 * ) V_137 -> V_145 . V_151 ;
if ( V_284 -> V_285 == F_117 ( 0x8100 ) ) {
V_91 -> V_286 = true ;
V_137 -> V_287 = F_114 ( ( (struct V_288 * ) V_284 ) -> V_289 ) & V_290 ;
}
V_137 -> V_277 = ( V_91 -> V_286 ) ? 18 : 14 ;
V_275 = ( V_91 -> V_291 ) ? 40 : 20 ;
V_137 -> V_4 = ( V_91 -> V_291 ) ? false : true ;
V_137 -> V_265 = V_145 + V_137 -> V_277 ;
V_265 = (struct V_264 * ) V_137 -> V_265 ;
V_137 -> V_267 = V_137 -> V_265 + V_275 ;
V_267 = (struct V_266 * ) V_137 -> V_267 ;
if ( V_137 -> V_4 ) {
V_282 = F_114 ( V_265 -> V_279 ) ;
} else {
V_263 = (struct V_262 * ) V_137 -> V_265 ;
V_282 = F_114 ( V_263 -> V_292 ) + V_275 ;
}
V_137 -> V_293 = V_282 + V_137 -> V_277 ;
if ( V_91 -> V_292 < V_137 -> V_293 ) {
F_28 ( L_25 ,
V_91 -> V_292 , V_137 -> V_293 ) ;
return V_294 ;
}
V_137 -> V_278 = ( V_267 -> V_295 ) << 2 ;
V_137 -> V_296 = V_282 - V_275 - V_137 -> V_278 ;
V_137 -> V_191 = ( V_137 -> V_296 ) ? V_137 -> V_267 + V_137 -> V_278 : NULL ;
V_137 -> V_297 = V_137 -> V_277 + V_275 + V_137 -> V_278 ;
V_137 -> V_274 = F_13 ( V_267 -> V_280 ) ;
return 0 ;
}
static void F_120 ( unsigned long V_170 )
{
struct V_298 * V_299 = (struct V_298 * ) V_170 ;
struct V_106 * V_300 = V_299 -> V_31 ;
struct V_301 * V_302 = V_299 -> V_303 ;
struct V_301 * V_304 = NULL ;
T_6 V_198 ;
unsigned long V_68 ;
F_121 ( V_302 , & V_302 -> V_305 ) ;
for ( V_198 = 0 ; V_198 < V_306 ; V_198 ++ ) {
F_20 ( & V_302 -> V_180 , V_68 ) ;
if ( V_300 -> V_307 [ V_198 ] ) {
if ( V_300 -> V_307 [ V_198 ] -> V_308 ) {
V_304 = & V_300 -> V_307 [ V_198 ] -> V_303 ;
F_121 ( V_304 , & V_304 -> V_305 ) ;
}
}
F_24 ( & V_302 -> V_180 , V_68 ) ;
}
F_122 ( & V_302 -> V_309 ,
V_189 + F_123 ( V_310 ) ) ;
}
void F_124 ( struct V_298 * V_170 )
{
struct V_301 * V_311 = V_170 -> V_303 ;
F_79 ( & V_311 -> V_309 ) ;
V_311 -> V_309 . V_187 = F_120 ;
V_311 -> V_309 . V_191 = ( unsigned long ) V_170 ;
F_122 ( & V_311 -> V_309 ,
V_189 + F_123 ( V_310 ) ) ;
}
void F_125 ( struct V_298 * V_170 )
{
struct V_301 * V_311 = V_170 -> V_303 ;
F_126 ( & V_311 -> V_309 ) ;
}
