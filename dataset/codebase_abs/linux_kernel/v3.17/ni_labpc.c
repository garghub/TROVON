static unsigned int F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static void F_3 ( struct V_1 * V_2 ,
unsigned int V_5 , unsigned long V_3 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static unsigned int F_5 ( struct V_1 * V_2 , unsigned long V_3 )
{
return F_6 ( V_2 -> V_6 + V_3 ) ;
}
static void F_7 ( struct V_1 * V_2 ,
unsigned int V_5 , unsigned long V_3 )
{
F_8 ( V_5 , V_2 -> V_6 + V_3 ) ;
}
static void F_9 ( struct V_1 * V_2 ,
unsigned long V_3 ,
unsigned int V_7 ,
unsigned int V_8 ,
unsigned int V_9 )
{
if ( V_2 -> V_6 ) {
F_10 ( V_2 -> V_6 + V_3 , 0 , V_7 , V_9 ) ;
F_11 ( V_2 -> V_6 + V_3 , 0 , V_7 , V_8 ) ;
} else {
F_12 ( V_2 -> V_4 + V_3 , 0 , V_7 , V_9 ) ;
F_13 ( V_2 -> V_4 + V_3 , 0 , V_7 , V_8 ) ;
}
}
static void F_14 ( struct V_1 * V_2 ,
unsigned long V_3 ,
unsigned int V_7 ,
unsigned int V_9 )
{
if ( V_2 -> V_6 )
F_10 ( V_2 -> V_6 + V_3 , 0 , V_7 , V_9 ) ;
else
F_12 ( V_2 -> V_4 + V_3 , 0 , V_7 , V_9 ) ;
}
static int F_15 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
unsigned long V_15 ;
F_16 ( & V_2 -> V_16 , V_15 ) ;
V_13 -> V_17 &= ~ ( V_18 | V_19 | V_20 ) ;
V_13 -> V_21 ( V_2 , V_13 -> V_17 , V_22 ) ;
F_17 ( & V_2 -> V_16 , V_15 ) ;
V_13 -> V_23 = 0 ;
V_13 -> V_21 ( V_2 , V_13 -> V_23 , V_24 ) ;
return 0 ;
}
static void F_18 ( struct V_1 * V_2 ,
enum V_25 V_9 ,
unsigned int V_26 ,
unsigned int V_27 ,
unsigned int V_28 )
{
const struct V_29 * V_30 = F_19 ( V_2 ) ;
struct V_12 * V_13 = V_2 -> V_14 ;
if ( V_30 -> V_31 ) {
V_27 += ( V_27 > 0 ) + ( V_27 > 7 ) ;
}
if ( ( V_9 == V_32 || V_9 == V_33 ) &&
V_28 == V_34 )
V_26 *= 2 ;
V_13 -> V_35 = F_20 ( V_26 ) ;
V_13 -> V_35 |= F_21 ( V_27 ) ;
V_13 -> V_21 ( V_2 , V_13 -> V_35 , V_36 ) ;
}
static void F_22 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
enum V_25 V_9 ,
enum V_37 V_38 ,
unsigned int V_27 ,
unsigned int V_28 ,
bool V_39 )
{
const struct V_29 * V_30 = F_19 ( V_2 ) ;
struct V_12 * V_13 = V_2 -> V_14 ;
if ( ! V_30 -> V_31 )
return;
if ( V_28 != V_40 )
V_13 -> V_41 |= V_42 ;
else
V_13 -> V_41 &= ~ V_42 ;
if ( F_23 ( V_11 , V_27 ) )
V_13 -> V_41 |= V_43 ;
else
V_13 -> V_41 &= ~ V_43 ;
if ( V_38 == V_44 )
V_13 -> V_41 |= V_45 ;
else
V_13 -> V_41 &= ~ V_45 ;
if ( V_39 )
V_13 -> V_41 |= V_46 ;
else
V_13 -> V_41 &= ~ V_46 ;
if ( V_9 == V_47 )
V_13 -> V_41 |= V_48 ;
else
V_13 -> V_41 &= ~ V_48 ;
V_13 -> V_21 ( V_2 , V_13 -> V_41 , V_49 ) ;
}
static unsigned int F_24 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
unsigned int V_50 = V_13 -> V_51 ( V_2 , V_52 ) ;
unsigned int V_53 = V_13 -> V_51 ( V_2 , V_52 ) ;
return ( V_53 << 8 ) | V_50 ;
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
V_13 -> V_21 ( V_2 , 0x1 , V_54 ) ;
F_24 ( V_2 ) ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_55 * V_56 ,
unsigned long V_57 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
V_13 -> V_58 = V_13 -> V_51 ( V_2 , V_59 ) ;
if ( V_13 -> V_58 & V_60 )
return 0 ;
return - V_61 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_55 * V_56 ,
unsigned int * V_62 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
unsigned int V_26 = F_28 ( V_56 -> V_63 ) ;
unsigned int V_27 = F_29 ( V_56 -> V_63 ) ;
unsigned int V_28 = F_30 ( V_56 -> V_63 ) ;
int V_64 ;
int V_65 ;
F_15 ( V_2 , V_11 ) ;
F_18 ( V_2 , V_32 , V_26 , V_27 , V_28 ) ;
F_22 ( V_2 , V_11 , V_32 , V_66 ,
V_27 , V_28 , false ) ;
V_13 -> V_67 = 0 ;
V_13 -> V_67 |= V_68 ;
if ( V_28 == V_34 )
V_13 -> V_67 |= V_69 ;
V_13 -> V_21 ( V_2 , V_13 -> V_67 , V_70 ) ;
F_14 ( V_2 , V_71 , 0 , V_72 ) ;
F_25 ( V_2 ) ;
for ( V_65 = 0 ; V_65 < V_56 -> V_73 ; V_65 ++ ) {
V_13 -> V_21 ( V_2 , 0x1 , V_74 ) ;
V_64 = F_31 ( V_2 , V_11 , V_56 , F_26 , 0 ) ;
if ( V_64 )
return V_64 ;
V_62 [ V_65 ] = F_24 ( V_2 ) ;
}
return V_56 -> V_73 ;
}
static bool F_32 ( const struct V_75 * V_76 ,
enum V_25 V_9 )
{
if ( V_9 == V_32 || V_76 -> V_77 == V_78 )
return true ;
return false ;
}
static unsigned int F_33 ( const struct V_75 * V_76 ,
enum V_25 V_9 )
{
if ( V_76 -> V_79 != V_80 )
return 0 ;
if ( V_9 == V_32 && V_76 -> V_77 == V_80 )
return V_76 -> V_81 ;
return V_76 -> V_82 ;
}
static void F_34 ( struct V_75 * V_76 ,
enum V_25 V_9 , unsigned int V_83 )
{
if ( V_76 -> V_79 != V_80 )
return;
if ( V_9 == V_32 &&
V_76 -> V_77 == V_80 ) {
V_76 -> V_81 = V_83 ;
if ( V_76 -> V_82 > V_76 -> V_81 )
V_76 -> V_82 = V_76 -> V_81 ;
} else
V_76 -> V_82 = V_83 ;
}
static unsigned int F_35 ( const struct V_75 * V_76 ,
enum V_25 V_9 )
{
if ( V_76 -> V_77 != V_80 )
return 0 ;
if ( V_9 == V_32 && V_76 -> V_79 == V_80 )
return 0 ;
return V_76 -> V_81 ;
}
static void F_36 ( struct V_75 * V_76 ,
enum V_25 V_9 , unsigned int V_83 )
{
if ( V_76 -> V_77 != V_80 )
return;
if ( V_9 == V_32 && V_76 -> V_79 == V_80 )
return;
V_76 -> V_81 = V_83 ;
}
static void F_37 ( struct V_1 * V_2 , struct V_75 * V_76 ,
enum V_25 V_9 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
const int V_84 = 0x10000 ;
const int V_85 = 2 ;
unsigned int V_86 ;
unsigned int V_87 ;
unsigned int V_88 ;
V_88 = F_33 ( V_76 , V_9 ) ;
V_87 = F_35 ( V_76 , V_9 ) ;
if ( V_88 && V_87 ) {
V_13 -> V_89 = ( V_87 - 1 ) /
( V_90 * V_84 ) + 1 ;
if ( V_13 -> V_89 < V_85 )
V_13 -> V_89 = V_85 ;
if ( V_13 -> V_89 > V_84 )
V_13 -> V_89 = V_84 ;
V_86 = V_90 * V_13 -> V_89 ;
switch ( V_76 -> V_15 & V_91 ) {
default:
case V_92 :
V_13 -> V_93 =
( V_88 + ( V_86 / 2 ) ) / V_86 ;
V_13 -> V_94 =
( V_87 + ( V_86 / 2 ) ) / V_86 ;
break;
case V_95 :
V_13 -> V_93 =
( V_88 + ( V_86 - 1 ) ) / V_86 ;
V_13 -> V_94 =
( V_87 + ( V_86 - 1 ) ) / V_86 ;
break;
case V_96 :
V_13 -> V_93 = V_88 / V_86 ;
V_13 -> V_94 = V_87 / V_86 ;
break;
}
if ( V_13 -> V_93 < V_85 )
V_13 -> V_93 = V_85 ;
if ( V_13 -> V_93 > V_84 )
V_13 -> V_93 = V_84 ;
if ( V_13 -> V_94 < V_85 )
V_13 -> V_94 = V_85 ;
if ( V_13 -> V_94 > V_84 )
V_13 -> V_94 = V_84 ;
F_34 ( V_76 , V_9 ,
V_86 * V_13 -> V_93 ) ;
F_36 ( V_76 , V_9 ,
V_86 * V_13 -> V_94 ) ;
} else if ( V_87 ) {
F_38 ( V_90 ,
& V_13 -> V_94 ,
& V_13 -> V_89 ,
& V_87 , V_76 -> V_15 ) ;
F_36 ( V_76 , V_9 , V_87 ) ;
} else if ( V_88 ) {
F_38 ( V_90 ,
& V_13 -> V_93 ,
& V_13 -> V_89 ,
& V_88 , V_76 -> V_15 ) ;
F_34 ( V_76 , V_9 , V_88 ) ;
}
}
static enum V_25 F_39 ( const struct V_75 * V_76 )
{
unsigned int V_97 ;
unsigned int V_98 ;
if ( V_76 -> V_99 == 1 )
return V_32 ;
if ( V_76 -> V_100 == NULL )
return V_47 ;
V_97 = F_28 ( V_76 -> V_100 [ 0 ] ) ;
V_98 = F_28 ( V_76 -> V_100 [ 1 ] ) ;
if ( V_97 < V_98 )
return V_47 ;
if ( V_97 > V_98 )
return V_101 ;
return V_33 ;
}
static int F_40 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_75 * V_76 )
{
enum V_25 V_9 = F_39 ( V_76 ) ;
unsigned int V_97 = F_28 ( V_76 -> V_100 [ 0 ] ) ;
unsigned int V_102 = F_29 ( V_76 -> V_100 [ 0 ] ) ;
unsigned int V_103 = F_30 ( V_76 -> V_100 [ 0 ] ) ;
int V_65 ;
if ( V_9 == V_32 )
return 0 ;
for ( V_65 = 0 ; V_65 < V_76 -> V_99 ; V_65 ++ ) {
unsigned int V_26 = F_28 ( V_76 -> V_100 [ V_65 ] ) ;
unsigned int V_27 = F_29 ( V_76 -> V_100 [ V_65 ] ) ;
unsigned int V_28 = F_30 ( V_76 -> V_100 [ V_65 ] ) ;
switch ( V_9 ) {
case V_32 :
break;
case V_33 :
if ( V_26 != V_97 ) {
F_41 ( V_2 -> V_104 ,
L_1 ) ;
return - V_105 ;
}
break;
case V_47 :
if ( V_26 != V_65 ) {
F_41 ( V_2 -> V_104 ,
L_1 ) ;
return - V_105 ;
}
break;
case V_101 :
if ( V_26 != ( V_76 -> V_99 - V_65 - 1 ) ) {
F_41 ( V_2 -> V_104 ,
L_1 ) ;
return - V_105 ;
}
break;
}
if ( V_27 != V_102 ) {
F_41 ( V_2 -> V_104 ,
L_2 ) ;
return - V_105 ;
}
if ( V_28 != V_103 ) {
F_41 ( V_2 -> V_104 ,
L_3 ) ;
return - V_105 ;
}
}
return 0 ;
}
static int F_42 ( struct V_1 * V_2 ,
struct V_10 * V_11 , struct V_75 * V_76 )
{
const struct V_29 * V_30 = F_19 ( V_2 ) ;
int V_106 = 0 ;
int V_107 , V_108 ;
unsigned int V_109 ;
enum V_25 V_9 ;
V_106 |= F_43 ( & V_76 -> V_110 , V_111 | V_112 ) ;
V_106 |= F_43 ( & V_76 -> V_77 ,
V_80 | V_78 | V_112 ) ;
V_106 |= F_43 ( & V_76 -> V_79 , V_80 | V_112 ) ;
V_106 |= F_43 ( & V_76 -> V_113 , V_114 ) ;
V_109 = V_114 | V_115 ;
if ( V_30 -> V_31 )
V_109 |= V_112 ;
V_106 |= F_43 ( & V_76 -> V_116 , V_109 ) ;
if ( V_106 )
return 1 ;
V_106 |= F_44 ( V_76 -> V_110 ) ;
V_106 |= F_44 ( V_76 -> V_77 ) ;
V_106 |= F_44 ( V_76 -> V_79 ) ;
V_106 |= F_44 ( V_76 -> V_116 ) ;
if ( V_76 -> V_110 == V_112 && V_76 -> V_116 == V_112 )
V_106 ++ ;
if ( V_106 )
return 2 ;
switch ( V_76 -> V_110 ) {
case V_111 :
V_106 |= F_45 ( & V_76 -> V_117 , 0 ) ;
break;
case V_112 :
break;
}
if ( ! V_76 -> V_99 )
V_106 |= - V_105 ;
V_106 |= F_45 ( & V_76 -> V_118 , V_76 -> V_99 ) ;
if ( V_76 -> V_79 == V_80 )
V_106 |= F_46 ( & V_76 -> V_82 ,
V_30 -> V_119 ) ;
if ( V_76 -> V_77 == V_80 ) {
if ( V_76 -> V_79 == V_80 )
V_106 |= F_46 ( & V_76 -> V_81 ,
V_76 -> V_82 * V_76 -> V_99 ) ;
V_106 |= F_46 ( & V_76 -> V_81 ,
V_30 -> V_119 * V_76 -> V_99 ) ;
}
switch ( V_76 -> V_116 ) {
case V_114 :
V_106 |= F_46 ( & V_76 -> V_120 , 1 ) ;
break;
case V_115 :
V_106 |= F_45 ( & V_76 -> V_120 , 0 ) ;
break;
default:
break;
}
if ( V_106 )
return 3 ;
V_107 = V_76 -> V_82 ;
V_108 = V_76 -> V_81 ;
V_9 = F_39 ( V_76 ) ;
F_37 ( V_2 , V_76 , V_9 ) ;
if ( V_107 != V_76 -> V_82 || V_108 != V_76 -> V_81 )
V_106 ++ ;
if ( V_106 )
return 4 ;
if ( V_76 -> V_100 && V_76 -> V_99 > 0 )
V_106 |= F_40 ( V_2 , V_11 , V_76 ) ;
if ( V_106 )
return 5 ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
const struct V_29 * V_30 = F_19 ( V_2 ) ;
struct V_12 * V_13 = V_2 -> V_14 ;
struct V_121 * V_122 = V_11 -> V_122 ;
struct V_75 * V_76 = & V_122 -> V_76 ;
enum V_25 V_9 = F_39 ( V_76 ) ;
unsigned int V_63 = ( V_9 == V_47 )
? V_76 -> V_100 [ V_76 -> V_99 - 1 ]
: V_76 -> V_100 [ 0 ] ;
unsigned int V_26 = F_28 ( V_63 ) ;
unsigned int V_27 = F_29 ( V_63 ) ;
unsigned int V_28 = F_30 ( V_63 ) ;
enum V_37 V_38 ;
unsigned long V_15 ;
F_15 ( V_2 , V_11 ) ;
if ( V_76 -> V_116 == V_114 )
V_13 -> V_8 = V_76 -> V_120 * V_76 -> V_99 ;
if ( V_76 -> V_116 == V_112 ) {
F_9 ( V_2 , V_71 ,
1 , 3 , V_123 ) ;
} else {
F_14 ( V_2 , V_71 , 1 , V_123 ) ;
}
if ( F_48 ( V_2 ) &&
( V_76 -> V_15 & ( V_124 | V_125 ) ) == 0 )
V_38 = V_126 ;
else if (
V_30 -> V_31 &&
( V_76 -> V_15 & V_124 ) == 0 &&
( V_76 -> V_116 != V_114 || V_13 -> V_8 > 256 ) )
V_38 = V_44 ;
else
V_38 = V_66 ;
V_13 -> V_127 = V_38 ;
F_18 ( V_2 , V_9 , V_26 , V_27 , V_28 ) ;
F_22 ( V_2 , V_11 , V_9 , V_38 , V_27 , V_28 ,
( V_76 -> V_116 == V_112 ) ) ;
if ( V_9 == V_47 || V_9 == V_101 ) {
V_13 -> V_35 |= V_128 ;
F_49 ( 1 ) ;
V_13 -> V_21 ( V_2 , V_13 -> V_35 , V_36 ) ;
}
V_13 -> V_21 ( V_2 , V_76 -> V_99 , V_129 ) ;
V_13 -> V_21 ( V_2 , 0x1 , V_130 ) ;
if ( V_76 -> V_79 == V_80 ||
V_76 -> V_77 == V_80 ) {
F_37 ( V_2 , V_76 , V_9 ) ;
F_9 ( V_2 , V_131 ,
0 , V_13 -> V_89 , V_132 ) ;
}
if ( F_33 ( V_76 , V_9 ) ) {
F_9 ( V_2 , V_71 ,
0 , V_13 -> V_93 , V_72 ) ;
} else {
F_14 ( V_2 , V_71 , 0 , V_72 ) ;
}
if ( F_35 ( V_76 , V_9 ) ) {
F_9 ( V_2 , V_131 ,
1 , V_13 -> V_94 , V_72 ) ;
}
F_25 ( V_2 ) ;
if ( V_38 == V_126 )
F_50 ( V_2 , V_11 ) ;
V_13 -> V_23 |= V_133 ;
if ( V_38 == V_66 )
V_13 -> V_23 |= V_134 ;
V_13 -> V_21 ( V_2 , V_13 -> V_23 , V_24 ) ;
V_13 -> V_67 = 0 ;
if ( V_76 -> V_79 != V_112 )
V_13 -> V_67 |= V_68 ;
if ( ! F_32 ( V_76 , V_9 ) ) {
V_13 -> V_67 |= V_135 ;
if ( V_76 -> V_77 == V_112 )
V_13 -> V_67 |= V_136 ;
}
if ( V_28 == V_34 )
V_13 -> V_67 |= V_69 ;
V_13 -> V_21 ( V_2 , V_13 -> V_67 , V_70 ) ;
F_16 ( & V_2 -> V_16 , V_15 ) ;
V_13 -> V_17 |= V_137 ;
V_13 -> V_17 &= ~ ( V_18 | V_19 | V_20 ) ;
if ( V_76 -> V_110 == V_112 )
V_13 -> V_17 |= V_19 ;
else
V_13 -> V_17 |= V_18 ;
if ( V_76 -> V_116 == V_112 )
V_13 -> V_17 |= ( V_19 | V_20 ) ;
V_13 -> V_21 ( V_2 , V_13 -> V_17 , V_22 ) ;
F_17 ( & V_2 -> V_16 , V_15 ) ;
return 0 ;
}
static int F_51 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
struct V_121 * V_122 = V_2 -> V_138 -> V_122 ;
struct V_75 * V_76 = & V_122 -> V_76 ;
unsigned short V_62 ;
const int V_139 = 10000 ;
unsigned int V_65 ;
V_13 -> V_58 = V_13 -> V_51 ( V_2 , V_59 ) ;
for ( V_65 = 0 ; ( V_13 -> V_58 & V_60 ) && V_65 < V_139 ;
V_65 ++ ) {
if ( V_76 -> V_116 == V_114 ) {
if ( V_13 -> V_8 == 0 )
break;
V_13 -> V_8 -- ;
}
V_62 = F_24 ( V_2 ) ;
F_52 ( V_2 -> V_138 , V_62 ) ;
V_13 -> V_58 = V_13 -> V_51 ( V_2 , V_59 ) ;
}
if ( V_65 == V_139 ) {
F_53 ( V_2 -> V_104 , L_4 ) ;
V_122 -> V_140 |= V_141 | V_142 ;
return - 1 ;
}
return 0 ;
}
static void F_54 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
if ( V_13 -> V_127 == V_126 )
F_55 ( V_2 ) ;
F_51 ( V_2 ) ;
}
static T_1 F_56 ( int V_143 , void * V_144 )
{
struct V_1 * V_2 = V_144 ;
const struct V_29 * V_30 = F_19 ( V_2 ) ;
struct V_12 * V_13 = V_2 -> V_14 ;
struct V_10 * V_11 = V_2 -> V_138 ;
struct V_121 * V_122 ;
struct V_75 * V_76 ;
if ( ! V_2 -> V_145 ) {
F_53 ( V_2 -> V_104 , L_5 ) ;
return V_146 ;
}
V_122 = V_11 -> V_122 ;
V_76 = & V_122 -> V_76 ;
V_13 -> V_58 = V_13 -> V_51 ( V_2 , V_59 ) ;
if ( V_30 -> V_31 )
V_13 -> V_147 = V_13 -> V_51 ( V_2 , V_148 ) ;
if ( ( V_13 -> V_58 & ( V_149 | V_150 | V_151 |
V_152 | V_60 ) ) == 0
&& ( V_13 -> V_147 & V_153 ) == 0
&& ( V_13 -> V_147 & V_154 ) ) {
return V_155 ;
}
if ( V_13 -> V_58 & V_152 ) {
V_13 -> V_21 ( V_2 , 0x1 , V_54 ) ;
V_122 -> V_140 |= V_141 | V_142 ;
F_57 ( V_2 , V_11 ) ;
F_53 ( V_2 -> V_104 , L_6 ) ;
return V_146 ;
}
if ( V_13 -> V_127 == V_126 )
F_58 ( V_2 ) ;
else
F_51 ( V_2 ) ;
if ( V_13 -> V_58 & V_150 ) {
F_53 ( V_2 -> V_104 , L_7 ) ;
V_13 -> V_21 ( V_2 , 0x1 , V_156 ) ;
}
if ( V_13 -> V_58 & V_151 ) {
V_13 -> V_21 ( V_2 , 0x1 , V_54 ) ;
V_122 -> V_140 |= V_141 | V_142 ;
F_57 ( V_2 , V_11 ) ;
F_53 ( V_2 -> V_104 , L_8 ) ;
return V_146 ;
}
if ( V_76 -> V_116 == V_112 ) {
if ( V_13 -> V_147 & V_153 ) {
F_54 ( V_2 ) ;
V_122 -> V_140 |= V_142 ;
}
}
if ( V_76 -> V_116 == V_114 ) {
if ( V_13 -> V_8 == 0 )
V_122 -> V_140 |= V_142 ;
}
F_57 ( V_2 , V_11 ) ;
return V_146 ;
}
static int F_59 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_55 * V_56 ,
unsigned int * V_62 )
{
const struct V_29 * V_30 = F_19 ( V_2 ) ;
struct V_12 * V_13 = V_2 -> V_14 ;
int V_157 , V_27 ;
unsigned long V_15 ;
int V_50 , V_53 ;
V_157 = F_28 ( V_56 -> V_63 ) ;
F_16 ( & V_2 -> V_16 , V_15 ) ;
V_13 -> V_17 &= ~ F_60 ( V_157 ) ;
V_13 -> V_21 ( V_2 , V_13 -> V_17 , V_22 ) ;
F_17 ( & V_2 -> V_16 , V_15 ) ;
if ( V_30 -> V_31 ) {
V_27 = F_29 ( V_56 -> V_63 ) ;
if ( F_23 ( V_11 , V_27 ) )
V_13 -> V_41 |= F_61 ( V_157 ) ;
else
V_13 -> V_41 &= ~ F_61 ( V_157 ) ;
V_13 -> V_21 ( V_2 , V_13 -> V_41 , V_49 ) ;
}
V_50 = V_62 [ 0 ] & 0xff ;
V_53 = ( V_62 [ 0 ] >> 8 ) & 0xff ;
V_13 -> V_21 ( V_2 , V_50 , F_62 ( V_157 ) ) ;
V_13 -> V_21 ( V_2 , V_53 , F_63 ( V_157 ) ) ;
V_13 -> V_158 [ V_157 ] = V_62 [ 0 ] ;
return 1 ;
}
static int F_64 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_55 * V_56 ,
unsigned int * V_62 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
V_62 [ 0 ] = V_13 -> V_158 [ F_28 ( V_56 -> V_63 ) ] ;
return 1 ;
}
static int F_65 ( int V_159 , int V_160 , int V_62 , unsigned long V_161 )
{
struct V_1 * V_2 = (struct V_1 * ) V_161 ;
if ( V_159 ) {
F_8 ( V_62 , V_2 -> V_6 + V_162 + V_160 ) ;
return 0 ;
}
return F_6 ( V_2 -> V_6 + V_162 + V_160 ) ;
}
static void F_66 ( struct V_1 * V_2 , unsigned int V_163 ,
unsigned int V_164 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
int V_65 ;
for ( V_65 = 1 ; V_65 <= V_164 ; V_65 ++ ) {
V_13 -> V_165 &= ~ V_166 ;
if ( V_163 & ( 1 << ( V_164 - V_65 ) ) )
V_13 -> V_165 |= V_167 ;
else
V_13 -> V_165 &= ~ V_167 ;
F_49 ( 1 ) ;
V_13 -> V_21 ( V_2 , V_13 -> V_165 , V_168 ) ;
V_13 -> V_165 |= V_166 ;
F_49 ( 1 ) ;
V_13 -> V_21 ( V_2 , V_13 -> V_165 , V_168 ) ;
}
}
static unsigned int F_67 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
unsigned int V_163 = 0 ;
int V_65 ;
const int V_164 = 8 ;
for ( V_65 = 1 ; V_65 <= V_164 ; V_65 ++ ) {
V_13 -> V_165 |= V_166 ;
F_49 ( 1 ) ;
V_13 -> V_21 ( V_2 , V_13 -> V_165 , V_168 ) ;
V_13 -> V_165 &= ~ V_166 ;
F_49 ( 1 ) ;
V_13 -> V_21 ( V_2 , V_13 -> V_165 , V_168 ) ;
F_49 ( 1 ) ;
V_13 -> V_147 = V_13 -> V_51 ( V_2 , V_148 ) ;
if ( V_13 -> V_147 & V_169 )
V_163 |= 1 << ( V_164 - V_65 ) ;
}
return V_163 ;
}
static unsigned int F_68 ( struct V_1 * V_2 ,
unsigned int V_170 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
unsigned int V_163 ;
const int V_171 = 0x3 ;
const int V_172 = 8 ;
V_13 -> V_165 &= ~ V_173 ;
F_49 ( 1 ) ;
V_13 -> V_21 ( V_2 , V_13 -> V_165 , V_168 ) ;
V_13 -> V_165 |= ( V_173 | V_174 ) ;
F_49 ( 1 ) ;
V_13 -> V_21 ( V_2 , V_13 -> V_165 , V_168 ) ;
F_66 ( V_2 , V_171 , V_172 ) ;
F_66 ( V_2 , V_170 , V_172 ) ;
V_163 = F_67 ( V_2 ) ;
V_13 -> V_165 &= ~ ( V_173 | V_174 ) ;
F_49 ( 1 ) ;
V_13 -> V_21 ( V_2 , V_13 -> V_165 , V_168 ) ;
return V_163 ;
}
static unsigned int F_69 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
unsigned int V_163 ;
const int V_175 = 0x5 ;
const int V_172 = 8 ;
V_13 -> V_165 &= ~ V_173 ;
F_49 ( 1 ) ;
V_13 -> V_21 ( V_2 , V_13 -> V_165 , V_168 ) ;
V_13 -> V_165 |= ( V_173 | V_174 ) ;
F_49 ( 1 ) ;
V_13 -> V_21 ( V_2 , V_13 -> V_165 , V_168 ) ;
F_66 ( V_2 , V_175 , V_172 ) ;
V_163 = F_67 ( V_2 ) ;
V_13 -> V_165 &= ~ ( V_173 | V_174 ) ;
F_49 ( 1 ) ;
V_13 -> V_21 ( V_2 , V_13 -> V_165 , V_168 ) ;
return V_163 ;
}
static int F_70 ( struct V_1 * V_2 ,
unsigned int V_170 , unsigned int V_163 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
const int V_176 = 0x6 ;
const int V_177 = 0x2 ;
const int V_172 = 8 ;
const int V_178 = 0x1 ;
const int V_139 = 10000 ;
int V_65 ;
for ( V_65 = 0 ; V_65 < V_139 ; V_65 ++ ) {
if ( ( F_69 ( V_2 ) & V_178 ) ==
0 )
break;
}
if ( V_65 == V_139 ) {
F_53 ( V_2 -> V_104 , L_9 ) ;
return - V_179 ;
}
V_13 -> V_180 [ V_170 ] = V_163 ;
V_13 -> V_165 &= ~ V_173 ;
F_49 ( 1 ) ;
V_13 -> V_21 ( V_2 , V_13 -> V_165 , V_168 ) ;
V_13 -> V_165 |= ( V_173 | V_174 ) ;
F_49 ( 1 ) ;
V_13 -> V_21 ( V_2 , V_13 -> V_165 , V_168 ) ;
F_66 ( V_2 , V_176 , V_172 ) ;
V_13 -> V_165 &= ~ V_173 ;
F_49 ( 1 ) ;
V_13 -> V_21 ( V_2 , V_13 -> V_165 , V_168 ) ;
V_13 -> V_165 |= V_173 ;
F_49 ( 1 ) ;
V_13 -> V_21 ( V_2 , V_13 -> V_165 , V_168 ) ;
F_66 ( V_2 , V_177 , V_172 ) ;
F_66 ( V_2 , V_170 , V_172 ) ;
F_66 ( V_2 , V_163 , V_172 ) ;
V_13 -> V_165 &= ~ V_173 ;
F_49 ( 1 ) ;
V_13 -> V_21 ( V_2 , V_13 -> V_165 , V_168 ) ;
V_13 -> V_165 &= ~ ( V_173 | V_174 ) ;
F_49 ( 1 ) ;
V_13 -> V_21 ( V_2 , V_13 -> V_165 , V_168 ) ;
return 0 ;
}
static void F_71 ( struct V_1 * V_2 , unsigned int V_157 ,
unsigned int V_163 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
if ( V_163 == V_13 -> V_181 [ V_157 ] )
return;
V_13 -> V_181 [ V_157 ] = V_163 ;
V_13 -> V_165 &= ~ ( V_182 | V_173 | V_174 ) ;
F_49 ( 1 ) ;
V_13 -> V_21 ( V_2 , V_13 -> V_165 , V_168 ) ;
F_66 ( V_2 , V_157 , 4 ) ;
F_66 ( V_2 , V_163 , 8 ) ;
V_13 -> V_165 |= V_182 ;
F_49 ( 1 ) ;
V_13 -> V_21 ( V_2 , V_13 -> V_165 , V_168 ) ;
V_13 -> V_165 &= ~ V_182 ;
F_49 ( 1 ) ;
V_13 -> V_21 ( V_2 , V_13 -> V_165 , V_168 ) ;
}
static int F_72 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_55 * V_56 ,
unsigned int * V_62 )
{
unsigned int V_26 = F_28 ( V_56 -> V_63 ) ;
if ( V_56 -> V_73 > 0 )
F_71 ( V_2 , V_26 , V_62 [ V_56 -> V_73 - 1 ] ) ;
return V_56 -> V_73 ;
}
static int F_73 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_55 * V_56 ,
unsigned int * V_62 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
unsigned int V_26 = F_28 ( V_56 -> V_63 ) ;
int V_65 ;
for ( V_65 = 0 ; V_65 < V_56 -> V_73 ; V_65 ++ )
V_62 [ V_65 ] = V_13 -> V_181 [ V_26 ] ;
return V_56 -> V_73 ;
}
static int F_74 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_55 * V_56 ,
unsigned int * V_62 )
{
unsigned int V_26 = F_28 ( V_56 -> V_63 ) ;
int V_64 ;
if ( V_26 < 16 || V_26 > 127 )
return - V_105 ;
if ( V_56 -> V_73 > 0 ) {
V_64 = F_70 ( V_2 , V_26 , V_62 [ V_56 -> V_73 - 1 ] ) ;
if ( V_64 )
return V_64 ;
}
return V_56 -> V_73 ;
}
static int F_75 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_55 * V_56 ,
unsigned int * V_62 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
unsigned int V_26 = F_28 ( V_56 -> V_63 ) ;
int V_65 ;
for ( V_65 = 0 ; V_65 < V_56 -> V_73 ; V_65 ++ )
V_62 [ V_65 ] = V_13 -> V_180 [ V_26 ] ;
return V_56 -> V_73 ;
}
int F_76 ( struct V_1 * V_2 ,
unsigned int V_143 , unsigned long V_183 )
{
const struct V_29 * V_30 = F_19 ( V_2 ) ;
struct V_12 * V_13 = V_2 -> V_14 ;
struct V_10 * V_11 ;
int V_64 ;
int V_65 ;
if ( V_2 -> V_6 ) {
V_13 -> V_51 = F_5 ;
V_13 -> V_21 = F_7 ;
} else {
V_13 -> V_51 = F_1 ;
V_13 -> V_21 = F_3 ;
}
V_13 -> V_21 ( V_2 , V_13 -> V_35 , V_36 ) ;
V_13 -> V_21 ( V_2 , V_13 -> V_17 , V_22 ) ;
V_13 -> V_21 ( V_2 , V_13 -> V_23 , V_24 ) ;
V_13 -> V_21 ( V_2 , V_13 -> V_67 , V_70 ) ;
if ( V_30 -> V_31 ) {
V_13 -> V_21 ( V_2 , V_13 -> V_165 , V_168 ) ;
V_13 -> V_21 ( V_2 , V_13 -> V_41 , V_49 ) ;
}
if ( V_143 ) {
V_64 = F_77 ( V_143 , F_56 , V_183 ,
V_2 -> V_184 , V_2 ) ;
if ( V_64 == 0 )
V_2 -> V_143 = V_143 ;
}
V_64 = F_78 ( V_2 , 5 ) ;
if ( V_64 )
return V_64 ;
V_11 = & V_2 -> V_185 [ 0 ] ;
V_11 -> type = V_186 ;
V_11 -> V_187 = V_188 | V_189 | V_190 | V_191 ;
V_11 -> V_192 = 8 ;
V_11 -> V_193 = 8 ;
V_11 -> V_194 = 0x0fff ;
V_11 -> V_195 = V_30 -> V_31
? & V_196 : & V_197 ;
V_11 -> V_198 = F_27 ;
if ( V_2 -> V_143 ) {
V_2 -> V_138 = V_11 ;
V_11 -> V_187 |= V_199 ;
V_11 -> V_200 = F_47 ;
V_11 -> V_201 = F_42 ;
V_11 -> V_202 = F_15 ;
}
V_11 = & V_2 -> V_185 [ 1 ] ;
if ( V_30 -> V_203 ) {
V_11 -> type = V_204 ;
V_11 -> V_187 = V_188 | V_205 | V_189 ;
V_11 -> V_192 = V_206 ;
V_11 -> V_194 = 0x0fff ;
V_11 -> V_195 = & V_207 ;
V_11 -> V_198 = F_64 ;
V_11 -> V_208 = F_59 ;
for ( V_65 = 0 ; V_65 < V_11 -> V_192 ; V_65 ++ ) {
short V_50 , V_53 ;
V_13 -> V_158 [ V_65 ] = V_11 -> V_194 / 2 ;
V_50 = V_13 -> V_158 [ V_65 ] & 0xff ;
V_53 = ( V_13 -> V_158 [ V_65 ] >> 8 ) & 0xff ;
V_13 -> V_21 ( V_2 , V_50 , F_62 ( V_65 ) ) ;
V_13 -> V_21 ( V_2 , V_53 , F_63 ( V_65 ) ) ;
}
} else {
V_11 -> type = V_209 ;
}
V_11 = & V_2 -> V_185 [ 2 ] ;
if ( V_2 -> V_6 ) {
V_64 = F_79 ( V_2 , V_11 , F_65 ,
( unsigned long ) V_2 ) ;
} else {
V_64 = F_79 ( V_2 , V_11 , NULL ,
V_2 -> V_4 + V_162 ) ;
}
if ( V_64 )
return V_64 ;
V_11 = & V_2 -> V_185 [ 3 ] ;
if ( V_30 -> V_31 ) {
V_11 -> type = V_210 ;
V_11 -> V_187 = V_188 | V_205 | V_211 ;
V_11 -> V_192 = 16 ;
V_11 -> V_194 = 0xff ;
V_11 -> V_198 = F_73 ;
V_11 -> V_208 = F_72 ;
for ( V_65 = 0 ; V_65 < V_11 -> V_192 ; V_65 ++ )
F_71 ( V_2 , V_65 , V_11 -> V_194 / 2 ) ;
} else
V_11 -> type = V_209 ;
V_11 = & V_2 -> V_185 [ 4 ] ;
if ( V_30 -> V_31 ) {
V_11 -> type = V_212 ;
V_11 -> V_187 = V_188 | V_205 | V_211 ;
V_11 -> V_192 = V_213 ;
V_11 -> V_194 = 0xff ;
V_11 -> V_198 = F_75 ;
V_11 -> V_208 = F_74 ;
for ( V_65 = 0 ; V_65 < V_11 -> V_192 ; V_65 ++ )
V_13 -> V_180 [ V_65 ] = F_68 ( V_2 , V_65 ) ;
} else
V_11 -> type = V_209 ;
return 0 ;
}
static int F_80 ( struct V_1 * V_2 , struct V_214 * V_215 )
{
struct V_12 * V_13 ;
unsigned int V_143 = V_215 -> V_216 [ 1 ] ;
unsigned int V_217 = V_215 -> V_216 [ 2 ] ;
int V_64 ;
V_13 = F_81 ( V_2 , sizeof( * V_13 ) ) ;
if ( ! V_13 )
return - V_218 ;
V_64 = F_82 ( V_2 , V_215 -> V_216 [ 0 ] , 0x20 ) ;
if ( V_64 )
return V_64 ;
V_64 = F_76 ( V_2 , V_143 , 0 ) ;
if ( V_64 )
return V_64 ;
if ( V_2 -> V_143 )
F_83 ( V_2 , V_217 ) ;
return 0 ;
}
static void F_84 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
if ( V_13 )
F_85 ( V_2 ) ;
F_86 ( V_2 ) ;
}
static int T_2 F_87 ( void )
{
return 0 ;
}
static void T_3 F_88 ( void )
{
}
