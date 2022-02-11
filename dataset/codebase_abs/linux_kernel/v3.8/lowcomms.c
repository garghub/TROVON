static void F_1 ( struct V_1 * V_2 , int V_3 )
{
V_2 -> V_4 += V_3 ;
}
static int F_2 ( struct V_1 * V_2 )
{
return ( ( V_2 -> V_5 + V_2 -> V_4 ) & V_2 -> V_6 ) ;
}
static void F_3 ( struct V_1 * V_2 , int V_7 )
{
V_2 -> V_5 = V_2 -> V_4 = 0 ;
V_2 -> V_6 = V_7 - 1 ;
}
static void F_4 ( struct V_1 * V_2 , int V_3 )
{
V_2 -> V_4 -= V_3 ;
V_2 -> V_5 += V_3 ;
V_2 -> V_5 &= V_2 -> V_6 ;
}
static bool F_5 ( struct V_1 * V_2 )
{
return V_2 -> V_4 == 0 ;
}
static inline int F_6 ( int V_8 )
{
return V_8 & ( V_9 - 1 ) ;
}
static struct V_10 * F_7 ( int V_8 )
{
int V_11 ;
struct V_12 * V_13 ;
struct V_10 * V_14 ;
V_11 = F_6 ( V_8 ) ;
F_8 (con, h, &connection_hash[r], list) {
if ( V_14 -> V_8 == V_8 )
return V_14 ;
}
return NULL ;
}
static struct V_10 * F_9 ( int V_8 , T_1 V_15 )
{
struct V_10 * V_14 = NULL ;
int V_11 ;
V_14 = F_7 ( V_8 ) ;
if ( V_14 || ! V_15 )
return V_14 ;
V_14 = F_10 ( V_16 , V_15 ) ;
if ( ! V_14 )
return NULL ;
V_11 = F_6 ( V_8 ) ;
F_11 ( & V_14 -> V_17 , & V_18 [ V_11 ] ) ;
V_14 -> V_8 = V_8 ;
F_12 ( & V_14 -> V_19 ) ;
F_13 ( & V_14 -> V_20 ) ;
F_14 ( & V_14 -> V_21 ) ;
F_15 ( & V_14 -> V_22 , V_23 ) ;
F_15 ( & V_14 -> V_24 , V_25 ) ;
if ( V_14 -> V_8 ) {
struct V_10 * V_26 = F_7 ( 0 ) ;
V_14 -> V_27 = V_26 -> V_27 ;
if ( ! V_14 -> V_28 )
V_14 -> V_28 = V_26 -> V_28 ;
}
return V_14 ;
}
static void F_16 ( void (* F_17)( struct V_10 * V_29 ) )
{
int V_30 ;
struct V_12 * V_13 , * V_3 ;
struct V_10 * V_14 ;
for ( V_30 = 0 ; V_30 < V_9 ; V_30 ++ ) {
F_18 (con, h, n, &connection_hash[i], list) {
F_17 ( V_14 ) ;
}
}
}
static struct V_10 * F_19 ( int V_8 , T_1 V_31 )
{
struct V_10 * V_14 ;
F_20 ( & V_32 ) ;
V_14 = F_9 ( V_8 , V_31 ) ;
F_21 ( & V_32 ) ;
return V_14 ;
}
static struct V_10 * F_22 ( int V_33 )
{
int V_30 ;
struct V_12 * V_13 ;
struct V_10 * V_14 ;
F_20 ( & V_32 ) ;
for ( V_30 = 0 ; V_30 < V_9 ; V_30 ++ ) {
F_8 (con, h, &connection_hash[i], list) {
if ( V_14 -> V_34 == V_33 ) {
F_21 ( & V_32 ) ;
return V_14 ;
}
}
}
F_21 ( & V_32 ) ;
return NULL ;
}
static struct V_35 * F_23 ( int V_8 )
{
struct V_35 * V_36 ;
F_24 (na, &dlm_node_addrs, list) {
if ( V_36 -> V_8 == V_8 )
return V_36 ;
}
return NULL ;
}
static int F_25 ( struct V_37 * V_38 , struct V_37 * V_39 )
{
switch ( V_38 -> V_40 ) {
case V_41 : {
struct V_42 * V_43 = (struct V_42 * ) V_38 ;
struct V_42 * V_44 = (struct V_42 * ) V_39 ;
if ( V_43 -> V_45 . V_46 != V_44 -> V_45 . V_46 )
return 0 ;
if ( V_43 -> V_47 != V_44 -> V_47 )
return 0 ;
break;
}
case V_48 : {
struct V_49 * V_43 = (struct V_49 * ) V_38 ;
struct V_49 * V_44 = (struct V_49 * ) V_39 ;
if ( ! F_26 ( & V_43 -> V_50 , & V_44 -> V_50 ) )
return 0 ;
if ( V_43 -> V_51 != V_44 -> V_51 )
return 0 ;
break;
}
default:
return 0 ;
}
return 1 ;
}
static int F_27 ( int V_8 , struct V_37 * V_52 ,
struct V_53 * V_54 )
{
struct V_37 V_55 ;
struct V_35 * V_36 ;
if ( ! V_56 )
return - 1 ;
F_28 ( & V_57 ) ;
V_36 = F_23 ( V_8 ) ;
if ( V_36 && V_36 -> V_58 )
memcpy ( & V_55 , V_36 -> V_59 [ 0 ] , sizeof( struct V_37 ) ) ;
F_29 ( & V_57 ) ;
if ( ! V_36 )
return - V_60 ;
if ( ! V_36 -> V_58 )
return - V_61 ;
if ( V_52 )
memcpy ( V_52 , & V_55 , sizeof( struct V_37 ) ) ;
if ( ! V_54 )
return 0 ;
if ( V_62 [ 0 ] -> V_40 == V_41 ) {
struct V_42 * V_63 = (struct V_42 * ) & V_55 ;
struct V_42 * V_64 = (struct V_42 * ) V_54 ;
V_64 -> V_45 . V_46 = V_63 -> V_45 . V_46 ;
} else {
struct V_49 * V_65 = (struct V_49 * ) & V_55 ;
struct V_49 * V_66 = (struct V_49 * ) V_54 ;
V_66 -> V_50 = V_65 -> V_50 ;
}
return 0 ;
}
static int F_30 ( struct V_37 * V_59 , int * V_8 )
{
struct V_35 * V_36 ;
int V_67 = - V_60 ;
F_28 ( & V_57 ) ;
F_24 (na, &dlm_node_addrs, list) {
if ( ! V_36 -> V_58 )
continue;
if ( ! F_25 ( V_36 -> V_59 [ 0 ] , V_59 ) )
continue;
* V_8 = V_36 -> V_8 ;
V_67 = 0 ;
break;
}
F_29 ( & V_57 ) ;
return V_67 ;
}
int F_31 ( int V_8 , struct V_37 * V_59 , int V_4 )
{
struct V_37 * V_68 ;
struct V_35 * V_69 , * V_36 ;
V_69 = F_32 ( sizeof( struct V_35 ) , V_70 ) ;
if ( ! V_69 )
return - V_71 ;
V_68 = F_32 ( sizeof( struct V_37 ) , V_70 ) ;
if ( ! V_68 ) {
F_33 ( V_69 ) ;
return - V_71 ;
}
memcpy ( V_68 , V_59 , V_4 ) ;
F_28 ( & V_57 ) ;
V_36 = F_23 ( V_8 ) ;
if ( ! V_36 ) {
V_69 -> V_8 = V_8 ;
V_69 -> V_59 [ 0 ] = V_68 ;
V_69 -> V_58 = 1 ;
F_34 ( & V_69 -> V_17 , & V_72 ) ;
F_29 ( & V_57 ) ;
return 0 ;
}
if ( V_36 -> V_58 >= V_73 ) {
F_29 ( & V_57 ) ;
F_33 ( V_68 ) ;
F_33 ( V_69 ) ;
return - V_74 ;
}
V_36 -> V_59 [ V_36 -> V_58 ++ ] = V_68 ;
F_29 ( & V_57 ) ;
F_33 ( V_69 ) ;
return 0 ;
}
static void F_35 ( struct V_75 * V_76 , int V_77 )
{
struct V_10 * V_14 = F_36 ( V_76 ) ;
if ( V_14 && ! F_37 ( V_78 , & V_14 -> V_79 ) )
F_38 ( V_80 , & V_14 -> V_24 ) ;
}
static void F_39 ( struct V_75 * V_76 )
{
struct V_10 * V_14 = F_36 ( V_76 ) ;
if ( ! V_14 )
return;
F_40 ( V_81 , & V_14 -> V_75 -> V_79 ) ;
if ( F_41 ( V_82 , & V_14 -> V_79 ) ) {
V_14 -> V_75 -> V_76 -> V_83 -- ;
F_40 ( V_84 , & V_14 -> V_75 -> V_79 ) ;
}
if ( ! F_37 ( V_85 , & V_14 -> V_79 ) )
F_38 ( V_86 , & V_14 -> V_22 ) ;
}
static inline void F_42 ( struct V_10 * V_14 )
{
if ( F_43 ( V_87 , & V_14 -> V_79 ) )
return;
if ( ! F_37 ( V_88 , & V_14 -> V_79 ) )
F_38 ( V_86 , & V_14 -> V_22 ) ;
}
static void F_44 ( struct V_75 * V_76 )
{
if ( V_76 -> V_89 == V_90 )
F_39 ( V_76 ) ;
}
int F_45 ( int V_8 )
{
struct V_10 * V_14 ;
if ( V_91 . V_92 != 0 )
return 0 ;
if ( V_8 == F_46 () )
return 0 ;
V_14 = F_19 ( V_8 , V_70 ) ;
if ( ! V_14 )
return - V_71 ;
F_42 ( V_14 ) ;
return 0 ;
}
static void F_47 ( struct V_93 * V_75 , struct V_10 * V_14 )
{
V_14 -> V_75 = V_75 ;
V_14 -> V_75 -> V_76 -> V_94 = F_35 ;
V_14 -> V_75 -> V_76 -> V_95 = F_39 ;
V_14 -> V_75 -> V_76 -> V_96 = F_44 ;
V_14 -> V_75 -> V_76 -> V_97 = V_14 ;
V_14 -> V_75 -> V_76 -> V_98 = V_70 ;
}
static void F_48 ( struct V_37 * V_99 , T_2 V_100 ,
int * V_101 )
{
V_99 -> V_40 = V_62 [ 0 ] -> V_40 ;
if ( V_99 -> V_40 == V_41 ) {
struct V_42 * V_102 = (struct V_42 * ) V_99 ;
V_102 -> V_47 = F_49 ( V_100 ) ;
* V_101 = sizeof( struct V_42 ) ;
memset ( & V_102 -> V_103 , 0 , sizeof( V_102 -> V_103 ) ) ;
} else {
struct V_49 * V_104 = (struct V_49 * ) V_99 ;
V_104 -> V_51 = F_49 ( V_100 ) ;
* V_101 = sizeof( struct V_49 ) ;
}
memset ( ( char * ) V_99 + * V_101 , 0 , sizeof( struct V_37 ) - * V_101 ) ;
}
static void F_50 ( struct V_10 * V_14 , bool V_105 )
{
F_20 ( & V_14 -> V_19 ) ;
if ( V_14 -> V_75 ) {
F_51 ( V_14 -> V_75 ) ;
V_14 -> V_75 = NULL ;
}
if ( V_14 -> V_106 && V_105 ) {
F_50 ( V_14 -> V_106 , false ) ;
}
if ( V_14 -> V_107 ) {
F_52 ( V_14 -> V_107 ) ;
V_14 -> V_107 = NULL ;
}
V_14 -> V_108 = 0 ;
F_21 ( & V_14 -> V_19 ) ;
}
static void F_53 ( T_3 V_109 )
{
static char V_110 [ F_54 ( sizeof( struct V_111 ) ) ] ;
struct V_112 V_113 ;
struct V_114 * V_115 ;
struct V_111 * V_116 ;
int V_117 ;
struct V_10 * V_14 ;
V_14 = F_19 ( 0 , 0 ) ;
F_55 ( V_14 == NULL ) ;
V_113 . V_118 = NULL ;
V_113 . V_119 = 0 ;
V_113 . V_120 = V_110 ;
V_113 . V_121 = sizeof( V_110 ) ;
V_113 . V_122 = V_123 ;
V_115 = F_56 ( & V_113 ) ;
V_115 -> V_124 = V_125 ;
V_115 -> V_126 = V_127 ;
V_115 -> V_128 = F_57 ( sizeof( struct V_111 ) ) ;
V_113 . V_121 = V_115 -> V_128 ;
V_116 = F_58 ( V_115 ) ;
memset ( V_116 , 0x00 , sizeof( struct V_111 ) ) ;
V_116 -> V_129 |= V_130 ;
V_116 -> V_131 = V_109 ;
V_117 = F_59 ( V_14 -> V_75 , & V_113 , NULL , 0 , 0 ) ;
if ( V_117 != 0 )
F_60 ( L_1 , V_117 ) ;
}
static void F_61 ( struct V_10 * V_14 )
{
V_14 -> V_34 = 0 ;
if ( F_41 ( V_88 , & V_14 -> V_79 ) ) {
if ( ! F_37 ( V_85 , & V_14 -> V_79 ) )
F_38 ( V_86 , & V_14 -> V_22 ) ;
}
}
static void F_62 ( void )
{
F_20 ( & V_32 ) ;
F_16 ( F_61 ) ;
F_21 ( & V_32 ) ;
}
static void F_63 ( struct V_10 * V_14 ,
struct V_112 * V_132 , char * V_133 )
{
union V_134 * V_135 = (union V_134 * ) V_133 ;
if ( V_135 -> V_136 . V_137 == V_138 ) {
switch ( V_135 -> V_139 . V_140 ) {
case V_141 :
case V_142 :
{
struct V_143 V_144 ;
int V_8 ;
int V_145 , V_117 ;
int V_101 ;
struct V_10 * V_146 ;
if ( ( int ) V_135 -> V_139 . V_147 <= 0 ) {
F_60 ( L_2 ,
( int ) V_135 -> V_139 . V_147 ) ;
F_62 () ;
return;
}
memset ( & V_144 , 0 , sizeof( struct V_143 ) ) ;
V_145 = sizeof( struct V_143 ) ;
V_144 . V_148 = V_135 -> V_139 . V_147 ;
V_117 = F_64 ( V_14 -> V_75 ,
V_125 ,
V_149 ,
( char * ) & V_144 ,
& V_145 ) ;
if ( V_117 < 0 ) {
F_60 ( L_3
L_4 ,
( int ) V_135 -> V_139 . V_147 ,
V_117 ) ;
V_146 = F_22 ( V_135 -> V_139 . V_147 ) ;
if ( V_146 )
F_40 ( V_88 , & V_14 -> V_79 ) ;
return;
}
F_48 ( & V_144 . V_150 , 0 , & V_101 ) ;
if ( F_30 ( & V_144 . V_150 , & V_8 ) ) {
unsigned char * V_151 = ( unsigned char * ) & V_144 . V_150 ;
F_60 ( L_5 ) ;
F_65 ( L_6 , V_152 ,
V_151 , sizeof( struct V_37 ) ) ;
F_53 ( V_144 . V_148 ) ;
return;
}
V_146 = F_19 ( V_8 , V_70 ) ;
if ( ! V_146 )
return;
F_66 ( V_14 -> V_75 -> V_76 ) ;
V_117 = F_67 ( V_14 -> V_75 -> V_76 ,
V_135 -> V_139 . V_147 ,
& V_146 -> V_75 ) ;
F_68 ( V_14 -> V_75 -> V_76 ) ;
if ( V_117 < 0 ) {
F_60 ( L_7
L_8 ,
( int ) V_135 -> V_139 . V_147 ,
V_8 , V_117 ) ;
return;
}
F_47 ( V_146 -> V_75 , V_146 ) ;
F_60 ( L_9 ,
V_8 , ( int ) V_135 -> V_139 . V_147 ) ;
F_40 ( V_88 , & V_146 -> V_79 ) ;
F_40 ( V_153 , & V_14 -> V_79 ) ;
if ( ! F_37 ( V_85 , & V_146 -> V_79 ) ) {
F_38 ( V_86 , & V_146 -> V_22 ) ;
}
if ( ! F_37 ( V_78 , & V_146 -> V_79 ) )
F_38 ( V_80 , & V_146 -> V_24 ) ;
}
break;
case V_154 :
case V_155 :
{
V_14 = F_22 ( V_135 -> V_139 . V_147 ) ;
if ( V_14 ) {
V_14 -> V_34 = 0 ;
}
}
break;
case V_156 :
{
F_60 ( L_10 ) ;
F_62 () ;
}
break;
default:
F_60 ( L_11 ,
( int ) V_135 -> V_139 . V_147 ,
V_135 -> V_139 . V_140 ) ;
}
}
}
static int F_69 ( struct V_10 * V_14 )
{
int V_117 = 0 ;
struct V_112 V_132 = {} ;
struct V_157 V_158 [ 2 ] ;
unsigned V_4 ;
int V_11 ;
int V_159 = 0 ;
int V_160 ;
char V_161 [ F_54 ( sizeof( struct V_111 ) ) ] ;
F_20 ( & V_14 -> V_19 ) ;
if ( V_14 -> V_75 == NULL ) {
V_117 = - V_162 ;
goto V_163;
}
if ( V_14 -> V_107 == NULL ) {
V_14 -> V_107 = F_70 ( V_164 ) ;
if ( V_14 -> V_107 == NULL )
goto V_165;
F_3 ( & V_14 -> V_2 , V_166 ) ;
}
memset ( & V_161 , 0 , sizeof( V_161 ) ) ;
V_132 . V_120 = V_161 ;
V_132 . V_121 = sizeof( V_161 ) ;
V_158 [ 0 ] . V_167 = V_14 -> V_2 . V_5 - F_2 ( & V_14 -> V_2 ) ;
V_158 [ 0 ] . V_168 = F_71 ( V_14 -> V_107 ) + F_2 ( & V_14 -> V_2 ) ;
V_158 [ 1 ] . V_167 = 0 ;
V_160 = 1 ;
if ( F_2 ( & V_14 -> V_2 ) >= V_14 -> V_2 . V_5 ) {
V_158 [ 0 ] . V_167 = V_166 - F_2 ( & V_14 -> V_2 ) ;
V_158 [ 1 ] . V_167 = V_14 -> V_2 . V_5 ;
V_158 [ 1 ] . V_168 = F_71 ( V_14 -> V_107 ) ;
V_160 = 2 ;
}
V_4 = V_158 [ 0 ] . V_167 + V_158 [ 1 ] . V_167 ;
V_11 = V_117 = F_72 ( V_14 -> V_75 , & V_132 , V_158 , V_160 , V_4 ,
V_169 | V_170 ) ;
if ( V_117 <= 0 )
goto V_163;
if ( V_132 . V_122 & V_171 ) {
V_132 . V_120 = V_161 ;
V_132 . V_121 = sizeof( V_161 ) ;
F_63 ( V_14 , & V_132 ,
F_71 ( V_14 -> V_107 ) + V_14 -> V_2 . V_5 ) ;
F_21 ( & V_14 -> V_19 ) ;
return 0 ;
}
F_55 ( V_14 -> V_8 == 0 ) ;
if ( V_117 == V_4 )
V_159 = 1 ;
F_1 ( & V_14 -> V_2 , V_117 ) ;
V_117 = F_73 ( V_14 -> V_8 ,
F_71 ( V_14 -> V_107 ) ,
V_14 -> V_2 . V_5 , V_14 -> V_2 . V_4 ,
V_166 ) ;
if ( V_117 == - V_172 ) {
F_60 ( L_12
L_13 ,
F_71 ( V_14 -> V_107 ) , V_14 -> V_2 . V_5 , V_14 -> V_2 . V_4 ,
V_4 , V_158 [ 0 ] . V_168 , V_11 ) ;
}
if ( V_117 < 0 )
goto V_163;
F_4 ( & V_14 -> V_2 , V_117 ) ;
if ( F_5 ( & V_14 -> V_2 ) && ! V_159 ) {
F_52 ( V_14 -> V_107 ) ;
V_14 -> V_107 = NULL ;
}
if ( V_159 )
goto V_165;
F_21 ( & V_14 -> V_19 ) ;
return 0 ;
V_165:
if ( ! F_37 ( V_78 , & V_14 -> V_79 ) )
F_38 ( V_80 , & V_14 -> V_24 ) ;
F_21 ( & V_14 -> V_19 ) ;
return - V_162 ;
V_163:
F_21 ( & V_14 -> V_19 ) ;
if ( V_117 != - V_162 ) {
F_50 ( V_14 , false ) ;
}
if ( V_117 == 0 )
V_117 = - V_162 ;
return V_117 ;
}
static int F_74 ( struct V_10 * V_14 )
{
int V_173 ;
struct V_37 V_174 ;
struct V_93 * V_175 ;
int V_4 ;
int V_8 ;
struct V_10 * V_176 ;
struct V_10 * V_177 ;
F_20 ( & V_32 ) ;
if ( ! V_178 ) {
F_21 ( & V_32 ) ;
return - 1 ;
}
F_21 ( & V_32 ) ;
memset ( & V_174 , 0 , sizeof( V_174 ) ) ;
V_173 = F_75 ( V_62 [ 0 ] -> V_40 , V_179 ,
V_180 , & V_175 ) ;
if ( V_173 < 0 )
return - V_71 ;
F_76 ( & V_14 -> V_19 , 0 ) ;
V_173 = - V_181 ;
if ( V_14 -> V_75 == NULL )
goto V_182;
V_175 -> type = V_14 -> V_75 -> type ;
V_175 -> V_183 = V_14 -> V_75 -> V_183 ;
V_173 = V_14 -> V_75 -> V_183 -> V_184 ( V_14 -> V_75 , V_175 , V_185 ) ;
if ( V_173 < 0 )
goto V_182;
memset ( & V_174 , 0 , sizeof( V_174 ) ) ;
if ( V_175 -> V_183 -> V_186 ( V_175 , (struct V_53 * ) & V_174 ,
& V_4 , 2 ) ) {
V_173 = - V_187 ;
goto V_182;
}
F_48 ( & V_174 , 0 , & V_4 ) ;
if ( F_30 ( & V_174 , & V_8 ) ) {
unsigned char * V_151 = ( unsigned char * ) & V_174 ;
F_60 ( L_14 ) ;
F_65 ( L_6 , V_152 ,
V_151 , sizeof( struct V_37 ) ) ;
F_51 ( V_175 ) ;
F_21 ( & V_14 -> V_19 ) ;
return - 1 ;
}
F_60 ( L_15 , V_8 ) ;
V_176 = F_19 ( V_8 , V_70 ) ;
if ( ! V_176 ) {
V_173 = - V_71 ;
goto V_182;
}
F_76 ( & V_176 -> V_19 , 1 ) ;
if ( V_176 -> V_75 ) {
struct V_10 * V_106 = V_176 -> V_106 ;
if ( ! V_106 ) {
V_106 = F_10 ( V_16 , V_70 ) ;
if ( ! V_106 ) {
F_60 ( L_16 ) ;
F_21 ( & V_176 -> V_19 ) ;
V_173 = - V_71 ;
goto V_182;
}
V_106 -> V_8 = V_8 ;
V_106 -> V_28 = F_69 ;
F_12 ( & V_106 -> V_19 ) ;
F_15 ( & V_106 -> V_22 , V_23 ) ;
F_15 ( & V_106 -> V_24 , V_25 ) ;
F_77 ( V_188 , & V_106 -> V_79 ) ;
}
if ( ! V_106 -> V_75 ) {
V_176 -> V_106 = V_106 ;
V_106 -> V_75 = V_175 ;
V_175 -> V_76 -> V_97 = V_106 ;
F_47 ( V_175 , V_106 ) ;
V_177 = V_106 ;
}
else {
F_78 ( L_17 , V_8 ) ;
V_173 = - V_162 ;
F_21 ( & V_176 -> V_19 ) ;
goto V_182;
}
}
else {
V_175 -> V_76 -> V_97 = V_176 ;
V_176 -> V_28 = F_69 ;
F_47 ( V_175 , V_176 ) ;
V_177 = V_176 ;
}
F_21 ( & V_176 -> V_19 ) ;
if ( ! F_37 ( V_78 , & V_177 -> V_79 ) )
F_38 ( V_80 , & V_177 -> V_24 ) ;
F_21 ( & V_14 -> V_19 ) ;
return 0 ;
V_182:
F_21 ( & V_14 -> V_19 ) ;
F_51 ( V_175 ) ;
if ( V_173 != - V_162 )
F_60 ( L_18 , V_173 ) ;
return V_173 ;
}
static void F_79 ( struct V_189 * V_190 )
{
F_52 ( V_190 -> V_191 ) ;
F_33 ( V_190 ) ;
}
static void F_80 ( struct V_10 * V_14 )
{
struct V_37 V_192 ;
char V_110 [ F_54 ( sizeof( struct V_111 ) ) ] ;
struct V_112 V_113 ;
struct V_114 * V_115 ;
struct V_111 * V_116 ;
struct V_10 * V_193 ;
struct V_189 * V_190 ;
int V_4 , V_194 ;
int V_117 ;
int V_195 ;
struct V_157 V_158 [ 1 ] ;
if ( F_37 ( V_153 , & V_14 -> V_79 ) )
return;
if ( V_14 -> V_108 ++ > V_196 )
return;
if ( F_27 ( V_14 -> V_8 , NULL , (struct V_53 * ) & V_192 ) ) {
F_60 ( L_19 , V_14 -> V_8 ) ;
return;
}
V_193 = F_19 ( 0 , 0 ) ;
F_55 ( V_193 == NULL ) ;
F_48 ( & V_192 , V_91 . V_197 , & V_195 ) ;
V_113 . V_118 = & V_192 ;
V_113 . V_119 = V_195 ;
V_113 . V_120 = V_110 ;
V_113 . V_121 = sizeof( V_110 ) ;
V_113 . V_122 = V_123 ;
F_28 ( & V_14 -> V_21 ) ;
if ( F_81 ( & V_14 -> V_20 ) ) {
F_29 ( & V_14 -> V_21 ) ;
F_60 ( L_20 , V_14 -> V_8 ) ;
return;
}
V_190 = F_82 ( & V_14 -> V_20 , struct V_189 , V_17 ) ;
V_4 = V_190 -> V_4 ;
V_194 = V_190 -> V_194 ;
F_29 ( & V_14 -> V_21 ) ;
V_158 [ 0 ] . V_168 = F_71 ( V_190 -> V_191 ) + V_194 ;
V_158 [ 0 ] . V_167 = V_4 ;
V_115 = F_56 ( & V_113 ) ;
V_115 -> V_124 = V_125 ;
V_115 -> V_126 = V_127 ;
V_115 -> V_128 = F_57 ( sizeof( struct V_111 ) ) ;
V_116 = F_58 ( V_115 ) ;
memset ( V_116 , 0x00 , sizeof( struct V_111 ) ) ;
V_116 -> V_198 = F_83 ( F_46 () ) ;
V_113 . V_121 = V_115 -> V_128 ;
V_117 = F_59 ( V_193 -> V_75 , & V_113 , V_158 , 1 , V_4 ) ;
if ( V_117 < 0 ) {
F_60 ( L_21 ,
V_14 -> V_8 , V_117 ) ;
F_40 ( V_88 , & V_14 -> V_79 ) ;
F_40 ( V_153 , & V_14 -> V_79 ) ;
}
else {
F_28 ( & V_14 -> V_21 ) ;
V_190 -> V_194 += V_117 ;
V_190 -> V_4 -= V_117 ;
if ( V_190 -> V_4 == 0 && V_190 -> V_199 == 0 ) {
F_84 ( & V_190 -> V_17 ) ;
F_79 ( V_190 ) ;
}
F_29 ( & V_14 -> V_21 ) ;
}
}
static void F_85 ( struct V_10 * V_14 )
{
struct V_37 V_99 , V_200 ;
int V_101 ;
struct V_93 * V_75 = NULL ;
int V_201 = 1 ;
int V_173 ;
if ( V_14 -> V_8 == 0 ) {
F_60 ( L_22 ) ;
return;
}
F_20 ( & V_14 -> V_19 ) ;
if ( V_14 -> V_108 ++ > V_196 )
goto V_202;
if ( V_14 -> V_75 )
goto V_202;
V_173 = F_75 ( V_62 [ 0 ] -> V_40 , V_179 ,
V_180 , & V_75 ) ;
if ( V_173 < 0 )
goto V_203;
memset ( & V_99 , 0 , sizeof( V_99 ) ) ;
V_173 = F_27 ( V_14 -> V_8 , & V_99 , NULL ) ;
if ( V_173 < 0 ) {
F_60 ( L_19 , V_14 -> V_8 ) ;
goto V_203;
}
V_75 -> V_76 -> V_97 = V_14 ;
V_14 -> V_28 = F_69 ;
V_14 -> V_27 = F_85 ;
F_47 ( V_75 , V_14 ) ;
memcpy ( & V_200 , V_62 [ 0 ] , sizeof( V_200 ) ) ;
F_48 ( & V_200 , 0 , & V_101 ) ;
V_173 = V_75 -> V_183 -> V_204 ( V_75 , (struct V_53 * ) & V_200 ,
V_101 ) ;
if ( V_173 < 0 ) {
F_60 ( L_23 , V_173 ) ;
}
F_48 ( & V_99 , V_91 . V_197 , & V_101 ) ;
F_60 ( L_24 , V_14 -> V_8 ) ;
F_86 ( V_75 , V_205 , V_206 , ( char * ) & V_201 ,
sizeof( V_201 ) ) ;
V_173 = V_75 -> V_183 -> V_207 ( V_75 , (struct V_53 * ) & V_99 , V_101 ,
V_185 ) ;
if ( V_173 == - V_208 )
V_173 = 0 ;
if ( V_173 == 0 )
goto V_202;
V_203:
if ( V_14 -> V_75 ) {
F_51 ( V_14 -> V_75 ) ;
V_14 -> V_75 = NULL ;
} else if ( V_75 ) {
F_51 ( V_75 ) ;
}
if ( V_173 != - V_209 &&
V_173 != - V_210 &&
V_173 != - V_211 &&
V_173 != - V_212 &&
V_173 != - V_213 ) {
F_60 ( L_25 , V_14 -> V_8 ,
V_14 -> V_108 , V_173 ) ;
F_21 ( & V_14 -> V_19 ) ;
F_87 ( 1000 ) ;
F_42 ( V_14 ) ;
return;
}
V_202:
F_21 ( & V_14 -> V_19 ) ;
return;
}
static struct V_93 * F_88 ( struct V_10 * V_14 ,
struct V_37 * V_99 )
{
struct V_93 * V_75 = NULL ;
int V_173 = 0 ;
int V_201 = 1 ;
int V_101 ;
if ( V_62 [ 0 ] -> V_40 == V_41 )
V_101 = sizeof( struct V_42 ) ;
else
V_101 = sizeof( struct V_49 ) ;
V_173 = F_75 ( V_62 [ 0 ] -> V_40 , V_179 ,
V_180 , & V_75 ) ;
if ( V_173 < 0 ) {
F_60 ( L_26 ) ;
goto V_214;
}
F_86 ( V_75 , V_205 , V_206 , ( char * ) & V_201 ,
sizeof( V_201 ) ) ;
V_173 = F_86 ( V_75 , V_215 , V_216 ,
( char * ) & V_201 , sizeof( V_201 ) ) ;
if ( V_173 < 0 ) {
F_60 ( L_27 , V_173 ) ;
}
V_14 -> V_28 = F_74 ;
V_14 -> V_27 = F_85 ;
F_48 ( V_99 , V_91 . V_197 , & V_101 ) ;
V_173 = V_75 -> V_183 -> V_204 ( V_75 , (struct V_53 * ) V_99 , V_101 ) ;
if ( V_173 < 0 ) {
F_60 ( L_28 , V_91 . V_197 ) ;
F_51 ( V_75 ) ;
V_75 = NULL ;
V_14 -> V_75 = NULL ;
goto V_214;
}
V_173 = F_86 ( V_75 , V_215 , V_217 ,
( char * ) & V_201 , sizeof( V_201 ) ) ;
if ( V_173 < 0 ) {
F_60 ( L_29 , V_173 ) ;
}
V_173 = V_75 -> V_183 -> V_218 ( V_75 , 5 ) ;
if ( V_173 < 0 ) {
F_60 ( L_30 , V_91 . V_197 ) ;
F_51 ( V_75 ) ;
V_75 = NULL ;
goto V_214;
}
V_214:
return V_75 ;
}
static void F_89 ( void )
{
struct V_37 V_55 , * V_59 ;
int V_30 ;
V_56 = 0 ;
for ( V_30 = 0 ; V_30 < V_73 ; V_30 ++ ) {
if ( F_90 ( & V_55 , V_30 ) )
break;
V_59 = F_91 ( sizeof( * V_59 ) , V_70 ) ;
if ( ! V_59 )
break;
memcpy ( V_59 , & V_55 , sizeof( * V_59 ) ) ;
V_62 [ V_56 ++ ] = V_59 ;
}
}
static int F_92 ( struct V_10 * V_219 ,
struct V_37 * V_59 ,
int V_101 , int V_220 )
{
int V_173 = 0 ;
if ( V_220 == 1 )
V_173 = F_93 ( V_219 -> V_75 ,
(struct V_53 * ) V_59 ,
V_101 ) ;
else
V_173 = F_86 ( V_219 -> V_75 , V_221 ,
V_222 ,
( char * ) V_59 , V_101 ) ;
if ( V_173 < 0 )
F_60 ( L_31 ,
V_91 . V_197 , V_220 ) ;
return V_173 ;
}
static int F_94 ( void )
{
struct V_93 * V_75 = NULL ;
struct V_37 V_223 ;
struct V_224 V_225 ;
int V_173 = - V_212 , V_220 = 1 , V_30 , V_101 ;
struct V_10 * V_14 = F_19 ( 0 , V_70 ) ;
int V_226 = V_227 ;
if ( ! V_14 )
return - V_71 ;
F_60 ( L_32 ) ;
V_173 = F_75 ( V_62 [ 0 ] -> V_40 , V_228 ,
V_125 , & V_75 ) ;
if ( V_173 < 0 ) {
F_60 ( L_33 ) ;
goto V_202;
}
memset ( & V_225 , 0 , sizeof( V_225 ) ) ;
V_225 . V_229 = 1 ;
V_225 . V_230 = 1 ;
V_225 . V_231 = 1 ;
V_225 . V_232 = 1 ;
V_225 . V_233 = 1 ;
V_173 = F_86 ( V_75 , V_215 , V_234 ,
( char * ) & V_226 , sizeof( V_226 ) ) ;
if ( V_173 )
F_60 ( L_34 , V_173 ) ;
V_173 = F_86 ( V_75 , V_221 , V_235 ,
( char * ) & V_225 , sizeof( V_225 ) ) ;
if ( V_173 < 0 ) {
F_60 ( L_35 ,
V_173 ) ;
goto V_236;
}
V_75 -> V_76 -> V_97 = V_14 ;
V_14 -> V_75 = V_75 ;
V_14 -> V_75 -> V_76 -> V_94 = F_35 ;
V_14 -> V_28 = F_69 ;
V_14 -> V_27 = F_80 ;
for ( V_30 = 0 ; V_30 < V_56 ; V_30 ++ ) {
memcpy ( & V_223 , V_62 [ V_30 ] , sizeof( V_223 ) ) ;
F_48 ( & V_223 , V_91 . V_197 , & V_101 ) ;
V_173 = F_92 ( V_14 , & V_223 , V_101 , V_220 ) ;
if ( V_173 )
goto V_236;
++ V_220 ;
}
V_173 = V_75 -> V_183 -> V_218 ( V_75 , 5 ) ;
if ( V_173 < 0 ) {
F_60 ( L_36 ) ;
goto V_236;
}
return 0 ;
V_236:
F_51 ( V_75 ) ;
V_14 -> V_75 = NULL ;
V_202:
return V_173 ;
}
static int F_95 ( void )
{
struct V_93 * V_75 = NULL ;
struct V_10 * V_14 = F_19 ( 0 , V_70 ) ;
int V_173 = - V_212 ;
if ( ! V_14 )
return - V_71 ;
if ( V_62 [ 1 ] != NULL ) {
F_60 ( L_37
L_38 ) ;
return - V_212 ;
}
F_60 ( L_39 ) ;
V_75 = F_88 ( V_14 , V_62 [ 0 ] ) ;
if ( V_75 ) {
F_47 ( V_75 , V_14 ) ;
V_173 = 0 ;
}
else {
V_173 = - V_237 ;
}
return V_173 ;
}
static struct V_189 * F_96 ( struct V_10 * V_14 ,
T_1 V_31 )
{
struct V_189 * V_238 ;
V_238 = F_91 ( sizeof( struct V_189 ) , V_31 ) ;
if ( ! V_238 )
return NULL ;
V_238 -> V_191 = F_70 ( V_31 ) ;
if ( ! V_238 -> V_191 ) {
F_33 ( V_238 ) ;
return NULL ;
}
V_238 -> V_194 = 0 ;
V_238 -> V_4 = 0 ;
V_238 -> V_239 = 0 ;
V_238 -> V_199 = 0 ;
V_238 -> V_14 = V_14 ;
return V_238 ;
}
void * F_97 ( int V_8 , int V_4 , T_1 V_31 , char * * V_240 )
{
struct V_10 * V_14 ;
struct V_189 * V_190 ;
int V_194 = 0 ;
V_14 = F_19 ( V_8 , V_31 ) ;
if ( ! V_14 )
return NULL ;
F_28 ( & V_14 -> V_21 ) ;
V_190 = F_98 ( V_14 -> V_20 . V_241 , struct V_189 , V_17 ) ;
if ( ( & V_190 -> V_17 == & V_14 -> V_20 ) ||
( V_166 - V_190 -> V_239 < V_4 ) ) {
V_190 = NULL ;
} else {
V_194 = V_190 -> V_239 ;
V_190 -> V_239 += V_4 ;
V_190 -> V_199 ++ ;
}
F_29 ( & V_14 -> V_21 ) ;
if ( V_190 ) {
V_242:
* V_240 = F_71 ( V_190 -> V_191 ) + V_194 ;
return V_190 ;
}
V_190 = F_96 ( V_14 , V_31 ) ;
if ( V_190 ) {
F_28 ( & V_14 -> V_21 ) ;
V_194 = V_190 -> V_239 ;
V_190 -> V_239 += V_4 ;
V_190 -> V_199 ++ ;
F_99 ( & V_190 -> V_17 , & V_14 -> V_20 ) ;
F_29 ( & V_14 -> V_21 ) ;
goto V_242;
}
return NULL ;
}
void F_100 ( void * V_243 )
{
struct V_189 * V_190 = (struct V_189 * ) V_243 ;
struct V_10 * V_14 = V_190 -> V_14 ;
int V_199 ;
F_28 ( & V_14 -> V_21 ) ;
V_199 = -- V_190 -> V_199 ;
if ( V_199 )
goto V_202;
V_190 -> V_4 = V_190 -> V_239 - V_190 -> V_194 ;
F_29 ( & V_14 -> V_21 ) ;
if ( ! F_37 ( V_85 , & V_14 -> V_79 ) ) {
F_38 ( V_86 , & V_14 -> V_22 ) ;
}
return;
V_202:
F_29 ( & V_14 -> V_21 ) ;
return;
}
static void F_101 ( struct V_10 * V_14 )
{
int V_117 = 0 ;
const int V_122 = V_169 | V_170 ;
struct V_189 * V_190 ;
int V_4 , V_194 ;
int V_244 = 0 ;
F_20 ( & V_14 -> V_19 ) ;
if ( V_14 -> V_75 == NULL )
goto V_245;
F_28 ( & V_14 -> V_21 ) ;
for (; ; ) {
V_190 = F_98 ( V_14 -> V_20 . V_246 , struct V_189 ,
V_17 ) ;
if ( (struct V_247 * ) V_190 == & V_14 -> V_20 )
break;
V_4 = V_190 -> V_4 ;
V_194 = V_190 -> V_194 ;
F_55 ( V_4 == 0 && V_190 -> V_199 == 0 ) ;
F_29 ( & V_14 -> V_21 ) ;
V_117 = 0 ;
if ( V_4 ) {
V_117 = F_102 ( V_14 -> V_75 , V_190 -> V_191 , V_194 , V_4 ,
V_122 ) ;
if ( V_117 == - V_162 || V_117 == 0 ) {
if ( V_117 == - V_162 &&
F_43 ( V_84 , & V_14 -> V_75 -> V_79 ) &&
! F_37 ( V_82 , & V_14 -> V_79 ) ) {
F_77 ( V_81 , & V_14 -> V_75 -> V_79 ) ;
V_14 -> V_75 -> V_76 -> V_83 ++ ;
}
F_103 () ;
goto V_202;
} else if ( V_117 < 0 )
goto V_248;
}
if ( ++ V_244 >= V_249 ) {
F_103 () ;
V_244 = 0 ;
}
F_28 ( & V_14 -> V_21 ) ;
V_190 -> V_194 += V_117 ;
V_190 -> V_4 -= V_117 ;
if ( V_190 -> V_4 == 0 && V_190 -> V_199 == 0 ) {
F_84 ( & V_190 -> V_17 ) ;
F_79 ( V_190 ) ;
}
}
F_29 ( & V_14 -> V_21 ) ;
V_202:
F_21 ( & V_14 -> V_19 ) ;
return;
V_248:
F_21 ( & V_14 -> V_19 ) ;
F_50 ( V_14 , false ) ;
F_42 ( V_14 ) ;
return;
V_245:
F_21 ( & V_14 -> V_19 ) ;
if ( ! F_43 ( V_153 , & V_14 -> V_79 ) )
F_42 ( V_14 ) ;
}
static void F_104 ( struct V_10 * V_14 )
{
struct V_189 * V_190 , * V_250 ;
F_28 ( & V_14 -> V_21 ) ;
F_105 (e, safe, &con->writequeue, list) {
F_84 ( & V_190 -> V_17 ) ;
F_79 ( V_190 ) ;
}
F_29 ( & V_14 -> V_21 ) ;
}
int F_106 ( int V_8 )
{
struct V_10 * V_14 ;
struct V_35 * V_36 ;
F_60 ( L_40 , V_8 ) ;
V_14 = F_19 ( V_8 , 0 ) ;
if ( V_14 ) {
F_40 ( V_88 , & V_14 -> V_79 ) ;
F_40 ( V_85 , & V_14 -> V_79 ) ;
F_77 ( V_87 , & V_14 -> V_79 ) ;
if ( F_107 ( & V_14 -> V_22 ) )
F_60 ( L_41 , V_8 ) ;
if ( F_107 ( & V_14 -> V_24 ) )
F_60 ( L_42 , V_8 ) ;
F_104 ( V_14 ) ;
F_50 ( V_14 , true ) ;
}
F_28 ( & V_57 ) ;
V_36 = F_23 ( V_8 ) ;
if ( V_36 ) {
F_84 ( & V_36 -> V_17 ) ;
while ( V_36 -> V_58 -- )
F_33 ( V_36 -> V_59 [ V_36 -> V_58 ] ) ;
F_33 ( V_36 ) ;
}
F_29 ( & V_57 ) ;
return 0 ;
}
static void V_25 ( struct V_251 * V_252 )
{
struct V_10 * V_14 = F_108 ( V_252 , struct V_10 , V_24 ) ;
int V_253 ;
F_40 ( V_78 , & V_14 -> V_79 ) ;
do {
V_253 = V_14 -> V_28 ( V_14 ) ;
} while ( ! V_253 );
}
static void V_23 ( struct V_251 * V_252 )
{
struct V_10 * V_14 = F_108 ( V_252 , struct V_10 , V_22 ) ;
if ( F_41 ( V_88 , & V_14 -> V_79 ) ) {
V_14 -> V_27 ( V_14 ) ;
F_77 ( V_85 , & V_14 -> V_79 ) ;
}
if ( F_41 ( V_85 , & V_14 -> V_79 ) )
F_101 ( V_14 ) ;
}
static void F_109 ( void )
{
F_16 ( F_104 ) ;
}
static void F_110 ( void )
{
F_111 ( V_80 ) ;
F_111 ( V_86 ) ;
}
static int F_112 ( void )
{
V_80 = F_113 ( L_43 ,
V_254 | V_255 , 1 ) ;
if ( ! V_80 ) {
F_60 ( L_44 ) ;
return - V_71 ;
}
V_86 = F_113 ( L_45 ,
V_254 | V_255 , 1 ) ;
if ( ! V_86 ) {
F_60 ( L_46 ) ;
F_111 ( V_80 ) ;
return - V_71 ;
}
return 0 ;
}
static void F_114 ( struct V_10 * V_14 )
{
V_14 -> V_79 |= 0x0F ;
if ( V_14 -> V_75 && V_14 -> V_75 -> V_76 )
V_14 -> V_75 -> V_76 -> V_97 = NULL ;
}
static void F_115 ( struct V_10 * V_14 )
{
F_50 ( V_14 , true ) ;
if ( V_14 -> V_106 )
F_116 ( V_16 , V_14 -> V_106 ) ;
F_117 ( & V_14 -> V_17 ) ;
F_116 ( V_16 , V_14 ) ;
}
void F_118 ( void )
{
F_20 ( & V_32 ) ;
V_178 = 0 ;
F_16 ( F_114 ) ;
F_21 ( & V_32 ) ;
F_110 () ;
F_20 ( & V_32 ) ;
F_109 () ;
F_16 ( F_115 ) ;
F_21 ( & V_32 ) ;
F_119 ( V_16 ) ;
}
int F_120 ( void )
{
int error = - V_212 ;
struct V_10 * V_14 ;
int V_30 ;
for ( V_30 = 0 ; V_30 < V_9 ; V_30 ++ )
F_121 ( & V_18 [ V_30 ] ) ;
F_89 () ;
if ( ! V_56 ) {
error = - V_181 ;
F_60 ( L_47 ) ;
goto V_256;
}
error = - V_71 ;
V_16 = F_122 ( L_48 , sizeof( struct V_10 ) ,
F_123 ( struct V_10 ) , 0 ,
NULL ) ;
if ( ! V_16 )
goto V_256;
error = F_112 () ;
if ( error )
goto V_257;
V_178 = 1 ;
if ( V_91 . V_92 == 0 )
error = F_95 () ;
else
error = F_94 () ;
if ( error )
goto V_258;
return 0 ;
V_258:
V_178 = 0 ;
V_14 = F_19 ( 0 , 0 ) ;
if ( V_14 ) {
F_50 ( V_14 , false ) ;
F_116 ( V_16 , V_14 ) ;
}
V_257:
F_119 ( V_16 ) ;
V_256:
return error ;
}
void F_124 ( void )
{
struct V_35 * V_36 , * V_250 ;
F_28 ( & V_57 ) ;
F_105 (na, safe, &dlm_node_addrs, list) {
F_84 ( & V_36 -> V_17 ) ;
while ( V_36 -> V_58 -- )
F_33 ( V_36 -> V_59 [ V_36 -> V_58 ] ) ;
F_33 ( V_36 ) ;
}
F_29 ( & V_57 ) ;
}
