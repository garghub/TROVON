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
static void F_12 ( void * V_9 , struct V_18 * V_19 )
{
char V_20 [ 500 ] ;
int V_2 ;
char * V_60 ;
F_13 ( V_9 , V_61 , V_59 ) ;
F_13 ( V_9 , V_61 , type ) ;
F_13 ( V_9 , V_61 , V_62 ) ;
V_2 = sprintf ( V_20 , L_34 , ( * V_59 ) [ 0 ] ? * V_59 : L_1 ,
( * type ) [ 0 ] ? * type : L_1 ) ;
if ( V_62 [ 0 ] )
sprintf ( & V_20 [ V_2 ] , L_35 , ( * type ) [ 0 ] ? L_1 : L_36 ,
* V_62 ) ;
for ( V_60 = V_20 ; V_60 && * V_60 ; V_60 ++ )
if ( isspace ( * V_60 ) )
* V_60 = '_' ;
F_8 ( & V_19 -> V_42 , L_32 , V_20 ) ;
strcat ( V_20 , L_37 ) ;
F_1 ( V_20 ) ;
F_8 ( & V_19 -> V_42 , L_32 , V_20 ) ;
}
static void F_14 ( void * V_9 , unsigned long V_7 ,
struct V_18 * V_19 )
{
unsigned int V_10 ;
const unsigned long V_8 = V_63 ;
F_3 ( V_19 -> V_59 , L_38 , V_7 , V_8 , V_9 ) ;
V_7 -= V_8 ;
for ( V_10 = 0 ; V_10 < V_7 ; V_10 += V_8 )
F_12 ( V_9 + V_10 , V_19 ) ;
}
static int F_15 ( const char * V_64 ,
void * V_9 , char * V_20 )
{
F_6 ( V_9 , V_65 , V_66 ) ;
F_6 ( V_9 , V_65 , V_67 ) ;
F_6 ( V_9 , V_65 , V_68 ) ;
F_6 ( V_9 , V_65 , V_69 ) ;
sprintf ( V_20 , L_39 ) ;
F_7 ( V_20 , L_40 , V_66 != V_70 , V_66 ) ;
F_7 ( V_20 , L_41 , V_67 != V_71 , V_67 ) ;
F_7 ( V_20 , L_15 , V_68 != V_72 , V_68 ) ;
F_7 ( V_20 , L_16 , V_69 != V_72 , V_69 ) ;
return 1 ;
}
static int F_16 ( const char * V_64 ,
void * V_9 , char * V_20 )
{
F_6 ( V_9 , V_73 , V_22 ) ;
F_6 ( V_9 , V_73 , V_74 ) ;
F_6 ( V_9 , V_73 , V_75 ) ;
F_6 ( V_9 , V_73 , V_76 ) ;
F_6 ( V_9 , V_73 , V_77 ) ;
strcpy ( V_20 , L_42 ) ;
F_7 ( V_20 , L_43 , V_22 & V_78 ,
V_74 ) ;
F_7 ( V_20 , L_44 , V_22 & V_79 ,
V_75 ) ;
F_7 ( V_20 , L_45 , V_22 & V_80 ,
V_76 ) ;
F_7 ( V_20 , L_46 , V_22 & V_81 ,
V_77 ) ;
F_1 ( V_20 ) ;
return 1 ;
}
static int F_17 ( const char * V_64 ,
void * V_9 , char * V_20 )
{
unsigned char V_82 , V_83 , V_84 ,
V_85 , V_86 , V_87 ;
F_6 ( V_9 , V_88 , V_68 ) ;
F_6 ( V_9 , V_88 , V_89 ) ;
F_6 ( V_9 , V_88 , V_90 ) ;
F_6 ( V_9 , V_88 , V_91 ) ;
F_6 ( V_9 , V_88 , V_92 ) ;
F_6 ( V_9 , V_88 , V_93 ) ;
strcpy ( V_20 , L_47 ) ;
F_7 ( V_20 , L_15 , V_68 != V_94 , V_68 ) ;
F_7 ( V_20 , L_17 , V_89 != V_94 , V_89 ) ;
F_7 ( V_20 , L_48 , V_90 != V_94 , V_90 ) ;
F_7 ( V_20 , L_49 , V_91 != V_94 , V_91 ) ;
V_82 = ( V_92 ) >> 16 ;
V_85 = ( V_93 ) >> 16 ;
V_83 = ( V_92 ) >> 8 ;
V_86 = ( V_93 ) >> 8 ;
V_84 = V_92 ;
V_87 = V_93 ;
if ( ( V_85 != 0 && V_85 != 0xFF )
|| ( V_86 != 0 && V_86 != 0xFF )
|| ( V_87 != 0 && V_87 != 0xFF ) ) {
F_18 ( L_50 ,
V_64 , V_93 ) ;
return 0 ;
}
F_7 ( V_20 , L_51 , V_85 == 0xFF , V_82 ) ;
F_7 ( V_20 , L_52 , V_86 == 0xFF , V_83 ) ;
F_7 ( V_20 , L_53 , V_87 == 0xFF , V_84 ) ;
F_1 ( V_20 ) ;
return 1 ;
}
static int F_19 ( const char * V_64 ,
void * V_9 , char * V_20 )
{
F_6 ( V_9 , V_95 , V_22 ) ;
F_6 ( V_9 , V_95 , V_96 ) ;
F_6 ( V_9 , V_95 , V_97 ) ;
F_6 ( V_9 , V_95 , V_98 ) ;
F_6 ( V_9 , V_95 , V_99 ) ;
strcpy ( V_20 , L_54 ) ;
F_7 ( V_20 , L_55 , V_22 & V_100 ,
V_96 ) ;
F_7 ( V_20 , L_56 , V_22 & V_101 ,
V_97 ) ;
F_7 ( V_20 , L_57 , V_22 & V_102 ,
V_98 ) ;
F_7 ( V_20 , L_58 , V_22 & V_103 ,
V_99 ) ;
F_1 ( V_20 ) ;
return 1 ;
}
static int F_20 ( const char * V_64 ,
void * V_9 , char * V_20 )
{
F_6 ( V_9 , V_104 , V_98 ) ;
sprintf ( V_20 , L_59 , V_98 ) ;
return 1 ;
}
static int F_21 ( const char * V_64 ,
void * V_9 , char * V_20 )
{
F_6 ( V_9 , V_105 , type ) ;
sprintf ( V_20 , L_60 , type ) ;
return 1 ;
}
static int F_22 ( const char * V_64 ,
void * V_9 , char * V_20 )
{
F_6 ( V_9 , V_106 , type ) ;
F_6 ( V_9 , V_106 , V_107 ) ;
F_6 ( V_9 , V_106 , V_108 ) ;
F_6 ( V_9 , V_106 , V_109 ) ;
strcpy ( V_20 , L_61 ) ;
F_7 ( V_20 , L_62 , type != V_110 , type ) ;
F_7 ( V_20 , L_63 , V_107 != V_110 , V_107 ) ;
F_7 ( V_20 , L_64 , V_108 != V_110 , V_108 ) ;
F_7 ( V_20 , L_65 , V_109 != V_110 , V_109 ) ;
F_1 ( V_20 ) ;
return 1 ;
}
static int F_23 ( const char * V_64 ,
void * V_9 , char * V_20 )
{
F_13 ( V_9 , V_111 , V_108 ) ;
F_13 ( V_9 , V_111 , V_112 ) ;
F_13 ( V_9 , V_111 , V_113 ) ;
if ( V_108 && strlen ( ( const char * ) * V_108 ) )
sprintf ( V_20 , L_66 , * V_108 ) ;
else if ( V_112 ) {
int V_10 , V_114 , V_115 = 0 ;
unsigned int V_116 ;
sprintf ( & V_20 [ V_115 ] , L_67 ) ;
V_115 = 6 ;
for ( V_10 = 1 ; V_10 <= 3 ; V_10 ++ ) {
V_114 = 8 * ( 3 - V_10 ) ;
V_116 = ( * V_113 >> V_114 ) & 0xFF ;
if ( V_116 )
sprintf ( & V_20 [ V_115 ] , L_68 ,
( * V_112 >> V_114 ) & 0xFF ) ;
else
sprintf ( & V_20 [ V_115 ] , L_69 ) ;
V_115 += 2 ;
}
sprintf ( & V_20 [ V_115 ] , L_70 ) ;
}
return 1 ;
}
static void F_24 ( void * V_9 , unsigned long V_7 ,
struct V_18 * V_19 )
{
const unsigned long V_8 = V_117 ;
const unsigned int V_118 = ( V_7 / V_8 ) - 1 ;
unsigned int V_10 ;
F_3 ( V_19 -> V_59 , L_71 , V_7 , V_8 , V_9 ) ;
for ( V_10 = 0 ; V_10 < V_118 ; V_10 ++ ) {
F_13 ( V_9 + V_10 * V_8 , V_119 , V_108 ) ;
char V_120 [ sizeof( * V_108 ) ] ;
int V_47 ;
F_8 ( & V_19 -> V_42 ,
L_72 , * V_108 ) ;
for ( V_47 = 0 ; V_47 < sizeof( V_120 ) ; V_47 ++ )
V_120 [ V_47 ] = toupper ( ( * V_108 ) [ V_47 ] ) ;
F_8 ( & V_19 -> V_42 ,
L_73 , V_120 ) ;
}
}
static void F_25 ( void * V_9 , unsigned long V_7 ,
struct V_18 * V_19 )
{
const unsigned long V_8 = V_121 ;
const unsigned int V_118 = ( V_7 / V_8 ) - 1 ;
unsigned int V_10 ;
F_3 ( V_19 -> V_59 , L_71 , V_7 , V_8 , V_9 ) ;
for ( V_10 = 0 ; V_10 < V_118 ; V_10 ++ ) {
unsigned int V_47 ;
F_13 ( V_9 + V_10 * V_8 , V_122 , V_123 ) ;
for ( V_47 = 0 ; V_47 < V_124 ; V_47 ++ ) {
const char * V_108 = ( char * ) ( * V_123 ) [ V_47 ] . V_108 ;
int V_125 , V_126 ;
int V_127 = 0 ;
if ( ! V_108 [ 0 ] )
break;
for ( V_125 = 0 ; V_125 < V_10 && ! V_127 ; V_125 ++ ) {
F_13 ( V_9 + V_125 * V_8 , V_122 , V_123 ) ;
for ( V_126 = 0 ; V_126 < V_124 ; V_126 ++ ) {
const char * V_128 = ( char * ) ( * V_123 ) [ V_126 ] . V_108 ;
if ( ! V_128 [ 0 ] )
break;
if ( ! strcmp ( V_108 , V_128 ) ) {
V_127 = 1 ;
break;
}
}
}
if ( ! V_127 ) {
char V_120 [ V_129 ] ;
int V_130 ;
F_8 ( & V_19 -> V_42 ,
L_72 , V_108 ) ;
for ( V_130 = 0 ; V_130 < sizeof( V_120 ) ; V_130 ++ )
V_120 [ V_130 ] = toupper ( V_108 [ V_130 ] ) ;
F_8 ( & V_19 -> V_42 ,
L_73 , V_120 ) ;
}
}
}
}
static int F_26 ( const char * V_64 ,
void * V_9 , char * V_20 )
{
unsigned int V_10 ;
F_6 ( V_9 , V_131 , V_22 ) ;
F_6 ( V_9 , V_131 , V_132 ) ;
F_6 ( V_9 , V_131 , V_133 ) ;
F_6 ( V_9 , V_131 , V_134 ) ;
F_6 ( V_9 , V_131 , V_135 ) ;
F_6 ( V_9 , V_131 , V_136 ) ;
F_13 ( V_9 , V_131 , V_137 ) ;
for ( V_10 = 0 ; V_10 < 4 ; V_10 ++ ) {
( * V_137 ) [ V_10 ] = F_27 ( ( * V_137 ) [ V_10 ] ) ;
}
strcpy ( V_20 , L_74 ) ;
F_7 ( V_20 , L_56 , V_22 & V_138 ,
V_132 ) ;
F_7 ( V_20 , L_75 , V_22 & V_139 ,
V_133 ) ;
F_7 ( V_20 , L_76 , V_22 & V_140 ,
V_134 ) ;
F_7 ( V_20 , L_77 , V_22 & V_141 ,
V_135 ) ;
F_7 ( V_20 , L_78 , V_22 & V_142 ,
V_136 ) ;
F_7 ( V_20 , L_79 , V_22 & V_143 , ( * V_137 ) [ 0 ] ) ;
F_7 ( V_20 , L_80 , V_22 & V_144 , ( * V_137 ) [ 1 ] ) ;
F_7 ( V_20 , L_81 , V_22 & V_145 , ( * V_137 ) [ 2 ] ) ;
F_7 ( V_20 , L_82 , V_22 & V_146 , ( * V_137 ) [ 3 ] ) ;
F_1 ( V_20 ) ;
return 1 ;
}
static int F_28 ( const char * V_64 , void * V_9 ,
char * V_20 )
{
char * V_60 ;
F_13 ( V_9 , V_147 , type ) ;
F_13 ( V_9 , V_147 , V_148 ) ;
sprintf ( V_20 , L_83 , ( * type ) [ 0 ] ? * type : L_1 ,
( * V_148 ) [ 0 ] ? * V_148 : L_1 ) ;
for ( V_60 = V_20 ; V_60 && * V_60 ; V_60 ++ )
if ( isspace ( * V_60 ) )
* V_60 = '_' ;
F_1 ( V_20 ) ;
return 1 ;
}
static void F_29 ( char * V_20 ,
T_3 * V_149 , unsigned int V_150 , unsigned int V_17 )
{
unsigned int V_10 ;
for ( V_10 = V_150 / V_151 ; V_10 < V_17 / V_151 + 1 ; V_10 ++ )
V_149 [ V_10 ] = F_27 ( V_149 [ V_10 ] ) ;
for ( V_10 = V_150 ; V_10 < V_17 ; V_10 ++ )
if ( V_149 [ V_10 / V_151 ] & ( 1L << ( V_10 % V_151 ) ) )
sprintf ( V_20 + strlen ( V_20 ) , L_84 , V_10 ) ;
}
static int F_30 ( const char * V_64 , void * V_9 ,
char * V_20 )
{
F_6 ( V_9 , V_152 , V_153 ) ;
F_6 ( V_9 , V_152 , V_154 ) ;
F_6 ( V_9 , V_152 , V_68 ) ;
F_6 ( V_9 , V_152 , V_69 ) ;
F_6 ( V_9 , V_152 , V_77 ) ;
F_13 ( V_9 , V_152 , V_155 ) ;
F_13 ( V_9 , V_152 , V_156 ) ;
F_13 ( V_9 , V_152 , V_157 ) ;
F_13 ( V_9 , V_152 , V_158 ) ;
F_13 ( V_9 , V_152 , V_159 ) ;
F_13 ( V_9 , V_152 , V_160 ) ;
F_13 ( V_9 , V_152 , V_161 ) ;
F_13 ( V_9 , V_152 , V_162 ) ;
F_13 ( V_9 , V_152 , V_163 ) ;
sprintf ( V_20 , L_85 ) ;
F_7 ( V_20 , L_40 , V_153 & V_164 , V_154 ) ;
F_7 ( V_20 , L_15 , V_153 & V_165 , V_68 ) ;
F_7 ( V_20 , L_16 , V_153 & V_166 , V_69 ) ;
F_7 ( V_20 , L_86 , V_153 & V_167 , V_77 ) ;
sprintf ( V_20 + strlen ( V_20 ) , L_87 ) ;
if ( V_153 & V_168 )
F_29 ( V_20 , * V_155 , 0 , V_169 ) ;
sprintf ( V_20 + strlen ( V_20 ) , L_88 ) ;
if ( V_153 & V_170 )
F_29 ( V_20 , * V_156 ,
V_171 ,
V_172 ) ;
sprintf ( V_20 + strlen ( V_20 ) , L_89 ) ;
if ( V_153 & V_173 )
F_29 ( V_20 , * V_157 , 0 , V_174 ) ;
sprintf ( V_20 + strlen ( V_20 ) , L_90 ) ;
if ( V_153 & V_175 )
F_29 ( V_20 , * V_158 , 0 , V_176 ) ;
sprintf ( V_20 + strlen ( V_20 ) , L_91 ) ;
if ( V_153 & V_177 )
F_29 ( V_20 , * V_159 , 0 , V_178 ) ;
sprintf ( V_20 + strlen ( V_20 ) , L_92 ) ;
if ( V_153 & V_179 )
F_29 ( V_20 , * V_160 , 0 , V_180 ) ;
sprintf ( V_20 + strlen ( V_20 ) , L_93 ) ;
if ( V_153 & V_181 )
F_29 ( V_20 , * V_161 , 0 , V_182 ) ;
sprintf ( V_20 + strlen ( V_20 ) , L_94 ) ;
if ( V_153 & V_183 )
F_29 ( V_20 , * V_162 , 0 , V_184 ) ;
sprintf ( V_20 + strlen ( V_20 ) , L_95 ) ;
if ( V_153 & V_185 )
F_29 ( V_20 , * V_163 , 0 , V_186 ) ;
return 1 ;
}
static int F_31 ( const char * V_64 , void * V_9 ,
char * V_20 )
{
F_13 ( V_9 , V_187 , V_188 ) ;
if ( V_188 [ 0 ] )
sprintf ( V_20 , V_189 L_1 , * V_188 ) ;
else
strcat ( V_20 , L_1 ) ;
return 1 ;
}
static int F_32 ( const char * V_64 , void * V_9 ,
char * V_20 )
{
F_6 ( V_9 , V_190 , V_191 ) ;
F_6 ( V_9 , V_190 , V_192 ) ;
F_6 ( V_9 , V_190 , V_193 ) ;
F_6 ( V_9 , V_190 , V_194 ) ;
strcpy ( V_20 , L_96 ) ;
F_7 ( V_20 , L_55 , V_191 != V_195 , V_191 ) ;
F_7 ( V_20 , L_97 , V_192 != V_196 , V_192 ) ;
F_7 ( V_20 , L_98 , V_193 != V_197 , V_193 ) ;
F_7 ( V_20 , L_48 , V_194 != V_198 , V_194 ) ;
F_1 ( V_20 ) ;
return 1 ;
}
static int F_33 ( const char * V_64 ,
void * V_9 , char * V_20 )
{
F_6 ( V_9 , V_199 , V_92 ) ;
F_6 ( V_9 , V_199 , V_68 ) ;
F_6 ( V_9 , V_199 , V_89 ) ;
strcpy ( V_20 , L_99 ) ;
F_7 ( V_20 , L_75 , V_92 != ( V_200 ) V_201 , V_92 ) ;
F_7 ( V_20 , L_15 , V_68 != ( V_202 ) V_201 , V_68 ) ;
F_7 ( V_20 , L_17 , V_89 != ( V_202 ) V_201 , V_89 ) ;
F_1 ( V_20 ) ;
return 1 ;
}
static int F_34 ( const char * V_64 ,
void * V_9 , char * V_20 )
{
F_6 ( V_9 , V_203 , V_68 ) ;
F_6 ( V_9 , V_203 , V_204 ) ;
F_6 ( V_9 , V_203 , V_205 ) ;
strcpy ( V_20 , L_100 ) ;
F_7 ( V_20 , L_15 , V_68 != V_206 , V_68 ) ;
F_7 ( V_20 , L_64 , V_204 != V_207 , V_204 ) ;
F_7 ( V_20 , L_98 , V_205 != V_208 , V_205 ) ;
F_1 ( V_20 ) ;
return 1 ;
}
static int F_35 ( const char * V_64 ,
void * V_9 , char * V_20 )
{
F_6 ( V_9 , V_209 , V_210 ) ;
F_6 ( V_9 , V_209 , V_108 ) ;
F_6 ( V_9 , V_209 , V_211 ) ;
F_6 ( V_9 , V_209 , V_92 ) ;
strcpy ( V_20 , L_101 ) ;
F_7 ( V_20 , L_56 , V_210 != V_212 , V_210 ) ;
F_7 ( V_20 , L_64 , V_108 != V_213 , V_108 ) ;
F_7 ( V_20 , L_98 , V_211 != V_214 , V_211 ) ;
F_7 ( V_20 , L_102 , V_92 != V_215 , V_92 ) ;
F_1 ( V_20 ) ;
return 1 ;
}
static int F_36 ( const char * V_64 , void * V_9 ,
char * V_20 )
{
F_6 ( V_9 , V_216 , V_89 ) ;
F_6 ( V_9 , V_216 , V_68 ) ;
strcpy ( V_20 , L_103 ) ;
F_7 ( V_20 , L_17 , V_89 != V_217 , V_89 ) ;
F_7 ( V_20 , L_15 , V_68 != V_217 , V_68 ) ;
F_1 ( V_20 ) ;
return 1 ;
}
static int F_37 ( const char * V_64 , void * V_9 ,
char * V_20 )
{
int V_10 ;
F_13 ( V_9 , V_218 , V_219 ) ;
char V_220 [ ( sizeof( * V_219 ) + 1 ) * 2 ] ;
for ( V_10 = 0 ; V_10 < ( sizeof( * V_219 ) * 2 ) ; V_10 += 2 )
sprintf ( & V_220 [ V_10 ] , L_68 , F_27 ( ( V_219 -> V_4 ) [ V_10 / 2 ] ) ) ;
strcpy ( V_20 , L_104 ) ;
strcat ( V_20 , V_220 ) ;
return 1 ;
}
static int F_38 ( const char * V_64 , void * V_9 ,
char * V_20 )
{
F_13 ( V_9 , V_221 , V_59 ) ;
sprintf ( V_20 , V_222 L_105 , * V_59 ) ;
return 1 ;
}
static int F_39 ( const char * V_64 , void * V_9 ,
char * V_20 )
{
F_13 ( V_9 , V_223 , V_59 ) ;
sprintf ( V_20 , V_224 L_105 , * V_59 ) ;
return 1 ;
}
static void F_40 ( char * V_225 , const char * V_226 )
{
for (; * V_226 ; V_226 ++ )
if ( * V_226 > ' ' && * V_226 < 127 && * V_226 != ':' )
* ( V_225 ++ ) = * V_226 ;
* V_225 = 0 ;
}
static int F_41 ( const char * V_64 , void * V_9 ,
char * V_20 )
{
int V_10 , V_47 ;
F_13 ( V_9 , V_227 , V_228 ) ;
sprintf ( V_20 , L_106 ) ;
for ( V_10 = 0 ; V_10 < F_42 ( V_229 ) ; V_10 ++ ) {
for ( V_47 = 0 ; V_47 < 4 ; V_47 ++ ) {
if ( ( * V_228 ) [ V_47 ] . V_230 &&
( * V_228 ) [ V_47 ] . V_230 == V_229 [ V_10 ] . V_231 ) {
sprintf ( V_20 + strlen ( V_20 ) , L_107 ,
V_229 [ V_10 ] . V_232 ) ;
F_40 ( V_20 + strlen ( V_20 ) ,
( * V_228 ) [ V_47 ] . V_233 ) ;
strcat ( V_20 , L_1 ) ;
}
}
}
strcat ( V_20 , L_108 ) ;
return 1 ;
}
static int F_43 ( const char * V_64 ,
void * V_9 , char * V_20 )
{
F_13 ( V_9 , V_234 , V_59 ) ;
sprintf ( V_20 , V_235 L_105 , * V_59 ) ;
return 1 ;
}
static int F_44 ( const char * V_64 ,
void * V_9 , char * V_20 )
{
int V_10 ;
F_6 ( V_9 , V_236 , V_237 ) ;
F_6 ( V_9 , V_236 , V_238 ) ;
V_20 += sprintf ( V_20 , V_239 ) ;
for ( V_10 = 0 ; V_10 < 32 ; V_10 ++ ) {
if ( ! ( ( V_238 >> ( 31 - V_10 ) ) & 1 ) )
* ( V_20 ++ ) = '?' ;
else if ( ( V_237 >> ( 31 - V_10 ) ) & 1 )
* ( V_20 ++ ) = '1' ;
else
* ( V_20 ++ ) = '0' ;
}
* V_20 = 0 ;
return 1 ;
}
static int F_45 ( const char * V_64 , void * V_9 ,
char * V_20 )
{
F_6 ( V_9 , V_240 , V_108 ) ;
strcpy ( V_20 , L_109 ) ;
F_7 ( V_20 , L_53 , V_108 != V_241 , V_108 ) ;
return 1 ;
}
static int F_46 ( const char * V_64 ,
void * V_9 , char * V_20 )
{
F_6 ( V_9 , V_242 , V_68 ) ;
F_6 ( V_9 , V_242 , V_135 ) ;
sprintf ( V_20 , L_110 ,
'A' + ( ( V_68 >> 2 ) & 0x3f ) - 1 ,
'A' + ( ( ( V_68 & 3 ) << 3 ) | ( ( V_68 >> 13 ) & 7 ) ) - 1 ,
'A' + ( ( V_68 >> 8 ) & 0x1f ) - 1 ,
( V_135 >> 4 ) & 0x0f , V_135 & 0x0f ,
( V_135 >> 12 ) & 0x0f , ( V_135 >> 8 ) & 0x0f ) ;
return 1 ;
}
static int F_47 ( const char * V_64 ,
void * V_9 , char * V_20 )
{
F_6 ( V_9 , V_243 , V_244 ) ;
F_6 ( V_9 , V_243 , V_68 ) ;
F_6 ( V_9 , V_243 , V_89 ) ;
strcpy ( V_20 , L_111 ) ;
F_7 ( V_20 , L_76 , V_244 != V_245 , V_244 ) ;
F_7 ( V_20 , L_15 , V_68 != V_246 , V_68 ) ;
F_7 ( V_20 , L_17 , V_89 != V_246 , V_89 ) ;
F_1 ( V_20 ) ;
return 1 ;
}
static void F_48 ( char * * V_247 ,
unsigned int V_248 , unsigned int V_249 )
{
char * V_250 = * V_247 ;
unsigned int V_10 ;
switch ( V_249 ) {
case 0 :
* V_250 ++ = '?' ;
break;
case 0xf :
V_250 += sprintf ( V_250 , L_19 , V_248 ) ;
break;
default:
* V_250 ++ = '[' ;
for ( V_10 = 0 ; V_10 < 0x10 ; V_10 ++ )
if ( ( V_10 & V_249 ) == V_248 )
V_250 += sprintf ( V_250 , L_19 , V_10 ) ;
* V_250 ++ = ']' ;
}
* V_250 = '\0' ;
* V_247 = V_250 ;
}
static int F_49 ( const char * V_64 ,
void * V_9 , char * V_20 )
{
unsigned int V_251 ;
char * V_250 = V_20 ;
F_6 ( V_9 , V_252 , V_108 ) ;
F_6 ( V_9 , V_252 , V_249 ) ;
if ( ( V_108 & V_249 ) != V_108 )
F_4 ( L_112
L_113 ,
V_64 , V_108 , V_249 ) ;
V_250 += sprintf ( V_20 , L_114 ) ;
for ( V_251 = 0 ; V_251 < 8 ; V_251 ++ )
F_48 ( & V_250 ,
( V_108 >> ( 4 * ( 7 - V_251 ) ) ) & 0xf ,
( V_249 >> ( 4 * ( 7 - V_251 ) ) ) & 0xf ) ;
return 1 ;
}
static int F_50 ( const char * V_64 ,
void * V_9 , char * V_20 )
{
F_6 ( V_9 , V_253 , type ) ;
sprintf ( V_20 , L_115 , type ) ;
return 1 ;
}
static int F_51 ( const char * V_64 , void * V_9 ,
char * V_20 )
{
F_6 ( V_9 , V_254 , V_255 ) ;
F_6 ( V_9 , V_254 , V_256 ) ;
F_6 ( V_9 , V_254 , V_257 ) ;
F_6 ( V_9 , V_254 , V_68 ) ;
strcpy ( V_20 , L_116 ) ;
F_7 ( V_20 , L_43 , V_68 != V_258 , V_68 ) ;
F_7 ( V_20 , L_117 , V_256 != V_259 , V_256 ) ;
F_7 ( V_20 , L_118 , V_257 != V_260 , V_257 ) ;
strcat ( V_20 , L_119 ) ;
if ( V_255 != V_261 )
sprintf ( V_20 + strlen ( V_20 ) , L_120 , V_255 ) ;
return 1 ;
}
static int F_52 ( const char * V_64 , void * V_9 , char * V_20 )
{
F_6 ( V_9 , V_262 , V_255 ) ;
sprintf ( V_20 , L_121 , V_255 ) ;
return 1 ;
}
static int F_53 ( const char * V_64 , void * V_9 ,
char * V_20 )
{
F_13 ( V_9 , V_263 , V_59 ) ;
F_13 ( V_9 , V_263 , V_3 ) ;
F_6 ( V_9 , V_263 , V_77 ) ;
sprintf ( V_20 , V_264 ) ;
sprintf ( V_20 + strlen ( V_20 ) , L_122 , ( * V_59 ) [ 0 ] ? * V_59 : L_1 ) ;
F_2 ( V_20 , * V_3 ) ;
F_7 ( V_20 , L_108 , V_77 != V_265 , V_77 ) ;
strcat ( V_20 , L_70 ) ;
return 1 ;
}
static int F_54 ( const char * V_64 ,
void * V_9 , char * V_20 )
{
F_6 ( V_9 , V_266 , V_267 ) ;
F_6 ( V_9 , V_266 , V_268 ) ;
F_6 ( V_9 , V_266 , V_269 ) ;
F_6 ( V_9 , V_266 , V_270 ) ;
strcpy ( V_20 , L_123 ) ;
F_7 ( V_20 , L_15 , V_268 != V_271 , V_268 ) ;
F_7 ( V_20 , L_17 , V_267 != V_271 , V_267 ) ;
F_7 ( V_20 , L_124 , V_270 != V_271 , V_270 ) ;
F_7 ( V_20 , L_125 , V_269 != V_271 , V_269 ) ;
F_1 ( V_20 ) ;
return 1 ;
}
static int F_55 ( const char * V_64 , void * V_9 ,
char * V_20 )
{
F_6 ( V_9 , V_272 , V_68 ) ;
F_6 ( V_9 , V_272 , V_69 ) ;
sprintf ( V_20 , L_126 , V_68 , V_69 ) ;
return 1 ;
}
static int F_56 ( const char * V_64 , void * V_9 , char * V_20 )
{
F_6 ( V_9 , V_273 , V_74 ) ;
F_6 ( V_9 , V_273 , V_274 ) ;
F_6 ( V_9 , V_273 , V_275 ) ;
strcpy ( V_20 , L_127 ) ;
F_7 ( V_20 , L_15 , V_74 != 0 , V_74 ) ;
F_7 ( V_20 , L_128 , V_274 != 0 , V_274 ) ;
F_7 ( V_20 , L_129 , V_275 != 0 , V_275 ) ;
F_1 ( V_20 ) ;
return 1 ;
}
static bool F_57 ( const char * V_59 , unsigned V_276 , const char * V_277 )
{
if ( V_276 != strlen ( V_277 ) )
return false ;
return memcmp ( V_59 , V_277 , V_276 ) == 0 ;
}
static void F_58 ( void * V_9 , unsigned long V_7 ,
unsigned long V_8 ,
const char * V_6 ,
void * V_135 ,
struct V_18 * V_19 )
{
unsigned int V_10 ;
char V_20 [ 500 ] ;
int (* F_59)( const char * , void * V_278 , char * V_20 ) = V_135 ;
F_3 ( V_19 -> V_59 , V_6 , V_7 , V_8 , V_9 ) ;
V_7 -= V_8 ;
for ( V_10 = 0 ; V_10 < V_7 ; V_10 += V_8 ) {
if ( F_59 ( V_19 -> V_59 , V_9 + V_10 , V_20 ) ) {
F_8 ( & V_19 -> V_42 ,
L_32 , V_20 ) ;
}
}
}
void F_60 ( struct V_18 * V_19 , struct V_279 * V_280 ,
T_4 * V_281 , const char * V_282 )
{
void * V_9 ;
char * V_283 = NULL ;
const char * V_59 , * V_284 ;
unsigned int V_276 ;
if ( ! V_281 -> V_285 || F_61 ( V_280 , V_281 ) >= V_280 -> V_286 )
return;
if ( F_62 ( V_281 -> V_287 ) != V_288 )
return;
V_59 = strstr ( V_282 , L_130 ) ;
if ( ! V_59 )
return;
V_59 += strlen ( L_130 ) ;
V_276 = strlen ( V_59 ) ;
if ( V_276 < strlen ( L_131 ) )
return;
if ( strcmp ( V_59 + V_276 - strlen ( L_131 ) , L_131 ) )
return;
V_284 = strstr ( V_59 , L_132 ) ;
if ( ! V_284 )
return;
V_276 = V_284 - V_59 ;
if ( V_280 -> V_289 [ F_61 ( V_280 , V_281 ) ] . V_290 & V_291 ) {
V_283 = calloc ( 1 , V_281 -> V_292 ) ;
V_9 = V_283 ;
} else {
V_9 = ( void * ) V_280 -> V_293
+ V_280 -> V_289 [ F_61 ( V_280 , V_281 ) ] . V_294
+ V_281 -> V_295 ;
}
if ( F_57 ( V_59 , V_276 , L_33 ) )
F_11 ( V_9 , V_281 -> V_292 , V_19 ) ;
if ( F_57 ( V_59 , V_276 , L_38 ) )
F_14 ( V_9 , V_281 -> V_292 , V_19 ) ;
else if ( F_57 ( V_59 , V_276 , L_71 ) )
F_24 ( V_9 , V_281 -> V_292 , V_19 ) ;
else if ( F_57 ( V_59 , V_276 , L_133 ) )
F_25 ( V_9 , V_281 -> V_292 , V_19 ) ;
else {
struct V_296 * * V_250 ;
F_63 ( V_297 ) ;
for ( V_250 = V_298 ; V_250 < V_299 ; V_250 ++ ) {
if ( F_57 ( V_59 , V_276 , ( * V_250 ) -> V_6 ) ) {
F_58 ( V_9 , V_281 -> V_292 , ( * V_250 ) -> V_8 ,
( * V_250 ) -> V_6 , ( * V_250 ) -> V_135 , V_19 ) ;
break;
}
}
}
free ( V_283 ) ;
}
void F_64 ( struct V_300 * V_301 , struct V_18 * V_19 )
{
F_8 ( V_301 , L_11 ) ;
F_65 ( V_301 , V_19 -> V_42 . V_250 , V_19 -> V_42 . V_302 ) ;
free ( V_19 -> V_42 . V_250 ) ;
}
