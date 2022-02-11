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
V_4 = F_2 ( & V_117 -> V_6 . V_122 [ V_74 ] ) ;
while ( 1 ) {
if ( V_4 == NULL ) {
V_13 = - V_123 ;
goto V_124;
}
if ( ! F_3 ( V_4 -> V_6 ) ) {
V_13 = - V_123 ;
goto V_124;
}
V_6 = F_44 (
F_4 ( V_4 -> V_6 ) ) ;
if ( V_6 -> type == V_125 ) {
struct V_126 * V_127 = F_45 ( & V_6 -> V_12 ) ;
V_127 -> V_113 [ V_4 -> V_7 ] . V_128 = V_117 ;
V_117 -> V_129 = V_4 -> V_7 ;
V_120 = true ;
}
if ( V_6 -> type == V_130 )
break;
if ( F_46 ( & V_119 ,
& V_6 -> V_12 . V_6 ) ) {
V_13 = - V_123 ;
goto V_124;
}
if ( V_6 -> type == V_131 ) {
if ( V_67 -> V_132 ) {
V_13 = - V_123 ;
goto V_124;
}
V_67 -> V_132 = V_6 ;
V_67 -> V_133 = V_120 ? V_67 -> V_127
: & V_117 -> V_6 ;
}
V_4 = & V_6 -> V_122 [ V_6 -> V_134 ] ;
V_4 = F_2 ( V_4 ) ;
}
if ( V_6 != & V_69 -> V_6 )
V_13 = - V_123 ;
V_124:
F_47 ( & V_119 ) ;
return V_13 ;
}
static int F_48 ( struct V_66 * V_67 ,
struct V_8 * V_9 )
{
struct V_135 V_136 ;
struct V_137 * V_6 = & V_9 -> V_9 . V_6 ;
struct V_138 * V_139 = V_6 -> V_140 . V_139 ;
unsigned int V_39 ;
int V_13 ;
V_13 = F_49 ( & V_136 , V_139 ) ;
if ( V_13 )
return V_13 ;
F_50 ( & V_136 , V_6 ) ;
while ( ( V_6 = F_51 ( & V_136 ) ) ) {
struct V_1 * V_12 ;
struct V_98 * V_19 ;
struct V_71 * V_141 ;
if ( ! F_3 ( V_6 ) )
continue;
V_12 = F_4 ( V_6 ) ;
V_141 = F_44 ( V_12 ) ;
F_52 ( & V_141 -> V_142 , & V_67 -> V_143 ) ;
if ( V_141 -> type == V_144 ) {
V_19 = F_53 ( V_12 ) ;
V_67 -> V_113 [ V_19 -> V_6 . V_7 ] = V_19 ;
V_19 -> V_9 -> V_101 = ++ V_67 -> V_145 ;
V_19 -> V_67 = V_67 ;
} else if ( V_141 -> type == V_130 ) {
V_19 = F_53 ( V_12 ) ;
V_67 -> V_69 = V_19 ;
V_19 -> V_9 -> V_101 = 0 ;
V_19 -> V_67 = V_67 ;
} else if ( V_141 -> type == V_146 ) {
V_67 -> V_92 = V_141 ;
} else if ( V_141 -> type == V_125 ) {
V_67 -> V_127 = V_141 ;
}
}
F_54 ( & V_136 ) ;
if ( V_67 -> V_145 == 0 || ! V_67 -> V_69 )
return - V_123 ;
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
static int F_55 ( struct V_66 * V_67 ,
struct V_8 * V_9 )
{
F_56 ( V_67 ) ;
V_67 -> V_147 = F_39 ;
return F_48 ( V_67 , V_9 ) ;
}
static struct V_66 * F_57 ( struct V_8 * V_9 )
{
struct V_66 * V_67 ;
int V_13 ;
if ( ! V_9 -> V_19 -> V_67 ) {
V_67 = F_58 ( sizeof( * V_67 ) , V_148 ) ;
if ( ! V_67 )
return F_59 ( - V_149 ) ;
V_13 = F_55 ( V_67 , V_9 ) ;
if ( V_13 < 0 ) {
F_60 ( V_67 ) ;
F_61 ( V_67 ) ;
return F_59 ( V_13 ) ;
}
} else {
V_67 = V_9 -> V_19 -> V_67 ;
F_62 ( & V_67 -> V_150 ) ;
}
return V_67 ;
}
static void F_63 ( struct V_150 * V_150 )
{
struct V_66 * V_67 = F_64 ( V_150 , F_65 ( * V_67 ) , V_150 ) ;
F_60 ( V_67 ) ;
F_61 ( V_67 ) ;
}
static void F_66 ( struct V_66 * V_67 )
{
struct V_138 * V_139 = & V_67 -> V_69 -> V_6 . V_41 -> V_121 ;
F_67 ( & V_139 -> V_151 ) ;
F_68 ( & V_67 -> V_150 , F_63 ) ;
F_69 ( & V_139 -> V_151 ) ;
}
static int
F_70 ( struct V_152 * V_153 ,
unsigned int * V_154 , unsigned int * V_155 ,
unsigned int V_156 [] , struct V_157 * V_158 [] )
{
struct V_8 * V_9 = F_71 ( V_153 ) ;
const struct V_26 * V_22 = & V_9 -> V_19 -> V_22 ;
unsigned int V_39 ;
if ( * V_155 ) {
if ( * V_155 != V_22 -> V_65 )
return - V_14 ;
for ( V_39 = 0 ; V_39 < * V_155 ; V_39 ++ )
if ( V_156 [ V_39 ] < V_22 -> V_62 [ V_39 ] . V_64 )
return - V_14 ;
return 0 ;
}
* V_155 = V_22 -> V_65 ;
for ( V_39 = 0 ; V_39 < V_22 -> V_65 ; ++ V_39 )
V_156 [ V_39 ] = V_22 -> V_62 [ V_39 ] . V_64 ;
return 0 ;
}
static int F_72 ( struct V_159 * V_160 )
{
struct V_161 * V_162 = F_73 ( V_160 ) ;
struct V_8 * V_9 = F_71 ( V_160 -> V_152 ) ;
struct V_85 * V_93 = F_74 ( V_162 ) ;
const struct V_26 * V_22 = & V_9 -> V_19 -> V_22 ;
unsigned int V_39 ;
if ( V_160 -> V_65 < V_22 -> V_65 )
return - V_14 ;
for ( V_39 = 0 ; V_39 < V_160 -> V_65 ; ++ V_39 ) {
V_93 -> V_99 . V_163 [ V_39 ] = F_75 ( V_160 , V_39 ) ;
if ( F_29 ( V_160 , V_39 ) < V_22 -> V_62 [ V_39 ] . V_64 )
return - V_14 ;
}
for ( ; V_39 < 3 ; ++ V_39 )
V_93 -> V_99 . V_163 [ V_39 ] = 0 ;
return 0 ;
}
static void F_76 ( struct V_159 * V_160 )
{
struct V_161 * V_162 = F_73 ( V_160 ) ;
struct V_8 * V_9 = F_71 ( V_160 -> V_152 ) ;
struct V_66 * V_67 = V_9 -> V_19 -> V_67 ;
struct V_85 * V_93 = F_74 ( V_162 ) ;
unsigned long V_88 ;
bool V_164 ;
F_21 ( & V_9 -> V_89 , V_88 ) ;
V_164 = F_22 ( & V_9 -> V_90 ) ;
F_52 ( & V_93 -> V_91 , & V_9 -> V_90 ) ;
F_23 ( & V_9 -> V_89 , V_88 ) ;
if ( ! V_164 )
return;
F_21 ( & V_67 -> V_89 , V_88 ) ;
V_9 -> V_19 -> V_99 = V_93 -> V_99 ;
V_67 -> V_100 |= 1 << V_9 -> V_101 ;
if ( F_77 ( & V_9 -> V_91 ) &&
F_41 ( V_67 ) )
F_33 ( V_67 ) ;
F_23 ( & V_67 -> V_89 , V_88 ) ;
}
static int F_78 ( struct V_66 * V_67 )
{
struct V_71 * V_6 ;
F_15 ( V_67 ) ;
V_67 -> V_103 = F_34 ( V_67 -> V_69 -> V_107 ) ;
if ( ! V_67 -> V_103 )
return - V_149 ;
if ( V_67 -> V_132 ) {
struct V_165 * V_132 = F_79 ( & V_67 -> V_132 -> V_12 ) ;
if ( V_67 -> V_133 -> type == V_125 ) {
V_132 -> V_166 = false ;
} else {
struct V_98 * V_128 =
F_53 ( & V_67 -> V_133 -> V_12 ) ;
V_132 -> V_166 = V_128 -> V_20 -> V_167 ;
}
}
F_17 (entity, &pipe->entities, list_pipe) {
F_80 ( V_6 , V_67 -> V_103 ) ;
if ( V_6 -> V_78 -> V_105 )
V_6 -> V_78 -> V_105 ( V_6 , V_67 , V_67 -> V_103 ,
V_168 ) ;
}
return 0 ;
}
static int F_81 ( struct V_152 * V_153 , unsigned int V_169 )
{
struct V_8 * V_9 = F_71 ( V_153 ) ;
struct V_66 * V_67 = V_9 -> V_19 -> V_67 ;
unsigned long V_88 ;
int V_13 ;
F_67 ( & V_67 -> V_170 ) ;
if ( V_67 -> V_171 == V_67 -> V_145 ) {
V_13 = F_78 ( V_67 ) ;
if ( V_13 < 0 ) {
F_69 ( & V_67 -> V_170 ) ;
return V_13 ;
}
}
V_67 -> V_171 ++ ;
F_69 ( & V_67 -> V_170 ) ;
F_21 ( & V_67 -> V_89 , V_88 ) ;
if ( F_41 ( V_67 ) )
F_33 ( V_67 ) ;
F_23 ( & V_67 -> V_89 , V_88 ) ;
return 0 ;
}
static void F_82 ( struct V_152 * V_153 )
{
struct V_8 * V_9 = F_71 ( V_153 ) ;
struct V_66 * V_67 = V_9 -> V_19 -> V_67 ;
struct V_85 * V_172 ;
unsigned long V_88 ;
int V_13 ;
F_21 ( & V_9 -> V_89 , V_88 ) ;
V_67 -> V_100 &= ~ ( 1 << V_9 -> V_101 ) ;
F_23 ( & V_9 -> V_89 , V_88 ) ;
F_67 ( & V_67 -> V_170 ) ;
if ( -- V_67 -> V_171 == V_67 -> V_145 ) {
V_13 = F_83 ( V_67 ) ;
if ( V_13 == - V_173 )
F_35 ( V_9 -> V_41 -> V_109 , L_2 ) ;
F_84 ( V_67 -> V_103 ) ;
V_67 -> V_103 = NULL ;
}
F_69 ( & V_67 -> V_170 ) ;
F_85 ( & V_9 -> V_9 . V_6 ) ;
F_66 ( V_67 ) ;
F_21 ( & V_9 -> V_89 , V_88 ) ;
F_17 (buffer, &video->irqqueue, queue)
F_30 ( & V_172 -> V_93 . V_95 , V_174 ) ;
F_86 ( & V_9 -> V_90 ) ;
F_23 ( & V_9 -> V_89 , V_88 ) ;
}
static int
F_87 ( struct V_175 * V_175 , void * V_176 , struct V_177 * V_178 )
{
struct V_179 * V_180 = V_175 -> V_181 ;
struct V_8 * V_9 = F_88 ( V_180 -> V_182 ) ;
V_178 -> V_183 = V_184 | V_185
| V_186
| V_187 ;
if ( V_9 -> type == V_188 )
V_178 -> V_189 = V_186
| V_185 ;
else
V_178 -> V_189 = V_187
| V_185 ;
F_89 ( V_178 -> V_190 , L_3 , sizeof( V_178 -> V_190 ) ) ;
F_89 ( V_178 -> V_191 , V_9 -> V_9 . V_192 , sizeof( V_178 -> V_191 ) ) ;
snprintf ( V_178 -> V_193 , sizeof( V_178 -> V_193 ) , L_4 ,
F_90 ( V_9 -> V_41 -> V_109 ) ) ;
return 0 ;
}
static int
F_91 ( struct V_175 * V_175 , void * V_176 , struct V_194 * V_22 )
{
struct V_179 * V_180 = V_175 -> V_181 ;
struct V_8 * V_9 = F_88 ( V_180 -> V_182 ) ;
if ( V_22 -> type != V_9 -> V_91 . type )
return - V_14 ;
F_67 ( & V_9 -> V_170 ) ;
V_22 -> V_11 . V_195 = V_9 -> V_19 -> V_22 ;
F_69 ( & V_9 -> V_170 ) ;
return 0 ;
}
static int
F_92 ( struct V_175 * V_175 , void * V_176 , struct V_194 * V_22 )
{
struct V_179 * V_180 = V_175 -> V_181 ;
struct V_8 * V_9 = F_88 ( V_180 -> V_182 ) ;
if ( V_22 -> type != V_9 -> V_91 . type )
return - V_14 ;
return F_7 ( V_9 , & V_22 -> V_11 . V_195 , NULL ) ;
}
static int
F_93 ( struct V_175 * V_175 , void * V_176 , struct V_194 * V_22 )
{
struct V_179 * V_180 = V_175 -> V_181 ;
struct V_8 * V_9 = F_88 ( V_180 -> V_182 ) ;
const struct V_28 * V_38 ;
int V_13 ;
if ( V_22 -> type != V_9 -> V_91 . type )
return - V_14 ;
V_13 = F_7 ( V_9 , & V_22 -> V_11 . V_195 , & V_38 ) ;
if ( V_13 < 0 )
return V_13 ;
F_67 ( & V_9 -> V_170 ) ;
if ( F_94 ( & V_9 -> V_91 ) ) {
V_13 = - V_196 ;
goto V_87;
}
V_9 -> V_19 -> V_22 = V_22 -> V_11 . V_195 ;
V_9 -> V_19 -> V_20 = V_38 ;
V_87:
F_69 ( & V_9 -> V_170 ) ;
return V_13 ;
}
static int
F_95 ( struct V_175 * V_175 , void * V_176 , enum V_197 type )
{
struct V_179 * V_180 = V_175 -> V_181 ;
struct V_8 * V_9 = F_88 ( V_180 -> V_182 ) ;
struct V_138 * V_139 = & V_9 -> V_41 -> V_121 ;
struct V_66 * V_67 ;
int V_13 ;
if ( V_9 -> V_91 . V_198 && V_9 -> V_91 . V_198 != V_175 -> V_181 )
return - V_196 ;
F_67 ( & V_139 -> V_151 ) ;
V_67 = F_57 ( V_9 ) ;
if ( F_96 ( V_67 ) ) {
F_69 ( & V_139 -> V_151 ) ;
return F_97 ( V_67 ) ;
}
V_13 = F_98 ( & V_9 -> V_9 . V_6 , & V_67 -> V_67 ) ;
if ( V_13 < 0 ) {
F_69 ( & V_139 -> V_151 ) ;
goto V_199;
}
F_69 ( & V_139 -> V_151 ) ;
V_13 = F_5 ( V_9 ) ;
if ( V_13 < 0 )
goto V_200;
V_13 = F_99 ( & V_9 -> V_91 , type ) ;
if ( V_13 < 0 )
goto V_200;
return 0 ;
V_200:
F_85 ( & V_9 -> V_9 . V_6 ) ;
V_199:
F_66 ( V_67 ) ;
return V_13 ;
}
static int F_100 ( struct V_175 * V_175 )
{
struct V_8 * V_9 = F_101 ( V_175 ) ;
struct V_179 * V_180 ;
int V_13 = 0 ;
V_180 = F_58 ( sizeof( * V_180 ) , V_148 ) ;
if ( V_180 == NULL )
return - V_149 ;
F_102 ( V_180 , & V_9 -> V_9 ) ;
F_103 ( V_180 ) ;
V_175 -> V_181 = V_180 ;
V_13 = F_104 ( V_9 -> V_41 ) ;
if ( V_13 < 0 ) {
F_105 ( V_180 ) ;
F_61 ( V_180 ) ;
}
return V_13 ;
}
static int F_106 ( struct V_175 * V_175 )
{
struct V_8 * V_9 = F_101 ( V_175 ) ;
struct V_179 * V_180 = V_175 -> V_181 ;
F_67 ( & V_9 -> V_170 ) ;
if ( V_9 -> V_91 . V_198 == V_180 ) {
F_107 ( & V_9 -> V_91 ) ;
V_9 -> V_91 . V_198 = NULL ;
}
F_69 ( & V_9 -> V_170 ) ;
F_108 ( V_9 -> V_41 ) ;
F_109 ( V_175 ) ;
V_175 -> V_181 = NULL ;
return 0 ;
}
struct V_8 * F_110 ( struct V_68 * V_41 ,
struct V_98 * V_19 )
{
struct V_8 * V_9 ;
const char * V_201 ;
int V_13 ;
V_9 = F_111 ( V_41 -> V_109 , sizeof( * V_9 ) , V_148 ) ;
if ( ! V_9 )
return F_59 ( - V_149 ) ;
V_19 -> V_9 = V_9 ;
V_9 -> V_41 = V_41 ;
V_9 -> V_19 = V_19 ;
if ( V_19 -> V_6 . type == V_144 ) {
V_201 = L_5 ;
V_9 -> type = V_202 ;
V_9 -> V_4 . V_88 = V_203 ;
V_9 -> V_9 . V_204 = V_205 ;
} else {
V_201 = L_6 ;
V_9 -> type = V_188 ;
V_9 -> V_4 . V_88 = V_206 ;
V_9 -> V_9 . V_204 = V_207 ;
}
F_112 ( & V_9 -> V_170 ) ;
F_113 ( & V_9 -> V_89 ) ;
F_86 ( & V_9 -> V_90 ) ;
V_13 = F_114 ( & V_9 -> V_9 . V_6 , 1 , & V_9 -> V_4 ) ;
if ( V_13 < 0 )
return F_59 ( V_13 ) ;
V_19 -> V_22 . V_40 = V_42 ;
V_19 -> V_22 . V_25 = V_208 ;
V_19 -> V_22 . V_24 = V_209 ;
F_7 ( V_9 , & V_19 -> V_22 , & V_19 -> V_20 ) ;
V_9 -> V_9 . V_210 = & V_9 -> V_41 -> V_210 ;
V_9 -> V_9 . V_211 = & V_212 ;
snprintf ( V_9 -> V_9 . V_192 , sizeof( V_9 -> V_9 . V_192 ) , L_7 ,
V_19 -> V_6 . V_12 . V_192 , V_201 ) ;
V_9 -> V_9 . V_213 = V_214 ;
V_9 -> V_9 . V_215 = V_216 ;
V_9 -> V_9 . V_217 = & V_218 ;
F_115 ( & V_9 -> V_9 , V_9 ) ;
V_9 -> V_91 . type = V_9 -> type ;
V_9 -> V_91 . V_219 = V_220 | V_221 | V_222 ;
V_9 -> V_91 . V_170 = & V_9 -> V_170 ;
V_9 -> V_91 . V_223 = V_9 ;
V_9 -> V_91 . V_224 = sizeof( struct V_85 ) ;
V_9 -> V_91 . V_78 = & V_225 ;
V_9 -> V_91 . V_226 = & V_227 ;
V_9 -> V_91 . V_228 = V_229 ;
V_9 -> V_91 . V_109 = V_9 -> V_41 -> V_109 ;
V_13 = F_116 ( & V_9 -> V_91 ) ;
if ( V_13 < 0 ) {
F_35 ( V_9 -> V_41 -> V_109 , L_8 ) ;
goto error;
}
V_9 -> V_9 . V_91 = & V_9 -> V_91 ;
V_13 = F_117 ( & V_9 -> V_9 , V_214 , - 1 ) ;
if ( V_13 < 0 ) {
F_35 ( V_9 -> V_41 -> V_109 , L_9 ) ;
goto error;
}
return V_9 ;
error:
F_118 ( V_9 ) ;
return F_59 ( V_13 ) ;
}
void F_118 ( struct V_8 * V_9 )
{
if ( F_119 ( & V_9 -> V_9 ) )
F_120 ( & V_9 -> V_9 ) ;
F_121 ( & V_9 -> V_9 . V_6 ) ;
}
