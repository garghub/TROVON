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
if ( ( V_1 <= 12000000 ) & ( V_1 >= 1200 ) ) {
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
if ( V_11 -> V_25 ) {
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
V_11 -> V_127 = F_14 ( V_120 -> V_126 ) ;
F_32 ( & V_71 -> V_22 , L_22 , V_11 -> V_127 ) ;
}
static T_4 F_35 ( struct V_128 * V_22 ,
struct V_129 * V_130 , char * V_77 )
{
struct V_6 * V_7 = F_36 ( V_22 ) ;
struct V_10 * V_11 = F_8 ( V_7 ) ;
if ( V_11 -> V_32 & V_74 )
return sprintf ( V_77 , L_23 ) ;
else
return sprintf ( V_77 , L_24 , V_11 -> V_73 ) ;
}
static T_4 F_37 ( struct V_128 * V_22 ,
struct V_129 * V_130 , const char * V_131 ,
T_5 V_132 )
{
struct V_6 * V_7 = F_36 ( V_22 ) ;
struct V_10 * V_11 = F_8 ( V_7 ) ;
int V_133 = F_38 ( V_131 , NULL , 10 ) ;
int V_13 ;
V_11 -> V_73 = V_133 ;
V_13 = F_17 ( V_7 ) ;
if ( V_13 < 0 )
return - V_134 ;
return V_132 ;
}
static T_4 F_39 ( struct V_128 * V_22 ,
struct V_129 * V_130 , const char * V_131 , T_5 V_132 )
{
struct V_6 * V_7 = F_36 ( V_22 ) ;
struct V_10 * V_11 = F_8 ( V_7 ) ;
struct V_70 * V_71 = V_7 -> V_21 -> V_22 ;
int V_133 = F_38 ( V_131 , NULL , 10 ) ;
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
static int F_40 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = F_8 ( V_7 ) ;
int V_137 = 0 ;
F_9 ( L_14 , V_16 ) ;
if ( V_11 -> V_37 != V_38 ) {
F_9 ( L_27 , V_64 [ V_11 -> V_37 ] ) ;
V_137 = F_41 ( & V_7 -> V_22 , & V_138 ) ;
if ( ( ! V_137 ) &&
( V_11 -> V_37 == V_50 ||
V_11 -> V_37 == V_51 ||
V_11 -> V_37 == V_52 ||
V_11 -> V_37 == V_61 ||
V_11 -> V_37 == V_62 ||
V_11 -> V_37 == V_63 ) ) {
V_137 = F_41 ( & V_7 -> V_22 ,
& V_139 ) ;
}
}
return V_137 ;
}
static void F_42 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = F_8 ( V_7 ) ;
F_9 ( L_14 , V_16 ) ;
if ( V_11 -> V_37 != V_38 ) {
F_43 ( & V_7 -> V_22 , & V_138 ) ;
if ( V_11 -> V_37 == V_50 ||
V_11 -> V_37 == V_51 ||
V_11 -> V_37 == V_52 ||
V_11 -> V_37 == V_61 ||
V_11 -> V_37 == V_62 ||
V_11 -> V_37 == V_63 ) {
F_43 ( & V_7 -> V_22 , & V_139 ) ;
}
}
}
static int F_44 ( struct V_104 * V_21 ,
const struct V_140 * V_141 )
{
struct V_142 * V_143 =
(struct V_142 * ) V_141 -> V_144 ;
if ( V_143 && V_143 -> V_145 ) {
int V_146 = V_143 -> V_145 ( V_21 ) ;
if ( V_146 != 0 )
return V_146 ;
}
F_45 ( V_21 , ( void * ) V_141 -> V_144 ) ;
return 0 ;
}
static int F_46 ( struct V_6 * V_7 )
{
struct V_10 * V_11 ;
struct V_142 * V_143 = F_47 ( V_7 -> V_21 ) ;
F_9 ( L_14 , V_16 ) ;
V_11 = F_48 ( sizeof( struct V_10 ) , V_78 ) ;
if ( ! V_11 ) {
F_18 ( & V_7 -> V_22 , L_28 , V_16 ,
sizeof( struct V_10 ) ) ;
return - V_79 ;
}
F_49 ( & V_11 -> V_147 ) ;
F_50 ( & V_11 -> V_89 ) ;
F_51 ( & V_11 -> V_148 ) ;
V_11 -> V_32 = V_74 ;
if ( V_143 && V_143 -> V_149 )
V_143 -> V_149 ( V_11 ) ;
V_11 -> V_7 = V_7 ;
F_52 ( V_7 , V_11 ) ;
F_31 ( V_7 ) ;
F_33 ( V_7 ) ;
if ( F_19 ( V_7 ) < 0 )
V_11 -> V_73 = 16 ;
F_17 ( V_7 ) ;
F_40 ( V_7 ) ;
return 0 ;
}
static void F_53 ( struct V_10 * V_11 )
{
F_9 ( L_14 , V_16 ) ;
V_11 -> V_32 |= V_34 ;
V_11 -> V_35 = 77 ;
V_11 -> V_150 = 38400 ;
}
static void F_54 ( struct V_10 * V_11 )
{
F_9 ( L_14 , V_16 ) ;
V_11 -> V_32 |= V_34 ;
V_11 -> V_35 = 240 ;
V_11 -> V_150 = 38400 ;
V_11 -> V_151 = 1 ;
}
static int F_55 ( struct V_104 * V_21 )
{
struct V_70 * V_71 = V_21 -> V_22 ;
int V_73 = V_152 ;
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
static int F_56 ( struct V_104 * V_21 )
{
struct V_70 * V_71 = V_21 -> V_22 ;
struct V_118 * V_25 = V_21 -> V_25 ;
F_9 ( L_14 , V_16 ) ;
if ( V_25 == V_71 -> V_108 -> V_25 [ 0 ] ) {
F_32 ( & V_71 -> V_22 ,
L_31 ) ;
return - V_153 ;
}
return 0 ;
}
static int F_57 ( struct V_104 * V_21 )
{
struct V_70 * V_71 = V_21 -> V_22 ;
struct V_118 * V_25 = V_21 -> V_25 ;
F_9 ( L_14 , V_16 ) ;
if ( V_25 == V_71 -> V_108 -> V_25 [ 2 ] )
return 0 ;
F_32 ( & V_71 -> V_22 , L_31 ) ;
return - V_153 ;
}
static int F_58 ( struct V_104 * V_21 )
{
struct V_154 * V_155 = V_21 -> V_22 -> V_156 [ 1 ] ;
struct V_119 * V_120 = & V_155 -> V_109 ;
if ( V_155 -> V_157 && V_120 -> V_126 == 0 ) {
V_120 -> V_126 = F_34 ( 0x40 ) ;
F_32 ( & V_21 -> V_22 -> V_22 ,
L_32 ) ;
}
return 0 ;
}
static void F_59 ( struct V_147 * V_158 )
{
struct V_10 * V_11 = F_60 ( V_158 , struct V_10 , V_147 ) ;
F_22 ( V_11 ) ;
}
static int F_61 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = F_8 ( V_7 ) ;
F_9 ( L_14 , V_16 ) ;
F_42 ( V_7 ) ;
F_62 ( & V_11 -> V_147 , F_59 ) ;
return 0 ;
}
static int F_63 ( struct V_28 * V_29 , struct V_6 * V_7 )
{
struct V_70 * V_22 = V_7 -> V_21 -> V_22 ;
struct V_10 * V_11 = F_8 ( V_7 ) ;
int V_101 ;
F_9 ( L_14 , V_16 ) ;
F_10 ( V_22 , F_11 ( V_22 , 0 ) ,
V_159 , V_160 ,
V_161 ,
V_11 -> V_25 , NULL , 0 , V_26 ) ;
if ( V_29 )
F_64 ( V_29 , V_7 , V_29 -> V_162 ) ;
V_101 = F_65 ( V_29 , V_7 ) ;
if ( ! V_101 )
F_66 ( & V_11 -> V_147 ) ;
return V_101 ;
}
static void F_67 ( struct V_6 * V_7 , int V_163 )
{
struct V_10 * V_11 = F_8 ( V_7 ) ;
F_27 ( & V_7 -> V_21 -> V_164 ) ;
if ( ! V_7 -> V_21 -> V_165 ) {
if ( ! V_163 && F_10 ( V_7 -> V_21 -> V_22 ,
F_11 ( V_7 -> V_21 -> V_22 , 0 ) ,
V_166 ,
V_167 ,
0 , V_11 -> V_25 , NULL , 0 ,
V_26 ) < 0 ) {
F_18 ( & V_7 -> V_22 , L_33 ) ;
}
if ( V_163 )
F_68 ( V_7 , V_14 | V_15 ) ;
else
F_69 ( V_7 , V_14 | V_15 ) ;
}
F_29 ( & V_7 -> V_21 -> V_164 ) ;
}
static void F_70 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = F_8 ( V_7 ) ;
F_9 ( L_14 , V_16 ) ;
F_71 ( V_7 ) ;
F_62 ( & V_11 -> V_147 , F_59 ) ;
}
static int F_72 ( struct V_6 * V_7 ,
void * V_168 , T_5 V_169 )
{
struct V_10 * V_11 ;
int V_132 ;
unsigned long V_32 ;
V_11 = F_8 ( V_7 ) ;
if ( V_11 -> V_37 == V_38 ) {
unsigned char * V_170 = V_168 ;
int V_124 , V_171 , V_172 ;
V_132 = 0 ;
F_73 ( & V_7 -> V_173 , V_32 ) ;
for ( V_124 = 0 ; V_124 < V_169 - 1 ; V_124 += V_11 -> V_127 ) {
V_171 = F_74 ( int , V_169 - V_124 , V_11 -> V_127 ) - 1 ;
V_172 = F_75 ( & V_7 -> V_174 , & V_170 [ V_124 + 1 ] , V_171 ) ;
if ( ! V_172 )
break;
V_170 [ V_124 ] = ( V_172 << 2 ) + 1 ;
V_132 += V_172 + 1 ;
}
F_76 ( & V_7 -> V_173 , V_32 ) ;
} else {
V_132 = F_77 ( & V_7 -> V_174 , V_168 , V_169 ,
& V_7 -> V_173 ) ;
}
return V_132 ;
}
static int F_78 ( struct V_28 * V_29 ,
struct V_6 * V_7 , struct V_10 * V_11 ,
char * V_175 , int V_171 )
{
int V_124 ;
char V_176 ;
char V_177 ;
char * V_178 ;
F_9 ( L_34 , V_16 , V_7 -> V_179 ) ;
if ( V_171 < 2 ) {
F_9 ( L_35 ) ;
return 0 ;
}
V_176 = V_175 [ 0 ] & V_180 ;
if ( V_176 != V_11 -> V_181 ) {
V_11 -> V_182 |= V_176 ^ V_11 -> V_181 ;
F_79 ( & V_11 -> V_148 ) ;
V_11 -> V_181 = V_176 ;
}
V_177 = V_183 ;
if ( V_175 [ 1 ] & V_184 ) {
if ( V_175 [ 1 ] & V_185 ) {
V_177 = V_186 ;
F_80 ( V_7 ) ;
} else if ( V_175 [ 1 ] & V_187 ) {
V_177 = V_188 ;
} else if ( V_175 [ 1 ] & V_189 ) {
V_177 = V_190 ;
}
if ( V_175 [ 1 ] & V_191 )
F_81 ( V_29 , 0 , V_192 ) ;
}
if ( V_175 [ 1 ] & V_193 )
V_11 -> V_102 = 1 ;
else
V_11 -> V_102 = 0 ;
V_171 -= 2 ;
if ( ! V_171 )
return 0 ;
V_178 = V_175 + 2 ;
if ( V_7 -> V_7 . V_194 && V_7 -> V_195 ) {
for ( V_124 = 0 ; V_124 < V_171 ; V_124 ++ , V_178 ++ ) {
if ( ! F_82 ( V_7 , * V_178 ) )
F_81 ( V_29 , * V_178 , V_177 ) ;
}
} else {
F_83 ( V_29 , V_178 , V_177 , V_171 ) ;
}
return V_171 ;
}
static void F_84 ( struct V_196 * V_196 )
{
struct V_6 * V_7 = V_196 -> V_197 ;
struct V_28 * V_29 ;
struct V_10 * V_11 = F_8 ( V_7 ) ;
char * V_198 = ( char * ) V_196 -> V_199 ;
int V_124 ;
int V_171 ;
int V_132 = 0 ;
V_29 = F_85 ( & V_7 -> V_7 ) ;
if ( ! V_29 )
return;
for ( V_124 = 0 ; V_124 < V_196 -> V_200 ; V_124 += V_11 -> V_127 ) {
V_171 = F_74 ( int , V_196 -> V_200 - V_124 , V_11 -> V_127 ) ;
V_132 += F_78 ( V_29 , V_7 , V_11 , & V_198 [ V_124 ] , V_171 ) ;
}
if ( V_132 )
F_86 ( V_29 ) ;
F_87 ( V_29 ) ;
}
static void F_88 ( struct V_28 * V_29 , int V_201 )
{
struct V_6 * V_7 = V_29 -> V_202 ;
struct V_10 * V_11 = F_8 ( V_7 ) ;
T_2 V_12 ;
if ( V_201 )
V_12 = V_11 -> V_203 | V_204 ;
else
V_12 = V_11 -> V_203 ;
if ( F_10 ( V_7 -> V_21 -> V_22 ,
F_11 ( V_7 -> V_21 -> V_22 , 0 ) ,
V_205 ,
V_206 ,
V_12 , V_11 -> V_25 ,
NULL , 0 , V_26 ) < 0 ) {
F_18 ( & V_7 -> V_22 , L_36
L_37 , V_16 , V_201 ) ;
}
F_9 ( L_38 , V_16 ,
V_201 , V_12 ) ;
}
static void F_64 ( struct V_28 * V_29 ,
struct V_6 * V_7 , struct V_207 * V_208 )
{
struct V_70 * V_22 = V_7 -> V_21 -> V_22 ;
struct V_10 * V_11 = F_8 ( V_7 ) ;
struct V_207 * V_162 = V_29 -> V_162 ;
unsigned int V_209 = V_162 -> V_210 ;
T_2 V_12 ;
unsigned int V_211 = V_162 -> V_212 ;
unsigned char V_213 ;
unsigned char V_214 ;
F_9 ( L_14 , V_16 ) ;
if ( V_11 -> V_150 && ( ( V_162 -> V_210 & V_215 ) != V_216 ) ) {
F_9 ( L_39 , V_16 ) ;
F_15 ( V_29 , V_11 -> V_150 ,
V_11 -> V_150 ) ;
}
if ( V_11 -> V_151 ) {
F_9 ( L_40 , V_16 ) ;
V_162 -> V_210 |= V_217 ;
}
V_209 = V_162 -> V_210 ;
V_12 = 0 ;
V_12 |= ( V_209 & V_218 ? V_219 :
V_220 ) ;
if ( V_209 & V_221 ) {
if ( V_209 & V_222 )
V_12 |= V_209 & V_223 ?
V_224 :
V_225 ;
else
V_12 |= V_209 & V_223 ?
V_226 :
V_227 ;
} else {
V_12 |= V_228 ;
}
if ( V_209 & V_229 ) {
switch ( V_209 & V_229 ) {
case V_230 : V_12 |= 7 ; F_9 ( L_41 ) ; break;
case V_231 : V_12 |= 8 ; F_9 ( L_42 ) ; break;
default:
F_18 ( & V_7 -> V_22 , L_43 ) ;
}
}
V_11 -> V_203 = V_12 ;
if ( F_10 ( V_22 , F_11 ( V_22 , 0 ) ,
V_205 ,
V_206 ,
V_12 , V_11 -> V_25 ,
NULL , 0 , V_69 ) < 0 ) {
F_18 ( & V_7 -> V_22 , L_44
L_45 , V_16 ) ;
}
if ( ( V_209 & V_215 ) == V_216 ) {
if ( F_10 ( V_22 , F_11 ( V_22 , 0 ) ,
V_166 ,
V_167 ,
0 , V_11 -> V_25 ,
NULL , 0 , V_26 ) < 0 ) {
F_18 ( & V_7 -> V_22 ,
L_46 ,
V_16 ) ;
}
F_69 ( V_7 , V_14 | V_15 ) ;
} else {
F_27 ( & V_11 -> V_89 ) ;
if ( F_16 ( V_29 , V_7 ) )
F_18 ( & V_7 -> V_22 , L_47 ,
V_16 ) ;
F_29 ( & V_11 -> V_89 ) ;
if ( ! V_208 || ( V_208 -> V_210 & V_215 ) == V_216 )
F_68 ( V_7 , V_14 | V_15 ) ;
}
if ( V_209 & V_217 ) {
F_9 ( L_48 , V_16 ) ;
if ( F_10 ( V_22 ,
F_11 ( V_22 , 0 ) ,
V_166 ,
V_167 ,
0 , ( V_232 | V_11 -> V_25 ) ,
NULL , 0 , V_26 ) < 0 ) {
F_18 ( & V_7 -> V_22 ,
L_49 ) ;
}
} else {
if ( V_211 & V_233 ) {
F_9 ( L_50 ,
V_16 , V_211 ) ;
V_214 = V_162 -> V_234 [ V_235 ] ;
V_213 = V_162 -> V_234 [ V_236 ] ;
V_12 = ( V_213 << 8 ) | ( V_214 ) ;
if ( F_10 ( V_22 ,
F_11 ( V_22 , 0 ) ,
V_166 ,
V_167 ,
V_12 , ( V_237
| V_11 -> V_25 ) ,
NULL , 0 , V_26 ) < 0 ) {
F_18 ( & V_7 -> V_22 , L_51
L_52 ) ;
}
} else {
F_9 ( L_53 , V_16 ) ;
if ( F_10 ( V_22 ,
F_11 ( V_22 , 0 ) ,
V_166 ,
V_167 ,
0 , V_11 -> V_25 ,
NULL , 0 , V_26 ) < 0 ) {
F_18 ( & V_7 -> V_22 ,
L_54 ) ;
}
}
}
}
static int F_89 ( struct V_28 * V_29 )
{
struct V_6 * V_7 = V_29 -> V_202 ;
struct V_10 * V_11 = F_8 ( V_7 ) ;
unsigned char * V_77 ;
int V_171 ;
int V_146 ;
F_9 ( L_55 , V_16 ) ;
V_77 = F_20 ( 2 , V_78 ) ;
if ( ! V_77 )
return - V_79 ;
switch ( V_11 -> V_37 ) {
case V_38 :
V_171 = 1 ;
break;
case V_49 :
case V_50 :
case V_51 :
case V_52 :
case V_61 :
case V_62 :
case V_63 :
V_171 = 2 ;
break;
default:
V_146 = - V_85 ;
goto V_238;
}
V_146 = F_10 ( V_7 -> V_21 -> V_22 ,
F_21 ( V_7 -> V_21 -> V_22 , 0 ) ,
V_239 ,
V_240 ,
0 , V_11 -> V_25 ,
V_77 , V_171 , V_26 ) ;
if ( V_146 < 0 )
goto V_238;
V_146 = ( V_77 [ 0 ] & V_241 ? V_242 : 0 ) |
( V_77 [ 0 ] & V_243 ? V_244 : 0 ) |
( V_77 [ 0 ] & V_245 ? V_246 : 0 ) |
( V_77 [ 0 ] & V_247 ? V_248 : 0 ) |
V_11 -> V_27 ;
V_238:
F_22 ( V_77 ) ;
return V_146 ;
}
static int F_90 ( struct V_28 * V_29 ,
unsigned int V_8 , unsigned int V_9 )
{
struct V_6 * V_7 = V_29 -> V_202 ;
F_9 ( L_56 , V_16 ) ;
return F_7 ( V_7 , V_8 , V_9 ) ;
}
static int F_91 ( struct V_28 * V_29 ,
unsigned int V_249 , unsigned long V_250 )
{
struct V_6 * V_7 = V_29 -> V_202 ;
struct V_10 * V_11 = F_8 ( V_7 ) ;
F_9 ( L_57 , V_16 , V_249 ) ;
switch ( V_249 ) {
case V_251 :
return F_23 ( V_7 ,
(struct V_82 T_3 * ) V_250 ) ;
case V_252 :
return F_25 ( V_29 , V_7 ,
(struct V_82 T_3 * ) V_250 ) ;
case V_253 :
while ( V_11 != NULL ) {
F_92 ( & V_11 -> V_148 ) ;
if ( F_93 ( V_254 ) )
return - V_255 ;
else {
char V_256 = V_11 -> V_182 ;
if ( V_256 == 0 )
return - V_134 ;
V_11 -> V_182 = 0 ;
if ( ( ( V_250 & V_257 ) && ( V_256 & V_258 ) ) ||
( ( V_250 & V_242 ) && ( V_256 & V_259 ) ) ||
( ( V_250 & V_248 ) && ( V_256 & V_260 ) ) ||
( ( V_250 & V_244 ) && ( V_256 & V_261 ) ) ) {
return 0 ;
}
}
}
return 0 ;
case V_262 :
return F_30 ( V_7 , (struct V_82 T_3 * ) V_250 ) ;
break;
default:
break;
}
F_9 ( L_58 , V_16 , V_249 ) ;
return - V_263 ;
}
static int T_6 F_94 ( void )
{
int V_137 ;
F_9 ( L_14 , V_16 ) ;
if ( V_264 > 0 && V_265 > 0 ) {
int V_124 ;
for ( V_124 = 0 ; V_266 [ V_124 ] . V_267 ; V_124 ++ )
;
V_266 [ V_124 ] . V_268 = V_269 ;
V_266 [ V_124 ] . V_267 = V_264 ;
V_266 [ V_124 ] . V_55 = V_265 ;
}
V_137 = F_95 ( & V_270 ) ;
if ( V_137 )
goto V_271;
V_137 = F_96 ( & V_272 ) ;
if ( V_137 )
goto V_273;
F_97 (KERN_INFO KBUILD_MODNAME L_59 DRIVER_VERSION L_60
DRIVER_DESC L_61 ) ;
return 0 ;
V_273:
F_98 ( & V_270 ) ;
V_271:
return V_137 ;
}
static void T_7 F_99 ( void )
{
F_9 ( L_14 , V_16 ) ;
F_100 ( & V_272 ) ;
F_98 ( & V_270 ) ;
}
