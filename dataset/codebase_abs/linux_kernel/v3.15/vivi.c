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
V_11 -> V_83 -> V_75 . V_84 ,
V_11 -> V_85 -> V_75 . V_76 ) ;
F_10 ( V_11 , V_59 , line ++ * 16 , 16 , V_62 ) ;
snprintf ( V_62 , sizeof( V_62 ) , L_6 ,
V_11 -> boolean -> V_75 . V_76 ,
V_11 -> V_86 -> V_87 [ V_11 -> V_86 -> V_75 . V_76 ] ,
V_11 -> string -> V_75 . string ) ;
F_10 ( V_11 , V_59 , line ++ * 16 , 16 , V_62 ) ;
snprintf ( V_62 , sizeof( V_62 ) , L_7 ,
V_11 -> V_88 -> V_89 [ V_11 -> V_88 -> V_75 . V_76 ] ,
V_11 -> V_88 -> V_75 . V_76 ) ;
F_10 ( V_11 , V_59 , line ++ * 16 , 16 , V_62 ) ;
F_17 ( V_11 -> V_72 . V_73 ) ;
if ( V_11 -> V_90 ) {
V_11 -> V_90 -- ;
snprintf ( V_62 , sizeof( V_62 ) , L_8 ) ;
F_10 ( V_11 , V_59 , line ++ * 16 , 16 , V_62 ) ;
}
V_11 -> V_66 += 2 ;
V_31 -> V_60 . V_91 . V_92 = V_93 ;
V_31 -> V_60 . V_91 . V_94 = V_11 -> V_95 ++ ;
F_18 ( & V_31 -> V_60 . V_91 . V_96 ) ;
}
static void F_19 ( struct V_10 * V_11 )
{
struct V_97 * V_98 = & V_11 -> V_99 ;
struct V_56 * V_31 ;
unsigned long V_100 = 0 ;
F_20 ( V_11 , 1 , L_9 ) ;
F_21 ( & V_11 -> V_101 , V_100 ) ;
if ( F_22 ( & V_98 -> V_102 ) ) {
F_20 ( V_11 , 1 , L_10 ) ;
F_23 ( & V_11 -> V_101 , V_100 ) ;
return;
}
V_31 = F_24 ( V_98 -> V_102 . V_103 , struct V_56 , V_104 ) ;
F_25 ( & V_31 -> V_104 ) ;
F_23 ( & V_11 -> V_101 , V_100 ) ;
F_18 ( & V_31 -> V_60 . V_91 . V_96 ) ;
F_12 ( V_11 , V_31 ) ;
F_20 ( V_11 , 1 , L_11 , V_31 ) ;
F_26 ( & V_31 -> V_60 , V_105 ) ;
F_20 ( V_11 , 2 , L_12 , V_31 , V_31 -> V_60 . V_91 . V_106 ) ;
}
static void F_27 ( struct V_10 * V_11 )
{
struct V_97 * V_98 = & V_11 -> V_99 ;
int V_107 ;
F_28 ( V_108 , V_109 ) ;
F_20 ( V_11 , 1 , L_13 , V_110 ,
( unsigned long ) V_98 ) ;
F_29 ( & V_98 -> V_111 , & V_108 ) ;
if ( F_30 () )
goto V_112;
V_107 = F_31 ( F_32 ( V_11 , 1 ) ) ;
F_19 ( V_11 ) ;
F_33 ( V_107 ) ;
V_112:
F_34 ( & V_98 -> V_111 , & V_108 ) ;
F_35 () ;
}
static int F_36 ( void * V_113 )
{
struct V_10 * V_11 = V_113 ;
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
struct V_97 * V_98 = & V_11 -> V_99 ;
F_20 ( V_11 , 1 , L_16 , V_110 ) ;
V_11 -> V_61 = 0 ;
V_11 -> V_66 = 0 ;
V_11 -> V_71 = V_71 ;
V_98 -> V_114 = 0 ;
V_98 -> V_115 = V_71 ;
V_98 -> V_116 = F_39 ( F_36 , V_11 , L_17 ,
V_11 -> V_117 . V_118 ) ;
if ( F_40 ( V_98 -> V_116 ) ) {
F_41 ( & V_11 -> V_117 , L_18 ) ;
return F_42 ( V_98 -> V_116 ) ;
}
F_43 ( & V_98 -> V_111 ) ;
F_20 ( V_11 , 1 , L_19 , V_110 ) ;
return 0 ;
}
static void F_44 ( struct V_10 * V_11 )
{
struct V_97 * V_98 = & V_11 -> V_99 ;
F_20 ( V_11 , 1 , L_16 , V_110 ) ;
if ( V_98 -> V_116 ) {
F_45 ( V_98 -> V_116 ) ;
V_98 -> V_116 = NULL ;
}
while ( ! F_22 ( & V_98 -> V_102 ) ) {
struct V_56 * V_31 ;
V_31 = F_24 ( V_98 -> V_102 . V_103 , struct V_56 , V_104 ) ;
F_25 ( & V_31 -> V_104 ) ;
F_26 ( & V_31 -> V_60 , V_119 ) ;
F_20 ( V_11 , 2 , L_12 , V_31 , V_31 -> V_60 . V_91 . V_106 ) ;
}
}
static int F_46 ( struct V_120 * V_121 , const struct V_7 * V_3 ,
unsigned int * V_122 , unsigned int * V_123 ,
unsigned int V_124 [] , void * V_125 [] )
{
struct V_10 * V_11 = F_47 ( V_121 ) ;
unsigned long V_126 ;
V_126 = V_11 -> V_46 * V_11 -> V_53 * V_11 -> V_41 ;
if ( V_3 ) {
if ( V_3 -> V_3 . V_9 . V_127 < V_126 )
return - V_128 ;
V_126 = V_3 -> V_3 . V_9 . V_127 ;
if ( V_126 > 7680 * 4320 * V_11 -> V_41 )
return - V_128 ;
}
* V_123 = 1 ;
V_124 [ 0 ] = V_126 ;
F_20 ( V_11 , 1 , L_20 , V_110 ,
* V_122 , V_126 ) ;
return 0 ;
}
static int F_48 ( struct V_129 * V_60 )
{
struct V_10 * V_11 = F_47 ( V_60 -> V_120 ) ;
struct V_56 * V_31 = F_49 ( V_60 , struct V_56 , V_60 ) ;
unsigned long V_126 ;
F_20 ( V_11 , 1 , L_21 , V_110 , V_60 -> V_91 . V_92 ) ;
F_50 ( NULL == V_11 -> V_3 ) ;
if ( V_11 -> V_46 < 48 || V_11 -> V_46 > V_130 ||
V_11 -> V_53 < 32 || V_11 -> V_53 > V_131 )
return - V_128 ;
V_126 = V_11 -> V_46 * V_11 -> V_53 * V_11 -> V_41 ;
if ( F_51 ( V_60 , 0 ) < V_126 ) {
F_20 ( V_11 , 1 , L_22 ,
V_110 , F_51 ( V_60 , 0 ) , V_126 ) ;
return - V_128 ;
}
F_52 ( & V_31 -> V_60 , 0 , V_126 ) ;
F_4 ( V_11 ) ;
F_9 ( V_11 ) ;
return 0 ;
}
static void F_53 ( struct V_129 * V_60 )
{
struct V_10 * V_11 = F_47 ( V_60 -> V_120 ) ;
struct V_56 * V_31 = F_49 ( V_60 , struct V_56 , V_60 ) ;
struct V_97 * V_99 = & V_11 -> V_99 ;
unsigned long V_100 = 0 ;
F_20 ( V_11 , 1 , L_16 , V_110 ) ;
F_21 ( & V_11 -> V_101 , V_100 ) ;
F_54 ( & V_31 -> V_104 , & V_99 -> V_102 ) ;
F_23 ( & V_11 -> V_101 , V_100 ) ;
}
static int F_55 ( struct V_120 * V_121 , unsigned int V_132 )
{
struct V_10 * V_11 = F_47 ( V_121 ) ;
int V_133 ;
F_20 ( V_11 , 1 , L_16 , V_110 ) ;
V_11 -> V_95 = 0 ;
V_133 = F_38 ( V_11 ) ;
if ( V_133 ) {
struct V_56 * V_31 , * V_134 ;
F_56 (buf, tmp, &dev->vidq.active, list) {
F_25 ( & V_31 -> V_104 ) ;
F_26 ( & V_31 -> V_60 , V_135 ) ;
}
}
return V_133 ;
}
static int F_57 ( struct V_120 * V_121 )
{
struct V_10 * V_11 = F_47 ( V_121 ) ;
F_20 ( V_11 , 1 , L_16 , V_110 ) ;
F_44 ( V_11 ) ;
return 0 ;
}
static void F_58 ( struct V_120 * V_121 )
{
struct V_10 * V_11 = F_47 ( V_121 ) ;
F_16 ( & V_11 -> V_136 ) ;
}
static void F_59 ( struct V_120 * V_121 )
{
struct V_10 * V_11 = F_47 ( V_121 ) ;
F_17 ( & V_11 -> V_136 ) ;
}
static int F_60 ( struct V_137 * V_137 , void * V_138 ,
struct V_139 * V_140 )
{
struct V_10 * V_11 = F_61 ( V_137 ) ;
strcpy ( V_140 -> V_141 , L_23 ) ;
strcpy ( V_140 -> V_142 , L_23 ) ;
snprintf ( V_140 -> V_143 , sizeof( V_140 -> V_143 ) ,
L_24 , V_11 -> V_117 . V_118 ) ;
V_140 -> V_144 = V_145 | V_146 |
V_147 ;
V_140 -> V_148 = V_140 -> V_144 | V_149 ;
return 0 ;
}
static int F_62 ( struct V_137 * V_137 , void * V_138 ,
struct V_150 * V_8 )
{
const struct V_1 * V_3 ;
if ( V_8 -> V_106 >= F_2 ( V_5 ) )
return - V_128 ;
V_3 = & V_5 [ V_8 -> V_106 ] ;
F_63 ( V_8 -> V_151 , V_3 -> V_118 , sizeof( V_8 -> V_151 ) ) ;
V_8 -> V_2 = V_3 -> V_6 ;
return 0 ;
}
static int F_64 ( struct V_137 * V_137 , void * V_138 ,
struct V_7 * V_8 )
{
struct V_10 * V_11 = F_61 ( V_137 ) ;
V_8 -> V_3 . V_9 . V_46 = V_11 -> V_46 ;
V_8 -> V_3 . V_9 . V_53 = V_11 -> V_53 ;
V_8 -> V_3 . V_9 . V_92 = V_93 ;
V_8 -> V_3 . V_9 . V_2 = V_11 -> V_3 -> V_6 ;
V_8 -> V_3 . V_9 . V_152 =
( V_8 -> V_3 . V_9 . V_46 * V_11 -> V_3 -> V_153 ) >> 3 ;
V_8 -> V_3 . V_9 . V_127 =
V_8 -> V_3 . V_9 . V_53 * V_8 -> V_3 . V_9 . V_152 ;
if ( V_11 -> V_3 -> V_15 )
V_8 -> V_3 . V_9 . V_154 = V_155 ;
else
V_8 -> V_3 . V_9 . V_154 = V_156 ;
return 0 ;
}
static int F_65 ( struct V_137 * V_137 , void * V_138 ,
struct V_7 * V_8 )
{
struct V_10 * V_11 = F_61 ( V_137 ) ;
const struct V_1 * V_3 ;
V_3 = F_3 ( V_8 ) ;
if ( ! V_3 ) {
F_20 ( V_11 , 1 , L_25 ,
V_8 -> V_3 . V_9 . V_2 ) ;
V_8 -> V_3 . V_9 . V_2 = V_23 ;
V_3 = F_3 ( V_8 ) ;
}
V_8 -> V_3 . V_9 . V_92 = V_93 ;
F_66 ( & V_8 -> V_3 . V_9 . V_46 , 48 , V_130 , 2 ,
& V_8 -> V_3 . V_9 . V_53 , 32 , V_131 , 0 , 0 ) ;
V_8 -> V_3 . V_9 . V_152 =
( V_8 -> V_3 . V_9 . V_46 * V_3 -> V_153 ) >> 3 ;
V_8 -> V_3 . V_9 . V_127 =
V_8 -> V_3 . V_9 . V_53 * V_8 -> V_3 . V_9 . V_152 ;
if ( V_3 -> V_15 )
V_8 -> V_3 . V_9 . V_154 = V_155 ;
else
V_8 -> V_3 . V_9 . V_154 = V_156 ;
V_8 -> V_3 . V_9 . V_138 = 0 ;
return 0 ;
}
static int F_67 ( struct V_137 * V_137 , void * V_138 ,
struct V_7 * V_8 )
{
struct V_10 * V_11 = F_61 ( V_137 ) ;
struct V_120 * V_157 = & V_11 -> V_158 ;
int V_159 = F_65 ( V_137 , V_138 , V_8 ) ;
if ( V_159 < 0 )
return V_159 ;
if ( F_68 ( V_157 ) ) {
F_20 ( V_11 , 1 , L_26 , V_110 ) ;
return - V_160 ;
}
V_11 -> V_3 = F_3 ( V_8 ) ;
V_11 -> V_41 = V_11 -> V_3 -> V_153 / 8 ;
V_11 -> V_46 = V_8 -> V_3 . V_9 . V_46 ;
V_11 -> V_53 = V_8 -> V_3 . V_9 . V_53 ;
return 0 ;
}
static int F_69 ( struct V_137 * V_137 , void * V_161 ,
struct V_162 * V_163 )
{
static const struct V_164 V_124 = {
48 , V_130 , 4 ,
32 , V_131 , 1
} ;
int V_165 ;
if ( V_163 -> V_106 )
return - V_128 ;
for ( V_165 = 0 ; V_165 < F_2 ( V_5 ) ; V_165 ++ )
if ( V_5 [ V_165 ] . V_6 == V_163 -> V_166 )
break;
if ( V_165 == F_2 ( V_5 ) )
return - V_128 ;
V_163 -> type = V_167 ;
V_163 -> V_168 = V_124 ;
return 0 ;
}
static int F_70 ( struct V_137 * V_137 , void * V_138 ,
struct V_169 * V_170 )
{
if ( V_170 -> V_106 >= V_171 )
return - V_128 ;
V_170 -> type = V_172 ;
sprintf ( V_170 -> V_118 , L_27 , V_170 -> V_106 ) ;
return 0 ;
}
static int F_71 ( struct V_137 * V_137 , void * V_138 , unsigned int * V_165 )
{
struct V_10 * V_11 = F_61 ( V_137 ) ;
* V_165 = V_11 -> V_17 ;
return 0 ;
}
static int F_72 ( struct V_137 * V_137 , void * V_138 , unsigned int V_165 )
{
struct V_10 * V_11 = F_61 ( V_137 ) ;
if ( V_165 >= V_171 )
return - V_128 ;
if ( V_165 == V_11 -> V_17 )
return 0 ;
V_11 -> V_17 = V_165 ;
F_73 ( V_11 -> V_74 ,
128 * V_165 , 255 + 128 * V_165 , 1 , 127 + 128 * V_165 ) ;
F_4 ( V_11 ) ;
F_9 ( V_11 ) ;
return 0 ;
}
static int F_74 ( struct V_137 * V_137 , void * V_138 ,
struct V_173 * V_174 )
{
const struct V_1 * V_3 ;
if ( V_174 -> V_106 )
return - V_128 ;
V_3 = F_1 ( V_174 -> V_166 ) ;
if ( ! V_3 )
return - V_128 ;
if ( V_174 -> V_46 < 48 || V_174 -> V_46 > V_130 || ( V_174 -> V_46 & 3 ) )
return - V_128 ;
if ( V_174 -> V_53 < 32 || V_174 -> V_53 > V_131 )
return - V_128 ;
V_174 -> type = V_175 ;
V_174 -> V_168 . V_176 = V_177 ;
V_174 -> V_168 . V_178 = V_179 ;
V_174 -> V_168 . V_180 = (struct V_181 ) { 1 , 1 } ;
return 0 ;
}
static int F_75 ( struct V_137 * V_137 , void * V_138 ,
struct V_182 * V_183 )
{
struct V_10 * V_11 = F_61 ( V_137 ) ;
if ( V_183 -> type != V_184 )
return - V_128 ;
V_183 -> V_183 . V_185 . V_186 = V_187 ;
V_183 -> V_183 . V_185 . V_188 = V_11 -> V_188 ;
V_183 -> V_183 . V_185 . V_189 = 1 ;
return 0 ;
}
static int F_76 ( struct V_137 * V_137 , void * V_138 ,
struct V_182 * V_183 )
{
struct V_10 * V_11 = F_61 ( V_137 ) ;
struct V_181 V_190 ;
if ( V_183 -> type != V_184 )
return - V_128 ;
V_190 = V_183 -> V_183 . V_185 . V_188 ;
V_190 = V_190 . V_191 ? V_190 : V_192 ;
V_190 = F_77 ( V_190 , < , V_177 ) ? V_177 : V_190 ;
V_190 = F_77 ( V_190 , > , V_179 ) ? V_179 : V_190 ;
V_11 -> V_188 = V_190 ;
V_183 -> V_183 . V_185 . V_188 = V_190 ;
V_183 -> V_183 . V_185 . V_189 = 1 ;
return 0 ;
}
static int F_78 ( struct V_193 * V_194 )
{
struct V_10 * V_11 = F_49 ( V_194 -> V_195 , struct V_10 , V_72 ) ;
if ( V_194 == V_11 -> V_80 )
V_11 -> V_65 -> V_76 = V_71 & 0xff ;
return 0 ;
}
static int F_79 ( struct V_193 * V_194 )
{
struct V_10 * V_11 = F_49 ( V_194 -> V_195 , struct V_10 , V_72 ) ;
switch ( V_194 -> V_196 ) {
case V_197 :
V_11 -> V_38 = V_194 -> V_76 ;
break;
default:
if ( V_194 == V_11 -> V_198 )
V_11 -> V_90 = 30 ;
break;
}
return 0 ;
}
static int F_80 ( void )
{
struct V_10 * V_11 ;
struct V_199 * V_104 ;
while ( ! F_22 ( & V_200 ) ) {
V_104 = V_200 . V_103 ;
F_25 ( V_104 ) ;
V_11 = F_24 ( V_104 , struct V_10 , V_200 ) ;
F_81 ( & V_11 -> V_117 , L_28 ,
F_82 ( & V_11 -> V_201 ) ) ;
F_83 ( & V_11 -> V_201 ) ;
F_84 ( & V_11 -> V_117 ) ;
F_85 ( & V_11 -> V_72 ) ;
F_86 ( V_11 ) ;
}
return 0 ;
}
static int T_5 F_87 ( int V_202 )
{
struct V_10 * V_11 ;
struct V_203 * V_204 ;
struct V_205 * V_206 ;
struct V_120 * V_157 ;
int V_159 ;
V_11 = F_88 ( sizeof( * V_11 ) , V_207 ) ;
if ( ! V_11 )
return - V_208 ;
snprintf ( V_11 -> V_117 . V_118 , sizeof( V_11 -> V_117 . V_118 ) ,
L_29 , V_209 , V_202 ) ;
V_159 = F_89 ( NULL , & V_11 -> V_117 ) ;
if ( V_159 )
goto V_210;
V_11 -> V_3 = & V_5 [ 0 ] ;
V_11 -> V_188 = V_192 ;
V_11 -> V_46 = 640 ;
V_11 -> V_53 = 480 ;
V_11 -> V_41 = V_11 -> V_3 -> V_153 / 8 ;
V_206 = & V_11 -> V_72 ;
F_90 ( V_206 , 11 ) ;
V_11 -> V_81 = F_91 ( V_206 , & V_211 ,
V_212 , 0 , 255 , 1 , 200 ) ;
V_11 -> V_74 = F_91 ( V_206 , & V_211 ,
V_213 , 0 , 255 , 1 , 127 ) ;
V_11 -> V_77 = F_91 ( V_206 , & V_211 ,
V_214 , 0 , 255 , 1 , 16 ) ;
V_11 -> V_78 = F_91 ( V_206 , & V_211 ,
V_215 , 0 , 255 , 1 , 127 ) ;
V_11 -> V_79 = F_91 ( V_206 , & V_211 ,
V_216 , - 128 , 127 , 1 , 0 ) ;
V_11 -> V_80 = F_91 ( V_206 , & V_211 ,
V_217 , 0 , 1 , 1 , 1 ) ;
V_11 -> V_65 = F_91 ( V_206 , & V_211 ,
V_218 , 0 , 255 , 1 , 100 ) ;
V_11 -> V_37 = F_91 ( V_206 , & V_211 ,
V_197 , 0 , 255 , 1 , 0 ) ;
V_11 -> V_198 = F_92 ( V_206 , & V_219 , NULL ) ;
V_11 -> V_82 = F_92 ( V_206 , & V_220 , NULL ) ;
V_11 -> V_83 = F_92 ( V_206 , & V_221 , NULL ) ;
V_11 -> boolean = F_92 ( V_206 , & V_222 , NULL ) ;
V_11 -> V_86 = F_92 ( V_206 , & V_223 , NULL ) ;
V_11 -> string = F_92 ( V_206 , & V_224 , NULL ) ;
V_11 -> V_85 = F_92 ( V_206 , & V_225 , NULL ) ;
V_11 -> V_88 = F_92 ( V_206 , & V_226 , NULL ) ;
if ( V_206 -> error ) {
V_159 = V_206 -> error ;
goto V_227;
}
F_93 ( 2 , & V_11 -> V_80 , 0 , true ) ;
V_11 -> V_117 . V_72 = V_206 ;
F_94 ( & V_11 -> V_101 ) ;
V_157 = & V_11 -> V_158 ;
V_157 -> type = V_184 ;
V_157 -> V_228 = V_229 | V_230 | V_231 | V_232 ;
V_157 -> V_233 = V_11 ;
V_157 -> V_234 = sizeof( struct V_56 ) ;
V_157 -> V_235 = & V_236 ;
V_157 -> V_237 = & V_238 ;
V_157 -> V_239 = V_240 ;
V_159 = F_95 ( V_157 ) ;
if ( V_159 )
goto V_227;
F_96 ( & V_11 -> V_136 ) ;
F_97 ( & V_11 -> V_99 . V_102 ) ;
F_98 ( & V_11 -> V_99 . V_111 ) ;
V_204 = & V_11 -> V_201 ;
* V_204 = V_241 ;
V_204 -> V_242 = V_242 ;
V_204 -> V_117 = & V_11 -> V_117 ;
V_204 -> V_243 = V_157 ;
F_99 ( V_244 , & V_204 -> V_100 ) ;
V_204 -> V_73 = & V_11 -> V_136 ;
F_100 ( V_204 , V_11 ) ;
V_159 = F_101 ( V_204 , V_245 , V_246 ) ;
if ( V_159 < 0 )
goto V_227;
F_54 ( & V_11 -> V_200 , & V_200 ) ;
F_81 ( & V_11 -> V_117 , L_30 ,
F_82 ( V_204 ) ) ;
return 0 ;
V_227:
F_85 ( V_206 ) ;
F_84 ( & V_11 -> V_117 ) ;
V_210:
F_86 ( V_11 ) ;
return V_159 ;
}
static int T_5 F_102 ( void )
{
const struct V_247 * V_248 = F_103 ( L_31 ) ;
int V_159 = 0 , V_165 ;
if ( V_248 == NULL ) {
F_104 ( V_249 L_32 ) ;
return - V_250 ;
}
V_251 = V_248 -> V_113 ;
if ( V_252 <= 0 )
V_252 = 1 ;
for ( V_165 = 0 ; V_165 < V_252 ; V_165 ++ ) {
V_159 = F_87 ( V_165 ) ;
if ( V_159 ) {
if ( V_165 )
V_159 = 0 ;
break;
}
}
if ( V_159 < 0 ) {
F_104 ( V_249 L_33 , V_159 ) ;
return V_159 ;
}
F_104 ( V_253 L_34
L_35 ,
V_254 ) ;
V_252 = V_165 ;
return V_159 ;
}
static void T_6 F_105 ( void )
{
F_80 () ;
}
