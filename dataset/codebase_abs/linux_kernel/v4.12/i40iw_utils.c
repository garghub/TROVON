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
void F_70 ( struct V_83 * V_84 , T_2 V_169 , T_2 V_170 , T_2 V_171 )
{
struct V_86 * V_87 ;
V_87 = (struct V_86 * ) V_84 -> V_88 ;
F_71 ( V_87 , V_169 , 0 , V_170 , V_171 ) ;
}
void F_72 ( struct V_83 * V_84 , int V_172 )
{
struct V_86 * V_87 ;
T_1 V_173 = V_174 ;
T_2 V_175 = 0 ;
bool V_176 ;
unsigned long V_70 ;
V_87 = (struct V_86 * ) V_84 -> V_88 ;
F_20 ( & V_87 -> V_177 , V_70 ) ;
if ( V_87 -> V_178 ) {
V_87 -> V_178 = 0 ;
V_175 = 1 ;
}
V_176 = ! ( V_84 -> V_179 & V_180 ) ;
V_84 -> V_179 |= V_180 ;
F_24 ( & V_87 -> V_177 , V_70 ) ;
if ( V_176 ) {
if ( ! V_172 )
F_73 ( V_84 ) ;
else
V_173 = V_181 ;
F_71 ( V_87 , V_173 , V_175 , 0 , 0 ) ;
F_74 ( V_87 ) ;
}
}
static void F_75 ( unsigned long V_182 )
{
struct V_86 * V_87 = (struct V_86 * ) V_182 ;
struct V_83 * V_84 = (struct V_83 * ) & V_87 -> V_123 ;
F_72 ( V_84 , 1 ) ;
F_51 ( & V_87 -> V_90 ) ;
}
void F_76 ( struct V_83 * V_84 )
{
struct V_86 * V_87 ;
V_87 = (struct V_86 * ) V_84 -> V_88 ;
F_50 ( & V_87 -> V_90 ) ;
F_77 ( & V_87 -> V_183 , F_75 ,
( unsigned long ) V_87 ) ;
V_87 -> V_183 . V_184 = V_185 + V_186 ;
F_78 ( & V_87 -> V_183 ) ;
}
void F_73 ( struct V_83 * V_84 )
{
struct V_86 * V_87 ;
V_87 = (struct V_86 * ) V_84 -> V_88 ;
if ( F_79 ( & V_87 -> V_183 ) )
F_51 ( & V_87 -> V_90 ) ;
}
static void F_80 ( struct V_187 * V_188 )
{
struct V_189 * V_190 =
& ( (struct V_191 * ) V_188 ) -> V_190 ;
if ( V_190 -> V_192 )
V_190 -> V_81 ( V_190 -> V_192 ) ;
}
void F_81 ( struct V_108 * V_31 ,
struct V_189 * V_190 ,
T_1 V_193 )
{
struct V_191 * V_188 ;
struct V_1 * V_2 = (struct V_1 * ) V_31 -> V_161 ;
V_188 = & V_2 -> V_194 [ V_193 ] ;
memcpy ( & V_188 -> V_190 , V_190 , sizeof( * V_190 ) ) ;
F_82 ( & V_188 -> V_188 , F_80 ) ;
F_83 ( V_2 -> V_195 , & V_188 -> V_188 ) ;
}
static void F_84 ( struct V_187 * V_188 )
{
struct V_65 * V_69 =
( (struct V_191 * ) V_188 ) -> V_69 ;
struct V_196 V_197 ;
struct V_198 * V_199 =
& V_69 -> V_93 . V_126 . V_127 . V_200 . V_93 ;
struct V_1 * V_2 =
(struct V_1 * ) V_69 -> V_93 . V_126 . V_127 . V_200 . V_31 -> V_161 ;
V_197 . V_67 = NULL ;
V_197 . V_104 = V_69 -> V_103 . V_104 ;
V_197 . V_105 = V_69 -> V_103 . V_105 ;
V_197 . V_201 = V_69 -> V_103 . V_201 ;
V_197 . V_202 = V_69 -> V_103 . V_202 ;
V_197 . V_129 = 0 ;
V_197 . error = V_69 -> V_103 . error ;
V_199 -> V_81 ( V_69 -> V_93 . V_126 . V_127 . V_200 . V_31 ,
V_199 -> V_203 , & V_197 ) ;
F_33 ( & V_2 -> V_67 , V_69 ) ;
}
static void F_85 ( struct V_65 * V_69 ,
T_1 V_204 )
{
struct V_191 * V_188 ;
struct V_198 * V_199 =
& V_69 -> V_93 . V_126 . V_127 . V_200 . V_93 ;
struct V_1 * V_2 =
(struct V_1 * ) V_69 -> V_93 . V_126 . V_127 . V_200 . V_31 ->
V_161 ;
if ( V_199 && V_199 -> V_81 ) {
F_56 ( & V_2 -> V_109 , V_205 , L_11 , V_206 ) ;
F_49 ( & V_69 -> V_78 ) ;
V_188 = & V_2 -> V_194 [ V_199 -> V_193 ] ;
V_188 -> V_69 = V_69 ;
F_82 ( & V_188 -> V_188 , F_84 ) ;
F_83 ( V_2 -> V_195 , & V_188 -> V_188 ) ;
F_56 ( & V_2 -> V_109 , V_205 , L_12 , V_206 ) ;
} else {
F_56 ( & V_2 -> V_109 , V_205 , L_13 , V_206 ) ;
}
}
enum V_107 F_86 ( struct V_108 * V_31 ,
struct V_198 * V_199 )
{
enum V_107 V_110 ;
struct V_65 * V_69 ;
struct V_92 * V_120 ;
struct V_1 * V_2 = (struct V_1 * ) V_31 -> V_161 ;
F_56 ( & V_2 -> V_109 , V_205 , L_6 , V_206 ) ;
V_69 = F_19 ( & V_2 -> V_67 , false ) ;
if ( ! V_69 )
return V_157 ;
V_120 = & V_69 -> V_93 ;
V_69 -> V_81 = F_85 ;
V_69 -> V_85 = V_199 ;
memcpy ( & V_120 -> V_126 . V_127 . V_200 . V_93 , V_199 ,
sizeof( * V_199 ) ) ;
V_120 -> V_126 . V_127 . V_200 . V_31 = V_31 ;
V_120 -> V_99 = V_207 ;
V_120 -> V_125 = 1 ;
V_120 -> V_126 . V_127 . V_200 . V_129 = ( V_130 ) V_69 ;
V_110 = F_42 ( V_2 , V_69 ) ;
if ( V_110 )
F_28 ( L_14 ) ;
return V_110 ;
}
enum V_107 F_87 ( struct V_108 * V_31 ,
struct V_146 * V_208 ,
T_2 V_209 )
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
V_120 -> V_126 . V_127 . V_210 . V_67 = V_31 -> V_67 ;
V_120 -> V_126 . V_127 . V_210 . V_211 = V_208 -> V_155 ;
V_120 -> V_126 . V_127 . V_210 . V_212 = V_208 -> V_153 ;
V_120 -> V_126 . V_127 . V_210 . V_209 = V_209 ;
V_120 -> V_99 = V_213 ;
V_120 -> V_125 = 1 ;
V_120 -> V_126 . V_127 . V_210 . V_129 = ( V_130 ) V_69 ;
V_110 = F_42 ( V_2 , V_69 ) ;
if ( V_110 )
F_28 ( L_15 ) ;
return V_110 ;
}
enum V_107 F_88 ( struct V_108 * V_31 ,
struct V_146 * V_208 ,
T_2 V_209 )
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
V_120 -> V_126 . V_127 . V_214 . V_67 = V_31 -> V_67 ;
V_120 -> V_126 . V_127 . V_214 . V_211 = V_208 -> V_155 ;
V_120 -> V_126 . V_127 . V_214 . V_212 = V_208 -> V_153 ;
V_120 -> V_126 . V_127 . V_214 . V_209 = V_209 ;
V_120 -> V_99 = V_215 ;
V_120 -> V_125 = 1 ;
V_120 -> V_126 . V_127 . V_214 . V_129 = ( V_130 ) V_69 ;
V_110 = F_42 ( V_2 , V_69 ) ;
if ( V_110 )
F_28 ( L_16 ) ;
return V_110 ;
}
enum V_107 F_89 ( struct V_108 * V_31 )
{
struct V_1 * V_2 = V_31 -> V_161 ;
int V_97 ;
F_56 ( V_31 , V_216 , L_17 ,
V_206 , __LINE__ , V_31 , V_2 ) ;
F_29 ( & V_2 -> V_217 , 2 ) ;
V_97 = F_40 ( V_2 -> V_218 ,
( F_90 ( & V_2 -> V_217 ) == 1 ) ,
V_219 ) ;
F_91 ( & V_2 -> V_217 ) ;
if ( ! V_97 ) {
F_28 ( L_18 , V_97 ) ;
F_29 ( & V_2 -> V_217 , 0 ) ;
V_31 -> V_220 = false ;
return V_221 ;
}
F_47 ( & V_31 -> V_222 ) ;
return 0 ;
}
enum V_107 F_92 ( struct V_108 * V_31 ,
struct V_223 * V_224 )
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
V_120 -> V_99 = V_225 ;
V_120 -> V_125 = 1 ;
V_120 -> V_126 . V_127 . V_226 . V_224 = V_224 ;
V_120 -> V_126 . V_127 . V_226 . V_129 = ( V_130 ) V_69 ;
V_110 = F_42 ( V_2 , V_69 ) ;
if ( V_110 )
F_28 ( L_19 ) ;
return V_110 ;
}
enum V_107 F_93 ( struct V_108 * V_31 ,
struct V_83 * V_84 )
{
struct V_1 * V_2 = (struct V_1 * ) V_31 -> V_161 ;
struct V_66 * V_94 = & V_2 -> V_67 ;
struct V_65 * V_69 ;
struct V_92 * V_120 ;
struct V_227 * V_228 ;
enum V_107 V_110 ;
V_69 = F_19 ( V_94 , true ) ;
if ( ! V_69 )
return V_157 ;
V_120 = & V_69 -> V_93 ;
V_228 = & V_69 -> V_93 . V_126 . V_127 . V_229 . V_93 ;
memset ( V_228 , 0 , sizeof( * V_228 ) ) ;
V_228 -> V_230 = true ;
V_228 -> V_173 = V_231 ;
V_120 -> V_99 = V_232 ;
V_120 -> V_125 = 1 ;
V_120 -> V_126 . V_127 . V_229 . V_84 = V_84 ;
V_120 -> V_126 . V_127 . V_229 . V_129 = ( V_130 ) V_69 ;
V_110 = F_42 ( V_2 , V_69 ) ;
if ( V_110 )
F_28 ( L_20 ) ;
return V_110 ;
}
void F_94 ( struct V_108 * V_31 , struct V_223 * V_224 )
{
struct V_1 * V_2 = (struct V_1 * ) V_31 -> V_161 ;
F_95 ( V_2 , V_224 ) ;
}
void F_96 ( struct V_108 * V_31 , struct V_83 * V_84 )
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
void F_97 ( struct V_108 * V_31 , struct V_83 * V_84 )
{
struct V_233 V_93 ;
struct V_1 * V_2 = (struct V_1 * ) V_31 -> V_161 ;
F_56 ( V_31 , V_234 , L_22 , V_206 ) ;
memset ( & V_93 , 0 , sizeof( V_93 ) ) ;
V_93 . V_235 = V_236 ;
V_93 . V_237 = true ;
V_93 . V_238 = 0x3 ;
( void ) F_98 ( V_2 , V_84 , & V_93 , false ) ;
}
enum V_107 F_99 ( struct V_239 * * V_138 )
{
struct V_240 * V_241 ;
struct V_239 * V_242 ;
V_241 = F_100 ( L_23 , 0 , 0 ) ;
if ( F_101 ( V_241 ) )
return V_243 ;
V_242 = F_25 ( sizeof( * V_242 ) + F_102 ( V_241 ) ,
V_156 ) ;
if ( ! V_242 ) {
F_103 ( V_241 ) ;
return V_243 ;
}
V_242 -> V_241 = V_241 ;
* V_138 = V_242 ;
return 0 ;
}
void F_104 ( struct V_239 * V_138 )
{
if ( V_138 ) {
F_103 ( V_138 -> V_241 ) ;
F_31 ( V_138 ) ;
}
}
enum V_107 F_105 ( struct V_108 * V_31 ,
struct V_146 * V_147 )
{
enum V_107 V_110 ;
struct V_1 * V_2 = (struct V_1 * ) V_31 -> V_161 ;
V_110 = F_106 ( V_2 , V_147 , V_244 ,
V_245 ) ;
return V_110 ;
}
enum V_107 F_107 ( struct V_239 * V_138 ,
void * V_53 ,
T_1 V_246 ,
T_1 V_20 )
{
T_1 V_247 = 0 ;
int V_248 ;
enum V_107 V_249 = 0 ;
F_108 ( V_138 ) ;
V_248 = F_109 ( V_138 , V_53 , V_246 ) ;
if ( ! V_248 )
F_110 ( V_138 , ( T_2 * ) & V_247 ) ;
if ( V_247 != V_20 ) {
F_28 ( L_24 ) ;
V_249 = V_243 ;
}
return V_249 ;
}
struct V_83 * F_111 ( struct V_108 * V_31 ,
struct V_250 * V_139 )
{
struct V_1 * V_2 = (struct V_1 * ) V_31 -> V_161 ;
struct V_86 * V_87 ;
struct V_251 * V_252 ;
T_1 V_253 [ 4 ] , V_254 [ 4 ] ;
T_6 V_255 , V_256 ;
struct V_257 * V_258 ;
struct V_259 * V_260 = (struct V_259 * ) V_139 -> V_260 ;
struct V_261 * V_262 = (struct V_261 * ) V_139 -> V_262 ;
if ( V_260 -> V_263 == 4 ) {
memset ( V_253 , 0 , sizeof( V_253 ) ) ;
V_253 [ 0 ] = F_13 ( V_260 -> V_264 ) ;
memset ( V_254 , 0 , sizeof( V_254 ) ) ;
V_254 [ 0 ] = F_13 ( V_260 -> V_265 ) ;
} else {
V_258 = (struct V_257 * ) V_139 -> V_260 ;
F_17 ( V_253 , V_258 -> V_264 . V_54 . V_55 ) ;
F_17 ( V_254 , V_258 -> V_265 . V_54 . V_55 ) ;
}
V_255 = F_112 ( V_262 -> V_266 ) ;
V_256 = F_112 ( V_262 -> V_267 ) ;
V_252 = F_113 ( & V_2 -> V_268 , V_256 , V_254 , V_255 ,
V_253 , false ) ;
if ( ! V_252 )
return NULL ;
V_87 = V_252 -> V_87 ;
return & V_87 -> V_123 ;
}
void F_114 ( struct V_250 * V_139 , T_6 V_246 , T_1 V_269 )
{
struct V_261 * V_262 ;
struct V_259 * V_260 ;
T_6 V_270 ;
T_6 V_271 ;
T_2 * V_53 = ( T_2 * ) V_139 -> V_147 . V_153 ;
V_270 = ( V_139 -> V_4 ) ? 20 : 40 ;
V_260 = (struct V_259 * ) ( V_53 + V_139 -> V_272 ) ;
V_262 = (struct V_261 * ) ( V_53 + V_139 -> V_272 + V_270 ) ;
V_271 = V_246 + V_139 -> V_273 + V_270 ;
V_260 -> V_274 = F_115 ( V_271 ) ;
V_262 -> V_275 = F_116 ( V_269 ) ;
}
enum V_107 F_117 ( struct V_276 * V_93 ,
struct V_250 * V_139 )
{
struct V_259 * V_260 ;
struct V_257 * V_258 ;
struct V_261 * V_262 ;
T_6 V_270 ;
T_6 V_277 ;
T_2 * V_147 = ( T_2 * ) V_139 -> V_147 . V_153 ;
struct V_278 * V_279 = (struct V_278 * ) V_139 -> V_147 . V_153 ;
if ( V_279 -> V_280 == F_115 ( 0x8100 ) ) {
V_93 -> V_281 = true ;
V_139 -> V_282 = F_112 ( ( (struct V_283 * ) V_279 ) -> V_284 ) & V_285 ;
}
V_139 -> V_272 = ( V_93 -> V_281 ) ? 18 : 14 ;
V_270 = ( V_93 -> V_286 ) ? 40 : 20 ;
V_139 -> V_4 = ( V_93 -> V_286 ) ? false : true ;
V_139 -> V_260 = V_147 + V_139 -> V_272 ;
V_260 = (struct V_259 * ) V_139 -> V_260 ;
V_139 -> V_262 = V_139 -> V_260 + V_270 ;
V_262 = (struct V_261 * ) V_139 -> V_262 ;
if ( V_139 -> V_4 ) {
V_277 = F_112 ( V_260 -> V_274 ) ;
} else {
V_258 = (struct V_257 * ) V_139 -> V_260 ;
V_277 = F_112 ( V_258 -> V_287 ) + V_270 ;
}
V_139 -> V_288 = V_277 + V_139 -> V_272 ;
if ( V_93 -> V_287 < V_139 -> V_288 ) {
F_28 ( L_25 ,
V_93 -> V_287 , V_139 -> V_288 ) ;
return V_289 ;
}
V_139 -> V_273 = ( V_262 -> V_290 ) << 2 ;
V_139 -> V_291 = V_277 - V_270 - V_139 -> V_273 ;
V_139 -> V_292 = ( V_139 -> V_291 ) ? V_139 -> V_262 + V_139 -> V_273 : NULL ;
V_139 -> V_293 = V_139 -> V_272 + V_270 + V_139 -> V_273 ;
V_139 -> V_269 = F_13 ( V_262 -> V_275 ) ;
return 0 ;
}
static void F_118 ( unsigned long V_294 )
{
struct V_295 * V_296 = (struct V_295 * ) V_294 ;
struct V_108 * V_297 = V_296 -> V_31 ;
struct V_298 * V_299 = V_296 -> V_300 ;
struct V_298 * V_301 = NULL ;
T_6 V_193 ;
unsigned long V_70 ;
F_119 ( V_299 , & V_299 -> V_302 ) ;
for ( V_193 = 0 ; V_193 < V_303 ; V_193 ++ ) {
F_20 ( & V_299 -> V_177 , V_70 ) ;
if ( V_297 -> V_304 [ V_193 ] ) {
if ( V_297 -> V_304 [ V_193 ] -> V_305 ) {
V_301 = & V_297 -> V_304 [ V_193 ] -> V_300 ;
F_119 ( V_301 , & V_301 -> V_302 ) ;
}
}
F_24 ( & V_299 -> V_177 , V_70 ) ;
}
F_120 ( & V_299 -> V_306 ,
V_185 + F_121 ( V_307 ) ) ;
}
void F_122 ( struct V_295 * V_294 )
{
struct V_298 * V_308 = V_294 -> V_300 ;
F_77 ( & V_308 -> V_306 , F_118 ,
( unsigned long ) V_294 ) ;
F_120 ( & V_308 -> V_306 ,
V_185 + F_121 ( V_307 ) ) ;
}
void F_123 ( struct V_295 * V_294 )
{
struct V_298 * V_308 = V_294 -> V_300 ;
F_124 ( & V_308 -> V_306 ) ;
}
