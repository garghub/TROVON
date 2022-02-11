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
return;
}
static void F_10 ( struct V_6 * V_8 ,
unsigned char V_15 )
{
V_8 -> V_16 = V_15 ;
F_11 ( & V_8 -> V_17 ) ;
return;
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
F_2 ( L_5 , V_24 ) ;
return;
}
V_6 = V_20 -> V_25 ;
F_2 ( L_6 , V_26 , V_6 -> V_27 ) ;
V_19 = F_15 ( & V_6 -> V_2 -> V_2 ) ;
if ( V_19 )
F_16 ( V_19 ) ;
F_17 ( V_19 ) ;
}
static void F_18 ( struct V_20 * V_20 )
{
}
static void F_19 ( struct V_20 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_25 ;
struct V_5 * V_4 = F_8 ( V_2 , V_26 ) ;
struct V_6 * V_8 = F_4 ( V_2 ) ;
unsigned char * V_7 ;
struct V_18 * V_19 ;
unsigned int V_28 ;
unsigned int V_29 ;
int V_30 , V_31 ;
int V_32 , V_33 ;
if ( V_20 -> V_24 ) {
V_8 -> V_34 = 1 ;
F_2 ( L_7 ,
V_26 , V_20 -> V_24 ) ;
return;
}
V_19 = F_15 ( & V_2 -> V_2 ) ;
if ( ! V_19 ) {
F_2 ( L_8 , V_26 ) ;
return;
}
V_7 = V_20 -> V_35 ;
V_29 = V_20 -> V_22 ;
V_28 = V_19 -> V_28 - V_4 -> V_36 ;
F_2 ( L_6 , V_26 , V_2 -> V_37 ) ;
F_2 ( L_9 , V_26 , V_8 -> V_38 ) ;
if ( F_1 ( V_2 , V_26 ) != 0 ) {
F_2 ( L_10 , V_26 ) ;
V_8 -> V_34 = 1 ;
goto exit;
}
if ( ! V_4 ) {
F_2 ( L_11 , V_26 ) ;
goto exit;
}
if ( V_8 -> V_39 == 1 ) {
F_2 ( L_12 , V_26 ) ;
V_8 -> V_34 = 1 ;
goto exit;
}
if ( V_8 -> V_38 == 1 ) {
V_8 -> V_34 = 1 ;
goto exit;
}
if ( V_20 -> V_24 ) {
V_8 -> V_34 = 1 ;
F_2 ( L_13 ,
V_26 , V_20 -> V_24 ) ;
goto exit;
}
if ( V_19 && V_29 ) {
V_33 = 0 ;
for ( V_30 = 0 ; V_30 < V_29 ; ++ V_30 ) {
if ( ( V_30 <= ( V_29 - 3 ) ) && ( V_7 [ V_30 ] == 0x1b )
&& ( V_7 [ V_30 + 1 ] == 0x1b ) ) {
V_32 = 0 ;
switch ( V_7 [ V_30 + 2 ] ) {
case 0x00 :
if ( V_30 > ( V_29 - 4 ) ) {
F_2 ( L_14 ) ;
break;
}
F_9 ( V_8 , V_7 [ V_30 + 3 ] ) ;
V_30 += 3 ;
V_32 = 1 ;
break;
case 0x01 :
F_2 ( L_15 ) ;
if ( V_30 > ( V_29 - 4 ) ) {
F_2 ( L_16 ) ;
break;
}
F_10 ( V_8 ,
V_7 [ V_30 + 3 ] ) ;
V_30 += 3 ;
V_32 = 1 ;
break;
case 0xff :
F_2 ( L_17 ) ;
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
F_20 ( V_19 ) ;
}
F_21 ( V_2 -> V_21 , V_4 -> V_40 ,
F_22 ( V_4 -> V_40 ,
V_2 -> V_41 ) ,
V_2 -> V_21 -> V_35 ,
V_2 -> V_21 -> V_42 ,
F_19 , V_2 ) ;
V_31 = F_23 ( V_2 -> V_21 , V_43 ) ;
if ( V_31 )
F_2 ( L_18 ,
V_26 , V_31 ) ;
else {
if ( V_19 && V_29 ) {
F_20 ( V_19 ) ;
F_24 ( V_19 ) ;
}
}
F_25 ( & V_2 -> V_44 ) ;
exit:
F_17 ( V_19 ) ;
}
static int F_26 ( struct V_5 * V_4 ,
struct V_45 * V_46 )
{
int V_31 ;
unsigned char * V_35 ;
V_35 =
F_27 ( sizeof( struct V_45 ) , V_47 ) ;
if ( ! V_35 )
return - V_48 ;
V_31 = F_28 ( V_4 -> V_40 , F_29 ( V_4 -> V_40 , 0 ) ,
V_49 , 0xc0 , 0 , 0 ,
V_35 ,
sizeof( struct V_45 ) , 300 ) ;
if ( V_31 > 0 )
memcpy ( V_46 , V_35 ,
sizeof( struct V_45 ) ) ;
F_30 ( V_35 ) ;
return V_31 ;
}
static int F_31 ( struct V_5 * V_4 )
{
int V_31 ;
T_1 V_50 ;
V_50 = V_51 ;
V_31 = F_28 ( V_4 -> V_40 , F_32 ( V_4 -> V_40 , 0 ) ,
V_52 , 0x40 ,
V_50 , 0 , NULL , 0 , 300 ) ;
return V_31 ;
}
static int F_33 ( struct V_5 * V_4 , T_1 V_53 )
{
int V_31 ;
T_1 V_50 ;
V_50 = V_51 ;
V_31 =
F_28 ( V_4 -> V_40 , F_32 ( V_4 -> V_40 , 0 ) ,
V_54 , 0x40 , V_53 , 0 , NULL , 0 , 300 ) ;
return V_31 ;
}
static int F_34 ( struct V_5 * V_4 ,
struct V_45 * V_46 )
{
int V_31 ;
T_1 V_55 ;
T_1 V_56 ;
V_56 = ( ( T_1 ) ( V_46 -> V_57 ) ) ;
V_56 = ( V_56 << 8 ) ;
V_56 += ( ( T_1 ) ( V_46 -> V_58 ) ) ;
V_55 = sizeof( struct V_45 ) ;
F_2 ( L_19 , V_26 , V_56 ) ;
V_31 = F_28 ( V_4 -> V_40 , F_32 ( V_4 -> V_40 , 0 ) ,
V_49 , 0x40 , V_56 ,
0 , NULL , 0 , 300 ) ;
return V_31 ;
}
static int F_35 ( struct V_5 * V_4 , T_1 V_59 ,
struct V_60 * V_61 )
{
int V_31 ;
V_31 = F_28 ( V_4 -> V_40 , F_29 ( V_4 -> V_40 , 0 ) ,
V_62 ,
V_63 , 1 , V_59 ,
V_61 ,
sizeof( struct V_60 ) , 300 ) ;
return V_31 ;
}
static int F_36 ( struct V_5 * V_4 , T_1 V_59 )
{
int V_31 ;
V_31 = F_28 ( V_4 -> V_40 , F_29 ( V_4 -> V_40 , 0 ) ,
V_62 ,
V_64 , 0 , V_59 ,
NULL , 0 , 300 ) ;
return V_31 ;
}
static int F_37 ( struct V_5 * V_4 , unsigned short V_59 ,
unsigned short V_65 , T_2 * V_66 )
{
int V_31 ;
T_1 V_67 ;
V_67 = sizeof( struct V_45 ) ;
V_31 =
F_28 ( V_4 -> V_40 , F_29 ( V_4 -> V_40 , 0 ) ,
V_68 , 0xC0 , V_65 ,
V_59 , ( void * ) V_66 , sizeof( * V_66 ) , 300 ) ;
return V_31 ;
}
static int F_38 ( struct V_5 * V_4 , unsigned short V_59 ,
unsigned short V_65 , unsigned short V_69 )
{
int V_31 ;
unsigned short V_70 ;
V_70 = V_69 ;
V_70 = V_70 << 8 ;
V_70 = V_70 + V_65 ;
V_31 =
F_28 ( V_4 -> V_40 , F_32 ( V_4 -> V_40 , 0 ) ,
V_68 , 0x40 , V_70 , V_59 ,
NULL , 0 , 300 ) ;
return V_31 ;
}
static int F_39 ( struct V_5 * V_4 , unsigned short V_59 ,
unsigned short V_71 , unsigned char V_72 )
{
int V_31 ;
unsigned short V_73 ;
V_73 = ( V_72 << 8 ) + V_59 ;
V_31 =
F_28 ( V_4 -> V_40 , F_32 ( V_4 -> V_40 , 0 ) ,
V_74 , 0x40 , V_71 ,
V_73 , NULL , 0 , 300 ) ;
return V_31 ;
}
static int F_40 ( struct V_5 * V_4 , unsigned int V_28 ,
int V_75 )
{
T_2 V_76 = 0 ;
T_2 V_77 = 0 , V_78 = 0 ;
unsigned int V_24 ;
if ( V_75 == 1 ) {
V_76 = V_79 ;
}
else {
V_76 = 0 ;
}
V_78 = V_76 << 8 ;
if ( V_75 == 1 ) {
V_77 = V_80 ;
} else {
V_77 = 0 ;
}
V_78 |= V_77 ;
V_24 =
F_28 ( V_4 -> V_40 , F_32 ( V_4 -> V_40 , 0 ) ,
V_81 , 0x40 , V_78 ,
V_28 , NULL , 0 , 300 ) ;
return V_24 ;
}
static int F_41 ( struct V_5 * V_4 , T_1 V_28 ,
unsigned char V_82 , unsigned char V_83 )
{
T_1 V_84 ;
int V_31 ;
V_84 = V_83 << 8 ;
V_84 = ( unsigned short ) V_82 ;
V_31 =
F_28 ( V_4 -> V_40 , F_32 ( V_4 -> V_40 , 0 ) ,
V_85 , 0x40 , V_84 ,
V_28 , NULL , 0 , 300 ) ;
return V_31 ;
}
static int F_42 ( struct V_5 * V_4 , T_1 V_28 )
{
int V_31 ;
V_31 =
F_28 ( V_4 -> V_40 , F_32 ( V_4 -> V_40 , 0 ) ,
V_86 , 0x40 , 0 , V_28 ,
NULL , 0 , 300 ) ;
return V_31 ;
}
static int F_43 ( struct V_5 * V_4 )
{
struct V_1 * V_2 ;
struct V_6 * V_8 ;
struct V_45 V_87 ;
int V_30 ;
int V_24 ;
F_2 ( L_20 , V_26 ) ;
for ( V_30 = 0 ; V_30 < V_4 -> V_88 ; V_30 ++ ) {
V_2 = V_4 -> V_2 [ V_30 ] ;
V_8 = F_44 ( sizeof( * V_8 ) , V_47 ) ;
if ( ! V_8 ) {
F_2 ( L_21 ,
V_26 , V_30 ) ;
for ( -- V_30 ; V_30 >= 0 ; V_30 -- ) {
V_2 = V_4 -> V_2 [ V_30 ] ;
F_30 ( F_5 ( V_2 ) ) ;
F_7 ( V_2 , NULL ) ;
}
return - V_48 ;
}
F_45 ( & V_8 -> V_89 ) ;
F_7 ( V_2 , V_8 ) ;
}
V_24 = F_26 ( V_4 , & V_87 ) ;
if ( V_24 < 0 ) {
F_2 ( __FILE__ L_22 ) ;
goto V_90;
}
F_2 ( __FILE__ L_23 , V_87 . V_57 ) ;
V_87 . V_57 &= ~ V_91 ;
F_2 ( __FILE__ L_24 , V_87 . V_57 ) ;
V_24 = F_34 ( V_4 , & V_87 ) ;
if ( V_24 < 0 ) {
F_2 ( __FILE__ L_25 ) ;
goto V_90;
}
V_24 = F_26 ( V_4 , & V_87 ) ;
if ( V_24 < 0 ) {
F_2 ( __FILE__ L_26 ) ;
goto V_90;
}
switch ( V_4 -> V_40 -> V_92 . V_93 ) {
case V_94 :
case V_95 :
case V_96 :
case V_97 :
case V_98 :
case V_99 :
case V_100 :
case V_101 :
V_87 . V_58 &= ~ ( V_102 | V_103 ) ;
V_87 . V_58 |= V_104 ;
V_87 . V_57 &= ~ ( V_105 ) ;
V_87 . V_57 |= V_106 ;
break;
case V_107 :
case V_108 :
case V_109 :
case V_110 :
case V_111 :
case V_112 :
case V_113 :
case V_114 :
case V_115 :
V_87 . V_58 &= ~ ( V_102 | V_103 ) ;
V_87 . V_58 |= V_104 ;
V_87 . V_57 &= ~ ( V_105 ) ;
V_87 . V_57 |= V_116 ;
break;
default:
V_87 . V_58 &= ~ ( V_102 | V_103 ) ;
V_87 . V_58 |= V_104 ;
V_87 . V_57 &= ~ ( V_105 ) ;
V_87 . V_57 |= V_106 ;
break;
}
V_24 = F_31 ( V_4 ) ;
if ( V_24 < 0 ) {
F_2 ( __FILE__ L_27 ) ;
goto V_90;
}
V_24 = F_33 ( V_4 , V_117 ) ;
if ( V_24 < 0 ) {
F_2 ( __FILE__ L_28 ) ;
goto V_90;
}
F_2 ( __FILE__ L_23 , V_87 . V_57 ) ;
V_87 . V_57 |= V_118 ;
F_2 ( __FILE__ L_24 , V_87 . V_57 ) ;
V_24 = F_34 ( V_4 , & V_87 ) ;
if ( V_24 < 0 ) {
F_2 ( __FILE__ L_25 ) ;
goto V_90;
}
F_2 ( L_29 , V_26 ) ;
return 0 ;
V_90:
for ( V_30 = 0 ; V_30 < V_4 -> V_88 ; V_30 ++ ) {
V_2 = V_4 -> V_2 [ V_30 ] ;
V_8 = F_4 ( V_2 ) ;
F_30 ( V_8 ) ;
F_7 ( V_2 , NULL ) ;
}
F_2 ( L_30 , V_26 ) ;
return - V_119 ;
}
static void F_46 ( struct V_5 * V_4 )
{
struct V_1 * V_2 ;
struct V_6 * V_8 ;
int V_30 ;
F_2 ( L_20 , V_26 ) ;
for ( V_30 = 0 ; V_30 < V_4 -> V_88 ; V_30 ++ ) {
V_2 = V_4 -> V_2 [ V_30 ] ;
if ( ! V_2 )
continue;
V_8 = F_5 ( V_2 ) ;
F_30 ( V_8 ) ;
F_7 ( V_2 , NULL ) ;
}
}
static int F_47 ( struct V_18 * V_19 ,
struct V_1 * V_2 )
{
struct V_5 * V_4 ;
struct V_6 * V_6 ;
struct V_6 * V_120 ;
struct V_60 V_121 ;
int V_31 ;
if ( F_1 ( V_2 , V_26 ) )
return - V_122 ;
F_2 ( L_6 , V_26 , V_2 -> V_37 ) ;
V_4 = V_2 -> V_4 ;
if ( F_3 ( V_4 , V_26 ) )
return - V_122 ;
V_6 = F_4 ( V_2 ) ;
V_120 = F_4 ( V_4 -> V_2 [ 0 ] ) ;
if ( V_6 == NULL || V_120 == NULL )
return - V_122 ;
F_48 ( V_4 -> V_40 , V_2 -> V_123 -> V_124 ) ;
F_48 ( V_4 -> V_40 , V_2 -> V_21 -> V_124 ) ;
V_120 -> V_125 ++ ;
V_31 = F_26 ( V_4 , & V_120 -> V_87 ) ;
V_31 = F_35 ( V_4 , V_2 -> V_37 , & V_121 ) ;
if ( V_31 < 0 ) {
F_2 ( __FILE__ L_31 ) ;
return V_31 ;
}
F_2 ( __FILE__ L_32 ) ;
V_6 -> V_10 = V_121 . V_9 &
( V_11 | V_12 | V_13 | V_14 ) ;
V_6 -> V_16 = V_121 . V_15 &
( V_80 | V_126 | V_127 | V_128 ) ;
V_31 = F_39 ( V_4 , V_2 -> V_37 , V_129 , V_130 ) ;
if ( V_31 < 0 ) {
F_2 ( __FILE__ L_33 ) ;
return V_31 ;
}
F_2 ( __FILE__ L_34 ) ;
if ( V_120 -> V_125 == 1 ) {
if ( V_4 -> V_2 [ 0 ] -> V_131 == NULL ) {
F_49 ( V_4 -> V_2 [ 0 ] -> V_132 ,
V_4 -> V_40 ,
F_50 ( V_4 -> V_40 ,
V_4 -> V_2 [ 0 ] -> V_133 ) ,
V_4 -> V_2 [ 0 ] -> V_131 ,
V_4 -> V_2 [ 0 ] ->
V_132 -> V_42 ,
F_18 , V_4 ,
V_4 -> V_2 [ 0 ] ->
V_132 -> V_134 ) ;
V_31 =
F_23 ( V_4 -> V_2 [ 0 ] -> V_132 ,
V_47 ) ;
if ( V_31 ) {
F_51 ( & V_2 -> V_40 ,
L_35
L_36 , V_26 , V_31 ) ;
}
}
}
F_2 ( L_37 , V_2 -> V_37 ) ;
F_2 ( L_38 , V_2 -> V_4 -> V_36 ) ;
F_2 ( L_39 , V_2 -> V_41 ) ;
F_2 ( L_40 , V_2 -> V_135 ) ;
F_2 ( L_41 , V_2 -> V_133 ) ;
F_2 ( L_42 , V_6 -> V_27 ) ;
V_6 -> V_21 = V_2 -> V_21 ;
F_21 ( V_6 -> V_21 ,
V_4 -> V_40 ,
F_22 ( V_4 -> V_40 ,
V_2 -> V_41 ) ,
V_2 -> V_136 ,
V_6 -> V_21 -> V_42 ,
F_19 , V_6 ) ;
F_2 ( L_43 , V_2 -> V_41 ) ;
V_6 -> V_137 = true ;
V_31 = F_23 ( V_6 -> V_21 , V_47 ) ;
if ( V_31 ) {
F_51 ( & V_2 -> V_40 ,
L_44 ,
V_26 , V_31 ) ;
V_6 -> V_137 = false ;
}
F_52 ( & V_6 -> V_17 ) ;
F_52 ( & V_6 -> V_138 ) ;
memset ( & ( V_6 -> V_139 ) , 0x00 , sizeof( V_6 -> V_139 ) ) ;
return 0 ;
}
static int F_53 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_140 ;
struct V_5 * V_4 ;
int V_141 = 0 ;
V_4 = F_8 ( V_2 , V_26 ) ;
F_2 ( L_6 , V_26 , V_2 -> V_37 ) ;
if ( V_4 -> V_142 ) {
if ( V_2 -> V_123 -> V_24 == - V_143 )
V_141 = V_2 -> V_123 -> V_42 ;
}
F_2 ( L_45 , V_26 , V_141 ) ;
return V_141 ;
}
static void F_54 ( struct V_18 * V_19 ,
struct V_6 * V_8 )
{
int V_144 = V_145 / 10 ;
int V_17 = 30 ;
int V_146 ;
while ( 1 ) {
V_146 = F_53 ( V_19 ) ;
if ( V_146 <= 0 )
return;
F_55 ( & V_8 -> V_17 , V_144 ) ;
V_17 -- ;
if ( V_17 == 0 ) {
F_2 ( L_46 , V_26 ) ;
return;
} else {
V_17 = 30 ;
}
}
}
static void F_56 ( struct V_1 * V_2 )
{
struct V_5 * V_4 = V_2 -> V_4 ;
struct V_6 * V_8 ;
struct V_6 * V_120 ;
struct V_18 * V_19 ;
int V_24 ;
unsigned int V_28 ;
V_24 = 0 ;
F_2 ( L_6 , V_26 , V_2 -> V_37 ) ;
V_19 = F_15 ( & V_2 -> V_2 ) ;
V_28 = V_19 -> V_28 - V_4 -> V_36 ;
V_8 = F_4 ( V_2 ) ;
V_120 = F_4 ( V_4 -> V_2 [ 0 ] ) ;
if ( V_4 -> V_142 )
F_57 ( V_2 -> V_123 ) ;
if ( V_4 -> V_147 )
F_57 ( V_2 -> V_21 ) ;
if ( V_4 -> V_40 )
F_54 ( V_19 , V_8 ) ;
F_17 ( V_19 ) ;
V_24 = F_36 ( V_4 , V_28 ) ;
if ( V_24 < 0 )
F_2 ( L_47 ,
V_26 , V_2 -> V_37 ) ;
V_120 -> V_125 -- ;
F_2 ( L_48 ,
V_120 -> V_125 , V_2 -> V_37 ) ;
if ( V_120 -> V_125 == 0 ) {
if ( V_4 -> V_2 [ 0 ] -> V_132 ) {
F_2 ( L_49 , L_50 ) ;
F_58 ( V_4 -> V_2 [ 0 ] -> V_132 ) ;
}
}
if ( V_8 -> V_123 ) {
F_30 ( V_8 -> V_123 -> V_35 ) ;
F_59 ( V_8 -> V_123 ) ;
}
}
static int F_60 ( struct V_18 * V_19 , struct V_1 * V_2 ,
const unsigned char * V_148 , int V_146 )
{
int V_31 ;
struct V_5 * V_4 = F_8 ( V_2 , V_26 ) ;
if ( V_4 == NULL )
return - V_122 ;
F_2 ( L_6 , V_26 , V_2 -> V_37 ) ;
if ( V_146 == 0 ) {
F_2 ( L_51 , V_26 ) ;
return 0 ;
}
if ( V_4 -> V_142 ) {
if ( V_2 -> V_123 -> V_24 == - V_143 ) {
F_2 ( L_52 , V_26 ) ;
return 0 ;
}
V_146 =
( V_146 > V_2 -> V_149 ) ? V_2 -> V_149 : V_146 ;
memcpy ( V_2 -> V_123 -> V_35 , V_148 , V_146 ) ;
F_21 ( V_2 -> V_123 , V_4 -> V_40 ,
F_61 ( V_4 -> V_40 ,
V_2 ->
V_135 ) ,
V_2 -> V_123 -> V_35 , V_146 ,
F_14 , V_2 ) ;
V_31 = F_23 ( V_2 -> V_123 , V_43 ) ;
if ( V_31 )
F_2 ( L_53 ,
V_26 , V_31 ) ;
else
V_31 = V_146 ;
return V_31 ;
}
return 0 ;
}
static int F_62 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_140 ;
struct V_5 * V_4 ;
struct V_6 * V_8 ;
int V_150 = - V_151 ;
if ( F_1 ( V_2 , V_26 ) ) {
F_2 ( L_49 , L_54 ) ;
return - 1 ;
}
V_4 = F_8 ( V_2 , V_26 ) ;
if ( ! V_4 )
return - V_122 ;
V_8 = F_4 ( V_2 ) ;
F_63 ( & V_8 -> V_89 ) ;
F_2 ( L_6 , V_26 , V_2 -> V_37 ) ;
if ( V_4 -> V_142 ) {
if ( V_2 -> V_123 -> V_24 != - V_143 )
V_150 = V_2 -> V_149 ;
}
F_64 ( & V_8 -> V_89 ) ;
return V_150 ;
}
static int F_65 ( struct V_18 * V_19 ,
unsigned int V_152 , unsigned long V_153 )
{
struct V_1 * V_2 = V_19 -> V_140 ;
struct V_6 * V_8 = F_4 ( V_2 ) ;
struct V_5 * V_4 = F_8 ( V_2 , V_26 ) ;
unsigned int V_28 ;
F_2 ( L_55 , V_26 , V_152 ) ;
V_28 = V_19 -> V_28 - V_4 -> V_36 ;
if ( V_152 == V_154 ) {
while ( V_8 != NULL ) {
F_66 ( & V_8 -> V_138 ) ;
if ( F_67 ( V_155 ) )
return - V_156 ;
else {
char V_157 = V_8 -> V_158 ;
if ( V_157 == 0 )
return - V_119 ;
V_8 -> V_158 = 0 ;
if ( ( ( V_153 & V_159 )
&& ( V_157 & V_127 ) )
|| ( ( V_153 & V_160 )
&& ( V_157 & V_126 ) )
|| ( ( V_153 & V_161 )
&& ( V_157 & V_128 ) )
|| ( ( V_153 & V_162 )
&& ( V_157 & V_80 ) ) ) {
return 0 ;
}
}
}
return 0 ;
}
F_2 ( L_56 , V_26 , V_2 -> V_37 ) ;
return - V_163 ;
}
static void F_68 ( struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_164 * V_165 )
{
struct V_164 * V_166 = V_19 -> V_166 ;
unsigned char V_167 = 0 ;
unsigned int V_168 = V_166 -> V_169 ;
unsigned int V_28 ;
int V_170 , V_171 , V_172 ;
int V_24 ;
F_2 ( L_49 , V_26 ) ;
V_28 = V_19 -> V_28 - V_2 -> V_4 -> V_36 ;
switch ( V_168 ) {
case V_173 :
V_167 |= V_174 ;
break;
case V_175 :
V_167 |= V_176 ;
break;
case V_177 :
V_167 |= V_178 ;
break;
default:
case V_179 :
V_167 |= V_180 ;
break;
}
if ( V_168 & V_181 ) {
if ( V_168 & V_182 )
V_167 |= V_183 ;
else
V_167 |= V_184 ;
}
if ( V_168 & V_185 )
V_167 |= V_186 ;
else
V_167 |= V_187 ;
F_2 ( L_57 , V_26 ) ;
V_170 = F_69 ( V_19 ) ;
if ( ! V_170 )
V_170 = 9600 ;
F_2 ( L_58 , V_26 , V_170 ) ;
V_171 = V_188 / V_170 ;
V_172 = V_188 % V_170 ;
if ( ( ( V_172 * 2 ) >= V_170 ) && ( V_170 != 110 ) )
V_171 ++ ;
V_24 =
F_39 ( V_2 -> V_4 , V_28 , ( unsigned short ) V_171 , V_167 ) ;
if ( V_24 < 0 ) {
F_2 ( __FILE__ L_33 ) ;
return;
}
if ( V_168 & V_189 ) {
F_2 ( L_59 , V_26 ,
V_2 -> V_37 ) ;
V_24 = F_40 ( V_2 -> V_4 , V_28 , 1 ) ;
if ( V_24 < 0 ) {
F_2 ( __FILE__ L_60 ) ;
return;
}
} else {
F_2 ( L_61 , V_26 ,
V_2 -> V_37 ) ;
V_24 = F_40 ( V_2 -> V_4 , V_28 , 0 ) ;
if ( V_24 < 0 ) {
F_2 ( __FILE__ L_60 ) ;
return;
}
}
if ( F_70 ( V_19 ) || F_71 ( V_19 ) ) {
unsigned char V_82 = F_72 ( V_19 ) ;
unsigned char V_83 = F_73 ( V_19 ) ;
V_24 =
F_41 ( V_2 -> V_4 , V_28 , V_82 ,
V_83 ) ;
if ( V_24 < 0 )
F_2 ( __FILE__ L_62 ) ;
} else {
V_24 = F_42 ( V_2 -> V_4 , V_28 ) ;
if ( V_24 < 0 )
F_2 ( __FILE__ L_63 ) ;
}
V_19 -> V_166 -> V_169 &= ~ V_190 ;
}
static void F_74 ( struct V_18 * V_19 , int V_191 )
{
struct V_1 * V_2 = V_19 -> V_140 ;
struct V_5 * V_4 = F_8 ( V_2 , V_26 ) ;
struct V_6 * V_8 ;
T_3 V_28 , V_192 ;
unsigned int V_31 ;
V_28 = V_19 -> V_28 - V_4 -> V_36 ;
V_8 = F_4 ( V_2 ) ;
if ( V_191 == - 1 )
V_192 = 1 ;
else
V_192 = 0 ;
F_63 ( & V_8 -> V_89 ) ;
F_2 ( L_6 , V_26 , V_2 -> V_37 ) ;
V_31 =
F_28 ( V_4 -> V_40 , F_32 ( V_4 -> V_40 , 0 ) ,
V_193 , 0x40 , V_192 , V_28 , NULL , 0 , 300 ) ;
F_64 ( & V_8 -> V_89 ) ;
}
static inline int F_75 ( struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_5 * V_4 )
{
T_4 V_76 ;
T_4 V_77 ;
unsigned int V_31 = 0 ;
int V_24 ;
unsigned int V_28 ;
F_2 ( L_64 , V_26 , V_2 -> V_37 , V_19 ) ;
V_28 = V_19 -> V_28 - V_4 -> V_36 ;
V_24 =
F_37 ( V_2 -> V_4 , V_28 , V_194 , & V_76 ) ;
if ( V_24 >= 0 ) {
V_24 =
F_37 ( V_2 -> V_4 , V_28 ,
V_195 , & V_77 ) ;
}
if ( V_24 >= 0 ) {
V_31 = ( ( V_76 & V_196 ) ? V_197 : 0 )
| ( ( V_76 & V_79 ) ? V_198 : 0 )
| ( ( V_77 & V_80 ) ? V_162 : 0 )
| ( ( V_77 & V_128 ) ? V_199 : 0 )
| ( ( V_77 & V_127 ) ? V_200 : 0 )
| ( ( V_77 & V_126 ) ? V_160 : 0 ) ;
return V_31 ;
} else
return - V_201 ;
}
static inline int F_76 ( struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_5 * V_4 ,
unsigned int V_202 )
{
T_4 V_76 ;
int V_24 ;
unsigned int V_28 ;
F_2 ( L_6 , V_26 , V_2 -> V_37 ) ;
V_28 = V_19 -> V_28 - V_4 -> V_36 ;
V_24 =
F_37 ( V_2 -> V_4 , V_28 , V_194 , & V_76 ) ;
if ( V_24 < 0 )
return - V_201 ;
V_76 &= ~ ( V_79 | V_196 | V_203 ) ;
if ( V_202 & V_198 )
V_76 |= V_79 ;
if ( V_202 & V_197 )
V_76 |= V_196 ;
if ( V_202 & V_204 )
V_76 |= V_203 ;
V_24 =
F_38 ( V_2 -> V_4 , V_28 , V_194 , V_76 ) ;
if ( V_24 < 0 )
return - V_201 ;
else
return 0 ;
}
static int F_77 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_140 ;
struct V_5 * V_4 = F_8 ( V_2 , V_26 ) ;
struct V_6 * V_8 = F_4 ( V_2 ) ;
int V_150 = - V_122 ;
F_2 ( L_65 , V_26 ) ;
if ( ! V_4 )
return - V_122 ;
F_63 ( & V_8 -> V_89 ) ;
F_2 ( L_6 , V_26 , V_2 -> V_37 ) ;
F_2 ( L_9 , V_26 , V_8 -> V_38 ) ;
V_150 = F_75 ( V_19 , V_2 , V_4 ) ;
F_64 ( & V_8 -> V_89 ) ;
return V_150 ;
}
static int F_78 ( struct V_18 * V_19 ,
unsigned int V_205 , unsigned int V_206 )
{
struct V_1 * V_2 = V_19 -> V_140 ;
struct V_5 * V_4 = F_8 ( V_2 , V_26 ) ;
struct V_6 * V_8 = F_4 ( V_2 ) ;
int V_150 = - V_122 ;
F_2 ( L_65 , V_26 ) ;
if ( ! V_4 )
return - V_122 ;
F_63 ( & V_8 -> V_89 ) ;
F_2 ( L_6 , V_26 , V_2 -> V_37 ) ;
F_2 ( L_66 , V_26 , V_8 -> V_38 ) ;
V_150 = F_76 ( V_19 , V_2 , V_4 , V_205 ) ;
F_64 ( & V_8 -> V_89 ) ;
return V_150 ;
}
static void F_79 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_140 ;
struct V_5 * V_4 = F_8 ( V_2 , V_26 ) ;
struct V_6 * V_8 ;
F_2 ( L_6 , V_26 , V_2 -> V_37 ) ;
if ( ! V_4 )
return;
V_8 = F_4 ( V_2 ) ;
F_63 ( & V_8 -> V_89 ) ;
V_8 -> V_38 = 1 ;
F_2 ( L_67 , V_26 ) ;
F_64 ( & V_8 -> V_89 ) ;
return;
}
static void F_80 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_140 ;
struct V_5 * V_4 = F_8 ( V_2 , V_26 ) ;
struct V_6 * V_8 ;
unsigned int V_31 ;
if ( ! V_4 )
return;
V_8 = F_4 ( V_2 ) ;
F_63 ( & V_8 -> V_89 ) ;
F_2 ( L_6 , V_26 , V_2 -> V_37 ) ;
if ( V_8 -> V_38 == 1 ) {
F_2 ( L_68 , V_26 ) ;
V_8 -> V_38 = 0 ;
F_2 ( L_69 , V_26 ) ;
if ( ( V_4 -> V_147 ) && ( V_8 -> V_34 == 1 ) ) {
F_21 ( V_2 -> V_21 , V_4 -> V_40 ,
F_22 ( V_4 -> V_40 ,
V_2 -> V_41 ) ,
V_2 -> V_21 -> V_35 ,
V_2 -> V_21 ->
V_42 ,
F_19 , V_2 ) ;
V_31 = F_23 ( V_2 -> V_21 , V_43 ) ;
if ( V_31 )
F_81 ( L_70 ,
V_26 , V_31 ) ;
}
}
F_64 ( & V_8 -> V_89 ) ;
return;
}
static int F_82 ( struct V_5 * V_4 )
{
int V_88 ;
F_2 ( L_71 ,
( int ) V_4 -> V_207 -> V_208 -> V_209 . V_210 ) ;
F_2 ( L_71 ,
( int ) V_4 -> V_207 -> V_211 -> V_209 . V_210 ) ;
V_88 =
( V_4 -> V_207 -> V_208 -> V_209 . V_210 - 1 ) / 2 ;
return V_88 ;
}
static int T_5 F_83 ( void )
{
int V_150 ;
F_2 ( L_72 , V_26 ) ;
V_150 = F_84 ( & V_212 ) ;
if ( V_150 )
goto V_213;
F_85 (KERN_INFO KBUILD_MODNAME L_73 DRIVER_VERSION L_74
DRIVER_DESC L_75 ) ;
V_150 = F_86 ( & V_214 ) ;
if ( V_150 == 0 )
return 0 ;
F_87 ( & V_212 ) ;
V_213:
return V_150 ;
}
static void T_6 F_88 ( void )
{
F_89 ( & V_214 ) ;
F_87 ( & V_212 ) ;
}
