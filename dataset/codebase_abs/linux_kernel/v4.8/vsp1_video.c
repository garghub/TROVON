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
V_38 = F_9 ( V_27 -> V_40 ) ;
if ( V_38 == NULL )
V_38 = F_9 ( V_41 ) ;
V_27 -> V_40 = V_38 -> V_42 ;
V_27 -> V_43 = V_44 ;
V_27 -> V_45 = V_46 ;
memset ( V_27 -> V_47 , 0 , sizeof( V_27 -> V_47 ) ) ;
V_25 = F_10 ( V_25 , V_38 -> V_48 ) ;
V_24 = F_10 ( V_24 , V_38 -> V_49 ) ;
V_27 -> V_25 = F_11 ( V_25 , V_50 , V_51 ) ;
V_27 -> V_24 = F_11 ( V_24 , V_52 ,
V_53 ) ;
for ( V_39 = 0 ; V_39 < F_12 ( V_38 -> V_54 , 2U ) ; ++ V_39 ) {
unsigned int V_48 = V_39 > 0 ? V_38 -> V_48 : 1 ;
unsigned int V_49 = V_39 > 0 ? V_38 -> V_49 : 1 ;
unsigned int V_55 = 128 ;
unsigned int V_56 ;
V_56 = F_13 (unsigned int, pix->plane_fmt[i].bytesperline,
pix->width / hsub * info->bpp[i] / 8 ,
round_down(65535U, align)) ;
V_27 -> V_57 [ V_39 ] . V_58 = F_14 ( V_56 , V_55 ) ;
V_27 -> V_57 [ V_39 ] . V_59 = V_27 -> V_57 [ V_39 ] . V_58
* V_27 -> V_24 / V_49 ;
}
if ( V_38 -> V_54 == 3 ) {
V_27 -> V_57 [ 2 ] . V_58 = V_27 -> V_57 [ 1 ] . V_58 ;
V_27 -> V_57 [ 2 ] . V_59 = V_27 -> V_57 [ 1 ] . V_59 ;
}
V_27 -> V_60 = V_38 -> V_54 ;
if ( V_20 )
* V_20 = V_38 ;
return 0 ;
}
static struct V_61 *
F_15 ( struct V_8 * V_9 )
{
struct V_62 * V_63 = V_9 -> V_19 -> V_63 ;
struct V_61 * V_64 = NULL ;
struct V_61 * V_65 ;
unsigned long V_66 ;
unsigned int V_39 ;
F_16 ( & V_9 -> V_67 , V_66 ) ;
if ( F_17 ( & V_9 -> V_68 ) ) {
F_18 ( & V_9 -> V_67 , V_66 ) ;
return NULL ;
}
V_65 = F_19 ( & V_9 -> V_68 ,
struct V_61 , V_69 ) ;
if ( V_63 -> V_70 && F_20 ( & V_9 -> V_68 ) ) {
F_18 ( & V_9 -> V_67 , V_66 ) ;
return V_65 ;
}
F_21 ( & V_65 -> V_69 ) ;
if ( ! F_17 ( & V_9 -> V_68 ) )
V_64 = F_19 ( & V_9 -> V_68 ,
struct V_61 , V_69 ) ;
F_18 ( & V_9 -> V_67 , V_66 ) ;
V_65 -> V_71 . V_72 = V_63 -> V_72 ;
V_65 -> V_71 . V_73 . V_74 = F_22 () ;
for ( V_39 = 0 ; V_39 < V_65 -> V_71 . V_73 . V_60 ; ++ V_39 )
F_23 ( & V_65 -> V_71 . V_73 , V_39 ,
F_24 ( & V_65 -> V_71 . V_73 , V_39 ) ) ;
F_25 ( & V_65 -> V_71 . V_73 , V_75 ) ;
return V_64 ;
}
static void F_26 ( struct V_62 * V_63 ,
struct V_76 * V_19 )
{
struct V_8 * V_9 = V_19 -> V_9 ;
struct V_61 * V_71 ;
unsigned long V_66 ;
V_71 = F_15 ( V_9 ) ;
if ( V_71 == NULL )
return;
F_16 ( & V_63 -> V_67 , V_66 ) ;
V_9 -> V_19 -> V_77 = V_71 -> V_77 ;
V_63 -> V_78 |= 1 << V_9 -> V_79 ;
F_18 ( & V_63 -> V_67 , V_66 ) ;
}
static void F_27 ( struct V_62 * V_63 )
{
struct V_80 * V_81 = V_63 -> V_82 -> V_6 . V_81 ;
struct V_83 * V_6 ;
unsigned int V_39 ;
if ( ! V_63 -> V_84 )
V_63 -> V_84 = F_28 ( V_63 -> V_82 -> V_85 ) ;
F_29 (entity, &pipe->entities, list_pipe) {
if ( V_6 -> V_86 -> V_87 )
V_6 -> V_86 -> V_87 ( V_6 , V_63 , V_63 -> V_84 , false ) ;
}
for ( V_39 = 0 ; V_39 < V_81 -> V_38 -> V_88 ; ++ V_39 ) {
struct V_76 * V_19 = V_63 -> V_89 [ V_39 ] ;
if ( V_19 )
F_30 ( V_19 , V_63 -> V_84 ) ;
}
if ( ! V_63 -> V_70 )
F_30 ( V_63 -> V_82 , V_63 -> V_84 ) ;
F_31 ( V_63 -> V_84 ) ;
V_63 -> V_84 = NULL ;
F_32 ( V_63 ) ;
}
static void F_33 ( struct V_62 * V_63 )
{
struct V_80 * V_81 = V_63 -> V_82 -> V_6 . V_81 ;
enum V_90 V_91 ;
unsigned long V_66 ;
unsigned int V_39 ;
for ( V_39 = 0 ; V_39 < V_81 -> V_38 -> V_88 ; ++ V_39 ) {
if ( ! V_63 -> V_89 [ V_39 ] )
continue;
F_26 ( V_63 , V_63 -> V_89 [ V_39 ] ) ;
}
F_26 ( V_63 , V_63 -> V_82 ) ;
F_16 ( & V_63 -> V_67 , V_66 ) ;
V_91 = V_63 -> V_91 ;
V_63 -> V_91 = V_92 ;
if ( V_91 == V_93 )
F_34 ( & V_63 -> V_94 ) ;
else if ( F_35 ( V_63 ) )
F_27 ( V_63 ) ;
F_18 ( & V_63 -> V_67 , V_66 ) ;
}
static int F_36 ( struct V_62 * V_63 ,
struct V_76 * V_95 ,
struct V_76 * V_82 )
{
struct V_96 V_97 ;
struct V_83 * V_6 ;
struct V_2 * V_4 ;
bool V_98 = false ;
int V_13 ;
V_13 = F_37 ( & V_97 , & V_95 -> V_6 . V_81 -> V_99 ) ;
if ( V_13 < 0 )
return V_13 ;
V_4 = F_2 ( & V_95 -> V_6 . V_100 [ V_101 ] ) ;
while ( 1 ) {
if ( V_4 == NULL ) {
V_13 = - V_102 ;
goto V_103;
}
if ( ! F_3 ( V_4 -> V_6 ) ) {
V_13 = - V_102 ;
goto V_103;
}
V_6 = F_38 (
F_4 ( V_4 -> V_6 ) ) ;
if ( V_6 -> type == V_104 ) {
struct V_105 * V_106 = F_39 ( & V_6 -> V_12 ) ;
V_106 -> V_89 [ V_4 -> V_7 ] . V_107 = V_95 ;
V_95 -> V_108 = V_4 -> V_7 ;
V_98 = true ;
}
if ( V_6 -> type == V_109 )
break;
if ( F_40 ( & V_97 ,
& V_6 -> V_12 . V_6 ) ) {
V_13 = - V_102 ;
goto V_103;
}
if ( V_6 -> type == V_110 ) {
if ( V_63 -> V_111 ) {
V_13 = - V_102 ;
goto V_103;
}
V_63 -> V_111 = V_6 ;
V_63 -> V_112 = V_98 ? V_63 -> V_106
: & V_95 -> V_6 ;
}
V_4 = & V_6 -> V_100 [ V_6 -> V_113 ] ;
V_4 = F_2 ( V_4 ) ;
}
if ( V_6 != & V_82 -> V_6 )
V_13 = - V_102 ;
V_103:
F_41 ( & V_97 ) ;
return V_13 ;
}
static int F_42 ( struct V_62 * V_63 ,
struct V_8 * V_9 )
{
struct V_114 V_115 ;
struct V_116 * V_6 = & V_9 -> V_9 . V_6 ;
struct V_117 * V_118 = V_6 -> V_119 . V_118 ;
unsigned int V_39 ;
int V_13 ;
V_13 = F_43 ( & V_115 , V_118 ) ;
if ( V_13 )
return V_13 ;
F_44 ( & V_115 , V_6 ) ;
while ( ( V_6 = F_45 ( & V_115 ) ) ) {
struct V_1 * V_12 ;
struct V_76 * V_19 ;
struct V_83 * V_120 ;
if ( ! F_3 ( V_6 ) )
continue;
V_12 = F_4 ( V_6 ) ;
V_120 = F_38 ( V_12 ) ;
F_46 ( & V_120 -> V_121 , & V_63 -> V_122 ) ;
if ( V_120 -> type == V_123 ) {
V_19 = F_47 ( V_12 ) ;
V_63 -> V_89 [ V_19 -> V_6 . V_7 ] = V_19 ;
V_19 -> V_9 -> V_79 = ++ V_63 -> V_124 ;
V_19 -> V_63 = V_63 ;
} else if ( V_120 -> type == V_109 ) {
V_19 = F_47 ( V_12 ) ;
V_63 -> V_82 = V_19 ;
V_19 -> V_9 -> V_79 = 0 ;
V_19 -> V_63 = V_63 ;
} else if ( V_120 -> type == V_125 ) {
V_63 -> V_70 = V_120 ;
} else if ( V_120 -> type == V_104 ) {
V_63 -> V_106 = V_120 ;
}
}
F_48 ( & V_115 ) ;
if ( V_63 -> V_124 == 0 || ! V_63 -> V_82 )
return - V_102 ;
for ( V_39 = 0 ; V_39 < V_9 -> V_81 -> V_38 -> V_88 ; ++ V_39 ) {
if ( ! V_63 -> V_89 [ V_39 ] )
continue;
V_13 = F_36 ( V_63 , V_63 -> V_89 [ V_39 ] ,
V_63 -> V_82 ) ;
if ( V_13 < 0 )
return V_13 ;
}
return 0 ;
}
static int F_49 ( struct V_62 * V_63 ,
struct V_8 * V_9 )
{
F_50 ( V_63 ) ;
V_63 -> V_126 = F_33 ;
return F_42 ( V_63 , V_9 ) ;
}
static struct V_62 * F_51 ( struct V_8 * V_9 )
{
struct V_62 * V_63 ;
int V_13 ;
if ( ! V_9 -> V_19 -> V_63 ) {
V_63 = F_52 ( sizeof( * V_63 ) , V_127 ) ;
if ( ! V_63 )
return F_53 ( - V_128 ) ;
V_13 = F_49 ( V_63 , V_9 ) ;
if ( V_13 < 0 ) {
F_54 ( V_63 ) ;
F_55 ( V_63 ) ;
return F_53 ( V_13 ) ;
}
} else {
V_63 = V_9 -> V_19 -> V_63 ;
F_56 ( & V_63 -> V_129 ) ;
}
return V_63 ;
}
static void F_57 ( struct V_129 * V_129 )
{
struct V_62 * V_63 = F_58 ( V_129 , F_59 ( * V_63 ) , V_129 ) ;
F_54 ( V_63 ) ;
F_55 ( V_63 ) ;
}
static void F_60 ( struct V_62 * V_63 )
{
struct V_117 * V_118 = & V_63 -> V_82 -> V_6 . V_81 -> V_99 ;
F_61 ( & V_118 -> V_130 ) ;
F_62 ( & V_63 -> V_129 , F_57 ) ;
F_63 ( & V_118 -> V_130 ) ;
}
static int
F_64 ( struct V_131 * V_132 ,
unsigned int * V_133 , unsigned int * V_134 ,
unsigned int V_135 [] , struct V_136 * V_137 [] )
{
struct V_8 * V_9 = F_65 ( V_132 ) ;
const struct V_26 * V_22 = & V_9 -> V_19 -> V_22 ;
unsigned int V_39 ;
if ( * V_134 ) {
if ( * V_134 != V_22 -> V_60 )
return - V_14 ;
for ( V_39 = 0 ; V_39 < * V_134 ; V_39 ++ )
if ( V_135 [ V_39 ] < V_22 -> V_57 [ V_39 ] . V_59 )
return - V_14 ;
return 0 ;
}
* V_134 = V_22 -> V_60 ;
for ( V_39 = 0 ; V_39 < V_22 -> V_60 ; ++ V_39 )
V_135 [ V_39 ] = V_22 -> V_57 [ V_39 ] . V_59 ;
return 0 ;
}
static int F_66 ( struct V_138 * V_139 )
{
struct V_140 * V_141 = F_67 ( V_139 ) ;
struct V_8 * V_9 = F_65 ( V_139 -> V_131 ) ;
struct V_61 * V_71 = F_68 ( V_141 ) ;
const struct V_26 * V_22 = & V_9 -> V_19 -> V_22 ;
unsigned int V_39 ;
if ( V_139 -> V_60 < V_22 -> V_60 )
return - V_14 ;
for ( V_39 = 0 ; V_39 < V_139 -> V_60 ; ++ V_39 ) {
V_71 -> V_77 . V_142 [ V_39 ] = F_69 ( V_139 , V_39 ) ;
if ( F_24 ( V_139 , V_39 ) < V_22 -> V_57 [ V_39 ] . V_59 )
return - V_14 ;
}
for ( ; V_39 < 3 ; ++ V_39 )
V_71 -> V_77 . V_142 [ V_39 ] = 0 ;
return 0 ;
}
static void F_70 ( struct V_138 * V_139 )
{
struct V_140 * V_141 = F_67 ( V_139 ) ;
struct V_8 * V_9 = F_65 ( V_139 -> V_131 ) ;
struct V_62 * V_63 = V_9 -> V_19 -> V_63 ;
struct V_61 * V_71 = F_68 ( V_141 ) ;
unsigned long V_66 ;
bool V_143 ;
F_16 ( & V_9 -> V_67 , V_66 ) ;
V_143 = F_17 ( & V_9 -> V_68 ) ;
F_46 ( & V_71 -> V_69 , & V_9 -> V_68 ) ;
F_18 ( & V_9 -> V_67 , V_66 ) ;
if ( ! V_143 )
return;
F_16 ( & V_63 -> V_67 , V_66 ) ;
V_9 -> V_19 -> V_77 = V_71 -> V_77 ;
V_63 -> V_78 |= 1 << V_9 -> V_79 ;
if ( F_71 ( & V_9 -> V_69 ) &&
F_35 ( V_63 ) )
F_27 ( V_63 ) ;
F_18 ( & V_63 -> V_67 , V_66 ) ;
}
static int F_72 ( struct V_62 * V_63 )
{
struct V_83 * V_6 ;
V_63 -> V_84 = F_28 ( V_63 -> V_82 -> V_85 ) ;
if ( ! V_63 -> V_84 )
return - V_128 ;
if ( V_63 -> V_111 ) {
struct V_144 * V_111 = F_73 ( & V_63 -> V_111 -> V_12 ) ;
if ( V_63 -> V_112 -> type == V_104 ) {
V_111 -> V_145 = false ;
} else {
struct V_76 * V_107 =
F_47 ( & V_63 -> V_112 -> V_12 ) ;
V_111 -> V_145 = V_107 -> V_20 -> V_146 ;
}
}
F_29 (entity, &pipe->entities, list_pipe) {
F_74 ( V_6 , V_63 -> V_84 ) ;
if ( V_6 -> V_86 -> V_87 )
V_6 -> V_86 -> V_87 ( V_6 , V_63 , V_63 -> V_84 , true ) ;
}
return 0 ;
}
static int F_75 ( struct V_131 * V_132 , unsigned int V_147 )
{
struct V_8 * V_9 = F_65 ( V_132 ) ;
struct V_62 * V_63 = V_9 -> V_19 -> V_63 ;
unsigned long V_66 ;
int V_13 ;
F_61 ( & V_63 -> V_148 ) ;
if ( V_63 -> V_149 == V_63 -> V_124 ) {
V_13 = F_72 ( V_63 ) ;
if ( V_13 < 0 ) {
F_63 ( & V_63 -> V_148 ) ;
return V_13 ;
}
}
V_63 -> V_149 ++ ;
F_63 ( & V_63 -> V_148 ) ;
F_16 ( & V_63 -> V_67 , V_66 ) ;
if ( F_35 ( V_63 ) )
F_27 ( V_63 ) ;
F_18 ( & V_63 -> V_67 , V_66 ) ;
return 0 ;
}
static void F_76 ( struct V_131 * V_132 )
{
struct V_8 * V_9 = F_65 ( V_132 ) ;
struct V_62 * V_63 = V_9 -> V_19 -> V_63 ;
struct V_61 * V_150 ;
unsigned long V_66 ;
int V_13 ;
F_61 ( & V_63 -> V_148 ) ;
if ( -- V_63 -> V_149 == V_63 -> V_124 ) {
V_13 = F_77 ( V_63 ) ;
if ( V_13 == - V_151 )
F_78 ( V_9 -> V_81 -> V_152 , L_1 ) ;
F_79 ( V_63 -> V_84 ) ;
V_63 -> V_84 = NULL ;
}
F_63 ( & V_63 -> V_148 ) ;
F_80 ( & V_9 -> V_9 . V_6 ) ;
F_60 ( V_63 ) ;
F_16 ( & V_9 -> V_67 , V_66 ) ;
F_29 (buffer, &video->irqqueue, queue)
F_25 ( & V_150 -> V_71 . V_73 , V_153 ) ;
F_81 ( & V_9 -> V_68 ) ;
F_18 ( & V_9 -> V_67 , V_66 ) ;
}
static int
F_82 ( struct V_154 * V_154 , void * V_155 , struct V_156 * V_157 )
{
struct V_158 * V_159 = V_154 -> V_160 ;
struct V_8 * V_9 = F_83 ( V_159 -> V_161 ) ;
V_157 -> V_162 = V_163 | V_164
| V_165
| V_166 ;
if ( V_9 -> type == V_167 )
V_157 -> V_168 = V_165
| V_164 ;
else
V_157 -> V_168 = V_166
| V_164 ;
F_84 ( V_157 -> V_169 , L_2 , sizeof( V_157 -> V_169 ) ) ;
F_84 ( V_157 -> V_170 , V_9 -> V_9 . V_171 , sizeof( V_157 -> V_170 ) ) ;
snprintf ( V_157 -> V_172 , sizeof( V_157 -> V_172 ) , L_3 ,
F_85 ( V_9 -> V_81 -> V_152 ) ) ;
return 0 ;
}
static int
F_86 ( struct V_154 * V_154 , void * V_155 , struct V_173 * V_22 )
{
struct V_158 * V_159 = V_154 -> V_160 ;
struct V_8 * V_9 = F_83 ( V_159 -> V_161 ) ;
if ( V_22 -> type != V_9 -> V_69 . type )
return - V_14 ;
F_61 ( & V_9 -> V_148 ) ;
V_22 -> V_11 . V_174 = V_9 -> V_19 -> V_22 ;
F_63 ( & V_9 -> V_148 ) ;
return 0 ;
}
static int
F_87 ( struct V_154 * V_154 , void * V_155 , struct V_173 * V_22 )
{
struct V_158 * V_159 = V_154 -> V_160 ;
struct V_8 * V_9 = F_83 ( V_159 -> V_161 ) ;
if ( V_22 -> type != V_9 -> V_69 . type )
return - V_14 ;
return F_7 ( V_9 , & V_22 -> V_11 . V_174 , NULL ) ;
}
static int
F_88 ( struct V_154 * V_154 , void * V_155 , struct V_173 * V_22 )
{
struct V_158 * V_159 = V_154 -> V_160 ;
struct V_8 * V_9 = F_83 ( V_159 -> V_161 ) ;
const struct V_28 * V_38 ;
int V_13 ;
if ( V_22 -> type != V_9 -> V_69 . type )
return - V_14 ;
V_13 = F_7 ( V_9 , & V_22 -> V_11 . V_174 , & V_38 ) ;
if ( V_13 < 0 )
return V_13 ;
F_61 ( & V_9 -> V_148 ) ;
if ( F_89 ( & V_9 -> V_69 ) ) {
V_13 = - V_175 ;
goto V_65;
}
V_9 -> V_19 -> V_22 = V_22 -> V_11 . V_174 ;
V_9 -> V_19 -> V_20 = V_38 ;
V_65:
F_63 ( & V_9 -> V_148 ) ;
return V_13 ;
}
static int
F_90 ( struct V_154 * V_154 , void * V_155 , enum V_176 type )
{
struct V_158 * V_159 = V_154 -> V_160 ;
struct V_8 * V_9 = F_83 ( V_159 -> V_161 ) ;
struct V_117 * V_118 = & V_9 -> V_81 -> V_99 ;
struct V_62 * V_63 ;
int V_13 ;
if ( V_9 -> V_69 . V_177 && V_9 -> V_69 . V_177 != V_154 -> V_160 )
return - V_175 ;
F_61 ( & V_118 -> V_130 ) ;
V_63 = F_51 ( V_9 ) ;
if ( F_91 ( V_63 ) ) {
F_63 ( & V_118 -> V_130 ) ;
return F_92 ( V_63 ) ;
}
V_13 = F_93 ( & V_9 -> V_9 . V_6 , & V_63 -> V_63 ) ;
if ( V_13 < 0 ) {
F_63 ( & V_118 -> V_130 ) ;
goto V_178;
}
F_63 ( & V_118 -> V_130 ) ;
V_13 = F_5 ( V_9 ) ;
if ( V_13 < 0 )
goto V_179;
V_13 = F_94 ( & V_9 -> V_69 , type ) ;
if ( V_13 < 0 )
goto V_179;
return 0 ;
V_179:
F_80 ( & V_9 -> V_9 . V_6 ) ;
V_178:
F_60 ( V_63 ) ;
return V_13 ;
}
static int F_95 ( struct V_154 * V_154 )
{
struct V_8 * V_9 = F_96 ( V_154 ) ;
struct V_158 * V_159 ;
int V_13 = 0 ;
V_159 = F_52 ( sizeof( * V_159 ) , V_127 ) ;
if ( V_159 == NULL )
return - V_128 ;
F_97 ( V_159 , & V_9 -> V_9 ) ;
F_98 ( V_159 ) ;
V_154 -> V_160 = V_159 ;
V_13 = F_99 ( V_9 -> V_81 ) ;
if ( V_13 < 0 ) {
F_100 ( V_159 ) ;
F_55 ( V_159 ) ;
}
return V_13 ;
}
static int F_101 ( struct V_154 * V_154 )
{
struct V_8 * V_9 = F_96 ( V_154 ) ;
struct V_158 * V_159 = V_154 -> V_160 ;
F_61 ( & V_9 -> V_148 ) ;
if ( V_9 -> V_69 . V_177 == V_159 ) {
F_102 ( & V_9 -> V_69 ) ;
V_9 -> V_69 . V_177 = NULL ;
}
F_63 ( & V_9 -> V_148 ) ;
F_103 ( V_9 -> V_81 ) ;
F_104 ( V_154 ) ;
V_154 -> V_160 = NULL ;
return 0 ;
}
struct V_8 * F_105 ( struct V_80 * V_81 ,
struct V_76 * V_19 )
{
struct V_8 * V_9 ;
const char * V_180 ;
int V_13 ;
V_9 = F_106 ( V_81 -> V_152 , sizeof( * V_9 ) , V_127 ) ;
if ( ! V_9 )
return F_53 ( - V_128 ) ;
V_19 -> V_9 = V_9 ;
V_9 -> V_81 = V_81 ;
V_9 -> V_19 = V_19 ;
if ( V_19 -> V_6 . type == V_123 ) {
V_180 = L_4 ;
V_9 -> type = V_181 ;
V_9 -> V_4 . V_66 = V_182 ;
V_9 -> V_9 . V_183 = V_184 ;
} else {
V_180 = L_5 ;
V_9 -> type = V_167 ;
V_9 -> V_4 . V_66 = V_185 ;
V_9 -> V_9 . V_183 = V_186 ;
}
F_107 ( & V_9 -> V_148 ) ;
F_108 ( & V_9 -> V_67 ) ;
F_81 ( & V_9 -> V_68 ) ;
V_13 = F_109 ( & V_9 -> V_9 . V_6 , 1 , & V_9 -> V_4 ) ;
if ( V_13 < 0 )
return F_53 ( V_13 ) ;
V_19 -> V_22 . V_40 = V_41 ;
V_19 -> V_22 . V_25 = V_187 ;
V_19 -> V_22 . V_24 = V_188 ;
F_7 ( V_9 , & V_19 -> V_22 , & V_19 -> V_20 ) ;
V_9 -> V_9 . V_189 = & V_9 -> V_81 -> V_189 ;
V_9 -> V_9 . V_190 = & V_191 ;
snprintf ( V_9 -> V_9 . V_171 , sizeof( V_9 -> V_9 . V_171 ) , L_6 ,
V_19 -> V_6 . V_12 . V_171 , V_180 ) ;
V_9 -> V_9 . V_192 = V_193 ;
V_9 -> V_9 . V_194 = V_195 ;
V_9 -> V_9 . V_196 = & V_197 ;
F_110 ( & V_9 -> V_9 , V_9 ) ;
V_9 -> V_69 . type = V_9 -> type ;
V_9 -> V_69 . V_198 = V_199 | V_200 | V_201 ;
V_9 -> V_69 . V_148 = & V_9 -> V_148 ;
V_9 -> V_69 . V_202 = V_9 ;
V_9 -> V_69 . V_203 = sizeof( struct V_61 ) ;
V_9 -> V_69 . V_86 = & V_204 ;
V_9 -> V_69 . V_205 = & V_206 ;
V_9 -> V_69 . V_207 = V_208 ;
V_9 -> V_69 . V_152 = V_9 -> V_81 -> V_152 ;
V_13 = F_111 ( & V_9 -> V_69 ) ;
if ( V_13 < 0 ) {
F_78 ( V_9 -> V_81 -> V_152 , L_7 ) ;
goto error;
}
V_9 -> V_9 . V_69 = & V_9 -> V_69 ;
V_13 = F_112 ( & V_9 -> V_9 , V_193 , - 1 ) ;
if ( V_13 < 0 ) {
F_78 ( V_9 -> V_81 -> V_152 , L_8 ) ;
goto error;
}
return V_9 ;
error:
F_113 ( V_9 ) ;
return F_53 ( V_13 ) ;
}
void F_113 ( struct V_8 * V_9 )
{
if ( F_114 ( & V_9 -> V_9 ) )
F_115 ( & V_9 -> V_9 ) ;
F_116 ( & V_9 -> V_9 . V_6 ) ;
}
