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
static int F_9 ( struct V_4 * V_5 ,
unsigned long V_6 ,
unsigned int V_7 ,
unsigned int V_8 , unsigned int V_9 )
{
const struct V_10 * V_11 = F_10 ( V_5 ) ;
if ( V_11 -> V_12 )
return F_11 ( ( void V_3 * ) V_6 , 0 ,
V_7 , V_8 , V_9 ) ;
else
return F_12 ( V_6 , 0 , V_7 , V_8 , V_9 ) ;
}
static int F_13 ( struct V_4 * V_5 ,
unsigned long V_6 ,
unsigned int V_7 ,
unsigned int V_9 )
{
const struct V_10 * V_11 = F_10 ( V_5 ) ;
if ( V_11 -> V_12 )
return F_14 ( ( void V_3 * ) V_6 , 0 ,
V_7 , V_9 ) ;
else
return F_15 ( V_6 , 0 , V_7 , V_9 ) ;
}
static bool F_16 ( struct V_13 * V_14 ,
unsigned int V_15 )
{
return V_14 -> V_16 -> V_15 [ V_15 ] . V_17 >= 0 ;
}
static int F_17 ( struct V_4 * V_5 , struct V_13 * V_14 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned long V_21 ;
F_18 ( & V_5 -> V_22 , V_21 ) ;
V_19 -> V_23 &= ~ ( V_24 | V_25 | V_26 ) ;
V_19 -> V_27 ( V_19 -> V_23 , V_5 -> V_28 + V_29 ) ;
F_19 ( & V_5 -> V_22 , V_21 ) ;
V_19 -> V_30 = 0 ;
V_19 -> V_27 ( V_19 -> V_30 , V_5 -> V_28 + V_31 ) ;
return 0 ;
}
static void F_20 ( struct V_4 * V_5 ,
enum V_32 V_9 ,
unsigned int V_33 ,
unsigned int V_15 ,
unsigned int V_34 )
{
const struct V_10 * V_11 = F_10 ( V_5 ) ;
struct V_18 * V_19 = V_5 -> V_20 ;
if ( ( V_9 == V_35 || V_9 == V_36 ) &&
V_34 == V_37 )
V_33 *= 2 ;
V_19 -> V_38 = F_21 ( V_33 ) ;
V_19 -> V_38 |= V_11 -> V_39 [ V_15 ] ;
V_19 -> V_27 ( V_19 -> V_38 , V_5 -> V_28 + V_40 ) ;
}
static void F_22 ( struct V_4 * V_5 ,
struct V_13 * V_14 ,
enum V_32 V_9 ,
enum V_41 V_42 ,
unsigned int V_15 ,
unsigned int V_34 ,
bool V_43 )
{
const struct V_10 * V_11 = F_10 ( V_5 ) ;
struct V_18 * V_19 = V_5 -> V_20 ;
if ( V_11 -> V_44 != V_45 )
return;
if ( V_34 != V_46 )
V_19 -> V_47 |= V_48 ;
else
V_19 -> V_47 &= ~ V_48 ;
if ( F_16 ( V_14 , V_15 ) )
V_19 -> V_47 |= V_49 ;
else
V_19 -> V_47 &= ~ V_49 ;
if ( V_42 == V_50 )
V_19 -> V_47 |= V_51 ;
else
V_19 -> V_47 &= ~ V_51 ;
if ( V_43 )
V_19 -> V_47 |= V_52 ;
else
V_19 -> V_47 &= ~ V_52 ;
if ( V_9 == V_53 )
V_19 -> V_47 |= V_54 ;
else
V_19 -> V_47 &= ~ V_54 ;
V_19 -> V_27 ( V_19 -> V_47 , V_5 -> V_28 + V_55 ) ;
}
static unsigned int F_23 ( struct V_4 * V_5 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned int V_56 = V_19 -> V_57 ( V_5 -> V_28 + V_58 ) ;
unsigned int V_59 = V_19 -> V_57 ( V_5 -> V_28 + V_58 ) ;
return ( V_59 << 8 ) | V_56 ;
}
static void F_24 ( struct V_4 * V_5 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
V_19 -> V_27 ( 0x1 , V_5 -> V_28 + V_60 ) ;
F_23 ( V_5 ) ;
}
static int F_25 ( struct V_4 * V_5 ,
int V_61 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
int V_62 ;
for ( V_62 = 0 ; V_62 < V_61 ; V_62 ++ ) {
V_19 -> V_63 = V_19 -> V_57 ( V_5 -> V_28 + V_64 ) ;
if ( V_19 -> V_63 & V_65 )
return 0 ;
F_26 ( 1 ) ;
}
return - V_66 ;
}
static int F_27 ( struct V_4 * V_5 ,
struct V_13 * V_14 ,
struct V_67 * V_68 ,
unsigned int * V_69 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned int V_33 = F_28 ( V_68 -> V_70 ) ;
unsigned int V_15 = F_29 ( V_68 -> V_70 ) ;
unsigned int V_34 = F_30 ( V_68 -> V_70 ) ;
int V_71 ;
int V_62 ;
F_17 ( V_5 , V_14 ) ;
F_20 ( V_5 , V_35 , V_33 , V_15 , V_34 ) ;
F_22 ( V_5 , V_14 , V_35 , V_72 ,
V_15 , V_34 , false ) ;
V_19 -> V_73 = 0 ;
V_19 -> V_73 |= V_74 ;
if ( V_34 == V_37 )
V_19 -> V_73 |= V_75 ;
V_19 -> V_27 ( V_19 -> V_73 , V_5 -> V_28 + V_76 ) ;
V_71 = F_13 ( V_5 , V_5 -> V_28 + V_77 ,
0 , V_78 ) ;
if ( V_71 )
return V_71 ;
F_24 ( V_5 ) ;
for ( V_62 = 0 ; V_62 < V_68 -> V_79 ; V_62 ++ ) {
V_19 -> V_27 ( 0x1 , V_5 -> V_28 + V_80 ) ;
V_71 = F_25 ( V_5 , V_81 ) ;
if ( V_71 )
return V_71 ;
V_69 [ V_62 ] = F_23 ( V_5 ) ;
}
return V_68 -> V_79 ;
}
static unsigned int F_31 ( const struct V_82 * V_83 )
{
unsigned int V_84 ;
unsigned int V_85 ;
if ( V_83 -> V_86 == V_87 )
V_85 = 1000000000 / V_83 -> V_88 ;
else
V_85 = 0xffffffff ;
V_84 = ( V_85 / 3 ) * V_89 ;
if ( V_84 > V_90 )
V_84 = V_90 - V_90 % V_89 ;
else if ( V_84 < V_89 )
V_84 = V_89 ;
return V_84 ;
}
static bool F_32 ( const struct V_82 * V_83 ,
enum V_32 V_9 )
{
if ( V_9 == V_35 || V_83 -> V_91 == V_92 )
return true ;
return false ;
}
static unsigned int F_33 ( const struct V_82 * V_83 ,
enum V_32 V_9 )
{
if ( V_83 -> V_86 != V_87 )
return 0 ;
if ( V_9 == V_35 && V_83 -> V_91 == V_87 )
return V_83 -> V_93 ;
return V_83 -> V_88 ;
}
static void F_34 ( struct V_82 * V_83 ,
enum V_32 V_9 , unsigned int V_94 )
{
if ( V_83 -> V_86 != V_87 )
return;
if ( V_9 == V_35 &&
V_83 -> V_91 == V_87 ) {
V_83 -> V_93 = V_94 ;
if ( V_83 -> V_88 > V_83 -> V_93 )
V_83 -> V_88 = V_83 -> V_93 ;
} else
V_83 -> V_88 = V_94 ;
}
static unsigned int F_35 ( const struct V_82 * V_83 ,
enum V_32 V_9 )
{
if ( V_83 -> V_91 != V_87 )
return 0 ;
if ( V_9 == V_35 && V_83 -> V_86 == V_87 )
return 0 ;
return V_83 -> V_93 ;
}
static void F_36 ( struct V_82 * V_83 ,
enum V_32 V_9 , unsigned int V_94 )
{
if ( V_83 -> V_91 != V_87 )
return;
if ( V_9 == V_35 && V_83 -> V_86 == V_87 )
return;
V_83 -> V_93 = V_94 ;
}
static void F_37 ( struct V_4 * V_5 , struct V_82 * V_83 ,
enum V_32 V_9 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
const int V_95 = 0x10000 ;
const int V_96 = 2 ;
unsigned int V_97 ;
unsigned int V_98 ;
unsigned int V_99 ;
V_99 = F_33 ( V_83 , V_9 ) ;
V_98 = F_35 ( V_83 , V_9 ) ;
if ( V_99 && V_98 ) {
V_19 -> V_100 = ( V_98 - 1 ) /
( V_101 * V_95 ) + 1 ;
if ( V_19 -> V_100 < V_96 )
V_19 -> V_100 = V_96 ;
if ( V_19 -> V_100 > V_95 )
V_19 -> V_100 = V_95 ;
V_97 = V_101 * V_19 -> V_100 ;
switch ( V_83 -> V_21 & V_102 ) {
default:
case V_103 :
V_19 -> V_104 =
( V_99 + ( V_97 / 2 ) ) / V_97 ;
V_19 -> V_105 =
( V_98 + ( V_97 / 2 ) ) / V_97 ;
break;
case V_106 :
V_19 -> V_104 =
( V_99 + ( V_97 - 1 ) ) / V_97 ;
V_19 -> V_105 =
( V_98 + ( V_97 - 1 ) ) / V_97 ;
break;
case V_107 :
V_19 -> V_104 = V_99 / V_97 ;
V_19 -> V_105 = V_98 / V_97 ;
break;
}
if ( V_19 -> V_104 < V_96 )
V_19 -> V_104 = V_96 ;
if ( V_19 -> V_104 > V_95 )
V_19 -> V_104 = V_95 ;
if ( V_19 -> V_105 < V_96 )
V_19 -> V_105 = V_96 ;
if ( V_19 -> V_105 > V_95 )
V_19 -> V_105 = V_95 ;
F_34 ( V_83 , V_9 ,
V_97 * V_19 -> V_104 ) ;
F_36 ( V_83 , V_9 ,
V_97 * V_19 -> V_105 ) ;
} else if ( V_98 ) {
F_38 ( V_101 ,
& ( V_19 -> V_105 ) ,
& ( V_19 -> V_100 ) ,
& V_98 ,
V_83 -> V_21 & V_102 ) ;
F_36 ( V_83 , V_9 , V_98 ) ;
} else if ( V_99 ) {
F_38 ( V_101 ,
& ( V_19 -> V_104 ) ,
& ( V_19 -> V_100 ) ,
& V_99 ,
V_83 -> V_21 & V_102 ) ;
F_34 ( V_83 , V_9 , V_99 ) ;
}
}
static enum V_32 F_39 ( const struct V_82 * V_83 )
{
if ( V_83 -> V_108 == 1 )
return V_35 ;
if ( V_83 -> V_109 == NULL )
return V_53 ;
if ( F_28 ( V_83 -> V_109 [ 0 ] ) == F_28 ( V_83 -> V_109 [ 1 ] ) )
return V_36 ;
if ( F_28 ( V_83 -> V_109 [ 0 ] ) < F_28 ( V_83 -> V_109 [ 1 ] ) )
return V_53 ;
if ( F_28 ( V_83 -> V_109 [ 0 ] ) > F_28 ( V_83 -> V_109 [ 1 ] ) )
return V_110 ;
F_40 ( L_1 ) ;
return 0 ;
}
static int F_41 ( const struct V_4 * V_5 ,
const struct V_82 * V_83 ,
enum V_32 V_9 )
{
int V_111 , V_15 , V_34 , V_62 ;
if ( V_83 -> V_109 == NULL )
return 0 ;
if ( V_9 == V_35 )
return 0 ;
if ( V_9 == V_36 ) {
if ( V_83 -> V_108 > 0xff ) {
F_42 ( V_5 ,
L_2 ) ;
return 1 ;
}
}
V_111 = F_28 ( V_83 -> V_109 [ 0 ] ) ;
V_15 = F_29 ( V_83 -> V_109 [ 0 ] ) ;
V_34 = F_30 ( V_83 -> V_109 [ 0 ] ) ;
for ( V_62 = 0 ; V_62 < V_83 -> V_108 ; V_62 ++ ) {
switch ( V_9 ) {
case V_36 :
if ( F_28 ( V_83 -> V_109 [ V_62 ] ) != V_111 ) {
F_42 ( V_5 ,
L_3 ) ;
return 1 ;
}
break;
case V_53 :
if ( F_28 ( V_83 -> V_109 [ V_62 ] ) != V_62 ) {
F_42 ( V_5 ,
L_3 ) ;
return 1 ;
}
break;
case V_110 :
if ( F_28 ( V_83 -> V_109 [ V_62 ] ) !=
V_83 -> V_108 - V_62 - 1 ) {
F_42 ( V_5 ,
L_3 ) ;
return 1 ;
}
break;
default:
F_43 ( V_5 -> V_112 ,
L_4 ) ;
return 1 ;
break;
}
if ( F_29 ( V_83 -> V_109 [ V_62 ] ) != V_15 ) {
F_42 ( V_5 ,
L_5 ) ;
return 1 ;
}
if ( F_30 ( V_83 -> V_109 [ V_62 ] ) != V_34 ) {
F_42 ( V_5 ,
L_6 ) ;
return 1 ;
}
}
return 0 ;
}
static int F_44 ( struct V_4 * V_5 ,
struct V_13 * V_14 , struct V_82 * V_83 )
{
const struct V_10 * V_11 = F_10 ( V_5 ) ;
int V_113 = 0 ;
int V_114 , V_115 ;
unsigned int V_116 ;
enum V_32 V_9 ;
V_113 |= F_45 ( & V_83 -> V_117 , V_118 | V_119 ) ;
V_113 |= F_45 ( & V_83 -> V_91 ,
V_87 | V_92 | V_119 ) ;
V_113 |= F_45 ( & V_83 -> V_86 , V_87 | V_119 ) ;
V_113 |= F_45 ( & V_83 -> V_120 , V_121 ) ;
V_116 = V_121 | V_122 ;
if ( V_11 -> V_44 == V_45 )
V_116 |= V_119 ;
V_113 |= F_45 ( & V_83 -> V_123 , V_116 ) ;
if ( V_113 )
return 1 ;
V_113 |= F_46 ( V_83 -> V_117 ) ;
V_113 |= F_46 ( V_83 -> V_91 ) ;
V_113 |= F_46 ( V_83 -> V_86 ) ;
V_113 |= F_46 ( V_83 -> V_123 ) ;
if ( V_83 -> V_117 == V_119 && V_83 -> V_123 == V_119 )
V_113 ++ ;
if ( V_113 )
return 2 ;
if ( V_83 -> V_124 == V_118 )
V_113 |= F_47 ( & V_83 -> V_124 , 0 ) ;
if ( ! V_83 -> V_108 )
V_113 |= - V_125 ;
V_113 |= F_47 ( & V_83 -> V_126 , V_83 -> V_108 ) ;
if ( V_83 -> V_86 == V_87 )
V_113 |= F_48 ( & V_83 -> V_88 ,
V_11 -> V_127 ) ;
if ( V_83 -> V_91 == V_87 ) {
if ( V_83 -> V_86 == V_87 )
V_113 |= F_48 ( & V_83 -> V_93 ,
V_83 -> V_88 * V_83 -> V_108 ) ;
V_113 |= F_48 ( & V_83 -> V_93 ,
V_11 -> V_127 * V_83 -> V_108 ) ;
}
switch ( V_83 -> V_123 ) {
case V_121 :
V_113 |= F_48 ( & V_83 -> V_128 , 1 ) ;
break;
case V_122 :
V_113 |= F_47 ( & V_83 -> V_128 , 0 ) ;
break;
default:
break;
}
if ( V_113 )
return 3 ;
V_114 = V_83 -> V_88 ;
V_115 = V_83 -> V_93 ;
V_9 = F_39 ( V_83 ) ;
F_37 ( V_5 , V_83 , V_9 ) ;
if ( V_114 != V_83 -> V_88 || V_115 != V_83 -> V_93 )
V_113 ++ ;
if ( V_113 )
return 4 ;
if ( F_41 ( V_5 , V_83 , V_9 ) )
return 5 ;
return 0 ;
}
static int F_49 ( struct V_4 * V_5 , struct V_13 * V_14 )
{
const struct V_10 * V_11 = F_10 ( V_5 ) ;
struct V_18 * V_19 = V_5 -> V_20 ;
struct V_129 * V_130 = V_14 -> V_130 ;
struct V_82 * V_83 = & V_130 -> V_83 ;
enum V_32 V_9 = F_39 ( V_83 ) ;
unsigned int V_70 = ( V_9 == V_53 )
? V_83 -> V_109 [ V_83 -> V_108 - 1 ]
: V_83 -> V_109 [ 0 ] ;
unsigned int V_33 = F_28 ( V_70 ) ;
unsigned int V_15 = F_29 ( V_70 ) ;
unsigned int V_34 = F_30 ( V_70 ) ;
enum V_41 V_42 ;
unsigned long V_21 ;
int V_71 ;
F_17 ( V_5 , V_14 ) ;
if ( V_83 -> V_123 == V_121 )
V_19 -> V_8 = V_83 -> V_128 * V_83 -> V_108 ;
if ( V_83 -> V_123 == V_119 ) {
V_71 = F_9 ( V_5 , V_5 -> V_28 + V_77 ,
1 , 3 , V_131 ) ;
} else {
V_71 = F_13 ( V_5 ,
V_5 -> V_28 + V_77 ,
1 , V_131 ) ;
}
if ( V_71 ) {
F_42 ( V_5 , L_7 ) ;
return V_71 ;
}
#ifdef F_50
if ( V_19 -> V_132 &&
( V_83 -> V_21 & ( V_133 | V_134 ) ) == 0 ) {
V_42 = V_135 ;
} else
#endif
if ( V_11 -> V_44 == V_45 &&
( V_83 -> V_21 & V_133 ) == 0 &&
( V_83 -> V_123 != V_121 || V_19 -> V_8 > 256 ) ) {
V_42 = V_50 ;
} else
V_42 = V_72 ;
V_19 -> V_136 = V_42 ;
F_20 ( V_5 , V_9 , V_33 , V_15 , V_34 ) ;
F_22 ( V_5 , V_14 , V_9 , V_42 , V_15 , V_34 ,
( V_83 -> V_123 == V_119 ) ) ;
if ( V_9 == V_53 || V_9 == V_110 ) {
V_19 -> V_38 |= V_137 ;
F_26 ( 1 ) ;
V_19 -> V_27 ( V_19 -> V_38 , V_5 -> V_28 + V_40 ) ;
}
V_19 -> V_27 ( V_83 -> V_108 ,
V_5 -> V_28 + V_138 ) ;
V_19 -> V_27 ( 0x1 , V_5 -> V_28 + V_139 ) ;
if ( V_83 -> V_86 == V_87 ||
V_83 -> V_91 == V_87 ) {
F_37 ( V_5 , V_83 , V_9 ) ;
V_71 = F_9 ( V_5 , V_5 -> V_28 + V_140 ,
0 , V_19 -> V_100 , V_141 ) ;
if ( V_71 < 0 ) {
F_42 ( V_5 , L_8 ) ;
return - 1 ;
}
}
if ( F_33 ( V_83 , V_9 ) ) {
V_71 = F_9 ( V_5 , V_5 -> V_28 + V_77 ,
0 , V_19 -> V_104 , V_78 ) ;
} else {
V_71 = F_13 ( V_5 ,
V_5 -> V_28 + V_77 ,
0 , V_78 ) ;
}
if ( V_71 ) {
F_42 ( V_5 , L_9 ) ;
return V_71 ;
}
if ( F_35 ( V_83 , V_9 ) ) {
V_71 = F_9 ( V_5 , V_5 -> V_28 + V_140 ,
1 , V_19 -> V_105 , V_78 ) ;
if ( V_71 < 0 ) {
F_42 ( V_5 , L_10 ) ;
return - 1 ;
}
}
F_24 ( V_5 ) ;
#ifdef F_50
if ( V_42 == V_135 ) {
unsigned long V_142 ;
V_142 = F_51 () ;
F_52 ( V_19 -> V_132 ) ;
F_53 ( V_19 -> V_132 ) ;
F_54 ( V_19 -> V_132 , V_19 -> V_143 ) ;
V_19 -> V_144 = F_31 ( V_83 ) ;
if ( V_83 -> V_123 == V_121 &&
V_19 -> V_8 * V_89 < V_19 -> V_144 ) {
V_19 -> V_144 =
V_19 -> V_8 * V_89 ;
}
F_55 ( V_19 -> V_132 , V_19 -> V_144 ) ;
F_56 ( V_19 -> V_132 ) ;
F_57 ( V_142 ) ;
V_19 -> V_30 |= ( V_145 | V_146 ) ;
} else
V_19 -> V_30 &= ~ ( V_145 | V_146 ) ;
#endif
V_19 -> V_30 |= V_147 ;
if ( V_42 == V_72 )
V_19 -> V_30 |= V_148 ;
else
V_19 -> V_30 &= ~ V_148 ;
V_19 -> V_27 ( V_19 -> V_30 , V_5 -> V_28 + V_31 ) ;
V_19 -> V_73 = 0 ;
if ( V_83 -> V_86 != V_119 )
V_19 -> V_73 |= V_74 ;
if ( ! F_32 ( V_83 , V_9 ) ) {
V_19 -> V_73 |= V_149 ;
if ( V_83 -> V_91 == V_119 )
V_19 -> V_73 |= V_150 ;
}
if ( V_34 == V_37 )
V_19 -> V_73 |= V_75 ;
V_19 -> V_27 ( V_19 -> V_73 , V_5 -> V_28 + V_76 ) ;
F_18 ( & V_5 -> V_22 , V_21 ) ;
V_19 -> V_23 |= V_151 ;
V_19 -> V_23 &= ~ ( V_24 | V_25 | V_26 ) ;
if ( V_83 -> V_117 == V_119 )
V_19 -> V_23 |= V_25 ;
else
V_19 -> V_23 |= V_24 ;
if ( V_83 -> V_123 == V_119 )
V_19 -> V_23 |= ( V_25 | V_26 ) ;
V_19 -> V_27 ( V_19 -> V_23 , V_5 -> V_28 + V_29 ) ;
F_19 ( & V_5 -> V_22 , V_21 ) ;
return 0 ;
}
static void F_58 ( struct V_4 * V_5 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
struct V_13 * V_14 = V_5 -> V_152 ;
struct V_129 * V_130 = V_14 -> V_130 ;
int V_153 ;
unsigned long V_21 ;
unsigned int V_154 , V_155 , V_156 , V_157 ;
int V_62 ;
V_153 = V_19 -> V_63 ;
V_21 = F_51 () ;
F_52 ( V_19 -> V_132 ) ;
F_53 ( V_19 -> V_132 ) ;
V_154 = V_19 -> V_144 / V_89 ;
V_156 = F_59 ( V_19 -> V_132 ) / V_89 ;
V_155 = V_154 - V_156 ;
if ( V_19 -> V_8 < V_155 && V_130 -> V_83 . V_123 == V_121 )
V_155 = V_19 -> V_8 ;
V_157 = 0 ;
if ( V_130 -> V_83 . V_123 != V_121 ) {
V_157 = V_19 -> V_144 / V_89 ;
} else if ( V_19 -> V_8 > V_155 ) {
V_157 = V_19 -> V_8 - V_155 ;
if ( V_157 > V_154 )
V_157 = V_154 ;
}
for ( V_62 = 0 ; V_62 < V_155 ; V_62 ++ )
F_60 ( V_14 , V_19 -> V_158 [ V_62 ] ) ;
if ( V_130 -> V_83 . V_123 == V_121 )
V_19 -> V_8 -= V_155 ;
F_54 ( V_19 -> V_132 , V_19 -> V_143 ) ;
F_55 ( V_19 -> V_132 , V_157 * V_89 ) ;
F_57 ( V_21 ) ;
V_130 -> V_159 |= V_160 ;
}
static void F_61 ( struct V_4 * V_5 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
F_58 ( V_5 ) ;
F_56 ( V_19 -> V_132 ) ;
V_19 -> V_27 ( 0x1 , V_5 -> V_28 + V_161 ) ;
}
static int F_62 ( struct V_4 * V_5 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
short V_69 ;
struct V_129 * V_130 = V_5 -> V_152 -> V_130 ;
const int V_61 = 10000 ;
unsigned int V_62 ;
V_19 -> V_63 = V_19 -> V_57 ( V_5 -> V_28 + V_64 ) ;
for ( V_62 = 0 ; ( V_19 -> V_63 & V_65 ) && V_62 < V_61 ;
V_62 ++ ) {
if ( V_130 -> V_83 . V_123 == V_121 ) {
if ( V_19 -> V_8 == 0 )
break;
V_19 -> V_8 -- ;
}
V_69 = F_23 ( V_5 ) ;
F_60 ( V_5 -> V_152 , V_69 ) ;
V_19 -> V_63 = V_19 -> V_57 ( V_5 -> V_28 + V_64 ) ;
}
if ( V_62 == V_61 ) {
F_42 ( V_5 , L_11 ) ;
V_130 -> V_159 |= V_162 | V_163 ;
return - 1 ;
}
return 0 ;
}
static void F_63 ( struct V_4 * V_5 )
{
#ifdef F_50
struct V_18 * V_19 = V_5 -> V_20 ;
if ( V_19 -> V_136 == V_135 )
F_58 ( V_5 ) ;
#endif
F_62 ( V_5 ) ;
}
static T_1 F_64 ( int V_164 , void * V_165 )
{
struct V_4 * V_5 = V_165 ;
const struct V_10 * V_11 = F_10 ( V_5 ) ;
struct V_18 * V_19 = V_5 -> V_20 ;
struct V_13 * V_14 = V_5 -> V_152 ;
struct V_129 * V_130 ;
struct V_82 * V_83 ;
if ( ! V_5 -> V_166 ) {
F_42 ( V_5 , L_12 ) ;
return V_167 ;
}
V_130 = V_14 -> V_130 ;
V_83 = & V_130 -> V_83 ;
V_130 -> V_159 = 0 ;
V_19 -> V_63 = V_19 -> V_57 ( V_5 -> V_28 + V_64 ) ;
if ( V_11 -> V_44 == V_45 )
V_19 -> V_168 = V_19 -> V_57 ( V_5 -> V_28 + V_169 ) ;
if ( ( V_19 -> V_63 & ( V_170 | V_171 | V_172 |
V_173 | V_65 ) ) == 0
&& ( V_19 -> V_168 & V_174 ) == 0
&& ( V_19 -> V_168 & V_175 ) ) {
return V_176 ;
}
if ( V_19 -> V_63 & V_173 ) {
V_19 -> V_27 ( 0x1 , V_5 -> V_28 + V_60 ) ;
V_130 -> V_159 |= V_162 | V_163 ;
F_65 ( V_5 , V_14 ) ;
F_42 ( V_5 , L_13 ) ;
return V_167 ;
}
#ifdef F_50
if ( V_19 -> V_136 == V_135 ) {
if ( V_19 -> V_63 & V_170 ||
( V_11 -> V_44 == V_45
&& V_19 -> V_168 & V_174 ) ) {
F_61 ( V_5 ) ;
}
} else
#endif
F_62 ( V_5 ) ;
if ( V_19 -> V_63 & V_171 ) {
F_42 ( V_5 , L_14 ) ;
V_19 -> V_27 ( 0x1 , V_5 -> V_28 + V_177 ) ;
}
if ( V_19 -> V_63 & V_172 ) {
V_19 -> V_27 ( 0x1 , V_5 -> V_28 + V_60 ) ;
V_130 -> V_159 |= V_162 | V_163 ;
F_65 ( V_5 , V_14 ) ;
F_42 ( V_5 , L_15 ) ;
return V_167 ;
}
if ( V_83 -> V_123 == V_119 ) {
if ( V_19 -> V_168 & V_174 ) {
F_63 ( V_5 ) ;
F_17 ( V_5 , V_14 ) ;
V_130 -> V_159 |= V_163 ;
}
}
if ( V_83 -> V_123 == V_121 ) {
if ( V_19 -> V_8 == 0 ) {
F_17 ( V_5 , V_14 ) ;
V_130 -> V_159 |= V_163 ;
}
}
F_65 ( V_5 , V_14 ) ;
return V_167 ;
}
static int F_66 ( struct V_4 * V_5 ,
struct V_13 * V_14 ,
struct V_67 * V_68 ,
unsigned int * V_69 )
{
const struct V_10 * V_11 = F_10 ( V_5 ) ;
struct V_18 * V_19 = V_5 -> V_20 ;
int V_111 , V_15 ;
unsigned long V_21 ;
int V_56 , V_59 ;
V_111 = F_28 ( V_68 -> V_70 ) ;
F_18 ( & V_5 -> V_22 , V_21 ) ;
V_19 -> V_23 &= ~ F_67 ( V_111 ) ;
V_19 -> V_27 ( V_19 -> V_23 , V_5 -> V_28 + V_29 ) ;
F_19 ( & V_5 -> V_22 , V_21 ) ;
if ( V_11 -> V_44 == V_45 ) {
V_15 = F_29 ( V_68 -> V_70 ) ;
if ( F_16 ( V_14 , V_15 ) )
V_19 -> V_47 |= F_68 ( V_111 ) ;
else
V_19 -> V_47 &= ~ F_68 ( V_111 ) ;
V_19 -> V_27 ( V_19 -> V_47 , V_5 -> V_28 + V_55 ) ;
}
V_56 = V_69 [ 0 ] & 0xff ;
V_59 = ( V_69 [ 0 ] >> 8 ) & 0xff ;
V_19 -> V_27 ( V_56 , V_5 -> V_28 + F_69 ( V_111 ) ) ;
V_19 -> V_27 ( V_59 , V_5 -> V_28 + F_70 ( V_111 ) ) ;
V_19 -> V_178 [ V_111 ] = V_69 [ 0 ] ;
return 1 ;
}
static int F_71 ( struct V_4 * V_5 ,
struct V_13 * V_14 ,
struct V_67 * V_68 ,
unsigned int * V_69 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
V_69 [ 0 ] = V_19 -> V_178 [ F_28 ( V_68 -> V_70 ) ] ;
return 1 ;
}
static int F_72 ( int V_179 , int V_180 , int V_69 , unsigned long V_28 )
{
if ( V_179 ) {
F_8 ( V_69 , ( void V_3 * ) ( V_28 + V_180 ) ) ;
return 0 ;
} else {
return F_6 ( ( void V_3 * ) ( V_28 + V_180 ) ) ;
}
}
static void F_73 ( struct V_4 * V_5 , unsigned int V_181 ,
unsigned int V_182 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
int V_62 ;
for ( V_62 = 1 ; V_62 <= V_182 ; V_62 ++ ) {
V_19 -> V_183 &= ~ V_184 ;
if ( V_181 & ( 1 << ( V_182 - V_62 ) ) )
V_19 -> V_183 |= V_185 ;
else
V_19 -> V_183 &= ~ V_185 ;
F_26 ( 1 ) ;
V_19 -> V_27 ( V_19 -> V_183 , V_5 -> V_28 + V_186 ) ;
V_19 -> V_183 |= V_184 ;
F_26 ( 1 ) ;
V_19 -> V_27 ( V_19 -> V_183 , V_5 -> V_28 + V_186 ) ;
}
}
static unsigned int F_74 ( struct V_4 * V_5 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned int V_181 = 0 ;
int V_62 ;
const int V_182 = 8 ;
for ( V_62 = 1 ; V_62 <= V_182 ; V_62 ++ ) {
V_19 -> V_183 |= V_184 ;
F_26 ( 1 ) ;
V_19 -> V_27 ( V_19 -> V_183 , V_5 -> V_28 + V_186 ) ;
V_19 -> V_183 &= ~ V_184 ;
F_26 ( 1 ) ;
V_19 -> V_27 ( V_19 -> V_183 , V_5 -> V_28 + V_186 ) ;
F_26 ( 1 ) ;
V_19 -> V_168 = V_19 -> V_57 ( V_5 -> V_28 + V_169 ) ;
if ( V_19 -> V_168 & V_187 )
V_181 |= 1 << ( V_182 - V_62 ) ;
}
return V_181 ;
}
static unsigned int F_75 ( struct V_4 * V_5 ,
unsigned int V_1 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned int V_181 ;
const int V_188 = 0x3 ;
const int V_189 = 8 ;
V_19 -> V_183 &= ~ V_190 ;
F_26 ( 1 ) ;
V_19 -> V_27 ( V_19 -> V_183 , V_5 -> V_28 + V_186 ) ;
V_19 -> V_183 |= ( V_190 | V_191 ) ;
F_26 ( 1 ) ;
V_19 -> V_27 ( V_19 -> V_183 , V_5 -> V_28 + V_186 ) ;
F_73 ( V_5 , V_188 , V_189 ) ;
F_73 ( V_5 , V_1 , V_189 ) ;
V_181 = F_74 ( V_5 ) ;
V_19 -> V_183 &= ~ ( V_190 | V_191 ) ;
F_26 ( 1 ) ;
V_19 -> V_27 ( V_19 -> V_183 , V_5 -> V_28 + V_186 ) ;
return V_181 ;
}
static unsigned int F_76 ( struct V_4 * V_5 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned int V_181 ;
const int V_192 = 0x5 ;
const int V_189 = 8 ;
V_19 -> V_183 &= ~ V_190 ;
F_26 ( 1 ) ;
V_19 -> V_27 ( V_19 -> V_183 , V_5 -> V_28 + V_186 ) ;
V_19 -> V_183 |= ( V_190 | V_191 ) ;
F_26 ( 1 ) ;
V_19 -> V_27 ( V_19 -> V_183 , V_5 -> V_28 + V_186 ) ;
F_73 ( V_5 , V_192 , V_189 ) ;
V_181 = F_74 ( V_5 ) ;
V_19 -> V_183 &= ~ ( V_190 | V_191 ) ;
F_26 ( 1 ) ;
V_19 -> V_27 ( V_19 -> V_183 , V_5 -> V_28 + V_186 ) ;
return V_181 ;
}
static int F_77 ( struct V_4 * V_5 ,
unsigned int V_1 , unsigned int V_181 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
const int V_193 = 0x6 ;
const int V_194 = 0x2 ;
const int V_189 = 8 ;
const int V_195 = 0x1 ;
const int V_61 = 10000 ;
int V_62 ;
for ( V_62 = 0 ; V_62 < V_61 ; V_62 ++ ) {
if ( ( F_76 ( V_5 ) & V_195 ) ==
0 )
break;
}
if ( V_62 == V_61 ) {
F_42 ( V_5 , L_16 ) ;
return - V_66 ;
}
V_19 -> V_196 [ V_1 ] = V_181 ;
V_19 -> V_183 &= ~ V_190 ;
F_26 ( 1 ) ;
V_19 -> V_27 ( V_19 -> V_183 , V_5 -> V_28 + V_186 ) ;
V_19 -> V_183 |= ( V_190 | V_191 ) ;
F_26 ( 1 ) ;
V_19 -> V_27 ( V_19 -> V_183 , V_5 -> V_28 + V_186 ) ;
F_73 ( V_5 , V_193 , V_189 ) ;
V_19 -> V_183 &= ~ V_190 ;
F_26 ( 1 ) ;
V_19 -> V_27 ( V_19 -> V_183 , V_5 -> V_28 + V_186 ) ;
V_19 -> V_183 |= V_190 ;
F_26 ( 1 ) ;
V_19 -> V_27 ( V_19 -> V_183 , V_5 -> V_28 + V_186 ) ;
F_73 ( V_5 , V_194 , V_189 ) ;
F_73 ( V_5 , V_1 , V_189 ) ;
F_73 ( V_5 , V_181 , V_189 ) ;
V_19 -> V_183 &= ~ V_190 ;
F_26 ( 1 ) ;
V_19 -> V_27 ( V_19 -> V_183 , V_5 -> V_28 + V_186 ) ;
V_19 -> V_183 &= ~ ( V_190 | V_191 ) ;
F_26 ( 1 ) ;
V_19 -> V_27 ( V_19 -> V_183 , V_5 -> V_28 + V_186 ) ;
return 0 ;
}
static void F_78 ( struct V_4 * V_5 , unsigned int V_111 ,
unsigned int V_181 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
if ( V_181 == V_19 -> V_197 [ V_111 ] )
return;
V_19 -> V_197 [ V_111 ] = V_181 ;
V_19 -> V_183 &= ~ ( V_198 | V_190 | V_191 ) ;
F_26 ( 1 ) ;
V_19 -> V_27 ( V_19 -> V_183 , V_5 -> V_28 + V_186 ) ;
F_73 ( V_5 , V_111 , 4 ) ;
F_73 ( V_5 , V_181 , 8 ) ;
V_19 -> V_183 |= V_198 ;
F_26 ( 1 ) ;
V_19 -> V_27 ( V_19 -> V_183 , V_5 -> V_28 + V_186 ) ;
V_19 -> V_183 &= ~ V_198 ;
F_26 ( 1 ) ;
V_19 -> V_27 ( V_19 -> V_183 , V_5 -> V_28 + V_186 ) ;
}
static int F_79 ( struct V_4 * V_5 ,
struct V_13 * V_14 ,
struct V_67 * V_68 ,
unsigned int * V_69 )
{
unsigned int V_33 = F_28 ( V_68 -> V_70 ) ;
if ( V_68 -> V_79 > 0 )
F_78 ( V_5 , V_33 , V_69 [ V_68 -> V_79 - 1 ] ) ;
return V_68 -> V_79 ;
}
static int F_80 ( struct V_4 * V_5 ,
struct V_13 * V_14 ,
struct V_67 * V_68 ,
unsigned int * V_69 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned int V_33 = F_28 ( V_68 -> V_70 ) ;
int V_62 ;
for ( V_62 = 0 ; V_62 < V_68 -> V_79 ; V_62 ++ )
V_69 [ V_62 ] = V_19 -> V_197 [ V_33 ] ;
return V_68 -> V_79 ;
}
static int F_81 ( struct V_4 * V_5 ,
struct V_13 * V_14 ,
struct V_67 * V_68 ,
unsigned int * V_69 )
{
unsigned int V_33 = F_28 ( V_68 -> V_70 ) ;
int V_71 ;
if ( V_33 < 16 || V_33 > 127 )
return - V_125 ;
if ( V_68 -> V_79 > 0 ) {
V_71 = F_77 ( V_5 , V_33 , V_69 [ V_68 -> V_79 - 1 ] ) ;
if ( V_71 )
return V_71 ;
}
return V_68 -> V_79 ;
}
static int F_82 ( struct V_4 * V_5 ,
struct V_13 * V_14 ,
struct V_67 * V_68 ,
unsigned int * V_69 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned int V_33 = F_28 ( V_68 -> V_70 ) ;
int V_62 ;
for ( V_62 = 0 ; V_62 < V_68 -> V_79 ; V_62 ++ )
V_69 [ V_62 ] = V_19 -> V_196 [ V_33 ] ;
return V_68 -> V_79 ;
}
int F_83 ( struct V_4 * V_5 ,
unsigned int V_164 , unsigned long V_199 )
{
const struct V_10 * V_11 = F_10 ( V_5 ) ;
struct V_18 * V_19 = V_5 -> V_20 ;
struct V_13 * V_14 ;
int V_71 ;
int V_62 ;
if ( V_11 -> V_12 ) {
V_19 -> V_57 = F_5 ;
V_19 -> V_27 = F_7 ;
} else {
V_19 -> V_57 = F_1 ;
V_19 -> V_27 = F_3 ;
}
V_19 -> V_27 ( V_19 -> V_38 , V_5 -> V_28 + V_40 ) ;
V_19 -> V_27 ( V_19 -> V_23 , V_5 -> V_28 + V_29 ) ;
V_19 -> V_27 ( V_19 -> V_30 , V_5 -> V_28 + V_31 ) ;
V_19 -> V_27 ( V_19 -> V_73 , V_5 -> V_28 + V_76 ) ;
if ( V_11 -> V_44 == V_45 ) {
V_19 -> V_27 ( V_19 -> V_183 , V_5 -> V_28 + V_186 ) ;
V_19 -> V_27 ( V_19 -> V_47 , V_5 -> V_28 + V_55 ) ;
}
if ( V_164 ) {
V_71 = F_84 ( V_164 , F_64 , V_199 ,
V_5 -> V_200 , V_5 ) ;
if ( V_71 == 0 )
V_5 -> V_164 = V_164 ;
}
V_71 = F_85 ( V_5 , 5 ) ;
if ( V_71 )
return V_71 ;
V_14 = & V_5 -> V_201 [ 0 ] ;
V_14 -> type = V_202 ;
V_14 -> V_203 = V_204 | V_205 | V_206 | V_207 ;
V_14 -> V_208 = 8 ;
V_14 -> V_209 = 8 ;
V_14 -> V_210 = 0x0fff ;
V_14 -> V_16 = V_11 -> V_211 ;
V_14 -> V_212 = F_27 ;
if ( V_5 -> V_164 ) {
V_5 -> V_152 = V_14 ;
V_14 -> V_203 |= V_213 ;
V_14 -> V_214 = F_49 ;
V_14 -> V_215 = F_44 ;
V_14 -> V_216 = F_17 ;
}
V_14 = & V_5 -> V_201 [ 1 ] ;
if ( V_11 -> V_217 ) {
V_14 -> type = V_218 ;
V_14 -> V_203 = V_204 | V_219 | V_205 ;
V_14 -> V_208 = V_220 ;
V_14 -> V_210 = 0x0fff ;
V_14 -> V_16 = & V_221 ;
V_14 -> V_212 = F_71 ;
V_14 -> V_222 = F_66 ;
for ( V_62 = 0 ; V_62 < V_14 -> V_208 ; V_62 ++ ) {
short V_56 , V_59 ;
V_19 -> V_178 [ V_62 ] = V_14 -> V_210 / 2 ;
V_56 = V_19 -> V_178 [ V_62 ] & 0xff ;
V_59 = ( V_19 -> V_178 [ V_62 ] >> 8 ) & 0xff ;
V_19 -> V_27 ( V_56 , V_5 -> V_28 + F_69 ( V_62 ) ) ;
V_19 -> V_27 ( V_59 , V_5 -> V_28 + F_70 ( V_62 ) ) ;
}
} else {
V_14 -> type = V_223 ;
}
V_14 = & V_5 -> V_201 [ 2 ] ;
V_71 = F_86 ( V_5 , V_14 ,
( V_11 -> V_12 ) ? F_72 : NULL ,
V_5 -> V_28 + V_224 ) ;
if ( V_71 )
return V_71 ;
V_14 = & V_5 -> V_201 [ 3 ] ;
if ( V_11 -> V_44 == V_45 ) {
V_14 -> type = V_225 ;
V_14 -> V_203 = V_204 | V_219 | V_226 ;
V_14 -> V_208 = 16 ;
V_14 -> V_210 = 0xff ;
V_14 -> V_212 = F_80 ;
V_14 -> V_222 = F_79 ;
for ( V_62 = 0 ; V_62 < V_14 -> V_208 ; V_62 ++ )
F_78 ( V_5 , V_62 , V_14 -> V_210 / 2 ) ;
} else
V_14 -> type = V_223 ;
V_14 = & V_5 -> V_201 [ 4 ] ;
if ( V_11 -> V_44 == V_45 ) {
V_14 -> type = V_227 ;
V_14 -> V_203 = V_204 | V_219 | V_226 ;
V_14 -> V_208 = V_228 ;
V_14 -> V_210 = 0xff ;
V_14 -> V_212 = F_82 ;
V_14 -> V_222 = F_81 ;
for ( V_62 = 0 ; V_62 < V_14 -> V_208 ; V_62 ++ )
V_19 -> V_196 [ V_62 ] = F_75 ( V_5 , V_62 ) ;
} else
V_14 -> type = V_223 ;
return 0 ;
}
void F_87 ( struct V_4 * V_5 )
{
F_88 ( V_5 , 2 ) ;
}
static int F_89 ( struct V_4 * V_5 , struct V_229 * V_230 )
{
struct V_18 * V_19 ;
unsigned int V_164 = V_230 -> V_231 [ 1 ] ;
unsigned int V_132 = V_230 -> V_231 [ 2 ] ;
int V_71 ;
V_19 = F_90 ( sizeof( * V_19 ) , V_232 ) ;
if ( ! V_19 )
return - V_233 ;
V_5 -> V_20 = V_19 ;
V_71 = F_91 ( V_5 , V_230 -> V_231 [ 0 ] , V_234 ) ;
if ( V_71 )
return V_71 ;
V_71 = F_83 ( V_5 , V_164 , 0 ) ;
if ( V_71 )
return V_71 ;
#ifdef F_50
if ( V_5 -> V_164 && ( V_132 == 1 || V_132 == 3 ) ) {
V_19 -> V_158 = F_92 ( V_90 ,
V_232 | V_235 ) ;
if ( V_19 -> V_158 ) {
V_71 = F_93 ( V_132 , V_5 -> V_200 ) ;
if ( V_71 == 0 ) {
unsigned long V_236 ;
V_19 -> V_132 = V_132 ;
V_19 -> V_143 =
F_94 ( V_19 -> V_158 ) ;
V_236 = F_51 () ;
F_52 ( V_19 -> V_132 ) ;
F_95 ( V_19 -> V_132 , V_237 ) ;
F_57 ( V_236 ) ;
} else {
F_96 ( V_19 -> V_158 ) ;
}
}
}
#endif
return 0 ;
}
static void F_97 ( struct V_4 * V_5 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
F_87 ( V_5 ) ;
if ( V_19 ) {
F_96 ( V_19 -> V_158 ) ;
if ( V_19 -> V_132 )
F_98 ( V_19 -> V_132 ) ;
}
F_99 ( V_5 ) ;
}
static int T_2 F_100 ( void )
{
return 0 ;
}
static void T_3 F_101 ( void )
{
}
