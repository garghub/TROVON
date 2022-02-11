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
if ( V_1 <= 3000000 ) {
T_2 V_53 = F_14 (
V_7 -> V_21 -> V_22 -> V_54 . V_55 ) ;
if ( ( ( V_56 == V_53 ) ||
( V_57 == V_53 ) ||
( V_58 == V_53 ) ||
( V_59 == V_53 ) ||
( V_60 == V_53 ) ) &&
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
case V_61 :
case V_62 :
case V_63 :
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
V_64 [ V_11 -> V_37 ] ) ;
}
F_15 ( V_29 , V_1 , V_1 ) ;
return V_30 ;
}
static int F_16 ( struct V_28 * V_29 , struct V_6 * V_7 )
{
struct V_10 * V_11 = F_8 ( V_7 ) ;
T_2 V_12 ;
T_2 V_65 ;
T_1 V_66 ;
int V_13 ;
V_66 = F_12 ( V_29 , V_7 ) ;
V_12 = ( T_2 ) V_66 ;
V_65 = ( T_2 ) ( V_66 >> 16 ) ;
if ( ( V_11 -> V_37 == V_51 ) || ( V_11 -> V_37 == V_61 ) ||
( V_11 -> V_37 == V_62 ) || ( V_11 -> V_37 == V_63 ) ) {
V_65 = ( T_2 ) ( ( V_65 << 8 ) | V_11 -> V_25 ) ;
}
V_13 = F_10 ( V_7 -> V_21 -> V_22 ,
F_11 ( V_7 -> V_21 -> V_22 , 0 ) ,
V_67 ,
V_68 ,
V_12 , V_65 ,
NULL , 0 , V_69 ) ;
return V_13 ;
}
static int F_17 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = F_8 ( V_7 ) ;
struct V_70 * V_71 = V_7 -> V_21 -> V_22 ;
int V_13 ;
int V_72 = V_11 -> V_73 ;
if ( V_11 -> V_32 & V_74 )
V_72 = 1 ;
F_9 ( L_12 , V_16 , V_72 ) ;
V_13 = F_10 ( V_71 ,
F_11 ( V_71 , 0 ) ,
V_75 ,
V_76 ,
V_72 , V_11 -> V_25 ,
NULL , 0 , V_26 ) ;
if ( V_13 < 0 )
F_18 ( & V_7 -> V_22 , L_13 , V_13 ) ;
return V_13 ;
}
static int F_19 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = F_8 ( V_7 ) ;
struct V_70 * V_71 = V_7 -> V_21 -> V_22 ;
unsigned char * V_77 ;
int V_13 ;
F_9 ( L_14 , V_16 ) ;
V_77 = F_20 ( 1 , V_78 ) ;
if ( ! V_77 )
return - V_79 ;
V_13 = F_10 ( V_71 ,
F_21 ( V_71 , 0 ) ,
V_80 ,
V_81 ,
0 , V_11 -> V_25 ,
V_77 , 1 , V_26 ) ;
if ( V_13 < 0 )
F_18 ( & V_7 -> V_22 , L_15 , V_13 ) ;
else
V_11 -> V_73 = V_77 [ 0 ] ;
F_22 ( V_77 ) ;
return V_13 ;
}
static int F_23 ( struct V_6 * V_7 ,
struct V_82 T_3 * V_83 )
{
struct V_10 * V_11 = F_8 ( V_7 ) ;
struct V_82 V_84 ;
if ( ! V_83 )
return - V_85 ;
memset ( & V_84 , 0 , sizeof( V_84 ) ) ;
V_84 . V_32 = V_11 -> V_32 ;
V_84 . V_36 = V_11 -> V_36 ;
V_84 . V_35 = V_11 -> V_35 ;
if ( F_24 ( V_83 , & V_84 , sizeof( * V_83 ) ) )
return - V_85 ;
return 0 ;
}
static int F_25 ( struct V_28 * V_29 ,
struct V_6 * V_7 , struct V_82 T_3 * V_86 )
{
struct V_10 * V_11 = F_8 ( V_7 ) ;
struct V_82 V_87 ;
struct V_10 V_88 ;
if ( F_26 ( & V_87 , V_86 , sizeof( V_87 ) ) )
return - V_85 ;
F_27 ( & V_11 -> V_89 ) ;
V_88 = * V_11 ;
if ( ! F_28 ( V_90 ) ) {
if ( ( ( V_87 . V_32 & ~ V_91 ) !=
( V_11 -> V_32 & ~ V_91 ) ) ) {
F_29 ( & V_11 -> V_89 ) ;
return - V_92 ;
}
V_11 -> V_32 = ( ( V_11 -> V_32 & ~ V_91 ) |
( V_87 . V_32 & V_91 ) ) ;
V_11 -> V_35 = V_87 . V_35 ;
goto V_93;
}
if ( ( V_87 . V_36 != V_11 -> V_36 ) &&
( V_87 . V_36 < 9600 ) ) {
F_29 ( & V_11 -> V_89 ) ;
return - V_94 ;
}
V_11 -> V_32 = ( ( V_11 -> V_32 & ~ V_95 ) |
( V_87 . V_32 & V_95 ) ) ;
V_11 -> V_35 = V_87 . V_35 ;
F_17 ( V_7 ) ;
V_93:
if ( ( V_88 . V_32 & V_33 ) !=
( V_11 -> V_32 & V_33 ) ) {
if ( ( V_11 -> V_32 & V_33 ) == V_96 )
V_29 -> V_97 = 57600 ;
else if ( ( V_11 -> V_32 & V_33 ) == V_98 )
V_29 -> V_97 = 115200 ;
else if ( ( V_11 -> V_32 & V_33 ) == V_99 )
V_29 -> V_97 = 230400 ;
else if ( ( V_11 -> V_32 & V_33 ) == V_100 )
V_29 -> V_97 = 460800 ;
else
V_29 -> V_97 = 0 ;
}
if ( ( ( V_88 . V_32 & V_33 ) !=
( V_11 -> V_32 & V_33 ) ) ||
( ( ( V_11 -> V_32 & V_33 ) == V_34 ) &&
( V_88 . V_35 != V_11 -> V_35 ) ) ) {
F_16 ( V_29 , V_7 ) ;
F_29 ( & V_11 -> V_89 ) ;
}
else
F_29 ( & V_11 -> V_89 ) ;
return 0 ;
}
static int F_30 ( struct V_6 * V_7 ,
struct V_82 T_3 * V_83 )
{
struct V_10 * V_11 = F_8 ( V_7 ) ;
unsigned int V_101 = 0 ;
if ( ! V_83 )
return - V_85 ;
if ( V_11 -> V_102 )
V_101 = V_103 ;
if ( F_24 ( V_83 , & V_101 , sizeof( unsigned int ) ) )
return - V_85 ;
return 0 ;
}
static void F_31 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = F_8 ( V_7 ) ;
struct V_104 * V_21 = V_7 -> V_21 ;
struct V_70 * V_71 = V_21 -> V_22 ;
unsigned V_105 ;
unsigned V_106 ;
V_11 -> V_36 = 48000000 / 2 ;
V_105 = F_14 ( V_71 -> V_54 . V_107 ) ;
V_106 = V_71 -> V_108 -> V_109 . V_110 ;
F_9 ( L_16 , V_16 ,
V_105 , V_106 ) ;
if ( V_106 > 1 ) {
int V_111 ;
if ( V_105 == 0x0800 ) {
V_11 -> V_37 = V_62 ;
V_11 -> V_36 = 120000000 / 2 ;
} else if ( V_105 == 0x0700 ) {
V_11 -> V_37 = V_61 ;
V_11 -> V_36 = 120000000 / 2 ;
} else
V_11 -> V_37 = V_51 ;
V_111 = V_21 -> V_25 -> V_112 -> V_109 . V_113 ;
if ( V_111 == 0 ) {
V_11 -> V_25 = V_114 ;
} else if ( V_111 == 1 ) {
V_11 -> V_25 = V_115 ;
} else if ( V_111 == 2 ) {
V_11 -> V_25 = V_116 ;
} else if ( V_111 == 3 ) {
V_11 -> V_25 = V_117 ;
}
if ( V_105 < 0x500 ) {
F_9 ( L_17 ,
V_16 ) ;
}
} else if ( V_105 < 0x200 ) {
V_11 -> V_37 = V_38 ;
V_11 -> V_36 = 12000000 / 16 ;
} else if ( V_105 < 0x400 ) {
V_11 -> V_37 = V_49 ;
} else if ( V_105 < 0x600 ) {
V_11 -> V_37 = V_50 ;
} else if ( V_105 < 0x900 ) {
V_11 -> V_37 = V_52 ;
} else {
V_11 -> V_37 = V_63 ;
}
F_32 ( & V_71 -> V_22 , L_18 , V_64 [ V_11 -> V_37 ] ) ;
}
static void F_33 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = F_8 ( V_7 ) ;
struct V_104 * V_21 = V_7 -> V_21 ;
struct V_70 * V_71 = V_21 -> V_22 ;
struct V_118 * V_25 = V_21 -> V_25 ;
struct V_119 * V_120 = & V_25 -> V_121 -> V_122 [ 1 ] . V_109 ;
unsigned V_123 ;
int V_124 ;
V_123 = V_25 -> V_121 -> V_109 . V_125 ;
F_32 ( & V_71 -> V_22 , L_19 , V_123 ) ;
for ( V_124 = 0 ; V_124 < V_123 ; V_124 ++ ) {
F_32 ( & V_71 -> V_22 , L_20 , V_124 + 1 ,
V_25 -> V_121 -> V_122 [ V_124 ] . V_109 . V_126 ) ;
V_120 = & V_25 -> V_121 -> V_122 [ V_124 ] . V_109 ;
if ( V_120 -> V_126 == 0 ) {
V_120 -> V_126 = F_34 ( 0x40 ) ;
F_32 ( & V_71 -> V_22 , L_21 , V_124 ) ;
}
}
V_11 -> V_127 = F_35 ( V_120 ) ;
F_32 ( & V_71 -> V_22 , L_22 , V_11 -> V_127 ) ;
}
static T_4 F_36 ( struct V_128 * V_22 ,
struct V_129 * V_130 , char * V_77 )
{
struct V_6 * V_7 = F_37 ( V_22 ) ;
struct V_10 * V_11 = F_8 ( V_7 ) ;
if ( V_11 -> V_32 & V_74 )
return sprintf ( V_77 , L_23 ) ;
else
return sprintf ( V_77 , L_24 , V_11 -> V_73 ) ;
}
static T_4 F_38 ( struct V_128 * V_22 ,
struct V_129 * V_130 , const char * V_131 ,
T_5 V_132 )
{
struct V_6 * V_7 = F_37 ( V_22 ) ;
struct V_10 * V_11 = F_8 ( V_7 ) ;
int V_133 = F_39 ( V_131 , NULL , 10 ) ;
int V_13 ;
V_11 -> V_73 = V_133 ;
V_13 = F_17 ( V_7 ) ;
if ( V_13 < 0 )
return - V_134 ;
return V_132 ;
}
static T_4 F_40 ( struct V_128 * V_22 ,
struct V_129 * V_130 , const char * V_131 , T_5 V_132 )
{
struct V_6 * V_7 = F_37 ( V_22 ) ;
struct V_10 * V_11 = F_8 ( V_7 ) ;
struct V_70 * V_71 = V_7 -> V_21 -> V_22 ;
int V_133 = F_39 ( V_131 , NULL , 10 ) ;
int V_13 ;
F_9 ( L_25 , V_16 , V_133 ) ;
V_13 = F_10 ( V_71 ,
F_11 ( V_71 , 0 ) ,
V_135 ,
V_136 ,
V_133 , V_11 -> V_25 ,
NULL , 0 , V_26 ) ;
if ( V_13 < 0 ) {
F_9 ( L_26 , V_13 ) ;
return - V_134 ;
}
return V_132 ;
}
static int F_41 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = F_8 ( V_7 ) ;
int V_137 = 0 ;
F_9 ( L_14 , V_16 ) ;
if ( V_11 -> V_37 != V_38 ) {
F_9 ( L_27 , V_64 [ V_11 -> V_37 ] ) ;
V_137 = F_42 ( & V_7 -> V_22 , & V_138 ) ;
if ( ( ! V_137 ) &&
( V_11 -> V_37 == V_50 ||
V_11 -> V_37 == V_51 ||
V_11 -> V_37 == V_52 ||
V_11 -> V_37 == V_61 ||
V_11 -> V_37 == V_62 ||
V_11 -> V_37 == V_63 ) ) {
V_137 = F_42 ( & V_7 -> V_22 ,
& V_139 ) ;
}
}
return V_137 ;
}
static void F_43 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = F_8 ( V_7 ) ;
F_9 ( L_14 , V_16 ) ;
if ( V_11 -> V_37 != V_38 ) {
F_44 ( & V_7 -> V_22 , & V_138 ) ;
if ( V_11 -> V_37 == V_50 ||
V_11 -> V_37 == V_51 ||
V_11 -> V_37 == V_52 ||
V_11 -> V_37 == V_61 ||
V_11 -> V_37 == V_62 ||
V_11 -> V_37 == V_63 ) {
F_44 ( & V_7 -> V_22 , & V_139 ) ;
}
}
}
static int F_45 ( struct V_104 * V_21 ,
const struct V_140 * V_141 )
{
struct V_142 * V_143 =
(struct V_142 * ) V_141 -> V_144 ;
if ( V_143 && V_143 -> V_145 ) {
int V_146 = V_143 -> V_145 ( V_21 ) ;
if ( V_146 != 0 )
return V_146 ;
}
F_46 ( V_21 , ( void * ) V_141 -> V_144 ) ;
return 0 ;
}
static int F_47 ( struct V_6 * V_7 )
{
struct V_10 * V_11 ;
struct V_142 * V_143 = F_48 ( V_7 -> V_21 ) ;
F_9 ( L_14 , V_16 ) ;
V_11 = F_49 ( sizeof( struct V_10 ) , V_78 ) ;
if ( ! V_11 ) {
F_18 ( & V_7 -> V_22 , L_28 , V_16 ,
sizeof( struct V_10 ) ) ;
return - V_79 ;
}
F_50 ( & V_11 -> V_147 ) ;
F_51 ( & V_11 -> V_89 ) ;
memset ( & V_11 -> V_148 , 0x00 , sizeof( V_11 -> V_148 ) ) ;
F_52 ( & V_11 -> V_149 ) ;
V_11 -> V_32 = V_74 ;
if ( V_143 && V_143 -> V_150 )
V_143 -> V_150 ( V_11 ) ;
V_11 -> V_7 = V_7 ;
F_53 ( V_7 , V_11 ) ;
F_31 ( V_7 ) ;
F_33 ( V_7 ) ;
if ( F_19 ( V_7 ) < 0 )
V_11 -> V_73 = 16 ;
F_17 ( V_7 ) ;
F_41 ( V_7 ) ;
return 0 ;
}
static void F_54 ( struct V_10 * V_11 )
{
F_9 ( L_14 , V_16 ) ;
V_11 -> V_32 |= V_34 ;
V_11 -> V_35 = 77 ;
V_11 -> V_151 = 38400 ;
}
static void F_55 ( struct V_10 * V_11 )
{
F_9 ( L_14 , V_16 ) ;
V_11 -> V_32 |= V_34 ;
V_11 -> V_35 = 240 ;
V_11 -> V_151 = 38400 ;
V_11 -> V_152 = 1 ;
}
static int F_56 ( struct V_104 * V_21 )
{
struct V_70 * V_71 = V_21 -> V_22 ;
int V_73 = V_153 ;
if ( V_73 == 0 )
V_73 = 1 ;
if ( V_73 > 99 )
V_73 = 99 ;
F_9 ( L_29 , V_16 , V_73 ) ;
F_32 ( & V_71 -> V_22 , L_30 , V_73 ) ;
F_10 ( V_71 , F_11 ( V_71 , 0 ) ,
V_75 ,
V_76 ,
V_73 , 0 , NULL , 0 , V_26 ) ;
return 0 ;
}
static int F_57 ( struct V_104 * V_21 )
{
struct V_70 * V_71 = V_21 -> V_22 ;
struct V_118 * V_25 = V_21 -> V_25 ;
F_9 ( L_14 , V_16 ) ;
if ( V_25 == V_71 -> V_108 -> V_25 [ 0 ] ) {
F_32 ( & V_71 -> V_22 ,
L_31 ) ;
return - V_154 ;
}
return 0 ;
}
static int F_58 ( struct V_104 * V_21 )
{
struct V_70 * V_71 = V_21 -> V_22 ;
F_9 ( L_14 , V_16 ) ;
if ( strcmp ( V_71 -> V_155 , L_32 ) == 0 )
return F_57 ( V_21 ) ;
return 0 ;
}
static int F_59 ( struct V_104 * V_21 )
{
struct V_70 * V_71 = V_21 -> V_22 ;
struct V_118 * V_25 = V_21 -> V_25 ;
F_9 ( L_14 , V_16 ) ;
if ( V_25 == V_71 -> V_108 -> V_25 [ 2 ] )
return 0 ;
F_32 ( & V_71 -> V_22 , L_31 ) ;
return - V_154 ;
}
static int F_60 ( struct V_104 * V_21 )
{
struct V_156 * V_157 = V_21 -> V_22 -> V_158 [ 1 ] ;
struct V_119 * V_120 = & V_157 -> V_109 ;
if ( V_157 -> V_159 && V_120 -> V_126 == 0 ) {
V_120 -> V_126 = F_34 ( 0x40 ) ;
F_32 ( & V_21 -> V_22 -> V_22 ,
L_33 ) ;
}
return 0 ;
}
static void F_61 ( struct V_147 * V_160 )
{
struct V_10 * V_11 = F_62 ( V_160 , struct V_10 , V_147 ) ;
F_22 ( V_11 ) ;
}
static int F_63 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = F_8 ( V_7 ) ;
F_9 ( L_14 , V_16 ) ;
F_43 ( V_7 ) ;
F_64 ( & V_11 -> V_147 , F_61 ) ;
return 0 ;
}
static int F_65 ( struct V_28 * V_29 , struct V_6 * V_7 )
{
struct V_70 * V_22 = V_7 -> V_21 -> V_22 ;
struct V_10 * V_11 = F_8 ( V_7 ) ;
int V_101 ;
F_9 ( L_14 , V_16 ) ;
F_10 ( V_22 , F_11 ( V_22 , 0 ) ,
V_161 , V_162 ,
V_163 ,
V_11 -> V_25 , NULL , 0 , V_26 ) ;
if ( V_29 )
F_66 ( V_29 , V_7 , V_29 -> V_164 ) ;
V_101 = F_67 ( V_29 , V_7 ) ;
if ( ! V_101 )
F_68 ( & V_11 -> V_147 ) ;
return V_101 ;
}
static void F_69 ( struct V_6 * V_7 , int V_165 )
{
struct V_10 * V_11 = F_8 ( V_7 ) ;
F_27 ( & V_7 -> V_21 -> V_166 ) ;
if ( ! V_7 -> V_21 -> V_167 ) {
if ( ! V_165 && F_10 ( V_7 -> V_21 -> V_22 ,
F_11 ( V_7 -> V_21 -> V_22 , 0 ) ,
V_168 ,
V_169 ,
0 , V_11 -> V_25 , NULL , 0 ,
V_26 ) < 0 ) {
F_18 ( & V_7 -> V_22 , L_34 ) ;
}
if ( V_165 )
F_70 ( V_7 , V_14 | V_15 ) ;
else
F_71 ( V_7 , V_14 | V_15 ) ;
}
F_29 ( & V_7 -> V_21 -> V_166 ) ;
}
static void F_72 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = F_8 ( V_7 ) ;
F_9 ( L_14 , V_16 ) ;
F_73 ( V_7 ) ;
F_64 ( & V_11 -> V_147 , F_61 ) ;
}
static int F_74 ( struct V_6 * V_7 ,
void * V_170 , T_5 V_171 )
{
struct V_10 * V_11 ;
int V_132 ;
unsigned long V_32 ;
V_11 = F_8 ( V_7 ) ;
if ( V_11 -> V_37 == V_38 ) {
unsigned char * V_172 = V_170 ;
int V_124 , V_173 , V_174 ;
V_132 = 0 ;
F_75 ( & V_7 -> V_175 , V_32 ) ;
for ( V_124 = 0 ; V_124 < V_171 - 1 ; V_124 += V_11 -> V_127 ) {
V_173 = F_76 ( int , V_171 - V_124 , V_11 -> V_127 ) - 1 ;
V_174 = F_77 ( & V_7 -> V_176 , & V_172 [ V_124 + 1 ] , V_173 ) ;
if ( ! V_174 )
break;
V_11 -> V_148 . V_177 += V_174 ;
V_172 [ V_124 ] = ( V_174 << 2 ) + 1 ;
V_132 += V_174 + 1 ;
}
F_78 ( & V_7 -> V_175 , V_32 ) ;
} else {
V_132 = F_79 ( & V_7 -> V_176 , V_170 , V_171 ,
& V_7 -> V_175 ) ;
V_11 -> V_148 . V_177 += V_132 ;
}
return V_132 ;
}
static int F_80 ( struct V_28 * V_29 ,
struct V_6 * V_7 , struct V_10 * V_11 ,
char * V_178 , int V_173 )
{
int V_124 ;
char V_179 ;
char V_180 ;
char * V_181 ;
F_9 ( L_35 , V_16 , V_7 -> V_182 ) ;
if ( V_173 < 2 ) {
F_9 ( L_36 ) ;
return 0 ;
}
V_179 = V_178 [ 0 ] & V_183 ;
if ( V_179 & V_184 )
V_11 -> V_148 . V_185 ++ ;
if ( V_179 & V_186 )
V_11 -> V_148 . V_187 ++ ;
if ( V_179 & V_188 )
V_11 -> V_148 . V_189 ++ ;
if ( V_179 & V_190 )
V_11 -> V_148 . V_191 ++ ;
if ( V_179 != V_11 -> V_192 ) {
V_11 -> V_193 |= V_179 ^ V_11 -> V_192 ;
F_81 ( & V_11 -> V_149 ) ;
V_11 -> V_192 = V_179 ;
}
V_180 = V_194 ;
if ( V_178 [ 1 ] & V_195 ) {
if ( V_178 [ 1 ] & V_196 ) {
V_180 = V_197 ;
V_11 -> V_148 . V_198 ++ ;
F_82 ( V_7 ) ;
} else if ( V_178 [ 1 ] & V_199 ) {
V_180 = V_200 ;
V_11 -> V_148 . V_201 ++ ;
} else if ( V_178 [ 1 ] & V_202 ) {
V_180 = V_203 ;
V_11 -> V_148 . V_204 ++ ;
}
if ( V_178 [ 1 ] & V_205 ) {
V_11 -> V_148 . V_206 ++ ;
F_83 ( V_29 , 0 , V_207 ) ;
}
}
if ( V_178 [ 1 ] & V_208 )
V_11 -> V_102 = 1 ;
else
V_11 -> V_102 = 0 ;
V_173 -= 2 ;
if ( ! V_173 )
return 0 ;
V_11 -> V_148 . V_209 += V_173 ;
V_181 = V_178 + 2 ;
if ( V_7 -> V_7 . V_210 && V_7 -> V_211 ) {
for ( V_124 = 0 ; V_124 < V_173 ; V_124 ++ , V_181 ++ ) {
if ( ! F_84 ( V_7 , * V_181 ) )
F_83 ( V_29 , * V_181 , V_180 ) ;
}
} else {
F_85 ( V_29 , V_181 , V_180 , V_173 ) ;
}
return V_173 ;
}
static void F_86 ( struct V_212 * V_212 )
{
struct V_6 * V_7 = V_212 -> V_213 ;
struct V_28 * V_29 ;
struct V_10 * V_11 = F_8 ( V_7 ) ;
char * V_214 = ( char * ) V_212 -> V_215 ;
int V_124 ;
int V_173 ;
int V_132 = 0 ;
V_29 = F_87 ( & V_7 -> V_7 ) ;
if ( ! V_29 )
return;
for ( V_124 = 0 ; V_124 < V_212 -> V_216 ; V_124 += V_11 -> V_127 ) {
V_173 = F_76 ( int , V_212 -> V_216 - V_124 , V_11 -> V_127 ) ;
V_132 += F_80 ( V_29 , V_7 , V_11 , & V_214 [ V_124 ] , V_173 ) ;
}
if ( V_132 )
F_88 ( V_29 ) ;
F_89 ( V_29 ) ;
}
static void F_90 ( struct V_28 * V_29 , int V_217 )
{
struct V_6 * V_7 = V_29 -> V_218 ;
struct V_10 * V_11 = F_8 ( V_7 ) ;
T_2 V_12 ;
if ( V_217 )
V_12 = V_11 -> V_219 | V_220 ;
else
V_12 = V_11 -> V_219 ;
if ( F_10 ( V_7 -> V_21 -> V_22 ,
F_11 ( V_7 -> V_21 -> V_22 , 0 ) ,
V_221 ,
V_222 ,
V_12 , V_11 -> V_25 ,
NULL , 0 , V_26 ) < 0 ) {
F_18 ( & V_7 -> V_22 , L_37
L_38 , V_16 , V_217 ) ;
}
F_9 ( L_39 , V_16 ,
V_217 , V_12 ) ;
}
static void F_66 ( struct V_28 * V_29 ,
struct V_6 * V_7 , struct V_223 * V_224 )
{
struct V_70 * V_22 = V_7 -> V_21 -> V_22 ;
struct V_10 * V_11 = F_8 ( V_7 ) ;
struct V_223 * V_164 = V_29 -> V_164 ;
unsigned int V_225 = V_164 -> V_226 ;
T_2 V_12 ;
unsigned int V_227 = V_164 -> V_228 ;
unsigned char V_229 ;
unsigned char V_230 ;
F_9 ( L_14 , V_16 ) ;
if ( V_11 -> V_151 && ( ( V_164 -> V_226 & V_231 ) != V_232 ) ) {
F_9 ( L_40 , V_16 ) ;
F_15 ( V_29 , V_11 -> V_151 ,
V_11 -> V_151 ) ;
}
if ( V_11 -> V_152 ) {
F_9 ( L_41 , V_16 ) ;
V_164 -> V_226 |= V_233 ;
}
V_225 = V_164 -> V_226 ;
if ( V_224 -> V_226 == V_164 -> V_226
&& V_224 -> V_234 == V_164 -> V_234
&& V_224 -> V_235 == V_164 -> V_235 )
goto V_236;
if ( ( V_224 -> V_226 & ( V_237 | V_238 | V_239 | V_240 | V_241 ) ) ==
( V_164 -> V_226 & ( V_237 | V_238 | V_239 | V_240 | V_241 ) ) )
goto V_242;
V_12 = 0 ;
V_12 |= ( V_225 & V_241 ? V_243 :
V_244 ) ;
if ( V_225 & V_239 ) {
if ( V_225 & V_240 )
V_12 |= V_225 & V_238 ?
V_245 :
V_246 ;
else
V_12 |= V_225 & V_238 ?
V_247 :
V_248 ;
} else {
V_12 |= V_249 ;
}
if ( V_225 & V_237 ) {
switch ( V_225 & V_237 ) {
case V_250 : V_12 |= 7 ; F_9 ( L_42 ) ; break;
case V_251 : V_12 |= 8 ; F_9 ( L_43 ) ; break;
default:
F_18 ( & V_7 -> V_22 , L_44 ) ;
}
}
V_11 -> V_219 = V_12 ;
if ( F_10 ( V_22 , F_11 ( V_22 , 0 ) ,
V_221 ,
V_222 ,
V_12 , V_11 -> V_25 ,
NULL , 0 , V_69 ) < 0 ) {
F_18 ( & V_7 -> V_22 , L_45
L_46 , V_16 ) ;
}
V_242:
if ( ( V_225 & V_231 ) == V_232 ) {
if ( F_10 ( V_22 , F_11 ( V_22 , 0 ) ,
V_168 ,
V_169 ,
0 , V_11 -> V_25 ,
NULL , 0 , V_26 ) < 0 ) {
F_18 ( & V_7 -> V_22 ,
L_47 ,
V_16 ) ;
}
F_71 ( V_7 , V_14 | V_15 ) ;
} else {
F_27 ( & V_11 -> V_89 ) ;
if ( F_16 ( V_29 , V_7 ) )
F_18 ( & V_7 -> V_22 , L_48 ,
V_16 ) ;
F_29 ( & V_11 -> V_89 ) ;
if ( ! V_224 || ( V_224 -> V_226 & V_231 ) == V_232 )
F_70 ( V_7 , V_14 | V_15 ) ;
}
V_236:
if ( V_225 & V_233 ) {
F_9 ( L_49 , V_16 ) ;
if ( F_10 ( V_22 ,
F_11 ( V_22 , 0 ) ,
V_168 ,
V_169 ,
0 , ( V_252 | V_11 -> V_25 ) ,
NULL , 0 , V_26 ) < 0 ) {
F_18 ( & V_7 -> V_22 ,
L_50 ) ;
}
} else {
if ( V_227 & V_253 ) {
F_9 ( L_51 ,
V_16 , V_227 ) ;
V_230 = V_164 -> V_254 [ V_255 ] ;
V_229 = V_164 -> V_254 [ V_256 ] ;
V_12 = ( V_229 << 8 ) | ( V_230 ) ;
if ( F_10 ( V_22 ,
F_11 ( V_22 , 0 ) ,
V_168 ,
V_169 ,
V_12 , ( V_257
| V_11 -> V_25 ) ,
NULL , 0 , V_26 ) < 0 ) {
F_18 ( & V_7 -> V_22 , L_52
L_53 ) ;
}
} else {
F_9 ( L_54 , V_16 ) ;
if ( F_10 ( V_22 ,
F_11 ( V_22 , 0 ) ,
V_168 ,
V_169 ,
0 , V_11 -> V_25 ,
NULL , 0 , V_26 ) < 0 ) {
F_18 ( & V_7 -> V_22 ,
L_55 ) ;
}
}
}
}
static int F_91 ( struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_218 ;
struct V_10 * V_11 = F_8 ( V_7 ) ;
unsigned char * V_77 ;
int V_173 ;
int V_146 ;
F_9 ( L_56 , V_16 ) ;
V_77 = F_20 ( 2 , V_78 ) ;
if ( ! V_77 )
return - V_79 ;
switch ( V_11 -> V_37 ) {
case V_38 :
V_173 = 1 ;
break;
case V_49 :
case V_50 :
case V_51 :
case V_52 :
case V_61 :
case V_62 :
case V_63 :
V_173 = 2 ;
break;
default:
V_146 = - V_85 ;
goto V_258;
}
V_146 = F_10 ( V_7 -> V_21 -> V_22 ,
F_21 ( V_7 -> V_21 -> V_22 , 0 ) ,
V_259 ,
V_260 ,
0 , V_11 -> V_25 ,
V_77 , V_173 , V_26 ) ;
if ( V_146 < 0 )
goto V_258;
V_146 = ( V_77 [ 0 ] & V_261 ? V_262 : 0 ) |
( V_77 [ 0 ] & V_263 ? V_264 : 0 ) |
( V_77 [ 0 ] & V_265 ? V_266 : 0 ) |
( V_77 [ 0 ] & V_267 ? V_268 : 0 ) |
V_11 -> V_27 ;
V_258:
F_22 ( V_77 ) ;
return V_146 ;
}
static int F_92 ( struct V_28 * V_29 ,
unsigned int V_8 , unsigned int V_9 )
{
struct V_6 * V_7 = V_29 -> V_218 ;
F_9 ( L_57 , V_16 ) ;
return F_7 ( V_7 , V_8 , V_9 ) ;
}
static int F_93 ( struct V_28 * V_29 ,
struct V_269 * V_148 )
{
struct V_6 * V_7 = V_29 -> V_218 ;
struct V_10 * V_11 = F_8 ( V_7 ) ;
struct V_270 * V_271 = & V_11 -> V_148 ;
V_148 -> V_185 = V_271 -> V_185 ;
V_148 -> V_187 = V_271 -> V_187 ;
V_148 -> V_189 = V_271 -> V_189 ;
V_148 -> V_191 = V_271 -> V_191 ;
V_148 -> V_177 = V_271 -> V_177 ;
V_148 -> V_209 = V_271 -> V_209 ;
V_148 -> V_204 = V_271 -> V_204 ;
V_148 -> V_201 = V_271 -> V_201 ;
V_148 -> V_206 = V_271 -> V_206 ;
V_148 -> V_198 = V_271 -> V_198 ;
V_148 -> V_272 = V_271 -> V_272 ;
return 0 ;
}
static int F_94 ( struct V_28 * V_29 ,
unsigned int V_273 , unsigned long V_274 )
{
struct V_6 * V_7 = V_29 -> V_218 ;
struct V_10 * V_11 = F_8 ( V_7 ) ;
struct V_270 V_275 ;
struct V_270 V_276 ;
F_9 ( L_58 , V_16 , V_273 ) ;
switch ( V_273 ) {
case V_277 :
return F_23 ( V_7 ,
(struct V_82 T_3 * ) V_274 ) ;
case V_278 :
return F_25 ( V_29 , V_7 ,
(struct V_82 T_3 * ) V_274 ) ;
case V_279 :
V_276 = V_11 -> V_148 ;
while ( 1 ) {
F_95 ( & V_11 -> V_149 ) ;
if ( F_96 ( V_280 ) )
return - V_281 ;
V_275 = V_11 -> V_148 ;
if ( V_275 . V_189 == V_276 . V_189 && V_275 . V_187 == V_276 . V_187 &&
V_275 . V_191 == V_276 . V_191 && V_275 . V_185 == V_276 . V_185 )
return - V_134 ;
if ( ( ( V_274 & V_282 ) && ( V_275 . V_189 != V_276 . V_189 ) ) ||
( ( V_274 & V_262 ) && ( V_275 . V_187 != V_276 . V_187 ) ) ||
( ( V_274 & V_268 ) && ( V_275 . V_191 != V_276 . V_191 ) ) ||
( ( V_274 & V_264 ) && ( V_275 . V_185 != V_276 . V_185 ) ) ) {
return 0 ;
}
V_276 = V_275 ;
}
break;
case V_283 :
return F_30 ( V_7 , (struct V_82 T_3 * ) V_274 ) ;
break;
default:
break;
}
F_9 ( L_59 , V_16 , V_273 ) ;
return - V_284 ;
}
static int T_6 F_97 ( void )
{
int V_137 ;
F_9 ( L_14 , V_16 ) ;
if ( V_285 > 0 && V_286 > 0 ) {
int V_124 ;
for ( V_124 = 0 ; V_287 [ V_124 ] . V_288 ; V_124 ++ )
;
V_287 [ V_124 ] . V_289 = V_290 ;
V_287 [ V_124 ] . V_288 = V_285 ;
V_287 [ V_124 ] . V_55 = V_286 ;
}
V_137 = F_98 ( & V_291 ) ;
if ( V_137 )
goto V_292;
V_137 = F_99 ( & V_293 ) ;
if ( V_137 )
goto V_294;
F_100 (KERN_INFO KBUILD_MODNAME L_60 DRIVER_VERSION L_61
DRIVER_DESC L_62 ) ;
return 0 ;
V_294:
F_101 ( & V_291 ) ;
V_292:
return V_137 ;
}
static void T_7 F_102 ( void )
{
F_9 ( L_14 , V_16 ) ;
F_103 ( & V_293 ) ;
F_101 ( & V_291 ) ;
}
