static unsigned int F_1 ( struct V_1 * V_1 )
{
unsigned int V_2 ;
if ( V_1 -> V_3 == V_4 )
V_2 = 8000 ;
else
V_2 = 1000 ;
V_2 /= ( V_1 -> V_5 + 1 ) ;
return V_2 ;
}
static int F_2 ( struct V_1 * V_1 )
{
T_1 V_6 [ 3 ] ;
int V_7 ;
int V_8 ;
V_7 = F_3 ( V_1 -> V_9 , V_10 ,
V_11 , V_11 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_3 ( V_1 -> V_9 , V_10 ,
V_12 ,
V_13 ) ;
if ( V_7 )
return V_7 ;
for ( V_8 = 0 ; V_8 < 3 ; V_8 ++ )
V_6 [ V_8 ] = F_4 ( V_1 -> V_14 [ V_8 ] ) ;
V_7 = F_5 ( V_1 -> V_9 , V_15 , V_6 ,
sizeof( V_6 ) ) ;
if ( V_7 )
return V_7 ;
V_7 = F_6 ( V_1 -> V_9 , V_16 ,
V_17 << V_18 |
V_1 -> V_19 << V_20 |
V_1 -> V_3 << V_21 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_6 ( V_1 -> V_9 , V_22 , V_1 -> V_5 ) ;
if ( V_7 )
return V_7 ;
F_7 ( 50 + 1000 / F_1 ( V_1 ) ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_1 )
{
int V_7 ;
T_2 V_5 ;
enum V_23 V_3 ;
V_3 = V_1 -> V_3 ;
V_5 = V_1 -> V_5 ;
V_1 -> V_3 = V_24 ;
V_1 -> V_5 = 0 ;
V_7 = F_2 ( V_1 ) ;
V_1 -> V_3 = V_3 ;
V_1 -> V_5 = V_5 ;
return V_7 ;
}
static int F_9 ( struct V_25 * V_26 ,
struct V_27 const * V_28 ,
int * V_29 , int * V_30 ,
long V_31 )
{
struct V_1 * V_1 = F_10 ( V_26 ) ;
int V_7 ;
T_1 V_6 ;
switch ( V_31 ) {
case V_32 :
switch ( V_28 -> type ) {
case V_33 :
* V_29 = 23000 ;
return V_34 ;
default:
return - V_35 ;
}
case V_36 :
switch ( V_28 -> type ) {
case V_37 :
* V_29 = V_1 -> V_14 [ V_28 -> V_38 - 1 ] ;
return V_34 ;
default:
return - V_35 ;
}
case V_39 :
* V_29 = F_1 ( V_1 ) ;
return V_34 ;
case V_40 :
switch ( V_28 -> type ) {
case V_33 :
* V_29 = 1000 ;
* V_30 = 280 ;
return V_41 ;
case V_37 :
* V_29 = V_42 [ V_1 -> V_19 ] * 2 ;
* V_30 = V_43 ;
return V_41 ;
default:
return - V_35 ;
}
case V_44 :
F_11 ( V_1 -> V_45 ) ;
F_12 ( & V_1 -> V_46 ) ;
V_7 = F_8 ( V_1 ) ;
if ( V_7 )
goto V_47;
switch ( V_28 -> type ) {
case V_33 :
V_7 = F_13 ( V_1 -> V_9 , V_48 ,
& V_6 , sizeof( V_6 ) ) ;
if ( V_7 ) {
F_14 ( V_1 -> V_45 ,
L_1 ) ;
goto V_47;
}
* V_29 = F_15 ( V_6 ) ;
V_7 = V_34 ;
goto V_47;
case V_37 :
V_7 = F_13 ( V_1 -> V_9 ,
F_16 ( V_28 -> V_38 - 1 ) ,
& V_6 ,
sizeof( V_6 ) ) ;
if ( V_7 ) {
F_14 ( V_1 -> V_45 ,
L_2 ) ;
goto V_47;
}
* V_29 = F_15 ( V_6 ) ;
V_7 = V_34 ;
goto V_47;
default:
V_7 = - V_35 ;
goto V_47;
}
default:
break;
}
return - V_35 ;
V_47:
F_17 ( & V_1 -> V_46 ) ;
F_18 ( V_1 -> V_45 ) ;
F_19 ( V_1 -> V_45 ) ;
return V_7 ;
}
static int F_20 ( struct V_25 * V_26 ,
const struct V_27 * V_28 ,
int V_29 , int V_30 , long V_31 )
{
struct V_1 * V_1 = F_10 ( V_26 ) ;
unsigned int V_49 =
F_21 ( V_42 [ 0 ] * 1000000 * 2 ,
V_43 ) ;
unsigned int V_50 =
F_21 ( V_42 [ 1 ] * 1000000 * 2 ,
V_43 ) ;
unsigned int V_51 =
F_21 ( V_42 [ 2 ] * 1000000 * 2 ,
V_43 ) ;
unsigned int V_52 =
F_21 ( V_42 [ 3 ] * 1000000 * 2 ,
V_43 ) ;
switch ( V_31 ) {
case V_36 :
if ( V_28 -> type != V_37 )
return - V_35 ;
V_1 -> V_14 [ V_28 -> V_38 - 1 ] = V_29 ;
return 0 ;
case V_39 :
if ( V_29 < 4 || V_29 > 8000 )
return - V_35 ;
if ( V_29 > 1000 ) {
V_1 -> V_3 = V_24 ;
V_1 -> V_5 = F_21 ( 8000 , V_29 ) - 1 ;
return 0 ;
}
V_1 -> V_3 = V_53 ;
V_1 -> V_5 = F_21 ( 1000 , V_29 ) - 1 ;
return 0 ;
case V_40 :
if ( V_28 -> type != V_37 )
return - V_35 ;
if ( V_29 != 0 ) {
V_1 -> V_19 = V_54 ;
return 0 ;
}
if ( V_30 <= V_49 ||
V_30 < ( ( V_50 + V_49 ) / 2 ) )
V_1 -> V_19 = V_55 ;
else if ( V_30 <= V_50 ||
V_30 < ( ( V_51 + V_50 ) / 2 ) )
V_1 -> V_19 = V_56 ;
else if ( V_30 <= V_51 ||
V_30 < ( ( V_52 + V_51 ) / 2 ) )
V_1 -> V_19 = V_57 ;
else
V_1 -> V_19 = V_54 ;
return 0 ;
default:
break;
}
return - V_35 ;
}
static T_3 F_22 ( int V_58 , void * V_59 )
{
const struct V_60 * V_61 = V_59 ;
struct V_25 * V_26 = V_61 -> V_26 ;
struct V_1 * V_1 = F_10 ( V_26 ) ;
int V_7 ;
T_1 V_62 [ 8 ] ;
T_4 V_63 ;
unsigned int V_64 = 0 ;
if ( F_23 ( V_26 ) )
V_63 = V_1 -> V_65 ;
else
V_63 = F_24 ( V_26 ) ;
F_12 ( & V_1 -> V_46 ) ;
if ( V_1 -> V_66 ) {
T_1 V_67 ;
T_5 V_68 ;
unsigned int V_69 = 8 ;
bool V_70 = false ;
V_7 = F_13 ( V_1 -> V_9 ,
V_71 ,
& V_67 ,
sizeof( V_67 ) ) ;
if ( V_7 )
goto V_72;
V_68 = F_15 ( V_67 ) ;
if ( V_68 == 512 ) {
F_25 ( V_1 -> V_45 ,
L_3 ) ;
V_70 = true ;
V_7 = F_3 ( V_1 -> V_9 ,
V_73 ,
V_74 |
V_75 ,
V_74 |
V_75 ) ;
if ( V_7 ) {
F_25 ( V_1 -> V_45 , L_4 ) ;
goto V_72;
}
V_1 -> V_76 = false ;
}
if ( V_68 )
F_26 ( V_1 -> V_45 ,
L_5 ,
V_68 ) ;
while ( ! V_70 && V_68 > V_69 ) {
unsigned int V_77 ;
unsigned int V_78 ;
T_1 V_79 [ 5 ] ;
if ( V_1 -> V_76 ) {
V_77 = V_69 + 2 ;
V_78 = 0 ;
} else {
V_77 = V_69 ;
V_78 = 1 ;
V_79 [ 0 ] = 0xAAAA ;
}
V_7 = F_13 ( V_1 -> V_9 ,
V_80 ,
& V_79 [ V_78 ] ,
V_77 ) ;
F_26 ( V_1 -> V_45 ,
L_6 ,
V_79 [ 0 ] ,
V_79 [ 1 ] ,
V_79 [ 2 ] ,
V_79 [ 3 ] ,
V_79 [ 4 ] ) ;
F_27 ( V_26 ,
& V_79 [ 1 ] ,
V_63 ) ;
V_68 -= V_77 ;
V_64 ++ ;
V_1 -> V_76 = true ;
if ( V_68 < V_69 ) {
V_7 = F_13 ( V_1 -> V_9 ,
V_71 ,
& V_67 ,
sizeof( V_67 ) ) ;
if ( V_7 )
goto V_72;
V_68 = F_15 ( V_67 ) ;
}
if ( V_68 < V_69 )
F_26 ( V_1 -> V_45 ,
L_7 ,
V_68 ) ;
V_63 = 0 ;
}
}
if ( V_64 ) {
F_26 ( V_1 -> V_45 ,
L_8 ,
V_64 ) ;
goto V_72;
}
V_7 = F_13 ( V_1 -> V_9 , V_48 , & V_62 ,
sizeof( V_62 ) ) ;
if ( V_7 ) {
F_14 ( V_1 -> V_45 ,
L_2 ) ;
goto V_72;
}
F_27 ( V_26 , V_62 , V_63 ) ;
V_72:
F_17 ( & V_1 -> V_46 ) ;
F_28 ( V_26 -> V_81 ) ;
return V_82 ;
}
static int F_29 ( struct V_25 * V_26 )
{
struct V_1 * V_1 = F_10 ( V_26 ) ;
F_11 ( V_1 -> V_45 ) ;
if ( ! V_1 -> V_66 )
return F_8 ( V_1 ) ;
return 0 ;
}
static int F_30 ( struct V_25 * V_26 )
{
struct V_1 * V_1 = F_10 ( V_26 ) ;
F_18 ( V_1 -> V_45 ) ;
F_19 ( V_1 -> V_45 ) ;
return 0 ;
}
static const struct V_83 *
F_31 ( const struct V_25 * V_26 ,
const struct V_27 * V_28 )
{
struct V_1 * V_1 = F_10 ( V_26 ) ;
return & V_1 -> V_84 ;
}
static int F_32 ( struct V_1 * V_1 ,
T_2 V_85 ,
T_2 V_86 ,
T_2 V_87 ,
T_2 * V_88 )
{
int V_7 ;
V_7 = F_6 ( V_1 -> V_9 ,
V_89 ,
V_85 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_6 ( V_1 -> V_9 ,
V_90 ,
V_86 ) ;
if ( V_7 )
return V_7 ;
return F_13 ( V_1 -> V_9 ,
V_91 ,
V_88 ,
V_87 ) ;
}
static int F_33 ( struct V_1 * V_1 )
{
int V_7 ;
T_2 V_92 [ 8 ] ;
V_7 = F_3 ( V_1 -> V_9 ,
V_10 ,
V_11 ,
V_11 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_3 ( V_1 -> V_9 ,
V_10 ,
V_12 ,
V_13 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_6 ( V_1 -> V_9 ,
V_93 ,
0 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_32 ( V_1 ,
( V_94 |
V_95 |
V_96 ) ,
0 ,
sizeof( V_92 ) ,
V_92 ) ;
if ( V_7 )
return V_7 ;
F_34 ( V_92 , sizeof( V_92 ) ) ;
F_25 ( V_1 -> V_45 ,
L_9
L_10 ,
( V_92 [ 1 ] << 8 | V_92 [ 0 ] ) & 0x1fff ,
( ( V_92 [ 2 ] << 8 | V_92 [ 1 ] ) & 0x03e0 ) >> 5 ,
( ( V_92 [ 4 ] << 16 | V_92 [ 3 ] << 8 | V_92 [ 2 ] ) & 0x3fffc ) >> 2 ,
( ( V_92 [ 5 ] << 8 | V_92 [ 4 ] ) & 0x3ffc ) >> 2 ,
( ( V_92 [ 6 ] << 8 | V_92 [ 5 ] ) & 0x0380 ) >> 7 ,
V_92 [ 6 ] >> 2 ) ;
return 0 ;
}
static int F_35 ( struct V_1 * V_1 )
{
int V_7 ;
V_7 = F_36 ( F_37 ( V_1 -> V_97 ) , V_1 -> V_97 ) ;
if ( V_7 ) {
F_14 ( V_1 -> V_45 , L_11 ) ;
return V_7 ;
}
F_7 ( 200 ) ;
V_7 = F_3 ( V_1 -> V_9 , V_10 ,
V_98 , 0 ) ;
if ( V_7 ) {
F_14 ( V_1 -> V_45 , L_12 ) ;
return V_7 ;
}
F_7 ( 10 ) ;
return 0 ;
}
static int F_38 ( struct V_1 * V_1 )
{
int V_7 ;
V_7 = F_3 ( V_1 -> V_9 , V_10 ,
V_98 , V_98 ) ;
if ( V_7 )
F_14 ( V_1 -> V_45 , L_13 ) ;
V_7 = F_39 ( F_37 ( V_1 -> V_97 ) , V_1 -> V_97 ) ;
if ( V_7 )
F_14 ( V_1 -> V_45 , L_14 ) ;
return 0 ;
}
static T_3 F_40 ( int V_58 , void * V_59 )
{
struct V_99 * V_81 = V_59 ;
struct V_25 * V_26 = F_41 ( V_81 ) ;
struct V_1 * V_1 = F_10 ( V_26 ) ;
if ( ! V_1 -> V_66 )
return V_100 ;
V_1 -> V_65 = F_24 ( V_26 ) ;
return V_101 ;
}
static T_3 F_42 ( int V_58 , void * V_59 )
{
struct V_99 * V_81 = V_59 ;
struct V_25 * V_26 = F_41 ( V_81 ) ;
struct V_1 * V_1 = F_10 ( V_26 ) ;
unsigned int V_29 ;
int V_7 ;
V_7 = F_43 ( V_1 -> V_9 , V_102 , & V_29 ) ;
if ( V_7 ) {
F_14 ( V_1 -> V_45 , L_15 ) ;
return V_82 ;
}
if ( ! ( V_29 & V_103 ) )
return V_100 ;
F_44 ( V_59 ) ;
return V_82 ;
}
static int F_45 ( struct V_99 * V_81 ,
bool V_104 )
{
struct V_25 * V_26 = F_41 ( V_81 ) ;
struct V_1 * V_1 = F_10 ( V_26 ) ;
unsigned int V_29 ;
int V_7 ;
if ( ! V_104 ) {
V_7 = F_6 ( V_1 -> V_9 ,
V_93 ,
0 ) ;
if ( V_7 )
F_14 ( V_1 -> V_45 , L_16 ) ;
V_7 = F_43 ( V_1 -> V_9 , V_102 , & V_29 ) ;
if ( V_7 )
F_14 ( V_1 -> V_45 , L_17 ) ;
V_7 = F_6 ( V_1 -> V_9 , V_105 , 0 ) ;
if ( V_7 )
F_14 ( V_1 -> V_45 , L_18 ) ;
V_7 = F_6 ( V_1 -> V_9 , V_73 ,
V_75 ) ;
if ( V_7 )
F_14 ( V_1 -> V_45 , L_4 ) ;
F_18 ( V_1 -> V_45 ) ;
F_19 ( V_1 -> V_45 ) ;
V_1 -> V_66 = false ;
return 0 ;
} else {
F_11 ( V_1 -> V_45 ) ;
V_1 -> V_66 = true ;
V_7 = F_6 ( V_1 -> V_9 , V_105 , 0 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_3 ( V_1 -> V_9 , V_73 ,
V_74 |
V_75 ,
V_74 |
V_75 ) ;
if ( V_7 )
return V_7 ;
V_1 -> V_76 = false ;
V_7 = F_6 ( V_1 -> V_9 , V_105 ,
V_106 |
V_107 |
V_108 |
V_109 |
V_110 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_2 ( V_1 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_43 ( V_1 -> V_9 , V_102 , & V_29 ) ;
if ( V_7 )
F_14 ( V_1 -> V_45 , L_17 ) ;
V_29 = V_111 ;
if ( V_1 -> V_112 )
V_29 |= V_113 ;
if ( V_1 -> V_114 )
V_29 |= V_115 ;
if ( V_1 -> V_116 )
V_29 |= V_117 ;
V_7 = F_6 ( V_1 -> V_9 , V_93 , V_29 ) ;
if ( V_7 )
return V_7 ;
}
return 0 ;
}
static int F_46 ( struct V_25 * V_26 , int V_58 )
{
struct V_1 * V_1 = F_10 ( V_26 ) ;
unsigned long V_118 ;
int V_7 ;
V_1 -> V_81 = F_47 ( & V_26 -> V_45 ,
L_19 ,
V_26 -> V_119 ,
V_26 -> V_120 ) ;
if ( ! V_1 -> V_81 )
return - V_121 ;
if ( F_48 ( V_1 -> V_45 -> V_122 , L_20 ) )
V_1 -> V_116 = true ;
V_118 = F_49 ( F_50 ( V_58 ) ) ;
switch ( V_118 ) {
case V_123 :
F_25 ( & V_26 -> V_45 ,
L_21 ) ;
if ( V_1 -> V_116 ) {
F_25 ( & V_26 -> V_45 ,
L_22 ) ;
V_1 -> V_116 = false ;
}
break;
case V_124 :
V_1 -> V_112 = true ;
F_25 ( & V_26 -> V_45 ,
L_23 ) ;
break;
case V_125 :
V_1 -> V_114 = true ;
F_25 ( & V_26 -> V_45 ,
L_24 ) ;
if ( V_1 -> V_116 ) {
F_25 ( & V_26 -> V_45 ,
L_25 ) ;
V_1 -> V_116 = false ;
}
V_118 |= V_126 ;
break;
case V_127 :
V_1 -> V_114 = true ;
V_1 -> V_112 = true ;
V_118 |= V_126 ;
F_25 ( & V_26 -> V_45 ,
L_26 ) ;
break;
default:
F_14 ( & V_26 -> V_45 ,
L_27
L_28 , V_118 ) ;
V_118 = V_123 ;
break;
}
if ( V_1 -> V_116 )
V_118 |= V_128 ;
V_7 = F_51 ( V_58 ,
F_40 ,
F_42 ,
V_118 ,
V_1 -> V_81 -> V_119 ,
V_1 -> V_81 ) ;
if ( V_7 ) {
F_14 ( V_1 -> V_45 ,
L_29 , V_58 , V_7 ) ;
return V_7 ;
}
V_1 -> V_58 = V_58 ;
V_1 -> V_81 -> V_45 . V_129 = V_1 -> V_45 ;
V_1 -> V_81 -> V_130 = & V_131 ;
F_52 ( V_1 -> V_81 , V_26 ) ;
V_7 = F_53 ( V_1 -> V_81 ) ;
if ( V_7 )
return V_7 ;
V_26 -> V_81 = F_54 ( V_1 -> V_81 ) ;
return 0 ;
}
int F_55 ( struct V_132 * V_45 ,
struct V_133 * V_9 ,
int V_58 ,
const char * V_119 )
{
struct V_25 * V_26 ;
struct V_1 * V_1 ;
unsigned int V_29 ;
int V_7 ;
V_26 = F_56 ( V_45 , sizeof( * V_1 ) ) ;
if ( ! V_26 )
return - V_121 ;
V_1 = F_10 ( V_26 ) ;
V_1 -> V_45 = V_45 ;
V_1 -> V_9 = V_9 ;
F_57 ( & V_1 -> V_46 ) ;
V_1 -> V_19 = V_54 ;
V_1 -> V_3 = V_134 ;
V_1 -> V_5 = 99 ;
V_7 = F_58 ( V_45 , L_30 ,
& V_1 -> V_84 ) ;
if ( V_7 )
return V_7 ;
V_1 -> V_97 [ 0 ] . V_135 = V_136 ;
V_1 -> V_97 [ 1 ] . V_135 = V_137 ;
V_7 = F_59 ( V_45 , F_37 ( V_1 -> V_97 ) ,
V_1 -> V_97 ) ;
if ( V_7 ) {
F_14 ( V_45 , L_31 ) ;
return V_7 ;
}
V_7 = F_35 ( V_1 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_43 ( V_9 , V_138 , & V_29 ) ;
if ( V_7 ) {
F_14 ( V_45 , L_32 ) ;
V_7 = - V_139 ;
goto V_140;
}
if ( V_29 != V_141 ) {
F_14 ( V_45 , L_33 , ( T_2 ) V_29 ) ;
V_7 = - V_139 ;
goto V_140;
}
V_7 = F_43 ( V_9 , V_142 , & V_29 ) ;
if ( V_7 ) {
F_14 ( V_45 , L_32 ) ;
V_7 = - V_139 ;
goto V_140;
}
F_25 ( V_45 , L_34 ,
( ( V_29 >> 4 ) & 0xf ) , ( V_29 & 0xf ) ) ;
V_7 = F_33 ( V_1 ) ;
if ( V_7 )
goto V_140;
V_26 -> V_45 . V_129 = V_45 ;
V_26 -> V_143 = V_144 ;
V_26 -> V_145 = F_37 ( V_144 ) ;
V_26 -> V_146 = & V_147 ;
V_26 -> V_148 = V_149 ;
V_26 -> V_150 = V_151 ;
V_26 -> V_119 = V_119 ;
V_7 = F_60 ( V_26 , V_152 ,
F_22 ,
& V_153 ) ;
if ( V_7 ) {
F_14 ( V_45 , L_35 ) ;
goto V_140;
}
V_7 = F_61 ( V_26 ) ;
if ( V_7 ) {
F_14 ( V_45 , L_36 ) ;
goto V_154;
}
F_62 ( V_45 , V_26 ) ;
if ( V_58 ) {
V_7 = F_46 ( V_26 , V_58 ) ;
if ( V_7 )
F_14 ( V_45 , L_37 ) ;
}
F_63 ( V_45 ) ;
F_64 ( V_45 ) ;
F_65 ( V_45 ) ;
F_66 ( V_45 , 10000 ) ;
F_67 ( V_45 ) ;
F_68 ( V_45 ) ;
return 0 ;
V_154:
F_69 ( V_26 ) ;
V_140:
F_38 ( V_1 ) ;
return V_7 ;
}
int F_70 ( struct V_132 * V_45 )
{
struct V_25 * V_26 = F_71 ( V_45 ) ;
struct V_1 * V_1 = F_10 ( V_26 ) ;
F_11 ( V_45 ) ;
F_72 ( V_45 ) ;
F_73 ( V_45 ) ;
F_69 ( V_26 ) ;
if ( V_1 -> V_58 )
F_74 ( V_1 -> V_58 , V_1 ) ;
F_75 ( V_26 ) ;
F_38 ( V_1 ) ;
return 0 ;
}
static int F_76 ( struct V_132 * V_45 )
{
return F_38 ( F_10 ( F_71 ( V_45 ) ) ) ;
}
static int F_77 ( struct V_132 * V_45 )
{
return F_35 ( F_10 ( F_71 ( V_45 ) ) ) ;
}
