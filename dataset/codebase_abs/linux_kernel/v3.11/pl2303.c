static int F_1 ( T_1 V_1 , T_1 V_2 ,
struct V_3 * V_4 , unsigned char * V_5 )
{
int V_6 = F_2 ( V_4 -> V_7 , F_3 ( V_4 -> V_7 , 0 ) ,
V_8 , V_9 ,
V_1 , V_2 , V_5 , 1 , 100 ) ;
F_4 ( & V_4 -> V_10 -> V_7 , L_1 ,
V_9 , V_8 , V_1 , V_2 ,
V_6 , V_5 [ 0 ] ) ;
return V_6 ;
}
static int F_5 ( T_1 V_1 , T_1 V_2 ,
struct V_3 * V_4 )
{
int V_6 = F_2 ( V_4 -> V_7 , F_6 ( V_4 -> V_7 , 0 ) ,
V_11 , V_12 ,
V_1 , V_2 , NULL , 0 , 100 ) ;
F_4 ( & V_4 -> V_10 -> V_7 , L_2 ,
V_12 , V_11 , V_1 , V_2 ,
V_6 ) ;
return V_6 ;
}
static int F_7 ( struct V_3 * V_4 )
{
struct V_13 * V_14 ;
enum V_15 type = V_16 ;
unsigned char * V_5 ;
V_14 = F_8 ( sizeof( * V_14 ) , V_17 ) ;
if ( ! V_14 )
return - V_18 ;
V_5 = F_9 ( 10 , V_17 ) ;
if ( ! V_5 ) {
F_10 ( V_14 ) ;
return - V_18 ;
}
if ( V_4 -> V_7 -> V_19 . V_20 == 0x02 )
type = V_16 ;
else if ( V_4 -> V_7 -> V_19 . V_21 == 0x40 )
type = V_22 ;
else if ( V_4 -> V_7 -> V_19 . V_20 == 0x00 )
type = V_23 ;
else if ( V_4 -> V_7 -> V_19 . V_20 == 0xFF )
type = V_23 ;
F_4 ( & V_4 -> V_10 -> V_7 , L_3 , type ) ;
V_14 -> type = type ;
F_11 ( V_4 , V_14 ) ;
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
F_10 ( V_5 ) ;
return 0 ;
}
static void F_12 ( struct V_3 * V_4 )
{
struct V_13 * V_14 ;
V_14 = F_13 ( V_4 ) ;
F_10 ( V_14 ) ;
}
static int F_14 ( struct V_24 * V_25 )
{
struct V_26 * V_27 ;
V_27 = F_8 ( sizeof( * V_27 ) , V_17 ) ;
if ( ! V_27 )
return - V_18 ;
F_15 ( & V_27 -> V_28 ) ;
F_16 ( V_25 , V_27 ) ;
return 0 ;
}
static int F_17 ( struct V_24 * V_25 )
{
struct V_26 * V_27 ;
V_27 = F_18 ( V_25 ) ;
F_10 ( V_27 ) ;
return 0 ;
}
static int F_19 ( struct V_24 * V_25 , T_2 V_1 )
{
struct V_29 * V_7 = V_25 -> V_4 -> V_7 ;
int V_30 ;
V_30 = F_2 ( V_7 , F_6 ( V_7 , 0 ) ,
V_31 , V_32 ,
V_1 , 0 , NULL , 0 , 100 ) ;
F_4 ( & V_25 -> V_7 , L_4 , V_33 ,
V_1 , V_30 ) ;
return V_30 ;
}
static void F_20 ( struct V_34 * V_35 ,
struct V_24 * V_25 , struct V_36 * V_37 )
{
struct V_3 * V_4 = V_25 -> V_4 ;
struct V_13 * V_14 = F_13 ( V_4 ) ;
struct V_26 * V_27 = F_18 ( V_25 ) ;
unsigned long V_38 ;
unsigned int V_39 ;
unsigned char * V_5 ;
int V_40 ;
int V_41 ;
T_2 V_42 ;
const int V_43 [] = { 75 , 150 , 300 , 600 , 1200 , 1800 , 2400 , 3600 ,
4800 , 7200 , 9600 , 14400 , 19200 , 28800 , 38400 ,
57600 , 115200 , 230400 , 460800 , 500000 , 614400 ,
921600 , 1228800 , 2457600 , 3000000 , 6000000 } ;
int V_44 , V_45 ;
int V_46 ;
if ( V_37 && ! F_21 ( & V_35 -> V_47 , V_37 ) )
return;
V_39 = V_35 -> V_47 . V_48 ;
V_5 = F_8 ( 7 , V_17 ) ;
if ( ! V_5 ) {
F_22 ( & V_25 -> V_7 , L_5 , V_33 ) ;
if ( V_37 )
V_35 -> V_47 = * V_37 ;
return;
}
V_41 = F_2 ( V_4 -> V_7 , F_3 ( V_4 -> V_7 , 0 ) ,
V_49 , V_50 ,
0 , 0 , V_5 , 7 , 100 ) ;
F_4 ( & V_25 -> V_7 , L_6 , V_41 , V_5 ) ;
if ( V_39 & V_51 ) {
switch ( V_39 & V_51 ) {
case V_52 :
V_5 [ 6 ] = 5 ;
break;
case V_53 :
V_5 [ 6 ] = 6 ;
break;
case V_54 :
V_5 [ 6 ] = 7 ;
break;
default:
case V_55 :
V_5 [ 6 ] = 8 ;
break;
}
F_4 ( & V_25 -> V_7 , L_7 , V_5 [ 6 ] ) ;
}
V_40 = F_23 ( V_35 ) ;
F_4 ( & V_25 -> V_7 , L_8 , V_40 ) ;
if ( V_40 ) {
for ( V_46 = 0 ; V_46 < F_24 ( V_43 ) ; V_46 ++ ) {
if ( V_43 [ V_46 ] / V_40 ) {
V_45 = V_43 [ V_46 ] ;
if ( V_46 == 0 ) {
V_40 = V_45 ;
} else {
V_44 = V_43 [ V_46 - 1 ] ;
if ( ( V_45 % V_40 )
> ( V_40 % V_44 ) )
V_40 = V_44 ;
else
V_40 = V_45 ;
}
break;
}
}
if ( V_40 > 1228800 ) {
if ( V_14 -> type != V_22 )
V_40 = 1228800 ;
else if ( V_40 > 6000000 )
V_40 = 6000000 ;
}
F_4 ( & V_25 -> V_7 , L_9 , V_40 ) ;
if ( V_40 <= 115200 ) {
V_5 [ 0 ] = V_40 & 0xff ;
V_5 [ 1 ] = ( V_40 >> 8 ) & 0xff ;
V_5 [ 2 ] = ( V_40 >> 16 ) & 0xff ;
V_5 [ 3 ] = ( V_40 >> 24 ) & 0xff ;
} else {
unsigned V_56 = 12 * 1000 * 1000 * 32 / V_40 ;
V_5 [ 3 ] = 0x80 ;
V_5 [ 2 ] = 0 ;
V_5 [ 1 ] = ( V_56 >= 256 ) ;
while ( V_56 >= 256 ) {
V_56 >>= 2 ;
V_5 [ 1 ] <<= 1 ;
}
V_5 [ 0 ] = V_56 ;
}
}
if ( V_39 & V_57 ) {
if ( ( V_39 & V_51 ) == V_52 ) {
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
if ( V_39 & V_58 ) {
if ( V_39 & V_59 ) {
if ( V_39 & V_60 ) {
V_5 [ 5 ] = 3 ;
F_4 ( & V_25 -> V_7 , L_13 ) ;
} else {
V_5 [ 5 ] = 1 ;
F_4 ( & V_25 -> V_7 , L_14 ) ;
}
} else {
if ( V_39 & V_60 ) {
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
V_41 = F_2 ( V_4 -> V_7 , F_6 ( V_4 -> V_7 , 0 ) ,
V_61 , V_62 ,
0 , 0 , V_5 , 7 , 100 ) ;
F_4 ( & V_25 -> V_7 , L_18 , V_41 ) ;
F_25 ( & V_27 -> V_28 , V_38 ) ;
V_42 = V_27 -> V_63 ;
if ( ( V_39 & V_64 ) == V_65 )
V_27 -> V_63 &= ~ ( V_66 | V_67 ) ;
else if ( V_37 && ( V_37 -> V_48 & V_64 ) == V_65 )
V_27 -> V_63 |= ( V_66 | V_67 ) ;
if ( V_42 != V_27 -> V_63 ) {
V_42 = V_27 -> V_63 ;
F_26 ( & V_27 -> V_28 , V_38 ) ;
F_19 ( V_25 , V_42 ) ;
} else {
F_26 ( & V_27 -> V_28 , V_38 ) ;
}
V_5 [ 0 ] = V_5 [ 1 ] = V_5 [ 2 ] = V_5 [ 3 ] = V_5 [ 4 ] = V_5 [ 5 ] = V_5 [ 6 ] = 0 ;
V_41 = F_2 ( V_4 -> V_7 , F_3 ( V_4 -> V_7 , 0 ) ,
V_49 , V_50 ,
0 , 0 , V_5 , 7 , 100 ) ;
F_4 ( & V_25 -> V_7 , L_6 , V_41 , V_5 ) ;
if ( V_39 & V_68 ) {
if ( V_14 -> type == V_22 )
F_5 ( 0x0 , 0x61 , V_4 ) ;
else
F_5 ( 0x0 , 0x41 , V_4 ) ;
} else {
F_5 ( 0x0 , 0x0 , V_4 ) ;
}
if ( V_40 )
F_27 ( V_35 , V_40 , V_40 ) ;
F_10 ( V_5 ) ;
}
static void F_28 ( struct V_24 * V_25 , int V_69 )
{
struct V_26 * V_27 = F_18 ( V_25 ) ;
unsigned long V_38 ;
T_2 V_42 ;
F_25 ( & V_27 -> V_28 , V_38 ) ;
if ( V_69 )
V_27 -> V_63 |= ( V_66 | V_67 ) ;
else
V_27 -> V_63 &= ~ ( V_66 | V_67 ) ;
V_42 = V_27 -> V_63 ;
F_26 ( & V_27 -> V_28 , V_38 ) ;
F_19 ( V_25 , V_42 ) ;
}
static void F_29 ( struct V_24 * V_25 )
{
F_30 ( V_25 ) ;
F_31 ( V_25 -> V_70 ) ;
}
static int F_32 ( struct V_34 * V_35 , struct V_24 * V_25 )
{
struct V_3 * V_4 = V_25 -> V_4 ;
struct V_13 * V_14 = F_13 ( V_4 ) ;
int V_71 ;
if ( V_14 -> type != V_22 ) {
F_33 ( V_4 -> V_7 , V_25 -> V_72 -> V_73 ) ;
F_33 ( V_4 -> V_7 , V_25 -> V_74 -> V_73 ) ;
} else {
F_5 ( 8 , 0 , V_4 ) ;
F_5 ( 9 , 0 , V_4 ) ;
}
if ( V_35 )
F_20 ( V_35 , V_25 , NULL ) ;
V_71 = F_34 ( V_25 -> V_70 , V_17 ) ;
if ( V_71 ) {
F_22 ( & V_25 -> V_7 , L_19
L_20 , V_33 , V_71 ) ;
return V_71 ;
}
V_71 = F_35 ( V_35 , V_25 ) ;
if ( V_71 ) {
F_31 ( V_25 -> V_70 ) ;
return V_71 ;
}
V_25 -> V_25 . V_75 = 256 ;
return 0 ;
}
static int F_36 ( struct V_34 * V_35 ,
unsigned int V_76 , unsigned int V_77 )
{
struct V_24 * V_25 = V_35 -> V_78 ;
struct V_26 * V_27 = F_18 ( V_25 ) ;
unsigned long V_38 ;
T_2 V_42 ;
int V_79 ;
F_25 ( & V_27 -> V_28 , V_38 ) ;
if ( V_76 & V_80 )
V_27 -> V_63 |= V_67 ;
if ( V_76 & V_81 )
V_27 -> V_63 |= V_66 ;
if ( V_77 & V_80 )
V_27 -> V_63 &= ~ V_67 ;
if ( V_77 & V_81 )
V_27 -> V_63 &= ~ V_66 ;
V_42 = V_27 -> V_63 ;
F_26 ( & V_27 -> V_28 , V_38 ) ;
V_79 = F_19 ( V_25 , V_42 ) ;
if ( V_79 )
return F_37 ( V_79 ) ;
return 0 ;
}
static int F_38 ( struct V_34 * V_35 )
{
struct V_24 * V_25 = V_35 -> V_78 ;
struct V_26 * V_27 = F_18 ( V_25 ) ;
unsigned long V_38 ;
unsigned int V_82 ;
unsigned int V_83 ;
unsigned int V_71 ;
F_25 ( & V_27 -> V_28 , V_38 ) ;
V_82 = V_27 -> V_63 ;
V_83 = V_27 -> V_84 ;
F_26 ( & V_27 -> V_28 , V_38 ) ;
V_71 = ( ( V_82 & V_66 ) ? V_81 : 0 )
| ( ( V_82 & V_67 ) ? V_80 : 0 )
| ( ( V_83 & V_85 ) ? V_86 : 0 )
| ( ( V_83 & V_87 ) ? V_88 : 0 )
| ( ( V_83 & V_89 ) ? V_90 : 0 )
| ( ( V_83 & V_91 ) ? V_92 : 0 ) ;
F_4 ( & V_25 -> V_7 , L_21 , V_33 , V_71 ) ;
return V_71 ;
}
static int F_39 ( struct V_24 * V_25 )
{
struct V_26 * V_27 = F_18 ( V_25 ) ;
if ( V_27 -> V_84 & V_91 )
return 1 ;
return 0 ;
}
static int F_40 ( struct V_34 * V_35 , unsigned long V_93 )
{
struct V_24 * V_25 = V_35 -> V_78 ;
struct V_26 * V_27 = F_18 ( V_25 ) ;
unsigned long V_38 ;
unsigned int V_94 ;
unsigned int V_83 ;
unsigned int V_95 ;
F_25 ( & V_27 -> V_28 , V_38 ) ;
V_94 = V_27 -> V_84 ;
F_26 ( & V_27 -> V_28 , V_38 ) ;
while ( 1 ) {
F_41 ( & V_25 -> V_25 . V_96 ) ;
if ( F_42 ( V_97 ) )
return - V_98 ;
if ( V_25 -> V_4 -> V_99 )
return - V_100 ;
F_25 ( & V_27 -> V_28 , V_38 ) ;
V_83 = V_27 -> V_84 ;
F_26 ( & V_27 -> V_28 , V_38 ) ;
V_95 = V_94 ^ V_83 ;
if ( ( ( V_93 & V_101 ) && ( V_95 & V_89 ) ) ||
( ( V_93 & V_88 ) && ( V_95 & V_87 ) ) ||
( ( V_93 & V_92 ) && ( V_95 & V_91 ) ) ||
( ( V_93 & V_86 ) && ( V_95 & V_85 ) ) ) {
return 0 ;
}
V_94 = V_83 ;
}
return 0 ;
}
static int F_43 ( struct V_34 * V_35 ,
unsigned int V_102 , unsigned long V_93 )
{
struct V_103 V_104 ;
struct V_24 * V_25 = V_35 -> V_78 ;
F_4 ( & V_25 -> V_7 , L_22 , V_33 , V_102 ) ;
switch ( V_102 ) {
case V_105 :
memset ( & V_104 , 0 , sizeof V_104 ) ;
V_104 . type = V_106 ;
V_104 . line = V_25 -> V_107 ;
V_104 . V_25 = V_25 -> V_108 ;
V_104 . V_109 = 460800 ;
if ( F_44 ( ( void V_110 * ) V_93 , & V_104 , sizeof V_104 ) )
return - V_111 ;
return 0 ;
default:
F_4 ( & V_25 -> V_7 , L_23 , V_33 , V_102 ) ;
break;
}
return - V_112 ;
}
static void F_45 ( struct V_34 * V_35 , int V_113 )
{
struct V_24 * V_25 = V_35 -> V_78 ;
struct V_3 * V_4 = V_25 -> V_4 ;
T_3 V_114 ;
int V_71 ;
if ( V_113 == 0 )
V_114 = V_115 ;
else
V_114 = V_116 ;
F_4 ( & V_25 -> V_7 , L_24 , V_33 ,
V_114 == V_115 ? L_25 : L_26 ) ;
V_71 = F_2 ( V_4 -> V_7 , F_6 ( V_4 -> V_7 , 0 ) ,
V_117 , V_118 , V_114 ,
0 , NULL , 0 , 100 ) ;
if ( V_71 )
F_22 ( & V_25 -> V_7 , L_27 , V_71 ) ;
}
static void F_46 ( struct V_24 * V_25 ,
unsigned char * V_119 ,
unsigned int V_120 )
{
struct V_26 * V_27 = F_18 ( V_25 ) ;
struct V_34 * V_35 ;
unsigned long V_38 ;
T_2 V_121 = V_122 ;
T_2 V_123 = V_122 + 1 ;
T_2 V_124 ;
T_3 V_125 , V_126 ;
V_125 = F_47 ( V_25 -> V_4 -> V_7 -> V_19 . V_127 ) ;
V_126 = F_47 ( V_25 -> V_4 -> V_7 -> V_19 . V_128 ) ;
if ( V_125 == V_129 ) {
if ( V_126 == V_130 ||
V_126 == V_131 ||
V_126 == V_132 ) {
V_123 = 1 ;
V_121 = 0 ;
}
}
if ( V_120 < V_123 )
return;
F_25 ( & V_27 -> V_28 , V_38 ) ;
V_124 = V_27 -> V_84 ;
V_27 -> V_84 = V_119 [ V_121 ] ;
F_26 ( & V_27 -> V_28 , V_38 ) ;
if ( V_27 -> V_84 & V_133 )
F_48 ( V_25 ) ;
F_49 ( & V_25 -> V_25 . V_96 ) ;
V_35 = F_50 ( & V_25 -> V_25 ) ;
if ( ! V_35 )
return;
if ( ( V_27 -> V_84 ^ V_124 ) & V_91 )
F_51 ( V_25 , V_35 ,
V_27 -> V_84 & V_91 ) ;
F_52 ( V_35 ) ;
}
static void F_53 ( struct V_134 * V_134 )
{
struct V_24 * V_25 = V_134 -> V_135 ;
unsigned char * V_119 = V_134 -> V_136 ;
unsigned int V_120 = V_134 -> V_120 ;
int V_83 = V_134 -> V_83 ;
int V_30 ;
switch ( V_83 ) {
case 0 :
break;
case - V_137 :
case - V_138 :
case - V_139 :
F_4 ( & V_25 -> V_7 , L_28 ,
V_33 , V_83 ) ;
return;
default:
F_4 ( & V_25 -> V_7 , L_29 ,
V_33 , V_83 ) ;
goto exit;
}
F_54 ( & V_25 -> V_7 , V_33 ,
V_134 -> V_120 , V_134 -> V_136 ) ;
F_46 ( V_25 , V_119 , V_120 ) ;
exit:
V_30 = F_34 ( V_134 , V_140 ) ;
if ( V_30 )
F_22 ( & V_25 -> V_7 ,
L_30 ,
V_33 , V_30 ) ;
}
static void F_55 ( struct V_134 * V_134 )
{
struct V_24 * V_25 = V_134 -> V_135 ;
struct V_26 * V_27 = F_18 ( V_25 ) ;
unsigned char * V_119 = V_134 -> V_136 ;
char V_141 = V_142 ;
unsigned long V_38 ;
T_2 V_84 ;
int V_41 ;
F_25 ( & V_27 -> V_28 , V_38 ) ;
V_84 = V_27 -> V_84 ;
V_27 -> V_84 &= ~ V_143 ;
F_26 ( & V_27 -> V_28 , V_38 ) ;
F_49 ( & V_25 -> V_25 . V_96 ) ;
if ( ! V_134 -> V_120 )
return;
if ( V_84 & V_133 )
V_141 = V_144 ;
else if ( V_84 & V_145 )
V_141 = V_146 ;
else if ( V_84 & V_147 )
V_141 = V_148 ;
F_4 ( & V_25 -> V_7 , L_31 , V_33 , V_141 ) ;
if ( V_84 & V_149 )
F_56 ( & V_25 -> V_25 , 0 , V_150 ) ;
if ( V_25 -> V_25 . V_151 && V_25 -> V_152 ) {
for ( V_41 = 0 ; V_41 < V_134 -> V_120 ; ++ V_41 )
if ( ! F_57 ( V_25 , V_119 [ V_41 ] ) )
F_56 ( & V_25 -> V_25 , V_119 [ V_41 ] ,
V_141 ) ;
} else {
F_58 ( & V_25 -> V_25 , V_119 , V_141 ,
V_134 -> V_120 ) ;
}
F_59 ( & V_25 -> V_25 ) ;
}
