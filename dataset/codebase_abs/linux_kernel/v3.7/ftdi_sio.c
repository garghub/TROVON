static unsigned short int F_1 ( int V_1 , int V_2 )
{
unsigned short int V_3 ;
int V_4 = V_2 / 2 / V_1 ;
if ( ( V_4 & 0x7 ) == 7 )
V_4 ++ ;
V_3 = V_4 >> 3 ;
V_4 &= 0x7 ;
if ( V_4 == 1 )
V_3 |= 0xc000 ;
else if ( V_4 >= 4 )
V_3 |= 0x4000 ;
else if ( V_4 != 0 )
V_3 |= 0x8000 ;
else if ( V_3 == 1 )
V_3 = 0 ;
return V_3 ;
}
static unsigned short int F_2 ( int V_1 )
{
return F_1 ( V_1 , 48000000 ) ;
}
static T_1 F_3 ( int V_1 , int V_2 )
{
static const unsigned char V_5 [ 8 ] = { 0 , 3 , 2 , 4 , 1 , 5 , 6 , 7 } ;
T_1 V_3 ;
int V_4 = V_2 / 2 / V_1 ;
V_3 = V_4 >> 3 ;
V_3 |= ( T_1 ) V_5 [ V_4 & 0x7 ] << 14 ;
if ( V_3 == 1 )
V_3 = 0 ;
else if ( V_3 == 0x4001 )
V_3 = 1 ;
return V_3 ;
}
static T_1 F_4 ( int V_1 )
{
return F_3 ( V_1 , 48000000 ) ;
}
static T_1 F_5 ( int V_1 , int V_2 )
{
static const unsigned char V_5 [ 8 ] = { 0 , 3 , 2 , 4 , 1 , 5 , 6 , 7 } ;
T_1 V_3 ;
int V_4 ;
V_4 = V_2 * 8 / ( V_1 * 10 ) ;
V_3 = V_4 >> 3 ;
V_3 |= ( T_1 ) V_5 [ V_4 & 0x7 ] << 14 ;
if ( V_3 == 1 )
V_3 = 0 ;
else if ( V_3 == 0x4001 )
V_3 = 1 ;
V_3 |= 0x00020000 ;
return V_3 ;
}
static T_1 F_6 ( int V_1 )
{
return F_5 ( V_1 , 120000000 ) ;
}
static int F_7 ( struct V_6 * V_7 , unsigned int V_8 ,
unsigned int V_9 )
{
struct V_10 * V_11 = F_8 ( V_7 ) ;
struct V_12 * V_13 = & V_7 -> V_13 ;
unsigned V_14 ;
int V_15 ;
if ( ( ( V_8 | V_9 ) & ( V_16 | V_17 ) ) == 0 ) {
F_9 ( V_13 , L_1 , V_18 ) ;
return 0 ;
}
V_9 &= ~ V_8 ;
V_14 = 0 ;
if ( V_9 & V_16 )
V_14 |= V_19 ;
if ( V_9 & V_17 )
V_14 |= V_20 ;
if ( V_8 & V_16 )
V_14 |= V_21 ;
if ( V_8 & V_17 )
V_14 |= V_22 ;
V_15 = F_10 ( V_7 -> V_23 -> V_13 ,
F_11 ( V_7 -> V_23 -> V_13 , 0 ) ,
V_24 ,
V_25 ,
V_14 , V_11 -> V_26 ,
NULL , 0 , V_27 ) ;
if ( V_15 < 0 ) {
F_9 ( V_13 , L_2 ,
V_18 ,
( V_8 & V_16 ) ? L_3 : ( V_9 & V_16 ) ? L_4 : L_5 ,
( V_8 & V_17 ) ? L_3 : ( V_9 & V_17 ) ? L_4 : L_5 ) ;
} else {
F_9 ( V_13 , L_6 , V_18 ,
( V_8 & V_16 ) ? L_3 : ( V_9 & V_16 ) ? L_4 : L_5 ,
( V_8 & V_17 ) ? L_3 : ( V_9 & V_17 ) ? L_4 : L_5 ) ;
V_11 -> V_28 = ( V_11 -> V_28 & ~ V_9 ) | V_8 ;
}
return V_15 ;
}
static T_1 F_12 ( struct V_29 * V_30 ,
struct V_6 * V_7 )
{
struct V_10 * V_11 = F_8 ( V_7 ) ;
struct V_12 * V_13 = & V_7 -> V_13 ;
T_1 V_31 = 0 ;
int V_32 = 1 ;
int V_1 ;
V_1 = F_13 ( V_30 ) ;
F_9 ( V_13 , L_7 , V_18 , V_1 ) ;
if ( V_1 == 38400 &&
( ( V_11 -> V_33 & V_34 ) == V_35 ) &&
( V_11 -> V_36 ) ) {
V_1 = V_11 -> V_37 / V_11 -> V_36 ;
F_9 ( V_13 , L_8 ,
V_18 , V_11 -> V_36 , V_1 ) ;
}
if ( ! V_1 )
V_1 = 9600 ;
switch ( V_11 -> V_38 ) {
case V_39 :
switch ( V_1 ) {
case 300 : V_31 = V_40 ; break;
case 600 : V_31 = V_41 ; break;
case 1200 : V_31 = V_42 ; break;
case 2400 : V_31 = V_43 ; break;
case 4800 : V_31 = V_44 ; break;
case 9600 : V_31 = V_45 ; break;
case 19200 : V_31 = V_46 ; break;
case 38400 : V_31 = V_47 ; break;
case 57600 : V_31 = V_48 ; break;
case 115200 : V_31 = V_49 ; break;
}
if ( V_31 == 0 ) {
F_9 ( V_13 , L_9 ,
V_18 , V_1 ) ;
V_31 = V_45 ;
V_1 = 9600 ;
V_32 = 0 ;
}
break;
case V_50 :
if ( V_1 <= 3000000 ) {
V_31 = F_2 ( V_1 ) ;
} else {
F_9 ( V_13 , L_10 , V_18 ) ;
V_1 = 9600 ;
V_31 = F_2 ( 9600 ) ;
V_32 = 0 ;
}
break;
case V_51 :
case V_52 :
case V_53 :
case V_54 :
if ( V_1 <= 3000000 ) {
T_2 V_55 = F_14 (
V_7 -> V_23 -> V_13 -> V_56 . V_57 ) ;
if ( ( ( V_58 == V_55 ) ||
( V_59 == V_55 ) ||
( V_60 == V_55 ) ||
( V_61 == V_55 ) ||
( V_62 == V_55 ) ) &&
( V_1 == 19200 ) ) {
V_1 = 1200000 ;
}
V_31 = F_4 ( V_1 ) ;
} else {
F_9 ( V_13 , L_10 , V_18 ) ;
V_31 = F_4 ( 9600 ) ;
V_32 = 0 ;
V_1 = 9600 ;
}
break;
case V_63 :
case V_64 :
case V_65 :
if ( ( V_1 <= 12000000 ) && ( V_1 >= 1200 ) ) {
V_31 = F_6 ( V_1 ) ;
} else if ( V_1 < 1200 ) {
V_31 = F_4 ( V_1 ) ;
} else {
F_9 ( V_13 , L_10 , V_18 ) ;
V_31 = F_4 ( 9600 ) ;
V_32 = 0 ;
V_1 = 9600 ;
}
break;
}
if ( V_32 ) {
F_9 ( V_13 , L_11 ,
V_18 , V_1 , ( unsigned long ) V_31 ,
V_66 [ V_11 -> V_38 ] ) ;
}
F_15 ( V_30 , V_1 , V_1 ) ;
return V_31 ;
}
static int F_16 ( struct V_29 * V_30 , struct V_6 * V_7 )
{
struct V_10 * V_11 = F_8 ( V_7 ) ;
T_2 V_14 ;
T_2 V_67 ;
T_1 V_68 ;
int V_15 ;
V_68 = F_12 ( V_30 , V_7 ) ;
V_14 = ( T_2 ) V_68 ;
V_67 = ( T_2 ) ( V_68 >> 16 ) ;
if ( ( V_11 -> V_38 == V_52 ) || ( V_11 -> V_38 == V_63 ) ||
( V_11 -> V_38 == V_64 ) || ( V_11 -> V_38 == V_65 ) ) {
V_67 = ( T_2 ) ( ( V_67 << 8 ) | V_11 -> V_26 ) ;
}
V_15 = F_10 ( V_7 -> V_23 -> V_13 ,
F_11 ( V_7 -> V_23 -> V_13 , 0 ) ,
V_69 ,
V_70 ,
V_14 , V_67 ,
NULL , 0 , V_71 ) ;
return V_15 ;
}
static int F_17 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = F_8 ( V_7 ) ;
struct V_72 * V_73 = V_7 -> V_23 -> V_13 ;
int V_15 ;
int V_74 = V_11 -> V_75 ;
if ( V_11 -> V_33 & V_76 )
V_74 = 1 ;
F_9 ( & V_7 -> V_13 , L_12 , V_18 , V_74 ) ;
V_15 = F_10 ( V_73 ,
F_11 ( V_73 , 0 ) ,
V_77 ,
V_78 ,
V_74 , V_11 -> V_26 ,
NULL , 0 , V_27 ) ;
if ( V_15 < 0 )
F_18 ( & V_7 -> V_13 , L_13 , V_15 ) ;
return V_15 ;
}
static int F_19 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = F_8 ( V_7 ) ;
struct V_72 * V_73 = V_7 -> V_23 -> V_13 ;
unsigned char * V_79 ;
int V_15 ;
V_79 = F_20 ( 1 , V_80 ) ;
if ( ! V_79 )
return - V_81 ;
V_15 = F_10 ( V_73 ,
F_21 ( V_73 , 0 ) ,
V_82 ,
V_83 ,
0 , V_11 -> V_26 ,
V_79 , 1 , V_27 ) ;
if ( V_15 < 0 )
F_18 ( & V_7 -> V_13 , L_14 , V_15 ) ;
else
V_11 -> V_75 = V_79 [ 0 ] ;
F_22 ( V_79 ) ;
return V_15 ;
}
static int F_23 ( struct V_6 * V_7 ,
struct V_84 T_3 * V_85 )
{
struct V_10 * V_11 = F_8 ( V_7 ) ;
struct V_84 V_86 ;
if ( ! V_85 )
return - V_87 ;
memset ( & V_86 , 0 , sizeof( V_86 ) ) ;
V_86 . V_33 = V_11 -> V_33 ;
V_86 . V_37 = V_11 -> V_37 ;
V_86 . V_36 = V_11 -> V_36 ;
if ( F_24 ( V_85 , & V_86 , sizeof( * V_85 ) ) )
return - V_87 ;
return 0 ;
}
static int F_25 ( struct V_29 * V_30 ,
struct V_6 * V_7 , struct V_84 T_3 * V_88 )
{
struct V_10 * V_11 = F_8 ( V_7 ) ;
struct V_84 V_89 ;
struct V_10 V_90 ;
if ( F_26 ( & V_89 , V_88 , sizeof( V_89 ) ) )
return - V_87 ;
F_27 ( & V_11 -> V_91 ) ;
V_90 = * V_11 ;
if ( ! F_28 ( V_92 ) ) {
if ( ( ( V_89 . V_33 & ~ V_93 ) !=
( V_11 -> V_33 & ~ V_93 ) ) ) {
F_29 ( & V_11 -> V_91 ) ;
return - V_94 ;
}
V_11 -> V_33 = ( ( V_11 -> V_33 & ~ V_93 ) |
( V_89 . V_33 & V_93 ) ) ;
V_11 -> V_36 = V_89 . V_36 ;
goto V_95;
}
if ( V_89 . V_37 != V_11 -> V_37 ) {
F_29 ( & V_11 -> V_91 ) ;
return - V_96 ;
}
V_11 -> V_33 = ( ( V_11 -> V_33 & ~ V_97 ) |
( V_89 . V_33 & V_97 ) ) ;
V_11 -> V_36 = V_89 . V_36 ;
F_17 ( V_7 ) ;
V_95:
if ( ( V_90 . V_33 & V_34 ) !=
( V_11 -> V_33 & V_34 ) ) {
if ( ( V_11 -> V_33 & V_34 ) == V_98 )
V_30 -> V_99 = 57600 ;
else if ( ( V_11 -> V_33 & V_34 ) == V_100 )
V_30 -> V_99 = 115200 ;
else if ( ( V_11 -> V_33 & V_34 ) == V_101 )
V_30 -> V_99 = 230400 ;
else if ( ( V_11 -> V_33 & V_34 ) == V_102 )
V_30 -> V_99 = 460800 ;
else
V_30 -> V_99 = 0 ;
}
if ( ( ( V_90 . V_33 & V_34 ) !=
( V_11 -> V_33 & V_34 ) ) ||
( ( ( V_11 -> V_33 & V_34 ) == V_35 ) &&
( V_90 . V_36 != V_11 -> V_36 ) ) ) {
F_16 ( V_30 , V_7 ) ;
F_29 ( & V_11 -> V_91 ) ;
}
else
F_29 ( & V_11 -> V_91 ) ;
return 0 ;
}
static int F_30 ( struct V_6 * V_7 ,
struct V_84 T_3 * V_85 )
{
struct V_10 * V_11 = F_8 ( V_7 ) ;
unsigned int V_103 = 0 ;
if ( ! V_85 )
return - V_87 ;
if ( V_11 -> V_104 )
V_103 = V_105 ;
if ( F_24 ( V_85 , & V_103 , sizeof( unsigned int ) ) )
return - V_87 ;
return 0 ;
}
static void F_31 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = F_8 ( V_7 ) ;
struct V_106 * V_23 = V_7 -> V_23 ;
struct V_72 * V_73 = V_23 -> V_13 ;
unsigned V_107 ;
unsigned V_108 ;
V_11 -> V_37 = 48000000 / 2 ;
V_107 = F_14 ( V_73 -> V_56 . V_109 ) ;
V_108 = V_73 -> V_110 -> V_111 . V_112 ;
F_9 ( & V_7 -> V_13 , L_15 , V_18 ,
V_107 , V_108 ) ;
if ( V_108 > 1 ) {
int V_113 ;
if ( V_107 == 0x0800 ) {
V_11 -> V_38 = V_64 ;
V_11 -> V_37 = 120000000 / 2 ;
} else if ( V_107 == 0x0700 ) {
V_11 -> V_38 = V_63 ;
V_11 -> V_37 = 120000000 / 2 ;
} else
V_11 -> V_38 = V_52 ;
V_113 = V_23 -> V_26 -> V_114 -> V_111 . V_115 ;
if ( V_113 == 0 ) {
V_11 -> V_26 = V_116 ;
} else if ( V_113 == 1 ) {
V_11 -> V_26 = V_117 ;
} else if ( V_113 == 2 ) {
V_11 -> V_26 = V_118 ;
} else if ( V_113 == 3 ) {
V_11 -> V_26 = V_119 ;
}
if ( V_107 < 0x500 ) {
F_9 ( & V_7 -> V_13 ,
L_16 ,
V_18 ) ;
}
} else if ( V_107 < 0x200 ) {
V_11 -> V_38 = V_39 ;
V_11 -> V_37 = 12000000 / 16 ;
} else if ( V_107 < 0x400 ) {
V_11 -> V_38 = V_50 ;
} else if ( V_107 < 0x600 ) {
V_11 -> V_38 = V_51 ;
} else if ( V_107 < 0x900 ) {
V_11 -> V_38 = V_53 ;
} else if ( V_107 < 0x1000 ) {
V_11 -> V_38 = V_65 ;
} else {
V_11 -> V_38 = V_54 ;
}
F_32 ( & V_73 -> V_13 , L_17 , V_66 [ V_11 -> V_38 ] ) ;
}
static void F_33 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = F_8 ( V_7 ) ;
struct V_106 * V_23 = V_7 -> V_23 ;
struct V_72 * V_73 = V_23 -> V_13 ;
struct V_120 * V_26 = V_23 -> V_26 ;
struct V_121 * V_122 = & V_26 -> V_123 -> V_124 [ 1 ] . V_111 ;
unsigned V_125 ;
int V_126 ;
V_125 = V_26 -> V_123 -> V_111 . V_127 ;
F_32 ( & V_73 -> V_13 , L_18 , V_125 ) ;
for ( V_126 = 0 ; V_126 < V_125 ; V_126 ++ ) {
F_32 ( & V_73 -> V_13 , L_19 , V_126 + 1 ,
V_26 -> V_123 -> V_124 [ V_126 ] . V_111 . V_128 ) ;
V_122 = & V_26 -> V_123 -> V_124 [ V_126 ] . V_111 ;
if ( V_122 -> V_128 == 0 ) {
V_122 -> V_128 = F_34 ( 0x40 ) ;
F_32 ( & V_73 -> V_13 , L_20 , V_126 ) ;
}
}
V_11 -> V_129 = F_35 ( V_122 ) ;
F_32 ( & V_73 -> V_13 , L_21 , V_11 -> V_129 ) ;
}
static T_4 F_36 ( struct V_12 * V_13 ,
struct V_130 * V_131 , char * V_79 )
{
struct V_6 * V_7 = F_37 ( V_13 ) ;
struct V_10 * V_11 = F_8 ( V_7 ) ;
if ( V_11 -> V_33 & V_76 )
return sprintf ( V_79 , L_22 ) ;
else
return sprintf ( V_79 , L_23 , V_11 -> V_75 ) ;
}
static T_4 F_38 ( struct V_12 * V_13 ,
struct V_130 * V_131 , const char * V_132 ,
T_5 V_133 )
{
struct V_6 * V_7 = F_37 ( V_13 ) ;
struct V_10 * V_11 = F_8 ( V_7 ) ;
int V_134 = F_39 ( V_132 , NULL , 10 ) ;
int V_15 ;
V_11 -> V_75 = V_134 ;
V_15 = F_17 ( V_7 ) ;
if ( V_15 < 0 )
return - V_135 ;
return V_133 ;
}
static T_4 F_40 ( struct V_12 * V_13 ,
struct V_130 * V_131 , const char * V_132 , T_5 V_133 )
{
struct V_6 * V_7 = F_37 ( V_13 ) ;
struct V_10 * V_11 = F_8 ( V_7 ) ;
struct V_72 * V_73 = V_7 -> V_23 -> V_13 ;
int V_134 = F_39 ( V_132 , NULL , 10 ) ;
int V_15 ;
F_9 ( & V_7 -> V_13 , L_24 , V_18 , V_134 ) ;
V_15 = F_10 ( V_73 ,
F_11 ( V_73 , 0 ) ,
V_136 ,
V_137 ,
V_134 , V_11 -> V_26 ,
NULL , 0 , V_27 ) ;
if ( V_15 < 0 ) {
F_9 ( & V_7 -> V_13 , L_25 , V_15 ) ;
return - V_135 ;
}
return V_133 ;
}
static int F_41 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = F_8 ( V_7 ) ;
int V_138 = 0 ;
if ( V_11 -> V_38 != V_39 ) {
F_9 ( & V_7 -> V_13 , L_26 , V_66 [ V_11 -> V_38 ] ) ;
V_138 = F_42 ( & V_7 -> V_13 , & V_139 ) ;
if ( ( ! V_138 ) &&
( V_11 -> V_38 == V_51 ||
V_11 -> V_38 == V_52 ||
V_11 -> V_38 == V_53 ||
V_11 -> V_38 == V_63 ||
V_11 -> V_38 == V_64 ||
V_11 -> V_38 == V_65 ||
V_11 -> V_38 == V_54 ) ) {
V_138 = F_42 ( & V_7 -> V_13 ,
& V_140 ) ;
}
}
return V_138 ;
}
static void F_43 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = F_8 ( V_7 ) ;
if ( V_11 -> V_38 != V_39 ) {
F_44 ( & V_7 -> V_13 , & V_139 ) ;
if ( V_11 -> V_38 == V_51 ||
V_11 -> V_38 == V_52 ||
V_11 -> V_38 == V_53 ||
V_11 -> V_38 == V_63 ||
V_11 -> V_38 == V_64 ||
V_11 -> V_38 == V_65 ||
V_11 -> V_38 == V_54 ) {
F_44 ( & V_7 -> V_13 , & V_140 ) ;
}
}
}
static int F_45 ( struct V_106 * V_23 ,
const struct V_141 * V_142 )
{
struct V_143 * V_144 =
(struct V_143 * ) V_142 -> V_145 ;
if ( V_144 && V_144 -> V_146 ) {
int V_147 = V_144 -> V_146 ( V_23 ) ;
if ( V_147 != 0 )
return V_147 ;
}
F_46 ( V_23 , ( void * ) V_142 -> V_145 ) ;
return 0 ;
}
static int F_47 ( struct V_6 * V_7 )
{
struct V_10 * V_11 ;
struct V_143 * V_144 = F_48 ( V_7 -> V_23 ) ;
V_11 = F_49 ( sizeof( struct V_10 ) , V_80 ) ;
if ( ! V_11 ) {
F_18 ( & V_7 -> V_13 , L_27 , V_18 ,
sizeof( struct V_10 ) ) ;
return - V_81 ;
}
F_50 ( & V_11 -> V_148 ) ;
F_51 ( & V_11 -> V_91 ) ;
memset ( & V_11 -> V_149 , 0x00 , sizeof( V_11 -> V_149 ) ) ;
F_52 ( & V_11 -> V_150 ) ;
V_11 -> V_33 = V_76 ;
V_11 -> V_151 = false ;
if ( V_144 && V_144 -> V_152 )
V_144 -> V_152 ( V_11 ) ;
V_11 -> V_7 = V_7 ;
F_53 ( V_7 , V_11 ) ;
F_31 ( V_7 ) ;
F_33 ( V_7 ) ;
if ( F_19 ( V_7 ) < 0 )
V_11 -> V_75 = 16 ;
F_17 ( V_7 ) ;
F_41 ( V_7 ) ;
return 0 ;
}
static void F_54 ( struct V_10 * V_11 )
{
V_11 -> V_33 |= V_35 ;
V_11 -> V_36 = 77 ;
V_11 -> V_153 = 38400 ;
}
static void F_55 ( struct V_10 * V_11 )
{
V_11 -> V_33 |= V_35 ;
V_11 -> V_36 = 240 ;
V_11 -> V_153 = 38400 ;
V_11 -> V_154 = 1 ;
}
static int F_56 ( struct V_106 * V_23 )
{
struct V_72 * V_73 = V_23 -> V_13 ;
int V_75 = V_155 ;
if ( V_75 == 0 )
V_75 = 1 ;
if ( V_75 > 99 )
V_75 = 99 ;
F_9 ( & V_73 -> V_13 , L_28 , V_18 , V_75 ) ;
F_32 ( & V_73 -> V_13 , L_29 , V_75 ) ;
F_10 ( V_73 , F_11 ( V_73 , 0 ) ,
V_77 ,
V_78 ,
V_75 , 0 , NULL , 0 , V_27 ) ;
return 0 ;
}
static int F_57 ( struct V_106 * V_23 )
{
struct V_72 * V_73 = V_23 -> V_13 ;
struct V_120 * V_26 = V_23 -> V_26 ;
if ( V_26 == V_73 -> V_110 -> V_26 [ 0 ] ) {
F_32 ( & V_73 -> V_13 ,
L_30 ) ;
return - V_156 ;
}
return 0 ;
}
static int F_58 ( struct V_106 * V_23 )
{
struct V_72 * V_73 = V_23 -> V_13 ;
if ( ( V_73 -> V_157 && ! strcmp ( V_73 -> V_157 , L_31 ) ) ||
( V_73 -> V_158 && ! strcmp ( V_73 -> V_158 , L_32 ) ) )
return F_57 ( V_23 ) ;
return 0 ;
}
static int F_59 ( struct V_106 * V_23 )
{
struct V_72 * V_73 = V_23 -> V_13 ;
struct V_120 * V_26 = V_23 -> V_26 ;
if ( V_26 == V_73 -> V_110 -> V_26 [ 2 ] )
return 0 ;
F_32 ( & V_73 -> V_13 , L_30 ) ;
return - V_156 ;
}
static int F_60 ( struct V_106 * V_23 )
{
struct V_159 * V_160 = V_23 -> V_13 -> V_161 [ 1 ] ;
struct V_121 * V_122 = & V_160 -> V_111 ;
if ( V_160 -> V_162 && V_122 -> V_128 == 0 ) {
V_122 -> V_128 = F_34 ( 0x40 ) ;
F_32 ( & V_23 -> V_13 -> V_13 ,
L_33 ) ;
}
return 0 ;
}
static void F_61 ( struct V_148 * V_163 )
{
struct V_10 * V_11 = F_62 ( V_163 , struct V_10 , V_148 ) ;
F_22 ( V_11 ) ;
}
static int F_63 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = F_8 ( V_7 ) ;
V_11 -> V_151 = true ;
F_64 ( & V_11 -> V_150 ) ;
F_43 ( V_7 ) ;
F_65 ( & V_11 -> V_148 , F_61 ) ;
return 0 ;
}
static int F_66 ( struct V_29 * V_30 , struct V_6 * V_7 )
{
struct V_164 V_165 ;
struct V_72 * V_13 = V_7 -> V_23 -> V_13 ;
struct V_10 * V_11 = F_8 ( V_7 ) ;
int V_103 ;
F_10 ( V_13 , F_11 ( V_13 , 0 ) ,
V_166 , V_167 ,
V_168 ,
V_11 -> V_26 , NULL , 0 , V_27 ) ;
if ( V_30 ) {
memset ( & V_165 , 0 , sizeof( V_165 ) ) ;
F_67 ( V_30 , V_7 , & V_165 ) ;
}
V_103 = F_68 ( V_30 , V_7 ) ;
if ( ! V_103 )
F_69 ( & V_11 -> V_148 ) ;
return V_103 ;
}
static void F_70 ( struct V_6 * V_7 , int V_169 )
{
struct V_10 * V_11 = F_8 ( V_7 ) ;
F_27 ( & V_7 -> V_23 -> V_170 ) ;
if ( ! V_7 -> V_23 -> V_171 ) {
if ( ! V_169 && F_10 ( V_7 -> V_23 -> V_13 ,
F_11 ( V_7 -> V_23 -> V_13 , 0 ) ,
V_172 ,
V_173 ,
0 , V_11 -> V_26 , NULL , 0 ,
V_27 ) < 0 ) {
F_18 ( & V_7 -> V_13 , L_34 ) ;
}
if ( V_169 )
F_71 ( V_7 , V_16 | V_17 ) ;
else
F_72 ( V_7 , V_16 | V_17 ) ;
}
F_29 ( & V_7 -> V_23 -> V_170 ) ;
}
static void F_73 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = F_8 ( V_7 ) ;
F_74 ( V_7 ) ;
F_65 ( & V_11 -> V_148 , F_61 ) ;
}
static int F_75 ( struct V_6 * V_7 ,
void * V_174 , T_5 V_175 )
{
struct V_10 * V_11 ;
int V_133 ;
unsigned long V_33 ;
V_11 = F_8 ( V_7 ) ;
if ( V_11 -> V_38 == V_39 ) {
unsigned char * V_176 = V_174 ;
int V_126 , V_177 , V_178 ;
V_133 = 0 ;
F_76 ( & V_7 -> V_179 , V_33 ) ;
for ( V_126 = 0 ; V_126 < V_175 - 1 ; V_126 += V_11 -> V_129 ) {
V_177 = F_77 ( int , V_175 - V_126 , V_11 -> V_129 ) - 1 ;
V_178 = F_78 ( & V_7 -> V_180 , & V_176 [ V_126 + 1 ] , V_177 ) ;
if ( ! V_178 )
break;
V_11 -> V_149 . V_181 += V_178 ;
V_176 [ V_126 ] = ( V_178 << 2 ) + 1 ;
V_133 += V_178 + 1 ;
}
F_79 ( & V_7 -> V_179 , V_33 ) ;
} else {
V_133 = F_80 ( & V_7 -> V_180 , V_174 , V_175 ,
& V_7 -> V_179 ) ;
V_11 -> V_149 . V_181 += V_133 ;
}
return V_133 ;
}
static int F_81 ( struct V_29 * V_30 ,
struct V_6 * V_7 , struct V_10 * V_11 ,
char * V_182 , int V_177 )
{
int V_126 ;
char V_183 ;
char V_184 ;
char * V_185 ;
if ( V_177 < 2 ) {
F_9 ( & V_7 -> V_13 , L_35 ) ;
return 0 ;
}
V_183 = V_182 [ 0 ] & V_186 ;
if ( V_183 != V_11 -> V_187 ) {
char V_188 = V_183 ^ V_11 -> V_187 ;
if ( V_188 & V_189 )
V_11 -> V_149 . V_190 ++ ;
if ( V_188 & V_191 )
V_11 -> V_149 . V_192 ++ ;
if ( V_188 & V_193 )
V_11 -> V_149 . V_194 ++ ;
if ( V_188 & V_195 )
V_11 -> V_149 . V_196 ++ ;
F_64 ( & V_11 -> V_150 ) ;
V_11 -> V_187 = V_183 ;
}
V_184 = V_197 ;
if ( V_182 [ 1 ] & V_198 ) {
if ( V_182 [ 1 ] & V_199 ) {
V_184 = V_200 ;
V_11 -> V_149 . V_201 ++ ;
F_82 ( V_7 ) ;
} else if ( V_182 [ 1 ] & V_202 ) {
V_184 = V_203 ;
V_11 -> V_149 . V_204 ++ ;
} else if ( V_182 [ 1 ] & V_205 ) {
V_184 = V_206 ;
V_11 -> V_149 . V_207 ++ ;
}
if ( V_182 [ 1 ] & V_208 ) {
V_11 -> V_149 . V_209 ++ ;
F_83 ( V_30 , 0 , V_210 ) ;
}
}
if ( V_182 [ 1 ] & V_211 )
V_11 -> V_104 = 1 ;
else
V_11 -> V_104 = 0 ;
V_177 -= 2 ;
if ( ! V_177 )
return 0 ;
V_11 -> V_149 . V_212 += V_177 ;
V_185 = V_182 + 2 ;
if ( V_7 -> V_7 . V_213 && V_7 -> V_214 ) {
for ( V_126 = 0 ; V_126 < V_177 ; V_126 ++ , V_185 ++ ) {
if ( ! F_84 ( V_7 , * V_185 ) )
F_83 ( V_30 , * V_185 , V_184 ) ;
}
} else {
F_85 ( V_30 , V_185 , V_184 , V_177 ) ;
}
return V_177 ;
}
static void F_86 ( struct V_215 * V_215 )
{
struct V_6 * V_7 = V_215 -> V_216 ;
struct V_29 * V_30 ;
struct V_10 * V_11 = F_8 ( V_7 ) ;
char * V_217 = ( char * ) V_215 -> V_218 ;
int V_126 ;
int V_177 ;
int V_133 = 0 ;
V_30 = F_87 ( & V_7 -> V_7 ) ;
if ( ! V_30 )
return;
for ( V_126 = 0 ; V_126 < V_215 -> V_219 ; V_126 += V_11 -> V_129 ) {
V_177 = F_77 ( int , V_215 -> V_219 - V_126 , V_11 -> V_129 ) ;
V_133 += F_81 ( V_30 , V_7 , V_11 , & V_217 [ V_126 ] , V_177 ) ;
}
if ( V_133 )
F_88 ( V_30 ) ;
F_89 ( V_30 ) ;
}
static void F_90 ( struct V_29 * V_30 , int V_220 )
{
struct V_6 * V_7 = V_30 -> V_221 ;
struct V_10 * V_11 = F_8 ( V_7 ) ;
T_2 V_14 ;
if ( V_220 )
V_14 = V_11 -> V_222 | V_223 ;
else
V_14 = V_11 -> V_222 ;
if ( F_10 ( V_7 -> V_23 -> V_13 ,
F_11 ( V_7 -> V_23 -> V_13 , 0 ) ,
V_224 ,
V_225 ,
V_14 , V_11 -> V_26 ,
NULL , 0 , V_27 ) < 0 ) {
F_18 ( & V_7 -> V_13 , L_36 ,
V_18 , V_220 ) ;
}
F_9 ( & V_7 -> V_13 , L_37 , V_18 ,
V_220 , V_14 ) ;
}
static void F_67 ( struct V_29 * V_30 ,
struct V_6 * V_7 , struct V_164 * V_226 )
{
struct V_72 * V_13 = V_7 -> V_23 -> V_13 ;
struct V_12 * V_227 = & V_7 -> V_13 ;
struct V_10 * V_11 = F_8 ( V_7 ) ;
struct V_164 * V_228 = & V_30 -> V_228 ;
unsigned int V_229 = V_228 -> V_230 ;
T_2 V_14 ;
unsigned int V_231 = V_228 -> V_232 ;
unsigned char V_233 ;
unsigned char V_234 ;
if ( V_11 -> V_153 && ( ( V_228 -> V_230 & V_235 ) != V_236 ) ) {
F_9 ( V_227 , L_38 , V_18 ) ;
F_15 ( V_30 , V_11 -> V_153 ,
V_11 -> V_153 ) ;
}
if ( V_11 -> V_154 ) {
F_9 ( V_227 , L_39 , V_18 ) ;
V_228 -> V_230 |= V_237 ;
}
V_229 = V_228 -> V_230 ;
if ( ! V_226 )
goto V_238;
if ( V_226 -> V_230 == V_228 -> V_230
&& V_226 -> V_239 == V_228 -> V_239
&& V_226 -> V_240 == V_228 -> V_240 )
goto V_241;
if ( ( V_226 -> V_230 & ( V_242 | V_243 | V_244 | V_245 | V_246 ) ) ==
( V_228 -> V_230 & ( V_242 | V_243 | V_244 | V_245 | V_246 ) ) )
goto V_247;
V_238:
V_14 = 0 ;
V_14 |= ( V_229 & V_246 ? V_248 :
V_249 ) ;
if ( V_229 & V_244 ) {
if ( V_229 & V_245 )
V_14 |= V_229 & V_243 ?
V_250 :
V_251 ;
else
V_14 |= V_229 & V_243 ?
V_252 :
V_253 ;
} else {
V_14 |= V_254 ;
}
if ( V_229 & V_242 ) {
switch ( V_229 & V_242 ) {
case V_255 :
V_14 |= 7 ;
F_9 ( V_227 , L_40 ) ;
break;
case V_256 :
V_14 |= 8 ;
F_9 ( V_227 , L_41 ) ;
break;
default:
F_18 ( V_227 , L_42 ) ;
}
}
V_11 -> V_222 = V_14 ;
if ( F_10 ( V_13 , F_11 ( V_13 , 0 ) ,
V_224 ,
V_225 ,
V_14 , V_11 -> V_26 ,
NULL , 0 , V_71 ) < 0 ) {
F_18 ( V_227 , L_43 ,
V_18 ) ;
}
V_247:
if ( ( V_229 & V_235 ) == V_236 ) {
if ( F_10 ( V_13 , F_11 ( V_13 , 0 ) ,
V_172 ,
V_173 ,
0 , V_11 -> V_26 ,
NULL , 0 , V_27 ) < 0 ) {
F_18 ( V_227 , L_44 ,
V_18 ) ;
}
F_72 ( V_7 , V_16 | V_17 ) ;
} else {
F_27 ( & V_11 -> V_91 ) ;
if ( F_16 ( V_30 , V_7 ) )
F_18 ( V_227 , L_45 , V_18 ) ;
F_29 ( & V_11 -> V_91 ) ;
if ( ! V_226 || ( V_226 -> V_230 & V_235 ) == V_236 )
F_71 ( V_7 , V_16 | V_17 ) ;
}
V_241:
if ( V_229 & V_237 ) {
F_9 ( V_227 , L_46 , V_18 ) ;
if ( F_10 ( V_13 ,
F_11 ( V_13 , 0 ) ,
V_172 ,
V_173 ,
0 , ( V_257 | V_11 -> V_26 ) ,
NULL , 0 , V_27 ) < 0 ) {
F_18 ( V_227 , L_47 ) ;
}
} else {
if ( V_231 & V_258 ) {
F_9 ( V_227 , L_48 ,
V_18 , V_231 ) ;
V_234 = V_228 -> V_259 [ V_260 ] ;
V_233 = V_228 -> V_259 [ V_261 ] ;
V_14 = ( V_233 << 8 ) | ( V_234 ) ;
if ( F_10 ( V_13 ,
F_11 ( V_13 , 0 ) ,
V_172 ,
V_173 ,
V_14 , ( V_262
| V_11 -> V_26 ) ,
NULL , 0 , V_27 ) < 0 ) {
F_18 ( & V_7 -> V_13 , L_49
L_50 ) ;
}
} else {
F_9 ( V_227 , L_51 , V_18 ) ;
if ( F_10 ( V_13 ,
F_11 ( V_13 , 0 ) ,
V_172 ,
V_173 ,
0 , V_11 -> V_26 ,
NULL , 0 , V_27 ) < 0 ) {
F_18 ( V_227 , L_52 ) ;
}
}
}
}
static int F_91 ( struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_221 ;
struct V_10 * V_11 = F_8 ( V_7 ) ;
unsigned char * V_79 ;
int V_177 ;
int V_147 ;
V_79 = F_20 ( 2 , V_80 ) ;
if ( ! V_79 )
return - V_81 ;
switch ( V_11 -> V_38 ) {
case V_39 :
V_177 = 1 ;
break;
case V_50 :
case V_51 :
case V_52 :
case V_53 :
case V_63 :
case V_64 :
case V_65 :
case V_54 :
V_177 = 2 ;
break;
default:
V_147 = - V_87 ;
goto V_263;
}
V_147 = F_10 ( V_7 -> V_23 -> V_13 ,
F_21 ( V_7 -> V_23 -> V_13 , 0 ) ,
V_264 ,
V_265 ,
0 , V_11 -> V_26 ,
V_79 , V_177 , V_27 ) ;
if ( V_147 < 0 )
goto V_263;
V_147 = ( V_79 [ 0 ] & V_266 ? V_267 : 0 ) |
( V_79 [ 0 ] & V_268 ? V_269 : 0 ) |
( V_79 [ 0 ] & V_270 ? V_271 : 0 ) |
( V_79 [ 0 ] & V_272 ? V_273 : 0 ) |
V_11 -> V_28 ;
V_263:
F_22 ( V_79 ) ;
return V_147 ;
}
static int F_92 ( struct V_29 * V_30 ,
unsigned int V_8 , unsigned int V_9 )
{
struct V_6 * V_7 = V_30 -> V_221 ;
return F_7 ( V_7 , V_8 , V_9 ) ;
}
static int F_93 ( struct V_29 * V_30 ,
struct V_274 * V_149 )
{
struct V_6 * V_7 = V_30 -> V_221 ;
struct V_10 * V_11 = F_8 ( V_7 ) ;
struct V_275 * V_276 = & V_11 -> V_149 ;
V_149 -> V_190 = V_276 -> V_190 ;
V_149 -> V_192 = V_276 -> V_192 ;
V_149 -> V_194 = V_276 -> V_194 ;
V_149 -> V_196 = V_276 -> V_196 ;
V_149 -> V_181 = V_276 -> V_181 ;
V_149 -> V_212 = V_276 -> V_212 ;
V_149 -> V_207 = V_276 -> V_207 ;
V_149 -> V_204 = V_276 -> V_204 ;
V_149 -> V_209 = V_276 -> V_209 ;
V_149 -> V_201 = V_276 -> V_201 ;
V_149 -> V_277 = V_276 -> V_277 ;
return 0 ;
}
static int F_94 ( struct V_29 * V_30 ,
unsigned int V_278 , unsigned long V_279 )
{
struct V_6 * V_7 = V_30 -> V_221 ;
struct V_10 * V_11 = F_8 ( V_7 ) ;
struct V_275 V_280 ;
struct V_275 V_281 ;
F_9 ( & V_7 -> V_13 , L_53 , V_18 , V_278 ) ;
switch ( V_278 ) {
case V_282 :
return F_23 ( V_7 ,
(struct V_84 T_3 * ) V_279 ) ;
case V_283 :
return F_25 ( V_30 , V_7 ,
(struct V_84 T_3 * ) V_279 ) ;
case V_284 :
V_281 = V_11 -> V_149 ;
while ( ! V_11 -> V_151 ) {
F_95 ( & V_11 -> V_150 ) ;
if ( F_96 ( V_285 ) )
return - V_286 ;
V_280 = V_11 -> V_149 ;
if ( ( ( V_279 & V_287 ) && ( V_280 . V_194 != V_281 . V_194 ) ) ||
( ( V_279 & V_267 ) && ( V_280 . V_192 != V_281 . V_192 ) ) ||
( ( V_279 & V_273 ) && ( V_280 . V_196 != V_281 . V_196 ) ) ||
( ( V_279 & V_269 ) && ( V_280 . V_190 != V_281 . V_190 ) ) ) {
return 0 ;
}
V_281 = V_280 ;
}
return - V_135 ;
break;
case V_288 :
return F_30 ( V_7 , (struct V_84 T_3 * ) V_279 ) ;
break;
default:
break;
}
F_9 ( & V_7 -> V_13 , L_54 ,
V_18 , V_278 ) ;
return - V_289 ;
}
static int T_6 F_97 ( void )
{
if ( V_290 > 0 && V_158 > 0 ) {
int V_126 ;
for ( V_126 = 0 ; V_291 [ V_126 ] . V_292 ; V_126 ++ )
;
V_291 [ V_126 ] . V_293 = V_294 ;
V_291 [ V_126 ] . V_292 = V_290 ;
V_291 [ V_126 ] . V_57 = V_158 ;
}
return F_98 ( V_295 , V_296 , V_291 ) ;
}
static void T_7 F_99 ( void )
{
F_100 ( V_295 ) ;
}
