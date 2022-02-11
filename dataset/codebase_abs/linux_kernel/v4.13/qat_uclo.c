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
return ( char * ) ( ( ( V_32 ) ( V_29 -> V_33 ) ) + V_30 ) ;
}
static int F_7 ( struct V_34 * V_35 )
{
int V_36 = V_35 -> V_37 & 0xff ;
int V_38 = V_35 -> V_39 & 0xff ;
if ( V_35 -> V_40 != V_41 ) {
F_5 ( L_2 , V_35 -> V_40 ) ;
return - V_27 ;
}
if ( V_38 != V_42 || V_36 != V_43 ) {
F_5 ( L_3 ,
V_36 , V_38 ) ;
return - V_27 ;
}
return 0 ;
}
static int F_8 ( struct V_44 * V_45 )
{
int V_36 = V_45 -> V_37 & 0xff ;
int V_38 = V_45 -> V_39 & 0xff ;
if ( V_45 -> V_40 != V_46 ) {
F_5 ( L_4 , V_45 -> V_40 ) ;
return - V_27 ;
}
if ( V_45 -> V_47 != 0 ) {
F_5 ( L_5 ) ;
return - V_27 ;
}
if ( V_45 -> V_48 <= 0x1 ) {
F_5 ( L_6 ) ;
return - V_27 ;
}
if ( V_36 != V_49 || V_38 != V_50 ) {
F_5 ( L_7 ,
V_36 , V_38 ) ;
return - V_27 ;
}
return 0 ;
}
static void F_9 ( struct V_51 * V_52 ,
unsigned int V_53 , unsigned int * V_54 ,
unsigned int V_55 )
{
unsigned int V_56 ;
unsigned char * V_57 = ( unsigned char * ) V_54 ;
while ( V_55 ) {
memcpy ( & V_56 , V_57 , 4 ) ;
F_10 ( V_52 , V_53 , V_56 ) ;
V_55 -= 4 ;
V_57 += 4 ;
V_53 += 4 ;
}
}
static void F_11 ( struct V_51 * V_52 ,
unsigned char V_3 , unsigned int V_53 ,
unsigned int * V_54 ,
unsigned int V_55 )
{
unsigned int V_56 ;
unsigned char * V_57 = ( unsigned char * ) V_54 ;
V_53 >>= 0x2 ;
while ( V_55 ) {
memcpy ( & V_56 , V_57 , 4 ) ;
F_12 ( V_52 , V_3 , V_53 ++ , 1 , & V_56 ) ;
V_55 -= 4 ;
V_57 += 4 ;
}
}
static void F_13 ( struct V_51 * V_52 ,
unsigned char V_3 ,
struct V_58
* V_59 )
{
struct V_58 * V_60 ;
if ( ! V_59 )
return;
V_60 = V_59 -> V_61 ;
while ( V_60 ) {
unsigned int V_53 , * V_62 , V_63 ;
V_3 = V_60 -> V_3 ;
V_53 = V_60 -> V_53 ;
V_62 = V_60 -> V_62 ;
V_63 = V_60 -> V_63 ;
F_11 ( V_52 , V_3 , V_53 , V_62 , V_63 ) ;
V_60 = V_60 -> V_61 ;
}
}
static void
F_14 ( struct V_51 * V_52 ,
struct V_58 * * V_64 )
{
struct V_58 * V_60 ;
V_60 = * V_64 ;
while ( V_60 ) {
struct V_58 * V_65 ;
V_65 = V_60 ;
V_60 = V_60 -> V_61 ;
F_3 ( V_65 ) ;
}
* V_64 = NULL ;
}
static int F_15 ( char * V_66 , unsigned int * V_67 )
{
char V_68 [ 16 ] = { 0 } ;
unsigned long V_3 = 0 ;
int V_26 ;
strncpy ( V_68 , V_66 , 15 ) ;
for ( V_26 = 0 ; V_26 < 16 ; V_26 ++ ) {
if ( ! isdigit ( V_68 [ V_26 ] ) ) {
V_68 [ V_26 ] = '\0' ;
break;
}
}
if ( ( F_16 ( V_68 , 10 , & V_3 ) ) )
return - V_69 ;
* V_67 = ( unsigned int ) V_3 ;
return 0 ;
}
static int F_17 ( struct V_51 * V_52 ,
struct V_70 * V_71 ,
unsigned int V_72 , unsigned int * V_3 )
{
struct V_1 * V_2 = V_52 -> V_2 ;
char * V_66 ;
if ( ( V_71 -> V_53 + V_71 -> V_55 ) > ( V_72 << 0x2 ) ) {
F_5 ( L_8 ) ;
return - V_27 ;
}
if ( V_71 -> V_73 != V_74 ) {
F_5 ( L_9 ) ;
return - V_27 ;
}
V_66 = F_6 ( & V_2 -> V_29 , V_71 -> V_75 ) ;
if ( ! V_66 ) {
F_5 ( L_10 ) ;
return - V_27 ;
}
if ( F_15 ( V_66 , V_3 ) ) {
F_5 ( L_11 ) ;
return - V_27 ;
}
if ( * V_3 >= V_76 ) {
F_5 ( L_12 , * V_3 ) ;
return - V_27 ;
}
return 0 ;
}
static int F_18 ( struct V_51
* V_52 , struct V_70
* V_71 , unsigned int V_3 ,
struct V_58
* * V_77 )
{
struct V_58 * V_78 , * V_79 ;
struct V_58 * V_80 , * V_81 ;
struct V_82 * V_83 ;
unsigned int V_26 , V_84 = 0 ;
V_83 =
(struct V_82 * ) ( ( V_32 ) V_71 +
sizeof( struct V_70 ) ) ;
V_78 = * V_77 ;
if ( ! V_78 ) {
V_78 = F_2 ( sizeof( * V_78 ) , V_22 ) ;
if ( ! V_78 )
return - V_23 ;
V_78 -> V_63 = 1 ;
* V_77 = V_78 ;
V_84 = 1 ;
}
V_81 = V_78 ;
while ( V_81 -> V_61 )
V_81 = V_81 -> V_61 ;
V_79 = V_81 ;
for ( V_26 = 0 ; V_26 < V_71 -> V_85 ; V_26 ++ ) {
V_80 = F_2 ( sizeof( * V_80 ) , V_22 ) ;
if ( ! V_80 )
goto V_24;
V_80 -> V_3 = V_3 ;
V_80 -> V_53 = V_71 -> V_53 + V_83 -> V_86 ;
V_80 -> V_62 = & V_83 -> V_62 ;
V_80 -> V_63 = 4 ;
V_80 -> V_61 = NULL ;
V_79 -> V_61 = V_80 ;
V_79 = V_80 ;
V_78 -> V_63 += F_19 () ;
V_83 ++ ;
}
return 0 ;
V_24:
while ( V_81 ) {
V_80 = V_81 -> V_61 ;
F_3 ( V_81 ) ;
V_81 = V_80 ;
}
if ( V_84 )
F_3 ( * V_77 ) ;
return - V_23 ;
}
static int F_20 ( struct V_51 * V_52 ,
struct V_70 * V_71 )
{
struct V_1 * V_2 = V_52 -> V_2 ;
unsigned int V_3 ;
if ( F_17 ( V_52 , V_71 ,
V_87 , & V_3 ) )
return - V_27 ;
if ( F_18 ( V_52 , V_71 , V_3 ,
& V_2 -> V_88 [ V_3 ] ) )
return - V_27 ;
return 0 ;
}
static int F_21 ( struct V_51 * V_52 ,
struct V_70 * V_71 )
{
struct V_1 * V_2 = V_52 -> V_2 ;
unsigned int V_3 , V_89 , V_90 , V_26 ;
V_89 = V_2 -> V_20 ;
if ( F_17 ( V_52 , V_71 , V_89 , & V_3 ) )
return - V_27 ;
if ( F_18 ( V_52 , V_71 , V_3 ,
& V_2 -> V_91 [ V_3 ] ) )
return - V_27 ;
V_90 = ( V_71 -> V_53 + V_71 -> V_55 ) >> 0x2 ;
for ( V_26 = 0 ; V_26 < V_2 -> V_6 [ V_3 ] . V_15 ; V_26 ++ ) {
if ( V_2 -> V_6 [ V_3 ] . V_14 [ V_26 ] .
V_8 -> V_92 < V_90 )
V_2 -> V_6 [ V_3 ] . V_14 [ V_26 ] .
V_8 -> V_92 = V_90 ;
}
return 0 ;
}
static int F_22 ( struct V_51 * V_52 ,
struct V_70 * V_71 )
{
switch ( V_71 -> V_21 ) {
case V_93 :
if ( F_20 ( V_52 , V_71 ) )
return - V_27 ;
break;
case V_94 :
if ( F_21 ( V_52 , V_71 ) )
return - V_27 ;
break;
default:
F_5 ( L_13 ,
V_71 -> V_21 ) ;
return - V_27 ;
}
return 0 ;
}
static int F_23 ( struct V_51 * V_52 ,
struct V_7 * V_95 )
{
unsigned int V_26 ;
struct V_96 * V_10 ;
struct V_97 * V_98 ;
unsigned char V_3 ;
unsigned int V_89 ;
unsigned int V_99 ;
struct V_1 * V_2 = V_52 -> V_2 ;
T_1 * V_100 ;
V_98 = V_95 -> V_16 ;
V_100 = F_24 ( V_101 , sizeof( T_1 ) ,
V_22 ) ;
if ( ! V_100 )
return - V_23 ;
for ( V_26 = 0 ; V_26 < V_101 ; V_26 ++ )
memcpy ( & V_100 [ V_26 ] , & V_98 -> V_102 ,
sizeof( T_1 ) ) ;
V_10 = V_95 -> V_10 ;
for ( V_3 = 0 ; V_3 < V_52 -> V_103 -> V_104 ; V_3 ++ ) {
if ( ! F_25 ( V_3 , ( unsigned long * ) & V_98 -> V_105 ) )
continue;
V_89 = V_2 -> V_6 [ V_3 ] . V_19 ;
V_99 = V_10 -> V_106 + V_10 -> V_107 ;
F_26 ( V_52 , ( unsigned char ) V_3 , 0 ,
V_10 -> V_106 , & V_100 [ 0 ] ) ;
F_26 ( V_52 , ( unsigned char ) V_3 , V_99 ,
V_89 - V_99 + 1 ,
& V_100 [ V_10 -> V_106 ] ) ;
}
F_3 ( V_100 ) ;
return 0 ;
}
static int F_27 ( struct V_51 * V_52 )
{
int V_26 , V_3 ;
struct V_1 * V_2 = V_52 -> V_2 ;
struct V_70 * V_108 = V_2 -> V_109 . V_71 ;
for ( V_26 = 0 ; V_26 < V_2 -> V_109 . V_110 ; V_26 ++ ) {
if ( V_108 -> V_55 ) {
if ( F_22 ( V_52 , V_108 ) )
return - V_27 ;
}
V_108 = (struct V_70 * ) ( ( V_32 ) (
( V_32 ) V_108 +
sizeof( struct V_70 ) ) +
( sizeof( struct V_82 ) *
V_108 -> V_85 ) ) ;
}
for ( V_3 = 0 ; V_3 < V_52 -> V_103 -> V_104 ; V_3 ++ ) {
if ( F_28 ( V_52 , V_3 ,
V_2 -> V_88 [ V_3 ] ) ) {
F_5 ( L_14 , V_3 ) ;
return - V_27 ;
}
F_14 ( V_52 ,
& V_2 -> V_88 [ V_3 ] ) ;
F_13 ( V_52 , V_3 ,
V_2 -> V_91 [ V_3 ] ) ;
F_14 ( V_52 ,
& V_2 ->
V_91 [ V_3 ] ) ;
}
return 0 ;
}
static void * F_29 ( struct V_111 * V_112 ,
char * V_113 , void * V_114 )
{
int V_26 ;
struct V_115 * V_116 =
(struct V_115 * )
( ( V_32 ) V_112 + sizeof( struct V_111 ) ) ;
for ( V_26 = 0 ; V_26 < V_112 -> V_48 ; V_26 ++ ) {
if ( ( V_114 < ( void * ) & V_116 [ V_26 ] ) &&
! strncmp ( V_116 [ V_26 ] . V_113 , V_113 ,
V_117 ) ) {
return & V_116 [ V_26 ] ;
}
}
return NULL ;
}
static unsigned int F_30 ( unsigned int V_118 , int V_119 )
{
int V_26 ;
unsigned int V_120 = 1 << 0xF ;
unsigned int V_121 = ( unsigned int ) ( ( V_118 >> 0x18 ) ^ V_119 ) ;
V_118 ^= V_121 << 0x8 ;
for ( V_26 = 0 ; V_26 < 0x8 ; V_26 ++ ) {
if ( V_118 & V_120 )
V_118 = ( V_118 << 1 ) ^ 0x1021 ;
else
V_118 <<= 1 ;
}
return V_118 & 0xFFFF ;
}
static unsigned int F_31 ( char * V_57 , int V_67 )
{
unsigned int V_122 = 0 ;
if ( V_57 )
while ( V_67 -- )
V_122 = F_30 ( V_122 , * V_57 ++ ) ;
return V_122 ;
}
static struct V_123 *
F_32 ( char * V_68 , struct V_34 * V_124 ,
char * V_113 )
{
struct V_125 * V_126 ;
struct V_123 * V_112 ;
char * V_127 ;
int V_26 ;
V_126 = (struct V_125 * )
( V_68 + sizeof( struct V_34 ) ) ;
for ( V_26 = 0 ; V_26 < V_124 -> V_48 ; V_26 ++ ) {
if ( ! strncmp ( V_126 -> V_113 , V_113 ,
V_117 ) ) {
V_127 = V_68 + V_126 -> V_128 ;
if ( V_126 -> V_129 != F_31 (
V_127 , V_126 -> V_63 ) )
break;
V_112 = F_2 ( sizeof( * V_112 ) , V_22 ) ;
if ( ! V_112 )
break;
V_112 -> V_130 = V_127 ;
V_112 -> V_129 = V_126 -> V_129 ;
V_112 -> V_63 = V_126 -> V_63 ;
return V_112 ;
}
V_126 ++ ;
}
return NULL ;
}
static unsigned int
F_33 ( struct V_131 * V_132 ,
struct V_97 * V_95 )
{
struct V_133 * V_134 , * V_135 , * V_136 ;
struct V_133 * V_137 ;
struct V_138 * V_139 ;
V_139 = (struct V_138 * )
( ( char * ) V_95 + sizeof( struct V_97 ) ) ;
V_134 = (struct V_133 * ) ( V_132 -> V_140 +
V_139 -> V_141 ) ;
V_135 = (struct V_133 * ) ( V_132 -> V_140 +
V_139 -> V_142 ) ;
V_136 = (struct V_133 * )
( V_132 -> V_140 +
V_139 -> V_143 ) ;
if ( V_134 -> V_110 || V_135 -> V_110 ||
V_136 -> V_110 ) {
F_5 ( L_15 ) ;
return - V_27 ;
}
V_137 = (struct V_133 * )
( V_132 -> V_140 +
V_139 -> V_144 ) ;
if ( V_137 -> V_110 ) {
F_5 ( L_16 ) ;
return - V_27 ;
}
if ( V_95 -> V_145 > 1 ) {
F_5 ( L_17 ) ;
return - V_27 ;
}
if ( F_34 ( V_95 -> V_146 ) ) {
F_5 ( L_18 ) ;
return - V_69 ;
}
if ( F_35 ( V_95 -> V_146 ) ) {
F_5 ( L_19 ) ;
return - V_69 ;
}
return 0 ;
}
static void F_36 ( struct V_131
* V_132 ,
struct V_97 * V_147 ,
struct V_96 * V_10 )
{
struct V_138 * V_139 ;
struct V_148 * V_149 ;
struct V_133 * V_150 ;
struct V_151 * V_152 ;
int V_26 ;
V_139 = (struct V_138 * )
( ( char * ) V_147 + sizeof( struct V_97 ) ) ;
V_10 -> V_153 = V_139 -> V_153 ;
V_10 -> V_154 = V_139 -> V_154 ;
V_10 -> V_155 = V_139 -> V_155 ;
V_10 -> V_106 = V_139 -> V_106 ;
V_149 = (struct V_148 * ) ( V_132 -> V_140 +
V_139 -> V_156 ) ;
V_10 -> V_107 = V_149 -> V_107 ;
V_150 = (struct V_133 * )
( V_132 -> V_140 +
V_149 -> V_150 ) ;
V_10 -> V_157 = V_150 -> V_110 ;
V_152 = (struct V_151 * ) ( ( char * ) V_150 +
sizeof( struct V_133 ) ) ;
V_10 -> V_152 = (struct V_158 * ) V_152 ;
for ( V_26 = 0 ; V_26 < V_150 -> V_110 ; V_26 ++ )
V_10 -> V_152 [ V_26 ] . V_159 =
( V_32 ) V_132 -> V_140 + V_152 [ V_26 ] . V_160 ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_7 * V_13 ,
int V_161 )
{
int V_26 , V_162 ;
struct V_115 * V_116 = NULL ;
struct V_97 * V_95 ;
struct V_133 * V_163 ;
struct V_133 * V_164 ;
struct V_133 * V_165 ;
struct V_131 * V_132 =
& V_2 -> V_132 ;
for ( V_162 = 0 ; V_162 < V_161 ; V_162 ++ ) {
V_116 = F_29 ( V_132 -> V_112 ,
V_166 , V_116 ) ;
if ( ! V_116 )
break;
V_95 = (struct V_97 * ) ( V_132 -> V_140 +
V_116 -> V_128 ) ;
V_163 = (struct V_133 * )
( V_95 -> V_167 +
V_2 -> V_112 -> V_130 ) ;
V_13 [ V_162 ] . V_168 = V_163 -> V_110 ;
V_13 [ V_162 ] . V_169 = (struct V_170 * )
( ( ( char * ) V_163 ) +
sizeof( struct V_133 ) ) ;
V_164 = (struct V_133 * )
( V_95 -> V_164 +
V_2 -> V_112 -> V_130 ) ;
V_13 [ V_162 ] . V_171 = V_164 -> V_110 ;
V_13 [ V_162 ] . V_172 = (struct V_173 * )
( ( ( char * ) V_164 ) +
sizeof( struct V_133 ) ) ;
V_165 = (struct V_133 * )
( V_95 -> V_165 + V_2 -> V_112 -> V_130 ) ;
V_13 [ V_162 ] . V_174 = V_165 -> V_110 ;
V_13 [ V_162 ] . V_175 = (struct V_176 * )
( ( ( char * ) V_165 ) +
sizeof( struct V_133 ) ) ;
V_13 [ V_162 ] . V_16 = V_95 ;
if ( F_33 ( V_132 , V_95 ) )
goto V_24;
V_13 [ V_162 ] . V_10 =
F_2 ( sizeof( struct V_96 ) ,
V_22 ) ;
if ( ! V_13 [ V_162 ] . V_10 )
goto V_24;
F_36 ( V_132 , V_95 ,
V_13 [ V_162 ] . V_10 ) ;
}
return V_162 ;
V_24:
for ( V_26 = 0 ; V_26 < V_162 ; V_26 ++ )
F_3 ( V_13 [ V_26 ] . V_10 ) ;
return 0 ;
}
static int F_38 ( struct V_51 * V_52 , int V_177 )
{
int V_26 , V_3 ;
int V_178 = 0 ;
struct V_1 * V_2 = V_52 -> V_2 ;
for ( V_3 = 0 ; V_3 < V_177 ; V_3 ++ ) {
if ( ! F_25 ( V_3 ,
( unsigned long * ) & V_52 -> V_103 -> V_179 ) )
continue;
for ( V_26 = 0 ; V_26 < V_2 -> V_180 ; V_26 ++ ) {
if ( ! F_25 ( V_3 , ( unsigned long * )
& V_2 -> V_13 [ V_26 ] . V_16 -> V_105 ) )
continue;
V_178 = 1 ;
if ( F_1 ( V_2 , V_3 , V_26 ) )
return - V_27 ;
}
}
if ( ! V_178 ) {
F_5 ( L_20 ) ;
return - V_27 ;
}
return 0 ;
}
static struct V_28 *
F_39 ( struct V_123 * V_112 ,
char * V_181 , struct V_28 * V_29 )
{
struct V_115 * V_116 ;
V_116 = F_29 ( (struct V_111 * )
V_112 -> V_130 , V_181 , NULL ) ;
if ( V_116 ) {
int V_182 ;
memcpy ( & V_29 -> V_31 , V_112 -> V_130 +
V_116 -> V_128 , sizeof( V_29 -> V_31 ) ) ;
V_182 = ( char * ) & V_29 -> V_33 - ( char * ) V_29 ;
V_29 -> V_33 = ( V_32 ) V_112 -> V_130 +
V_116 -> V_128 + V_182 ;
return V_29 ;
}
return NULL ;
}
static void
F_40 ( struct V_131 * V_132 ,
struct V_183 * V_109 )
{
struct V_115 * V_116 ;
V_116 = F_29 ( V_132 -> V_112 ,
V_184 , NULL ) ;
if ( V_116 ) {
memmove ( & V_109 -> V_110 , V_132 -> V_140 +
V_116 -> V_128 , sizeof( unsigned int ) ) ;
V_109 -> V_71 = (struct V_70 * )
( V_132 -> V_140 + V_116 -> V_128 +
sizeof( unsigned int ) ) ;
}
}
static unsigned int
F_41 ( struct V_51 * V_52 )
{
switch ( V_52 -> V_185 -> V_186 ) {
case V_187 :
return V_188 ;
case V_189 :
return V_190 ;
case V_191 :
return V_192 ;
default:
F_5 ( L_21 ,
V_52 -> V_185 -> V_186 ) ;
return 0 ;
}
}
static int F_42 ( struct V_1 * V_2 )
{
unsigned int V_37 , V_193 = V_2 -> V_193 ;
if ( ! ( V_193 & V_2 -> V_132 . V_112 -> V_194 ) ) {
F_5 ( L_22 ,
V_2 -> V_132 . V_112 -> V_194 ,
V_193 ) ;
return - V_27 ;
}
V_37 = V_2 -> V_195 & 0xff ;
if ( ( V_2 -> V_132 . V_112 -> V_196 < V_37 ) ||
( V_2 -> V_132 . V_112 -> V_197 > V_37 ) ) {
F_5 ( L_23 , V_37 ) ;
return - V_27 ;
}
return 0 ;
}
static int F_43 ( struct V_51 * V_52 ,
unsigned char V_3 , unsigned char V_198 ,
enum V_199 V_200 ,
unsigned short V_201 , unsigned int V_62 )
{
switch ( V_200 ) {
case V_202 :
case V_203 :
V_198 = 0 ;
case V_204 :
case V_205 :
return F_44 ( V_52 , V_3 , V_198 , V_200 ,
V_201 , V_62 ) ;
case V_206 :
case V_207 :
case V_208 :
case V_209 :
V_198 = 0 ;
case V_210 :
case V_211 :
case V_212 :
case V_213 :
return F_45 ( V_52 , V_3 , V_198 , V_200 ,
V_201 , V_62 ) ;
case V_214 :
case V_215 :
V_198 = 0 ;
case V_216 :
case V_217 :
return F_46 ( V_52 , V_3 , V_198 , V_200 ,
V_201 , V_62 ) ;
case V_218 :
return F_47 ( V_52 , V_3 , V_198 , V_201 , V_62 ) ;
default:
F_5 ( L_24 , V_200 ) ;
return - V_69 ;
}
return 0 ;
}
static int F_48 ( struct V_51 * V_52 ,
unsigned int V_3 ,
struct V_7 * V_219 )
{
unsigned int V_26 ;
unsigned char V_198 ;
struct V_173 * V_172 ;
if ( F_49 ( V_219 -> V_16 -> V_146 ) ==
V_220 )
V_198 = 0xff ;
else
V_198 = 0x55 ;
for ( V_26 = 0 ; V_26 < V_219 -> V_171 ; V_26 ++ ) {
unsigned int V_221 ;
V_172 = & V_219 -> V_172 [ V_26 ] ;
V_221 = V_172 -> V_62 ;
switch ( V_172 -> V_222 ) {
case V_223 :
F_43 ( V_52 , V_3 , V_198 ,
(enum V_199 )
V_172 -> V_200 ,
( unsigned short ) V_172 -> V_201 ,
V_221 ) ;
break;
case V_224 :
if ( ! ( ( 1 << V_172 -> V_225 ) & V_198 ) ) {
F_5 ( L_25 ,
V_172 -> V_225 ) ;
return - V_27 ;
}
F_43 ( V_52 , V_3 ,
( unsigned char )
( 1 << V_172 -> V_225 ) ,
(enum V_199 )
V_172 -> V_200 ,
( unsigned short ) V_172 -> V_201 ,
V_221 ) ;
break;
case V_226 :
F_5 ( L_26 ) ;
return - V_27 ;
case V_227 :
F_5 ( L_27 ) ;
return - V_27 ;
default:
break;
}
}
return 0 ;
}
static int F_50 ( struct V_51 * V_52 )
{
struct V_1 * V_2 = V_52 -> V_2 ;
unsigned int V_228 , V_3 ;
if ( V_2 -> V_229 )
return 0 ;
if ( V_2 -> V_109 . V_110 ) {
if ( F_27 ( V_52 ) ) {
F_5 ( L_28 ) ;
return - V_27 ;
}
}
for ( V_3 = 0 ; V_3 < V_52 -> V_103 -> V_104 ; V_3 ++ ) {
for ( V_228 = 0 ; V_228 < V_2 -> V_6 [ V_3 ] . V_15 ; V_228 ++ ) {
if ( ! V_2 -> V_6 [ V_3 ] . V_14 [ V_228 ] . V_8 )
continue;
if ( F_48 ( V_52 , V_3 ,
V_2 -> V_6 [ V_3 ] .
V_14 [ V_228 ] . V_8 ) )
return - V_27 ;
}
}
V_2 -> V_229 = 1 ;
return 0 ;
}
static int F_51 ( struct V_51 * V_52 )
{
unsigned char V_3 , V_230 , V_228 ;
struct V_97 * V_98 ;
struct V_5 * V_6 ;
struct V_1 * V_2 = V_52 -> V_2 ;
for ( V_3 = 0 ; V_3 < V_52 -> V_103 -> V_104 ; V_3 ++ ) {
if ( ! F_25 ( V_3 ,
( unsigned long * ) & V_52 -> V_103 -> V_179 ) )
continue;
V_6 = & V_2 -> V_6 [ V_3 ] ;
for ( V_228 = 0 ; V_228 < F_52 (unsigned int, ae_data->slice_num,
ICP_QAT_UCLO_MAX_CTX) ; V_228 ++ ) {
if ( ! V_2 -> V_6 [ V_3 ] . V_14 [ V_228 ] . V_8 )
continue;
V_98 = V_6 -> V_14 [ V_228 ] . V_8 -> V_16 ;
if ( F_53 ( V_52 , V_3 ,
( char ) F_49
( V_98 -> V_146 ) ) ) {
F_5 ( L_29 ) ;
return - V_69 ;
}
V_230 = F_54 ( V_98 -> V_146 ) ;
if ( F_55 ( V_52 , V_3 , V_230 ) ) {
F_5 ( L_30 ) ;
return - V_69 ;
}
if ( F_56 ( V_52 , V_3 , V_231 ,
( char ) F_57
( V_98 -> V_146 ) ) ) {
F_5 ( L_31 ) ;
return - V_69 ;
}
if ( F_56 ( V_52 , V_3 , V_232 ,
( char ) F_58
( V_98 -> V_146 ) ) ) {
F_5 ( L_32 ) ;
return - V_69 ;
}
}
}
return 0 ;
}
static void F_59 ( struct V_51 * V_52 )
{
struct V_1 * V_2 = V_52 -> V_2 ;
struct V_7 * V_95 ;
int V_233 ;
for ( V_233 = 0 ; V_233 < V_2 -> V_180 ; V_233 ++ ) {
V_95 = & V_2 -> V_13 [ V_233 ] ;
V_95 -> V_92 = V_95 -> V_10 -> V_106 +
V_95 -> V_10 -> V_107 ;
}
}
static int F_60 ( struct V_51 * V_52 )
{
struct V_1 * V_2 = V_52 -> V_2 ;
unsigned int V_3 ;
V_2 -> V_132 . V_140 = V_2 -> V_112 -> V_130 ;
V_2 -> V_132 . V_112 = (struct V_111 * )
V_2 -> V_112 -> V_130 ;
V_2 -> V_234 = 6 ;
V_2 -> V_193 = F_41 ( V_52 ) ;
V_2 -> V_195 = V_235 |
( V_236 & V_52 -> V_103 -> V_237 ) ;
if ( F_42 ( V_2 ) ) {
F_5 ( L_33 ) ;
return - V_27 ;
}
V_2 -> V_238 = F_24 ( V_239 , sizeof( T_1 ) ,
V_22 ) ;
if ( ! V_2 -> V_238 )
return - V_23 ;
V_2 -> V_20 = V_101 ;
if ( ! V_2 -> V_112 -> V_130 ||
! F_39 ( V_2 -> V_112 , V_240 ,
& V_2 -> V_29 ) ) {
F_5 ( L_34 ) ;
goto V_24;
}
V_2 -> V_180 =
F_37 ( V_2 , V_2 -> V_13 ,
V_76 * V_220 ) ;
if ( ! V_2 -> V_180 )
goto V_24;
if ( F_38 ( V_52 , V_52 -> V_103 -> V_104 ) ) {
F_5 ( L_35 ) ;
goto V_241;
}
F_59 ( V_52 ) ;
F_40 ( & V_2 -> V_132 ,
& V_2 -> V_109 ) ;
if ( F_51 ( V_52 ) )
goto V_241;
return 0 ;
V_241:
for ( V_3 = 0 ; V_3 < V_2 -> V_180 ; V_3 ++ )
F_3 ( V_2 -> V_13 [ V_3 ] . V_10 ) ;
V_24:
F_3 ( V_2 -> V_238 ) ;
return - V_69 ;
}
static int F_61 ( struct V_51 * V_52 ,
struct V_44 * V_242 ,
int V_243 )
{
unsigned int V_244 = 0 ;
unsigned int V_245 = 0 ;
struct V_246 * V_247 = V_52 -> V_248 ;
V_247 -> V_40 = V_46 ;
V_247 -> V_249 = ( char * ) V_242 ;
V_247 -> V_243 = V_243 ;
V_245 = V_243 - F_62 ( struct V_44 ,
V_39 ) ;
V_244 = F_31 ( ( char * ) & V_242 -> V_39 ,
V_245 ) ;
if ( V_244 != V_242 -> V_244 ) {
F_5 ( L_36 ) ;
return - V_27 ;
}
V_247 -> V_244 = V_242 -> V_244 ;
V_247 -> V_39 = V_242 -> V_39 ;
V_247 -> V_37 = V_242 -> V_37 ;
V_247 -> V_47 = V_242 -> V_47 ;
return 0 ;
}
static void F_63 ( struct V_246 * V_247 ,
struct V_250 * V_251 ,
struct V_252 * V_253 )
{
struct V_254 * V_146 ;
struct V_255 * V_256 ;
V_251 -> V_257 = ( V_247 -> V_249 +
V_253 -> V_128 +
sizeof( * V_256 ) ) ;
V_251 -> V_258 = ( (struct V_255 * ) ( V_32 )
( V_247 -> V_249 +
V_253 -> V_128 ) ) -> V_259 ;
V_251 -> V_260 = V_251 -> V_257 ;
V_251 -> V_261 = ( V_251 -> V_260 +
sizeof( struct V_262 ) ) ;
V_251 -> V_263 = V_251 -> V_261 +
V_264 +
V_265 ;
V_251 -> V_266 = V_251 -> V_263 +
V_267 ;
V_146 = (struct V_254 * ) ( V_251 -> V_266 ) ;
V_251 -> V_179 = V_146 -> V_179 ;
V_251 -> V_268 = ( unsigned long ) & V_146 -> V_268 ;
V_251 -> V_269 = ( unsigned long ) & V_146 -> V_269 ;
V_251 -> V_47 = V_146 -> V_47 ;
}
static void
F_64 ( struct V_246 * V_247 ,
struct V_252 * V_253 )
{
char * * V_270 = ( char * * ) & V_247 -> V_270 ;
unsigned int * V_271 = & V_247 -> V_271 ;
struct V_272 * V_273 ;
* V_271 = * ( unsigned int * ) ( V_32 )
( V_253 -> V_128 + V_247 -> V_249 ) ;
* V_270 = ( char * ) ( V_32 )
( V_247 -> V_249 + V_253 -> V_128 +
sizeof( V_273 -> V_274 ) ) ;
}
static int F_65 ( struct V_51 * V_52 ,
struct V_250 * V_275 )
{
struct V_254 * V_276 = NULL ;
unsigned int V_195 , V_37 , V_193 ;
V_193 = F_41 ( V_52 ) ;
V_276 = (struct V_254 * ) V_275 -> V_266 ;
V_195 = V_235 |
( V_236 & V_52 -> V_103 -> V_237 ) ;
if ( V_276 -> V_277 != V_193 ) {
F_5 ( L_37 ,
V_276 -> V_277 ) ;
return - V_27 ;
}
V_37 = V_195 & 0xff ;
if ( ( V_37 > V_276 -> V_278 ) ||
( V_37 < V_276 -> V_279 ) ) {
F_5 ( L_38 , V_37 ) ;
return - V_27 ;
}
return 0 ;
}
static void F_66 ( struct V_51 * V_52 )
{
struct V_246 * V_248 = V_52 -> V_248 ;
F_3 ( V_248 -> V_280 . V_281 ) ;
V_248 -> V_280 . V_281 = NULL ;
F_3 ( V_52 -> V_248 ) ;
V_52 -> V_248 = NULL ;
}
static void F_67 ( struct V_250 * V_251 ,
unsigned int V_282 , unsigned int V_283 )
{
struct V_250 V_284 ;
if ( V_282 != V_283 - 1 ) {
memcpy ( & V_284 , & V_251 [ V_283 - 1 ] ,
sizeof( * V_251 ) ) ;
memcpy ( & V_251 [ V_283 - 1 ] , & V_251 [ V_282 ] ,
sizeof( * V_251 ) ) ;
memcpy ( & V_251 [ V_282 ] , & V_284 ,
sizeof( * V_251 ) ) ;
}
}
static int F_68 ( struct V_51 * V_52 ,
struct V_44 * V_242 ,
int V_243 )
{
struct V_246 * V_247 = V_52 -> V_248 ;
struct V_252 * V_253 = NULL ;
struct V_250 * V_251 = NULL ;
int V_285 = 0 , V_286 = V_76 ;
unsigned int V_26 = 0 ;
struct V_250 V_284 ;
if ( ! V_242 || ( V_243 == 0 ) ) {
F_5 ( L_39 ) ;
return - V_27 ;
}
if ( F_8 ( V_242 ) )
return - V_27 ;
V_285 = F_61 ( V_52 , V_242 , V_243 ) ;
if ( V_285 )
return V_285 ;
V_253 = (struct V_252 * )
( ( V_32 ) V_242 + sizeof( * V_242 ) ) ;
F_64 ( V_247 , V_253 ) ;
V_247 -> V_280 . V_283 = V_242 -> V_48 - 1 ;
if ( V_247 -> V_280 . V_283 != 0 ) {
V_251 = F_2 ( V_247 -> V_280 . V_283 *
sizeof( V_284 ) , V_22 ) ;
if ( ! V_251 )
return - V_23 ;
V_247 -> V_280 . V_281 = V_251 ;
}
for ( V_26 = 0 ; V_26 < V_247 -> V_280 . V_283 ; V_26 ++ ) {
F_63 ( V_52 -> V_248 , & V_251 [ V_26 ] ,
& V_253 [ 1 + V_26 ] ) ;
V_285 = F_65 ( V_52 ,
& V_251 [ V_26 ] ) ;
if ( V_285 )
return V_285 ;
if ( ( V_251 [ V_26 ] . V_179 & 0x1 ) != 0 )
V_286 = V_26 ;
}
F_67 ( V_251 , V_286 ,
V_247 -> V_280 . V_283 ) ;
return 0 ;
}
static int F_69 ( struct V_51 * V_52 ,
struct V_287 * V_288 )
{
unsigned int V_289 , V_290 = 0 ;
T_2 V_291 ;
V_291 = F_70 ( V_288 -> V_292 , V_288 -> V_293 )
- sizeof( struct V_294 ) ;
F_71 ( V_52 , V_295 , ( V_291 >> V_296 ) ) ;
F_71 ( V_52 , V_297 , V_291 ) ;
F_71 ( V_52 , V_298 , V_299 ) ;
do {
F_72 ( V_300 ) ;
V_289 = F_73 ( V_52 , V_301 ) ;
if ( ( V_289 & V_302 ) == V_303 )
goto V_304;
if ( ( ( V_289 >> V_305 ) & 0x1 ) )
if ( ( V_289 & V_302 ) == V_306 )
return 0 ;
} while ( V_290 ++ < V_307 );
V_304:
F_5 ( L_40 ,
V_289 & V_302 , V_290 ) ;
return - V_27 ;
}
static int F_74 ( struct V_51 * V_52 ,
struct V_308 * V_309 ,
unsigned int V_63 )
{
void * V_310 ;
T_3 V_57 ;
V_310 = F_75 ( & V_52 -> V_185 -> V_311 ,
V_63 , & V_57 , V_22 ) ;
if ( ! V_310 )
return - V_23 ;
V_309 -> V_312 = V_310 ;
V_309 -> V_313 = V_57 ;
V_309 -> V_314 = V_63 ;
return 0 ;
}
static void F_76 ( struct V_51 * V_52 ,
struct V_308 * V_309 )
{
F_77 ( & V_52 -> V_185 -> V_311 ,
( V_315 ) ( V_309 -> V_314 ) ,
( V_309 -> V_312 ) ,
V_309 -> V_313 ) ;
memset ( V_309 , 0 , sizeof( * V_309 ) ) ;
}
static void F_78 ( struct V_51 * V_52 ,
struct V_287 * * V_288 )
{
struct V_308 V_309 ;
V_309 . V_312 = * V_288 ;
V_309 . V_313 = ( (struct V_294 * )
( * V_288 ) ) -> V_316 ;
V_309 . V_314 = ( (struct V_294 * )
( * V_288 ) ) -> V_317 ;
F_76 ( V_52 , & V_309 ) ;
}
static int F_79 ( struct V_51 * V_52 ,
char * V_95 , unsigned int V_63 ,
struct V_287 * * V_288 )
{
struct V_262 * V_318 = (struct V_262 * ) V_95 ;
struct V_287 * V_319 ;
struct V_294 * V_320 ;
T_2 V_321 , V_291 , V_322 ;
unsigned int V_323 , V_324 = sizeof( * V_320 ) ;
struct V_308 V_325 ;
if ( V_63 > ( V_326 + V_327 ) ) {
F_5 ( L_41 , V_63 ) ;
return - V_27 ;
}
V_323 = ( V_318 -> V_47 == V_328 ) ?
V_329 + V_324 :
V_63 + V_330 + V_324 ;
if ( F_74 ( V_52 , & V_325 , V_323 ) ) {
F_5 ( L_42 ) ;
return - V_23 ;
}
V_320 = V_325 . V_312 ;
V_320 -> V_317 = V_325 . V_314 ;
V_320 -> V_316 = V_325 . V_313 ;
V_322 = ( V_32 ) V_325 . V_312 + V_324 ;
V_291 = V_325 . V_313 + V_324 ;
V_319 = V_325 . V_312 ;
V_319 -> V_292 = ( unsigned int ) ( V_291 >> V_296 ) ;
V_319 -> V_293 = ( unsigned int ) V_291 ;
V_321 = V_322 ;
memcpy ( ( void * ) ( V_32 ) V_321 , V_95 , sizeof( * V_318 ) ) ;
V_291 = F_70 ( V_319 -> V_292 , V_319 -> V_293 ) +
sizeof( * V_318 ) ;
V_321 = V_321 + sizeof( * V_318 ) ;
V_319 -> V_331 = ( unsigned int ) ( V_291 >> V_296 ) ;
V_319 -> V_332 = ( unsigned int ) V_291 ;
memcpy ( ( void * ) ( V_32 ) V_321 ,
( void * ) ( V_95 + sizeof( * V_318 ) ) ,
V_264 ) ;
memset ( ( void * ) ( V_32 ) ( V_321 + V_264 ) ,
0 , V_330 ) ;
memcpy ( ( void * ) ( V_32 ) ( V_321 + V_264 +
V_330 ) ,
( void * ) ( V_95 + sizeof( * V_318 ) +
V_264 ) ,
sizeof( unsigned int ) ) ;
V_291 = F_70 ( V_319 -> V_331 ,
V_319 -> V_332 ) +
V_333 ;
V_321 = V_321 + V_333 ;
V_319 -> V_334 = ( unsigned int ) ( V_291 >> V_296 ) ;
V_319 -> V_335 = ( unsigned int ) V_291 ;
memcpy ( ( void * ) ( V_32 ) V_321 ,
( void * ) ( V_95 + sizeof( * V_318 ) +
V_264 +
V_265 ) ,
V_267 ) ;
V_291 = F_70 ( V_319 -> V_334 ,
V_319 -> V_335 ) +
V_267 ;
V_321 += V_267 ;
V_319 -> V_336 = ( unsigned int ) ( V_291 >> V_296 ) ;
V_319 -> V_337 = ( unsigned int ) V_291 ;
V_319 -> V_338 = V_63 - V_326 ;
memcpy ( ( void * ) ( V_32 ) V_321 ,
( void * ) ( V_95 + V_326 ) ,
V_319 -> V_338 ) ;
V_321 = V_322 ;
if ( ( (struct V_262 * ) ( V_32 ) V_321 ) -> V_47 ==
V_328 ) {
V_319 -> V_339 = V_319 -> V_336 ;
V_319 -> V_340 = V_319 -> V_337 ;
V_291 = F_70 ( V_319 -> V_339 ,
V_319 -> V_340 ) +
sizeof( struct V_254 ) ;
V_319 -> V_341 = ( unsigned int )
( V_291 >> V_296 ) ;
V_319 -> V_342 = ( unsigned int ) V_291 ;
V_291 += V_343 ;
V_319 -> V_344 = ( unsigned int )
( V_291 >> V_296 ) ;
V_319 -> V_345 = ( unsigned int ) V_291 ;
} else {
V_319 -> V_344 = V_319 -> V_336 ;
V_319 -> V_345 = V_319 -> V_337 ;
}
* V_288 = V_319 ;
return 0 ;
}
static int F_80 ( struct V_51 * V_52 ,
struct V_287 * V_288 )
{
unsigned int V_26 ;
unsigned int V_289 ;
struct V_254 * V_321 ;
unsigned int V_346 = V_347 ;
V_321 = ( void * ) ( ( V_32 ) V_288 +
sizeof( struct V_294 ) +
sizeof( struct V_262 ) +
V_333 +
V_267 ) ;
for ( V_26 = 0 ; V_26 < V_52 -> V_103 -> V_104 ; V_26 ++ ) {
int V_290 = 0 ;
if ( ! ( ( V_321 -> V_179 >> V_26 ) & 0x1 ) )
continue;
if ( F_81 ( V_52 , V_26 ) ) {
F_5 ( L_43 , V_26 ) ;
return - V_27 ;
}
F_71 ( V_52 , V_298 ,
( V_348 | ( V_26 << V_349 ) ) ) ;
do {
F_72 ( V_300 ) ;
V_289 = F_73 ( V_52 , V_301 ) ;
if ( ( ( V_289 & V_302 ) ==
V_350 ) &&
( ( V_289 >> V_346 ) & ( 1 << V_26 ) ) )
break;
} while ( V_290 ++ < V_307 );
if ( V_290 > V_307 ) {
F_5 ( L_44 , V_290 ) ;
return - V_27 ;
}
}
return 0 ;
}
static int F_82 ( struct V_51 * V_52 ,
void * V_351 , int V_352 )
{
struct V_246 * V_247 ;
V_247 = F_2 ( sizeof( * V_247 ) , V_22 ) ;
if ( ! V_247 )
return - V_23 ;
V_52 -> V_248 = V_247 ;
if ( F_68 ( V_52 , V_351 , V_352 ) ) {
F_66 ( V_52 ) ;
F_5 ( L_45 ) ;
return - V_27 ;
}
return 0 ;
}
int F_83 ( struct V_51 * V_52 ,
void * V_351 , int V_352 )
{
struct V_287 * V_288 = NULL ;
int V_353 = 0 ;
if ( V_52 -> V_354 ) {
if ( ! F_79 ( V_52 , V_351 , V_352 , & V_288 ) )
V_353 = F_69 ( V_52 , V_288 ) ;
F_78 ( V_52 , & V_288 ) ;
} else {
if ( V_52 -> V_185 -> V_186 == V_191 ) {
F_5 ( L_46 ) ;
return - V_27 ;
}
F_9 ( V_52 , 0 , V_351 , V_352 ) ;
}
return V_353 ;
}
static int F_84 ( struct V_51 * V_52 ,
void * V_351 , int V_352 )
{
struct V_34 * V_355 ;
struct V_1 * V_356 ;
V_356 = F_2 ( sizeof( * V_356 ) , V_22 ) ;
if ( ! V_356 )
return - V_23 ;
V_356 -> V_357 = F_85 ( V_351 , V_352 , V_22 ) ;
if ( ! V_356 -> V_357 )
goto V_358;
V_355 = (struct V_34 * ) V_356 -> V_357 ;
if ( F_7 ( V_355 ) )
goto V_359;
V_356 -> V_112 = F_32 ( ( char * ) V_356 -> V_357 , V_355 ,
V_360 ) ;
if ( ! V_356 -> V_112 ) {
F_5 ( L_47 ) ;
goto V_359;
}
V_52 -> V_2 = V_356 ;
if ( F_60 ( V_52 ) )
goto V_361;
return 0 ;
V_361:
V_52 -> V_2 = NULL ;
F_3 ( V_356 -> V_112 ) ;
V_359:
F_3 ( V_356 -> V_357 ) ;
V_358:
F_3 ( V_356 ) ;
return - V_23 ;
}
int F_86 ( struct V_51 * V_52 ,
void * V_351 , int V_352 )
{
F_87 ( V_76 >=
( sizeof( V_52 -> V_103 -> V_179 ) * 8 ) ) ;
if ( ! V_52 || ! V_351 || V_352 < 24 )
return - V_27 ;
return ( V_52 -> V_354 ) ?
F_82 ( V_52 , V_351 , V_352 ) :
F_84 ( V_52 , V_351 , V_352 ) ;
}
void F_88 ( struct V_51 * V_52 )
{
struct V_1 * V_2 = V_52 -> V_2 ;
unsigned int V_233 ;
if ( V_52 -> V_248 )
F_66 ( V_52 ) ;
if ( ! V_2 )
return;
F_3 ( V_2 -> V_238 ) ;
for ( V_233 = 0 ; V_233 < V_2 -> V_180 ; V_233 ++ )
F_3 ( V_2 -> V_13 [ V_233 ] . V_10 ) ;
for ( V_233 = 0 ; V_233 < V_52 -> V_103 -> V_104 ; V_233 ++ )
F_4 ( & V_2 -> V_6 [ V_233 ] ) ;
F_3 ( V_2 -> V_112 ) ;
F_3 ( V_2 -> V_357 ) ;
F_3 ( V_2 ) ;
V_52 -> V_2 = NULL ;
}
static void F_89 ( struct V_1 * V_2 ,
struct V_96 * V_25 ,
T_1 * V_362 , unsigned int V_363 ,
unsigned int V_364 , T_1 V_365 )
{
T_1 V_366 = 0 ;
unsigned int V_26 ;
if ( ! V_25 ) {
* V_362 = V_365 ;
return;
}
for ( V_26 = 0 ; V_26 < V_25 -> V_157 ; V_26 ++ ) {
if ( V_364 >= V_25 -> V_152 [ V_26 ] . V_367 &&
V_364 <= V_25 -> V_152 [ V_26 ] . V_367 +
V_25 -> V_152 [ V_26 ] . V_368 - 1 ) {
V_364 -= V_25 -> V_152 [ V_26 ] . V_367 ;
V_364 *= V_2 -> V_234 ;
memcpy ( & V_366 , ( void * ) ( ( ( V_32 )
V_25 -> V_152 [ V_26 ] . V_159 ) + V_364 ) ,
V_2 -> V_234 ) ;
V_366 = V_366 & 0xbffffffffffull ;
}
}
* V_362 = V_366 ;
if ( * V_362 == V_369 )
* V_362 = V_365 ;
}
static void F_90 ( struct V_51 * V_52 ,
struct V_96
* V_25 , unsigned int V_3 )
{
unsigned int V_370 , V_371 , V_26 , V_368 , V_372 ;
struct V_1 * V_2 = V_52 -> V_2 ;
T_1 V_373 ;
memcpy ( & V_373 , V_2 -> V_13 [ 0 ] . V_16 -> V_102 ,
sizeof( T_1 ) ) ;
V_370 = V_25 -> V_106 ;
V_371 = 0 ;
V_368 = V_25 -> V_107 ;
while ( V_368 ) {
if ( V_368 < V_239 )
V_372 = V_368 ;
else
V_372 = V_239 ;
for ( V_26 = 0 ; V_26 < V_372 ; V_26 ++ )
F_89 ( V_2 , V_25 ,
& V_2 -> V_238 [ V_26 ] ,
V_370 + V_26 ,
V_371 + V_26 , V_373 ) ;
F_26 ( V_52 , ( unsigned char ) V_3 ,
V_370 , V_372 ,
V_2 -> V_238 ) ;
V_370 += V_372 ;
V_371 += V_372 ;
V_368 -= V_372 ;
}
}
static void F_91 ( struct V_51 * V_52 ,
struct V_97 * V_95 )
{
struct V_1 * V_2 = V_52 -> V_2 ;
unsigned int V_198 , V_228 ;
struct V_9 * V_10 ;
unsigned char V_3 ;
int V_225 ;
if ( F_49 ( V_95 -> V_146 ) == V_220 )
V_198 = 0xff ;
else
V_198 = 0x55 ;
for ( V_3 = 0 ; V_3 < V_52 -> V_103 -> V_104 ; V_3 ++ ) {
if ( ! F_25 ( V_3 , ( unsigned long * ) & V_95 -> V_105 ) )
continue;
for ( V_228 = 0 ; V_228 < V_2 -> V_6 [ V_3 ] . V_15 ; V_228 ++ ) {
if ( V_95 -> V_18 & V_2 -> V_6 [ V_3 ] .
V_14 [ V_228 ] . V_17 )
break;
}
if ( V_228 >= V_2 -> V_6 [ V_3 ] . V_15 )
continue;
V_10 = V_2 -> V_6 [ V_3 ] . V_14 [ V_228 ] . V_10 ;
if ( ! V_10 -> V_25 -> V_153 )
continue;
F_90 ( V_52 , V_10 -> V_25 , V_3 ) ;
V_10 = V_2 -> V_6 [ V_3 ] . V_14 [ V_228 ] . V_10 ;
for ( V_225 = 0 ; V_225 < V_220 ; V_225 ++ )
V_2 -> V_6 [ V_3 ] . V_14 [ V_228 ] . V_374 [ V_225 ] =
( V_198 & ( 1 << V_225 ) ) ? V_10 : NULL ;
F_92 ( V_52 , ( unsigned char ) V_3 ,
V_95 -> V_18 ) ;
F_93 ( V_52 , ( unsigned char ) V_3 , V_95 -> V_18 ,
V_95 -> V_375 ) ;
}
}
static int F_94 ( struct V_51 * V_52 )
{
unsigned int V_26 ;
struct V_287 * V_288 = NULL ;
struct V_246 * V_248 = V_52 -> V_248 ;
struct V_250 * V_281 = V_248 -> V_280 . V_281 ;
for ( V_26 = 0 ; V_26 < V_248 -> V_280 . V_283 ; V_26 ++ ) {
if ( F_79 ( V_52 ,
( char * ) V_281 [ V_26 ] . V_257 ,
( unsigned int )
( V_281 [ V_26 ] . V_258 ) ,
& V_288 ) )
goto V_376;
if ( F_69 ( V_52 , V_288 ) )
goto V_376;
if ( F_80 ( V_52 , V_288 ) )
goto V_376;
F_78 ( V_52 , & V_288 ) ;
}
return 0 ;
V_376:
F_78 ( V_52 , & V_288 ) ;
return - V_27 ;
}
static int F_95 ( struct V_51 * V_52 )
{
struct V_1 * V_2 = V_52 -> V_2 ;
unsigned int V_26 ;
if ( F_50 ( V_52 ) )
return - V_27 ;
for ( V_26 = 0 ; V_26 < V_2 -> V_180 ; V_26 ++ ) {
if ( ! V_2 -> V_13 [ V_26 ] . V_16 )
return - V_27 ;
if ( F_23 ( V_52 , & V_2 -> V_13 [ V_26 ] ) )
return - V_27 ;
F_91 ( V_52 ,
V_2 -> V_13 [ V_26 ] . V_16 ) ;
}
return 0 ;
}
int F_96 ( struct V_51 * V_52 )
{
return ( V_52 -> V_354 ) ? F_94 ( V_52 ) :
F_95 ( V_52 ) ;
}
