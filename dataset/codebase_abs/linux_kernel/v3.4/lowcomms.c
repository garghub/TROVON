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
V_50 -> V_51 = V_49 -> V_51 ;
}
return 0 ;
}
static void F_25 ( struct V_52 * V_53 , int V_54 )
{
struct V_10 * V_14 = F_26 ( V_53 ) ;
if ( V_14 && ! F_27 ( V_55 , & V_14 -> V_56 ) )
F_28 ( V_57 , & V_14 -> V_24 ) ;
}
static void F_29 ( struct V_52 * V_53 )
{
struct V_10 * V_14 = F_26 ( V_53 ) ;
if ( ! V_14 )
return;
F_30 ( V_58 , & V_14 -> V_52 -> V_56 ) ;
if ( F_31 ( V_59 , & V_14 -> V_56 ) ) {
V_14 -> V_52 -> V_53 -> V_60 -- ;
F_30 ( V_61 , & V_14 -> V_52 -> V_56 ) ;
}
if ( ! F_27 ( V_62 , & V_14 -> V_56 ) )
F_28 ( V_63 , & V_14 -> V_22 ) ;
}
static inline void F_32 ( struct V_10 * V_14 )
{
if ( F_33 ( V_64 , & V_14 -> V_56 ) )
return;
if ( ! F_27 ( V_65 , & V_14 -> V_56 ) )
F_28 ( V_63 , & V_14 -> V_22 ) ;
}
static void F_34 ( struct V_52 * V_53 )
{
if ( V_53 -> V_66 == V_67 )
F_29 ( V_53 ) ;
}
int F_35 ( int V_8 )
{
struct V_10 * V_14 ;
if ( V_68 . V_69 != 0 )
return 0 ;
if ( V_8 == F_36 () )
return 0 ;
V_14 = F_19 ( V_8 , V_70 ) ;
if ( ! V_14 )
return - V_71 ;
F_32 ( V_14 ) ;
return 0 ;
}
static int F_37 ( struct V_72 * V_52 , struct V_10 * V_14 )
{
V_14 -> V_52 = V_52 ;
V_14 -> V_52 -> V_53 -> V_73 = F_25 ;
V_14 -> V_52 -> V_53 -> V_74 = F_29 ;
V_14 -> V_52 -> V_53 -> V_75 = F_34 ;
V_14 -> V_52 -> V_53 -> V_76 = V_14 ;
V_14 -> V_52 -> V_53 -> V_77 = V_70 ;
return 0 ;
}
static void F_38 ( struct V_37 * V_78 , T_2 V_79 ,
int * V_80 )
{
V_78 -> V_41 = V_40 [ 0 ] -> V_41 ;
if ( V_78 -> V_41 == V_42 ) {
struct V_43 * V_81 = (struct V_43 * ) V_78 ;
V_81 -> V_82 = F_39 ( V_79 ) ;
* V_80 = sizeof( struct V_43 ) ;
memset ( & V_81 -> V_83 , 0 , sizeof( V_81 -> V_83 ) ) ;
} else {
struct V_48 * V_84 = (struct V_48 * ) V_78 ;
V_84 -> V_85 = F_39 ( V_79 ) ;
* V_80 = sizeof( struct V_48 ) ;
}
memset ( ( char * ) V_78 + * V_80 , 0 , sizeof( struct V_37 ) - * V_80 ) ;
}
static void F_40 ( struct V_10 * V_14 , bool V_86 )
{
F_20 ( & V_14 -> V_19 ) ;
if ( V_14 -> V_52 ) {
F_41 ( V_14 -> V_52 ) ;
V_14 -> V_52 = NULL ;
}
if ( V_14 -> V_87 && V_86 ) {
F_40 ( V_14 -> V_87 , false ) ;
}
if ( V_14 -> V_88 ) {
F_42 ( V_14 -> V_88 ) ;
V_14 -> V_88 = NULL ;
}
V_14 -> V_89 = 0 ;
F_21 ( & V_14 -> V_19 ) ;
}
static void F_43 ( T_3 V_90 )
{
static char V_91 [ F_44 ( sizeof( struct V_92 ) ) ] ;
struct V_93 V_94 ;
struct V_95 * V_96 ;
struct V_92 * V_97 ;
int V_98 ;
struct V_10 * V_14 ;
V_14 = F_19 ( 0 , 0 ) ;
F_45 ( V_14 == NULL ) ;
V_94 . V_99 = NULL ;
V_94 . V_100 = 0 ;
V_94 . V_101 = V_91 ;
V_94 . V_102 = sizeof( V_91 ) ;
V_94 . V_103 = V_104 ;
V_96 = F_46 ( & V_94 ) ;
V_96 -> V_105 = V_106 ;
V_96 -> V_107 = V_108 ;
V_96 -> V_109 = F_47 ( sizeof( struct V_92 ) ) ;
V_94 . V_102 = V_96 -> V_109 ;
V_97 = F_48 ( V_96 ) ;
memset ( V_97 , 0x00 , sizeof( struct V_92 ) ) ;
V_97 -> V_110 |= V_111 ;
V_97 -> V_112 = V_90 ;
V_98 = F_49 ( V_14 -> V_52 , & V_94 , NULL , 0 , 0 ) ;
if ( V_98 != 0 )
F_50 ( L_1 , V_98 ) ;
}
static void F_51 ( struct V_10 * V_14 )
{
V_14 -> V_34 = 0 ;
if ( F_31 ( V_65 , & V_14 -> V_56 ) ) {
if ( ! F_27 ( V_62 , & V_14 -> V_56 ) )
F_28 ( V_63 , & V_14 -> V_22 ) ;
}
}
static void F_52 ( void )
{
F_20 ( & V_32 ) ;
F_16 ( F_51 ) ;
F_21 ( & V_32 ) ;
}
static void F_53 ( struct V_10 * V_14 ,
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
if ( ( int ) V_116 -> V_120 . V_128 <= 0 ) {
F_50 ( L_2 ,
( int ) V_116 -> V_120 . V_128 ) ;
F_52 () ;
return;
}
memset ( & V_125 , 0 , sizeof( struct V_124 ) ) ;
V_126 = sizeof( struct V_124 ) ;
V_125 . V_129 = V_116 -> V_120 . V_128 ;
V_98 = F_54 ( V_14 -> V_52 ,
V_106 ,
V_130 ,
( char * ) & V_125 ,
& V_126 ) ;
if ( V_98 < 0 ) {
F_50 ( L_3
L_4 ,
( int ) V_116 -> V_120 . V_128 ,
V_98 ) ;
V_127 = F_22 ( V_116 -> V_120 . V_128 ) ;
if ( V_127 )
F_30 ( V_65 , & V_14 -> V_56 ) ;
return;
}
F_38 ( & V_125 . V_131 , 0 , & V_80 ) ;
if ( F_55 ( & V_125 . V_131 , & V_8 ) ) {
unsigned char * V_132 = ( unsigned char * ) & V_125 . V_131 ;
F_50 ( L_5 ) ;
F_56 ( L_6 , V_133 ,
V_132 , sizeof( struct V_37 ) ) ;
F_43 ( V_125 . V_129 ) ;
return;
}
V_127 = F_19 ( V_8 , V_70 ) ;
if ( ! V_127 )
return;
F_57 ( V_14 -> V_52 -> V_53 ) ;
V_98 = F_58 ( V_14 -> V_52 -> V_53 ,
V_116 -> V_120 . V_128 ,
& V_127 -> V_52 ) ;
F_59 ( V_14 -> V_52 -> V_53 ) ;
if ( V_98 < 0 ) {
F_50 ( L_7
L_8 ,
( int ) V_116 -> V_120 . V_128 ,
V_8 , V_98 ) ;
return;
}
F_37 ( V_127 -> V_52 , V_127 ) ;
F_50 ( L_9 ,
V_8 , ( int ) V_116 -> V_120 . V_128 ) ;
F_30 ( V_65 , & V_127 -> V_56 ) ;
F_30 ( V_134 , & V_14 -> V_56 ) ;
if ( ! F_27 ( V_62 , & V_127 -> V_56 ) ) {
F_28 ( V_63 , & V_127 -> V_22 ) ;
}
if ( ! F_27 ( V_55 , & V_127 -> V_56 ) )
F_28 ( V_57 , & V_127 -> V_24 ) ;
}
break;
case V_135 :
case V_136 :
{
V_14 = F_22 ( V_116 -> V_120 . V_128 ) ;
if ( V_14 ) {
V_14 -> V_34 = 0 ;
}
}
break;
case V_137 :
{
F_50 ( L_10 ) ;
F_52 () ;
}
break;
default:
F_50 ( L_11 ,
( int ) V_116 -> V_120 . V_128 ,
V_116 -> V_120 . V_121 ) ;
}
}
}
static int F_60 ( struct V_10 * V_14 )
{
int V_98 = 0 ;
struct V_93 V_113 = {} ;
struct V_138 V_139 [ 2 ] ;
unsigned V_4 ;
int V_11 ;
int V_140 = 0 ;
int V_141 ;
char V_142 [ F_44 ( sizeof( struct V_92 ) ) ] ;
F_20 ( & V_14 -> V_19 ) ;
if ( V_14 -> V_52 == NULL ) {
V_98 = - V_143 ;
goto V_144;
}
if ( V_14 -> V_88 == NULL ) {
V_14 -> V_88 = F_61 ( V_145 ) ;
if ( V_14 -> V_88 == NULL )
goto V_146;
F_3 ( & V_14 -> V_2 , V_147 ) ;
}
memset ( & V_142 , 0 , sizeof( V_142 ) ) ;
V_113 . V_101 = V_142 ;
V_113 . V_102 = sizeof( V_142 ) ;
V_139 [ 0 ] . V_148 = V_14 -> V_2 . V_5 - F_2 ( & V_14 -> V_2 ) ;
V_139 [ 0 ] . V_149 = F_62 ( V_14 -> V_88 ) + F_2 ( & V_14 -> V_2 ) ;
V_139 [ 1 ] . V_148 = 0 ;
V_141 = 1 ;
if ( F_2 ( & V_14 -> V_2 ) >= V_14 -> V_2 . V_5 ) {
V_139 [ 0 ] . V_148 = V_147 - F_2 ( & V_14 -> V_2 ) ;
V_139 [ 1 ] . V_148 = V_14 -> V_2 . V_5 ;
V_139 [ 1 ] . V_149 = F_62 ( V_14 -> V_88 ) ;
V_141 = 2 ;
}
V_4 = V_139 [ 0 ] . V_148 + V_139 [ 1 ] . V_148 ;
V_11 = V_98 = F_63 ( V_14 -> V_52 , & V_113 , V_139 , V_141 , V_4 ,
V_150 | V_151 ) ;
if ( V_98 <= 0 )
goto V_144;
if ( V_113 . V_103 & V_152 ) {
V_113 . V_101 = V_142 ;
V_113 . V_102 = sizeof( V_142 ) ;
F_53 ( V_14 , & V_113 ,
F_62 ( V_14 -> V_88 ) + V_14 -> V_2 . V_5 ) ;
F_21 ( & V_14 -> V_19 ) ;
return 0 ;
}
F_45 ( V_14 -> V_8 == 0 ) ;
if ( V_98 == V_4 )
V_140 = 1 ;
F_1 ( & V_14 -> V_2 , V_98 ) ;
V_98 = F_64 ( V_14 -> V_8 ,
F_62 ( V_14 -> V_88 ) ,
V_14 -> V_2 . V_5 , V_14 -> V_2 . V_4 ,
V_147 ) ;
if ( V_98 == - V_153 ) {
F_50 ( L_12
L_13 ,
F_62 ( V_14 -> V_88 ) , V_14 -> V_2 . V_5 , V_14 -> V_2 . V_4 ,
V_4 , V_139 [ 0 ] . V_149 , V_11 ) ;
}
if ( V_98 < 0 )
goto V_144;
F_4 ( & V_14 -> V_2 , V_98 ) ;
if ( F_5 ( & V_14 -> V_2 ) && ! V_140 ) {
F_42 ( V_14 -> V_88 ) ;
V_14 -> V_88 = NULL ;
}
if ( V_140 )
goto V_146;
F_21 ( & V_14 -> V_19 ) ;
return 0 ;
V_146:
if ( ! F_27 ( V_55 , & V_14 -> V_56 ) )
F_28 ( V_57 , & V_14 -> V_24 ) ;
F_21 ( & V_14 -> V_19 ) ;
return - V_143 ;
V_144:
F_21 ( & V_14 -> V_19 ) ;
if ( V_98 != - V_143 ) {
F_40 ( V_14 , false ) ;
}
if ( V_98 == 0 )
V_98 = - V_143 ;
return V_98 ;
}
static int F_65 ( struct V_10 * V_14 )
{
int V_154 ;
struct V_37 V_155 ;
struct V_72 * V_156 ;
int V_4 ;
int V_8 ;
struct V_10 * V_157 ;
struct V_10 * V_158 ;
memset ( & V_155 , 0 , sizeof( V_155 ) ) ;
V_154 = F_66 ( V_40 [ 0 ] -> V_41 , V_159 ,
V_160 , & V_156 ) ;
if ( V_154 < 0 )
return - V_71 ;
F_67 ( & V_14 -> V_19 , 0 ) ;
V_154 = - V_161 ;
if ( V_14 -> V_52 == NULL )
goto V_162;
V_156 -> type = V_14 -> V_52 -> type ;
V_156 -> V_163 = V_14 -> V_52 -> V_163 ;
V_154 = V_14 -> V_52 -> V_163 -> V_164 ( V_14 -> V_52 , V_156 , V_165 ) ;
if ( V_154 < 0 )
goto V_162;
memset ( & V_155 , 0 , sizeof( V_155 ) ) ;
if ( V_156 -> V_163 -> V_166 ( V_156 , (struct V_35 * ) & V_155 ,
& V_4 , 2 ) ) {
V_154 = - V_167 ;
goto V_162;
}
F_38 ( & V_155 , 0 , & V_4 ) ;
if ( F_55 ( & V_155 , & V_8 ) ) {
unsigned char * V_132 = ( unsigned char * ) & V_155 ;
F_50 ( L_14 ) ;
F_56 ( L_6 , V_133 ,
V_132 , sizeof( struct V_37 ) ) ;
F_41 ( V_156 ) ;
F_21 ( & V_14 -> V_19 ) ;
return - 1 ;
}
F_50 ( L_15 , V_8 ) ;
V_157 = F_19 ( V_8 , V_70 ) ;
if ( ! V_157 ) {
V_154 = - V_71 ;
goto V_162;
}
F_67 ( & V_157 -> V_19 , 1 ) ;
if ( V_157 -> V_52 ) {
struct V_10 * V_87 = V_157 -> V_87 ;
if ( ! V_87 ) {
V_87 = F_10 ( V_16 , V_70 ) ;
if ( ! V_87 ) {
F_50 ( L_16 ) ;
F_21 ( & V_157 -> V_19 ) ;
V_154 = - V_71 ;
goto V_162;
}
V_87 -> V_8 = V_8 ;
V_87 -> V_28 = F_60 ;
F_12 ( & V_87 -> V_19 ) ;
F_15 ( & V_87 -> V_22 , V_23 ) ;
F_15 ( & V_87 -> V_24 , V_25 ) ;
F_68 ( V_168 , & V_87 -> V_56 ) ;
}
if ( ! V_87 -> V_52 ) {
V_157 -> V_87 = V_87 ;
V_87 -> V_52 = V_156 ;
V_156 -> V_53 -> V_76 = V_87 ;
F_37 ( V_156 , V_87 ) ;
V_158 = V_87 ;
}
else {
F_69 ( L_17 , V_8 ) ;
V_154 = - V_143 ;
F_21 ( & V_157 -> V_19 ) ;
goto V_162;
}
}
else {
V_156 -> V_53 -> V_76 = V_157 ;
V_157 -> V_28 = F_60 ;
F_37 ( V_156 , V_157 ) ;
V_158 = V_157 ;
}
F_21 ( & V_157 -> V_19 ) ;
if ( ! F_27 ( V_55 , & V_158 -> V_56 ) )
F_28 ( V_57 , & V_158 -> V_24 ) ;
F_21 ( & V_14 -> V_19 ) ;
return 0 ;
V_162:
F_21 ( & V_14 -> V_19 ) ;
F_41 ( V_156 ) ;
if ( V_154 != - V_143 )
F_50 ( L_18 , V_154 ) ;
return V_154 ;
}
static void F_70 ( struct V_169 * V_170 )
{
F_42 ( V_170 -> V_171 ) ;
F_71 ( V_170 ) ;
}
static void F_72 ( struct V_10 * V_14 )
{
struct V_37 V_172 ;
char V_91 [ F_44 ( sizeof( struct V_92 ) ) ] ;
struct V_93 V_94 ;
struct V_95 * V_96 ;
struct V_92 * V_97 ;
struct V_10 * V_173 ;
struct V_169 * V_170 ;
int V_4 , V_174 ;
int V_98 ;
int V_175 ;
struct V_138 V_139 [ 1 ] ;
if ( F_27 ( V_134 , & V_14 -> V_56 ) )
return;
if ( V_14 -> V_89 ++ > V_176 )
return;
if ( F_23 ( V_14 -> V_8 , (struct V_35 * ) & V_172 ) ) {
F_50 ( L_19 , V_14 -> V_8 ) ;
return;
}
V_173 = F_19 ( 0 , 0 ) ;
F_45 ( V_173 == NULL ) ;
F_38 ( & V_172 , V_68 . V_177 , & V_175 ) ;
V_94 . V_99 = & V_172 ;
V_94 . V_100 = V_175 ;
V_94 . V_101 = V_91 ;
V_94 . V_102 = sizeof( V_91 ) ;
V_94 . V_103 = V_104 ;
F_73 ( & V_14 -> V_21 ) ;
if ( F_74 ( & V_14 -> V_20 ) ) {
F_75 ( & V_14 -> V_21 ) ;
F_50 ( L_20 , V_14 -> V_8 ) ;
return;
}
V_170 = F_76 ( & V_14 -> V_20 , struct V_169 , V_17 ) ;
V_4 = V_170 -> V_4 ;
V_174 = V_170 -> V_174 ;
F_75 ( & V_14 -> V_21 ) ;
V_139 [ 0 ] . V_149 = F_62 ( V_170 -> V_171 ) + V_174 ;
V_139 [ 0 ] . V_148 = V_4 ;
V_96 = F_46 ( & V_94 ) ;
V_96 -> V_105 = V_106 ;
V_96 -> V_107 = V_108 ;
V_96 -> V_109 = F_47 ( sizeof( struct V_92 ) ) ;
V_97 = F_48 ( V_96 ) ;
memset ( V_97 , 0x00 , sizeof( struct V_92 ) ) ;
V_97 -> V_178 = F_77 ( F_36 () ) ;
V_94 . V_102 = V_96 -> V_109 ;
V_98 = F_49 ( V_173 -> V_52 , & V_94 , V_139 , 1 , V_4 ) ;
if ( V_98 < 0 ) {
F_50 ( L_21 ,
V_14 -> V_8 , V_98 ) ;
F_30 ( V_65 , & V_14 -> V_56 ) ;
F_30 ( V_134 , & V_14 -> V_56 ) ;
}
else {
F_73 ( & V_14 -> V_21 ) ;
V_170 -> V_174 += V_98 ;
V_170 -> V_4 -= V_98 ;
if ( V_170 -> V_4 == 0 && V_170 -> V_179 == 0 ) {
F_78 ( & V_170 -> V_17 ) ;
F_70 ( V_170 ) ;
}
F_75 ( & V_14 -> V_21 ) ;
}
}
static void F_79 ( struct V_10 * V_14 )
{
int V_154 = - V_180 ;
struct V_37 V_78 , V_181 ;
int V_80 ;
struct V_72 * V_52 = NULL ;
int V_182 = 1 ;
if ( V_14 -> V_8 == 0 ) {
F_50 ( L_22 ) ;
return;
}
F_20 ( & V_14 -> V_19 ) ;
if ( V_14 -> V_89 ++ > V_176 )
goto V_183;
if ( V_14 -> V_52 ) {
V_154 = 0 ;
goto V_183;
}
V_154 = F_66 ( V_40 [ 0 ] -> V_41 , V_159 ,
V_160 , & V_52 ) ;
if ( V_154 < 0 )
goto V_184;
memset ( & V_78 , 0 , sizeof( V_78 ) ) ;
if ( F_24 ( V_14 -> V_8 , & V_78 ) )
goto V_184;
V_52 -> V_53 -> V_76 = V_14 ;
V_14 -> V_28 = F_60 ;
V_14 -> V_27 = F_79 ;
F_37 ( V_52 , V_14 ) ;
memcpy ( & V_181 , V_40 [ 0 ] , sizeof( V_181 ) ) ;
F_38 ( & V_181 , 0 , & V_80 ) ;
V_154 = V_52 -> V_163 -> V_185 ( V_52 , (struct V_35 * ) & V_181 ,
V_80 ) ;
if ( V_154 < 0 ) {
F_50 ( L_23 , V_154 ) ;
}
F_38 ( & V_78 , V_68 . V_177 , & V_80 ) ;
F_50 ( L_24 , V_14 -> V_8 ) ;
F_80 ( V_52 , V_186 , V_187 , ( char * ) & V_182 ,
sizeof( V_182 ) ) ;
V_154 =
V_52 -> V_163 -> V_188 ( V_52 , (struct V_35 * ) & V_78 , V_80 ,
V_165 ) ;
if ( V_154 == - V_189 )
V_154 = 0 ;
if ( V_154 == 0 )
goto V_183;
V_184:
if ( V_14 -> V_52 ) {
F_41 ( V_14 -> V_52 ) ;
V_14 -> V_52 = NULL ;
} else if ( V_52 ) {
F_41 ( V_52 ) ;
}
if ( V_154 != - V_180 && V_154 != - V_190 &&
V_154 != - V_191 && V_154 != - V_192
&& V_154 != - V_193 ) {
F_32 ( V_14 ) ;
V_154 = 0 ;
}
V_183:
F_21 ( & V_14 -> V_19 ) ;
return;
}
static struct V_72 * F_81 ( struct V_10 * V_14 ,
struct V_37 * V_78 )
{
struct V_72 * V_52 = NULL ;
int V_154 = 0 ;
int V_182 = 1 ;
int V_80 ;
if ( V_40 [ 0 ] -> V_41 == V_42 )
V_80 = sizeof( struct V_43 ) ;
else
V_80 = sizeof( struct V_48 ) ;
V_154 = F_66 ( V_40 [ 0 ] -> V_41 , V_159 ,
V_160 , & V_52 ) ;
if ( V_154 < 0 ) {
F_50 ( L_25 ) ;
goto V_194;
}
F_80 ( V_52 , V_186 , V_187 , ( char * ) & V_182 ,
sizeof( V_182 ) ) ;
V_154 = F_80 ( V_52 , V_195 , V_196 ,
( char * ) & V_182 , sizeof( V_182 ) ) ;
if ( V_154 < 0 ) {
F_50 ( L_26 , V_154 ) ;
}
V_52 -> V_53 -> V_76 = V_14 ;
V_14 -> V_28 = F_65 ;
V_14 -> V_27 = F_79 ;
V_14 -> V_52 = V_52 ;
F_38 ( V_78 , V_68 . V_177 , & V_80 ) ;
V_154 = V_52 -> V_163 -> V_185 ( V_52 , (struct V_35 * ) V_78 , V_80 ) ;
if ( V_154 < 0 ) {
F_50 ( L_27 , V_68 . V_177 ) ;
F_41 ( V_52 ) ;
V_52 = NULL ;
V_14 -> V_52 = NULL ;
goto V_194;
}
V_154 = F_80 ( V_52 , V_195 , V_197 ,
( char * ) & V_182 , sizeof( V_182 ) ) ;
if ( V_154 < 0 ) {
F_50 ( L_28 , V_154 ) ;
}
V_154 = V_52 -> V_163 -> V_198 ( V_52 , 5 ) ;
if ( V_154 < 0 ) {
F_50 ( L_29 , V_68 . V_177 ) ;
F_41 ( V_52 ) ;
V_52 = NULL ;
goto V_194;
}
V_194:
return V_52 ;
}
static void F_82 ( void )
{
struct V_37 V_199 , * V_38 ;
int V_30 ;
V_39 = 0 ;
for ( V_30 = 0 ; V_30 < V_200 ; V_30 ++ ) {
if ( F_83 ( & V_199 , V_30 ) )
break;
V_38 = F_84 ( sizeof( * V_38 ) , V_70 ) ;
if ( ! V_38 )
break;
memcpy ( V_38 , & V_199 , sizeof( * V_38 ) ) ;
V_40 [ V_39 ++ ] = V_38 ;
}
}
static int F_85 ( struct V_10 * V_201 ,
struct V_37 * V_38 ,
int V_80 , int V_202 )
{
int V_154 = 0 ;
if ( V_202 == 1 )
V_154 = F_86 ( V_201 -> V_52 ,
(struct V_35 * ) V_38 ,
V_80 ) ;
else
V_154 = F_80 ( V_201 -> V_52 , V_203 ,
V_204 ,
( char * ) V_38 , V_80 ) ;
if ( V_154 < 0 )
F_50 ( L_30 ,
V_68 . V_177 , V_202 ) ;
return V_154 ;
}
static int F_87 ( void )
{
struct V_72 * V_52 = NULL ;
struct V_37 V_205 ;
struct V_206 V_207 ;
int V_154 = - V_192 , V_202 = 1 , V_30 , V_80 ;
struct V_10 * V_14 = F_19 ( 0 , V_70 ) ;
int V_208 = V_209 ;
if ( ! V_14 )
return - V_71 ;
F_50 ( L_31 ) ;
V_154 = F_66 ( V_40 [ 0 ] -> V_41 , V_210 ,
V_106 , & V_52 ) ;
if ( V_154 < 0 ) {
F_50 ( L_32 ) ;
goto V_183;
}
memset ( & V_207 , 0 , sizeof( V_207 ) ) ;
V_207 . V_211 = 1 ;
V_207 . V_212 = 1 ;
V_207 . V_213 = 1 ;
V_207 . V_214 = 1 ;
V_207 . V_215 = 1 ;
V_154 = F_80 ( V_52 , V_195 , V_216 ,
( char * ) & V_208 , sizeof( V_208 ) ) ;
if ( V_154 )
F_50 ( L_33 , V_154 ) ;
V_154 = F_80 ( V_52 , V_203 , V_217 ,
( char * ) & V_207 , sizeof( V_207 ) ) ;
if ( V_154 < 0 ) {
F_50 ( L_34 ,
V_154 ) ;
goto V_218;
}
V_52 -> V_53 -> V_76 = V_14 ;
V_14 -> V_52 = V_52 ;
V_14 -> V_52 -> V_53 -> V_73 = F_25 ;
V_14 -> V_28 = F_60 ;
V_14 -> V_27 = F_72 ;
for ( V_30 = 0 ; V_30 < V_39 ; V_30 ++ ) {
memcpy ( & V_205 , V_40 [ V_30 ] , sizeof( V_205 ) ) ;
F_38 ( & V_205 , V_68 . V_177 , & V_80 ) ;
V_154 = F_85 ( V_14 , & V_205 , V_80 , V_202 ) ;
if ( V_154 )
goto V_218;
++ V_202 ;
}
V_154 = V_52 -> V_163 -> V_198 ( V_52 , 5 ) ;
if ( V_154 < 0 ) {
F_50 ( L_35 ) ;
goto V_218;
}
return 0 ;
V_218:
F_41 ( V_52 ) ;
V_14 -> V_52 = NULL ;
V_183:
return V_154 ;
}
static int F_88 ( void )
{
struct V_72 * V_52 = NULL ;
struct V_10 * V_14 = F_19 ( 0 , V_70 ) ;
int V_154 = - V_192 ;
if ( ! V_14 )
return - V_71 ;
if ( V_40 [ 1 ] != NULL ) {
F_50 ( L_36
L_37 ) ;
return - V_192 ;
}
F_50 ( L_38 ) ;
V_52 = F_81 ( V_14 , V_40 [ 0 ] ) ;
if ( V_52 ) {
F_37 ( V_52 , V_14 ) ;
V_154 = 0 ;
}
else {
V_154 = - V_219 ;
}
return V_154 ;
}
static struct V_169 * F_89 ( struct V_10 * V_14 ,
T_1 V_31 )
{
struct V_169 * V_220 ;
V_220 = F_84 ( sizeof( struct V_169 ) , V_31 ) ;
if ( ! V_220 )
return NULL ;
V_220 -> V_171 = F_61 ( V_31 ) ;
if ( ! V_220 -> V_171 ) {
F_71 ( V_220 ) ;
return NULL ;
}
V_220 -> V_174 = 0 ;
V_220 -> V_4 = 0 ;
V_220 -> V_221 = 0 ;
V_220 -> V_179 = 0 ;
V_220 -> V_14 = V_14 ;
return V_220 ;
}
void * F_90 ( int V_8 , int V_4 , T_1 V_31 , char * * V_222 )
{
struct V_10 * V_14 ;
struct V_169 * V_170 ;
int V_174 = 0 ;
int V_179 = 0 ;
V_14 = F_19 ( V_8 , V_31 ) ;
if ( ! V_14 )
return NULL ;
F_73 ( & V_14 -> V_21 ) ;
V_170 = F_91 ( V_14 -> V_20 . V_223 , struct V_169 , V_17 ) ;
if ( ( & V_170 -> V_17 == & V_14 -> V_20 ) ||
( V_147 - V_170 -> V_221 < V_4 ) ) {
V_170 = NULL ;
} else {
V_174 = V_170 -> V_221 ;
V_170 -> V_221 += V_4 ;
V_179 = V_170 -> V_179 ++ ;
}
F_75 ( & V_14 -> V_21 ) ;
if ( V_170 ) {
V_224:
* V_222 = F_62 ( V_170 -> V_171 ) + V_174 ;
return V_170 ;
}
V_170 = F_89 ( V_14 , V_31 ) ;
if ( V_170 ) {
F_73 ( & V_14 -> V_21 ) ;
V_174 = V_170 -> V_221 ;
V_170 -> V_221 += V_4 ;
V_179 = V_170 -> V_179 ++ ;
F_92 ( & V_170 -> V_17 , & V_14 -> V_20 ) ;
F_75 ( & V_14 -> V_21 ) ;
goto V_224;
}
return NULL ;
}
void F_93 ( void * V_225 )
{
struct V_169 * V_170 = (struct V_169 * ) V_225 ;
struct V_10 * V_14 = V_170 -> V_14 ;
int V_179 ;
F_73 ( & V_14 -> V_21 ) ;
V_179 = -- V_170 -> V_179 ;
if ( V_179 )
goto V_183;
V_170 -> V_4 = V_170 -> V_221 - V_170 -> V_174 ;
F_75 ( & V_14 -> V_21 ) ;
if ( ! F_27 ( V_62 , & V_14 -> V_56 ) ) {
F_28 ( V_63 , & V_14 -> V_22 ) ;
}
return;
V_183:
F_75 ( & V_14 -> V_21 ) ;
return;
}
static void F_94 ( struct V_10 * V_14 )
{
int V_98 = 0 ;
const int V_103 = V_150 | V_151 ;
struct V_169 * V_170 ;
int V_4 , V_174 ;
int V_226 = 0 ;
F_20 ( & V_14 -> V_19 ) ;
if ( V_14 -> V_52 == NULL )
goto V_227;
F_73 ( & V_14 -> V_21 ) ;
for (; ; ) {
V_170 = F_91 ( V_14 -> V_20 . V_228 , struct V_169 ,
V_17 ) ;
if ( (struct V_229 * ) V_170 == & V_14 -> V_20 )
break;
V_4 = V_170 -> V_4 ;
V_174 = V_170 -> V_174 ;
F_45 ( V_4 == 0 && V_170 -> V_179 == 0 ) ;
F_75 ( & V_14 -> V_21 ) ;
V_98 = 0 ;
if ( V_4 ) {
V_98 = F_95 ( V_14 -> V_52 , V_170 -> V_171 , V_174 , V_4 ,
V_103 ) ;
if ( V_98 == - V_143 || V_98 == 0 ) {
if ( V_98 == - V_143 &&
F_33 ( V_61 , & V_14 -> V_52 -> V_56 ) &&
! F_27 ( V_59 , & V_14 -> V_56 ) ) {
F_68 ( V_58 , & V_14 -> V_52 -> V_56 ) ;
V_14 -> V_52 -> V_53 -> V_60 ++ ;
}
F_96 () ;
goto V_183;
}
if ( V_98 <= 0 )
goto V_230;
}
if ( ++ V_226 >= V_231 ) {
F_96 () ;
V_226 = 0 ;
}
F_73 ( & V_14 -> V_21 ) ;
V_170 -> V_174 += V_98 ;
V_170 -> V_4 -= V_98 ;
if ( V_170 -> V_4 == 0 && V_170 -> V_179 == 0 ) {
F_78 ( & V_170 -> V_17 ) ;
F_70 ( V_170 ) ;
continue;
}
}
F_75 ( & V_14 -> V_21 ) ;
V_183:
F_21 ( & V_14 -> V_19 ) ;
return;
V_230:
F_21 ( & V_14 -> V_19 ) ;
F_40 ( V_14 , false ) ;
F_32 ( V_14 ) ;
return;
V_227:
F_21 ( & V_14 -> V_19 ) ;
if ( ! F_33 ( V_134 , & V_14 -> V_56 ) )
F_32 ( V_14 ) ;
return;
}
static void F_97 ( struct V_10 * V_14 )
{
struct V_169 * V_170 , * V_232 ;
F_73 ( & V_14 -> V_21 ) ;
F_98 (e, safe, &con->writequeue, list) {
F_78 ( & V_170 -> V_17 ) ;
F_70 ( V_170 ) ;
}
F_75 ( & V_14 -> V_21 ) ;
}
int F_99 ( int V_8 )
{
struct V_10 * V_14 ;
F_50 ( L_39 , V_8 ) ;
V_14 = F_19 ( V_8 , 0 ) ;
if ( V_14 ) {
F_30 ( V_65 , & V_14 -> V_56 ) ;
F_30 ( V_62 , & V_14 -> V_56 ) ;
F_68 ( V_64 , & V_14 -> V_56 ) ;
if ( F_100 ( & V_14 -> V_22 ) )
F_50 ( L_40 , V_8 ) ;
if ( F_100 ( & V_14 -> V_24 ) )
F_50 ( L_41 , V_8 ) ;
F_97 ( V_14 ) ;
F_40 ( V_14 , true ) ;
}
return 0 ;
}
static void V_25 ( struct V_233 * V_234 )
{
struct V_10 * V_14 = F_101 ( V_234 , struct V_10 , V_24 ) ;
int V_235 ;
F_30 ( V_55 , & V_14 -> V_56 ) ;
do {
V_235 = V_14 -> V_28 ( V_14 ) ;
} while ( ! V_235 );
}
static void V_23 ( struct V_233 * V_234 )
{
struct V_10 * V_14 = F_101 ( V_234 , struct V_10 , V_22 ) ;
if ( F_31 ( V_65 , & V_14 -> V_56 ) ) {
V_14 -> V_27 ( V_14 ) ;
F_68 ( V_62 , & V_14 -> V_56 ) ;
}
if ( F_31 ( V_62 , & V_14 -> V_56 ) )
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
V_57 = F_106 ( L_42 ,
V_236 | V_237 , 1 ) ;
if ( ! V_57 ) {
F_50 ( L_43 ) ;
return - V_71 ;
}
V_63 = F_106 ( L_44 ,
V_236 | V_237 , 1 ) ;
if ( ! V_63 ) {
F_50 ( L_45 ) ;
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
F_40 ( V_14 , true ) ;
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
int error = - V_192 ;
struct V_10 * V_14 ;
int V_30 ;
for ( V_30 = 0 ; V_30 < V_9 ; V_30 ++ )
F_114 ( & V_18 [ V_30 ] ) ;
F_82 () ;
if ( ! V_39 ) {
error = - V_161 ;
F_50 ( L_46 ) ;
goto V_183;
}
error = - V_71 ;
V_16 = F_115 ( L_47 , sizeof( struct V_10 ) ,
F_116 ( struct V_10 ) , 0 ,
NULL ) ;
if ( ! V_16 )
goto V_183;
if ( V_68 . V_69 == 0 )
error = F_88 () ;
else
error = F_87 () ;
if ( error )
goto V_238;
error = F_105 () ;
if ( error )
goto V_238;
return 0 ;
V_238:
V_14 = F_19 ( 0 , 0 ) ;
if ( V_14 ) {
F_40 ( V_14 , false ) ;
F_109 ( V_16 , V_14 ) ;
}
F_112 ( V_16 ) ;
V_183:
return error ;
}
