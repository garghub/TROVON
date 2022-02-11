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
if ( ! V_10 || ! F_5 ( V_10 -> V_11 ) )
return NULL ;
if ( V_9 )
* V_9 = V_10 -> V_12 ;
return F_6 ( V_10 -> V_11 ) ;
}
static int F_7 ( struct V_13 * V_14 )
{
struct V_15 V_16 ;
struct V_6 * V_17 ;
int V_18 ;
V_17 = F_3 ( & V_14 -> V_9 , & V_16 . V_9 ) ;
if ( V_17 == NULL )
return - V_19 ;
V_16 . V_20 = V_21 ;
V_18 = F_8 ( V_17 , V_9 , V_22 , NULL , & V_16 ) ;
if ( V_18 < 0 )
return V_18 == - V_23 ? - V_19 : V_18 ;
if ( V_14 -> V_24 -> V_25 != V_16 . V_26 . V_27 ||
V_14 -> V_26 . V_28 != V_16 . V_26 . V_28 ||
V_14 -> V_26 . V_29 != V_16 . V_26 . V_29 )
return - V_19 ;
return 0 ;
}
static int F_9 ( struct V_13 * V_14 ,
struct V_30 * V_31 ,
const struct V_1 * * V_24 )
{
static const T_1 V_32 [] [ 2 ] = {
{ V_33 , V_34 } ,
{ V_35 , V_36 } ,
{ V_37 , V_38 } ,
{ V_39 , V_40 } ,
} ;
const struct V_1 * V_5 ;
unsigned int V_29 = V_31 -> V_29 ;
unsigned int V_28 = V_31 -> V_28 ;
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_32 ) ; ++ V_3 ) {
if ( V_32 [ V_3 ] [ 0 ] == V_31 -> V_41 ) {
V_31 -> V_41 = V_32 [ V_3 ] [ 1 ] ;
break;
}
}
V_5 = F_1 ( V_31 -> V_41 ) ;
if ( V_5 == NULL )
V_5 = F_1 ( V_42 ) ;
V_31 -> V_41 = V_5 -> V_2 ;
V_31 -> V_43 = V_44 ;
V_31 -> V_45 = V_46 ;
memset ( V_31 -> V_47 , 0 , sizeof( V_31 -> V_47 ) ) ;
V_29 = F_10 ( V_29 , V_5 -> V_48 ) ;
V_28 = F_10 ( V_28 , V_5 -> V_49 ) ;
V_31 -> V_29 = F_11 ( V_29 , V_50 , V_51 ) ;
V_31 -> V_28 = F_11 ( V_28 , V_52 ,
V_53 ) ;
for ( V_3 = 0 ; V_3 < F_12 ( V_5 -> V_54 , 2U ) ; ++ V_3 ) {
unsigned int V_48 = V_3 > 0 ? V_5 -> V_48 : 1 ;
unsigned int V_49 = V_3 > 0 ? V_5 -> V_49 : 1 ;
unsigned int V_55 = 128 ;
unsigned int V_56 ;
V_56 = F_13 (unsigned int, pix->plane_fmt[i].bytesperline,
pix->width / hsub * info->bpp[i] / 8 ,
round_down(65535U, align)) ;
V_31 -> V_57 [ V_3 ] . V_58 = F_14 ( V_56 , V_55 ) ;
V_31 -> V_57 [ V_3 ] . V_59 = V_31 -> V_57 [ V_3 ] . V_58
* V_31 -> V_28 / V_49 ;
}
if ( V_5 -> V_54 == 3 ) {
V_31 -> V_57 [ 2 ] . V_58 = V_31 -> V_57 [ 1 ] . V_58 ;
V_31 -> V_57 [ 2 ] . V_59 = V_31 -> V_57 [ 1 ] . V_59 ;
}
V_31 -> V_60 = V_5 -> V_54 ;
if ( V_24 )
* V_24 = V_5 ;
return 0 ;
}
static int F_15 ( struct V_61 * V_62 ,
struct V_63 * V_64 ,
struct V_63 * V_65 )
{
struct V_66 * V_11 ;
struct V_67 V_68 ;
struct V_7 * V_9 ;
int V_69 ;
bool V_70 = false ;
V_64 -> V_71 . V_72 = 0 ;
V_64 -> V_71 . V_73 = 0 ;
V_69 = F_16 (
& V_68 , V_64 -> V_11 . V_74 [ V_75 ] . V_76 . V_77 ) ;
if ( V_69 )
return V_69 ;
V_9 = F_4 ( & V_64 -> V_11 . V_74 [ V_75 ] ) ;
while ( 1 ) {
if ( V_9 == NULL ) {
V_69 = - V_78 ;
goto V_79;
}
if ( ! F_5 ( V_9 -> V_11 ) ) {
V_69 = - V_78 ;
goto V_79;
}
V_11 = F_17 (
F_6 ( V_9 -> V_11 ) ) ;
if ( V_11 -> type == V_80 ) {
struct V_81 * V_82 = F_18 ( & V_11 -> V_17 ) ;
struct V_83 * V_84 =
& V_82 -> V_85 [ V_9 -> V_12 ] . V_86 ;
V_82 -> V_85 [ V_9 -> V_12 ] . V_87 = V_64 ;
V_64 -> V_71 . V_72 = V_84 -> V_72 ;
V_64 -> V_71 . V_73 = V_84 -> V_73 ;
V_70 = true ;
}
if ( V_11 -> type == V_88 )
break;
if ( F_19 ( & V_68 ,
& V_11 -> V_17 . V_11 ) ) {
V_69 = - V_78 ;
goto V_79;
}
if ( V_11 -> type == V_89 ) {
if ( V_62 -> V_90 ) {
V_69 = - V_78 ;
goto V_79;
}
V_62 -> V_90 = V_11 ;
V_62 -> V_91 = V_70 ? V_62 -> V_82
: & V_64 -> V_11 ;
}
V_9 = & V_11 -> V_74 [ V_11 -> V_92 ] ;
V_9 = F_4 ( V_9 ) ;
}
if ( V_11 != & V_65 -> V_11 )
V_69 = - V_78 ;
V_79:
F_20 ( & V_68 ) ;
return V_69 ;
}
static void F_21 ( struct V_61 * V_62 )
{
if ( V_62 -> V_82 ) {
struct V_81 * V_82 = F_18 ( & V_62 -> V_82 -> V_17 ) ;
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_82 -> V_85 ) ; ++ V_3 )
V_82 -> V_85 [ V_3 ] . V_87 = NULL ;
}
F_22 ( & V_62 -> V_93 ) ;
V_62 -> V_94 = V_95 ;
V_62 -> V_96 = 0 ;
V_62 -> V_97 = 0 ;
V_62 -> V_98 = 0 ;
V_62 -> V_65 = NULL ;
V_62 -> V_82 = NULL ;
V_62 -> V_99 = NULL ;
V_62 -> V_90 = NULL ;
}
static int F_23 ( struct V_61 * V_62 ,
struct V_13 * V_14 )
{
struct V_100 V_101 ;
struct V_102 * V_11 = & V_14 -> V_14 . V_11 ;
struct V_103 * V_77 = V_11 -> V_76 . V_77 ;
unsigned int V_3 ;
int V_18 ;
F_24 ( & V_77 -> V_104 ) ;
V_18 = F_25 ( & V_101 , V_77 ) ;
if ( V_18 ) {
F_26 ( & V_77 -> V_104 ) ;
return V_18 ;
}
F_27 ( & V_101 , V_11 ) ;
while ( ( V_11 = F_28 ( & V_101 ) ) ) {
struct V_6 * V_17 ;
struct V_63 * V_105 ;
struct V_66 * V_106 ;
if ( F_29 ( V_11 ) ) {
V_62 -> V_97 ++ ;
continue;
}
V_17 = F_6 ( V_11 ) ;
V_106 = F_17 ( V_17 ) ;
F_30 ( & V_106 -> V_107 , & V_62 -> V_93 ) ;
if ( V_106 -> type == V_108 ) {
V_105 = F_31 ( V_17 ) ;
V_62 -> V_85 [ V_62 -> V_98 ++ ] = V_105 ;
V_105 -> V_14 . V_109 = V_62 -> V_98 ;
} else if ( V_106 -> type == V_88 ) {
V_105 = F_31 ( V_17 ) ;
V_62 -> V_65 = F_31 ( V_17 ) ;
V_105 -> V_14 . V_109 = 0 ;
} else if ( V_106 -> type == V_110 ) {
V_62 -> V_99 = V_106 ;
} else if ( V_106 -> type == V_80 ) {
V_62 -> V_82 = V_106 ;
}
}
F_26 ( & V_77 -> V_104 ) ;
F_32 ( & V_101 ) ;
if ( V_62 -> V_98 == 0 || ! V_62 -> V_65 ) {
V_18 = - V_78 ;
goto error;
}
for ( V_3 = 0 ; V_3 < V_62 -> V_98 ; ++ V_3 ) {
V_18 = F_15 ( V_62 , V_62 -> V_85 [ V_3 ] ,
V_62 -> V_65 ) ;
if ( V_18 < 0 )
goto error;
}
return 0 ;
error:
F_21 ( V_62 ) ;
return V_18 ;
}
static int F_33 ( struct V_61 * V_62 ,
struct V_13 * V_14 )
{
int V_18 ;
F_24 ( & V_62 -> V_111 ) ;
if ( V_62 -> V_112 == 0 ) {
V_18 = F_23 ( V_62 , V_14 ) ;
if ( V_18 < 0 )
goto V_113;
}
V_62 -> V_112 ++ ;
V_18 = 0 ;
V_113:
F_26 ( & V_62 -> V_111 ) ;
return V_18 ;
}
static void F_34 ( struct V_61 * V_62 )
{
F_24 ( & V_62 -> V_111 ) ;
if ( -- V_62 -> V_112 == 0 )
F_21 ( V_62 ) ;
F_26 ( & V_62 -> V_111 ) ;
}
static void F_35 ( struct V_61 * V_62 )
{
struct V_114 * V_115 = V_62 -> V_65 -> V_11 . V_115 ;
F_36 ( V_115 , F_37 ( V_62 -> V_65 -> V_11 . V_12 ) , V_116 ) ;
V_62 -> V_94 = V_117 ;
V_62 -> V_96 = 0 ;
}
static bool F_38 ( struct V_61 * V_62 )
{
unsigned long V_118 ;
bool V_119 ;
F_39 ( & V_62 -> V_120 , V_118 ) ;
V_119 = V_62 -> V_94 == V_95 ;
F_40 ( & V_62 -> V_120 , V_118 ) ;
return V_119 ;
}
static int F_41 ( struct V_61 * V_62 )
{
struct V_66 * V_11 ;
unsigned long V_118 ;
int V_18 ;
F_39 ( & V_62 -> V_120 , V_118 ) ;
if ( V_62 -> V_94 == V_117 )
V_62 -> V_94 = V_121 ;
F_40 ( & V_62 -> V_120 , V_118 ) ;
V_18 = F_42 ( V_62 -> V_122 , F_38 ( V_62 ) ,
F_43 ( 500 ) ) ;
V_18 = V_18 == 0 ? - V_123 : 0 ;
F_44 (entity, &pipe->entities, list_pipe) {
if ( V_11 -> V_124 && V_11 -> V_124 -> V_125 )
F_36 ( V_11 -> V_115 , V_11 -> V_124 -> V_125 ,
V_126 ) ;
F_8 ( & V_11 -> V_17 , V_14 , V_127 , 0 ) ;
}
return V_18 ;
}
static bool F_45 ( struct V_61 * V_62 )
{
unsigned int V_128 ;
V_128 = ( ( 1 << V_62 -> V_98 ) - 1 ) << 1 ;
if ( ! V_62 -> V_99 )
V_128 |= 1 << 0 ;
return V_62 -> V_96 == V_128 ;
}
static struct V_129 *
F_46 ( struct V_13 * V_14 )
{
struct V_61 * V_62 = F_47 ( & V_14 -> V_14 . V_11 ) ;
struct V_129 * V_130 = NULL ;
struct V_129 * V_113 ;
unsigned long V_118 ;
unsigned int V_3 ;
F_39 ( & V_14 -> V_120 , V_118 ) ;
if ( F_48 ( & V_14 -> V_131 ) ) {
F_40 ( & V_14 -> V_120 , V_118 ) ;
return NULL ;
}
V_113 = F_49 ( & V_14 -> V_131 ,
struct V_129 , V_132 ) ;
if ( V_62 -> V_99 && F_50 ( & V_14 -> V_131 ) ) {
F_40 ( & V_14 -> V_120 , V_118 ) ;
return V_113 ;
}
F_51 ( & V_113 -> V_132 ) ;
if ( ! F_48 ( & V_14 -> V_131 ) )
V_130 = F_49 ( & V_14 -> V_131 ,
struct V_129 , V_132 ) ;
F_40 ( & V_14 -> V_120 , V_118 ) ;
V_113 -> V_133 . V_134 = V_14 -> V_134 ++ ;
V_113 -> V_133 . V_135 . V_136 = F_52 () ;
for ( V_3 = 0 ; V_3 < V_113 -> V_133 . V_135 . V_60 ; ++ V_3 )
F_53 ( & V_113 -> V_133 . V_135 , V_3 , V_113 -> V_137 [ V_3 ] ) ;
F_54 ( & V_113 -> V_133 . V_135 , V_138 ) ;
return V_130 ;
}
static void F_55 ( struct V_61 * V_62 ,
struct V_13 * V_14 )
{
struct V_129 * V_133 ;
unsigned long V_118 ;
V_133 = F_46 ( V_14 ) ;
if ( V_133 == NULL )
return;
F_39 ( & V_62 -> V_120 , V_118 ) ;
V_14 -> V_139 -> V_132 ( V_14 , V_133 ) ;
V_62 -> V_96 |= 1 << V_14 -> V_109 ;
F_40 ( & V_62 -> V_120 , V_118 ) ;
}
void F_56 ( struct V_61 * V_62 )
{
enum V_140 V_94 ;
unsigned long V_118 ;
unsigned int V_3 ;
if ( V_62 == NULL )
return;
for ( V_3 = 0 ; V_3 < V_62 -> V_98 ; ++ V_3 )
F_55 ( V_62 , & V_62 -> V_85 [ V_3 ] -> V_14 ) ;
if ( ! V_62 -> V_99 )
F_55 ( V_62 , & V_62 -> V_65 -> V_14 ) ;
F_39 ( & V_62 -> V_120 , V_118 ) ;
V_94 = V_62 -> V_94 ;
V_62 -> V_94 = V_95 ;
if ( V_94 == V_121 ) {
F_57 ( & V_62 -> V_122 ) ;
goto V_113;
}
if ( F_45 ( V_62 ) )
F_35 ( V_62 ) ;
V_113:
F_40 ( & V_62 -> V_120 , V_118 ) ;
}
void F_58 ( struct V_61 * V_62 ,
struct V_66 * V_64 ,
unsigned int V_141 )
{
struct V_66 * V_11 ;
struct V_7 * V_9 ;
V_9 = F_4 ( & V_64 -> V_74 [ V_75 ] ) ;
while ( V_9 ) {
if ( ! F_5 ( V_9 -> V_11 ) )
break;
V_11 = F_17 ( F_6 ( V_9 -> V_11 ) ) ;
if ( V_11 -> type == V_80 )
V_141 = 255 ;
if ( V_11 -> type == V_89 ) {
struct V_142 * V_90 = F_59 ( & V_11 -> V_17 ) ;
F_60 ( V_90 , V_141 ) ;
break;
}
V_9 = & V_11 -> V_74 [ V_11 -> V_92 ] ;
V_9 = F_4 ( V_9 ) ;
}
}
void F_61 ( struct V_114 * V_115 )
{
unsigned long V_118 ;
unsigned int V_3 ;
int V_18 ;
for ( V_3 = 0 ; V_3 < V_115 -> V_143 . V_144 ; ++ V_3 ) {
struct V_63 * V_145 = V_115 -> V_145 [ V_3 ] ;
struct V_61 * V_62 ;
if ( V_145 == NULL )
continue;
V_62 = F_47 ( & V_145 -> V_11 . V_17 . V_11 ) ;
if ( V_62 == NULL )
continue;
F_39 ( & V_62 -> V_120 , V_118 ) ;
if ( V_62 -> V_94 == V_117 )
V_62 -> V_94 = V_121 ;
F_40 ( & V_62 -> V_120 , V_118 ) ;
}
for ( V_3 = 0 ; V_3 < V_115 -> V_143 . V_144 ; ++ V_3 ) {
struct V_63 * V_145 = V_115 -> V_145 [ V_3 ] ;
struct V_61 * V_62 ;
if ( V_145 == NULL )
continue;
V_62 = F_47 ( & V_145 -> V_11 . V_17 . V_11 ) ;
if ( V_62 == NULL )
continue;
V_18 = F_42 ( V_62 -> V_122 , F_38 ( V_62 ) ,
F_43 ( 500 ) ) ;
if ( V_18 == 0 )
F_62 ( V_115 -> V_146 , L_1 ,
V_145 -> V_11 . V_12 ) ;
}
}
void F_63 ( struct V_114 * V_115 )
{
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < V_115 -> V_143 . V_144 ; ++ V_3 ) {
struct V_63 * V_145 = V_115 -> V_145 [ V_3 ] ;
struct V_61 * V_62 ;
if ( V_145 == NULL )
continue;
V_62 = F_47 ( & V_145 -> V_11 . V_17 . V_11 ) ;
if ( V_62 == NULL )
continue;
if ( F_45 ( V_62 ) )
F_35 ( V_62 ) ;
}
}
static int
F_64 ( struct V_147 * V_148 ,
unsigned int * V_149 , unsigned int * V_150 ,
unsigned int V_151 [] , void * V_152 [] )
{
struct V_13 * V_14 = F_65 ( V_148 ) ;
const struct V_30 * V_26 = & V_14 -> V_26 ;
unsigned int V_3 ;
if ( * V_150 ) {
if ( * V_150 != V_26 -> V_60 )
return - V_19 ;
for ( V_3 = 0 ; V_3 < * V_150 ; V_3 ++ ) {
if ( V_151 [ V_3 ] < V_26 -> V_57 [ V_3 ] . V_59 )
return - V_19 ;
V_152 [ V_3 ] = V_14 -> V_153 ;
}
return 0 ;
}
* V_150 = V_26 -> V_60 ;
for ( V_3 = 0 ; V_3 < V_26 -> V_60 ; ++ V_3 ) {
V_151 [ V_3 ] = V_26 -> V_57 [ V_3 ] . V_59 ;
V_152 [ V_3 ] = V_14 -> V_153 ;
}
return 0 ;
}
static int F_66 ( struct V_154 * V_155 )
{
struct V_156 * V_157 = F_67 ( V_155 ) ;
struct V_13 * V_14 = F_65 ( V_155 -> V_147 ) ;
struct V_129 * V_133 = F_68 ( V_157 ) ;
const struct V_30 * V_26 = & V_14 -> V_26 ;
unsigned int V_3 ;
if ( V_155 -> V_60 < V_26 -> V_60 )
return - V_19 ;
for ( V_3 = 0 ; V_3 < V_155 -> V_60 ; ++ V_3 ) {
V_133 -> V_158 [ V_3 ] = F_69 ( V_155 , V_3 ) ;
V_133 -> V_137 [ V_3 ] = F_70 ( V_155 , V_3 ) ;
if ( V_133 -> V_137 [ V_3 ] < V_26 -> V_57 [ V_3 ] . V_59 )
return - V_19 ;
}
return 0 ;
}
static void F_71 ( struct V_154 * V_155 )
{
struct V_156 * V_157 = F_67 ( V_155 ) ;
struct V_13 * V_14 = F_65 ( V_155 -> V_147 ) ;
struct V_61 * V_62 = F_47 ( & V_14 -> V_14 . V_11 ) ;
struct V_129 * V_133 = F_68 ( V_157 ) ;
unsigned long V_118 ;
bool V_159 ;
F_39 ( & V_14 -> V_120 , V_118 ) ;
V_159 = F_48 ( & V_14 -> V_131 ) ;
F_30 ( & V_133 -> V_132 , & V_14 -> V_131 ) ;
F_40 ( & V_14 -> V_120 , V_118 ) ;
if ( ! V_159 )
return;
F_39 ( & V_62 -> V_120 , V_118 ) ;
V_14 -> V_139 -> V_132 ( V_14 , V_133 ) ;
V_62 -> V_96 |= 1 << V_14 -> V_109 ;
if ( F_72 ( & V_14 -> V_132 ) &&
F_45 ( V_62 ) )
F_35 ( V_62 ) ;
F_40 ( & V_62 -> V_120 , V_118 ) ;
}
static void F_73 ( struct V_66 * V_160 )
{
struct V_66 * V_161 ;
if ( V_160 -> V_124 -> V_125 == 0 )
return;
V_161 = F_74 ( V_160 -> V_161 , struct V_66 , V_17 . V_11 ) ;
F_36 ( V_160 -> V_115 , V_160 -> V_124 -> V_125 ,
V_161 -> V_124 -> V_85 [ V_160 -> V_162 ] ) ;
}
static int F_75 ( struct V_147 * V_148 , unsigned int V_163 )
{
struct V_13 * V_14 = F_65 ( V_148 ) ;
struct V_61 * V_62 = F_47 ( & V_14 -> V_14 . V_11 ) ;
struct V_66 * V_11 ;
unsigned long V_118 ;
int V_18 ;
F_24 ( & V_62 -> V_111 ) ;
if ( V_62 -> V_164 == V_62 -> V_97 - 1 ) {
if ( V_62 -> V_90 ) {
struct V_142 * V_90 = F_59 ( & V_62 -> V_90 -> V_17 ) ;
if ( V_62 -> V_91 -> type == V_80 ) {
V_90 -> V_165 = false ;
} else {
struct V_63 * V_87 =
F_31 ( & V_62 -> V_91 -> V_17 ) ;
V_90 -> V_165 = V_87 -> V_14 . V_24 -> V_141 ;
}
}
F_44 (entity, &pipe->entities, list_pipe) {
F_73 ( V_11 ) ;
V_18 = F_8 ( & V_11 -> V_17 , V_14 ,
V_127 , 1 ) ;
if ( V_18 < 0 ) {
F_26 ( & V_62 -> V_111 ) ;
return V_18 ;
}
}
}
V_62 -> V_164 ++ ;
F_26 ( & V_62 -> V_111 ) ;
F_39 ( & V_62 -> V_120 , V_118 ) ;
if ( F_45 ( V_62 ) )
F_35 ( V_62 ) ;
F_40 ( & V_62 -> V_120 , V_118 ) ;
return 0 ;
}
static void F_76 ( struct V_147 * V_148 )
{
struct V_13 * V_14 = F_65 ( V_148 ) ;
struct V_61 * V_62 = F_47 ( & V_14 -> V_14 . V_11 ) ;
struct V_129 * V_166 ;
unsigned long V_118 ;
int V_18 ;
F_24 ( & V_62 -> V_111 ) ;
if ( -- V_62 -> V_164 == 0 ) {
V_18 = F_41 ( V_62 ) ;
if ( V_18 == - V_123 )
F_77 ( V_14 -> V_115 -> V_146 , L_2 ) ;
}
F_26 ( & V_62 -> V_111 ) ;
F_34 ( V_62 ) ;
F_78 ( & V_14 -> V_14 . V_11 ) ;
F_39 ( & V_14 -> V_120 , V_118 ) ;
F_44 (buffer, &video->irqqueue, queue)
F_54 ( & V_166 -> V_133 . V_135 , V_167 ) ;
F_22 ( & V_14 -> V_131 ) ;
F_40 ( & V_14 -> V_120 , V_118 ) ;
}
static int
F_79 ( struct V_168 * V_168 , void * V_169 , struct V_170 * V_171 )
{
struct V_172 * V_173 = V_168 -> V_174 ;
struct V_13 * V_14 = F_80 ( V_173 -> V_175 ) ;
V_171 -> V_176 = V_177 | V_178
| V_179
| V_180 ;
if ( V_14 -> type == V_181 )
V_171 -> V_182 = V_179
| V_178 ;
else
V_171 -> V_182 = V_180
| V_178 ;
F_81 ( V_171 -> V_183 , L_3 , sizeof( V_171 -> V_183 ) ) ;
F_81 ( V_171 -> V_184 , V_14 -> V_14 . V_185 , sizeof( V_171 -> V_184 ) ) ;
snprintf ( V_171 -> V_186 , sizeof( V_171 -> V_186 ) , L_4 ,
F_82 ( V_14 -> V_115 -> V_146 ) ) ;
return 0 ;
}
static int
F_83 ( struct V_168 * V_168 , void * V_169 , struct V_187 * V_26 )
{
struct V_172 * V_173 = V_168 -> V_174 ;
struct V_13 * V_14 = F_80 ( V_173 -> V_175 ) ;
if ( V_26 -> type != V_14 -> V_132 . type )
return - V_19 ;
F_24 ( & V_14 -> V_111 ) ;
V_26 -> V_16 . V_188 = V_14 -> V_26 ;
F_26 ( & V_14 -> V_111 ) ;
return 0 ;
}
static int
F_84 ( struct V_168 * V_168 , void * V_169 , struct V_187 * V_26 )
{
struct V_172 * V_173 = V_168 -> V_174 ;
struct V_13 * V_14 = F_80 ( V_173 -> V_175 ) ;
if ( V_26 -> type != V_14 -> V_132 . type )
return - V_19 ;
return F_9 ( V_14 , & V_26 -> V_16 . V_188 , NULL ) ;
}
static int
F_85 ( struct V_168 * V_168 , void * V_169 , struct V_187 * V_26 )
{
struct V_172 * V_173 = V_168 -> V_174 ;
struct V_13 * V_14 = F_80 ( V_173 -> V_175 ) ;
const struct V_1 * V_5 ;
int V_18 ;
if ( V_26 -> type != V_14 -> V_132 . type )
return - V_19 ;
V_18 = F_9 ( V_14 , & V_26 -> V_16 . V_188 , & V_5 ) ;
if ( V_18 < 0 )
return V_18 ;
F_24 ( & V_14 -> V_111 ) ;
if ( F_86 ( & V_14 -> V_132 ) ) {
V_18 = - V_189 ;
goto V_113;
}
V_14 -> V_26 = V_26 -> V_16 . V_188 ;
V_14 -> V_24 = V_5 ;
V_113:
F_26 ( & V_14 -> V_111 ) ;
return V_18 ;
}
static int
F_87 ( struct V_168 * V_168 , void * V_169 , enum V_190 type )
{
struct V_172 * V_173 = V_168 -> V_174 ;
struct V_13 * V_14 = F_80 ( V_173 -> V_175 ) ;
struct V_61 * V_62 ;
int V_18 ;
if ( V_14 -> V_132 . V_191 && V_14 -> V_132 . V_191 != V_168 -> V_174 )
return - V_189 ;
V_14 -> V_134 = 0 ;
V_62 = V_14 -> V_14 . V_11 . V_62
? F_47 ( & V_14 -> V_14 . V_11 ) : & V_14 -> V_62 ;
V_18 = F_88 ( & V_14 -> V_14 . V_11 , & V_62 -> V_62 ) ;
if ( V_18 < 0 )
return V_18 ;
V_18 = F_7 ( V_14 ) ;
if ( V_18 < 0 )
goto V_192;
V_18 = F_33 ( V_62 , V_14 ) ;
if ( V_18 < 0 )
goto V_192;
V_18 = F_89 ( & V_14 -> V_132 , type ) ;
if ( V_18 < 0 )
goto V_193;
return 0 ;
V_193:
F_34 ( V_62 ) ;
V_192:
F_78 ( & V_14 -> V_14 . V_11 ) ;
return V_18 ;
}
static int F_90 ( struct V_168 * V_168 )
{
struct V_13 * V_14 = F_91 ( V_168 ) ;
struct V_172 * V_173 ;
int V_18 = 0 ;
V_173 = F_92 ( sizeof( * V_173 ) , V_194 ) ;
if ( V_173 == NULL )
return - V_195 ;
F_93 ( V_173 , & V_14 -> V_14 ) ;
F_94 ( V_173 ) ;
V_168 -> V_174 = V_173 ;
V_18 = F_95 ( V_14 -> V_115 ) ;
if ( V_18 < 0 ) {
F_96 ( V_173 ) ;
F_97 ( V_173 ) ;
}
return V_18 ;
}
static int F_98 ( struct V_168 * V_168 )
{
struct V_13 * V_14 = F_91 ( V_168 ) ;
struct V_172 * V_173 = V_168 -> V_174 ;
F_24 ( & V_14 -> V_111 ) ;
if ( V_14 -> V_132 . V_191 == V_173 ) {
F_99 ( & V_14 -> V_132 ) ;
V_14 -> V_132 . V_191 = NULL ;
}
F_26 ( & V_14 -> V_111 ) ;
F_100 ( V_14 -> V_115 ) ;
F_101 ( V_168 ) ;
V_168 -> V_174 = NULL ;
return 0 ;
}
int F_102 ( struct V_13 * V_14 , struct V_66 * V_105 )
{
const char * V_196 ;
int V_18 ;
switch ( V_14 -> type ) {
case V_181 :
V_196 = L_5 ;
V_14 -> V_9 . V_118 = V_197 ;
break;
case V_198 :
V_196 = L_6 ;
V_14 -> V_9 . V_118 = V_199 ;
V_14 -> V_14 . V_200 = V_201 ;
break;
default:
return - V_19 ;
}
V_14 -> V_105 = V_105 ;
F_103 ( & V_14 -> V_111 ) ;
F_104 ( & V_14 -> V_120 ) ;
F_22 ( & V_14 -> V_131 ) ;
F_103 ( & V_14 -> V_62 . V_111 ) ;
F_104 ( & V_14 -> V_62 . V_120 ) ;
F_22 ( & V_14 -> V_62 . V_93 ) ;
F_105 ( & V_14 -> V_62 . V_122 ) ;
V_14 -> V_62 . V_94 = V_95 ;
V_18 = F_106 ( & V_14 -> V_14 . V_11 , 1 , & V_14 -> V_9 ) ;
if ( V_18 < 0 )
return V_18 ;
V_14 -> V_24 = F_1 ( V_42 ) ;
V_14 -> V_26 . V_41 = V_14 -> V_24 -> V_2 ;
V_14 -> V_26 . V_43 = V_44 ;
V_14 -> V_26 . V_45 = V_46 ;
V_14 -> V_26 . V_29 = V_202 ;
V_14 -> V_26 . V_28 = V_203 ;
V_14 -> V_26 . V_60 = 1 ;
V_14 -> V_26 . V_57 [ 0 ] . V_58 =
V_14 -> V_26 . V_29 * V_14 -> V_24 -> V_204 [ 0 ] / 8 ;
V_14 -> V_26 . V_57 [ 0 ] . V_59 =
V_14 -> V_26 . V_57 [ 0 ] . V_58 * V_14 -> V_26 . V_28 ;
V_14 -> V_14 . V_205 = & V_14 -> V_115 -> V_205 ;
V_14 -> V_14 . V_206 = & V_207 ;
snprintf ( V_14 -> V_14 . V_185 , sizeof( V_14 -> V_14 . V_185 ) , L_7 ,
V_105 -> V_17 . V_185 , V_196 ) ;
V_14 -> V_14 . V_208 = V_209 ;
V_14 -> V_14 . V_210 = V_211 ;
V_14 -> V_14 . V_212 = & V_213 ;
F_107 ( & V_14 -> V_14 , V_14 ) ;
V_14 -> V_153 = F_108 ( V_14 -> V_115 -> V_146 ) ;
if ( F_109 ( V_14 -> V_153 ) ) {
V_18 = F_110 ( V_14 -> V_153 ) ;
goto error;
}
V_14 -> V_132 . type = V_14 -> type ;
V_14 -> V_132 . V_214 = V_215 | V_216 | V_217 ;
V_14 -> V_132 . V_111 = & V_14 -> V_111 ;
V_14 -> V_132 . V_218 = V_14 ;
V_14 -> V_132 . V_219 = sizeof( struct V_129 ) ;
V_14 -> V_132 . V_139 = & V_220 ;
V_14 -> V_132 . V_221 = & V_222 ;
V_14 -> V_132 . V_223 = V_224 ;
V_18 = F_111 ( & V_14 -> V_132 ) ;
if ( V_18 < 0 ) {
F_77 ( V_14 -> V_115 -> V_146 , L_8 ) ;
goto error;
}
V_14 -> V_14 . V_132 = & V_14 -> V_132 ;
V_18 = F_112 ( & V_14 -> V_14 , V_209 , - 1 ) ;
if ( V_18 < 0 ) {
F_77 ( V_14 -> V_115 -> V_146 , L_9 ) ;
goto error;
}
return 0 ;
error:
F_113 ( V_14 -> V_153 ) ;
F_114 ( V_14 ) ;
return V_18 ;
}
void F_114 ( struct V_13 * V_14 )
{
if ( F_115 ( & V_14 -> V_14 ) )
F_116 ( & V_14 -> V_14 ) ;
F_113 ( V_14 -> V_153 ) ;
F_117 ( & V_14 -> V_14 . V_11 ) ;
}
