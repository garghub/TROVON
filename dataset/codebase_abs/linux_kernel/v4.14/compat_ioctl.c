static int F_1 ( struct V_1 * V_1 , unsigned int V_2 , unsigned long V_3 )
{
int V_4 ;
V_4 = F_2 ( V_1 , V_2 , V_3 ) ;
if ( V_4 )
return V_4 ;
return F_3 ( V_1 , V_2 , V_3 ) ;
}
static int F_4 ( struct V_1 * V_1 ,
unsigned int V_2 , T_1 T_2 * V_5 )
{
int V_4 ;
unsigned long T_2 * V_6 = F_5 ( sizeof( * V_6 ) ) ;
if ( V_6 == NULL )
return - V_7 ;
V_4 = F_1 ( V_1 , V_2 , ( unsigned long ) V_6 ) ;
if ( V_4 )
return V_4 ;
if ( F_6 ( V_6 , V_5 ) )
return - V_7 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_1 ,
unsigned int V_2 , struct V_8 T_2 * V_9 )
{
struct V_10 T_2 * V_11 =
F_5 ( sizeof( * V_11 ) ) ;
int V_4 ;
if ( V_11 == NULL )
return - V_7 ;
V_4 = F_1 ( V_1 , V_2 , ( unsigned long ) V_11 ) ;
if ( ! V_4 ) {
V_4 = F_6 ( & V_11 -> type , & V_9 -> type ) ;
V_4 |= F_6 ( & V_11 -> V_12 , & V_9 -> V_12 ) ;
V_4 |= F_6 ( & V_11 -> V_13 . V_14 . V_15 , & V_9 -> V_13 . V_14 . V_15 ) ;
V_4 |= F_6 ( & V_11 -> V_13 . V_14 . V_16 , & V_9 -> V_13 . V_14 . V_16 ) ;
V_4 |= F_6 ( & V_11 -> V_13 . V_14 . V_17 ,
& V_9 -> V_13 . V_14 . V_17 ) ;
if ( V_4 )
V_4 = - V_7 ;
}
return V_4 ;
}
static int F_8 ( struct V_1 * V_1 ,
unsigned int V_2 , struct V_18 T_2 * V_9 )
{
struct V_19 T_2 * V_20 ;
T_3 V_21 ;
T_4 V_14 ;
int V_4 ;
V_4 = F_9 ( V_21 , & V_9 -> V_22 ) ;
V_4 |= F_9 ( V_14 , & V_9 -> V_14 ) ;
if ( V_4 )
return - V_7 ;
V_20 =
F_5 ( sizeof( struct V_19 ) ) ;
V_4 = F_10 ( F_11 ( V_21 ) , & V_20 -> V_22 ) ;
V_4 |= F_10 ( V_14 , & V_20 -> V_14 ) ;
if ( V_4 )
return - V_7 ;
V_4 = F_1 ( V_1 , V_2 , ( unsigned long ) V_20 ) ;
return V_4 ;
}
static int F_12 ( struct V_1 * V_1 ,
unsigned int V_2 , struct V_23 T_2 * V_9 )
{
struct V_24 T_2 * V_20 ;
T_3 V_25 ;
int V_26 , V_4 ;
V_4 = F_9 ( V_25 , & V_9 -> V_27 ) ;
V_4 |= F_9 ( V_26 , & V_9 -> V_26 ) ;
if ( V_4 )
return - V_7 ;
V_20 = F_5 ( sizeof( struct V_24 ) ) ;
V_4 = F_10 ( F_11 ( V_25 ) , & V_20 -> V_27 ) ;
V_4 |= F_10 ( V_26 , & V_20 -> V_26 ) ;
if ( V_4 )
return - V_7 ;
V_4 = F_1 ( V_1 , V_2 , ( unsigned long ) V_20 ) ;
return V_4 ;
}
static int F_13 ( T_5 T_2 * V_28 , void T_2 * V_29 , T_6 V_30 )
{
T_7 T_2 * V_31 = ( T_7 T_2 * ) ( V_28 + 1 ) ;
T_8 T_2 * V_32 = V_29 ;
int V_33 ;
for ( V_33 = 0 ; V_33 < V_30 ; V_33 ++ ) {
T_9 V_34 , V_35 ;
if ( F_9 ( V_34 , & V_32 [ V_33 ] . V_36 ) ||
F_9 ( V_35 , & V_32 [ V_33 ] . V_37 ) ||
F_10 ( F_11 ( V_34 ) , & V_31 [ V_33 ] . V_36 ) ||
F_10 ( V_35 , & V_31 [ V_33 ] . V_37 ) )
return - V_7 ;
}
if ( F_10 ( V_31 , & V_28 -> V_29 ) )
return - V_7 ;
return 0 ;
}
static int F_14 ( struct V_1 * V_1 , unsigned int V_2 ,
T_10 T_2 * V_38 )
{
T_5 T_2 * V_28 ;
T_6 V_30 ;
T_9 V_39 ;
void T_2 * V_29 ;
int V_4 ;
int V_40 ;
if ( F_9 ( V_40 , & V_38 -> V_40 ) )
return - V_7 ;
if ( V_40 != 'S' )
return F_1 ( V_1 , V_2 , ( unsigned long ) V_38 ) ;
if ( F_9 ( V_30 , & V_38 -> V_30 ) )
return - V_7 ;
{
void T_2 * V_41 = F_5 ( 0 ) ;
void T_2 * V_42 = F_5 ( sizeof( T_5 ) +
( V_30 * sizeof( T_7 ) ) ) ;
if ( V_42 > V_41 )
return - V_43 ;
V_28 = V_42 ;
}
if ( F_15 ( & V_28 -> V_40 , & V_38 -> V_40 ,
( 2 * sizeof( int ) ) +
( 2 * sizeof( unsigned char ) ) +
( 1 * sizeof( unsigned short ) ) +
( 1 * sizeof( unsigned int ) ) ) )
return - V_7 ;
if ( F_9 ( V_39 , & V_38 -> V_29 ) )
return - V_7 ;
V_29 = F_11 ( V_39 ) ;
if ( V_30 ) {
if ( F_13 ( V_28 , V_29 , V_30 ) )
return - V_7 ;
} else {
if ( F_10 ( V_29 , & V_28 -> V_29 ) )
return - V_7 ;
}
{
unsigned char T_2 * V_44 ;
unsigned char T_2 * V_45 ;
if ( F_9 ( V_39 , & V_38 -> V_44 ) )
return - V_7 ;
V_44 = F_11 ( V_39 ) ;
if ( F_9 ( V_39 , & V_38 -> V_45 ) )
return - V_7 ;
V_45 = F_11 ( V_39 ) ;
if ( F_10 ( V_44 , & V_28 -> V_44 ) ||
F_10 ( V_45 , & V_28 -> V_45 ) )
return - V_7 ;
}
if ( F_15 ( & V_28 -> V_46 , & V_38 -> V_46 ,
3 * sizeof( int ) ) )
return - V_7 ;
if ( F_9 ( V_39 , & V_38 -> V_47 ) )
return - V_7 ;
if ( F_10 ( F_11 ( V_39 ) , & V_28 -> V_47 ) )
return - V_7 ;
V_4 = F_1 ( V_1 , V_2 , ( unsigned long ) V_28 ) ;
if ( V_4 >= 0 ) {
void T_2 * V_48 ;
if ( F_15 ( & V_38 -> V_49 , & V_28 -> V_49 ,
sizeof( int ) ) ||
F_9 ( V_48 , & V_28 -> V_47 ) ||
F_10 ( ( T_9 ) ( unsigned long ) V_48 ,
& V_38 -> V_47 ) ||
F_15 ( & V_38 -> V_50 , & V_28 -> V_50 ,
( 4 * sizeof( unsigned char ) ) +
( 2 * sizeof( unsigned short ) ) +
( 3 * sizeof( int ) ) ) )
V_4 = - V_7 ;
}
return V_4 ;
}
static int F_16 ( struct V_1 * V_1 ,
unsigned int V_2 , struct V_51 T_2 * V_52 )
{
int V_4 , V_33 ;
T_11 T_2 * V_53 ;
V_53 = F_5 ( sizeof( T_11 ) * V_54 ) ;
V_4 = F_1 ( V_1 , V_2 , ( unsigned long ) V_53 ) ;
if ( V_4 < 0 )
return V_4 ;
for ( V_33 = 0 ; V_33 < V_54 ; V_33 ++ ) {
void T_2 * V_55 ;
int V_56 ;
if ( F_15 ( V_52 + V_33 , V_53 + V_33 , F_17 ( T_11 , V_47 ) ) ||
F_9 ( V_55 , & V_53 [ V_33 ] . V_47 ) ||
F_9 ( V_56 , & V_53 [ V_33 ] . V_57 ) ||
F_10 ( ( T_9 ) ( unsigned long ) ( V_55 ) , & V_52 [ V_33 ] . V_47 ) ||
F_10 ( V_56 , & V_52 [ V_33 ] . V_57 ) )
return - V_7 ;
}
return V_4 ;
}
static int F_18 ( struct V_1 * V_1 ,
unsigned int V_2 , struct V_58 T_2 * V_59 )
{
struct V_60 T_2 * V_61 = F_5 ( sizeof( struct V_60 ) ) ;
void T_2 * V_62 ;
T_9 V_63 ;
T_6 V_64 ;
if ( F_9 ( V_64 , & V_59 -> V_35 ) ||
F_9 ( V_63 , & V_59 -> V_65 ) )
return - V_7 ;
V_62 = F_11 ( V_63 ) ;
if ( F_10 ( V_64 , & V_61 -> V_35 ) ||
F_10 ( V_62 , & V_61 -> V_65 ) )
return - V_7 ;
if ( V_2 == V_66 )
V_2 = V_67 ;
else
V_2 = V_68 ;
return F_1 ( V_1 , V_2 , ( unsigned long ) V_61 ) ;
}
static int F_19 ( struct V_1 * V_1 , unsigned int V_2 ,
struct V_69 T_2 * V_70 )
{
struct V_71 T_2 * V_72 ;
T_12 V_73 , V_74 ;
int V_4 ;
V_72 = F_5 ( sizeof( * V_72 ) ) ;
V_4 = F_1 ( V_1 , V_75 , ( unsigned long ) V_72 ) ;
if ( ! V_4 ) {
if ( F_9 ( V_73 , & V_72 -> V_76 ) ||
F_9 ( V_74 , & V_72 -> V_77 ) ||
F_10 ( V_73 , & V_70 -> V_76 ) ||
F_10 ( V_74 , & V_70 -> V_77 ) )
V_4 = - V_7 ;
}
return V_4 ;
}
static int F_20 ( struct V_1 * V_1 , unsigned int V_2 ,
struct V_78 T_2 * V_79 )
{
struct V_80 T_2 * V_81 ;
T_13 V_39 ;
void T_2 * V_48 ;
V_81 = F_5 ( sizeof( * V_81 ) ) ;
if ( F_9 ( V_39 , & V_79 -> V_55 ) )
return - V_7 ;
V_48 = F_11 ( V_39 ) ;
if ( F_10 ( V_48 , & V_81 -> V_55 ) )
return - V_7 ;
if ( F_15 ( & V_81 -> V_26 , & V_79 -> V_26 ,
sizeof( T_13 ) + sizeof( int ) ) )
return - V_7 ;
return F_1 ( V_1 , V_82 , ( unsigned long ) V_81 ) ;
}
static int F_21 ( struct V_1 * V_1 ,
unsigned int V_2 , void T_2 * V_5 )
{
struct V_83 T_2 * V_84 = NULL ;
struct V_85 T_2 * V_86 ;
struct V_87 T_2 * V_88 = NULL ;
struct V_89 T_2 * V_90 ;
unsigned long V_91 ;
void * V_92 ;
int V_4 = 0 ;
switch( V_2 ) {
case V_93 :
V_91 = V_94 ;
V_88 = F_5 ( sizeof( * V_88 ) ) ;
V_92 = V_88 ;
break;
default:
V_91 = V_95 ;
V_84 = F_5 ( sizeof( * V_84 ) ) ;
V_92 = V_84 ;
break;
}
if ( V_92 == NULL )
return - V_7 ;
V_4 = F_1 ( V_1 , V_91 , ( unsigned long ) V_92 ) ;
if ( V_4 )
return V_4 ;
switch ( V_2 ) {
case V_93 :
V_90 = V_5 ;
V_4 = F_6 ( & V_88 -> V_96 , & V_90 -> V_96 ) ;
break;
case V_97 :
V_86 = V_5 ;
V_4 = F_6 ( & V_84 -> V_98 , & V_86 -> V_98 ) ;
V_4 |= F_6 ( & V_84 -> V_99 , & V_86 -> V_99 ) ;
V_4 |= F_6 ( & V_84 -> V_100 , & V_86 -> V_100 ) ;
V_4 |= F_6 ( & V_84 -> V_101 , & V_86 -> V_101 ) ;
V_4 |= F_6 ( & V_84 -> V_102 , & V_86 -> V_102 ) ;
V_4 |= F_6 ( & V_84 -> V_103 , & V_86 -> V_103 ) ;
V_4 |= F_6 ( & V_84 -> V_96 , & V_86 -> V_96 ) ;
break;
}
return V_4 ? - V_7 : 0 ;
}
static int F_22 ( struct V_1 * V_1 ,
unsigned V_2 , struct V_104 T_2 * V_105 )
{
typedef struct V_104 T_14;
int V_4 ;
struct V_106 T_2 * V_107 = F_5 ( sizeof( * V_107 ) ) ;
T_13 V_108 ;
unsigned int V_34 ;
unsigned char * V_109 ;
if ( V_107 == NULL )
return - V_7 ;
if ( V_2 == V_110 ) {
if ( F_15 ( V_107 , V_105 , F_17 ( T_14 , V_109 ) ) ||
F_9 ( V_108 , & V_105 -> V_109 ) )
return - V_7 ;
V_109 = F_11 ( V_108 ) ;
if ( F_10 ( V_109 , & V_107 -> V_109 ) ||
F_6 ( & V_105 -> V_111 ,
& V_107 -> V_111 ) ||
F_6 ( & V_105 -> V_112 , & V_107 -> V_112 ) ||
F_10 ( 0UL , & V_107 -> V_113 ) )
return - V_7 ;
}
V_4 = F_1 ( V_1 , V_2 , ( unsigned long ) V_107 ) ;
if ( V_2 == V_114 && V_4 >= 0 ) {
if ( F_15 ( V_105 , V_107 , F_17 ( T_14 , V_109 ) ) ||
F_9 ( V_109 , & V_107 -> V_109 ) )
return - V_7 ;
V_34 = ( unsigned long ) V_109 >> 32 ?
0xffffffff : ( unsigned ) ( unsigned long ) V_109 ;
if ( F_10 ( V_34 , & V_105 -> V_109 ) ||
F_6 ( & V_107 -> V_111 ,
& V_105 -> V_111 ) ||
F_6 ( & V_107 -> V_112 , & V_105 -> V_112 ) )
return - V_7 ;
}
return V_4 ;
}
static int F_23 ( struct V_1 * V_1 ,
unsigned int V_2 , struct V_115 T_2 * V_108 )
{
struct V_116 T_2 * V_117 ;
struct V_118 T_2 * V_119 ;
struct V_120 T_2 * V_121 ;
T_15 V_48 ;
T_9 V_122 ;
int V_33 ;
if ( F_9 ( V_122 , & V_108 -> V_122 ) )
return - V_7 ;
if ( V_122 > V_123 )
return - V_43 ;
if ( F_9 ( V_48 , & V_108 -> V_124 ) )
return - V_7 ;
V_121 = F_11 ( V_48 ) ;
V_117 = F_5 ( sizeof( * V_117 ) +
V_122 * sizeof( struct V_118 ) ) ;
V_119 = & V_117 -> V_124 [ 0 ] ;
if ( F_10 ( V_122 , & V_117 -> V_2 . V_122 ) ||
F_10 ( V_119 , & V_117 -> V_2 . V_124 ) )
return - V_7 ;
for ( V_33 = 0 ; V_33 < V_122 ; V_33 ++ ) {
if ( F_15 ( & V_119 [ V_33 ] . V_125 , & V_121 [ V_33 ] . V_125 , 3 * sizeof( T_6 ) ) )
return - V_7 ;
if ( F_9 ( V_48 , & V_121 [ V_33 ] . V_126 ) ||
F_10 ( F_11 ( V_48 ) , & V_119 [ V_33 ] . V_126 ) )
return - V_7 ;
}
return F_1 ( V_1 , V_2 , ( unsigned long ) V_117 ) ;
}
static int F_24 ( struct V_1 * V_1 ,
unsigned int V_2 , struct V_127 T_2 * V_108 )
{
struct V_128 T_2 * V_117 ;
union {
struct V_127 V_129 ;
struct V_128 V_39 ;
} V_130 ;
V_117 = F_5 ( sizeof( * V_117 ) ) ;
if ( V_117 == NULL )
return - V_131 ;
memset ( & V_130 , 0 , sizeof( V_130 ) ) ;
if ( F_25 ( & V_130 . V_129 , V_108 , sizeof( V_130 . V_129 ) ) )
return - V_7 ;
V_130 . V_39 . V_39 = F_11 ( V_130 . V_129 . V_39 ) ;
if ( F_26 ( V_117 , & V_130 . V_39 , sizeof( V_130 . V_39 ) ) )
return - V_7 ;
return F_1 ( V_1 , V_2 , ( unsigned long ) V_117 ) ;
}
static int F_27 ( struct V_1 * V_1 ,
unsigned V_2 , void T_2 * V_5 )
{
unsigned long T_2 * V_6 = F_5 ( sizeof( * V_6 ) ) ;
int V_132 ;
if ( V_6 == NULL )
return - V_7 ;
switch ( V_2 ) {
case V_133 :
case V_134 :
V_132 = F_1 ( V_1 , ( V_2 == V_133 ) ?
V_135 : V_136 ,
( unsigned long ) V_6 ) ;
if ( V_132 )
return V_132 ;
return F_6 ( V_6 , ( unsigned int T_2 * ) V_5 ) ;
case V_137 :
return F_1 ( V_1 , V_138 , ( unsigned long ) V_5 ) ;
case V_139 :
return F_1 ( V_1 , V_140 , ( unsigned long ) V_5 ) ;
}
return - V_141 ;
}
static int F_28 ( struct V_1 * V_1 ,
struct V_142 T_2 * V_143 )
{
struct V_144 T_2 * V_145 = F_5 ( sizeof( * V_145 ) ) ;
if ( F_15 ( & V_145 -> V_146 , & V_143 -> V_146 , sizeof( V_147 ) ) ||
F_15 ( & V_145 -> V_148 , & V_143 -> V_148 , sizeof( V_147 ) ) ||
F_15 ( & V_145 -> V_149 , & V_143 -> V_149 , sizeof( V_150 ) ) ||
F_15 ( & V_145 -> V_151 , & V_143 -> V_151 , sizeof( V_150 ) ) ||
F_15 ( & V_145 -> V_152 , & V_143 -> V_152 , sizeof( V_153 ) ) ||
F_15 ( & V_145 -> V_154 , & V_143 -> V_154 , sizeof( T_9 ) ) ||
F_15 ( & V_145 -> V_155 , & V_143 -> V_155 , 4 * sizeof( T_9 ) ) )
return - V_7 ;
return F_29 ( V_1 , V_145 ) ;
}
static long F_30 ( unsigned int V_2 ,
unsigned long V_3 , struct V_1 * V_1 )
{
void T_2 * V_5 = F_11 ( V_3 ) ;
switch ( V_2 ) {
case V_156 :
return F_19 ( V_1 , V_2 , V_5 ) ;
case V_157 :
return F_20 ( V_1 , V_2 , V_5 ) ;
case V_66 :
case V_158 :
return F_18 ( V_1 , V_2 , V_5 ) ;
#ifdef F_31
case V_159 :
return F_14 ( V_1 , V_2 , V_5 ) ;
case V_160 :
return F_16 ( V_1 , V_2 , V_5 ) ;
case V_97 :
case V_93 :
return F_21 ( V_1 , V_2 , V_5 ) ;
#endif
case V_114 :
case V_110 :
return F_22 ( V_1 , V_2 , V_5 ) ;
case V_161 :
return F_4 ( V_1 , V_2 , V_5 ) ;
case V_162 :
return F_23 ( V_1 , V_2 , V_5 ) ;
case V_163 :
return F_24 ( V_1 , V_2 , V_5 ) ;
case V_133 :
case V_137 :
case V_134 :
case V_139 :
return F_27 ( V_1 , V_2 , V_5 ) ;
case V_164 :
return F_7 ( V_1 , V_2 , V_5 ) ;
case V_165 :
return F_8 ( V_1 , V_2 , V_5 ) ;
case V_166 :
return F_12 ( V_1 , V_2 , V_5 ) ;
}
switch ( V_2 ) {
case V_167 :
case V_168 :
case V_169 :
case V_170 :
case V_171 :
case V_172 :
case V_173 :
case V_174 :
case V_175 :
case V_176 :
case V_177 :
case V_178 :
case V_179 :
case V_180 :
case V_181 :
return F_3 ( V_1 , V_2 , V_3 ) ;
}
return - V_141 ;
}
static int F_32 ( unsigned int V_182 )
{
int V_33 ;
const int V_183 = F_33 ( V_184 ) - 1 ;
F_34 ( V_183 >= ( 1 << 16 ) ) ;
V_33 = ( ( V_182 >> 16 ) * V_183 ) >> 16 ;
while ( V_184 [ V_33 ] < V_182 && V_33 < V_183 )
V_33 ++ ;
while ( V_184 [ V_33 ] > V_182 && V_33 > 0 )
V_33 -- ;
return V_184 [ V_33 ] == V_182 ;
}
static int T_16 F_35 ( const void * V_145 , const void * V_185 )
{
unsigned int V_186 , V_187 ;
V_186 = * ( unsigned int * ) V_145 ;
V_187 = * ( unsigned int * ) V_185 ;
if ( V_186 > V_187 )
return 1 ;
if ( V_186 < V_187 )
return - 1 ;
return 0 ;
}
static int T_16 F_36 ( void )
{
F_37 ( V_184 , F_33 ( V_184 ) , sizeof( * V_184 ) ,
F_35 , NULL ) ;
return 0 ;
}
