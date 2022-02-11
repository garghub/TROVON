static int F_1 ( T_1 V_1 , T_1 V_2 ,
struct V_3 * V_4 , unsigned char * V_5 )
{
int V_6 = F_2 ( V_4 -> V_7 , F_3 ( V_4 -> V_7 , 0 ) ,
V_8 , V_9 ,
V_1 , V_2 , V_5 , 1 , 100 ) ;
F_4 ( & V_4 -> V_7 -> V_7 , L_1 ,
V_9 , V_8 , V_1 , V_2 ,
V_6 , V_5 [ 0 ] ) ;
return V_6 ;
}
static int F_5 ( T_1 V_1 , T_1 V_2 ,
struct V_3 * V_4 )
{
int V_6 = F_2 ( V_4 -> V_7 , F_6 ( V_4 -> V_7 , 0 ) ,
V_10 , V_11 ,
V_1 , V_2 , NULL , 0 , 100 ) ;
F_4 ( & V_4 -> V_7 -> V_7 , L_2 ,
V_11 , V_10 , V_1 , V_2 ,
V_6 ) ;
return V_6 ;
}
static int F_7 ( struct V_3 * V_4 )
{
struct V_12 * V_13 ;
enum V_14 type = V_15 ;
unsigned char * V_5 ;
V_13 = F_8 ( sizeof( * V_13 ) , V_16 ) ;
if ( ! V_13 )
return - V_17 ;
V_5 = F_9 ( 10 , V_16 ) ;
if ( ! V_5 ) {
F_10 ( V_13 ) ;
return - V_17 ;
}
if ( V_4 -> V_7 -> V_18 . V_19 == 0x02 )
type = V_15 ;
else if ( V_4 -> V_7 -> V_18 . V_20 == 0x40 )
type = V_21 ;
else if ( V_4 -> V_7 -> V_18 . V_19 == 0x00 )
type = V_22 ;
else if ( V_4 -> V_7 -> V_18 . V_19 == 0xFF )
type = V_22 ;
F_4 ( & V_4 -> V_23 -> V_7 , L_3 , type ) ;
V_13 -> type = type ;
F_11 ( V_4 , V_13 ) ;
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
if ( type == V_21 )
F_5 ( 2 , 0x44 , V_4 ) ;
else
F_5 ( 2 , 0x24 , V_4 ) ;
F_10 ( V_5 ) ;
return 0 ;
}
static void F_12 ( struct V_3 * V_4 )
{
struct V_12 * V_13 ;
V_13 = F_13 ( V_4 ) ;
F_10 ( V_13 ) ;
}
static int F_14 ( struct V_24 * V_25 )
{
struct V_26 * V_27 ;
V_27 = F_8 ( sizeof( * V_27 ) , V_16 ) ;
if ( ! V_27 )
return - V_17 ;
F_15 ( & V_27 -> V_28 ) ;
F_16 ( & V_27 -> V_29 ) ;
F_17 ( V_25 , V_27 ) ;
return 0 ;
}
static int F_18 ( struct V_24 * V_25 )
{
struct V_26 * V_27 ;
V_27 = F_19 ( V_25 ) ;
F_10 ( V_27 ) ;
return 0 ;
}
static int F_20 ( struct V_30 * V_7 , T_2 V_1 )
{
int V_31 ;
V_31 = F_2 ( V_7 , F_6 ( V_7 , 0 ) ,
V_32 , V_33 ,
V_1 , 0 , NULL , 0 , 100 ) ;
F_4 ( & V_7 -> V_7 , L_4 , V_34 ,
V_1 , V_31 ) ;
return V_31 ;
}
static void F_21 ( struct V_35 * V_36 ,
struct V_24 * V_25 , struct V_37 * V_38 )
{
struct V_3 * V_4 = V_25 -> V_4 ;
struct V_12 * V_13 = F_13 ( V_4 ) ;
struct V_26 * V_27 = F_19 ( V_25 ) ;
unsigned long V_39 ;
unsigned int V_40 ;
unsigned char * V_5 ;
int V_41 ;
int V_42 ;
T_2 V_43 ;
const int V_44 [] = { 75 , 150 , 300 , 600 , 1200 , 1800 , 2400 , 3600 ,
4800 , 7200 , 9600 , 14400 , 19200 , 28800 , 38400 ,
57600 , 115200 , 230400 , 460800 , 614400 ,
921600 , 1228800 , 2457600 , 3000000 , 6000000 } ;
int V_45 , V_46 ;
int V_47 ;
if ( ! F_22 ( & V_36 -> V_48 , V_38 ) )
return;
V_40 = V_36 -> V_48 . V_49 ;
V_5 = F_8 ( 7 , V_16 ) ;
if ( ! V_5 ) {
F_23 ( & V_25 -> V_7 , L_5 , V_34 ) ;
V_36 -> V_48 = * V_38 ;
return;
}
V_42 = F_2 ( V_4 -> V_7 , F_3 ( V_4 -> V_7 , 0 ) ,
V_50 , V_51 ,
0 , 0 , V_5 , 7 , 100 ) ;
F_4 ( & V_25 -> V_7 , L_6 , V_42 ,
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
F_4 ( & V_25 -> V_7 , L_7 , V_5 [ 6 ] ) ;
}
V_41 = F_24 ( V_36 ) ;
F_4 ( & V_25 -> V_7 , L_8 , V_41 ) ;
if ( V_41 ) {
for ( V_47 = 0 ; V_47 < F_25 ( V_44 ) ; V_47 ++ ) {
if ( V_44 [ V_47 ] / V_41 ) {
V_46 = V_44 [ V_47 ] ;
if ( V_47 == 0 ) {
V_41 = V_46 ;
} else {
V_45 = V_44 [ V_47 - 1 ] ;
if ( ( V_46 % V_41 )
> ( V_41 % V_45 ) )
V_41 = V_45 ;
else
V_41 = V_46 ;
}
break;
}
}
if ( V_41 > 1228800 ) {
if ( V_13 -> type != V_21 )
V_41 = 1228800 ;
else if ( V_41 > 6000000 )
V_41 = 6000000 ;
}
F_4 ( & V_25 -> V_7 , L_9 , V_41 ) ;
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
F_4 ( & V_25 -> V_7 , L_10 ) ;
} else {
V_5 [ 4 ] = 2 ;
F_4 ( & V_25 -> V_7 , L_11 ) ;
}
} else {
V_5 [ 4 ] = 0 ;
F_4 ( & V_25 -> V_7 , L_12 ) ;
}
if ( V_40 & V_59 ) {
if ( V_40 & V_60 ) {
if ( V_40 & V_61 ) {
V_5 [ 5 ] = 3 ;
F_4 ( & V_25 -> V_7 , L_13 ) ;
} else {
V_5 [ 5 ] = 1 ;
F_4 ( & V_25 -> V_7 , L_14 ) ;
}
} else {
if ( V_40 & V_61 ) {
V_5 [ 5 ] = 4 ;
F_4 ( & V_25 -> V_7 , L_15 ) ;
} else {
V_5 [ 5 ] = 2 ;
F_4 ( & V_25 -> V_7 , L_16 ) ;
}
}
} else {
V_5 [ 5 ] = 0 ;
F_4 ( & V_25 -> V_7 , L_17 ) ;
}
V_42 = F_2 ( V_4 -> V_7 , F_6 ( V_4 -> V_7 , 0 ) ,
V_62 , V_63 ,
0 , 0 , V_5 , 7 , 100 ) ;
F_4 ( & V_25 -> V_7 , L_18 , V_42 ) ;
F_26 ( & V_27 -> V_28 , V_39 ) ;
V_43 = V_27 -> V_64 ;
if ( ( V_40 & V_65 ) == V_66 )
V_27 -> V_64 &= ~ ( V_67 | V_68 ) ;
else if ( ( V_38 -> V_49 & V_65 ) == V_66 )
V_27 -> V_64 |= ( V_67 | V_68 ) ;
if ( V_43 != V_27 -> V_64 ) {
V_43 = V_27 -> V_64 ;
F_27 ( & V_27 -> V_28 , V_39 ) ;
F_20 ( V_4 -> V_7 , V_43 ) ;
} else {
F_27 ( & V_27 -> V_28 , V_39 ) ;
}
V_5 [ 0 ] = V_5 [ 1 ] = V_5 [ 2 ] = V_5 [ 3 ] = V_5 [ 4 ] = V_5 [ 5 ] = V_5 [ 6 ] = 0 ;
V_42 = F_2 ( V_4 -> V_7 , F_3 ( V_4 -> V_7 , 0 ) ,
V_50 , V_51 ,
0 , 0 , V_5 , 7 , 100 ) ;
F_4 ( & V_25 -> V_7 , L_6 , V_42 ,
V_5 [ 0 ] , V_5 [ 1 ] , V_5 [ 2 ] , V_5 [ 3 ] , V_5 [ 4 ] , V_5 [ 5 ] , V_5 [ 6 ] ) ;
if ( V_40 & V_69 ) {
if ( V_13 -> type == V_21 )
F_5 ( 0x0 , 0x61 , V_4 ) ;
else
F_5 ( 0x0 , 0x41 , V_4 ) ;
} else {
F_5 ( 0x0 , 0x0 , V_4 ) ;
}
if ( V_41 )
F_28 ( V_36 , V_41 , V_41 ) ;
F_10 ( V_5 ) ;
}
static void F_29 ( struct V_24 * V_25 , int V_70 )
{
struct V_26 * V_27 = F_19 ( V_25 ) ;
unsigned long V_39 ;
T_2 V_43 ;
F_26 ( & V_27 -> V_28 , V_39 ) ;
if ( V_70 )
V_27 -> V_64 |= ( V_67 | V_68 ) ;
else
V_27 -> V_64 &= ~ ( V_67 | V_68 ) ;
V_43 = V_27 -> V_64 ;
F_27 ( & V_27 -> V_28 , V_39 ) ;
F_20 ( V_25 -> V_4 -> V_7 , V_43 ) ;
}
static void F_30 ( struct V_24 * V_25 )
{
F_31 ( V_25 ) ;
F_32 ( V_25 -> V_71 ) ;
}
static int F_33 ( struct V_35 * V_36 , struct V_24 * V_25 )
{
struct V_37 V_72 ;
struct V_3 * V_4 = V_25 -> V_4 ;
struct V_12 * V_13 = F_13 ( V_4 ) ;
int V_73 ;
if ( V_13 -> type != V_21 ) {
F_34 ( V_4 -> V_7 , V_25 -> V_74 -> V_75 ) ;
F_34 ( V_4 -> V_7 , V_25 -> V_76 -> V_75 ) ;
} else {
F_5 ( 8 , 0 , V_4 ) ;
F_5 ( 9 , 0 , V_4 ) ;
}
if ( V_36 )
F_21 ( V_36 , V_25 , & V_72 ) ;
V_73 = F_35 ( V_25 -> V_71 , V_16 ) ;
if ( V_73 ) {
F_23 ( & V_25 -> V_7 , L_19
L_20 , V_34 , V_73 ) ;
return V_73 ;
}
V_73 = F_36 ( V_36 , V_25 ) ;
if ( V_73 ) {
F_32 ( V_25 -> V_71 ) ;
return V_73 ;
}
V_25 -> V_25 . V_77 = 256 ;
return 0 ;
}
static int F_37 ( struct V_35 * V_36 ,
unsigned int V_78 , unsigned int V_79 )
{
struct V_24 * V_25 = V_36 -> V_80 ;
struct V_3 * V_4 = V_25 -> V_4 ;
struct V_26 * V_27 = F_19 ( V_25 ) ;
unsigned long V_39 ;
T_2 V_43 ;
int V_81 ;
F_26 ( & V_27 -> V_28 , V_39 ) ;
if ( V_78 & V_82 )
V_27 -> V_64 |= V_68 ;
if ( V_78 & V_83 )
V_27 -> V_64 |= V_67 ;
if ( V_79 & V_82 )
V_27 -> V_64 &= ~ V_68 ;
if ( V_79 & V_83 )
V_27 -> V_64 &= ~ V_67 ;
V_43 = V_27 -> V_64 ;
F_27 ( & V_27 -> V_28 , V_39 ) ;
F_38 ( & V_4 -> V_84 ) ;
if ( ! V_4 -> V_85 )
V_81 = F_20 ( V_4 -> V_7 , V_43 ) ;
else
V_81 = - V_86 ;
F_39 ( & V_4 -> V_84 ) ;
return V_81 ;
}
static int F_40 ( struct V_35 * V_36 )
{
struct V_24 * V_25 = V_36 -> V_80 ;
struct V_26 * V_27 = F_19 ( V_25 ) ;
unsigned long V_39 ;
unsigned int V_87 ;
unsigned int V_88 ;
unsigned int V_73 ;
F_26 ( & V_27 -> V_28 , V_39 ) ;
V_87 = V_27 -> V_64 ;
V_88 = V_27 -> V_89 ;
F_27 ( & V_27 -> V_28 , V_39 ) ;
V_73 = ( ( V_87 & V_67 ) ? V_83 : 0 )
| ( ( V_87 & V_68 ) ? V_82 : 0 )
| ( ( V_88 & V_90 ) ? V_91 : 0 )
| ( ( V_88 & V_92 ) ? V_93 : 0 )
| ( ( V_88 & V_94 ) ? V_95 : 0 )
| ( ( V_88 & V_96 ) ? V_97 : 0 ) ;
F_4 ( & V_25 -> V_7 , L_21 , V_34 , V_73 ) ;
return V_73 ;
}
static int F_41 ( struct V_24 * V_25 )
{
struct V_26 * V_27 = F_19 ( V_25 ) ;
if ( V_27 -> V_89 & V_96 )
return 1 ;
return 0 ;
}
static int F_42 ( struct V_24 * V_25 , unsigned int V_98 )
{
struct V_26 * V_27 = F_19 ( V_25 ) ;
unsigned long V_39 ;
unsigned int V_99 ;
unsigned int V_88 ;
unsigned int V_100 ;
F_26 ( & V_27 -> V_28 , V_39 ) ;
V_99 = V_27 -> V_89 ;
F_27 ( & V_27 -> V_28 , V_39 ) ;
while ( 1 ) {
F_43 ( & V_27 -> V_29 ) ;
if ( F_44 ( V_101 ) )
return - V_102 ;
F_26 ( & V_27 -> V_28 , V_39 ) ;
V_88 = V_27 -> V_89 ;
F_27 ( & V_27 -> V_28 , V_39 ) ;
V_100 = V_99 ^ V_88 ;
if ( ( ( V_98 & V_103 ) && ( V_100 & V_94 ) ) ||
( ( V_98 & V_93 ) && ( V_100 & V_92 ) ) ||
( ( V_98 & V_97 ) && ( V_100 & V_96 ) ) ||
( ( V_98 & V_91 ) && ( V_100 & V_90 ) ) ) {
return 0 ;
}
V_99 = V_88 ;
}
return 0 ;
}
static int F_45 ( struct V_35 * V_36 ,
unsigned int V_104 , unsigned long V_98 )
{
struct V_105 V_106 ;
struct V_24 * V_25 = V_36 -> V_80 ;
F_4 ( & V_25 -> V_7 , L_22 , V_34 , V_104 ) ;
switch ( V_104 ) {
case V_107 :
memset ( & V_106 , 0 , sizeof V_106 ) ;
V_106 . type = V_108 ;
V_106 . line = V_25 -> V_4 -> V_109 ;
V_106 . V_25 = V_25 -> V_110 ;
V_106 . V_111 = 460800 ;
if ( F_46 ( ( void V_112 * ) V_98 , & V_106 , sizeof V_106 ) )
return - V_113 ;
return 0 ;
case V_114 :
F_4 ( & V_25 -> V_7 , L_23 , V_34 ) ;
return F_42 ( V_25 , V_98 ) ;
default:
F_4 ( & V_25 -> V_7 , L_24 , V_34 , V_104 ) ;
break;
}
return - V_115 ;
}
static void F_47 ( struct V_35 * V_36 , int V_116 )
{
struct V_24 * V_25 = V_36 -> V_80 ;
struct V_3 * V_4 = V_25 -> V_4 ;
T_3 V_117 ;
int V_73 ;
if ( V_116 == 0 )
V_117 = V_118 ;
else
V_117 = V_119 ;
F_4 ( & V_25 -> V_7 , L_25 , V_34 ,
V_117 == V_118 ? L_26 : L_27 ) ;
V_73 = F_2 ( V_4 -> V_7 , F_6 ( V_4 -> V_7 , 0 ) ,
V_120 , V_121 , V_117 ,
0 , NULL , 0 , 100 ) ;
if ( V_73 )
F_23 ( & V_25 -> V_7 , L_28 , V_73 ) ;
}
static void F_48 ( struct V_24 * V_25 ,
unsigned char * V_122 ,
unsigned int V_123 )
{
struct V_26 * V_27 = F_19 ( V_25 ) ;
struct V_35 * V_36 ;
unsigned long V_39 ;
T_2 V_124 = V_125 ;
T_2 V_126 = V_125 + 1 ;
T_2 V_127 ;
T_3 V_128 , V_129 ;
V_128 = F_49 ( V_25 -> V_4 -> V_7 -> V_18 . V_130 ) ;
V_129 = F_49 ( V_25 -> V_4 -> V_7 -> V_18 . V_131 ) ;
if ( V_128 == V_132 ) {
if ( V_129 == V_133 ||
V_129 == V_134 ||
V_129 == V_135 ) {
V_126 = 1 ;
V_124 = 0 ;
}
}
if ( V_123 < V_126 )
return;
F_26 ( & V_27 -> V_28 , V_39 ) ;
V_127 = V_27 -> V_89 ;
V_27 -> V_89 = V_122 [ V_124 ] ;
F_27 ( & V_27 -> V_28 , V_39 ) ;
if ( V_27 -> V_89 & V_136 )
F_50 ( V_25 ) ;
F_51 ( & V_27 -> V_29 ) ;
V_36 = F_52 ( & V_25 -> V_25 ) ;
if ( ! V_36 )
return;
if ( ( V_27 -> V_89 ^ V_127 ) & V_96 )
F_53 ( V_25 , V_36 ,
V_27 -> V_89 & V_96 ) ;
F_54 ( V_36 ) ;
}
static void F_55 ( struct V_137 * V_137 )
{
struct V_24 * V_25 = V_137 -> V_138 ;
unsigned char * V_122 = V_137 -> V_139 ;
unsigned int V_123 = V_137 -> V_123 ;
int V_88 = V_137 -> V_88 ;
int V_31 ;
switch ( V_88 ) {
case 0 :
break;
case - V_140 :
case - V_141 :
case - V_142 :
F_4 ( & V_25 -> V_7 , L_29 ,
V_34 , V_88 ) ;
return;
default:
F_4 ( & V_25 -> V_7 , L_30 ,
V_34 , V_88 ) ;
goto exit;
}
F_56 ( & V_25 -> V_7 , V_34 ,
V_137 -> V_123 , V_137 -> V_139 ) ;
F_48 ( V_25 , V_122 , V_123 ) ;
exit:
V_31 = F_35 ( V_137 , V_143 ) ;
if ( V_31 )
F_23 ( & V_25 -> V_7 ,
L_31 ,
V_34 , V_31 ) ;
}
static void F_57 ( struct V_137 * V_137 )
{
struct V_24 * V_25 = V_137 -> V_138 ;
struct V_26 * V_27 = F_19 ( V_25 ) ;
struct V_35 * V_36 ;
unsigned char * V_122 = V_137 -> V_139 ;
char V_144 = V_145 ;
unsigned long V_39 ;
T_2 V_89 ;
int V_42 ;
F_26 ( & V_27 -> V_28 , V_39 ) ;
V_89 = V_27 -> V_89 ;
V_27 -> V_89 &= ~ V_146 ;
F_27 ( & V_27 -> V_28 , V_39 ) ;
F_51 ( & V_27 -> V_29 ) ;
if ( ! V_137 -> V_123 )
return;
V_36 = F_52 ( & V_25 -> V_25 ) ;
if ( ! V_36 )
return;
if ( V_89 & V_136 )
V_144 = V_147 ;
else if ( V_89 & V_148 )
V_144 = V_149 ;
else if ( V_89 & V_150 )
V_144 = V_151 ;
F_4 ( & V_25 -> V_7 , L_32 , V_34 , V_144 ) ;
if ( V_89 & V_152 )
F_58 ( V_36 , 0 , V_153 ) ;
if ( V_25 -> V_25 . V_154 && V_25 -> V_155 ) {
for ( V_42 = 0 ; V_42 < V_137 -> V_123 ; ++ V_42 )
if ( ! F_59 ( V_25 , V_122 [ V_42 ] ) )
F_58 ( V_36 , V_122 [ V_42 ] , V_144 ) ;
} else {
F_60 ( V_36 , V_122 , V_144 ,
V_137 -> V_123 ) ;
}
F_61 ( V_36 ) ;
F_54 ( V_36 ) ;
}
