static int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_10 = NULL ;
struct V_11 * V_12 = NULL ;
V_6 = & V_2 -> V_6 [ V_3 ] ;
V_8 = & V_2 -> V_13 [ V_4 ] ;
V_12 = & V_6 -> V_14 [ V_6 -> V_15 ] ;
V_12 -> V_8 = V_8 ;
if ( V_8 -> V_16 ) {
V_12 -> V_17 =
V_8 -> V_16 -> V_18 ;
V_6 -> V_19 = V_2 -> V_20 ;
} else {
V_12 -> V_17 = 0 ;
}
V_12 -> V_21 = F_2 ( sizeof( * V_12 -> V_21 ) , V_22 ) ;
if ( ! V_12 -> V_21 )
return - V_23 ;
V_12 -> V_10 = F_2 ( sizeof( * V_12 -> V_10 ) , V_22 ) ;
if ( ! V_12 -> V_10 )
goto V_24;
V_10 = V_12 -> V_10 ;
V_10 -> V_25 = V_8 -> V_10 ;
V_12 -> V_10 -> V_21 = V_12 -> V_21 ;
V_6 -> V_15 ++ ;
return 0 ;
V_24:
F_3 ( V_12 -> V_21 ) ;
V_12 -> V_21 = NULL ;
return - V_23 ;
}
static int F_4 ( struct V_5 * V_6 )
{
unsigned int V_26 ;
if ( ! V_6 ) {
F_5 ( L_1 ) ;
return - V_27 ;
}
for ( V_26 = 0 ; V_26 < V_6 -> V_15 ; V_26 ++ ) {
F_3 ( V_6 -> V_14 [ V_26 ] . V_21 ) ;
V_6 -> V_14 [ V_26 ] . V_21 = NULL ;
F_3 ( V_6 -> V_14 [ V_26 ] . V_10 ) ;
V_6 -> V_14 [ V_26 ] . V_10 = NULL ;
}
return 0 ;
}
static char * F_6 ( struct V_28 * V_29 ,
unsigned int V_30 )
{
if ( ( ! V_29 -> V_31 ) || ( V_30 > V_29 -> V_31 ) )
return NULL ;
return ( char * ) ( ( ( unsigned long ) ( V_29 -> V_32 ) ) + V_30 ) ;
}
static int F_7 ( struct V_33 * V_34 )
{
int V_35 = V_34 -> V_36 & 0xff ;
int V_37 = V_34 -> V_38 & 0xff ;
if ( V_34 -> V_39 != V_40 ) {
F_5 ( L_2 , V_34 -> V_39 ) ;
return - V_27 ;
}
if ( V_37 != V_41 || V_35 != V_42 ) {
F_5 ( L_3 ,
V_35 , V_37 ) ;
return - V_27 ;
}
return 0 ;
}
static void F_8 ( struct V_43 * V_44 ,
unsigned int V_45 , unsigned int * V_46 ,
unsigned int V_47 )
{
unsigned int V_48 ;
unsigned char * V_49 = ( unsigned char * ) V_46 ;
while ( V_47 ) {
memcpy ( & V_48 , V_49 , 4 ) ;
F_9 ( V_44 , V_45 , V_48 ) ;
V_47 -= 4 ;
V_49 += 4 ;
V_45 += 4 ;
}
}
static void F_10 ( struct V_43 * V_44 ,
unsigned char V_3 , unsigned int V_45 ,
unsigned int * V_46 ,
unsigned int V_47 )
{
unsigned int V_48 ;
unsigned char * V_49 = ( unsigned char * ) V_46 ;
V_45 >>= 0x2 ;
while ( V_47 ) {
memcpy ( & V_48 , V_49 , 4 ) ;
F_11 ( V_44 , V_3 , V_45 ++ , 1 , & V_48 ) ;
V_47 -= 4 ;
V_49 += 4 ;
}
}
static void F_12 ( struct V_43 * V_44 ,
unsigned char V_3 ,
struct V_50
* V_51 )
{
struct V_50 * V_52 ;
if ( ! V_51 )
return;
V_52 = V_51 -> V_53 ;
while ( V_52 ) {
unsigned int V_45 , * V_54 , V_55 ;
V_3 = V_52 -> V_3 ;
V_45 = V_52 -> V_45 ;
V_54 = V_52 -> V_54 ;
V_55 = V_52 -> V_55 ;
F_10 ( V_44 , V_3 , V_45 , V_54 , V_55 ) ;
V_52 = V_52 -> V_53 ;
}
}
static void
F_13 ( struct V_43 * V_44 ,
struct V_50 * * V_56 )
{
struct V_50 * V_52 ;
V_52 = * V_56 ;
while ( V_52 ) {
struct V_50 * V_57 ;
V_57 = V_52 ;
V_52 = V_52 -> V_53 ;
F_3 ( V_57 ) ;
}
* V_56 = NULL ;
}
static int F_14 ( char * V_58 , unsigned int * V_59 )
{
char V_60 [ 16 ] = { 0 } ;
unsigned long V_3 = 0 ;
int V_26 ;
strncpy ( V_60 , V_58 , 15 ) ;
for ( V_26 = 0 ; V_26 < 16 ; V_26 ++ ) {
if ( ! isdigit ( V_60 [ V_26 ] ) ) {
V_60 [ V_26 ] = '\0' ;
break;
}
}
if ( ( F_15 ( V_60 , 10 , & V_3 ) ) )
return - V_61 ;
* V_59 = ( unsigned int ) V_3 ;
return 0 ;
}
static int F_16 ( struct V_43 * V_44 ,
struct V_62 * V_63 ,
unsigned int V_64 , unsigned int * V_3 )
{
struct V_1 * V_2 = V_44 -> V_2 ;
char * V_58 ;
if ( ( V_63 -> V_45 + V_63 -> V_47 ) > ( V_64 << 0x2 ) ) {
F_5 ( L_4 ) ;
return - V_27 ;
}
if ( V_63 -> V_65 != V_66 ) {
F_5 ( L_5 ) ;
return - V_27 ;
}
V_58 = F_6 ( & V_2 -> V_29 , V_63 -> V_67 ) ;
if ( ! V_58 ) {
F_5 ( L_6 ) ;
return - V_27 ;
}
if ( F_14 ( V_58 , V_3 ) ) {
F_5 ( L_7 ) ;
return - V_27 ;
}
if ( * V_3 >= V_68 ) {
F_5 ( L_8 , * V_3 ) ;
return - V_27 ;
}
return 0 ;
}
static int F_17 ( struct V_43
* V_44 , struct V_62
* V_63 , unsigned int V_3 ,
struct V_50
* * V_69 )
{
struct V_50 * V_70 , * V_71 ;
struct V_50 * V_72 , * V_73 ;
struct V_74 * V_75 ;
unsigned int V_26 , V_76 = 0 ;
V_75 =
(struct V_74 * ) ( ( unsigned long ) V_63 +
sizeof( struct V_62 ) ) ;
V_70 = * V_69 ;
if ( ! V_70 ) {
V_70 = F_2 ( sizeof( * V_70 ) , V_22 ) ;
if ( ! V_70 )
return - V_23 ;
V_70 -> V_55 = 1 ;
* V_69 = V_70 ;
V_76 = 1 ;
}
V_73 = V_70 ;
while ( V_73 -> V_53 )
V_73 = V_73 -> V_53 ;
V_71 = V_73 ;
for ( V_26 = 0 ; V_26 < V_63 -> V_77 ; V_26 ++ ) {
V_72 = F_2 ( sizeof( * V_72 ) , V_22 ) ;
if ( ! V_72 )
goto V_24;
V_72 -> V_3 = V_3 ;
V_72 -> V_45 = V_63 -> V_45 + V_75 -> V_78 ;
V_72 -> V_54 = & V_75 -> V_54 ;
V_72 -> V_55 = 4 ;
V_72 -> V_53 = NULL ;
V_71 -> V_53 = V_72 ;
V_71 = V_72 ;
V_70 -> V_55 += F_18 () ;
V_75 ++ ;
}
return 0 ;
V_24:
while ( V_73 ) {
V_72 = V_73 -> V_53 ;
F_3 ( V_73 ) ;
V_73 = V_72 ;
}
if ( V_76 )
F_3 ( * V_69 ) ;
return - V_23 ;
}
static int F_19 ( struct V_43 * V_44 ,
struct V_62 * V_63 )
{
struct V_1 * V_2 = V_44 -> V_2 ;
unsigned int V_3 ;
if ( F_16 ( V_44 , V_63 ,
V_79 , & V_3 ) )
return - V_27 ;
if ( F_17 ( V_44 , V_63 , V_3 ,
& V_2 -> V_80 [ V_3 ] ) )
return - V_27 ;
return 0 ;
}
static int F_20 ( struct V_43 * V_44 ,
struct V_62 * V_63 )
{
struct V_1 * V_2 = V_44 -> V_2 ;
unsigned int V_3 , V_81 , V_82 , V_26 ;
V_81 = V_2 -> V_20 ;
if ( F_16 ( V_44 , V_63 , V_81 , & V_3 ) )
return - V_27 ;
if ( F_17 ( V_44 , V_63 , V_3 ,
& V_2 -> V_83 [ V_3 ] ) )
return - V_27 ;
V_82 = ( V_63 -> V_45 + V_63 -> V_47 ) >> 0x2 ;
for ( V_26 = 0 ; V_26 < V_2 -> V_6 [ V_3 ] . V_15 ; V_26 ++ ) {
if ( V_2 -> V_6 [ V_3 ] . V_14 [ V_26 ] .
V_8 -> V_84 < V_82 )
V_2 -> V_6 [ V_3 ] . V_14 [ V_26 ] .
V_8 -> V_84 = V_82 ;
}
return 0 ;
}
static int F_21 ( struct V_43 * V_44 ,
struct V_62 * V_63 )
{
switch ( V_63 -> V_21 ) {
case V_85 :
if ( F_19 ( V_44 , V_63 ) )
return - V_27 ;
break;
case V_86 :
if ( F_20 ( V_44 , V_63 ) )
return - V_27 ;
break;
default:
F_5 ( L_9 ,
V_63 -> V_21 ) ;
return - V_27 ;
}
return 0 ;
}
static int F_22 ( struct V_43 * V_44 ,
struct V_7 * V_87 )
{
unsigned int V_26 ;
struct V_88 * V_10 ;
struct V_89 * V_90 ;
unsigned char V_3 ;
unsigned int V_81 ;
unsigned int V_91 ;
struct V_1 * V_2 = V_44 -> V_2 ;
T_1 * V_92 ;
V_90 = V_87 -> V_16 ;
V_92 = F_23 ( V_93 , sizeof( T_1 ) ,
V_22 ) ;
if ( ! V_92 )
return - V_23 ;
for ( V_26 = 0 ; V_26 < V_93 ; V_26 ++ )
memcpy ( & V_92 [ V_26 ] , & V_90 -> V_94 ,
sizeof( T_1 ) ) ;
V_10 = V_87 -> V_10 ;
for ( V_3 = 0 ; V_3 < V_44 -> V_95 -> V_96 ; V_3 ++ ) {
if ( ! F_24 ( V_3 , ( unsigned long * ) & V_90 -> V_97 ) )
continue;
V_81 = V_2 -> V_6 [ V_3 ] . V_19 ;
V_91 = V_10 -> V_98 + V_10 -> V_99 ;
F_25 ( V_44 , ( unsigned char ) V_3 , 0 ,
V_10 -> V_98 , & V_92 [ 0 ] ) ;
F_25 ( V_44 , ( unsigned char ) V_3 , V_91 ,
V_81 - V_91 + 1 ,
& V_92 [ V_10 -> V_98 ] ) ;
}
F_3 ( V_92 ) ;
return 0 ;
}
static int F_26 ( struct V_43 * V_44 )
{
int V_26 , V_3 ;
struct V_1 * V_2 = V_44 -> V_2 ;
struct V_62 * V_100 = V_2 -> V_101 . V_63 ;
for ( V_26 = 0 ; V_26 < V_2 -> V_101 . V_102 ; V_26 ++ ) {
if ( V_100 -> V_47 ) {
if ( F_21 ( V_44 , V_100 ) )
return - V_27 ;
}
V_100 = (struct V_62 * ) ( ( unsigned long ) (
( unsigned long ) V_100 +
sizeof( struct V_62 ) ) +
( sizeof( struct V_74 ) *
V_100 -> V_77 ) ) ;
}
for ( V_3 = 0 ; V_3 < V_44 -> V_95 -> V_96 ; V_3 ++ ) {
if ( F_27 ( V_44 , V_3 ,
V_2 -> V_80 [ V_3 ] ) ) {
F_5 ( L_10 , V_3 ) ;
return - V_27 ;
}
F_13 ( V_44 ,
& V_2 -> V_80 [ V_3 ] ) ;
F_12 ( V_44 , V_3 ,
V_2 -> V_83 [ V_3 ] ) ;
F_13 ( V_44 ,
& V_2 ->
V_83 [ V_3 ] ) ;
}
return 0 ;
}
static void * F_28 ( struct V_103 * V_104 ,
char * V_105 , void * V_106 )
{
int V_26 ;
struct V_107 * V_108 =
(struct V_107 * )
( ( unsigned long ) V_104 + sizeof( struct V_103 ) ) ;
for ( V_26 = 0 ; V_26 < V_104 -> V_109 ; V_26 ++ ) {
if ( ( V_106 < ( void * ) & V_108 [ V_26 ] ) &&
! strncmp ( V_108 [ V_26 ] . V_105 , V_105 ,
V_110 ) ) {
return & V_108 [ V_26 ] ;
}
}
return NULL ;
}
static unsigned int F_29 ( unsigned int V_111 , int V_112 )
{
int V_26 ;
unsigned int V_113 = 1 << 0xF ;
unsigned int V_114 = ( unsigned int ) ( ( V_111 >> 0x18 ) ^ V_112 ) ;
V_111 ^= V_114 << 0x8 ;
for ( V_26 = 0 ; V_26 < 0x8 ; V_26 ++ ) {
if ( V_111 & V_113 )
V_111 = ( V_111 << 1 ) ^ 0x1021 ;
else
V_111 <<= 1 ;
}
return V_111 & 0xFFFF ;
}
static unsigned int F_30 ( char * V_49 , int V_59 )
{
unsigned int V_115 = 0 ;
if ( V_49 )
while ( V_59 -- )
V_115 = F_29 ( V_115 , * V_49 ++ ) ;
return V_115 ;
}
static struct V_116 *
F_31 ( char * V_60 , struct V_33 * V_117 ,
char * V_105 )
{
struct V_118 * V_119 ;
struct V_116 * V_104 ;
char * V_120 ;
int V_26 ;
V_119 = (struct V_118 * )
( V_60 + sizeof( struct V_33 ) ) ;
for ( V_26 = 0 ; V_26 < V_117 -> V_109 ; V_26 ++ ) {
if ( ! strncmp ( V_119 -> V_105 , V_105 ,
V_110 ) ) {
V_120 = V_60 + V_119 -> V_121 ;
if ( V_119 -> V_122 != F_30 (
V_120 , V_119 -> V_55 ) )
break;
V_104 = F_2 ( sizeof( * V_104 ) , V_22 ) ;
if ( ! V_104 )
break;
V_104 -> V_123 = V_120 ;
V_104 -> V_122 = V_119 -> V_122 ;
V_104 -> V_55 = V_119 -> V_55 ;
return V_104 ;
}
V_119 ++ ;
}
return NULL ;
}
static unsigned int
F_32 ( struct V_124 * V_125 ,
struct V_89 * V_87 )
{
struct V_126 * V_127 , * V_128 , * V_129 ;
struct V_126 * V_130 ;
struct V_131 * V_132 ;
V_132 = (struct V_131 * )
( ( char * ) V_87 + sizeof( struct V_89 ) ) ;
V_127 = (struct V_126 * ) ( V_125 -> V_133 +
V_132 -> V_134 ) ;
V_128 = (struct V_126 * ) ( V_125 -> V_133 +
V_132 -> V_135 ) ;
V_129 = (struct V_126 * )
( V_125 -> V_133 +
V_132 -> V_136 ) ;
if ( V_127 -> V_102 || V_128 -> V_102 ||
V_129 -> V_102 ) {
F_5 ( L_11 ) ;
return - V_27 ;
}
V_130 = (struct V_126 * )
( V_125 -> V_133 +
V_132 -> V_137 ) ;
if ( V_130 -> V_102 ) {
F_5 ( L_12 ) ;
return - V_27 ;
}
if ( V_87 -> V_138 > 1 ) {
F_5 ( L_13 ) ;
return - V_27 ;
}
if ( F_33 ( V_87 -> V_139 ) ) {
F_5 ( L_14 ) ;
return - V_61 ;
}
if ( F_34 ( V_87 -> V_139 ) ) {
F_5 ( L_15 ) ;
return - V_61 ;
}
return 0 ;
}
static void F_35 ( struct V_124
* V_125 ,
struct V_89 * V_140 ,
struct V_88 * V_10 )
{
struct V_131 * V_132 ;
struct V_141 * V_142 ;
struct V_126 * V_143 ;
struct V_144 * V_145 ;
int V_26 ;
V_132 = (struct V_131 * )
( ( char * ) V_140 + sizeof( struct V_89 ) ) ;
V_10 -> V_146 = V_132 -> V_146 ;
V_10 -> V_147 = V_132 -> V_147 ;
V_10 -> V_148 = V_132 -> V_148 ;
V_10 -> V_98 = V_132 -> V_98 ;
V_142 = (struct V_141 * ) ( V_125 -> V_133 +
V_132 -> V_149 ) ;
V_10 -> V_99 = V_142 -> V_99 ;
V_143 = (struct V_126 * )
( V_125 -> V_133 +
V_142 -> V_143 ) ;
V_10 -> V_150 = V_143 -> V_102 ;
V_145 = (struct V_144 * ) ( ( char * ) V_143 +
sizeof( struct V_126 ) ) ;
V_10 -> V_145 = (struct V_151 * ) V_145 ;
for ( V_26 = 0 ; V_26 < V_143 -> V_102 ; V_26 ++ )
V_10 -> V_145 [ V_26 ] . V_152 =
( unsigned long ) V_125 -> V_133 + V_145 [ V_26 ] . V_153 ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_7 * V_13 ,
int V_154 )
{
int V_26 , V_155 ;
struct V_107 * V_108 = NULL ;
struct V_89 * V_87 ;
struct V_126 * V_156 ;
struct V_126 * V_157 ;
struct V_126 * V_158 ;
struct V_124 * V_125 =
& V_2 -> V_125 ;
for ( V_155 = 0 ; V_155 < V_154 ; V_155 ++ ) {
V_108 = F_28 ( V_125 -> V_104 ,
V_159 , V_108 ) ;
if ( ! V_108 )
break;
V_87 = (struct V_89 * ) ( V_125 -> V_133 +
V_108 -> V_121 ) ;
V_156 = (struct V_126 * )
( V_87 -> V_160 +
V_2 -> V_104 -> V_123 ) ;
V_13 [ V_155 ] . V_161 = V_156 -> V_102 ;
V_13 [ V_155 ] . V_162 = (struct V_163 * )
( ( ( char * ) V_156 ) +
sizeof( struct V_126 ) ) ;
V_157 = (struct V_126 * )
( V_87 -> V_157 +
V_2 -> V_104 -> V_123 ) ;
V_13 [ V_155 ] . V_164 = V_157 -> V_102 ;
V_13 [ V_155 ] . V_165 = (struct V_166 * )
( ( ( char * ) V_157 ) +
sizeof( struct V_126 ) ) ;
V_158 = (struct V_126 * )
( V_87 -> V_158 + V_2 -> V_104 -> V_123 ) ;
V_13 [ V_155 ] . V_167 = V_158 -> V_102 ;
V_13 [ V_155 ] . V_168 = (struct V_169 * )
( ( ( char * ) V_158 ) +
sizeof( struct V_126 ) ) ;
V_13 [ V_155 ] . V_16 = V_87 ;
if ( F_32 ( V_125 , V_87 ) )
goto V_24;
V_13 [ V_155 ] . V_10 =
F_2 ( sizeof( struct V_88 ) ,
V_22 ) ;
if ( ! V_13 [ V_155 ] . V_10 )
goto V_24;
F_35 ( V_125 , V_87 ,
V_13 [ V_155 ] . V_10 ) ;
}
return V_155 ;
V_24:
for ( V_26 = 0 ; V_26 < V_155 ; V_26 ++ )
F_3 ( V_13 [ V_26 ] . V_10 ) ;
return 0 ;
}
static int F_37 ( struct V_43 * V_44 , int V_170 )
{
int V_26 , V_3 ;
int V_171 = 0 ;
struct V_1 * V_2 = V_44 -> V_2 ;
for ( V_3 = 0 ; V_3 <= V_170 ; V_3 ++ ) {
if ( ! F_24 ( V_3 ,
( unsigned long * ) & V_44 -> V_95 -> V_172 ) )
continue;
for ( V_26 = 0 ; V_26 < V_2 -> V_173 ; V_26 ++ ) {
if ( ! F_24 ( V_3 , ( unsigned long * )
& V_2 -> V_13 [ V_26 ] . V_16 -> V_97 ) )
continue;
V_171 = 1 ;
if ( F_1 ( V_2 , V_3 , V_26 ) )
return - V_27 ;
}
}
if ( ! V_171 ) {
F_5 ( L_16 ) ;
return - V_27 ;
}
return 0 ;
}
static struct V_28 *
F_38 ( struct V_116 * V_104 ,
char * V_174 , struct V_28 * V_29 )
{
struct V_107 * V_108 ;
V_108 = F_28 ( (struct V_103 * )
V_104 -> V_123 , V_174 , NULL ) ;
if ( V_108 ) {
int V_175 ;
memcpy ( & V_29 -> V_31 , V_104 -> V_123 +
V_108 -> V_121 , sizeof( V_29 -> V_31 ) ) ;
V_175 = ( char * ) & V_29 -> V_32 - ( char * ) V_29 ;
V_29 -> V_32 = ( unsigned long ) V_104 -> V_123 +
V_108 -> V_121 + V_175 ;
return V_29 ;
}
return NULL ;
}
static void
F_39 ( struct V_124 * V_125 ,
struct V_176 * V_101 )
{
struct V_107 * V_108 ;
V_108 = F_28 ( V_125 -> V_104 ,
V_177 , NULL ) ;
if ( V_108 ) {
memmove ( & V_101 -> V_102 , V_125 -> V_133 +
V_108 -> V_121 , sizeof( unsigned int ) ) ;
V_101 -> V_63 = (struct V_62 * )
( V_125 -> V_133 + V_108 -> V_121 +
sizeof( unsigned int ) ) ;
}
}
static int F_40 ( struct V_1 * V_2 )
{
unsigned int V_36 , V_178 = V_2 -> V_178 ;
if ( ! ( V_178 & V_2 -> V_125 . V_104 -> V_179 ) ) {
F_5 ( L_17 ,
V_2 -> V_125 . V_104 -> V_179 , V_178 ) ;
return - V_27 ;
}
V_36 = V_2 -> V_180 & 0xff ;
if ( ( V_2 -> V_125 . V_104 -> V_181 < V_36 ) ||
( V_2 -> V_125 . V_104 -> V_182 > V_36 ) ) {
F_5 ( L_18 , V_36 ) ;
return - V_27 ;
}
return 0 ;
}
static int F_41 ( struct V_43 * V_44 ,
unsigned char V_3 , unsigned char V_183 ,
enum V_184 V_185 ,
unsigned short V_186 , unsigned int V_54 )
{
switch ( V_185 ) {
case V_187 :
case V_188 :
V_183 = 0 ;
case V_189 :
case V_190 :
return F_42 ( V_44 , V_3 , V_183 , V_185 ,
V_186 , V_54 ) ;
case V_191 :
case V_192 :
case V_193 :
case V_194 :
V_183 = 0 ;
case V_195 :
case V_196 :
case V_197 :
case V_198 :
return F_43 ( V_44 , V_3 , V_183 , V_185 ,
V_186 , V_54 ) ;
case V_199 :
case V_200 :
V_183 = 0 ;
case V_201 :
case V_202 :
return F_44 ( V_44 , V_3 , V_183 , V_185 ,
V_186 , V_54 ) ;
case V_203 :
return F_45 ( V_44 , V_3 , V_183 , V_186 , V_54 ) ;
default:
F_5 ( L_19 , V_185 ) ;
return - V_61 ;
}
return 0 ;
}
static int F_46 ( struct V_43 * V_44 ,
unsigned int V_3 ,
struct V_7 * V_204 )
{
unsigned int V_26 ;
unsigned char V_183 ;
struct V_166 * V_165 ;
if ( F_47 ( V_204 -> V_16 -> V_139 ) ==
V_205 )
V_183 = 0xff ;
else
V_183 = 0x55 ;
for ( V_26 = 0 ; V_26 < V_204 -> V_164 ; V_26 ++ ) {
unsigned int V_206 ;
V_165 = & V_204 -> V_165 [ V_26 ] ;
V_206 = V_165 -> V_54 ;
switch ( V_165 -> V_207 ) {
case V_208 :
F_41 ( V_44 , V_3 , V_183 ,
(enum V_184 )
V_165 -> V_185 ,
( unsigned short ) V_165 -> V_186 ,
V_206 ) ;
break;
case V_209 :
if ( ! ( ( 1 << V_165 -> V_210 ) & V_183 ) ) {
F_5 ( L_20 ,
V_165 -> V_210 ) ;
return - V_27 ;
}
F_41 ( V_44 , V_3 ,
( unsigned char )
( 1 << V_165 -> V_210 ) ,
(enum V_184 )
V_165 -> V_185 ,
( unsigned short ) V_165 -> V_186 ,
V_206 ) ;
break;
case V_211 :
F_5 ( L_21 ) ;
return - V_27 ;
case V_212 :
F_5 ( L_22 ) ;
return - V_27 ;
default:
break;
}
}
return 0 ;
}
static int F_48 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_2 ;
unsigned int V_213 , V_3 ;
if ( V_2 -> V_214 )
return 0 ;
if ( V_2 -> V_101 . V_102 ) {
if ( F_26 ( V_44 ) ) {
F_5 ( L_23 ) ;
return - V_27 ;
}
}
for ( V_3 = 0 ; V_3 < V_44 -> V_95 -> V_96 ; V_3 ++ ) {
for ( V_213 = 0 ; V_213 < V_2 -> V_6 [ V_3 ] . V_15 ; V_213 ++ ) {
if ( ! V_2 -> V_6 [ V_3 ] . V_14 [ V_213 ] . V_8 )
continue;
if ( F_46 ( V_44 , V_3 ,
V_2 -> V_6 [ V_3 ] .
V_14 [ V_213 ] . V_8 ) )
return - V_27 ;
}
}
V_2 -> V_214 = 1 ;
return 0 ;
}
static int F_49 ( struct V_43 * V_44 )
{
unsigned char V_3 , V_215 , V_213 ;
struct V_89 * V_90 ;
struct V_5 * V_6 ;
struct V_1 * V_2 = V_44 -> V_2 ;
for ( V_3 = 0 ; V_3 < V_44 -> V_95 -> V_96 ; V_3 ++ ) {
if ( ! F_24 ( V_3 ,
( unsigned long * ) & V_44 -> V_95 -> V_172 ) )
continue;
V_6 = & V_2 -> V_6 [ V_3 ] ;
for ( V_213 = 0 ; V_213 < F_50 (unsigned int, ae_data->slice_num,
ICP_QAT_UCLO_MAX_CTX) ; V_213 ++ ) {
if ( ! V_2 -> V_6 [ V_3 ] . V_14 [ V_213 ] . V_8 )
continue;
V_90 = V_6 -> V_14 [ V_213 ] . V_8 -> V_16 ;
if ( F_51 ( V_44 , V_3 ,
( char ) F_47
( V_90 -> V_139 ) ) ) {
F_5 ( L_24 ) ;
return - V_61 ;
}
V_215 = F_52 ( V_90 -> V_139 ) ;
if ( F_53 ( V_44 , V_3 , V_215 ) ) {
F_5 ( L_25 ) ;
return - V_61 ;
}
if ( F_54 ( V_44 , V_3 , V_216 ,
( char ) F_55
( V_90 -> V_139 ) ) ) {
F_5 ( L_26 ) ;
return - V_61 ;
}
if ( F_54 ( V_44 , V_3 , V_217 ,
( char ) F_56
( V_90 -> V_139 ) ) ) {
F_5 ( L_27 ) ;
return - V_61 ;
}
}
}
return 0 ;
}
static void F_57 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_2 ;
struct V_7 * V_87 ;
int V_218 ;
for ( V_218 = 0 ; V_218 < V_2 -> V_173 ; V_218 ++ ) {
V_87 = & V_2 -> V_13 [ V_218 ] ;
V_87 -> V_84 = V_87 -> V_10 -> V_98 +
V_87 -> V_10 -> V_99 ;
}
}
static int F_58 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_2 ;
unsigned int V_3 ;
V_2 -> V_219 = F_23 ( V_220 , sizeof( T_1 ) ,
V_22 ) ;
if ( ! V_2 -> V_219 )
return - V_23 ;
V_2 -> V_125 . V_133 = V_2 -> V_104 -> V_123 ;
V_2 -> V_125 . V_104 = (struct V_103 * )
V_2 -> V_104 -> V_123 ;
V_2 -> V_221 = 6 ;
V_2 -> V_178 = V_222 ;
V_2 -> V_180 = V_223 |
( V_224 & V_44 -> V_95 -> V_225 ) ;
if ( F_40 ( V_2 ) ) {
F_5 ( L_28 ) ;
return - V_27 ;
}
V_2 -> V_20 = V_93 ;
if ( ! V_2 -> V_104 -> V_123 ||
! F_38 ( V_2 -> V_104 , V_226 ,
& V_2 -> V_29 ) ) {
F_5 ( L_29 ) ;
goto V_24;
}
V_2 -> V_173 =
F_36 ( V_2 , V_2 -> V_13 ,
V_68 * V_205 ) ;
if ( ! V_2 -> V_173 )
goto V_24;
if ( F_37 ( V_44 , V_44 -> V_95 -> V_96 ) ) {
F_5 ( L_30 ) ;
goto V_227;
}
F_57 ( V_44 ) ;
F_39 ( & V_2 -> V_125 ,
& V_2 -> V_101 ) ;
if ( F_49 ( V_44 ) )
goto V_227;
return 0 ;
V_227:
for ( V_3 = 0 ; V_3 < V_2 -> V_173 ; V_3 ++ )
F_3 ( V_2 -> V_13 [ V_3 ] . V_10 ) ;
V_24:
F_3 ( V_2 -> V_219 ) ;
return - V_61 ;
}
void F_59 ( struct V_43 * V_44 ,
void * V_228 , int V_229 )
{
F_8 ( V_44 , 0 , V_228 , F_60 ( V_229 , 4 ) ) ;
}
int F_61 ( struct V_43 * V_44 ,
void * V_228 , int V_229 )
{
struct V_33 * V_230 ;
struct V_1 * V_231 ;
F_62 ( V_68 >=
( sizeof( V_44 -> V_95 -> V_172 ) * 8 ) ) ;
if ( ! V_44 || ! V_228 || V_229 < 24 )
return - V_27 ;
V_231 = F_2 ( sizeof( * V_231 ) , V_22 ) ;
if ( ! V_231 )
return - V_23 ;
V_231 -> V_232 = F_63 ( V_228 , V_229 , V_22 ) ;
if ( ! V_231 -> V_232 )
goto V_233;
V_230 = (struct V_33 * ) V_231 -> V_232 ;
if ( F_7 ( V_230 ) )
goto V_234;
V_231 -> V_104 = F_31 ( ( char * ) V_231 -> V_232 , V_230 ,
V_235 ) ;
if ( ! V_231 -> V_104 ) {
F_5 ( L_31 ) ;
goto V_234;
}
V_44 -> V_2 = V_231 ;
if ( F_58 ( V_44 ) )
goto V_236;
return 0 ;
V_236:
V_44 -> V_2 = NULL ;
F_3 ( V_231 -> V_104 ) ;
V_234:
F_3 ( V_231 -> V_232 ) ;
V_233:
F_3 ( V_231 ) ;
return - V_23 ;
}
void F_64 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_2 ;
unsigned int V_218 ;
if ( ! V_2 )
return;
F_3 ( V_2 -> V_219 ) ;
for ( V_218 = 0 ; V_218 < V_2 -> V_173 ; V_218 ++ )
F_3 ( V_2 -> V_13 [ V_218 ] . V_10 ) ;
for ( V_218 = 0 ; V_218 < V_44 -> V_95 -> V_96 ; V_218 ++ )
F_4 ( & V_2 -> V_6 [ V_218 ] ) ;
F_3 ( V_2 -> V_104 ) ;
F_3 ( V_2 -> V_232 ) ;
F_3 ( V_2 ) ;
V_44 -> V_2 = NULL ;
}
static void F_65 ( struct V_1 * V_2 ,
struct V_88 * V_25 ,
T_1 * V_237 , unsigned int V_238 ,
unsigned int V_239 , T_1 V_240 )
{
T_1 V_241 = 0 ;
unsigned int V_26 ;
if ( ! V_25 ) {
* V_237 = V_240 ;
return;
}
for ( V_26 = 0 ; V_26 < V_25 -> V_150 ; V_26 ++ ) {
if ( V_239 >= V_25 -> V_145 [ V_26 ] . V_242 &&
V_239 <= V_25 -> V_145 [ V_26 ] . V_242 +
V_25 -> V_145 [ V_26 ] . V_243 - 1 ) {
V_239 -= V_25 -> V_145 [ V_26 ] . V_242 ;
V_239 *= V_2 -> V_221 ;
memcpy ( & V_241 , ( void * ) ( ( ( unsigned long )
V_25 -> V_145 [ V_26 ] . V_152 ) + V_239 ) ,
V_2 -> V_221 ) ;
V_241 = V_241 & 0xbffffffffffull ;
}
}
* V_237 = V_241 ;
if ( * V_237 == V_244 )
* V_237 = V_240 ;
}
static void F_66 ( struct V_43 * V_44 ,
struct V_88
* V_25 , unsigned int V_3 )
{
unsigned int V_245 , V_246 , V_26 , V_243 , V_247 ;
struct V_1 * V_2 = V_44 -> V_2 ;
T_1 V_248 ;
memcpy ( & V_248 , V_2 -> V_13 [ 0 ] . V_16 -> V_94 ,
sizeof( T_1 ) ) ;
V_245 = V_25 -> V_98 ;
V_246 = 0 ;
V_243 = V_25 -> V_99 ;
while ( V_243 ) {
if ( V_243 < V_220 )
V_247 = V_243 ;
else
V_247 = V_220 ;
for ( V_26 = 0 ; V_26 < V_247 ; V_26 ++ )
F_65 ( V_2 , V_25 ,
& V_2 -> V_219 [ V_26 ] ,
V_245 + V_26 ,
V_246 + V_26 , V_248 ) ;
F_25 ( V_44 , ( unsigned char ) V_3 ,
V_245 , V_247 ,
V_2 -> V_219 ) ;
V_245 += V_247 ;
V_246 += V_247 ;
V_243 -= V_247 ;
}
}
static void F_67 ( struct V_43 * V_44 ,
struct V_89 * V_87 )
{
struct V_1 * V_2 = V_44 -> V_2 ;
unsigned int V_183 , V_213 ;
struct V_9 * V_10 ;
unsigned char V_3 ;
int V_210 ;
if ( F_47 ( V_87 -> V_139 ) == V_205 )
V_183 = 0xff ;
else
V_183 = 0x55 ;
for ( V_3 = 0 ; V_3 < V_44 -> V_95 -> V_96 ; V_3 ++ ) {
if ( ! F_24 ( V_3 , ( unsigned long * ) & V_87 -> V_97 ) )
continue;
for ( V_213 = 0 ; V_213 < V_2 -> V_6 [ V_3 ] . V_15 ; V_213 ++ ) {
if ( V_87 -> V_18 & V_2 -> V_6 [ V_3 ] .
V_14 [ V_213 ] . V_17 )
break;
}
if ( V_213 >= V_2 -> V_6 [ V_3 ] . V_15 )
continue;
V_10 = V_2 -> V_6 [ V_3 ] . V_14 [ V_213 ] . V_10 ;
if ( ! V_10 -> V_25 -> V_146 )
continue;
F_66 ( V_44 , V_10 -> V_25 , V_3 ) ;
V_10 = V_2 -> V_6 [ V_3 ] . V_14 [ V_213 ] . V_10 ;
for ( V_210 = 0 ; V_210 < V_205 ; V_210 ++ )
V_2 -> V_6 [ V_3 ] . V_14 [ V_213 ] . V_249 [ V_210 ] =
( V_183 & ( 1 << V_210 ) ) ? V_10 : NULL ;
F_68 ( V_44 , ( unsigned char ) V_3 ,
V_87 -> V_18 ) ;
F_69 ( V_44 , ( unsigned char ) V_3 , V_87 -> V_18 ,
V_87 -> V_250 ) ;
}
}
int F_70 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_2 ;
unsigned int V_26 ;
if ( F_48 ( V_44 ) )
return - V_27 ;
for ( V_26 = 0 ; V_26 < V_2 -> V_173 ; V_26 ++ ) {
if ( ! V_2 -> V_13 [ V_26 ] . V_16 )
return - V_27 ;
if ( F_22 ( V_44 , & V_2 -> V_13 [ V_26 ] ) )
return - V_27 ;
F_67 ( V_44 ,
V_2 -> V_13 [ V_26 ] . V_16 ) ;
}
return 0 ;
}
