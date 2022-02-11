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
struct V_1 * V_2 = F_31 ( V_67 , struct V_1 , V_67 ) ;
unsigned long V_70 ;
if ( V_69 -> V_76 ) {
F_32 ( V_69 ) ;
} else {
V_69 -> V_80 = false ;
V_69 -> V_81 = NULL ;
V_69 -> V_79 = false ;
F_20 ( & V_67 -> V_71 , V_70 ) ;
F_33 ( & V_69 -> V_74 , & V_67 -> V_72 ) ;
F_24 ( & V_67 -> V_71 , V_70 ) ;
}
F_34 ( & V_2 -> V_82 ) ;
}
void F_35 ( struct V_66 * V_67 ,
struct V_65 * V_69 )
{
if ( F_36 ( & V_69 -> V_78 ) )
F_30 ( V_67 , V_69 ) ;
}
static void F_37 ( struct V_66 * V_67 ,
struct V_65 * V_69 )
{
struct V_1 * V_2 = F_31 ( V_67 , struct V_1 , V_67 ) ;
if ( V_69 -> V_79 ) {
V_69 -> V_83 . error = true ;
V_69 -> V_80 = true ;
F_34 ( & V_69 -> V_77 ) ;
}
F_35 ( V_67 , V_69 ) ;
F_38 ( V_2 -> V_82 ,
! F_39 ( & V_69 -> V_78 ) ,
1000 ) ;
}
void F_40 ( struct V_1 * V_2 )
{
struct V_84 * V_31 = & V_2 -> V_85 ;
struct V_66 * V_67 = & V_2 -> V_67 ;
struct V_65 * V_69 = NULL ;
struct V_86 * V_87 = NULL ;
T_1 V_88 , V_89 , V_90 ;
V_89 = F_41 ( V_67 -> V_91 . V_92 ) ;
V_90 = F_42 ( V_67 -> V_91 . V_92 ) ;
for ( V_88 = 0 ; V_88 < V_89 ; V_88 ++ ) {
V_69 = (struct V_65 * ) ( unsigned long ) V_67 -> V_93 [ V_90 ] ;
if ( V_69 )
F_37 ( V_67 , V_69 ) ;
V_90 = ( V_90 + 1 ) % F_43 ( V_67 -> V_91 . V_92 ) ;
}
while ( ! F_21 ( & V_31 -> V_94 ) ) {
V_87 = (struct V_86 * ) F_44 ( & V_31 -> V_94 ) ;
V_69 = F_31 ( V_87 , struct V_65 , V_95 ) ;
if ( V_69 )
F_37 ( V_67 , V_69 ) ;
}
}
static void F_45 ( struct V_65 * V_69 , T_1 V_96 )
{
struct V_97 * V_98 = (struct V_97 * ) V_69 -> V_99 ;
struct V_100 * V_101 = (struct V_100 * ) V_98 -> V_102 ;
struct V_1 * V_2 ;
T_1 V_103 = V_101 -> V_104 . V_103 ;
V_2 = V_101 -> V_2 ;
F_46 ( V_101 -> V_105 , V_2 ) ;
F_47 ( V_2 , V_101 , V_103 ) ;
F_48 ( V_2 ) ;
}
static int F_49 ( struct V_1 * V_2 ,
struct V_65 * V_69 )
{
struct V_86 * V_95 = & V_69 -> V_95 ;
struct V_66 * V_106 = & V_2 -> V_67 ;
bool V_107 = false ;
int V_108 = 0 ;
int V_109 = 0 ;
V_109 = F_38 ( V_69 -> V_77 ,
V_69 -> V_80 ,
V_110 ) ;
if ( ! V_109 ) {
F_28 ( L_2 ,
V_95 -> V_111 , V_109 ) ;
V_108 = - V_112 ;
if ( ! V_2 -> V_113 ) {
V_2 -> V_113 = true ;
F_50 ( V_2 ) ;
}
goto V_114;
}
V_107 = V_69 -> V_83 . error ;
if ( V_107 ) {
F_28 ( L_3 ,
V_95 -> V_111 , V_69 -> V_83 . V_115 ,
V_69 -> V_83 . V_116 ) ;
V_108 = - V_117 ;
goto V_114;
}
V_114:
F_35 ( V_106 , V_69 ) ;
return V_108 ;
}
enum V_118 F_51 ( struct V_1 * V_2 ,
struct V_65
* V_69 )
{
struct V_84 * V_31 = & V_2 -> V_85 ;
enum V_118 V_119 ;
struct V_86 * V_95 = & V_69 -> V_95 ;
int V_108 = 0 ;
if ( V_2 -> V_113 ) {
F_30 ( & V_2 -> V_67 , V_69 ) ;
return V_120 ;
}
V_119 = F_52 ( V_31 , V_95 ) ;
if ( V_119 ) {
F_28 ( L_4 , V_95 -> V_111 ) ;
F_30 ( & V_2 -> V_67 , V_69 ) ;
return V_119 ;
}
if ( V_69 -> V_79 )
V_108 = F_49 ( V_2 , V_69 ) ;
if ( V_108 )
V_119 = V_120 ;
return V_119 ;
}
void F_53 ( struct V_1 * V_2 )
{
F_54 ( & V_2 -> V_121 ) ;
}
void F_48 ( struct V_1 * V_2 )
{
if ( ! F_55 ( & V_2 -> V_121 ) )
return;
F_34 ( & V_2 -> V_82 ) ;
}
void F_56 ( struct V_122 * V_105 )
{
F_57 ( & V_105 -> V_123 ) ;
}
void F_46 ( struct V_122 * V_105 , struct V_1 * V_2 )
{
if ( ! F_36 ( & V_105 -> V_123 ) )
return;
F_5 ( V_2 , V_2 -> V_124 , V_105 -> V_125 . V_126 ) ;
F_32 ( V_105 ) ;
}
void F_58 ( struct V_127 * V_104 )
{
struct V_100 * V_101 = (struct V_100 * ) V_104 ;
F_57 ( & V_101 -> V_78 ) ;
}
void F_59 ( struct V_127 * V_104 )
{
struct V_100 * V_101 ;
enum V_118 V_119 ;
struct V_65 * V_69 ;
struct V_86 * V_128 ;
struct V_1 * V_2 ;
T_1 V_103 ;
unsigned long V_70 ;
V_101 = F_60 ( V_104 ) ;
V_2 = V_101 -> V_2 ;
F_20 ( & V_2 -> V_129 , V_70 ) ;
if ( ! F_36 ( & V_101 -> V_78 ) ) {
F_24 ( & V_2 -> V_129 , V_70 ) ;
return;
}
V_103 = V_101 -> V_104 . V_103 ;
V_2 -> V_130 [ V_103 ] = NULL ;
F_24 ( & V_2 -> V_129 , V_70 ) ;
V_69 = F_19 ( & V_2 -> V_67 , false ) ;
if ( ! V_69 )
return;
V_69 -> V_81 = F_45 ;
V_69 -> V_99 = ( void * ) & V_101 -> V_131 ;
V_128 = & V_69 -> V_95 ;
V_128 -> V_111 = V_132 ;
V_128 -> V_133 = 1 ;
V_128 -> V_134 . V_135 . V_136 . V_98 = & V_101 -> V_131 ;
V_128 -> V_134 . V_135 . V_136 . V_137 = ( V_138 ) V_69 ;
V_128 -> V_134 . V_135 . V_136 . V_139 = true ;
V_119 = F_51 ( V_2 , V_69 ) ;
if ( ! V_119 )
return;
F_46 ( V_101 -> V_105 , V_2 ) ;
F_47 ( V_2 , V_101 , V_103 ) ;
F_48 ( V_2 ) ;
}
struct V_127 * F_61 ( struct V_140 * V_38 , int V_141 )
{
struct V_1 * V_2 = F_62 ( V_38 ) ;
if ( ( V_141 < V_142 ) || ( V_141 >= V_2 -> V_143 ) )
return NULL ;
return & V_2 -> V_130 [ V_141 ] -> V_104 ;
}
void F_63 ( struct V_84 * V_31 ,
enum V_144 V_145 ,
char * V_146 ,
T_4 * V_147 ,
T_1 V_148 )
{
T_1 V_88 ;
if ( ! ( V_31 -> V_149 & V_145 ) )
return;
F_64 ( V_31 , V_145 , L_5 , V_146 ) ;
F_64 ( V_31 , V_145 , L_6 , V_147 ,
( unsigned long long ) F_65 ( V_147 ) ) ;
for ( V_88 = 0 ; V_88 < V_148 ; V_88 += 8 )
F_64 ( V_31 , V_145 , L_7 , V_88 , V_147 [ V_88 / 8 ] ) ;
}
T_2 T_5 * F_66 ( void * V_150 )
{
struct V_84 * V_31 = (struct V_84 * ) V_150 ;
return V_31 -> V_18 -> V_21 ;
}
void * F_44 ( struct V_151 * V_74 )
{
struct V_151 * V_152 ;
if ( F_21 ( V_74 ) )
return NULL ;
V_152 = ( void * ) V_74 -> V_73 ;
F_67 ( V_152 ) ;
return ( void * ) V_152 ;
}
enum V_118 F_68 ( struct V_17 * V_18 ,
struct V_153 * V_154 ,
T_4 V_148 ,
T_1 V_155 )
{
struct V_156 * V_157 = (struct V_156 * ) V_18 -> V_158 ;
if ( ! V_154 )
return V_159 ;
V_154 -> V_148 = F_69 ( V_148 , V_155 ) ;
V_154 -> V_160 = F_70 ( & V_157 -> V_31 , V_154 -> V_148 ,
( V_161 * ) & V_154 -> V_162 , V_163 ) ;
if ( ! V_154 -> V_160 )
return V_164 ;
return 0 ;
}
void F_71 ( struct V_17 * V_18 , struct V_153 * V_154 )
{
struct V_156 * V_157 = (struct V_156 * ) V_18 -> V_158 ;
if ( ! V_154 || ! V_154 -> V_160 )
return;
F_72 ( & V_157 -> V_31 , V_154 -> V_148 ,
V_154 -> V_160 , ( V_161 ) V_154 -> V_162 ) ;
V_154 -> V_160 = NULL ;
}
enum V_118 F_73 ( struct V_17 * V_18 ,
struct V_165 * V_154 ,
T_1 V_148 )
{
if ( ! V_154 )
return V_159 ;
V_154 -> V_148 = V_148 ;
V_154 -> V_160 = F_25 ( V_148 , V_163 ) ;
if ( V_154 -> V_160 )
return 0 ;
else
return V_164 ;
}
enum V_118 F_74 ( struct V_17 * V_18 ,
struct V_165 * V_154 )
{
if ( ! V_154 )
return V_159 ;
F_32 ( V_154 -> V_160 ) ;
return 0 ;
}
enum V_118 F_75 ( struct V_84 * V_31 ,
struct V_166 * V_167 )
{
enum V_118 V_119 ;
struct V_65 * V_69 ;
struct V_86 * V_128 ;
struct V_1 * V_2 = (struct V_1 * ) V_31 -> V_168 ;
V_69 = F_19 ( & V_2 -> V_67 , true ) ;
if ( ! V_69 )
return V_164 ;
V_128 = & V_69 -> V_95 ;
memcpy ( & V_128 -> V_134 . V_135 . V_169 . V_95 , V_167 ,
sizeof( V_128 -> V_134 . V_135 . V_169 . V_95 ) ) ;
V_128 -> V_111 = V_170 ;
V_128 -> V_133 = 1 ;
V_128 -> V_134 . V_135 . V_169 . V_31 = V_31 ;
V_128 -> V_134 . V_135 . V_169 . V_137 = ( V_138 ) V_69 ;
V_119 = F_51 ( V_2 , V_69 ) ;
if ( V_119 )
F_28 ( L_8 ) ;
return V_119 ;
}
void F_76 ( struct V_84 * V_31 , struct V_97 * V_98 , bool V_171 )
{
struct V_1 * V_2 = (struct V_1 * ) V_31 -> V_168 ;
struct V_65 * V_69 ;
struct V_172 * V_67 = V_31 -> V_67 ;
struct V_86 * V_128 ;
enum V_118 V_119 ;
V_69 = F_19 ( & V_2 -> V_67 , false ) ;
if ( ! V_69 )
return;
V_128 = & V_69 -> V_95 ;
V_128 -> V_111 = ( V_171 ) ? V_173 : V_174 ;
V_128 -> V_134 . V_135 . V_175 . V_67 = V_67 ;
V_128 -> V_134 . V_135 . V_175 . V_98 = V_98 ;
V_128 -> V_134 . V_135 . V_175 . V_137 = ( V_138 ) V_69 ;
V_119 = F_51 ( V_2 , V_69 ) ;
if ( V_119 )
F_28 ( L_9 ) ;
}
void F_77 ( struct V_97 * V_98 , T_2 V_176 , T_2 V_177 , T_2 V_178 )
{
struct V_100 * V_101 ;
V_101 = (struct V_100 * ) V_98 -> V_102 ;
F_78 ( V_101 , V_176 , 0 , V_177 , V_178 ) ;
}
void F_79 ( struct V_97 * V_98 , int V_179 )
{
struct V_100 * V_101 ;
T_1 V_180 = V_181 ;
T_2 V_182 = 0 ;
bool V_183 ;
unsigned long V_70 ;
V_101 = (struct V_100 * ) V_98 -> V_102 ;
F_20 ( & V_101 -> V_184 , V_70 ) ;
if ( V_101 -> V_185 ) {
V_101 -> V_185 = 0 ;
V_182 = 1 ;
}
V_183 = ! ( V_98 -> V_186 & V_187 ) ;
V_98 -> V_186 |= V_187 ;
F_24 ( & V_101 -> V_184 , V_70 ) ;
if ( V_183 ) {
if ( ! V_179 )
F_80 ( V_98 ) ;
else
V_180 = V_188 ;
F_78 ( V_101 , V_180 , V_182 , 0 , 0 ) ;
F_81 ( V_101 ) ;
}
}
static void F_82 ( unsigned long V_189 )
{
struct V_100 * V_101 = (struct V_100 * ) V_189 ;
struct V_97 * V_98 = (struct V_97 * ) & V_101 -> V_131 ;
F_79 ( V_98 , 1 ) ;
F_59 ( & V_101 -> V_104 ) ;
}
void F_83 ( struct V_97 * V_98 )
{
struct V_100 * V_101 ;
V_101 = (struct V_100 * ) V_98 -> V_102 ;
F_58 ( & V_101 -> V_104 ) ;
F_84 ( & V_101 -> V_190 , F_82 ,
( unsigned long ) V_101 ) ;
V_101 -> V_190 . V_191 = V_192 + V_193 ;
F_85 ( & V_101 -> V_190 ) ;
}
void F_80 ( struct V_97 * V_98 )
{
struct V_100 * V_101 ;
V_101 = (struct V_100 * ) V_98 -> V_102 ;
if ( F_86 ( & V_101 -> V_190 ) )
F_59 ( & V_101 -> V_104 ) ;
}
static void F_87 ( struct V_194 * V_195 )
{
struct V_196 * V_197 =
& ( (struct V_198 * ) V_195 ) -> V_197 ;
if ( V_197 -> V_199 )
V_197 -> V_81 ( V_197 -> V_199 ) ;
}
void F_88 ( struct V_84 * V_31 ,
struct V_196 * V_197 ,
T_1 V_200 )
{
struct V_198 * V_195 ;
struct V_1 * V_2 = (struct V_1 * ) V_31 -> V_168 ;
V_195 = & V_2 -> V_201 [ V_200 ] ;
memcpy ( & V_195 -> V_197 , V_197 , sizeof( * V_197 ) ) ;
F_89 ( & V_195 -> V_195 , F_87 ) ;
F_90 ( V_2 -> V_202 , & V_195 -> V_195 ) ;
}
static void F_91 ( struct V_194 * V_195 )
{
struct V_65 * V_69 =
( (struct V_198 * ) V_195 ) -> V_69 ;
struct V_203 V_204 ;
struct V_205 * V_206 =
& V_69 -> V_95 . V_134 . V_135 . V_207 . V_95 ;
struct V_1 * V_2 =
(struct V_1 * ) V_69 -> V_95 . V_134 . V_135 . V_207 . V_31 -> V_168 ;
V_204 . V_67 = NULL ;
V_204 . V_115 = V_69 -> V_83 . V_115 ;
V_204 . V_116 = V_69 -> V_83 . V_116 ;
V_204 . V_208 = V_69 -> V_83 . V_208 ;
V_204 . V_209 = V_69 -> V_83 . V_209 ;
V_204 . V_137 = 0 ;
V_204 . error = V_69 -> V_83 . error ;
V_206 -> V_81 ( V_69 -> V_95 . V_134 . V_135 . V_207 . V_31 ,
V_206 -> V_210 , & V_204 ) ;
F_35 ( & V_2 -> V_67 , V_69 ) ;
}
static void F_92 ( struct V_65 * V_69 ,
T_1 V_211 )
{
struct V_198 * V_195 ;
struct V_205 * V_206 =
& V_69 -> V_95 . V_134 . V_135 . V_207 . V_95 ;
struct V_1 * V_2 =
(struct V_1 * ) V_69 -> V_95 . V_134 . V_135 . V_207 . V_31 ->
V_168 ;
if ( V_206 && V_206 -> V_81 ) {
F_64 ( & V_2 -> V_85 , V_212 , L_10 , V_213 ) ;
F_57 ( & V_69 -> V_78 ) ;
V_195 = & V_2 -> V_201 [ V_206 -> V_200 ] ;
V_195 -> V_69 = V_69 ;
F_89 ( & V_195 -> V_195 , F_91 ) ;
F_90 ( V_2 -> V_202 , & V_195 -> V_195 ) ;
F_64 ( & V_2 -> V_85 , V_212 , L_11 , V_213 ) ;
} else {
F_64 ( & V_2 -> V_85 , V_212 , L_12 , V_213 ) ;
}
}
enum V_118 F_93 ( struct V_84 * V_31 ,
struct V_205 * V_206 )
{
enum V_118 V_119 ;
struct V_65 * V_69 ;
struct V_86 * V_128 ;
struct V_1 * V_2 = (struct V_1 * ) V_31 -> V_168 ;
F_64 ( & V_2 -> V_85 , V_212 , L_5 , V_213 ) ;
V_69 = F_19 ( & V_2 -> V_67 , false ) ;
if ( ! V_69 )
return V_164 ;
V_128 = & V_69 -> V_95 ;
V_69 -> V_81 = F_92 ;
V_69 -> V_99 = V_206 ;
memcpy ( & V_128 -> V_134 . V_135 . V_207 . V_95 , V_206 ,
sizeof( * V_206 ) ) ;
V_128 -> V_134 . V_135 . V_207 . V_31 = V_31 ;
V_128 -> V_111 = V_214 ;
V_128 -> V_133 = 1 ;
V_128 -> V_134 . V_135 . V_207 . V_137 = ( V_138 ) V_69 ;
V_119 = F_51 ( V_2 , V_69 ) ;
if ( V_119 )
F_28 ( L_13 ) ;
return V_119 ;
}
enum V_118 F_94 ( struct V_84 * V_31 ,
struct V_153 * V_215 ,
T_2 V_216 )
{
enum V_118 V_119 ;
struct V_65 * V_69 ;
struct V_86 * V_128 ;
struct V_1 * V_2 = (struct V_1 * ) V_31 -> V_168 ;
V_69 = F_19 ( & V_2 -> V_67 , true ) ;
if ( ! V_69 )
return V_164 ;
V_128 = & V_69 -> V_95 ;
V_69 -> V_99 = NULL ;
V_128 -> V_134 . V_135 . V_217 . V_67 = V_31 -> V_67 ;
V_128 -> V_134 . V_135 . V_217 . V_218 = V_215 -> V_162 ;
V_128 -> V_134 . V_135 . V_217 . V_219 = V_215 -> V_160 ;
V_128 -> V_134 . V_135 . V_217 . V_216 = V_216 ;
V_128 -> V_111 = V_220 ;
V_128 -> V_133 = 1 ;
V_128 -> V_134 . V_135 . V_217 . V_137 = ( V_138 ) V_69 ;
V_119 = F_51 ( V_2 , V_69 ) ;
if ( V_119 )
F_28 ( L_14 ) ;
return V_119 ;
}
enum V_118 F_95 ( struct V_84 * V_31 ,
struct V_153 * V_215 ,
T_2 V_216 )
{
enum V_118 V_119 ;
struct V_65 * V_69 ;
struct V_86 * V_128 ;
struct V_1 * V_2 = (struct V_1 * ) V_31 -> V_168 ;
V_69 = F_19 ( & V_2 -> V_67 , true ) ;
if ( ! V_69 )
return V_164 ;
V_128 = & V_69 -> V_95 ;
V_69 -> V_99 = NULL ;
V_128 -> V_134 . V_135 . V_221 . V_67 = V_31 -> V_67 ;
V_128 -> V_134 . V_135 . V_221 . V_218 = V_215 -> V_162 ;
V_128 -> V_134 . V_135 . V_221 . V_219 = V_215 -> V_160 ;
V_128 -> V_134 . V_135 . V_221 . V_216 = V_216 ;
V_128 -> V_111 = V_222 ;
V_128 -> V_133 = 1 ;
V_128 -> V_134 . V_135 . V_221 . V_137 = ( V_138 ) V_69 ;
V_119 = F_51 ( V_2 , V_69 ) ;
if ( V_119 )
F_28 ( L_15 ) ;
return V_119 ;
}
enum V_118 F_96 ( struct V_84 * V_31 )
{
struct V_1 * V_2 = V_31 -> V_168 ;
int V_109 ;
F_64 ( V_31 , V_223 , L_16 ,
V_213 , __LINE__ , V_31 , V_2 ) ;
F_29 ( & V_2 -> V_224 , 2 ) ;
V_109 = F_38 ( V_2 -> V_225 ,
( F_39 ( & V_2 -> V_224 ) == 1 ) ,
V_226 ) ;
F_97 ( & V_2 -> V_224 ) ;
if ( ! V_109 ) {
F_28 ( L_17 , V_109 ) ;
F_29 ( & V_2 -> V_224 , 0 ) ;
V_31 -> V_227 = false ;
return V_228 ;
}
F_34 ( & V_31 -> V_229 ) ;
return 0 ;
}
enum V_118 F_98 ( struct V_84 * V_31 ,
struct V_230 * V_231 )
{
struct V_1 * V_2 = (struct V_1 * ) V_31 -> V_168 ;
struct V_66 * V_106 = & V_2 -> V_67 ;
struct V_65 * V_69 ;
struct V_86 * V_128 ;
enum V_118 V_119 ;
V_69 = F_19 ( V_106 , true ) ;
if ( ! V_69 )
return V_164 ;
V_128 = & V_69 -> V_95 ;
V_128 -> V_111 = V_232 ;
V_128 -> V_133 = 1 ;
V_128 -> V_134 . V_135 . V_233 . V_231 = V_231 ;
V_128 -> V_134 . V_135 . V_233 . V_137 = ( V_138 ) V_69 ;
V_119 = F_51 ( V_2 , V_69 ) ;
if ( V_119 )
F_28 ( L_18 ) ;
return V_119 ;
}
enum V_118 F_99 ( struct V_84 * V_31 ,
struct V_97 * V_98 )
{
struct V_1 * V_2 = (struct V_1 * ) V_31 -> V_168 ;
struct V_66 * V_106 = & V_2 -> V_67 ;
struct V_65 * V_69 ;
struct V_86 * V_128 ;
struct V_234 * V_235 ;
enum V_118 V_119 ;
V_69 = F_19 ( V_106 , true ) ;
if ( ! V_69 )
return V_164 ;
V_128 = & V_69 -> V_95 ;
V_235 = & V_69 -> V_95 . V_134 . V_135 . V_236 . V_95 ;
memset ( V_235 , 0 , sizeof( * V_235 ) ) ;
V_235 -> V_237 = true ;
V_235 -> V_180 = V_238 ;
V_128 -> V_111 = V_239 ;
V_128 -> V_133 = 1 ;
V_128 -> V_134 . V_135 . V_236 . V_98 = V_98 ;
V_128 -> V_134 . V_135 . V_236 . V_137 = ( V_138 ) V_69 ;
V_119 = F_51 ( V_2 , V_69 ) ;
if ( V_119 )
F_28 ( L_19 ) ;
return V_119 ;
}
void F_100 ( struct V_84 * V_31 , struct V_230 * V_231 )
{
struct V_1 * V_2 = (struct V_1 * ) V_31 -> V_168 ;
F_101 ( V_2 , V_231 ) ;
}
void F_102 ( struct V_84 * V_31 , struct V_97 * V_98 )
{
struct V_1 * V_2 = (struct V_1 * ) V_31 -> V_168 ;
struct V_66 * V_106 = & V_2 -> V_67 ;
struct V_65 * V_69 ;
struct V_86 * V_128 ;
enum V_118 V_119 ;
V_69 = F_19 ( V_106 , true ) ;
if ( ! V_69 )
return;
V_128 = & V_69 -> V_95 ;
memset ( V_128 , 0 , sizeof( * V_128 ) ) ;
V_128 -> V_111 = V_132 ;
V_128 -> V_133 = 1 ;
V_128 -> V_134 . V_135 . V_136 . V_98 = V_98 ;
V_128 -> V_134 . V_135 . V_136 . V_137 = ( V_138 ) V_69 ;
V_128 -> V_134 . V_135 . V_136 . V_139 = true ;
V_119 = F_51 ( V_2 , V_69 ) ;
if ( V_119 )
F_28 ( L_20 ) ;
}
void F_103 ( struct V_84 * V_31 , struct V_97 * V_98 )
{
struct V_240 V_95 ;
struct V_1 * V_2 = (struct V_1 * ) V_31 -> V_168 ;
F_64 ( V_31 , V_241 , L_21 , V_213 ) ;
memset ( & V_95 , 0 , sizeof( V_95 ) ) ;
V_95 . V_242 = V_243 ;
V_95 . V_244 = true ;
V_95 . V_245 = 0x3 ;
( void ) F_104 ( V_2 , V_98 , & V_95 , false ) ;
}
enum V_118 F_105 ( struct V_246 * * V_146 )
{
struct V_247 * V_248 ;
struct V_246 * V_249 ;
V_248 = F_106 ( L_22 , 0 , 0 ) ;
if ( F_107 ( V_248 ) )
return V_250 ;
V_249 = F_25 ( sizeof( * V_249 ) + F_108 ( V_248 ) ,
V_163 ) ;
if ( ! V_249 ) {
F_109 ( V_248 ) ;
return V_250 ;
}
V_249 -> V_248 = V_248 ;
* V_146 = V_249 ;
return 0 ;
}
void F_110 ( struct V_246 * V_146 )
{
if ( V_146 ) {
F_109 ( V_146 -> V_248 ) ;
F_32 ( V_146 ) ;
}
}
enum V_118 F_111 ( struct V_84 * V_31 ,
struct V_153 * V_154 )
{
enum V_118 V_119 ;
struct V_1 * V_2 = (struct V_1 * ) V_31 -> V_168 ;
V_119 = F_112 ( V_2 , V_154 , V_251 ,
V_252 ) ;
return V_119 ;
}
enum V_118 F_113 ( struct V_246 * V_146 ,
void * V_53 ,
T_1 V_253 ,
T_1 V_20 )
{
T_1 V_254 = 0 ;
int V_255 ;
enum V_118 V_256 = 0 ;
F_114 ( V_146 ) ;
V_255 = F_115 ( V_146 , V_53 , V_253 ) ;
if ( ! V_255 )
F_116 ( V_146 , ( T_2 * ) & V_254 ) ;
if ( V_254 != V_20 ) {
F_28 ( L_23 ) ;
V_256 = V_250 ;
}
return V_256 ;
}
struct V_97 * F_117 ( struct V_84 * V_31 ,
struct V_257 * V_147 )
{
struct V_1 * V_2 = (struct V_1 * ) V_31 -> V_168 ;
struct V_100 * V_101 ;
struct V_258 * V_259 ;
T_1 V_260 [ 4 ] , V_261 [ 4 ] ;
T_6 V_262 , V_263 ;
struct V_264 * V_265 ;
struct V_266 * V_267 = (struct V_266 * ) V_147 -> V_267 ;
struct V_268 * V_269 = (struct V_268 * ) V_147 -> V_269 ;
if ( V_267 -> V_270 == 4 ) {
memset ( V_260 , 0 , sizeof( V_260 ) ) ;
V_260 [ 0 ] = F_13 ( V_267 -> V_271 ) ;
memset ( V_261 , 0 , sizeof( V_261 ) ) ;
V_261 [ 0 ] = F_13 ( V_267 -> V_272 ) ;
} else {
V_265 = (struct V_264 * ) V_147 -> V_267 ;
F_17 ( V_260 , V_265 -> V_271 . V_54 . V_55 ) ;
F_17 ( V_261 , V_265 -> V_272 . V_54 . V_55 ) ;
}
V_262 = F_118 ( V_269 -> V_273 ) ;
V_263 = F_118 ( V_269 -> V_274 ) ;
V_259 = F_119 ( & V_2 -> V_275 , V_263 , V_261 , V_262 ,
V_260 , false ) ;
if ( ! V_259 )
return NULL ;
V_101 = V_259 -> V_101 ;
return & V_101 -> V_131 ;
}
void F_120 ( struct V_257 * V_147 , T_6 V_253 , T_1 V_276 )
{
struct V_268 * V_269 ;
struct V_266 * V_267 ;
T_6 V_277 ;
T_6 V_278 ;
T_2 * V_53 = ( T_2 * ) V_147 -> V_154 . V_160 ;
V_277 = ( V_147 -> V_4 ) ? 20 : 40 ;
V_267 = (struct V_266 * ) ( V_53 + V_147 -> V_279 ) ;
V_269 = (struct V_268 * ) ( V_53 + V_147 -> V_279 + V_277 ) ;
V_278 = V_253 + V_147 -> V_280 + V_277 ;
V_267 -> V_281 = F_121 ( V_278 ) ;
V_269 -> V_282 = F_122 ( V_276 ) ;
}
enum V_118 F_123 ( struct V_283 * V_95 ,
struct V_257 * V_147 )
{
struct V_266 * V_267 ;
struct V_264 * V_265 ;
struct V_268 * V_269 ;
T_6 V_277 ;
T_6 V_284 ;
T_2 * V_154 = ( T_2 * ) V_147 -> V_154 . V_160 ;
struct V_285 * V_286 = (struct V_285 * ) V_147 -> V_154 . V_160 ;
if ( V_286 -> V_287 == F_121 ( 0x8100 ) ) {
V_95 -> V_288 = true ;
V_147 -> V_289 = F_118 ( ( (struct V_290 * ) V_286 ) -> V_291 ) & V_292 ;
}
V_147 -> V_279 = ( V_95 -> V_288 ) ? 18 : 14 ;
V_277 = ( V_95 -> V_293 ) ? 40 : 20 ;
V_147 -> V_4 = ( V_95 -> V_293 ) ? false : true ;
V_147 -> V_267 = V_154 + V_147 -> V_279 ;
V_267 = (struct V_266 * ) V_147 -> V_267 ;
V_147 -> V_269 = V_147 -> V_267 + V_277 ;
V_269 = (struct V_268 * ) V_147 -> V_269 ;
if ( V_147 -> V_4 ) {
V_284 = F_118 ( V_267 -> V_281 ) ;
} else {
V_265 = (struct V_264 * ) V_147 -> V_267 ;
V_284 = F_118 ( V_265 -> V_294 ) + V_277 ;
}
V_147 -> V_295 = V_284 + V_147 -> V_279 ;
if ( V_95 -> V_294 < V_147 -> V_295 ) {
F_28 ( L_24 ,
V_95 -> V_294 , V_147 -> V_295 ) ;
return V_296 ;
}
V_147 -> V_280 = ( V_269 -> V_297 ) << 2 ;
V_147 -> V_298 = V_284 - V_277 - V_147 -> V_280 ;
V_147 -> V_299 = ( V_147 -> V_298 ) ? V_147 -> V_269 + V_147 -> V_280 : NULL ;
V_147 -> V_300 = V_147 -> V_279 + V_277 + V_147 -> V_280 ;
V_147 -> V_276 = F_13 ( V_269 -> V_282 ) ;
return 0 ;
}
static void F_124 ( unsigned long V_301 )
{
struct V_302 * V_303 = (struct V_302 * ) V_301 ;
struct V_84 * V_304 = V_303 -> V_31 ;
struct V_305 * V_306 = V_303 -> V_307 ;
struct V_305 * V_308 = NULL ;
T_6 V_200 ;
unsigned long V_70 ;
F_125 ( V_306 , & V_306 -> V_309 ) ;
for ( V_200 = 0 ; V_200 < V_310 ; V_200 ++ ) {
F_20 ( & V_306 -> V_184 , V_70 ) ;
if ( V_304 -> V_311 [ V_200 ] ) {
if ( V_304 -> V_311 [ V_200 ] -> V_312 ) {
V_308 = & V_304 -> V_311 [ V_200 ] -> V_307 ;
F_125 ( V_308 , & V_308 -> V_309 ) ;
}
}
F_24 ( & V_306 -> V_184 , V_70 ) ;
}
F_126 ( & V_306 -> V_313 ,
V_192 + F_127 ( V_314 ) ) ;
}
void F_128 ( struct V_302 * V_301 )
{
struct V_305 * V_315 = V_301 -> V_307 ;
F_84 ( & V_315 -> V_313 , F_124 ,
( unsigned long ) V_301 ) ;
F_126 ( & V_315 -> V_313 ,
V_192 + F_127 ( V_314 ) ) ;
}
void F_129 ( struct V_302 * V_301 )
{
struct V_305 * V_315 = V_301 -> V_307 ;
F_130 ( & V_315 -> V_313 ) ;
}
