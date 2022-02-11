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
if ( ( V_91 . V_33 ^ V_11 -> V_33 ) & ~ V_95 ) {
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
if ( ( V_11 -> V_33 ^ V_92 . V_33 ) & V_34 ||
( ( V_11 -> V_33 & V_34 ) == V_35 &&
V_11 -> V_36 != V_92 . V_36 ) ) {
if ( V_11 -> V_33 & V_34 )
F_32 ( & V_7 -> V_13 , L_15 ) ;
F_17 ( V_30 , V_7 ) ;
F_31 ( & V_11 -> V_93 ) ;
}
else
F_31 ( & V_11 -> V_93 ) ;
return 0 ;
}
static int F_33 ( struct V_6 * V_7 ,
unsigned int T_3 * V_87 )
{
struct V_10 * V_11 = F_8 ( V_7 ) ;
unsigned int V_99 = 0 ;
if ( V_11 -> V_100 )
V_99 = V_101 ;
if ( F_26 ( V_87 , & V_99 , sizeof( unsigned int ) ) )
return - V_89 ;
return 0 ;
}
static void F_34 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = F_8 ( V_7 ) ;
struct V_102 * V_23 = V_7 -> V_23 ;
struct V_72 * V_73 = V_23 -> V_13 ;
unsigned V_103 ;
unsigned V_104 ;
V_11 -> V_37 = 48000000 / 2 ;
V_103 = F_15 ( V_73 -> V_56 . V_105 ) ;
V_104 = V_73 -> V_106 -> V_107 . V_108 ;
F_9 ( & V_7 -> V_13 , L_16 , V_18 ,
V_103 , V_104 ) ;
if ( V_104 > 1 ) {
int V_109 ;
if ( V_103 == 0x0800 ) {
V_11 -> V_38 = V_64 ;
V_11 -> V_37 = 120000000 / 2 ;
} else if ( V_103 == 0x0700 ) {
V_11 -> V_38 = V_63 ;
V_11 -> V_37 = 120000000 / 2 ;
} else
V_11 -> V_38 = V_52 ;
V_109 = V_23 -> V_26 -> V_110 -> V_107 . V_111 ;
if ( V_109 == 0 ) {
V_11 -> V_26 = V_112 ;
} else if ( V_109 == 1 ) {
V_11 -> V_26 = V_113 ;
} else if ( V_109 == 2 ) {
V_11 -> V_26 = V_114 ;
} else if ( V_109 == 3 ) {
V_11 -> V_26 = V_115 ;
}
if ( V_103 < 0x500 ) {
F_9 ( & V_7 -> V_13 ,
L_17 ,
V_18 ) ;
}
} else if ( V_103 < 0x200 ) {
V_11 -> V_38 = V_39 ;
V_11 -> V_37 = 12000000 / 16 ;
} else if ( V_103 < 0x400 ) {
V_11 -> V_38 = V_50 ;
if ( V_73 -> V_56 . V_116 == 0 &&
F_20 ( V_7 ) >= 0 ) {
F_9 ( & V_7 -> V_13 ,
L_18 ,
V_18 ) ;
V_11 -> V_38 = V_51 ;
}
} else if ( V_103 < 0x600 ) {
V_11 -> V_38 = V_51 ;
} else if ( V_103 < 0x900 ) {
V_11 -> V_38 = V_53 ;
} else if ( V_103 < 0x1000 ) {
V_11 -> V_38 = V_65 ;
} else {
V_11 -> V_38 = V_54 ;
}
F_35 ( & V_73 -> V_13 , L_19 , V_66 [ V_11 -> V_38 ] ) ;
}
static void F_36 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = F_8 ( V_7 ) ;
struct V_117 * V_26 = V_7 -> V_23 -> V_26 ;
struct V_118 * V_119 ;
unsigned V_120 ;
unsigned V_121 ;
V_120 = V_26 -> V_122 -> V_107 . V_123 ;
if ( ! V_120 )
return;
for ( V_121 = 0 ; V_121 < V_120 ; V_121 ++ ) {
V_119 = & V_26 -> V_122 -> V_124 [ V_121 ] . V_107 ;
if ( ! V_119 -> V_125 ) {
V_119 -> V_125 = F_37 ( 0x40 ) ;
F_38 ( & V_7 -> V_13 , L_20 ,
F_39 ( V_119 ) ) ;
}
}
V_11 -> V_126 = F_40 ( V_119 ) ;
}
static T_4 F_41 ( struct V_12 * V_13 ,
struct V_127 * V_128 , char * V_80 )
{
struct V_6 * V_7 = F_42 ( V_13 ) ;
struct V_10 * V_11 = F_8 ( V_7 ) ;
if ( V_11 -> V_33 & V_77 )
return sprintf ( V_80 , L_21 ) ;
else
return sprintf ( V_80 , L_22 , V_11 -> V_75 ) ;
}
static T_4 F_43 ( struct V_12 * V_13 ,
struct V_127 * V_128 ,
const char * V_129 , T_5 V_130 )
{
struct V_6 * V_7 = F_42 ( V_13 ) ;
struct V_10 * V_11 = F_8 ( V_7 ) ;
T_6 V_131 ;
int V_15 ;
if ( F_44 ( V_129 , 10 , & V_131 ) )
return - V_76 ;
V_11 -> V_75 = V_131 ;
V_15 = F_18 ( V_7 ) ;
if ( V_15 < 0 )
return - V_85 ;
return V_130 ;
}
static T_4 F_45 ( struct V_12 * V_13 ,
struct V_127 * V_128 , const char * V_129 , T_5 V_130 )
{
struct V_6 * V_7 = F_42 ( V_13 ) ;
struct V_10 * V_11 = F_8 ( V_7 ) ;
struct V_72 * V_73 = V_7 -> V_23 -> V_13 ;
unsigned int V_131 ;
int V_15 ;
if ( F_46 ( V_129 , 0 , & V_131 ) || V_131 >= 0x200 )
return - V_76 ;
F_9 ( & V_7 -> V_13 , L_23 , V_18 , V_131 ) ;
V_15 = F_10 ( V_73 ,
F_11 ( V_73 , 0 ) ,
V_132 ,
V_133 ,
V_131 , V_11 -> V_26 ,
NULL , 0 , V_27 ) ;
if ( V_15 < 0 ) {
F_9 ( & V_7 -> V_13 , L_24 , V_15 ) ;
return - V_85 ;
}
return V_130 ;
}
static int F_47 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = F_8 ( V_7 ) ;
int V_134 = 0 ;
if ( V_11 -> V_38 != V_39 ) {
F_9 ( & V_7 -> V_13 , L_25 , V_66 [ V_11 -> V_38 ] ) ;
V_134 = F_48 ( & V_7 -> V_13 , & V_135 ) ;
if ( ( ! V_134 ) &&
( V_11 -> V_38 == V_51 ||
V_11 -> V_38 == V_52 ||
V_11 -> V_38 == V_53 ||
V_11 -> V_38 == V_63 ||
V_11 -> V_38 == V_64 ||
V_11 -> V_38 == V_65 ||
V_11 -> V_38 == V_54 ) ) {
V_134 = F_48 ( & V_7 -> V_13 ,
& V_136 ) ;
}
}
return V_134 ;
}
static void F_49 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = F_8 ( V_7 ) ;
if ( V_11 -> V_38 != V_39 ) {
F_50 ( & V_7 -> V_13 , & V_135 ) ;
if ( V_11 -> V_38 == V_51 ||
V_11 -> V_38 == V_52 ||
V_11 -> V_38 == V_53 ||
V_11 -> V_38 == V_63 ||
V_11 -> V_38 == V_64 ||
V_11 -> V_38 == V_65 ||
V_11 -> V_38 == V_54 ) {
F_50 ( & V_7 -> V_13 , & V_136 ) ;
}
}
}
static int F_51 ( struct V_102 * V_23 ,
const struct V_137 * V_138 )
{
const struct V_139 * V_140 =
(struct V_139 * ) V_138 -> V_141 ;
if ( V_140 && V_140 -> V_142 ) {
int V_143 = V_140 -> V_142 ( V_23 ) ;
if ( V_143 != 0 )
return V_143 ;
}
F_52 ( V_23 , ( void * ) V_138 -> V_141 ) ;
return 0 ;
}
static int F_53 ( struct V_6 * V_7 )
{
struct V_10 * V_11 ;
const struct V_139 * V_140 = F_54 ( V_7 -> V_23 ) ;
V_11 = F_55 ( sizeof( struct V_10 ) , V_81 ) ;
if ( ! V_11 )
return - V_82 ;
F_56 ( & V_11 -> V_93 ) ;
if ( V_140 && V_140 -> V_144 )
V_140 -> V_144 ( V_11 ) ;
F_57 ( V_7 , V_11 ) ;
F_34 ( V_7 ) ;
F_36 ( V_7 ) ;
if ( F_24 ( V_7 ) < 0 )
V_11 -> V_75 = 16 ;
F_18 ( V_7 ) ;
F_47 ( V_7 ) ;
return 0 ;
}
static void F_58 ( struct V_10 * V_11 )
{
V_11 -> V_33 |= V_35 ;
V_11 -> V_36 = 77 ;
V_11 -> V_145 = 38400 ;
}
static void F_59 ( struct V_10 * V_11 )
{
V_11 -> V_33 |= V_35 ;
V_11 -> V_36 = 240 ;
V_11 -> V_145 = 38400 ;
V_11 -> V_146 = 1 ;
}
static int F_60 ( struct V_102 * V_23 )
{
struct V_72 * V_73 = V_23 -> V_13 ;
int V_75 = V_147 ;
if ( V_75 == 0 )
V_75 = 1 ;
if ( V_75 > 99 )
V_75 = 99 ;
F_9 ( & V_73 -> V_13 , L_26 , V_18 , V_75 ) ;
F_35 ( & V_73 -> V_13 , L_27 , V_75 ) ;
F_10 ( V_73 , F_11 ( V_73 , 0 ) ,
V_78 ,
V_79 ,
V_75 , 0 , NULL , 0 , V_27 ) ;
return 0 ;
}
static int F_61 ( struct V_102 * V_23 )
{
struct V_72 * V_73 = V_23 -> V_13 ;
struct V_117 * V_26 = V_23 -> V_26 ;
if ( V_26 == V_73 -> V_106 -> V_26 [ 0 ] ) {
F_35 ( & V_73 -> V_13 ,
L_28 ) ;
return - V_148 ;
}
return 0 ;
}
static int F_62 ( struct V_102 * V_23 )
{
struct V_72 * V_73 = V_23 -> V_13 ;
if ( V_73 -> V_149 && ! strcmp ( V_73 -> V_149 , L_29 ) )
return F_61 ( V_23 ) ;
if ( V_73 -> V_150 &&
( ! strcmp ( V_73 -> V_150 , L_30 ) ||
! strcmp ( V_73 -> V_150 , L_31 ) ) )
return F_61 ( V_23 ) ;
return 0 ;
}
static int F_63 ( struct V_102 * V_23 )
{
struct V_72 * V_73 = V_23 -> V_13 ;
struct V_117 * V_26 = V_23 -> V_26 ;
if ( V_26 == V_73 -> V_106 -> V_26 [ 0 ] ||
V_26 == V_73 -> V_106 -> V_26 [ 1 ] ) {
F_35 ( & V_73 -> V_13 , L_28 ) ;
return - V_148 ;
}
return 0 ;
}
static int F_64 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = F_8 ( V_7 ) ;
F_49 ( V_7 ) ;
F_23 ( V_11 ) ;
return 0 ;
}
static int F_65 ( struct V_29 * V_30 , struct V_6 * V_7 )
{
struct V_72 * V_13 = V_7 -> V_23 -> V_13 ;
struct V_10 * V_11 = F_8 ( V_7 ) ;
F_10 ( V_13 , F_11 ( V_13 , 0 ) ,
V_151 , V_152 ,
V_153 ,
V_11 -> V_26 , NULL , 0 , V_27 ) ;
if ( V_30 )
F_66 ( V_30 , V_7 , NULL ) ;
return F_67 ( V_30 , V_7 ) ;
}
static void F_68 ( struct V_6 * V_7 , int V_154 )
{
struct V_10 * V_11 = F_8 ( V_7 ) ;
if ( ! V_154 ) {
if ( F_10 ( V_7 -> V_23 -> V_13 ,
F_11 ( V_7 -> V_23 -> V_13 , 0 ) ,
V_155 ,
V_156 ,
0 , V_11 -> V_26 , NULL , 0 ,
V_27 ) < 0 ) {
F_19 ( & V_7 -> V_13 , L_32 ) ;
}
}
if ( V_154 )
F_69 ( V_7 , V_16 | V_17 ) ;
else
F_70 ( V_7 , V_16 | V_17 ) ;
}
static int F_71 ( struct V_6 * V_7 ,
void * V_157 , T_5 V_158 )
{
struct V_10 * V_11 ;
int V_130 ;
unsigned long V_33 ;
V_11 = F_8 ( V_7 ) ;
if ( V_11 -> V_38 == V_39 ) {
unsigned char * V_159 = V_157 ;
int V_121 , V_160 , V_161 ;
V_130 = 0 ;
F_72 ( & V_7 -> V_162 , V_33 ) ;
for ( V_121 = 0 ; V_121 < V_158 - 1 ; V_121 += V_11 -> V_126 ) {
V_160 = F_73 ( int , V_158 - V_121 , V_11 -> V_126 ) - 1 ;
V_161 = F_74 ( & V_7 -> V_163 , & V_159 [ V_121 + 1 ] , V_160 ) ;
if ( ! V_161 )
break;
V_7 -> V_164 . V_165 += V_161 ;
V_159 [ V_121 ] = ( V_161 << 2 ) + 1 ;
V_130 += V_161 + 1 ;
}
F_75 ( & V_7 -> V_162 , V_33 ) ;
} else {
V_130 = F_76 ( & V_7 -> V_163 , V_157 , V_158 ,
& V_7 -> V_162 ) ;
V_7 -> V_164 . V_165 += V_130 ;
}
return V_130 ;
}
static int F_77 ( struct V_6 * V_7 ,
struct V_10 * V_11 , char * V_166 , int V_160 )
{
int V_121 ;
char V_167 ;
char V_168 ;
char * V_169 ;
if ( V_160 < 2 ) {
F_9 ( & V_7 -> V_13 , L_33 ) ;
return 0 ;
}
V_167 = V_166 [ 0 ] & V_170 ;
if ( V_167 != V_11 -> V_171 ) {
char V_172 = V_167 ^ V_11 -> V_171 ;
if ( V_172 & V_173 )
V_7 -> V_164 . V_174 ++ ;
if ( V_172 & V_175 )
V_7 -> V_164 . V_176 ++ ;
if ( V_172 & V_177 )
V_7 -> V_164 . V_178 ++ ;
if ( V_172 & V_179 ) {
struct V_29 * V_30 ;
V_7 -> V_164 . V_180 ++ ;
V_30 = F_78 ( & V_7 -> V_7 ) ;
if ( V_30 )
F_79 ( V_7 , V_30 ,
V_167 & V_179 ) ;
F_80 ( V_30 ) ;
}
F_81 ( & V_7 -> V_7 . V_181 ) ;
V_11 -> V_171 = V_167 ;
}
if ( V_166 [ 1 ] & V_182 )
V_11 -> V_100 = 1 ;
else
V_11 -> V_100 = 0 ;
V_160 -= 2 ;
if ( ! V_160 )
return 0 ;
V_168 = V_183 ;
if ( V_166 [ 1 ] & V_184 ) {
if ( V_166 [ 1 ] & V_185 ) {
V_168 = V_186 ;
V_7 -> V_164 . V_187 ++ ;
F_82 ( V_7 ) ;
} else if ( V_166 [ 1 ] & V_188 ) {
V_168 = V_189 ;
V_7 -> V_164 . V_190 ++ ;
} else if ( V_166 [ 1 ] & V_191 ) {
V_168 = V_192 ;
V_7 -> V_164 . V_193 ++ ;
}
if ( V_166 [ 1 ] & V_194 ) {
V_7 -> V_164 . V_195 ++ ;
F_83 ( & V_7 -> V_7 , 0 , V_196 ) ;
}
}
V_7 -> V_164 . V_197 += V_160 ;
V_169 = V_166 + 2 ;
if ( V_7 -> V_7 . V_198 && V_7 -> V_199 ) {
for ( V_121 = 0 ; V_121 < V_160 ; V_121 ++ , V_169 ++ ) {
if ( ! F_84 ( V_7 , * V_169 ) )
F_83 ( & V_7 -> V_7 , * V_169 , V_168 ) ;
}
} else {
F_85 ( & V_7 -> V_7 , V_169 , V_168 , V_160 ) ;
}
return V_160 ;
}
static void F_86 ( struct V_200 * V_200 )
{
struct V_6 * V_7 = V_200 -> V_201 ;
struct V_10 * V_11 = F_8 ( V_7 ) ;
char * V_202 = ( char * ) V_200 -> V_203 ;
int V_121 ;
int V_160 ;
int V_130 = 0 ;
for ( V_121 = 0 ; V_121 < V_200 -> V_204 ; V_121 += V_11 -> V_126 ) {
V_160 = F_73 ( int , V_200 -> V_204 - V_121 , V_11 -> V_126 ) ;
V_130 += F_77 ( V_7 , V_11 , & V_202 [ V_121 ] , V_160 ) ;
}
if ( V_130 )
F_87 ( & V_7 -> V_7 ) ;
}
static void F_88 ( struct V_29 * V_30 , int V_205 )
{
struct V_6 * V_7 = V_30 -> V_206 ;
struct V_10 * V_11 = F_8 ( V_7 ) ;
T_2 V_14 ;
if ( V_205 )
V_14 = V_11 -> V_207 | V_208 ;
else
V_14 = V_11 -> V_207 ;
if ( F_10 ( V_7 -> V_23 -> V_13 ,
F_11 ( V_7 -> V_23 -> V_13 , 0 ) ,
V_209 ,
V_210 ,
V_14 , V_11 -> V_26 ,
NULL , 0 , V_27 ) < 0 ) {
F_19 ( & V_7 -> V_13 , L_34 ,
V_18 , V_205 ) ;
}
F_9 ( & V_7 -> V_13 , L_35 , V_18 ,
V_205 , V_14 ) ;
}
static bool F_89 ( struct V_6 * V_7 )
{
unsigned char V_80 [ 2 ] ;
int V_143 ;
V_143 = F_90 ( V_7 , V_80 ) ;
if ( V_143 == 2 ) {
if ( ! ( V_80 [ 1 ] & V_182 ) )
return false ;
}
return true ;
}
static void F_66 ( struct V_29 * V_30 ,
struct V_6 * V_7 , struct V_211 * V_212 )
{
struct V_72 * V_13 = V_7 -> V_23 -> V_13 ;
struct V_12 * V_213 = & V_7 -> V_13 ;
struct V_10 * V_11 = F_8 ( V_7 ) ;
struct V_211 * V_214 = & V_30 -> V_214 ;
unsigned int V_215 = V_214 -> V_216 ;
T_2 V_14 ;
unsigned int V_217 = V_214 -> V_218 ;
unsigned char V_219 ;
unsigned char V_220 ;
if ( V_11 -> V_145 && ( ( V_214 -> V_216 & V_221 ) != V_222 ) ) {
F_9 ( V_213 , L_36 , V_18 ) ;
F_16 ( V_30 , V_11 -> V_145 ,
V_11 -> V_145 ) ;
}
if ( V_11 -> V_146 ) {
F_9 ( V_213 , L_37 , V_18 ) ;
V_214 -> V_216 |= V_223 ;
}
if ( F_91 ( V_30 ) == V_224 ) {
F_38 ( V_213 , L_38 ) ;
V_214 -> V_216 &= ~ V_225 ;
if ( V_212 )
V_214 -> V_216 |= V_212 -> V_216 & V_225 ;
else
V_214 -> V_216 |= V_226 ;
}
V_215 = V_214 -> V_216 ;
if ( ! V_212 )
goto V_227;
if ( V_212 -> V_216 == V_214 -> V_216
&& V_212 -> V_228 == V_214 -> V_228
&& V_212 -> V_229 == V_214 -> V_229 )
goto V_230;
if ( ( V_212 -> V_216 & ( V_225 | V_231 | V_232 | V_233 | V_234 ) ) ==
( V_214 -> V_216 & ( V_225 | V_231 | V_232 | V_233 | V_234 ) ) )
goto V_235;
V_227:
V_14 = 0 ;
V_14 |= ( V_215 & V_234 ? V_236 :
V_237 ) ;
if ( V_215 & V_232 ) {
if ( V_215 & V_233 )
V_14 |= V_215 & V_231 ?
V_238 :
V_239 ;
else
V_14 |= V_215 & V_231 ?
V_240 :
V_241 ;
} else {
V_14 |= V_242 ;
}
switch ( V_215 & V_225 ) {
case V_243 :
F_9 ( V_213 , L_39 ) ;
break;
case V_244 :
V_14 |= 7 ;
F_9 ( V_213 , L_40 ) ;
break;
default:
case V_226 :
V_14 |= 8 ;
F_9 ( V_213 , L_41 ) ;
break;
}
V_11 -> V_207 = V_14 ;
if ( F_10 ( V_13 , F_11 ( V_13 , 0 ) ,
V_209 ,
V_210 ,
V_14 , V_11 -> V_26 ,
NULL , 0 , V_71 ) < 0 ) {
F_19 ( V_213 , L_42 ,
V_18 ) ;
}
V_235:
if ( ( V_215 & V_221 ) == V_222 ) {
if ( F_10 ( V_13 , F_11 ( V_13 , 0 ) ,
V_155 ,
V_156 ,
0 , V_11 -> V_26 ,
NULL , 0 , V_27 ) < 0 ) {
F_19 ( V_213 , L_43 ,
V_18 ) ;
}
F_70 ( V_7 , V_16 | V_17 ) ;
} else {
F_29 ( & V_11 -> V_93 ) ;
if ( F_17 ( V_30 , V_7 ) )
F_19 ( V_213 , L_44 , V_18 ) ;
F_31 ( & V_11 -> V_93 ) ;
if ( V_212 && ( V_212 -> V_216 & V_221 ) == V_222 )
F_69 ( V_7 , V_16 | V_17 ) ;
}
V_230:
if ( V_215 & V_223 ) {
F_9 ( V_213 , L_45 , V_18 ) ;
if ( F_10 ( V_13 ,
F_11 ( V_13 , 0 ) ,
V_155 ,
V_156 ,
0 , ( V_245 | V_11 -> V_26 ) ,
NULL , 0 , V_27 ) < 0 ) {
F_19 ( V_213 , L_46 ) ;
}
} else {
if ( V_217 & V_246 ) {
F_9 ( V_213 , L_47 ,
V_18 , V_217 ) ;
V_220 = V_214 -> V_247 [ V_248 ] ;
V_219 = V_214 -> V_247 [ V_249 ] ;
V_14 = ( V_219 << 8 ) | ( V_220 ) ;
if ( F_10 ( V_13 ,
F_11 ( V_13 , 0 ) ,
V_155 ,
V_156 ,
V_14 , ( V_250
| V_11 -> V_26 ) ,
NULL , 0 , V_27 ) < 0 ) {
F_19 ( & V_7 -> V_13 , L_48
L_49 ) ;
}
} else {
F_9 ( V_213 , L_50 , V_18 ) ;
if ( F_10 ( V_13 ,
F_11 ( V_13 , 0 ) ,
V_155 ,
V_156 ,
0 , V_11 -> V_26 ,
NULL , 0 , V_27 ) < 0 ) {
F_19 ( V_213 , L_51 ) ;
}
}
}
}
static int F_90 ( struct V_6 * V_7 ,
unsigned char V_167 [ 2 ] )
{
struct V_10 * V_11 = F_8 ( V_7 ) ;
unsigned char * V_80 ;
int V_160 ;
int V_143 ;
V_80 = F_21 ( 2 , V_81 ) ;
if ( ! V_80 )
return - V_82 ;
switch ( V_11 -> V_38 ) {
case V_39 :
V_160 = 1 ;
break;
case V_50 :
case V_51 :
case V_52 :
case V_53 :
case V_63 :
case V_64 :
case V_65 :
case V_54 :
V_160 = 2 ;
break;
default:
V_143 = - V_89 ;
goto V_251;
}
V_143 = F_10 ( V_7 -> V_23 -> V_13 ,
F_22 ( V_7 -> V_23 -> V_13 , 0 ) ,
V_252 ,
V_253 ,
0 , V_11 -> V_26 ,
V_80 , V_160 , V_27 ) ;
if ( V_143 < 1 ) {
F_19 ( & V_7 -> V_13 , L_52 , V_143 ) ;
if ( V_143 >= 0 )
V_143 = - V_85 ;
V_143 = F_12 ( V_143 ) ;
goto V_251;
}
V_167 [ 0 ] = V_80 [ 0 ] ;
if ( V_143 > 1 )
V_167 [ 1 ] = V_80 [ 1 ] ;
else
V_167 [ 1 ] = 0 ;
F_9 ( & V_7 -> V_13 , L_53 , V_18 , V_167 [ 0 ] ,
V_167 [ 1 ] ) ;
V_251:
F_23 ( V_80 ) ;
return V_143 ;
}
static int F_92 ( struct V_29 * V_30 )
{
struct V_6 * V_7 = V_30 -> V_206 ;
struct V_10 * V_11 = F_8 ( V_7 ) ;
unsigned char V_80 [ 2 ] ;
int V_143 ;
V_143 = F_90 ( V_7 , V_80 ) ;
if ( V_143 < 0 )
return V_143 ;
V_143 = ( V_80 [ 0 ] & V_254 ? V_255 : 0 ) |
( V_80 [ 0 ] & V_256 ? V_257 : 0 ) |
( V_80 [ 0 ] & V_258 ? V_259 : 0 ) |
( V_80 [ 0 ] & V_260 ? V_261 : 0 ) |
V_11 -> V_28 ;
return V_143 ;
}
static int F_93 ( struct V_29 * V_30 ,
unsigned int V_8 , unsigned int V_9 )
{
struct V_6 * V_7 = V_30 -> V_206 ;
return F_7 ( V_7 , V_8 , V_9 ) ;
}
static int F_94 ( struct V_29 * V_30 ,
unsigned int V_262 , unsigned long V_263 )
{
struct V_6 * V_7 = V_30 -> V_206 ;
void T_3 * V_264 = ( void T_3 * ) V_263 ;
switch ( V_262 ) {
case V_265 :
return F_25 ( V_7 , V_264 ) ;
case V_266 :
return F_27 ( V_30 , V_7 , V_264 ) ;
case V_267 :
return F_33 ( V_7 , V_264 ) ;
default:
break;
}
return - V_268 ;
}
