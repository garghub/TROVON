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
static int F_9 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
unsigned long V_12 ;
F_10 ( & V_2 -> V_13 , V_12 ) ;
V_10 -> V_14 &= ~ ( V_15 | V_16 | V_17 ) ;
V_10 -> V_18 ( V_2 , V_10 -> V_14 , V_19 ) ;
F_11 ( & V_2 -> V_13 , V_12 ) ;
V_10 -> V_20 = 0 ;
V_10 -> V_18 ( V_2 , V_10 -> V_20 , V_21 ) ;
return 0 ;
}
static void F_12 ( struct V_1 * V_2 ,
enum V_22 V_23 ,
unsigned int V_24 ,
unsigned int V_25 ,
unsigned int V_26 )
{
const struct V_27 * V_28 = V_2 -> V_29 ;
struct V_9 * V_10 = V_2 -> V_11 ;
if ( V_28 -> V_30 ) {
V_25 += ( V_25 > 0 ) + ( V_25 > 7 ) ;
}
if ( ( V_23 == V_31 || V_23 == V_32 ) &&
V_26 == V_33 )
V_24 *= 2 ;
V_10 -> V_34 = F_13 ( V_24 ) ;
V_10 -> V_34 |= F_14 ( V_25 ) ;
V_10 -> V_18 ( V_2 , V_10 -> V_34 , V_35 ) ;
}
static void F_15 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
enum V_22 V_23 ,
enum V_36 V_37 ,
unsigned int V_25 ,
unsigned int V_26 ,
bool V_38 )
{
const struct V_27 * V_28 = V_2 -> V_29 ;
struct V_9 * V_10 = V_2 -> V_11 ;
if ( ! V_28 -> V_30 )
return;
if ( V_26 != V_39 )
V_10 -> V_40 |= V_41 ;
else
V_10 -> V_40 &= ~ V_41 ;
if ( F_16 ( V_8 , V_25 ) )
V_10 -> V_40 |= V_42 ;
else
V_10 -> V_40 &= ~ V_42 ;
if ( V_37 == V_43 )
V_10 -> V_40 |= V_44 ;
else
V_10 -> V_40 &= ~ V_44 ;
if ( V_38 )
V_10 -> V_40 |= V_45 ;
else
V_10 -> V_40 &= ~ V_45 ;
if ( V_23 == V_46 )
V_10 -> V_40 |= V_47 ;
else
V_10 -> V_40 &= ~ V_47 ;
V_10 -> V_18 ( V_2 , V_10 -> V_40 , V_48 ) ;
}
static unsigned int F_17 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
unsigned int V_49 = V_10 -> V_50 ( V_2 , V_51 ) ;
unsigned int V_52 = V_10 -> V_50 ( V_2 , V_51 ) ;
return ( V_52 << 8 ) | V_49 ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
V_10 -> V_18 ( V_2 , 0x1 , V_53 ) ;
F_17 ( V_2 ) ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
struct V_54 * V_55 ,
unsigned long V_56 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
V_10 -> V_57 = V_10 -> V_50 ( V_2 , V_58 ) ;
if ( V_10 -> V_57 & V_59 )
return 0 ;
return - V_60 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
struct V_54 * V_55 ,
unsigned int * V_61 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
unsigned int V_24 = F_21 ( V_55 -> V_62 ) ;
unsigned int V_25 = F_22 ( V_55 -> V_62 ) ;
unsigned int V_26 = F_23 ( V_55 -> V_62 ) ;
int V_63 ;
int V_64 ;
F_9 ( V_2 , V_8 ) ;
F_12 ( V_2 , V_31 , V_24 , V_25 , V_26 ) ;
F_15 ( V_2 , V_8 , V_31 , V_65 ,
V_25 , V_26 , false ) ;
V_10 -> V_66 = 0 ;
V_10 -> V_66 |= V_67 ;
if ( V_26 == V_33 )
V_10 -> V_66 |= V_68 ;
V_10 -> V_18 ( V_2 , V_10 -> V_66 , V_69 ) ;
F_24 ( V_10 -> V_70 , 0 , V_71 | V_72 ) ;
F_18 ( V_2 ) ;
for ( V_64 = 0 ; V_64 < V_55 -> V_73 ; V_64 ++ ) {
V_10 -> V_18 ( V_2 , 0x1 , V_74 ) ;
V_63 = F_25 ( V_2 , V_8 , V_55 , F_19 , 0 ) ;
if ( V_63 )
return V_63 ;
V_61 [ V_64 ] = F_17 ( V_2 ) ;
}
return V_55 -> V_73 ;
}
static bool F_26 ( const struct V_75 * V_76 ,
enum V_22 V_23 )
{
if ( V_23 == V_31 || V_76 -> V_77 == V_78 )
return true ;
return false ;
}
static unsigned int F_27 ( const struct V_75 * V_76 ,
enum V_22 V_23 )
{
if ( V_76 -> V_79 != V_80 )
return 0 ;
if ( V_23 == V_31 && V_76 -> V_77 == V_80 )
return V_76 -> V_81 ;
return V_76 -> V_82 ;
}
static void F_28 ( struct V_75 * V_76 ,
enum V_22 V_23 , unsigned int V_83 )
{
if ( V_76 -> V_79 != V_80 )
return;
if ( V_23 == V_31 &&
V_76 -> V_77 == V_80 ) {
V_76 -> V_81 = V_83 ;
if ( V_76 -> V_82 > V_76 -> V_81 )
V_76 -> V_82 = V_76 -> V_81 ;
} else {
V_76 -> V_82 = V_83 ;
}
}
static unsigned int F_29 ( const struct V_75 * V_76 ,
enum V_22 V_23 )
{
if ( V_76 -> V_77 != V_80 )
return 0 ;
if ( V_23 == V_31 && V_76 -> V_79 == V_80 )
return 0 ;
return V_76 -> V_81 ;
}
static void F_30 ( struct V_75 * V_76 ,
enum V_22 V_23 , unsigned int V_83 )
{
if ( V_76 -> V_77 != V_80 )
return;
if ( V_23 == V_31 && V_76 -> V_79 == V_80 )
return;
V_76 -> V_81 = V_83 ;
}
static void F_31 ( struct V_1 * V_2 , struct V_75 * V_76 ,
enum V_22 V_23 )
{
struct V_84 * V_85 = V_2 -> V_85 ;
unsigned int V_86 = F_27 ( V_76 , V_23 ) ;
unsigned int V_87 = F_29 ( V_76 , V_23 ) ;
unsigned int V_88 ;
if ( V_86 && V_87 ) {
V_85 -> V_89 = ( V_87 - 1 ) /
( V_85 -> V_90 * V_91 ) + 1 ;
F_32 ( & V_85 -> V_89 , 2 ) ;
F_33 ( & V_85 -> V_89 ,
V_91 ) ;
V_88 = V_85 -> V_90 * V_85 -> V_89 ;
switch ( V_76 -> V_12 & V_92 ) {
default:
case V_93 :
V_85 -> V_94 = F_34 ( V_86 ,
V_88 ) ;
V_85 -> V_95 = F_34 ( V_87 ,
V_88 ) ;
break;
case V_96 :
V_85 -> V_94 = F_35 ( V_86 ,
V_88 ) ;
V_85 -> V_95 = F_35 ( V_87 ,
V_88 ) ;
break;
case V_97 :
V_85 -> V_94 = V_86 / V_88 ;
V_85 -> V_95 = V_87 / V_88 ;
break;
}
F_32 ( & V_85 -> V_94 , 2 ) ;
F_33 ( & V_85 -> V_94 , V_91 ) ;
F_32 ( & V_85 -> V_95 , 2 ) ;
F_33 ( & V_85 -> V_95 ,
V_91 ) ;
F_28 ( V_76 , V_23 ,
V_88 * V_85 -> V_94 ) ;
F_30 ( V_76 , V_23 ,
V_88 * V_85 -> V_95 ) ;
} else if ( V_87 ) {
F_36 ( V_85 , & V_87 ,
V_76 -> V_12 ) ;
F_30 ( V_76 , V_23 , V_87 ) ;
} else if ( V_86 ) {
F_36 ( V_85 , & V_86 ,
V_76 -> V_12 ) ;
V_85 -> V_94 = V_85 -> V_95 ;
F_28 ( V_76 , V_23 , V_86 ) ;
}
}
static enum V_22 F_37 ( const struct V_75 * V_76 )
{
unsigned int V_98 ;
unsigned int V_99 ;
if ( V_76 -> V_100 == 1 )
return V_31 ;
if ( ! V_76 -> V_101 )
return V_46 ;
V_98 = F_21 ( V_76 -> V_101 [ 0 ] ) ;
V_99 = F_21 ( V_76 -> V_101 [ 1 ] ) ;
if ( V_98 < V_99 )
return V_46 ;
if ( V_98 > V_99 )
return V_102 ;
return V_32 ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
struct V_75 * V_76 )
{
enum V_22 V_23 = F_37 ( V_76 ) ;
unsigned int V_98 = F_21 ( V_76 -> V_101 [ 0 ] ) ;
unsigned int V_103 = F_22 ( V_76 -> V_101 [ 0 ] ) ;
unsigned int V_104 = F_23 ( V_76 -> V_101 [ 0 ] ) ;
int V_64 ;
for ( V_64 = 0 ; V_64 < V_76 -> V_100 ; V_64 ++ ) {
unsigned int V_24 = F_21 ( V_76 -> V_101 [ V_64 ] ) ;
unsigned int V_25 = F_22 ( V_76 -> V_101 [ V_64 ] ) ;
unsigned int V_26 = F_23 ( V_76 -> V_101 [ V_64 ] ) ;
switch ( V_23 ) {
case V_31 :
break;
case V_32 :
if ( V_24 != V_98 ) {
F_39 ( V_2 -> V_105 ,
L_1 ) ;
return - V_106 ;
}
break;
case V_46 :
if ( V_24 != V_64 ) {
F_39 ( V_2 -> V_105 ,
L_1 ) ;
return - V_106 ;
}
break;
case V_102 :
if ( V_24 != ( V_76 -> V_100 - V_64 - 1 ) ) {
F_39 ( V_2 -> V_105 ,
L_1 ) ;
return - V_106 ;
}
break;
}
if ( V_25 != V_103 ) {
F_39 ( V_2 -> V_105 ,
L_2 ) ;
return - V_106 ;
}
if ( V_26 != V_104 ) {
F_39 ( V_2 -> V_105 ,
L_3 ) ;
return - V_106 ;
}
}
return 0 ;
}
static int F_40 ( struct V_1 * V_2 ,
struct V_7 * V_8 , struct V_75 * V_76 )
{
const struct V_27 * V_28 = V_2 -> V_29 ;
int V_107 = 0 ;
int V_108 , V_109 ;
unsigned int V_110 ;
enum V_22 V_23 ;
V_107 |= F_41 ( & V_76 -> V_111 , V_112 | V_113 ) ;
V_107 |= F_41 ( & V_76 -> V_77 ,
V_80 | V_78 | V_113 ) ;
V_107 |= F_41 ( & V_76 -> V_79 ,
V_80 | V_113 ) ;
V_107 |= F_41 ( & V_76 -> V_114 , V_115 ) ;
V_110 = V_115 | V_116 ;
if ( V_28 -> V_30 )
V_110 |= V_113 ;
V_107 |= F_41 ( & V_76 -> V_117 , V_110 ) ;
if ( V_107 )
return 1 ;
V_107 |= F_42 ( V_76 -> V_111 ) ;
V_107 |= F_42 ( V_76 -> V_77 ) ;
V_107 |= F_42 ( V_76 -> V_79 ) ;
V_107 |= F_42 ( V_76 -> V_117 ) ;
if ( V_76 -> V_111 == V_113 && V_76 -> V_117 == V_113 )
V_107 ++ ;
if ( V_107 )
return 2 ;
switch ( V_76 -> V_111 ) {
case V_112 :
V_107 |= F_43 ( & V_76 -> V_118 , 0 ) ;
break;
case V_113 :
break;
}
if ( ! V_76 -> V_100 )
V_107 |= - V_106 ;
V_107 |= F_43 ( & V_76 -> V_119 ,
V_76 -> V_100 ) ;
if ( V_76 -> V_79 == V_80 ) {
V_107 |= F_32 ( & V_76 -> V_82 ,
V_28 -> V_120 ) ;
}
if ( V_76 -> V_77 == V_80 ) {
if ( V_76 -> V_79 == V_80 ) {
V_107 |= F_32 ( & V_76 ->
V_81 ,
V_76 -> V_82 *
V_76 -> V_100 ) ;
}
V_107 |= F_32 ( & V_76 -> V_81 ,
V_28 -> V_120 *
V_76 -> V_100 ) ;
}
switch ( V_76 -> V_117 ) {
case V_115 :
V_107 |= F_32 ( & V_76 -> V_121 , 1 ) ;
break;
case V_116 :
V_107 |= F_43 ( & V_76 -> V_121 , 0 ) ;
break;
default:
break;
}
if ( V_107 )
return 3 ;
V_108 = V_76 -> V_82 ;
V_109 = V_76 -> V_81 ;
V_23 = F_37 ( V_76 ) ;
F_31 ( V_2 , V_76 , V_23 ) ;
if ( V_108 != V_76 -> V_82 || V_109 != V_76 -> V_81 )
V_107 ++ ;
if ( V_107 )
return 4 ;
if ( V_76 -> V_101 && V_76 -> V_100 > 0 )
V_107 |= F_38 ( V_2 , V_8 , V_76 ) ;
if ( V_107 )
return 5 ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
const struct V_27 * V_28 = V_2 -> V_29 ;
struct V_9 * V_10 = V_2 -> V_11 ;
struct V_122 * V_123 = V_8 -> V_123 ;
struct V_75 * V_76 = & V_123 -> V_76 ;
enum V_22 V_23 = F_37 ( V_76 ) ;
unsigned int V_62 = ( V_23 == V_46 ) ?
V_76 -> V_101 [ V_76 -> V_100 - 1 ] :
V_76 -> V_101 [ 0 ] ;
unsigned int V_24 = F_21 ( V_62 ) ;
unsigned int V_25 = F_22 ( V_62 ) ;
unsigned int V_26 = F_23 ( V_62 ) ;
enum V_36 V_37 ;
unsigned long V_12 ;
F_9 ( V_2 , V_8 ) ;
if ( V_76 -> V_117 == V_115 )
V_10 -> V_124 = V_76 -> V_121 * V_76 -> V_100 ;
if ( V_76 -> V_117 == V_113 ) {
F_45 ( V_10 -> V_70 , 1 ,
3 , V_125 | V_72 ) ;
} else {
F_24 ( V_10 -> V_70 , 1 ,
V_125 | V_72 ) ;
}
if ( V_10 -> V_126 &&
( V_76 -> V_12 & ( V_127 | V_128 ) ) == 0 )
V_37 = V_129 ;
else if (
V_28 -> V_30 &&
( V_76 -> V_12 & V_127 ) == 0 &&
( V_76 -> V_117 != V_115 || V_10 -> V_124 > 256 ) )
V_37 = V_43 ;
else
V_37 = V_65 ;
V_10 -> V_130 = V_37 ;
F_12 ( V_2 , V_23 , V_24 , V_25 , V_26 ) ;
F_15 ( V_2 , V_8 , V_23 , V_37 , V_25 , V_26 ,
( V_76 -> V_117 == V_113 ) ) ;
if ( V_23 == V_46 || V_23 == V_102 ) {
V_10 -> V_34 |= V_131 ;
F_46 ( 1 ) ;
V_10 -> V_18 ( V_2 , V_10 -> V_34 , V_35 ) ;
}
V_10 -> V_18 ( V_2 , V_76 -> V_100 , V_132 ) ;
V_10 -> V_18 ( V_2 , 0x1 , V_133 ) ;
if ( V_76 -> V_79 == V_80 ||
V_76 -> V_77 == V_80 ) {
struct V_84 * V_85 = V_2 -> V_85 ;
struct V_84 * V_70 = V_10 -> V_70 ;
F_47 ( V_85 ) ;
F_45 ( V_85 , 0 , V_85 -> V_134 ,
V_135 | V_72 ) ;
F_24 ( V_70 , 0 , V_71 | V_72 ) ;
if ( F_27 ( V_76 , V_23 ) )
F_48 ( V_70 , 0 , V_85 -> V_136 ) ;
if ( F_29 ( V_76 , V_23 ) )
F_45 ( V_85 , 1 , V_85 -> V_137 ,
V_71 | V_72 ) ;
}
F_18 ( V_2 ) ;
if ( V_37 == V_129 )
F_49 ( V_2 , V_8 ) ;
V_10 -> V_20 |= V_138 ;
if ( V_37 == V_65 )
V_10 -> V_20 |= V_139 ;
V_10 -> V_18 ( V_2 , V_10 -> V_20 , V_21 ) ;
V_10 -> V_66 = 0 ;
if ( V_76 -> V_79 != V_113 )
V_10 -> V_66 |= V_67 ;
if ( ! F_26 ( V_76 , V_23 ) ) {
V_10 -> V_66 |= V_140 ;
if ( V_76 -> V_77 == V_113 )
V_10 -> V_66 |= V_141 ;
}
if ( V_26 == V_33 )
V_10 -> V_66 |= V_68 ;
V_10 -> V_18 ( V_2 , V_10 -> V_66 , V_69 ) ;
F_10 ( & V_2 -> V_13 , V_12 ) ;
V_10 -> V_14 |= V_142 ;
V_10 -> V_14 &= ~ ( V_15 | V_16 | V_17 ) ;
if ( V_76 -> V_111 == V_113 )
V_10 -> V_14 |= V_16 ;
else
V_10 -> V_14 |= V_15 ;
if ( V_76 -> V_117 == V_113 )
V_10 -> V_14 |= ( V_16 | V_17 ) ;
V_10 -> V_18 ( V_2 , V_10 -> V_14 , V_19 ) ;
F_11 ( & V_2 -> V_13 , V_12 ) ;
return 0 ;
}
static int F_50 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
struct V_122 * V_123 = V_2 -> V_143 -> V_123 ;
struct V_75 * V_76 = & V_123 -> V_76 ;
unsigned short V_61 ;
const int V_144 = 10000 ;
unsigned int V_64 ;
V_10 -> V_57 = V_10 -> V_50 ( V_2 , V_58 ) ;
for ( V_64 = 0 ; ( V_10 -> V_57 & V_59 ) && V_64 < V_144 ;
V_64 ++ ) {
if ( V_76 -> V_117 == V_115 ) {
if ( V_10 -> V_124 == 0 )
break;
V_10 -> V_124 -- ;
}
V_61 = F_17 ( V_2 ) ;
F_51 ( V_2 -> V_143 , & V_61 , 1 ) ;
V_10 -> V_57 = V_10 -> V_50 ( V_2 , V_58 ) ;
}
if ( V_64 == V_144 ) {
F_52 ( V_2 -> V_105 , L_4 ) ;
V_123 -> V_145 |= V_146 ;
return - 1 ;
}
return 0 ;
}
static void F_53 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
if ( V_10 -> V_130 == V_129 )
F_54 ( V_2 ) ;
F_50 ( V_2 ) ;
}
static T_1 F_55 ( int V_147 , void * V_148 )
{
struct V_1 * V_2 = V_148 ;
const struct V_27 * V_28 = V_2 -> V_29 ;
struct V_9 * V_10 = V_2 -> V_11 ;
struct V_7 * V_8 = V_2 -> V_143 ;
struct V_122 * V_123 ;
struct V_75 * V_76 ;
if ( ! V_2 -> V_149 ) {
F_52 ( V_2 -> V_105 , L_5 ) ;
return V_150 ;
}
V_123 = V_8 -> V_123 ;
V_76 = & V_123 -> V_76 ;
V_10 -> V_57 = V_10 -> V_50 ( V_2 , V_58 ) ;
if ( V_28 -> V_30 )
V_10 -> V_151 = V_10 -> V_50 ( V_2 , V_152 ) ;
if ( ( V_10 -> V_57 & ( V_153 | V_154 | V_155 |
V_156 | V_59 ) ) == 0 &&
( V_10 -> V_151 & V_157 ) == 0 &&
( V_10 -> V_151 & V_158 ) ) {
return V_159 ;
}
if ( V_10 -> V_57 & V_156 ) {
V_10 -> V_18 ( V_2 , 0x1 , V_53 ) ;
V_123 -> V_145 |= V_146 ;
F_56 ( V_2 , V_8 ) ;
F_52 ( V_2 -> V_105 , L_6 ) ;
return V_150 ;
}
if ( V_10 -> V_130 == V_129 )
F_57 ( V_2 ) ;
else
F_50 ( V_2 ) ;
if ( V_10 -> V_57 & V_154 ) {
F_52 ( V_2 -> V_105 , L_7 ) ;
V_10 -> V_18 ( V_2 , 0x1 , V_160 ) ;
}
if ( V_10 -> V_57 & V_155 ) {
V_10 -> V_18 ( V_2 , 0x1 , V_53 ) ;
V_123 -> V_145 |= V_146 ;
F_56 ( V_2 , V_8 ) ;
F_52 ( V_2 -> V_105 , L_8 ) ;
return V_150 ;
}
if ( V_76 -> V_117 == V_113 ) {
if ( V_10 -> V_151 & V_157 ) {
F_53 ( V_2 ) ;
V_123 -> V_145 |= V_161 ;
}
}
if ( V_76 -> V_117 == V_115 ) {
if ( V_10 -> V_124 == 0 )
V_123 -> V_145 |= V_161 ;
}
F_56 ( V_2 , V_8 ) ;
return V_150 ;
}
static void F_58 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
unsigned int V_24 , unsigned int V_162 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
V_10 -> V_18 ( V_2 , V_162 & 0xff , F_59 ( V_24 ) ) ;
V_10 -> V_18 ( V_2 , ( V_162 >> 8 ) & 0xff , F_60 ( V_24 ) ) ;
V_8 -> V_163 [ V_24 ] = V_162 ;
}
static int F_61 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
struct V_54 * V_55 ,
unsigned int * V_61 )
{
const struct V_27 * V_28 = V_2 -> V_29 ;
struct V_9 * V_10 = V_2 -> V_11 ;
int V_164 , V_25 ;
unsigned long V_12 ;
V_164 = F_21 ( V_55 -> V_62 ) ;
F_10 ( & V_2 -> V_13 , V_12 ) ;
V_10 -> V_14 &= ~ F_62 ( V_164 ) ;
V_10 -> V_18 ( V_2 , V_10 -> V_14 , V_19 ) ;
F_11 ( & V_2 -> V_13 , V_12 ) ;
if ( V_28 -> V_30 ) {
V_25 = F_22 ( V_55 -> V_62 ) ;
if ( F_16 ( V_8 , V_25 ) )
V_10 -> V_40 |= F_63 ( V_164 ) ;
else
V_10 -> V_40 &= ~ F_63 ( V_164 ) ;
V_10 -> V_18 ( V_2 , V_10 -> V_40 , V_48 ) ;
}
F_58 ( V_2 , V_8 , V_164 , V_61 [ 0 ] ) ;
return 1 ;
}
static void F_64 ( struct V_1 * V_2 , unsigned int V_165 ,
unsigned int V_166 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
int V_64 ;
for ( V_64 = 1 ; V_64 <= V_166 ; V_64 ++ ) {
V_10 -> V_167 &= ~ V_168 ;
if ( V_165 & ( 1 << ( V_166 - V_64 ) ) )
V_10 -> V_167 |= V_169 ;
else
V_10 -> V_167 &= ~ V_169 ;
F_46 ( 1 ) ;
V_10 -> V_18 ( V_2 , V_10 -> V_167 , V_170 ) ;
V_10 -> V_167 |= V_168 ;
F_46 ( 1 ) ;
V_10 -> V_18 ( V_2 , V_10 -> V_167 , V_170 ) ;
}
}
static unsigned int F_65 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
unsigned int V_165 = 0 ;
int V_64 ;
const int V_166 = 8 ;
for ( V_64 = 1 ; V_64 <= V_166 ; V_64 ++ ) {
V_10 -> V_167 |= V_168 ;
F_46 ( 1 ) ;
V_10 -> V_18 ( V_2 , V_10 -> V_167 , V_170 ) ;
V_10 -> V_167 &= ~ V_168 ;
F_46 ( 1 ) ;
V_10 -> V_18 ( V_2 , V_10 -> V_167 , V_170 ) ;
F_46 ( 1 ) ;
V_10 -> V_151 = V_10 -> V_50 ( V_2 , V_152 ) ;
if ( V_10 -> V_151 & V_171 )
V_165 |= 1 << ( V_166 - V_64 ) ;
}
return V_165 ;
}
static unsigned int F_66 ( struct V_1 * V_2 ,
unsigned int V_172 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
unsigned int V_165 ;
const int V_173 = 0x3 ;
const int V_174 = 8 ;
V_10 -> V_167 &= ~ V_175 ;
F_46 ( 1 ) ;
V_10 -> V_18 ( V_2 , V_10 -> V_167 , V_170 ) ;
V_10 -> V_167 |= ( V_175 | V_176 ) ;
F_46 ( 1 ) ;
V_10 -> V_18 ( V_2 , V_10 -> V_167 , V_170 ) ;
F_64 ( V_2 , V_173 , V_174 ) ;
F_64 ( V_2 , V_172 , V_174 ) ;
V_165 = F_65 ( V_2 ) ;
V_10 -> V_167 &= ~ ( V_175 | V_176 ) ;
F_46 ( 1 ) ;
V_10 -> V_18 ( V_2 , V_10 -> V_167 , V_170 ) ;
return V_165 ;
}
static unsigned int F_67 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
unsigned int V_165 ;
const int V_177 = 0x5 ;
const int V_174 = 8 ;
V_10 -> V_167 &= ~ V_175 ;
F_46 ( 1 ) ;
V_10 -> V_18 ( V_2 , V_10 -> V_167 , V_170 ) ;
V_10 -> V_167 |= ( V_175 | V_176 ) ;
F_46 ( 1 ) ;
V_10 -> V_18 ( V_2 , V_10 -> V_167 , V_170 ) ;
F_64 ( V_2 , V_177 , V_174 ) ;
V_165 = F_65 ( V_2 ) ;
V_10 -> V_167 &= ~ ( V_175 | V_176 ) ;
F_46 ( 1 ) ;
V_10 -> V_18 ( V_2 , V_10 -> V_167 , V_170 ) ;
return V_165 ;
}
static void F_68 ( struct V_1 * V_2 ,
unsigned int V_172 , unsigned int V_165 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
const int V_178 = 0x6 ;
const int V_179 = 0x2 ;
const int V_174 = 8 ;
V_10 -> V_167 &= ~ V_175 ;
F_46 ( 1 ) ;
V_10 -> V_18 ( V_2 , V_10 -> V_167 , V_170 ) ;
V_10 -> V_167 |= ( V_175 | V_176 ) ;
F_46 ( 1 ) ;
V_10 -> V_18 ( V_2 , V_10 -> V_167 , V_170 ) ;
F_64 ( V_2 , V_178 , V_174 ) ;
V_10 -> V_167 &= ~ V_175 ;
F_46 ( 1 ) ;
V_10 -> V_18 ( V_2 , V_10 -> V_167 , V_170 ) ;
V_10 -> V_167 |= V_175 ;
F_46 ( 1 ) ;
V_10 -> V_18 ( V_2 , V_10 -> V_167 , V_170 ) ;
F_64 ( V_2 , V_179 , V_174 ) ;
F_64 ( V_2 , V_172 , V_174 ) ;
F_64 ( V_2 , V_165 , V_174 ) ;
V_10 -> V_167 &= ~ V_175 ;
F_46 ( 1 ) ;
V_10 -> V_18 ( V_2 , V_10 -> V_167 , V_170 ) ;
V_10 -> V_167 &= ~ ( V_175 | V_176 ) ;
F_46 ( 1 ) ;
V_10 -> V_18 ( V_2 , V_10 -> V_167 , V_170 ) ;
}
static void F_69 ( struct V_1 * V_2 , unsigned int V_164 ,
unsigned int V_165 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
V_10 -> V_167 &= ~ ( V_180 | V_175 | V_176 ) ;
F_46 ( 1 ) ;
V_10 -> V_18 ( V_2 , V_10 -> V_167 , V_170 ) ;
F_64 ( V_2 , V_164 , 4 ) ;
F_64 ( V_2 , V_165 , 8 ) ;
V_10 -> V_167 |= V_180 ;
F_46 ( 1 ) ;
V_10 -> V_18 ( V_2 , V_10 -> V_167 , V_170 ) ;
V_10 -> V_167 &= ~ V_180 ;
F_46 ( 1 ) ;
V_10 -> V_18 ( V_2 , V_10 -> V_167 , V_170 ) ;
}
static int F_70 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
struct V_54 * V_55 ,
unsigned int * V_61 )
{
unsigned int V_24 = F_21 ( V_55 -> V_62 ) ;
if ( V_55 -> V_73 > 0 ) {
unsigned int V_162 = V_61 [ V_55 -> V_73 - 1 ] ;
if ( V_8 -> V_163 [ V_24 ] != V_162 ) {
F_69 ( V_2 , V_24 , V_162 ) ;
V_8 -> V_163 [ V_24 ] = V_162 ;
}
}
return V_55 -> V_73 ;
}
static int F_71 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
struct V_54 * V_55 ,
unsigned long V_56 )
{
unsigned int V_181 ;
V_181 = F_67 ( V_2 ) ;
if ( ( V_181 & 0x1 ) == 0 )
return 0 ;
return - V_60 ;
}
static int F_72 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
struct V_54 * V_55 ,
unsigned int * V_61 )
{
unsigned int V_24 = F_21 ( V_55 -> V_62 ) ;
int V_63 ;
if ( V_24 < 16 || V_24 > 127 )
return - V_106 ;
if ( V_55 -> V_73 > 0 ) {
unsigned int V_162 = V_61 [ V_55 -> V_73 - 1 ] ;
V_63 = F_25 ( V_2 , V_8 , V_55 , F_71 , 0 ) ;
if ( V_63 )
return V_63 ;
F_68 ( V_2 , V_24 , V_162 ) ;
V_8 -> V_163 [ V_24 ] = V_162 ;
}
return V_55 -> V_73 ;
}
int F_73 ( struct V_1 * V_2 ,
unsigned int V_147 , unsigned long V_182 )
{
const struct V_27 * V_28 = V_2 -> V_29 ;
struct V_9 * V_10 ;
struct V_7 * V_8 ;
int V_63 ;
int V_64 ;
V_10 = F_74 ( V_2 , sizeof( * V_10 ) ) ;
if ( ! V_10 )
return - V_183 ;
if ( V_2 -> V_6 ) {
V_10 -> V_50 = F_5 ;
V_10 -> V_18 = F_7 ;
} else {
V_10 -> V_50 = F_1 ;
V_10 -> V_18 = F_3 ;
}
V_10 -> V_18 ( V_2 , V_10 -> V_34 , V_35 ) ;
V_10 -> V_18 ( V_2 , V_10 -> V_14 , V_19 ) ;
V_10 -> V_18 ( V_2 , V_10 -> V_20 , V_21 ) ;
V_10 -> V_18 ( V_2 , V_10 -> V_66 , V_69 ) ;
if ( V_28 -> V_30 ) {
V_10 -> V_18 ( V_2 , V_10 -> V_167 , V_170 ) ;
V_10 -> V_18 ( V_2 , V_10 -> V_40 , V_48 ) ;
}
if ( V_147 ) {
V_63 = F_75 ( V_147 , F_55 , V_182 ,
V_2 -> V_184 , V_2 ) ;
if ( V_63 == 0 )
V_2 -> V_147 = V_147 ;
}
if ( V_2 -> V_6 ) {
V_2 -> V_85 = F_76 ( V_2 -> V_6 + V_185 ,
V_186 ,
V_187 , 0 ) ;
V_10 -> V_70 = F_76 ( V_2 -> V_6 +
V_188 ,
V_186 ,
V_187 , 0 ) ;
} else {
V_2 -> V_85 = F_77 ( V_2 -> V_4 + V_185 ,
V_186 ,
V_187 , 0 ) ;
V_10 -> V_70 = F_77 ( V_2 -> V_4 +
V_188 ,
V_186 ,
V_187 , 0 ) ;
}
if ( ! V_2 -> V_85 || ! V_10 -> V_70 )
return - V_183 ;
V_63 = F_78 ( V_2 , 5 ) ;
if ( V_63 )
return V_63 ;
V_8 = & V_2 -> V_189 [ 0 ] ;
V_8 -> type = V_190 ;
V_8 -> V_191 = V_192 | V_193 | V_194 | V_195 ;
V_8 -> V_196 = 8 ;
V_8 -> V_197 = 8 ;
V_8 -> V_198 = 0x0fff ;
V_8 -> V_199 = V_28 -> V_30 ?
& V_200 : & V_201 ;
V_8 -> V_202 = F_20 ;
if ( V_2 -> V_147 ) {
V_2 -> V_143 = V_8 ;
V_8 -> V_191 |= V_203 ;
V_8 -> V_204 = F_44 ;
V_8 -> V_205 = F_40 ;
V_8 -> V_206 = F_9 ;
}
V_8 = & V_2 -> V_189 [ 1 ] ;
if ( V_28 -> V_207 ) {
V_8 -> type = V_208 ;
V_8 -> V_191 = V_192 | V_209 | V_193 ;
V_8 -> V_196 = V_210 ;
V_8 -> V_198 = 0x0fff ;
V_8 -> V_199 = & V_211 ;
V_8 -> V_212 = F_61 ;
V_63 = F_79 ( V_8 ) ;
if ( V_63 )
return V_63 ;
for ( V_64 = 0 ; V_64 < V_8 -> V_196 ; V_64 ++ )
F_58 ( V_2 , V_8 , V_64 , V_8 -> V_198 / 2 ) ;
} else {
V_8 -> type = V_213 ;
}
V_8 = & V_2 -> V_189 [ 2 ] ;
if ( V_2 -> V_6 )
V_63 = F_80 ( V_2 , V_8 , NULL , V_214 ) ;
else
V_63 = F_81 ( V_2 , V_8 , NULL , V_214 ) ;
if ( V_63 )
return V_63 ;
V_8 = & V_2 -> V_189 [ 3 ] ;
if ( V_28 -> V_30 ) {
V_8 -> type = V_215 ;
V_8 -> V_191 = V_192 | V_209 | V_216 ;
V_8 -> V_196 = 16 ;
V_8 -> V_198 = 0xff ;
V_8 -> V_212 = F_70 ;
V_63 = F_79 ( V_8 ) ;
if ( V_63 )
return V_63 ;
for ( V_64 = 0 ; V_64 < V_8 -> V_196 ; V_64 ++ ) {
F_69 ( V_2 , V_64 , V_8 -> V_198 / 2 ) ;
V_8 -> V_163 [ V_64 ] = V_8 -> V_198 / 2 ;
}
} else {
V_8 -> type = V_213 ;
}
V_8 = & V_2 -> V_189 [ 4 ] ;
if ( V_28 -> V_30 ) {
V_8 -> type = V_217 ;
V_8 -> V_191 = V_192 | V_209 | V_216 ;
V_8 -> V_196 = V_218 ;
V_8 -> V_198 = 0xff ;
V_8 -> V_212 = F_72 ;
V_63 = F_79 ( V_8 ) ;
if ( V_63 )
return V_63 ;
for ( V_64 = 0 ; V_64 < V_8 -> V_196 ; V_64 ++ )
V_8 -> V_163 [ V_64 ] = F_66 ( V_2 , V_64 ) ;
} else {
V_8 -> type = V_213 ;
}
return 0 ;
}
void F_82 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
if ( V_10 )
F_83 ( V_10 -> V_70 ) ;
}
static int T_2 F_84 ( void )
{
return 0 ;
}
static void T_3 F_85 ( void )
{
}
