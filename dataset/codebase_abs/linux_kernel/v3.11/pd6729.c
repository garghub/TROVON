static unsigned char F_1 ( struct V_1 * V_2 ,
unsigned short V_3 )
{
unsigned long V_4 ;
unsigned char V_5 ;
unsigned long V_6 ;
F_2 ( & V_7 , V_6 ) ;
V_3 += V_2 -> V_8 * 0x40 ;
V_4 = V_2 -> V_9 ;
F_3 ( V_3 , V_4 ) ;
V_5 = F_4 ( V_4 + 1 ) ;
F_5 ( & V_7 , V_6 ) ;
return V_5 ;
}
static unsigned short F_6 ( struct V_1 * V_2 ,
unsigned short V_3 )
{
unsigned long V_4 ;
unsigned short V_10 ;
unsigned long V_6 ;
F_2 ( & V_7 , V_6 ) ;
V_3 = V_3 + V_2 -> V_8 * 0x40 ;
V_4 = V_2 -> V_9 ;
F_3 ( V_3 , V_4 ) ;
V_10 = F_4 ( V_4 + 1 ) ;
V_3 ++ ;
F_3 ( V_3 , V_4 ) ;
V_10 = V_10 | ( F_4 ( V_4 + 1 ) << 8 ) ;
F_5 ( & V_7 , V_6 ) ;
return V_10 ;
}
static void F_7 ( struct V_1 * V_2 , unsigned short V_3 ,
unsigned char V_11 )
{
unsigned long V_4 ;
unsigned long V_6 ;
F_2 ( & V_7 , V_6 ) ;
V_3 = V_3 + V_2 -> V_8 * 0x40 ;
V_4 = V_2 -> V_9 ;
F_3 ( V_3 , V_4 ) ;
F_3 ( V_11 , V_4 + 1 ) ;
F_5 ( & V_7 , V_6 ) ;
}
static void F_8 ( struct V_1 * V_2 , unsigned short V_3 ,
unsigned char V_12 )
{
unsigned long V_4 ;
unsigned char V_5 ;
unsigned long V_6 ;
F_2 ( & V_7 , V_6 ) ;
V_3 = V_3 + V_2 -> V_8 * 0x40 ;
V_4 = V_2 -> V_9 ;
F_3 ( V_3 , V_4 ) ;
V_5 = F_4 ( V_4 + 1 ) ;
V_5 |= V_12 ;
F_3 ( V_3 , V_4 ) ;
F_3 ( V_5 , V_4 + 1 ) ;
F_5 ( & V_7 , V_6 ) ;
}
static void F_9 ( struct V_1 * V_2 , unsigned short V_3 ,
unsigned char V_12 )
{
unsigned long V_4 ;
unsigned char V_5 ;
unsigned long V_6 ;
F_2 ( & V_7 , V_6 ) ;
V_3 = V_3 + V_2 -> V_8 * 0x40 ;
V_4 = V_2 -> V_9 ;
F_3 ( V_3 , V_4 ) ;
V_5 = F_4 ( V_4 + 1 ) ;
V_5 &= ~ V_12 ;
F_3 ( V_3 , V_4 ) ;
F_3 ( V_5 , V_4 + 1 ) ;
F_5 ( & V_7 , V_6 ) ;
}
static void F_10 ( struct V_1 * V_2 , unsigned short V_3 ,
unsigned short V_11 )
{
unsigned long V_4 ;
unsigned char V_5 ;
unsigned long V_6 ;
F_2 ( & V_7 , V_6 ) ;
V_3 = V_3 + V_2 -> V_8 * 0x40 ;
V_4 = V_2 -> V_9 ;
F_3 ( V_3 , V_4 ) ;
V_5 = V_11 & 255 ;
F_3 ( V_5 , V_4 + 1 ) ;
V_3 ++ ;
F_3 ( V_3 , V_4 ) ;
V_5 = V_11 >> 8 ;
F_3 ( V_5 , V_4 + 1 ) ;
F_5 ( & V_7 , V_6 ) ;
}
static T_1 F_11 ( int V_13 , void * V_14 )
{
struct V_1 * V_2 = (struct V_1 * ) V_14 ;
int V_15 ;
int V_16 = 0 ;
int V_17 = 0 ;
unsigned int V_18 , V_19 = 0 ;
while ( 1 ) {
V_16 ++ ;
if ( V_16 > 20 ) {
F_12 ( V_20 L_1
L_2 ) ;
break;
}
V_19 = 0 ;
for ( V_15 = 0 ; V_15 < V_21 ; V_15 ++ ) {
unsigned int V_22 ;
V_22 = F_1 ( & V_2 [ V_15 ] , V_23 ) ;
if ( V_22 == 0 )
continue;
V_17 = 1 ;
V_18 = 0 ;
if ( V_22 & V_24 ) {
V_18 |= V_25 ;
F_13 ( & V_2 [ V_15 ] . V_2 . V_14 ,
L_3 , V_15 ) ;
}
if ( F_1 ( & V_2 [ V_15 ] , V_26 )
& V_27 ) {
V_18 |= ( V_22 & V_28 )
? V_29 : 0 ;
} else {
V_18 |= ( V_22 & V_30 )
? V_31 : 0 ;
V_18 |= ( V_22 & V_32 )
? V_33 : 0 ;
V_18 |= ( V_22 & V_34 )
? V_35 : 0 ;
}
if ( V_18 )
F_14 ( & V_2 [ V_15 ] . V_2 , V_18 ) ;
V_19 |= V_18 ;
}
if ( V_19 == 0 )
break;
}
return F_15 ( V_17 ) ;
}
static void F_16 ( unsigned long V_36 )
{
struct V_1 * V_2 = (struct V_1 * ) V_36 ;
F_11 ( 0 , ( void * ) V_2 ) ;
F_17 ( & V_2 -> V_37 , V_38 + V_39 ) ;
}
static int F_18 ( struct V_40 * V_41 , T_2 * V_11 )
{
struct V_1 * V_2
= F_19 ( V_41 , struct V_1 , V_2 ) ;
unsigned int V_42 ;
unsigned int V_36 ;
struct V_1 * V_43 ;
V_42 = F_1 ( V_2 , V_44 ) ;
* V_11 = 0 ;
if ( ( V_42 & V_45 ) == V_45 )
* V_11 |= V_25 ;
if ( F_1 ( V_2 , V_26 ) & V_27 ) {
if ( ! ( V_42 & V_46 ) )
* V_11 |= V_29 ;
} else {
if ( ! ( V_42 & V_47 ) )
* V_11 |= V_31 ;
if ( ! ( V_42 & V_48 ) )
* V_11 |= V_33 ;
}
if ( V_42 & V_49 )
* V_11 |= V_50 ;
if ( V_42 & V_51 )
* V_11 |= V_35 ;
if ( V_42 & V_52 )
* V_11 |= V_53 ;
V_43 = ( V_2 -> V_8 ) ? V_2 : V_2 + 1 ;
F_7 ( V_43 , V_54 , V_55 ) ;
V_36 = F_6 ( V_43 , V_56 ) ;
* V_11 |= ( V_36 & F_20 ( V_2 -> V_8 ) ) ? 0 : V_57 ;
return 0 ;
}
static int F_21 ( struct V_40 * V_41 , T_3 * V_58 )
{
struct V_1 * V_2
= F_19 ( V_41 , struct V_1 , V_2 ) ;
unsigned char V_3 , V_36 ;
F_7 ( V_2 , V_59 , 0x00 ) ;
F_7 ( V_2 , V_60 , 0x00 ) ;
V_2 -> V_61 = V_58 -> V_62 ;
V_3 = 0 ;
if ( ! ( V_58 -> V_6 & V_63 ) )
V_3 |= V_64 ;
if ( V_58 -> V_6 & V_65 )
V_3 |= V_27 ;
F_7 ( V_2 , V_26 , V_3 ) ;
V_3 = V_66 ;
if ( V_58 -> V_6 & V_67 ) {
F_22 ( & V_41 -> V_14 , L_4 ) ;
V_3 |= V_68 ;
}
if ( V_58 -> V_6 & V_69 ) {
F_22 ( & V_41 -> V_14 , L_5 ) ;
V_3 |= V_70 ;
}
switch ( V_58 -> V_71 ) {
case 0 :
break;
case 33 :
F_22 ( & V_41 -> V_14 ,
L_6 ,
V_2 -> V_8 ) ;
V_3 |= V_72 ;
F_8 ( V_2 , V_73 , V_74 ) ;
break;
case 50 :
F_22 ( & V_41 -> V_14 ,
L_7 ,
V_2 -> V_8 ) ;
V_3 |= V_72 ;
F_9 ( V_2 , V_73 , V_74 ) ;
break;
default:
F_22 ( & V_41 -> V_14 ,
L_8
L_9 , V_58 -> V_71 ) ;
return - V_75 ;
}
switch ( V_58 -> V_76 ) {
case 0 :
F_22 ( & V_41 -> V_14 , L_10 ,
V_2 -> V_8 ) ;
break;
case 33 :
case 50 :
F_22 ( & V_41 -> V_14 , L_11 ,
V_2 -> V_8 ) ;
V_3 |= V_77 ;
break;
case 120 :
F_22 ( & V_41 -> V_14 , L_12 ) ;
V_3 |= V_78 ;
break;
default:
F_22 ( & V_41 -> V_14 , L_13
L_14 , V_58 -> V_76 ) ;
return - V_75 ;
}
if ( V_3 != F_1 ( V_2 , V_79 ) )
F_7 ( V_2 , V_79 , V_3 ) ;
if ( V_80 == 1 ) {
V_36 = V_81 | V_82 ;
} else
V_36 = 0 ;
F_7 ( V_2 , V_54 , V_83 ) ;
F_7 ( V_2 , V_56 , V_36 ) ;
V_3 = 0x00 ;
if ( V_58 -> V_84 & V_25 )
V_3 |= V_24 ;
if ( V_58 -> V_6 & V_65 ) {
if ( V_58 -> V_84 & V_29 )
V_3 |= V_28 ;
} else {
if ( V_58 -> V_84 & V_31 )
V_3 |= V_30 ;
if ( V_58 -> V_84 & V_33 )
V_3 |= V_32 ;
if ( V_58 -> V_84 & V_35 )
V_3 |= V_34 ;
}
if ( V_80 == 1 )
V_3 |= 0x30 ;
F_7 ( V_2 , V_85 , V_3 ) ;
V_3 = F_1 ( V_2 , V_26 ) ;
if ( V_80 == 1 )
V_3 |= 0x03 ;
else
V_3 |= V_2 -> V_61 ;
F_7 ( V_2 , V_26 , V_3 ) ;
( void ) F_1 ( V_2 , V_23 ) ;
return 0 ;
}
static int F_23 ( struct V_40 * V_41 ,
struct V_86 * V_87 )
{
struct V_1 * V_2
= F_19 ( V_41 , struct V_1 , V_2 ) ;
unsigned char V_88 , V_89 ;
V_88 = V_87 -> V_88 ;
if ( V_88 > 1 ) {
F_22 ( & V_41 -> V_14 , L_15 ) ;
return - V_75 ;
}
if ( F_1 ( V_2 , V_90 ) & F_24 ( V_88 ) )
F_9 ( V_2 , V_90 , F_24 ( V_88 ) ) ;
F_10 ( V_2 , F_25 ( V_88 ) + V_91 , V_87 -> V_92 ) ;
F_10 ( V_2 , F_25 ( V_88 ) + V_93 , V_87 -> V_94 ) ;
V_89 = F_1 ( V_2 , V_95 ) & ~ F_26 ( V_88 ) ;
if ( V_87 -> V_6 & V_96 )
V_89 |= F_27 ( V_88 ) ;
if ( V_87 -> V_6 & V_97 )
V_89 |= F_28 ( V_88 ) ;
if ( V_87 -> V_6 & V_98 )
V_89 |= F_29 ( V_88 ) ;
F_7 ( V_2 , V_95 , V_89 ) ;
if ( V_87 -> V_6 & V_99 )
F_8 ( V_2 , V_90 , F_24 ( V_88 ) ) ;
return 0 ;
}
static int F_30 ( struct V_40 * V_41 ,
struct V_100 * V_101 )
{
struct V_1 * V_2
= F_19 ( V_41 , struct V_1 , V_2 ) ;
unsigned short V_102 , V_15 ;
unsigned char V_88 ;
V_88 = V_101 -> V_88 ;
if ( V_88 > 4 ) {
F_31 ( & V_41 -> V_14 , L_16 ) ;
return - V_75 ;
}
if ( ( V_101 -> V_103 -> V_92 > V_101 -> V_103 -> V_104 ) || ( V_101 -> V_105 > 1000 ) ) {
F_31 ( & V_41 -> V_14 , L_17 ) ;
return - V_75 ;
}
if ( F_1 ( V_2 , V_90 ) & F_32 ( V_88 ) )
F_9 ( V_2 , V_90 , F_32 ( V_88 ) ) ;
V_102 = F_33 ( V_88 ) ;
V_15 = ( V_101 -> V_103 -> V_92 >> 12 ) & 0x0fff ;
if ( V_101 -> V_6 & V_97 )
V_15 |= V_106 ;
if ( V_101 -> V_6 & V_96 )
V_15 |= V_107 ;
F_10 ( V_2 , V_102 + V_91 , V_15 ) ;
V_15 = ( V_101 -> V_103 -> V_104 >> 12 ) & 0x0fff ;
switch ( F_34 ( V_101 -> V_105 ) ) {
case 0 :
break;
case 1 :
V_15 |= V_108 ;
break;
case 2 :
V_15 |= V_109 ;
break;
default:
V_15 |= V_109 | V_108 ;
break;
}
F_10 ( V_2 , V_102 + V_93 , V_15 ) ;
F_7 ( V_2 , V_54 , F_35 ( V_88 ) ) ;
F_7 ( V_2 , V_56 , V_101 -> V_103 -> V_92 >> 24 ) ;
V_15 = ( ( V_101 -> V_110 - V_101 -> V_103 -> V_92 ) >> 12 ) & 0x3fff ;
if ( V_101 -> V_6 & V_111 )
V_15 |= V_112 ;
if ( V_101 -> V_6 & V_113 ) {
V_15 |= V_114 ;
} else {
}
F_10 ( V_2 , V_102 + V_115 , V_15 ) ;
if ( V_101 -> V_6 & V_99 )
F_8 ( V_2 , V_90 , F_32 ( V_88 ) ) ;
return 0 ;
}
static int F_36 ( struct V_40 * V_41 )
{
int V_15 ;
struct V_116 V_103 = { . V_104 = 0x0fff } ;
V_86 V_87 = { 0 , 0 , 0 , 0 , 1 } ;
V_100 V_101 = { . V_103 = & V_103 , } ;
F_21 ( V_41 , & V_117 ) ;
for ( V_15 = 0 ; V_15 < 2 ; V_15 ++ ) {
V_87 . V_88 = V_15 ;
F_23 ( V_41 , & V_87 ) ;
}
for ( V_15 = 0 ; V_15 < 5 ; V_15 ++ ) {
V_101 . V_88 = V_15 ;
F_30 ( V_41 , & V_101 ) ;
}
return 0 ;
}
static T_1 F_37 ( int V_13 , void * V_14 )
{
F_38 ( L_18 , V_13 ) ;
return V_118 ;
}
static int F_39 ( int V_13 )
{
int V_119 ;
V_119 = F_40 ( V_13 , F_37 , V_120 , L_19 ,
F_37 ) ;
if ( V_119 )
return - 1 ;
F_41 ( V_13 , F_37 ) ;
return 0 ;
}
static T_2 F_42 ( void )
{
T_2 V_121 , V_12 = 0 ;
int V_15 ;
if ( V_80 == 1 ) {
F_12 ( V_122 L_20
L_21 ) ;
return 0 ;
}
V_121 = V_123 ;
for ( V_15 = 0 ; V_15 < 16 ; V_15 ++ )
if ( ( V_121 & ( 1 << V_15 ) ) && ( F_39 ( V_15 ) == 0 ) )
V_12 |= ( 1 << V_15 ) ;
F_12 ( V_122 L_22 ) ;
for ( V_15 = 0 ; V_15 < 16 ; V_15 ++ )
if ( V_12 & ( 1 << V_15 ) )
F_12 ( L_23 , ( ( V_12 & ( ( 1 << V_15 ) - 1 ) ) ? L_24 : L_25 ) , V_15 ) ;
if ( V_12 == 0 )
F_12 ( L_26 ) ;
else
F_12 ( L_27 ) ;
return V_12 ;
}
static int F_43 ( struct V_124 * V_14 ,
const struct V_125 * V_126 )
{
int V_15 , V_127 , V_119 ;
T_2 V_12 ;
char V_128 ;
struct V_1 * V_2 ;
V_2 = F_44 ( sizeof( struct V_1 ) * V_21 ,
V_129 ) ;
if ( ! V_2 ) {
F_31 ( & V_14 -> V_14 , L_28 ) ;
return - V_130 ;
}
V_119 = F_45 ( V_14 ) ;
if ( V_119 ) {
F_31 ( & V_14 -> V_14 , L_29 ) ;
goto V_131;
}
if ( ! F_46 ( V_14 , 0 ) ) {
F_31 ( & V_14 -> V_14 , L_30
L_31 ) ;
V_119 = - V_130 ;
goto V_132;
}
F_47 ( & V_14 -> V_14 , L_32
L_33 ,
( unsigned long long ) F_46 ( V_14 , 0 ) , V_14 -> V_13 ) ;
F_48 ( V_14 , V_133 , & V_128 ) ;
if ( ! ( V_128 & V_134 ) ) {
F_22 ( & V_14 -> V_14 , L_34 ) ;
V_128 |= V_134 ;
F_49 ( V_14 , V_133 , V_128 ) ;
}
V_119 = F_50 ( V_14 , L_35 ) ;
if ( V_119 ) {
F_31 ( & V_14 -> V_14 , L_36 ) ;
goto V_132;
}
if ( V_14 -> V_13 == V_135 )
V_80 = 0 ;
V_12 = F_42 () ;
if ( V_80 == 0 && V_12 == 0 ) {
F_31 ( & V_14 -> V_14 , L_37 ) ;
V_119 = - V_136 ;
goto V_137;
}
for ( V_15 = 0 ; V_15 < V_21 ; V_15 ++ ) {
V_2 [ V_15 ] . V_9 = F_46 ( V_14 , 0 ) ;
V_2 [ V_15 ] . V_2 . V_138 |= V_139 | V_140 ;
V_2 [ V_15 ] . V_2 . V_141 = 0x1000 ;
V_2 [ V_15 ] . V_2 . V_142 = V_12 ;
V_2 [ V_15 ] . V_2 . V_143 = V_14 -> V_13 ;
V_2 [ V_15 ] . V_2 . V_144 = V_14 ;
V_2 [ V_15 ] . V_2 . V_145 = V_146 ;
V_2 [ V_15 ] . V_8 = V_15 ;
V_2 [ V_15 ] . V_2 . V_147 = & V_148 ;
V_2 [ V_15 ] . V_2 . V_149 = & V_150 ;
V_2 [ V_15 ] . V_2 . V_14 . V_151 = & V_14 -> V_14 ;
V_2 [ V_15 ] . V_2 . V_152 = & V_2 [ V_15 ] ;
}
F_51 ( V_14 , V_2 ) ;
if ( V_80 == 1 ) {
V_119 = F_40 ( V_14 -> V_13 , F_11 , V_153 ,
L_35 , V_2 ) ;
if ( V_119 ) {
F_52 ( & V_14 -> V_14 , L_38 ,
V_14 -> V_13 ) ;
goto V_137;
}
} else {
F_53 ( & V_2 -> V_37 ) ;
V_2 -> V_37 . V_154 = F_16 ;
V_2 -> V_37 . V_36 = ( unsigned long ) V_2 ;
V_2 -> V_37 . V_155 = V_38 + V_39 ;
F_54 ( & V_2 -> V_37 ) ;
}
for ( V_15 = 0 ; V_15 < V_21 ; V_15 ++ ) {
V_119 = F_55 ( & V_2 [ V_15 ] . V_2 ) ;
if ( V_119 ) {
F_31 ( & V_14 -> V_14 , L_39 ) ;
for ( V_127 = 0 ; V_127 < V_15 ; V_127 ++ )
F_56 ( & V_2 [ V_127 ] . V_2 ) ;
goto V_156;
}
}
return 0 ;
V_156:
if ( V_80 == 1 )
F_41 ( V_14 -> V_13 , V_2 ) ;
else
F_57 ( & V_2 -> V_37 ) ;
V_137:
F_58 ( V_14 ) ;
V_132:
F_59 ( V_14 ) ;
V_131:
F_60 ( V_2 ) ;
return V_119 ;
}
static void F_61 ( struct V_124 * V_14 )
{
int V_15 ;
struct V_1 * V_2 = F_62 ( V_14 ) ;
for ( V_15 = 0 ; V_15 < V_21 ; V_15 ++ ) {
F_7 ( & V_2 [ V_15 ] , V_85 , 0 ) ;
F_7 ( & V_2 [ V_15 ] , V_26 , 0 ) ;
F_56 ( & V_2 [ V_15 ] . V_2 ) ;
}
if ( V_80 == 1 )
F_41 ( V_14 -> V_13 , V_2 ) ;
else
F_57 ( & V_2 -> V_37 ) ;
F_58 ( V_14 ) ;
F_59 ( V_14 ) ;
F_60 ( V_2 ) ;
}
static int F_63 ( void )
{
return F_64 ( & V_157 ) ;
}
static void F_65 ( void )
{
F_66 ( & V_157 ) ;
}
