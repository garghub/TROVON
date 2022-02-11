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
if ( ( ( V_55 == V_58 ) ||
( V_55 == V_59 ) ||
( V_55 == V_60 ) ||
( V_55 == V_61 ) ||
( V_55 == V_62 ) ) &&
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
struct V_120 * V_26 = V_7 -> V_23 -> V_26 ;
struct V_121 * V_122 ;
unsigned V_123 ;
unsigned V_124 ;
V_123 = V_26 -> V_125 -> V_111 . V_126 ;
if ( ! V_123 )
return;
for ( V_124 = 0 ; V_124 < V_123 ; V_124 ++ ) {
V_122 = & V_26 -> V_125 -> V_127 [ V_124 ] . V_111 ;
if ( ! V_122 -> V_128 ) {
V_122 -> V_128 = F_35 ( 0x40 ) ;
F_36 ( & V_7 -> V_13 , L_18 ,
F_37 ( V_122 ) ) ;
}
}
V_11 -> V_129 = F_38 ( V_122 ) ;
}
static T_4 F_39 ( struct V_12 * V_13 ,
struct V_130 * V_131 , char * V_79 )
{
struct V_6 * V_7 = F_40 ( V_13 ) ;
struct V_10 * V_11 = F_8 ( V_7 ) ;
if ( V_11 -> V_33 & V_76 )
return sprintf ( V_79 , L_19 ) ;
else
return sprintf ( V_79 , L_20 , V_11 -> V_75 ) ;
}
static T_4 F_41 ( struct V_12 * V_13 ,
struct V_130 * V_131 ,
const char * V_132 , T_5 V_133 )
{
struct V_6 * V_7 = F_40 ( V_13 ) ;
struct V_10 * V_11 = F_8 ( V_7 ) ;
int V_134 = F_42 ( V_132 , NULL , 10 ) ;
int V_15 ;
V_11 -> V_75 = V_134 ;
V_15 = F_18 ( V_7 ) ;
if ( V_15 < 0 )
return - V_135 ;
return V_133 ;
}
static T_4 F_43 ( struct V_12 * V_13 ,
struct V_130 * V_131 , const char * V_132 , T_5 V_133 )
{
struct V_6 * V_7 = F_40 ( V_13 ) ;
struct V_10 * V_11 = F_8 ( V_7 ) ;
struct V_72 * V_73 = V_7 -> V_23 -> V_13 ;
int V_134 = F_42 ( V_132 , NULL , 10 ) ;
int V_15 ;
F_9 ( & V_7 -> V_13 , L_21 , V_18 , V_134 ) ;
V_15 = F_10 ( V_73 ,
F_11 ( V_73 , 0 ) ,
V_136 ,
V_137 ,
V_134 , V_11 -> V_26 ,
NULL , 0 , V_27 ) ;
if ( V_15 < 0 ) {
F_9 ( & V_7 -> V_13 , L_22 , V_15 ) ;
return - V_135 ;
}
return V_133 ;
}
static int F_44 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = F_8 ( V_7 ) ;
int V_138 = 0 ;
if ( V_11 -> V_38 != V_39 ) {
F_9 ( & V_7 -> V_13 , L_23 , V_66 [ V_11 -> V_38 ] ) ;
V_138 = F_45 ( & V_7 -> V_13 , & V_139 ) ;
if ( ( ! V_138 ) &&
( V_11 -> V_38 == V_51 ||
V_11 -> V_38 == V_52 ||
V_11 -> V_38 == V_53 ||
V_11 -> V_38 == V_63 ||
V_11 -> V_38 == V_64 ||
V_11 -> V_38 == V_65 ||
V_11 -> V_38 == V_54 ) ) {
V_138 = F_45 ( & V_7 -> V_13 ,
& V_140 ) ;
}
}
return V_138 ;
}
static void F_46 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = F_8 ( V_7 ) ;
if ( V_11 -> V_38 != V_39 ) {
F_47 ( & V_7 -> V_13 , & V_139 ) ;
if ( V_11 -> V_38 == V_51 ||
V_11 -> V_38 == V_52 ||
V_11 -> V_38 == V_53 ||
V_11 -> V_38 == V_63 ||
V_11 -> V_38 == V_64 ||
V_11 -> V_38 == V_65 ||
V_11 -> V_38 == V_54 ) {
F_47 ( & V_7 -> V_13 , & V_140 ) ;
}
}
}
static int F_48 ( struct V_106 * V_23 ,
const struct V_141 * V_142 )
{
const struct V_143 * V_144 =
(struct V_143 * ) V_142 -> V_145 ;
if ( V_144 && V_144 -> V_146 ) {
int V_147 = V_144 -> V_146 ( V_23 ) ;
if ( V_147 != 0 )
return V_147 ;
}
F_49 ( V_23 , ( void * ) V_142 -> V_145 ) ;
return 0 ;
}
static int F_50 ( struct V_6 * V_7 )
{
struct V_10 * V_11 ;
const struct V_143 * V_144 = F_51 ( V_7 -> V_23 ) ;
V_11 = F_52 ( sizeof( struct V_10 ) , V_80 ) ;
if ( ! V_11 )
return - V_81 ;
F_53 ( & V_11 -> V_91 ) ;
V_11 -> V_33 = V_76 ;
if ( V_144 && V_144 -> V_148 )
V_144 -> V_148 ( V_11 ) ;
F_54 ( V_7 , V_11 ) ;
F_32 ( V_7 ) ;
F_34 ( V_7 ) ;
if ( F_20 ( V_7 ) < 0 )
V_11 -> V_75 = 16 ;
F_18 ( V_7 ) ;
F_44 ( V_7 ) ;
return 0 ;
}
static void F_55 ( struct V_10 * V_11 )
{
V_11 -> V_33 |= V_35 ;
V_11 -> V_36 = 77 ;
V_11 -> V_149 = 38400 ;
}
static void F_56 ( struct V_10 * V_11 )
{
V_11 -> V_33 |= V_35 ;
V_11 -> V_36 = 240 ;
V_11 -> V_149 = 38400 ;
V_11 -> V_150 = 1 ;
}
static int F_57 ( struct V_106 * V_23 )
{
struct V_72 * V_73 = V_23 -> V_13 ;
int V_75 = V_151 ;
if ( V_75 == 0 )
V_75 = 1 ;
if ( V_75 > 99 )
V_75 = 99 ;
F_9 ( & V_73 -> V_13 , L_24 , V_18 , V_75 ) ;
F_33 ( & V_73 -> V_13 , L_25 , V_75 ) ;
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
L_26 ) ;
return - V_152 ;
}
return 0 ;
}
static int F_59 ( struct V_106 * V_23 )
{
struct V_72 * V_73 = V_23 -> V_13 ;
if ( V_73 -> V_153 && ! strcmp ( V_73 -> V_153 , L_27 ) )
return F_58 ( V_23 ) ;
if ( V_73 -> V_154 &&
( ! strcmp ( V_73 -> V_154 , L_28 ) ||
! strcmp ( V_73 -> V_154 , L_29 ) ) )
return F_58 ( V_23 ) ;
return 0 ;
}
static int F_60 ( struct V_106 * V_23 )
{
struct V_72 * V_73 = V_23 -> V_13 ;
struct V_120 * V_26 = V_23 -> V_26 ;
if ( V_26 == V_73 -> V_110 -> V_26 [ 0 ] ||
V_26 == V_73 -> V_110 -> V_26 [ 1 ] ) {
F_33 ( & V_73 -> V_13 , L_26 ) ;
return - V_152 ;
}
return 0 ;
}
static int F_61 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = F_8 ( V_7 ) ;
F_46 ( V_7 ) ;
F_23 ( V_11 ) ;
return 0 ;
}
static int F_62 ( struct V_29 * V_30 , struct V_6 * V_7 )
{
struct V_72 * V_13 = V_7 -> V_23 -> V_13 ;
struct V_10 * V_11 = F_8 ( V_7 ) ;
F_10 ( V_13 , F_11 ( V_13 , 0 ) ,
V_155 , V_156 ,
V_157 ,
V_11 -> V_26 , NULL , 0 , V_27 ) ;
if ( V_30 )
F_63 ( V_30 , V_7 , NULL ) ;
return F_64 ( V_30 , V_7 ) ;
}
static void F_65 ( struct V_6 * V_7 , int V_158 )
{
struct V_10 * V_11 = F_8 ( V_7 ) ;
if ( ! V_158 ) {
if ( F_10 ( V_7 -> V_23 -> V_13 ,
F_11 ( V_7 -> V_23 -> V_13 , 0 ) ,
V_159 ,
V_160 ,
0 , V_11 -> V_26 , NULL , 0 ,
V_27 ) < 0 ) {
F_19 ( & V_7 -> V_13 , L_30 ) ;
}
}
if ( V_158 )
F_66 ( V_7 , V_16 | V_17 ) ;
else
F_67 ( V_7 , V_16 | V_17 ) ;
}
static int F_68 ( struct V_6 * V_7 ,
void * V_161 , T_5 V_162 )
{
struct V_10 * V_11 ;
int V_133 ;
unsigned long V_33 ;
V_11 = F_8 ( V_7 ) ;
if ( V_11 -> V_38 == V_39 ) {
unsigned char * V_163 = V_161 ;
int V_124 , V_164 , V_165 ;
V_133 = 0 ;
F_69 ( & V_7 -> V_166 , V_33 ) ;
for ( V_124 = 0 ; V_124 < V_162 - 1 ; V_124 += V_11 -> V_129 ) {
V_164 = F_70 ( int , V_162 - V_124 , V_11 -> V_129 ) - 1 ;
V_165 = F_71 ( & V_7 -> V_167 , & V_163 [ V_124 + 1 ] , V_164 ) ;
if ( ! V_165 )
break;
V_7 -> V_168 . V_169 += V_165 ;
V_163 [ V_124 ] = ( V_165 << 2 ) + 1 ;
V_133 += V_165 + 1 ;
}
F_72 ( & V_7 -> V_166 , V_33 ) ;
} else {
V_133 = F_73 ( & V_7 -> V_167 , V_161 , V_162 ,
& V_7 -> V_166 ) ;
V_7 -> V_168 . V_169 += V_133 ;
}
return V_133 ;
}
static int F_74 ( struct V_6 * V_7 ,
struct V_10 * V_11 , char * V_170 , int V_164 )
{
int V_124 ;
char V_171 ;
char V_172 ;
char * V_173 ;
if ( V_164 < 2 ) {
F_9 ( & V_7 -> V_13 , L_31 ) ;
return 0 ;
}
V_171 = V_170 [ 0 ] & V_174 ;
if ( V_171 != V_11 -> V_175 ) {
char V_176 = V_171 ^ V_11 -> V_175 ;
if ( V_176 & V_177 )
V_7 -> V_168 . V_178 ++ ;
if ( V_176 & V_179 )
V_7 -> V_168 . V_180 ++ ;
if ( V_176 & V_181 )
V_7 -> V_168 . V_182 ++ ;
if ( V_176 & V_183 ) {
struct V_29 * V_30 ;
V_7 -> V_168 . V_184 ++ ;
V_30 = F_75 ( & V_7 -> V_7 ) ;
if ( V_30 )
F_76 ( V_7 , V_30 ,
V_171 & V_183 ) ;
F_77 ( V_30 ) ;
}
F_78 ( & V_7 -> V_7 . V_185 ) ;
V_11 -> V_175 = V_171 ;
}
V_172 = V_186 ;
if ( V_170 [ 1 ] & V_187 ) {
if ( V_170 [ 1 ] & V_188 ) {
V_172 = V_189 ;
V_7 -> V_168 . V_190 ++ ;
F_79 ( V_7 ) ;
} else if ( V_170 [ 1 ] & V_191 ) {
V_172 = V_192 ;
V_7 -> V_168 . V_193 ++ ;
} else if ( V_170 [ 1 ] & V_194 ) {
V_172 = V_195 ;
V_7 -> V_168 . V_196 ++ ;
}
if ( V_170 [ 1 ] & V_197 ) {
V_7 -> V_168 . V_198 ++ ;
F_80 ( & V_7 -> V_7 , 0 , V_199 ) ;
}
}
if ( V_170 [ 1 ] & V_200 )
V_11 -> V_104 = 1 ;
else
V_11 -> V_104 = 0 ;
V_164 -= 2 ;
if ( ! V_164 )
return 0 ;
V_7 -> V_168 . V_201 += V_164 ;
V_173 = V_170 + 2 ;
if ( V_7 -> V_7 . V_202 && V_7 -> V_203 ) {
for ( V_124 = 0 ; V_124 < V_164 ; V_124 ++ , V_173 ++ ) {
if ( ! F_81 ( V_7 , * V_173 ) )
F_80 ( & V_7 -> V_7 , * V_173 , V_172 ) ;
}
} else {
F_82 ( & V_7 -> V_7 , V_173 , V_172 , V_164 ) ;
}
return V_164 ;
}
static void F_83 ( struct V_204 * V_204 )
{
struct V_6 * V_7 = V_204 -> V_205 ;
struct V_10 * V_11 = F_8 ( V_7 ) ;
char * V_206 = ( char * ) V_204 -> V_207 ;
int V_124 ;
int V_164 ;
int V_133 = 0 ;
for ( V_124 = 0 ; V_124 < V_204 -> V_208 ; V_124 += V_11 -> V_129 ) {
V_164 = F_70 ( int , V_204 -> V_208 - V_124 , V_11 -> V_129 ) ;
V_133 += F_74 ( V_7 , V_11 , & V_206 [ V_124 ] , V_164 ) ;
}
if ( V_133 )
F_84 ( & V_7 -> V_7 ) ;
}
static void F_85 ( struct V_29 * V_30 , int V_209 )
{
struct V_6 * V_7 = V_30 -> V_210 ;
struct V_10 * V_11 = F_8 ( V_7 ) ;
T_2 V_14 ;
if ( V_209 )
V_14 = V_11 -> V_211 | V_212 ;
else
V_14 = V_11 -> V_211 ;
if ( F_10 ( V_7 -> V_23 -> V_13 ,
F_11 ( V_7 -> V_23 -> V_13 , 0 ) ,
V_213 ,
V_214 ,
V_14 , V_11 -> V_26 ,
NULL , 0 , V_27 ) < 0 ) {
F_19 ( & V_7 -> V_13 , L_32 ,
V_18 , V_209 ) ;
}
F_9 ( & V_7 -> V_13 , L_33 , V_18 ,
V_209 , V_14 ) ;
}
static bool F_86 ( struct V_6 * V_7 )
{
unsigned char V_79 [ 2 ] ;
int V_147 ;
V_147 = F_87 ( V_7 , V_79 ) ;
if ( V_147 == 2 ) {
if ( ! ( V_79 [ 1 ] & V_200 ) )
return false ;
}
return true ;
}
static void F_63 ( struct V_29 * V_30 ,
struct V_6 * V_7 , struct V_215 * V_216 )
{
struct V_72 * V_13 = V_7 -> V_23 -> V_13 ;
struct V_12 * V_217 = & V_7 -> V_13 ;
struct V_10 * V_11 = F_8 ( V_7 ) ;
struct V_215 * V_218 = & V_30 -> V_218 ;
unsigned int V_219 = V_218 -> V_220 ;
T_2 V_14 ;
unsigned int V_221 = V_218 -> V_222 ;
unsigned char V_223 ;
unsigned char V_224 ;
if ( V_11 -> V_149 && ( ( V_218 -> V_220 & V_225 ) != V_226 ) ) {
F_9 ( V_217 , L_34 , V_18 ) ;
F_16 ( V_30 , V_11 -> V_149 ,
V_11 -> V_149 ) ;
}
if ( V_11 -> V_150 ) {
F_9 ( V_217 , L_35 , V_18 ) ;
V_218 -> V_220 |= V_227 ;
}
if ( F_88 ( V_30 ) == V_228 ) {
F_36 ( V_217 , L_36 ) ;
V_218 -> V_220 &= ~ V_229 ;
if ( V_216 )
V_218 -> V_220 |= V_216 -> V_220 & V_229 ;
else
V_218 -> V_220 |= V_230 ;
}
V_219 = V_218 -> V_220 ;
if ( ! V_216 )
goto V_231;
if ( V_216 -> V_220 == V_218 -> V_220
&& V_216 -> V_232 == V_218 -> V_232
&& V_216 -> V_233 == V_218 -> V_233 )
goto V_234;
if ( ( V_216 -> V_220 & ( V_229 | V_235 | V_236 | V_237 | V_238 ) ) ==
( V_218 -> V_220 & ( V_229 | V_235 | V_236 | V_237 | V_238 ) ) )
goto V_239;
V_231:
V_14 = 0 ;
V_14 |= ( V_219 & V_238 ? V_240 :
V_241 ) ;
if ( V_219 & V_236 ) {
if ( V_219 & V_237 )
V_14 |= V_219 & V_235 ?
V_242 :
V_243 ;
else
V_14 |= V_219 & V_235 ?
V_244 :
V_245 ;
} else {
V_14 |= V_246 ;
}
switch ( V_219 & V_229 ) {
case V_247 :
F_9 ( V_217 , L_37 ) ;
break;
case V_248 :
V_14 |= 7 ;
F_9 ( V_217 , L_38 ) ;
break;
default:
case V_230 :
V_14 |= 8 ;
F_9 ( V_217 , L_39 ) ;
break;
}
V_11 -> V_211 = V_14 ;
if ( F_10 ( V_13 , F_11 ( V_13 , 0 ) ,
V_213 ,
V_214 ,
V_14 , V_11 -> V_26 ,
NULL , 0 , V_71 ) < 0 ) {
F_19 ( V_217 , L_40 ,
V_18 ) ;
}
V_239:
if ( ( V_219 & V_225 ) == V_226 ) {
if ( F_10 ( V_13 , F_11 ( V_13 , 0 ) ,
V_159 ,
V_160 ,
0 , V_11 -> V_26 ,
NULL , 0 , V_27 ) < 0 ) {
F_19 ( V_217 , L_41 ,
V_18 ) ;
}
F_67 ( V_7 , V_16 | V_17 ) ;
} else {
F_28 ( & V_11 -> V_91 ) ;
if ( F_17 ( V_30 , V_7 ) )
F_19 ( V_217 , L_42 , V_18 ) ;
F_30 ( & V_11 -> V_91 ) ;
if ( V_216 && ( V_216 -> V_220 & V_225 ) == V_226 )
F_66 ( V_7 , V_16 | V_17 ) ;
}
V_234:
if ( V_219 & V_227 ) {
F_9 ( V_217 , L_43 , V_18 ) ;
if ( F_10 ( V_13 ,
F_11 ( V_13 , 0 ) ,
V_159 ,
V_160 ,
0 , ( V_249 | V_11 -> V_26 ) ,
NULL , 0 , V_27 ) < 0 ) {
F_19 ( V_217 , L_44 ) ;
}
} else {
if ( V_221 & V_250 ) {
F_9 ( V_217 , L_45 ,
V_18 , V_221 ) ;
V_224 = V_218 -> V_251 [ V_252 ] ;
V_223 = V_218 -> V_251 [ V_253 ] ;
V_14 = ( V_223 << 8 ) | ( V_224 ) ;
if ( F_10 ( V_13 ,
F_11 ( V_13 , 0 ) ,
V_159 ,
V_160 ,
V_14 , ( V_254
| V_11 -> V_26 ) ,
NULL , 0 , V_27 ) < 0 ) {
F_19 ( & V_7 -> V_13 , L_46
L_47 ) ;
}
} else {
F_9 ( V_217 , L_48 , V_18 ) ;
if ( F_10 ( V_13 ,
F_11 ( V_13 , 0 ) ,
V_159 ,
V_160 ,
0 , V_11 -> V_26 ,
NULL , 0 , V_27 ) < 0 ) {
F_19 ( V_217 , L_49 ) ;
}
}
}
}
static int F_87 ( struct V_6 * V_7 ,
unsigned char V_171 [ 2 ] )
{
struct V_10 * V_11 = F_8 ( V_7 ) ;
unsigned char * V_79 ;
int V_164 ;
int V_147 ;
V_79 = F_21 ( 2 , V_80 ) ;
if ( ! V_79 )
return - V_81 ;
switch ( V_11 -> V_38 ) {
case V_39 :
V_164 = 1 ;
break;
case V_50 :
case V_51 :
case V_52 :
case V_53 :
case V_63 :
case V_64 :
case V_65 :
case V_54 :
V_164 = 2 ;
break;
default:
V_147 = - V_87 ;
goto V_255;
}
V_147 = F_10 ( V_7 -> V_23 -> V_13 ,
F_22 ( V_7 -> V_23 -> V_13 , 0 ) ,
V_256 ,
V_257 ,
0 , V_11 -> V_26 ,
V_79 , V_164 , V_27 ) ;
if ( V_147 < 0 ) {
F_19 ( & V_7 -> V_13 , L_50 , V_147 ) ;
V_147 = F_12 ( V_147 ) ;
goto V_255;
}
V_171 [ 0 ] = V_79 [ 0 ] ;
if ( V_147 > 1 )
V_171 [ 1 ] = V_79 [ 1 ] ;
else
V_171 [ 1 ] = 0 ;
F_9 ( & V_7 -> V_13 , L_51 , V_18 , V_171 [ 0 ] ,
V_171 [ 1 ] ) ;
V_255:
F_23 ( V_79 ) ;
return V_147 ;
}
static int F_89 ( struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_210 ;
struct V_10 * V_11 = F_8 ( V_7 ) ;
unsigned char V_79 [ 2 ] ;
int V_147 ;
V_147 = F_87 ( V_7 , V_79 ) ;
if ( V_147 < 0 )
return V_147 ;
V_147 = ( V_79 [ 0 ] & V_258 ? V_259 : 0 ) |
( V_79 [ 0 ] & V_260 ? V_261 : 0 ) |
( V_79 [ 0 ] & V_262 ? V_263 : 0 ) |
( V_79 [ 0 ] & V_264 ? V_265 : 0 ) |
V_11 -> V_28 ;
return V_147 ;
}
static int F_90 ( struct V_29 * V_30 ,
unsigned int V_8 , unsigned int V_9 )
{
struct V_6 * V_7 = V_30 -> V_210 ;
return F_7 ( V_7 , V_8 , V_9 ) ;
}
static int F_91 ( struct V_29 * V_30 ,
unsigned int V_266 , unsigned long V_267 )
{
struct V_6 * V_7 = V_30 -> V_210 ;
switch ( V_266 ) {
case V_268 :
return F_24 ( V_7 ,
(struct V_84 T_3 * ) V_267 ) ;
case V_269 :
return F_26 ( V_30 , V_7 ,
(struct V_84 T_3 * ) V_267 ) ;
case V_270 :
return F_31 ( V_7 , (struct V_84 T_3 * ) V_267 ) ;
break;
default:
break;
}
return - V_271 ;
}
