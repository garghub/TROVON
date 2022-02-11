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
const struct V_29 * V_30 = V_2 -> V_31 ;
struct V_12 * V_13 = V_2 -> V_14 ;
if ( V_30 -> V_32 ) {
V_27 += ( V_27 > 0 ) + ( V_27 > 7 ) ;
}
if ( ( V_9 == V_33 || V_9 == V_34 ) &&
V_28 == V_35 )
V_26 *= 2 ;
V_13 -> V_36 = F_19 ( V_26 ) ;
V_13 -> V_36 |= F_20 ( V_27 ) ;
V_13 -> V_21 ( V_2 , V_13 -> V_36 , V_37 ) ;
}
static void F_21 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
enum V_25 V_9 ,
enum V_38 V_39 ,
unsigned int V_27 ,
unsigned int V_28 ,
bool V_40 )
{
const struct V_29 * V_30 = V_2 -> V_31 ;
struct V_12 * V_13 = V_2 -> V_14 ;
if ( ! V_30 -> V_32 )
return;
if ( V_28 != V_41 )
V_13 -> V_42 |= V_43 ;
else
V_13 -> V_42 &= ~ V_43 ;
if ( F_22 ( V_11 , V_27 ) )
V_13 -> V_42 |= V_44 ;
else
V_13 -> V_42 &= ~ V_44 ;
if ( V_39 == V_45 )
V_13 -> V_42 |= V_46 ;
else
V_13 -> V_42 &= ~ V_46 ;
if ( V_40 )
V_13 -> V_42 |= V_47 ;
else
V_13 -> V_42 &= ~ V_47 ;
if ( V_9 == V_48 )
V_13 -> V_42 |= V_49 ;
else
V_13 -> V_42 &= ~ V_49 ;
V_13 -> V_21 ( V_2 , V_13 -> V_42 , V_50 ) ;
}
static unsigned int F_23 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
unsigned int V_51 = V_13 -> V_52 ( V_2 , V_53 ) ;
unsigned int V_54 = V_13 -> V_52 ( V_2 , V_53 ) ;
return ( V_54 << 8 ) | V_51 ;
}
static void F_24 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
V_13 -> V_21 ( V_2 , 0x1 , V_55 ) ;
F_23 ( V_2 ) ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_56 * V_57 ,
unsigned long V_58 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
V_13 -> V_59 = V_13 -> V_52 ( V_2 , V_60 ) ;
if ( V_13 -> V_59 & V_61 )
return 0 ;
return - V_62 ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_56 * V_57 ,
unsigned int * V_63 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
unsigned int V_26 = F_27 ( V_57 -> V_64 ) ;
unsigned int V_27 = F_28 ( V_57 -> V_64 ) ;
unsigned int V_28 = F_29 ( V_57 -> V_64 ) ;
int V_65 ;
int V_66 ;
F_15 ( V_2 , V_11 ) ;
F_18 ( V_2 , V_33 , V_26 , V_27 , V_28 ) ;
F_21 ( V_2 , V_11 , V_33 , V_67 ,
V_27 , V_28 , false ) ;
V_13 -> V_68 = 0 ;
V_13 -> V_68 |= V_69 ;
if ( V_28 == V_35 )
V_13 -> V_68 |= V_70 ;
V_13 -> V_21 ( V_2 , V_13 -> V_68 , V_71 ) ;
F_14 ( V_2 , V_72 , 0 , V_73 ) ;
F_24 ( V_2 ) ;
for ( V_66 = 0 ; V_66 < V_57 -> V_74 ; V_66 ++ ) {
V_13 -> V_21 ( V_2 , 0x1 , V_75 ) ;
V_65 = F_30 ( V_2 , V_11 , V_57 , F_25 , 0 ) ;
if ( V_65 )
return V_65 ;
V_63 [ V_66 ] = F_23 ( V_2 ) ;
}
return V_57 -> V_74 ;
}
static bool F_31 ( const struct V_76 * V_77 ,
enum V_25 V_9 )
{
if ( V_9 == V_33 || V_77 -> V_78 == V_79 )
return true ;
return false ;
}
static unsigned int F_32 ( const struct V_76 * V_77 ,
enum V_25 V_9 )
{
if ( V_77 -> V_80 != V_81 )
return 0 ;
if ( V_9 == V_33 && V_77 -> V_78 == V_81 )
return V_77 -> V_82 ;
return V_77 -> V_83 ;
}
static void F_33 ( struct V_76 * V_77 ,
enum V_25 V_9 , unsigned int V_84 )
{
if ( V_77 -> V_80 != V_81 )
return;
if ( V_9 == V_33 &&
V_77 -> V_78 == V_81 ) {
V_77 -> V_82 = V_84 ;
if ( V_77 -> V_83 > V_77 -> V_82 )
V_77 -> V_83 = V_77 -> V_82 ;
} else {
V_77 -> V_83 = V_84 ;
}
}
static unsigned int F_34 ( const struct V_76 * V_77 ,
enum V_25 V_9 )
{
if ( V_77 -> V_78 != V_81 )
return 0 ;
if ( V_9 == V_33 && V_77 -> V_80 == V_81 )
return 0 ;
return V_77 -> V_82 ;
}
static void F_35 ( struct V_76 * V_77 ,
enum V_25 V_9 , unsigned int V_84 )
{
if ( V_77 -> V_78 != V_81 )
return;
if ( V_9 == V_33 && V_77 -> V_80 == V_81 )
return;
V_77 -> V_82 = V_84 ;
}
static void F_36 ( struct V_1 * V_2 , struct V_76 * V_77 ,
enum V_25 V_9 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
unsigned int V_85 ;
unsigned int V_86 ;
unsigned int V_87 ;
V_87 = F_32 ( V_77 , V_9 ) ;
V_86 = F_34 ( V_77 , V_9 ) ;
if ( V_87 && V_86 ) {
V_13 -> V_88 = ( V_86 - 1 ) /
( V_89 * 0x10000 ) + 1 ;
F_37 ( & V_13 -> V_88 , 2 ) ;
F_38 ( & V_13 -> V_88 , 0x10000 ) ;
V_85 = V_89 * V_13 -> V_88 ;
switch ( V_77 -> V_15 & V_90 ) {
default:
case V_91 :
V_13 -> V_92 = F_39 ( V_87 ,
V_85 ) ;
V_13 -> V_93 = F_39 ( V_86 ,
V_85 ) ;
break;
case V_94 :
V_13 -> V_92 = F_40 ( V_87 ,
V_85 ) ;
V_13 -> V_93 = F_40 ( V_86 ,
V_85 ) ;
break;
case V_95 :
V_13 -> V_92 = V_87 / V_85 ;
V_13 -> V_93 = V_86 / V_85 ;
break;
}
F_37 ( & V_13 -> V_92 , 2 ) ;
F_38 ( & V_13 -> V_92 , 0x10000 ) ;
F_37 ( & V_13 -> V_93 , 2 ) ;
F_38 ( & V_13 -> V_93 , 0x10000 ) ;
F_33 ( V_77 , V_9 ,
V_85 * V_13 -> V_92 ) ;
F_35 ( V_77 , V_9 ,
V_85 * V_13 -> V_93 ) ;
} else if ( V_86 ) {
F_41 ( V_89 ,
& V_13 -> V_93 ,
& V_13 -> V_88 ,
& V_86 , V_77 -> V_15 ) ;
F_35 ( V_77 , V_9 , V_86 ) ;
} else if ( V_87 ) {
F_41 ( V_89 ,
& V_13 -> V_92 ,
& V_13 -> V_88 ,
& V_87 , V_77 -> V_15 ) ;
F_33 ( V_77 , V_9 , V_87 ) ;
}
}
static enum V_25 F_42 ( const struct V_76 * V_77 )
{
unsigned int V_96 ;
unsigned int V_97 ;
if ( V_77 -> V_98 == 1 )
return V_33 ;
if ( V_77 -> V_99 == NULL )
return V_48 ;
V_96 = F_27 ( V_77 -> V_99 [ 0 ] ) ;
V_97 = F_27 ( V_77 -> V_99 [ 1 ] ) ;
if ( V_96 < V_97 )
return V_48 ;
if ( V_96 > V_97 )
return V_100 ;
return V_34 ;
}
static int F_43 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_76 * V_77 )
{
enum V_25 V_9 = F_42 ( V_77 ) ;
unsigned int V_96 = F_27 ( V_77 -> V_99 [ 0 ] ) ;
unsigned int V_101 = F_28 ( V_77 -> V_99 [ 0 ] ) ;
unsigned int V_102 = F_29 ( V_77 -> V_99 [ 0 ] ) ;
int V_66 ;
if ( V_9 == V_33 )
return 0 ;
for ( V_66 = 0 ; V_66 < V_77 -> V_98 ; V_66 ++ ) {
unsigned int V_26 = F_27 ( V_77 -> V_99 [ V_66 ] ) ;
unsigned int V_27 = F_28 ( V_77 -> V_99 [ V_66 ] ) ;
unsigned int V_28 = F_29 ( V_77 -> V_99 [ V_66 ] ) ;
switch ( V_9 ) {
case V_33 :
break;
case V_34 :
if ( V_26 != V_96 ) {
F_44 ( V_2 -> V_103 ,
L_1 ) ;
return - V_104 ;
}
break;
case V_48 :
if ( V_26 != V_66 ) {
F_44 ( V_2 -> V_103 ,
L_1 ) ;
return - V_104 ;
}
break;
case V_100 :
if ( V_26 != ( V_77 -> V_98 - V_66 - 1 ) ) {
F_44 ( V_2 -> V_103 ,
L_1 ) ;
return - V_104 ;
}
break;
}
if ( V_27 != V_101 ) {
F_44 ( V_2 -> V_103 ,
L_2 ) ;
return - V_104 ;
}
if ( V_28 != V_102 ) {
F_44 ( V_2 -> V_103 ,
L_3 ) ;
return - V_104 ;
}
}
return 0 ;
}
static int F_45 ( struct V_1 * V_2 ,
struct V_10 * V_11 , struct V_76 * V_77 )
{
const struct V_29 * V_30 = V_2 -> V_31 ;
int V_105 = 0 ;
int V_106 , V_107 ;
unsigned int V_108 ;
enum V_25 V_9 ;
V_105 |= F_46 ( & V_77 -> V_109 , V_110 | V_111 ) ;
V_105 |= F_46 ( & V_77 -> V_78 ,
V_81 | V_79 | V_111 ) ;
V_105 |= F_46 ( & V_77 -> V_80 , V_81 | V_111 ) ;
V_105 |= F_46 ( & V_77 -> V_112 , V_113 ) ;
V_108 = V_113 | V_114 ;
if ( V_30 -> V_32 )
V_108 |= V_111 ;
V_105 |= F_46 ( & V_77 -> V_115 , V_108 ) ;
if ( V_105 )
return 1 ;
V_105 |= F_47 ( V_77 -> V_109 ) ;
V_105 |= F_47 ( V_77 -> V_78 ) ;
V_105 |= F_47 ( V_77 -> V_80 ) ;
V_105 |= F_47 ( V_77 -> V_115 ) ;
if ( V_77 -> V_109 == V_111 && V_77 -> V_115 == V_111 )
V_105 ++ ;
if ( V_105 )
return 2 ;
switch ( V_77 -> V_109 ) {
case V_110 :
V_105 |= F_48 ( & V_77 -> V_116 , 0 ) ;
break;
case V_111 :
break;
}
if ( ! V_77 -> V_98 )
V_105 |= - V_104 ;
V_105 |= F_48 ( & V_77 -> V_117 , V_77 -> V_98 ) ;
if ( V_77 -> V_80 == V_81 )
V_105 |= F_37 ( & V_77 -> V_83 ,
V_30 -> V_118 ) ;
if ( V_77 -> V_78 == V_81 ) {
if ( V_77 -> V_80 == V_81 )
V_105 |= F_37 ( & V_77 -> V_82 ,
V_77 -> V_83 * V_77 -> V_98 ) ;
V_105 |= F_37 ( & V_77 -> V_82 ,
V_30 -> V_118 * V_77 -> V_98 ) ;
}
switch ( V_77 -> V_115 ) {
case V_113 :
V_105 |= F_37 ( & V_77 -> V_119 , 1 ) ;
break;
case V_114 :
V_105 |= F_48 ( & V_77 -> V_119 , 0 ) ;
break;
default:
break;
}
if ( V_105 )
return 3 ;
V_106 = V_77 -> V_83 ;
V_107 = V_77 -> V_82 ;
V_9 = F_42 ( V_77 ) ;
F_36 ( V_2 , V_77 , V_9 ) ;
if ( V_106 != V_77 -> V_83 || V_107 != V_77 -> V_82 )
V_105 ++ ;
if ( V_105 )
return 4 ;
if ( V_77 -> V_99 && V_77 -> V_98 > 0 )
V_105 |= F_43 ( V_2 , V_11 , V_77 ) ;
if ( V_105 )
return 5 ;
return 0 ;
}
static int F_49 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
const struct V_29 * V_30 = V_2 -> V_31 ;
struct V_12 * V_13 = V_2 -> V_14 ;
struct V_120 * V_121 = V_11 -> V_121 ;
struct V_76 * V_77 = & V_121 -> V_77 ;
enum V_25 V_9 = F_42 ( V_77 ) ;
unsigned int V_64 = ( V_9 == V_48 ) ?
V_77 -> V_99 [ V_77 -> V_98 - 1 ] :
V_77 -> V_99 [ 0 ] ;
unsigned int V_26 = F_27 ( V_64 ) ;
unsigned int V_27 = F_28 ( V_64 ) ;
unsigned int V_28 = F_29 ( V_64 ) ;
enum V_38 V_39 ;
unsigned long V_15 ;
F_15 ( V_2 , V_11 ) ;
if ( V_77 -> V_115 == V_113 )
V_13 -> V_8 = V_77 -> V_119 * V_77 -> V_98 ;
if ( V_77 -> V_115 == V_111 ) {
F_9 ( V_2 , V_72 ,
1 , 3 , V_122 ) ;
} else {
F_14 ( V_2 , V_72 , 1 , V_122 ) ;
}
if ( V_13 -> V_123 &&
( V_77 -> V_15 & ( V_124 | V_125 ) ) == 0 )
V_39 = V_126 ;
else if (
V_30 -> V_32 &&
( V_77 -> V_15 & V_124 ) == 0 &&
( V_77 -> V_115 != V_113 || V_13 -> V_8 > 256 ) )
V_39 = V_45 ;
else
V_39 = V_67 ;
V_13 -> V_127 = V_39 ;
F_18 ( V_2 , V_9 , V_26 , V_27 , V_28 ) ;
F_21 ( V_2 , V_11 , V_9 , V_39 , V_27 , V_28 ,
( V_77 -> V_115 == V_111 ) ) ;
if ( V_9 == V_48 || V_9 == V_100 ) {
V_13 -> V_36 |= V_128 ;
F_50 ( 1 ) ;
V_13 -> V_21 ( V_2 , V_13 -> V_36 , V_37 ) ;
}
V_13 -> V_21 ( V_2 , V_77 -> V_98 , V_129 ) ;
V_13 -> V_21 ( V_2 , 0x1 , V_130 ) ;
if ( V_77 -> V_80 == V_81 ||
V_77 -> V_78 == V_81 ) {
F_36 ( V_2 , V_77 , V_9 ) ;
F_9 ( V_2 , V_131 ,
0 , V_13 -> V_88 , V_132 ) ;
}
if ( F_32 ( V_77 , V_9 ) ) {
F_9 ( V_2 , V_72 ,
0 , V_13 -> V_92 , V_73 ) ;
} else {
F_14 ( V_2 , V_72 , 0 , V_73 ) ;
}
if ( F_34 ( V_77 , V_9 ) ) {
F_9 ( V_2 , V_131 ,
1 , V_13 -> V_93 , V_73 ) ;
}
F_24 ( V_2 ) ;
if ( V_39 == V_126 )
F_51 ( V_2 , V_11 ) ;
V_13 -> V_23 |= V_133 ;
if ( V_39 == V_67 )
V_13 -> V_23 |= V_134 ;
V_13 -> V_21 ( V_2 , V_13 -> V_23 , V_24 ) ;
V_13 -> V_68 = 0 ;
if ( V_77 -> V_80 != V_111 )
V_13 -> V_68 |= V_69 ;
if ( ! F_31 ( V_77 , V_9 ) ) {
V_13 -> V_68 |= V_135 ;
if ( V_77 -> V_78 == V_111 )
V_13 -> V_68 |= V_136 ;
}
if ( V_28 == V_35 )
V_13 -> V_68 |= V_70 ;
V_13 -> V_21 ( V_2 , V_13 -> V_68 , V_71 ) ;
F_16 ( & V_2 -> V_16 , V_15 ) ;
V_13 -> V_17 |= V_137 ;
V_13 -> V_17 &= ~ ( V_18 | V_19 | V_20 ) ;
if ( V_77 -> V_109 == V_111 )
V_13 -> V_17 |= V_19 ;
else
V_13 -> V_17 |= V_18 ;
if ( V_77 -> V_115 == V_111 )
V_13 -> V_17 |= ( V_19 | V_20 ) ;
V_13 -> V_21 ( V_2 , V_13 -> V_17 , V_22 ) ;
F_17 ( & V_2 -> V_16 , V_15 ) ;
return 0 ;
}
static int F_52 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
struct V_120 * V_121 = V_2 -> V_138 -> V_121 ;
struct V_76 * V_77 = & V_121 -> V_77 ;
unsigned short V_63 ;
const int V_139 = 10000 ;
unsigned int V_66 ;
V_13 -> V_59 = V_13 -> V_52 ( V_2 , V_60 ) ;
for ( V_66 = 0 ; ( V_13 -> V_59 & V_61 ) && V_66 < V_139 ;
V_66 ++ ) {
if ( V_77 -> V_115 == V_113 ) {
if ( V_13 -> V_8 == 0 )
break;
V_13 -> V_8 -- ;
}
V_63 = F_23 ( V_2 ) ;
F_53 ( V_2 -> V_138 , & V_63 , 1 ) ;
V_13 -> V_59 = V_13 -> V_52 ( V_2 , V_60 ) ;
}
if ( V_66 == V_139 ) {
F_54 ( V_2 -> V_103 , L_4 ) ;
V_121 -> V_140 |= V_141 ;
return - 1 ;
}
return 0 ;
}
static void F_55 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
if ( V_13 -> V_127 == V_126 )
F_56 ( V_2 ) ;
F_52 ( V_2 ) ;
}
static T_1 F_57 ( int V_142 , void * V_143 )
{
struct V_1 * V_2 = V_143 ;
const struct V_29 * V_30 = V_2 -> V_31 ;
struct V_12 * V_13 = V_2 -> V_14 ;
struct V_10 * V_11 = V_2 -> V_138 ;
struct V_120 * V_121 ;
struct V_76 * V_77 ;
if ( ! V_2 -> V_144 ) {
F_54 ( V_2 -> V_103 , L_5 ) ;
return V_145 ;
}
V_121 = V_11 -> V_121 ;
V_77 = & V_121 -> V_77 ;
V_13 -> V_59 = V_13 -> V_52 ( V_2 , V_60 ) ;
if ( V_30 -> V_32 )
V_13 -> V_146 = V_13 -> V_52 ( V_2 , V_147 ) ;
if ( ( V_13 -> V_59 & ( V_148 | V_149 | V_150 |
V_151 | V_61 ) ) == 0 &&
( V_13 -> V_146 & V_152 ) == 0 &&
( V_13 -> V_146 & V_153 ) ) {
return V_154 ;
}
if ( V_13 -> V_59 & V_151 ) {
V_13 -> V_21 ( V_2 , 0x1 , V_55 ) ;
V_121 -> V_140 |= V_141 ;
F_58 ( V_2 , V_11 ) ;
F_54 ( V_2 -> V_103 , L_6 ) ;
return V_145 ;
}
if ( V_13 -> V_127 == V_126 )
F_59 ( V_2 ) ;
else
F_52 ( V_2 ) ;
if ( V_13 -> V_59 & V_149 ) {
F_54 ( V_2 -> V_103 , L_7 ) ;
V_13 -> V_21 ( V_2 , 0x1 , V_155 ) ;
}
if ( V_13 -> V_59 & V_150 ) {
V_13 -> V_21 ( V_2 , 0x1 , V_55 ) ;
V_121 -> V_140 |= V_141 ;
F_58 ( V_2 , V_11 ) ;
F_54 ( V_2 -> V_103 , L_8 ) ;
return V_145 ;
}
if ( V_77 -> V_115 == V_111 ) {
if ( V_13 -> V_146 & V_152 ) {
F_55 ( V_2 ) ;
V_121 -> V_140 |= V_156 ;
}
}
if ( V_77 -> V_115 == V_113 ) {
if ( V_13 -> V_8 == 0 )
V_121 -> V_140 |= V_156 ;
}
F_58 ( V_2 , V_11 ) ;
return V_145 ;
}
static void F_60 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
unsigned int V_26 , unsigned int V_157 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
V_13 -> V_21 ( V_2 , V_157 & 0xff , F_61 ( V_26 ) ) ;
V_13 -> V_21 ( V_2 , ( V_157 >> 8 ) & 0xff , F_62 ( V_26 ) ) ;
V_11 -> V_158 [ V_26 ] = V_157 ;
}
static int F_63 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_56 * V_57 ,
unsigned int * V_63 )
{
const struct V_29 * V_30 = V_2 -> V_31 ;
struct V_12 * V_13 = V_2 -> V_14 ;
int V_159 , V_27 ;
unsigned long V_15 ;
V_159 = F_27 ( V_57 -> V_64 ) ;
F_16 ( & V_2 -> V_16 , V_15 ) ;
V_13 -> V_17 &= ~ F_64 ( V_159 ) ;
V_13 -> V_21 ( V_2 , V_13 -> V_17 , V_22 ) ;
F_17 ( & V_2 -> V_16 , V_15 ) ;
if ( V_30 -> V_32 ) {
V_27 = F_28 ( V_57 -> V_64 ) ;
if ( F_22 ( V_11 , V_27 ) )
V_13 -> V_42 |= F_65 ( V_159 ) ;
else
V_13 -> V_42 &= ~ F_65 ( V_159 ) ;
V_13 -> V_21 ( V_2 , V_13 -> V_42 , V_50 ) ;
}
F_60 ( V_2 , V_11 , V_159 , V_63 [ 0 ] ) ;
return 1 ;
}
static void F_66 ( struct V_1 * V_2 , unsigned int V_160 ,
unsigned int V_161 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
int V_66 ;
for ( V_66 = 1 ; V_66 <= V_161 ; V_66 ++ ) {
V_13 -> V_162 &= ~ V_163 ;
if ( V_160 & ( 1 << ( V_161 - V_66 ) ) )
V_13 -> V_162 |= V_164 ;
else
V_13 -> V_162 &= ~ V_164 ;
F_50 ( 1 ) ;
V_13 -> V_21 ( V_2 , V_13 -> V_162 , V_165 ) ;
V_13 -> V_162 |= V_163 ;
F_50 ( 1 ) ;
V_13 -> V_21 ( V_2 , V_13 -> V_162 , V_165 ) ;
}
}
static unsigned int F_67 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
unsigned int V_160 = 0 ;
int V_66 ;
const int V_161 = 8 ;
for ( V_66 = 1 ; V_66 <= V_161 ; V_66 ++ ) {
V_13 -> V_162 |= V_163 ;
F_50 ( 1 ) ;
V_13 -> V_21 ( V_2 , V_13 -> V_162 , V_165 ) ;
V_13 -> V_162 &= ~ V_163 ;
F_50 ( 1 ) ;
V_13 -> V_21 ( V_2 , V_13 -> V_162 , V_165 ) ;
F_50 ( 1 ) ;
V_13 -> V_146 = V_13 -> V_52 ( V_2 , V_147 ) ;
if ( V_13 -> V_146 & V_166 )
V_160 |= 1 << ( V_161 - V_66 ) ;
}
return V_160 ;
}
static unsigned int F_68 ( struct V_1 * V_2 ,
unsigned int V_167 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
unsigned int V_160 ;
const int V_168 = 0x3 ;
const int V_169 = 8 ;
V_13 -> V_162 &= ~ V_170 ;
F_50 ( 1 ) ;
V_13 -> V_21 ( V_2 , V_13 -> V_162 , V_165 ) ;
V_13 -> V_162 |= ( V_170 | V_171 ) ;
F_50 ( 1 ) ;
V_13 -> V_21 ( V_2 , V_13 -> V_162 , V_165 ) ;
F_66 ( V_2 , V_168 , V_169 ) ;
F_66 ( V_2 , V_167 , V_169 ) ;
V_160 = F_67 ( V_2 ) ;
V_13 -> V_162 &= ~ ( V_170 | V_171 ) ;
F_50 ( 1 ) ;
V_13 -> V_21 ( V_2 , V_13 -> V_162 , V_165 ) ;
return V_160 ;
}
static unsigned int F_69 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
unsigned int V_160 ;
const int V_172 = 0x5 ;
const int V_169 = 8 ;
V_13 -> V_162 &= ~ V_170 ;
F_50 ( 1 ) ;
V_13 -> V_21 ( V_2 , V_13 -> V_162 , V_165 ) ;
V_13 -> V_162 |= ( V_170 | V_171 ) ;
F_50 ( 1 ) ;
V_13 -> V_21 ( V_2 , V_13 -> V_162 , V_165 ) ;
F_66 ( V_2 , V_172 , V_169 ) ;
V_160 = F_67 ( V_2 ) ;
V_13 -> V_162 &= ~ ( V_170 | V_171 ) ;
F_50 ( 1 ) ;
V_13 -> V_21 ( V_2 , V_13 -> V_162 , V_165 ) ;
return V_160 ;
}
static void F_70 ( struct V_1 * V_2 ,
unsigned int V_167 , unsigned int V_160 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
const int V_173 = 0x6 ;
const int V_174 = 0x2 ;
const int V_169 = 8 ;
V_13 -> V_162 &= ~ V_170 ;
F_50 ( 1 ) ;
V_13 -> V_21 ( V_2 , V_13 -> V_162 , V_165 ) ;
V_13 -> V_162 |= ( V_170 | V_171 ) ;
F_50 ( 1 ) ;
V_13 -> V_21 ( V_2 , V_13 -> V_162 , V_165 ) ;
F_66 ( V_2 , V_173 , V_169 ) ;
V_13 -> V_162 &= ~ V_170 ;
F_50 ( 1 ) ;
V_13 -> V_21 ( V_2 , V_13 -> V_162 , V_165 ) ;
V_13 -> V_162 |= V_170 ;
F_50 ( 1 ) ;
V_13 -> V_21 ( V_2 , V_13 -> V_162 , V_165 ) ;
F_66 ( V_2 , V_174 , V_169 ) ;
F_66 ( V_2 , V_167 , V_169 ) ;
F_66 ( V_2 , V_160 , V_169 ) ;
V_13 -> V_162 &= ~ V_170 ;
F_50 ( 1 ) ;
V_13 -> V_21 ( V_2 , V_13 -> V_162 , V_165 ) ;
V_13 -> V_162 &= ~ ( V_170 | V_171 ) ;
F_50 ( 1 ) ;
V_13 -> V_21 ( V_2 , V_13 -> V_162 , V_165 ) ;
}
static void F_71 ( struct V_1 * V_2 , unsigned int V_159 ,
unsigned int V_160 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
V_13 -> V_162 &= ~ ( V_175 | V_170 | V_171 ) ;
F_50 ( 1 ) ;
V_13 -> V_21 ( V_2 , V_13 -> V_162 , V_165 ) ;
F_66 ( V_2 , V_159 , 4 ) ;
F_66 ( V_2 , V_160 , 8 ) ;
V_13 -> V_162 |= V_175 ;
F_50 ( 1 ) ;
V_13 -> V_21 ( V_2 , V_13 -> V_162 , V_165 ) ;
V_13 -> V_162 &= ~ V_175 ;
F_50 ( 1 ) ;
V_13 -> V_21 ( V_2 , V_13 -> V_162 , V_165 ) ;
}
static int F_72 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_56 * V_57 ,
unsigned int * V_63 )
{
unsigned int V_26 = F_27 ( V_57 -> V_64 ) ;
if ( V_57 -> V_74 > 0 ) {
unsigned int V_157 = V_63 [ V_57 -> V_74 - 1 ] ;
if ( V_11 -> V_158 [ V_26 ] != V_157 ) {
F_71 ( V_2 , V_26 , V_157 ) ;
V_11 -> V_158 [ V_26 ] = V_157 ;
}
}
return V_57 -> V_74 ;
}
static int F_73 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_56 * V_57 ,
unsigned long V_58 )
{
unsigned int V_176 ;
V_176 = F_69 ( V_2 ) ;
if ( ( V_176 & 0x1 ) == 0 )
return 0 ;
return - V_62 ;
}
static int F_74 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_56 * V_57 ,
unsigned int * V_63 )
{
unsigned int V_26 = F_27 ( V_57 -> V_64 ) ;
int V_65 ;
if ( V_26 < 16 || V_26 > 127 )
return - V_104 ;
if ( V_57 -> V_74 > 0 ) {
unsigned int V_157 = V_63 [ V_57 -> V_74 - 1 ] ;
V_65 = F_30 ( V_2 , V_11 , V_57 , F_73 , 0 ) ;
if ( V_65 )
return V_65 ;
F_70 ( V_2 , V_26 , V_157 ) ;
V_11 -> V_158 [ V_26 ] = V_157 ;
}
return V_57 -> V_74 ;
}
int F_75 ( struct V_1 * V_2 ,
unsigned int V_142 , unsigned long V_177 )
{
const struct V_29 * V_30 = V_2 -> V_31 ;
struct V_12 * V_13 ;
struct V_10 * V_11 ;
int V_65 ;
int V_66 ;
V_13 = F_76 ( V_2 , sizeof( * V_13 ) ) ;
if ( ! V_13 )
return - V_178 ;
if ( V_2 -> V_6 ) {
V_13 -> V_52 = F_5 ;
V_13 -> V_21 = F_7 ;
} else {
V_13 -> V_52 = F_1 ;
V_13 -> V_21 = F_3 ;
}
V_13 -> V_21 ( V_2 , V_13 -> V_36 , V_37 ) ;
V_13 -> V_21 ( V_2 , V_13 -> V_17 , V_22 ) ;
V_13 -> V_21 ( V_2 , V_13 -> V_23 , V_24 ) ;
V_13 -> V_21 ( V_2 , V_13 -> V_68 , V_71 ) ;
if ( V_30 -> V_32 ) {
V_13 -> V_21 ( V_2 , V_13 -> V_162 , V_165 ) ;
V_13 -> V_21 ( V_2 , V_13 -> V_42 , V_50 ) ;
}
if ( V_142 ) {
V_65 = F_77 ( V_142 , F_57 , V_177 ,
V_2 -> V_179 , V_2 ) ;
if ( V_65 == 0 )
V_2 -> V_142 = V_142 ;
}
V_65 = F_78 ( V_2 , 5 ) ;
if ( V_65 )
return V_65 ;
V_11 = & V_2 -> V_180 [ 0 ] ;
V_11 -> type = V_181 ;
V_11 -> V_182 = V_183 | V_184 | V_185 | V_186 ;
V_11 -> V_187 = 8 ;
V_11 -> V_188 = 8 ;
V_11 -> V_189 = 0x0fff ;
V_11 -> V_190 = V_30 -> V_32 ?
& V_191 : & V_192 ;
V_11 -> V_193 = F_26 ;
if ( V_2 -> V_142 ) {
V_2 -> V_138 = V_11 ;
V_11 -> V_182 |= V_194 ;
V_11 -> V_195 = F_49 ;
V_11 -> V_196 = F_45 ;
V_11 -> V_197 = F_15 ;
}
V_11 = & V_2 -> V_180 [ 1 ] ;
if ( V_30 -> V_198 ) {
V_11 -> type = V_199 ;
V_11 -> V_182 = V_183 | V_200 | V_184 ;
V_11 -> V_187 = V_201 ;
V_11 -> V_189 = 0x0fff ;
V_11 -> V_190 = & V_202 ;
V_11 -> V_203 = F_63 ;
V_65 = F_79 ( V_11 ) ;
if ( V_65 )
return V_65 ;
for ( V_66 = 0 ; V_66 < V_11 -> V_187 ; V_66 ++ )
F_60 ( V_2 , V_11 , V_66 , V_11 -> V_189 / 2 ) ;
} else {
V_11 -> type = V_204 ;
}
V_11 = & V_2 -> V_180 [ 2 ] ;
if ( V_2 -> V_6 )
V_65 = F_80 ( V_2 , V_11 , NULL , V_205 ) ;
else
V_65 = F_81 ( V_2 , V_11 , NULL , V_205 ) ;
if ( V_65 )
return V_65 ;
V_11 = & V_2 -> V_180 [ 3 ] ;
if ( V_30 -> V_32 ) {
V_11 -> type = V_206 ;
V_11 -> V_182 = V_183 | V_200 | V_207 ;
V_11 -> V_187 = 16 ;
V_11 -> V_189 = 0xff ;
V_11 -> V_203 = F_72 ;
V_65 = F_79 ( V_11 ) ;
if ( V_65 )
return V_65 ;
for ( V_66 = 0 ; V_66 < V_11 -> V_187 ; V_66 ++ ) {
F_71 ( V_2 , V_66 , V_11 -> V_189 / 2 ) ;
V_11 -> V_158 [ V_66 ] = V_11 -> V_189 / 2 ;
}
} else {
V_11 -> type = V_204 ;
}
V_11 = & V_2 -> V_180 [ 4 ] ;
if ( V_30 -> V_32 ) {
V_11 -> type = V_208 ;
V_11 -> V_182 = V_183 | V_200 | V_207 ;
V_11 -> V_187 = V_209 ;
V_11 -> V_189 = 0xff ;
V_11 -> V_203 = F_74 ;
V_65 = F_79 ( V_11 ) ;
if ( V_65 )
return V_65 ;
for ( V_66 = 0 ; V_66 < V_11 -> V_187 ; V_66 ++ )
V_11 -> V_158 [ V_66 ] = F_68 ( V_2 , V_66 ) ;
} else {
V_11 -> type = V_204 ;
}
return 0 ;
}
static int T_2 F_82 ( void )
{
return 0 ;
}
static void T_3 F_83 ( void )
{
}
