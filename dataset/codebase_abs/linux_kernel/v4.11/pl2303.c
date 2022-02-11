static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
unsigned char V_4 [ 1 ] )
{
struct V_5 * V_6 = & V_2 -> V_7 -> V_6 ;
int V_8 ;
V_8 = F_2 ( V_2 -> V_6 , F_3 ( V_2 -> V_6 , 0 ) ,
V_9 , V_10 ,
V_3 , 0 , V_4 , 1 , 100 ) ;
if ( V_8 != 1 ) {
F_4 ( V_6 , L_1 , V_11 ,
V_3 , V_8 ) ;
if ( V_8 >= 0 )
V_8 = - V_12 ;
return V_8 ;
}
F_5 ( V_6 , L_2 , V_11 , V_3 , V_4 [ 0 ] ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_13 )
{
struct V_5 * V_6 = & V_2 -> V_7 -> V_6 ;
int V_8 ;
F_5 ( V_6 , L_2 , V_11 , V_3 , V_13 ) ;
V_8 = F_2 ( V_2 -> V_6 , F_7 ( V_2 -> V_6 , 0 ) ,
V_14 , V_15 ,
V_3 , V_13 , NULL , 0 , 100 ) ;
if ( V_8 ) {
F_4 ( V_6 , L_3 , V_11 ,
V_3 , V_8 ) ;
return V_8 ;
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
const struct V_16 * V_17 )
{
F_9 ( V_2 , ( void * ) V_17 -> V_18 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_19 * V_20 ;
unsigned char V_21 = V_2 -> V_21 ;
enum V_22 type = V_23 ;
unsigned char * V_4 ;
if ( V_2 -> V_24 < V_21 ||
V_2 -> V_25 < V_21 ||
V_2 -> V_26 < V_21 ) {
F_4 ( & V_2 -> V_7 -> V_6 , L_4 ) ;
return - V_27 ;
}
V_20 = F_11 ( sizeof( * V_20 ) , V_28 ) ;
if ( ! V_20 )
return - V_29 ;
V_4 = F_12 ( 1 , V_28 ) ;
if ( ! V_4 ) {
F_13 ( V_20 ) ;
return - V_29 ;
}
if ( V_2 -> V_6 -> V_30 . V_31 == 0x02 )
type = V_23 ;
else if ( V_2 -> V_6 -> V_30 . V_32 == 0x40 )
type = V_33 ;
else if ( V_2 -> V_6 -> V_30 . V_31 == 0x00 )
type = V_23 ;
else if ( V_2 -> V_6 -> V_30 . V_31 == 0xFF )
type = V_23 ;
F_5 ( & V_2 -> V_7 -> V_6 , L_5 , type ) ;
V_20 -> type = & V_34 [ type ] ;
V_20 -> V_35 = ( unsigned long ) F_14 ( V_2 ) ;
V_20 -> V_35 |= V_20 -> type -> V_35 ;
F_9 ( V_2 , V_20 ) ;
F_1 ( V_2 , 0x8484 , V_4 ) ;
F_6 ( V_2 , 0x0404 , 0 ) ;
F_1 ( V_2 , 0x8484 , V_4 ) ;
F_1 ( V_2 , 0x8383 , V_4 ) ;
F_1 ( V_2 , 0x8484 , V_4 ) ;
F_6 ( V_2 , 0x0404 , 1 ) ;
F_1 ( V_2 , 0x8484 , V_4 ) ;
F_1 ( V_2 , 0x8383 , V_4 ) ;
F_6 ( V_2 , 0 , 1 ) ;
F_6 ( V_2 , 1 , 0 ) ;
if ( V_20 -> V_35 & V_36 )
F_6 ( V_2 , 2 , 0x24 ) ;
else
F_6 ( V_2 , 2 , 0x44 ) ;
F_13 ( V_4 ) ;
return 0 ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = F_14 ( V_2 ) ;
F_13 ( V_20 ) ;
}
static int F_16 ( struct V_37 * V_38 )
{
struct V_39 * V_40 ;
V_40 = F_11 ( sizeof( * V_40 ) , V_28 ) ;
if ( ! V_40 )
return - V_29 ;
F_17 ( & V_40 -> V_41 ) ;
F_18 ( V_38 , V_40 ) ;
V_38 -> V_38 . V_42 = 256 ;
return 0 ;
}
static int F_19 ( struct V_37 * V_38 )
{
struct V_39 * V_40 = F_20 ( V_38 ) ;
F_13 ( V_40 ) ;
return 0 ;
}
static int F_21 ( struct V_37 * V_38 , T_2 V_3 )
{
struct V_43 * V_6 = V_38 -> V_2 -> V_6 ;
int V_44 ;
F_5 ( & V_38 -> V_6 , L_6 , V_11 , V_3 ) ;
V_44 = F_2 ( V_6 , F_7 ( V_6 , 0 ) ,
V_45 , V_46 ,
V_3 , 0 , NULL , 0 , 100 ) ;
if ( V_44 )
F_4 ( & V_38 -> V_6 , L_7 , V_11 , V_44 ) ;
return V_44 ;
}
static T_3 F_22 ( T_3 V_47 )
{
static const T_3 V_48 [] = {
75 , 150 , 300 , 600 , 1200 , 1800 , 2400 , 3600 , 4800 , 7200 , 9600 ,
14400 , 19200 , 28800 , 38400 , 57600 , 115200 , 230400 , 460800 ,
614400 , 921600 , 1228800 , 2457600 , 3000000 , 6000000
} ;
unsigned V_49 ;
for ( V_49 = 0 ; V_49 < F_23 ( V_48 ) ; ++ V_49 ) {
if ( V_48 [ V_49 ] > V_47 )
break;
}
if ( V_49 == F_23 ( V_48 ) )
V_47 = V_48 [ V_49 - 1 ] ;
else if ( V_49 > 0 && ( V_48 [ V_49 ] - V_47 ) > ( V_47 - V_48 [ V_49 - 1 ] ) )
V_47 = V_48 [ V_49 - 1 ] ;
else
V_47 = V_48 [ V_49 ] ;
return V_47 ;
}
static T_3 F_24 ( unsigned char V_4 [ 4 ] ,
T_3 V_47 )
{
F_25 ( V_47 , V_4 ) ;
return V_47 ;
}
static T_3 F_26 ( unsigned char V_4 [ 4 ] ,
T_3 V_47 )
{
unsigned int V_50 , V_51 , V_52 ;
V_50 = 12000000 * 32 ;
V_51 = V_50 / V_47 ;
if ( V_51 == 0 )
V_51 = 1 ;
V_52 = 0 ;
while ( V_51 >= 512 ) {
if ( V_52 < 7 ) {
V_51 >>= 2 ;
V_52 ++ ;
} else {
V_51 = 511 ;
break;
}
}
V_4 [ 3 ] = 0x80 ;
V_4 [ 2 ] = 0 ;
V_4 [ 1 ] = V_52 << 1 | V_51 >> 8 ;
V_4 [ 0 ] = V_51 & 0xff ;
V_47 = ( V_50 / V_51 ) >> ( V_52 << 1 ) ;
return V_47 ;
}
static void F_27 ( struct V_53 * V_54 ,
struct V_37 * V_38 ,
T_2 V_4 [ 4 ] )
{
struct V_1 * V_2 = V_38 -> V_2 ;
struct V_19 * V_20 = F_14 ( V_2 ) ;
T_3 V_48 ;
T_3 V_47 ;
V_47 = F_28 ( V_54 ) ;
F_5 ( & V_38 -> V_6 , L_8 , V_47 ) ;
if ( ! V_47 )
return;
if ( V_20 -> type -> V_55 )
V_47 = F_29 ( T_3 , V_47 , V_20 -> type -> V_55 ) ;
V_48 = F_22 ( V_47 ) ;
if ( V_47 == V_48 )
V_47 = F_24 ( V_4 , V_47 ) ;
else
V_47 = F_26 ( V_4 , V_47 ) ;
F_30 ( V_54 , V_47 , V_47 ) ;
F_5 ( & V_38 -> V_6 , L_9 , V_47 ) ;
}
static int F_31 ( struct V_37 * V_38 ,
unsigned char V_4 [ 7 ] )
{
struct V_43 * V_56 = V_38 -> V_2 -> V_6 ;
int V_57 ;
V_57 = F_2 ( V_56 , F_3 ( V_56 , 0 ) ,
V_58 , V_59 ,
0 , 0 , V_4 , 7 , 100 ) ;
if ( V_57 != 7 ) {
F_4 ( & V_38 -> V_6 , L_7 , V_11 , V_57 ) ;
if ( V_57 >= 0 )
V_57 = - V_12 ;
return V_57 ;
}
F_5 ( & V_38 -> V_6 , L_10 , V_11 , V_4 ) ;
return 0 ;
}
static int F_32 ( struct V_37 * V_38 ,
unsigned char V_4 [ 7 ] )
{
struct V_43 * V_56 = V_38 -> V_2 -> V_6 ;
int V_57 ;
V_57 = F_2 ( V_56 , F_7 ( V_56 , 0 ) ,
V_60 , V_61 ,
0 , 0 , V_4 , 7 , 100 ) ;
if ( V_57 < 0 ) {
F_4 ( & V_38 -> V_6 , L_7 , V_11 , V_57 ) ;
return V_57 ;
}
F_5 ( & V_38 -> V_6 , L_10 , V_11 , V_4 ) ;
return 0 ;
}
static void F_33 ( struct V_53 * V_54 ,
struct V_37 * V_38 , struct V_62 * V_63 )
{
struct V_1 * V_2 = V_38 -> V_2 ;
struct V_19 * V_20 = F_14 ( V_2 ) ;
struct V_39 * V_40 = F_20 ( V_38 ) ;
unsigned long V_64 ;
unsigned char * V_4 ;
int V_57 ;
T_2 V_65 ;
if ( V_63 && ! F_34 ( & V_54 -> V_66 , V_63 ) )
return;
V_4 = F_11 ( 7 , V_28 ) ;
if ( ! V_4 ) {
if ( V_63 )
V_54 -> V_66 = * V_63 ;
return;
}
F_31 ( V_38 , V_4 ) ;
switch ( F_35 ( V_54 ) ) {
case V_67 :
V_4 [ 6 ] = 5 ;
break;
case V_68 :
V_4 [ 6 ] = 6 ;
break;
case V_69 :
V_4 [ 6 ] = 7 ;
break;
default:
case V_70 :
V_4 [ 6 ] = 8 ;
}
F_5 ( & V_38 -> V_6 , L_11 , V_4 [ 6 ] ) ;
F_27 ( V_54 , V_38 , & V_4 [ 0 ] ) ;
if ( F_36 ( V_54 ) ) {
if ( F_35 ( V_54 ) == V_67 ) {
V_4 [ 4 ] = 1 ;
F_5 ( & V_38 -> V_6 , L_12 ) ;
} else {
V_4 [ 4 ] = 2 ;
F_5 ( & V_38 -> V_6 , L_13 ) ;
}
} else {
V_4 [ 4 ] = 0 ;
F_5 ( & V_38 -> V_6 , L_14 ) ;
}
if ( F_37 ( V_54 ) ) {
if ( F_38 ( V_54 ) ) {
if ( F_39 ( V_54 ) ) {
V_4 [ 5 ] = 3 ;
F_5 ( & V_38 -> V_6 , L_15 ) ;
} else {
V_4 [ 5 ] = 1 ;
F_5 ( & V_38 -> V_6 , L_16 ) ;
}
} else {
if ( F_39 ( V_54 ) ) {
V_4 [ 5 ] = 4 ;
F_5 ( & V_38 -> V_6 , L_17 ) ;
} else {
V_4 [ 5 ] = 2 ;
F_5 ( & V_38 -> V_6 , L_18 ) ;
}
}
} else {
V_4 [ 5 ] = 0 ;
F_5 ( & V_38 -> V_6 , L_19 ) ;
}
if ( ! V_63 || memcmp ( V_4 , V_40 -> V_71 , 7 ) ) {
V_57 = F_32 ( V_38 , V_4 ) ;
if ( ! V_57 )
memcpy ( V_40 -> V_71 , V_4 , 7 ) ;
}
F_40 ( & V_40 -> V_41 , V_64 ) ;
V_65 = V_40 -> V_72 ;
if ( F_41 ( V_54 ) == V_73 )
V_40 -> V_72 &= ~ ( V_74 | V_75 ) ;
else if ( V_63 && ( V_63 -> V_76 & V_77 ) == V_73 )
V_40 -> V_72 |= ( V_74 | V_75 ) ;
if ( V_65 != V_40 -> V_72 ) {
V_65 = V_40 -> V_72 ;
F_42 ( & V_40 -> V_41 , V_64 ) ;
F_21 ( V_38 , V_65 ) ;
} else {
F_42 ( & V_40 -> V_41 , V_64 ) ;
}
if ( F_43 ( V_54 ) ) {
if ( V_20 -> V_35 & V_36 )
F_6 ( V_2 , 0x0 , 0x41 ) ;
else
F_6 ( V_2 , 0x0 , 0x61 ) ;
} else {
F_6 ( V_2 , 0x0 , 0x0 ) ;
}
F_13 ( V_4 ) ;
}
static void F_44 ( struct V_37 * V_38 , int V_78 )
{
struct V_39 * V_40 = F_20 ( V_38 ) ;
unsigned long V_64 ;
T_2 V_65 ;
F_40 ( & V_40 -> V_41 , V_64 ) ;
if ( V_78 )
V_40 -> V_72 |= ( V_74 | V_75 ) ;
else
V_40 -> V_72 &= ~ ( V_74 | V_75 ) ;
V_65 = V_40 -> V_72 ;
F_42 ( & V_40 -> V_41 , V_64 ) ;
F_21 ( V_38 , V_65 ) ;
}
static void F_45 ( struct V_37 * V_38 )
{
F_46 ( V_38 ) ;
F_47 ( V_38 -> V_79 ) ;
F_48 ( V_38 , false ) ;
}
static int F_49 ( struct V_53 * V_54 , struct V_37 * V_38 )
{
struct V_1 * V_2 = V_38 -> V_2 ;
struct V_19 * V_20 = F_14 ( V_2 ) ;
int V_80 ;
if ( V_20 -> V_35 & V_36 ) {
F_50 ( V_2 -> V_6 , V_38 -> V_81 -> V_82 ) ;
F_50 ( V_2 -> V_6 , V_38 -> V_83 -> V_82 ) ;
} else {
F_6 ( V_2 , 8 , 0 ) ;
F_6 ( V_2 , 9 , 0 ) ;
}
if ( V_54 )
F_33 ( V_54 , V_38 , NULL ) ;
V_80 = F_51 ( V_38 -> V_79 , V_28 ) ;
if ( V_80 ) {
F_4 ( & V_38 -> V_6 , L_20 ,
V_80 ) ;
return V_80 ;
}
V_80 = F_52 ( V_54 , V_38 ) ;
if ( V_80 ) {
F_47 ( V_38 -> V_79 ) ;
return V_80 ;
}
return 0 ;
}
static int F_53 ( struct V_53 * V_54 ,
unsigned int V_84 , unsigned int V_85 )
{
struct V_37 * V_38 = V_54 -> V_86 ;
struct V_39 * V_40 = F_20 ( V_38 ) ;
unsigned long V_64 ;
T_2 V_65 ;
int V_57 ;
F_40 ( & V_40 -> V_41 , V_64 ) ;
if ( V_84 & V_87 )
V_40 -> V_72 |= V_75 ;
if ( V_84 & V_88 )
V_40 -> V_72 |= V_74 ;
if ( V_85 & V_87 )
V_40 -> V_72 &= ~ V_75 ;
if ( V_85 & V_88 )
V_40 -> V_72 &= ~ V_74 ;
V_65 = V_40 -> V_72 ;
F_42 ( & V_40 -> V_41 , V_64 ) ;
V_57 = F_21 ( V_38 , V_65 ) ;
if ( V_57 )
return F_54 ( V_57 ) ;
return 0 ;
}
static int F_55 ( struct V_53 * V_54 )
{
struct V_37 * V_38 = V_54 -> V_86 ;
struct V_39 * V_40 = F_20 ( V_38 ) ;
unsigned long V_64 ;
unsigned int V_89 ;
unsigned int V_90 ;
unsigned int V_80 ;
F_40 ( & V_40 -> V_41 , V_64 ) ;
V_89 = V_40 -> V_72 ;
V_90 = V_40 -> V_91 ;
F_42 ( & V_40 -> V_41 , V_64 ) ;
V_80 = ( ( V_89 & V_74 ) ? V_88 : 0 )
| ( ( V_89 & V_75 ) ? V_87 : 0 )
| ( ( V_90 & V_92 ) ? V_93 : 0 )
| ( ( V_90 & V_94 ) ? V_95 : 0 )
| ( ( V_90 & V_96 ) ? V_97 : 0 )
| ( ( V_90 & V_98 ) ? V_99 : 0 ) ;
F_5 ( & V_38 -> V_6 , L_21 , V_11 , V_80 ) ;
return V_80 ;
}
static int F_56 ( struct V_37 * V_38 )
{
struct V_39 * V_40 = F_20 ( V_38 ) ;
if ( V_40 -> V_91 & V_98 )
return 1 ;
return 0 ;
}
static int F_57 ( struct V_53 * V_54 ,
unsigned int V_100 , unsigned long V_101 )
{
struct V_102 V_103 ;
struct V_37 * V_38 = V_54 -> V_86 ;
switch ( V_100 ) {
case V_104 :
memset ( & V_103 , 0 , sizeof V_103 ) ;
V_103 . type = V_105 ;
V_103 . line = V_38 -> V_106 ;
V_103 . V_38 = V_38 -> V_107 ;
V_103 . V_108 = 460800 ;
if ( F_58 ( ( void V_109 * ) V_101 , & V_103 , sizeof V_103 ) )
return - V_110 ;
return 0 ;
default:
break;
}
return - V_111 ;
}
static void F_48 ( struct V_37 * V_38 , bool V_112 )
{
struct V_1 * V_2 = V_38 -> V_2 ;
T_1 V_113 ;
int V_80 ;
if ( V_112 )
V_113 = V_114 ;
else
V_113 = V_115 ;
F_5 ( & V_38 -> V_6 , L_22 , V_11 ,
V_113 == V_115 ? L_23 : L_24 ) ;
V_80 = F_2 ( V_2 -> V_6 , F_7 ( V_2 -> V_6 , 0 ) ,
V_116 , V_117 , V_113 ,
0 , NULL , 0 , 100 ) ;
if ( V_80 )
F_4 ( & V_38 -> V_6 , L_25 , V_80 ) ;
}
static void F_59 ( struct V_53 * V_54 , int V_113 )
{
struct V_37 * V_38 = V_54 -> V_86 ;
F_48 ( V_38 , V_113 ) ;
}
static void F_60 ( struct V_37 * V_38 ,
unsigned char * V_118 ,
unsigned int V_119 )
{
struct V_1 * V_2 = V_38 -> V_2 ;
struct V_19 * V_20 = F_14 ( V_2 ) ;
struct V_39 * V_40 = F_20 ( V_38 ) ;
struct V_53 * V_54 ;
unsigned long V_64 ;
unsigned int V_120 = V_121 ;
T_2 V_90 ;
T_2 V_122 ;
if ( V_20 -> V_35 & V_123 )
V_120 = 0 ;
if ( V_119 < V_120 + 1 )
return;
V_90 = V_118 [ V_120 ] ;
F_40 ( & V_40 -> V_41 , V_64 ) ;
V_122 = V_40 -> V_91 ^ V_90 ;
V_40 -> V_91 = V_90 ;
F_42 ( & V_40 -> V_41 , V_64 ) ;
if ( V_90 & V_124 )
F_61 ( V_38 ) ;
if ( V_122 & V_125 ) {
if ( V_122 & V_92 )
V_38 -> V_126 . V_127 ++ ;
if ( V_122 & V_94 )
V_38 -> V_126 . V_128 ++ ;
if ( V_122 & V_96 )
V_38 -> V_126 . V_129 ++ ;
if ( V_122 & V_98 ) {
V_38 -> V_126 . V_130 ++ ;
V_54 = F_62 ( & V_38 -> V_38 ) ;
if ( V_54 ) {
F_63 ( V_38 , V_54 ,
V_90 & V_98 ) ;
F_64 ( V_54 ) ;
}
}
F_65 ( & V_38 -> V_38 . V_131 ) ;
}
}
static void F_66 ( struct V_132 * V_132 )
{
struct V_37 * V_38 = V_132 -> V_133 ;
unsigned char * V_118 = V_132 -> V_134 ;
unsigned int V_119 = V_132 -> V_119 ;
int V_90 = V_132 -> V_90 ;
int V_44 ;
switch ( V_90 ) {
case 0 :
break;
case - V_135 :
case - V_136 :
case - V_137 :
F_5 ( & V_38 -> V_6 , L_26 ,
V_11 , V_90 ) ;
return;
default:
F_5 ( & V_38 -> V_6 , L_27 ,
V_11 , V_90 ) ;
goto exit;
}
F_67 ( & V_38 -> V_6 , V_11 ,
V_132 -> V_119 , V_132 -> V_134 ) ;
F_60 ( V_38 , V_118 , V_119 ) ;
exit:
V_44 = F_51 ( V_132 , V_138 ) ;
if ( V_44 ) {
F_4 ( & V_38 -> V_6 ,
L_28 ,
V_11 , V_44 ) ;
}
}
static void F_68 ( struct V_132 * V_132 )
{
struct V_37 * V_38 = V_132 -> V_133 ;
struct V_39 * V_40 = F_20 ( V_38 ) ;
unsigned char * V_118 = V_132 -> V_134 ;
char V_139 = V_140 ;
unsigned long V_64 ;
T_2 V_91 ;
int V_49 ;
F_40 ( & V_40 -> V_41 , V_64 ) ;
V_91 = V_40 -> V_91 ;
V_40 -> V_91 &= ~ V_141 ;
F_42 ( & V_40 -> V_41 , V_64 ) ;
if ( ! V_132 -> V_119 )
return;
if ( V_91 & V_124 )
V_139 = V_142 ;
else if ( V_91 & V_143 )
V_139 = V_144 ;
else if ( V_91 & V_145 )
V_139 = V_146 ;
if ( V_139 != V_140 )
F_5 ( & V_38 -> V_6 , L_29 , V_11 ,
V_139 ) ;
if ( V_91 & V_147 )
F_69 ( & V_38 -> V_38 , 0 , V_148 ) ;
if ( V_38 -> V_38 . V_149 && V_38 -> V_150 ) {
for ( V_49 = 0 ; V_49 < V_132 -> V_119 ; ++ V_49 )
if ( ! F_70 ( V_38 , V_118 [ V_49 ] ) )
F_69 ( & V_38 -> V_38 , V_118 [ V_49 ] ,
V_139 ) ;
} else {
F_71 ( & V_38 -> V_38 , V_118 , V_139 ,
V_132 -> V_119 ) ;
}
F_72 ( & V_38 -> V_38 ) ;
}
