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
int V_30 ;
unsigned char * V_135 = ( unsigned char * ) & V_125 . V_134 ;
F_51 ( L_5 ) ;
for ( V_30 = 0 ; V_30 < sizeof( struct V_37 ) ; V_30 ++ )
F_57 ( L_6 , V_135 [ V_30 ] ) ;
F_57 ( L_7 ) ;
F_44 ( V_125 . V_132 ) ;
return;
}
V_127 = F_19 ( V_8 , V_70 ) ;
if ( ! V_127 )
return;
V_128 . V_90 = V_116 -> V_120 . V_131 ;
V_98 = F_55 ( V_14 -> V_52 , V_106 ,
V_136 ,
( void * ) & V_128 , & V_129 ) ;
if ( V_98 < 0 ) {
F_51 ( L_8
L_9 ,
V_128 . V_90 , V_8 , V_98 ) ;
return;
}
V_127 -> V_52 = F_58 ( V_128 . V_137 , & V_130 ) ;
if ( ! V_127 -> V_52 ) {
F_51 ( L_10 , V_130 ) ;
return;
}
F_38 ( V_127 -> V_52 , V_127 ) ;
F_59 ( V_127 -> V_52 ) ;
F_51 ( L_11 ,
V_8 , ( int ) V_116 -> V_120 . V_131 ) ;
F_31 ( V_65 , & V_127 -> V_56 ) ;
F_31 ( V_138 , & V_14 -> V_56 ) ;
if ( ! F_28 ( V_62 , & V_127 -> V_56 ) ) {
F_29 ( V_63 , & V_127 -> V_22 ) ;
}
if ( ! F_28 ( V_55 , & V_127 -> V_56 ) )
F_29 ( V_57 , & V_127 -> V_24 ) ;
}
break;
case V_139 :
case V_140 :
{
V_14 = F_22 ( V_116 -> V_120 . V_131 ) ;
if ( V_14 ) {
V_14 -> V_34 = 0 ;
}
}
break;
case V_141 :
{
F_51 ( L_12 ) ;
F_53 () ;
}
break;
default:
F_51 ( L_13 ,
( int ) V_116 -> V_120 . V_131 ,
V_116 -> V_120 . V_121 ) ;
}
}
}
static int F_60 ( struct V_10 * V_14 )
{
int V_98 = 0 ;
struct V_93 V_113 = {} ;
struct V_142 V_143 [ 2 ] ;
unsigned V_4 ;
int V_11 ;
int V_144 = 0 ;
int V_145 ;
char V_146 [ F_45 ( sizeof( struct V_92 ) ) ] ;
F_20 ( & V_14 -> V_19 ) ;
if ( V_14 -> V_52 == NULL ) {
V_98 = - V_147 ;
goto V_148;
}
if ( V_14 -> V_88 == NULL ) {
V_14 -> V_88 = F_61 ( V_149 ) ;
if ( V_14 -> V_88 == NULL )
goto V_150;
F_3 ( & V_14 -> V_2 , V_151 ) ;
}
memset ( & V_146 , 0 , sizeof( V_146 ) ) ;
V_113 . V_101 = V_146 ;
V_113 . V_102 = sizeof( V_146 ) ;
V_143 [ 0 ] . V_152 = V_14 -> V_2 . V_5 - F_2 ( & V_14 -> V_2 ) ;
V_143 [ 0 ] . V_153 = F_62 ( V_14 -> V_88 ) + F_2 ( & V_14 -> V_2 ) ;
V_143 [ 1 ] . V_152 = 0 ;
V_145 = 1 ;
if ( F_2 ( & V_14 -> V_2 ) >= V_14 -> V_2 . V_5 ) {
V_143 [ 0 ] . V_152 = V_151 - F_2 ( & V_14 -> V_2 ) ;
V_143 [ 1 ] . V_152 = V_14 -> V_2 . V_5 ;
V_143 [ 1 ] . V_153 = F_62 ( V_14 -> V_88 ) ;
V_145 = 2 ;
}
V_4 = V_143 [ 0 ] . V_152 + V_143 [ 1 ] . V_152 ;
V_11 = V_98 = F_63 ( V_14 -> V_52 , & V_113 , V_143 , V_145 , V_4 ,
V_154 | V_155 ) ;
if ( V_98 <= 0 )
goto V_148;
if ( V_113 . V_103 & V_156 ) {
V_113 . V_101 = V_146 ;
V_113 . V_102 = sizeof( V_146 ) ;
F_54 ( V_14 , & V_113 ,
F_62 ( V_14 -> V_88 ) + V_14 -> V_2 . V_5 ) ;
F_21 ( & V_14 -> V_19 ) ;
return 0 ;
}
F_46 ( V_14 -> V_8 == 0 ) ;
if ( V_98 == V_4 )
V_144 = 1 ;
F_1 ( & V_14 -> V_2 , V_98 ) ;
V_98 = F_64 ( V_14 -> V_8 ,
F_62 ( V_14 -> V_88 ) ,
V_14 -> V_2 . V_5 , V_14 -> V_2 . V_4 ,
V_151 ) ;
if ( V_98 == - V_157 ) {
F_51 ( L_14
L_15 ,
F_62 ( V_14 -> V_88 ) , V_14 -> V_2 . V_5 , V_14 -> V_2 . V_4 ,
V_4 , V_143 [ 0 ] . V_153 , V_11 ) ;
}
if ( V_98 < 0 )
goto V_148;
F_4 ( & V_14 -> V_2 , V_98 ) ;
if ( F_5 ( & V_14 -> V_2 ) && ! V_144 ) {
F_43 ( V_14 -> V_88 ) ;
V_14 -> V_88 = NULL ;
}
if ( V_144 )
goto V_150;
F_21 ( & V_14 -> V_19 ) ;
return 0 ;
V_150:
if ( ! F_28 ( V_55 , & V_14 -> V_56 ) )
F_29 ( V_57 , & V_14 -> V_24 ) ;
F_21 ( & V_14 -> V_19 ) ;
return - V_147 ;
V_148:
F_21 ( & V_14 -> V_19 ) ;
if ( V_98 != - V_147 ) {
F_41 ( V_14 , false ) ;
}
if ( V_98 == 0 )
V_98 = - V_147 ;
return V_98 ;
}
static int F_65 ( struct V_10 * V_14 )
{
int V_158 ;
struct V_37 V_159 ;
struct V_72 * V_160 ;
int V_4 ;
int V_8 ;
struct V_10 * V_161 ;
struct V_10 * V_162 ;
memset ( & V_159 , 0 , sizeof( V_159 ) ) ;
V_158 = F_66 ( V_40 [ 0 ] -> V_41 , V_163 ,
V_164 , & V_160 ) ;
if ( V_158 < 0 )
return - V_71 ;
F_67 ( & V_14 -> V_19 , 0 ) ;
V_158 = - V_165 ;
if ( V_14 -> V_52 == NULL )
goto V_166;
V_160 -> type = V_14 -> V_52 -> type ;
V_160 -> V_167 = V_14 -> V_52 -> V_167 ;
V_158 = V_14 -> V_52 -> V_167 -> V_168 ( V_14 -> V_52 , V_160 , V_169 ) ;
if ( V_158 < 0 )
goto V_166;
memset ( & V_159 , 0 , sizeof( V_159 ) ) ;
if ( V_160 -> V_167 -> V_170 ( V_160 , (struct V_35 * ) & V_159 ,
& V_4 , 2 ) ) {
V_158 = - V_171 ;
goto V_166;
}
F_39 ( & V_159 , 0 , & V_4 ) ;
if ( F_56 ( & V_159 , & V_8 ) ) {
F_51 ( L_16 ) ;
F_42 ( V_160 ) ;
F_21 ( & V_14 -> V_19 ) ;
return - 1 ;
}
F_51 ( L_17 , V_8 ) ;
V_161 = F_19 ( V_8 , V_70 ) ;
if ( ! V_161 ) {
V_158 = - V_71 ;
goto V_166;
}
F_67 ( & V_161 -> V_19 , 1 ) ;
if ( V_161 -> V_52 ) {
struct V_10 * V_87 = V_161 -> V_87 ;
if ( ! V_87 ) {
V_87 = F_10 ( V_16 , V_70 ) ;
if ( ! V_87 ) {
F_51 ( L_18 ) ;
F_21 ( & V_161 -> V_19 ) ;
V_158 = - V_71 ;
goto V_166;
}
V_87 -> V_8 = V_8 ;
V_87 -> V_28 = F_60 ;
F_12 ( & V_87 -> V_19 ) ;
F_15 ( & V_87 -> V_22 , V_23 ) ;
F_15 ( & V_87 -> V_24 , V_25 ) ;
F_68 ( V_172 , & V_87 -> V_56 ) ;
}
if ( ! V_87 -> V_52 ) {
V_161 -> V_87 = V_87 ;
V_87 -> V_52 = V_160 ;
V_160 -> V_53 -> V_76 = V_87 ;
F_38 ( V_160 , V_87 ) ;
V_162 = V_87 ;
}
else {
F_57 ( L_19 , V_8 ) ;
V_158 = - V_147 ;
F_21 ( & V_161 -> V_19 ) ;
goto V_166;
}
}
else {
V_160 -> V_53 -> V_76 = V_161 ;
V_161 -> V_28 = F_60 ;
F_38 ( V_160 , V_161 ) ;
V_162 = V_161 ;
}
F_21 ( & V_161 -> V_19 ) ;
if ( ! F_28 ( V_55 , & V_162 -> V_56 ) )
F_29 ( V_57 , & V_162 -> V_24 ) ;
F_21 ( & V_14 -> V_19 ) ;
return 0 ;
V_166:
F_21 ( & V_14 -> V_19 ) ;
F_42 ( V_160 ) ;
if ( V_158 != - V_147 )
F_51 ( L_20 , V_158 ) ;
return V_158 ;
}
static void F_69 ( struct V_173 * V_174 )
{
F_43 ( V_174 -> V_175 ) ;
F_70 ( V_174 ) ;
}
static void F_71 ( struct V_10 * V_14 )
{
struct V_37 V_176 ;
char V_91 [ F_45 ( sizeof( struct V_92 ) ) ] ;
struct V_93 V_94 ;
struct V_95 * V_96 ;
struct V_92 * V_97 ;
struct V_10 * V_177 ;
struct V_173 * V_174 ;
int V_4 , V_178 ;
int V_98 ;
int V_179 ;
struct V_142 V_143 [ 1 ] ;
if ( F_28 ( V_138 , & V_14 -> V_56 ) )
return;
if ( V_14 -> V_89 ++ > V_180 )
return;
if ( F_23 ( V_14 -> V_8 , (struct V_35 * ) & V_176 ) ) {
F_51 ( L_21 , V_14 -> V_8 ) ;
return;
}
V_177 = F_19 ( 0 , 0 ) ;
F_46 ( V_177 == NULL ) ;
F_39 ( & V_176 , V_68 . V_181 , & V_179 ) ;
V_94 . V_99 = & V_176 ;
V_94 . V_100 = V_179 ;
V_94 . V_101 = V_91 ;
V_94 . V_102 = sizeof( V_91 ) ;
V_94 . V_103 = V_104 ;
F_72 ( & V_14 -> V_21 ) ;
if ( F_73 ( & V_14 -> V_20 ) ) {
F_74 ( & V_14 -> V_21 ) ;
F_51 ( L_22 , V_14 -> V_8 ) ;
return;
}
V_174 = F_75 ( & V_14 -> V_20 , struct V_173 , V_17 ) ;
V_4 = V_174 -> V_4 ;
V_178 = V_174 -> V_178 ;
F_74 ( & V_14 -> V_21 ) ;
V_143 [ 0 ] . V_153 = F_62 ( V_174 -> V_175 ) + V_178 ;
V_143 [ 0 ] . V_152 = V_4 ;
V_96 = F_47 ( & V_94 ) ;
V_96 -> V_105 = V_106 ;
V_96 -> V_107 = V_108 ;
V_96 -> V_109 = F_48 ( sizeof( struct V_92 ) ) ;
V_97 = F_49 ( V_96 ) ;
memset ( V_97 , 0x00 , sizeof( struct V_92 ) ) ;
V_97 -> V_182 = F_76 ( F_37 () ) ;
V_94 . V_102 = V_96 -> V_109 ;
V_98 = F_50 ( V_177 -> V_52 , & V_94 , V_143 , 1 , V_4 ) ;
if ( V_98 < 0 ) {
F_51 ( L_23 ,
V_14 -> V_8 , V_98 ) ;
F_31 ( V_65 , & V_14 -> V_56 ) ;
F_31 ( V_138 , & V_14 -> V_56 ) ;
}
else {
F_72 ( & V_14 -> V_21 ) ;
V_174 -> V_178 += V_98 ;
V_174 -> V_4 -= V_98 ;
if ( V_174 -> V_4 == 0 && V_174 -> V_183 == 0 ) {
F_77 ( & V_174 -> V_17 ) ;
F_69 ( V_174 ) ;
}
F_74 ( & V_14 -> V_21 ) ;
}
}
static void F_78 ( struct V_10 * V_14 )
{
int V_158 = - V_184 ;
struct V_37 V_78 , V_185 ;
int V_80 ;
struct V_72 * V_52 = NULL ;
int V_186 = 1 ;
if ( V_14 -> V_8 == 0 ) {
F_51 ( L_24 ) ;
return;
}
F_20 ( & V_14 -> V_19 ) ;
if ( V_14 -> V_89 ++ > V_180 )
goto V_187;
if ( V_14 -> V_52 ) {
V_158 = 0 ;
goto V_187;
}
V_158 = F_66 ( V_40 [ 0 ] -> V_41 , V_163 ,
V_164 , & V_52 ) ;
if ( V_158 < 0 )
goto V_188;
memset ( & V_78 , 0 , sizeof( V_78 ) ) ;
if ( F_24 ( V_14 -> V_8 , & V_78 ) )
goto V_188;
V_52 -> V_53 -> V_76 = V_14 ;
V_14 -> V_28 = F_60 ;
V_14 -> V_27 = F_78 ;
F_38 ( V_52 , V_14 ) ;
memcpy ( & V_185 , V_40 [ 0 ] , sizeof( V_185 ) ) ;
F_39 ( & V_185 , 0 , & V_80 ) ;
V_158 = V_52 -> V_167 -> V_189 ( V_52 , (struct V_35 * ) & V_185 ,
V_80 ) ;
if ( V_158 < 0 ) {
F_51 ( L_25 , V_158 ) ;
}
F_39 ( & V_78 , V_68 . V_181 , & V_80 ) ;
F_51 ( L_26 , V_14 -> V_8 ) ;
F_79 ( V_52 , V_190 , V_191 , ( char * ) & V_186 ,
sizeof( V_186 ) ) ;
V_158 =
V_52 -> V_167 -> V_192 ( V_52 , (struct V_35 * ) & V_78 , V_80 ,
V_169 ) ;
if ( V_158 == - V_193 )
V_158 = 0 ;
if ( V_158 == 0 )
goto V_187;
V_188:
if ( V_14 -> V_52 ) {
F_42 ( V_14 -> V_52 ) ;
V_14 -> V_52 = NULL ;
} else if ( V_52 ) {
F_42 ( V_52 ) ;
}
if ( V_158 != - V_184 && V_158 != - V_194 &&
V_158 != - V_195 && V_158 != - V_196
&& V_158 != - V_197 ) {
F_33 ( V_14 ) ;
V_158 = 0 ;
}
V_187:
F_21 ( & V_14 -> V_19 ) ;
return;
}
static struct V_72 * F_80 ( struct V_10 * V_14 ,
struct V_37 * V_78 )
{
struct V_72 * V_52 = NULL ;
int V_158 = 0 ;
int V_186 = 1 ;
int V_80 ;
if ( V_40 [ 0 ] -> V_41 == V_42 )
V_80 = sizeof( struct V_43 ) ;
else
V_80 = sizeof( struct V_48 ) ;
V_158 = F_66 ( V_40 [ 0 ] -> V_41 , V_163 ,
V_164 , & V_52 ) ;
if ( V_158 < 0 ) {
F_51 ( L_27 ) ;
goto V_198;
}
F_79 ( V_52 , V_190 , V_191 , ( char * ) & V_186 ,
sizeof( V_186 ) ) ;
V_158 = F_79 ( V_52 , V_199 , V_200 ,
( char * ) & V_186 , sizeof( V_186 ) ) ;
if ( V_158 < 0 ) {
F_51 ( L_28 , V_158 ) ;
}
V_52 -> V_53 -> V_76 = V_14 ;
V_14 -> V_28 = F_65 ;
V_14 -> V_27 = F_78 ;
V_14 -> V_52 = V_52 ;
F_39 ( V_78 , V_68 . V_181 , & V_80 ) ;
V_158 = V_52 -> V_167 -> V_189 ( V_52 , (struct V_35 * ) V_78 , V_80 ) ;
if ( V_158 < 0 ) {
F_51 ( L_29 , V_68 . V_181 ) ;
F_42 ( V_52 ) ;
V_52 = NULL ;
V_14 -> V_52 = NULL ;
goto V_198;
}
V_158 = F_79 ( V_52 , V_199 , V_201 ,
( char * ) & V_186 , sizeof( V_186 ) ) ;
if ( V_158 < 0 ) {
F_51 ( L_30 , V_158 ) ;
}
V_158 = V_52 -> V_167 -> V_202 ( V_52 , 5 ) ;
if ( V_158 < 0 ) {
F_51 ( L_31 , V_68 . V_181 ) ;
F_42 ( V_52 ) ;
V_52 = NULL ;
goto V_198;
}
V_198:
return V_52 ;
}
static void F_81 ( void )
{
struct V_37 V_203 , * V_38 ;
int V_30 ;
V_39 = 0 ;
for ( V_30 = 0 ; V_30 < V_204 - 1 ; V_30 ++ ) {
if ( F_82 ( & V_203 , V_30 ) )
break;
V_38 = F_83 ( sizeof( * V_38 ) , V_70 ) ;
if ( ! V_38 )
break;
memcpy ( V_38 , & V_203 , sizeof( * V_38 ) ) ;
V_40 [ V_39 ++ ] = V_38 ;
}
}
static int F_84 ( struct V_10 * V_205 ,
struct V_37 * V_38 ,
int V_80 , int V_206 )
{
int V_158 = 0 ;
if ( V_206 == 1 )
V_158 = F_85 ( V_205 -> V_52 ,
(struct V_35 * ) V_38 ,
V_80 ) ;
else
V_158 = F_79 ( V_205 -> V_52 , V_207 ,
V_208 ,
( char * ) V_38 , V_80 ) ;
if ( V_158 < 0 )
F_51 ( L_32 ,
V_68 . V_181 , V_206 ) ;
return V_158 ;
}
static int F_86 ( void )
{
struct V_72 * V_52 = NULL ;
struct V_37 V_209 ;
struct V_210 V_211 ;
int V_158 = - V_196 , V_206 = 1 , V_30 , V_80 ;
struct V_10 * V_14 = F_19 ( 0 , V_70 ) ;
int V_212 = V_213 ;
if ( ! V_14 )
return - V_71 ;
F_51 ( L_33 ) ;
V_158 = F_66 ( V_40 [ 0 ] -> V_41 , V_214 ,
V_106 , & V_52 ) ;
if ( V_158 < 0 ) {
F_51 ( L_34 ) ;
goto V_187;
}
memset ( & V_211 , 0 , sizeof( V_211 ) ) ;
V_211 . V_215 = 1 ;
V_211 . V_216 = 1 ;
V_211 . V_217 = 1 ;
V_211 . V_218 = 1 ;
V_211 . V_219 = 1 ;
V_158 = F_79 ( V_52 , V_199 , V_220 ,
( char * ) & V_212 , sizeof( V_212 ) ) ;
if ( V_158 )
F_51 ( L_35 , V_158 ) ;
V_158 = F_79 ( V_52 , V_207 , V_221 ,
( char * ) & V_211 , sizeof( V_211 ) ) ;
if ( V_158 < 0 ) {
F_51 ( L_36 ,
V_158 ) ;
goto V_222;
}
V_52 -> V_53 -> V_76 = V_14 ;
V_14 -> V_52 = V_52 ;
V_14 -> V_52 -> V_53 -> V_73 = F_26 ;
V_14 -> V_28 = F_60 ;
V_14 -> V_27 = F_71 ;
for ( V_30 = 0 ; V_30 < V_39 ; V_30 ++ ) {
memcpy ( & V_209 , V_40 [ V_30 ] , sizeof( V_209 ) ) ;
F_39 ( & V_209 , V_68 . V_181 , & V_80 ) ;
V_158 = F_84 ( V_14 , & V_209 , V_80 , V_206 ) ;
if ( V_158 )
goto V_222;
++ V_206 ;
}
V_158 = V_52 -> V_167 -> V_202 ( V_52 , 5 ) ;
if ( V_158 < 0 ) {
F_51 ( L_37 ) ;
goto V_222;
}
return 0 ;
V_222:
F_42 ( V_52 ) ;
V_14 -> V_52 = NULL ;
V_187:
return V_158 ;
}
static int F_87 ( void )
{
struct V_72 * V_52 = NULL ;
struct V_10 * V_14 = F_19 ( 0 , V_70 ) ;
int V_158 = - V_196 ;
if ( ! V_14 )
return - V_71 ;
if ( V_40 [ 1 ] != NULL ) {
F_51 ( L_38
L_39 ) ;
return - V_196 ;
}
F_51 ( L_40 ) ;
V_52 = F_80 ( V_14 , V_40 [ 0 ] ) ;
if ( V_52 ) {
F_38 ( V_52 , V_14 ) ;
V_158 = 0 ;
}
else {
V_158 = - V_223 ;
}
return V_158 ;
}
static struct V_173 * F_88 ( struct V_10 * V_14 ,
T_1 V_31 )
{
struct V_173 * V_224 ;
V_224 = F_83 ( sizeof( struct V_173 ) , V_31 ) ;
if ( ! V_224 )
return NULL ;
V_224 -> V_175 = F_61 ( V_31 ) ;
if ( ! V_224 -> V_175 ) {
F_70 ( V_224 ) ;
return NULL ;
}
V_224 -> V_178 = 0 ;
V_224 -> V_4 = 0 ;
V_224 -> V_225 = 0 ;
V_224 -> V_183 = 0 ;
V_224 -> V_14 = V_14 ;
return V_224 ;
}
void * F_89 ( int V_8 , int V_4 , T_1 V_31 , char * * V_226 )
{
struct V_10 * V_14 ;
struct V_173 * V_174 ;
int V_178 = 0 ;
int V_183 = 0 ;
V_14 = F_19 ( V_8 , V_31 ) ;
if ( ! V_14 )
return NULL ;
F_72 ( & V_14 -> V_21 ) ;
V_174 = F_90 ( V_14 -> V_20 . V_227 , struct V_173 , V_17 ) ;
if ( ( & V_174 -> V_17 == & V_14 -> V_20 ) ||
( V_151 - V_174 -> V_225 < V_4 ) ) {
V_174 = NULL ;
} else {
V_178 = V_174 -> V_225 ;
V_174 -> V_225 += V_4 ;
V_183 = V_174 -> V_183 ++ ;
}
F_74 ( & V_14 -> V_21 ) ;
if ( V_174 ) {
V_228:
* V_226 = F_62 ( V_174 -> V_175 ) + V_178 ;
return V_174 ;
}
V_174 = F_88 ( V_14 , V_31 ) ;
if ( V_174 ) {
F_72 ( & V_14 -> V_21 ) ;
V_178 = V_174 -> V_225 ;
V_174 -> V_225 += V_4 ;
V_183 = V_174 -> V_183 ++ ;
F_91 ( & V_174 -> V_17 , & V_14 -> V_20 ) ;
F_74 ( & V_14 -> V_21 ) ;
goto V_228;
}
return NULL ;
}
void F_92 ( void * V_229 )
{
struct V_173 * V_174 = (struct V_173 * ) V_229 ;
struct V_10 * V_14 = V_174 -> V_14 ;
int V_183 ;
F_72 ( & V_14 -> V_21 ) ;
V_183 = -- V_174 -> V_183 ;
if ( V_183 )
goto V_187;
V_174 -> V_4 = V_174 -> V_225 - V_174 -> V_178 ;
F_74 ( & V_14 -> V_21 ) ;
if ( ! F_28 ( V_62 , & V_14 -> V_56 ) ) {
F_29 ( V_63 , & V_14 -> V_22 ) ;
}
return;
V_187:
F_74 ( & V_14 -> V_21 ) ;
return;
}
static void F_93 ( struct V_10 * V_14 )
{
int V_98 = 0 ;
const int V_103 = V_154 | V_155 ;
struct V_173 * V_174 ;
int V_4 , V_178 ;
int V_230 = 0 ;
F_20 ( & V_14 -> V_19 ) ;
if ( V_14 -> V_52 == NULL )
goto V_231;
F_72 ( & V_14 -> V_21 ) ;
for (; ; ) {
V_174 = F_90 ( V_14 -> V_20 . V_232 , struct V_173 ,
V_17 ) ;
if ( (struct V_233 * ) V_174 == & V_14 -> V_20 )
break;
V_4 = V_174 -> V_4 ;
V_178 = V_174 -> V_178 ;
F_46 ( V_4 == 0 && V_174 -> V_183 == 0 ) ;
F_74 ( & V_14 -> V_21 ) ;
V_98 = 0 ;
if ( V_4 ) {
V_98 = F_94 ( V_14 -> V_52 , V_174 -> V_175 , V_178 , V_4 ,
V_103 ) ;
if ( V_98 == - V_147 || V_98 == 0 ) {
if ( V_98 == - V_147 &&
F_34 ( V_61 , & V_14 -> V_52 -> V_56 ) &&
! F_28 ( V_59 , & V_14 -> V_56 ) ) {
F_68 ( V_58 , & V_14 -> V_52 -> V_56 ) ;
V_14 -> V_52 -> V_53 -> V_60 ++ ;
}
F_95 () ;
goto V_187;
}
if ( V_98 <= 0 )
goto V_234;
}
if ( ++ V_230 >= V_235 ) {
F_95 () ;
V_230 = 0 ;
}
F_72 ( & V_14 -> V_21 ) ;
V_174 -> V_178 += V_98 ;
V_174 -> V_4 -= V_98 ;
if ( V_174 -> V_4 == 0 && V_174 -> V_183 == 0 ) {
F_77 ( & V_174 -> V_17 ) ;
F_69 ( V_174 ) ;
continue;
}
}
F_74 ( & V_14 -> V_21 ) ;
V_187:
F_21 ( & V_14 -> V_19 ) ;
return;
V_234:
F_21 ( & V_14 -> V_19 ) ;
F_41 ( V_14 , false ) ;
F_33 ( V_14 ) ;
return;
V_231:
F_21 ( & V_14 -> V_19 ) ;
if ( ! F_34 ( V_138 , & V_14 -> V_56 ) )
F_33 ( V_14 ) ;
return;
}
static void F_96 ( struct V_10 * V_14 )
{
struct V_173 * V_174 , * V_236 ;
F_72 ( & V_14 -> V_21 ) ;
F_97 (e, safe, &con->writequeue, list) {
F_77 ( & V_174 -> V_17 ) ;
F_69 ( V_174 ) ;
}
F_74 ( & V_14 -> V_21 ) ;
}
int F_98 ( int V_8 )
{
struct V_10 * V_14 ;
F_51 ( L_41 , V_8 ) ;
V_14 = F_19 ( V_8 , 0 ) ;
if ( V_14 ) {
F_31 ( V_65 , & V_14 -> V_56 ) ;
F_31 ( V_62 , & V_14 -> V_56 ) ;
F_68 ( V_64 , & V_14 -> V_56 ) ;
if ( F_99 ( & V_14 -> V_22 ) )
F_51 ( L_42 , V_8 ) ;
if ( F_99 ( & V_14 -> V_24 ) )
F_51 ( L_43 , V_8 ) ;
F_96 ( V_14 ) ;
F_41 ( V_14 , true ) ;
}
return 0 ;
}
static void V_25 ( struct V_237 * V_238 )
{
struct V_10 * V_14 = F_100 ( V_238 , struct V_10 , V_24 ) ;
int V_130 ;
F_31 ( V_55 , & V_14 -> V_56 ) ;
do {
V_130 = V_14 -> V_28 ( V_14 ) ;
} while ( ! V_130 );
}
static void V_23 ( struct V_237 * V_238 )
{
struct V_10 * V_14 = F_100 ( V_238 , struct V_10 , V_22 ) ;
if ( F_32 ( V_65 , & V_14 -> V_56 ) ) {
V_14 -> V_27 ( V_14 ) ;
F_68 ( V_62 , & V_14 -> V_56 ) ;
}
if ( F_32 ( V_62 , & V_14 -> V_56 ) )
F_93 ( V_14 ) ;
}
static void F_101 ( void )
{
F_16 ( F_96 ) ;
}
static void F_102 ( void )
{
F_103 ( V_57 ) ;
F_103 ( V_63 ) ;
}
static int F_104 ( void )
{
V_57 = F_105 ( L_44 ,
V_239 | V_240 , 1 ) ;
if ( ! V_57 ) {
F_51 ( L_45 ) ;
return - V_71 ;
}
V_63 = F_105 ( L_46 ,
V_239 | V_240 , 1 ) ;
if ( ! V_63 ) {
F_51 ( L_47 ) ;
F_103 ( V_57 ) ;
return - V_71 ;
}
return 0 ;
}
static void F_106 ( struct V_10 * V_14 )
{
V_14 -> V_56 |= 0x0F ;
if ( V_14 -> V_52 && V_14 -> V_52 -> V_53 )
V_14 -> V_52 -> V_53 -> V_76 = NULL ;
}
static void F_107 ( struct V_10 * V_14 )
{
F_41 ( V_14 , true ) ;
if ( V_14 -> V_87 )
F_108 ( V_16 , V_14 -> V_87 ) ;
F_109 ( & V_14 -> V_17 ) ;
F_108 ( V_16 , V_14 ) ;
}
void F_110 ( void )
{
F_20 ( & V_32 ) ;
F_16 ( F_106 ) ;
F_21 ( & V_32 ) ;
F_102 () ;
F_20 ( & V_32 ) ;
F_101 () ;
F_16 ( F_107 ) ;
F_21 ( & V_32 ) ;
F_111 ( V_16 ) ;
}
int F_112 ( void )
{
int error = - V_196 ;
struct V_10 * V_14 ;
int V_30 ;
for ( V_30 = 0 ; V_30 < V_9 ; V_30 ++ )
F_113 ( & V_18 [ V_30 ] ) ;
F_81 () ;
if ( ! V_39 ) {
error = - V_165 ;
F_51 ( L_48 ) ;
goto V_187;
}
error = - V_71 ;
V_16 = F_114 ( L_49 , sizeof( struct V_10 ) ,
F_115 ( struct V_10 ) , 0 ,
NULL ) ;
if ( ! V_16 )
goto V_187;
if ( V_68 . V_69 == 0 )
error = F_87 () ;
else
error = F_86 () ;
if ( error )
goto V_241;
error = F_104 () ;
if ( error )
goto V_241;
return 0 ;
V_241:
V_14 = F_19 ( 0 , 0 ) ;
if ( V_14 ) {
F_41 ( V_14 , false ) ;
F_108 ( V_16 , V_14 ) ;
}
F_111 ( V_16 ) ;
V_187:
return error ;
}
