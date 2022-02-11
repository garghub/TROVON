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
static int F_23 ( const struct V_113 * V_114 ,
struct V_113 * V_115 )
{
struct V_68 * V_116 = & V_115 -> V_62 . V_116 ;
const struct V_61 * V_117 = & V_114 -> V_62 . V_117 ;
if ( V_114 -> type == V_91 )
V_115 -> type = V_94 ;
else if ( V_114 -> type == V_97 )
V_115 -> type = V_100 ;
else
return - V_90 ;
V_116 -> V_59 = V_117 -> V_59 ;
V_116 -> V_60 = V_117 -> V_60 ;
V_116 -> V_63 = V_117 -> V_63 ;
V_116 -> V_38 = V_117 -> V_38 ;
V_116 -> V_67 = V_117 -> V_67 ;
V_116 -> V_69 = 1 ;
V_116 -> V_70 [ 0 ] . V_66 = V_117 -> V_66 ;
V_116 -> V_70 [ 0 ] . V_65 = V_117 -> V_65 ;
return 0 ;
}
static int F_24 ( const struct V_113 * V_115 ,
struct V_113 * V_114 )
{
const struct V_68 * V_116 = & V_115 -> V_62 . V_116 ;
struct V_61 * V_117 = & V_114 -> V_62 . V_117 ;
if ( V_115 -> type == V_94 )
V_114 -> type = V_91 ;
else if ( V_115 -> type == V_100 )
V_114 -> type = V_97 ;
else
return - V_90 ;
V_117 -> V_59 = V_116 -> V_59 ;
V_117 -> V_60 = V_116 -> V_60 ;
V_117 -> V_63 = V_116 -> V_63 ;
V_117 -> V_38 = V_116 -> V_38 ;
V_117 -> V_67 = V_116 -> V_67 ;
V_117 -> V_66 = V_116 -> V_70 [ 0 ] . V_66 ;
V_117 -> V_65 = V_116 -> V_70 [ 0 ] . V_65 ;
return 0 ;
}
static long F_25 ( struct V_118 * V_118 ,
unsigned int V_16 , void * V_119 )
{
struct V_23 * V_24 = F_26 ( V_118 ) ;
const struct V_87 * V_88 = V_24 -> V_120 ;
void * V_121 = V_118 -> V_122 ;
struct V_123 * V_124 = NULL ;
struct V_113 V_125 ;
int V_126 = 0 ;
long V_127 = - V_128 ;
if ( V_88 == NULL ) {
F_9 ( V_129 L_28 ,
V_24 -> V_14 ) ;
return V_127 ;
}
if ( ( V_24 -> V_74 & V_130 ) &&
! ( V_24 -> V_74 & V_75 ) ) {
F_27 ( V_24 -> V_14 , V_16 ) ;
F_9 ( V_76 L_27 ) ;
}
if ( F_28 ( V_131 , & V_24 -> V_37 ) ) {
V_124 = V_118 -> V_122 ;
V_126 = F_28 ( V_132 , & V_24 -> V_37 ) ;
}
if ( V_126 ) {
switch ( V_16 ) {
case V_133 :
case V_134 :
case V_135 :
case V_136 :
case V_137 :
case V_138 :
case V_139 :
case V_140 :
case V_141 :
case V_142 :
case V_143 :
case V_144 :
case V_145 :
case V_146 :
case V_147 :
case V_148 :
case V_149 :
case V_150 :
case V_151 :
case V_152 :
case V_153 :
case V_154 :
case V_155 :
case V_156 :
V_127 = F_29 ( V_24 -> V_157 , V_124 -> V_157 ) ;
if ( V_127 )
goto V_158;
V_127 = - V_90 ;
break;
}
}
switch ( V_16 ) {
case V_159 :
{
struct V_160 * V_161 = (struct V_160 * ) V_119 ;
if ( ! V_88 -> V_162 )
break;
V_161 -> V_163 = V_164 ;
V_127 = V_88 -> V_162 ( V_118 , V_121 , V_161 ) ;
if ( ! V_127 )
F_12 ( V_16 , L_29
L_30
L_31 ,
V_161 -> V_165 , V_161 -> V_166 , V_161 -> V_167 ,
V_161 -> V_163 ,
V_161 -> V_168 ) ;
break;
}
case V_169 :
{
enum V_170 * V_26 = V_119 ;
if ( V_88 -> V_171 ) {
V_127 = V_88 -> V_171 ( V_118 , V_121 , V_26 ) ;
} else if ( V_126 ) {
* V_26 = F_30 ( & V_24 -> V_172 -> V_157 ) ;
V_127 = 0 ;
}
if ( ! V_127 )
F_12 ( V_16 , L_32 , * V_26 ) ;
break;
}
case V_145 :
{
enum V_170 * V_26 = V_119 ;
if ( ! V_88 -> V_173 && ! V_126 )
break;
F_12 ( V_16 , L_33 , * V_26 ) ;
if ( V_88 -> V_173 )
V_127 = V_88 -> V_173 ( V_118 , V_121 , * V_26 ) ;
else
V_127 = F_31 ( & V_24 -> V_172 -> V_157 , & V_124 -> V_157 , * V_26 ) ;
break;
}
case V_174 :
{
struct V_175 * V_176 = V_119 ;
switch ( V_176 -> type ) {
case V_91 :
if ( V_88 -> V_177 )
V_127 = V_88 -> V_177 ( V_118 , V_121 , V_176 ) ;
break;
case V_94 :
if ( V_88 -> V_178 )
V_127 = V_88 -> V_178 ( V_118 ,
V_121 , V_176 ) ;
break;
case V_95 :
if ( V_88 -> V_179 )
V_127 = V_88 -> V_179 ( V_118 ,
V_121 , V_176 ) ;
break;
case V_97 :
if ( V_88 -> V_180 )
V_127 = V_88 -> V_180 ( V_118 , V_121 , V_176 ) ;
break;
case V_100 :
if ( V_88 -> V_181 )
V_127 = V_88 -> V_181 ( V_118 ,
V_121 , V_176 ) ;
break;
case V_111 :
if ( V_88 -> V_182 )
V_127 = V_88 -> V_182 ( V_118 ,
V_121 , V_176 ) ;
break;
default:
break;
}
if ( ! V_127 )
F_12 ( V_16 , L_34
L_35 ,
V_176 -> V_35 , V_176 -> type , V_176 -> V_37 ,
( V_176 -> V_63 & 0xff ) ,
( V_176 -> V_63 >> 8 ) & 0xff ,
( V_176 -> V_63 >> 16 ) & 0xff ,
( V_176 -> V_63 >> 24 ) & 0xff ,
V_176 -> V_183 ) ;
break;
}
case V_184 :
{
struct V_113 * V_176 = (struct V_113 * ) V_119 ;
F_12 ( V_16 , L_36 , F_13 ( V_176 -> type , V_36 ) ) ;
switch ( V_176 -> type ) {
case V_91 :
if ( V_88 -> V_92 ) {
V_127 = V_88 -> V_92 ( V_118 , V_121 , V_176 ) ;
} else if ( V_88 -> V_93 ) {
if ( F_23 ( V_176 , & V_125 ) )
break;
V_127 = V_88 -> V_93 ( V_118 , V_121 ,
& V_125 ) ;
if ( V_127 )
break;
if ( V_125 . V_62 . V_116 . V_69 > 1 ) {
V_127 = - V_185 ;
break;
}
V_127 = F_24 ( & V_125 , V_176 ) ;
}
if ( ! V_127 )
F_17 ( V_24 , & V_176 -> V_62 . V_117 ) ;
break;
case V_94 :
if ( V_88 -> V_93 ) {
V_127 = V_88 -> V_93 ( V_118 ,
V_121 , V_176 ) ;
} else if ( V_88 -> V_92 ) {
if ( F_24 ( V_176 , & V_125 ) )
break;
V_127 = V_88 -> V_92 ( V_118 ,
V_121 , & V_125 ) ;
if ( V_127 )
break;
V_127 = F_23 ( & V_125 , V_176 ) ;
}
if ( ! V_127 )
F_18 ( V_24 , & V_176 -> V_62 . V_116 ) ;
break;
case V_95 :
if ( V_88 -> V_96 )
V_127 = V_88 -> V_96 ( V_118 ,
V_121 , V_176 ) ;
break;
case V_97 :
if ( V_88 -> V_98 ) {
V_127 = V_88 -> V_98 ( V_118 , V_121 , V_176 ) ;
} else if ( V_88 -> V_99 ) {
if ( F_23 ( V_176 , & V_125 ) )
break;
V_127 = V_88 -> V_99 ( V_118 , V_121 ,
& V_125 ) ;
if ( V_127 )
break;
if ( V_125 . V_62 . V_116 . V_69 > 1 ) {
V_127 = - V_185 ;
break;
}
V_127 = F_24 ( & V_125 , V_176 ) ;
}
if ( ! V_127 )
F_17 ( V_24 , & V_176 -> V_62 . V_117 ) ;
break;
case V_100 :
if ( V_88 -> V_99 ) {
V_127 = V_88 -> V_99 ( V_118 ,
V_121 , V_176 ) ;
} else if ( V_88 -> V_98 ) {
if ( F_24 ( V_176 , & V_125 ) )
break;
V_127 = V_88 -> V_98 ( V_118 ,
V_121 , & V_125 ) ;
if ( V_127 )
break;
V_127 = F_23 ( & V_125 , V_176 ) ;
}
if ( ! V_127 )
F_18 ( V_24 , & V_176 -> V_62 . V_116 ) ;
break;
case V_101 :
if ( V_88 -> V_102 )
V_127 = V_88 -> V_102 ( V_118 ,
V_121 , V_176 ) ;
break;
case V_103 :
if ( V_88 -> V_104 )
V_127 = V_88 -> V_104 ( V_118 , V_121 , V_176 ) ;
break;
case V_105 :
if ( V_88 -> V_106 )
V_127 = V_88 -> V_106 ( V_118 , V_121 , V_176 ) ;
break;
case V_107 :
if ( V_88 -> V_108 )
V_127 = V_88 -> V_108 ( V_118 ,
V_121 , V_176 ) ;
break;
case V_109 :
if ( V_88 -> V_110 )
V_127 = V_88 -> V_110 ( V_118 ,
V_121 , V_176 ) ;
break;
case V_111 :
if ( V_88 -> V_112 )
V_127 = V_88 -> V_112 ( V_118 ,
V_121 , V_176 ) ;
break;
}
break;
}
case V_139 :
{
struct V_113 * V_176 = (struct V_113 * ) V_119 ;
F_12 ( V_16 , L_36 , F_13 ( V_176 -> type , V_36 ) ) ;
switch ( V_176 -> type ) {
case V_91 :
F_32 ( V_176 , V_62 . V_117 ) ;
F_17 ( V_24 , & V_176 -> V_62 . V_117 ) ;
if ( V_88 -> V_186 ) {
V_127 = V_88 -> V_186 ( V_118 , V_121 , V_176 ) ;
} else if ( V_88 -> V_187 ) {
if ( F_23 ( V_176 , & V_125 ) )
break;
V_127 = V_88 -> V_187 ( V_118 , V_121 ,
& V_125 ) ;
if ( V_127 )
break;
if ( V_125 . V_62 . V_116 . V_69 > 1 ) {
V_127 = - V_185 ;
F_33 ( 1 ) ;
break;
}
V_127 = F_24 ( & V_125 , V_176 ) ;
}
break;
case V_94 :
F_32 ( V_176 , V_62 . V_116 ) ;
F_18 ( V_24 , & V_176 -> V_62 . V_116 ) ;
if ( V_88 -> V_187 ) {
V_127 = V_88 -> V_187 ( V_118 ,
V_121 , V_176 ) ;
} else if ( V_88 -> V_186 &&
V_176 -> V_62 . V_116 . V_69 == 1 ) {
if ( F_24 ( V_176 , & V_125 ) )
break;
V_127 = V_88 -> V_186 ( V_118 ,
V_121 , & V_125 ) ;
if ( V_127 )
break;
V_127 = F_23 ( & V_125 , V_176 ) ;
}
break;
case V_95 :
F_32 ( V_176 , V_62 . V_188 ) ;
if ( V_88 -> V_189 )
V_127 = V_88 -> V_189 ( V_118 ,
V_121 , V_176 ) ;
break;
case V_97 :
F_32 ( V_176 , V_62 . V_117 ) ;
F_17 ( V_24 , & V_176 -> V_62 . V_117 ) ;
if ( V_88 -> V_190 ) {
V_127 = V_88 -> V_190 ( V_118 , V_121 , V_176 ) ;
} else if ( V_88 -> V_191 ) {
if ( F_23 ( V_176 , & V_125 ) )
break;
V_127 = V_88 -> V_191 ( V_118 , V_121 ,
& V_125 ) ;
if ( V_127 )
break;
if ( V_125 . V_62 . V_116 . V_69 > 1 ) {
V_127 = - V_185 ;
F_33 ( 1 ) ;
break;
}
V_127 = F_24 ( & V_125 , V_176 ) ;
}
break;
case V_100 :
F_32 ( V_176 , V_62 . V_116 ) ;
F_18 ( V_24 , & V_176 -> V_62 . V_116 ) ;
if ( V_88 -> V_191 ) {
V_127 = V_88 -> V_191 ( V_118 ,
V_121 , V_176 ) ;
} else if ( V_88 -> V_190 &&
V_176 -> V_62 . V_116 . V_69 == 1 ) {
if ( F_24 ( V_176 , & V_125 ) )
break;
V_127 = V_88 -> V_190 ( V_118 ,
V_121 , & V_125 ) ;
if ( V_127 )
break;
V_127 = F_24 ( & V_125 , V_176 ) ;
}
break;
case V_101 :
F_32 ( V_176 , V_62 . V_188 ) ;
if ( V_88 -> V_192 )
V_127 = V_88 -> V_192 ( V_118 ,
V_121 , V_176 ) ;
break;
case V_103 :
F_32 ( V_176 , V_62 . V_193 ) ;
if ( V_88 -> V_194 )
V_127 = V_88 -> V_194 ( V_118 , V_121 , V_176 ) ;
break;
case V_105 :
F_32 ( V_176 , V_62 . V_193 ) ;
if ( V_88 -> V_195 )
V_127 = V_88 -> V_195 ( V_118 , V_121 , V_176 ) ;
break;
case V_107 :
F_32 ( V_176 , V_62 . V_196 ) ;
if ( V_88 -> V_197 )
V_127 = V_88 -> V_197 ( V_118 ,
V_121 , V_176 ) ;
break;
case V_109 :
F_32 ( V_176 , V_62 . V_196 ) ;
if ( V_88 -> V_198 )
V_127 = V_88 -> V_198 ( V_118 ,
V_121 , V_176 ) ;
break;
case V_111 :
if ( V_88 -> V_199 )
V_127 = V_88 -> V_199 ( V_118 ,
V_121 , V_176 ) ;
break;
}
break;
}
case V_200 :
{
struct V_113 * V_176 = (struct V_113 * ) V_119 ;
F_12 ( V_16 , L_36 , F_13 ( V_176 -> type ,
V_36 ) ) ;
switch ( V_176 -> type ) {
case V_91 :
F_32 ( V_176 , V_62 . V_117 ) ;
if ( V_88 -> V_201 ) {
V_127 = V_88 -> V_201 ( V_118 , V_121 , V_176 ) ;
} else if ( V_88 -> V_202 ) {
if ( F_23 ( V_176 , & V_125 ) )
break;
V_127 = V_88 -> V_202 ( V_118 ,
V_121 , & V_125 ) ;
if ( V_127 )
break;
if ( V_125 . V_62 . V_116 . V_69 > 1 ) {
V_127 = - V_185 ;
F_33 ( 1 ) ;
break;
}
V_127 = F_24 ( & V_125 , V_176 ) ;
}
if ( ! V_127 )
F_17 ( V_24 , & V_176 -> V_62 . V_117 ) ;
break;
case V_94 :
F_32 ( V_176 , V_62 . V_116 ) ;
if ( V_88 -> V_202 ) {
V_127 = V_88 -> V_202 ( V_118 ,
V_121 , V_176 ) ;
} else if ( V_88 -> V_201 &&
V_176 -> V_62 . V_116 . V_69 == 1 ) {
if ( F_24 ( V_176 , & V_125 ) )
break;
V_127 = V_88 -> V_201 ( V_118 ,
V_121 , & V_125 ) ;
if ( V_127 )
break;
V_127 = F_23 ( & V_125 , V_176 ) ;
}
if ( ! V_127 )
F_18 ( V_24 , & V_176 -> V_62 . V_116 ) ;
break;
case V_95 :
F_32 ( V_176 , V_62 . V_188 ) ;
if ( V_88 -> V_203 )
V_127 = V_88 -> V_203 ( V_118 ,
V_121 , V_176 ) ;
break;
case V_97 :
F_32 ( V_176 , V_62 . V_117 ) ;
if ( V_88 -> V_204 ) {
V_127 = V_88 -> V_204 ( V_118 , V_121 , V_176 ) ;
} else if ( V_88 -> V_205 ) {
if ( F_23 ( V_176 , & V_125 ) )
break;
V_127 = V_88 -> V_205 ( V_118 ,
V_121 , & V_125 ) ;
if ( V_127 )
break;
if ( V_125 . V_62 . V_116 . V_69 > 1 ) {
V_127 = - V_185 ;
F_33 ( 1 ) ;
break;
}
V_127 = F_24 ( & V_125 , V_176 ) ;
}
if ( ! V_127 )
F_17 ( V_24 , & V_176 -> V_62 . V_117 ) ;
break;
case V_100 :
F_32 ( V_176 , V_62 . V_116 ) ;
if ( V_88 -> V_205 ) {
V_127 = V_88 -> V_205 ( V_118 ,
V_121 , V_176 ) ;
} else if ( V_88 -> V_204 &&
V_176 -> V_62 . V_116 . V_69 == 1 ) {
if ( F_24 ( V_176 , & V_125 ) )
break;
V_127 = V_88 -> V_204 ( V_118 ,
V_121 , & V_125 ) ;
if ( V_127 )
break;
V_127 = F_23 ( & V_125 , V_176 ) ;
}
if ( ! V_127 )
F_18 ( V_24 , & V_176 -> V_62 . V_116 ) ;
break;
case V_101 :
F_32 ( V_176 , V_62 . V_188 ) ;
if ( V_88 -> V_206 )
V_127 = V_88 -> V_206 ( V_118 ,
V_121 , V_176 ) ;
break;
case V_103 :
F_32 ( V_176 , V_62 . V_193 ) ;
if ( V_88 -> V_207 )
V_127 = V_88 -> V_207 ( V_118 , V_121 , V_176 ) ;
break;
case V_105 :
F_32 ( V_176 , V_62 . V_193 ) ;
if ( V_88 -> V_208 )
V_127 = V_88 -> V_208 ( V_118 , V_121 , V_176 ) ;
break;
case V_107 :
F_32 ( V_176 , V_62 . V_196 ) ;
if ( V_88 -> V_209 )
V_127 = V_88 -> V_209 ( V_118 ,
V_121 , V_176 ) ;
break;
case V_109 :
F_32 ( V_176 , V_62 . V_196 ) ;
if ( V_88 -> V_210 )
V_127 = V_88 -> V_210 ( V_118 ,
V_121 , V_176 ) ;
break;
case V_111 :
if ( V_88 -> V_211 )
V_127 = V_88 -> V_211 ( V_118 ,
V_121 , V_176 ) ;
break;
}
break;
}
case V_154 :
{
struct V_212 * V_26 = V_119 ;
if ( ! V_88 -> V_213 )
break;
V_127 = F_22 ( V_88 , V_26 -> type ) ;
if ( V_127 )
break;
if ( V_26 -> type < V_111 )
F_32 ( V_26 , V_40 ) ;
V_127 = V_88 -> V_213 ( V_118 , V_121 , V_26 ) ;
F_12 ( V_16 , L_37 ,
V_26 -> V_78 ,
F_13 ( V_26 -> type , V_36 ) ,
F_13 ( V_26 -> V_40 , V_41 ) ) ;
break;
}
case V_214 :
{
struct V_25 * V_26 = V_119 ;
if ( ! V_88 -> V_215 )
break;
V_127 = F_22 ( V_88 , V_26 -> type ) ;
if ( V_127 )
break;
V_127 = V_88 -> V_215 ( V_118 , V_121 , V_26 ) ;
if ( ! V_127 )
F_11 ( V_16 , V_24 , V_26 ) ;
break;
}
case V_216 :
{
struct V_25 * V_26 = V_119 ;
if ( ! V_88 -> V_217 )
break;
V_127 = F_22 ( V_88 , V_26 -> type ) ;
if ( V_127 )
break;
V_127 = V_88 -> V_217 ( V_118 , V_121 , V_26 ) ;
if ( ! V_127 )
F_11 ( V_16 , V_24 , V_26 ) ;
break;
}
case V_218 :
{
struct V_25 * V_26 = V_119 ;
if ( ! V_88 -> V_219 )
break;
V_127 = F_22 ( V_88 , V_26 -> type ) ;
if ( V_127 )
break;
V_127 = V_88 -> V_219 ( V_118 , V_121 , V_26 ) ;
if ( ! V_127 )
F_11 ( V_16 , V_24 , V_26 ) ;
break;
}
case V_153 :
{
int * V_3 = V_119 ;
if ( ! V_88 -> V_220 )
break;
F_12 ( V_16 , L_38 , * V_3 ) ;
V_127 = V_88 -> V_220 ( V_118 , V_121 , * V_3 ) ;
break;
}
case V_221 :
{
struct V_222 * V_26 = V_119 ;
if ( ! V_88 -> V_223 )
break;
V_127 = V_88 -> V_223 ( V_118 , V_121 , V_119 ) ;
if ( ! V_127 ) {
F_12 ( V_16 , L_39 ,
V_26 -> V_224 , V_26 -> V_37 ,
( unsigned long ) V_26 -> V_225 ) ;
F_17 ( V_24 , & V_26 -> V_62 ) ;
}
break;
}
case V_144 :
{
struct V_222 * V_26 = V_119 ;
if ( ! V_88 -> V_226 )
break;
F_12 ( V_16 , L_39 ,
V_26 -> V_224 , V_26 -> V_37 , ( unsigned long ) V_26 -> V_225 ) ;
F_17 ( V_24 , & V_26 -> V_62 ) ;
V_127 = V_88 -> V_226 ( V_118 , V_121 , V_119 ) ;
break;
}
case V_155 :
{
enum V_89 V_3 = * ( int * ) V_119 ;
if ( ! V_88 -> V_227 )
break;
F_12 ( V_16 , L_36 , F_13 ( V_3 , V_36 ) ) ;
V_127 = V_88 -> V_227 ( V_118 , V_121 , V_3 ) ;
break;
}
case V_156 :
{
enum V_89 V_3 = * ( int * ) V_119 ;
if ( ! V_88 -> V_228 )
break;
F_12 ( V_16 , L_36 , F_13 ( V_3 , V_36 ) ) ;
V_127 = V_88 -> V_228 ( V_118 , V_121 , V_3 ) ;
break;
}
case V_229 :
{
struct V_12 * V_26 = V_119 ;
T_1 V_1 = V_24 -> V_230 , V_231 = 0 ;
unsigned int V_35 = V_26 -> V_35 , V_3 , V_232 = 0 ;
const char * V_6 = L_23 ;
for ( V_3 = 0 ; V_3 <= V_35 && V_1 ; V_3 ++ ) {
while ( ( V_1 & V_4 [ V_232 ] . V_5 ) != V_4 [ V_232 ] . V_5 )
V_232 ++ ;
V_231 = V_4 [ V_232 ] . V_5 ;
V_6 = V_4 [ V_232 ] . V_6 ;
V_232 ++ ;
if ( V_231 == 0 )
break;
if ( V_231 != V_233 &&
V_231 != V_234 &&
V_231 != V_235 )
V_1 &= ~ V_231 ;
}
if ( V_3 <= V_35 )
break;
F_4 ( V_26 , V_231 , V_6 ) ;
F_12 ( V_16 , L_40
L_41 , V_26 -> V_35 ,
( unsigned long long ) V_26 -> V_1 , V_26 -> V_14 ,
V_26 -> V_8 . V_10 ,
V_26 -> V_8 . V_11 ,
V_26 -> V_15 ) ;
V_127 = 0 ;
break;
}
case V_236 :
{
T_1 * V_1 = V_119 ;
V_127 = 0 ;
if ( V_88 -> V_237 )
V_127 = V_88 -> V_237 ( V_118 , V_121 , V_1 ) ;
else if ( V_24 -> V_238 )
* V_1 = V_24 -> V_238 ;
else
V_127 = - V_90 ;
if ( ! V_127 )
F_12 ( V_16 , L_42 , ( long long unsigned ) * V_1 ) ;
break;
}
case V_134 :
{
T_1 * V_1 = V_119 , V_239 ;
F_12 ( V_16 , L_43 , ( long long unsigned ) * V_1 ) ;
V_239 = ( * V_1 ) & V_24 -> V_230 ;
if ( V_24 -> V_230 && ! V_239 )
break;
if ( V_88 -> V_240 )
V_127 = V_88 -> V_240 ( V_118 , V_121 , & V_239 ) ;
else
V_127 = - V_90 ;
if ( V_127 >= 0 )
V_24 -> V_238 = V_239 ;
break;
}
case V_241 :
{
T_1 * V_26 = V_119 ;
if ( ! V_88 -> V_242 )
break;
V_127 = V_88 -> V_242 ( V_118 , V_121 , V_119 ) ;
if ( ! V_127 )
F_12 ( V_16 , L_44 ,
( unsigned long long ) * V_26 ) ;
break;
}
case V_243 :
{
struct V_244 * V_26 = V_119 ;
if ( V_88 -> V_240 )
V_26 -> V_168 |= V_245 ;
if ( V_88 -> V_246 )
V_26 -> V_168 |= V_247 ;
if ( V_88 -> V_248 )
V_26 -> V_168 |= V_249 ;
if ( ! V_88 -> V_250 )
break;
V_127 = V_88 -> V_250 ( V_118 , V_121 , V_26 ) ;
if ( ! V_127 )
F_12 ( V_16 , L_45
L_46
L_47 ,
V_26 -> V_35 , V_26 -> V_14 , V_26 -> type , V_26 -> V_251 ,
V_26 -> V_252 ,
( unsigned long long ) V_26 -> V_5 ,
V_26 -> V_253 ) ;
break;
}
case V_254 :
{
unsigned int * V_3 = V_119 ;
if ( ! V_88 -> V_255 )
break;
V_127 = V_88 -> V_255 ( V_118 , V_121 , V_3 ) ;
if ( ! V_127 )
F_12 ( V_16 , L_38 , * V_3 ) ;
break;
}
case V_135 :
{
unsigned int * V_3 = V_119 ;
if ( ! V_88 -> V_256 )
break;
F_12 ( V_16 , L_38 , * V_3 ) ;
V_127 = V_88 -> V_256 ( V_118 , V_121 , * V_3 ) ;
break;
}
case V_257 :
{
struct V_258 * V_26 = V_119 ;
if ( ! V_88 -> V_259 )
break;
if ( V_88 -> V_240 )
V_26 -> V_168 |= V_260 ;
if ( V_88 -> V_246 )
V_26 -> V_168 |= V_261 ;
if ( V_88 -> V_248 )
V_26 -> V_168 |= V_262 ;
V_127 = V_88 -> V_259 ( V_118 , V_121 , V_26 ) ;
if ( ! V_127 )
F_12 ( V_16 , L_45
L_48
L_49 ,
V_26 -> V_35 , V_26 -> V_14 , V_26 -> type , V_26 -> V_251 ,
V_26 -> V_263 , ( unsigned long long ) V_26 -> V_5 ) ;
break;
}
case V_264 :
{
unsigned int * V_3 = V_119 ;
if ( ! V_88 -> V_265 )
break;
V_127 = V_88 -> V_265 ( V_118 , V_121 , V_3 ) ;
if ( ! V_127 )
F_12 ( V_16 , L_38 , * V_3 ) ;
break;
}
case V_136 :
{
unsigned int * V_3 = V_119 ;
if ( ! V_88 -> V_266 )
break;
F_12 ( V_16 , L_38 , * V_3 ) ;
V_127 = V_88 -> V_266 ( V_118 , V_121 , * V_3 ) ;
break;
}
case V_267 :
{
struct V_268 * V_26 = V_119 ;
if ( V_124 && V_124 -> V_269 )
V_127 = V_268 ( V_124 -> V_269 , V_26 ) ;
else if ( V_24 -> V_269 )
V_127 = V_268 ( V_24 -> V_269 , V_26 ) ;
else if ( V_88 -> V_270 )
V_127 = V_88 -> V_270 ( V_118 , V_121 , V_26 ) ;
else
break;
if ( ! V_127 )
F_12 ( V_16 , L_50
L_51 ,
V_26 -> V_1 , V_26 -> type , V_26 -> V_14 ,
V_26 -> V_271 , V_26 -> V_272 ,
V_26 -> V_273 , V_26 -> V_274 , V_26 -> V_37 ) ;
else
F_12 ( V_16 , L_52 , V_26 -> V_1 ) ;
break;
}
case V_275 :
{
struct V_276 * V_26 = V_119 ;
if ( V_124 && V_124 -> V_269 )
V_127 = F_34 ( V_124 -> V_269 , V_26 ) ;
else if ( V_24 -> V_269 )
V_127 = F_34 ( V_24 -> V_269 , V_26 ) ;
else if ( V_88 -> V_277 )
V_127 = V_88 -> V_277 ( V_118 , V_121 , V_26 ) ;
else if ( V_88 -> V_278 ) {
struct V_71 V_279 ;
struct V_280 V_281 ;
V_279 . V_77 = F_21 ( V_26 -> V_1 ) ;
V_279 . V_78 = 1 ;
V_279 . V_79 = & V_281 ;
V_281 . V_1 = V_26 -> V_1 ;
V_281 . V_81 = V_26 -> V_81 ;
if ( F_20 ( & V_279 , 1 ) ) {
V_127 = V_88 -> V_278 ( V_118 , V_121 , & V_279 ) ;
if ( V_127 == 0 )
V_26 -> V_81 = V_281 . V_81 ;
}
} else
break;
if ( ! V_127 )
F_12 ( V_16 , L_53 , V_26 -> V_1 , V_26 -> V_81 ) ;
else
F_12 ( V_16 , L_52 , V_26 -> V_1 ) ;
break;
}
case V_133 :
{
struct V_276 * V_26 = V_119 ;
struct V_71 V_279 ;
struct V_280 V_281 ;
if ( ! ( V_124 && V_124 -> V_269 ) && ! V_24 -> V_269 &&
! V_88 -> V_282 && ! V_88 -> V_283 )
break;
F_12 ( V_16 , L_53 , V_26 -> V_1 , V_26 -> V_81 ) ;
if ( V_124 && V_124 -> V_269 ) {
V_127 = F_35 ( V_124 , V_124 -> V_269 , V_26 ) ;
break;
}
if ( V_24 -> V_269 ) {
V_127 = F_35 ( NULL , V_24 -> V_269 , V_26 ) ;
break;
}
if ( V_88 -> V_282 ) {
V_127 = V_88 -> V_282 ( V_118 , V_121 , V_26 ) ;
break;
}
if ( ! V_88 -> V_283 )
break;
V_279 . V_77 = F_21 ( V_26 -> V_1 ) ;
V_279 . V_78 = 1 ;
V_279 . V_79 = & V_281 ;
V_281 . V_1 = V_26 -> V_1 ;
V_281 . V_81 = V_26 -> V_81 ;
if ( F_20 ( & V_279 , 1 ) )
V_127 = V_88 -> V_283 ( V_118 , V_121 , & V_279 ) ;
break;
}
case V_284 :
{
struct V_71 * V_26 = V_119 ;
V_26 -> V_86 = V_26 -> V_78 ;
if ( V_124 && V_124 -> V_269 )
V_127 = F_36 ( V_124 -> V_269 , V_26 ) ;
else if ( V_24 -> V_269 )
V_127 = F_36 ( V_24 -> V_269 , V_26 ) ;
else if ( V_88 -> V_278 && F_20 ( V_26 , 0 ) )
V_127 = V_88 -> V_278 ( V_118 , V_121 , V_26 ) ;
else
break;
F_19 ( V_16 , V_24 , V_26 , ! V_127 ) ;
break;
}
case V_143 :
{
struct V_71 * V_26 = V_119 ;
V_26 -> V_86 = V_26 -> V_78 ;
if ( ! ( V_124 && V_124 -> V_269 ) && ! V_24 -> V_269 &&
! V_88 -> V_283 )
break;
F_19 ( V_16 , V_24 , V_26 , 1 ) ;
if ( V_124 && V_124 -> V_269 )
V_127 = F_37 ( V_124 , V_124 -> V_269 , V_26 ) ;
else if ( V_24 -> V_269 )
V_127 = F_37 ( NULL , V_24 -> V_269 , V_26 ) ;
else if ( F_20 ( V_26 , 0 ) )
V_127 = V_88 -> V_283 ( V_118 , V_121 , V_26 ) ;
break;
}
case V_285 :
{
struct V_71 * V_26 = V_119 ;
V_26 -> V_86 = V_26 -> V_78 ;
if ( ! ( V_124 && V_124 -> V_269 ) && ! V_24 -> V_269 &&
! V_88 -> V_286 )
break;
F_19 ( V_16 , V_24 , V_26 , 1 ) ;
if ( V_124 && V_124 -> V_269 )
V_127 = F_38 ( V_124 -> V_269 , V_26 ) ;
else if ( V_24 -> V_269 )
V_127 = F_38 ( V_24 -> V_269 , V_26 ) ;
else if ( F_20 ( V_26 , 0 ) )
V_127 = V_88 -> V_286 ( V_118 , V_121 , V_26 ) ;
break;
}
case V_287 :
{
struct V_288 * V_26 = V_119 ;
if ( V_124 && V_124 -> V_269 )
V_127 = V_288 ( V_124 -> V_269 , V_26 ) ;
else if ( V_24 -> V_269 )
V_127 = V_288 ( V_24 -> V_269 , V_26 ) ;
else if ( V_88 -> V_289 )
V_127 = V_88 -> V_289 ( V_118 , V_121 , V_26 ) ;
else
break;
if ( ! V_127 )
F_12 ( V_16 , L_54 ,
V_26 -> V_1 , V_26 -> V_35 , V_26 -> V_14 ) ;
else
F_12 ( V_16 , L_55 ,
V_26 -> V_1 , V_26 -> V_35 ) ;
break;
}
case V_290 :
{
struct V_291 * V_26 = V_119 ;
if ( ! V_88 -> V_292 )
break;
V_127 = V_88 -> V_292 ( V_118 , V_121 , V_26 ) ;
if ( ! V_127 )
F_12 ( V_16 , L_56
L_57 , V_26 -> V_35 , V_26 -> V_14 ,
V_26 -> V_224 , V_26 -> V_293 ) ;
else
F_12 ( V_16 , L_58 , V_26 -> V_35 ) ;
break;
}
case V_294 :
{
struct V_291 * V_26 = V_119 ;
if ( ! V_88 -> V_295 )
break;
V_127 = V_88 -> V_295 ( V_118 , V_121 , V_26 ) ;
if ( ! V_127 )
F_12 ( V_16 , L_56
L_57 , V_26 -> V_35 ,
V_26 -> V_14 , V_26 -> V_224 , V_26 -> V_293 ) ;
else
F_12 ( V_16 , L_58 , V_26 -> V_35 ) ;
break;
}
case V_141 :
{
struct V_291 * V_26 = V_119 ;
if ( ! V_88 -> V_296 )
break;
F_12 ( V_16 , L_56
L_57 , V_26 -> V_35 , V_26 -> V_14 ,
V_26 -> V_224 , V_26 -> V_293 ) ;
V_127 = V_88 -> V_296 ( V_118 , V_121 , V_26 ) ;
break;
}
case V_297 :
{
struct V_298 * V_26 = V_119 ;
if ( ! V_88 -> V_299 )
break;
F_12 ( V_16 , L_59 , V_26 -> V_35 ) ;
V_127 = V_88 -> V_299 ( V_118 , V_121 , V_26 ) ;
if ( ! V_127 )
F_15 ( L_60
L_61 , V_26 -> V_35 , V_26 -> V_14 ,
V_26 -> V_224 , V_26 -> V_293 ) ;
break;
}
case V_300 :
{
struct V_298 * V_26 = V_119 ;
if ( ! V_88 -> V_301 )
break;
V_127 = V_88 -> V_301 ( V_118 , V_121 , V_26 ) ;
if ( ! V_127 )
F_15 ( L_60
L_61 , V_26 -> V_35 , V_26 -> V_14 ,
V_26 -> V_224 , V_26 -> V_293 ) ;
break;
}
case V_142 :
{
struct V_298 * V_26 = V_119 ;
if ( ! V_88 -> V_302 )
break;
F_12 ( V_16 , L_60
L_61 , V_26 -> V_35 , V_26 -> V_14 ,
V_26 -> V_224 , V_26 -> V_293 ) ;
V_127 = V_88 -> V_302 ( V_118 , V_121 , V_26 ) ;
break;
}
case V_303 :
{
struct V_304 * V_26 = V_119 ;
if ( ! V_88 -> V_305 )
break;
V_127 = V_88 -> V_305 ( V_118 , V_121 , V_26 ) ;
if ( ! V_127 )
F_12 ( V_16 , L_62
L_63
L_64 ,
V_26 -> V_35 , V_26 -> V_14 , V_26 -> V_224 ,
V_26 -> V_306 , V_26 -> V_307 ,
V_26 -> V_308 ) ;
break;
}
case V_149 :
{
struct V_304 * V_26 = V_119 ;
if ( ! V_88 -> V_309 )
break;
F_12 ( V_16 , L_60
L_65 ,
V_26 -> V_35 , V_26 -> V_14 , V_26 -> V_224 , V_26 -> V_306 ,
V_26 -> V_307 , V_26 -> V_308 ) ;
V_127 = V_88 -> V_309 ( V_118 , V_121 , V_26 ) ;
break;
}
case V_310 :
{
struct V_311 * V_26 = V_119 ;
if ( ! V_88 -> V_312 )
break;
F_12 ( V_16 , L_36 , F_13 ( V_26 -> type , V_36 ) ) ;
V_127 = V_88 -> V_312 ( V_118 , V_121 , V_26 ) ;
if ( ! V_127 )
F_16 ( V_24 , L_23 , & V_26 -> V_72 ) ;
break;
}
case V_140 :
{
struct V_311 * V_26 = V_119 ;
if ( ! V_88 -> V_313 )
break;
F_12 ( V_16 , L_36 , F_13 ( V_26 -> type , V_36 ) ) ;
F_16 ( V_24 , L_23 , & V_26 -> V_72 ) ;
V_127 = V_88 -> V_313 ( V_118 , V_121 , V_26 ) ;
break;
}
case V_314 :
{
struct V_315 * V_26 = V_119 ;
if ( ! V_88 -> V_316 )
break;
F_12 ( V_16 , L_36 , F_13 ( V_26 -> type , V_36 ) ) ;
V_127 = V_88 -> V_316 ( V_118 , V_121 , V_26 ) ;
if ( ! V_127 ) {
F_16 ( V_24 , L_66 , & V_26 -> V_317 ) ;
F_16 ( V_24 , L_67 , & V_26 -> V_318 ) ;
}
break;
}
case V_319 :
{
struct V_320 * V_26 = V_119 ;
if ( ! V_88 -> V_321 )
break;
V_127 = V_88 -> V_321 ( V_118 , V_121 , V_26 ) ;
if ( ! V_127 )
F_12 ( V_16 , L_68
L_69
L_70 ,
V_26 -> V_322 , V_26 -> V_323 , V_26 -> V_324 ,
V_26 -> V_325 , V_26 -> V_326 ) ;
break;
}
case V_148 :
{
struct V_320 * V_26 = V_119 ;
if ( ! V_88 -> V_321 )
break;
F_12 ( V_16 , L_71
L_72 ,
V_26 -> V_322 , V_26 -> V_323 , V_26 -> V_324 ,
V_26 -> V_325 , V_26 -> V_326 ) ;
V_127 = V_88 -> V_327 ( V_118 , V_121 , V_26 ) ;
break;
}
case V_328 :
{
struct V_329 * V_26 = V_119 ;
if ( ! V_88 -> V_330 )
break;
V_127 = V_88 -> V_330 ( V_118 , V_121 , V_26 ) ;
if ( ! V_127 )
F_12 ( V_16 , L_73 ,
V_26 -> V_331 , V_26 -> V_332 ) ;
break;
}
case V_152 :
{
struct V_333 * V_26 = V_119 ;
if ( ! V_88 -> V_334 )
break;
V_127 = V_88 -> V_334 ( V_118 , V_121 , V_26 ) ;
if ( ! V_127 )
F_12 ( V_16 , L_74 , V_26 -> V_16 , V_26 -> V_37 ) ;
break;
}
case V_335 :
{
struct V_333 * V_26 = V_119 ;
if ( ! V_88 -> V_336 )
break;
V_127 = V_88 -> V_336 ( V_118 , V_121 , V_26 ) ;
if ( ! V_127 )
F_12 ( V_16 , L_74 , V_26 -> V_16 , V_26 -> V_37 ) ;
break;
}
case V_337 :
{
struct V_338 * V_26 = V_119 ;
if ( V_88 -> V_339 ) {
V_127 = F_22 ( V_88 , V_26 -> type ) ;
if ( V_127 )
break;
V_127 = V_88 -> V_339 ( V_118 , V_121 , V_26 ) ;
} else {
T_1 V_5 = V_24 -> V_238 ;
if ( V_26 -> type != V_91 )
break;
V_127 = 0 ;
if ( V_88 -> V_237 )
V_127 = V_88 -> V_237 ( V_118 , V_121 , & V_5 ) ;
else if ( V_5 == 0 )
V_127 = - V_90 ;
if ( V_127 == 0 )
F_3 ( V_5 ,
& V_26 -> V_340 . V_341 . V_342 ) ;
}
F_12 ( V_16 , L_75 , V_26 -> type ) ;
break;
}
case V_150 :
{
struct V_338 * V_26 = V_119 ;
if ( ! V_88 -> V_343 )
break;
V_127 = F_22 ( V_88 , V_26 -> type ) ;
if ( V_127 )
break;
F_12 ( V_16 , L_75 , V_26 -> type ) ;
V_127 = V_88 -> V_343 ( V_118 , V_121 , V_26 ) ;
break;
}
case V_344 :
{
struct V_345 * V_26 = V_119 ;
if ( ! V_88 -> V_346 )
break;
V_26 -> type = ( V_24 -> V_347 == V_348 ) ?
V_349 : V_350 ;
V_127 = V_88 -> V_346 ( V_118 , V_121 , V_26 ) ;
if ( ! V_127 )
F_12 ( V_16 , L_45
L_76
L_77
L_78 ,
V_26 -> V_35 , V_26 -> V_14 , V_26 -> type ,
V_26 -> V_224 , V_26 -> V_306 ,
V_26 -> V_307 , V_26 -> signal , V_26 -> V_351 ,
V_26 -> V_352 , V_26 -> V_353 ) ;
break;
}
case V_137 :
{
struct V_345 * V_26 = V_119 ;
if ( ! V_88 -> V_354 )
break;
V_26 -> type = ( V_24 -> V_347 == V_348 ) ?
V_349 : V_350 ;
F_12 ( V_16 , L_45
L_76
L_77
L_78 ,
V_26 -> V_35 , V_26 -> V_14 , V_26 -> type ,
V_26 -> V_224 , V_26 -> V_306 ,
V_26 -> V_307 , V_26 -> signal , V_26 -> V_351 ,
V_26 -> V_352 , V_26 -> V_353 ) ;
V_127 = V_88 -> V_354 ( V_118 , V_121 , V_26 ) ;
break;
}
case V_355 :
{
struct V_356 * V_26 = V_119 ;
if ( ! V_88 -> V_357 )
break;
V_26 -> type = ( V_24 -> V_347 == V_348 ) ?
V_349 : V_350 ;
V_127 = V_88 -> V_357 ( V_118 , V_121 , V_26 ) ;
if ( ! V_127 )
F_12 ( V_16 , L_79 ,
V_26 -> V_252 , V_26 -> type , V_26 -> V_358 ) ;
break;
}
case V_138 :
{
struct V_356 * V_26 = V_119 ;
if ( ! V_88 -> V_359 )
break;
F_12 ( V_16 , L_79 ,
V_26 -> V_252 , V_26 -> type , V_26 -> V_358 ) ;
V_127 = V_88 -> V_359 ( V_118 , V_121 , V_26 ) ;
break;
}
case V_360 :
{
struct V_361 * V_26 = V_119 ;
if ( ! V_88 -> V_362 )
break;
memset ( V_26 , 0 , F_39 ( struct V_361 , type ) ) ;
F_12 ( V_16 , L_36 , F_13 ( V_26 -> type , V_36 ) ) ;
V_127 = V_88 -> V_362 ( V_118 , V_121 , V_26 ) ;
if ( ! V_127 )
F_15 ( L_80 , V_26 -> V_363 ) ;
break;
}
case V_364 :
{
if ( ! V_88 -> V_365 )
break;
V_127 = V_88 -> V_365 ( V_118 , V_121 ) ;
break;
}
#ifdef F_40
case V_366 :
{
struct V_367 * V_26 = V_119 ;
if ( V_88 -> V_368 ) {
if ( ! F_41 ( V_369 ) )
V_127 = - V_370 ;
else
V_127 = V_88 -> V_368 ( V_118 , V_121 , V_26 ) ;
}
break;
}
case V_371 :
{
struct V_367 * V_26 = V_119 ;
if ( V_88 -> V_372 ) {
if ( ! F_41 ( V_369 ) )
V_127 = - V_370 ;
else
V_127 = V_88 -> V_372 ( V_118 , V_121 , V_26 ) ;
}
break;
}
#endif
case V_373 :
{
struct V_374 * V_26 = V_119 ;
if ( ! V_88 -> V_375 )
break;
V_26 -> V_376 = V_377 ;
V_26 -> V_378 = 0 ;
V_127 = V_88 -> V_375 ( V_118 , V_121 , V_26 ) ;
if ( ! V_127 )
F_12 ( V_16 , L_81 , V_26 -> V_376 , V_26 -> V_378 ) ;
break;
}
case V_151 :
{
struct V_379 * V_26 = V_119 ;
enum V_380 type ;
if ( ! V_88 -> V_381 )
break;
type = ( V_24 -> V_347 == V_348 ) ?
V_349 : V_350 ;
F_12 ( V_16 ,
L_82 ,
V_26 -> V_252 , V_26 -> type , V_26 -> V_382 , V_26 -> V_383 , V_26 -> V_384 ) ;
if ( V_26 -> type != type )
V_127 = - V_90 ;
else
V_127 = V_88 -> V_381 ( V_118 , V_121 , V_26 ) ;
break;
}
case V_385 :
{
struct V_386 * V_26 = V_119 ;
if ( ! V_88 -> V_387 )
break;
V_127 = V_88 -> V_387 ( V_118 , V_121 , V_26 ) ;
F_12 ( V_16 ,
L_83 ,
V_26 -> V_35 ,
( V_26 -> V_388 & 0xff ) ,
( V_26 -> V_388 >> 8 ) & 0xff ,
( V_26 -> V_388 >> 16 ) & 0xff ,
( V_26 -> V_388 >> 24 ) & 0xff ,
V_26 -> type ) ;
switch ( V_26 -> type ) {
case V_389 :
F_42 ( L_84 ,
V_26 -> V_390 . V_59 , V_26 -> V_390 . V_60 ) ;
break;
case V_391 :
F_42 ( L_85 ,
V_26 -> V_392 . V_393 , V_26 -> V_392 . V_394 ,
V_26 -> V_392 . V_395 , V_26 -> V_392 . V_396 ,
V_26 -> V_392 . V_397 , V_26 -> V_392 . V_398 ) ;
break;
case V_399 :
F_42 ( L_86 ) ;
break;
default:
F_42 ( L_87 ) ;
}
break;
}
case V_400 :
{
struct V_401 * V_26 = V_119 ;
if ( ! V_88 -> V_402 )
break;
V_127 = V_88 -> V_402 ( V_118 , V_121 , V_26 ) ;
F_12 ( V_16 ,
L_88 ,
V_26 -> V_35 , V_26 -> V_388 ,
V_26 -> V_59 , V_26 -> V_60 , V_26 -> type ) ;
switch ( V_26 -> type ) {
case V_403 :
F_15 ( L_89 ,
V_26 -> V_390 . V_10 ,
V_26 -> V_390 . V_11 ) ;
break;
case V_404 :
F_15 ( L_90 ,
V_26 -> V_392 . V_405 . V_10 ,
V_26 -> V_392 . V_405 . V_11 ,
V_26 -> V_392 . V_406 . V_10 ,
V_26 -> V_392 . V_406 . V_11 ,
V_26 -> V_392 . V_273 . V_10 ,
V_26 -> V_392 . V_273 . V_11 ) ;
break;
case V_407 :
F_15 ( L_86 ) ;
break;
default:
F_15 ( L_87 ) ;
}
break;
}
case V_408 :
{
struct V_409 * V_26 = V_119 ;
if ( ! V_88 -> V_410 )
break;
V_127 = V_88 -> V_410 ( V_118 , V_121 , V_26 ) ;
if ( ! V_127 )
F_12 ( V_16 ,
L_91
L_92 ,
V_26 -> V_35 , V_26 -> V_411 , V_26 -> V_14 , V_26 -> V_59 ,
V_26 -> V_60 ) ;
break;
}
case V_146 :
{
struct V_412 * V_26 = V_119 ;
if ( ! V_88 -> V_246 )
break;
F_12 ( V_16 , L_93 , V_26 -> V_411 ) ;
V_127 = V_88 -> V_246 ( V_118 , V_121 , V_26 ) ;
break;
}
case V_413 :
{
struct V_412 * V_26 = V_119 ;
if ( ! V_88 -> V_414 )
break;
V_127 = V_88 -> V_414 ( V_118 , V_121 , V_26 ) ;
if ( ! V_127 )
F_12 ( V_16 , L_93 , V_26 -> V_411 ) ;
break;
}
case V_415 :
{
struct V_412 * V_26 = V_119 ;
if ( ! V_88 -> V_416 )
break;
V_127 = V_88 -> V_416 ( V_118 , V_121 , V_26 ) ;
if ( ! V_127 )
F_12 ( V_16 , L_93 , V_26 -> V_411 ) ;
break;
}
case V_147 :
{
struct V_417 * V_26 = V_119 ;
if ( ! V_88 -> V_248 )
break;
switch ( V_26 -> type ) {
case V_418 :
F_15 ( L_94
L_95
L_96
L_97
L_98
L_99 ,
V_26 -> V_419 . V_420 , V_26 -> V_419 . V_421 ,
V_26 -> V_419 . V_59 , V_26 -> V_419 . V_60 , V_26 -> V_419 . V_422 ,
V_26 -> V_419 . V_423 , V_26 -> V_419 . V_424 ,
V_26 -> V_419 . V_425 , V_26 -> V_419 . V_426 ,
V_26 -> V_419 . V_427 , V_26 -> V_419 . V_428 ,
V_26 -> V_419 . V_429 , V_26 -> V_419 . V_430 ,
V_26 -> V_419 . V_431 ) ;
V_127 = V_88 -> V_248 ( V_118 , V_121 , V_26 ) ;
break;
default:
F_15 ( L_100 , V_26 -> type ) ;
break;
}
break;
}
case V_432 :
{
struct V_417 * V_26 = V_119 ;
if ( ! V_88 -> V_433 )
break;
V_127 = V_88 -> V_433 ( V_118 , V_121 , V_26 ) ;
if ( ! V_127 ) {
switch ( V_26 -> type ) {
case V_418 :
F_15 ( L_101
L_102
L_95
L_103
L_104
L_105
L_98
L_99 ,
V_26 -> V_419 . V_420 , V_26 -> V_419 . V_421 ,
V_26 -> V_419 . V_59 , V_26 -> V_419 . V_60 ,
V_26 -> V_419 . V_422 , V_26 -> V_419 . V_423 ,
V_26 -> V_419 . V_424 , V_26 -> V_419 . V_425 ,
V_26 -> V_419 . V_426 , V_26 -> V_419 . V_427 ,
V_26 -> V_419 . V_428 , V_26 -> V_419 . V_429 ,
V_26 -> V_419 . V_430 , V_26 -> V_419 . V_431 ) ;
break;
default:
F_15 ( L_100 , V_26 -> type ) ;
break;
}
}
break;
}
case V_434 :
{
struct V_435 * V_436 = V_119 ;
if ( ! V_88 -> V_437 )
break;
V_127 = F_43 ( V_121 , V_436 , V_118 -> V_438 & V_439 ) ;
if ( V_127 < 0 ) {
F_12 ( V_16 , L_106 ) ;
break;
}
F_12 ( V_16 ,
L_107
L_108 ,
V_436 -> V_440 , V_436 -> type , V_436 -> V_39 ,
V_436 -> V_32 . V_33 , V_436 -> V_32 . V_441 ) ;
break;
}
case V_442 :
{
struct V_443 * V_444 = V_119 ;
if ( ! V_88 -> V_437 )
break;
V_127 = V_88 -> V_437 ( V_121 , V_444 ) ;
if ( V_127 < 0 ) {
F_12 ( V_16 , L_109 , V_127 ) ;
break;
}
F_12 ( V_16 , L_110 , V_444 -> type ) ;
break;
}
case V_445 :
{
struct V_443 * V_444 = V_119 ;
if ( ! V_88 -> V_446 )
break;
V_127 = V_88 -> V_446 ( V_121 , V_444 ) ;
if ( V_127 < 0 ) {
F_12 ( V_16 , L_109 , V_127 ) ;
break;
}
F_12 ( V_16 , L_110 , V_444 -> type ) ;
break;
}
default:
{
bool V_447 = true ;
if ( ! V_88 -> V_448 )
break;
if ( V_126 )
V_447 = F_29 ( V_24 -> V_157 , V_124 -> V_157 ) >= 0 ;
V_127 = V_88 -> V_448 ( V_118 , V_121 , V_447 , V_16 , V_119 ) ;
break;
}
}
V_158:
if ( V_24 -> V_74 & V_75 ) {
if ( V_127 < 0 ) {
F_27 ( V_24 -> V_14 , V_16 ) ;
F_9 ( V_76 L_111 , V_127 ) ;
}
}
return V_127 ;
}
static unsigned long F_44 ( unsigned int V_16 )
{
#define F_45 ( V_16 , type , V_38 ) \
case VIDIOC_##cmd: \
return offsetof(struct v4l2_##type, field) + \
sizeof(((struct v4l2_##type *)0)->field);
switch ( V_16 ) {
F_45 ( V_449 , V_450 , type ) ;
F_45 ( V_451 , V_452 , type ) ;
F_45 ( V_453 , V_454 , V_44 ) ;
F_45 ( V_455 , V_456 , type ) ;
F_45 ( V_457 , V_458 , V_35 ) ;
F_45 ( V_459 , V_460 , V_35 ) ;
F_45 ( V_461 , V_462 , V_1 ) ;
F_45 ( V_463 , V_252 , V_35 ) ;
F_45 ( V_464 , V_465 , V_1 ) ;
F_45 ( V_466 , V_467 , V_35 ) ;
F_45 ( V_468 , V_469 , V_35 ) ;
F_45 ( V_470 , V_263 , V_35 ) ;
F_45 ( V_471 , V_358 , V_252 ) ;
F_45 ( V_472 , V_473 , type ) ;
F_45 ( V_474 , V_475 , type ) ;
F_45 ( V_476 , V_477 , V_35 ) ;
F_45 ( V_478 , V_479 , V_35 ) ;
F_45 ( V_480 , V_481 , V_37 ) ;
F_45 ( V_482 , V_481 , V_37 ) ;
F_45 ( V_483 , V_484 , type ) ;
F_45 ( V_485 , V_486 , V_388 ) ;
F_45 ( V_487 , V_488 , V_60 ) ;
default:
return F_46 ( V_16 ) ;
}
}
static int F_47 ( unsigned int V_16 , void * V_489 , T_3 * V_490 ,
void * T_4 * V_491 , void * * * V_492 )
{
int V_127 = 0 ;
switch ( V_16 ) {
case V_214 :
case V_216 :
case V_218 : {
struct V_25 * V_493 = V_489 ;
if ( F_14 ( V_493 -> type ) && V_493 -> V_44 > 0 ) {
if ( V_493 -> V_44 > V_494 ) {
V_127 = - V_90 ;
break;
}
* V_491 = ( void T_4 * ) V_493 -> V_42 . V_43 ;
* V_492 = ( void * ) & V_493 -> V_42 . V_43 ;
* V_490 = sizeof( struct V_30 ) * V_493 -> V_44 ;
V_127 = 1 ;
}
break;
}
case V_143 :
case V_284 :
case V_285 : {
struct V_71 * V_279 = V_489 ;
if ( V_279 -> V_78 != 0 ) {
* V_491 = ( void T_4 * ) V_279 -> V_79 ;
* V_492 = ( void * ) & V_279 -> V_79 ;
* V_490 = sizeof( struct V_280 )
* V_279 -> V_78 ;
V_127 = 1 ;
}
break;
}
}
return V_127 ;
}
long
F_48 ( struct V_118 * V_118 , unsigned int V_16 , unsigned long V_119 ,
T_5 V_495 )
{
char V_496 [ 128 ] ;
void * V_497 = NULL ;
void * V_489 = ( void * ) V_119 ;
long V_498 = - V_90 ;
bool V_499 ;
T_3 V_490 = 0 ;
void T_4 * V_491 = NULL ;
void * * V_492 = NULL ;
if ( F_10 ( V_16 ) != V_20 ) {
if ( F_46 ( V_16 ) <= sizeof( V_496 ) ) {
V_489 = V_496 ;
} else {
V_497 = F_49 ( F_46 ( V_16 ) , V_500 ) ;
if ( NULL == V_497 )
return - V_501 ;
V_489 = V_497 ;
}
V_498 = - V_502 ;
if ( F_10 ( V_16 ) & V_22 ) {
unsigned long V_503 = F_44 ( V_16 ) ;
if ( F_50 ( V_489 , ( void T_4 * ) V_119 , V_503 ) )
goto V_504;
if ( V_503 < F_46 ( V_16 ) )
memset ( ( V_505 * ) V_489 + V_503 , 0 , F_46 ( V_16 ) - V_503 ) ;
} else {
memset ( V_489 , 0 , F_46 ( V_16 ) ) ;
}
}
V_498 = F_47 ( V_16 , V_489 , & V_490 , & V_491 , & V_492 ) ;
if ( V_498 < 0 )
goto V_504;
V_499 = V_498 ;
if ( V_499 ) {
V_497 = F_49 ( V_490 , V_500 ) ;
V_498 = - V_501 ;
if ( NULL == V_497 )
goto V_506;
V_498 = - V_502 ;
if ( F_50 ( V_497 , V_491 , V_490 ) )
goto V_506;
* V_492 = V_497 ;
}
V_498 = V_495 ( V_118 , V_16 , V_489 ) ;
if ( V_498 == - V_507 )
V_498 = - V_90 ;
if ( V_499 ) {
* V_492 = V_491 ;
if ( F_51 ( V_491 , V_497 , V_490 ) )
V_498 = - V_502 ;
goto V_506;
}
if ( V_498 < 0 )
goto V_504;
V_506:
switch ( F_10 ( V_16 ) ) {
case V_21 :
case ( V_22 | V_21 ) :
if ( F_51 ( ( void T_4 * ) V_119 , V_489 , F_46 ( V_16 ) ) )
V_498 = - V_502 ;
break;
}
V_504:
F_52 ( V_497 ) ;
return V_498 ;
}
long F_53 ( struct V_118 * V_118 ,
unsigned int V_16 , unsigned long V_119 )
{
return F_48 ( V_118 , V_16 , V_119 , F_25 ) ;
}
