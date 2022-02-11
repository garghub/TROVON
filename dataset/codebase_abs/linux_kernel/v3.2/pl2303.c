static int F_1 ( T_1 V_1 , T_1 V_2 ,
struct V_3 * V_4 , unsigned char * V_5 )
{
int V_6 = F_2 ( V_4 -> V_7 , F_3 ( V_4 -> V_7 , 0 ) ,
V_8 , V_9 ,
V_1 , V_2 , V_5 , 1 , 100 ) ;
F_4 ( L_1 , V_9 ,
V_8 , V_1 , V_2 , V_6 , V_5 [ 0 ] ) ;
return V_6 ;
}
static int F_5 ( T_1 V_1 , T_1 V_2 ,
struct V_3 * V_4 )
{
int V_6 = F_2 ( V_4 -> V_7 , F_6 ( V_4 -> V_7 , 0 ) ,
V_10 , V_11 ,
V_1 , V_2 , NULL , 0 , 100 ) ;
F_4 ( L_2 , V_11 ,
V_10 , V_1 , V_2 , V_6 ) ;
return V_6 ;
}
static int F_7 ( struct V_3 * V_4 )
{
struct V_12 * V_13 ;
enum V_14 type = V_15 ;
unsigned char * V_5 ;
int V_16 ;
V_5 = F_8 ( 10 , V_17 ) ;
if ( V_5 == NULL )
return - V_18 ;
if ( V_4 -> V_7 -> V_19 . V_20 == 0x02 )
type = V_15 ;
else if ( V_4 -> V_7 -> V_19 . V_21 == 0x40 )
type = V_22 ;
else if ( V_4 -> V_7 -> V_19 . V_20 == 0x00 )
type = V_23 ;
else if ( V_4 -> V_7 -> V_19 . V_20 == 0xFF )
type = V_23 ;
F_4 ( L_3 , type ) ;
for ( V_16 = 0 ; V_16 < V_4 -> V_24 ; ++ V_16 ) {
V_13 = F_9 ( sizeof( struct V_12 ) , V_17 ) ;
if ( ! V_13 )
goto V_25;
F_10 ( & V_13 -> V_26 ) ;
F_11 ( & V_13 -> V_27 ) ;
V_13 -> type = type ;
F_12 ( V_4 -> V_28 [ V_16 ] , V_13 ) ;
}
F_1 ( 0x8484 , 0 , V_4 , V_5 ) ;
F_5 ( 0x0404 , 0 , V_4 ) ;
F_1 ( 0x8484 , 0 , V_4 , V_5 ) ;
F_1 ( 0x8383 , 0 , V_4 , V_5 ) ;
F_1 ( 0x8484 , 0 , V_4 , V_5 ) ;
F_5 ( 0x0404 , 1 , V_4 ) ;
F_1 ( 0x8484 , 0 , V_4 , V_5 ) ;
F_1 ( 0x8383 , 0 , V_4 , V_5 ) ;
F_5 ( 0 , 1 , V_4 ) ;
F_5 ( 1 , 0 , V_4 ) ;
if ( type == V_22 )
F_5 ( 2 , 0x44 , V_4 ) ;
else
F_5 ( 2 , 0x24 , V_4 ) ;
F_13 ( V_5 ) ;
return 0 ;
V_25:
F_13 ( V_5 ) ;
for ( -- V_16 ; V_16 >= 0 ; -- V_16 ) {
V_13 = F_14 ( V_4 -> V_28 [ V_16 ] ) ;
F_13 ( V_13 ) ;
F_12 ( V_4 -> V_28 [ V_16 ] , NULL ) ;
}
return - V_18 ;
}
static int F_15 ( struct V_29 * V_7 , T_2 V_1 )
{
int V_30 ;
V_30 = F_2 ( V_7 , F_6 ( V_7 , 0 ) ,
V_31 , V_32 ,
V_1 , 0 , NULL , 0 , 100 ) ;
F_4 ( L_4 , V_33 , V_1 , V_30 ) ;
return V_30 ;
}
static void F_16 ( struct V_34 * V_35 ,
struct V_36 * V_28 , struct V_37 * V_38 )
{
struct V_3 * V_4 = V_28 -> V_4 ;
struct V_12 * V_13 = F_14 ( V_28 ) ;
unsigned long V_39 ;
unsigned int V_40 ;
unsigned char * V_5 ;
int V_41 ;
int V_16 ;
T_2 V_42 ;
const int V_43 [] = { 75 , 150 , 300 , 600 , 1200 , 1800 , 2400 , 3600 ,
4800 , 7200 , 9600 , 14400 , 19200 , 28800 , 38400 ,
57600 , 115200 , 230400 , 460800 , 614400 ,
921600 , 1228800 , 2457600 , 3000000 , 6000000 } ;
int V_44 , V_45 ;
int V_46 ;
F_4 ( L_5 , V_33 , V_28 -> V_47 ) ;
if ( ! F_17 ( V_35 -> V_48 , V_38 ) )
return;
V_40 = V_35 -> V_48 -> V_49 ;
V_5 = F_9 ( 7 , V_17 ) ;
if ( ! V_5 ) {
F_18 ( & V_28 -> V_7 , L_6 , V_33 ) ;
* V_35 -> V_48 = * V_38 ;
return;
}
V_16 = F_2 ( V_4 -> V_7 , F_3 ( V_4 -> V_7 , 0 ) ,
V_50 , V_51 ,
0 , 0 , V_5 , 7 , 100 ) ;
F_4 ( L_7 , V_16 ,
V_5 [ 0 ] , V_5 [ 1 ] , V_5 [ 2 ] , V_5 [ 3 ] , V_5 [ 4 ] , V_5 [ 5 ] , V_5 [ 6 ] ) ;
if ( V_40 & V_52 ) {
switch ( V_40 & V_52 ) {
case V_53 :
V_5 [ 6 ] = 5 ;
break;
case V_54 :
V_5 [ 6 ] = 6 ;
break;
case V_55 :
V_5 [ 6 ] = 7 ;
break;
default:
case V_56 :
V_5 [ 6 ] = 8 ;
break;
}
F_4 ( L_8 , V_33 , V_5 [ 6 ] ) ;
}
V_41 = F_19 ( V_35 ) ;
F_4 ( L_9 , V_33 , V_41 ) ;
if ( V_41 ) {
for ( V_46 = 0 ; V_46 < F_20 ( V_43 ) ; V_46 ++ ) {
if ( V_43 [ V_46 ] / V_41 ) {
V_45 = V_43 [ V_46 ] ;
if ( V_46 == 0 ) {
V_41 = V_45 ;
} else {
V_44 = V_43 [ V_46 - 1 ] ;
if ( ( V_45 % V_41 )
> ( V_41 % V_44 ) )
V_41 = V_44 ;
else
V_41 = V_45 ;
}
break;
}
}
if ( V_41 > 1228800 ) {
if ( V_13 -> type != V_22 )
V_41 = 1228800 ;
else if ( V_41 > 6000000 )
V_41 = 6000000 ;
}
F_4 ( L_10 , V_33 , V_41 ) ;
if ( V_41 <= 115200 ) {
V_5 [ 0 ] = V_41 & 0xff ;
V_5 [ 1 ] = ( V_41 >> 8 ) & 0xff ;
V_5 [ 2 ] = ( V_41 >> 16 ) & 0xff ;
V_5 [ 3 ] = ( V_41 >> 24 ) & 0xff ;
} else {
unsigned V_57 = 12 * 1000 * 1000 * 32 / V_41 ;
V_5 [ 3 ] = 0x80 ;
V_5 [ 2 ] = 0 ;
V_5 [ 1 ] = ( V_57 >= 256 ) ;
while ( V_57 >= 256 ) {
V_57 >>= 2 ;
V_5 [ 1 ] <<= 1 ;
}
V_5 [ 0 ] = V_57 ;
}
}
if ( V_40 & V_58 ) {
if ( ( V_40 & V_52 ) == V_53 ) {
V_5 [ 4 ] = 1 ;
F_4 ( L_11 , V_33 ) ;
} else {
V_5 [ 4 ] = 2 ;
F_4 ( L_12 , V_33 ) ;
}
} else {
V_5 [ 4 ] = 0 ;
F_4 ( L_13 , V_33 ) ;
}
if ( V_40 & V_59 ) {
if ( V_40 & V_60 ) {
if ( V_40 & V_61 ) {
V_5 [ 5 ] = 3 ;
F_4 ( L_14 , V_33 ) ;
} else {
V_5 [ 5 ] = 1 ;
F_4 ( L_15 , V_33 ) ;
}
} else {
if ( V_40 & V_61 ) {
V_5 [ 5 ] = 4 ;
F_4 ( L_16 , V_33 ) ;
} else {
V_5 [ 5 ] = 2 ;
F_4 ( L_17 , V_33 ) ;
}
}
} else {
V_5 [ 5 ] = 0 ;
F_4 ( L_18 , V_33 ) ;
}
V_16 = F_2 ( V_4 -> V_7 , F_6 ( V_4 -> V_7 , 0 ) ,
V_62 , V_63 ,
0 , 0 , V_5 , 7 , 100 ) ;
F_4 ( L_19 , V_16 ) ;
F_21 ( & V_13 -> V_26 , V_39 ) ;
V_42 = V_13 -> V_64 ;
if ( ( V_40 & V_65 ) == V_66 )
V_13 -> V_64 &= ~ ( V_67 | V_68 ) ;
else
V_13 -> V_64 |= ( V_67 | V_68 ) ;
if ( V_42 != V_13 -> V_64 ) {
V_42 = V_13 -> V_64 ;
F_22 ( & V_13 -> V_26 , V_39 ) ;
F_15 ( V_4 -> V_7 , V_42 ) ;
} else {
F_22 ( & V_13 -> V_26 , V_39 ) ;
}
V_5 [ 0 ] = V_5 [ 1 ] = V_5 [ 2 ] = V_5 [ 3 ] = V_5 [ 4 ] = V_5 [ 5 ] = V_5 [ 6 ] = 0 ;
V_16 = F_2 ( V_4 -> V_7 , F_3 ( V_4 -> V_7 , 0 ) ,
V_50 , V_51 ,
0 , 0 , V_5 , 7 , 100 ) ;
F_4 ( L_7 , V_16 ,
V_5 [ 0 ] , V_5 [ 1 ] , V_5 [ 2 ] , V_5 [ 3 ] , V_5 [ 4 ] , V_5 [ 5 ] , V_5 [ 6 ] ) ;
if ( V_40 & V_69 ) {
if ( V_13 -> type == V_22 )
F_5 ( 0x0 , 0x61 , V_4 ) ;
else
F_5 ( 0x0 , 0x41 , V_4 ) ;
} else {
F_5 ( 0x0 , 0x0 , V_4 ) ;
}
if ( V_41 )
F_23 ( V_35 , V_41 , V_41 ) ;
F_13 ( V_5 ) ;
}
static void F_24 ( struct V_36 * V_28 , int V_70 )
{
struct V_12 * V_13 = F_14 ( V_28 ) ;
unsigned long V_39 ;
T_2 V_42 ;
F_21 ( & V_13 -> V_26 , V_39 ) ;
if ( V_70 )
V_13 -> V_64 |= ( V_67 | V_68 ) ;
else
V_13 -> V_64 &= ~ ( V_67 | V_68 ) ;
V_42 = V_13 -> V_64 ;
F_22 ( & V_13 -> V_26 , V_39 ) ;
F_15 ( V_28 -> V_4 -> V_7 , V_42 ) ;
}
static void F_25 ( struct V_36 * V_28 )
{
F_4 ( L_20 , V_33 , V_28 -> V_47 ) ;
F_26 ( V_28 ) ;
F_27 ( V_28 -> V_71 ) ;
}
static int F_28 ( struct V_34 * V_35 , struct V_36 * V_28 )
{
struct V_37 V_72 ;
struct V_3 * V_4 = V_28 -> V_4 ;
struct V_12 * V_13 = F_14 ( V_28 ) ;
int V_73 ;
F_4 ( L_5 , V_33 , V_28 -> V_47 ) ;
if ( V_13 -> type != V_22 ) {
F_29 ( V_4 -> V_7 , V_28 -> V_74 -> V_75 ) ;
F_29 ( V_4 -> V_7 , V_28 -> V_76 -> V_75 ) ;
} else {
F_5 ( 8 , 0 , V_4 ) ;
F_5 ( 9 , 0 , V_4 ) ;
}
if ( V_35 )
F_16 ( V_35 , V_28 , & V_72 ) ;
F_4 ( L_21 , V_33 ) ;
V_73 = F_30 ( V_28 , V_17 ) ;
if ( V_73 ) {
F_25 ( V_28 ) ;
return - V_77 ;
}
F_4 ( L_22 , V_33 ) ;
V_73 = F_31 ( V_28 -> V_71 , V_17 ) ;
if ( V_73 ) {
F_18 ( & V_28 -> V_7 , L_23
L_24 , V_33 , V_73 ) ;
F_25 ( V_28 ) ;
return - V_77 ;
}
V_28 -> V_28 . V_78 = 256 ;
return 0 ;
}
static int F_32 ( struct V_34 * V_35 ,
unsigned int V_79 , unsigned int V_80 )
{
struct V_36 * V_28 = V_35 -> V_81 ;
struct V_12 * V_13 = F_14 ( V_28 ) ;
unsigned long V_39 ;
T_2 V_42 ;
if ( ! F_33 ( V_28 -> V_4 -> V_82 ) )
return - V_83 ;
F_21 ( & V_13 -> V_26 , V_39 ) ;
if ( V_79 & V_84 )
V_13 -> V_64 |= V_68 ;
if ( V_79 & V_85 )
V_13 -> V_64 |= V_67 ;
if ( V_80 & V_84 )
V_13 -> V_64 &= ~ V_68 ;
if ( V_80 & V_85 )
V_13 -> V_64 &= ~ V_67 ;
V_42 = V_13 -> V_64 ;
F_22 ( & V_13 -> V_26 , V_39 ) ;
return F_15 ( V_28 -> V_4 -> V_7 , V_42 ) ;
}
static int F_34 ( struct V_34 * V_35 )
{
struct V_36 * V_28 = V_35 -> V_81 ;
struct V_12 * V_13 = F_14 ( V_28 ) ;
unsigned long V_39 ;
unsigned int V_86 ;
unsigned int V_87 ;
unsigned int V_73 ;
F_4 ( L_25 , V_33 , V_28 -> V_47 ) ;
if ( ! F_33 ( V_28 -> V_4 -> V_82 ) )
return - V_83 ;
F_21 ( & V_13 -> V_26 , V_39 ) ;
V_86 = V_13 -> V_64 ;
V_87 = V_13 -> V_88 ;
F_22 ( & V_13 -> V_26 , V_39 ) ;
V_73 = ( ( V_86 & V_67 ) ? V_85 : 0 )
| ( ( V_86 & V_68 ) ? V_84 : 0 )
| ( ( V_87 & V_89 ) ? V_90 : 0 )
| ( ( V_87 & V_91 ) ? V_92 : 0 )
| ( ( V_87 & V_93 ) ? V_94 : 0 )
| ( ( V_87 & V_95 ) ? V_96 : 0 ) ;
F_4 ( L_26 , V_33 , V_73 ) ;
return V_73 ;
}
static int F_35 ( struct V_36 * V_28 )
{
struct V_12 * V_13 = F_14 ( V_28 ) ;
if ( V_13 -> V_88 & V_95 )
return 1 ;
return 0 ;
}
static int F_36 ( struct V_36 * V_28 , unsigned int V_97 )
{
struct V_12 * V_13 = F_14 ( V_28 ) ;
unsigned long V_39 ;
unsigned int V_98 ;
unsigned int V_87 ;
unsigned int V_99 ;
F_21 ( & V_13 -> V_26 , V_39 ) ;
V_98 = V_13 -> V_88 ;
F_22 ( & V_13 -> V_26 , V_39 ) ;
while ( 1 ) {
F_37 ( & V_13 -> V_27 ) ;
if ( F_38 ( V_100 ) )
return - V_101 ;
F_21 ( & V_13 -> V_26 , V_39 ) ;
V_87 = V_13 -> V_88 ;
F_22 ( & V_13 -> V_26 , V_39 ) ;
V_99 = V_98 ^ V_87 ;
if ( ( ( V_97 & V_102 ) && ( V_99 & V_93 ) ) ||
( ( V_97 & V_92 ) && ( V_99 & V_91 ) ) ||
( ( V_97 & V_96 ) && ( V_99 & V_95 ) ) ||
( ( V_97 & V_90 ) && ( V_99 & V_89 ) ) ) {
return 0 ;
}
V_98 = V_87 ;
}
return 0 ;
}
static int F_39 ( struct V_34 * V_35 ,
unsigned int V_103 , unsigned long V_97 )
{
struct V_104 V_105 ;
struct V_36 * V_28 = V_35 -> V_81 ;
F_4 ( L_27 , V_33 , V_28 -> V_47 , V_103 ) ;
switch ( V_103 ) {
case V_106 :
memset ( & V_105 , 0 , sizeof V_105 ) ;
V_105 . type = V_107 ;
V_105 . line = V_28 -> V_4 -> V_108 ;
V_105 . V_28 = V_28 -> V_47 ;
V_105 . V_109 = 460800 ;
if ( F_40 ( ( void V_110 * ) V_97 , & V_105 , sizeof V_105 ) )
return - V_111 ;
return 0 ;
case V_112 :
F_4 ( L_28 , V_33 , V_28 -> V_47 ) ;
return F_36 ( V_28 , V_97 ) ;
default:
F_4 ( L_29 , V_33 , V_103 ) ;
break;
}
return - V_113 ;
}
static void F_41 ( struct V_34 * V_35 , int V_114 )
{
struct V_36 * V_28 = V_35 -> V_81 ;
struct V_3 * V_4 = V_28 -> V_4 ;
T_3 V_115 ;
int V_73 ;
F_4 ( L_20 , V_33 , V_28 -> V_47 ) ;
if ( V_114 == 0 )
V_115 = V_116 ;
else
V_115 = V_117 ;
F_4 ( L_30 , V_33 ,
V_115 == V_116 ? L_31 : L_32 ) ;
V_73 = F_2 ( V_4 -> V_7 , F_6 ( V_4 -> V_7 , 0 ) ,
V_118 , V_119 , V_115 ,
0 , NULL , 0 , 100 ) ;
if ( V_73 )
F_4 ( L_33 , V_33 , V_73 ) ;
}
static void F_42 ( struct V_3 * V_4 )
{
int V_16 ;
struct V_12 * V_13 ;
F_4 ( L_34 , V_33 ) ;
for ( V_16 = 0 ; V_16 < V_4 -> V_24 ; ++ V_16 ) {
V_13 = F_14 ( V_4 -> V_28 [ V_16 ] ) ;
F_13 ( V_13 ) ;
}
}
static void F_43 ( struct V_36 * V_28 ,
unsigned char * V_120 ,
unsigned int V_121 )
{
struct V_12 * V_13 = F_14 ( V_28 ) ;
struct V_34 * V_35 ;
unsigned long V_39 ;
T_2 V_122 = V_123 ;
T_2 V_124 = V_123 + 1 ;
T_2 V_125 ;
T_3 V_126 , V_127 ;
V_126 = F_44 ( V_28 -> V_4 -> V_7 -> V_19 . V_128 ) ;
V_127 = F_44 ( V_28 -> V_4 -> V_7 -> V_19 . V_129 ) ;
if ( V_126 == V_130 ) {
if ( V_127 == V_131 ||
V_127 == V_132 ||
V_127 == V_133 ) {
V_124 = 1 ;
V_122 = 0 ;
}
}
if ( V_121 < V_124 )
return;
F_21 ( & V_13 -> V_26 , V_39 ) ;
V_125 = V_13 -> V_88 ;
V_13 -> V_88 = V_120 [ V_122 ] ;
F_22 ( & V_13 -> V_26 , V_39 ) ;
if ( V_13 -> V_88 & V_134 )
F_45 ( V_28 ) ;
F_46 ( & V_13 -> V_27 ) ;
V_35 = F_47 ( & V_28 -> V_28 ) ;
if ( ! V_35 )
return;
if ( ( V_13 -> V_88 ^ V_125 ) & V_95 )
F_48 ( V_28 , V_35 ,
V_13 -> V_88 & V_95 ) ;
F_49 ( V_35 ) ;
}
static void F_50 ( struct V_135 * V_135 )
{
struct V_36 * V_28 = V_135 -> V_136 ;
unsigned char * V_120 = V_135 -> V_137 ;
unsigned int V_121 = V_135 -> V_121 ;
int V_87 = V_135 -> V_87 ;
int V_30 ;
F_4 ( L_25 , V_33 , V_28 -> V_47 ) ;
switch ( V_87 ) {
case 0 :
break;
case - V_138 :
case - V_139 :
case - V_140 :
F_4 ( L_35 , V_33 ,
V_87 ) ;
return;
default:
F_4 ( L_36 , V_33 ,
V_87 ) ;
goto exit;
}
F_51 ( V_141 , & V_28 -> V_7 , V_33 ,
V_135 -> V_121 , V_135 -> V_137 ) ;
F_43 ( V_28 , V_120 , V_121 ) ;
exit:
V_30 = F_31 ( V_135 , V_142 ) ;
if ( V_30 )
F_18 ( & V_135 -> V_7 -> V_7 ,
L_37 ,
V_33 , V_30 ) ;
}
static void F_52 ( struct V_135 * V_135 )
{
struct V_36 * V_28 = V_135 -> V_136 ;
struct V_12 * V_13 = F_14 ( V_28 ) ;
struct V_34 * V_35 ;
unsigned char * V_120 = V_135 -> V_137 ;
char V_143 = V_144 ;
unsigned long V_39 ;
T_2 V_88 ;
int V_16 ;
F_21 ( & V_13 -> V_26 , V_39 ) ;
V_88 = V_13 -> V_88 ;
V_13 -> V_88 &= ~ V_145 ;
F_22 ( & V_13 -> V_26 , V_39 ) ;
F_46 ( & V_13 -> V_27 ) ;
if ( ! V_135 -> V_121 )
return;
V_35 = F_47 ( & V_28 -> V_28 ) ;
if ( ! V_35 )
return;
if ( V_88 & V_134 )
V_143 = V_146 ;
else if ( V_88 & V_147 )
V_143 = V_148 ;
else if ( V_88 & V_149 )
V_143 = V_150 ;
F_4 ( L_38 , V_33 , V_143 ) ;
if ( V_88 & V_151 )
F_53 ( V_35 , 0 , V_152 ) ;
if ( V_28 -> V_28 . V_153 && V_28 -> V_154 ) {
for ( V_16 = 0 ; V_16 < V_135 -> V_121 ; ++ V_16 )
if ( ! F_54 ( V_28 , V_120 [ V_16 ] ) )
F_53 ( V_35 , V_120 [ V_16 ] , V_143 ) ;
} else {
F_55 ( V_35 , V_120 , V_143 ,
V_135 -> V_121 ) ;
}
F_56 ( V_35 ) ;
F_49 ( V_35 ) ;
}
static int T_4 F_57 ( void )
{
int V_30 ;
V_30 = F_58 ( & V_155 ) ;
if ( V_30 )
goto V_156;
V_30 = F_59 ( & V_157 ) ;
if ( V_30 )
goto V_158;
F_60 (KERN_INFO KBUILD_MODNAME L_39 DRIVER_DESC L_40 ) ;
return 0 ;
V_158:
F_61 ( & V_155 ) ;
V_156:
return V_30 ;
}
static void T_5 F_62 ( void )
{
F_63 ( & V_157 ) ;
F_61 ( & V_155 ) ;
}
