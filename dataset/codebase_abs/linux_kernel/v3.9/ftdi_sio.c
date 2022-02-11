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
V_11 -> V_33 = V_76 ;
if ( V_144 && V_144 -> V_149 )
V_144 -> V_149 ( V_11 ) ;
F_53 ( V_7 , V_11 ) ;
F_32 ( V_7 ) ;
F_34 ( V_7 ) ;
if ( F_20 ( V_7 ) < 0 )
V_11 -> V_75 = 16 ;
F_18 ( V_7 ) ;
F_42 ( V_7 ) ;
return 0 ;
}
static void F_54 ( struct V_10 * V_11 )
{
V_11 -> V_33 |= V_35 ;
V_11 -> V_36 = 77 ;
V_11 -> V_150 = 38400 ;
}
static void F_55 ( struct V_10 * V_11 )
{
V_11 -> V_33 |= V_35 ;
V_11 -> V_36 = 240 ;
V_11 -> V_150 = 38400 ;
V_11 -> V_151 = 1 ;
}
static int F_56 ( struct V_106 * V_23 )
{
struct V_72 * V_73 = V_23 -> V_13 ;
int V_75 = V_152 ;
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
static int F_57 ( struct V_106 * V_23 )
{
struct V_72 * V_73 = V_23 -> V_13 ;
struct V_120 * V_26 = V_23 -> V_26 ;
if ( V_26 == V_73 -> V_110 -> V_26 [ 0 ] ) {
F_33 ( & V_73 -> V_13 ,
L_30 ) ;
return - V_153 ;
}
return 0 ;
}
static int F_58 ( struct V_106 * V_23 )
{
struct V_72 * V_73 = V_23 -> V_13 ;
if ( ( V_73 -> V_154 && ! strcmp ( V_73 -> V_154 , L_31 ) ) ||
( V_73 -> V_155 && ! strcmp ( V_73 -> V_155 , L_32 ) ) )
return F_57 ( V_23 ) ;
return 0 ;
}
static int F_59 ( struct V_106 * V_23 )
{
struct V_72 * V_73 = V_23 -> V_13 ;
struct V_120 * V_26 = V_23 -> V_26 ;
if ( V_26 == V_73 -> V_110 -> V_26 [ 2 ] )
return 0 ;
F_33 ( & V_73 -> V_13 , L_30 ) ;
return - V_153 ;
}
static int F_60 ( struct V_106 * V_23 )
{
struct V_156 * V_157 = V_23 -> V_13 -> V_158 [ 1 ] ;
struct V_121 * V_122 = & V_157 -> V_111 ;
if ( V_157 -> V_159 && V_122 -> V_128 == 0 ) {
V_122 -> V_128 = F_35 ( 0x40 ) ;
F_33 ( & V_23 -> V_13 -> V_13 ,
L_33 ) ;
}
return 0 ;
}
static void F_61 ( struct V_148 * V_160 )
{
struct V_10 * V_11 = F_62 ( V_160 , struct V_10 , V_148 ) ;
F_23 ( V_11 ) ;
}
static int F_63 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = F_8 ( V_7 ) ;
F_64 ( & V_7 -> V_161 ) ;
F_44 ( V_7 ) ;
F_65 ( & V_11 -> V_148 , F_61 ) ;
return 0 ;
}
static int F_66 ( struct V_29 * V_30 , struct V_6 * V_7 )
{
struct V_162 V_163 ;
struct V_72 * V_13 = V_7 -> V_23 -> V_13 ;
struct V_10 * V_11 = F_8 ( V_7 ) ;
int V_103 ;
F_10 ( V_13 , F_11 ( V_13 , 0 ) ,
V_164 , V_165 ,
V_166 ,
V_11 -> V_26 , NULL , 0 , V_27 ) ;
if ( V_30 ) {
memset ( & V_163 , 0 , sizeof( V_163 ) ) ;
F_67 ( V_30 , V_7 , & V_163 ) ;
}
V_103 = F_68 ( V_30 , V_7 ) ;
if ( ! V_103 )
F_69 ( & V_11 -> V_148 ) ;
return V_103 ;
}
static void F_70 ( struct V_6 * V_7 , int V_167 )
{
struct V_10 * V_11 = F_8 ( V_7 ) ;
if ( ! V_167 ) {
if ( F_10 ( V_7 -> V_23 -> V_13 ,
F_11 ( V_7 -> V_23 -> V_13 , 0 ) ,
V_168 ,
V_169 ,
0 , V_11 -> V_26 , NULL , 0 ,
V_27 ) < 0 ) {
F_19 ( & V_7 -> V_13 , L_34 ) ;
}
}
if ( V_167 )
F_71 ( V_7 , V_16 | V_17 ) ;
else
F_72 ( V_7 , V_16 | V_17 ) ;
}
static void F_73 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = F_8 ( V_7 ) ;
F_74 ( V_7 ) ;
F_65 ( & V_11 -> V_148 , F_61 ) ;
}
static int F_75 ( struct V_6 * V_7 ,
void * V_170 , T_5 V_171 )
{
struct V_10 * V_11 ;
int V_133 ;
unsigned long V_33 ;
V_11 = F_8 ( V_7 ) ;
if ( V_11 -> V_38 == V_39 ) {
unsigned char * V_172 = V_170 ;
int V_126 , V_173 , V_174 ;
V_133 = 0 ;
F_76 ( & V_7 -> V_175 , V_33 ) ;
for ( V_126 = 0 ; V_126 < V_171 - 1 ; V_126 += V_11 -> V_129 ) {
V_173 = F_77 ( int , V_171 - V_126 , V_11 -> V_129 ) - 1 ;
V_174 = F_78 ( & V_7 -> V_176 , & V_172 [ V_126 + 1 ] , V_173 ) ;
if ( ! V_174 )
break;
V_11 -> V_177 . V_178 += V_174 ;
V_172 [ V_126 ] = ( V_174 << 2 ) + 1 ;
V_133 += V_174 + 1 ;
}
F_79 ( & V_7 -> V_175 , V_33 ) ;
} else {
V_133 = F_80 ( & V_7 -> V_176 , V_170 , V_171 ,
& V_7 -> V_175 ) ;
V_11 -> V_177 . V_178 += V_133 ;
}
return V_133 ;
}
static int F_81 ( struct V_6 * V_7 ,
struct V_10 * V_11 , char * V_179 , int V_173 )
{
int V_126 ;
char V_180 ;
char V_181 ;
char * V_182 ;
if ( V_173 < 2 ) {
F_9 ( & V_7 -> V_13 , L_35 ) ;
return 0 ;
}
V_180 = V_179 [ 0 ] & V_183 ;
if ( V_180 != V_11 -> V_184 ) {
char V_185 = V_180 ^ V_11 -> V_184 ;
if ( V_185 & V_186 )
V_11 -> V_177 . V_187 ++ ;
if ( V_185 & V_188 )
V_11 -> V_177 . V_189 ++ ;
if ( V_185 & V_190 )
V_11 -> V_177 . V_191 ++ ;
if ( V_185 & V_192 )
V_11 -> V_177 . V_193 ++ ;
F_64 ( & V_7 -> V_161 ) ;
V_11 -> V_184 = V_180 ;
}
V_181 = V_194 ;
if ( V_179 [ 1 ] & V_195 ) {
if ( V_179 [ 1 ] & V_196 ) {
V_181 = V_197 ;
V_11 -> V_177 . V_198 ++ ;
F_82 ( V_7 ) ;
} else if ( V_179 [ 1 ] & V_199 ) {
V_181 = V_200 ;
V_11 -> V_177 . V_201 ++ ;
} else if ( V_179 [ 1 ] & V_202 ) {
V_181 = V_203 ;
V_11 -> V_177 . V_204 ++ ;
}
if ( V_179 [ 1 ] & V_205 ) {
V_11 -> V_177 . V_206 ++ ;
F_83 ( & V_7 -> V_7 , 0 , V_207 ) ;
}
}
if ( V_179 [ 1 ] & V_208 )
V_11 -> V_104 = 1 ;
else
V_11 -> V_104 = 0 ;
V_173 -= 2 ;
if ( ! V_173 )
return 0 ;
V_11 -> V_177 . V_209 += V_173 ;
V_182 = V_179 + 2 ;
if ( V_7 -> V_7 . V_210 && V_7 -> V_211 ) {
for ( V_126 = 0 ; V_126 < V_173 ; V_126 ++ , V_182 ++ ) {
if ( ! F_84 ( V_7 , * V_182 ) )
F_83 ( & V_7 -> V_7 , * V_182 , V_181 ) ;
}
} else {
F_85 ( & V_7 -> V_7 , V_182 , V_181 , V_173 ) ;
}
return V_173 ;
}
static void F_86 ( struct V_212 * V_212 )
{
struct V_6 * V_7 = V_212 -> V_213 ;
struct V_10 * V_11 = F_8 ( V_7 ) ;
char * V_214 = ( char * ) V_212 -> V_215 ;
int V_126 ;
int V_173 ;
int V_133 = 0 ;
for ( V_126 = 0 ; V_126 < V_212 -> V_216 ; V_126 += V_11 -> V_129 ) {
V_173 = F_77 ( int , V_212 -> V_216 - V_126 , V_11 -> V_129 ) ;
V_133 += F_81 ( V_7 , V_11 , & V_214 [ V_126 ] , V_173 ) ;
}
if ( V_133 )
F_87 ( & V_7 -> V_7 ) ;
}
static void F_88 ( struct V_29 * V_30 , int V_217 )
{
struct V_6 * V_7 = V_30 -> V_218 ;
struct V_10 * V_11 = F_8 ( V_7 ) ;
T_2 V_14 ;
if ( V_217 )
V_14 = V_11 -> V_219 | V_220 ;
else
V_14 = V_11 -> V_219 ;
if ( F_10 ( V_7 -> V_23 -> V_13 ,
F_11 ( V_7 -> V_23 -> V_13 , 0 ) ,
V_221 ,
V_222 ,
V_14 , V_11 -> V_26 ,
NULL , 0 , V_27 ) < 0 ) {
F_19 ( & V_7 -> V_13 , L_36 ,
V_18 , V_217 ) ;
}
F_9 ( & V_7 -> V_13 , L_37 , V_18 ,
V_217 , V_14 ) ;
}
static int F_89 ( struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_218 ;
int V_223 ;
unsigned char V_79 [ 2 ] ;
int V_147 ;
V_223 = F_90 ( V_30 ) ;
if ( V_223 )
goto V_224;
V_147 = F_91 ( V_30 , V_79 ) ;
if ( V_147 == 2 ) {
if ( ! ( V_79 [ 1 ] & V_208 ) )
V_223 = 1 ;
}
V_224:
F_9 ( & V_7 -> V_13 , L_38 , V_18 , V_223 ) ;
return V_223 ;
}
static void F_67 ( struct V_29 * V_30 ,
struct V_6 * V_7 , struct V_162 * V_225 )
{
struct V_72 * V_13 = V_7 -> V_23 -> V_13 ;
struct V_12 * V_226 = & V_7 -> V_13 ;
struct V_10 * V_11 = F_8 ( V_7 ) ;
struct V_162 * V_227 = & V_30 -> V_227 ;
unsigned int V_228 = V_227 -> V_229 ;
T_2 V_14 ;
unsigned int V_230 = V_227 -> V_231 ;
unsigned char V_232 ;
unsigned char V_233 ;
if ( V_11 -> V_150 && ( ( V_227 -> V_229 & V_234 ) != V_235 ) ) {
F_9 ( V_226 , L_39 , V_18 ) ;
F_16 ( V_30 , V_11 -> V_150 ,
V_11 -> V_150 ) ;
}
if ( V_11 -> V_151 ) {
F_9 ( V_226 , L_40 , V_18 ) ;
V_227 -> V_229 |= V_236 ;
}
V_228 = V_227 -> V_229 ;
if ( ! V_225 )
goto V_237;
if ( V_225 -> V_229 == V_227 -> V_229
&& V_225 -> V_238 == V_227 -> V_238
&& V_225 -> V_239 == V_227 -> V_239 )
goto V_240;
if ( ( V_225 -> V_229 & ( V_241 | V_242 | V_243 | V_244 | V_245 ) ) ==
( V_227 -> V_229 & ( V_241 | V_242 | V_243 | V_244 | V_245 ) ) )
goto V_246;
V_237:
V_14 = 0 ;
V_14 |= ( V_228 & V_245 ? V_247 :
V_248 ) ;
if ( V_228 & V_243 ) {
if ( V_228 & V_244 )
V_14 |= V_228 & V_242 ?
V_249 :
V_250 ;
else
V_14 |= V_228 & V_242 ?
V_251 :
V_252 ;
} else {
V_14 |= V_253 ;
}
if ( V_228 & V_241 ) {
switch ( V_228 & V_241 ) {
case V_254 :
V_14 |= 7 ;
F_9 ( V_226 , L_41 ) ;
break;
case V_255 :
V_14 |= 8 ;
F_9 ( V_226 , L_42 ) ;
break;
default:
F_19 ( V_226 , L_43 ) ;
}
}
V_11 -> V_219 = V_14 ;
if ( F_10 ( V_13 , F_11 ( V_13 , 0 ) ,
V_221 ,
V_222 ,
V_14 , V_11 -> V_26 ,
NULL , 0 , V_71 ) < 0 ) {
F_19 ( V_226 , L_44 ,
V_18 ) ;
}
V_246:
if ( ( V_228 & V_234 ) == V_235 ) {
if ( F_10 ( V_13 , F_11 ( V_13 , 0 ) ,
V_168 ,
V_169 ,
0 , V_11 -> V_26 ,
NULL , 0 , V_27 ) < 0 ) {
F_19 ( V_226 , L_45 ,
V_18 ) ;
}
F_72 ( V_7 , V_16 | V_17 ) ;
} else {
F_28 ( & V_11 -> V_91 ) ;
if ( F_17 ( V_30 , V_7 ) )
F_19 ( V_226 , L_46 , V_18 ) ;
F_30 ( & V_11 -> V_91 ) ;
if ( ! V_225 || ( V_225 -> V_229 & V_234 ) == V_235 )
F_71 ( V_7 , V_16 | V_17 ) ;
}
V_240:
if ( V_228 & V_236 ) {
F_9 ( V_226 , L_47 , V_18 ) ;
if ( F_10 ( V_13 ,
F_11 ( V_13 , 0 ) ,
V_168 ,
V_169 ,
0 , ( V_256 | V_11 -> V_26 ) ,
NULL , 0 , V_27 ) < 0 ) {
F_19 ( V_226 , L_48 ) ;
}
} else {
if ( V_230 & V_257 ) {
F_9 ( V_226 , L_49 ,
V_18 , V_230 ) ;
V_233 = V_227 -> V_258 [ V_259 ] ;
V_232 = V_227 -> V_258 [ V_260 ] ;
V_14 = ( V_232 << 8 ) | ( V_233 ) ;
if ( F_10 ( V_13 ,
F_11 ( V_13 , 0 ) ,
V_168 ,
V_169 ,
V_14 , ( V_261
| V_11 -> V_26 ) ,
NULL , 0 , V_27 ) < 0 ) {
F_19 ( & V_7 -> V_13 , L_50
L_51 ) ;
}
} else {
F_9 ( V_226 , L_52 , V_18 ) ;
if ( F_10 ( V_13 ,
F_11 ( V_13 , 0 ) ,
V_168 ,
V_169 ,
0 , V_11 -> V_26 ,
NULL , 0 , V_27 ) < 0 ) {
F_19 ( V_226 , L_53 ) ;
}
}
}
}
static int F_91 ( struct V_29 * V_30 ,
unsigned char V_180 [ 2 ] )
{
struct V_6 * V_7 = V_30 -> V_218 ;
struct V_10 * V_11 = F_8 ( V_7 ) ;
unsigned char * V_79 ;
int V_173 ;
int V_147 ;
V_79 = F_21 ( 2 , V_80 ) ;
if ( ! V_79 )
return - V_81 ;
switch ( V_11 -> V_38 ) {
case V_39 :
V_173 = 1 ;
break;
case V_50 :
case V_51 :
case V_52 :
case V_53 :
case V_63 :
case V_64 :
case V_65 :
case V_54 :
V_173 = 2 ;
break;
default:
V_147 = - V_87 ;
goto V_224;
}
V_147 = F_10 ( V_7 -> V_23 -> V_13 ,
F_22 ( V_7 -> V_23 -> V_13 , 0 ) ,
V_262 ,
V_263 ,
0 , V_11 -> V_26 ,
V_79 , V_173 , V_27 ) ;
if ( V_147 < 0 ) {
F_19 ( & V_7 -> V_13 , L_54 , V_147 ) ;
V_147 = F_12 ( V_147 ) ;
goto V_224;
}
V_180 [ 0 ] = V_79 [ 0 ] ;
if ( V_147 > 1 )
V_180 [ 1 ] = V_79 [ 1 ] ;
else
V_180 [ 1 ] = 0 ;
F_9 ( & V_7 -> V_13 , L_55 , V_18 , V_180 [ 0 ] ,
V_180 [ 1 ] ) ;
V_224:
F_23 ( V_79 ) ;
return V_147 ;
}
static int F_92 ( struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_218 ;
struct V_10 * V_11 = F_8 ( V_7 ) ;
unsigned char V_79 [ 2 ] ;
int V_147 ;
V_147 = F_91 ( V_30 , V_79 ) ;
if ( V_147 < 0 )
return V_147 ;
V_147 = ( V_79 [ 0 ] & V_264 ? V_265 : 0 ) |
( V_79 [ 0 ] & V_266 ? V_267 : 0 ) |
( V_79 [ 0 ] & V_268 ? V_269 : 0 ) |
( V_79 [ 0 ] & V_270 ? V_271 : 0 ) |
V_11 -> V_28 ;
return V_147 ;
}
static int F_93 ( struct V_29 * V_30 ,
unsigned int V_8 , unsigned int V_9 )
{
struct V_6 * V_7 = V_30 -> V_218 ;
return F_7 ( V_7 , V_8 , V_9 ) ;
}
static int F_94 ( struct V_29 * V_30 ,
struct V_272 * V_177 )
{
struct V_6 * V_7 = V_30 -> V_218 ;
struct V_10 * V_11 = F_8 ( V_7 ) ;
struct V_273 * V_274 = & V_11 -> V_177 ;
V_177 -> V_187 = V_274 -> V_187 ;
V_177 -> V_189 = V_274 -> V_189 ;
V_177 -> V_191 = V_274 -> V_191 ;
V_177 -> V_193 = V_274 -> V_193 ;
V_177 -> V_178 = V_274 -> V_178 ;
V_177 -> V_209 = V_274 -> V_209 ;
V_177 -> V_204 = V_274 -> V_204 ;
V_177 -> V_201 = V_274 -> V_201 ;
V_177 -> V_206 = V_274 -> V_206 ;
V_177 -> V_198 = V_274 -> V_198 ;
V_177 -> V_275 = V_274 -> V_275 ;
return 0 ;
}
static int F_95 ( struct V_29 * V_30 ,
unsigned int V_276 , unsigned long V_277 )
{
struct V_6 * V_7 = V_30 -> V_218 ;
struct V_10 * V_11 = F_8 ( V_7 ) ;
struct V_273 V_278 ;
struct V_273 V_279 ;
F_9 ( & V_7 -> V_13 , L_56 , V_18 , V_276 ) ;
switch ( V_276 ) {
case V_280 :
return F_24 ( V_7 ,
(struct V_84 T_3 * ) V_277 ) ;
case V_281 :
return F_26 ( V_30 , V_7 ,
(struct V_84 T_3 * ) V_277 ) ;
case V_282 :
V_279 = V_11 -> V_177 ;
for (; ; ) {
F_96 ( & V_7 -> V_161 ) ;
if ( F_97 ( V_283 ) )
return - V_284 ;
if ( V_7 -> V_23 -> V_285 )
return - V_135 ;
V_278 = V_11 -> V_177 ;
if ( ( ( V_277 & V_286 ) && ( V_278 . V_191 != V_279 . V_191 ) ) ||
( ( V_277 & V_265 ) && ( V_278 . V_189 != V_279 . V_189 ) ) ||
( ( V_277 & V_271 ) && ( V_278 . V_193 != V_279 . V_193 ) ) ||
( ( V_277 & V_267 ) && ( V_278 . V_187 != V_279 . V_187 ) ) ) {
return 0 ;
}
V_279 = V_278 ;
}
case V_287 :
return F_31 ( V_7 , (struct V_84 T_3 * ) V_277 ) ;
break;
default:
break;
}
F_9 ( & V_7 -> V_13 , L_57 ,
V_18 , V_276 ) ;
return - V_288 ;
}
static int T_6 F_98 ( void )
{
if ( V_289 > 0 && V_155 > 0 ) {
int V_126 ;
for ( V_126 = 0 ; V_290 [ V_126 ] . V_291 ; V_126 ++ )
;
V_290 [ V_126 ] . V_292 = V_293 ;
V_290 [ V_126 ] . V_291 = V_289 ;
V_290 [ V_126 ] . V_57 = V_155 ;
}
return F_99 ( V_294 , V_295 , V_290 ) ;
}
static void T_7 F_100 ( void )
{
F_101 ( V_294 ) ;
}
