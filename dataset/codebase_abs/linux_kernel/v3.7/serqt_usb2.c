static int F_1 ( struct V_1 * V_2 ,
const char * V_3 )
{
if ( ! V_2 ) {
F_2 ( L_1 , V_3 ) ;
return - 1 ;
}
if ( ! V_2 -> V_4 ) {
F_2 ( L_2 , V_3 ) ;
return - 1 ;
}
return 0 ;
}
static int F_3 ( struct V_5 * V_4 ,
const char * V_3 )
{
if ( ! V_4 ) {
F_2 ( L_3 , V_3 ) ;
return - 1 ;
}
if ( ! V_4 -> type ) {
F_2 ( L_4 , V_3 ) ;
return - 1 ;
}
return 0 ;
}
static inline struct V_6 * F_4 ( struct V_1
* V_2 )
{
return (struct V_6 * ) F_5 ( V_2 ) ;
}
static inline void F_6 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
F_7 ( V_2 , ( void * ) V_7 ) ;
}
static struct V_5 * F_8 ( struct V_1 * V_2 ,
const char * V_3 )
{
if ( ! V_2 ||
F_1 ( V_2 , V_3 ) ||
F_3 ( V_2 -> V_4 , V_3 ) ) {
return NULL ;
}
return V_2 -> V_4 ;
}
static void F_9 ( struct V_6 * V_8 ,
unsigned char V_9 )
{
V_8 -> V_10 =
V_9 & ( V_11 | V_12 | V_13 |
V_14 ) ;
}
static void F_10 ( struct V_6 * V_8 ,
unsigned char V_15 )
{
V_8 -> V_16 = V_15 ;
F_11 ( & V_8 -> V_17 ) ;
}
static void F_12 ( struct V_18 * V_19 , struct V_1 * V_2 ,
unsigned char V_7 )
{
struct V_20 * V_20 = V_2 -> V_21 ;
if ( V_20 -> V_22 )
F_13 ( V_19 , V_7 , V_23 ) ;
}
static void F_14 ( struct V_20 * V_20 )
{
struct V_18 * V_19 ;
int V_24 ;
struct V_6 * V_6 ;
V_24 = V_20 -> V_24 ;
if ( V_24 ) {
F_15 ( & V_20 -> V_25 -> V_25 , L_5 , V_24 ) ;
return;
}
V_6 = V_20 -> V_26 ;
V_19 = F_16 ( & V_6 -> V_2 -> V_2 ) ;
if ( V_19 )
F_17 ( V_19 ) ;
F_18 ( V_19 ) ;
}
static void F_19 ( struct V_20 * V_20 )
{
}
static void F_20 ( struct V_20 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_26 ;
struct V_5 * V_4 = F_8 ( V_2 , V_27 ) ;
struct V_6 * V_8 = F_4 ( V_2 ) ;
unsigned char * V_7 ;
struct V_18 * V_19 ;
unsigned int V_28 ;
unsigned int V_29 ;
int V_30 , V_31 ;
int V_32 , V_33 ;
if ( V_20 -> V_24 ) {
V_8 -> V_34 = 1 ;
F_15 ( & V_20 -> V_25 -> V_25 , L_6 ,
V_27 , V_20 -> V_24 ) ;
return;
}
V_19 = F_16 ( & V_2 -> V_2 ) ;
if ( ! V_19 )
return;
V_7 = V_20 -> V_35 ;
V_29 = V_20 -> V_22 ;
V_28 = V_19 -> V_28 - V_4 -> V_36 ;
F_15 ( & V_2 -> V_25 , L_7 , V_27 , V_8 -> V_37 ) ;
if ( F_1 ( V_2 , V_27 ) != 0 ) {
V_8 -> V_34 = 1 ;
goto exit;
}
if ( ! V_4 )
goto exit;
if ( V_8 -> V_38 == 1 ) {
F_15 ( & V_2 -> V_25 , L_8 , V_27 ) ;
V_8 -> V_34 = 1 ;
goto exit;
}
if ( V_8 -> V_37 == 1 ) {
V_8 -> V_34 = 1 ;
goto exit;
}
if ( V_20 -> V_24 ) {
V_8 -> V_34 = 1 ;
F_15 ( & V_2 -> V_25 , L_9 ,
V_27 , V_20 -> V_24 ) ;
goto exit;
}
if ( V_29 ) {
V_33 = 0 ;
for ( V_30 = 0 ; V_30 < V_29 ; ++ V_30 ) {
if ( ( V_30 <= ( V_29 - 3 ) ) && ( V_7 [ V_30 ] == 0x1b )
&& ( V_7 [ V_30 + 1 ] == 0x1b ) ) {
V_32 = 0 ;
switch ( V_7 [ V_30 + 2 ] ) {
case 0x00 :
if ( V_30 > ( V_29 - 4 ) ) {
F_15 ( & V_2 -> V_25 , L_10 ) ;
break;
}
F_9 ( V_8 , V_7 [ V_30 + 3 ] ) ;
V_30 += 3 ;
V_32 = 1 ;
break;
case 0x01 :
F_15 ( & V_2 -> V_25 , L_11 ) ;
if ( V_30 > ( V_29 - 4 ) ) {
F_15 ( & V_2 -> V_25 , L_12 ) ;
break;
}
F_10 ( V_8 ,
V_7 [ V_30 + 3 ] ) ;
V_30 += 3 ;
V_32 = 1 ;
break;
case 0xff :
F_15 ( & V_2 -> V_25 , L_13 ) ;
if ( V_19 ) {
F_12 ( V_19 , V_2 , V_7 [ V_30 ] ) ;
F_12 ( V_19 , V_2 , V_7 [ V_30 + 1 ] ) ;
}
V_30 += 2 ;
break;
}
if ( V_32 == 1 )
continue;
}
if ( V_19 && V_20 -> V_22 )
F_13 ( V_19 , V_7 [ V_30 ] , V_23 ) ;
}
F_21 ( V_19 ) ;
}
F_22 ( V_2 -> V_21 , V_4 -> V_25 ,
F_23 ( V_4 -> V_25 ,
V_2 -> V_39 ) ,
V_2 -> V_21 -> V_35 ,
V_2 -> V_21 -> V_40 ,
F_20 , V_2 ) ;
V_31 = F_24 ( V_2 -> V_21 , V_41 ) ;
if ( V_31 )
F_15 ( & V_2 -> V_25 , L_14 ,
V_27 , V_31 ) ;
else {
if ( V_29 ) {
F_21 ( V_19 ) ;
F_25 ( V_19 ) ;
}
}
F_26 ( & V_2 -> V_42 ) ;
exit:
F_18 ( V_19 ) ;
}
static int F_27 ( struct V_5 * V_4 ,
struct V_43 * V_44 )
{
int V_31 ;
unsigned char * V_35 ;
V_35 =
F_28 ( sizeof( struct V_43 ) , V_45 ) ;
if ( ! V_35 )
return - V_46 ;
V_31 = F_29 ( V_4 -> V_25 , F_30 ( V_4 -> V_25 , 0 ) ,
V_47 , 0xc0 , 0 , 0 ,
V_35 ,
sizeof( struct V_43 ) , 300 ) ;
if ( V_31 > 0 )
memcpy ( V_44 , V_35 ,
sizeof( struct V_43 ) ) ;
F_31 ( V_35 ) ;
return V_31 ;
}
static int F_32 ( struct V_5 * V_4 )
{
int V_31 ;
T_1 V_48 ;
V_48 = V_49 ;
V_31 = F_29 ( V_4 -> V_25 , F_33 ( V_4 -> V_25 , 0 ) ,
V_50 , 0x40 ,
V_48 , 0 , NULL , 0 , 300 ) ;
return V_31 ;
}
static int F_34 ( struct V_5 * V_4 , T_1 V_51 )
{
int V_31 ;
T_1 V_48 ;
V_48 = V_49 ;
V_31 =
F_29 ( V_4 -> V_25 , F_33 ( V_4 -> V_25 , 0 ) ,
V_52 , 0x40 , V_51 , 0 , NULL , 0 , 300 ) ;
return V_31 ;
}
static int F_35 ( struct V_5 * V_4 ,
struct V_43 * V_44 )
{
int V_31 ;
T_1 V_53 ;
T_1 V_54 ;
V_54 = ( ( T_1 ) ( V_44 -> V_55 ) ) ;
V_54 = ( V_54 << 8 ) ;
V_54 += ( ( T_1 ) ( V_44 -> V_56 ) ) ;
V_53 = sizeof( struct V_43 ) ;
V_31 = F_29 ( V_4 -> V_25 , F_33 ( V_4 -> V_25 , 0 ) ,
V_47 , 0x40 , V_54 ,
0 , NULL , 0 , 300 ) ;
return V_31 ;
}
static int F_36 ( struct V_5 * V_4 , T_1 V_57 ,
struct V_58 * V_59 )
{
int V_31 ;
V_31 = F_29 ( V_4 -> V_25 , F_30 ( V_4 -> V_25 , 0 ) ,
V_60 ,
V_61 , 1 , V_57 ,
V_59 ,
sizeof( struct V_58 ) , 300 ) ;
return V_31 ;
}
static int F_37 ( struct V_5 * V_4 , T_1 V_57 )
{
int V_31 ;
V_31 = F_29 ( V_4 -> V_25 , F_30 ( V_4 -> V_25 , 0 ) ,
V_60 ,
V_62 , 0 , V_57 ,
NULL , 0 , 300 ) ;
return V_31 ;
}
static int F_38 ( struct V_5 * V_4 , unsigned short V_57 ,
unsigned short V_63 , T_2 * V_64 )
{
int V_31 ;
T_1 V_65 ;
V_65 = sizeof( struct V_43 ) ;
V_31 =
F_29 ( V_4 -> V_25 , F_30 ( V_4 -> V_25 , 0 ) ,
V_66 , 0xC0 , V_63 ,
V_57 , ( void * ) V_64 , sizeof( * V_64 ) , 300 ) ;
return V_31 ;
}
static int F_39 ( struct V_5 * V_4 , unsigned short V_57 ,
unsigned short V_63 , unsigned short V_67 )
{
int V_31 ;
unsigned short V_68 ;
V_68 = V_67 ;
V_68 = V_68 << 8 ;
V_68 = V_68 + V_63 ;
V_31 =
F_29 ( V_4 -> V_25 , F_33 ( V_4 -> V_25 , 0 ) ,
V_66 , 0x40 , V_68 , V_57 ,
NULL , 0 , 300 ) ;
return V_31 ;
}
static int F_40 ( struct V_5 * V_4 , unsigned short V_57 ,
unsigned short V_69 , unsigned char V_70 )
{
int V_31 ;
unsigned short V_71 ;
V_71 = ( V_70 << 8 ) + V_57 ;
V_31 =
F_29 ( V_4 -> V_25 , F_33 ( V_4 -> V_25 , 0 ) ,
V_72 , 0x40 , V_69 ,
V_71 , NULL , 0 , 300 ) ;
return V_31 ;
}
static int F_41 ( struct V_5 * V_4 , unsigned int V_28 ,
int V_73 )
{
T_2 V_74 = 0 ;
T_2 V_75 = 0 , V_76 = 0 ;
unsigned int V_24 ;
if ( V_73 == 1 ) {
V_74 = V_77 ;
}
else {
V_74 = 0 ;
}
V_76 = V_74 << 8 ;
if ( V_73 == 1 ) {
V_75 = V_78 ;
} else {
V_75 = 0 ;
}
V_76 |= V_75 ;
V_24 =
F_29 ( V_4 -> V_25 , F_33 ( V_4 -> V_25 , 0 ) ,
V_79 , 0x40 , V_76 ,
V_28 , NULL , 0 , 300 ) ;
return V_24 ;
}
static int F_42 ( struct V_5 * V_4 , T_1 V_28 ,
unsigned char V_80 , unsigned char V_81 )
{
T_1 V_82 ;
int V_31 ;
V_82 = V_81 << 8 ;
V_82 = ( unsigned short ) V_80 ;
V_31 =
F_29 ( V_4 -> V_25 , F_33 ( V_4 -> V_25 , 0 ) ,
V_83 , 0x40 , V_82 ,
V_28 , NULL , 0 , 300 ) ;
return V_31 ;
}
static int F_43 ( struct V_5 * V_4 , T_1 V_28 )
{
int V_31 ;
V_31 =
F_29 ( V_4 -> V_25 , F_33 ( V_4 -> V_25 , 0 ) ,
V_84 , 0x40 , 0 , V_28 ,
NULL , 0 , 300 ) ;
return V_31 ;
}
static int F_44 ( struct V_5 * V_4 )
{
struct V_85 * V_25 = & V_4 -> V_25 -> V_25 ;
struct V_1 * V_2 ;
struct V_6 * V_8 ;
struct V_43 V_86 ;
int V_30 ;
int V_24 ;
for ( V_30 = 0 ; V_30 < V_4 -> V_87 ; V_30 ++ ) {
V_2 = V_4 -> V_2 [ V_30 ] ;
V_8 = F_45 ( sizeof( * V_8 ) , V_45 ) ;
if ( ! V_8 ) {
for ( -- V_30 ; V_30 >= 0 ; V_30 -- ) {
V_2 = V_4 -> V_2 [ V_30 ] ;
F_31 ( F_5 ( V_2 ) ) ;
F_7 ( V_2 , NULL ) ;
}
return - V_46 ;
}
F_46 ( & V_8 -> V_88 ) ;
F_7 ( V_2 , V_8 ) ;
}
V_24 = F_27 ( V_4 , & V_86 ) ;
if ( V_24 < 0 )
goto V_89;
F_15 ( V_25 , L_15 , V_86 . V_55 ) ;
V_86 . V_55 &= ~ V_90 ;
F_15 ( V_25 , L_16 , V_86 . V_55 ) ;
V_24 = F_35 ( V_4 , & V_86 ) ;
if ( V_24 < 0 ) {
F_15 ( V_25 , L_17 ) ;
goto V_89;
}
V_24 = F_27 ( V_4 , & V_86 ) ;
if ( V_24 < 0 ) {
F_15 ( V_25 , L_18 ) ;
goto V_89;
}
switch ( V_4 -> V_25 -> V_91 . V_92 ) {
case V_93 :
case V_94 :
case V_95 :
case V_96 :
case V_97 :
case V_98 :
case V_99 :
case V_100 :
V_86 . V_56 &= ~ ( V_101 | V_102 ) ;
V_86 . V_56 |= V_103 ;
V_86 . V_55 &= ~ ( V_104 ) ;
V_86 . V_55 |= V_105 ;
break;
case V_106 :
case V_107 :
case V_108 :
case V_109 :
case V_110 :
case V_111 :
case V_112 :
case V_113 :
case V_114 :
V_86 . V_56 &= ~ ( V_101 | V_102 ) ;
V_86 . V_56 |= V_103 ;
V_86 . V_55 &= ~ ( V_104 ) ;
V_86 . V_55 |= V_115 ;
break;
default:
V_86 . V_56 &= ~ ( V_101 | V_102 ) ;
V_86 . V_56 |= V_103 ;
V_86 . V_55 &= ~ ( V_104 ) ;
V_86 . V_55 |= V_105 ;
break;
}
V_24 = F_32 ( V_4 ) ;
if ( V_24 < 0 ) {
F_15 ( V_25 , L_19 ) ;
goto V_89;
}
V_24 = F_34 ( V_4 , V_116 ) ;
if ( V_24 < 0 ) {
F_15 ( V_25 , L_20 ) ;
goto V_89;
}
F_15 ( V_25 , L_15 , V_86 . V_55 ) ;
V_86 . V_55 |= V_117 ;
F_15 ( V_25 , L_16 , V_86 . V_55 ) ;
V_24 = F_35 ( V_4 , & V_86 ) ;
if ( V_24 < 0 ) {
F_15 ( V_25 , L_17 ) ;
goto V_89;
}
return 0 ;
V_89:
for ( V_30 = 0 ; V_30 < V_4 -> V_87 ; V_30 ++ ) {
V_2 = V_4 -> V_2 [ V_30 ] ;
V_8 = F_4 ( V_2 ) ;
F_31 ( V_8 ) ;
F_7 ( V_2 , NULL ) ;
}
return - V_118 ;
}
static void F_47 ( struct V_5 * V_4 )
{
struct V_1 * V_2 ;
struct V_6 * V_8 ;
int V_30 ;
for ( V_30 = 0 ; V_30 < V_4 -> V_87 ; V_30 ++ ) {
V_2 = V_4 -> V_2 [ V_30 ] ;
if ( ! V_2 )
continue;
V_8 = F_5 ( V_2 ) ;
F_31 ( V_8 ) ;
F_7 ( V_2 , NULL ) ;
}
}
static int F_48 ( struct V_18 * V_19 ,
struct V_1 * V_2 )
{
struct V_5 * V_4 ;
struct V_6 * V_6 ;
struct V_6 * V_119 ;
struct V_58 V_120 ;
int V_31 ;
if ( F_1 ( V_2 , V_27 ) )
return - V_121 ;
V_4 = V_2 -> V_4 ;
if ( F_3 ( V_4 , V_27 ) )
return - V_121 ;
V_6 = F_4 ( V_2 ) ;
V_119 = F_4 ( V_4 -> V_2 [ 0 ] ) ;
if ( V_6 == NULL || V_119 == NULL )
return - V_121 ;
F_49 ( V_4 -> V_25 , V_2 -> V_122 -> V_123 ) ;
F_49 ( V_4 -> V_25 , V_2 -> V_21 -> V_123 ) ;
V_119 -> V_124 ++ ;
V_31 = F_27 ( V_4 , & V_119 -> V_86 ) ;
V_31 = F_36 ( V_4 , V_2 -> V_125 , & V_120 ) ;
if ( V_31 < 0 ) {
F_15 ( & V_2 -> V_25 , L_21 ) ;
return V_31 ;
}
F_15 ( & V_2 -> V_25 , L_22 ) ;
V_6 -> V_10 = V_120 . V_9 &
( V_11 | V_12 | V_13 | V_14 ) ;
V_6 -> V_16 = V_120 . V_15 &
( V_78 | V_126 | V_127 | V_128 ) ;
V_31 = F_40 ( V_4 , V_2 -> V_125 , V_129 , V_130 ) ;
if ( V_31 < 0 ) {
F_15 ( & V_2 -> V_25 , L_23 ) ;
return V_31 ;
}
F_15 ( & V_2 -> V_25 , L_24 ) ;
if ( V_119 -> V_124 == 1 ) {
if ( V_4 -> V_2 [ 0 ] -> V_131 == NULL ) {
F_50 ( V_4 -> V_2 [ 0 ] -> V_132 ,
V_4 -> V_25 ,
F_51 ( V_4 -> V_25 ,
V_4 -> V_2 [ 0 ] -> V_133 ) ,
V_4 -> V_2 [ 0 ] -> V_131 ,
V_4 -> V_2 [ 0 ] ->
V_132 -> V_40 ,
F_19 , V_4 ,
V_4 -> V_2 [ 0 ] ->
V_132 -> V_134 ) ;
V_31 =
F_24 ( V_4 -> V_2 [ 0 ] -> V_132 ,
V_45 ) ;
if ( V_31 ) {
F_52 ( & V_2 -> V_25 ,
L_25
L_26 , V_27 , V_31 ) ;
}
}
}
F_15 ( & V_2 -> V_25 , L_27 , V_2 -> V_125 ) ;
F_15 ( & V_2 -> V_25 , L_28 , V_2 -> V_4 -> V_36 ) ;
F_15 ( & V_2 -> V_25 , L_29 , V_2 -> V_39 ) ;
F_15 ( & V_2 -> V_25 , L_30 , V_2 -> V_135 ) ;
F_15 ( & V_2 -> V_25 , L_31 , V_2 -> V_133 ) ;
F_15 ( & V_2 -> V_25 , L_32 , V_6 -> V_136 ) ;
V_6 -> V_21 = V_2 -> V_21 ;
F_22 ( V_6 -> V_21 ,
V_4 -> V_25 ,
F_23 ( V_4 -> V_25 ,
V_2 -> V_39 ) ,
V_2 -> V_137 ,
V_6 -> V_21 -> V_40 ,
F_20 , V_6 ) ;
F_15 ( & V_2 -> V_25 , L_33 , V_2 -> V_39 ) ;
V_6 -> V_138 = true ;
V_31 = F_24 ( V_6 -> V_21 , V_45 ) ;
if ( V_31 ) {
F_52 ( & V_2 -> V_25 ,
L_34 ,
V_27 , V_31 ) ;
V_6 -> V_138 = false ;
}
F_53 ( & V_6 -> V_17 ) ;
F_53 ( & V_6 -> V_139 ) ;
memset ( & ( V_6 -> V_140 ) , 0x00 , sizeof( V_6 -> V_140 ) ) ;
return 0 ;
}
static int F_54 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_141 ;
struct V_5 * V_4 ;
int V_142 = 0 ;
V_4 = F_8 ( V_2 , V_27 ) ;
if ( V_4 -> V_143 ) {
if ( V_2 -> V_122 -> V_24 == - V_144 )
V_142 = V_2 -> V_122 -> V_40 ;
}
return V_142 ;
}
static void F_55 ( struct V_18 * V_19 ,
struct V_6 * V_8 )
{
int V_145 = V_146 / 10 ;
int V_17 = 30 ;
int V_147 ;
while ( 1 ) {
V_147 = F_54 ( V_19 ) ;
if ( V_147 <= 0 )
return;
F_56 ( & V_8 -> V_17 , V_145 ) ;
V_17 -- ;
if ( V_17 == 0 ) {
F_15 ( & V_8 -> V_2 -> V_25 , L_35 , V_27 ) ;
return;
} else {
V_17 = 30 ;
}
}
}
static void F_57 ( struct V_1 * V_2 )
{
struct V_5 * V_4 = V_2 -> V_4 ;
struct V_6 * V_8 ;
struct V_6 * V_119 ;
struct V_18 * V_19 ;
int V_24 ;
unsigned int V_28 ;
V_24 = 0 ;
V_19 = F_16 ( & V_2 -> V_2 ) ;
V_28 = V_19 -> V_28 - V_4 -> V_36 ;
V_8 = F_4 ( V_2 ) ;
V_119 = F_4 ( V_4 -> V_2 [ 0 ] ) ;
if ( V_4 -> V_143 )
F_58 ( V_2 -> V_122 ) ;
if ( V_4 -> V_148 )
F_58 ( V_2 -> V_21 ) ;
if ( V_4 -> V_25 )
F_55 ( V_19 , V_8 ) ;
F_18 ( V_19 ) ;
V_24 = F_37 ( V_4 , V_28 ) ;
if ( V_24 < 0 )
F_15 ( & V_2 -> V_25 , L_36 , V_27 , V_2 -> V_125 ) ;
V_119 -> V_124 -- ;
F_15 ( & V_2 -> V_25 , L_37 , V_119 -> V_124 , V_2 -> V_125 ) ;
if ( V_119 -> V_124 == 0 ) {
if ( V_4 -> V_2 [ 0 ] -> V_132 ) {
F_15 ( & V_2 -> V_25 , L_38 , L_39 ) ;
F_59 ( V_4 -> V_2 [ 0 ] -> V_132 ) ;
}
}
if ( V_8 -> V_122 ) {
F_31 ( V_8 -> V_122 -> V_35 ) ;
F_60 ( V_8 -> V_122 ) ;
}
}
static int F_61 ( struct V_18 * V_19 , struct V_1 * V_2 ,
const unsigned char * V_149 , int V_147 )
{
int V_31 ;
struct V_5 * V_4 = F_8 ( V_2 , V_27 ) ;
if ( V_4 == NULL )
return - V_121 ;
if ( V_147 == 0 ) {
F_15 ( & V_2 -> V_25 , L_40 , V_27 ) ;
return 0 ;
}
if ( V_4 -> V_143 ) {
if ( V_2 -> V_122 -> V_24 == - V_144 ) {
F_15 ( & V_2 -> V_25 , L_41 , V_27 ) ;
return 0 ;
}
V_147 =
( V_147 > V_2 -> V_150 ) ? V_2 -> V_150 : V_147 ;
memcpy ( V_2 -> V_122 -> V_35 , V_149 , V_147 ) ;
F_22 ( V_2 -> V_122 , V_4 -> V_25 ,
F_62 ( V_4 -> V_25 ,
V_2 ->
V_135 ) ,
V_2 -> V_122 -> V_35 , V_147 ,
F_14 , V_2 ) ;
V_31 = F_24 ( V_2 -> V_122 , V_41 ) ;
if ( V_31 )
F_15 ( & V_2 -> V_25 , L_42 ,
V_27 , V_31 ) ;
else
V_31 = V_147 ;
return V_31 ;
}
return 0 ;
}
static int F_63 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_141 ;
struct V_5 * V_4 ;
struct V_6 * V_8 ;
int V_151 = - V_152 ;
if ( F_1 ( V_2 , V_27 ) )
return - 1 ;
V_4 = F_8 ( V_2 , V_27 ) ;
if ( ! V_4 )
return - V_121 ;
V_8 = F_4 ( V_2 ) ;
F_64 ( & V_8 -> V_88 ) ;
if ( V_4 -> V_143 ) {
if ( V_2 -> V_122 -> V_24 != - V_144 )
V_151 = V_2 -> V_150 ;
}
F_65 ( & V_8 -> V_88 ) ;
return V_151 ;
}
static int F_66 ( struct V_18 * V_19 ,
unsigned int V_153 , unsigned long V_154 )
{
struct V_1 * V_2 = V_19 -> V_141 ;
struct V_6 * V_8 = F_4 ( V_2 ) ;
struct V_5 * V_4 = F_8 ( V_2 , V_27 ) ;
unsigned int V_28 ;
F_15 ( & V_2 -> V_25 , L_43 , V_27 , V_153 ) ;
V_28 = V_19 -> V_28 - V_4 -> V_36 ;
if ( V_153 == V_155 ) {
while ( V_8 != NULL ) {
F_67 ( & V_8 -> V_139 ) ;
if ( F_68 ( V_156 ) )
return - V_157 ;
else {
char V_158 = V_8 -> V_159 ;
if ( V_158 == 0 )
return - V_118 ;
V_8 -> V_159 = 0 ;
if ( ( ( V_154 & V_160 )
&& ( V_158 & V_127 ) )
|| ( ( V_154 & V_161 )
&& ( V_158 & V_126 ) )
|| ( ( V_154 & V_162 )
&& ( V_158 & V_128 ) )
|| ( ( V_154 & V_163 )
&& ( V_158 & V_78 ) ) ) {
return 0 ;
}
}
}
return 0 ;
}
F_15 ( & V_2 -> V_25 , L_44 , V_27 , V_2 -> V_125 ) ;
return - V_164 ;
}
static void F_69 ( struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_165 * V_166 )
{
struct V_165 * V_167 = & V_19 -> V_167 ;
unsigned char V_168 = 0 ;
unsigned int V_169 = V_167 -> V_170 ;
unsigned int V_28 ;
int V_171 , V_172 , V_173 ;
int V_24 ;
V_28 = V_19 -> V_28 - V_2 -> V_4 -> V_36 ;
switch ( V_169 & V_174 ) {
case V_175 :
V_168 |= V_176 ;
break;
case V_177 :
V_168 |= V_178 ;
break;
case V_179 :
V_168 |= V_180 ;
break;
default:
V_167 -> V_170 &= ~ V_174 ;
V_167 -> V_170 |= V_181 ;
case V_181 :
V_168 |= V_182 ;
break;
}
if ( V_169 & V_183 ) {
if ( V_169 & V_184 )
V_168 |= V_185 ;
else
V_168 |= V_186 ;
}
if ( V_169 & V_187 )
V_168 |= V_188 ;
else
V_168 |= V_189 ;
F_15 ( & V_2 -> V_25 , L_45 , V_27 ) ;
V_171 = F_70 ( V_19 ) ;
if ( ! V_171 )
V_171 = 9600 ;
F_15 ( & V_2 -> V_25 , L_46 , V_27 , V_171 ) ;
V_172 = V_190 / V_171 ;
V_173 = V_190 % V_171 ;
if ( ( ( V_173 * 2 ) >= V_171 ) && ( V_171 != 110 ) )
V_172 ++ ;
V_24 =
F_40 ( V_2 -> V_4 , V_28 , ( unsigned short ) V_172 , V_168 ) ;
if ( V_24 < 0 ) {
F_15 ( & V_2 -> V_25 , L_23 ) ;
return;
}
if ( V_169 & V_191 ) {
F_15 ( & V_2 -> V_25 , L_47 , V_27 , V_2 -> V_125 ) ;
V_24 = F_41 ( V_2 -> V_4 , V_28 , 1 ) ;
if ( V_24 < 0 ) {
F_15 ( & V_2 -> V_25 , L_48 ) ;
return;
}
} else {
F_15 ( & V_2 -> V_25 , L_49 , V_27 , V_2 -> V_125 ) ;
V_24 = F_41 ( V_2 -> V_4 , V_28 , 0 ) ;
if ( V_24 < 0 ) {
F_15 ( & V_2 -> V_25 , L_48 ) ;
return;
}
}
if ( F_71 ( V_19 ) || F_72 ( V_19 ) ) {
unsigned char V_80 = F_73 ( V_19 ) ;
unsigned char V_81 = F_74 ( V_19 ) ;
V_24 =
F_42 ( V_2 -> V_4 , V_28 , V_80 ,
V_81 ) ;
if ( V_24 < 0 )
F_15 ( & V_2 -> V_25 , L_50 ) ;
} else {
V_24 = F_43 ( V_2 -> V_4 , V_28 ) ;
if ( V_24 < 0 )
F_15 ( & V_2 -> V_25 , L_51 ) ;
}
V_167 -> V_170 &= ~ V_192 ;
}
static void F_75 ( struct V_18 * V_19 , int V_193 )
{
struct V_1 * V_2 = V_19 -> V_141 ;
struct V_5 * V_4 = F_8 ( V_2 , V_27 ) ;
struct V_6 * V_8 ;
T_3 V_28 , V_194 ;
unsigned int V_31 ;
V_28 = V_19 -> V_28 - V_4 -> V_36 ;
V_8 = F_4 ( V_2 ) ;
if ( V_193 == - 1 )
V_194 = 1 ;
else
V_194 = 0 ;
F_64 ( & V_8 -> V_88 ) ;
V_31 =
F_29 ( V_4 -> V_25 , F_33 ( V_4 -> V_25 , 0 ) ,
V_195 , 0x40 , V_194 , V_28 , NULL , 0 , 300 ) ;
F_65 ( & V_8 -> V_88 ) ;
}
static inline int F_76 ( struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_5 * V_4 )
{
T_4 V_74 ;
T_4 V_75 ;
unsigned int V_31 = 0 ;
int V_24 ;
unsigned int V_28 ;
V_28 = V_19 -> V_28 - V_4 -> V_36 ;
V_24 =
F_38 ( V_2 -> V_4 , V_28 , V_196 , & V_74 ) ;
if ( V_24 >= 0 ) {
V_24 =
F_38 ( V_2 -> V_4 , V_28 ,
V_197 , & V_75 ) ;
}
if ( V_24 >= 0 ) {
V_31 = ( ( V_74 & V_198 ) ? V_199 : 0 )
| ( ( V_74 & V_77 ) ? V_200 : 0 )
| ( ( V_75 & V_78 ) ? V_163 : 0 )
| ( ( V_75 & V_128 ) ? V_201 : 0 )
| ( ( V_75 & V_127 ) ? V_202 : 0 )
| ( ( V_75 & V_126 ) ? V_161 : 0 ) ;
return V_31 ;
} else
return - V_203 ;
}
static inline int F_77 ( struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_5 * V_4 ,
unsigned int V_204 )
{
T_4 V_74 ;
int V_24 ;
unsigned int V_28 ;
V_28 = V_19 -> V_28 - V_4 -> V_36 ;
V_24 =
F_38 ( V_2 -> V_4 , V_28 , V_196 , & V_74 ) ;
if ( V_24 < 0 )
return - V_203 ;
V_74 &= ~ ( V_77 | V_198 | V_205 ) ;
if ( V_204 & V_200 )
V_74 |= V_77 ;
if ( V_204 & V_199 )
V_74 |= V_198 ;
if ( V_204 & V_206 )
V_74 |= V_205 ;
V_24 =
F_39 ( V_2 -> V_4 , V_28 , V_196 , V_74 ) ;
if ( V_24 < 0 )
return - V_203 ;
else
return 0 ;
}
static int F_78 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_141 ;
struct V_5 * V_4 = F_8 ( V_2 , V_27 ) ;
struct V_6 * V_8 = F_4 ( V_2 ) ;
int V_151 ;
if ( ! V_4 )
return - V_121 ;
F_64 ( & V_8 -> V_88 ) ;
V_151 = F_76 ( V_19 , V_2 , V_4 ) ;
F_65 ( & V_8 -> V_88 ) ;
return V_151 ;
}
static int F_79 ( struct V_18 * V_19 ,
unsigned int V_207 , unsigned int V_208 )
{
struct V_1 * V_2 = V_19 -> V_141 ;
struct V_5 * V_4 = F_8 ( V_2 , V_27 ) ;
struct V_6 * V_8 = F_4 ( V_2 ) ;
int V_151 ;
if ( ! V_4 )
return - V_121 ;
F_64 ( & V_8 -> V_88 ) ;
V_151 = F_77 ( V_19 , V_2 , V_4 , V_207 ) ;
F_65 ( & V_8 -> V_88 ) ;
return V_151 ;
}
static void F_80 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_141 ;
struct V_5 * V_4 = F_8 ( V_2 , V_27 ) ;
struct V_6 * V_8 ;
if ( ! V_4 )
return;
V_8 = F_4 ( V_2 ) ;
F_64 ( & V_8 -> V_88 ) ;
V_8 -> V_37 = 1 ;
F_65 ( & V_8 -> V_88 ) ;
}
static void F_81 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_141 ;
struct V_5 * V_4 = F_8 ( V_2 , V_27 ) ;
struct V_6 * V_8 ;
unsigned int V_31 ;
if ( ! V_4 )
return;
V_8 = F_4 ( V_2 ) ;
F_64 ( & V_8 -> V_88 ) ;
if ( V_8 -> V_37 == 1 ) {
F_15 ( & V_2 -> V_25 , L_52 , V_27 ) ;
V_8 -> V_37 = 0 ;
F_15 ( & V_2 -> V_25 , L_53 , V_27 ) ;
if ( ( V_4 -> V_148 ) && ( V_8 -> V_34 == 1 ) ) {
F_22 ( V_2 -> V_21 , V_4 -> V_25 ,
F_23 ( V_4 -> V_25 ,
V_2 -> V_39 ) ,
V_2 -> V_21 -> V_35 ,
V_2 -> V_21 ->
V_40 ,
F_20 , V_2 ) ;
V_31 = F_24 ( V_2 -> V_21 , V_41 ) ;
if ( V_31 )
F_52 ( & V_2 -> V_25 ,
L_54 ,
V_27 , V_31 ) ;
}
}
F_65 ( & V_8 -> V_88 ) ;
}
static int F_82 ( struct V_5 * V_4 )
{
int V_87 ;
V_87 =
( V_4 -> V_209 -> V_210 -> V_211 . V_212 - 1 ) / 2 ;
return V_87 ;
}
