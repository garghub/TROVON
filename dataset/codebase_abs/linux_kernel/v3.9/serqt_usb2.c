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
struct V_22 * V_23 ;
int V_24 ;
struct V_6 * V_6 ;
V_24 = V_18 -> V_24 ;
if ( V_24 ) {
F_15 ( & V_18 -> V_25 -> V_25 ,
L_5 , V_24 ) ;
return;
}
V_6 = V_18 -> V_26 ;
V_23 = F_16 ( & V_6 -> V_2 -> V_2 ) ;
if ( V_23 )
F_17 ( V_23 ) ;
F_18 ( V_23 ) ;
}
static void F_19 ( struct V_18 * V_18 )
{
}
static void F_20 ( struct V_18 * V_18 ,
struct V_6 * V_8 ,
struct V_1 * V_2 )
{
int V_27 , V_28 ;
unsigned char * V_7 = V_18 -> V_29 ;
unsigned int V_30 = V_18 -> V_20 ;
for ( V_28 = 0 ; V_28 < V_30 ; ++ V_28 ) {
if ( ( V_28 <= ( V_30 - 3 ) ) && ( V_7 [ V_28 ] == 0x1b )
&& ( V_7 [ V_28 + 1 ] == 0x1b ) ) {
V_27 = 0 ;
switch ( V_7 [ V_28 + 2 ] ) {
case 0x00 :
if ( V_28 > ( V_30 - 4 ) ) {
F_15 ( & V_2 -> V_25 ,
L_6 ) ;
break;
}
F_9 ( V_8 , V_7 [ V_28 + 3 ] ) ;
V_28 += 3 ;
V_27 = 1 ;
break;
case 0x01 :
if ( V_28 > ( V_30 - 4 ) ) {
F_15 ( & V_2 -> V_25 ,
L_6 ) ;
break;
}
F_10 ( V_8 , V_7 [ V_28 + 3 ] ) ;
V_28 += 3 ;
V_27 = 1 ;
break;
case 0xff :
F_15 ( & V_2 -> V_25 , L_7 ) ;
F_12 ( V_2 , V_7 [ V_28 ] ) ;
F_12 ( V_2 , V_7 [ V_28 + 1 ] ) ;
V_28 += 2 ;
break;
}
if ( V_27 == 1 )
continue;
}
if ( V_18 -> V_20 )
F_13 ( & V_2 -> V_2 , V_7 [ V_28 ] , V_21 ) ;
}
F_21 ( & V_2 -> V_2 ) ;
}
static void F_22 ( struct V_18 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_26 ;
struct V_5 * V_4 = F_8 ( V_2 , V_31 ) ;
struct V_6 * V_8 = F_4 ( V_2 ) ;
int V_32 ;
if ( V_18 -> V_24 ) {
V_8 -> V_33 = 1 ;
F_15 ( & V_18 -> V_25 -> V_25 ,
L_8 ,
V_31 , V_18 -> V_24 ) ;
return;
}
F_15 ( & V_2 -> V_25 ,
L_9 , V_31 , V_8 -> V_34 ) ;
if ( F_1 ( V_2 , V_31 ) != 0 ) {
V_8 -> V_33 = 1 ;
return;
}
if ( ! V_4 )
return;
if ( V_8 -> V_35 == 1 ) {
F_15 ( & V_2 -> V_25 ,
L_10 , V_31 ) ;
V_8 -> V_33 = 1 ;
return;
}
if ( V_8 -> V_34 == 1 ) {
V_8 -> V_33 = 1 ;
return;
}
if ( V_18 -> V_24 ) {
V_8 -> V_33 = 1 ;
F_15 ( & V_2 -> V_25 ,
L_11 ,
V_31 , V_18 -> V_24 ) ;
return;
}
if ( V_18 -> V_20 )
F_20 ( V_18 , V_8 , V_2 ) ;
F_23 ( V_2 -> V_19 , V_4 -> V_25 ,
F_24 ( V_4 -> V_25 ,
V_2 -> V_36 ) ,
V_2 -> V_19 -> V_29 ,
V_2 -> V_19 -> V_37 ,
F_22 , V_2 ) ;
V_32 = F_25 ( V_2 -> V_19 , V_38 ) ;
if ( V_32 )
F_15 ( & V_2 -> V_25 ,
L_12 ,
V_31 , V_32 ) ;
else {
if ( V_18 -> V_20 ) {
F_21 ( & V_2 -> V_2 ) ;
F_26 ( & V_2 -> V_2 ) ;
}
}
F_27 ( & V_2 -> V_39 ) ;
}
static int F_28 ( struct V_5 * V_4 ,
struct V_40 * V_41 )
{
int V_32 ;
unsigned char * V_29 ;
V_29 =
F_29 ( sizeof( struct V_40 ) , V_42 ) ;
if ( ! V_29 )
return - V_43 ;
V_32 = F_30 ( V_4 -> V_25 , F_31 ( V_4 -> V_25 , 0 ) ,
V_44 , 0xc0 , 0 , 0 ,
V_29 ,
sizeof( struct V_40 ) , 300 ) ;
if ( V_32 > 0 )
memcpy ( V_41 , V_29 ,
sizeof( struct V_40 ) ) ;
F_32 ( V_29 ) ;
return V_32 ;
}
static int F_33 ( struct V_5 * V_4 )
{
int V_32 ;
T_1 V_45 ;
V_45 = V_46 ;
V_32 = F_30 ( V_4 -> V_25 , F_34 ( V_4 -> V_25 , 0 ) ,
V_47 , 0x40 ,
V_45 , 0 , NULL , 0 , 300 ) ;
return V_32 ;
}
static int F_35 ( struct V_5 * V_4 , T_1 V_48 )
{
int V_32 ;
T_1 V_45 ;
V_45 = V_46 ;
V_32 =
F_30 ( V_4 -> V_25 , F_34 ( V_4 -> V_25 , 0 ) ,
V_49 , 0x40 , V_48 , 0 , NULL , 0 , 300 ) ;
return V_32 ;
}
static int F_36 ( struct V_5 * V_4 ,
struct V_40 * V_41 )
{
int V_32 ;
T_1 V_50 ;
T_1 V_51 ;
V_51 = ( ( T_1 ) ( V_41 -> V_52 ) ) ;
V_51 = ( V_51 << 8 ) ;
V_51 += ( ( T_1 ) ( V_41 -> V_53 ) ) ;
V_50 = sizeof( struct V_40 ) ;
V_32 = F_30 ( V_4 -> V_25 , F_34 ( V_4 -> V_25 , 0 ) ,
V_44 , 0x40 , V_51 ,
0 , NULL , 0 , 300 ) ;
return V_32 ;
}
static int F_37 ( struct V_5 * V_4 , T_1 V_54 ,
struct V_55 * V_56 )
{
int V_32 ;
V_32 = F_30 ( V_4 -> V_25 , F_31 ( V_4 -> V_25 , 0 ) ,
V_57 ,
V_58 , 1 , V_54 ,
V_56 ,
sizeof( struct V_55 ) , 300 ) ;
return V_32 ;
}
static int F_38 ( struct V_5 * V_4 , T_1 V_54 )
{
int V_32 ;
V_32 = F_30 ( V_4 -> V_25 , F_31 ( V_4 -> V_25 , 0 ) ,
V_57 ,
V_59 , 0 , V_54 ,
NULL , 0 , 300 ) ;
return V_32 ;
}
static int F_39 ( struct V_5 * V_4 , unsigned short V_54 ,
unsigned short V_60 , T_2 * V_61 )
{
int V_32 ;
T_1 V_62 ;
V_62 = sizeof( struct V_40 ) ;
V_32 =
F_30 ( V_4 -> V_25 , F_31 ( V_4 -> V_25 , 0 ) ,
V_63 , 0xC0 , V_60 ,
V_54 , ( void * ) V_61 , sizeof( * V_61 ) , 300 ) ;
return V_32 ;
}
static int F_40 ( struct V_5 * V_4 , unsigned short V_54 ,
unsigned short V_60 , unsigned short V_64 )
{
int V_32 ;
unsigned short V_65 ;
V_65 = V_64 ;
V_65 = V_65 << 8 ;
V_65 = V_65 + V_60 ;
V_32 =
F_30 ( V_4 -> V_25 , F_34 ( V_4 -> V_25 , 0 ) ,
V_63 , 0x40 , V_65 , V_54 ,
NULL , 0 , 300 ) ;
return V_32 ;
}
static int F_41 ( struct V_5 * V_4 , unsigned short V_54 ,
unsigned short V_66 , unsigned char V_67 )
{
int V_32 ;
unsigned short V_68 ;
V_68 = ( V_67 << 8 ) + V_54 ;
V_32 =
F_30 ( V_4 -> V_25 , F_34 ( V_4 -> V_25 , 0 ) ,
V_69 , 0x40 , V_66 ,
V_68 , NULL , 0 , 300 ) ;
return V_32 ;
}
static int F_42 ( struct V_5 * V_4 , unsigned int V_70 ,
int V_71 )
{
T_2 V_72 = 0 ;
T_2 V_73 = 0 , V_74 = 0 ;
unsigned int V_24 ;
if ( V_71 == 1 ) {
V_72 = V_75 ;
}
else {
V_72 = 0 ;
}
V_74 = V_72 << 8 ;
if ( V_71 == 1 ) {
V_73 = V_76 ;
} else {
V_73 = 0 ;
}
V_74 |= V_73 ;
V_24 =
F_30 ( V_4 -> V_25 , F_34 ( V_4 -> V_25 , 0 ) ,
V_77 , 0x40 , V_74 ,
V_70 , NULL , 0 , 300 ) ;
return V_24 ;
}
static int F_43 ( struct V_5 * V_4 , T_1 V_70 ,
unsigned char V_78 , unsigned char V_79 )
{
T_1 V_80 ;
int V_32 ;
V_80 = V_79 << 8 ;
V_80 = ( unsigned short ) V_78 ;
V_32 =
F_30 ( V_4 -> V_25 , F_34 ( V_4 -> V_25 , 0 ) ,
V_81 , 0x40 , V_80 ,
V_70 , NULL , 0 , 300 ) ;
return V_32 ;
}
static int F_44 ( struct V_5 * V_4 , T_1 V_70 )
{
int V_32 ;
V_32 =
F_30 ( V_4 -> V_25 , F_34 ( V_4 -> V_25 , 0 ) ,
V_82 , 0x40 , 0 , V_70 ,
NULL , 0 , 300 ) ;
return V_32 ;
}
static int F_45 ( struct V_5 * V_4 )
{
struct V_83 * V_25 = & V_4 -> V_25 -> V_25 ;
struct V_1 * V_2 ;
struct V_6 * V_8 ;
struct V_40 V_84 ;
int V_28 ;
int V_24 ;
for ( V_28 = 0 ; V_28 < V_4 -> V_85 ; V_28 ++ ) {
V_2 = V_4 -> V_2 [ V_28 ] ;
V_8 = F_46 ( sizeof( * V_8 ) , V_42 ) ;
if ( ! V_8 ) {
for ( -- V_28 ; V_28 >= 0 ; V_28 -- ) {
V_2 = V_4 -> V_2 [ V_28 ] ;
F_32 ( F_5 ( V_2 ) ) ;
F_7 ( V_2 , NULL ) ;
}
return - V_43 ;
}
F_47 ( & V_8 -> V_86 ) ;
F_7 ( V_2 , V_8 ) ;
}
V_24 = F_28 ( V_4 , & V_84 ) ;
if ( V_24 < 0 )
goto V_87;
F_15 ( V_25 , L_13 , V_84 . V_52 ) ;
V_84 . V_52 &= ~ V_88 ;
F_15 ( V_25 , L_14 , V_84 . V_52 ) ;
V_24 = F_36 ( V_4 , & V_84 ) ;
if ( V_24 < 0 ) {
F_15 ( V_25 , L_15 ) ;
goto V_87;
}
V_24 = F_28 ( V_4 , & V_84 ) ;
if ( V_24 < 0 ) {
F_15 ( V_25 , L_16 ) ;
goto V_87;
}
switch ( V_4 -> V_25 -> V_89 . V_90 ) {
case V_91 :
case V_92 :
case V_93 :
case V_94 :
case V_95 :
case V_96 :
case V_97 :
case V_98 :
V_84 . V_53 &= ~ ( V_99 | V_100 ) ;
V_84 . V_53 |= V_101 ;
V_84 . V_52 &= ~ ( V_102 ) ;
V_84 . V_52 |= V_103 ;
break;
case V_104 :
case V_105 :
case V_106 :
case V_107 :
case V_108 :
case V_109 :
case V_110 :
case V_111 :
case V_112 :
V_84 . V_53 &= ~ ( V_99 | V_100 ) ;
V_84 . V_53 |= V_101 ;
V_84 . V_52 &= ~ ( V_102 ) ;
V_84 . V_52 |= V_113 ;
break;
default:
V_84 . V_53 &= ~ ( V_99 | V_100 ) ;
V_84 . V_53 |= V_101 ;
V_84 . V_52 &= ~ ( V_102 ) ;
V_84 . V_52 |= V_103 ;
break;
}
V_24 = F_33 ( V_4 ) ;
if ( V_24 < 0 ) {
F_15 ( V_25 , L_17 ) ;
goto V_87;
}
V_24 = F_35 ( V_4 , V_114 ) ;
if ( V_24 < 0 ) {
F_15 ( V_25 , L_18 ) ;
goto V_87;
}
F_15 ( V_25 , L_13 , V_84 . V_52 ) ;
V_84 . V_52 |= V_115 ;
F_15 ( V_25 , L_14 , V_84 . V_52 ) ;
V_24 = F_36 ( V_4 , & V_84 ) ;
if ( V_24 < 0 ) {
F_15 ( V_25 , L_15 ) ;
goto V_87;
}
return 0 ;
V_87:
for ( V_28 = 0 ; V_28 < V_4 -> V_85 ; V_28 ++ ) {
V_2 = V_4 -> V_2 [ V_28 ] ;
V_8 = F_4 ( V_2 ) ;
F_32 ( V_8 ) ;
F_7 ( V_2 , NULL ) ;
}
return - V_116 ;
}
static void F_48 ( struct V_5 * V_4 )
{
struct V_1 * V_2 ;
struct V_6 * V_8 ;
int V_28 ;
for ( V_28 = 0 ; V_28 < V_4 -> V_85 ; V_28 ++ ) {
V_2 = V_4 -> V_2 [ V_28 ] ;
if ( ! V_2 )
continue;
V_8 = F_5 ( V_2 ) ;
F_32 ( V_8 ) ;
F_7 ( V_2 , NULL ) ;
}
}
static void F_49 ( struct V_5 * V_4 ,
struct V_1 * V_2 )
{
int V_32 ;
struct V_1 * V_117 = V_4 -> V_2 [ 0 ] ;
F_50 ( V_117 -> V_118 ,
V_4 -> V_25 ,
F_51 ( V_4 -> V_25 ,
V_117 -> V_119 ) ,
V_117 -> V_120 ,
V_117 -> V_118 -> V_37 ,
F_19 , V_4 ,
V_117 -> V_118 -> V_121 ) ;
V_32 = F_25 ( V_117 -> V_118 ,
V_42 ) ;
if ( V_32 ) {
F_52 ( & V_2 -> V_25 ,
L_19 ,
V_31 , V_32 ) ;
}
}
static int F_53 ( struct V_22 * V_23 ,
struct V_1 * V_2 )
{
struct V_5 * V_4 ;
struct V_6 * V_6 ;
struct V_6 * V_117 ;
struct V_55 V_122 ;
int V_32 ;
if ( F_1 ( V_2 , V_31 ) )
return - V_123 ;
V_4 = V_2 -> V_4 ;
if ( F_3 ( V_4 , V_31 ) )
return - V_123 ;
V_6 = F_4 ( V_2 ) ;
V_117 = F_4 ( V_4 -> V_2 [ 0 ] ) ;
if ( V_6 == NULL || V_117 == NULL )
return - V_123 ;
F_54 ( V_4 -> V_25 , V_2 -> V_124 -> V_125 ) ;
F_54 ( V_4 -> V_25 , V_2 -> V_19 -> V_125 ) ;
V_117 -> V_126 ++ ;
V_32 = F_28 ( V_4 , & V_117 -> V_84 ) ;
V_32 = F_37 ( V_4 , V_2 -> V_127 , & V_122 ) ;
if ( V_32 < 0 ) {
F_15 ( & V_2 -> V_25 , L_20 ) ;
return V_32 ;
}
F_15 ( & V_2 -> V_25 , L_21 ) ;
V_6 -> V_10 = V_122 . V_9 &
( V_11 | V_12 | V_13 | V_14 ) ;
V_6 -> V_16 = V_122 . V_15 &
( V_76 | V_128 | V_129 | V_130 ) ;
V_32 = F_41 ( V_4 , V_2 -> V_127 , V_131 , V_132 ) ;
if ( V_32 < 0 ) {
F_15 ( & V_2 -> V_25 , L_22 ) ;
return V_32 ;
}
F_15 ( & V_2 -> V_25 , L_23 ) ;
if ( V_117 -> V_126 == 1 ) {
if ( V_4 -> V_2 [ 0 ] -> V_120 == NULL )
F_49 ( V_4 , V_2 ) ;
}
F_15 ( & V_2 -> V_25 , L_24 , V_2 -> V_127 ) ;
F_15 ( & V_2 -> V_25 , L_25 , V_2 -> V_4 -> V_133 ) ;
F_15 ( & V_2 -> V_25 ,
L_26 , V_2 -> V_36 ) ;
F_15 ( & V_2 -> V_25 ,
L_27 , V_2 -> V_134 ) ;
F_15 ( & V_2 -> V_25 , L_28 ,
V_2 -> V_119 ) ;
F_15 ( & V_2 -> V_25 , L_29 ,
V_6 -> V_135 ) ;
V_6 -> V_19 = V_2 -> V_19 ;
F_23 ( V_6 -> V_19 ,
V_4 -> V_25 ,
F_24 ( V_4 -> V_25 ,
V_2 -> V_36 ) ,
V_2 -> V_136 ,
V_6 -> V_19 -> V_37 ,
F_22 , V_6 ) ;
F_15 ( & V_2 -> V_25 , L_30 ,
V_2 -> V_36 ) ;
V_6 -> V_137 = true ;
V_32 = F_25 ( V_6 -> V_19 , V_42 ) ;
if ( V_32 ) {
F_52 ( & V_2 -> V_25 ,
L_31 ,
V_31 , V_32 ) ;
V_6 -> V_137 = false ;
}
F_55 ( & V_6 -> V_17 ) ;
F_55 ( & V_6 -> V_138 ) ;
memset ( & ( V_6 -> V_139 ) , 0x00 , sizeof( V_6 -> V_139 ) ) ;
return 0 ;
}
static int F_56 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = V_23 -> V_140 ;
struct V_5 * V_4 ;
int V_141 = 0 ;
V_4 = F_8 ( V_2 , V_31 ) ;
if ( V_4 -> V_142 ) {
if ( V_2 -> V_124 -> V_24 == - V_143 )
V_141 = V_2 -> V_124 -> V_37 ;
}
return V_141 ;
}
static void F_57 ( struct V_22 * V_23 ,
struct V_6 * V_8 )
{
int V_144 = V_145 / 10 ;
int V_17 = 30 ;
int V_146 ;
while ( 1 ) {
V_146 = F_56 ( V_23 ) ;
if ( V_146 <= 0 )
return;
F_58 ( & V_8 -> V_17 , V_144 ) ;
V_17 -- ;
if ( V_17 == 0 ) {
F_15 ( & V_8 -> V_2 -> V_25 , L_32 , V_31 ) ;
return;
} else {
V_17 = 30 ;
}
}
}
static void F_59 ( struct V_1 * V_2 )
{
struct V_5 * V_4 = V_2 -> V_4 ;
struct V_6 * V_8 ;
struct V_6 * V_117 ;
struct V_22 * V_23 ;
int V_24 ;
unsigned int V_70 ;
V_24 = 0 ;
V_23 = F_16 ( & V_2 -> V_2 ) ;
V_70 = V_23 -> V_70 - V_4 -> V_133 ;
V_8 = F_4 ( V_2 ) ;
V_117 = F_4 ( V_4 -> V_2 [ 0 ] ) ;
if ( V_4 -> V_142 )
F_60 ( V_2 -> V_124 ) ;
if ( V_4 -> V_147 )
F_60 ( V_2 -> V_19 ) ;
if ( V_4 -> V_25 )
F_57 ( V_23 , V_8 ) ;
F_18 ( V_23 ) ;
V_24 = F_38 ( V_4 , V_70 ) ;
if ( V_24 < 0 )
F_15 ( & V_2 -> V_25 ,
L_33 ,
V_31 , V_2 -> V_127 ) ;
V_117 -> V_126 -- ;
F_15 ( & V_2 -> V_25 , L_34 ,
V_117 -> V_126 , V_2 -> V_127 ) ;
if ( V_117 -> V_126 == 0 ) {
if ( V_4 -> V_2 [ 0 ] -> V_118 ) {
F_15 ( & V_2 -> V_25 , L_35 ) ;
F_61 ( V_4 -> V_2 [ 0 ] -> V_118 ) ;
}
}
if ( V_8 -> V_124 ) {
F_32 ( V_8 -> V_124 -> V_29 ) ;
F_62 ( V_8 -> V_124 ) ;
}
}
static int F_63 ( struct V_22 * V_23 , struct V_1 * V_2 ,
const unsigned char * V_148 , int V_146 )
{
int V_32 ;
struct V_5 * V_4 = F_8 ( V_2 , V_31 ) ;
if ( V_4 == NULL )
return - V_123 ;
if ( V_146 == 0 ) {
F_15 ( & V_2 -> V_25 ,
L_36 , V_31 ) ;
return 0 ;
}
if ( V_4 -> V_142 ) {
if ( V_2 -> V_124 -> V_24 == - V_143 ) {
F_15 ( & V_2 -> V_25 , L_37 , V_31 ) ;
return 0 ;
}
V_146 =
( V_146 > V_2 -> V_149 ) ? V_2 -> V_149 : V_146 ;
memcpy ( V_2 -> V_124 -> V_29 , V_148 , V_146 ) ;
F_23 ( V_2 -> V_124 , V_4 -> V_25 ,
F_64 ( V_4 -> V_25 ,
V_2 ->
V_134 ) ,
V_2 -> V_124 -> V_29 , V_146 ,
F_14 , V_2 ) ;
V_32 = F_25 ( V_2 -> V_124 , V_38 ) ;
if ( V_32 )
F_15 ( & V_2 -> V_25 ,
L_38 ,
V_31 , V_32 ) ;
else
V_32 = V_146 ;
return V_32 ;
}
return 0 ;
}
static int F_65 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = V_23 -> V_140 ;
struct V_5 * V_4 ;
struct V_6 * V_8 ;
int V_150 = - V_151 ;
if ( F_1 ( V_2 , V_31 ) )
return - 1 ;
V_4 = F_8 ( V_2 , V_31 ) ;
if ( ! V_4 )
return - V_123 ;
V_8 = F_4 ( V_2 ) ;
F_66 ( & V_8 -> V_86 ) ;
if ( V_4 -> V_142 ) {
if ( V_2 -> V_124 -> V_24 != - V_143 )
V_150 = V_2 -> V_149 ;
}
F_67 ( & V_8 -> V_86 ) ;
return V_150 ;
}
static int F_68 ( struct V_22 * V_23 ,
unsigned int V_152 , unsigned long V_153 )
{
struct V_1 * V_2 = V_23 -> V_140 ;
struct V_6 * V_8 = F_4 ( V_2 ) ;
struct V_5 * V_4 = F_8 ( V_2 , V_31 ) ;
unsigned int V_70 ;
F_15 ( & V_2 -> V_25 , L_39 , V_31 , V_152 ) ;
V_70 = V_23 -> V_70 - V_4 -> V_133 ;
if ( V_152 == V_154 ) {
while ( V_8 != NULL ) {
F_69 ( & V_8 -> V_138 ) ;
if ( F_70 ( V_155 ) )
return - V_156 ;
else {
char V_157 = V_8 -> V_158 ;
if ( V_157 == 0 )
return - V_116 ;
V_8 -> V_158 = 0 ;
if ( ( ( V_153 & V_159 )
&& ( V_157 & V_129 ) )
|| ( ( V_153 & V_160 )
&& ( V_157 & V_128 ) )
|| ( ( V_153 & V_161 )
&& ( V_157 & V_130 ) )
|| ( ( V_153 & V_162 )
&& ( V_157 & V_76 ) ) ) {
return 0 ;
}
}
}
return 0 ;
}
F_15 ( & V_2 -> V_25 , L_40 ,
V_31 , V_2 -> V_127 ) ;
return - V_163 ;
}
static void F_71 ( struct V_22 * V_23 ,
struct V_1 * V_2 ,
struct V_164 * V_165 )
{
struct V_164 * V_166 = & V_23 -> V_166 ;
unsigned char V_167 = 0 ;
unsigned int V_168 = V_166 -> V_169 ;
unsigned int V_70 ;
int V_170 , V_171 , V_172 ;
int V_24 ;
V_70 = V_23 -> V_70 - V_2 -> V_4 -> V_133 ;
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
F_15 ( & V_2 -> V_25 , L_41 , V_31 ) ;
V_170 = F_72 ( V_23 ) ;
if ( ! V_170 )
V_170 = 9600 ;
F_15 ( & V_2 -> V_25 , L_42 , V_31 , V_170 ) ;
V_171 = V_189 / V_170 ;
V_172 = V_189 % V_170 ;
if ( ( ( V_172 * 2 ) >= V_170 ) && ( V_170 != 110 ) )
V_171 ++ ;
V_24 =
F_41 ( V_2 -> V_4 , V_70 , ( unsigned short ) V_171 , V_167 ) ;
if ( V_24 < 0 ) {
F_15 ( & V_2 -> V_25 , L_22 ) ;
return;
}
if ( V_168 & V_190 ) {
F_15 ( & V_2 -> V_25 , L_43 ,
V_31 , V_2 -> V_127 ) ;
V_24 = F_42 ( V_2 -> V_4 , V_70 , 1 ) ;
if ( V_24 < 0 ) {
F_15 ( & V_2 -> V_25 , L_44 ) ;
return;
}
} else {
F_15 ( & V_2 -> V_25 ,
L_45 ,
V_31 , V_2 -> V_127 ) ;
V_24 = F_42 ( V_2 -> V_4 , V_70 , 0 ) ;
if ( V_24 < 0 ) {
F_15 ( & V_2 -> V_25 , L_44 ) ;
return;
}
}
if ( F_73 ( V_23 ) || F_74 ( V_23 ) ) {
unsigned char V_78 = F_75 ( V_23 ) ;
unsigned char V_79 = F_76 ( V_23 ) ;
V_24 =
F_43 ( V_2 -> V_4 , V_70 , V_78 ,
V_79 ) ;
if ( V_24 < 0 )
F_15 ( & V_2 -> V_25 ,
L_46 ) ;
} else {
V_24 = F_44 ( V_2 -> V_4 , V_70 ) ;
if ( V_24 < 0 )
F_15 ( & V_2 -> V_25 ,
L_47 ) ;
}
V_166 -> V_169 &= ~ V_191 ;
}
static void F_77 ( struct V_22 * V_23 , int V_192 )
{
struct V_1 * V_2 = V_23 -> V_140 ;
struct V_5 * V_4 = F_8 ( V_2 , V_31 ) ;
struct V_6 * V_8 ;
T_3 V_70 , V_193 ;
unsigned int V_32 ;
V_70 = V_23 -> V_70 - V_4 -> V_133 ;
V_8 = F_4 ( V_2 ) ;
if ( V_192 == - 1 )
V_193 = 1 ;
else
V_193 = 0 ;
F_66 ( & V_8 -> V_86 ) ;
V_32 =
F_30 ( V_4 -> V_25 , F_34 ( V_4 -> V_25 , 0 ) ,
V_194 , 0x40 , V_193 , V_70 , NULL , 0 , 300 ) ;
F_67 ( & V_8 -> V_86 ) ;
}
static inline int F_78 ( struct V_22 * V_23 ,
struct V_1 * V_2 ,
struct V_5 * V_4 )
{
T_4 V_72 ;
T_4 V_73 ;
unsigned int V_32 = 0 ;
int V_24 ;
unsigned int V_70 ;
V_70 = V_23 -> V_70 - V_4 -> V_133 ;
V_24 =
F_39 ( V_2 -> V_4 , V_70 , V_195 , & V_72 ) ;
if ( V_24 >= 0 ) {
V_24 =
F_39 ( V_2 -> V_4 , V_70 ,
V_196 , & V_73 ) ;
}
if ( V_24 >= 0 ) {
V_32 = ( ( V_72 & V_197 ) ? V_198 : 0 )
| ( ( V_72 & V_75 ) ? V_199 : 0 )
| ( ( V_73 & V_76 ) ? V_162 : 0 )
| ( ( V_73 & V_130 ) ? V_200 : 0 )
| ( ( V_73 & V_129 ) ? V_201 : 0 )
| ( ( V_73 & V_128 ) ? V_160 : 0 ) ;
return V_32 ;
} else
return - V_202 ;
}
static inline int F_79 ( struct V_22 * V_23 ,
struct V_1 * V_2 ,
struct V_5 * V_4 ,
unsigned int V_203 )
{
T_4 V_72 ;
int V_24 ;
unsigned int V_70 ;
V_70 = V_23 -> V_70 - V_4 -> V_133 ;
V_24 =
F_39 ( V_2 -> V_4 , V_70 , V_195 , & V_72 ) ;
if ( V_24 < 0 )
return - V_202 ;
V_72 &= ~ ( V_75 | V_197 | V_204 ) ;
if ( V_203 & V_199 )
V_72 |= V_75 ;
if ( V_203 & V_198 )
V_72 |= V_197 ;
if ( V_203 & V_205 )
V_72 |= V_204 ;
V_24 =
F_40 ( V_2 -> V_4 , V_70 , V_195 , V_72 ) ;
if ( V_24 < 0 )
return - V_202 ;
else
return 0 ;
}
static int F_80 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = V_23 -> V_140 ;
struct V_5 * V_4 = F_8 ( V_2 , V_31 ) ;
struct V_6 * V_8 = F_4 ( V_2 ) ;
int V_150 ;
if ( ! V_4 )
return - V_123 ;
F_66 ( & V_8 -> V_86 ) ;
V_150 = F_78 ( V_23 , V_2 , V_4 ) ;
F_67 ( & V_8 -> V_86 ) ;
return V_150 ;
}
static int F_81 ( struct V_22 * V_23 ,
unsigned int V_206 , unsigned int V_207 )
{
struct V_1 * V_2 = V_23 -> V_140 ;
struct V_5 * V_4 = F_8 ( V_2 , V_31 ) ;
struct V_6 * V_8 = F_4 ( V_2 ) ;
int V_150 ;
if ( ! V_4 )
return - V_123 ;
F_66 ( & V_8 -> V_86 ) ;
V_150 = F_79 ( V_23 , V_2 , V_4 , V_206 ) ;
F_67 ( & V_8 -> V_86 ) ;
return V_150 ;
}
static void F_82 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = V_23 -> V_140 ;
struct V_5 * V_4 = F_8 ( V_2 , V_31 ) ;
struct V_6 * V_8 ;
if ( ! V_4 )
return;
V_8 = F_4 ( V_2 ) ;
F_66 ( & V_8 -> V_86 ) ;
V_8 -> V_34 = 1 ;
F_67 ( & V_8 -> V_86 ) ;
}
static void F_83 ( struct V_1 * V_2 ,
struct V_5 * V_4 )
{
int V_32 ;
F_23 ( V_2 -> V_19 , V_4 -> V_25 ,
F_24 ( V_4 -> V_25 ,
V_2 -> V_36 ) ,
V_2 -> V_19 -> V_29 ,
V_2 -> V_19 -> V_37 ,
F_22 , V_2 ) ;
V_32 = F_25 ( V_2 -> V_19 , V_38 ) ;
if ( V_32 )
F_52 ( & V_2 -> V_25 ,
L_48 ,
V_31 , V_32 ) ;
}
static void F_84 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = V_23 -> V_140 ;
struct V_5 * V_4 = F_8 ( V_2 , V_31 ) ;
struct V_6 * V_8 ;
if ( ! V_4 )
return;
V_8 = F_4 ( V_2 ) ;
F_66 ( & V_8 -> V_86 ) ;
if ( V_8 -> V_34 == 1 ) {
F_15 ( & V_2 -> V_25 , L_49 , V_31 ) ;
V_8 -> V_34 = 0 ;
F_15 ( & V_2 -> V_25 , L_50 , V_31 ) ;
if ( ( V_4 -> V_147 ) && ( V_8 -> V_33 == 1 ) )
F_83 ( V_2 , V_4 ) ;
}
F_67 ( & V_8 -> V_86 ) ;
}
static int F_85 ( struct V_5 * V_4 )
{
int V_85 ;
V_85 =
( V_4 -> V_208 -> V_209 -> V_210 . V_211 - 1 ) / 2 ;
return V_85 ;
}
