static const struct V_1 * F_1 ( T_1 V_2 )
{
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; ++ V_3 ) {
const struct V_1 * V_5 = & V_4 [ V_3 ] ;
if ( V_5 -> V_2 == V_2 )
return V_5 ;
}
return NULL ;
}
static struct V_6 *
F_3 ( struct V_7 * V_8 , T_1 * V_9 )
{
struct V_7 * V_10 ;
V_10 = F_4 ( V_8 ) ;
if ( V_10 == NULL ||
F_5 ( V_10 -> V_11 ) != V_12 )
return NULL ;
if ( V_9 )
* V_9 = V_10 -> V_13 ;
return F_6 ( V_10 -> V_11 ) ;
}
static int F_7 ( struct V_14 * V_15 )
{
struct V_16 V_17 ;
struct V_6 * V_18 ;
int V_19 ;
V_18 = F_3 ( & V_15 -> V_9 , & V_17 . V_9 ) ;
if ( V_18 == NULL )
return - V_20 ;
V_17 . V_21 = V_22 ;
V_19 = F_8 ( V_18 , V_9 , V_23 , NULL , & V_17 ) ;
if ( V_19 < 0 )
return V_19 == - V_24 ? - V_20 : V_19 ;
if ( V_15 -> V_25 -> V_26 != V_17 . V_27 . V_28 ||
V_15 -> V_27 . V_29 != V_17 . V_27 . V_29 ||
V_15 -> V_27 . V_30 != V_17 . V_27 . V_30 )
return - V_20 ;
return 0 ;
}
static int F_9 ( struct V_14 * V_15 ,
struct V_31 * V_32 ,
const struct V_1 * * V_25 )
{
static const T_1 V_33 [] [ 2 ] = {
{ V_34 , V_35 } ,
{ V_36 , V_37 } ,
{ V_38 , V_39 } ,
{ V_40 , V_41 } ,
} ;
const struct V_1 * V_5 ;
unsigned int V_30 = V_32 -> V_30 ;
unsigned int V_29 = V_32 -> V_29 ;
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_33 ) ; ++ V_3 ) {
if ( V_33 [ V_3 ] [ 0 ] == V_32 -> V_42 ) {
V_32 -> V_42 = V_33 [ V_3 ] [ 1 ] ;
break;
}
}
V_5 = F_1 ( V_32 -> V_42 ) ;
if ( V_5 == NULL )
V_5 = F_1 ( V_43 ) ;
V_32 -> V_42 = V_5 -> V_2 ;
V_32 -> V_44 = V_45 ;
V_32 -> V_46 = V_47 ;
memset ( V_32 -> V_48 , 0 , sizeof( V_32 -> V_48 ) ) ;
V_30 = F_10 ( V_30 , V_5 -> V_49 ) ;
V_29 = F_10 ( V_29 , V_5 -> V_50 ) ;
V_32 -> V_30 = F_11 ( V_30 , V_51 , V_52 ) ;
V_32 -> V_29 = F_11 ( V_29 , V_53 ,
V_54 ) ;
for ( V_3 = 0 ; V_3 < F_12 ( V_5 -> V_55 , 2U ) ; ++ V_3 ) {
unsigned int V_49 = V_3 > 0 ? V_5 -> V_49 : 1 ;
unsigned int V_50 = V_3 > 0 ? V_5 -> V_50 : 1 ;
unsigned int V_56 = 128 ;
unsigned int V_57 ;
V_57 = F_13 (unsigned int, pix->plane_fmt[i].bytesperline,
pix->width / hsub * info->bpp[i] / 8 ,
round_down(65535U, align)) ;
V_32 -> V_58 [ V_3 ] . V_59 = F_14 ( V_57 , V_56 ) ;
V_32 -> V_58 [ V_3 ] . V_60 = V_32 -> V_58 [ V_3 ] . V_59
* V_32 -> V_29 / V_50 ;
}
if ( V_5 -> V_55 == 3 ) {
V_32 -> V_58 [ 2 ] . V_59 = V_32 -> V_58 [ 1 ] . V_59 ;
V_32 -> V_58 [ 2 ] . V_60 = V_32 -> V_58 [ 1 ] . V_60 ;
}
V_32 -> V_61 = V_5 -> V_55 ;
if ( V_25 )
* V_25 = V_5 ;
return 0 ;
}
static bool
F_15 ( struct V_14 * V_15 ,
const struct V_31 * V_27 ,
struct V_31 * V_62 )
{
unsigned int V_3 ;
* V_62 = * V_27 ;
F_9 ( V_15 , V_62 , NULL ) ;
if ( V_27 -> V_30 != V_62 -> V_30 ||
V_27 -> V_29 != V_62 -> V_29 ||
V_27 -> V_42 != V_62 -> V_42 ||
V_27 -> V_61 != V_62 -> V_61 )
return false ;
for ( V_3 = 0 ; V_3 < V_27 -> V_61 ; ++ V_3 ) {
if ( V_27 -> V_58 [ V_3 ] . V_59 !=
V_62 -> V_58 [ V_3 ] . V_59 )
return false ;
V_62 -> V_58 [ V_3 ] . V_60 =
F_12 ( V_62 -> V_58 [ V_3 ] . V_60 ,
V_27 -> V_58 [ V_3 ] . V_60 ) ;
}
return true ;
}
static int F_16 ( struct V_63 * V_64 ,
struct V_65 * V_66 ,
struct V_65 * V_67 )
{
struct V_68 * V_11 ;
unsigned int V_69 = 0 ;
struct V_7 * V_9 ;
bool V_70 = false ;
V_66 -> V_71 . V_72 = 0 ;
V_66 -> V_71 . V_73 = 0 ;
V_9 = F_4 ( & V_66 -> V_11 . V_74 [ V_75 ] ) ;
while ( 1 ) {
if ( V_9 == NULL )
return - V_76 ;
if ( F_5 ( V_9 -> V_11 ) != V_12 )
return - V_76 ;
V_11 = F_17 ( F_6 ( V_9 -> V_11 ) ) ;
if ( V_11 -> type == V_77 ) {
struct V_78 * V_79 = F_18 ( & V_11 -> V_18 ) ;
struct V_80 * V_81 =
& V_79 -> V_82 [ V_9 -> V_13 ] . V_83 ;
V_79 -> V_82 [ V_9 -> V_13 ] . V_84 = V_66 ;
V_66 -> V_71 . V_72 = V_81 -> V_72 ;
V_66 -> V_71 . V_73 = V_81 -> V_73 ;
V_70 = true ;
}
if ( V_11 -> type == V_85 )
break;
if ( V_69 & ( 1 << V_11 -> V_18 . V_11 . V_86 ) )
return - V_76 ;
V_69 |= 1 << V_11 -> V_18 . V_11 . V_86 ;
if ( V_11 -> type == V_87 ) {
if ( V_64 -> V_88 )
return - V_76 ;
V_64 -> V_88 = V_11 ;
V_64 -> V_89 = V_70 ? V_64 -> V_79
: & V_66 -> V_11 ;
}
V_9 = & V_11 -> V_74 [ V_11 -> V_90 ] ;
V_9 = F_4 ( V_9 ) ;
}
if ( V_11 != & V_67 -> V_11 )
return - V_76 ;
return 0 ;
}
static void F_19 ( struct V_63 * V_64 )
{
if ( V_64 -> V_79 ) {
struct V_78 * V_79 = F_18 ( & V_64 -> V_79 -> V_18 ) ;
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_79 -> V_82 ) ; ++ V_3 )
V_79 -> V_82 [ V_3 ] . V_84 = NULL ;
}
F_20 ( & V_64 -> V_69 ) ;
V_64 -> V_91 = V_92 ;
V_64 -> V_93 = 0 ;
V_64 -> V_94 = 0 ;
V_64 -> V_95 = 0 ;
V_64 -> V_67 = NULL ;
V_64 -> V_79 = NULL ;
V_64 -> V_96 = NULL ;
V_64 -> V_88 = NULL ;
}
static int F_21 ( struct V_63 * V_64 ,
struct V_14 * V_15 )
{
struct V_97 V_98 ;
struct V_99 * V_11 = & V_15 -> V_15 . V_11 ;
struct V_100 * V_101 = V_11 -> V_102 ;
unsigned int V_3 ;
int V_19 ;
F_22 ( & V_101 -> V_103 ) ;
F_23 ( & V_98 , V_11 ) ;
while ( ( V_11 = F_24 ( & V_98 ) ) ) {
struct V_6 * V_18 ;
struct V_65 * V_104 ;
struct V_68 * V_105 ;
if ( F_5 ( V_11 ) != V_12 ) {
V_64 -> V_94 ++ ;
continue;
}
V_18 = F_6 ( V_11 ) ;
V_105 = F_17 ( V_18 ) ;
F_25 ( & V_105 -> V_106 , & V_64 -> V_69 ) ;
if ( V_105 -> type == V_107 ) {
V_104 = F_26 ( V_18 ) ;
V_64 -> V_82 [ V_64 -> V_95 ++ ] = V_104 ;
V_104 -> V_15 . V_108 = V_64 -> V_95 ;
} else if ( V_105 -> type == V_85 ) {
V_104 = F_26 ( V_18 ) ;
V_64 -> V_67 = F_26 ( V_18 ) ;
V_104 -> V_15 . V_108 = 0 ;
} else if ( V_105 -> type == V_109 ) {
V_64 -> V_96 = V_105 ;
} else if ( V_105 -> type == V_77 ) {
V_64 -> V_79 = V_105 ;
}
}
F_27 ( & V_101 -> V_103 ) ;
if ( V_64 -> V_95 == 0 || ! V_64 -> V_67 ) {
V_19 = - V_76 ;
goto error;
}
for ( V_3 = 0 ; V_3 < V_64 -> V_95 ; ++ V_3 ) {
V_19 = F_16 ( V_64 , V_64 -> V_82 [ V_3 ] ,
V_64 -> V_67 ) ;
if ( V_19 < 0 )
goto error;
}
return 0 ;
error:
F_19 ( V_64 ) ;
return V_19 ;
}
static int F_28 ( struct V_63 * V_64 ,
struct V_14 * V_15 )
{
int V_19 ;
F_22 ( & V_64 -> V_110 ) ;
if ( V_64 -> V_111 == 0 ) {
V_19 = F_21 ( V_64 , V_15 ) ;
if ( V_19 < 0 )
goto V_112;
}
V_64 -> V_111 ++ ;
V_19 = 0 ;
V_112:
F_27 ( & V_64 -> V_110 ) ;
return V_19 ;
}
static void F_29 ( struct V_63 * V_64 )
{
F_22 ( & V_64 -> V_110 ) ;
if ( -- V_64 -> V_111 == 0 )
F_19 ( V_64 ) ;
F_27 ( & V_64 -> V_110 ) ;
}
static void F_30 ( struct V_63 * V_64 )
{
struct V_113 * V_114 = V_64 -> V_67 -> V_11 . V_114 ;
F_31 ( V_114 , F_32 ( V_64 -> V_67 -> V_11 . V_13 ) , V_115 ) ;
V_64 -> V_91 = V_116 ;
V_64 -> V_93 = 0 ;
}
static int F_33 ( struct V_63 * V_64 )
{
struct V_68 * V_11 ;
unsigned long V_117 ;
int V_19 ;
F_34 ( & V_64 -> V_118 , V_117 ) ;
if ( V_64 -> V_91 == V_116 )
V_64 -> V_91 = V_119 ;
F_35 ( & V_64 -> V_118 , V_117 ) ;
V_19 = F_36 ( V_64 -> V_120 , V_64 -> V_91 == V_92 ,
F_37 ( 500 ) ) ;
V_19 = V_19 == 0 ? - V_121 : 0 ;
F_38 (entity, &pipe->entities, list_pipe) {
if ( V_11 -> V_122 && V_11 -> V_122 -> V_123 )
F_31 ( V_11 -> V_114 , V_11 -> V_122 -> V_123 ,
V_124 ) ;
F_8 ( & V_11 -> V_18 , V_15 , V_125 , 0 ) ;
}
return V_19 ;
}
static bool F_39 ( struct V_63 * V_64 )
{
unsigned int V_126 ;
V_126 = ( ( 1 << V_64 -> V_95 ) - 1 ) << 1 ;
if ( ! V_64 -> V_96 )
V_126 |= 1 << 0 ;
return V_64 -> V_93 == V_126 ;
}
static struct V_127 *
F_40 ( struct V_14 * V_15 )
{
struct V_63 * V_64 = F_41 ( & V_15 -> V_15 . V_11 ) ;
struct V_127 * V_128 = NULL ;
struct V_127 * V_112 ;
unsigned long V_117 ;
unsigned int V_3 ;
F_34 ( & V_15 -> V_118 , V_117 ) ;
if ( F_42 ( & V_15 -> V_129 ) ) {
F_35 ( & V_15 -> V_118 , V_117 ) ;
return NULL ;
}
V_112 = F_43 ( & V_15 -> V_129 ,
struct V_127 , V_130 ) ;
if ( V_64 -> V_96 && F_44 ( & V_15 -> V_129 ) ) {
F_35 ( & V_15 -> V_118 , V_117 ) ;
return V_112 ;
}
F_45 ( & V_112 -> V_130 ) ;
if ( ! F_42 ( & V_15 -> V_129 ) )
V_128 = F_43 ( & V_15 -> V_129 ,
struct V_127 , V_130 ) ;
F_35 ( & V_15 -> V_118 , V_117 ) ;
V_112 -> V_131 . V_132 . V_133 = V_15 -> V_133 ++ ;
F_46 ( & V_112 -> V_131 . V_132 . V_134 ) ;
for ( V_3 = 0 ; V_3 < V_112 -> V_131 . V_61 ; ++ V_3 )
F_47 ( & V_112 -> V_131 , V_3 , V_112 -> V_135 [ V_3 ] ) ;
F_48 ( & V_112 -> V_131 , V_136 ) ;
return V_128 ;
}
static void F_49 ( struct V_63 * V_64 ,
struct V_14 * V_15 )
{
struct V_127 * V_131 ;
unsigned long V_117 ;
V_131 = F_40 ( V_15 ) ;
if ( V_131 == NULL )
return;
F_34 ( & V_64 -> V_118 , V_117 ) ;
V_15 -> V_137 -> V_130 ( V_15 , V_131 ) ;
V_64 -> V_93 |= 1 << V_15 -> V_108 ;
F_35 ( & V_64 -> V_118 , V_117 ) ;
}
void F_50 ( struct V_63 * V_64 )
{
enum V_138 V_91 ;
unsigned long V_117 ;
unsigned int V_3 ;
if ( V_64 == NULL )
return;
for ( V_3 = 0 ; V_3 < V_64 -> V_95 ; ++ V_3 )
F_49 ( V_64 , & V_64 -> V_82 [ V_3 ] -> V_15 ) ;
if ( ! V_64 -> V_96 )
F_49 ( V_64 , & V_64 -> V_67 -> V_15 ) ;
F_34 ( & V_64 -> V_118 , V_117 ) ;
V_91 = V_64 -> V_91 ;
V_64 -> V_91 = V_92 ;
if ( V_91 == V_119 ) {
F_51 ( & V_64 -> V_120 ) ;
goto V_112;
}
if ( F_39 ( V_64 ) )
F_30 ( V_64 ) ;
V_112:
F_35 ( & V_64 -> V_118 , V_117 ) ;
}
void F_52 ( struct V_63 * V_64 ,
struct V_68 * V_66 ,
unsigned int V_139 )
{
struct V_68 * V_11 ;
struct V_7 * V_9 ;
V_9 = F_4 ( & V_66 -> V_74 [ V_75 ] ) ;
while ( V_9 ) {
if ( F_5 ( V_9 -> V_11 ) != V_12 )
break;
V_11 = F_17 ( F_6 ( V_9 -> V_11 ) ) ;
if ( V_11 -> type == V_77 )
V_139 = 255 ;
if ( V_11 -> type == V_87 ) {
struct V_140 * V_88 = F_53 ( & V_11 -> V_18 ) ;
F_54 ( V_88 , V_139 ) ;
break;
}
V_9 = & V_11 -> V_74 [ V_11 -> V_90 ] ;
V_9 = F_4 ( V_9 ) ;
}
}
static int
F_55 ( struct V_141 * V_142 , const struct V_143 * V_17 ,
unsigned int * V_144 , unsigned int * V_145 ,
unsigned int V_146 [] , void * V_147 [] )
{
struct V_14 * V_15 = F_56 ( V_142 ) ;
const struct V_31 * V_27 ;
struct V_31 V_148 ;
unsigned int V_3 ;
if ( V_17 ) {
if ( ! F_15 ( V_15 , & V_17 -> V_17 . V_148 , & V_148 ) )
return - V_20 ;
V_27 = & V_148 ;
} else {
V_27 = & V_15 -> V_27 ;
}
* V_145 = V_27 -> V_61 ;
for ( V_3 = 0 ; V_3 < V_27 -> V_61 ; ++ V_3 ) {
V_146 [ V_3 ] = V_27 -> V_58 [ V_3 ] . V_60 ;
V_147 [ V_3 ] = V_15 -> V_149 ;
}
return 0 ;
}
static int F_57 ( struct V_150 * V_151 )
{
struct V_14 * V_15 = F_56 ( V_151 -> V_141 ) ;
struct V_127 * V_131 = F_58 ( V_151 ) ;
const struct V_31 * V_27 = & V_15 -> V_27 ;
unsigned int V_3 ;
if ( V_151 -> V_61 < V_27 -> V_61 )
return - V_20 ;
for ( V_3 = 0 ; V_3 < V_151 -> V_61 ; ++ V_3 ) {
V_131 -> V_152 [ V_3 ] = F_59 ( V_151 , V_3 ) ;
V_131 -> V_135 [ V_3 ] = F_60 ( V_151 , V_3 ) ;
if ( V_131 -> V_135 [ V_3 ] < V_27 -> V_58 [ V_3 ] . V_60 )
return - V_20 ;
}
return 0 ;
}
static void F_61 ( struct V_150 * V_151 )
{
struct V_14 * V_15 = F_56 ( V_151 -> V_141 ) ;
struct V_63 * V_64 = F_41 ( & V_15 -> V_15 . V_11 ) ;
struct V_127 * V_131 = F_58 ( V_151 ) ;
unsigned long V_117 ;
bool V_153 ;
F_34 ( & V_15 -> V_118 , V_117 ) ;
V_153 = F_42 ( & V_15 -> V_129 ) ;
F_25 ( & V_131 -> V_130 , & V_15 -> V_129 ) ;
F_35 ( & V_15 -> V_118 , V_117 ) ;
if ( ! V_153 )
return;
F_34 ( & V_64 -> V_118 , V_117 ) ;
V_15 -> V_137 -> V_130 ( V_15 , V_131 ) ;
V_64 -> V_93 |= 1 << V_15 -> V_108 ;
if ( F_62 ( & V_15 -> V_130 ) &&
F_39 ( V_64 ) )
F_30 ( V_64 ) ;
F_35 ( & V_64 -> V_118 , V_117 ) ;
}
static void F_63 ( struct V_68 * V_154 )
{
struct V_68 * V_155 ;
if ( V_154 -> V_122 -> V_123 == 0 )
return;
V_155 = F_64 ( V_154 -> V_155 , struct V_68 , V_18 . V_11 ) ;
F_31 ( V_154 -> V_114 , V_154 -> V_122 -> V_123 ,
V_155 -> V_122 -> V_82 [ V_154 -> V_156 ] ) ;
}
static int F_65 ( struct V_141 * V_142 , unsigned int V_157 )
{
struct V_14 * V_15 = F_56 ( V_142 ) ;
struct V_63 * V_64 = F_41 ( & V_15 -> V_15 . V_11 ) ;
struct V_68 * V_11 ;
unsigned long V_117 ;
int V_19 ;
F_22 ( & V_64 -> V_110 ) ;
if ( V_64 -> V_158 == V_64 -> V_94 - 1 ) {
if ( V_64 -> V_88 ) {
struct V_140 * V_88 = F_53 ( & V_64 -> V_88 -> V_18 ) ;
if ( V_64 -> V_89 -> type == V_77 ) {
V_88 -> V_159 = false ;
} else {
struct V_65 * V_84 =
F_26 ( & V_64 -> V_89 -> V_18 ) ;
V_88 -> V_159 = V_84 -> V_15 . V_25 -> V_139 ;
}
}
F_38 (entity, &pipe->entities, list_pipe) {
F_63 ( V_11 ) ;
V_19 = F_8 ( & V_11 -> V_18 , V_15 ,
V_125 , 1 ) ;
if ( V_19 < 0 ) {
F_27 ( & V_64 -> V_110 ) ;
return V_19 ;
}
}
}
V_64 -> V_158 ++ ;
F_27 ( & V_64 -> V_110 ) ;
F_34 ( & V_64 -> V_118 , V_117 ) ;
if ( F_39 ( V_64 ) )
F_30 ( V_64 ) ;
F_35 ( & V_64 -> V_118 , V_117 ) ;
return 0 ;
}
static void F_66 ( struct V_141 * V_142 )
{
struct V_14 * V_15 = F_56 ( V_142 ) ;
struct V_63 * V_64 = F_41 ( & V_15 -> V_15 . V_11 ) ;
struct V_127 * V_160 ;
unsigned long V_117 ;
int V_19 ;
F_22 ( & V_64 -> V_110 ) ;
if ( -- V_64 -> V_158 == 0 ) {
V_19 = F_33 ( V_64 ) ;
if ( V_19 == - V_121 )
F_67 ( V_15 -> V_114 -> V_161 , L_1 ) ;
}
F_27 ( & V_64 -> V_110 ) ;
F_29 ( V_64 ) ;
F_68 ( & V_15 -> V_15 . V_11 ) ;
F_34 ( & V_15 -> V_118 , V_117 ) ;
F_38 (buffer, &video->irqqueue, queue)
F_48 ( & V_160 -> V_131 , V_162 ) ;
F_20 ( & V_15 -> V_129 ) ;
F_35 ( & V_15 -> V_118 , V_117 ) ;
}
static int
F_69 ( struct V_163 * V_163 , void * V_164 , struct V_165 * V_166 )
{
struct V_167 * V_168 = V_163 -> V_169 ;
struct V_14 * V_15 = F_70 ( V_168 -> V_170 ) ;
V_166 -> V_171 = V_172 | V_173
| V_174
| V_175 ;
if ( V_15 -> type == V_176 )
V_166 -> V_177 = V_174
| V_173 ;
else
V_166 -> V_177 = V_175
| V_173 ;
F_71 ( V_166 -> V_178 , L_2 , sizeof( V_166 -> V_178 ) ) ;
F_71 ( V_166 -> V_179 , V_15 -> V_15 . V_180 , sizeof( V_166 -> V_179 ) ) ;
snprintf ( V_166 -> V_181 , sizeof( V_166 -> V_181 ) , L_3 ,
F_72 ( V_15 -> V_114 -> V_161 ) ) ;
return 0 ;
}
static int
F_73 ( struct V_163 * V_163 , void * V_164 , struct V_143 * V_27 )
{
struct V_167 * V_168 = V_163 -> V_169 ;
struct V_14 * V_15 = F_70 ( V_168 -> V_170 ) ;
if ( V_27 -> type != V_15 -> V_130 . type )
return - V_20 ;
F_22 ( & V_15 -> V_110 ) ;
V_27 -> V_17 . V_148 = V_15 -> V_27 ;
F_27 ( & V_15 -> V_110 ) ;
return 0 ;
}
static int
F_74 ( struct V_163 * V_163 , void * V_164 , struct V_143 * V_27 )
{
struct V_167 * V_168 = V_163 -> V_169 ;
struct V_14 * V_15 = F_70 ( V_168 -> V_170 ) ;
if ( V_27 -> type != V_15 -> V_130 . type )
return - V_20 ;
return F_9 ( V_15 , & V_27 -> V_17 . V_148 , NULL ) ;
}
static int
F_75 ( struct V_163 * V_163 , void * V_164 , struct V_143 * V_27 )
{
struct V_167 * V_168 = V_163 -> V_169 ;
struct V_14 * V_15 = F_70 ( V_168 -> V_170 ) ;
const struct V_1 * V_5 ;
int V_19 ;
if ( V_27 -> type != V_15 -> V_130 . type )
return - V_20 ;
V_19 = F_9 ( V_15 , & V_27 -> V_17 . V_148 , & V_5 ) ;
if ( V_19 < 0 )
return V_19 ;
F_22 ( & V_15 -> V_110 ) ;
if ( F_76 ( & V_15 -> V_130 ) ) {
V_19 = - V_182 ;
goto V_112;
}
V_15 -> V_27 = V_27 -> V_17 . V_148 ;
V_15 -> V_25 = V_5 ;
V_112:
F_27 ( & V_15 -> V_110 ) ;
return V_19 ;
}
static int
F_77 ( struct V_163 * V_163 , void * V_164 , enum V_183 type )
{
struct V_167 * V_168 = V_163 -> V_169 ;
struct V_14 * V_15 = F_70 ( V_168 -> V_170 ) ;
struct V_63 * V_64 ;
int V_19 ;
if ( V_15 -> V_130 . V_184 && V_15 -> V_130 . V_184 != V_163 -> V_169 )
return - V_182 ;
V_15 -> V_133 = 0 ;
V_64 = V_15 -> V_15 . V_11 . V_64
? F_41 ( & V_15 -> V_15 . V_11 ) : & V_15 -> V_64 ;
V_19 = F_78 ( & V_15 -> V_15 . V_11 , & V_64 -> V_64 ) ;
if ( V_19 < 0 )
return V_19 ;
V_19 = F_7 ( V_15 ) ;
if ( V_19 < 0 )
goto V_185;
V_19 = F_28 ( V_64 , V_15 ) ;
if ( V_19 < 0 )
goto V_185;
V_19 = F_79 ( & V_15 -> V_130 , type ) ;
if ( V_19 < 0 )
goto V_186;
return 0 ;
V_186:
F_29 ( V_64 ) ;
V_185:
F_68 ( & V_15 -> V_15 . V_11 ) ;
return V_19 ;
}
static int F_80 ( struct V_163 * V_163 )
{
struct V_14 * V_15 = F_81 ( V_163 ) ;
struct V_167 * V_168 ;
int V_19 = 0 ;
V_168 = F_82 ( sizeof( * V_168 ) , V_187 ) ;
if ( V_168 == NULL )
return - V_188 ;
F_83 ( V_168 , & V_15 -> V_15 ) ;
F_84 ( V_168 ) ;
V_163 -> V_169 = V_168 ;
V_19 = F_85 ( V_15 -> V_114 ) ;
if ( V_19 < 0 ) {
F_86 ( V_168 ) ;
F_87 ( V_168 ) ;
}
return V_19 ;
}
static int F_88 ( struct V_163 * V_163 )
{
struct V_14 * V_15 = F_81 ( V_163 ) ;
struct V_167 * V_168 = V_163 -> V_169 ;
F_22 ( & V_15 -> V_110 ) ;
if ( V_15 -> V_130 . V_184 == V_168 ) {
F_89 ( & V_15 -> V_130 ) ;
V_15 -> V_130 . V_184 = NULL ;
}
F_27 ( & V_15 -> V_110 ) ;
F_90 ( V_15 -> V_114 ) ;
F_91 ( V_163 ) ;
V_163 -> V_169 = NULL ;
return 0 ;
}
int F_92 ( struct V_14 * V_15 , struct V_68 * V_104 )
{
const char * V_189 ;
int V_19 ;
switch ( V_15 -> type ) {
case V_176 :
V_189 = L_4 ;
V_15 -> V_9 . V_117 = V_190 ;
break;
case V_191 :
V_189 = L_5 ;
V_15 -> V_9 . V_117 = V_192 ;
V_15 -> V_15 . V_193 = V_194 ;
break;
default:
return - V_20 ;
}
V_15 -> V_104 = V_104 ;
F_93 ( & V_15 -> V_110 ) ;
F_94 ( & V_15 -> V_118 ) ;
F_20 ( & V_15 -> V_129 ) ;
F_93 ( & V_15 -> V_64 . V_110 ) ;
F_94 ( & V_15 -> V_64 . V_118 ) ;
F_20 ( & V_15 -> V_64 . V_69 ) ;
F_95 ( & V_15 -> V_64 . V_120 ) ;
V_15 -> V_64 . V_91 = V_92 ;
V_19 = F_96 ( & V_15 -> V_15 . V_11 , 1 , & V_15 -> V_9 , 0 ) ;
if ( V_19 < 0 )
return V_19 ;
V_15 -> V_25 = F_1 ( V_43 ) ;
V_15 -> V_27 . V_42 = V_15 -> V_25 -> V_2 ;
V_15 -> V_27 . V_44 = V_45 ;
V_15 -> V_27 . V_46 = V_47 ;
V_15 -> V_27 . V_30 = V_195 ;
V_15 -> V_27 . V_29 = V_196 ;
V_15 -> V_27 . V_61 = 1 ;
V_15 -> V_27 . V_58 [ 0 ] . V_59 =
V_15 -> V_27 . V_30 * V_15 -> V_25 -> V_197 [ 0 ] / 8 ;
V_15 -> V_27 . V_58 [ 0 ] . V_60 =
V_15 -> V_27 . V_58 [ 0 ] . V_59 * V_15 -> V_27 . V_29 ;
V_15 -> V_15 . V_198 = & V_15 -> V_114 -> V_198 ;
V_15 -> V_15 . V_199 = & V_200 ;
snprintf ( V_15 -> V_15 . V_180 , sizeof( V_15 -> V_15 . V_180 ) , L_6 ,
V_104 -> V_18 . V_180 , V_189 ) ;
V_15 -> V_15 . V_201 = V_202 ;
V_15 -> V_15 . V_203 = V_204 ;
V_15 -> V_15 . V_205 = & V_206 ;
F_97 ( & V_15 -> V_15 , V_15 ) ;
V_15 -> V_149 = F_98 ( V_15 -> V_114 -> V_161 ) ;
if ( F_99 ( V_15 -> V_149 ) ) {
V_19 = F_100 ( V_15 -> V_149 ) ;
goto error;
}
V_15 -> V_130 . type = V_15 -> type ;
V_15 -> V_130 . V_207 = V_208 | V_209 | V_210 ;
V_15 -> V_130 . V_110 = & V_15 -> V_110 ;
V_15 -> V_130 . V_211 = V_15 ;
V_15 -> V_130 . V_212 = sizeof( struct V_127 ) ;
V_15 -> V_130 . V_137 = & V_213 ;
V_15 -> V_130 . V_214 = & V_215 ;
V_15 -> V_130 . V_216 = V_217 ;
V_19 = F_101 ( & V_15 -> V_130 ) ;
if ( V_19 < 0 ) {
F_67 ( V_15 -> V_114 -> V_161 , L_7 ) ;
goto error;
}
V_15 -> V_15 . V_130 = & V_15 -> V_130 ;
V_19 = F_102 ( & V_15 -> V_15 , V_202 , - 1 ) ;
if ( V_19 < 0 ) {
F_67 ( V_15 -> V_114 -> V_161 , L_8 ) ;
goto error;
}
return 0 ;
error:
F_103 ( V_15 -> V_149 ) ;
F_104 ( V_15 ) ;
return V_19 ;
}
void F_104 ( struct V_14 * V_15 )
{
if ( F_105 ( & V_15 -> V_15 ) )
F_106 ( & V_15 -> V_15 ) ;
F_103 ( V_15 -> V_149 ) ;
F_107 ( & V_15 -> V_15 . V_11 ) ;
}
