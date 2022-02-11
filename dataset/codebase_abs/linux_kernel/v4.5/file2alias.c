static inline void F_1 ( char * V_1 )
{
int V_2 = strlen ( V_1 ) ;
if ( V_1 [ V_2 - 1 ] != '*' )
strcat ( V_1 + V_2 , L_1 ) ;
}
static inline void F_2 ( char * V_1 , T_1 V_3 )
{
int V_2 = strlen ( V_1 ) ;
sprintf ( V_1 + V_2 , L_2 ,
V_3 . V_4 [ 3 ] , V_3 . V_4 [ 2 ] , V_3 . V_4 [ 1 ] , V_3 . V_4 [ 0 ] ,
V_3 . V_4 [ 5 ] , V_3 . V_4 [ 4 ] , V_3 . V_4 [ 7 ] , V_3 . V_4 [ 6 ] ,
V_3 . V_4 [ 8 ] , V_3 . V_4 [ 9 ] , V_3 . V_4 [ 10 ] , V_3 . V_4 [ 11 ] ,
V_3 . V_4 [ 12 ] , V_3 . V_4 [ 13 ] , V_3 . V_4 [ 14 ] , V_3 . V_4 [ 15 ] ) ;
}
static void F_3 ( const char * V_5 , const char * V_6 ,
unsigned long V_7 , unsigned long V_8 ,
void * V_9 )
{
int V_10 ;
if ( V_7 % V_8 || V_7 < V_8 ) {
F_4 ( L_3
L_4
L_5
L_6
L_7 ,
V_5 , V_6 , V_8 , V_6 , V_7 , V_6 ) ;
}
for ( V_10 = 0 ; V_10 < V_8 ; V_10 ++ ) {
if ( * ( V_11 * ) ( V_9 + V_7 - V_8 + V_10 ) ) {
fprintf ( V_12 , L_8
L_9 ,
V_5 , V_6 , V_8 , V_7 / V_8 ) ;
for ( V_10 = 0 ; V_10 < V_8 ; V_10 ++ )
fprintf ( V_12 , L_10 ,
* ( V_11 * ) ( V_9 + V_7 - V_8 + V_10 ) ) ;
fprintf ( V_12 , L_11 ) ;
F_4 ( L_12
L_13 , V_5 , V_6 ) ;
}
}
}
static void F_5 ( void * V_9 ,
unsigned int V_13 , int V_14 ,
unsigned char V_15 , unsigned char V_16 ,
unsigned char V_17 , struct V_18 * V_19 )
{
char V_20 [ 500 ] ;
F_6 ( V_9 , V_21 , V_22 ) ;
F_6 ( V_9 , V_21 , V_23 ) ;
F_6 ( V_9 , V_21 , V_24 ) ;
F_6 ( V_9 , V_21 , V_25 ) ;
F_6 ( V_9 , V_21 , V_26 ) ;
F_6 ( V_9 , V_21 , V_27 ) ;
F_6 ( V_9 , V_21 , V_28 ) ;
F_6 ( V_9 , V_21 , V_29 ) ;
F_6 ( V_9 , V_21 , V_30 ) ;
F_6 ( V_9 , V_21 , V_31 ) ;
F_6 ( V_9 , V_21 , V_32 ) ;
strcpy ( V_20 , L_14 ) ;
F_7 ( V_20 , L_15 , V_22 & V_33 ,
V_23 ) ;
F_7 ( V_20 , L_16 , V_22 & V_34 ,
V_24 ) ;
strcat ( V_20 , L_17 ) ;
if ( V_14 )
sprintf ( V_20 + strlen ( V_20 ) , L_18 ,
V_14 , V_13 ) ;
if ( V_15 == V_16 )
sprintf ( V_20 + strlen ( V_20 ) , L_19 , V_15 ) ;
else if ( V_15 > 0 || V_16 < V_17 ) {
if ( V_15 > 0x9 || V_16 < 0xA )
sprintf ( V_20 + strlen ( V_20 ) ,
L_20 ,
V_15 ,
V_16 ) ;
else {
sprintf ( V_20 + strlen ( V_20 ) ,
V_15 < 0x9 ? L_21 : L_22 ,
V_15 ) ;
sprintf ( V_20 + strlen ( V_20 ) ,
V_16 > 0xA ? L_23 : L_24 ,
V_16 ) ;
}
}
if ( V_14 < ( sizeof( V_25 ) * 2 - 1 ) )
strcat ( V_20 , L_1 ) ;
F_7 ( V_20 , L_25 , V_22 & V_35 ,
V_26 ) ;
F_7 ( V_20 , L_26 , V_22 & V_36 ,
V_27 ) ;
F_7 ( V_20 , L_27 , V_22 & V_37 ,
V_28 ) ;
F_7 ( V_20 , L_28 , V_22 & V_38 ,
V_29 ) ;
F_7 ( V_20 , L_29 , V_22 & V_39 ,
V_30 ) ;
F_7 ( V_20 , L_30 , V_22 & V_40 ,
V_31 ) ;
F_7 ( V_20 , L_31 , V_22 & V_41 ,
V_32 ) ;
F_1 ( V_20 ) ;
F_8 ( & V_19 -> V_42 ,
L_32 , V_20 ) ;
}
static unsigned int F_9 ( unsigned int * V_43 ,
int V_44 ,
unsigned char V_17 ,
T_2 V_45 )
{
unsigned int V_46 = * V_43 , V_10 , V_47 ;
unsigned long long V_48 , V_49 = 0 ;
if ( V_17 > 0x9 ) {
* V_43 += V_44 ;
return V_46 ;
}
for ( V_10 = 0 ; V_10 < V_45 ; V_10 ++ ) {
V_48 = ( * V_43 >> ( V_10 << 2 ) ) & 0xf ;
V_48 = V_48 > 9 ? 9 : V_48 ;
for ( V_47 = 0 ; V_47 < V_10 ; V_47 ++ )
V_48 = V_48 * 10 ;
V_49 += V_48 ;
}
V_49 += V_44 ;
* V_43 = 0 ;
for ( V_10 = 0 ; V_10 < V_45 ; V_10 ++ ) {
for ( V_48 = 1 , V_47 = 0 ; V_47 < V_10 ; V_47 ++ )
V_48 = V_48 * 10 ;
V_48 = ( V_49 / V_48 ) % 10 ;
* V_43 += V_48 << ( V_10 << 2 ) ;
}
return V_46 ;
}
static void F_10 ( void * V_9 , struct V_18 * V_19 )
{
unsigned int V_50 , V_51 ;
unsigned char V_52 , V_53 , V_17 ;
int V_54 ;
F_6 ( V_9 , V_21 , V_22 ) ;
F_6 ( V_9 , V_21 , V_23 ) ;
F_6 ( V_9 , V_21 , V_24 ) ;
F_6 ( V_9 , V_21 , V_25 ) ;
F_6 ( V_9 , V_21 , V_55 ) ;
F_6 ( V_9 , V_21 , V_26 ) ;
F_6 ( V_9 , V_21 , V_29 ) ;
V_50 = V_22 & V_56 ?
V_25 : 0x0U ;
V_51 = V_22 & V_57 ?
V_55 : ~ 0x0U ;
V_17 = 0x9 ;
for ( V_54 = 0 ; V_54 < sizeof( V_25 ) * 2 ; V_54 ++ ) {
V_53 = ( V_50 >> ( V_54 << 2 ) ) & 0xf ;
V_52 = ( ( V_51 > 0x9999 ? 0x9999 : V_51 ) >> ( V_54 << 2 ) ) & 0xf ;
if ( V_53 > V_17 || V_52 > V_17 ) {
V_17 = 0xf ;
break;
}
}
if ( ! ( V_23 | V_24 | V_26 | V_29 ) )
return;
for ( V_54 = sizeof( V_25 ) * 2 - 1 ; V_50 <= V_51 ; V_54 -- ) {
V_53 = V_50 & 0xf ;
V_52 = V_51 & 0xf ;
if ( V_52 > V_17 )
V_52 = V_17 ;
V_50 >>= 4 ;
V_51 >>= 4 ;
if ( V_50 == V_51 || ! V_54 ) {
F_5 ( V_9 , V_50 , V_54 , V_53 , V_52 , V_17 , V_19 ) ;
break;
}
if ( V_53 > 0x0 )
F_5 ( V_9 ,
F_9 ( & V_50 , 1 , V_17 ,
sizeof( V_25 ) * 2 ) ,
V_54 , V_53 , V_17 , V_17 , V_19 ) ;
if ( V_52 < V_17 )
F_5 ( V_9 ,
F_9 ( & V_51 , - 1 , V_17 ,
sizeof( V_25 ) * 2 ) ,
V_54 , 0x0 , V_52 , V_17 , V_19 ) ;
}
}
static void F_11 ( void * V_9 , unsigned long V_7 ,
struct V_18 * V_19 )
{
unsigned int V_10 ;
const unsigned long V_8 = V_58 ;
F_3 ( V_19 -> V_59 , L_33 , V_7 , V_8 , V_9 ) ;
V_7 -= V_8 ;
for ( V_10 = 0 ; V_10 < V_7 ; V_10 += V_8 )
F_10 ( V_9 + V_10 , V_19 ) ;
}
static int F_12 ( const char * V_60 ,
void * V_9 , char * V_20 )
{
F_6 ( V_9 , V_61 , V_62 ) ;
F_6 ( V_9 , V_61 , V_63 ) ;
F_6 ( V_9 , V_61 , V_64 ) ;
F_6 ( V_9 , V_61 , V_65 ) ;
sprintf ( V_20 , L_34 ) ;
F_7 ( V_20 , L_35 , V_62 != V_66 , V_62 ) ;
F_7 ( V_20 , L_36 , V_63 != V_67 , V_63 ) ;
F_7 ( V_20 , L_15 , V_64 != V_68 , V_64 ) ;
F_7 ( V_20 , L_16 , V_65 != V_68 , V_65 ) ;
return 1 ;
}
static int F_13 ( const char * V_60 ,
void * V_9 , char * V_20 )
{
F_6 ( V_9 , V_69 , V_22 ) ;
F_6 ( V_9 , V_69 , V_70 ) ;
F_6 ( V_9 , V_69 , V_71 ) ;
F_6 ( V_9 , V_69 , V_72 ) ;
F_6 ( V_9 , V_69 , V_73 ) ;
strcpy ( V_20 , L_37 ) ;
F_7 ( V_20 , L_38 , V_22 & V_74 ,
V_70 ) ;
F_7 ( V_20 , L_39 , V_22 & V_75 ,
V_71 ) ;
F_7 ( V_20 , L_40 , V_22 & V_76 ,
V_72 ) ;
F_7 ( V_20 , L_41 , V_22 & V_77 ,
V_73 ) ;
F_1 ( V_20 ) ;
return 1 ;
}
static int F_14 ( const char * V_60 ,
void * V_9 , char * V_20 )
{
unsigned char V_78 , V_79 , V_80 ,
V_81 , V_82 , V_83 ;
F_6 ( V_9 , V_84 , V_64 ) ;
F_6 ( V_9 , V_84 , V_85 ) ;
F_6 ( V_9 , V_84 , V_86 ) ;
F_6 ( V_9 , V_84 , V_87 ) ;
F_6 ( V_9 , V_84 , V_88 ) ;
F_6 ( V_9 , V_84 , V_89 ) ;
strcpy ( V_20 , L_42 ) ;
F_7 ( V_20 , L_15 , V_64 != V_90 , V_64 ) ;
F_7 ( V_20 , L_17 , V_85 != V_90 , V_85 ) ;
F_7 ( V_20 , L_43 , V_86 != V_90 , V_86 ) ;
F_7 ( V_20 , L_44 , V_87 != V_90 , V_87 ) ;
V_78 = ( V_88 ) >> 16 ;
V_81 = ( V_89 ) >> 16 ;
V_79 = ( V_88 ) >> 8 ;
V_82 = ( V_89 ) >> 8 ;
V_80 = V_88 ;
V_83 = V_89 ;
if ( ( V_81 != 0 && V_81 != 0xFF )
|| ( V_82 != 0 && V_82 != 0xFF )
|| ( V_83 != 0 && V_83 != 0xFF ) ) {
F_15 ( L_45 ,
V_60 , V_89 ) ;
return 0 ;
}
F_7 ( V_20 , L_46 , V_81 == 0xFF , V_78 ) ;
F_7 ( V_20 , L_47 , V_82 == 0xFF , V_79 ) ;
F_7 ( V_20 , L_48 , V_83 == 0xFF , V_80 ) ;
F_1 ( V_20 ) ;
return 1 ;
}
static int F_16 ( const char * V_60 ,
void * V_9 , char * V_20 )
{
F_6 ( V_9 , V_91 , V_22 ) ;
F_6 ( V_9 , V_91 , V_92 ) ;
F_6 ( V_9 , V_91 , V_93 ) ;
F_6 ( V_9 , V_91 , V_94 ) ;
F_6 ( V_9 , V_91 , V_95 ) ;
strcpy ( V_20 , L_49 ) ;
F_7 ( V_20 , L_50 , V_22 & V_96 ,
V_92 ) ;
F_7 ( V_20 , L_51 , V_22 & V_97 ,
V_93 ) ;
F_7 ( V_20 , L_52 , V_22 & V_98 ,
V_94 ) ;
F_7 ( V_20 , L_53 , V_22 & V_99 ,
V_95 ) ;
F_1 ( V_20 ) ;
return 1 ;
}
static int F_17 ( const char * V_60 ,
void * V_9 , char * V_20 )
{
F_6 ( V_9 , V_100 , V_94 ) ;
sprintf ( V_20 , L_54 , V_94 ) ;
return 1 ;
}
static int F_18 ( const char * V_60 ,
void * V_9 , char * V_20 )
{
F_6 ( V_9 , V_101 , type ) ;
sprintf ( V_20 , L_55 , type ) ;
return 1 ;
}
static int F_19 ( const char * V_60 ,
void * V_9 , char * V_20 )
{
F_6 ( V_9 , V_102 , type ) ;
F_6 ( V_9 , V_102 , V_103 ) ;
F_6 ( V_9 , V_102 , V_104 ) ;
F_6 ( V_9 , V_102 , V_105 ) ;
strcpy ( V_20 , L_56 ) ;
F_7 ( V_20 , L_57 , type != V_106 , type ) ;
F_7 ( V_20 , L_58 , V_103 != V_106 , V_103 ) ;
F_7 ( V_20 , L_59 , V_104 != V_106 , V_104 ) ;
F_7 ( V_20 , L_60 , V_105 != V_106 , V_105 ) ;
F_1 ( V_20 ) ;
return 1 ;
}
static int F_20 ( const char * V_60 ,
void * V_9 , char * V_20 )
{
F_21 ( V_9 , V_107 , V_104 ) ;
F_21 ( V_9 , V_107 , V_108 ) ;
F_21 ( V_9 , V_107 , V_109 ) ;
if ( V_104 && strlen ( ( const char * ) * V_104 ) )
sprintf ( V_20 , L_61 , * V_104 ) ;
else if ( V_108 ) {
int V_10 , V_110 , V_111 = 0 ;
unsigned int V_112 ;
sprintf ( & V_20 [ V_111 ] , L_62 ) ;
V_111 = 6 ;
for ( V_10 = 1 ; V_10 <= 3 ; V_10 ++ ) {
V_110 = 8 * ( 3 - V_10 ) ;
V_112 = ( * V_109 >> V_110 ) & 0xFF ;
if ( V_112 )
sprintf ( & V_20 [ V_111 ] , L_63 ,
( * V_108 >> V_110 ) & 0xFF ) ;
else
sprintf ( & V_20 [ V_111 ] , L_64 ) ;
V_111 += 2 ;
}
sprintf ( & V_20 [ V_111 ] , L_65 ) ;
}
return 1 ;
}
static void F_22 ( void * V_9 , unsigned long V_7 ,
struct V_18 * V_19 )
{
const unsigned long V_8 = V_113 ;
const unsigned int V_114 = ( V_7 / V_8 ) - 1 ;
unsigned int V_10 ;
F_3 ( V_19 -> V_59 , L_66 , V_7 , V_8 , V_9 ) ;
for ( V_10 = 0 ; V_10 < V_114 ; V_10 ++ ) {
F_21 ( V_9 + V_10 * V_8 , V_115 , V_104 ) ;
char V_116 [ sizeof( * V_104 ) ] ;
int V_47 ;
F_8 ( & V_19 -> V_42 ,
L_67 , * V_104 ) ;
for ( V_47 = 0 ; V_47 < sizeof( V_116 ) ; V_47 ++ )
V_116 [ V_47 ] = toupper ( ( * V_104 ) [ V_47 ] ) ;
F_8 ( & V_19 -> V_42 ,
L_68 , V_116 ) ;
}
}
static void F_23 ( void * V_9 , unsigned long V_7 ,
struct V_18 * V_19 )
{
const unsigned long V_8 = V_117 ;
const unsigned int V_114 = ( V_7 / V_8 ) - 1 ;
unsigned int V_10 ;
F_3 ( V_19 -> V_59 , L_66 , V_7 , V_8 , V_9 ) ;
for ( V_10 = 0 ; V_10 < V_114 ; V_10 ++ ) {
unsigned int V_47 ;
F_21 ( V_9 + V_10 * V_8 , V_118 , V_119 ) ;
for ( V_47 = 0 ; V_47 < V_120 ; V_47 ++ ) {
const char * V_104 = ( char * ) ( * V_119 ) [ V_47 ] . V_104 ;
int V_121 , V_122 ;
int V_123 = 0 ;
if ( ! V_104 [ 0 ] )
break;
for ( V_121 = 0 ; V_121 < V_10 && ! V_123 ; V_121 ++ ) {
F_21 ( V_9 + V_121 * V_8 , V_118 , V_119 ) ;
for ( V_122 = 0 ; V_122 < V_120 ; V_122 ++ ) {
const char * V_124 = ( char * ) ( * V_119 ) [ V_122 ] . V_104 ;
if ( ! V_124 [ 0 ] )
break;
if ( ! strcmp ( V_104 , V_124 ) ) {
V_123 = 1 ;
break;
}
}
}
if ( ! V_123 ) {
char V_116 [ V_125 ] ;
int V_126 ;
F_8 ( & V_19 -> V_42 ,
L_67 , V_104 ) ;
for ( V_126 = 0 ; V_126 < sizeof( V_116 ) ; V_126 ++ )
V_116 [ V_126 ] = toupper ( V_104 [ V_126 ] ) ;
F_8 ( & V_19 -> V_42 ,
L_68 , V_116 ) ;
}
}
}
}
static int F_24 ( const char * V_60 ,
void * V_9 , char * V_20 )
{
unsigned int V_10 ;
F_6 ( V_9 , V_127 , V_22 ) ;
F_6 ( V_9 , V_127 , V_128 ) ;
F_6 ( V_9 , V_127 , V_129 ) ;
F_6 ( V_9 , V_127 , V_130 ) ;
F_6 ( V_9 , V_127 , V_131 ) ;
F_6 ( V_9 , V_127 , V_132 ) ;
F_21 ( V_9 , V_127 , V_133 ) ;
for ( V_10 = 0 ; V_10 < 4 ; V_10 ++ ) {
( * V_133 ) [ V_10 ] = F_25 ( ( * V_133 ) [ V_10 ] ) ;
}
strcpy ( V_20 , L_69 ) ;
F_7 ( V_20 , L_51 , V_22 & V_134 ,
V_128 ) ;
F_7 ( V_20 , L_70 , V_22 & V_135 ,
V_129 ) ;
F_7 ( V_20 , L_71 , V_22 & V_136 ,
V_130 ) ;
F_7 ( V_20 , L_72 , V_22 & V_137 ,
V_131 ) ;
F_7 ( V_20 , L_73 , V_22 & V_138 ,
V_132 ) ;
F_7 ( V_20 , L_74 , V_22 & V_139 , ( * V_133 ) [ 0 ] ) ;
F_7 ( V_20 , L_75 , V_22 & V_140 , ( * V_133 ) [ 1 ] ) ;
F_7 ( V_20 , L_76 , V_22 & V_141 , ( * V_133 ) [ 2 ] ) ;
F_7 ( V_20 , L_77 , V_22 & V_142 , ( * V_133 ) [ 3 ] ) ;
F_1 ( V_20 ) ;
return 1 ;
}
static int F_26 ( const char * V_60 , void * V_9 , char * V_20 )
{
int V_2 ;
char * V_143 ;
F_21 ( V_9 , V_144 , V_59 ) ;
F_21 ( V_9 , V_144 , type ) ;
F_21 ( V_9 , V_144 , V_145 ) ;
V_2 = sprintf ( V_20 , L_78 , ( * V_59 ) [ 0 ] ? * V_59 : L_1 ,
( * type ) [ 0 ] ? * type : L_1 ) ;
if ( V_145 [ 0 ] )
sprintf ( & V_20 [ V_2 ] , L_79 , ( * type ) [ 0 ] ? L_1 : L_80 ,
* V_145 ) ;
for ( V_143 = V_20 ; V_143 && * V_143 ; V_143 ++ )
if ( isspace ( * V_143 ) )
* V_143 = '_' ;
return 1 ;
}
static int F_27 ( const char * V_60 , void * V_9 ,
char * V_20 )
{
char * V_143 ;
F_21 ( V_9 , V_146 , type ) ;
F_21 ( V_9 , V_146 , V_147 ) ;
sprintf ( V_20 , L_81 , ( * type ) [ 0 ] ? * type : L_1 ,
( * V_147 ) [ 0 ] ? * V_147 : L_1 ) ;
for ( V_143 = V_20 ; V_143 && * V_143 ; V_143 ++ )
if ( isspace ( * V_143 ) )
* V_143 = '_' ;
F_1 ( V_20 ) ;
return 1 ;
}
static void F_28 ( char * V_20 ,
T_3 * V_148 , unsigned int V_149 , unsigned int V_17 )
{
unsigned int V_10 ;
for ( V_10 = V_149 / V_150 ; V_10 < V_17 / V_150 + 1 ; V_10 ++ )
V_148 [ V_10 ] = F_25 ( V_148 [ V_10 ] ) ;
for ( V_10 = V_149 ; V_10 < V_17 ; V_10 ++ )
if ( V_148 [ V_10 / V_150 ] & ( 1L << ( V_10 % V_150 ) ) )
sprintf ( V_20 + strlen ( V_20 ) , L_82 , V_10 ) ;
}
static int F_29 ( const char * V_60 , void * V_9 ,
char * V_20 )
{
F_6 ( V_9 , V_151 , V_152 ) ;
F_6 ( V_9 , V_151 , V_153 ) ;
F_6 ( V_9 , V_151 , V_64 ) ;
F_6 ( V_9 , V_151 , V_65 ) ;
F_6 ( V_9 , V_151 , V_73 ) ;
F_21 ( V_9 , V_151 , V_154 ) ;
F_21 ( V_9 , V_151 , V_155 ) ;
F_21 ( V_9 , V_151 , V_156 ) ;
F_21 ( V_9 , V_151 , V_157 ) ;
F_21 ( V_9 , V_151 , V_158 ) ;
F_21 ( V_9 , V_151 , V_159 ) ;
F_21 ( V_9 , V_151 , V_160 ) ;
F_21 ( V_9 , V_151 , V_161 ) ;
F_21 ( V_9 , V_151 , V_162 ) ;
sprintf ( V_20 , L_83 ) ;
F_7 ( V_20 , L_35 , V_152 & V_163 , V_153 ) ;
F_7 ( V_20 , L_15 , V_152 & V_164 , V_64 ) ;
F_7 ( V_20 , L_16 , V_152 & V_165 , V_65 ) ;
F_7 ( V_20 , L_84 , V_152 & V_166 , V_73 ) ;
sprintf ( V_20 + strlen ( V_20 ) , L_85 ) ;
if ( V_152 & V_167 )
F_28 ( V_20 , * V_154 , 0 , V_168 ) ;
sprintf ( V_20 + strlen ( V_20 ) , L_86 ) ;
if ( V_152 & V_169 )
F_28 ( V_20 , * V_155 ,
V_170 ,
V_171 ) ;
sprintf ( V_20 + strlen ( V_20 ) , L_87 ) ;
if ( V_152 & V_172 )
F_28 ( V_20 , * V_156 , 0 , V_173 ) ;
sprintf ( V_20 + strlen ( V_20 ) , L_88 ) ;
if ( V_152 & V_174 )
F_28 ( V_20 , * V_157 , 0 , V_175 ) ;
sprintf ( V_20 + strlen ( V_20 ) , L_89 ) ;
if ( V_152 & V_176 )
F_28 ( V_20 , * V_158 , 0 , V_177 ) ;
sprintf ( V_20 + strlen ( V_20 ) , L_90 ) ;
if ( V_152 & V_178 )
F_28 ( V_20 , * V_159 , 0 , V_179 ) ;
sprintf ( V_20 + strlen ( V_20 ) , L_91 ) ;
if ( V_152 & V_180 )
F_28 ( V_20 , * V_160 , 0 , V_181 ) ;
sprintf ( V_20 + strlen ( V_20 ) , L_92 ) ;
if ( V_152 & V_182 )
F_28 ( V_20 , * V_161 , 0 , V_183 ) ;
sprintf ( V_20 + strlen ( V_20 ) , L_93 ) ;
if ( V_152 & V_184 )
F_28 ( V_20 , * V_162 , 0 , V_185 ) ;
return 1 ;
}
static int F_30 ( const char * V_60 , void * V_9 ,
char * V_20 )
{
F_21 ( V_9 , V_186 , V_187 ) ;
if ( V_187 [ 0 ] )
sprintf ( V_20 , V_188 L_1 , * V_187 ) ;
else
strcat ( V_20 , L_1 ) ;
return 1 ;
}
static int F_31 ( const char * V_60 , void * V_9 ,
char * V_20 )
{
F_6 ( V_9 , V_189 , V_190 ) ;
F_6 ( V_9 , V_189 , V_191 ) ;
F_6 ( V_9 , V_189 , V_192 ) ;
F_6 ( V_9 , V_189 , V_193 ) ;
strcpy ( V_20 , L_94 ) ;
F_7 ( V_20 , L_50 , V_190 != V_194 , V_190 ) ;
F_7 ( V_20 , L_95 , V_191 != V_195 , V_191 ) ;
F_7 ( V_20 , L_96 , V_192 != V_196 , V_192 ) ;
F_7 ( V_20 , L_43 , V_193 != V_197 , V_193 ) ;
F_1 ( V_20 ) ;
return 1 ;
}
static int F_32 ( const char * V_60 ,
void * V_9 , char * V_20 )
{
F_6 ( V_9 , V_198 , V_88 ) ;
F_6 ( V_9 , V_198 , V_64 ) ;
F_6 ( V_9 , V_198 , V_85 ) ;
strcpy ( V_20 , L_97 ) ;
F_7 ( V_20 , L_70 , V_88 != ( V_199 ) V_200 , V_88 ) ;
F_7 ( V_20 , L_15 , V_64 != ( V_201 ) V_200 , V_64 ) ;
F_7 ( V_20 , L_17 , V_85 != ( V_201 ) V_200 , V_85 ) ;
F_1 ( V_20 ) ;
return 1 ;
}
static int F_33 ( const char * V_60 ,
void * V_9 , char * V_20 )
{
F_6 ( V_9 , V_202 , V_64 ) ;
F_6 ( V_9 , V_202 , V_203 ) ;
F_6 ( V_9 , V_202 , V_204 ) ;
strcpy ( V_20 , L_98 ) ;
F_7 ( V_20 , L_15 , V_64 != V_205 , V_64 ) ;
F_7 ( V_20 , L_59 , V_203 != V_206 , V_203 ) ;
F_7 ( V_20 , L_96 , V_204 != V_207 , V_204 ) ;
F_1 ( V_20 ) ;
return 1 ;
}
static int F_34 ( const char * V_60 ,
void * V_9 , char * V_20 )
{
F_6 ( V_9 , V_208 , V_209 ) ;
F_6 ( V_9 , V_208 , V_104 ) ;
F_6 ( V_9 , V_208 , V_210 ) ;
F_6 ( V_9 , V_208 , V_88 ) ;
strcpy ( V_20 , L_99 ) ;
F_7 ( V_20 , L_51 , V_209 != V_211 , V_209 ) ;
F_7 ( V_20 , L_59 , V_104 != V_212 , V_104 ) ;
F_7 ( V_20 , L_96 , V_210 != V_213 , V_210 ) ;
F_7 ( V_20 , L_100 , V_88 != V_214 , V_88 ) ;
F_1 ( V_20 ) ;
return 1 ;
}
static int F_35 ( const char * V_60 , void * V_9 ,
char * V_20 )
{
F_6 ( V_9 , V_215 , V_85 ) ;
F_6 ( V_9 , V_215 , V_64 ) ;
strcpy ( V_20 , L_101 ) ;
F_7 ( V_20 , L_17 , V_85 != V_216 , V_85 ) ;
F_7 ( V_20 , L_15 , V_64 != V_216 , V_64 ) ;
F_1 ( V_20 ) ;
return 1 ;
}
static int F_36 ( const char * V_60 , void * V_9 ,
char * V_20 )
{
int V_10 ;
F_21 ( V_9 , V_217 , V_218 ) ;
char V_219 [ ( sizeof( * V_218 ) + 1 ) * 2 ] ;
for ( V_10 = 0 ; V_10 < ( sizeof( * V_218 ) * 2 ) ; V_10 += 2 )
sprintf ( & V_219 [ V_10 ] , L_63 , F_25 ( ( V_218 -> V_4 ) [ V_10 / 2 ] ) ) ;
strcpy ( V_20 , L_102 ) ;
strcat ( V_20 , V_219 ) ;
return 1 ;
}
static int F_37 ( const char * V_60 , void * V_9 ,
char * V_20 )
{
F_21 ( V_9 , V_220 , V_59 ) ;
sprintf ( V_20 , V_221 L_103 , * V_59 ) ;
return 1 ;
}
static int F_38 ( const char * V_60 , void * V_9 ,
char * V_20 )
{
F_21 ( V_9 , V_222 , V_59 ) ;
sprintf ( V_20 , V_223 L_103 , * V_59 ) ;
return 1 ;
}
static void F_39 ( char * V_224 , const char * V_225 )
{
for (; * V_225 ; V_225 ++ )
if ( * V_225 > ' ' && * V_225 < 127 && * V_225 != ':' )
* ( V_224 ++ ) = * V_225 ;
* V_224 = 0 ;
}
static int F_40 ( const char * V_60 , void * V_9 ,
char * V_20 )
{
int V_10 , V_47 ;
F_21 ( V_9 , V_226 , V_227 ) ;
sprintf ( V_20 , L_104 ) ;
for ( V_10 = 0 ; V_10 < F_41 ( V_228 ) ; V_10 ++ ) {
for ( V_47 = 0 ; V_47 < 4 ; V_47 ++ ) {
if ( ( * V_227 ) [ V_47 ] . V_229 &&
( * V_227 ) [ V_47 ] . V_229 == V_228 [ V_10 ] . V_230 ) {
sprintf ( V_20 + strlen ( V_20 ) , L_105 ,
V_228 [ V_10 ] . V_231 ) ;
F_39 ( V_20 + strlen ( V_20 ) ,
( * V_227 ) [ V_47 ] . V_232 ) ;
strcat ( V_20 , L_1 ) ;
}
}
}
strcat ( V_20 , L_106 ) ;
return 1 ;
}
static int F_42 ( const char * V_60 ,
void * V_9 , char * V_20 )
{
F_21 ( V_9 , V_233 , V_59 ) ;
sprintf ( V_20 , V_234 L_103 , * V_59 ) ;
return 1 ;
}
static int F_43 ( const char * V_60 ,
void * V_9 , char * V_20 )
{
int V_10 ;
F_6 ( V_9 , V_235 , V_236 ) ;
F_6 ( V_9 , V_235 , V_237 ) ;
V_20 += sprintf ( V_20 , V_238 ) ;
for ( V_10 = 0 ; V_10 < 32 ; V_10 ++ ) {
if ( ! ( ( V_237 >> ( 31 - V_10 ) ) & 1 ) )
* ( V_20 ++ ) = '?' ;
else if ( ( V_236 >> ( 31 - V_10 ) ) & 1 )
* ( V_20 ++ ) = '1' ;
else
* ( V_20 ++ ) = '0' ;
}
* V_20 = 0 ;
return 1 ;
}
static int F_44 ( const char * V_60 , void * V_9 ,
char * V_20 )
{
F_6 ( V_9 , V_239 , V_104 ) ;
strcpy ( V_20 , L_107 ) ;
F_7 ( V_20 , L_48 , V_104 != V_240 , V_104 ) ;
return 1 ;
}
static int F_45 ( const char * V_60 ,
void * V_9 , char * V_20 )
{
F_6 ( V_9 , V_241 , V_64 ) ;
F_6 ( V_9 , V_241 , V_131 ) ;
sprintf ( V_20 , L_108 ,
'A' + ( ( V_64 >> 2 ) & 0x3f ) - 1 ,
'A' + ( ( ( V_64 & 3 ) << 3 ) | ( ( V_64 >> 13 ) & 7 ) ) - 1 ,
'A' + ( ( V_64 >> 8 ) & 0x1f ) - 1 ,
( V_131 >> 4 ) & 0x0f , V_131 & 0x0f ,
( V_131 >> 12 ) & 0x0f , ( V_131 >> 8 ) & 0x0f ) ;
return 1 ;
}
static int F_46 ( const char * V_60 ,
void * V_9 , char * V_20 )
{
F_6 ( V_9 , V_242 , V_243 ) ;
F_6 ( V_9 , V_242 , V_64 ) ;
F_6 ( V_9 , V_242 , V_85 ) ;
strcpy ( V_20 , L_109 ) ;
F_7 ( V_20 , L_71 , V_243 != V_244 , V_243 ) ;
F_7 ( V_20 , L_15 , V_64 != V_245 , V_64 ) ;
F_7 ( V_20 , L_17 , V_85 != V_245 , V_85 ) ;
F_1 ( V_20 ) ;
return 1 ;
}
static void F_47 ( char * * V_246 ,
unsigned int V_247 , unsigned int V_248 )
{
char * V_249 = * V_246 ;
unsigned int V_10 ;
switch ( V_248 ) {
case 0 :
* V_249 ++ = '?' ;
break;
case 0xf :
V_249 += sprintf ( V_249 , L_19 , V_247 ) ;
break;
default:
* V_249 ++ = '[' ;
for ( V_10 = 0 ; V_10 < 0x10 ; V_10 ++ )
if ( ( V_10 & V_248 ) == V_247 )
V_249 += sprintf ( V_249 , L_19 , V_10 ) ;
* V_249 ++ = ']' ;
}
* V_249 = '\0' ;
* V_246 = V_249 ;
}
static int F_48 ( const char * V_60 ,
void * V_9 , char * V_20 )
{
unsigned int V_250 ;
char * V_249 = V_20 ;
F_6 ( V_9 , V_251 , V_104 ) ;
F_6 ( V_9 , V_251 , V_248 ) ;
if ( ( V_104 & V_248 ) != V_104 )
F_4 ( L_110
L_111 ,
V_60 , V_104 , V_248 ) ;
V_249 += sprintf ( V_20 , L_112 ) ;
for ( V_250 = 0 ; V_250 < 8 ; V_250 ++ )
F_47 ( & V_249 ,
( V_104 >> ( 4 * ( 7 - V_250 ) ) ) & 0xf ,
( V_248 >> ( 4 * ( 7 - V_250 ) ) ) & 0xf ) ;
return 1 ;
}
static int F_49 ( const char * V_60 ,
void * V_9 , char * V_20 )
{
F_6 ( V_9 , V_252 , type ) ;
sprintf ( V_20 , L_113 , type ) ;
return 1 ;
}
static int F_50 ( const char * V_60 , void * V_9 ,
char * V_20 )
{
F_6 ( V_9 , V_253 , V_254 ) ;
F_6 ( V_9 , V_253 , V_255 ) ;
F_6 ( V_9 , V_253 , V_256 ) ;
F_6 ( V_9 , V_253 , V_64 ) ;
strcpy ( V_20 , L_114 ) ;
F_7 ( V_20 , L_38 , V_64 != V_257 , V_64 ) ;
F_7 ( V_20 , L_115 , V_255 != V_258 , V_255 ) ;
F_7 ( V_20 , L_116 , V_256 != V_259 , V_256 ) ;
strcat ( V_20 , L_117 ) ;
if ( V_254 != V_260 )
sprintf ( V_20 + strlen ( V_20 ) , L_118 , V_254 ) ;
return 1 ;
}
static int F_51 ( const char * V_60 , void * V_9 , char * V_20 )
{
F_6 ( V_9 , V_261 , V_254 ) ;
sprintf ( V_20 , L_119 , V_254 ) ;
return 1 ;
}
static int F_52 ( const char * V_60 , void * V_9 ,
char * V_20 )
{
F_21 ( V_9 , V_262 , V_59 ) ;
F_21 ( V_9 , V_262 , V_3 ) ;
F_6 ( V_9 , V_262 , V_73 ) ;
sprintf ( V_20 , V_263 ) ;
sprintf ( V_20 + strlen ( V_20 ) , L_120 , ( * V_59 ) [ 0 ] ? * V_59 : L_1 ) ;
F_2 ( V_20 , * V_3 ) ;
F_7 ( V_20 , L_106 , V_73 != V_264 , V_73 ) ;
strcat ( V_20 , L_65 ) ;
return 1 ;
}
static int F_53 ( const char * V_60 ,
void * V_9 , char * V_20 )
{
F_6 ( V_9 , V_265 , V_266 ) ;
F_6 ( V_9 , V_265 , V_267 ) ;
F_6 ( V_9 , V_265 , V_268 ) ;
F_6 ( V_9 , V_265 , V_269 ) ;
strcpy ( V_20 , L_121 ) ;
F_7 ( V_20 , L_15 , V_267 != V_270 , V_267 ) ;
F_7 ( V_20 , L_17 , V_266 != V_270 , V_266 ) ;
F_7 ( V_20 , L_122 , V_269 != V_270 , V_269 ) ;
F_7 ( V_20 , L_123 , V_268 != V_270 , V_268 ) ;
F_1 ( V_20 ) ;
return 1 ;
}
static int F_54 ( const char * V_60 , void * V_9 ,
char * V_20 )
{
F_6 ( V_9 , V_271 , V_64 ) ;
F_6 ( V_9 , V_271 , V_65 ) ;
sprintf ( V_20 , L_124 , V_64 , V_65 ) ;
return 1 ;
}
static int F_55 ( const char * V_60 , void * V_9 , char * V_20 )
{
F_6 ( V_9 , V_272 , V_70 ) ;
F_6 ( V_9 , V_272 , V_273 ) ;
F_6 ( V_9 , V_272 , V_274 ) ;
strcpy ( V_20 , L_125 ) ;
F_7 ( V_20 , L_15 , V_70 != 0 , V_70 ) ;
F_7 ( V_20 , L_126 , V_273 != 0 , V_273 ) ;
F_7 ( V_20 , L_127 , V_274 != 0 , V_274 ) ;
F_1 ( V_20 ) ;
return 1 ;
}
static bool F_56 ( const char * V_59 , unsigned V_275 , const char * V_276 )
{
if ( V_275 != strlen ( V_276 ) )
return false ;
return memcmp ( V_59 , V_276 , V_275 ) == 0 ;
}
static void F_57 ( void * V_9 , unsigned long V_7 ,
unsigned long V_8 ,
const char * V_6 ,
void * V_131 ,
struct V_18 * V_19 )
{
unsigned int V_10 ;
char V_20 [ 500 ] ;
int (* F_58)( const char * , void * V_277 , char * V_20 ) = V_131 ;
F_3 ( V_19 -> V_59 , V_6 , V_7 , V_8 , V_9 ) ;
V_7 -= V_8 ;
for ( V_10 = 0 ; V_10 < V_7 ; V_10 += V_8 ) {
if ( F_58 ( V_19 -> V_59 , V_9 + V_10 , V_20 ) ) {
F_8 ( & V_19 -> V_42 ,
L_32 , V_20 ) ;
}
}
}
void F_59 ( struct V_18 * V_19 , struct V_278 * V_279 ,
T_4 * V_280 , const char * V_281 )
{
void * V_9 ;
char * V_282 = NULL ;
const char * V_59 , * V_283 ;
unsigned int V_275 ;
if ( ! V_280 -> V_284 || F_60 ( V_279 , V_280 ) >= V_279 -> V_285 )
return;
if ( F_61 ( V_280 -> V_286 ) != V_287 )
return;
V_59 = strstr ( V_281 , L_128 ) ;
if ( ! V_59 )
return;
V_59 += strlen ( L_128 ) ;
V_275 = strlen ( V_59 ) ;
if ( V_275 < strlen ( L_129 ) )
return;
if ( strcmp ( V_59 + V_275 - strlen ( L_129 ) , L_129 ) )
return;
V_283 = strstr ( V_59 , L_130 ) ;
if ( ! V_283 )
return;
V_275 = V_283 - V_59 ;
if ( V_279 -> V_288 [ F_60 ( V_279 , V_280 ) ] . V_289 & V_290 ) {
V_282 = calloc ( 1 , V_280 -> V_291 ) ;
V_9 = V_282 ;
} else {
V_9 = ( void * ) V_279 -> V_292
+ V_279 -> V_288 [ F_60 ( V_279 , V_280 ) ] . V_293
+ V_280 -> V_294 ;
}
if ( F_56 ( V_59 , V_275 , L_33 ) )
F_11 ( V_9 , V_280 -> V_291 , V_19 ) ;
else if ( F_56 ( V_59 , V_275 , L_66 ) )
F_22 ( V_9 , V_280 -> V_291 , V_19 ) ;
else if ( F_56 ( V_59 , V_275 , L_131 ) )
F_23 ( V_9 , V_280 -> V_291 , V_19 ) ;
else {
struct V_295 * * V_249 ;
F_62 ( V_296 ) ;
for ( V_249 = V_297 ; V_249 < V_298 ; V_249 ++ ) {
if ( F_56 ( V_59 , V_275 , ( * V_249 ) -> V_6 ) ) {
F_57 ( V_9 , V_280 -> V_291 , ( * V_249 ) -> V_8 ,
( * V_249 ) -> V_6 , ( * V_249 ) -> V_131 , V_19 ) ;
break;
}
}
}
free ( V_282 ) ;
}
void F_63 ( struct V_299 * V_300 , struct V_18 * V_19 )
{
F_8 ( V_300 , L_11 ) ;
F_64 ( V_300 , V_19 -> V_42 . V_249 , V_19 -> V_42 . V_301 ) ;
free ( V_19 -> V_42 . V_249 ) ;
}
