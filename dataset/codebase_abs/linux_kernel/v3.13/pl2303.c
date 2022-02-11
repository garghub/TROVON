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
V_25 -> V_25 . V_29 = 256 ;
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
struct V_30 * V_7 = V_25 -> V_4 -> V_7 ;
int V_31 ;
V_31 = F_2 ( V_7 , F_6 ( V_7 , 0 ) ,
V_32 , V_33 ,
V_1 , 0 , NULL , 0 , 100 ) ;
F_4 ( & V_25 -> V_7 , L_4 , V_34 ,
V_1 , V_31 ) ;
return V_31 ;
}
static void F_20 ( struct V_35 * V_36 ,
struct V_24 * V_25 ,
T_2 V_5 [ 4 ] )
{
const int V_37 [] = { 75 , 150 , 300 , 600 , 1200 , 1800 , 2400 , 3600 ,
4800 , 7200 , 9600 , 14400 , 19200 , 28800 , 38400 ,
57600 , 115200 , 230400 , 460800 , 500000 , 614400 ,
921600 , 1228800 , 2457600 , 3000000 , 6000000 } ;
struct V_3 * V_4 = V_25 -> V_4 ;
struct V_13 * V_14 = F_13 ( V_4 ) ;
int V_38 ;
int V_39 ;
V_38 = F_21 ( V_36 ) ;
F_4 ( & V_25 -> V_7 , L_5 , V_38 ) ;
if ( ! V_38 )
return;
for ( V_39 = 0 ; V_39 < F_22 ( V_37 ) ; ++ V_39 ) {
if ( V_37 [ V_39 ] > V_38 )
break;
}
if ( V_39 == F_22 ( V_37 ) )
V_38 = V_37 [ V_39 - 1 ] ;
else if ( V_39 > 0 && ( V_37 [ V_39 ] - V_38 ) > ( V_38 - V_37 [ V_39 - 1 ] ) )
V_38 = V_37 [ V_39 - 1 ] ;
else
V_38 = V_37 [ V_39 ] ;
if ( V_14 -> type != V_22 )
V_38 = F_23 ( int , V_38 , 1228800 ) ;
if ( V_38 <= 115200 ) {
F_24 ( V_38 , V_5 ) ;
} else {
unsigned V_40 = 12000000 * 32 / V_38 ;
V_5 [ 3 ] = 0x80 ;
V_5 [ 2 ] = 0 ;
V_5 [ 1 ] = ( V_40 >= 256 ) ;
while ( V_40 >= 256 ) {
V_40 >>= 2 ;
V_5 [ 1 ] <<= 1 ;
}
V_5 [ 0 ] = V_40 ;
}
F_25 ( V_36 , V_38 , V_38 ) ;
F_4 ( & V_25 -> V_7 , L_6 , V_38 ) ;
}
static void F_26 ( struct V_35 * V_36 ,
struct V_24 * V_25 , struct V_41 * V_42 )
{
struct V_3 * V_4 = V_25 -> V_4 ;
struct V_13 * V_14 = F_13 ( V_4 ) ;
struct V_26 * V_27 = F_18 ( V_25 ) ;
unsigned long V_43 ;
unsigned char * V_5 ;
int V_39 ;
T_2 V_44 ;
if ( V_42 && ! F_27 ( & V_36 -> V_45 , V_42 ) )
return;
V_5 = F_8 ( 7 , V_17 ) ;
if ( ! V_5 ) {
F_28 ( & V_25 -> V_7 , L_7 , V_34 ) ;
if ( V_42 )
V_36 -> V_45 = * V_42 ;
return;
}
V_39 = F_2 ( V_4 -> V_7 , F_3 ( V_4 -> V_7 , 0 ) ,
V_46 , V_47 ,
0 , 0 , V_5 , 7 , 100 ) ;
F_4 ( & V_25 -> V_7 , L_8 , V_39 , V_5 ) ;
switch ( F_29 ( V_36 ) ) {
case V_48 :
V_5 [ 6 ] = 5 ;
break;
case V_49 :
V_5 [ 6 ] = 6 ;
break;
case V_50 :
V_5 [ 6 ] = 7 ;
break;
default:
case V_51 :
V_5 [ 6 ] = 8 ;
}
F_4 ( & V_25 -> V_7 , L_9 , V_5 [ 6 ] ) ;
F_20 ( V_36 , V_25 , & V_5 [ 0 ] ) ;
if ( F_30 ( V_36 ) ) {
if ( F_29 ( V_36 ) == V_48 ) {
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
if ( F_31 ( V_36 ) ) {
if ( F_32 ( V_36 ) ) {
if ( V_36 -> V_45 . V_52 & V_53 ) {
V_5 [ 5 ] = 3 ;
F_4 ( & V_25 -> V_7 , L_13 ) ;
} else {
V_5 [ 5 ] = 1 ;
F_4 ( & V_25 -> V_7 , L_14 ) ;
}
} else {
if ( V_36 -> V_45 . V_52 & V_53 ) {
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
V_39 = F_2 ( V_4 -> V_7 , F_6 ( V_4 -> V_7 , 0 ) ,
V_54 , V_55 ,
0 , 0 , V_5 , 7 , 100 ) ;
F_4 ( & V_25 -> V_7 , L_18 , V_39 ) ;
F_33 ( & V_27 -> V_28 , V_43 ) ;
V_44 = V_27 -> V_56 ;
if ( F_34 ( V_36 ) == V_57 )
V_27 -> V_56 &= ~ ( V_58 | V_59 ) ;
else if ( V_42 && ( V_42 -> V_52 & V_60 ) == V_57 )
V_27 -> V_56 |= ( V_58 | V_59 ) ;
if ( V_44 != V_27 -> V_56 ) {
V_44 = V_27 -> V_56 ;
F_35 ( & V_27 -> V_28 , V_43 ) ;
F_19 ( V_25 , V_44 ) ;
} else {
F_35 ( & V_27 -> V_28 , V_43 ) ;
}
memset ( V_5 , 0 , 7 ) ;
V_39 = F_2 ( V_4 -> V_7 , F_3 ( V_4 -> V_7 , 0 ) ,
V_46 , V_47 ,
0 , 0 , V_5 , 7 , 100 ) ;
F_4 ( & V_25 -> V_7 , L_8 , V_39 , V_5 ) ;
if ( F_36 ( V_36 ) ) {
if ( V_14 -> type == V_22 )
F_5 ( 0x0 , 0x61 , V_4 ) ;
else
F_5 ( 0x0 , 0x41 , V_4 ) ;
} else {
F_5 ( 0x0 , 0x0 , V_4 ) ;
}
F_10 ( V_5 ) ;
}
static void F_37 ( struct V_24 * V_25 , int V_61 )
{
struct V_26 * V_27 = F_18 ( V_25 ) ;
unsigned long V_43 ;
T_2 V_44 ;
F_33 ( & V_27 -> V_28 , V_43 ) ;
if ( V_61 )
V_27 -> V_56 |= ( V_58 | V_59 ) ;
else
V_27 -> V_56 &= ~ ( V_58 | V_59 ) ;
V_44 = V_27 -> V_56 ;
F_35 ( & V_27 -> V_28 , V_43 ) ;
F_19 ( V_25 , V_44 ) ;
}
static void F_38 ( struct V_24 * V_25 )
{
F_39 ( V_25 ) ;
F_40 ( V_25 -> V_62 ) ;
}
static int F_41 ( struct V_35 * V_36 , struct V_24 * V_25 )
{
struct V_3 * V_4 = V_25 -> V_4 ;
struct V_13 * V_14 = F_13 ( V_4 ) ;
int V_63 ;
if ( V_14 -> type != V_22 ) {
F_42 ( V_4 -> V_7 , V_25 -> V_64 -> V_65 ) ;
F_42 ( V_4 -> V_7 , V_25 -> V_66 -> V_65 ) ;
} else {
F_5 ( 8 , 0 , V_4 ) ;
F_5 ( 9 , 0 , V_4 ) ;
}
if ( V_36 )
F_26 ( V_36 , V_25 , NULL ) ;
V_63 = F_43 ( V_25 -> V_62 , V_17 ) ;
if ( V_63 ) {
F_28 ( & V_25 -> V_7 , L_19
L_20 , V_34 , V_63 ) ;
return V_63 ;
}
V_63 = F_44 ( V_36 , V_25 ) ;
if ( V_63 ) {
F_40 ( V_25 -> V_62 ) ;
return V_63 ;
}
return 0 ;
}
static int F_45 ( struct V_35 * V_36 ,
unsigned int V_67 , unsigned int V_68 )
{
struct V_24 * V_25 = V_36 -> V_69 ;
struct V_26 * V_27 = F_18 ( V_25 ) ;
unsigned long V_43 ;
T_2 V_44 ;
int V_70 ;
F_33 ( & V_27 -> V_28 , V_43 ) ;
if ( V_67 & V_71 )
V_27 -> V_56 |= V_59 ;
if ( V_67 & V_72 )
V_27 -> V_56 |= V_58 ;
if ( V_68 & V_71 )
V_27 -> V_56 &= ~ V_59 ;
if ( V_68 & V_72 )
V_27 -> V_56 &= ~ V_58 ;
V_44 = V_27 -> V_56 ;
F_35 ( & V_27 -> V_28 , V_43 ) ;
V_70 = F_19 ( V_25 , V_44 ) ;
if ( V_70 )
return F_46 ( V_70 ) ;
return 0 ;
}
static int F_47 ( struct V_35 * V_36 )
{
struct V_24 * V_25 = V_36 -> V_69 ;
struct V_26 * V_27 = F_18 ( V_25 ) ;
unsigned long V_43 ;
unsigned int V_73 ;
unsigned int V_74 ;
unsigned int V_63 ;
F_33 ( & V_27 -> V_28 , V_43 ) ;
V_73 = V_27 -> V_56 ;
V_74 = V_27 -> V_75 ;
F_35 ( & V_27 -> V_28 , V_43 ) ;
V_63 = ( ( V_73 & V_58 ) ? V_72 : 0 )
| ( ( V_73 & V_59 ) ? V_71 : 0 )
| ( ( V_74 & V_76 ) ? V_77 : 0 )
| ( ( V_74 & V_78 ) ? V_79 : 0 )
| ( ( V_74 & V_80 ) ? V_81 : 0 )
| ( ( V_74 & V_82 ) ? V_83 : 0 ) ;
F_4 ( & V_25 -> V_7 , L_21 , V_34 , V_63 ) ;
return V_63 ;
}
static int F_48 ( struct V_24 * V_25 )
{
struct V_26 * V_27 = F_18 ( V_25 ) ;
if ( V_27 -> V_75 & V_82 )
return 1 ;
return 0 ;
}
static int F_49 ( struct V_35 * V_36 , unsigned long V_84 )
{
struct V_24 * V_25 = V_36 -> V_69 ;
struct V_26 * V_27 = F_18 ( V_25 ) ;
unsigned long V_43 ;
unsigned int V_85 ;
unsigned int V_74 ;
unsigned int V_86 ;
F_33 ( & V_27 -> V_28 , V_43 ) ;
V_85 = V_27 -> V_75 ;
F_35 ( & V_27 -> V_28 , V_43 ) ;
while ( 1 ) {
F_50 ( & V_25 -> V_25 . V_87 ) ;
if ( F_51 ( V_88 ) )
return - V_89 ;
if ( V_25 -> V_4 -> V_90 )
return - V_91 ;
F_33 ( & V_27 -> V_28 , V_43 ) ;
V_74 = V_27 -> V_75 ;
F_35 ( & V_27 -> V_28 , V_43 ) ;
V_86 = V_85 ^ V_74 ;
if ( ( ( V_84 & V_92 ) && ( V_86 & V_80 ) ) ||
( ( V_84 & V_79 ) && ( V_86 & V_78 ) ) ||
( ( V_84 & V_83 ) && ( V_86 & V_82 ) ) ||
( ( V_84 & V_77 ) && ( V_86 & V_76 ) ) ) {
return 0 ;
}
V_85 = V_74 ;
}
return 0 ;
}
static int F_52 ( struct V_35 * V_36 ,
unsigned int V_93 , unsigned long V_84 )
{
struct V_94 V_95 ;
struct V_24 * V_25 = V_36 -> V_69 ;
F_4 ( & V_25 -> V_7 , L_22 , V_34 , V_93 ) ;
switch ( V_93 ) {
case V_96 :
memset ( & V_95 , 0 , sizeof V_95 ) ;
V_95 . type = V_97 ;
V_95 . line = V_25 -> V_98 ;
V_95 . V_25 = V_25 -> V_99 ;
V_95 . V_100 = 460800 ;
if ( F_53 ( ( void V_101 * ) V_84 , & V_95 , sizeof V_95 ) )
return - V_102 ;
return 0 ;
default:
F_4 ( & V_25 -> V_7 , L_23 , V_34 , V_93 ) ;
break;
}
return - V_103 ;
}
static void F_54 ( struct V_35 * V_36 , int V_104 )
{
struct V_24 * V_25 = V_36 -> V_69 ;
struct V_3 * V_4 = V_25 -> V_4 ;
T_3 V_105 ;
int V_63 ;
if ( V_104 == 0 )
V_105 = V_106 ;
else
V_105 = V_107 ;
F_4 ( & V_25 -> V_7 , L_24 , V_34 ,
V_105 == V_106 ? L_25 : L_26 ) ;
V_63 = F_2 ( V_4 -> V_7 , F_6 ( V_4 -> V_7 , 0 ) ,
V_108 , V_109 , V_105 ,
0 , NULL , 0 , 100 ) ;
if ( V_63 )
F_28 ( & V_25 -> V_7 , L_27 , V_63 ) ;
}
static void F_55 ( struct V_24 * V_25 ,
unsigned char * V_110 ,
unsigned int V_111 )
{
struct V_26 * V_27 = F_18 ( V_25 ) ;
struct V_35 * V_36 ;
unsigned long V_43 ;
T_2 V_112 = V_113 ;
T_2 V_114 = V_113 + 1 ;
T_2 V_115 ;
T_3 V_116 , V_117 ;
V_116 = F_56 ( V_25 -> V_4 -> V_7 -> V_19 . V_118 ) ;
V_117 = F_56 ( V_25 -> V_4 -> V_7 -> V_19 . V_119 ) ;
if ( V_116 == V_120 ) {
if ( V_117 == V_121 ||
V_117 == V_122 ||
V_117 == V_123 ) {
V_114 = 1 ;
V_112 = 0 ;
}
}
if ( V_111 < V_114 )
return;
F_33 ( & V_27 -> V_28 , V_43 ) ;
V_115 = V_27 -> V_75 ;
V_27 -> V_75 = V_110 [ V_112 ] ;
F_35 ( & V_27 -> V_28 , V_43 ) ;
if ( V_27 -> V_75 & V_124 )
F_57 ( V_25 ) ;
F_58 ( & V_25 -> V_25 . V_87 ) ;
V_36 = F_59 ( & V_25 -> V_25 ) ;
if ( ! V_36 )
return;
if ( ( V_27 -> V_75 ^ V_115 ) & V_82 )
F_60 ( V_25 , V_36 ,
V_27 -> V_75 & V_82 ) ;
F_61 ( V_36 ) ;
}
static void F_62 ( struct V_125 * V_125 )
{
struct V_24 * V_25 = V_125 -> V_126 ;
unsigned char * V_110 = V_125 -> V_127 ;
unsigned int V_111 = V_125 -> V_111 ;
int V_74 = V_125 -> V_74 ;
int V_31 ;
switch ( V_74 ) {
case 0 :
break;
case - V_128 :
case - V_129 :
case - V_130 :
F_4 ( & V_25 -> V_7 , L_28 ,
V_34 , V_74 ) ;
return;
default:
F_4 ( & V_25 -> V_7 , L_29 ,
V_34 , V_74 ) ;
goto exit;
}
F_63 ( & V_25 -> V_7 , V_34 ,
V_125 -> V_111 , V_125 -> V_127 ) ;
F_55 ( V_25 , V_110 , V_111 ) ;
exit:
V_31 = F_43 ( V_125 , V_131 ) ;
if ( V_31 )
F_28 ( & V_25 -> V_7 ,
L_30 ,
V_34 , V_31 ) ;
}
static void F_64 ( struct V_125 * V_125 )
{
struct V_24 * V_25 = V_125 -> V_126 ;
struct V_26 * V_27 = F_18 ( V_25 ) ;
unsigned char * V_110 = V_125 -> V_127 ;
char V_132 = V_133 ;
unsigned long V_43 ;
T_2 V_75 ;
int V_39 ;
F_33 ( & V_27 -> V_28 , V_43 ) ;
V_75 = V_27 -> V_75 ;
V_27 -> V_75 &= ~ V_134 ;
F_35 ( & V_27 -> V_28 , V_43 ) ;
F_58 ( & V_25 -> V_25 . V_87 ) ;
if ( ! V_125 -> V_111 )
return;
if ( V_75 & V_124 )
V_132 = V_135 ;
else if ( V_75 & V_136 )
V_132 = V_137 ;
else if ( V_75 & V_138 )
V_132 = V_139 ;
if ( V_132 != V_133 )
F_4 ( & V_25 -> V_7 , L_31 , V_34 ,
V_132 ) ;
if ( V_75 & V_140 )
F_65 ( & V_25 -> V_25 , 0 , V_141 ) ;
if ( V_25 -> V_25 . V_142 && V_25 -> V_143 ) {
for ( V_39 = 0 ; V_39 < V_125 -> V_111 ; ++ V_39 )
if ( ! F_66 ( V_25 , V_110 [ V_39 ] ) )
F_65 ( & V_25 -> V_25 , V_110 [ V_39 ] ,
V_132 ) ;
} else {
F_67 ( & V_25 -> V_25 , V_110 , V_132 ,
V_125 -> V_111 ) ;
}
F_68 ( & V_25 -> V_25 ) ;
}
