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
unsigned int V_27 ;
unsigned int V_28 ;
int V_29 , V_30 ;
int V_31 , V_32 ;
if ( V_20 -> V_24 ) {
V_8 -> V_33 = 1 ;
F_2 ( L_6 ,
V_26 , V_20 -> V_24 ) ;
return;
}
V_19 = F_15 ( & V_2 -> V_2 ) ;
if ( ! V_19 ) {
F_2 ( L_7 , V_26 ) ;
return;
}
V_7 = V_20 -> V_34 ;
V_28 = V_20 -> V_22 ;
V_27 = V_19 -> V_27 - V_4 -> V_35 ;
F_2 ( L_8 , V_26 , V_8 -> V_36 ) ;
if ( F_1 ( V_2 , V_26 ) != 0 ) {
F_2 ( L_9 , V_26 ) ;
V_8 -> V_33 = 1 ;
goto exit;
}
if ( ! V_4 ) {
F_2 ( L_10 , V_26 ) ;
goto exit;
}
if ( V_8 -> V_37 == 1 ) {
F_2 ( L_11 , V_26 ) ;
V_8 -> V_33 = 1 ;
goto exit;
}
if ( V_8 -> V_36 == 1 ) {
V_8 -> V_33 = 1 ;
goto exit;
}
if ( V_20 -> V_24 ) {
V_8 -> V_33 = 1 ;
F_2 ( L_12 ,
V_26 , V_20 -> V_24 ) ;
goto exit;
}
if ( V_19 && V_28 ) {
V_32 = 0 ;
for ( V_29 = 0 ; V_29 < V_28 ; ++ V_29 ) {
if ( ( V_29 <= ( V_28 - 3 ) ) && ( V_7 [ V_29 ] == 0x1b )
&& ( V_7 [ V_29 + 1 ] == 0x1b ) ) {
V_31 = 0 ;
switch ( V_7 [ V_29 + 2 ] ) {
case 0x00 :
if ( V_29 > ( V_28 - 4 ) ) {
F_2 ( L_13 ) ;
break;
}
F_9 ( V_8 , V_7 [ V_29 + 3 ] ) ;
V_29 += 3 ;
V_31 = 1 ;
break;
case 0x01 :
F_2 ( L_14 ) ;
if ( V_29 > ( V_28 - 4 ) ) {
F_2 ( L_15 ) ;
break;
}
F_10 ( V_8 ,
V_7 [ V_29 + 3 ] ) ;
V_29 += 3 ;
V_31 = 1 ;
break;
case 0xff :
F_2 ( L_16 ) ;
if ( V_19 ) {
F_12 ( V_19 , V_2 , V_7 [ V_29 ] ) ;
F_12 ( V_19 , V_2 , V_7 [ V_29 + 1 ] ) ;
}
V_29 += 2 ;
break;
}
if ( V_31 == 1 )
continue;
}
if ( V_19 && V_20 -> V_22 )
F_13 ( V_19 , V_7 [ V_29 ] , V_23 ) ;
}
F_20 ( V_19 ) ;
}
F_21 ( V_2 -> V_21 , V_4 -> V_38 ,
F_22 ( V_4 -> V_38 ,
V_2 -> V_39 ) ,
V_2 -> V_21 -> V_34 ,
V_2 -> V_21 -> V_40 ,
F_19 , V_2 ) ;
V_30 = F_23 ( V_2 -> V_21 , V_41 ) ;
if ( V_30 )
F_2 ( L_17 ,
V_26 , V_30 ) ;
else {
if ( V_19 && V_28 ) {
F_20 ( V_19 ) ;
F_24 ( V_19 ) ;
}
}
F_25 ( & V_2 -> V_42 ) ;
exit:
F_17 ( V_19 ) ;
}
static int F_26 ( struct V_5 * V_4 ,
struct V_43 * V_44 )
{
int V_30 ;
unsigned char * V_34 ;
V_34 =
F_27 ( sizeof( struct V_43 ) , V_45 ) ;
if ( ! V_34 )
return - V_46 ;
V_30 = F_28 ( V_4 -> V_38 , F_29 ( V_4 -> V_38 , 0 ) ,
V_47 , 0xc0 , 0 , 0 ,
V_34 ,
sizeof( struct V_43 ) , 300 ) ;
if ( V_30 > 0 )
memcpy ( V_44 , V_34 ,
sizeof( struct V_43 ) ) ;
F_30 ( V_34 ) ;
return V_30 ;
}
static int F_31 ( struct V_5 * V_4 )
{
int V_30 ;
T_1 V_48 ;
V_48 = V_49 ;
V_30 = F_28 ( V_4 -> V_38 , F_32 ( V_4 -> V_38 , 0 ) ,
V_50 , 0x40 ,
V_48 , 0 , NULL , 0 , 300 ) ;
return V_30 ;
}
static int F_33 ( struct V_5 * V_4 , T_1 V_51 )
{
int V_30 ;
T_1 V_48 ;
V_48 = V_49 ;
V_30 =
F_28 ( V_4 -> V_38 , F_32 ( V_4 -> V_38 , 0 ) ,
V_52 , 0x40 , V_51 , 0 , NULL , 0 , 300 ) ;
return V_30 ;
}
static int F_34 ( struct V_5 * V_4 ,
struct V_43 * V_44 )
{
int V_30 ;
T_1 V_53 ;
T_1 V_54 ;
V_54 = ( ( T_1 ) ( V_44 -> V_55 ) ) ;
V_54 = ( V_54 << 8 ) ;
V_54 += ( ( T_1 ) ( V_44 -> V_56 ) ) ;
V_53 = sizeof( struct V_43 ) ;
F_2 ( L_18 , V_26 , V_54 ) ;
V_30 = F_28 ( V_4 -> V_38 , F_32 ( V_4 -> V_38 , 0 ) ,
V_47 , 0x40 , V_54 ,
0 , NULL , 0 , 300 ) ;
return V_30 ;
}
static int F_35 ( struct V_5 * V_4 , T_1 V_57 ,
struct V_58 * V_59 )
{
int V_30 ;
V_30 = F_28 ( V_4 -> V_38 , F_29 ( V_4 -> V_38 , 0 ) ,
V_60 ,
V_61 , 1 , V_57 ,
V_59 ,
sizeof( struct V_58 ) , 300 ) ;
return V_30 ;
}
static int F_36 ( struct V_5 * V_4 , T_1 V_57 )
{
int V_30 ;
V_30 = F_28 ( V_4 -> V_38 , F_29 ( V_4 -> V_38 , 0 ) ,
V_60 ,
V_62 , 0 , V_57 ,
NULL , 0 , 300 ) ;
return V_30 ;
}
static int F_37 ( struct V_5 * V_4 , unsigned short V_57 ,
unsigned short V_63 , T_2 * V_64 )
{
int V_30 ;
T_1 V_65 ;
V_65 = sizeof( struct V_43 ) ;
V_30 =
F_28 ( V_4 -> V_38 , F_29 ( V_4 -> V_38 , 0 ) ,
V_66 , 0xC0 , V_63 ,
V_57 , ( void * ) V_64 , sizeof( * V_64 ) , 300 ) ;
return V_30 ;
}
static int F_38 ( struct V_5 * V_4 , unsigned short V_57 ,
unsigned short V_63 , unsigned short V_67 )
{
int V_30 ;
unsigned short V_68 ;
V_68 = V_67 ;
V_68 = V_68 << 8 ;
V_68 = V_68 + V_63 ;
V_30 =
F_28 ( V_4 -> V_38 , F_32 ( V_4 -> V_38 , 0 ) ,
V_66 , 0x40 , V_68 , V_57 ,
NULL , 0 , 300 ) ;
return V_30 ;
}
static int F_39 ( struct V_5 * V_4 , unsigned short V_57 ,
unsigned short V_69 , unsigned char V_70 )
{
int V_30 ;
unsigned short V_71 ;
V_71 = ( V_70 << 8 ) + V_57 ;
V_30 =
F_28 ( V_4 -> V_38 , F_32 ( V_4 -> V_38 , 0 ) ,
V_72 , 0x40 , V_69 ,
V_71 , NULL , 0 , 300 ) ;
return V_30 ;
}
static int F_40 ( struct V_5 * V_4 , unsigned int V_27 ,
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
F_28 ( V_4 -> V_38 , F_32 ( V_4 -> V_38 , 0 ) ,
V_79 , 0x40 , V_76 ,
V_27 , NULL , 0 , 300 ) ;
return V_24 ;
}
static int F_41 ( struct V_5 * V_4 , T_1 V_27 ,
unsigned char V_80 , unsigned char V_81 )
{
T_1 V_82 ;
int V_30 ;
V_82 = V_81 << 8 ;
V_82 = ( unsigned short ) V_80 ;
V_30 =
F_28 ( V_4 -> V_38 , F_32 ( V_4 -> V_38 , 0 ) ,
V_83 , 0x40 , V_82 ,
V_27 , NULL , 0 , 300 ) ;
return V_30 ;
}
static int F_42 ( struct V_5 * V_4 , T_1 V_27 )
{
int V_30 ;
V_30 =
F_28 ( V_4 -> V_38 , F_32 ( V_4 -> V_38 , 0 ) ,
V_84 , 0x40 , 0 , V_27 ,
NULL , 0 , 300 ) ;
return V_30 ;
}
static int F_43 ( struct V_5 * V_4 )
{
struct V_1 * V_2 ;
struct V_6 * V_8 ;
struct V_43 V_85 ;
int V_29 ;
int V_24 ;
for ( V_29 = 0 ; V_29 < V_4 -> V_86 ; V_29 ++ ) {
V_2 = V_4 -> V_2 [ V_29 ] ;
V_8 = F_44 ( sizeof( * V_8 ) , V_45 ) ;
if ( ! V_8 ) {
F_2 ( L_19 ,
V_26 , V_29 ) ;
for ( -- V_29 ; V_29 >= 0 ; V_29 -- ) {
V_2 = V_4 -> V_2 [ V_29 ] ;
F_30 ( F_5 ( V_2 ) ) ;
F_7 ( V_2 , NULL ) ;
}
return - V_46 ;
}
F_45 ( & V_8 -> V_87 ) ;
F_7 ( V_2 , V_8 ) ;
}
V_24 = F_26 ( V_4 , & V_85 ) ;
if ( V_24 < 0 ) {
F_2 ( __FILE__ L_20 ) ;
goto V_88;
}
F_2 ( __FILE__ L_21 , V_85 . V_55 ) ;
V_85 . V_55 &= ~ V_89 ;
F_2 ( __FILE__ L_22 , V_85 . V_55 ) ;
V_24 = F_34 ( V_4 , & V_85 ) ;
if ( V_24 < 0 ) {
F_2 ( __FILE__ L_23 ) ;
goto V_88;
}
V_24 = F_26 ( V_4 , & V_85 ) ;
if ( V_24 < 0 ) {
F_2 ( __FILE__ L_24 ) ;
goto V_88;
}
switch ( V_4 -> V_38 -> V_90 . V_91 ) {
case V_92 :
case V_93 :
case V_94 :
case V_95 :
case V_96 :
case V_97 :
case V_98 :
case V_99 :
V_85 . V_56 &= ~ ( V_100 | V_101 ) ;
V_85 . V_56 |= V_102 ;
V_85 . V_55 &= ~ ( V_103 ) ;
V_85 . V_55 |= V_104 ;
break;
case V_105 :
case V_106 :
case V_107 :
case V_108 :
case V_109 :
case V_110 :
case V_111 :
case V_112 :
case V_113 :
V_85 . V_56 &= ~ ( V_100 | V_101 ) ;
V_85 . V_56 |= V_102 ;
V_85 . V_55 &= ~ ( V_103 ) ;
V_85 . V_55 |= V_114 ;
break;
default:
V_85 . V_56 &= ~ ( V_100 | V_101 ) ;
V_85 . V_56 |= V_102 ;
V_85 . V_55 &= ~ ( V_103 ) ;
V_85 . V_55 |= V_104 ;
break;
}
V_24 = F_31 ( V_4 ) ;
if ( V_24 < 0 ) {
F_2 ( __FILE__ L_25 ) ;
goto V_88;
}
V_24 = F_33 ( V_4 , V_115 ) ;
if ( V_24 < 0 ) {
F_2 ( __FILE__ L_26 ) ;
goto V_88;
}
F_2 ( __FILE__ L_21 , V_85 . V_55 ) ;
V_85 . V_55 |= V_116 ;
F_2 ( __FILE__ L_22 , V_85 . V_55 ) ;
V_24 = F_34 ( V_4 , & V_85 ) ;
if ( V_24 < 0 ) {
F_2 ( __FILE__ L_23 ) ;
goto V_88;
}
F_2 ( L_27 , V_26 ) ;
return 0 ;
V_88:
for ( V_29 = 0 ; V_29 < V_4 -> V_86 ; V_29 ++ ) {
V_2 = V_4 -> V_2 [ V_29 ] ;
V_8 = F_4 ( V_2 ) ;
F_30 ( V_8 ) ;
F_7 ( V_2 , NULL ) ;
}
F_2 ( L_28 , V_26 ) ;
return - V_117 ;
}
static void F_46 ( struct V_5 * V_4 )
{
struct V_1 * V_2 ;
struct V_6 * V_8 ;
int V_29 ;
for ( V_29 = 0 ; V_29 < V_4 -> V_86 ; V_29 ++ ) {
V_2 = V_4 -> V_2 [ V_29 ] ;
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
struct V_6 * V_118 ;
struct V_58 V_119 ;
int V_30 ;
if ( F_1 ( V_2 , V_26 ) )
return - V_120 ;
V_4 = V_2 -> V_4 ;
if ( F_3 ( V_4 , V_26 ) )
return - V_120 ;
V_6 = F_4 ( V_2 ) ;
V_118 = F_4 ( V_4 -> V_2 [ 0 ] ) ;
if ( V_6 == NULL || V_118 == NULL )
return - V_120 ;
F_48 ( V_4 -> V_38 , V_2 -> V_121 -> V_122 ) ;
F_48 ( V_4 -> V_38 , V_2 -> V_21 -> V_122 ) ;
V_118 -> V_123 ++ ;
V_30 = F_26 ( V_4 , & V_118 -> V_85 ) ;
V_30 = F_35 ( V_4 , V_2 -> V_124 , & V_119 ) ;
if ( V_30 < 0 ) {
F_2 ( __FILE__ L_29 ) ;
return V_30 ;
}
F_2 ( __FILE__ L_30 ) ;
V_6 -> V_10 = V_119 . V_9 &
( V_11 | V_12 | V_13 | V_14 ) ;
V_6 -> V_16 = V_119 . V_15 &
( V_78 | V_125 | V_126 | V_127 ) ;
V_30 = F_39 ( V_4 , V_2 -> V_124 , V_128 , V_129 ) ;
if ( V_30 < 0 ) {
F_2 ( __FILE__ L_31 ) ;
return V_30 ;
}
F_2 ( __FILE__ L_32 ) ;
if ( V_118 -> V_123 == 1 ) {
if ( V_4 -> V_2 [ 0 ] -> V_130 == NULL ) {
F_49 ( V_4 -> V_2 [ 0 ] -> V_131 ,
V_4 -> V_38 ,
F_50 ( V_4 -> V_38 ,
V_4 -> V_2 [ 0 ] -> V_132 ) ,
V_4 -> V_2 [ 0 ] -> V_130 ,
V_4 -> V_2 [ 0 ] ->
V_131 -> V_40 ,
F_18 , V_4 ,
V_4 -> V_2 [ 0 ] ->
V_131 -> V_133 ) ;
V_30 =
F_23 ( V_4 -> V_2 [ 0 ] -> V_131 ,
V_45 ) ;
if ( V_30 ) {
F_51 ( & V_2 -> V_38 ,
L_33
L_34 , V_26 , V_30 ) ;
}
}
}
F_2 ( L_35 , V_2 -> V_124 ) ;
F_2 ( L_36 , V_2 -> V_4 -> V_35 ) ;
F_2 ( L_37 , V_2 -> V_39 ) ;
F_2 ( L_38 , V_2 -> V_134 ) ;
F_2 ( L_39 , V_2 -> V_132 ) ;
F_2 ( L_40 , V_6 -> V_135 ) ;
V_6 -> V_21 = V_2 -> V_21 ;
F_21 ( V_6 -> V_21 ,
V_4 -> V_38 ,
F_22 ( V_4 -> V_38 ,
V_2 -> V_39 ) ,
V_2 -> V_136 ,
V_6 -> V_21 -> V_40 ,
F_19 , V_6 ) ;
F_2 ( L_41 , V_2 -> V_39 ) ;
V_6 -> V_137 = true ;
V_30 = F_23 ( V_6 -> V_21 , V_45 ) ;
if ( V_30 ) {
F_51 ( & V_2 -> V_38 ,
L_42 ,
V_26 , V_30 ) ;
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
if ( V_4 -> V_142 ) {
if ( V_2 -> V_121 -> V_24 == - V_143 )
V_141 = V_2 -> V_121 -> V_40 ;
}
F_2 ( L_43 , V_26 , V_141 ) ;
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
F_2 ( L_44 , V_26 ) ;
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
struct V_6 * V_118 ;
struct V_18 * V_19 ;
int V_24 ;
unsigned int V_27 ;
V_24 = 0 ;
V_19 = F_15 ( & V_2 -> V_2 ) ;
V_27 = V_19 -> V_27 - V_4 -> V_35 ;
V_8 = F_4 ( V_2 ) ;
V_118 = F_4 ( V_4 -> V_2 [ 0 ] ) ;
if ( V_4 -> V_142 )
F_57 ( V_2 -> V_121 ) ;
if ( V_4 -> V_147 )
F_57 ( V_2 -> V_21 ) ;
if ( V_4 -> V_38 )
F_54 ( V_19 , V_8 ) ;
F_17 ( V_19 ) ;
V_24 = F_36 ( V_4 , V_27 ) ;
if ( V_24 < 0 )
F_2 ( L_45 ,
V_26 , V_2 -> V_124 ) ;
V_118 -> V_123 -- ;
F_2 ( L_46 ,
V_118 -> V_123 , V_2 -> V_124 ) ;
if ( V_118 -> V_123 == 0 ) {
if ( V_4 -> V_2 [ 0 ] -> V_131 ) {
F_2 ( L_47 , L_48 ) ;
F_58 ( V_4 -> V_2 [ 0 ] -> V_131 ) ;
}
}
if ( V_8 -> V_121 ) {
F_30 ( V_8 -> V_121 -> V_34 ) ;
F_59 ( V_8 -> V_121 ) ;
}
}
static int F_60 ( struct V_18 * V_19 , struct V_1 * V_2 ,
const unsigned char * V_148 , int V_146 )
{
int V_30 ;
struct V_5 * V_4 = F_8 ( V_2 , V_26 ) ;
if ( V_4 == NULL )
return - V_120 ;
if ( V_146 == 0 ) {
F_2 ( L_49 , V_26 ) ;
return 0 ;
}
if ( V_4 -> V_142 ) {
if ( V_2 -> V_121 -> V_24 == - V_143 ) {
F_2 ( L_50 , V_26 ) ;
return 0 ;
}
V_146 =
( V_146 > V_2 -> V_149 ) ? V_2 -> V_149 : V_146 ;
memcpy ( V_2 -> V_121 -> V_34 , V_148 , V_146 ) ;
F_21 ( V_2 -> V_121 , V_4 -> V_38 ,
F_61 ( V_4 -> V_38 ,
V_2 ->
V_134 ) ,
V_2 -> V_121 -> V_34 , V_146 ,
F_14 , V_2 ) ;
V_30 = F_23 ( V_2 -> V_121 , V_41 ) ;
if ( V_30 )
F_2 ( L_51 ,
V_26 , V_30 ) ;
else
V_30 = V_146 ;
return V_30 ;
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
F_2 ( L_47 , L_52 ) ;
return - 1 ;
}
V_4 = F_8 ( V_2 , V_26 ) ;
if ( ! V_4 )
return - V_120 ;
V_8 = F_4 ( V_2 ) ;
F_63 ( & V_8 -> V_87 ) ;
if ( V_4 -> V_142 ) {
if ( V_2 -> V_121 -> V_24 != - V_143 )
V_150 = V_2 -> V_149 ;
}
F_64 ( & V_8 -> V_87 ) ;
return V_150 ;
}
static int F_65 ( struct V_18 * V_19 ,
unsigned int V_152 , unsigned long V_153 )
{
struct V_1 * V_2 = V_19 -> V_140 ;
struct V_6 * V_8 = F_4 ( V_2 ) ;
struct V_5 * V_4 = F_8 ( V_2 , V_26 ) ;
unsigned int V_27 ;
F_2 ( L_53 , V_26 , V_152 ) ;
V_27 = V_19 -> V_27 - V_4 -> V_35 ;
if ( V_152 == V_154 ) {
while ( V_8 != NULL ) {
F_66 ( & V_8 -> V_138 ) ;
if ( F_67 ( V_155 ) )
return - V_156 ;
else {
char V_157 = V_8 -> V_158 ;
if ( V_157 == 0 )
return - V_117 ;
V_8 -> V_158 = 0 ;
if ( ( ( V_153 & V_159 )
&& ( V_157 & V_126 ) )
|| ( ( V_153 & V_160 )
&& ( V_157 & V_125 ) )
|| ( ( V_153 & V_161 )
&& ( V_157 & V_127 ) )
|| ( ( V_153 & V_162 )
&& ( V_157 & V_78 ) ) ) {
return 0 ;
}
}
}
return 0 ;
}
F_2 ( L_54 , V_26 , V_2 -> V_124 ) ;
return - V_163 ;
}
static void F_68 ( struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_164 * V_165 )
{
struct V_164 * V_166 = V_19 -> V_166 ;
unsigned char V_167 = 0 ;
unsigned int V_168 = V_166 -> V_169 ;
unsigned int V_27 ;
int V_170 , V_171 , V_172 ;
int V_24 ;
V_27 = V_19 -> V_27 - V_2 -> V_4 -> V_35 ;
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
F_2 ( L_55 , V_26 ) ;
V_170 = F_69 ( V_19 ) ;
if ( ! V_170 )
V_170 = 9600 ;
F_2 ( L_56 , V_26 , V_170 ) ;
V_171 = V_188 / V_170 ;
V_172 = V_188 % V_170 ;
if ( ( ( V_172 * 2 ) >= V_170 ) && ( V_170 != 110 ) )
V_171 ++ ;
V_24 =
F_39 ( V_2 -> V_4 , V_27 , ( unsigned short ) V_171 , V_167 ) ;
if ( V_24 < 0 ) {
F_2 ( __FILE__ L_31 ) ;
return;
}
if ( V_168 & V_189 ) {
F_2 ( L_57 , V_26 ,
V_2 -> V_124 ) ;
V_24 = F_40 ( V_2 -> V_4 , V_27 , 1 ) ;
if ( V_24 < 0 ) {
F_2 ( __FILE__ L_58 ) ;
return;
}
} else {
F_2 ( L_59 , V_26 ,
V_2 -> V_124 ) ;
V_24 = F_40 ( V_2 -> V_4 , V_27 , 0 ) ;
if ( V_24 < 0 ) {
F_2 ( __FILE__ L_58 ) ;
return;
}
}
if ( F_70 ( V_19 ) || F_71 ( V_19 ) ) {
unsigned char V_80 = F_72 ( V_19 ) ;
unsigned char V_81 = F_73 ( V_19 ) ;
V_24 =
F_41 ( V_2 -> V_4 , V_27 , V_80 ,
V_81 ) ;
if ( V_24 < 0 )
F_2 ( __FILE__ L_60 ) ;
} else {
V_24 = F_42 ( V_2 -> V_4 , V_27 ) ;
if ( V_24 < 0 )
F_2 ( __FILE__ L_61 ) ;
}
V_19 -> V_166 -> V_169 &= ~ V_190 ;
}
static void F_74 ( struct V_18 * V_19 , int V_191 )
{
struct V_1 * V_2 = V_19 -> V_140 ;
struct V_5 * V_4 = F_8 ( V_2 , V_26 ) ;
struct V_6 * V_8 ;
T_3 V_27 , V_192 ;
unsigned int V_30 ;
V_27 = V_19 -> V_27 - V_4 -> V_35 ;
V_8 = F_4 ( V_2 ) ;
if ( V_191 == - 1 )
V_192 = 1 ;
else
V_192 = 0 ;
F_63 ( & V_8 -> V_87 ) ;
V_30 =
F_28 ( V_4 -> V_38 , F_32 ( V_4 -> V_38 , 0 ) ,
V_193 , 0x40 , V_192 , V_27 , NULL , 0 , 300 ) ;
F_64 ( & V_8 -> V_87 ) ;
}
static inline int F_75 ( struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_5 * V_4 )
{
T_4 V_74 ;
T_4 V_75 ;
unsigned int V_30 = 0 ;
int V_24 ;
unsigned int V_27 ;
V_27 = V_19 -> V_27 - V_4 -> V_35 ;
V_24 =
F_37 ( V_2 -> V_4 , V_27 , V_194 , & V_74 ) ;
if ( V_24 >= 0 ) {
V_24 =
F_37 ( V_2 -> V_4 , V_27 ,
V_195 , & V_75 ) ;
}
if ( V_24 >= 0 ) {
V_30 = ( ( V_74 & V_196 ) ? V_197 : 0 )
| ( ( V_74 & V_77 ) ? V_198 : 0 )
| ( ( V_75 & V_78 ) ? V_162 : 0 )
| ( ( V_75 & V_127 ) ? V_199 : 0 )
| ( ( V_75 & V_126 ) ? V_200 : 0 )
| ( ( V_75 & V_125 ) ? V_160 : 0 ) ;
return V_30 ;
} else
return - V_201 ;
}
static inline int F_76 ( struct V_18 * V_19 ,
struct V_1 * V_2 ,
struct V_5 * V_4 ,
unsigned int V_202 )
{
T_4 V_74 ;
int V_24 ;
unsigned int V_27 ;
V_27 = V_19 -> V_27 - V_4 -> V_35 ;
V_24 =
F_37 ( V_2 -> V_4 , V_27 , V_194 , & V_74 ) ;
if ( V_24 < 0 )
return - V_201 ;
V_74 &= ~ ( V_77 | V_196 | V_203 ) ;
if ( V_202 & V_198 )
V_74 |= V_77 ;
if ( V_202 & V_197 )
V_74 |= V_196 ;
if ( V_202 & V_204 )
V_74 |= V_203 ;
V_24 =
F_38 ( V_2 -> V_4 , V_27 , V_194 , V_74 ) ;
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
int V_150 = - V_120 ;
if ( ! V_4 )
return - V_120 ;
F_63 ( & V_8 -> V_87 ) ;
V_150 = F_75 ( V_19 , V_2 , V_4 ) ;
F_64 ( & V_8 -> V_87 ) ;
return V_150 ;
}
static int F_78 ( struct V_18 * V_19 ,
unsigned int V_205 , unsigned int V_206 )
{
struct V_1 * V_2 = V_19 -> V_140 ;
struct V_5 * V_4 = F_8 ( V_2 , V_26 ) ;
struct V_6 * V_8 = F_4 ( V_2 ) ;
int V_150 = - V_120 ;
if ( ! V_4 )
return - V_120 ;
F_63 ( & V_8 -> V_87 ) ;
V_150 = F_76 ( V_19 , V_2 , V_4 , V_205 ) ;
F_64 ( & V_8 -> V_87 ) ;
return V_150 ;
}
static void F_79 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_140 ;
struct V_5 * V_4 = F_8 ( V_2 , V_26 ) ;
struct V_6 * V_8 ;
if ( ! V_4 )
return;
V_8 = F_4 ( V_2 ) ;
F_63 ( & V_8 -> V_87 ) ;
V_8 -> V_36 = 1 ;
F_64 ( & V_8 -> V_87 ) ;
return;
}
static void F_80 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_140 ;
struct V_5 * V_4 = F_8 ( V_2 , V_26 ) ;
struct V_6 * V_8 ;
unsigned int V_30 ;
if ( ! V_4 )
return;
V_8 = F_4 ( V_2 ) ;
F_63 ( & V_8 -> V_87 ) ;
if ( V_8 -> V_36 == 1 ) {
F_2 ( L_62 , V_26 ) ;
V_8 -> V_36 = 0 ;
F_2 ( L_63 , V_26 ) ;
if ( ( V_4 -> V_147 ) && ( V_8 -> V_33 == 1 ) ) {
F_21 ( V_2 -> V_21 , V_4 -> V_38 ,
F_22 ( V_4 -> V_38 ,
V_2 -> V_39 ) ,
V_2 -> V_21 -> V_34 ,
V_2 -> V_21 ->
V_40 ,
F_19 , V_2 ) ;
V_30 = F_23 ( V_2 -> V_21 , V_41 ) ;
if ( V_30 )
F_51 ( & V_2 -> V_38 ,
L_64 ,
V_26 , V_30 ) ;
}
}
F_64 ( & V_8 -> V_87 ) ;
return;
}
static int F_81 ( struct V_5 * V_4 )
{
int V_86 ;
F_2 ( L_65 ,
( int ) V_4 -> V_207 -> V_208 -> V_209 . V_210 ) ;
F_2 ( L_65 ,
( int ) V_4 -> V_207 -> V_211 -> V_209 . V_210 ) ;
V_86 =
( V_4 -> V_207 -> V_208 -> V_209 . V_210 - 1 ) / 2 ;
return V_86 ;
}
