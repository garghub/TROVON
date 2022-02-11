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
static int F_23 ( int V_8 , struct V_35 * V_36 )
{
struct V_37 V_38 ;
int error ;
if ( ! V_39 )
return - 1 ;
error = F_24 ( V_8 , & V_38 ) ;
if ( error )
return error ;
if ( V_40 [ 0 ] -> V_41 == V_42 ) {
struct V_43 * V_44 = (struct V_43 * ) & V_38 ;
struct V_43 * V_45 = (struct V_43 * ) V_36 ;
V_45 -> V_46 . V_47 = V_44 -> V_46 . V_47 ;
} else {
struct V_48 * V_49 = (struct V_48 * ) & V_38 ;
struct V_48 * V_50 = (struct V_48 * ) V_36 ;
F_25 ( & V_50 -> V_51 , & V_49 -> V_51 ) ;
}
return 0 ;
}
static void F_26 ( struct V_52 * V_53 , int V_54 )
{
struct V_10 * V_14 = F_27 ( V_53 ) ;
if ( V_14 && ! F_28 ( V_55 , & V_14 -> V_56 ) )
F_29 ( V_57 , & V_14 -> V_24 ) ;
}
static void F_30 ( struct V_52 * V_53 )
{
struct V_10 * V_14 = F_27 ( V_53 ) ;
if ( ! V_14 )
return;
F_31 ( V_58 , & V_14 -> V_52 -> V_56 ) ;
if ( F_32 ( V_59 , & V_14 -> V_56 ) ) {
V_14 -> V_52 -> V_53 -> V_60 -- ;
F_31 ( V_61 , & V_14 -> V_52 -> V_56 ) ;
}
if ( ! F_28 ( V_62 , & V_14 -> V_56 ) )
F_29 ( V_63 , & V_14 -> V_22 ) ;
}
static inline void F_33 ( struct V_10 * V_14 )
{
if ( F_34 ( V_64 , & V_14 -> V_56 ) )
return;
if ( ! F_28 ( V_65 , & V_14 -> V_56 ) )
F_29 ( V_63 , & V_14 -> V_22 ) ;
}
static void F_35 ( struct V_52 * V_53 )
{
if ( V_53 -> V_66 == V_67 )
F_30 ( V_53 ) ;
}
int F_36 ( int V_8 )
{
struct V_10 * V_14 ;
if ( V_68 . V_69 != 0 )
return 0 ;
if ( V_8 == F_37 () )
return 0 ;
V_14 = F_19 ( V_8 , V_70 ) ;
if ( ! V_14 )
return - V_71 ;
F_33 ( V_14 ) ;
return 0 ;
}
static int F_38 ( struct V_72 * V_52 , struct V_10 * V_14 )
{
V_14 -> V_52 = V_52 ;
V_14 -> V_52 -> V_53 -> V_73 = F_26 ;
V_14 -> V_52 -> V_53 -> V_74 = F_30 ;
V_14 -> V_52 -> V_53 -> V_75 = F_35 ;
V_14 -> V_52 -> V_53 -> V_76 = V_14 ;
V_14 -> V_52 -> V_53 -> V_77 = V_70 ;
return 0 ;
}
static void F_39 ( struct V_37 * V_78 , T_2 V_79 ,
int * V_80 )
{
V_78 -> V_41 = V_40 [ 0 ] -> V_41 ;
if ( V_78 -> V_41 == V_42 ) {
struct V_43 * V_81 = (struct V_43 * ) V_78 ;
V_81 -> V_82 = F_40 ( V_79 ) ;
* V_80 = sizeof( struct V_43 ) ;
memset ( & V_81 -> V_83 , 0 , sizeof( V_81 -> V_83 ) ) ;
} else {
struct V_48 * V_84 = (struct V_48 * ) V_78 ;
V_84 -> V_85 = F_40 ( V_79 ) ;
* V_80 = sizeof( struct V_48 ) ;
}
memset ( ( char * ) V_78 + * V_80 , 0 , sizeof( struct V_37 ) - * V_80 ) ;
}
static void F_41 ( struct V_10 * V_14 , bool V_86 )
{
F_20 ( & V_14 -> V_19 ) ;
if ( V_14 -> V_52 ) {
F_42 ( V_14 -> V_52 ) ;
V_14 -> V_52 = NULL ;
}
if ( V_14 -> V_87 && V_86 ) {
F_41 ( V_14 -> V_87 , false ) ;
}
if ( V_14 -> V_88 ) {
F_43 ( V_14 -> V_88 ) ;
V_14 -> V_88 = NULL ;
}
V_14 -> V_89 = 0 ;
F_21 ( & V_14 -> V_19 ) ;
}
static void F_44 ( T_3 V_90 )
{
static char V_91 [ F_45 ( sizeof( struct V_92 ) ) ] ;
struct V_93 V_94 ;
struct V_95 * V_96 ;
struct V_92 * V_97 ;
int V_98 ;
struct V_10 * V_14 ;
V_14 = F_19 ( 0 , 0 ) ;
F_46 ( V_14 == NULL ) ;
V_94 . V_99 = NULL ;
V_94 . V_100 = 0 ;
V_94 . V_101 = V_91 ;
V_94 . V_102 = sizeof( V_91 ) ;
V_94 . V_103 = V_104 ;
V_96 = F_47 ( & V_94 ) ;
V_96 -> V_105 = V_106 ;
V_96 -> V_107 = V_108 ;
V_96 -> V_109 = F_48 ( sizeof( struct V_92 ) ) ;
V_94 . V_102 = V_96 -> V_109 ;
V_97 = F_49 ( V_96 ) ;
memset ( V_97 , 0x00 , sizeof( struct V_92 ) ) ;
V_97 -> V_110 |= V_111 ;
V_97 -> V_112 = V_90 ;
V_98 = F_50 ( V_14 -> V_52 , & V_94 , NULL , 0 , 0 ) ;
if ( V_98 != 0 )
F_51 ( L_1 , V_98 ) ;
}
static void F_52 ( struct V_10 * V_14 )
{
V_14 -> V_34 = 0 ;
if ( F_32 ( V_65 , & V_14 -> V_56 ) ) {
if ( ! F_28 ( V_62 , & V_14 -> V_56 ) )
F_29 ( V_63 , & V_14 -> V_22 ) ;
}
}
static void F_53 ( void )
{
F_20 ( & V_32 ) ;
F_16 ( F_52 ) ;
F_21 ( & V_32 ) ;
}
static void F_54 ( struct V_10 * V_14 ,
struct V_93 * V_113 , char * V_114 )
{
union V_115 * V_116 = (union V_115 * ) V_114 ;
if ( V_116 -> V_117 . V_118 == V_119 ) {
switch ( V_116 -> V_120 . V_121 ) {
case V_122 :
case V_123 :
{
struct V_124 V_125 ;
int V_8 ;
int V_126 , V_98 ;
int V_80 ;
struct V_10 * V_127 ;
T_4 V_128 ;
int V_129 = sizeof( V_128 ) ;
int V_130 ;
if ( ( int ) V_116 -> V_120 . V_131 <= 0 ) {
F_51 ( L_2 ,
( int ) V_116 -> V_120 . V_131 ) ;
F_53 () ;
return;
}
memset ( & V_125 , 0 , sizeof( struct V_124 ) ) ;
V_126 = sizeof( struct V_124 ) ;
V_125 . V_132 = V_116 -> V_120 . V_131 ;
V_98 = F_55 ( V_14 -> V_52 ,
V_106 ,
V_133 ,
( char * ) & V_125 ,
& V_126 ) ;
if ( V_98 < 0 ) {
F_51 ( L_3
L_4 ,
( int ) V_116 -> V_120 . V_131 ,
V_98 ) ;
V_127 = F_22 ( V_116 -> V_120 . V_131 ) ;
if ( V_127 )
F_31 ( V_65 , & V_14 -> V_56 ) ;
return;
}
F_39 ( & V_125 . V_134 , 0 , & V_80 ) ;
if ( F_56 ( & V_125 . V_134 , & V_8 ) ) {
unsigned char * V_135 = ( unsigned char * ) & V_125 . V_134 ;
F_51 ( L_5 ) ;
F_57 ( L_6 , V_136 ,
V_135 , sizeof( struct V_37 ) ) ;
F_44 ( V_125 . V_132 ) ;
return;
}
V_127 = F_19 ( V_8 , V_70 ) ;
if ( ! V_127 )
return;
V_128 . V_90 = V_116 -> V_120 . V_131 ;
V_98 = F_55 ( V_14 -> V_52 , V_106 ,
V_137 ,
( void * ) & V_128 , & V_129 ) ;
if ( V_98 < 0 ) {
F_51 ( L_7
L_8 ,
V_128 . V_90 , V_8 , V_98 ) ;
return;
}
V_127 -> V_52 = F_58 ( V_128 . V_138 , & V_130 ) ;
if ( ! V_127 -> V_52 ) {
F_51 ( L_9 , V_130 ) ;
return;
}
F_38 ( V_127 -> V_52 , V_127 ) ;
F_59 ( V_127 -> V_52 ) ;
F_51 ( L_10 ,
V_8 , ( int ) V_116 -> V_120 . V_131 ) ;
F_31 ( V_65 , & V_127 -> V_56 ) ;
F_31 ( V_139 , & V_14 -> V_56 ) ;
if ( ! F_28 ( V_62 , & V_127 -> V_56 ) ) {
F_29 ( V_63 , & V_127 -> V_22 ) ;
}
if ( ! F_28 ( V_55 , & V_127 -> V_56 ) )
F_29 ( V_57 , & V_127 -> V_24 ) ;
}
break;
case V_140 :
case V_141 :
{
V_14 = F_22 ( V_116 -> V_120 . V_131 ) ;
if ( V_14 ) {
V_14 -> V_34 = 0 ;
}
}
break;
case V_142 :
{
F_51 ( L_11 ) ;
F_53 () ;
}
break;
default:
F_51 ( L_12 ,
( int ) V_116 -> V_120 . V_131 ,
V_116 -> V_120 . V_121 ) ;
}
}
}
static int F_60 ( struct V_10 * V_14 )
{
int V_98 = 0 ;
struct V_93 V_113 = {} ;
struct V_143 V_144 [ 2 ] ;
unsigned V_4 ;
int V_11 ;
int V_145 = 0 ;
int V_146 ;
char V_147 [ F_45 ( sizeof( struct V_92 ) ) ] ;
F_20 ( & V_14 -> V_19 ) ;
if ( V_14 -> V_52 == NULL ) {
V_98 = - V_148 ;
goto V_149;
}
if ( V_14 -> V_88 == NULL ) {
V_14 -> V_88 = F_61 ( V_150 ) ;
if ( V_14 -> V_88 == NULL )
goto V_151;
F_3 ( & V_14 -> V_2 , V_152 ) ;
}
memset ( & V_147 , 0 , sizeof( V_147 ) ) ;
V_113 . V_101 = V_147 ;
V_113 . V_102 = sizeof( V_147 ) ;
V_144 [ 0 ] . V_153 = V_14 -> V_2 . V_5 - F_2 ( & V_14 -> V_2 ) ;
V_144 [ 0 ] . V_154 = F_62 ( V_14 -> V_88 ) + F_2 ( & V_14 -> V_2 ) ;
V_144 [ 1 ] . V_153 = 0 ;
V_146 = 1 ;
if ( F_2 ( & V_14 -> V_2 ) >= V_14 -> V_2 . V_5 ) {
V_144 [ 0 ] . V_153 = V_152 - F_2 ( & V_14 -> V_2 ) ;
V_144 [ 1 ] . V_153 = V_14 -> V_2 . V_5 ;
V_144 [ 1 ] . V_154 = F_62 ( V_14 -> V_88 ) ;
V_146 = 2 ;
}
V_4 = V_144 [ 0 ] . V_153 + V_144 [ 1 ] . V_153 ;
V_11 = V_98 = F_63 ( V_14 -> V_52 , & V_113 , V_144 , V_146 , V_4 ,
V_155 | V_156 ) ;
if ( V_98 <= 0 )
goto V_149;
if ( V_113 . V_103 & V_157 ) {
V_113 . V_101 = V_147 ;
V_113 . V_102 = sizeof( V_147 ) ;
F_54 ( V_14 , & V_113 ,
F_62 ( V_14 -> V_88 ) + V_14 -> V_2 . V_5 ) ;
F_21 ( & V_14 -> V_19 ) ;
return 0 ;
}
F_46 ( V_14 -> V_8 == 0 ) ;
if ( V_98 == V_4 )
V_145 = 1 ;
F_1 ( & V_14 -> V_2 , V_98 ) ;
V_98 = F_64 ( V_14 -> V_8 ,
F_62 ( V_14 -> V_88 ) ,
V_14 -> V_2 . V_5 , V_14 -> V_2 . V_4 ,
V_152 ) ;
if ( V_98 == - V_158 ) {
F_51 ( L_13
L_14 ,
F_62 ( V_14 -> V_88 ) , V_14 -> V_2 . V_5 , V_14 -> V_2 . V_4 ,
V_4 , V_144 [ 0 ] . V_154 , V_11 ) ;
}
if ( V_98 < 0 )
goto V_149;
F_4 ( & V_14 -> V_2 , V_98 ) ;
if ( F_5 ( & V_14 -> V_2 ) && ! V_145 ) {
F_43 ( V_14 -> V_88 ) ;
V_14 -> V_88 = NULL ;
}
if ( V_145 )
goto V_151;
F_21 ( & V_14 -> V_19 ) ;
return 0 ;
V_151:
if ( ! F_28 ( V_55 , & V_14 -> V_56 ) )
F_29 ( V_57 , & V_14 -> V_24 ) ;
F_21 ( & V_14 -> V_19 ) ;
return - V_148 ;
V_149:
F_21 ( & V_14 -> V_19 ) ;
if ( V_98 != - V_148 ) {
F_41 ( V_14 , false ) ;
}
if ( V_98 == 0 )
V_98 = - V_148 ;
return V_98 ;
}
static int F_65 ( struct V_10 * V_14 )
{
int V_159 ;
struct V_37 V_160 ;
struct V_72 * V_161 ;
int V_4 ;
int V_8 ;
struct V_10 * V_162 ;
struct V_10 * V_163 ;
memset ( & V_160 , 0 , sizeof( V_160 ) ) ;
V_159 = F_66 ( V_40 [ 0 ] -> V_41 , V_164 ,
V_165 , & V_161 ) ;
if ( V_159 < 0 )
return - V_71 ;
F_67 ( & V_14 -> V_19 , 0 ) ;
V_159 = - V_166 ;
if ( V_14 -> V_52 == NULL )
goto V_167;
V_161 -> type = V_14 -> V_52 -> type ;
V_161 -> V_168 = V_14 -> V_52 -> V_168 ;
V_159 = V_14 -> V_52 -> V_168 -> V_169 ( V_14 -> V_52 , V_161 , V_170 ) ;
if ( V_159 < 0 )
goto V_167;
memset ( & V_160 , 0 , sizeof( V_160 ) ) ;
if ( V_161 -> V_168 -> V_171 ( V_161 , (struct V_35 * ) & V_160 ,
& V_4 , 2 ) ) {
V_159 = - V_172 ;
goto V_167;
}
F_39 ( & V_160 , 0 , & V_4 ) ;
if ( F_56 ( & V_160 , & V_8 ) ) {
unsigned char * V_135 = ( unsigned char * ) & V_160 ;
F_51 ( L_15 ) ;
F_57 ( L_6 , V_136 ,
V_135 , sizeof( struct V_37 ) ) ;
F_42 ( V_161 ) ;
F_21 ( & V_14 -> V_19 ) ;
return - 1 ;
}
F_51 ( L_16 , V_8 ) ;
V_162 = F_19 ( V_8 , V_70 ) ;
if ( ! V_162 ) {
V_159 = - V_71 ;
goto V_167;
}
F_67 ( & V_162 -> V_19 , 1 ) ;
if ( V_162 -> V_52 ) {
struct V_10 * V_87 = V_162 -> V_87 ;
if ( ! V_87 ) {
V_87 = F_10 ( V_16 , V_70 ) ;
if ( ! V_87 ) {
F_51 ( L_17 ) ;
F_21 ( & V_162 -> V_19 ) ;
V_159 = - V_71 ;
goto V_167;
}
V_87 -> V_8 = V_8 ;
V_87 -> V_28 = F_60 ;
F_12 ( & V_87 -> V_19 ) ;
F_15 ( & V_87 -> V_22 , V_23 ) ;
F_15 ( & V_87 -> V_24 , V_25 ) ;
F_68 ( V_173 , & V_87 -> V_56 ) ;
}
if ( ! V_87 -> V_52 ) {
V_162 -> V_87 = V_87 ;
V_87 -> V_52 = V_161 ;
V_161 -> V_53 -> V_76 = V_87 ;
F_38 ( V_161 , V_87 ) ;
V_163 = V_87 ;
}
else {
F_69 ( L_18 , V_8 ) ;
V_159 = - V_148 ;
F_21 ( & V_162 -> V_19 ) ;
goto V_167;
}
}
else {
V_161 -> V_53 -> V_76 = V_162 ;
V_162 -> V_28 = F_60 ;
F_38 ( V_161 , V_162 ) ;
V_163 = V_162 ;
}
F_21 ( & V_162 -> V_19 ) ;
if ( ! F_28 ( V_55 , & V_163 -> V_56 ) )
F_29 ( V_57 , & V_163 -> V_24 ) ;
F_21 ( & V_14 -> V_19 ) ;
return 0 ;
V_167:
F_21 ( & V_14 -> V_19 ) ;
F_42 ( V_161 ) ;
if ( V_159 != - V_148 )
F_51 ( L_19 , V_159 ) ;
return V_159 ;
}
static void F_70 ( struct V_174 * V_175 )
{
F_43 ( V_175 -> V_176 ) ;
F_71 ( V_175 ) ;
}
static void F_72 ( struct V_10 * V_14 )
{
struct V_37 V_177 ;
char V_91 [ F_45 ( sizeof( struct V_92 ) ) ] ;
struct V_93 V_94 ;
struct V_95 * V_96 ;
struct V_92 * V_97 ;
struct V_10 * V_178 ;
struct V_174 * V_175 ;
int V_4 , V_179 ;
int V_98 ;
int V_180 ;
struct V_143 V_144 [ 1 ] ;
if ( F_28 ( V_139 , & V_14 -> V_56 ) )
return;
if ( V_14 -> V_89 ++ > V_181 )
return;
if ( F_23 ( V_14 -> V_8 , (struct V_35 * ) & V_177 ) ) {
F_51 ( L_20 , V_14 -> V_8 ) ;
return;
}
V_178 = F_19 ( 0 , 0 ) ;
F_46 ( V_178 == NULL ) ;
F_39 ( & V_177 , V_68 . V_182 , & V_180 ) ;
V_94 . V_99 = & V_177 ;
V_94 . V_100 = V_180 ;
V_94 . V_101 = V_91 ;
V_94 . V_102 = sizeof( V_91 ) ;
V_94 . V_103 = V_104 ;
F_73 ( & V_14 -> V_21 ) ;
if ( F_74 ( & V_14 -> V_20 ) ) {
F_75 ( & V_14 -> V_21 ) ;
F_51 ( L_21 , V_14 -> V_8 ) ;
return;
}
V_175 = F_76 ( & V_14 -> V_20 , struct V_174 , V_17 ) ;
V_4 = V_175 -> V_4 ;
V_179 = V_175 -> V_179 ;
F_75 ( & V_14 -> V_21 ) ;
V_144 [ 0 ] . V_154 = F_62 ( V_175 -> V_176 ) + V_179 ;
V_144 [ 0 ] . V_153 = V_4 ;
V_96 = F_47 ( & V_94 ) ;
V_96 -> V_105 = V_106 ;
V_96 -> V_107 = V_108 ;
V_96 -> V_109 = F_48 ( sizeof( struct V_92 ) ) ;
V_97 = F_49 ( V_96 ) ;
memset ( V_97 , 0x00 , sizeof( struct V_92 ) ) ;
V_97 -> V_183 = F_77 ( F_37 () ) ;
V_94 . V_102 = V_96 -> V_109 ;
V_98 = F_50 ( V_178 -> V_52 , & V_94 , V_144 , 1 , V_4 ) ;
if ( V_98 < 0 ) {
F_51 ( L_22 ,
V_14 -> V_8 , V_98 ) ;
F_31 ( V_65 , & V_14 -> V_56 ) ;
F_31 ( V_139 , & V_14 -> V_56 ) ;
}
else {
F_73 ( & V_14 -> V_21 ) ;
V_175 -> V_179 += V_98 ;
V_175 -> V_4 -= V_98 ;
if ( V_175 -> V_4 == 0 && V_175 -> V_184 == 0 ) {
F_78 ( & V_175 -> V_17 ) ;
F_70 ( V_175 ) ;
}
F_75 ( & V_14 -> V_21 ) ;
}
}
static void F_79 ( struct V_10 * V_14 )
{
int V_159 = - V_185 ;
struct V_37 V_78 , V_186 ;
int V_80 ;
struct V_72 * V_52 = NULL ;
int V_187 = 1 ;
if ( V_14 -> V_8 == 0 ) {
F_51 ( L_23 ) ;
return;
}
F_20 ( & V_14 -> V_19 ) ;
if ( V_14 -> V_89 ++ > V_181 )
goto V_188;
if ( V_14 -> V_52 ) {
V_159 = 0 ;
goto V_188;
}
V_159 = F_66 ( V_40 [ 0 ] -> V_41 , V_164 ,
V_165 , & V_52 ) ;
if ( V_159 < 0 )
goto V_189;
memset ( & V_78 , 0 , sizeof( V_78 ) ) ;
if ( F_24 ( V_14 -> V_8 , & V_78 ) )
goto V_189;
V_52 -> V_53 -> V_76 = V_14 ;
V_14 -> V_28 = F_60 ;
V_14 -> V_27 = F_79 ;
F_38 ( V_52 , V_14 ) ;
memcpy ( & V_186 , V_40 [ 0 ] , sizeof( V_186 ) ) ;
F_39 ( & V_186 , 0 , & V_80 ) ;
V_159 = V_52 -> V_168 -> V_190 ( V_52 , (struct V_35 * ) & V_186 ,
V_80 ) ;
if ( V_159 < 0 ) {
F_51 ( L_24 , V_159 ) ;
}
F_39 ( & V_78 , V_68 . V_182 , & V_80 ) ;
F_51 ( L_25 , V_14 -> V_8 ) ;
F_80 ( V_52 , V_191 , V_192 , ( char * ) & V_187 ,
sizeof( V_187 ) ) ;
V_159 =
V_52 -> V_168 -> V_193 ( V_52 , (struct V_35 * ) & V_78 , V_80 ,
V_170 ) ;
if ( V_159 == - V_194 )
V_159 = 0 ;
if ( V_159 == 0 )
goto V_188;
V_189:
if ( V_14 -> V_52 ) {
F_42 ( V_14 -> V_52 ) ;
V_14 -> V_52 = NULL ;
} else if ( V_52 ) {
F_42 ( V_52 ) ;
}
if ( V_159 != - V_185 && V_159 != - V_195 &&
V_159 != - V_196 && V_159 != - V_197
&& V_159 != - V_198 ) {
F_33 ( V_14 ) ;
V_159 = 0 ;
}
V_188:
F_21 ( & V_14 -> V_19 ) ;
return;
}
static struct V_72 * F_81 ( struct V_10 * V_14 ,
struct V_37 * V_78 )
{
struct V_72 * V_52 = NULL ;
int V_159 = 0 ;
int V_187 = 1 ;
int V_80 ;
if ( V_40 [ 0 ] -> V_41 == V_42 )
V_80 = sizeof( struct V_43 ) ;
else
V_80 = sizeof( struct V_48 ) ;
V_159 = F_66 ( V_40 [ 0 ] -> V_41 , V_164 ,
V_165 , & V_52 ) ;
if ( V_159 < 0 ) {
F_51 ( L_26 ) ;
goto V_199;
}
F_80 ( V_52 , V_191 , V_192 , ( char * ) & V_187 ,
sizeof( V_187 ) ) ;
V_159 = F_80 ( V_52 , V_200 , V_201 ,
( char * ) & V_187 , sizeof( V_187 ) ) ;
if ( V_159 < 0 ) {
F_51 ( L_27 , V_159 ) ;
}
V_52 -> V_53 -> V_76 = V_14 ;
V_14 -> V_28 = F_65 ;
V_14 -> V_27 = F_79 ;
V_14 -> V_52 = V_52 ;
F_39 ( V_78 , V_68 . V_182 , & V_80 ) ;
V_159 = V_52 -> V_168 -> V_190 ( V_52 , (struct V_35 * ) V_78 , V_80 ) ;
if ( V_159 < 0 ) {
F_51 ( L_28 , V_68 . V_182 ) ;
F_42 ( V_52 ) ;
V_52 = NULL ;
V_14 -> V_52 = NULL ;
goto V_199;
}
V_159 = F_80 ( V_52 , V_200 , V_202 ,
( char * ) & V_187 , sizeof( V_187 ) ) ;
if ( V_159 < 0 ) {
F_51 ( L_29 , V_159 ) ;
}
V_159 = V_52 -> V_168 -> V_203 ( V_52 , 5 ) ;
if ( V_159 < 0 ) {
F_51 ( L_30 , V_68 . V_182 ) ;
F_42 ( V_52 ) ;
V_52 = NULL ;
goto V_199;
}
V_199:
return V_52 ;
}
static void F_82 ( void )
{
struct V_37 V_204 , * V_38 ;
int V_30 ;
V_39 = 0 ;
for ( V_30 = 0 ; V_30 < V_205 - 1 ; V_30 ++ ) {
if ( F_83 ( & V_204 , V_30 ) )
break;
V_38 = F_84 ( sizeof( * V_38 ) , V_70 ) ;
if ( ! V_38 )
break;
memcpy ( V_38 , & V_204 , sizeof( * V_38 ) ) ;
V_40 [ V_39 ++ ] = V_38 ;
}
}
static int F_85 ( struct V_10 * V_206 ,
struct V_37 * V_38 ,
int V_80 , int V_207 )
{
int V_159 = 0 ;
if ( V_207 == 1 )
V_159 = F_86 ( V_206 -> V_52 ,
(struct V_35 * ) V_38 ,
V_80 ) ;
else
V_159 = F_80 ( V_206 -> V_52 , V_208 ,
V_209 ,
( char * ) V_38 , V_80 ) ;
if ( V_159 < 0 )
F_51 ( L_31 ,
V_68 . V_182 , V_207 ) ;
return V_159 ;
}
static int F_87 ( void )
{
struct V_72 * V_52 = NULL ;
struct V_37 V_210 ;
struct V_211 V_212 ;
int V_159 = - V_197 , V_207 = 1 , V_30 , V_80 ;
struct V_10 * V_14 = F_19 ( 0 , V_70 ) ;
int V_213 = V_214 ;
if ( ! V_14 )
return - V_71 ;
F_51 ( L_32 ) ;
V_159 = F_66 ( V_40 [ 0 ] -> V_41 , V_215 ,
V_106 , & V_52 ) ;
if ( V_159 < 0 ) {
F_51 ( L_33 ) ;
goto V_188;
}
memset ( & V_212 , 0 , sizeof( V_212 ) ) ;
V_212 . V_216 = 1 ;
V_212 . V_217 = 1 ;
V_212 . V_218 = 1 ;
V_212 . V_219 = 1 ;
V_212 . V_220 = 1 ;
V_159 = F_80 ( V_52 , V_200 , V_221 ,
( char * ) & V_213 , sizeof( V_213 ) ) ;
if ( V_159 )
F_51 ( L_34 , V_159 ) ;
V_159 = F_80 ( V_52 , V_208 , V_222 ,
( char * ) & V_212 , sizeof( V_212 ) ) ;
if ( V_159 < 0 ) {
F_51 ( L_35 ,
V_159 ) ;
goto V_223;
}
V_52 -> V_53 -> V_76 = V_14 ;
V_14 -> V_52 = V_52 ;
V_14 -> V_52 -> V_53 -> V_73 = F_26 ;
V_14 -> V_28 = F_60 ;
V_14 -> V_27 = F_72 ;
for ( V_30 = 0 ; V_30 < V_39 ; V_30 ++ ) {
memcpy ( & V_210 , V_40 [ V_30 ] , sizeof( V_210 ) ) ;
F_39 ( & V_210 , V_68 . V_182 , & V_80 ) ;
V_159 = F_85 ( V_14 , & V_210 , V_80 , V_207 ) ;
if ( V_159 )
goto V_223;
++ V_207 ;
}
V_159 = V_52 -> V_168 -> V_203 ( V_52 , 5 ) ;
if ( V_159 < 0 ) {
F_51 ( L_36 ) ;
goto V_223;
}
return 0 ;
V_223:
F_42 ( V_52 ) ;
V_14 -> V_52 = NULL ;
V_188:
return V_159 ;
}
static int F_88 ( void )
{
struct V_72 * V_52 = NULL ;
struct V_10 * V_14 = F_19 ( 0 , V_70 ) ;
int V_159 = - V_197 ;
if ( ! V_14 )
return - V_71 ;
if ( V_40 [ 1 ] != NULL ) {
F_51 ( L_37
L_38 ) ;
return - V_197 ;
}
F_51 ( L_39 ) ;
V_52 = F_81 ( V_14 , V_40 [ 0 ] ) ;
if ( V_52 ) {
F_38 ( V_52 , V_14 ) ;
V_159 = 0 ;
}
else {
V_159 = - V_224 ;
}
return V_159 ;
}
static struct V_174 * F_89 ( struct V_10 * V_14 ,
T_1 V_31 )
{
struct V_174 * V_225 ;
V_225 = F_84 ( sizeof( struct V_174 ) , V_31 ) ;
if ( ! V_225 )
return NULL ;
V_225 -> V_176 = F_61 ( V_31 ) ;
if ( ! V_225 -> V_176 ) {
F_71 ( V_225 ) ;
return NULL ;
}
V_225 -> V_179 = 0 ;
V_225 -> V_4 = 0 ;
V_225 -> V_226 = 0 ;
V_225 -> V_184 = 0 ;
V_225 -> V_14 = V_14 ;
return V_225 ;
}
void * F_90 ( int V_8 , int V_4 , T_1 V_31 , char * * V_227 )
{
struct V_10 * V_14 ;
struct V_174 * V_175 ;
int V_179 = 0 ;
int V_184 = 0 ;
V_14 = F_19 ( V_8 , V_31 ) ;
if ( ! V_14 )
return NULL ;
F_73 ( & V_14 -> V_21 ) ;
V_175 = F_91 ( V_14 -> V_20 . V_228 , struct V_174 , V_17 ) ;
if ( ( & V_175 -> V_17 == & V_14 -> V_20 ) ||
( V_152 - V_175 -> V_226 < V_4 ) ) {
V_175 = NULL ;
} else {
V_179 = V_175 -> V_226 ;
V_175 -> V_226 += V_4 ;
V_184 = V_175 -> V_184 ++ ;
}
F_75 ( & V_14 -> V_21 ) ;
if ( V_175 ) {
V_229:
* V_227 = F_62 ( V_175 -> V_176 ) + V_179 ;
return V_175 ;
}
V_175 = F_89 ( V_14 , V_31 ) ;
if ( V_175 ) {
F_73 ( & V_14 -> V_21 ) ;
V_179 = V_175 -> V_226 ;
V_175 -> V_226 += V_4 ;
V_184 = V_175 -> V_184 ++ ;
F_92 ( & V_175 -> V_17 , & V_14 -> V_20 ) ;
F_75 ( & V_14 -> V_21 ) ;
goto V_229;
}
return NULL ;
}
void F_93 ( void * V_230 )
{
struct V_174 * V_175 = (struct V_174 * ) V_230 ;
struct V_10 * V_14 = V_175 -> V_14 ;
int V_184 ;
F_73 ( & V_14 -> V_21 ) ;
V_184 = -- V_175 -> V_184 ;
if ( V_184 )
goto V_188;
V_175 -> V_4 = V_175 -> V_226 - V_175 -> V_179 ;
F_75 ( & V_14 -> V_21 ) ;
if ( ! F_28 ( V_62 , & V_14 -> V_56 ) ) {
F_29 ( V_63 , & V_14 -> V_22 ) ;
}
return;
V_188:
F_75 ( & V_14 -> V_21 ) ;
return;
}
static void F_94 ( struct V_10 * V_14 )
{
int V_98 = 0 ;
const int V_103 = V_155 | V_156 ;
struct V_174 * V_175 ;
int V_4 , V_179 ;
int V_231 = 0 ;
F_20 ( & V_14 -> V_19 ) ;
if ( V_14 -> V_52 == NULL )
goto V_232;
F_73 ( & V_14 -> V_21 ) ;
for (; ; ) {
V_175 = F_91 ( V_14 -> V_20 . V_233 , struct V_174 ,
V_17 ) ;
if ( (struct V_234 * ) V_175 == & V_14 -> V_20 )
break;
V_4 = V_175 -> V_4 ;
V_179 = V_175 -> V_179 ;
F_46 ( V_4 == 0 && V_175 -> V_184 == 0 ) ;
F_75 ( & V_14 -> V_21 ) ;
V_98 = 0 ;
if ( V_4 ) {
V_98 = F_95 ( V_14 -> V_52 , V_175 -> V_176 , V_179 , V_4 ,
V_103 ) ;
if ( V_98 == - V_148 || V_98 == 0 ) {
if ( V_98 == - V_148 &&
F_34 ( V_61 , & V_14 -> V_52 -> V_56 ) &&
! F_28 ( V_59 , & V_14 -> V_56 ) ) {
F_68 ( V_58 , & V_14 -> V_52 -> V_56 ) ;
V_14 -> V_52 -> V_53 -> V_60 ++ ;
}
F_96 () ;
goto V_188;
}
if ( V_98 <= 0 )
goto V_235;
}
if ( ++ V_231 >= V_236 ) {
F_96 () ;
V_231 = 0 ;
}
F_73 ( & V_14 -> V_21 ) ;
V_175 -> V_179 += V_98 ;
V_175 -> V_4 -= V_98 ;
if ( V_175 -> V_4 == 0 && V_175 -> V_184 == 0 ) {
F_78 ( & V_175 -> V_17 ) ;
F_70 ( V_175 ) ;
continue;
}
}
F_75 ( & V_14 -> V_21 ) ;
V_188:
F_21 ( & V_14 -> V_19 ) ;
return;
V_235:
F_21 ( & V_14 -> V_19 ) ;
F_41 ( V_14 , false ) ;
F_33 ( V_14 ) ;
return;
V_232:
F_21 ( & V_14 -> V_19 ) ;
if ( ! F_34 ( V_139 , & V_14 -> V_56 ) )
F_33 ( V_14 ) ;
return;
}
static void F_97 ( struct V_10 * V_14 )
{
struct V_174 * V_175 , * V_237 ;
F_73 ( & V_14 -> V_21 ) ;
F_98 (e, safe, &con->writequeue, list) {
F_78 ( & V_175 -> V_17 ) ;
F_70 ( V_175 ) ;
}
F_75 ( & V_14 -> V_21 ) ;
}
int F_99 ( int V_8 )
{
struct V_10 * V_14 ;
F_51 ( L_40 , V_8 ) ;
V_14 = F_19 ( V_8 , 0 ) ;
if ( V_14 ) {
F_31 ( V_65 , & V_14 -> V_56 ) ;
F_31 ( V_62 , & V_14 -> V_56 ) ;
F_68 ( V_64 , & V_14 -> V_56 ) ;
if ( F_100 ( & V_14 -> V_22 ) )
F_51 ( L_41 , V_8 ) ;
if ( F_100 ( & V_14 -> V_24 ) )
F_51 ( L_42 , V_8 ) ;
F_97 ( V_14 ) ;
F_41 ( V_14 , true ) ;
}
return 0 ;
}
static void V_25 ( struct V_238 * V_239 )
{
struct V_10 * V_14 = F_101 ( V_239 , struct V_10 , V_24 ) ;
int V_130 ;
F_31 ( V_55 , & V_14 -> V_56 ) ;
do {
V_130 = V_14 -> V_28 ( V_14 ) ;
} while ( ! V_130 );
}
static void V_23 ( struct V_238 * V_239 )
{
struct V_10 * V_14 = F_101 ( V_239 , struct V_10 , V_22 ) ;
if ( F_32 ( V_65 , & V_14 -> V_56 ) ) {
V_14 -> V_27 ( V_14 ) ;
F_68 ( V_62 , & V_14 -> V_56 ) ;
}
if ( F_32 ( V_62 , & V_14 -> V_56 ) )
F_94 ( V_14 ) ;
}
static void F_102 ( void )
{
F_16 ( F_97 ) ;
}
static void F_103 ( void )
{
F_104 ( V_57 ) ;
F_104 ( V_63 ) ;
}
static int F_105 ( void )
{
V_57 = F_106 ( L_43 ,
V_240 | V_241 , 1 ) ;
if ( ! V_57 ) {
F_51 ( L_44 ) ;
return - V_71 ;
}
V_63 = F_106 ( L_45 ,
V_240 | V_241 , 1 ) ;
if ( ! V_63 ) {
F_51 ( L_46 ) ;
F_104 ( V_57 ) ;
return - V_71 ;
}
return 0 ;
}
static void F_107 ( struct V_10 * V_14 )
{
V_14 -> V_56 |= 0x0F ;
if ( V_14 -> V_52 && V_14 -> V_52 -> V_53 )
V_14 -> V_52 -> V_53 -> V_76 = NULL ;
}
static void F_108 ( struct V_10 * V_14 )
{
F_41 ( V_14 , true ) ;
if ( V_14 -> V_87 )
F_109 ( V_16 , V_14 -> V_87 ) ;
F_110 ( & V_14 -> V_17 ) ;
F_109 ( V_16 , V_14 ) ;
}
void F_111 ( void )
{
F_20 ( & V_32 ) ;
F_16 ( F_107 ) ;
F_21 ( & V_32 ) ;
F_103 () ;
F_20 ( & V_32 ) ;
F_102 () ;
F_16 ( F_108 ) ;
F_21 ( & V_32 ) ;
F_112 ( V_16 ) ;
}
int F_113 ( void )
{
int error = - V_197 ;
struct V_10 * V_14 ;
int V_30 ;
for ( V_30 = 0 ; V_30 < V_9 ; V_30 ++ )
F_114 ( & V_18 [ V_30 ] ) ;
F_82 () ;
if ( ! V_39 ) {
error = - V_166 ;
F_51 ( L_47 ) ;
goto V_188;
}
error = - V_71 ;
V_16 = F_115 ( L_48 , sizeof( struct V_10 ) ,
F_116 ( struct V_10 ) , 0 ,
NULL ) ;
if ( ! V_16 )
goto V_188;
if ( V_68 . V_69 == 0 )
error = F_88 () ;
else
error = F_87 () ;
if ( error )
goto V_242;
error = F_105 () ;
if ( error )
goto V_242;
return 0 ;
V_242:
V_14 = F_19 ( 0 , 0 ) ;
if ( V_14 ) {
F_41 ( V_14 , false ) ;
F_109 ( V_16 , V_14 ) ;
}
F_112 ( V_16 ) ;
V_188:
return error ;
}
