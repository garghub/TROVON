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
struct V_52 * V_53 )
{
struct V_36 V_54 ;
struct V_34 * V_35 ;
if ( ! V_55 )
return - 1 ;
F_28 ( & V_56 ) ;
V_35 = F_23 ( V_8 ) ;
if ( V_35 && V_35 -> V_57 )
memcpy ( & V_54 , V_35 -> V_58 [ 0 ] , sizeof( struct V_36 ) ) ;
F_29 ( & V_56 ) ;
if ( ! V_35 )
return - V_59 ;
if ( ! V_35 -> V_57 )
return - V_60 ;
if ( V_51 )
memcpy ( V_51 , & V_54 , sizeof( struct V_36 ) ) ;
if ( ! V_53 )
return 0 ;
if ( V_61 [ 0 ] -> V_39 == V_40 ) {
struct V_41 * V_62 = (struct V_41 * ) & V_54 ;
struct V_41 * V_63 = (struct V_41 * ) V_53 ;
V_63 -> V_44 . V_45 = V_62 -> V_44 . V_45 ;
} else {
struct V_48 * V_64 = (struct V_48 * ) & V_54 ;
struct V_48 * V_65 = (struct V_48 * ) V_53 ;
V_65 -> V_49 = V_64 -> V_49 ;
}
return 0 ;
}
static int F_30 ( struct V_36 * V_58 , int * V_8 )
{
struct V_34 * V_35 ;
int V_66 = - V_59 ;
F_28 ( & V_56 ) ;
F_24 (na, &dlm_node_addrs, list) {
if ( ! V_35 -> V_57 )
continue;
if ( ! F_25 ( V_35 -> V_58 [ 0 ] , V_58 ) )
continue;
* V_8 = V_35 -> V_8 ;
V_66 = 0 ;
break;
}
F_29 ( & V_56 ) ;
return V_66 ;
}
int F_31 ( int V_8 , struct V_36 * V_58 , int V_4 )
{
struct V_36 * V_67 ;
struct V_34 * V_68 , * V_35 ;
V_68 = F_32 ( sizeof( struct V_34 ) , V_69 ) ;
if ( ! V_68 )
return - V_70 ;
V_67 = F_32 ( sizeof( struct V_36 ) , V_69 ) ;
if ( ! V_67 ) {
F_33 ( V_68 ) ;
return - V_70 ;
}
memcpy ( V_67 , V_58 , V_4 ) ;
F_28 ( & V_56 ) ;
V_35 = F_23 ( V_8 ) ;
if ( ! V_35 ) {
V_68 -> V_8 = V_8 ;
V_68 -> V_58 [ 0 ] = V_67 ;
V_68 -> V_57 = 1 ;
F_34 ( & V_68 -> V_15 , & V_71 ) ;
F_29 ( & V_56 ) ;
return 0 ;
}
if ( V_35 -> V_57 >= V_72 ) {
F_29 ( & V_56 ) ;
F_33 ( V_67 ) ;
F_33 ( V_68 ) ;
return - V_73 ;
}
V_35 -> V_58 [ V_35 -> V_57 ++ ] = V_67 ;
F_29 ( & V_56 ) ;
F_33 ( V_68 ) ;
return 0 ;
}
static void F_35 ( struct V_74 * V_75 , int V_76 )
{
struct V_10 * V_12 = F_36 ( V_75 ) ;
if ( V_12 && ! F_37 ( V_77 , & V_12 -> V_78 ) )
F_38 ( V_79 , & V_12 -> V_22 ) ;
}
static void F_39 ( struct V_74 * V_75 )
{
struct V_10 * V_12 = F_36 ( V_75 ) ;
if ( ! V_12 )
return;
F_40 ( V_80 , & V_12 -> V_74 -> V_78 ) ;
if ( F_41 ( V_81 , & V_12 -> V_78 ) ) {
V_12 -> V_74 -> V_75 -> V_82 -- ;
F_40 ( V_83 , & V_12 -> V_74 -> V_78 ) ;
}
if ( ! F_37 ( V_84 , & V_12 -> V_78 ) )
F_38 ( V_85 , & V_12 -> V_20 ) ;
}
static inline void F_42 ( struct V_10 * V_12 )
{
if ( F_43 ( V_86 , & V_12 -> V_78 ) )
return;
if ( ! F_37 ( V_87 , & V_12 -> V_78 ) )
F_38 ( V_85 , & V_12 -> V_20 ) ;
}
static void F_44 ( struct V_74 * V_75 )
{
if ( V_75 -> V_88 == V_89 )
F_39 ( V_75 ) ;
}
int F_45 ( int V_8 )
{
struct V_10 * V_12 ;
if ( V_90 . V_91 != 0 )
return 0 ;
if ( V_8 == F_46 () )
return 0 ;
V_12 = F_19 ( V_8 , V_69 ) ;
if ( ! V_12 )
return - V_70 ;
F_42 ( V_12 ) ;
return 0 ;
}
static void F_47 ( struct V_92 * V_74 , struct V_10 * V_12 )
{
V_12 -> V_74 = V_74 ;
V_12 -> V_74 -> V_75 -> V_93 = F_35 ;
V_12 -> V_74 -> V_75 -> V_94 = F_39 ;
V_12 -> V_74 -> V_75 -> V_95 = F_44 ;
V_12 -> V_74 -> V_75 -> V_96 = V_12 ;
V_12 -> V_74 -> V_75 -> V_97 = V_69 ;
}
static void F_48 ( struct V_36 * V_98 , T_2 V_99 ,
int * V_100 )
{
V_98 -> V_39 = V_61 [ 0 ] -> V_39 ;
if ( V_98 -> V_39 == V_40 ) {
struct V_41 * V_101 = (struct V_41 * ) V_98 ;
V_101 -> V_46 = F_49 ( V_99 ) ;
* V_100 = sizeof( struct V_41 ) ;
memset ( & V_101 -> V_102 , 0 , sizeof( V_101 -> V_102 ) ) ;
} else {
struct V_48 * V_103 = (struct V_48 * ) V_98 ;
V_103 -> V_50 = F_49 ( V_99 ) ;
* V_100 = sizeof( struct V_48 ) ;
}
memset ( ( char * ) V_98 + * V_100 , 0 , sizeof( struct V_36 ) - * V_100 ) ;
}
static void F_50 ( struct V_10 * V_12 , bool V_104 )
{
F_20 ( & V_12 -> V_17 ) ;
if ( V_12 -> V_74 ) {
F_51 ( V_12 -> V_74 ) ;
V_12 -> V_74 = NULL ;
}
if ( V_12 -> V_105 && V_104 ) {
F_50 ( V_12 -> V_105 , false ) ;
}
if ( V_12 -> V_106 ) {
F_52 ( V_12 -> V_106 ) ;
V_12 -> V_106 = NULL ;
}
V_12 -> V_107 = 0 ;
F_21 ( & V_12 -> V_17 ) ;
}
static void F_53 ( T_3 V_108 )
{
static char V_109 [ F_54 ( sizeof( struct V_110 ) ) ] ;
struct V_111 V_112 ;
struct V_113 * V_114 ;
struct V_110 * V_115 ;
int V_116 ;
struct V_10 * V_12 ;
V_12 = F_19 ( 0 , 0 ) ;
F_55 ( V_12 == NULL ) ;
V_112 . V_117 = NULL ;
V_112 . V_118 = 0 ;
V_112 . V_119 = V_109 ;
V_112 . V_120 = sizeof( V_109 ) ;
V_112 . V_121 = V_122 ;
V_114 = F_56 ( & V_112 ) ;
V_114 -> V_123 = V_124 ;
V_114 -> V_125 = V_126 ;
V_114 -> V_127 = F_57 ( sizeof( struct V_110 ) ) ;
V_112 . V_120 = V_114 -> V_127 ;
V_115 = F_58 ( V_114 ) ;
memset ( V_115 , 0x00 , sizeof( struct V_110 ) ) ;
V_115 -> V_128 |= V_129 ;
V_115 -> V_130 = V_108 ;
V_116 = F_59 ( V_12 -> V_74 , & V_112 , NULL , 0 , 0 ) ;
if ( V_116 != 0 )
F_60 ( L_1 , V_116 ) ;
}
static void F_61 ( struct V_10 * V_12 )
{
V_12 -> V_33 = 0 ;
if ( F_41 ( V_87 , & V_12 -> V_78 ) ) {
if ( ! F_37 ( V_84 , & V_12 -> V_78 ) )
F_38 ( V_85 , & V_12 -> V_20 ) ;
}
}
static void F_62 ( void )
{
F_20 ( & V_31 ) ;
F_16 ( F_61 ) ;
F_21 ( & V_31 ) ;
}
static void F_63 ( struct V_10 * V_12 ,
struct V_111 * V_131 , char * V_132 )
{
union V_133 * V_134 = (union V_133 * ) V_132 ;
if ( V_134 -> V_135 . V_136 == V_137 ) {
switch ( V_134 -> V_138 . V_139 ) {
case V_140 :
case V_141 :
{
struct V_142 V_143 ;
int V_8 ;
int V_144 , V_116 ;
int V_100 ;
struct V_10 * V_145 ;
if ( ( int ) V_134 -> V_138 . V_146 <= 0 ) {
F_60 ( L_2 ,
( int ) V_134 -> V_138 . V_146 ) ;
F_62 () ;
return;
}
memset ( & V_143 , 0 , sizeof( struct V_142 ) ) ;
V_144 = sizeof( struct V_142 ) ;
V_143 . V_147 = V_134 -> V_138 . V_146 ;
V_116 = F_64 ( V_12 -> V_74 ,
V_124 ,
V_148 ,
( char * ) & V_143 ,
& V_144 ) ;
if ( V_116 < 0 ) {
F_60 ( L_3
L_4 ,
( int ) V_134 -> V_138 . V_146 ,
V_116 ) ;
V_145 = F_22 ( V_134 -> V_138 . V_146 ) ;
if ( V_145 )
F_40 ( V_87 , & V_12 -> V_78 ) ;
return;
}
F_48 ( & V_143 . V_149 , 0 , & V_100 ) ;
if ( F_30 ( & V_143 . V_149 , & V_8 ) ) {
unsigned char * V_150 = ( unsigned char * ) & V_143 . V_149 ;
F_60 ( L_5 ) ;
F_65 ( L_6 , V_151 ,
V_150 , sizeof( struct V_36 ) ) ;
F_53 ( V_143 . V_147 ) ;
return;
}
V_145 = F_19 ( V_8 , V_69 ) ;
if ( ! V_145 )
return;
F_66 ( V_12 -> V_74 -> V_75 ) ;
V_116 = F_67 ( V_12 -> V_74 -> V_75 ,
V_134 -> V_138 . V_146 ,
& V_145 -> V_74 ) ;
F_68 ( V_12 -> V_74 -> V_75 ) ;
if ( V_116 < 0 ) {
F_60 ( L_7
L_8 ,
( int ) V_134 -> V_138 . V_146 ,
V_8 , V_116 ) ;
return;
}
F_47 ( V_145 -> V_74 , V_145 ) ;
F_60 ( L_9 ,
V_8 , ( int ) V_134 -> V_138 . V_146 ) ;
F_40 ( V_87 , & V_145 -> V_78 ) ;
F_40 ( V_152 , & V_12 -> V_78 ) ;
if ( ! F_37 ( V_84 , & V_145 -> V_78 ) ) {
F_38 ( V_85 , & V_145 -> V_20 ) ;
}
if ( ! F_37 ( V_77 , & V_145 -> V_78 ) )
F_38 ( V_79 , & V_145 -> V_22 ) ;
}
break;
case V_153 :
case V_154 :
{
V_12 = F_22 ( V_134 -> V_138 . V_146 ) ;
if ( V_12 ) {
V_12 -> V_33 = 0 ;
}
}
break;
case V_155 :
{
F_60 ( L_10 ) ;
F_62 () ;
}
break;
default:
F_60 ( L_11 ,
( int ) V_134 -> V_138 . V_146 ,
V_134 -> V_138 . V_139 ) ;
}
}
}
static int F_69 ( struct V_10 * V_12 )
{
int V_116 = 0 ;
struct V_111 V_131 = {} ;
struct V_156 V_157 [ 2 ] ;
unsigned V_4 ;
int V_11 ;
int V_158 = 0 ;
int V_159 ;
char V_160 [ F_54 ( sizeof( struct V_110 ) ) ] ;
F_20 ( & V_12 -> V_17 ) ;
if ( V_12 -> V_74 == NULL ) {
V_116 = - V_161 ;
goto V_162;
}
if ( V_12 -> V_106 == NULL ) {
V_12 -> V_106 = F_70 ( V_163 ) ;
if ( V_12 -> V_106 == NULL )
goto V_164;
F_3 ( & V_12 -> V_2 , V_165 ) ;
}
memset ( & V_160 , 0 , sizeof( V_160 ) ) ;
V_131 . V_119 = V_160 ;
V_131 . V_120 = sizeof( V_160 ) ;
V_157 [ 0 ] . V_166 = V_12 -> V_2 . V_5 - F_2 ( & V_12 -> V_2 ) ;
V_157 [ 0 ] . V_167 = F_71 ( V_12 -> V_106 ) + F_2 ( & V_12 -> V_2 ) ;
V_157 [ 1 ] . V_166 = 0 ;
V_159 = 1 ;
if ( F_2 ( & V_12 -> V_2 ) >= V_12 -> V_2 . V_5 ) {
V_157 [ 0 ] . V_166 = V_165 - F_2 ( & V_12 -> V_2 ) ;
V_157 [ 1 ] . V_166 = V_12 -> V_2 . V_5 ;
V_157 [ 1 ] . V_167 = F_71 ( V_12 -> V_106 ) ;
V_159 = 2 ;
}
V_4 = V_157 [ 0 ] . V_166 + V_157 [ 1 ] . V_166 ;
V_11 = V_116 = F_72 ( V_12 -> V_74 , & V_131 , V_157 , V_159 , V_4 ,
V_168 | V_169 ) ;
if ( V_116 <= 0 )
goto V_162;
if ( V_131 . V_121 & V_170 ) {
V_131 . V_119 = V_160 ;
V_131 . V_120 = sizeof( V_160 ) ;
F_63 ( V_12 , & V_131 ,
F_71 ( V_12 -> V_106 ) + V_12 -> V_2 . V_5 ) ;
F_21 ( & V_12 -> V_17 ) ;
return 0 ;
}
F_55 ( V_12 -> V_8 == 0 ) ;
if ( V_116 == V_4 )
V_158 = 1 ;
F_1 ( & V_12 -> V_2 , V_116 ) ;
V_116 = F_73 ( V_12 -> V_8 ,
F_71 ( V_12 -> V_106 ) ,
V_12 -> V_2 . V_5 , V_12 -> V_2 . V_4 ,
V_165 ) ;
if ( V_116 == - V_171 ) {
F_60 ( L_12
L_13 ,
F_71 ( V_12 -> V_106 ) , V_12 -> V_2 . V_5 , V_12 -> V_2 . V_4 ,
V_4 , V_157 [ 0 ] . V_167 , V_11 ) ;
}
if ( V_116 < 0 )
goto V_162;
F_4 ( & V_12 -> V_2 , V_116 ) ;
if ( F_5 ( & V_12 -> V_2 ) && ! V_158 ) {
F_52 ( V_12 -> V_106 ) ;
V_12 -> V_106 = NULL ;
}
if ( V_158 )
goto V_164;
F_21 ( & V_12 -> V_17 ) ;
return 0 ;
V_164:
if ( ! F_37 ( V_77 , & V_12 -> V_78 ) )
F_38 ( V_79 , & V_12 -> V_22 ) ;
F_21 ( & V_12 -> V_17 ) ;
return - V_161 ;
V_162:
F_21 ( & V_12 -> V_17 ) ;
if ( V_116 != - V_161 ) {
F_50 ( V_12 , false ) ;
}
if ( V_116 == 0 )
V_116 = - V_161 ;
return V_116 ;
}
static int F_74 ( struct V_10 * V_12 )
{
int V_172 ;
struct V_36 V_173 ;
struct V_92 * V_174 ;
int V_4 ;
int V_8 ;
struct V_10 * V_175 ;
struct V_10 * V_176 ;
F_20 ( & V_31 ) ;
if ( ! V_177 ) {
F_21 ( & V_31 ) ;
return - 1 ;
}
F_21 ( & V_31 ) ;
memset ( & V_173 , 0 , sizeof( V_173 ) ) ;
V_172 = F_75 ( V_61 [ 0 ] -> V_39 , V_178 ,
V_179 , & V_174 ) ;
if ( V_172 < 0 )
return - V_70 ;
F_76 ( & V_12 -> V_17 , 0 ) ;
V_172 = - V_180 ;
if ( V_12 -> V_74 == NULL )
goto V_181;
V_174 -> type = V_12 -> V_74 -> type ;
V_174 -> V_182 = V_12 -> V_74 -> V_182 ;
V_172 = V_12 -> V_74 -> V_182 -> V_183 ( V_12 -> V_74 , V_174 , V_184 ) ;
if ( V_172 < 0 )
goto V_181;
memset ( & V_173 , 0 , sizeof( V_173 ) ) ;
if ( V_174 -> V_182 -> V_185 ( V_174 , (struct V_52 * ) & V_173 ,
& V_4 , 2 ) ) {
V_172 = - V_186 ;
goto V_181;
}
F_48 ( & V_173 , 0 , & V_4 ) ;
if ( F_30 ( & V_173 , & V_8 ) ) {
unsigned char * V_150 = ( unsigned char * ) & V_173 ;
F_60 ( L_14 ) ;
F_65 ( L_6 , V_151 ,
V_150 , sizeof( struct V_36 ) ) ;
F_51 ( V_174 ) ;
F_21 ( & V_12 -> V_17 ) ;
return - 1 ;
}
F_60 ( L_15 , V_8 ) ;
V_175 = F_19 ( V_8 , V_69 ) ;
if ( ! V_175 ) {
V_172 = - V_70 ;
goto V_181;
}
F_76 ( & V_175 -> V_17 , 1 ) ;
if ( V_175 -> V_74 ) {
struct V_10 * V_105 = V_175 -> V_105 ;
if ( ! V_105 ) {
V_105 = F_10 ( V_14 , V_69 ) ;
if ( ! V_105 ) {
F_60 ( L_16 ) ;
F_21 ( & V_175 -> V_17 ) ;
V_172 = - V_70 ;
goto V_181;
}
V_105 -> V_8 = V_8 ;
V_105 -> V_26 = F_69 ;
F_12 ( & V_105 -> V_17 ) ;
F_15 ( & V_105 -> V_20 , V_21 ) ;
F_15 ( & V_105 -> V_22 , V_23 ) ;
F_77 ( V_187 , & V_105 -> V_78 ) ;
}
if ( ! V_105 -> V_74 ) {
V_175 -> V_105 = V_105 ;
V_105 -> V_74 = V_174 ;
V_174 -> V_75 -> V_96 = V_105 ;
F_47 ( V_174 , V_105 ) ;
V_176 = V_105 ;
}
else {
F_78 ( L_17 , V_8 ) ;
V_172 = - V_161 ;
F_21 ( & V_175 -> V_17 ) ;
goto V_181;
}
}
else {
V_174 -> V_75 -> V_96 = V_175 ;
V_175 -> V_26 = F_69 ;
F_47 ( V_174 , V_175 ) ;
V_176 = V_175 ;
}
F_21 ( & V_175 -> V_17 ) ;
if ( ! F_37 ( V_77 , & V_176 -> V_78 ) )
F_38 ( V_79 , & V_176 -> V_22 ) ;
F_21 ( & V_12 -> V_17 ) ;
return 0 ;
V_181:
F_21 ( & V_12 -> V_17 ) ;
F_51 ( V_174 ) ;
if ( V_172 != - V_161 )
F_60 ( L_18 , V_172 ) ;
return V_172 ;
}
static void F_79 ( struct V_188 * V_189 )
{
F_52 ( V_189 -> V_190 ) ;
F_33 ( V_189 ) ;
}
static void F_80 ( struct V_10 * V_12 )
{
struct V_36 V_191 ;
char V_109 [ F_54 ( sizeof( struct V_110 ) ) ] ;
struct V_111 V_112 ;
struct V_113 * V_114 ;
struct V_110 * V_115 ;
struct V_10 * V_192 ;
struct V_188 * V_189 ;
int V_4 , V_193 ;
int V_116 ;
int V_194 ;
struct V_156 V_157 [ 1 ] ;
if ( F_37 ( V_152 , & V_12 -> V_78 ) )
return;
if ( V_12 -> V_107 ++ > V_195 )
return;
if ( F_27 ( V_12 -> V_8 , NULL , (struct V_52 * ) & V_191 ) ) {
F_60 ( L_19 , V_12 -> V_8 ) ;
return;
}
V_192 = F_19 ( 0 , 0 ) ;
F_55 ( V_192 == NULL ) ;
F_48 ( & V_191 , V_90 . V_196 , & V_194 ) ;
V_112 . V_117 = & V_191 ;
V_112 . V_118 = V_194 ;
V_112 . V_119 = V_109 ;
V_112 . V_120 = sizeof( V_109 ) ;
V_112 . V_121 = V_122 ;
F_28 ( & V_12 -> V_19 ) ;
if ( F_81 ( & V_12 -> V_18 ) ) {
F_29 ( & V_12 -> V_19 ) ;
F_60 ( L_20 , V_12 -> V_8 ) ;
return;
}
V_189 = F_82 ( & V_12 -> V_18 , struct V_188 , V_15 ) ;
V_4 = V_189 -> V_4 ;
V_193 = V_189 -> V_193 ;
F_29 ( & V_12 -> V_19 ) ;
V_157 [ 0 ] . V_167 = F_71 ( V_189 -> V_190 ) + V_193 ;
V_157 [ 0 ] . V_166 = V_4 ;
V_114 = F_56 ( & V_112 ) ;
V_114 -> V_123 = V_124 ;
V_114 -> V_125 = V_126 ;
V_114 -> V_127 = F_57 ( sizeof( struct V_110 ) ) ;
V_115 = F_58 ( V_114 ) ;
memset ( V_115 , 0x00 , sizeof( struct V_110 ) ) ;
V_115 -> V_197 = F_83 ( F_46 () ) ;
V_112 . V_120 = V_114 -> V_127 ;
V_116 = F_59 ( V_192 -> V_74 , & V_112 , V_157 , 1 , V_4 ) ;
if ( V_116 < 0 ) {
F_60 ( L_21 ,
V_12 -> V_8 , V_116 ) ;
F_40 ( V_87 , & V_12 -> V_78 ) ;
F_40 ( V_152 , & V_12 -> V_78 ) ;
}
else {
F_28 ( & V_12 -> V_19 ) ;
V_189 -> V_193 += V_116 ;
V_189 -> V_4 -= V_116 ;
if ( V_189 -> V_4 == 0 && V_189 -> V_198 == 0 ) {
F_84 ( & V_189 -> V_15 ) ;
F_79 ( V_189 ) ;
}
F_29 ( & V_12 -> V_19 ) ;
}
}
static void F_85 ( struct V_10 * V_12 )
{
struct V_36 V_98 , V_199 ;
int V_100 ;
struct V_92 * V_74 = NULL ;
int V_200 = 1 ;
int V_172 ;
if ( V_12 -> V_8 == 0 ) {
F_60 ( L_22 ) ;
return;
}
F_20 ( & V_12 -> V_17 ) ;
if ( V_12 -> V_107 ++ > V_195 )
goto V_201;
if ( V_12 -> V_74 )
goto V_201;
V_172 = F_75 ( V_61 [ 0 ] -> V_39 , V_178 ,
V_179 , & V_74 ) ;
if ( V_172 < 0 )
goto V_202;
memset ( & V_98 , 0 , sizeof( V_98 ) ) ;
V_172 = F_27 ( V_12 -> V_8 , & V_98 , NULL ) ;
if ( V_172 < 0 ) {
F_60 ( L_19 , V_12 -> V_8 ) ;
goto V_202;
}
V_74 -> V_75 -> V_96 = V_12 ;
V_12 -> V_26 = F_69 ;
V_12 -> V_25 = F_85 ;
F_47 ( V_74 , V_12 ) ;
memcpy ( & V_199 , V_61 [ 0 ] , sizeof( V_199 ) ) ;
F_48 ( & V_199 , 0 , & V_100 ) ;
V_172 = V_74 -> V_182 -> V_203 ( V_74 , (struct V_52 * ) & V_199 ,
V_100 ) ;
if ( V_172 < 0 ) {
F_60 ( L_23 , V_172 ) ;
}
F_48 ( & V_98 , V_90 . V_196 , & V_100 ) ;
F_60 ( L_24 , V_12 -> V_8 ) ;
F_86 ( V_74 , V_204 , V_205 , ( char * ) & V_200 ,
sizeof( V_200 ) ) ;
V_172 = V_74 -> V_182 -> V_206 ( V_74 , (struct V_52 * ) & V_98 , V_100 ,
V_184 ) ;
if ( V_172 == - V_207 )
V_172 = 0 ;
if ( V_172 == 0 )
goto V_201;
V_202:
if ( V_12 -> V_74 ) {
F_51 ( V_12 -> V_74 ) ;
V_12 -> V_74 = NULL ;
} else if ( V_74 ) {
F_51 ( V_74 ) ;
}
if ( V_172 != - V_208 &&
V_172 != - V_209 &&
V_172 != - V_210 &&
V_172 != - V_211 &&
V_172 != - V_212 ) {
F_60 ( L_25 , V_12 -> V_8 ,
V_12 -> V_107 , V_172 ) ;
F_21 ( & V_12 -> V_17 ) ;
F_87 ( 1000 ) ;
F_42 ( V_12 ) ;
return;
}
V_201:
F_21 ( & V_12 -> V_17 ) ;
return;
}
static struct V_92 * F_88 ( struct V_10 * V_12 ,
struct V_36 * V_98 )
{
struct V_92 * V_74 = NULL ;
int V_172 = 0 ;
int V_200 = 1 ;
int V_100 ;
if ( V_61 [ 0 ] -> V_39 == V_40 )
V_100 = sizeof( struct V_41 ) ;
else
V_100 = sizeof( struct V_48 ) ;
V_172 = F_75 ( V_61 [ 0 ] -> V_39 , V_178 ,
V_179 , & V_74 ) ;
if ( V_172 < 0 ) {
F_60 ( L_26 ) ;
goto V_213;
}
F_86 ( V_74 , V_204 , V_205 , ( char * ) & V_200 ,
sizeof( V_200 ) ) ;
V_172 = F_86 ( V_74 , V_214 , V_215 ,
( char * ) & V_200 , sizeof( V_200 ) ) ;
if ( V_172 < 0 ) {
F_60 ( L_27 , V_172 ) ;
}
V_12 -> V_26 = F_74 ;
V_12 -> V_25 = F_85 ;
F_48 ( V_98 , V_90 . V_196 , & V_100 ) ;
V_172 = V_74 -> V_182 -> V_203 ( V_74 , (struct V_52 * ) V_98 , V_100 ) ;
if ( V_172 < 0 ) {
F_60 ( L_28 , V_90 . V_196 ) ;
F_51 ( V_74 ) ;
V_74 = NULL ;
V_12 -> V_74 = NULL ;
goto V_213;
}
V_172 = F_86 ( V_74 , V_214 , V_216 ,
( char * ) & V_200 , sizeof( V_200 ) ) ;
if ( V_172 < 0 ) {
F_60 ( L_29 , V_172 ) ;
}
V_172 = V_74 -> V_182 -> V_217 ( V_74 , 5 ) ;
if ( V_172 < 0 ) {
F_60 ( L_30 , V_90 . V_196 ) ;
F_51 ( V_74 ) ;
V_74 = NULL ;
goto V_213;
}
V_213:
return V_74 ;
}
static void F_89 ( void )
{
struct V_36 V_54 , * V_58 ;
int V_28 ;
V_55 = 0 ;
for ( V_28 = 0 ; V_28 < V_72 ; V_28 ++ ) {
if ( F_90 ( & V_54 , V_28 ) )
break;
V_58 = F_91 ( sizeof( * V_58 ) , V_69 ) ;
if ( ! V_58 )
break;
memcpy ( V_58 , & V_54 , sizeof( * V_58 ) ) ;
V_61 [ V_55 ++ ] = V_58 ;
}
}
static int F_92 ( struct V_10 * V_218 ,
struct V_36 * V_58 ,
int V_100 , int V_219 )
{
int V_172 = 0 ;
if ( V_219 == 1 )
V_172 = F_93 ( V_218 -> V_74 ,
(struct V_52 * ) V_58 ,
V_100 ) ;
else
V_172 = F_86 ( V_218 -> V_74 , V_220 ,
V_221 ,
( char * ) V_58 , V_100 ) ;
if ( V_172 < 0 )
F_60 ( L_31 ,
V_90 . V_196 , V_219 ) ;
return V_172 ;
}
static int F_94 ( void )
{
struct V_92 * V_74 = NULL ;
struct V_36 V_222 ;
struct V_223 V_224 ;
int V_172 = - V_211 , V_219 = 1 , V_28 , V_100 ;
struct V_10 * V_12 = F_19 ( 0 , V_69 ) ;
int V_225 = V_226 ;
if ( ! V_12 )
return - V_70 ;
F_60 ( L_32 ) ;
V_172 = F_75 ( V_61 [ 0 ] -> V_39 , V_227 ,
V_124 , & V_74 ) ;
if ( V_172 < 0 ) {
F_60 ( L_33 ) ;
goto V_201;
}
memset ( & V_224 , 0 , sizeof( V_224 ) ) ;
V_224 . V_228 = 1 ;
V_224 . V_229 = 1 ;
V_224 . V_230 = 1 ;
V_224 . V_231 = 1 ;
V_224 . V_232 = 1 ;
V_172 = F_86 ( V_74 , V_214 , V_233 ,
( char * ) & V_225 , sizeof( V_225 ) ) ;
if ( V_172 )
F_60 ( L_34 , V_172 ) ;
V_172 = F_86 ( V_74 , V_220 , V_234 ,
( char * ) & V_224 , sizeof( V_224 ) ) ;
if ( V_172 < 0 ) {
F_60 ( L_35 ,
V_172 ) ;
goto V_235;
}
V_74 -> V_75 -> V_96 = V_12 ;
V_12 -> V_74 = V_74 ;
V_12 -> V_74 -> V_75 -> V_93 = F_35 ;
V_12 -> V_26 = F_69 ;
V_12 -> V_25 = F_80 ;
for ( V_28 = 0 ; V_28 < V_55 ; V_28 ++ ) {
memcpy ( & V_222 , V_61 [ V_28 ] , sizeof( V_222 ) ) ;
F_48 ( & V_222 , V_90 . V_196 , & V_100 ) ;
V_172 = F_92 ( V_12 , & V_222 , V_100 , V_219 ) ;
if ( V_172 )
goto V_235;
++ V_219 ;
}
V_172 = V_74 -> V_182 -> V_217 ( V_74 , 5 ) ;
if ( V_172 < 0 ) {
F_60 ( L_36 ) ;
goto V_235;
}
return 0 ;
V_235:
F_51 ( V_74 ) ;
V_12 -> V_74 = NULL ;
V_201:
return V_172 ;
}
static int F_95 ( void )
{
struct V_92 * V_74 = NULL ;
struct V_10 * V_12 = F_19 ( 0 , V_69 ) ;
int V_172 = - V_211 ;
if ( ! V_12 )
return - V_70 ;
if ( V_61 [ 1 ] != NULL ) {
F_60 ( L_37
L_38 ) ;
return - V_211 ;
}
F_60 ( L_39 ) ;
V_74 = F_88 ( V_12 , V_61 [ 0 ] ) ;
if ( V_74 ) {
F_47 ( V_74 , V_12 ) ;
V_172 = 0 ;
}
else {
V_172 = - V_236 ;
}
return V_172 ;
}
static struct V_188 * F_96 ( struct V_10 * V_12 ,
T_1 V_30 )
{
struct V_188 * V_237 ;
V_237 = F_91 ( sizeof( struct V_188 ) , V_30 ) ;
if ( ! V_237 )
return NULL ;
V_237 -> V_190 = F_70 ( V_30 ) ;
if ( ! V_237 -> V_190 ) {
F_33 ( V_237 ) ;
return NULL ;
}
V_237 -> V_193 = 0 ;
V_237 -> V_4 = 0 ;
V_237 -> V_238 = 0 ;
V_237 -> V_198 = 0 ;
V_237 -> V_12 = V_12 ;
return V_237 ;
}
void * F_97 ( int V_8 , int V_4 , T_1 V_30 , char * * V_239 )
{
struct V_10 * V_12 ;
struct V_188 * V_189 ;
int V_193 = 0 ;
V_12 = F_19 ( V_8 , V_30 ) ;
if ( ! V_12 )
return NULL ;
F_28 ( & V_12 -> V_19 ) ;
V_189 = F_98 ( V_12 -> V_18 . V_240 , struct V_188 , V_15 ) ;
if ( ( & V_189 -> V_15 == & V_12 -> V_18 ) ||
( V_165 - V_189 -> V_238 < V_4 ) ) {
V_189 = NULL ;
} else {
V_193 = V_189 -> V_238 ;
V_189 -> V_238 += V_4 ;
V_189 -> V_198 ++ ;
}
F_29 ( & V_12 -> V_19 ) ;
if ( V_189 ) {
V_241:
* V_239 = F_71 ( V_189 -> V_190 ) + V_193 ;
return V_189 ;
}
V_189 = F_96 ( V_12 , V_30 ) ;
if ( V_189 ) {
F_28 ( & V_12 -> V_19 ) ;
V_193 = V_189 -> V_238 ;
V_189 -> V_238 += V_4 ;
V_189 -> V_198 ++ ;
F_99 ( & V_189 -> V_15 , & V_12 -> V_18 ) ;
F_29 ( & V_12 -> V_19 ) ;
goto V_241;
}
return NULL ;
}
void F_100 ( void * V_242 )
{
struct V_188 * V_189 = (struct V_188 * ) V_242 ;
struct V_10 * V_12 = V_189 -> V_12 ;
int V_198 ;
F_28 ( & V_12 -> V_19 ) ;
V_198 = -- V_189 -> V_198 ;
if ( V_198 )
goto V_201;
V_189 -> V_4 = V_189 -> V_238 - V_189 -> V_193 ;
F_29 ( & V_12 -> V_19 ) ;
if ( ! F_37 ( V_84 , & V_12 -> V_78 ) ) {
F_38 ( V_85 , & V_12 -> V_20 ) ;
}
return;
V_201:
F_29 ( & V_12 -> V_19 ) ;
return;
}
static void F_101 ( struct V_10 * V_12 )
{
int V_116 = 0 ;
const int V_121 = V_168 | V_169 ;
struct V_188 * V_189 ;
int V_4 , V_193 ;
int V_243 = 0 ;
F_20 ( & V_12 -> V_17 ) ;
if ( V_12 -> V_74 == NULL )
goto V_244;
F_28 ( & V_12 -> V_19 ) ;
for (; ; ) {
V_189 = F_98 ( V_12 -> V_18 . V_245 , struct V_188 ,
V_15 ) ;
if ( (struct V_246 * ) V_189 == & V_12 -> V_18 )
break;
V_4 = V_189 -> V_4 ;
V_193 = V_189 -> V_193 ;
F_55 ( V_4 == 0 && V_189 -> V_198 == 0 ) ;
F_29 ( & V_12 -> V_19 ) ;
V_116 = 0 ;
if ( V_4 ) {
V_116 = F_102 ( V_12 -> V_74 , V_189 -> V_190 , V_193 , V_4 ,
V_121 ) ;
if ( V_116 == - V_161 || V_116 == 0 ) {
if ( V_116 == - V_161 &&
F_43 ( V_83 , & V_12 -> V_74 -> V_78 ) &&
! F_37 ( V_81 , & V_12 -> V_78 ) ) {
F_77 ( V_80 , & V_12 -> V_74 -> V_78 ) ;
V_12 -> V_74 -> V_75 -> V_82 ++ ;
}
F_103 () ;
goto V_201;
} else if ( V_116 < 0 )
goto V_247;
}
if ( ++ V_243 >= V_248 ) {
F_103 () ;
V_243 = 0 ;
}
F_28 ( & V_12 -> V_19 ) ;
V_189 -> V_193 += V_116 ;
V_189 -> V_4 -= V_116 ;
if ( V_189 -> V_4 == 0 && V_189 -> V_198 == 0 ) {
F_84 ( & V_189 -> V_15 ) ;
F_79 ( V_189 ) ;
}
}
F_29 ( & V_12 -> V_19 ) ;
V_201:
F_21 ( & V_12 -> V_17 ) ;
return;
V_247:
F_21 ( & V_12 -> V_17 ) ;
F_50 ( V_12 , false ) ;
F_42 ( V_12 ) ;
return;
V_244:
F_21 ( & V_12 -> V_17 ) ;
if ( ! F_43 ( V_152 , & V_12 -> V_78 ) )
F_42 ( V_12 ) ;
}
static void F_104 ( struct V_10 * V_12 )
{
struct V_188 * V_189 , * V_249 ;
F_28 ( & V_12 -> V_19 ) ;
F_105 (e, safe, &con->writequeue, list) {
F_84 ( & V_189 -> V_15 ) ;
F_79 ( V_189 ) ;
}
F_29 ( & V_12 -> V_19 ) ;
}
int F_106 ( int V_8 )
{
struct V_10 * V_12 ;
struct V_34 * V_35 ;
F_60 ( L_40 , V_8 ) ;
V_12 = F_19 ( V_8 , 0 ) ;
if ( V_12 ) {
F_40 ( V_87 , & V_12 -> V_78 ) ;
F_40 ( V_84 , & V_12 -> V_78 ) ;
F_77 ( V_86 , & V_12 -> V_78 ) ;
if ( F_107 ( & V_12 -> V_20 ) )
F_60 ( L_41 , V_8 ) ;
if ( F_107 ( & V_12 -> V_22 ) )
F_60 ( L_42 , V_8 ) ;
F_104 ( V_12 ) ;
F_50 ( V_12 , true ) ;
}
F_28 ( & V_56 ) ;
V_35 = F_23 ( V_8 ) ;
if ( V_35 ) {
F_84 ( & V_35 -> V_15 ) ;
while ( V_35 -> V_57 -- )
F_33 ( V_35 -> V_58 [ V_35 -> V_57 ] ) ;
F_33 ( V_35 ) ;
}
F_29 ( & V_56 ) ;
return 0 ;
}
static void V_23 ( struct V_250 * V_251 )
{
struct V_10 * V_12 = F_108 ( V_251 , struct V_10 , V_22 ) ;
int V_252 ;
F_40 ( V_77 , & V_12 -> V_78 ) ;
do {
V_252 = V_12 -> V_26 ( V_12 ) ;
} while ( ! V_252 );
}
static void V_21 ( struct V_250 * V_251 )
{
struct V_10 * V_12 = F_108 ( V_251 , struct V_10 , V_20 ) ;
if ( F_41 ( V_87 , & V_12 -> V_78 ) ) {
V_12 -> V_25 ( V_12 ) ;
F_77 ( V_84 , & V_12 -> V_78 ) ;
}
if ( F_41 ( V_84 , & V_12 -> V_78 ) )
F_101 ( V_12 ) ;
}
static void F_109 ( void )
{
F_16 ( F_104 ) ;
}
static void F_110 ( void )
{
F_111 ( V_79 ) ;
F_111 ( V_85 ) ;
}
static int F_112 ( void )
{
V_79 = F_113 ( L_43 ,
V_253 | V_254 , 1 ) ;
if ( ! V_79 ) {
F_60 ( L_44 ) ;
return - V_70 ;
}
V_85 = F_113 ( L_45 ,
V_253 | V_254 , 1 ) ;
if ( ! V_85 ) {
F_60 ( L_46 ) ;
F_111 ( V_79 ) ;
return - V_70 ;
}
return 0 ;
}
static void F_114 ( struct V_10 * V_12 )
{
V_12 -> V_78 |= 0x0F ;
if ( V_12 -> V_74 && V_12 -> V_74 -> V_75 )
V_12 -> V_74 -> V_75 -> V_96 = NULL ;
}
static void F_115 ( struct V_10 * V_12 )
{
F_50 ( V_12 , true ) ;
if ( V_12 -> V_105 )
F_116 ( V_14 , V_12 -> V_105 ) ;
F_117 ( & V_12 -> V_15 ) ;
F_116 ( V_14 , V_12 ) ;
}
void F_118 ( void )
{
F_20 ( & V_31 ) ;
V_177 = 0 ;
F_16 ( F_114 ) ;
F_21 ( & V_31 ) ;
F_110 () ;
F_20 ( & V_31 ) ;
F_109 () ;
F_16 ( F_115 ) ;
F_21 ( & V_31 ) ;
F_119 ( V_14 ) ;
}
int F_120 ( void )
{
int error = - V_211 ;
struct V_10 * V_12 ;
int V_28 ;
for ( V_28 = 0 ; V_28 < V_9 ; V_28 ++ )
F_121 ( & V_16 [ V_28 ] ) ;
F_89 () ;
if ( ! V_55 ) {
error = - V_180 ;
F_60 ( L_47 ) ;
goto V_255;
}
error = - V_70 ;
V_14 = F_122 ( L_48 , sizeof( struct V_10 ) ,
F_123 ( struct V_10 ) , 0 ,
NULL ) ;
if ( ! V_14 )
goto V_255;
error = F_112 () ;
if ( error )
goto V_256;
V_177 = 1 ;
if ( V_90 . V_91 == 0 )
error = F_95 () ;
else
error = F_94 () ;
if ( error )
goto V_257;
return 0 ;
V_257:
V_177 = 0 ;
V_12 = F_19 ( 0 , 0 ) ;
if ( V_12 ) {
F_50 ( V_12 , false ) ;
F_116 ( V_14 , V_12 ) ;
}
V_256:
F_119 ( V_14 ) ;
V_255:
return error ;
}
void F_124 ( void )
{
struct V_34 * V_35 , * V_249 ;
F_28 ( & V_56 ) ;
F_105 (na, safe, &dlm_node_addrs, list) {
F_84 ( & V_35 -> V_15 ) ;
while ( V_35 -> V_57 -- )
F_33 ( V_35 -> V_58 [ V_35 -> V_57 ] ) ;
F_33 ( V_35 ) ;
}
F_29 ( & V_56 ) ;
}
