static inline T_1 F_1 ( T_1 V_1 )
{
return ( V_1 & V_2 ) >> V_3 ;
}
static inline T_1 F_2 ( T_1 V_1 )
{
return ( V_1 & V_4 ) >> V_5 ;
}
static inline T_1 F_3 ( T_1 V_1 )
{
return ( V_1 & V_6 ) >> V_7 ;
}
static inline T_1 F_4 ( T_1 V_1 )
{
return ( V_1 & V_8 ) >> V_9 ;
}
static inline T_1 F_5 ( T_1 V_1 )
{
return ( V_1 & V_10 ) >> V_11 ;
}
static inline T_1 F_6 ( T_1 V_1 )
{
return ( V_1 & V_8 ) >> V_9 ;
}
static inline T_1 F_7 ( T_1 V_1 )
{
return ( V_1 & V_12 ) >> V_13 ;
}
static inline T_1 F_8 ( T_1 V_1 )
{
return ( V_1 & V_14 ) >> V_15 ;
}
T_1 F_9 ( enum V_16 V_17 )
{
switch ( V_17 ) {
case V_18 :
return ( 0xFFFFFFF0 | V_19 ) ;
case V_20 :
return ( 0xFFFFFF00 | V_21
| ( V_22 << 4 ) ) ;
case V_23 :
return ( 0xFFFFF000 | V_21
| ( V_22 << 4 )
| ( V_24 << 8 ) ) ;
case V_25 :
return ( 0xFFFFF000 | V_21
| ( V_19 << 4 )
| ( V_22 << 8 ) ) ;
case V_26 :
return ( 0xFFFF0000 | V_21
| ( V_19 << 4 )
| ( V_22 << 8 )
| ( V_24 << 12 ) ) ;
case V_27 :
return ( 0xFFFF0000 | V_21
| ( V_22 << 4 )
| ( V_28 << 8 )
| ( V_29 << 12 ) ) ;
case V_30 :
return ( 0xFFFF0000 | V_21
| ( V_19 << 4 )
| ( V_22 << 8 )
| ( V_31 << 12 ) ) ;
case V_32 :
return ( 0xFFF00000 | V_21
| ( V_19 << 4 )
| ( V_22 << 8 )
| ( V_28 << 12 )
| ( V_29 << 16 ) ) ;
case V_33 :
return ( 0xFF000000 | V_19
| ( V_21 << 4 )
| ( V_22 << 8 )
| ( V_28 << 12 )
| ( V_29 << 16 )
| ( V_24 << 20 ) ) ;
case V_34 :
return ( 0xFFFFFF00 | V_21
| ( V_21 << 4 ) ) ;
default:
return 0xFFFFFFFF ;
}
}
static struct V_35 * F_10 ( struct V_36 * V_37 ,
int V_38 )
{
struct V_35 * V_39 ;
F_11 (stream, &hsw->stream_list, node) {
if ( V_39 -> V_40 . V_41 == V_38 )
return V_39 ;
}
return NULL ;
}
static void F_12 ( struct V_36 * V_37 , T_1 V_42 )
{
struct V_43 V_44 ;
T_1 V_45 ;
T_2 V_46 [ V_47 - 5 * sizeof( T_1 ) ] ;
char * V_48 [ 5 ] , * V_49 ;
int V_50 = 0 ;
V_45 = ( V_42 & 0x1FFFFFFF ) << 3 ;
F_13 ( V_37 -> V_51 , L_1 ,
V_42 , V_45 ) ;
F_14 ( V_37 -> V_52 , & V_44 , V_45 , sizeof( V_44 ) ) ;
F_15 ( V_37 -> V_52 , V_44 . V_53 ,
V_44 . V_54 , V_44 . V_55 ,
V_44 . V_56 ) ;
V_37 -> V_57 = true ;
F_16 ( & V_37 -> V_58 ) ;
F_13 ( V_37 -> V_51 , L_2 ,
V_44 . V_53 , V_44 . V_54 ) ;
F_13 ( V_37 -> V_51 , L_3 ,
V_44 . V_55 , V_44 . V_56 ) ;
if ( V_44 . V_59 < sizeof( V_44 . V_46 ) ) {
V_44 . V_46 [ V_44 . V_59 ] = 0 ;
F_13 ( V_37 -> V_51 , L_4 , V_44 . V_46 ) ;
memcpy ( V_46 , V_44 . V_46 , V_44 . V_59 ) ;
V_49 = & V_46 [ 0 ] ;
for ( V_50 = 0 ; V_50 < F_17 ( V_48 ) ; V_50 ++ )
V_48 [ V_50 ] = F_18 ( & V_49 , L_5 ) ;
F_19 ( V_37 -> V_51 , L_6
L_7 ,
V_48 [ 0 ] , V_48 [ 1 ] , V_48 [ 2 ] , V_48 [ 3 ] , V_48 [ 4 ] ) ;
}
}
static void F_20 ( struct V_60 * V_61 )
{
struct V_35 * V_39 = F_21 ( V_61 ,
struct V_35 , V_62 ) ;
struct V_63 * V_64 = & V_39 -> V_64 ;
struct V_65 * V_66 = & V_39 -> V_67 ;
struct V_36 * V_37 = V_39 -> V_37 ;
T_1 V_68 ;
V_68 = F_6 ( V_39 -> V_42 ) ;
switch ( V_68 ) {
case V_69 :
F_22 ( L_8 ,
V_39 -> V_40 . V_41 ) ;
F_23 ( V_37 -> V_52 , V_64 , sizeof( * V_64 ) ) ;
F_24 ( V_37 -> V_51 , L_9 ,
V_64 -> V_70 , V_64 -> V_71 ,
V_64 -> V_72 ) ;
break;
case V_73 :
F_22 ( L_10 ,
V_39 -> V_40 . V_41 ) ;
F_23 ( V_37 -> V_52 , V_66 , sizeof( * V_66 ) ) ;
if ( V_39 -> V_74 )
V_39 -> V_74 ( V_39 , V_39 -> V_75 ) ;
break;
default:
F_24 ( V_37 -> V_51 , L_11 ,
V_39 -> V_42 ) ;
break;
}
F_25 ( V_37 -> V_52 , V_76 ,
V_77 | V_78 , V_78 ) ;
F_25 ( V_37 -> V_52 , V_79 , V_80 , 0 ) ;
}
static void F_26 ( struct V_36 * V_37 , struct V_81 * V_1 )
{
struct V_35 * V_39 ;
T_1 V_42 = V_1 -> V_42 & ~ ( V_82 | V_4 ) ;
T_1 V_38 = F_5 ( V_42 ) ;
T_1 V_83 = F_3 ( V_42 ) ;
V_39 = F_10 ( V_37 , V_38 ) ;
if ( V_39 == NULL )
return;
switch ( V_83 ) {
case V_84 :
case V_85 :
break;
case V_86 :
F_22 ( L_12 , V_39 -> V_40 . V_41 ) ;
break;
case V_87 :
V_39 -> V_88 = false ;
F_22 ( L_13 ,
V_39 -> V_40 . V_41 ) ;
break;
case V_89 :
V_39 -> V_88 = true ;
F_22 ( L_14 ,
V_39 -> V_40 . V_41 ) ;
break;
}
}
static int F_27 ( struct V_36 * V_37 , T_1 V_42 )
{
struct V_81 * V_1 ;
T_1 V_40 = F_2 ( V_42 ) ;
F_28 ( L_15 , V_42 ) ;
V_1 = F_29 ( & V_37 -> V_90 , V_42 ) ;
if ( V_1 == NULL ) {
F_30 ( L_16 , V_42 ) ;
return - V_91 ;
}
switch ( V_40 ) {
case V_92 :
F_31 ( L_17 , V_42 ) ;
V_1 -> V_93 = true ;
V_37 -> V_90 . V_93 = true ;
return 1 ;
case V_94 :
if ( V_1 -> V_93 ) {
F_31 ( L_18 , V_42 ) ;
F_23 ( V_37 -> V_52 , V_1 -> V_95 ,
V_1 -> V_96 ) ;
V_37 -> V_90 . V_93 = false ;
} else {
F_32 ( V_37 -> V_52 , V_1 -> V_95 ,
V_1 -> V_96 ) ;
}
break;
case V_97 :
F_30 ( L_19 , V_42 ) ;
V_1 -> V_98 = - V_99 ;
break;
case V_100 :
F_30 ( L_20 , V_42 ) ;
V_1 -> V_98 = - V_101 ;
break;
case V_102 :
F_30 ( L_21 , V_42 ) ;
V_1 -> V_98 = - V_103 ;
break;
case V_104 :
F_30 ( L_22 , V_42 ) ;
V_1 -> V_98 = - V_105 ;
break;
case V_106 :
F_30 ( L_23 , V_42 ) ;
V_1 -> V_98 = - V_105 ;
break;
case V_107 :
F_30 ( L_24 , V_42 ) ;
V_1 -> V_98 = - V_105 ;
break;
case V_108 :
F_30 ( L_25 , V_42 ) ;
V_1 -> V_98 = - V_105 ;
break;
case V_109 :
F_30 ( L_26 , V_42 ) ;
V_1 -> V_98 = - V_105 ;
break;
case V_110 :
F_30 ( L_27 , V_42 ) ;
V_1 -> V_98 = - V_105 ;
break;
default:
F_30 ( L_28 , V_42 ) ;
V_1 -> V_98 = - V_105 ;
break;
}
if ( F_1 ( V_42 ) == V_111 )
F_26 ( V_37 , V_1 ) ;
F_33 ( & V_1 -> V_112 ) ;
F_34 ( & V_37 -> V_90 , V_1 ) ;
return 1 ;
}
static int F_35 ( struct V_36 * V_37 , T_1 V_42 )
{
T_1 V_113 , V_114 ;
int V_115 = 0 ;
V_113 = F_7 ( V_42 ) ;
V_114 = F_8 ( V_42 ) ;
F_13 ( V_37 -> V_51 , L_29 ,
V_42 ) ;
F_13 ( V_37 -> V_51 , L_30 ,
V_113 , V_114 ) ;
switch ( V_113 ) {
case V_116 :
F_13 ( V_37 -> V_51 , L_31 ) ;
V_115 = 1 ;
break;
default:
V_115 = F_27 ( V_37 , V_42 ) ;
break;
}
return V_115 ;
}
static int F_36 ( struct V_36 * V_37 , T_1 V_42 )
{
T_1 V_83 , V_38 , V_117 ;
struct V_35 * V_39 ;
int V_115 = 0 ;
V_83 = F_3 ( V_42 ) ;
V_38 = F_5 ( V_42 ) ;
V_117 = F_4 ( V_42 ) ;
V_39 = F_10 ( V_37 , V_38 ) ;
if ( V_39 == NULL )
return V_115 ;
V_39 -> V_42 = V_42 ;
switch ( V_83 ) {
case V_84 :
F_24 ( V_37 -> V_51 , L_32 ,
V_42 ) ;
break;
case V_85 :
F_37 ( & V_39 -> V_62 ) ;
break;
default:
V_115 = F_27 ( V_37 , V_42 ) ;
break;
}
return V_115 ;
}
static int F_38 ( struct V_36 * V_37 , T_1 V_42 )
{
T_1 V_113 = ( V_42 & V_118 ) >> V_119 ;
struct V_120 * V_39 = & V_37 -> V_121 ;
int V_122 = 1 ;
if ( V_113 != V_123 ) {
F_24 ( V_37 -> V_51 ,
L_33 , V_42 ) ;
return 0 ;
}
F_39 ( & V_39 -> V_124 ) ;
V_39 -> V_125 = V_39 -> V_126 ;
F_23 (
V_37 -> V_52 , & V_39 -> V_126 , sizeof( V_39 -> V_126 ) ) ;
F_40 ( & V_39 -> V_124 ) ;
F_37 ( & V_39 -> V_62 ) ;
return V_122 ;
}
static int F_41 ( struct V_36 * V_37 )
{
struct V_127 * V_128 = V_37 -> V_52 ;
T_1 type , V_42 ;
int V_115 = 1 ;
V_42 = F_42 ( V_128 , V_76 ) ;
type = F_1 ( V_42 ) ;
F_43 ( L_15 , V_42 ) ;
if ( ! V_37 -> V_57 && V_42 & V_129 ) {
F_12 ( V_37 , V_42 ) ;
return V_115 ;
}
switch ( type ) {
case V_130 :
case V_131 :
case V_132 :
case V_133 :
case V_134 :
case V_135 :
case V_136 :
case V_137 :
case V_138 :
case V_139 :
case V_140 :
case V_141 :
F_24 ( V_37 -> V_51 , L_34 ,
type , V_42 ) ;
break;
case V_111 :
V_115 = F_36 ( V_37 , V_42 ) ;
break;
case V_142 :
V_115 = F_38 ( V_37 , V_42 ) ;
break;
case V_143 :
V_115 = F_35 ( V_37 , V_42 ) ;
break;
default:
F_24 ( V_37 -> V_51 , L_35 ,
type , V_42 ) ;
break;
}
return V_115 ;
}
static T_3 F_44 ( int V_144 , void * V_145 )
{
struct V_127 * V_128 = (struct V_127 * ) V_145 ;
struct V_36 * V_37 = F_45 ( V_128 ) ;
struct V_146 * V_90 = & V_37 -> V_90 ;
T_1 V_147 , V_148 ;
unsigned long V_149 ;
F_46 ( & V_128 -> V_150 , V_149 ) ;
V_147 = F_47 ( V_37 -> V_52 ) ;
V_148 = F_42 ( V_128 , V_76 ) ;
if ( V_147 & V_151 ) {
F_27 ( V_37 , V_147 ) ;
F_48 ( V_128 , V_152 ,
V_151 , 0 ) ;
F_48 ( V_128 , V_79 ,
V_153 , 0 ) ;
}
if ( V_148 & V_77 ) {
F_41 ( V_37 ) ;
F_48 ( V_128 , V_76 ,
V_77 | V_78 , V_78 ) ;
F_48 ( V_128 , V_79 ,
V_80 , 0 ) ;
}
F_49 ( & V_128 -> V_150 , V_149 ) ;
F_37 ( & V_90 -> V_154 ) ;
return V_155 ;
}
int F_50 ( struct V_36 * V_37 ,
struct V_156 * V_157 )
{
int V_122 ;
V_122 = F_51 ( & V_37 -> V_90 ,
F_52 ( V_130 ) ,
NULL , 0 , V_157 , sizeof( * V_157 ) ) ;
if ( V_122 < 0 )
F_24 ( V_37 -> V_51 , L_36 ) ;
return V_122 ;
}
int F_53 ( struct V_36 * V_37 , struct V_35 * V_39 ,
T_1 V_158 , T_1 V_159 , T_1 * V_160 )
{
if ( V_159 > 1 )
return - V_105 ;
F_14 ( V_37 -> V_52 , V_160 ,
V_39 -> V_40 . V_161 [ V_159 ] ,
sizeof( * V_160 ) ) ;
return 0 ;
}
int F_54 ( struct V_36 * V_37 ,
struct V_35 * V_39 , T_1 V_158 , T_1 V_159 , T_1 V_160 )
{
struct V_162 * V_163 ;
T_1 V_42 ;
int V_122 ;
F_43 ( L_37 , V_39 -> V_40 . V_41 ) ;
if ( V_159 >= 2 && V_159 != V_164 )
return - V_105 ;
V_42 = F_52 ( V_111 ) |
F_55 ( V_84 ) ;
V_42 |= ( V_39 -> V_40 . V_41 << V_11 ) ;
V_42 |= ( V_165 << V_9 ) ;
V_42 |= ( V_158 << V_166 ) ;
V_163 = & V_39 -> V_167 ;
V_163 -> V_168 = V_160 ;
if ( V_159 == V_164 ) {
if ( V_37 -> V_169 [ 0 ] && V_37 -> V_169 [ 1 ] ) {
V_37 -> V_170 [ 0 ] = V_37 -> V_170 [ 1 ] = V_160 ;
return 0 ;
} else if ( V_37 -> V_169 [ 0 ] )
V_163 -> V_159 = 1 ;
else if ( V_37 -> V_169 [ 1 ] )
V_163 -> V_159 = 0 ;
else
V_163 -> V_159 = V_164 ;
} else {
if ( V_37 -> V_169 [ V_159 ] ) {
V_37 -> V_170 [ V_159 ] = V_160 ;
return 0 ;
}
V_163 -> V_159 = V_159 ;
}
V_122 = F_51 ( & V_37 -> V_90 , V_42 , V_163 ,
sizeof( * V_163 ) , NULL , 0 ) ;
if ( V_122 < 0 ) {
F_24 ( V_37 -> V_51 , L_38 ) ;
return V_122 ;
}
return 0 ;
}
int F_56 ( struct V_36 * V_37 , T_1 V_158 , T_1 V_159 ,
T_1 * V_160 )
{
if ( V_159 > 1 )
return - V_105 ;
F_14 ( V_37 -> V_52 , V_160 ,
V_37 -> V_171 . V_161 [ V_159 ] ,
sizeof( * V_160 ) ) ;
return 0 ;
}
int F_57 ( struct V_36 * V_37 , T_1 V_158 , T_1 V_159 ,
T_1 V_160 )
{
struct V_162 V_163 ;
T_1 V_42 ;
int V_122 ;
F_43 ( L_39 , V_160 ) ;
if ( V_159 >= 2 && V_159 != V_164 )
return - V_105 ;
if ( V_159 == V_164 ) {
if ( V_37 -> V_169 [ 0 ] && V_37 -> V_169 [ 1 ] ) {
V_37 -> V_170 [ 0 ] = V_37 -> V_170 [ 1 ] = V_160 ;
return 0 ;
} else if ( V_37 -> V_169 [ 0 ] )
V_163 . V_159 = 1 ;
else if ( V_37 -> V_169 [ 1 ] )
V_163 . V_159 = 0 ;
else
V_163 . V_159 = V_164 ;
} else {
if ( V_37 -> V_169 [ V_159 ] ) {
V_37 -> V_170 [ V_159 ] = V_160 ;
return 0 ;
}
V_163 . V_159 = V_159 ;
}
V_42 = F_52 ( V_111 ) |
F_55 ( V_84 ) ;
V_42 |= ( V_37 -> V_171 . V_172 << V_11 ) ;
V_42 |= ( V_165 << V_9 ) ;
V_42 |= ( V_158 << V_166 ) ;
V_163 . V_173 = V_37 -> V_173 ;
V_163 . V_174 = V_37 -> V_174 ;
V_163 . V_168 = V_160 ;
V_122 = F_51 ( & V_37 -> V_90 , V_42 , & V_163 ,
sizeof( V_163 ) , NULL , 0 ) ;
if ( V_122 < 0 ) {
F_24 ( V_37 -> V_51 , L_40 ) ;
return V_122 ;
}
return 0 ;
}
struct V_35 * F_58 ( struct V_36 * V_37 , int V_175 ,
T_1 (* V_74)( struct V_35 * V_39 , void * V_176 ) ,
void * V_176 )
{
struct V_35 * V_39 ;
struct V_127 * V_128 = V_37 -> V_52 ;
unsigned long V_149 ;
V_39 = F_59 ( sizeof( * V_39 ) , V_177 ) ;
if ( V_39 == NULL )
return NULL ;
F_46 ( & V_128 -> V_150 , V_149 ) ;
V_39 -> V_40 . V_41 = V_178 ;
F_60 ( & V_39 -> V_179 , & V_37 -> V_180 ) ;
V_39 -> V_74 = V_74 ;
V_39 -> V_75 = V_176 ;
V_39 -> V_37 = V_37 ;
V_39 -> V_181 = V_175 ;
F_61 ( & V_39 -> V_62 , F_20 ) ;
F_49 ( & V_128 -> V_150 , V_149 ) ;
return V_39 ;
}
int F_62 ( struct V_36 * V_37 , struct V_35 * V_39 )
{
T_1 V_42 ;
int V_122 = 0 ;
struct V_127 * V_128 = V_37 -> V_52 ;
unsigned long V_149 ;
if ( ! V_39 ) {
F_63 ( V_37 -> V_51 , L_41 ) ;
return 0 ;
}
if ( ! V_39 -> V_182 )
goto V_183;
F_43 ( L_42 , V_39 -> V_181 ) ;
V_39 -> V_184 . V_38 = V_39 -> V_40 . V_41 ;
V_42 = F_52 ( V_132 ) ;
V_122 = F_51 ( & V_37 -> V_90 , V_42 , & V_39 -> V_184 ,
sizeof( V_39 -> V_184 ) , NULL , 0 ) ;
if ( V_122 < 0 ) {
F_24 ( V_37 -> V_51 , L_43 ,
V_39 -> V_184 . V_38 ) ;
return - V_185 ;
}
F_64 ( V_39 , & V_39 -> V_184 ) ;
V_183:
F_65 ( & V_39 -> V_62 ) ;
F_46 ( & V_128 -> V_150 , V_149 ) ;
F_33 ( & V_39 -> V_179 ) ;
F_66 ( V_39 ) ;
F_49 ( & V_128 -> V_150 , V_149 ) ;
return V_122 ;
}
int F_67 ( struct V_36 * V_37 ,
struct V_35 * V_39 , enum V_186 V_187 )
{
if ( V_39 -> V_182 ) {
F_24 ( V_37 -> V_51 , L_44 ) ;
return - V_105 ;
}
V_39 -> V_188 . V_189 . V_190 = V_187 ;
return 0 ;
}
int F_68 ( struct V_36 * V_37 ,
struct V_35 * V_39 , int V_191 )
{
if ( V_39 -> V_182 ) {
F_24 ( V_37 -> V_51 , L_45 ) ;
return - V_105 ;
}
V_39 -> V_188 . V_189 . V_192 = V_191 ;
return 0 ;
}
int F_69 ( struct V_36 * V_37 ,
struct V_35 * V_39 , int V_193 )
{
if ( V_39 -> V_182 ) {
F_24 ( V_37 -> V_51 , L_46 ) ;
return - V_105 ;
}
V_39 -> V_188 . V_189 . V_194 = V_193 ;
return 0 ;
}
int F_70 ( struct V_36 * V_37 ,
struct V_35 * V_39 , T_1 V_195 ,
enum V_16 V_17 )
{
if ( V_39 -> V_182 ) {
F_24 ( V_37 -> V_51 , L_47 ) ;
return - V_105 ;
}
V_39 -> V_188 . V_189 . V_195 = V_195 ;
V_39 -> V_188 . V_189 . V_17 = V_17 ;
return 0 ;
}
int F_71 ( struct V_36 * V_37 ,
struct V_35 * V_39 , enum V_196 V_197 )
{
if ( V_39 -> V_182 ) {
F_24 ( V_37 -> V_51 , L_48 ) ;
return - V_105 ;
}
V_39 -> V_188 . V_189 . V_197 = V_197 ;
return 0 ;
}
int F_72 ( struct V_36 * V_37 ,
struct V_35 * V_39 , T_1 V_187 )
{
if ( V_39 -> V_182 ) {
F_24 ( V_37 -> V_51 , L_49 ) ;
return - V_105 ;
}
V_39 -> V_188 . V_189 . V_198 = V_187 ;
return 0 ;
}
int F_73 ( struct V_36 * V_37 , struct V_35 * V_39 ,
enum V_199 V_200 ,
enum V_201 V_202 ,
enum F_73 V_203 )
{
if ( V_39 -> V_182 ) {
F_24 ( V_37 -> V_51 , L_50 ) ;
return - V_105 ;
}
V_39 -> V_188 . V_200 = V_200 ;
V_39 -> V_188 . V_202 = V_202 ;
V_39 -> V_188 . V_203 = V_203 ;
F_74 ( V_39 , & V_39 -> V_188 ) ;
return 0 ;
}
int F_75 ( struct V_36 * V_37 , struct V_35 * V_39 ,
T_1 V_204 , T_1 V_205 ,
T_1 V_206 , T_1 V_207 , T_1 V_208 )
{
if ( V_39 -> V_182 ) {
F_24 ( V_37 -> V_51 , L_51 ) ;
return - V_105 ;
}
V_39 -> V_188 . V_209 . V_204 = V_204 ;
V_39 -> V_188 . V_209 . V_205 = V_205 ;
V_39 -> V_188 . V_209 . V_206 = V_206 ;
V_39 -> V_188 . V_209 . V_207 = V_207 ;
V_39 -> V_188 . V_209 . V_208 = V_208 ;
F_76 ( V_39 ) ;
return 0 ;
}
int F_77 ( struct V_36 * V_37 ,
struct V_35 * V_39 , struct V_210 * V_211 )
{
struct V_212 * V_195 = & V_39 -> V_188 . V_195 ;
struct V_127 * V_52 = F_78 ( V_37 ) ;
struct V_213 * V_214 = V_211 -> V_214 ;
if ( V_39 -> V_182 ) {
F_24 ( V_37 -> V_51 , L_52 ) ;
return - V_105 ;
}
V_195 -> V_215 = 1 ;
V_195 -> V_216 [ 0 ] . V_114 = V_214 -> V_175 ;
V_195 -> V_216 [ 0 ] . V_217 = V_214 -> V_218 ;
V_39 -> V_188 . V_219 . V_45 =
F_79 ( V_52 , V_211 -> V_220 , V_221 ) ;
V_39 -> V_188 . V_219 . V_222 = V_214 -> V_223 ;
V_39 -> V_188 . V_224 . V_45 =
F_79 ( V_52 , V_52 -> V_225 , V_221 ) ;
V_39 -> V_188 . V_224 . V_222 = V_52 -> V_226 ;
F_13 ( V_37 -> V_51 , L_53 , V_214 -> V_175 ,
V_211 -> V_175 ) ;
F_13 ( V_37 -> V_51 , L_54 ,
V_39 -> V_188 . V_219 . V_45 ,
V_39 -> V_188 . V_219 . V_222 ) ;
F_13 ( V_37 -> V_51 , L_55 ,
V_39 -> V_188 . V_224 . V_45 ,
V_39 -> V_188 . V_224 . V_222 ) ;
return 0 ;
}
int F_80 ( struct V_36 * V_37 , struct V_35 * V_39 )
{
struct V_227 * V_228 = & V_39 -> V_188 ;
struct V_229 * V_40 = & V_39 -> V_40 ;
T_1 V_42 ;
int V_122 ;
if ( ! V_39 ) {
F_63 ( V_37 -> V_51 , L_56 ) ;
return 0 ;
}
if ( V_39 -> V_182 ) {
F_63 ( V_37 -> V_51 , L_57 ) ;
return 0 ;
}
F_43 ( L_58 , V_39 -> V_181 ) ;
V_42 = F_52 ( V_131 ) ;
V_122 = F_51 ( & V_37 -> V_90 , V_42 , V_228 ,
sizeof( * V_228 ) , V_40 , sizeof( * V_40 ) ) ;
if ( V_122 < 0 ) {
F_24 ( V_37 -> V_51 , L_59 ) ;
return V_122 ;
}
V_39 -> V_182 = 1 ;
F_81 ( V_39 ) ;
return 0 ;
}
T_4 F_82 ( struct V_36 * V_37 ,
struct V_35 * V_39 )
{
return V_39 -> V_230 ;
}
void F_83 ( struct V_36 * V_37 ,
struct V_35 * V_39 , T_4 V_231 )
{
V_39 -> V_230 = V_231 ;
}
bool F_84 ( struct V_36 * V_37 ,
struct V_35 * V_39 )
{
return V_39 -> V_232 ;
}
void F_85 ( struct V_36 * V_37 ,
struct V_35 * V_39 , bool V_231 )
{
V_39 -> V_232 = V_231 ;
}
int F_86 ( struct V_36 * V_37 )
{
struct V_233 * V_40 ;
T_1 V_42 ;
int V_122 ;
V_40 = & V_37 -> V_171 ;
V_42 = F_52 ( V_138 ) ;
F_43 ( L_60 , 0 ) ;
V_122 = F_51 ( & V_37 -> V_90 , V_42 , NULL , 0 ,
V_40 , sizeof( * V_40 ) ) ;
if ( V_122 < 0 ) {
F_24 ( V_37 -> V_51 , L_61 ) ;
return V_122 ;
}
F_87 ( V_40 ) ;
return 0 ;
}
static int F_88 ( struct V_36 * V_37 , int type ,
int V_38 , int V_234 )
{
T_1 V_42 ;
V_42 = F_52 ( V_111 ) | F_55 ( type ) ;
V_42 |= ( V_38 << V_11 ) ;
if ( V_234 )
return F_51 ( & V_37 -> V_90 , V_42 ,
NULL , 0 , NULL , 0 ) ;
else
return F_89 ( & V_37 -> V_90 , V_42 , NULL , 0 ) ;
}
int F_90 ( struct V_36 * V_37 , struct V_35 * V_39 ,
int V_234 )
{
int V_122 ;
if ( ! V_39 ) {
F_63 ( V_37 -> V_51 , L_62 ) ;
return 0 ;
}
F_43 ( L_63 , V_39 -> V_40 . V_41 ) ;
V_122 = F_88 ( V_37 , V_87 ,
V_39 -> V_40 . V_41 , V_234 ) ;
if ( V_122 < 0 )
F_24 ( V_37 -> V_51 , L_64 ,
V_39 -> V_40 . V_41 ) ;
return V_122 ;
}
int F_91 ( struct V_36 * V_37 , struct V_35 * V_39 ,
int V_234 )
{
int V_122 ;
if ( ! V_39 ) {
F_63 ( V_37 -> V_51 , L_65 ) ;
return 0 ;
}
F_43 ( L_66 , V_39 -> V_40 . V_41 ) ;
V_122 = F_88 ( V_37 , V_89 ,
V_39 -> V_40 . V_41 , V_234 ) ;
if ( V_122 < 0 )
F_24 ( V_37 -> V_51 , L_67 ,
V_39 -> V_40 . V_41 ) ;
return V_122 ;
}
int F_92 ( struct V_36 * V_37 , struct V_35 * V_39 )
{
int V_122 , V_235 = 10 ;
if ( ! V_39 ) {
F_63 ( V_37 -> V_51 , L_68 ) ;
return 0 ;
}
if ( ! V_39 -> V_182 )
return 0 ;
while ( V_39 -> V_88 && -- V_235 )
F_93 ( 1 ) ;
if ( ! V_235 ) {
F_24 ( V_37 -> V_51 , L_69 ,
V_39 -> V_40 . V_41 ) ;
return - V_105 ;
}
F_43 ( L_12 , V_39 -> V_40 . V_41 ) ;
V_122 = F_88 ( V_37 , V_86 ,
V_39 -> V_40 . V_41 , 1 ) ;
if ( V_122 < 0 )
F_24 ( V_37 -> V_51 , L_70 ,
V_39 -> V_40 . V_41 ) ;
return V_122 ;
}
T_1 F_94 ( struct V_36 * V_37 ,
struct V_35 * V_39 )
{
T_1 V_67 ;
F_14 ( V_37 -> V_52 , & V_67 ,
V_39 -> V_40 . V_236 , sizeof( V_67 ) ) ;
return V_67 ;
}
T_5 F_95 ( struct V_36 * V_37 ,
struct V_35 * V_39 )
{
T_5 V_237 ;
F_14 ( V_37 -> V_52 , & V_237 ,
V_39 -> V_40 . V_238 ,
sizeof( V_237 ) ) ;
return V_237 ;
}
int F_96 ( struct V_36 * V_37 ,
enum V_239 V_51 , enum V_240 V_241 ,
enum V_242 V_243 , T_1 V_244 )
{
struct V_245 V_17 ;
T_1 V_42 ;
int V_122 ;
F_43 ( L_71 , V_51 ) ;
V_37 -> V_246 = V_17 . V_247 = V_51 ;
V_37 -> V_248 = V_17 . V_249 = V_241 ;
V_37 -> V_250 = V_17 . V_243 = V_243 ;
V_37 -> V_251 = V_17 . V_244 = V_244 ;
if ( V_243 == V_252 )
V_17 . V_191 = 4 ;
else
V_17 . V_191 = 2 ;
F_97 ( & V_17 ) ;
V_42 = F_52 ( V_136 ) ;
V_122 = F_51 ( & V_37 -> V_90 , V_42 , & V_17 ,
sizeof( V_17 ) , NULL , 0 ) ;
if ( V_122 < 0 )
F_24 ( V_37 -> V_51 , L_72 ) ;
return V_122 ;
}
int F_98 ( struct V_36 * V_37 ,
enum V_253 V_254 , struct V_255 * V_256 )
{
T_1 V_42 , V_257 ;
int V_122 , V_258 ;
V_42 = F_52 ( V_137 ) ;
V_257 = V_254 ;
F_43 ( L_73 , V_254 ) ;
V_122 = F_51 ( & V_37 -> V_90 , V_42 , & V_257 ,
sizeof( V_257 ) , V_256 , sizeof( * V_256 ) ) ;
if ( V_122 < 0 ) {
F_24 ( V_37 -> V_51 , L_74 , V_254 ) ;
return V_122 ;
}
for ( V_258 = 0 ; V_258 < V_256 -> V_259 ; V_258 ++ ) {
F_13 ( V_37 -> V_51 ,
L_75 ,
V_258 , V_256 -> V_260 [ V_258 ] . V_45 ,
V_256 -> V_260 [ V_258 ] . V_222 ,
V_256 -> V_260 [ V_258 ] . V_261 ) ;
}
F_13 ( V_37 -> V_51 , L_76 ,
V_256 -> V_259 , V_254 ) ;
return V_122 ;
}
struct V_210 * F_99 ( struct V_36 * V_37 ,
int V_262 , int V_45 )
{
struct V_127 * V_52 = V_37 -> V_52 ;
struct V_213 * V_214 ;
struct V_210 * V_211 ;
int V_263 ;
V_214 = F_100 ( V_52 , V_262 ) ;
if ( V_214 == NULL ) {
F_24 ( V_52 -> V_51 , L_77 ,
V_262 ) ;
return NULL ;
}
V_211 = F_101 ( V_214 , V_262 , NULL ) ;
if ( V_211 == NULL ) {
F_24 ( V_52 -> V_51 , L_78 ,
V_262 ) ;
return NULL ;
}
V_263 = F_102 ( V_211 , V_45 ) ;
if ( V_263 < 0 ) {
F_24 ( V_52 -> V_51 , L_79 ,
V_262 ) ;
F_103 ( V_211 ) ;
return NULL ;
}
F_13 ( V_52 -> V_51 , L_80 , V_211 -> V_175 ,
V_262 ) ;
return V_211 ;
}
void F_104 ( struct V_210 * V_211 )
{
F_105 ( V_211 ) ;
F_103 ( V_211 ) ;
}
static int F_106 ( struct V_36 * V_37 )
{
struct V_127 * V_128 = V_37 -> V_52 ;
T_1 V_258 , V_45 , V_222 ;
int V_122 = 0 ;
F_43 ( L_81 , V_264 ) ;
if ( V_37 -> V_256 . V_259 > V_264 ) {
F_24 ( V_37 -> V_51 ,
L_82 ,
V_264 ) ;
memset ( & V_37 -> V_256 , 0 , sizeof( V_37 -> V_256 ) ) ;
return - V_105 ;
}
V_122 = F_107 ( V_128 , 0 ) ;
if ( V_122 < 0 ) {
F_24 ( V_37 -> V_51 , L_83 , V_122 ) ;
return V_122 ;
}
F_25 ( V_128 , V_265 ,
V_266 | V_267 ,
V_266 | V_267 ) ;
for ( V_258 = 0 ; V_258 < V_37 -> V_256 . V_259 ; V_258 ++ ) {
if ( V_37 -> V_256 . V_260 [ V_258 ] . V_261 == V_268
&& V_37 -> V_256 . V_260 [ V_258 ] . V_45 > V_269
&& V_37 -> V_256 . V_260 [ V_258 ] . V_45 <
V_269 + V_270 ) {
V_45 = V_37 -> V_256 . V_260 [ V_258 ] . V_45
- V_269 ;
V_222 = ( V_37 -> V_256 . V_260 [ V_258 ] . V_222 + 3 ) & ( ~ 3 ) ;
V_122 = F_108 ( V_128 , V_37 -> V_271 + V_45 ,
V_128 -> V_272 . V_273 + V_45 , V_222 ) ;
if ( V_122 < 0 ) {
F_24 ( V_37 -> V_51 ,
L_84 ) ;
memset ( & V_37 -> V_256 , 0 , sizeof( V_37 -> V_256 ) ) ;
goto V_183;
}
}
}
V_183:
F_109 ( V_128 ) ;
return V_122 ;
}
static int F_110 ( struct V_36 * V_37 )
{
struct V_127 * V_128 = V_37 -> V_52 ;
T_1 V_258 , V_45 , V_222 ;
int V_122 ;
for ( V_258 = 0 ; V_258 < V_37 -> V_256 . V_259 ; V_258 ++ ) {
if ( V_37 -> V_256 . V_260 [ V_258 ] . V_261 == V_268
&& V_37 -> V_256 . V_260 [ V_258 ] . V_45 > V_269
&& V_37 -> V_256 . V_260 [ V_258 ] . V_45 <
V_269 + V_270 ) {
V_45 = V_37 -> V_256 . V_260 [ V_258 ] . V_45
- V_269 ;
V_222 = ( V_37 -> V_256 . V_260 [ V_258 ] . V_222 + 3 ) & ( ~ 3 ) ;
V_122 = F_111 ( V_128 , V_128 -> V_272 . V_273 + V_45 ,
V_37 -> V_271 + V_45 , V_222 ) ;
if ( V_122 < 0 ) {
F_24 ( V_37 -> V_51 ,
L_85 ) ;
return V_122 ;
}
}
}
return 0 ;
}
int F_112 ( struct V_36 * V_37 )
{
struct V_127 * V_52 = V_37 -> V_52 ;
struct V_274 * V_274 , * V_275 ;
int V_122 ;
F_13 ( V_37 -> V_51 , L_86 ) ;
V_122 = F_113 ( V_52 ) ;
if ( V_122 < 0 ) {
F_24 ( V_37 -> V_51 , L_87 ) ;
return - V_276 ;
}
V_122 = F_107 ( V_52 , 0 ) ;
if ( V_122 < 0 ) {
F_24 ( V_37 -> V_51 , L_83 , V_122 ) ;
return V_122 ;
}
F_114 (sst_fw, t, &dsp->fw_list, list) {
V_122 = F_115 ( V_274 ) ;
if ( V_122 < 0 ) {
F_24 ( V_37 -> V_51 , L_88 ) ;
F_109 ( V_52 ) ;
return - V_101 ;
}
}
V_122 = F_116 ( V_37 -> V_52 ) ;
if ( V_122 < 0 )
return - V_105 ;
F_109 ( V_52 ) ;
return 0 ;
}
static int F_117 ( struct V_36 * V_37 )
{
struct V_127 * V_52 = V_37 -> V_52 ;
int V_122 ;
F_13 ( V_37 -> V_51 , L_89 ) ;
V_122 = F_107 ( V_52 , 0 ) ;
if ( V_122 < 0 ) {
F_24 ( V_37 -> V_51 , L_83 , V_122 ) ;
return V_122 ;
}
V_122 = F_110 ( V_37 ) ;
if ( V_122 < 0 ) {
F_24 ( V_37 -> V_51 , L_90 ) ;
F_109 ( V_52 ) ;
return - V_101 ;
}
F_109 ( V_52 ) ;
F_118 ( V_52 ) ;
return V_122 ;
}
int F_119 ( struct V_36 * V_37 )
{
int V_122 ;
F_13 ( V_37 -> V_51 , L_91 ) ;
V_122 = F_98 ( V_37 , V_277 , & V_37 -> V_256 ) ;
if ( V_122 < 0 )
return V_122 ;
F_120 ( V_37 -> V_52 ) ;
V_122 = F_106 ( V_37 ) ;
if ( V_122 < 0 )
return V_122 ;
F_121 ( & V_37 -> V_90 ) ;
return 0 ;
}
int F_122 ( struct V_36 * V_37 )
{
struct V_274 * V_274 , * V_275 ;
struct V_127 * V_52 = V_37 -> V_52 ;
F_123 (sst_fw, t, &dsp->fw_list, list) {
F_124 ( V_274 ) ;
}
F_125 ( V_52 ) ;
V_37 -> V_57 = false ;
F_126 ( V_52 ) ;
return 0 ;
}
int F_127 ( struct V_36 * V_37 )
{
struct V_278 * V_51 = V_37 -> V_51 ;
int V_122 ;
F_13 ( V_51 , L_92 ) ;
if ( V_37 -> V_57 )
return 1 ;
V_122 = F_117 ( V_37 ) ;
if ( V_122 < 0 )
F_24 ( V_51 , L_93 ) ;
F_128 ( V_37 ) ;
V_122 = F_129 ( V_37 -> V_58 , V_37 -> V_57 ,
F_130 ( V_279 ) ) ;
if ( V_122 == 0 ) {
F_24 ( V_37 -> V_51 , L_94 ,
F_42 ( V_37 -> V_52 , V_76 ) ,
F_42 ( V_37 -> V_52 , V_152 ) ) ;
return - V_91 ;
}
V_122 = F_96 ( V_37 , V_37 -> V_246 , V_37 -> V_248 ,
V_37 -> V_250 , V_37 -> V_251 ) ;
if ( V_122 < 0 )
F_24 ( V_51 , L_95 ) ;
return V_122 ;
}
struct V_127 * F_78 ( struct V_36 * V_37 )
{
return V_37 -> V_52 ;
}
void F_128 ( struct V_36 * V_37 )
{
struct V_213 * V_214 ;
enum V_280 V_175 ;
for ( V_175 = V_281 ; V_175 < V_282 ; V_175 ++ ) {
V_214 = F_100 ( V_37 -> V_52 , V_175 ) ;
if ( V_214 ) {
if ( V_175 == V_283 )
V_214 -> V_254 = V_284 ;
else
V_214 -> V_254 = V_285 ;
}
}
}
bool F_131 ( struct V_36 * V_37 , T_1 V_114 )
{
struct V_213 * V_214 ;
V_214 = F_100 ( V_37 -> V_52 , V_114 ) ;
if ( V_214 == NULL || V_214 -> V_254 == V_286 )
return false ;
else
return true ;
}
bool F_132 ( struct V_36 * V_37 , T_1 V_114 )
{
struct V_213 * V_214 ;
V_214 = F_100 ( V_37 -> V_52 , V_114 ) ;
if ( V_214 != NULL && V_214 -> V_254 == V_285 )
return true ;
else
return false ;
}
void F_133 ( struct V_36 * V_37 , T_1 V_114 )
{
V_37 -> V_287 |= ( 1 << V_114 ) ;
}
void F_134 ( struct V_36 * V_37 , T_1 V_114 )
{
V_37 -> V_287 &= ~ ( 1 << V_114 ) ;
}
bool F_135 ( struct V_36 * V_37 , T_1 V_114 )
{
return V_37 -> V_287 & ( 1 << V_114 ) ;
}
void F_136 ( struct V_36 * V_37 )
{
V_37 -> V_288 = 0 ;
V_37 -> V_289 = 0 ;
memset ( ( void * ) V_37 -> V_290 , 0 , sizeof( V_37 -> V_290 ) ) ;
}
int F_137 ( struct V_36 * V_37 , T_2 * V_291 )
{
if ( V_37 -> V_288 > V_292 - 1 ) {
F_63 ( V_37 -> V_51 , L_96 ) ;
return - V_293 ;
}
memcpy ( V_37 -> V_290 [ V_37 -> V_288 ] , V_291 , V_294 ) ;
V_37 -> V_288 ++ ;
return 0 ;
}
int F_138 ( struct V_36 * V_37 , T_2 * V_291 )
{
T_2 V_175 = 0 ;
while ( V_37 -> V_289 < V_292 ) {
V_175 = V_37 -> V_290 [ V_37 -> V_289 ] [ 0 ] ;
V_37 -> V_289 ++ ;
if ( V_291 [ 0 ] == V_175 ) {
memcpy ( V_291 , V_37 -> V_290 [ V_37 -> V_289 ] ,
V_294 ) ;
break;
}
}
if ( V_37 -> V_289 > V_292 - 1 ) {
F_13 ( V_37 -> V_51 , L_97 ) ;
V_37 -> V_289 = 0 ;
return 0 ;
}
return 0 ;
}
int F_139 ( struct V_36 * V_37 )
{
int V_122 , V_295 ;
if ( ! F_132 ( V_37 , V_283 ) ) {
F_13 ( V_37 -> V_51 , L_98 ) ;
return 0 ;
}
for ( V_295 = 0 ; V_295 < V_37 -> V_288 ; V_295 ++ ) {
V_122 = F_140 ( V_37 ,
V_283 , 0 , V_37 -> V_290 [ V_295 ] [ 0 ] ,
V_294 , V_37 -> V_290 [ V_295 ] ) ;
if ( V_122 < 0 )
return V_122 ;
}
return 0 ;
}
int F_141 ( struct V_36 * V_37 ,
T_1 V_114 , T_1 V_296 , char * V_297 )
{
int V_122 = 0 ;
const struct V_298 * V_299 = NULL ;
struct V_274 * V_300 ;
struct V_213 * V_214 ;
struct V_278 * V_51 = V_37 -> V_51 ;
struct V_127 * V_52 = V_37 -> V_52 ;
F_13 ( V_51 , L_99 , V_114 , V_297 ) ;
V_214 = F_100 ( V_52 , V_114 ) ;
if ( V_214 == NULL ) {
if ( V_114 == V_281 ) {
V_299 = V_52 -> V_75 -> V_299 ;
if ( ! V_299 ) {
F_24 ( V_51 , L_100 ) ;
return - V_276 ;
}
} else {
V_122 = F_142 ( & V_299 , V_297 , V_51 ) ;
if ( V_122 ) {
F_19 ( V_51 , L_101 ,
V_297 , V_122 ) ;
return V_122 ;
}
}
V_300 = F_143 ( V_52 , V_299 , V_37 ) ;
if ( V_300 == NULL ) {
F_24 ( V_51 , L_102 ) ;
V_122 = - V_101 ;
goto V_183;
}
V_214 = F_100 ( V_52 , V_114 ) ;
if ( V_214 == NULL ) {
F_24 ( V_51 , L_103 ,
V_114 , V_297 ) ;
}
} else
F_19 ( V_51 , L_104 ,
V_114 , V_297 ) ;
V_183:
if ( V_299 && V_114 != V_281 )
F_144 ( V_299 ) ;
return V_122 ;
}
int F_145 ( struct V_36 * V_37 ,
T_1 V_114 , T_1 V_296 )
{
int V_122 ;
T_1 V_42 = 0 ;
struct V_301 V_17 ;
struct V_213 * V_214 ;
struct V_210 * V_211 ;
struct V_278 * V_51 = V_37 -> V_51 ;
struct V_127 * V_52 = V_37 -> V_52 ;
if ( ! F_131 ( V_37 , V_114 ) ) {
F_13 ( V_51 , L_105 , V_114 ) ;
return 0 ;
}
if ( F_132 ( V_37 , V_114 ) ) {
F_19 ( V_51 , L_106 , V_114 ) ;
return 0 ;
}
V_214 = F_100 ( V_52 , V_114 ) ;
if ( V_214 == NULL ) {
F_24 ( V_51 , L_107 , V_114 ) ;
return - V_302 ;
}
V_211 = F_146 ( V_214 , V_114 ) ;
if ( V_211 == NULL ) {
F_24 ( V_51 , L_108 , V_114 ) ;
return - V_302 ;
}
V_42 = F_52 ( V_143 ) |
F_147 ( V_303 ) |
F_148 ( V_114 ) ;
F_13 ( V_51 , L_109 , V_42 ) ;
V_17 . V_195 . V_215 = 1 ;
V_17 . V_195 . V_216 [ 0 ] . V_114 = V_214 -> V_175 ;
V_17 . V_195 . V_216 [ 0 ] . V_217 = V_214 -> V_218 ;
V_17 . V_219 . V_45 =
F_79 ( V_52 ,
V_211 -> V_220 , V_221 ) ;
V_17 . V_219 . V_222 = V_214 -> V_223 ;
V_17 . V_224 . V_45 =
F_79 ( V_52 ,
V_52 -> V_225 , V_221 ) ;
V_17 . V_224 . V_222 = V_214 -> V_226 ;
F_13 ( V_51 , L_110 ,
V_17 . V_195 . V_216 [ 0 ] . V_114 ,
V_17 . V_219 . V_222 ,
V_17 . V_219 . V_45 ,
V_17 . V_224 . V_222 , V_17 . V_224 . V_45 ,
V_17 . V_195 . V_216 [ 0 ] . V_217 ) ;
V_122 = F_51 ( & V_37 -> V_90 , V_42 ,
& V_17 , sizeof( V_17 ) , NULL , 0 ) ;
if ( V_122 < 0 )
F_24 ( V_51 , L_111 , V_122 ) ;
else
V_214 -> V_254 = V_285 ;
return V_122 ;
}
int F_149 ( struct V_36 * V_37 ,
T_1 V_114 , T_1 V_296 )
{
int V_122 ;
T_1 V_42 ;
struct V_213 * V_214 ;
struct V_278 * V_51 = V_37 -> V_51 ;
struct V_127 * V_52 = V_37 -> V_52 ;
if ( ! F_131 ( V_37 , V_114 ) ) {
F_13 ( V_51 , L_105 , V_114 ) ;
return 0 ;
}
if ( ! F_132 ( V_37 , V_114 ) ) {
F_19 ( V_51 , L_112 , V_114 ) ;
return 0 ;
}
V_214 = F_100 ( V_52 , V_114 ) ;
if ( V_214 == NULL ) {
F_24 ( V_51 , L_107 , V_114 ) ;
return - V_302 ;
}
V_42 = F_52 ( V_143 ) |
F_147 ( V_304 ) |
F_148 ( V_114 ) ;
V_122 = F_51 ( & V_37 -> V_90 , V_42 , NULL , 0 , NULL , 0 ) ;
if ( V_122 < 0 )
F_24 ( V_51 , L_113 , V_122 ) ;
else
V_214 -> V_254 = V_284 ;
return V_122 ;
}
int F_140 ( struct V_36 * V_37 ,
T_1 V_114 , T_1 V_296 , T_1 V_305 ,
T_1 V_306 , char * V_307 )
{
int V_122 ;
unsigned char * V_176 = NULL ;
T_1 V_42 = 0 ;
T_1 V_308 = 0 , V_309 = 0 ;
T_6 V_310 = 0 ;
struct V_311 * V_312 ;
struct V_278 * V_51 = V_37 -> V_51 ;
V_42 = F_52 ( V_143 ) |
F_147 ( V_313 ) |
F_148 ( V_114 ) ;
F_13 ( V_51 , L_114 , V_42 ) ;
V_308 = V_306 +
sizeof( struct V_311 ) -
sizeof( struct V_314 ) ;
F_13 ( V_51 , L_115 , V_306 ) ;
F_13 ( V_51 , L_116 , V_308 ) ;
if ( V_308 <= V_315 ) {
F_13 ( V_51 , L_117 ,
V_309 ) ;
V_309 = F_150 ( V_308 , 4 ) ;
F_13 ( V_51 , L_118 ,
V_309 ) ;
V_312 = F_59 ( V_309 , V_177 ) ;
if ( V_312 == NULL )
return - V_101 ;
memcpy ( V_312 -> V_176 , V_307 , V_306 ) ;
} else {
F_63 ( V_51 , L_119 ) ;
return 0 ;
}
V_312 -> V_305 = V_305 ;
V_312 -> V_316 = V_306 ;
V_122 = F_51 ( & V_37 -> V_90 , V_42 ,
V_312 , V_309 , NULL , 0 ) ;
if ( V_122 < 0 )
F_24 ( V_51 , L_120 , V_122 ) ;
F_66 ( V_312 ) ;
if ( V_176 )
F_151 ( V_37 -> V_52 -> V_317 ,
V_306 , ( void * ) V_176 , V_310 ) ;
return V_122 ;
}
static void F_152 ( struct V_146 * V_90 , struct V_81 * V_1 )
{
F_153 ( V_90 -> V_52 , V_1 -> V_318 , V_1 -> V_319 ) ;
F_154 ( V_90 -> V_52 , V_1 -> V_42 ) ;
}
static void F_155 ( struct V_146 * V_90 , const char * V_320 )
{
struct V_127 * V_128 = V_90 -> V_52 ;
T_1 V_321 , V_148 , V_322 , V_147 ;
V_147 = F_42 ( V_128 , V_152 ) ;
V_321 = F_42 ( V_128 , V_323 ) ;
V_148 = F_42 ( V_128 , V_76 ) ;
V_322 = F_42 ( V_128 , V_79 ) ;
F_24 ( V_90 -> V_51 ,
L_121 ,
V_320 , V_147 , V_321 , V_148 , V_322 ) ;
}
static void F_156 ( struct V_81 * V_1 , char * V_318 ,
T_7 V_319 )
{
memcpy ( V_1 -> V_318 , V_318 , V_319 ) ;
}
static T_5 F_157 ( T_5 V_42 , T_5 * V_324 )
{
V_42 &= ~ ( V_82 | V_4 ) ;
* V_324 = ( T_5 ) - 1 ;
return V_42 ;
}
static bool F_158 ( struct V_127 * V_52 )
{
T_5 V_147 ;
V_147 = F_42 ( V_52 , V_152 ) ;
return ( V_147 & ( V_325 | V_151 ) ) ;
}
int F_159 ( struct V_278 * V_51 , struct V_326 * V_75 )
{
struct V_156 V_157 ;
struct V_36 * V_37 ;
struct V_146 * V_90 ;
int V_122 ;
F_13 ( V_51 , L_122 ) ;
V_37 = F_160 ( V_51 , sizeof( * V_37 ) , V_177 ) ;
if ( V_37 == NULL )
return - V_101 ;
V_37 -> V_51 = V_51 ;
V_90 = & V_37 -> V_90 ;
V_90 -> V_51 = V_51 ;
V_90 -> V_327 . V_328 = F_152 ;
V_90 -> V_327 . V_329 = F_155 ;
V_90 -> V_327 . V_330 = F_156 ;
V_90 -> V_327 . V_331 = F_157 ;
V_90 -> V_327 . V_332 = F_158 ;
V_90 -> V_333 = V_47 ;
V_90 -> V_334 = V_47 ;
V_122 = F_161 ( V_90 ) ;
if ( V_122 != 0 )
goto V_335;
F_162 ( & V_37 -> V_180 ) ;
F_163 ( & V_37 -> V_58 ) ;
V_336 . V_337 = V_37 ;
V_37 -> V_52 = F_164 ( V_51 , & V_336 , V_75 ) ;
if ( V_37 -> V_52 == NULL ) {
V_122 = - V_276 ;
goto V_338;
}
V_90 -> V_52 = V_37 -> V_52 ;
V_37 -> V_339 = F_165 ( V_37 -> V_52 -> V_317 ,
V_270 , & V_37 -> V_271 , V_177 ) ;
if ( V_37 -> V_339 == NULL ) {
V_122 = - V_101 ;
goto V_340;
}
F_166 ( V_37 -> V_52 ) ;
V_122 = F_141 ( V_37 , V_281 , 0 , L_123 ) ;
if ( V_122 < 0 )
goto V_341;
F_141 ( V_37 , V_283 , 0 , L_124 ) ;
V_122 = F_116 ( V_37 -> V_52 ) ;
if ( V_122 < 0 )
goto V_342;
F_136 ( V_37 ) ;
F_118 ( V_37 -> V_52 ) ;
V_122 = F_129 ( V_37 -> V_58 , V_37 -> V_57 ,
F_130 ( V_279 ) ) ;
if ( V_122 == 0 ) {
V_122 = - V_91 ;
F_24 ( V_37 -> V_51 , L_94 ,
F_42 ( V_37 -> V_52 , V_76 ) ,
F_42 ( V_37 -> V_52 , V_152 ) ) ;
goto V_342;
}
F_128 ( V_37 ) ;
F_50 ( V_37 , & V_157 ) ;
V_122 = F_86 ( V_37 ) ;
if ( V_122 < 0 ) {
F_24 ( V_37 -> V_51 , L_125 ) ;
goto V_342;
}
V_75 -> V_52 = V_37 ;
return 0 ;
V_342:
F_166 ( V_37 -> V_52 ) ;
F_167 ( V_37 -> V_52 ) ;
V_341:
F_151 ( V_37 -> V_52 -> V_317 , V_270 ,
V_37 -> V_339 , V_37 -> V_271 ) ;
V_340:
F_168 ( V_37 -> V_52 ) ;
V_338:
F_169 ( V_90 ) ;
V_335:
return V_122 ;
}
void F_170 ( struct V_278 * V_51 , struct V_326 * V_75 )
{
struct V_36 * V_37 = V_75 -> V_52 ;
F_166 ( V_37 -> V_52 ) ;
F_167 ( V_37 -> V_52 ) ;
F_151 ( V_37 -> V_52 -> V_317 , V_270 ,
V_37 -> V_339 , V_37 -> V_271 ) ;
F_168 ( V_37 -> V_52 ) ;
F_169 ( & V_37 -> V_90 ) ;
}
