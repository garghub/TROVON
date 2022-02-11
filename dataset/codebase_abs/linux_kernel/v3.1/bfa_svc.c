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
V_44 -> V_51 = V_46 ;
for ( V_35 = 0 ; V_35 < V_44 -> V_47 ; V_35 ++ ) {
V_46 -> V_52 = V_44 ;
V_46 -> V_53 = V_35 ;
F_15 ( & V_46 -> V_54 , & V_44 -> V_48 ) ;
F_16 ( & V_46 -> V_55 , V_56 , V_46 ) ;
V_46 -> V_57 = V_58 ;
V_46 = V_46 + 1 ;
}
F_13 ( V_44 ) = ( void * ) V_46 ;
}
static void
F_17 ( struct V_59 * V_60 , struct V_61 * V_62 ,
struct V_63 * V_64 )
{
struct V_43 * V_52 = F_18 ( V_64 ) ;
struct V_65 * V_66 = F_19 ( V_64 ) ;
struct V_67 * V_68 ;
T_2 V_69 , V_70 , V_71 ;
T_2 V_47 = V_60 -> V_72 . V_73 ;
T_3 V_74 ;
if ( V_47 == 0 )
return;
if ( V_60 -> V_75 . V_76 )
V_74 = 2 * V_77 ;
else
V_74 = V_77 + V_78 ;
V_69 = F_20 ( V_47 , V_74 ) ;
V_71 = F_21 ( V_74 ) ;
F_22 (fcxp_mod, seg_ptr, nsegs, idx) {
if ( V_47 >= V_71 ) {
V_47 -= V_71 ;
F_23 ( V_62 , V_68 ,
V_71 * V_74 ) ;
} else
F_23 ( V_62 , V_68 ,
V_47 * V_74 ) ;
}
F_24 ( V_62 , V_66 ,
V_60 -> V_72 . V_73 * sizeof( struct V_45 ) ) ;
}
static void
F_25 ( struct V_63 * V_64 , void * V_79 , struct V_59 * V_60 ,
struct V_80 * V_81 )
{
struct V_43 * V_44 = F_18 ( V_64 ) ;
V_44 -> V_64 = V_64 ;
V_44 -> V_47 = V_60 -> V_72 . V_73 ;
V_44 -> V_82 = V_44 -> V_83 = V_77 ;
if ( ! V_60 -> V_75 . V_76 )
V_44 -> V_83 = V_78 ;
F_14 ( & V_44 -> V_84 ) ;
F_12 ( V_44 ) ;
}
static void
F_26 ( struct V_63 * V_64 )
{
}
static void
F_27 ( struct V_63 * V_64 )
{
}
static void
F_28 ( struct V_63 * V_64 )
{
}
static void
F_29 ( struct V_63 * V_64 )
{
struct V_43 * V_44 = F_18 ( V_64 ) ;
struct V_45 * V_46 ;
struct V_85 * V_54 , * V_86 ;
F_30 ( & V_44 -> V_50 , & V_44 -> V_48 ) ;
F_31 (qe, qen, &mod->fcxp_active_q) {
V_46 = (struct V_45 * ) V_54 ;
if ( V_46 -> V_87 == NULL ) {
V_46 -> V_88 ( V_46 -> V_87 , V_46 , V_46 -> V_89 ,
V_90 , 0 , 0 , NULL ) ;
F_32 ( V_46 ) ;
} else {
V_46 -> V_91 = V_90 ;
F_33 ( V_64 , & V_46 -> V_92 ,
V_93 , V_46 ) ;
}
}
}
static struct V_45 *
F_34 ( struct V_43 * V_94 )
{
struct V_45 * V_46 ;
F_35 ( & V_94 -> V_48 , & V_46 ) ;
if ( V_46 )
F_15 ( & V_46 -> V_54 , & V_94 -> V_49 ) ;
return V_46 ;
}
static void
F_36 ( struct V_45 * V_46 ,
struct V_63 * V_64 ,
V_37 * V_95 ,
T_3 * V_96 ,
T_4 * V_97 ,
T_5 * V_98 ,
struct V_85 * V_99 ,
int V_100 ,
T_4 V_101 ,
T_5 V_102 )
{
F_5 ( V_64 == NULL ) ;
F_37 ( V_64 , V_46 -> V_53 ) ;
if ( V_100 == 0 ) {
* V_95 = 1 ;
} else {
F_5 ( * V_101 == NULL ) ;
F_5 ( * V_102 == NULL ) ;
* V_95 = 0 ;
* V_97 = V_101 ;
* V_98 = V_102 ;
* V_96 = V_100 ;
if ( V_100 > V_103 )
F_5 ( 1 ) ;
}
}
static void
F_38 ( struct V_45 * V_46 ,
void * V_87 , struct V_63 * V_64 , int V_104 ,
int V_105 , T_4 V_106 ,
T_5 V_107 ,
T_4 V_108 ,
T_5 V_109 )
{
F_5 ( V_64 == NULL ) ;
F_37 ( V_64 , V_46 -> V_53 ) ;
V_46 -> V_87 = V_87 ;
F_36 ( V_46 , V_64 ,
& V_46 -> V_110 , & V_46 -> V_104 , & V_46 -> V_106 ,
& V_46 -> V_107 , & V_46 -> V_111 ,
V_104 , V_106 , V_107 ) ;
F_36 ( V_46 , V_64 ,
& V_46 -> V_112 , & V_46 -> V_105 , & V_46 -> V_108 ,
& V_46 -> V_109 , & V_46 -> V_113 ,
V_105 , V_108 , V_109 ) ;
}
static void
F_39 ( struct V_45 * V_46 )
{
struct V_43 * V_44 = V_46 -> V_52 ;
struct V_114 * V_115 ;
F_35 ( & V_44 -> V_84 , & V_115 ) ;
if ( V_115 ) {
F_37 ( V_44 -> V_64 , V_46 -> V_53 ) ;
F_38 ( V_46 , V_115 -> V_87 , V_115 -> V_64 , V_115 -> V_104 ,
V_115 -> V_105 , V_115 -> V_106 ,
V_115 -> V_107 , V_115 -> V_108 ,
V_115 -> V_109 ) ;
V_115 -> V_116 ( V_115 -> V_117 , V_46 ) ;
return;
}
F_5 ( ! F_40 ( & V_44 -> V_49 , V_46 ) ) ;
F_41 ( & V_46 -> V_54 ) ;
F_15 ( & V_46 -> V_54 , & V_44 -> V_48 ) ;
}
static void
F_42 ( void * V_118 , struct V_45 * V_46 , void * V_119 ,
T_6 V_120 , T_3 V_121 ,
T_3 V_122 , struct V_38 * V_123 )
{
}
static void
V_93 ( void * V_119 , T_7 V_124 )
{
struct V_45 * V_46 = V_119 ;
if ( V_124 ) {
V_46 -> V_88 ( V_46 -> V_87 , V_46 , V_46 -> V_89 ,
V_46 -> V_91 , V_46 -> V_121 ,
V_46 -> V_125 , & V_46 -> V_123 ) ;
} else {
F_32 ( V_46 ) ;
}
}
static void
F_43 ( struct V_63 * V_64 , struct V_126 * V_127 )
{
struct V_43 * V_44 = F_18 ( V_64 ) ;
struct V_45 * V_46 ;
T_2 V_53 = F_44 ( V_127 -> V_53 ) ;
F_37 ( V_64 , V_53 ) ;
V_127 -> V_121 = F_45 ( V_127 -> V_121 ) ;
if ( V_127 -> V_120 == V_128 )
V_127 -> V_125 = 0 ;
else
V_127 -> V_125 = F_45 ( V_127 -> V_125 ) ;
V_46 = F_46 ( V_44 , V_53 ) ;
F_5 ( V_46 -> V_88 == NULL ) ;
F_47 ( V_44 -> V_64 , V_46 , V_127 ) ;
if ( V_46 -> V_88 != NULL ) {
F_37 ( V_44 -> V_64 , ( NULL == V_46 -> V_87 ) ) ;
if ( V_46 -> V_87 == NULL ) {
V_46 -> V_88 ( V_46 -> V_87 , V_46 , V_46 -> V_89 ,
V_127 -> V_120 , V_127 -> V_121 ,
V_127 -> V_125 , & V_127 -> V_129 ) ;
F_32 ( V_46 ) ;
} else {
V_46 -> V_91 = V_127 -> V_120 ;
V_46 -> V_121 = V_127 -> V_121 ;
V_46 -> V_125 = V_127 -> V_125 ;
V_46 -> V_123 = V_127 -> V_129 ;
F_33 ( V_64 , & V_46 -> V_92 ,
V_93 , V_46 ) ;
}
} else {
F_37 ( V_64 , ( NULL == V_46 -> V_88 ) ) ;
}
}
static void
F_48 ( struct V_63 * V_64 , T_3 V_130 , struct V_45 * V_46 ,
struct V_38 * V_129 )
{
if ( V_130 > 0 ) {
if ( V_46 -> V_110 ) {
T_3 V_42 =
* ( ( T_3 * ) F_49 ( V_46 ) ) ;
F_11 ( V_64 -> V_13 , V_131 ,
V_132 ,
V_130 + sizeof( struct V_38 ) , V_129 ,
V_42 ) ;
} else {
F_10 ( V_64 -> V_13 , V_131 ,
V_132 ,
V_130 + sizeof( struct V_38 ) ,
V_129 ) ;
}
} else {
F_10 ( V_64 -> V_13 , V_131 , V_132 ,
V_130 + sizeof( struct V_38 ) , V_129 ) ;
}
}
static void
F_47 ( struct V_63 * V_64 , struct V_45 * V_46 ,
struct V_126 * V_127 )
{
if ( V_127 -> V_121 > 0 ) {
if ( V_46 -> V_112 ) {
T_3 V_42 =
* ( ( T_3 * ) F_50 ( V_46 ) ) ;
F_11 ( V_64 -> V_13 , V_131 ,
V_133 ,
( T_2 ) V_127 -> V_121 ,
& V_127 -> V_129 , V_42 ) ;
} else {
F_10 ( V_64 -> V_13 , V_131 ,
V_133 ,
( T_2 ) V_127 -> V_121 ,
& V_127 -> V_129 ) ;
}
} else {
F_10 ( V_64 -> V_13 , V_131 , V_133 ,
( T_2 ) V_127 -> V_121 , & V_127 -> V_129 ) ;
}
}
static void
V_56 ( void * V_119 )
{
struct V_45 * V_46 = V_119 ;
struct V_63 * V_64 = V_46 -> V_52 -> V_64 ;
struct V_134 * V_135 ;
V_46 -> V_57 = V_58 ;
V_135 = F_51 ( V_64 , V_136 ) ;
F_52 ( V_46 , V_135 ) ;
}
static void
F_52 ( struct V_45 * V_46 , struct V_134 * V_135 )
{
struct V_63 * V_64 = V_46 -> V_52 -> V_64 ;
struct V_137 * V_138 = & V_46 -> V_139 ;
struct V_140 * V_141 = & V_46 -> V_142 ;
struct V_143 * V_144 = V_138 -> V_145 ;
F_53 ( V_135 -> V_146 , V_147 , V_148 ,
F_54 ( V_64 ) ) ;
V_135 -> V_53 = F_55 ( V_46 -> V_53 ) ;
if ( V_144 ) {
V_135 -> V_149 = V_144 -> V_150 ;
V_135 -> V_151 = F_55 ( V_144 -> V_152 . V_151 ) ;
if ( V_135 -> V_151 == 0 )
V_135 -> V_151 = F_55 ( V_153 ) ;
} else {
V_135 -> V_149 = 0 ;
V_135 -> V_151 = F_55 ( V_153 ) ;
}
V_135 -> V_154 = F_55 ( V_138 -> V_154 ) ;
V_135 -> V_155 = F_56 ( V_64 , V_138 -> V_156 ) ;
V_135 -> V_157 = V_138 -> V_157 ;
V_135 -> V_158 = V_141 -> V_158 ;
V_135 -> V_159 = V_138 -> V_159 ;
V_135 -> V_129 = V_138 -> V_129 ;
V_135 -> V_160 = F_57 ( V_138 -> V_161 ) ;
V_135 -> V_162 = F_57 ( V_141 -> V_162 ) ;
if ( V_46 -> V_110 == 1 ) {
F_58 ( & V_135 -> V_163 , V_138 -> V_161 ,
F_59 ( V_46 ) ) ;
} else {
if ( V_46 -> V_104 > 0 ) {
F_5 ( V_46 -> V_104 != 1 ) ;
F_58 ( & V_135 -> V_163 , V_138 -> V_161 ,
V_46 -> V_106 ( V_46 -> V_87 , 0 ) ) ;
} else {
F_5 ( V_138 -> V_161 != 0 ) ;
F_58 ( & V_135 -> V_164 , 0 , 0 ) ;
}
}
if ( V_46 -> V_112 == 1 ) {
F_5 ( V_141 -> V_162 > V_78 ) ;
F_58 ( & V_135 -> V_164 , V_141 -> V_162 ,
F_60 ( V_46 ) ) ;
} else {
if ( V_46 -> V_105 > 0 ) {
F_5 ( V_46 -> V_105 != 1 ) ;
F_58 ( & V_135 -> V_164 , V_141 -> V_162 ,
V_46 -> V_108 ( V_46 -> V_87 , 0 ) ) ;
} else {
F_5 ( V_141 -> V_162 != 0 ) ;
F_58 ( & V_135 -> V_164 , 0 , 0 ) ;
}
}
F_48 ( V_64 , V_138 -> V_161 , V_46 , & V_138 -> V_129 ) ;
F_61 ( V_64 , V_136 , V_135 -> V_146 ) ;
F_37 ( V_64 , F_62 ( V_64 , V_136 ) ) ;
F_37 ( V_64 , F_63 ( V_64 , V_136 ) ) ;
}
struct V_45 *
F_64 ( void * V_87 , struct V_63 * V_64 , int V_104 ,
int V_105 , T_4 V_106 ,
T_5 V_107 ,
T_4 V_108 ,
T_5 V_109 )
{
struct V_45 * V_46 = NULL ;
F_5 ( V_64 == NULL ) ;
V_46 = F_34 ( F_18 ( V_64 ) ) ;
if ( V_46 == NULL )
return NULL ;
F_37 ( V_64 , V_46 -> V_53 ) ;
F_38 ( V_46 , V_87 , V_64 , V_104 , V_105 , V_106 ,
V_107 , V_108 , V_109 ) ;
return V_46 ;
}
void *
F_65 ( struct V_45 * V_46 )
{
struct V_43 * V_44 = V_46 -> V_52 ;
void * V_165 ;
F_5 ( V_46 -> V_110 != 1 ) ;
V_165 = F_66 ( V_44 , V_46 -> V_53 ,
V_44 -> V_82 + V_44 -> V_83 ) ;
return V_165 ;
}
T_3
F_67 ( struct V_45 * V_46 )
{
struct V_43 * V_44 = V_46 -> V_52 ;
return V_44 -> V_82 ;
}
void *
F_68 ( struct V_45 * V_46 )
{
struct V_43 * V_44 = V_46 -> V_52 ;
void * V_166 ;
F_5 ( V_46 -> V_112 != 1 ) ;
V_166 = F_66 ( V_44 , V_46 -> V_53 ,
V_44 -> V_82 + V_44 -> V_83 ) ;
return ( ( V_37 * ) V_166 ) + V_44 -> V_82 ;
}
void
F_32 ( struct V_45 * V_46 )
{
struct V_43 * V_44 = V_46 -> V_52 ;
F_5 ( V_46 == NULL ) ;
F_37 ( V_44 -> V_64 , V_46 -> V_53 ) ;
F_39 ( V_46 ) ;
}
void
F_69 ( struct V_45 * V_46 , struct V_143 * V_144 ,
T_2 V_154 , V_37 V_156 , T_7 V_159 , enum V_167 cos ,
T_3 V_130 , struct V_38 * V_129 , T_8 V_168 ,
void * V_119 , T_3 V_162 , V_37 V_158 )
{
struct V_63 * V_64 = V_46 -> V_52 -> V_64 ;
struct V_137 * V_138 = & V_46 -> V_139 ;
struct V_140 * V_141 = & V_46 -> V_142 ;
struct V_134 * V_135 ;
F_37 ( V_64 , V_46 -> V_53 ) ;
V_138 -> V_145 = V_144 ;
V_138 -> V_154 = V_154 ;
V_138 -> V_156 = V_156 ;
V_138 -> V_157 = cos ;
V_141 -> V_158 = V_158 ;
V_138 -> V_159 = V_159 ;
V_138 -> V_129 = * V_129 ;
V_138 -> V_161 = V_130 ;
V_141 -> V_162 = V_162 ;
V_46 -> V_88 = V_168 ? V_168 : F_42 ;
V_46 -> V_89 = V_119 ;
V_135 = F_51 ( V_64 , V_136 ) ;
if ( ! V_135 ) {
F_37 ( V_64 , V_46 -> V_53 ) ;
V_46 -> V_57 = V_169 ;
F_70 ( V_64 , V_136 , & V_46 -> V_55 ) ;
return;
}
F_52 ( V_46 , V_135 ) ;
}
T_6
F_71 ( struct V_45 * V_46 )
{
F_37 ( V_46 -> V_52 -> V_64 , V_46 -> V_53 ) ;
F_5 ( 1 ) ;
return V_128 ;
}
void
F_72 ( struct V_63 * V_64 , struct V_114 * V_115 ,
T_9 V_116 , void * V_117 ,
void * V_87 , int V_104 ,
int V_105 , T_4 V_106 ,
T_5 V_107 ,
T_4 V_108 ,
T_5 V_109 )
{
struct V_43 * V_44 = F_18 ( V_64 ) ;
F_5 ( ! F_73 ( & V_44 -> V_48 ) ) ;
V_115 -> V_116 = V_116 ;
V_115 -> V_117 = V_117 ;
V_115 -> V_87 = V_87 ;
V_115 -> V_64 = V_64 ;
V_115 -> V_104 = V_104 ;
V_115 -> V_105 = V_105 ;
V_115 -> V_106 = V_106 ;
V_115 -> V_107 = V_107 ;
V_115 -> V_108 = V_108 ;
V_115 -> V_109 = V_109 ;
F_15 ( & V_115 -> V_54 , & V_44 -> V_84 ) ;
}
void
F_74 ( struct V_63 * V_64 , struct V_114 * V_115 )
{
struct V_43 * V_44 = F_18 ( V_64 ) ;
F_5 ( ! F_40 ( & V_44 -> V_84 , V_115 ) ) ;
F_41 ( & V_115 -> V_54 ) ;
}
void
F_75 ( struct V_45 * V_46 )
{
if ( V_46 -> V_57 ) {
V_46 -> V_57 = V_58 ;
F_76 ( & V_46 -> V_55 ) ;
F_32 ( V_46 ) ;
return;
}
V_46 -> V_88 = F_42 ;
}
void
F_77 ( struct V_63 * V_64 , struct V_170 * V_171 )
{
switch ( V_171 -> V_172 . V_173 ) {
case V_174 :
F_43 ( V_64 , (struct V_126 * ) V_171 ) ;
break;
default:
F_37 ( V_64 , V_171 -> V_172 . V_173 ) ;
F_5 ( 1 ) ;
}
}
T_3
F_78 ( struct V_63 * V_64 )
{
struct V_43 * V_44 = F_18 ( V_64 ) ;
return V_44 -> V_83 ;
}
void
F_79 ( struct V_63 * V_64 , T_2 V_175 )
{
struct V_43 * V_44 = F_18 ( V_64 ) ;
struct V_85 * V_54 ;
int V_35 ;
for ( V_35 = 0 ; V_35 < ( V_44 -> V_47 - V_175 ) ; V_35 ++ ) {
F_80 ( & V_44 -> V_48 , & V_54 ) ;
F_15 ( V_54 , & V_44 -> V_50 ) ;
}
}
static void
F_81 ( struct V_176 * V_177 , enum V_178 V_25 )
{
F_37 ( V_177 -> V_64 , V_177 -> V_179 ) ;
F_37 ( V_177 -> V_64 , V_25 ) ;
switch ( V_25 ) {
case V_180 :
if ( F_82 ( V_177 -> V_64 , V_177 -> V_181 ) ) {
F_83 ( V_177 , V_182 ) ;
F_70 ( V_177 -> V_64 , V_177 -> V_181 , & V_177 -> V_115 ) ;
} else {
F_83 ( V_177 , V_183 ) ;
F_84 ( V_177 ) ;
}
if ( V_177 -> V_184 )
F_8 ( V_177 -> V_64 -> V_13 , V_185 ,
V_186 , 0 , L_1 ) ;
else
F_8 ( V_177 -> V_64 -> V_13 , V_185 ,
V_186 , 0 , L_2 ) ;
break;
case V_187 :
F_85 ( V_177 ) ;
break;
case V_188 :
F_86 ( V_177 ) ;
break;
case V_189 :
case V_190 :
break;
case V_191 :
break;
default:
F_87 ( V_177 -> V_64 , V_25 ) ;
}
}
static void
V_183 ( struct V_176 * V_177 , enum V_178 V_25 )
{
F_37 ( V_177 -> V_64 , V_177 -> V_179 ) ;
F_37 ( V_177 -> V_64 , V_25 ) ;
switch ( V_25 ) {
case V_191 :
if ( V_177 -> V_192 == V_128 ) {
F_83 ( V_177 , V_193 ) ;
if ( V_177 -> V_184 )
F_8 ( V_177 -> V_64 -> V_13 , V_185 ,
V_186 , 0 , L_3 ) ;
else
F_8 ( V_177 -> V_64 -> V_13 , V_185 ,
V_186 , 0 , L_4 ) ;
F_37 ( V_177 -> V_64 , V_177 -> V_194 ) ;
F_37 ( V_177 -> V_64 , V_177 -> V_195 ) ;
if ( ! V_177 -> V_194 && V_177 -> V_195 )
F_88 ( V_177 , V_196 ) ;
} else {
F_83 ( V_177 , F_81 ) ;
if ( V_177 -> V_184 )
F_8 ( V_177 -> V_64 -> V_13 , V_185 ,
V_186 , 0 ,
L_5 ) ;
else
F_8 ( V_177 -> V_64 -> V_13 , V_185 ,
V_186 , 0 ,
L_6 ) ;
}
F_89 ( V_177 ) ;
break;
case V_190 :
case V_188 :
F_83 ( V_177 , F_81 ) ;
break;
case V_196 :
F_37 ( V_177 -> V_64 , V_177 -> V_194 ) ;
F_37 ( V_177 -> V_64 , V_177 -> V_195 ) ;
break;
default:
F_87 ( V_177 -> V_64 , V_25 ) ;
}
}
static void
V_182 ( struct V_176 * V_177 , enum V_178 V_25 )
{
F_37 ( V_177 -> V_64 , V_177 -> V_179 ) ;
F_37 ( V_177 -> V_64 , V_25 ) ;
switch ( V_25 ) {
case V_197 :
F_83 ( V_177 , V_183 ) ;
break;
case V_190 :
case V_188 :
F_83 ( V_177 , F_81 ) ;
F_76 ( & V_177 -> V_115 ) ;
break;
case V_189 :
break;
default:
F_87 ( V_177 -> V_64 , V_25 ) ;
}
}
static void
V_193 ( struct V_176 * V_177 , enum V_178 V_25 )
{
F_37 ( V_177 -> V_64 , V_177 -> V_179 ) ;
F_37 ( V_177 -> V_64 , V_25 ) ;
switch ( V_25 ) {
case V_187 :
if ( F_82 ( V_177 -> V_64 , V_177 -> V_181 ) ) {
F_83 ( V_177 , V_198 ) ;
F_70 ( V_177 -> V_64 , V_177 -> V_181 , & V_177 -> V_115 ) ;
} else {
F_83 ( V_177 , V_199 ) ;
F_90 ( V_177 ) ;
}
F_8 ( V_177 -> V_64 -> V_13 , V_185 ,
V_200 , 0 , L_7 ) ;
break;
case V_189 :
F_83 ( V_177 , F_81 ) ;
F_91 ( V_177 ) ;
F_8 ( V_177 -> V_64 -> V_13 , V_185 ,
V_201 , 0 , L_8 ) ;
break;
case V_196 :
if ( F_82 ( V_177 -> V_64 , V_177 -> V_181 ) ) {
F_83 ( V_177 , V_202 ) ;
F_70 ( V_177 -> V_64 , V_177 -> V_181 , & V_177 -> V_115 ) ;
} else
F_92 ( V_177 ) ;
break;
case V_190 :
case V_188 :
F_83 ( V_177 , F_81 ) ;
break;
default:
F_87 ( V_177 -> V_64 , V_25 ) ;
}
}
static void
V_202 ( struct V_176 * V_177 , enum V_178 V_25 )
{
F_37 ( V_177 -> V_64 , V_177 -> V_179 ) ;
F_37 ( V_177 -> V_64 , V_25 ) ;
switch ( V_25 ) {
case V_197 :
F_83 ( V_177 , V_193 ) ;
F_92 ( V_177 ) ;
break;
case V_187 :
F_83 ( V_177 , V_198 ) ;
F_8 ( V_177 -> V_64 -> V_13 , V_185 ,
V_200 , 0 , L_7 ) ;
break;
case V_189 :
F_83 ( V_177 , F_81 ) ;
F_76 ( & V_177 -> V_115 ) ;
F_91 ( V_177 ) ;
F_8 ( V_177 -> V_64 -> V_13 , V_185 ,
V_201 , 0 , L_8 ) ;
break;
case V_190 :
case V_188 :
F_83 ( V_177 , F_81 ) ;
F_76 ( & V_177 -> V_115 ) ;
break;
default:
F_87 ( V_177 -> V_64 , V_25 ) ;
}
}
static void
V_199 ( struct V_176 * V_177 , enum V_178 V_25 )
{
F_37 ( V_177 -> V_64 , V_177 -> V_179 ) ;
F_37 ( V_177 -> V_64 , V_25 ) ;
switch ( V_25 ) {
case V_191 :
F_83 ( V_177 , F_81 ) ;
F_85 ( V_177 ) ;
break;
case V_190 :
case V_188 :
F_83 ( V_177 , F_81 ) ;
break;
default:
F_87 ( V_177 -> V_64 , V_25 ) ;
}
}
static void
V_198 ( struct V_176 * V_177 , enum V_178 V_25 )
{
F_37 ( V_177 -> V_64 , V_177 -> V_179 ) ;
F_37 ( V_177 -> V_64 , V_25 ) ;
switch ( V_25 ) {
case V_197 :
F_83 ( V_177 , V_199 ) ;
F_90 ( V_177 ) ;
break;
case V_190 :
case V_188 :
F_83 ( V_177 , F_81 ) ;
F_76 ( & V_177 -> V_115 ) ;
break;
default:
F_87 ( V_177 -> V_64 , V_25 ) ;
}
}
static void
F_93 ( struct V_59 * V_60 , struct V_61 * V_62 ,
struct V_63 * V_64 )
{
struct V_65 * V_203 = F_94 ( V_64 ) ;
if ( V_60 -> V_75 . V_76 )
F_24 ( V_62 , V_203 ,
sizeof( struct V_176 ) * V_204 ) ;
else
F_24 ( V_62 , V_203 ,
sizeof( struct V_176 ) * V_205 ) ;
}
static void
F_95 ( struct V_63 * V_64 , void * V_79 , struct V_59 * V_60 ,
struct V_80 * V_81 )
{
struct V_206 * V_44 = F_96 ( V_64 ) ;
struct V_176 * V_177 ;
int V_35 ;
V_44 -> V_207 = V_205 ;
if ( V_60 -> V_75 . V_76 )
V_44 -> V_207 = V_204 ;
else
V_44 -> V_207 = V_205 ;
V_44 -> V_208 = V_177 = (struct V_176 * ) F_13 ( V_44 ) ;
F_13 ( V_44 ) += V_44 -> V_207 * sizeof( struct V_176 ) ;
F_14 ( & V_44 -> V_209 ) ;
F_14 ( & V_44 -> V_210 ) ;
F_14 ( & V_44 -> V_211 ) ;
for ( V_35 = 0 ; V_35 < V_44 -> V_207 ; V_35 ++ , V_177 ++ ) {
V_177 -> V_64 = V_64 ;
V_177 -> V_179 = ( V_37 ) V_35 ;
V_177 -> V_181 = V_212 ;
F_16 ( & V_177 -> V_115 , V_213 , V_177 ) ;
F_15 ( & V_177 -> V_54 , & V_44 -> V_209 ) ;
}
}
static void
F_97 ( struct V_63 * V_64 )
{
}
static void
F_98 ( struct V_63 * V_64 )
{
}
static void
F_99 ( struct V_63 * V_64 )
{
}
static void
F_100 ( struct V_63 * V_64 )
{
struct V_206 * V_44 = F_96 ( V_64 ) ;
struct V_176 * V_177 ;
struct V_85 * V_54 , * V_86 ;
F_31 (qe, qen, &mod->lps_active_q) {
V_177 = (struct V_176 * ) V_54 ;
F_88 ( V_177 , V_190 ) ;
}
F_31 (qe, qen, &mod->lps_login_q) {
V_177 = (struct V_176 * ) V_54 ;
F_88 ( V_177 , V_190 ) ;
}
F_30 ( & V_44 -> V_211 , & V_44 -> V_210 ) ;
}
static void
F_101 ( struct V_63 * V_64 , struct V_214 * V_215 )
{
struct V_206 * V_44 = F_96 ( V_64 ) ;
struct V_176 * V_177 ;
F_5 ( V_215 -> V_179 >= V_44 -> V_207 ) ;
V_177 = F_102 ( V_44 , V_215 -> V_179 ) ;
V_177 -> V_192 = V_215 -> V_192 ;
switch ( V_215 -> V_192 ) {
case V_128 :
V_177 -> V_216 = V_215 -> V_216 ;
V_177 -> V_194 = V_215 -> V_217 ;
if ( V_177 -> V_194 )
V_177 -> V_195 = V_215 -> V_195 ;
V_177 -> V_218 = V_215 -> V_218 ;
V_177 -> V_219 = F_44 ( V_215 -> V_220 ) ;
V_177 -> V_221 = V_215 -> V_222 ;
V_177 -> V_223 = V_215 -> V_224 ;
V_177 -> V_225 = V_215 -> V_225 ;
V_177 -> V_226 = V_215 -> V_226 ;
V_177 -> V_227 = V_215 -> V_227 ;
V_177 -> V_228 = V_215 -> V_228 ;
V_177 -> V_229 = V_215 -> V_230 ;
break;
case V_231 :
V_177 -> V_232 = V_215 -> V_232 ;
V_177 -> V_233 = V_215 -> V_233 ;
break;
case V_234 :
V_177 -> V_235 = V_215 -> V_235 ;
break;
case V_236 :
if ( ! V_215 -> V_235 )
F_103 ( V_177 , V_215 -> V_235 ) ;
break;
default:
break;
}
F_41 ( & V_177 -> V_54 ) ;
F_15 ( & V_177 -> V_54 , & V_44 -> V_210 ) ;
F_88 ( V_177 , V_191 ) ;
}
static void
F_103 ( struct V_176 * V_237 , V_37 V_238 )
{
struct V_63 * V_64 = V_237 -> V_64 ;
struct V_206 * V_44 = F_96 ( V_64 ) ;
struct V_85 * V_54 , * V_239 ;
struct V_176 * V_177 ;
F_37 ( V_64 , V_238 ) ;
V_54 = F_104 ( V_237 ) ;
while ( V_238 && V_54 ) {
V_239 = F_104 ( V_54 ) ;
V_177 = (struct V_176 * ) V_54 ;
F_37 ( V_64 , V_177 -> V_179 ) ;
V_177 -> V_192 = V_237 -> V_192 ;
F_41 ( & V_177 -> V_54 ) ;
F_15 ( & V_177 -> V_54 , & V_44 -> V_210 ) ;
F_88 ( V_177 , V_191 ) ;
V_54 = V_239 ;
V_238 -- ;
}
}
static void
F_105 ( struct V_63 * V_64 , struct V_240 * V_215 )
{
struct V_206 * V_44 = F_96 ( V_64 ) ;
struct V_176 * V_177 ;
F_5 ( V_215 -> V_179 >= V_44 -> V_207 ) ;
V_177 = F_102 ( V_44 , V_215 -> V_179 ) ;
F_88 ( V_177 , V_191 ) ;
}
static void
F_106 ( struct V_63 * V_64 , struct V_241 * V_242 )
{
struct V_206 * V_44 = F_96 ( V_64 ) ;
struct V_176 * V_177 ;
V_177 = F_102 ( V_44 , V_242 -> V_179 ) ;
F_88 ( V_177 , V_189 ) ;
}
static void
V_213 ( void * V_243 )
{
struct V_176 * V_177 = V_243 ;
F_88 ( V_177 , V_197 ) ;
}
static void
F_86 ( struct V_176 * V_177 )
{
struct V_206 * V_44 = F_96 ( V_177 -> V_64 ) ;
V_177 -> V_195 = 0 ;
F_41 ( & V_177 -> V_54 ) ;
F_15 ( & V_177 -> V_54 , & V_44 -> V_209 ) ;
}
static void
F_84 ( struct V_176 * V_177 )
{
struct V_206 * V_44 = F_96 ( V_177 -> V_64 ) ;
struct V_244 * V_245 ;
V_245 = F_51 ( V_177 -> V_64 , V_177 -> V_181 ) ;
F_5 ( ! V_245 ) ;
F_53 ( V_245 -> V_146 , V_246 , V_247 ,
F_54 ( V_177 -> V_64 ) ) ;
V_245 -> V_179 = V_177 -> V_179 ;
V_245 -> V_248 = V_177 -> V_248 ;
V_245 -> V_249 = F_55 ( V_177 -> V_250 ) ;
V_245 -> V_251 = V_177 -> V_251 ;
V_245 -> V_252 = V_177 -> V_252 ;
V_245 -> V_184 = V_177 -> V_184 ;
V_245 -> V_253 = V_177 -> V_253 ;
V_245 -> V_230 = V_177 -> V_230 ;
F_61 ( V_177 -> V_64 , V_177 -> V_181 , V_245 -> V_146 ) ;
F_41 ( & V_177 -> V_54 ) ;
F_15 ( & V_177 -> V_54 , & V_44 -> V_211 ) ;
}
static void
F_90 ( struct V_176 * V_177 )
{
struct V_254 * V_245 ;
V_245 = F_51 ( V_177 -> V_64 , V_177 -> V_181 ) ;
F_5 ( ! V_245 ) ;
F_53 ( V_245 -> V_146 , V_246 , V_255 ,
F_54 ( V_177 -> V_64 ) ) ;
V_245 -> V_216 = V_177 -> V_216 ;
V_245 -> V_222 = V_177 -> V_251 ;
F_61 ( V_177 -> V_64 , V_177 -> V_181 , V_245 -> V_146 ) ;
}
static void
F_92 ( struct V_176 * V_177 )
{
struct V_256 * V_245 ;
V_245 = F_51 ( V_177 -> V_64 , V_177 -> V_181 ) ;
F_5 ( ! V_245 ) ;
F_53 ( V_245 -> V_146 , V_246 , V_257 ,
F_54 ( V_177 -> V_64 ) ) ;
V_245 -> V_216 = V_177 -> V_216 ;
V_245 -> V_195 = V_177 -> V_195 ;
F_61 ( V_177 -> V_64 , V_177 -> V_181 , V_245 -> V_146 ) ;
}
static void
F_107 ( void * V_258 , T_7 V_124 )
{
struct V_176 * V_177 = V_258 ;
if ( ! V_124 )
return;
if ( V_177 -> V_184 )
F_108 ( V_177 -> V_64 -> V_79 , V_177 -> V_259 , V_177 -> V_192 ) ;
else
F_109 ( V_177 -> V_64 -> V_79 , V_177 -> V_259 , V_177 -> V_192 ) ;
}
static void
F_89 ( struct V_176 * V_177 )
{
if ( ! V_177 -> V_64 -> V_260 ) {
F_33 ( V_177 -> V_64 , & V_177 -> V_92 , F_107 ,
V_177 ) ;
return;
}
if ( V_177 -> V_184 )
F_108 ( V_177 -> V_64 -> V_79 , V_177 -> V_259 , V_177 -> V_192 ) ;
else
F_109 ( V_177 -> V_64 -> V_79 , V_177 -> V_259 , V_177 -> V_192 ) ;
}
static void
F_110 ( void * V_258 , T_7 V_124 )
{
struct V_176 * V_177 = V_258 ;
if ( ! V_124 )
return;
if ( V_177 -> V_184 )
F_111 ( V_177 -> V_64 -> V_79 , V_177 -> V_259 ) ;
}
static void
F_85 ( struct V_176 * V_177 )
{
if ( ! V_177 -> V_64 -> V_260 ) {
F_33 ( V_177 -> V_64 , & V_177 -> V_92 , F_110 ,
V_177 ) ;
return;
}
if ( V_177 -> V_184 )
F_111 ( V_177 -> V_64 -> V_79 , V_177 -> V_259 ) ;
}
static void
F_112 ( void * V_258 , T_7 V_124 )
{
struct V_176 * V_177 = V_258 ;
if ( ! V_124 )
return;
if ( V_177 -> V_184 )
F_113 ( V_177 -> V_64 -> V_79 , V_177 -> V_259 ) ;
}
static void
F_91 ( struct V_176 * V_177 )
{
if ( ! V_177 -> V_64 -> V_260 ) {
F_33 ( V_177 -> V_64 , & V_177 -> V_92 , F_112 ,
V_177 ) ;
return;
}
if ( V_177 -> V_184 )
F_113 ( V_177 -> V_64 -> V_79 , V_177 -> V_259 ) ;
}
T_3
F_114 ( struct V_63 * V_64 )
{
if ( F_115 ( & V_64 -> V_261 ) == V_262 )
return V_263 ;
else
return V_264 ;
}
struct V_176 *
F_116 ( struct V_63 * V_64 )
{
struct V_206 * V_44 = F_96 ( V_64 ) ;
struct V_176 * V_177 = NULL ;
F_35 ( & V_44 -> V_209 , & V_177 ) ;
if ( V_177 == NULL )
return NULL ;
F_15 ( & V_177 -> V_54 , & V_44 -> V_210 ) ;
F_83 ( V_177 , F_81 ) ;
return V_177 ;
}
void
F_117 ( struct V_176 * V_177 )
{
F_88 ( V_177 , V_188 ) ;
}
void
F_118 ( struct V_176 * V_177 , void * V_259 , V_37 V_248 , T_2 V_250 ,
T_10 V_251 , T_10 V_252 , T_7 V_253 , T_11 V_230 )
{
V_177 -> V_259 = V_259 ;
V_177 -> V_248 = V_248 ;
V_177 -> V_250 = V_250 ;
V_177 -> V_251 = V_251 ;
V_177 -> V_252 = V_252 ;
V_177 -> V_184 = V_58 ;
V_177 -> V_253 = V_253 ;
V_177 -> V_230 = V_230 ;
F_88 ( V_177 , V_180 ) ;
}
void
F_119 ( struct V_176 * V_177 , void * V_259 , T_2 V_250 , T_10 V_251 ,
T_10 V_252 )
{
V_177 -> V_259 = V_259 ;
V_177 -> V_248 = 0 ;
V_177 -> V_250 = V_250 ;
V_177 -> V_251 = V_251 ;
V_177 -> V_252 = V_252 ;
V_177 -> V_184 = V_169 ;
V_177 -> V_253 = V_58 ;
F_88 ( V_177 , V_180 ) ;
}
void
F_120 ( struct V_176 * V_177 )
{
F_88 ( V_177 , V_187 ) ;
}
V_37
F_56 ( struct V_63 * V_64 , V_37 V_156 )
{
struct V_206 * V_44 = F_96 ( V_64 ) ;
return F_102 ( V_44 , V_156 ) -> V_216 ;
}
V_37
F_121 ( struct V_63 * V_64 , T_3 V_265 )
{
struct V_206 * V_44 = F_96 ( V_64 ) ;
struct V_176 * V_177 ;
int V_35 ;
for ( V_35 = 0 , V_177 = V_44 -> V_208 ; V_35 < V_44 -> V_207 ; V_35 ++ , V_177 ++ ) {
if ( V_177 -> V_195 == V_265 )
return V_177 -> V_179 ;
}
return 0 ;
}
T_3
F_122 ( struct V_63 * V_64 )
{
struct V_206 * V_44 = F_96 ( V_64 ) ;
return F_102 ( V_44 , 0 ) -> V_195 ;
}
void
F_123 ( struct V_176 * V_177 , T_12 V_266 )
{
F_37 ( V_177 -> V_64 , V_177 -> V_179 ) ;
F_37 ( V_177 -> V_64 , V_266 ) ;
V_177 -> V_195 = V_266 ;
F_88 ( V_177 , V_196 ) ;
}
void
F_124 ( struct V_63 * V_64 , struct V_170 * V_245 )
{
union V_267 V_171 ;
F_37 ( V_64 , V_245 -> V_172 . V_173 ) ;
V_171 . V_171 = V_245 ;
switch ( V_245 -> V_172 . V_173 ) {
case V_268 :
F_101 ( V_64 , V_171 . V_269 ) ;
break;
case V_270 :
F_105 ( V_64 , V_171 . V_271 ) ;
break;
case V_272 :
F_106 ( V_64 , V_171 . V_273 ) ;
break;
default:
F_37 ( V_64 , V_245 -> V_172 . V_173 ) ;
F_5 ( 1 ) ;
}
}
static void
F_125 ( struct V_274 * V_275 , enum V_276 V_25 )
{
struct V_277 * V_79 = (struct V_277 * ) V_275 -> V_64 -> V_79 ;
struct V_278 * V_279 ;
F_126 ( V_79 , V_279 ) ;
if ( ! V_279 )
return;
V_279 -> V_280 . V_281 . V_282 = F_127 ( V_275 -> V_64 ) ;
V_279 -> V_280 . V_281 . V_251 = V_275 -> V_251 ;
F_128 ( V_279 , V_79 , ++ V_275 -> V_64 -> V_283 ,
V_284 , V_25 ) ;
}
static void
F_129 ( struct V_274 * V_275 ,
enum V_285 V_25 )
{
F_37 ( V_275 -> V_64 , V_25 ) ;
switch ( V_25 ) {
case V_286 :
V_275 -> V_287 = V_169 ;
if ( F_130 ( V_275 ) ) {
F_37 ( V_275 -> V_64 , V_169 ) ;
F_83 ( V_275 , V_288 ) ;
} else {
F_37 ( V_275 -> V_64 , V_58 ) ;
F_83 ( V_275 ,
V_289 ) ;
}
break;
case V_290 :
break;
case V_291 :
F_83 ( V_275 , V_292 ) ;
break;
case V_293 :
F_83 ( V_275 , V_294 ) ;
break;
default:
F_87 ( V_275 -> V_64 , V_25 ) ;
}
}
static void
V_289 ( struct V_274 * V_275 ,
enum V_285 V_25 )
{
char V_295 [ V_296 ] ;
struct V_277 * V_79 = (struct V_277 * ) V_275 -> V_64 -> V_79 ;
F_37 ( V_275 -> V_64 , V_25 ) ;
switch ( V_25 ) {
case V_297 :
F_83 ( V_275 , V_288 ) ;
F_130 ( V_275 ) ;
break;
case V_298 :
F_76 ( & V_275 -> V_299 ) ;
F_83 ( V_275 , V_300 ) ;
break;
case V_290 :
break;
case V_291 :
F_83 ( V_275 , V_292 ) ;
F_76 ( & V_275 -> V_299 ) ;
F_8 ( V_275 -> V_64 -> V_13 , V_301 ,
V_302 , 0 , L_9 ) ;
F_131 ( V_295 , V_275 -> V_251 ) ;
F_132 ( V_303 , V_79 , V_304 ,
L_10 , V_295 ) ;
F_125 ( V_275 , V_305 ) ;
break;
case V_306 :
case V_307 :
break;
case V_293 :
F_76 ( & V_275 -> V_299 ) ;
F_83 ( V_275 , V_294 ) ;
break;
default:
F_87 ( V_275 -> V_64 , V_25 ) ;
}
}
static void
V_288 ( struct V_274 * V_275 ,
enum V_285 V_25 )
{
char V_295 [ V_296 ] ;
struct V_277 * V_79 = (struct V_277 * ) V_275 -> V_64 -> V_79 ;
F_37 ( V_275 -> V_64 , V_25 ) ;
switch ( V_25 ) {
case V_308 :
case V_307 :
F_83 ( V_275 , V_309 ) ;
break;
case V_306 :
F_133 ( V_275 ) ;
F_83 ( V_275 , V_310 ) ;
F_5 ( ! V_275 -> V_311 ) ;
F_134 ( V_275 , V_312 , V_58 ) ;
break;
case V_290 :
break;
case V_291 :
if ( F_135 ( V_275 ) )
F_83 ( V_275 , V_313 ) ;
else
F_83 ( V_275 ,
V_314 ) ;
F_8 ( V_275 -> V_64 -> V_13 , V_301 ,
V_302 , 0 , L_9 ) ;
F_131 ( V_295 , V_275 -> V_251 ) ;
F_132 ( V_303 , V_79 , V_304 ,
L_10 , V_295 ) ;
F_125 ( V_275 , V_305 ) ;
break;
case V_298 :
F_83 ( V_275 , V_300 ) ;
break;
case V_293 :
F_83 ( V_275 , V_294 ) ;
break;
default:
F_87 ( V_275 -> V_64 , V_25 ) ;
}
}
static void
V_309 ( struct V_274 * V_275 ,
enum V_285 V_25 )
{
struct V_315 * V_316 = V_275 -> V_317 . V_318 . V_25 ;
char V_295 [ V_296 ] ;
struct V_277 * V_79 = (struct V_277 * ) V_275 -> V_64 -> V_79 ;
F_37 ( V_275 -> V_64 , V_25 ) ;
switch ( V_25 ) {
case V_306 :
F_133 ( V_275 ) ;
F_83 ( V_275 , V_310 ) ;
F_5 ( ! V_275 -> V_311 ) ;
F_8 ( V_275 -> V_64 -> V_13 , V_301 ,
V_319 , 0 , L_11 ) ;
if ( ! F_136 ( & V_275 -> V_64 -> V_261 ) ) {
F_37 ( V_275 -> V_64 ,
V_316 -> V_320 . V_321 . V_322 . V_323 ) ;
F_37 ( V_275 -> V_64 ,
V_316 -> V_320 . V_321 . V_322 . V_324 ) ;
if ( V_316 -> V_320 . V_321 . V_322 . V_324 )
F_8 ( V_275 -> V_64 -> V_13 , V_301 ,
V_325 , 0 ,
L_12 ) ;
else
F_8 ( V_275 -> V_64 -> V_13 , V_301 ,
V_325 , 0 ,
L_13 ) ;
}
F_134 ( V_275 , V_312 , V_58 ) ;
F_131 ( V_295 , V_275 -> V_251 ) ;
F_132 ( V_303 , V_79 , V_304 ,
L_14 , V_295 ) ;
F_125 ( V_275 , V_326 ) ;
if ( V_275 -> V_60 . V_327 &&
V_275 -> V_328 . V_329 != V_330 )
F_125 ( V_275 , V_331 ) ;
break;
case V_307 :
break;
case V_290 :
break;
case V_291 :
if ( F_135 ( V_275 ) )
F_83 ( V_275 , V_313 ) ;
else
F_83 ( V_275 ,
V_314 ) ;
F_8 ( V_275 -> V_64 -> V_13 , V_301 ,
V_302 , 0 , L_9 ) ;
F_131 ( V_295 , V_275 -> V_251 ) ;
F_132 ( V_303 , V_79 , V_304 ,
L_10 , V_295 ) ;
F_125 ( V_275 , V_305 ) ;
break;
case V_298 :
F_83 ( V_275 , V_300 ) ;
break;
case V_293 :
F_83 ( V_275 , V_294 ) ;
break;
default:
F_87 ( V_275 -> V_64 , V_25 ) ;
}
}
static void
V_310 ( struct V_274 * V_275 ,
enum V_285 V_25 )
{
char V_295 [ V_296 ] ;
struct V_277 * V_79 = (struct V_277 * ) V_275 -> V_64 -> V_79 ;
F_37 ( V_275 -> V_64 , V_25 ) ;
switch ( V_25 ) {
case V_290 :
break;
case V_291 :
if ( F_135 ( V_275 ) )
F_83 ( V_275 , V_313 ) ;
else
F_83 ( V_275 ,
V_314 ) ;
F_137 ( V_275 ) ;
F_134 ( V_275 , V_332 , V_58 ) ;
F_8 ( V_275 -> V_64 -> V_13 , V_301 ,
V_302 , 0 , L_9 ) ;
F_131 ( V_295 , V_275 -> V_251 ) ;
F_132 ( V_303 , V_79 , V_304 ,
L_15 , V_295 ) ;
F_125 ( V_275 , V_333 ) ;
F_132 ( V_303 , V_79 , V_304 ,
L_10 , V_295 ) ;
F_125 ( V_275 , V_305 ) ;
break;
case V_307 :
F_83 ( V_275 , V_309 ) ;
F_137 ( V_275 ) ;
F_134 ( V_275 , V_332 , V_58 ) ;
F_8 ( V_275 -> V_64 -> V_13 , V_301 ,
V_319 , 0 , L_16 ) ;
F_131 ( V_295 , V_275 -> V_251 ) ;
if ( F_138 ( V_275 -> V_64 ) ) {
F_132 ( V_303 , V_79 , V_304 ,
L_15 , V_295 ) ;
F_125 ( V_275 , V_333 ) ;
} else {
F_132 ( V_334 , V_79 , V_304 ,
L_17
L_18 , V_295 ) ;
F_125 ( V_275 , V_335 ) ;
}
break;
case V_298 :
F_83 ( V_275 , V_300 ) ;
F_137 ( V_275 ) ;
F_131 ( V_295 , V_275 -> V_251 ) ;
if ( F_138 ( V_275 -> V_64 ) ) {
F_132 ( V_303 , V_79 , V_304 ,
L_15 , V_295 ) ;
F_125 ( V_275 , V_333 ) ;
} else {
F_132 ( V_334 , V_79 , V_304 ,
L_17
L_18 , V_295 ) ;
F_125 ( V_275 , V_335 ) ;
}
break;
case V_293 :
F_83 ( V_275 , V_294 ) ;
F_137 ( V_275 ) ;
F_134 ( V_275 , V_332 , V_58 ) ;
F_131 ( V_295 , V_275 -> V_251 ) ;
if ( F_138 ( V_275 -> V_64 ) ) {
F_132 ( V_303 , V_79 , V_304 ,
L_15 , V_295 ) ;
F_125 ( V_275 , V_333 ) ;
} else {
F_132 ( V_334 , V_79 , V_304 ,
L_17
L_18 , V_295 ) ;
F_125 ( V_275 , V_335 ) ;
}
break;
default:
F_87 ( V_275 -> V_64 , V_25 ) ;
}
}
static void
V_314 ( struct V_274 * V_275 ,
enum V_285 V_25 )
{
F_37 ( V_275 -> V_64 , V_25 ) ;
switch ( V_25 ) {
case V_297 :
F_83 ( V_275 , V_313 ) ;
F_135 ( V_275 ) ;
break;
case V_298 :
F_83 ( V_275 , V_300 ) ;
F_76 ( & V_275 -> V_299 ) ;
break;
case V_290 :
F_83 ( V_275 , V_336 ) ;
break;
case V_291 :
break;
case V_306 :
case V_307 :
break;
case V_293 :
F_83 ( V_275 , V_337 ) ;
F_76 ( & V_275 -> V_299 ) ;
break;
default:
F_87 ( V_275 -> V_64 , V_25 ) ;
}
}
static void
V_336 ( struct V_274 * V_275 ,
enum V_285 V_25 )
{
F_37 ( V_275 -> V_64 , V_25 ) ;
switch ( V_25 ) {
case V_297 :
F_83 ( V_275 , V_313 ) ;
F_135 ( V_275 ) ;
if ( F_130 ( V_275 ) )
F_83 ( V_275 , V_288 ) ;
else
F_83 ( V_275 ,
V_289 ) ;
break;
case V_298 :
F_83 ( V_275 , V_300 ) ;
F_76 ( & V_275 -> V_299 ) ;
break;
case V_290 :
break;
case V_291 :
F_83 ( V_275 , V_314 ) ;
break;
case V_306 :
case V_307 :
break;
case V_293 :
F_83 ( V_275 , V_337 ) ;
F_76 ( & V_275 -> V_299 ) ;
break;
default:
F_87 ( V_275 -> V_64 , V_25 ) ;
}
}
static void
V_313 ( struct V_274 * V_275 ,
enum V_285 V_25 )
{
char V_295 [ V_296 ] ;
struct V_277 * V_79 = (struct V_277 * ) V_275 -> V_64 -> V_79 ;
F_37 ( V_275 -> V_64 , V_25 ) ;
switch ( V_25 ) {
case V_308 :
F_83 ( V_275 , V_292 ) ;
break;
case V_291 :
break;
case V_290 :
if ( F_130 ( V_275 ) )
F_83 ( V_275 , V_288 ) ;
else
F_83 ( V_275 ,
V_289 ) ;
F_8 ( V_275 -> V_64 -> V_13 , V_301 ,
V_338 , 0 , L_19 ) ;
F_131 ( V_295 , V_275 -> V_251 ) ;
F_132 ( V_303 , V_79 , V_304 ,
L_20 , V_295 ) ;
F_125 ( V_275 , V_339 ) ;
break;
case V_298 :
F_83 ( V_275 , V_300 ) ;
break;
case V_306 :
case V_307 :
break;
case V_293 :
F_83 ( V_275 , V_337 ) ;
break;
default:
F_87 ( V_275 -> V_64 , V_25 ) ;
}
}
static void
V_292 ( struct V_274 * V_275 ,
enum V_285 V_25 )
{
char V_295 [ V_296 ] ;
struct V_277 * V_79 = (struct V_277 * ) V_275 -> V_64 -> V_79 ;
F_37 ( V_275 -> V_64 , V_25 ) ;
switch ( V_25 ) {
case V_286 :
break;
case V_298 :
F_83 ( V_275 , V_300 ) ;
break;
case V_290 :
if ( F_130 ( V_275 ) )
F_83 ( V_275 , V_288 ) ;
else
F_83 ( V_275 ,
V_289 ) ;
F_8 ( V_275 -> V_64 -> V_13 , V_301 ,
V_338 , 0 , L_19 ) ;
F_131 ( V_295 , V_275 -> V_251 ) ;
F_132 ( V_303 , V_79 , V_304 ,
L_20 , V_295 ) ;
F_125 ( V_275 , V_339 ) ;
break;
case V_291 :
break;
case V_293 :
F_83 ( V_275 , V_337 ) ;
break;
default:
F_87 ( V_275 -> V_64 , V_25 ) ;
}
}
static void
V_300 ( struct V_274 * V_275 ,
enum V_285 V_25 )
{
F_37 ( V_275 -> V_64 , V_25 ) ;
switch ( V_25 ) {
case V_286 :
if ( F_130 ( V_275 ) )
F_83 ( V_275 , V_288 ) ;
else
F_83 ( V_275 ,
V_289 ) ;
break;
default:
;
}
}
static void
V_294 ( struct V_274 * V_275 ,
enum V_285 V_25 )
{
F_37 ( V_275 -> V_64 , V_25 ) ;
switch ( V_25 ) {
case V_286 :
if ( F_130 ( V_275 ) )
F_83 ( V_275 , V_288 ) ;
else
F_83 ( V_275 ,
V_289 ) ;
break;
default:
;
}
}
static void
V_337 ( struct V_274 * V_275 ,
enum V_285 V_25 )
{
F_37 ( V_275 -> V_64 , V_25 ) ;
switch ( V_25 ) {
case V_286 :
F_83 ( V_275 , V_292 ) ;
break;
case V_290 :
F_83 ( V_275 , V_294 ) ;
break;
default:
;
}
}
static void
F_139 ( struct V_340 * V_341 ,
enum V_342 V_25 )
{
F_37 ( V_341 -> V_275 -> V_64 , V_25 ) ;
switch ( V_25 ) {
case V_343 :
F_83 ( V_341 , V_344 ) ;
F_140 ( V_341 , V_312 ) ;
break;
default:
F_87 ( V_341 -> V_275 -> V_64 , V_25 ) ;
}
}
static void
F_141 ( struct V_340 * V_341 ,
enum V_342 V_25 )
{
F_37 ( V_341 -> V_275 -> V_64 , V_25 ) ;
switch ( V_25 ) {
case V_343 :
F_83 ( V_341 , V_345 ) ;
break;
case V_346 :
F_83 ( V_341 , F_139 ) ;
break;
default:
F_87 ( V_341 -> V_275 -> V_64 , V_25 ) ;
}
}
static void
V_345 ( struct V_340 * V_341 ,
enum V_342 V_25 )
{
F_37 ( V_341 -> V_275 -> V_64 , V_25 ) ;
switch ( V_25 ) {
case V_347 :
F_83 ( V_341 , F_141 ) ;
break;
case V_346 :
F_83 ( V_341 , V_344 ) ;
F_140 ( V_341 , V_312 ) ;
break;
default:
F_87 ( V_341 -> V_275 -> V_64 , V_25 ) ;
}
}
static void
F_142 ( struct V_340 * V_341 ,
enum V_342 V_25 )
{
F_37 ( V_341 -> V_275 -> V_64 , V_25 ) ;
switch ( V_25 ) {
case V_347 :
F_83 ( V_341 , F_141 ) ;
F_140 ( V_341 , V_332 ) ;
break;
default:
F_87 ( V_341 -> V_275 -> V_64 , V_25 ) ;
}
}
static void
V_344 ( struct V_340 * V_341 ,
enum V_342 V_25 )
{
F_37 ( V_341 -> V_275 -> V_64 , V_25 ) ;
switch ( V_25 ) {
case V_347 :
F_83 ( V_341 , V_348 ) ;
break;
case V_346 :
F_83 ( V_341 , F_142 ) ;
break;
default:
F_87 ( V_341 -> V_275 -> V_64 , V_25 ) ;
}
}
static void
V_348 ( struct V_340 * V_341 ,
enum V_342 V_25 )
{
F_37 ( V_341 -> V_275 -> V_64 , V_25 ) ;
switch ( V_25 ) {
case V_343 :
F_83 ( V_341 , V_349 ) ;
break;
case V_346 :
F_83 ( V_341 , F_141 ) ;
F_140 ( V_341 , V_332 ) ;
break;
default:
F_87 ( V_341 -> V_275 -> V_64 , V_25 ) ;
}
}
static void
V_349 ( struct V_340 * V_341 ,
enum V_342 V_25 )
{
F_37 ( V_341 -> V_275 -> V_64 , V_25 ) ;
switch ( V_25 ) {
case V_347 :
F_83 ( V_341 , V_348 ) ;
break;
case V_346 :
F_83 ( V_341 , V_345 ) ;
F_140 ( V_341 , V_332 ) ;
break;
default:
F_87 ( V_341 -> V_275 -> V_64 , V_25 ) ;
}
}
static void
F_143 ( void * V_119 , T_7 V_124 )
{
struct V_340 * V_341 = V_119 ;
if ( V_124 )
V_341 -> V_275 -> V_311 ( V_341 -> V_275 -> V_350 , V_341 -> V_351 ) ;
else
F_88 ( V_341 , V_346 ) ;
}
static void
F_134 ( struct V_274 * V_275 , enum V_352 V_25 ,
T_7 V_353 )
{
if ( V_275 -> V_60 . V_354 && ! V_353 )
return;
switch ( V_25 ) {
case V_312 :
F_88 ( & V_275 -> V_341 , V_343 ) ;
break;
case V_332 :
F_88 ( & V_275 -> V_341 , V_347 ) ;
break;
default:
F_5 ( 1 ) ;
}
}
static void
F_140 ( struct V_340 * V_341 , enum V_352 V_25 )
{
struct V_274 * V_275 = V_341 -> V_275 ;
if ( V_275 -> V_64 -> V_260 ) {
V_275 -> V_311 ( V_275 -> V_350 , V_25 ) ;
F_88 ( V_341 , V_346 ) ;
} else {
V_341 -> V_351 = V_25 ;
F_33 ( V_275 -> V_64 , & V_341 -> V_355 ,
F_143 , V_341 ) ;
}
}
static void
F_144 ( struct V_59 * V_60 , struct V_61 * V_62 ,
struct V_63 * V_64 )
{
struct V_67 * V_356 = F_145 ( V_64 ) ;
F_23 ( V_62 , V_356 , V_357 ) ;
}
static void
F_146 ( void * V_119 )
{
struct V_274 * V_275 = V_119 ;
F_88 ( V_275 , V_297 ) ;
}
static void
F_147 ( struct V_274 * V_275 )
{
struct V_67 * V_356 = & V_275 -> V_356 ;
V_275 -> V_358 = F_148 ( V_356 ) ;
V_275 -> V_359 = F_149 ( V_356 ) ;
V_275 -> V_360 = (union V_361 * )
F_148 ( V_356 ) ;
}
static void
F_150 ( struct V_63 * V_64 , void * V_79 , struct V_59 * V_60 ,
struct V_80 * V_81 )
{
struct V_274 * V_275 = F_151 ( V_64 ) ;
struct V_362 * V_363 = & V_275 -> V_60 ;
struct V_340 * V_341 = & V_275 -> V_341 ;
struct V_9 V_10 ;
V_275 -> V_64 = V_64 ;
V_341 -> V_275 = V_275 ;
F_147 ( V_275 ) ;
F_83 ( V_275 , F_129 ) ;
F_83 ( V_341 , F_139 ) ;
F_3 ( & V_10 ) ;
V_275 -> V_364 = V_10 . V_11 ;
V_363 -> V_365 = V_366 ;
V_363 -> V_367 = V_368 ;
V_363 -> V_354 = V_58 ;
V_363 -> V_369 = 0 ;
V_363 -> V_370 = V_371 ;
F_14 ( & V_275 -> V_372 ) ;
F_14 ( & V_275 -> V_373 ) ;
F_16 ( & V_275 -> V_299 , F_146 , V_275 ) ;
}
static void
F_152 ( struct V_63 * V_64 )
{
}
static void
F_153 ( struct V_63 * V_64 )
{
F_88 ( F_151 ( V_64 ) , V_286 ) ;
}
static void
F_154 ( struct V_63 * V_64 )
{
F_88 ( F_151 ( V_64 ) , V_298 ) ;
F_155 ( V_64 ) ;
}
static void
F_156 ( struct V_63 * V_64 )
{
struct V_274 * V_275 = F_151 ( V_64 ) ;
F_88 ( V_275 , V_293 ) ;
F_155 ( V_64 ) ;
}
static void
F_133 ( struct V_274 * V_275 )
{
struct V_315 * V_316 = V_275 -> V_317 . V_318 . V_25 ;
struct V_374 * V_353 = & V_275 -> V_353 ;
V_275 -> V_367 = V_316 -> V_320 . V_367 ;
V_275 -> V_365 = V_316 -> V_320 . V_365 ;
if ( V_275 -> V_365 == V_375 )
V_275 -> V_376 = 0 ;
V_275 -> V_328 = V_316 -> V_320 . V_328 ;
V_275 -> V_377 = V_316 -> V_320 . V_321 . V_377 ;
if ( ! V_275 -> V_60 . V_354 )
V_353 -> V_378 . V_329 = V_379 ;
V_275 -> V_380 = F_44 ( V_316 -> V_320 . V_321 . V_322 . V_381 ) ;
F_37 ( V_275 -> V_64 , V_275 -> V_367 ) ;
F_37 ( V_275 -> V_64 , V_275 -> V_365 ) ;
}
static void
F_137 ( struct V_274 * V_275 )
{
V_275 -> V_367 = V_382 ;
V_275 -> V_365 = V_383 ;
V_275 -> V_384 = V_58 ;
}
static T_7
F_130 ( struct V_274 * V_275 )
{
struct V_385 * V_245 ;
V_275 -> V_386 ++ ;
V_245 = F_51 ( V_275 -> V_64 , V_387 ) ;
if ( ! V_245 ) {
F_70 ( V_275 -> V_64 , V_387 ,
& V_275 -> V_299 ) ;
return V_58 ;
}
F_53 ( V_245 -> V_146 , V_388 , V_389 ,
F_54 ( V_275 -> V_64 ) ) ;
V_245 -> V_252 = V_275 -> V_252 ;
V_245 -> V_251 = V_275 -> V_251 ;
V_245 -> V_363 = V_275 -> V_60 ;
V_245 -> V_386 = V_275 -> V_386 ;
V_245 -> V_363 . V_369 = F_55 ( V_275 -> V_60 . V_369 ) ;
V_245 -> V_287 = V_275 -> V_287 ;
F_157 ( V_245 -> V_390 , V_275 -> V_359 ) ;
F_37 ( V_275 -> V_64 , V_245 -> V_390 . V_391 . V_392 ) ;
F_37 ( V_275 -> V_64 , V_245 -> V_390 . V_391 . V_393 ) ;
F_61 ( V_275 -> V_64 , V_387 , V_245 -> V_146 ) ;
return V_169 ;
}
static T_7
F_135 ( struct V_274 * V_275 )
{
struct V_394 * V_245 ;
V_275 -> V_386 ++ ;
V_245 = F_51 ( V_275 -> V_64 , V_387 ) ;
if ( ! V_245 ) {
F_70 ( V_275 -> V_64 , V_387 ,
& V_275 -> V_299 ) ;
return V_58 ;
}
F_53 ( V_245 -> V_146 , V_388 , V_395 ,
F_54 ( V_275 -> V_64 ) ) ;
V_245 -> V_386 = V_275 -> V_386 ;
F_61 ( V_275 -> V_64 , V_387 , V_245 -> V_146 ) ;
return V_169 ;
}
static void
F_158 ( struct V_274 * V_275 )
{
V_275 -> V_251 = V_275 -> V_64 -> V_261 . V_378 -> V_251 ;
V_275 -> V_252 = V_275 -> V_64 -> V_261 . V_378 -> V_252 ;
F_37 ( V_275 -> V_64 , V_275 -> V_251 ) ;
F_37 ( V_275 -> V_64 , V_275 -> V_252 ) ;
}
static void
F_159 ( void * V_396 )
{
struct V_274 * V_275 = V_396 ;
struct V_397 * V_245 ;
V_245 = F_51 ( V_275 -> V_64 , V_387 ) ;
if ( ! V_245 ) {
F_37 ( V_275 -> V_64 , V_275 -> V_60 . V_398 ) ;
return;
}
F_53 ( V_245 -> V_146 , V_388 , V_399 ,
F_54 ( V_275 -> V_64 ) ) ;
V_245 -> V_398 = F_55 ( ( T_2 ) V_275 -> V_60 . V_398 ) ;
V_245 -> V_230 = V_275 -> V_60 . V_230 ;
F_61 ( V_275 -> V_64 , V_387 , V_245 -> V_146 ) ;
}
static void
F_160 ( struct V_400 * V_401 ,
struct V_400 * V_402 )
{
T_3 * V_403 = ( T_3 * ) V_401 ;
T_13 * V_404 = ( T_13 * ) V_402 ;
int V_35 ;
for ( V_35 = 0 ; V_35 < ( sizeof( struct V_400 ) / sizeof( T_3 ) ) ; ++ V_35 )
V_403 [ V_35 ] = F_45 ( V_404 [ V_35 ] ) ;
}
static void
F_161 ( struct V_405 * V_401 ,
struct V_405 * V_402 )
{
T_3 * V_403 = ( T_3 * ) V_401 ;
T_13 * V_404 = ( T_13 * ) V_402 ;
int V_35 ;
for ( V_35 = 0 ; V_35 < ( ( sizeof( struct V_405 ) ) / sizeof( T_3 ) ) ;
V_35 = V_35 + 2 ) {
#ifdef F_162
V_403 [ V_35 ] = F_45 ( V_404 [ V_35 ] ) ;
V_403 [ V_35 + 1 ] = F_45 ( V_404 [ V_35 + 1 ] ) ;
#else
V_403 [ V_35 ] = F_45 ( V_404 [ V_35 + 1 ] ) ;
V_403 [ V_35 + 1 ] = F_45 ( V_404 [ V_35 ] ) ;
#endif
}
}
static void
F_163 ( void * V_119 , T_7 V_124 )
{
struct V_274 * V_275 = (struct V_274 * ) V_119 ;
struct V_406 * V_407 ;
struct V_85 * V_54 , * V_86 ;
union V_361 * V_408 ;
if ( V_124 ) {
struct V_9 V_10 ;
if ( V_275 -> V_409 == V_128 )
F_3 ( & V_10 ) ;
F_31 (qe, qen, &fcport->stats_pending_q) {
F_35 ( & V_275 -> V_372 , & V_54 ) ;
V_407 = (struct V_406 * ) V_54 ;
if ( V_275 -> V_409 == V_128 ) {
V_408 = (union V_361 * ) V_407 -> V_410 ;
if ( F_136 ( & V_275 -> V_64 -> V_261 ) )
F_160 ( & V_408 -> V_411 ,
& V_275 -> V_360 -> V_411 ) ;
else {
F_161 ( & V_408 -> V_412 ,
& V_275 -> V_360 -> V_412 ) ;
V_408 -> V_412 . V_413 =
V_10 . V_11 - V_275 -> V_364 ;
}
}
F_164 ( V_275 -> V_64 , & V_407 -> V_92 ,
V_275 -> V_409 ) ;
}
V_275 -> V_409 = V_128 ;
} else {
F_14 ( & V_275 -> V_372 ) ;
V_275 -> V_409 = V_128 ;
}
}
static void
F_165 ( void * V_119 )
{
struct V_274 * V_275 = (struct V_274 * ) V_119 ;
F_37 ( V_275 -> V_64 , V_275 -> V_414 ) ;
if ( V_275 -> V_414 ) {
F_76 ( & V_275 -> V_415 ) ;
V_275 -> V_414 = V_58 ;
}
V_275 -> V_409 = V_416 ;
F_163 ( V_275 , V_169 ) ;
}
static void
F_166 ( void * V_119 )
{
struct V_274 * V_275 = (struct V_274 * ) V_119 ;
struct V_394 * V_171 ;
V_171 = F_51 ( V_275 -> V_64 , V_387 ) ;
if ( ! V_171 ) {
V_275 -> V_414 = V_169 ;
F_16 ( & V_275 -> V_415 ,
F_166 , V_275 ) ;
F_70 ( V_275 -> V_64 , V_387 ,
& V_275 -> V_415 ) ;
return;
}
V_275 -> V_414 = V_58 ;
memset ( V_171 , 0 , sizeof( struct V_394 ) ) ;
F_53 ( V_171 -> V_146 , V_388 , V_417 ,
F_54 ( V_275 -> V_64 ) ) ;
F_61 ( V_275 -> V_64 , V_387 , V_171 -> V_146 ) ;
}
static void
F_167 ( void * V_119 , T_7 V_124 )
{
struct V_274 * V_275 = (struct V_274 * ) V_119 ;
struct V_406 * V_407 ;
struct V_85 * V_54 , * V_86 ;
if ( V_124 ) {
struct V_9 V_10 ;
F_3 ( & V_10 ) ;
V_275 -> V_364 = V_10 . V_11 ;
F_31 (qe, qen, &fcport->statsclr_pending_q) {
F_35 ( & V_275 -> V_373 , & V_54 ) ;
V_407 = (struct V_406 * ) V_54 ;
F_164 ( V_275 -> V_64 , & V_407 -> V_92 ,
V_275 -> V_409 ) ;
}
V_275 -> V_409 = V_128 ;
} else {
F_14 ( & V_275 -> V_373 ) ;
V_275 -> V_409 = V_128 ;
}
}
static void
F_168 ( void * V_119 )
{
struct V_274 * V_275 = (struct V_274 * ) V_119 ;
F_37 ( V_275 -> V_64 , V_275 -> V_414 ) ;
if ( V_275 -> V_414 ) {
F_76 ( & V_275 -> V_415 ) ;
V_275 -> V_414 = V_58 ;
}
V_275 -> V_409 = V_416 ;
F_167 ( V_275 , V_169 ) ;
}
static void
F_169 ( void * V_119 )
{
struct V_274 * V_275 = (struct V_274 * ) V_119 ;
struct V_394 * V_171 ;
V_171 = F_51 ( V_275 -> V_64 , V_387 ) ;
if ( ! V_171 ) {
V_275 -> V_414 = V_169 ;
F_16 ( & V_275 -> V_415 ,
F_169 , V_275 ) ;
F_70 ( V_275 -> V_64 , V_387 ,
& V_275 -> V_415 ) ;
return;
}
V_275 -> V_414 = V_58 ;
memset ( V_171 , 0 , sizeof( struct V_394 ) ) ;
F_53 ( V_171 -> V_146 , V_388 , V_418 ,
F_54 ( V_275 -> V_64 ) ) ;
F_61 ( V_275 -> V_64 , V_387 , V_171 -> V_146 ) ;
}
static void
F_170 ( struct V_274 * V_275 , struct V_419 * V_420 )
{
struct V_374 * V_353 = & V_275 -> V_353 ;
struct V_421 * V_422 ;
struct V_423 * V_424 ;
enum V_425 V_426 ;
int V_35 ;
int V_427 = 0 ;
F_37 ( V_275 -> V_64 , V_275 -> V_60 . V_354 ) ;
F_5 ( V_420 -> V_428 != V_429 &&
V_420 -> V_428 != V_430 ) ;
F_37 ( V_275 -> V_64 , V_353 -> V_378 . V_329 ) ;
F_37 ( V_275 -> V_64 , V_420 -> V_428 ) ;
F_37 ( V_275 -> V_64 , V_420 -> V_431 ) ;
V_426 = V_353 -> V_378 . V_329 ;
if ( V_275 -> V_60 . V_354 && ( V_353 -> V_378 . V_329 != V_379 ) )
V_353 -> V_378 . V_329 = V_420 -> V_428 ;
V_353 -> V_378 . V_367 = V_420 -> V_431 ;
for ( V_35 = 0 ; V_35 < V_432 ; V_35 ++ ) {
V_424 = & V_353 -> V_378 . V_433 [ V_35 ] ;
V_422 = & V_420 -> V_422 [ V_35 ] ;
V_424 -> V_320 = V_422 -> V_329 ;
V_424 -> V_434 = V_422 -> V_434 ;
V_424 -> V_435 = V_422 -> V_435 ;
V_424 -> V_367 = V_422 -> V_367 ;
V_424 -> V_436 = F_45 ( V_422 -> V_436 ) ;
if ( V_422 -> V_329 == V_437 ) {
V_275 -> V_367 = V_422 -> V_367 ;
V_275 -> V_365 = V_366 ;
V_427 |= 1 << V_35 ;
}
F_37 ( V_275 -> V_64 , V_424 -> V_320 ) ;
F_37 ( V_275 -> V_64 , V_424 -> V_434 ) ;
F_37 ( V_275 -> V_64 , V_424 -> V_435 ) ;
F_37 ( V_275 -> V_64 , V_424 -> V_367 ) ;
F_37 ( V_275 -> V_64 , V_424 -> V_436 ) ;
}
switch ( V_427 ) {
case 3 :
F_8 ( V_275 -> V_64 -> V_13 , V_301 ,
V_438 , 0 , L_21 ) ;
break;
case 2 :
F_8 ( V_275 -> V_64 -> V_13 , V_301 ,
V_438 , 0 , L_22 ) ;
break;
case 1 :
F_8 ( V_275 -> V_64 -> V_13 , V_301 ,
V_438 , 0 , L_23 ) ;
break;
default:
F_8 ( V_275 -> V_64 -> V_13 , V_301 ,
V_438 , 0 , L_24 ) ;
}
if ( ( V_426 != V_353 -> V_378 . V_329 ) ||
( V_420 -> V_428 == V_430 ) ) {
F_134 ( V_275 , ( V_420 -> V_428 == V_429 ) ?
V_312 : V_332 , V_169 ) ;
}
}
static void
F_155 ( struct V_63 * V_64 )
{
struct V_274 * V_275 = F_151 ( V_64 ) ;
int V_35 = 0 ;
if ( V_275 -> V_60 . V_354 ) {
if ( V_275 -> V_353 . V_378 . V_329 == V_429 )
F_134 ( V_275 , V_332 , V_169 ) ;
V_275 -> V_353 . V_378 . V_329 = V_430 ;
V_275 -> V_353 . V_378 . V_367 = V_382 ;
for ( V_35 = 0 ; V_35 < V_432 ; V_35 ++ ) {
V_275 -> V_353 . V_378 . V_433 [ V_35 ] . V_434 = 0 ;
V_275 -> V_353 . V_378 . V_433 [ V_35 ] . V_435 =
V_439 ;
V_275 -> V_353 . V_378 . V_433 [ V_35 ] . V_320 =
V_440 ;
V_275 -> V_353 . V_378 . V_433 [ V_35 ] . V_367 =
V_382 ;
V_275 -> V_353 . V_378 . V_433 [ V_35 ] . V_436 = 0 ;
}
}
}
void
F_171 ( struct V_63 * V_64 )
{
struct V_274 * V_275 = F_151 ( V_64 ) ;
F_158 ( V_275 ) ;
if ( V_275 -> V_60 . V_369 == 0 )
V_275 -> V_60 . V_369 = F_172 ( & V_64 -> V_261 ) ;
V_275 -> V_60 . V_441 = F_173 ( & V_64 -> V_261 ) ;
V_275 -> V_442 = F_174 ( & V_64 -> V_261 ) ;
if ( F_175 ( V_64 ) )
V_64 -> V_443 . V_281 . V_444 = V_169 ;
F_5 ( ! V_275 -> V_60 . V_369 ) ;
F_5 ( ! V_275 -> V_60 . V_441 ) ;
F_5 ( ! V_275 -> V_442 ) ;
}
void
F_176 ( struct V_63 * V_64 , struct V_170 * V_171 )
{
struct V_274 * V_275 = F_151 ( V_64 ) ;
union V_445 V_318 ;
V_318 . V_171 = V_171 ;
V_275 -> V_317 . V_318 = V_318 ;
F_37 ( V_64 , V_171 -> V_172 . V_173 ) ;
F_37 ( V_64 , F_177 ( V_446 , V_275 -> V_447 ) ) ;
switch ( V_171 -> V_172 . V_173 ) {
case V_448 :
if ( V_275 -> V_386 == V_318 . V_449 -> V_386 ) {
if ( V_275 -> V_287 ) {
V_275 -> V_60 = V_318 . V_449 -> V_363 ;
V_275 -> V_60 . V_369 =
F_55 ( V_275 -> V_60 . V_369 ) ;
V_275 -> V_60 . V_450 =
F_55 ( V_275 -> V_60 . V_450 ) ;
V_275 -> V_60 . V_451 =
F_55 ( V_275 -> V_60 . V_451 ) ;
if ( V_275 -> V_60 . V_354 )
V_275 -> V_353 . V_378 . V_329 =
V_430 ;
else
V_275 -> V_353 . V_378 . V_329 =
V_379 ;
V_275 -> V_287 = V_58 ;
}
if ( V_275 -> V_60 . V_327 )
V_275 -> V_328 . V_329 = V_452 ;
else
V_275 -> V_328 . V_329 = V_453 ;
F_88 ( V_275 , V_308 ) ;
}
break;
case V_454 :
if ( V_275 -> V_386 == V_318 . V_449 -> V_386 )
F_88 ( V_275 , V_308 ) ;
break;
case V_455 :
if ( V_318 . V_25 -> V_320 . V_456 == V_312 )
F_88 ( V_275 , V_306 ) ;
else
F_88 ( V_275 , V_307 ) ;
break;
case V_457 :
F_170 ( V_275 , V_318 . V_458 ) ;
break;
case V_459 :
if ( F_73 ( & V_275 -> V_372 ) ||
( V_275 -> V_409 == V_416 ) )
break;
F_178 ( & V_275 -> V_460 ) ;
V_275 -> V_409 = V_318 . V_461 -> V_192 ;
F_163 ( V_275 , V_169 ) ;
break;
case V_462 :
if ( F_73 ( & V_275 -> V_373 ) ||
( V_275 -> V_409 == V_416 ) )
break;
F_178 ( & V_275 -> V_460 ) ;
V_275 -> V_409 = V_128 ;
F_167 ( V_275 , V_169 ) ;
break;
case V_463 :
F_88 ( V_275 , V_290 ) ;
break;
case V_464 :
F_88 ( V_275 , V_291 ) ;
break;
default:
F_5 ( 1 ) ;
break;
}
}
void
F_179 ( struct V_63 * V_64 ,
void (* V_168) ( void * V_119 ,
enum V_352 V_25 ) ,
void * V_119 )
{
struct V_274 * V_275 = F_151 ( V_64 ) ;
V_275 -> V_311 = V_168 ;
V_275 -> V_350 = V_119 ;
}
T_6
F_180 ( struct V_63 * V_64 )
{
struct V_274 * V_275 = F_151 ( V_64 ) ;
if ( F_175 ( V_64 ) )
return V_465 ;
if ( F_181 ( & V_64 -> V_261 ) )
return V_466 ;
if ( V_275 -> V_467 )
return V_468 ;
F_88 ( F_151 ( V_64 ) , V_290 ) ;
return V_128 ;
}
T_6
F_182 ( struct V_63 * V_64 )
{
if ( F_175 ( V_64 ) )
return V_465 ;
if ( F_181 ( & V_64 -> V_261 ) )
return V_466 ;
F_88 ( F_151 ( V_64 ) , V_291 ) ;
return V_128 ;
}
T_6
F_175 ( struct V_63 * V_64 )
{
struct V_274 * V_275 = F_151 ( V_64 ) ;
struct V_469 * V_470 = & V_64 -> V_470 ;
struct V_471 * V_472 = V_470 -> V_472 ;
if ( V_472 -> V_473 . V_474 == V_475 ) {
F_37 ( V_64 , V_275 -> V_251 ) ;
return V_465 ;
}
return V_128 ;
}
T_6
F_183 ( struct V_63 * V_64 , enum V_476 V_367 )
{
struct V_274 * V_275 = F_151 ( V_64 ) ;
F_37 ( V_64 , V_367 ) ;
if ( V_275 -> V_60 . V_354 == V_169 )
return V_477 ;
if ( ( V_367 != V_368 ) && ( V_367 > V_275 -> V_442 ) ) {
F_37 ( V_64 , V_275 -> V_442 ) ;
return V_478 ;
}
if ( F_184 ( V_275 -> V_64 -> V_261 . V_378 -> V_479 ) ) {
if ( F_185 ( & V_275 -> V_64 -> V_261 ) == V_480 ) {
if ( ( V_367 == V_371 ) &&
( F_186 ( V_64 -> V_261 . V_81 . V_481 ) ) )
return V_478 ;
if ( ! ( V_367 == V_371 ||
V_367 == V_482 ||
V_367 == V_483 ||
V_367 == V_484 ||
V_367 == V_485 ||
V_367 == V_368 ) )
return V_478 ;
} else {
if ( V_367 != V_486 )
return V_478 ;
}
}
V_275 -> V_60 . V_367 = V_367 ;
return V_128 ;
}
enum V_476
F_187 ( struct V_63 * V_64 )
{
struct V_274 * V_275 = F_151 ( V_64 ) ;
return V_275 -> V_367 ;
}
T_6
F_188 ( struct V_63 * V_64 , enum V_487 V_365 )
{
struct V_274 * V_275 = F_151 ( V_64 ) ;
F_37 ( V_64 , V_365 ) ;
F_37 ( V_64 , V_275 -> V_60 . V_365 ) ;
switch ( V_365 ) {
case V_366 :
case V_375 :
case V_488 :
break;
default:
return V_489 ;
}
V_275 -> V_60 . V_365 = V_365 ;
return V_128 ;
}
enum V_487
F_189 ( struct V_63 * V_64 )
{
struct V_274 * V_275 = F_151 ( V_64 ) ;
return V_275 -> V_365 ;
}
T_6
F_190 ( struct V_63 * V_64 , V_37 V_248 )
{
struct V_274 * V_275 = F_151 ( V_64 ) ;
F_37 ( V_64 , V_248 ) ;
F_37 ( V_64 , V_275 -> V_60 . V_490 ) ;
F_37 ( V_64 , V_275 -> V_60 . V_491 ) ;
V_275 -> V_60 . V_490 = V_169 ;
V_275 -> V_60 . V_491 = V_248 ;
return V_128 ;
}
T_6
F_191 ( struct V_63 * V_64 )
{
struct V_274 * V_275 = F_151 ( V_64 ) ;
F_37 ( V_64 , V_275 -> V_60 . V_490 ) ;
F_37 ( V_64 , V_275 -> V_60 . V_491 ) ;
V_275 -> V_60 . V_490 = V_58 ;
return V_128 ;
}
T_7
F_192 ( struct V_63 * V_64 , V_37 * V_248 )
{
struct V_274 * V_275 = F_151 ( V_64 ) ;
* V_248 = V_275 -> V_60 . V_491 ;
return V_275 -> V_60 . V_490 ;
}
V_37
F_193 ( struct V_63 * V_64 )
{
struct V_274 * V_275 = F_151 ( V_64 ) ;
return V_275 -> V_376 ;
}
T_6
F_194 ( struct V_63 * V_64 , T_2 V_369 )
{
struct V_274 * V_275 = F_151 ( V_64 ) ;
F_37 ( V_64 , V_369 ) ;
F_37 ( V_64 , V_275 -> V_60 . V_369 ) ;
if ( ( V_369 > V_153 ) || ( V_369 < V_492 ) )
return V_493 ;
if ( ( V_369 != V_153 ) && ( V_369 & ( V_369 - 1 ) ) )
return V_493 ;
V_275 -> V_60 . V_369 = V_369 ;
return V_128 ;
}
T_2
F_195 ( struct V_63 * V_64 )
{
struct V_274 * V_275 = F_151 ( V_64 ) ;
return V_275 -> V_60 . V_369 ;
}
V_37
F_196 ( struct V_63 * V_64 )
{
struct V_274 * V_275 = F_151 ( V_64 ) ;
return V_275 -> V_60 . V_441 ;
}
void
F_197 ( struct V_63 * V_64 , T_2 V_398 , V_37 V_230 )
{
struct V_274 * V_275 = F_151 ( V_64 ) ;
V_275 -> V_60 . V_398 = ( V_37 ) V_398 ;
V_275 -> V_60 . V_230 = V_230 ;
if ( V_230 )
V_275 -> V_384 = V_169 ;
F_159 ( V_275 ) ;
}
T_10
F_198 ( struct V_63 * V_64 , T_7 V_494 )
{
struct V_274 * V_275 = F_151 ( V_64 ) ;
if ( V_494 )
return V_275 -> V_252 ;
else
return V_275 -> V_251 ;
}
void
F_199 ( struct V_63 * V_64 , struct V_495 * V_378 )
{
struct V_274 * V_275 = F_151 ( V_64 ) ;
memset ( V_378 , 0 , sizeof( struct V_495 ) ) ;
V_378 -> V_252 = V_275 -> V_252 ;
V_378 -> V_251 = V_275 -> V_251 ;
V_378 -> V_496 = V_64 -> V_261 . V_378 -> V_497 ;
V_378 -> V_498 = V_64 -> V_261 . V_378 -> V_499 ;
memcpy ( & V_378 -> V_500 , & V_275 -> V_60 ,
sizeof( struct V_362 ) ) ;
V_378 -> V_500 . V_367 = V_275 -> V_60 . V_367 ;
V_378 -> V_501 = V_275 -> V_442 ;
V_378 -> V_367 = V_275 -> V_367 ;
V_378 -> V_502 = V_503 ;
V_378 -> V_500 . V_365 = V_275 -> V_60 . V_365 ;
V_378 -> V_365 = V_275 -> V_365 ;
V_378 -> V_500 . V_354 = V_275 -> V_60 . V_354 ;
V_378 -> V_504 = V_275 -> V_504 ;
V_378 -> V_505 = V_275 -> V_505 ;
V_378 -> V_500 . V_450 = F_200 ( V_64 ) ;
V_378 -> V_500 . V_451 = F_201 ( V_64 ) ;
V_378 -> V_506 = F_177 ( V_446 , V_275 -> V_447 ) ;
V_378 -> V_507 = V_275 -> V_384 ;
if ( F_175 ( V_64 ) )
V_378 -> V_506 = V_508 ;
else {
if ( F_181 ( & V_275 -> V_64 -> V_261 ) )
V_378 -> V_506 = V_509 ;
else if ( F_202 ( & V_275 -> V_64 -> V_261 ) )
V_378 -> V_506 = V_510 ;
else if ( F_203 ( & V_275 -> V_64 -> V_261 ) )
V_378 -> V_506 = V_511 ;
}
V_378 -> V_380 = V_275 -> V_380 ;
}
T_6
F_204 ( struct V_63 * V_64 , struct V_406 * V_407 )
{
struct V_274 * V_275 = F_151 ( V_64 ) ;
if ( F_181 ( & V_64 -> V_261 ) )
return V_466 ;
if ( ! F_73 ( & V_275 -> V_373 ) )
return V_512 ;
if ( F_73 ( & V_275 -> V_372 ) ) {
F_15 ( & V_407 -> V_92 . V_54 , & V_275 -> V_372 ) ;
F_166 ( V_275 ) ;
F_205 ( V_64 , & V_275 -> V_460 ,
F_165 ,
V_275 , V_513 ) ;
} else
F_15 ( & V_407 -> V_92 . V_54 , & V_275 -> V_372 ) ;
return V_128 ;
}
T_6
F_206 ( struct V_63 * V_64 , struct V_406 * V_407 )
{
struct V_274 * V_275 = F_151 ( V_64 ) ;
if ( ! F_73 ( & V_275 -> V_372 ) )
return V_512 ;
if ( F_73 ( & V_275 -> V_373 ) ) {
F_15 ( & V_407 -> V_92 . V_54 , & V_275 -> V_373 ) ;
F_169 ( V_275 ) ;
F_205 ( V_64 , & V_275 -> V_460 ,
F_168 ,
V_275 , V_513 ) ;
} else
F_15 ( & V_407 -> V_92 . V_54 , & V_275 -> V_373 ) ;
return V_128 ;
}
T_7
F_207 ( struct V_63 * V_64 )
{
struct V_274 * V_275 = F_151 ( V_64 ) ;
return F_177 ( V_446 , V_275 -> V_447 ) ==
V_514 ;
}
T_7
F_208 ( struct V_63 * V_64 )
{
struct V_274 * V_275 = F_151 ( V_64 ) ;
return V_275 -> V_60 . V_515 ? V_169 : V_58 ;
}
void
F_209 ( struct V_63 * V_64 , V_37 V_329 )
{
struct V_274 * V_275 = F_151 ( V_64 ) ;
F_37 ( V_64 , V_329 ) ;
V_275 -> V_60 . V_516 = V_329 ;
}
enum V_476
F_210 ( struct V_63 * V_64 )
{
struct V_274 * V_275 = F_151 ( V_64 ) ;
F_37 ( V_64 , V_275 -> V_60 . V_370 ) ;
return V_275 -> V_60 . V_370 ;
}
void
F_211 ( void * V_517 , T_7 V_504 ,
T_7 V_505 )
{
struct V_63 * V_64 = V_517 ;
struct V_274 * V_275 = F_151 ( V_64 ) ;
F_37 ( V_64 , V_504 ) ;
F_37 ( V_64 , V_505 ) ;
F_37 ( V_64 , V_275 -> V_504 ) ;
F_37 ( V_64 , V_275 -> V_505 ) ;
V_275 -> V_504 = V_504 ;
V_275 -> V_505 = V_505 ;
}
T_7
F_212 ( struct V_63 * V_64 )
{
struct V_274 * V_275 = F_151 ( V_64 ) ;
return ( ! V_275 -> V_60 . V_354 &&
F_213 ( V_275 , V_310 ) ) ||
( V_275 -> V_60 . V_354 &&
V_275 -> V_353 . V_378 . V_329 == V_429 ) ;
}
T_7
F_214 ( struct V_63 * V_64 )
{
struct V_274 * V_275 = F_151 ( V_64 ) ;
return V_275 -> V_60 . V_327 ;
}
T_7
F_215 ( struct V_63 * V_64 )
{
struct V_274 * V_275 = F_151 ( V_64 ) ;
return V_275 -> V_60 . V_354 ;
}
static void
F_216 ( struct V_143 * V_518 , enum V_519 V_25 )
{
F_37 ( V_518 -> V_64 , V_518 -> V_520 ) ;
F_37 ( V_518 -> V_64 , V_25 ) ;
switch ( V_25 ) {
case V_521 :
F_217 ( V_518 , V_522 ) ;
F_83 ( V_518 , V_523 ) ;
break;
default:
F_217 ( V_518 , V_524 ) ;
F_87 ( V_518 -> V_64 , V_25 ) ;
}
}
static void
V_523 ( struct V_143 * V_518 , enum V_519 V_25 )
{
F_37 ( V_518 -> V_64 , V_518 -> V_520 ) ;
F_37 ( V_518 -> V_64 , V_25 ) ;
switch ( V_25 ) {
case V_525 :
F_217 ( V_518 , V_526 ) ;
if ( F_218 ( V_518 ) )
F_83 ( V_518 , V_527 ) ;
else
F_83 ( V_518 , V_528 ) ;
break;
case V_529 :
F_217 ( V_518 , V_530 ) ;
F_83 ( V_518 , F_216 ) ;
F_219 ( V_518 ) ;
break;
case V_531 :
F_217 ( V_518 , V_532 ) ;
F_83 ( V_518 , V_533 ) ;
break;
default:
F_217 ( V_518 , V_534 ) ;
F_87 ( V_518 -> V_64 , V_25 ) ;
}
}
static void
V_527 ( struct V_143 * V_518 , enum V_519 V_25 )
{
F_37 ( V_518 -> V_64 , V_518 -> V_520 ) ;
F_37 ( V_518 -> V_64 , V_25 ) ;
switch ( V_25 ) {
case V_535 :
F_217 ( V_518 , V_536 ) ;
F_83 ( V_518 , V_537 ) ;
F_220 ( V_518 ) ;
break;
case V_529 :
F_217 ( V_518 , V_538 ) ;
F_83 ( V_518 , V_539 ) ;
break;
case V_540 :
F_217 ( V_518 , V_541 ) ;
F_83 ( V_518 , V_542 ) ;
break;
case V_531 :
F_217 ( V_518 , V_543 ) ;
F_83 ( V_518 , V_533 ) ;
break;
default:
F_217 ( V_518 , V_544 ) ;
F_87 ( V_518 -> V_64 , V_25 ) ;
}
}
static void
V_528 ( struct V_143 * V_518 , enum V_519 V_25 )
{
F_37 ( V_518 -> V_64 , V_518 -> V_520 ) ;
F_37 ( V_518 -> V_64 , V_25 ) ;
switch ( V_25 ) {
case V_545 :
F_83 ( V_518 , V_527 ) ;
F_218 ( V_518 ) ;
break;
case V_529 :
F_217 ( V_518 , V_538 ) ;
F_83 ( V_518 , F_216 ) ;
F_76 ( & V_518 -> V_299 ) ;
F_219 ( V_518 ) ;
break;
case V_540 :
F_217 ( V_518 , V_541 ) ;
F_83 ( V_518 , V_546 ) ;
F_76 ( & V_518 -> V_299 ) ;
F_221 ( V_518 ) ;
break;
case V_531 :
F_217 ( V_518 , V_543 ) ;
F_83 ( V_518 , V_533 ) ;
F_76 ( & V_518 -> V_299 ) ;
break;
default:
F_217 ( V_518 , V_544 ) ;
F_87 ( V_518 -> V_64 , V_25 ) ;
}
}
static void
V_537 ( struct V_143 * V_518 , enum V_519 V_25 )
{
struct V_547 * V_548 ;
F_37 ( V_518 -> V_64 , V_518 -> V_520 ) ;
F_37 ( V_518 -> V_64 , V_25 ) ;
switch ( V_25 ) {
case V_540 :
F_217 ( V_518 , V_549 ) ;
if ( F_222 ( V_518 ) )
F_83 ( V_518 , V_550 ) ;
else
F_83 ( V_518 , V_551 ) ;
break;
case V_529 :
F_217 ( V_518 , V_552 ) ;
if ( F_222 ( V_518 ) )
F_83 ( V_518 , V_553 ) ;
else
F_83 ( V_518 , V_554 ) ;
break;
case V_531 :
F_217 ( V_518 , V_555 ) ;
F_83 ( V_518 , V_533 ) ;
break;
case V_556 :
F_223 ( V_518 ) ;
break;
case V_557 :
V_548 = (struct V_547 * ) V_518 -> V_317 . V_558 ;
V_518 -> V_328 = V_548 -> V_559 ;
F_37 ( V_518 -> V_64 , V_548 -> V_560 . V_561 ) ;
F_37 ( V_518 -> V_64 , V_548 -> V_559 . V_561 ) ;
F_37 ( V_518 -> V_64 , V_548 -> V_560 . V_562 ) ;
F_37 ( V_518 -> V_64 , V_548 -> V_559 . V_562 ) ;
V_548 -> V_560 . V_561 =
F_45 ( V_548 -> V_560 . V_561 ) ;
V_548 -> V_559 . V_561 =
F_45 ( V_548 -> V_559 . V_561 ) ;
if ( V_548 -> V_560 . V_561 !=
V_548 -> V_559 . V_561 )
F_224 ( V_518 -> V_563 ,
V_548 -> V_560 ,
V_548 -> V_559 ) ;
if ( V_548 -> V_560 . V_562 !=
V_548 -> V_559 . V_562 )
F_225 ( V_518 -> V_563 ,
V_548 -> V_560 ,
V_548 -> V_559 ) ;
break;
default:
F_217 ( V_518 , V_564 ) ;
F_87 ( V_518 -> V_64 , V_25 ) ;
}
}
static void
V_550 ( struct V_143 * V_518 , enum V_519 V_25 )
{
F_37 ( V_518 -> V_64 , V_518 -> V_520 ) ;
F_37 ( V_518 -> V_64 , V_25 ) ;
switch ( V_25 ) {
case V_535 :
F_217 ( V_518 , V_565 ) ;
F_83 ( V_518 , V_546 ) ;
F_221 ( V_518 ) ;
break;
case V_529 :
F_217 ( V_518 , V_566 ) ;
F_83 ( V_518 , V_553 ) ;
break;
case V_531 :
F_217 ( V_518 , V_567 ) ;
F_83 ( V_518 , V_533 ) ;
F_221 ( V_518 ) ;
break;
default:
F_217 ( V_518 , V_568 ) ;
F_87 ( V_518 -> V_64 , V_25 ) ;
}
}
static void
V_551 ( struct V_143 * V_518 , enum V_519 V_25 )
{
F_37 ( V_518 -> V_64 , V_518 -> V_520 ) ;
F_37 ( V_518 -> V_64 , V_25 ) ;
switch ( V_25 ) {
case V_545 :
F_83 ( V_518 , V_550 ) ;
F_222 ( V_518 ) ;
break;
case V_529 :
F_217 ( V_518 , V_566 ) ;
F_83 ( V_518 , V_554 ) ;
break;
case V_531 :
F_217 ( V_518 , V_567 ) ;
F_83 ( V_518 , V_533 ) ;
F_76 ( & V_518 -> V_299 ) ;
F_221 ( V_518 ) ;
break;
default:
F_217 ( V_518 , V_568 ) ;
F_87 ( V_518 -> V_64 , V_25 ) ;
}
}
static void
V_546 ( struct V_143 * V_518 , enum V_519 V_25 )
{
F_37 ( V_518 -> V_64 , V_518 -> V_520 ) ;
F_37 ( V_518 -> V_64 , V_25 ) ;
switch ( V_25 ) {
case V_529 :
F_217 ( V_518 , V_569 ) ;
F_83 ( V_518 , F_216 ) ;
F_219 ( V_518 ) ;
break;
case V_525 :
F_217 ( V_518 , V_570 ) ;
if ( F_218 ( V_518 ) )
F_83 ( V_518 , V_527 ) ;
else
F_83 ( V_518 , V_528 ) ;
break;
case V_531 :
F_217 ( V_518 , V_571 ) ;
F_83 ( V_518 , V_533 ) ;
break;
default:
F_217 ( V_518 , V_572 ) ;
F_87 ( V_518 -> V_64 , V_25 ) ;
}
}
static void
V_553 ( struct V_143 * V_518 , enum V_519 V_25 )
{
F_37 ( V_518 -> V_64 , V_518 -> V_520 ) ;
F_37 ( V_518 -> V_64 , V_25 ) ;
switch ( V_25 ) {
case V_535 :
F_217 ( V_518 , V_573 ) ;
F_83 ( V_518 , F_216 ) ;
F_219 ( V_518 ) ;
break;
case V_531 :
F_217 ( V_518 , V_574 ) ;
F_83 ( V_518 , F_216 ) ;
F_219 ( V_518 ) ;
break;
default:
F_87 ( V_518 -> V_64 , V_25 ) ;
}
}
static void
V_554 ( struct V_143 * V_518 , enum V_519 V_25 )
{
F_37 ( V_518 -> V_64 , V_518 -> V_520 ) ;
F_37 ( V_518 -> V_64 , V_25 ) ;
switch ( V_25 ) {
case V_545 :
F_217 ( V_518 , V_573 ) ;
F_83 ( V_518 , V_553 ) ;
F_222 ( V_518 ) ;
break;
case V_531 :
F_217 ( V_518 , V_574 ) ;
F_83 ( V_518 , F_216 ) ;
F_76 ( & V_518 -> V_299 ) ;
F_219 ( V_518 ) ;
break;
default:
F_87 ( V_518 -> V_64 , V_25 ) ;
}
}
static void
V_539 ( struct V_143 * V_518 ,
enum V_519 V_25 )
{
F_37 ( V_518 -> V_64 , V_518 -> V_520 ) ;
F_37 ( V_518 -> V_64 , V_25 ) ;
switch ( V_25 ) {
case V_535 :
F_217 ( V_518 , V_575 ) ;
if ( F_222 ( V_518 ) )
F_83 ( V_518 , V_553 ) ;
else
F_83 ( V_518 , V_554 ) ;
break;
case V_531 :
F_217 ( V_518 , V_576 ) ;
F_83 ( V_518 , F_216 ) ;
F_219 ( V_518 ) ;
break;
default:
F_217 ( V_518 , V_577 ) ;
F_87 ( V_518 -> V_64 , V_25 ) ;
}
}
static void
V_542 ( struct V_143 * V_518 ,
enum V_519 V_25 )
{
F_37 ( V_518 -> V_64 , V_518 -> V_520 ) ;
F_37 ( V_518 -> V_64 , V_25 ) ;
switch ( V_25 ) {
case V_535 :
F_217 ( V_518 , V_578 ) ;
if ( F_222 ( V_518 ) )
F_83 ( V_518 , V_550 ) ;
else
F_83 ( V_518 , V_551 ) ;
break;
case V_529 :
F_217 ( V_518 , V_579 ) ;
F_83 ( V_518 , V_539 ) ;
break;
case V_531 :
F_217 ( V_518 , V_580 ) ;
F_83 ( V_518 , V_533 ) ;
break;
default:
F_217 ( V_518 , V_581 ) ;
F_87 ( V_518 -> V_64 , V_25 ) ;
}
}
static void
V_533 ( struct V_143 * V_518 , enum V_519 V_25 )
{
F_37 ( V_518 -> V_64 , V_518 -> V_520 ) ;
F_37 ( V_518 -> V_64 , V_25 ) ;
switch ( V_25 ) {
case V_540 :
F_217 ( V_518 , V_582 ) ;
F_221 ( V_518 ) ;
break;
case V_529 :
F_217 ( V_518 , V_583 ) ;
F_83 ( V_518 , F_216 ) ;
F_219 ( V_518 ) ;
break;
case V_525 :
F_217 ( V_518 , V_584 ) ;
if ( F_218 ( V_518 ) )
F_83 ( V_518 , V_527 ) ;
else
F_83 ( V_518 , V_528 ) ;
break;
case V_531 :
break;
default:
F_217 ( V_518 , V_585 ) ;
F_87 ( V_518 -> V_64 , V_25 ) ;
}
}
static void
F_226 ( void * V_119 , T_7 V_124 )
{
struct V_143 * V_518 = V_119 ;
if ( V_124 )
F_227 ( V_518 -> V_563 ) ;
}
static void
F_228 ( void * V_119 , T_7 V_124 )
{
struct V_143 * V_518 = V_119 ;
if ( V_124 )
F_229 ( V_518 -> V_563 ) ;
}
static void
F_230 ( void * V_119 )
{
struct V_143 * V_518 = V_119 ;
F_88 ( V_518 , V_545 ) ;
}
static void
F_231 ( struct V_59 * V_60 , struct V_61 * V_62 ,
struct V_63 * V_64 )
{
struct V_65 * V_586 = F_232 ( V_64 ) ;
if ( V_60 -> V_72 . V_587 < V_588 )
V_60 -> V_72 . V_587 = V_588 ;
F_24 ( V_62 , V_586 ,
V_60 -> V_72 . V_587 * sizeof( struct V_143 ) ) ;
}
static void
F_233 ( struct V_63 * V_64 , void * V_79 , struct V_59 * V_60 ,
struct V_80 * V_81 )
{
struct V_589 * V_44 = F_234 ( V_64 ) ;
struct V_143 * V_518 ;
T_2 V_35 ;
F_14 ( & V_44 -> V_590 ) ;
F_14 ( & V_44 -> V_591 ) ;
F_14 ( & V_44 -> V_592 ) ;
V_518 = (struct V_143 * ) F_13 ( V_44 ) ;
V_44 -> V_593 = V_518 ;
V_44 -> V_587 = V_60 -> V_72 . V_587 ;
F_5 ( ! V_44 -> V_587 ||
( V_44 -> V_587 & ( V_44 -> V_587 - 1 ) ) ) ;
for ( V_35 = 0 ; V_35 < V_44 -> V_587 ; V_35 ++ , V_518 ++ ) {
memset ( V_518 , 0 , sizeof( struct V_143 ) ) ;
V_518 -> V_64 = V_64 ;
V_518 -> V_520 = V_35 ;
F_83 ( V_518 , F_216 ) ;
if ( V_35 )
F_15 ( & V_518 -> V_54 , & V_44 -> V_590 ) ;
F_16 ( & V_518 -> V_299 , F_230 , V_518 ) ;
}
F_13 ( V_44 ) = ( V_37 * ) V_518 ;
}
static void
F_235 ( struct V_63 * V_64 )
{
}
static void
F_236 ( struct V_63 * V_64 )
{
}
static void
F_237 ( struct V_63 * V_64 )
{
}
static void
F_238 ( struct V_63 * V_64 )
{
struct V_589 * V_44 = F_234 ( V_64 ) ;
struct V_143 * V_144 ;
struct V_85 * V_54 , * V_86 ;
F_30 ( & V_44 -> V_592 , & V_44 -> V_590 ) ;
F_31 (qe, qen, &mod->rp_active_q) {
V_144 = (struct V_143 * ) V_54 ;
F_88 ( V_144 , V_531 ) ;
}
}
static struct V_143 *
F_239 ( struct V_589 * V_44 )
{
struct V_143 * V_144 ;
F_35 ( & V_44 -> V_590 , & V_144 ) ;
if ( V_144 )
F_15 ( & V_144 -> V_54 , & V_44 -> V_591 ) ;
return V_144 ;
}
static void
F_219 ( struct V_143 * V_144 )
{
struct V_589 * V_44 = F_234 ( V_144 -> V_64 ) ;
F_5 ( ! F_40 ( & V_44 -> V_591 , V_144 ) ) ;
F_41 ( & V_144 -> V_54 ) ;
F_15 ( & V_144 -> V_54 , & V_44 -> V_590 ) ;
}
static T_7
F_218 ( struct V_143 * V_518 )
{
struct V_594 * V_245 ;
V_245 = F_51 ( V_518 -> V_64 , V_595 ) ;
if ( ! V_245 ) {
F_70 ( V_518 -> V_64 , V_595 , & V_518 -> V_299 ) ;
return V_58 ;
}
F_53 ( V_245 -> V_146 , V_596 , V_597 ,
F_54 ( V_518 -> V_64 ) ) ;
V_245 -> V_598 = V_518 -> V_520 ;
V_245 -> V_151 = F_55 ( V_518 -> V_152 . V_151 ) ;
V_245 -> V_265 = V_518 -> V_152 . V_265 ;
V_245 -> V_155 = F_56 ( V_518 -> V_64 , ( V_37 ) V_518 -> V_152 . V_156 ) ;
V_245 -> V_599 = V_518 -> V_152 . V_599 ;
V_245 -> V_600 = V_518 -> V_152 . V_600 ;
V_245 -> V_601 = V_518 -> V_152 . V_601 ;
V_245 -> V_154 = V_518 -> V_152 . V_154 ;
V_245 -> V_602 = V_518 -> V_152 . V_602 ;
F_61 ( V_518 -> V_64 , V_595 , V_245 -> V_146 ) ;
return V_169 ;
}
static T_7
F_222 ( struct V_143 * V_518 )
{
struct V_603 * V_245 ;
V_245 = F_51 ( V_518 -> V_64 , V_595 ) ;
if ( ! V_245 ) {
F_70 ( V_518 -> V_64 , V_595 , & V_518 -> V_299 ) ;
return V_58 ;
}
F_53 ( V_245 -> V_146 , V_596 , V_604 ,
F_54 ( V_518 -> V_64 ) ) ;
V_245 -> V_150 = V_518 -> V_150 ;
F_61 ( V_518 -> V_64 , V_595 , V_245 -> V_146 ) ;
return V_169 ;
}
static T_7
F_223 ( struct V_143 * V_518 )
{
struct V_605 * V_245 ;
V_245 = F_51 ( V_518 -> V_64 , V_595 ) ;
if ( ! V_245 ) {
F_37 ( V_518 -> V_64 , V_518 -> V_152 . V_367 ) ;
return V_58 ;
}
F_53 ( V_245 -> V_146 , V_596 , V_606 ,
F_54 ( V_518 -> V_64 ) ) ;
V_245 -> V_150 = V_518 -> V_150 ;
V_245 -> V_367 = ( V_37 ) V_518 -> V_152 . V_367 ;
F_61 ( V_518 -> V_64 , V_595 , V_245 -> V_146 ) ;
return V_169 ;
}
void
F_240 ( struct V_63 * V_64 , struct V_170 * V_245 )
{
union V_607 V_171 ;
struct V_143 * V_518 ;
F_37 ( V_64 , V_245 -> V_172 . V_173 ) ;
V_171 . V_171 = V_245 ;
switch ( V_245 -> V_172 . V_173 ) {
case V_608 :
V_518 = F_241 ( V_64 , V_171 . V_609 -> V_598 ) ;
V_518 -> V_150 = V_171 . V_609 -> V_150 ;
V_518 -> V_328 = V_171 . V_609 -> V_328 ;
F_242 ( V_64 , V_518 ) ;
F_5 ( V_171 . V_609 -> V_192 != V_128 ) ;
F_88 ( V_518 , V_535 ) ;
break;
case V_610 :
V_518 = F_241 ( V_64 , V_171 . V_611 -> V_598 ) ;
F_5 ( V_171 . V_611 -> V_192 != V_128 ) ;
F_243 ( V_64 , V_518 ) ;
F_88 ( V_518 , V_535 ) ;
break;
case V_612 :
V_518 = F_241 ( V_64 , V_171 . V_613 -> V_598 ) ;
V_518 -> V_317 . V_558 = V_171 . V_613 ;
F_88 ( V_518 , V_557 ) ;
break;
default:
F_37 ( V_64 , V_245 -> V_172 . V_173 ) ;
F_5 ( 1 ) ;
}
}
void
F_244 ( struct V_63 * V_64 , T_2 V_614 )
{
struct V_589 * V_44 = F_234 ( V_64 ) ;
struct V_85 * V_54 ;
int V_35 ;
for ( V_35 = 0 ; V_35 < ( V_44 -> V_587 - V_614 ) ; V_35 ++ ) {
F_80 ( & V_44 -> V_590 , & V_54 ) ;
F_15 ( V_54 , & V_44 -> V_592 ) ;
}
}
struct V_143 *
F_245 ( struct V_63 * V_64 , void * V_563 )
{
struct V_143 * V_518 ;
V_518 = F_239 ( F_234 ( V_64 ) ) ;
if ( V_518 == NULL )
return NULL ;
V_518 -> V_64 = V_64 ;
V_518 -> V_563 = V_563 ;
memset ( & V_518 -> V_360 , 0 , sizeof( V_518 -> V_360 ) ) ;
F_5 ( ! F_213 ( V_518 , F_216 ) ) ;
F_88 ( V_518 , V_521 ) ;
return V_518 ;
}
void
F_246 ( struct V_143 * V_144 , struct V_615 * V_152 )
{
F_5 ( V_152 -> V_151 == 0 ) ;
if ( V_152 -> V_151 == 0 ) {
F_37 ( V_144 -> V_64 , V_144 -> V_520 ) ;
V_152 -> V_151 = V_492 ;
}
V_144 -> V_152 = * V_152 ;
F_88 ( V_144 , V_525 ) ;
}
void
F_247 ( struct V_143 * V_144 , enum V_476 V_367 )
{
F_5 ( V_367 == 0 ) ;
F_5 ( V_367 == V_368 ) ;
V_144 -> V_152 . V_367 = V_367 ;
F_88 ( V_144 , V_556 ) ;
}
void
F_242 ( struct V_63 * V_64 , struct V_143 * V_518 )
{
struct V_206 * V_616 = F_96 ( V_64 ) ;
T_10 V_617 , V_618 ;
V_37 V_156 = ( V_37 ) V_518 -> V_152 . V_156 ;
V_618 = ( (struct V_619 * ) V_518 -> V_563 ) -> V_251 ;
V_617 = ( F_102 ( V_616 , V_518 -> V_152 . V_156 ) ) -> V_251 ;
F_102 ( V_616 , V_518 -> V_152 . V_156 ) -> V_620 =
V_518 -> V_620 = V_169 ;
F_248 ( V_64 , V_617 , V_618 , V_518 -> V_520 , V_156 ) ;
}
void
F_243 ( struct V_63 * V_64 , struct V_143 * V_518 )
{
struct V_206 * V_616 = F_96 ( V_64 ) ;
T_10 V_617 , V_618 ;
V_618 = ( (struct V_619 * ) V_518 -> V_563 ) -> V_251 ;
V_617 = ( F_102 ( V_616 , V_518 -> V_152 . V_156 ) ) -> V_251 ;
F_102 ( V_616 , V_518 -> V_152 . V_156 ) -> V_620 =
V_518 -> V_620 = V_58 ;
F_248 ( V_64 , V_617 , V_618 ,
V_621 , V_622 ) ;
}
static void
F_249 ( struct V_59 * V_60 , struct V_61 * V_62 ,
struct V_63 * V_64 )
{
struct V_623 * V_624 = F_250 ( V_64 ) ;
struct V_65 * V_625 = F_251 ( V_64 ) ;
struct V_67 * V_68 ;
T_2 V_69 , V_70 , V_626 , V_627 ;
T_3 V_628 = sizeof( struct V_629 ) ;
if ( V_60 -> V_75 . V_630 < V_631 )
V_60 -> V_75 . V_630 = V_631 ;
else if ( V_60 -> V_75 . V_630 > V_632 )
V_60 -> V_75 . V_630 = V_632 ;
V_627 = V_60 -> V_75 . V_630 ;
V_69 = F_20 ( V_627 , V_628 ) ;
V_626 = F_21 ( V_628 ) ;
F_22 (sgpg_mod, seg_ptr, nsegs, idx) {
if ( V_627 >= V_626 ) {
V_627 -= V_626 ;
F_23 ( V_62 , V_68 ,
V_626 * V_628 ) ;
} else
F_23 ( V_62 , V_68 ,
V_627 * V_628 ) ;
}
F_24 ( V_62 , V_625 ,
V_60 -> V_75 . V_630 * sizeof( struct V_633 ) ) ;
}
static void
F_252 ( struct V_63 * V_64 , void * V_79 , struct V_59 * V_60 ,
struct V_80 * V_81 )
{
struct V_623 * V_44 = F_250 ( V_64 ) ;
struct V_633 * V_634 ;
struct V_629 * V_635 ;
T_1 V_636 ;
struct V_67 * V_68 ;
T_3 V_628 = sizeof( struct V_629 ) ;
T_2 V_35 , V_70 , V_69 , V_626 , V_627 ;
union {
T_1 V_637 ;
union V_638 V_639 ;
} V_640 , V_641 ;
F_14 ( & V_44 -> V_642 ) ;
F_14 ( & V_44 -> V_643 ) ;
F_37 ( V_64 , V_60 -> V_75 . V_630 ) ;
V_44 -> V_644 = V_44 -> V_630 = V_60 -> V_75 . V_630 ;
V_627 = V_60 -> V_75 . V_630 ;
V_69 = F_20 ( V_627 , V_628 ) ;
V_634 = (struct V_633 * ) F_13 ( V_44 ) ;
F_22 (mod, seg_ptr, nsegs, idx) {
if ( ! F_148 ( V_68 ) )
break;
V_636 = F_253 ( F_149 ( V_68 ) ) -
F_149 ( V_68 ) ;
V_635 = (struct V_629 * )
( ( ( V_37 * ) F_148 ( V_68 ) ) + V_636 ) ;
V_640 . V_637 = F_149 ( V_68 ) + V_636 ;
F_5 ( V_640 . V_637 & ( V_628 - 1 ) ) ;
V_626 = ( V_68 -> V_645 - ( T_3 ) V_636 ) / V_628 ;
for ( V_35 = 0 ; V_627 > 0 && V_35 < V_626 ; V_35 ++ , V_627 -- ) {
memset ( V_634 , 0 , sizeof( * V_634 ) ) ;
memset ( V_635 , 0 , sizeof( * V_635 ) ) ;
V_634 -> V_635 = V_635 ;
V_641 . V_637 = F_254 ( V_640 . V_637 ) ;
V_634 -> V_640 = V_641 . V_639 ;
F_15 ( & V_634 -> V_54 , & V_44 -> V_642 ) ;
V_635 ++ ;
V_634 ++ ;
V_640 . V_637 += V_628 ;
}
}
F_13 ( V_44 ) = ( V_37 * ) V_634 ;
}
static void
F_255 ( struct V_63 * V_64 )
{
}
static void
F_256 ( struct V_63 * V_64 )
{
}
static void
F_257 ( struct V_63 * V_64 )
{
}
static void
F_258 ( struct V_63 * V_64 )
{
}
T_6
F_259 ( struct V_63 * V_64 , struct V_85 * V_642 , int V_646 )
{
struct V_623 * V_44 = F_250 ( V_64 ) ;
struct V_633 * V_634 ;
int V_35 ;
if ( V_44 -> V_644 < V_646 )
return V_647 ;
for ( V_35 = 0 ; V_35 < V_646 ; V_35 ++ ) {
F_35 ( & V_44 -> V_642 , & V_634 ) ;
F_5 ( ! V_634 ) ;
F_15 ( & V_634 -> V_54 , V_642 ) ;
}
V_44 -> V_644 -= V_646 ;
return V_128 ;
}
void
F_260 ( struct V_63 * V_64 , struct V_85 * V_642 , int V_648 )
{
struct V_623 * V_44 = F_250 ( V_64 ) ;
struct V_649 * V_115 ;
V_44 -> V_644 += V_648 ;
F_5 ( V_44 -> V_644 > V_44 -> V_630 ) ;
F_30 ( V_642 , & V_44 -> V_642 ) ;
if ( F_73 ( & V_44 -> V_643 ) )
return;
do {
V_115 = F_261 ( & V_44 -> V_643 ) ;
if ( V_44 -> V_644 < V_115 -> V_648 )
V_648 = V_44 -> V_644 ;
else
V_648 = V_115 -> V_648 ;
F_259 ( V_64 , & V_115 -> V_642 , V_648 ) ;
V_115 -> V_648 -= V_648 ;
if ( V_115 -> V_648 == 0 ) {
F_41 ( & V_115 -> V_54 ) ;
V_115 -> V_168 ( V_115 -> V_119 ) ;
}
} while ( V_44 -> V_644 && ! F_73 ( & V_44 -> V_643 ) );
}
void
F_262 ( struct V_63 * V_64 , struct V_649 * V_115 , int V_648 )
{
struct V_623 * V_44 = F_250 ( V_64 ) ;
F_5 ( V_648 <= 0 ) ;
F_5 ( V_648 <= V_44 -> V_644 ) ;
V_115 -> V_650 = V_115 -> V_648 = V_648 ;
if ( V_44 -> V_644 ) {
F_5 ( ! F_73 ( & V_44 -> V_643 ) ) ;
F_30 ( & V_44 -> V_642 , & V_115 -> V_642 ) ;
V_115 -> V_648 -= V_44 -> V_644 ;
V_44 -> V_644 = 0 ;
}
F_15 ( & V_115 -> V_54 , & V_44 -> V_643 ) ;
}
void
F_263 ( struct V_63 * V_64 , struct V_649 * V_115 )
{
struct V_623 * V_44 = F_250 ( V_64 ) ;
F_5 ( ! F_40 ( & V_44 -> V_643 , V_115 ) ) ;
F_41 ( & V_115 -> V_54 ) ;
if ( V_115 -> V_650 != V_115 -> V_648 )
F_260 ( V_64 , & V_115 -> V_642 ,
V_115 -> V_650 - V_115 -> V_648 ) ;
}
void
F_264 ( struct V_649 * V_115 , void (* V_168) ( void * V_119 ) ,
void * V_119 )
{
F_14 ( & V_115 -> V_642 ) ;
V_115 -> V_168 = V_168 ;
V_115 -> V_119 = V_119 ;
}
static void
F_265 ( void * V_119 , T_7 V_124 )
{
struct V_651 * V_652 = V_119 ;
struct V_653 * V_654 = F_266 ( V_652 -> V_64 ) ;
if ( V_124 )
V_654 -> V_655 ( V_654 -> V_119 , V_652 ) ;
}
static void
F_267 ( struct V_653 * V_654 )
{
struct V_656 * V_657 ;
T_2 V_35 ;
T_2 V_658 ;
V_654 -> V_659 = (struct V_656 * ) F_13 ( V_654 ) ;
V_657 = V_654 -> V_659 ;
for ( V_35 = 0 , V_657 = V_654 -> V_659 ; V_35 < V_654 -> V_660 ;
V_35 ++ , V_657 ++ ) {
memset ( V_657 , 0 , sizeof( struct V_656 ) ) ;
V_657 -> V_661 = V_35 ;
V_658 = sizeof( struct V_662 ) ;
V_657 -> V_658 = F_55 ( V_658 ) ;
F_53 ( V_657 -> V_146 , V_663 , V_664 ,
F_54 ( V_654 -> V_64 ) ) ;
F_58 ( & V_657 -> V_665 , V_658 , F_268 ( V_654 , V_35 ) ) ;
}
F_13 ( V_654 ) = ( V_37 * ) V_657 ;
}
static void
F_269 ( struct V_653 * V_654 )
{
T_2 V_35 ;
struct V_651 * V_652 ;
V_654 -> V_666 = (struct V_651 * ) F_13 ( V_654 ) ;
for ( V_35 = 0 , V_652 = V_654 -> V_666 ; V_35 < V_654 -> V_660 ; V_35 ++ , V_652 ++ ) {
memset ( V_652 , 0 , sizeof( struct V_651 ) ) ;
V_652 -> V_64 = V_654 -> V_64 ;
V_652 -> V_667 = V_35 ;
V_652 -> V_668 = V_669 ;
V_652 -> V_670 = F_66 ( V_654 , V_35 , V_669 ) ;
V_652 -> V_671 = F_268 ( V_654 , V_35 ) ;
F_15 ( & V_652 -> V_54 , & V_654 -> V_672 ) ;
}
F_13 ( V_654 ) = ( V_37 * ) V_652 ;
}
static void
F_270 ( struct V_653 * V_654 )
{
F_269 ( V_654 ) ;
F_267 ( V_654 ) ;
}
static void
F_271 ( struct V_59 * V_60 , struct V_61 * V_62 ,
struct V_63 * V_64 )
{
struct V_653 * V_654 = F_266 ( V_64 ) ;
struct V_65 * V_673 = F_272 ( V_64 ) ;
T_3 V_660 = V_60 -> V_72 . V_674 ;
struct V_67 * V_68 ;
T_2 V_69 , V_70 , V_675 = 0 ;
V_69 = F_20 ( V_660 , V_669 ) ;
V_675 = F_21 ( V_669 ) ;
F_22 (ufm, seg_ptr, nsegs, idx) {
if ( V_660 >= V_675 ) {
V_660 -= V_675 ;
F_23 ( V_62 , V_68 ,
V_675 * V_669 ) ;
} else
F_23 ( V_62 , V_68 ,
V_660 * V_669 ) ;
}
F_24 ( V_62 , V_673 , V_60 -> V_72 . V_674 *
( sizeof( struct V_651 ) + sizeof( struct V_656 ) ) ) ;
}
static void
F_273 ( struct V_63 * V_64 , void * V_79 , struct V_59 * V_60 ,
struct V_80 * V_81 )
{
struct V_653 * V_654 = F_266 ( V_64 ) ;
V_654 -> V_64 = V_64 ;
V_654 -> V_660 = V_60 -> V_72 . V_674 ;
F_14 ( & V_654 -> V_672 ) ;
F_14 ( & V_654 -> V_676 ) ;
F_14 ( & V_654 -> V_677 ) ;
F_270 ( V_654 ) ;
}
static void
F_274 ( struct V_63 * V_64 )
{
}
static struct V_651 *
F_275 ( struct V_653 * V_678 )
{
struct V_651 * V_652 ;
F_35 ( & V_678 -> V_672 , & V_652 ) ;
return V_652 ;
}
static void
F_276 ( struct V_653 * V_678 , struct V_651 * V_652 )
{
F_15 ( & V_652 -> V_54 , & V_678 -> V_672 ) ;
}
static T_6
F_277 ( struct V_653 * V_654 , struct V_651 * V_652 )
{
struct V_656 * V_679 ;
V_679 = F_51 ( V_654 -> V_64 , V_136 ) ;
if ( ! V_679 )
return V_680 ;
memcpy ( V_679 , & V_654 -> V_659 [ V_652 -> V_667 ] ,
sizeof( struct V_656 ) ) ;
F_61 ( V_654 -> V_64 , V_136 , V_679 -> V_146 ) ;
F_37 ( V_654 -> V_64 , V_652 -> V_667 ) ;
F_15 ( & V_652 -> V_54 , & V_654 -> V_676 ) ;
return V_128 ;
}
static void
F_278 ( struct V_653 * V_678 )
{
struct V_651 * V_652 ;
while ( ( V_652 = F_275 ( V_678 ) ) != NULL ) {
if ( F_277 ( V_678 , V_652 ) != V_128 )
break;
}
}
static void
F_279 ( struct V_63 * V_64 , struct V_681 * V_245 )
{
struct V_653 * V_654 = F_266 ( V_64 ) ;
T_2 V_667 = V_245 -> V_661 ;
struct V_651 * V_652 = & V_654 -> V_666 [ V_667 ] ;
struct V_662 * V_682 ;
T_11 * V_683 ;
struct V_38 * V_129 ;
V_682 = (struct V_662 * )
F_66 ( V_654 , V_667 , V_652 -> V_668 ) ;
V_683 = & V_682 -> V_401 [ 0 ] ;
V_245 -> V_684 = F_44 ( V_245 -> V_684 ) ;
V_245 -> V_685 = F_44 ( V_245 -> V_685 ) ;
V_129 = (struct V_38 * ) V_682 ;
F_41 ( & V_652 -> V_54 ) ;
V_652 -> V_686 = V_683 ;
V_652 -> V_687 = V_245 -> V_685 ;
F_5 ( V_652 -> V_687 < sizeof( struct V_38 ) ) ;
if ( V_652 -> V_687 == sizeof( struct V_38 ) ) {
F_10 ( V_64 -> V_13 , V_688 , V_133 ,
V_652 -> V_687 , (struct V_38 * ) V_683 ) ;
} else {
T_3 V_42 = * ( ( T_3 * ) ( V_683 + sizeof( struct V_38 ) ) ) ;
F_11 ( V_64 -> V_13 , V_688 ,
V_133 , V_652 -> V_687 ,
(struct V_38 * ) V_683 , V_42 ) ;
}
if ( V_64 -> V_260 )
F_265 ( V_652 , V_169 ) ;
else
F_33 ( V_64 , & V_652 -> V_92 , F_265 , V_652 ) ;
}
static void
F_280 ( struct V_63 * V_64 )
{
}
static void
F_281 ( struct V_63 * V_64 )
{
struct V_653 * V_654 = F_266 ( V_64 ) ;
struct V_651 * V_652 ;
struct V_85 * V_54 , * V_86 ;
F_30 ( & V_654 -> V_677 , & V_654 -> V_672 ) ;
F_31 (qe, qen, &ufm->uf_posted_q) {
V_652 = (struct V_651 * ) V_54 ;
F_41 ( & V_652 -> V_54 ) ;
F_276 ( V_654 , V_652 ) ;
}
}
static void
F_282 ( struct V_63 * V_64 )
{
F_278 ( F_266 ( V_64 ) ) ;
}
void
F_283 ( struct V_63 * V_64 , T_14 V_655 , void * V_119 )
{
struct V_653 * V_654 = F_266 ( V_64 ) ;
V_654 -> V_655 = V_655 ;
V_654 -> V_119 = V_119 ;
}
void
F_284 ( struct V_651 * V_652 )
{
F_276 ( F_266 ( V_652 -> V_64 ) , V_652 ) ;
F_278 ( F_266 ( V_652 -> V_64 ) ) ;
}
void
F_285 ( struct V_63 * V_64 , struct V_170 * V_171 )
{
F_37 ( V_64 , V_171 -> V_172 . V_173 ) ;
switch ( V_171 -> V_172 . V_173 ) {
case V_689 :
F_279 ( V_64 , (struct V_681 * ) V_171 ) ;
break;
default:
F_37 ( V_64 , V_171 -> V_172 . V_173 ) ;
F_5 ( 1 ) ;
}
}
void
F_286 ( struct V_63 * V_64 , T_2 V_690 )
{
struct V_653 * V_44 = F_266 ( V_64 ) ;
struct V_85 * V_54 ;
int V_35 ;
for ( V_35 = 0 ; V_35 < ( V_44 -> V_660 - V_690 ) ; V_35 ++ ) {
F_80 ( & V_44 -> V_672 , & V_54 ) ;
F_15 ( V_54 , & V_44 -> V_677 ) ;
}
}
static void
F_287 ( struct V_691 * V_692 )
{
struct V_274 * V_275 = F_151 ( V_692 -> V_64 ) ;
if ( V_692 -> V_693 . V_694 )
V_275 -> V_467 = V_169 ;
else
V_275 -> V_467 = V_58 ;
}
static void
F_288 ( struct V_59 * V_60 , struct V_61 * V_695 ,
struct V_63 * V_64 )
{
}
static void
F_289 ( struct V_63 * V_64 , void * V_79 , struct V_59 * V_60 ,
struct V_80 * V_81 )
{
struct V_691 * V_692 = F_290 ( V_64 ) ;
V_692 -> V_64 = V_64 ;
V_692 -> V_696 = V_64 -> V_696 ;
}
static void
F_291 ( struct V_63 * V_64 )
{
struct V_691 * V_692 = F_290 ( V_64 ) ;
F_37 ( V_692 , V_692 -> V_693 . V_694 ) ;
if ( V_692 -> V_693 . V_694 ) {
V_692 -> V_693 . V_192 = V_90 ;
V_692 -> V_693 . V_168 ( V_692 -> V_693 . V_119 , V_692 -> V_693 . V_192 ) ;
V_692 -> V_693 . V_694 = 0 ;
F_287 ( V_692 ) ;
}
}
static void
F_292 ( struct V_63 * V_64 )
{
}
static void
F_293 ( struct V_63 * V_64 )
{
}
static void
F_294 ( struct V_63 * V_64 )
{
}
static void
F_295 ( void * V_119 )
{
struct V_691 * V_692 = V_119 ;
struct V_697 * V_698 = V_692 -> V_699 . V_700 ;
F_37 ( V_692 , V_692 -> V_699 . V_701 ) ;
F_37 ( V_692 , V_692 -> V_699 . V_238 ) ;
V_692 -> V_699 . V_702 = 0 ;
V_698 -> V_192 = V_416 ;
V_698 -> V_238 = V_703 - V_692 -> V_699 . V_238 ;
if ( V_692 -> V_699 . V_701 )
V_698 -> V_704 = V_692 -> V_699 . V_701 ;
F_37 ( V_692 , V_416 ) ;
V_692 -> V_699 . V_192 = V_416 ;
V_692 -> V_699 . V_168 ( V_692 -> V_699 . V_119 , V_692 -> V_699 . V_192 ) ;
V_692 -> V_699 . V_694 = 0 ;
}
static T_6
F_296 ( struct V_691 * V_692 )
{
T_3 V_35 ;
struct V_705 * V_706 ;
V_706 = F_51 ( V_692 -> V_64 , V_692 -> V_699 . V_704 ) ;
if ( ! V_706 )
return V_512 ;
F_53 ( V_706 -> V_146 , V_707 , V_708 ,
F_54 ( V_692 -> V_64 ) ) ;
for ( V_35 = 0 ; V_35 < V_709 ; V_35 ++ )
V_706 -> V_410 [ V_35 ] = V_710 ;
F_37 ( V_692 , V_692 -> V_699 . V_704 ) ;
F_61 ( V_692 -> V_64 , V_692 -> V_699 . V_704 , V_706 -> V_146 ) ;
return V_128 ;
}
static void
F_297 ( struct V_691 * V_692 ,
T_15 * V_215 )
{
struct V_697 * V_698 = V_692 -> V_699 . V_700 ;
T_6 V_192 = V_128 ;
int V_35 ;
if ( ! V_692 -> V_699 . V_702 ) {
F_37 ( V_692 , V_692 -> V_699 . V_702 ) ;
return;
}
V_692 -> V_699 . V_238 -- ;
for ( V_35 = 0 ; V_35 < V_709 ; V_35 ++ ) {
if ( V_215 -> V_410 [ V_35 ] != ~ ( V_710 ) ) {
V_698 -> V_192 = V_711 ;
break;
}
}
if ( V_698 -> V_192 == V_128 ) {
if ( V_692 -> V_699 . V_238 > 0 ) {
V_192 = F_296 ( V_692 ) ;
if ( V_192 == V_128 )
return;
else
V_698 -> V_192 = V_192 ;
} else if ( V_692 -> V_699 . V_701 > 0 &&
V_692 -> V_699 . V_704 < ( V_712 - 1 ) ) {
V_692 -> V_699 . V_238 = V_703 ;
V_692 -> V_699 . V_704 ++ ;
V_192 = F_296 ( V_692 ) ;
if ( V_192 == V_128 )
return;
else
V_698 -> V_192 = V_192 ;
}
}
if ( V_692 -> V_699 . V_702 ) {
F_178 ( & V_692 -> V_699 . V_460 ) ;
V_692 -> V_699 . V_702 = 0 ;
}
V_698 -> V_704 = V_692 -> V_699 . V_704 ;
V_698 -> V_238 = V_703 - V_692 -> V_699 . V_238 ;
F_37 ( V_692 , V_698 -> V_238 ) ;
F_37 ( V_692 , V_698 -> V_192 ) ;
V_692 -> V_699 . V_192 = V_698 -> V_192 ;
V_692 -> V_699 . V_168 ( V_692 -> V_699 . V_119 , V_692 -> V_699 . V_192 ) ;
V_692 -> V_699 . V_694 = 0 ;
}
static void
F_298 ( struct V_691 * V_692 ,
struct V_713 * V_215 )
{
struct V_714 * V_698 = V_692 -> V_693 . V_700 ;
V_698 -> V_715 = F_45 ( V_215 -> V_698 . V_715 ) ;
V_698 -> V_716 = F_45 ( V_215 -> V_698 . V_716 ) ;
V_698 -> V_717 = F_45 ( V_215 -> V_698 . V_717 ) ;
V_698 -> V_718 = F_45 ( V_215 -> V_698 . V_718 ) ;
V_698 -> V_719 = F_45 ( V_215 -> V_698 . V_719 ) ;
V_698 -> V_192 = V_215 -> V_698 . V_192 ;
V_692 -> V_693 . V_192 = V_215 -> V_698 . V_192 ;
F_37 ( V_692 , V_692 -> V_693 . V_192 ) ;
V_692 -> V_693 . V_168 ( V_692 -> V_693 . V_119 , V_692 -> V_693 . V_192 ) ;
V_692 -> V_693 . V_694 = 0 ;
F_287 ( V_692 ) ;
}
static T_6
F_299 ( struct V_691 * V_692 ,
struct V_720 * V_721 )
{
struct V_722 * V_723 ;
V_723 = F_51 ( V_692 -> V_64 , V_724 ) ;
if ( ! V_723 )
return V_512 ;
F_53 ( V_723 -> V_146 , V_707 , V_725 ,
F_54 ( V_692 -> V_64 ) ) ;
V_723 -> V_726 = V_721 -> V_726 ;
V_723 -> V_367 = V_721 -> V_367 ;
V_723 -> V_727 = V_721 -> V_727 ;
V_723 -> V_728 = V_721 -> V_728 ;
F_61 ( V_692 -> V_64 , V_724 , V_723 -> V_146 ) ;
F_37 ( V_692 , V_721 -> V_726 ) ;
F_37 ( V_692 , V_721 -> V_367 ) ;
F_37 ( V_692 , V_721 -> V_727 ) ;
F_37 ( V_692 , V_721 -> V_728 ) ;
return V_128 ;
}
void
F_300 ( struct V_63 * V_64 , struct V_170 * V_171 )
{
struct V_691 * V_692 = F_290 ( V_64 ) ;
switch ( V_171 -> V_172 . V_173 ) {
case V_729 :
F_298 ( V_692 ,
(struct V_713 * ) V_171 ) ;
break;
case V_730 :
F_297 ( V_692 , ( T_15 * ) V_171 ) ;
break;
default:
F_37 ( V_692 , V_171 -> V_172 . V_173 ) ;
F_5 ( 1 ) ;
}
}
T_6
F_301 ( struct V_63 * V_64 , enum V_731 V_732 ,
enum V_476 V_367 , T_3 V_733 , T_3 V_734 ,
struct V_714 * V_700 , T_16 V_168 ,
void * V_119 )
{
struct V_720 V_721 ;
struct V_495 V_378 ;
T_6 V_192 ;
struct V_691 * V_692 = F_290 ( V_64 ) ;
if ( ! F_302 ( V_64 ) )
return V_735 ;
if ( F_175 ( V_64 ) ) {
F_37 ( V_692 , V_465 ) ;
return V_465 ;
}
if ( F_207 ( V_64 ) == V_58 ) {
F_37 ( V_692 , V_732 ) ;
return V_736 ;
}
if ( F_185 ( & V_64 -> V_261 ) == V_480 ) {
if ( ! ( V_367 == V_371 ||
V_367 == V_482 ||
V_367 == V_483 ||
V_367 == V_484 ||
V_367 == V_485 ||
V_367 == V_368 ) ) {
F_37 ( V_692 , V_367 ) ;
return V_478 ;
}
F_199 ( V_64 , & V_378 ) ;
F_37 ( V_692 , V_378 . V_501 ) ;
if ( V_367 > V_378 . V_501 )
return V_478 ;
} else {
if ( V_367 != V_486 ) {
F_37 ( V_692 , V_367 ) ;
return V_478 ;
}
}
if ( F_184 ( V_64 -> V_261 . V_378 -> V_479 ) ) {
if ( F_185 ( & V_64 -> V_261 ) == V_480 ) {
if ( ( V_367 == V_371 ) &&
( F_186 ( V_64 -> V_261 . V_81 . V_481 ) ) )
return V_478 ;
if ( ! ( V_367 == V_371 ||
V_367 == V_482 ||
V_367 == V_483 ||
V_367 == V_484 ||
V_367 == V_485 ||
V_367 == V_368 ) )
return V_478 ;
} else {
if ( V_367 != V_486 )
return V_478 ;
}
}
if ( V_692 -> V_693 . V_694 ) {
F_37 ( V_692 , V_692 -> V_693 . V_694 ) ;
return V_512 ;
}
V_692 -> V_693 . V_694 = 1 ;
V_721 . V_726 = V_732 ;
V_721 . V_367 = V_367 ;
V_721 . V_727 = V_733 ;
V_721 . V_728 = V_734 ;
V_692 -> V_693 . V_700 = V_700 ;
V_692 -> V_693 . V_168 = V_168 ;
V_692 -> V_693 . V_119 = V_119 ;
memset ( V_700 , 0 , sizeof( struct V_714 ) ) ;
F_287 ( V_692 ) ;
V_192 = F_299 ( V_692 , & V_721 ) ;
return V_192 ;
}
T_6
F_303 ( struct V_63 * V_64 , T_3 V_737 , T_3 V_704 ,
struct V_697 * V_700 , T_16 V_168 ,
void * V_119 )
{
struct V_691 * V_692 = F_290 ( V_64 ) ;
T_6 V_192 ;
F_37 ( V_692 , V_737 ) ;
F_37 ( V_692 , V_704 ) ;
if ( ! V_737 && ! F_302 ( V_64 ) )
return V_735 ;
if ( V_692 -> V_699 . V_694 ) {
F_37 ( V_692 , V_692 -> V_699 . V_694 ) ;
return V_512 ;
}
V_692 -> V_699 . V_694 = 1 ;
V_692 -> V_699 . V_168 = V_168 ;
V_692 -> V_699 . V_119 = V_119 ;
V_692 -> V_699 . V_700 = V_700 ;
V_692 -> V_699 . V_238 = V_703 ;
V_692 -> V_699 . V_700 -> V_192 = V_128 ;
V_692 -> V_699 . V_700 -> V_238 = 0 ;
if ( V_704 < V_712 ) {
V_692 -> V_699 . V_700 -> V_704 = ( V_37 ) V_704 ;
V_692 -> V_699 . V_704 = ( V_37 ) V_704 ;
V_692 -> V_699 . V_701 = 0 ;
} else {
V_692 -> V_699 . V_700 -> V_704 = 0 ;
V_692 -> V_699 . V_704 = 0 ;
V_692 -> V_699 . V_701 = 1 ;
}
V_192 = F_296 ( V_692 ) ;
if ( V_192 == V_128 ) {
F_205 ( V_64 , & V_692 -> V_699 . V_460 ,
F_295 , V_692 ,
V_738 ) ;
V_692 -> V_699 . V_702 = 1 ;
}
return V_192 ;
}
T_6
F_304 ( struct V_63 * V_64 )
{
struct V_691 * V_692 = F_290 ( V_64 ) ;
return V_692 -> V_693 . V_694 ? V_468 : V_128 ;
}
