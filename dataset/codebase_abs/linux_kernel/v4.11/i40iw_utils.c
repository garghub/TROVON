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
if ( V_2 -> V_39 < V_40 )
return V_37 ;
V_32 = V_2 -> V_41 -> V_32 ;
V_33 = F_12 ( V_32 ) ;
if ( V_32 != V_29 )
return V_37 ;
if ( V_33 )
V_36 = F_13 (
( (struct V_42 * ) V_33 -> V_43 ) -> V_44 -> V_45 ) ;
else
V_36 = F_13 ( V_27 -> V_45 ) ;
switch ( V_24 ) {
case V_46 :
V_6 = V_16 ;
case V_47 :
case V_48 :
F_14 ( V_2 ,
V_32 -> V_49 ,
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
struct V_50 * V_27 = (struct V_50 * ) V_25 ;
struct V_28 * V_29 = V_27 -> V_51 -> V_31 ;
struct V_28 * V_32 ;
struct V_1 * V_2 ;
struct V_34 * V_35 ;
T_1 V_52 [ 4 ] ;
T_1 V_6 = V_12 ;
V_35 = F_11 ( V_29 ) ;
if ( ! V_35 )
return V_37 ;
V_2 = & V_35 -> V_38 ;
if ( V_2 -> V_39 < V_40 )
return V_37 ;
V_32 = V_2 -> V_41 -> V_32 ;
if ( V_32 != V_29 )
return V_37 ;
F_17 ( V_52 , V_27 -> V_53 . V_54 . V_55 ) ;
switch ( V_24 ) {
case V_46 :
V_6 = V_16 ;
case V_47 :
case V_48 :
F_14 ( V_2 ,
V_32 -> V_49 ,
V_52 ,
false ,
V_6 ) ;
F_15 ( V_2 , V_32 , V_52 , false ,
( V_6 == V_12 ) ? true : false ) ;
break;
default:
break;
}
return V_37 ;
}
int F_18 ( struct V_22 * V_23 , unsigned long V_24 , void * V_25 )
{
struct V_56 * V_57 = V_25 ;
struct V_1 * V_2 ;
struct V_34 * V_58 ;
T_3 * V_59 ;
T_1 V_36 [ 4 ] ;
switch ( V_24 ) {
case V_60 :
V_58 = F_11 ( (struct V_28 * ) V_57 -> V_31 ) ;
if ( ! V_58 )
return V_37 ;
V_2 = & V_58 -> V_38 ;
if ( V_2 -> V_39 < V_40 )
return V_37 ;
V_59 = ( T_3 * ) V_57 -> V_61 ;
F_17 ( V_36 , V_59 ) ;
if ( V_57 -> V_62 & V_63 ) {
F_14 ( V_2 ,
V_57 -> V_64 ,
V_36 ,
false ,
V_12 ) ;
} else {
F_14 ( V_2 ,
V_57 -> V_64 ,
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
struct V_65 * F_19 ( struct V_66 * V_67 , bool V_68 )
{
struct V_65 * V_69 = NULL ;
unsigned long V_70 ;
F_20 ( & V_67 -> V_71 , V_70 ) ;
if ( ! F_21 ( & V_67 -> V_72 ) ) {
V_69 = F_22 ( V_67 -> V_72 . V_73 ,
struct V_65 , V_74 ) ;
F_23 ( & V_69 -> V_74 ) ;
}
F_24 ( & V_67 -> V_71 , V_70 ) ;
if ( ! V_69 ) {
V_69 = F_25 ( sizeof( * V_69 ) , V_75 ) ;
if ( V_69 ) {
V_69 -> V_76 = true ;
F_26 ( & V_69 -> V_74 ) ;
F_27 ( & V_69 -> V_77 ) ;
}
}
if ( ! V_69 ) {
F_28 ( L_1 ) ;
return NULL ;
}
if ( V_68 ) {
F_29 ( & V_69 -> V_78 , 2 ) ;
V_69 -> V_79 = true ;
} else {
F_29 ( & V_69 -> V_78 , 1 ) ;
}
return V_69 ;
}
void F_30 ( struct V_66 * V_67 , struct V_65 * V_69 )
{
unsigned long V_70 ;
if ( V_69 -> V_76 ) {
F_31 ( V_69 ) ;
} else {
V_69 -> V_80 = false ;
V_69 -> V_81 = NULL ;
V_69 -> V_79 = false ;
F_20 ( & V_67 -> V_71 , V_70 ) ;
F_32 ( & V_69 -> V_74 , & V_67 -> V_72 ) ;
F_24 ( & V_67 -> V_71 , V_70 ) ;
}
}
void F_33 ( struct V_66 * V_67 ,
struct V_65 * V_69 )
{
if ( F_34 ( & V_69 -> V_78 ) )
F_30 ( V_67 , V_69 ) ;
}
static void F_35 ( struct V_65 * V_69 , T_1 V_82 )
{
struct V_83 * V_84 = (struct V_83 * ) V_69 -> V_85 ;
struct V_86 * V_87 = (struct V_86 * ) V_84 -> V_88 ;
struct V_1 * V_2 ;
T_1 V_89 = V_87 -> V_90 . V_89 ;
V_2 = V_87 -> V_2 ;
F_36 ( V_87 -> V_91 , V_2 ) ;
F_37 ( V_2 , V_87 , V_89 ) ;
F_38 ( V_2 ) ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_65 * V_69 )
{
struct V_92 * V_93 = & V_69 -> V_93 ;
struct V_66 * V_94 = & V_2 -> V_67 ;
bool V_95 = false ;
int V_96 = 0 ;
int V_97 = 0 ;
V_97 = F_40 ( V_69 -> V_77 ,
V_69 -> V_80 ,
V_98 ) ;
if ( ! V_97 ) {
F_28 ( L_2 ,
V_93 -> V_99 , V_97 ) ;
V_96 = - V_100 ;
if ( ! V_2 -> V_101 ) {
V_2 -> V_101 = true ;
F_41 ( V_2 ) ;
}
goto V_102;
}
V_95 = V_69 -> V_103 . error ;
if ( V_95 ) {
F_28 ( L_3 ,
V_93 -> V_99 , V_69 -> V_103 . V_104 ,
V_69 -> V_103 . V_105 ) ;
V_96 = - V_106 ;
goto V_102;
}
V_102:
F_33 ( V_94 , V_69 ) ;
return V_96 ;
}
enum V_107 F_42 ( struct V_1 * V_2 ,
struct V_65
* V_69 )
{
struct V_108 * V_31 = & V_2 -> V_109 ;
enum V_107 V_110 ;
struct V_92 * V_93 = & V_69 -> V_93 ;
int V_96 = 0 ;
if ( V_2 -> V_101 ) {
F_30 ( & V_2 -> V_67 , V_69 ) ;
return V_111 ;
}
V_110 = F_43 ( V_31 , V_93 ) ;
if ( V_110 ) {
F_28 ( L_4 , V_93 -> V_99 ) ;
F_30 ( & V_2 -> V_67 , V_69 ) ;
return V_110 ;
}
if ( V_69 -> V_79 )
V_96 = F_39 ( V_2 , V_69 ) ;
if ( V_96 )
V_110 = V_111 ;
return V_110 ;
}
void F_44 ( struct V_1 * V_2 )
{
F_45 ( & V_2 -> V_112 ) ;
}
void F_38 ( struct V_1 * V_2 )
{
if ( ! F_46 ( & V_2 -> V_112 ) )
return;
F_47 ( & V_2 -> V_113 ) ;
}
void F_48 ( struct V_114 * V_91 )
{
F_49 ( & V_91 -> V_115 ) ;
}
void F_36 ( struct V_114 * V_91 , struct V_1 * V_2 )
{
if ( ! F_34 ( & V_91 -> V_115 ) )
return;
F_5 ( V_2 , V_2 -> V_116 , V_91 -> V_117 . V_118 ) ;
F_31 ( V_91 ) ;
}
void F_50 ( struct V_119 * V_90 )
{
struct V_86 * V_87 = (struct V_86 * ) V_90 ;
F_49 ( & V_87 -> V_78 ) ;
}
void F_51 ( struct V_119 * V_90 )
{
struct V_86 * V_87 ;
enum V_107 V_110 ;
struct V_65 * V_69 ;
struct V_92 * V_120 ;
struct V_1 * V_2 ;
T_1 V_89 ;
unsigned long V_70 ;
V_87 = F_52 ( V_90 ) ;
V_2 = V_87 -> V_2 ;
F_20 ( & V_2 -> V_121 , V_70 ) ;
if ( ! F_34 ( & V_87 -> V_78 ) ) {
F_24 ( & V_2 -> V_121 , V_70 ) ;
return;
}
V_89 = V_87 -> V_90 . V_89 ;
V_2 -> V_122 [ V_89 ] = NULL ;
F_24 ( & V_2 -> V_121 , V_70 ) ;
V_69 = F_19 ( & V_2 -> V_67 , false ) ;
if ( ! V_69 )
return;
V_69 -> V_81 = F_35 ;
V_69 -> V_85 = ( void * ) & V_87 -> V_123 ;
V_120 = & V_69 -> V_93 ;
V_120 -> V_99 = V_124 ;
V_120 -> V_125 = 1 ;
V_120 -> V_126 . V_127 . V_128 . V_84 = & V_87 -> V_123 ;
V_120 -> V_126 . V_127 . V_128 . V_129 = ( V_130 ) V_69 ;
V_120 -> V_126 . V_127 . V_128 . V_131 = true ;
V_110 = F_42 ( V_2 , V_69 ) ;
if ( V_110 )
F_28 ( L_5 ) ;
}
struct V_119 * F_53 ( struct V_132 * V_38 , int V_133 )
{
struct V_1 * V_2 = F_54 ( V_38 ) ;
if ( ( V_133 < V_134 ) || ( V_133 >= V_2 -> V_135 ) )
return NULL ;
return & V_2 -> V_122 [ V_133 ] -> V_90 ;
}
void F_55 ( struct V_108 * V_31 ,
enum V_136 V_137 ,
char * V_138 ,
T_4 * V_139 ,
T_1 V_140 )
{
T_1 V_141 ;
if ( ! ( V_31 -> V_142 & V_137 ) )
return;
F_56 ( V_31 , V_137 , L_6 , V_138 ) ;
F_56 ( V_31 , V_137 , L_7 , V_139 ,
( unsigned long long ) F_57 ( V_139 ) ) ;
for ( V_141 = 0 ; V_141 < V_140 ; V_141 += 8 )
F_56 ( V_31 , V_137 , L_8 , V_141 , V_139 [ V_141 / 8 ] ) ;
}
T_2 T_5 * F_58 ( void * V_143 )
{
struct V_108 * V_31 = (struct V_108 * ) V_143 ;
return V_31 -> V_18 -> V_21 ;
}
void * F_59 ( struct V_144 * V_74 )
{
struct V_144 * V_145 ;
if ( F_21 ( V_74 ) )
return NULL ;
V_145 = ( void * ) V_74 -> V_73 ;
F_60 ( V_145 ) ;
return ( void * ) V_145 ;
}
enum V_107 F_61 ( struct V_17 * V_18 ,
struct V_146 * V_147 ,
T_4 V_140 ,
T_1 V_148 )
{
struct V_149 * V_150 = (struct V_149 * ) V_18 -> V_151 ;
if ( ! V_147 )
return V_152 ;
V_147 -> V_140 = F_62 ( V_140 , V_148 ) ;
V_147 -> V_153 = F_63 ( & V_150 -> V_31 , V_147 -> V_140 ,
( V_154 * ) & V_147 -> V_155 , V_156 ) ;
if ( ! V_147 -> V_153 )
return V_157 ;
return 0 ;
}
void F_64 ( struct V_17 * V_18 , struct V_146 * V_147 )
{
struct V_149 * V_150 = (struct V_149 * ) V_18 -> V_151 ;
if ( ! V_147 || ! V_147 -> V_153 )
return;
F_65 ( & V_150 -> V_31 , V_147 -> V_140 ,
V_147 -> V_153 , ( V_154 ) V_147 -> V_155 ) ;
V_147 -> V_153 = NULL ;
}
enum V_107 F_66 ( struct V_17 * V_18 ,
struct V_158 * V_147 ,
T_1 V_140 )
{
if ( ! V_147 )
return V_152 ;
V_147 -> V_140 = V_140 ;
V_147 -> V_153 = F_25 ( V_140 , V_156 ) ;
if ( V_147 -> V_153 )
return 0 ;
else
return V_157 ;
}
enum V_107 F_67 ( struct V_17 * V_18 ,
struct V_158 * V_147 )
{
if ( ! V_147 )
return V_152 ;
F_31 ( V_147 -> V_153 ) ;
return 0 ;
}
enum V_107 F_68 ( struct V_108 * V_31 ,
struct V_159 * V_160 )
{
enum V_107 V_110 ;
struct V_65 * V_69 ;
struct V_92 * V_120 ;
struct V_1 * V_2 = (struct V_1 * ) V_31 -> V_161 ;
V_69 = F_19 ( & V_2 -> V_67 , true ) ;
if ( ! V_69 )
return V_157 ;
V_120 = & V_69 -> V_93 ;
memcpy ( & V_120 -> V_126 . V_127 . V_162 . V_93 , V_160 ,
sizeof( V_120 -> V_126 . V_127 . V_162 . V_93 ) ) ;
V_120 -> V_99 = V_163 ;
V_120 -> V_125 = 1 ;
V_120 -> V_126 . V_127 . V_162 . V_31 = V_31 ;
V_120 -> V_126 . V_127 . V_162 . V_129 = ( V_130 ) V_69 ;
V_110 = F_42 ( V_2 , V_69 ) ;
if ( V_110 )
F_28 ( L_9 ) ;
return V_110 ;
}
void F_69 ( struct V_108 * V_31 , struct V_83 * V_84 , bool V_164 )
{
struct V_1 * V_2 = (struct V_1 * ) V_31 -> V_161 ;
struct V_65 * V_69 ;
struct V_165 * V_67 = V_31 -> V_67 ;
struct V_92 * V_120 ;
enum V_107 V_110 ;
V_69 = F_19 ( & V_2 -> V_67 , false ) ;
if ( ! V_69 )
return;
V_120 = & V_69 -> V_93 ;
V_120 -> V_99 = ( V_164 ) ? V_166 : V_167 ;
V_120 -> V_126 . V_127 . V_168 . V_67 = V_67 ;
V_120 -> V_126 . V_127 . V_168 . V_84 = V_84 ;
V_120 -> V_126 . V_127 . V_168 . V_129 = ( V_130 ) V_69 ;
V_110 = F_42 ( V_2 , V_69 ) ;
if ( V_110 )
F_28 ( L_10 ) ;
}
void F_70 ( struct V_108 * V_31 , struct V_83 * V_84 )
{
struct V_1 * V_2 = (struct V_1 * ) V_31 -> V_161 ;
struct V_86 * V_87 = (struct V_86 * ) V_84 -> V_88 ;
struct V_169 V_93 ;
memset ( & V_93 , 0 , sizeof( V_93 ) ) ;
V_93 . V_170 = true ;
V_93 . V_171 = V_84 -> V_172 -> V_173 ;
F_71 ( V_2 , V_87 , & V_93 , false ) ;
}
void F_72 ( struct V_83 * V_84 , T_2 V_174 , T_2 V_175 , T_2 V_176 )
{
struct V_86 * V_87 ;
V_87 = (struct V_86 * ) V_84 -> V_88 ;
F_73 ( V_87 , V_174 , 0 , V_175 , V_176 ) ;
}
void F_74 ( struct V_83 * V_84 , int V_177 )
{
struct V_86 * V_87 ;
T_1 V_178 = V_179 ;
T_2 V_180 = 0 ;
bool V_181 ;
unsigned long V_70 ;
V_87 = (struct V_86 * ) V_84 -> V_88 ;
F_20 ( & V_87 -> V_182 , V_70 ) ;
if ( V_87 -> V_183 ) {
V_87 -> V_183 = 0 ;
V_180 = 1 ;
}
V_181 = ! ( V_84 -> V_184 & V_185 ) ;
V_84 -> V_184 |= V_185 ;
F_24 ( & V_87 -> V_182 , V_70 ) ;
if ( V_181 ) {
if ( ! V_177 )
F_75 ( V_84 ) ;
else
V_178 = V_186 ;
F_73 ( V_87 , V_178 , V_180 , 0 , 0 ) ;
F_76 ( V_87 ) ;
}
}
static void F_77 ( unsigned long V_187 )
{
struct V_86 * V_87 = (struct V_86 * ) V_187 ;
struct V_83 * V_84 = (struct V_83 * ) & V_87 -> V_123 ;
F_74 ( V_84 , 1 ) ;
F_51 ( & V_87 -> V_90 ) ;
}
void F_78 ( struct V_83 * V_84 )
{
struct V_86 * V_87 ;
V_87 = (struct V_86 * ) V_84 -> V_88 ;
F_50 ( & V_87 -> V_90 ) ;
F_79 ( & V_87 -> V_188 ) ;
V_87 -> V_188 . V_189 = F_77 ;
V_87 -> V_188 . V_190 = V_191 + V_192 ;
V_87 -> V_188 . V_193 = ( unsigned long ) V_87 ;
F_80 ( & V_87 -> V_188 ) ;
}
void F_75 ( struct V_83 * V_84 )
{
struct V_86 * V_87 ;
V_87 = (struct V_86 * ) V_84 -> V_88 ;
if ( F_81 ( & V_87 -> V_188 ) )
F_51 ( & V_87 -> V_90 ) ;
}
static void F_82 ( struct V_194 * V_195 )
{
struct V_196 * V_197 =
& ( (struct V_198 * ) V_195 ) -> V_197 ;
if ( V_197 -> V_199 )
V_197 -> V_81 ( V_197 -> V_199 ) ;
}
void F_83 ( struct V_108 * V_31 ,
struct V_196 * V_197 ,
T_1 V_200 )
{
struct V_198 * V_195 ;
struct V_1 * V_2 = (struct V_1 * ) V_31 -> V_161 ;
V_195 = & V_2 -> V_201 [ V_200 ] ;
memcpy ( & V_195 -> V_197 , V_197 , sizeof( * V_197 ) ) ;
F_84 ( & V_195 -> V_195 , F_82 ) ;
F_85 ( V_2 -> V_202 , & V_195 -> V_195 ) ;
}
static void F_86 ( struct V_194 * V_195 )
{
struct V_65 * V_69 =
( (struct V_198 * ) V_195 ) -> V_69 ;
struct V_203 V_204 ;
struct V_205 * V_206 =
& V_69 -> V_93 . V_126 . V_127 . V_207 . V_93 ;
struct V_1 * V_2 =
(struct V_1 * ) V_69 -> V_93 . V_126 . V_127 . V_207 . V_31 -> V_161 ;
V_204 . V_67 = NULL ;
V_204 . V_104 = V_69 -> V_103 . V_104 ;
V_204 . V_105 = V_69 -> V_103 . V_105 ;
V_204 . V_208 = V_69 -> V_103 . V_208 ;
V_204 . V_209 = V_69 -> V_103 . V_209 ;
V_204 . V_129 = 0 ;
V_204 . error = V_69 -> V_103 . error ;
V_206 -> V_81 ( V_69 -> V_93 . V_126 . V_127 . V_207 . V_31 ,
V_206 -> V_210 , & V_204 ) ;
F_33 ( & V_2 -> V_67 , V_69 ) ;
}
static void F_87 ( struct V_65 * V_69 ,
T_1 V_211 )
{
struct V_198 * V_195 ;
struct V_205 * V_206 =
& V_69 -> V_93 . V_126 . V_127 . V_207 . V_93 ;
struct V_1 * V_2 =
(struct V_1 * ) V_69 -> V_93 . V_126 . V_127 . V_207 . V_31 ->
V_161 ;
if ( V_206 && V_206 -> V_81 ) {
F_56 ( & V_2 -> V_109 , V_212 , L_11 , V_213 ) ;
F_49 ( & V_69 -> V_78 ) ;
V_195 = & V_2 -> V_201 [ V_206 -> V_200 ] ;
V_195 -> V_69 = V_69 ;
F_84 ( & V_195 -> V_195 , F_86 ) ;
F_85 ( V_2 -> V_202 , & V_195 -> V_195 ) ;
F_56 ( & V_2 -> V_109 , V_212 , L_12 , V_213 ) ;
} else {
F_56 ( & V_2 -> V_109 , V_212 , L_13 , V_213 ) ;
}
}
enum V_107 F_88 ( struct V_108 * V_31 ,
struct V_205 * V_206 )
{
enum V_107 V_110 ;
struct V_65 * V_69 ;
struct V_92 * V_120 ;
struct V_1 * V_2 = (struct V_1 * ) V_31 -> V_161 ;
F_56 ( & V_2 -> V_109 , V_212 , L_6 , V_213 ) ;
V_69 = F_19 ( & V_2 -> V_67 , false ) ;
if ( ! V_69 )
return V_157 ;
V_120 = & V_69 -> V_93 ;
V_69 -> V_81 = F_87 ;
V_69 -> V_85 = V_206 ;
memcpy ( & V_120 -> V_126 . V_127 . V_207 . V_93 , V_206 ,
sizeof( * V_206 ) ) ;
V_120 -> V_126 . V_127 . V_207 . V_31 = V_31 ;
V_120 -> V_99 = V_214 ;
V_120 -> V_125 = 1 ;
V_120 -> V_126 . V_127 . V_207 . V_129 = ( V_130 ) V_69 ;
V_110 = F_42 ( V_2 , V_69 ) ;
if ( V_110 )
F_28 ( L_14 ) ;
return V_110 ;
}
enum V_107 F_89 ( struct V_108 * V_31 ,
struct V_146 * V_215 ,
T_2 V_216 )
{
enum V_107 V_110 ;
struct V_65 * V_69 ;
struct V_92 * V_120 ;
struct V_1 * V_2 = (struct V_1 * ) V_31 -> V_161 ;
V_69 = F_19 ( & V_2 -> V_67 , true ) ;
if ( ! V_69 )
return V_157 ;
V_120 = & V_69 -> V_93 ;
V_69 -> V_85 = NULL ;
V_120 -> V_126 . V_127 . V_217 . V_67 = V_31 -> V_67 ;
V_120 -> V_126 . V_127 . V_217 . V_218 = V_215 -> V_155 ;
V_120 -> V_126 . V_127 . V_217 . V_219 = V_215 -> V_153 ;
V_120 -> V_126 . V_127 . V_217 . V_216 = V_216 ;
V_120 -> V_99 = V_220 ;
V_120 -> V_125 = 1 ;
V_120 -> V_126 . V_127 . V_217 . V_129 = ( V_130 ) V_69 ;
V_110 = F_42 ( V_2 , V_69 ) ;
if ( V_110 )
F_28 ( L_15 ) ;
return V_110 ;
}
enum V_107 F_90 ( struct V_108 * V_31 ,
struct V_146 * V_215 ,
T_2 V_216 )
{
enum V_107 V_110 ;
struct V_65 * V_69 ;
struct V_92 * V_120 ;
struct V_1 * V_2 = (struct V_1 * ) V_31 -> V_161 ;
V_69 = F_19 ( & V_2 -> V_67 , true ) ;
if ( ! V_69 )
return V_157 ;
V_120 = & V_69 -> V_93 ;
V_69 -> V_85 = NULL ;
V_120 -> V_126 . V_127 . V_221 . V_67 = V_31 -> V_67 ;
V_120 -> V_126 . V_127 . V_221 . V_218 = V_215 -> V_155 ;
V_120 -> V_126 . V_127 . V_221 . V_219 = V_215 -> V_153 ;
V_120 -> V_126 . V_127 . V_221 . V_216 = V_216 ;
V_120 -> V_99 = V_222 ;
V_120 -> V_125 = 1 ;
V_120 -> V_126 . V_127 . V_221 . V_129 = ( V_130 ) V_69 ;
V_110 = F_42 ( V_2 , V_69 ) ;
if ( V_110 )
F_28 ( L_16 ) ;
return V_110 ;
}
enum V_107 F_91 ( struct V_108 * V_31 )
{
struct V_1 * V_2 = V_31 -> V_161 ;
int V_97 ;
F_56 ( V_31 , V_223 , L_17 ,
V_213 , __LINE__ , V_31 , V_2 ) ;
F_29 ( & V_2 -> V_224 , 2 ) ;
V_97 = F_40 ( V_2 -> V_225 ,
( F_92 ( & V_2 -> V_224 ) == 1 ) ,
V_226 ) ;
F_93 ( & V_2 -> V_224 ) ;
if ( ! V_97 ) {
F_28 ( L_18 , V_97 ) ;
F_29 ( & V_2 -> V_224 , 0 ) ;
V_31 -> V_227 = false ;
return V_228 ;
}
F_47 ( & V_31 -> V_229 ) ;
return 0 ;
}
enum V_107 F_94 ( struct V_108 * V_31 ,
struct V_230 * V_231 )
{
struct V_1 * V_2 = (struct V_1 * ) V_31 -> V_161 ;
struct V_66 * V_94 = & V_2 -> V_67 ;
struct V_65 * V_69 ;
struct V_92 * V_120 ;
enum V_107 V_110 ;
V_69 = F_19 ( V_94 , true ) ;
if ( ! V_69 )
return V_157 ;
V_120 = & V_69 -> V_93 ;
V_120 -> V_99 = V_232 ;
V_120 -> V_125 = 1 ;
V_120 -> V_126 . V_127 . V_233 . V_231 = V_231 ;
V_120 -> V_126 . V_127 . V_233 . V_129 = ( V_130 ) V_69 ;
V_110 = F_42 ( V_2 , V_69 ) ;
if ( V_110 )
F_28 ( L_19 ) ;
return V_110 ;
}
enum V_107 F_95 ( struct V_108 * V_31 ,
struct V_83 * V_84 )
{
struct V_1 * V_2 = (struct V_1 * ) V_31 -> V_161 ;
struct V_66 * V_94 = & V_2 -> V_67 ;
struct V_65 * V_69 ;
struct V_92 * V_120 ;
struct V_234 * V_235 ;
enum V_107 V_110 ;
V_69 = F_19 ( V_94 , true ) ;
if ( ! V_69 )
return V_157 ;
V_120 = & V_69 -> V_93 ;
V_235 = & V_69 -> V_93 . V_126 . V_127 . V_236 . V_93 ;
memset ( V_235 , 0 , sizeof( * V_235 ) ) ;
V_235 -> V_237 = true ;
V_235 -> V_178 = V_238 ;
V_120 -> V_99 = V_239 ;
V_120 -> V_125 = 1 ;
V_120 -> V_126 . V_127 . V_236 . V_84 = V_84 ;
V_120 -> V_126 . V_127 . V_236 . V_129 = ( V_130 ) V_69 ;
V_110 = F_42 ( V_2 , V_69 ) ;
if ( V_110 )
F_28 ( L_20 ) ;
return V_110 ;
}
void F_96 ( struct V_108 * V_31 , struct V_230 * V_231 )
{
struct V_1 * V_2 = (struct V_1 * ) V_31 -> V_161 ;
F_97 ( V_2 , V_231 ) ;
}
void F_98 ( struct V_108 * V_31 , struct V_83 * V_84 )
{
struct V_1 * V_2 = (struct V_1 * ) V_31 -> V_161 ;
struct V_66 * V_94 = & V_2 -> V_67 ;
struct V_65 * V_69 ;
struct V_92 * V_120 ;
enum V_107 V_110 ;
V_69 = F_19 ( V_94 , true ) ;
if ( ! V_69 )
return;
V_120 = & V_69 -> V_93 ;
memset ( V_120 , 0 , sizeof( * V_120 ) ) ;
V_120 -> V_99 = V_124 ;
V_120 -> V_125 = 1 ;
V_120 -> V_126 . V_127 . V_128 . V_84 = V_84 ;
V_120 -> V_126 . V_127 . V_128 . V_129 = ( V_130 ) V_69 ;
V_120 -> V_126 . V_127 . V_128 . V_131 = true ;
V_110 = F_42 ( V_2 , V_69 ) ;
if ( V_110 )
F_28 ( L_21 ) ;
}
void F_99 ( struct V_108 * V_31 , struct V_83 * V_84 )
{
struct V_240 V_93 ;
struct V_1 * V_2 = (struct V_1 * ) V_31 -> V_161 ;
F_56 ( V_31 , V_241 , L_22 , V_213 ) ;
memset ( & V_93 , 0 , sizeof( V_93 ) ) ;
V_93 . V_242 = V_243 ;
V_93 . V_244 = true ;
V_93 . V_245 = 0x3 ;
( void ) F_100 ( V_2 , V_84 , & V_93 , false ) ;
}
enum V_107 F_101 ( struct V_246 * * V_138 )
{
struct V_247 * V_248 ;
struct V_246 * V_249 ;
V_248 = F_102 ( L_23 , 0 , 0 ) ;
if ( F_103 ( V_248 ) )
return V_250 ;
V_249 = F_25 ( sizeof( * V_249 ) + F_104 ( V_248 ) ,
V_156 ) ;
if ( ! V_249 ) {
F_105 ( V_248 ) ;
return V_250 ;
}
V_249 -> V_248 = V_248 ;
* V_138 = V_249 ;
return 0 ;
}
void F_106 ( struct V_246 * V_138 )
{
if ( V_138 ) {
F_105 ( V_138 -> V_248 ) ;
F_31 ( V_138 ) ;
}
}
enum V_107 F_107 ( struct V_108 * V_31 ,
struct V_146 * V_147 )
{
enum V_107 V_110 ;
struct V_1 * V_2 = (struct V_1 * ) V_31 -> V_161 ;
V_110 = F_108 ( V_2 , V_147 , V_251 ,
V_252 ) ;
return V_110 ;
}
enum V_107 F_109 ( struct V_246 * V_138 ,
void * V_53 ,
T_1 V_253 ,
T_1 V_20 )
{
T_1 V_254 = 0 ;
int V_255 ;
enum V_107 V_256 = 0 ;
F_110 ( V_138 ) ;
V_255 = F_111 ( V_138 , V_53 , V_253 ) ;
if ( ! V_255 )
F_112 ( V_138 , ( T_2 * ) & V_254 ) ;
if ( V_254 != V_20 ) {
F_28 ( L_24 ) ;
V_256 = V_250 ;
}
return V_256 ;
}
struct V_83 * F_113 ( struct V_108 * V_31 ,
struct V_257 * V_139 )
{
struct V_1 * V_2 = (struct V_1 * ) V_31 -> V_161 ;
struct V_86 * V_87 ;
struct V_258 * V_259 ;
T_1 V_260 [ 4 ] , V_261 [ 4 ] ;
T_6 V_262 , V_263 ;
struct V_264 * V_265 ;
struct V_266 * V_267 = (struct V_266 * ) V_139 -> V_267 ;
struct V_268 * V_269 = (struct V_268 * ) V_139 -> V_269 ;
if ( V_267 -> V_270 == 4 ) {
memset ( V_260 , 0 , sizeof( V_260 ) ) ;
V_260 [ 0 ] = F_13 ( V_267 -> V_271 ) ;
memset ( V_261 , 0 , sizeof( V_261 ) ) ;
V_261 [ 0 ] = F_13 ( V_267 -> V_272 ) ;
} else {
V_265 = (struct V_264 * ) V_139 -> V_267 ;
F_17 ( V_260 , V_265 -> V_271 . V_54 . V_55 ) ;
F_17 ( V_261 , V_265 -> V_272 . V_54 . V_55 ) ;
}
V_262 = F_114 ( V_269 -> V_273 ) ;
V_263 = F_114 ( V_269 -> V_274 ) ;
V_259 = F_115 ( & V_2 -> V_275 , V_263 , V_261 , V_262 ,
V_260 , false ) ;
if ( ! V_259 )
return NULL ;
V_87 = V_259 -> V_87 ;
return & V_87 -> V_123 ;
}
void F_116 ( struct V_257 * V_139 , T_6 V_253 , T_1 V_276 )
{
struct V_268 * V_269 ;
struct V_266 * V_267 ;
T_6 V_277 ;
T_6 V_278 ;
T_2 * V_53 = ( T_2 * ) V_139 -> V_147 . V_153 ;
V_277 = ( V_139 -> V_4 ) ? 20 : 40 ;
V_267 = (struct V_266 * ) ( V_53 + V_139 -> V_279 ) ;
V_269 = (struct V_268 * ) ( V_53 + V_139 -> V_279 + V_277 ) ;
V_278 = V_253 + V_139 -> V_280 + V_277 ;
V_267 -> V_281 = F_117 ( V_278 ) ;
V_269 -> V_282 = F_118 ( V_276 ) ;
}
enum V_107 F_119 ( struct V_283 * V_93 ,
struct V_257 * V_139 )
{
struct V_266 * V_267 ;
struct V_264 * V_265 ;
struct V_268 * V_269 ;
T_6 V_277 ;
T_6 V_284 ;
T_2 * V_147 = ( T_2 * ) V_139 -> V_147 . V_153 ;
struct V_285 * V_286 = (struct V_285 * ) V_139 -> V_147 . V_153 ;
if ( V_286 -> V_287 == F_117 ( 0x8100 ) ) {
V_93 -> V_288 = true ;
V_139 -> V_289 = F_114 ( ( (struct V_290 * ) V_286 ) -> V_291 ) & V_292 ;
}
V_139 -> V_279 = ( V_93 -> V_288 ) ? 18 : 14 ;
V_277 = ( V_93 -> V_293 ) ? 40 : 20 ;
V_139 -> V_4 = ( V_93 -> V_293 ) ? false : true ;
V_139 -> V_267 = V_147 + V_139 -> V_279 ;
V_267 = (struct V_266 * ) V_139 -> V_267 ;
V_139 -> V_269 = V_139 -> V_267 + V_277 ;
V_269 = (struct V_268 * ) V_139 -> V_269 ;
if ( V_139 -> V_4 ) {
V_284 = F_114 ( V_267 -> V_281 ) ;
} else {
V_265 = (struct V_264 * ) V_139 -> V_267 ;
V_284 = F_114 ( V_265 -> V_294 ) + V_277 ;
}
V_139 -> V_295 = V_284 + V_139 -> V_279 ;
if ( V_93 -> V_294 < V_139 -> V_295 ) {
F_28 ( L_25 ,
V_93 -> V_294 , V_139 -> V_295 ) ;
return V_296 ;
}
V_139 -> V_280 = ( V_269 -> V_297 ) << 2 ;
V_139 -> V_298 = V_284 - V_277 - V_139 -> V_280 ;
V_139 -> V_193 = ( V_139 -> V_298 ) ? V_139 -> V_269 + V_139 -> V_280 : NULL ;
V_139 -> V_299 = V_139 -> V_279 + V_277 + V_139 -> V_280 ;
V_139 -> V_276 = F_13 ( V_269 -> V_282 ) ;
return 0 ;
}
static void F_120 ( unsigned long V_172 )
{
struct V_300 * V_301 = (struct V_300 * ) V_172 ;
struct V_108 * V_302 = V_301 -> V_31 ;
struct V_303 * V_304 = V_301 -> V_305 ;
struct V_303 * V_306 = NULL ;
T_6 V_200 ;
unsigned long V_70 ;
F_121 ( V_304 , & V_304 -> V_307 ) ;
for ( V_200 = 0 ; V_200 < V_308 ; V_200 ++ ) {
F_20 ( & V_304 -> V_182 , V_70 ) ;
if ( V_302 -> V_309 [ V_200 ] ) {
if ( V_302 -> V_309 [ V_200 ] -> V_310 ) {
V_306 = & V_302 -> V_309 [ V_200 ] -> V_305 ;
F_121 ( V_306 , & V_306 -> V_307 ) ;
}
}
F_24 ( & V_304 -> V_182 , V_70 ) ;
}
F_122 ( & V_304 -> V_311 ,
V_191 + F_123 ( V_312 ) ) ;
}
void F_124 ( struct V_300 * V_172 )
{
struct V_303 * V_313 = V_172 -> V_305 ;
F_79 ( & V_313 -> V_311 ) ;
V_313 -> V_311 . V_189 = F_120 ;
V_313 -> V_311 . V_193 = ( unsigned long ) V_172 ;
F_122 ( & V_313 -> V_311 ,
V_191 + F_123 ( V_312 ) ) ;
}
void F_125 ( struct V_300 * V_172 )
{
struct V_303 * V_313 = V_172 -> V_305 ;
F_126 ( & V_313 -> V_311 ) ;
}
