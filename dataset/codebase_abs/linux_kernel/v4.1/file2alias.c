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
F_3 ( L_2
L_3
L_4
L_5
L_6 ,
V_3 , V_4 , V_6 , V_4 , V_5 , V_4 ) ;
}
for ( V_8 = 0 ; V_8 < V_6 ; V_8 ++ ) {
if ( * ( V_9 * ) ( V_7 + V_5 - V_6 + V_8 ) ) {
fprintf ( V_10 , L_7
L_8 ,
V_3 , V_4 , V_6 , V_5 / V_6 ) ;
for ( V_8 = 0 ; V_8 < V_6 ; V_8 ++ )
fprintf ( V_10 , L_9 ,
* ( V_9 * ) ( V_7 + V_5 - V_6 + V_8 ) ) ;
fprintf ( V_10 , L_10 ) ;
F_3 ( L_11
L_12 , V_3 , V_4 ) ;
}
}
}
static void F_4 ( void * V_7 ,
unsigned int V_11 , int V_12 ,
unsigned char V_13 , unsigned char V_14 ,
unsigned char V_15 , struct V_16 * V_17 )
{
char V_18 [ 500 ] ;
F_5 ( V_7 , V_19 , V_20 ) ;
F_5 ( V_7 , V_19 , V_21 ) ;
F_5 ( V_7 , V_19 , V_22 ) ;
F_5 ( V_7 , V_19 , V_23 ) ;
F_5 ( V_7 , V_19 , V_24 ) ;
F_5 ( V_7 , V_19 , V_25 ) ;
F_5 ( V_7 , V_19 , V_26 ) ;
F_5 ( V_7 , V_19 , V_27 ) ;
F_5 ( V_7 , V_19 , V_28 ) ;
F_5 ( V_7 , V_19 , V_29 ) ;
F_5 ( V_7 , V_19 , V_30 ) ;
strcpy ( V_18 , L_13 ) ;
F_6 ( V_18 , L_14 , V_20 & V_31 ,
V_21 ) ;
F_6 ( V_18 , L_15 , V_20 & V_32 ,
V_22 ) ;
strcat ( V_18 , L_16 ) ;
if ( V_12 )
sprintf ( V_18 + strlen ( V_18 ) , L_17 ,
V_12 , V_11 ) ;
if ( V_13 == V_14 )
sprintf ( V_18 + strlen ( V_18 ) , L_18 , V_13 ) ;
else if ( V_13 > 0 || V_14 < V_15 ) {
if ( V_13 > 0x9 || V_14 < 0xA )
sprintf ( V_18 + strlen ( V_18 ) ,
L_19 ,
V_13 ,
V_14 ) ;
else {
sprintf ( V_18 + strlen ( V_18 ) ,
V_13 < 0x9 ? L_20 : L_21 ,
V_13 ) ;
sprintf ( V_18 + strlen ( V_18 ) ,
V_14 > 0xA ? L_22 : L_23 ,
V_14 ) ;
}
}
if ( V_12 < ( sizeof( V_23 ) * 2 - 1 ) )
strcat ( V_18 , L_1 ) ;
F_6 ( V_18 , L_24 , V_20 & V_33 ,
V_24 ) ;
F_6 ( V_18 , L_25 , V_20 & V_34 ,
V_25 ) ;
F_6 ( V_18 , L_26 , V_20 & V_35 ,
V_26 ) ;
F_6 ( V_18 , L_27 , V_20 & V_36 ,
V_27 ) ;
F_6 ( V_18 , L_28 , V_20 & V_37 ,
V_28 ) ;
F_6 ( V_18 , L_29 , V_20 & V_38 ,
V_29 ) ;
F_6 ( V_18 , L_30 , V_20 & V_39 ,
V_30 ) ;
F_1 ( V_18 ) ;
F_7 ( & V_17 -> V_40 ,
L_31 , V_18 ) ;
}
static unsigned int F_8 ( unsigned int * V_41 ,
int V_42 ,
unsigned char V_15 ,
T_1 V_43 )
{
unsigned int V_44 = * V_41 , V_8 , V_45 ;
unsigned long long V_46 , V_47 = 0 ;
if ( V_15 > 0x9 ) {
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
static void F_9 ( void * V_7 , struct V_16 * V_17 )
{
unsigned int V_48 , V_49 ;
unsigned char V_50 , V_51 , V_15 ;
int V_52 ;
F_5 ( V_7 , V_19 , V_20 ) ;
F_5 ( V_7 , V_19 , V_21 ) ;
F_5 ( V_7 , V_19 , V_22 ) ;
F_5 ( V_7 , V_19 , V_23 ) ;
F_5 ( V_7 , V_19 , V_53 ) ;
F_5 ( V_7 , V_19 , V_24 ) ;
F_5 ( V_7 , V_19 , V_27 ) ;
V_48 = V_20 & V_54 ?
V_23 : 0x0U ;
V_49 = V_20 & V_55 ?
V_53 : ~ 0x0U ;
V_15 = 0x9 ;
for ( V_52 = 0 ; V_52 < sizeof( V_23 ) * 2 ; V_52 ++ ) {
V_51 = ( V_48 >> ( V_52 << 2 ) ) & 0xf ;
V_50 = ( ( V_49 > 0x9999 ? 0x9999 : V_49 ) >> ( V_52 << 2 ) ) & 0xf ;
if ( V_51 > V_15 || V_50 > V_15 ) {
V_15 = 0xf ;
break;
}
}
if ( ! ( V_21 | V_22 | V_24 | V_27 ) )
return;
for ( V_52 = sizeof( V_23 ) * 2 - 1 ; V_48 <= V_49 ; V_52 -- ) {
V_51 = V_48 & 0xf ;
V_50 = V_49 & 0xf ;
if ( V_50 > V_15 )
V_50 = V_15 ;
V_48 >>= 4 ;
V_49 >>= 4 ;
if ( V_48 == V_49 || ! V_52 ) {
F_4 ( V_7 , V_48 , V_52 , V_51 , V_50 , V_15 , V_17 ) ;
break;
}
if ( V_51 > 0x0 )
F_4 ( V_7 ,
F_8 ( & V_48 , 1 , V_15 ,
sizeof( V_23 ) * 2 ) ,
V_52 , V_51 , V_15 , V_15 , V_17 ) ;
if ( V_50 < V_15 )
F_4 ( V_7 ,
F_8 ( & V_49 , - 1 , V_15 ,
sizeof( V_23 ) * 2 ) ,
V_52 , 0x0 , V_50 , V_15 , V_17 ) ;
}
}
static void F_10 ( void * V_7 , unsigned long V_5 ,
struct V_16 * V_17 )
{
unsigned int V_8 ;
const unsigned long V_6 = V_56 ;
F_2 ( V_17 -> V_57 , L_32 , V_5 , V_6 , V_7 ) ;
V_5 -= V_6 ;
for ( V_8 = 0 ; V_8 < V_5 ; V_8 += V_6 )
F_9 ( V_7 + V_8 , V_17 ) ;
}
static int F_11 ( const char * V_58 ,
void * V_7 , char * V_18 )
{
F_5 ( V_7 , V_59 , V_60 ) ;
F_5 ( V_7 , V_59 , V_61 ) ;
F_5 ( V_7 , V_59 , V_62 ) ;
F_5 ( V_7 , V_59 , V_63 ) ;
sprintf ( V_18 , L_33 ) ;
F_6 ( V_18 , L_34 , V_60 != V_64 , V_60 ) ;
F_6 ( V_18 , L_35 , V_61 != V_65 , V_61 ) ;
F_6 ( V_18 , L_14 , V_62 != V_66 , V_62 ) ;
F_6 ( V_18 , L_15 , V_63 != V_66 , V_63 ) ;
return 1 ;
}
static int F_12 ( const char * V_58 ,
void * V_7 , char * V_18 )
{
F_5 ( V_7 , V_67 , V_20 ) ;
F_5 ( V_7 , V_67 , V_68 ) ;
F_5 ( V_7 , V_67 , V_69 ) ;
F_5 ( V_7 , V_67 , V_70 ) ;
F_5 ( V_7 , V_67 , V_71 ) ;
strcpy ( V_18 , L_36 ) ;
F_6 ( V_18 , L_37 , V_20 & V_72 ,
V_68 ) ;
F_6 ( V_18 , L_38 , V_20 & V_73 ,
V_69 ) ;
F_6 ( V_18 , L_39 , V_20 & V_74 ,
V_70 ) ;
F_6 ( V_18 , L_40 , V_20 & V_75 ,
V_71 ) ;
F_1 ( V_18 ) ;
return 1 ;
}
static int F_13 ( const char * V_58 ,
void * V_7 , char * V_18 )
{
unsigned char V_76 , V_77 , V_78 ,
V_79 , V_80 , V_81 ;
F_5 ( V_7 , V_82 , V_62 ) ;
F_5 ( V_7 , V_82 , V_83 ) ;
F_5 ( V_7 , V_82 , V_84 ) ;
F_5 ( V_7 , V_82 , V_85 ) ;
F_5 ( V_7 , V_82 , V_86 ) ;
F_5 ( V_7 , V_82 , V_87 ) ;
strcpy ( V_18 , L_41 ) ;
F_6 ( V_18 , L_14 , V_62 != V_88 , V_62 ) ;
F_6 ( V_18 , L_16 , V_83 != V_88 , V_83 ) ;
F_6 ( V_18 , L_42 , V_84 != V_88 , V_84 ) ;
F_6 ( V_18 , L_43 , V_85 != V_88 , V_85 ) ;
V_76 = ( V_86 ) >> 16 ;
V_79 = ( V_87 ) >> 16 ;
V_77 = ( V_86 ) >> 8 ;
V_80 = ( V_87 ) >> 8 ;
V_78 = V_86 ;
V_81 = V_87 ;
if ( ( V_79 != 0 && V_79 != 0xFF )
|| ( V_80 != 0 && V_80 != 0xFF )
|| ( V_81 != 0 && V_81 != 0xFF ) ) {
F_14 ( L_44 ,
V_58 , V_87 ) ;
return 0 ;
}
F_6 ( V_18 , L_45 , V_79 == 0xFF , V_76 ) ;
F_6 ( V_18 , L_46 , V_80 == 0xFF , V_77 ) ;
F_6 ( V_18 , L_47 , V_81 == 0xFF , V_78 ) ;
F_1 ( V_18 ) ;
return 1 ;
}
static int F_15 ( const char * V_58 ,
void * V_7 , char * V_18 )
{
F_5 ( V_7 , V_89 , V_20 ) ;
F_5 ( V_7 , V_89 , V_90 ) ;
F_5 ( V_7 , V_89 , V_91 ) ;
F_5 ( V_7 , V_89 , V_92 ) ;
F_5 ( V_7 , V_89 , V_93 ) ;
strcpy ( V_18 , L_48 ) ;
F_6 ( V_18 , L_49 , V_20 & V_94 ,
V_90 ) ;
F_6 ( V_18 , L_50 , V_20 & V_95 ,
V_91 ) ;
F_6 ( V_18 , L_51 , V_20 & V_96 ,
V_92 ) ;
F_6 ( V_18 , L_52 , V_20 & V_97 ,
V_93 ) ;
F_1 ( V_18 ) ;
return 1 ;
}
static int F_16 ( const char * V_58 ,
void * V_7 , char * V_18 )
{
F_5 ( V_7 , V_98 , V_92 ) ;
sprintf ( V_18 , L_53 , V_92 ) ;
return 1 ;
}
static int F_17 ( const char * V_58 ,
void * V_7 , char * V_18 )
{
F_5 ( V_7 , V_99 , type ) ;
sprintf ( V_18 , L_54 , type ) ;
return 1 ;
}
static int F_18 ( const char * V_58 ,
void * V_7 , char * V_18 )
{
F_5 ( V_7 , V_100 , type ) ;
F_5 ( V_7 , V_100 , V_101 ) ;
F_5 ( V_7 , V_100 , V_102 ) ;
F_5 ( V_7 , V_100 , V_103 ) ;
strcpy ( V_18 , L_55 ) ;
F_6 ( V_18 , L_56 , type != V_104 , type ) ;
F_6 ( V_18 , L_57 , V_101 != V_104 , V_101 ) ;
F_6 ( V_18 , L_58 , V_102 != V_104 , V_102 ) ;
F_6 ( V_18 , L_59 , V_103 != V_104 , V_103 ) ;
F_1 ( V_18 ) ;
return 1 ;
}
static int F_19 ( const char * V_58 ,
void * V_7 , char * V_18 )
{
F_20 ( V_7 , V_105 , V_102 ) ;
sprintf ( V_18 , L_60 , * V_102 ) ;
return 1 ;
}
static void F_21 ( void * V_7 , unsigned long V_5 ,
struct V_16 * V_17 )
{
const unsigned long V_6 = V_106 ;
const unsigned int V_107 = ( V_5 / V_6 ) - 1 ;
unsigned int V_8 ;
F_2 ( V_17 -> V_57 , L_61 , V_5 , V_6 , V_7 ) ;
for ( V_8 = 0 ; V_8 < V_107 ; V_8 ++ ) {
F_20 ( V_7 + V_8 * V_6 , V_108 , V_102 ) ;
char V_109 [ sizeof( * V_102 ) ] ;
int V_45 ;
F_7 ( & V_17 -> V_40 ,
L_62 , * V_102 ) ;
for ( V_45 = 0 ; V_45 < sizeof( V_109 ) ; V_45 ++ )
V_109 [ V_45 ] = toupper ( ( * V_102 ) [ V_45 ] ) ;
F_7 ( & V_17 -> V_40 ,
L_63 , V_109 ) ;
}
}
static void F_22 ( void * V_7 , unsigned long V_5 ,
struct V_16 * V_17 )
{
const unsigned long V_6 = V_110 ;
const unsigned int V_107 = ( V_5 / V_6 ) - 1 ;
unsigned int V_8 ;
F_2 ( V_17 -> V_57 , L_61 , V_5 , V_6 , V_7 ) ;
for ( V_8 = 0 ; V_8 < V_107 ; V_8 ++ ) {
unsigned int V_45 ;
F_20 ( V_7 + V_8 * V_6 , V_111 , V_112 ) ;
for ( V_45 = 0 ; V_45 < V_113 ; V_45 ++ ) {
const char * V_102 = ( char * ) ( * V_112 ) [ V_45 ] . V_102 ;
int V_114 , V_115 ;
int V_116 = 0 ;
if ( ! V_102 [ 0 ] )
break;
for ( V_114 = 0 ; V_114 < V_8 && ! V_116 ; V_114 ++ ) {
F_20 ( V_7 + V_114 * V_6 , V_111 , V_112 ) ;
for ( V_115 = 0 ; V_115 < V_113 ; V_115 ++ ) {
const char * V_117 = ( char * ) ( * V_112 ) [ V_115 ] . V_102 ;
if ( ! V_117 [ 0 ] )
break;
if ( ! strcmp ( V_102 , V_117 ) ) {
V_116 = 1 ;
break;
}
}
}
if ( ! V_116 ) {
char V_109 [ V_118 ] ;
int V_119 ;
F_7 ( & V_17 -> V_40 ,
L_62 , V_102 ) ;
for ( V_119 = 0 ; V_119 < sizeof( V_109 ) ; V_119 ++ )
V_109 [ V_119 ] = toupper ( V_102 [ V_119 ] ) ;
F_7 ( & V_17 -> V_40 ,
L_63 , V_109 ) ;
}
}
}
}
static int F_23 ( const char * V_58 ,
void * V_7 , char * V_18 )
{
unsigned int V_8 ;
F_5 ( V_7 , V_120 , V_20 ) ;
F_5 ( V_7 , V_120 , V_121 ) ;
F_5 ( V_7 , V_120 , V_122 ) ;
F_5 ( V_7 , V_120 , V_123 ) ;
F_5 ( V_7 , V_120 , V_124 ) ;
F_5 ( V_7 , V_120 , V_125 ) ;
F_20 ( V_7 , V_120 , V_126 ) ;
for ( V_8 = 0 ; V_8 < 4 ; V_8 ++ ) {
( * V_126 ) [ V_8 ] = F_24 ( ( * V_126 ) [ V_8 ] ) ;
}
strcpy ( V_18 , L_64 ) ;
F_6 ( V_18 , L_50 , V_20 & V_127 ,
V_121 ) ;
F_6 ( V_18 , L_65 , V_20 & V_128 ,
V_122 ) ;
F_6 ( V_18 , L_66 , V_20 & V_129 ,
V_123 ) ;
F_6 ( V_18 , L_67 , V_20 & V_130 ,
V_124 ) ;
F_6 ( V_18 , L_68 , V_20 & V_131 ,
V_125 ) ;
F_6 ( V_18 , L_69 , V_20 & V_132 , ( * V_126 ) [ 0 ] ) ;
F_6 ( V_18 , L_70 , V_20 & V_133 , ( * V_126 ) [ 1 ] ) ;
F_6 ( V_18 , L_71 , V_20 & V_134 , ( * V_126 ) [ 2 ] ) ;
F_6 ( V_18 , L_72 , V_20 & V_135 , ( * V_126 ) [ 3 ] ) ;
F_1 ( V_18 ) ;
return 1 ;
}
static int F_25 ( const char * V_58 , void * V_7 , char * V_18 )
{
int V_2 ;
char * V_136 ;
F_20 ( V_7 , V_137 , V_57 ) ;
F_20 ( V_7 , V_137 , type ) ;
F_20 ( V_7 , V_137 , V_138 ) ;
V_2 = sprintf ( V_18 , L_73 , ( * V_57 ) [ 0 ] ? * V_57 : L_1 ,
( * type ) [ 0 ] ? * type : L_1 ) ;
if ( V_138 [ 0 ] )
sprintf ( & V_18 [ V_2 ] , L_74 , ( * type ) [ 0 ] ? L_1 : L_75 ,
* V_138 ) ;
for ( V_136 = V_18 ; V_136 && * V_136 ; V_136 ++ )
if ( isspace ( * V_136 ) )
* V_136 = '_' ;
F_1 ( V_18 ) ;
return 1 ;
}
static int F_26 ( const char * V_58 , void * V_7 ,
char * V_18 )
{
char * V_136 ;
F_20 ( V_7 , V_139 , type ) ;
F_20 ( V_7 , V_139 , V_140 ) ;
sprintf ( V_18 , L_76 , ( * type ) [ 0 ] ? * type : L_1 ,
( * V_140 ) [ 0 ] ? * V_140 : L_1 ) ;
for ( V_136 = V_18 ; V_136 && * V_136 ; V_136 ++ )
if ( isspace ( * V_136 ) )
* V_136 = '_' ;
F_1 ( V_18 ) ;
return 1 ;
}
static void F_27 ( char * V_18 ,
T_2 * V_141 , unsigned int V_142 , unsigned int V_15 )
{
unsigned int V_8 ;
for ( V_8 = V_142 / V_143 ; V_8 < V_15 / V_143 + 1 ; V_8 ++ )
V_141 [ V_8 ] = F_24 ( V_141 [ V_8 ] ) ;
for ( V_8 = V_142 ; V_8 < V_15 ; V_8 ++ )
if ( V_141 [ V_8 / V_143 ] & ( 1L << ( V_8 % V_143 ) ) )
sprintf ( V_18 + strlen ( V_18 ) , L_77 , V_8 ) ;
}
static int F_28 ( const char * V_58 , void * V_7 ,
char * V_18 )
{
F_5 ( V_7 , V_144 , V_145 ) ;
F_5 ( V_7 , V_144 , V_146 ) ;
F_5 ( V_7 , V_144 , V_62 ) ;
F_5 ( V_7 , V_144 , V_63 ) ;
F_5 ( V_7 , V_144 , V_71 ) ;
F_20 ( V_7 , V_144 , V_147 ) ;
F_20 ( V_7 , V_144 , V_148 ) ;
F_20 ( V_7 , V_144 , V_149 ) ;
F_20 ( V_7 , V_144 , V_150 ) ;
F_20 ( V_7 , V_144 , V_151 ) ;
F_20 ( V_7 , V_144 , V_152 ) ;
F_20 ( V_7 , V_144 , V_153 ) ;
F_20 ( V_7 , V_144 , V_154 ) ;
F_20 ( V_7 , V_144 , V_155 ) ;
sprintf ( V_18 , L_78 ) ;
F_6 ( V_18 , L_34 , V_145 & V_156 , V_146 ) ;
F_6 ( V_18 , L_14 , V_145 & V_157 , V_62 ) ;
F_6 ( V_18 , L_15 , V_145 & V_158 , V_63 ) ;
F_6 ( V_18 , L_79 , V_145 & V_159 , V_71 ) ;
sprintf ( V_18 + strlen ( V_18 ) , L_80 ) ;
if ( V_145 & V_160 )
F_27 ( V_18 , * V_147 , 0 , V_161 ) ;
sprintf ( V_18 + strlen ( V_18 ) , L_81 ) ;
if ( V_145 & V_162 )
F_27 ( V_18 , * V_148 ,
V_163 ,
V_164 ) ;
sprintf ( V_18 + strlen ( V_18 ) , L_82 ) ;
if ( V_145 & V_165 )
F_27 ( V_18 , * V_149 , 0 , V_166 ) ;
sprintf ( V_18 + strlen ( V_18 ) , L_83 ) ;
if ( V_145 & V_167 )
F_27 ( V_18 , * V_150 , 0 , V_168 ) ;
sprintf ( V_18 + strlen ( V_18 ) , L_84 ) ;
if ( V_145 & V_169 )
F_27 ( V_18 , * V_151 , 0 , V_170 ) ;
sprintf ( V_18 + strlen ( V_18 ) , L_85 ) ;
if ( V_145 & V_171 )
F_27 ( V_18 , * V_152 , 0 , V_172 ) ;
sprintf ( V_18 + strlen ( V_18 ) , L_86 ) ;
if ( V_145 & V_173 )
F_27 ( V_18 , * V_153 , 0 , V_174 ) ;
sprintf ( V_18 + strlen ( V_18 ) , L_87 ) ;
if ( V_145 & V_175 )
F_27 ( V_18 , * V_154 , 0 , V_176 ) ;
sprintf ( V_18 + strlen ( V_18 ) , L_88 ) ;
if ( V_145 & V_177 )
F_27 ( V_18 , * V_155 , 0 , V_178 ) ;
return 1 ;
}
static int F_29 ( const char * V_58 , void * V_7 ,
char * V_18 )
{
F_20 ( V_7 , V_179 , V_180 ) ;
if ( V_180 [ 0 ] )
sprintf ( V_18 , V_181 L_1 , * V_180 ) ;
else
strcat ( V_18 , L_1 ) ;
return 1 ;
}
static int F_30 ( const char * V_58 , void * V_7 ,
char * V_18 )
{
F_5 ( V_7 , V_182 , V_183 ) ;
F_5 ( V_7 , V_182 , V_184 ) ;
F_5 ( V_7 , V_182 , V_185 ) ;
F_5 ( V_7 , V_182 , V_186 ) ;
strcpy ( V_18 , L_89 ) ;
F_6 ( V_18 , L_49 , V_183 != V_187 , V_183 ) ;
F_6 ( V_18 , L_90 , V_184 != V_188 , V_184 ) ;
F_6 ( V_18 , L_91 , V_185 != V_189 , V_185 ) ;
F_6 ( V_18 , L_42 , V_186 != V_190 , V_186 ) ;
F_1 ( V_18 ) ;
return 1 ;
}
static int F_31 ( const char * V_58 ,
void * V_7 , char * V_18 )
{
F_5 ( V_7 , V_191 , V_86 ) ;
F_5 ( V_7 , V_191 , V_62 ) ;
F_5 ( V_7 , V_191 , V_83 ) ;
strcpy ( V_18 , L_92 ) ;
F_6 ( V_18 , L_65 , V_86 != ( V_192 ) V_193 , V_86 ) ;
F_6 ( V_18 , L_14 , V_62 != ( V_194 ) V_193 , V_62 ) ;
F_6 ( V_18 , L_16 , V_83 != ( V_194 ) V_193 , V_83 ) ;
F_1 ( V_18 ) ;
return 1 ;
}
static int F_32 ( const char * V_58 ,
void * V_7 , char * V_18 )
{
F_5 ( V_7 , V_195 , V_62 ) ;
F_5 ( V_7 , V_195 , V_196 ) ;
F_5 ( V_7 , V_195 , V_197 ) ;
strcpy ( V_18 , L_93 ) ;
F_6 ( V_18 , L_14 , V_62 != V_198 , V_62 ) ;
F_6 ( V_18 , L_58 , V_196 != V_199 , V_196 ) ;
F_6 ( V_18 , L_91 , V_197 != V_200 , V_197 ) ;
F_1 ( V_18 ) ;
return 1 ;
}
static int F_33 ( const char * V_58 ,
void * V_7 , char * V_18 )
{
F_5 ( V_7 , V_201 , V_202 ) ;
F_5 ( V_7 , V_201 , V_102 ) ;
F_5 ( V_7 , V_201 , V_203 ) ;
F_5 ( V_7 , V_201 , V_86 ) ;
strcpy ( V_18 , L_94 ) ;
F_6 ( V_18 , L_50 , V_202 != V_204 , V_202 ) ;
F_6 ( V_18 , L_58 , V_102 != V_205 , V_102 ) ;
F_6 ( V_18 , L_91 , V_203 != V_206 , V_203 ) ;
F_6 ( V_18 , L_95 , V_86 != V_207 , V_86 ) ;
F_1 ( V_18 ) ;
return 1 ;
}
static int F_34 ( const char * V_58 , void * V_7 ,
char * V_18 )
{
F_5 ( V_7 , V_208 , V_83 ) ;
F_5 ( V_7 , V_208 , V_62 ) ;
strcpy ( V_18 , L_96 ) ;
F_6 ( V_18 , L_16 , V_83 != V_209 , V_83 ) ;
F_6 ( V_18 , L_14 , V_62 != V_209 , V_62 ) ;
F_1 ( V_18 ) ;
return 1 ;
}
static int F_35 ( const char * V_58 , void * V_7 ,
char * V_18 )
{
int V_8 ;
F_20 ( V_7 , V_210 , V_211 ) ;
char V_212 [ ( sizeof( * V_211 ) + 1 ) * 2 ] ;
for ( V_8 = 0 ; V_8 < ( sizeof( * V_211 ) * 2 ) ; V_8 += 2 )
sprintf ( & V_212 [ V_8 ] , L_97 , F_24 ( ( * V_211 ) [ V_8 / 2 ] ) ) ;
strcpy ( V_18 , L_98 ) ;
strcat ( V_18 , V_212 ) ;
return 1 ;
}
static int F_36 ( const char * V_58 , void * V_7 ,
char * V_18 )
{
F_20 ( V_7 , V_213 , V_57 ) ;
sprintf ( V_18 , V_214 L_99 , * V_57 ) ;
return 1 ;
}
static int F_37 ( const char * V_58 , void * V_7 ,
char * V_18 )
{
F_20 ( V_7 , V_215 , V_57 ) ;
sprintf ( V_18 , V_216 L_99 , * V_57 ) ;
return 1 ;
}
static void F_38 ( char * V_217 , const char * V_218 )
{
for (; * V_218 ; V_218 ++ )
if ( * V_218 > ' ' && * V_218 < 127 && * V_218 != ':' )
* ( V_217 ++ ) = * V_218 ;
* V_217 = 0 ;
}
static int F_39 ( const char * V_58 , void * V_7 ,
char * V_18 )
{
int V_8 , V_45 ;
F_20 ( V_7 , V_219 , V_220 ) ;
sprintf ( V_18 , L_100 ) ;
for ( V_8 = 0 ; V_8 < F_40 ( V_221 ) ; V_8 ++ ) {
for ( V_45 = 0 ; V_45 < 4 ; V_45 ++ ) {
if ( ( * V_220 ) [ V_45 ] . V_222 &&
( * V_220 ) [ V_45 ] . V_222 == V_221 [ V_8 ] . V_223 ) {
sprintf ( V_18 + strlen ( V_18 ) , L_101 ,
V_221 [ V_8 ] . V_224 ) ;
F_38 ( V_18 + strlen ( V_18 ) ,
( * V_220 ) [ V_45 ] . V_225 ) ;
strcat ( V_18 , L_1 ) ;
}
}
}
strcat ( V_18 , L_102 ) ;
return 1 ;
}
static int F_41 ( const char * V_58 ,
void * V_7 , char * V_18 )
{
F_20 ( V_7 , V_226 , V_57 ) ;
sprintf ( V_18 , V_227 L_99 , * V_57 ) ;
return 1 ;
}
static int F_42 ( const char * V_58 ,
void * V_7 , char * V_18 )
{
int V_8 ;
F_5 ( V_7 , V_228 , V_229 ) ;
F_5 ( V_7 , V_228 , V_230 ) ;
V_18 += sprintf ( V_18 , V_231 ) ;
for ( V_8 = 0 ; V_8 < 32 ; V_8 ++ ) {
if ( ! ( ( V_230 >> ( 31 - V_8 ) ) & 1 ) )
* ( V_18 ++ ) = '?' ;
else if ( ( V_229 >> ( 31 - V_8 ) ) & 1 )
* ( V_18 ++ ) = '1' ;
else
* ( V_18 ++ ) = '0' ;
}
* V_18 = 0 ;
return 1 ;
}
static int F_43 ( const char * V_58 , void * V_7 ,
char * V_18 )
{
F_5 ( V_7 , V_232 , V_102 ) ;
strcpy ( V_18 , L_103 ) ;
F_6 ( V_18 , L_47 , V_102 != V_233 , V_102 ) ;
return 1 ;
}
static int F_44 ( const char * V_58 ,
void * V_7 , char * V_18 )
{
F_5 ( V_7 , V_234 , V_62 ) ;
F_5 ( V_7 , V_234 , V_124 ) ;
sprintf ( V_18 , L_104 ,
'A' + ( ( V_62 >> 2 ) & 0x3f ) - 1 ,
'A' + ( ( ( V_62 & 3 ) << 3 ) | ( ( V_62 >> 13 ) & 7 ) ) - 1 ,
'A' + ( ( V_62 >> 8 ) & 0x1f ) - 1 ,
( V_124 >> 4 ) & 0x0f , V_124 & 0x0f ,
( V_124 >> 12 ) & 0x0f , ( V_124 >> 8 ) & 0x0f ) ;
return 1 ;
}
static int F_45 ( const char * V_58 ,
void * V_7 , char * V_18 )
{
F_5 ( V_7 , V_235 , V_236 ) ;
F_5 ( V_7 , V_235 , V_62 ) ;
F_5 ( V_7 , V_235 , V_83 ) ;
strcpy ( V_18 , L_105 ) ;
F_6 ( V_18 , L_66 , V_236 != V_237 , V_236 ) ;
F_6 ( V_18 , L_14 , V_62 != V_238 , V_62 ) ;
F_6 ( V_18 , L_16 , V_83 != V_238 , V_83 ) ;
F_1 ( V_18 ) ;
return 1 ;
}
static void F_46 ( char * * V_239 ,
unsigned int V_240 , unsigned int V_241 )
{
char * V_242 = * V_239 ;
unsigned int V_8 ;
switch ( V_241 ) {
case 0 :
* V_242 ++ = '?' ;
break;
case 0xf :
V_242 += sprintf ( V_242 , L_18 , V_240 ) ;
break;
default:
* V_242 ++ = '[' ;
for ( V_8 = 0 ; V_8 < 0x10 ; V_8 ++ )
if ( ( V_8 & V_241 ) == V_240 )
V_242 += sprintf ( V_242 , L_18 , V_8 ) ;
* V_242 ++ = ']' ;
}
* V_242 = '\0' ;
* V_239 = V_242 ;
}
static int F_47 ( const char * V_58 ,
void * V_7 , char * V_18 )
{
unsigned int V_243 ;
char * V_242 = V_18 ;
F_5 ( V_7 , V_244 , V_102 ) ;
F_5 ( V_7 , V_244 , V_241 ) ;
if ( ( V_102 & V_241 ) != V_102 )
F_3 ( L_106
L_107 ,
V_58 , V_102 , V_241 ) ;
V_242 += sprintf ( V_18 , L_108 ) ;
for ( V_243 = 0 ; V_243 < 8 ; V_243 ++ )
F_46 ( & V_242 ,
( V_102 >> ( 4 * ( 7 - V_243 ) ) ) & 0xf ,
( V_241 >> ( 4 * ( 7 - V_243 ) ) ) & 0xf ) ;
return 1 ;
}
static int F_48 ( const char * V_58 ,
void * V_7 , char * V_18 )
{
F_5 ( V_7 , V_245 , type ) ;
sprintf ( V_18 , L_109 , type ) ;
return 1 ;
}
static int F_49 ( const char * V_58 , void * V_7 ,
char * V_18 )
{
F_5 ( V_7 , V_246 , V_247 ) ;
F_5 ( V_7 , V_246 , V_248 ) ;
F_5 ( V_7 , V_246 , V_249 ) ;
F_5 ( V_7 , V_246 , V_62 ) ;
strcpy ( V_18 , L_110 ) ;
F_6 ( V_18 , L_37 , V_62 != V_250 , V_62 ) ;
F_6 ( V_18 , L_111 , V_248 != V_251 , V_248 ) ;
F_6 ( V_18 , L_112 , V_249 != V_252 , V_249 ) ;
strcat ( V_18 , L_113 ) ;
if ( V_247 != V_253 )
sprintf ( V_18 + strlen ( V_18 ) , L_114 , V_247 ) ;
return 1 ;
}
static int F_50 ( const char * V_58 , void * V_7 , char * V_18 )
{
F_5 ( V_7 , V_254 , V_247 ) ;
sprintf ( V_18 , L_115 , V_247 ) ;
return 1 ;
}
static int F_51 ( const char * V_58 , void * V_7 ,
char * V_18 )
{
F_20 ( V_7 , V_255 , V_57 ) ;
sprintf ( V_18 , V_256 L_99 , * V_57 ) ;
return 1 ;
}
static int F_52 ( const char * V_58 ,
void * V_7 , char * V_18 )
{
F_5 ( V_7 , V_257 , V_258 ) ;
F_5 ( V_7 , V_257 , V_259 ) ;
F_5 ( V_7 , V_257 , V_260 ) ;
F_5 ( V_7 , V_257 , V_261 ) ;
strcpy ( V_18 , L_116 ) ;
F_6 ( V_18 , L_14 , V_259 != V_262 , V_259 ) ;
F_6 ( V_18 , L_16 , V_258 != V_262 , V_258 ) ;
F_6 ( V_18 , L_117 , V_261 != V_262 , V_261 ) ;
F_6 ( V_18 , L_118 , V_260 != V_262 , V_260 ) ;
F_1 ( V_18 ) ;
return 1 ;
}
static bool F_53 ( const char * V_57 , unsigned V_263 , const char * V_264 )
{
if ( V_263 != strlen ( V_264 ) )
return false ;
return memcmp ( V_57 , V_264 , V_263 ) == 0 ;
}
static void F_54 ( void * V_7 , unsigned long V_5 ,
unsigned long V_6 ,
const char * V_4 ,
void * V_124 ,
struct V_16 * V_17 )
{
unsigned int V_8 ;
char V_18 [ 500 ] ;
int (* F_55)( const char * , void * V_265 , char * V_18 ) = V_124 ;
F_2 ( V_17 -> V_57 , V_4 , V_5 , V_6 , V_7 ) ;
V_5 -= V_6 ;
for ( V_8 = 0 ; V_8 < V_5 ; V_8 += V_6 ) {
if ( F_55 ( V_17 -> V_57 , V_7 + V_8 , V_18 ) ) {
F_7 ( & V_17 -> V_40 ,
L_31 , V_18 ) ;
}
}
}
void F_56 ( struct V_16 * V_17 , struct V_266 * V_267 ,
T_3 * V_268 , const char * V_269 )
{
void * V_7 ;
char * V_270 = NULL ;
const char * V_57 , * V_271 ;
unsigned int V_263 ;
if ( ! V_268 -> V_272 || F_57 ( V_267 , V_268 ) >= V_267 -> V_273 )
return;
if ( F_58 ( V_268 -> V_274 ) != V_275 )
return;
V_57 = strstr ( V_269 , L_119 ) ;
if ( ! V_57 )
return;
V_57 += strlen ( L_119 ) ;
V_263 = strlen ( V_57 ) ;
if ( V_263 < strlen ( L_120 ) )
return;
if ( strcmp ( V_57 + V_263 - strlen ( L_120 ) , L_120 ) )
return;
V_271 = strstr ( V_57 , L_121 ) ;
if ( ! V_271 )
return;
V_263 = V_271 - V_57 ;
if ( V_267 -> V_276 [ F_57 ( V_267 , V_268 ) ] . V_277 & V_278 ) {
V_270 = calloc ( 1 , V_268 -> V_279 ) ;
V_7 = V_270 ;
} else {
V_7 = ( void * ) V_267 -> V_280
+ V_267 -> V_276 [ F_57 ( V_267 , V_268 ) ] . V_281
+ V_268 -> V_282 ;
}
if ( F_53 ( V_57 , V_263 , L_32 ) )
F_10 ( V_7 , V_268 -> V_279 , V_17 ) ;
else if ( F_53 ( V_57 , V_263 , L_61 ) )
F_21 ( V_7 , V_268 -> V_279 , V_17 ) ;
else if ( F_53 ( V_57 , V_263 , L_122 ) )
F_22 ( V_7 , V_268 -> V_279 , V_17 ) ;
else {
struct V_283 * * V_242 ;
F_59 ( V_284 ) ;
for ( V_242 = V_285 ; V_242 < V_286 ; V_242 ++ ) {
if ( F_53 ( V_57 , V_263 , ( * V_242 ) -> V_4 ) ) {
F_54 ( V_7 , V_268 -> V_279 , ( * V_242 ) -> V_6 ,
( * V_242 ) -> V_4 , ( * V_242 ) -> V_124 , V_17 ) ;
break;
}
}
}
free ( V_270 ) ;
}
void F_60 ( struct V_287 * V_288 , struct V_16 * V_17 )
{
F_7 ( V_288 , L_10 ) ;
F_61 ( V_288 , V_17 -> V_40 . V_242 , V_17 -> V_40 . V_289 ) ;
free ( V_17 -> V_40 . V_242 ) ;
}
