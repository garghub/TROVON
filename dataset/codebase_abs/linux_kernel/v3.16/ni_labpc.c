static inline unsigned int F_1 ( unsigned long V_1 )
{
return F_2 ( V_1 ) ;
}
static inline void F_3 ( unsigned int V_2 , unsigned long V_1 )
{
F_4 ( V_2 , V_1 ) ;
}
static inline unsigned int F_5 ( unsigned long V_1 )
{
return F_6 ( ( void V_3 * ) V_1 ) ;
}
static inline void F_7 ( unsigned int V_2 , unsigned long V_1 )
{
F_8 ( V_2 , ( void V_3 * ) V_1 ) ;
}
static void F_9 ( struct V_4 * V_5 ,
unsigned long V_6 ,
unsigned int V_7 ,
unsigned int V_8 ,
unsigned int V_9 )
{
const struct V_10 * V_11 = F_10 ( V_5 ) ;
if ( V_11 -> V_12 ) {
void V_3 * V_13 = ( void V_3 * ) V_6 ;
F_11 ( V_13 , 0 , V_7 , V_9 ) ;
F_12 ( V_13 , 0 , V_7 , V_8 ) ;
} else {
F_13 ( V_6 , 0 , V_7 , V_9 ) ;
F_14 ( V_6 , 0 , V_7 , V_8 ) ;
}
}
static void F_15 ( struct V_4 * V_5 ,
unsigned long V_6 ,
unsigned int V_7 ,
unsigned int V_9 )
{
const struct V_10 * V_11 = F_10 ( V_5 ) ;
if ( V_11 -> V_12 ) {
void V_3 * V_13 = ( void V_3 * ) V_6 ;
F_11 ( V_13 , 0 , V_7 , V_9 ) ;
} else {
F_13 ( V_6 , 0 , V_7 , V_9 ) ;
}
}
static int F_16 ( struct V_4 * V_5 , struct V_14 * V_15 )
{
struct V_16 * V_17 = V_5 -> V_18 ;
unsigned long V_19 ;
F_17 ( & V_5 -> V_20 , V_19 ) ;
V_17 -> V_21 &= ~ ( V_22 | V_23 | V_24 ) ;
V_17 -> V_25 ( V_17 -> V_21 , V_5 -> V_26 + V_27 ) ;
F_18 ( & V_5 -> V_20 , V_19 ) ;
V_17 -> V_28 = 0 ;
V_17 -> V_25 ( V_17 -> V_28 , V_5 -> V_26 + V_29 ) ;
return 0 ;
}
static void F_19 ( struct V_4 * V_5 ,
enum V_30 V_9 ,
unsigned int V_31 ,
unsigned int V_32 ,
unsigned int V_33 )
{
const struct V_10 * V_11 = F_10 ( V_5 ) ;
struct V_16 * V_17 = V_5 -> V_18 ;
if ( V_11 -> V_34 ) {
V_32 += ( V_32 > 0 ) + ( V_32 > 7 ) ;
}
if ( ( V_9 == V_35 || V_9 == V_36 ) &&
V_33 == V_37 )
V_31 *= 2 ;
V_17 -> V_38 = F_20 ( V_31 ) ;
V_17 -> V_38 |= F_21 ( V_32 ) ;
V_17 -> V_25 ( V_17 -> V_38 , V_5 -> V_26 + V_39 ) ;
}
static void F_22 ( struct V_4 * V_5 ,
struct V_14 * V_15 ,
enum V_30 V_9 ,
enum V_40 V_41 ,
unsigned int V_32 ,
unsigned int V_33 ,
bool V_42 )
{
const struct V_10 * V_11 = F_10 ( V_5 ) ;
struct V_16 * V_17 = V_5 -> V_18 ;
if ( ! V_11 -> V_34 )
return;
if ( V_33 != V_43 )
V_17 -> V_44 |= V_45 ;
else
V_17 -> V_44 &= ~ V_45 ;
if ( F_23 ( V_15 , V_32 ) )
V_17 -> V_44 |= V_46 ;
else
V_17 -> V_44 &= ~ V_46 ;
if ( V_41 == V_47 )
V_17 -> V_44 |= V_48 ;
else
V_17 -> V_44 &= ~ V_48 ;
if ( V_42 )
V_17 -> V_44 |= V_49 ;
else
V_17 -> V_44 &= ~ V_49 ;
if ( V_9 == V_50 )
V_17 -> V_44 |= V_51 ;
else
V_17 -> V_44 &= ~ V_51 ;
V_17 -> V_25 ( V_17 -> V_44 , V_5 -> V_26 + V_52 ) ;
}
static unsigned int F_24 ( struct V_4 * V_5 )
{
struct V_16 * V_17 = V_5 -> V_18 ;
unsigned int V_53 = V_17 -> V_54 ( V_5 -> V_26 + V_55 ) ;
unsigned int V_56 = V_17 -> V_54 ( V_5 -> V_26 + V_55 ) ;
return ( V_56 << 8 ) | V_53 ;
}
static void F_25 ( struct V_4 * V_5 )
{
struct V_16 * V_17 = V_5 -> V_18 ;
V_17 -> V_25 ( 0x1 , V_5 -> V_26 + V_57 ) ;
F_24 ( V_5 ) ;
}
static int F_26 ( struct V_4 * V_5 ,
struct V_14 * V_15 ,
struct V_58 * V_59 ,
unsigned long V_60 )
{
struct V_16 * V_17 = V_5 -> V_18 ;
V_17 -> V_61 = V_17 -> V_54 ( V_5 -> V_26 + V_62 ) ;
if ( V_17 -> V_61 & V_63 )
return 0 ;
return - V_64 ;
}
static int F_27 ( struct V_4 * V_5 ,
struct V_14 * V_15 ,
struct V_58 * V_59 ,
unsigned int * V_65 )
{
struct V_16 * V_17 = V_5 -> V_18 ;
unsigned int V_31 = F_28 ( V_59 -> V_66 ) ;
unsigned int V_32 = F_29 ( V_59 -> V_66 ) ;
unsigned int V_33 = F_30 ( V_59 -> V_66 ) ;
int V_67 ;
int V_68 ;
F_16 ( V_5 , V_15 ) ;
F_19 ( V_5 , V_35 , V_31 , V_32 , V_33 ) ;
F_22 ( V_5 , V_15 , V_35 , V_69 ,
V_32 , V_33 , false ) ;
V_17 -> V_70 = 0 ;
V_17 -> V_70 |= V_71 ;
if ( V_33 == V_37 )
V_17 -> V_70 |= V_72 ;
V_17 -> V_25 ( V_17 -> V_70 , V_5 -> V_26 + V_73 ) ;
F_15 ( V_5 , V_5 -> V_26 + V_74 ,
0 , V_75 ) ;
F_25 ( V_5 ) ;
for ( V_68 = 0 ; V_68 < V_59 -> V_76 ; V_68 ++ ) {
V_17 -> V_25 ( 0x1 , V_5 -> V_26 + V_77 ) ;
V_67 = F_31 ( V_5 , V_15 , V_59 , F_26 , 0 ) ;
if ( V_67 )
return V_67 ;
V_65 [ V_68 ] = F_24 ( V_5 ) ;
}
return V_59 -> V_76 ;
}
static bool F_32 ( const struct V_78 * V_79 ,
enum V_30 V_9 )
{
if ( V_9 == V_35 || V_79 -> V_80 == V_81 )
return true ;
return false ;
}
static unsigned int F_33 ( const struct V_78 * V_79 ,
enum V_30 V_9 )
{
if ( V_79 -> V_82 != V_83 )
return 0 ;
if ( V_9 == V_35 && V_79 -> V_80 == V_83 )
return V_79 -> V_84 ;
return V_79 -> V_85 ;
}
static void F_34 ( struct V_78 * V_79 ,
enum V_30 V_9 , unsigned int V_86 )
{
if ( V_79 -> V_82 != V_83 )
return;
if ( V_9 == V_35 &&
V_79 -> V_80 == V_83 ) {
V_79 -> V_84 = V_86 ;
if ( V_79 -> V_85 > V_79 -> V_84 )
V_79 -> V_85 = V_79 -> V_84 ;
} else
V_79 -> V_85 = V_86 ;
}
static unsigned int F_35 ( const struct V_78 * V_79 ,
enum V_30 V_9 )
{
if ( V_79 -> V_80 != V_83 )
return 0 ;
if ( V_9 == V_35 && V_79 -> V_82 == V_83 )
return 0 ;
return V_79 -> V_84 ;
}
static void F_36 ( struct V_78 * V_79 ,
enum V_30 V_9 , unsigned int V_86 )
{
if ( V_79 -> V_80 != V_83 )
return;
if ( V_9 == V_35 && V_79 -> V_82 == V_83 )
return;
V_79 -> V_84 = V_86 ;
}
static void F_37 ( struct V_4 * V_5 , struct V_78 * V_79 ,
enum V_30 V_9 )
{
struct V_16 * V_17 = V_5 -> V_18 ;
const int V_87 = 0x10000 ;
const int V_88 = 2 ;
unsigned int V_89 ;
unsigned int V_90 ;
unsigned int V_91 ;
V_91 = F_33 ( V_79 , V_9 ) ;
V_90 = F_35 ( V_79 , V_9 ) ;
if ( V_91 && V_90 ) {
V_17 -> V_92 = ( V_90 - 1 ) /
( V_93 * V_87 ) + 1 ;
if ( V_17 -> V_92 < V_88 )
V_17 -> V_92 = V_88 ;
if ( V_17 -> V_92 > V_87 )
V_17 -> V_92 = V_87 ;
V_89 = V_93 * V_17 -> V_92 ;
switch ( V_79 -> V_19 & V_94 ) {
default:
case V_95 :
V_17 -> V_96 =
( V_91 + ( V_89 / 2 ) ) / V_89 ;
V_17 -> V_97 =
( V_90 + ( V_89 / 2 ) ) / V_89 ;
break;
case V_98 :
V_17 -> V_96 =
( V_91 + ( V_89 - 1 ) ) / V_89 ;
V_17 -> V_97 =
( V_90 + ( V_89 - 1 ) ) / V_89 ;
break;
case V_99 :
V_17 -> V_96 = V_91 / V_89 ;
V_17 -> V_97 = V_90 / V_89 ;
break;
}
if ( V_17 -> V_96 < V_88 )
V_17 -> V_96 = V_88 ;
if ( V_17 -> V_96 > V_87 )
V_17 -> V_96 = V_87 ;
if ( V_17 -> V_97 < V_88 )
V_17 -> V_97 = V_88 ;
if ( V_17 -> V_97 > V_87 )
V_17 -> V_97 = V_87 ;
F_34 ( V_79 , V_9 ,
V_89 * V_17 -> V_96 ) ;
F_36 ( V_79 , V_9 ,
V_89 * V_17 -> V_97 ) ;
} else if ( V_90 ) {
F_38 ( V_93 ,
& V_17 -> V_97 ,
& V_17 -> V_92 ,
& V_90 , V_79 -> V_19 ) ;
F_36 ( V_79 , V_9 , V_90 ) ;
} else if ( V_91 ) {
F_38 ( V_93 ,
& V_17 -> V_96 ,
& V_17 -> V_92 ,
& V_91 , V_79 -> V_19 ) ;
F_34 ( V_79 , V_9 , V_91 ) ;
}
}
static enum V_30 F_39 ( const struct V_78 * V_79 )
{
if ( V_79 -> V_100 == 1 )
return V_35 ;
if ( V_79 -> V_101 == NULL )
return V_50 ;
if ( F_28 ( V_79 -> V_101 [ 0 ] ) == F_28 ( V_79 -> V_101 [ 1 ] ) )
return V_36 ;
if ( F_28 ( V_79 -> V_101 [ 0 ] ) < F_28 ( V_79 -> V_101 [ 1 ] ) )
return V_50 ;
if ( F_28 ( V_79 -> V_101 [ 0 ] ) > F_28 ( V_79 -> V_101 [ 1 ] ) )
return V_102 ;
F_40 ( L_1 ) ;
return 0 ;
}
static int F_41 ( struct V_4 * V_5 ,
struct V_14 * V_15 ,
struct V_78 * V_79 )
{
enum V_30 V_9 = F_39 ( V_79 ) ;
unsigned int V_103 = F_28 ( V_79 -> V_101 [ 0 ] ) ;
unsigned int V_104 = F_29 ( V_79 -> V_101 [ 0 ] ) ;
unsigned int V_105 = F_30 ( V_79 -> V_101 [ 0 ] ) ;
int V_68 ;
if ( V_9 == V_35 )
return 0 ;
for ( V_68 = 0 ; V_68 < V_79 -> V_100 ; V_68 ++ ) {
unsigned int V_31 = F_28 ( V_79 -> V_101 [ V_68 ] ) ;
unsigned int V_32 = F_29 ( V_79 -> V_101 [ V_68 ] ) ;
unsigned int V_33 = F_30 ( V_79 -> V_101 [ V_68 ] ) ;
switch ( V_9 ) {
case V_35 :
break;
case V_36 :
if ( V_31 != V_103 ) {
F_42 ( V_5 -> V_106 ,
L_2 ) ;
return - V_107 ;
}
break;
case V_50 :
if ( V_31 != V_68 ) {
F_42 ( V_5 -> V_106 ,
L_2 ) ;
return - V_107 ;
}
break;
case V_102 :
if ( V_31 != ( V_79 -> V_100 - V_68 - 1 ) ) {
F_42 ( V_5 -> V_106 ,
L_2 ) ;
return - V_107 ;
}
break;
}
if ( V_32 != V_104 ) {
F_42 ( V_5 -> V_106 ,
L_3 ) ;
return - V_107 ;
}
if ( V_33 != V_105 ) {
F_42 ( V_5 -> V_106 ,
L_4 ) ;
return - V_107 ;
}
}
return 0 ;
}
static int F_43 ( struct V_4 * V_5 ,
struct V_14 * V_15 , struct V_78 * V_79 )
{
const struct V_10 * V_11 = F_10 ( V_5 ) ;
int V_108 = 0 ;
int V_109 , V_110 ;
unsigned int V_111 ;
enum V_30 V_9 ;
V_108 |= F_44 ( & V_79 -> V_112 , V_113 | V_114 ) ;
V_108 |= F_44 ( & V_79 -> V_80 ,
V_83 | V_81 | V_114 ) ;
V_108 |= F_44 ( & V_79 -> V_82 , V_83 | V_114 ) ;
V_108 |= F_44 ( & V_79 -> V_115 , V_116 ) ;
V_111 = V_116 | V_117 ;
if ( V_11 -> V_34 )
V_111 |= V_114 ;
V_108 |= F_44 ( & V_79 -> V_118 , V_111 ) ;
if ( V_108 )
return 1 ;
V_108 |= F_45 ( V_79 -> V_112 ) ;
V_108 |= F_45 ( V_79 -> V_80 ) ;
V_108 |= F_45 ( V_79 -> V_82 ) ;
V_108 |= F_45 ( V_79 -> V_118 ) ;
if ( V_79 -> V_112 == V_114 && V_79 -> V_118 == V_114 )
V_108 ++ ;
if ( V_108 )
return 2 ;
switch ( V_79 -> V_112 ) {
case V_113 :
V_108 |= F_46 ( & V_79 -> V_119 , 0 ) ;
break;
case V_114 :
break;
}
if ( ! V_79 -> V_100 )
V_108 |= - V_107 ;
V_108 |= F_46 ( & V_79 -> V_120 , V_79 -> V_100 ) ;
if ( V_79 -> V_82 == V_83 )
V_108 |= F_47 ( & V_79 -> V_85 ,
V_11 -> V_121 ) ;
if ( V_79 -> V_80 == V_83 ) {
if ( V_79 -> V_82 == V_83 )
V_108 |= F_47 ( & V_79 -> V_84 ,
V_79 -> V_85 * V_79 -> V_100 ) ;
V_108 |= F_47 ( & V_79 -> V_84 ,
V_11 -> V_121 * V_79 -> V_100 ) ;
}
switch ( V_79 -> V_118 ) {
case V_116 :
V_108 |= F_47 ( & V_79 -> V_122 , 1 ) ;
break;
case V_117 :
V_108 |= F_46 ( & V_79 -> V_122 , 0 ) ;
break;
default:
break;
}
if ( V_108 )
return 3 ;
V_109 = V_79 -> V_85 ;
V_110 = V_79 -> V_84 ;
V_9 = F_39 ( V_79 ) ;
F_37 ( V_5 , V_79 , V_9 ) ;
if ( V_109 != V_79 -> V_85 || V_110 != V_79 -> V_84 )
V_108 ++ ;
if ( V_108 )
return 4 ;
if ( V_79 -> V_101 && V_79 -> V_100 > 0 )
V_108 |= F_41 ( V_5 , V_15 , V_79 ) ;
if ( V_108 )
return 5 ;
return 0 ;
}
static int F_48 ( struct V_4 * V_5 , struct V_14 * V_15 )
{
const struct V_10 * V_11 = F_10 ( V_5 ) ;
struct V_16 * V_17 = V_5 -> V_18 ;
struct V_123 * V_124 = V_15 -> V_124 ;
struct V_78 * V_79 = & V_124 -> V_79 ;
enum V_30 V_9 = F_39 ( V_79 ) ;
unsigned int V_66 = ( V_9 == V_50 )
? V_79 -> V_101 [ V_79 -> V_100 - 1 ]
: V_79 -> V_101 [ 0 ] ;
unsigned int V_31 = F_28 ( V_66 ) ;
unsigned int V_32 = F_29 ( V_66 ) ;
unsigned int V_33 = F_30 ( V_66 ) ;
enum V_40 V_41 ;
unsigned long V_19 ;
F_16 ( V_5 , V_15 ) ;
if ( V_79 -> V_118 == V_116 )
V_17 -> V_8 = V_79 -> V_122 * V_79 -> V_100 ;
if ( V_79 -> V_118 == V_114 ) {
F_9 ( V_5 , V_5 -> V_26 + V_74 ,
1 , 3 , V_125 ) ;
} else {
F_15 ( V_5 , V_5 -> V_26 + V_74 ,
1 , V_125 ) ;
}
if ( F_49 ( V_5 ) &&
( V_79 -> V_19 & ( V_126 | V_127 ) ) == 0 )
V_41 = V_128 ;
else if (
V_11 -> V_34 &&
( V_79 -> V_19 & V_126 ) == 0 &&
( V_79 -> V_118 != V_116 || V_17 -> V_8 > 256 ) )
V_41 = V_47 ;
else
V_41 = V_69 ;
V_17 -> V_129 = V_41 ;
F_19 ( V_5 , V_9 , V_31 , V_32 , V_33 ) ;
F_22 ( V_5 , V_15 , V_9 , V_41 , V_32 , V_33 ,
( V_79 -> V_118 == V_114 ) ) ;
if ( V_9 == V_50 || V_9 == V_102 ) {
V_17 -> V_38 |= V_130 ;
F_50 ( 1 ) ;
V_17 -> V_25 ( V_17 -> V_38 , V_5 -> V_26 + V_39 ) ;
}
V_17 -> V_25 ( V_79 -> V_100 ,
V_5 -> V_26 + V_131 ) ;
V_17 -> V_25 ( 0x1 , V_5 -> V_26 + V_132 ) ;
if ( V_79 -> V_82 == V_83 ||
V_79 -> V_80 == V_83 ) {
F_37 ( V_5 , V_79 , V_9 ) ;
F_9 ( V_5 , V_5 -> V_26 + V_133 ,
0 , V_17 -> V_92 , V_134 ) ;
}
if ( F_33 ( V_79 , V_9 ) ) {
F_9 ( V_5 , V_5 -> V_26 + V_74 ,
0 , V_17 -> V_96 , V_75 ) ;
} else {
F_15 ( V_5 , V_5 -> V_26 + V_74 ,
0 , V_75 ) ;
}
if ( F_35 ( V_79 , V_9 ) ) {
F_9 ( V_5 , V_5 -> V_26 + V_133 ,
1 , V_17 -> V_97 , V_75 ) ;
}
F_25 ( V_5 ) ;
if ( V_41 == V_128 )
F_51 ( V_5 , V_15 ) ;
V_17 -> V_28 |= V_135 ;
if ( V_41 == V_69 )
V_17 -> V_28 |= V_136 ;
V_17 -> V_25 ( V_17 -> V_28 , V_5 -> V_26 + V_29 ) ;
V_17 -> V_70 = 0 ;
if ( V_79 -> V_82 != V_114 )
V_17 -> V_70 |= V_71 ;
if ( ! F_32 ( V_79 , V_9 ) ) {
V_17 -> V_70 |= V_137 ;
if ( V_79 -> V_80 == V_114 )
V_17 -> V_70 |= V_138 ;
}
if ( V_33 == V_37 )
V_17 -> V_70 |= V_72 ;
V_17 -> V_25 ( V_17 -> V_70 , V_5 -> V_26 + V_73 ) ;
F_17 ( & V_5 -> V_20 , V_19 ) ;
V_17 -> V_21 |= V_139 ;
V_17 -> V_21 &= ~ ( V_22 | V_23 | V_24 ) ;
if ( V_79 -> V_112 == V_114 )
V_17 -> V_21 |= V_23 ;
else
V_17 -> V_21 |= V_22 ;
if ( V_79 -> V_118 == V_114 )
V_17 -> V_21 |= ( V_23 | V_24 ) ;
V_17 -> V_25 ( V_17 -> V_21 , V_5 -> V_26 + V_27 ) ;
F_18 ( & V_5 -> V_20 , V_19 ) ;
return 0 ;
}
static int F_52 ( struct V_4 * V_5 )
{
struct V_16 * V_17 = V_5 -> V_18 ;
struct V_123 * V_124 = V_5 -> V_140 -> V_124 ;
struct V_78 * V_79 = & V_124 -> V_79 ;
unsigned short V_65 ;
const int V_141 = 10000 ;
unsigned int V_68 ;
V_17 -> V_61 = V_17 -> V_54 ( V_5 -> V_26 + V_62 ) ;
for ( V_68 = 0 ; ( V_17 -> V_61 & V_63 ) && V_68 < V_141 ;
V_68 ++ ) {
if ( V_79 -> V_118 == V_116 ) {
if ( V_17 -> V_8 == 0 )
break;
V_17 -> V_8 -- ;
}
V_65 = F_24 ( V_5 ) ;
F_53 ( V_5 -> V_140 , V_65 ) ;
V_17 -> V_61 = V_17 -> V_54 ( V_5 -> V_26 + V_62 ) ;
}
if ( V_68 == V_141 ) {
F_54 ( V_5 , L_5 ) ;
V_124 -> V_142 |= V_143 | V_144 ;
return - 1 ;
}
return 0 ;
}
static void F_55 ( struct V_4 * V_5 )
{
struct V_16 * V_17 = V_5 -> V_18 ;
if ( V_17 -> V_129 == V_128 )
F_56 ( V_5 ) ;
F_52 ( V_5 ) ;
}
static T_1 F_57 ( int V_145 , void * V_146 )
{
struct V_4 * V_5 = V_146 ;
const struct V_10 * V_11 = F_10 ( V_5 ) ;
struct V_16 * V_17 = V_5 -> V_18 ;
struct V_14 * V_15 = V_5 -> V_140 ;
struct V_123 * V_124 ;
struct V_78 * V_79 ;
if ( ! V_5 -> V_147 ) {
F_54 ( V_5 , L_6 ) ;
return V_148 ;
}
V_124 = V_15 -> V_124 ;
V_79 = & V_124 -> V_79 ;
V_17 -> V_61 = V_17 -> V_54 ( V_5 -> V_26 + V_62 ) ;
if ( V_11 -> V_34 )
V_17 -> V_149 = V_17 -> V_54 ( V_5 -> V_26 + V_150 ) ;
if ( ( V_17 -> V_61 & ( V_151 | V_152 | V_153 |
V_154 | V_63 ) ) == 0
&& ( V_17 -> V_149 & V_155 ) == 0
&& ( V_17 -> V_149 & V_156 ) ) {
return V_157 ;
}
if ( V_17 -> V_61 & V_154 ) {
V_17 -> V_25 ( 0x1 , V_5 -> V_26 + V_57 ) ;
V_124 -> V_142 |= V_143 | V_144 ;
F_58 ( V_5 , V_15 ) ;
F_54 ( V_5 , L_7 ) ;
return V_148 ;
}
if ( V_17 -> V_129 == V_128 )
F_59 ( V_5 ) ;
else
F_52 ( V_5 ) ;
if ( V_17 -> V_61 & V_152 ) {
F_54 ( V_5 , L_8 ) ;
V_17 -> V_25 ( 0x1 , V_5 -> V_26 + V_158 ) ;
}
if ( V_17 -> V_61 & V_153 ) {
V_17 -> V_25 ( 0x1 , V_5 -> V_26 + V_57 ) ;
V_124 -> V_142 |= V_143 | V_144 ;
F_58 ( V_5 , V_15 ) ;
F_54 ( V_5 , L_9 ) ;
return V_148 ;
}
if ( V_79 -> V_118 == V_114 ) {
if ( V_17 -> V_149 & V_155 ) {
F_55 ( V_5 ) ;
V_124 -> V_142 |= V_144 ;
}
}
if ( V_79 -> V_118 == V_116 ) {
if ( V_17 -> V_8 == 0 )
V_124 -> V_142 |= V_144 ;
}
F_58 ( V_5 , V_15 ) ;
return V_148 ;
}
static int F_60 ( struct V_4 * V_5 ,
struct V_14 * V_15 ,
struct V_58 * V_59 ,
unsigned int * V_65 )
{
const struct V_10 * V_11 = F_10 ( V_5 ) ;
struct V_16 * V_17 = V_5 -> V_18 ;
int V_159 , V_32 ;
unsigned long V_19 ;
int V_53 , V_56 ;
V_159 = F_28 ( V_59 -> V_66 ) ;
F_17 ( & V_5 -> V_20 , V_19 ) ;
V_17 -> V_21 &= ~ F_61 ( V_159 ) ;
V_17 -> V_25 ( V_17 -> V_21 , V_5 -> V_26 + V_27 ) ;
F_18 ( & V_5 -> V_20 , V_19 ) ;
if ( V_11 -> V_34 ) {
V_32 = F_29 ( V_59 -> V_66 ) ;
if ( F_23 ( V_15 , V_32 ) )
V_17 -> V_44 |= F_62 ( V_159 ) ;
else
V_17 -> V_44 &= ~ F_62 ( V_159 ) ;
V_17 -> V_25 ( V_17 -> V_44 , V_5 -> V_26 + V_52 ) ;
}
V_53 = V_65 [ 0 ] & 0xff ;
V_56 = ( V_65 [ 0 ] >> 8 ) & 0xff ;
V_17 -> V_25 ( V_53 , V_5 -> V_26 + F_63 ( V_159 ) ) ;
V_17 -> V_25 ( V_56 , V_5 -> V_26 + F_64 ( V_159 ) ) ;
V_17 -> V_160 [ V_159 ] = V_65 [ 0 ] ;
return 1 ;
}
static int F_65 ( struct V_4 * V_5 ,
struct V_14 * V_15 ,
struct V_58 * V_59 ,
unsigned int * V_65 )
{
struct V_16 * V_17 = V_5 -> V_18 ;
V_65 [ 0 ] = V_17 -> V_160 [ F_28 ( V_59 -> V_66 ) ] ;
return 1 ;
}
static int F_66 ( int V_161 , int V_162 , int V_65 , unsigned long V_26 )
{
if ( V_161 ) {
F_8 ( V_65 , ( void V_3 * ) ( V_26 + V_162 ) ) ;
return 0 ;
} else {
return F_6 ( ( void V_3 * ) ( V_26 + V_162 ) ) ;
}
}
static void F_67 ( struct V_4 * V_5 , unsigned int V_163 ,
unsigned int V_164 )
{
struct V_16 * V_17 = V_5 -> V_18 ;
int V_68 ;
for ( V_68 = 1 ; V_68 <= V_164 ; V_68 ++ ) {
V_17 -> V_165 &= ~ V_166 ;
if ( V_163 & ( 1 << ( V_164 - V_68 ) ) )
V_17 -> V_165 |= V_167 ;
else
V_17 -> V_165 &= ~ V_167 ;
F_50 ( 1 ) ;
V_17 -> V_25 ( V_17 -> V_165 , V_5 -> V_26 + V_168 ) ;
V_17 -> V_165 |= V_166 ;
F_50 ( 1 ) ;
V_17 -> V_25 ( V_17 -> V_165 , V_5 -> V_26 + V_168 ) ;
}
}
static unsigned int F_68 ( struct V_4 * V_5 )
{
struct V_16 * V_17 = V_5 -> V_18 ;
unsigned int V_163 = 0 ;
int V_68 ;
const int V_164 = 8 ;
for ( V_68 = 1 ; V_68 <= V_164 ; V_68 ++ ) {
V_17 -> V_165 |= V_166 ;
F_50 ( 1 ) ;
V_17 -> V_25 ( V_17 -> V_165 , V_5 -> V_26 + V_168 ) ;
V_17 -> V_165 &= ~ V_166 ;
F_50 ( 1 ) ;
V_17 -> V_25 ( V_17 -> V_165 , V_5 -> V_26 + V_168 ) ;
F_50 ( 1 ) ;
V_17 -> V_149 = V_17 -> V_54 ( V_5 -> V_26 + V_150 ) ;
if ( V_17 -> V_149 & V_169 )
V_163 |= 1 << ( V_164 - V_68 ) ;
}
return V_163 ;
}
static unsigned int F_69 ( struct V_4 * V_5 ,
unsigned int V_1 )
{
struct V_16 * V_17 = V_5 -> V_18 ;
unsigned int V_163 ;
const int V_170 = 0x3 ;
const int V_171 = 8 ;
V_17 -> V_165 &= ~ V_172 ;
F_50 ( 1 ) ;
V_17 -> V_25 ( V_17 -> V_165 , V_5 -> V_26 + V_168 ) ;
V_17 -> V_165 |= ( V_172 | V_173 ) ;
F_50 ( 1 ) ;
V_17 -> V_25 ( V_17 -> V_165 , V_5 -> V_26 + V_168 ) ;
F_67 ( V_5 , V_170 , V_171 ) ;
F_67 ( V_5 , V_1 , V_171 ) ;
V_163 = F_68 ( V_5 ) ;
V_17 -> V_165 &= ~ ( V_172 | V_173 ) ;
F_50 ( 1 ) ;
V_17 -> V_25 ( V_17 -> V_165 , V_5 -> V_26 + V_168 ) ;
return V_163 ;
}
static unsigned int F_70 ( struct V_4 * V_5 )
{
struct V_16 * V_17 = V_5 -> V_18 ;
unsigned int V_163 ;
const int V_174 = 0x5 ;
const int V_171 = 8 ;
V_17 -> V_165 &= ~ V_172 ;
F_50 ( 1 ) ;
V_17 -> V_25 ( V_17 -> V_165 , V_5 -> V_26 + V_168 ) ;
V_17 -> V_165 |= ( V_172 | V_173 ) ;
F_50 ( 1 ) ;
V_17 -> V_25 ( V_17 -> V_165 , V_5 -> V_26 + V_168 ) ;
F_67 ( V_5 , V_174 , V_171 ) ;
V_163 = F_68 ( V_5 ) ;
V_17 -> V_165 &= ~ ( V_172 | V_173 ) ;
F_50 ( 1 ) ;
V_17 -> V_25 ( V_17 -> V_165 , V_5 -> V_26 + V_168 ) ;
return V_163 ;
}
static int F_71 ( struct V_4 * V_5 ,
unsigned int V_1 , unsigned int V_163 )
{
struct V_16 * V_17 = V_5 -> V_18 ;
const int V_175 = 0x6 ;
const int V_176 = 0x2 ;
const int V_171 = 8 ;
const int V_177 = 0x1 ;
const int V_141 = 10000 ;
int V_68 ;
for ( V_68 = 0 ; V_68 < V_141 ; V_68 ++ ) {
if ( ( F_70 ( V_5 ) & V_177 ) ==
0 )
break;
}
if ( V_68 == V_141 ) {
F_54 ( V_5 , L_10 ) ;
return - V_178 ;
}
V_17 -> V_179 [ V_1 ] = V_163 ;
V_17 -> V_165 &= ~ V_172 ;
F_50 ( 1 ) ;
V_17 -> V_25 ( V_17 -> V_165 , V_5 -> V_26 + V_168 ) ;
V_17 -> V_165 |= ( V_172 | V_173 ) ;
F_50 ( 1 ) ;
V_17 -> V_25 ( V_17 -> V_165 , V_5 -> V_26 + V_168 ) ;
F_67 ( V_5 , V_175 , V_171 ) ;
V_17 -> V_165 &= ~ V_172 ;
F_50 ( 1 ) ;
V_17 -> V_25 ( V_17 -> V_165 , V_5 -> V_26 + V_168 ) ;
V_17 -> V_165 |= V_172 ;
F_50 ( 1 ) ;
V_17 -> V_25 ( V_17 -> V_165 , V_5 -> V_26 + V_168 ) ;
F_67 ( V_5 , V_176 , V_171 ) ;
F_67 ( V_5 , V_1 , V_171 ) ;
F_67 ( V_5 , V_163 , V_171 ) ;
V_17 -> V_165 &= ~ V_172 ;
F_50 ( 1 ) ;
V_17 -> V_25 ( V_17 -> V_165 , V_5 -> V_26 + V_168 ) ;
V_17 -> V_165 &= ~ ( V_172 | V_173 ) ;
F_50 ( 1 ) ;
V_17 -> V_25 ( V_17 -> V_165 , V_5 -> V_26 + V_168 ) ;
return 0 ;
}
static void F_72 ( struct V_4 * V_5 , unsigned int V_159 ,
unsigned int V_163 )
{
struct V_16 * V_17 = V_5 -> V_18 ;
if ( V_163 == V_17 -> V_180 [ V_159 ] )
return;
V_17 -> V_180 [ V_159 ] = V_163 ;
V_17 -> V_165 &= ~ ( V_181 | V_172 | V_173 ) ;
F_50 ( 1 ) ;
V_17 -> V_25 ( V_17 -> V_165 , V_5 -> V_26 + V_168 ) ;
F_67 ( V_5 , V_159 , 4 ) ;
F_67 ( V_5 , V_163 , 8 ) ;
V_17 -> V_165 |= V_181 ;
F_50 ( 1 ) ;
V_17 -> V_25 ( V_17 -> V_165 , V_5 -> V_26 + V_168 ) ;
V_17 -> V_165 &= ~ V_181 ;
F_50 ( 1 ) ;
V_17 -> V_25 ( V_17 -> V_165 , V_5 -> V_26 + V_168 ) ;
}
static int F_73 ( struct V_4 * V_5 ,
struct V_14 * V_15 ,
struct V_58 * V_59 ,
unsigned int * V_65 )
{
unsigned int V_31 = F_28 ( V_59 -> V_66 ) ;
if ( V_59 -> V_76 > 0 )
F_72 ( V_5 , V_31 , V_65 [ V_59 -> V_76 - 1 ] ) ;
return V_59 -> V_76 ;
}
static int F_74 ( struct V_4 * V_5 ,
struct V_14 * V_15 ,
struct V_58 * V_59 ,
unsigned int * V_65 )
{
struct V_16 * V_17 = V_5 -> V_18 ;
unsigned int V_31 = F_28 ( V_59 -> V_66 ) ;
int V_68 ;
for ( V_68 = 0 ; V_68 < V_59 -> V_76 ; V_68 ++ )
V_65 [ V_68 ] = V_17 -> V_180 [ V_31 ] ;
return V_59 -> V_76 ;
}
static int F_75 ( struct V_4 * V_5 ,
struct V_14 * V_15 ,
struct V_58 * V_59 ,
unsigned int * V_65 )
{
unsigned int V_31 = F_28 ( V_59 -> V_66 ) ;
int V_67 ;
if ( V_31 < 16 || V_31 > 127 )
return - V_107 ;
if ( V_59 -> V_76 > 0 ) {
V_67 = F_71 ( V_5 , V_31 , V_65 [ V_59 -> V_76 - 1 ] ) ;
if ( V_67 )
return V_67 ;
}
return V_59 -> V_76 ;
}
static int F_76 ( struct V_4 * V_5 ,
struct V_14 * V_15 ,
struct V_58 * V_59 ,
unsigned int * V_65 )
{
struct V_16 * V_17 = V_5 -> V_18 ;
unsigned int V_31 = F_28 ( V_59 -> V_66 ) ;
int V_68 ;
for ( V_68 = 0 ; V_68 < V_59 -> V_76 ; V_68 ++ )
V_65 [ V_68 ] = V_17 -> V_179 [ V_31 ] ;
return V_59 -> V_76 ;
}
int F_77 ( struct V_4 * V_5 ,
unsigned int V_145 , unsigned long V_182 )
{
const struct V_10 * V_11 = F_10 ( V_5 ) ;
struct V_16 * V_17 = V_5 -> V_18 ;
struct V_14 * V_15 ;
int V_67 ;
int V_68 ;
if ( V_11 -> V_12 ) {
V_17 -> V_54 = F_5 ;
V_17 -> V_25 = F_7 ;
} else {
V_17 -> V_54 = F_1 ;
V_17 -> V_25 = F_3 ;
}
V_17 -> V_25 ( V_17 -> V_38 , V_5 -> V_26 + V_39 ) ;
V_17 -> V_25 ( V_17 -> V_21 , V_5 -> V_26 + V_27 ) ;
V_17 -> V_25 ( V_17 -> V_28 , V_5 -> V_26 + V_29 ) ;
V_17 -> V_25 ( V_17 -> V_70 , V_5 -> V_26 + V_73 ) ;
if ( V_11 -> V_34 ) {
V_17 -> V_25 ( V_17 -> V_165 , V_5 -> V_26 + V_168 ) ;
V_17 -> V_25 ( V_17 -> V_44 , V_5 -> V_26 + V_52 ) ;
}
if ( V_145 ) {
V_67 = F_78 ( V_145 , F_57 , V_182 ,
V_5 -> V_183 , V_5 ) ;
if ( V_67 == 0 )
V_5 -> V_145 = V_145 ;
}
V_67 = F_79 ( V_5 , 5 ) ;
if ( V_67 )
return V_67 ;
V_15 = & V_5 -> V_184 [ 0 ] ;
V_15 -> type = V_185 ;
V_15 -> V_186 = V_187 | V_188 | V_189 | V_190 ;
V_15 -> V_191 = 8 ;
V_15 -> V_192 = 8 ;
V_15 -> V_193 = 0x0fff ;
V_15 -> V_194 = V_11 -> V_34
? & V_195 : & V_196 ;
V_15 -> V_197 = F_27 ;
if ( V_5 -> V_145 ) {
V_5 -> V_140 = V_15 ;
V_15 -> V_186 |= V_198 ;
V_15 -> V_199 = F_48 ;
V_15 -> V_200 = F_43 ;
V_15 -> V_201 = F_16 ;
}
V_15 = & V_5 -> V_184 [ 1 ] ;
if ( V_11 -> V_202 ) {
V_15 -> type = V_203 ;
V_15 -> V_186 = V_187 | V_204 | V_188 ;
V_15 -> V_191 = V_205 ;
V_15 -> V_193 = 0x0fff ;
V_15 -> V_194 = & V_206 ;
V_15 -> V_197 = F_65 ;
V_15 -> V_207 = F_60 ;
for ( V_68 = 0 ; V_68 < V_15 -> V_191 ; V_68 ++ ) {
short V_53 , V_56 ;
V_17 -> V_160 [ V_68 ] = V_15 -> V_193 / 2 ;
V_53 = V_17 -> V_160 [ V_68 ] & 0xff ;
V_56 = ( V_17 -> V_160 [ V_68 ] >> 8 ) & 0xff ;
V_17 -> V_25 ( V_53 , V_5 -> V_26 + F_63 ( V_68 ) ) ;
V_17 -> V_25 ( V_56 , V_5 -> V_26 + F_64 ( V_68 ) ) ;
}
} else {
V_15 -> type = V_208 ;
}
V_15 = & V_5 -> V_184 [ 2 ] ;
V_67 = F_80 ( V_5 , V_15 ,
( V_11 -> V_12 ) ? F_66 : NULL ,
V_5 -> V_26 + V_209 ) ;
if ( V_67 )
return V_67 ;
V_15 = & V_5 -> V_184 [ 3 ] ;
if ( V_11 -> V_34 ) {
V_15 -> type = V_210 ;
V_15 -> V_186 = V_187 | V_204 | V_211 ;
V_15 -> V_191 = 16 ;
V_15 -> V_193 = 0xff ;
V_15 -> V_197 = F_74 ;
V_15 -> V_207 = F_73 ;
for ( V_68 = 0 ; V_68 < V_15 -> V_191 ; V_68 ++ )
F_72 ( V_5 , V_68 , V_15 -> V_193 / 2 ) ;
} else
V_15 -> type = V_208 ;
V_15 = & V_5 -> V_184 [ 4 ] ;
if ( V_11 -> V_34 ) {
V_15 -> type = V_212 ;
V_15 -> V_186 = V_187 | V_204 | V_211 ;
V_15 -> V_191 = V_213 ;
V_15 -> V_193 = 0xff ;
V_15 -> V_197 = F_76 ;
V_15 -> V_207 = F_75 ;
for ( V_68 = 0 ; V_68 < V_15 -> V_191 ; V_68 ++ )
V_17 -> V_179 [ V_68 ] = F_69 ( V_5 , V_68 ) ;
} else
V_15 -> type = V_208 ;
return 0 ;
}
static int F_81 ( struct V_4 * V_5 , struct V_214 * V_215 )
{
struct V_16 * V_17 ;
unsigned int V_145 = V_215 -> V_216 [ 1 ] ;
unsigned int V_217 = V_215 -> V_216 [ 2 ] ;
int V_67 ;
V_17 = F_82 ( V_5 , sizeof( * V_17 ) ) ;
if ( ! V_17 )
return - V_218 ;
V_67 = F_83 ( V_5 , V_215 -> V_216 [ 0 ] , V_219 ) ;
if ( V_67 )
return V_67 ;
V_67 = F_77 ( V_5 , V_145 , 0 ) ;
if ( V_67 )
return V_67 ;
if ( V_5 -> V_145 )
F_84 ( V_5 , V_217 ) ;
return 0 ;
}
static void F_85 ( struct V_4 * V_5 )
{
struct V_16 * V_17 = V_5 -> V_18 ;
if ( V_17 )
F_86 ( V_5 ) ;
F_87 ( V_5 ) ;
}
static int T_2 F_88 ( void )
{
return 0 ;
}
static void T_3 F_89 ( void )
{
}
