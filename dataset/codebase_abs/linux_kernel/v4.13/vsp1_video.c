static struct V_1 *
F_1 ( struct V_2 * V_3 , T_1 * V_4 )
{
struct V_2 * V_5 ;
V_5 = F_2 ( V_3 ) ;
if ( ! V_5 || ! F_3 ( V_5 -> V_6 ) )
return NULL ;
if ( V_4 )
* V_4 = V_5 -> V_7 ;
return F_4 ( V_5 -> V_6 ) ;
}
static int F_5 ( struct V_8 * V_9 )
{
struct V_10 V_11 ;
struct V_1 * V_12 ;
int V_13 ;
V_12 = F_1 ( & V_9 -> V_4 , & V_11 . V_4 ) ;
if ( V_12 == NULL )
return - V_14 ;
V_11 . V_15 = V_16 ;
V_13 = F_6 ( V_12 , V_4 , V_17 , NULL , & V_11 ) ;
if ( V_13 < 0 )
return V_13 == - V_18 ? - V_14 : V_13 ;
if ( V_9 -> V_19 -> V_20 -> V_21 != V_11 . V_22 . V_23 ||
V_9 -> V_19 -> V_22 . V_24 != V_11 . V_22 . V_24 ||
V_9 -> V_19 -> V_22 . V_25 != V_11 . V_22 . V_25 )
return - V_14 ;
return 0 ;
}
static int F_7 ( struct V_8 * V_9 ,
struct V_26 * V_27 ,
const struct V_28 * * V_20 )
{
static const T_1 V_29 [] [ 2 ] = {
{ V_30 , V_31 } ,
{ V_32 , V_33 } ,
{ V_34 , V_35 } ,
{ V_36 , V_37 } ,
} ;
const struct V_28 * V_38 ;
unsigned int V_25 = V_27 -> V_25 ;
unsigned int V_24 = V_27 -> V_24 ;
unsigned int V_39 ;
for ( V_39 = 0 ; V_39 < F_8 ( V_29 ) ; ++ V_39 ) {
if ( V_29 [ V_39 ] [ 0 ] == V_27 -> V_40 ) {
V_27 -> V_40 = V_29 [ V_39 ] [ 1 ] ;
break;
}
}
V_38 = F_9 ( V_9 -> V_41 , V_27 -> V_40 ) ;
if ( V_38 == NULL )
V_38 = F_9 ( V_9 -> V_41 , V_42 ) ;
V_27 -> V_40 = V_38 -> V_43 ;
V_27 -> V_44 = V_45 ;
V_27 -> V_46 = V_47 ;
if ( V_38 -> V_43 == V_48 ||
V_38 -> V_43 == V_49 )
V_27 -> V_50 = V_51 ;
memset ( V_27 -> V_52 , 0 , sizeof( V_27 -> V_52 ) ) ;
V_25 = F_10 ( V_25 , V_38 -> V_53 ) ;
V_24 = F_10 ( V_24 , V_38 -> V_54 ) ;
V_27 -> V_25 = F_11 ( V_25 , V_55 , V_56 ) ;
V_27 -> V_24 = F_11 ( V_24 , V_57 ,
V_58 ) ;
for ( V_39 = 0 ; V_39 < F_12 ( V_38 -> V_59 , 2U ) ; ++ V_39 ) {
unsigned int V_53 = V_39 > 0 ? V_38 -> V_53 : 1 ;
unsigned int V_54 = V_39 > 0 ? V_38 -> V_54 : 1 ;
unsigned int V_60 = 128 ;
unsigned int V_61 ;
V_61 = F_13 (unsigned int, pix->plane_fmt[i].bytesperline,
pix->width / hsub * info->bpp[i] / 8 ,
round_down(65535U, align)) ;
V_27 -> V_62 [ V_39 ] . V_63 = F_14 ( V_61 , V_60 ) ;
V_27 -> V_62 [ V_39 ] . V_64 = V_27 -> V_62 [ V_39 ] . V_63
* V_27 -> V_24 / V_54 ;
}
if ( V_38 -> V_59 == 3 ) {
V_27 -> V_62 [ 2 ] . V_63 = V_27 -> V_62 [ 1 ] . V_63 ;
V_27 -> V_62 [ 2 ] . V_64 = V_27 -> V_62 [ 1 ] . V_64 ;
}
V_27 -> V_65 = V_38 -> V_59 ;
if ( V_20 )
* V_20 = V_38 ;
return 0 ;
}
static void F_15 ( struct V_66 * V_67 )
{
struct V_68 * V_41 = V_67 -> V_69 -> V_6 . V_41 ;
const struct V_70 * V_22 ;
struct V_71 * V_6 ;
unsigned int V_72 ;
V_22 = F_16 ( & V_67 -> V_69 -> V_6 ,
V_67 -> V_69 -> V_6 . V_73 ,
V_74 ) ;
V_72 = V_22 -> V_25 ;
if ( V_41 -> V_38 -> V_75 == 2 ) {
V_67 -> V_72 = V_72 ;
V_67 -> V_76 = 1 ;
return;
}
F_17 (entity, &pipe->entities, list_pipe) {
unsigned int V_77 = V_56 ;
if ( V_6 -> V_78 -> V_79 ) {
V_77 = V_6 -> V_78 -> V_79 ( V_6 , V_67 ) ;
if ( V_77 )
V_72 = F_12 ( V_72 , V_77 ) ;
}
}
V_67 -> V_72 = V_72 ;
V_67 -> V_76 = F_18 ( V_22 -> V_25 , V_72 ) ;
}
static struct V_80 F_19 ( struct V_66 * V_67 ,
unsigned int V_72 ,
unsigned int V_7 )
{
const struct V_70 * V_22 ;
struct V_80 V_81 ;
unsigned int V_82 ;
V_22 = F_16 ( & V_67 -> V_69 -> V_6 ,
V_67 -> V_69 -> V_6 . V_73 ,
V_74 ) ;
if ( V_67 -> V_76 <= 1 ) {
V_81 . V_83 = 0 ;
V_81 . V_84 = 0 ;
V_81 . V_25 = V_22 -> V_25 ;
V_81 . V_24 = V_22 -> V_24 ;
return V_81 ;
}
V_81 . V_83 = V_7 * V_72 ;
V_81 . V_84 = 0 ;
V_81 . V_25 = V_72 ;
V_81 . V_24 = V_22 -> V_24 ;
V_82 = V_22 -> V_25 % V_72 ;
if ( V_82 ) {
unsigned int V_76 = V_67 -> V_76 - 1 ;
if ( V_82 < V_72 / 2 ) {
if ( V_7 == V_76 - 1 ) {
V_81 . V_25 = V_72 / 2 ;
} else if ( V_7 == V_76 ) {
V_81 . V_25 = ( V_72 / 2 ) + V_82 ;
V_81 . V_83 -= V_72 / 2 ;
}
} else if ( V_7 == V_76 ) {
V_81 . V_25 = V_82 ;
}
}
return V_81 ;
}
static struct V_85 *
F_20 ( struct V_8 * V_9 )
{
struct V_66 * V_67 = V_9 -> V_19 -> V_67 ;
struct V_85 * V_86 = NULL ;
struct V_85 * V_87 ;
unsigned long V_88 ;
unsigned int V_39 ;
F_21 ( & V_9 -> V_89 , V_88 ) ;
if ( F_22 ( & V_9 -> V_90 ) ) {
F_23 ( & V_9 -> V_89 , V_88 ) ;
return NULL ;
}
V_87 = F_24 ( & V_9 -> V_90 ,
struct V_85 , V_91 ) ;
if ( V_67 -> V_92 && F_25 ( & V_9 -> V_90 ) ) {
F_23 ( & V_9 -> V_89 , V_88 ) ;
return V_87 ;
}
F_26 ( & V_87 -> V_91 ) ;
if ( ! F_22 ( & V_9 -> V_90 ) )
V_86 = F_24 ( & V_9 -> V_90 ,
struct V_85 , V_91 ) ;
F_23 ( & V_9 -> V_89 , V_88 ) ;
V_87 -> V_93 . V_94 = V_67 -> V_94 ;
V_87 -> V_93 . V_95 . V_96 = F_27 () ;
for ( V_39 = 0 ; V_39 < V_87 -> V_93 . V_95 . V_65 ; ++ V_39 )
F_28 ( & V_87 -> V_93 . V_95 , V_39 ,
F_29 ( & V_87 -> V_93 . V_95 , V_39 ) ) ;
F_30 ( & V_87 -> V_93 . V_95 , V_97 ) ;
return V_86 ;
}
static void F_31 ( struct V_66 * V_67 ,
struct V_98 * V_19 )
{
struct V_8 * V_9 = V_19 -> V_9 ;
struct V_85 * V_93 ;
V_93 = F_20 ( V_9 ) ;
if ( V_93 == NULL )
return;
V_9 -> V_19 -> V_99 = V_93 -> V_99 ;
V_67 -> V_100 |= 1 << V_9 -> V_101 ;
}
static void F_32 ( struct V_66 * V_67 ,
struct V_102 * V_103 )
{
struct V_71 * V_6 ;
V_67 -> V_81 = F_19 ( V_67 , V_67 -> V_72 ,
V_67 -> V_104 ) ;
F_17 (entity, &pipe->entities, list_pipe) {
if ( V_6 -> V_78 -> V_105 )
V_6 -> V_78 -> V_105 ( V_6 , V_67 , V_103 ,
V_106 ) ;
}
}
static void F_33 ( struct V_66 * V_67 )
{
struct V_68 * V_41 = V_67 -> V_69 -> V_6 . V_41 ;
struct V_71 * V_6 ;
if ( ! V_67 -> V_103 )
V_67 -> V_103 = F_34 ( V_67 -> V_69 -> V_107 ) ;
F_17 (entity, &pipe->entities, list_pipe) {
if ( V_6 -> V_78 -> V_105 )
V_6 -> V_78 -> V_105 ( V_6 , V_67 , V_67 -> V_103 ,
V_108 ) ;
}
V_67 -> V_104 = 0 ;
F_32 ( V_67 , V_67 -> V_103 ) ;
for ( V_67 -> V_104 = 1 ;
V_67 -> V_104 < V_67 -> V_76 ;
V_67 -> V_104 ++ ) {
struct V_102 * V_103 ;
V_103 = F_34 ( V_67 -> V_69 -> V_107 ) ;
if ( ! V_103 ) {
F_35 ( V_41 -> V_109 , L_1 ) ;
break;
}
F_32 ( V_67 , V_103 ) ;
F_36 ( V_67 -> V_103 , V_103 ) ;
}
F_37 ( V_67 -> V_103 ) ;
V_67 -> V_103 = NULL ;
F_38 ( V_67 ) ;
}
static void F_39 ( struct V_66 * V_67 )
{
struct V_68 * V_41 = V_67 -> V_69 -> V_6 . V_41 ;
enum V_110 V_111 ;
unsigned long V_88 ;
unsigned int V_39 ;
F_21 ( & V_67 -> V_89 , V_88 ) ;
for ( V_39 = 0 ; V_39 < V_41 -> V_38 -> V_112 ; ++ V_39 ) {
if ( ! V_67 -> V_113 [ V_39 ] )
continue;
F_31 ( V_67 , V_67 -> V_113 [ V_39 ] ) ;
}
F_31 ( V_67 , V_67 -> V_69 ) ;
V_111 = V_67 -> V_111 ;
V_67 -> V_111 = V_114 ;
if ( V_111 == V_115 )
F_40 ( & V_67 -> V_116 ) ;
else if ( F_41 ( V_67 ) )
F_33 ( V_67 ) ;
F_23 ( & V_67 -> V_89 , V_88 ) ;
}
static int F_42 ( struct V_66 * V_67 ,
struct V_98 * V_117 ,
struct V_98 * V_69 )
{
struct V_118 V_119 ;
struct V_71 * V_6 ;
struct V_2 * V_4 ;
bool V_120 = false ;
int V_13 ;
V_13 = F_43 ( & V_119 , & V_117 -> V_6 . V_41 -> V_121 ) ;
if ( V_13 < 0 )
return V_13 ;
V_4 = F_44 ( & V_117 -> V_6 . V_122 [ V_123 ] ) ;
while ( 1 ) {
if ( V_4 == NULL ) {
V_13 = - V_124 ;
goto V_125;
}
if ( ! F_3 ( V_4 -> V_6 ) ) {
V_13 = - V_124 ;
goto V_125;
}
V_6 = F_45 (
F_4 ( V_4 -> V_6 ) ) ;
if ( V_6 -> type == V_126 ) {
struct V_127 * V_128 = F_46 ( & V_6 -> V_12 ) ;
V_128 -> V_113 [ V_4 -> V_7 ] . V_129 = V_117 ;
V_117 -> V_130 = V_4 -> V_7 ;
V_120 = true ;
}
if ( V_6 -> type == V_131 )
break;
if ( F_47 ( & V_119 ,
& V_6 -> V_12 . V_6 ) ) {
V_13 = - V_124 ;
goto V_125;
}
if ( V_6 -> type == V_132 ) {
if ( V_67 -> V_133 ) {
V_13 = - V_124 ;
goto V_125;
}
V_67 -> V_133 = V_6 ;
V_67 -> V_134 = V_120 ? V_67 -> V_128
: & V_117 -> V_6 ;
}
V_4 = & V_6 -> V_122 [ V_6 -> V_135 ] ;
V_4 = F_44 ( V_4 ) ;
}
if ( V_6 != & V_69 -> V_6 )
V_13 = - V_124 ;
V_125:
F_48 ( & V_119 ) ;
return V_13 ;
}
static int F_49 ( struct V_66 * V_67 ,
struct V_8 * V_9 )
{
struct V_136 V_137 ;
struct V_138 * V_6 = & V_9 -> V_9 . V_6 ;
struct V_139 * V_140 = V_6 -> V_141 . V_140 ;
unsigned int V_39 ;
int V_13 ;
V_13 = F_50 ( & V_137 , V_140 ) ;
if ( V_13 )
return V_13 ;
F_51 ( & V_137 , V_6 ) ;
while ( ( V_6 = F_52 ( & V_137 ) ) ) {
struct V_1 * V_12 ;
struct V_98 * V_19 ;
struct V_71 * V_142 ;
if ( ! F_3 ( V_6 ) )
continue;
V_12 = F_4 ( V_6 ) ;
V_142 = F_45 ( V_12 ) ;
F_53 ( & V_142 -> V_143 , & V_67 -> V_144 ) ;
if ( V_142 -> type == V_145 ) {
V_19 = F_54 ( V_12 ) ;
V_67 -> V_113 [ V_19 -> V_6 . V_7 ] = V_19 ;
V_19 -> V_9 -> V_101 = ++ V_67 -> V_146 ;
V_19 -> V_67 = V_67 ;
} else if ( V_142 -> type == V_131 ) {
V_19 = F_54 ( V_12 ) ;
V_67 -> V_69 = V_19 ;
V_19 -> V_9 -> V_101 = 0 ;
V_19 -> V_67 = V_67 ;
} else if ( V_142 -> type == V_147 ) {
V_67 -> V_92 = V_142 ;
} else if ( V_142 -> type == V_126 ) {
V_67 -> V_128 = V_142 ;
} else if ( V_142 -> type == V_148 ) {
struct V_149 * V_150 = F_55 ( V_12 ) ;
V_67 -> V_150 = V_142 ;
V_150 -> V_151 . V_67 = V_67 ;
} else if ( V_142 -> type == V_152 ) {
struct V_153 * V_154 = F_56 ( V_12 ) ;
V_67 -> V_154 = V_142 ;
V_154 -> V_151 . V_67 = V_67 ;
}
}
F_57 ( & V_137 ) ;
if ( V_67 -> V_146 == 0 || ! V_67 -> V_69 )
return - V_124 ;
for ( V_39 = 0 ; V_39 < V_9 -> V_41 -> V_38 -> V_112 ; ++ V_39 ) {
if ( ! V_67 -> V_113 [ V_39 ] )
continue;
V_13 = F_42 ( V_67 , V_67 -> V_113 [ V_39 ] ,
V_67 -> V_69 ) ;
if ( V_13 < 0 )
return V_13 ;
}
return 0 ;
}
static int F_58 ( struct V_66 * V_67 ,
struct V_8 * V_9 )
{
F_59 ( V_67 ) ;
V_67 -> V_155 = F_39 ;
return F_49 ( V_67 , V_9 ) ;
}
static struct V_66 * F_60 ( struct V_8 * V_9 )
{
struct V_66 * V_67 ;
int V_13 ;
if ( ! V_9 -> V_19 -> V_67 ) {
V_67 = F_61 ( sizeof( * V_67 ) , V_156 ) ;
if ( ! V_67 )
return F_62 ( - V_157 ) ;
V_13 = F_58 ( V_67 , V_9 ) ;
if ( V_13 < 0 ) {
F_63 ( V_67 ) ;
F_64 ( V_67 ) ;
return F_62 ( V_13 ) ;
}
} else {
V_67 = V_9 -> V_19 -> V_67 ;
F_65 ( & V_67 -> V_158 ) ;
}
return V_67 ;
}
static void F_66 ( struct V_158 * V_158 )
{
struct V_66 * V_67 = F_67 ( V_158 , F_68 ( * V_67 ) , V_158 ) ;
F_63 ( V_67 ) ;
F_64 ( V_67 ) ;
}
static void F_69 ( struct V_66 * V_67 )
{
struct V_139 * V_140 = & V_67 -> V_69 -> V_6 . V_41 -> V_121 ;
F_70 ( & V_140 -> V_159 ) ;
F_71 ( & V_67 -> V_158 , F_66 ) ;
F_72 ( & V_140 -> V_159 ) ;
}
static int
F_73 ( struct V_160 * V_161 ,
unsigned int * V_162 , unsigned int * V_163 ,
unsigned int V_164 [] , struct V_165 * V_166 [] )
{
struct V_8 * V_9 = F_74 ( V_161 ) ;
const struct V_26 * V_22 = & V_9 -> V_19 -> V_22 ;
unsigned int V_39 ;
if ( * V_163 ) {
if ( * V_163 != V_22 -> V_65 )
return - V_14 ;
for ( V_39 = 0 ; V_39 < * V_163 ; V_39 ++ )
if ( V_164 [ V_39 ] < V_22 -> V_62 [ V_39 ] . V_64 )
return - V_14 ;
return 0 ;
}
* V_163 = V_22 -> V_65 ;
for ( V_39 = 0 ; V_39 < V_22 -> V_65 ; ++ V_39 )
V_164 [ V_39 ] = V_22 -> V_62 [ V_39 ] . V_64 ;
return 0 ;
}
static int F_75 ( struct V_167 * V_168 )
{
struct V_169 * V_170 = F_76 ( V_168 ) ;
struct V_8 * V_9 = F_74 ( V_168 -> V_160 ) ;
struct V_85 * V_93 = F_77 ( V_170 ) ;
const struct V_26 * V_22 = & V_9 -> V_19 -> V_22 ;
unsigned int V_39 ;
if ( V_168 -> V_65 < V_22 -> V_65 )
return - V_14 ;
for ( V_39 = 0 ; V_39 < V_168 -> V_65 ; ++ V_39 ) {
V_93 -> V_99 . V_171 [ V_39 ] = F_78 ( V_168 , V_39 ) ;
if ( F_29 ( V_168 , V_39 ) < V_22 -> V_62 [ V_39 ] . V_64 )
return - V_14 ;
}
for ( ; V_39 < 3 ; ++ V_39 )
V_93 -> V_99 . V_171 [ V_39 ] = 0 ;
return 0 ;
}
static void F_79 ( struct V_167 * V_168 )
{
struct V_169 * V_170 = F_76 ( V_168 ) ;
struct V_8 * V_9 = F_74 ( V_168 -> V_160 ) ;
struct V_66 * V_67 = V_9 -> V_19 -> V_67 ;
struct V_85 * V_93 = F_77 ( V_170 ) ;
unsigned long V_88 ;
bool V_172 ;
F_21 ( & V_9 -> V_89 , V_88 ) ;
V_172 = F_22 ( & V_9 -> V_90 ) ;
F_53 ( & V_93 -> V_91 , & V_9 -> V_90 ) ;
F_23 ( & V_9 -> V_89 , V_88 ) ;
if ( ! V_172 )
return;
F_21 ( & V_67 -> V_89 , V_88 ) ;
V_9 -> V_19 -> V_99 = V_93 -> V_99 ;
V_67 -> V_100 |= 1 << V_9 -> V_101 ;
if ( F_80 ( & V_9 -> V_91 ) &&
F_41 ( V_67 ) )
F_33 ( V_67 ) ;
F_23 ( & V_67 -> V_89 , V_88 ) ;
}
static int F_81 ( struct V_66 * V_67 )
{
struct V_71 * V_6 ;
F_15 ( V_67 ) ;
V_67 -> V_103 = F_34 ( V_67 -> V_69 -> V_107 ) ;
if ( ! V_67 -> V_103 )
return - V_157 ;
if ( V_67 -> V_133 ) {
struct V_173 * V_133 = F_82 ( & V_67 -> V_133 -> V_12 ) ;
if ( V_67 -> V_134 -> type == V_126 ) {
V_133 -> V_174 = false ;
} else {
struct V_98 * V_129 =
F_54 ( & V_67 -> V_134 -> V_12 ) ;
V_133 -> V_174 = V_129 -> V_20 -> V_175 ;
}
}
F_17 (entity, &pipe->entities, list_pipe) {
F_83 ( V_6 , V_67 , V_67 -> V_103 ) ;
if ( V_6 -> V_78 -> V_105 )
V_6 -> V_78 -> V_105 ( V_6 , V_67 , V_67 -> V_103 ,
V_176 ) ;
}
return 0 ;
}
static int F_84 ( struct V_160 * V_161 , unsigned int V_177 )
{
struct V_8 * V_9 = F_74 ( V_161 ) ;
struct V_66 * V_67 = V_9 -> V_19 -> V_67 ;
bool V_178 = false ;
unsigned long V_88 ;
int V_13 ;
F_70 ( & V_67 -> V_179 ) ;
if ( V_67 -> V_180 == V_67 -> V_146 ) {
V_13 = F_81 ( V_67 ) ;
if ( V_13 < 0 ) {
F_72 ( & V_67 -> V_179 ) ;
return V_13 ;
}
V_178 = true ;
}
V_67 -> V_180 ++ ;
F_72 ( & V_67 -> V_179 ) ;
if ( ! V_178 )
return 0 ;
F_21 ( & V_67 -> V_89 , V_88 ) ;
if ( F_41 ( V_67 ) )
F_33 ( V_67 ) ;
F_23 ( & V_67 -> V_89 , V_88 ) ;
return 0 ;
}
static void F_85 ( struct V_160 * V_161 )
{
struct V_8 * V_9 = F_74 ( V_161 ) ;
struct V_66 * V_67 = V_9 -> V_19 -> V_67 ;
struct V_85 * V_181 ;
unsigned long V_88 ;
int V_13 ;
F_21 ( & V_9 -> V_89 , V_88 ) ;
V_67 -> V_100 &= ~ ( 1 << V_9 -> V_101 ) ;
F_23 ( & V_9 -> V_89 , V_88 ) ;
F_70 ( & V_67 -> V_179 ) ;
if ( -- V_67 -> V_180 == V_67 -> V_146 ) {
V_13 = F_86 ( V_67 ) ;
if ( V_13 == - V_182 )
F_35 ( V_9 -> V_41 -> V_109 , L_2 ) ;
F_87 ( V_67 -> V_103 ) ;
V_67 -> V_103 = NULL ;
}
F_72 ( & V_67 -> V_179 ) ;
F_88 ( & V_9 -> V_9 . V_6 ) ;
F_69 ( V_67 ) ;
F_21 ( & V_9 -> V_89 , V_88 ) ;
F_17 (buffer, &video->irqqueue, queue)
F_30 ( & V_181 -> V_93 . V_95 , V_183 ) ;
F_89 ( & V_9 -> V_90 ) ;
F_23 ( & V_9 -> V_89 , V_88 ) ;
}
static int
F_90 ( struct V_184 * V_184 , void * V_185 , struct V_186 * V_187 )
{
struct V_188 * V_189 = V_184 -> V_190 ;
struct V_8 * V_9 = F_91 ( V_189 -> V_191 ) ;
V_187 -> V_192 = V_193 | V_194
| V_195
| V_196 ;
if ( V_9 -> type == V_197 )
V_187 -> V_198 = V_195
| V_194 ;
else
V_187 -> V_198 = V_196
| V_194 ;
F_92 ( V_187 -> V_199 , L_3 , sizeof( V_187 -> V_199 ) ) ;
F_92 ( V_187 -> V_200 , V_9 -> V_9 . V_201 , sizeof( V_187 -> V_200 ) ) ;
snprintf ( V_187 -> V_202 , sizeof( V_187 -> V_202 ) , L_4 ,
F_93 ( V_9 -> V_41 -> V_109 ) ) ;
return 0 ;
}
static int
F_94 ( struct V_184 * V_184 , void * V_185 , struct V_203 * V_22 )
{
struct V_188 * V_189 = V_184 -> V_190 ;
struct V_8 * V_9 = F_91 ( V_189 -> V_191 ) ;
if ( V_22 -> type != V_9 -> V_91 . type )
return - V_14 ;
F_70 ( & V_9 -> V_179 ) ;
V_22 -> V_11 . V_204 = V_9 -> V_19 -> V_22 ;
F_72 ( & V_9 -> V_179 ) ;
return 0 ;
}
static int
F_95 ( struct V_184 * V_184 , void * V_185 , struct V_203 * V_22 )
{
struct V_188 * V_189 = V_184 -> V_190 ;
struct V_8 * V_9 = F_91 ( V_189 -> V_191 ) ;
if ( V_22 -> type != V_9 -> V_91 . type )
return - V_14 ;
return F_7 ( V_9 , & V_22 -> V_11 . V_204 , NULL ) ;
}
static int
F_96 ( struct V_184 * V_184 , void * V_185 , struct V_203 * V_22 )
{
struct V_188 * V_189 = V_184 -> V_190 ;
struct V_8 * V_9 = F_91 ( V_189 -> V_191 ) ;
const struct V_28 * V_38 ;
int V_13 ;
if ( V_22 -> type != V_9 -> V_91 . type )
return - V_14 ;
V_13 = F_7 ( V_9 , & V_22 -> V_11 . V_204 , & V_38 ) ;
if ( V_13 < 0 )
return V_13 ;
F_70 ( & V_9 -> V_179 ) ;
if ( F_97 ( & V_9 -> V_91 ) ) {
V_13 = - V_205 ;
goto V_87;
}
V_9 -> V_19 -> V_22 = V_22 -> V_11 . V_204 ;
V_9 -> V_19 -> V_20 = V_38 ;
V_87:
F_72 ( & V_9 -> V_179 ) ;
return V_13 ;
}
static int
F_98 ( struct V_184 * V_184 , void * V_185 , enum V_206 type )
{
struct V_188 * V_189 = V_184 -> V_190 ;
struct V_8 * V_9 = F_91 ( V_189 -> V_191 ) ;
struct V_139 * V_140 = & V_9 -> V_41 -> V_121 ;
struct V_66 * V_67 ;
int V_13 ;
if ( V_9 -> V_91 . V_207 && V_9 -> V_91 . V_207 != V_184 -> V_190 )
return - V_205 ;
F_70 ( & V_140 -> V_159 ) ;
V_67 = F_60 ( V_9 ) ;
if ( F_99 ( V_67 ) ) {
F_72 ( & V_140 -> V_159 ) ;
return F_100 ( V_67 ) ;
}
V_13 = F_101 ( & V_9 -> V_9 . V_6 , & V_67 -> V_67 ) ;
if ( V_13 < 0 ) {
F_72 ( & V_140 -> V_159 ) ;
goto V_208;
}
F_72 ( & V_140 -> V_159 ) ;
V_13 = F_5 ( V_9 ) ;
if ( V_13 < 0 )
goto V_209;
V_13 = F_102 ( & V_9 -> V_91 , type ) ;
if ( V_13 < 0 )
goto V_209;
return 0 ;
V_209:
F_88 ( & V_9 -> V_9 . V_6 ) ;
V_208:
F_69 ( V_67 ) ;
return V_13 ;
}
static int F_103 ( struct V_184 * V_184 )
{
struct V_8 * V_9 = F_104 ( V_184 ) ;
struct V_188 * V_189 ;
int V_13 = 0 ;
V_189 = F_61 ( sizeof( * V_189 ) , V_156 ) ;
if ( V_189 == NULL )
return - V_157 ;
F_105 ( V_189 , & V_9 -> V_9 ) ;
F_106 ( V_189 ) ;
V_184 -> V_190 = V_189 ;
V_13 = F_107 ( V_9 -> V_41 ) ;
if ( V_13 < 0 ) {
F_108 ( V_189 ) ;
F_109 ( V_189 ) ;
F_64 ( V_189 ) ;
}
return V_13 ;
}
static int F_110 ( struct V_184 * V_184 )
{
struct V_8 * V_9 = F_104 ( V_184 ) ;
struct V_188 * V_189 = V_184 -> V_190 ;
F_70 ( & V_9 -> V_179 ) ;
if ( V_9 -> V_91 . V_207 == V_189 ) {
F_111 ( & V_9 -> V_91 ) ;
V_9 -> V_91 . V_207 = NULL ;
}
F_72 ( & V_9 -> V_179 ) ;
F_112 ( V_9 -> V_41 ) ;
F_113 ( V_184 ) ;
V_184 -> V_190 = NULL ;
return 0 ;
}
struct V_8 * F_114 ( struct V_68 * V_41 ,
struct V_98 * V_19 )
{
struct V_8 * V_9 ;
const char * V_210 ;
int V_13 ;
V_9 = F_115 ( V_41 -> V_109 , sizeof( * V_9 ) , V_156 ) ;
if ( ! V_9 )
return F_62 ( - V_157 ) ;
V_19 -> V_9 = V_9 ;
V_9 -> V_41 = V_41 ;
V_9 -> V_19 = V_19 ;
if ( V_19 -> V_6 . type == V_145 ) {
V_210 = L_5 ;
V_9 -> type = V_211 ;
V_9 -> V_4 . V_88 = V_212 ;
V_9 -> V_9 . V_213 = V_214 ;
} else {
V_210 = L_6 ;
V_9 -> type = V_197 ;
V_9 -> V_4 . V_88 = V_215 ;
V_9 -> V_9 . V_213 = V_216 ;
}
F_116 ( & V_9 -> V_179 ) ;
F_117 ( & V_9 -> V_89 ) ;
F_89 ( & V_9 -> V_90 ) ;
V_13 = F_118 ( & V_9 -> V_9 . V_6 , 1 , & V_9 -> V_4 ) ;
if ( V_13 < 0 )
return F_62 ( V_13 ) ;
V_19 -> V_22 . V_40 = V_42 ;
V_19 -> V_22 . V_25 = V_217 ;
V_19 -> V_22 . V_24 = V_218 ;
F_7 ( V_9 , & V_19 -> V_22 , & V_19 -> V_20 ) ;
V_9 -> V_9 . V_219 = & V_9 -> V_41 -> V_219 ;
V_9 -> V_9 . V_220 = & V_221 ;
snprintf ( V_9 -> V_9 . V_201 , sizeof( V_9 -> V_9 . V_201 ) , L_7 ,
V_19 -> V_6 . V_12 . V_201 , V_210 ) ;
V_9 -> V_9 . V_222 = V_223 ;
V_9 -> V_9 . V_224 = V_225 ;
V_9 -> V_9 . V_226 = & V_227 ;
F_119 ( & V_9 -> V_9 , V_9 ) ;
V_9 -> V_91 . type = V_9 -> type ;
V_9 -> V_91 . V_228 = V_229 | V_230 | V_231 ;
V_9 -> V_91 . V_179 = & V_9 -> V_179 ;
V_9 -> V_91 . V_232 = V_9 ;
V_9 -> V_91 . V_233 = sizeof( struct V_85 ) ;
V_9 -> V_91 . V_78 = & V_234 ;
V_9 -> V_91 . V_235 = & V_236 ;
V_9 -> V_91 . V_237 = V_238 ;
V_9 -> V_91 . V_109 = V_9 -> V_41 -> V_239 ;
V_13 = F_120 ( & V_9 -> V_91 ) ;
if ( V_13 < 0 ) {
F_35 ( V_9 -> V_41 -> V_109 , L_8 ) ;
goto error;
}
V_9 -> V_9 . V_91 = & V_9 -> V_91 ;
V_13 = F_121 ( & V_9 -> V_9 , V_223 , - 1 ) ;
if ( V_13 < 0 ) {
F_35 ( V_9 -> V_41 -> V_109 , L_9 ) ;
goto error;
}
return V_9 ;
error:
F_122 ( V_9 ) ;
return F_62 ( V_13 ) ;
}
void F_122 ( struct V_8 * V_9 )
{
if ( F_123 ( & V_9 -> V_9 ) )
F_124 ( & V_9 -> V_9 ) ;
F_125 ( & V_9 -> V_9 . V_6 ) ;
}
