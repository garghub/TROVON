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
const struct V_1 * V_5 ;
unsigned int V_30 = V_32 -> V_30 ;
unsigned int V_29 = V_32 -> V_29 ;
unsigned int V_3 ;
V_5 = F_1 ( V_32 -> V_33 ) ;
if ( V_5 == NULL )
V_5 = F_1 ( V_34 ) ;
V_32 -> V_33 = V_5 -> V_2 ;
V_32 -> V_35 = V_36 ;
V_32 -> V_37 = V_38 ;
memset ( V_32 -> V_39 , 0 , sizeof( V_32 -> V_39 ) ) ;
V_30 = F_10 ( V_30 , V_5 -> V_40 ) ;
V_29 = F_10 ( V_29 , V_5 -> V_41 ) ;
V_32 -> V_30 = F_11 ( V_30 , V_42 , V_43 ) ;
V_32 -> V_29 = F_11 ( V_29 , V_44 ,
V_45 ) ;
for ( V_3 = 0 ; V_3 < F_12 ( V_5 -> V_46 , 2U ) ; ++ V_3 ) {
unsigned int V_40 = V_3 > 0 ? V_5 -> V_40 : 1 ;
unsigned int V_41 = V_3 > 0 ? V_5 -> V_41 : 1 ;
unsigned int V_47 = 128 ;
unsigned int V_48 ;
V_48 = F_13 (unsigned int, pix->plane_fmt[i].bytesperline,
pix->width / hsub * info->bpp[i] / 8 ,
round_down(65535U, align)) ;
V_32 -> V_49 [ V_3 ] . V_50 = F_14 ( V_48 , V_47 ) ;
V_32 -> V_49 [ V_3 ] . V_51 = V_32 -> V_49 [ V_3 ] . V_50
* V_32 -> V_29 / V_41 ;
}
if ( V_5 -> V_46 == 3 ) {
V_32 -> V_49 [ 2 ] . V_50 = V_32 -> V_49 [ 1 ] . V_50 ;
V_32 -> V_49 [ 2 ] . V_51 = V_32 -> V_49 [ 1 ] . V_51 ;
}
V_32 -> V_52 = V_5 -> V_46 ;
if ( V_25 )
* V_25 = V_5 ;
return 0 ;
}
static bool
F_15 ( struct V_14 * V_15 ,
const struct V_31 * V_27 ,
struct V_31 * V_53 )
{
unsigned int V_3 ;
* V_53 = * V_27 ;
F_9 ( V_15 , V_53 , NULL ) ;
if ( V_27 -> V_30 != V_53 -> V_30 ||
V_27 -> V_29 != V_53 -> V_29 ||
V_27 -> V_33 != V_53 -> V_33 ||
V_27 -> V_52 != V_53 -> V_52 )
return false ;
for ( V_3 = 0 ; V_3 < V_27 -> V_52 ; ++ V_3 ) {
if ( V_27 -> V_49 [ V_3 ] . V_50 !=
V_53 -> V_49 [ V_3 ] . V_50 )
return false ;
V_53 -> V_49 [ V_3 ] . V_51 =
F_12 ( V_53 -> V_49 [ V_3 ] . V_51 ,
V_27 -> V_49 [ V_3 ] . V_51 ) ;
}
return true ;
}
static int F_16 ( struct V_54 * V_55 ,
struct V_54 * V_56 )
{
struct V_57 * V_11 ;
unsigned int V_58 = 0 ;
struct V_7 * V_9 ;
bool V_59 = false ;
V_55 -> V_60 . V_61 = 0 ;
V_55 -> V_60 . V_62 = 0 ;
V_9 = F_4 ( & V_55 -> V_11 . V_63 [ V_64 ] ) ;
while ( 1 ) {
if ( V_9 == NULL )
return - V_65 ;
if ( F_5 ( V_9 -> V_11 ) != V_12 )
return - V_65 ;
V_11 = F_17 ( F_6 ( V_9 -> V_11 ) ) ;
if ( V_11 -> type == V_66 ) {
struct V_67 * V_68 = F_18 ( & V_11 -> V_18 ) ;
struct V_69 * V_70 = & V_68 -> V_71 [ V_9 -> V_13 ] ;
V_55 -> V_60 . V_61 = V_70 -> V_61 ;
V_55 -> V_60 . V_62 = V_70 -> V_62 ;
}
if ( V_11 -> type == V_72 )
break;
if ( V_58 & ( 1 << V_11 -> V_18 . V_11 . V_73 ) )
return - V_65 ;
V_58 |= 1 << V_11 -> V_18 . V_11 . V_73 ;
if ( V_11 -> type == V_74 ) {
if ( V_59 )
return - V_65 ;
V_59 = true ;
}
V_9 = & V_11 -> V_63 [ V_11 -> V_75 ] ;
V_9 = F_4 ( V_9 ) ;
}
if ( V_11 != & V_56 -> V_11 )
return - V_65 ;
return 0 ;
}
static int F_19 ( struct V_76 * V_77 ,
struct V_14 * V_15 )
{
struct V_78 V_79 ;
struct V_80 * V_11 = & V_15 -> V_15 . V_11 ;
struct V_81 * V_82 = V_11 -> V_83 ;
unsigned int V_3 ;
int V_19 ;
F_20 ( & V_82 -> V_84 ) ;
F_21 ( & V_79 , V_11 ) ;
while ( ( V_11 = F_22 ( & V_79 ) ) ) {
struct V_6 * V_18 ;
struct V_54 * V_85 ;
struct V_57 * V_86 ;
if ( F_5 ( V_11 ) != V_12 ) {
V_77 -> V_87 ++ ;
continue;
}
V_18 = F_6 ( V_11 ) ;
V_86 = F_17 ( V_18 ) ;
F_23 ( & V_86 -> V_88 , & V_77 -> V_58 ) ;
if ( V_86 -> type == V_89 ) {
V_85 = F_24 ( V_18 ) ;
V_77 -> V_90 [ V_77 -> V_91 ++ ] = V_85 ;
V_85 -> V_15 . V_92 = V_77 -> V_91 ;
} else if ( V_86 -> type == V_72 ) {
V_85 = F_24 ( V_18 ) ;
V_77 -> V_56 = F_24 ( V_18 ) ;
V_85 -> V_15 . V_92 = 0 ;
} else if ( V_86 -> type == V_93 ) {
V_77 -> V_94 = V_86 ;
} else if ( V_86 -> type == V_66 ) {
V_77 -> V_68 = V_86 ;
}
}
F_25 ( & V_82 -> V_84 ) ;
if ( V_77 -> V_91 == 0 || ! V_77 -> V_56 ) {
V_19 = - V_65 ;
goto error;
}
for ( V_3 = 0 ; V_3 < V_77 -> V_91 ; ++ V_3 ) {
V_19 = F_16 ( V_77 -> V_90 [ V_3 ] ,
V_77 -> V_56 ) ;
if ( V_19 < 0 )
goto error;
}
return 0 ;
error:
F_26 ( & V_77 -> V_58 ) ;
V_77 -> V_95 = 0 ;
V_77 -> V_87 = 0 ;
V_77 -> V_91 = 0 ;
V_77 -> V_56 = NULL ;
V_77 -> V_68 = NULL ;
V_77 -> V_94 = NULL ;
return V_19 ;
}
static int F_27 ( struct V_76 * V_77 ,
struct V_14 * V_15 )
{
int V_19 ;
F_20 ( & V_77 -> V_96 ) ;
if ( V_77 -> V_97 == 0 ) {
V_19 = F_19 ( V_77 , V_15 ) ;
if ( V_19 < 0 )
goto V_98;
}
V_77 -> V_97 ++ ;
V_19 = 0 ;
V_98:
F_25 ( & V_77 -> V_96 ) ;
return V_19 ;
}
static void F_28 ( struct V_76 * V_77 )
{
F_20 ( & V_77 -> V_96 ) ;
if ( -- V_77 -> V_97 == 0 ) {
F_26 ( & V_77 -> V_58 ) ;
V_77 -> V_99 = V_100 ;
V_77 -> V_95 = 0 ;
V_77 -> V_87 = 0 ;
V_77 -> V_91 = 0 ;
V_77 -> V_56 = NULL ;
V_77 -> V_68 = NULL ;
V_77 -> V_94 = NULL ;
}
F_25 ( & V_77 -> V_96 ) ;
}
static void F_29 ( struct V_76 * V_77 )
{
struct V_101 * V_102 = V_77 -> V_56 -> V_11 . V_102 ;
F_30 ( V_102 , F_31 ( V_77 -> V_56 -> V_11 . V_13 ) , V_103 ) ;
V_77 -> V_99 = V_104 ;
V_77 -> V_95 = 0 ;
}
static int F_32 ( struct V_76 * V_77 )
{
struct V_57 * V_11 ;
unsigned long V_105 ;
int V_19 ;
F_33 ( & V_77 -> V_106 , V_105 ) ;
V_77 -> V_99 = V_107 ;
F_34 ( & V_77 -> V_106 , V_105 ) ;
V_19 = F_35 ( V_77 -> V_108 , V_77 -> V_99 == V_100 ,
F_36 ( 500 ) ) ;
V_19 = V_19 == 0 ? - V_109 : 0 ;
F_37 (entity, &pipe->entities, list_pipe) {
if ( V_11 -> V_110 )
F_30 ( V_11 -> V_102 , V_11 -> V_110 -> V_111 ,
V_112 ) ;
F_8 ( & V_11 -> V_18 , V_15 , V_113 , 0 ) ;
}
return V_19 ;
}
static bool F_38 ( struct V_76 * V_77 )
{
unsigned int V_114 ;
V_114 = ( ( 1 << V_77 -> V_91 ) - 1 ) << 1 ;
if ( ! V_77 -> V_94 )
V_114 |= 1 << 0 ;
return V_77 -> V_95 == V_114 ;
}
static struct V_115 *
F_39 ( struct V_14 * V_15 )
{
struct V_76 * V_77 = F_40 ( & V_15 -> V_15 . V_11 ) ;
struct V_115 * V_116 = NULL ;
struct V_115 * V_98 ;
unsigned long V_105 ;
unsigned int V_3 ;
F_33 ( & V_15 -> V_106 , V_105 ) ;
if ( F_41 ( & V_15 -> V_117 ) ) {
F_34 ( & V_15 -> V_106 , V_105 ) ;
return NULL ;
}
V_98 = F_42 ( & V_15 -> V_117 ,
struct V_115 , V_118 ) ;
if ( V_77 -> V_94 && F_43 ( & V_15 -> V_117 ) ) {
F_34 ( & V_15 -> V_106 , V_105 ) ;
return V_98 ;
}
F_44 ( & V_98 -> V_118 ) ;
if ( ! F_41 ( & V_15 -> V_117 ) )
V_116 = F_42 ( & V_15 -> V_117 ,
struct V_115 , V_118 ) ;
F_34 ( & V_15 -> V_106 , V_105 ) ;
V_98 -> V_119 . V_120 . V_121 = V_15 -> V_121 ++ ;
F_45 ( & V_98 -> V_119 . V_120 . V_122 ) ;
for ( V_3 = 0 ; V_3 < V_98 -> V_119 . V_52 ; ++ V_3 )
F_46 ( & V_98 -> V_119 , V_3 , V_98 -> V_123 [ V_3 ] ) ;
F_47 ( & V_98 -> V_119 , V_124 ) ;
return V_116 ;
}
static void F_48 ( struct V_76 * V_77 ,
struct V_14 * V_15 )
{
struct V_115 * V_119 ;
unsigned long V_105 ;
V_119 = F_39 ( V_15 ) ;
if ( V_119 == NULL )
return;
F_33 ( & V_77 -> V_106 , V_105 ) ;
V_15 -> V_125 -> V_118 ( V_15 , V_119 ) ;
V_77 -> V_95 |= 1 << V_15 -> V_92 ;
F_34 ( & V_77 -> V_106 , V_105 ) ;
}
void F_49 ( struct V_76 * V_77 )
{
unsigned long V_105 ;
unsigned int V_3 ;
if ( V_77 == NULL )
return;
for ( V_3 = 0 ; V_3 < V_77 -> V_91 ; ++ V_3 )
F_48 ( V_77 , & V_77 -> V_90 [ V_3 ] -> V_15 ) ;
if ( ! V_77 -> V_94 )
F_48 ( V_77 , & V_77 -> V_56 -> V_15 ) ;
F_33 ( & V_77 -> V_106 , V_105 ) ;
if ( V_77 -> V_99 == V_107 ) {
V_77 -> V_99 = V_100 ;
F_50 ( & V_77 -> V_108 ) ;
goto V_98;
}
if ( F_38 ( V_77 ) )
F_29 ( V_77 ) ;
V_98:
F_34 ( & V_77 -> V_106 , V_105 ) ;
}
static int
F_51 ( struct V_126 * V_127 , const struct V_128 * V_17 ,
unsigned int * V_129 , unsigned int * V_130 ,
unsigned int V_131 [] , void * V_132 [] )
{
struct V_14 * V_15 = F_52 ( V_127 ) ;
const struct V_31 * V_27 ;
struct V_31 V_133 ;
unsigned int V_3 ;
if ( V_17 ) {
if ( ! F_15 ( V_15 , & V_17 -> V_17 . V_133 , & V_133 ) )
return - V_20 ;
V_27 = & V_133 ;
} else {
V_27 = & V_15 -> V_27 ;
}
* V_130 = V_27 -> V_52 ;
for ( V_3 = 0 ; V_3 < V_27 -> V_52 ; ++ V_3 ) {
V_131 [ V_3 ] = V_27 -> V_49 [ V_3 ] . V_51 ;
V_132 [ V_3 ] = V_15 -> V_134 ;
}
return 0 ;
}
static int F_53 ( struct V_135 * V_136 )
{
struct V_14 * V_15 = F_52 ( V_136 -> V_126 ) ;
struct V_115 * V_119 = F_54 ( V_136 ) ;
const struct V_31 * V_27 = & V_15 -> V_27 ;
unsigned int V_3 ;
if ( V_136 -> V_52 < V_27 -> V_52 )
return - V_20 ;
V_119 -> V_15 = V_15 ;
for ( V_3 = 0 ; V_3 < V_136 -> V_52 ; ++ V_3 ) {
V_119 -> V_137 [ V_3 ] = F_55 ( V_136 , V_3 ) ;
V_119 -> V_123 [ V_3 ] = F_56 ( V_136 , V_3 ) ;
if ( V_119 -> V_123 [ V_3 ] < V_27 -> V_49 [ V_3 ] . V_51 )
return - V_20 ;
}
return 0 ;
}
static void F_57 ( struct V_135 * V_136 )
{
struct V_14 * V_15 = F_52 ( V_136 -> V_126 ) ;
struct V_76 * V_77 = F_40 ( & V_15 -> V_15 . V_11 ) ;
struct V_115 * V_119 = F_54 ( V_136 ) ;
unsigned long V_105 ;
bool V_138 ;
F_33 ( & V_15 -> V_106 , V_105 ) ;
V_138 = F_41 ( & V_15 -> V_117 ) ;
F_23 ( & V_119 -> V_118 , & V_15 -> V_117 ) ;
F_34 ( & V_15 -> V_106 , V_105 ) ;
if ( ! V_138 )
return;
F_33 ( & V_77 -> V_106 , V_105 ) ;
V_15 -> V_125 -> V_118 ( V_15 , V_119 ) ;
V_77 -> V_95 |= 1 << V_15 -> V_92 ;
if ( F_58 ( & V_15 -> V_118 ) &&
F_38 ( V_77 ) )
F_29 ( V_77 ) ;
F_34 ( & V_77 -> V_106 , V_105 ) ;
}
static void F_59 ( struct V_57 * V_139 )
{
struct V_57 * V_140 ;
if ( V_139 -> V_110 -> V_111 == 0 )
return;
V_140 = F_60 ( V_139 -> V_140 , struct V_57 , V_18 . V_11 ) ;
F_30 ( V_139 -> V_102 , V_139 -> V_110 -> V_111 ,
V_140 -> V_110 -> V_90 [ V_139 -> V_141 ] ) ;
}
static int F_61 ( struct V_126 * V_127 , unsigned int V_142 )
{
struct V_14 * V_15 = F_52 ( V_127 ) ;
struct V_76 * V_77 = F_40 ( & V_15 -> V_15 . V_11 ) ;
struct V_57 * V_11 ;
unsigned long V_105 ;
int V_19 ;
F_20 ( & V_77 -> V_96 ) ;
if ( V_77 -> V_143 == V_77 -> V_87 - 1 ) {
F_37 (entity, &pipe->entities, list_pipe) {
F_59 ( V_11 ) ;
V_19 = F_8 ( & V_11 -> V_18 , V_15 ,
V_113 , 1 ) ;
if ( V_19 < 0 ) {
F_25 ( & V_77 -> V_96 ) ;
return V_19 ;
}
}
}
V_77 -> V_143 ++ ;
F_25 ( & V_77 -> V_96 ) ;
F_33 ( & V_77 -> V_106 , V_105 ) ;
if ( F_38 ( V_77 ) )
F_29 ( V_77 ) ;
F_34 ( & V_77 -> V_106 , V_105 ) ;
return 0 ;
}
static void F_62 ( struct V_126 * V_127 )
{
struct V_14 * V_15 = F_52 ( V_127 ) ;
struct V_76 * V_77 = F_40 ( & V_15 -> V_15 . V_11 ) ;
unsigned long V_105 ;
int V_19 ;
F_20 ( & V_77 -> V_96 ) ;
if ( -- V_77 -> V_143 == 0 ) {
V_19 = F_32 ( V_77 ) ;
if ( V_19 == - V_109 )
F_63 ( V_15 -> V_102 -> V_144 , L_1 ) ;
}
F_25 ( & V_77 -> V_96 ) ;
F_28 ( V_77 ) ;
F_64 ( & V_15 -> V_15 . V_11 ) ;
F_33 ( & V_15 -> V_106 , V_105 ) ;
F_26 ( & V_15 -> V_117 ) ;
F_34 ( & V_15 -> V_106 , V_105 ) ;
}
static int
F_65 ( struct V_145 * V_145 , void * V_146 , struct V_147 * V_148 )
{
struct V_149 * V_150 = V_145 -> V_151 ;
struct V_14 * V_15 = F_66 ( V_150 -> V_152 ) ;
V_148 -> V_153 = V_154 | V_155
| V_156
| V_157 ;
if ( V_15 -> type == V_158 )
V_148 -> V_159 = V_156
| V_155 ;
else
V_148 -> V_159 = V_157
| V_155 ;
F_67 ( V_148 -> V_160 , L_2 , sizeof( V_148 -> V_160 ) ) ;
F_67 ( V_148 -> V_161 , V_15 -> V_15 . V_162 , sizeof( V_148 -> V_161 ) ) ;
snprintf ( V_148 -> V_163 , sizeof( V_148 -> V_163 ) , L_3 ,
F_68 ( V_15 -> V_102 -> V_144 ) ) ;
return 0 ;
}
static int
F_69 ( struct V_145 * V_145 , void * V_146 , struct V_128 * V_27 )
{
struct V_149 * V_150 = V_145 -> V_151 ;
struct V_14 * V_15 = F_66 ( V_150 -> V_152 ) ;
if ( V_27 -> type != V_15 -> V_118 . type )
return - V_20 ;
F_20 ( & V_15 -> V_96 ) ;
V_27 -> V_17 . V_133 = V_15 -> V_27 ;
F_25 ( & V_15 -> V_96 ) ;
return 0 ;
}
static int
F_70 ( struct V_145 * V_145 , void * V_146 , struct V_128 * V_27 )
{
struct V_149 * V_150 = V_145 -> V_151 ;
struct V_14 * V_15 = F_66 ( V_150 -> V_152 ) ;
if ( V_27 -> type != V_15 -> V_118 . type )
return - V_20 ;
return F_9 ( V_15 , & V_27 -> V_17 . V_133 , NULL ) ;
}
static int
F_71 ( struct V_145 * V_145 , void * V_146 , struct V_128 * V_27 )
{
struct V_149 * V_150 = V_145 -> V_151 ;
struct V_14 * V_15 = F_66 ( V_150 -> V_152 ) ;
const struct V_1 * V_5 ;
int V_19 ;
if ( V_27 -> type != V_15 -> V_118 . type )
return - V_20 ;
V_19 = F_9 ( V_15 , & V_27 -> V_17 . V_133 , & V_5 ) ;
if ( V_19 < 0 )
return V_19 ;
F_20 ( & V_15 -> V_96 ) ;
if ( F_72 ( & V_15 -> V_118 ) ) {
V_19 = - V_164 ;
goto V_98;
}
V_15 -> V_27 = V_27 -> V_17 . V_133 ;
V_15 -> V_25 = V_5 ;
V_98:
F_25 ( & V_15 -> V_96 ) ;
return V_19 ;
}
static int
F_73 ( struct V_145 * V_145 , void * V_146 , enum V_165 type )
{
struct V_149 * V_150 = V_145 -> V_151 ;
struct V_14 * V_15 = F_66 ( V_150 -> V_152 ) ;
struct V_76 * V_77 ;
int V_19 ;
if ( V_15 -> V_118 . V_166 && V_15 -> V_118 . V_166 != V_145 -> V_151 )
return - V_164 ;
V_15 -> V_121 = 0 ;
V_77 = V_15 -> V_15 . V_11 . V_77
? F_40 ( & V_15 -> V_15 . V_11 ) : & V_15 -> V_77 ;
V_19 = F_74 ( & V_15 -> V_15 . V_11 , & V_77 -> V_77 ) ;
if ( V_19 < 0 )
return V_19 ;
V_19 = F_7 ( V_15 ) ;
if ( V_19 < 0 )
goto V_167;
V_19 = F_27 ( V_77 , V_15 ) ;
if ( V_19 < 0 )
goto V_167;
V_19 = F_75 ( & V_15 -> V_118 , type ) ;
if ( V_19 < 0 )
goto V_168;
return 0 ;
V_168:
F_28 ( V_77 ) ;
V_167:
F_64 ( & V_15 -> V_15 . V_11 ) ;
return V_19 ;
}
static int F_76 ( struct V_145 * V_145 )
{
struct V_14 * V_15 = F_77 ( V_145 ) ;
struct V_149 * V_150 ;
int V_19 = 0 ;
V_150 = F_78 ( sizeof( * V_150 ) , V_169 ) ;
if ( V_150 == NULL )
return - V_170 ;
F_79 ( V_150 , & V_15 -> V_15 ) ;
F_80 ( V_150 ) ;
V_145 -> V_151 = V_150 ;
if ( ! F_81 ( V_15 -> V_102 ) ) {
V_19 = - V_164 ;
F_82 ( V_150 ) ;
F_83 ( V_150 ) ;
}
return V_19 ;
}
static int F_84 ( struct V_145 * V_145 )
{
struct V_14 * V_15 = F_77 ( V_145 ) ;
struct V_149 * V_150 = V_145 -> V_151 ;
F_20 ( & V_15 -> V_96 ) ;
if ( V_15 -> V_118 . V_166 == V_150 ) {
F_85 ( & V_15 -> V_118 ) ;
V_15 -> V_118 . V_166 = NULL ;
}
F_25 ( & V_15 -> V_96 ) ;
F_86 ( V_15 -> V_102 ) ;
F_87 ( V_145 ) ;
V_145 -> V_151 = NULL ;
return 0 ;
}
int F_88 ( struct V_14 * V_15 , struct V_57 * V_85 )
{
const char * V_171 ;
int V_19 ;
switch ( V_15 -> type ) {
case V_158 :
V_171 = L_4 ;
V_15 -> V_9 . V_105 = V_172 ;
break;
case V_173 :
V_171 = L_5 ;
V_15 -> V_9 . V_105 = V_174 ;
V_15 -> V_15 . V_175 = V_176 ;
break;
default:
return - V_20 ;
}
V_15 -> V_85 = V_85 ;
F_89 ( & V_15 -> V_96 ) ;
F_90 ( & V_15 -> V_106 ) ;
F_26 ( & V_15 -> V_117 ) ;
F_89 ( & V_15 -> V_77 . V_96 ) ;
F_90 ( & V_15 -> V_77 . V_106 ) ;
F_26 ( & V_15 -> V_77 . V_58 ) ;
F_91 ( & V_15 -> V_77 . V_108 ) ;
V_15 -> V_77 . V_99 = V_100 ;
V_19 = F_92 ( & V_15 -> V_15 . V_11 , 1 , & V_15 -> V_9 , 0 ) ;
if ( V_19 < 0 )
return V_19 ;
V_15 -> V_25 = F_1 ( V_34 ) ;
V_15 -> V_27 . V_33 = V_15 -> V_25 -> V_2 ;
V_15 -> V_27 . V_35 = V_36 ;
V_15 -> V_27 . V_37 = V_38 ;
V_15 -> V_27 . V_30 = V_177 ;
V_15 -> V_27 . V_29 = V_178 ;
V_15 -> V_27 . V_52 = 1 ;
V_15 -> V_27 . V_49 [ 0 ] . V_50 =
V_15 -> V_27 . V_30 * V_15 -> V_25 -> V_179 [ 0 ] / 8 ;
V_15 -> V_27 . V_49 [ 0 ] . V_51 =
V_15 -> V_27 . V_49 [ 0 ] . V_50 * V_15 -> V_27 . V_29 ;
V_15 -> V_15 . V_180 = & V_15 -> V_102 -> V_180 ;
V_15 -> V_15 . V_181 = & V_182 ;
snprintf ( V_15 -> V_15 . V_162 , sizeof( V_15 -> V_15 . V_162 ) , L_6 ,
V_85 -> V_18 . V_162 , V_171 ) ;
V_15 -> V_15 . V_183 = V_184 ;
V_15 -> V_15 . V_185 = V_186 ;
V_15 -> V_15 . V_187 = & V_188 ;
F_93 ( & V_15 -> V_15 , V_15 ) ;
V_15 -> V_134 = F_94 ( V_15 -> V_102 -> V_144 ) ;
if ( F_95 ( V_15 -> V_134 ) ) {
V_19 = F_96 ( V_15 -> V_134 ) ;
goto error;
}
V_15 -> V_118 . type = V_15 -> type ;
V_15 -> V_118 . V_189 = V_190 | V_191 | V_192 ;
V_15 -> V_118 . V_96 = & V_15 -> V_96 ;
V_15 -> V_118 . V_193 = V_15 ;
V_15 -> V_118 . V_194 = sizeof( struct V_115 ) ;
V_15 -> V_118 . V_125 = & V_195 ;
V_15 -> V_118 . V_196 = & V_197 ;
V_15 -> V_118 . V_198 = V_199 ;
V_19 = F_97 ( & V_15 -> V_118 ) ;
if ( V_19 < 0 ) {
F_63 ( V_15 -> V_102 -> V_144 , L_7 ) ;
goto error;
}
V_15 -> V_15 . V_118 = & V_15 -> V_118 ;
V_19 = F_98 ( & V_15 -> V_15 , V_184 , - 1 ) ;
if ( V_19 < 0 ) {
F_63 ( V_15 -> V_102 -> V_144 , L_8 ) ;
goto error;
}
return 0 ;
error:
F_99 ( V_15 -> V_134 ) ;
F_100 ( V_15 ) ;
return V_19 ;
}
void F_100 ( struct V_14 * V_15 )
{
if ( F_101 ( & V_15 -> V_15 ) )
F_102 ( & V_15 -> V_15 ) ;
F_99 ( V_15 -> V_134 ) ;
F_103 ( & V_15 -> V_15 . V_11 ) ;
}
