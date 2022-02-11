static inline void F_1 ( char * V_1 )
{
int V_2 = strlen ( V_1 ) ;
if ( V_1 [ V_2 - 1 ] != '*' )
strcat ( V_1 + V_2 , L_1 ) ;
}
static void F_2 ( const char * V_3 , const char * V_4 ,
unsigned long V_5 , unsigned long V_6 ,
void * V_7 )
{
int V_8 ;
if ( V_5 % V_6 || V_5 < V_6 ) {
if ( V_9 != 0 )
return;
F_3 ( L_2
L_3
L_4
L_5 ,
V_3 , V_4 , V_6 , V_4 , V_5 , V_4 ) ;
}
for ( V_8 = 0 ; V_8 < V_6 ; V_8 ++ ) {
if ( * ( V_10 * ) ( V_7 + V_5 - V_6 + V_8 ) ) {
fprintf ( V_11 , L_6
L_7 ,
V_3 , V_4 , V_6 , V_5 / V_6 ) ;
for ( V_8 = 0 ; V_8 < V_6 ; V_8 ++ )
fprintf ( V_11 , L_8 ,
* ( V_10 * ) ( V_7 + V_5 - V_6 + V_8 ) ) ;
fprintf ( V_11 , L_9 ) ;
F_3 ( L_10
L_11 , V_3 , V_4 ) ;
}
}
}
static void F_4 ( struct V_12 * V_13 ,
unsigned int V_14 , int V_15 ,
unsigned char V_16 , unsigned char V_17 ,
unsigned char V_18 , struct V_19 * V_20 )
{
char V_21 [ 500 ] ;
strcpy ( V_21 , L_12 ) ;
F_5 ( V_21 , L_13 , V_13 -> V_22 & V_23 ,
V_13 -> V_24 ) ;
F_5 ( V_21 , L_14 , V_13 -> V_22 & V_25 ,
V_13 -> V_26 ) ;
strcat ( V_21 , L_15 ) ;
if ( V_15 )
sprintf ( V_21 + strlen ( V_21 ) , L_16 ,
V_15 , V_14 ) ;
if ( V_16 == V_17 )
sprintf ( V_21 + strlen ( V_21 ) , L_17 , V_16 ) ;
else if ( V_16 > 0 || V_17 < V_18 ) {
if ( V_16 > 0x9 || V_17 < 0xA )
sprintf ( V_21 + strlen ( V_21 ) ,
L_18 ,
V_16 ,
V_17 ) ;
else {
sprintf ( V_21 + strlen ( V_21 ) ,
V_16 < 0x9 ? L_19 : L_20 ,
V_16 ) ;
sprintf ( V_21 + strlen ( V_21 ) ,
V_17 > 0xA ? L_21 : L_22 ,
V_16 ) ;
}
}
if ( V_15 < ( sizeof( V_13 -> V_27 ) * 2 - 1 ) )
strcat ( V_21 , L_1 ) ;
F_5 ( V_21 , L_23 , V_13 -> V_22 & V_28 ,
V_13 -> V_29 ) ;
F_5 ( V_21 , L_24 ,
V_13 -> V_22 & V_30 ,
V_13 -> V_31 ) ;
F_5 ( V_21 , L_25 ,
V_13 -> V_22 & V_32 ,
V_13 -> V_33 ) ;
F_5 ( V_21 , L_26 ,
V_13 -> V_22 & V_34 ,
V_13 -> V_35 ) ;
F_5 ( V_21 , L_27 ,
V_13 -> V_22 & V_36 ,
V_13 -> V_37 ) ;
F_5 ( V_21 , L_28 ,
V_13 -> V_22 & V_38 ,
V_13 -> V_39 ) ;
F_1 ( V_21 ) ;
F_6 ( & V_20 -> V_40 ,
L_29 , V_21 ) ;
}
static unsigned int F_7 ( unsigned int * V_41 ,
int V_42 ,
unsigned char V_18 ,
T_1 V_43 )
{
unsigned int V_44 = * V_41 , V_8 , V_45 ;
unsigned long long V_46 , V_47 = 0 ;
if ( V_18 > 0x9 ) {
* V_41 += V_42 ;
return V_44 ;
}
for ( V_8 = 0 ; V_8 < V_43 ; V_8 ++ ) {
V_46 = ( * V_41 >> ( V_8 << 2 ) ) & 0xf ;
V_46 = V_46 > 9 ? 9 : V_46 ;
for ( V_45 = 0 ; V_45 < V_8 ; V_45 ++ )
V_46 = V_46 * 10 ;
V_47 += V_46 ;
}
V_47 += V_42 ;
* V_41 = 0 ;
for ( V_8 = 0 ; V_8 < V_43 ; V_8 ++ ) {
for ( V_46 = 1 , V_45 = 0 ; V_45 < V_8 ; V_45 ++ )
V_46 = V_46 * 10 ;
V_46 = ( V_47 / V_46 ) % 10 ;
* V_41 += V_46 << ( V_8 << 2 ) ;
}
return V_44 ;
}
static void F_8 ( struct V_12 * V_13 , struct V_19 * V_20 )
{
unsigned int V_48 , V_49 ;
unsigned char V_50 , V_51 , V_18 ;
int V_52 ;
V_13 -> V_22 = F_9 ( V_13 -> V_22 ) ;
V_13 -> V_24 = F_9 ( V_13 -> V_24 ) ;
V_13 -> V_26 = F_9 ( V_13 -> V_26 ) ;
V_48 = V_13 -> V_22 & V_53 ?
F_9 ( V_13 -> V_27 ) : 0x0U ;
V_49 = V_13 -> V_22 & V_54 ?
F_9 ( V_13 -> V_55 ) : ~ 0x0U ;
V_18 = 0x9 ;
for ( V_52 = 0 ; V_52 < sizeof( V_13 -> V_27 ) * 2 ; V_52 ++ ) {
V_51 = ( V_48 >> ( V_52 << 2 ) ) & 0xf ;
V_50 = ( ( V_49 > 0x9999 ? 0x9999 : V_49 ) >> ( V_52 << 2 ) ) & 0xf ;
if ( V_51 > V_18 || V_50 > V_18 ) {
V_18 = 0xf ;
break;
}
}
if ( ! ( V_13 -> V_24 | V_13 -> V_26 | V_13 -> V_29 | V_13 -> V_35 ) )
return;
for ( V_52 = sizeof( V_13 -> V_27 ) * 2 - 1 ; V_48 <= V_49 ; V_52 -- ) {
V_51 = V_48 & 0xf ;
V_50 = V_49 & 0xf ;
if ( V_50 > V_18 )
V_50 = V_18 ;
V_48 >>= 4 ;
V_49 >>= 4 ;
if ( V_48 == V_49 || ! V_52 ) {
F_4 ( V_13 , V_48 , V_52 , V_51 , V_50 , V_18 , V_20 ) ;
break;
}
if ( V_51 > 0x0 )
F_4 ( V_13 ,
F_7 ( & V_48 , 1 , V_18 ,
sizeof( V_13 -> V_27 ) * 2 ) ,
V_52 , V_51 , V_18 , V_18 , V_20 ) ;
if ( V_50 < V_18 )
F_4 ( V_13 ,
F_7 ( & V_49 , - 1 , V_18 ,
sizeof( V_13 -> V_27 ) * 2 ) ,
V_52 , 0x0 , V_50 , V_18 , V_20 ) ;
}
}
static void F_10 ( void * V_7 , unsigned long V_5 ,
struct V_19 * V_20 )
{
unsigned int V_8 ;
const unsigned long V_6 = sizeof( struct V_12 ) ;
F_2 ( V_20 -> V_56 , L_30 , V_5 , V_6 , V_7 ) ;
V_5 -= V_6 ;
for ( V_8 = 0 ; V_8 < V_5 ; V_8 += V_6 )
F_8 ( V_7 + V_8 , V_20 ) ;
}
static int F_11 ( const char * V_57 ,
struct V_58 * V_13 , char * V_21 )
{
V_13 -> V_59 = F_9 ( V_13 -> V_59 ) ;
V_13 -> V_60 = F_9 ( V_13 -> V_60 ) ;
V_13 -> V_61 = F_9 ( V_13 -> V_61 ) ;
V_13 -> V_62 = F_9 ( V_13 -> V_62 ) ;
sprintf ( V_21 , L_31 ) ;
F_5 ( V_21 , L_32 , V_13 -> V_59 != V_63 , V_13 -> V_59 ) ;
F_5 ( V_21 , L_33 , V_13 -> V_60 != V_64 , V_13 -> V_60 ) ;
F_5 ( V_21 , L_13 , V_13 -> V_61 != V_65 , V_13 -> V_61 ) ;
F_5 ( V_21 , L_14 , V_13 -> V_62 != V_65 , V_13 -> V_62 ) ;
return 1 ;
}
static int F_12 ( const char * V_57 ,
struct V_66 * V_13 , char * V_21 )
{
V_13 -> V_22 = F_9 ( V_13 -> V_22 ) ;
V_13 -> V_67 = F_9 ( V_13 -> V_67 ) ;
V_13 -> V_68 = F_9 ( V_13 -> V_68 ) ;
V_13 -> V_69 = F_9 ( V_13 -> V_69 ) ;
V_13 -> V_70 = F_9 ( V_13 -> V_70 ) ;
strcpy ( V_21 , L_34 ) ;
F_5 ( V_21 , L_35 , V_13 -> V_22 & V_71 ,
V_13 -> V_67 ) ;
F_5 ( V_21 , L_36 , V_13 -> V_22 & V_72 ,
V_13 -> V_68 ) ;
F_5 ( V_21 , L_37 , V_13 -> V_22 & V_73 ,
V_13 -> V_69 ) ;
F_5 ( V_21 , L_38 , V_13 -> V_22 & V_74 ,
V_13 -> V_70 ) ;
F_1 ( V_21 ) ;
return 1 ;
}
static int F_13 ( const char * V_57 ,
struct V_75 * V_13 , char * V_21 )
{
unsigned char V_76 , V_77 , V_78 ,
V_79 , V_80 , V_81 ;
V_13 -> V_61 = F_9 ( V_13 -> V_61 ) ;
V_13 -> V_82 = F_9 ( V_13 -> V_82 ) ;
V_13 -> V_83 = F_9 ( V_13 -> V_83 ) ;
V_13 -> V_84 = F_9 ( V_13 -> V_84 ) ;
V_13 -> V_85 = F_9 ( V_13 -> V_85 ) ;
V_13 -> V_86 = F_9 ( V_13 -> V_86 ) ;
strcpy ( V_21 , L_39 ) ;
F_5 ( V_21 , L_13 , V_13 -> V_61 != V_87 , V_13 -> V_61 ) ;
F_5 ( V_21 , L_15 , V_13 -> V_82 != V_87 , V_13 -> V_82 ) ;
F_5 ( V_21 , L_40 , V_13 -> V_83 != V_87 , V_13 -> V_83 ) ;
F_5 ( V_21 , L_41 , V_13 -> V_84 != V_87 , V_13 -> V_84 ) ;
V_76 = ( V_13 -> V_85 ) >> 16 ;
V_79 = ( V_13 -> V_86 ) >> 16 ;
V_77 = ( V_13 -> V_85 ) >> 8 ;
V_80 = ( V_13 -> V_86 ) >> 8 ;
V_78 = V_13 -> V_85 ;
V_81 = V_13 -> V_86 ;
if ( ( V_79 != 0 && V_79 != 0xFF )
|| ( V_80 != 0 && V_80 != 0xFF )
|| ( V_81 != 0 && V_81 != 0xFF ) ) {
F_14 ( L_42 ,
V_57 , V_13 -> V_86 ) ;
return 0 ;
}
F_5 ( V_21 , L_43 , V_79 == 0xFF , V_76 ) ;
F_5 ( V_21 , L_44 , V_80 == 0xFF , V_77 ) ;
F_5 ( V_21 , L_45 , V_81 == 0xFF , V_78 ) ;
F_1 ( V_21 ) ;
return 1 ;
}
static int F_15 ( const char * V_57 ,
struct V_88 * V_13 , char * V_21 )
{
V_13 -> V_22 = F_9 ( V_13 -> V_22 ) ;
V_13 -> V_89 = F_9 ( V_13 -> V_89 ) ;
V_13 -> V_90 = F_9 ( V_13 -> V_90 ) ;
V_13 -> V_91 = F_9 ( V_13 -> V_91 ) ;
V_13 -> V_92 = F_9 ( V_13 -> V_92 ) ;
strcpy ( V_21 , L_46 ) ;
F_5 ( V_21 , L_47 , V_13 -> V_22 & V_93 ,
V_13 -> V_89 ) ;
F_5 ( V_21 , L_48 , V_13 -> V_22 & V_94 ,
V_13 -> V_90 ) ;
F_5 ( V_21 , L_49 , V_13 -> V_22 & V_95 ,
V_13 -> V_91 ) ;
F_5 ( V_21 , L_50 , V_13 -> V_22 & V_96 ,
V_13 -> V_92 ) ;
F_1 ( V_21 ) ;
return 1 ;
}
static int F_16 ( const char * V_57 ,
struct V_97 * V_13 , char * V_21 )
{
sprintf ( V_21 , L_51 , V_13 -> V_91 ) ;
return 1 ;
}
static int F_17 ( const char * V_57 ,
struct V_98 * V_13 , char * V_21 )
{
sprintf ( V_21 , L_52 , V_13 -> type ) ;
return 1 ;
}
static int F_18 ( const char * V_57 ,
struct V_99 * V_13 , char * V_21 )
{
V_13 -> type = F_9 ( V_13 -> type ) ;
V_13 -> V_100 = F_9 ( V_13 -> V_100 ) ;
V_13 -> V_13 = F_9 ( V_13 -> V_13 ) ;
V_13 -> V_101 = F_9 ( V_13 -> V_101 ) ;
strcpy ( V_21 , L_53 ) ;
F_5 ( V_21 , L_54 , V_13 -> type != V_102 , V_13 -> type ) ;
F_5 ( V_21 , L_55 , V_13 -> V_100 != V_102 , V_13 -> V_100 ) ;
F_5 ( V_21 , L_56 , V_13 -> V_13 != V_102 , V_13 -> V_13 ) ;
F_5 ( V_21 , L_57 , V_13 -> V_101 != V_102 , V_13 -> V_101 ) ;
F_1 ( V_21 ) ;
return 1 ;
}
static int F_19 ( const char * V_57 ,
struct V_103 * V_13 , char * V_21 )
{
sprintf ( V_21 , L_58 , V_13 -> V_13 ) ;
return 1 ;
}
static void F_20 ( void * V_7 , unsigned long V_5 ,
struct V_19 * V_20 )
{
const unsigned long V_6 = sizeof( struct V_104 ) ;
const unsigned int V_105 = ( V_5 / V_6 ) - 1 ;
const struct V_104 * V_106 = V_7 ;
unsigned int V_8 ;
F_2 ( V_20 -> V_56 , L_59 , V_5 , V_6 , V_7 ) ;
for ( V_8 = 0 ; V_8 < V_105 ; V_8 ++ ) {
const char * V_13 = ( char * ) V_106 [ V_8 ] . V_13 ;
char V_107 [ sizeof( V_106 [ 0 ] . V_13 ) ] ;
int V_45 ;
F_6 ( & V_20 -> V_40 ,
L_60 , V_13 ) ;
for ( V_45 = 0 ; V_45 < sizeof( V_107 ) ; V_45 ++ )
V_107 [ V_45 ] = toupper ( V_13 [ V_45 ] ) ;
F_6 ( & V_20 -> V_40 ,
L_61 , V_107 ) ;
}
}
static void F_21 ( void * V_7 , unsigned long V_5 ,
struct V_19 * V_20 )
{
const unsigned long V_6 = sizeof( struct V_108 ) ;
const unsigned int V_105 = ( V_5 / V_6 ) - 1 ;
const struct V_108 * V_109 = V_7 ;
unsigned int V_8 ;
F_2 ( V_20 -> V_56 , L_59 , V_5 , V_6 , V_7 ) ;
for ( V_8 = 0 ; V_8 < V_105 ; V_8 ++ ) {
unsigned int V_45 ;
const struct V_108 * V_110 = & V_109 [ V_8 ] ;
for ( V_45 = 0 ; V_45 < V_111 ; V_45 ++ ) {
const char * V_13 = ( char * ) V_110 -> V_106 [ V_45 ] . V_13 ;
int V_112 , V_113 ;
int V_114 = 0 ;
if ( ! V_13 [ 0 ] )
break;
for ( V_112 = 0 ; V_112 < V_8 && ! V_114 ; V_112 ++ ) {
const struct V_108 * V_115 = & V_109 [ V_112 ] ;
for ( V_113 = 0 ; V_113 < V_111 ; V_113 ++ ) {
const char * V_116 = ( char * ) V_115 -> V_106 [ V_113 ] . V_13 ;
if ( ! V_116 [ 0 ] )
break;
if ( ! strcmp ( V_13 , V_116 ) ) {
V_114 = 1 ;
break;
}
}
}
if ( ! V_114 ) {
char V_107 [ sizeof( V_110 -> V_106 [ 0 ] . V_13 ) ] ;
int V_117 ;
F_6 ( & V_20 -> V_40 ,
L_60 , V_13 ) ;
for ( V_117 = 0 ; V_117 < sizeof( V_107 ) ; V_117 ++ )
V_107 [ V_117 ] = toupper ( V_13 [ V_117 ] ) ;
F_6 ( & V_20 -> V_40 ,
L_61 , V_107 ) ;
}
}
}
}
static int F_22 ( const char * V_57 ,
struct V_118 * V_13 , char * V_21 )
{
unsigned int V_8 ;
V_13 -> V_22 = F_9 ( V_13 -> V_22 ) ;
V_13 -> V_119 = F_9 ( V_13 -> V_119 ) ;
V_13 -> V_120 = F_9 ( V_13 -> V_120 ) ;
V_13 -> V_121 = F_9 ( V_13 -> V_121 ) ;
V_13 -> V_122 = F_9 ( V_13 -> V_122 ) ;
V_13 -> V_123 = F_9 ( V_13 -> V_123 ) ;
for ( V_8 = 0 ; V_8 < 4 ; V_8 ++ ) {
V_13 -> V_124 [ V_8 ] = F_9 ( V_13 -> V_124 [ V_8 ] ) ;
}
strcpy ( V_21 , L_62 ) ;
F_5 ( V_21 , L_48 , V_13 -> V_22 & V_125 ,
V_13 -> V_119 ) ;
F_5 ( V_21 , L_63 , V_13 -> V_22 & V_126 ,
V_13 -> V_120 ) ;
F_5 ( V_21 , L_64 , V_13 -> V_22 & V_127 ,
V_13 -> V_121 ) ;
F_5 ( V_21 , L_65 , V_13 -> V_22 & V_128 ,
V_13 -> V_122 ) ;
F_5 ( V_21 , L_66 , V_13 -> V_22 & V_129 ,
V_13 -> V_123 ) ;
F_5 ( V_21 , L_67 , V_13 -> V_22 & V_130 , V_13 -> V_124 [ 0 ] ) ;
F_5 ( V_21 , L_68 , V_13 -> V_22 & V_131 , V_13 -> V_124 [ 1 ] ) ;
F_5 ( V_21 , L_69 , V_13 -> V_22 & V_132 , V_13 -> V_124 [ 2 ] ) ;
F_5 ( V_21 , L_70 , V_13 -> V_22 & V_133 , V_13 -> V_124 [ 3 ] ) ;
F_1 ( V_21 ) ;
return 1 ;
}
static int F_23 ( const char * V_57 , struct V_134 * V_135 , char * V_21 )
{
int V_2 ;
char * V_136 ;
V_2 = sprintf ( V_21 , L_71 ,
V_135 -> V_56 [ 0 ] ? V_135 -> V_56 : L_1 ,
V_135 -> type [ 0 ] ? V_135 -> type : L_1 ) ;
if ( V_135 -> V_137 [ 0 ] )
sprintf ( & V_21 [ V_2 ] , L_72 ,
V_135 -> type [ 0 ] ? L_1 : L_73 ,
V_135 -> V_137 ) ;
for ( V_136 = V_21 ; V_136 && * V_136 ; V_136 ++ )
if ( isspace ( * V_136 ) )
* V_136 = '_' ;
F_1 ( V_21 ) ;
return 1 ;
}
static int F_24 ( const char * V_57 , struct V_138 * V_139 ,
char * V_21 )
{
char * V_136 ;
sprintf ( V_21 , L_74 , V_139 -> type [ 0 ] ? V_139 -> type : L_1 ,
V_139 -> V_140 [ 0 ] ? V_139 -> V_140 : L_1 ) ;
for ( V_136 = V_21 ; V_136 && * V_136 ; V_136 ++ )
if ( isspace ( * V_136 ) )
* V_136 = '_' ;
F_1 ( V_21 ) ;
return 1 ;
}
static void F_25 ( char * V_21 ,
T_2 * V_141 , unsigned int V_142 , unsigned int V_18 )
{
unsigned int V_8 ;
for ( V_8 = V_142 ; V_8 < V_18 ; V_8 ++ )
if ( V_141 [ V_8 / V_143 ] & ( 1L << ( V_8 % V_143 ) ) )
sprintf ( V_21 + strlen ( V_21 ) , L_75 , V_8 ) ;
}
static int F_26 ( const char * V_57 , struct V_144 * V_13 ,
char * V_21 )
{
sprintf ( V_21 , L_76 ) ;
F_5 ( V_21 , L_32 , V_13 -> V_145 & V_146 , V_13 -> V_147 ) ;
F_5 ( V_21 , L_13 , V_13 -> V_145 & V_148 , V_13 -> V_61 ) ;
F_5 ( V_21 , L_14 , V_13 -> V_145 & V_149 , V_13 -> V_62 ) ;
F_5 ( V_21 , L_77 , V_13 -> V_145 & V_150 , V_13 -> V_70 ) ;
sprintf ( V_21 + strlen ( V_21 ) , L_78 ) ;
if ( V_13 -> V_145 & V_151 )
F_25 ( V_21 , V_13 -> V_152 , 0 , V_153 ) ;
sprintf ( V_21 + strlen ( V_21 ) , L_79 ) ;
if ( V_13 -> V_145 & V_154 )
F_25 ( V_21 , V_13 -> V_155 ,
V_156 ,
V_157 ) ;
sprintf ( V_21 + strlen ( V_21 ) , L_80 ) ;
if ( V_13 -> V_145 & V_158 )
F_25 ( V_21 , V_13 -> V_159 , 0 , V_160 ) ;
sprintf ( V_21 + strlen ( V_21 ) , L_81 ) ;
if ( V_13 -> V_145 & V_161 )
F_25 ( V_21 , V_13 -> V_162 , 0 , V_163 ) ;
sprintf ( V_21 + strlen ( V_21 ) , L_82 ) ;
if ( V_13 -> V_145 & V_164 )
F_25 ( V_21 , V_13 -> V_165 , 0 , V_166 ) ;
sprintf ( V_21 + strlen ( V_21 ) , L_83 ) ;
if ( V_13 -> V_145 & V_167 )
F_25 ( V_21 , V_13 -> V_168 , 0 , V_169 ) ;
sprintf ( V_21 + strlen ( V_21 ) , L_84 ) ;
if ( V_13 -> V_145 & V_170 )
F_25 ( V_21 , V_13 -> V_171 , 0 , V_172 ) ;
sprintf ( V_21 + strlen ( V_21 ) , L_85 ) ;
if ( V_13 -> V_145 & V_173 )
F_25 ( V_21 , V_13 -> V_174 , 0 , V_175 ) ;
sprintf ( V_21 + strlen ( V_21 ) , L_86 ) ;
if ( V_13 -> V_145 & V_176 )
F_25 ( V_21 , V_13 -> V_177 , 0 , V_178 ) ;
return 1 ;
}
static int F_27 ( const char * V_57 , struct V_179 * V_180 ,
char * V_21 )
{
if ( V_180 -> V_181 [ 0 ] )
sprintf ( V_21 , V_182 L_1 , V_180 -> V_181 ) ;
else
strcat ( V_21 , L_1 ) ;
return 1 ;
}
static int F_28 ( const char * V_57 , struct V_183 * V_13 ,
char * V_21 )
{
V_13 -> V_184 = F_9 ( V_13 -> V_184 ) ;
V_13 -> V_185 = F_9 ( V_13 -> V_185 ) ;
V_13 -> V_186 = F_9 ( V_13 -> V_186 ) ;
V_13 -> V_187 = F_9 ( V_13 -> V_187 ) ;
strcpy ( V_21 , L_87 ) ;
F_5 ( V_21 , L_47 , V_13 -> V_184 != V_188 , V_13 -> V_184 ) ;
F_5 ( V_21 , L_88 , V_13 -> V_185 != V_189 , V_13 -> V_185 ) ;
F_5 ( V_21 , L_89 , V_13 -> V_186 != V_190 , V_13 -> V_186 ) ;
F_5 ( V_21 , L_40 , V_13 -> V_187 != V_191 , V_13 -> V_187 ) ;
F_1 ( V_21 ) ;
return 1 ;
}
static int F_29 ( const char * V_57 ,
struct V_192 * V_13 , char * V_21 )
{
V_13 -> V_85 = F_9 ( V_13 -> V_85 ) ;
V_13 -> V_61 = F_9 ( V_13 -> V_61 ) ;
V_13 -> V_82 = F_9 ( V_13 -> V_82 ) ;
strcpy ( V_21 , L_90 ) ;
F_5 ( V_21 , L_63 , V_13 -> V_85 != ( V_193 ) V_194 , V_13 -> V_85 ) ;
F_5 ( V_21 , L_13 , V_13 -> V_61 != ( V_195 ) V_194 , V_13 -> V_61 ) ;
F_5 ( V_21 , L_15 , V_13 -> V_82 != ( V_195 ) V_194 , V_13 -> V_82 ) ;
F_1 ( V_21 ) ;
return 1 ;
}
static int F_30 ( const char * V_57 ,
struct V_196 * V_13 , char * V_21 )
{
V_13 -> V_61 = F_9 ( V_13 -> V_61 ) ;
V_13 -> V_197 = F_9 ( V_13 -> V_197 ) ;
V_13 -> V_198 = F_9 ( V_13 -> V_198 ) ;
strcpy ( V_21 , L_91 ) ;
F_5 ( V_21 , L_13 , V_13 -> V_61 != V_199 , V_13 -> V_61 ) ;
F_5 ( V_21 , L_56 , V_13 -> V_197 != V_200 , V_13 -> V_197 ) ;
F_5 ( V_21 , L_89 , V_13 -> V_198 != V_201 , V_13 -> V_198 ) ;
F_1 ( V_21 ) ;
return 1 ;
}
static int F_31 ( const char * V_57 ,
struct V_202 * V_13 , char * V_21 )
{
V_13 -> V_203 = F_9 ( V_13 -> V_203 ) ;
V_13 -> V_13 = F_9 ( V_13 -> V_13 ) ;
V_13 -> V_204 = F_9 ( V_13 -> V_204 ) ;
V_13 -> V_85 = F_9 ( V_13 -> V_85 ) ;
strcpy ( V_21 , L_92 ) ;
F_5 ( V_21 , L_48 , V_13 -> V_203 != V_205 , V_13 -> V_203 ) ;
F_5 ( V_21 , L_56 , V_13 -> V_13 != V_206 , V_13 -> V_13 ) ;
F_5 ( V_21 , L_89 , V_13 -> V_204 != V_207 , V_13 -> V_204 ) ;
F_5 ( V_21 , L_93 , V_13 -> V_85 != V_208 , V_13 -> V_85 ) ;
F_1 ( V_21 ) ;
return 1 ;
}
static int F_32 ( const char * V_57 , struct V_209 * V_13 ,
char * V_21 )
{
V_13 -> V_82 = F_9 ( V_13 -> V_82 ) ;
V_13 -> V_61 = F_9 ( V_13 -> V_61 ) ;
strcpy ( V_21 , L_94 ) ;
F_5 ( V_21 , L_15 , V_13 -> V_82 != V_210 , V_13 -> V_82 ) ;
F_5 ( V_21 , L_13 , V_13 -> V_61 != V_210 , V_13 -> V_61 ) ;
F_1 ( V_21 ) ;
return 1 ;
}
static int F_33 ( const char * V_57 , struct V_211 * V_13 ,
char * V_21 )
{
int V_8 ;
char V_212 [ ( ( sizeof( V_13 -> V_213 ) + 1 ) ) * 2 ] ;
for ( V_8 = 0 ; V_8 < ( sizeof( V_13 -> V_213 ) * 2 ) ; V_8 += 2 )
sprintf ( & V_212 [ V_8 ] , L_95 , V_13 -> V_213 [ V_8 / 2 ] ) ;
strcpy ( V_21 , L_96 ) ;
strcat ( V_21 , V_212 ) ;
return 1 ;
}
static int F_34 ( const char * V_57 , struct V_214 * V_13 ,
char * V_21 )
{
sprintf ( V_21 , V_215 L_97 , V_13 -> V_56 ) ;
return 1 ;
}
static int F_35 ( const char * V_57 , struct V_216 * V_13 ,
char * V_21 )
{
sprintf ( V_21 , V_217 L_97 , V_13 -> V_56 ) ;
return 1 ;
}
static void F_36 ( char * V_218 , const char * V_219 )
{
for (; * V_219 ; V_219 ++ )
if ( * V_219 > ' ' && * V_219 < 127 && * V_219 != ':' )
* ( V_218 ++ ) = * V_219 ;
* V_218 = 0 ;
}
static int F_37 ( const char * V_57 , struct V_220 * V_13 ,
char * V_21 )
{
int V_8 , V_45 ;
sprintf ( V_21 , L_98 ) ;
for ( V_8 = 0 ; V_8 < F_38 ( V_221 ) ; V_8 ++ ) {
for ( V_45 = 0 ; V_45 < 4 ; V_45 ++ ) {
if ( V_13 -> V_222 [ V_45 ] . V_223 &&
V_13 -> V_222 [ V_45 ] . V_223 == V_221 [ V_8 ] . V_224 ) {
sprintf ( V_21 + strlen ( V_21 ) , L_99 ,
V_221 [ V_8 ] . V_225 ) ;
F_36 ( V_21 + strlen ( V_21 ) ,
V_13 -> V_222 [ V_45 ] . V_226 ) ;
strcat ( V_21 , L_1 ) ;
}
}
}
strcat ( V_21 , L_100 ) ;
return 1 ;
}
static int F_39 ( const char * V_57 ,
struct V_227 * V_13 , char * V_21 )
{
sprintf ( V_21 , V_228 L_97 , V_13 -> V_56 ) ;
return 1 ;
}
static int F_40 ( const char * V_57 ,
struct V_229 * V_13 , char * V_21 )
{
int V_8 ;
V_21 += sprintf ( V_21 , V_230 ) ;
for ( V_8 = 0 ; V_8 < 32 ; V_8 ++ ) {
if ( ! ( ( V_13 -> V_231 >> ( 31 - V_8 ) ) & 1 ) )
* ( V_21 ++ ) = '?' ;
else if ( ( V_13 -> V_232 >> ( 31 - V_8 ) ) & 1 )
* ( V_21 ++ ) = '1' ;
else
* ( V_21 ++ ) = '0' ;
}
* V_21 = 0 ;
return 1 ;
}
static int F_41 ( const char * V_57 , struct V_233 * V_13 ,
char * V_21 )
{
V_13 -> V_13 = F_9 ( V_13 -> V_13 ) ;
strcpy ( V_21 , L_101 ) ;
F_5 ( V_21 , L_45 , V_13 -> V_13 != V_234 , V_13 -> V_13 ) ;
return 1 ;
}
static int F_42 ( const char * V_57 ,
struct V_235 * V_13 , char * V_21 )
{
sprintf ( V_21 , L_102 ,
'A' + ( ( V_13 -> V_61 >> 2 ) & 0x3f ) - 1 ,
'A' + ( ( ( V_13 -> V_61 & 3 ) << 3 ) | ( ( V_13 -> V_61 >> 13 ) & 7 ) ) - 1 ,
'A' + ( ( V_13 -> V_61 >> 8 ) & 0x1f ) - 1 ,
( V_13 -> V_122 >> 4 ) & 0x0f , V_13 -> V_122 & 0x0f ,
( V_13 -> V_122 >> 12 ) & 0x0f , ( V_13 -> V_122 >> 8 ) & 0x0f ) ;
return 1 ;
}
static void F_43 ( char * * V_236 ,
unsigned int V_237 , unsigned int V_238 )
{
char * V_239 = * V_236 ;
unsigned int V_8 ;
switch ( V_238 ) {
case 0 :
* V_239 ++ = '?' ;
break;
case 0xf :
V_239 += sprintf ( V_239 , L_17 , V_237 ) ;
break;
default:
* V_239 ++ = '[' ;
for ( V_8 = 0 ; V_8 < 0x10 ; V_8 ++ )
if ( ( V_8 & V_238 ) == V_237 )
V_239 += sprintf ( V_239 , L_17 , V_8 ) ;
* V_239 ++ = ']' ;
}
* V_239 = '\0' ;
* V_236 = V_239 ;
}
static int F_44 ( const char * V_57 ,
struct V_240 * V_13 , char * V_21 )
{
unsigned int V_241 ;
char * V_239 = V_21 ;
if ( ( V_13 -> V_13 & V_13 -> V_238 ) != V_13 -> V_13 )
F_3 ( L_103
L_104 ,
V_57 , V_13 -> V_13 , V_13 -> V_238 ) ;
V_239 += sprintf ( V_21 , L_105 ) ;
for ( V_241 = 0 ; V_241 < 8 ; V_241 ++ )
F_43 ( & V_239 ,
( V_13 -> V_13 >> ( 4 * ( 7 - V_241 ) ) ) & 0xf ,
( V_13 -> V_238 >> ( 4 * ( 7 - V_241 ) ) ) & 0xf ) ;
return 1 ;
}
static int F_45 ( const char * V_57 , struct V_242 * V_13 ,
char * V_21 )
{
V_13 -> V_243 = F_9 ( V_13 -> V_243 ) ;
V_13 -> V_244 = F_9 ( V_13 -> V_244 ) ;
V_13 -> V_245 = F_9 ( V_13 -> V_245 ) ;
V_13 -> V_61 = F_9 ( V_13 -> V_61 ) ;
strcpy ( V_21 , L_106 ) ;
F_5 ( V_21 , L_107 , V_13 -> V_61 != V_246 , V_13 -> V_61 ) ;
F_5 ( V_21 , L_108 , V_13 -> V_244 != V_247 , V_13 -> V_244 ) ;
F_5 ( V_21 , L_109 , V_13 -> V_245 != V_248 , V_13 -> V_245 ) ;
strcat ( V_21 , L_110 ) ;
if ( V_13 -> V_243 != V_249 )
sprintf ( V_21 + strlen ( V_21 ) , L_111 , V_13 -> V_243 ) ;
return 1 ;
}
static bool F_46 ( const char * V_56 , unsigned V_250 , const char * V_251 )
{
if ( V_250 != strlen ( V_251 ) )
return false ;
return memcmp ( V_56 , V_251 , V_250 ) == 0 ;
}
static void F_47 ( void * V_7 , unsigned long V_5 ,
unsigned long V_6 ,
const char * V_4 ,
void * V_122 ,
struct V_19 * V_20 )
{
unsigned int V_8 ;
char V_21 [ 500 ] ;
int (* F_48)( const char * , void * V_252 , char * V_21 ) = V_122 ;
F_2 ( V_20 -> V_56 , V_4 , V_5 , V_6 , V_7 ) ;
V_5 -= V_6 ;
for ( V_8 = 0 ; V_8 < V_5 ; V_8 += V_6 ) {
if ( F_48 ( V_20 -> V_56 , V_7 + V_8 , V_21 ) ) {
F_6 ( & V_20 -> V_40 ,
L_29 , V_21 ) ;
}
}
}
void F_49 ( struct V_19 * V_20 , struct V_253 * V_254 ,
T_3 * V_255 , const char * V_256 )
{
void * V_7 ;
char * V_257 = NULL ;
const char * V_56 ;
unsigned int V_250 ;
if ( ! V_255 -> V_258 || F_50 ( V_254 , V_255 ) >= V_254 -> V_259 )
return;
if ( F_51 ( V_255 -> V_260 ) != V_261 )
return;
V_56 = strstr ( V_256 , L_112 ) ;
if ( ! V_56 )
return;
V_56 += strlen ( L_112 ) ;
V_250 = strlen ( V_56 ) ;
if ( V_250 < strlen ( L_113 ) )
return;
if ( strcmp ( V_56 + V_250 - strlen ( L_113 ) , L_113 ) )
return;
V_250 -= strlen ( L_113 ) ;
if ( V_254 -> V_262 [ F_50 ( V_254 , V_255 ) ] . V_263 & V_264 ) {
V_257 = calloc ( 1 , V_255 -> V_265 ) ;
V_7 = V_257 ;
} else {
V_7 = ( void * ) V_254 -> V_266
+ V_254 -> V_262 [ F_50 ( V_254 , V_255 ) ] . V_267
+ V_255 -> V_268 ;
}
if ( F_46 ( V_56 , V_250 , L_30 ) )
F_10 ( V_7 , V_255 -> V_265 , V_20 ) ;
else if ( F_46 ( V_56 , V_250 , L_59 ) )
F_20 ( V_7 , V_255 -> V_265 , V_20 ) ;
else if ( F_46 ( V_56 , V_250 , L_114 ) )
F_21 ( V_7 , V_255 -> V_265 , V_20 ) ;
else {
struct V_269 * * V_239 ;
F_52 ( V_270 ) ;
for ( V_239 = V_271 ; V_239 < V_272 ; V_239 ++ ) {
if ( F_46 ( V_56 , V_250 , ( * V_239 ) -> V_4 ) ) {
F_47 ( V_7 , V_255 -> V_265 , ( * V_239 ) -> V_6 ,
( * V_239 ) -> V_4 , ( * V_239 ) -> V_122 , V_20 ) ;
break;
}
}
}
free ( V_257 ) ;
}
void F_53 ( struct V_273 * V_274 , struct V_19 * V_20 )
{
F_6 ( V_274 , L_9 ) ;
F_54 ( V_274 , V_20 -> V_40 . V_239 , V_20 -> V_40 . V_275 ) ;
free ( V_20 -> V_40 . V_239 ) ;
}
