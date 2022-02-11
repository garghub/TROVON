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
F_84 ( V_177 ) ;
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
if ( V_215 -> V_235 )
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
F_159 ( struct V_396 * V_397 ,
struct V_396 * V_398 )
{
T_3 * V_399 = ( T_3 * ) V_397 ;
T_13 * V_400 = ( T_13 * ) V_398 ;
int V_35 ;
for ( V_35 = 0 ; V_35 < ( sizeof( struct V_396 ) / sizeof( T_3 ) ) ; ++ V_35 )
V_399 [ V_35 ] = F_45 ( V_400 [ V_35 ] ) ;
}
static void
F_160 ( struct V_401 * V_397 ,
struct V_401 * V_398 )
{
T_3 * V_399 = ( T_3 * ) V_397 ;
T_13 * V_400 = ( T_13 * ) V_398 ;
int V_35 ;
for ( V_35 = 0 ; V_35 < ( ( sizeof( struct V_401 ) ) / sizeof( T_3 ) ) ;
V_35 = V_35 + 2 ) {
#ifdef F_161
V_399 [ V_35 ] = F_45 ( V_400 [ V_35 ] ) ;
V_399 [ V_35 + 1 ] = F_45 ( V_400 [ V_35 + 1 ] ) ;
#else
V_399 [ V_35 ] = F_45 ( V_400 [ V_35 + 1 ] ) ;
V_399 [ V_35 + 1 ] = F_45 ( V_400 [ V_35 ] ) ;
#endif
}
}
static void
F_162 ( void * V_119 , T_7 V_124 )
{
struct V_274 * V_275 = (struct V_274 * ) V_119 ;
struct V_402 * V_403 ;
struct V_85 * V_54 , * V_86 ;
union V_361 * V_404 ;
if ( V_124 ) {
struct V_9 V_10 ;
if ( V_275 -> V_405 == V_128 )
F_3 ( & V_10 ) ;
F_31 (qe, qen, &fcport->stats_pending_q) {
F_35 ( & V_275 -> V_372 , & V_54 ) ;
V_403 = (struct V_402 * ) V_54 ;
if ( V_275 -> V_405 == V_128 ) {
V_404 = (union V_361 * ) V_403 -> V_406 ;
if ( F_136 ( & V_275 -> V_64 -> V_261 ) )
F_159 ( & V_404 -> V_407 ,
& V_275 -> V_360 -> V_407 ) ;
else {
F_160 ( & V_404 -> V_408 ,
& V_275 -> V_360 -> V_408 ) ;
V_404 -> V_408 . V_409 =
V_10 . V_11 - V_275 -> V_364 ;
}
}
F_163 ( V_275 -> V_64 , & V_403 -> V_92 ,
V_275 -> V_405 ) ;
}
V_275 -> V_405 = V_128 ;
} else {
F_14 ( & V_275 -> V_372 ) ;
V_275 -> V_405 = V_128 ;
}
}
static void
F_164 ( void * V_119 )
{
struct V_274 * V_275 = (struct V_274 * ) V_119 ;
F_37 ( V_275 -> V_64 , V_275 -> V_410 ) ;
if ( V_275 -> V_410 ) {
F_76 ( & V_275 -> V_411 ) ;
V_275 -> V_410 = V_58 ;
}
V_275 -> V_405 = V_412 ;
F_162 ( V_275 , V_169 ) ;
}
static void
F_165 ( void * V_119 )
{
struct V_274 * V_275 = (struct V_274 * ) V_119 ;
struct V_394 * V_171 ;
V_171 = F_51 ( V_275 -> V_64 , V_387 ) ;
if ( ! V_171 ) {
V_275 -> V_410 = V_169 ;
F_16 ( & V_275 -> V_411 ,
F_165 , V_275 ) ;
F_70 ( V_275 -> V_64 , V_387 ,
& V_275 -> V_411 ) ;
return;
}
V_275 -> V_410 = V_58 ;
memset ( V_171 , 0 , sizeof( struct V_394 ) ) ;
F_53 ( V_171 -> V_146 , V_388 , V_413 ,
F_54 ( V_275 -> V_64 ) ) ;
F_61 ( V_275 -> V_64 , V_387 , V_171 -> V_146 ) ;
}
static void
F_166 ( void * V_119 , T_7 V_124 )
{
struct V_274 * V_275 = (struct V_274 * ) V_119 ;
struct V_402 * V_403 ;
struct V_85 * V_54 , * V_86 ;
if ( V_124 ) {
struct V_9 V_10 ;
F_3 ( & V_10 ) ;
V_275 -> V_364 = V_10 . V_11 ;
F_31 (qe, qen, &fcport->statsclr_pending_q) {
F_35 ( & V_275 -> V_373 , & V_54 ) ;
V_403 = (struct V_402 * ) V_54 ;
F_163 ( V_275 -> V_64 , & V_403 -> V_92 ,
V_275 -> V_405 ) ;
}
V_275 -> V_405 = V_128 ;
} else {
F_14 ( & V_275 -> V_373 ) ;
V_275 -> V_405 = V_128 ;
}
}
static void
F_167 ( void * V_119 )
{
struct V_274 * V_275 = (struct V_274 * ) V_119 ;
F_37 ( V_275 -> V_64 , V_275 -> V_410 ) ;
if ( V_275 -> V_410 ) {
F_76 ( & V_275 -> V_411 ) ;
V_275 -> V_410 = V_58 ;
}
V_275 -> V_405 = V_412 ;
F_166 ( V_275 , V_169 ) ;
}
static void
F_168 ( void * V_119 )
{
struct V_274 * V_275 = (struct V_274 * ) V_119 ;
struct V_394 * V_171 ;
V_171 = F_51 ( V_275 -> V_64 , V_387 ) ;
if ( ! V_171 ) {
V_275 -> V_410 = V_169 ;
F_16 ( & V_275 -> V_411 ,
F_168 , V_275 ) ;
F_70 ( V_275 -> V_64 , V_387 ,
& V_275 -> V_411 ) ;
return;
}
V_275 -> V_410 = V_58 ;
memset ( V_171 , 0 , sizeof( struct V_394 ) ) ;
F_53 ( V_171 -> V_146 , V_388 , V_414 ,
F_54 ( V_275 -> V_64 ) ) ;
F_61 ( V_275 -> V_64 , V_387 , V_171 -> V_146 ) ;
}
static void
F_169 ( struct V_274 * V_275 , struct V_415 * V_416 )
{
struct V_374 * V_353 = & V_275 -> V_353 ;
struct V_417 * V_418 ;
struct V_419 * V_420 ;
enum V_421 V_422 ;
int V_35 ;
int V_423 = 0 ;
F_37 ( V_275 -> V_64 , V_275 -> V_60 . V_354 ) ;
F_5 ( V_416 -> V_424 != V_425 &&
V_416 -> V_424 != V_426 ) ;
F_37 ( V_275 -> V_64 , V_353 -> V_378 . V_329 ) ;
F_37 ( V_275 -> V_64 , V_416 -> V_424 ) ;
F_37 ( V_275 -> V_64 , V_416 -> V_427 ) ;
V_422 = V_353 -> V_378 . V_329 ;
if ( V_275 -> V_60 . V_354 && ( V_353 -> V_378 . V_329 != V_379 ) )
V_353 -> V_378 . V_329 = V_416 -> V_424 ;
V_353 -> V_378 . V_367 = V_416 -> V_427 ;
for ( V_35 = 0 ; V_35 < V_428 ; V_35 ++ ) {
V_420 = & V_353 -> V_378 . V_429 [ V_35 ] ;
V_418 = & V_416 -> V_418 [ V_35 ] ;
V_420 -> V_320 = V_418 -> V_329 ;
V_420 -> V_430 = V_418 -> V_430 ;
V_420 -> V_431 = V_418 -> V_431 ;
V_420 -> V_367 = V_418 -> V_367 ;
V_420 -> V_432 = F_45 ( V_418 -> V_432 ) ;
if ( V_418 -> V_329 == V_433 ) {
V_275 -> V_367 = V_418 -> V_367 ;
V_275 -> V_365 = V_366 ;
V_423 |= 1 << V_35 ;
}
F_37 ( V_275 -> V_64 , V_420 -> V_320 ) ;
F_37 ( V_275 -> V_64 , V_420 -> V_430 ) ;
F_37 ( V_275 -> V_64 , V_420 -> V_431 ) ;
F_37 ( V_275 -> V_64 , V_420 -> V_367 ) ;
F_37 ( V_275 -> V_64 , V_420 -> V_432 ) ;
}
switch ( V_423 ) {
case 3 :
F_8 ( V_275 -> V_64 -> V_13 , V_301 ,
V_434 , 0 , L_21 ) ;
break;
case 2 :
F_8 ( V_275 -> V_64 -> V_13 , V_301 ,
V_434 , 0 , L_22 ) ;
break;
case 1 :
F_8 ( V_275 -> V_64 -> V_13 , V_301 ,
V_434 , 0 , L_23 ) ;
break;
default:
F_8 ( V_275 -> V_64 -> V_13 , V_301 ,
V_434 , 0 , L_24 ) ;
}
if ( ( V_422 != V_353 -> V_378 . V_329 ) ||
( V_416 -> V_424 == V_426 ) ) {
F_134 ( V_275 , ( V_416 -> V_424 == V_425 ) ?
V_312 : V_332 , V_169 ) ;
}
}
static void
F_155 ( struct V_63 * V_64 )
{
struct V_274 * V_275 = F_151 ( V_64 ) ;
int V_35 = 0 ;
if ( V_275 -> V_60 . V_354 ) {
if ( V_275 -> V_353 . V_378 . V_329 == V_425 )
F_134 ( V_275 , V_332 , V_169 ) ;
V_275 -> V_353 . V_378 . V_329 = V_426 ;
V_275 -> V_353 . V_378 . V_367 = V_382 ;
for ( V_35 = 0 ; V_35 < V_428 ; V_35 ++ ) {
V_275 -> V_353 . V_378 . V_429 [ V_35 ] . V_430 = 0 ;
V_275 -> V_353 . V_378 . V_429 [ V_35 ] . V_431 =
V_435 ;
V_275 -> V_353 . V_378 . V_429 [ V_35 ] . V_320 =
V_436 ;
V_275 -> V_353 . V_378 . V_429 [ V_35 ] . V_367 =
V_382 ;
V_275 -> V_353 . V_378 . V_429 [ V_35 ] . V_432 = 0 ;
}
}
}
void
F_170 ( struct V_63 * V_64 )
{
struct V_274 * V_275 = F_151 ( V_64 ) ;
F_158 ( V_275 ) ;
if ( V_275 -> V_60 . V_369 == 0 )
V_275 -> V_60 . V_369 = F_171 ( & V_64 -> V_261 ) ;
V_275 -> V_60 . V_437 = F_172 ( & V_64 -> V_261 ) ;
V_275 -> V_438 = F_173 ( & V_64 -> V_261 ) ;
if ( F_174 ( V_64 ) )
V_64 -> V_439 . V_281 . V_440 = V_169 ;
F_5 ( ! V_275 -> V_60 . V_369 ) ;
F_5 ( ! V_275 -> V_60 . V_437 ) ;
F_5 ( ! V_275 -> V_438 ) ;
}
void
F_175 ( struct V_63 * V_64 , struct V_170 * V_171 )
{
struct V_274 * V_275 = F_151 ( V_64 ) ;
union V_441 V_318 ;
V_318 . V_171 = V_171 ;
V_275 -> V_317 . V_318 = V_318 ;
F_37 ( V_64 , V_171 -> V_172 . V_173 ) ;
F_37 ( V_64 , F_176 ( V_442 , V_275 -> V_443 ) ) ;
switch ( V_171 -> V_172 . V_173 ) {
case V_444 :
if ( V_275 -> V_386 == V_318 . V_445 -> V_386 ) {
if ( V_275 -> V_287 ) {
V_275 -> V_60 = V_318 . V_445 -> V_363 ;
V_275 -> V_60 . V_369 =
F_55 ( V_275 -> V_60 . V_369 ) ;
V_275 -> V_60 . V_446 =
F_55 ( V_275 -> V_60 . V_446 ) ;
V_275 -> V_60 . V_447 =
F_55 ( V_275 -> V_60 . V_447 ) ;
if ( V_275 -> V_60 . V_354 )
V_275 -> V_353 . V_378 . V_329 =
V_426 ;
else
V_275 -> V_353 . V_378 . V_329 =
V_379 ;
V_275 -> V_287 = V_58 ;
}
if ( V_275 -> V_60 . V_327 )
V_275 -> V_328 . V_329 = V_448 ;
else
V_275 -> V_328 . V_329 = V_449 ;
F_88 ( V_275 , V_308 ) ;
}
break;
case V_450 :
if ( V_275 -> V_386 == V_318 . V_445 -> V_386 )
F_88 ( V_275 , V_308 ) ;
break;
case V_451 :
if ( V_318 . V_25 -> V_320 . V_452 == V_312 )
F_88 ( V_275 , V_306 ) ;
else
F_88 ( V_275 , V_307 ) ;
break;
case V_453 :
F_169 ( V_275 , V_318 . V_454 ) ;
break;
case V_455 :
if ( F_73 ( & V_275 -> V_372 ) ||
( V_275 -> V_405 == V_412 ) )
break;
F_177 ( & V_275 -> V_456 ) ;
V_275 -> V_405 = V_318 . V_457 -> V_192 ;
F_162 ( V_275 , V_169 ) ;
break;
case V_458 :
if ( F_73 ( & V_275 -> V_373 ) ||
( V_275 -> V_405 == V_412 ) )
break;
F_177 ( & V_275 -> V_456 ) ;
V_275 -> V_405 = V_128 ;
F_166 ( V_275 , V_169 ) ;
break;
case V_459 :
F_88 ( V_275 , V_290 ) ;
break;
case V_460 :
F_88 ( V_275 , V_291 ) ;
break;
default:
F_5 ( 1 ) ;
break;
}
}
void
F_178 ( struct V_63 * V_64 ,
void (* V_168) ( void * V_119 ,
enum V_352 V_25 ) ,
void * V_119 )
{
struct V_274 * V_275 = F_151 ( V_64 ) ;
V_275 -> V_311 = V_168 ;
V_275 -> V_350 = V_119 ;
}
T_6
F_179 ( struct V_63 * V_64 )
{
struct V_274 * V_275 = F_151 ( V_64 ) ;
if ( F_174 ( V_64 ) )
return V_461 ;
if ( F_180 ( & V_64 -> V_261 ) )
return V_462 ;
if ( V_275 -> V_463 )
return V_464 ;
F_88 ( F_151 ( V_64 ) , V_290 ) ;
return V_128 ;
}
T_6
F_181 ( struct V_63 * V_64 )
{
if ( F_174 ( V_64 ) )
return V_461 ;
if ( F_180 ( & V_64 -> V_261 ) )
return V_462 ;
F_88 ( F_151 ( V_64 ) , V_291 ) ;
return V_128 ;
}
T_6
F_174 ( struct V_63 * V_64 )
{
struct V_274 * V_275 = F_151 ( V_64 ) ;
struct V_465 * V_466 = & V_64 -> V_466 ;
struct V_467 * V_468 = V_466 -> V_468 ;
if ( V_468 -> V_469 . V_470 == V_471 ) {
F_37 ( V_64 , V_275 -> V_251 ) ;
return V_461 ;
}
return V_128 ;
}
T_6
F_182 ( struct V_63 * V_64 , enum V_472 V_367 )
{
struct V_274 * V_275 = F_151 ( V_64 ) ;
F_37 ( V_64 , V_367 ) ;
if ( V_275 -> V_60 . V_354 == V_169 )
return V_473 ;
if ( ( V_367 != V_368 ) && ( V_367 > V_275 -> V_438 ) ) {
F_37 ( V_64 , V_275 -> V_438 ) ;
return V_474 ;
}
if ( F_183 ( & V_275 -> V_64 -> V_261 ) == V_475 ) {
if ( ( V_367 == V_371 ) &&
( F_184 ( V_64 -> V_261 . V_81 . V_476 ) ) )
return V_474 ;
if ( ! ( V_367 == V_371 ||
V_367 == V_477 ||
V_367 == V_478 ||
V_367 == V_479 ||
V_367 == V_480 ||
V_367 == V_368 ) )
return V_474 ;
} else {
if ( V_367 != V_481 )
return V_474 ;
}
V_275 -> V_60 . V_367 = V_367 ;
return V_128 ;
}
enum V_472
F_185 ( struct V_63 * V_64 )
{
struct V_274 * V_275 = F_151 ( V_64 ) ;
return V_275 -> V_367 ;
}
T_6
F_186 ( struct V_63 * V_64 , enum V_482 V_365 )
{
struct V_274 * V_275 = F_151 ( V_64 ) ;
F_37 ( V_64 , V_365 ) ;
F_37 ( V_64 , V_275 -> V_60 . V_365 ) ;
switch ( V_365 ) {
case V_366 :
case V_375 :
case V_483 :
break;
default:
return V_484 ;
}
V_275 -> V_60 . V_365 = V_365 ;
return V_128 ;
}
enum V_482
F_187 ( struct V_63 * V_64 )
{
struct V_274 * V_275 = F_151 ( V_64 ) ;
return V_275 -> V_365 ;
}
T_6
F_188 ( struct V_63 * V_64 , V_37 V_248 )
{
struct V_274 * V_275 = F_151 ( V_64 ) ;
F_37 ( V_64 , V_248 ) ;
F_37 ( V_64 , V_275 -> V_60 . V_485 ) ;
F_37 ( V_64 , V_275 -> V_60 . V_486 ) ;
V_275 -> V_60 . V_485 = V_169 ;
V_275 -> V_60 . V_486 = V_248 ;
return V_128 ;
}
T_6
F_189 ( struct V_63 * V_64 )
{
struct V_274 * V_275 = F_151 ( V_64 ) ;
F_37 ( V_64 , V_275 -> V_60 . V_485 ) ;
F_37 ( V_64 , V_275 -> V_60 . V_486 ) ;
V_275 -> V_60 . V_485 = V_58 ;
return V_128 ;
}
T_7
F_190 ( struct V_63 * V_64 , V_37 * V_248 )
{
struct V_274 * V_275 = F_151 ( V_64 ) ;
* V_248 = V_275 -> V_60 . V_486 ;
return V_275 -> V_60 . V_485 ;
}
V_37
F_191 ( struct V_63 * V_64 )
{
struct V_274 * V_275 = F_151 ( V_64 ) ;
return V_275 -> V_376 ;
}
T_6
F_192 ( struct V_63 * V_64 , T_2 V_369 )
{
struct V_274 * V_275 = F_151 ( V_64 ) ;
F_37 ( V_64 , V_369 ) ;
F_37 ( V_64 , V_275 -> V_60 . V_369 ) ;
if ( ( V_369 > V_153 ) || ( V_369 < V_487 ) )
return V_488 ;
if ( ( V_369 != V_153 ) && ( V_369 & ( V_369 - 1 ) ) )
return V_488 ;
V_275 -> V_60 . V_369 = V_369 ;
return V_128 ;
}
T_2
F_193 ( struct V_63 * V_64 )
{
struct V_274 * V_275 = F_151 ( V_64 ) ;
return V_275 -> V_60 . V_369 ;
}
V_37
F_194 ( struct V_63 * V_64 )
{
struct V_274 * V_275 = F_151 ( V_64 ) ;
return V_275 -> V_60 . V_437 ;
}
void
F_195 ( struct V_63 * V_64 , T_2 V_489 , V_37 V_230 )
{
struct V_274 * V_275 = F_151 ( V_64 ) ;
V_275 -> V_60 . V_489 = ( V_37 ) V_489 ;
V_275 -> V_60 . V_230 = V_230 ;
if ( V_230 )
V_275 -> V_384 = V_169 ;
}
T_10
F_196 ( struct V_63 * V_64 , T_7 V_490 )
{
struct V_274 * V_275 = F_151 ( V_64 ) ;
if ( V_490 )
return V_275 -> V_252 ;
else
return V_275 -> V_251 ;
}
void
F_197 ( struct V_63 * V_64 , struct V_491 * V_378 )
{
struct V_274 * V_275 = F_151 ( V_64 ) ;
memset ( V_378 , 0 , sizeof( struct V_491 ) ) ;
V_378 -> V_252 = V_275 -> V_252 ;
V_378 -> V_251 = V_275 -> V_251 ;
V_378 -> V_492 = V_64 -> V_261 . V_378 -> V_493 ;
V_378 -> V_494 = V_64 -> V_261 . V_378 -> V_495 ;
memcpy ( & V_378 -> V_496 , & V_275 -> V_60 ,
sizeof( struct V_362 ) ) ;
V_378 -> V_496 . V_367 = V_275 -> V_60 . V_367 ;
V_378 -> V_497 = V_275 -> V_438 ;
V_378 -> V_367 = V_275 -> V_367 ;
V_378 -> V_498 = V_499 ;
V_378 -> V_496 . V_365 = V_275 -> V_60 . V_365 ;
V_378 -> V_365 = V_275 -> V_365 ;
V_378 -> V_496 . V_354 = V_275 -> V_60 . V_354 ;
V_378 -> V_500 = V_275 -> V_500 ;
V_378 -> V_501 = V_275 -> V_501 ;
V_378 -> V_496 . V_446 = F_198 ( V_64 ) ;
V_378 -> V_496 . V_447 = F_199 ( V_64 ) ;
V_378 -> V_502 = F_176 ( V_442 , V_275 -> V_443 ) ;
V_378 -> V_503 = V_275 -> V_384 ;
if ( F_174 ( V_64 ) )
V_378 -> V_502 = V_504 ;
else {
if ( F_180 ( & V_275 -> V_64 -> V_261 ) )
V_378 -> V_502 = V_505 ;
else if ( F_200 ( & V_275 -> V_64 -> V_261 ) )
V_378 -> V_502 = V_506 ;
}
V_378 -> V_380 = V_275 -> V_380 ;
}
T_6
F_201 ( struct V_63 * V_64 , struct V_402 * V_403 )
{
struct V_274 * V_275 = F_151 ( V_64 ) ;
if ( F_180 ( & V_64 -> V_261 ) )
return V_462 ;
if ( ! F_73 ( & V_275 -> V_373 ) )
return V_507 ;
if ( F_73 ( & V_275 -> V_372 ) ) {
F_15 ( & V_403 -> V_92 . V_54 , & V_275 -> V_372 ) ;
F_165 ( V_275 ) ;
F_202 ( V_64 , & V_275 -> V_456 ,
F_164 ,
V_275 , V_508 ) ;
} else
F_15 ( & V_403 -> V_92 . V_54 , & V_275 -> V_372 ) ;
return V_128 ;
}
T_6
F_203 ( struct V_63 * V_64 , struct V_402 * V_403 )
{
struct V_274 * V_275 = F_151 ( V_64 ) ;
if ( ! F_73 ( & V_275 -> V_372 ) )
return V_507 ;
if ( F_73 ( & V_275 -> V_373 ) ) {
F_15 ( & V_403 -> V_92 . V_54 , & V_275 -> V_373 ) ;
F_168 ( V_275 ) ;
F_202 ( V_64 , & V_275 -> V_456 ,
F_167 ,
V_275 , V_508 ) ;
} else
F_15 ( & V_403 -> V_92 . V_54 , & V_275 -> V_373 ) ;
return V_128 ;
}
T_7
F_204 ( struct V_63 * V_64 )
{
struct V_274 * V_275 = F_151 ( V_64 ) ;
return F_176 ( V_442 , V_275 -> V_443 ) ==
V_509 ;
}
T_7
F_205 ( struct V_63 * V_64 )
{
struct V_274 * V_275 = F_151 ( V_64 ) ;
return V_275 -> V_60 . V_510 ? V_169 : V_58 ;
}
void
F_206 ( struct V_63 * V_64 , V_37 V_329 )
{
struct V_274 * V_275 = F_151 ( V_64 ) ;
F_37 ( V_64 , V_329 ) ;
V_275 -> V_60 . V_511 = V_329 ;
}
enum V_472
F_207 ( struct V_63 * V_64 )
{
struct V_274 * V_275 = F_151 ( V_64 ) ;
F_37 ( V_64 , V_275 -> V_60 . V_370 ) ;
return V_275 -> V_60 . V_370 ;
}
void
F_208 ( void * V_512 , T_7 V_500 ,
T_7 V_501 )
{
struct V_63 * V_64 = V_512 ;
struct V_274 * V_275 = F_151 ( V_64 ) ;
F_37 ( V_64 , V_500 ) ;
F_37 ( V_64 , V_501 ) ;
F_37 ( V_64 , V_275 -> V_500 ) ;
F_37 ( V_64 , V_275 -> V_501 ) ;
V_275 -> V_500 = V_500 ;
V_275 -> V_501 = V_501 ;
}
T_7
F_209 ( struct V_63 * V_64 )
{
struct V_274 * V_275 = F_151 ( V_64 ) ;
return ( ! V_275 -> V_60 . V_354 &&
F_210 ( V_275 , V_310 ) ) ||
( V_275 -> V_60 . V_354 &&
V_275 -> V_353 . V_378 . V_329 == V_425 ) ;
}
T_7
F_211 ( struct V_63 * V_64 )
{
struct V_274 * V_275 = F_151 ( V_64 ) ;
return V_275 -> V_60 . V_327 ;
}
T_7
F_212 ( struct V_63 * V_64 )
{
struct V_274 * V_275 = F_151 ( V_64 ) ;
return V_275 -> V_60 . V_354 ;
}
static void
F_213 ( struct V_143 * V_513 , enum V_514 V_25 )
{
F_37 ( V_513 -> V_64 , V_513 -> V_515 ) ;
F_37 ( V_513 -> V_64 , V_25 ) ;
switch ( V_25 ) {
case V_516 :
F_214 ( V_513 , V_517 ) ;
F_83 ( V_513 , V_518 ) ;
break;
default:
F_214 ( V_513 , V_519 ) ;
F_87 ( V_513 -> V_64 , V_25 ) ;
}
}
static void
V_518 ( struct V_143 * V_513 , enum V_514 V_25 )
{
F_37 ( V_513 -> V_64 , V_513 -> V_515 ) ;
F_37 ( V_513 -> V_64 , V_25 ) ;
switch ( V_25 ) {
case V_520 :
F_214 ( V_513 , V_521 ) ;
if ( F_215 ( V_513 ) )
F_83 ( V_513 , V_522 ) ;
else
F_83 ( V_513 , V_523 ) ;
break;
case V_524 :
F_214 ( V_513 , V_525 ) ;
F_83 ( V_513 , F_213 ) ;
F_216 ( V_513 ) ;
break;
case V_526 :
F_214 ( V_513 , V_527 ) ;
F_83 ( V_513 , V_528 ) ;
break;
default:
F_214 ( V_513 , V_529 ) ;
F_87 ( V_513 -> V_64 , V_25 ) ;
}
}
static void
V_522 ( struct V_143 * V_513 , enum V_514 V_25 )
{
F_37 ( V_513 -> V_64 , V_513 -> V_515 ) ;
F_37 ( V_513 -> V_64 , V_25 ) ;
switch ( V_25 ) {
case V_530 :
F_214 ( V_513 , V_531 ) ;
F_83 ( V_513 , V_532 ) ;
F_217 ( V_513 ) ;
break;
case V_524 :
F_214 ( V_513 , V_533 ) ;
F_83 ( V_513 , V_534 ) ;
break;
case V_535 :
F_214 ( V_513 , V_536 ) ;
F_83 ( V_513 , V_537 ) ;
break;
case V_526 :
F_214 ( V_513 , V_538 ) ;
F_83 ( V_513 , V_528 ) ;
break;
default:
F_214 ( V_513 , V_539 ) ;
F_87 ( V_513 -> V_64 , V_25 ) ;
}
}
static void
V_523 ( struct V_143 * V_513 , enum V_514 V_25 )
{
F_37 ( V_513 -> V_64 , V_513 -> V_515 ) ;
F_37 ( V_513 -> V_64 , V_25 ) ;
switch ( V_25 ) {
case V_540 :
F_83 ( V_513 , V_522 ) ;
F_215 ( V_513 ) ;
break;
case V_524 :
F_214 ( V_513 , V_533 ) ;
F_83 ( V_513 , F_213 ) ;
F_76 ( & V_513 -> V_299 ) ;
F_216 ( V_513 ) ;
break;
case V_535 :
F_214 ( V_513 , V_536 ) ;
F_83 ( V_513 , V_541 ) ;
F_76 ( & V_513 -> V_299 ) ;
F_218 ( V_513 ) ;
break;
case V_526 :
F_214 ( V_513 , V_538 ) ;
F_83 ( V_513 , V_528 ) ;
F_76 ( & V_513 -> V_299 ) ;
break;
default:
F_214 ( V_513 , V_539 ) ;
F_87 ( V_513 -> V_64 , V_25 ) ;
}
}
static void
V_532 ( struct V_143 * V_513 , enum V_514 V_25 )
{
struct V_542 * V_543 ;
F_37 ( V_513 -> V_64 , V_513 -> V_515 ) ;
F_37 ( V_513 -> V_64 , V_25 ) ;
switch ( V_25 ) {
case V_535 :
F_214 ( V_513 , V_544 ) ;
if ( F_219 ( V_513 ) )
F_83 ( V_513 , V_545 ) ;
else
F_83 ( V_513 , V_546 ) ;
break;
case V_524 :
F_214 ( V_513 , V_547 ) ;
if ( F_219 ( V_513 ) )
F_83 ( V_513 , V_548 ) ;
else
F_83 ( V_513 , V_549 ) ;
break;
case V_526 :
F_214 ( V_513 , V_550 ) ;
F_83 ( V_513 , V_528 ) ;
break;
case V_551 :
F_220 ( V_513 ) ;
break;
case V_552 :
V_543 = (struct V_542 * ) V_513 -> V_317 . V_553 ;
V_513 -> V_328 = V_543 -> V_554 ;
F_37 ( V_513 -> V_64 , V_543 -> V_555 . V_556 ) ;
F_37 ( V_513 -> V_64 , V_543 -> V_554 . V_556 ) ;
F_37 ( V_513 -> V_64 , V_543 -> V_555 . V_557 ) ;
F_37 ( V_513 -> V_64 , V_543 -> V_554 . V_557 ) ;
V_543 -> V_555 . V_556 =
F_45 ( V_543 -> V_555 . V_556 ) ;
V_543 -> V_554 . V_556 =
F_45 ( V_543 -> V_554 . V_556 ) ;
if ( V_543 -> V_555 . V_556 !=
V_543 -> V_554 . V_556 )
F_221 ( V_513 -> V_558 ,
V_543 -> V_555 ,
V_543 -> V_554 ) ;
if ( V_543 -> V_555 . V_557 !=
V_543 -> V_554 . V_557 )
F_222 ( V_513 -> V_558 ,
V_543 -> V_555 ,
V_543 -> V_554 ) ;
break;
default:
F_214 ( V_513 , V_559 ) ;
F_87 ( V_513 -> V_64 , V_25 ) ;
}
}
static void
V_545 ( struct V_143 * V_513 , enum V_514 V_25 )
{
F_37 ( V_513 -> V_64 , V_513 -> V_515 ) ;
F_37 ( V_513 -> V_64 , V_25 ) ;
switch ( V_25 ) {
case V_530 :
F_214 ( V_513 , V_560 ) ;
F_83 ( V_513 , V_541 ) ;
F_218 ( V_513 ) ;
break;
case V_524 :
F_214 ( V_513 , V_561 ) ;
F_83 ( V_513 , V_548 ) ;
break;
case V_526 :
F_214 ( V_513 , V_562 ) ;
F_83 ( V_513 , V_528 ) ;
F_218 ( V_513 ) ;
break;
default:
F_214 ( V_513 , V_563 ) ;
F_87 ( V_513 -> V_64 , V_25 ) ;
}
}
static void
V_546 ( struct V_143 * V_513 , enum V_514 V_25 )
{
F_37 ( V_513 -> V_64 , V_513 -> V_515 ) ;
F_37 ( V_513 -> V_64 , V_25 ) ;
switch ( V_25 ) {
case V_540 :
F_83 ( V_513 , V_545 ) ;
F_219 ( V_513 ) ;
break;
case V_524 :
F_214 ( V_513 , V_561 ) ;
F_83 ( V_513 , V_549 ) ;
break;
case V_526 :
F_214 ( V_513 , V_562 ) ;
F_83 ( V_513 , V_528 ) ;
F_76 ( & V_513 -> V_299 ) ;
F_218 ( V_513 ) ;
break;
default:
F_214 ( V_513 , V_563 ) ;
F_87 ( V_513 -> V_64 , V_25 ) ;
}
}
static void
V_541 ( struct V_143 * V_513 , enum V_514 V_25 )
{
F_37 ( V_513 -> V_64 , V_513 -> V_515 ) ;
F_37 ( V_513 -> V_64 , V_25 ) ;
switch ( V_25 ) {
case V_524 :
F_214 ( V_513 , V_564 ) ;
F_83 ( V_513 , F_213 ) ;
F_216 ( V_513 ) ;
break;
case V_520 :
F_214 ( V_513 , V_565 ) ;
if ( F_215 ( V_513 ) )
F_83 ( V_513 , V_522 ) ;
else
F_83 ( V_513 , V_523 ) ;
break;
case V_526 :
F_214 ( V_513 , V_566 ) ;
F_83 ( V_513 , V_528 ) ;
break;
default:
F_214 ( V_513 , V_567 ) ;
F_87 ( V_513 -> V_64 , V_25 ) ;
}
}
static void
V_548 ( struct V_143 * V_513 , enum V_514 V_25 )
{
F_37 ( V_513 -> V_64 , V_513 -> V_515 ) ;
F_37 ( V_513 -> V_64 , V_25 ) ;
switch ( V_25 ) {
case V_530 :
F_214 ( V_513 , V_568 ) ;
F_83 ( V_513 , F_213 ) ;
F_216 ( V_513 ) ;
break;
case V_526 :
F_214 ( V_513 , V_569 ) ;
F_83 ( V_513 , F_213 ) ;
F_216 ( V_513 ) ;
break;
default:
F_87 ( V_513 -> V_64 , V_25 ) ;
}
}
static void
V_549 ( struct V_143 * V_513 , enum V_514 V_25 )
{
F_37 ( V_513 -> V_64 , V_513 -> V_515 ) ;
F_37 ( V_513 -> V_64 , V_25 ) ;
switch ( V_25 ) {
case V_540 :
F_214 ( V_513 , V_568 ) ;
F_83 ( V_513 , V_548 ) ;
F_219 ( V_513 ) ;
break;
case V_526 :
F_214 ( V_513 , V_569 ) ;
F_83 ( V_513 , F_213 ) ;
F_76 ( & V_513 -> V_299 ) ;
F_216 ( V_513 ) ;
break;
default:
F_87 ( V_513 -> V_64 , V_25 ) ;
}
}
static void
V_534 ( struct V_143 * V_513 ,
enum V_514 V_25 )
{
F_37 ( V_513 -> V_64 , V_513 -> V_515 ) ;
F_37 ( V_513 -> V_64 , V_25 ) ;
switch ( V_25 ) {
case V_530 :
F_214 ( V_513 , V_570 ) ;
if ( F_219 ( V_513 ) )
F_83 ( V_513 , V_548 ) ;
else
F_83 ( V_513 , V_549 ) ;
break;
case V_526 :
F_214 ( V_513 , V_571 ) ;
F_83 ( V_513 , F_213 ) ;
F_216 ( V_513 ) ;
break;
default:
F_214 ( V_513 , V_572 ) ;
F_87 ( V_513 -> V_64 , V_25 ) ;
}
}
static void
V_537 ( struct V_143 * V_513 ,
enum V_514 V_25 )
{
F_37 ( V_513 -> V_64 , V_513 -> V_515 ) ;
F_37 ( V_513 -> V_64 , V_25 ) ;
switch ( V_25 ) {
case V_530 :
F_214 ( V_513 , V_573 ) ;
if ( F_219 ( V_513 ) )
F_83 ( V_513 , V_545 ) ;
else
F_83 ( V_513 , V_546 ) ;
break;
case V_524 :
F_214 ( V_513 , V_574 ) ;
F_83 ( V_513 , V_534 ) ;
break;
case V_526 :
F_214 ( V_513 , V_575 ) ;
F_83 ( V_513 , V_528 ) ;
break;
default:
F_214 ( V_513 , V_576 ) ;
F_87 ( V_513 -> V_64 , V_25 ) ;
}
}
static void
V_528 ( struct V_143 * V_513 , enum V_514 V_25 )
{
F_37 ( V_513 -> V_64 , V_513 -> V_515 ) ;
F_37 ( V_513 -> V_64 , V_25 ) ;
switch ( V_25 ) {
case V_535 :
F_214 ( V_513 , V_577 ) ;
F_218 ( V_513 ) ;
break;
case V_524 :
F_214 ( V_513 , V_578 ) ;
F_83 ( V_513 , F_213 ) ;
F_216 ( V_513 ) ;
break;
case V_520 :
F_214 ( V_513 , V_579 ) ;
if ( F_215 ( V_513 ) )
F_83 ( V_513 , V_522 ) ;
else
F_83 ( V_513 , V_523 ) ;
break;
case V_526 :
break;
default:
F_214 ( V_513 , V_580 ) ;
F_87 ( V_513 -> V_64 , V_25 ) ;
}
}
static void
F_223 ( void * V_119 , T_7 V_124 )
{
struct V_143 * V_513 = V_119 ;
if ( V_124 )
F_224 ( V_513 -> V_558 ) ;
}
static void
F_225 ( void * V_119 , T_7 V_124 )
{
struct V_143 * V_513 = V_119 ;
if ( V_124 )
F_226 ( V_513 -> V_558 ) ;
}
static void
F_227 ( void * V_119 )
{
struct V_143 * V_513 = V_119 ;
F_88 ( V_513 , V_540 ) ;
}
static void
F_228 ( struct V_59 * V_60 , struct V_61 * V_62 ,
struct V_63 * V_64 )
{
struct V_65 * V_581 = F_229 ( V_64 ) ;
if ( V_60 -> V_72 . V_582 < V_583 )
V_60 -> V_72 . V_582 = V_583 ;
F_24 ( V_62 , V_581 ,
V_60 -> V_72 . V_582 * sizeof( struct V_143 ) ) ;
}
static void
F_230 ( struct V_63 * V_64 , void * V_79 , struct V_59 * V_60 ,
struct V_80 * V_81 )
{
struct V_584 * V_44 = F_231 ( V_64 ) ;
struct V_143 * V_513 ;
T_2 V_35 ;
F_14 ( & V_44 -> V_585 ) ;
F_14 ( & V_44 -> V_586 ) ;
F_14 ( & V_44 -> V_587 ) ;
V_513 = (struct V_143 * ) F_13 ( V_44 ) ;
V_44 -> V_588 = V_513 ;
V_44 -> V_582 = V_60 -> V_72 . V_582 ;
F_5 ( ! V_44 -> V_582 ||
( V_44 -> V_582 & ( V_44 -> V_582 - 1 ) ) ) ;
for ( V_35 = 0 ; V_35 < V_44 -> V_582 ; V_35 ++ , V_513 ++ ) {
memset ( V_513 , 0 , sizeof( struct V_143 ) ) ;
V_513 -> V_64 = V_64 ;
V_513 -> V_515 = V_35 ;
F_83 ( V_513 , F_213 ) ;
if ( V_35 )
F_15 ( & V_513 -> V_54 , & V_44 -> V_585 ) ;
F_16 ( & V_513 -> V_299 , F_227 , V_513 ) ;
}
F_13 ( V_44 ) = ( V_37 * ) V_513 ;
}
static void
F_232 ( struct V_63 * V_64 )
{
}
static void
F_233 ( struct V_63 * V_64 )
{
}
static void
F_234 ( struct V_63 * V_64 )
{
}
static void
F_235 ( struct V_63 * V_64 )
{
struct V_584 * V_44 = F_231 ( V_64 ) ;
struct V_143 * V_144 ;
struct V_85 * V_54 , * V_86 ;
F_30 ( & V_44 -> V_587 , & V_44 -> V_585 ) ;
F_31 (qe, qen, &mod->rp_active_q) {
V_144 = (struct V_143 * ) V_54 ;
F_88 ( V_144 , V_526 ) ;
}
}
static struct V_143 *
F_236 ( struct V_584 * V_44 )
{
struct V_143 * V_144 ;
F_35 ( & V_44 -> V_585 , & V_144 ) ;
if ( V_144 )
F_15 ( & V_144 -> V_54 , & V_44 -> V_586 ) ;
return V_144 ;
}
static void
F_216 ( struct V_143 * V_144 )
{
struct V_584 * V_44 = F_231 ( V_144 -> V_64 ) ;
F_5 ( ! F_40 ( & V_44 -> V_586 , V_144 ) ) ;
F_41 ( & V_144 -> V_54 ) ;
F_15 ( & V_144 -> V_54 , & V_44 -> V_585 ) ;
}
static T_7
F_215 ( struct V_143 * V_513 )
{
struct V_589 * V_245 ;
V_245 = F_51 ( V_513 -> V_64 , V_590 ) ;
if ( ! V_245 ) {
F_70 ( V_513 -> V_64 , V_590 , & V_513 -> V_299 ) ;
return V_58 ;
}
F_53 ( V_245 -> V_146 , V_591 , V_592 ,
F_54 ( V_513 -> V_64 ) ) ;
V_245 -> V_593 = V_513 -> V_515 ;
V_245 -> V_151 = F_55 ( V_513 -> V_152 . V_151 ) ;
V_245 -> V_265 = V_513 -> V_152 . V_265 ;
V_245 -> V_155 = F_56 ( V_513 -> V_64 , ( V_37 ) V_513 -> V_152 . V_156 ) ;
V_245 -> V_594 = V_513 -> V_152 . V_594 ;
V_245 -> V_595 = V_513 -> V_152 . V_595 ;
V_245 -> V_596 = V_513 -> V_152 . V_596 ;
V_245 -> V_154 = V_513 -> V_152 . V_154 ;
V_245 -> V_597 = V_513 -> V_152 . V_597 ;
F_61 ( V_513 -> V_64 , V_590 , V_245 -> V_146 ) ;
return V_169 ;
}
static T_7
F_219 ( struct V_143 * V_513 )
{
struct V_598 * V_245 ;
V_245 = F_51 ( V_513 -> V_64 , V_590 ) ;
if ( ! V_245 ) {
F_70 ( V_513 -> V_64 , V_590 , & V_513 -> V_299 ) ;
return V_58 ;
}
F_53 ( V_245 -> V_146 , V_591 , V_599 ,
F_54 ( V_513 -> V_64 ) ) ;
V_245 -> V_150 = V_513 -> V_150 ;
F_61 ( V_513 -> V_64 , V_590 , V_245 -> V_146 ) ;
return V_169 ;
}
static T_7
F_220 ( struct V_143 * V_513 )
{
struct V_600 * V_245 ;
V_245 = F_51 ( V_513 -> V_64 , V_590 ) ;
if ( ! V_245 ) {
F_37 ( V_513 -> V_64 , V_513 -> V_152 . V_367 ) ;
return V_58 ;
}
F_53 ( V_245 -> V_146 , V_591 , V_601 ,
F_54 ( V_513 -> V_64 ) ) ;
V_245 -> V_150 = V_513 -> V_150 ;
V_245 -> V_367 = ( V_37 ) V_513 -> V_152 . V_367 ;
F_61 ( V_513 -> V_64 , V_590 , V_245 -> V_146 ) ;
return V_169 ;
}
void
F_237 ( struct V_63 * V_64 , struct V_170 * V_245 )
{
union V_602 V_171 ;
struct V_143 * V_513 ;
F_37 ( V_64 , V_245 -> V_172 . V_173 ) ;
V_171 . V_171 = V_245 ;
switch ( V_245 -> V_172 . V_173 ) {
case V_603 :
V_513 = F_238 ( V_64 , V_171 . V_604 -> V_593 ) ;
V_513 -> V_150 = V_171 . V_604 -> V_150 ;
V_513 -> V_328 = V_171 . V_604 -> V_328 ;
F_239 ( V_64 , V_513 ) ;
F_5 ( V_171 . V_604 -> V_192 != V_128 ) ;
F_88 ( V_513 , V_530 ) ;
break;
case V_605 :
V_513 = F_238 ( V_64 , V_171 . V_606 -> V_593 ) ;
F_5 ( V_171 . V_606 -> V_192 != V_128 ) ;
F_240 ( V_64 , V_513 ) ;
F_88 ( V_513 , V_530 ) ;
break;
case V_607 :
V_513 = F_238 ( V_64 , V_171 . V_608 -> V_593 ) ;
V_513 -> V_317 . V_553 = V_171 . V_608 ;
F_88 ( V_513 , V_552 ) ;
break;
default:
F_37 ( V_64 , V_245 -> V_172 . V_173 ) ;
F_5 ( 1 ) ;
}
}
void
F_241 ( struct V_63 * V_64 , T_2 V_609 )
{
struct V_584 * V_44 = F_231 ( V_64 ) ;
struct V_85 * V_54 ;
int V_35 ;
for ( V_35 = 0 ; V_35 < ( V_44 -> V_582 - V_609 ) ; V_35 ++ ) {
F_80 ( & V_44 -> V_585 , & V_54 ) ;
F_15 ( V_54 , & V_44 -> V_587 ) ;
}
}
struct V_143 *
F_242 ( struct V_63 * V_64 , void * V_558 )
{
struct V_143 * V_513 ;
V_513 = F_236 ( F_231 ( V_64 ) ) ;
if ( V_513 == NULL )
return NULL ;
V_513 -> V_64 = V_64 ;
V_513 -> V_558 = V_558 ;
memset ( & V_513 -> V_360 , 0 , sizeof( V_513 -> V_360 ) ) ;
F_5 ( ! F_210 ( V_513 , F_213 ) ) ;
F_88 ( V_513 , V_516 ) ;
return V_513 ;
}
void
F_243 ( struct V_143 * V_144 , struct V_610 * V_152 )
{
F_5 ( V_152 -> V_151 == 0 ) ;
if ( V_152 -> V_151 == 0 ) {
F_37 ( V_144 -> V_64 , V_144 -> V_515 ) ;
V_152 -> V_151 = V_487 ;
}
V_144 -> V_152 = * V_152 ;
F_88 ( V_144 , V_520 ) ;
}
void
F_244 ( struct V_143 * V_144 , enum V_472 V_367 )
{
F_5 ( V_367 == 0 ) ;
F_5 ( V_367 == V_368 ) ;
V_144 -> V_152 . V_367 = V_367 ;
F_88 ( V_144 , V_551 ) ;
}
void
F_239 ( struct V_63 * V_64 , struct V_143 * V_513 )
{
struct V_206 * V_611 = F_96 ( V_64 ) ;
T_10 V_612 , V_613 ;
V_37 V_156 = ( V_37 ) V_513 -> V_152 . V_156 ;
V_613 = ( (struct V_614 * ) V_513 -> V_558 ) -> V_251 ;
V_612 = ( F_102 ( V_611 , V_513 -> V_152 . V_156 ) ) -> V_251 ;
F_102 ( V_611 , V_513 -> V_152 . V_156 ) -> V_615 =
V_513 -> V_615 = V_169 ;
F_245 ( V_64 , V_612 , V_613 , V_513 -> V_515 , V_156 ) ;
}
void
F_240 ( struct V_63 * V_64 , struct V_143 * V_513 )
{
struct V_206 * V_611 = F_96 ( V_64 ) ;
T_10 V_612 , V_613 ;
V_613 = ( (struct V_614 * ) V_513 -> V_558 ) -> V_251 ;
V_612 = ( F_102 ( V_611 , V_513 -> V_152 . V_156 ) ) -> V_251 ;
F_102 ( V_611 , V_513 -> V_152 . V_156 ) -> V_615 =
V_513 -> V_615 = V_58 ;
F_245 ( V_64 , V_612 , V_613 ,
V_616 , V_617 ) ;
}
static void
F_246 ( struct V_59 * V_60 , struct V_61 * V_62 ,
struct V_63 * V_64 )
{
struct V_618 * V_619 = F_247 ( V_64 ) ;
struct V_65 * V_620 = F_248 ( V_64 ) ;
struct V_67 * V_68 ;
T_2 V_69 , V_70 , V_621 , V_622 ;
T_3 V_623 = sizeof( struct V_624 ) ;
if ( V_60 -> V_75 . V_625 < V_626 )
V_60 -> V_75 . V_625 = V_626 ;
else if ( V_60 -> V_75 . V_625 > V_627 )
V_60 -> V_75 . V_625 = V_627 ;
V_622 = V_60 -> V_75 . V_625 ;
V_69 = F_20 ( V_622 , V_623 ) ;
V_621 = F_21 ( V_623 ) ;
F_22 (sgpg_mod, seg_ptr, nsegs, idx) {
if ( V_622 >= V_621 ) {
V_622 -= V_621 ;
F_23 ( V_62 , V_68 ,
V_621 * V_623 ) ;
} else
F_23 ( V_62 , V_68 ,
V_622 * V_623 ) ;
}
F_24 ( V_62 , V_620 ,
V_60 -> V_75 . V_625 * sizeof( struct V_628 ) ) ;
}
static void
F_249 ( struct V_63 * V_64 , void * V_79 , struct V_59 * V_60 ,
struct V_80 * V_81 )
{
struct V_618 * V_44 = F_247 ( V_64 ) ;
struct V_628 * V_629 ;
struct V_624 * V_630 ;
T_1 V_631 ;
struct V_67 * V_68 ;
T_3 V_623 = sizeof( struct V_624 ) ;
T_2 V_35 , V_70 , V_69 , V_621 , V_622 ;
union {
T_1 V_632 ;
union V_633 V_634 ;
} V_635 , V_636 ;
F_14 ( & V_44 -> V_637 ) ;
F_14 ( & V_44 -> V_638 ) ;
F_37 ( V_64 , V_60 -> V_75 . V_625 ) ;
V_44 -> V_639 = V_44 -> V_625 = V_60 -> V_75 . V_625 ;
V_622 = V_60 -> V_75 . V_625 ;
V_69 = F_20 ( V_622 , V_623 ) ;
V_629 = (struct V_628 * ) F_13 ( V_44 ) ;
F_22 (mod, seg_ptr, nsegs, idx) {
if ( ! F_148 ( V_68 ) )
break;
V_631 = F_250 ( F_149 ( V_68 ) ) -
F_149 ( V_68 ) ;
V_630 = (struct V_624 * )
( ( ( V_37 * ) F_148 ( V_68 ) ) + V_631 ) ;
V_635 . V_632 = F_149 ( V_68 ) + V_631 ;
F_5 ( V_635 . V_632 & ( V_623 - 1 ) ) ;
V_621 = ( V_68 -> V_640 - ( T_3 ) V_631 ) / V_623 ;
for ( V_35 = 0 ; V_622 > 0 && V_35 < V_621 ; V_35 ++ , V_622 -- ) {
memset ( V_629 , 0 , sizeof( * V_629 ) ) ;
memset ( V_630 , 0 , sizeof( * V_630 ) ) ;
V_629 -> V_630 = V_630 ;
V_636 . V_632 = F_251 ( V_635 . V_632 ) ;
V_629 -> V_635 = V_636 . V_634 ;
F_15 ( & V_629 -> V_54 , & V_44 -> V_637 ) ;
V_630 ++ ;
V_629 ++ ;
V_635 . V_632 += V_623 ;
}
}
F_13 ( V_44 ) = ( V_37 * ) V_629 ;
}
static void
F_252 ( struct V_63 * V_64 )
{
}
static void
F_253 ( struct V_63 * V_64 )
{
}
static void
F_254 ( struct V_63 * V_64 )
{
}
static void
F_255 ( struct V_63 * V_64 )
{
}
T_6
F_256 ( struct V_63 * V_64 , struct V_85 * V_637 , int V_641 )
{
struct V_618 * V_44 = F_247 ( V_64 ) ;
struct V_628 * V_629 ;
int V_35 ;
if ( V_44 -> V_639 < V_641 )
return V_642 ;
for ( V_35 = 0 ; V_35 < V_641 ; V_35 ++ ) {
F_35 ( & V_44 -> V_637 , & V_629 ) ;
F_5 ( ! V_629 ) ;
F_15 ( & V_629 -> V_54 , V_637 ) ;
}
V_44 -> V_639 -= V_641 ;
return V_128 ;
}
void
F_257 ( struct V_63 * V_64 , struct V_85 * V_637 , int V_643 )
{
struct V_618 * V_44 = F_247 ( V_64 ) ;
struct V_644 * V_115 ;
V_44 -> V_639 += V_643 ;
F_5 ( V_44 -> V_639 > V_44 -> V_625 ) ;
F_30 ( V_637 , & V_44 -> V_637 ) ;
if ( F_73 ( & V_44 -> V_638 ) )
return;
do {
V_115 = F_258 ( & V_44 -> V_638 ) ;
if ( V_44 -> V_639 < V_115 -> V_643 )
V_643 = V_44 -> V_639 ;
else
V_643 = V_115 -> V_643 ;
F_256 ( V_64 , & V_115 -> V_637 , V_643 ) ;
V_115 -> V_643 -= V_643 ;
if ( V_115 -> V_643 == 0 ) {
F_41 ( & V_115 -> V_54 ) ;
V_115 -> V_168 ( V_115 -> V_119 ) ;
}
} while ( V_44 -> V_639 && ! F_73 ( & V_44 -> V_638 ) );
}
void
F_259 ( struct V_63 * V_64 , struct V_644 * V_115 , int V_643 )
{
struct V_618 * V_44 = F_247 ( V_64 ) ;
F_5 ( V_643 <= 0 ) ;
F_5 ( V_643 <= V_44 -> V_639 ) ;
V_115 -> V_645 = V_115 -> V_643 = V_643 ;
if ( V_44 -> V_639 ) {
F_5 ( ! F_73 ( & V_44 -> V_638 ) ) ;
F_30 ( & V_44 -> V_637 , & V_115 -> V_637 ) ;
V_115 -> V_643 -= V_44 -> V_639 ;
V_44 -> V_639 = 0 ;
}
F_15 ( & V_115 -> V_54 , & V_44 -> V_638 ) ;
}
void
F_260 ( struct V_63 * V_64 , struct V_644 * V_115 )
{
struct V_618 * V_44 = F_247 ( V_64 ) ;
F_5 ( ! F_40 ( & V_44 -> V_638 , V_115 ) ) ;
F_41 ( & V_115 -> V_54 ) ;
if ( V_115 -> V_645 != V_115 -> V_643 )
F_257 ( V_64 , & V_115 -> V_637 ,
V_115 -> V_645 - V_115 -> V_643 ) ;
}
void
F_261 ( struct V_644 * V_115 , void (* V_168) ( void * V_119 ) ,
void * V_119 )
{
F_14 ( & V_115 -> V_637 ) ;
V_115 -> V_168 = V_168 ;
V_115 -> V_119 = V_119 ;
}
static void
F_262 ( void * V_119 , T_7 V_124 )
{
struct V_646 * V_647 = V_119 ;
struct V_648 * V_649 = F_263 ( V_647 -> V_64 ) ;
if ( V_124 )
V_649 -> V_650 ( V_649 -> V_119 , V_647 ) ;
}
static void
F_264 ( struct V_648 * V_649 )
{
struct V_651 * V_652 ;
T_2 V_35 ;
T_2 V_653 ;
V_649 -> V_654 = (struct V_651 * ) F_13 ( V_649 ) ;
V_652 = V_649 -> V_654 ;
for ( V_35 = 0 , V_652 = V_649 -> V_654 ; V_35 < V_649 -> V_655 ;
V_35 ++ , V_652 ++ ) {
memset ( V_652 , 0 , sizeof( struct V_651 ) ) ;
V_652 -> V_656 = V_35 ;
V_653 = sizeof( struct V_657 ) ;
V_652 -> V_653 = F_55 ( V_653 ) ;
F_53 ( V_652 -> V_146 , V_658 , V_659 ,
F_54 ( V_649 -> V_64 ) ) ;
F_58 ( & V_652 -> V_660 , V_653 , F_265 ( V_649 , V_35 ) ) ;
}
F_13 ( V_649 ) = ( V_37 * ) V_652 ;
}
static void
F_266 ( struct V_648 * V_649 )
{
T_2 V_35 ;
struct V_646 * V_647 ;
V_649 -> V_661 = (struct V_646 * ) F_13 ( V_649 ) ;
for ( V_35 = 0 , V_647 = V_649 -> V_661 ; V_35 < V_649 -> V_655 ; V_35 ++ , V_647 ++ ) {
memset ( V_647 , 0 , sizeof( struct V_646 ) ) ;
V_647 -> V_64 = V_649 -> V_64 ;
V_647 -> V_662 = V_35 ;
V_647 -> V_663 = V_664 ;
V_647 -> V_665 = F_66 ( V_649 , V_35 , V_664 ) ;
V_647 -> V_666 = F_265 ( V_649 , V_35 ) ;
F_15 ( & V_647 -> V_54 , & V_649 -> V_667 ) ;
}
F_13 ( V_649 ) = ( V_37 * ) V_647 ;
}
static void
F_267 ( struct V_648 * V_649 )
{
F_266 ( V_649 ) ;
F_264 ( V_649 ) ;
}
static void
F_268 ( struct V_59 * V_60 , struct V_61 * V_62 ,
struct V_63 * V_64 )
{
struct V_648 * V_649 = F_263 ( V_64 ) ;
struct V_65 * V_668 = F_269 ( V_64 ) ;
T_3 V_655 = V_60 -> V_72 . V_669 ;
struct V_67 * V_68 ;
T_2 V_69 , V_70 , V_670 = 0 ;
V_69 = F_20 ( V_655 , V_664 ) ;
V_670 = F_21 ( V_664 ) ;
F_22 (ufm, seg_ptr, nsegs, idx) {
if ( V_655 >= V_670 ) {
V_655 -= V_670 ;
F_23 ( V_62 , V_68 ,
V_670 * V_664 ) ;
} else
F_23 ( V_62 , V_68 ,
V_655 * V_664 ) ;
}
F_24 ( V_62 , V_668 , V_60 -> V_72 . V_669 *
( sizeof( struct V_646 ) + sizeof( struct V_651 ) ) ) ;
}
static void
F_270 ( struct V_63 * V_64 , void * V_79 , struct V_59 * V_60 ,
struct V_80 * V_81 )
{
struct V_648 * V_649 = F_263 ( V_64 ) ;
V_649 -> V_64 = V_64 ;
V_649 -> V_655 = V_60 -> V_72 . V_669 ;
F_14 ( & V_649 -> V_667 ) ;
F_14 ( & V_649 -> V_671 ) ;
F_14 ( & V_649 -> V_672 ) ;
F_267 ( V_649 ) ;
}
static void
F_271 ( struct V_63 * V_64 )
{
}
static struct V_646 *
F_272 ( struct V_648 * V_673 )
{
struct V_646 * V_647 ;
F_35 ( & V_673 -> V_667 , & V_647 ) ;
return V_647 ;
}
static void
F_273 ( struct V_648 * V_673 , struct V_646 * V_647 )
{
F_15 ( & V_647 -> V_54 , & V_673 -> V_667 ) ;
}
static T_6
F_274 ( struct V_648 * V_649 , struct V_646 * V_647 )
{
struct V_651 * V_674 ;
V_674 = F_51 ( V_649 -> V_64 , V_136 ) ;
if ( ! V_674 )
return V_675 ;
memcpy ( V_674 , & V_649 -> V_654 [ V_647 -> V_662 ] ,
sizeof( struct V_651 ) ) ;
F_61 ( V_649 -> V_64 , V_136 , V_674 -> V_146 ) ;
F_37 ( V_649 -> V_64 , V_647 -> V_662 ) ;
F_15 ( & V_647 -> V_54 , & V_649 -> V_671 ) ;
return V_128 ;
}
static void
F_275 ( struct V_648 * V_673 )
{
struct V_646 * V_647 ;
while ( ( V_647 = F_272 ( V_673 ) ) != NULL ) {
if ( F_274 ( V_673 , V_647 ) != V_128 )
break;
}
}
static void
F_276 ( struct V_63 * V_64 , struct V_676 * V_245 )
{
struct V_648 * V_649 = F_263 ( V_64 ) ;
T_2 V_662 = V_245 -> V_656 ;
struct V_646 * V_647 = & V_649 -> V_661 [ V_662 ] ;
struct V_657 * V_677 ;
T_11 * V_678 ;
struct V_38 * V_129 ;
V_677 = (struct V_657 * )
F_66 ( V_649 , V_662 , V_647 -> V_663 ) ;
V_678 = & V_677 -> V_397 [ 0 ] ;
V_245 -> V_679 = F_44 ( V_245 -> V_679 ) ;
V_245 -> V_680 = F_44 ( V_245 -> V_680 ) ;
V_129 = (struct V_38 * ) V_677 ;
F_41 ( & V_647 -> V_54 ) ;
V_647 -> V_681 = V_678 ;
V_647 -> V_682 = V_245 -> V_680 ;
F_5 ( V_647 -> V_682 < sizeof( struct V_38 ) ) ;
if ( V_647 -> V_682 == sizeof( struct V_38 ) ) {
F_10 ( V_64 -> V_13 , V_683 , V_133 ,
V_647 -> V_682 , (struct V_38 * ) V_678 ) ;
} else {
T_3 V_42 = * ( ( T_3 * ) ( V_678 + sizeof( struct V_38 ) ) ) ;
F_11 ( V_64 -> V_13 , V_683 ,
V_133 , V_647 -> V_682 ,
(struct V_38 * ) V_678 , V_42 ) ;
}
if ( V_64 -> V_260 )
F_262 ( V_647 , V_169 ) ;
else
F_33 ( V_64 , & V_647 -> V_92 , F_262 , V_647 ) ;
}
static void
F_277 ( struct V_63 * V_64 )
{
}
static void
F_278 ( struct V_63 * V_64 )
{
struct V_648 * V_649 = F_263 ( V_64 ) ;
struct V_646 * V_647 ;
struct V_85 * V_54 , * V_86 ;
F_30 ( & V_649 -> V_672 , & V_649 -> V_667 ) ;
F_31 (qe, qen, &ufm->uf_posted_q) {
V_647 = (struct V_646 * ) V_54 ;
F_41 ( & V_647 -> V_54 ) ;
F_273 ( V_649 , V_647 ) ;
}
}
static void
F_279 ( struct V_63 * V_64 )
{
F_275 ( F_263 ( V_64 ) ) ;
}
void
F_280 ( struct V_63 * V_64 , T_14 V_650 , void * V_119 )
{
struct V_648 * V_649 = F_263 ( V_64 ) ;
V_649 -> V_650 = V_650 ;
V_649 -> V_119 = V_119 ;
}
void
F_281 ( struct V_646 * V_647 )
{
F_273 ( F_263 ( V_647 -> V_64 ) , V_647 ) ;
F_275 ( F_263 ( V_647 -> V_64 ) ) ;
}
void
F_282 ( struct V_63 * V_64 , struct V_170 * V_171 )
{
F_37 ( V_64 , V_171 -> V_172 . V_173 ) ;
switch ( V_171 -> V_172 . V_173 ) {
case V_684 :
F_276 ( V_64 , (struct V_676 * ) V_171 ) ;
break;
default:
F_37 ( V_64 , V_171 -> V_172 . V_173 ) ;
F_5 ( 1 ) ;
}
}
void
F_283 ( struct V_63 * V_64 , T_2 V_685 )
{
struct V_648 * V_44 = F_263 ( V_64 ) ;
struct V_85 * V_54 ;
int V_35 ;
for ( V_35 = 0 ; V_35 < ( V_44 -> V_655 - V_685 ) ; V_35 ++ ) {
F_80 ( & V_44 -> V_667 , & V_54 ) ;
F_15 ( V_54 , & V_44 -> V_672 ) ;
}
}
static void
F_284 ( struct V_686 * V_687 )
{
struct V_274 * V_275 = F_151 ( V_687 -> V_64 ) ;
if ( V_687 -> V_688 . V_689 )
V_275 -> V_463 = V_169 ;
else
V_275 -> V_463 = V_58 ;
}
static void
F_285 ( struct V_59 * V_60 , struct V_61 * V_690 ,
struct V_63 * V_64 )
{
}
static void
F_286 ( struct V_63 * V_64 , void * V_79 , struct V_59 * V_60 ,
struct V_80 * V_81 )
{
struct V_686 * V_687 = F_287 ( V_64 ) ;
V_687 -> V_64 = V_64 ;
V_687 -> V_691 = V_64 -> V_691 ;
}
static void
F_288 ( struct V_63 * V_64 )
{
struct V_686 * V_687 = F_287 ( V_64 ) ;
F_37 ( V_687 , V_687 -> V_688 . V_689 ) ;
if ( V_687 -> V_688 . V_689 ) {
V_687 -> V_688 . V_192 = V_90 ;
V_687 -> V_688 . V_168 ( V_687 -> V_688 . V_119 , V_687 -> V_688 . V_192 ) ;
V_687 -> V_688 . V_689 = 0 ;
F_284 ( V_687 ) ;
}
}
static void
F_289 ( struct V_63 * V_64 )
{
}
static void
F_290 ( struct V_63 * V_64 )
{
}
static void
F_291 ( struct V_63 * V_64 )
{
}
static void
F_292 ( void * V_119 )
{
struct V_686 * V_687 = V_119 ;
struct V_692 * V_693 = V_687 -> V_694 . V_695 ;
F_37 ( V_687 , V_687 -> V_694 . V_696 ) ;
F_37 ( V_687 , V_687 -> V_694 . V_238 ) ;
V_687 -> V_694 . V_697 = 0 ;
V_693 -> V_192 = V_412 ;
V_693 -> V_238 = V_698 - V_687 -> V_694 . V_238 ;
if ( V_687 -> V_694 . V_696 )
V_693 -> V_699 = V_687 -> V_694 . V_696 ;
F_37 ( V_687 , V_412 ) ;
V_687 -> V_694 . V_192 = V_412 ;
V_687 -> V_694 . V_168 ( V_687 -> V_694 . V_119 , V_687 -> V_694 . V_192 ) ;
V_687 -> V_694 . V_689 = 0 ;
}
static T_6
F_293 ( struct V_686 * V_687 )
{
T_3 V_35 ;
struct V_700 * V_701 ;
V_701 = F_51 ( V_687 -> V_64 , V_687 -> V_694 . V_699 ) ;
if ( ! V_701 )
return V_507 ;
F_53 ( V_701 -> V_146 , V_702 , V_703 ,
F_54 ( V_687 -> V_64 ) ) ;
for ( V_35 = 0 ; V_35 < V_704 ; V_35 ++ )
V_701 -> V_406 [ V_35 ] = V_705 ;
F_37 ( V_687 , V_687 -> V_694 . V_699 ) ;
F_61 ( V_687 -> V_64 , V_687 -> V_694 . V_699 , V_701 -> V_146 ) ;
return V_128 ;
}
static void
F_294 ( struct V_686 * V_687 ,
T_15 * V_215 )
{
struct V_692 * V_693 = V_687 -> V_694 . V_695 ;
T_6 V_192 = V_128 ;
int V_35 ;
if ( ! V_687 -> V_694 . V_697 ) {
F_37 ( V_687 , V_687 -> V_694 . V_697 ) ;
return;
}
V_687 -> V_694 . V_238 -- ;
for ( V_35 = 0 ; V_35 < V_704 ; V_35 ++ ) {
if ( V_215 -> V_406 [ V_35 ] != ~ ( V_705 ) ) {
V_693 -> V_192 = V_706 ;
break;
}
}
if ( V_693 -> V_192 == V_128 ) {
if ( V_687 -> V_694 . V_238 > 0 ) {
V_192 = F_293 ( V_687 ) ;
if ( V_192 == V_128 )
return;
else
V_693 -> V_192 = V_192 ;
} else if ( V_687 -> V_694 . V_696 > 0 &&
V_687 -> V_694 . V_699 < ( V_707 - 1 ) ) {
V_687 -> V_694 . V_238 = V_698 ;
V_687 -> V_694 . V_699 ++ ;
V_192 = F_293 ( V_687 ) ;
if ( V_192 == V_128 )
return;
else
V_693 -> V_192 = V_192 ;
}
}
if ( V_687 -> V_694 . V_697 ) {
F_177 ( & V_687 -> V_694 . V_456 ) ;
V_687 -> V_694 . V_697 = 0 ;
}
V_693 -> V_699 = V_687 -> V_694 . V_699 ;
V_693 -> V_238 = V_698 - V_687 -> V_694 . V_238 ;
F_37 ( V_687 , V_693 -> V_238 ) ;
F_37 ( V_687 , V_693 -> V_192 ) ;
V_687 -> V_694 . V_192 = V_693 -> V_192 ;
V_687 -> V_694 . V_168 ( V_687 -> V_694 . V_119 , V_687 -> V_694 . V_192 ) ;
V_687 -> V_694 . V_689 = 0 ;
}
static void
F_295 ( struct V_686 * V_687 ,
struct V_708 * V_215 )
{
struct V_709 * V_693 = V_687 -> V_688 . V_695 ;
V_693 -> V_710 = F_45 ( V_215 -> V_693 . V_710 ) ;
V_693 -> V_711 = F_45 ( V_215 -> V_693 . V_711 ) ;
V_693 -> V_712 = F_45 ( V_215 -> V_693 . V_712 ) ;
V_693 -> V_713 = F_45 ( V_215 -> V_693 . V_713 ) ;
V_693 -> V_714 = F_45 ( V_215 -> V_693 . V_714 ) ;
V_693 -> V_192 = V_215 -> V_693 . V_192 ;
V_687 -> V_688 . V_192 = V_215 -> V_693 . V_192 ;
F_37 ( V_687 , V_687 -> V_688 . V_192 ) ;
V_687 -> V_688 . V_168 ( V_687 -> V_688 . V_119 , V_687 -> V_688 . V_192 ) ;
V_687 -> V_688 . V_689 = 0 ;
F_284 ( V_687 ) ;
}
static T_6
F_296 ( struct V_686 * V_687 ,
struct V_715 * V_716 )
{
struct V_717 * V_718 ;
V_718 = F_51 ( V_687 -> V_64 , V_719 ) ;
if ( ! V_718 )
return V_507 ;
F_53 ( V_718 -> V_146 , V_702 , V_720 ,
F_54 ( V_687 -> V_64 ) ) ;
V_718 -> V_721 = V_716 -> V_721 ;
V_718 -> V_367 = V_716 -> V_367 ;
V_718 -> V_722 = V_716 -> V_722 ;
V_718 -> V_723 = V_716 -> V_723 ;
F_61 ( V_687 -> V_64 , V_719 , V_718 -> V_146 ) ;
F_37 ( V_687 , V_716 -> V_721 ) ;
F_37 ( V_687 , V_716 -> V_367 ) ;
F_37 ( V_687 , V_716 -> V_722 ) ;
F_37 ( V_687 , V_716 -> V_723 ) ;
return V_128 ;
}
void
F_297 ( struct V_63 * V_64 , struct V_170 * V_171 )
{
struct V_686 * V_687 = F_287 ( V_64 ) ;
switch ( V_171 -> V_172 . V_173 ) {
case V_724 :
F_295 ( V_687 ,
(struct V_708 * ) V_171 ) ;
break;
case V_725 :
F_294 ( V_687 , ( T_15 * ) V_171 ) ;
break;
default:
F_37 ( V_687 , V_171 -> V_172 . V_173 ) ;
F_5 ( 1 ) ;
}
}
T_6
F_298 ( struct V_63 * V_64 , enum V_726 V_727 ,
enum V_472 V_367 , T_3 V_728 , T_3 V_729 ,
struct V_709 * V_695 , T_16 V_168 ,
void * V_119 )
{
struct V_715 V_716 ;
struct V_491 V_378 ;
T_6 V_192 ;
struct V_686 * V_687 = F_287 ( V_64 ) ;
if ( ! F_299 ( V_64 ) )
return V_730 ;
if ( F_174 ( V_64 ) ) {
F_37 ( V_687 , V_461 ) ;
return V_461 ;
}
if ( F_204 ( V_64 ) == V_58 ) {
F_37 ( V_687 , V_727 ) ;
return V_731 ;
}
if ( F_183 ( & V_64 -> V_261 ) == V_475 ) {
if ( ! ( V_367 == V_371 ||
V_367 == V_477 ||
V_367 == V_478 ||
V_367 == V_479 ||
V_367 == V_480 ||
V_367 == V_368 ) ) {
F_37 ( V_687 , V_367 ) ;
return V_474 ;
}
F_197 ( V_64 , & V_378 ) ;
F_37 ( V_687 , V_378 . V_497 ) ;
if ( V_367 > V_378 . V_497 )
return V_474 ;
} else {
if ( V_367 != V_481 ) {
F_37 ( V_687 , V_367 ) ;
return V_474 ;
}
}
if ( F_300 ( V_64 -> V_261 . V_378 -> V_732 ) ) {
if ( F_183 ( & V_64 -> V_261 ) == V_475 ) {
if ( ( V_367 == V_371 ) &&
( F_184 ( V_64 -> V_261 . V_81 . V_476 ) ) )
return V_474 ;
if ( ! ( V_367 == V_371 ||
V_367 == V_477 ||
V_367 == V_478 ||
V_367 == V_479 ||
V_367 == V_480 ||
V_367 == V_368 ) )
return V_474 ;
} else {
if ( V_367 != V_481 )
return V_474 ;
}
}
if ( V_687 -> V_688 . V_689 ) {
F_37 ( V_687 , V_687 -> V_688 . V_689 ) ;
return V_507 ;
}
V_687 -> V_688 . V_689 = 1 ;
V_716 . V_721 = V_727 ;
V_716 . V_367 = V_367 ;
V_716 . V_722 = V_728 ;
V_716 . V_723 = V_729 ;
V_687 -> V_688 . V_695 = V_695 ;
V_687 -> V_688 . V_168 = V_168 ;
V_687 -> V_688 . V_119 = V_119 ;
memset ( V_695 , 0 , sizeof( struct V_709 ) ) ;
F_284 ( V_687 ) ;
V_192 = F_296 ( V_687 , & V_716 ) ;
return V_192 ;
}
T_6
F_301 ( struct V_63 * V_64 , T_3 V_733 , T_3 V_699 ,
struct V_692 * V_695 , T_16 V_168 ,
void * V_119 )
{
struct V_686 * V_687 = F_287 ( V_64 ) ;
T_6 V_192 ;
F_37 ( V_687 , V_733 ) ;
F_37 ( V_687 , V_699 ) ;
if ( ! V_733 && ! F_299 ( V_64 ) )
return V_730 ;
if ( V_687 -> V_694 . V_689 ) {
F_37 ( V_687 , V_687 -> V_694 . V_689 ) ;
return V_507 ;
}
V_687 -> V_694 . V_689 = 1 ;
V_687 -> V_694 . V_168 = V_168 ;
V_687 -> V_694 . V_119 = V_119 ;
V_687 -> V_694 . V_695 = V_695 ;
V_687 -> V_694 . V_238 = V_698 ;
V_687 -> V_694 . V_695 -> V_192 = V_128 ;
V_687 -> V_694 . V_695 -> V_238 = 0 ;
if ( V_699 < V_707 ) {
V_687 -> V_694 . V_695 -> V_699 = ( V_37 ) V_699 ;
V_687 -> V_694 . V_699 = ( V_37 ) V_699 ;
V_687 -> V_694 . V_696 = 0 ;
} else {
V_687 -> V_694 . V_695 -> V_699 = 0 ;
V_687 -> V_694 . V_699 = 0 ;
V_687 -> V_694 . V_696 = 1 ;
}
V_192 = F_293 ( V_687 ) ;
if ( V_192 == V_128 ) {
F_202 ( V_64 , & V_687 -> V_694 . V_456 ,
F_292 , V_687 ,
V_734 ) ;
V_687 -> V_694 . V_697 = 1 ;
}
return V_192 ;
}
T_6
F_302 ( struct V_63 * V_64 )
{
struct V_686 * V_687 = F_287 ( V_64 ) ;
return V_687 -> V_688 . V_689 ? V_464 : V_128 ;
}
