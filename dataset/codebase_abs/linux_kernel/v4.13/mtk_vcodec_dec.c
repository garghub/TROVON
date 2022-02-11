static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
unsigned int V_5 ;
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ ) {
V_4 = & V_7 [ V_5 ] ;
if ( V_4 -> V_8 == V_3 -> V_4 . V_9 . V_10 )
return V_4 ;
}
return NULL ;
}
static struct V_11 * F_2 ( struct V_12 * V_13 ,
enum V_14 type )
{
if ( F_3 ( type ) )
return & V_13 -> V_15 [ V_16 ] ;
return & V_13 -> V_15 [ V_17 ] ;
}
static struct V_18 * F_4 ( struct V_12 * V_13 )
{
struct V_19 * V_20 = NULL ;
struct V_21 * V_22 ;
F_5 ( 3 , L_1 , V_13 -> V_23 ) ;
if ( F_6 ( V_13 ,
V_24 ,
& V_20 ) ) {
F_7 ( L_2 ,
V_13 -> V_23 ) ;
return NULL ;
}
if ( V_20 == NULL ) {
F_5 ( 3 , L_3 ) ;
return NULL ;
}
V_22 = F_8 ( V_20 , struct V_21 ,
V_25 ) ;
F_9 ( & V_13 -> V_26 ) ;
if ( V_22 -> V_27 ) {
F_10 ( & V_22 -> V_28 . V_29 , 0 ,
V_13 -> V_30 . V_31 ) ;
F_10 ( & V_22 -> V_28 . V_29 , 1 ,
V_13 -> V_30 . V_32 ) ;
V_22 -> V_33 = true ;
F_5 ( 2 ,
L_4 ,
V_13 -> V_23 , V_20 -> V_34 ,
V_22 -> V_28 . V_29 . V_35 ,
V_22 -> V_36 ) ;
F_11 ( & V_22 -> V_28 , V_37 ) ;
V_13 -> V_38 ++ ;
}
F_12 ( & V_13 -> V_26 ) ;
return & V_22 -> V_28 . V_29 ;
}
static struct V_18 * F_13 ( struct V_12 * V_13 )
{
struct V_21 * V_22 ;
struct V_19 * V_39 = NULL ;
if ( F_6 ( V_13 ,
V_40 ,
& V_39 ) ) {
F_7 ( L_5 , V_13 -> V_23 ) ;
return NULL ;
}
if ( V_39 == NULL ) {
F_5 ( 3 , L_6 ) ;
return NULL ;
}
F_5 ( 3 , L_7 ,
V_13 -> V_23 , V_39 ) ;
V_22 = F_8 ( V_39 , struct V_21 ,
V_25 ) ;
F_9 ( & V_13 -> V_26 ) ;
if ( V_22 -> V_27 ) {
if ( ( V_22 -> V_36 ) &&
( V_22 -> V_41 ) &&
( V_39 -> V_34 == V_42 ) ) {
F_5 ( 2 ,
L_8 ,
V_13 -> V_23 , V_39 -> V_34 ,
V_22 -> V_28 . V_29 . V_35 ,
V_22 -> V_36 ) ;
F_14 ( V_13 -> V_43 , & V_22 -> V_28 ) ;
} else if ( ( V_22 -> V_36 == false ) &&
( V_22 -> V_41 == true ) ) {
F_5 ( 2 ,
L_9 ,
V_13 -> V_23 , V_39 -> V_34 ,
V_22 -> V_28 . V_29 . V_35 ) ;
F_14 ( V_13 -> V_43 , & V_22 -> V_28 ) ;
V_22 -> V_36 = true ;
} else {
F_5 ( 3 , L_10 ,
V_13 -> V_23 , V_39 -> V_34 ,
V_22 -> V_28 . V_29 . V_35 ,
V_22 -> V_36 ,
V_22 -> V_41 ) ;
}
V_22 -> V_27 = false ;
}
F_12 ( & V_13 -> V_26 ) ;
return & V_22 -> V_28 . V_29 ;
}
static void F_15 ( struct V_12 * V_13 )
{
struct V_18 * V_44 ;
do {
V_44 = F_4 ( V_13 ) ;
} while ( V_44 );
}
static void F_16 ( struct V_12 * V_13 )
{
struct V_18 * V_44 ;
do {
V_44 = F_13 ( V_13 ) ;
} while ( V_44 );
}
static void F_17 ( struct V_12 * V_13 )
{
static const struct V_45 V_46 = {
. type = V_47 ,
. V_48 . V_49 . V_50 =
V_51 ,
} ;
F_5 ( 1 , L_1 , V_13 -> V_23 ) ;
F_18 ( & V_13 -> V_52 , & V_46 ) ;
}
static void F_19 ( struct V_12 * V_13 )
{
bool V_53 ;
int V_54 = 0 ;
V_54 = F_20 ( V_13 , NULL , NULL , & V_53 ) ;
if ( V_54 )
F_7 ( L_11 , V_54 ) ;
F_15 ( V_13 ) ;
F_16 ( V_13 ) ;
}
static int F_21 ( struct V_12 * V_13 )
{
unsigned int V_55 = 0 ;
int V_54 ;
if ( F_6 ( V_13 ,
V_56 ,
& V_13 -> V_57 ) ) {
F_7 ( L_12 ,
V_13 -> V_23 ) ;
return - V_58 ;
}
if ( V_13 -> V_57 . V_59 == 0 ||
V_13 -> V_57 . V_60 == 0 ||
V_13 -> V_57 . V_61 == 0 ||
V_13 -> V_57 . V_62 == 0 ) {
F_7 ( L_13 ) ;
return - V_58 ;
}
if ( ( V_13 -> V_57 . V_59 == V_13 -> V_30 . V_59 ) ||
( V_13 -> V_57 . V_60 == V_13 -> V_30 . V_60 ) )
return 0 ;
F_5 ( 1 ,
L_14 ,
V_13 -> V_23 , V_13 -> V_57 . V_59 ,
V_13 -> V_57 . V_60 ,
V_13 -> V_30 . V_59 , V_13 -> V_30 . V_60 ,
V_13 -> V_57 . V_61 ,
V_13 -> V_57 . V_62 ) ;
V_54 = F_6 ( V_13 , V_63 , & V_55 ) ;
if ( V_55 == 0 )
F_7 ( L_15 , V_54 ) ;
V_13 -> V_64 = V_55 ;
return V_54 ;
}
static void F_22 ( struct V_65 * V_66 )
{
struct V_12 * V_13 = F_8 ( V_66 , struct V_12 ,
V_67 ) ;
struct V_68 * V_69 = V_13 -> V_69 ;
struct V_18 * V_70 , * V_71 ;
struct V_72 V_73 ;
struct V_19 * V_74 ;
bool V_53 = false ;
int V_54 ;
struct V_21 * V_75 , * V_76 ;
struct V_77 * V_78 , * V_79 ;
V_70 = F_23 ( V_13 -> V_43 ) ;
if ( V_70 == NULL ) {
F_24 ( V_69 -> V_80 , V_13 -> V_43 ) ;
F_5 ( 1 , L_16 , V_13 -> V_23 ) ;
return;
}
V_71 = F_25 ( V_13 -> V_43 ) ;
if ( V_71 == NULL ) {
F_24 ( V_69 -> V_80 , V_13 -> V_43 ) ;
F_5 ( 1 , L_17 , V_13 -> V_23 ) ;
return;
}
V_79 = F_8 ( V_70 , struct V_77 , V_29 ) ;
V_76 = F_8 ( V_79 , struct V_21 , V_28 ) ;
V_78 = F_8 ( V_71 , struct V_77 , V_29 ) ;
V_75 = F_8 ( V_78 , struct V_21 , V_28 ) ;
V_74 = & V_75 -> V_25 ;
V_74 -> V_81 . V_82 = F_26 ( V_71 , 0 ) ;
V_74 -> V_81 . V_83 = F_27 ( V_71 , 0 ) ;
V_74 -> V_81 . V_84 = V_13 -> V_30 . V_31 + V_13 -> V_30 . V_85 ;
V_74 -> V_86 . V_82 = F_26 ( V_71 , 1 ) ;
V_74 -> V_86 . V_83 = F_27 ( V_71 , 1 ) ;
V_74 -> V_86 . V_84 = V_13 -> V_30 . V_32 + V_13 -> V_30 . V_87 ;
V_74 -> V_34 = 0 ;
F_5 ( 3 , L_18 , V_13 -> V_23 ) ;
F_5 ( 3 ,
L_19 ,
V_71 -> V_35 , V_74 ,
V_74 -> V_81 . V_82 , & V_74 -> V_81 . V_83 ,
& V_74 -> V_86 . V_83 , V_74 -> V_81 . V_84 ) ;
if ( V_76 -> V_88 ) {
F_5 ( 1 , L_20 ) ;
V_70 = F_28 ( V_13 -> V_43 ) ;
V_71 = F_29 ( V_13 -> V_43 ) ;
F_9 ( & V_13 -> V_26 ) ;
V_75 -> V_27 = false ;
F_12 ( & V_13 -> V_26 ) ;
F_20 ( V_13 , NULL , NULL , & V_53 ) ;
F_15 ( V_13 ) ;
F_10 ( & V_75 -> V_28 . V_29 , 0 , 0 ) ;
F_10 ( & V_75 -> V_28 . V_29 , 1 , 0 ) ;
V_78 -> V_89 |= V_90 ;
F_11 ( & V_75 -> V_28 , V_37 ) ;
F_16 ( V_13 ) ;
F_24 ( V_69 -> V_80 , V_13 -> V_43 ) ;
return;
}
V_73 . V_82 = F_26 ( V_70 , 0 ) ;
V_73 . V_83 = F_27 ( V_70 , 0 ) ;
V_73 . V_84 = ( V_91 ) V_70 -> V_92 [ 0 ] . V_93 ;
if ( ! V_73 . V_82 ) {
F_24 ( V_69 -> V_80 , V_13 -> V_43 ) ;
F_7 ( L_21 ,
V_13 -> V_23 , V_70 -> V_35 ) ;
return;
}
F_5 ( 3 , L_22 ,
V_13 -> V_23 , V_73 . V_82 , & V_73 . V_83 , V_73 . V_84 , V_70 ) ;
V_75 -> V_28 . V_29 . V_94
= V_76 -> V_28 . V_29 . V_94 ;
V_75 -> V_28 . V_95
= V_76 -> V_28 . V_95 ;
F_9 ( & V_13 -> V_26 ) ;
V_75 -> V_27 = true ;
F_12 ( & V_13 -> V_26 ) ;
V_76 -> V_27 = true ;
V_54 = F_20 ( V_13 , & V_73 , V_74 , & V_53 ) ;
if ( V_54 ) {
F_7 (
L_23 ,
V_13 -> V_23 ,
V_70 -> V_35 ,
V_73 . V_84 ,
V_76 -> V_28 . V_29 . V_94 ,
V_71 -> V_35 ,
V_54 , V_53 ) ;
V_70 = F_28 ( V_13 -> V_43 ) ;
if ( V_54 == - V_96 ) {
F_9 ( & V_13 -> V_26 ) ;
V_76 -> error = true ;
F_12 ( & V_13 -> V_26 ) ;
}
F_11 ( & V_76 -> V_28 , V_97 ) ;
} else if ( V_53 == false ) {
V_70 = F_28 ( V_13 -> V_43 ) ;
F_11 ( & V_76 -> V_28 , V_37 ) ;
}
V_71 = F_29 ( V_13 -> V_43 ) ;
F_15 ( V_13 ) ;
F_16 ( V_13 ) ;
if ( ! V_54 && V_53 ) {
F_21 ( V_13 ) ;
F_19 ( V_13 ) ;
F_17 ( V_13 ) ;
}
F_24 ( V_69 -> V_80 , V_13 -> V_43 ) ;
}
static int F_30 ( struct V_98 * V_98 , void * V_99 ,
struct V_100 * V_101 )
{
switch ( V_101 -> V_101 ) {
case V_102 :
case V_103 :
if ( V_101 -> V_89 != 0 ) {
F_7 ( L_24 , V_101 -> V_89 ) ;
return - V_58 ;
}
break;
default:
return - V_58 ;
}
return 0 ;
}
static int F_31 ( struct V_98 * V_98 , void * V_99 ,
struct V_100 * V_101 )
{
struct V_12 * V_13 = F_32 ( V_99 ) ;
struct V_104 * V_105 , * V_106 ;
int V_54 ;
V_54 = F_30 ( V_98 , V_99 , V_101 ) ;
if ( V_54 )
return V_54 ;
F_5 ( 1 , L_25 , V_101 -> V_101 ) ;
V_106 = F_33 ( V_13 -> V_43 ,
V_107 ) ;
switch ( V_101 -> V_101 ) {
case V_102 :
V_105 = F_33 ( V_13 -> V_43 ,
V_108 ) ;
if ( ! F_34 ( V_105 ) ) {
F_5 ( 1 , L_26 ) ;
return 0 ;
}
if ( ! F_34 ( V_106 ) ) {
F_5 ( 1 , L_27 ) ;
return 0 ;
}
F_14 ( V_13 -> V_43 , & V_13 -> V_109 -> V_28 ) ;
F_35 ( V_13 -> V_43 ) ;
break;
case V_103 :
F_36 ( V_106 ) ;
break;
default:
return - V_58 ;
}
return 0 ;
}
void F_37 ( struct V_12 * V_13 )
{
F_12 ( & V_13 -> V_69 -> V_110 ) ;
}
void F_38 ( struct V_12 * V_13 )
{
F_9 ( & V_13 -> V_69 -> V_110 ) ;
}
void F_39 ( struct V_12 * V_13 )
{
F_40 ( V_13 ) ;
V_13 -> V_111 = V_112 ;
}
void F_41 ( struct V_12 * V_13 )
{
struct V_11 * V_15 ;
V_13 -> V_43 -> V_113 = & V_13 -> V_69 -> V_114 ;
V_13 -> V_52 . V_43 = V_13 -> V_43 ;
V_13 -> V_52 . V_115 = & V_13 -> V_116 ;
F_42 ( & V_13 -> V_67 , F_22 ) ;
V_13 -> V_117 = V_118 ;
V_13 -> V_119 = V_120 ;
V_13 -> V_121 = V_122 ;
V_13 -> V_123 = V_124 ;
V_15 = & V_13 -> V_15 [ V_16 ] ;
memset ( V_15 , 0 , sizeof( struct V_11 ) ) ;
V_15 -> V_125 = V_126 ;
V_15 -> V_127 = V_128 ;
V_15 -> V_4 = & V_7 [ V_129 ] ;
V_15 -> V_130 = V_131 ;
V_15 -> V_132 [ 0 ] = V_126 * V_128 ;
V_15 -> V_133 [ 0 ] = 0 ;
V_15 = & V_13 -> V_15 [ V_17 ] ;
memset ( V_15 , 0 , sizeof( struct V_11 ) ) ;
V_15 -> V_125 = V_126 ;
V_15 -> V_127 = V_128 ;
V_15 -> V_134 = V_126 ;
V_15 -> V_135 = V_128 ;
V_15 -> V_4 = & V_7 [ V_136 ] ;
V_15 -> V_130 = V_131 ;
F_43 ( & V_15 -> V_134 ,
V_137 ,
V_138 , 4 ,
& V_15 -> V_135 ,
V_139 ,
V_140 , 5 , 6 ) ;
V_15 -> V_132 [ 0 ] = V_15 -> V_134 * V_15 -> V_135 ;
V_15 -> V_133 [ 0 ] = V_15 -> V_134 ;
V_15 -> V_132 [ 1 ] = V_15 -> V_132 [ 0 ] / 2 ;
V_15 -> V_133 [ 1 ] = V_15 -> V_134 ;
}
static int F_44 ( struct V_98 * V_98 , void * V_99 ,
struct V_141 * V_73 )
{
struct V_12 * V_13 = F_32 ( V_99 ) ;
if ( V_13 -> V_111 == V_142 ) {
F_7 ( L_28 ,
V_13 -> V_23 ) ;
return - V_96 ;
}
return F_45 ( V_98 , V_13 -> V_43 , V_73 ) ;
}
static int F_46 ( struct V_98 * V_98 , void * V_99 ,
struct V_141 * V_73 )
{
struct V_12 * V_13 = F_32 ( V_99 ) ;
if ( V_13 -> V_111 == V_142 ) {
F_7 ( L_29 ,
V_13 -> V_23 ) ;
return - V_96 ;
}
return F_47 ( V_98 , V_13 -> V_43 , V_73 ) ;
}
static int F_48 ( struct V_98 * V_98 , void * V_99 ,
struct V_143 * V_144 )
{
F_49 ( V_144 -> V_145 , V_146 , sizeof( V_144 -> V_145 ) ) ;
F_49 ( V_144 -> V_147 , V_148 , sizeof( V_144 -> V_147 ) ) ;
F_49 ( V_144 -> V_149 , V_148 , sizeof( V_144 -> V_149 ) ) ;
return 0 ;
}
static int F_50 ( struct V_150 * V_52 ,
const struct V_151 * V_152 )
{
switch ( V_152 -> type ) {
case V_153 :
return F_51 ( V_52 , V_152 , 2 , NULL ) ;
case V_47 :
return F_52 ( V_52 , V_152 ) ;
default:
return F_53 ( V_52 , V_152 ) ;
}
}
static int F_54 ( struct V_2 * V_3 , struct V_1 * V_4 )
{
struct V_154 * V_155 = & V_3 -> V_4 . V_9 ;
int V_156 ;
V_155 -> V_130 = V_131 ;
if ( V_3 -> type == V_108 ) {
V_155 -> V_157 = 1 ;
V_155 -> V_158 [ 0 ] . V_133 = 0 ;
} else if ( V_3 -> type == V_107 ) {
int V_159 , V_160 ;
V_155 -> V_161 = F_55 ( V_155 -> V_161 ,
V_139 ,
V_140 ) ;
V_155 -> V_162 = F_55 ( V_155 -> V_162 ,
V_137 ,
V_138 ) ;
V_159 = V_155 -> V_162 ;
V_160 = V_155 -> V_161 ;
F_43 ( & V_155 -> V_162 ,
V_137 ,
V_138 , 6 ,
& V_155 -> V_161 ,
V_139 ,
V_140 , 6 , 9 ) ;
if ( V_155 -> V_162 < V_159 &&
( V_155 -> V_162 + 64 ) <= V_138 )
V_155 -> V_162 += 64 ;
if ( V_155 -> V_161 < V_160 &&
( V_155 -> V_161 + 64 ) <= V_140 )
V_155 -> V_161 += 64 ;
F_5 ( 0 ,
L_30 ,
V_159 , V_160 , V_155 -> V_162 ,
V_155 -> V_161 ,
V_155 -> V_162 * V_155 -> V_161 ) ;
V_155 -> V_157 = V_4 -> V_157 ;
V_155 -> V_158 [ 0 ] . V_132 =
V_155 -> V_162 * V_155 -> V_161 ;
V_155 -> V_158 [ 0 ] . V_133 = V_155 -> V_162 ;
if ( V_155 -> V_157 == 2 ) {
V_155 -> V_158 [ 1 ] . V_132 =
( V_155 -> V_162 * V_155 -> V_161 ) / 2 ;
V_155 -> V_158 [ 1 ] . V_133 =
V_155 -> V_162 ;
}
}
for ( V_156 = 0 ; V_156 < V_155 -> V_157 ; V_156 ++ )
memset ( & ( V_155 -> V_158 [ V_156 ] . V_163 [ 0 ] ) , 0x0 ,
sizeof( V_155 -> V_158 [ 0 ] . V_163 ) ) ;
V_155 -> V_89 = 0 ;
memset ( & V_155 -> V_163 , 0x0 , sizeof( V_155 -> V_163 ) ) ;
return 0 ;
}
static int F_56 ( struct V_98 * V_98 , void * V_99 ,
struct V_2 * V_3 )
{
struct V_1 * V_4 ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 ) {
V_3 -> V_4 . V_164 . V_10 = V_7 [ V_136 ] . V_8 ;
V_4 = F_1 ( V_3 ) ;
}
return F_54 ( V_3 , V_4 ) ;
}
static int F_57 ( struct V_98 * V_98 , void * V_99 ,
struct V_2 * V_3 )
{
struct V_154 * V_155 = & V_3 -> V_4 . V_9 ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 ) {
V_3 -> V_4 . V_164 . V_10 = V_7 [ V_129 ] . V_8 ;
V_4 = F_1 ( V_3 ) ;
}
if ( V_155 -> V_158 [ 0 ] . V_132 == 0 ) {
F_7 ( L_31 ) ;
return - V_58 ;
}
return F_54 ( V_3 , V_4 ) ;
}
static int F_58 ( struct V_98 * V_98 , void * V_99 ,
struct V_165 * V_166 )
{
struct V_12 * V_13 = F_32 ( V_99 ) ;
struct V_11 * V_15 ;
if ( V_166 -> type != V_167 )
return - V_58 ;
V_15 = & V_13 -> V_15 [ V_17 ] ;
switch ( V_166 -> V_168 ) {
case V_169 :
V_166 -> V_170 . V_171 = 0 ;
V_166 -> V_170 . V_172 = 0 ;
V_166 -> V_170 . V_162 = V_13 -> V_30 . V_59 ;
V_166 -> V_170 . V_161 = V_13 -> V_30 . V_60 ;
break;
case V_173 :
V_166 -> V_170 . V_171 = 0 ;
V_166 -> V_170 . V_172 = 0 ;
V_166 -> V_170 . V_162 = V_13 -> V_30 . V_61 ;
V_166 -> V_170 . V_161 = V_13 -> V_30 . V_62 ;
break;
case V_174 :
if ( F_6 ( V_13 , V_175 , & ( V_166 -> V_170 ) ) ) {
V_166 -> V_170 . V_171 = 0 ;
V_166 -> V_170 . V_172 = 0 ;
V_166 -> V_170 . V_162 = V_15 -> V_125 ;
V_166 -> V_170 . V_161 = V_15 -> V_127 ;
}
break;
default:
return - V_58 ;
}
if ( V_13 -> V_111 < V_176 ) {
V_166 -> V_170 . V_171 = 0 ;
V_166 -> V_170 . V_172 = 0 ;
V_166 -> V_170 . V_162 = V_15 -> V_125 ;
V_166 -> V_170 . V_161 = V_15 -> V_127 ;
return 0 ;
}
return 0 ;
}
static int F_59 ( struct V_98 * V_98 , void * V_99 ,
struct V_165 * V_166 )
{
struct V_12 * V_13 = F_32 ( V_99 ) ;
if ( V_166 -> type != V_167 )
return - V_58 ;
switch ( V_166 -> V_168 ) {
case V_174 :
V_166 -> V_170 . V_171 = 0 ;
V_166 -> V_170 . V_172 = 0 ;
V_166 -> V_170 . V_162 = V_13 -> V_30 . V_59 ;
V_166 -> V_170 . V_161 = V_13 -> V_30 . V_60 ;
break;
default:
return - V_58 ;
}
return 0 ;
}
static int F_60 ( struct V_98 * V_98 , void * V_99 ,
struct V_2 * V_3 )
{
struct V_12 * V_13 = F_32 ( V_99 ) ;
struct V_154 * V_9 ;
struct V_11 * V_15 ;
int V_54 = 0 ;
struct V_1 * V_4 ;
F_5 ( 3 , L_1 , V_13 -> V_23 ) ;
V_15 = F_2 ( V_13 , V_3 -> type ) ;
if ( ! V_15 )
return - V_58 ;
V_9 = & V_3 -> V_4 . V_9 ;
if ( ( V_3 -> type == V_108 ) &&
F_61 ( & V_13 -> V_43 -> V_177 . V_178 ) ) {
F_7 ( L_32 ) ;
V_54 = - V_179 ;
}
if ( ( V_3 -> type == V_107 ) &&
F_61 ( & V_13 -> V_43 -> V_180 . V_178 ) ) {
F_7 ( L_33 ) ;
V_54 = - V_179 ;
}
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL ) {
if ( V_3 -> type == V_108 ) {
V_3 -> V_4 . V_164 . V_10 =
V_7 [ V_129 ] . V_8 ;
V_4 = F_1 ( V_3 ) ;
} else if ( V_3 -> type == V_107 ) {
V_3 -> V_4 . V_164 . V_10 =
V_7 [ V_136 ] . V_8 ;
V_4 = F_1 ( V_3 ) ;
}
}
V_15 -> V_4 = V_4 ;
F_54 ( V_3 , V_15 -> V_4 ) ;
if ( V_3 -> type == V_108 ) {
V_15 -> V_132 [ 0 ] = V_9 -> V_158 [ 0 ] . V_132 ;
V_15 -> V_134 = V_9 -> V_162 ;
V_15 -> V_135 = V_9 -> V_161 ;
V_13 -> V_117 = V_3 -> V_4 . V_9 . V_117 ;
V_13 -> V_119 = V_3 -> V_4 . V_9 . V_119 ;
V_13 -> V_121 = V_3 -> V_4 . V_9 . V_121 ;
V_13 -> V_123 = V_3 -> V_4 . V_9 . V_123 ;
if ( V_13 -> V_111 == V_112 ) {
V_54 = F_62 ( V_13 , V_15 -> V_4 -> V_8 ) ;
if ( V_54 ) {
F_7 ( L_34 ,
V_13 -> V_23 , V_54 ) ;
return - V_58 ;
}
V_13 -> V_111 = V_181 ;
}
}
return 0 ;
}
static int F_63 ( struct V_98 * V_98 , void * V_99 ,
struct V_182 * V_183 )
{
int V_156 = 0 ;
struct V_12 * V_13 = F_32 ( V_99 ) ;
if ( V_183 -> V_35 != 0 )
return - V_58 ;
for ( V_156 = 0 ; V_156 < V_184 ; ++ V_156 ) {
if ( V_183 -> V_185 != V_186 [ V_156 ] . V_8 )
continue;
V_183 -> type = V_187 ;
V_183 -> V_188 = V_186 [ V_156 ] . V_188 ;
if ( ! ( V_13 -> V_69 -> V_189 &
V_190 ) ) {
F_5 ( 3 , L_35 ) ;
V_183 -> V_188 . V_191 =
V_192 ;
V_183 -> V_188 . V_193 =
V_194 ;
}
F_5 ( 1 , L_36 ,
V_13 -> V_69 -> V_189 ,
V_183 -> V_188 . V_195 ,
V_183 -> V_188 . V_191 ,
V_183 -> V_188 . V_196 ,
V_183 -> V_188 . V_197 ,
V_183 -> V_188 . V_193 ,
V_183 -> V_188 . V_198 ) ;
return 0 ;
}
return - V_58 ;
}
static int F_64 ( struct V_199 * V_3 , bool V_200 )
{
struct V_1 * V_4 ;
int V_156 , V_201 = 0 ;
for ( V_156 = 0 ; V_156 < V_6 ; V_156 ++ ) {
if ( V_200 && ( V_7 [ V_156 ] . type != V_202 ) )
continue;
if ( ! V_200 &&
( V_7 [ V_156 ] . type != V_203 ) )
continue;
if ( V_201 == V_3 -> V_35 )
break;
++ V_201 ;
}
if ( V_156 == V_6 )
return - V_58 ;
V_4 = & V_7 [ V_156 ] ;
V_3 -> V_10 = V_4 -> V_8 ;
return 0 ;
}
static int F_65 ( struct V_98 * V_98 , void * V_204 ,
struct V_199 * V_3 )
{
return F_64 ( V_3 , false ) ;
}
static int F_66 ( struct V_98 * V_98 , void * V_99 ,
struct V_199 * V_3 )
{
return F_64 ( V_3 , true ) ;
}
static int F_67 ( struct V_98 * V_98 , void * V_99 ,
struct V_2 * V_3 )
{
struct V_12 * V_13 = F_32 ( V_99 ) ;
struct V_154 * V_9 = & V_3 -> V_4 . V_9 ;
struct V_104 * V_205 ;
struct V_11 * V_15 ;
V_205 = F_33 ( V_13 -> V_43 , V_3 -> type ) ;
if ( ! V_205 ) {
F_7 ( L_37 , V_3 -> type ) ;
return - V_58 ;
}
V_15 = F_2 ( V_13 , V_3 -> type ) ;
V_9 -> V_130 = V_131 ;
V_9 -> V_117 = V_13 -> V_117 ;
V_9 -> V_119 = V_13 -> V_119 ;
V_9 -> V_121 = V_13 -> V_121 ;
V_9 -> V_123 = V_13 -> V_123 ;
if ( ( V_3 -> type == V_107 ) &&
( V_13 -> V_111 >= V_176 ) ) {
V_15 -> V_132 [ 0 ] = V_13 -> V_30 . V_31 +
V_13 -> V_30 . V_85 ;
V_15 -> V_132 [ 1 ] = V_13 -> V_30 . V_32 +
V_13 -> V_30 . V_87 ;
V_15 -> V_133 [ 0 ] = V_13 -> V_57 . V_61 ;
V_15 -> V_133 [ 1 ] = V_13 -> V_57 . V_61 ;
V_15 -> V_134 = V_13 -> V_30 . V_61 ;
V_15 -> V_135 = V_13 -> V_30 . V_62 ;
V_9 -> V_162 = V_15 -> V_134 ;
V_9 -> V_161 = V_15 -> V_135 ;
V_9 -> V_157 = V_15 -> V_4 -> V_157 ;
V_9 -> V_10 = V_15 -> V_4 -> V_8 ;
V_9 -> V_158 [ 0 ] . V_133 = V_15 -> V_133 [ 0 ] ;
V_9 -> V_158 [ 0 ] . V_132 = V_15 -> V_132 [ 0 ] ;
V_9 -> V_158 [ 1 ] . V_133 = V_15 -> V_133 [ 1 ] ;
V_9 -> V_158 [ 1 ] . V_132 = V_15 -> V_132 [ 1 ] ;
} else if ( V_3 -> type == V_108 ) {
V_9 -> V_162 = V_15 -> V_125 ;
V_9 -> V_161 = V_15 -> V_127 ;
V_9 -> V_158 [ 0 ] . V_133 = V_15 -> V_133 [ 0 ] ;
V_9 -> V_158 [ 0 ] . V_132 = V_15 -> V_132 [ 0 ] ;
V_9 -> V_10 = V_15 -> V_4 -> V_8 ;
V_9 -> V_157 = V_15 -> V_4 -> V_157 ;
} else {
V_9 -> V_162 = V_15 -> V_134 ;
V_9 -> V_161 = V_15 -> V_135 ;
V_9 -> V_157 = V_15 -> V_4 -> V_157 ;
V_9 -> V_10 = V_15 -> V_4 -> V_8 ;
V_9 -> V_158 [ 0 ] . V_133 = V_15 -> V_133 [ 0 ] ;
V_9 -> V_158 [ 0 ] . V_132 = V_15 -> V_132 [ 0 ] ;
V_9 -> V_158 [ 1 ] . V_133 = V_15 -> V_133 [ 1 ] ;
V_9 -> V_158 [ 1 ] . V_132 = V_15 -> V_132 [ 1 ] ;
F_5 ( 1 , L_38 ,
V_13 -> V_23 , V_3 -> type , V_13 -> V_111 ) ;
}
return 0 ;
}
static int F_68 ( struct V_104 * V_205 ,
unsigned int * V_206 ,
unsigned int * V_207 ,
unsigned int V_208 [] ,
struct V_209 * V_210 [] )
{
struct V_12 * V_13 = F_69 ( V_205 ) ;
struct V_11 * V_15 ;
unsigned int V_156 ;
V_15 = F_2 ( V_13 , V_205 -> type ) ;
if ( V_15 == NULL ) {
F_7 ( L_39 , V_205 -> type ) ;
return - V_58 ;
}
if ( * V_207 ) {
for ( V_156 = 0 ; V_156 < * V_207 ; V_156 ++ ) {
if ( V_208 [ V_156 ] < V_15 -> V_132 [ V_156 ] )
return - V_58 ;
}
} else {
if ( V_205 -> type == V_107 )
* V_207 = 2 ;
else
* V_207 = 1 ;
for ( V_156 = 0 ; V_156 < * V_207 ; V_156 ++ )
V_208 [ V_156 ] = V_15 -> V_132 [ V_156 ] ;
}
F_5 ( 1 ,
L_40 ,
V_13 -> V_23 , V_205 -> type , * V_207 , * V_206 ,
V_208 [ 0 ] , V_208 [ 1 ] ) ;
return 0 ;
}
static int F_70 ( struct V_18 * V_28 )
{
struct V_12 * V_13 = F_69 ( V_28 -> V_104 ) ;
struct V_11 * V_15 ;
int V_156 ;
F_5 ( 3 , L_41 ,
V_13 -> V_23 , V_28 -> V_104 -> type , V_28 -> V_35 ) ;
V_15 = F_2 ( V_13 , V_28 -> V_104 -> type ) ;
for ( V_156 = 0 ; V_156 < V_15 -> V_4 -> V_157 ; V_156 ++ ) {
if ( F_71 ( V_28 , V_156 ) < V_15 -> V_132 [ V_156 ] ) {
F_7 ( L_42 ,
V_156 , F_71 ( V_28 , V_156 ) ,
V_15 -> V_132 [ V_156 ] ) ;
}
}
return 0 ;
}
static void F_72 ( struct V_18 * V_28 )
{
struct V_18 * V_70 ;
struct V_72 V_211 ;
bool V_53 = false ;
int V_54 = 0 ;
unsigned int V_55 = 1 ;
struct V_12 * V_13 = F_69 ( V_28 -> V_104 ) ;
struct V_77 * V_212 = NULL ;
struct V_21 * V_73 = NULL ;
F_5 ( 3 , L_43 ,
V_13 -> V_23 , V_28 -> V_104 -> type ,
V_28 -> V_35 , V_28 ) ;
if ( V_28 -> V_104 -> type != V_108 ) {
V_212 = F_73 ( V_28 ) ;
V_73 = F_8 ( V_212 , struct V_21 , V_28 ) ;
F_9 ( & V_13 -> V_26 ) ;
if ( V_73 -> V_27 == false ) {
F_14 ( V_13 -> V_43 , V_212 ) ;
V_73 -> V_36 = true ;
V_73 -> V_41 = true ;
V_73 -> V_33 = false ;
} else {
V_73 -> V_36 = false ;
V_73 -> V_41 = true ;
V_73 -> V_33 = false ;
}
F_12 ( & V_13 -> V_26 ) ;
return;
}
F_14 ( V_13 -> V_43 , F_73 ( V_28 ) ) ;
if ( V_13 -> V_111 != V_181 ) {
F_5 ( 3 , L_44 ,
V_13 -> V_23 , V_13 -> V_111 ) ;
return;
}
V_70 = F_23 ( V_13 -> V_43 ) ;
if ( ! V_70 ) {
F_7 ( L_45 ) ;
return;
}
V_212 = F_73 ( V_70 ) ;
V_73 = F_8 ( V_212 , struct V_21 , V_28 ) ;
if ( V_73 -> V_88 ) {
F_7 ( L_46 ) ;
F_28 ( V_13 -> V_43 ) ;
return;
}
V_211 . V_82 = F_26 ( V_70 , 0 ) ;
V_211 . V_83 = F_27 ( V_70 , 0 ) ;
V_211 . V_84 = ( V_91 ) V_70 -> V_92 [ 0 ] . V_93 ;
F_5 ( 2 ,
L_47 ,
V_13 -> V_23 , V_70 -> V_35 ,
V_211 . V_82 , & V_211 . V_83 ,
V_211 . V_84 ) ;
V_54 = F_20 ( V_13 , & V_211 , NULL , & V_53 ) ;
if ( V_54 || ! V_53 ) {
V_70 = F_28 ( V_13 -> V_43 ) ;
if ( V_54 == - V_96 ) {
F_7 ( L_48 ,
V_13 -> V_23 ) ;
V_13 -> V_111 = V_142 ;
F_11 ( F_73 ( V_70 ) ,
V_97 ) ;
} else {
F_11 ( F_73 ( V_70 ) ,
V_37 ) ;
}
F_5 ( V_54 ? 0 : 1 ,
L_49 ,
V_13 -> V_23 , V_70 -> V_35 ,
V_211 . V_84 , V_54 , V_53 ) ;
return;
}
if ( F_6 ( V_13 , V_56 , & V_13 -> V_30 ) ) {
F_7 ( L_12 ,
V_13 -> V_23 ) ;
return;
}
V_13 -> V_57 = V_13 -> V_30 ;
V_13 -> V_15 [ V_17 ] . V_132 [ 0 ] =
V_13 -> V_30 . V_31 +
V_13 -> V_30 . V_85 ;
V_13 -> V_15 [ V_17 ] . V_133 [ 0 ] =
V_13 -> V_30 . V_61 ;
V_13 -> V_15 [ V_17 ] . V_132 [ 1 ] =
V_13 -> V_30 . V_32 +
V_13 -> V_30 . V_87 ;
V_13 -> V_15 [ V_17 ] . V_133 [ 1 ] = V_13 -> V_30 . V_61 ;
F_5 ( 2 , L_50 ,
V_13 -> V_23 ,
V_13 -> V_30 . V_61 , V_13 -> V_30 . V_62 ,
V_13 -> V_30 . V_59 , V_13 -> V_30 . V_60 ,
V_13 -> V_15 [ V_17 ] . V_132 [ 0 ] ,
V_13 -> V_15 [ V_17 ] . V_132 [ 1 ] ) ;
V_54 = F_6 ( V_13 , V_63 , & V_55 ) ;
if ( V_55 == 0 )
F_7 ( L_51 , V_13 -> V_23 , V_54 ) ;
V_13 -> V_64 = V_55 ;
V_13 -> V_111 = V_176 ;
F_5 ( 1 , L_52 , V_13 -> V_23 , V_13 -> V_64 ) ;
}
static void F_74 ( struct V_18 * V_28 )
{
struct V_12 * V_13 = F_69 ( V_28 -> V_104 ) ;
struct V_77 * V_212 ;
struct V_21 * V_73 ;
bool V_213 ;
V_212 = F_8 ( V_28 , struct V_77 , V_29 ) ;
V_73 = F_8 ( V_212 , struct V_21 , V_28 ) ;
F_9 ( & V_13 -> V_26 ) ;
if ( V_28 -> V_104 -> type == V_107 ) {
V_73 -> V_41 = false ;
V_73 -> V_36 = false ;
}
V_213 = V_73 -> error ;
F_12 ( & V_13 -> V_26 ) ;
if ( V_213 ) {
F_7 ( L_53 ) ;
V_13 -> V_111 = V_142 ;
}
}
static int F_75 ( struct V_18 * V_28 )
{
struct V_77 * V_212 = F_8 ( V_28 ,
struct V_77 , V_29 ) ;
struct V_21 * V_73 = F_8 ( V_212 ,
struct V_21 , V_28 ) ;
if ( V_28 -> V_104 -> type == V_107 ) {
V_73 -> V_27 = false ;
V_73 -> V_33 = false ;
V_73 -> V_41 = false ;
} else {
V_73 -> V_88 = false ;
}
return 0 ;
}
static int F_76 ( struct V_104 * V_178 , unsigned int V_214 )
{
struct V_12 * V_13 = F_69 ( V_178 ) ;
if ( V_13 -> V_111 == V_215 )
V_13 -> V_111 = V_176 ;
return 0 ;
}
static void F_77 ( struct V_104 * V_178 )
{
struct V_18 * V_70 = NULL , * V_71 = NULL ;
struct V_12 * V_13 = F_69 ( V_178 ) ;
F_5 ( 3 , L_54 ,
V_13 -> V_23 , V_178 -> type , V_13 -> V_111 , V_13 -> V_38 ) ;
if ( V_178 -> type == V_108 ) {
while ( ( V_70 = F_28 ( V_13 -> V_43 ) ) ) {
struct V_77 * V_212 =
F_73 ( V_70 ) ;
struct V_21 * V_216 = F_8 (
V_212 , struct V_21 , V_28 ) ;
if ( ! V_216 -> V_88 )
F_11 ( V_212 ,
V_97 ) ;
}
return;
}
if ( V_13 -> V_111 >= V_176 ) {
V_13 -> V_30 = V_13 -> V_57 ;
F_5 ( 2 ,
L_14 ,
V_13 -> V_23 , V_13 -> V_57 . V_59 ,
V_13 -> V_57 . V_60 ,
V_13 -> V_30 . V_59 , V_13 -> V_30 . V_60 ,
V_13 -> V_57 . V_61 ,
V_13 -> V_57 . V_62 ) ;
F_19 ( V_13 ) ;
}
V_13 -> V_111 = V_215 ;
while ( ( V_71 = F_29 ( V_13 -> V_43 ) ) ) {
F_10 ( V_71 , 0 , 0 ) ;
F_10 ( V_71 , 1 , 0 ) ;
F_11 ( F_73 ( V_71 ) ,
V_97 ) ;
}
}
static void F_78 ( void * V_99 )
{
struct V_12 * V_13 = V_99 ;
struct V_68 * V_69 = V_13 -> V_69 ;
F_79 ( V_69 -> V_217 , & V_13 -> V_67 ) ;
}
static int F_80 ( void * V_218 )
{
struct V_12 * V_13 = V_218 ;
F_5 ( 3 , L_1 , V_13 -> V_23 ) ;
if ( V_13 -> V_111 == V_142 )
return 0 ;
if ( ( V_13 -> V_57 . V_59 != V_13 -> V_30 . V_59 ) ||
( V_13 -> V_57 . V_60 != V_13 -> V_30 . V_60 ) )
return 0 ;
if ( V_13 -> V_111 != V_176 )
return 0 ;
return 1 ;
}
static void F_81 ( void * V_99 )
{
struct V_12 * V_13 = V_99 ;
V_13 -> V_111 = V_142 ;
}
static int F_82 ( struct V_219 * V_220 )
{
struct V_12 * V_13 = F_83 ( V_220 ) ;
int V_54 = 0 ;
switch ( V_220 -> V_23 ) {
case V_221 :
if ( V_13 -> V_111 >= V_176 ) {
V_220 -> V_222 = V_13 -> V_64 ;
} else {
F_5 ( 0 , L_55 ) ;
V_220 -> V_222 = 0 ;
}
break;
default:
V_54 = - V_58 ;
}
return V_54 ;
}
int F_84 ( struct V_12 * V_13 )
{
struct V_219 * V_220 ;
F_85 ( & V_13 -> V_116 , 1 ) ;
V_220 = F_86 ( & V_13 -> V_116 ,
& V_223 ,
V_221 ,
0 , 32 , 1 , 1 ) ;
V_220 -> V_89 |= V_224 ;
if ( V_13 -> V_116 . error ) {
F_7 ( L_56 ,
V_13 -> V_116 . error ) ;
return V_13 -> V_116 . error ;
}
F_87 ( & V_13 -> V_116 ) ;
return 0 ;
}
static void F_88 ( void * V_218 )
{
struct V_12 * V_13 = V_218 ;
F_5 ( 3 , L_1 , V_13 -> V_23 ) ;
F_9 ( & V_13 -> V_69 -> V_114 ) ;
}
static void F_89 ( void * V_218 )
{
struct V_12 * V_13 = V_218 ;
F_5 ( 3 , L_1 , V_13 -> V_23 ) ;
F_12 ( & V_13 -> V_69 -> V_114 ) ;
}
int F_90 ( void * V_99 , struct V_104 * V_105 ,
struct V_104 * V_106 )
{
struct V_12 * V_13 = V_99 ;
int V_54 = 0 ;
F_5 ( 3 , L_1 , V_13 -> V_23 ) ;
V_105 -> type = V_108 ;
V_105 -> V_225 = V_226 | V_227 ;
V_105 -> V_228 = V_13 ;
V_105 -> V_229 = sizeof( struct V_21 ) ;
V_105 -> V_230 = & V_231 ;
V_105 -> V_232 = & V_233 ;
V_105 -> V_234 = V_235 ;
V_105 -> V_26 = & V_13 -> V_69 -> V_114 ;
V_105 -> V_69 = & V_13 -> V_69 -> V_236 -> V_69 ;
V_54 = F_91 ( V_105 ) ;
if ( V_54 ) {
F_7 ( L_57 ) ;
return V_54 ;
}
V_106 -> type = V_107 ;
V_106 -> V_225 = V_226 | V_227 ;
V_106 -> V_228 = V_13 ;
V_106 -> V_229 = sizeof( struct V_21 ) ;
V_106 -> V_230 = & V_231 ;
V_106 -> V_232 = & V_233 ;
V_106 -> V_234 = V_235 ;
V_106 -> V_26 = & V_13 -> V_69 -> V_114 ;
V_106 -> V_69 = & V_13 -> V_69 -> V_236 -> V_69 ;
V_54 = F_91 ( V_106 ) ;
if ( V_54 ) {
F_92 ( V_105 ) ;
F_7 ( L_58 ) ;
}
return V_54 ;
}
