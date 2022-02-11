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
F_16 ( V_62 -> V_58 [ V_3 ] . V_60 ,
V_27 -> V_58 [ V_3 ] . V_60 ) ;
}
return true ;
}
static int F_17 ( struct V_63 * V_64 ,
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
V_11 = F_18 ( F_6 ( V_9 -> V_11 ) ) ;
if ( V_11 -> type == V_77 ) {
struct V_78 * V_79 = F_19 ( & V_11 -> V_18 ) ;
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
static void F_20 ( struct V_63 * V_64 )
{
if ( V_64 -> V_79 ) {
struct V_78 * V_79 = F_19 ( & V_64 -> V_79 -> V_18 ) ;
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_79 -> V_82 ) ; ++ V_3 )
V_79 -> V_82 [ V_3 ] . V_84 = NULL ;
}
F_21 ( & V_64 -> V_69 ) ;
V_64 -> V_91 = V_92 ;
V_64 -> V_93 = 0 ;
V_64 -> V_94 = 0 ;
V_64 -> V_95 = 0 ;
V_64 -> V_67 = NULL ;
V_64 -> V_79 = NULL ;
V_64 -> V_96 = NULL ;
V_64 -> V_88 = NULL ;
}
static int F_22 ( struct V_63 * V_64 ,
struct V_14 * V_15 )
{
struct V_97 V_98 ;
struct V_99 * V_11 = & V_15 -> V_15 . V_11 ;
struct V_100 * V_101 = V_11 -> V_102 ;
unsigned int V_3 ;
int V_19 ;
F_23 ( & V_101 -> V_103 ) ;
F_24 ( & V_98 , V_11 ) ;
while ( ( V_11 = F_25 ( & V_98 ) ) ) {
struct V_6 * V_18 ;
struct V_65 * V_104 ;
struct V_68 * V_105 ;
if ( F_5 ( V_11 ) != V_12 ) {
V_64 -> V_94 ++ ;
continue;
}
V_18 = F_6 ( V_11 ) ;
V_105 = F_18 ( V_18 ) ;
F_26 ( & V_105 -> V_106 , & V_64 -> V_69 ) ;
if ( V_105 -> type == V_107 ) {
V_104 = F_27 ( V_18 ) ;
V_64 -> V_82 [ V_64 -> V_95 ++ ] = V_104 ;
V_104 -> V_15 . V_108 = V_64 -> V_95 ;
} else if ( V_105 -> type == V_85 ) {
V_104 = F_27 ( V_18 ) ;
V_64 -> V_67 = F_27 ( V_18 ) ;
V_104 -> V_15 . V_108 = 0 ;
} else if ( V_105 -> type == V_109 ) {
V_64 -> V_96 = V_105 ;
} else if ( V_105 -> type == V_77 ) {
V_64 -> V_79 = V_105 ;
}
}
F_28 ( & V_101 -> V_103 ) ;
if ( V_64 -> V_95 == 0 || ! V_64 -> V_67 ) {
V_19 = - V_76 ;
goto error;
}
for ( V_3 = 0 ; V_3 < V_64 -> V_95 ; ++ V_3 ) {
V_19 = F_17 ( V_64 , V_64 -> V_82 [ V_3 ] ,
V_64 -> V_67 ) ;
if ( V_19 < 0 )
goto error;
}
return 0 ;
error:
F_20 ( V_64 ) ;
return V_19 ;
}
static int F_29 ( struct V_63 * V_64 ,
struct V_14 * V_15 )
{
int V_19 ;
F_23 ( & V_64 -> V_110 ) ;
if ( V_64 -> V_111 == 0 ) {
V_19 = F_22 ( V_64 , V_15 ) ;
if ( V_19 < 0 )
goto V_112;
}
V_64 -> V_111 ++ ;
V_19 = 0 ;
V_112:
F_28 ( & V_64 -> V_110 ) ;
return V_19 ;
}
static void F_30 ( struct V_63 * V_64 )
{
F_23 ( & V_64 -> V_110 ) ;
if ( -- V_64 -> V_111 == 0 )
F_20 ( V_64 ) ;
F_28 ( & V_64 -> V_110 ) ;
}
static void F_31 ( struct V_63 * V_64 )
{
struct V_113 * V_114 = V_64 -> V_67 -> V_11 . V_114 ;
F_32 ( V_114 , F_33 ( V_64 -> V_67 -> V_11 . V_13 ) , V_115 ) ;
V_64 -> V_91 = V_116 ;
V_64 -> V_93 = 0 ;
}
static bool F_34 ( struct V_63 * V_64 )
{
unsigned long V_117 ;
bool V_118 ;
F_35 ( & V_64 -> V_119 , V_117 ) ;
V_118 = V_64 -> V_91 == V_92 ,
F_36 ( & V_64 -> V_119 , V_117 ) ;
return V_118 ;
}
static int F_37 ( struct V_63 * V_64 )
{
struct V_68 * V_11 ;
unsigned long V_117 ;
int V_19 ;
F_35 ( & V_64 -> V_119 , V_117 ) ;
if ( V_64 -> V_91 == V_116 )
V_64 -> V_91 = V_120 ;
F_36 ( & V_64 -> V_119 , V_117 ) ;
V_19 = F_38 ( V_64 -> V_121 , F_34 ( V_64 ) ,
F_39 ( 500 ) ) ;
V_19 = V_19 == 0 ? - V_122 : 0 ;
F_40 (entity, &pipe->entities, list_pipe) {
if ( V_11 -> V_123 && V_11 -> V_123 -> V_124 )
F_32 ( V_11 -> V_114 , V_11 -> V_123 -> V_124 ,
V_125 ) ;
F_8 ( & V_11 -> V_18 , V_15 , V_126 , 0 ) ;
}
return V_19 ;
}
static bool F_41 ( struct V_63 * V_64 )
{
unsigned int V_127 ;
V_127 = ( ( 1 << V_64 -> V_95 ) - 1 ) << 1 ;
if ( ! V_64 -> V_96 )
V_127 |= 1 << 0 ;
return V_64 -> V_93 == V_127 ;
}
static struct V_128 *
F_42 ( struct V_14 * V_15 )
{
struct V_63 * V_64 = F_43 ( & V_15 -> V_15 . V_11 ) ;
struct V_128 * V_129 = NULL ;
struct V_128 * V_112 ;
unsigned long V_117 ;
unsigned int V_3 ;
F_35 ( & V_15 -> V_119 , V_117 ) ;
if ( F_44 ( & V_15 -> V_130 ) ) {
F_36 ( & V_15 -> V_119 , V_117 ) ;
return NULL ;
}
V_112 = F_45 ( & V_15 -> V_130 ,
struct V_128 , V_131 ) ;
if ( V_64 -> V_96 && F_46 ( & V_15 -> V_130 ) ) {
F_36 ( & V_15 -> V_119 , V_117 ) ;
return V_112 ;
}
F_47 ( & V_112 -> V_131 ) ;
if ( ! F_44 ( & V_15 -> V_130 ) )
V_129 = F_45 ( & V_15 -> V_130 ,
struct V_128 , V_131 ) ;
F_36 ( & V_15 -> V_119 , V_117 ) ;
V_112 -> V_132 . V_133 = V_15 -> V_133 ++ ;
F_48 ( & V_112 -> V_132 . V_134 ) ;
for ( V_3 = 0 ; V_3 < V_112 -> V_132 . V_135 . V_61 ; ++ V_3 )
F_49 ( & V_112 -> V_132 . V_135 , V_3 , V_112 -> V_136 [ V_3 ] ) ;
F_50 ( & V_112 -> V_132 . V_135 , V_137 ) ;
return V_129 ;
}
static void F_51 ( struct V_63 * V_64 ,
struct V_14 * V_15 )
{
struct V_128 * V_132 ;
unsigned long V_117 ;
V_132 = F_42 ( V_15 ) ;
if ( V_132 == NULL )
return;
F_35 ( & V_64 -> V_119 , V_117 ) ;
V_15 -> V_138 -> V_131 ( V_15 , V_132 ) ;
V_64 -> V_93 |= 1 << V_15 -> V_108 ;
F_36 ( & V_64 -> V_119 , V_117 ) ;
}
void F_52 ( struct V_63 * V_64 )
{
enum V_139 V_91 ;
unsigned long V_117 ;
unsigned int V_3 ;
if ( V_64 == NULL )
return;
for ( V_3 = 0 ; V_3 < V_64 -> V_95 ; ++ V_3 )
F_51 ( V_64 , & V_64 -> V_82 [ V_3 ] -> V_15 ) ;
if ( ! V_64 -> V_96 )
F_51 ( V_64 , & V_64 -> V_67 -> V_15 ) ;
F_35 ( & V_64 -> V_119 , V_117 ) ;
V_91 = V_64 -> V_91 ;
V_64 -> V_91 = V_92 ;
if ( V_91 == V_120 ) {
F_53 ( & V_64 -> V_121 ) ;
goto V_112;
}
if ( F_41 ( V_64 ) )
F_31 ( V_64 ) ;
V_112:
F_36 ( & V_64 -> V_119 , V_117 ) ;
}
void F_54 ( struct V_63 * V_64 ,
struct V_68 * V_66 ,
unsigned int V_140 )
{
struct V_68 * V_11 ;
struct V_7 * V_9 ;
V_9 = F_4 ( & V_66 -> V_74 [ V_75 ] ) ;
while ( V_9 ) {
if ( F_5 ( V_9 -> V_11 ) != V_12 )
break;
V_11 = F_18 ( F_6 ( V_9 -> V_11 ) ) ;
if ( V_11 -> type == V_77 )
V_140 = 255 ;
if ( V_11 -> type == V_87 ) {
struct V_141 * V_88 = F_55 ( & V_11 -> V_18 ) ;
F_56 ( V_88 , V_140 ) ;
break;
}
V_9 = & V_11 -> V_74 [ V_11 -> V_90 ] ;
V_9 = F_4 ( V_9 ) ;
}
}
void F_57 ( struct V_113 * V_114 )
{
unsigned long V_117 ;
unsigned int V_3 ;
int V_19 ;
for ( V_3 = 0 ; V_3 < V_114 -> V_142 . V_143 ; ++ V_3 ) {
struct V_65 * V_144 = V_114 -> V_144 [ V_3 ] ;
struct V_63 * V_64 ;
if ( V_144 == NULL )
continue;
V_64 = F_43 ( & V_144 -> V_11 . V_18 . V_11 ) ;
if ( V_64 == NULL )
continue;
F_35 ( & V_64 -> V_119 , V_117 ) ;
if ( V_64 -> V_91 == V_116 )
V_64 -> V_91 = V_120 ;
F_36 ( & V_64 -> V_119 , V_117 ) ;
}
for ( V_3 = 0 ; V_3 < V_114 -> V_142 . V_143 ; ++ V_3 ) {
struct V_65 * V_144 = V_114 -> V_144 [ V_3 ] ;
struct V_63 * V_64 ;
if ( V_144 == NULL )
continue;
V_64 = F_43 ( & V_144 -> V_11 . V_18 . V_11 ) ;
if ( V_64 == NULL )
continue;
V_19 = F_38 ( V_64 -> V_121 , F_34 ( V_64 ) ,
F_39 ( 500 ) ) ;
if ( V_19 == 0 )
F_58 ( V_114 -> V_145 , L_1 ,
V_144 -> V_11 . V_13 ) ;
}
}
void F_59 ( struct V_113 * V_114 )
{
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < V_114 -> V_142 . V_143 ; ++ V_3 ) {
struct V_65 * V_144 = V_114 -> V_144 [ V_3 ] ;
struct V_63 * V_64 ;
if ( V_144 == NULL )
continue;
V_64 = F_43 ( & V_144 -> V_11 . V_18 . V_11 ) ;
if ( V_64 == NULL )
continue;
if ( F_41 ( V_64 ) )
F_31 ( V_64 ) ;
}
}
static int
F_60 ( struct V_146 * V_147 , const void * V_148 ,
unsigned int * V_149 , unsigned int * V_150 ,
unsigned int V_151 [] , void * V_152 [] )
{
const struct V_153 * V_17 = V_148 ;
struct V_14 * V_15 = F_61 ( V_147 ) ;
const struct V_31 * V_27 ;
struct V_31 V_154 ;
unsigned int V_3 ;
if ( V_17 ) {
if ( ! F_15 ( V_15 , & V_17 -> V_17 . V_154 , & V_154 ) )
return - V_20 ;
V_27 = & V_154 ;
} else {
V_27 = & V_15 -> V_27 ;
}
* V_150 = V_27 -> V_61 ;
for ( V_3 = 0 ; V_3 < V_27 -> V_61 ; ++ V_3 ) {
V_151 [ V_3 ] = V_27 -> V_58 [ V_3 ] . V_60 ;
V_152 [ V_3 ] = V_15 -> V_155 ;
}
return 0 ;
}
static int F_62 ( struct V_156 * V_157 )
{
struct V_158 * V_159 = F_63 ( V_157 ) ;
struct V_14 * V_15 = F_61 ( V_157 -> V_146 ) ;
struct V_128 * V_132 = F_64 ( V_159 ) ;
const struct V_31 * V_27 = & V_15 -> V_27 ;
unsigned int V_3 ;
if ( V_157 -> V_61 < V_27 -> V_61 )
return - V_20 ;
for ( V_3 = 0 ; V_3 < V_157 -> V_61 ; ++ V_3 ) {
V_132 -> V_160 [ V_3 ] = F_65 ( V_157 , V_3 ) ;
V_132 -> V_136 [ V_3 ] = F_66 ( V_157 , V_3 ) ;
if ( V_132 -> V_136 [ V_3 ] < V_27 -> V_58 [ V_3 ] . V_60 )
return - V_20 ;
}
return 0 ;
}
static void F_67 ( struct V_156 * V_157 )
{
struct V_158 * V_159 = F_63 ( V_157 ) ;
struct V_14 * V_15 = F_61 ( V_157 -> V_146 ) ;
struct V_63 * V_64 = F_43 ( & V_15 -> V_15 . V_11 ) ;
struct V_128 * V_132 = F_64 ( V_159 ) ;
unsigned long V_117 ;
bool V_161 ;
F_35 ( & V_15 -> V_119 , V_117 ) ;
V_161 = F_44 ( & V_15 -> V_130 ) ;
F_26 ( & V_132 -> V_131 , & V_15 -> V_130 ) ;
F_36 ( & V_15 -> V_119 , V_117 ) ;
if ( ! V_161 )
return;
F_35 ( & V_64 -> V_119 , V_117 ) ;
V_15 -> V_138 -> V_131 ( V_15 , V_132 ) ;
V_64 -> V_93 |= 1 << V_15 -> V_108 ;
if ( F_68 ( & V_15 -> V_131 ) &&
F_41 ( V_64 ) )
F_31 ( V_64 ) ;
F_36 ( & V_64 -> V_119 , V_117 ) ;
}
static void F_69 ( struct V_68 * V_162 )
{
struct V_68 * V_163 ;
if ( V_162 -> V_123 -> V_124 == 0 )
return;
V_163 = F_70 ( V_162 -> V_163 , struct V_68 , V_18 . V_11 ) ;
F_32 ( V_162 -> V_114 , V_162 -> V_123 -> V_124 ,
V_163 -> V_123 -> V_82 [ V_162 -> V_164 ] ) ;
}
static int F_71 ( struct V_146 * V_147 , unsigned int V_165 )
{
struct V_14 * V_15 = F_61 ( V_147 ) ;
struct V_63 * V_64 = F_43 ( & V_15 -> V_15 . V_11 ) ;
struct V_68 * V_11 ;
unsigned long V_117 ;
int V_19 ;
F_23 ( & V_64 -> V_110 ) ;
if ( V_64 -> V_166 == V_64 -> V_94 - 1 ) {
if ( V_64 -> V_88 ) {
struct V_141 * V_88 = F_55 ( & V_64 -> V_88 -> V_18 ) ;
if ( V_64 -> V_89 -> type == V_77 ) {
V_88 -> V_167 = false ;
} else {
struct V_65 * V_84 =
F_27 ( & V_64 -> V_89 -> V_18 ) ;
V_88 -> V_167 = V_84 -> V_15 . V_25 -> V_140 ;
}
}
F_40 (entity, &pipe->entities, list_pipe) {
F_69 ( V_11 ) ;
V_19 = F_8 ( & V_11 -> V_18 , V_15 ,
V_126 , 1 ) ;
if ( V_19 < 0 ) {
F_28 ( & V_64 -> V_110 ) ;
return V_19 ;
}
}
}
V_64 -> V_166 ++ ;
F_28 ( & V_64 -> V_110 ) ;
F_35 ( & V_64 -> V_119 , V_117 ) ;
if ( F_41 ( V_64 ) )
F_31 ( V_64 ) ;
F_36 ( & V_64 -> V_119 , V_117 ) ;
return 0 ;
}
static void F_72 ( struct V_146 * V_147 )
{
struct V_14 * V_15 = F_61 ( V_147 ) ;
struct V_63 * V_64 = F_43 ( & V_15 -> V_15 . V_11 ) ;
struct V_128 * V_168 ;
unsigned long V_117 ;
int V_19 ;
F_23 ( & V_64 -> V_110 ) ;
if ( -- V_64 -> V_166 == 0 ) {
V_19 = F_37 ( V_64 ) ;
if ( V_19 == - V_122 )
F_73 ( V_15 -> V_114 -> V_145 , L_2 ) ;
}
F_28 ( & V_64 -> V_110 ) ;
F_30 ( V_64 ) ;
F_74 ( & V_15 -> V_15 . V_11 ) ;
F_35 ( & V_15 -> V_119 , V_117 ) ;
F_40 (buffer, &video->irqqueue, queue)
F_50 ( & V_168 -> V_132 . V_135 , V_169 ) ;
F_21 ( & V_15 -> V_130 ) ;
F_36 ( & V_15 -> V_119 , V_117 ) ;
}
static int
F_75 ( struct V_170 * V_170 , void * V_171 , struct V_172 * V_173 )
{
struct V_174 * V_175 = V_170 -> V_176 ;
struct V_14 * V_15 = F_76 ( V_175 -> V_177 ) ;
V_173 -> V_178 = V_179 | V_180
| V_181
| V_182 ;
if ( V_15 -> type == V_183 )
V_173 -> V_184 = V_181
| V_180 ;
else
V_173 -> V_184 = V_182
| V_180 ;
F_77 ( V_173 -> V_185 , L_3 , sizeof( V_173 -> V_185 ) ) ;
F_77 ( V_173 -> V_186 , V_15 -> V_15 . V_187 , sizeof( V_173 -> V_186 ) ) ;
snprintf ( V_173 -> V_188 , sizeof( V_173 -> V_188 ) , L_4 ,
F_78 ( V_15 -> V_114 -> V_145 ) ) ;
return 0 ;
}
static int
F_79 ( struct V_170 * V_170 , void * V_171 , struct V_153 * V_27 )
{
struct V_174 * V_175 = V_170 -> V_176 ;
struct V_14 * V_15 = F_76 ( V_175 -> V_177 ) ;
if ( V_27 -> type != V_15 -> V_131 . type )
return - V_20 ;
F_23 ( & V_15 -> V_110 ) ;
V_27 -> V_17 . V_154 = V_15 -> V_27 ;
F_28 ( & V_15 -> V_110 ) ;
return 0 ;
}
static int
F_80 ( struct V_170 * V_170 , void * V_171 , struct V_153 * V_27 )
{
struct V_174 * V_175 = V_170 -> V_176 ;
struct V_14 * V_15 = F_76 ( V_175 -> V_177 ) ;
if ( V_27 -> type != V_15 -> V_131 . type )
return - V_20 ;
return F_9 ( V_15 , & V_27 -> V_17 . V_154 , NULL ) ;
}
static int
F_81 ( struct V_170 * V_170 , void * V_171 , struct V_153 * V_27 )
{
struct V_174 * V_175 = V_170 -> V_176 ;
struct V_14 * V_15 = F_76 ( V_175 -> V_177 ) ;
const struct V_1 * V_5 ;
int V_19 ;
if ( V_27 -> type != V_15 -> V_131 . type )
return - V_20 ;
V_19 = F_9 ( V_15 , & V_27 -> V_17 . V_154 , & V_5 ) ;
if ( V_19 < 0 )
return V_19 ;
F_23 ( & V_15 -> V_110 ) ;
if ( F_82 ( & V_15 -> V_131 ) ) {
V_19 = - V_189 ;
goto V_112;
}
V_15 -> V_27 = V_27 -> V_17 . V_154 ;
V_15 -> V_25 = V_5 ;
V_112:
F_28 ( & V_15 -> V_110 ) ;
return V_19 ;
}
static int
F_83 ( struct V_170 * V_170 , void * V_171 , enum V_190 type )
{
struct V_174 * V_175 = V_170 -> V_176 ;
struct V_14 * V_15 = F_76 ( V_175 -> V_177 ) ;
struct V_63 * V_64 ;
int V_19 ;
if ( V_15 -> V_131 . V_191 && V_15 -> V_131 . V_191 != V_170 -> V_176 )
return - V_189 ;
V_15 -> V_133 = 0 ;
V_64 = V_15 -> V_15 . V_11 . V_64
? F_43 ( & V_15 -> V_15 . V_11 ) : & V_15 -> V_64 ;
V_19 = F_84 ( & V_15 -> V_15 . V_11 , & V_64 -> V_64 ) ;
if ( V_19 < 0 )
return V_19 ;
V_19 = F_7 ( V_15 ) ;
if ( V_19 < 0 )
goto V_192;
V_19 = F_29 ( V_64 , V_15 ) ;
if ( V_19 < 0 )
goto V_192;
V_19 = F_85 ( & V_15 -> V_131 , type ) ;
if ( V_19 < 0 )
goto V_193;
return 0 ;
V_193:
F_30 ( V_64 ) ;
V_192:
F_74 ( & V_15 -> V_15 . V_11 ) ;
return V_19 ;
}
static int F_86 ( struct V_170 * V_170 )
{
struct V_14 * V_15 = F_87 ( V_170 ) ;
struct V_174 * V_175 ;
int V_19 = 0 ;
V_175 = F_88 ( sizeof( * V_175 ) , V_194 ) ;
if ( V_175 == NULL )
return - V_195 ;
F_89 ( V_175 , & V_15 -> V_15 ) ;
F_90 ( V_175 ) ;
V_170 -> V_176 = V_175 ;
V_19 = F_91 ( V_15 -> V_114 ) ;
if ( V_19 < 0 ) {
F_92 ( V_175 ) ;
F_93 ( V_175 ) ;
}
return V_19 ;
}
static int F_94 ( struct V_170 * V_170 )
{
struct V_14 * V_15 = F_87 ( V_170 ) ;
struct V_174 * V_175 = V_170 -> V_176 ;
F_23 ( & V_15 -> V_110 ) ;
if ( V_15 -> V_131 . V_191 == V_175 ) {
F_95 ( & V_15 -> V_131 ) ;
V_15 -> V_131 . V_191 = NULL ;
}
F_28 ( & V_15 -> V_110 ) ;
F_96 ( V_15 -> V_114 ) ;
F_97 ( V_170 ) ;
V_170 -> V_176 = NULL ;
return 0 ;
}
int F_98 ( struct V_14 * V_15 , struct V_68 * V_104 )
{
const char * V_196 ;
int V_19 ;
switch ( V_15 -> type ) {
case V_183 :
V_196 = L_5 ;
V_15 -> V_9 . V_117 = V_197 ;
break;
case V_198 :
V_196 = L_6 ;
V_15 -> V_9 . V_117 = V_199 ;
V_15 -> V_15 . V_200 = V_201 ;
break;
default:
return - V_20 ;
}
V_15 -> V_104 = V_104 ;
F_99 ( & V_15 -> V_110 ) ;
F_100 ( & V_15 -> V_119 ) ;
F_21 ( & V_15 -> V_130 ) ;
F_99 ( & V_15 -> V_64 . V_110 ) ;
F_100 ( & V_15 -> V_64 . V_119 ) ;
F_21 ( & V_15 -> V_64 . V_69 ) ;
F_101 ( & V_15 -> V_64 . V_121 ) ;
V_15 -> V_64 . V_91 = V_92 ;
V_19 = F_102 ( & V_15 -> V_15 . V_11 , 1 , & V_15 -> V_9 , 0 ) ;
if ( V_19 < 0 )
return V_19 ;
V_15 -> V_25 = F_1 ( V_43 ) ;
V_15 -> V_27 . V_42 = V_15 -> V_25 -> V_2 ;
V_15 -> V_27 . V_44 = V_45 ;
V_15 -> V_27 . V_46 = V_47 ;
V_15 -> V_27 . V_30 = V_202 ;
V_15 -> V_27 . V_29 = V_203 ;
V_15 -> V_27 . V_61 = 1 ;
V_15 -> V_27 . V_58 [ 0 ] . V_59 =
V_15 -> V_27 . V_30 * V_15 -> V_25 -> V_204 [ 0 ] / 8 ;
V_15 -> V_27 . V_58 [ 0 ] . V_60 =
V_15 -> V_27 . V_58 [ 0 ] . V_59 * V_15 -> V_27 . V_29 ;
V_15 -> V_15 . V_205 = & V_15 -> V_114 -> V_205 ;
V_15 -> V_15 . V_206 = & V_207 ;
snprintf ( V_15 -> V_15 . V_187 , sizeof( V_15 -> V_15 . V_187 ) , L_7 ,
V_104 -> V_18 . V_187 , V_196 ) ;
V_15 -> V_15 . V_208 = V_209 ;
V_15 -> V_15 . V_210 = V_211 ;
V_15 -> V_15 . V_212 = & V_213 ;
F_103 ( & V_15 -> V_15 , V_15 ) ;
V_15 -> V_155 = F_104 ( V_15 -> V_114 -> V_145 ) ;
if ( F_105 ( V_15 -> V_155 ) ) {
V_19 = F_106 ( V_15 -> V_155 ) ;
goto error;
}
V_15 -> V_131 . type = V_15 -> type ;
V_15 -> V_131 . V_214 = V_215 | V_216 | V_217 ;
V_15 -> V_131 . V_110 = & V_15 -> V_110 ;
V_15 -> V_131 . V_218 = V_15 ;
V_15 -> V_131 . V_219 = sizeof( struct V_128 ) ;
V_15 -> V_131 . V_138 = & V_220 ;
V_15 -> V_131 . V_221 = & V_222 ;
V_15 -> V_131 . V_223 = V_224 ;
V_19 = F_107 ( & V_15 -> V_131 ) ;
if ( V_19 < 0 ) {
F_73 ( V_15 -> V_114 -> V_145 , L_8 ) ;
goto error;
}
V_15 -> V_15 . V_131 = & V_15 -> V_131 ;
V_19 = F_108 ( & V_15 -> V_15 , V_209 , - 1 ) ;
if ( V_19 < 0 ) {
F_73 ( V_15 -> V_114 -> V_145 , L_9 ) ;
goto error;
}
return 0 ;
error:
F_109 ( V_15 -> V_155 ) ;
F_110 ( V_15 ) ;
return V_19 ;
}
void F_110 ( struct V_14 * V_15 )
{
if ( F_111 ( & V_15 -> V_15 ) )
F_112 ( & V_15 -> V_15 ) ;
F_109 ( V_15 -> V_155 ) ;
F_113 ( & V_15 -> V_15 . V_11 ) ;
}
