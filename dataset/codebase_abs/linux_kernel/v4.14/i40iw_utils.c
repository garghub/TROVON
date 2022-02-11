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
if ( V_2 -> V_39 < V_40 || V_2 -> V_41 )
return V_37 ;
V_32 = V_2 -> V_42 -> V_32 ;
V_33 = F_12 ( V_32 ) ;
if ( V_32 != V_29 )
return V_37 ;
if ( V_33 )
V_36 = F_13 (
( (struct V_43 * ) V_33 -> V_44 ) -> V_45 -> V_46 ) ;
else
V_36 = F_13 ( V_27 -> V_46 ) ;
switch ( V_24 ) {
case V_47 :
V_6 = V_16 ;
case V_48 :
case V_49 :
F_14 ( V_2 ,
V_32 -> V_50 ,
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
struct V_51 * V_27 = (struct V_51 * ) V_25 ;
struct V_28 * V_29 = V_27 -> V_52 -> V_31 ;
struct V_28 * V_32 ;
struct V_1 * V_2 ;
struct V_34 * V_35 ;
T_1 V_53 [ 4 ] ;
T_1 V_6 = V_12 ;
V_35 = F_11 ( V_29 ) ;
if ( ! V_35 )
return V_37 ;
V_2 = & V_35 -> V_38 ;
if ( V_2 -> V_39 < V_40 || V_2 -> V_41 )
return V_37 ;
V_32 = V_2 -> V_42 -> V_32 ;
if ( V_32 != V_29 )
return V_37 ;
F_17 ( V_53 , V_27 -> V_54 . V_55 . V_56 ) ;
switch ( V_24 ) {
case V_47 :
V_6 = V_16 ;
case V_48 :
case V_49 :
F_14 ( V_2 ,
V_32 -> V_50 ,
V_53 ,
false ,
V_6 ) ;
F_15 ( V_2 , V_32 , V_53 , false ,
( V_6 == V_12 ) ? true : false ) ;
break;
default:
break;
}
return V_37 ;
}
int F_18 ( struct V_22 * V_23 , unsigned long V_24 , void * V_25 )
{
struct V_57 * V_58 = V_25 ;
struct V_1 * V_2 ;
struct V_34 * V_59 ;
T_3 * V_60 ;
T_1 V_36 [ 4 ] ;
switch ( V_24 ) {
case V_61 :
V_59 = F_11 ( (struct V_28 * ) V_58 -> V_31 ) ;
if ( ! V_59 )
return V_37 ;
V_2 = & V_59 -> V_38 ;
if ( V_2 -> V_39 < V_40 || V_2 -> V_41 )
return V_37 ;
V_60 = ( T_3 * ) V_58 -> V_62 ;
F_17 ( V_36 , V_60 ) ;
if ( V_58 -> V_63 & V_64 ) {
F_14 ( V_2 ,
V_58 -> V_65 ,
V_36 ,
false ,
V_12 ) ;
} else {
F_14 ( V_2 ,
V_58 -> V_65 ,
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
struct V_66 * F_19 ( struct V_67 * V_68 , bool V_69 )
{
struct V_66 * V_70 = NULL ;
unsigned long V_71 ;
F_20 ( & V_68 -> V_72 , V_71 ) ;
if ( ! F_21 ( & V_68 -> V_73 ) ) {
V_70 = F_22 ( V_68 -> V_73 . V_74 ,
struct V_66 , V_75 ) ;
F_23 ( & V_70 -> V_75 ) ;
}
F_24 ( & V_68 -> V_72 , V_71 ) ;
if ( ! V_70 ) {
V_70 = F_25 ( sizeof( * V_70 ) , V_76 ) ;
if ( V_70 ) {
V_70 -> V_77 = true ;
F_26 ( & V_70 -> V_75 ) ;
F_27 ( & V_70 -> V_78 ) ;
}
}
if ( ! V_70 ) {
F_28 ( L_1 ) ;
return NULL ;
}
if ( V_69 ) {
F_29 ( & V_70 -> V_79 , 2 ) ;
V_70 -> V_80 = true ;
} else {
F_29 ( & V_70 -> V_79 , 1 ) ;
}
return V_70 ;
}
void F_30 ( struct V_67 * V_68 , struct V_66 * V_70 )
{
struct V_1 * V_2 = F_31 ( V_68 , struct V_1 , V_68 ) ;
unsigned long V_71 ;
if ( V_70 -> V_77 ) {
F_32 ( V_70 ) ;
} else {
V_70 -> V_81 = false ;
V_70 -> V_82 = NULL ;
V_70 -> V_80 = false ;
F_20 ( & V_68 -> V_72 , V_71 ) ;
F_33 ( & V_70 -> V_75 , & V_68 -> V_73 ) ;
F_24 ( & V_68 -> V_72 , V_71 ) ;
}
F_34 ( & V_2 -> V_83 ) ;
}
void F_35 ( struct V_67 * V_68 ,
struct V_66 * V_70 )
{
if ( F_36 ( & V_70 -> V_79 ) )
F_30 ( V_68 , V_70 ) ;
}
static void F_37 ( struct V_67 * V_68 ,
struct V_66 * V_70 )
{
struct V_1 * V_2 = F_31 ( V_68 , struct V_1 , V_68 ) ;
if ( V_70 -> V_80 ) {
V_70 -> V_84 . error = true ;
V_70 -> V_81 = true ;
F_34 ( & V_70 -> V_78 ) ;
}
F_35 ( V_68 , V_70 ) ;
F_38 ( V_2 -> V_83 ,
! F_39 ( & V_70 -> V_79 ) ,
1000 ) ;
}
void F_40 ( struct V_1 * V_2 )
{
struct V_85 * V_31 = & V_2 -> V_86 ;
struct V_67 * V_68 = & V_2 -> V_68 ;
struct V_66 * V_70 = NULL ;
struct V_87 * V_88 = NULL ;
T_1 V_89 , V_90 , V_91 ;
V_90 = F_41 ( V_68 -> V_92 . V_93 ) ;
V_91 = F_42 ( V_68 -> V_92 . V_93 ) ;
for ( V_89 = 0 ; V_89 < V_90 ; V_89 ++ ) {
V_70 = (struct V_66 * ) ( unsigned long ) V_68 -> V_94 [ V_91 ] ;
if ( V_70 )
F_37 ( V_68 , V_70 ) ;
V_91 = ( V_91 + 1 ) % F_43 ( V_68 -> V_92 . V_93 ) ;
}
while ( ! F_21 ( & V_31 -> V_95 ) ) {
V_88 = (struct V_87 * ) F_44 ( & V_31 -> V_95 ) ;
V_70 = F_31 ( V_88 , struct V_66 , V_96 ) ;
if ( V_70 )
F_37 ( V_68 , V_70 ) ;
}
}
static void F_45 ( struct V_66 * V_70 , T_1 V_97 )
{
struct V_98 * V_99 = (struct V_98 * ) V_70 -> V_100 ;
struct V_101 * V_102 = (struct V_101 * ) V_99 -> V_103 ;
struct V_1 * V_2 ;
T_1 V_104 = V_102 -> V_105 . V_104 ;
V_2 = V_102 -> V_2 ;
F_46 ( V_102 -> V_106 , V_2 ) ;
F_47 ( V_2 , V_102 , V_104 ) ;
F_48 ( V_2 ) ;
}
static int F_49 ( struct V_1 * V_2 ,
struct V_66 * V_70 )
{
struct V_87 * V_96 = & V_70 -> V_96 ;
struct V_67 * V_107 = & V_2 -> V_68 ;
struct V_108 V_109 ;
bool V_110 = false ;
int V_111 = 0 ;
memset ( & V_109 , 0 , sizeof( V_109 ) ) ;
V_109 . V_112 = V_2 -> V_86 . V_113 [ V_114 ] ;
do {
if ( F_38 ( V_70 -> V_78 ,
V_70 -> V_81 , V_115 ) )
break;
F_50 ( & V_109 , & V_2 -> V_86 ) ;
if ( V_109 . V_116 < V_117 )
continue;
F_28 ( L_2 , V_96 -> V_118 ) ;
V_111 = - V_119 ;
if ( ! V_2 -> V_120 ) {
V_2 -> V_120 = true ;
F_51 ( V_2 ) ;
}
goto V_121;
} while ( 1 );
V_110 = V_70 -> V_84 . error ;
if ( V_110 ) {
F_28 ( L_3 ,
V_96 -> V_118 , V_70 -> V_84 . V_122 ,
V_70 -> V_84 . V_123 ) ;
V_111 = - V_124 ;
goto V_121;
}
V_121:
F_35 ( V_107 , V_70 ) ;
return V_111 ;
}
enum V_125 F_52 ( struct V_1 * V_2 ,
struct V_66
* V_70 )
{
struct V_85 * V_31 = & V_2 -> V_86 ;
enum V_125 V_126 ;
struct V_87 * V_96 = & V_70 -> V_96 ;
int V_111 = 0 ;
if ( V_2 -> V_120 ) {
F_30 ( & V_2 -> V_68 , V_70 ) ;
return V_127 ;
}
V_126 = F_53 ( V_31 , V_96 ) ;
if ( V_126 ) {
F_28 ( L_4 , V_96 -> V_118 ) ;
F_30 ( & V_2 -> V_68 , V_70 ) ;
return V_126 ;
}
if ( V_70 -> V_80 )
V_111 = F_49 ( V_2 , V_70 ) ;
if ( V_111 )
V_126 = V_127 ;
return V_126 ;
}
void F_54 ( struct V_1 * V_2 )
{
F_55 ( & V_2 -> V_128 ) ;
}
void F_48 ( struct V_1 * V_2 )
{
if ( ! F_56 ( & V_2 -> V_128 ) )
return;
F_34 ( & V_2 -> V_83 ) ;
}
void F_57 ( struct V_129 * V_106 )
{
F_58 ( & V_106 -> V_130 ) ;
}
void F_46 ( struct V_129 * V_106 , struct V_1 * V_2 )
{
if ( ! F_36 ( & V_106 -> V_130 ) )
return;
F_5 ( V_2 , V_2 -> V_131 , V_106 -> V_132 . V_133 ) ;
F_32 ( V_106 ) ;
}
void F_59 ( struct V_134 * V_105 )
{
struct V_101 * V_102 = (struct V_101 * ) V_105 ;
F_58 ( & V_102 -> V_79 ) ;
}
void F_60 ( struct V_134 * V_105 )
{
struct V_101 * V_102 ;
enum V_125 V_126 ;
struct V_66 * V_70 ;
struct V_87 * V_135 ;
struct V_1 * V_2 ;
T_1 V_104 ;
unsigned long V_71 ;
V_102 = F_61 ( V_105 ) ;
V_2 = V_102 -> V_2 ;
F_20 ( & V_2 -> V_136 , V_71 ) ;
if ( ! F_36 ( & V_102 -> V_79 ) ) {
F_24 ( & V_2 -> V_136 , V_71 ) ;
return;
}
V_104 = V_102 -> V_105 . V_104 ;
V_2 -> V_137 [ V_104 ] = NULL ;
F_24 ( & V_2 -> V_136 , V_71 ) ;
V_70 = F_19 ( & V_2 -> V_68 , false ) ;
if ( ! V_70 )
return;
V_70 -> V_82 = F_45 ;
V_70 -> V_100 = ( void * ) & V_102 -> V_138 ;
V_135 = & V_70 -> V_96 ;
V_135 -> V_118 = V_139 ;
V_135 -> V_140 = 1 ;
V_135 -> V_141 . V_142 . V_143 . V_99 = & V_102 -> V_138 ;
V_135 -> V_141 . V_142 . V_143 . V_144 = ( V_145 ) V_70 ;
V_135 -> V_141 . V_142 . V_143 . V_146 = true ;
V_126 = F_52 ( V_2 , V_70 ) ;
if ( ! V_126 )
return;
F_46 ( V_102 -> V_106 , V_2 ) ;
F_47 ( V_2 , V_102 , V_104 ) ;
F_48 ( V_2 ) ;
}
struct V_134 * F_62 ( struct V_147 * V_38 , int V_148 )
{
struct V_1 * V_2 = F_63 ( V_38 ) ;
if ( ( V_148 < V_149 ) || ( V_148 >= V_2 -> V_150 ) )
return NULL ;
return & V_2 -> V_137 [ V_148 ] -> V_105 ;
}
void F_64 ( struct V_85 * V_31 ,
enum V_151 V_152 ,
char * V_153 ,
T_4 * V_154 ,
T_1 V_155 )
{
T_1 V_89 ;
if ( ! ( V_31 -> V_156 & V_152 ) )
return;
F_65 ( V_31 , V_152 , L_5 , V_153 ) ;
F_65 ( V_31 , V_152 , L_6 , V_154 ,
( unsigned long long ) F_66 ( V_154 ) ) ;
for ( V_89 = 0 ; V_89 < V_155 ; V_89 += 8 )
F_65 ( V_31 , V_152 , L_7 , V_89 , V_154 [ V_89 / 8 ] ) ;
}
T_2 T_5 * F_67 ( void * V_157 )
{
struct V_85 * V_31 = (struct V_85 * ) V_157 ;
return V_31 -> V_18 -> V_21 ;
}
void * F_44 ( struct V_158 * V_75 )
{
struct V_158 * V_159 ;
if ( F_21 ( V_75 ) )
return NULL ;
V_159 = ( void * ) V_75 -> V_74 ;
F_68 ( V_159 ) ;
return ( void * ) V_159 ;
}
enum V_125 F_69 ( struct V_17 * V_18 ,
struct V_160 * V_161 ,
T_4 V_155 ,
T_1 V_162 )
{
struct V_163 * V_164 = (struct V_163 * ) V_18 -> V_165 ;
if ( ! V_161 )
return V_166 ;
V_161 -> V_155 = F_70 ( V_155 , V_162 ) ;
V_161 -> V_167 = F_71 ( & V_164 -> V_31 , V_161 -> V_155 ,
( V_168 * ) & V_161 -> V_169 , V_170 ) ;
if ( ! V_161 -> V_167 )
return V_171 ;
return 0 ;
}
void F_72 ( struct V_17 * V_18 , struct V_160 * V_161 )
{
struct V_163 * V_164 = (struct V_163 * ) V_18 -> V_165 ;
if ( ! V_161 || ! V_161 -> V_167 )
return;
F_73 ( & V_164 -> V_31 , V_161 -> V_155 ,
V_161 -> V_167 , ( V_168 ) V_161 -> V_169 ) ;
V_161 -> V_167 = NULL ;
}
enum V_125 F_74 ( struct V_17 * V_18 ,
struct V_172 * V_161 ,
T_1 V_155 )
{
if ( ! V_161 )
return V_166 ;
V_161 -> V_155 = V_155 ;
V_161 -> V_167 = F_25 ( V_155 , V_170 ) ;
if ( V_161 -> V_167 )
return 0 ;
else
return V_171 ;
}
enum V_125 F_75 ( struct V_17 * V_18 ,
struct V_172 * V_161 )
{
if ( ! V_161 )
return V_166 ;
F_32 ( V_161 -> V_167 ) ;
return 0 ;
}
enum V_125 F_76 ( struct V_85 * V_31 ,
struct V_173 * V_174 )
{
enum V_125 V_126 ;
struct V_66 * V_70 ;
struct V_87 * V_135 ;
struct V_1 * V_2 = (struct V_1 * ) V_31 -> V_175 ;
V_70 = F_19 ( & V_2 -> V_68 , true ) ;
if ( ! V_70 )
return V_171 ;
V_135 = & V_70 -> V_96 ;
memcpy ( & V_135 -> V_141 . V_142 . V_176 . V_96 , V_174 ,
sizeof( V_135 -> V_141 . V_142 . V_176 . V_96 ) ) ;
V_135 -> V_118 = V_177 ;
V_135 -> V_140 = 1 ;
V_135 -> V_141 . V_142 . V_176 . V_31 = V_31 ;
V_135 -> V_141 . V_142 . V_176 . V_144 = ( V_145 ) V_70 ;
V_126 = F_52 ( V_2 , V_70 ) ;
if ( V_126 )
F_28 ( L_8 ) ;
return V_126 ;
}
void F_77 ( struct V_85 * V_31 , struct V_98 * V_99 , bool V_178 )
{
struct V_1 * V_2 = (struct V_1 * ) V_31 -> V_175 ;
struct V_66 * V_70 ;
struct V_179 * V_68 = V_31 -> V_68 ;
struct V_87 * V_135 ;
enum V_125 V_126 ;
V_70 = F_19 ( & V_2 -> V_68 , false ) ;
if ( ! V_70 )
return;
V_135 = & V_70 -> V_96 ;
V_135 -> V_118 = ( V_178 ) ? V_180 : V_181 ;
V_135 -> V_141 . V_142 . V_182 . V_68 = V_68 ;
V_135 -> V_141 . V_142 . V_182 . V_99 = V_99 ;
V_135 -> V_141 . V_142 . V_182 . V_144 = ( V_145 ) V_70 ;
V_126 = F_52 ( V_2 , V_70 ) ;
if ( V_126 )
F_28 ( L_9 ) ;
}
void F_78 ( struct V_98 * V_99 , T_2 V_183 , T_2 V_184 , T_2 V_185 )
{
struct V_101 * V_102 ;
V_102 = (struct V_101 * ) V_99 -> V_103 ;
F_79 ( V_102 , V_183 , 0 , V_184 , V_185 ) ;
}
void F_80 ( struct V_98 * V_99 , int V_186 )
{
struct V_101 * V_102 ;
T_1 V_187 = V_188 ;
T_2 V_189 = 0 ;
bool V_190 ;
unsigned long V_71 ;
V_102 = (struct V_101 * ) V_99 -> V_103 ;
F_20 ( & V_102 -> V_191 , V_71 ) ;
if ( V_102 -> V_192 ) {
V_102 -> V_192 = 0 ;
V_189 = 1 ;
}
V_190 = ! ( V_99 -> V_193 & V_194 ) ;
V_99 -> V_193 |= V_194 ;
F_24 ( & V_102 -> V_191 , V_71 ) ;
if ( V_190 ) {
if ( ! V_186 )
F_81 ( V_99 ) ;
else
V_187 = V_195 ;
F_79 ( V_102 , V_187 , V_189 , 0 , 0 ) ;
F_82 ( V_102 ) ;
}
}
static void F_83 ( unsigned long V_196 )
{
struct V_101 * V_102 = (struct V_101 * ) V_196 ;
struct V_98 * V_99 = (struct V_98 * ) & V_102 -> V_138 ;
F_80 ( V_99 , 1 ) ;
F_60 ( & V_102 -> V_105 ) ;
}
void F_84 ( struct V_98 * V_99 )
{
struct V_101 * V_102 ;
V_102 = (struct V_101 * ) V_99 -> V_103 ;
F_59 ( & V_102 -> V_105 ) ;
F_85 ( & V_102 -> V_197 , F_83 ,
( unsigned long ) V_102 ) ;
V_102 -> V_197 . V_198 = V_199 + V_200 ;
F_86 ( & V_102 -> V_197 ) ;
}
void F_81 ( struct V_98 * V_99 )
{
struct V_101 * V_102 ;
V_102 = (struct V_101 * ) V_99 -> V_103 ;
if ( F_87 ( & V_102 -> V_197 ) )
F_60 ( & V_102 -> V_105 ) ;
}
static void F_88 ( struct V_201 * V_202 )
{
struct V_203 * V_204 =
& ( (struct V_205 * ) V_202 ) -> V_204 ;
if ( V_204 -> V_206 )
V_204 -> V_82 ( V_204 -> V_206 ) ;
}
void F_89 ( struct V_85 * V_31 ,
struct V_203 * V_204 ,
T_1 V_207 )
{
struct V_205 * V_202 ;
struct V_1 * V_2 = (struct V_1 * ) V_31 -> V_175 ;
V_202 = & V_2 -> V_208 [ V_207 ] ;
memcpy ( & V_202 -> V_204 , V_204 , sizeof( * V_204 ) ) ;
F_90 ( & V_202 -> V_202 , F_88 ) ;
F_91 ( V_2 -> V_209 , & V_202 -> V_202 ) ;
}
static void F_92 ( struct V_201 * V_202 )
{
struct V_66 * V_70 =
( (struct V_205 * ) V_202 ) -> V_70 ;
struct V_210 V_211 ;
struct V_212 * V_213 =
& V_70 -> V_96 . V_141 . V_142 . V_214 . V_96 ;
struct V_1 * V_2 =
(struct V_1 * ) V_70 -> V_96 . V_141 . V_142 . V_214 . V_31 -> V_175 ;
V_211 . V_68 = NULL ;
V_211 . V_122 = V_70 -> V_84 . V_122 ;
V_211 . V_123 = V_70 -> V_84 . V_123 ;
V_211 . V_215 = V_70 -> V_84 . V_215 ;
V_211 . V_216 = V_70 -> V_84 . V_216 ;
V_211 . V_144 = 0 ;
V_211 . error = V_70 -> V_84 . error ;
V_213 -> V_82 ( V_70 -> V_96 . V_141 . V_142 . V_214 . V_31 ,
V_213 -> V_217 , & V_211 ) ;
F_35 ( & V_2 -> V_68 , V_70 ) ;
}
static void F_93 ( struct V_66 * V_70 ,
T_1 V_218 )
{
struct V_205 * V_202 ;
struct V_212 * V_213 =
& V_70 -> V_96 . V_141 . V_142 . V_214 . V_96 ;
struct V_1 * V_2 =
(struct V_1 * ) V_70 -> V_96 . V_141 . V_142 . V_214 . V_31 ->
V_175 ;
if ( V_213 && V_213 -> V_82 ) {
F_65 ( & V_2 -> V_86 , V_219 , L_10 , V_220 ) ;
F_58 ( & V_70 -> V_79 ) ;
V_202 = & V_2 -> V_208 [ V_213 -> V_207 ] ;
V_202 -> V_70 = V_70 ;
F_90 ( & V_202 -> V_202 , F_92 ) ;
F_91 ( V_2 -> V_209 , & V_202 -> V_202 ) ;
F_65 ( & V_2 -> V_86 , V_219 , L_11 , V_220 ) ;
} else {
F_65 ( & V_2 -> V_86 , V_219 , L_12 , V_220 ) ;
}
}
enum V_125 F_94 ( struct V_85 * V_31 ,
struct V_212 * V_213 )
{
enum V_125 V_126 ;
struct V_66 * V_70 ;
struct V_87 * V_135 ;
struct V_1 * V_2 = (struct V_1 * ) V_31 -> V_175 ;
F_65 ( & V_2 -> V_86 , V_219 , L_5 , V_220 ) ;
V_70 = F_19 ( & V_2 -> V_68 , false ) ;
if ( ! V_70 )
return V_171 ;
V_135 = & V_70 -> V_96 ;
V_70 -> V_82 = F_93 ;
V_70 -> V_100 = V_213 ;
memcpy ( & V_135 -> V_141 . V_142 . V_214 . V_96 , V_213 ,
sizeof( * V_213 ) ) ;
V_135 -> V_141 . V_142 . V_214 . V_31 = V_31 ;
V_135 -> V_118 = V_221 ;
V_135 -> V_140 = 1 ;
V_135 -> V_141 . V_142 . V_214 . V_144 = ( V_145 ) V_70 ;
V_126 = F_52 ( V_2 , V_70 ) ;
if ( V_126 )
F_28 ( L_13 ) ;
return V_126 ;
}
enum V_125 F_95 ( struct V_85 * V_31 ,
struct V_160 * V_222 ,
T_2 V_223 )
{
enum V_125 V_126 ;
struct V_66 * V_70 ;
struct V_87 * V_135 ;
struct V_1 * V_2 = (struct V_1 * ) V_31 -> V_175 ;
V_70 = F_19 ( & V_2 -> V_68 , true ) ;
if ( ! V_70 )
return V_171 ;
V_135 = & V_70 -> V_96 ;
V_70 -> V_100 = NULL ;
V_135 -> V_141 . V_142 . V_224 . V_68 = V_31 -> V_68 ;
V_135 -> V_141 . V_142 . V_224 . V_225 = V_222 -> V_169 ;
V_135 -> V_141 . V_142 . V_224 . V_226 = V_222 -> V_167 ;
V_135 -> V_141 . V_142 . V_224 . V_223 = V_223 ;
V_135 -> V_118 = V_227 ;
V_135 -> V_140 = 1 ;
V_135 -> V_141 . V_142 . V_224 . V_144 = ( V_145 ) V_70 ;
V_126 = F_52 ( V_2 , V_70 ) ;
if ( V_126 )
F_28 ( L_14 ) ;
return V_126 ;
}
enum V_125 F_96 ( struct V_85 * V_31 ,
struct V_160 * V_222 ,
T_2 V_223 )
{
enum V_125 V_126 ;
struct V_66 * V_70 ;
struct V_87 * V_135 ;
struct V_1 * V_2 = (struct V_1 * ) V_31 -> V_175 ;
V_70 = F_19 ( & V_2 -> V_68 , true ) ;
if ( ! V_70 )
return V_171 ;
V_135 = & V_70 -> V_96 ;
V_70 -> V_100 = NULL ;
V_135 -> V_141 . V_142 . V_228 . V_68 = V_31 -> V_68 ;
V_135 -> V_141 . V_142 . V_228 . V_225 = V_222 -> V_169 ;
V_135 -> V_141 . V_142 . V_228 . V_226 = V_222 -> V_167 ;
V_135 -> V_141 . V_142 . V_228 . V_223 = V_223 ;
V_135 -> V_118 = V_229 ;
V_135 -> V_140 = 1 ;
V_135 -> V_141 . V_142 . V_228 . V_144 = ( V_145 ) V_70 ;
V_126 = F_52 ( V_2 , V_70 ) ;
if ( V_126 )
F_28 ( L_15 ) ;
return V_126 ;
}
enum V_125 F_97 ( struct V_85 * V_31 )
{
struct V_1 * V_2 = V_31 -> V_175 ;
int V_230 ;
F_65 ( V_31 , V_231 , L_16 ,
V_220 , __LINE__ , V_31 , V_2 ) ;
F_29 ( & V_2 -> V_232 , 2 ) ;
V_230 = F_38 ( V_2 -> V_233 ,
( F_39 ( & V_2 -> V_232 ) == 1 ) ,
V_234 ) ;
F_98 ( & V_2 -> V_232 ) ;
if ( ! V_230 ) {
F_28 ( L_17 , V_230 ) ;
F_29 ( & V_2 -> V_232 , 0 ) ;
V_31 -> V_235 = false ;
return V_236 ;
}
F_34 ( & V_31 -> V_237 ) ;
return 0 ;
}
enum V_125 F_99 ( struct V_85 * V_31 ,
struct V_238 * V_239 )
{
struct V_1 * V_2 = (struct V_1 * ) V_31 -> V_175 ;
struct V_67 * V_107 = & V_2 -> V_68 ;
struct V_66 * V_70 ;
struct V_87 * V_135 ;
enum V_125 V_126 ;
V_70 = F_19 ( V_107 , true ) ;
if ( ! V_70 )
return V_171 ;
V_135 = & V_70 -> V_96 ;
V_135 -> V_118 = V_240 ;
V_135 -> V_140 = 1 ;
V_135 -> V_141 . V_142 . V_241 . V_239 = V_239 ;
V_135 -> V_141 . V_142 . V_241 . V_144 = ( V_145 ) V_70 ;
V_126 = F_52 ( V_2 , V_70 ) ;
if ( V_126 )
F_28 ( L_18 ) ;
return V_126 ;
}
enum V_125 F_100 ( struct V_85 * V_31 ,
struct V_98 * V_99 )
{
struct V_1 * V_2 = (struct V_1 * ) V_31 -> V_175 ;
struct V_67 * V_107 = & V_2 -> V_68 ;
struct V_66 * V_70 ;
struct V_87 * V_135 ;
struct V_242 * V_243 ;
enum V_125 V_126 ;
V_70 = F_19 ( V_107 , true ) ;
if ( ! V_70 )
return V_171 ;
V_135 = & V_70 -> V_96 ;
V_243 = & V_70 -> V_96 . V_141 . V_142 . V_244 . V_96 ;
memset ( V_243 , 0 , sizeof( * V_243 ) ) ;
V_243 -> V_245 = true ;
V_243 -> V_187 = V_246 ;
V_135 -> V_118 = V_247 ;
V_135 -> V_140 = 1 ;
V_135 -> V_141 . V_142 . V_244 . V_99 = V_99 ;
V_135 -> V_141 . V_142 . V_244 . V_144 = ( V_145 ) V_70 ;
V_126 = F_52 ( V_2 , V_70 ) ;
if ( V_126 )
F_28 ( L_19 ) ;
return V_126 ;
}
void F_101 ( struct V_85 * V_31 , struct V_238 * V_239 )
{
struct V_1 * V_2 = (struct V_1 * ) V_31 -> V_175 ;
F_102 ( V_2 , V_239 ) ;
}
void F_103 ( struct V_85 * V_31 , struct V_98 * V_99 )
{
struct V_1 * V_2 = (struct V_1 * ) V_31 -> V_175 ;
struct V_67 * V_107 = & V_2 -> V_68 ;
struct V_66 * V_70 ;
struct V_87 * V_135 ;
enum V_125 V_126 ;
V_70 = F_19 ( V_107 , true ) ;
if ( ! V_70 )
return;
V_135 = & V_70 -> V_96 ;
memset ( V_135 , 0 , sizeof( * V_135 ) ) ;
V_135 -> V_118 = V_139 ;
V_135 -> V_140 = 1 ;
V_135 -> V_141 . V_142 . V_143 . V_99 = V_99 ;
V_135 -> V_141 . V_142 . V_143 . V_144 = ( V_145 ) V_70 ;
V_135 -> V_141 . V_142 . V_143 . V_146 = true ;
V_126 = F_52 ( V_2 , V_70 ) ;
if ( V_126 )
F_28 ( L_20 ) ;
}
void F_104 ( struct V_85 * V_31 , struct V_98 * V_99 )
{
struct V_248 V_96 ;
struct V_1 * V_2 = (struct V_1 * ) V_31 -> V_175 ;
F_65 ( V_31 , V_249 , L_21 , V_220 ) ;
memset ( & V_96 , 0 , sizeof( V_96 ) ) ;
V_96 . V_250 = V_251 ;
V_96 . V_252 = true ;
V_96 . V_253 = 0x3 ;
( void ) F_105 ( V_2 , V_99 , & V_96 , false ) ;
}
enum V_125 F_106 ( struct V_254 * * V_153 )
{
struct V_255 * V_256 ;
struct V_254 * V_257 ;
V_256 = F_107 ( L_22 , 0 , 0 ) ;
if ( F_108 ( V_256 ) )
return V_258 ;
V_257 = F_25 ( sizeof( * V_257 ) + F_109 ( V_256 ) ,
V_170 ) ;
if ( ! V_257 ) {
F_110 ( V_256 ) ;
return V_258 ;
}
V_257 -> V_256 = V_256 ;
* V_153 = V_257 ;
return 0 ;
}
void F_111 ( struct V_254 * V_153 )
{
if ( V_153 ) {
F_110 ( V_153 -> V_256 ) ;
F_32 ( V_153 ) ;
}
}
enum V_125 F_112 ( struct V_85 * V_31 ,
struct V_160 * V_161 )
{
enum V_125 V_126 ;
struct V_1 * V_2 = (struct V_1 * ) V_31 -> V_175 ;
V_126 = F_113 ( V_2 , V_161 , V_259 ,
V_260 ) ;
return V_126 ;
}
enum V_125 F_114 ( struct V_254 * V_153 ,
void * V_54 ,
T_1 V_261 ,
T_1 V_20 )
{
T_1 V_262 = 0 ;
int V_263 ;
enum V_125 V_264 = 0 ;
F_115 ( V_153 ) ;
V_263 = F_116 ( V_153 , V_54 , V_261 ) ;
if ( ! V_263 )
F_117 ( V_153 , ( T_2 * ) & V_262 ) ;
if ( V_262 != V_20 ) {
F_28 ( L_23 ) ;
V_264 = V_258 ;
}
return V_264 ;
}
struct V_98 * F_118 ( struct V_85 * V_31 ,
struct V_265 * V_154 )
{
struct V_1 * V_2 = (struct V_1 * ) V_31 -> V_175 ;
struct V_101 * V_102 ;
struct V_266 * V_267 ;
T_1 V_268 [ 4 ] , V_269 [ 4 ] ;
T_6 V_270 , V_271 ;
struct V_272 * V_273 ;
struct V_274 * V_275 = (struct V_274 * ) V_154 -> V_275 ;
struct V_276 * V_277 = (struct V_276 * ) V_154 -> V_277 ;
if ( V_275 -> V_278 == 4 ) {
memset ( V_268 , 0 , sizeof( V_268 ) ) ;
V_268 [ 0 ] = F_13 ( V_275 -> V_279 ) ;
memset ( V_269 , 0 , sizeof( V_269 ) ) ;
V_269 [ 0 ] = F_13 ( V_275 -> V_280 ) ;
} else {
V_273 = (struct V_272 * ) V_154 -> V_275 ;
F_17 ( V_268 , V_273 -> V_279 . V_55 . V_56 ) ;
F_17 ( V_269 , V_273 -> V_280 . V_55 . V_56 ) ;
}
V_270 = F_119 ( V_277 -> V_281 ) ;
V_271 = F_119 ( V_277 -> V_282 ) ;
V_267 = F_120 ( & V_2 -> V_283 , V_271 , V_269 , V_270 ,
V_268 , false ) ;
if ( ! V_267 )
return NULL ;
V_102 = V_267 -> V_102 ;
return & V_102 -> V_138 ;
}
void F_121 ( struct V_265 * V_154 , T_6 V_261 , T_1 V_284 )
{
struct V_276 * V_277 ;
struct V_274 * V_275 ;
T_6 V_285 ;
T_6 V_286 ;
T_2 * V_54 = ( T_2 * ) V_154 -> V_161 . V_167 ;
V_285 = ( V_154 -> V_4 ) ? 20 : 40 ;
V_275 = (struct V_274 * ) ( V_54 + V_154 -> V_287 ) ;
V_277 = (struct V_276 * ) ( V_54 + V_154 -> V_287 + V_285 ) ;
V_286 = V_261 + V_154 -> V_288 + V_285 ;
V_275 -> V_289 = F_122 ( V_286 ) ;
V_277 -> V_290 = F_123 ( V_284 ) ;
}
enum V_125 F_124 ( struct V_291 * V_96 ,
struct V_265 * V_154 )
{
struct V_274 * V_275 ;
struct V_272 * V_273 ;
struct V_276 * V_277 ;
T_6 V_285 ;
T_6 V_292 ;
T_2 * V_161 = ( T_2 * ) V_154 -> V_161 . V_167 ;
struct V_293 * V_294 = (struct V_293 * ) V_154 -> V_161 . V_167 ;
if ( V_294 -> V_295 == F_122 ( 0x8100 ) ) {
V_96 -> V_296 = true ;
V_154 -> V_297 = F_119 ( ( (struct V_298 * ) V_294 ) -> V_299 ) & V_300 ;
}
V_154 -> V_287 = ( V_96 -> V_296 ) ? 18 : 14 ;
V_285 = ( V_96 -> V_301 ) ? 40 : 20 ;
V_154 -> V_4 = ( V_96 -> V_301 ) ? false : true ;
V_154 -> V_275 = V_161 + V_154 -> V_287 ;
V_275 = (struct V_274 * ) V_154 -> V_275 ;
V_154 -> V_277 = V_154 -> V_275 + V_285 ;
V_277 = (struct V_276 * ) V_154 -> V_277 ;
if ( V_154 -> V_4 ) {
V_292 = F_119 ( V_275 -> V_289 ) ;
} else {
V_273 = (struct V_272 * ) V_154 -> V_275 ;
V_292 = F_119 ( V_273 -> V_302 ) + V_285 ;
}
V_154 -> V_303 = V_292 + V_154 -> V_287 ;
if ( V_96 -> V_302 < V_154 -> V_303 ) {
F_28 ( L_24 ,
V_96 -> V_302 , V_154 -> V_303 ) ;
return V_304 ;
}
V_154 -> V_288 = ( V_277 -> V_305 ) << 2 ;
V_154 -> V_306 = V_292 - V_285 - V_154 -> V_288 ;
V_154 -> V_307 = ( V_154 -> V_306 ) ? V_154 -> V_277 + V_154 -> V_288 : NULL ;
V_154 -> V_308 = V_154 -> V_287 + V_285 + V_154 -> V_288 ;
V_154 -> V_284 = F_13 ( V_277 -> V_290 ) ;
return 0 ;
}
static void F_125 ( unsigned long V_309 )
{
struct V_310 * V_311 = (struct V_310 * ) V_309 ;
struct V_85 * V_312 = V_311 -> V_31 ;
struct V_313 * V_314 = V_311 -> V_315 ;
struct V_313 * V_316 = NULL ;
T_6 V_207 ;
unsigned long V_71 ;
F_126 ( V_314 , & V_314 -> V_317 ) ;
for ( V_207 = 0 ; V_207 < V_318 ; V_207 ++ ) {
F_20 ( & V_314 -> V_191 , V_71 ) ;
if ( V_312 -> V_319 [ V_207 ] ) {
if ( V_312 -> V_319 [ V_207 ] -> V_320 ) {
V_316 = & V_312 -> V_319 [ V_207 ] -> V_315 ;
F_126 ( V_316 , & V_316 -> V_317 ) ;
}
}
F_24 ( & V_314 -> V_191 , V_71 ) ;
}
F_127 ( & V_314 -> V_321 ,
V_199 + F_128 ( V_322 ) ) ;
}
void F_129 ( struct V_310 * V_309 )
{
struct V_313 * V_323 = V_309 -> V_315 ;
F_85 ( & V_323 -> V_321 , F_125 ,
( unsigned long ) V_309 ) ;
F_127 ( & V_323 -> V_321 ,
V_199 + F_128 ( V_322 ) ) ;
}
void F_130 ( struct V_310 * V_309 )
{
struct V_313 * V_323 = V_309 -> V_315 ;
F_131 ( & V_323 -> V_321 ) ;
}
