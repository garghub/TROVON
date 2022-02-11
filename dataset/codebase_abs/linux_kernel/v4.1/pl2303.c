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
enum V_21 type = V_22 ;
unsigned char * V_4 ;
V_20 = F_11 ( sizeof( * V_20 ) , V_23 ) ;
if ( ! V_20 )
return - V_24 ;
V_4 = F_12 ( 1 , V_23 ) ;
if ( ! V_4 ) {
F_13 ( V_20 ) ;
return - V_24 ;
}
if ( V_2 -> V_6 -> V_25 . V_26 == 0x02 )
type = V_22 ;
else if ( V_2 -> V_6 -> V_25 . V_27 == 0x40 )
type = V_28 ;
else if ( V_2 -> V_6 -> V_25 . V_26 == 0x00 )
type = V_22 ;
else if ( V_2 -> V_6 -> V_25 . V_26 == 0xFF )
type = V_22 ;
F_5 ( & V_2 -> V_7 -> V_6 , L_4 , type ) ;
V_20 -> type = & V_29 [ type ] ;
V_20 -> V_30 = ( unsigned long ) F_14 ( V_2 ) ;
V_20 -> V_30 |= V_20 -> type -> V_30 ;
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
if ( V_20 -> V_30 & V_31 )
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
static int F_16 ( struct V_32 * V_33 )
{
struct V_34 * V_35 ;
V_35 = F_11 ( sizeof( * V_35 ) , V_23 ) ;
if ( ! V_35 )
return - V_24 ;
F_17 ( & V_35 -> V_36 ) ;
F_18 ( V_33 , V_35 ) ;
V_33 -> V_33 . V_37 = 256 ;
return 0 ;
}
static int F_19 ( struct V_32 * V_33 )
{
struct V_34 * V_35 = F_20 ( V_33 ) ;
F_13 ( V_35 ) ;
return 0 ;
}
static int F_21 ( struct V_32 * V_33 , T_2 V_3 )
{
struct V_38 * V_6 = V_33 -> V_2 -> V_6 ;
int V_39 ;
F_5 ( & V_33 -> V_6 , L_5 , V_11 , V_3 ) ;
V_39 = F_2 ( V_6 , F_7 ( V_6 , 0 ) ,
V_40 , V_41 ,
V_3 , 0 , NULL , 0 , 100 ) ;
if ( V_39 )
F_4 ( & V_33 -> V_6 , L_6 , V_11 , V_39 ) ;
return V_39 ;
}
static T_3 F_22 ( T_3 V_42 )
{
static const T_3 V_43 [] = {
75 , 150 , 300 , 600 , 1200 , 1800 , 2400 , 3600 , 4800 , 7200 , 9600 ,
14400 , 19200 , 28800 , 38400 , 57600 , 115200 , 230400 , 460800 ,
614400 , 921600 , 1228800 , 2457600 , 3000000 , 6000000
} ;
unsigned V_44 ;
for ( V_44 = 0 ; V_44 < F_23 ( V_43 ) ; ++ V_44 ) {
if ( V_43 [ V_44 ] > V_42 )
break;
}
if ( V_44 == F_23 ( V_43 ) )
V_42 = V_43 [ V_44 - 1 ] ;
else if ( V_44 > 0 && ( V_43 [ V_44 ] - V_42 ) > ( V_42 - V_43 [ V_44 - 1 ] ) )
V_42 = V_43 [ V_44 - 1 ] ;
else
V_42 = V_43 [ V_44 ] ;
return V_42 ;
}
static T_3 F_24 ( unsigned char V_4 [ 4 ] ,
T_3 V_42 )
{
F_25 ( V_42 , V_4 ) ;
return V_42 ;
}
static T_3 F_26 ( unsigned char V_4 [ 4 ] ,
T_3 V_42 )
{
unsigned int V_45 ;
V_45 = 12000000 * 32 / V_42 ;
V_4 [ 3 ] = 0x80 ;
V_4 [ 2 ] = 0 ;
V_4 [ 1 ] = ( V_45 >= 256 ) ;
while ( V_45 >= 256 ) {
V_45 >>= 2 ;
V_4 [ 1 ] <<= 1 ;
}
V_4 [ 0 ] = V_45 ;
return V_42 ;
}
static void F_27 ( struct V_46 * V_47 ,
struct V_32 * V_33 ,
T_2 V_4 [ 4 ] )
{
struct V_1 * V_2 = V_33 -> V_2 ;
struct V_19 * V_20 = F_14 ( V_2 ) ;
T_3 V_43 ;
T_3 V_42 ;
V_42 = F_28 ( V_47 ) ;
F_5 ( & V_33 -> V_6 , L_7 , V_42 ) ;
if ( ! V_42 )
return;
if ( V_20 -> type -> V_48 )
V_42 = F_29 ( T_3 , V_42 , V_20 -> type -> V_48 ) ;
V_43 = F_22 ( V_42 ) ;
if ( V_42 == V_43 )
V_42 = F_24 ( V_4 , V_42 ) ;
else
V_42 = F_26 ( V_4 , V_42 ) ;
F_30 ( V_47 , V_42 , V_42 ) ;
F_5 ( & V_33 -> V_6 , L_8 , V_42 ) ;
}
static int F_31 ( struct V_32 * V_33 ,
unsigned char V_4 [ 7 ] )
{
struct V_38 * V_49 = V_33 -> V_2 -> V_6 ;
int V_50 ;
V_50 = F_2 ( V_49 , F_3 ( V_49 , 0 ) ,
V_51 , V_52 ,
0 , 0 , V_4 , 7 , 100 ) ;
if ( V_50 != 7 ) {
F_4 ( & V_33 -> V_6 , L_6 , V_11 , V_50 ) ;
if ( V_50 > 0 )
V_50 = - V_12 ;
return V_50 ;
}
F_5 ( & V_33 -> V_6 , L_9 , V_11 , V_4 ) ;
return 0 ;
}
static int F_32 ( struct V_32 * V_33 ,
unsigned char V_4 [ 7 ] )
{
struct V_38 * V_49 = V_33 -> V_2 -> V_6 ;
int V_50 ;
V_50 = F_2 ( V_49 , F_7 ( V_49 , 0 ) ,
V_53 , V_54 ,
0 , 0 , V_4 , 7 , 100 ) ;
if ( V_50 != 7 ) {
F_4 ( & V_33 -> V_6 , L_6 , V_11 , V_50 ) ;
if ( V_50 > 0 )
V_50 = - V_12 ;
return V_50 ;
}
F_5 ( & V_33 -> V_6 , L_9 , V_11 , V_4 ) ;
return 0 ;
}
static void F_33 ( struct V_46 * V_47 ,
struct V_32 * V_33 , struct V_55 * V_56 )
{
struct V_1 * V_2 = V_33 -> V_2 ;
struct V_19 * V_20 = F_14 ( V_2 ) ;
struct V_34 * V_35 = F_20 ( V_33 ) ;
unsigned long V_57 ;
unsigned char * V_4 ;
int V_50 ;
T_2 V_58 ;
if ( V_56 && ! F_34 ( & V_47 -> V_59 , V_56 ) )
return;
V_4 = F_11 ( 7 , V_23 ) ;
if ( ! V_4 ) {
if ( V_56 )
V_47 -> V_59 = * V_56 ;
return;
}
F_31 ( V_33 , V_4 ) ;
switch ( F_35 ( V_47 ) ) {
case V_60 :
V_4 [ 6 ] = 5 ;
break;
case V_61 :
V_4 [ 6 ] = 6 ;
break;
case V_62 :
V_4 [ 6 ] = 7 ;
break;
default:
case V_63 :
V_4 [ 6 ] = 8 ;
}
F_5 ( & V_33 -> V_6 , L_10 , V_4 [ 6 ] ) ;
F_27 ( V_47 , V_33 , & V_4 [ 0 ] ) ;
if ( F_36 ( V_47 ) ) {
if ( F_35 ( V_47 ) == V_60 ) {
V_4 [ 4 ] = 1 ;
F_5 ( & V_33 -> V_6 , L_11 ) ;
} else {
V_4 [ 4 ] = 2 ;
F_5 ( & V_33 -> V_6 , L_12 ) ;
}
} else {
V_4 [ 4 ] = 0 ;
F_5 ( & V_33 -> V_6 , L_13 ) ;
}
if ( F_37 ( V_47 ) ) {
if ( F_38 ( V_47 ) ) {
if ( F_39 ( V_47 ) ) {
V_4 [ 5 ] = 3 ;
F_5 ( & V_33 -> V_6 , L_14 ) ;
} else {
V_4 [ 5 ] = 1 ;
F_5 ( & V_33 -> V_6 , L_15 ) ;
}
} else {
if ( F_39 ( V_47 ) ) {
V_4 [ 5 ] = 4 ;
F_5 ( & V_33 -> V_6 , L_16 ) ;
} else {
V_4 [ 5 ] = 2 ;
F_5 ( & V_33 -> V_6 , L_17 ) ;
}
}
} else {
V_4 [ 5 ] = 0 ;
F_5 ( & V_33 -> V_6 , L_18 ) ;
}
if ( ! V_56 || memcmp ( V_4 , V_35 -> V_64 , 7 ) ) {
V_50 = F_32 ( V_33 , V_4 ) ;
if ( ! V_50 )
memcpy ( V_35 -> V_64 , V_4 , 7 ) ;
}
F_40 ( & V_35 -> V_36 , V_57 ) ;
V_58 = V_35 -> V_65 ;
if ( F_41 ( V_47 ) == V_66 )
V_35 -> V_65 &= ~ ( V_67 | V_68 ) ;
else if ( V_56 && ( V_56 -> V_69 & V_70 ) == V_66 )
V_35 -> V_65 |= ( V_67 | V_68 ) ;
if ( V_58 != V_35 -> V_65 ) {
V_58 = V_35 -> V_65 ;
F_42 ( & V_35 -> V_36 , V_57 ) ;
F_21 ( V_33 , V_58 ) ;
} else {
F_42 ( & V_35 -> V_36 , V_57 ) ;
}
if ( F_43 ( V_47 ) ) {
if ( V_20 -> V_30 & V_31 )
F_6 ( V_2 , 0x0 , 0x41 ) ;
else
F_6 ( V_2 , 0x0 , 0x61 ) ;
} else {
F_6 ( V_2 , 0x0 , 0x0 ) ;
}
F_13 ( V_4 ) ;
}
static void F_44 ( struct V_32 * V_33 , int V_71 )
{
struct V_34 * V_35 = F_20 ( V_33 ) ;
unsigned long V_57 ;
T_2 V_58 ;
F_40 ( & V_35 -> V_36 , V_57 ) ;
if ( V_71 )
V_35 -> V_65 |= ( V_67 | V_68 ) ;
else
V_35 -> V_65 &= ~ ( V_67 | V_68 ) ;
V_58 = V_35 -> V_65 ;
F_42 ( & V_35 -> V_36 , V_57 ) ;
F_21 ( V_33 , V_58 ) ;
}
static void F_45 ( struct V_32 * V_33 )
{
F_46 ( V_33 ) ;
F_47 ( V_33 -> V_72 ) ;
F_48 ( V_33 , false ) ;
}
static int F_49 ( struct V_46 * V_47 , struct V_32 * V_33 )
{
struct V_1 * V_2 = V_33 -> V_2 ;
struct V_19 * V_20 = F_14 ( V_2 ) ;
int V_73 ;
if ( V_20 -> V_30 & V_31 ) {
F_50 ( V_2 -> V_6 , V_33 -> V_74 -> V_75 ) ;
F_50 ( V_2 -> V_6 , V_33 -> V_76 -> V_75 ) ;
} else {
F_6 ( V_2 , 8 , 0 ) ;
F_6 ( V_2 , 9 , 0 ) ;
}
if ( V_47 )
F_33 ( V_47 , V_33 , NULL ) ;
V_73 = F_51 ( V_33 -> V_72 , V_23 ) ;
if ( V_73 ) {
F_4 ( & V_33 -> V_6 , L_19 ,
V_73 ) ;
return V_73 ;
}
V_73 = F_52 ( V_47 , V_33 ) ;
if ( V_73 ) {
F_47 ( V_33 -> V_72 ) ;
return V_73 ;
}
return 0 ;
}
static int F_53 ( struct V_46 * V_47 ,
unsigned int V_77 , unsigned int V_78 )
{
struct V_32 * V_33 = V_47 -> V_79 ;
struct V_34 * V_35 = F_20 ( V_33 ) ;
unsigned long V_57 ;
T_2 V_58 ;
int V_50 ;
F_40 ( & V_35 -> V_36 , V_57 ) ;
if ( V_77 & V_80 )
V_35 -> V_65 |= V_68 ;
if ( V_77 & V_81 )
V_35 -> V_65 |= V_67 ;
if ( V_78 & V_80 )
V_35 -> V_65 &= ~ V_68 ;
if ( V_78 & V_81 )
V_35 -> V_65 &= ~ V_67 ;
V_58 = V_35 -> V_65 ;
F_42 ( & V_35 -> V_36 , V_57 ) ;
V_50 = F_21 ( V_33 , V_58 ) ;
if ( V_50 )
return F_54 ( V_50 ) ;
return 0 ;
}
static int F_55 ( struct V_46 * V_47 )
{
struct V_32 * V_33 = V_47 -> V_79 ;
struct V_34 * V_35 = F_20 ( V_33 ) ;
unsigned long V_57 ;
unsigned int V_82 ;
unsigned int V_83 ;
unsigned int V_73 ;
F_40 ( & V_35 -> V_36 , V_57 ) ;
V_82 = V_35 -> V_65 ;
V_83 = V_35 -> V_84 ;
F_42 ( & V_35 -> V_36 , V_57 ) ;
V_73 = ( ( V_82 & V_67 ) ? V_81 : 0 )
| ( ( V_82 & V_68 ) ? V_80 : 0 )
| ( ( V_83 & V_85 ) ? V_86 : 0 )
| ( ( V_83 & V_87 ) ? V_88 : 0 )
| ( ( V_83 & V_89 ) ? V_90 : 0 )
| ( ( V_83 & V_91 ) ? V_92 : 0 ) ;
F_5 ( & V_33 -> V_6 , L_20 , V_11 , V_73 ) ;
return V_73 ;
}
static int F_56 ( struct V_32 * V_33 )
{
struct V_34 * V_35 = F_20 ( V_33 ) ;
if ( V_35 -> V_84 & V_91 )
return 1 ;
return 0 ;
}
static int F_57 ( struct V_46 * V_47 ,
unsigned int V_93 , unsigned long V_94 )
{
struct V_95 V_96 ;
struct V_32 * V_33 = V_47 -> V_79 ;
switch ( V_93 ) {
case V_97 :
memset ( & V_96 , 0 , sizeof V_96 ) ;
V_96 . type = V_98 ;
V_96 . line = V_33 -> V_99 ;
V_96 . V_33 = V_33 -> V_100 ;
V_96 . V_101 = 460800 ;
if ( F_58 ( ( void V_102 * ) V_94 , & V_96 , sizeof V_96 ) )
return - V_103 ;
return 0 ;
default:
break;
}
return - V_104 ;
}
static void F_48 ( struct V_32 * V_33 , bool V_105 )
{
struct V_1 * V_2 = V_33 -> V_2 ;
T_1 V_106 ;
int V_73 ;
if ( V_105 )
V_106 = V_107 ;
else
V_106 = V_108 ;
F_5 ( & V_33 -> V_6 , L_21 , V_11 ,
V_106 == V_108 ? L_22 : L_23 ) ;
V_73 = F_2 ( V_2 -> V_6 , F_7 ( V_2 -> V_6 , 0 ) ,
V_109 , V_110 , V_106 ,
0 , NULL , 0 , 100 ) ;
if ( V_73 )
F_4 ( & V_33 -> V_6 , L_24 , V_73 ) ;
}
static void F_59 ( struct V_46 * V_47 , int V_106 )
{
struct V_32 * V_33 = V_47 -> V_79 ;
F_48 ( V_33 , V_106 ) ;
}
static void F_60 ( struct V_32 * V_33 ,
unsigned char * V_111 ,
unsigned int V_112 )
{
struct V_1 * V_2 = V_33 -> V_2 ;
struct V_19 * V_20 = F_14 ( V_2 ) ;
struct V_34 * V_35 = F_20 ( V_33 ) ;
struct V_46 * V_47 ;
unsigned long V_57 ;
unsigned int V_113 = V_114 ;
T_2 V_83 ;
T_2 V_115 ;
if ( V_20 -> V_30 & V_116 )
V_113 = 0 ;
if ( V_112 < V_113 + 1 )
return;
V_83 = V_111 [ V_113 ] ;
F_40 ( & V_35 -> V_36 , V_57 ) ;
V_115 = V_35 -> V_84 ^ V_83 ;
V_35 -> V_84 = V_83 ;
F_42 ( & V_35 -> V_36 , V_57 ) ;
if ( V_83 & V_117 )
F_61 ( V_33 ) ;
if ( V_115 & V_118 ) {
if ( V_115 & V_85 )
V_33 -> V_119 . V_120 ++ ;
if ( V_115 & V_87 )
V_33 -> V_119 . V_121 ++ ;
if ( V_115 & V_89 )
V_33 -> V_119 . V_122 ++ ;
if ( V_115 & V_91 ) {
V_33 -> V_119 . V_123 ++ ;
V_47 = F_62 ( & V_33 -> V_33 ) ;
if ( V_47 ) {
F_63 ( V_33 , V_47 ,
V_83 & V_91 ) ;
F_64 ( V_47 ) ;
}
}
F_65 ( & V_33 -> V_33 . V_124 ) ;
}
}
static void F_66 ( struct V_125 * V_125 )
{
struct V_32 * V_33 = V_125 -> V_126 ;
unsigned char * V_111 = V_125 -> V_127 ;
unsigned int V_112 = V_125 -> V_112 ;
int V_83 = V_125 -> V_83 ;
int V_39 ;
switch ( V_83 ) {
case 0 :
break;
case - V_128 :
case - V_129 :
case - V_130 :
F_5 ( & V_33 -> V_6 , L_25 ,
V_11 , V_83 ) ;
return;
default:
F_5 ( & V_33 -> V_6 , L_26 ,
V_11 , V_83 ) ;
goto exit;
}
F_67 ( & V_33 -> V_6 , V_11 ,
V_125 -> V_112 , V_125 -> V_127 ) ;
F_60 ( V_33 , V_111 , V_112 ) ;
exit:
V_39 = F_51 ( V_125 , V_131 ) ;
if ( V_39 ) {
F_4 ( & V_33 -> V_6 ,
L_27 ,
V_11 , V_39 ) ;
}
}
static void F_68 ( struct V_125 * V_125 )
{
struct V_32 * V_33 = V_125 -> V_126 ;
struct V_34 * V_35 = F_20 ( V_33 ) ;
unsigned char * V_111 = V_125 -> V_127 ;
char V_132 = V_133 ;
unsigned long V_57 ;
T_2 V_84 ;
int V_44 ;
F_40 ( & V_35 -> V_36 , V_57 ) ;
V_84 = V_35 -> V_84 ;
V_35 -> V_84 &= ~ V_134 ;
F_42 ( & V_35 -> V_36 , V_57 ) ;
if ( ! V_125 -> V_112 )
return;
if ( V_84 & V_117 )
V_132 = V_135 ;
else if ( V_84 & V_136 )
V_132 = V_137 ;
else if ( V_84 & V_138 )
V_132 = V_139 ;
if ( V_132 != V_133 )
F_5 ( & V_33 -> V_6 , L_28 , V_11 ,
V_132 ) ;
if ( V_84 & V_140 )
F_69 ( & V_33 -> V_33 , 0 , V_141 ) ;
if ( V_33 -> V_33 . V_142 && V_33 -> V_143 ) {
for ( V_44 = 0 ; V_44 < V_125 -> V_112 ; ++ V_44 )
if ( ! F_70 ( V_33 , V_111 [ V_44 ] ) )
F_69 ( & V_33 -> V_33 , V_111 [ V_44 ] ,
V_132 ) ;
} else {
F_71 ( & V_33 -> V_33 , V_111 , V_132 ,
V_125 -> V_112 ) ;
}
F_72 ( & V_33 -> V_33 ) ;
}
