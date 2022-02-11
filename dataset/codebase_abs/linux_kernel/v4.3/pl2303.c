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
unsigned int V_45 , V_46 , V_47 ;
V_45 = 12000000 * 32 ;
V_46 = V_45 / V_42 ;
if ( V_46 == 0 )
V_46 = 1 ;
V_47 = 0 ;
while ( V_46 >= 512 ) {
if ( V_47 < 7 ) {
V_46 >>= 2 ;
V_47 ++ ;
} else {
V_46 = 511 ;
break;
}
}
V_4 [ 3 ] = 0x80 ;
V_4 [ 2 ] = 0 ;
V_4 [ 1 ] = V_47 << 1 | V_46 >> 8 ;
V_4 [ 0 ] = V_46 & 0xff ;
V_42 = ( V_45 / V_46 ) >> ( V_47 << 1 ) ;
return V_42 ;
}
static void F_27 ( struct V_48 * V_49 ,
struct V_32 * V_33 ,
T_2 V_4 [ 4 ] )
{
struct V_1 * V_2 = V_33 -> V_2 ;
struct V_19 * V_20 = F_14 ( V_2 ) ;
T_3 V_43 ;
T_3 V_42 ;
V_42 = F_28 ( V_49 ) ;
F_5 ( & V_33 -> V_6 , L_7 , V_42 ) ;
if ( ! V_42 )
return;
if ( V_20 -> type -> V_50 )
V_42 = F_29 ( T_3 , V_42 , V_20 -> type -> V_50 ) ;
V_43 = F_22 ( V_42 ) ;
if ( V_42 == V_43 )
V_42 = F_24 ( V_4 , V_42 ) ;
else
V_42 = F_26 ( V_4 , V_42 ) ;
F_30 ( V_49 , V_42 , V_42 ) ;
F_5 ( & V_33 -> V_6 , L_8 , V_42 ) ;
}
static int F_31 ( struct V_32 * V_33 ,
unsigned char V_4 [ 7 ] )
{
struct V_38 * V_51 = V_33 -> V_2 -> V_6 ;
int V_52 ;
V_52 = F_2 ( V_51 , F_3 ( V_51 , 0 ) ,
V_53 , V_54 ,
0 , 0 , V_4 , 7 , 100 ) ;
if ( V_52 != 7 ) {
F_4 ( & V_33 -> V_6 , L_6 , V_11 , V_52 ) ;
if ( V_52 > 0 )
V_52 = - V_12 ;
return V_52 ;
}
F_5 ( & V_33 -> V_6 , L_9 , V_11 , V_4 ) ;
return 0 ;
}
static int F_32 ( struct V_32 * V_33 ,
unsigned char V_4 [ 7 ] )
{
struct V_38 * V_51 = V_33 -> V_2 -> V_6 ;
int V_52 ;
V_52 = F_2 ( V_51 , F_7 ( V_51 , 0 ) ,
V_55 , V_56 ,
0 , 0 , V_4 , 7 , 100 ) ;
if ( V_52 != 7 ) {
F_4 ( & V_33 -> V_6 , L_6 , V_11 , V_52 ) ;
if ( V_52 > 0 )
V_52 = - V_12 ;
return V_52 ;
}
F_5 ( & V_33 -> V_6 , L_9 , V_11 , V_4 ) ;
return 0 ;
}
static void F_33 ( struct V_48 * V_49 ,
struct V_32 * V_33 , struct V_57 * V_58 )
{
struct V_1 * V_2 = V_33 -> V_2 ;
struct V_19 * V_20 = F_14 ( V_2 ) ;
struct V_34 * V_35 = F_20 ( V_33 ) ;
unsigned long V_59 ;
unsigned char * V_4 ;
int V_52 ;
T_2 V_60 ;
if ( V_58 && ! F_34 ( & V_49 -> V_61 , V_58 ) )
return;
V_4 = F_11 ( 7 , V_23 ) ;
if ( ! V_4 ) {
if ( V_58 )
V_49 -> V_61 = * V_58 ;
return;
}
F_31 ( V_33 , V_4 ) ;
switch ( F_35 ( V_49 ) ) {
case V_62 :
V_4 [ 6 ] = 5 ;
break;
case V_63 :
V_4 [ 6 ] = 6 ;
break;
case V_64 :
V_4 [ 6 ] = 7 ;
break;
default:
case V_65 :
V_4 [ 6 ] = 8 ;
}
F_5 ( & V_33 -> V_6 , L_10 , V_4 [ 6 ] ) ;
F_27 ( V_49 , V_33 , & V_4 [ 0 ] ) ;
if ( F_36 ( V_49 ) ) {
if ( F_35 ( V_49 ) == V_62 ) {
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
if ( F_37 ( V_49 ) ) {
if ( F_38 ( V_49 ) ) {
if ( F_39 ( V_49 ) ) {
V_4 [ 5 ] = 3 ;
F_5 ( & V_33 -> V_6 , L_14 ) ;
} else {
V_4 [ 5 ] = 1 ;
F_5 ( & V_33 -> V_6 , L_15 ) ;
}
} else {
if ( F_39 ( V_49 ) ) {
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
if ( ! V_58 || memcmp ( V_4 , V_35 -> V_66 , 7 ) ) {
V_52 = F_32 ( V_33 , V_4 ) ;
if ( ! V_52 )
memcpy ( V_35 -> V_66 , V_4 , 7 ) ;
}
F_40 ( & V_35 -> V_36 , V_59 ) ;
V_60 = V_35 -> V_67 ;
if ( F_41 ( V_49 ) == V_68 )
V_35 -> V_67 &= ~ ( V_69 | V_70 ) ;
else if ( V_58 && ( V_58 -> V_71 & V_72 ) == V_68 )
V_35 -> V_67 |= ( V_69 | V_70 ) ;
if ( V_60 != V_35 -> V_67 ) {
V_60 = V_35 -> V_67 ;
F_42 ( & V_35 -> V_36 , V_59 ) ;
F_21 ( V_33 , V_60 ) ;
} else {
F_42 ( & V_35 -> V_36 , V_59 ) ;
}
if ( F_43 ( V_49 ) ) {
if ( V_20 -> V_30 & V_31 )
F_6 ( V_2 , 0x0 , 0x41 ) ;
else
F_6 ( V_2 , 0x0 , 0x61 ) ;
} else {
F_6 ( V_2 , 0x0 , 0x0 ) ;
}
F_13 ( V_4 ) ;
}
static void F_44 ( struct V_32 * V_33 , int V_73 )
{
struct V_34 * V_35 = F_20 ( V_33 ) ;
unsigned long V_59 ;
T_2 V_60 ;
F_40 ( & V_35 -> V_36 , V_59 ) ;
if ( V_73 )
V_35 -> V_67 |= ( V_69 | V_70 ) ;
else
V_35 -> V_67 &= ~ ( V_69 | V_70 ) ;
V_60 = V_35 -> V_67 ;
F_42 ( & V_35 -> V_36 , V_59 ) ;
F_21 ( V_33 , V_60 ) ;
}
static void F_45 ( struct V_32 * V_33 )
{
F_46 ( V_33 ) ;
F_47 ( V_33 -> V_74 ) ;
F_48 ( V_33 , false ) ;
}
static int F_49 ( struct V_48 * V_49 , struct V_32 * V_33 )
{
struct V_1 * V_2 = V_33 -> V_2 ;
struct V_19 * V_20 = F_14 ( V_2 ) ;
int V_75 ;
if ( V_20 -> V_30 & V_31 ) {
F_50 ( V_2 -> V_6 , V_33 -> V_76 -> V_77 ) ;
F_50 ( V_2 -> V_6 , V_33 -> V_78 -> V_77 ) ;
} else {
F_6 ( V_2 , 8 , 0 ) ;
F_6 ( V_2 , 9 , 0 ) ;
}
if ( V_49 )
F_33 ( V_49 , V_33 , NULL ) ;
V_75 = F_51 ( V_33 -> V_74 , V_23 ) ;
if ( V_75 ) {
F_4 ( & V_33 -> V_6 , L_19 ,
V_75 ) ;
return V_75 ;
}
V_75 = F_52 ( V_49 , V_33 ) ;
if ( V_75 ) {
F_47 ( V_33 -> V_74 ) ;
return V_75 ;
}
return 0 ;
}
static int F_53 ( struct V_48 * V_49 ,
unsigned int V_79 , unsigned int V_80 )
{
struct V_32 * V_33 = V_49 -> V_81 ;
struct V_34 * V_35 = F_20 ( V_33 ) ;
unsigned long V_59 ;
T_2 V_60 ;
int V_52 ;
F_40 ( & V_35 -> V_36 , V_59 ) ;
if ( V_79 & V_82 )
V_35 -> V_67 |= V_70 ;
if ( V_79 & V_83 )
V_35 -> V_67 |= V_69 ;
if ( V_80 & V_82 )
V_35 -> V_67 &= ~ V_70 ;
if ( V_80 & V_83 )
V_35 -> V_67 &= ~ V_69 ;
V_60 = V_35 -> V_67 ;
F_42 ( & V_35 -> V_36 , V_59 ) ;
V_52 = F_21 ( V_33 , V_60 ) ;
if ( V_52 )
return F_54 ( V_52 ) ;
return 0 ;
}
static int F_55 ( struct V_48 * V_49 )
{
struct V_32 * V_33 = V_49 -> V_81 ;
struct V_34 * V_35 = F_20 ( V_33 ) ;
unsigned long V_59 ;
unsigned int V_84 ;
unsigned int V_85 ;
unsigned int V_75 ;
F_40 ( & V_35 -> V_36 , V_59 ) ;
V_84 = V_35 -> V_67 ;
V_85 = V_35 -> V_86 ;
F_42 ( & V_35 -> V_36 , V_59 ) ;
V_75 = ( ( V_84 & V_69 ) ? V_83 : 0 )
| ( ( V_84 & V_70 ) ? V_82 : 0 )
| ( ( V_85 & V_87 ) ? V_88 : 0 )
| ( ( V_85 & V_89 ) ? V_90 : 0 )
| ( ( V_85 & V_91 ) ? V_92 : 0 )
| ( ( V_85 & V_93 ) ? V_94 : 0 ) ;
F_5 ( & V_33 -> V_6 , L_20 , V_11 , V_75 ) ;
return V_75 ;
}
static int F_56 ( struct V_32 * V_33 )
{
struct V_34 * V_35 = F_20 ( V_33 ) ;
if ( V_35 -> V_86 & V_93 )
return 1 ;
return 0 ;
}
static int F_57 ( struct V_48 * V_49 ,
unsigned int V_95 , unsigned long V_96 )
{
struct V_97 V_98 ;
struct V_32 * V_33 = V_49 -> V_81 ;
switch ( V_95 ) {
case V_99 :
memset ( & V_98 , 0 , sizeof V_98 ) ;
V_98 . type = V_100 ;
V_98 . line = V_33 -> V_101 ;
V_98 . V_33 = V_33 -> V_102 ;
V_98 . V_103 = 460800 ;
if ( F_58 ( ( void V_104 * ) V_96 , & V_98 , sizeof V_98 ) )
return - V_105 ;
return 0 ;
default:
break;
}
return - V_106 ;
}
static void F_48 ( struct V_32 * V_33 , bool V_107 )
{
struct V_1 * V_2 = V_33 -> V_2 ;
T_1 V_108 ;
int V_75 ;
if ( V_107 )
V_108 = V_109 ;
else
V_108 = V_110 ;
F_5 ( & V_33 -> V_6 , L_21 , V_11 ,
V_108 == V_110 ? L_22 : L_23 ) ;
V_75 = F_2 ( V_2 -> V_6 , F_7 ( V_2 -> V_6 , 0 ) ,
V_111 , V_112 , V_108 ,
0 , NULL , 0 , 100 ) ;
if ( V_75 )
F_4 ( & V_33 -> V_6 , L_24 , V_75 ) ;
}
static void F_59 ( struct V_48 * V_49 , int V_108 )
{
struct V_32 * V_33 = V_49 -> V_81 ;
F_48 ( V_33 , V_108 ) ;
}
static void F_60 ( struct V_32 * V_33 ,
unsigned char * V_113 ,
unsigned int V_114 )
{
struct V_1 * V_2 = V_33 -> V_2 ;
struct V_19 * V_20 = F_14 ( V_2 ) ;
struct V_34 * V_35 = F_20 ( V_33 ) ;
struct V_48 * V_49 ;
unsigned long V_59 ;
unsigned int V_115 = V_116 ;
T_2 V_85 ;
T_2 V_117 ;
if ( V_20 -> V_30 & V_118 )
V_115 = 0 ;
if ( V_114 < V_115 + 1 )
return;
V_85 = V_113 [ V_115 ] ;
F_40 ( & V_35 -> V_36 , V_59 ) ;
V_117 = V_35 -> V_86 ^ V_85 ;
V_35 -> V_86 = V_85 ;
F_42 ( & V_35 -> V_36 , V_59 ) ;
if ( V_85 & V_119 )
F_61 ( V_33 ) ;
if ( V_117 & V_120 ) {
if ( V_117 & V_87 )
V_33 -> V_121 . V_122 ++ ;
if ( V_117 & V_89 )
V_33 -> V_121 . V_123 ++ ;
if ( V_117 & V_91 )
V_33 -> V_121 . V_124 ++ ;
if ( V_117 & V_93 ) {
V_33 -> V_121 . V_125 ++ ;
V_49 = F_62 ( & V_33 -> V_33 ) ;
if ( V_49 ) {
F_63 ( V_33 , V_49 ,
V_85 & V_93 ) ;
F_64 ( V_49 ) ;
}
}
F_65 ( & V_33 -> V_33 . V_126 ) ;
}
}
static void F_66 ( struct V_127 * V_127 )
{
struct V_32 * V_33 = V_127 -> V_128 ;
unsigned char * V_113 = V_127 -> V_129 ;
unsigned int V_114 = V_127 -> V_114 ;
int V_85 = V_127 -> V_85 ;
int V_39 ;
switch ( V_85 ) {
case 0 :
break;
case - V_130 :
case - V_131 :
case - V_132 :
F_5 ( & V_33 -> V_6 , L_25 ,
V_11 , V_85 ) ;
return;
default:
F_5 ( & V_33 -> V_6 , L_26 ,
V_11 , V_85 ) ;
goto exit;
}
F_67 ( & V_33 -> V_6 , V_11 ,
V_127 -> V_114 , V_127 -> V_129 ) ;
F_60 ( V_33 , V_113 , V_114 ) ;
exit:
V_39 = F_51 ( V_127 , V_133 ) ;
if ( V_39 ) {
F_4 ( & V_33 -> V_6 ,
L_27 ,
V_11 , V_39 ) ;
}
}
static void F_68 ( struct V_127 * V_127 )
{
struct V_32 * V_33 = V_127 -> V_128 ;
struct V_34 * V_35 = F_20 ( V_33 ) ;
unsigned char * V_113 = V_127 -> V_129 ;
char V_134 = V_135 ;
unsigned long V_59 ;
T_2 V_86 ;
int V_44 ;
F_40 ( & V_35 -> V_36 , V_59 ) ;
V_86 = V_35 -> V_86 ;
V_35 -> V_86 &= ~ V_136 ;
F_42 ( & V_35 -> V_36 , V_59 ) ;
if ( ! V_127 -> V_114 )
return;
if ( V_86 & V_119 )
V_134 = V_137 ;
else if ( V_86 & V_138 )
V_134 = V_139 ;
else if ( V_86 & V_140 )
V_134 = V_141 ;
if ( V_134 != V_135 )
F_5 ( & V_33 -> V_6 , L_28 , V_11 ,
V_134 ) ;
if ( V_86 & V_142 )
F_69 ( & V_33 -> V_33 , 0 , V_143 ) ;
if ( V_33 -> V_33 . V_144 && V_33 -> V_145 ) {
for ( V_44 = 0 ; V_44 < V_127 -> V_114 ; ++ V_44 )
if ( ! F_70 ( V_33 , V_113 [ V_44 ] ) )
F_69 ( & V_33 -> V_33 , V_113 [ V_44 ] ,
V_134 ) ;
} else {
F_71 ( & V_33 -> V_33 , V_113 , V_134 ,
V_127 -> V_114 ) ;
}
F_72 ( & V_33 -> V_33 ) ;
}
