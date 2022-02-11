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
struct V_10 * V_12 ;
V_11 = F_6 ( V_8 ) ;
F_8 (con, &connection_hash[r], list) {
if ( V_12 -> V_8 == V_8 )
return V_12 ;
}
return NULL ;
}
static struct V_10 * F_9 ( int V_8 , T_1 V_13 )
{
struct V_10 * V_12 = NULL ;
int V_11 ;
V_12 = F_7 ( V_8 ) ;
if ( V_12 || ! V_13 )
return V_12 ;
V_12 = F_10 ( V_14 , V_13 ) ;
if ( ! V_12 )
return NULL ;
V_11 = F_6 ( V_8 ) ;
F_11 ( & V_12 -> V_15 , & V_16 [ V_11 ] ) ;
V_12 -> V_8 = V_8 ;
F_12 ( & V_12 -> V_17 ) ;
F_13 ( & V_12 -> V_18 ) ;
F_14 ( & V_12 -> V_19 ) ;
F_15 ( & V_12 -> V_20 , V_21 ) ;
F_15 ( & V_12 -> V_22 , V_23 ) ;
if ( V_12 -> V_8 ) {
struct V_10 * V_24 = F_7 ( 0 ) ;
V_12 -> V_25 = V_24 -> V_25 ;
if ( ! V_12 -> V_26 )
V_12 -> V_26 = V_24 -> V_26 ;
}
return V_12 ;
}
static void F_16 ( void (* F_17)( struct V_10 * V_27 ) )
{
int V_28 ;
struct V_29 * V_3 ;
struct V_10 * V_12 ;
for ( V_28 = 0 ; V_28 < V_9 ; V_28 ++ ) {
F_18 (con, n, &connection_hash[i], list)
F_17 ( V_12 ) ;
}
}
static struct V_10 * F_19 ( int V_8 , T_1 V_30 )
{
struct V_10 * V_12 ;
F_20 ( & V_31 ) ;
V_12 = F_9 ( V_8 , V_30 ) ;
F_21 ( & V_31 ) ;
return V_12 ;
}
static struct V_10 * F_22 ( int V_32 )
{
int V_28 ;
struct V_10 * V_12 ;
F_20 ( & V_31 ) ;
for ( V_28 = 0 ; V_28 < V_9 ; V_28 ++ ) {
F_8 (con, &connection_hash[i], list) {
if ( V_12 -> V_33 == V_32 ) {
F_21 ( & V_31 ) ;
return V_12 ;
}
}
}
F_21 ( & V_31 ) ;
return NULL ;
}
static struct V_34 * F_23 ( int V_8 )
{
struct V_34 * V_35 ;
F_24 (na, &dlm_node_addrs, list) {
if ( V_35 -> V_8 == V_8 )
return V_35 ;
}
return NULL ;
}
static int F_25 ( struct V_36 * V_37 , struct V_36 * V_38 )
{
switch ( V_37 -> V_39 ) {
case V_40 : {
struct V_41 * V_42 = (struct V_41 * ) V_37 ;
struct V_41 * V_43 = (struct V_41 * ) V_38 ;
if ( V_42 -> V_44 . V_45 != V_43 -> V_44 . V_45 )
return 0 ;
if ( V_42 -> V_46 != V_43 -> V_46 )
return 0 ;
break;
}
case V_47 : {
struct V_48 * V_42 = (struct V_48 * ) V_37 ;
struct V_48 * V_43 = (struct V_48 * ) V_38 ;
if ( ! F_26 ( & V_42 -> V_49 , & V_43 -> V_49 ) )
return 0 ;
if ( V_42 -> V_50 != V_43 -> V_50 )
return 0 ;
break;
}
default:
return 0 ;
}
return 1 ;
}
static int F_27 ( int V_8 , struct V_36 * V_51 ,
struct V_52 * V_53 , bool V_54 )
{
struct V_36 V_55 ;
struct V_34 * V_35 ;
if ( ! V_56 )
return - 1 ;
F_28 ( & V_57 ) ;
V_35 = F_23 ( V_8 ) ;
if ( V_35 && V_35 -> V_58 ) {
if ( V_54 ) {
V_35 -> V_59 ++ ;
if ( V_35 -> V_59 == V_35 -> V_58 )
V_35 -> V_59 = 0 ;
}
memcpy ( & V_55 , V_35 -> V_60 [ V_35 -> V_59 ] ,
sizeof( struct V_36 ) ) ;
}
F_29 ( & V_57 ) ;
if ( ! V_35 )
return - V_61 ;
if ( ! V_35 -> V_58 )
return - V_62 ;
if ( V_51 )
memcpy ( V_51 , & V_55 , sizeof( struct V_36 ) ) ;
if ( ! V_53 )
return 0 ;
if ( V_63 [ 0 ] -> V_39 == V_40 ) {
struct V_41 * V_64 = (struct V_41 * ) & V_55 ;
struct V_41 * V_65 = (struct V_41 * ) V_53 ;
V_65 -> V_44 . V_45 = V_64 -> V_44 . V_45 ;
} else {
struct V_48 * V_66 = (struct V_48 * ) & V_55 ;
struct V_48 * V_67 = (struct V_48 * ) V_53 ;
V_67 -> V_49 = V_66 -> V_49 ;
}
return 0 ;
}
static int F_30 ( struct V_36 * V_60 , int * V_8 )
{
struct V_34 * V_35 ;
int V_68 = - V_61 ;
int V_69 ;
F_28 ( & V_57 ) ;
F_24 (na, &dlm_node_addrs, list) {
if ( ! V_35 -> V_58 )
continue;
for ( V_69 = 0 ; V_69 < V_35 -> V_58 ; V_69 ++ ) {
if ( F_25 ( V_35 -> V_60 [ V_69 ] , V_60 ) ) {
* V_8 = V_35 -> V_8 ;
V_68 = 0 ;
goto V_70;
}
}
}
V_70:
F_29 ( & V_57 ) ;
return V_68 ;
}
int F_31 ( int V_8 , struct V_36 * V_60 , int V_4 )
{
struct V_36 * V_71 ;
struct V_34 * V_72 , * V_35 ;
V_72 = F_32 ( sizeof( struct V_34 ) , V_73 ) ;
if ( ! V_72 )
return - V_74 ;
V_71 = F_32 ( sizeof( struct V_36 ) , V_73 ) ;
if ( ! V_71 ) {
F_33 ( V_72 ) ;
return - V_74 ;
}
memcpy ( V_71 , V_60 , V_4 ) ;
F_28 ( & V_57 ) ;
V_35 = F_23 ( V_8 ) ;
if ( ! V_35 ) {
V_72 -> V_8 = V_8 ;
V_72 -> V_60 [ 0 ] = V_71 ;
V_72 -> V_58 = 1 ;
F_34 ( & V_72 -> V_15 , & V_75 ) ;
F_29 ( & V_57 ) ;
return 0 ;
}
if ( V_35 -> V_58 >= V_76 ) {
F_29 ( & V_57 ) ;
F_33 ( V_71 ) ;
F_33 ( V_72 ) ;
return - V_77 ;
}
V_35 -> V_60 [ V_35 -> V_58 ++ ] = V_71 ;
F_29 ( & V_57 ) ;
F_33 ( V_72 ) ;
return 0 ;
}
static void F_35 ( struct V_78 * V_79 , int V_80 )
{
struct V_10 * V_12 = F_36 ( V_79 ) ;
if ( V_12 && ! F_37 ( V_81 , & V_12 -> V_82 ) )
F_38 ( V_83 , & V_12 -> V_22 ) ;
}
static void F_39 ( struct V_78 * V_79 )
{
struct V_10 * V_12 = F_36 ( V_79 ) ;
if ( ! V_12 )
return;
F_40 ( V_84 , & V_12 -> V_78 -> V_82 ) ;
if ( F_41 ( V_85 , & V_12 -> V_82 ) ) {
V_12 -> V_78 -> V_79 -> V_86 -- ;
F_40 ( V_87 , & V_12 -> V_78 -> V_82 ) ;
}
if ( ! F_37 ( V_88 , & V_12 -> V_82 ) )
F_38 ( V_89 , & V_12 -> V_20 ) ;
}
static inline void F_42 ( struct V_10 * V_12 )
{
if ( F_43 ( V_90 , & V_12 -> V_82 ) )
return;
if ( ! F_37 ( V_91 , & V_12 -> V_82 ) )
F_38 ( V_89 , & V_12 -> V_20 ) ;
}
static void F_44 ( struct V_78 * V_79 )
{
if ( V_79 -> V_92 == V_93 )
F_39 ( V_79 ) ;
}
int F_45 ( int V_8 )
{
struct V_10 * V_12 ;
if ( V_94 . V_95 != 0 )
return 0 ;
if ( V_8 == F_46 () )
return 0 ;
V_12 = F_19 ( V_8 , V_73 ) ;
if ( ! V_12 )
return - V_74 ;
F_42 ( V_12 ) ;
return 0 ;
}
static void F_47 ( struct V_96 * V_78 , struct V_10 * V_12 )
{
V_12 -> V_78 = V_78 ;
V_12 -> V_78 -> V_79 -> V_97 = F_35 ;
V_12 -> V_78 -> V_79 -> V_98 = F_39 ;
V_12 -> V_78 -> V_79 -> V_99 = F_44 ;
V_12 -> V_78 -> V_79 -> V_100 = V_12 ;
V_12 -> V_78 -> V_79 -> V_101 = V_73 ;
}
static void F_48 ( struct V_36 * V_102 , T_2 V_103 ,
int * V_104 )
{
V_102 -> V_39 = V_63 [ 0 ] -> V_39 ;
if ( V_102 -> V_39 == V_40 ) {
struct V_41 * V_105 = (struct V_41 * ) V_102 ;
V_105 -> V_46 = F_49 ( V_103 ) ;
* V_104 = sizeof( struct V_41 ) ;
memset ( & V_105 -> V_106 , 0 , sizeof( V_105 -> V_106 ) ) ;
} else {
struct V_48 * V_107 = (struct V_48 * ) V_102 ;
V_107 -> V_50 = F_49 ( V_103 ) ;
* V_104 = sizeof( struct V_48 ) ;
}
memset ( ( char * ) V_102 + * V_104 , 0 , sizeof( struct V_36 ) - * V_104 ) ;
}
static void F_50 ( struct V_10 * V_12 , bool V_108 )
{
F_20 ( & V_12 -> V_17 ) ;
if ( V_12 -> V_78 ) {
F_51 ( V_12 -> V_78 ) ;
V_12 -> V_78 = NULL ;
}
if ( V_12 -> V_109 && V_108 ) {
F_50 ( V_12 -> V_109 , false ) ;
}
if ( V_12 -> V_110 ) {
F_52 ( V_12 -> V_110 ) ;
V_12 -> V_110 = NULL ;
}
V_12 -> V_111 = 0 ;
F_21 ( & V_12 -> V_17 ) ;
}
static void F_53 ( T_3 V_112 )
{
static char V_113 [ F_54 ( sizeof( struct V_114 ) ) ] ;
struct V_115 V_116 ;
struct V_117 * V_118 ;
struct V_114 * V_119 ;
int V_120 ;
struct V_10 * V_12 ;
V_12 = F_19 ( 0 , 0 ) ;
F_55 ( V_12 == NULL ) ;
V_116 . V_121 = NULL ;
V_116 . V_122 = 0 ;
V_116 . V_123 = V_113 ;
V_116 . V_124 = sizeof( V_113 ) ;
V_116 . V_125 = V_126 ;
V_118 = F_56 ( & V_116 ) ;
V_118 -> V_127 = V_128 ;
V_118 -> V_129 = V_130 ;
V_118 -> V_131 = F_57 ( sizeof( struct V_114 ) ) ;
V_116 . V_124 = V_118 -> V_131 ;
V_119 = F_58 ( V_118 ) ;
memset ( V_119 , 0x00 , sizeof( struct V_114 ) ) ;
V_119 -> V_132 |= V_133 ;
V_119 -> V_134 = V_112 ;
V_120 = F_59 ( V_12 -> V_78 , & V_116 , NULL , 0 , 0 ) ;
if ( V_120 != 0 )
F_60 ( L_1 , V_120 ) ;
}
static void F_61 ( struct V_10 * V_12 )
{
if ( ! V_12 -> V_8 || V_12 -> V_33 )
return;
F_60 ( L_2 , V_12 -> V_8 ) ;
V_12 -> V_54 = true ;
V_12 -> V_33 = 0 ;
if ( F_41 ( V_135 , & V_12 -> V_82 ) ) {
if ( ! F_37 ( V_88 , & V_12 -> V_82 ) )
F_38 ( V_89 , & V_12 -> V_20 ) ;
}
}
static void F_62 ( void )
{
F_20 ( & V_31 ) ;
F_16 ( F_61 ) ;
F_21 ( & V_31 ) ;
}
static void F_63 ( struct V_10 * V_136 ,
struct V_137 * V_138 ,
char * V_139 )
{
int V_4 = V_138 -> V_140 - sizeof( struct V_137 ) ;
struct V_141 * V_142 ;
struct V_10 * V_12 ;
char * V_143 ;
int V_8 = V_138 -> V_144 . V_145 ;
F_60 ( L_3 , V_4 , V_8 ) ;
V_12 = F_19 ( V_8 , 0 ) ;
if ( ! V_12 ) {
F_60 ( L_4 ,
V_8 ) ;
return;
}
V_142 = F_64 ( V_8 , V_4 , V_73 , & V_143 ) ;
if ( ! V_142 ) {
F_60 ( L_5 ) ;
return;
}
memcpy ( V_143 , V_139 + sizeof( struct V_137 ) , V_4 ) ;
F_65 ( V_142 ) ;
if ( V_12 -> V_33 ) {
if ( ! F_37 ( V_88 , & V_12 -> V_82 ) )
F_38 ( V_89 , & V_12 -> V_20 ) ;
} else
F_61 ( V_12 ) ;
}
static void F_66 ( struct V_10 * V_12 ,
struct V_115 * V_146 , char * V_139 )
{
union V_147 * V_148 = (union V_147 * ) V_139 ;
switch ( V_148 -> V_149 . V_150 ) {
case V_151 :
F_63 ( V_12 , & V_148 -> V_138 , V_139 ) ;
break;
case V_152 :
switch ( V_148 -> V_153 . V_154 ) {
case V_155 :
case V_156 :
{
struct V_157 V_158 ;
int V_8 ;
int V_159 , V_120 ;
int V_104 ;
struct V_10 * V_160 ;
if ( ( int ) V_148 -> V_153 . V_161 <= 0 ) {
F_60 ( L_6 ,
( int ) V_148 -> V_153 . V_161 ) ;
F_62 () ;
return;
}
memset ( & V_158 , 0 , sizeof( struct V_157 ) ) ;
V_159 = sizeof( struct V_157 ) ;
V_158 . V_162 = V_148 -> V_153 . V_161 ;
V_120 = F_67 ( V_12 -> V_78 ,
V_128 ,
V_163 ,
( char * ) & V_158 ,
& V_159 ) ;
if ( V_120 < 0 ) {
F_60 ( L_7
L_8 ,
( int ) V_148 -> V_153 . V_161 ,
V_120 ) ;
V_160 = F_22 ( V_148 -> V_153 . V_161 ) ;
if ( V_160 )
F_40 ( V_91 , & V_12 -> V_82 ) ;
return;
}
F_48 ( & V_158 . V_164 , 0 , & V_104 ) ;
if ( F_30 ( & V_158 . V_164 , & V_8 ) ) {
unsigned char * V_165 = ( unsigned char * ) & V_158 . V_164 ;
F_60 ( L_9 ) ;
F_68 ( L_10 , V_166 ,
V_165 , sizeof( struct V_36 ) ) ;
F_53 ( V_158 . V_162 ) ;
return;
}
V_160 = F_19 ( V_8 , V_73 ) ;
if ( ! V_160 )
return;
F_69 ( V_12 -> V_78 -> V_79 ) ;
V_120 = F_70 ( V_12 -> V_78 -> V_79 ,
V_148 -> V_153 . V_161 ,
& V_160 -> V_78 ) ;
F_71 ( V_12 -> V_78 -> V_79 ) ;
if ( V_120 < 0 ) {
F_60 ( L_11
L_12 ,
( int ) V_148 -> V_153 . V_161 ,
V_8 , V_120 ) ;
return;
}
F_47 ( V_160 -> V_78 , V_160 ) ;
F_60 ( L_13 ,
V_8 , ( int ) V_148 -> V_153 . V_161 ) ;
V_160 -> V_33 = V_148 -> V_153 . V_161 ;
V_160 -> V_54 = false ;
F_40 ( V_91 , & V_160 -> V_82 ) ;
F_40 ( V_135 , & V_160 -> V_82 ) ;
if ( ! F_37 ( V_88 , & V_160 -> V_82 ) ) {
F_38 ( V_89 , & V_160 -> V_20 ) ;
}
if ( ! F_37 ( V_81 , & V_160 -> V_82 ) )
F_38 ( V_83 , & V_160 -> V_22 ) ;
}
break;
case V_167 :
case V_168 :
{
V_12 = F_22 ( V_148 -> V_153 . V_161 ) ;
if ( V_12 ) {
V_12 -> V_33 = 0 ;
}
}
break;
case V_169 :
{
F_60 ( L_14 ) ;
}
break;
default:
F_60 ( L_15 ,
( int ) V_148 -> V_153 . V_161 ,
V_148 -> V_153 . V_154 ) ;
}
default:
;
}
}
static int F_72 ( struct V_10 * V_12 )
{
int V_120 = 0 ;
struct V_115 V_146 = {} ;
struct V_170 V_171 [ 2 ] ;
unsigned V_4 ;
int V_11 ;
int V_172 = 0 ;
int V_173 ;
char V_174 [ F_54 ( sizeof( struct V_114 ) ) ] ;
F_20 ( & V_12 -> V_17 ) ;
if ( V_12 -> V_78 == NULL ) {
V_120 = - V_175 ;
goto V_176;
}
if ( V_12 -> V_110 == NULL ) {
V_12 -> V_110 = F_73 ( V_177 ) ;
if ( V_12 -> V_110 == NULL )
goto V_178;
F_3 ( & V_12 -> V_2 , V_179 ) ;
}
memset ( & V_174 , 0 , sizeof( V_174 ) ) ;
V_146 . V_123 = V_174 ;
V_146 . V_124 = sizeof( V_174 ) ;
V_171 [ 0 ] . V_180 = V_12 -> V_2 . V_5 - F_2 ( & V_12 -> V_2 ) ;
V_171 [ 0 ] . V_181 = F_74 ( V_12 -> V_110 ) + F_2 ( & V_12 -> V_2 ) ;
V_171 [ 1 ] . V_180 = 0 ;
V_173 = 1 ;
if ( F_2 ( & V_12 -> V_2 ) >= V_12 -> V_2 . V_5 ) {
V_171 [ 0 ] . V_180 = V_179 - F_2 ( & V_12 -> V_2 ) ;
V_171 [ 1 ] . V_180 = V_12 -> V_2 . V_5 ;
V_171 [ 1 ] . V_181 = F_74 ( V_12 -> V_110 ) ;
V_173 = 2 ;
}
V_4 = V_171 [ 0 ] . V_180 + V_171 [ 1 ] . V_180 ;
V_11 = V_120 = F_75 ( V_12 -> V_78 , & V_146 , V_171 , V_173 , V_4 ,
V_182 | V_183 ) ;
if ( V_120 <= 0 )
goto V_176;
if ( V_146 . V_125 & V_184 ) {
V_146 . V_123 = V_174 ;
V_146 . V_124 = sizeof( V_174 ) ;
F_66 ( V_12 , & V_146 ,
F_74 ( V_12 -> V_110 ) + V_12 -> V_2 . V_5 ) ;
F_21 ( & V_12 -> V_17 ) ;
return 0 ;
}
F_55 ( V_12 -> V_8 == 0 ) ;
if ( V_120 == V_4 )
V_172 = 1 ;
F_1 ( & V_12 -> V_2 , V_120 ) ;
V_120 = F_76 ( V_12 -> V_8 ,
F_74 ( V_12 -> V_110 ) ,
V_12 -> V_2 . V_5 , V_12 -> V_2 . V_4 ,
V_179 ) ;
if ( V_120 == - V_185 ) {
F_60 ( L_16
L_17 ,
F_74 ( V_12 -> V_110 ) , V_12 -> V_2 . V_5 , V_12 -> V_2 . V_4 ,
V_4 , V_171 [ 0 ] . V_181 , V_11 ) ;
}
if ( V_120 < 0 )
goto V_176;
F_4 ( & V_12 -> V_2 , V_120 ) ;
if ( F_5 ( & V_12 -> V_2 ) && ! V_172 ) {
F_52 ( V_12 -> V_110 ) ;
V_12 -> V_110 = NULL ;
}
if ( V_172 )
goto V_178;
F_21 ( & V_12 -> V_17 ) ;
return 0 ;
V_178:
if ( ! F_37 ( V_81 , & V_12 -> V_82 ) )
F_38 ( V_83 , & V_12 -> V_22 ) ;
F_21 ( & V_12 -> V_17 ) ;
return - V_175 ;
V_176:
F_21 ( & V_12 -> V_17 ) ;
if ( V_120 != - V_175 ) {
F_50 ( V_12 , false ) ;
}
if ( V_120 == 0 )
V_120 = - V_175 ;
return V_120 ;
}
static int F_77 ( struct V_10 * V_12 )
{
int V_186 ;
struct V_36 V_187 ;
struct V_96 * V_188 ;
int V_4 ;
int V_8 ;
struct V_10 * V_189 ;
struct V_10 * V_190 ;
F_20 ( & V_31 ) ;
if ( ! V_191 ) {
F_21 ( & V_31 ) ;
return - 1 ;
}
F_21 ( & V_31 ) ;
memset ( & V_187 , 0 , sizeof( V_187 ) ) ;
V_186 = F_78 ( V_63 [ 0 ] -> V_39 , V_192 ,
V_193 , & V_188 ) ;
if ( V_186 < 0 )
return - V_74 ;
F_79 ( & V_12 -> V_17 , 0 ) ;
V_186 = - V_194 ;
if ( V_12 -> V_78 == NULL )
goto V_195;
V_188 -> type = V_12 -> V_78 -> type ;
V_188 -> V_196 = V_12 -> V_78 -> V_196 ;
V_186 = V_12 -> V_78 -> V_196 -> V_197 ( V_12 -> V_78 , V_188 , V_198 ) ;
if ( V_186 < 0 )
goto V_195;
memset ( & V_187 , 0 , sizeof( V_187 ) ) ;
if ( V_188 -> V_196 -> V_199 ( V_188 , (struct V_52 * ) & V_187 ,
& V_4 , 2 ) ) {
V_186 = - V_200 ;
goto V_195;
}
F_48 ( & V_187 , 0 , & V_4 ) ;
if ( F_30 ( & V_187 , & V_8 ) ) {
unsigned char * V_165 = ( unsigned char * ) & V_187 ;
F_60 ( L_18 ) ;
F_68 ( L_10 , V_166 ,
V_165 , sizeof( struct V_36 ) ) ;
F_51 ( V_188 ) ;
F_21 ( & V_12 -> V_17 ) ;
return - 1 ;
}
F_60 ( L_19 , V_8 ) ;
V_189 = F_19 ( V_8 , V_73 ) ;
if ( ! V_189 ) {
V_186 = - V_74 ;
goto V_195;
}
F_79 ( & V_189 -> V_17 , 1 ) ;
if ( V_189 -> V_78 ) {
struct V_10 * V_109 = V_189 -> V_109 ;
if ( ! V_109 ) {
V_109 = F_10 ( V_14 , V_73 ) ;
if ( ! V_109 ) {
F_60 ( L_20 ) ;
F_21 ( & V_189 -> V_17 ) ;
V_186 = - V_74 ;
goto V_195;
}
V_109 -> V_8 = V_8 ;
V_109 -> V_26 = F_72 ;
F_12 ( & V_109 -> V_17 ) ;
F_15 ( & V_109 -> V_20 , V_21 ) ;
F_15 ( & V_109 -> V_22 , V_23 ) ;
F_80 ( V_201 , & V_109 -> V_82 ) ;
}
if ( ! V_109 -> V_78 ) {
V_189 -> V_109 = V_109 ;
V_109 -> V_78 = V_188 ;
V_188 -> V_79 -> V_100 = V_109 ;
F_47 ( V_188 , V_109 ) ;
V_190 = V_109 ;
}
else {
F_81 ( L_21 , V_8 ) ;
V_186 = - V_175 ;
F_21 ( & V_189 -> V_17 ) ;
goto V_195;
}
}
else {
V_188 -> V_79 -> V_100 = V_189 ;
V_189 -> V_26 = F_72 ;
F_47 ( V_188 , V_189 ) ;
V_190 = V_189 ;
}
F_21 ( & V_189 -> V_17 ) ;
if ( ! F_37 ( V_81 , & V_190 -> V_82 ) )
F_38 ( V_83 , & V_190 -> V_22 ) ;
F_21 ( & V_12 -> V_17 ) ;
return 0 ;
V_195:
F_21 ( & V_12 -> V_17 ) ;
F_51 ( V_188 ) ;
if ( V_186 != - V_175 )
F_60 ( L_22 , V_186 ) ;
return V_186 ;
}
static void F_82 ( struct V_202 * V_203 )
{
F_52 ( V_203 -> V_204 ) ;
F_33 ( V_203 ) ;
}
static void F_83 ( struct V_202 * V_203 , int V_205 )
{
V_203 -> V_206 += V_205 ;
V_203 -> V_4 -= V_205 ;
if ( V_203 -> V_4 == 0 && V_203 -> V_207 == 0 ) {
F_84 ( & V_203 -> V_15 ) ;
F_82 ( V_203 ) ;
}
}
static void F_85 ( struct V_10 * V_12 )
{
struct V_36 V_208 ;
char V_113 [ F_54 ( sizeof( struct V_114 ) ) ] ;
struct V_115 V_116 ;
struct V_117 * V_118 ;
struct V_114 * V_119 ;
struct V_10 * V_209 ;
struct V_202 * V_203 ;
int V_4 , V_206 ;
int V_120 ;
int V_210 ;
struct V_170 V_171 [ 1 ] ;
F_20 ( & V_12 -> V_17 ) ;
if ( F_37 ( V_135 , & V_12 -> V_82 ) )
goto V_70;
if ( F_27 ( V_12 -> V_8 , NULL , (struct V_52 * ) & V_208 ,
V_12 -> V_54 ) ) {
F_60 ( L_23 , V_12 -> V_8 ) ;
goto V_70;
}
V_209 = F_19 ( 0 , 0 ) ;
F_55 ( V_209 == NULL ) ;
F_48 ( & V_208 , V_94 . V_211 , & V_210 ) ;
V_116 . V_121 = & V_208 ;
V_116 . V_122 = V_210 ;
V_116 . V_123 = V_113 ;
V_116 . V_124 = sizeof( V_113 ) ;
V_116 . V_125 = V_126 ;
F_28 ( & V_12 -> V_19 ) ;
if ( F_86 ( & V_12 -> V_18 ) ) {
F_29 ( & V_12 -> V_19 ) ;
F_60 ( L_24 , V_12 -> V_8 ) ;
goto V_70;
}
V_203 = F_87 ( & V_12 -> V_18 , struct V_202 , V_15 ) ;
V_4 = V_203 -> V_4 ;
V_206 = V_203 -> V_206 ;
V_171 [ 0 ] . V_181 = F_74 ( V_203 -> V_204 ) + V_206 ;
V_171 [ 0 ] . V_180 = V_4 ;
F_29 ( & V_12 -> V_19 ) ;
if ( V_208 . V_39 == V_40 ) {
struct V_41 * sin = (struct V_41 * ) & V_208 ;
F_60 ( L_25 , & sin -> V_44 . V_45 ) ;
} else {
struct V_48 * V_212 = (struct V_48 * ) & V_208 ;
F_60 ( L_26 , & V_212 -> V_49 ) ;
}
V_118 = F_56 ( & V_116 ) ;
V_118 -> V_127 = V_128 ;
V_118 -> V_129 = V_130 ;
V_118 -> V_131 = F_57 ( sizeof( struct V_114 ) ) ;
V_119 = F_58 ( V_118 ) ;
memset ( V_119 , 0x00 , sizeof( struct V_114 ) ) ;
V_119 -> V_145 = F_88 ( V_12 -> V_8 ) ;
V_116 . V_124 = V_118 -> V_131 ;
V_119 -> V_132 |= V_213 ;
V_120 = F_59 ( V_209 -> V_78 , & V_116 , V_171 , 1 , V_4 ) ;
if ( V_120 < 0 ) {
F_60 ( L_27 ,
V_12 -> V_8 , V_120 ) ;
F_40 ( V_91 , & V_12 -> V_82 ) ;
F_40 ( V_135 , & V_12 -> V_82 ) ;
}
else {
F_28 ( & V_12 -> V_19 ) ;
F_83 ( V_203 , V_120 ) ;
F_29 ( & V_12 -> V_19 ) ;
}
V_70:
F_21 ( & V_12 -> V_17 ) ;
}
static void F_89 ( struct V_10 * V_12 )
{
struct V_36 V_102 , V_214 ;
int V_104 ;
struct V_96 * V_78 = NULL ;
int V_215 = 1 ;
int V_186 ;
if ( V_12 -> V_8 == 0 ) {
F_60 ( L_28 ) ;
return;
}
F_20 ( & V_12 -> V_17 ) ;
if ( V_12 -> V_111 ++ > V_216 )
goto V_217;
if ( V_12 -> V_78 )
goto V_217;
V_186 = F_78 ( V_63 [ 0 ] -> V_39 , V_192 ,
V_193 , & V_78 ) ;
if ( V_186 < 0 )
goto V_218;
memset ( & V_102 , 0 , sizeof( V_102 ) ) ;
V_186 = F_27 ( V_12 -> V_8 , & V_102 , NULL , false ) ;
if ( V_186 < 0 ) {
F_60 ( L_23 , V_12 -> V_8 ) ;
goto V_218;
}
V_78 -> V_79 -> V_100 = V_12 ;
V_12 -> V_26 = F_72 ;
V_12 -> V_25 = F_89 ;
F_47 ( V_78 , V_12 ) ;
memcpy ( & V_214 , V_63 [ 0 ] , sizeof( V_214 ) ) ;
F_48 ( & V_214 , 0 , & V_104 ) ;
V_186 = V_78 -> V_196 -> V_219 ( V_78 , (struct V_52 * ) & V_214 ,
V_104 ) ;
if ( V_186 < 0 ) {
F_60 ( L_29 , V_186 ) ;
}
F_48 ( & V_102 , V_94 . V_211 , & V_104 ) ;
F_60 ( L_30 , V_12 -> V_8 ) ;
F_90 ( V_78 , V_220 , V_221 , ( char * ) & V_215 ,
sizeof( V_215 ) ) ;
V_186 = V_78 -> V_196 -> V_222 ( V_78 , (struct V_52 * ) & V_102 , V_104 ,
V_198 ) ;
if ( V_186 == - V_223 )
V_186 = 0 ;
if ( V_186 == 0 )
goto V_217;
V_218:
if ( V_12 -> V_78 ) {
F_51 ( V_12 -> V_78 ) ;
V_12 -> V_78 = NULL ;
} else if ( V_78 ) {
F_51 ( V_78 ) ;
}
if ( V_186 != - V_224 &&
V_186 != - V_225 &&
V_186 != - V_226 &&
V_186 != - V_227 &&
V_186 != - V_228 ) {
F_60 ( L_31 , V_12 -> V_8 ,
V_12 -> V_111 , V_186 ) ;
F_21 ( & V_12 -> V_17 ) ;
F_91 ( 1000 ) ;
F_42 ( V_12 ) ;
return;
}
V_217:
F_21 ( & V_12 -> V_17 ) ;
return;
}
static struct V_96 * F_92 ( struct V_10 * V_12 ,
struct V_36 * V_102 )
{
struct V_96 * V_78 = NULL ;
int V_186 = 0 ;
int V_215 = 1 ;
int V_104 ;
if ( V_63 [ 0 ] -> V_39 == V_40 )
V_104 = sizeof( struct V_41 ) ;
else
V_104 = sizeof( struct V_48 ) ;
V_186 = F_78 ( V_63 [ 0 ] -> V_39 , V_192 ,
V_193 , & V_78 ) ;
if ( V_186 < 0 ) {
F_60 ( L_32 ) ;
goto V_229;
}
F_90 ( V_78 , V_220 , V_221 , ( char * ) & V_215 ,
sizeof( V_215 ) ) ;
V_186 = F_90 ( V_78 , V_230 , V_231 ,
( char * ) & V_215 , sizeof( V_215 ) ) ;
if ( V_186 < 0 ) {
F_60 ( L_33 , V_186 ) ;
}
V_12 -> V_26 = F_77 ;
V_12 -> V_25 = F_89 ;
F_48 ( V_102 , V_94 . V_211 , & V_104 ) ;
V_186 = V_78 -> V_196 -> V_219 ( V_78 , (struct V_52 * ) V_102 , V_104 ) ;
if ( V_186 < 0 ) {
F_60 ( L_34 , V_94 . V_211 ) ;
F_51 ( V_78 ) ;
V_78 = NULL ;
V_12 -> V_78 = NULL ;
goto V_229;
}
V_186 = F_90 ( V_78 , V_230 , V_232 ,
( char * ) & V_215 , sizeof( V_215 ) ) ;
if ( V_186 < 0 ) {
F_60 ( L_35 , V_186 ) ;
}
V_186 = V_78 -> V_196 -> V_233 ( V_78 , 5 ) ;
if ( V_186 < 0 ) {
F_60 ( L_36 , V_94 . V_211 ) ;
F_51 ( V_78 ) ;
V_78 = NULL ;
goto V_229;
}
V_229:
return V_78 ;
}
static void F_93 ( void )
{
struct V_36 V_55 , * V_60 ;
int V_28 ;
V_56 = 0 ;
for ( V_28 = 0 ; V_28 < V_76 ; V_28 ++ ) {
if ( F_94 ( & V_55 , V_28 ) )
break;
V_60 = F_95 ( sizeof( * V_60 ) , V_73 ) ;
if ( ! V_60 )
break;
memcpy ( V_60 , & V_55 , sizeof( * V_60 ) ) ;
V_63 [ V_56 ++ ] = V_60 ;
}
}
static int F_96 ( struct V_10 * V_234 ,
struct V_36 * V_60 ,
int V_104 , int V_235 )
{
int V_186 = 0 ;
if ( V_235 == 1 )
V_186 = F_97 ( V_234 -> V_78 ,
(struct V_52 * ) V_60 ,
V_104 ) ;
else
V_186 = F_90 ( V_234 -> V_78 , V_236 ,
V_237 ,
( char * ) V_60 , V_104 ) ;
if ( V_186 < 0 )
F_60 ( L_37 ,
V_94 . V_211 , V_235 ) ;
return V_186 ;
}
static int F_98 ( void )
{
struct V_96 * V_78 = NULL ;
struct V_36 V_238 ;
struct V_239 V_240 ;
int V_186 = - V_227 , V_235 = 1 , V_28 , V_104 ;
struct V_10 * V_12 = F_19 ( 0 , V_73 ) ;
int V_241 = V_242 ;
int V_215 = 1 ;
if ( ! V_12 )
return - V_74 ;
F_60 ( L_38 ) ;
V_186 = F_78 ( V_63 [ 0 ] -> V_39 , V_243 ,
V_128 , & V_78 ) ;
if ( V_186 < 0 ) {
F_60 ( L_39 ) ;
goto V_217;
}
memset ( & V_240 , 0 , sizeof( V_240 ) ) ;
V_240 . V_244 = 1 ;
V_240 . V_245 = 1 ;
V_240 . V_246 = 1 ;
V_240 . V_247 = 1 ;
V_240 . V_248 = 1 ;
V_186 = F_90 ( V_78 , V_230 , V_249 ,
( char * ) & V_241 , sizeof( V_241 ) ) ;
if ( V_186 )
F_60 ( L_40 , V_186 ) ;
V_186 = F_90 ( V_78 , V_236 , V_250 ,
( char * ) & V_240 , sizeof( V_240 ) ) ;
if ( V_186 < 0 ) {
F_60 ( L_41 ,
V_186 ) ;
goto V_251;
}
V_186 = F_90 ( V_78 , V_236 , V_252 , ( char * ) & V_215 ,
sizeof( V_215 ) ) ;
if ( V_186 < 0 )
F_60 ( L_42 , V_186 ) ;
V_78 -> V_79 -> V_100 = V_12 ;
V_12 -> V_78 = V_78 ;
V_12 -> V_78 -> V_79 -> V_97 = F_35 ;
V_12 -> V_26 = F_72 ;
V_12 -> V_25 = F_85 ;
for ( V_28 = 0 ; V_28 < V_56 ; V_28 ++ ) {
memcpy ( & V_238 , V_63 [ V_28 ] , sizeof( V_238 ) ) ;
F_48 ( & V_238 , V_94 . V_211 , & V_104 ) ;
V_186 = F_96 ( V_12 , & V_238 , V_104 , V_235 ) ;
if ( V_186 )
goto V_251;
++ V_235 ;
}
V_186 = V_78 -> V_196 -> V_233 ( V_78 , 5 ) ;
if ( V_186 < 0 ) {
F_60 ( L_43 ) ;
goto V_251;
}
return 0 ;
V_251:
F_51 ( V_78 ) ;
V_12 -> V_78 = NULL ;
V_217:
return V_186 ;
}
static int F_99 ( void )
{
struct V_96 * V_78 = NULL ;
struct V_10 * V_12 = F_19 ( 0 , V_73 ) ;
int V_186 = - V_227 ;
if ( ! V_12 )
return - V_74 ;
if ( V_63 [ 1 ] != NULL ) {
F_60 ( L_44
L_45 ) ;
return - V_227 ;
}
F_60 ( L_46 ) ;
V_78 = F_92 ( V_12 , V_63 [ 0 ] ) ;
if ( V_78 ) {
F_47 ( V_78 , V_12 ) ;
V_186 = 0 ;
}
else {
V_186 = - V_253 ;
}
return V_186 ;
}
static struct V_202 * F_100 ( struct V_10 * V_12 ,
T_1 V_30 )
{
struct V_202 * V_254 ;
V_254 = F_95 ( sizeof( struct V_202 ) , V_30 ) ;
if ( ! V_254 )
return NULL ;
V_254 -> V_204 = F_73 ( V_30 ) ;
if ( ! V_254 -> V_204 ) {
F_33 ( V_254 ) ;
return NULL ;
}
V_254 -> V_206 = 0 ;
V_254 -> V_4 = 0 ;
V_254 -> V_255 = 0 ;
V_254 -> V_207 = 0 ;
V_254 -> V_12 = V_12 ;
return V_254 ;
}
void * F_64 ( int V_8 , int V_4 , T_1 V_30 , char * * V_256 )
{
struct V_10 * V_12 ;
struct V_202 * V_203 ;
int V_206 = 0 ;
V_12 = F_19 ( V_8 , V_30 ) ;
if ( ! V_12 )
return NULL ;
F_28 ( & V_12 -> V_19 ) ;
V_203 = F_101 ( V_12 -> V_18 . V_257 , struct V_202 , V_15 ) ;
if ( ( & V_203 -> V_15 == & V_12 -> V_18 ) ||
( V_179 - V_203 -> V_255 < V_4 ) ) {
V_203 = NULL ;
} else {
V_206 = V_203 -> V_255 ;
V_203 -> V_255 += V_4 ;
V_203 -> V_207 ++ ;
}
F_29 ( & V_12 -> V_19 ) ;
if ( V_203 ) {
V_258:
* V_256 = F_74 ( V_203 -> V_204 ) + V_206 ;
return V_203 ;
}
V_203 = F_100 ( V_12 , V_30 ) ;
if ( V_203 ) {
F_28 ( & V_12 -> V_19 ) ;
V_206 = V_203 -> V_255 ;
V_203 -> V_255 += V_4 ;
V_203 -> V_207 ++ ;
F_102 ( & V_203 -> V_15 , & V_12 -> V_18 ) ;
F_29 ( & V_12 -> V_19 ) ;
goto V_258;
}
return NULL ;
}
void F_65 ( void * V_142 )
{
struct V_202 * V_203 = (struct V_202 * ) V_142 ;
struct V_10 * V_12 = V_203 -> V_12 ;
int V_207 ;
F_28 ( & V_12 -> V_19 ) ;
V_207 = -- V_203 -> V_207 ;
if ( V_207 )
goto V_217;
V_203 -> V_4 = V_203 -> V_255 - V_203 -> V_206 ;
F_29 ( & V_12 -> V_19 ) ;
if ( ! F_37 ( V_88 , & V_12 -> V_82 ) ) {
F_38 ( V_89 , & V_12 -> V_20 ) ;
}
return;
V_217:
F_29 ( & V_12 -> V_19 ) ;
return;
}
static void F_103 ( struct V_10 * V_12 )
{
int V_120 = 0 ;
const int V_125 = V_182 | V_183 ;
struct V_202 * V_203 ;
int V_4 , V_206 ;
int V_259 = 0 ;
F_20 ( & V_12 -> V_17 ) ;
if ( V_12 -> V_78 == NULL )
goto V_260;
F_28 ( & V_12 -> V_19 ) ;
for (; ; ) {
V_203 = F_101 ( V_12 -> V_18 . V_261 , struct V_202 ,
V_15 ) ;
if ( (struct V_262 * ) V_203 == & V_12 -> V_18 )
break;
V_4 = V_203 -> V_4 ;
V_206 = V_203 -> V_206 ;
F_55 ( V_4 == 0 && V_203 -> V_207 == 0 ) ;
F_29 ( & V_12 -> V_19 ) ;
V_120 = 0 ;
if ( V_4 ) {
V_120 = F_104 ( V_12 -> V_78 , V_203 -> V_204 , V_206 , V_4 ,
V_125 ) ;
if ( V_120 == - V_175 || V_120 == 0 ) {
if ( V_120 == - V_175 &&
F_43 ( V_87 , & V_12 -> V_78 -> V_82 ) &&
! F_37 ( V_85 , & V_12 -> V_82 ) ) {
F_80 ( V_84 , & V_12 -> V_78 -> V_82 ) ;
V_12 -> V_78 -> V_79 -> V_86 ++ ;
}
F_105 () ;
goto V_217;
} else if ( V_120 < 0 )
goto V_263;
}
if ( ++ V_259 >= V_264 ) {
F_105 () ;
V_259 = 0 ;
}
F_28 ( & V_12 -> V_19 ) ;
F_83 ( V_203 , V_120 ) ;
}
F_29 ( & V_12 -> V_19 ) ;
V_217:
F_21 ( & V_12 -> V_17 ) ;
return;
V_263:
F_21 ( & V_12 -> V_17 ) ;
F_50 ( V_12 , false ) ;
F_42 ( V_12 ) ;
return;
V_260:
F_21 ( & V_12 -> V_17 ) ;
if ( ! F_43 ( V_135 , & V_12 -> V_82 ) )
F_42 ( V_12 ) ;
}
static void F_106 ( struct V_10 * V_12 )
{
struct V_202 * V_203 , * V_265 ;
F_28 ( & V_12 -> V_19 ) ;
F_107 (e, safe, &con->writequeue, list) {
F_84 ( & V_203 -> V_15 ) ;
F_82 ( V_203 ) ;
}
F_29 ( & V_12 -> V_19 ) ;
}
int F_108 ( int V_8 )
{
struct V_10 * V_12 ;
struct V_34 * V_35 ;
F_60 ( L_47 , V_8 ) ;
V_12 = F_19 ( V_8 , 0 ) ;
if ( V_12 ) {
F_40 ( V_91 , & V_12 -> V_82 ) ;
F_40 ( V_88 , & V_12 -> V_82 ) ;
F_80 ( V_90 , & V_12 -> V_82 ) ;
if ( F_109 ( & V_12 -> V_20 ) )
F_60 ( L_48 , V_8 ) ;
if ( F_109 ( & V_12 -> V_22 ) )
F_60 ( L_49 , V_8 ) ;
F_106 ( V_12 ) ;
F_50 ( V_12 , true ) ;
}
F_28 ( & V_57 ) ;
V_35 = F_23 ( V_8 ) ;
if ( V_35 ) {
F_84 ( & V_35 -> V_15 ) ;
while ( V_35 -> V_58 -- )
F_33 ( V_35 -> V_60 [ V_35 -> V_58 ] ) ;
F_33 ( V_35 ) ;
}
F_29 ( & V_57 ) ;
return 0 ;
}
static void V_23 ( struct V_266 * V_267 )
{
struct V_10 * V_12 = F_110 ( V_267 , struct V_10 , V_22 ) ;
int V_268 ;
F_40 ( V_81 , & V_12 -> V_82 ) ;
do {
V_268 = V_12 -> V_26 ( V_12 ) ;
} while ( ! V_268 );
}
static void V_21 ( struct V_266 * V_267 )
{
struct V_10 * V_12 = F_110 ( V_267 , struct V_10 , V_20 ) ;
if ( F_41 ( V_91 , & V_12 -> V_82 ) ) {
V_12 -> V_25 ( V_12 ) ;
F_80 ( V_88 , & V_12 -> V_82 ) ;
}
if ( F_41 ( V_88 , & V_12 -> V_82 ) )
F_103 ( V_12 ) ;
}
static void F_111 ( void )
{
F_16 ( F_106 ) ;
}
static void F_112 ( void )
{
F_113 ( V_83 ) ;
F_113 ( V_89 ) ;
}
static int F_114 ( void )
{
V_83 = F_115 ( L_50 ,
V_269 | V_270 , 1 ) ;
if ( ! V_83 ) {
F_60 ( L_51 ) ;
return - V_74 ;
}
V_89 = F_115 ( L_52 ,
V_269 | V_270 , 1 ) ;
if ( ! V_89 ) {
F_60 ( L_53 ) ;
F_113 ( V_83 ) ;
return - V_74 ;
}
return 0 ;
}
static void F_116 ( struct V_10 * V_12 )
{
V_12 -> V_82 |= 0x0F ;
if ( V_12 -> V_78 && V_12 -> V_78 -> V_79 )
V_12 -> V_78 -> V_79 -> V_100 = NULL ;
}
static void F_117 ( struct V_10 * V_12 )
{
F_50 ( V_12 , true ) ;
if ( V_12 -> V_109 )
F_118 ( V_14 , V_12 -> V_109 ) ;
F_119 ( & V_12 -> V_15 ) ;
F_118 ( V_14 , V_12 ) ;
}
void F_120 ( void )
{
F_20 ( & V_31 ) ;
V_191 = 0 ;
F_16 ( F_116 ) ;
F_21 ( & V_31 ) ;
F_112 () ;
F_20 ( & V_31 ) ;
F_111 () ;
F_16 ( F_117 ) ;
F_21 ( & V_31 ) ;
F_121 ( V_14 ) ;
}
int F_122 ( void )
{
int error = - V_227 ;
struct V_10 * V_12 ;
int V_28 ;
for ( V_28 = 0 ; V_28 < V_9 ; V_28 ++ )
F_123 ( & V_16 [ V_28 ] ) ;
F_93 () ;
if ( ! V_56 ) {
error = - V_194 ;
F_60 ( L_54 ) ;
goto V_271;
}
error = - V_74 ;
V_14 = F_124 ( L_55 , sizeof( struct V_10 ) ,
F_125 ( struct V_10 ) , 0 ,
NULL ) ;
if ( ! V_14 )
goto V_271;
error = F_114 () ;
if ( error )
goto V_272;
V_191 = 1 ;
if ( V_94 . V_95 == 0 )
error = F_99 () ;
else
error = F_98 () ;
if ( error )
goto V_273;
return 0 ;
V_273:
V_191 = 0 ;
V_12 = F_19 ( 0 , 0 ) ;
if ( V_12 ) {
F_50 ( V_12 , false ) ;
F_118 ( V_14 , V_12 ) ;
}
V_272:
F_121 ( V_14 ) ;
V_271:
return error ;
}
void F_126 ( void )
{
struct V_34 * V_35 , * V_265 ;
F_28 ( & V_57 ) ;
F_107 (na, safe, &dlm_node_addrs, list) {
F_84 ( & V_35 -> V_15 ) ;
while ( V_35 -> V_58 -- )
F_33 ( V_35 -> V_60 [ V_35 -> V_58 ] ) ;
F_33 ( V_35 ) ;
}
F_29 ( & V_57 ) ;
}
