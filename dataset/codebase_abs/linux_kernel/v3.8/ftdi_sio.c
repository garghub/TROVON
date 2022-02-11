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
V_15 = F_12 ( V_15 ) ;
} else {
F_9 ( V_13 , L_6 , V_18 ,
( V_8 & V_16 ) ? L_3 : ( V_9 & V_16 ) ? L_4 : L_5 ,
( V_8 & V_17 ) ? L_3 : ( V_9 & V_17 ) ? L_4 : L_5 ) ;
V_11 -> V_28 = ( V_11 -> V_28 & ~ V_9 ) | V_8 ;
}
return V_15 ;
}
static T_1 F_13 ( struct V_29 * V_30 ,
struct V_6 * V_7 )
{
struct V_10 * V_11 = F_8 ( V_7 ) ;
struct V_12 * V_13 = & V_7 -> V_13 ;
T_1 V_31 = 0 ;
int V_32 = 1 ;
int V_1 ;
V_1 = F_14 ( V_30 ) ;
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
T_2 V_55 = F_15 (
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
F_16 ( V_30 , V_1 , V_1 ) ;
return V_31 ;
}
static int F_17 ( struct V_29 * V_30 , struct V_6 * V_7 )
{
struct V_10 * V_11 = F_8 ( V_7 ) ;
T_2 V_14 ;
T_2 V_67 ;
T_1 V_68 ;
int V_15 ;
V_68 = F_13 ( V_30 , V_7 ) ;
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
static int F_18 ( struct V_6 * V_7 )
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
F_19 ( & V_7 -> V_13 , L_13 , V_15 ) ;
return V_15 ;
}
static int F_20 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = F_8 ( V_7 ) ;
struct V_72 * V_73 = V_7 -> V_23 -> V_13 ;
unsigned char * V_79 ;
int V_15 ;
V_79 = F_21 ( 1 , V_80 ) ;
if ( ! V_79 )
return - V_81 ;
V_15 = F_10 ( V_73 ,
F_22 ( V_73 , 0 ) ,
V_82 ,
V_83 ,
0 , V_11 -> V_26 ,
V_79 , 1 , V_27 ) ;
if ( V_15 < 0 )
F_19 ( & V_7 -> V_13 , L_14 , V_15 ) ;
else
V_11 -> V_75 = V_79 [ 0 ] ;
F_23 ( V_79 ) ;
return V_15 ;
}
static int F_24 ( struct V_6 * V_7 ,
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
if ( F_25 ( V_85 , & V_86 , sizeof( * V_85 ) ) )
return - V_87 ;
return 0 ;
}
static int F_26 ( struct V_29 * V_30 ,
struct V_6 * V_7 , struct V_84 T_3 * V_88 )
{
struct V_10 * V_11 = F_8 ( V_7 ) ;
struct V_84 V_89 ;
struct V_10 V_90 ;
if ( F_27 ( & V_89 , V_88 , sizeof( V_89 ) ) )
return - V_87 ;
F_28 ( & V_11 -> V_91 ) ;
V_90 = * V_11 ;
if ( ! F_29 ( V_92 ) ) {
if ( ( ( V_89 . V_33 & ~ V_93 ) !=
( V_11 -> V_33 & ~ V_93 ) ) ) {
F_30 ( & V_11 -> V_91 ) ;
return - V_94 ;
}
V_11 -> V_33 = ( ( V_11 -> V_33 & ~ V_93 ) |
( V_89 . V_33 & V_93 ) ) ;
V_11 -> V_36 = V_89 . V_36 ;
goto V_95;
}
if ( V_89 . V_37 != V_11 -> V_37 ) {
F_30 ( & V_11 -> V_91 ) ;
return - V_96 ;
}
V_11 -> V_33 = ( ( V_11 -> V_33 & ~ V_97 ) |
( V_89 . V_33 & V_97 ) ) ;
V_11 -> V_36 = V_89 . V_36 ;
F_18 ( V_7 ) ;
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
F_17 ( V_30 , V_7 ) ;
F_30 ( & V_11 -> V_91 ) ;
}
else
F_30 ( & V_11 -> V_91 ) ;
return 0 ;
}
static int F_31 ( struct V_6 * V_7 ,
struct V_84 T_3 * V_85 )
{
struct V_10 * V_11 = F_8 ( V_7 ) ;
unsigned int V_103 = 0 ;
if ( ! V_85 )
return - V_87 ;
if ( V_11 -> V_104 )
V_103 = V_105 ;
if ( F_25 ( V_85 , & V_103 , sizeof( unsigned int ) ) )
return - V_87 ;
return 0 ;
}
static void F_32 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = F_8 ( V_7 ) ;
struct V_106 * V_23 = V_7 -> V_23 ;
struct V_72 * V_73 = V_23 -> V_13 ;
unsigned V_107 ;
unsigned V_108 ;
V_11 -> V_37 = 48000000 / 2 ;
V_107 = F_15 ( V_73 -> V_56 . V_109 ) ;
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
F_33 ( & V_73 -> V_13 , L_17 , V_66 [ V_11 -> V_38 ] ) ;
}
static void F_34 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = F_8 ( V_7 ) ;
struct V_106 * V_23 = V_7 -> V_23 ;
struct V_72 * V_73 = V_23 -> V_13 ;
struct V_120 * V_26 = V_23 -> V_26 ;
struct V_121 * V_122 = & V_26 -> V_123 -> V_124 [ 1 ] . V_111 ;
unsigned V_125 ;
int V_126 ;
V_125 = V_26 -> V_123 -> V_111 . V_127 ;
F_33 ( & V_73 -> V_13 , L_18 , V_125 ) ;
for ( V_126 = 0 ; V_126 < V_125 ; V_126 ++ ) {
F_33 ( & V_73 -> V_13 , L_19 , V_126 + 1 ,
V_26 -> V_123 -> V_124 [ V_126 ] . V_111 . V_128 ) ;
V_122 = & V_26 -> V_123 -> V_124 [ V_126 ] . V_111 ;
if ( V_122 -> V_128 == 0 ) {
V_122 -> V_128 = F_35 ( 0x40 ) ;
F_33 ( & V_73 -> V_13 , L_20 , V_126 ) ;
}
}
V_11 -> V_129 = F_36 ( V_122 ) ;
F_33 ( & V_73 -> V_13 , L_21 , V_11 -> V_129 ) ;
}
static T_4 F_37 ( struct V_12 * V_13 ,
struct V_130 * V_131 , char * V_79 )
{
struct V_6 * V_7 = F_38 ( V_13 ) ;
struct V_10 * V_11 = F_8 ( V_7 ) ;
if ( V_11 -> V_33 & V_76 )
return sprintf ( V_79 , L_22 ) ;
else
return sprintf ( V_79 , L_23 , V_11 -> V_75 ) ;
}
static T_4 F_39 ( struct V_12 * V_13 ,
struct V_130 * V_131 , const char * V_132 ,
T_5 V_133 )
{
struct V_6 * V_7 = F_38 ( V_13 ) ;
struct V_10 * V_11 = F_8 ( V_7 ) ;
int V_134 = F_40 ( V_132 , NULL , 10 ) ;
int V_15 ;
V_11 -> V_75 = V_134 ;
V_15 = F_18 ( V_7 ) ;
if ( V_15 < 0 )
return - V_135 ;
return V_133 ;
}
static T_4 F_41 ( struct V_12 * V_13 ,
struct V_130 * V_131 , const char * V_132 , T_5 V_133 )
{
struct V_6 * V_7 = F_38 ( V_13 ) ;
struct V_10 * V_11 = F_8 ( V_7 ) ;
struct V_72 * V_73 = V_7 -> V_23 -> V_13 ;
int V_134 = F_40 ( V_132 , NULL , 10 ) ;
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
static int F_42 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = F_8 ( V_7 ) ;
int V_138 = 0 ;
if ( V_11 -> V_38 != V_39 ) {
F_9 ( & V_7 -> V_13 , L_26 , V_66 [ V_11 -> V_38 ] ) ;
V_138 = F_43 ( & V_7 -> V_13 , & V_139 ) ;
if ( ( ! V_138 ) &&
( V_11 -> V_38 == V_51 ||
V_11 -> V_38 == V_52 ||
V_11 -> V_38 == V_53 ||
V_11 -> V_38 == V_63 ||
V_11 -> V_38 == V_64 ||
V_11 -> V_38 == V_65 ||
V_11 -> V_38 == V_54 ) ) {
V_138 = F_43 ( & V_7 -> V_13 ,
& V_140 ) ;
}
}
return V_138 ;
}
static void F_44 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = F_8 ( V_7 ) ;
if ( V_11 -> V_38 != V_39 ) {
F_45 ( & V_7 -> V_13 , & V_139 ) ;
if ( V_11 -> V_38 == V_51 ||
V_11 -> V_38 == V_52 ||
V_11 -> V_38 == V_53 ||
V_11 -> V_38 == V_63 ||
V_11 -> V_38 == V_64 ||
V_11 -> V_38 == V_65 ||
V_11 -> V_38 == V_54 ) {
F_45 ( & V_7 -> V_13 , & V_140 ) ;
}
}
}
static int F_46 ( struct V_106 * V_23 ,
const struct V_141 * V_142 )
{
struct V_143 * V_144 =
(struct V_143 * ) V_142 -> V_145 ;
if ( V_144 && V_144 -> V_146 ) {
int V_147 = V_144 -> V_146 ( V_23 ) ;
if ( V_147 != 0 )
return V_147 ;
}
F_47 ( V_23 , ( void * ) V_142 -> V_145 ) ;
return 0 ;
}
static int F_48 ( struct V_6 * V_7 )
{
struct V_10 * V_11 ;
struct V_143 * V_144 = F_49 ( V_7 -> V_23 ) ;
V_11 = F_50 ( sizeof( struct V_10 ) , V_80 ) ;
if ( ! V_11 ) {
F_19 ( & V_7 -> V_13 , L_27 , V_18 ,
sizeof( struct V_10 ) ) ;
return - V_81 ;
}
F_51 ( & V_11 -> V_148 ) ;
F_52 ( & V_11 -> V_91 ) ;
F_53 ( & V_11 -> V_149 ) ;
V_11 -> V_33 = V_76 ;
V_11 -> V_150 = false ;
if ( V_144 && V_144 -> V_151 )
V_144 -> V_151 ( V_11 ) ;
F_54 ( V_7 , V_11 ) ;
F_32 ( V_7 ) ;
F_34 ( V_7 ) ;
if ( F_20 ( V_7 ) < 0 )
V_11 -> V_75 = 16 ;
F_18 ( V_7 ) ;
F_42 ( V_7 ) ;
return 0 ;
}
static void F_55 ( struct V_10 * V_11 )
{
V_11 -> V_33 |= V_35 ;
V_11 -> V_36 = 77 ;
V_11 -> V_152 = 38400 ;
}
static void F_56 ( struct V_10 * V_11 )
{
V_11 -> V_33 |= V_35 ;
V_11 -> V_36 = 240 ;
V_11 -> V_152 = 38400 ;
V_11 -> V_153 = 1 ;
}
static int F_57 ( struct V_106 * V_23 )
{
struct V_72 * V_73 = V_23 -> V_13 ;
int V_75 = V_154 ;
if ( V_75 == 0 )
V_75 = 1 ;
if ( V_75 > 99 )
V_75 = 99 ;
F_9 ( & V_73 -> V_13 , L_28 , V_18 , V_75 ) ;
F_33 ( & V_73 -> V_13 , L_29 , V_75 ) ;
F_10 ( V_73 , F_11 ( V_73 , 0 ) ,
V_77 ,
V_78 ,
V_75 , 0 , NULL , 0 , V_27 ) ;
return 0 ;
}
static int F_58 ( struct V_106 * V_23 )
{
struct V_72 * V_73 = V_23 -> V_13 ;
struct V_120 * V_26 = V_23 -> V_26 ;
if ( V_26 == V_73 -> V_110 -> V_26 [ 0 ] ) {
F_33 ( & V_73 -> V_13 ,
L_30 ) ;
return - V_155 ;
}
return 0 ;
}
static int F_59 ( struct V_106 * V_23 )
{
struct V_72 * V_73 = V_23 -> V_13 ;
if ( ( V_73 -> V_156 && ! strcmp ( V_73 -> V_156 , L_31 ) ) ||
( V_73 -> V_157 && ! strcmp ( V_73 -> V_157 , L_32 ) ) )
return F_58 ( V_23 ) ;
return 0 ;
}
static int F_60 ( struct V_106 * V_23 )
{
struct V_72 * V_73 = V_23 -> V_13 ;
struct V_120 * V_26 = V_23 -> V_26 ;
if ( V_26 == V_73 -> V_110 -> V_26 [ 2 ] )
return 0 ;
F_33 ( & V_73 -> V_13 , L_30 ) ;
return - V_155 ;
}
static int F_61 ( struct V_106 * V_23 )
{
struct V_158 * V_159 = V_23 -> V_13 -> V_160 [ 1 ] ;
struct V_121 * V_122 = & V_159 -> V_111 ;
if ( V_159 -> V_161 && V_122 -> V_128 == 0 ) {
V_122 -> V_128 = F_35 ( 0x40 ) ;
F_33 ( & V_23 -> V_13 -> V_13 ,
L_33 ) ;
}
return 0 ;
}
static void F_62 ( struct V_148 * V_162 )
{
struct V_10 * V_11 = F_63 ( V_162 , struct V_10 , V_148 ) ;
F_23 ( V_11 ) ;
}
static int F_64 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = F_8 ( V_7 ) ;
V_11 -> V_150 = true ;
F_65 ( & V_11 -> V_149 ) ;
F_44 ( V_7 ) ;
F_66 ( & V_11 -> V_148 , F_62 ) ;
return 0 ;
}
static int F_67 ( struct V_29 * V_30 , struct V_6 * V_7 )
{
struct V_163 V_164 ;
struct V_72 * V_13 = V_7 -> V_23 -> V_13 ;
struct V_10 * V_11 = F_8 ( V_7 ) ;
int V_103 ;
F_10 ( V_13 , F_11 ( V_13 , 0 ) ,
V_165 , V_166 ,
V_167 ,
V_11 -> V_26 , NULL , 0 , V_27 ) ;
if ( V_30 ) {
memset ( & V_164 , 0 , sizeof( V_164 ) ) ;
F_68 ( V_30 , V_7 , & V_164 ) ;
}
V_103 = F_69 ( V_30 , V_7 ) ;
if ( ! V_103 )
F_70 ( & V_11 -> V_148 ) ;
return V_103 ;
}
static void F_71 ( struct V_6 * V_7 , int V_168 )
{
struct V_10 * V_11 = F_8 ( V_7 ) ;
F_28 ( & V_7 -> V_23 -> V_169 ) ;
if ( ! V_7 -> V_23 -> V_170 ) {
if ( ! V_168 && F_10 ( V_7 -> V_23 -> V_13 ,
F_11 ( V_7 -> V_23 -> V_13 , 0 ) ,
V_171 ,
V_172 ,
0 , V_11 -> V_26 , NULL , 0 ,
V_27 ) < 0 ) {
F_19 ( & V_7 -> V_13 , L_34 ) ;
}
if ( V_168 )
F_72 ( V_7 , V_16 | V_17 ) ;
else
F_73 ( V_7 , V_16 | V_17 ) ;
}
F_30 ( & V_7 -> V_23 -> V_169 ) ;
}
static void F_74 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = F_8 ( V_7 ) ;
F_75 ( V_7 ) ;
F_66 ( & V_11 -> V_148 , F_62 ) ;
}
static int F_76 ( struct V_6 * V_7 ,
void * V_173 , T_5 V_174 )
{
struct V_10 * V_11 ;
int V_133 ;
unsigned long V_33 ;
V_11 = F_8 ( V_7 ) ;
if ( V_11 -> V_38 == V_39 ) {
unsigned char * V_175 = V_173 ;
int V_126 , V_176 , V_177 ;
V_133 = 0 ;
F_77 ( & V_7 -> V_178 , V_33 ) ;
for ( V_126 = 0 ; V_126 < V_174 - 1 ; V_126 += V_11 -> V_129 ) {
V_176 = F_78 ( int , V_174 - V_126 , V_11 -> V_129 ) - 1 ;
V_177 = F_79 ( & V_7 -> V_179 , & V_175 [ V_126 + 1 ] , V_176 ) ;
if ( ! V_177 )
break;
V_11 -> V_180 . V_181 += V_177 ;
V_175 [ V_126 ] = ( V_177 << 2 ) + 1 ;
V_133 += V_177 + 1 ;
}
F_80 ( & V_7 -> V_178 , V_33 ) ;
} else {
V_133 = F_81 ( & V_7 -> V_179 , V_173 , V_174 ,
& V_7 -> V_178 ) ;
V_11 -> V_180 . V_181 += V_133 ;
}
return V_133 ;
}
static int F_82 ( struct V_29 * V_30 ,
struct V_6 * V_7 , struct V_10 * V_11 ,
char * V_182 , int V_176 )
{
int V_126 ;
char V_183 ;
char V_184 ;
char * V_185 ;
if ( V_176 < 2 ) {
F_9 ( & V_7 -> V_13 , L_35 ) ;
return 0 ;
}
V_183 = V_182 [ 0 ] & V_186 ;
if ( V_183 != V_11 -> V_187 ) {
char V_188 = V_183 ^ V_11 -> V_187 ;
if ( V_188 & V_189 )
V_11 -> V_180 . V_190 ++ ;
if ( V_188 & V_191 )
V_11 -> V_180 . V_192 ++ ;
if ( V_188 & V_193 )
V_11 -> V_180 . V_194 ++ ;
if ( V_188 & V_195 )
V_11 -> V_180 . V_196 ++ ;
F_65 ( & V_11 -> V_149 ) ;
V_11 -> V_187 = V_183 ;
}
V_184 = V_197 ;
if ( V_182 [ 1 ] & V_198 ) {
if ( V_182 [ 1 ] & V_199 ) {
V_184 = V_200 ;
V_11 -> V_180 . V_201 ++ ;
F_83 ( V_7 ) ;
} else if ( V_182 [ 1 ] & V_202 ) {
V_184 = V_203 ;
V_11 -> V_180 . V_204 ++ ;
} else if ( V_182 [ 1 ] & V_205 ) {
V_184 = V_206 ;
V_11 -> V_180 . V_207 ++ ;
}
if ( V_182 [ 1 ] & V_208 ) {
V_11 -> V_180 . V_209 ++ ;
F_84 ( V_30 , 0 , V_210 ) ;
}
}
if ( V_182 [ 1 ] & V_211 )
V_11 -> V_104 = 1 ;
else
V_11 -> V_104 = 0 ;
V_176 -= 2 ;
if ( ! V_176 )
return 0 ;
V_11 -> V_180 . V_212 += V_176 ;
V_185 = V_182 + 2 ;
if ( V_7 -> V_7 . V_213 && V_7 -> V_214 ) {
for ( V_126 = 0 ; V_126 < V_176 ; V_126 ++ , V_185 ++ ) {
if ( ! F_85 ( V_7 , * V_185 ) )
F_84 ( V_30 , * V_185 , V_184 ) ;
}
} else {
F_86 ( V_30 , V_185 , V_184 , V_176 ) ;
}
return V_176 ;
}
static void F_87 ( struct V_215 * V_215 )
{
struct V_6 * V_7 = V_215 -> V_216 ;
struct V_29 * V_30 ;
struct V_10 * V_11 = F_8 ( V_7 ) ;
char * V_217 = ( char * ) V_215 -> V_218 ;
int V_126 ;
int V_176 ;
int V_133 = 0 ;
V_30 = F_88 ( & V_7 -> V_7 ) ;
if ( ! V_30 )
return;
for ( V_126 = 0 ; V_126 < V_215 -> V_219 ; V_126 += V_11 -> V_129 ) {
V_176 = F_78 ( int , V_215 -> V_219 - V_126 , V_11 -> V_129 ) ;
V_133 += F_82 ( V_30 , V_7 , V_11 , & V_217 [ V_126 ] , V_176 ) ;
}
if ( V_133 )
F_89 ( V_30 ) ;
F_90 ( V_30 ) ;
}
static void F_91 ( struct V_29 * V_30 , int V_220 )
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
F_19 ( & V_7 -> V_13 , L_36 ,
V_18 , V_220 ) ;
}
F_9 ( & V_7 -> V_13 , L_37 , V_18 ,
V_220 , V_14 ) ;
}
static int F_92 ( struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_221 ;
int V_226 ;
unsigned char V_79 [ 2 ] ;
int V_147 ;
V_226 = F_93 ( V_30 ) ;
if ( V_226 )
goto V_227;
V_147 = F_94 ( V_30 , V_79 ) ;
if ( V_147 == 2 ) {
if ( ! ( V_79 [ 1 ] & V_211 ) )
V_226 = 1 ;
}
V_227:
F_9 ( & V_7 -> V_13 , L_38 , V_18 , V_226 ) ;
return V_226 ;
}
static void F_68 ( struct V_29 * V_30 ,
struct V_6 * V_7 , struct V_163 * V_228 )
{
struct V_72 * V_13 = V_7 -> V_23 -> V_13 ;
struct V_12 * V_229 = & V_7 -> V_13 ;
struct V_10 * V_11 = F_8 ( V_7 ) ;
struct V_163 * V_230 = & V_30 -> V_230 ;
unsigned int V_231 = V_230 -> V_232 ;
T_2 V_14 ;
unsigned int V_233 = V_230 -> V_234 ;
unsigned char V_235 ;
unsigned char V_236 ;
if ( V_11 -> V_152 && ( ( V_230 -> V_232 & V_237 ) != V_238 ) ) {
F_9 ( V_229 , L_39 , V_18 ) ;
F_16 ( V_30 , V_11 -> V_152 ,
V_11 -> V_152 ) ;
}
if ( V_11 -> V_153 ) {
F_9 ( V_229 , L_40 , V_18 ) ;
V_230 -> V_232 |= V_239 ;
}
V_231 = V_230 -> V_232 ;
if ( ! V_228 )
goto V_240;
if ( V_228 -> V_232 == V_230 -> V_232
&& V_228 -> V_241 == V_230 -> V_241
&& V_228 -> V_242 == V_230 -> V_242 )
goto V_243;
if ( ( V_228 -> V_232 & ( V_244 | V_245 | V_246 | V_247 | V_248 ) ) ==
( V_230 -> V_232 & ( V_244 | V_245 | V_246 | V_247 | V_248 ) ) )
goto V_249;
V_240:
V_14 = 0 ;
V_14 |= ( V_231 & V_248 ? V_250 :
V_251 ) ;
if ( V_231 & V_246 ) {
if ( V_231 & V_247 )
V_14 |= V_231 & V_245 ?
V_252 :
V_253 ;
else
V_14 |= V_231 & V_245 ?
V_254 :
V_255 ;
} else {
V_14 |= V_256 ;
}
if ( V_231 & V_244 ) {
switch ( V_231 & V_244 ) {
case V_257 :
V_14 |= 7 ;
F_9 ( V_229 , L_41 ) ;
break;
case V_258 :
V_14 |= 8 ;
F_9 ( V_229 , L_42 ) ;
break;
default:
F_19 ( V_229 , L_43 ) ;
}
}
V_11 -> V_222 = V_14 ;
if ( F_10 ( V_13 , F_11 ( V_13 , 0 ) ,
V_224 ,
V_225 ,
V_14 , V_11 -> V_26 ,
NULL , 0 , V_71 ) < 0 ) {
F_19 ( V_229 , L_44 ,
V_18 ) ;
}
V_249:
if ( ( V_231 & V_237 ) == V_238 ) {
if ( F_10 ( V_13 , F_11 ( V_13 , 0 ) ,
V_171 ,
V_172 ,
0 , V_11 -> V_26 ,
NULL , 0 , V_27 ) < 0 ) {
F_19 ( V_229 , L_45 ,
V_18 ) ;
}
F_73 ( V_7 , V_16 | V_17 ) ;
} else {
F_28 ( & V_11 -> V_91 ) ;
if ( F_17 ( V_30 , V_7 ) )
F_19 ( V_229 , L_46 , V_18 ) ;
F_30 ( & V_11 -> V_91 ) ;
if ( ! V_228 || ( V_228 -> V_232 & V_237 ) == V_238 )
F_72 ( V_7 , V_16 | V_17 ) ;
}
V_243:
if ( V_231 & V_239 ) {
F_9 ( V_229 , L_47 , V_18 ) ;
if ( F_10 ( V_13 ,
F_11 ( V_13 , 0 ) ,
V_171 ,
V_172 ,
0 , ( V_259 | V_11 -> V_26 ) ,
NULL , 0 , V_27 ) < 0 ) {
F_19 ( V_229 , L_48 ) ;
}
} else {
if ( V_233 & V_260 ) {
F_9 ( V_229 , L_49 ,
V_18 , V_233 ) ;
V_236 = V_230 -> V_261 [ V_262 ] ;
V_235 = V_230 -> V_261 [ V_263 ] ;
V_14 = ( V_235 << 8 ) | ( V_236 ) ;
if ( F_10 ( V_13 ,
F_11 ( V_13 , 0 ) ,
V_171 ,
V_172 ,
V_14 , ( V_264
| V_11 -> V_26 ) ,
NULL , 0 , V_27 ) < 0 ) {
F_19 ( & V_7 -> V_13 , L_50
L_51 ) ;
}
} else {
F_9 ( V_229 , L_52 , V_18 ) ;
if ( F_10 ( V_13 ,
F_11 ( V_13 , 0 ) ,
V_171 ,
V_172 ,
0 , V_11 -> V_26 ,
NULL , 0 , V_27 ) < 0 ) {
F_19 ( V_229 , L_53 ) ;
}
}
}
}
static int F_94 ( struct V_29 * V_30 ,
unsigned char V_183 [ 2 ] )
{
struct V_6 * V_7 = V_30 -> V_221 ;
struct V_10 * V_11 = F_8 ( V_7 ) ;
unsigned char * V_79 ;
int V_176 ;
int V_147 ;
V_79 = F_21 ( 2 , V_80 ) ;
if ( ! V_79 )
return - V_81 ;
switch ( V_11 -> V_38 ) {
case V_39 :
V_176 = 1 ;
break;
case V_50 :
case V_51 :
case V_52 :
case V_53 :
case V_63 :
case V_64 :
case V_65 :
case V_54 :
V_176 = 2 ;
break;
default:
V_147 = - V_87 ;
goto V_227;
}
V_147 = F_10 ( V_7 -> V_23 -> V_13 ,
F_22 ( V_7 -> V_23 -> V_13 , 0 ) ,
V_265 ,
V_266 ,
0 , V_11 -> V_26 ,
V_79 , V_176 , V_27 ) ;
if ( V_147 < 0 ) {
F_19 ( & V_7 -> V_13 , L_54 , V_147 ) ;
V_147 = F_12 ( V_147 ) ;
goto V_227;
}
V_183 [ 0 ] = V_79 [ 0 ] ;
if ( V_147 > 1 )
V_183 [ 1 ] = V_79 [ 1 ] ;
else
V_183 [ 1 ] = 0 ;
F_9 ( & V_7 -> V_13 , L_55 , V_18 , V_183 [ 0 ] ,
V_183 [ 1 ] ) ;
V_227:
F_23 ( V_79 ) ;
return V_147 ;
}
static int F_95 ( struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_221 ;
struct V_10 * V_11 = F_8 ( V_7 ) ;
unsigned char V_79 [ 2 ] ;
int V_147 ;
V_147 = F_94 ( V_30 , V_79 ) ;
if ( V_147 < 0 )
return V_147 ;
V_147 = ( V_79 [ 0 ] & V_267 ? V_268 : 0 ) |
( V_79 [ 0 ] & V_269 ? V_270 : 0 ) |
( V_79 [ 0 ] & V_271 ? V_272 : 0 ) |
( V_79 [ 0 ] & V_273 ? V_274 : 0 ) |
V_11 -> V_28 ;
return V_147 ;
}
static int F_96 ( struct V_29 * V_30 ,
unsigned int V_8 , unsigned int V_9 )
{
struct V_6 * V_7 = V_30 -> V_221 ;
return F_7 ( V_7 , V_8 , V_9 ) ;
}
static int F_97 ( struct V_29 * V_30 ,
struct V_275 * V_180 )
{
struct V_6 * V_7 = V_30 -> V_221 ;
struct V_10 * V_11 = F_8 ( V_7 ) ;
struct V_276 * V_277 = & V_11 -> V_180 ;
V_180 -> V_190 = V_277 -> V_190 ;
V_180 -> V_192 = V_277 -> V_192 ;
V_180 -> V_194 = V_277 -> V_194 ;
V_180 -> V_196 = V_277 -> V_196 ;
V_180 -> V_181 = V_277 -> V_181 ;
V_180 -> V_212 = V_277 -> V_212 ;
V_180 -> V_207 = V_277 -> V_207 ;
V_180 -> V_204 = V_277 -> V_204 ;
V_180 -> V_209 = V_277 -> V_209 ;
V_180 -> V_201 = V_277 -> V_201 ;
V_180 -> V_278 = V_277 -> V_278 ;
return 0 ;
}
static int F_98 ( struct V_29 * V_30 ,
unsigned int V_279 , unsigned long V_280 )
{
struct V_6 * V_7 = V_30 -> V_221 ;
struct V_10 * V_11 = F_8 ( V_7 ) ;
struct V_276 V_281 ;
struct V_276 V_282 ;
F_9 ( & V_7 -> V_13 , L_56 , V_18 , V_279 ) ;
switch ( V_279 ) {
case V_283 :
return F_24 ( V_7 ,
(struct V_84 T_3 * ) V_280 ) ;
case V_284 :
return F_26 ( V_30 , V_7 ,
(struct V_84 T_3 * ) V_280 ) ;
case V_285 :
V_282 = V_11 -> V_180 ;
while ( ! V_11 -> V_150 ) {
F_99 ( & V_11 -> V_149 ) ;
if ( F_100 ( V_286 ) )
return - V_287 ;
V_281 = V_11 -> V_180 ;
if ( ( ( V_280 & V_288 ) && ( V_281 . V_194 != V_282 . V_194 ) ) ||
( ( V_280 & V_268 ) && ( V_281 . V_192 != V_282 . V_192 ) ) ||
( ( V_280 & V_274 ) && ( V_281 . V_196 != V_282 . V_196 ) ) ||
( ( V_280 & V_270 ) && ( V_281 . V_190 != V_282 . V_190 ) ) ) {
return 0 ;
}
V_282 = V_281 ;
}
return - V_135 ;
break;
case V_289 :
return F_31 ( V_7 , (struct V_84 T_3 * ) V_280 ) ;
break;
default:
break;
}
F_9 ( & V_7 -> V_13 , L_57 ,
V_18 , V_279 ) ;
return - V_290 ;
}
static int T_6 F_101 ( void )
{
if ( V_291 > 0 && V_157 > 0 ) {
int V_126 ;
for ( V_126 = 0 ; V_292 [ V_126 ] . V_293 ; V_126 ++ )
;
V_292 [ V_126 ] . V_294 = V_295 ;
V_292 [ V_126 ] . V_293 = V_291 ;
V_292 [ V_126 ] . V_57 = V_157 ;
}
return F_102 ( V_296 , V_297 , V_292 ) ;
}
static void T_7 F_103 ( void )
{
F_104 ( V_296 ) ;
}
