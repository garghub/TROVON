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
unsigned int V_26 ;
struct V_74 * V_75 ;
V_75 =
(struct V_74 * ) ( ( unsigned long ) V_63 +
sizeof( struct V_62 ) ) ;
switch ( V_63 -> V_21 ) {
case V_85 :
if ( ( V_63 -> V_45 + V_63 -> V_47 ) >
V_86 ) {
F_5 ( L_9 ) ;
return - V_27 ;
}
for ( V_26 = 0 ; V_26 < V_63 -> V_77 ; V_26 ++ ) {
F_8 ( V_44 ,
V_63 -> V_45 +
V_75 -> V_78 ,
& V_75 -> V_54 , 4 ) ;
V_75 ++ ;
}
break;
case V_87 :
if ( F_19 ( V_44 , V_63 ) )
return - V_27 ;
break;
case V_88 :
if ( F_20 ( V_44 , V_63 ) )
return - V_27 ;
break;
default:
F_5 ( L_10 ,
V_63 -> V_21 ) ;
return - V_27 ;
}
return 0 ;
}
static int F_22 ( struct V_43 * V_44 ,
struct V_7 * V_89 )
{
unsigned int V_26 ;
struct V_90 * V_10 ;
struct V_91 * V_92 ;
unsigned char V_3 ;
unsigned int V_81 ;
unsigned int V_93 ;
struct V_1 * V_2 = V_44 -> V_2 ;
T_1 * V_94 ;
V_92 = V_89 -> V_16 ;
V_94 = F_23 ( V_95 , sizeof( T_1 ) ,
V_22 ) ;
if ( ! V_94 )
return - V_23 ;
for ( V_26 = 0 ; V_26 < V_95 ; V_26 ++ )
memcpy ( & V_94 [ V_26 ] , & V_92 -> V_96 ,
sizeof( T_1 ) ) ;
V_10 = V_89 -> V_10 ;
for ( V_3 = 0 ; V_3 < V_44 -> V_97 -> V_98 ; V_3 ++ ) {
if ( ! F_24 ( V_3 , ( unsigned long * ) & V_92 -> V_99 ) )
continue;
V_81 = V_2 -> V_6 [ V_3 ] . V_19 ;
V_93 = V_10 -> V_100 + V_10 -> V_101 ;
F_25 ( V_44 , ( unsigned char ) V_3 , 0 ,
V_10 -> V_100 , & V_94 [ 0 ] ) ;
F_25 ( V_44 , ( unsigned char ) V_3 , V_93 ,
V_81 - V_93 + 1 ,
& V_94 [ V_10 -> V_100 ] ) ;
}
F_3 ( V_94 ) ;
return 0 ;
}
static int F_26 ( struct V_43 * V_44 )
{
int V_26 , V_3 ;
struct V_1 * V_2 = V_44 -> V_2 ;
struct V_62 * V_102 = V_2 -> V_103 . V_63 ;
for ( V_26 = 0 ; V_26 < V_2 -> V_103 . V_104 ; V_26 ++ ) {
if ( V_102 -> V_47 ) {
if ( F_21 ( V_44 , V_102 ) )
return - V_27 ;
}
V_102 = (struct V_62 * ) ( ( unsigned long ) (
( unsigned long ) V_102 +
sizeof( struct V_62 ) ) +
( sizeof( struct V_74 ) *
V_102 -> V_77 ) ) ;
}
for ( V_3 = 0 ; V_3 < V_44 -> V_97 -> V_98 ; V_3 ++ ) {
if ( F_27 ( V_44 , V_3 ,
V_2 -> V_80 [ V_3 ] ) ) {
F_5 ( L_11 , V_3 ) ;
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
static void * F_28 ( struct V_105 * V_106 ,
char * V_107 , void * V_108 )
{
int V_26 ;
struct V_109 * V_110 =
(struct V_109 * )
( ( unsigned long ) V_106 + sizeof( struct V_105 ) ) ;
for ( V_26 = 0 ; V_26 < V_106 -> V_111 ; V_26 ++ ) {
if ( ( V_108 < ( void * ) & V_110 [ V_26 ] ) &&
! strncmp ( V_110 [ V_26 ] . V_107 , V_107 ,
V_112 ) ) {
return & V_110 [ V_26 ] ;
}
}
return NULL ;
}
static unsigned int F_29 ( unsigned int V_113 , int V_114 )
{
int V_26 ;
unsigned int V_115 = 1 << 0xF ;
unsigned int V_116 = ( unsigned int ) ( ( V_113 >> 0x18 ) ^ V_114 ) ;
V_113 ^= V_116 << 0x8 ;
for ( V_26 = 0 ; V_26 < 0x8 ; V_26 ++ ) {
if ( V_113 & V_115 )
V_113 = ( V_113 << 1 ) ^ 0x1021 ;
else
V_113 <<= 1 ;
}
return V_113 & 0xFFFF ;
}
static unsigned int F_30 ( char * V_49 , int V_59 )
{
unsigned int V_117 = 0 ;
if ( V_49 )
while ( V_59 -- )
V_117 = F_29 ( V_117 , * V_49 ++ ) ;
return V_117 ;
}
static struct V_118 *
F_31 ( char * V_60 , struct V_33 * V_119 ,
char * V_107 )
{
struct V_120 * V_121 ;
struct V_118 * V_106 ;
char * V_122 ;
int V_26 ;
V_121 = (struct V_120 * )
( V_60 + sizeof( struct V_33 ) ) ;
for ( V_26 = 0 ; V_26 < V_119 -> V_111 ; V_26 ++ ) {
if ( ! strncmp ( V_121 -> V_107 , V_107 ,
V_112 ) ) {
V_122 = V_60 + V_121 -> V_123 ;
if ( V_121 -> V_124 != F_30 (
V_122 , V_121 -> V_55 ) )
break;
V_106 = F_2 ( sizeof( * V_106 ) , V_22 ) ;
if ( ! V_106 )
break;
V_106 -> V_125 = V_122 ;
V_106 -> V_124 = V_121 -> V_124 ;
V_106 -> V_55 = V_121 -> V_55 ;
return V_106 ;
}
V_121 ++ ;
}
return NULL ;
}
static unsigned int
F_32 ( struct V_126 * V_127 ,
struct V_91 * V_89 )
{
struct V_128 * V_129 , * V_130 , * V_131 ;
struct V_128 * V_132 ;
struct V_133 * V_134 ;
V_134 = (struct V_133 * )
( ( char * ) V_89 + sizeof( struct V_91 ) ) ;
V_129 = (struct V_128 * ) ( V_127 -> V_135 +
V_134 -> V_136 ) ;
V_130 = (struct V_128 * ) ( V_127 -> V_135 +
V_134 -> V_137 ) ;
V_131 = (struct V_128 * )
( V_127 -> V_135 +
V_134 -> V_138 ) ;
if ( V_129 -> V_104 || V_130 -> V_104 ||
V_131 -> V_104 ) {
F_5 ( L_12 ) ;
return - V_27 ;
}
V_132 = (struct V_128 * )
( V_127 -> V_135 +
V_134 -> V_139 ) ;
if ( V_132 -> V_104 ) {
F_5 ( L_13 ) ;
return - V_27 ;
}
if ( V_89 -> V_140 > 1 ) {
F_5 ( L_14 ) ;
return - V_27 ;
}
if ( F_33 ( V_89 -> V_141 ) ) {
F_5 ( L_15 ) ;
return - V_61 ;
}
if ( F_34 ( V_89 -> V_141 ) ) {
F_5 ( L_16 ) ;
return - V_61 ;
}
return 0 ;
}
static void F_35 ( struct V_126
* V_127 ,
struct V_91 * V_142 ,
struct V_90 * V_10 )
{
struct V_133 * V_134 ;
struct V_143 * V_144 ;
struct V_128 * V_145 ;
struct V_146 * V_147 ;
int V_26 ;
V_134 = (struct V_133 * )
( ( char * ) V_142 + sizeof( struct V_91 ) ) ;
V_10 -> V_148 = V_134 -> V_148 ;
V_10 -> V_149 = V_134 -> V_149 ;
V_10 -> V_150 = V_134 -> V_150 ;
V_10 -> V_100 = V_134 -> V_100 ;
V_144 = (struct V_143 * ) ( V_127 -> V_135 +
V_134 -> V_151 ) ;
V_10 -> V_101 = V_144 -> V_101 ;
V_145 = (struct V_128 * )
( V_127 -> V_135 +
V_144 -> V_145 ) ;
V_10 -> V_152 = V_145 -> V_104 ;
V_147 = (struct V_146 * ) ( ( char * ) V_145 +
sizeof( struct V_128 ) ) ;
V_10 -> V_147 = (struct V_153 * ) V_147 ;
for ( V_26 = 0 ; V_26 < V_145 -> V_104 ; V_26 ++ )
V_10 -> V_147 [ V_26 ] . V_154 =
( unsigned long ) V_127 -> V_135 + V_147 [ V_26 ] . V_155 ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_7 * V_13 ,
int V_156 )
{
int V_26 , V_157 ;
struct V_109 * V_110 = NULL ;
struct V_91 * V_89 ;
struct V_128 * V_158 ;
struct V_128 * V_159 ;
struct V_128 * V_160 ;
struct V_126 * V_127 =
& V_2 -> V_127 ;
for ( V_157 = 0 ; V_157 < V_156 ; V_157 ++ ) {
V_110 = F_28 ( V_127 -> V_106 ,
V_161 , V_110 ) ;
if ( ! V_110 )
break;
V_89 = (struct V_91 * ) ( V_127 -> V_135 +
V_110 -> V_123 ) ;
V_158 = (struct V_128 * )
( V_89 -> V_162 +
V_2 -> V_106 -> V_125 ) ;
V_13 [ V_157 ] . V_163 = V_158 -> V_104 ;
V_13 [ V_157 ] . V_164 = (struct V_165 * )
( ( ( char * ) V_158 ) +
sizeof( struct V_128 ) ) ;
V_159 = (struct V_128 * )
( V_89 -> V_159 +
V_2 -> V_106 -> V_125 ) ;
V_13 [ V_157 ] . V_166 = V_159 -> V_104 ;
V_13 [ V_157 ] . V_167 = (struct V_168 * )
( ( ( char * ) V_159 ) +
sizeof( struct V_128 ) ) ;
V_160 = (struct V_128 * )
( V_89 -> V_160 + V_2 -> V_106 -> V_125 ) ;
V_13 [ V_157 ] . V_169 = V_160 -> V_104 ;
V_13 [ V_157 ] . V_170 = (struct V_171 * )
( ( ( char * ) V_160 ) +
sizeof( struct V_128 ) ) ;
V_13 [ V_157 ] . V_16 = V_89 ;
if ( F_32 ( V_127 , V_89 ) )
goto V_24;
V_13 [ V_157 ] . V_10 =
F_2 ( sizeof( struct V_90 ) ,
V_22 ) ;
if ( ! V_13 [ V_157 ] . V_10 )
goto V_24;
F_35 ( V_127 , V_89 ,
V_13 [ V_157 ] . V_10 ) ;
}
return V_157 ;
V_24:
for ( V_26 = 0 ; V_26 < V_157 ; V_26 ++ )
F_3 ( V_13 [ V_26 ] . V_10 ) ;
return 0 ;
}
static int F_37 ( struct V_43 * V_44 , int V_172 )
{
int V_26 , V_3 ;
int V_173 = 0 ;
struct V_1 * V_2 = V_44 -> V_2 ;
for ( V_3 = 0 ; V_3 <= V_172 ; V_3 ++ ) {
if ( ! F_24 ( V_3 ,
( unsigned long * ) & V_44 -> V_97 -> V_174 ) )
continue;
for ( V_26 = 0 ; V_26 < V_2 -> V_175 ; V_26 ++ ) {
if ( ! F_24 ( V_3 , ( unsigned long * )
& V_2 -> V_13 [ V_26 ] . V_16 -> V_99 ) )
continue;
V_173 = 1 ;
if ( F_1 ( V_2 , V_3 , V_26 ) )
return - V_27 ;
}
}
if ( ! V_173 ) {
F_5 ( L_17 ) ;
return - V_27 ;
}
return 0 ;
}
static struct V_28 *
F_38 ( struct V_118 * V_106 ,
char * V_176 , struct V_28 * V_29 )
{
struct V_109 * V_110 ;
V_110 = F_28 ( (struct V_105 * )
V_106 -> V_125 , V_176 , NULL ) ;
if ( V_110 ) {
int V_177 ;
memcpy ( & V_29 -> V_31 , V_106 -> V_125 +
V_110 -> V_123 , sizeof( V_29 -> V_31 ) ) ;
V_177 = ( char * ) & V_29 -> V_32 - ( char * ) V_29 ;
V_29 -> V_32 = ( unsigned long ) V_106 -> V_125 +
V_110 -> V_123 + V_177 ;
return V_29 ;
}
return NULL ;
}
static void
F_39 ( struct V_126 * V_127 ,
struct V_178 * V_103 )
{
struct V_109 * V_110 ;
V_110 = F_28 ( V_127 -> V_106 ,
V_179 , NULL ) ;
if ( V_110 ) {
memmove ( & V_103 -> V_104 , V_127 -> V_135 +
V_110 -> V_123 , sizeof( unsigned int ) ) ;
V_103 -> V_63 = (struct V_62 * )
( V_127 -> V_135 + V_110 -> V_123 +
sizeof( unsigned int ) ) ;
}
}
static int F_40 ( struct V_1 * V_2 )
{
unsigned int V_36 , V_180 = V_2 -> V_180 ;
if ( ! ( V_180 & V_2 -> V_127 . V_106 -> V_181 ) ) {
F_5 ( L_18 ,
V_2 -> V_127 . V_106 -> V_181 , V_180 ) ;
return - V_27 ;
}
V_36 = V_2 -> V_182 & 0xff ;
if ( ( V_2 -> V_127 . V_106 -> V_183 < V_36 ) ||
( V_2 -> V_127 . V_106 -> V_184 > V_36 ) ) {
F_5 ( L_19 , V_36 ) ;
return - V_27 ;
}
return 0 ;
}
static int F_41 ( struct V_43 * V_44 ,
unsigned char V_3 , unsigned char V_185 ,
enum V_186 V_187 ,
unsigned short V_188 , unsigned int V_54 )
{
switch ( V_187 ) {
case V_189 :
case V_190 :
V_185 = 0 ;
case V_191 :
case V_192 :
return F_42 ( V_44 , V_3 , V_185 , V_187 ,
V_188 , V_54 ) ;
case V_193 :
case V_194 :
case V_195 :
case V_196 :
V_185 = 0 ;
case V_197 :
case V_198 :
case V_199 :
case V_200 :
return F_43 ( V_44 , V_3 , V_185 , V_187 ,
V_188 , V_54 ) ;
case V_201 :
case V_202 :
V_185 = 0 ;
case V_203 :
case V_204 :
return F_44 ( V_44 , V_3 , V_185 , V_187 ,
V_188 , V_54 ) ;
case V_205 :
return F_45 ( V_44 , V_3 , V_185 , V_188 , V_54 ) ;
default:
F_5 ( L_20 , V_187 ) ;
return - V_61 ;
}
return 0 ;
}
static int F_46 ( struct V_43 * V_44 ,
unsigned int V_3 ,
struct V_7 * V_206 )
{
unsigned int V_26 ;
unsigned char V_185 ;
struct V_168 * V_167 ;
if ( F_47 ( V_206 -> V_16 -> V_141 ) ==
V_207 )
V_185 = 0xff ;
else
V_185 = 0x55 ;
for ( V_26 = 0 ; V_26 < V_206 -> V_166 ; V_26 ++ ) {
unsigned int V_208 ;
V_167 = & V_206 -> V_167 [ V_26 ] ;
V_208 = V_167 -> V_54 ;
switch ( V_167 -> V_209 ) {
case V_210 :
F_41 ( V_44 , V_3 , V_185 ,
(enum V_186 )
V_167 -> V_187 ,
( unsigned short ) V_167 -> V_188 ,
V_208 ) ;
break;
case V_211 :
if ( ! ( ( 1 << V_167 -> V_212 ) & V_185 ) ) {
F_5 ( L_21 ,
V_167 -> V_212 ) ;
return - V_27 ;
}
F_41 ( V_44 , V_3 ,
( unsigned char )
( 1 << V_167 -> V_212 ) ,
(enum V_186 )
V_167 -> V_187 ,
( unsigned short ) V_167 -> V_188 ,
V_208 ) ;
break;
case V_213 :
F_5 ( L_22 ) ;
return - V_27 ;
case V_214 :
F_5 ( L_23 ) ;
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
unsigned int V_215 , V_3 ;
if ( V_2 -> V_216 )
return 0 ;
if ( V_2 -> V_103 . V_104 ) {
if ( F_26 ( V_44 ) ) {
F_5 ( L_24 ) ;
return - V_27 ;
}
}
for ( V_3 = 0 ; V_3 < V_44 -> V_97 -> V_98 ; V_3 ++ ) {
for ( V_215 = 0 ; V_215 < V_2 -> V_6 [ V_3 ] . V_15 ; V_215 ++ ) {
if ( ! V_2 -> V_6 [ V_3 ] . V_14 [ V_215 ] . V_8 )
continue;
if ( F_46 ( V_44 , V_3 ,
V_2 -> V_6 [ V_3 ] .
V_14 [ V_215 ] . V_8 ) )
return - V_27 ;
}
}
V_2 -> V_216 = 1 ;
return 0 ;
}
static int F_49 ( struct V_43 * V_44 )
{
unsigned char V_3 , V_217 , V_215 ;
struct V_91 * V_92 ;
struct V_5 * V_6 ;
struct V_1 * V_2 = V_44 -> V_2 ;
for ( V_3 = 0 ; V_3 < V_44 -> V_97 -> V_98 ; V_3 ++ ) {
if ( ! F_24 ( V_3 ,
( unsigned long * ) & V_44 -> V_97 -> V_174 ) )
continue;
V_6 = & V_2 -> V_6 [ V_3 ] ;
for ( V_215 = 0 ; V_215 < F_50 (unsigned int, ae_data->slice_num,
ICP_QAT_UCLO_MAX_CTX) ; V_215 ++ ) {
if ( ! V_2 -> V_6 [ V_3 ] . V_14 [ V_215 ] . V_8 )
continue;
V_92 = V_6 -> V_14 [ V_215 ] . V_8 -> V_16 ;
if ( F_51 ( V_44 , V_3 ,
( char ) F_47
( V_92 -> V_141 ) ) ) {
F_5 ( L_25 ) ;
return - V_61 ;
}
V_217 = F_52 ( V_92 -> V_141 ) ;
if ( F_53 ( V_44 , V_3 , V_217 ) ) {
F_5 ( L_26 ) ;
return - V_61 ;
}
if ( F_54 ( V_44 , V_3 , V_218 ,
( char ) F_55
( V_92 -> V_141 ) ) ) {
F_5 ( L_27 ) ;
return - V_61 ;
}
if ( F_54 ( V_44 , V_3 , V_219 ,
( char ) F_56
( V_92 -> V_141 ) ) ) {
F_5 ( L_28 ) ;
return - V_61 ;
}
}
}
return 0 ;
}
static void F_57 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_2 ;
struct V_7 * V_89 ;
int V_220 ;
for ( V_220 = 0 ; V_220 < V_2 -> V_175 ; V_220 ++ ) {
V_89 = & V_2 -> V_13 [ V_220 ] ;
V_89 -> V_84 = V_89 -> V_10 -> V_100 +
V_89 -> V_10 -> V_101 ;
}
}
static int F_58 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_2 ;
unsigned int V_3 ;
V_2 -> V_221 = F_23 ( V_222 , sizeof( T_1 ) ,
V_22 ) ;
if ( ! V_2 -> V_221 )
return - V_23 ;
V_2 -> V_127 . V_135 = V_2 -> V_106 -> V_125 ;
V_2 -> V_127 . V_106 = (struct V_105 * )
V_2 -> V_106 -> V_125 ;
V_2 -> V_223 = 6 ;
V_2 -> V_180 = V_224 ;
V_2 -> V_182 = V_225 |
( V_226 & V_44 -> V_97 -> V_227 ) ;
if ( F_40 ( V_2 ) ) {
F_5 ( L_29 ) ;
return - V_27 ;
}
V_2 -> V_20 = V_95 ;
if ( ! V_2 -> V_106 -> V_125 ||
! F_38 ( V_2 -> V_106 , V_228 ,
& V_2 -> V_29 ) ) {
F_5 ( L_30 ) ;
goto V_24;
}
V_2 -> V_175 =
F_36 ( V_2 , V_2 -> V_13 ,
V_68 * V_207 ) ;
if ( ! V_2 -> V_175 )
goto V_24;
if ( F_37 ( V_44 , V_44 -> V_97 -> V_98 ) ) {
F_5 ( L_31 ) ;
goto V_229;
}
F_57 ( V_44 ) ;
F_39 ( & V_2 -> V_127 ,
& V_2 -> V_103 ) ;
if ( F_49 ( V_44 ) )
goto V_229;
return 0 ;
V_229:
for ( V_3 = 0 ; V_3 < V_2 -> V_175 ; V_3 ++ )
F_3 ( V_2 -> V_13 [ V_3 ] . V_10 ) ;
V_24:
F_3 ( V_2 -> V_221 ) ;
return - V_61 ;
}
int F_59 ( struct V_43 * V_44 ,
void * V_230 , int V_231 )
{
struct V_33 * V_232 ;
struct V_1 * V_233 ;
F_60 ( V_68 >=
( sizeof( V_44 -> V_97 -> V_174 ) * 8 ) ) ;
if ( ! V_44 || ! V_230 || V_231 < 24 )
return - V_27 ;
V_233 = F_2 ( sizeof( * V_233 ) , V_22 ) ;
if ( ! V_233 )
return - V_23 ;
V_233 -> V_234 = F_61 ( V_230 , V_231 , V_22 ) ;
if ( ! V_233 -> V_234 )
goto V_235;
V_232 = (struct V_33 * ) V_233 -> V_234 ;
if ( F_7 ( V_232 ) )
goto V_236;
V_233 -> V_106 = F_31 ( ( char * ) V_233 -> V_234 , V_232 ,
V_237 ) ;
if ( ! V_233 -> V_106 ) {
F_5 ( L_32 ) ;
goto V_236;
}
V_44 -> V_2 = V_233 ;
if ( F_58 ( V_44 ) )
goto V_238;
return 0 ;
V_238:
V_44 -> V_2 = NULL ;
F_3 ( V_233 -> V_106 ) ;
V_236:
F_3 ( V_233 -> V_234 ) ;
V_235:
F_3 ( V_233 ) ;
return - V_23 ;
}
void F_62 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_2 ;
unsigned int V_220 ;
if ( ! V_2 )
return;
F_3 ( V_2 -> V_221 ) ;
for ( V_220 = 0 ; V_220 < V_2 -> V_175 ; V_220 ++ )
F_3 ( V_2 -> V_13 [ V_220 ] . V_10 ) ;
for ( V_220 = 0 ; V_220 < V_44 -> V_97 -> V_98 ; V_220 ++ )
F_4 ( & V_2 -> V_6 [ V_220 ] ) ;
F_3 ( V_2 -> V_106 ) ;
F_3 ( V_2 -> V_234 ) ;
F_3 ( V_2 ) ;
V_44 -> V_2 = NULL ;
}
static void F_63 ( struct V_1 * V_2 ,
struct V_90 * V_25 ,
T_1 * V_239 , unsigned int V_240 ,
unsigned int V_241 , T_1 V_242 )
{
T_1 V_243 = 0 ;
unsigned int V_26 ;
if ( ! V_25 ) {
* V_239 = V_242 ;
return;
}
for ( V_26 = 0 ; V_26 < V_25 -> V_152 ; V_26 ++ ) {
if ( V_241 >= V_25 -> V_147 [ V_26 ] . V_244 &&
V_241 <= V_25 -> V_147 [ V_26 ] . V_244 +
V_25 -> V_147 [ V_26 ] . V_245 - 1 ) {
V_241 -= V_25 -> V_147 [ V_26 ] . V_244 ;
V_241 *= V_2 -> V_223 ;
memcpy ( & V_243 , ( void * ) ( ( ( unsigned long )
V_25 -> V_147 [ V_26 ] . V_154 ) + V_241 ) ,
V_2 -> V_223 ) ;
V_243 = V_243 & 0xbffffffffffull ;
}
}
* V_239 = V_243 ;
if ( * V_239 == V_246 )
* V_239 = V_242 ;
}
static void F_64 ( struct V_43 * V_44 ,
struct V_90
* V_25 , unsigned int V_3 )
{
unsigned int V_247 , V_248 , V_26 , V_245 , V_249 ;
struct V_1 * V_2 = V_44 -> V_2 ;
T_1 V_250 ;
memcpy ( & V_250 , V_2 -> V_13 [ 0 ] . V_16 -> V_96 ,
sizeof( T_1 ) ) ;
V_247 = V_25 -> V_100 ;
V_248 = 0 ;
V_245 = V_25 -> V_101 ;
while ( V_245 ) {
if ( V_245 < V_222 )
V_249 = V_245 ;
else
V_249 = V_222 ;
for ( V_26 = 0 ; V_26 < V_249 ; V_26 ++ )
F_63 ( V_2 , V_25 ,
& V_2 -> V_221 [ V_26 ] ,
V_247 + V_26 ,
V_248 + V_26 , V_250 ) ;
F_25 ( V_44 , ( unsigned char ) V_3 ,
V_247 , V_249 ,
V_2 -> V_221 ) ;
V_247 += V_249 ;
V_248 += V_249 ;
V_245 -= V_249 ;
}
}
static void F_65 ( struct V_43 * V_44 ,
struct V_91 * V_89 )
{
struct V_1 * V_2 = V_44 -> V_2 ;
unsigned int V_185 , V_215 ;
struct V_9 * V_10 ;
unsigned char V_3 ;
int V_212 ;
if ( F_47 ( V_89 -> V_141 ) == V_207 )
V_185 = 0xff ;
else
V_185 = 0x55 ;
for ( V_3 = 0 ; V_3 < V_44 -> V_97 -> V_98 ; V_3 ++ ) {
if ( ! F_24 ( V_3 , ( unsigned long * ) & V_89 -> V_99 ) )
continue;
for ( V_215 = 0 ; V_215 < V_2 -> V_6 [ V_3 ] . V_15 ; V_215 ++ ) {
if ( V_89 -> V_18 & V_2 -> V_6 [ V_3 ] .
V_14 [ V_215 ] . V_17 )
break;
}
if ( V_215 >= V_2 -> V_6 [ V_3 ] . V_15 )
continue;
V_10 = V_2 -> V_6 [ V_3 ] . V_14 [ V_215 ] . V_10 ;
if ( ! V_10 -> V_25 -> V_148 )
continue;
F_64 ( V_44 , V_10 -> V_25 , V_3 ) ;
V_10 = V_2 -> V_6 [ V_3 ] . V_14 [ V_215 ] . V_10 ;
for ( V_212 = 0 ; V_212 < V_207 ; V_212 ++ )
V_2 -> V_6 [ V_3 ] . V_14 [ V_215 ] . V_251 [ V_212 ] =
( V_185 & ( 1 << V_212 ) ) ? V_10 : NULL ;
F_66 ( V_44 , ( unsigned char ) V_3 ,
V_89 -> V_18 ) ;
F_67 ( V_44 , ( unsigned char ) V_3 , V_89 -> V_18 ,
V_89 -> V_252 ) ;
}
}
int F_68 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_2 ;
unsigned int V_26 ;
if ( F_48 ( V_44 ) )
return - V_27 ;
for ( V_26 = 0 ; V_26 < V_2 -> V_175 ; V_26 ++ ) {
if ( ! V_2 -> V_13 [ V_26 ] . V_16 )
return - V_27 ;
if ( F_22 ( V_44 , & V_2 -> V_13 [ V_26 ] ) )
return - V_27 ;
F_65 ( V_44 ,
V_2 -> V_13 [ V_26 ] . V_16 ) ;
}
return 0 ;
}
