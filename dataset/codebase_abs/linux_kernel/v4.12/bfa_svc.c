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
void
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
void
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
void
F_26 ( struct V_67 * V_68 )
{
struct V_43 * V_44 = F_18 ( V_68 ) ;
struct V_45 * V_46 ;
struct V_90 * V_56 , * V_91 ;
F_27 ( & V_44 -> V_51 , & V_44 -> V_48 ) ;
F_27 ( & V_44 -> V_52 , & V_44 -> V_49 ) ;
F_28 (qe, qen, &mod->fcxp_active_q) {
V_46 = (struct V_45 * ) V_56 ;
if ( V_46 -> V_92 == NULL ) {
V_46 -> V_93 ( V_46 -> V_92 , V_46 , V_46 -> V_94 ,
V_95 , 0 , 0 , NULL ) ;
F_29 ( V_46 ) ;
} else {
V_46 -> V_96 = V_95 ;
F_30 ( V_68 , & V_46 -> V_97 ,
V_98 , V_46 ) ;
}
}
}
static struct V_45 *
F_31 ( struct V_43 * V_99 , T_4 V_100 )
{
struct V_45 * V_46 ;
if ( V_100 )
F_32 ( & V_99 -> V_48 , & V_46 ) ;
else
F_32 ( & V_99 -> V_49 , & V_46 ) ;
if ( V_46 )
F_15 ( & V_46 -> V_56 , & V_99 -> V_50 ) ;
return V_46 ;
}
static void
F_33 ( struct V_45 * V_46 ,
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
F_34 ( V_68 , V_46 -> V_55 ) ;
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
F_35 ( struct V_45 * V_46 ,
void * V_92 , struct V_67 * V_68 , int V_110 ,
int V_111 , T_5 V_112 ,
T_6 V_113 ,
T_5 V_114 ,
T_6 V_115 )
{
F_5 ( V_68 == NULL ) ;
F_34 ( V_68 , V_46 -> V_55 ) ;
V_46 -> V_92 = V_92 ;
F_33 ( V_46 , V_68 ,
& V_46 -> V_116 , & V_46 -> V_110 , & V_46 -> V_112 ,
& V_46 -> V_113 , & V_46 -> V_117 ,
V_110 , V_112 , V_113 ) ;
F_33 ( V_46 , V_68 ,
& V_46 -> V_118 , & V_46 -> V_111 , & V_46 -> V_114 ,
& V_46 -> V_115 , & V_46 -> V_119 ,
V_111 , V_114 , V_115 ) ;
}
static void
F_36 ( struct V_45 * V_46 )
{
struct V_43 * V_44 = V_46 -> V_54 ;
struct V_120 * V_121 ;
if ( V_46 -> V_57 )
F_32 ( & V_44 -> V_88 , & V_121 ) ;
else
F_32 ( & V_44 -> V_89 , & V_121 ) ;
if ( V_121 ) {
F_34 ( V_44 -> V_68 , V_46 -> V_55 ) ;
F_35 ( V_46 , V_121 -> V_92 , V_121 -> V_68 , V_121 -> V_110 ,
V_121 -> V_111 , V_121 -> V_112 ,
V_121 -> V_113 , V_121 -> V_114 ,
V_121 -> V_115 ) ;
V_121 -> V_122 ( V_121 -> V_123 , V_46 ) ;
return;
}
F_5 ( ! F_37 ( & V_44 -> V_50 , V_46 ) ) ;
F_38 ( & V_46 -> V_56 ) ;
if ( V_46 -> V_57 )
F_15 ( & V_46 -> V_56 , & V_44 -> V_48 ) ;
else
F_15 ( & V_46 -> V_56 , & V_44 -> V_49 ) ;
}
static void
F_39 ( void * V_124 , struct V_45 * V_46 , void * V_125 ,
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
F_29 ( V_46 ) ;
}
}
static void
F_40 ( struct V_67 * V_68 , struct V_132 * V_133 )
{
struct V_43 * V_44 = F_18 ( V_68 ) ;
struct V_45 * V_46 ;
T_2 V_55 = F_41 ( V_133 -> V_55 ) ;
F_34 ( V_68 , V_55 ) ;
V_133 -> V_127 = F_42 ( V_133 -> V_127 ) ;
if ( V_133 -> V_126 == V_134 )
V_133 -> V_131 = 0 ;
else
V_133 -> V_131 = F_42 ( V_133 -> V_131 ) ;
V_46 = F_43 ( V_44 , V_55 ) ;
F_5 ( V_46 -> V_93 == NULL ) ;
F_44 ( V_44 -> V_68 , V_46 , V_133 ) ;
if ( V_46 -> V_93 != NULL ) {
F_34 ( V_44 -> V_68 , ( NULL == V_46 -> V_92 ) ) ;
if ( V_46 -> V_92 == NULL ) {
V_46 -> V_93 ( V_46 -> V_92 , V_46 , V_46 -> V_94 ,
V_133 -> V_126 , V_133 -> V_127 ,
V_133 -> V_131 , & V_133 -> V_135 ) ;
F_29 ( V_46 ) ;
} else {
V_46 -> V_96 = V_133 -> V_126 ;
V_46 -> V_127 = V_133 -> V_127 ;
V_46 -> V_131 = V_133 -> V_131 ;
V_46 -> V_129 = V_133 -> V_135 ;
F_30 ( V_68 , & V_46 -> V_97 ,
V_98 , V_46 ) ;
}
} else {
F_34 ( V_68 , ( NULL == V_46 -> V_93 ) ) ;
}
}
static void
F_45 ( struct V_67 * V_68 , T_3 V_136 , struct V_45 * V_46 ,
struct V_38 * V_135 )
{
if ( V_136 > 0 ) {
if ( V_46 -> V_116 ) {
T_3 V_42 =
* ( ( T_3 * ) F_46 ( V_46 ) ) ;
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
F_44 ( struct V_67 * V_68 , struct V_45 * V_46 ,
struct V_132 * V_133 )
{
if ( V_133 -> V_127 > 0 ) {
if ( V_46 -> V_118 ) {
T_3 V_42 =
* ( ( T_3 * ) F_47 ( V_46 ) ) ;
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
V_141 = F_48 ( V_68 , V_142 ) ;
F_49 ( V_46 , V_141 ) ;
}
static void
F_49 ( struct V_45 * V_46 , struct V_140 * V_141 )
{
struct V_67 * V_68 = V_46 -> V_54 -> V_68 ;
struct V_143 * V_144 = & V_46 -> V_145 ;
struct V_146 * V_147 = & V_46 -> V_148 ;
struct V_149 * V_150 = V_144 -> V_151 ;
F_50 ( V_141 -> V_152 , V_153 , V_154 ,
F_51 ( V_68 ) ) ;
V_141 -> V_55 = F_52 ( V_46 -> V_55 ) ;
if ( V_150 ) {
V_141 -> V_155 = V_150 -> V_156 ;
V_141 -> V_157 = F_52 ( V_150 -> V_158 . V_157 ) ;
if ( V_141 -> V_157 == 0 )
V_141 -> V_157 = F_52 ( V_159 ) ;
} else {
V_141 -> V_155 = 0 ;
V_141 -> V_157 = F_52 ( V_159 ) ;
}
V_141 -> V_160 = F_52 ( V_144 -> V_160 ) ;
V_141 -> V_161 = F_53 ( V_68 , V_144 -> V_162 ) ;
V_141 -> V_163 = V_144 -> V_163 ;
V_141 -> V_164 = V_147 -> V_164 ;
V_141 -> V_165 = V_144 -> V_165 ;
V_141 -> V_135 = V_144 -> V_135 ;
V_141 -> V_166 = F_54 ( V_144 -> V_167 ) ;
V_141 -> V_168 = F_54 ( V_147 -> V_168 ) ;
if ( V_46 -> V_116 == 1 ) {
F_55 ( & V_141 -> V_169 , V_144 -> V_167 ,
F_56 ( V_46 ) ) ;
} else {
if ( V_46 -> V_110 > 0 ) {
F_5 ( V_46 -> V_110 != 1 ) ;
F_55 ( & V_141 -> V_169 , V_144 -> V_167 ,
V_46 -> V_112 ( V_46 -> V_92 , 0 ) ) ;
} else {
F_5 ( V_144 -> V_167 != 0 ) ;
F_55 ( & V_141 -> V_170 , 0 , 0 ) ;
}
}
if ( V_46 -> V_118 == 1 ) {
F_5 ( V_147 -> V_168 > V_82 ) ;
F_55 ( & V_141 -> V_170 , V_147 -> V_168 ,
F_57 ( V_46 ) ) ;
} else {
if ( V_46 -> V_111 > 0 ) {
F_5 ( V_46 -> V_111 != 1 ) ;
F_55 ( & V_141 -> V_170 , V_147 -> V_168 ,
V_46 -> V_114 ( V_46 -> V_92 , 0 ) ) ;
} else {
F_5 ( V_147 -> V_168 != 0 ) ;
F_55 ( & V_141 -> V_170 , 0 , 0 ) ;
}
}
F_45 ( V_68 , V_144 -> V_167 , V_46 , & V_144 -> V_135 ) ;
F_58 ( V_68 , V_142 , V_141 -> V_152 ) ;
F_34 ( V_68 , F_59 ( V_68 , V_142 ) ) ;
F_34 ( V_68 , F_60 ( V_68 , V_142 ) ) ;
}
struct V_45 *
F_61 ( void * V_92 , struct V_67 * V_68 , int V_110 ,
int V_111 , T_5 V_112 ,
T_6 V_113 ,
T_5 V_114 ,
T_6 V_115 , T_4 V_100 )
{
struct V_45 * V_46 = NULL ;
F_5 ( V_68 == NULL ) ;
V_46 = F_31 ( F_18 ( V_68 ) , V_100 ) ;
if ( V_46 == NULL )
return NULL ;
F_34 ( V_68 , V_46 -> V_55 ) ;
F_35 ( V_46 , V_92 , V_68 , V_110 , V_111 , V_112 ,
V_113 , V_114 , V_115 ) ;
return V_46 ;
}
void *
F_62 ( struct V_45 * V_46 )
{
struct V_43 * V_44 = V_46 -> V_54 ;
void * V_171 ;
F_5 ( V_46 -> V_116 != 1 ) ;
V_171 = F_63 ( V_44 , V_46 -> V_55 ,
V_44 -> V_86 + V_44 -> V_87 ) ;
return V_171 ;
}
T_3
F_64 ( struct V_45 * V_46 )
{
struct V_43 * V_44 = V_46 -> V_54 ;
return V_44 -> V_86 ;
}
void *
F_65 ( struct V_45 * V_46 )
{
struct V_43 * V_44 = V_46 -> V_54 ;
void * V_172 ;
F_5 ( V_46 -> V_118 != 1 ) ;
V_172 = F_63 ( V_44 , V_46 -> V_55 ,
V_44 -> V_86 + V_44 -> V_87 ) ;
return ( ( V_37 * ) V_172 ) + V_44 -> V_86 ;
}
void
F_29 ( struct V_45 * V_46 )
{
struct V_43 * V_44 = V_46 -> V_54 ;
F_5 ( V_46 == NULL ) ;
F_34 ( V_44 -> V_68 , V_46 -> V_55 ) ;
F_36 ( V_46 ) ;
}
void
F_66 ( struct V_45 * V_46 , struct V_149 * V_150 ,
T_2 V_160 , V_37 V_162 , T_4 V_165 , enum V_173 cos ,
T_3 V_136 , struct V_38 * V_135 , T_8 V_174 ,
void * V_125 , T_3 V_168 , V_37 V_164 )
{
struct V_67 * V_68 = V_46 -> V_54 -> V_68 ;
struct V_143 * V_144 = & V_46 -> V_145 ;
struct V_146 * V_147 = & V_46 -> V_148 ;
struct V_140 * V_141 ;
F_34 ( V_68 , V_46 -> V_55 ) ;
V_144 -> V_151 = V_150 ;
V_144 -> V_160 = V_160 ;
V_144 -> V_162 = V_162 ;
V_144 -> V_163 = cos ;
V_147 -> V_164 = V_164 ;
V_144 -> V_165 = V_165 ;
V_144 -> V_135 = * V_135 ;
V_144 -> V_167 = V_136 ;
V_147 -> V_168 = V_168 ;
V_46 -> V_93 = V_174 ? V_174 : F_39 ;
V_46 -> V_94 = V_125 ;
V_141 = F_48 ( V_68 , V_142 ) ;
if ( ! V_141 ) {
F_34 ( V_68 , V_46 -> V_55 ) ;
V_46 -> V_62 = V_58 ;
F_67 ( V_68 , V_142 , & V_46 -> V_60 ) ;
return;
}
F_49 ( V_46 , V_141 ) ;
}
T_7
F_68 ( struct V_45 * V_46 )
{
F_34 ( V_46 -> V_54 -> V_68 , V_46 -> V_55 ) ;
F_5 ( 1 ) ;
return V_134 ;
}
void
F_69 ( struct V_67 * V_68 , struct V_120 * V_121 ,
T_9 V_122 , void * V_123 ,
void * V_92 , int V_110 ,
int V_111 , T_5 V_112 ,
T_6 V_113 ,
T_5 V_114 ,
T_6 V_115 , T_4 V_100 )
{
struct V_43 * V_44 = F_18 ( V_68 ) ;
if ( V_100 )
F_5 ( ! F_70 ( & V_44 -> V_48 ) ) ;
else
F_5 ( ! F_70 ( & V_44 -> V_49 ) ) ;
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
F_71 ( struct V_67 * V_68 , struct V_120 * V_121 )
{
struct V_43 * V_44 = F_18 ( V_68 ) ;
F_5 ( ! F_37 ( & V_44 -> V_88 , V_121 ) ||
! F_37 ( & V_44 -> V_89 , V_121 ) ) ;
F_38 ( & V_121 -> V_56 ) ;
}
void
F_72 ( struct V_45 * V_46 )
{
if ( V_46 -> V_62 ) {
V_46 -> V_62 = V_59 ;
F_73 ( & V_46 -> V_60 ) ;
F_29 ( V_46 ) ;
return;
}
V_46 -> V_93 = F_39 ;
}
void
F_74 ( struct V_67 * V_68 , struct V_175 * V_176 )
{
switch ( V_176 -> V_177 . V_178 ) {
case V_179 :
F_40 ( V_68 , (struct V_132 * ) V_176 ) ;
break;
default:
F_34 ( V_68 , V_176 -> V_177 . V_178 ) ;
F_5 ( 1 ) ;
}
}
T_3
F_75 ( struct V_67 * V_68 )
{
struct V_43 * V_44 = F_18 ( V_68 ) ;
return V_44 -> V_87 ;
}
void
F_76 ( struct V_67 * V_68 , T_2 V_180 )
{
struct V_43 * V_44 = F_18 ( V_68 ) ;
struct V_90 * V_56 ;
int V_35 ;
for ( V_35 = 0 ; V_35 < ( V_44 -> V_47 - V_180 ) ; V_35 ++ ) {
if ( V_35 < ( ( V_44 -> V_47 - V_180 ) / 2 ) ) {
F_77 ( & V_44 -> V_48 , & V_56 ) ;
F_15 ( V_56 , & V_44 -> V_51 ) ;
} else {
F_77 ( & V_44 -> V_49 , & V_56 ) ;
F_15 ( V_56 , & V_44 -> V_52 ) ;
}
}
}
static void
F_78 ( struct V_181 * V_182 , enum V_183 V_25 )
{
F_34 ( V_182 -> V_68 , V_182 -> V_184 ) ;
F_34 ( V_182 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_185 :
if ( F_79 ( V_182 -> V_68 , V_182 -> V_186 ) ) {
F_80 ( V_182 , V_187 ) ;
F_67 ( V_182 -> V_68 , V_182 -> V_186 , & V_182 -> V_121 ) ;
} else {
F_80 ( V_182 , V_188 ) ;
F_81 ( V_182 ) ;
}
if ( V_182 -> V_189 )
F_8 ( V_182 -> V_68 -> V_13 , V_190 ,
V_191 , 0 , L_1 ) ;
else
F_8 ( V_182 -> V_68 -> V_13 , V_190 ,
V_191 , 0 , L_2 ) ;
break;
case V_192 :
F_82 ( V_182 ) ;
break;
case V_193 :
F_83 ( V_182 ) ;
break;
case V_194 :
case V_195 :
break;
case V_196 :
break;
case V_197 :
break;
default:
F_84 ( V_182 -> V_68 , V_25 ) ;
}
}
static void
V_188 ( struct V_181 * V_182 , enum V_183 V_25 )
{
F_34 ( V_182 -> V_68 , V_182 -> V_184 ) ;
F_34 ( V_182 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_196 :
if ( V_182 -> V_198 == V_134 ) {
F_80 ( V_182 , V_199 ) ;
if ( V_182 -> V_189 )
F_8 ( V_182 -> V_68 -> V_13 , V_190 ,
V_191 , 0 , L_3 ) ;
else
F_8 ( V_182 -> V_68 -> V_13 , V_190 ,
V_191 , 0 , L_4 ) ;
F_34 ( V_182 -> V_68 , V_182 -> V_200 ) ;
F_34 ( V_182 -> V_68 , V_182 -> V_201 ) ;
if ( ! V_182 -> V_200 && V_182 -> V_201 )
F_85 ( V_182 , V_197 ) ;
} else {
F_80 ( V_182 , F_78 ) ;
if ( V_182 -> V_189 )
F_8 ( V_182 -> V_68 -> V_13 , V_190 ,
V_191 , 0 ,
L_5 ) ;
else
F_8 ( V_182 -> V_68 -> V_13 , V_190 ,
V_191 , 0 ,
L_6 ) ;
}
F_86 ( V_182 ) ;
break;
case V_195 :
case V_193 :
F_80 ( V_182 , F_78 ) ;
break;
case V_197 :
F_34 ( V_182 -> V_68 , V_182 -> V_200 ) ;
F_34 ( V_182 -> V_68 , V_182 -> V_201 ) ;
break;
default:
F_84 ( V_182 -> V_68 , V_25 ) ;
}
}
static void
V_187 ( struct V_181 * V_182 , enum V_183 V_25 )
{
F_34 ( V_182 -> V_68 , V_182 -> V_184 ) ;
F_34 ( V_182 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_202 :
F_80 ( V_182 , V_188 ) ;
F_81 ( V_182 ) ;
break;
case V_195 :
case V_193 :
F_80 ( V_182 , F_78 ) ;
F_73 ( & V_182 -> V_121 ) ;
break;
case V_194 :
break;
default:
F_84 ( V_182 -> V_68 , V_25 ) ;
}
}
static void
V_199 ( struct V_181 * V_182 , enum V_183 V_25 )
{
F_34 ( V_182 -> V_68 , V_182 -> V_184 ) ;
F_34 ( V_182 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_192 :
if ( F_79 ( V_182 -> V_68 , V_182 -> V_186 ) ) {
F_80 ( V_182 , V_203 ) ;
F_67 ( V_182 -> V_68 , V_182 -> V_186 , & V_182 -> V_121 ) ;
} else {
F_80 ( V_182 , V_204 ) ;
F_87 ( V_182 ) ;
}
F_8 ( V_182 -> V_68 -> V_13 , V_190 ,
V_205 , 0 , L_7 ) ;
break;
case V_194 :
F_80 ( V_182 , F_78 ) ;
F_88 ( V_182 ) ;
F_8 ( V_182 -> V_68 -> V_13 , V_190 ,
V_206 , 0 , L_8 ) ;
break;
case V_197 :
if ( F_79 ( V_182 -> V_68 , V_182 -> V_186 ) ) {
F_80 ( V_182 , V_207 ) ;
F_67 ( V_182 -> V_68 , V_182 -> V_186 , & V_182 -> V_121 ) ;
} else
F_89 ( V_182 ) ;
break;
case V_195 :
case V_193 :
F_80 ( V_182 , F_78 ) ;
break;
default:
F_84 ( V_182 -> V_68 , V_25 ) ;
}
}
static void
V_207 ( struct V_181 * V_182 , enum V_183 V_25 )
{
F_34 ( V_182 -> V_68 , V_182 -> V_184 ) ;
F_34 ( V_182 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_202 :
F_80 ( V_182 , V_199 ) ;
F_89 ( V_182 ) ;
break;
case V_192 :
F_80 ( V_182 , V_203 ) ;
F_8 ( V_182 -> V_68 -> V_13 , V_190 ,
V_205 , 0 , L_7 ) ;
break;
case V_194 :
F_80 ( V_182 , F_78 ) ;
F_73 ( & V_182 -> V_121 ) ;
F_88 ( V_182 ) ;
F_8 ( V_182 -> V_68 -> V_13 , V_190 ,
V_206 , 0 , L_8 ) ;
break;
case V_195 :
case V_193 :
F_80 ( V_182 , F_78 ) ;
F_73 ( & V_182 -> V_121 ) ;
break;
default:
F_84 ( V_182 -> V_68 , V_25 ) ;
}
}
static void
V_204 ( struct V_181 * V_182 , enum V_183 V_25 )
{
F_34 ( V_182 -> V_68 , V_182 -> V_184 ) ;
F_34 ( V_182 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_196 :
case V_195 :
F_80 ( V_182 , F_78 ) ;
F_82 ( V_182 ) ;
break;
case V_193 :
F_80 ( V_182 , F_78 ) ;
break;
default:
F_84 ( V_182 -> V_68 , V_25 ) ;
}
}
static void
V_203 ( struct V_181 * V_182 , enum V_183 V_25 )
{
F_34 ( V_182 -> V_68 , V_182 -> V_184 ) ;
F_34 ( V_182 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_202 :
F_80 ( V_182 , V_204 ) ;
F_87 ( V_182 ) ;
break;
case V_195 :
case V_193 :
F_80 ( V_182 , F_78 ) ;
F_73 ( & V_182 -> V_121 ) ;
break;
default:
F_84 ( V_182 -> V_68 , V_25 ) ;
}
}
void
F_90 ( struct V_63 * V_64 , struct V_65 * V_66 ,
struct V_67 * V_68 )
{
struct V_69 * V_208 = F_91 ( V_68 ) ;
if ( V_64 -> V_79 . V_80 )
F_24 ( V_66 , V_208 ,
sizeof( struct V_181 ) * V_209 ) ;
else
F_24 ( V_66 , V_208 ,
sizeof( struct V_181 ) * V_210 ) ;
}
void
F_92 ( struct V_67 * V_68 , void * V_83 , struct V_63 * V_64 ,
struct V_84 * V_85 )
{
struct V_211 * V_44 = F_93 ( V_68 ) ;
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
void
F_94 ( struct V_67 * V_68 )
{
struct V_211 * V_44 = F_93 ( V_68 ) ;
struct V_181 * V_182 ;
struct V_90 * V_56 , * V_91 ;
F_28 (qe, qen, &mod->lps_active_q) {
V_182 = (struct V_181 * ) V_56 ;
F_85 ( V_182 , V_195 ) ;
}
F_28 (qe, qen, &mod->lps_login_q) {
V_182 = (struct V_181 * ) V_56 ;
F_85 ( V_182 , V_195 ) ;
}
F_27 ( & V_44 -> V_216 , & V_44 -> V_215 ) ;
}
static void
F_95 ( struct V_67 * V_68 , struct V_219 * V_220 )
{
struct V_211 * V_44 = F_93 ( V_68 ) ;
struct V_181 * V_182 ;
F_5 ( V_220 -> V_184 >= V_44 -> V_212 ) ;
V_182 = F_96 ( V_44 , V_220 -> V_184 ) ;
V_182 -> V_198 = V_220 -> V_198 ;
switch ( V_220 -> V_198 ) {
case V_134 :
V_182 -> V_221 = V_220 -> V_221 ;
V_182 -> V_200 = V_220 -> V_222 ;
if ( V_182 -> V_200 )
V_182 -> V_201 = V_220 -> V_201 ;
V_182 -> V_223 = V_220 -> V_223 ;
V_182 -> V_224 = F_41 ( V_220 -> V_225 ) ;
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
F_97 ( V_182 , V_220 -> V_238 ) ;
break;
default:
break;
}
F_38 ( & V_182 -> V_56 ) ;
F_15 ( & V_182 -> V_56 , & V_44 -> V_215 ) ;
F_85 ( V_182 , V_196 ) ;
}
static void
F_97 ( struct V_181 * V_240 , V_37 V_241 )
{
struct V_67 * V_68 = V_240 -> V_68 ;
struct V_211 * V_44 = F_93 ( V_68 ) ;
struct V_90 * V_56 , * V_242 ;
struct V_181 * V_182 ;
F_34 ( V_68 , V_241 ) ;
V_56 = F_98 ( V_240 ) ;
while ( V_241 && V_56 ) {
V_242 = F_98 ( V_56 ) ;
V_182 = (struct V_181 * ) V_56 ;
F_34 ( V_68 , V_182 -> V_184 ) ;
V_182 -> V_198 = V_240 -> V_198 ;
F_38 ( & V_182 -> V_56 ) ;
F_15 ( & V_182 -> V_56 , & V_44 -> V_215 ) ;
F_85 ( V_182 , V_196 ) ;
V_56 = V_242 ;
V_241 -- ;
}
}
static void
F_99 ( struct V_67 * V_68 , struct V_243 * V_220 )
{
struct V_211 * V_44 = F_93 ( V_68 ) ;
struct V_181 * V_182 ;
F_5 ( V_220 -> V_184 >= V_44 -> V_212 ) ;
V_182 = F_96 ( V_44 , V_220 -> V_184 ) ;
F_85 ( V_182 , V_196 ) ;
}
static void
F_100 ( struct V_67 * V_68 , struct V_244 * V_245 )
{
struct V_211 * V_44 = F_93 ( V_68 ) ;
struct V_181 * V_182 ;
V_182 = F_96 ( V_44 , V_245 -> V_184 ) ;
F_85 ( V_182 , V_194 ) ;
}
static void
V_218 ( void * V_246 )
{
struct V_181 * V_182 = V_246 ;
F_85 ( V_182 , V_202 ) ;
}
static void
F_83 ( struct V_181 * V_182 )
{
struct V_211 * V_44 = F_93 ( V_182 -> V_68 ) ;
V_182 -> V_201 = 0 ;
F_38 ( & V_182 -> V_56 ) ;
F_15 ( & V_182 -> V_56 , & V_44 -> V_214 ) ;
}
static void
F_81 ( struct V_181 * V_182 )
{
struct V_211 * V_44 = F_93 ( V_182 -> V_68 ) ;
struct V_247 * V_248 ;
V_248 = F_48 ( V_182 -> V_68 , V_182 -> V_186 ) ;
F_5 ( ! V_248 ) ;
F_50 ( V_248 -> V_152 , V_249 , V_250 ,
F_51 ( V_182 -> V_68 ) ) ;
V_248 -> V_184 = V_182 -> V_184 ;
V_248 -> V_251 = V_182 -> V_251 ;
V_248 -> V_252 = F_52 ( V_182 -> V_253 ) ;
V_248 -> V_254 = V_182 -> V_254 ;
V_248 -> V_255 = V_182 -> V_255 ;
V_248 -> V_189 = V_182 -> V_189 ;
V_248 -> V_256 = V_182 -> V_256 ;
F_58 ( V_182 -> V_68 , V_182 -> V_186 , V_248 -> V_152 ) ;
F_38 ( & V_182 -> V_56 ) ;
F_15 ( & V_182 -> V_56 , & V_44 -> V_216 ) ;
}
static void
F_87 ( struct V_181 * V_182 )
{
struct V_257 * V_248 ;
V_248 = F_48 ( V_182 -> V_68 , V_182 -> V_186 ) ;
F_5 ( ! V_248 ) ;
F_50 ( V_248 -> V_152 , V_249 , V_258 ,
F_51 ( V_182 -> V_68 ) ) ;
V_248 -> V_221 = V_182 -> V_221 ;
V_248 -> V_227 = V_182 -> V_254 ;
F_58 ( V_182 -> V_68 , V_182 -> V_186 , V_248 -> V_152 ) ;
}
static void
F_89 ( struct V_181 * V_182 )
{
struct V_259 * V_248 ;
V_248 = F_48 ( V_182 -> V_68 , V_182 -> V_186 ) ;
F_5 ( ! V_248 ) ;
F_50 ( V_248 -> V_152 , V_249 , V_260 ,
F_51 ( V_182 -> V_68 ) ) ;
V_248 -> V_221 = V_182 -> V_221 ;
V_248 -> V_201 = V_182 -> V_201 ;
F_58 ( V_182 -> V_68 , V_182 -> V_186 , V_248 -> V_152 ) ;
}
static void
F_101 ( void * V_261 , T_4 V_130 )
{
struct V_181 * V_182 = V_261 ;
if ( ! V_130 )
return;
if ( V_182 -> V_189 )
F_102 ( V_182 -> V_68 -> V_83 , V_182 -> V_262 , V_182 -> V_198 ) ;
else
F_103 ( V_182 -> V_68 -> V_83 , V_182 -> V_262 , V_182 -> V_198 ) ;
}
static void
F_86 ( struct V_181 * V_182 )
{
if ( ! V_182 -> V_68 -> V_263 ) {
F_30 ( V_182 -> V_68 , & V_182 -> V_97 , F_101 ,
V_182 ) ;
return;
}
if ( V_182 -> V_189 )
F_102 ( V_182 -> V_68 -> V_83 , V_182 -> V_262 , V_182 -> V_198 ) ;
else
F_103 ( V_182 -> V_68 -> V_83 , V_182 -> V_262 , V_182 -> V_198 ) ;
}
static void
F_104 ( void * V_261 , T_4 V_130 )
{
struct V_181 * V_182 = V_261 ;
if ( ! V_130 )
return;
if ( V_182 -> V_189 )
F_105 ( V_182 -> V_68 -> V_83 , V_182 -> V_262 ) ;
else
F_106 ( V_182 -> V_68 -> V_83 , V_182 -> V_262 ) ;
}
static void
F_82 ( struct V_181 * V_182 )
{
if ( ! V_182 -> V_68 -> V_263 ) {
F_30 ( V_182 -> V_68 , & V_182 -> V_97 , F_104 ,
V_182 ) ;
return;
}
if ( V_182 -> V_189 )
F_105 ( V_182 -> V_68 -> V_83 , V_182 -> V_262 ) ;
}
static void
F_107 ( void * V_261 , T_4 V_130 )
{
struct V_181 * V_182 = V_261 ;
if ( ! V_130 )
return;
if ( V_182 -> V_189 )
F_108 ( V_182 -> V_68 -> V_83 , V_182 -> V_262 ) ;
}
static void
F_88 ( struct V_181 * V_182 )
{
if ( ! V_182 -> V_68 -> V_263 ) {
F_30 ( V_182 -> V_68 , & V_182 -> V_97 , F_107 ,
V_182 ) ;
return;
}
if ( V_182 -> V_189 )
F_108 ( V_182 -> V_68 -> V_83 , V_182 -> V_262 ) ;
}
T_3
F_109 ( struct V_67 * V_68 )
{
if ( F_110 ( & V_68 -> V_264 ) == V_265 )
return V_266 ;
else
return V_267 ;
}
struct V_181 *
F_111 ( struct V_67 * V_68 )
{
struct V_211 * V_44 = F_93 ( V_68 ) ;
struct V_181 * V_182 = NULL ;
F_32 ( & V_44 -> V_214 , & V_182 ) ;
if ( V_182 == NULL )
return NULL ;
F_15 ( & V_182 -> V_56 , & V_44 -> V_215 ) ;
F_80 ( V_182 , F_78 ) ;
return V_182 ;
}
void
F_112 ( struct V_181 * V_182 )
{
F_85 ( V_182 , V_193 ) ;
}
void
F_113 ( struct V_181 * V_182 , void * V_262 , V_37 V_251 , T_2 V_253 ,
T_10 V_254 , T_10 V_255 , T_4 V_256 )
{
V_182 -> V_262 = V_262 ;
V_182 -> V_251 = V_251 ;
V_182 -> V_253 = V_253 ;
V_182 -> V_254 = V_254 ;
V_182 -> V_255 = V_255 ;
V_182 -> V_189 = V_59 ;
V_182 -> V_256 = V_256 ;
F_85 ( V_182 , V_185 ) ;
}
void
F_114 ( struct V_181 * V_182 , void * V_262 , T_2 V_253 , T_10 V_254 ,
T_10 V_255 )
{
V_182 -> V_262 = V_262 ;
V_182 -> V_251 = 0 ;
V_182 -> V_253 = V_253 ;
V_182 -> V_254 = V_254 ;
V_182 -> V_255 = V_255 ;
V_182 -> V_189 = V_58 ;
V_182 -> V_256 = V_59 ;
F_85 ( V_182 , V_185 ) ;
}
void
F_115 ( struct V_181 * V_182 )
{
F_85 ( V_182 , V_192 ) ;
}
V_37
F_53 ( struct V_67 * V_68 , V_37 V_162 )
{
struct V_211 * V_44 = F_93 ( V_68 ) ;
return F_96 ( V_44 , V_162 ) -> V_221 ;
}
V_37
F_116 ( struct V_67 * V_68 , T_3 V_268 )
{
struct V_211 * V_44 = F_93 ( V_68 ) ;
struct V_181 * V_182 ;
int V_35 ;
for ( V_35 = 0 , V_182 = V_44 -> V_213 ; V_35 < V_44 -> V_212 ; V_35 ++ , V_182 ++ ) {
if ( V_182 -> V_201 == V_268 )
return V_182 -> V_184 ;
}
return 0 ;
}
T_3
F_117 ( struct V_67 * V_68 )
{
struct V_211 * V_44 = F_93 ( V_68 ) ;
return F_96 ( V_44 , 0 ) -> V_201 ;
}
void
F_118 ( struct V_181 * V_182 , T_11 V_269 )
{
F_34 ( V_182 -> V_68 , V_182 -> V_184 ) ;
F_34 ( V_182 -> V_68 , V_269 ) ;
V_182 -> V_201 = V_269 ;
F_85 ( V_182 , V_197 ) ;
}
void
F_119 ( struct V_67 * V_68 , struct V_175 * V_248 )
{
union V_270 V_176 ;
F_34 ( V_68 , V_248 -> V_177 . V_178 ) ;
V_176 . V_176 = V_248 ;
switch ( V_248 -> V_177 . V_178 ) {
case V_271 :
F_95 ( V_68 , V_176 . V_272 ) ;
break;
case V_273 :
F_99 ( V_68 , V_176 . V_274 ) ;
break;
case V_275 :
F_100 ( V_68 , V_176 . V_276 ) ;
break;
default:
F_34 ( V_68 , V_248 -> V_177 . V_178 ) ;
F_5 ( 1 ) ;
}
}
static void
F_120 ( struct V_277 * V_278 , enum V_279 V_25 )
{
struct V_280 * V_83 = (struct V_280 * ) V_278 -> V_68 -> V_83 ;
struct V_281 * V_282 ;
F_121 ( V_83 , V_282 ) ;
if ( ! V_282 )
return;
V_282 -> V_283 . V_284 . V_285 = F_122 ( V_278 -> V_68 ) ;
V_282 -> V_283 . V_284 . V_254 = V_278 -> V_254 ;
F_123 ( V_282 , V_83 , ++ V_278 -> V_68 -> V_286 ,
V_287 , V_25 ) ;
}
static void
F_124 ( struct V_277 * V_278 ,
enum V_288 V_25 )
{
F_34 ( V_278 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_289 :
V_278 -> V_290 = V_58 ;
if ( F_125 ( V_278 ) ) {
F_34 ( V_278 -> V_68 , V_58 ) ;
F_80 ( V_278 , V_291 ) ;
} else {
F_34 ( V_278 -> V_68 , V_59 ) ;
F_80 ( V_278 ,
V_292 ) ;
}
break;
case V_293 :
break;
case V_294 :
F_80 ( V_278 , V_295 ) ;
break;
case V_296 :
F_80 ( V_278 , V_297 ) ;
break;
default:
F_84 ( V_278 -> V_68 , V_25 ) ;
}
}
static void
V_292 ( struct V_277 * V_278 ,
enum V_288 V_25 )
{
char V_298 [ V_299 ] ;
struct V_280 * V_83 = (struct V_280 * ) V_278 -> V_68 -> V_83 ;
F_34 ( V_278 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_300 :
F_80 ( V_278 , V_291 ) ;
F_125 ( V_278 ) ;
break;
case V_301 :
F_73 ( & V_278 -> V_302 ) ;
F_80 ( V_278 , V_303 ) ;
break;
case V_293 :
break;
case V_294 :
F_80 ( V_278 , V_295 ) ;
F_73 ( & V_278 -> V_302 ) ;
F_8 ( V_278 -> V_68 -> V_13 , V_304 ,
V_305 , 0 , L_9 ) ;
F_126 ( V_298 , V_278 -> V_254 ) ;
F_127 ( V_306 , V_83 , V_307 ,
L_10 , V_298 ) ;
F_120 ( V_278 , V_308 ) ;
break;
case V_309 :
case V_310 :
break;
case V_296 :
F_73 ( & V_278 -> V_302 ) ;
F_80 ( V_278 , V_297 ) ;
break;
case V_311 :
F_128 ( V_278 ) ;
F_120 ( V_278 , V_312 ) ;
F_80 ( V_278 , V_313 ) ;
break;
default:
F_84 ( V_278 -> V_68 , V_25 ) ;
}
}
static void
V_291 ( struct V_277 * V_278 ,
enum V_288 V_25 )
{
char V_298 [ V_299 ] ;
struct V_280 * V_83 = (struct V_280 * ) V_278 -> V_68 -> V_83 ;
F_34 ( V_278 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_314 :
case V_310 :
F_80 ( V_278 , V_315 ) ;
break;
case V_309 :
F_129 ( V_278 ) ;
F_80 ( V_278 , V_316 ) ;
F_5 ( ! V_278 -> V_317 ) ;
F_130 ( V_278 , V_318 , V_59 ) ;
break;
case V_293 :
break;
case V_294 :
if ( F_131 ( V_278 ) )
F_80 ( V_278 , V_319 ) ;
else
F_80 ( V_278 ,
V_320 ) ;
F_8 ( V_278 -> V_68 -> V_13 , V_304 ,
V_305 , 0 , L_9 ) ;
F_126 ( V_298 , V_278 -> V_254 ) ;
F_127 ( V_306 , V_83 , V_307 ,
L_10 , V_298 ) ;
F_120 ( V_278 , V_308 ) ;
break;
case V_301 :
F_80 ( V_278 , V_303 ) ;
break;
case V_296 :
F_80 ( V_278 , V_297 ) ;
break;
case V_311 :
F_128 ( V_278 ) ;
F_120 ( V_278 , V_312 ) ;
F_80 ( V_278 , V_313 ) ;
break;
default:
F_84 ( V_278 -> V_68 , V_25 ) ;
}
}
static void
V_315 ( struct V_277 * V_278 ,
enum V_288 V_25 )
{
struct V_321 * V_322 = V_278 -> V_323 . V_324 . V_25 ;
char V_298 [ V_299 ] ;
struct V_280 * V_83 = (struct V_280 * ) V_278 -> V_68 -> V_83 ;
F_34 ( V_278 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_309 :
F_129 ( V_278 ) ;
F_80 ( V_278 , V_316 ) ;
F_5 ( ! V_278 -> V_317 ) ;
F_8 ( V_278 -> V_68 -> V_13 , V_304 ,
V_325 , 0 , L_11 ) ;
if ( ! F_132 ( & V_278 -> V_68 -> V_264 ) ) {
F_34 ( V_278 -> V_68 ,
V_322 -> V_326 . V_327 . V_328 . V_329 . V_330 ) ;
F_34 ( V_278 -> V_68 ,
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
F_130 ( V_278 , V_318 , V_59 ) ;
F_126 ( V_298 , V_278 -> V_254 ) ;
F_127 ( V_306 , V_83 , V_307 ,
L_14 , V_298 ) ;
F_120 ( V_278 , V_333 ) ;
if ( V_278 -> V_64 . V_334 &&
V_278 -> V_335 . V_336 != V_337 )
F_120 ( V_278 , V_338 ) ;
break;
case V_310 :
break;
case V_293 :
break;
case V_294 :
if ( F_131 ( V_278 ) )
F_80 ( V_278 , V_319 ) ;
else
F_80 ( V_278 ,
V_320 ) ;
F_8 ( V_278 -> V_68 -> V_13 , V_304 ,
V_305 , 0 , L_9 ) ;
F_126 ( V_298 , V_278 -> V_254 ) ;
F_127 ( V_306 , V_83 , V_307 ,
L_10 , V_298 ) ;
F_120 ( V_278 , V_308 ) ;
break;
case V_301 :
F_80 ( V_278 , V_303 ) ;
break;
case V_296 :
F_80 ( V_278 , V_297 ) ;
break;
case V_311 :
F_128 ( V_278 ) ;
F_120 ( V_278 , V_312 ) ;
F_80 ( V_278 , V_313 ) ;
break;
default:
F_84 ( V_278 -> V_68 , V_25 ) ;
}
}
static void
V_316 ( struct V_277 * V_278 ,
enum V_288 V_25 )
{
char V_298 [ V_299 ] ;
struct V_280 * V_83 = (struct V_280 * ) V_278 -> V_68 -> V_83 ;
F_34 ( V_278 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_293 :
break;
case V_294 :
if ( F_131 ( V_278 ) )
F_80 ( V_278 , V_319 ) ;
else
F_80 ( V_278 ,
V_320 ) ;
F_128 ( V_278 ) ;
F_130 ( V_278 , V_339 , V_59 ) ;
F_8 ( V_278 -> V_68 -> V_13 , V_304 ,
V_305 , 0 , L_9 ) ;
F_126 ( V_298 , V_278 -> V_254 ) ;
F_127 ( V_306 , V_83 , V_307 ,
L_15 , V_298 ) ;
F_120 ( V_278 , V_340 ) ;
F_127 ( V_306 , V_83 , V_307 ,
L_10 , V_298 ) ;
F_120 ( V_278 , V_308 ) ;
break;
case V_310 :
F_80 ( V_278 , V_315 ) ;
F_128 ( V_278 ) ;
F_130 ( V_278 , V_339 , V_59 ) ;
F_8 ( V_278 -> V_68 -> V_13 , V_304 ,
V_325 , 0 , L_16 ) ;
F_126 ( V_298 , V_278 -> V_254 ) ;
if ( F_133 ( V_278 -> V_68 ) ) {
F_127 ( V_306 , V_83 , V_307 ,
L_15 , V_298 ) ;
F_120 ( V_278 , V_340 ) ;
} else {
F_127 ( V_341 , V_83 , V_307 ,
L_17
L_18 , V_298 ) ;
F_120 ( V_278 , V_312 ) ;
}
break;
case V_301 :
F_80 ( V_278 , V_303 ) ;
F_128 ( V_278 ) ;
F_126 ( V_298 , V_278 -> V_254 ) ;
if ( F_133 ( V_278 -> V_68 ) ) {
F_127 ( V_306 , V_83 , V_307 ,
L_15 , V_298 ) ;
F_120 ( V_278 , V_340 ) ;
} else {
F_127 ( V_341 , V_83 , V_307 ,
L_17
L_18 , V_298 ) ;
F_120 ( V_278 , V_312 ) ;
}
break;
case V_296 :
F_80 ( V_278 , V_297 ) ;
F_128 ( V_278 ) ;
F_130 ( V_278 , V_339 , V_59 ) ;
F_126 ( V_298 , V_278 -> V_254 ) ;
if ( F_133 ( V_278 -> V_68 ) ) {
F_127 ( V_306 , V_83 , V_307 ,
L_15 , V_298 ) ;
F_120 ( V_278 , V_340 ) ;
} else {
F_127 ( V_341 , V_83 , V_307 ,
L_17
L_18 , V_298 ) ;
F_120 ( V_278 , V_312 ) ;
}
break;
case V_311 :
F_128 ( V_278 ) ;
F_120 ( V_278 , V_312 ) ;
F_80 ( V_278 , V_313 ) ;
break;
default:
F_84 ( V_278 -> V_68 , V_25 ) ;
}
}
static void
V_320 ( struct V_277 * V_278 ,
enum V_288 V_25 )
{
F_34 ( V_278 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_300 :
F_80 ( V_278 , V_319 ) ;
F_131 ( V_278 ) ;
break;
case V_301 :
F_80 ( V_278 , V_303 ) ;
F_73 ( & V_278 -> V_302 ) ;
break;
case V_293 :
F_80 ( V_278 , V_342 ) ;
break;
case V_294 :
break;
case V_309 :
case V_310 :
break;
case V_296 :
F_80 ( V_278 , V_343 ) ;
F_73 ( & V_278 -> V_302 ) ;
break;
case V_311 :
F_128 ( V_278 ) ;
F_120 ( V_278 , V_312 ) ;
F_80 ( V_278 , V_313 ) ;
break;
default:
F_84 ( V_278 -> V_68 , V_25 ) ;
}
}
static void
V_342 ( struct V_277 * V_278 ,
enum V_288 V_25 )
{
F_34 ( V_278 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_300 :
F_80 ( V_278 , V_319 ) ;
F_131 ( V_278 ) ;
if ( F_125 ( V_278 ) )
F_80 ( V_278 , V_291 ) ;
else
F_80 ( V_278 ,
V_292 ) ;
break;
case V_301 :
F_80 ( V_278 , V_303 ) ;
F_73 ( & V_278 -> V_302 ) ;
break;
case V_293 :
break;
case V_294 :
F_80 ( V_278 , V_320 ) ;
break;
case V_309 :
case V_310 :
break;
case V_296 :
F_80 ( V_278 , V_343 ) ;
F_73 ( & V_278 -> V_302 ) ;
break;
default:
F_84 ( V_278 -> V_68 , V_25 ) ;
}
}
static void
V_319 ( struct V_277 * V_278 ,
enum V_288 V_25 )
{
char V_298 [ V_299 ] ;
struct V_280 * V_83 = (struct V_280 * ) V_278 -> V_68 -> V_83 ;
F_34 ( V_278 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_314 :
F_80 ( V_278 , V_295 ) ;
break;
case V_294 :
break;
case V_293 :
if ( F_125 ( V_278 ) )
F_80 ( V_278 , V_291 ) ;
else
F_80 ( V_278 ,
V_292 ) ;
F_8 ( V_278 -> V_68 -> V_13 , V_304 ,
V_344 , 0 , L_19 ) ;
F_126 ( V_298 , V_278 -> V_254 ) ;
F_127 ( V_306 , V_83 , V_307 ,
L_20 , V_298 ) ;
F_120 ( V_278 , V_345 ) ;
break;
case V_301 :
F_80 ( V_278 , V_303 ) ;
break;
case V_309 :
case V_310 :
break;
case V_296 :
F_80 ( V_278 , V_343 ) ;
break;
default:
F_84 ( V_278 -> V_68 , V_25 ) ;
}
}
static void
V_295 ( struct V_277 * V_278 ,
enum V_288 V_25 )
{
char V_298 [ V_299 ] ;
struct V_280 * V_83 = (struct V_280 * ) V_278 -> V_68 -> V_83 ;
F_34 ( V_278 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_289 :
break;
case V_301 :
F_80 ( V_278 , V_303 ) ;
break;
case V_293 :
if ( F_125 ( V_278 ) )
F_80 ( V_278 , V_291 ) ;
else
F_80 ( V_278 ,
V_292 ) ;
F_8 ( V_278 -> V_68 -> V_13 , V_304 ,
V_344 , 0 , L_19 ) ;
F_126 ( V_298 , V_278 -> V_254 ) ;
F_127 ( V_306 , V_83 , V_307 ,
L_20 , V_298 ) ;
F_120 ( V_278 , V_345 ) ;
break;
case V_294 :
break;
case V_296 :
F_80 ( V_278 , V_343 ) ;
break;
case V_346 :
F_80 ( V_278 , V_347 ) ;
break;
case V_348 :
F_80 ( V_278 , V_349 ) ;
break;
default:
F_84 ( V_278 -> V_68 , V_25 ) ;
}
}
static void
V_303 ( struct V_277 * V_278 ,
enum V_288 V_25 )
{
F_34 ( V_278 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_289 :
if ( F_125 ( V_278 ) )
F_80 ( V_278 , V_291 ) ;
else
F_80 ( V_278 ,
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
F_34 ( V_278 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_289 :
if ( F_125 ( V_278 ) )
F_80 ( V_278 , V_291 ) ;
else
F_80 ( V_278 ,
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
F_34 ( V_278 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_289 :
F_80 ( V_278 , V_295 ) ;
break;
case V_293 :
F_80 ( V_278 , V_297 ) ;
break;
default:
;
}
}
static void
V_347 ( struct V_277 * V_278 , enum V_288 V_25 )
{
F_34 ( V_278 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_346 :
case V_294 :
case V_293 :
case V_289 :
break;
case V_301 :
F_80 ( V_278 , V_303 ) ;
break;
case V_296 :
F_80 ( V_278 , V_343 ) ;
break;
case V_350 :
F_80 ( V_278 , V_295 ) ;
break;
default:
F_84 ( V_278 -> V_68 , V_25 ) ;
}
}
static void
V_349 ( struct V_277 * V_278 ,
enum V_288 V_25 )
{
F_34 ( V_278 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_294 :
case V_351 :
F_80 ( V_278 , V_295 ) ;
break;
case V_346 :
case V_350 :
case V_293 :
case V_289 :
break;
case V_301 :
F_80 ( V_278 , V_303 ) ;
break;
case V_296 :
F_80 ( V_278 , V_343 ) ;
break;
default:
F_84 ( V_278 -> V_68 , V_25 ) ;
}
}
static void
V_313 ( struct V_277 * V_278 ,
enum V_288 V_25 )
{
F_34 ( V_278 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_346 :
case V_293 :
case V_289 :
break;
case V_294 :
if ( F_131 ( V_278 ) )
F_80 ( V_278 , V_319 ) ;
else
F_80 ( V_278 , V_320 ) ;
F_128 ( V_278 ) ;
F_130 ( V_278 , V_339 , V_59 ) ;
F_8 ( V_278 -> V_68 -> V_13 , V_304 ,
V_305 , 0 , L_9 ) ;
F_120 ( V_278 , V_308 ) ;
break;
case V_301 :
F_80 ( V_278 , V_303 ) ;
break;
case V_296 :
F_128 ( V_278 ) ;
F_130 ( V_278 , V_339 , V_59 ) ;
F_80 ( V_278 , V_297 ) ;
break;
default:
F_84 ( V_278 -> V_68 , V_25 ) ;
}
}
static void
F_134 ( struct V_352 * V_353 ,
enum V_354 V_25 )
{
F_34 ( V_353 -> V_278 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_355 :
F_80 ( V_353 , V_356 ) ;
F_135 ( V_353 , V_318 ) ;
break;
default:
F_84 ( V_353 -> V_278 -> V_68 , V_25 ) ;
}
}
static void
F_136 ( struct V_352 * V_353 ,
enum V_354 V_25 )
{
F_34 ( V_353 -> V_278 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_355 :
F_80 ( V_353 , V_357 ) ;
break;
case V_358 :
F_80 ( V_353 , F_134 ) ;
break;
default:
F_84 ( V_353 -> V_278 -> V_68 , V_25 ) ;
}
}
static void
V_357 ( struct V_352 * V_353 ,
enum V_354 V_25 )
{
F_34 ( V_353 -> V_278 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_359 :
F_80 ( V_353 , F_136 ) ;
break;
case V_358 :
F_80 ( V_353 , V_356 ) ;
F_135 ( V_353 , V_318 ) ;
break;
default:
F_84 ( V_353 -> V_278 -> V_68 , V_25 ) ;
}
}
static void
F_137 ( struct V_352 * V_353 ,
enum V_354 V_25 )
{
F_34 ( V_353 -> V_278 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_359 :
F_80 ( V_353 , F_136 ) ;
F_135 ( V_353 , V_339 ) ;
break;
default:
F_84 ( V_353 -> V_278 -> V_68 , V_25 ) ;
}
}
static void
V_356 ( struct V_352 * V_353 ,
enum V_354 V_25 )
{
F_34 ( V_353 -> V_278 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_359 :
F_80 ( V_353 , V_360 ) ;
break;
case V_358 :
F_80 ( V_353 , F_137 ) ;
break;
default:
F_84 ( V_353 -> V_278 -> V_68 , V_25 ) ;
}
}
static void
V_360 ( struct V_352 * V_353 ,
enum V_354 V_25 )
{
F_34 ( V_353 -> V_278 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_355 :
F_80 ( V_353 , V_361 ) ;
break;
case V_358 :
F_80 ( V_353 , F_136 ) ;
F_135 ( V_353 , V_339 ) ;
break;
default:
F_84 ( V_353 -> V_278 -> V_68 , V_25 ) ;
}
}
static void
V_361 ( struct V_352 * V_353 ,
enum V_354 V_25 )
{
F_34 ( V_353 -> V_278 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_359 :
F_80 ( V_353 , V_360 ) ;
break;
case V_358 :
F_80 ( V_353 , V_357 ) ;
F_135 ( V_353 , V_339 ) ;
break;
default:
F_84 ( V_353 -> V_278 -> V_68 , V_25 ) ;
}
}
static void
F_138 ( void * V_125 , T_4 V_130 )
{
struct V_352 * V_353 = V_125 ;
if ( V_130 )
V_353 -> V_278 -> V_317 ( V_353 -> V_278 -> V_362 , V_353 -> V_363 ) ;
else
F_85 ( V_353 , V_358 ) ;
}
static void
F_130 ( struct V_277 * V_278 , enum V_364 V_25 ,
T_4 V_365 )
{
if ( V_278 -> V_64 . V_366 && ! V_365 )
return;
switch ( V_25 ) {
case V_318 :
F_85 ( & V_278 -> V_353 , V_355 ) ;
break;
case V_339 :
F_85 ( & V_278 -> V_353 , V_359 ) ;
break;
default:
F_5 ( 1 ) ;
}
}
static void
F_135 ( struct V_352 * V_353 , enum V_364 V_25 )
{
struct V_277 * V_278 = V_353 -> V_278 ;
if ( V_278 -> V_68 -> V_263 ) {
V_278 -> V_317 ( V_278 -> V_362 , V_25 ) ;
F_85 ( V_353 , V_358 ) ;
} else {
V_353 -> V_363 = V_25 ;
F_30 ( V_278 -> V_68 , & V_353 -> V_367 ,
F_138 , V_353 ) ;
}
}
void
F_139 ( struct V_63 * V_64 , struct V_65 * V_66 ,
struct V_67 * V_68 )
{
struct V_71 * V_368 = F_140 ( V_68 ) ;
F_23 ( V_66 , V_368 , V_369 ) ;
}
static void
F_141 ( void * V_125 )
{
struct V_277 * V_278 = V_125 ;
F_85 ( V_278 , V_300 ) ;
}
static void
F_142 ( struct V_277 * V_278 )
{
struct V_71 * V_368 = & V_278 -> V_368 ;
V_278 -> V_370 = F_143 ( V_368 ) ;
V_278 -> V_371 = F_144 ( V_368 ) ;
V_278 -> V_372 = (union V_373 * )
F_143 ( V_368 ) ;
}
void
F_145 ( struct V_67 * V_68 , void * V_83 , struct V_63 * V_64 ,
struct V_84 * V_85 )
{
struct V_277 * V_278 = F_146 ( V_68 ) ;
struct V_374 * V_375 = & V_278 -> V_64 ;
struct V_352 * V_353 = & V_278 -> V_353 ;
struct V_9 V_10 ;
V_278 -> V_68 = V_68 ;
V_353 -> V_278 = V_278 ;
F_142 ( V_278 ) ;
F_80 ( V_278 , F_124 ) ;
F_80 ( V_353 , F_134 ) ;
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
F_16 ( & V_278 -> V_302 , F_141 , V_278 ) ;
}
void
F_147 ( struct V_67 * V_68 )
{
F_85 ( F_146 ( V_68 ) , V_289 ) ;
}
void
F_148 ( struct V_67 * V_68 )
{
struct V_277 * V_278 = F_146 ( V_68 ) ;
F_85 ( V_278 , V_296 ) ;
F_149 ( V_68 ) ;
}
static void
F_150 ( struct V_277 * V_278 ,
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
F_129 ( struct V_277 * V_278 )
{
struct V_321 * V_322 = V_278 -> V_323 . V_324 . V_25 ;
struct V_404 * V_365 = & V_278 -> V_365 ;
V_278 -> V_380 = V_322 -> V_326 . V_380 ;
V_278 -> V_378 = V_322 -> V_326 . V_378 ;
if ( V_278 -> V_378 == V_405 ) {
F_150 ( V_278 ,
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
F_41 ( V_322 -> V_326 . V_327 . V_328 . V_329 . V_411 ) ;
F_34 ( V_278 -> V_68 , V_278 -> V_380 ) ;
F_34 ( V_278 -> V_68 , V_278 -> V_378 ) ;
}
static void
F_128 ( struct V_277 * V_278 )
{
V_278 -> V_380 = V_412 ;
V_278 -> V_378 = V_413 ;
V_278 -> V_392 = V_393 ;
}
static T_4
F_125 ( struct V_277 * V_278 )
{
struct V_414 * V_248 ;
V_278 -> V_415 ++ ;
V_248 = F_48 ( V_278 -> V_68 , V_416 ) ;
if ( ! V_248 ) {
F_67 ( V_278 -> V_68 , V_416 ,
& V_278 -> V_302 ) ;
return V_59 ;
}
F_50 ( V_248 -> V_152 , V_417 , V_418 ,
F_51 ( V_278 -> V_68 ) ) ;
V_248 -> V_255 = V_278 -> V_255 ;
V_248 -> V_254 = V_278 -> V_254 ;
V_248 -> V_375 = V_278 -> V_64 ;
V_248 -> V_415 = V_278 -> V_415 ;
V_248 -> V_375 . V_382 = F_52 ( V_278 -> V_64 . V_382 ) ;
V_248 -> V_290 = V_278 -> V_290 ;
F_151 ( V_248 -> V_419 , V_278 -> V_371 ) ;
F_34 ( V_278 -> V_68 , V_248 -> V_419 . V_420 . V_421 ) ;
F_34 ( V_278 -> V_68 , V_248 -> V_419 . V_420 . V_422 ) ;
F_58 ( V_278 -> V_68 , V_416 , V_248 -> V_152 ) ;
return V_58 ;
}
static T_4
F_131 ( struct V_277 * V_278 )
{
struct V_423 * V_248 ;
V_278 -> V_415 ++ ;
V_248 = F_48 ( V_278 -> V_68 , V_416 ) ;
if ( ! V_248 ) {
F_67 ( V_278 -> V_68 , V_416 ,
& V_278 -> V_302 ) ;
return V_59 ;
}
F_50 ( V_248 -> V_152 , V_417 , V_424 ,
F_51 ( V_278 -> V_68 ) ) ;
V_248 -> V_415 = V_278 -> V_415 ;
F_58 ( V_278 -> V_68 , V_416 , V_248 -> V_152 ) ;
return V_58 ;
}
static void
F_152 ( struct V_277 * V_278 )
{
V_278 -> V_254 = V_278 -> V_68 -> V_264 . V_327 -> V_254 ;
V_278 -> V_255 = V_278 -> V_68 -> V_264 . V_327 -> V_255 ;
F_34 ( V_278 -> V_68 , V_278 -> V_254 ) ;
F_34 ( V_278 -> V_68 , V_278 -> V_255 ) ;
}
static void
F_153 ( struct V_425 * V_426 ,
struct V_425 * V_427 )
{
T_3 * V_428 = ( T_3 * ) V_426 ;
T_12 * V_429 = ( T_12 * ) V_427 ;
int V_35 ;
for ( V_35 = 0 ; V_35 < ( sizeof( struct V_425 ) / sizeof( T_3 ) ) ; ++ V_35 )
V_428 [ V_35 ] = F_42 ( V_429 [ V_35 ] ) ;
}
static void
F_154 ( struct V_430 * V_426 ,
struct V_430 * V_427 )
{
T_3 * V_428 = ( T_3 * ) V_426 ;
T_12 * V_429 = ( T_12 * ) V_427 ;
int V_35 ;
for ( V_35 = 0 ; V_35 < ( ( sizeof( struct V_430 ) ) / sizeof( T_3 ) ) ;
V_35 = V_35 + 2 ) {
#ifdef F_155
V_428 [ V_35 ] = F_42 ( V_429 [ V_35 ] ) ;
V_428 [ V_35 + 1 ] = F_42 ( V_429 [ V_35 + 1 ] ) ;
#else
V_428 [ V_35 ] = F_42 ( V_429 [ V_35 + 1 ] ) ;
V_428 [ V_35 + 1 ] = F_42 ( V_429 [ V_35 ] ) ;
#endif
}
}
static void
F_156 ( void * V_125 , T_4 V_130 )
{
struct V_277 * V_278 = (struct V_277 * ) V_125 ;
struct V_431 * V_432 ;
struct V_90 * V_56 , * V_91 ;
union V_373 * V_433 ;
if ( V_130 ) {
struct V_9 V_10 ;
if ( V_278 -> V_434 == V_134 )
F_3 ( & V_10 ) ;
F_28 (qe, qen, &fcport->stats_pending_q) {
F_32 ( & V_278 -> V_394 , & V_56 ) ;
V_432 = (struct V_431 * ) V_56 ;
if ( V_278 -> V_434 == V_134 ) {
V_433 = (union V_373 * ) V_432 -> V_435 ;
if ( F_132 ( & V_278 -> V_68 -> V_264 ) )
F_153 ( & V_433 -> V_436 ,
& V_278 -> V_372 -> V_436 ) ;
else {
F_154 ( & V_433 -> V_437 ,
& V_278 -> V_372 -> V_437 ) ;
V_433 -> V_437 . V_438 =
V_10 . V_11 - V_278 -> V_376 ;
}
}
F_157 ( V_278 -> V_68 , & V_432 -> V_97 ,
V_278 -> V_434 ) ;
}
V_278 -> V_434 = V_134 ;
} else {
F_14 ( & V_278 -> V_394 ) ;
V_278 -> V_434 = V_134 ;
}
}
static void
F_158 ( void * V_125 )
{
struct V_277 * V_278 = (struct V_277 * ) V_125 ;
F_34 ( V_278 -> V_68 , V_278 -> V_439 ) ;
if ( V_278 -> V_439 ) {
F_73 ( & V_278 -> V_440 ) ;
V_278 -> V_439 = V_59 ;
}
V_278 -> V_434 = V_441 ;
F_156 ( V_278 , V_58 ) ;
}
static void
F_159 ( void * V_125 )
{
struct V_277 * V_278 = (struct V_277 * ) V_125 ;
struct V_423 * V_176 ;
V_176 = F_48 ( V_278 -> V_68 , V_416 ) ;
if ( ! V_176 ) {
V_278 -> V_439 = V_58 ;
F_16 ( & V_278 -> V_440 ,
F_159 , V_278 ) ;
F_67 ( V_278 -> V_68 , V_416 ,
& V_278 -> V_440 ) ;
return;
}
V_278 -> V_439 = V_59 ;
memset ( V_176 , 0 , sizeof( struct V_423 ) ) ;
F_50 ( V_176 -> V_152 , V_417 , V_442 ,
F_51 ( V_278 -> V_68 ) ) ;
F_58 ( V_278 -> V_68 , V_416 , V_176 -> V_152 ) ;
}
static void
F_160 ( void * V_125 , T_4 V_130 )
{
struct V_277 * V_278 = (struct V_277 * ) V_125 ;
struct V_431 * V_432 ;
struct V_90 * V_56 , * V_91 ;
if ( V_130 ) {
struct V_9 V_10 ;
F_3 ( & V_10 ) ;
V_278 -> V_376 = V_10 . V_11 ;
F_28 (qe, qen, &fcport->statsclr_pending_q) {
F_32 ( & V_278 -> V_395 , & V_56 ) ;
V_432 = (struct V_431 * ) V_56 ;
F_157 ( V_278 -> V_68 , & V_432 -> V_97 ,
V_278 -> V_434 ) ;
}
V_278 -> V_434 = V_134 ;
} else {
F_14 ( & V_278 -> V_395 ) ;
V_278 -> V_434 = V_134 ;
}
}
static void
F_161 ( void * V_125 )
{
struct V_277 * V_278 = (struct V_277 * ) V_125 ;
F_34 ( V_278 -> V_68 , V_278 -> V_439 ) ;
if ( V_278 -> V_439 ) {
F_73 ( & V_278 -> V_440 ) ;
V_278 -> V_439 = V_59 ;
}
V_278 -> V_434 = V_441 ;
F_160 ( V_278 , V_58 ) ;
}
static void
F_162 ( void * V_125 )
{
struct V_277 * V_278 = (struct V_277 * ) V_125 ;
struct V_423 * V_176 ;
V_176 = F_48 ( V_278 -> V_68 , V_416 ) ;
if ( ! V_176 ) {
V_278 -> V_439 = V_58 ;
F_16 ( & V_278 -> V_440 ,
F_162 , V_278 ) ;
F_67 ( V_278 -> V_68 , V_416 ,
& V_278 -> V_440 ) ;
return;
}
V_278 -> V_439 = V_59 ;
memset ( V_176 , 0 , sizeof( struct V_423 ) ) ;
F_50 ( V_176 -> V_152 , V_417 , V_443 ,
F_51 ( V_278 -> V_68 ) ) ;
F_58 ( V_278 -> V_68 , V_416 , V_176 -> V_152 ) ;
}
static void
F_163 ( struct V_277 * V_278 , struct V_444 * V_445 )
{
struct V_404 * V_365 = & V_278 -> V_365 ;
struct V_446 * V_447 ;
struct V_448 * V_449 ;
enum V_450 V_451 ;
int V_35 ;
int V_452 = 0 ;
F_34 ( V_278 -> V_68 , V_278 -> V_64 . V_366 ) ;
F_5 ( V_445 -> V_453 != V_454 &&
V_445 -> V_453 != V_455 ) ;
F_34 ( V_278 -> V_68 , V_365 -> V_327 . V_336 ) ;
F_34 ( V_278 -> V_68 , V_445 -> V_453 ) ;
F_34 ( V_278 -> V_68 , V_445 -> V_456 ) ;
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
V_449 -> V_461 = F_42 ( V_447 -> V_461 ) ;
if ( V_447 -> V_336 == V_462 ) {
V_278 -> V_380 = V_447 -> V_380 ;
V_278 -> V_378 = V_379 ;
V_452 |= 1 << V_35 ;
}
F_34 ( V_278 -> V_68 , V_449 -> V_326 ) ;
F_34 ( V_278 -> V_68 , V_449 -> V_459 ) ;
F_34 ( V_278 -> V_68 , V_449 -> V_460 ) ;
F_34 ( V_278 -> V_68 , V_449 -> V_380 ) ;
F_34 ( V_278 -> V_68 , V_449 -> V_461 ) ;
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
F_130 ( V_278 , ( V_445 -> V_453 == V_454 ) ?
V_318 : V_339 , V_58 ) ;
}
}
static void
F_149 ( struct V_67 * V_68 )
{
struct V_277 * V_278 = F_146 ( V_68 ) ;
int V_35 = 0 ;
if ( V_278 -> V_64 . V_366 ) {
if ( V_278 -> V_365 . V_327 . V_336 == V_454 )
F_130 ( V_278 , V_339 , V_58 ) ;
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
F_164 ( struct V_67 * V_68 )
{
struct V_277 * V_278 = F_146 ( V_68 ) ;
F_152 ( V_278 ) ;
if ( V_278 -> V_64 . V_382 == 0 )
V_278 -> V_64 . V_382 = F_165 ( & V_68 -> V_264 ) ;
V_278 -> V_64 . V_466 = F_166 ( & V_68 -> V_264 ) ;
V_278 -> V_467 = F_167 ( & V_68 -> V_264 ) ;
if ( F_168 ( V_68 ) )
V_68 -> V_468 . V_284 . V_469 = V_58 ;
F_5 ( ! V_278 -> V_64 . V_382 ) ;
F_5 ( ! V_278 -> V_64 . V_466 ) ;
F_5 ( ! V_278 -> V_467 ) ;
}
void
F_169 ( struct V_67 * V_68 , struct V_175 * V_176 )
{
struct V_277 * V_278 = F_146 ( V_68 ) ;
union V_470 V_324 ;
V_324 . V_176 = V_176 ;
V_278 -> V_323 . V_324 = V_324 ;
F_34 ( V_68 , V_176 -> V_177 . V_178 ) ;
F_34 ( V_68 , F_170 ( V_471 , V_278 -> V_472 ) ) ;
switch ( V_176 -> V_177 . V_178 ) {
case V_473 :
if ( V_278 -> V_415 == V_324 . V_474 -> V_415 ) {
V_278 -> V_377 = V_58 ;
if ( V_278 -> V_290 ) {
V_278 -> V_64 = V_324 . V_474 -> V_375 ;
V_278 -> V_64 . V_382 =
F_52 ( V_278 -> V_64 . V_382 ) ;
V_278 -> V_64 . V_475 =
F_52 ( V_278 -> V_64 . V_475 ) ;
V_278 -> V_64 . V_476 =
F_52 ( V_278 -> V_64 . V_476 ) ;
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
F_85 ( V_278 , V_314 ) ;
}
break;
case V_482 :
if ( V_278 -> V_415 == V_324 . V_474 -> V_415 )
F_85 ( V_278 , V_314 ) ;
break;
case V_483 :
if ( V_278 -> V_64 . V_407 )
V_278 -> V_408 . V_336 = V_480 ;
else
V_278 -> V_408 . V_336 = V_481 ;
if ( V_324 . V_25 -> V_326 . V_484 == V_318 )
F_85 ( V_278 , V_309 ) ;
else {
if ( V_324 . V_25 -> V_326 . V_485 ==
V_486 )
F_85 ( V_278 ,
V_311 ) ;
else
F_85 ( V_278 ,
V_310 ) ;
}
V_278 -> V_335 . V_479 =
V_324 . V_25 -> V_326 . V_335 . V_479 ;
break;
case V_487 :
F_163 ( V_278 , V_324 . V_488 ) ;
break;
case V_489 :
if ( F_70 ( & V_278 -> V_394 ) ||
( V_278 -> V_434 == V_441 ) )
break;
F_171 ( & V_278 -> V_490 ) ;
V_278 -> V_434 = V_324 . V_491 -> V_198 ;
F_156 ( V_278 , V_58 ) ;
break;
case V_492 :
if ( F_70 ( & V_278 -> V_395 ) ||
( V_278 -> V_434 == V_441 ) )
break;
F_171 ( & V_278 -> V_490 ) ;
V_278 -> V_434 = V_134 ;
F_160 ( V_278 , V_58 ) ;
break;
case V_493 :
F_85 ( V_278 , V_293 ) ;
break;
case V_494 :
F_85 ( V_278 , V_294 ) ;
break;
default:
F_5 ( 1 ) ;
break;
}
}
void
F_172 ( struct V_67 * V_68 ,
void (* V_174) ( void * V_125 ,
enum V_364 V_25 ) ,
void * V_125 )
{
struct V_277 * V_278 = F_146 ( V_68 ) ;
V_278 -> V_317 = V_174 ;
V_278 -> V_362 = V_125 ;
}
T_7
F_173 ( struct V_67 * V_68 )
{
struct V_277 * V_278 = F_146 ( V_68 ) ;
if ( F_168 ( V_68 ) )
return V_495 ;
if ( F_174 ( & V_68 -> V_264 ) )
return V_496 ;
if ( V_278 -> V_497 )
return V_498 ;
F_85 ( F_146 ( V_68 ) , V_293 ) ;
return V_134 ;
}
T_7
F_175 ( struct V_67 * V_68 )
{
if ( F_168 ( V_68 ) )
return V_495 ;
if ( F_174 ( & V_68 -> V_264 ) )
return V_496 ;
F_85 ( F_146 ( V_68 ) , V_294 ) ;
return V_134 ;
}
T_7
F_168 ( struct V_67 * V_68 )
{
struct V_277 * V_278 = F_146 ( V_68 ) ;
struct V_499 * V_500 = & V_68 -> V_500 ;
struct V_501 * V_502 = V_500 -> V_502 ;
if ( V_502 -> V_503 . V_504 == V_505 ) {
F_34 ( V_68 , V_278 -> V_254 ) ;
return V_495 ;
}
return V_134 ;
}
T_7
F_176 ( struct V_67 * V_68 , enum V_506 V_380 )
{
struct V_277 * V_278 = F_146 ( V_68 ) ;
F_34 ( V_68 , V_380 ) ;
if ( V_278 -> V_64 . V_366 == V_58 )
return V_507 ;
if ( ( V_278 -> V_64 . V_378 == V_405 ) &&
( V_380 == V_508 ) )
return V_509 ;
if ( ( V_380 != V_381 ) && ( V_380 > V_278 -> V_467 ) ) {
F_34 ( V_68 , V_278 -> V_467 ) ;
return V_509 ;
}
if ( F_177 ( & V_278 -> V_68 -> V_264 ) == V_510 ) {
if ( ( V_380 == V_384 ) &&
( F_178 ( V_68 -> V_264 . V_85 . V_511 ) ) )
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
F_179 ( struct V_67 * V_68 )
{
struct V_277 * V_278 = F_146 ( V_68 ) ;
return V_278 -> V_380 ;
}
T_7
F_180 ( struct V_67 * V_68 , enum V_516 V_378 )
{
struct V_277 * V_278 = F_146 ( V_68 ) ;
F_34 ( V_68 , V_378 ) ;
F_34 ( V_68 , V_278 -> V_64 . V_378 ) ;
switch ( V_378 ) {
case V_379 :
break;
case V_405 :
if ( ( F_181 ( V_68 ) != V_59 ) ||
( V_278 -> V_335 . V_336 != V_478 ) )
return V_517 ;
if ( V_278 -> V_64 . V_518 != V_59 )
return V_519 ;
if ( ( F_182 ( V_68 ) != V_59 ) ||
( V_278 -> V_365 . V_327 . V_336 != V_409 ) )
return V_520 ;
if ( ( F_179 ( V_68 ) == V_508 ) ||
( V_278 -> V_64 . V_380 == V_508 ) )
return V_509 ;
if ( F_183 ( V_68 -> V_264 . V_327 -> V_521 ) )
return V_522 ;
if ( F_184 ( V_68 ) != V_59 )
return V_523 ;
if ( F_185 ( V_68 ) != V_59 )
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
F_186 ( struct V_67 * V_68 )
{
struct V_277 * V_278 = F_146 ( V_68 ) ;
return V_278 -> V_378 ;
}
enum V_516
F_187 ( struct V_67 * V_68 )
{
struct V_277 * V_278 = F_146 ( V_68 ) ;
return V_278 -> V_64 . V_378 ;
}
T_7
F_188 ( struct V_67 * V_68 , V_37 V_251 )
{
struct V_277 * V_278 = F_146 ( V_68 ) ;
F_34 ( V_68 , V_251 ) ;
F_34 ( V_68 , V_278 -> V_64 . V_526 ) ;
F_34 ( V_68 , V_278 -> V_64 . V_527 ) ;
V_278 -> V_64 . V_526 = V_58 ;
V_278 -> V_64 . V_527 = V_251 ;
return V_134 ;
}
T_7
F_189 ( struct V_67 * V_68 )
{
struct V_277 * V_278 = F_146 ( V_68 ) ;
F_34 ( V_68 , V_278 -> V_64 . V_526 ) ;
F_34 ( V_68 , V_278 -> V_64 . V_527 ) ;
V_278 -> V_64 . V_526 = V_59 ;
return V_134 ;
}
T_4
F_190 ( struct V_67 * V_68 , V_37 * V_251 )
{
struct V_277 * V_278 = F_146 ( V_68 ) ;
* V_251 = V_278 -> V_64 . V_527 ;
return V_278 -> V_64 . V_526 ;
}
V_37
F_191 ( struct V_67 * V_68 )
{
struct V_277 * V_278 = F_146 ( V_68 ) ;
return V_278 -> V_398 ;
}
T_7
F_192 ( struct V_67 * V_68 , T_2 V_382 )
{
struct V_277 * V_278 = F_146 ( V_68 ) ;
F_34 ( V_68 , V_382 ) ;
F_34 ( V_68 , V_278 -> V_64 . V_382 ) ;
if ( ( V_382 > V_159 ) || ( V_382 < V_528 ) )
return V_529 ;
if ( ( V_382 != V_159 ) && ( V_382 & ( V_382 - 1 ) ) )
return V_529 ;
V_278 -> V_64 . V_382 = V_382 ;
return V_134 ;
}
T_2
F_193 ( struct V_67 * V_68 )
{
struct V_277 * V_278 = F_146 ( V_68 ) ;
return V_278 -> V_64 . V_382 ;
}
V_37
F_194 ( struct V_67 * V_68 )
{
if ( F_186 ( V_68 ) != V_405 )
return ( F_146 ( V_68 ) ) -> V_64 . V_466 ;
else
return 0 ;
}
void
F_195 ( struct V_67 * V_68 , T_2 V_530 )
{
struct V_277 * V_278 = F_146 ( V_68 ) ;
V_278 -> V_64 . V_530 = ( V_37 ) V_530 ;
}
T_10
F_196 ( struct V_67 * V_68 , T_4 V_531 )
{
struct V_277 * V_278 = F_146 ( V_68 ) ;
if ( V_531 )
return V_278 -> V_255 ;
else
return V_278 -> V_254 ;
}
void
F_197 ( struct V_67 * V_68 , struct V_532 * V_327 )
{
struct V_277 * V_278 = F_146 ( V_68 ) ;
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
V_327 -> V_537 . V_475 = F_198 ( V_68 ) ;
V_327 -> V_537 . V_476 = F_199 ( V_68 ) ;
V_327 -> V_543 = F_170 ( V_471 , V_278 -> V_472 ) ;
V_327 -> V_392 = V_278 -> V_392 ;
if ( F_168 ( V_68 ) )
V_327 -> V_543 = V_544 ;
else {
if ( F_174 ( & V_278 -> V_68 -> V_264 ) )
V_327 -> V_543 = V_545 ;
else if ( F_200 ( & V_278 -> V_68 -> V_264 ) )
V_327 -> V_543 = V_546 ;
}
V_327 -> V_410 = V_278 -> V_410 ;
}
T_7
F_201 ( struct V_67 * V_68 , struct V_431 * V_432 )
{
struct V_277 * V_278 = F_146 ( V_68 ) ;
if ( ! F_202 ( V_68 ) ||
! V_278 -> V_377 )
return V_547 ;
if ( ! F_70 ( & V_278 -> V_395 ) )
return V_548 ;
if ( F_70 ( & V_278 -> V_394 ) ) {
F_15 ( & V_432 -> V_97 . V_56 , & V_278 -> V_394 ) ;
F_159 ( V_278 ) ;
F_203 ( V_68 , & V_278 -> V_490 ,
F_158 ,
V_278 , V_549 ) ;
} else
F_15 ( & V_432 -> V_97 . V_56 , & V_278 -> V_394 ) ;
return V_134 ;
}
T_7
F_204 ( struct V_67 * V_68 , struct V_431 * V_432 )
{
struct V_277 * V_278 = F_146 ( V_68 ) ;
if ( ! F_202 ( V_68 ) ||
! V_278 -> V_377 )
return V_547 ;
if ( ! F_70 ( & V_278 -> V_394 ) )
return V_548 ;
if ( F_70 ( & V_278 -> V_395 ) ) {
F_15 ( & V_432 -> V_97 . V_56 , & V_278 -> V_395 ) ;
F_162 ( V_278 ) ;
F_203 ( V_68 , & V_278 -> V_490 ,
F_161 ,
V_278 , V_549 ) ;
} else
F_15 ( & V_432 -> V_97 . V_56 , & V_278 -> V_395 ) ;
return V_134 ;
}
T_4
F_205 ( struct V_67 * V_68 )
{
struct V_277 * V_278 = F_146 ( V_68 ) ;
return F_170 ( V_471 , V_278 -> V_472 ) ==
V_550 ;
}
T_4
F_184 ( struct V_67 * V_68 )
{
struct V_277 * V_278 = F_146 ( V_68 ) ;
return ( F_170 ( V_471 , V_278 -> V_472 ) ==
V_551 ) ;
}
T_4
F_185 ( struct V_67 * V_68 )
{
struct V_277 * V_278 = F_146 ( V_68 ) ;
return ( F_170 ( V_471 , V_278 -> V_472 ) ==
V_552 ) ;
}
T_7
F_206 ( struct V_67 * V_68 , struct V_553 * V_385 )
{
struct V_277 * V_278 = F_146 ( V_68 ) ;
enum V_554 V_285 = F_122 ( V_68 ) ;
F_34 ( V_68 , V_285 ) ;
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
F_207 ( struct V_67 * V_68 )
{
struct V_277 * V_278 = F_146 ( V_68 ) ;
return V_278 -> V_64 . V_518 ? V_58 : V_59 ;
}
void
F_208 ( struct V_67 * V_68 , V_37 V_336 )
{
struct V_277 * V_278 = F_146 ( V_68 ) ;
F_34 ( V_68 , V_336 ) ;
V_278 -> V_64 . V_556 = V_336 ;
}
enum V_506
F_209 ( struct V_67 * V_68 )
{
struct V_277 * V_278 = F_146 ( V_68 ) ;
F_34 ( V_68 , V_278 -> V_64 . V_383 ) ;
return V_278 -> V_64 . V_383 ;
}
void
F_210 ( void * V_557 , T_4 V_541 ,
T_4 V_542 )
{
struct V_67 * V_68 = V_557 ;
struct V_277 * V_278 = F_146 ( V_68 ) ;
F_34 ( V_68 , V_541 ) ;
F_34 ( V_68 , V_542 ) ;
F_34 ( V_68 , V_278 -> V_541 ) ;
F_34 ( V_68 , V_278 -> V_542 ) ;
V_278 -> V_541 = V_541 ;
V_278 -> V_542 = V_542 ;
}
T_4
F_211 ( struct V_67 * V_68 )
{
struct V_277 * V_278 = F_146 ( V_68 ) ;
return ( ! V_278 -> V_64 . V_366 &&
F_212 ( V_278 , V_316 ) ) ||
( V_278 -> V_64 . V_366 &&
V_278 -> V_365 . V_327 . V_336 == V_454 ) ;
}
T_4
F_181 ( struct V_67 * V_68 )
{
struct V_277 * V_278 = F_146 ( V_68 ) ;
return V_278 -> V_64 . V_334 ;
}
T_4
F_182 ( struct V_67 * V_68 )
{
struct V_277 * V_278 = F_146 ( V_68 ) ;
return V_278 -> V_64 . V_366 ;
}
T_7
F_213 ( struct V_67 * V_68 , T_4 V_558 , V_37 V_559 )
{
struct V_277 * V_278 = F_146 ( V_68 ) ;
F_34 ( V_68 , V_558 ) ;
if ( F_177 ( & V_278 -> V_68 -> V_264 ) != V_510 )
return V_560 ;
if ( F_183 ( V_68 -> V_264 . V_327 -> V_521 ) &&
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
( V_278 -> V_64 . V_380 < F_167 ( & V_68 -> V_264 ) ) )
return V_564 ;
if ( F_167 ( & V_68 -> V_264 ) < V_514 )
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
F_214 ( struct V_67 * V_68 ,
struct V_570 * V_408 )
{
struct V_277 * V_278 = F_146 ( V_68 ) ;
if ( F_177 ( & V_278 -> V_68 -> V_264 ) != V_510 )
return V_560 ;
if ( V_278 -> V_64 . V_378 == V_405 )
return V_563 ;
* V_408 = V_278 -> V_408 ;
return V_134 ;
}
void
F_215 ( struct V_67 * V_68 )
{
F_85 ( F_146 ( V_68 ) , V_346 ) ;
F_216 ( & V_68 -> V_468 . V_284 , V_58 ) ;
}
void
F_217 ( struct V_67 * V_68 )
{
F_85 ( F_146 ( V_68 ) , V_350 ) ;
F_216 ( & V_68 -> V_468 . V_284 , V_59 ) ;
}
void
F_218 ( struct V_67 * V_68 )
{
F_85 ( F_146 ( V_68 ) , V_348 ) ;
}
void
F_219 ( struct V_67 * V_68 )
{
F_85 ( F_146 ( V_68 ) , V_351 ) ;
}
static void
F_220 ( struct V_149 * V_571 , enum V_572 V_25 )
{
F_34 ( V_571 -> V_68 , V_571 -> V_573 ) ;
F_34 ( V_571 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_574 :
F_221 ( V_571 , V_575 ) ;
F_80 ( V_571 , V_576 ) ;
break;
default:
F_221 ( V_571 , V_577 ) ;
F_84 ( V_571 -> V_68 , V_25 ) ;
}
}
static void
V_576 ( struct V_149 * V_571 , enum V_572 V_25 )
{
F_34 ( V_571 -> V_68 , V_571 -> V_573 ) ;
F_34 ( V_571 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_578 :
F_221 ( V_571 , V_579 ) ;
if ( F_222 ( V_571 ) )
F_80 ( V_571 , V_580 ) ;
else
F_80 ( V_571 , V_581 ) ;
break;
case V_582 :
F_221 ( V_571 , V_583 ) ;
F_80 ( V_571 , F_220 ) ;
F_223 ( V_571 ) ;
break;
case V_584 :
F_221 ( V_571 , V_585 ) ;
F_80 ( V_571 , V_586 ) ;
break;
default:
F_221 ( V_571 , V_587 ) ;
F_84 ( V_571 -> V_68 , V_25 ) ;
}
}
static void
V_580 ( struct V_149 * V_571 , enum V_572 V_25 )
{
F_34 ( V_571 -> V_68 , V_571 -> V_573 ) ;
F_34 ( V_571 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_588 :
F_221 ( V_571 , V_589 ) ;
F_80 ( V_571 , V_590 ) ;
F_224 ( V_571 ) ;
break;
case V_582 :
F_221 ( V_571 , V_591 ) ;
F_80 ( V_571 , V_592 ) ;
break;
case V_593 :
F_221 ( V_571 , V_594 ) ;
F_80 ( V_571 , V_595 ) ;
break;
case V_584 :
F_221 ( V_571 , V_596 ) ;
F_80 ( V_571 , V_586 ) ;
break;
default:
F_221 ( V_571 , V_597 ) ;
F_84 ( V_571 -> V_68 , V_25 ) ;
}
}
static void
V_581 ( struct V_149 * V_571 , enum V_572 V_25 )
{
F_34 ( V_571 -> V_68 , V_571 -> V_573 ) ;
F_34 ( V_571 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_598 :
F_80 ( V_571 , V_580 ) ;
F_222 ( V_571 ) ;
break;
case V_582 :
F_221 ( V_571 , V_591 ) ;
F_80 ( V_571 , F_220 ) ;
F_73 ( & V_571 -> V_302 ) ;
F_223 ( V_571 ) ;
break;
case V_593 :
F_221 ( V_571 , V_594 ) ;
F_80 ( V_571 , V_599 ) ;
F_73 ( & V_571 -> V_302 ) ;
F_225 ( V_571 ) ;
break;
case V_584 :
F_221 ( V_571 , V_596 ) ;
F_80 ( V_571 , V_586 ) ;
F_73 ( & V_571 -> V_302 ) ;
break;
default:
F_221 ( V_571 , V_597 ) ;
F_84 ( V_571 -> V_68 , V_25 ) ;
}
}
static void
V_590 ( struct V_149 * V_571 , enum V_572 V_25 )
{
struct V_600 * V_601 ;
F_34 ( V_571 -> V_68 , V_571 -> V_573 ) ;
F_34 ( V_571 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_593 :
F_221 ( V_571 , V_602 ) ;
if ( F_226 ( V_571 ) )
F_80 ( V_571 , V_603 ) ;
else
F_80 ( V_571 , V_604 ) ;
break;
case V_582 :
F_221 ( V_571 , V_605 ) ;
if ( F_226 ( V_571 ) )
F_80 ( V_571 , V_606 ) ;
else
F_80 ( V_571 , V_607 ) ;
break;
case V_584 :
F_221 ( V_571 , V_608 ) ;
F_80 ( V_571 , V_586 ) ;
break;
case V_609 :
F_227 ( V_571 ) ;
break;
case V_610 :
V_601 = (struct V_600 * ) V_571 -> V_323 . V_611 ;
V_571 -> V_335 = V_601 -> V_612 ;
F_34 ( V_571 -> V_68 , V_601 -> V_613 . V_614 ) ;
F_34 ( V_571 -> V_68 , V_601 -> V_612 . V_614 ) ;
F_34 ( V_571 -> V_68 , V_601 -> V_613 . V_615 ) ;
F_34 ( V_571 -> V_68 , V_601 -> V_612 . V_615 ) ;
V_601 -> V_613 . V_614 =
F_42 ( V_601 -> V_613 . V_614 ) ;
V_601 -> V_612 . V_614 =
F_42 ( V_601 -> V_612 . V_614 ) ;
if ( V_601 -> V_613 . V_614 !=
V_601 -> V_612 . V_614 )
F_228 ( V_571 -> V_616 ,
V_601 -> V_613 ,
V_601 -> V_612 ) ;
if ( V_601 -> V_613 . V_615 !=
V_601 -> V_612 . V_615 )
F_229 ( V_571 -> V_616 ,
V_601 -> V_613 ,
V_601 -> V_612 ) ;
break;
default:
F_221 ( V_571 , V_617 ) ;
F_84 ( V_571 -> V_68 , V_25 ) ;
}
}
static void
V_603 ( struct V_149 * V_571 , enum V_572 V_25 )
{
F_34 ( V_571 -> V_68 , V_571 -> V_573 ) ;
F_34 ( V_571 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_588 :
F_221 ( V_571 , V_618 ) ;
F_80 ( V_571 , V_599 ) ;
F_225 ( V_571 ) ;
break;
case V_582 :
F_221 ( V_571 , V_619 ) ;
F_80 ( V_571 , V_606 ) ;
break;
case V_584 :
F_221 ( V_571 , V_620 ) ;
F_80 ( V_571 , V_586 ) ;
F_225 ( V_571 ) ;
break;
default:
F_221 ( V_571 , V_621 ) ;
F_84 ( V_571 -> V_68 , V_25 ) ;
}
}
static void
V_604 ( struct V_149 * V_571 , enum V_572 V_25 )
{
F_34 ( V_571 -> V_68 , V_571 -> V_573 ) ;
F_34 ( V_571 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_598 :
F_80 ( V_571 , V_603 ) ;
F_226 ( V_571 ) ;
break;
case V_582 :
F_221 ( V_571 , V_619 ) ;
F_80 ( V_571 , V_607 ) ;
break;
case V_584 :
F_221 ( V_571 , V_620 ) ;
F_80 ( V_571 , V_586 ) ;
F_73 ( & V_571 -> V_302 ) ;
F_225 ( V_571 ) ;
break;
default:
F_221 ( V_571 , V_621 ) ;
F_84 ( V_571 -> V_68 , V_25 ) ;
}
}
static void
V_599 ( struct V_149 * V_571 , enum V_572 V_25 )
{
F_34 ( V_571 -> V_68 , V_571 -> V_573 ) ;
F_34 ( V_571 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_582 :
F_221 ( V_571 , V_622 ) ;
F_80 ( V_571 , F_220 ) ;
F_223 ( V_571 ) ;
break;
case V_578 :
F_221 ( V_571 , V_623 ) ;
if ( F_222 ( V_571 ) )
F_80 ( V_571 , V_580 ) ;
else
F_80 ( V_571 , V_581 ) ;
break;
case V_584 :
F_221 ( V_571 , V_624 ) ;
F_80 ( V_571 , V_586 ) ;
break;
case V_593 :
F_225 ( V_571 ) ;
break;
default:
F_221 ( V_571 , V_625 ) ;
F_84 ( V_571 -> V_68 , V_25 ) ;
}
}
static void
V_606 ( struct V_149 * V_571 , enum V_572 V_25 )
{
F_34 ( V_571 -> V_68 , V_571 -> V_573 ) ;
F_34 ( V_571 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_588 :
F_221 ( V_571 , V_626 ) ;
F_80 ( V_571 , F_220 ) ;
F_223 ( V_571 ) ;
break;
case V_584 :
F_221 ( V_571 , V_627 ) ;
F_80 ( V_571 , F_220 ) ;
F_223 ( V_571 ) ;
break;
default:
F_84 ( V_571 -> V_68 , V_25 ) ;
}
}
static void
V_607 ( struct V_149 * V_571 , enum V_572 V_25 )
{
F_34 ( V_571 -> V_68 , V_571 -> V_573 ) ;
F_34 ( V_571 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_598 :
F_221 ( V_571 , V_626 ) ;
F_80 ( V_571 , V_606 ) ;
F_226 ( V_571 ) ;
break;
case V_584 :
F_221 ( V_571 , V_627 ) ;
F_80 ( V_571 , F_220 ) ;
F_73 ( & V_571 -> V_302 ) ;
F_223 ( V_571 ) ;
break;
default:
F_84 ( V_571 -> V_68 , V_25 ) ;
}
}
static void
V_592 ( struct V_149 * V_571 ,
enum V_572 V_25 )
{
F_34 ( V_571 -> V_68 , V_571 -> V_573 ) ;
F_34 ( V_571 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_588 :
F_221 ( V_571 , V_628 ) ;
if ( F_226 ( V_571 ) )
F_80 ( V_571 , V_606 ) ;
else
F_80 ( V_571 , V_607 ) ;
break;
case V_584 :
F_221 ( V_571 , V_629 ) ;
F_80 ( V_571 , F_220 ) ;
F_223 ( V_571 ) ;
break;
default:
F_221 ( V_571 , V_630 ) ;
F_84 ( V_571 -> V_68 , V_25 ) ;
}
}
static void
V_595 ( struct V_149 * V_571 ,
enum V_572 V_25 )
{
F_34 ( V_571 -> V_68 , V_571 -> V_573 ) ;
F_34 ( V_571 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_588 :
F_221 ( V_571 , V_631 ) ;
if ( F_226 ( V_571 ) )
F_80 ( V_571 , V_603 ) ;
else
F_80 ( V_571 , V_604 ) ;
break;
case V_582 :
F_221 ( V_571 , V_632 ) ;
F_80 ( V_571 , V_592 ) ;
break;
case V_584 :
F_221 ( V_571 , V_633 ) ;
F_80 ( V_571 , V_586 ) ;
F_225 ( V_571 ) ;
break;
default:
F_221 ( V_571 , V_634 ) ;
F_84 ( V_571 -> V_68 , V_25 ) ;
}
}
static void
V_586 ( struct V_149 * V_571 , enum V_572 V_25 )
{
F_34 ( V_571 -> V_68 , V_571 -> V_573 ) ;
F_34 ( V_571 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_593 :
F_221 ( V_571 , V_635 ) ;
F_225 ( V_571 ) ;
break;
case V_582 :
F_221 ( V_571 , V_636 ) ;
F_80 ( V_571 , F_220 ) ;
F_223 ( V_571 ) ;
break;
case V_578 :
F_221 ( V_571 , V_637 ) ;
if ( F_222 ( V_571 ) )
F_80 ( V_571 , V_580 ) ;
else
F_80 ( V_571 , V_581 ) ;
break;
case V_584 :
break;
default:
F_221 ( V_571 , V_638 ) ;
F_84 ( V_571 -> V_68 , V_25 ) ;
}
}
static void
F_230 ( void * V_125 , T_4 V_130 )
{
struct V_149 * V_571 = V_125 ;
if ( V_130 )
F_231 ( V_571 -> V_616 ) ;
}
static void
F_232 ( void * V_125 , T_4 V_130 )
{
struct V_149 * V_571 = V_125 ;
if ( V_130 )
F_233 ( V_571 -> V_616 ) ;
}
static void
F_234 ( void * V_125 )
{
struct V_149 * V_571 = V_125 ;
F_85 ( V_571 , V_598 ) ;
}
void
F_235 ( struct V_63 * V_64 , struct V_65 * V_66 ,
struct V_67 * V_68 )
{
struct V_69 * V_639 = F_236 ( V_68 ) ;
if ( V_64 -> V_76 . V_640 < V_641 )
V_64 -> V_76 . V_640 = V_641 ;
F_24 ( V_66 , V_639 ,
V_64 -> V_76 . V_640 * sizeof( struct V_149 ) ) ;
}
void
F_237 ( struct V_67 * V_68 , void * V_83 , struct V_63 * V_64 ,
struct V_84 * V_85 )
{
struct V_642 * V_44 = F_238 ( V_68 ) ;
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
F_80 ( V_571 , F_220 ) ;
if ( V_35 )
F_15 ( & V_571 -> V_56 , & V_44 -> V_643 ) ;
F_16 ( & V_571 -> V_302 , F_234 , V_571 ) ;
}
F_13 ( V_44 ) = ( V_37 * ) V_571 ;
}
void
F_239 ( struct V_67 * V_68 )
{
struct V_642 * V_44 = F_238 ( V_68 ) ;
struct V_149 * V_150 ;
struct V_90 * V_56 , * V_91 ;
F_27 ( & V_44 -> V_645 , & V_44 -> V_643 ) ;
F_28 (qe, qen, &mod->rp_active_q) {
V_150 = (struct V_149 * ) V_56 ;
F_85 ( V_150 , V_584 ) ;
}
}
static struct V_149 *
F_240 ( struct V_642 * V_44 )
{
struct V_149 * V_150 ;
F_32 ( & V_44 -> V_643 , & V_150 ) ;
if ( V_150 )
F_15 ( & V_150 -> V_56 , & V_44 -> V_644 ) ;
return V_150 ;
}
static void
F_223 ( struct V_149 * V_150 )
{
struct V_642 * V_44 = F_238 ( V_150 -> V_68 ) ;
F_5 ( ! F_37 ( & V_44 -> V_644 , V_150 ) ) ;
F_38 ( & V_150 -> V_56 ) ;
F_15 ( & V_150 -> V_56 , & V_44 -> V_643 ) ;
}
static T_4
F_222 ( struct V_149 * V_571 )
{
struct V_647 * V_248 ;
V_248 = F_48 ( V_571 -> V_68 , V_648 ) ;
if ( ! V_248 ) {
F_67 ( V_571 -> V_68 , V_648 , & V_571 -> V_302 ) ;
return V_59 ;
}
F_50 ( V_248 -> V_152 , V_649 , V_650 ,
F_51 ( V_571 -> V_68 ) ) ;
V_248 -> V_651 = V_571 -> V_573 ;
V_248 -> V_157 = F_52 ( V_571 -> V_158 . V_157 ) ;
V_248 -> V_268 = V_571 -> V_158 . V_268 ;
V_248 -> V_161 = F_53 ( V_571 -> V_68 , ( V_37 ) V_571 -> V_158 . V_162 ) ;
V_248 -> V_652 = V_571 -> V_158 . V_652 ;
V_248 -> V_653 = V_571 -> V_158 . V_653 ;
V_248 -> V_654 = V_571 -> V_158 . V_654 ;
V_248 -> V_160 = V_571 -> V_158 . V_160 ;
V_248 -> V_655 = V_571 -> V_158 . V_655 ;
F_58 ( V_571 -> V_68 , V_648 , V_248 -> V_152 ) ;
return V_58 ;
}
static T_4
F_226 ( struct V_149 * V_571 )
{
struct V_656 * V_248 ;
V_248 = F_48 ( V_571 -> V_68 , V_648 ) ;
if ( ! V_248 ) {
F_67 ( V_571 -> V_68 , V_648 , & V_571 -> V_302 ) ;
return V_59 ;
}
F_50 ( V_248 -> V_152 , V_649 , V_657 ,
F_51 ( V_571 -> V_68 ) ) ;
V_248 -> V_156 = V_571 -> V_156 ;
F_58 ( V_571 -> V_68 , V_648 , V_248 -> V_152 ) ;
return V_58 ;
}
static T_4
F_227 ( struct V_149 * V_571 )
{
struct V_658 * V_248 ;
V_248 = F_48 ( V_571 -> V_68 , V_648 ) ;
if ( ! V_248 ) {
F_34 ( V_571 -> V_68 , V_571 -> V_158 . V_380 ) ;
return V_59 ;
}
F_50 ( V_248 -> V_152 , V_649 , V_659 ,
F_51 ( V_571 -> V_68 ) ) ;
V_248 -> V_156 = V_571 -> V_156 ;
V_248 -> V_380 = ( V_37 ) V_571 -> V_158 . V_380 ;
F_58 ( V_571 -> V_68 , V_648 , V_248 -> V_152 ) ;
return V_58 ;
}
void
F_241 ( struct V_67 * V_68 , struct V_175 * V_248 )
{
union V_660 V_176 ;
struct V_149 * V_571 ;
F_34 ( V_68 , V_248 -> V_177 . V_178 ) ;
V_176 . V_176 = V_248 ;
switch ( V_248 -> V_177 . V_178 ) {
case V_661 :
V_571 = F_242 ( V_68 , V_176 . V_662 -> V_651 ) ;
V_571 -> V_156 = V_176 . V_662 -> V_156 ;
V_571 -> V_335 = V_176 . V_662 -> V_335 ;
F_243 ( V_68 , V_571 ) ;
F_5 ( V_176 . V_662 -> V_198 != V_134 ) ;
F_85 ( V_571 , V_588 ) ;
break;
case V_663 :
V_571 = F_242 ( V_68 , V_176 . V_664 -> V_651 ) ;
F_5 ( V_176 . V_664 -> V_198 != V_134 ) ;
F_244 ( V_68 , V_571 ) ;
F_85 ( V_571 , V_588 ) ;
break;
case V_665 :
V_571 = F_242 ( V_68 , V_176 . V_666 -> V_651 ) ;
V_571 -> V_323 . V_611 = V_176 . V_666 ;
F_85 ( V_571 , V_610 ) ;
break;
case V_667 :
F_150 ( F_146 ( V_68 ) ,
& V_176 . V_668 -> V_397 ) ;
F_245 ( V_68 ) ;
break;
case V_669 :
F_246 ( V_68 ) ;
break;
case V_670 :
V_571 = F_242 ( V_68 , V_176 . V_668 -> V_651 ) ;
F_247 ( V_571 -> V_616 ) ;
break;
default:
F_34 ( V_68 , V_248 -> V_177 . V_178 ) ;
F_5 ( 1 ) ;
}
}
void
F_248 ( struct V_67 * V_68 , T_2 V_671 )
{
struct V_642 * V_44 = F_238 ( V_68 ) ;
struct V_90 * V_56 ;
int V_35 ;
for ( V_35 = 0 ; V_35 < ( V_44 -> V_640 - V_671 ) ; V_35 ++ ) {
F_77 ( & V_44 -> V_643 , & V_56 ) ;
F_15 ( V_56 , & V_44 -> V_645 ) ;
}
}
struct V_149 *
F_249 ( struct V_67 * V_68 , void * V_616 )
{
struct V_149 * V_571 ;
V_571 = F_240 ( F_238 ( V_68 ) ) ;
if ( V_571 == NULL )
return NULL ;
V_571 -> V_68 = V_68 ;
V_571 -> V_616 = V_616 ;
memset ( & V_571 -> V_372 , 0 , sizeof( V_571 -> V_372 ) ) ;
F_5 ( ! F_212 ( V_571 , F_220 ) ) ;
F_85 ( V_571 , V_574 ) ;
return V_571 ;
}
void
F_250 ( struct V_149 * V_150 , struct V_672 * V_158 )
{
F_5 ( V_158 -> V_157 == 0 ) ;
if ( V_158 -> V_157 == 0 ) {
F_34 ( V_150 -> V_68 , V_150 -> V_573 ) ;
V_158 -> V_157 = V_528 ;
}
V_150 -> V_158 = * V_158 ;
F_85 ( V_150 , V_578 ) ;
}
void
F_251 ( struct V_149 * V_150 , enum V_506 V_380 )
{
F_5 ( V_380 == 0 ) ;
F_5 ( V_380 == V_381 ) ;
if ( V_150 ) {
V_150 -> V_158 . V_380 = V_380 ;
F_85 ( V_150 , V_609 ) ;
}
}
void
F_243 ( struct V_67 * V_68 , struct V_149 * V_571 )
{
struct V_211 * V_673 = F_93 ( V_68 ) ;
T_10 V_674 , V_675 ;
V_37 V_162 = ( V_37 ) V_571 -> V_158 . V_162 ;
V_675 = ( (struct V_676 * ) V_571 -> V_616 ) -> V_254 ;
V_674 = ( F_96 ( V_673 , V_571 -> V_158 . V_162 ) ) -> V_254 ;
F_96 ( V_673 , V_571 -> V_158 . V_162 ) -> V_677 =
V_571 -> V_677 = V_58 ;
F_252 ( V_68 , V_674 , V_675 , V_571 -> V_573 , V_162 ) ;
}
void
F_244 ( struct V_67 * V_68 , struct V_149 * V_571 )
{
struct V_211 * V_673 = F_93 ( V_68 ) ;
T_10 V_674 , V_675 ;
V_675 = ( (struct V_676 * ) V_571 -> V_616 ) -> V_254 ;
V_674 = ( F_96 ( V_673 , V_571 -> V_158 . V_162 ) ) -> V_254 ;
F_96 ( V_673 , V_571 -> V_158 . V_162 ) -> V_677 =
V_571 -> V_677 = V_59 ;
F_252 ( V_68 , V_674 , V_675 ,
V_678 , V_679 ) ;
}
void
F_253 ( struct V_63 * V_64 , struct V_65 * V_66 ,
struct V_67 * V_68 )
{
struct V_680 * V_681 = F_254 ( V_68 ) ;
struct V_69 * V_682 = F_255 ( V_68 ) ;
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
void
F_256 ( struct V_67 * V_68 , void * V_83 , struct V_63 * V_64 ,
struct V_84 * V_85 )
{
struct V_680 * V_44 = F_254 ( V_68 ) ;
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
F_34 ( V_68 , V_64 -> V_79 . V_687 ) ;
V_44 -> V_701 = V_44 -> V_687 = V_64 -> V_79 . V_687 ;
V_684 = V_64 -> V_79 . V_687 ;
V_73 = F_20 ( V_684 , V_685 ) ;
V_691 = (struct V_690 * ) F_13 ( V_44 ) ;
F_22 (mod, seg_ptr, nsegs, idx) {
if ( ! F_143 ( V_72 ) )
break;
V_693 = F_257 ( F_144 ( V_72 ) ) -
F_144 ( V_72 ) ;
V_692 = (struct V_686 * )
( ( ( V_37 * ) F_143 ( V_72 ) ) + V_693 ) ;
V_697 . V_694 = F_144 ( V_72 ) + V_693 ;
F_5 ( V_697 . V_694 & ( V_685 - 1 ) ) ;
V_683 = ( V_72 -> V_702 - ( T_3 ) V_693 ) / V_685 ;
for ( V_35 = 0 ; V_684 > 0 && V_35 < V_683 ; V_35 ++ , V_684 -- ) {
memset ( V_691 , 0 , sizeof( * V_691 ) ) ;
memset ( V_692 , 0 , sizeof( * V_692 ) ) ;
V_691 -> V_692 = V_692 ;
V_698 . V_694 = F_258 ( V_697 . V_694 ) ;
V_691 -> V_697 = V_698 . V_696 ;
F_15 ( & V_691 -> V_56 , & V_44 -> V_699 ) ;
V_692 ++ ;
V_691 ++ ;
V_697 . V_694 += V_685 ;
}
}
F_13 ( V_44 ) = ( V_37 * ) V_691 ;
}
T_7
F_259 ( struct V_67 * V_68 , struct V_90 * V_699 , int V_703 )
{
struct V_680 * V_44 = F_254 ( V_68 ) ;
struct V_690 * V_691 ;
int V_35 ;
if ( V_44 -> V_701 < V_703 )
return V_704 ;
for ( V_35 = 0 ; V_35 < V_703 ; V_35 ++ ) {
F_32 ( & V_44 -> V_699 , & V_691 ) ;
F_5 ( ! V_691 ) ;
F_15 ( & V_691 -> V_56 , V_699 ) ;
}
V_44 -> V_701 -= V_703 ;
return V_134 ;
}
void
F_260 ( struct V_67 * V_68 , struct V_90 * V_699 , int V_705 )
{
struct V_680 * V_44 = F_254 ( V_68 ) ;
struct V_706 * V_121 ;
V_44 -> V_701 += V_705 ;
F_5 ( V_44 -> V_701 > V_44 -> V_687 ) ;
F_27 ( V_699 , & V_44 -> V_699 ) ;
if ( F_70 ( & V_44 -> V_700 ) )
return;
do {
V_121 = F_261 ( & V_44 -> V_700 ) ;
if ( V_44 -> V_701 < V_121 -> V_705 )
V_705 = V_44 -> V_701 ;
else
V_705 = V_121 -> V_705 ;
F_259 ( V_68 , & V_121 -> V_699 , V_705 ) ;
V_121 -> V_705 -= V_705 ;
if ( V_121 -> V_705 == 0 ) {
F_38 ( & V_121 -> V_56 ) ;
V_121 -> V_174 ( V_121 -> V_125 ) ;
}
} while ( V_44 -> V_701 && ! F_70 ( & V_44 -> V_700 ) );
}
void
F_262 ( struct V_67 * V_68 , struct V_706 * V_121 , int V_705 )
{
struct V_680 * V_44 = F_254 ( V_68 ) ;
F_5 ( V_705 <= 0 ) ;
F_5 ( V_705 <= V_44 -> V_701 ) ;
V_121 -> V_707 = V_121 -> V_705 = V_705 ;
if ( V_44 -> V_701 ) {
F_5 ( ! F_70 ( & V_44 -> V_700 ) ) ;
F_27 ( & V_44 -> V_699 , & V_121 -> V_699 ) ;
V_121 -> V_705 -= V_44 -> V_701 ;
V_44 -> V_701 = 0 ;
}
F_15 ( & V_121 -> V_56 , & V_44 -> V_700 ) ;
}
void
F_263 ( struct V_67 * V_68 , struct V_706 * V_121 )
{
struct V_680 * V_44 = F_254 ( V_68 ) ;
F_5 ( ! F_37 ( & V_44 -> V_700 , V_121 ) ) ;
F_38 ( & V_121 -> V_56 ) ;
if ( V_121 -> V_707 != V_121 -> V_705 )
F_260 ( V_68 , & V_121 -> V_699 ,
V_121 -> V_707 - V_121 -> V_705 ) ;
}
void
F_264 ( struct V_706 * V_121 , void (* V_174) ( void * V_125 ) ,
void * V_125 )
{
F_14 ( & V_121 -> V_699 ) ;
V_121 -> V_174 = V_174 ;
V_121 -> V_125 = V_125 ;
}
static void
F_265 ( void * V_125 , T_4 V_130 )
{
struct V_708 * V_709 = V_125 ;
struct V_710 * V_711 = F_266 ( V_709 -> V_68 ) ;
if ( V_130 )
V_711 -> V_712 ( V_711 -> V_125 , V_709 ) ;
}
static void
F_267 ( struct V_710 * V_711 )
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
V_714 -> V_715 = F_52 ( V_715 ) ;
F_50 ( V_714 -> V_152 , V_720 , V_721 ,
F_51 ( V_711 -> V_68 ) ) ;
F_55 ( & V_714 -> V_722 , V_715 , F_268 ( V_711 , V_35 ) ) ;
}
F_13 ( V_711 ) = ( V_37 * ) V_714 ;
}
static void
F_269 ( struct V_710 * V_711 )
{
T_2 V_35 ;
struct V_708 * V_709 ;
V_711 -> V_723 = (struct V_708 * ) F_13 ( V_711 ) ;
for ( V_35 = 0 , V_709 = V_711 -> V_723 ; V_35 < V_711 -> V_717 ; V_35 ++ , V_709 ++ ) {
memset ( V_709 , 0 , sizeof( struct V_708 ) ) ;
V_709 -> V_68 = V_711 -> V_68 ;
V_709 -> V_724 = V_35 ;
V_709 -> V_725 = V_726 ;
V_709 -> V_727 = F_63 ( V_711 , V_35 , V_726 ) ;
V_709 -> V_728 = F_268 ( V_711 , V_35 ) ;
F_15 ( & V_709 -> V_56 , & V_711 -> V_729 ) ;
}
F_13 ( V_711 ) = ( V_37 * ) V_709 ;
}
static void
F_270 ( struct V_710 * V_711 )
{
F_269 ( V_711 ) ;
F_267 ( V_711 ) ;
}
void
F_271 ( struct V_63 * V_64 , struct V_65 * V_66 ,
struct V_67 * V_68 )
{
struct V_710 * V_711 = F_266 ( V_68 ) ;
struct V_69 * V_730 = F_272 ( V_68 ) ;
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
void
F_273 ( struct V_67 * V_68 , void * V_83 , struct V_63 * V_64 ,
struct V_84 * V_85 )
{
struct V_710 * V_711 = F_266 ( V_68 ) ;
V_711 -> V_68 = V_68 ;
V_711 -> V_717 = V_64 -> V_76 . V_731 ;
F_14 ( & V_711 -> V_729 ) ;
F_14 ( & V_711 -> V_733 ) ;
F_14 ( & V_711 -> V_734 ) ;
F_270 ( V_711 ) ;
}
static struct V_708 *
F_274 ( struct V_710 * V_735 )
{
struct V_708 * V_709 ;
F_32 ( & V_735 -> V_729 , & V_709 ) ;
return V_709 ;
}
static void
F_275 ( struct V_710 * V_735 , struct V_708 * V_709 )
{
F_15 ( & V_709 -> V_56 , & V_735 -> V_729 ) ;
}
static T_7
F_276 ( struct V_710 * V_711 , struct V_708 * V_709 )
{
struct V_713 * V_736 ;
V_736 = F_48 ( V_711 -> V_68 , V_142 ) ;
if ( ! V_736 )
return V_737 ;
memcpy ( V_736 , & V_711 -> V_716 [ V_709 -> V_724 ] ,
sizeof( struct V_713 ) ) ;
F_58 ( V_711 -> V_68 , V_142 , V_736 -> V_152 ) ;
F_34 ( V_711 -> V_68 , V_709 -> V_724 ) ;
F_15 ( & V_709 -> V_56 , & V_711 -> V_733 ) ;
return V_134 ;
}
static void
F_277 ( struct V_710 * V_735 )
{
struct V_708 * V_709 ;
while ( ( V_709 = F_274 ( V_735 ) ) != NULL ) {
if ( F_276 ( V_735 , V_709 ) != V_134 )
break;
}
}
static void
F_278 ( struct V_67 * V_68 , struct V_738 * V_248 )
{
struct V_710 * V_711 = F_266 ( V_68 ) ;
T_2 V_724 = V_248 -> V_718 ;
struct V_708 * V_709 = & V_711 -> V_723 [ V_724 ] ;
struct V_719 * V_739 ;
T_13 * V_740 ;
struct V_38 * V_135 ;
V_739 = (struct V_719 * )
F_63 ( V_711 , V_724 , V_709 -> V_725 ) ;
V_740 = & V_739 -> V_426 [ 0 ] ;
V_248 -> V_741 = F_41 ( V_248 -> V_741 ) ;
V_248 -> V_742 = F_41 ( V_248 -> V_742 ) ;
V_135 = (struct V_38 * ) V_739 ;
F_38 ( & V_709 -> V_56 ) ;
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
F_265 ( V_709 , V_58 ) ;
else
F_30 ( V_68 , & V_709 -> V_97 , F_265 , V_709 ) ;
}
void
F_279 ( struct V_67 * V_68 )
{
struct V_710 * V_711 = F_266 ( V_68 ) ;
struct V_708 * V_709 ;
struct V_90 * V_56 , * V_91 ;
F_27 ( & V_711 -> V_734 , & V_711 -> V_729 ) ;
F_28 (qe, qen, &ufm->uf_posted_q) {
V_709 = (struct V_708 * ) V_56 ;
F_38 ( & V_709 -> V_56 ) ;
F_275 ( V_711 , V_709 ) ;
}
}
void
F_280 ( struct V_67 * V_68 )
{
F_277 ( F_266 ( V_68 ) ) ;
}
void
F_281 ( struct V_67 * V_68 , T_14 V_712 , void * V_125 )
{
struct V_710 * V_711 = F_266 ( V_68 ) ;
V_711 -> V_712 = V_712 ;
V_711 -> V_125 = V_125 ;
}
void
F_282 ( struct V_708 * V_709 )
{
F_275 ( F_266 ( V_709 -> V_68 ) , V_709 ) ;
F_277 ( F_266 ( V_709 -> V_68 ) ) ;
}
void
F_283 ( struct V_67 * V_68 , struct V_175 * V_176 )
{
F_34 ( V_68 , V_176 -> V_177 . V_178 ) ;
switch ( V_176 -> V_177 . V_178 ) {
case V_746 :
F_278 ( V_68 , (struct V_738 * ) V_176 ) ;
break;
default:
F_34 ( V_68 , V_176 -> V_177 . V_178 ) ;
F_5 ( 1 ) ;
}
}
void
F_284 ( struct V_67 * V_68 , T_2 V_747 )
{
struct V_710 * V_44 = F_266 ( V_68 ) ;
struct V_90 * V_56 ;
int V_35 ;
for ( V_35 = 0 ; V_35 < ( V_44 -> V_717 - V_747 ) ; V_35 ++ ) {
F_77 ( & V_44 -> V_729 , & V_56 ) ;
F_15 ( V_56 , & V_44 -> V_734 ) ;
}
}
static void
F_285 ( struct V_748 * V_749 )
{
struct V_277 * V_278 = F_146 ( V_749 -> V_68 ) ;
if ( V_749 -> V_750 . V_751 )
V_278 -> V_497 = V_58 ;
else
V_278 -> V_497 = V_59 ;
}
void
F_286 ( struct V_67 * V_68 , void * V_83 , struct V_63 * V_64 ,
struct V_84 * V_85 )
{
struct V_748 * V_749 = F_287 ( V_68 ) ;
struct V_752 * V_753 = & V_749 -> V_753 ;
V_749 -> V_68 = V_68 ;
V_749 -> V_754 = V_68 -> V_754 ;
V_753 -> V_68 = V_68 ;
F_80 ( V_753 , V_755 ) ;
F_16 ( & V_753 -> V_302 , V_756 , V_753 ) ;
V_753 -> V_174 = NULL ;
V_753 -> V_125 = NULL ;
V_753 -> V_757 = V_758 ;
memset ( & V_753 -> V_759 , 0 , sizeof( struct V_760 ) ) ;
}
void
F_288 ( struct V_67 * V_68 )
{
struct V_748 * V_749 = F_287 ( V_68 ) ;
struct V_752 * V_753 = & V_749 -> V_753 ;
F_34 ( V_749 , V_749 -> V_750 . V_751 ) ;
if ( V_749 -> V_750 . V_751 ) {
V_749 -> V_750 . V_198 = V_95 ;
V_749 -> V_750 . V_174 ( V_749 -> V_750 . V_125 , V_749 -> V_750 . V_198 ) ;
V_749 -> V_750 . V_751 = 0 ;
F_285 ( V_749 ) ;
}
F_85 ( V_753 , V_761 ) ;
}
static void
F_289 ( void * V_125 )
{
struct V_748 * V_749 = V_125 ;
struct V_762 * V_763 = V_749 -> V_764 . V_759 ;
F_34 ( V_749 , V_749 -> V_764 . V_765 ) ;
F_34 ( V_749 , V_749 -> V_764 . V_241 ) ;
V_749 -> V_764 . V_766 = 0 ;
V_763 -> V_198 = V_441 ;
V_763 -> V_241 = V_767 - V_749 -> V_764 . V_241 ;
if ( V_749 -> V_764 . V_765 )
V_763 -> V_768 = V_749 -> V_764 . V_765 ;
F_34 ( V_749 , V_441 ) ;
V_749 -> V_764 . V_198 = V_441 ;
V_749 -> V_764 . V_174 ( V_749 -> V_764 . V_125 , V_749 -> V_764 . V_198 ) ;
V_749 -> V_764 . V_751 = 0 ;
}
static T_7
F_290 ( struct V_748 * V_749 )
{
T_3 V_35 ;
struct V_769 * V_100 ;
V_100 = F_48 ( V_749 -> V_68 , V_749 -> V_764 . V_768 ) ;
if ( ! V_100 )
return V_548 ;
F_50 ( V_100 -> V_152 , V_770 , V_771 ,
F_51 ( V_749 -> V_68 ) ) ;
for ( V_35 = 0 ; V_35 < V_772 ; V_35 ++ )
V_100 -> V_435 [ V_35 ] = V_773 ;
F_34 ( V_749 , V_749 -> V_764 . V_768 ) ;
F_58 ( V_749 -> V_68 , V_749 -> V_764 . V_768 , V_100 -> V_152 ) ;
return V_134 ;
}
static void
F_291 ( struct V_748 * V_749 ,
T_15 * V_220 )
{
struct V_762 * V_763 = V_749 -> V_764 . V_759 ;
T_7 V_198 = V_134 ;
int V_35 ;
if ( ! V_749 -> V_764 . V_766 ) {
F_34 ( V_749 , V_749 -> V_764 . V_766 ) ;
return;
}
V_749 -> V_764 . V_241 -- ;
for ( V_35 = 0 ; V_35 < V_772 ; V_35 ++ ) {
if ( V_220 -> V_435 [ V_35 ] != ~ ( V_773 ) ) {
V_763 -> V_198 = V_774 ;
break;
}
}
if ( V_763 -> V_198 == V_134 ) {
if ( V_749 -> V_764 . V_241 > 0 ) {
V_198 = F_290 ( V_749 ) ;
if ( V_198 == V_134 )
return;
else
V_763 -> V_198 = V_198 ;
} else if ( V_749 -> V_764 . V_765 > 0 &&
V_749 -> V_764 . V_768 < ( V_775 - 1 ) ) {
V_749 -> V_764 . V_241 = V_767 ;
V_749 -> V_764 . V_768 ++ ;
V_198 = F_290 ( V_749 ) ;
if ( V_198 == V_134 )
return;
else
V_763 -> V_198 = V_198 ;
}
}
if ( V_749 -> V_764 . V_766 ) {
F_171 ( & V_749 -> V_764 . V_490 ) ;
V_749 -> V_764 . V_766 = 0 ;
}
V_763 -> V_768 = V_749 -> V_764 . V_768 ;
V_763 -> V_241 = V_767 - V_749 -> V_764 . V_241 ;
F_34 ( V_749 , V_763 -> V_241 ) ;
F_34 ( V_749 , V_763 -> V_198 ) ;
V_749 -> V_764 . V_198 = V_763 -> V_198 ;
V_749 -> V_764 . V_174 ( V_749 -> V_764 . V_125 , V_749 -> V_764 . V_198 ) ;
V_749 -> V_764 . V_751 = 0 ;
}
static void
F_292 ( struct V_748 * V_749 ,
struct V_776 * V_220 )
{
struct V_777 * V_763 = V_749 -> V_750 . V_759 ;
V_763 -> V_778 = F_42 ( V_220 -> V_763 . V_778 ) ;
V_763 -> V_779 = F_42 ( V_220 -> V_763 . V_779 ) ;
V_763 -> V_780 = F_42 ( V_220 -> V_763 . V_780 ) ;
V_763 -> V_781 = F_42 ( V_220 -> V_763 . V_781 ) ;
V_763 -> V_782 = F_42 ( V_220 -> V_763 . V_782 ) ;
V_763 -> V_198 = V_220 -> V_763 . V_198 ;
V_749 -> V_750 . V_198 = V_220 -> V_763 . V_198 ;
F_34 ( V_749 , V_749 -> V_750 . V_198 ) ;
V_749 -> V_750 . V_174 ( V_749 -> V_750 . V_125 , V_749 -> V_750 . V_198 ) ;
V_749 -> V_750 . V_751 = 0 ;
F_285 ( V_749 ) ;
}
static T_7
F_293 ( struct V_748 * V_749 ,
struct V_783 * V_784 )
{
struct V_785 * V_786 ;
V_786 = F_48 ( V_749 -> V_68 , V_787 ) ;
if ( ! V_786 )
return V_548 ;
F_50 ( V_786 -> V_152 , V_770 , V_788 ,
F_51 ( V_749 -> V_68 ) ) ;
V_786 -> V_789 = V_784 -> V_789 ;
V_786 -> V_380 = V_784 -> V_380 ;
V_786 -> V_790 = V_784 -> V_790 ;
V_786 -> V_791 = V_784 -> V_791 ;
F_58 ( V_749 -> V_68 , V_787 , V_786 -> V_152 ) ;
F_34 ( V_749 , V_784 -> V_789 ) ;
F_34 ( V_749 , V_784 -> V_380 ) ;
F_34 ( V_749 , V_784 -> V_790 ) ;
F_34 ( V_749 , V_784 -> V_791 ) ;
return V_134 ;
}
void
F_294 ( struct V_67 * V_68 , struct V_175 * V_176 )
{
struct V_748 * V_749 = F_287 ( V_68 ) ;
switch ( V_176 -> V_177 . V_178 ) {
case V_792 :
F_292 ( V_749 ,
(struct V_776 * ) V_176 ) ;
break;
case V_793 :
F_291 ( V_749 , ( T_15 * ) V_176 ) ;
break;
case V_794 :
F_295 ( & V_749 -> V_753 ,
(struct V_795 * ) V_176 ) ;
break;
case V_796 :
F_296 ( & V_749 -> V_753 ,
(struct V_797 * ) V_176 ) ;
break;
default:
F_34 ( V_749 , V_176 -> V_177 . V_178 ) ;
F_5 ( 1 ) ;
}
}
T_7
F_297 ( struct V_67 * V_68 , enum V_798 V_799 ,
enum V_506 V_380 , T_3 V_800 , T_3 V_801 ,
struct V_777 * V_759 , T_16 V_174 ,
void * V_125 )
{
struct V_783 V_784 ;
struct V_532 V_327 ;
T_7 V_198 ;
struct V_748 * V_749 = F_287 ( V_68 ) ;
if ( ! F_202 ( V_68 ) )
return V_547 ;
if ( F_168 ( V_68 ) ) {
F_34 ( V_749 , V_495 ) ;
return V_495 ;
}
if ( F_205 ( V_68 ) == V_59 ) {
F_34 ( V_749 , V_799 ) ;
return V_802 ;
}
if ( F_177 ( & V_68 -> V_264 ) == V_510 ) {
if ( ! ( V_380 == V_384 ||
V_380 == V_512 ||
V_380 == V_513 ||
V_380 == V_514 ||
V_380 == V_508 ||
V_380 == V_381 ) ) {
F_34 ( V_749 , V_380 ) ;
return V_509 ;
}
F_197 ( V_68 , & V_327 ) ;
F_34 ( V_749 , V_327 . V_538 ) ;
if ( V_380 > V_327 . V_538 )
return V_509 ;
} else {
if ( V_380 != V_515 ) {
F_34 ( V_749 , V_380 ) ;
return V_509 ;
}
}
if ( ( V_380 == V_384 ) &&
( F_178 ( V_68 -> V_264 . V_85 . V_511 ) ) ) {
F_34 ( V_749 , V_380 ) ;
return V_509 ;
}
if ( F_183 ( V_68 -> V_264 . V_327 -> V_521 ) ) {
if ( F_177 ( & V_68 -> V_264 ) == V_510 ) {
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
if ( F_184 ( V_68 ) ) {
F_34 ( V_749 , V_749 -> V_750 . V_751 ) ;
return V_803 ;
}
if ( V_749 -> V_750 . V_751 ) {
F_34 ( V_749 , V_749 -> V_750 . V_751 ) ;
return V_548 ;
}
V_749 -> V_750 . V_751 = 1 ;
V_784 . V_789 = V_799 ;
V_784 . V_380 = V_380 ;
V_784 . V_790 = V_800 ;
V_784 . V_791 = V_801 ;
V_749 -> V_750 . V_759 = V_759 ;
V_749 -> V_750 . V_174 = V_174 ;
V_749 -> V_750 . V_125 = V_125 ;
memset ( V_759 , 0 , sizeof( struct V_777 ) ) ;
F_285 ( V_749 ) ;
V_198 = F_293 ( V_749 , & V_784 ) ;
return V_198 ;
}
T_7
F_298 ( struct V_67 * V_68 , T_3 V_804 , T_3 V_768 ,
struct V_762 * V_759 , T_16 V_174 ,
void * V_125 )
{
struct V_748 * V_749 = F_287 ( V_68 ) ;
T_7 V_198 ;
F_34 ( V_749 , V_804 ) ;
F_34 ( V_749 , V_768 ) ;
if ( ! V_804 && ! F_202 ( V_68 ) )
return V_547 ;
if ( V_749 -> V_764 . V_751 ) {
F_34 ( V_749 , V_749 -> V_764 . V_751 ) ;
return V_548 ;
}
V_749 -> V_764 . V_751 = 1 ;
V_749 -> V_764 . V_174 = V_174 ;
V_749 -> V_764 . V_125 = V_125 ;
V_749 -> V_764 . V_759 = V_759 ;
V_749 -> V_764 . V_241 = V_767 ;
V_749 -> V_764 . V_759 -> V_198 = V_134 ;
V_749 -> V_764 . V_759 -> V_241 = 0 ;
if ( V_768 < V_775 ) {
V_749 -> V_764 . V_759 -> V_768 = ( V_37 ) V_768 ;
V_749 -> V_764 . V_768 = ( V_37 ) V_768 ;
V_749 -> V_764 . V_765 = 0 ;
} else {
V_749 -> V_764 . V_759 -> V_768 = 0 ;
V_749 -> V_764 . V_768 = 0 ;
V_749 -> V_764 . V_765 = 1 ;
}
V_198 = F_290 ( V_749 ) ;
if ( V_198 == V_134 ) {
F_203 ( V_68 , & V_749 -> V_764 . V_490 ,
F_289 , V_749 ,
V_805 ) ;
V_749 -> V_764 . V_766 = 1 ;
}
return V_198 ;
}
T_7
F_299 ( struct V_67 * V_68 )
{
struct V_748 * V_749 = F_287 ( V_68 ) ;
return V_749 -> V_750 . V_751 ? V_498 : V_134 ;
}
static void
F_300 ( struct V_752 * V_753 , T_7 V_806 )
{
if ( V_753 -> V_174 != NULL ) {
V_753 -> V_174 ( V_753 -> V_125 , V_806 ) ;
V_753 -> V_174 = NULL ;
V_753 -> V_125 = NULL ;
}
}
static void
V_755 ( struct V_752 * V_753 , enum V_807 V_25 )
{
F_34 ( V_753 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_808 :
F_215 ( V_753 -> V_68 ) ;
if ( F_301 ( V_753 , V_809 ) )
F_80 ( V_753 , V_810 ) ;
else
F_80 ( V_753 , V_811 ) ;
break;
case V_812 :
break;
case V_761 :
break;
case V_813 :
if ( V_753 -> V_324 . V_445 . V_336 == V_814 ) {
F_218 ( V_753 -> V_68 ) ;
V_753 -> V_815 = V_58 ;
V_753 -> V_757 = V_816 ;
F_80 ( V_753 , V_817 ) ;
} else {
F_34 ( V_753 -> V_68 , V_753 -> V_324 . V_445 . V_336 ) ;
F_5 ( 1 ) ;
}
break;
default:
F_84 ( V_753 -> V_68 , V_25 ) ;
}
}
static void
V_811 ( struct V_752 * V_753 ,
enum V_807 V_25 )
{
F_34 ( V_753 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_818 :
F_80 ( V_753 , V_810 ) ;
F_301 ( V_753 , V_809 ) ;
break;
case V_761 :
F_73 ( & V_753 -> V_302 ) ;
F_80 ( V_753 , V_755 ) ;
F_300 ( V_753 , V_737 ) ;
break;
default:
F_84 ( V_753 -> V_68 , V_25 ) ;
}
}
static void
V_810 ( struct V_752 * V_753 , enum V_807 V_25 )
{
F_34 ( V_753 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_819 :
memset ( & V_753 -> V_759 , 0 ,
sizeof( struct V_760 ) ) ;
if ( V_753 -> V_324 . V_220 . V_198 == V_820 ) {
V_753 -> V_757 = V_821 ;
} else {
V_753 -> V_757 = V_822 ;
F_302 ( V_753 , V_823 ) ;
}
F_80 ( V_753 , V_817 ) ;
break;
case V_824 :
V_753 -> V_757 = V_758 ;
F_217 ( V_753 -> V_68 ) ;
F_80 ( V_753 , V_755 ) ;
break;
case V_761 :
F_80 ( V_753 , V_755 ) ;
F_300 ( V_753 , V_737 ) ;
break;
default:
F_84 ( V_753 -> V_68 , V_25 ) ;
}
}
static void
V_817 ( struct V_752 * V_753 , enum V_807 V_25 )
{
F_34 ( V_753 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_825 :
if ( F_301 ( V_753 , V_826 ) )
F_80 ( V_753 , V_827 ) ;
else
F_80 ( V_753 , V_828 ) ;
break;
case V_812 :
F_217 ( V_753 -> V_68 ) ;
if ( F_301 ( V_753 , V_829 ) )
F_80 ( V_753 , V_830 ) ;
else
F_80 ( V_753 , V_831 ) ;
break;
case V_761 :
F_80 ( V_753 , V_755 ) ;
break;
case V_813 :
switch ( V_753 -> V_324 . V_445 . V_336 ) {
case V_832 :
V_753 -> V_757 = V_833 ;
break;
case V_834 :
V_753 -> V_757 = V_822 ;
break;
case V_835 :
case V_836 :
break;
case V_837 :
V_753 -> V_757 = V_821 ;
break;
case V_838 :
F_219 ( V_753 -> V_68 ) ;
if ( F_301 ( V_753 , V_839 ) )
F_80 ( V_753 ,
V_840 ) ;
else
F_80 ( V_753 ,
V_841 ) ;
break;
case V_842 :
F_219 ( V_753 -> V_68 ) ;
F_80 ( V_753 , V_755 ) ;
V_753 -> V_815 = V_59 ;
break;
default:
F_34 ( V_753 -> V_68 , V_753 -> V_324 . V_445 . V_336 ) ;
F_84 ( V_753 -> V_68 , V_25 ) ;
}
break;
default:
F_84 ( V_753 -> V_68 , V_25 ) ;
}
}
static void
V_831 ( struct V_752 * V_753 ,
enum V_807 V_25 )
{
F_34 ( V_753 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_818 :
F_80 ( V_753 , V_830 ) ;
F_301 ( V_753 , V_829 ) ;
break;
case V_761 :
F_80 ( V_753 , V_755 ) ;
F_73 ( & V_753 -> V_302 ) ;
F_300 ( V_753 , V_134 ) ;
break;
case V_813 :
break;
default:
F_84 ( V_753 -> V_68 , V_25 ) ;
}
}
static void
V_830 ( struct V_752 * V_753 , enum V_807 V_25 )
{
F_34 ( V_753 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_819 :
V_753 -> V_757 = V_758 ;
F_80 ( V_753 , V_755 ) ;
break;
case V_761 :
F_80 ( V_753 , V_755 ) ;
F_300 ( V_753 , V_134 ) ;
break;
case V_813 :
break;
default:
F_84 ( V_753 -> V_68 , V_25 ) ;
}
}
static void
V_828 ( struct V_752 * V_753 ,
enum V_807 V_25 )
{
F_34 ( V_753 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_818 :
F_80 ( V_753 , V_827 ) ;
F_301 ( V_753 , V_826 ) ;
break;
case V_761 :
F_73 ( & V_753 -> V_302 ) ;
F_80 ( V_753 , V_755 ) ;
F_300 ( V_753 , V_737 ) ;
break;
default:
F_84 ( V_753 -> V_68 , V_25 ) ;
}
}
static void
V_827 ( struct V_752 * V_753 , enum V_807 V_25 )
{
F_34 ( V_753 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_819 :
memset ( & V_753 -> V_759 , 0 ,
sizeof( struct V_760 ) ) ;
if ( V_753 -> V_324 . V_220 . V_198 == V_820 ) {
V_753 -> V_757 = V_821 ;
} else {
V_753 -> V_757 = V_822 ;
F_302 ( V_753 , V_843 ) ;
}
case V_824 :
F_80 ( V_753 , V_817 ) ;
break;
case V_761 :
F_80 ( V_753 , V_755 ) ;
F_300 ( V_753 , V_737 ) ;
break;
default:
F_84 ( V_753 -> V_68 , V_25 ) ;
}
}
static void
V_840 ( struct V_752 * V_753 ,
enum V_807 V_25 )
{
F_34 ( V_753 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_813 :
switch ( V_753 -> V_324 . V_445 . V_336 ) {
case V_844 :
F_80 ( V_753 , V_755 ) ;
V_753 -> V_815 = V_59 ;
F_173 ( V_753 -> V_68 ) ;
break;
default:
F_34 ( V_753 -> V_68 , V_753 -> V_324 . V_445 . V_336 ) ;
F_84 ( V_753 -> V_68 , V_25 ) ;
}
break;
case V_761 :
F_80 ( V_753 , V_755 ) ;
F_300 ( V_753 , V_134 ) ;
break;
default:
F_84 ( V_753 -> V_68 , V_25 ) ;
}
}
static void
V_841 ( struct V_752 * V_753 ,
enum V_807 V_25 )
{
F_34 ( V_753 -> V_68 , V_25 ) ;
switch ( V_25 ) {
case V_818 :
F_80 ( V_753 , V_840 ) ;
F_301 ( V_753 , V_839 ) ;
break;
case V_761 :
F_80 ( V_753 , V_755 ) ;
F_73 ( & V_753 -> V_302 ) ;
F_300 ( V_753 , V_134 ) ;
break;
case V_813 :
break;
default:
F_84 ( V_753 -> V_68 , V_25 ) ;
}
}
static T_4
F_301 ( struct V_752 * V_753 , enum V_845 V_100 )
{
struct V_846 * V_248 ;
V_248 = F_48 ( V_753 -> V_68 , V_787 ) ;
if ( ! V_248 ) {
F_67 ( V_753 -> V_68 , V_416 , & V_753 -> V_302 ) ;
return V_59 ;
}
F_50 ( V_248 -> V_152 , V_770 , V_847 ,
F_51 ( V_753 -> V_68 ) ) ;
V_248 -> V_100 = V_100 ;
if ( ( V_100 == V_809 ) || ( V_100 == V_826 ) ) {
V_248 -> V_800 = F_54 ( V_753 -> V_800 ) ;
V_248 -> V_848 = F_54 ( V_753 -> V_848 ) ;
}
F_58 ( V_753 -> V_68 , V_787 , V_248 -> V_152 ) ;
return V_58 ;
}
static void
V_756 ( void * V_125 )
{
struct V_752 * V_753 = V_125 ;
F_85 ( V_753 , V_818 ) ;
}
static void
F_295 ( struct V_752 * V_753 , struct V_795 * V_176 )
{
V_176 -> V_198 = F_54 ( V_176 -> V_198 ) ;
V_753 -> V_324 . V_220 . V_198 = V_176 -> V_198 ;
V_753 -> V_849 = V_176 -> V_254 ;
V_753 -> V_850 = V_176 -> V_255 ;
if ( ( V_176 -> V_198 == V_134 ) ||
( V_176 -> V_198 == V_851 ) ) {
F_34 ( V_753 -> V_68 , V_176 -> V_198 ) ;
F_34 ( V_753 -> V_68 , V_753 -> V_849 ) ;
F_34 ( V_753 -> V_68 , V_753 -> V_850 ) ;
F_85 ( V_753 , V_819 ) ;
} else {
F_34 ( V_753 -> V_68 , V_176 -> V_198 ) ;
F_85 ( V_753 , V_824 ) ;
}
F_300 ( V_753 , V_176 -> V_198 ) ;
}
static T_4
F_303 ( struct V_752 * V_753 )
{
if ( F_212 ( V_753 , V_810 ) ||
F_212 ( V_753 , V_811 ) ||
F_212 ( V_753 , V_830 ) ||
F_212 ( V_753 , V_831 ) ||
F_212 ( V_753 , V_827 ) ||
F_212 ( V_753 , V_828 ) ) {
return V_58 ;
} else {
return V_59 ;
}
}
static void
F_296 ( struct V_752 * V_753 , struct V_797 * V_176 )
{
int V_35 ;
T_13 V_852 ;
F_34 ( V_753 -> V_68 , V_176 -> V_336 ) ;
V_753 -> V_324 . V_445 . V_336 = V_176 -> V_336 ;
switch ( V_753 -> V_324 . V_445 . V_336 ) {
case V_832 :
V_753 -> V_759 . V_853 = F_2 () ;
F_34 ( V_753 -> V_68 , V_753 -> V_759 . V_853 ) ;
V_753 -> V_759 . V_198 = V_176 -> V_854 . V_855 . V_198 ;
F_34 ( V_753 -> V_68 , V_753 -> V_759 . V_198 ) ;
V_753 -> V_759 . V_856 =
F_54 ( V_176 -> V_854 . V_855 . V_857 ) ;
V_753 -> V_759 . V_858 =
F_54 ( V_176 -> V_854 . V_855 . V_859 ) ;
V_753 -> V_759 . V_860 =
F_41 ( V_176 -> V_854 . V_855 . V_861 ) ;
V_753 -> V_759 . V_862 = F_41 ( V_176 -> V_854 . V_855 . V_863 ) ;
V_753 -> V_759 . V_380 = V_176 -> V_854 . V_855 . V_380 ;
F_34 ( V_753 -> V_68 , V_753 -> V_759 . V_856 ) ;
F_34 ( V_753 -> V_68 , V_753 -> V_759 . V_858 ) ;
F_34 ( V_753 -> V_68 , V_753 -> V_759 . V_860 ) ;
F_34 ( V_753 -> V_68 , V_753 -> V_759 . V_862 ) ;
F_34 ( V_753 -> V_68 , V_753 -> V_759 . V_380 ) ;
for ( V_35 = V_864 ; V_35 < V_865 ; V_35 ++ ) {
V_753 -> V_759 . V_866 [ V_35 ] . V_198 =
V_176 -> V_854 . V_855 . V_867 [ V_35 ] ;
F_34 ( V_753 -> V_68 , V_753 -> V_759 . V_866 [ V_35 ] . V_198 ) ;
}
break;
case V_835 :
case V_814 :
memset ( & V_753 -> V_759 , 0 ,
sizeof( struct V_760 ) ) ;
break;
case V_834 :
memset ( & V_753 -> V_759 , 0 ,
sizeof( struct V_760 ) ) ;
V_753 -> V_849 = V_176 -> V_854 . V_868 . V_254 ;
V_753 -> V_850 = V_176 -> V_854 . V_868 . V_255 ;
V_753 -> V_800 = F_54 ( V_176 -> V_854 . V_868 . V_869 ) ;
F_302 ( V_753 , V_176 -> V_854 . V_868 . V_870 ) ;
break;
case V_836 :
V_852 = V_176 -> V_854 . V_868 . type ;
V_753 -> V_759 . V_866 [ V_852 ] . V_871 =
F_2 () ;
V_753 -> V_759 . V_866 [ V_852 ] . V_198 =
V_872 ;
F_34 ( V_753 -> V_68 , V_852 ) ;
F_34 ( V_753 -> V_68 ,
V_753 -> V_759 . V_866 [ V_852 ] . V_871 ) ;
break;
case V_837 :
case V_844 :
case V_838 :
case V_842 :
V_753 -> V_759 . V_198 = V_873 ;
break;
default:
F_84 ( V_753 -> V_68 , V_176 -> V_336 ) ;
}
F_85 ( V_753 , V_813 ) ;
}
T_7
F_304 ( struct V_67 * V_68 , T_3 V_800 , T_3 V_801 ,
T_16 V_174 , void * V_125 )
{
struct V_748 * V_749 = F_287 ( V_68 ) ;
struct V_752 * V_753 = & V_749 -> V_753 ;
if ( F_183 ( V_753 -> V_68 -> V_264 . V_327 -> V_521 ) ) {
F_34 ( V_753 -> V_68 , V_495 ) ;
return V_562 ;
}
if ( ! ( F_178 ( V_753 -> V_68 -> V_264 . V_85 . V_511 ) ) ) {
F_34 ( V_753 -> V_68 , V_753 -> V_68 -> V_264 . V_85 . V_511 ) ;
return V_565 ;
}
if ( ! F_202 ( V_68 ) )
return V_547 ;
if ( F_168 ( V_68 ) ) {
F_34 ( V_753 -> V_68 , V_495 ) ;
return V_495 ;
}
if ( F_177 ( & V_68 -> V_264 ) != V_510 ) {
F_34 ( V_753 -> V_68 , F_177 ( & V_68 -> V_264 ) ) ;
return V_874 ;
}
if ( ( F_187 ( V_68 ) == V_405 ) ||
( F_186 ( V_68 ) == V_405 ) ) {
F_34 ( V_753 -> V_68 , 0 ) ;
return V_563 ;
}
if ( F_182 ( V_68 ) ) {
F_34 ( V_753 -> V_68 , 0 ) ;
return V_520 ;
}
if ( F_299 ( V_68 ) ) {
F_34 ( V_753 -> V_68 , 0 ) ;
return V_498 ;
}
if ( ( F_205 ( V_68 ) == V_59 ) &&
( F_184 ( V_68 ) == V_59 ) ) {
F_34 ( V_753 -> V_68 , 0 ) ;
return V_802 ;
}
if ( V_753 -> V_815 )
return V_875 ;
if ( F_303 ( V_753 ) )
return V_548 ;
if ( F_212 ( V_753 , V_817 ) ) {
F_34 ( V_753 -> V_68 , 0 ) ;
return V_803 ;
}
F_34 ( V_753 -> V_68 , V_800 ) ;
F_34 ( V_753 -> V_68 , V_801 ) ;
V_753 -> V_800 = ( V_800 ) ? V_800 : V_876 ;
V_753 -> V_848 = ( V_801 ) ? V_801 : V_877 ;
V_753 -> V_174 = V_174 ;
V_753 -> V_125 = V_125 ;
F_85 ( V_753 , V_808 ) ;
return V_134 ;
}
T_7
F_305 ( struct V_67 * V_68 , T_16 V_174 , void * V_125 )
{
struct V_748 * V_749 = F_287 ( V_68 ) ;
struct V_752 * V_753 = & V_749 -> V_753 ;
if ( F_174 ( & V_68 -> V_264 ) )
return V_496 ;
if ( F_168 ( V_68 ) ) {
F_34 ( V_753 -> V_68 , V_495 ) ;
return V_495 ;
}
if ( V_753 -> V_815 ) {
return V_875 ;
}
if ( ( F_205 ( V_68 ) == V_59 ) &&
( F_184 ( V_68 ) == V_59 ) ) {
F_34 ( V_753 -> V_68 , 0 ) ;
return V_802 ;
}
if ( F_303 ( V_753 ) )
return V_548 ;
if ( F_212 ( V_753 , V_755 ) ) {
F_34 ( V_753 -> V_68 , 0 ) ;
return V_878 ;
}
V_753 -> V_174 = V_174 ;
V_753 -> V_125 = V_125 ;
F_85 ( V_753 , V_812 ) ;
return V_134 ;
}
T_7
F_306 ( struct V_67 * V_68 , T_3 V_800 , T_3 V_801 ,
T_16 V_174 , void * V_125 )
{
struct V_748 * V_749 = F_287 ( V_68 ) ;
struct V_752 * V_753 = & V_749 -> V_753 ;
if ( ! F_202 ( V_68 ) )
return V_547 ;
if ( V_753 -> V_815 )
return V_875 ;
if ( F_303 ( V_753 ) )
return V_548 ;
if ( ! F_212 ( V_753 , V_817 ) ) {
F_34 ( V_753 -> V_68 , 0 ) ;
return V_878 ;
} else {
if ( V_753 -> V_757 == V_821 )
return V_820 ;
if ( V_753 -> V_757 == V_822 )
return V_548 ;
F_5 ( V_753 -> V_757 != V_833 ) ;
}
F_34 ( V_753 -> V_68 , V_800 ) ;
F_34 ( V_753 -> V_68 , V_801 ) ;
V_753 -> V_800 = ( V_800 ) ? V_800 : V_876 ;
V_753 -> V_848 = ( V_801 ) ? V_801 : V_877 ;
V_753 -> V_174 = V_174 ;
V_753 -> V_125 = V_125 ;
F_85 ( V_753 , V_825 ) ;
return V_134 ;
}
T_7
F_307 ( struct V_67 * V_68 , struct V_760 * V_759 )
{
struct V_748 * V_749 = F_287 ( V_68 ) ;
struct V_752 * V_753 = & V_749 -> V_753 ;
if ( ! F_202 ( V_68 ) )
return V_547 ;
if ( F_303 ( V_753 ) )
return V_548 ;
if ( ! F_212 ( V_753 , V_817 ) ) {
F_34 ( V_753 -> V_68 , 0 ) ;
return V_878 ;
}
if ( V_753 -> V_757 == V_821 )
return V_820 ;
memcpy ( V_759 , & V_753 -> V_759 , sizeof( struct V_760 ) ) ;
return V_134 ;
}
