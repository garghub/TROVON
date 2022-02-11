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
static bool F_32 ( const struct V_80 * V_81 ,
enum V_32 V_9 )
{
if ( V_9 == V_36 || V_81 -> V_82 == V_83 )
return true ;
return false ;
}
static unsigned int F_33 ( const struct V_80 * V_81 ,
enum V_32 V_9 )
{
if ( V_81 -> V_84 != V_85 )
return 0 ;
if ( V_9 == V_36 && V_81 -> V_82 == V_85 )
return V_81 -> V_86 ;
return V_81 -> V_87 ;
}
static void F_34 ( struct V_80 * V_81 ,
enum V_32 V_9 , unsigned int V_88 )
{
if ( V_81 -> V_84 != V_85 )
return;
if ( V_9 == V_36 &&
V_81 -> V_82 == V_85 ) {
V_81 -> V_86 = V_88 ;
if ( V_81 -> V_87 > V_81 -> V_86 )
V_81 -> V_87 = V_81 -> V_86 ;
} else
V_81 -> V_87 = V_88 ;
}
static unsigned int F_35 ( const struct V_80 * V_81 ,
enum V_32 V_9 )
{
if ( V_81 -> V_82 != V_85 )
return 0 ;
if ( V_9 == V_36 && V_81 -> V_84 == V_85 )
return 0 ;
return V_81 -> V_86 ;
}
static void F_36 ( struct V_80 * V_81 ,
enum V_32 V_9 , unsigned int V_88 )
{
if ( V_81 -> V_82 != V_85 )
return;
if ( V_9 == V_36 && V_81 -> V_84 == V_85 )
return;
V_81 -> V_86 = V_88 ;
}
static void F_37 ( struct V_4 * V_5 , struct V_80 * V_81 ,
enum V_32 V_9 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
const int V_89 = 0x10000 ;
const int V_90 = 2 ;
unsigned int V_91 ;
unsigned int V_92 ;
unsigned int V_93 ;
V_93 = F_33 ( V_81 , V_9 ) ;
V_92 = F_35 ( V_81 , V_9 ) ;
if ( V_93 && V_92 ) {
V_19 -> V_94 = ( V_92 - 1 ) /
( V_95 * V_89 ) + 1 ;
if ( V_19 -> V_94 < V_90 )
V_19 -> V_94 = V_90 ;
if ( V_19 -> V_94 > V_89 )
V_19 -> V_94 = V_89 ;
V_91 = V_95 * V_19 -> V_94 ;
switch ( V_81 -> V_21 & V_96 ) {
default:
case V_97 :
V_19 -> V_98 =
( V_93 + ( V_91 / 2 ) ) / V_91 ;
V_19 -> V_99 =
( V_92 + ( V_91 / 2 ) ) / V_91 ;
break;
case V_100 :
V_19 -> V_98 =
( V_93 + ( V_91 - 1 ) ) / V_91 ;
V_19 -> V_99 =
( V_92 + ( V_91 - 1 ) ) / V_91 ;
break;
case V_101 :
V_19 -> V_98 = V_93 / V_91 ;
V_19 -> V_99 = V_92 / V_91 ;
break;
}
if ( V_19 -> V_98 < V_90 )
V_19 -> V_98 = V_90 ;
if ( V_19 -> V_98 > V_89 )
V_19 -> V_98 = V_89 ;
if ( V_19 -> V_99 < V_90 )
V_19 -> V_99 = V_90 ;
if ( V_19 -> V_99 > V_89 )
V_19 -> V_99 = V_89 ;
F_34 ( V_81 , V_9 ,
V_91 * V_19 -> V_98 ) ;
F_36 ( V_81 , V_9 ,
V_91 * V_19 -> V_99 ) ;
} else if ( V_92 ) {
F_38 ( V_95 ,
& ( V_19 -> V_99 ) ,
& ( V_19 -> V_94 ) ,
& V_92 ,
V_81 -> V_21 & V_96 ) ;
F_36 ( V_81 , V_9 , V_92 ) ;
} else if ( V_93 ) {
F_38 ( V_95 ,
& ( V_19 -> V_98 ) ,
& ( V_19 -> V_94 ) ,
& V_93 ,
V_81 -> V_21 & V_96 ) ;
F_34 ( V_81 , V_9 , V_93 ) ;
}
}
static enum V_32 F_39 ( const struct V_80 * V_81 )
{
if ( V_81 -> V_102 == 1 )
return V_36 ;
if ( V_81 -> V_103 == NULL )
return V_51 ;
if ( F_29 ( V_81 -> V_103 [ 0 ] ) == F_29 ( V_81 -> V_103 [ 1 ] ) )
return V_37 ;
if ( F_29 ( V_81 -> V_103 [ 0 ] ) < F_29 ( V_81 -> V_103 [ 1 ] ) )
return V_51 ;
if ( F_29 ( V_81 -> V_103 [ 0 ] ) > F_29 ( V_81 -> V_103 [ 1 ] ) )
return V_104 ;
F_40 ( L_1 ) ;
return 0 ;
}
static int F_41 ( const struct V_4 * V_5 ,
const struct V_80 * V_81 ,
enum V_32 V_9 )
{
int V_105 , V_15 , V_34 , V_60 ;
if ( V_81 -> V_103 == NULL )
return 0 ;
if ( V_9 == V_36 )
return 0 ;
if ( V_9 == V_37 ) {
if ( V_81 -> V_102 > 0xff ) {
F_42 ( V_5 ,
L_2 ) ;
return 1 ;
}
}
V_105 = F_29 ( V_81 -> V_103 [ 0 ] ) ;
V_15 = F_30 ( V_81 -> V_103 [ 0 ] ) ;
V_34 = F_31 ( V_81 -> V_103 [ 0 ] ) ;
for ( V_60 = 0 ; V_60 < V_81 -> V_102 ; V_60 ++ ) {
switch ( V_9 ) {
case V_37 :
if ( F_29 ( V_81 -> V_103 [ V_60 ] ) != V_105 ) {
F_42 ( V_5 ,
L_3 ) ;
return 1 ;
}
break;
case V_51 :
if ( F_29 ( V_81 -> V_103 [ V_60 ] ) != V_60 ) {
F_42 ( V_5 ,
L_3 ) ;
return 1 ;
}
break;
case V_104 :
if ( F_29 ( V_81 -> V_103 [ V_60 ] ) !=
V_81 -> V_102 - V_60 - 1 ) {
F_42 ( V_5 ,
L_3 ) ;
return 1 ;
}
break;
default:
F_43 ( V_5 -> V_106 ,
L_4 ) ;
return 1 ;
break;
}
if ( F_30 ( V_81 -> V_103 [ V_60 ] ) != V_15 ) {
F_42 ( V_5 ,
L_5 ) ;
return 1 ;
}
if ( F_31 ( V_81 -> V_103 [ V_60 ] ) != V_34 ) {
F_42 ( V_5 ,
L_6 ) ;
return 1 ;
}
}
return 0 ;
}
static int F_44 ( struct V_4 * V_5 ,
struct V_13 * V_14 , struct V_80 * V_81 )
{
const struct V_10 * V_11 = F_10 ( V_5 ) ;
int V_107 = 0 ;
int V_108 , V_109 ;
unsigned int V_110 ;
enum V_32 V_9 ;
V_107 |= F_45 ( & V_81 -> V_111 , V_112 | V_113 ) ;
V_107 |= F_45 ( & V_81 -> V_82 ,
V_85 | V_83 | V_113 ) ;
V_107 |= F_45 ( & V_81 -> V_84 , V_85 | V_113 ) ;
V_107 |= F_45 ( & V_81 -> V_114 , V_115 ) ;
V_110 = V_115 | V_116 ;
if ( V_11 -> V_35 )
V_110 |= V_113 ;
V_107 |= F_45 ( & V_81 -> V_117 , V_110 ) ;
if ( V_107 )
return 1 ;
V_107 |= F_46 ( V_81 -> V_111 ) ;
V_107 |= F_46 ( V_81 -> V_82 ) ;
V_107 |= F_46 ( V_81 -> V_84 ) ;
V_107 |= F_46 ( V_81 -> V_117 ) ;
if ( V_81 -> V_111 == V_113 && V_81 -> V_117 == V_113 )
V_107 ++ ;
if ( V_107 )
return 2 ;
if ( V_81 -> V_118 == V_112 )
V_107 |= F_47 ( & V_81 -> V_118 , 0 ) ;
if ( ! V_81 -> V_102 )
V_107 |= - V_119 ;
V_107 |= F_47 ( & V_81 -> V_120 , V_81 -> V_102 ) ;
if ( V_81 -> V_84 == V_85 )
V_107 |= F_48 ( & V_81 -> V_87 ,
V_11 -> V_121 ) ;
if ( V_81 -> V_82 == V_85 ) {
if ( V_81 -> V_84 == V_85 )
V_107 |= F_48 ( & V_81 -> V_86 ,
V_81 -> V_87 * V_81 -> V_102 ) ;
V_107 |= F_48 ( & V_81 -> V_86 ,
V_11 -> V_121 * V_81 -> V_102 ) ;
}
switch ( V_81 -> V_117 ) {
case V_115 :
V_107 |= F_48 ( & V_81 -> V_122 , 1 ) ;
break;
case V_116 :
V_107 |= F_47 ( & V_81 -> V_122 , 0 ) ;
break;
default:
break;
}
if ( V_107 )
return 3 ;
V_108 = V_81 -> V_87 ;
V_109 = V_81 -> V_86 ;
V_9 = F_39 ( V_81 ) ;
F_37 ( V_5 , V_81 , V_9 ) ;
if ( V_108 != V_81 -> V_87 || V_109 != V_81 -> V_86 )
V_107 ++ ;
if ( V_107 )
return 4 ;
if ( F_41 ( V_5 , V_81 , V_9 ) )
return 5 ;
return 0 ;
}
static int F_49 ( struct V_4 * V_5 , struct V_13 * V_14 )
{
const struct V_10 * V_11 = F_10 ( V_5 ) ;
struct V_18 * V_19 = V_5 -> V_20 ;
struct V_123 * V_124 = V_14 -> V_124 ;
struct V_80 * V_81 = & V_124 -> V_81 ;
enum V_32 V_9 = F_39 ( V_81 ) ;
unsigned int V_68 = ( V_9 == V_51 )
? V_81 -> V_103 [ V_81 -> V_102 - 1 ]
: V_81 -> V_103 [ 0 ] ;
unsigned int V_33 = F_29 ( V_68 ) ;
unsigned int V_15 = F_30 ( V_68 ) ;
unsigned int V_34 = F_31 ( V_68 ) ;
enum V_41 V_42 ;
unsigned long V_21 ;
int V_69 ;
F_17 ( V_5 , V_14 ) ;
if ( V_81 -> V_117 == V_115 )
V_19 -> V_8 = V_81 -> V_122 * V_81 -> V_102 ;
if ( V_81 -> V_117 == V_113 ) {
V_69 = F_9 ( V_5 , V_5 -> V_28 + V_75 ,
1 , 3 , V_125 ) ;
} else {
V_69 = F_13 ( V_5 ,
V_5 -> V_28 + V_75 ,
1 , V_125 ) ;
}
if ( V_69 ) {
F_42 ( V_5 , L_7 ) ;
return V_69 ;
}
if ( F_50 ( V_5 ) &&
( V_81 -> V_21 & ( V_126 | V_127 ) ) == 0 )
V_42 = V_128 ;
else if (
V_11 -> V_35 &&
( V_81 -> V_21 & V_126 ) == 0 &&
( V_81 -> V_117 != V_115 || V_19 -> V_8 > 256 ) )
V_42 = V_48 ;
else
V_42 = V_70 ;
V_19 -> V_129 = V_42 ;
F_20 ( V_5 , V_9 , V_33 , V_15 , V_34 ) ;
F_23 ( V_5 , V_14 , V_9 , V_42 , V_15 , V_34 ,
( V_81 -> V_117 == V_113 ) ) ;
if ( V_9 == V_51 || V_9 == V_104 ) {
V_19 -> V_39 |= V_130 ;
F_27 ( 1 ) ;
V_19 -> V_27 ( V_19 -> V_39 , V_5 -> V_28 + V_40 ) ;
}
V_19 -> V_27 ( V_81 -> V_102 ,
V_5 -> V_28 + V_131 ) ;
V_19 -> V_27 ( 0x1 , V_5 -> V_28 + V_132 ) ;
if ( V_81 -> V_84 == V_85 ||
V_81 -> V_82 == V_85 ) {
F_37 ( V_5 , V_81 , V_9 ) ;
V_69 = F_9 ( V_5 , V_5 -> V_28 + V_133 ,
0 , V_19 -> V_94 , V_134 ) ;
if ( V_69 < 0 ) {
F_42 ( V_5 , L_8 ) ;
return - 1 ;
}
}
if ( F_33 ( V_81 , V_9 ) ) {
V_69 = F_9 ( V_5 , V_5 -> V_28 + V_75 ,
0 , V_19 -> V_98 , V_76 ) ;
} else {
V_69 = F_13 ( V_5 ,
V_5 -> V_28 + V_75 ,
0 , V_76 ) ;
}
if ( V_69 ) {
F_42 ( V_5 , L_9 ) ;
return V_69 ;
}
if ( F_35 ( V_81 , V_9 ) ) {
V_69 = F_9 ( V_5 , V_5 -> V_28 + V_133 ,
1 , V_19 -> V_99 , V_76 ) ;
if ( V_69 < 0 ) {
F_42 ( V_5 , L_10 ) ;
return - 1 ;
}
}
F_25 ( V_5 ) ;
if ( V_42 == V_128 )
F_51 ( V_5 , V_14 ) ;
V_19 -> V_30 |= V_135 ;
if ( V_42 == V_70 )
V_19 -> V_30 |= V_136 ;
V_19 -> V_27 ( V_19 -> V_30 , V_5 -> V_28 + V_31 ) ;
V_19 -> V_71 = 0 ;
if ( V_81 -> V_84 != V_113 )
V_19 -> V_71 |= V_72 ;
if ( ! F_32 ( V_81 , V_9 ) ) {
V_19 -> V_71 |= V_137 ;
if ( V_81 -> V_82 == V_113 )
V_19 -> V_71 |= V_138 ;
}
if ( V_34 == V_38 )
V_19 -> V_71 |= V_73 ;
V_19 -> V_27 ( V_19 -> V_71 , V_5 -> V_28 + V_74 ) ;
F_18 ( & V_5 -> V_22 , V_21 ) ;
V_19 -> V_23 |= V_139 ;
V_19 -> V_23 &= ~ ( V_24 | V_25 | V_26 ) ;
if ( V_81 -> V_111 == V_113 )
V_19 -> V_23 |= V_25 ;
else
V_19 -> V_23 |= V_24 ;
if ( V_81 -> V_117 == V_113 )
V_19 -> V_23 |= ( V_25 | V_26 ) ;
V_19 -> V_27 ( V_19 -> V_23 , V_5 -> V_28 + V_29 ) ;
F_19 ( & V_5 -> V_22 , V_21 ) ;
return 0 ;
}
static int F_52 ( struct V_4 * V_5 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
short V_67 ;
struct V_123 * V_124 = V_5 -> V_140 -> V_124 ;
const int V_59 = 10000 ;
unsigned int V_60 ;
V_19 -> V_61 = V_19 -> V_55 ( V_5 -> V_28 + V_62 ) ;
for ( V_60 = 0 ; ( V_19 -> V_61 & V_63 ) && V_60 < V_59 ;
V_60 ++ ) {
if ( V_124 -> V_81 . V_117 == V_115 ) {
if ( V_19 -> V_8 == 0 )
break;
V_19 -> V_8 -- ;
}
V_67 = F_24 ( V_5 ) ;
F_53 ( V_5 -> V_140 , V_67 ) ;
V_19 -> V_61 = V_19 -> V_55 ( V_5 -> V_28 + V_62 ) ;
}
if ( V_60 == V_59 ) {
F_42 ( V_5 , L_11 ) ;
V_124 -> V_141 |= V_142 | V_143 ;
return - 1 ;
}
return 0 ;
}
static void F_54 ( struct V_4 * V_5 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
if ( V_19 -> V_129 == V_128 )
F_55 ( V_5 ) ;
F_52 ( V_5 ) ;
}
static T_1 F_56 ( int V_144 , void * V_145 )
{
struct V_4 * V_5 = V_145 ;
const struct V_10 * V_11 = F_10 ( V_5 ) ;
struct V_18 * V_19 = V_5 -> V_20 ;
struct V_13 * V_14 = V_5 -> V_140 ;
struct V_123 * V_124 ;
struct V_80 * V_81 ;
if ( ! V_5 -> V_146 ) {
F_42 ( V_5 , L_12 ) ;
return V_147 ;
}
V_124 = V_14 -> V_124 ;
V_81 = & V_124 -> V_81 ;
V_124 -> V_141 = 0 ;
V_19 -> V_61 = V_19 -> V_55 ( V_5 -> V_28 + V_62 ) ;
if ( V_11 -> V_35 )
V_19 -> V_148 = V_19 -> V_55 ( V_5 -> V_28 + V_149 ) ;
if ( ( V_19 -> V_61 & ( V_150 | V_151 | V_152 |
V_153 | V_63 ) ) == 0
&& ( V_19 -> V_148 & V_154 ) == 0
&& ( V_19 -> V_148 & V_155 ) ) {
return V_156 ;
}
if ( V_19 -> V_61 & V_153 ) {
V_19 -> V_27 ( 0x1 , V_5 -> V_28 + V_58 ) ;
V_124 -> V_141 |= V_142 | V_143 ;
F_57 ( V_5 , V_14 ) ;
F_42 ( V_5 , L_13 ) ;
return V_147 ;
}
if ( V_19 -> V_129 == V_128 )
F_58 ( V_5 ) ;
else
F_52 ( V_5 ) ;
if ( V_19 -> V_61 & V_151 ) {
F_42 ( V_5 , L_14 ) ;
V_19 -> V_27 ( 0x1 , V_5 -> V_28 + V_157 ) ;
}
if ( V_19 -> V_61 & V_152 ) {
V_19 -> V_27 ( 0x1 , V_5 -> V_28 + V_58 ) ;
V_124 -> V_141 |= V_142 | V_143 ;
F_57 ( V_5 , V_14 ) ;
F_42 ( V_5 , L_15 ) ;
return V_147 ;
}
if ( V_81 -> V_117 == V_113 ) {
if ( V_19 -> V_148 & V_154 ) {
F_54 ( V_5 ) ;
F_17 ( V_5 , V_14 ) ;
V_124 -> V_141 |= V_143 ;
}
}
if ( V_81 -> V_117 == V_115 ) {
if ( V_19 -> V_8 == 0 ) {
F_17 ( V_5 , V_14 ) ;
V_124 -> V_141 |= V_143 ;
}
}
F_57 ( V_5 , V_14 ) ;
return V_147 ;
}
static int F_59 ( struct V_4 * V_5 ,
struct V_13 * V_14 ,
struct V_65 * V_66 ,
unsigned int * V_67 )
{
const struct V_10 * V_11 = F_10 ( V_5 ) ;
struct V_18 * V_19 = V_5 -> V_20 ;
int V_105 , V_15 ;
unsigned long V_21 ;
int V_54 , V_57 ;
V_105 = F_29 ( V_66 -> V_68 ) ;
F_18 ( & V_5 -> V_22 , V_21 ) ;
V_19 -> V_23 &= ~ F_60 ( V_105 ) ;
V_19 -> V_27 ( V_19 -> V_23 , V_5 -> V_28 + V_29 ) ;
F_19 ( & V_5 -> V_22 , V_21 ) ;
if ( V_11 -> V_35 ) {
V_15 = F_30 ( V_66 -> V_68 ) ;
if ( F_16 ( V_14 , V_15 ) )
V_19 -> V_45 |= F_61 ( V_105 ) ;
else
V_19 -> V_45 &= ~ F_61 ( V_105 ) ;
V_19 -> V_27 ( V_19 -> V_45 , V_5 -> V_28 + V_53 ) ;
}
V_54 = V_67 [ 0 ] & 0xff ;
V_57 = ( V_67 [ 0 ] >> 8 ) & 0xff ;
V_19 -> V_27 ( V_54 , V_5 -> V_28 + F_62 ( V_105 ) ) ;
V_19 -> V_27 ( V_57 , V_5 -> V_28 + F_63 ( V_105 ) ) ;
V_19 -> V_158 [ V_105 ] = V_67 [ 0 ] ;
return 1 ;
}
static int F_64 ( struct V_4 * V_5 ,
struct V_13 * V_14 ,
struct V_65 * V_66 ,
unsigned int * V_67 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
V_67 [ 0 ] = V_19 -> V_158 [ F_29 ( V_66 -> V_68 ) ] ;
return 1 ;
}
static int F_65 ( int V_159 , int V_160 , int V_67 , unsigned long V_28 )
{
if ( V_159 ) {
F_8 ( V_67 , ( void V_3 * ) ( V_28 + V_160 ) ) ;
return 0 ;
} else {
return F_6 ( ( void V_3 * ) ( V_28 + V_160 ) ) ;
}
}
static void F_66 ( struct V_4 * V_5 , unsigned int V_161 ,
unsigned int V_162 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
int V_60 ;
for ( V_60 = 1 ; V_60 <= V_162 ; V_60 ++ ) {
V_19 -> V_163 &= ~ V_164 ;
if ( V_161 & ( 1 << ( V_162 - V_60 ) ) )
V_19 -> V_163 |= V_165 ;
else
V_19 -> V_163 &= ~ V_165 ;
F_27 ( 1 ) ;
V_19 -> V_27 ( V_19 -> V_163 , V_5 -> V_28 + V_166 ) ;
V_19 -> V_163 |= V_164 ;
F_27 ( 1 ) ;
V_19 -> V_27 ( V_19 -> V_163 , V_5 -> V_28 + V_166 ) ;
}
}
static unsigned int F_67 ( struct V_4 * V_5 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned int V_161 = 0 ;
int V_60 ;
const int V_162 = 8 ;
for ( V_60 = 1 ; V_60 <= V_162 ; V_60 ++ ) {
V_19 -> V_163 |= V_164 ;
F_27 ( 1 ) ;
V_19 -> V_27 ( V_19 -> V_163 , V_5 -> V_28 + V_166 ) ;
V_19 -> V_163 &= ~ V_164 ;
F_27 ( 1 ) ;
V_19 -> V_27 ( V_19 -> V_163 , V_5 -> V_28 + V_166 ) ;
F_27 ( 1 ) ;
V_19 -> V_148 = V_19 -> V_55 ( V_5 -> V_28 + V_149 ) ;
if ( V_19 -> V_148 & V_167 )
V_161 |= 1 << ( V_162 - V_60 ) ;
}
return V_161 ;
}
static unsigned int F_68 ( struct V_4 * V_5 ,
unsigned int V_1 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned int V_161 ;
const int V_168 = 0x3 ;
const int V_169 = 8 ;
V_19 -> V_163 &= ~ V_170 ;
F_27 ( 1 ) ;
V_19 -> V_27 ( V_19 -> V_163 , V_5 -> V_28 + V_166 ) ;
V_19 -> V_163 |= ( V_170 | V_171 ) ;
F_27 ( 1 ) ;
V_19 -> V_27 ( V_19 -> V_163 , V_5 -> V_28 + V_166 ) ;
F_66 ( V_5 , V_168 , V_169 ) ;
F_66 ( V_5 , V_1 , V_169 ) ;
V_161 = F_67 ( V_5 ) ;
V_19 -> V_163 &= ~ ( V_170 | V_171 ) ;
F_27 ( 1 ) ;
V_19 -> V_27 ( V_19 -> V_163 , V_5 -> V_28 + V_166 ) ;
return V_161 ;
}
static unsigned int F_69 ( struct V_4 * V_5 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned int V_161 ;
const int V_172 = 0x5 ;
const int V_169 = 8 ;
V_19 -> V_163 &= ~ V_170 ;
F_27 ( 1 ) ;
V_19 -> V_27 ( V_19 -> V_163 , V_5 -> V_28 + V_166 ) ;
V_19 -> V_163 |= ( V_170 | V_171 ) ;
F_27 ( 1 ) ;
V_19 -> V_27 ( V_19 -> V_163 , V_5 -> V_28 + V_166 ) ;
F_66 ( V_5 , V_172 , V_169 ) ;
V_161 = F_67 ( V_5 ) ;
V_19 -> V_163 &= ~ ( V_170 | V_171 ) ;
F_27 ( 1 ) ;
V_19 -> V_27 ( V_19 -> V_163 , V_5 -> V_28 + V_166 ) ;
return V_161 ;
}
static int F_70 ( struct V_4 * V_5 ,
unsigned int V_1 , unsigned int V_161 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
const int V_173 = 0x6 ;
const int V_174 = 0x2 ;
const int V_169 = 8 ;
const int V_175 = 0x1 ;
const int V_59 = 10000 ;
int V_60 ;
for ( V_60 = 0 ; V_60 < V_59 ; V_60 ++ ) {
if ( ( F_69 ( V_5 ) & V_175 ) ==
0 )
break;
}
if ( V_60 == V_59 ) {
F_42 ( V_5 , L_16 ) ;
return - V_64 ;
}
V_19 -> V_176 [ V_1 ] = V_161 ;
V_19 -> V_163 &= ~ V_170 ;
F_27 ( 1 ) ;
V_19 -> V_27 ( V_19 -> V_163 , V_5 -> V_28 + V_166 ) ;
V_19 -> V_163 |= ( V_170 | V_171 ) ;
F_27 ( 1 ) ;
V_19 -> V_27 ( V_19 -> V_163 , V_5 -> V_28 + V_166 ) ;
F_66 ( V_5 , V_173 , V_169 ) ;
V_19 -> V_163 &= ~ V_170 ;
F_27 ( 1 ) ;
V_19 -> V_27 ( V_19 -> V_163 , V_5 -> V_28 + V_166 ) ;
V_19 -> V_163 |= V_170 ;
F_27 ( 1 ) ;
V_19 -> V_27 ( V_19 -> V_163 , V_5 -> V_28 + V_166 ) ;
F_66 ( V_5 , V_174 , V_169 ) ;
F_66 ( V_5 , V_1 , V_169 ) ;
F_66 ( V_5 , V_161 , V_169 ) ;
V_19 -> V_163 &= ~ V_170 ;
F_27 ( 1 ) ;
V_19 -> V_27 ( V_19 -> V_163 , V_5 -> V_28 + V_166 ) ;
V_19 -> V_163 &= ~ ( V_170 | V_171 ) ;
F_27 ( 1 ) ;
V_19 -> V_27 ( V_19 -> V_163 , V_5 -> V_28 + V_166 ) ;
return 0 ;
}
static void F_71 ( struct V_4 * V_5 , unsigned int V_105 ,
unsigned int V_161 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
if ( V_161 == V_19 -> V_177 [ V_105 ] )
return;
V_19 -> V_177 [ V_105 ] = V_161 ;
V_19 -> V_163 &= ~ ( V_178 | V_170 | V_171 ) ;
F_27 ( 1 ) ;
V_19 -> V_27 ( V_19 -> V_163 , V_5 -> V_28 + V_166 ) ;
F_66 ( V_5 , V_105 , 4 ) ;
F_66 ( V_5 , V_161 , 8 ) ;
V_19 -> V_163 |= V_178 ;
F_27 ( 1 ) ;
V_19 -> V_27 ( V_19 -> V_163 , V_5 -> V_28 + V_166 ) ;
V_19 -> V_163 &= ~ V_178 ;
F_27 ( 1 ) ;
V_19 -> V_27 ( V_19 -> V_163 , V_5 -> V_28 + V_166 ) ;
}
static int F_72 ( struct V_4 * V_5 ,
struct V_13 * V_14 ,
struct V_65 * V_66 ,
unsigned int * V_67 )
{
unsigned int V_33 = F_29 ( V_66 -> V_68 ) ;
if ( V_66 -> V_77 > 0 )
F_71 ( V_5 , V_33 , V_67 [ V_66 -> V_77 - 1 ] ) ;
return V_66 -> V_77 ;
}
static int F_73 ( struct V_4 * V_5 ,
struct V_13 * V_14 ,
struct V_65 * V_66 ,
unsigned int * V_67 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned int V_33 = F_29 ( V_66 -> V_68 ) ;
int V_60 ;
for ( V_60 = 0 ; V_60 < V_66 -> V_77 ; V_60 ++ )
V_67 [ V_60 ] = V_19 -> V_177 [ V_33 ] ;
return V_66 -> V_77 ;
}
static int F_74 ( struct V_4 * V_5 ,
struct V_13 * V_14 ,
struct V_65 * V_66 ,
unsigned int * V_67 )
{
unsigned int V_33 = F_29 ( V_66 -> V_68 ) ;
int V_69 ;
if ( V_33 < 16 || V_33 > 127 )
return - V_119 ;
if ( V_66 -> V_77 > 0 ) {
V_69 = F_70 ( V_5 , V_33 , V_67 [ V_66 -> V_77 - 1 ] ) ;
if ( V_69 )
return V_69 ;
}
return V_66 -> V_77 ;
}
static int F_75 ( struct V_4 * V_5 ,
struct V_13 * V_14 ,
struct V_65 * V_66 ,
unsigned int * V_67 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
unsigned int V_33 = F_29 ( V_66 -> V_68 ) ;
int V_60 ;
for ( V_60 = 0 ; V_60 < V_66 -> V_77 ; V_60 ++ )
V_67 [ V_60 ] = V_19 -> V_176 [ V_33 ] ;
return V_66 -> V_77 ;
}
int F_76 ( struct V_4 * V_5 ,
unsigned int V_144 , unsigned long V_179 )
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
V_19 -> V_27 ( V_19 -> V_163 , V_5 -> V_28 + V_166 ) ;
V_19 -> V_27 ( V_19 -> V_45 , V_5 -> V_28 + V_53 ) ;
}
if ( V_144 ) {
V_69 = F_77 ( V_144 , F_56 , V_179 ,
V_5 -> V_180 , V_5 ) ;
if ( V_69 == 0 )
V_5 -> V_144 = V_144 ;
}
V_69 = F_78 ( V_5 , 5 ) ;
if ( V_69 )
return V_69 ;
V_14 = & V_5 -> V_181 [ 0 ] ;
V_14 -> type = V_182 ;
V_14 -> V_183 = V_184 | V_185 | V_186 | V_187 ;
V_14 -> V_188 = 8 ;
V_14 -> V_189 = 8 ;
V_14 -> V_190 = 0x0fff ;
V_14 -> V_16 = V_11 -> V_35
? & V_191 : & V_192 ;
V_14 -> V_193 = F_28 ;
if ( V_5 -> V_144 ) {
V_5 -> V_140 = V_14 ;
V_14 -> V_183 |= V_194 ;
V_14 -> V_195 = F_49 ;
V_14 -> V_196 = F_44 ;
V_14 -> V_197 = F_17 ;
}
V_14 = & V_5 -> V_181 [ 1 ] ;
if ( V_11 -> V_198 ) {
V_14 -> type = V_199 ;
V_14 -> V_183 = V_184 | V_200 | V_185 ;
V_14 -> V_188 = V_201 ;
V_14 -> V_190 = 0x0fff ;
V_14 -> V_16 = & V_202 ;
V_14 -> V_193 = F_64 ;
V_14 -> V_203 = F_59 ;
for ( V_60 = 0 ; V_60 < V_14 -> V_188 ; V_60 ++ ) {
short V_54 , V_57 ;
V_19 -> V_158 [ V_60 ] = V_14 -> V_190 / 2 ;
V_54 = V_19 -> V_158 [ V_60 ] & 0xff ;
V_57 = ( V_19 -> V_158 [ V_60 ] >> 8 ) & 0xff ;
V_19 -> V_27 ( V_54 , V_5 -> V_28 + F_62 ( V_60 ) ) ;
V_19 -> V_27 ( V_57 , V_5 -> V_28 + F_63 ( V_60 ) ) ;
}
} else {
V_14 -> type = V_204 ;
}
V_14 = & V_5 -> V_181 [ 2 ] ;
V_69 = F_79 ( V_5 , V_14 ,
( V_11 -> V_12 ) ? F_65 : NULL ,
V_5 -> V_28 + V_205 ) ;
if ( V_69 )
return V_69 ;
V_14 = & V_5 -> V_181 [ 3 ] ;
if ( V_11 -> V_35 ) {
V_14 -> type = V_206 ;
V_14 -> V_183 = V_184 | V_200 | V_207 ;
V_14 -> V_188 = 16 ;
V_14 -> V_190 = 0xff ;
V_14 -> V_193 = F_73 ;
V_14 -> V_203 = F_72 ;
for ( V_60 = 0 ; V_60 < V_14 -> V_188 ; V_60 ++ )
F_71 ( V_5 , V_60 , V_14 -> V_190 / 2 ) ;
} else
V_14 -> type = V_204 ;
V_14 = & V_5 -> V_181 [ 4 ] ;
if ( V_11 -> V_35 ) {
V_14 -> type = V_208 ;
V_14 -> V_183 = V_184 | V_200 | V_207 ;
V_14 -> V_188 = V_209 ;
V_14 -> V_190 = 0xff ;
V_14 -> V_193 = F_75 ;
V_14 -> V_203 = F_74 ;
for ( V_60 = 0 ; V_60 < V_14 -> V_188 ; V_60 ++ )
V_19 -> V_176 [ V_60 ] = F_68 ( V_5 , V_60 ) ;
} else
V_14 -> type = V_204 ;
return 0 ;
}
static int F_80 ( struct V_4 * V_5 , struct V_210 * V_211 )
{
struct V_18 * V_19 ;
unsigned int V_144 = V_211 -> V_212 [ 1 ] ;
unsigned int V_213 = V_211 -> V_212 [ 2 ] ;
int V_69 ;
V_19 = F_81 ( V_5 , sizeof( * V_19 ) ) ;
if ( ! V_19 )
return - V_214 ;
V_69 = F_82 ( V_5 , V_211 -> V_212 [ 0 ] , V_215 ) ;
if ( V_69 )
return V_69 ;
V_69 = F_76 ( V_5 , V_144 , 0 ) ;
if ( V_69 )
return V_69 ;
if ( V_5 -> V_144 )
F_83 ( V_5 , V_213 ) ;
return 0 ;
}
static void F_84 ( struct V_4 * V_5 )
{
struct V_18 * V_19 = V_5 -> V_20 ;
if ( V_19 )
F_85 ( V_5 ) ;
F_86 ( V_5 ) ;
}
static int T_2 F_87 ( void )
{
return 0 ;
}
static void T_3 F_88 ( void )
{
}
