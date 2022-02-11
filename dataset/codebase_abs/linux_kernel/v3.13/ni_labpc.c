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
static int F_16 ( struct V_4 * V_5 , struct V_13 * V_14 )
{
struct V_15 * V_16 = V_5 -> V_17 ;
unsigned long V_18 ;
F_17 ( & V_5 -> V_19 , V_18 ) ;
V_16 -> V_20 &= ~ ( V_21 | V_22 | V_23 ) ;
V_16 -> V_24 ( V_16 -> V_20 , V_5 -> V_25 + V_26 ) ;
F_18 ( & V_5 -> V_19 , V_18 ) ;
V_16 -> V_27 = 0 ;
V_16 -> V_24 ( V_16 -> V_27 , V_5 -> V_25 + V_28 ) ;
return 0 ;
}
static void F_19 ( struct V_4 * V_5 ,
enum V_29 V_9 ,
unsigned int V_30 ,
unsigned int V_31 ,
unsigned int V_32 )
{
const struct V_10 * V_11 = F_10 ( V_5 ) ;
struct V_15 * V_16 = V_5 -> V_17 ;
if ( V_11 -> V_33 ) {
V_31 += ( V_31 > 0 ) + ( V_31 > 7 ) ;
}
if ( ( V_9 == V_34 || V_9 == V_35 ) &&
V_32 == V_36 )
V_30 *= 2 ;
V_16 -> V_37 = F_20 ( V_30 ) ;
V_16 -> V_37 |= F_21 ( V_31 ) ;
V_16 -> V_24 ( V_16 -> V_37 , V_5 -> V_25 + V_38 ) ;
}
static void F_22 ( struct V_4 * V_5 ,
struct V_13 * V_14 ,
enum V_29 V_9 ,
enum V_39 V_40 ,
unsigned int V_31 ,
unsigned int V_32 ,
bool V_41 )
{
const struct V_10 * V_11 = F_10 ( V_5 ) ;
struct V_15 * V_16 = V_5 -> V_17 ;
if ( ! V_11 -> V_33 )
return;
if ( V_32 != V_42 )
V_16 -> V_43 |= V_44 ;
else
V_16 -> V_43 &= ~ V_44 ;
if ( F_23 ( V_14 , V_31 ) )
V_16 -> V_43 |= V_45 ;
else
V_16 -> V_43 &= ~ V_45 ;
if ( V_40 == V_46 )
V_16 -> V_43 |= V_47 ;
else
V_16 -> V_43 &= ~ V_47 ;
if ( V_41 )
V_16 -> V_43 |= V_48 ;
else
V_16 -> V_43 &= ~ V_48 ;
if ( V_9 == V_49 )
V_16 -> V_43 |= V_50 ;
else
V_16 -> V_43 &= ~ V_50 ;
V_16 -> V_24 ( V_16 -> V_43 , V_5 -> V_25 + V_51 ) ;
}
static unsigned int F_24 ( struct V_4 * V_5 )
{
struct V_15 * V_16 = V_5 -> V_17 ;
unsigned int V_52 = V_16 -> V_53 ( V_5 -> V_25 + V_54 ) ;
unsigned int V_55 = V_16 -> V_53 ( V_5 -> V_25 + V_54 ) ;
return ( V_55 << 8 ) | V_52 ;
}
static void F_25 ( struct V_4 * V_5 )
{
struct V_15 * V_16 = V_5 -> V_17 ;
V_16 -> V_24 ( 0x1 , V_5 -> V_25 + V_56 ) ;
F_24 ( V_5 ) ;
}
static int F_26 ( struct V_4 * V_5 ,
int V_57 )
{
struct V_15 * V_16 = V_5 -> V_17 ;
int V_58 ;
for ( V_58 = 0 ; V_58 < V_57 ; V_58 ++ ) {
V_16 -> V_59 = V_16 -> V_53 ( V_5 -> V_25 + V_60 ) ;
if ( V_16 -> V_59 & V_61 )
return 0 ;
F_27 ( 1 ) ;
}
return - V_62 ;
}
static int F_28 ( struct V_4 * V_5 ,
struct V_13 * V_14 ,
struct V_63 * V_64 ,
unsigned int * V_65 )
{
struct V_15 * V_16 = V_5 -> V_17 ;
unsigned int V_30 = F_29 ( V_64 -> V_66 ) ;
unsigned int V_31 = F_30 ( V_64 -> V_66 ) ;
unsigned int V_32 = F_31 ( V_64 -> V_66 ) ;
int V_67 ;
int V_58 ;
F_16 ( V_5 , V_14 ) ;
F_19 ( V_5 , V_34 , V_30 , V_31 , V_32 ) ;
F_22 ( V_5 , V_14 , V_34 , V_68 ,
V_31 , V_32 , false ) ;
V_16 -> V_69 = 0 ;
V_16 -> V_69 |= V_70 ;
if ( V_32 == V_36 )
V_16 -> V_69 |= V_71 ;
V_16 -> V_24 ( V_16 -> V_69 , V_5 -> V_25 + V_72 ) ;
V_67 = F_13 ( V_5 , V_5 -> V_25 + V_73 ,
0 , V_74 ) ;
if ( V_67 )
return V_67 ;
F_25 ( V_5 ) ;
for ( V_58 = 0 ; V_58 < V_64 -> V_75 ; V_58 ++ ) {
V_16 -> V_24 ( 0x1 , V_5 -> V_25 + V_76 ) ;
V_67 = F_26 ( V_5 , V_77 ) ;
if ( V_67 )
return V_67 ;
V_65 [ V_58 ] = F_24 ( V_5 ) ;
}
return V_64 -> V_75 ;
}
static bool F_32 ( const struct V_78 * V_79 ,
enum V_29 V_9 )
{
if ( V_9 == V_34 || V_79 -> V_80 == V_81 )
return true ;
return false ;
}
static unsigned int F_33 ( const struct V_78 * V_79 ,
enum V_29 V_9 )
{
if ( V_79 -> V_82 != V_83 )
return 0 ;
if ( V_9 == V_34 && V_79 -> V_80 == V_83 )
return V_79 -> V_84 ;
return V_79 -> V_85 ;
}
static void F_34 ( struct V_78 * V_79 ,
enum V_29 V_9 , unsigned int V_86 )
{
if ( V_79 -> V_82 != V_83 )
return;
if ( V_9 == V_34 &&
V_79 -> V_80 == V_83 ) {
V_79 -> V_84 = V_86 ;
if ( V_79 -> V_85 > V_79 -> V_84 )
V_79 -> V_85 = V_79 -> V_84 ;
} else
V_79 -> V_85 = V_86 ;
}
static unsigned int F_35 ( const struct V_78 * V_79 ,
enum V_29 V_9 )
{
if ( V_79 -> V_80 != V_83 )
return 0 ;
if ( V_9 == V_34 && V_79 -> V_82 == V_83 )
return 0 ;
return V_79 -> V_84 ;
}
static void F_36 ( struct V_78 * V_79 ,
enum V_29 V_9 , unsigned int V_86 )
{
if ( V_79 -> V_80 != V_83 )
return;
if ( V_9 == V_34 && V_79 -> V_82 == V_83 )
return;
V_79 -> V_84 = V_86 ;
}
static void F_37 ( struct V_4 * V_5 , struct V_78 * V_79 ,
enum V_29 V_9 )
{
struct V_15 * V_16 = V_5 -> V_17 ;
const int V_87 = 0x10000 ;
const int V_88 = 2 ;
unsigned int V_89 ;
unsigned int V_90 ;
unsigned int V_91 ;
V_91 = F_33 ( V_79 , V_9 ) ;
V_90 = F_35 ( V_79 , V_9 ) ;
if ( V_91 && V_90 ) {
V_16 -> V_92 = ( V_90 - 1 ) /
( V_93 * V_87 ) + 1 ;
if ( V_16 -> V_92 < V_88 )
V_16 -> V_92 = V_88 ;
if ( V_16 -> V_92 > V_87 )
V_16 -> V_92 = V_87 ;
V_89 = V_93 * V_16 -> V_92 ;
switch ( V_79 -> V_18 & V_94 ) {
default:
case V_95 :
V_16 -> V_96 =
( V_91 + ( V_89 / 2 ) ) / V_89 ;
V_16 -> V_97 =
( V_90 + ( V_89 / 2 ) ) / V_89 ;
break;
case V_98 :
V_16 -> V_96 =
( V_91 + ( V_89 - 1 ) ) / V_89 ;
V_16 -> V_97 =
( V_90 + ( V_89 - 1 ) ) / V_89 ;
break;
case V_99 :
V_16 -> V_96 = V_91 / V_89 ;
V_16 -> V_97 = V_90 / V_89 ;
break;
}
if ( V_16 -> V_96 < V_88 )
V_16 -> V_96 = V_88 ;
if ( V_16 -> V_96 > V_87 )
V_16 -> V_96 = V_87 ;
if ( V_16 -> V_97 < V_88 )
V_16 -> V_97 = V_88 ;
if ( V_16 -> V_97 > V_87 )
V_16 -> V_97 = V_87 ;
F_34 ( V_79 , V_9 ,
V_89 * V_16 -> V_96 ) ;
F_36 ( V_79 , V_9 ,
V_89 * V_16 -> V_97 ) ;
} else if ( V_90 ) {
F_38 ( V_93 ,
& V_16 -> V_97 ,
& V_16 -> V_92 ,
& V_90 , V_79 -> V_18 ) ;
F_36 ( V_79 , V_9 , V_90 ) ;
} else if ( V_91 ) {
F_38 ( V_93 ,
& V_16 -> V_96 ,
& V_16 -> V_92 ,
& V_91 , V_79 -> V_18 ) ;
F_34 ( V_79 , V_9 , V_91 ) ;
}
}
static enum V_29 F_39 ( const struct V_78 * V_79 )
{
if ( V_79 -> V_100 == 1 )
return V_34 ;
if ( V_79 -> V_101 == NULL )
return V_49 ;
if ( F_29 ( V_79 -> V_101 [ 0 ] ) == F_29 ( V_79 -> V_101 [ 1 ] ) )
return V_35 ;
if ( F_29 ( V_79 -> V_101 [ 0 ] ) < F_29 ( V_79 -> V_101 [ 1 ] ) )
return V_49 ;
if ( F_29 ( V_79 -> V_101 [ 0 ] ) > F_29 ( V_79 -> V_101 [ 1 ] ) )
return V_102 ;
F_40 ( L_1 ) ;
return 0 ;
}
static int F_41 ( const struct V_4 * V_5 ,
const struct V_78 * V_79 ,
enum V_29 V_9 )
{
int V_103 , V_31 , V_32 , V_58 ;
if ( V_79 -> V_101 == NULL )
return 0 ;
if ( V_9 == V_34 )
return 0 ;
if ( V_9 == V_35 ) {
if ( V_79 -> V_100 > 0xff ) {
F_42 ( V_5 ,
L_2 ) ;
return 1 ;
}
}
V_103 = F_29 ( V_79 -> V_101 [ 0 ] ) ;
V_31 = F_30 ( V_79 -> V_101 [ 0 ] ) ;
V_32 = F_31 ( V_79 -> V_101 [ 0 ] ) ;
for ( V_58 = 0 ; V_58 < V_79 -> V_100 ; V_58 ++ ) {
switch ( V_9 ) {
case V_35 :
if ( F_29 ( V_79 -> V_101 [ V_58 ] ) != V_103 ) {
F_42 ( V_5 ,
L_3 ) ;
return 1 ;
}
break;
case V_49 :
if ( F_29 ( V_79 -> V_101 [ V_58 ] ) != V_58 ) {
F_42 ( V_5 ,
L_3 ) ;
return 1 ;
}
break;
case V_102 :
if ( F_29 ( V_79 -> V_101 [ V_58 ] ) !=
V_79 -> V_100 - V_58 - 1 ) {
F_42 ( V_5 ,
L_3 ) ;
return 1 ;
}
break;
default:
F_43 ( V_5 -> V_104 ,
L_4 ) ;
return 1 ;
break;
}
if ( F_30 ( V_79 -> V_101 [ V_58 ] ) != V_31 ) {
F_42 ( V_5 ,
L_5 ) ;
return 1 ;
}
if ( F_31 ( V_79 -> V_101 [ V_58 ] ) != V_32 ) {
F_42 ( V_5 ,
L_6 ) ;
return 1 ;
}
}
return 0 ;
}
static int F_44 ( struct V_4 * V_5 ,
struct V_13 * V_14 , struct V_78 * V_79 )
{
const struct V_10 * V_11 = F_10 ( V_5 ) ;
int V_105 = 0 ;
int V_106 , V_107 ;
unsigned int V_108 ;
enum V_29 V_9 ;
V_105 |= F_45 ( & V_79 -> V_109 , V_110 | V_111 ) ;
V_105 |= F_45 ( & V_79 -> V_80 ,
V_83 | V_81 | V_111 ) ;
V_105 |= F_45 ( & V_79 -> V_82 , V_83 | V_111 ) ;
V_105 |= F_45 ( & V_79 -> V_112 , V_113 ) ;
V_108 = V_113 | V_114 ;
if ( V_11 -> V_33 )
V_108 |= V_111 ;
V_105 |= F_45 ( & V_79 -> V_115 , V_108 ) ;
if ( V_105 )
return 1 ;
V_105 |= F_46 ( V_79 -> V_109 ) ;
V_105 |= F_46 ( V_79 -> V_80 ) ;
V_105 |= F_46 ( V_79 -> V_82 ) ;
V_105 |= F_46 ( V_79 -> V_115 ) ;
if ( V_79 -> V_109 == V_111 && V_79 -> V_115 == V_111 )
V_105 ++ ;
if ( V_105 )
return 2 ;
if ( V_79 -> V_116 == V_110 )
V_105 |= F_47 ( & V_79 -> V_116 , 0 ) ;
if ( ! V_79 -> V_100 )
V_105 |= - V_117 ;
V_105 |= F_47 ( & V_79 -> V_118 , V_79 -> V_100 ) ;
if ( V_79 -> V_82 == V_83 )
V_105 |= F_48 ( & V_79 -> V_85 ,
V_11 -> V_119 ) ;
if ( V_79 -> V_80 == V_83 ) {
if ( V_79 -> V_82 == V_83 )
V_105 |= F_48 ( & V_79 -> V_84 ,
V_79 -> V_85 * V_79 -> V_100 ) ;
V_105 |= F_48 ( & V_79 -> V_84 ,
V_11 -> V_119 * V_79 -> V_100 ) ;
}
switch ( V_79 -> V_115 ) {
case V_113 :
V_105 |= F_48 ( & V_79 -> V_120 , 1 ) ;
break;
case V_114 :
V_105 |= F_47 ( & V_79 -> V_120 , 0 ) ;
break;
default:
break;
}
if ( V_105 )
return 3 ;
V_106 = V_79 -> V_85 ;
V_107 = V_79 -> V_84 ;
V_9 = F_39 ( V_79 ) ;
F_37 ( V_5 , V_79 , V_9 ) ;
if ( V_106 != V_79 -> V_85 || V_107 != V_79 -> V_84 )
V_105 ++ ;
if ( V_105 )
return 4 ;
if ( F_41 ( V_5 , V_79 , V_9 ) )
return 5 ;
return 0 ;
}
static int F_49 ( struct V_4 * V_5 , struct V_13 * V_14 )
{
const struct V_10 * V_11 = F_10 ( V_5 ) ;
struct V_15 * V_16 = V_5 -> V_17 ;
struct V_121 * V_122 = V_14 -> V_122 ;
struct V_78 * V_79 = & V_122 -> V_79 ;
enum V_29 V_9 = F_39 ( V_79 ) ;
unsigned int V_66 = ( V_9 == V_49 )
? V_79 -> V_101 [ V_79 -> V_100 - 1 ]
: V_79 -> V_101 [ 0 ] ;
unsigned int V_30 = F_29 ( V_66 ) ;
unsigned int V_31 = F_30 ( V_66 ) ;
unsigned int V_32 = F_31 ( V_66 ) ;
enum V_39 V_40 ;
unsigned long V_18 ;
int V_67 ;
F_16 ( V_5 , V_14 ) ;
if ( V_79 -> V_115 == V_113 )
V_16 -> V_8 = V_79 -> V_120 * V_79 -> V_100 ;
if ( V_79 -> V_115 == V_111 ) {
V_67 = F_9 ( V_5 , V_5 -> V_25 + V_73 ,
1 , 3 , V_123 ) ;
} else {
V_67 = F_13 ( V_5 ,
V_5 -> V_25 + V_73 ,
1 , V_123 ) ;
}
if ( V_67 ) {
F_42 ( V_5 , L_7 ) ;
return V_67 ;
}
if ( F_50 ( V_5 ) &&
( V_79 -> V_18 & ( V_124 | V_125 ) ) == 0 )
V_40 = V_126 ;
else if (
V_11 -> V_33 &&
( V_79 -> V_18 & V_124 ) == 0 &&
( V_79 -> V_115 != V_113 || V_16 -> V_8 > 256 ) )
V_40 = V_46 ;
else
V_40 = V_68 ;
V_16 -> V_127 = V_40 ;
F_19 ( V_5 , V_9 , V_30 , V_31 , V_32 ) ;
F_22 ( V_5 , V_14 , V_9 , V_40 , V_31 , V_32 ,
( V_79 -> V_115 == V_111 ) ) ;
if ( V_9 == V_49 || V_9 == V_102 ) {
V_16 -> V_37 |= V_128 ;
F_27 ( 1 ) ;
V_16 -> V_24 ( V_16 -> V_37 , V_5 -> V_25 + V_38 ) ;
}
V_16 -> V_24 ( V_79 -> V_100 ,
V_5 -> V_25 + V_129 ) ;
V_16 -> V_24 ( 0x1 , V_5 -> V_25 + V_130 ) ;
if ( V_79 -> V_82 == V_83 ||
V_79 -> V_80 == V_83 ) {
F_37 ( V_5 , V_79 , V_9 ) ;
V_67 = F_9 ( V_5 , V_5 -> V_25 + V_131 ,
0 , V_16 -> V_92 , V_132 ) ;
if ( V_67 < 0 ) {
F_42 ( V_5 , L_8 ) ;
return - 1 ;
}
}
if ( F_33 ( V_79 , V_9 ) ) {
V_67 = F_9 ( V_5 , V_5 -> V_25 + V_73 ,
0 , V_16 -> V_96 , V_74 ) ;
} else {
V_67 = F_13 ( V_5 ,
V_5 -> V_25 + V_73 ,
0 , V_74 ) ;
}
if ( V_67 ) {
F_42 ( V_5 , L_9 ) ;
return V_67 ;
}
if ( F_35 ( V_79 , V_9 ) ) {
V_67 = F_9 ( V_5 , V_5 -> V_25 + V_131 ,
1 , V_16 -> V_97 , V_74 ) ;
if ( V_67 < 0 ) {
F_42 ( V_5 , L_10 ) ;
return - 1 ;
}
}
F_25 ( V_5 ) ;
if ( V_40 == V_126 )
F_51 ( V_5 , V_14 ) ;
V_16 -> V_27 |= V_133 ;
if ( V_40 == V_68 )
V_16 -> V_27 |= V_134 ;
V_16 -> V_24 ( V_16 -> V_27 , V_5 -> V_25 + V_28 ) ;
V_16 -> V_69 = 0 ;
if ( V_79 -> V_82 != V_111 )
V_16 -> V_69 |= V_70 ;
if ( ! F_32 ( V_79 , V_9 ) ) {
V_16 -> V_69 |= V_135 ;
if ( V_79 -> V_80 == V_111 )
V_16 -> V_69 |= V_136 ;
}
if ( V_32 == V_36 )
V_16 -> V_69 |= V_71 ;
V_16 -> V_24 ( V_16 -> V_69 , V_5 -> V_25 + V_72 ) ;
F_17 ( & V_5 -> V_19 , V_18 ) ;
V_16 -> V_20 |= V_137 ;
V_16 -> V_20 &= ~ ( V_21 | V_22 | V_23 ) ;
if ( V_79 -> V_109 == V_111 )
V_16 -> V_20 |= V_22 ;
else
V_16 -> V_20 |= V_21 ;
if ( V_79 -> V_115 == V_111 )
V_16 -> V_20 |= ( V_22 | V_23 ) ;
V_16 -> V_24 ( V_16 -> V_20 , V_5 -> V_25 + V_26 ) ;
F_18 ( & V_5 -> V_19 , V_18 ) ;
return 0 ;
}
static int F_52 ( struct V_4 * V_5 )
{
struct V_15 * V_16 = V_5 -> V_17 ;
unsigned short V_65 ;
struct V_121 * V_122 = V_5 -> V_138 -> V_122 ;
const int V_57 = 10000 ;
unsigned int V_58 ;
V_16 -> V_59 = V_16 -> V_53 ( V_5 -> V_25 + V_60 ) ;
for ( V_58 = 0 ; ( V_16 -> V_59 & V_61 ) && V_58 < V_57 ;
V_58 ++ ) {
if ( V_122 -> V_79 . V_115 == V_113 ) {
if ( V_16 -> V_8 == 0 )
break;
V_16 -> V_8 -- ;
}
V_65 = F_24 ( V_5 ) ;
F_53 ( V_5 -> V_138 , V_65 ) ;
V_16 -> V_59 = V_16 -> V_53 ( V_5 -> V_25 + V_60 ) ;
}
if ( V_58 == V_57 ) {
F_42 ( V_5 , L_11 ) ;
V_122 -> V_139 |= V_140 | V_141 ;
return - 1 ;
}
return 0 ;
}
static void F_54 ( struct V_4 * V_5 )
{
struct V_15 * V_16 = V_5 -> V_17 ;
if ( V_16 -> V_127 == V_126 )
F_55 ( V_5 ) ;
F_52 ( V_5 ) ;
}
static T_1 F_56 ( int V_142 , void * V_143 )
{
struct V_4 * V_5 = V_143 ;
const struct V_10 * V_11 = F_10 ( V_5 ) ;
struct V_15 * V_16 = V_5 -> V_17 ;
struct V_13 * V_14 = V_5 -> V_138 ;
struct V_121 * V_122 ;
struct V_78 * V_79 ;
if ( ! V_5 -> V_144 ) {
F_42 ( V_5 , L_12 ) ;
return V_145 ;
}
V_122 = V_14 -> V_122 ;
V_79 = & V_122 -> V_79 ;
V_122 -> V_139 = 0 ;
V_16 -> V_59 = V_16 -> V_53 ( V_5 -> V_25 + V_60 ) ;
if ( V_11 -> V_33 )
V_16 -> V_146 = V_16 -> V_53 ( V_5 -> V_25 + V_147 ) ;
if ( ( V_16 -> V_59 & ( V_148 | V_149 | V_150 |
V_151 | V_61 ) ) == 0
&& ( V_16 -> V_146 & V_152 ) == 0
&& ( V_16 -> V_146 & V_153 ) ) {
return V_154 ;
}
if ( V_16 -> V_59 & V_151 ) {
V_16 -> V_24 ( 0x1 , V_5 -> V_25 + V_56 ) ;
V_122 -> V_139 |= V_140 | V_141 ;
F_57 ( V_5 , V_14 ) ;
F_42 ( V_5 , L_13 ) ;
return V_145 ;
}
if ( V_16 -> V_127 == V_126 )
F_58 ( V_5 ) ;
else
F_52 ( V_5 ) ;
if ( V_16 -> V_59 & V_149 ) {
F_42 ( V_5 , L_14 ) ;
V_16 -> V_24 ( 0x1 , V_5 -> V_25 + V_155 ) ;
}
if ( V_16 -> V_59 & V_150 ) {
V_16 -> V_24 ( 0x1 , V_5 -> V_25 + V_56 ) ;
V_122 -> V_139 |= V_140 | V_141 ;
F_57 ( V_5 , V_14 ) ;
F_42 ( V_5 , L_15 ) ;
return V_145 ;
}
if ( V_79 -> V_115 == V_111 ) {
if ( V_16 -> V_146 & V_152 ) {
F_54 ( V_5 ) ;
F_16 ( V_5 , V_14 ) ;
V_122 -> V_139 |= V_141 ;
}
}
if ( V_79 -> V_115 == V_113 ) {
if ( V_16 -> V_8 == 0 ) {
F_16 ( V_5 , V_14 ) ;
V_122 -> V_139 |= V_141 ;
}
}
F_57 ( V_5 , V_14 ) ;
return V_145 ;
}
static int F_59 ( struct V_4 * V_5 ,
struct V_13 * V_14 ,
struct V_63 * V_64 ,
unsigned int * V_65 )
{
const struct V_10 * V_11 = F_10 ( V_5 ) ;
struct V_15 * V_16 = V_5 -> V_17 ;
int V_103 , V_31 ;
unsigned long V_18 ;
int V_52 , V_55 ;
V_103 = F_29 ( V_64 -> V_66 ) ;
F_17 ( & V_5 -> V_19 , V_18 ) ;
V_16 -> V_20 &= ~ F_60 ( V_103 ) ;
V_16 -> V_24 ( V_16 -> V_20 , V_5 -> V_25 + V_26 ) ;
F_18 ( & V_5 -> V_19 , V_18 ) ;
if ( V_11 -> V_33 ) {
V_31 = F_30 ( V_64 -> V_66 ) ;
if ( F_23 ( V_14 , V_31 ) )
V_16 -> V_43 |= F_61 ( V_103 ) ;
else
V_16 -> V_43 &= ~ F_61 ( V_103 ) ;
V_16 -> V_24 ( V_16 -> V_43 , V_5 -> V_25 + V_51 ) ;
}
V_52 = V_65 [ 0 ] & 0xff ;
V_55 = ( V_65 [ 0 ] >> 8 ) & 0xff ;
V_16 -> V_24 ( V_52 , V_5 -> V_25 + F_62 ( V_103 ) ) ;
V_16 -> V_24 ( V_55 , V_5 -> V_25 + F_63 ( V_103 ) ) ;
V_16 -> V_156 [ V_103 ] = V_65 [ 0 ] ;
return 1 ;
}
static int F_64 ( struct V_4 * V_5 ,
struct V_13 * V_14 ,
struct V_63 * V_64 ,
unsigned int * V_65 )
{
struct V_15 * V_16 = V_5 -> V_17 ;
V_65 [ 0 ] = V_16 -> V_156 [ F_29 ( V_64 -> V_66 ) ] ;
return 1 ;
}
static int F_65 ( int V_157 , int V_158 , int V_65 , unsigned long V_25 )
{
if ( V_157 ) {
F_8 ( V_65 , ( void V_3 * ) ( V_25 + V_158 ) ) ;
return 0 ;
} else {
return F_6 ( ( void V_3 * ) ( V_25 + V_158 ) ) ;
}
}
static void F_66 ( struct V_4 * V_5 , unsigned int V_159 ,
unsigned int V_160 )
{
struct V_15 * V_16 = V_5 -> V_17 ;
int V_58 ;
for ( V_58 = 1 ; V_58 <= V_160 ; V_58 ++ ) {
V_16 -> V_161 &= ~ V_162 ;
if ( V_159 & ( 1 << ( V_160 - V_58 ) ) )
V_16 -> V_161 |= V_163 ;
else
V_16 -> V_161 &= ~ V_163 ;
F_27 ( 1 ) ;
V_16 -> V_24 ( V_16 -> V_161 , V_5 -> V_25 + V_164 ) ;
V_16 -> V_161 |= V_162 ;
F_27 ( 1 ) ;
V_16 -> V_24 ( V_16 -> V_161 , V_5 -> V_25 + V_164 ) ;
}
}
static unsigned int F_67 ( struct V_4 * V_5 )
{
struct V_15 * V_16 = V_5 -> V_17 ;
unsigned int V_159 = 0 ;
int V_58 ;
const int V_160 = 8 ;
for ( V_58 = 1 ; V_58 <= V_160 ; V_58 ++ ) {
V_16 -> V_161 |= V_162 ;
F_27 ( 1 ) ;
V_16 -> V_24 ( V_16 -> V_161 , V_5 -> V_25 + V_164 ) ;
V_16 -> V_161 &= ~ V_162 ;
F_27 ( 1 ) ;
V_16 -> V_24 ( V_16 -> V_161 , V_5 -> V_25 + V_164 ) ;
F_27 ( 1 ) ;
V_16 -> V_146 = V_16 -> V_53 ( V_5 -> V_25 + V_147 ) ;
if ( V_16 -> V_146 & V_165 )
V_159 |= 1 << ( V_160 - V_58 ) ;
}
return V_159 ;
}
static unsigned int F_68 ( struct V_4 * V_5 ,
unsigned int V_1 )
{
struct V_15 * V_16 = V_5 -> V_17 ;
unsigned int V_159 ;
const int V_166 = 0x3 ;
const int V_167 = 8 ;
V_16 -> V_161 &= ~ V_168 ;
F_27 ( 1 ) ;
V_16 -> V_24 ( V_16 -> V_161 , V_5 -> V_25 + V_164 ) ;
V_16 -> V_161 |= ( V_168 | V_169 ) ;
F_27 ( 1 ) ;
V_16 -> V_24 ( V_16 -> V_161 , V_5 -> V_25 + V_164 ) ;
F_66 ( V_5 , V_166 , V_167 ) ;
F_66 ( V_5 , V_1 , V_167 ) ;
V_159 = F_67 ( V_5 ) ;
V_16 -> V_161 &= ~ ( V_168 | V_169 ) ;
F_27 ( 1 ) ;
V_16 -> V_24 ( V_16 -> V_161 , V_5 -> V_25 + V_164 ) ;
return V_159 ;
}
static unsigned int F_69 ( struct V_4 * V_5 )
{
struct V_15 * V_16 = V_5 -> V_17 ;
unsigned int V_159 ;
const int V_170 = 0x5 ;
const int V_167 = 8 ;
V_16 -> V_161 &= ~ V_168 ;
F_27 ( 1 ) ;
V_16 -> V_24 ( V_16 -> V_161 , V_5 -> V_25 + V_164 ) ;
V_16 -> V_161 |= ( V_168 | V_169 ) ;
F_27 ( 1 ) ;
V_16 -> V_24 ( V_16 -> V_161 , V_5 -> V_25 + V_164 ) ;
F_66 ( V_5 , V_170 , V_167 ) ;
V_159 = F_67 ( V_5 ) ;
V_16 -> V_161 &= ~ ( V_168 | V_169 ) ;
F_27 ( 1 ) ;
V_16 -> V_24 ( V_16 -> V_161 , V_5 -> V_25 + V_164 ) ;
return V_159 ;
}
static int F_70 ( struct V_4 * V_5 ,
unsigned int V_1 , unsigned int V_159 )
{
struct V_15 * V_16 = V_5 -> V_17 ;
const int V_171 = 0x6 ;
const int V_172 = 0x2 ;
const int V_167 = 8 ;
const int V_173 = 0x1 ;
const int V_57 = 10000 ;
int V_58 ;
for ( V_58 = 0 ; V_58 < V_57 ; V_58 ++ ) {
if ( ( F_69 ( V_5 ) & V_173 ) ==
0 )
break;
}
if ( V_58 == V_57 ) {
F_42 ( V_5 , L_16 ) ;
return - V_62 ;
}
V_16 -> V_174 [ V_1 ] = V_159 ;
V_16 -> V_161 &= ~ V_168 ;
F_27 ( 1 ) ;
V_16 -> V_24 ( V_16 -> V_161 , V_5 -> V_25 + V_164 ) ;
V_16 -> V_161 |= ( V_168 | V_169 ) ;
F_27 ( 1 ) ;
V_16 -> V_24 ( V_16 -> V_161 , V_5 -> V_25 + V_164 ) ;
F_66 ( V_5 , V_171 , V_167 ) ;
V_16 -> V_161 &= ~ V_168 ;
F_27 ( 1 ) ;
V_16 -> V_24 ( V_16 -> V_161 , V_5 -> V_25 + V_164 ) ;
V_16 -> V_161 |= V_168 ;
F_27 ( 1 ) ;
V_16 -> V_24 ( V_16 -> V_161 , V_5 -> V_25 + V_164 ) ;
F_66 ( V_5 , V_172 , V_167 ) ;
F_66 ( V_5 , V_1 , V_167 ) ;
F_66 ( V_5 , V_159 , V_167 ) ;
V_16 -> V_161 &= ~ V_168 ;
F_27 ( 1 ) ;
V_16 -> V_24 ( V_16 -> V_161 , V_5 -> V_25 + V_164 ) ;
V_16 -> V_161 &= ~ ( V_168 | V_169 ) ;
F_27 ( 1 ) ;
V_16 -> V_24 ( V_16 -> V_161 , V_5 -> V_25 + V_164 ) ;
return 0 ;
}
static void F_71 ( struct V_4 * V_5 , unsigned int V_103 ,
unsigned int V_159 )
{
struct V_15 * V_16 = V_5 -> V_17 ;
if ( V_159 == V_16 -> V_175 [ V_103 ] )
return;
V_16 -> V_175 [ V_103 ] = V_159 ;
V_16 -> V_161 &= ~ ( V_176 | V_168 | V_169 ) ;
F_27 ( 1 ) ;
V_16 -> V_24 ( V_16 -> V_161 , V_5 -> V_25 + V_164 ) ;
F_66 ( V_5 , V_103 , 4 ) ;
F_66 ( V_5 , V_159 , 8 ) ;
V_16 -> V_161 |= V_176 ;
F_27 ( 1 ) ;
V_16 -> V_24 ( V_16 -> V_161 , V_5 -> V_25 + V_164 ) ;
V_16 -> V_161 &= ~ V_176 ;
F_27 ( 1 ) ;
V_16 -> V_24 ( V_16 -> V_161 , V_5 -> V_25 + V_164 ) ;
}
static int F_72 ( struct V_4 * V_5 ,
struct V_13 * V_14 ,
struct V_63 * V_64 ,
unsigned int * V_65 )
{
unsigned int V_30 = F_29 ( V_64 -> V_66 ) ;
if ( V_64 -> V_75 > 0 )
F_71 ( V_5 , V_30 , V_65 [ V_64 -> V_75 - 1 ] ) ;
return V_64 -> V_75 ;
}
static int F_73 ( struct V_4 * V_5 ,
struct V_13 * V_14 ,
struct V_63 * V_64 ,
unsigned int * V_65 )
{
struct V_15 * V_16 = V_5 -> V_17 ;
unsigned int V_30 = F_29 ( V_64 -> V_66 ) ;
int V_58 ;
for ( V_58 = 0 ; V_58 < V_64 -> V_75 ; V_58 ++ )
V_65 [ V_58 ] = V_16 -> V_175 [ V_30 ] ;
return V_64 -> V_75 ;
}
static int F_74 ( struct V_4 * V_5 ,
struct V_13 * V_14 ,
struct V_63 * V_64 ,
unsigned int * V_65 )
{
unsigned int V_30 = F_29 ( V_64 -> V_66 ) ;
int V_67 ;
if ( V_30 < 16 || V_30 > 127 )
return - V_117 ;
if ( V_64 -> V_75 > 0 ) {
V_67 = F_70 ( V_5 , V_30 , V_65 [ V_64 -> V_75 - 1 ] ) ;
if ( V_67 )
return V_67 ;
}
return V_64 -> V_75 ;
}
static int F_75 ( struct V_4 * V_5 ,
struct V_13 * V_14 ,
struct V_63 * V_64 ,
unsigned int * V_65 )
{
struct V_15 * V_16 = V_5 -> V_17 ;
unsigned int V_30 = F_29 ( V_64 -> V_66 ) ;
int V_58 ;
for ( V_58 = 0 ; V_58 < V_64 -> V_75 ; V_58 ++ )
V_65 [ V_58 ] = V_16 -> V_174 [ V_30 ] ;
return V_64 -> V_75 ;
}
int F_76 ( struct V_4 * V_5 ,
unsigned int V_142 , unsigned long V_177 )
{
const struct V_10 * V_11 = F_10 ( V_5 ) ;
struct V_15 * V_16 = V_5 -> V_17 ;
struct V_13 * V_14 ;
int V_67 ;
int V_58 ;
if ( V_11 -> V_12 ) {
V_16 -> V_53 = F_5 ;
V_16 -> V_24 = F_7 ;
} else {
V_16 -> V_53 = F_1 ;
V_16 -> V_24 = F_3 ;
}
V_16 -> V_24 ( V_16 -> V_37 , V_5 -> V_25 + V_38 ) ;
V_16 -> V_24 ( V_16 -> V_20 , V_5 -> V_25 + V_26 ) ;
V_16 -> V_24 ( V_16 -> V_27 , V_5 -> V_25 + V_28 ) ;
V_16 -> V_24 ( V_16 -> V_69 , V_5 -> V_25 + V_72 ) ;
if ( V_11 -> V_33 ) {
V_16 -> V_24 ( V_16 -> V_161 , V_5 -> V_25 + V_164 ) ;
V_16 -> V_24 ( V_16 -> V_43 , V_5 -> V_25 + V_51 ) ;
}
if ( V_142 ) {
V_67 = F_77 ( V_142 , F_56 , V_177 ,
V_5 -> V_178 , V_5 ) ;
if ( V_67 == 0 )
V_5 -> V_142 = V_142 ;
}
V_67 = F_78 ( V_5 , 5 ) ;
if ( V_67 )
return V_67 ;
V_14 = & V_5 -> V_179 [ 0 ] ;
V_14 -> type = V_180 ;
V_14 -> V_181 = V_182 | V_183 | V_184 | V_185 ;
V_14 -> V_186 = 8 ;
V_14 -> V_187 = 8 ;
V_14 -> V_188 = 0x0fff ;
V_14 -> V_189 = V_11 -> V_33
? & V_190 : & V_191 ;
V_14 -> V_192 = F_28 ;
if ( V_5 -> V_142 ) {
V_5 -> V_138 = V_14 ;
V_14 -> V_181 |= V_193 ;
V_14 -> V_194 = F_49 ;
V_14 -> V_195 = F_44 ;
V_14 -> V_196 = F_16 ;
}
V_14 = & V_5 -> V_179 [ 1 ] ;
if ( V_11 -> V_197 ) {
V_14 -> type = V_198 ;
V_14 -> V_181 = V_182 | V_199 | V_183 ;
V_14 -> V_186 = V_200 ;
V_14 -> V_188 = 0x0fff ;
V_14 -> V_189 = & V_201 ;
V_14 -> V_192 = F_64 ;
V_14 -> V_202 = F_59 ;
for ( V_58 = 0 ; V_58 < V_14 -> V_186 ; V_58 ++ ) {
short V_52 , V_55 ;
V_16 -> V_156 [ V_58 ] = V_14 -> V_188 / 2 ;
V_52 = V_16 -> V_156 [ V_58 ] & 0xff ;
V_55 = ( V_16 -> V_156 [ V_58 ] >> 8 ) & 0xff ;
V_16 -> V_24 ( V_52 , V_5 -> V_25 + F_62 ( V_58 ) ) ;
V_16 -> V_24 ( V_55 , V_5 -> V_25 + F_63 ( V_58 ) ) ;
}
} else {
V_14 -> type = V_203 ;
}
V_14 = & V_5 -> V_179 [ 2 ] ;
V_67 = F_79 ( V_5 , V_14 ,
( V_11 -> V_12 ) ? F_65 : NULL ,
V_5 -> V_25 + V_204 ) ;
if ( V_67 )
return V_67 ;
V_14 = & V_5 -> V_179 [ 3 ] ;
if ( V_11 -> V_33 ) {
V_14 -> type = V_205 ;
V_14 -> V_181 = V_182 | V_199 | V_206 ;
V_14 -> V_186 = 16 ;
V_14 -> V_188 = 0xff ;
V_14 -> V_192 = F_73 ;
V_14 -> V_202 = F_72 ;
for ( V_58 = 0 ; V_58 < V_14 -> V_186 ; V_58 ++ )
F_71 ( V_5 , V_58 , V_14 -> V_188 / 2 ) ;
} else
V_14 -> type = V_203 ;
V_14 = & V_5 -> V_179 [ 4 ] ;
if ( V_11 -> V_33 ) {
V_14 -> type = V_207 ;
V_14 -> V_181 = V_182 | V_199 | V_206 ;
V_14 -> V_186 = V_208 ;
V_14 -> V_188 = 0xff ;
V_14 -> V_192 = F_75 ;
V_14 -> V_202 = F_74 ;
for ( V_58 = 0 ; V_58 < V_14 -> V_186 ; V_58 ++ )
V_16 -> V_174 [ V_58 ] = F_68 ( V_5 , V_58 ) ;
} else
V_14 -> type = V_203 ;
return 0 ;
}
static int F_80 ( struct V_4 * V_5 , struct V_209 * V_210 )
{
struct V_15 * V_16 ;
unsigned int V_142 = V_210 -> V_211 [ 1 ] ;
unsigned int V_212 = V_210 -> V_211 [ 2 ] ;
int V_67 ;
V_16 = F_81 ( V_5 , sizeof( * V_16 ) ) ;
if ( ! V_16 )
return - V_213 ;
V_67 = F_82 ( V_5 , V_210 -> V_211 [ 0 ] , V_214 ) ;
if ( V_67 )
return V_67 ;
V_67 = F_76 ( V_5 , V_142 , 0 ) ;
if ( V_67 )
return V_67 ;
if ( V_5 -> V_142 )
F_83 ( V_5 , V_212 ) ;
return 0 ;
}
static void F_84 ( struct V_4 * V_5 )
{
struct V_15 * V_16 = V_5 -> V_17 ;
if ( V_16 )
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
