const char * F_1 ( T_1 V_1 )
{
T_2 V_2 = V_1 ;
int V_3 ;
F_2 ( V_2 != V_1 ) ;
for ( V_3 = 0 ; V_4 [ V_3 ] . V_5 ; V_3 ++ )
if ( V_2 == V_4 [ V_3 ] . V_5 )
break;
return V_4 [ V_3 ] . V_6 ;
}
void F_3 ( int V_1 , struct V_7 * V_8 )
{
if ( V_1 & V_9 ) {
V_8 -> V_10 = 1001 ;
V_8 -> V_11 = 30000 ;
} else {
V_8 -> V_10 = 1 ;
V_8 -> V_11 = 25 ;
}
}
int F_4 ( struct V_12 * V_13 ,
int V_1 , const char * V_14 )
{
V_13 -> V_1 = V_1 ;
F_3 ( V_1 , & V_13 -> V_8 ) ;
V_13 -> V_15 = ( V_1 & V_9 ) ? 525 : 625 ;
F_5 ( V_13 -> V_14 , V_14 , sizeof( V_13 -> V_14 ) ) ;
return 0 ;
}
void F_6 ( unsigned int V_16 )
{
char * V_17 , * type ;
switch ( F_7 ( V_16 ) ) {
case 'd' :
type = L_1 ;
break;
case 'V' :
if ( F_8 ( V_16 ) >= V_18 ) {
type = L_2 ;
break;
}
F_9 ( L_3 , V_19 [ F_8 ( V_16 ) ] ) ;
return;
default:
type = L_4 ;
}
switch ( F_10 ( V_16 ) ) {
case V_20 : V_17 = L_5 ; break;
case V_21 : V_17 = L_6 ; break;
case V_22 : V_17 = L_7 ; break;
case V_21 | V_22 : V_17 = L_8 ; break;
default: V_17 = L_9 ; break;
}
F_9 ( L_10 ,
type , F_7 ( V_16 ) , V_17 , F_8 ( V_16 ) , V_16 ) ;
}
static void F_11 ( unsigned int V_16 , struct V_23 * V_24 ,
struct V_25 * V_26 )
{
struct V_27 * V_28 = & V_26 -> V_29 ;
struct V_30 * V_31 ;
int V_3 ;
F_12 ( V_16 , L_11
L_12 ,
V_26 -> V_32 . V_33 / 3600 ,
( int ) ( V_26 -> V_32 . V_33 / 60 ) % 60 ,
( int ) ( V_26 -> V_32 . V_33 % 60 ) ,
( long ) V_26 -> V_32 . V_34 ,
V_26 -> V_35 ,
F_13 ( V_26 -> type , V_36 ) ,
V_26 -> V_37 , V_26 -> V_38 , V_26 -> V_39 ,
F_13 ( V_26 -> V_40 , V_41 ) ) ;
if ( F_14 ( V_26 -> type ) && V_26 -> V_42 . V_43 ) {
for ( V_3 = 0 ; V_3 < V_26 -> V_44 ; ++ V_3 ) {
V_31 = & V_26 -> V_42 . V_43 [ V_3 ] ;
F_15 ( L_13
L_14 ,
V_3 , V_31 -> V_45 , V_31 -> V_46 ,
V_31 -> V_42 . V_47 , V_31 -> V_44 ) ;
}
} else {
F_15 ( L_15 ,
V_26 -> V_45 , V_26 -> V_42 . V_47 , V_26 -> V_44 ) ;
}
F_15 ( L_16
L_17 ,
V_28 -> V_48 , V_28 -> V_49 , V_28 -> V_50 ,
V_28 -> type , V_28 -> V_37 , V_28 -> V_51 , * ( V_52 * ) V_28 -> V_53 ) ;
}
static inline void F_16 ( struct V_23 * V_24 , char * V_54 ,
struct V_55 * V_56 )
{
F_15 ( L_18 , V_54 , V_56 -> V_57 , V_56 -> V_58 ,
V_56 -> V_59 , V_56 -> V_60 ) ;
}
static inline void F_17 ( struct V_23 * V_24 ,
struct V_61 * V_62 )
{
F_15 ( L_19
L_20 ,
V_62 -> V_59 , V_62 -> V_60 ,
( V_62 -> V_63 & 0xff ) ,
( V_62 -> V_63 >> 8 ) & 0xff ,
( V_62 -> V_63 >> 16 ) & 0xff ,
( V_62 -> V_63 >> 24 ) & 0xff ,
F_13 ( V_62 -> V_38 , V_64 ) ,
V_62 -> V_65 , V_62 -> V_66 , V_62 -> V_67 ) ;
}
static inline void F_18 ( struct V_23 * V_24 ,
struct V_68 * V_62 )
{
int V_3 ;
F_15 ( L_19
L_21 ,
V_62 -> V_59 , V_62 -> V_60 ,
( V_62 -> V_63 & 0xff ) ,
( V_62 -> V_63 >> 8 ) & 0xff ,
( V_62 -> V_63 >> 16 ) & 0xff ,
( V_62 -> V_63 >> 24 ) & 0xff ,
F_13 ( V_62 -> V_38 , V_64 ) ,
V_62 -> V_67 , V_62 -> V_69 ) ;
for ( V_3 = 0 ; V_3 < V_62 -> V_69 ; ++ V_3 )
F_15 ( L_22 , V_3 ,
V_62 -> V_70 [ V_3 ] . V_65 ,
V_62 -> V_70 [ V_3 ] . V_66 ) ;
}
static inline void F_19 ( unsigned int V_16 ,
struct V_23 * V_24 , struct V_71 * V_72 , int V_73 )
{
V_52 V_3 ;
if ( ! ( V_24 -> V_74 & V_75 ) )
return;
F_12 ( V_16 , L_23 ) ;
F_9 ( V_76 L_24 , V_72 -> V_77 ) ;
for ( V_3 = 0 ; V_3 < V_72 -> V_78 ; V_3 ++ ) {
if ( V_73 && ! V_72 -> V_79 [ V_3 ] . V_80 )
F_9 ( V_76 L_25 ,
V_72 -> V_79 [ V_3 ] . V_1 , V_72 -> V_79 [ V_3 ] . V_81 ) ;
else
F_9 ( V_76 L_26 ,
V_72 -> V_79 [ V_3 ] . V_1 , V_72 -> V_79 [ V_3 ] . V_80 ) ;
}
F_9 ( V_76 L_27 ) ;
}
static inline int F_20 ( struct V_71 * V_72 , int V_82 )
{
V_52 V_3 ;
V_72 -> V_83 [ 0 ] = V_72 -> V_83 [ 1 ] = 0 ;
for ( V_3 = 0 ; V_3 < V_72 -> V_78 ; V_3 ++ )
V_72 -> V_79 [ V_3 ] . V_84 [ 0 ] = 0 ;
if ( ! V_82 && V_72 -> V_77 == V_85 )
return 0 ;
for ( V_3 = 0 ; V_3 < V_72 -> V_78 ; V_3 ++ ) {
if ( F_21 ( V_72 -> V_79 [ V_3 ] . V_1 ) != V_72 -> V_77 ) {
V_72 -> V_86 = V_3 ;
return 0 ;
}
}
return 1 ;
}
static int F_22 ( const struct V_87 * V_88 , enum V_89 type )
{
if ( V_88 == NULL )
return - V_90 ;
switch ( type ) {
case V_91 :
if ( V_88 -> V_92 ||
V_88 -> V_93 )
return 0 ;
break;
case V_94 :
if ( V_88 -> V_93 )
return 0 ;
break;
case V_95 :
if ( V_88 -> V_96 )
return 0 ;
break;
case V_97 :
if ( V_88 -> V_98 ||
V_88 -> V_99 )
return 0 ;
break;
case V_100 :
if ( V_88 -> V_99 )
return 0 ;
break;
case V_101 :
if ( V_88 -> V_102 )
return 0 ;
break;
case V_103 :
if ( V_88 -> V_104 )
return 0 ;
break;
case V_105 :
if ( V_88 -> V_106 )
return 0 ;
break;
case V_107 :
if ( V_88 -> V_108 )
return 0 ;
break;
case V_109 :
if ( V_88 -> V_110 )
return 0 ;
break;
case V_111 :
if ( V_88 -> V_112 )
return 0 ;
break;
}
return - V_90 ;
}
static long F_23 ( struct V_113 * V_113 ,
unsigned int V_16 , void * V_114 )
{
struct V_23 * V_24 = F_24 ( V_113 ) ;
const struct V_87 * V_88 = V_24 -> V_115 ;
void * V_116 = V_113 -> V_117 ;
struct V_118 * V_119 = NULL ;
int V_120 = 0 ;
long V_121 = 0 ;
long V_122 = - V_123 ;
if ( V_88 == NULL ) {
F_9 ( V_124 L_28 ,
V_24 -> V_14 ) ;
return V_122 ;
}
if ( ( V_24 -> V_74 & V_125 ) &&
! ( V_24 -> V_74 & V_75 ) ) {
F_25 ( V_24 -> V_14 , V_16 ) ;
F_9 ( V_76 L_27 ) ;
}
if ( F_26 ( V_126 , & V_24 -> V_37 ) ) {
V_119 = V_113 -> V_117 ;
V_120 = F_26 ( V_127 , & V_24 -> V_37 ) ;
}
if ( V_120 )
V_121 = F_27 ( V_24 -> V_128 , V_119 -> V_128 ) ;
switch ( V_16 ) {
case V_129 :
{
struct V_130 * V_131 = (struct V_130 * ) V_114 ;
if ( ! V_88 -> V_132 )
break;
V_131 -> V_133 = V_134 ;
V_122 = V_88 -> V_132 ( V_113 , V_116 , V_131 ) ;
if ( ! V_122 )
F_12 ( V_16 , L_29
L_30
L_31 ,
V_131 -> V_135 , V_131 -> V_136 , V_131 -> V_137 ,
V_131 -> V_133 ,
V_131 -> V_138 ) ;
break;
}
case V_139 :
{
enum V_140 * V_26 = V_114 ;
if ( V_88 -> V_141 ) {
V_122 = V_88 -> V_141 ( V_113 , V_116 , V_26 ) ;
} else if ( V_120 ) {
* V_26 = F_28 ( & V_24 -> V_142 -> V_128 ) ;
V_122 = 0 ;
}
if ( ! V_122 )
F_12 ( V_16 , L_32 , * V_26 ) ;
break;
}
case V_143 :
{
enum V_140 * V_26 = V_114 ;
if ( ! V_88 -> V_144 && ! V_120 )
break;
F_12 ( V_16 , L_33 , * V_26 ) ;
if ( V_88 -> V_144 )
V_122 = V_88 -> V_144 ( V_113 , V_116 , * V_26 ) ;
else
V_122 = V_121 ? V_121 :
F_29 ( & V_24 -> V_142 -> V_128 ,
& V_119 -> V_128 , * V_26 ) ;
break;
}
case V_145 :
{
struct V_146 * V_147 = V_114 ;
switch ( V_147 -> type ) {
case V_91 :
if ( F_30 ( V_88 -> V_148 ) )
V_122 = V_88 -> V_148 ( V_113 , V_116 , V_147 ) ;
break;
case V_94 :
if ( F_30 ( V_88 -> V_149 ) )
V_122 = V_88 -> V_149 ( V_113 ,
V_116 , V_147 ) ;
break;
case V_95 :
if ( F_30 ( V_88 -> V_150 ) )
V_122 = V_88 -> V_150 ( V_113 ,
V_116 , V_147 ) ;
break;
case V_97 :
if ( F_30 ( V_88 -> V_151 ) )
V_122 = V_88 -> V_151 ( V_113 , V_116 , V_147 ) ;
break;
case V_100 :
if ( F_30 ( V_88 -> V_152 ) )
V_122 = V_88 -> V_152 ( V_113 ,
V_116 , V_147 ) ;
break;
case V_111 :
if ( F_30 ( V_88 -> V_153 ) )
V_122 = V_88 -> V_153 ( V_113 ,
V_116 , V_147 ) ;
break;
default:
break;
}
if ( F_30 ( ! V_122 ) )
F_12 ( V_16 , L_34
L_35 ,
V_147 -> V_35 , V_147 -> type , V_147 -> V_37 ,
( V_147 -> V_63 & 0xff ) ,
( V_147 -> V_63 >> 8 ) & 0xff ,
( V_147 -> V_63 >> 16 ) & 0xff ,
( V_147 -> V_63 >> 24 ) & 0xff ,
V_147 -> V_154 ) ;
else if ( V_122 == - V_123 &&
( V_88 -> V_148 ||
V_88 -> V_151 ||
V_88 -> V_149 ||
V_88 -> V_152 ||
V_88 -> V_150 ||
V_88 -> V_153 ) )
V_122 = - V_90 ;
break;
}
case V_155 :
{
struct V_156 * V_147 = (struct V_156 * ) V_114 ;
F_12 ( V_16 , L_36 , F_13 ( V_147 -> type , V_36 ) ) ;
switch ( V_147 -> type ) {
case V_91 :
if ( V_88 -> V_92 )
V_122 = V_88 -> V_92 ( V_113 , V_116 , V_147 ) ;
if ( ! V_122 )
F_17 ( V_24 , & V_147 -> V_62 . V_157 ) ;
break;
case V_94 :
if ( V_88 -> V_93 )
V_122 = V_88 -> V_93 ( V_113 ,
V_116 , V_147 ) ;
if ( ! V_122 )
F_18 ( V_24 , & V_147 -> V_62 . V_158 ) ;
break;
case V_95 :
if ( F_30 ( V_88 -> V_96 ) )
V_122 = V_88 -> V_96 ( V_113 ,
V_116 , V_147 ) ;
break;
case V_97 :
if ( V_88 -> V_98 )
V_122 = V_88 -> V_98 ( V_113 , V_116 , V_147 ) ;
if ( ! V_122 )
F_17 ( V_24 , & V_147 -> V_62 . V_157 ) ;
break;
case V_100 :
if ( V_88 -> V_99 )
V_122 = V_88 -> V_99 ( V_113 ,
V_116 , V_147 ) ;
if ( ! V_122 )
F_18 ( V_24 , & V_147 -> V_62 . V_158 ) ;
break;
case V_101 :
if ( F_30 ( V_88 -> V_102 ) )
V_122 = V_88 -> V_102 ( V_113 ,
V_116 , V_147 ) ;
break;
case V_103 :
if ( F_30 ( V_88 -> V_104 ) )
V_122 = V_88 -> V_104 ( V_113 , V_116 , V_147 ) ;
break;
case V_105 :
if ( F_30 ( V_88 -> V_106 ) )
V_122 = V_88 -> V_106 ( V_113 , V_116 , V_147 ) ;
break;
case V_107 :
if ( F_30 ( V_88 -> V_108 ) )
V_122 = V_88 -> V_108 ( V_113 ,
V_116 , V_147 ) ;
break;
case V_109 :
if ( F_30 ( V_88 -> V_110 ) )
V_122 = V_88 -> V_110 ( V_113 ,
V_116 , V_147 ) ;
break;
case V_111 :
if ( F_30 ( V_88 -> V_112 ) )
V_122 = V_88 -> V_112 ( V_113 ,
V_116 , V_147 ) ;
break;
}
if ( F_31 ( V_122 == - V_123 && F_32 ( V_159 ) ) )
V_122 = - V_90 ;
break;
}
case V_160 :
{
struct V_156 * V_147 = (struct V_156 * ) V_114 ;
if ( ! F_32 ( V_54 ) )
break;
if ( V_121 ) {
V_122 = V_121 ;
break;
}
V_122 = - V_90 ;
F_12 ( V_16 , L_36 , F_13 ( V_147 -> type , V_36 ) ) ;
switch ( V_147 -> type ) {
case V_91 :
F_33 ( V_147 , V_62 . V_157 ) ;
F_17 ( V_24 , & V_147 -> V_62 . V_157 ) ;
if ( V_88 -> V_161 )
V_122 = V_88 -> V_161 ( V_113 , V_116 , V_147 ) ;
break;
case V_94 :
F_33 ( V_147 , V_62 . V_158 ) ;
F_18 ( V_24 , & V_147 -> V_62 . V_158 ) ;
if ( V_88 -> V_162 )
V_122 = V_88 -> V_162 ( V_113 ,
V_116 , V_147 ) ;
break;
case V_95 :
F_33 ( V_147 , V_62 . V_163 ) ;
if ( V_88 -> V_164 )
V_122 = V_88 -> V_164 ( V_113 ,
V_116 , V_147 ) ;
break;
case V_97 :
F_33 ( V_147 , V_62 . V_157 ) ;
F_17 ( V_24 , & V_147 -> V_62 . V_157 ) ;
if ( V_88 -> V_165 )
V_122 = V_88 -> V_165 ( V_113 , V_116 , V_147 ) ;
break;
case V_100 :
F_33 ( V_147 , V_62 . V_158 ) ;
F_18 ( V_24 , & V_147 -> V_62 . V_158 ) ;
if ( V_88 -> V_166 )
V_122 = V_88 -> V_166 ( V_113 ,
V_116 , V_147 ) ;
break;
case V_101 :
F_33 ( V_147 , V_62 . V_163 ) ;
if ( V_88 -> V_167 )
V_122 = V_88 -> V_167 ( V_113 ,
V_116 , V_147 ) ;
break;
case V_103 :
F_33 ( V_147 , V_62 . V_168 ) ;
if ( F_30 ( V_88 -> V_169 ) )
V_122 = V_88 -> V_169 ( V_113 , V_116 , V_147 ) ;
break;
case V_105 :
F_33 ( V_147 , V_62 . V_168 ) ;
if ( F_30 ( V_88 -> V_170 ) )
V_122 = V_88 -> V_170 ( V_113 , V_116 , V_147 ) ;
break;
case V_107 :
F_33 ( V_147 , V_62 . V_171 ) ;
if ( F_30 ( V_88 -> V_172 ) )
V_122 = V_88 -> V_172 ( V_113 ,
V_116 , V_147 ) ;
break;
case V_109 :
F_33 ( V_147 , V_62 . V_171 ) ;
if ( F_30 ( V_88 -> V_173 ) )
V_122 = V_88 -> V_173 ( V_113 ,
V_116 , V_147 ) ;
break;
case V_111 :
if ( F_30 ( V_88 -> V_174 ) )
V_122 = V_88 -> V_174 ( V_113 ,
V_116 , V_147 ) ;
break;
}
break;
}
case V_175 :
{
struct V_156 * V_147 = (struct V_156 * ) V_114 ;
F_12 ( V_16 , L_36 , F_13 ( V_147 -> type ,
V_36 ) ) ;
switch ( V_147 -> type ) {
case V_91 :
F_33 ( V_147 , V_62 . V_157 ) ;
if ( V_88 -> V_176 )
V_122 = V_88 -> V_176 ( V_113 , V_116 , V_147 ) ;
if ( ! V_122 )
F_17 ( V_24 , & V_147 -> V_62 . V_157 ) ;
break;
case V_94 :
F_33 ( V_147 , V_62 . V_158 ) ;
if ( V_88 -> V_177 )
V_122 = V_88 -> V_177 ( V_113 ,
V_116 , V_147 ) ;
if ( ! V_122 )
F_18 ( V_24 , & V_147 -> V_62 . V_158 ) ;
break;
case V_95 :
F_33 ( V_147 , V_62 . V_163 ) ;
if ( F_30 ( V_88 -> V_178 ) )
V_122 = V_88 -> V_178 ( V_113 ,
V_116 , V_147 ) ;
break;
case V_97 :
F_33 ( V_147 , V_62 . V_157 ) ;
if ( V_88 -> V_179 )
V_122 = V_88 -> V_179 ( V_113 , V_116 , V_147 ) ;
if ( ! V_122 )
F_17 ( V_24 , & V_147 -> V_62 . V_157 ) ;
break;
case V_100 :
F_33 ( V_147 , V_62 . V_158 ) ;
if ( V_88 -> V_180 )
V_122 = V_88 -> V_180 ( V_113 ,
V_116 , V_147 ) ;
if ( ! V_122 )
F_18 ( V_24 , & V_147 -> V_62 . V_158 ) ;
break;
case V_101 :
F_33 ( V_147 , V_62 . V_163 ) ;
if ( F_30 ( V_88 -> V_181 ) )
V_122 = V_88 -> V_181 ( V_113 ,
V_116 , V_147 ) ;
break;
case V_103 :
F_33 ( V_147 , V_62 . V_168 ) ;
if ( F_30 ( V_88 -> V_182 ) )
V_122 = V_88 -> V_182 ( V_113 , V_116 , V_147 ) ;
break;
case V_105 :
F_33 ( V_147 , V_62 . V_168 ) ;
if ( F_30 ( V_88 -> V_183 ) )
V_122 = V_88 -> V_183 ( V_113 , V_116 , V_147 ) ;
break;
case V_107 :
F_33 ( V_147 , V_62 . V_171 ) ;
if ( F_30 ( V_88 -> V_184 ) )
V_122 = V_88 -> V_184 ( V_113 ,
V_116 , V_147 ) ;
break;
case V_109 :
F_33 ( V_147 , V_62 . V_171 ) ;
if ( F_30 ( V_88 -> V_185 ) )
V_122 = V_88 -> V_185 ( V_113 ,
V_116 , V_147 ) ;
break;
case V_111 :
if ( F_30 ( V_88 -> V_186 ) )
V_122 = V_88 -> V_186 ( V_113 ,
V_116 , V_147 ) ;
break;
}
if ( F_31 ( V_122 == - V_123 && F_32 ( V_187 ) ) )
V_122 = - V_90 ;
break;
}
case V_188 :
{
struct V_189 * V_26 = V_114 ;
if ( ! V_88 -> V_190 )
break;
if ( V_121 ) {
V_122 = V_121 ;
break;
}
V_122 = F_22 ( V_88 , V_26 -> type ) ;
if ( V_122 )
break;
if ( V_26 -> type < V_111 )
F_33 ( V_26 , V_40 ) ;
V_122 = V_88 -> V_190 ( V_113 , V_116 , V_26 ) ;
F_12 ( V_16 , L_37 ,
V_26 -> V_78 ,
F_13 ( V_26 -> type , V_36 ) ,
F_13 ( V_26 -> V_40 , V_41 ) ) ;
break;
}
case V_191 :
{
struct V_25 * V_26 = V_114 ;
if ( ! V_88 -> V_192 )
break;
V_122 = F_22 ( V_88 , V_26 -> type ) ;
if ( V_122 )
break;
V_122 = V_88 -> V_192 ( V_113 , V_116 , V_26 ) ;
if ( ! V_122 )
F_11 ( V_16 , V_24 , V_26 ) ;
break;
}
case V_193 :
{
struct V_25 * V_26 = V_114 ;
if ( ! V_88 -> V_194 )
break;
V_122 = F_22 ( V_88 , V_26 -> type ) ;
if ( V_122 )
break;
V_122 = V_88 -> V_194 ( V_113 , V_116 , V_26 ) ;
if ( ! V_122 )
F_11 ( V_16 , V_24 , V_26 ) ;
break;
}
case V_195 :
{
struct V_25 * V_26 = V_114 ;
if ( ! V_88 -> V_196 )
break;
V_122 = F_22 ( V_88 , V_26 -> type ) ;
if ( V_122 )
break;
V_122 = V_88 -> V_196 ( V_113 , V_116 , V_26 ) ;
if ( ! V_122 )
F_11 ( V_16 , V_24 , V_26 ) ;
break;
}
case V_197 :
{
int * V_3 = V_114 ;
if ( ! V_88 -> V_198 )
break;
if ( V_121 ) {
V_122 = V_121 ;
break;
}
F_12 ( V_16 , L_38 , * V_3 ) ;
V_122 = V_88 -> V_198 ( V_113 , V_116 , * V_3 ) ;
break;
}
case V_199 :
{
struct V_200 * V_26 = V_114 ;
if ( ! V_88 -> V_201 )
break;
V_122 = V_88 -> V_201 ( V_113 , V_116 , V_114 ) ;
if ( ! V_122 ) {
F_12 ( V_16 , L_39 ,
V_26 -> V_202 , V_26 -> V_37 ,
( unsigned long ) V_26 -> V_203 ) ;
F_17 ( V_24 , & V_26 -> V_62 ) ;
}
break;
}
case V_204 :
{
struct V_200 * V_26 = V_114 ;
if ( ! V_88 -> V_205 )
break;
if ( V_121 ) {
V_122 = V_121 ;
break;
}
F_12 ( V_16 , L_39 ,
V_26 -> V_202 , V_26 -> V_37 , ( unsigned long ) V_26 -> V_203 ) ;
F_17 ( V_24 , & V_26 -> V_62 ) ;
V_122 = V_88 -> V_205 ( V_113 , V_116 , V_114 ) ;
break;
}
case V_206 :
{
enum V_89 V_3 = * ( int * ) V_114 ;
if ( ! V_88 -> V_207 )
break;
if ( V_121 ) {
V_122 = V_121 ;
break;
}
F_12 ( V_16 , L_36 , F_13 ( V_3 , V_36 ) ) ;
V_122 = V_88 -> V_207 ( V_113 , V_116 , V_3 ) ;
break;
}
case V_208 :
{
enum V_89 V_3 = * ( int * ) V_114 ;
if ( ! V_88 -> V_209 )
break;
if ( V_121 ) {
V_122 = V_121 ;
break;
}
F_12 ( V_16 , L_36 , F_13 ( V_3 , V_36 ) ) ;
V_122 = V_88 -> V_209 ( V_113 , V_116 , V_3 ) ;
break;
}
case V_210 :
{
struct V_12 * V_26 = V_114 ;
T_1 V_1 = V_24 -> V_211 , V_212 = 0 ;
unsigned int V_35 = V_26 -> V_35 , V_3 , V_213 = 0 ;
const char * V_6 = L_23 ;
if ( V_1 == 0 )
break;
V_122 = - V_90 ;
for ( V_3 = 0 ; V_3 <= V_35 && V_1 ; V_3 ++ ) {
while ( ( V_1 & V_4 [ V_213 ] . V_5 ) != V_4 [ V_213 ] . V_5 )
V_213 ++ ;
V_212 = V_4 [ V_213 ] . V_5 ;
V_6 = V_4 [ V_213 ] . V_6 ;
V_213 ++ ;
if ( V_212 == 0 )
break;
if ( V_212 != V_214 &&
V_212 != V_215 &&
V_212 != V_216 )
V_1 &= ~ V_212 ;
}
if ( V_3 <= V_35 )
break;
F_4 ( V_26 , V_212 , V_6 ) ;
F_12 ( V_16 , L_40
L_41 , V_26 -> V_35 ,
( unsigned long long ) V_26 -> V_1 , V_26 -> V_14 ,
V_26 -> V_8 . V_10 ,
V_26 -> V_8 . V_11 ,
V_26 -> V_15 ) ;
V_122 = 0 ;
break;
}
case V_217 :
{
T_1 * V_1 = V_114 ;
if ( V_88 -> V_218 )
V_122 = V_88 -> V_218 ( V_113 , V_116 , V_1 ) ;
else if ( V_24 -> V_219 ) {
V_122 = 0 ;
* V_1 = V_24 -> V_219 ;
}
if ( F_30 ( ! V_122 ) )
F_12 ( V_16 , L_42 , ( long long unsigned ) * V_1 ) ;
break;
}
case V_220 :
{
T_1 * V_1 = V_114 , V_221 ;
F_12 ( V_16 , L_43 , ( long long unsigned ) * V_1 ) ;
if ( ! V_88 -> V_222 )
break;
if ( V_121 ) {
V_122 = V_121 ;
break;
}
V_122 = - V_90 ;
V_221 = ( * V_1 ) & V_24 -> V_211 ;
if ( V_24 -> V_211 && ! V_221 )
break;
V_122 = V_88 -> V_222 ( V_113 , V_116 , & V_221 ) ;
if ( V_122 >= 0 )
V_24 -> V_219 = V_221 ;
break;
}
case V_223 :
{
T_1 * V_26 = V_114 ;
if ( ! V_88 -> V_224 )
break;
* V_26 = V_24 -> V_211 ;
V_122 = V_88 -> V_224 ( V_113 , V_116 , V_114 ) ;
if ( ! V_122 )
F_12 ( V_16 , L_44 ,
( unsigned long long ) * V_26 ) ;
break;
}
case V_225 :
{
struct V_226 * V_26 = V_114 ;
if ( V_88 -> V_222 )
V_26 -> V_138 |= V_227 ;
if ( V_88 -> V_228 )
V_26 -> V_138 |= V_229 ;
if ( V_88 -> V_230 )
V_26 -> V_138 |= V_231 ;
if ( ! V_88 -> V_232 )
break;
V_122 = V_88 -> V_232 ( V_113 , V_116 , V_26 ) ;
if ( ! V_122 )
F_12 ( V_16 , L_45
L_46
L_47 ,
V_26 -> V_35 , V_26 -> V_14 , V_26 -> type , V_26 -> V_233 ,
V_26 -> V_234 ,
( unsigned long long ) V_26 -> V_5 ,
V_26 -> V_235 ) ;
break;
}
case V_236 :
{
unsigned int * V_3 = V_114 ;
if ( ! V_88 -> V_237 )
break;
V_122 = V_88 -> V_237 ( V_113 , V_116 , V_3 ) ;
if ( ! V_122 )
F_12 ( V_16 , L_38 , * V_3 ) ;
break;
}
case V_238 :
{
unsigned int * V_3 = V_114 ;
if ( ! V_88 -> V_239 )
break;
if ( V_121 ) {
V_122 = V_121 ;
break;
}
F_12 ( V_16 , L_38 , * V_3 ) ;
V_122 = V_88 -> V_239 ( V_113 , V_116 , * V_3 ) ;
break;
}
case V_240 :
{
struct V_241 * V_26 = V_114 ;
if ( ! V_88 -> V_242 )
break;
if ( V_88 -> V_222 )
V_26 -> V_138 |= V_243 ;
if ( V_88 -> V_228 )
V_26 -> V_138 |= V_244 ;
if ( V_88 -> V_230 )
V_26 -> V_138 |= V_245 ;
V_122 = V_88 -> V_242 ( V_113 , V_116 , V_26 ) ;
if ( ! V_122 )
F_12 ( V_16 , L_45
L_48
L_49 ,
V_26 -> V_35 , V_26 -> V_14 , V_26 -> type , V_26 -> V_233 ,
V_26 -> V_246 , ( unsigned long long ) V_26 -> V_5 ) ;
break;
}
case V_247 :
{
unsigned int * V_3 = V_114 ;
if ( ! V_88 -> V_248 )
break;
V_122 = V_88 -> V_248 ( V_113 , V_116 , V_3 ) ;
if ( ! V_122 )
F_12 ( V_16 , L_38 , * V_3 ) ;
break;
}
case V_249 :
{
unsigned int * V_3 = V_114 ;
if ( ! V_88 -> V_250 )
break;
if ( V_121 ) {
V_122 = V_121 ;
break;
}
F_12 ( V_16 , L_38 , * V_3 ) ;
V_122 = V_88 -> V_250 ( V_113 , V_116 , * V_3 ) ;
break;
}
case V_251 :
{
struct V_252 * V_26 = V_114 ;
if ( V_119 && V_119 -> V_253 )
V_122 = V_252 ( V_119 -> V_253 , V_26 ) ;
else if ( V_24 -> V_253 )
V_122 = V_252 ( V_24 -> V_253 , V_26 ) ;
else if ( V_88 -> V_254 )
V_122 = V_88 -> V_254 ( V_113 , V_116 , V_26 ) ;
else
break;
if ( ! V_122 )
F_12 ( V_16 , L_50
L_51 ,
V_26 -> V_1 , V_26 -> type , V_26 -> V_14 ,
V_26 -> V_255 , V_26 -> V_256 ,
V_26 -> V_257 , V_26 -> V_258 , V_26 -> V_37 ) ;
else
F_12 ( V_16 , L_52 , V_26 -> V_1 ) ;
break;
}
case V_259 :
{
struct V_260 * V_26 = V_114 ;
if ( V_119 && V_119 -> V_253 )
V_122 = F_34 ( V_119 -> V_253 , V_26 ) ;
else if ( V_24 -> V_253 )
V_122 = F_34 ( V_24 -> V_253 , V_26 ) ;
else if ( V_88 -> V_261 )
V_122 = V_88 -> V_261 ( V_113 , V_116 , V_26 ) ;
else if ( V_88 -> V_262 ) {
struct V_71 V_263 ;
struct V_264 V_265 ;
V_263 . V_77 = F_21 ( V_26 -> V_1 ) ;
V_263 . V_78 = 1 ;
V_263 . V_79 = & V_265 ;
V_265 . V_1 = V_26 -> V_1 ;
V_265 . V_81 = V_26 -> V_81 ;
if ( F_20 ( & V_263 , 1 ) ) {
V_122 = V_88 -> V_262 ( V_113 , V_116 , & V_263 ) ;
if ( V_122 == 0 )
V_26 -> V_81 = V_265 . V_81 ;
}
} else
break;
if ( ! V_122 )
F_12 ( V_16 , L_53 , V_26 -> V_1 , V_26 -> V_81 ) ;
else
F_12 ( V_16 , L_52 , V_26 -> V_1 ) ;
break;
}
case V_266 :
{
struct V_260 * V_26 = V_114 ;
struct V_71 V_263 ;
struct V_264 V_265 ;
if ( ! ( V_119 && V_119 -> V_253 ) && ! V_24 -> V_253 &&
! V_88 -> V_267 && ! V_88 -> V_268 )
break;
if ( V_121 ) {
V_122 = V_121 ;
break;
}
F_12 ( V_16 , L_53 , V_26 -> V_1 , V_26 -> V_81 ) ;
if ( V_119 && V_119 -> V_253 ) {
V_122 = F_35 ( V_119 , V_119 -> V_253 , V_26 ) ;
break;
}
if ( V_24 -> V_253 ) {
V_122 = F_35 ( NULL , V_24 -> V_253 , V_26 ) ;
break;
}
if ( V_88 -> V_267 ) {
V_122 = V_88 -> V_267 ( V_113 , V_116 , V_26 ) ;
break;
}
if ( ! V_88 -> V_268 )
break;
V_263 . V_77 = F_21 ( V_26 -> V_1 ) ;
V_263 . V_78 = 1 ;
V_263 . V_79 = & V_265 ;
V_265 . V_1 = V_26 -> V_1 ;
V_265 . V_81 = V_26 -> V_81 ;
if ( F_20 ( & V_263 , 1 ) )
V_122 = V_88 -> V_268 ( V_113 , V_116 , & V_263 ) ;
else
V_122 = - V_90 ;
break;
}
case V_269 :
{
struct V_71 * V_26 = V_114 ;
V_26 -> V_86 = V_26 -> V_78 ;
if ( V_119 && V_119 -> V_253 )
V_122 = F_36 ( V_119 -> V_253 , V_26 ) ;
else if ( V_24 -> V_253 )
V_122 = F_36 ( V_24 -> V_253 , V_26 ) ;
else if ( V_88 -> V_262 )
V_122 = F_20 ( V_26 , 0 ) ?
V_88 -> V_262 ( V_113 , V_116 , V_26 ) :
- V_90 ;
else
break;
F_19 ( V_16 , V_24 , V_26 , ! V_122 ) ;
break;
}
case V_270 :
{
struct V_71 * V_26 = V_114 ;
V_26 -> V_86 = V_26 -> V_78 ;
if ( ! ( V_119 && V_119 -> V_253 ) && ! V_24 -> V_253 &&
! V_88 -> V_268 )
break;
if ( V_121 ) {
V_122 = V_121 ;
break;
}
F_19 ( V_16 , V_24 , V_26 , 1 ) ;
if ( V_119 && V_119 -> V_253 )
V_122 = F_37 ( V_119 , V_119 -> V_253 , V_26 ) ;
else if ( V_24 -> V_253 )
V_122 = F_37 ( NULL , V_24 -> V_253 , V_26 ) ;
else if ( F_20 ( V_26 , 0 ) )
V_122 = V_88 -> V_268 ( V_113 , V_116 , V_26 ) ;
else
V_122 = - V_90 ;
break;
}
case V_271 :
{
struct V_71 * V_26 = V_114 ;
V_26 -> V_86 = V_26 -> V_78 ;
if ( ! ( V_119 && V_119 -> V_253 ) && ! V_24 -> V_253 &&
! V_88 -> V_272 )
break;
F_19 ( V_16 , V_24 , V_26 , 1 ) ;
if ( V_119 && V_119 -> V_253 )
V_122 = F_38 ( V_119 -> V_253 , V_26 ) ;
else if ( V_24 -> V_253 )
V_122 = F_38 ( V_24 -> V_253 , V_26 ) ;
else if ( F_20 ( V_26 , 0 ) )
V_122 = V_88 -> V_272 ( V_113 , V_116 , V_26 ) ;
else
V_122 = - V_90 ;
break;
}
case V_273 :
{
struct V_274 * V_26 = V_114 ;
if ( V_119 && V_119 -> V_253 )
V_122 = V_274 ( V_119 -> V_253 , V_26 ) ;
else if ( V_24 -> V_253 )
V_122 = V_274 ( V_24 -> V_253 , V_26 ) ;
else if ( V_88 -> V_275 )
V_122 = V_88 -> V_275 ( V_113 , V_116 , V_26 ) ;
else
break;
if ( ! V_122 )
F_12 ( V_16 , L_54 ,
V_26 -> V_1 , V_26 -> V_35 , V_26 -> V_14 ) ;
else
F_12 ( V_16 , L_55 ,
V_26 -> V_1 , V_26 -> V_35 ) ;
break;
}
case V_276 :
{
struct V_277 * V_26 = V_114 ;
if ( ! V_88 -> V_278 )
break;
V_122 = V_88 -> V_278 ( V_113 , V_116 , V_26 ) ;
if ( ! V_122 )
F_12 ( V_16 , L_56
L_57 , V_26 -> V_35 , V_26 -> V_14 ,
V_26 -> V_202 , V_26 -> V_279 ) ;
else
F_12 ( V_16 , L_58 , V_26 -> V_35 ) ;
break;
}
case V_280 :
{
struct V_277 * V_26 = V_114 ;
if ( ! V_88 -> V_281 )
break;
V_122 = V_88 -> V_281 ( V_113 , V_116 , V_26 ) ;
if ( ! V_122 )
F_12 ( V_16 , L_56
L_57 , V_26 -> V_35 ,
V_26 -> V_14 , V_26 -> V_202 , V_26 -> V_279 ) ;
else
F_12 ( V_16 , L_58 , V_26 -> V_35 ) ;
break;
}
case V_282 :
{
struct V_277 * V_26 = V_114 ;
if ( ! V_88 -> V_283 )
break;
if ( V_121 ) {
V_122 = V_121 ;
break;
}
F_12 ( V_16 , L_56
L_57 , V_26 -> V_35 , V_26 -> V_14 ,
V_26 -> V_202 , V_26 -> V_279 ) ;
V_122 = V_88 -> V_283 ( V_113 , V_116 , V_26 ) ;
break;
}
case V_284 :
{
struct V_285 * V_26 = V_114 ;
if ( ! V_88 -> V_286 )
break;
F_12 ( V_16 , L_59 , V_26 -> V_35 ) ;
V_122 = V_88 -> V_286 ( V_113 , V_116 , V_26 ) ;
if ( ! V_122 )
F_15 ( L_60
L_61 , V_26 -> V_35 , V_26 -> V_14 ,
V_26 -> V_202 , V_26 -> V_279 ) ;
break;
}
case V_287 :
{
struct V_285 * V_26 = V_114 ;
if ( ! V_88 -> V_288 )
break;
V_122 = V_88 -> V_288 ( V_113 , V_116 , V_26 ) ;
if ( ! V_122 )
F_15 ( L_60
L_61 , V_26 -> V_35 , V_26 -> V_14 ,
V_26 -> V_202 , V_26 -> V_279 ) ;
break;
}
case V_289 :
{
struct V_285 * V_26 = V_114 ;
if ( ! V_88 -> V_290 )
break;
if ( V_121 ) {
V_122 = V_121 ;
break;
}
F_12 ( V_16 , L_60
L_61 , V_26 -> V_35 , V_26 -> V_14 ,
V_26 -> V_202 , V_26 -> V_279 ) ;
V_122 = V_88 -> V_290 ( V_113 , V_116 , V_26 ) ;
break;
}
case V_291 :
{
struct V_292 * V_26 = V_114 ;
if ( ! V_88 -> V_293 )
break;
V_122 = V_88 -> V_293 ( V_113 , V_116 , V_26 ) ;
if ( ! V_122 )
F_12 ( V_16 , L_62
L_63
L_64 ,
V_26 -> V_35 , V_26 -> V_14 , V_26 -> V_202 ,
V_26 -> V_294 , V_26 -> V_295 ,
V_26 -> V_296 ) ;
break;
}
case V_297 :
{
struct V_292 * V_26 = V_114 ;
if ( ! V_88 -> V_298 )
break;
if ( V_121 ) {
V_122 = V_121 ;
break;
}
F_12 ( V_16 , L_60
L_65 ,
V_26 -> V_35 , V_26 -> V_14 , V_26 -> V_202 , V_26 -> V_294 ,
V_26 -> V_295 , V_26 -> V_296 ) ;
V_122 = V_88 -> V_298 ( V_113 , V_116 , V_26 ) ;
break;
}
case V_299 :
{
struct V_300 * V_26 = V_114 ;
if ( ! V_88 -> V_301 && ! V_88 -> V_302 )
break;
F_12 ( V_16 , L_36 , F_13 ( V_26 -> type , V_36 ) ) ;
if ( V_88 -> V_301 ) {
V_122 = V_88 -> V_301 ( V_113 , V_116 , V_26 ) ;
} else {
struct V_303 V_54 = {
. type = V_26 -> type ,
} ;
if ( F_39 ( V_26 -> type ) )
V_54 . V_304 = V_305 ;
else
V_54 . V_304 = V_306 ;
V_122 = V_88 -> V_302 ( V_113 , V_116 , & V_54 ) ;
if ( ! V_122 )
V_26 -> V_72 = V_54 . V_56 ;
}
if ( ! V_122 )
F_16 ( V_24 , L_23 , & V_26 -> V_72 ) ;
break;
}
case V_307 :
{
struct V_300 * V_26 = V_114 ;
if ( ! V_88 -> V_308 && ! V_88 -> V_309 )
break;
if ( V_121 ) {
V_122 = V_121 ;
break;
}
F_12 ( V_16 , L_36 , F_13 ( V_26 -> type , V_36 ) ) ;
F_16 ( V_24 , L_23 , & V_26 -> V_72 ) ;
if ( V_88 -> V_308 ) {
V_122 = V_88 -> V_308 ( V_113 , V_116 , V_26 ) ;
} else {
struct V_303 V_54 = {
. type = V_26 -> type ,
. V_56 = V_26 -> V_72 ,
} ;
if ( F_39 ( V_26 -> type ) )
V_54 . V_304 = V_305 ;
else
V_54 . V_304 = V_306 ;
V_122 = V_88 -> V_309 ( V_113 , V_116 , & V_54 ) ;
}
break;
}
case V_310 :
{
struct V_303 * V_26 = V_114 ;
if ( ! V_88 -> V_302 )
break;
F_12 ( V_16 , L_36 , F_13 ( V_26 -> type , V_36 ) ) ;
V_122 = V_88 -> V_302 ( V_113 , V_116 , V_26 ) ;
if ( ! V_122 )
F_16 ( V_24 , L_23 , & V_26 -> V_56 ) ;
break;
}
case V_311 :
{
struct V_303 * V_26 = V_114 ;
if ( ! V_88 -> V_309 )
break;
if ( V_121 ) {
V_122 = V_121 ;
break;
}
F_12 ( V_16 , L_36 , F_13 ( V_26 -> type , V_36 ) ) ;
F_16 ( V_24 , L_23 , & V_26 -> V_56 ) ;
V_122 = V_88 -> V_309 ( V_113 , V_116 , V_26 ) ;
break;
}
case V_312 :
{
struct V_313 * V_26 = V_114 ;
if ( ! V_88 -> V_314 && ! V_88 -> V_302 )
break;
F_12 ( V_16 , L_36 , F_13 ( V_26 -> type , V_36 ) ) ;
if ( V_88 -> V_314 ) {
V_122 = V_88 -> V_314 ( V_113 , V_116 , V_26 ) ;
} else {
struct V_303 V_54 = { . type = V_26 -> type } ;
if ( F_39 ( V_26 -> type ) )
V_54 . V_304 = V_315 ;
else
V_54 . V_304 = V_316 ;
V_122 = V_88 -> V_302 ( V_113 , V_116 , & V_54 ) ;
if ( V_122 )
break;
V_26 -> V_317 = V_54 . V_56 ;
if ( F_39 ( V_26 -> type ) )
V_54 . V_304 = V_318 ;
else
V_54 . V_304 = V_319 ;
V_122 = V_88 -> V_302 ( V_113 , V_116 , & V_54 ) ;
if ( V_122 )
break;
V_26 -> V_320 = V_54 . V_56 ;
V_26 -> V_321 . V_10 = 1 ;
V_26 -> V_321 . V_11 = 1 ;
}
if ( ! V_122 ) {
F_16 ( V_24 , L_66 , & V_26 -> V_317 ) ;
F_16 ( V_24 , L_67 , & V_26 -> V_320 ) ;
}
break;
}
case V_322 :
{
struct V_323 * V_26 = V_114 ;
if ( ! V_88 -> V_324 )
break;
V_122 = V_88 -> V_324 ( V_113 , V_116 , V_26 ) ;
if ( ! V_122 )
F_12 ( V_16 , L_68
L_69
L_70 ,
V_26 -> V_325 , V_26 -> V_326 , V_26 -> V_327 ,
V_26 -> V_328 , V_26 -> V_329 ) ;
break;
}
case V_330 :
{
struct V_323 * V_26 = V_114 ;
if ( ! V_88 -> V_324 )
break;
if ( V_121 ) {
V_122 = V_121 ;
break;
}
F_12 ( V_16 , L_71
L_72 ,
V_26 -> V_325 , V_26 -> V_326 , V_26 -> V_327 ,
V_26 -> V_328 , V_26 -> V_329 ) ;
V_122 = V_88 -> V_331 ( V_113 , V_116 , V_26 ) ;
break;
}
case V_332 :
{
struct V_333 * V_26 = V_114 ;
if ( ! V_88 -> V_334 )
break;
V_122 = V_88 -> V_334 ( V_113 , V_116 , V_26 ) ;
if ( ! V_122 )
F_12 ( V_16 , L_73 ,
V_26 -> V_335 , V_26 -> V_336 ) ;
break;
}
case V_337 :
{
struct V_338 * V_26 = V_114 ;
if ( ! V_88 -> V_339 )
break;
if ( V_121 ) {
V_122 = V_121 ;
break;
}
V_122 = V_88 -> V_339 ( V_113 , V_116 , V_26 ) ;
if ( ! V_122 )
F_12 ( V_16 , L_74 , V_26 -> V_16 , V_26 -> V_37 ) ;
break;
}
case V_340 :
{
struct V_338 * V_26 = V_114 ;
if ( ! V_88 -> V_341 )
break;
V_122 = V_88 -> V_341 ( V_113 , V_116 , V_26 ) ;
if ( ! V_122 )
F_12 ( V_16 , L_74 , V_26 -> V_16 , V_26 -> V_37 ) ;
break;
}
case V_342 :
{
struct V_343 * V_26 = V_114 ;
if ( ! V_88 -> V_344 && ! V_24 -> V_219 )
break;
if ( V_88 -> V_344 ) {
V_122 = F_22 ( V_88 , V_26 -> type ) ;
if ( V_122 )
break;
V_122 = V_88 -> V_344 ( V_113 , V_116 , V_26 ) ;
} else {
T_1 V_5 = V_24 -> V_219 ;
V_122 = - V_90 ;
if ( V_26 -> type != V_91 )
break;
V_122 = 0 ;
if ( V_88 -> V_218 )
V_122 = V_88 -> V_218 ( V_113 , V_116 , & V_5 ) ;
if ( V_122 == 0 )
F_3 ( V_5 ,
& V_26 -> V_345 . V_346 . V_347 ) ;
}
F_12 ( V_16 , L_75 , V_26 -> type ) ;
break;
}
case V_348 :
{
struct V_343 * V_26 = V_114 ;
if ( ! V_88 -> V_349 )
break;
if ( V_121 ) {
V_122 = V_121 ;
break;
}
V_122 = F_22 ( V_88 , V_26 -> type ) ;
if ( V_122 )
break;
F_12 ( V_16 , L_75 , V_26 -> type ) ;
V_122 = V_88 -> V_349 ( V_113 , V_116 , V_26 ) ;
break;
}
case V_350 :
{
struct V_351 * V_26 = V_114 ;
if ( ! V_88 -> V_352 )
break;
V_26 -> type = ( V_24 -> V_353 == V_354 ) ?
V_355 : V_356 ;
V_122 = V_88 -> V_352 ( V_113 , V_116 , V_26 ) ;
if ( ! V_122 )
F_12 ( V_16 , L_45
L_76
L_77
L_78 ,
V_26 -> V_35 , V_26 -> V_14 , V_26 -> type ,
V_26 -> V_202 , V_26 -> V_294 ,
V_26 -> V_295 , V_26 -> signal , V_26 -> V_357 ,
V_26 -> V_358 , V_26 -> V_359 ) ;
break;
}
case V_360 :
{
struct V_351 * V_26 = V_114 ;
if ( ! V_88 -> V_361 )
break;
if ( V_121 ) {
V_122 = V_121 ;
break;
}
V_26 -> type = ( V_24 -> V_353 == V_354 ) ?
V_355 : V_356 ;
F_12 ( V_16 , L_45
L_76
L_77
L_78 ,
V_26 -> V_35 , V_26 -> V_14 , V_26 -> type ,
V_26 -> V_202 , V_26 -> V_294 ,
V_26 -> V_295 , V_26 -> signal , V_26 -> V_357 ,
V_26 -> V_358 , V_26 -> V_359 ) ;
V_122 = V_88 -> V_361 ( V_113 , V_116 , V_26 ) ;
break;
}
case V_362 :
{
struct V_363 * V_26 = V_114 ;
if ( ! V_88 -> V_364 )
break;
V_26 -> type = ( V_24 -> V_353 == V_354 ) ?
V_355 : V_356 ;
V_122 = V_88 -> V_364 ( V_113 , V_116 , V_26 ) ;
if ( ! V_122 )
F_12 ( V_16 , L_79 ,
V_26 -> V_234 , V_26 -> type , V_26 -> V_365 ) ;
break;
}
case V_366 :
{
struct V_363 * V_26 = V_114 ;
enum V_367 type ;
if ( ! V_88 -> V_368 )
break;
if ( V_121 ) {
V_122 = V_121 ;
break;
}
type = ( V_24 -> V_353 == V_354 ) ?
V_355 : V_356 ;
F_12 ( V_16 , L_79 ,
V_26 -> V_234 , V_26 -> type , V_26 -> V_365 ) ;
if ( V_26 -> type != type )
V_122 = - V_90 ;
else
V_122 = V_88 -> V_368 ( V_113 , V_116 , V_26 ) ;
break;
}
case V_369 :
{
struct V_370 * V_26 = V_114 ;
if ( ! V_88 -> V_371 )
break;
memset ( V_26 , 0 , F_40 ( struct V_370 , type ) ) ;
F_12 ( V_16 , L_36 , F_13 ( V_26 -> type , V_36 ) ) ;
V_122 = V_88 -> V_371 ( V_113 , V_116 , V_26 ) ;
if ( ! V_122 )
F_15 ( L_80 , V_26 -> V_372 ) ;
break;
}
case V_373 :
{
if ( ! V_88 -> V_374 )
break;
V_122 = V_88 -> V_374 ( V_113 , V_116 ) ;
break;
}
#ifdef F_41
case V_375 :
{
struct V_376 * V_26 = V_114 ;
if ( V_88 -> V_377 ) {
if ( ! F_42 ( V_378 ) )
V_122 = - V_379 ;
else
V_122 = V_88 -> V_377 ( V_113 , V_116 , V_26 ) ;
}
break;
}
case V_380 :
{
struct V_376 * V_26 = V_114 ;
if ( V_88 -> V_381 ) {
if ( ! F_42 ( V_378 ) )
V_122 = - V_379 ;
else
V_122 = V_88 -> V_381 ( V_113 , V_116 , V_26 ) ;
}
break;
}
#endif
case V_382 :
{
struct V_383 * V_26 = V_114 ;
if ( ! V_88 -> V_384 )
break;
V_26 -> V_385 = V_386 ;
V_26 -> V_387 = 0 ;
V_122 = V_88 -> V_384 ( V_113 , V_116 , V_26 ) ;
if ( ! V_122 )
F_12 ( V_16 , L_81 , V_26 -> V_385 , V_26 -> V_387 ) ;
break;
}
case V_388 :
{
struct V_389 * V_26 = V_114 ;
enum V_367 type ;
if ( ! V_88 -> V_390 )
break;
if ( V_121 ) {
V_122 = V_121 ;
break;
}
type = ( V_24 -> V_353 == V_354 ) ?
V_355 : V_356 ;
F_12 ( V_16 ,
L_82 ,
V_26 -> V_234 , V_26 -> type , V_26 -> V_391 , V_26 -> V_392 , V_26 -> V_393 ) ;
if ( V_26 -> type != type )
V_122 = - V_90 ;
else
V_122 = V_88 -> V_390 ( V_113 , V_116 , V_26 ) ;
break;
}
case V_394 :
{
struct V_395 * V_26 = V_114 ;
if ( ! V_88 -> V_396 )
break;
V_122 = V_88 -> V_396 ( V_113 , V_116 , V_26 ) ;
F_12 ( V_16 ,
L_83 ,
V_26 -> V_35 ,
( V_26 -> V_397 & 0xff ) ,
( V_26 -> V_397 >> 8 ) & 0xff ,
( V_26 -> V_397 >> 16 ) & 0xff ,
( V_26 -> V_397 >> 24 ) & 0xff ,
V_26 -> type ) ;
switch ( V_26 -> type ) {
case V_398 :
F_43 ( L_84 ,
V_26 -> V_399 . V_59 , V_26 -> V_399 . V_60 ) ;
break;
case V_400 :
F_43 ( L_85 ,
V_26 -> V_401 . V_402 , V_26 -> V_401 . V_403 ,
V_26 -> V_401 . V_404 , V_26 -> V_401 . V_405 ,
V_26 -> V_401 . V_406 , V_26 -> V_401 . V_407 ) ;
break;
case V_408 :
F_43 ( L_86 ) ;
break;
default:
F_43 ( L_87 ) ;
}
break;
}
case V_409 :
{
struct V_410 * V_26 = V_114 ;
if ( ! V_88 -> V_411 )
break;
V_122 = V_88 -> V_411 ( V_113 , V_116 , V_26 ) ;
F_12 ( V_16 ,
L_88 ,
V_26 -> V_35 , V_26 -> V_397 ,
V_26 -> V_59 , V_26 -> V_60 , V_26 -> type ) ;
switch ( V_26 -> type ) {
case V_412 :
F_15 ( L_89 ,
V_26 -> V_399 . V_10 ,
V_26 -> V_399 . V_11 ) ;
break;
case V_413 :
F_15 ( L_90 ,
V_26 -> V_401 . V_414 . V_10 ,
V_26 -> V_401 . V_414 . V_11 ,
V_26 -> V_401 . V_415 . V_10 ,
V_26 -> V_401 . V_415 . V_11 ,
V_26 -> V_401 . V_257 . V_10 ,
V_26 -> V_401 . V_257 . V_11 ) ;
break;
case V_416 :
F_15 ( L_86 ) ;
break;
default:
F_15 ( L_87 ) ;
}
break;
}
case V_417 :
{
struct V_418 * V_26 = V_114 ;
if ( ! V_88 -> V_419 )
break;
V_122 = V_88 -> V_419 ( V_113 , V_116 , V_26 ) ;
if ( ! V_122 )
F_12 ( V_16 ,
L_91
L_92 ,
V_26 -> V_35 , V_26 -> V_420 , V_26 -> V_14 , V_26 -> V_59 ,
V_26 -> V_60 ) ;
break;
}
case V_421 :
{
struct V_422 * V_26 = V_114 ;
if ( ! V_88 -> V_228 )
break;
if ( V_121 ) {
V_122 = V_121 ;
break;
}
F_12 ( V_16 , L_93 , V_26 -> V_420 ) ;
V_122 = V_88 -> V_228 ( V_113 , V_116 , V_26 ) ;
break;
}
case V_423 :
{
struct V_422 * V_26 = V_114 ;
if ( ! V_88 -> V_424 )
break;
V_122 = V_88 -> V_424 ( V_113 , V_116 , V_26 ) ;
if ( ! V_122 )
F_12 ( V_16 , L_93 , V_26 -> V_420 ) ;
break;
}
case V_425 :
{
struct V_422 * V_26 = V_114 ;
if ( ! V_88 -> V_426 )
break;
V_122 = V_88 -> V_426 ( V_113 , V_116 , V_26 ) ;
if ( ! V_122 )
F_12 ( V_16 , L_93 , V_26 -> V_420 ) ;
break;
}
case V_427 :
{
struct V_428 * V_26 = V_114 ;
if ( ! V_88 -> V_230 )
break;
if ( V_121 ) {
V_122 = V_121 ;
break;
}
switch ( V_26 -> type ) {
case V_429 :
F_15 ( L_94
L_95
L_96
L_97
L_98
L_99 ,
V_26 -> V_430 . V_431 , V_26 -> V_430 . V_432 ,
V_26 -> V_430 . V_59 , V_26 -> V_430 . V_60 , V_26 -> V_430 . V_433 ,
V_26 -> V_430 . V_434 , V_26 -> V_430 . V_435 ,
V_26 -> V_430 . V_436 , V_26 -> V_430 . V_437 ,
V_26 -> V_430 . V_438 , V_26 -> V_430 . V_439 ,
V_26 -> V_430 . V_440 , V_26 -> V_430 . V_441 ,
V_26 -> V_430 . V_442 ) ;
V_122 = V_88 -> V_230 ( V_113 , V_116 , V_26 ) ;
break;
default:
F_15 ( L_100 , V_26 -> type ) ;
break;
}
break;
}
case V_443 :
{
struct V_428 * V_26 = V_114 ;
if ( ! V_88 -> V_444 )
break;
V_122 = V_88 -> V_444 ( V_113 , V_116 , V_26 ) ;
if ( ! V_122 ) {
switch ( V_26 -> type ) {
case V_429 :
F_15 ( L_101
L_102
L_95
L_103
L_104
L_105
L_98
L_99 ,
V_26 -> V_430 . V_431 , V_26 -> V_430 . V_432 ,
V_26 -> V_430 . V_59 , V_26 -> V_430 . V_60 ,
V_26 -> V_430 . V_433 , V_26 -> V_430 . V_434 ,
V_26 -> V_430 . V_435 , V_26 -> V_430 . V_436 ,
V_26 -> V_430 . V_437 , V_26 -> V_430 . V_438 ,
V_26 -> V_430 . V_439 , V_26 -> V_430 . V_440 ,
V_26 -> V_430 . V_441 , V_26 -> V_430 . V_442 ) ;
break;
default:
F_15 ( L_100 , V_26 -> type ) ;
break;
}
}
break;
}
case V_445 :
{
struct V_446 * V_447 = V_114 ;
if ( ! V_88 -> V_448 )
break;
V_122 = F_44 ( V_116 , V_447 , V_113 -> V_449 & V_450 ) ;
if ( V_122 < 0 ) {
F_12 ( V_16 , L_106 ) ;
break;
}
F_12 ( V_16 ,
L_107
L_108 ,
V_447 -> V_451 , V_447 -> type , V_447 -> V_39 ,
V_447 -> V_32 . V_33 , V_447 -> V_32 . V_452 ) ;
break;
}
case V_453 :
{
struct V_454 * V_455 = V_114 ;
if ( ! V_88 -> V_448 )
break;
V_122 = V_88 -> V_448 ( V_116 , V_455 ) ;
if ( V_122 < 0 ) {
F_12 ( V_16 , L_109 , V_122 ) ;
break;
}
F_12 ( V_16 , L_110 , V_455 -> type ) ;
break;
}
case V_456 :
{
struct V_454 * V_455 = V_114 ;
if ( ! V_88 -> V_457 )
break;
V_122 = V_88 -> V_457 ( V_116 , V_455 ) ;
if ( V_122 < 0 ) {
F_12 ( V_16 , L_109 , V_122 ) ;
break;
}
F_12 ( V_16 , L_110 , V_455 -> type ) ;
break;
}
case V_458 :
{
struct V_459 * V_460 = V_114 ;
if ( ! V_88 -> V_461 )
break;
if ( V_121 ) {
V_122 = V_121 ;
break;
}
V_122 = F_22 ( V_88 , V_460 -> V_462 . type ) ;
if ( V_122 )
break;
V_122 = V_88 -> V_461 ( V_113 , V_116 , V_460 ) ;
F_12 ( V_16 , L_111 , V_460 -> V_78 , V_460 -> V_35 ) ;
break;
}
case V_463 :
{
struct V_25 * V_464 = V_114 ;
if ( ! V_88 -> V_465 )
break;
V_122 = F_22 ( V_88 , V_464 -> type ) ;
if ( V_122 )
break;
V_122 = V_88 -> V_465 ( V_113 , V_116 , V_464 ) ;
F_12 ( V_16 , L_112 , V_464 -> V_35 ) ;
break;
}
default:
if ( ! V_88 -> V_466 )
break;
V_122 = V_88 -> V_466 ( V_113 , V_116 , V_121 >= 0 , V_16 , V_114 ) ;
break;
}
if ( V_24 -> V_74 & V_75 ) {
if ( V_122 < 0 ) {
F_25 ( V_24 -> V_14 , V_16 ) ;
F_9 ( V_76 L_113 , V_122 ) ;
}
}
return V_122 ;
}
static unsigned long F_45 ( unsigned int V_16 )
{
#define F_46 ( V_16 , type , V_38 ) \
case VIDIOC_##cmd: \
return offsetof(struct v4l2_##type, field) + \
sizeof(((struct v4l2_##type *)0)->field);
switch ( V_16 ) {
F_46 ( V_467 , V_468 , type ) ;
F_46 ( V_469 , V_462 , type ) ;
F_46 ( V_470 , V_471 , V_44 ) ;
F_46 ( V_472 , V_473 , type ) ;
F_46 ( V_474 , V_475 , V_35 ) ;
F_46 ( V_476 , V_477 , V_35 ) ;
F_46 ( V_478 , V_479 , V_1 ) ;
F_46 ( V_480 , V_234 , V_35 ) ;
F_46 ( V_481 , V_482 , V_1 ) ;
F_46 ( V_483 , V_484 , V_35 ) ;
F_46 ( V_485 , V_486 , V_35 ) ;
F_46 ( V_487 , V_246 , V_35 ) ;
F_46 ( V_488 , V_365 , V_234 ) ;
F_46 ( V_489 , V_490 , type ) ;
F_46 ( V_491 , V_492 , type ) ;
F_46 ( V_493 , V_494 , V_35 ) ;
F_46 ( V_495 , V_496 , V_35 ) ;
F_46 ( V_497 , V_498 , V_37 ) ;
F_46 ( V_499 , V_498 , V_37 ) ;
F_46 ( V_500 , V_501 , type ) ;
F_46 ( V_502 , V_503 , V_397 ) ;
F_46 ( V_504 , V_505 , V_60 ) ;
default:
return F_47 ( V_16 ) ;
}
}
static int F_48 ( unsigned int V_16 , void * V_506 , T_3 * V_507 ,
void * T_4 * V_508 , void * * * V_509 )
{
int V_122 = 0 ;
switch ( V_16 ) {
case V_191 :
case V_193 :
case V_195 : {
struct V_25 * V_510 = V_506 ;
if ( F_14 ( V_510 -> type ) && V_510 -> V_44 > 0 ) {
if ( V_510 -> V_44 > V_511 ) {
V_122 = - V_90 ;
break;
}
* V_508 = ( void T_4 * ) V_510 -> V_42 . V_43 ;
* V_509 = ( void * ) & V_510 -> V_42 . V_43 ;
* V_507 = sizeof( struct V_30 ) * V_510 -> V_44 ;
V_122 = 1 ;
}
break;
}
case V_270 :
case V_269 :
case V_271 : {
struct V_71 * V_263 = V_506 ;
if ( V_263 -> V_78 != 0 ) {
if ( V_263 -> V_78 > V_512 ) {
V_122 = - V_90 ;
break;
}
* V_508 = ( void T_4 * ) V_263 -> V_79 ;
* V_509 = ( void * ) & V_263 -> V_79 ;
* V_507 = sizeof( struct V_264 )
* V_263 -> V_78 ;
V_122 = 1 ;
}
break;
}
}
return V_122 ;
}
long
F_49 ( struct V_113 * V_113 , unsigned int V_16 , unsigned long V_114 ,
T_5 V_513 )
{
char V_514 [ 128 ] ;
void * V_515 = NULL ;
void * V_506 = ( void * ) V_114 ;
long V_516 = - V_90 ;
bool V_517 ;
T_3 V_507 = 0 ;
void T_4 * V_508 = NULL ;
void * * V_509 = NULL ;
if ( F_10 ( V_16 ) != V_20 ) {
if ( F_47 ( V_16 ) <= sizeof( V_514 ) ) {
V_506 = V_514 ;
} else {
V_515 = F_50 ( F_47 ( V_16 ) , V_518 ) ;
if ( NULL == V_515 )
return - V_519 ;
V_506 = V_515 ;
}
V_516 = - V_520 ;
if ( F_10 ( V_16 ) & V_22 ) {
unsigned long V_521 = F_45 ( V_16 ) ;
if ( F_51 ( V_506 , ( void T_4 * ) V_114 , V_521 ) )
goto V_522;
if ( V_521 < F_47 ( V_16 ) )
memset ( ( V_523 * ) V_506 + V_521 , 0 , F_47 ( V_16 ) - V_521 ) ;
} else {
memset ( V_506 , 0 , F_47 ( V_16 ) ) ;
}
}
V_516 = F_48 ( V_16 , V_506 , & V_507 , & V_508 , & V_509 ) ;
if ( V_516 < 0 )
goto V_522;
V_517 = V_516 ;
if ( V_517 ) {
V_515 = F_50 ( V_507 , V_518 ) ;
V_516 = - V_519 ;
if ( NULL == V_515 )
goto V_524;
V_516 = - V_520 ;
if ( F_51 ( V_515 , V_508 , V_507 ) )
goto V_524;
* V_509 = V_515 ;
}
V_516 = V_513 ( V_113 , V_16 , V_506 ) ;
if ( V_516 == - V_525 )
V_516 = - V_90 ;
if ( V_517 ) {
* V_509 = V_508 ;
if ( F_52 ( V_508 , V_515 , V_507 ) )
V_516 = - V_520 ;
goto V_524;
}
if ( V_516 < 0 )
goto V_522;
V_524:
switch ( F_10 ( V_16 ) ) {
case V_21 :
case ( V_22 | V_21 ) :
if ( F_52 ( ( void T_4 * ) V_114 , V_506 , F_47 ( V_16 ) ) )
V_516 = - V_520 ;
break;
}
V_522:
F_53 ( V_515 ) ;
return V_516 ;
}
long F_54 ( struct V_113 * V_113 ,
unsigned int V_16 , unsigned long V_114 )
{
return F_49 ( V_113 , V_16 , V_114 , F_23 ) ;
}
