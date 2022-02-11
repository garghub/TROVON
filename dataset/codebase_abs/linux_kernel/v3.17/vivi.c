static const struct V_1 * F_1 ( T_1 V_2 )
{
const struct V_1 * V_3 ;
unsigned int V_4 ;
for ( V_4 = 0 ; V_4 < F_2 ( V_5 ) ; V_4 ++ ) {
V_3 = & V_5 [ V_4 ] ;
if ( V_3 -> V_6 == V_2 )
break;
}
if ( V_4 == F_2 ( V_5 ) )
return NULL ;
return & V_5 [ V_4 ] ;
}
static const struct V_1 * F_3 ( struct V_7 * V_8 )
{
return F_1 ( V_8 -> V_3 . V_9 . V_2 ) ;
}
static void F_4 ( struct V_10 * V_11 )
{
T_2 V_12 , V_13 , V_14 ;
int V_4 , V_15 ;
for ( V_4 = 0 ; V_4 < 9 ; V_4 ++ ) {
V_12 = V_16 [ V_11 -> V_17 ] . V_18 [ V_4 ] [ 0 ] ;
V_13 = V_16 [ V_11 -> V_17 ] . V_18 [ V_4 ] [ 1 ] ;
V_14 = V_16 [ V_11 -> V_17 ] . V_18 [ V_4 ] [ 2 ] ;
V_15 = V_11 -> V_3 -> V_15 ;
switch ( V_11 -> V_3 -> V_6 ) {
case V_19 :
case V_20 :
V_12 >>= 3 ;
V_13 >>= 2 ;
V_14 >>= 3 ;
break;
case V_21 :
case V_22 :
V_12 >>= 3 ;
V_13 >>= 3 ;
V_14 >>= 3 ;
break;
case V_23 :
case V_24 :
case V_25 :
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
break;
}
if ( V_15 ) {
V_11 -> V_16 [ V_4 ] [ 0 ] = F_5 ( V_12 , V_13 , V_14 ) ;
V_11 -> V_16 [ V_4 ] [ 1 ] = F_6 ( V_12 , V_13 , V_14 ) ;
V_11 -> V_16 [ V_4 ] [ 2 ] = F_7 ( V_12 , V_13 , V_14 ) ;
} else {
V_11 -> V_16 [ V_4 ] [ 0 ] = V_12 ;
V_11 -> V_16 [ V_4 ] [ 1 ] = V_13 ;
V_11 -> V_16 [ V_4 ] [ 2 ] = V_14 ;
}
}
}
static void F_8 ( struct V_10 * V_11 , T_2 * V_31 , int V_32 , bool V_33 )
{
T_2 V_34 , V_35 , V_36 ;
T_2 V_37 = V_11 -> V_38 ;
int V_39 ;
T_2 * V_40 ;
V_34 = V_11 -> V_16 [ V_32 ] [ 0 ] ;
V_35 = V_11 -> V_16 [ V_32 ] [ 1 ] ;
V_36 = V_11 -> V_16 [ V_32 ] [ 2 ] ;
for ( V_39 = 0 ; V_39 < V_11 -> V_41 ; V_39 ++ ) {
V_40 = V_31 + V_39 ;
switch ( V_11 -> V_3 -> V_6 ) {
case V_23 :
switch ( V_39 ) {
case 0 :
* V_40 = V_34 ;
break;
case 1 :
* V_40 = V_33 ? V_36 : V_35 ;
break;
}
break;
case V_24 :
switch ( V_39 ) {
case 0 :
* V_40 = V_33 ? V_36 : V_35 ;
break;
case 1 :
* V_40 = V_34 ;
break;
}
break;
case V_25 :
switch ( V_39 ) {
case 0 :
* V_40 = V_34 ;
break;
case 1 :
* V_40 = V_33 ? V_35 : V_36 ;
break;
}
break;
case V_26 :
switch ( V_39 ) {
case 0 :
* V_40 = V_33 ? V_35 : V_36 ;
break;
case 1 :
* V_40 = V_34 ;
break;
}
break;
case V_19 :
switch ( V_39 ) {
case 0 :
* V_40 = ( V_35 << 5 ) | V_36 ;
break;
case 1 :
* V_40 = ( V_34 << 3 ) | ( V_35 >> 3 ) ;
break;
}
break;
case V_20 :
switch ( V_39 ) {
case 0 :
* V_40 = ( V_34 << 3 ) | ( V_35 >> 3 ) ;
break;
case 1 :
* V_40 = ( V_35 << 5 ) | V_36 ;
break;
}
break;
case V_21 :
switch ( V_39 ) {
case 0 :
* V_40 = ( V_35 << 5 ) | V_36 ;
break;
case 1 :
* V_40 = ( V_37 & 0x80 ) | ( V_34 << 2 ) | ( V_35 >> 3 ) ;
break;
}
break;
case V_22 :
switch ( V_39 ) {
case 0 :
* V_40 = ( V_37 & 0x80 ) | ( V_34 << 2 ) | ( V_35 >> 3 ) ;
break;
case 1 :
* V_40 = ( V_35 << 5 ) | V_36 ;
break;
}
break;
case V_27 :
switch ( V_39 ) {
case 0 :
* V_40 = V_34 ;
break;
case 1 :
* V_40 = V_35 ;
break;
case 2 :
* V_40 = V_36 ;
break;
}
break;
case V_28 :
switch ( V_39 ) {
case 0 :
* V_40 = V_36 ;
break;
case 1 :
* V_40 = V_35 ;
break;
case 2 :
* V_40 = V_34 ;
break;
}
break;
case V_29 :
switch ( V_39 ) {
case 0 :
* V_40 = V_37 ;
break;
case 1 :
* V_40 = V_34 ;
break;
case 2 :
* V_40 = V_35 ;
break;
case 3 :
* V_40 = V_36 ;
break;
}
break;
case V_30 :
switch ( V_39 ) {
case 0 :
* V_40 = V_36 ;
break;
case 1 :
* V_40 = V_35 ;
break;
case 2 :
* V_40 = V_34 ;
break;
case 3 :
* V_40 = V_37 ;
break;
}
break;
}
}
}
static void F_9 ( struct V_10 * V_11 )
{
unsigned V_42 = V_11 -> V_41 ;
unsigned V_43 = 2 * V_42 ;
int V_32 ;
T_2 * V_44 ;
for ( V_32 = 0 ; V_32 < 16 ; ++ V_32 ) {
T_2 V_9 [ 8 ] ;
int V_45 = V_32 * V_11 -> V_46 / 8 ;
int V_47 = ( V_32 + 1 ) * V_11 -> V_46 / 8 ;
int V_48 ;
F_8 ( V_11 , & V_9 [ 0 ] , V_32 % 8 , 0 ) ;
F_8 ( V_11 , & V_9 [ V_42 ] , V_32 % 8 , 1 ) ;
for ( V_48 = V_45 / 2 * 2 , V_44 = V_11 -> line + V_48 * V_42 ; V_48 < V_47 ; V_48 += 2 , V_44 += V_43 )
memcpy ( V_44 , V_9 , V_43 ) ;
}
}
static void F_10 ( struct V_10 * V_11 , char * V_49 ,
int V_50 , int V_51 , char * V_52 )
{
int line ;
unsigned int V_46 = V_11 -> V_46 ;
if ( V_50 + 16 >= V_11 -> V_53 || V_51 + strlen ( V_52 ) * 8 >= V_46 )
return;
#define F_11 ( T_3 ) do { \
PIXTYPE fg; \
PIXTYPE bg; \
memcpy(&fg, &dev->textfg, sizeof(PIXTYPE)); \
memcpy(&bg, &dev->textbg, sizeof(PIXTYPE)); \
\
for (line = 0; line < 16; line++) { \
PIXTYPE *pos = (PIXTYPE *)( basep + ((y + line) * width + x) * sizeof(PIXTYPE) ); \
u8 *s; \
\
for (s = text; *s; s++) { \
u8 chr = font8x16[*s * 16 + line]; \
\
pos[0] = (chr & (0x01 << 7) ? fg : bg); \
pos[1] = (chr & (0x01 << 6) ? fg : bg); \
pos[2] = (chr & (0x01 << 5) ? fg : bg); \
pos[3] = (chr & (0x01 << 4) ? fg : bg); \
pos[4] = (chr & (0x01 << 3) ? fg : bg); \
pos[5] = (chr & (0x01 << 2) ? fg : bg); \
pos[6] = (chr & (0x01 << 1) ? fg : bg); \
pos[7] = (chr & (0x01 << 0) ? fg : bg); \
\
pos += 8; \
} \
} \
} while (0)
switch ( V_11 -> V_41 ) {
case 2 :
F_11 ( V_54 ) ; break;
case 4 :
F_11 ( T_1 ) ; break;
case 3 :
F_11 ( V_55 ) ; break;
}
}
static void F_12 ( struct V_10 * V_11 , struct V_56 * V_31 )
{
int V_57 = V_11 -> V_46 * V_11 -> V_41 ;
int V_58 = V_11 -> V_53 ;
void * V_59 = F_13 ( & V_31 -> V_60 , 0 ) ;
unsigned V_61 ;
char V_62 [ 100 ] ;
int V_63 , line = 1 ;
T_2 * V_64 ;
T_4 V_65 ;
if ( ! V_59 )
return;
V_64 = V_11 -> line + ( V_11 -> V_66 % V_11 -> V_46 ) * V_11 -> V_41 ;
for ( V_63 = 0 ; V_63 < V_58 ; V_63 ++ )
memcpy ( V_59 + V_63 * V_57 , V_64 , V_57 ) ;
F_8 ( V_11 , ( T_2 * ) & V_11 -> V_67 , V_68 , 0 ) ;
F_8 ( V_11 , ( T_2 * ) & V_11 -> V_69 , V_70 , 0 ) ;
V_11 -> V_61 += F_14 ( V_71 - V_11 -> V_71 ) ;
V_11 -> V_71 = V_71 ;
V_61 = V_11 -> V_61 ;
snprintf ( V_62 , sizeof( V_62 ) , L_1 ,
( V_61 / ( 60 * 60 * 1000 ) ) % 24 ,
( V_61 / ( 60 * 1000 ) ) % 60 ,
( V_61 / 1000 ) % 60 ,
V_61 % 1000 ) ;
F_10 ( V_11 , V_59 , line ++ * 16 , 16 , V_62 ) ;
snprintf ( V_62 , sizeof( V_62 ) , L_2 ,
V_11 -> V_46 , V_11 -> V_53 , V_11 -> V_17 ) ;
F_10 ( V_11 , V_59 , line ++ * 16 , 16 , V_62 ) ;
V_65 = F_15 ( V_11 -> V_65 ) ;
F_16 ( V_11 -> V_72 . V_73 ) ;
snprintf ( V_62 , sizeof( V_62 ) , L_3 ,
V_11 -> V_74 -> V_75 . V_76 ,
V_11 -> V_77 -> V_75 . V_76 ,
V_11 -> V_78 -> V_75 . V_76 ,
V_11 -> V_79 -> V_75 . V_76 ) ;
F_10 ( V_11 , V_59 , line ++ * 16 , 16 , V_62 ) ;
snprintf ( V_62 , sizeof( V_62 ) , L_4 ,
V_11 -> V_80 -> V_75 . V_76 , V_65 , V_11 -> V_81 -> V_75 . V_76 ,
V_11 -> V_37 -> V_75 . V_76 ) ;
F_10 ( V_11 , V_59 , line ++ * 16 , 16 , V_62 ) ;
snprintf ( V_62 , sizeof( V_62 ) , L_5 ,
V_11 -> V_82 -> V_75 . V_76 ,
* V_11 -> V_83 -> V_84 . V_85 ,
V_11 -> V_86 -> V_75 . V_76 ) ;
F_10 ( V_11 , V_59 , line ++ * 16 , 16 , V_62 ) ;
snprintf ( V_62 , sizeof( V_62 ) , L_6 ,
V_11 -> boolean -> V_75 . V_76 ,
V_11 -> V_87 -> V_88 [ V_11 -> V_87 -> V_75 . V_76 ] ,
V_11 -> string -> V_84 . V_89 ) ;
F_10 ( V_11 , V_59 , line ++ * 16 , 16 , V_62 ) ;
snprintf ( V_62 , sizeof( V_62 ) , L_7 ,
V_11 -> V_90 -> V_91 [ V_11 -> V_90 -> V_75 . V_76 ] ,
V_11 -> V_90 -> V_75 . V_76 ) ;
F_10 ( V_11 , V_59 , line ++ * 16 , 16 , V_62 ) ;
F_17 ( V_11 -> V_72 . V_73 ) ;
if ( V_11 -> V_92 ) {
V_11 -> V_92 -- ;
snprintf ( V_62 , sizeof( V_62 ) , L_8 ) ;
F_10 ( V_11 , V_59 , line ++ * 16 , 16 , V_62 ) ;
}
V_11 -> V_66 += 2 ;
V_31 -> V_60 . V_93 . V_94 = V_95 ;
V_31 -> V_60 . V_93 . V_96 = V_11 -> V_97 ++ ;
F_18 ( & V_31 -> V_60 . V_93 . V_98 ) ;
}
static void F_19 ( struct V_10 * V_11 )
{
struct V_99 * V_100 = & V_11 -> V_101 ;
struct V_56 * V_31 ;
unsigned long V_102 = 0 ;
F_20 ( V_11 , 1 , L_9 ) ;
F_21 ( & V_11 -> V_103 , V_102 ) ;
if ( F_22 ( & V_100 -> V_104 ) ) {
F_20 ( V_11 , 1 , L_10 ) ;
F_23 ( & V_11 -> V_103 , V_102 ) ;
return;
}
V_31 = F_24 ( V_100 -> V_104 . V_105 , struct V_56 , V_106 ) ;
F_25 ( & V_31 -> V_106 ) ;
F_23 ( & V_11 -> V_103 , V_102 ) ;
F_18 ( & V_31 -> V_60 . V_93 . V_98 ) ;
F_12 ( V_11 , V_31 ) ;
F_20 ( V_11 , 1 , L_11 , V_31 ) ;
F_26 ( & V_31 -> V_60 , V_107 ) ;
F_20 ( V_11 , 2 , L_12 , V_31 , V_31 -> V_60 . V_93 . V_108 ) ;
}
static void F_27 ( struct V_10 * V_11 )
{
struct V_99 * V_100 = & V_11 -> V_101 ;
int V_109 ;
F_28 ( V_110 , V_111 ) ;
F_20 ( V_11 , 1 , L_13 , V_112 ,
( unsigned long ) V_100 ) ;
F_29 ( & V_100 -> V_113 , & V_110 ) ;
if ( F_30 () )
goto V_114;
V_109 = F_31 ( F_32 ( V_11 , 1 ) ) ;
F_19 ( V_11 ) ;
F_33 ( V_109 ) ;
V_114:
F_34 ( & V_100 -> V_113 , & V_110 ) ;
F_35 () ;
}
static int F_36 ( void * V_115 )
{
struct V_10 * V_11 = V_115 ;
F_20 ( V_11 , 1 , L_14 ) ;
F_37 () ;
for (; ; ) {
F_27 ( V_11 ) ;
if ( F_30 () )
break;
}
F_20 ( V_11 , 1 , L_15 ) ;
return 0 ;
}
static int F_38 ( struct V_10 * V_11 )
{
struct V_99 * V_100 = & V_11 -> V_101 ;
F_20 ( V_11 , 1 , L_16 , V_112 ) ;
V_11 -> V_61 = 0 ;
V_11 -> V_66 = 0 ;
V_11 -> V_71 = V_71 ;
V_100 -> V_116 = 0 ;
V_100 -> V_117 = V_71 ;
V_100 -> V_118 = F_39 ( F_36 , V_11 , L_17 ,
V_11 -> V_119 . V_120 ) ;
if ( F_40 ( V_100 -> V_118 ) ) {
F_41 ( & V_11 -> V_119 , L_18 ) ;
return F_42 ( V_100 -> V_118 ) ;
}
F_43 ( & V_100 -> V_113 ) ;
F_20 ( V_11 , 1 , L_19 , V_112 ) ;
return 0 ;
}
static void F_44 ( struct V_10 * V_11 )
{
struct V_99 * V_100 = & V_11 -> V_101 ;
F_20 ( V_11 , 1 , L_16 , V_112 ) ;
if ( V_100 -> V_118 ) {
F_45 ( V_100 -> V_118 ) ;
V_100 -> V_118 = NULL ;
}
while ( ! F_22 ( & V_100 -> V_104 ) ) {
struct V_56 * V_31 ;
V_31 = F_24 ( V_100 -> V_104 . V_105 , struct V_56 , V_106 ) ;
F_25 ( & V_31 -> V_106 ) ;
F_26 ( & V_31 -> V_60 , V_121 ) ;
F_20 ( V_11 , 2 , L_12 , V_31 , V_31 -> V_60 . V_93 . V_108 ) ;
}
}
static int F_46 ( struct V_122 * V_123 , const struct V_7 * V_3 ,
unsigned int * V_124 , unsigned int * V_125 ,
unsigned int V_126 [] , void * V_127 [] )
{
struct V_10 * V_11 = F_47 ( V_123 ) ;
unsigned long V_128 ;
V_128 = V_11 -> V_46 * V_11 -> V_53 * V_11 -> V_41 ;
if ( V_3 ) {
if ( V_3 -> V_3 . V_9 . V_129 < V_128 )
return - V_130 ;
V_128 = V_3 -> V_3 . V_9 . V_129 ;
if ( V_128 > 7680 * 4320 * V_11 -> V_41 )
return - V_130 ;
}
* V_125 = 1 ;
V_126 [ 0 ] = V_128 ;
F_20 ( V_11 , 1 , L_20 , V_112 ,
* V_124 , V_128 ) ;
return 0 ;
}
static int F_48 ( struct V_131 * V_60 )
{
struct V_10 * V_11 = F_47 ( V_60 -> V_122 ) ;
struct V_56 * V_31 = F_49 ( V_60 , struct V_56 , V_60 ) ;
unsigned long V_128 ;
F_20 ( V_11 , 1 , L_21 , V_112 , V_60 -> V_93 . V_94 ) ;
F_50 ( NULL == V_11 -> V_3 ) ;
if ( V_11 -> V_46 < 48 || V_11 -> V_46 > V_132 ||
V_11 -> V_53 < 32 || V_11 -> V_53 > V_133 )
return - V_130 ;
V_128 = V_11 -> V_46 * V_11 -> V_53 * V_11 -> V_41 ;
if ( F_51 ( V_60 , 0 ) < V_128 ) {
F_20 ( V_11 , 1 , L_22 ,
V_112 , F_51 ( V_60 , 0 ) , V_128 ) ;
return - V_130 ;
}
F_52 ( & V_31 -> V_60 , 0 , V_128 ) ;
F_4 ( V_11 ) ;
F_9 ( V_11 ) ;
return 0 ;
}
static void F_53 ( struct V_131 * V_60 )
{
struct V_10 * V_11 = F_47 ( V_60 -> V_122 ) ;
struct V_56 * V_31 = F_49 ( V_60 , struct V_56 , V_60 ) ;
struct V_99 * V_101 = & V_11 -> V_101 ;
unsigned long V_102 = 0 ;
F_20 ( V_11 , 1 , L_16 , V_112 ) ;
F_21 ( & V_11 -> V_103 , V_102 ) ;
F_54 ( & V_31 -> V_106 , & V_101 -> V_104 ) ;
F_23 ( & V_11 -> V_103 , V_102 ) ;
}
static int F_55 ( struct V_122 * V_123 , unsigned int V_134 )
{
struct V_10 * V_11 = F_47 ( V_123 ) ;
int V_135 ;
F_20 ( V_11 , 1 , L_16 , V_112 ) ;
V_11 -> V_97 = 0 ;
V_135 = F_38 ( V_11 ) ;
if ( V_135 ) {
struct V_56 * V_31 , * V_136 ;
F_56 (buf, tmp, &dev->vidq.active, list) {
F_25 ( & V_31 -> V_106 ) ;
F_26 ( & V_31 -> V_60 , V_137 ) ;
}
}
return V_135 ;
}
static void F_57 ( struct V_122 * V_123 )
{
struct V_10 * V_11 = F_47 ( V_123 ) ;
F_20 ( V_11 , 1 , L_16 , V_112 ) ;
F_44 ( V_11 ) ;
}
static void F_58 ( struct V_122 * V_123 )
{
struct V_10 * V_11 = F_47 ( V_123 ) ;
F_16 ( & V_11 -> V_138 ) ;
}
static void F_59 ( struct V_122 * V_123 )
{
struct V_10 * V_11 = F_47 ( V_123 ) ;
F_17 ( & V_11 -> V_138 ) ;
}
static int F_60 ( struct V_139 * V_139 , void * V_140 ,
struct V_141 * V_142 )
{
struct V_10 * V_11 = F_61 ( V_139 ) ;
strcpy ( V_142 -> V_143 , L_23 ) ;
strcpy ( V_142 -> V_144 , L_23 ) ;
snprintf ( V_142 -> V_145 , sizeof( V_142 -> V_145 ) ,
L_24 , V_11 -> V_119 . V_120 ) ;
V_142 -> V_146 = V_147 | V_148 |
V_149 ;
V_142 -> V_150 = V_142 -> V_146 | V_151 ;
return 0 ;
}
static int F_62 ( struct V_139 * V_139 , void * V_140 ,
struct V_152 * V_8 )
{
const struct V_1 * V_3 ;
if ( V_8 -> V_108 >= F_2 ( V_5 ) )
return - V_130 ;
V_3 = & V_5 [ V_8 -> V_108 ] ;
F_63 ( V_8 -> V_153 , V_3 -> V_120 , sizeof( V_8 -> V_153 ) ) ;
V_8 -> V_2 = V_3 -> V_6 ;
return 0 ;
}
static int F_64 ( struct V_139 * V_139 , void * V_140 ,
struct V_7 * V_8 )
{
struct V_10 * V_11 = F_61 ( V_139 ) ;
V_8 -> V_3 . V_9 . V_46 = V_11 -> V_46 ;
V_8 -> V_3 . V_9 . V_53 = V_11 -> V_53 ;
V_8 -> V_3 . V_9 . V_94 = V_95 ;
V_8 -> V_3 . V_9 . V_2 = V_11 -> V_3 -> V_6 ;
V_8 -> V_3 . V_9 . V_154 =
( V_8 -> V_3 . V_9 . V_46 * V_11 -> V_3 -> V_155 ) >> 3 ;
V_8 -> V_3 . V_9 . V_129 =
V_8 -> V_3 . V_9 . V_53 * V_8 -> V_3 . V_9 . V_154 ;
if ( V_11 -> V_3 -> V_15 )
V_8 -> V_3 . V_9 . V_156 = V_157 ;
else
V_8 -> V_3 . V_9 . V_156 = V_158 ;
return 0 ;
}
static int F_65 ( struct V_139 * V_139 , void * V_140 ,
struct V_7 * V_8 )
{
struct V_10 * V_11 = F_61 ( V_139 ) ;
const struct V_1 * V_3 ;
V_3 = F_3 ( V_8 ) ;
if ( ! V_3 ) {
F_20 ( V_11 , 1 , L_25 ,
V_8 -> V_3 . V_9 . V_2 ) ;
V_8 -> V_3 . V_9 . V_2 = V_23 ;
V_3 = F_3 ( V_8 ) ;
}
V_8 -> V_3 . V_9 . V_94 = V_95 ;
F_66 ( & V_8 -> V_3 . V_9 . V_46 , 48 , V_132 , 2 ,
& V_8 -> V_3 . V_9 . V_53 , 32 , V_133 , 0 , 0 ) ;
V_8 -> V_3 . V_9 . V_154 =
( V_8 -> V_3 . V_9 . V_46 * V_3 -> V_155 ) >> 3 ;
V_8 -> V_3 . V_9 . V_129 =
V_8 -> V_3 . V_9 . V_53 * V_8 -> V_3 . V_9 . V_154 ;
if ( V_3 -> V_15 )
V_8 -> V_3 . V_9 . V_156 = V_157 ;
else
V_8 -> V_3 . V_9 . V_156 = V_158 ;
return 0 ;
}
static int F_67 ( struct V_139 * V_139 , void * V_140 ,
struct V_7 * V_8 )
{
struct V_10 * V_11 = F_61 ( V_139 ) ;
struct V_122 * V_159 = & V_11 -> V_160 ;
int V_161 = F_65 ( V_139 , V_140 , V_8 ) ;
if ( V_161 < 0 )
return V_161 ;
if ( F_68 ( V_159 ) ) {
F_20 ( V_11 , 1 , L_26 , V_112 ) ;
return - V_162 ;
}
V_11 -> V_3 = F_3 ( V_8 ) ;
V_11 -> V_41 = V_11 -> V_3 -> V_155 / 8 ;
V_11 -> V_46 = V_8 -> V_3 . V_9 . V_46 ;
V_11 -> V_53 = V_8 -> V_3 . V_9 . V_53 ;
return 0 ;
}
static int F_69 ( struct V_139 * V_139 , void * V_163 ,
struct V_164 * V_165 )
{
static const struct V_166 V_126 = {
48 , V_132 , 4 ,
32 , V_133 , 1
} ;
int V_167 ;
if ( V_165 -> V_108 )
return - V_130 ;
for ( V_167 = 0 ; V_167 < F_2 ( V_5 ) ; V_167 ++ )
if ( V_5 [ V_167 ] . V_6 == V_165 -> V_168 )
break;
if ( V_167 == F_2 ( V_5 ) )
return - V_130 ;
V_165 -> type = V_169 ;
V_165 -> V_170 = V_126 ;
return 0 ;
}
static int F_70 ( struct V_139 * V_139 , void * V_140 ,
struct V_171 * V_172 )
{
if ( V_172 -> V_108 >= V_173 )
return - V_130 ;
V_172 -> type = V_174 ;
sprintf ( V_172 -> V_120 , L_27 , V_172 -> V_108 ) ;
return 0 ;
}
static int F_71 ( struct V_139 * V_139 , void * V_140 , unsigned int * V_167 )
{
struct V_10 * V_11 = F_61 ( V_139 ) ;
* V_167 = V_11 -> V_17 ;
return 0 ;
}
static int F_72 ( struct V_139 * V_139 , void * V_140 , unsigned int V_167 )
{
struct V_10 * V_11 = F_61 ( V_139 ) ;
if ( V_167 >= V_173 )
return - V_130 ;
if ( V_167 == V_11 -> V_17 )
return 0 ;
V_11 -> V_17 = V_167 ;
F_73 ( V_11 -> V_74 ,
128 * V_167 , 255 + 128 * V_167 , 1 , 127 + 128 * V_167 ) ;
F_4 ( V_11 ) ;
F_9 ( V_11 ) ;
return 0 ;
}
static int F_74 ( struct V_139 * V_139 , void * V_140 ,
struct V_175 * V_176 )
{
const struct V_1 * V_3 ;
if ( V_176 -> V_108 )
return - V_130 ;
V_3 = F_1 ( V_176 -> V_168 ) ;
if ( ! V_3 )
return - V_130 ;
if ( V_176 -> V_46 < 48 || V_176 -> V_46 > V_132 || ( V_176 -> V_46 & 3 ) )
return - V_130 ;
if ( V_176 -> V_53 < 32 || V_176 -> V_53 > V_133 )
return - V_130 ;
V_176 -> type = V_177 ;
V_176 -> V_170 . V_178 = V_179 ;
V_176 -> V_170 . V_180 = V_181 ;
V_176 -> V_170 . V_182 = (struct V_183 ) { 1 , 1 } ;
return 0 ;
}
static int F_75 ( struct V_139 * V_139 , void * V_140 ,
struct V_184 * V_185 )
{
struct V_10 * V_11 = F_61 ( V_139 ) ;
if ( V_185 -> type != V_186 )
return - V_130 ;
V_185 -> V_185 . V_187 . V_188 = V_189 ;
V_185 -> V_185 . V_187 . V_190 = V_11 -> V_190 ;
V_185 -> V_185 . V_187 . V_191 = 1 ;
return 0 ;
}
static int F_76 ( struct V_139 * V_139 , void * V_140 ,
struct V_184 * V_185 )
{
struct V_10 * V_11 = F_61 ( V_139 ) ;
struct V_183 V_192 ;
if ( V_185 -> type != V_186 )
return - V_130 ;
V_192 = V_185 -> V_185 . V_187 . V_190 ;
V_192 = V_192 . V_193 ? V_192 : V_194 ;
V_192 = F_77 ( V_192 , < , V_179 ) ? V_179 : V_192 ;
V_192 = F_77 ( V_192 , > , V_181 ) ? V_181 : V_192 ;
V_11 -> V_190 = V_192 ;
V_185 -> V_185 . V_187 . V_190 = V_192 ;
V_185 -> V_185 . V_187 . V_191 = 1 ;
return 0 ;
}
static int F_78 ( struct V_195 * V_196 )
{
struct V_10 * V_11 = F_49 ( V_196 -> V_197 , struct V_10 , V_72 ) ;
if ( V_196 == V_11 -> V_80 )
V_11 -> V_65 -> V_76 = V_71 & 0xff ;
return 0 ;
}
static int F_79 ( struct V_195 * V_196 )
{
struct V_10 * V_11 = F_49 ( V_196 -> V_197 , struct V_10 , V_72 ) ;
switch ( V_196 -> V_198 ) {
case V_199 :
V_11 -> V_38 = V_196 -> V_76 ;
break;
default:
if ( V_196 == V_11 -> V_200 )
V_11 -> V_92 = 30 ;
break;
}
return 0 ;
}
static int F_80 ( void )
{
struct V_10 * V_11 ;
struct V_201 * V_106 ;
while ( ! F_22 ( & V_202 ) ) {
V_106 = V_202 . V_105 ;
F_25 ( V_106 ) ;
V_11 = F_24 ( V_106 , struct V_10 , V_202 ) ;
F_81 ( & V_11 -> V_119 , L_28 ,
F_82 ( & V_11 -> V_203 ) ) ;
F_83 ( & V_11 -> V_203 ) ;
F_84 ( & V_11 -> V_119 ) ;
F_85 ( & V_11 -> V_72 ) ;
F_86 ( V_11 ) ;
}
return 0 ;
}
static int T_5 F_87 ( int V_204 )
{
struct V_10 * V_11 ;
struct V_205 * V_206 ;
struct V_207 * V_208 ;
struct V_122 * V_159 ;
int V_161 ;
V_11 = F_88 ( sizeof( * V_11 ) , V_209 ) ;
if ( ! V_11 )
return - V_210 ;
snprintf ( V_11 -> V_119 . V_120 , sizeof( V_11 -> V_119 . V_120 ) ,
L_29 , V_211 , V_204 ) ;
V_161 = F_89 ( NULL , & V_11 -> V_119 ) ;
if ( V_161 )
goto V_212;
V_11 -> V_3 = & V_5 [ 0 ] ;
V_11 -> V_190 = V_194 ;
V_11 -> V_46 = 640 ;
V_11 -> V_53 = 480 ;
V_11 -> V_41 = V_11 -> V_3 -> V_155 / 8 ;
V_208 = & V_11 -> V_72 ;
F_90 ( V_208 , 11 ) ;
V_11 -> V_81 = F_91 ( V_208 , & V_213 ,
V_214 , 0 , 255 , 1 , 200 ) ;
V_11 -> V_74 = F_91 ( V_208 , & V_213 ,
V_215 , 0 , 255 , 1 , 127 ) ;
V_11 -> V_77 = F_91 ( V_208 , & V_213 ,
V_216 , 0 , 255 , 1 , 16 ) ;
V_11 -> V_78 = F_91 ( V_208 , & V_213 ,
V_217 , 0 , 255 , 1 , 127 ) ;
V_11 -> V_79 = F_91 ( V_208 , & V_213 ,
V_218 , - 128 , 127 , 1 , 0 ) ;
V_11 -> V_80 = F_91 ( V_208 , & V_213 ,
V_219 , 0 , 1 , 1 , 1 ) ;
V_11 -> V_65 = F_91 ( V_208 , & V_213 ,
V_220 , 0 , 255 , 1 , 100 ) ;
V_11 -> V_37 = F_91 ( V_208 , & V_213 ,
V_199 , 0 , 255 , 1 , 0 ) ;
V_11 -> V_200 = F_92 ( V_208 , & V_221 , NULL ) ;
V_11 -> V_82 = F_92 ( V_208 , & V_222 , NULL ) ;
V_11 -> V_83 = F_92 ( V_208 , & V_223 , NULL ) ;
V_11 -> boolean = F_92 ( V_208 , & V_224 , NULL ) ;
V_11 -> V_87 = F_92 ( V_208 , & V_225 , NULL ) ;
V_11 -> string = F_92 ( V_208 , & V_226 , NULL ) ;
V_11 -> V_86 = F_92 ( V_208 , & V_227 , NULL ) ;
V_11 -> V_90 = F_92 ( V_208 , & V_228 , NULL ) ;
if ( V_208 -> error ) {
V_161 = V_208 -> error ;
goto V_229;
}
F_93 ( 2 , & V_11 -> V_80 , 0 , true ) ;
V_11 -> V_119 . V_72 = V_208 ;
F_94 ( & V_11 -> V_103 ) ;
V_159 = & V_11 -> V_160 ;
V_159 -> type = V_186 ;
V_159 -> V_230 = V_231 | V_232 | V_233 | V_234 ;
V_159 -> V_235 = V_11 ;
V_159 -> V_236 = sizeof( struct V_56 ) ;
V_159 -> V_237 = & V_238 ;
V_159 -> V_239 = & V_240 ;
V_159 -> V_241 = V_242 ;
V_161 = F_95 ( V_159 ) ;
if ( V_161 )
goto V_229;
F_96 ( & V_11 -> V_138 ) ;
F_97 ( & V_11 -> V_101 . V_104 ) ;
F_98 ( & V_11 -> V_101 . V_113 ) ;
V_206 = & V_11 -> V_203 ;
* V_206 = V_243 ;
V_206 -> V_244 = V_244 ;
V_206 -> V_119 = & V_11 -> V_119 ;
V_206 -> V_245 = V_159 ;
V_206 -> V_73 = & V_11 -> V_138 ;
F_99 ( V_206 , V_11 ) ;
V_161 = F_100 ( V_206 , V_246 , V_247 ) ;
if ( V_161 < 0 )
goto V_229;
F_54 ( & V_11 -> V_202 , & V_202 ) ;
F_81 ( & V_11 -> V_119 , L_30 ,
F_82 ( V_206 ) ) ;
return 0 ;
V_229:
F_85 ( V_208 ) ;
F_84 ( & V_11 -> V_119 ) ;
V_212:
F_86 ( V_11 ) ;
return V_161 ;
}
static int T_5 F_101 ( void )
{
const struct V_248 * V_249 = F_102 ( L_31 ) ;
int V_161 = 0 , V_167 ;
if ( V_249 == NULL ) {
F_103 ( V_250 L_32 ) ;
return - V_251 ;
}
V_252 = V_249 -> V_115 ;
if ( V_253 <= 0 )
V_253 = 1 ;
for ( V_167 = 0 ; V_167 < V_253 ; V_167 ++ ) {
V_161 = F_87 ( V_167 ) ;
if ( V_161 ) {
if ( V_167 )
V_161 = 0 ;
break;
}
}
if ( V_161 < 0 ) {
F_103 ( V_250 L_33 , V_161 ) ;
return V_161 ;
}
F_103 ( V_254 L_34
L_35 ,
V_255 ) ;
V_253 = V_167 ;
return V_161 ;
}
static void T_6 F_104 ( void )
{
F_80 () ;
}
