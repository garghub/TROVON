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
V_9 = F_4 ( & V_55 -> V_11 . V_60 [ V_61 ] ) ;
while ( 1 ) {
if ( V_9 == NULL )
return - V_62 ;
if ( F_5 ( V_9 -> V_11 ) != V_12 )
return - V_62 ;
V_11 = F_17 ( F_6 ( V_9 -> V_11 ) ) ;
if ( V_11 -> type == V_63 )
break;
if ( V_58 & ( 1 << V_11 -> V_18 . V_11 . V_64 ) )
return - V_62 ;
V_58 |= 1 << V_11 -> V_18 . V_11 . V_64 ;
if ( V_11 -> type == V_65 ) {
if ( V_59 )
return - V_62 ;
V_59 = true ;
}
V_9 = & V_11 -> V_60 [ V_11 -> V_66 ] ;
V_9 = F_4 ( V_9 ) ;
}
if ( V_11 != & V_56 -> V_11 )
return - V_62 ;
return 0 ;
}
static int F_18 ( struct V_67 * V_68 ,
struct V_14 * V_15 )
{
struct V_69 V_70 ;
struct V_71 * V_11 = & V_15 -> V_15 . V_11 ;
struct V_72 * V_73 = V_11 -> V_74 ;
unsigned int V_3 ;
int V_19 ;
F_19 ( & V_73 -> V_75 ) ;
F_20 ( & V_70 , V_11 ) ;
while ( ( V_11 = F_21 ( & V_70 ) ) ) {
struct V_6 * V_18 ;
struct V_54 * V_76 ;
struct V_57 * V_77 ;
if ( F_5 ( V_11 ) != V_12 ) {
V_68 -> V_78 ++ ;
continue;
}
V_18 = F_6 ( V_11 ) ;
V_77 = F_17 ( V_18 ) ;
F_22 ( & V_77 -> V_79 , & V_68 -> V_58 ) ;
if ( V_77 -> type == V_80 ) {
V_76 = F_23 ( V_18 ) ;
V_68 -> V_81 [ V_68 -> V_82 ++ ] = V_76 ;
V_76 -> V_15 . V_83 = V_68 -> V_82 ;
} else if ( V_77 -> type == V_63 ) {
V_76 = F_23 ( V_18 ) ;
V_68 -> V_56 = F_23 ( V_18 ) ;
V_76 -> V_15 . V_83 = 0 ;
} else if ( V_77 -> type == V_84 ) {
V_68 -> V_85 = V_77 ;
}
}
F_24 ( & V_73 -> V_75 ) ;
if ( V_68 -> V_82 == 0 || ! V_68 -> V_56 ) {
V_19 = - V_62 ;
goto error;
}
for ( V_3 = 0 ; V_3 < V_68 -> V_82 ; ++ V_3 ) {
V_19 = F_16 ( V_68 -> V_81 [ V_3 ] ,
V_68 -> V_56 ) ;
if ( V_19 < 0 )
goto error;
}
return 0 ;
error:
F_25 ( & V_68 -> V_58 ) ;
V_68 -> V_86 = 0 ;
V_68 -> V_78 = 0 ;
V_68 -> V_82 = 0 ;
V_68 -> V_56 = NULL ;
V_68 -> V_85 = NULL ;
return V_19 ;
}
static int F_26 ( struct V_67 * V_68 ,
struct V_14 * V_15 )
{
int V_19 ;
F_19 ( & V_68 -> V_87 ) ;
if ( V_68 -> V_88 == 0 ) {
V_19 = F_18 ( V_68 , V_15 ) ;
if ( V_19 < 0 )
goto V_89;
}
V_68 -> V_88 ++ ;
V_19 = 0 ;
V_89:
F_24 ( & V_68 -> V_87 ) ;
return V_19 ;
}
static void F_27 ( struct V_67 * V_68 )
{
F_19 ( & V_68 -> V_87 ) ;
if ( -- V_68 -> V_88 == 0 ) {
F_25 ( & V_68 -> V_58 ) ;
V_68 -> V_90 = V_91 ;
V_68 -> V_86 = 0 ;
V_68 -> V_78 = 0 ;
V_68 -> V_82 = 0 ;
V_68 -> V_56 = NULL ;
V_68 -> V_85 = NULL ;
}
F_24 ( & V_68 -> V_87 ) ;
}
static void F_28 ( struct V_67 * V_68 )
{
struct V_92 * V_93 = V_68 -> V_56 -> V_11 . V_93 ;
F_29 ( V_93 , F_30 ( V_68 -> V_56 -> V_11 . V_13 ) , V_94 ) ;
V_68 -> V_90 = V_95 ;
V_68 -> V_86 = 0 ;
}
static int F_31 ( struct V_67 * V_68 )
{
struct V_57 * V_11 ;
unsigned long V_96 ;
int V_19 ;
F_32 ( & V_68 -> V_97 , V_96 ) ;
V_68 -> V_90 = V_98 ;
F_33 ( & V_68 -> V_97 , V_96 ) ;
V_19 = F_34 ( V_68 -> V_99 , V_68 -> V_90 == V_91 ,
F_35 ( 500 ) ) ;
V_19 = V_19 == 0 ? - V_100 : 0 ;
F_36 (entity, &pipe->entities, list_pipe) {
if ( V_11 -> V_101 )
F_29 ( V_11 -> V_93 , V_11 -> V_101 ,
V_102 ) ;
F_8 ( & V_11 -> V_18 , V_15 , V_103 , 0 ) ;
}
return V_19 ;
}
static bool F_37 ( struct V_67 * V_68 )
{
unsigned int V_104 ;
V_104 = ( ( 1 << V_68 -> V_82 ) - 1 ) << 1 ;
if ( ! V_68 -> V_85 )
V_104 |= 1 << 0 ;
return V_68 -> V_86 == V_104 ;
}
static struct V_105 *
F_38 ( struct V_14 * V_15 )
{
struct V_105 * V_106 = NULL ;
struct V_105 * V_89 ;
unsigned long V_96 ;
unsigned int V_3 ;
F_32 ( & V_15 -> V_97 , V_96 ) ;
if ( F_39 ( & V_15 -> V_107 ) ) {
F_33 ( & V_15 -> V_97 , V_96 ) ;
return NULL ;
}
V_89 = F_40 ( & V_15 -> V_107 ,
struct V_105 , V_108 ) ;
F_41 ( & V_89 -> V_108 ) ;
if ( ! F_39 ( & V_15 -> V_107 ) )
V_106 = F_40 ( & V_15 -> V_107 ,
struct V_105 , V_108 ) ;
F_33 ( & V_15 -> V_97 , V_96 ) ;
V_89 -> V_109 . V_110 . V_111 = V_15 -> V_111 ++ ;
F_42 ( & V_89 -> V_109 . V_110 . V_112 ) ;
for ( V_3 = 0 ; V_3 < V_89 -> V_109 . V_52 ; ++ V_3 )
F_43 ( & V_89 -> V_109 , V_3 , V_89 -> V_113 [ V_3 ] ) ;
F_44 ( & V_89 -> V_109 , V_114 ) ;
return V_106 ;
}
static void F_45 ( struct V_67 * V_68 ,
struct V_14 * V_15 )
{
struct V_105 * V_109 ;
unsigned long V_96 ;
V_109 = F_38 ( V_15 ) ;
if ( V_109 == NULL )
return;
F_32 ( & V_68 -> V_97 , V_96 ) ;
V_15 -> V_115 -> V_108 ( V_15 , V_109 ) ;
V_68 -> V_86 |= 1 << V_15 -> V_83 ;
F_33 ( & V_68 -> V_97 , V_96 ) ;
}
void F_46 ( struct V_67 * V_68 )
{
unsigned long V_96 ;
unsigned int V_3 ;
if ( V_68 == NULL )
return;
for ( V_3 = 0 ; V_3 < V_68 -> V_82 ; ++ V_3 )
F_45 ( V_68 , & V_68 -> V_81 [ V_3 ] -> V_15 ) ;
if ( ! V_68 -> V_85 )
F_45 ( V_68 , & V_68 -> V_56 -> V_15 ) ;
F_32 ( & V_68 -> V_97 , V_96 ) ;
if ( V_68 -> V_90 == V_98 ) {
V_68 -> V_90 = V_91 ;
F_47 ( & V_68 -> V_99 ) ;
goto V_89;
}
if ( F_37 ( V_68 ) )
F_28 ( V_68 ) ;
V_89:
F_33 ( & V_68 -> V_97 , V_96 ) ;
}
static int
F_48 ( struct V_116 * V_117 , const struct V_118 * V_17 ,
unsigned int * V_119 , unsigned int * V_120 ,
unsigned int V_121 [] , void * V_122 [] )
{
struct V_14 * V_15 = F_49 ( V_117 ) ;
const struct V_31 * V_27 ;
struct V_31 V_123 ;
unsigned int V_3 ;
if ( V_17 ) {
if ( ! F_15 ( V_15 , & V_17 -> V_17 . V_123 , & V_123 ) )
return - V_20 ;
V_27 = & V_123 ;
} else {
V_27 = & V_15 -> V_27 ;
}
* V_120 = V_27 -> V_52 ;
for ( V_3 = 0 ; V_3 < V_27 -> V_52 ; ++ V_3 ) {
V_121 [ V_3 ] = V_27 -> V_49 [ V_3 ] . V_51 ;
V_122 [ V_3 ] = V_15 -> V_124 ;
}
return 0 ;
}
static int F_50 ( struct V_125 * V_126 )
{
struct V_14 * V_15 = F_49 ( V_126 -> V_116 ) ;
struct V_105 * V_109 = F_51 ( V_126 ) ;
const struct V_31 * V_27 = & V_15 -> V_27 ;
unsigned int V_3 ;
if ( V_126 -> V_52 < V_27 -> V_52 )
return - V_20 ;
V_109 -> V_15 = V_15 ;
for ( V_3 = 0 ; V_3 < V_126 -> V_52 ; ++ V_3 ) {
V_109 -> V_127 [ V_3 ] = F_52 ( V_126 , V_3 ) ;
V_109 -> V_113 [ V_3 ] = F_53 ( V_126 , V_3 ) ;
if ( V_109 -> V_113 [ V_3 ] < V_27 -> V_49 [ V_3 ] . V_51 )
return - V_20 ;
}
return 0 ;
}
static void F_54 ( struct V_125 * V_126 )
{
struct V_14 * V_15 = F_49 ( V_126 -> V_116 ) ;
struct V_67 * V_68 = F_55 ( & V_15 -> V_15 . V_11 ) ;
struct V_105 * V_109 = F_51 ( V_126 ) ;
unsigned long V_96 ;
bool V_128 ;
F_32 ( & V_15 -> V_97 , V_96 ) ;
V_128 = F_39 ( & V_15 -> V_107 ) ;
F_22 ( & V_109 -> V_108 , & V_15 -> V_107 ) ;
F_33 ( & V_15 -> V_97 , V_96 ) ;
if ( ! V_128 )
return;
F_32 ( & V_68 -> V_97 , V_96 ) ;
V_15 -> V_115 -> V_108 ( V_15 , V_109 ) ;
V_68 -> V_86 |= 1 << V_15 -> V_83 ;
if ( F_56 ( & V_15 -> V_108 ) &&
F_37 ( V_68 ) )
F_28 ( V_68 ) ;
F_33 ( & V_68 -> V_97 , V_96 ) ;
}
static void F_57 ( struct V_57 * V_129 )
{
struct V_57 * V_130 ;
if ( V_129 -> V_101 == 0 )
return;
V_130 = F_58 ( V_129 -> V_130 , struct V_57 , V_18 . V_11 ) ;
F_29 ( V_129 -> V_93 , V_129 -> V_101 , V_130 -> V_64 ) ;
}
static int F_59 ( struct V_116 * V_117 , unsigned int V_131 )
{
struct V_14 * V_15 = F_49 ( V_117 ) ;
struct V_67 * V_68 = F_55 ( & V_15 -> V_15 . V_11 ) ;
struct V_57 * V_11 ;
unsigned long V_96 ;
int V_19 ;
F_19 ( & V_68 -> V_87 ) ;
if ( V_68 -> V_132 == V_68 -> V_78 - 1 ) {
F_36 (entity, &pipe->entities, list_pipe) {
F_57 ( V_11 ) ;
V_19 = F_8 ( & V_11 -> V_18 , V_15 ,
V_103 , 1 ) ;
if ( V_19 < 0 ) {
F_24 ( & V_68 -> V_87 ) ;
return V_19 ;
}
}
}
V_68 -> V_132 ++ ;
F_24 ( & V_68 -> V_87 ) ;
F_32 ( & V_68 -> V_97 , V_96 ) ;
if ( F_37 ( V_68 ) )
F_28 ( V_68 ) ;
F_33 ( & V_68 -> V_97 , V_96 ) ;
return 0 ;
}
static int F_60 ( struct V_116 * V_117 )
{
struct V_14 * V_15 = F_49 ( V_117 ) ;
struct V_67 * V_68 = F_55 ( & V_15 -> V_15 . V_11 ) ;
unsigned long V_96 ;
int V_19 ;
F_19 ( & V_68 -> V_87 ) ;
if ( -- V_68 -> V_132 == 0 ) {
V_19 = F_31 ( V_68 ) ;
if ( V_19 == - V_100 )
F_61 ( V_15 -> V_93 -> V_133 , L_1 ) ;
}
F_24 ( & V_68 -> V_87 ) ;
F_27 ( V_68 ) ;
F_62 ( & V_15 -> V_15 . V_11 ) ;
F_32 ( & V_15 -> V_97 , V_96 ) ;
F_25 ( & V_15 -> V_107 ) ;
F_33 ( & V_15 -> V_97 , V_96 ) ;
return 0 ;
}
static int
F_63 ( struct V_134 * V_134 , void * V_135 , struct V_136 * V_137 )
{
struct V_138 * V_139 = V_134 -> V_140 ;
struct V_14 * V_15 = F_64 ( V_139 -> V_141 ) ;
V_137 -> V_142 = V_143 | V_144
| V_145
| V_146 ;
if ( V_15 -> type == V_147 )
V_137 -> V_148 = V_145
| V_144 ;
else
V_137 -> V_148 = V_146
| V_144 ;
F_65 ( V_137 -> V_149 , L_2 , sizeof( V_137 -> V_149 ) ) ;
F_65 ( V_137 -> V_150 , V_15 -> V_15 . V_151 , sizeof( V_137 -> V_150 ) ) ;
snprintf ( V_137 -> V_152 , sizeof( V_137 -> V_152 ) , L_3 ,
F_66 ( V_15 -> V_93 -> V_133 ) ) ;
return 0 ;
}
static int
F_67 ( struct V_134 * V_134 , void * V_135 , struct V_118 * V_27 )
{
struct V_138 * V_139 = V_134 -> V_140 ;
struct V_14 * V_15 = F_64 ( V_139 -> V_141 ) ;
if ( V_27 -> type != V_15 -> V_108 . type )
return - V_20 ;
F_19 ( & V_15 -> V_87 ) ;
V_27 -> V_17 . V_123 = V_15 -> V_27 ;
F_24 ( & V_15 -> V_87 ) ;
return 0 ;
}
static int
F_68 ( struct V_134 * V_134 , void * V_135 , struct V_118 * V_27 )
{
struct V_138 * V_139 = V_134 -> V_140 ;
struct V_14 * V_15 = F_64 ( V_139 -> V_141 ) ;
if ( V_27 -> type != V_15 -> V_108 . type )
return - V_20 ;
return F_9 ( V_15 , & V_27 -> V_17 . V_123 , NULL ) ;
}
static int
F_69 ( struct V_134 * V_134 , void * V_135 , struct V_118 * V_27 )
{
struct V_138 * V_139 = V_134 -> V_140 ;
struct V_14 * V_15 = F_64 ( V_139 -> V_141 ) ;
const struct V_1 * V_5 ;
int V_19 ;
if ( V_27 -> type != V_15 -> V_108 . type )
return - V_20 ;
V_19 = F_9 ( V_15 , & V_27 -> V_17 . V_123 , & V_5 ) ;
if ( V_19 < 0 )
return V_19 ;
F_19 ( & V_15 -> V_87 ) ;
if ( F_70 ( & V_15 -> V_108 ) ) {
V_19 = - V_153 ;
goto V_89;
}
V_15 -> V_27 = V_27 -> V_17 . V_123 ;
V_15 -> V_25 = V_5 ;
V_89:
F_24 ( & V_15 -> V_87 ) ;
return V_19 ;
}
static int
F_71 ( struct V_134 * V_134 , void * V_135 , enum V_154 type )
{
struct V_138 * V_139 = V_134 -> V_140 ;
struct V_14 * V_15 = F_64 ( V_139 -> V_141 ) ;
struct V_67 * V_68 ;
int V_19 ;
if ( V_15 -> V_108 . V_155 && V_15 -> V_108 . V_155 != V_134 -> V_140 )
return - V_153 ;
V_15 -> V_111 = 0 ;
V_68 = V_15 -> V_15 . V_11 . V_68
? F_55 ( & V_15 -> V_15 . V_11 ) : & V_15 -> V_68 ;
V_19 = F_72 ( & V_15 -> V_15 . V_11 , & V_68 -> V_68 ) ;
if ( V_19 < 0 )
return V_19 ;
V_19 = F_7 ( V_15 ) ;
if ( V_19 < 0 )
goto V_156;
V_19 = F_26 ( V_68 , V_15 ) ;
if ( V_19 < 0 )
goto V_156;
V_19 = F_73 ( & V_15 -> V_108 , type ) ;
if ( V_19 < 0 )
goto V_157;
return 0 ;
V_157:
F_27 ( V_68 ) ;
V_156:
F_62 ( & V_15 -> V_15 . V_11 ) ;
return V_19 ;
}
static int F_74 ( struct V_134 * V_134 )
{
struct V_14 * V_15 = F_75 ( V_134 ) ;
struct V_138 * V_139 ;
int V_19 = 0 ;
V_139 = F_76 ( sizeof( * V_139 ) , V_158 ) ;
if ( V_139 == NULL )
return - V_159 ;
F_77 ( V_139 , & V_15 -> V_15 ) ;
F_78 ( V_139 ) ;
V_134 -> V_140 = V_139 ;
if ( ! F_79 ( V_15 -> V_93 ) ) {
V_19 = - V_153 ;
F_80 ( V_139 ) ;
F_81 ( V_139 ) ;
}
return V_19 ;
}
static int F_82 ( struct V_134 * V_134 )
{
struct V_14 * V_15 = F_75 ( V_134 ) ;
struct V_138 * V_139 = V_134 -> V_140 ;
F_19 ( & V_15 -> V_87 ) ;
if ( V_15 -> V_108 . V_155 == V_139 ) {
F_83 ( & V_15 -> V_108 ) ;
V_15 -> V_108 . V_155 = NULL ;
}
F_24 ( & V_15 -> V_87 ) ;
F_84 ( V_15 -> V_93 ) ;
F_85 ( V_134 ) ;
V_134 -> V_140 = NULL ;
return 0 ;
}
int F_86 ( struct V_14 * V_15 , struct V_57 * V_76 )
{
const char * V_160 ;
int V_19 ;
switch ( V_15 -> type ) {
case V_147 :
V_160 = L_4 ;
V_15 -> V_9 . V_96 = V_161 ;
break;
case V_162 :
V_160 = L_5 ;
V_15 -> V_9 . V_96 = V_163 ;
V_15 -> V_15 . V_164 = V_165 ;
break;
default:
return - V_20 ;
}
V_15 -> V_76 = V_76 ;
F_87 ( & V_15 -> V_87 ) ;
F_88 ( & V_15 -> V_97 ) ;
F_25 ( & V_15 -> V_107 ) ;
F_87 ( & V_15 -> V_68 . V_87 ) ;
F_88 ( & V_15 -> V_68 . V_97 ) ;
F_25 ( & V_15 -> V_68 . V_58 ) ;
F_89 ( & V_15 -> V_68 . V_99 ) ;
V_15 -> V_68 . V_90 = V_91 ;
V_19 = F_90 ( & V_15 -> V_15 . V_11 , 1 , & V_15 -> V_9 , 0 ) ;
if ( V_19 < 0 )
return V_19 ;
V_15 -> V_25 = F_1 ( V_34 ) ;
V_15 -> V_27 . V_33 = V_15 -> V_25 -> V_2 ;
V_15 -> V_27 . V_35 = V_36 ;
V_15 -> V_27 . V_37 = V_38 ;
V_15 -> V_27 . V_30 = V_166 ;
V_15 -> V_27 . V_29 = V_167 ;
V_15 -> V_27 . V_52 = 1 ;
V_15 -> V_27 . V_49 [ 0 ] . V_50 =
V_15 -> V_27 . V_30 * V_15 -> V_25 -> V_168 [ 0 ] / 8 ;
V_15 -> V_27 . V_49 [ 0 ] . V_51 =
V_15 -> V_27 . V_49 [ 0 ] . V_50 * V_15 -> V_27 . V_29 ;
V_15 -> V_15 . V_169 = & V_15 -> V_93 -> V_169 ;
V_15 -> V_15 . V_170 = & V_171 ;
snprintf ( V_15 -> V_15 . V_151 , sizeof( V_15 -> V_15 . V_151 ) , L_6 ,
V_76 -> V_18 . V_151 , V_160 ) ;
V_15 -> V_15 . V_172 = V_173 ;
V_15 -> V_15 . V_174 = V_175 ;
V_15 -> V_15 . V_176 = & V_177 ;
F_91 ( & V_15 -> V_15 , V_15 ) ;
V_15 -> V_124 = F_92 ( V_15 -> V_93 -> V_133 ) ;
if ( F_93 ( V_15 -> V_124 ) ) {
V_19 = F_94 ( V_15 -> V_124 ) ;
goto error;
}
V_15 -> V_108 . type = V_15 -> type ;
V_15 -> V_108 . V_178 = V_179 | V_180 | V_181 ;
V_15 -> V_108 . V_87 = & V_15 -> V_87 ;
V_15 -> V_108 . V_182 = V_15 ;
V_15 -> V_108 . V_183 = sizeof( struct V_105 ) ;
V_15 -> V_108 . V_115 = & V_184 ;
V_15 -> V_108 . V_185 = & V_186 ;
V_15 -> V_108 . V_187 = V_188 ;
V_19 = F_95 ( & V_15 -> V_108 ) ;
if ( V_19 < 0 ) {
F_61 ( V_15 -> V_93 -> V_133 , L_7 ) ;
goto error;
}
V_15 -> V_15 . V_108 = & V_15 -> V_108 ;
V_19 = F_96 ( & V_15 -> V_15 , V_173 , - 1 ) ;
if ( V_19 < 0 ) {
F_61 ( V_15 -> V_93 -> V_133 , L_8 ) ;
goto error;
}
return 0 ;
error:
F_97 ( V_15 -> V_124 ) ;
F_98 ( V_15 ) ;
return V_19 ;
}
void F_98 ( struct V_14 * V_15 )
{
if ( F_99 ( & V_15 -> V_15 ) )
F_100 ( & V_15 -> V_15 ) ;
F_97 ( V_15 -> V_124 ) ;
F_101 ( & V_15 -> V_15 . V_11 ) ;
}
