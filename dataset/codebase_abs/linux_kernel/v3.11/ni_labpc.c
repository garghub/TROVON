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
if ( V_11 -> V_35 ) {
V_15 += ( V_15 > 0 ) + ( V_15 > 7 ) ;
}
if ( ( V_9 == V_36 || V_9 == V_37 ) &&
V_34 == V_38 )
V_33 *= 2 ;
V_19 -> V_39 = F_21 ( V_33 ) ;
V_19 -> V_39 |= F_22 ( V_15 ) ;
V_19 -> V_27 ( V_19 -> V_39 , V_5 -> V_28 + V_40 ) ;
}
static void F_23 ( struct V_4 * V_5 ,
struct V_13 * V_14 ,
enum V_32 V_9 ,
enum V_41 V_42 ,
unsigned int V_15 ,
unsigned int V_34 ,
bool V_43 )
{
const struct V_10 * V_11 = F_10 ( V_5 ) ;
struct V_18 * V_19 = V_5 -> V_20 ;
if ( ! V_11 -> V_35 )
return;
if ( V_34 != V_44 )
V_19 -> V_45 |= V_46 ;
else
V_19 -> V_45 &= ~ V_46 ;
if ( F_16 ( V_14 , V_15 ) )
V_19 -> V_45 |= V_47 ;
else
V_19 -> V_45 &= ~ V_47 ;
if ( V_42 == V_48 )
V_19 -> V_45 |= V_49 ;
else
V_19 -> V_45 &= ~ V_49 ;
if ( V_43 )
V_19 -> V_45 |= V_50 ;
else
V_19 -> V_45 &= ~ V_50 ;
if ( V_9 == V_51 )
V_19 -> V_45 |= V_52 ;
else
V_19 -> V_45 &= ~ V_52 ;
V_19 -> V_27 ( V_19 -> V_45 , V_5 -> V_28 + V_53 ) ;
}
static unsigned int F_24 ( struct V_4 * V_5 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned int V_54 = V_19 -> V_55 ( V_5 -> V_28 + V_56 ) ;
unsigned int V_57 = V_19 -> V_55 ( V_5 -> V_28 + V_56 ) ;
return ( V_57 << 8 ) | V_54 ;
}
static void F_25 ( struct V_4 * V_5 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
V_19 -> V_27 ( 0x1 , V_5 -> V_28 + V_58 ) ;
F_24 ( V_5 ) ;
}
static int F_26 ( struct V_4 * V_5 ,
int V_59 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
int V_60 ;
for ( V_60 = 0 ; V_60 < V_59 ; V_60 ++ ) {
V_19 -> V_61 = V_19 -> V_55 ( V_5 -> V_28 + V_62 ) ;
if ( V_19 -> V_61 & V_63 )
return 0 ;
F_27 ( 1 ) ;
}
return - V_64 ;
}
static int F_28 ( struct V_4 * V_5 ,
struct V_13 * V_14 ,
struct V_65 * V_66 ,
unsigned int * V_67 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned int V_33 = F_29 ( V_66 -> V_68 ) ;
unsigned int V_15 = F_30 ( V_66 -> V_68 ) ;
unsigned int V_34 = F_31 ( V_66 -> V_68 ) ;
int V_69 ;
int V_60 ;
F_17 ( V_5 , V_14 ) ;
F_20 ( V_5 , V_36 , V_33 , V_15 , V_34 ) ;
F_23 ( V_5 , V_14 , V_36 , V_70 ,
V_15 , V_34 , false ) ;
V_19 -> V_71 = 0 ;
V_19 -> V_71 |= V_72 ;
if ( V_34 == V_38 )
V_19 -> V_71 |= V_73 ;
V_19 -> V_27 ( V_19 -> V_71 , V_5 -> V_28 + V_74 ) ;
V_69 = F_13 ( V_5 , V_5 -> V_28 + V_75 ,
0 , V_76 ) ;
if ( V_69 )
return V_69 ;
F_25 ( V_5 ) ;
for ( V_60 = 0 ; V_60 < V_66 -> V_77 ; V_60 ++ ) {
V_19 -> V_27 ( 0x1 , V_5 -> V_28 + V_78 ) ;
V_69 = F_26 ( V_5 , V_79 ) ;
if ( V_69 )
return V_69 ;
V_67 [ V_60 ] = F_24 ( V_5 ) ;
}
return V_66 -> V_77 ;
}
static unsigned int F_32 ( const struct V_80 * V_81 )
{
unsigned int V_82 ;
unsigned int V_83 ;
if ( V_81 -> V_84 == V_85 )
V_83 = 1000000000 / V_81 -> V_86 ;
else
V_83 = 0xffffffff ;
V_82 = ( V_83 / 3 ) * V_87 ;
if ( V_82 > V_88 )
V_82 = V_88 - V_88 % V_87 ;
else if ( V_82 < V_87 )
V_82 = V_87 ;
return V_82 ;
}
static bool F_33 ( const struct V_80 * V_81 ,
enum V_32 V_9 )
{
if ( V_9 == V_36 || V_81 -> V_89 == V_90 )
return true ;
return false ;
}
static unsigned int F_34 ( const struct V_80 * V_81 ,
enum V_32 V_9 )
{
if ( V_81 -> V_84 != V_85 )
return 0 ;
if ( V_9 == V_36 && V_81 -> V_89 == V_85 )
return V_81 -> V_91 ;
return V_81 -> V_86 ;
}
static void F_35 ( struct V_80 * V_81 ,
enum V_32 V_9 , unsigned int V_92 )
{
if ( V_81 -> V_84 != V_85 )
return;
if ( V_9 == V_36 &&
V_81 -> V_89 == V_85 ) {
V_81 -> V_91 = V_92 ;
if ( V_81 -> V_86 > V_81 -> V_91 )
V_81 -> V_86 = V_81 -> V_91 ;
} else
V_81 -> V_86 = V_92 ;
}
static unsigned int F_36 ( const struct V_80 * V_81 ,
enum V_32 V_9 )
{
if ( V_81 -> V_89 != V_85 )
return 0 ;
if ( V_9 == V_36 && V_81 -> V_84 == V_85 )
return 0 ;
return V_81 -> V_91 ;
}
static void F_37 ( struct V_80 * V_81 ,
enum V_32 V_9 , unsigned int V_92 )
{
if ( V_81 -> V_89 != V_85 )
return;
if ( V_9 == V_36 && V_81 -> V_84 == V_85 )
return;
V_81 -> V_91 = V_92 ;
}
static void F_38 ( struct V_4 * V_5 , struct V_80 * V_81 ,
enum V_32 V_9 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
const int V_93 = 0x10000 ;
const int V_94 = 2 ;
unsigned int V_95 ;
unsigned int V_96 ;
unsigned int V_97 ;
V_97 = F_34 ( V_81 , V_9 ) ;
V_96 = F_36 ( V_81 , V_9 ) ;
if ( V_97 && V_96 ) {
V_19 -> V_98 = ( V_96 - 1 ) /
( V_99 * V_93 ) + 1 ;
if ( V_19 -> V_98 < V_94 )
V_19 -> V_98 = V_94 ;
if ( V_19 -> V_98 > V_93 )
V_19 -> V_98 = V_93 ;
V_95 = V_99 * V_19 -> V_98 ;
switch ( V_81 -> V_21 & V_100 ) {
default:
case V_101 :
V_19 -> V_102 =
( V_97 + ( V_95 / 2 ) ) / V_95 ;
V_19 -> V_103 =
( V_96 + ( V_95 / 2 ) ) / V_95 ;
break;
case V_104 :
V_19 -> V_102 =
( V_97 + ( V_95 - 1 ) ) / V_95 ;
V_19 -> V_103 =
( V_96 + ( V_95 - 1 ) ) / V_95 ;
break;
case V_105 :
V_19 -> V_102 = V_97 / V_95 ;
V_19 -> V_103 = V_96 / V_95 ;
break;
}
if ( V_19 -> V_102 < V_94 )
V_19 -> V_102 = V_94 ;
if ( V_19 -> V_102 > V_93 )
V_19 -> V_102 = V_93 ;
if ( V_19 -> V_103 < V_94 )
V_19 -> V_103 = V_94 ;
if ( V_19 -> V_103 > V_93 )
V_19 -> V_103 = V_93 ;
F_35 ( V_81 , V_9 ,
V_95 * V_19 -> V_102 ) ;
F_37 ( V_81 , V_9 ,
V_95 * V_19 -> V_103 ) ;
} else if ( V_96 ) {
F_39 ( V_99 ,
& ( V_19 -> V_103 ) ,
& ( V_19 -> V_98 ) ,
& V_96 ,
V_81 -> V_21 & V_100 ) ;
F_37 ( V_81 , V_9 , V_96 ) ;
} else if ( V_97 ) {
F_39 ( V_99 ,
& ( V_19 -> V_102 ) ,
& ( V_19 -> V_98 ) ,
& V_97 ,
V_81 -> V_21 & V_100 ) ;
F_35 ( V_81 , V_9 , V_97 ) ;
}
}
static enum V_32 F_40 ( const struct V_80 * V_81 )
{
if ( V_81 -> V_106 == 1 )
return V_36 ;
if ( V_81 -> V_107 == NULL )
return V_51 ;
if ( F_29 ( V_81 -> V_107 [ 0 ] ) == F_29 ( V_81 -> V_107 [ 1 ] ) )
return V_37 ;
if ( F_29 ( V_81 -> V_107 [ 0 ] ) < F_29 ( V_81 -> V_107 [ 1 ] ) )
return V_51 ;
if ( F_29 ( V_81 -> V_107 [ 0 ] ) > F_29 ( V_81 -> V_107 [ 1 ] ) )
return V_108 ;
F_41 ( L_1 ) ;
return 0 ;
}
static int F_42 ( const struct V_4 * V_5 ,
const struct V_80 * V_81 ,
enum V_32 V_9 )
{
int V_109 , V_15 , V_34 , V_60 ;
if ( V_81 -> V_107 == NULL )
return 0 ;
if ( V_9 == V_36 )
return 0 ;
if ( V_9 == V_37 ) {
if ( V_81 -> V_106 > 0xff ) {
F_43 ( V_5 ,
L_2 ) ;
return 1 ;
}
}
V_109 = F_29 ( V_81 -> V_107 [ 0 ] ) ;
V_15 = F_30 ( V_81 -> V_107 [ 0 ] ) ;
V_34 = F_31 ( V_81 -> V_107 [ 0 ] ) ;
for ( V_60 = 0 ; V_60 < V_81 -> V_106 ; V_60 ++ ) {
switch ( V_9 ) {
case V_37 :
if ( F_29 ( V_81 -> V_107 [ V_60 ] ) != V_109 ) {
F_43 ( V_5 ,
L_3 ) ;
return 1 ;
}
break;
case V_51 :
if ( F_29 ( V_81 -> V_107 [ V_60 ] ) != V_60 ) {
F_43 ( V_5 ,
L_3 ) ;
return 1 ;
}
break;
case V_108 :
if ( F_29 ( V_81 -> V_107 [ V_60 ] ) !=
V_81 -> V_106 - V_60 - 1 ) {
F_43 ( V_5 ,
L_3 ) ;
return 1 ;
}
break;
default:
F_44 ( V_5 -> V_110 ,
L_4 ) ;
return 1 ;
break;
}
if ( F_30 ( V_81 -> V_107 [ V_60 ] ) != V_15 ) {
F_43 ( V_5 ,
L_5 ) ;
return 1 ;
}
if ( F_31 ( V_81 -> V_107 [ V_60 ] ) != V_34 ) {
F_43 ( V_5 ,
L_6 ) ;
return 1 ;
}
}
return 0 ;
}
static int F_45 ( struct V_4 * V_5 ,
struct V_13 * V_14 , struct V_80 * V_81 )
{
const struct V_10 * V_11 = F_10 ( V_5 ) ;
int V_111 = 0 ;
int V_112 , V_113 ;
unsigned int V_114 ;
enum V_32 V_9 ;
V_111 |= F_46 ( & V_81 -> V_115 , V_116 | V_117 ) ;
V_111 |= F_46 ( & V_81 -> V_89 ,
V_85 | V_90 | V_117 ) ;
V_111 |= F_46 ( & V_81 -> V_84 , V_85 | V_117 ) ;
V_111 |= F_46 ( & V_81 -> V_118 , V_119 ) ;
V_114 = V_119 | V_120 ;
if ( V_11 -> V_35 )
V_114 |= V_117 ;
V_111 |= F_46 ( & V_81 -> V_121 , V_114 ) ;
if ( V_111 )
return 1 ;
V_111 |= F_47 ( V_81 -> V_115 ) ;
V_111 |= F_47 ( V_81 -> V_89 ) ;
V_111 |= F_47 ( V_81 -> V_84 ) ;
V_111 |= F_47 ( V_81 -> V_121 ) ;
if ( V_81 -> V_115 == V_117 && V_81 -> V_121 == V_117 )
V_111 ++ ;
if ( V_111 )
return 2 ;
if ( V_81 -> V_122 == V_116 )
V_111 |= F_48 ( & V_81 -> V_122 , 0 ) ;
if ( ! V_81 -> V_106 )
V_111 |= - V_123 ;
V_111 |= F_48 ( & V_81 -> V_124 , V_81 -> V_106 ) ;
if ( V_81 -> V_84 == V_85 )
V_111 |= F_49 ( & V_81 -> V_86 ,
V_11 -> V_125 ) ;
if ( V_81 -> V_89 == V_85 ) {
if ( V_81 -> V_84 == V_85 )
V_111 |= F_49 ( & V_81 -> V_91 ,
V_81 -> V_86 * V_81 -> V_106 ) ;
V_111 |= F_49 ( & V_81 -> V_91 ,
V_11 -> V_125 * V_81 -> V_106 ) ;
}
switch ( V_81 -> V_121 ) {
case V_119 :
V_111 |= F_49 ( & V_81 -> V_126 , 1 ) ;
break;
case V_120 :
V_111 |= F_48 ( & V_81 -> V_126 , 0 ) ;
break;
default:
break;
}
if ( V_111 )
return 3 ;
V_112 = V_81 -> V_86 ;
V_113 = V_81 -> V_91 ;
V_9 = F_40 ( V_81 ) ;
F_38 ( V_5 , V_81 , V_9 ) ;
if ( V_112 != V_81 -> V_86 || V_113 != V_81 -> V_91 )
V_111 ++ ;
if ( V_111 )
return 4 ;
if ( F_42 ( V_5 , V_81 , V_9 ) )
return 5 ;
return 0 ;
}
static int F_50 ( struct V_4 * V_5 , struct V_13 * V_14 )
{
const struct V_10 * V_11 = F_10 ( V_5 ) ;
struct V_18 * V_19 = V_5 -> V_20 ;
struct V_127 * V_128 = V_14 -> V_128 ;
struct V_80 * V_81 = & V_128 -> V_81 ;
enum V_32 V_9 = F_40 ( V_81 ) ;
unsigned int V_68 = ( V_9 == V_51 )
? V_81 -> V_107 [ V_81 -> V_106 - 1 ]
: V_81 -> V_107 [ 0 ] ;
unsigned int V_33 = F_29 ( V_68 ) ;
unsigned int V_15 = F_30 ( V_68 ) ;
unsigned int V_34 = F_31 ( V_68 ) ;
enum V_41 V_42 ;
unsigned long V_21 ;
int V_69 ;
F_17 ( V_5 , V_14 ) ;
if ( V_81 -> V_121 == V_119 )
V_19 -> V_8 = V_81 -> V_126 * V_81 -> V_106 ;
if ( V_81 -> V_121 == V_117 ) {
V_69 = F_9 ( V_5 , V_5 -> V_28 + V_75 ,
1 , 3 , V_129 ) ;
} else {
V_69 = F_13 ( V_5 ,
V_5 -> V_28 + V_75 ,
1 , V_129 ) ;
}
if ( V_69 ) {
F_43 ( V_5 , L_7 ) ;
return V_69 ;
}
#ifdef F_51
if ( V_19 -> V_130 &&
( V_81 -> V_21 & ( V_131 | V_132 ) ) == 0 ) {
V_42 = V_133 ;
} else
#endif
if ( V_11 -> V_35 &&
( V_81 -> V_21 & V_131 ) == 0 &&
( V_81 -> V_121 != V_119 || V_19 -> V_8 > 256 ) ) {
V_42 = V_48 ;
} else
V_42 = V_70 ;
V_19 -> V_134 = V_42 ;
F_20 ( V_5 , V_9 , V_33 , V_15 , V_34 ) ;
F_23 ( V_5 , V_14 , V_9 , V_42 , V_15 , V_34 ,
( V_81 -> V_121 == V_117 ) ) ;
if ( V_9 == V_51 || V_9 == V_108 ) {
V_19 -> V_39 |= V_135 ;
F_27 ( 1 ) ;
V_19 -> V_27 ( V_19 -> V_39 , V_5 -> V_28 + V_40 ) ;
}
V_19 -> V_27 ( V_81 -> V_106 ,
V_5 -> V_28 + V_136 ) ;
V_19 -> V_27 ( 0x1 , V_5 -> V_28 + V_137 ) ;
if ( V_81 -> V_84 == V_85 ||
V_81 -> V_89 == V_85 ) {
F_38 ( V_5 , V_81 , V_9 ) ;
V_69 = F_9 ( V_5 , V_5 -> V_28 + V_138 ,
0 , V_19 -> V_98 , V_139 ) ;
if ( V_69 < 0 ) {
F_43 ( V_5 , L_8 ) ;
return - 1 ;
}
}
if ( F_34 ( V_81 , V_9 ) ) {
V_69 = F_9 ( V_5 , V_5 -> V_28 + V_75 ,
0 , V_19 -> V_102 , V_76 ) ;
} else {
V_69 = F_13 ( V_5 ,
V_5 -> V_28 + V_75 ,
0 , V_76 ) ;
}
if ( V_69 ) {
F_43 ( V_5 , L_9 ) ;
return V_69 ;
}
if ( F_36 ( V_81 , V_9 ) ) {
V_69 = F_9 ( V_5 , V_5 -> V_28 + V_138 ,
1 , V_19 -> V_103 , V_76 ) ;
if ( V_69 < 0 ) {
F_43 ( V_5 , L_10 ) ;
return - 1 ;
}
}
F_25 ( V_5 ) ;
#ifdef F_51
if ( V_42 == V_133 ) {
unsigned long V_140 ;
V_140 = F_52 () ;
F_53 ( V_19 -> V_130 ) ;
F_54 ( V_19 -> V_130 ) ;
F_55 ( V_19 -> V_130 , V_19 -> V_141 ) ;
V_19 -> V_142 = F_32 ( V_81 ) ;
if ( V_81 -> V_121 == V_119 &&
V_19 -> V_8 * V_87 < V_19 -> V_142 ) {
V_19 -> V_142 =
V_19 -> V_8 * V_87 ;
}
F_56 ( V_19 -> V_130 , V_19 -> V_142 ) ;
F_57 ( V_19 -> V_130 ) ;
F_58 ( V_140 ) ;
V_19 -> V_30 |= ( V_143 | V_144 ) ;
} else
V_19 -> V_30 &= ~ ( V_143 | V_144 ) ;
#endif
V_19 -> V_30 |= V_145 ;
if ( V_42 == V_70 )
V_19 -> V_30 |= V_146 ;
else
V_19 -> V_30 &= ~ V_146 ;
V_19 -> V_27 ( V_19 -> V_30 , V_5 -> V_28 + V_31 ) ;
V_19 -> V_71 = 0 ;
if ( V_81 -> V_84 != V_117 )
V_19 -> V_71 |= V_72 ;
if ( ! F_33 ( V_81 , V_9 ) ) {
V_19 -> V_71 |= V_147 ;
if ( V_81 -> V_89 == V_117 )
V_19 -> V_71 |= V_148 ;
}
if ( V_34 == V_38 )
V_19 -> V_71 |= V_73 ;
V_19 -> V_27 ( V_19 -> V_71 , V_5 -> V_28 + V_74 ) ;
F_18 ( & V_5 -> V_22 , V_21 ) ;
V_19 -> V_23 |= V_149 ;
V_19 -> V_23 &= ~ ( V_24 | V_25 | V_26 ) ;
if ( V_81 -> V_115 == V_117 )
V_19 -> V_23 |= V_25 ;
else
V_19 -> V_23 |= V_24 ;
if ( V_81 -> V_121 == V_117 )
V_19 -> V_23 |= ( V_25 | V_26 ) ;
V_19 -> V_27 ( V_19 -> V_23 , V_5 -> V_28 + V_29 ) ;
F_19 ( & V_5 -> V_22 , V_21 ) ;
return 0 ;
}
static void F_59 ( struct V_4 * V_5 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
struct V_13 * V_14 = V_5 -> V_150 ;
struct V_127 * V_128 = V_14 -> V_128 ;
int V_151 ;
unsigned long V_21 ;
unsigned int V_152 , V_153 , V_154 , V_155 ;
int V_60 ;
V_151 = V_19 -> V_61 ;
V_21 = F_52 () ;
F_53 ( V_19 -> V_130 ) ;
F_54 ( V_19 -> V_130 ) ;
V_152 = V_19 -> V_142 / V_87 ;
V_154 = F_60 ( V_19 -> V_130 ) / V_87 ;
V_153 = V_152 - V_154 ;
if ( V_19 -> V_8 < V_153 && V_128 -> V_81 . V_121 == V_119 )
V_153 = V_19 -> V_8 ;
V_155 = 0 ;
if ( V_128 -> V_81 . V_121 != V_119 ) {
V_155 = V_19 -> V_142 / V_87 ;
} else if ( V_19 -> V_8 > V_153 ) {
V_155 = V_19 -> V_8 - V_153 ;
if ( V_155 > V_152 )
V_155 = V_152 ;
}
for ( V_60 = 0 ; V_60 < V_153 ; V_60 ++ )
F_61 ( V_14 , V_19 -> V_156 [ V_60 ] ) ;
if ( V_128 -> V_81 . V_121 == V_119 )
V_19 -> V_8 -= V_153 ;
F_55 ( V_19 -> V_130 , V_19 -> V_141 ) ;
F_56 ( V_19 -> V_130 , V_155 * V_87 ) ;
F_58 ( V_21 ) ;
V_128 -> V_157 |= V_158 ;
}
static void F_62 ( struct V_4 * V_5 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
F_59 ( V_5 ) ;
F_57 ( V_19 -> V_130 ) ;
V_19 -> V_27 ( 0x1 , V_5 -> V_28 + V_159 ) ;
}
static int F_63 ( struct V_4 * V_5 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
short V_67 ;
struct V_127 * V_128 = V_5 -> V_150 -> V_128 ;
const int V_59 = 10000 ;
unsigned int V_60 ;
V_19 -> V_61 = V_19 -> V_55 ( V_5 -> V_28 + V_62 ) ;
for ( V_60 = 0 ; ( V_19 -> V_61 & V_63 ) && V_60 < V_59 ;
V_60 ++ ) {
if ( V_128 -> V_81 . V_121 == V_119 ) {
if ( V_19 -> V_8 == 0 )
break;
V_19 -> V_8 -- ;
}
V_67 = F_24 ( V_5 ) ;
F_61 ( V_5 -> V_150 , V_67 ) ;
V_19 -> V_61 = V_19 -> V_55 ( V_5 -> V_28 + V_62 ) ;
}
if ( V_60 == V_59 ) {
F_43 ( V_5 , L_11 ) ;
V_128 -> V_157 |= V_160 | V_161 ;
return - 1 ;
}
return 0 ;
}
static void F_64 ( struct V_4 * V_5 )
{
#ifdef F_51
struct V_18 * V_19 = V_5 -> V_20 ;
if ( V_19 -> V_134 == V_133 )
F_59 ( V_5 ) ;
#endif
F_63 ( V_5 ) ;
}
static T_1 F_65 ( int V_162 , void * V_163 )
{
struct V_4 * V_5 = V_163 ;
const struct V_10 * V_11 = F_10 ( V_5 ) ;
struct V_18 * V_19 = V_5 -> V_20 ;
struct V_13 * V_14 = V_5 -> V_150 ;
struct V_127 * V_128 ;
struct V_80 * V_81 ;
if ( ! V_5 -> V_164 ) {
F_43 ( V_5 , L_12 ) ;
return V_165 ;
}
V_128 = V_14 -> V_128 ;
V_81 = & V_128 -> V_81 ;
V_128 -> V_157 = 0 ;
V_19 -> V_61 = V_19 -> V_55 ( V_5 -> V_28 + V_62 ) ;
if ( V_11 -> V_35 )
V_19 -> V_166 = V_19 -> V_55 ( V_5 -> V_28 + V_167 ) ;
if ( ( V_19 -> V_61 & ( V_168 | V_169 | V_170 |
V_171 | V_63 ) ) == 0
&& ( V_19 -> V_166 & V_172 ) == 0
&& ( V_19 -> V_166 & V_173 ) ) {
return V_174 ;
}
if ( V_19 -> V_61 & V_171 ) {
V_19 -> V_27 ( 0x1 , V_5 -> V_28 + V_58 ) ;
V_128 -> V_157 |= V_160 | V_161 ;
F_66 ( V_5 , V_14 ) ;
F_43 ( V_5 , L_13 ) ;
return V_165 ;
}
#ifdef F_51
if ( V_19 -> V_134 == V_133 ) {
if ( V_19 -> V_61 & V_168 ||
( V_11 -> V_35 && V_19 -> V_166 & V_172 ) ) {
F_62 ( V_5 ) ;
}
} else
#endif
F_63 ( V_5 ) ;
if ( V_19 -> V_61 & V_169 ) {
F_43 ( V_5 , L_14 ) ;
V_19 -> V_27 ( 0x1 , V_5 -> V_28 + V_175 ) ;
}
if ( V_19 -> V_61 & V_170 ) {
V_19 -> V_27 ( 0x1 , V_5 -> V_28 + V_58 ) ;
V_128 -> V_157 |= V_160 | V_161 ;
F_66 ( V_5 , V_14 ) ;
F_43 ( V_5 , L_15 ) ;
return V_165 ;
}
if ( V_81 -> V_121 == V_117 ) {
if ( V_19 -> V_166 & V_172 ) {
F_64 ( V_5 ) ;
F_17 ( V_5 , V_14 ) ;
V_128 -> V_157 |= V_161 ;
}
}
if ( V_81 -> V_121 == V_119 ) {
if ( V_19 -> V_8 == 0 ) {
F_17 ( V_5 , V_14 ) ;
V_128 -> V_157 |= V_161 ;
}
}
F_66 ( V_5 , V_14 ) ;
return V_165 ;
}
static int F_67 ( struct V_4 * V_5 ,
struct V_13 * V_14 ,
struct V_65 * V_66 ,
unsigned int * V_67 )
{
const struct V_10 * V_11 = F_10 ( V_5 ) ;
struct V_18 * V_19 = V_5 -> V_20 ;
int V_109 , V_15 ;
unsigned long V_21 ;
int V_54 , V_57 ;
V_109 = F_29 ( V_66 -> V_68 ) ;
F_18 ( & V_5 -> V_22 , V_21 ) ;
V_19 -> V_23 &= ~ F_68 ( V_109 ) ;
V_19 -> V_27 ( V_19 -> V_23 , V_5 -> V_28 + V_29 ) ;
F_19 ( & V_5 -> V_22 , V_21 ) ;
if ( V_11 -> V_35 ) {
V_15 = F_30 ( V_66 -> V_68 ) ;
if ( F_16 ( V_14 , V_15 ) )
V_19 -> V_45 |= F_69 ( V_109 ) ;
else
V_19 -> V_45 &= ~ F_69 ( V_109 ) ;
V_19 -> V_27 ( V_19 -> V_45 , V_5 -> V_28 + V_53 ) ;
}
V_54 = V_67 [ 0 ] & 0xff ;
V_57 = ( V_67 [ 0 ] >> 8 ) & 0xff ;
V_19 -> V_27 ( V_54 , V_5 -> V_28 + F_70 ( V_109 ) ) ;
V_19 -> V_27 ( V_57 , V_5 -> V_28 + F_71 ( V_109 ) ) ;
V_19 -> V_176 [ V_109 ] = V_67 [ 0 ] ;
return 1 ;
}
static int F_72 ( struct V_4 * V_5 ,
struct V_13 * V_14 ,
struct V_65 * V_66 ,
unsigned int * V_67 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
V_67 [ 0 ] = V_19 -> V_176 [ F_29 ( V_66 -> V_68 ) ] ;
return 1 ;
}
static int F_73 ( int V_177 , int V_178 , int V_67 , unsigned long V_28 )
{
if ( V_177 ) {
F_8 ( V_67 , ( void V_3 * ) ( V_28 + V_178 ) ) ;
return 0 ;
} else {
return F_6 ( ( void V_3 * ) ( V_28 + V_178 ) ) ;
}
}
static void F_74 ( struct V_4 * V_5 , unsigned int V_179 ,
unsigned int V_180 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
int V_60 ;
for ( V_60 = 1 ; V_60 <= V_180 ; V_60 ++ ) {
V_19 -> V_181 &= ~ V_182 ;
if ( V_179 & ( 1 << ( V_180 - V_60 ) ) )
V_19 -> V_181 |= V_183 ;
else
V_19 -> V_181 &= ~ V_183 ;
F_27 ( 1 ) ;
V_19 -> V_27 ( V_19 -> V_181 , V_5 -> V_28 + V_184 ) ;
V_19 -> V_181 |= V_182 ;
F_27 ( 1 ) ;
V_19 -> V_27 ( V_19 -> V_181 , V_5 -> V_28 + V_184 ) ;
}
}
static unsigned int F_75 ( struct V_4 * V_5 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned int V_179 = 0 ;
int V_60 ;
const int V_180 = 8 ;
for ( V_60 = 1 ; V_60 <= V_180 ; V_60 ++ ) {
V_19 -> V_181 |= V_182 ;
F_27 ( 1 ) ;
V_19 -> V_27 ( V_19 -> V_181 , V_5 -> V_28 + V_184 ) ;
V_19 -> V_181 &= ~ V_182 ;
F_27 ( 1 ) ;
V_19 -> V_27 ( V_19 -> V_181 , V_5 -> V_28 + V_184 ) ;
F_27 ( 1 ) ;
V_19 -> V_166 = V_19 -> V_55 ( V_5 -> V_28 + V_167 ) ;
if ( V_19 -> V_166 & V_185 )
V_179 |= 1 << ( V_180 - V_60 ) ;
}
return V_179 ;
}
static unsigned int F_76 ( struct V_4 * V_5 ,
unsigned int V_1 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned int V_179 ;
const int V_186 = 0x3 ;
const int V_187 = 8 ;
V_19 -> V_181 &= ~ V_188 ;
F_27 ( 1 ) ;
V_19 -> V_27 ( V_19 -> V_181 , V_5 -> V_28 + V_184 ) ;
V_19 -> V_181 |= ( V_188 | V_189 ) ;
F_27 ( 1 ) ;
V_19 -> V_27 ( V_19 -> V_181 , V_5 -> V_28 + V_184 ) ;
F_74 ( V_5 , V_186 , V_187 ) ;
F_74 ( V_5 , V_1 , V_187 ) ;
V_179 = F_75 ( V_5 ) ;
V_19 -> V_181 &= ~ ( V_188 | V_189 ) ;
F_27 ( 1 ) ;
V_19 -> V_27 ( V_19 -> V_181 , V_5 -> V_28 + V_184 ) ;
return V_179 ;
}
static unsigned int F_77 ( struct V_4 * V_5 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned int V_179 ;
const int V_190 = 0x5 ;
const int V_187 = 8 ;
V_19 -> V_181 &= ~ V_188 ;
F_27 ( 1 ) ;
V_19 -> V_27 ( V_19 -> V_181 , V_5 -> V_28 + V_184 ) ;
V_19 -> V_181 |= ( V_188 | V_189 ) ;
F_27 ( 1 ) ;
V_19 -> V_27 ( V_19 -> V_181 , V_5 -> V_28 + V_184 ) ;
F_74 ( V_5 , V_190 , V_187 ) ;
V_179 = F_75 ( V_5 ) ;
V_19 -> V_181 &= ~ ( V_188 | V_189 ) ;
F_27 ( 1 ) ;
V_19 -> V_27 ( V_19 -> V_181 , V_5 -> V_28 + V_184 ) ;
return V_179 ;
}
static int F_78 ( struct V_4 * V_5 ,
unsigned int V_1 , unsigned int V_179 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
const int V_191 = 0x6 ;
const int V_192 = 0x2 ;
const int V_187 = 8 ;
const int V_193 = 0x1 ;
const int V_59 = 10000 ;
int V_60 ;
for ( V_60 = 0 ; V_60 < V_59 ; V_60 ++ ) {
if ( ( F_77 ( V_5 ) & V_193 ) ==
0 )
break;
}
if ( V_60 == V_59 ) {
F_43 ( V_5 , L_16 ) ;
return - V_64 ;
}
V_19 -> V_194 [ V_1 ] = V_179 ;
V_19 -> V_181 &= ~ V_188 ;
F_27 ( 1 ) ;
V_19 -> V_27 ( V_19 -> V_181 , V_5 -> V_28 + V_184 ) ;
V_19 -> V_181 |= ( V_188 | V_189 ) ;
F_27 ( 1 ) ;
V_19 -> V_27 ( V_19 -> V_181 , V_5 -> V_28 + V_184 ) ;
F_74 ( V_5 , V_191 , V_187 ) ;
V_19 -> V_181 &= ~ V_188 ;
F_27 ( 1 ) ;
V_19 -> V_27 ( V_19 -> V_181 , V_5 -> V_28 + V_184 ) ;
V_19 -> V_181 |= V_188 ;
F_27 ( 1 ) ;
V_19 -> V_27 ( V_19 -> V_181 , V_5 -> V_28 + V_184 ) ;
F_74 ( V_5 , V_192 , V_187 ) ;
F_74 ( V_5 , V_1 , V_187 ) ;
F_74 ( V_5 , V_179 , V_187 ) ;
V_19 -> V_181 &= ~ V_188 ;
F_27 ( 1 ) ;
V_19 -> V_27 ( V_19 -> V_181 , V_5 -> V_28 + V_184 ) ;
V_19 -> V_181 &= ~ ( V_188 | V_189 ) ;
F_27 ( 1 ) ;
V_19 -> V_27 ( V_19 -> V_181 , V_5 -> V_28 + V_184 ) ;
return 0 ;
}
static void F_79 ( struct V_4 * V_5 , unsigned int V_109 ,
unsigned int V_179 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
if ( V_179 == V_19 -> V_195 [ V_109 ] )
return;
V_19 -> V_195 [ V_109 ] = V_179 ;
V_19 -> V_181 &= ~ ( V_196 | V_188 | V_189 ) ;
F_27 ( 1 ) ;
V_19 -> V_27 ( V_19 -> V_181 , V_5 -> V_28 + V_184 ) ;
F_74 ( V_5 , V_109 , 4 ) ;
F_74 ( V_5 , V_179 , 8 ) ;
V_19 -> V_181 |= V_196 ;
F_27 ( 1 ) ;
V_19 -> V_27 ( V_19 -> V_181 , V_5 -> V_28 + V_184 ) ;
V_19 -> V_181 &= ~ V_196 ;
F_27 ( 1 ) ;
V_19 -> V_27 ( V_19 -> V_181 , V_5 -> V_28 + V_184 ) ;
}
static int F_80 ( struct V_4 * V_5 ,
struct V_13 * V_14 ,
struct V_65 * V_66 ,
unsigned int * V_67 )
{
unsigned int V_33 = F_29 ( V_66 -> V_68 ) ;
if ( V_66 -> V_77 > 0 )
F_79 ( V_5 , V_33 , V_67 [ V_66 -> V_77 - 1 ] ) ;
return V_66 -> V_77 ;
}
static int F_81 ( struct V_4 * V_5 ,
struct V_13 * V_14 ,
struct V_65 * V_66 ,
unsigned int * V_67 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned int V_33 = F_29 ( V_66 -> V_68 ) ;
int V_60 ;
for ( V_60 = 0 ; V_60 < V_66 -> V_77 ; V_60 ++ )
V_67 [ V_60 ] = V_19 -> V_195 [ V_33 ] ;
return V_66 -> V_77 ;
}
static int F_82 ( struct V_4 * V_5 ,
struct V_13 * V_14 ,
struct V_65 * V_66 ,
unsigned int * V_67 )
{
unsigned int V_33 = F_29 ( V_66 -> V_68 ) ;
int V_69 ;
if ( V_33 < 16 || V_33 > 127 )
return - V_123 ;
if ( V_66 -> V_77 > 0 ) {
V_69 = F_78 ( V_5 , V_33 , V_67 [ V_66 -> V_77 - 1 ] ) ;
if ( V_69 )
return V_69 ;
}
return V_66 -> V_77 ;
}
static int F_83 ( struct V_4 * V_5 ,
struct V_13 * V_14 ,
struct V_65 * V_66 ,
unsigned int * V_67 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned int V_33 = F_29 ( V_66 -> V_68 ) ;
int V_60 ;
for ( V_60 = 0 ; V_60 < V_66 -> V_77 ; V_60 ++ )
V_67 [ V_60 ] = V_19 -> V_194 [ V_33 ] ;
return V_66 -> V_77 ;
}
int F_84 ( struct V_4 * V_5 ,
unsigned int V_162 , unsigned long V_197 )
{
const struct V_10 * V_11 = F_10 ( V_5 ) ;
struct V_18 * V_19 = V_5 -> V_20 ;
struct V_13 * V_14 ;
int V_69 ;
int V_60 ;
if ( V_11 -> V_12 ) {
V_19 -> V_55 = F_5 ;
V_19 -> V_27 = F_7 ;
} else {
V_19 -> V_55 = F_1 ;
V_19 -> V_27 = F_3 ;
}
V_19 -> V_27 ( V_19 -> V_39 , V_5 -> V_28 + V_40 ) ;
V_19 -> V_27 ( V_19 -> V_23 , V_5 -> V_28 + V_29 ) ;
V_19 -> V_27 ( V_19 -> V_30 , V_5 -> V_28 + V_31 ) ;
V_19 -> V_27 ( V_19 -> V_71 , V_5 -> V_28 + V_74 ) ;
if ( V_11 -> V_35 ) {
V_19 -> V_27 ( V_19 -> V_181 , V_5 -> V_28 + V_184 ) ;
V_19 -> V_27 ( V_19 -> V_45 , V_5 -> V_28 + V_53 ) ;
}
if ( V_162 ) {
V_69 = F_85 ( V_162 , F_65 , V_197 ,
V_5 -> V_198 , V_5 ) ;
if ( V_69 == 0 )
V_5 -> V_162 = V_162 ;
}
V_69 = F_86 ( V_5 , 5 ) ;
if ( V_69 )
return V_69 ;
V_14 = & V_5 -> V_199 [ 0 ] ;
V_14 -> type = V_200 ;
V_14 -> V_201 = V_202 | V_203 | V_204 | V_205 ;
V_14 -> V_206 = 8 ;
V_14 -> V_207 = 8 ;
V_14 -> V_208 = 0x0fff ;
V_14 -> V_16 = V_11 -> V_35
? & V_209 : & V_210 ;
V_14 -> V_211 = F_28 ;
if ( V_5 -> V_162 ) {
V_5 -> V_150 = V_14 ;
V_14 -> V_201 |= V_212 ;
V_14 -> V_213 = F_50 ;
V_14 -> V_214 = F_45 ;
V_14 -> V_215 = F_17 ;
}
V_14 = & V_5 -> V_199 [ 1 ] ;
if ( V_11 -> V_216 ) {
V_14 -> type = V_217 ;
V_14 -> V_201 = V_202 | V_218 | V_203 ;
V_14 -> V_206 = V_219 ;
V_14 -> V_208 = 0x0fff ;
V_14 -> V_16 = & V_220 ;
V_14 -> V_211 = F_72 ;
V_14 -> V_221 = F_67 ;
for ( V_60 = 0 ; V_60 < V_14 -> V_206 ; V_60 ++ ) {
short V_54 , V_57 ;
V_19 -> V_176 [ V_60 ] = V_14 -> V_208 / 2 ;
V_54 = V_19 -> V_176 [ V_60 ] & 0xff ;
V_57 = ( V_19 -> V_176 [ V_60 ] >> 8 ) & 0xff ;
V_19 -> V_27 ( V_54 , V_5 -> V_28 + F_70 ( V_60 ) ) ;
V_19 -> V_27 ( V_57 , V_5 -> V_28 + F_71 ( V_60 ) ) ;
}
} else {
V_14 -> type = V_222 ;
}
V_14 = & V_5 -> V_199 [ 2 ] ;
V_69 = F_87 ( V_5 , V_14 ,
( V_11 -> V_12 ) ? F_73 : NULL ,
V_5 -> V_28 + V_223 ) ;
if ( V_69 )
return V_69 ;
V_14 = & V_5 -> V_199 [ 3 ] ;
if ( V_11 -> V_35 ) {
V_14 -> type = V_224 ;
V_14 -> V_201 = V_202 | V_218 | V_225 ;
V_14 -> V_206 = 16 ;
V_14 -> V_208 = 0xff ;
V_14 -> V_211 = F_81 ;
V_14 -> V_221 = F_80 ;
for ( V_60 = 0 ; V_60 < V_14 -> V_206 ; V_60 ++ )
F_79 ( V_5 , V_60 , V_14 -> V_208 / 2 ) ;
} else
V_14 -> type = V_222 ;
V_14 = & V_5 -> V_199 [ 4 ] ;
if ( V_11 -> V_35 ) {
V_14 -> type = V_226 ;
V_14 -> V_201 = V_202 | V_218 | V_225 ;
V_14 -> V_206 = V_227 ;
V_14 -> V_208 = 0xff ;
V_14 -> V_211 = F_83 ;
V_14 -> V_221 = F_82 ;
for ( V_60 = 0 ; V_60 < V_14 -> V_206 ; V_60 ++ )
V_19 -> V_194 [ V_60 ] = F_76 ( V_5 , V_60 ) ;
} else
V_14 -> type = V_222 ;
return 0 ;
}
static int F_88 ( struct V_4 * V_5 , struct V_228 * V_229 )
{
struct V_18 * V_19 ;
unsigned int V_162 = V_229 -> V_230 [ 1 ] ;
unsigned int V_130 = V_229 -> V_230 [ 2 ] ;
int V_69 ;
V_19 = F_89 ( sizeof( * V_19 ) , V_231 ) ;
if ( ! V_19 )
return - V_232 ;
V_5 -> V_20 = V_19 ;
V_69 = F_90 ( V_5 , V_229 -> V_230 [ 0 ] , V_233 ) ;
if ( V_69 )
return V_69 ;
V_69 = F_84 ( V_5 , V_162 , 0 ) ;
if ( V_69 )
return V_69 ;
#ifdef F_51
if ( V_5 -> V_162 && ( V_130 == 1 || V_130 == 3 ) ) {
V_19 -> V_156 = F_91 ( V_88 ,
V_231 | V_234 ) ;
if ( V_19 -> V_156 ) {
V_69 = F_92 ( V_130 , V_5 -> V_198 ) ;
if ( V_69 == 0 ) {
unsigned long V_235 ;
V_19 -> V_130 = V_130 ;
V_19 -> V_141 =
F_93 ( V_19 -> V_156 ) ;
V_235 = F_52 () ;
F_53 ( V_19 -> V_130 ) ;
F_94 ( V_19 -> V_130 , V_236 ) ;
F_58 ( V_235 ) ;
} else {
F_95 ( V_19 -> V_156 ) ;
}
}
}
#endif
return 0 ;
}
static void F_96 ( struct V_4 * V_5 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
if ( V_19 ) {
F_95 ( V_19 -> V_156 ) ;
if ( V_19 -> V_130 )
F_97 ( V_19 -> V_130 ) ;
}
F_98 ( V_5 ) ;
}
static int T_2 F_99 ( void )
{
return 0 ;
}
static void T_3 F_100 ( void )
{
}
