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
if ( V_11 -> V_38 == V_39 || V_11 -> V_38 == V_50 )
return - V_76 ;
if ( V_11 -> V_33 & V_77 )
V_74 = 1 ;
F_9 ( & V_7 -> V_13 , L_12 , V_18 , V_74 ) ;
V_15 = F_10 ( V_73 ,
F_11 ( V_73 , 0 ) ,
V_78 ,
V_79 ,
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
unsigned char * V_80 ;
int V_15 ;
V_80 = F_21 ( 1 , V_81 ) ;
if ( ! V_80 )
return - V_82 ;
V_15 = F_10 ( V_73 ,
F_22 ( V_73 , 0 ) ,
V_83 ,
V_84 ,
0 , V_11 -> V_26 ,
V_80 , 1 , V_27 ) ;
if ( V_15 < 1 ) {
if ( V_15 >= 0 )
V_15 = - V_85 ;
} else {
V_15 = V_80 [ 0 ] ;
}
F_23 ( V_80 ) ;
return V_15 ;
}
static int F_24 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = F_8 ( V_7 ) ;
int V_15 ;
if ( V_11 -> V_38 == V_39 || V_11 -> V_38 == V_50 )
return - V_76 ;
V_15 = F_20 ( V_7 ) ;
if ( V_15 < 0 ) {
F_19 ( & V_7 -> V_13 , L_14 , V_15 ) ;
return V_15 ;
}
V_11 -> V_75 = V_15 ;
return 0 ;
}
static int F_25 ( struct V_6 * V_7 ,
struct V_86 T_3 * V_87 )
{
struct V_10 * V_11 = F_8 ( V_7 ) ;
struct V_86 V_88 ;
memset ( & V_88 , 0 , sizeof( V_88 ) ) ;
V_88 . V_33 = V_11 -> V_33 ;
V_88 . V_37 = V_11 -> V_37 ;
V_88 . V_36 = V_11 -> V_36 ;
if ( F_26 ( V_87 , & V_88 , sizeof( * V_87 ) ) )
return - V_89 ;
return 0 ;
}
static int F_27 ( struct V_29 * V_30 ,
struct V_6 * V_7 , struct V_86 T_3 * V_90 )
{
struct V_10 * V_11 = F_8 ( V_7 ) ;
struct V_86 V_91 ;
struct V_10 V_92 ;
if ( F_28 ( & V_91 , V_90 , sizeof( V_91 ) ) )
return - V_89 ;
F_29 ( & V_11 -> V_93 ) ;
V_92 = * V_11 ;
if ( ! F_30 ( V_94 ) ) {
if ( ( ( V_91 . V_33 & ~ V_95 ) !=
( V_11 -> V_33 & ~ V_95 ) ) ) {
F_31 ( & V_11 -> V_93 ) ;
return - V_96 ;
}
V_11 -> V_33 = ( ( V_11 -> V_33 & ~ V_95 ) |
( V_91 . V_33 & V_95 ) ) ;
V_11 -> V_36 = V_91 . V_36 ;
goto V_97;
}
if ( V_91 . V_37 != V_11 -> V_37 ) {
F_31 ( & V_11 -> V_93 ) ;
return - V_76 ;
}
V_11 -> V_33 = ( ( V_11 -> V_33 & ~ V_98 ) |
( V_91 . V_33 & V_98 ) ) ;
V_11 -> V_36 = V_91 . V_36 ;
V_97:
F_18 ( V_7 ) ;
if ( ( V_92 . V_33 & V_34 ) !=
( V_11 -> V_33 & V_34 ) ) {
if ( ( V_11 -> V_33 & V_34 ) == V_99 )
V_30 -> V_100 = 57600 ;
else if ( ( V_11 -> V_33 & V_34 ) == V_101 )
V_30 -> V_100 = 115200 ;
else if ( ( V_11 -> V_33 & V_34 ) == V_102 )
V_30 -> V_100 = 230400 ;
else if ( ( V_11 -> V_33 & V_34 ) == V_103 )
V_30 -> V_100 = 460800 ;
else
V_30 -> V_100 = 0 ;
}
if ( ( ( V_92 . V_33 & V_34 ) !=
( V_11 -> V_33 & V_34 ) ) ||
( ( ( V_11 -> V_33 & V_34 ) == V_35 ) &&
( V_92 . V_36 != V_11 -> V_36 ) ) ) {
F_17 ( V_30 , V_7 ) ;
F_31 ( & V_11 -> V_93 ) ;
}
else
F_31 ( & V_11 -> V_93 ) ;
return 0 ;
}
static int F_32 ( struct V_6 * V_7 ,
unsigned int T_3 * V_87 )
{
struct V_10 * V_11 = F_8 ( V_7 ) ;
unsigned int V_104 = 0 ;
if ( V_11 -> V_105 )
V_104 = V_106 ;
if ( F_26 ( V_87 , & V_104 , sizeof( unsigned int ) ) )
return - V_89 ;
return 0 ;
}
static void F_33 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = F_8 ( V_7 ) ;
struct V_107 * V_23 = V_7 -> V_23 ;
struct V_72 * V_73 = V_23 -> V_13 ;
unsigned V_108 ;
unsigned V_109 ;
V_11 -> V_37 = 48000000 / 2 ;
V_108 = F_15 ( V_73 -> V_56 . V_110 ) ;
V_109 = V_73 -> V_111 -> V_112 . V_113 ;
F_9 ( & V_7 -> V_13 , L_15 , V_18 ,
V_108 , V_109 ) ;
if ( V_109 > 1 ) {
int V_114 ;
if ( V_108 == 0x0800 ) {
V_11 -> V_38 = V_64 ;
V_11 -> V_37 = 120000000 / 2 ;
} else if ( V_108 == 0x0700 ) {
V_11 -> V_38 = V_63 ;
V_11 -> V_37 = 120000000 / 2 ;
} else
V_11 -> V_38 = V_52 ;
V_114 = V_23 -> V_26 -> V_115 -> V_112 . V_116 ;
if ( V_114 == 0 ) {
V_11 -> V_26 = V_117 ;
} else if ( V_114 == 1 ) {
V_11 -> V_26 = V_118 ;
} else if ( V_114 == 2 ) {
V_11 -> V_26 = V_119 ;
} else if ( V_114 == 3 ) {
V_11 -> V_26 = V_120 ;
}
if ( V_108 < 0x500 ) {
F_9 ( & V_7 -> V_13 ,
L_16 ,
V_18 ) ;
}
} else if ( V_108 < 0x200 ) {
V_11 -> V_38 = V_39 ;
V_11 -> V_37 = 12000000 / 16 ;
} else if ( V_108 < 0x400 ) {
V_11 -> V_38 = V_50 ;
if ( V_73 -> V_56 . V_121 == 0 &&
F_20 ( V_7 ) >= 0 ) {
F_9 ( & V_7 -> V_13 ,
L_17 ,
V_18 ) ;
V_11 -> V_38 = V_51 ;
}
} else if ( V_108 < 0x600 ) {
V_11 -> V_38 = V_51 ;
} else if ( V_108 < 0x900 ) {
V_11 -> V_38 = V_53 ;
} else if ( V_108 < 0x1000 ) {
V_11 -> V_38 = V_65 ;
} else {
V_11 -> V_38 = V_54 ;
}
F_34 ( & V_73 -> V_13 , L_18 , V_66 [ V_11 -> V_38 ] ) ;
}
static void F_35 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = F_8 ( V_7 ) ;
struct V_122 * V_26 = V_7 -> V_23 -> V_26 ;
struct V_123 * V_124 ;
unsigned V_125 ;
unsigned V_126 ;
V_125 = V_26 -> V_127 -> V_112 . V_128 ;
if ( ! V_125 )
return;
for ( V_126 = 0 ; V_126 < V_125 ; V_126 ++ ) {
V_124 = & V_26 -> V_127 -> V_129 [ V_126 ] . V_112 ;
if ( ! V_124 -> V_130 ) {
V_124 -> V_130 = F_36 ( 0x40 ) ;
F_37 ( & V_7 -> V_13 , L_19 ,
F_38 ( V_124 ) ) ;
}
}
V_11 -> V_131 = F_39 ( V_124 ) ;
}
static T_4 F_40 ( struct V_12 * V_13 ,
struct V_132 * V_133 , char * V_80 )
{
struct V_6 * V_7 = F_41 ( V_13 ) ;
struct V_10 * V_11 = F_8 ( V_7 ) ;
if ( V_11 -> V_33 & V_77 )
return sprintf ( V_80 , L_20 ) ;
else
return sprintf ( V_80 , L_21 , V_11 -> V_75 ) ;
}
static T_4 F_42 ( struct V_12 * V_13 ,
struct V_132 * V_133 ,
const char * V_134 , T_5 V_135 )
{
struct V_6 * V_7 = F_41 ( V_13 ) ;
struct V_10 * V_11 = F_8 ( V_7 ) ;
T_6 V_136 ;
int V_15 ;
if ( F_43 ( V_134 , 10 , & V_136 ) )
return - V_76 ;
V_11 -> V_75 = V_136 ;
V_15 = F_18 ( V_7 ) ;
if ( V_15 < 0 )
return - V_85 ;
return V_135 ;
}
static T_4 F_44 ( struct V_12 * V_13 ,
struct V_132 * V_133 , const char * V_134 , T_5 V_135 )
{
struct V_6 * V_7 = F_41 ( V_13 ) ;
struct V_10 * V_11 = F_8 ( V_7 ) ;
struct V_72 * V_73 = V_7 -> V_23 -> V_13 ;
unsigned int V_136 ;
int V_15 ;
if ( F_45 ( V_134 , 0 , & V_136 ) || V_136 >= 0x200 )
return - V_76 ;
F_9 ( & V_7 -> V_13 , L_22 , V_18 , V_136 ) ;
V_15 = F_10 ( V_73 ,
F_11 ( V_73 , 0 ) ,
V_137 ,
V_138 ,
V_136 , V_11 -> V_26 ,
NULL , 0 , V_27 ) ;
if ( V_15 < 0 ) {
F_9 ( & V_7 -> V_13 , L_23 , V_15 ) ;
return - V_85 ;
}
return V_135 ;
}
static int F_46 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = F_8 ( V_7 ) ;
int V_139 = 0 ;
if ( V_11 -> V_38 != V_39 ) {
F_9 ( & V_7 -> V_13 , L_24 , V_66 [ V_11 -> V_38 ] ) ;
V_139 = F_47 ( & V_7 -> V_13 , & V_140 ) ;
if ( ( ! V_139 ) &&
( V_11 -> V_38 == V_51 ||
V_11 -> V_38 == V_52 ||
V_11 -> V_38 == V_53 ||
V_11 -> V_38 == V_63 ||
V_11 -> V_38 == V_64 ||
V_11 -> V_38 == V_65 ||
V_11 -> V_38 == V_54 ) ) {
V_139 = F_47 ( & V_7 -> V_13 ,
& V_141 ) ;
}
}
return V_139 ;
}
static void F_48 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = F_8 ( V_7 ) ;
if ( V_11 -> V_38 != V_39 ) {
F_49 ( & V_7 -> V_13 , & V_140 ) ;
if ( V_11 -> V_38 == V_51 ||
V_11 -> V_38 == V_52 ||
V_11 -> V_38 == V_53 ||
V_11 -> V_38 == V_63 ||
V_11 -> V_38 == V_64 ||
V_11 -> V_38 == V_65 ||
V_11 -> V_38 == V_54 ) {
F_49 ( & V_7 -> V_13 , & V_141 ) ;
}
}
}
static int F_50 ( struct V_107 * V_23 ,
const struct V_142 * V_143 )
{
const struct V_144 * V_145 =
(struct V_144 * ) V_143 -> V_146 ;
if ( V_145 && V_145 -> V_147 ) {
int V_148 = V_145 -> V_147 ( V_23 ) ;
if ( V_148 != 0 )
return V_148 ;
}
F_51 ( V_23 , ( void * ) V_143 -> V_146 ) ;
return 0 ;
}
static int F_52 ( struct V_6 * V_7 )
{
struct V_10 * V_11 ;
const struct V_144 * V_145 = F_53 ( V_7 -> V_23 ) ;
V_11 = F_54 ( sizeof( struct V_10 ) , V_81 ) ;
if ( ! V_11 )
return - V_82 ;
F_55 ( & V_11 -> V_93 ) ;
if ( V_145 && V_145 -> V_149 )
V_145 -> V_149 ( V_11 ) ;
F_56 ( V_7 , V_11 ) ;
F_33 ( V_7 ) ;
F_35 ( V_7 ) ;
if ( F_24 ( V_7 ) < 0 )
V_11 -> V_75 = 16 ;
F_18 ( V_7 ) ;
F_46 ( V_7 ) ;
return 0 ;
}
static void F_57 ( struct V_10 * V_11 )
{
V_11 -> V_33 |= V_35 ;
V_11 -> V_36 = 77 ;
V_11 -> V_150 = 38400 ;
}
static void F_58 ( struct V_10 * V_11 )
{
V_11 -> V_33 |= V_35 ;
V_11 -> V_36 = 240 ;
V_11 -> V_150 = 38400 ;
V_11 -> V_151 = 1 ;
}
static int F_59 ( struct V_107 * V_23 )
{
struct V_72 * V_73 = V_23 -> V_13 ;
int V_75 = V_152 ;
if ( V_75 == 0 )
V_75 = 1 ;
if ( V_75 > 99 )
V_75 = 99 ;
F_9 ( & V_73 -> V_13 , L_25 , V_18 , V_75 ) ;
F_34 ( & V_73 -> V_13 , L_26 , V_75 ) ;
F_10 ( V_73 , F_11 ( V_73 , 0 ) ,
V_78 ,
V_79 ,
V_75 , 0 , NULL , 0 , V_27 ) ;
return 0 ;
}
static int F_60 ( struct V_107 * V_23 )
{
struct V_72 * V_73 = V_23 -> V_13 ;
struct V_122 * V_26 = V_23 -> V_26 ;
if ( V_26 == V_73 -> V_111 -> V_26 [ 0 ] ) {
F_34 ( & V_73 -> V_13 ,
L_27 ) ;
return - V_153 ;
}
return 0 ;
}
static int F_61 ( struct V_107 * V_23 )
{
struct V_72 * V_73 = V_23 -> V_13 ;
if ( V_73 -> V_154 && ! strcmp ( V_73 -> V_154 , L_28 ) )
return F_60 ( V_23 ) ;
if ( V_73 -> V_155 &&
( ! strcmp ( V_73 -> V_155 , L_29 ) ||
! strcmp ( V_73 -> V_155 , L_30 ) ) )
return F_60 ( V_23 ) ;
return 0 ;
}
static int F_62 ( struct V_107 * V_23 )
{
struct V_72 * V_73 = V_23 -> V_13 ;
struct V_122 * V_26 = V_23 -> V_26 ;
if ( V_26 == V_73 -> V_111 -> V_26 [ 0 ] ||
V_26 == V_73 -> V_111 -> V_26 [ 1 ] ) {
F_34 ( & V_73 -> V_13 , L_27 ) ;
return - V_153 ;
}
return 0 ;
}
static int F_63 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = F_8 ( V_7 ) ;
F_48 ( V_7 ) ;
F_23 ( V_11 ) ;
return 0 ;
}
static int F_64 ( struct V_29 * V_30 , struct V_6 * V_7 )
{
struct V_72 * V_13 = V_7 -> V_23 -> V_13 ;
struct V_10 * V_11 = F_8 ( V_7 ) ;
F_10 ( V_13 , F_11 ( V_13 , 0 ) ,
V_156 , V_157 ,
V_158 ,
V_11 -> V_26 , NULL , 0 , V_27 ) ;
if ( V_30 )
F_65 ( V_30 , V_7 , NULL ) ;
return F_66 ( V_30 , V_7 ) ;
}
static void F_67 ( struct V_6 * V_7 , int V_159 )
{
struct V_10 * V_11 = F_8 ( V_7 ) ;
if ( ! V_159 ) {
if ( F_10 ( V_7 -> V_23 -> V_13 ,
F_11 ( V_7 -> V_23 -> V_13 , 0 ) ,
V_160 ,
V_161 ,
0 , V_11 -> V_26 , NULL , 0 ,
V_27 ) < 0 ) {
F_19 ( & V_7 -> V_13 , L_31 ) ;
}
}
if ( V_159 )
F_68 ( V_7 , V_16 | V_17 ) ;
else
F_69 ( V_7 , V_16 | V_17 ) ;
}
static int F_70 ( struct V_6 * V_7 ,
void * V_162 , T_5 V_163 )
{
struct V_10 * V_11 ;
int V_135 ;
unsigned long V_33 ;
V_11 = F_8 ( V_7 ) ;
if ( V_11 -> V_38 == V_39 ) {
unsigned char * V_164 = V_162 ;
int V_126 , V_165 , V_166 ;
V_135 = 0 ;
F_71 ( & V_7 -> V_167 , V_33 ) ;
for ( V_126 = 0 ; V_126 < V_163 - 1 ; V_126 += V_11 -> V_131 ) {
V_165 = F_72 ( int , V_163 - V_126 , V_11 -> V_131 ) - 1 ;
V_166 = F_73 ( & V_7 -> V_168 , & V_164 [ V_126 + 1 ] , V_165 ) ;
if ( ! V_166 )
break;
V_7 -> V_169 . V_170 += V_166 ;
V_164 [ V_126 ] = ( V_166 << 2 ) + 1 ;
V_135 += V_166 + 1 ;
}
F_74 ( & V_7 -> V_167 , V_33 ) ;
} else {
V_135 = F_75 ( & V_7 -> V_168 , V_162 , V_163 ,
& V_7 -> V_167 ) ;
V_7 -> V_169 . V_170 += V_135 ;
}
return V_135 ;
}
static int F_76 ( struct V_6 * V_7 ,
struct V_10 * V_11 , char * V_171 , int V_165 )
{
int V_126 ;
char V_172 ;
char V_173 ;
char * V_174 ;
if ( V_165 < 2 ) {
F_9 ( & V_7 -> V_13 , L_32 ) ;
return 0 ;
}
V_172 = V_171 [ 0 ] & V_175 ;
if ( V_172 != V_11 -> V_176 ) {
char V_177 = V_172 ^ V_11 -> V_176 ;
if ( V_177 & V_178 )
V_7 -> V_169 . V_179 ++ ;
if ( V_177 & V_180 )
V_7 -> V_169 . V_181 ++ ;
if ( V_177 & V_182 )
V_7 -> V_169 . V_183 ++ ;
if ( V_177 & V_184 ) {
struct V_29 * V_30 ;
V_7 -> V_169 . V_185 ++ ;
V_30 = F_77 ( & V_7 -> V_7 ) ;
if ( V_30 )
F_78 ( V_7 , V_30 ,
V_172 & V_184 ) ;
F_79 ( V_30 ) ;
}
F_80 ( & V_7 -> V_7 . V_186 ) ;
V_11 -> V_176 = V_172 ;
}
if ( V_171 [ 1 ] & V_187 )
V_11 -> V_105 = 1 ;
else
V_11 -> V_105 = 0 ;
V_165 -= 2 ;
if ( ! V_165 )
return 0 ;
V_173 = V_188 ;
if ( V_171 [ 1 ] & V_189 ) {
if ( V_171 [ 1 ] & V_190 ) {
V_173 = V_191 ;
V_7 -> V_169 . V_192 ++ ;
F_81 ( V_7 ) ;
} else if ( V_171 [ 1 ] & V_193 ) {
V_173 = V_194 ;
V_7 -> V_169 . V_195 ++ ;
} else if ( V_171 [ 1 ] & V_196 ) {
V_173 = V_197 ;
V_7 -> V_169 . V_198 ++ ;
}
if ( V_171 [ 1 ] & V_199 ) {
V_7 -> V_169 . V_200 ++ ;
F_82 ( & V_7 -> V_7 , 0 , V_201 ) ;
}
}
V_7 -> V_169 . V_202 += V_165 ;
V_174 = V_171 + 2 ;
if ( V_7 -> V_7 . V_203 && V_7 -> V_204 ) {
for ( V_126 = 0 ; V_126 < V_165 ; V_126 ++ , V_174 ++ ) {
if ( ! F_83 ( V_7 , * V_174 ) )
F_82 ( & V_7 -> V_7 , * V_174 , V_173 ) ;
}
} else {
F_84 ( & V_7 -> V_7 , V_174 , V_173 , V_165 ) ;
}
return V_165 ;
}
static void F_85 ( struct V_205 * V_205 )
{
struct V_6 * V_7 = V_205 -> V_206 ;
struct V_10 * V_11 = F_8 ( V_7 ) ;
char * V_207 = ( char * ) V_205 -> V_208 ;
int V_126 ;
int V_165 ;
int V_135 = 0 ;
for ( V_126 = 0 ; V_126 < V_205 -> V_209 ; V_126 += V_11 -> V_131 ) {
V_165 = F_72 ( int , V_205 -> V_209 - V_126 , V_11 -> V_131 ) ;
V_135 += F_76 ( V_7 , V_11 , & V_207 [ V_126 ] , V_165 ) ;
}
if ( V_135 )
F_86 ( & V_7 -> V_7 ) ;
}
static void F_87 ( struct V_29 * V_30 , int V_210 )
{
struct V_6 * V_7 = V_30 -> V_211 ;
struct V_10 * V_11 = F_8 ( V_7 ) ;
T_2 V_14 ;
if ( V_210 )
V_14 = V_11 -> V_212 | V_213 ;
else
V_14 = V_11 -> V_212 ;
if ( F_10 ( V_7 -> V_23 -> V_13 ,
F_11 ( V_7 -> V_23 -> V_13 , 0 ) ,
V_214 ,
V_215 ,
V_14 , V_11 -> V_26 ,
NULL , 0 , V_27 ) < 0 ) {
F_19 ( & V_7 -> V_13 , L_33 ,
V_18 , V_210 ) ;
}
F_9 ( & V_7 -> V_13 , L_34 , V_18 ,
V_210 , V_14 ) ;
}
static bool F_88 ( struct V_6 * V_7 )
{
unsigned char V_80 [ 2 ] ;
int V_148 ;
V_148 = F_89 ( V_7 , V_80 ) ;
if ( V_148 == 2 ) {
if ( ! ( V_80 [ 1 ] & V_187 ) )
return false ;
}
return true ;
}
static void F_65 ( struct V_29 * V_30 ,
struct V_6 * V_7 , struct V_216 * V_217 )
{
struct V_72 * V_13 = V_7 -> V_23 -> V_13 ;
struct V_12 * V_218 = & V_7 -> V_13 ;
struct V_10 * V_11 = F_8 ( V_7 ) ;
struct V_216 * V_219 = & V_30 -> V_219 ;
unsigned int V_220 = V_219 -> V_221 ;
T_2 V_14 ;
unsigned int V_222 = V_219 -> V_223 ;
unsigned char V_224 ;
unsigned char V_225 ;
if ( V_11 -> V_150 && ( ( V_219 -> V_221 & V_226 ) != V_227 ) ) {
F_9 ( V_218 , L_35 , V_18 ) ;
F_16 ( V_30 , V_11 -> V_150 ,
V_11 -> V_150 ) ;
}
if ( V_11 -> V_151 ) {
F_9 ( V_218 , L_36 , V_18 ) ;
V_219 -> V_221 |= V_228 ;
}
if ( F_90 ( V_30 ) == V_229 ) {
F_37 ( V_218 , L_37 ) ;
V_219 -> V_221 &= ~ V_230 ;
if ( V_217 )
V_219 -> V_221 |= V_217 -> V_221 & V_230 ;
else
V_219 -> V_221 |= V_231 ;
}
V_220 = V_219 -> V_221 ;
if ( ! V_217 )
goto V_232;
if ( V_217 -> V_221 == V_219 -> V_221
&& V_217 -> V_233 == V_219 -> V_233
&& V_217 -> V_234 == V_219 -> V_234 )
goto V_235;
if ( ( V_217 -> V_221 & ( V_230 | V_236 | V_237 | V_238 | V_239 ) ) ==
( V_219 -> V_221 & ( V_230 | V_236 | V_237 | V_238 | V_239 ) ) )
goto V_240;
V_232:
V_14 = 0 ;
V_14 |= ( V_220 & V_239 ? V_241 :
V_242 ) ;
if ( V_220 & V_237 ) {
if ( V_220 & V_238 )
V_14 |= V_220 & V_236 ?
V_243 :
V_244 ;
else
V_14 |= V_220 & V_236 ?
V_245 :
V_246 ;
} else {
V_14 |= V_247 ;
}
switch ( V_220 & V_230 ) {
case V_248 :
F_9 ( V_218 , L_38 ) ;
break;
case V_249 :
V_14 |= 7 ;
F_9 ( V_218 , L_39 ) ;
break;
default:
case V_231 :
V_14 |= 8 ;
F_9 ( V_218 , L_40 ) ;
break;
}
V_11 -> V_212 = V_14 ;
if ( F_10 ( V_13 , F_11 ( V_13 , 0 ) ,
V_214 ,
V_215 ,
V_14 , V_11 -> V_26 ,
NULL , 0 , V_71 ) < 0 ) {
F_19 ( V_218 , L_41 ,
V_18 ) ;
}
V_240:
if ( ( V_220 & V_226 ) == V_227 ) {
if ( F_10 ( V_13 , F_11 ( V_13 , 0 ) ,
V_160 ,
V_161 ,
0 , V_11 -> V_26 ,
NULL , 0 , V_27 ) < 0 ) {
F_19 ( V_218 , L_42 ,
V_18 ) ;
}
F_69 ( V_7 , V_16 | V_17 ) ;
} else {
F_29 ( & V_11 -> V_93 ) ;
if ( F_17 ( V_30 , V_7 ) )
F_19 ( V_218 , L_43 , V_18 ) ;
F_31 ( & V_11 -> V_93 ) ;
if ( V_217 && ( V_217 -> V_221 & V_226 ) == V_227 )
F_68 ( V_7 , V_16 | V_17 ) ;
}
V_235:
if ( V_220 & V_228 ) {
F_9 ( V_218 , L_44 , V_18 ) ;
if ( F_10 ( V_13 ,
F_11 ( V_13 , 0 ) ,
V_160 ,
V_161 ,
0 , ( V_250 | V_11 -> V_26 ) ,
NULL , 0 , V_27 ) < 0 ) {
F_19 ( V_218 , L_45 ) ;
}
} else {
if ( V_222 & V_251 ) {
F_9 ( V_218 , L_46 ,
V_18 , V_222 ) ;
V_225 = V_219 -> V_252 [ V_253 ] ;
V_224 = V_219 -> V_252 [ V_254 ] ;
V_14 = ( V_224 << 8 ) | ( V_225 ) ;
if ( F_10 ( V_13 ,
F_11 ( V_13 , 0 ) ,
V_160 ,
V_161 ,
V_14 , ( V_255
| V_11 -> V_26 ) ,
NULL , 0 , V_27 ) < 0 ) {
F_19 ( & V_7 -> V_13 , L_47
L_48 ) ;
}
} else {
F_9 ( V_218 , L_49 , V_18 ) ;
if ( F_10 ( V_13 ,
F_11 ( V_13 , 0 ) ,
V_160 ,
V_161 ,
0 , V_11 -> V_26 ,
NULL , 0 , V_27 ) < 0 ) {
F_19 ( V_218 , L_50 ) ;
}
}
}
}
static int F_89 ( struct V_6 * V_7 ,
unsigned char V_172 [ 2 ] )
{
struct V_10 * V_11 = F_8 ( V_7 ) ;
unsigned char * V_80 ;
int V_165 ;
int V_148 ;
V_80 = F_21 ( 2 , V_81 ) ;
if ( ! V_80 )
return - V_82 ;
switch ( V_11 -> V_38 ) {
case V_39 :
V_165 = 1 ;
break;
case V_50 :
case V_51 :
case V_52 :
case V_53 :
case V_63 :
case V_64 :
case V_65 :
case V_54 :
V_165 = 2 ;
break;
default:
V_148 = - V_89 ;
goto V_256;
}
V_148 = F_10 ( V_7 -> V_23 -> V_13 ,
F_22 ( V_7 -> V_23 -> V_13 , 0 ) ,
V_257 ,
V_258 ,
0 , V_11 -> V_26 ,
V_80 , V_165 , V_27 ) ;
if ( V_148 < 1 ) {
F_19 ( & V_7 -> V_13 , L_51 , V_148 ) ;
if ( V_148 >= 0 )
V_148 = - V_85 ;
V_148 = F_12 ( V_148 ) ;
goto V_256;
}
V_172 [ 0 ] = V_80 [ 0 ] ;
if ( V_148 > 1 )
V_172 [ 1 ] = V_80 [ 1 ] ;
else
V_172 [ 1 ] = 0 ;
F_9 ( & V_7 -> V_13 , L_52 , V_18 , V_172 [ 0 ] ,
V_172 [ 1 ] ) ;
V_256:
F_23 ( V_80 ) ;
return V_148 ;
}
static int F_91 ( struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_211 ;
struct V_10 * V_11 = F_8 ( V_7 ) ;
unsigned char V_80 [ 2 ] ;
int V_148 ;
V_148 = F_89 ( V_7 , V_80 ) ;
if ( V_148 < 0 )
return V_148 ;
V_148 = ( V_80 [ 0 ] & V_259 ? V_260 : 0 ) |
( V_80 [ 0 ] & V_261 ? V_262 : 0 ) |
( V_80 [ 0 ] & V_263 ? V_264 : 0 ) |
( V_80 [ 0 ] & V_265 ? V_266 : 0 ) |
V_11 -> V_28 ;
return V_148 ;
}
static int F_92 ( struct V_29 * V_30 ,
unsigned int V_8 , unsigned int V_9 )
{
struct V_6 * V_7 = V_30 -> V_211 ;
return F_7 ( V_7 , V_8 , V_9 ) ;
}
static int F_93 ( struct V_29 * V_30 ,
unsigned int V_267 , unsigned long V_268 )
{
struct V_6 * V_7 = V_30 -> V_211 ;
void T_3 * V_269 = ( void T_3 * ) V_268 ;
switch ( V_267 ) {
case V_270 :
return F_25 ( V_7 , V_269 ) ;
case V_271 :
return F_27 ( V_30 , V_7 , V_269 ) ;
case V_272 :
return F_32 ( V_7 , V_269 ) ;
default:
break;
}
return - V_273 ;
}
