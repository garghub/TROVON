static void F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
F_2 ( V_2 -> V_5 , L_1 , V_6 , V_4 ) ;
switch ( V_4 ) {
case V_7 :
F_3 ( ( V_8 << V_9 ) |
( V_10 << V_11 ) ,
V_2 -> V_12 + V_13 ) ;
break;
case V_14 :
F_3 ( ( V_15 << V_16 ) |
( V_17 << V_9 ) |
( V_10 << V_11 ) ,
V_2 -> V_12 + V_13 ) ;
break;
case V_18 :
F_3 ( ( V_19 << V_16 ) |
( V_17 << V_9 ) |
( V_10 << V_11 ) ,
V_2 -> V_12 + V_13 ) ;
break;
case V_20 :
F_3 ( ( V_21 << V_9 ) |
( V_10 << V_11 ) ,
V_2 -> V_12 + V_13 ) ;
break;
default:
F_4 ( V_2 -> V_5 , L_2 , V_4 ) ;
}
}
static void F_5 ( struct V_1 * V_2 )
{
F_3 ( F_6 ( V_2 -> V_12 + V_22 ) | V_23 ,
V_2 -> V_12 + V_22 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
F_3 ( F_6 ( V_2 -> V_12 + V_22 ) & ~ V_23 ,
V_2 -> V_12 + V_22 ) ;
}
static T_1 F_8 ( int V_24 , void * V_25 )
{
struct V_1 * V_2 = V_25 ;
T_2 V_26 = F_6 ( V_2 -> V_12 + V_27 ) ;
if ( ( V_26 & ~ V_28 ) == 0 )
return V_29 ;
if ( V_26 & V_30 )
F_3 ( V_31 | V_32 ,
V_2 -> V_12 + V_33 ) ;
F_3 ( V_26 & ~ V_28 , V_2 -> V_12 + V_27 ) ;
F_9 ( & V_2 -> V_34 ) ;
return V_35 ;
}
static int F_10 ( struct V_1 * V_2 )
{
unsigned long V_36 = V_37 + F_11 ( V_38 ) ;
while ( F_6 ( V_2 -> V_12 + V_27 ) & V_39 )
if ( F_12 ( V_37 , V_36 ) ) {
F_4 ( V_2 -> V_5 , L_3 ) ;
return - V_40 ;
}
return 0 ;
}
static int F_13 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
int V_41 ;
unsigned long V_42 = F_11 ( V_38 ) ;
V_41 = F_10 ( V_2 ) ;
if ( V_41 < 0 )
return V_41 ;
F_3 ( V_43 , V_2 -> V_12 + V_44 ) ;
F_14 ( & V_2 -> V_34 ) ;
F_1 ( V_2 , V_4 ) ;
V_42 = F_15 ( & V_2 -> V_34 , V_42 ) ;
F_3 ( 0 , V_2 -> V_12 + V_44 ) ;
if ( ! V_42 ) {
F_4 ( V_2 -> V_5 , L_4 ) ;
V_41 = - V_40 ;
}
F_1 ( V_2 , V_7 ) ;
return V_41 ;
}
static int F_16 ( struct V_1 * V_2 ,
T_3 * V_45 , unsigned int V_46 ,
unsigned int V_47 )
{
unsigned long V_42 = F_11 ( V_38 ) ;
F_14 ( & V_2 -> V_34 ) ;
F_3 ( V_48 , V_2 -> V_12 + V_44 ) ;
F_3 ( ( V_47 << V_49 ) |
( V_46 << V_50 ) ,
V_2 -> V_12 + V_51 ) ;
V_42 = F_15 ( & V_2 -> V_34 , V_42 ) ;
F_3 ( 0 , V_2 -> V_12 + V_44 ) ;
if ( ! V_42 ) {
F_4 ( V_2 -> V_5 , L_5 ) ;
return - V_52 ;
}
for (; V_46 > 0 ; V_46 -- , V_45 ++ )
* V_45 = F_6 ( V_2 -> V_12 + V_53 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_54 * V_55 )
{
unsigned int V_56 = V_57 ;
unsigned int V_47 = 0 ;
unsigned int V_58 = 0 ;
int V_41 ;
T_3 * V_59 = V_55 -> V_45 ;
while ( V_58 < V_55 -> V_46 ) {
if ( V_55 -> V_46 - V_58 <= V_57 ) {
V_47 = 1 ;
V_56 = V_55 -> V_46 - V_58 ;
}
V_41 = F_16 ( V_2 , V_59 , V_56 ,
V_47 ) ;
if ( V_41 < 0 )
return - V_52 ;
V_58 += V_56 ;
V_59 += V_56 ;
}
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , T_3 V_60 ,
unsigned int V_61 )
{
int V_41 ;
unsigned long V_42 = F_11 ( V_38 ) ;
unsigned int V_62 ;
V_41 = F_10 ( V_2 ) ;
if ( V_41 < 0 )
return V_41 ;
F_3 ( V_63 , V_2 -> V_12 + V_27 ) ;
F_3 ( V_43 , V_2 -> V_12 + V_44 ) ;
F_14 ( & V_2 -> V_34 ) ;
F_3 ( V_60 , V_2 -> V_12 + V_64 ) ;
V_42 = F_15 ( & V_2 -> V_34 , V_42 ) ;
F_3 ( 0 , V_2 -> V_12 + V_44 ) ;
if ( ! V_42 ) {
F_2 ( V_2 -> V_5 , L_4 ) ;
return - V_40 ;
}
V_62 = F_6 ( V_2 -> V_12 + V_13 ) & V_65 ? 1 : 0 ;
if ( V_62 ^ V_61 ) {
F_2 ( V_2 -> V_5 , L_6 ) ;
return - V_52 ;
}
return 0 ;
}
static int F_19 ( struct V_1 * V_2 ,
T_3 * V_45 , unsigned int V_46 )
{
int V_66 ;
unsigned long V_42 = F_11 ( V_38 ) ;
unsigned int V_67 ;
F_14 ( & V_2 -> V_34 ) ;
F_3 ( V_68 | V_69 ,
V_2 -> V_12 + V_44 ) ;
F_20 ( V_2 -> V_24 ) ;
for ( V_66 = 0 ; V_66 < V_46 ; V_66 ++ )
F_3 ( V_45 [ V_66 ] , ( V_2 -> V_12 + V_64 ) ) ;
F_21 ( V_2 -> V_24 ) ;
do {
V_42 = F_15 ( & V_2 -> V_34 , V_42 ) ;
V_67 = F_6 ( V_2 -> V_12 + V_70 ) ;
} while ( V_42 && ! ( V_67 & V_71 ) );
F_3 ( 0 , V_2 -> V_12 + V_44 ) ;
if ( F_6 ( V_2 -> V_12 + V_13 ) & V_65 ) {
F_4 ( V_2 -> V_5 , L_7 ) ;
return - V_52 ;
}
if ( ! V_42 ) {
F_4 ( V_2 -> V_5 , L_8 ) ;
return - V_52 ;
}
return 0 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_54 * V_55 )
{
unsigned int V_72 = V_73 ;
unsigned int V_74 = 0 ;
int V_41 ;
T_3 * V_59 = V_55 -> V_45 ;
while ( V_74 < V_55 -> V_46 ) {
if ( V_55 -> V_46 - V_74 <= V_73 )
V_72 = V_55 -> V_46 - V_74 ;
V_41 = F_19 ( V_2 , V_59 ,
V_72 ) ;
if ( V_41 < 0 )
return - V_52 ;
V_74 += V_72 ;
V_59 += V_72 ;
}
return 0 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_54 * V_55 )
{
unsigned char V_75 ;
if ( V_55 -> V_76 & V_77 ) {
V_75 = 0xF0 | ( ( V_55 -> V_75 & 0x300 ) >> 7 ) ;
if ( F_18 ( V_2 , V_75 , 0 ) < 0 )
return - V_52 ;
V_75 = V_55 -> V_75 & 0xFF ;
if ( F_18 ( V_2 , V_75 , 0 ) < 0 )
return - V_52 ;
if ( V_55 -> V_76 & V_78 ) {
if ( F_13 ( V_2 , V_18 ) < 0 )
return - V_52 ;
V_75 = 0xF0 | ( ( V_55 -> V_75 & 0x300 ) >> 7 ) | 0x01 ;
if ( F_18 ( V_2 , V_75 , 0 ) < 0 )
return - V_52 ;
}
} else {
V_75 = V_55 -> V_75 << 1 ;
if ( V_55 -> V_76 & V_78 )
V_75 |= 1 ;
if ( F_18 ( V_2 , V_75 , 0 ) < 0 )
return - V_52 ;
}
return 0 ;
}
static void F_24 ( struct V_1 * V_2 )
{
F_3 ( F_6 ( V_2 -> V_12 + V_22 ) & ~ V_79 ,
V_2 -> V_12 + V_22 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
F_3 ( F_6 ( V_2 -> V_12 + V_80 ) & ~ V_81 ,
V_2 -> V_12 + V_80 ) ;
F_3 ( ( V_2 -> V_82 -> V_83 << V_84 ) |
( V_2 -> V_82 -> V_85 << V_86 ) |
( V_2 -> V_82 -> V_87 << V_88 ) |
( V_2 -> V_82 -> V_89 << V_90 ) ,
V_2 -> V_12 + V_91 ) ;
F_3 ( ( V_2 -> V_82 -> V_92 << V_93 ) |
( V_2 -> V_82 -> V_94 << V_95 ) |
V_23 ,
V_2 -> V_12 + V_22 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
F_3 ( ( V_2 -> V_96 -> V_83 << V_84 ) |
( V_2 -> V_96 -> V_85 << V_86 ) |
( V_2 -> V_96 -> V_87 << V_88 ) |
( V_2 -> V_96 -> V_89 << V_90 ) ,
V_2 -> V_12 + V_91 ) ;
F_3 ( ( V_2 -> V_96 -> V_97 << V_98 ) |
( V_2 -> V_96 -> V_99 << V_100 ) |
( V_2 -> V_96 -> V_101 << V_102 ) ,
V_2 -> V_12 + V_80 ) ;
F_3 ( F_6 ( V_2 -> V_12 + V_80 ) | V_81 ,
V_2 -> V_12 + V_80 ) ;
}
static int F_27 ( struct V_1 * V_2 )
{
int V_41 ;
V_41 = F_18 ( V_2 , V_103 , 1 ) ;
if ( V_41 < 0 ) {
F_28 ( L_9 ) ;
return V_41 ;
}
V_41 = F_29 ( V_2 -> V_104 , V_105 ) ;
if ( V_41 ) {
F_4 ( V_2 -> V_5 , L_10 ,
V_6 , V_41 ) ;
return V_41 ;
}
F_26 ( V_2 ) ;
V_41 = F_13 ( V_2 , V_18 ) ;
if ( V_41 < 0 )
F_4 ( V_2 -> V_5 , L_11 ) ;
return V_41 ;
}
static int F_30 ( struct V_1 * V_2 )
{
int V_41 ;
F_25 ( V_2 ) ;
V_41 = F_29 ( V_2 -> V_104 , V_106 ) ;
if ( V_41 ) {
F_4 ( V_2 -> V_5 , L_10 ,
V_6 , V_41 ) ;
}
return V_41 ;
}
static int F_31 ( struct V_107 * V_108 ,
struct V_54 V_109 [] , int V_110 )
{
struct V_1 * V_2 = F_32 ( V_108 ) ;
struct V_54 * V_111 ;
int V_41 = 0 ;
int V_112 ;
V_41 = F_33 ( V_2 -> V_104 ) ;
if ( V_41 ) {
F_4 ( V_2 -> V_5 , L_12 ,
V_6 , V_41 ) ;
return V_41 ;
}
F_3 ( 0 , V_2 -> V_12 + V_113 ) ;
F_5 ( V_2 ) ;
V_41 = F_13 ( V_2 , V_14 ) ;
if ( V_41 < 0 ) {
F_4 ( V_2 -> V_5 , L_13 , V_41 ) ;
goto V_114;
}
if ( V_2 -> V_96 ) {
V_41 = F_27 ( V_2 ) ;
if ( V_41 < 0 )
goto V_115;
}
for ( V_112 = 0 ; V_112 < V_110 ; V_112 ++ ) {
V_111 = & V_109 [ V_112 ] ;
if ( ( V_112 != 0 ) && ( ( V_111 -> V_76 & V_116 ) == 0 ) ) {
V_41 = F_13 ( V_2 , V_18 ) ;
if ( V_41 < 0 ) {
F_4 ( V_2 -> V_5 ,
L_14 , V_41 ) ;
goto V_115;
}
}
if ( ! ( V_111 -> V_76 & V_116 ) ) {
V_41 = F_23 ( V_2 , V_111 ) ;
if ( V_41 < 0 ) {
F_4 ( V_2 -> V_5 ,
L_15 ,
V_111 -> V_75 , V_112 , V_41 ) ;
goto V_115;
}
}
if ( V_111 -> V_76 & V_78 ) {
V_41 = F_17 ( V_2 , V_111 ) ;
if ( V_41 < 0 ) {
F_4 ( V_2 -> V_5 , L_16 ) ;
goto V_115;
}
} else {
V_41 = F_22 ( V_2 , V_111 ) ;
if ( V_41 < 0 ) {
F_4 ( V_2 -> V_5 , L_17 ) ;
goto V_115;
}
}
}
V_41 = V_110 ;
V_115:
F_13 ( V_2 , V_20 ) ;
if ( V_2 -> V_96 ) {
int V_117 = F_30 ( V_2 ) ;
if ( V_117 )
V_41 = V_117 ;
}
V_114:
F_3 ( V_118 , V_2 -> V_12 + V_113 ) ;
F_7 ( V_2 ) ;
F_34 ( V_2 -> V_104 ) ;
return V_41 ;
}
static T_2 F_35 ( struct V_107 * V_119 )
{
return V_120 | V_121 | V_122 |
V_123 ;
}
static int F_36 ( struct V_1 * V_2 )
{
unsigned int V_124 ;
int V_125 = F_37 ( V_2 -> V_5 -> V_126 , L_18 ,
& V_124 ) ;
if ( V_125 < 0 ) {
F_4 ( V_2 -> V_5 , L_19 ) ;
return - V_127 ;
}
switch ( V_124 ) {
case 100000 :
V_2 -> V_82 = & V_128 [ V_129 ] ;
break;
case 400000 :
V_2 -> V_82 = & V_128 [ V_130 ] ;
break;
case 1000000 :
V_2 -> V_82 = & V_128 [ V_131 ] ;
break;
case 3400000 :
V_2 -> V_82 = & V_128 [ V_129 ] ;
V_2 -> V_96 = & V_132 [ V_133 ] ;
break;
default:
F_28 ( L_20 , V_124 ) ;
F_28 ( L_21 ) ;
return - V_134 ;
}
return 0 ;
}
static int F_38 ( struct V_135 * V_136 )
{
int V_41 = 0 ;
struct V_1 * V_2 ;
struct V_107 * V_119 ;
struct V_137 * V_138 ;
V_2 = F_39 ( & V_136 -> V_2 , sizeof( * V_2 ) , V_139 ) ;
if ( ! V_2 )
return - V_140 ;
F_40 ( V_136 , V_2 ) ;
V_2 -> V_5 = & V_136 -> V_2 ;
F_41 ( & V_2 -> V_34 ) ;
V_138 = F_42 ( V_136 , V_141 , 0 ) ;
V_2 -> V_12 = F_43 ( V_2 -> V_5 , V_138 ) ;
if ( F_44 ( V_2 -> V_12 ) )
return - V_140 ;
V_2 -> V_104 = F_45 ( V_2 -> V_5 , NULL ) ;
if ( F_44 ( V_2 -> V_104 ) ) {
F_4 ( V_2 -> V_5 , L_22 ) ;
return - V_127 ;
}
V_41 = F_29 ( V_2 -> V_104 , V_106 ) ;
if ( V_41 ) {
F_4 ( V_2 -> V_5 , L_10 ,
V_6 , V_41 ) ;
return V_41 ;
}
V_41 = F_33 ( V_2 -> V_104 ) ;
if ( V_41 ) {
F_4 ( V_2 -> V_5 , L_23 ) ;
return V_41 ;
}
V_41 = F_36 ( V_2 ) ;
if ( V_41 )
goto V_142;
F_5 ( V_2 ) ;
F_25 ( V_2 ) ;
F_3 ( 0 , V_2 -> V_12 + V_143 ) ;
F_24 ( V_2 ) ;
F_3 ( V_31 | V_32 ,
V_2 -> V_12 + V_33 ) ;
F_3 ( 0 , V_2 -> V_12 + V_44 ) ;
F_3 ( V_39 |
V_144 |
V_63 |
V_145 |
V_146 |
V_30 ,
V_2 -> V_12 + V_27 ) ;
V_2 -> V_24 = F_46 ( V_136 , 0 ) ;
if ( V_2 -> V_24 < 0 ) {
F_4 ( V_2 -> V_5 , L_24 ) ;
V_41 = - V_127 ;
goto V_142;
}
V_41 = F_47 ( & V_136 -> V_2 , V_2 -> V_24 , F_8 ,
V_147 , V_136 -> V_148 , V_2 ) ;
if ( V_41 ) {
F_4 ( V_2 -> V_5 , L_25 , V_2 -> V_24 ) ;
goto V_142;
}
F_1 ( V_2 , V_7 ) ;
F_3 ( V_118 , V_2 -> V_12 + V_113 ) ;
F_7 ( V_2 ) ;
F_34 ( V_2 -> V_104 ) ;
V_119 = & V_2 -> V_108 ;
F_48 ( V_119 , V_2 ) ;
V_119 -> V_149 = V_150 ;
F_49 ( V_119 -> V_148 , L_26 , sizeof( V_119 -> V_148 ) ) ;
V_119 -> V_151 = & V_152 ;
V_119 -> V_2 . V_153 = & V_136 -> V_2 ;
V_119 -> V_2 . V_126 = V_136 -> V_2 . V_126 ;
V_41 = F_50 ( V_119 ) ;
if ( V_41 ) {
F_4 ( V_2 -> V_5 , L_27 ) ;
return V_41 ;
}
F_51 ( V_2 -> V_5 , L_28 ) ;
return 0 ;
V_142:
F_7 ( V_2 ) ;
F_34 ( V_2 -> V_104 ) ;
return V_41 ;
}
static int F_52 ( struct V_135 * V_136 )
{
struct V_1 * V_2 = F_53 ( V_136 ) ;
F_54 ( & V_2 -> V_108 ) ;
return 0 ;
}
