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
static void F_12 ( struct V_1 * V_2 , unsigned char V_7 )
{
struct V_18 * V_18 = V_2 -> V_19 ;
if ( V_18 -> V_20 )
F_13 ( & V_2 -> V_2 , V_7 , V_21 ) ;
}
static void F_14 ( struct V_18 * V_18 )
{
int V_22 ;
struct V_6 * V_6 ;
V_22 = V_18 -> V_22 ;
if ( V_22 ) {
F_15 ( & V_18 -> V_23 -> V_23 ,
L_5 , V_22 ) ;
return;
}
V_6 = V_18 -> V_24 ;
F_16 ( & V_6 -> V_2 -> V_2 ) ;
}
static void F_17 ( struct V_18 * V_18 )
{
}
static void F_18 ( struct V_18 * V_18 ,
struct V_6 * V_8 ,
struct V_1 * V_2 )
{
int V_25 , V_26 ;
unsigned char * V_7 = V_18 -> V_27 ;
unsigned int V_28 = V_18 -> V_20 ;
for ( V_26 = 0 ; V_26 < V_28 ; ++ V_26 ) {
if ( ( V_26 <= ( V_28 - 3 ) ) && ( V_7 [ V_26 ] == 0x1b )
&& ( V_7 [ V_26 + 1 ] == 0x1b ) ) {
V_25 = 0 ;
switch ( V_7 [ V_26 + 2 ] ) {
case 0x00 :
if ( V_26 > ( V_28 - 4 ) ) {
F_15 ( & V_2 -> V_23 ,
L_6 ) ;
break;
}
F_9 ( V_8 , V_7 [ V_26 + 3 ] ) ;
V_26 += 3 ;
V_25 = 1 ;
break;
case 0x01 :
if ( V_26 > ( V_28 - 4 ) ) {
F_15 ( & V_2 -> V_23 ,
L_6 ) ;
break;
}
F_10 ( V_8 , V_7 [ V_26 + 3 ] ) ;
V_26 += 3 ;
V_25 = 1 ;
break;
case 0xff :
F_15 ( & V_2 -> V_23 , L_7 ) ;
F_12 ( V_2 , V_7 [ V_26 ] ) ;
F_12 ( V_2 , V_7 [ V_26 + 1 ] ) ;
V_26 += 2 ;
break;
}
if ( V_25 == 1 )
continue;
}
if ( V_18 -> V_20 )
F_13 ( & V_2 -> V_2 , V_7 [ V_26 ] , V_21 ) ;
}
F_19 ( & V_2 -> V_2 ) ;
}
static void F_20 ( struct V_18 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_24 ;
struct V_5 * V_4 = F_8 ( V_2 , V_29 ) ;
struct V_6 * V_8 = F_4 ( V_2 ) ;
int V_30 ;
if ( V_18 -> V_22 ) {
V_8 -> V_31 = 1 ;
F_15 ( & V_18 -> V_23 -> V_23 ,
L_8 ,
V_29 , V_18 -> V_22 ) ;
return;
}
F_15 ( & V_2 -> V_23 ,
L_9 , V_29 , V_8 -> V_32 ) ;
if ( F_1 ( V_2 , V_29 ) != 0 ) {
V_8 -> V_31 = 1 ;
return;
}
if ( ! V_4 )
return;
if ( V_8 -> V_33 == 1 ) {
F_15 ( & V_2 -> V_23 ,
L_10 , V_29 ) ;
V_8 -> V_31 = 1 ;
return;
}
if ( V_8 -> V_32 == 1 ) {
V_8 -> V_31 = 1 ;
return;
}
if ( V_18 -> V_22 ) {
V_8 -> V_31 = 1 ;
F_15 ( & V_2 -> V_23 ,
L_11 ,
V_29 , V_18 -> V_22 ) ;
return;
}
if ( V_18 -> V_20 )
F_18 ( V_18 , V_8 , V_2 ) ;
F_21 ( V_2 -> V_19 , V_4 -> V_23 ,
F_22 ( V_4 -> V_23 ,
V_2 -> V_34 ) ,
V_2 -> V_19 -> V_27 ,
V_2 -> V_19 -> V_35 ,
F_20 , V_2 ) ;
V_30 = F_23 ( V_2 -> V_19 , V_36 ) ;
if ( V_30 )
F_15 ( & V_2 -> V_23 ,
L_12 ,
V_29 , V_30 ) ;
else {
if ( V_18 -> V_20 ) {
F_19 ( & V_2 -> V_2 ) ;
F_24 ( & V_2 -> V_2 ) ;
}
}
F_25 ( & V_2 -> V_37 ) ;
}
static int F_26 ( struct V_5 * V_4 ,
struct V_38 * V_39 )
{
int V_30 ;
unsigned char * V_27 ;
V_27 =
F_27 ( sizeof( struct V_38 ) , V_40 ) ;
if ( ! V_27 )
return - V_41 ;
V_30 = F_28 ( V_4 -> V_23 , F_29 ( V_4 -> V_23 , 0 ) ,
V_42 , 0xc0 , 0 , 0 ,
V_27 ,
sizeof( struct V_38 ) , 300 ) ;
if ( V_30 > 0 )
memcpy ( V_39 , V_27 ,
sizeof( struct V_38 ) ) ;
F_30 ( V_27 ) ;
return V_30 ;
}
static int F_31 ( struct V_5 * V_4 )
{
int V_30 ;
T_1 V_43 ;
V_43 = V_44 ;
V_30 = F_28 ( V_4 -> V_23 , F_32 ( V_4 -> V_23 , 0 ) ,
V_45 , 0x40 ,
V_43 , 0 , NULL , 0 , 300 ) ;
return V_30 ;
}
static int F_33 ( struct V_5 * V_4 , T_1 V_46 )
{
int V_30 ;
T_1 V_43 ;
V_43 = V_44 ;
V_30 =
F_28 ( V_4 -> V_23 , F_32 ( V_4 -> V_23 , 0 ) ,
V_47 , 0x40 , V_46 , 0 , NULL , 0 , 300 ) ;
return V_30 ;
}
static int F_34 ( struct V_5 * V_4 ,
struct V_38 * V_39 )
{
int V_30 ;
T_1 V_48 ;
T_1 V_49 ;
V_49 = ( ( T_1 ) ( V_39 -> V_50 ) ) ;
V_49 = ( V_49 << 8 ) ;
V_49 += ( ( T_1 ) ( V_39 -> V_51 ) ) ;
V_48 = sizeof( struct V_38 ) ;
V_30 = F_28 ( V_4 -> V_23 , F_32 ( V_4 -> V_23 , 0 ) ,
V_42 , 0x40 , V_49 ,
0 , NULL , 0 , 300 ) ;
return V_30 ;
}
static int F_35 ( struct V_5 * V_4 , T_1 V_52 ,
struct V_53 * V_54 )
{
int V_30 ;
V_30 = F_28 ( V_4 -> V_23 , F_29 ( V_4 -> V_23 , 0 ) ,
V_55 ,
V_56 , 1 , V_52 ,
V_54 ,
sizeof( struct V_53 ) , 300 ) ;
return V_30 ;
}
static int F_36 ( struct V_5 * V_4 , T_1 V_52 )
{
int V_30 ;
V_30 = F_28 ( V_4 -> V_23 , F_29 ( V_4 -> V_23 , 0 ) ,
V_55 ,
V_57 , 0 , V_52 ,
NULL , 0 , 300 ) ;
return V_30 ;
}
static int F_37 ( struct V_5 * V_4 , unsigned short V_52 ,
unsigned short V_58 , T_2 * V_59 )
{
int V_30 ;
T_1 V_60 ;
V_60 = sizeof( struct V_38 ) ;
V_30 =
F_28 ( V_4 -> V_23 , F_29 ( V_4 -> V_23 , 0 ) ,
V_61 , 0xC0 , V_58 ,
V_52 , ( void * ) V_59 , sizeof( * V_59 ) , 300 ) ;
return V_30 ;
}
static int F_38 ( struct V_5 * V_4 , unsigned short V_52 ,
unsigned short V_58 , unsigned short V_62 )
{
int V_30 ;
unsigned short V_63 ;
V_63 = V_62 ;
V_63 = V_63 << 8 ;
V_63 = V_63 + V_58 ;
V_30 =
F_28 ( V_4 -> V_23 , F_32 ( V_4 -> V_23 , 0 ) ,
V_61 , 0x40 , V_63 , V_52 ,
NULL , 0 , 300 ) ;
return V_30 ;
}
static int F_39 ( struct V_5 * V_4 , unsigned short V_52 ,
unsigned short V_64 , unsigned char V_65 )
{
int V_30 ;
unsigned short V_66 ;
V_66 = ( V_65 << 8 ) + V_52 ;
V_30 =
F_28 ( V_4 -> V_23 , F_32 ( V_4 -> V_23 , 0 ) ,
V_67 , 0x40 , V_64 ,
V_66 , NULL , 0 , 300 ) ;
return V_30 ;
}
static int F_40 ( struct V_5 * V_4 , unsigned int V_68 ,
int V_69 )
{
T_2 V_70 = 0 ;
T_2 V_71 = 0 , V_72 = 0 ;
unsigned int V_22 ;
if ( V_69 == 1 ) {
V_70 = V_73 ;
}
else {
V_70 = 0 ;
}
V_72 = V_70 << 8 ;
if ( V_69 == 1 ) {
V_71 = V_74 ;
} else {
V_71 = 0 ;
}
V_72 |= V_71 ;
V_22 =
F_28 ( V_4 -> V_23 , F_32 ( V_4 -> V_23 , 0 ) ,
V_75 , 0x40 , V_72 ,
V_68 , NULL , 0 , 300 ) ;
return V_22 ;
}
static int F_41 ( struct V_5 * V_4 , T_1 V_68 ,
unsigned char V_76 , unsigned char V_77 )
{
T_1 V_78 ;
int V_30 ;
V_78 = V_77 << 8 ;
V_78 = ( unsigned short ) V_76 ;
V_30 =
F_28 ( V_4 -> V_23 , F_32 ( V_4 -> V_23 , 0 ) ,
V_79 , 0x40 , V_78 ,
V_68 , NULL , 0 , 300 ) ;
return V_30 ;
}
static int F_42 ( struct V_5 * V_4 , T_1 V_68 )
{
int V_30 ;
V_30 =
F_28 ( V_4 -> V_23 , F_32 ( V_4 -> V_23 , 0 ) ,
V_80 , 0x40 , 0 , V_68 ,
NULL , 0 , 300 ) ;
return V_30 ;
}
static int F_43 ( struct V_5 * V_4 )
{
struct V_81 * V_23 = & V_4 -> V_23 -> V_23 ;
struct V_1 * V_2 ;
struct V_6 * V_8 ;
struct V_38 V_82 ;
int V_26 ;
int V_22 ;
for ( V_26 = 0 ; V_26 < V_4 -> V_83 ; V_26 ++ ) {
V_2 = V_4 -> V_2 [ V_26 ] ;
V_8 = F_44 ( sizeof( * V_8 ) , V_40 ) ;
if ( ! V_8 ) {
for ( -- V_26 ; V_26 >= 0 ; V_26 -- ) {
V_2 = V_4 -> V_2 [ V_26 ] ;
F_30 ( F_5 ( V_2 ) ) ;
F_7 ( V_2 , NULL ) ;
}
return - V_41 ;
}
F_45 ( & V_8 -> V_84 ) ;
F_7 ( V_2 , V_8 ) ;
}
V_22 = F_26 ( V_4 , & V_82 ) ;
if ( V_22 < 0 )
goto V_85;
F_15 ( V_23 , L_13 , V_82 . V_50 ) ;
V_82 . V_50 &= ~ V_86 ;
F_15 ( V_23 , L_14 , V_82 . V_50 ) ;
V_22 = F_34 ( V_4 , & V_82 ) ;
if ( V_22 < 0 ) {
F_15 ( V_23 , L_15 ) ;
goto V_85;
}
V_22 = F_26 ( V_4 , & V_82 ) ;
if ( V_22 < 0 ) {
F_15 ( V_23 , L_16 ) ;
goto V_85;
}
switch ( V_4 -> V_23 -> V_87 . V_88 ) {
case V_89 :
case V_90 :
case V_91 :
case V_92 :
case V_93 :
case V_94 :
case V_95 :
case V_96 :
V_82 . V_51 &= ~ ( V_97 | V_98 ) ;
V_82 . V_51 |= V_99 ;
V_82 . V_50 &= ~ ( V_100 ) ;
V_82 . V_50 |= V_101 ;
break;
case V_102 :
case V_103 :
case V_104 :
case V_105 :
case V_106 :
case V_107 :
case V_108 :
case V_109 :
case V_110 :
V_82 . V_51 &= ~ ( V_97 | V_98 ) ;
V_82 . V_51 |= V_99 ;
V_82 . V_50 &= ~ ( V_100 ) ;
V_82 . V_50 |= V_111 ;
break;
default:
V_82 . V_51 &= ~ ( V_97 | V_98 ) ;
V_82 . V_51 |= V_99 ;
V_82 . V_50 &= ~ ( V_100 ) ;
V_82 . V_50 |= V_101 ;
break;
}
V_22 = F_31 ( V_4 ) ;
if ( V_22 < 0 ) {
F_15 ( V_23 , L_17 ) ;
goto V_85;
}
V_22 = F_33 ( V_4 , V_112 ) ;
if ( V_22 < 0 ) {
F_15 ( V_23 , L_18 ) ;
goto V_85;
}
F_15 ( V_23 , L_13 , V_82 . V_50 ) ;
V_82 . V_50 |= V_113 ;
F_15 ( V_23 , L_14 , V_82 . V_50 ) ;
V_22 = F_34 ( V_4 , & V_82 ) ;
if ( V_22 < 0 ) {
F_15 ( V_23 , L_15 ) ;
goto V_85;
}
return 0 ;
V_85:
for ( V_26 = 0 ; V_26 < V_4 -> V_83 ; V_26 ++ ) {
V_2 = V_4 -> V_2 [ V_26 ] ;
V_8 = F_4 ( V_2 ) ;
F_30 ( V_8 ) ;
F_7 ( V_2 , NULL ) ;
}
return - V_114 ;
}
static void F_46 ( struct V_5 * V_4 )
{
struct V_1 * V_2 ;
struct V_6 * V_8 ;
int V_26 ;
for ( V_26 = 0 ; V_26 < V_4 -> V_83 ; V_26 ++ ) {
V_2 = V_4 -> V_2 [ V_26 ] ;
if ( ! V_2 )
continue;
V_8 = F_5 ( V_2 ) ;
F_30 ( V_8 ) ;
F_7 ( V_2 , NULL ) ;
}
}
static void F_47 ( struct V_5 * V_4 ,
struct V_1 * V_2 )
{
int V_30 ;
struct V_1 * V_115 = V_4 -> V_2 [ 0 ] ;
F_48 ( V_115 -> V_116 ,
V_4 -> V_23 ,
F_49 ( V_4 -> V_23 ,
V_115 -> V_117 ) ,
V_115 -> V_118 ,
V_115 -> V_116 -> V_35 ,
F_17 , V_4 ,
V_115 -> V_116 -> V_119 ) ;
V_30 = F_23 ( V_115 -> V_116 ,
V_40 ) ;
if ( V_30 ) {
F_50 ( & V_2 -> V_23 ,
L_19 ,
V_29 , V_30 ) ;
}
}
static int F_51 ( struct V_120 * V_121 ,
struct V_1 * V_2 )
{
struct V_5 * V_4 ;
struct V_6 * V_6 ;
struct V_6 * V_115 ;
struct V_53 V_122 ;
int V_30 ;
if ( F_1 ( V_2 , V_29 ) )
return - V_123 ;
V_4 = V_2 -> V_4 ;
if ( F_3 ( V_4 , V_29 ) )
return - V_123 ;
V_6 = F_4 ( V_2 ) ;
V_115 = F_4 ( V_4 -> V_2 [ 0 ] ) ;
if ( V_6 == NULL || V_115 == NULL )
return - V_123 ;
F_52 ( V_4 -> V_23 , V_2 -> V_124 -> V_125 ) ;
F_52 ( V_4 -> V_23 , V_2 -> V_19 -> V_125 ) ;
V_115 -> V_126 ++ ;
V_30 = F_26 ( V_4 , & V_115 -> V_82 ) ;
V_30 = F_35 ( V_4 , V_2 -> V_127 , & V_122 ) ;
if ( V_30 < 0 ) {
F_15 ( & V_2 -> V_23 , L_20 ) ;
return V_30 ;
}
F_15 ( & V_2 -> V_23 , L_21 ) ;
V_6 -> V_10 = V_122 . V_9 &
( V_11 | V_12 | V_13 | V_14 ) ;
V_6 -> V_16 = V_122 . V_15 &
( V_74 | V_128 | V_129 | V_130 ) ;
V_30 = F_39 ( V_4 , V_2 -> V_127 , V_131 , V_132 ) ;
if ( V_30 < 0 ) {
F_15 ( & V_2 -> V_23 , L_22 ) ;
return V_30 ;
}
F_15 ( & V_2 -> V_23 , L_23 ) ;
if ( V_115 -> V_126 == 1 ) {
if ( V_4 -> V_2 [ 0 ] -> V_118 == NULL )
F_47 ( V_4 , V_2 ) ;
}
F_15 ( & V_2 -> V_23 , L_24 , V_2 -> V_127 ) ;
F_15 ( & V_2 -> V_23 , L_25 , V_2 -> V_4 -> V_133 ) ;
F_15 ( & V_2 -> V_23 ,
L_26 , V_2 -> V_34 ) ;
F_15 ( & V_2 -> V_23 ,
L_27 , V_2 -> V_134 ) ;
F_15 ( & V_2 -> V_23 , L_28 ,
V_2 -> V_117 ) ;
F_15 ( & V_2 -> V_23 , L_29 ,
V_6 -> V_135 ) ;
V_6 -> V_19 = V_2 -> V_19 ;
F_21 ( V_6 -> V_19 ,
V_4 -> V_23 ,
F_22 ( V_4 -> V_23 ,
V_2 -> V_34 ) ,
V_2 -> V_136 ,
V_6 -> V_19 -> V_35 ,
F_20 , V_6 ) ;
F_15 ( & V_2 -> V_23 , L_30 ,
V_2 -> V_34 ) ;
V_6 -> V_137 = true ;
V_30 = F_23 ( V_6 -> V_19 , V_40 ) ;
if ( V_30 ) {
F_50 ( & V_2 -> V_23 ,
L_31 ,
V_29 , V_30 ) ;
V_6 -> V_137 = false ;
}
F_53 ( & V_6 -> V_17 ) ;
F_53 ( & V_6 -> V_138 ) ;
memset ( & ( V_6 -> V_139 ) , 0x00 , sizeof( V_6 -> V_139 ) ) ;
return 0 ;
}
static int F_54 ( struct V_120 * V_121 )
{
struct V_1 * V_2 = V_121 -> V_140 ;
struct V_5 * V_4 ;
int V_141 = 0 ;
V_4 = F_8 ( V_2 , V_29 ) ;
if ( V_4 -> V_142 ) {
if ( V_2 -> V_124 -> V_22 == - V_143 )
V_141 = V_2 -> V_124 -> V_35 ;
}
return V_141 ;
}
static void F_55 ( struct V_120 * V_121 ,
struct V_6 * V_8 )
{
int V_144 = V_145 / 10 ;
int V_17 = 30 ;
int V_146 ;
while ( 1 ) {
V_146 = F_54 ( V_121 ) ;
if ( V_146 <= 0 )
return;
F_56 ( & V_8 -> V_17 , V_144 ) ;
V_17 -- ;
if ( V_17 == 0 ) {
F_15 ( & V_8 -> V_2 -> V_23 , L_32 , V_29 ) ;
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
struct V_6 * V_115 ;
struct V_120 * V_121 ;
int V_22 ;
unsigned int V_68 ;
V_22 = 0 ;
V_121 = F_58 ( & V_2 -> V_2 ) ;
V_68 = V_121 -> V_68 - V_4 -> V_133 ;
V_8 = F_4 ( V_2 ) ;
V_115 = F_4 ( V_4 -> V_2 [ 0 ] ) ;
if ( V_4 -> V_142 )
F_59 ( V_2 -> V_124 ) ;
if ( V_4 -> V_147 )
F_59 ( V_2 -> V_19 ) ;
if ( V_4 -> V_23 )
F_55 ( V_121 , V_8 ) ;
F_60 ( V_121 ) ;
V_22 = F_36 ( V_4 , V_68 ) ;
if ( V_22 < 0 )
F_15 ( & V_2 -> V_23 ,
L_33 ,
V_29 , V_2 -> V_127 ) ;
V_115 -> V_126 -- ;
F_15 ( & V_2 -> V_23 , L_34 ,
V_115 -> V_126 , V_2 -> V_127 ) ;
if ( V_115 -> V_126 == 0 ) {
if ( V_4 -> V_2 [ 0 ] -> V_116 ) {
F_15 ( & V_2 -> V_23 , L_35 ) ;
F_61 ( V_4 -> V_2 [ 0 ] -> V_116 ) ;
}
}
if ( V_8 -> V_124 ) {
F_30 ( V_8 -> V_124 -> V_27 ) ;
F_62 ( V_8 -> V_124 ) ;
}
}
static int F_63 ( struct V_120 * V_121 , struct V_1 * V_2 ,
const unsigned char * V_148 , int V_146 )
{
int V_30 ;
struct V_5 * V_4 = F_8 ( V_2 , V_29 ) ;
if ( V_4 == NULL )
return - V_123 ;
if ( V_146 == 0 ) {
F_15 ( & V_2 -> V_23 ,
L_36 , V_29 ) ;
return 0 ;
}
if ( V_4 -> V_142 ) {
if ( V_2 -> V_124 -> V_22 == - V_143 ) {
F_15 ( & V_2 -> V_23 , L_37 , V_29 ) ;
return 0 ;
}
V_146 =
( V_146 > V_2 -> V_149 ) ? V_2 -> V_149 : V_146 ;
memcpy ( V_2 -> V_124 -> V_27 , V_148 , V_146 ) ;
F_21 ( V_2 -> V_124 , V_4 -> V_23 ,
F_64 ( V_4 -> V_23 ,
V_2 ->
V_134 ) ,
V_2 -> V_124 -> V_27 , V_146 ,
F_14 , V_2 ) ;
V_30 = F_23 ( V_2 -> V_124 , V_36 ) ;
if ( V_30 )
F_15 ( & V_2 -> V_23 ,
L_38 ,
V_29 , V_30 ) ;
else
V_30 = V_146 ;
return V_30 ;
}
return 0 ;
}
static int F_65 ( struct V_120 * V_121 )
{
struct V_1 * V_2 = V_121 -> V_140 ;
struct V_5 * V_4 ;
struct V_6 * V_8 ;
int V_150 = - V_151 ;
if ( F_1 ( V_2 , V_29 ) )
return - 1 ;
V_4 = F_8 ( V_2 , V_29 ) ;
if ( ! V_4 )
return - V_123 ;
V_8 = F_4 ( V_2 ) ;
F_66 ( & V_8 -> V_84 ) ;
if ( V_4 -> V_142 ) {
if ( V_2 -> V_124 -> V_22 != - V_143 )
V_150 = V_2 -> V_149 ;
}
F_67 ( & V_8 -> V_84 ) ;
return V_150 ;
}
static int F_68 ( struct V_120 * V_121 ,
unsigned int V_152 , unsigned long V_153 )
{
struct V_1 * V_2 = V_121 -> V_140 ;
struct V_6 * V_8 = F_4 ( V_2 ) ;
struct V_5 * V_4 = F_8 ( V_2 , V_29 ) ;
unsigned int V_68 ;
F_15 ( & V_2 -> V_23 , L_39 , V_29 , V_152 ) ;
V_68 = V_121 -> V_68 - V_4 -> V_133 ;
if ( V_152 == V_154 ) {
while ( V_8 != NULL ) {
F_69 ( & V_8 -> V_138 ) ;
if ( F_70 ( V_155 ) )
return - V_156 ;
else {
char V_157 = V_8 -> V_158 ;
if ( V_157 == 0 )
return - V_114 ;
V_8 -> V_158 = 0 ;
if ( ( ( V_153 & V_159 )
&& ( V_157 & V_129 ) )
|| ( ( V_153 & V_160 )
&& ( V_157 & V_128 ) )
|| ( ( V_153 & V_161 )
&& ( V_157 & V_130 ) )
|| ( ( V_153 & V_162 )
&& ( V_157 & V_74 ) ) ) {
return 0 ;
}
}
}
return 0 ;
}
F_15 ( & V_2 -> V_23 , L_40 ,
V_29 , V_2 -> V_127 ) ;
return - V_163 ;
}
static void F_71 ( struct V_120 * V_121 ,
struct V_1 * V_2 ,
struct V_164 * V_165 )
{
struct V_164 * V_166 = & V_121 -> V_166 ;
unsigned char V_167 = 0 ;
unsigned int V_168 = V_166 -> V_169 ;
unsigned int V_68 ;
int V_170 , V_171 , V_172 ;
int V_22 ;
V_68 = V_121 -> V_68 - V_2 -> V_4 -> V_133 ;
switch ( V_168 & V_173 ) {
case V_174 :
V_167 |= V_175 ;
break;
case V_176 :
V_167 |= V_177 ;
break;
case V_178 :
V_167 |= V_179 ;
break;
default:
V_166 -> V_169 &= ~ V_173 ;
V_166 -> V_169 |= V_180 ;
case V_180 :
V_167 |= V_181 ;
break;
}
if ( V_168 & V_182 ) {
if ( V_168 & V_183 )
V_167 |= V_184 ;
else
V_167 |= V_185 ;
}
if ( V_168 & V_186 )
V_167 |= V_187 ;
else
V_167 |= V_188 ;
F_15 ( & V_2 -> V_23 , L_41 , V_29 ) ;
V_170 = F_72 ( V_121 ) ;
if ( ! V_170 )
V_170 = 9600 ;
F_15 ( & V_2 -> V_23 , L_42 , V_29 , V_170 ) ;
V_171 = V_189 / V_170 ;
V_172 = V_189 % V_170 ;
if ( ( ( V_172 * 2 ) >= V_170 ) && ( V_170 != 110 ) )
V_171 ++ ;
V_22 =
F_39 ( V_2 -> V_4 , V_68 , ( unsigned short ) V_171 , V_167 ) ;
if ( V_22 < 0 ) {
F_15 ( & V_2 -> V_23 , L_22 ) ;
return;
}
if ( V_168 & V_190 ) {
F_15 ( & V_2 -> V_23 , L_43 ,
V_29 , V_2 -> V_127 ) ;
V_22 = F_40 ( V_2 -> V_4 , V_68 , 1 ) ;
if ( V_22 < 0 ) {
F_15 ( & V_2 -> V_23 , L_44 ) ;
return;
}
} else {
F_15 ( & V_2 -> V_23 ,
L_45 ,
V_29 , V_2 -> V_127 ) ;
V_22 = F_40 ( V_2 -> V_4 , V_68 , 0 ) ;
if ( V_22 < 0 ) {
F_15 ( & V_2 -> V_23 , L_44 ) ;
return;
}
}
if ( F_73 ( V_121 ) || F_74 ( V_121 ) ) {
unsigned char V_76 = F_75 ( V_121 ) ;
unsigned char V_77 = F_76 ( V_121 ) ;
V_22 =
F_41 ( V_2 -> V_4 , V_68 , V_76 ,
V_77 ) ;
if ( V_22 < 0 )
F_15 ( & V_2 -> V_23 ,
L_46 ) ;
} else {
V_22 = F_42 ( V_2 -> V_4 , V_68 ) ;
if ( V_22 < 0 )
F_15 ( & V_2 -> V_23 ,
L_47 ) ;
}
V_166 -> V_169 &= ~ V_191 ;
}
static void F_77 ( struct V_120 * V_121 , int V_192 )
{
struct V_1 * V_2 = V_121 -> V_140 ;
struct V_5 * V_4 = F_8 ( V_2 , V_29 ) ;
struct V_6 * V_8 ;
T_3 V_68 , V_193 ;
unsigned int V_30 ;
V_68 = V_121 -> V_68 - V_4 -> V_133 ;
V_8 = F_4 ( V_2 ) ;
if ( V_192 == - 1 )
V_193 = 1 ;
else
V_193 = 0 ;
F_66 ( & V_8 -> V_84 ) ;
V_30 =
F_28 ( V_4 -> V_23 , F_32 ( V_4 -> V_23 , 0 ) ,
V_194 , 0x40 , V_193 , V_68 , NULL , 0 , 300 ) ;
F_67 ( & V_8 -> V_84 ) ;
}
static inline int F_78 ( struct V_120 * V_121 ,
struct V_1 * V_2 ,
struct V_5 * V_4 )
{
T_4 V_70 ;
T_4 V_71 ;
unsigned int V_30 = 0 ;
int V_22 ;
unsigned int V_68 ;
V_68 = V_121 -> V_68 - V_4 -> V_133 ;
V_22 =
F_37 ( V_2 -> V_4 , V_68 , V_195 , & V_70 ) ;
if ( V_22 >= 0 ) {
V_22 =
F_37 ( V_2 -> V_4 , V_68 ,
V_196 , & V_71 ) ;
}
if ( V_22 >= 0 ) {
V_30 = ( ( V_70 & V_197 ) ? V_198 : 0 )
| ( ( V_70 & V_73 ) ? V_199 : 0 )
| ( ( V_71 & V_74 ) ? V_162 : 0 )
| ( ( V_71 & V_130 ) ? V_200 : 0 )
| ( ( V_71 & V_129 ) ? V_201 : 0 )
| ( ( V_71 & V_128 ) ? V_160 : 0 ) ;
return V_30 ;
} else
return - V_202 ;
}
static inline int F_79 ( struct V_120 * V_121 ,
struct V_1 * V_2 ,
struct V_5 * V_4 ,
unsigned int V_203 )
{
T_4 V_70 ;
int V_22 ;
unsigned int V_68 ;
V_68 = V_121 -> V_68 - V_4 -> V_133 ;
V_22 =
F_37 ( V_2 -> V_4 , V_68 , V_195 , & V_70 ) ;
if ( V_22 < 0 )
return - V_202 ;
V_70 &= ~ ( V_73 | V_197 | V_204 ) ;
if ( V_203 & V_199 )
V_70 |= V_73 ;
if ( V_203 & V_198 )
V_70 |= V_197 ;
if ( V_203 & V_205 )
V_70 |= V_204 ;
V_22 =
F_38 ( V_2 -> V_4 , V_68 , V_195 , V_70 ) ;
if ( V_22 < 0 )
return - V_202 ;
else
return 0 ;
}
static int F_80 ( struct V_120 * V_121 )
{
struct V_1 * V_2 = V_121 -> V_140 ;
struct V_5 * V_4 = F_8 ( V_2 , V_29 ) ;
struct V_6 * V_8 = F_4 ( V_2 ) ;
int V_150 ;
if ( ! V_4 )
return - V_123 ;
F_66 ( & V_8 -> V_84 ) ;
V_150 = F_78 ( V_121 , V_2 , V_4 ) ;
F_67 ( & V_8 -> V_84 ) ;
return V_150 ;
}
static int F_81 ( struct V_120 * V_121 ,
unsigned int V_206 , unsigned int V_207 )
{
struct V_1 * V_2 = V_121 -> V_140 ;
struct V_5 * V_4 = F_8 ( V_2 , V_29 ) ;
struct V_6 * V_8 = F_4 ( V_2 ) ;
int V_150 ;
if ( ! V_4 )
return - V_123 ;
F_66 ( & V_8 -> V_84 ) ;
V_150 = F_79 ( V_121 , V_2 , V_4 , V_206 ) ;
F_67 ( & V_8 -> V_84 ) ;
return V_150 ;
}
static void F_82 ( struct V_120 * V_121 )
{
struct V_1 * V_2 = V_121 -> V_140 ;
struct V_5 * V_4 = F_8 ( V_2 , V_29 ) ;
struct V_6 * V_8 ;
if ( ! V_4 )
return;
V_8 = F_4 ( V_2 ) ;
F_66 ( & V_8 -> V_84 ) ;
V_8 -> V_32 = 1 ;
F_67 ( & V_8 -> V_84 ) ;
}
static void F_83 ( struct V_1 * V_2 ,
struct V_5 * V_4 )
{
int V_30 ;
F_21 ( V_2 -> V_19 , V_4 -> V_23 ,
F_22 ( V_4 -> V_23 ,
V_2 -> V_34 ) ,
V_2 -> V_19 -> V_27 ,
V_2 -> V_19 -> V_35 ,
F_20 , V_2 ) ;
V_30 = F_23 ( V_2 -> V_19 , V_36 ) ;
if ( V_30 )
F_50 ( & V_2 -> V_23 ,
L_48 ,
V_29 , V_30 ) ;
}
static void F_84 ( struct V_120 * V_121 )
{
struct V_1 * V_2 = V_121 -> V_140 ;
struct V_5 * V_4 = F_8 ( V_2 , V_29 ) ;
struct V_6 * V_8 ;
if ( ! V_4 )
return;
V_8 = F_4 ( V_2 ) ;
F_66 ( & V_8 -> V_84 ) ;
if ( V_8 -> V_32 == 1 ) {
F_15 ( & V_2 -> V_23 , L_49 , V_29 ) ;
V_8 -> V_32 = 0 ;
F_15 ( & V_2 -> V_23 , L_50 , V_29 ) ;
if ( ( V_4 -> V_147 ) && ( V_8 -> V_31 == 1 ) )
F_83 ( V_2 , V_4 ) ;
}
F_67 ( & V_8 -> V_84 ) ;
}
static int F_85 ( struct V_5 * V_4 )
{
int V_83 ;
V_83 =
( V_4 -> V_208 -> V_209 -> V_210 . V_211 - 1 ) / 2 ;
return V_83 ;
}
