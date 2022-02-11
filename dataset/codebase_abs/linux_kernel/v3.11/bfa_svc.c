static int
F_1 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_3 != V_4 ) &&
( V_2 -> V_3 != V_5 ) )
return 1 ;
if ( ( V_2 -> V_3 != V_4 ) &&
( V_2 -> V_6 > V_7 ) )
return 1 ;
return 0 ;
}
static T_1
F_2 ( void )
{
T_1 V_8 = 0 ;
struct V_9 V_10 ;
F_3 ( & V_10 ) ;
V_8 = V_10 . V_11 ;
return V_8 ;
}
static void
F_4 ( struct V_12 * V_13 , struct V_1 * V_2 )
{
T_2 V_14 ;
struct V_1 * V_15 ;
if ( V_13 -> V_16 == 0 )
return;
if ( F_1 ( V_2 ) ) {
F_5 ( 1 ) ;
return;
}
V_14 = V_13 -> V_14 ;
V_15 = & ( V_13 -> V_17 [ V_14 ] ) ;
memcpy ( V_15 , V_2 , sizeof( struct V_1 ) ) ;
V_15 -> V_10 = F_2 () ;
F_6 ( V_13 -> V_14 ) ;
if ( V_13 -> V_18 == V_13 -> V_14 )
F_6 ( V_13 -> V_18 ) ;
}
void
F_7 ( struct V_12 * V_13 )
{
memset ( ( char * ) V_13 , 0 , sizeof( struct V_12 ) ) ;
memcpy ( V_13 -> V_19 , V_20 , V_21 ) ;
V_13 -> V_18 = V_13 -> V_14 = 0 ;
V_13 -> V_16 = 1 ;
}
void
F_8 ( struct V_12 * V_13 , enum V_22 V_23 ,
enum V_24 V_25 ,
T_2 V_26 , char * V_27 )
{
struct V_1 V_28 ;
if ( V_13 -> V_16 ) {
memset ( & V_28 , 0 , sizeof( struct V_1 ) ) ;
V_28 . V_23 = V_23 ;
V_28 . V_29 = V_25 ;
V_28 . V_3 = V_5 ;
V_28 . V_26 = V_26 ;
strncpy ( V_28 . V_30 . V_31 , V_27 ,
V_32 - 1 ) ;
V_28 . V_30 . V_31 [ V_32 - 1 ] = '\0' ;
F_4 ( V_13 , & V_28 ) ;
}
}
void
F_9 ( struct V_12 * V_13 , enum V_22 V_23 ,
enum V_24 V_25 ,
T_2 V_26 , T_3 * V_33 , T_3 V_34 )
{
struct V_1 V_28 ;
T_3 V_35 ;
if ( V_34 > V_7 )
V_34 = V_7 ;
if ( V_13 -> V_16 ) {
memset ( & V_28 , 0 , sizeof( struct V_1 ) ) ;
V_28 . V_23 = V_23 ;
V_28 . V_29 = V_25 ;
V_28 . V_3 = V_4 ;
V_28 . V_26 = V_26 ;
for ( V_35 = 0 ; V_35 < V_34 ; V_35 ++ )
V_28 . V_30 . V_36 [ V_35 ] = V_33 [ V_35 ] ;
V_28 . V_6 = ( V_37 ) V_34 ;
F_4 ( V_13 , & V_28 ) ;
}
}
void
F_10 ( struct V_12 * V_13 , enum V_22 V_23 ,
enum V_24 V_25 ,
T_2 V_26 , struct V_38 * V_39 )
{
struct V_1 V_28 ;
T_3 * V_40 = ( T_3 * ) V_39 ;
T_3 V_41 [ V_7 ] ;
if ( V_13 -> V_16 ) {
memset ( & V_28 , 0 , sizeof( struct V_1 ) ) ;
V_41 [ 0 ] = V_40 [ 0 ] ;
V_41 [ 1 ] = V_40 [ 1 ] ;
V_41 [ 2 ] = V_40 [ 4 ] ;
F_9 ( V_13 , V_23 , V_25 , V_26 , V_41 , 3 ) ;
}
}
void
F_11 ( struct V_12 * V_13 , enum V_22 V_23 ,
enum V_24 V_25 , T_2 V_26 , struct V_38 * V_39 ,
T_3 V_42 )
{
struct V_1 V_28 ;
T_3 * V_40 = ( T_3 * ) V_39 ;
T_3 V_41 [ V_7 ] ;
if ( V_13 -> V_16 ) {
memset ( & V_28 , 0 , sizeof( struct V_1 ) ) ;
V_41 [ 0 ] = V_40 [ 0 ] ;
V_41 [ 1 ] = V_40 [ 1 ] ;
V_41 [ 2 ] = V_40 [ 4 ] ;
V_41 [ 3 ] = V_42 ;
F_9 ( V_13 , V_23 , V_25 , V_26 , V_41 , 4 ) ;
}
}
static void
F_12 ( struct V_43 * V_44 )
{
T_2 V_35 ;
struct V_45 * V_46 ;
V_46 = (struct V_45 * ) F_13 ( V_44 ) ;
memset ( V_46 , 0 , sizeof( struct V_45 ) * V_44 -> V_47 ) ;
F_14 ( & V_44 -> V_48 ) ;
F_14 ( & V_44 -> V_49 ) ;
F_14 ( & V_44 -> V_50 ) ;
F_14 ( & V_44 -> V_51 ) ;
F_14 ( & V_44 -> V_52 ) ;
V_44 -> V_53 = V_46 ;
for ( V_35 = 0 ; V_35 < V_44 -> V_47 ; V_35 ++ ) {
V_46 -> V_54 = V_44 ;
V_46 -> V_55 = V_35 ;
if ( V_35 < ( V_44 -> V_47 / 2 ) ) {
F_15 ( & V_46 -> V_56 , & V_44 -> V_48 ) ;
V_46 -> V_57 = V_58 ;
} else {
F_15 ( & V_46 -> V_56 , & V_44 -> V_49 ) ;
V_46 -> V_57 = V_59 ;
}
F_16 ( & V_46 -> V_60 , V_61 , V_46 ) ;
V_46 -> V_62 = V_59 ;
V_46 = V_46 + 1 ;
}
F_13 ( V_44 ) = ( void * ) V_46 ;
}
static void
F_17 ( struct V_63 * V_64 , struct V_65 * V_66 ,
struct V_67 * V_68 )
{
struct V_43 * V_54 = F_18 ( V_68 ) ;
struct V_69 * V_70 = F_19 ( V_68 ) ;
struct V_71 * V_72 ;
T_2 V_73 , V_74 , V_75 ;
T_2 V_47 = V_64 -> V_76 . V_77 ;
T_3 V_78 ;
if ( V_47 == 0 )
return;
if ( V_64 -> V_79 . V_80 )
V_78 = 2 * V_81 ;
else
V_78 = V_81 + V_82 ;
V_73 = F_20 ( V_47 , V_78 ) ;
V_75 = F_21 ( V_78 ) ;
F_22 (fcxp_mod, seg_ptr, nsegs, idx) {
if ( V_47 >= V_75 ) {
V_47 -= V_75 ;
F_23 ( V_66 , V_72 ,
V_75 * V_78 ) ;
} else
F_23 ( V_66 , V_72 ,
V_47 * V_78 ) ;
}
F_24 ( V_66 , V_70 ,
V_64 -> V_76 . V_77 * sizeof( struct V_45 ) ) ;
}
static void
F_25 ( struct V_67 * V_68 , void * V_83 , struct V_63 * V_64 ,
struct V_84 * V_85 )
{
struct V_43 * V_44 = F_18 ( V_68 ) ;
V_44 -> V_68 = V_68 ;
V_44 -> V_47 = V_64 -> V_76 . V_77 ;
V_44 -> V_86 = V_44 -> V_87 = V_81 ;
if ( ! V_64 -> V_79 . V_80 )
V_44 -> V_87 = V_82 ;
F_14 ( & V_44 -> V_88 ) ;
F_14 ( & V_44 -> V_89 ) ;
F_12 ( V_44 ) ;
}
static void
F_26 ( struct V_67 * V_68 )
{
}
static void
F_27 ( struct V_67 * V_68 )
{
}
static void
F_28 ( struct V_67 * V_68 )
{
}
static void
F_29 ( struct V_67 * V_68 )
{
struct V_43 * V_44 = F_18 ( V_68 ) ;
struct V_45 * V_46 ;
struct V_90 * V_56 , * V_91 ;
F_30 ( & V_44 -> V_51 , & V_44 -> V_48 ) ;
F_30 ( & V_44 -> V_52 , & V_44 -> V_49 ) ;
F_31 (qe, qen, &mod->fcxp_active_q) {
V_46 = (struct V_45 * ) V_56 ;
if ( V_46 -> V_92 == NULL ) {
V_46 -> V_93 ( V_46 -> V_92 , V_46 , V_46 -> V_94 ,
V_95 , 0 , 0 , NULL ) ;
F_32 ( V_46 ) ;
} else {
V_46 -> V_96 = V_95 ;
F_33 ( V_68 , & V_46 -> V_97 ,
V_98 , V_46 ) ;
}
}
}
static struct V_45 *
F_34 ( struct V_43 * V_99 , T_4 V_100 )
{
struct V_45 * V_46 ;
if ( V_100 )
F_35 ( & V_99 -> V_48 , & V_46 ) ;
else
F_35 ( & V_99 -> V_49 , & V_46 ) ;
if ( V_46 )
F_15 ( & V_46 -> V_56 , & V_99 -> V_50 ) ;
return V_46 ;
}
static void
F_36 ( struct V_45 * V_46 ,
struct V_67 * V_68 ,
V_37 * V_101 ,
T_3 * V_102 ,
T_5 * V_103 ,
T_6 * V_104 ,
struct V_90 * V_105 ,
int V_106 ,
T_5 V_107 ,
T_6 V_108 )
{
F_5 ( V_68 == NULL ) ;
F_37 ( V_68 , V_46 -> V_55 ) ;
if ( V_106 == 0 ) {
* V_101 = 1 ;
} else {
F_5 ( * V_107 == NULL ) ;
F_5 ( * V_108 == NULL ) ;
* V_101 = 0 ;
* V_103 = V_107 ;
* V_104 = V_108 ;
* V_102 = V_106 ;
if ( V_106 > V_109 )
F_5 ( 1 ) ;
}
}
static void
F_38 ( struct V_45 * V_46 ,
void * V_92 , struct V_67 * V_68 , int V_110 ,
int V_111 , T_5 V_112 ,
T_6 V_113 ,
T_5 V_114 ,
T_6 V_115 )
{
F_5 ( V_68 == NULL ) ;
F_37 ( V_68 , V_46 -> V_55 ) ;
V_46 -> V_92 = V_92 ;
F_36 ( V_46 , V_68 ,
& V_46 -> V_116 , & V_46 -> V_110 , & V_46 -> V_112 ,
& V_46 -> V_113 , & V_46 -> V_117 ,
V_110 , V_112 , V_113 ) ;
F_36 ( V_46 , V_68 ,
& V_46 -> V_118 , & V_46 -> V_111 , & V_46 -> V_114 ,
& V_46 -> V_115 , & V_46 -> V_119 ,
V_111 , V_114 , V_115 ) ;
}
static void
F_39 ( struct V_45 * V_46 )
{
struct V_43 * V_44 = V_46 -> V_54 ;
struct V_120 * V_121 ;
if ( V_46 -> V_57 )
F_35 ( & V_44 -> V_88 , & V_121 ) ;
else
F_35 ( & V_44 -> V_89 , & V_121 ) ;
if ( V_121 ) {
F_37 ( V_44 -> V_68 , V_46 -> V_55 ) ;
F_38 ( V_46 , V_121 -> V_92 , V_121 -> V_68 , V_121 -> V_110 ,
V_121 -> V_111 , V_121 -> V_112 ,
V_121 -> V_113 , V_121 -> V_114 ,
V_121 -> V_115 ) ;
V_121 -> V_122 ( V_121 -> V_123 , V_46 ) ;
return;
}
F_5 ( ! F_40 ( & V_44 -> V_50 , V_46 ) ) ;
F_41 ( & V_46 -> V_56 ) ;
if ( V_46 -> V_57 )
F_15 ( & V_46 -> V_56 , & V_44 -> V_48 ) ;
else
F_15 ( & V_46 -> V_56 , & V_44 -> V_49 ) ;
}
static void
F_42 ( void * V_124 , struct V_45 * V_46 , void * V_125 ,
T_7 V_126 , T_3 V_127 ,
T_3 V_128 , struct V_38 * V_129 )
{
}
static void
V_98 ( void * V_125 , T_4 V_130 )
{
struct V_45 * V_46 = V_125 ;
if ( V_130 ) {
V_46 -> V_93 ( V_46 -> V_92 , V_46 , V_46 -> V_94 ,
V_46 -> V_96 , V_46 -> V_127 ,
V_46 -> V_131 , & V_46 -> V_129 ) ;
} else {
F_32 ( V_46 ) ;
}
}
static void
F_43 ( struct V_67 * V_68 , struct V_132 * V_133 )
{
struct V_43 * V_44 = F_18 ( V_68 ) ;
struct V_45 * V_46 ;
T_2 V_55 = F_44 ( V_133 -> V_55 ) ;
F_37 ( V_68 , V_55 ) ;
V_133 -> V_127 = F_45 ( V_133 -> V_127 ) ;
if ( V_133 -> V_126 == V_134 )
V_133 -> V_131 = 0 ;
else
V_133 -> V_131 = F_45 ( V_133 -> V_131 ) ;
V_46 = F_46 ( V_44 , V_55 ) ;
F_5 ( V_46 -> V_93 == NULL ) ;
F_47 ( V_44 -> V_68 , V_46 , V_133 ) ;
if ( V_46 -> V_93 != NULL ) {
F_37 ( V_44 -> V_68 , ( NULL == V_46 -> V_92 ) ) ;
if ( V_46 -> V_92 == NULL ) {
V_46 -> V_93 ( V_46 -> V_92 , V_46 , V_46 -> V_94 ,
V_133 -> V_126 , V_133 -> V_127 ,
V_133 -> V_131 , & V_133 -> V_135 ) ;
F_32 ( V_46 ) ;
} else {
V_46 -> V_96 = V_133 -> V_126 ;
V_46 -> V_127 = V_133 -> V_127 ;
V_46 -> V_131 = V_133 -> V_131 ;
V_46 -> V_129 = V_133 -> V_135 ;
F_33 ( V_68 , & V_46 -> V_97 ,
V_98 , V_46 ) ;
}
} else {
F_37 ( V_68 , ( NULL == V_46 -> V_93 ) ) ;
}
}
static void
F_48 ( struct V_67 * V_68 , T_3 V_136 , struct V_45 * V_46 ,
struct V_38 * V_135 )
{
if ( V_136 > 0 ) {
if ( V_46 -> V_116 ) {
T_3 V_42 =
* ( ( T_3 * ) F_49 ( V_46 ) ) ;
F_11 ( V_68 -> V_13 , V_137 ,
V_138 ,
V_136 + sizeof( struct V_38 ) , V_135 ,
V_42 ) ;
} else {
F_10 ( V_68 -> V_13 , V_137 ,
V_138 ,
V_136 + sizeof( struct V_38 ) ,
V_135 ) ;
}
} else {
F_10 ( V_68 -> V_13 , V_137 , V_138 ,
V_136 + sizeof( struct V_38 ) , V_135 ) ;
}
}
static void
F_47 ( struct V_67 * V_68 , struct V_45 * V_46 ,
struct V_132 * V_133 )
{
if ( V_133 -> V_127 > 0 ) {
if ( V_46 -> V_118 ) {
T_3 V_42 =
* ( ( T_3 * ) F_50 ( V_46 ) ) ;
F_11 ( V_68 -> V_13 , V_137 ,
V_139 ,
( T_2 ) V_133 -> V_127 ,
& V_133 -> V_135 , V_42 ) ;
} else {
F_10 ( V_68 -> V_13 , V_137 ,
V_139 ,
( T_2 ) V_133 -> V_127 ,
& V_133 -> V_135 ) ;
}
} else {
F_10 ( V_68 -> V_13 , V_137 , V_139 ,
( T_2 ) V_133 -> V_127 , & V_133 -> V_135 ) ;
}
}
static void
V_61 ( void * V_125 )
{
struct V_45 * V_46 = V_125 ;
struct V_67 * V_68 = V_46 -> V_54 -> V_68 ;
struct V_140 * V_141 ;
V_46 -> V_62 = V_59 ;
V_141 = F_51 ( V_68 , V_142 ) ;
F_52 ( V_46 , V_141 ) ;
}
static void
F_52 ( struct V_45 * V_46 , struct V_140 * V_141 )
{
struct V_67 * V_68 = V_46 -> V_54 -> V_68 ;
struct V_143 * V_144 = & V_46 -> V_145 ;
struct V_146 * V_147 = & V_46 -> V_148 ;
struct V_149 * V_150 = V_144 -> V_151 ;
F_53 ( V_141 -> V_152 , V_153 , V_154 ,
F_54 ( V_68 ) ) ;
V_141 -> V_55 = F_55 ( V_46 -> V_55 ) ;
if ( V_150 ) {
V_141 -> V_155 = V_150 -> V_156 ;
V_141 -> V_157 = F_55 ( V_150 -> V_158 . V_157 ) ;
if ( V_141 -> V_157 == 0 )
V_141 -> V_157 = F_55 ( V_159 ) ;
} else {
V_141 -> V_155 = 0 ;
V_141 -> V_157 = F_55 ( V_159 ) ;
}
V_141 -> V_160 = F_55 ( V_144 -> V_160 ) ;
V_141 -> V_161 = F_56 ( V_68 , V_144 -> V_162 ) ;
V_141 -> V_163 = V_144 -> V_163 ;
V_141 -> V_164 = V_147 -> V_164 ;
V_141 -> V_165 = V_144 -> V_165 ;
V_141 -> V_135 = V_144 -> V_135 ;
V_141 -> V_166 = F_57 ( V_144 -> V_167 ) ;
V_141 -> V_168 = F_57 ( V_147 -> V_168 ) ;
if ( V_46 -> V_116 == 1 ) {
F_58 ( & V_141 -> V_169 , V_144 -> V_167 ,
F_59 ( V_46 ) ) ;
} else {
if ( V_46 -> V_110 > 0 ) {
F_5 ( V_46 -> V_110 != 1 ) ;
F_58 ( & V_141 -> V_169 , V_144 -> V_167 ,
V_46 -> V_112 ( V_46 -> V_92 , 0 ) ) ;
} else {
F_5 ( V_144 -> V_167 != 0 ) ;
F_58 ( & V_141 -> V_170 , 0 , 0 ) ;
}
}
if ( V_46 -> V_118 == 1 ) {
F_5 ( V_147 -> V_168 > V_82 ) ;
F_58 ( & V_141 -> V_170 , V_147 -> V_168 ,
F_60 ( V_46 ) ) ;
} else {
if ( V_46 -> V_111 > 0 ) {
F_5 ( V_46 -> V_111 != 1 ) ;
F_58 ( & V_141 -> V_170 , V_147 -> V_168 ,
V_46 -> V_114 ( V_46 -> V_92 , 0 ) ) ;
} else {
F_5 ( V_147 -> V_168 != 0 ) ;
F_58 ( & V_141 -> V_170 , 0 , 0 ) ;
}
}
F_48 ( V_68 , V_144 -> V_167 , V_46 , & V_144 -> V_135 ) ;
F_61 ( V_68 , V_142 , V_141 -> V_152 ) ;
F_37 ( V_68 , F_62 ( V_68 , V_142 ) ) ;
F_37 ( V_68 , F_63 ( V_68 , V_142 ) ) ;
}
struct V_45 *
F_64 ( void * V_92 , struct V_67 * V_68 , int V_110 ,
int V_111 , T_5 V_112 ,
T_6 V_113 ,
T_5 V_114 ,
T_6 V_115 , T_4 V_100 )
{
struct V_45 * V_46 = NULL ;
F_5 ( V_68 == NULL ) ;
V_46 = F_34 ( F_18 ( V_68 ) , V_100 ) ;
if ( V_46 == NULL )
return NULL ;
F_37 ( V_68 , V_46 -> V_55 ) ;
F_38 ( V_46 , V_92 , V_68 , V_110 , V_111 , V_112 ,
V_113 , V_114 , V_115 ) ;
return V_46 ;
}
void *
F_65 ( struct V_45 * V_46 )
{
struct V_43 * V_44 = V_46 -> V_54 ;
void * V_171 ;
F_5 ( V_46 -> V_116 != 1 ) ;
V_171 = F_66 ( V_44 , V_46 -> V_55 ,
V_44 -> V_86 + V_44 -> V_87 ) ;
return V_171 ;
}
T_3
F_67 ( struct V_45 * V_46 )
{
struct V_43 * V_44 = V_46 -> V_54 ;
return V_44 -> V_86 ;
}
void *
F_68 ( struct V_45 * V_46 )
{
struct V_43 * V_44 = V_46 -> V_54 ;
void * V_172 ;
F_5 ( V_46 -> V_118 != 1 ) ;
V_172 = F_66 ( V_44 , V_46 -> V_55 ,
V_44 -> V_86 + V_44 -> V_87 ) ;
return ( ( V_37 * ) V_172 ) + V_44 -> V_86 ;
}
void
F_32 ( struct V_45 * V_46 )
{
struct V_43 * V_44 = V_46 -> V_54 ;
F_5 ( V_46 == NULL ) ;
F_37 ( V_44 -> V_68 , V_46 -> V_55 ) ;
F_39 ( V_46 ) ;
}
void
F_69 ( struct V_45 * V_46 , struct V_149 * V_150 ,
T_2 V_160 , V_37 V_162 , T_4 V_165 , enum V_173 cos ,
T_3 V_136 , struct V_38 * V_135 , T_8 V_174 ,
void * V_125 , T_3 V_168 , V_37 V_164 )
{
struct V_67 * V_68 = V_46 -> V_54 -> V_68 ;
struct V_143 * V_144 = & V_46 -> V_145 ;
struct V_146 * V_147 = & V_46 -> V_148 ;
struct V_140 * V_141 ;
F_37 ( V_68 , V_46 -> V_55 ) ;
V_144 -> V_151 = V_150 ;
V_144 -> V_160 = V_160 ;
V_144 -> V_162 = V_162 ;
V_144 -> V_163 = cos ;
V_147 -> V_164 = V_164 ;
V_144 -> V_165 = V_165 ;
V_144 -> V_135 = * V_135 ;
V_144 -> V_167 = V_136 ;
V_147 -> V_168 = V_168 ;
V_46 -> V_93 = V_174 ? V_174 : F_42 ;
V_46 -> V_94 = V_125 ;
V_141 = F_51 ( V_68 , V_142 ) ;
if ( ! V_141 ) {
F_37 ( V_68 , V_46 -> V_55 ) ;
V_46 -> V_62 = V_58 ;
F_70 ( V_68 , V_142 , & V_46 -> V_60 ) ;
return;
}
F_52 ( V_46 , V_141 ) ;
}
T_7
F_71 ( struct V_45 * V_46 )
{
F_37 ( V_46 -> V_54 -> V_68 , V_46 -> V_55 ) ;
F_5 ( 1 ) ;
return V_134 ;
}
void
F_72 ( struct V_67 * V_68 , struct V_120 * V_121 ,
T_9 V_122 , void * V_123 ,
void * V_92 , int V_110 ,
int V_111 , T_5 V_112 ,
T_6 V_113 ,
T_5 V_114 ,
T_6 V_115 , T_4 V_100 )
{
struct V_43 * V_44 = F_18 ( V_68 ) ;
if ( V_100 )
F_5 ( ! F_73 ( & V_44 -> V_48 ) ) ;
else
F_5 ( ! F_73 ( & V_44 -> V_49 ) ) ;
V_121 -> V_122 = V_122 ;
V_121 -> V_123 = V_123 ;
V_121 -> V_92 = V_92 ;
V_121 -> V_68 = V_68 ;
V_121 -> V_110 = V_110 ;
V_121 -> V_111 = V_111 ;
V_121 -> V_112 = V_112 ;
V_121 -> V_113 = V_113 ;
V_121 -> V_114 = V_114 ;
V_121 -> V_115 = V_115 ;
if ( V_100 )
F_15 ( & V_121 -> V_56 , & V_44 -> V_88 ) ;
else
F_15 ( & V_121 -> V_56 , & V_44 -> V_89 ) ;
}
void
F_74 ( struct V_67 * V_68 , struct V_120 * V_121 )
{
struct V_43 * V_44 = F_18 ( V_68 ) ;
F_5 ( ! F_40 ( & V_44 -> V_88 , V_121 ) ||
! F_40 ( & V_44 -> V_89 , V_121 ) ) ;
F_41 ( & V_121 -> V_56 ) ;
}
void
F_75 ( struct V_45 * V_46 )
{
if ( V_46 -> V_62 ) {
V_46 -> V_62 = V_59 ;
F_76 ( & V_46 -> V_60 ) ;
F_32 ( V_46 ) ;
return;
}
V_46 -> V_93 = F_42 ;
}
void
F_77 ( struct V_67 * V_68 , struct V_175 * V_176 )
{
switch ( V_176 -> V_177 . V_178 ) {
case V_179 :
F_43 ( V_68 , (struct V_132 * ) V_176 ) ;
break;
default:
F_37 ( V_68 , V_176 -> V_177 . V_178 ) ;
F_5 ( 1 ) ;
}
}
T_3
F_78 ( struct V_67 * V_68 )
{
struct V_43 * V_44 = F_18 ( V_68 ) ;
return V_44 -> V_87 ;
}
void
F_79 ( struct V_67 * V_68 , T_2 V_180 )
{
struct V_43 * V_44 = F_18 ( V_68 ) ;
struct V_90 * V_56 ;
int V_35 ;
for ( V_35 = 0 ; V_35 < ( V_44 -> V_47 - V_180 ) ; V_35 ++ ) {
if ( V_35 < ( ( V_44 -> V_47 - V_180 ) / 2 ) ) {
F_80 ( & V_44 -> V_48 , & V_56 ) ;
F_15 ( V_56 , & V_44 -> V_51 ) ;
} else {
F_80 ( & V_44 -> V_49 , & V_56 ) ;
F_15 ( V_56 , & V_44 -> V_52 ) ;
}
}
}
static void
F_81 ( struct V_181 * V_182 , enum V_183 V_25 )
{
F_37 ( V_182 -> V_68 , V_182 -> V_184 ) ;
F_37 ( V_182 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_185 :
if ( F_82 ( V_182 -> V_68 , V_182 -> V_186 ) ) {
F_83 ( V_182 , V_187 ) ;
F_70 ( V_182 -> V_68 , V_182 -> V_186 , & V_182 -> V_121 ) ;
} else {
F_83 ( V_182 , V_188 ) ;
F_84 ( V_182 ) ;
}
if ( V_182 -> V_189 )
F_8 ( V_182 -> V_68 -> V_13 , V_190 ,
V_191 , 0 , L_1 ) ;
else
F_8 ( V_182 -> V_68 -> V_13 , V_190 ,
V_191 , 0 , L_2 ) ;
break;
case V_192 :
F_85 ( V_182 ) ;
break;
case V_193 :
F_86 ( V_182 ) ;
break;
case V_194 :
case V_195 :
break;
case V_196 :
break;
case V_197 :
break;
default:
F_87 ( V_182 -> V_68 , V_25 ) ;
}
}
static void
V_188 ( struct V_181 * V_182 , enum V_183 V_25 )
{
F_37 ( V_182 -> V_68 , V_182 -> V_184 ) ;
F_37 ( V_182 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_196 :
if ( V_182 -> V_198 == V_134 ) {
F_83 ( V_182 , V_199 ) ;
if ( V_182 -> V_189 )
F_8 ( V_182 -> V_68 -> V_13 , V_190 ,
V_191 , 0 , L_3 ) ;
else
F_8 ( V_182 -> V_68 -> V_13 , V_190 ,
V_191 , 0 , L_4 ) ;
F_37 ( V_182 -> V_68 , V_182 -> V_200 ) ;
F_37 ( V_182 -> V_68 , V_182 -> V_201 ) ;
if ( ! V_182 -> V_200 && V_182 -> V_201 )
F_88 ( V_182 , V_197 ) ;
} else {
F_83 ( V_182 , F_81 ) ;
if ( V_182 -> V_189 )
F_8 ( V_182 -> V_68 -> V_13 , V_190 ,
V_191 , 0 ,
L_5 ) ;
else
F_8 ( V_182 -> V_68 -> V_13 , V_190 ,
V_191 , 0 ,
L_6 ) ;
}
F_89 ( V_182 ) ;
break;
case V_195 :
case V_193 :
F_83 ( V_182 , F_81 ) ;
break;
case V_197 :
F_37 ( V_182 -> V_68 , V_182 -> V_200 ) ;
F_37 ( V_182 -> V_68 , V_182 -> V_201 ) ;
break;
default:
F_87 ( V_182 -> V_68 , V_25 ) ;
}
}
static void
V_187 ( struct V_181 * V_182 , enum V_183 V_25 )
{
F_37 ( V_182 -> V_68 , V_182 -> V_184 ) ;
F_37 ( V_182 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_202 :
F_83 ( V_182 , V_188 ) ;
F_84 ( V_182 ) ;
break;
case V_195 :
case V_193 :
F_83 ( V_182 , F_81 ) ;
F_76 ( & V_182 -> V_121 ) ;
break;
case V_194 :
break;
default:
F_87 ( V_182 -> V_68 , V_25 ) ;
}
}
static void
V_199 ( struct V_181 * V_182 , enum V_183 V_25 )
{
F_37 ( V_182 -> V_68 , V_182 -> V_184 ) ;
F_37 ( V_182 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_192 :
if ( F_82 ( V_182 -> V_68 , V_182 -> V_186 ) ) {
F_83 ( V_182 , V_203 ) ;
F_70 ( V_182 -> V_68 , V_182 -> V_186 , & V_182 -> V_121 ) ;
} else {
F_83 ( V_182 , V_204 ) ;
F_90 ( V_182 ) ;
}
F_8 ( V_182 -> V_68 -> V_13 , V_190 ,
V_205 , 0 , L_7 ) ;
break;
case V_194 :
F_83 ( V_182 , F_81 ) ;
F_91 ( V_182 ) ;
F_8 ( V_182 -> V_68 -> V_13 , V_190 ,
V_206 , 0 , L_8 ) ;
break;
case V_197 :
if ( F_82 ( V_182 -> V_68 , V_182 -> V_186 ) ) {
F_83 ( V_182 , V_207 ) ;
F_70 ( V_182 -> V_68 , V_182 -> V_186 , & V_182 -> V_121 ) ;
} else
F_92 ( V_182 ) ;
break;
case V_195 :
case V_193 :
F_83 ( V_182 , F_81 ) ;
break;
default:
F_87 ( V_182 -> V_68 , V_25 ) ;
}
}
static void
V_207 ( struct V_181 * V_182 , enum V_183 V_25 )
{
F_37 ( V_182 -> V_68 , V_182 -> V_184 ) ;
F_37 ( V_182 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_202 :
F_83 ( V_182 , V_199 ) ;
F_92 ( V_182 ) ;
break;
case V_192 :
F_83 ( V_182 , V_203 ) ;
F_8 ( V_182 -> V_68 -> V_13 , V_190 ,
V_205 , 0 , L_7 ) ;
break;
case V_194 :
F_83 ( V_182 , F_81 ) ;
F_76 ( & V_182 -> V_121 ) ;
F_91 ( V_182 ) ;
F_8 ( V_182 -> V_68 -> V_13 , V_190 ,
V_206 , 0 , L_8 ) ;
break;
case V_195 :
case V_193 :
F_83 ( V_182 , F_81 ) ;
F_76 ( & V_182 -> V_121 ) ;
break;
default:
F_87 ( V_182 -> V_68 , V_25 ) ;
}
}
static void
V_204 ( struct V_181 * V_182 , enum V_183 V_25 )
{
F_37 ( V_182 -> V_68 , V_182 -> V_184 ) ;
F_37 ( V_182 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_196 :
case V_195 :
F_83 ( V_182 , F_81 ) ;
F_85 ( V_182 ) ;
break;
case V_193 :
F_83 ( V_182 , F_81 ) ;
break;
default:
F_87 ( V_182 -> V_68 , V_25 ) ;
}
}
static void
V_203 ( struct V_181 * V_182 , enum V_183 V_25 )
{
F_37 ( V_182 -> V_68 , V_182 -> V_184 ) ;
F_37 ( V_182 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_202 :
F_83 ( V_182 , V_204 ) ;
F_90 ( V_182 ) ;
break;
case V_195 :
case V_193 :
F_83 ( V_182 , F_81 ) ;
F_76 ( & V_182 -> V_121 ) ;
break;
default:
F_87 ( V_182 -> V_68 , V_25 ) ;
}
}
static void
F_93 ( struct V_63 * V_64 , struct V_65 * V_66 ,
struct V_67 * V_68 )
{
struct V_69 * V_208 = F_94 ( V_68 ) ;
if ( V_64 -> V_79 . V_80 )
F_24 ( V_66 , V_208 ,
sizeof( struct V_181 ) * V_209 ) ;
else
F_24 ( V_66 , V_208 ,
sizeof( struct V_181 ) * V_210 ) ;
}
static void
F_95 ( struct V_67 * V_68 , void * V_83 , struct V_63 * V_64 ,
struct V_84 * V_85 )
{
struct V_211 * V_44 = F_96 ( V_68 ) ;
struct V_181 * V_182 ;
int V_35 ;
V_44 -> V_212 = V_210 ;
if ( V_64 -> V_79 . V_80 )
V_44 -> V_212 = V_209 ;
else
V_44 -> V_212 = V_210 ;
V_44 -> V_213 = V_182 = (struct V_181 * ) F_13 ( V_44 ) ;
F_13 ( V_44 ) += V_44 -> V_212 * sizeof( struct V_181 ) ;
F_14 ( & V_44 -> V_214 ) ;
F_14 ( & V_44 -> V_215 ) ;
F_14 ( & V_44 -> V_216 ) ;
for ( V_35 = 0 ; V_35 < V_44 -> V_212 ; V_35 ++ , V_182 ++ ) {
V_182 -> V_68 = V_68 ;
V_182 -> V_184 = ( V_37 ) V_35 ;
V_182 -> V_186 = V_217 ;
F_16 ( & V_182 -> V_121 , V_218 , V_182 ) ;
F_15 ( & V_182 -> V_56 , & V_44 -> V_214 ) ;
}
}
static void
F_97 ( struct V_67 * V_68 )
{
}
static void
F_98 ( struct V_67 * V_68 )
{
}
static void
F_99 ( struct V_67 * V_68 )
{
}
static void
F_100 ( struct V_67 * V_68 )
{
struct V_211 * V_44 = F_96 ( V_68 ) ;
struct V_181 * V_182 ;
struct V_90 * V_56 , * V_91 ;
F_31 (qe, qen, &mod->lps_active_q) {
V_182 = (struct V_181 * ) V_56 ;
F_88 ( V_182 , V_195 ) ;
}
F_31 (qe, qen, &mod->lps_login_q) {
V_182 = (struct V_181 * ) V_56 ;
F_88 ( V_182 , V_195 ) ;
}
F_30 ( & V_44 -> V_216 , & V_44 -> V_215 ) ;
}
static void
F_101 ( struct V_67 * V_68 , struct V_219 * V_220 )
{
struct V_211 * V_44 = F_96 ( V_68 ) ;
struct V_181 * V_182 ;
F_5 ( V_220 -> V_184 >= V_44 -> V_212 ) ;
V_182 = F_102 ( V_44 , V_220 -> V_184 ) ;
V_182 -> V_198 = V_220 -> V_198 ;
switch ( V_220 -> V_198 ) {
case V_134 :
V_182 -> V_221 = V_220 -> V_221 ;
V_182 -> V_200 = V_220 -> V_222 ;
if ( V_182 -> V_200 )
V_182 -> V_201 = V_220 -> V_201 ;
V_182 -> V_223 = V_220 -> V_223 ;
V_182 -> V_224 = F_44 ( V_220 -> V_225 ) ;
V_182 -> V_226 = V_220 -> V_227 ;
V_182 -> V_228 = V_220 -> V_229 ;
V_182 -> V_230 = V_220 -> V_230 ;
V_182 -> V_231 = V_220 -> V_231 ;
V_182 -> V_232 = V_220 -> V_232 ;
V_182 -> V_233 = V_220 -> V_233 ;
break;
case V_234 :
V_182 -> V_235 = V_220 -> V_235 ;
V_182 -> V_236 = V_220 -> V_236 ;
break;
case V_237 :
V_182 -> V_238 = V_220 -> V_238 ;
break;
case V_239 :
if ( V_220 -> V_238 )
F_103 ( V_182 , V_220 -> V_238 ) ;
break;
default:
break;
}
F_41 ( & V_182 -> V_56 ) ;
F_15 ( & V_182 -> V_56 , & V_44 -> V_215 ) ;
F_88 ( V_182 , V_196 ) ;
}
static void
F_103 ( struct V_181 * V_240 , V_37 V_241 )
{
struct V_67 * V_68 = V_240 -> V_68 ;
struct V_211 * V_44 = F_96 ( V_68 ) ;
struct V_90 * V_56 , * V_242 ;
struct V_181 * V_182 ;
F_37 ( V_68 , V_241 ) ;
V_56 = F_104 ( V_240 ) ;
while ( V_241 && V_56 ) {
V_242 = F_104 ( V_56 ) ;
V_182 = (struct V_181 * ) V_56 ;
F_37 ( V_68 , V_182 -> V_184 ) ;
V_182 -> V_198 = V_240 -> V_198 ;
F_41 ( & V_182 -> V_56 ) ;
F_15 ( & V_182 -> V_56 , & V_44 -> V_215 ) ;
F_88 ( V_182 , V_196 ) ;
V_56 = V_242 ;
V_241 -- ;
}
}
static void
F_105 ( struct V_67 * V_68 , struct V_243 * V_220 )
{
struct V_211 * V_44 = F_96 ( V_68 ) ;
struct V_181 * V_182 ;
F_5 ( V_220 -> V_184 >= V_44 -> V_212 ) ;
V_182 = F_102 ( V_44 , V_220 -> V_184 ) ;
F_88 ( V_182 , V_196 ) ;
}
static void
F_106 ( struct V_67 * V_68 , struct V_244 * V_245 )
{
struct V_211 * V_44 = F_96 ( V_68 ) ;
struct V_181 * V_182 ;
V_182 = F_102 ( V_44 , V_245 -> V_184 ) ;
F_88 ( V_182 , V_194 ) ;
}
static void
V_218 ( void * V_246 )
{
struct V_181 * V_182 = V_246 ;
F_88 ( V_182 , V_202 ) ;
}
static void
F_86 ( struct V_181 * V_182 )
{
struct V_211 * V_44 = F_96 ( V_182 -> V_68 ) ;
V_182 -> V_201 = 0 ;
F_41 ( & V_182 -> V_56 ) ;
F_15 ( & V_182 -> V_56 , & V_44 -> V_214 ) ;
}
static void
F_84 ( struct V_181 * V_182 )
{
struct V_211 * V_44 = F_96 ( V_182 -> V_68 ) ;
struct V_247 * V_248 ;
V_248 = F_51 ( V_182 -> V_68 , V_182 -> V_186 ) ;
F_5 ( ! V_248 ) ;
F_53 ( V_248 -> V_152 , V_249 , V_250 ,
F_54 ( V_182 -> V_68 ) ) ;
V_248 -> V_184 = V_182 -> V_184 ;
V_248 -> V_251 = V_182 -> V_251 ;
V_248 -> V_252 = F_55 ( V_182 -> V_253 ) ;
V_248 -> V_254 = V_182 -> V_254 ;
V_248 -> V_255 = V_182 -> V_255 ;
V_248 -> V_189 = V_182 -> V_189 ;
V_248 -> V_256 = V_182 -> V_256 ;
F_61 ( V_182 -> V_68 , V_182 -> V_186 , V_248 -> V_152 ) ;
F_41 ( & V_182 -> V_56 ) ;
F_15 ( & V_182 -> V_56 , & V_44 -> V_216 ) ;
}
static void
F_90 ( struct V_181 * V_182 )
{
struct V_257 * V_248 ;
V_248 = F_51 ( V_182 -> V_68 , V_182 -> V_186 ) ;
F_5 ( ! V_248 ) ;
F_53 ( V_248 -> V_152 , V_249 , V_258 ,
F_54 ( V_182 -> V_68 ) ) ;
V_248 -> V_221 = V_182 -> V_221 ;
V_248 -> V_227 = V_182 -> V_254 ;
F_61 ( V_182 -> V_68 , V_182 -> V_186 , V_248 -> V_152 ) ;
}
static void
F_92 ( struct V_181 * V_182 )
{
struct V_259 * V_248 ;
V_248 = F_51 ( V_182 -> V_68 , V_182 -> V_186 ) ;
F_5 ( ! V_248 ) ;
F_53 ( V_248 -> V_152 , V_249 , V_260 ,
F_54 ( V_182 -> V_68 ) ) ;
V_248 -> V_221 = V_182 -> V_221 ;
V_248 -> V_201 = V_182 -> V_201 ;
F_61 ( V_182 -> V_68 , V_182 -> V_186 , V_248 -> V_152 ) ;
}
static void
F_107 ( void * V_261 , T_4 V_130 )
{
struct V_181 * V_182 = V_261 ;
if ( ! V_130 )
return;
if ( V_182 -> V_189 )
F_108 ( V_182 -> V_68 -> V_83 , V_182 -> V_262 , V_182 -> V_198 ) ;
else
F_109 ( V_182 -> V_68 -> V_83 , V_182 -> V_262 , V_182 -> V_198 ) ;
}
static void
F_89 ( struct V_181 * V_182 )
{
if ( ! V_182 -> V_68 -> V_263 ) {
F_33 ( V_182 -> V_68 , & V_182 -> V_97 , F_107 ,
V_182 ) ;
return;
}
if ( V_182 -> V_189 )
F_108 ( V_182 -> V_68 -> V_83 , V_182 -> V_262 , V_182 -> V_198 ) ;
else
F_109 ( V_182 -> V_68 -> V_83 , V_182 -> V_262 , V_182 -> V_198 ) ;
}
static void
F_110 ( void * V_261 , T_4 V_130 )
{
struct V_181 * V_182 = V_261 ;
if ( ! V_130 )
return;
if ( V_182 -> V_189 )
F_111 ( V_182 -> V_68 -> V_83 , V_182 -> V_262 ) ;
else
F_112 ( V_182 -> V_68 -> V_83 , V_182 -> V_262 ) ;
}
static void
F_85 ( struct V_181 * V_182 )
{
if ( ! V_182 -> V_68 -> V_263 ) {
F_33 ( V_182 -> V_68 , & V_182 -> V_97 , F_110 ,
V_182 ) ;
return;
}
if ( V_182 -> V_189 )
F_111 ( V_182 -> V_68 -> V_83 , V_182 -> V_262 ) ;
}
static void
F_113 ( void * V_261 , T_4 V_130 )
{
struct V_181 * V_182 = V_261 ;
if ( ! V_130 )
return;
if ( V_182 -> V_189 )
F_114 ( V_182 -> V_68 -> V_83 , V_182 -> V_262 ) ;
}
static void
F_91 ( struct V_181 * V_182 )
{
if ( ! V_182 -> V_68 -> V_263 ) {
F_33 ( V_182 -> V_68 , & V_182 -> V_97 , F_113 ,
V_182 ) ;
return;
}
if ( V_182 -> V_189 )
F_114 ( V_182 -> V_68 -> V_83 , V_182 -> V_262 ) ;
}
T_3
F_115 ( struct V_67 * V_68 )
{
if ( F_116 ( & V_68 -> V_264 ) == V_265 )
return V_266 ;
else
return V_267 ;
}
struct V_181 *
F_117 ( struct V_67 * V_68 )
{
struct V_211 * V_44 = F_96 ( V_68 ) ;
struct V_181 * V_182 = NULL ;
F_35 ( & V_44 -> V_214 , & V_182 ) ;
if ( V_182 == NULL )
return NULL ;
F_15 ( & V_182 -> V_56 , & V_44 -> V_215 ) ;
F_83 ( V_182 , F_81 ) ;
return V_182 ;
}
void
F_118 ( struct V_181 * V_182 )
{
F_88 ( V_182 , V_193 ) ;
}
void
F_119 ( struct V_181 * V_182 , void * V_262 , V_37 V_251 , T_2 V_253 ,
T_10 V_254 , T_10 V_255 , T_4 V_256 )
{
V_182 -> V_262 = V_262 ;
V_182 -> V_251 = V_251 ;
V_182 -> V_253 = V_253 ;
V_182 -> V_254 = V_254 ;
V_182 -> V_255 = V_255 ;
V_182 -> V_189 = V_59 ;
V_182 -> V_256 = V_256 ;
F_88 ( V_182 , V_185 ) ;
}
void
F_120 ( struct V_181 * V_182 , void * V_262 , T_2 V_253 , T_10 V_254 ,
T_10 V_255 )
{
V_182 -> V_262 = V_262 ;
V_182 -> V_251 = 0 ;
V_182 -> V_253 = V_253 ;
V_182 -> V_254 = V_254 ;
V_182 -> V_255 = V_255 ;
V_182 -> V_189 = V_58 ;
V_182 -> V_256 = V_59 ;
F_88 ( V_182 , V_185 ) ;
}
void
F_121 ( struct V_181 * V_182 )
{
F_88 ( V_182 , V_192 ) ;
}
V_37
F_56 ( struct V_67 * V_68 , V_37 V_162 )
{
struct V_211 * V_44 = F_96 ( V_68 ) ;
return F_102 ( V_44 , V_162 ) -> V_221 ;
}
V_37
F_122 ( struct V_67 * V_68 , T_3 V_268 )
{
struct V_211 * V_44 = F_96 ( V_68 ) ;
struct V_181 * V_182 ;
int V_35 ;
for ( V_35 = 0 , V_182 = V_44 -> V_213 ; V_35 < V_44 -> V_212 ; V_35 ++ , V_182 ++ ) {
if ( V_182 -> V_201 == V_268 )
return V_182 -> V_184 ;
}
return 0 ;
}
T_3
F_123 ( struct V_67 * V_68 )
{
struct V_211 * V_44 = F_96 ( V_68 ) ;
return F_102 ( V_44 , 0 ) -> V_201 ;
}
void
F_124 ( struct V_181 * V_182 , T_11 V_269 )
{
F_37 ( V_182 -> V_68 , V_182 -> V_184 ) ;
F_37 ( V_182 -> V_68 , V_269 ) ;
V_182 -> V_201 = V_269 ;
F_88 ( V_182 , V_197 ) ;
}
void
F_125 ( struct V_67 * V_68 , struct V_175 * V_248 )
{
union V_270 V_176 ;
F_37 ( V_68 , V_248 -> V_177 . V_178 ) ;
V_176 . V_176 = V_248 ;
switch ( V_248 -> V_177 . V_178 ) {
case V_271 :
F_101 ( V_68 , V_176 . V_272 ) ;
break;
case V_273 :
F_105 ( V_68 , V_176 . V_274 ) ;
break;
case V_275 :
F_106 ( V_68 , V_176 . V_276 ) ;
break;
default:
F_37 ( V_68 , V_248 -> V_177 . V_178 ) ;
F_5 ( 1 ) ;
}
}
static void
F_126 ( struct V_277 * V_278 , enum V_279 V_25 )
{
struct V_280 * V_83 = (struct V_280 * ) V_278 -> V_68 -> V_83 ;
struct V_281 * V_282 ;
F_127 ( V_83 , V_282 ) ;
if ( ! V_282 )
return;
V_282 -> V_283 . V_284 . V_285 = F_128 ( V_278 -> V_68 ) ;
V_282 -> V_283 . V_284 . V_254 = V_278 -> V_254 ;
F_129 ( V_282 , V_83 , ++ V_278 -> V_68 -> V_286 ,
V_287 , V_25 ) ;
}
static void
F_130 ( struct V_277 * V_278 ,
enum V_288 V_25 )
{
F_37 ( V_278 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_289 :
V_278 -> V_290 = V_58 ;
if ( F_131 ( V_278 ) ) {
F_37 ( V_278 -> V_68 , V_58 ) ;
F_83 ( V_278 , V_291 ) ;
} else {
F_37 ( V_278 -> V_68 , V_59 ) ;
F_83 ( V_278 ,
V_292 ) ;
}
break;
case V_293 :
break;
case V_294 :
F_83 ( V_278 , V_295 ) ;
break;
case V_296 :
F_83 ( V_278 , V_297 ) ;
break;
default:
F_87 ( V_278 -> V_68 , V_25 ) ;
}
}
static void
V_292 ( struct V_277 * V_278 ,
enum V_288 V_25 )
{
char V_298 [ V_299 ] ;
struct V_280 * V_83 = (struct V_280 * ) V_278 -> V_68 -> V_83 ;
F_37 ( V_278 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_300 :
F_83 ( V_278 , V_291 ) ;
F_131 ( V_278 ) ;
break;
case V_301 :
F_76 ( & V_278 -> V_302 ) ;
F_83 ( V_278 , V_303 ) ;
break;
case V_293 :
break;
case V_294 :
F_83 ( V_278 , V_295 ) ;
F_76 ( & V_278 -> V_302 ) ;
F_8 ( V_278 -> V_68 -> V_13 , V_304 ,
V_305 , 0 , L_9 ) ;
F_132 ( V_298 , V_278 -> V_254 ) ;
F_133 ( V_306 , V_83 , V_307 ,
L_10 , V_298 ) ;
F_126 ( V_278 , V_308 ) ;
break;
case V_309 :
case V_310 :
break;
case V_296 :
F_76 ( & V_278 -> V_302 ) ;
F_83 ( V_278 , V_297 ) ;
break;
case V_311 :
F_134 ( V_278 ) ;
F_126 ( V_278 , V_312 ) ;
F_83 ( V_278 , V_313 ) ;
break;
default:
F_87 ( V_278 -> V_68 , V_25 ) ;
}
}
static void
V_291 ( struct V_277 * V_278 ,
enum V_288 V_25 )
{
char V_298 [ V_299 ] ;
struct V_280 * V_83 = (struct V_280 * ) V_278 -> V_68 -> V_83 ;
F_37 ( V_278 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_314 :
case V_310 :
F_83 ( V_278 , V_315 ) ;
break;
case V_309 :
F_135 ( V_278 ) ;
F_83 ( V_278 , V_316 ) ;
F_5 ( ! V_278 -> V_317 ) ;
F_136 ( V_278 , V_318 , V_59 ) ;
break;
case V_293 :
break;
case V_294 :
if ( F_137 ( V_278 ) )
F_83 ( V_278 , V_319 ) ;
else
F_83 ( V_278 ,
V_320 ) ;
F_8 ( V_278 -> V_68 -> V_13 , V_304 ,
V_305 , 0 , L_9 ) ;
F_132 ( V_298 , V_278 -> V_254 ) ;
F_133 ( V_306 , V_83 , V_307 ,
L_10 , V_298 ) ;
F_126 ( V_278 , V_308 ) ;
break;
case V_301 :
F_83 ( V_278 , V_303 ) ;
break;
case V_296 :
F_83 ( V_278 , V_297 ) ;
break;
case V_311 :
F_134 ( V_278 ) ;
F_126 ( V_278 , V_312 ) ;
F_83 ( V_278 , V_313 ) ;
break;
default:
F_87 ( V_278 -> V_68 , V_25 ) ;
}
}
static void
V_315 ( struct V_277 * V_278 ,
enum V_288 V_25 )
{
struct V_321 * V_322 = V_278 -> V_323 . V_324 . V_25 ;
char V_298 [ V_299 ] ;
struct V_280 * V_83 = (struct V_280 * ) V_278 -> V_68 -> V_83 ;
F_37 ( V_278 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_309 :
F_135 ( V_278 ) ;
F_83 ( V_278 , V_316 ) ;
F_5 ( ! V_278 -> V_317 ) ;
F_8 ( V_278 -> V_68 -> V_13 , V_304 ,
V_325 , 0 , L_11 ) ;
if ( ! F_138 ( & V_278 -> V_68 -> V_264 ) ) {
F_37 ( V_278 -> V_68 ,
V_322 -> V_326 . V_327 . V_328 . V_329 . V_330 ) ;
F_37 ( V_278 -> V_68 ,
V_322 -> V_326 . V_327 . V_328 . V_329 . V_331 ) ;
if ( V_322 -> V_326 . V_327 . V_328 . V_329 . V_331 )
F_8 ( V_278 -> V_68 -> V_13 , V_304 ,
V_332 , 0 ,
L_12 ) ;
else
F_8 ( V_278 -> V_68 -> V_13 , V_304 ,
V_332 , 0 ,
L_13 ) ;
}
F_136 ( V_278 , V_318 , V_59 ) ;
F_132 ( V_298 , V_278 -> V_254 ) ;
F_133 ( V_306 , V_83 , V_307 ,
L_14 , V_298 ) ;
F_126 ( V_278 , V_333 ) ;
if ( V_278 -> V_64 . V_334 &&
V_278 -> V_335 . V_336 != V_337 )
F_126 ( V_278 , V_338 ) ;
break;
case V_310 :
break;
case V_293 :
break;
case V_294 :
if ( F_137 ( V_278 ) )
F_83 ( V_278 , V_319 ) ;
else
F_83 ( V_278 ,
V_320 ) ;
F_8 ( V_278 -> V_68 -> V_13 , V_304 ,
V_305 , 0 , L_9 ) ;
F_132 ( V_298 , V_278 -> V_254 ) ;
F_133 ( V_306 , V_83 , V_307 ,
L_10 , V_298 ) ;
F_126 ( V_278 , V_308 ) ;
break;
case V_301 :
F_83 ( V_278 , V_303 ) ;
break;
case V_296 :
F_83 ( V_278 , V_297 ) ;
break;
case V_311 :
F_134 ( V_278 ) ;
F_126 ( V_278 , V_312 ) ;
F_83 ( V_278 , V_313 ) ;
break;
default:
F_87 ( V_278 -> V_68 , V_25 ) ;
}
}
static void
V_316 ( struct V_277 * V_278 ,
enum V_288 V_25 )
{
char V_298 [ V_299 ] ;
struct V_280 * V_83 = (struct V_280 * ) V_278 -> V_68 -> V_83 ;
F_37 ( V_278 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_293 :
break;
case V_294 :
if ( F_137 ( V_278 ) )
F_83 ( V_278 , V_319 ) ;
else
F_83 ( V_278 ,
V_320 ) ;
F_134 ( V_278 ) ;
F_136 ( V_278 , V_339 , V_59 ) ;
F_8 ( V_278 -> V_68 -> V_13 , V_304 ,
V_305 , 0 , L_9 ) ;
F_132 ( V_298 , V_278 -> V_254 ) ;
F_133 ( V_306 , V_83 , V_307 ,
L_15 , V_298 ) ;
F_126 ( V_278 , V_340 ) ;
F_133 ( V_306 , V_83 , V_307 ,
L_10 , V_298 ) ;
F_126 ( V_278 , V_308 ) ;
break;
case V_310 :
F_83 ( V_278 , V_315 ) ;
F_134 ( V_278 ) ;
F_136 ( V_278 , V_339 , V_59 ) ;
F_8 ( V_278 -> V_68 -> V_13 , V_304 ,
V_325 , 0 , L_16 ) ;
F_132 ( V_298 , V_278 -> V_254 ) ;
if ( F_139 ( V_278 -> V_68 ) ) {
F_133 ( V_306 , V_83 , V_307 ,
L_15 , V_298 ) ;
F_126 ( V_278 , V_340 ) ;
} else {
F_133 ( V_341 , V_83 , V_307 ,
L_17
L_18 , V_298 ) ;
F_126 ( V_278 , V_312 ) ;
}
break;
case V_301 :
F_83 ( V_278 , V_303 ) ;
F_134 ( V_278 ) ;
F_132 ( V_298 , V_278 -> V_254 ) ;
if ( F_139 ( V_278 -> V_68 ) ) {
F_133 ( V_306 , V_83 , V_307 ,
L_15 , V_298 ) ;
F_126 ( V_278 , V_340 ) ;
} else {
F_133 ( V_341 , V_83 , V_307 ,
L_17
L_18 , V_298 ) ;
F_126 ( V_278 , V_312 ) ;
}
break;
case V_296 :
F_83 ( V_278 , V_297 ) ;
F_134 ( V_278 ) ;
F_136 ( V_278 , V_339 , V_59 ) ;
F_132 ( V_298 , V_278 -> V_254 ) ;
if ( F_139 ( V_278 -> V_68 ) ) {
F_133 ( V_306 , V_83 , V_307 ,
L_15 , V_298 ) ;
F_126 ( V_278 , V_340 ) ;
} else {
F_133 ( V_341 , V_83 , V_307 ,
L_17
L_18 , V_298 ) ;
F_126 ( V_278 , V_312 ) ;
}
break;
case V_311 :
F_134 ( V_278 ) ;
F_126 ( V_278 , V_312 ) ;
F_83 ( V_278 , V_313 ) ;
break;
default:
F_87 ( V_278 -> V_68 , V_25 ) ;
}
}
static void
V_320 ( struct V_277 * V_278 ,
enum V_288 V_25 )
{
F_37 ( V_278 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_300 :
F_83 ( V_278 , V_319 ) ;
F_137 ( V_278 ) ;
break;
case V_301 :
F_83 ( V_278 , V_303 ) ;
F_76 ( & V_278 -> V_302 ) ;
break;
case V_293 :
F_83 ( V_278 , V_342 ) ;
break;
case V_294 :
break;
case V_309 :
case V_310 :
break;
case V_296 :
F_83 ( V_278 , V_343 ) ;
F_76 ( & V_278 -> V_302 ) ;
break;
case V_311 :
F_134 ( V_278 ) ;
F_126 ( V_278 , V_312 ) ;
F_83 ( V_278 , V_313 ) ;
break;
default:
F_87 ( V_278 -> V_68 , V_25 ) ;
}
}
static void
V_342 ( struct V_277 * V_278 ,
enum V_288 V_25 )
{
F_37 ( V_278 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_300 :
F_83 ( V_278 , V_319 ) ;
F_137 ( V_278 ) ;
if ( F_131 ( V_278 ) )
F_83 ( V_278 , V_291 ) ;
else
F_83 ( V_278 ,
V_292 ) ;
break;
case V_301 :
F_83 ( V_278 , V_303 ) ;
F_76 ( & V_278 -> V_302 ) ;
break;
case V_293 :
break;
case V_294 :
F_83 ( V_278 , V_320 ) ;
break;
case V_309 :
case V_310 :
break;
case V_296 :
F_83 ( V_278 , V_343 ) ;
F_76 ( & V_278 -> V_302 ) ;
break;
default:
F_87 ( V_278 -> V_68 , V_25 ) ;
}
}
static void
V_319 ( struct V_277 * V_278 ,
enum V_288 V_25 )
{
char V_298 [ V_299 ] ;
struct V_280 * V_83 = (struct V_280 * ) V_278 -> V_68 -> V_83 ;
F_37 ( V_278 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_314 :
F_83 ( V_278 , V_295 ) ;
break;
case V_294 :
break;
case V_293 :
if ( F_131 ( V_278 ) )
F_83 ( V_278 , V_291 ) ;
else
F_83 ( V_278 ,
V_292 ) ;
F_8 ( V_278 -> V_68 -> V_13 , V_304 ,
V_344 , 0 , L_19 ) ;
F_132 ( V_298 , V_278 -> V_254 ) ;
F_133 ( V_306 , V_83 , V_307 ,
L_20 , V_298 ) ;
F_126 ( V_278 , V_345 ) ;
break;
case V_301 :
F_83 ( V_278 , V_303 ) ;
break;
case V_309 :
case V_310 :
break;
case V_296 :
F_83 ( V_278 , V_343 ) ;
break;
default:
F_87 ( V_278 -> V_68 , V_25 ) ;
}
}
static void
V_295 ( struct V_277 * V_278 ,
enum V_288 V_25 )
{
char V_298 [ V_299 ] ;
struct V_280 * V_83 = (struct V_280 * ) V_278 -> V_68 -> V_83 ;
F_37 ( V_278 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_289 :
break;
case V_301 :
F_83 ( V_278 , V_303 ) ;
break;
case V_293 :
if ( F_131 ( V_278 ) )
F_83 ( V_278 , V_291 ) ;
else
F_83 ( V_278 ,
V_292 ) ;
F_8 ( V_278 -> V_68 -> V_13 , V_304 ,
V_344 , 0 , L_19 ) ;
F_132 ( V_298 , V_278 -> V_254 ) ;
F_133 ( V_306 , V_83 , V_307 ,
L_20 , V_298 ) ;
F_126 ( V_278 , V_345 ) ;
break;
case V_294 :
break;
case V_296 :
F_83 ( V_278 , V_343 ) ;
break;
case V_346 :
F_83 ( V_278 , V_347 ) ;
break;
case V_348 :
F_83 ( V_278 , V_349 ) ;
break;
default:
F_87 ( V_278 -> V_68 , V_25 ) ;
}
}
static void
V_303 ( struct V_277 * V_278 ,
enum V_288 V_25 )
{
F_37 ( V_278 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_289 :
if ( F_131 ( V_278 ) )
F_83 ( V_278 , V_291 ) ;
else
F_83 ( V_278 ,
V_292 ) ;
break;
default:
;
}
}
static void
V_297 ( struct V_277 * V_278 ,
enum V_288 V_25 )
{
F_37 ( V_278 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_289 :
if ( F_131 ( V_278 ) )
F_83 ( V_278 , V_291 ) ;
else
F_83 ( V_278 ,
V_292 ) ;
break;
default:
;
}
}
static void
V_343 ( struct V_277 * V_278 ,
enum V_288 V_25 )
{
F_37 ( V_278 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_289 :
F_83 ( V_278 , V_295 ) ;
break;
case V_293 :
F_83 ( V_278 , V_297 ) ;
break;
default:
;
}
}
static void
V_347 ( struct V_277 * V_278 , enum V_288 V_25 )
{
F_37 ( V_278 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_346 :
case V_294 :
case V_293 :
case V_289 :
break;
case V_301 :
F_83 ( V_278 , V_303 ) ;
break;
case V_296 :
F_83 ( V_278 , V_343 ) ;
break;
case V_350 :
F_83 ( V_278 , V_295 ) ;
break;
default:
F_87 ( V_278 -> V_68 , V_25 ) ;
}
}
static void
V_349 ( struct V_277 * V_278 ,
enum V_288 V_25 )
{
F_37 ( V_278 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_294 :
case V_351 :
F_83 ( V_278 , V_295 ) ;
break;
case V_346 :
case V_350 :
case V_293 :
case V_289 :
break;
case V_301 :
F_83 ( V_278 , V_303 ) ;
break;
case V_296 :
F_83 ( V_278 , V_343 ) ;
break;
default:
F_87 ( V_278 -> V_68 , V_25 ) ;
}
}
static void
V_313 ( struct V_277 * V_278 ,
enum V_288 V_25 )
{
F_37 ( V_278 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_346 :
case V_293 :
case V_289 :
break;
case V_294 :
if ( F_137 ( V_278 ) )
F_83 ( V_278 , V_319 ) ;
else
F_83 ( V_278 , V_320 ) ;
F_134 ( V_278 ) ;
F_136 ( V_278 , V_339 , V_59 ) ;
F_8 ( V_278 -> V_68 -> V_13 , V_304 ,
V_305 , 0 , L_9 ) ;
F_126 ( V_278 , V_308 ) ;
break;
case V_301 :
F_83 ( V_278 , V_303 ) ;
break;
case V_296 :
F_134 ( V_278 ) ;
F_136 ( V_278 , V_339 , V_59 ) ;
F_83 ( V_278 , V_297 ) ;
break;
default:
F_87 ( V_278 -> V_68 , V_25 ) ;
}
}
static void
F_140 ( struct V_352 * V_353 ,
enum V_354 V_25 )
{
F_37 ( V_353 -> V_278 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_355 :
F_83 ( V_353 , V_356 ) ;
F_141 ( V_353 , V_318 ) ;
break;
default:
F_87 ( V_353 -> V_278 -> V_68 , V_25 ) ;
}
}
static void
F_142 ( struct V_352 * V_353 ,
enum V_354 V_25 )
{
F_37 ( V_353 -> V_278 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_355 :
F_83 ( V_353 , V_357 ) ;
break;
case V_358 :
F_83 ( V_353 , F_140 ) ;
break;
default:
F_87 ( V_353 -> V_278 -> V_68 , V_25 ) ;
}
}
static void
V_357 ( struct V_352 * V_353 ,
enum V_354 V_25 )
{
F_37 ( V_353 -> V_278 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_359 :
F_83 ( V_353 , F_142 ) ;
break;
case V_358 :
F_83 ( V_353 , V_356 ) ;
F_141 ( V_353 , V_318 ) ;
break;
default:
F_87 ( V_353 -> V_278 -> V_68 , V_25 ) ;
}
}
static void
F_143 ( struct V_352 * V_353 ,
enum V_354 V_25 )
{
F_37 ( V_353 -> V_278 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_359 :
F_83 ( V_353 , F_142 ) ;
F_141 ( V_353 , V_339 ) ;
break;
default:
F_87 ( V_353 -> V_278 -> V_68 , V_25 ) ;
}
}
static void
V_356 ( struct V_352 * V_353 ,
enum V_354 V_25 )
{
F_37 ( V_353 -> V_278 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_359 :
F_83 ( V_353 , V_360 ) ;
break;
case V_358 :
F_83 ( V_353 , F_143 ) ;
break;
default:
F_87 ( V_353 -> V_278 -> V_68 , V_25 ) ;
}
}
static void
V_360 ( struct V_352 * V_353 ,
enum V_354 V_25 )
{
F_37 ( V_353 -> V_278 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_355 :
F_83 ( V_353 , V_361 ) ;
break;
case V_358 :
F_83 ( V_353 , F_142 ) ;
F_141 ( V_353 , V_339 ) ;
break;
default:
F_87 ( V_353 -> V_278 -> V_68 , V_25 ) ;
}
}
static void
V_361 ( struct V_352 * V_353 ,
enum V_354 V_25 )
{
F_37 ( V_353 -> V_278 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_359 :
F_83 ( V_353 , V_360 ) ;
break;
case V_358 :
F_83 ( V_353 , V_357 ) ;
F_141 ( V_353 , V_339 ) ;
break;
default:
F_87 ( V_353 -> V_278 -> V_68 , V_25 ) ;
}
}
static void
F_144 ( void * V_125 , T_4 V_130 )
{
struct V_352 * V_353 = V_125 ;
if ( V_130 )
V_353 -> V_278 -> V_317 ( V_353 -> V_278 -> V_362 , V_353 -> V_363 ) ;
else
F_88 ( V_353 , V_358 ) ;
}
static void
F_136 ( struct V_277 * V_278 , enum V_364 V_25 ,
T_4 V_365 )
{
if ( V_278 -> V_64 . V_366 && ! V_365 )
return;
switch ( V_25 ) {
case V_318 :
F_88 ( & V_278 -> V_353 , V_355 ) ;
break;
case V_339 :
F_88 ( & V_278 -> V_353 , V_359 ) ;
break;
default:
F_5 ( 1 ) ;
}
}
static void
F_141 ( struct V_352 * V_353 , enum V_364 V_25 )
{
struct V_277 * V_278 = V_353 -> V_278 ;
if ( V_278 -> V_68 -> V_263 ) {
V_278 -> V_317 ( V_278 -> V_362 , V_25 ) ;
F_88 ( V_353 , V_358 ) ;
} else {
V_353 -> V_363 = V_25 ;
F_33 ( V_278 -> V_68 , & V_353 -> V_367 ,
F_144 , V_353 ) ;
}
}
static void
F_145 ( struct V_63 * V_64 , struct V_65 * V_66 ,
struct V_67 * V_68 )
{
struct V_71 * V_368 = F_146 ( V_68 ) ;
F_23 ( V_66 , V_368 , V_369 ) ;
}
static void
F_147 ( void * V_125 )
{
struct V_277 * V_278 = V_125 ;
F_88 ( V_278 , V_300 ) ;
}
static void
F_148 ( struct V_277 * V_278 )
{
struct V_71 * V_368 = & V_278 -> V_368 ;
V_278 -> V_370 = F_149 ( V_368 ) ;
V_278 -> V_371 = F_150 ( V_368 ) ;
V_278 -> V_372 = (union V_373 * )
F_149 ( V_368 ) ;
}
static void
F_151 ( struct V_67 * V_68 , void * V_83 , struct V_63 * V_64 ,
struct V_84 * V_85 )
{
struct V_277 * V_278 = F_152 ( V_68 ) ;
struct V_374 * V_375 = & V_278 -> V_64 ;
struct V_352 * V_353 = & V_278 -> V_353 ;
struct V_9 V_10 ;
V_278 -> V_68 = V_68 ;
V_353 -> V_278 = V_278 ;
F_148 ( V_278 ) ;
F_83 ( V_278 , F_130 ) ;
F_83 ( V_353 , F_140 ) ;
F_3 ( & V_10 ) ;
V_278 -> V_376 = V_10 . V_11 ;
V_278 -> V_377 = V_59 ;
V_375 -> V_378 = V_379 ;
V_375 -> V_380 = V_381 ;
V_375 -> V_366 = V_59 ;
V_375 -> V_382 = 0 ;
V_375 -> V_383 = V_384 ;
V_375 -> V_385 . V_386 = V_387 ;
V_375 -> V_385 . V_388 = V_389 ;
V_375 -> V_385 . V_390 = V_391 ;
V_278 -> V_392 = V_393 ;
F_14 ( & V_278 -> V_394 ) ;
F_14 ( & V_278 -> V_395 ) ;
F_16 ( & V_278 -> V_302 , F_147 , V_278 ) ;
}
static void
F_153 ( struct V_67 * V_68 )
{
}
static void
F_154 ( struct V_67 * V_68 )
{
F_88 ( F_152 ( V_68 ) , V_289 ) ;
}
static void
F_155 ( struct V_67 * V_68 )
{
F_88 ( F_152 ( V_68 ) , V_301 ) ;
F_156 ( V_68 ) ;
}
static void
F_157 ( struct V_67 * V_68 )
{
struct V_277 * V_278 = F_152 ( V_68 ) ;
F_88 ( V_278 , V_296 ) ;
F_156 ( V_68 ) ;
}
static void
F_158 ( struct V_277 * V_278 ,
struct V_396 * V_397 )
{
V_278 -> V_398 = V_397 -> V_398 ;
V_278 -> V_399 =
V_397 -> V_400 ;
memcpy ( V_278 -> V_401 . V_402 ,
V_397 -> V_401 . V_402 ,
sizeof( struct V_403 ) ) ;
}
static void
F_135 ( struct V_277 * V_278 )
{
struct V_321 * V_322 = V_278 -> V_323 . V_324 . V_25 ;
struct V_404 * V_365 = & V_278 -> V_365 ;
V_278 -> V_380 = V_322 -> V_326 . V_380 ;
V_278 -> V_378 = V_322 -> V_326 . V_378 ;
if ( V_278 -> V_378 == V_405 ) {
F_158 ( V_278 ,
& V_322 -> V_326 . V_327 . V_397 ) ;
return;
}
V_278 -> V_335 = V_322 -> V_326 . V_335 ;
V_278 -> V_406 = V_322 -> V_326 . V_327 . V_328 . V_406 ;
if ( V_278 -> V_64 . V_407 )
V_278 -> V_408 = V_322 -> V_326 . V_327 . V_408 ;
V_278 -> V_392 = V_322 -> V_326 . V_392 ;
if ( ! V_278 -> V_64 . V_366 )
V_365 -> V_327 . V_336 = V_409 ;
V_278 -> V_410 =
F_44 ( V_322 -> V_326 . V_327 . V_328 . V_329 . V_411 ) ;
F_37 ( V_278 -> V_68 , V_278 -> V_380 ) ;
F_37 ( V_278 -> V_68 , V_278 -> V_378 ) ;
}
static void
F_134 ( struct V_277 * V_278 )
{
V_278 -> V_380 = V_412 ;
V_278 -> V_378 = V_413 ;
V_278 -> V_392 = V_393 ;
}
static T_4
F_131 ( struct V_277 * V_278 )
{
struct V_414 * V_248 ;
V_278 -> V_415 ++ ;
V_248 = F_51 ( V_278 -> V_68 , V_416 ) ;
if ( ! V_248 ) {
F_70 ( V_278 -> V_68 , V_416 ,
& V_278 -> V_302 ) ;
return V_59 ;
}
F_53 ( V_248 -> V_152 , V_417 , V_418 ,
F_54 ( V_278 -> V_68 ) ) ;
V_248 -> V_255 = V_278 -> V_255 ;
V_248 -> V_254 = V_278 -> V_254 ;
V_248 -> V_375 = V_278 -> V_64 ;
V_248 -> V_415 = V_278 -> V_415 ;
V_248 -> V_375 . V_382 = F_55 ( V_278 -> V_64 . V_382 ) ;
V_248 -> V_290 = V_278 -> V_290 ;
F_159 ( V_248 -> V_419 , V_278 -> V_371 ) ;
F_37 ( V_278 -> V_68 , V_248 -> V_419 . V_420 . V_421 ) ;
F_37 ( V_278 -> V_68 , V_248 -> V_419 . V_420 . V_422 ) ;
F_61 ( V_278 -> V_68 , V_416 , V_248 -> V_152 ) ;
return V_58 ;
}
static T_4
F_137 ( struct V_277 * V_278 )
{
struct V_423 * V_248 ;
V_278 -> V_415 ++ ;
V_248 = F_51 ( V_278 -> V_68 , V_416 ) ;
if ( ! V_248 ) {
F_70 ( V_278 -> V_68 , V_416 ,
& V_278 -> V_302 ) ;
return V_59 ;
}
F_53 ( V_248 -> V_152 , V_417 , V_424 ,
F_54 ( V_278 -> V_68 ) ) ;
V_248 -> V_415 = V_278 -> V_415 ;
F_61 ( V_278 -> V_68 , V_416 , V_248 -> V_152 ) ;
return V_58 ;
}
static void
F_160 ( struct V_277 * V_278 )
{
V_278 -> V_254 = V_278 -> V_68 -> V_264 . V_327 -> V_254 ;
V_278 -> V_255 = V_278 -> V_68 -> V_264 . V_327 -> V_255 ;
F_37 ( V_278 -> V_68 , V_278 -> V_254 ) ;
F_37 ( V_278 -> V_68 , V_278 -> V_255 ) ;
}
static void
F_161 ( struct V_425 * V_426 ,
struct V_425 * V_427 )
{
T_3 * V_428 = ( T_3 * ) V_426 ;
T_12 * V_429 = ( T_12 * ) V_427 ;
int V_35 ;
for ( V_35 = 0 ; V_35 < ( sizeof( struct V_425 ) / sizeof( T_3 ) ) ; ++ V_35 )
V_428 [ V_35 ] = F_45 ( V_429 [ V_35 ] ) ;
}
static void
F_162 ( struct V_430 * V_426 ,
struct V_430 * V_427 )
{
T_3 * V_428 = ( T_3 * ) V_426 ;
T_12 * V_429 = ( T_12 * ) V_427 ;
int V_35 ;
for ( V_35 = 0 ; V_35 < ( ( sizeof( struct V_430 ) ) / sizeof( T_3 ) ) ;
V_35 = V_35 + 2 ) {
#ifdef F_163
V_428 [ V_35 ] = F_45 ( V_429 [ V_35 ] ) ;
V_428 [ V_35 + 1 ] = F_45 ( V_429 [ V_35 + 1 ] ) ;
#else
V_428 [ V_35 ] = F_45 ( V_429 [ V_35 + 1 ] ) ;
V_428 [ V_35 + 1 ] = F_45 ( V_429 [ V_35 ] ) ;
#endif
}
}
static void
F_164 ( void * V_125 , T_4 V_130 )
{
struct V_277 * V_278 = (struct V_277 * ) V_125 ;
struct V_431 * V_432 ;
struct V_90 * V_56 , * V_91 ;
union V_373 * V_433 ;
if ( V_130 ) {
struct V_9 V_10 ;
if ( V_278 -> V_434 == V_134 )
F_3 ( & V_10 ) ;
F_31 (qe, qen, &fcport->stats_pending_q) {
F_35 ( & V_278 -> V_394 , & V_56 ) ;
V_432 = (struct V_431 * ) V_56 ;
if ( V_278 -> V_434 == V_134 ) {
V_433 = (union V_373 * ) V_432 -> V_435 ;
if ( F_138 ( & V_278 -> V_68 -> V_264 ) )
F_161 ( & V_433 -> V_436 ,
& V_278 -> V_372 -> V_436 ) ;
else {
F_162 ( & V_433 -> V_437 ,
& V_278 -> V_372 -> V_437 ) ;
V_433 -> V_437 . V_438 =
V_10 . V_11 - V_278 -> V_376 ;
}
}
F_165 ( V_278 -> V_68 , & V_432 -> V_97 ,
V_278 -> V_434 ) ;
}
V_278 -> V_434 = V_134 ;
} else {
F_14 ( & V_278 -> V_394 ) ;
V_278 -> V_434 = V_134 ;
}
}
static void
F_166 ( void * V_125 )
{
struct V_277 * V_278 = (struct V_277 * ) V_125 ;
F_37 ( V_278 -> V_68 , V_278 -> V_439 ) ;
if ( V_278 -> V_439 ) {
F_76 ( & V_278 -> V_440 ) ;
V_278 -> V_439 = V_59 ;
}
V_278 -> V_434 = V_441 ;
F_164 ( V_278 , V_58 ) ;
}
static void
F_167 ( void * V_125 )
{
struct V_277 * V_278 = (struct V_277 * ) V_125 ;
struct V_423 * V_176 ;
V_176 = F_51 ( V_278 -> V_68 , V_416 ) ;
if ( ! V_176 ) {
V_278 -> V_439 = V_58 ;
F_16 ( & V_278 -> V_440 ,
F_167 , V_278 ) ;
F_70 ( V_278 -> V_68 , V_416 ,
& V_278 -> V_440 ) ;
return;
}
V_278 -> V_439 = V_59 ;
memset ( V_176 , 0 , sizeof( struct V_423 ) ) ;
F_53 ( V_176 -> V_152 , V_417 , V_442 ,
F_54 ( V_278 -> V_68 ) ) ;
F_61 ( V_278 -> V_68 , V_416 , V_176 -> V_152 ) ;
}
static void
F_168 ( void * V_125 , T_4 V_130 )
{
struct V_277 * V_278 = (struct V_277 * ) V_125 ;
struct V_431 * V_432 ;
struct V_90 * V_56 , * V_91 ;
if ( V_130 ) {
struct V_9 V_10 ;
F_3 ( & V_10 ) ;
V_278 -> V_376 = V_10 . V_11 ;
F_31 (qe, qen, &fcport->statsclr_pending_q) {
F_35 ( & V_278 -> V_395 , & V_56 ) ;
V_432 = (struct V_431 * ) V_56 ;
F_165 ( V_278 -> V_68 , & V_432 -> V_97 ,
V_278 -> V_434 ) ;
}
V_278 -> V_434 = V_134 ;
} else {
F_14 ( & V_278 -> V_395 ) ;
V_278 -> V_434 = V_134 ;
}
}
static void
F_169 ( void * V_125 )
{
struct V_277 * V_278 = (struct V_277 * ) V_125 ;
F_37 ( V_278 -> V_68 , V_278 -> V_439 ) ;
if ( V_278 -> V_439 ) {
F_76 ( & V_278 -> V_440 ) ;
V_278 -> V_439 = V_59 ;
}
V_278 -> V_434 = V_441 ;
F_168 ( V_278 , V_58 ) ;
}
static void
F_170 ( void * V_125 )
{
struct V_277 * V_278 = (struct V_277 * ) V_125 ;
struct V_423 * V_176 ;
V_176 = F_51 ( V_278 -> V_68 , V_416 ) ;
if ( ! V_176 ) {
V_278 -> V_439 = V_58 ;
F_16 ( & V_278 -> V_440 ,
F_170 , V_278 ) ;
F_70 ( V_278 -> V_68 , V_416 ,
& V_278 -> V_440 ) ;
return;
}
V_278 -> V_439 = V_59 ;
memset ( V_176 , 0 , sizeof( struct V_423 ) ) ;
F_53 ( V_176 -> V_152 , V_417 , V_443 ,
F_54 ( V_278 -> V_68 ) ) ;
F_61 ( V_278 -> V_68 , V_416 , V_176 -> V_152 ) ;
}
static void
F_171 ( struct V_277 * V_278 , struct V_444 * V_445 )
{
struct V_404 * V_365 = & V_278 -> V_365 ;
struct V_446 * V_447 ;
struct V_448 * V_449 ;
enum V_450 V_451 ;
int V_35 ;
int V_452 = 0 ;
F_37 ( V_278 -> V_68 , V_278 -> V_64 . V_366 ) ;
F_5 ( V_445 -> V_453 != V_454 &&
V_445 -> V_453 != V_455 ) ;
F_37 ( V_278 -> V_68 , V_365 -> V_327 . V_336 ) ;
F_37 ( V_278 -> V_68 , V_445 -> V_453 ) ;
F_37 ( V_278 -> V_68 , V_445 -> V_456 ) ;
V_451 = V_365 -> V_327 . V_336 ;
if ( V_278 -> V_64 . V_366 && ( V_365 -> V_327 . V_336 != V_409 ) )
V_365 -> V_327 . V_336 = V_445 -> V_453 ;
V_365 -> V_327 . V_380 = V_445 -> V_456 ;
for ( V_35 = 0 ; V_35 < V_457 ; V_35 ++ ) {
V_449 = & V_365 -> V_327 . V_458 [ V_35 ] ;
V_447 = & V_445 -> V_447 [ V_35 ] ;
V_449 -> V_326 = V_447 -> V_336 ;
V_449 -> V_459 = V_447 -> V_459 ;
V_449 -> V_460 = V_447 -> V_460 ;
V_449 -> V_380 = V_447 -> V_380 ;
V_449 -> V_461 = F_45 ( V_447 -> V_461 ) ;
if ( V_447 -> V_336 == V_462 ) {
V_278 -> V_380 = V_447 -> V_380 ;
V_278 -> V_378 = V_379 ;
V_452 |= 1 << V_35 ;
}
F_37 ( V_278 -> V_68 , V_449 -> V_326 ) ;
F_37 ( V_278 -> V_68 , V_449 -> V_459 ) ;
F_37 ( V_278 -> V_68 , V_449 -> V_460 ) ;
F_37 ( V_278 -> V_68 , V_449 -> V_380 ) ;
F_37 ( V_278 -> V_68 , V_449 -> V_461 ) ;
}
switch ( V_452 ) {
case 3 :
F_8 ( V_278 -> V_68 -> V_13 , V_304 ,
V_463 , 0 , L_21 ) ;
break;
case 2 :
F_8 ( V_278 -> V_68 -> V_13 , V_304 ,
V_463 , 0 , L_22 ) ;
break;
case 1 :
F_8 ( V_278 -> V_68 -> V_13 , V_304 ,
V_463 , 0 , L_23 ) ;
break;
default:
F_8 ( V_278 -> V_68 -> V_13 , V_304 ,
V_463 , 0 , L_24 ) ;
}
if ( ( V_451 != V_365 -> V_327 . V_336 ) ||
( V_445 -> V_453 == V_455 ) ) {
F_136 ( V_278 , ( V_445 -> V_453 == V_454 ) ?
V_318 : V_339 , V_58 ) ;
}
}
static void
F_156 ( struct V_67 * V_68 )
{
struct V_277 * V_278 = F_152 ( V_68 ) ;
int V_35 = 0 ;
if ( V_278 -> V_64 . V_366 ) {
if ( V_278 -> V_365 . V_327 . V_336 == V_454 )
F_136 ( V_278 , V_339 , V_58 ) ;
V_278 -> V_365 . V_327 . V_336 = V_455 ;
V_278 -> V_365 . V_327 . V_380 = V_412 ;
for ( V_35 = 0 ; V_35 < V_457 ; V_35 ++ ) {
V_278 -> V_365 . V_327 . V_458 [ V_35 ] . V_459 = 0 ;
V_278 -> V_365 . V_327 . V_458 [ V_35 ] . V_460 =
V_464 ;
V_278 -> V_365 . V_327 . V_458 [ V_35 ] . V_326 =
V_465 ;
V_278 -> V_365 . V_327 . V_458 [ V_35 ] . V_380 =
V_412 ;
V_278 -> V_365 . V_327 . V_458 [ V_35 ] . V_461 = 0 ;
}
}
}
void
F_172 ( struct V_67 * V_68 )
{
struct V_277 * V_278 = F_152 ( V_68 ) ;
F_160 ( V_278 ) ;
if ( V_278 -> V_64 . V_382 == 0 )
V_278 -> V_64 . V_382 = F_173 ( & V_68 -> V_264 ) ;
V_278 -> V_64 . V_466 = F_174 ( & V_68 -> V_264 ) ;
V_278 -> V_467 = F_175 ( & V_68 -> V_264 ) ;
if ( F_176 ( V_68 ) )
V_68 -> V_468 . V_284 . V_469 = V_58 ;
F_5 ( ! V_278 -> V_64 . V_382 ) ;
F_5 ( ! V_278 -> V_64 . V_466 ) ;
F_5 ( ! V_278 -> V_467 ) ;
}
void
F_177 ( struct V_67 * V_68 , struct V_175 * V_176 )
{
struct V_277 * V_278 = F_152 ( V_68 ) ;
union V_470 V_324 ;
V_324 . V_176 = V_176 ;
V_278 -> V_323 . V_324 = V_324 ;
F_37 ( V_68 , V_176 -> V_177 . V_178 ) ;
F_37 ( V_68 , F_178 ( V_471 , V_278 -> V_472 ) ) ;
switch ( V_176 -> V_177 . V_178 ) {
case V_473 :
if ( V_278 -> V_415 == V_324 . V_474 -> V_415 ) {
V_278 -> V_377 = V_58 ;
if ( V_278 -> V_290 ) {
V_278 -> V_64 = V_324 . V_474 -> V_375 ;
V_278 -> V_64 . V_382 =
F_55 ( V_278 -> V_64 . V_382 ) ;
V_278 -> V_64 . V_475 =
F_55 ( V_278 -> V_64 . V_475 ) ;
V_278 -> V_64 . V_476 =
F_55 ( V_278 -> V_64 . V_476 ) ;
if ( V_278 -> V_64 . V_366 )
V_278 -> V_365 . V_327 . V_336 =
V_455 ;
else
V_278 -> V_365 . V_327 . V_336 =
V_409 ;
V_278 -> V_335 . V_385 =
V_324 . V_474 -> V_375 . V_385 ;
V_278 -> V_290 = V_59 ;
}
if ( V_278 -> V_64 . V_334 )
V_278 -> V_335 . V_336 = V_477 ;
else
V_278 -> V_335 . V_336 = V_478 ;
V_278 -> V_335 . V_479 =
V_324 . V_474 -> V_375 . V_385 ;
if ( V_278 -> V_64 . V_407 )
V_278 -> V_408 . V_336 = V_480 ;
else
V_278 -> V_408 . V_336 = V_481 ;
F_88 ( V_278 , V_314 ) ;
}
break;
case V_482 :
if ( V_278 -> V_415 == V_324 . V_474 -> V_415 )
F_88 ( V_278 , V_314 ) ;
break;
case V_483 :
if ( V_278 -> V_64 . V_407 )
V_278 -> V_408 . V_336 = V_480 ;
else
V_278 -> V_408 . V_336 = V_481 ;
if ( V_324 . V_25 -> V_326 . V_484 == V_318 )
F_88 ( V_278 , V_309 ) ;
else {
if ( V_324 . V_25 -> V_326 . V_485 ==
V_486 )
F_88 ( V_278 ,
V_311 ) ;
else
F_88 ( V_278 ,
V_310 ) ;
}
V_278 -> V_335 . V_479 =
V_324 . V_25 -> V_326 . V_335 . V_479 ;
break;
case V_487 :
F_171 ( V_278 , V_324 . V_488 ) ;
break;
case V_489 :
if ( F_73 ( & V_278 -> V_394 ) ||
( V_278 -> V_434 == V_441 ) )
break;
F_179 ( & V_278 -> V_490 ) ;
V_278 -> V_434 = V_324 . V_491 -> V_198 ;
F_164 ( V_278 , V_58 ) ;
break;
case V_492 :
if ( F_73 ( & V_278 -> V_395 ) ||
( V_278 -> V_434 == V_441 ) )
break;
F_179 ( & V_278 -> V_490 ) ;
V_278 -> V_434 = V_134 ;
F_168 ( V_278 , V_58 ) ;
break;
case V_493 :
F_88 ( V_278 , V_293 ) ;
break;
case V_494 :
F_88 ( V_278 , V_294 ) ;
break;
default:
F_5 ( 1 ) ;
break;
}
}
void
F_180 ( struct V_67 * V_68 ,
void (* V_174) ( void * V_125 ,
enum V_364 V_25 ) ,
void * V_125 )
{
struct V_277 * V_278 = F_152 ( V_68 ) ;
V_278 -> V_317 = V_174 ;
V_278 -> V_362 = V_125 ;
}
T_7
F_181 ( struct V_67 * V_68 )
{
struct V_277 * V_278 = F_152 ( V_68 ) ;
if ( F_176 ( V_68 ) )
return V_495 ;
if ( F_182 ( & V_68 -> V_264 ) )
return V_496 ;
if ( V_278 -> V_497 )
return V_498 ;
F_88 ( F_152 ( V_68 ) , V_293 ) ;
return V_134 ;
}
T_7
F_183 ( struct V_67 * V_68 )
{
if ( F_176 ( V_68 ) )
return V_495 ;
if ( F_182 ( & V_68 -> V_264 ) )
return V_496 ;
F_88 ( F_152 ( V_68 ) , V_294 ) ;
return V_134 ;
}
T_7
F_176 ( struct V_67 * V_68 )
{
struct V_277 * V_278 = F_152 ( V_68 ) ;
struct V_499 * V_500 = & V_68 -> V_500 ;
struct V_501 * V_502 = V_500 -> V_502 ;
if ( V_502 -> V_503 . V_504 == V_505 ) {
F_37 ( V_68 , V_278 -> V_254 ) ;
return V_495 ;
}
return V_134 ;
}
T_7
F_184 ( struct V_67 * V_68 , enum V_506 V_380 )
{
struct V_277 * V_278 = F_152 ( V_68 ) ;
F_37 ( V_68 , V_380 ) ;
if ( V_278 -> V_64 . V_366 == V_58 )
return V_507 ;
if ( ( V_278 -> V_64 . V_378 == V_405 ) &&
( V_380 == V_508 ) )
return V_509 ;
if ( ( V_380 != V_381 ) && ( V_380 > V_278 -> V_467 ) ) {
F_37 ( V_68 , V_278 -> V_467 ) ;
return V_509 ;
}
if ( F_185 ( & V_278 -> V_68 -> V_264 ) == V_510 ) {
if ( ( V_380 == V_384 ) &&
( F_186 ( V_68 -> V_264 . V_85 . V_511 ) ) )
return V_509 ;
if ( ! ( V_380 == V_384 ||
V_380 == V_512 ||
V_380 == V_513 ||
V_380 == V_514 ||
V_380 == V_508 ||
V_380 == V_381 ) )
return V_509 ;
} else {
if ( V_380 != V_515 )
return V_509 ;
}
V_278 -> V_64 . V_380 = V_380 ;
return V_134 ;
}
enum V_506
F_187 ( struct V_67 * V_68 )
{
struct V_277 * V_278 = F_152 ( V_68 ) ;
return V_278 -> V_380 ;
}
T_7
F_188 ( struct V_67 * V_68 , enum V_516 V_378 )
{
struct V_277 * V_278 = F_152 ( V_68 ) ;
F_37 ( V_68 , V_378 ) ;
F_37 ( V_68 , V_278 -> V_64 . V_378 ) ;
switch ( V_378 ) {
case V_379 :
break;
case V_405 :
if ( ( F_189 ( V_68 ) != V_59 ) ||
( V_278 -> V_335 . V_336 != V_478 ) )
return V_517 ;
if ( V_278 -> V_64 . V_518 != V_59 )
return V_519 ;
if ( ( F_190 ( V_68 ) != V_59 ) ||
( V_278 -> V_365 . V_327 . V_336 != V_409 ) )
return V_520 ;
if ( ( F_187 ( V_68 ) == V_508 ) ||
( V_278 -> V_64 . V_380 == V_508 ) )
return V_509 ;
if ( F_191 ( V_68 -> V_264 . V_327 -> V_521 ) )
return V_522 ;
if ( F_192 ( V_68 ) != V_59 )
return V_523 ;
if ( F_193 ( V_68 ) != V_59 )
return V_523 ;
break;
case V_524 :
break;
default:
return V_525 ;
}
V_278 -> V_64 . V_378 = V_378 ;
return V_134 ;
}
enum V_516
F_194 ( struct V_67 * V_68 )
{
struct V_277 * V_278 = F_152 ( V_68 ) ;
return V_278 -> V_378 ;
}
enum V_516
F_195 ( struct V_67 * V_68 )
{
struct V_277 * V_278 = F_152 ( V_68 ) ;
return V_278 -> V_64 . V_378 ;
}
T_7
F_196 ( struct V_67 * V_68 , V_37 V_251 )
{
struct V_277 * V_278 = F_152 ( V_68 ) ;
F_37 ( V_68 , V_251 ) ;
F_37 ( V_68 , V_278 -> V_64 . V_526 ) ;
F_37 ( V_68 , V_278 -> V_64 . V_527 ) ;
V_278 -> V_64 . V_526 = V_58 ;
V_278 -> V_64 . V_527 = V_251 ;
return V_134 ;
}
T_7
F_197 ( struct V_67 * V_68 )
{
struct V_277 * V_278 = F_152 ( V_68 ) ;
F_37 ( V_68 , V_278 -> V_64 . V_526 ) ;
F_37 ( V_68 , V_278 -> V_64 . V_527 ) ;
V_278 -> V_64 . V_526 = V_59 ;
return V_134 ;
}
T_4
F_198 ( struct V_67 * V_68 , V_37 * V_251 )
{
struct V_277 * V_278 = F_152 ( V_68 ) ;
* V_251 = V_278 -> V_64 . V_527 ;
return V_278 -> V_64 . V_526 ;
}
V_37
F_199 ( struct V_67 * V_68 )
{
struct V_277 * V_278 = F_152 ( V_68 ) ;
return V_278 -> V_398 ;
}
T_7
F_200 ( struct V_67 * V_68 , T_2 V_382 )
{
struct V_277 * V_278 = F_152 ( V_68 ) ;
F_37 ( V_68 , V_382 ) ;
F_37 ( V_68 , V_278 -> V_64 . V_382 ) ;
if ( ( V_382 > V_159 ) || ( V_382 < V_528 ) )
return V_529 ;
if ( ( V_382 != V_159 ) && ( V_382 & ( V_382 - 1 ) ) )
return V_529 ;
V_278 -> V_64 . V_382 = V_382 ;
return V_134 ;
}
T_2
F_201 ( struct V_67 * V_68 )
{
struct V_277 * V_278 = F_152 ( V_68 ) ;
return V_278 -> V_64 . V_382 ;
}
V_37
F_202 ( struct V_67 * V_68 )
{
if ( F_194 ( V_68 ) != V_405 )
return ( F_152 ( V_68 ) ) -> V_64 . V_466 ;
else
return 0 ;
}
void
F_203 ( struct V_67 * V_68 , T_2 V_530 )
{
struct V_277 * V_278 = F_152 ( V_68 ) ;
V_278 -> V_64 . V_530 = ( V_37 ) V_530 ;
}
T_10
F_204 ( struct V_67 * V_68 , T_4 V_531 )
{
struct V_277 * V_278 = F_152 ( V_68 ) ;
if ( V_531 )
return V_278 -> V_255 ;
else
return V_278 -> V_254 ;
}
void
F_205 ( struct V_67 * V_68 , struct V_532 * V_327 )
{
struct V_277 * V_278 = F_152 ( V_68 ) ;
memset ( V_327 , 0 , sizeof( struct V_532 ) ) ;
V_327 -> V_255 = V_278 -> V_255 ;
V_327 -> V_254 = V_278 -> V_254 ;
V_327 -> V_533 = V_68 -> V_264 . V_327 -> V_534 ;
V_327 -> V_535 = V_68 -> V_264 . V_327 -> V_536 ;
memcpy ( & V_327 -> V_537 , & V_278 -> V_64 ,
sizeof( struct V_374 ) ) ;
V_327 -> V_537 . V_380 = V_278 -> V_64 . V_380 ;
V_327 -> V_538 = V_278 -> V_467 ;
V_327 -> V_380 = V_278 -> V_380 ;
V_327 -> V_539 = V_540 ;
V_327 -> V_537 . V_378 = V_278 -> V_64 . V_378 ;
V_327 -> V_378 = V_278 -> V_378 ;
V_327 -> V_537 . V_366 = V_278 -> V_64 . V_366 ;
V_327 -> V_541 = V_278 -> V_541 ;
V_327 -> V_542 = V_278 -> V_542 ;
V_327 -> V_537 . V_475 = F_206 ( V_68 ) ;
V_327 -> V_537 . V_476 = F_207 ( V_68 ) ;
V_327 -> V_543 = F_178 ( V_471 , V_278 -> V_472 ) ;
V_327 -> V_392 = V_278 -> V_392 ;
if ( F_176 ( V_68 ) )
V_327 -> V_543 = V_544 ;
else {
if ( F_182 ( & V_278 -> V_68 -> V_264 ) )
V_327 -> V_543 = V_545 ;
else if ( F_208 ( & V_278 -> V_68 -> V_264 ) )
V_327 -> V_543 = V_546 ;
}
V_327 -> V_410 = V_278 -> V_410 ;
}
T_7
F_209 ( struct V_67 * V_68 , struct V_431 * V_432 )
{
struct V_277 * V_278 = F_152 ( V_68 ) ;
if ( ! F_210 ( V_68 ) ||
! V_278 -> V_377 )
return V_547 ;
if ( ! F_73 ( & V_278 -> V_395 ) )
return V_548 ;
if ( F_73 ( & V_278 -> V_394 ) ) {
F_15 ( & V_432 -> V_97 . V_56 , & V_278 -> V_394 ) ;
F_167 ( V_278 ) ;
F_211 ( V_68 , & V_278 -> V_490 ,
F_166 ,
V_278 , V_549 ) ;
} else
F_15 ( & V_432 -> V_97 . V_56 , & V_278 -> V_394 ) ;
return V_134 ;
}
T_7
F_212 ( struct V_67 * V_68 , struct V_431 * V_432 )
{
struct V_277 * V_278 = F_152 ( V_68 ) ;
if ( ! F_210 ( V_68 ) ||
! V_278 -> V_377 )
return V_547 ;
if ( ! F_73 ( & V_278 -> V_394 ) )
return V_548 ;
if ( F_73 ( & V_278 -> V_395 ) ) {
F_15 ( & V_432 -> V_97 . V_56 , & V_278 -> V_395 ) ;
F_170 ( V_278 ) ;
F_211 ( V_68 , & V_278 -> V_490 ,
F_169 ,
V_278 , V_549 ) ;
} else
F_15 ( & V_432 -> V_97 . V_56 , & V_278 -> V_395 ) ;
return V_134 ;
}
T_4
F_213 ( struct V_67 * V_68 )
{
struct V_277 * V_278 = F_152 ( V_68 ) ;
return F_178 ( V_471 , V_278 -> V_472 ) ==
V_550 ;
}
T_4
F_192 ( struct V_67 * V_68 )
{
struct V_277 * V_278 = F_152 ( V_68 ) ;
return ( F_178 ( V_471 , V_278 -> V_472 ) ==
V_551 ) ;
}
T_4
F_193 ( struct V_67 * V_68 )
{
struct V_277 * V_278 = F_152 ( V_68 ) ;
return ( F_178 ( V_471 , V_278 -> V_472 ) ==
V_552 ) ;
}
T_7
F_214 ( struct V_67 * V_68 , struct V_553 * V_385 )
{
struct V_277 * V_278 = F_152 ( V_68 ) ;
enum V_554 V_285 = F_128 ( V_68 ) ;
F_37 ( V_68 , V_285 ) ;
if ( ( V_385 -> V_386 == 0 ) || ( V_385 -> V_388 == 0 ) || ( V_385 -> V_390 == 0 ) )
return V_555 ;
if ( ( V_385 -> V_386 + V_385 -> V_388 + V_385 -> V_390 ) != 100 )
return V_555 ;
if ( ( V_385 -> V_388 > V_385 -> V_386 ) || ( V_385 -> V_390 > V_385 -> V_388 ) ||
( V_385 -> V_390 > V_385 -> V_386 ) )
return V_555 ;
if ( ( V_285 == V_510 ) &&
( V_278 -> V_64 . V_378 != V_405 ) )
V_278 -> V_64 . V_385 = * V_385 ;
return V_134 ;
}
T_4
F_215 ( struct V_67 * V_68 )
{
struct V_277 * V_278 = F_152 ( V_68 ) ;
return V_278 -> V_64 . V_518 ? V_58 : V_59 ;
}
void
F_216 ( struct V_67 * V_68 , V_37 V_336 )
{
struct V_277 * V_278 = F_152 ( V_68 ) ;
F_37 ( V_68 , V_336 ) ;
V_278 -> V_64 . V_556 = V_336 ;
}
enum V_506
F_217 ( struct V_67 * V_68 )
{
struct V_277 * V_278 = F_152 ( V_68 ) ;
F_37 ( V_68 , V_278 -> V_64 . V_383 ) ;
return V_278 -> V_64 . V_383 ;
}
void
F_218 ( void * V_557 , T_4 V_541 ,
T_4 V_542 )
{
struct V_67 * V_68 = V_557 ;
struct V_277 * V_278 = F_152 ( V_68 ) ;
F_37 ( V_68 , V_541 ) ;
F_37 ( V_68 , V_542 ) ;
F_37 ( V_68 , V_278 -> V_541 ) ;
F_37 ( V_68 , V_278 -> V_542 ) ;
V_278 -> V_541 = V_541 ;
V_278 -> V_542 = V_542 ;
}
T_4
F_219 ( struct V_67 * V_68 )
{
struct V_277 * V_278 = F_152 ( V_68 ) ;
return ( ! V_278 -> V_64 . V_366 &&
F_220 ( V_278 , V_316 ) ) ||
( V_278 -> V_64 . V_366 &&
V_278 -> V_365 . V_327 . V_336 == V_454 ) ;
}
T_4
F_189 ( struct V_67 * V_68 )
{
struct V_277 * V_278 = F_152 ( V_68 ) ;
return V_278 -> V_64 . V_334 ;
}
T_4
F_190 ( struct V_67 * V_68 )
{
struct V_277 * V_278 = F_152 ( V_68 ) ;
return V_278 -> V_64 . V_366 ;
}
T_7
F_221 ( struct V_67 * V_68 , T_4 V_558 , V_37 V_559 )
{
struct V_277 * V_278 = F_152 ( V_68 ) ;
F_37 ( V_68 , V_558 ) ;
if ( F_185 ( & V_278 -> V_68 -> V_264 ) != V_510 )
return V_560 ;
if ( F_191 ( V_68 -> V_264 . V_327 -> V_521 ) &&
( V_68 -> V_264 . V_327 -> V_521 != V_561 ) )
return V_562 ;
if ( V_558 ) {
if ( V_278 -> V_64 . V_378 == V_405 )
return V_563 ;
if ( V_278 -> V_64 . V_334 )
return V_517 ;
if ( V_278 -> V_64 . V_366 )
return V_507 ;
if ( ( V_278 -> V_64 . V_380 != V_381 ) &&
( V_278 -> V_64 . V_380 < F_175 ( & V_68 -> V_264 ) ) )
return V_564 ;
if ( F_175 ( & V_68 -> V_264 ) < V_514 )
return V_565 ;
if ( V_278 -> V_64 . V_407 ) {
if ( V_559 != V_278 -> V_64 . V_559 )
return V_566 ;
else
return V_567 ;
}
if ( ( V_559 == 0 ) || ( V_559 > V_568 ) )
V_559 = V_569 ;
V_278 -> V_64 . V_407 = V_558 ;
V_278 -> V_64 . V_559 = V_559 ;
} else {
if ( ! V_278 -> V_64 . V_407 )
return V_567 ;
V_278 -> V_64 . V_407 = V_558 ;
V_278 -> V_64 . V_559 = 0 ;
}
return V_134 ;
}
T_7
F_222 ( struct V_67 * V_68 ,
struct V_570 * V_408 )
{
struct V_277 * V_278 = F_152 ( V_68 ) ;
if ( F_185 ( & V_278 -> V_68 -> V_264 ) != V_510 )
return V_560 ;
if ( V_278 -> V_64 . V_378 == V_405 )
return V_563 ;
* V_408 = V_278 -> V_408 ;
return V_134 ;
}
void
F_223 ( struct V_67 * V_68 )
{
F_88 ( F_152 ( V_68 ) , V_346 ) ;
F_224 ( & V_68 -> V_468 . V_284 , V_58 ) ;
}
void
F_225 ( struct V_67 * V_68 )
{
F_88 ( F_152 ( V_68 ) , V_350 ) ;
F_224 ( & V_68 -> V_468 . V_284 , V_59 ) ;
}
void
F_226 ( struct V_67 * V_68 )
{
F_88 ( F_152 ( V_68 ) , V_348 ) ;
}
void
F_227 ( struct V_67 * V_68 )
{
F_88 ( F_152 ( V_68 ) , V_351 ) ;
}
static void
F_228 ( struct V_149 * V_571 , enum V_572 V_25 )
{
F_37 ( V_571 -> V_68 , V_571 -> V_573 ) ;
F_37 ( V_571 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_574 :
F_229 ( V_571 , V_575 ) ;
F_83 ( V_571 , V_576 ) ;
break;
default:
F_229 ( V_571 , V_577 ) ;
F_87 ( V_571 -> V_68 , V_25 ) ;
}
}
static void
V_576 ( struct V_149 * V_571 , enum V_572 V_25 )
{
F_37 ( V_571 -> V_68 , V_571 -> V_573 ) ;
F_37 ( V_571 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_578 :
F_229 ( V_571 , V_579 ) ;
if ( F_230 ( V_571 ) )
F_83 ( V_571 , V_580 ) ;
else
F_83 ( V_571 , V_581 ) ;
break;
case V_582 :
F_229 ( V_571 , V_583 ) ;
F_83 ( V_571 , F_228 ) ;
F_231 ( V_571 ) ;
break;
case V_584 :
F_229 ( V_571 , V_585 ) ;
F_83 ( V_571 , V_586 ) ;
break;
default:
F_229 ( V_571 , V_587 ) ;
F_87 ( V_571 -> V_68 , V_25 ) ;
}
}
static void
V_580 ( struct V_149 * V_571 , enum V_572 V_25 )
{
F_37 ( V_571 -> V_68 , V_571 -> V_573 ) ;
F_37 ( V_571 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_588 :
F_229 ( V_571 , V_589 ) ;
F_83 ( V_571 , V_590 ) ;
F_232 ( V_571 ) ;
break;
case V_582 :
F_229 ( V_571 , V_591 ) ;
F_83 ( V_571 , V_592 ) ;
break;
case V_593 :
F_229 ( V_571 , V_594 ) ;
F_83 ( V_571 , V_595 ) ;
break;
case V_584 :
F_229 ( V_571 , V_596 ) ;
F_83 ( V_571 , V_586 ) ;
break;
default:
F_229 ( V_571 , V_597 ) ;
F_87 ( V_571 -> V_68 , V_25 ) ;
}
}
static void
V_581 ( struct V_149 * V_571 , enum V_572 V_25 )
{
F_37 ( V_571 -> V_68 , V_571 -> V_573 ) ;
F_37 ( V_571 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_598 :
F_83 ( V_571 , V_580 ) ;
F_230 ( V_571 ) ;
break;
case V_582 :
F_229 ( V_571 , V_591 ) ;
F_83 ( V_571 , F_228 ) ;
F_76 ( & V_571 -> V_302 ) ;
F_231 ( V_571 ) ;
break;
case V_593 :
F_229 ( V_571 , V_594 ) ;
F_83 ( V_571 , V_599 ) ;
F_76 ( & V_571 -> V_302 ) ;
F_233 ( V_571 ) ;
break;
case V_584 :
F_229 ( V_571 , V_596 ) ;
F_83 ( V_571 , V_586 ) ;
F_76 ( & V_571 -> V_302 ) ;
break;
default:
F_229 ( V_571 , V_597 ) ;
F_87 ( V_571 -> V_68 , V_25 ) ;
}
}
static void
V_590 ( struct V_149 * V_571 , enum V_572 V_25 )
{
struct V_600 * V_601 ;
F_37 ( V_571 -> V_68 , V_571 -> V_573 ) ;
F_37 ( V_571 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_593 :
F_229 ( V_571 , V_602 ) ;
if ( F_234 ( V_571 ) )
F_83 ( V_571 , V_603 ) ;
else
F_83 ( V_571 , V_604 ) ;
break;
case V_582 :
F_229 ( V_571 , V_605 ) ;
if ( F_234 ( V_571 ) )
F_83 ( V_571 , V_606 ) ;
else
F_83 ( V_571 , V_607 ) ;
break;
case V_584 :
F_229 ( V_571 , V_608 ) ;
F_83 ( V_571 , V_586 ) ;
break;
case V_609 :
F_235 ( V_571 ) ;
break;
case V_610 :
V_601 = (struct V_600 * ) V_571 -> V_323 . V_611 ;
V_571 -> V_335 = V_601 -> V_612 ;
F_37 ( V_571 -> V_68 , V_601 -> V_613 . V_614 ) ;
F_37 ( V_571 -> V_68 , V_601 -> V_612 . V_614 ) ;
F_37 ( V_571 -> V_68 , V_601 -> V_613 . V_615 ) ;
F_37 ( V_571 -> V_68 , V_601 -> V_612 . V_615 ) ;
V_601 -> V_613 . V_614 =
F_45 ( V_601 -> V_613 . V_614 ) ;
V_601 -> V_612 . V_614 =
F_45 ( V_601 -> V_612 . V_614 ) ;
if ( V_601 -> V_613 . V_614 !=
V_601 -> V_612 . V_614 )
F_236 ( V_571 -> V_616 ,
V_601 -> V_613 ,
V_601 -> V_612 ) ;
if ( V_601 -> V_613 . V_615 !=
V_601 -> V_612 . V_615 )
F_237 ( V_571 -> V_616 ,
V_601 -> V_613 ,
V_601 -> V_612 ) ;
break;
default:
F_229 ( V_571 , V_617 ) ;
F_87 ( V_571 -> V_68 , V_25 ) ;
}
}
static void
V_603 ( struct V_149 * V_571 , enum V_572 V_25 )
{
F_37 ( V_571 -> V_68 , V_571 -> V_573 ) ;
F_37 ( V_571 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_588 :
F_229 ( V_571 , V_618 ) ;
F_83 ( V_571 , V_599 ) ;
F_233 ( V_571 ) ;
break;
case V_582 :
F_229 ( V_571 , V_619 ) ;
F_83 ( V_571 , V_606 ) ;
break;
case V_584 :
F_229 ( V_571 , V_620 ) ;
F_83 ( V_571 , V_586 ) ;
F_233 ( V_571 ) ;
break;
default:
F_229 ( V_571 , V_621 ) ;
F_87 ( V_571 -> V_68 , V_25 ) ;
}
}
static void
V_604 ( struct V_149 * V_571 , enum V_572 V_25 )
{
F_37 ( V_571 -> V_68 , V_571 -> V_573 ) ;
F_37 ( V_571 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_598 :
F_83 ( V_571 , V_603 ) ;
F_234 ( V_571 ) ;
break;
case V_582 :
F_229 ( V_571 , V_619 ) ;
F_83 ( V_571 , V_607 ) ;
break;
case V_584 :
F_229 ( V_571 , V_620 ) ;
F_83 ( V_571 , V_586 ) ;
F_76 ( & V_571 -> V_302 ) ;
F_233 ( V_571 ) ;
break;
default:
F_229 ( V_571 , V_621 ) ;
F_87 ( V_571 -> V_68 , V_25 ) ;
}
}
static void
V_599 ( struct V_149 * V_571 , enum V_572 V_25 )
{
F_37 ( V_571 -> V_68 , V_571 -> V_573 ) ;
F_37 ( V_571 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_582 :
F_229 ( V_571 , V_622 ) ;
F_83 ( V_571 , F_228 ) ;
F_231 ( V_571 ) ;
break;
case V_578 :
F_229 ( V_571 , V_623 ) ;
if ( F_230 ( V_571 ) )
F_83 ( V_571 , V_580 ) ;
else
F_83 ( V_571 , V_581 ) ;
break;
case V_584 :
F_229 ( V_571 , V_624 ) ;
F_83 ( V_571 , V_586 ) ;
break;
case V_593 :
F_233 ( V_571 ) ;
break;
default:
F_229 ( V_571 , V_625 ) ;
F_87 ( V_571 -> V_68 , V_25 ) ;
}
}
static void
V_606 ( struct V_149 * V_571 , enum V_572 V_25 )
{
F_37 ( V_571 -> V_68 , V_571 -> V_573 ) ;
F_37 ( V_571 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_588 :
F_229 ( V_571 , V_626 ) ;
F_83 ( V_571 , F_228 ) ;
F_231 ( V_571 ) ;
break;
case V_584 :
F_229 ( V_571 , V_627 ) ;
F_83 ( V_571 , F_228 ) ;
F_231 ( V_571 ) ;
break;
default:
F_87 ( V_571 -> V_68 , V_25 ) ;
}
}
static void
V_607 ( struct V_149 * V_571 , enum V_572 V_25 )
{
F_37 ( V_571 -> V_68 , V_571 -> V_573 ) ;
F_37 ( V_571 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_598 :
F_229 ( V_571 , V_626 ) ;
F_83 ( V_571 , V_606 ) ;
F_234 ( V_571 ) ;
break;
case V_584 :
F_229 ( V_571 , V_627 ) ;
F_83 ( V_571 , F_228 ) ;
F_76 ( & V_571 -> V_302 ) ;
F_231 ( V_571 ) ;
break;
default:
F_87 ( V_571 -> V_68 , V_25 ) ;
}
}
static void
V_592 ( struct V_149 * V_571 ,
enum V_572 V_25 )
{
F_37 ( V_571 -> V_68 , V_571 -> V_573 ) ;
F_37 ( V_571 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_588 :
F_229 ( V_571 , V_628 ) ;
if ( F_234 ( V_571 ) )
F_83 ( V_571 , V_606 ) ;
else
F_83 ( V_571 , V_607 ) ;
break;
case V_584 :
F_229 ( V_571 , V_629 ) ;
F_83 ( V_571 , F_228 ) ;
F_231 ( V_571 ) ;
break;
default:
F_229 ( V_571 , V_630 ) ;
F_87 ( V_571 -> V_68 , V_25 ) ;
}
}
static void
V_595 ( struct V_149 * V_571 ,
enum V_572 V_25 )
{
F_37 ( V_571 -> V_68 , V_571 -> V_573 ) ;
F_37 ( V_571 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_588 :
F_229 ( V_571 , V_631 ) ;
if ( F_234 ( V_571 ) )
F_83 ( V_571 , V_603 ) ;
else
F_83 ( V_571 , V_604 ) ;
break;
case V_582 :
F_229 ( V_571 , V_632 ) ;
F_83 ( V_571 , V_592 ) ;
break;
case V_584 :
F_229 ( V_571 , V_633 ) ;
F_83 ( V_571 , V_586 ) ;
F_233 ( V_571 ) ;
break;
default:
F_229 ( V_571 , V_634 ) ;
F_87 ( V_571 -> V_68 , V_25 ) ;
}
}
static void
V_586 ( struct V_149 * V_571 , enum V_572 V_25 )
{
F_37 ( V_571 -> V_68 , V_571 -> V_573 ) ;
F_37 ( V_571 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_593 :
F_229 ( V_571 , V_635 ) ;
F_233 ( V_571 ) ;
break;
case V_582 :
F_229 ( V_571 , V_636 ) ;
F_83 ( V_571 , F_228 ) ;
F_231 ( V_571 ) ;
break;
case V_578 :
F_229 ( V_571 , V_637 ) ;
if ( F_230 ( V_571 ) )
F_83 ( V_571 , V_580 ) ;
else
F_83 ( V_571 , V_581 ) ;
break;
case V_584 :
break;
default:
F_229 ( V_571 , V_638 ) ;
F_87 ( V_571 -> V_68 , V_25 ) ;
}
}
static void
F_238 ( void * V_125 , T_4 V_130 )
{
struct V_149 * V_571 = V_125 ;
if ( V_130 )
F_239 ( V_571 -> V_616 ) ;
}
static void
F_240 ( void * V_125 , T_4 V_130 )
{
struct V_149 * V_571 = V_125 ;
if ( V_130 )
F_241 ( V_571 -> V_616 ) ;
}
static void
F_242 ( void * V_125 )
{
struct V_149 * V_571 = V_125 ;
F_88 ( V_571 , V_598 ) ;
}
static void
F_243 ( struct V_63 * V_64 , struct V_65 * V_66 ,
struct V_67 * V_68 )
{
struct V_69 * V_639 = F_244 ( V_68 ) ;
if ( V_64 -> V_76 . V_640 < V_641 )
V_64 -> V_76 . V_640 = V_641 ;
F_24 ( V_66 , V_639 ,
V_64 -> V_76 . V_640 * sizeof( struct V_149 ) ) ;
}
static void
F_245 ( struct V_67 * V_68 , void * V_83 , struct V_63 * V_64 ,
struct V_84 * V_85 )
{
struct V_642 * V_44 = F_246 ( V_68 ) ;
struct V_149 * V_571 ;
T_2 V_35 ;
F_14 ( & V_44 -> V_643 ) ;
F_14 ( & V_44 -> V_644 ) ;
F_14 ( & V_44 -> V_645 ) ;
V_571 = (struct V_149 * ) F_13 ( V_44 ) ;
V_44 -> V_646 = V_571 ;
V_44 -> V_640 = V_64 -> V_76 . V_640 ;
F_5 ( ! V_44 -> V_640 ||
( V_44 -> V_640 & ( V_44 -> V_640 - 1 ) ) ) ;
for ( V_35 = 0 ; V_35 < V_44 -> V_640 ; V_35 ++ , V_571 ++ ) {
memset ( V_571 , 0 , sizeof( struct V_149 ) ) ;
V_571 -> V_68 = V_68 ;
V_571 -> V_573 = V_35 ;
F_83 ( V_571 , F_228 ) ;
if ( V_35 )
F_15 ( & V_571 -> V_56 , & V_44 -> V_643 ) ;
F_16 ( & V_571 -> V_302 , F_242 , V_571 ) ;
}
F_13 ( V_44 ) = ( V_37 * ) V_571 ;
}
static void
F_247 ( struct V_67 * V_68 )
{
}
static void
F_248 ( struct V_67 * V_68 )
{
}
static void
F_249 ( struct V_67 * V_68 )
{
}
static void
F_250 ( struct V_67 * V_68 )
{
struct V_642 * V_44 = F_246 ( V_68 ) ;
struct V_149 * V_150 ;
struct V_90 * V_56 , * V_91 ;
F_30 ( & V_44 -> V_645 , & V_44 -> V_643 ) ;
F_31 (qe, qen, &mod->rp_active_q) {
V_150 = (struct V_149 * ) V_56 ;
F_88 ( V_150 , V_584 ) ;
}
}
static struct V_149 *
F_251 ( struct V_642 * V_44 )
{
struct V_149 * V_150 ;
F_35 ( & V_44 -> V_643 , & V_150 ) ;
if ( V_150 )
F_15 ( & V_150 -> V_56 , & V_44 -> V_644 ) ;
return V_150 ;
}
static void
F_231 ( struct V_149 * V_150 )
{
struct V_642 * V_44 = F_246 ( V_150 -> V_68 ) ;
F_5 ( ! F_40 ( & V_44 -> V_644 , V_150 ) ) ;
F_41 ( & V_150 -> V_56 ) ;
F_15 ( & V_150 -> V_56 , & V_44 -> V_643 ) ;
}
static T_4
F_230 ( struct V_149 * V_571 )
{
struct V_647 * V_248 ;
V_248 = F_51 ( V_571 -> V_68 , V_648 ) ;
if ( ! V_248 ) {
F_70 ( V_571 -> V_68 , V_648 , & V_571 -> V_302 ) ;
return V_59 ;
}
F_53 ( V_248 -> V_152 , V_649 , V_650 ,
F_54 ( V_571 -> V_68 ) ) ;
V_248 -> V_651 = V_571 -> V_573 ;
V_248 -> V_157 = F_55 ( V_571 -> V_158 . V_157 ) ;
V_248 -> V_268 = V_571 -> V_158 . V_268 ;
V_248 -> V_161 = F_56 ( V_571 -> V_68 , ( V_37 ) V_571 -> V_158 . V_162 ) ;
V_248 -> V_652 = V_571 -> V_158 . V_652 ;
V_248 -> V_653 = V_571 -> V_158 . V_653 ;
V_248 -> V_654 = V_571 -> V_158 . V_654 ;
V_248 -> V_160 = V_571 -> V_158 . V_160 ;
V_248 -> V_655 = V_571 -> V_158 . V_655 ;
F_61 ( V_571 -> V_68 , V_648 , V_248 -> V_152 ) ;
return V_58 ;
}
static T_4
F_234 ( struct V_149 * V_571 )
{
struct V_656 * V_248 ;
V_248 = F_51 ( V_571 -> V_68 , V_648 ) ;
if ( ! V_248 ) {
F_70 ( V_571 -> V_68 , V_648 , & V_571 -> V_302 ) ;
return V_59 ;
}
F_53 ( V_248 -> V_152 , V_649 , V_657 ,
F_54 ( V_571 -> V_68 ) ) ;
V_248 -> V_156 = V_571 -> V_156 ;
F_61 ( V_571 -> V_68 , V_648 , V_248 -> V_152 ) ;
return V_58 ;
}
static T_4
F_235 ( struct V_149 * V_571 )
{
struct V_658 * V_248 ;
V_248 = F_51 ( V_571 -> V_68 , V_648 ) ;
if ( ! V_248 ) {
F_37 ( V_571 -> V_68 , V_571 -> V_158 . V_380 ) ;
return V_59 ;
}
F_53 ( V_248 -> V_152 , V_649 , V_659 ,
F_54 ( V_571 -> V_68 ) ) ;
V_248 -> V_156 = V_571 -> V_156 ;
V_248 -> V_380 = ( V_37 ) V_571 -> V_158 . V_380 ;
F_61 ( V_571 -> V_68 , V_648 , V_248 -> V_152 ) ;
return V_58 ;
}
void
F_252 ( struct V_67 * V_68 , struct V_175 * V_248 )
{
union V_660 V_176 ;
struct V_149 * V_571 ;
F_37 ( V_68 , V_248 -> V_177 . V_178 ) ;
V_176 . V_176 = V_248 ;
switch ( V_248 -> V_177 . V_178 ) {
case V_661 :
V_571 = F_253 ( V_68 , V_176 . V_662 -> V_651 ) ;
V_571 -> V_156 = V_176 . V_662 -> V_156 ;
V_571 -> V_335 = V_176 . V_662 -> V_335 ;
F_254 ( V_68 , V_571 ) ;
F_5 ( V_176 . V_662 -> V_198 != V_134 ) ;
F_88 ( V_571 , V_588 ) ;
break;
case V_663 :
V_571 = F_253 ( V_68 , V_176 . V_664 -> V_651 ) ;
F_5 ( V_176 . V_664 -> V_198 != V_134 ) ;
F_255 ( V_68 , V_571 ) ;
F_88 ( V_571 , V_588 ) ;
break;
case V_665 :
V_571 = F_253 ( V_68 , V_176 . V_666 -> V_651 ) ;
V_571 -> V_323 . V_611 = V_176 . V_666 ;
F_88 ( V_571 , V_610 ) ;
break;
case V_667 :
F_158 ( F_152 ( V_68 ) ,
& V_176 . V_668 -> V_397 ) ;
F_256 ( V_68 ) ;
break;
case V_669 :
F_257 ( V_68 ) ;
break;
case V_670 :
V_571 = F_253 ( V_68 , V_176 . V_668 -> V_651 ) ;
F_258 ( V_571 -> V_616 ) ;
break;
default:
F_37 ( V_68 , V_248 -> V_177 . V_178 ) ;
F_5 ( 1 ) ;
}
}
void
F_259 ( struct V_67 * V_68 , T_2 V_671 )
{
struct V_642 * V_44 = F_246 ( V_68 ) ;
struct V_90 * V_56 ;
int V_35 ;
for ( V_35 = 0 ; V_35 < ( V_44 -> V_640 - V_671 ) ; V_35 ++ ) {
F_80 ( & V_44 -> V_643 , & V_56 ) ;
F_15 ( V_56 , & V_44 -> V_645 ) ;
}
}
struct V_149 *
F_260 ( struct V_67 * V_68 , void * V_616 )
{
struct V_149 * V_571 ;
V_571 = F_251 ( F_246 ( V_68 ) ) ;
if ( V_571 == NULL )
return NULL ;
V_571 -> V_68 = V_68 ;
V_571 -> V_616 = V_616 ;
memset ( & V_571 -> V_372 , 0 , sizeof( V_571 -> V_372 ) ) ;
F_5 ( ! F_220 ( V_571 , F_228 ) ) ;
F_88 ( V_571 , V_574 ) ;
return V_571 ;
}
void
F_261 ( struct V_149 * V_150 , struct V_672 * V_158 )
{
F_5 ( V_158 -> V_157 == 0 ) ;
if ( V_158 -> V_157 == 0 ) {
F_37 ( V_150 -> V_68 , V_150 -> V_573 ) ;
V_158 -> V_157 = V_528 ;
}
V_150 -> V_158 = * V_158 ;
F_88 ( V_150 , V_578 ) ;
}
void
F_262 ( struct V_149 * V_150 , enum V_506 V_380 )
{
F_5 ( V_380 == 0 ) ;
F_5 ( V_380 == V_381 ) ;
if ( V_150 ) {
V_150 -> V_158 . V_380 = V_380 ;
F_88 ( V_150 , V_609 ) ;
}
}
void
F_254 ( struct V_67 * V_68 , struct V_149 * V_571 )
{
struct V_211 * V_673 = F_96 ( V_68 ) ;
T_10 V_674 , V_675 ;
V_37 V_162 = ( V_37 ) V_571 -> V_158 . V_162 ;
V_675 = ( (struct V_676 * ) V_571 -> V_616 ) -> V_254 ;
V_674 = ( F_102 ( V_673 , V_571 -> V_158 . V_162 ) ) -> V_254 ;
F_102 ( V_673 , V_571 -> V_158 . V_162 ) -> V_677 =
V_571 -> V_677 = V_58 ;
F_263 ( V_68 , V_674 , V_675 , V_571 -> V_573 , V_162 ) ;
}
void
F_255 ( struct V_67 * V_68 , struct V_149 * V_571 )
{
struct V_211 * V_673 = F_96 ( V_68 ) ;
T_10 V_674 , V_675 ;
V_675 = ( (struct V_676 * ) V_571 -> V_616 ) -> V_254 ;
V_674 = ( F_102 ( V_673 , V_571 -> V_158 . V_162 ) ) -> V_254 ;
F_102 ( V_673 , V_571 -> V_158 . V_162 ) -> V_677 =
V_571 -> V_677 = V_59 ;
F_263 ( V_68 , V_674 , V_675 ,
V_678 , V_679 ) ;
}
static void
F_264 ( struct V_63 * V_64 , struct V_65 * V_66 ,
struct V_67 * V_68 )
{
struct V_680 * V_681 = F_265 ( V_68 ) ;
struct V_69 * V_682 = F_266 ( V_68 ) ;
struct V_71 * V_72 ;
T_2 V_73 , V_74 , V_683 , V_684 ;
T_3 V_685 = sizeof( struct V_686 ) ;
if ( V_64 -> V_79 . V_687 < V_688 )
V_64 -> V_79 . V_687 = V_688 ;
else if ( V_64 -> V_79 . V_687 > V_689 )
V_64 -> V_79 . V_687 = V_689 ;
V_684 = V_64 -> V_79 . V_687 ;
V_73 = F_20 ( V_684 , V_685 ) ;
V_683 = F_21 ( V_685 ) ;
F_22 (sgpg_mod, seg_ptr, nsegs, idx) {
if ( V_684 >= V_683 ) {
V_684 -= V_683 ;
F_23 ( V_66 , V_72 ,
V_683 * V_685 ) ;
} else
F_23 ( V_66 , V_72 ,
V_684 * V_685 ) ;
}
F_24 ( V_66 , V_682 ,
V_64 -> V_79 . V_687 * sizeof( struct V_690 ) ) ;
}
static void
F_267 ( struct V_67 * V_68 , void * V_83 , struct V_63 * V_64 ,
struct V_84 * V_85 )
{
struct V_680 * V_44 = F_265 ( V_68 ) ;
struct V_690 * V_691 ;
struct V_686 * V_692 ;
T_1 V_693 ;
struct V_71 * V_72 ;
T_3 V_685 = sizeof( struct V_686 ) ;
T_2 V_35 , V_74 , V_73 , V_683 , V_684 ;
union {
T_1 V_694 ;
union V_695 V_696 ;
} V_697 , V_698 ;
F_14 ( & V_44 -> V_699 ) ;
F_14 ( & V_44 -> V_700 ) ;
F_37 ( V_68 , V_64 -> V_79 . V_687 ) ;
V_44 -> V_701 = V_44 -> V_687 = V_64 -> V_79 . V_687 ;
V_684 = V_64 -> V_79 . V_687 ;
V_73 = F_20 ( V_684 , V_685 ) ;
V_691 = (struct V_690 * ) F_13 ( V_44 ) ;
F_22 (mod, seg_ptr, nsegs, idx) {
if ( ! F_149 ( V_72 ) )
break;
V_693 = F_268 ( F_150 ( V_72 ) ) -
F_150 ( V_72 ) ;
V_692 = (struct V_686 * )
( ( ( V_37 * ) F_149 ( V_72 ) ) + V_693 ) ;
V_697 . V_694 = F_150 ( V_72 ) + V_693 ;
F_5 ( V_697 . V_694 & ( V_685 - 1 ) ) ;
V_683 = ( V_72 -> V_702 - ( T_3 ) V_693 ) / V_685 ;
for ( V_35 = 0 ; V_684 > 0 && V_35 < V_683 ; V_35 ++ , V_684 -- ) {
memset ( V_691 , 0 , sizeof( * V_691 ) ) ;
memset ( V_692 , 0 , sizeof( * V_692 ) ) ;
V_691 -> V_692 = V_692 ;
V_698 . V_694 = F_269 ( V_697 . V_694 ) ;
V_691 -> V_697 = V_698 . V_696 ;
F_15 ( & V_691 -> V_56 , & V_44 -> V_699 ) ;
V_692 ++ ;
V_691 ++ ;
V_697 . V_694 += V_685 ;
}
}
F_13 ( V_44 ) = ( V_37 * ) V_691 ;
}
static void
F_270 ( struct V_67 * V_68 )
{
}
static void
F_271 ( struct V_67 * V_68 )
{
}
static void
F_272 ( struct V_67 * V_68 )
{
}
static void
F_273 ( struct V_67 * V_68 )
{
}
T_7
F_274 ( struct V_67 * V_68 , struct V_90 * V_699 , int V_703 )
{
struct V_680 * V_44 = F_265 ( V_68 ) ;
struct V_690 * V_691 ;
int V_35 ;
if ( V_44 -> V_701 < V_703 )
return V_704 ;
for ( V_35 = 0 ; V_35 < V_703 ; V_35 ++ ) {
F_35 ( & V_44 -> V_699 , & V_691 ) ;
F_5 ( ! V_691 ) ;
F_15 ( & V_691 -> V_56 , V_699 ) ;
}
V_44 -> V_701 -= V_703 ;
return V_134 ;
}
void
F_275 ( struct V_67 * V_68 , struct V_90 * V_699 , int V_705 )
{
struct V_680 * V_44 = F_265 ( V_68 ) ;
struct V_706 * V_121 ;
V_44 -> V_701 += V_705 ;
F_5 ( V_44 -> V_701 > V_44 -> V_687 ) ;
F_30 ( V_699 , & V_44 -> V_699 ) ;
if ( F_73 ( & V_44 -> V_700 ) )
return;
do {
V_121 = F_276 ( & V_44 -> V_700 ) ;
if ( V_44 -> V_701 < V_121 -> V_705 )
V_705 = V_44 -> V_701 ;
else
V_705 = V_121 -> V_705 ;
F_274 ( V_68 , & V_121 -> V_699 , V_705 ) ;
V_121 -> V_705 -= V_705 ;
if ( V_121 -> V_705 == 0 ) {
F_41 ( & V_121 -> V_56 ) ;
V_121 -> V_174 ( V_121 -> V_125 ) ;
}
} while ( V_44 -> V_701 && ! F_73 ( & V_44 -> V_700 ) );
}
void
F_277 ( struct V_67 * V_68 , struct V_706 * V_121 , int V_705 )
{
struct V_680 * V_44 = F_265 ( V_68 ) ;
F_5 ( V_705 <= 0 ) ;
F_5 ( V_705 <= V_44 -> V_701 ) ;
V_121 -> V_707 = V_121 -> V_705 = V_705 ;
if ( V_44 -> V_701 ) {
F_5 ( ! F_73 ( & V_44 -> V_700 ) ) ;
F_30 ( & V_44 -> V_699 , & V_121 -> V_699 ) ;
V_121 -> V_705 -= V_44 -> V_701 ;
V_44 -> V_701 = 0 ;
}
F_15 ( & V_121 -> V_56 , & V_44 -> V_700 ) ;
}
void
F_278 ( struct V_67 * V_68 , struct V_706 * V_121 )
{
struct V_680 * V_44 = F_265 ( V_68 ) ;
F_5 ( ! F_40 ( & V_44 -> V_700 , V_121 ) ) ;
F_41 ( & V_121 -> V_56 ) ;
if ( V_121 -> V_707 != V_121 -> V_705 )
F_275 ( V_68 , & V_121 -> V_699 ,
V_121 -> V_707 - V_121 -> V_705 ) ;
}
void
F_279 ( struct V_706 * V_121 , void (* V_174) ( void * V_125 ) ,
void * V_125 )
{
F_14 ( & V_121 -> V_699 ) ;
V_121 -> V_174 = V_174 ;
V_121 -> V_125 = V_125 ;
}
static void
F_280 ( void * V_125 , T_4 V_130 )
{
struct V_708 * V_709 = V_125 ;
struct V_710 * V_711 = F_281 ( V_709 -> V_68 ) ;
if ( V_130 )
V_711 -> V_712 ( V_711 -> V_125 , V_709 ) ;
}
static void
F_282 ( struct V_710 * V_711 )
{
struct V_713 * V_714 ;
T_2 V_35 ;
T_2 V_715 ;
V_711 -> V_716 = (struct V_713 * ) F_13 ( V_711 ) ;
V_714 = V_711 -> V_716 ;
for ( V_35 = 0 , V_714 = V_711 -> V_716 ; V_35 < V_711 -> V_717 ;
V_35 ++ , V_714 ++ ) {
memset ( V_714 , 0 , sizeof( struct V_713 ) ) ;
V_714 -> V_718 = V_35 ;
V_715 = sizeof( struct V_719 ) ;
V_714 -> V_715 = F_55 ( V_715 ) ;
F_53 ( V_714 -> V_152 , V_720 , V_721 ,
F_54 ( V_711 -> V_68 ) ) ;
F_58 ( & V_714 -> V_722 , V_715 , F_283 ( V_711 , V_35 ) ) ;
}
F_13 ( V_711 ) = ( V_37 * ) V_714 ;
}
static void
F_284 ( struct V_710 * V_711 )
{
T_2 V_35 ;
struct V_708 * V_709 ;
V_711 -> V_723 = (struct V_708 * ) F_13 ( V_711 ) ;
for ( V_35 = 0 , V_709 = V_711 -> V_723 ; V_35 < V_711 -> V_717 ; V_35 ++ , V_709 ++ ) {
memset ( V_709 , 0 , sizeof( struct V_708 ) ) ;
V_709 -> V_68 = V_711 -> V_68 ;
V_709 -> V_724 = V_35 ;
V_709 -> V_725 = V_726 ;
V_709 -> V_727 = F_66 ( V_711 , V_35 , V_726 ) ;
V_709 -> V_728 = F_283 ( V_711 , V_35 ) ;
F_15 ( & V_709 -> V_56 , & V_711 -> V_729 ) ;
}
F_13 ( V_711 ) = ( V_37 * ) V_709 ;
}
static void
F_285 ( struct V_710 * V_711 )
{
F_284 ( V_711 ) ;
F_282 ( V_711 ) ;
}
static void
F_286 ( struct V_63 * V_64 , struct V_65 * V_66 ,
struct V_67 * V_68 )
{
struct V_710 * V_711 = F_281 ( V_68 ) ;
struct V_69 * V_730 = F_287 ( V_68 ) ;
T_3 V_717 = V_64 -> V_76 . V_731 ;
struct V_71 * V_72 ;
T_2 V_73 , V_74 , V_732 = 0 ;
V_73 = F_20 ( V_717 , V_726 ) ;
V_732 = F_21 ( V_726 ) ;
F_22 (ufm, seg_ptr, nsegs, idx) {
if ( V_717 >= V_732 ) {
V_717 -= V_732 ;
F_23 ( V_66 , V_72 ,
V_732 * V_726 ) ;
} else
F_23 ( V_66 , V_72 ,
V_717 * V_726 ) ;
}
F_24 ( V_66 , V_730 , V_64 -> V_76 . V_731 *
( sizeof( struct V_708 ) + sizeof( struct V_713 ) ) ) ;
}
static void
F_288 ( struct V_67 * V_68 , void * V_83 , struct V_63 * V_64 ,
struct V_84 * V_85 )
{
struct V_710 * V_711 = F_281 ( V_68 ) ;
V_711 -> V_68 = V_68 ;
V_711 -> V_717 = V_64 -> V_76 . V_731 ;
F_14 ( & V_711 -> V_729 ) ;
F_14 ( & V_711 -> V_733 ) ;
F_14 ( & V_711 -> V_734 ) ;
F_285 ( V_711 ) ;
}
static void
F_289 ( struct V_67 * V_68 )
{
}
static struct V_708 *
F_290 ( struct V_710 * V_735 )
{
struct V_708 * V_709 ;
F_35 ( & V_735 -> V_729 , & V_709 ) ;
return V_709 ;
}
static void
F_291 ( struct V_710 * V_735 , struct V_708 * V_709 )
{
F_15 ( & V_709 -> V_56 , & V_735 -> V_729 ) ;
}
static T_7
F_292 ( struct V_710 * V_711 , struct V_708 * V_709 )
{
struct V_713 * V_736 ;
V_736 = F_51 ( V_711 -> V_68 , V_142 ) ;
if ( ! V_736 )
return V_737 ;
memcpy ( V_736 , & V_711 -> V_716 [ V_709 -> V_724 ] ,
sizeof( struct V_713 ) ) ;
F_61 ( V_711 -> V_68 , V_142 , V_736 -> V_152 ) ;
F_37 ( V_711 -> V_68 , V_709 -> V_724 ) ;
F_15 ( & V_709 -> V_56 , & V_711 -> V_733 ) ;
return V_134 ;
}
static void
F_293 ( struct V_710 * V_735 )
{
struct V_708 * V_709 ;
while ( ( V_709 = F_290 ( V_735 ) ) != NULL ) {
if ( F_292 ( V_735 , V_709 ) != V_134 )
break;
}
}
static void
F_294 ( struct V_67 * V_68 , struct V_738 * V_248 )
{
struct V_710 * V_711 = F_281 ( V_68 ) ;
T_2 V_724 = V_248 -> V_718 ;
struct V_708 * V_709 = & V_711 -> V_723 [ V_724 ] ;
struct V_719 * V_739 ;
T_13 * V_740 ;
struct V_38 * V_135 ;
V_739 = (struct V_719 * )
F_66 ( V_711 , V_724 , V_709 -> V_725 ) ;
V_740 = & V_739 -> V_426 [ 0 ] ;
V_248 -> V_741 = F_44 ( V_248 -> V_741 ) ;
V_248 -> V_742 = F_44 ( V_248 -> V_742 ) ;
V_135 = (struct V_38 * ) V_739 ;
F_41 ( & V_709 -> V_56 ) ;
V_709 -> V_743 = V_740 ;
V_709 -> V_744 = V_248 -> V_742 ;
F_5 ( V_709 -> V_744 < sizeof( struct V_38 ) ) ;
if ( V_709 -> V_744 == sizeof( struct V_38 ) ) {
F_10 ( V_68 -> V_13 , V_745 , V_139 ,
V_709 -> V_744 , (struct V_38 * ) V_740 ) ;
} else {
T_3 V_42 = * ( ( T_3 * ) ( V_740 + sizeof( struct V_38 ) ) ) ;
F_11 ( V_68 -> V_13 , V_745 ,
V_139 , V_709 -> V_744 ,
(struct V_38 * ) V_740 , V_42 ) ;
}
if ( V_68 -> V_263 )
F_280 ( V_709 , V_58 ) ;
else
F_33 ( V_68 , & V_709 -> V_97 , F_280 , V_709 ) ;
}
static void
F_295 ( struct V_67 * V_68 )
{
}
static void
F_296 ( struct V_67 * V_68 )
{
struct V_710 * V_711 = F_281 ( V_68 ) ;
struct V_708 * V_709 ;
struct V_90 * V_56 , * V_91 ;
F_30 ( & V_711 -> V_734 , & V_711 -> V_729 ) ;
F_31 (qe, qen, &ufm->uf_posted_q) {
V_709 = (struct V_708 * ) V_56 ;
F_41 ( & V_709 -> V_56 ) ;
F_291 ( V_711 , V_709 ) ;
}
}
static void
F_297 ( struct V_67 * V_68 )
{
F_293 ( F_281 ( V_68 ) ) ;
}
void
F_298 ( struct V_67 * V_68 , T_14 V_712 , void * V_125 )
{
struct V_710 * V_711 = F_281 ( V_68 ) ;
V_711 -> V_712 = V_712 ;
V_711 -> V_125 = V_125 ;
}
void
F_299 ( struct V_708 * V_709 )
{
F_291 ( F_281 ( V_709 -> V_68 ) , V_709 ) ;
F_293 ( F_281 ( V_709 -> V_68 ) ) ;
}
void
F_300 ( struct V_67 * V_68 , struct V_175 * V_176 )
{
F_37 ( V_68 , V_176 -> V_177 . V_178 ) ;
switch ( V_176 -> V_177 . V_178 ) {
case V_746 :
F_294 ( V_68 , (struct V_738 * ) V_176 ) ;
break;
default:
F_37 ( V_68 , V_176 -> V_177 . V_178 ) ;
F_5 ( 1 ) ;
}
}
void
F_301 ( struct V_67 * V_68 , T_2 V_747 )
{
struct V_710 * V_44 = F_281 ( V_68 ) ;
struct V_90 * V_56 ;
int V_35 ;
for ( V_35 = 0 ; V_35 < ( V_44 -> V_717 - V_747 ) ; V_35 ++ ) {
F_80 ( & V_44 -> V_729 , & V_56 ) ;
F_15 ( V_56 , & V_44 -> V_734 ) ;
}
}
static void
F_302 ( struct V_748 * V_749 )
{
struct V_277 * V_278 = F_152 ( V_749 -> V_68 ) ;
if ( V_749 -> V_750 . V_751 )
V_278 -> V_497 = V_58 ;
else
V_278 -> V_497 = V_59 ;
}
static void
F_303 ( struct V_63 * V_64 , struct V_65 * V_752 ,
struct V_67 * V_68 )
{
}
static void
F_304 ( struct V_67 * V_68 , void * V_83 , struct V_63 * V_64 ,
struct V_84 * V_85 )
{
struct V_748 * V_749 = F_305 ( V_68 ) ;
struct V_753 * V_754 = & V_749 -> V_754 ;
V_749 -> V_68 = V_68 ;
V_749 -> V_755 = V_68 -> V_755 ;
V_754 -> V_68 = V_68 ;
F_83 ( V_754 , V_756 ) ;
F_16 ( & V_754 -> V_302 , V_757 , V_754 ) ;
V_754 -> V_174 = NULL ;
V_754 -> V_125 = NULL ;
V_754 -> V_758 = V_759 ;
memset ( & V_754 -> V_760 , 0 , sizeof( struct V_761 ) ) ;
}
static void
F_306 ( struct V_67 * V_68 )
{
struct V_748 * V_749 = F_305 ( V_68 ) ;
struct V_753 * V_754 = & V_749 -> V_754 ;
F_37 ( V_749 , V_749 -> V_750 . V_751 ) ;
if ( V_749 -> V_750 . V_751 ) {
V_749 -> V_750 . V_198 = V_95 ;
V_749 -> V_750 . V_174 ( V_749 -> V_750 . V_125 , V_749 -> V_750 . V_198 ) ;
V_749 -> V_750 . V_751 = 0 ;
F_302 ( V_749 ) ;
}
F_88 ( V_754 , V_762 ) ;
}
static void
F_307 ( struct V_67 * V_68 )
{
}
static void
F_308 ( struct V_67 * V_68 )
{
}
static void
F_309 ( struct V_67 * V_68 )
{
}
static void
F_310 ( void * V_125 )
{
struct V_748 * V_749 = V_125 ;
struct V_763 * V_764 = V_749 -> V_765 . V_760 ;
F_37 ( V_749 , V_749 -> V_765 . V_766 ) ;
F_37 ( V_749 , V_749 -> V_765 . V_241 ) ;
V_749 -> V_765 . V_767 = 0 ;
V_764 -> V_198 = V_441 ;
V_764 -> V_241 = V_768 - V_749 -> V_765 . V_241 ;
if ( V_749 -> V_765 . V_766 )
V_764 -> V_769 = V_749 -> V_765 . V_766 ;
F_37 ( V_749 , V_441 ) ;
V_749 -> V_765 . V_198 = V_441 ;
V_749 -> V_765 . V_174 ( V_749 -> V_765 . V_125 , V_749 -> V_765 . V_198 ) ;
V_749 -> V_765 . V_751 = 0 ;
}
static T_7
F_311 ( struct V_748 * V_749 )
{
T_3 V_35 ;
struct V_770 * V_100 ;
V_100 = F_51 ( V_749 -> V_68 , V_749 -> V_765 . V_769 ) ;
if ( ! V_100 )
return V_548 ;
F_53 ( V_100 -> V_152 , V_771 , V_772 ,
F_54 ( V_749 -> V_68 ) ) ;
for ( V_35 = 0 ; V_35 < V_773 ; V_35 ++ )
V_100 -> V_435 [ V_35 ] = V_774 ;
F_37 ( V_749 , V_749 -> V_765 . V_769 ) ;
F_61 ( V_749 -> V_68 , V_749 -> V_765 . V_769 , V_100 -> V_152 ) ;
return V_134 ;
}
static void
F_312 ( struct V_748 * V_749 ,
T_15 * V_220 )
{
struct V_763 * V_764 = V_749 -> V_765 . V_760 ;
T_7 V_198 = V_134 ;
int V_35 ;
if ( ! V_749 -> V_765 . V_767 ) {
F_37 ( V_749 , V_749 -> V_765 . V_767 ) ;
return;
}
V_749 -> V_765 . V_241 -- ;
for ( V_35 = 0 ; V_35 < V_773 ; V_35 ++ ) {
if ( V_220 -> V_435 [ V_35 ] != ~ ( V_774 ) ) {
V_764 -> V_198 = V_775 ;
break;
}
}
if ( V_764 -> V_198 == V_134 ) {
if ( V_749 -> V_765 . V_241 > 0 ) {
V_198 = F_311 ( V_749 ) ;
if ( V_198 == V_134 )
return;
else
V_764 -> V_198 = V_198 ;
} else if ( V_749 -> V_765 . V_766 > 0 &&
V_749 -> V_765 . V_769 < ( V_776 - 1 ) ) {
V_749 -> V_765 . V_241 = V_768 ;
V_749 -> V_765 . V_769 ++ ;
V_198 = F_311 ( V_749 ) ;
if ( V_198 == V_134 )
return;
else
V_764 -> V_198 = V_198 ;
}
}
if ( V_749 -> V_765 . V_767 ) {
F_179 ( & V_749 -> V_765 . V_490 ) ;
V_749 -> V_765 . V_767 = 0 ;
}
V_764 -> V_769 = V_749 -> V_765 . V_769 ;
V_764 -> V_241 = V_768 - V_749 -> V_765 . V_241 ;
F_37 ( V_749 , V_764 -> V_241 ) ;
F_37 ( V_749 , V_764 -> V_198 ) ;
V_749 -> V_765 . V_198 = V_764 -> V_198 ;
V_749 -> V_765 . V_174 ( V_749 -> V_765 . V_125 , V_749 -> V_765 . V_198 ) ;
V_749 -> V_765 . V_751 = 0 ;
}
static void
F_313 ( struct V_748 * V_749 ,
struct V_777 * V_220 )
{
struct V_778 * V_764 = V_749 -> V_750 . V_760 ;
V_764 -> V_779 = F_45 ( V_220 -> V_764 . V_779 ) ;
V_764 -> V_780 = F_45 ( V_220 -> V_764 . V_780 ) ;
V_764 -> V_781 = F_45 ( V_220 -> V_764 . V_781 ) ;
V_764 -> V_782 = F_45 ( V_220 -> V_764 . V_782 ) ;
V_764 -> V_783 = F_45 ( V_220 -> V_764 . V_783 ) ;
V_764 -> V_198 = V_220 -> V_764 . V_198 ;
V_749 -> V_750 . V_198 = V_220 -> V_764 . V_198 ;
F_37 ( V_749 , V_749 -> V_750 . V_198 ) ;
V_749 -> V_750 . V_174 ( V_749 -> V_750 . V_125 , V_749 -> V_750 . V_198 ) ;
V_749 -> V_750 . V_751 = 0 ;
F_302 ( V_749 ) ;
}
static T_7
F_314 ( struct V_748 * V_749 ,
struct V_784 * V_785 )
{
struct V_786 * V_787 ;
V_787 = F_51 ( V_749 -> V_68 , V_788 ) ;
if ( ! V_787 )
return V_548 ;
F_53 ( V_787 -> V_152 , V_771 , V_789 ,
F_54 ( V_749 -> V_68 ) ) ;
V_787 -> V_790 = V_785 -> V_790 ;
V_787 -> V_380 = V_785 -> V_380 ;
V_787 -> V_791 = V_785 -> V_791 ;
V_787 -> V_792 = V_785 -> V_792 ;
F_61 ( V_749 -> V_68 , V_788 , V_787 -> V_152 ) ;
F_37 ( V_749 , V_785 -> V_790 ) ;
F_37 ( V_749 , V_785 -> V_380 ) ;
F_37 ( V_749 , V_785 -> V_791 ) ;
F_37 ( V_749 , V_785 -> V_792 ) ;
return V_134 ;
}
void
F_315 ( struct V_67 * V_68 , struct V_175 * V_176 )
{
struct V_748 * V_749 = F_305 ( V_68 ) ;
switch ( V_176 -> V_177 . V_178 ) {
case V_793 :
F_313 ( V_749 ,
(struct V_777 * ) V_176 ) ;
break;
case V_794 :
F_312 ( V_749 , ( T_15 * ) V_176 ) ;
break;
case V_795 :
F_316 ( & V_749 -> V_754 ,
(struct V_796 * ) V_176 ) ;
break;
case V_797 :
F_317 ( & V_749 -> V_754 ,
(struct V_798 * ) V_176 ) ;
break;
default:
F_37 ( V_749 , V_176 -> V_177 . V_178 ) ;
F_5 ( 1 ) ;
}
}
T_7
F_318 ( struct V_67 * V_68 , enum V_799 V_800 ,
enum V_506 V_380 , T_3 V_801 , T_3 V_802 ,
struct V_778 * V_760 , T_16 V_174 ,
void * V_125 )
{
struct V_784 V_785 ;
struct V_532 V_327 ;
T_7 V_198 ;
struct V_748 * V_749 = F_305 ( V_68 ) ;
if ( ! F_210 ( V_68 ) )
return V_547 ;
if ( F_176 ( V_68 ) ) {
F_37 ( V_749 , V_495 ) ;
return V_495 ;
}
if ( F_213 ( V_68 ) == V_59 ) {
F_37 ( V_749 , V_800 ) ;
return V_803 ;
}
if ( F_185 ( & V_68 -> V_264 ) == V_510 ) {
if ( ! ( V_380 == V_384 ||
V_380 == V_512 ||
V_380 == V_513 ||
V_380 == V_514 ||
V_380 == V_508 ||
V_380 == V_381 ) ) {
F_37 ( V_749 , V_380 ) ;
return V_509 ;
}
F_205 ( V_68 , & V_327 ) ;
F_37 ( V_749 , V_327 . V_538 ) ;
if ( V_380 > V_327 . V_538 )
return V_509 ;
} else {
if ( V_380 != V_515 ) {
F_37 ( V_749 , V_380 ) ;
return V_509 ;
}
}
if ( ( V_380 == V_384 ) &&
( F_186 ( V_68 -> V_264 . V_85 . V_511 ) ) ) {
F_37 ( V_749 , V_380 ) ;
return V_509 ;
}
if ( F_191 ( V_68 -> V_264 . V_327 -> V_521 ) ) {
if ( F_185 ( & V_68 -> V_264 ) == V_510 ) {
if ( ! ( V_380 == V_384 ||
V_380 == V_512 ||
V_380 == V_513 ||
V_380 == V_514 ||
V_380 == V_508 ||
V_380 == V_381 ) )
return V_509 ;
} else {
if ( V_380 != V_515 )
return V_509 ;
}
}
if ( F_192 ( V_68 ) ) {
F_37 ( V_749 , V_749 -> V_750 . V_751 ) ;
return V_804 ;
}
if ( V_749 -> V_750 . V_751 ) {
F_37 ( V_749 , V_749 -> V_750 . V_751 ) ;
return V_548 ;
}
V_749 -> V_750 . V_751 = 1 ;
V_785 . V_790 = V_800 ;
V_785 . V_380 = V_380 ;
V_785 . V_791 = V_801 ;
V_785 . V_792 = V_802 ;
V_749 -> V_750 . V_760 = V_760 ;
V_749 -> V_750 . V_174 = V_174 ;
V_749 -> V_750 . V_125 = V_125 ;
memset ( V_760 , 0 , sizeof( struct V_778 ) ) ;
F_302 ( V_749 ) ;
V_198 = F_314 ( V_749 , & V_785 ) ;
return V_198 ;
}
T_7
F_319 ( struct V_67 * V_68 , T_3 V_805 , T_3 V_769 ,
struct V_763 * V_760 , T_16 V_174 ,
void * V_125 )
{
struct V_748 * V_749 = F_305 ( V_68 ) ;
T_7 V_198 ;
F_37 ( V_749 , V_805 ) ;
F_37 ( V_749 , V_769 ) ;
if ( ! V_805 && ! F_210 ( V_68 ) )
return V_547 ;
if ( V_749 -> V_765 . V_751 ) {
F_37 ( V_749 , V_749 -> V_765 . V_751 ) ;
return V_548 ;
}
V_749 -> V_765 . V_751 = 1 ;
V_749 -> V_765 . V_174 = V_174 ;
V_749 -> V_765 . V_125 = V_125 ;
V_749 -> V_765 . V_760 = V_760 ;
V_749 -> V_765 . V_241 = V_768 ;
V_749 -> V_765 . V_760 -> V_198 = V_134 ;
V_749 -> V_765 . V_760 -> V_241 = 0 ;
if ( V_769 < V_776 ) {
V_749 -> V_765 . V_760 -> V_769 = ( V_37 ) V_769 ;
V_749 -> V_765 . V_769 = ( V_37 ) V_769 ;
V_749 -> V_765 . V_766 = 0 ;
} else {
V_749 -> V_765 . V_760 -> V_769 = 0 ;
V_749 -> V_765 . V_769 = 0 ;
V_749 -> V_765 . V_766 = 1 ;
}
V_198 = F_311 ( V_749 ) ;
if ( V_198 == V_134 ) {
F_211 ( V_68 , & V_749 -> V_765 . V_490 ,
F_310 , V_749 ,
V_806 ) ;
V_749 -> V_765 . V_767 = 1 ;
}
return V_198 ;
}
T_7
F_320 ( struct V_67 * V_68 )
{
struct V_748 * V_749 = F_305 ( V_68 ) ;
return V_749 -> V_750 . V_751 ? V_498 : V_134 ;
}
static void
F_321 ( struct V_753 * V_754 , T_7 V_807 )
{
if ( V_754 -> V_174 != NULL ) {
V_754 -> V_174 ( V_754 -> V_125 , V_807 ) ;
V_754 -> V_174 = NULL ;
V_754 -> V_125 = NULL ;
}
}
static void
V_756 ( struct V_753 * V_754 , enum V_808 V_25 )
{
F_37 ( V_754 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_809 :
F_223 ( V_754 -> V_68 ) ;
if ( F_322 ( V_754 , V_810 ) )
F_83 ( V_754 , V_811 ) ;
else
F_83 ( V_754 , V_812 ) ;
break;
case V_813 :
break;
case V_762 :
break;
case V_814 :
if ( V_754 -> V_324 . V_445 . V_336 == V_815 ) {
F_226 ( V_754 -> V_68 ) ;
V_754 -> V_816 = V_58 ;
V_754 -> V_758 = V_817 ;
F_83 ( V_754 , V_818 ) ;
} else {
F_37 ( V_754 -> V_68 , V_754 -> V_324 . V_445 . V_336 ) ;
F_5 ( 1 ) ;
}
break;
default:
F_87 ( V_754 -> V_68 , V_25 ) ;
}
}
static void
V_812 ( struct V_753 * V_754 ,
enum V_808 V_25 )
{
F_37 ( V_754 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_819 :
F_83 ( V_754 , V_811 ) ;
F_322 ( V_754 , V_810 ) ;
break;
case V_762 :
F_76 ( & V_754 -> V_302 ) ;
F_83 ( V_754 , V_756 ) ;
F_321 ( V_754 , V_737 ) ;
break;
default:
F_87 ( V_754 -> V_68 , V_25 ) ;
}
}
static void
V_811 ( struct V_753 * V_754 , enum V_808 V_25 )
{
F_37 ( V_754 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_820 :
memset ( & V_754 -> V_760 , 0 ,
sizeof( struct V_761 ) ) ;
if ( V_754 -> V_324 . V_220 . V_198 == V_821 ) {
V_754 -> V_758 = V_822 ;
} else {
V_754 -> V_758 = V_823 ;
F_323 ( V_754 , V_824 ) ;
}
F_83 ( V_754 , V_818 ) ;
break;
case V_825 :
V_754 -> V_758 = V_759 ;
F_225 ( V_754 -> V_68 ) ;
F_83 ( V_754 , V_756 ) ;
break;
case V_762 :
F_83 ( V_754 , V_756 ) ;
F_321 ( V_754 , V_737 ) ;
break;
default:
F_87 ( V_754 -> V_68 , V_25 ) ;
}
}
static void
V_818 ( struct V_753 * V_754 , enum V_808 V_25 )
{
F_37 ( V_754 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_826 :
if ( F_322 ( V_754 , V_827 ) )
F_83 ( V_754 , V_828 ) ;
else
F_83 ( V_754 , V_829 ) ;
break;
case V_813 :
F_225 ( V_754 -> V_68 ) ;
if ( F_322 ( V_754 , V_830 ) )
F_83 ( V_754 , V_831 ) ;
else
F_83 ( V_754 , V_832 ) ;
break;
case V_762 :
F_83 ( V_754 , V_756 ) ;
break;
case V_814 :
switch ( V_754 -> V_324 . V_445 . V_336 ) {
case V_833 :
V_754 -> V_758 = V_834 ;
break;
case V_835 :
V_754 -> V_758 = V_823 ;
break;
case V_836 :
case V_837 :
break;
case V_838 :
V_754 -> V_758 = V_822 ;
break;
case V_839 :
F_227 ( V_754 -> V_68 ) ;
if ( F_322 ( V_754 , V_840 ) )
F_83 ( V_754 ,
V_841 ) ;
else
F_83 ( V_754 ,
V_842 ) ;
break;
case V_843 :
F_227 ( V_754 -> V_68 ) ;
F_83 ( V_754 , V_756 ) ;
V_754 -> V_816 = V_59 ;
break;
default:
F_37 ( V_754 -> V_68 , V_754 -> V_324 . V_445 . V_336 ) ;
F_87 ( V_754 -> V_68 , V_25 ) ;
}
break;
default:
F_87 ( V_754 -> V_68 , V_25 ) ;
}
}
static void
V_832 ( struct V_753 * V_754 ,
enum V_808 V_25 )
{
F_37 ( V_754 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_819 :
F_83 ( V_754 , V_831 ) ;
F_322 ( V_754 , V_830 ) ;
break;
case V_762 :
F_83 ( V_754 , V_756 ) ;
F_76 ( & V_754 -> V_302 ) ;
F_321 ( V_754 , V_134 ) ;
break;
case V_814 :
break;
default:
F_87 ( V_754 -> V_68 , V_25 ) ;
}
}
static void
V_831 ( struct V_753 * V_754 , enum V_808 V_25 )
{
F_37 ( V_754 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_820 :
V_754 -> V_758 = V_759 ;
F_83 ( V_754 , V_756 ) ;
break;
case V_762 :
F_83 ( V_754 , V_756 ) ;
F_321 ( V_754 , V_134 ) ;
break;
case V_814 :
break;
default:
F_87 ( V_754 -> V_68 , V_25 ) ;
}
}
static void
V_829 ( struct V_753 * V_754 ,
enum V_808 V_25 )
{
F_37 ( V_754 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_819 :
F_83 ( V_754 , V_828 ) ;
F_322 ( V_754 , V_827 ) ;
break;
case V_762 :
F_76 ( & V_754 -> V_302 ) ;
F_83 ( V_754 , V_756 ) ;
F_321 ( V_754 , V_737 ) ;
break;
default:
F_87 ( V_754 -> V_68 , V_25 ) ;
}
}
static void
V_828 ( struct V_753 * V_754 , enum V_808 V_25 )
{
F_37 ( V_754 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_820 :
memset ( & V_754 -> V_760 , 0 ,
sizeof( struct V_761 ) ) ;
if ( V_754 -> V_324 . V_220 . V_198 == V_821 ) {
V_754 -> V_758 = V_822 ;
} else {
V_754 -> V_758 = V_823 ;
F_323 ( V_754 , V_844 ) ;
}
case V_825 :
F_83 ( V_754 , V_818 ) ;
break;
case V_762 :
F_83 ( V_754 , V_756 ) ;
F_321 ( V_754 , V_737 ) ;
break;
default:
F_87 ( V_754 -> V_68 , V_25 ) ;
}
}
static void
V_841 ( struct V_753 * V_754 ,
enum V_808 V_25 )
{
F_37 ( V_754 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_814 :
switch ( V_754 -> V_324 . V_445 . V_336 ) {
case V_845 :
F_83 ( V_754 , V_756 ) ;
V_754 -> V_816 = V_59 ;
F_181 ( V_754 -> V_68 ) ;
break;
default:
F_37 ( V_754 -> V_68 , V_754 -> V_324 . V_445 . V_336 ) ;
F_87 ( V_754 -> V_68 , V_25 ) ;
}
break;
case V_762 :
F_83 ( V_754 , V_756 ) ;
F_321 ( V_754 , V_134 ) ;
break;
default:
F_87 ( V_754 -> V_68 , V_25 ) ;
}
}
static void
V_842 ( struct V_753 * V_754 ,
enum V_808 V_25 )
{
F_37 ( V_754 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_819 :
F_83 ( V_754 , V_841 ) ;
F_322 ( V_754 , V_840 ) ;
break;
case V_762 :
F_83 ( V_754 , V_756 ) ;
F_76 ( & V_754 -> V_302 ) ;
F_321 ( V_754 , V_134 ) ;
break;
case V_814 :
break;
default:
F_87 ( V_754 -> V_68 , V_25 ) ;
}
}
static T_4
F_322 ( struct V_753 * V_754 , enum V_846 V_100 )
{
struct V_847 * V_248 ;
V_248 = F_51 ( V_754 -> V_68 , V_788 ) ;
if ( ! V_248 ) {
F_70 ( V_754 -> V_68 , V_416 , & V_754 -> V_302 ) ;
return V_59 ;
}
F_53 ( V_248 -> V_152 , V_771 , V_848 ,
F_54 ( V_754 -> V_68 ) ) ;
V_248 -> V_100 = V_100 ;
if ( ( V_100 == V_810 ) || ( V_100 == V_827 ) ) {
V_248 -> V_801 = F_57 ( V_754 -> V_801 ) ;
V_248 -> V_849 = F_57 ( V_754 -> V_849 ) ;
}
F_61 ( V_754 -> V_68 , V_788 , V_248 -> V_152 ) ;
return V_58 ;
}
static void
V_757 ( void * V_125 )
{
struct V_753 * V_754 = V_125 ;
F_88 ( V_754 , V_819 ) ;
}
static void
F_316 ( struct V_753 * V_754 , struct V_796 * V_176 )
{
V_176 -> V_198 = F_57 ( V_176 -> V_198 ) ;
V_754 -> V_324 . V_220 . V_198 = V_176 -> V_198 ;
V_754 -> V_850 = V_176 -> V_254 ;
V_754 -> V_851 = V_176 -> V_255 ;
if ( ( V_176 -> V_198 == V_134 ) ||
( V_176 -> V_198 == V_852 ) ) {
F_37 ( V_754 -> V_68 , V_176 -> V_198 ) ;
F_37 ( V_754 -> V_68 , V_754 -> V_850 ) ;
F_37 ( V_754 -> V_68 , V_754 -> V_851 ) ;
F_88 ( V_754 , V_820 ) ;
} else {
F_37 ( V_754 -> V_68 , V_176 -> V_198 ) ;
F_88 ( V_754 , V_825 ) ;
}
F_321 ( V_754 , V_176 -> V_198 ) ;
}
static T_4
F_324 ( struct V_753 * V_754 )
{
if ( F_220 ( V_754 , V_811 ) ||
F_220 ( V_754 , V_812 ) ||
F_220 ( V_754 , V_831 ) ||
F_220 ( V_754 , V_832 ) ||
F_220 ( V_754 , V_828 ) ||
F_220 ( V_754 , V_829 ) ) {
return V_58 ;
} else {
return V_59 ;
}
}
static void
F_317 ( struct V_753 * V_754 , struct V_798 * V_176 )
{
int V_35 ;
T_13 V_853 ;
F_37 ( V_754 -> V_68 , V_176 -> V_336 ) ;
V_754 -> V_324 . V_445 . V_336 = V_176 -> V_336 ;
switch ( V_754 -> V_324 . V_445 . V_336 ) {
case V_833 :
V_754 -> V_760 . V_854 = F_2 () ;
F_37 ( V_754 -> V_68 , V_754 -> V_760 . V_854 ) ;
V_754 -> V_760 . V_198 = V_176 -> V_855 . V_856 . V_198 ;
F_37 ( V_754 -> V_68 , V_754 -> V_760 . V_198 ) ;
V_754 -> V_760 . V_857 =
F_57 ( V_176 -> V_855 . V_856 . V_858 ) ;
V_754 -> V_760 . V_859 =
F_57 ( V_176 -> V_855 . V_856 . V_860 ) ;
V_754 -> V_760 . V_861 =
F_44 ( V_176 -> V_855 . V_856 . V_862 ) ;
V_754 -> V_760 . V_863 = F_44 ( V_176 -> V_855 . V_856 . V_864 ) ;
V_754 -> V_760 . V_380 = V_176 -> V_855 . V_856 . V_380 ;
F_37 ( V_754 -> V_68 , V_754 -> V_760 . V_857 ) ;
F_37 ( V_754 -> V_68 , V_754 -> V_760 . V_859 ) ;
F_37 ( V_754 -> V_68 , V_754 -> V_760 . V_861 ) ;
F_37 ( V_754 -> V_68 , V_754 -> V_760 . V_863 ) ;
F_37 ( V_754 -> V_68 , V_754 -> V_760 . V_380 ) ;
for ( V_35 = V_865 ; V_35 < V_866 ; V_35 ++ ) {
V_754 -> V_760 . V_867 [ V_35 ] . V_198 =
V_176 -> V_855 . V_856 . V_868 [ V_35 ] ;
F_37 ( V_754 -> V_68 , V_754 -> V_760 . V_867 [ V_35 ] . V_198 ) ;
}
break;
case V_836 :
case V_815 :
memset ( & V_754 -> V_760 , 0 ,
sizeof( struct V_761 ) ) ;
break;
case V_835 :
memset ( & V_754 -> V_760 , 0 ,
sizeof( struct V_761 ) ) ;
V_754 -> V_850 = V_176 -> V_855 . V_869 . V_254 ;
V_754 -> V_851 = V_176 -> V_855 . V_869 . V_255 ;
V_754 -> V_801 = F_57 ( V_176 -> V_855 . V_869 . V_870 ) ;
F_323 ( V_754 , V_824 ) ;
break;
case V_837 :
V_853 = V_176 -> V_855 . V_869 . type ;
V_754 -> V_760 . V_867 [ V_853 ] . V_871 =
F_2 () ;
V_754 -> V_760 . V_867 [ V_853 ] . V_198 =
V_872 ;
F_37 ( V_754 -> V_68 , V_853 ) ;
F_37 ( V_754 -> V_68 ,
V_754 -> V_760 . V_867 [ V_853 ] . V_871 ) ;
break;
case V_838 :
case V_845 :
case V_839 :
case V_843 :
V_754 -> V_760 . V_198 = V_873 ;
break;
default:
F_87 ( V_754 -> V_68 , V_176 -> V_336 ) ;
}
F_88 ( V_754 , V_814 ) ;
}
T_7
F_325 ( struct V_67 * V_68 , T_3 V_801 , T_3 V_802 ,
T_16 V_174 , void * V_125 )
{
struct V_748 * V_749 = F_305 ( V_68 ) ;
struct V_753 * V_754 = & V_749 -> V_754 ;
if ( F_191 ( V_754 -> V_68 -> V_264 . V_327 -> V_521 ) ) {
F_37 ( V_754 -> V_68 , V_495 ) ;
return V_562 ;
}
if ( ! ( F_186 ( V_754 -> V_68 -> V_264 . V_85 . V_511 ) ) ) {
F_37 ( V_754 -> V_68 , V_754 -> V_68 -> V_264 . V_85 . V_511 ) ;
return V_565 ;
}
if ( ! F_210 ( V_68 ) )
return V_547 ;
if ( F_176 ( V_68 ) ) {
F_37 ( V_754 -> V_68 , V_495 ) ;
return V_495 ;
}
if ( F_185 ( & V_68 -> V_264 ) != V_510 ) {
F_37 ( V_754 -> V_68 , F_185 ( & V_68 -> V_264 ) ) ;
return V_874 ;
}
if ( ( F_195 ( V_68 ) == V_405 ) ||
( F_194 ( V_68 ) == V_405 ) ) {
F_37 ( V_754 -> V_68 , 0 ) ;
return V_563 ;
}
if ( F_190 ( V_68 ) ) {
F_37 ( V_754 -> V_68 , 0 ) ;
return V_520 ;
}
if ( F_320 ( V_68 ) ) {
F_37 ( V_754 -> V_68 , 0 ) ;
return V_498 ;
}
if ( ( F_213 ( V_68 ) == V_59 ) &&
( F_192 ( V_68 ) == V_59 ) ) {
F_37 ( V_754 -> V_68 , 0 ) ;
return V_803 ;
}
if ( V_754 -> V_816 )
return V_875 ;
if ( F_324 ( V_754 ) )
return V_548 ;
if ( F_220 ( V_754 , V_818 ) ) {
F_37 ( V_754 -> V_68 , 0 ) ;
return V_804 ;
}
F_37 ( V_754 -> V_68 , V_801 ) ;
F_37 ( V_754 -> V_68 , V_802 ) ;
V_754 -> V_801 = ( V_801 ) ? V_801 : V_876 ;
V_754 -> V_849 = ( V_802 ) ? V_802 : V_877 ;
V_754 -> V_174 = V_174 ;
V_754 -> V_125 = V_125 ;
F_88 ( V_754 , V_809 ) ;
return V_134 ;
}
T_7
F_326 ( struct V_67 * V_68 , T_16 V_174 , void * V_125 )
{
struct V_748 * V_749 = F_305 ( V_68 ) ;
struct V_753 * V_754 = & V_749 -> V_754 ;
if ( F_182 ( & V_68 -> V_264 ) )
return V_496 ;
if ( F_176 ( V_68 ) ) {
F_37 ( V_754 -> V_68 , V_495 ) ;
return V_495 ;
}
if ( V_754 -> V_816 ) {
return V_875 ;
}
if ( ( F_213 ( V_68 ) == V_59 ) &&
( F_192 ( V_68 ) == V_59 ) ) {
F_37 ( V_754 -> V_68 , 0 ) ;
return V_803 ;
}
if ( F_324 ( V_754 ) )
return V_548 ;
if ( F_220 ( V_754 , V_756 ) ) {
F_37 ( V_754 -> V_68 , 0 ) ;
return V_878 ;
}
V_754 -> V_174 = V_174 ;
V_754 -> V_125 = V_125 ;
F_88 ( V_754 , V_813 ) ;
return V_134 ;
}
T_7
F_327 ( struct V_67 * V_68 , T_3 V_801 , T_3 V_802 ,
T_16 V_174 , void * V_125 )
{
struct V_748 * V_749 = F_305 ( V_68 ) ;
struct V_753 * V_754 = & V_749 -> V_754 ;
if ( ! F_210 ( V_68 ) )
return V_547 ;
if ( V_754 -> V_816 )
return V_875 ;
if ( F_324 ( V_754 ) )
return V_548 ;
if ( ! F_220 ( V_754 , V_818 ) ) {
F_37 ( V_754 -> V_68 , 0 ) ;
return V_878 ;
} else {
if ( V_754 -> V_758 == V_822 )
return V_821 ;
if ( V_754 -> V_758 == V_823 )
return V_548 ;
F_5 ( V_754 -> V_758 != V_834 ) ;
}
F_37 ( V_754 -> V_68 , V_801 ) ;
F_37 ( V_754 -> V_68 , V_802 ) ;
V_754 -> V_801 = ( V_801 ) ? V_801 : V_876 ;
V_754 -> V_849 = ( V_802 ) ? V_802 : V_877 ;
V_754 -> V_174 = V_174 ;
V_754 -> V_125 = V_125 ;
F_88 ( V_754 , V_826 ) ;
return V_134 ;
}
T_7
F_328 ( struct V_67 * V_68 , struct V_761 * V_760 )
{
struct V_748 * V_749 = F_305 ( V_68 ) ;
struct V_753 * V_754 = & V_749 -> V_754 ;
if ( ! F_210 ( V_68 ) )
return V_547 ;
if ( F_324 ( V_754 ) )
return V_548 ;
if ( ! F_220 ( V_754 , V_818 ) ) {
F_37 ( V_754 -> V_68 , 0 ) ;
return V_878 ;
}
if ( V_754 -> V_758 == V_822 )
return V_821 ;
memcpy ( V_760 , & V_754 -> V_760 , sizeof( struct V_761 ) ) ;
return V_134 ;
}
