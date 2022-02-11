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
static int F_10 ( struct V_1 * V_2 ,
struct V_19 * V_20 )
{
struct V_21 * V_7 = V_2 -> V_7 ;
struct V_22 * V_6 = V_2 -> V_6 ;
struct V_5 * V_23 = & V_7 -> V_6 ;
struct V_24 * V_25 ;
struct V_26 * V_27 ;
unsigned int V_28 ;
if ( V_7 == V_6 -> V_29 -> V_7 [ 0 ] )
return 0 ;
V_25 = V_6 -> V_29 -> V_7 [ 0 ] -> V_30 ;
for ( V_28 = 0 ; V_28 < V_25 -> V_31 . V_32 ; ++ V_28 ) {
V_27 = & V_25 -> V_27 [ V_28 ] . V_31 ;
if ( ! F_11 ( V_27 ) )
continue;
F_5 ( V_23 , L_4 ) ;
if ( V_20 -> V_33 < F_12 ( V_20 -> V_34 ) )
V_20 -> V_34 [ V_20 -> V_33 ++ ] = V_27 ;
}
return 0 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_19 * V_20 )
{
unsigned long V_35 = ( unsigned long ) F_14 ( V_2 ) ;
struct V_5 * V_6 = & V_2 -> V_7 -> V_6 ;
int V_36 ;
if ( V_35 & V_37 ) {
V_36 = F_10 ( V_2 , V_20 ) ;
if ( V_36 )
return V_36 ;
}
if ( V_20 -> V_33 < 1 ) {
F_4 ( V_6 , L_5 ) ;
return - V_38 ;
}
return 1 ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_39 * V_40 ;
enum V_41 type = V_42 ;
unsigned char * V_4 ;
V_40 = F_16 ( sizeof( * V_40 ) , V_43 ) ;
if ( ! V_40 )
return - V_44 ;
V_4 = F_17 ( 1 , V_43 ) ;
if ( ! V_4 ) {
F_18 ( V_40 ) ;
return - V_44 ;
}
if ( V_2 -> V_6 -> V_45 . V_46 == 0x02 )
type = V_42 ;
else if ( V_2 -> V_6 -> V_45 . V_47 == 0x40 )
type = V_48 ;
else if ( V_2 -> V_6 -> V_45 . V_46 == 0x00 )
type = V_42 ;
else if ( V_2 -> V_6 -> V_45 . V_46 == 0xFF )
type = V_42 ;
F_5 ( & V_2 -> V_7 -> V_6 , L_6 , type ) ;
V_40 -> type = & V_49 [ type ] ;
V_40 -> V_35 = ( unsigned long ) F_14 ( V_2 ) ;
V_40 -> V_35 |= V_40 -> type -> V_35 ;
F_9 ( V_2 , V_40 ) ;
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
if ( V_40 -> V_35 & V_50 )
F_6 ( V_2 , 2 , 0x24 ) ;
else
F_6 ( V_2 , 2 , 0x44 ) ;
F_18 ( V_4 ) ;
return 0 ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = F_14 ( V_2 ) ;
F_18 ( V_40 ) ;
}
static int F_20 ( struct V_51 * V_52 )
{
struct V_53 * V_54 ;
V_54 = F_16 ( sizeof( * V_54 ) , V_43 ) ;
if ( ! V_54 )
return - V_44 ;
F_21 ( & V_54 -> V_55 ) ;
F_22 ( V_52 , V_54 ) ;
V_52 -> V_52 . V_56 = 256 ;
return 0 ;
}
static int F_23 ( struct V_51 * V_52 )
{
struct V_53 * V_54 = F_24 ( V_52 ) ;
F_18 ( V_54 ) ;
return 0 ;
}
static int F_25 ( struct V_51 * V_52 , T_2 V_3 )
{
struct V_22 * V_6 = V_52 -> V_2 -> V_6 ;
int V_57 ;
F_5 ( & V_52 -> V_6 , L_7 , V_11 , V_3 ) ;
V_57 = F_2 ( V_6 , F_7 ( V_6 , 0 ) ,
V_58 , V_59 ,
V_3 , 0 , NULL , 0 , 100 ) ;
if ( V_57 )
F_4 ( & V_52 -> V_6 , L_8 , V_11 , V_57 ) ;
return V_57 ;
}
static T_3 F_26 ( T_3 V_60 )
{
static const T_3 V_61 [] = {
75 , 150 , 300 , 600 , 1200 , 1800 , 2400 , 3600 , 4800 , 7200 , 9600 ,
14400 , 19200 , 28800 , 38400 , 57600 , 115200 , 230400 , 460800 ,
614400 , 921600 , 1228800 , 2457600 , 3000000 , 6000000
} ;
unsigned V_28 ;
for ( V_28 = 0 ; V_28 < F_12 ( V_61 ) ; ++ V_28 ) {
if ( V_61 [ V_28 ] > V_60 )
break;
}
if ( V_28 == F_12 ( V_61 ) )
V_60 = V_61 [ V_28 - 1 ] ;
else if ( V_28 > 0 && ( V_61 [ V_28 ] - V_60 ) > ( V_60 - V_61 [ V_28 - 1 ] ) )
V_60 = V_61 [ V_28 - 1 ] ;
else
V_60 = V_61 [ V_28 ] ;
return V_60 ;
}
static T_3 F_27 ( unsigned char V_4 [ 4 ] ,
T_3 V_60 )
{
F_28 ( V_60 , V_4 ) ;
return V_60 ;
}
static T_3 F_29 ( unsigned char V_4 [ 4 ] ,
T_3 V_60 )
{
unsigned int V_62 , V_63 , V_64 ;
V_62 = 12000000 * 32 ;
V_63 = V_62 / V_60 ;
if ( V_63 == 0 )
V_63 = 1 ;
V_64 = 0 ;
while ( V_63 >= 512 ) {
if ( V_64 < 7 ) {
V_63 >>= 2 ;
V_64 ++ ;
} else {
V_63 = 511 ;
break;
}
}
V_4 [ 3 ] = 0x80 ;
V_4 [ 2 ] = 0 ;
V_4 [ 1 ] = V_64 << 1 | V_63 >> 8 ;
V_4 [ 0 ] = V_63 & 0xff ;
V_60 = ( V_62 / V_63 ) >> ( V_64 << 1 ) ;
return V_60 ;
}
static void F_30 ( struct V_65 * V_66 ,
struct V_51 * V_52 ,
T_2 V_4 [ 4 ] )
{
struct V_1 * V_2 = V_52 -> V_2 ;
struct V_39 * V_40 = F_14 ( V_2 ) ;
T_3 V_61 ;
T_3 V_60 ;
V_60 = F_31 ( V_66 ) ;
F_5 ( & V_52 -> V_6 , L_9 , V_60 ) ;
if ( ! V_60 )
return;
if ( V_40 -> type -> V_67 )
V_60 = F_32 ( T_3 , V_60 , V_40 -> type -> V_67 ) ;
V_61 = F_26 ( V_60 ) ;
if ( V_60 == V_61 )
V_60 = F_27 ( V_4 , V_60 ) ;
else
V_60 = F_29 ( V_4 , V_60 ) ;
F_33 ( V_66 , V_60 , V_60 ) ;
F_5 ( & V_52 -> V_6 , L_10 , V_60 ) ;
}
static int F_34 ( struct V_51 * V_52 ,
unsigned char V_4 [ 7 ] )
{
struct V_22 * V_68 = V_52 -> V_2 -> V_6 ;
int V_36 ;
V_36 = F_2 ( V_68 , F_3 ( V_68 , 0 ) ,
V_69 , V_70 ,
0 , 0 , V_4 , 7 , 100 ) ;
if ( V_36 != 7 ) {
F_4 ( & V_52 -> V_6 , L_8 , V_11 , V_36 ) ;
if ( V_36 >= 0 )
V_36 = - V_12 ;
return V_36 ;
}
F_5 ( & V_52 -> V_6 , L_11 , V_11 , V_4 ) ;
return 0 ;
}
static int F_35 ( struct V_51 * V_52 ,
unsigned char V_4 [ 7 ] )
{
struct V_22 * V_68 = V_52 -> V_2 -> V_6 ;
int V_36 ;
V_36 = F_2 ( V_68 , F_7 ( V_68 , 0 ) ,
V_71 , V_72 ,
0 , 0 , V_4 , 7 , 100 ) ;
if ( V_36 < 0 ) {
F_4 ( & V_52 -> V_6 , L_8 , V_11 , V_36 ) ;
return V_36 ;
}
F_5 ( & V_52 -> V_6 , L_11 , V_11 , V_4 ) ;
return 0 ;
}
static void F_36 ( struct V_65 * V_66 ,
struct V_51 * V_52 , struct V_73 * V_74 )
{
struct V_1 * V_2 = V_52 -> V_2 ;
struct V_39 * V_40 = F_14 ( V_2 ) ;
struct V_53 * V_54 = F_24 ( V_52 ) ;
unsigned long V_75 ;
unsigned char * V_4 ;
int V_36 ;
T_2 V_76 ;
if ( V_74 && ! F_37 ( & V_66 -> V_77 , V_74 ) )
return;
V_4 = F_16 ( 7 , V_43 ) ;
if ( ! V_4 ) {
if ( V_74 )
V_66 -> V_77 = * V_74 ;
return;
}
F_34 ( V_52 , V_4 ) ;
switch ( F_38 ( V_66 ) ) {
case V_78 :
V_4 [ 6 ] = 5 ;
break;
case V_79 :
V_4 [ 6 ] = 6 ;
break;
case V_80 :
V_4 [ 6 ] = 7 ;
break;
default:
case V_81 :
V_4 [ 6 ] = 8 ;
}
F_5 ( & V_52 -> V_6 , L_12 , V_4 [ 6 ] ) ;
F_30 ( V_66 , V_52 , & V_4 [ 0 ] ) ;
if ( F_39 ( V_66 ) ) {
if ( F_38 ( V_66 ) == V_78 ) {
V_4 [ 4 ] = 1 ;
F_5 ( & V_52 -> V_6 , L_13 ) ;
} else {
V_4 [ 4 ] = 2 ;
F_5 ( & V_52 -> V_6 , L_14 ) ;
}
} else {
V_4 [ 4 ] = 0 ;
F_5 ( & V_52 -> V_6 , L_15 ) ;
}
if ( F_40 ( V_66 ) ) {
if ( F_41 ( V_66 ) ) {
if ( F_42 ( V_66 ) ) {
V_4 [ 5 ] = 3 ;
F_5 ( & V_52 -> V_6 , L_16 ) ;
} else {
V_4 [ 5 ] = 1 ;
F_5 ( & V_52 -> V_6 , L_17 ) ;
}
} else {
if ( F_42 ( V_66 ) ) {
V_4 [ 5 ] = 4 ;
F_5 ( & V_52 -> V_6 , L_18 ) ;
} else {
V_4 [ 5 ] = 2 ;
F_5 ( & V_52 -> V_6 , L_19 ) ;
}
}
} else {
V_4 [ 5 ] = 0 ;
F_5 ( & V_52 -> V_6 , L_20 ) ;
}
if ( ! V_74 || memcmp ( V_4 , V_54 -> V_82 , 7 ) ) {
V_36 = F_35 ( V_52 , V_4 ) ;
if ( ! V_36 )
memcpy ( V_54 -> V_82 , V_4 , 7 ) ;
}
F_43 ( & V_54 -> V_55 , V_75 ) ;
V_76 = V_54 -> V_83 ;
if ( F_44 ( V_66 ) == V_84 )
V_54 -> V_83 &= ~ ( V_85 | V_86 ) ;
else if ( V_74 && ( V_74 -> V_87 & V_88 ) == V_84 )
V_54 -> V_83 |= ( V_85 | V_86 ) ;
if ( V_76 != V_54 -> V_83 ) {
V_76 = V_54 -> V_83 ;
F_45 ( & V_54 -> V_55 , V_75 ) ;
F_25 ( V_52 , V_76 ) ;
} else {
F_45 ( & V_54 -> V_55 , V_75 ) ;
}
if ( F_46 ( V_66 ) ) {
if ( V_40 -> V_35 & V_50 )
F_6 ( V_2 , 0x0 , 0x41 ) ;
else
F_6 ( V_2 , 0x0 , 0x61 ) ;
} else {
F_6 ( V_2 , 0x0 , 0x0 ) ;
}
F_18 ( V_4 ) ;
}
static void F_47 ( struct V_51 * V_52 , int V_89 )
{
struct V_53 * V_54 = F_24 ( V_52 ) ;
unsigned long V_75 ;
T_2 V_76 ;
F_43 ( & V_54 -> V_55 , V_75 ) ;
if ( V_89 )
V_54 -> V_83 |= ( V_85 | V_86 ) ;
else
V_54 -> V_83 &= ~ ( V_85 | V_86 ) ;
V_76 = V_54 -> V_83 ;
F_45 ( & V_54 -> V_55 , V_75 ) ;
F_25 ( V_52 , V_76 ) ;
}
static void F_48 ( struct V_51 * V_52 )
{
F_49 ( V_52 ) ;
F_50 ( V_52 -> V_90 ) ;
F_51 ( V_52 , false ) ;
}
static int F_52 ( struct V_65 * V_66 , struct V_51 * V_52 )
{
struct V_1 * V_2 = V_52 -> V_2 ;
struct V_39 * V_40 = F_14 ( V_2 ) ;
int V_91 ;
if ( V_40 -> V_35 & V_50 ) {
F_53 ( V_2 -> V_6 , V_52 -> V_92 -> V_93 ) ;
F_53 ( V_2 -> V_6 , V_52 -> V_94 -> V_93 ) ;
} else {
F_6 ( V_2 , 8 , 0 ) ;
F_6 ( V_2 , 9 , 0 ) ;
}
if ( V_66 )
F_36 ( V_66 , V_52 , NULL ) ;
V_91 = F_54 ( V_52 -> V_90 , V_43 ) ;
if ( V_91 ) {
F_4 ( & V_52 -> V_6 , L_21 ,
V_91 ) ;
return V_91 ;
}
V_91 = F_55 ( V_66 , V_52 ) ;
if ( V_91 ) {
F_50 ( V_52 -> V_90 ) ;
return V_91 ;
}
return 0 ;
}
static int F_56 ( struct V_65 * V_66 ,
unsigned int V_95 , unsigned int V_96 )
{
struct V_51 * V_52 = V_66 -> V_97 ;
struct V_53 * V_54 = F_24 ( V_52 ) ;
unsigned long V_75 ;
T_2 V_76 ;
int V_36 ;
F_43 ( & V_54 -> V_55 , V_75 ) ;
if ( V_95 & V_98 )
V_54 -> V_83 |= V_86 ;
if ( V_95 & V_99 )
V_54 -> V_83 |= V_85 ;
if ( V_96 & V_98 )
V_54 -> V_83 &= ~ V_86 ;
if ( V_96 & V_99 )
V_54 -> V_83 &= ~ V_85 ;
V_76 = V_54 -> V_83 ;
F_45 ( & V_54 -> V_55 , V_75 ) ;
V_36 = F_25 ( V_52 , V_76 ) ;
if ( V_36 )
return F_57 ( V_36 ) ;
return 0 ;
}
static int F_58 ( struct V_65 * V_66 )
{
struct V_51 * V_52 = V_66 -> V_97 ;
struct V_53 * V_54 = F_24 ( V_52 ) ;
unsigned long V_75 ;
unsigned int V_100 ;
unsigned int V_101 ;
unsigned int V_91 ;
F_43 ( & V_54 -> V_55 , V_75 ) ;
V_100 = V_54 -> V_83 ;
V_101 = V_54 -> V_102 ;
F_45 ( & V_54 -> V_55 , V_75 ) ;
V_91 = ( ( V_100 & V_85 ) ? V_99 : 0 )
| ( ( V_100 & V_86 ) ? V_98 : 0 )
| ( ( V_101 & V_103 ) ? V_104 : 0 )
| ( ( V_101 & V_105 ) ? V_106 : 0 )
| ( ( V_101 & V_107 ) ? V_108 : 0 )
| ( ( V_101 & V_109 ) ? V_110 : 0 ) ;
F_5 ( & V_52 -> V_6 , L_22 , V_11 , V_91 ) ;
return V_91 ;
}
static int F_59 ( struct V_51 * V_52 )
{
struct V_53 * V_54 = F_24 ( V_52 ) ;
if ( V_54 -> V_102 & V_109 )
return 1 ;
return 0 ;
}
static int F_60 ( struct V_65 * V_66 ,
unsigned int V_111 , unsigned long V_112 )
{
struct V_113 V_114 ;
struct V_51 * V_52 = V_66 -> V_97 ;
switch ( V_111 ) {
case V_115 :
memset ( & V_114 , 0 , sizeof V_114 ) ;
V_114 . type = V_116 ;
V_114 . line = V_52 -> V_117 ;
V_114 . V_52 = V_52 -> V_118 ;
V_114 . V_119 = 460800 ;
if ( F_61 ( ( void V_120 * ) V_112 , & V_114 , sizeof V_114 ) )
return - V_121 ;
return 0 ;
default:
break;
}
return - V_122 ;
}
static void F_51 ( struct V_51 * V_52 , bool V_123 )
{
struct V_1 * V_2 = V_52 -> V_2 ;
T_1 V_124 ;
int V_91 ;
if ( V_123 )
V_124 = V_125 ;
else
V_124 = V_126 ;
F_5 ( & V_52 -> V_6 , L_23 , V_11 ,
V_124 == V_126 ? L_24 : L_25 ) ;
V_91 = F_2 ( V_2 -> V_6 , F_7 ( V_2 -> V_6 , 0 ) ,
V_127 , V_128 , V_124 ,
0 , NULL , 0 , 100 ) ;
if ( V_91 )
F_4 ( & V_52 -> V_6 , L_26 , V_91 ) ;
}
static void F_62 ( struct V_65 * V_66 , int V_124 )
{
struct V_51 * V_52 = V_66 -> V_97 ;
F_51 ( V_52 , V_124 ) ;
}
static void F_63 ( struct V_51 * V_52 ,
unsigned char * V_129 ,
unsigned int V_130 )
{
struct V_1 * V_2 = V_52 -> V_2 ;
struct V_39 * V_40 = F_14 ( V_2 ) ;
struct V_53 * V_54 = F_24 ( V_52 ) ;
struct V_65 * V_66 ;
unsigned long V_75 ;
unsigned int V_131 = V_132 ;
T_2 V_101 ;
T_2 V_133 ;
if ( V_40 -> V_35 & V_134 )
V_131 = 0 ;
if ( V_130 < V_131 + 1 )
return;
V_101 = V_129 [ V_131 ] ;
F_43 ( & V_54 -> V_55 , V_75 ) ;
V_133 = V_54 -> V_102 ^ V_101 ;
V_54 -> V_102 = V_101 ;
F_45 ( & V_54 -> V_55 , V_75 ) ;
if ( V_101 & V_135 )
F_64 ( V_52 ) ;
if ( V_133 & V_136 ) {
if ( V_133 & V_103 )
V_52 -> V_137 . V_138 ++ ;
if ( V_133 & V_105 )
V_52 -> V_137 . V_139 ++ ;
if ( V_133 & V_107 )
V_52 -> V_137 . V_140 ++ ;
if ( V_133 & V_109 ) {
V_52 -> V_137 . V_141 ++ ;
V_66 = F_65 ( & V_52 -> V_52 ) ;
if ( V_66 ) {
F_66 ( V_52 , V_66 ,
V_101 & V_109 ) ;
F_67 ( V_66 ) ;
}
}
F_68 ( & V_52 -> V_52 . V_142 ) ;
}
}
static void F_69 ( struct V_143 * V_143 )
{
struct V_51 * V_52 = V_143 -> V_144 ;
unsigned char * V_129 = V_143 -> V_145 ;
unsigned int V_130 = V_143 -> V_130 ;
int V_101 = V_143 -> V_101 ;
int V_57 ;
switch ( V_101 ) {
case 0 :
break;
case - V_146 :
case - V_147 :
case - V_148 :
F_5 ( & V_52 -> V_6 , L_27 ,
V_11 , V_101 ) ;
return;
default:
F_5 ( & V_52 -> V_6 , L_28 ,
V_11 , V_101 ) ;
goto exit;
}
F_70 ( & V_52 -> V_6 , V_11 ,
V_143 -> V_130 , V_143 -> V_145 ) ;
F_63 ( V_52 , V_129 , V_130 ) ;
exit:
V_57 = F_54 ( V_143 , V_149 ) ;
if ( V_57 ) {
F_4 ( & V_52 -> V_6 ,
L_29 ,
V_11 , V_57 ) ;
}
}
static void F_71 ( struct V_143 * V_143 )
{
struct V_51 * V_52 = V_143 -> V_144 ;
struct V_53 * V_54 = F_24 ( V_52 ) ;
unsigned char * V_129 = V_143 -> V_145 ;
char V_150 = V_151 ;
unsigned long V_75 ;
T_2 V_102 ;
int V_28 ;
F_43 ( & V_54 -> V_55 , V_75 ) ;
V_102 = V_54 -> V_102 ;
V_54 -> V_102 &= ~ V_152 ;
F_45 ( & V_54 -> V_55 , V_75 ) ;
if ( ! V_143 -> V_130 )
return;
if ( V_102 & V_135 )
V_150 = V_153 ;
else if ( V_102 & V_154 )
V_150 = V_155 ;
else if ( V_102 & V_156 )
V_150 = V_157 ;
if ( V_150 != V_151 )
F_5 ( & V_52 -> V_6 , L_30 , V_11 ,
V_150 ) ;
if ( V_102 & V_158 )
F_72 ( & V_52 -> V_52 , 0 , V_159 ) ;
if ( V_52 -> V_52 . V_160 && V_52 -> V_161 ) {
for ( V_28 = 0 ; V_28 < V_143 -> V_130 ; ++ V_28 )
if ( ! F_73 ( V_52 , V_129 [ V_28 ] ) )
F_72 ( & V_52 -> V_52 , V_129 [ V_28 ] ,
V_150 ) ;
} else {
F_74 ( & V_52 -> V_52 , V_129 , V_150 ,
V_143 -> V_130 ) ;
}
F_75 ( & V_52 -> V_52 ) ;
}
