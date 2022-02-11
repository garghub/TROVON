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
struct V_38 V_39 ;
int V_26 ;
int V_22 ;
for ( V_26 = 0 ; V_26 < V_4 -> V_82 ; V_26 ++ ) {
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
F_45 ( & V_8 -> V_83 ) ;
F_7 ( V_2 , V_8 ) ;
}
V_22 = F_26 ( V_4 , & V_39 ) ;
if ( V_22 < 0 )
goto V_84;
F_15 ( V_23 , L_13 , V_39 . V_50 ) ;
V_39 . V_50 &= ~ V_85 ;
F_15 ( V_23 , L_14 , V_39 . V_50 ) ;
V_22 = F_34 ( V_4 , & V_39 ) ;
if ( V_22 < 0 ) {
F_15 ( V_23 , L_15 ) ;
goto V_84;
}
V_22 = F_26 ( V_4 , & V_39 ) ;
if ( V_22 < 0 ) {
F_15 ( V_23 , L_16 ) ;
goto V_84;
}
switch ( V_4 -> V_23 -> V_86 . V_87 ) {
case V_88 :
case V_89 :
case V_90 :
case V_91 :
case V_92 :
case V_93 :
case V_94 :
case V_95 :
V_39 . V_51 &= ~ ( V_96 | V_97 ) ;
V_39 . V_51 |= V_98 ;
V_39 . V_50 &= ~ ( V_99 ) ;
V_39 . V_50 |= V_100 ;
break;
case V_101 :
case V_102 :
case V_103 :
case V_104 :
case V_105 :
case V_106 :
case V_107 :
case V_108 :
case V_109 :
V_39 . V_51 &= ~ ( V_96 | V_97 ) ;
V_39 . V_51 |= V_98 ;
V_39 . V_50 &= ~ ( V_99 ) ;
V_39 . V_50 |= V_110 ;
break;
default:
V_39 . V_51 &= ~ ( V_96 | V_97 ) ;
V_39 . V_51 |= V_98 ;
V_39 . V_50 &= ~ ( V_99 ) ;
V_39 . V_50 |= V_100 ;
break;
}
V_22 = F_31 ( V_4 ) ;
if ( V_22 < 0 ) {
F_15 ( V_23 , L_17 ) ;
goto V_84;
}
V_22 = F_33 ( V_4 , V_111 ) ;
if ( V_22 < 0 ) {
F_15 ( V_23 , L_18 ) ;
goto V_84;
}
F_15 ( V_23 , L_13 , V_39 . V_50 ) ;
V_39 . V_50 |= V_112 ;
F_15 ( V_23 , L_14 , V_39 . V_50 ) ;
V_22 = F_34 ( V_4 , & V_39 ) ;
if ( V_22 < 0 ) {
F_15 ( V_23 , L_15 ) ;
goto V_84;
}
return 0 ;
V_84:
for ( V_26 = 0 ; V_26 < V_4 -> V_82 ; V_26 ++ ) {
V_2 = V_4 -> V_2 [ V_26 ] ;
V_8 = F_4 ( V_2 ) ;
F_30 ( V_8 ) ;
F_7 ( V_2 , NULL ) ;
}
return - V_113 ;
}
static void F_46 ( struct V_5 * V_4 )
{
struct V_1 * V_2 ;
struct V_6 * V_8 ;
int V_26 ;
for ( V_26 = 0 ; V_26 < V_4 -> V_82 ; V_26 ++ ) {
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
struct V_1 * V_114 = V_4 -> V_2 [ 0 ] ;
F_48 ( V_114 -> V_115 ,
V_4 -> V_23 ,
F_49 ( V_4 -> V_23 ,
V_114 -> V_116 ) ,
V_114 -> V_117 ,
V_114 -> V_115 -> V_35 ,
F_17 , V_4 ,
V_114 -> V_115 -> V_118 ) ;
V_30 = F_23 ( V_114 -> V_115 ,
V_40 ) ;
if ( V_30 ) {
F_50 ( & V_2 -> V_23 ,
L_19 ,
V_29 , V_30 ) ;
}
}
static int F_51 ( struct V_119 * V_120 ,
struct V_1 * V_2 )
{
struct V_5 * V_4 ;
struct V_6 * V_6 ;
struct V_6 * V_114 ;
struct V_53 V_121 ;
int V_30 ;
if ( F_1 ( V_2 , V_29 ) )
return - V_122 ;
V_4 = V_2 -> V_4 ;
if ( F_3 ( V_4 , V_29 ) )
return - V_122 ;
V_6 = F_4 ( V_2 ) ;
V_114 = F_4 ( V_4 -> V_2 [ 0 ] ) ;
if ( V_6 == NULL || V_114 == NULL )
return - V_122 ;
F_52 ( V_4 -> V_23 , V_2 -> V_123 -> V_124 ) ;
F_52 ( V_4 -> V_23 , V_2 -> V_19 -> V_124 ) ;
V_114 -> V_125 ++ ;
V_30 = F_26 ( V_4 , & V_114 -> V_39 ) ;
V_30 = F_35 ( V_4 , V_2 -> V_126 , & V_121 ) ;
if ( V_30 < 0 ) {
F_15 ( & V_2 -> V_23 , L_20 ) ;
return V_30 ;
}
F_15 ( & V_2 -> V_23 , L_21 ) ;
V_6 -> V_10 = V_121 . V_9 &
( V_11 | V_12 | V_13 | V_14 ) ;
V_6 -> V_16 = V_121 . V_15 &
( V_74 | V_127 | V_128 | V_129 ) ;
V_30 = F_39 ( V_4 , V_2 -> V_126 , V_130 , V_131 ) ;
if ( V_30 < 0 ) {
F_15 ( & V_2 -> V_23 , L_22 ) ;
return V_30 ;
}
F_15 ( & V_2 -> V_23 , L_23 ) ;
if ( V_114 -> V_125 == 1 ) {
if ( V_4 -> V_2 [ 0 ] -> V_117 == NULL )
F_47 ( V_4 , V_2 ) ;
}
F_15 ( & V_2 -> V_23 , L_24 , V_2 -> V_132 ) ;
F_15 ( & V_2 -> V_23 ,
L_25 , V_2 -> V_34 ) ;
F_15 ( & V_2 -> V_23 ,
L_26 , V_2 -> V_133 ) ;
F_15 ( & V_2 -> V_23 , L_27 ,
V_2 -> V_116 ) ;
F_15 ( & V_2 -> V_23 , L_28 ,
V_6 -> V_134 ) ;
V_6 -> V_19 = V_2 -> V_19 ;
F_21 ( V_6 -> V_19 ,
V_4 -> V_23 ,
F_22 ( V_4 -> V_23 ,
V_2 -> V_34 ) ,
V_2 -> V_135 ,
V_6 -> V_19 -> V_35 ,
F_20 , V_6 ) ;
F_15 ( & V_2 -> V_23 , L_29 ,
V_2 -> V_34 ) ;
V_6 -> V_136 = true ;
V_30 = F_23 ( V_6 -> V_19 , V_40 ) ;
if ( V_30 ) {
F_50 ( & V_2 -> V_23 ,
L_30 ,
V_29 , V_30 ) ;
V_6 -> V_136 = false ;
}
F_53 ( & V_6 -> V_17 ) ;
F_53 ( & V_6 -> V_137 ) ;
memset ( & ( V_6 -> V_138 ) , 0x00 , sizeof( V_6 -> V_138 ) ) ;
return 0 ;
}
static int F_54 ( struct V_119 * V_120 )
{
struct V_1 * V_2 = V_120 -> V_139 ;
struct V_5 * V_4 ;
int V_140 = 0 ;
V_4 = F_8 ( V_2 , V_29 ) ;
if ( V_4 -> V_141 ) {
if ( V_2 -> V_123 -> V_22 == - V_142 )
V_140 = V_2 -> V_123 -> V_35 ;
}
return V_140 ;
}
static void F_55 ( struct V_119 * V_120 ,
struct V_6 * V_8 )
{
int V_143 = V_144 / 10 ;
int V_17 = 30 ;
int V_145 ;
while ( 1 ) {
V_145 = F_54 ( V_120 ) ;
if ( V_145 <= 0 )
return;
F_56 ( & V_8 -> V_17 , V_143 ) ;
V_17 -- ;
if ( V_17 == 0 ) {
F_15 ( & V_8 -> V_2 -> V_23 , L_31 , V_29 ) ;
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
struct V_6 * V_114 ;
struct V_119 * V_120 ;
int V_22 ;
unsigned int V_68 ;
V_22 = 0 ;
V_120 = F_58 ( & V_2 -> V_2 ) ;
V_68 = V_2 -> V_126 ;
V_8 = F_4 ( V_2 ) ;
V_114 = F_4 ( V_4 -> V_2 [ 0 ] ) ;
if ( V_4 -> V_141 )
F_59 ( V_2 -> V_123 ) ;
if ( V_4 -> V_146 )
F_59 ( V_2 -> V_19 ) ;
if ( V_4 -> V_23 )
F_55 ( V_120 , V_8 ) ;
F_60 ( V_120 ) ;
V_22 = F_36 ( V_4 , V_68 ) ;
if ( V_22 < 0 )
F_15 ( & V_2 -> V_23 , L_32 , V_29 ) ;
V_114 -> V_125 -- ;
F_15 ( & V_2 -> V_23 , L_33 , V_114 -> V_125 ) ;
if ( V_114 -> V_125 == 0 ) {
if ( V_4 -> V_2 [ 0 ] -> V_115 ) {
F_15 ( & V_2 -> V_23 , L_34 ) ;
F_61 ( V_4 -> V_2 [ 0 ] -> V_115 ) ;
}
}
if ( V_8 -> V_123 ) {
F_30 ( V_8 -> V_123 -> V_27 ) ;
F_62 ( V_8 -> V_123 ) ;
}
}
static int F_63 ( struct V_119 * V_120 , struct V_1 * V_2 ,
const unsigned char * V_147 , int V_145 )
{
int V_30 ;
struct V_5 * V_4 = F_8 ( V_2 , V_29 ) ;
if ( V_4 == NULL )
return - V_122 ;
if ( V_145 == 0 ) {
F_15 ( & V_2 -> V_23 ,
L_35 , V_29 ) ;
return 0 ;
}
if ( V_4 -> V_141 ) {
if ( V_2 -> V_123 -> V_22 == - V_142 ) {
F_15 ( & V_2 -> V_23 , L_36 , V_29 ) ;
return 0 ;
}
V_145 =
( V_145 > V_2 -> V_148 ) ? V_2 -> V_148 : V_145 ;
memcpy ( V_2 -> V_123 -> V_27 , V_147 , V_145 ) ;
F_21 ( V_2 -> V_123 , V_4 -> V_23 ,
F_64 ( V_4 -> V_23 ,
V_2 ->
V_133 ) ,
V_2 -> V_123 -> V_27 , V_145 ,
F_14 , V_2 ) ;
V_30 = F_23 ( V_2 -> V_123 , V_36 ) ;
if ( V_30 )
F_15 ( & V_2 -> V_23 ,
L_37 ,
V_29 , V_30 ) ;
else
V_30 = V_145 ;
return V_30 ;
}
return 0 ;
}
static int F_65 ( struct V_119 * V_120 )
{
struct V_1 * V_2 = V_120 -> V_139 ;
struct V_5 * V_4 ;
struct V_6 * V_8 ;
int V_149 = - V_150 ;
if ( F_1 ( V_2 , V_29 ) )
return - 1 ;
V_4 = F_8 ( V_2 , V_29 ) ;
if ( ! V_4 )
return - V_122 ;
V_8 = F_4 ( V_2 ) ;
F_66 ( & V_8 -> V_83 ) ;
if ( V_4 -> V_141 ) {
if ( V_2 -> V_123 -> V_22 != - V_142 )
V_149 = V_2 -> V_148 ;
}
F_67 ( & V_8 -> V_83 ) ;
return V_149 ;
}
static int F_68 ( struct V_119 * V_120 ,
unsigned int V_151 , unsigned long V_152 )
{
struct V_1 * V_2 = V_120 -> V_139 ;
struct V_6 * V_8 = F_4 ( V_2 ) ;
unsigned int V_68 ;
F_15 ( & V_2 -> V_23 , L_38 , V_29 , V_151 ) ;
V_68 = V_2 -> V_126 ;
if ( V_151 == V_153 ) {
while ( V_8 != NULL ) {
F_69 ( & V_8 -> V_137 ) ;
if ( F_70 ( V_154 ) )
return - V_155 ;
else {
char V_156 = V_8 -> V_157 ;
if ( V_156 == 0 )
return - V_113 ;
V_8 -> V_157 = 0 ;
if ( ( ( V_152 & V_158 )
&& ( V_156 & V_128 ) )
|| ( ( V_152 & V_159 )
&& ( V_156 & V_127 ) )
|| ( ( V_152 & V_160 )
&& ( V_156 & V_129 ) )
|| ( ( V_152 & V_161 )
&& ( V_156 & V_74 ) ) ) {
return 0 ;
}
}
}
return 0 ;
}
F_15 ( & V_2 -> V_23 , L_39 , V_29 ) ;
return - V_162 ;
}
static void F_71 ( struct V_119 * V_120 ,
struct V_1 * V_2 ,
struct V_163 * V_164 )
{
struct V_163 * V_165 = & V_120 -> V_165 ;
unsigned char V_166 = 0 ;
unsigned int V_167 = V_165 -> V_168 ;
unsigned int V_68 ;
int V_169 , V_170 , V_171 ;
int V_22 ;
V_68 = V_2 -> V_126 ;
switch ( V_167 & V_172 ) {
case V_173 :
V_166 |= V_174 ;
break;
case V_175 :
V_166 |= V_176 ;
break;
case V_177 :
V_166 |= V_178 ;
break;
default:
V_165 -> V_168 &= ~ V_172 ;
V_165 -> V_168 |= V_179 ;
case V_179 :
V_166 |= V_180 ;
break;
}
if ( V_167 & V_181 ) {
if ( V_167 & V_182 )
V_166 |= V_183 ;
else
V_166 |= V_184 ;
}
if ( V_167 & V_185 )
V_166 |= V_186 ;
else
V_166 |= V_187 ;
F_15 ( & V_2 -> V_23 , L_40 , V_29 ) ;
V_169 = F_72 ( V_120 ) ;
if ( ! V_169 )
V_169 = 9600 ;
F_15 ( & V_2 -> V_23 , L_41 , V_29 , V_169 ) ;
V_170 = V_188 / V_169 ;
V_171 = V_188 % V_169 ;
if ( ( ( V_171 * 2 ) >= V_169 ) && ( V_169 != 110 ) )
V_170 ++ ;
V_22 =
F_39 ( V_2 -> V_4 , V_68 , ( unsigned short ) V_170 , V_166 ) ;
if ( V_22 < 0 ) {
F_15 ( & V_2 -> V_23 , L_22 ) ;
return;
}
if ( V_167 & V_189 ) {
F_15 ( & V_2 -> V_23 , L_42 , V_29 ) ;
V_22 = F_40 ( V_2 -> V_4 , V_68 , 1 ) ;
if ( V_22 < 0 ) {
F_15 ( & V_2 -> V_23 , L_43 ) ;
return;
}
} else {
F_15 ( & V_2 -> V_23 ,
L_44 , V_29 ) ;
V_22 = F_40 ( V_2 -> V_4 , V_68 , 0 ) ;
if ( V_22 < 0 ) {
F_15 ( & V_2 -> V_23 , L_43 ) ;
return;
}
}
if ( F_73 ( V_120 ) || F_74 ( V_120 ) ) {
unsigned char V_76 = F_75 ( V_120 ) ;
unsigned char V_77 = F_76 ( V_120 ) ;
V_22 =
F_41 ( V_2 -> V_4 , V_68 , V_76 ,
V_77 ) ;
if ( V_22 < 0 )
F_15 ( & V_2 -> V_23 ,
L_45 ) ;
} else {
V_22 = F_42 ( V_2 -> V_4 , V_68 ) ;
if ( V_22 < 0 )
F_15 ( & V_2 -> V_23 ,
L_46 ) ;
}
V_165 -> V_168 &= ~ V_190 ;
}
static void F_77 ( struct V_119 * V_120 , int V_191 )
{
struct V_1 * V_2 = V_120 -> V_139 ;
struct V_5 * V_4 = F_8 ( V_2 , V_29 ) ;
struct V_6 * V_8 ;
T_3 V_68 , V_192 ;
unsigned int V_30 ;
V_68 = V_2 -> V_126 ;
V_8 = F_4 ( V_2 ) ;
if ( V_191 == - 1 )
V_192 = 1 ;
else
V_192 = 0 ;
F_66 ( & V_8 -> V_83 ) ;
V_30 =
F_28 ( V_4 -> V_23 , F_32 ( V_4 -> V_23 , 0 ) ,
V_193 , 0x40 , V_192 , V_68 , NULL , 0 , 300 ) ;
F_67 ( & V_8 -> V_83 ) ;
}
static inline int F_78 ( struct V_119 * V_120 ,
struct V_1 * V_2 ,
struct V_5 * V_4 )
{
T_4 V_70 ;
T_4 V_71 ;
unsigned int V_30 = 0 ;
int V_22 ;
unsigned int V_68 ;
V_68 = V_2 -> V_126 ;
V_22 =
F_37 ( V_2 -> V_4 , V_68 , V_194 , & V_70 ) ;
if ( V_22 >= 0 ) {
V_22 =
F_37 ( V_2 -> V_4 , V_68 ,
V_195 , & V_71 ) ;
}
if ( V_22 >= 0 ) {
V_30 = ( ( V_70 & V_196 ) ? V_197 : 0 )
| ( ( V_70 & V_73 ) ? V_198 : 0 )
| ( ( V_71 & V_74 ) ? V_161 : 0 )
| ( ( V_71 & V_129 ) ? V_199 : 0 )
| ( ( V_71 & V_128 ) ? V_200 : 0 )
| ( ( V_71 & V_127 ) ? V_159 : 0 ) ;
return V_30 ;
} else
return - V_201 ;
}
static inline int F_79 ( struct V_119 * V_120 ,
struct V_1 * V_2 ,
struct V_5 * V_4 ,
unsigned int V_62 )
{
T_4 V_70 ;
int V_22 ;
unsigned int V_68 ;
V_68 = V_2 -> V_126 ;
V_22 =
F_37 ( V_2 -> V_4 , V_68 , V_194 , & V_70 ) ;
if ( V_22 < 0 )
return - V_201 ;
V_70 &= ~ ( V_73 | V_196 | V_202 ) ;
if ( V_62 & V_198 )
V_70 |= V_73 ;
if ( V_62 & V_197 )
V_70 |= V_196 ;
if ( V_62 & V_203 )
V_70 |= V_202 ;
V_22 =
F_38 ( V_2 -> V_4 , V_68 , V_194 , V_70 ) ;
if ( V_22 < 0 )
return - V_201 ;
else
return 0 ;
}
static int F_80 ( struct V_119 * V_120 )
{
struct V_1 * V_2 = V_120 -> V_139 ;
struct V_5 * V_4 = F_8 ( V_2 , V_29 ) ;
struct V_6 * V_8 = F_4 ( V_2 ) ;
int V_149 ;
if ( ! V_4 )
return - V_122 ;
F_66 ( & V_8 -> V_83 ) ;
V_149 = F_78 ( V_120 , V_2 , V_4 ) ;
F_67 ( & V_8 -> V_83 ) ;
return V_149 ;
}
static int F_81 ( struct V_119 * V_120 ,
unsigned int V_204 , unsigned int V_205 )
{
struct V_1 * V_2 = V_120 -> V_139 ;
struct V_5 * V_4 = F_8 ( V_2 , V_29 ) ;
struct V_6 * V_8 = F_4 ( V_2 ) ;
int V_149 ;
if ( ! V_4 )
return - V_122 ;
F_66 ( & V_8 -> V_83 ) ;
V_149 = F_79 ( V_120 , V_2 , V_4 , V_204 ) ;
F_67 ( & V_8 -> V_83 ) ;
return V_149 ;
}
static void F_82 ( struct V_119 * V_120 )
{
struct V_1 * V_2 = V_120 -> V_139 ;
struct V_5 * V_4 = F_8 ( V_2 , V_29 ) ;
struct V_6 * V_8 ;
if ( ! V_4 )
return;
V_8 = F_4 ( V_2 ) ;
F_66 ( & V_8 -> V_83 ) ;
V_8 -> V_32 = 1 ;
F_67 ( & V_8 -> V_83 ) ;
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
L_47 ,
V_29 , V_30 ) ;
}
static void F_84 ( struct V_119 * V_120 )
{
struct V_1 * V_2 = V_120 -> V_139 ;
struct V_5 * V_4 = F_8 ( V_2 , V_29 ) ;
struct V_6 * V_8 ;
if ( ! V_4 )
return;
V_8 = F_4 ( V_2 ) ;
F_66 ( & V_8 -> V_83 ) ;
if ( V_8 -> V_32 == 1 ) {
F_15 ( & V_2 -> V_23 , L_48 , V_29 ) ;
V_8 -> V_32 = 0 ;
F_15 ( & V_2 -> V_23 , L_49 , V_29 ) ;
if ( ( V_4 -> V_146 ) && ( V_8 -> V_31 == 1 ) )
F_83 ( V_2 , V_4 ) ;
}
F_67 ( & V_8 -> V_83 ) ;
}
static int F_85 ( struct V_5 * V_4 )
{
int V_82 ;
V_82 =
( V_4 -> V_206 -> V_207 -> V_208 . V_209 - 1 ) / 2 ;
return V_82 ;
}
