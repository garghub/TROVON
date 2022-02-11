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
memset ( V_27 -> V_48 , 0 , sizeof( V_27 -> V_48 ) ) ;
V_25 = F_10 ( V_25 , V_38 -> V_49 ) ;
V_24 = F_10 ( V_24 , V_38 -> V_50 ) ;
V_27 -> V_25 = F_11 ( V_25 , V_51 , V_52 ) ;
V_27 -> V_24 = F_11 ( V_24 , V_53 ,
V_54 ) ;
for ( V_39 = 0 ; V_39 < F_12 ( V_38 -> V_55 , 2U ) ; ++ V_39 ) {
unsigned int V_49 = V_39 > 0 ? V_38 -> V_49 : 1 ;
unsigned int V_50 = V_39 > 0 ? V_38 -> V_50 : 1 ;
unsigned int V_56 = 128 ;
unsigned int V_57 ;
V_57 = F_13 (unsigned int, pix->plane_fmt[i].bytesperline,
pix->width / hsub * info->bpp[i] / 8 ,
round_down(65535U, align)) ;
V_27 -> V_58 [ V_39 ] . V_59 = F_14 ( V_57 , V_56 ) ;
V_27 -> V_58 [ V_39 ] . V_60 = V_27 -> V_58 [ V_39 ] . V_59
* V_27 -> V_24 / V_50 ;
}
if ( V_38 -> V_55 == 3 ) {
V_27 -> V_58 [ 2 ] . V_59 = V_27 -> V_58 [ 1 ] . V_59 ;
V_27 -> V_58 [ 2 ] . V_60 = V_27 -> V_58 [ 1 ] . V_60 ;
}
V_27 -> V_61 = V_38 -> V_55 ;
if ( V_20 )
* V_20 = V_38 ;
return 0 ;
}
static void F_15 ( struct V_62 * V_63 )
{
struct V_64 * V_41 = V_63 -> V_65 -> V_6 . V_41 ;
const struct V_66 * V_22 ;
struct V_67 * V_6 ;
unsigned int V_68 ;
V_22 = F_16 ( & V_63 -> V_65 -> V_6 ,
V_63 -> V_65 -> V_6 . V_69 ,
V_70 ) ;
V_68 = V_22 -> V_25 ;
if ( V_41 -> V_38 -> V_71 == 2 ) {
V_63 -> V_68 = V_68 ;
V_63 -> V_72 = 1 ;
return;
}
F_17 (entity, &pipe->entities, list_pipe) {
unsigned int V_73 = V_52 ;
if ( V_6 -> V_74 -> V_75 ) {
V_73 = V_6 -> V_74 -> V_75 ( V_6 , V_63 ) ;
if ( V_73 )
V_68 = F_12 ( V_68 , V_73 ) ;
}
}
V_63 -> V_68 = V_68 ;
V_63 -> V_72 = F_18 ( V_22 -> V_25 , V_68 ) ;
}
static struct V_76 F_19 ( struct V_62 * V_63 ,
unsigned int V_68 ,
unsigned int V_7 )
{
const struct V_66 * V_22 ;
struct V_76 V_77 ;
unsigned int V_78 ;
V_22 = F_16 ( & V_63 -> V_65 -> V_6 ,
V_63 -> V_65 -> V_6 . V_69 ,
V_70 ) ;
if ( V_63 -> V_72 <= 1 ) {
V_77 . V_79 = 0 ;
V_77 . V_80 = 0 ;
V_77 . V_25 = V_22 -> V_25 ;
V_77 . V_24 = V_22 -> V_24 ;
return V_77 ;
}
V_77 . V_79 = V_7 * V_68 ;
V_77 . V_80 = 0 ;
V_77 . V_25 = V_68 ;
V_77 . V_24 = V_22 -> V_24 ;
V_78 = V_22 -> V_25 % V_68 ;
if ( V_78 ) {
unsigned int V_72 = V_63 -> V_72 - 1 ;
if ( V_78 < V_68 / 2 ) {
if ( V_7 == V_72 - 1 ) {
V_77 . V_25 = V_68 / 2 ;
} else if ( V_7 == V_72 ) {
V_77 . V_25 = ( V_68 / 2 ) + V_78 ;
V_77 . V_79 -= V_68 / 2 ;
}
} else if ( V_7 == V_72 ) {
V_77 . V_25 = V_78 ;
}
}
return V_77 ;
}
static struct V_81 *
F_20 ( struct V_8 * V_9 )
{
struct V_62 * V_63 = V_9 -> V_19 -> V_63 ;
struct V_81 * V_82 = NULL ;
struct V_81 * V_83 ;
unsigned long V_84 ;
unsigned int V_39 ;
F_21 ( & V_9 -> V_85 , V_84 ) ;
if ( F_22 ( & V_9 -> V_86 ) ) {
F_23 ( & V_9 -> V_85 , V_84 ) ;
return NULL ;
}
V_83 = F_24 ( & V_9 -> V_86 ,
struct V_81 , V_87 ) ;
if ( V_63 -> V_88 && F_25 ( & V_9 -> V_86 ) ) {
F_23 ( & V_9 -> V_85 , V_84 ) ;
return V_83 ;
}
F_26 ( & V_83 -> V_87 ) ;
if ( ! F_22 ( & V_9 -> V_86 ) )
V_82 = F_24 ( & V_9 -> V_86 ,
struct V_81 , V_87 ) ;
F_23 ( & V_9 -> V_85 , V_84 ) ;
V_83 -> V_89 . V_90 = V_63 -> V_90 ;
V_83 -> V_89 . V_91 . V_92 = F_27 () ;
for ( V_39 = 0 ; V_39 < V_83 -> V_89 . V_91 . V_61 ; ++ V_39 )
F_28 ( & V_83 -> V_89 . V_91 , V_39 ,
F_29 ( & V_83 -> V_89 . V_91 , V_39 ) ) ;
F_30 ( & V_83 -> V_89 . V_91 , V_93 ) ;
return V_82 ;
}
static void F_31 ( struct V_62 * V_63 ,
struct V_94 * V_19 )
{
struct V_8 * V_9 = V_19 -> V_9 ;
struct V_81 * V_89 ;
V_89 = F_20 ( V_9 ) ;
if ( V_89 == NULL )
return;
V_9 -> V_19 -> V_95 = V_89 -> V_95 ;
V_63 -> V_96 |= 1 << V_9 -> V_97 ;
}
static void F_32 ( struct V_62 * V_63 ,
struct V_98 * V_99 )
{
struct V_67 * V_6 ;
V_63 -> V_77 = F_19 ( V_63 , V_63 -> V_68 ,
V_63 -> V_100 ) ;
F_17 (entity, &pipe->entities, list_pipe) {
if ( V_6 -> V_74 -> V_101 )
V_6 -> V_74 -> V_101 ( V_6 , V_63 , V_99 ,
V_102 ) ;
}
}
static void F_33 ( struct V_62 * V_63 )
{
struct V_64 * V_41 = V_63 -> V_65 -> V_6 . V_41 ;
struct V_67 * V_6 ;
if ( ! V_63 -> V_99 )
V_63 -> V_99 = F_34 ( V_63 -> V_65 -> V_103 ) ;
F_17 (entity, &pipe->entities, list_pipe) {
if ( V_6 -> V_74 -> V_101 )
V_6 -> V_74 -> V_101 ( V_6 , V_63 , V_63 -> V_99 ,
V_104 ) ;
}
V_63 -> V_100 = 0 ;
F_32 ( V_63 , V_63 -> V_99 ) ;
for ( V_63 -> V_100 = 1 ;
V_63 -> V_100 < V_63 -> V_72 ;
V_63 -> V_100 ++ ) {
struct V_98 * V_99 ;
V_99 = F_34 ( V_63 -> V_65 -> V_103 ) ;
if ( ! V_99 ) {
F_35 ( V_41 -> V_105 , L_1 ) ;
break;
}
F_32 ( V_63 , V_99 ) ;
F_36 ( V_63 -> V_99 , V_99 ) ;
}
F_37 ( V_63 -> V_99 ) ;
V_63 -> V_99 = NULL ;
F_38 ( V_63 ) ;
}
static void F_39 ( struct V_62 * V_63 )
{
struct V_64 * V_41 = V_63 -> V_65 -> V_6 . V_41 ;
enum V_106 V_107 ;
unsigned long V_84 ;
unsigned int V_39 ;
F_21 ( & V_63 -> V_85 , V_84 ) ;
for ( V_39 = 0 ; V_39 < V_41 -> V_38 -> V_108 ; ++ V_39 ) {
if ( ! V_63 -> V_109 [ V_39 ] )
continue;
F_31 ( V_63 , V_63 -> V_109 [ V_39 ] ) ;
}
F_31 ( V_63 , V_63 -> V_65 ) ;
V_107 = V_63 -> V_107 ;
V_63 -> V_107 = V_110 ;
if ( V_107 == V_111 )
F_40 ( & V_63 -> V_112 ) ;
else if ( F_41 ( V_63 ) )
F_33 ( V_63 ) ;
F_23 ( & V_63 -> V_85 , V_84 ) ;
}
static int F_42 ( struct V_62 * V_63 ,
struct V_94 * V_113 ,
struct V_94 * V_65 )
{
struct V_114 V_115 ;
struct V_67 * V_6 ;
struct V_2 * V_4 ;
bool V_116 = false ;
int V_13 ;
V_13 = F_43 ( & V_115 , & V_113 -> V_6 . V_41 -> V_117 ) ;
if ( V_13 < 0 )
return V_13 ;
V_4 = F_2 ( & V_113 -> V_6 . V_118 [ V_70 ] ) ;
while ( 1 ) {
if ( V_4 == NULL ) {
V_13 = - V_119 ;
goto V_120;
}
if ( ! F_3 ( V_4 -> V_6 ) ) {
V_13 = - V_119 ;
goto V_120;
}
V_6 = F_44 (
F_4 ( V_4 -> V_6 ) ) ;
if ( V_6 -> type == V_121 ) {
struct V_122 * V_123 = F_45 ( & V_6 -> V_12 ) ;
V_123 -> V_109 [ V_4 -> V_7 ] . V_124 = V_113 ;
V_113 -> V_125 = V_4 -> V_7 ;
V_116 = true ;
}
if ( V_6 -> type == V_126 )
break;
if ( F_46 ( & V_115 ,
& V_6 -> V_12 . V_6 ) ) {
V_13 = - V_119 ;
goto V_120;
}
if ( V_6 -> type == V_127 ) {
if ( V_63 -> V_128 ) {
V_13 = - V_119 ;
goto V_120;
}
V_63 -> V_128 = V_6 ;
V_63 -> V_129 = V_116 ? V_63 -> V_123
: & V_113 -> V_6 ;
}
V_4 = & V_6 -> V_118 [ V_6 -> V_130 ] ;
V_4 = F_2 ( V_4 ) ;
}
if ( V_6 != & V_65 -> V_6 )
V_13 = - V_119 ;
V_120:
F_47 ( & V_115 ) ;
return V_13 ;
}
static int F_48 ( struct V_62 * V_63 ,
struct V_8 * V_9 )
{
struct V_131 V_132 ;
struct V_133 * V_6 = & V_9 -> V_9 . V_6 ;
struct V_134 * V_135 = V_6 -> V_136 . V_135 ;
unsigned int V_39 ;
int V_13 ;
V_13 = F_49 ( & V_132 , V_135 ) ;
if ( V_13 )
return V_13 ;
F_50 ( & V_132 , V_6 ) ;
while ( ( V_6 = F_51 ( & V_132 ) ) ) {
struct V_1 * V_12 ;
struct V_94 * V_19 ;
struct V_67 * V_137 ;
if ( ! F_3 ( V_6 ) )
continue;
V_12 = F_4 ( V_6 ) ;
V_137 = F_44 ( V_12 ) ;
F_52 ( & V_137 -> V_138 , & V_63 -> V_139 ) ;
if ( V_137 -> type == V_140 ) {
V_19 = F_53 ( V_12 ) ;
V_63 -> V_109 [ V_19 -> V_6 . V_7 ] = V_19 ;
V_19 -> V_9 -> V_97 = ++ V_63 -> V_141 ;
V_19 -> V_63 = V_63 ;
} else if ( V_137 -> type == V_126 ) {
V_19 = F_53 ( V_12 ) ;
V_63 -> V_65 = V_19 ;
V_19 -> V_9 -> V_97 = 0 ;
V_19 -> V_63 = V_63 ;
} else if ( V_137 -> type == V_142 ) {
V_63 -> V_88 = V_137 ;
} else if ( V_137 -> type == V_121 ) {
V_63 -> V_123 = V_137 ;
}
}
F_54 ( & V_132 ) ;
if ( V_63 -> V_141 == 0 || ! V_63 -> V_65 )
return - V_119 ;
for ( V_39 = 0 ; V_39 < V_9 -> V_41 -> V_38 -> V_108 ; ++ V_39 ) {
if ( ! V_63 -> V_109 [ V_39 ] )
continue;
V_13 = F_42 ( V_63 , V_63 -> V_109 [ V_39 ] ,
V_63 -> V_65 ) ;
if ( V_13 < 0 )
return V_13 ;
}
return 0 ;
}
static int F_55 ( struct V_62 * V_63 ,
struct V_8 * V_9 )
{
F_56 ( V_63 ) ;
V_63 -> V_143 = F_39 ;
return F_48 ( V_63 , V_9 ) ;
}
static struct V_62 * F_57 ( struct V_8 * V_9 )
{
struct V_62 * V_63 ;
int V_13 ;
if ( ! V_9 -> V_19 -> V_63 ) {
V_63 = F_58 ( sizeof( * V_63 ) , V_144 ) ;
if ( ! V_63 )
return F_59 ( - V_145 ) ;
V_13 = F_55 ( V_63 , V_9 ) ;
if ( V_13 < 0 ) {
F_60 ( V_63 ) ;
F_61 ( V_63 ) ;
return F_59 ( V_13 ) ;
}
} else {
V_63 = V_9 -> V_19 -> V_63 ;
F_62 ( & V_63 -> V_146 ) ;
}
return V_63 ;
}
static void F_63 ( struct V_146 * V_146 )
{
struct V_62 * V_63 = F_64 ( V_146 , F_65 ( * V_63 ) , V_146 ) ;
F_60 ( V_63 ) ;
F_61 ( V_63 ) ;
}
static void F_66 ( struct V_62 * V_63 )
{
struct V_134 * V_135 = & V_63 -> V_65 -> V_6 . V_41 -> V_117 ;
F_67 ( & V_135 -> V_147 ) ;
F_68 ( & V_63 -> V_146 , F_63 ) ;
F_69 ( & V_135 -> V_147 ) ;
}
static int
F_70 ( struct V_148 * V_149 ,
unsigned int * V_150 , unsigned int * V_151 ,
unsigned int V_152 [] , struct V_153 * V_154 [] )
{
struct V_8 * V_9 = F_71 ( V_149 ) ;
const struct V_26 * V_22 = & V_9 -> V_19 -> V_22 ;
unsigned int V_39 ;
if ( * V_151 ) {
if ( * V_151 != V_22 -> V_61 )
return - V_14 ;
for ( V_39 = 0 ; V_39 < * V_151 ; V_39 ++ )
if ( V_152 [ V_39 ] < V_22 -> V_58 [ V_39 ] . V_60 )
return - V_14 ;
return 0 ;
}
* V_151 = V_22 -> V_61 ;
for ( V_39 = 0 ; V_39 < V_22 -> V_61 ; ++ V_39 )
V_152 [ V_39 ] = V_22 -> V_58 [ V_39 ] . V_60 ;
return 0 ;
}
static int F_72 ( struct V_155 * V_156 )
{
struct V_157 * V_158 = F_73 ( V_156 ) ;
struct V_8 * V_9 = F_71 ( V_156 -> V_148 ) ;
struct V_81 * V_89 = F_74 ( V_158 ) ;
const struct V_26 * V_22 = & V_9 -> V_19 -> V_22 ;
unsigned int V_39 ;
if ( V_156 -> V_61 < V_22 -> V_61 )
return - V_14 ;
for ( V_39 = 0 ; V_39 < V_156 -> V_61 ; ++ V_39 ) {
V_89 -> V_95 . V_159 [ V_39 ] = F_75 ( V_156 , V_39 ) ;
if ( F_29 ( V_156 , V_39 ) < V_22 -> V_58 [ V_39 ] . V_60 )
return - V_14 ;
}
for ( ; V_39 < 3 ; ++ V_39 )
V_89 -> V_95 . V_159 [ V_39 ] = 0 ;
return 0 ;
}
static void F_76 ( struct V_155 * V_156 )
{
struct V_157 * V_158 = F_73 ( V_156 ) ;
struct V_8 * V_9 = F_71 ( V_156 -> V_148 ) ;
struct V_62 * V_63 = V_9 -> V_19 -> V_63 ;
struct V_81 * V_89 = F_74 ( V_158 ) ;
unsigned long V_84 ;
bool V_160 ;
F_21 ( & V_9 -> V_85 , V_84 ) ;
V_160 = F_22 ( & V_9 -> V_86 ) ;
F_52 ( & V_89 -> V_87 , & V_9 -> V_86 ) ;
F_23 ( & V_9 -> V_85 , V_84 ) ;
if ( ! V_160 )
return;
F_21 ( & V_63 -> V_85 , V_84 ) ;
V_9 -> V_19 -> V_95 = V_89 -> V_95 ;
V_63 -> V_96 |= 1 << V_9 -> V_97 ;
if ( F_77 ( & V_9 -> V_87 ) &&
F_41 ( V_63 ) )
F_33 ( V_63 ) ;
F_23 ( & V_63 -> V_85 , V_84 ) ;
}
static int F_78 ( struct V_62 * V_63 )
{
struct V_67 * V_6 ;
F_15 ( V_63 ) ;
V_63 -> V_99 = F_34 ( V_63 -> V_65 -> V_103 ) ;
if ( ! V_63 -> V_99 )
return - V_145 ;
if ( V_63 -> V_128 ) {
struct V_161 * V_128 = F_79 ( & V_63 -> V_128 -> V_12 ) ;
if ( V_63 -> V_129 -> type == V_121 ) {
V_128 -> V_162 = false ;
} else {
struct V_94 * V_124 =
F_53 ( & V_63 -> V_129 -> V_12 ) ;
V_128 -> V_162 = V_124 -> V_20 -> V_163 ;
}
}
F_17 (entity, &pipe->entities, list_pipe) {
F_80 ( V_6 , V_63 -> V_99 ) ;
if ( V_6 -> V_74 -> V_101 )
V_6 -> V_74 -> V_101 ( V_6 , V_63 , V_63 -> V_99 ,
V_164 ) ;
}
return 0 ;
}
static int F_81 ( struct V_148 * V_149 , unsigned int V_165 )
{
struct V_8 * V_9 = F_71 ( V_149 ) ;
struct V_62 * V_63 = V_9 -> V_19 -> V_63 ;
unsigned long V_84 ;
int V_13 ;
F_67 ( & V_63 -> V_166 ) ;
if ( V_63 -> V_167 == V_63 -> V_141 ) {
V_13 = F_78 ( V_63 ) ;
if ( V_13 < 0 ) {
F_69 ( & V_63 -> V_166 ) ;
return V_13 ;
}
}
V_63 -> V_167 ++ ;
F_69 ( & V_63 -> V_166 ) ;
F_21 ( & V_63 -> V_85 , V_84 ) ;
if ( F_41 ( V_63 ) )
F_33 ( V_63 ) ;
F_23 ( & V_63 -> V_85 , V_84 ) ;
return 0 ;
}
static void F_82 ( struct V_148 * V_149 )
{
struct V_8 * V_9 = F_71 ( V_149 ) ;
struct V_62 * V_63 = V_9 -> V_19 -> V_63 ;
struct V_81 * V_168 ;
unsigned long V_84 ;
int V_13 ;
F_21 ( & V_9 -> V_85 , V_84 ) ;
V_63 -> V_96 &= ~ ( 1 << V_9 -> V_97 ) ;
F_23 ( & V_9 -> V_85 , V_84 ) ;
F_67 ( & V_63 -> V_166 ) ;
if ( -- V_63 -> V_167 == V_63 -> V_141 ) {
V_13 = F_83 ( V_63 ) ;
if ( V_13 == - V_169 )
F_35 ( V_9 -> V_41 -> V_105 , L_2 ) ;
F_84 ( V_63 -> V_99 ) ;
V_63 -> V_99 = NULL ;
}
F_69 ( & V_63 -> V_166 ) ;
F_85 ( & V_9 -> V_9 . V_6 ) ;
F_66 ( V_63 ) ;
F_21 ( & V_9 -> V_85 , V_84 ) ;
F_17 (buffer, &video->irqqueue, queue)
F_30 ( & V_168 -> V_89 . V_91 , V_170 ) ;
F_86 ( & V_9 -> V_86 ) ;
F_23 ( & V_9 -> V_85 , V_84 ) ;
}
static int
F_87 ( struct V_171 * V_171 , void * V_172 , struct V_173 * V_174 )
{
struct V_175 * V_176 = V_171 -> V_177 ;
struct V_8 * V_9 = F_88 ( V_176 -> V_178 ) ;
V_174 -> V_179 = V_180 | V_181
| V_182
| V_183 ;
if ( V_9 -> type == V_184 )
V_174 -> V_185 = V_182
| V_181 ;
else
V_174 -> V_185 = V_183
| V_181 ;
F_89 ( V_174 -> V_186 , L_3 , sizeof( V_174 -> V_186 ) ) ;
F_89 ( V_174 -> V_187 , V_9 -> V_9 . V_188 , sizeof( V_174 -> V_187 ) ) ;
snprintf ( V_174 -> V_189 , sizeof( V_174 -> V_189 ) , L_4 ,
F_90 ( V_9 -> V_41 -> V_105 ) ) ;
return 0 ;
}
static int
F_91 ( struct V_171 * V_171 , void * V_172 , struct V_190 * V_22 )
{
struct V_175 * V_176 = V_171 -> V_177 ;
struct V_8 * V_9 = F_88 ( V_176 -> V_178 ) ;
if ( V_22 -> type != V_9 -> V_87 . type )
return - V_14 ;
F_67 ( & V_9 -> V_166 ) ;
V_22 -> V_11 . V_191 = V_9 -> V_19 -> V_22 ;
F_69 ( & V_9 -> V_166 ) ;
return 0 ;
}
static int
F_92 ( struct V_171 * V_171 , void * V_172 , struct V_190 * V_22 )
{
struct V_175 * V_176 = V_171 -> V_177 ;
struct V_8 * V_9 = F_88 ( V_176 -> V_178 ) ;
if ( V_22 -> type != V_9 -> V_87 . type )
return - V_14 ;
return F_7 ( V_9 , & V_22 -> V_11 . V_191 , NULL ) ;
}
static int
F_93 ( struct V_171 * V_171 , void * V_172 , struct V_190 * V_22 )
{
struct V_175 * V_176 = V_171 -> V_177 ;
struct V_8 * V_9 = F_88 ( V_176 -> V_178 ) ;
const struct V_28 * V_38 ;
int V_13 ;
if ( V_22 -> type != V_9 -> V_87 . type )
return - V_14 ;
V_13 = F_7 ( V_9 , & V_22 -> V_11 . V_191 , & V_38 ) ;
if ( V_13 < 0 )
return V_13 ;
F_67 ( & V_9 -> V_166 ) ;
if ( F_94 ( & V_9 -> V_87 ) ) {
V_13 = - V_192 ;
goto V_83;
}
V_9 -> V_19 -> V_22 = V_22 -> V_11 . V_191 ;
V_9 -> V_19 -> V_20 = V_38 ;
V_83:
F_69 ( & V_9 -> V_166 ) ;
return V_13 ;
}
static int
F_95 ( struct V_171 * V_171 , void * V_172 , enum V_193 type )
{
struct V_175 * V_176 = V_171 -> V_177 ;
struct V_8 * V_9 = F_88 ( V_176 -> V_178 ) ;
struct V_134 * V_135 = & V_9 -> V_41 -> V_117 ;
struct V_62 * V_63 ;
int V_13 ;
if ( V_9 -> V_87 . V_194 && V_9 -> V_87 . V_194 != V_171 -> V_177 )
return - V_192 ;
F_67 ( & V_135 -> V_147 ) ;
V_63 = F_57 ( V_9 ) ;
if ( F_96 ( V_63 ) ) {
F_69 ( & V_135 -> V_147 ) ;
return F_97 ( V_63 ) ;
}
V_13 = F_98 ( & V_9 -> V_9 . V_6 , & V_63 -> V_63 ) ;
if ( V_13 < 0 ) {
F_69 ( & V_135 -> V_147 ) ;
goto V_195;
}
F_69 ( & V_135 -> V_147 ) ;
V_13 = F_5 ( V_9 ) ;
if ( V_13 < 0 )
goto V_196;
V_13 = F_99 ( & V_9 -> V_87 , type ) ;
if ( V_13 < 0 )
goto V_196;
return 0 ;
V_196:
F_85 ( & V_9 -> V_9 . V_6 ) ;
V_195:
F_66 ( V_63 ) ;
return V_13 ;
}
static int F_100 ( struct V_171 * V_171 )
{
struct V_8 * V_9 = F_101 ( V_171 ) ;
struct V_175 * V_176 ;
int V_13 = 0 ;
V_176 = F_58 ( sizeof( * V_176 ) , V_144 ) ;
if ( V_176 == NULL )
return - V_145 ;
F_102 ( V_176 , & V_9 -> V_9 ) ;
F_103 ( V_176 ) ;
V_171 -> V_177 = V_176 ;
V_13 = F_104 ( V_9 -> V_41 ) ;
if ( V_13 < 0 ) {
F_105 ( V_176 ) ;
F_61 ( V_176 ) ;
}
return V_13 ;
}
static int F_106 ( struct V_171 * V_171 )
{
struct V_8 * V_9 = F_101 ( V_171 ) ;
struct V_175 * V_176 = V_171 -> V_177 ;
F_67 ( & V_9 -> V_166 ) ;
if ( V_9 -> V_87 . V_194 == V_176 ) {
F_107 ( & V_9 -> V_87 ) ;
V_9 -> V_87 . V_194 = NULL ;
}
F_69 ( & V_9 -> V_166 ) ;
F_108 ( V_9 -> V_41 ) ;
F_109 ( V_171 ) ;
V_171 -> V_177 = NULL ;
return 0 ;
}
struct V_8 * F_110 ( struct V_64 * V_41 ,
struct V_94 * V_19 )
{
struct V_8 * V_9 ;
const char * V_197 ;
int V_13 ;
V_9 = F_111 ( V_41 -> V_105 , sizeof( * V_9 ) , V_144 ) ;
if ( ! V_9 )
return F_59 ( - V_145 ) ;
V_19 -> V_9 = V_9 ;
V_9 -> V_41 = V_41 ;
V_9 -> V_19 = V_19 ;
if ( V_19 -> V_6 . type == V_140 ) {
V_197 = L_5 ;
V_9 -> type = V_198 ;
V_9 -> V_4 . V_84 = V_199 ;
V_9 -> V_9 . V_200 = V_201 ;
} else {
V_197 = L_6 ;
V_9 -> type = V_184 ;
V_9 -> V_4 . V_84 = V_202 ;
V_9 -> V_9 . V_200 = V_203 ;
}
F_112 ( & V_9 -> V_166 ) ;
F_113 ( & V_9 -> V_85 ) ;
F_86 ( & V_9 -> V_86 ) ;
V_13 = F_114 ( & V_9 -> V_9 . V_6 , 1 , & V_9 -> V_4 ) ;
if ( V_13 < 0 )
return F_59 ( V_13 ) ;
V_19 -> V_22 . V_40 = V_42 ;
V_19 -> V_22 . V_25 = V_204 ;
V_19 -> V_22 . V_24 = V_205 ;
F_7 ( V_9 , & V_19 -> V_22 , & V_19 -> V_20 ) ;
V_9 -> V_9 . V_206 = & V_9 -> V_41 -> V_206 ;
V_9 -> V_9 . V_207 = & V_208 ;
snprintf ( V_9 -> V_9 . V_188 , sizeof( V_9 -> V_9 . V_188 ) , L_7 ,
V_19 -> V_6 . V_12 . V_188 , V_197 ) ;
V_9 -> V_9 . V_209 = V_210 ;
V_9 -> V_9 . V_211 = V_212 ;
V_9 -> V_9 . V_213 = & V_214 ;
F_115 ( & V_9 -> V_9 , V_9 ) ;
V_9 -> V_87 . type = V_9 -> type ;
V_9 -> V_87 . V_215 = V_216 | V_217 | V_218 ;
V_9 -> V_87 . V_166 = & V_9 -> V_166 ;
V_9 -> V_87 . V_219 = V_9 ;
V_9 -> V_87 . V_220 = sizeof( struct V_81 ) ;
V_9 -> V_87 . V_74 = & V_221 ;
V_9 -> V_87 . V_222 = & V_223 ;
V_9 -> V_87 . V_224 = V_225 ;
V_9 -> V_87 . V_105 = V_9 -> V_41 -> V_105 ;
V_13 = F_116 ( & V_9 -> V_87 ) ;
if ( V_13 < 0 ) {
F_35 ( V_9 -> V_41 -> V_105 , L_8 ) ;
goto error;
}
V_9 -> V_9 . V_87 = & V_9 -> V_87 ;
V_13 = F_117 ( & V_9 -> V_9 , V_210 , - 1 ) ;
if ( V_13 < 0 ) {
F_35 ( V_9 -> V_41 -> V_105 , L_9 ) ;
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
