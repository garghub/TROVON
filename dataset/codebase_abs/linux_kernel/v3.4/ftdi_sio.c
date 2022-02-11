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
unsigned V_12 ;
int V_13 ;
if ( ( ( V_8 | V_9 ) & ( V_14 | V_15 ) ) == 0 ) {
F_9 ( L_1 , V_16 ) ;
return 0 ;
}
V_9 &= ~ V_8 ;
V_12 = 0 ;
if ( V_9 & V_14 )
V_12 |= V_17 ;
if ( V_9 & V_15 )
V_12 |= V_18 ;
if ( V_8 & V_14 )
V_12 |= V_19 ;
if ( V_8 & V_15 )
V_12 |= V_20 ;
V_13 = F_10 ( V_7 -> V_21 -> V_22 ,
F_11 ( V_7 -> V_21 -> V_22 , 0 ) ,
V_23 ,
V_24 ,
V_12 , V_11 -> V_25 ,
NULL , 0 , V_26 ) ;
if ( V_13 < 0 ) {
F_9 ( L_2 ,
V_16 ,
( V_8 & V_14 ) ? L_3 :
( V_9 & V_14 ) ? L_4 : L_5 ,
( V_8 & V_15 ) ? L_3 :
( V_9 & V_15 ) ? L_4 : L_5 ) ;
} else {
F_9 ( L_6 , V_16 ,
( V_8 & V_14 ) ? L_3 :
( V_9 & V_14 ) ? L_4 : L_5 ,
( V_8 & V_15 ) ? L_3 :
( V_9 & V_15 ) ? L_4 : L_5 ) ;
V_11 -> V_27 = ( V_11 -> V_27 & ~ V_9 ) | V_8 ;
}
return V_13 ;
}
static T_1 F_12 ( struct V_28 * V_29 ,
struct V_6 * V_7 )
{
struct V_10 * V_11 = F_8 ( V_7 ) ;
T_1 V_30 = 0 ;
int V_31 = 1 ;
int V_1 ;
V_1 = F_13 ( V_29 ) ;
F_9 ( L_7 , V_16 , V_1 ) ;
if ( V_1 == 38400 &&
( ( V_11 -> V_32 & V_33 ) == V_34 ) &&
( V_11 -> V_35 ) ) {
V_1 = V_11 -> V_36 / V_11 -> V_35 ;
F_9 ( L_8 ,
V_16 , V_11 -> V_35 , V_1 ) ;
}
if ( ! V_1 )
V_1 = 9600 ;
switch ( V_11 -> V_37 ) {
case V_38 :
switch ( V_1 ) {
case 300 : V_30 = V_39 ; break;
case 600 : V_30 = V_40 ; break;
case 1200 : V_30 = V_41 ; break;
case 2400 : V_30 = V_42 ; break;
case 4800 : V_30 = V_43 ; break;
case 9600 : V_30 = V_44 ; break;
case 19200 : V_30 = V_45 ; break;
case 38400 : V_30 = V_46 ; break;
case 57600 : V_30 = V_47 ; break;
case 115200 : V_30 = V_48 ; break;
}
if ( V_30 == 0 ) {
F_9 ( L_9 ,
V_16 , V_1 ) ;
V_30 = V_44 ;
V_1 = 9600 ;
V_31 = 0 ;
}
break;
case V_49 :
if ( V_1 <= 3000000 ) {
V_30 = F_2 ( V_1 ) ;
} else {
F_9 ( L_10 , V_16 ) ;
V_1 = 9600 ;
V_30 = F_2 ( 9600 ) ;
V_31 = 0 ;
}
break;
case V_50 :
case V_51 :
case V_52 :
case V_53 :
if ( V_1 <= 3000000 ) {
T_2 V_54 = F_14 (
V_7 -> V_21 -> V_22 -> V_55 . V_56 ) ;
if ( ( ( V_57 == V_54 ) ||
( V_58 == V_54 ) ||
( V_59 == V_54 ) ||
( V_60 == V_54 ) ||
( V_61 == V_54 ) ) &&
( V_1 == 19200 ) ) {
V_1 = 1200000 ;
}
V_30 = F_4 ( V_1 ) ;
} else {
F_9 ( L_10 , V_16 ) ;
V_30 = F_4 ( 9600 ) ;
V_31 = 0 ;
V_1 = 9600 ;
}
break;
case V_62 :
case V_63 :
case V_64 :
if ( ( V_1 <= 12000000 ) && ( V_1 >= 1200 ) ) {
V_30 = F_6 ( V_1 ) ;
} else if ( V_1 < 1200 ) {
V_30 = F_4 ( V_1 ) ;
} else {
F_9 ( L_10 , V_16 ) ;
V_30 = F_4 ( 9600 ) ;
V_31 = 0 ;
V_1 = 9600 ;
}
break;
}
if ( V_31 ) {
F_9 ( L_11 ,
V_16 , V_1 , ( unsigned long ) V_30 ,
V_65 [ V_11 -> V_37 ] ) ;
}
F_15 ( V_29 , V_1 , V_1 ) ;
return V_30 ;
}
static int F_16 ( struct V_28 * V_29 , struct V_6 * V_7 )
{
struct V_10 * V_11 = F_8 ( V_7 ) ;
T_2 V_12 ;
T_2 V_66 ;
T_1 V_67 ;
int V_13 ;
V_67 = F_12 ( V_29 , V_7 ) ;
V_12 = ( T_2 ) V_67 ;
V_66 = ( T_2 ) ( V_67 >> 16 ) ;
if ( ( V_11 -> V_37 == V_51 ) || ( V_11 -> V_37 == V_62 ) ||
( V_11 -> V_37 == V_63 ) || ( V_11 -> V_37 == V_64 ) ) {
V_66 = ( T_2 ) ( ( V_66 << 8 ) | V_11 -> V_25 ) ;
}
V_13 = F_10 ( V_7 -> V_21 -> V_22 ,
F_11 ( V_7 -> V_21 -> V_22 , 0 ) ,
V_68 ,
V_69 ,
V_12 , V_66 ,
NULL , 0 , V_70 ) ;
return V_13 ;
}
static int F_17 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = F_8 ( V_7 ) ;
struct V_71 * V_72 = V_7 -> V_21 -> V_22 ;
int V_13 ;
int V_73 = V_11 -> V_74 ;
if ( V_11 -> V_32 & V_75 )
V_73 = 1 ;
F_9 ( L_12 , V_16 , V_73 ) ;
V_13 = F_10 ( V_72 ,
F_11 ( V_72 , 0 ) ,
V_76 ,
V_77 ,
V_73 , V_11 -> V_25 ,
NULL , 0 , V_26 ) ;
if ( V_13 < 0 )
F_18 ( & V_7 -> V_22 , L_13 , V_13 ) ;
return V_13 ;
}
static int F_19 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = F_8 ( V_7 ) ;
struct V_71 * V_72 = V_7 -> V_21 -> V_22 ;
unsigned char * V_78 ;
int V_13 ;
F_9 ( L_14 , V_16 ) ;
V_78 = F_20 ( 1 , V_79 ) ;
if ( ! V_78 )
return - V_80 ;
V_13 = F_10 ( V_72 ,
F_21 ( V_72 , 0 ) ,
V_81 ,
V_82 ,
0 , V_11 -> V_25 ,
V_78 , 1 , V_26 ) ;
if ( V_13 < 0 )
F_18 ( & V_7 -> V_22 , L_15 , V_13 ) ;
else
V_11 -> V_74 = V_78 [ 0 ] ;
F_22 ( V_78 ) ;
return V_13 ;
}
static int F_23 ( struct V_6 * V_7 ,
struct V_83 T_3 * V_84 )
{
struct V_10 * V_11 = F_8 ( V_7 ) ;
struct V_83 V_85 ;
if ( ! V_84 )
return - V_86 ;
memset ( & V_85 , 0 , sizeof( V_85 ) ) ;
V_85 . V_32 = V_11 -> V_32 ;
V_85 . V_36 = V_11 -> V_36 ;
V_85 . V_35 = V_11 -> V_35 ;
if ( F_24 ( V_84 , & V_85 , sizeof( * V_84 ) ) )
return - V_86 ;
return 0 ;
}
static int F_25 ( struct V_28 * V_29 ,
struct V_6 * V_7 , struct V_83 T_3 * V_87 )
{
struct V_10 * V_11 = F_8 ( V_7 ) ;
struct V_83 V_88 ;
struct V_10 V_89 ;
if ( F_26 ( & V_88 , V_87 , sizeof( V_88 ) ) )
return - V_86 ;
F_27 ( & V_11 -> V_90 ) ;
V_89 = * V_11 ;
if ( ! F_28 ( V_91 ) ) {
if ( ( ( V_88 . V_32 & ~ V_92 ) !=
( V_11 -> V_32 & ~ V_92 ) ) ) {
F_29 ( & V_11 -> V_90 ) ;
return - V_93 ;
}
V_11 -> V_32 = ( ( V_11 -> V_32 & ~ V_92 ) |
( V_88 . V_32 & V_92 ) ) ;
V_11 -> V_35 = V_88 . V_35 ;
goto V_94;
}
if ( V_88 . V_36 != V_11 -> V_36 ) {
F_29 ( & V_11 -> V_90 ) ;
return - V_95 ;
}
V_11 -> V_32 = ( ( V_11 -> V_32 & ~ V_96 ) |
( V_88 . V_32 & V_96 ) ) ;
V_11 -> V_35 = V_88 . V_35 ;
F_17 ( V_7 ) ;
V_94:
if ( ( V_89 . V_32 & V_33 ) !=
( V_11 -> V_32 & V_33 ) ) {
if ( ( V_11 -> V_32 & V_33 ) == V_97 )
V_29 -> V_98 = 57600 ;
else if ( ( V_11 -> V_32 & V_33 ) == V_99 )
V_29 -> V_98 = 115200 ;
else if ( ( V_11 -> V_32 & V_33 ) == V_100 )
V_29 -> V_98 = 230400 ;
else if ( ( V_11 -> V_32 & V_33 ) == V_101 )
V_29 -> V_98 = 460800 ;
else
V_29 -> V_98 = 0 ;
}
if ( ( ( V_89 . V_32 & V_33 ) !=
( V_11 -> V_32 & V_33 ) ) ||
( ( ( V_11 -> V_32 & V_33 ) == V_34 ) &&
( V_89 . V_35 != V_11 -> V_35 ) ) ) {
F_16 ( V_29 , V_7 ) ;
F_29 ( & V_11 -> V_90 ) ;
}
else
F_29 ( & V_11 -> V_90 ) ;
return 0 ;
}
static int F_30 ( struct V_6 * V_7 ,
struct V_83 T_3 * V_84 )
{
struct V_10 * V_11 = F_8 ( V_7 ) ;
unsigned int V_102 = 0 ;
if ( ! V_84 )
return - V_86 ;
if ( V_11 -> V_103 )
V_102 = V_104 ;
if ( F_24 ( V_84 , & V_102 , sizeof( unsigned int ) ) )
return - V_86 ;
return 0 ;
}
static void F_31 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = F_8 ( V_7 ) ;
struct V_105 * V_21 = V_7 -> V_21 ;
struct V_71 * V_72 = V_21 -> V_22 ;
unsigned V_106 ;
unsigned V_107 ;
V_11 -> V_36 = 48000000 / 2 ;
V_106 = F_14 ( V_72 -> V_55 . V_108 ) ;
V_107 = V_72 -> V_109 -> V_110 . V_111 ;
F_9 ( L_16 , V_16 ,
V_106 , V_107 ) ;
if ( V_107 > 1 ) {
int V_112 ;
if ( V_106 == 0x0800 ) {
V_11 -> V_37 = V_63 ;
V_11 -> V_36 = 120000000 / 2 ;
} else if ( V_106 == 0x0700 ) {
V_11 -> V_37 = V_62 ;
V_11 -> V_36 = 120000000 / 2 ;
} else
V_11 -> V_37 = V_51 ;
V_112 = V_21 -> V_25 -> V_113 -> V_110 . V_114 ;
if ( V_112 == 0 ) {
V_11 -> V_25 = V_115 ;
} else if ( V_112 == 1 ) {
V_11 -> V_25 = V_116 ;
} else if ( V_112 == 2 ) {
V_11 -> V_25 = V_117 ;
} else if ( V_112 == 3 ) {
V_11 -> V_25 = V_118 ;
}
if ( V_106 < 0x500 ) {
F_9 ( L_17 ,
V_16 ) ;
}
} else if ( V_106 < 0x200 ) {
V_11 -> V_37 = V_38 ;
V_11 -> V_36 = 12000000 / 16 ;
} else if ( V_106 < 0x400 ) {
V_11 -> V_37 = V_49 ;
} else if ( V_106 < 0x600 ) {
V_11 -> V_37 = V_50 ;
} else if ( V_106 < 0x900 ) {
V_11 -> V_37 = V_52 ;
} else if ( V_106 < 0x1000 ) {
V_11 -> V_37 = V_64 ;
} else {
V_11 -> V_37 = V_53 ;
}
F_32 ( & V_72 -> V_22 , L_18 , V_65 [ V_11 -> V_37 ] ) ;
}
static void F_33 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = F_8 ( V_7 ) ;
struct V_105 * V_21 = V_7 -> V_21 ;
struct V_71 * V_72 = V_21 -> V_22 ;
struct V_119 * V_25 = V_21 -> V_25 ;
struct V_120 * V_121 = & V_25 -> V_122 -> V_123 [ 1 ] . V_110 ;
unsigned V_124 ;
int V_125 ;
V_124 = V_25 -> V_122 -> V_110 . V_126 ;
F_32 ( & V_72 -> V_22 , L_19 , V_124 ) ;
for ( V_125 = 0 ; V_125 < V_124 ; V_125 ++ ) {
F_32 ( & V_72 -> V_22 , L_20 , V_125 + 1 ,
V_25 -> V_122 -> V_123 [ V_125 ] . V_110 . V_127 ) ;
V_121 = & V_25 -> V_122 -> V_123 [ V_125 ] . V_110 ;
if ( V_121 -> V_127 == 0 ) {
V_121 -> V_127 = F_34 ( 0x40 ) ;
F_32 ( & V_72 -> V_22 , L_21 , V_125 ) ;
}
}
V_11 -> V_128 = F_35 ( V_121 ) ;
F_32 ( & V_72 -> V_22 , L_22 , V_11 -> V_128 ) ;
}
static T_4 F_36 ( struct V_129 * V_22 ,
struct V_130 * V_131 , char * V_78 )
{
struct V_6 * V_7 = F_37 ( V_22 ) ;
struct V_10 * V_11 = F_8 ( V_7 ) ;
if ( V_11 -> V_32 & V_75 )
return sprintf ( V_78 , L_23 ) ;
else
return sprintf ( V_78 , L_24 , V_11 -> V_74 ) ;
}
static T_4 F_38 ( struct V_129 * V_22 ,
struct V_130 * V_131 , const char * V_132 ,
T_5 V_133 )
{
struct V_6 * V_7 = F_37 ( V_22 ) ;
struct V_10 * V_11 = F_8 ( V_7 ) ;
int V_134 = F_39 ( V_132 , NULL , 10 ) ;
int V_13 ;
V_11 -> V_74 = V_134 ;
V_13 = F_17 ( V_7 ) ;
if ( V_13 < 0 )
return - V_135 ;
return V_133 ;
}
static T_4 F_40 ( struct V_129 * V_22 ,
struct V_130 * V_131 , const char * V_132 , T_5 V_133 )
{
struct V_6 * V_7 = F_37 ( V_22 ) ;
struct V_10 * V_11 = F_8 ( V_7 ) ;
struct V_71 * V_72 = V_7 -> V_21 -> V_22 ;
int V_134 = F_39 ( V_132 , NULL , 10 ) ;
int V_13 ;
F_9 ( L_25 , V_16 , V_134 ) ;
V_13 = F_10 ( V_72 ,
F_11 ( V_72 , 0 ) ,
V_136 ,
V_137 ,
V_134 , V_11 -> V_25 ,
NULL , 0 , V_26 ) ;
if ( V_13 < 0 ) {
F_9 ( L_26 , V_13 ) ;
return - V_135 ;
}
return V_133 ;
}
static int F_41 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = F_8 ( V_7 ) ;
int V_138 = 0 ;
F_9 ( L_14 , V_16 ) ;
if ( V_11 -> V_37 != V_38 ) {
F_9 ( L_27 , V_65 [ V_11 -> V_37 ] ) ;
V_138 = F_42 ( & V_7 -> V_22 , & V_139 ) ;
if ( ( ! V_138 ) &&
( V_11 -> V_37 == V_50 ||
V_11 -> V_37 == V_51 ||
V_11 -> V_37 == V_52 ||
V_11 -> V_37 == V_62 ||
V_11 -> V_37 == V_63 ||
V_11 -> V_37 == V_64 ||
V_11 -> V_37 == V_53 ) ) {
V_138 = F_42 ( & V_7 -> V_22 ,
& V_140 ) ;
}
}
return V_138 ;
}
static void F_43 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = F_8 ( V_7 ) ;
F_9 ( L_14 , V_16 ) ;
if ( V_11 -> V_37 != V_38 ) {
F_44 ( & V_7 -> V_22 , & V_139 ) ;
if ( V_11 -> V_37 == V_50 ||
V_11 -> V_37 == V_51 ||
V_11 -> V_37 == V_52 ||
V_11 -> V_37 == V_62 ||
V_11 -> V_37 == V_63 ||
V_11 -> V_37 == V_64 ||
V_11 -> V_37 == V_53 ) {
F_44 ( & V_7 -> V_22 , & V_140 ) ;
}
}
}
static int F_45 ( struct V_105 * V_21 ,
const struct V_141 * V_142 )
{
struct V_143 * V_144 =
(struct V_143 * ) V_142 -> V_145 ;
if ( V_144 && V_144 -> V_146 ) {
int V_147 = V_144 -> V_146 ( V_21 ) ;
if ( V_147 != 0 )
return V_147 ;
}
F_46 ( V_21 , ( void * ) V_142 -> V_145 ) ;
return 0 ;
}
static int F_47 ( struct V_6 * V_7 )
{
struct V_10 * V_11 ;
struct V_143 * V_144 = F_48 ( V_7 -> V_21 ) ;
F_9 ( L_14 , V_16 ) ;
V_11 = F_49 ( sizeof( struct V_10 ) , V_79 ) ;
if ( ! V_11 ) {
F_18 ( & V_7 -> V_22 , L_28 , V_16 ,
sizeof( struct V_10 ) ) ;
return - V_80 ;
}
F_50 ( & V_11 -> V_148 ) ;
F_51 ( & V_11 -> V_90 ) ;
memset ( & V_11 -> V_149 , 0x00 , sizeof( V_11 -> V_149 ) ) ;
F_52 ( & V_11 -> V_150 ) ;
V_11 -> V_32 = V_75 ;
V_11 -> V_151 = false ;
if ( V_144 && V_144 -> V_152 )
V_144 -> V_152 ( V_11 ) ;
V_11 -> V_7 = V_7 ;
F_53 ( V_7 , V_11 ) ;
F_31 ( V_7 ) ;
F_33 ( V_7 ) ;
if ( F_19 ( V_7 ) < 0 )
V_11 -> V_74 = 16 ;
F_17 ( V_7 ) ;
F_41 ( V_7 ) ;
return 0 ;
}
static void F_54 ( struct V_10 * V_11 )
{
F_9 ( L_14 , V_16 ) ;
V_11 -> V_32 |= V_34 ;
V_11 -> V_35 = 77 ;
V_11 -> V_153 = 38400 ;
}
static void F_55 ( struct V_10 * V_11 )
{
F_9 ( L_14 , V_16 ) ;
V_11 -> V_32 |= V_34 ;
V_11 -> V_35 = 240 ;
V_11 -> V_153 = 38400 ;
V_11 -> V_154 = 1 ;
}
static int F_56 ( struct V_105 * V_21 )
{
struct V_71 * V_72 = V_21 -> V_22 ;
int V_74 = V_155 ;
if ( V_74 == 0 )
V_74 = 1 ;
if ( V_74 > 99 )
V_74 = 99 ;
F_9 ( L_29 , V_16 , V_74 ) ;
F_32 ( & V_72 -> V_22 , L_30 , V_74 ) ;
F_10 ( V_72 , F_11 ( V_72 , 0 ) ,
V_76 ,
V_77 ,
V_74 , 0 , NULL , 0 , V_26 ) ;
return 0 ;
}
static int F_57 ( struct V_105 * V_21 )
{
struct V_71 * V_72 = V_21 -> V_22 ;
struct V_119 * V_25 = V_21 -> V_25 ;
F_9 ( L_14 , V_16 ) ;
if ( V_25 == V_72 -> V_109 -> V_25 [ 0 ] ) {
F_32 ( & V_72 -> V_22 ,
L_31 ) ;
return - V_156 ;
}
return 0 ;
}
static int F_58 ( struct V_105 * V_21 )
{
struct V_71 * V_72 = V_21 -> V_22 ;
F_9 ( L_14 , V_16 ) ;
if ( ( V_72 -> V_157 && ! strcmp ( V_72 -> V_157 , L_32 ) ) ||
( V_72 -> V_158 && ! strcmp ( V_72 -> V_158 , L_33 ) ) )
return F_57 ( V_21 ) ;
return 0 ;
}
static int F_59 ( struct V_105 * V_21 )
{
struct V_71 * V_72 = V_21 -> V_22 ;
struct V_119 * V_25 = V_21 -> V_25 ;
F_9 ( L_14 , V_16 ) ;
if ( V_25 == V_72 -> V_109 -> V_25 [ 2 ] )
return 0 ;
F_32 ( & V_72 -> V_22 , L_31 ) ;
return - V_156 ;
}
static int F_60 ( struct V_105 * V_21 )
{
struct V_159 * V_160 = V_21 -> V_22 -> V_161 [ 1 ] ;
struct V_120 * V_121 = & V_160 -> V_110 ;
if ( V_160 -> V_162 && V_121 -> V_127 == 0 ) {
V_121 -> V_127 = F_34 ( 0x40 ) ;
F_32 ( & V_21 -> V_22 -> V_22 ,
L_34 ) ;
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
F_9 ( L_14 , V_16 ) ;
V_11 -> V_151 = true ;
F_64 ( & V_11 -> V_150 ) ;
F_43 ( V_7 ) ;
F_65 ( & V_11 -> V_148 , F_61 ) ;
return 0 ;
}
static int F_66 ( struct V_28 * V_29 , struct V_6 * V_7 )
{
struct V_164 V_165 ;
struct V_71 * V_22 = V_7 -> V_21 -> V_22 ;
struct V_10 * V_11 = F_8 ( V_7 ) ;
int V_102 ;
F_9 ( L_14 , V_16 ) ;
F_10 ( V_22 , F_11 ( V_22 , 0 ) ,
V_166 , V_167 ,
V_168 ,
V_11 -> V_25 , NULL , 0 , V_26 ) ;
if ( V_29 ) {
memset ( & V_165 , 0 , sizeof( V_165 ) ) ;
F_67 ( V_29 , V_7 , & V_165 ) ;
}
V_102 = F_68 ( V_29 , V_7 ) ;
if ( ! V_102 )
F_69 ( & V_11 -> V_148 ) ;
return V_102 ;
}
static void F_70 ( struct V_6 * V_7 , int V_169 )
{
struct V_10 * V_11 = F_8 ( V_7 ) ;
F_27 ( & V_7 -> V_21 -> V_170 ) ;
if ( ! V_7 -> V_21 -> V_171 ) {
if ( ! V_169 && F_10 ( V_7 -> V_21 -> V_22 ,
F_11 ( V_7 -> V_21 -> V_22 , 0 ) ,
V_172 ,
V_173 ,
0 , V_11 -> V_25 , NULL , 0 ,
V_26 ) < 0 ) {
F_18 ( & V_7 -> V_22 , L_35 ) ;
}
if ( V_169 )
F_71 ( V_7 , V_14 | V_15 ) ;
else
F_72 ( V_7 , V_14 | V_15 ) ;
}
F_29 ( & V_7 -> V_21 -> V_170 ) ;
}
static void F_73 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = F_8 ( V_7 ) ;
F_9 ( L_14 , V_16 ) ;
F_74 ( V_7 ) ;
F_65 ( & V_11 -> V_148 , F_61 ) ;
}
static int F_75 ( struct V_6 * V_7 ,
void * V_174 , T_5 V_175 )
{
struct V_10 * V_11 ;
int V_133 ;
unsigned long V_32 ;
V_11 = F_8 ( V_7 ) ;
if ( V_11 -> V_37 == V_38 ) {
unsigned char * V_176 = V_174 ;
int V_125 , V_177 , V_178 ;
V_133 = 0 ;
F_76 ( & V_7 -> V_179 , V_32 ) ;
for ( V_125 = 0 ; V_125 < V_175 - 1 ; V_125 += V_11 -> V_128 ) {
V_177 = F_77 ( int , V_175 - V_125 , V_11 -> V_128 ) - 1 ;
V_178 = F_78 ( & V_7 -> V_180 , & V_176 [ V_125 + 1 ] , V_177 ) ;
if ( ! V_178 )
break;
V_11 -> V_149 . V_181 += V_178 ;
V_176 [ V_125 ] = ( V_178 << 2 ) + 1 ;
V_133 += V_178 + 1 ;
}
F_79 ( & V_7 -> V_179 , V_32 ) ;
} else {
V_133 = F_80 ( & V_7 -> V_180 , V_174 , V_175 ,
& V_7 -> V_179 ) ;
V_11 -> V_149 . V_181 += V_133 ;
}
return V_133 ;
}
static int F_81 ( struct V_28 * V_29 ,
struct V_6 * V_7 , struct V_10 * V_11 ,
char * V_182 , int V_177 )
{
int V_125 ;
char V_183 ;
char V_184 ;
char * V_185 ;
F_9 ( L_36 , V_16 , V_7 -> V_186 ) ;
if ( V_177 < 2 ) {
F_9 ( L_37 ) ;
return 0 ;
}
V_183 = V_182 [ 0 ] & V_187 ;
if ( V_183 != V_11 -> V_188 ) {
char V_189 = V_183 ^ V_11 -> V_188 ;
if ( V_189 & V_190 )
V_11 -> V_149 . V_191 ++ ;
if ( V_189 & V_192 )
V_11 -> V_149 . V_193 ++ ;
if ( V_189 & V_194 )
V_11 -> V_149 . V_195 ++ ;
if ( V_189 & V_196 )
V_11 -> V_149 . V_197 ++ ;
F_64 ( & V_11 -> V_150 ) ;
V_11 -> V_188 = V_183 ;
}
V_184 = V_198 ;
if ( V_182 [ 1 ] & V_199 ) {
if ( V_182 [ 1 ] & V_200 ) {
V_184 = V_201 ;
V_11 -> V_149 . V_202 ++ ;
F_82 ( V_7 ) ;
} else if ( V_182 [ 1 ] & V_203 ) {
V_184 = V_204 ;
V_11 -> V_149 . V_205 ++ ;
} else if ( V_182 [ 1 ] & V_206 ) {
V_184 = V_207 ;
V_11 -> V_149 . V_208 ++ ;
}
if ( V_182 [ 1 ] & V_209 ) {
V_11 -> V_149 . V_210 ++ ;
F_83 ( V_29 , 0 , V_211 ) ;
}
}
if ( V_182 [ 1 ] & V_212 )
V_11 -> V_103 = 1 ;
else
V_11 -> V_103 = 0 ;
V_177 -= 2 ;
if ( ! V_177 )
return 0 ;
V_11 -> V_149 . V_213 += V_177 ;
V_185 = V_182 + 2 ;
if ( V_7 -> V_7 . V_214 && V_7 -> V_215 ) {
for ( V_125 = 0 ; V_125 < V_177 ; V_125 ++ , V_185 ++ ) {
if ( ! F_84 ( V_7 , * V_185 ) )
F_83 ( V_29 , * V_185 , V_184 ) ;
}
} else {
F_85 ( V_29 , V_185 , V_184 , V_177 ) ;
}
return V_177 ;
}
static void F_86 ( struct V_216 * V_216 )
{
struct V_6 * V_7 = V_216 -> V_217 ;
struct V_28 * V_29 ;
struct V_10 * V_11 = F_8 ( V_7 ) ;
char * V_218 = ( char * ) V_216 -> V_219 ;
int V_125 ;
int V_177 ;
int V_133 = 0 ;
V_29 = F_87 ( & V_7 -> V_7 ) ;
if ( ! V_29 )
return;
for ( V_125 = 0 ; V_125 < V_216 -> V_220 ; V_125 += V_11 -> V_128 ) {
V_177 = F_77 ( int , V_216 -> V_220 - V_125 , V_11 -> V_128 ) ;
V_133 += F_81 ( V_29 , V_7 , V_11 , & V_218 [ V_125 ] , V_177 ) ;
}
if ( V_133 )
F_88 ( V_29 ) ;
F_89 ( V_29 ) ;
}
static void F_90 ( struct V_28 * V_29 , int V_221 )
{
struct V_6 * V_7 = V_29 -> V_222 ;
struct V_10 * V_11 = F_8 ( V_7 ) ;
T_2 V_12 ;
if ( V_221 )
V_12 = V_11 -> V_223 | V_224 ;
else
V_12 = V_11 -> V_223 ;
if ( F_10 ( V_7 -> V_21 -> V_22 ,
F_11 ( V_7 -> V_21 -> V_22 , 0 ) ,
V_225 ,
V_226 ,
V_12 , V_11 -> V_25 ,
NULL , 0 , V_26 ) < 0 ) {
F_18 ( & V_7 -> V_22 , L_38
L_39 , V_16 , V_221 ) ;
}
F_9 ( L_40 , V_16 ,
V_221 , V_12 ) ;
}
static void F_67 ( struct V_28 * V_29 ,
struct V_6 * V_7 , struct V_164 * V_227 )
{
struct V_71 * V_22 = V_7 -> V_21 -> V_22 ;
struct V_10 * V_11 = F_8 ( V_7 ) ;
struct V_164 * V_228 = V_29 -> V_228 ;
unsigned int V_229 = V_228 -> V_230 ;
T_2 V_12 ;
unsigned int V_231 = V_228 -> V_232 ;
unsigned char V_233 ;
unsigned char V_234 ;
F_9 ( L_14 , V_16 ) ;
if ( V_11 -> V_153 && ( ( V_228 -> V_230 & V_235 ) != V_236 ) ) {
F_9 ( L_41 , V_16 ) ;
F_15 ( V_29 , V_11 -> V_153 ,
V_11 -> V_153 ) ;
}
if ( V_11 -> V_154 ) {
F_9 ( L_42 , V_16 ) ;
V_228 -> V_230 |= V_237 ;
}
V_229 = V_228 -> V_230 ;
if ( V_227 == 0 )
goto V_238;
if ( V_227 -> V_230 == V_228 -> V_230
&& V_227 -> V_239 == V_228 -> V_239
&& V_227 -> V_240 == V_228 -> V_240 )
goto V_241;
if ( ( V_227 -> V_230 & ( V_242 | V_243 | V_244 | V_245 | V_246 ) ) ==
( V_228 -> V_230 & ( V_242 | V_243 | V_244 | V_245 | V_246 ) ) )
goto V_247;
V_238:
V_12 = 0 ;
V_12 |= ( V_229 & V_246 ? V_248 :
V_249 ) ;
if ( V_229 & V_244 ) {
if ( V_229 & V_245 )
V_12 |= V_229 & V_243 ?
V_250 :
V_251 ;
else
V_12 |= V_229 & V_243 ?
V_252 :
V_253 ;
} else {
V_12 |= V_254 ;
}
if ( V_229 & V_242 ) {
switch ( V_229 & V_242 ) {
case V_255 : V_12 |= 7 ; F_9 ( L_43 ) ; break;
case V_256 : V_12 |= 8 ; F_9 ( L_44 ) ; break;
default:
F_18 ( & V_7 -> V_22 , L_45 ) ;
}
}
V_11 -> V_223 = V_12 ;
if ( F_10 ( V_22 , F_11 ( V_22 , 0 ) ,
V_225 ,
V_226 ,
V_12 , V_11 -> V_25 ,
NULL , 0 , V_70 ) < 0 ) {
F_18 ( & V_7 -> V_22 , L_46
L_47 , V_16 ) ;
}
V_247:
if ( ( V_229 & V_235 ) == V_236 ) {
if ( F_10 ( V_22 , F_11 ( V_22 , 0 ) ,
V_172 ,
V_173 ,
0 , V_11 -> V_25 ,
NULL , 0 , V_26 ) < 0 ) {
F_18 ( & V_7 -> V_22 ,
L_48 ,
V_16 ) ;
}
F_72 ( V_7 , V_14 | V_15 ) ;
} else {
F_27 ( & V_11 -> V_90 ) ;
if ( F_16 ( V_29 , V_7 ) )
F_18 ( & V_7 -> V_22 , L_49 ,
V_16 ) ;
F_29 ( & V_11 -> V_90 ) ;
if ( ! V_227 || ( V_227 -> V_230 & V_235 ) == V_236 )
F_71 ( V_7 , V_14 | V_15 ) ;
}
V_241:
if ( V_229 & V_237 ) {
F_9 ( L_50 , V_16 ) ;
if ( F_10 ( V_22 ,
F_11 ( V_22 , 0 ) ,
V_172 ,
V_173 ,
0 , ( V_257 | V_11 -> V_25 ) ,
NULL , 0 , V_26 ) < 0 ) {
F_18 ( & V_7 -> V_22 ,
L_51 ) ;
}
} else {
if ( V_231 & V_258 ) {
F_9 ( L_52 ,
V_16 , V_231 ) ;
V_234 = V_228 -> V_259 [ V_260 ] ;
V_233 = V_228 -> V_259 [ V_261 ] ;
V_12 = ( V_233 << 8 ) | ( V_234 ) ;
if ( F_10 ( V_22 ,
F_11 ( V_22 , 0 ) ,
V_172 ,
V_173 ,
V_12 , ( V_262
| V_11 -> V_25 ) ,
NULL , 0 , V_26 ) < 0 ) {
F_18 ( & V_7 -> V_22 , L_53
L_54 ) ;
}
} else {
F_9 ( L_55 , V_16 ) ;
if ( F_10 ( V_22 ,
F_11 ( V_22 , 0 ) ,
V_172 ,
V_173 ,
0 , V_11 -> V_25 ,
NULL , 0 , V_26 ) < 0 ) {
F_18 ( & V_7 -> V_22 ,
L_56 ) ;
}
}
}
}
static int F_91 ( struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_222 ;
struct V_10 * V_11 = F_8 ( V_7 ) ;
unsigned char * V_78 ;
int V_177 ;
int V_147 ;
F_9 ( L_57 , V_16 ) ;
V_78 = F_20 ( 2 , V_79 ) ;
if ( ! V_78 )
return - V_80 ;
switch ( V_11 -> V_37 ) {
case V_38 :
V_177 = 1 ;
break;
case V_49 :
case V_50 :
case V_51 :
case V_52 :
case V_62 :
case V_63 :
case V_64 :
case V_53 :
V_177 = 2 ;
break;
default:
V_147 = - V_86 ;
goto V_263;
}
V_147 = F_10 ( V_7 -> V_21 -> V_22 ,
F_21 ( V_7 -> V_21 -> V_22 , 0 ) ,
V_264 ,
V_265 ,
0 , V_11 -> V_25 ,
V_78 , V_177 , V_26 ) ;
if ( V_147 < 0 )
goto V_263;
V_147 = ( V_78 [ 0 ] & V_266 ? V_267 : 0 ) |
( V_78 [ 0 ] & V_268 ? V_269 : 0 ) |
( V_78 [ 0 ] & V_270 ? V_271 : 0 ) |
( V_78 [ 0 ] & V_272 ? V_273 : 0 ) |
V_11 -> V_27 ;
V_263:
F_22 ( V_78 ) ;
return V_147 ;
}
static int F_92 ( struct V_28 * V_29 ,
unsigned int V_8 , unsigned int V_9 )
{
struct V_6 * V_7 = V_29 -> V_222 ;
F_9 ( L_58 , V_16 ) ;
return F_7 ( V_7 , V_8 , V_9 ) ;
}
static int F_93 ( struct V_28 * V_29 ,
struct V_274 * V_149 )
{
struct V_6 * V_7 = V_29 -> V_222 ;
struct V_10 * V_11 = F_8 ( V_7 ) ;
struct V_275 * V_276 = & V_11 -> V_149 ;
V_149 -> V_191 = V_276 -> V_191 ;
V_149 -> V_193 = V_276 -> V_193 ;
V_149 -> V_195 = V_276 -> V_195 ;
V_149 -> V_197 = V_276 -> V_197 ;
V_149 -> V_181 = V_276 -> V_181 ;
V_149 -> V_213 = V_276 -> V_213 ;
V_149 -> V_208 = V_276 -> V_208 ;
V_149 -> V_205 = V_276 -> V_205 ;
V_149 -> V_210 = V_276 -> V_210 ;
V_149 -> V_202 = V_276 -> V_202 ;
V_149 -> V_277 = V_276 -> V_277 ;
return 0 ;
}
static int F_94 ( struct V_28 * V_29 ,
unsigned int V_278 , unsigned long V_279 )
{
struct V_6 * V_7 = V_29 -> V_222 ;
struct V_10 * V_11 = F_8 ( V_7 ) ;
struct V_275 V_280 ;
struct V_275 V_281 ;
F_9 ( L_59 , V_16 , V_278 ) ;
switch ( V_278 ) {
case V_282 :
return F_23 ( V_7 ,
(struct V_83 T_3 * ) V_279 ) ;
case V_283 :
return F_25 ( V_29 , V_7 ,
(struct V_83 T_3 * ) V_279 ) ;
case V_284 :
V_281 = V_11 -> V_149 ;
while ( ! V_11 -> V_151 ) {
F_95 ( & V_11 -> V_150 ) ;
if ( F_96 ( V_285 ) )
return - V_286 ;
V_280 = V_11 -> V_149 ;
if ( ( ( V_279 & V_287 ) && ( V_280 . V_195 != V_281 . V_195 ) ) ||
( ( V_279 & V_267 ) && ( V_280 . V_193 != V_281 . V_193 ) ) ||
( ( V_279 & V_273 ) && ( V_280 . V_197 != V_281 . V_197 ) ) ||
( ( V_279 & V_269 ) && ( V_280 . V_191 != V_281 . V_191 ) ) ) {
return 0 ;
}
V_281 = V_280 ;
}
return - V_135 ;
break;
case V_288 :
return F_30 ( V_7 , (struct V_83 T_3 * ) V_279 ) ;
break;
default:
break;
}
F_9 ( L_60 , V_16 , V_278 ) ;
return - V_289 ;
}
static int T_6 F_97 ( void )
{
int V_138 ;
F_9 ( L_14 , V_16 ) ;
if ( V_290 > 0 && V_158 > 0 ) {
int V_125 ;
for ( V_125 = 0 ; V_291 [ V_125 ] . V_292 ; V_125 ++ )
;
V_291 [ V_125 ] . V_293 = V_294 ;
V_291 [ V_125 ] . V_292 = V_290 ;
V_291 [ V_125 ] . V_56 = V_158 ;
}
V_138 = F_98 ( & V_295 , V_296 ) ;
if ( V_138 == 0 )
F_99 (KERN_INFO KBUILD_MODNAME L_61 DRIVER_VERSION L_62
DRIVER_DESC L_63 ) ;
return V_138 ;
}
static void T_7 F_100 ( void )
{
F_9 ( L_14 , V_16 ) ;
F_101 ( & V_295 , V_296 ) ;
}
