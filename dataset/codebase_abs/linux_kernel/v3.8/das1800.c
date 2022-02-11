static inline T_1 F_1 ( const struct V_1 * V_2 ,
T_1 V_3 )
{
V_3 += 1 << ( V_4 -> V_5 - 1 ) ;
return V_3 ;
}
static void F_2 ( struct V_1 * V_2 , T_1 * V_6 ,
unsigned int V_7 )
{
unsigned int V_8 ;
int V_9 ;
V_9 = F_3 ( V_2 -> V_10 + V_11 ) & V_12 ;
if ( ! V_9 ) {
for ( V_8 = 0 ; V_8 < V_7 ; V_8 ++ )
V_6 [ V_8 ] = F_1 ( V_2 , V_6 [ V_8 ] ) ;
}
}
static void F_4 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
int V_18 = 0 ;
struct V_19 * V_20 = & V_14 -> V_21 -> V_20 ;
V_18 = V_22 / 2 ;
if ( V_20 -> V_23 == V_24 && V_16 -> V_25 < V_18 )
V_18 = V_16 -> V_25 ;
F_5 ( V_2 -> V_10 + V_26 , V_16 -> V_27 , V_18 ) ;
F_2 ( V_2 , V_16 -> V_27 , V_18 ) ;
F_6 ( V_14 , V_16 -> V_27 ,
V_18 * sizeof( V_16 -> V_27 [ 0 ] ) ) ;
if ( V_20 -> V_23 == V_24 )
V_16 -> V_25 -= V_18 ;
return;
}
static void F_7 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
short V_28 ;
int V_9 ;
struct V_19 * V_20 = & V_14 -> V_21 -> V_20 ;
V_9 = F_3 ( V_2 -> V_10 + V_11 ) & V_12 ;
while ( F_3 ( V_2 -> V_10 + V_29 ) & V_30 ) {
if ( V_20 -> V_23 == V_24 && V_16 -> V_25 == 0 )
break;
V_28 = F_8 ( V_2 -> V_10 + V_26 ) ;
if ( ! V_9 )
;
V_28 = F_1 ( V_2 , V_28 ) ;
F_9 ( V_14 , V_28 ) ;
if ( V_20 -> V_23 == V_24 )
V_16 -> V_25 -- ;
}
return;
}
static void F_10 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
unsigned int V_31 , T_1 * V_32 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
unsigned int V_33 , V_34 ;
struct V_19 * V_20 = & V_14 -> V_21 -> V_20 ;
F_11 ( V_31 ) ;
F_12 ( V_31 ) ;
V_33 = V_16 -> V_35 - F_13 ( V_31 ) ;
V_34 = V_33 / sizeof( short ) ;
if ( V_20 -> V_23 == V_24 && V_16 -> V_25 < V_34 )
V_34 = V_16 -> V_25 ;
F_2 ( V_2 , V_32 , V_34 ) ;
F_6 ( V_14 , V_32 , V_33 ) ;
if ( V_14 -> V_21 -> V_20 . V_23 == V_24 )
V_16 -> V_25 -= V_34 ;
return;
}
static void F_14 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
unsigned long V_36 ;
const int V_37 = V_16 -> V_38 & V_39 ;
V_36 = F_15 () ;
F_10 ( V_2 , V_14 , V_16 -> V_40 ,
V_16 -> V_41 ) ;
if ( V_37 ) {
if ( V_16 -> V_40 == V_16 -> V_42 ) {
V_16 -> V_40 = V_16 -> V_43 ;
V_16 -> V_41 = V_16 -> V_44 ;
} else {
V_16 -> V_40 = V_16 -> V_42 ;
V_16 -> V_41 = V_16 -> V_27 ;
}
F_10 ( V_2 , V_14 , V_16 -> V_40 ,
V_16 -> V_41 ) ;
}
F_16 ( V_36 ) ;
F_7 ( V_2 , V_14 ) ;
return;
}
static void F_17 ( struct V_1 * V_2 ,
struct V_13 * V_14 , unsigned int V_45 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
unsigned long V_36 ;
const int V_37 = V_16 -> V_38 & V_39 ;
V_36 = F_15 () ;
F_10 ( V_2 , V_14 , V_16 -> V_40 ,
V_16 -> V_41 ) ;
F_18 ( V_16 -> V_40 ,
F_19 ( V_16 -> V_41 ) ) ;
F_20 ( V_16 -> V_40 , V_16 -> V_35 ) ;
F_21 ( V_16 -> V_40 ) ;
F_16 ( V_36 ) ;
if ( V_45 & V_46 ) {
F_22 ( V_47 & ~ V_46 , V_2 -> V_10 + V_29 ) ;
if ( V_37 ) {
if ( V_16 -> V_40 == V_16 -> V_42 ) {
V_16 -> V_40 = V_16 -> V_43 ;
V_16 -> V_41 = V_16 -> V_44 ;
} else {
V_16 -> V_40 = V_16 -> V_42 ;
V_16 -> V_41 = V_16 -> V_27 ;
}
}
}
return;
}
static int F_23 ( struct V_1 * V_2 , struct V_13 * V_14 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
F_22 ( 0x0 , V_2 -> V_10 + V_29 ) ;
F_22 ( 0x0 , V_2 -> V_10 + V_48 ) ;
F_22 ( 0x0 , V_2 -> V_10 + V_49 ) ;
if ( V_16 -> V_42 )
F_11 ( V_16 -> V_42 ) ;
if ( V_16 -> V_43 )
F_11 ( V_16 -> V_43 ) ;
return 0 ;
}
static void F_24 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
struct V_13 * V_14 = & V_2 -> V_50 [ 0 ] ;
struct V_51 * V_21 = V_14 -> V_21 ;
struct V_19 * V_20 = & V_21 -> V_20 ;
unsigned int V_45 = F_3 ( V_2 -> V_10 + V_29 ) ;
V_21 -> V_52 = 0 ;
F_22 ( V_53 , V_2 -> V_10 + V_54 ) ;
if ( V_16 -> V_38 & V_55 ) {
F_17 ( V_2 , V_14 , V_45 ) ;
} else if ( V_45 & V_56 ) {
F_4 ( V_2 , V_14 ) ;
} else if ( V_45 & V_30 ) {
F_7 ( V_2 , V_14 ) ;
}
V_21 -> V_52 |= V_57 ;
if ( V_45 & V_58 ) {
F_22 ( V_47 & ~ V_58 , V_2 -> V_10 + V_29 ) ;
F_25 ( V_2 , L_1 ) ;
F_23 ( V_2 , V_14 ) ;
V_21 -> V_52 |= V_59 | V_60 ;
F_26 ( V_2 , V_14 ) ;
return;
}
if ( V_45 & V_61 ) {
F_22 ( V_47 & ~ V_61 , V_2 -> V_10 + V_29 ) ;
if ( V_16 -> V_38 & V_55 )
F_14 ( V_2 , V_14 ) ;
else
F_7 ( V_2 , V_14 ) ;
F_23 ( V_2 , V_14 ) ;
V_21 -> V_52 |= V_60 ;
} else if ( V_20 -> V_23 == V_24 && V_16 -> V_25 == 0 ) {
F_23 ( V_2 , V_14 ) ;
V_21 -> V_52 |= V_60 ;
}
F_26 ( V_2 , V_14 ) ;
return;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
unsigned long V_36 ;
F_28 ( & V_2 -> V_62 , V_36 ) ;
F_24 ( V_2 ) ;
F_29 ( & V_2 -> V_62 , V_36 ) ;
return V_14 -> V_21 -> V_63 - V_14 -> V_21 -> V_64 ;
}
static T_2 F_30 ( int V_65 , void * V_66 )
{
struct V_1 * V_2 = V_66 ;
unsigned int V_45 ;
if ( V_2 -> V_67 == 0 ) {
F_25 ( V_2 , L_2 ) ;
return V_68 ;
}
F_31 ( & V_2 -> V_62 ) ;
V_45 = F_3 ( V_2 -> V_10 + V_29 ) ;
if ( ! ( V_45 & INT ) ) {
F_32 ( & V_2 -> V_62 ) ;
return V_69 ;
}
F_22 ( V_47 & ~ INT , V_2 -> V_10 + V_29 ) ;
F_24 ( V_2 ) ;
F_32 ( & V_2 -> V_62 ) ;
return V_68 ;
}
static unsigned int F_33 ( unsigned int V_70 , int V_71 )
{
unsigned int V_72 ;
if ( V_70 > 64000 )
V_70 = 64000 ;
switch ( V_71 ) {
case V_73 :
default:
V_72 = ( V_70 + 500 ) / 1000 ;
break;
case V_74 :
V_72 = V_70 / 1000 ;
break;
case V_75 :
V_72 = ( V_70 - 1 ) / 1000 + 1 ;
break;
}
return V_72 * 1000 ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
struct V_19 * V_20 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
int V_76 = 0 ;
unsigned int V_77 ;
int V_8 ;
int V_9 ;
V_76 |= F_35 ( & V_20 -> V_78 , V_79 | V_80 ) ;
V_76 |= F_35 ( & V_20 -> V_81 ,
V_82 | V_83 | V_80 ) ;
V_76 |= F_35 ( & V_20 -> V_84 , V_83 | V_80 ) ;
V_76 |= F_35 ( & V_20 -> V_85 , V_24 ) ;
V_76 |= F_35 ( & V_20 -> V_23 ,
V_24 | V_80 | V_86 ) ;
if ( V_76 )
return 1 ;
V_76 |= F_36 ( V_20 -> V_78 ) ;
V_76 |= F_36 ( V_20 -> V_81 ) ;
V_76 |= F_36 ( V_20 -> V_84 ) ;
V_76 |= F_36 ( V_20 -> V_23 ) ;
if ( V_20 -> V_81 != V_82 &&
V_20 -> V_84 != V_83 )
V_76 |= - V_87 ;
if ( V_76 )
return 2 ;
V_76 |= F_37 ( & V_20 -> V_88 , 0 ) ;
if ( V_20 -> V_84 == V_83 )
V_76 |= F_38 ( & V_20 -> V_70 ,
V_4 -> V_89 ) ;
V_76 |= F_38 ( & V_20 -> V_90 , 1 ) ;
V_76 |= F_37 ( & V_20 -> V_91 , V_20 -> V_90 ) ;
switch ( V_20 -> V_23 ) {
case V_24 :
V_76 |= F_38 ( & V_20 -> V_92 , 1 ) ;
break;
case V_86 :
V_76 |= F_37 ( & V_20 -> V_92 , 0 ) ;
break;
default:
break;
}
if ( V_76 )
return 3 ;
if ( V_20 -> V_84 == V_83 ) {
if ( V_20 -> V_81 == V_82 ) {
V_77 = V_20 -> V_70 ;
F_39 ( V_93 ,
& ( V_16 -> V_94 ) ,
& ( V_16 -> V_95 ) ,
& ( V_20 -> V_70 ) ,
V_20 ->
V_36 & V_96 ) ;
if ( V_77 != V_20 -> V_70 )
V_76 ++ ;
}
else {
V_77 = V_20 -> V_70 ;
V_20 -> V_70 =
F_33 ( V_20 -> V_70 ,
V_20 -> V_36 & V_96 ) ;
if ( V_77 != V_20 -> V_70 )
V_76 ++ ;
if ( V_20 -> V_81 == V_83 ) {
if ( V_20 -> V_70 * V_20 -> V_90 >
V_20 -> V_97 ) {
V_20 -> V_97 =
V_20 -> V_70 *
V_20 -> V_90 ;
V_76 ++ ;
}
V_77 = V_20 -> V_97 ;
F_39 ( V_93 ,
& ( V_16 ->
V_94 ) ,
& ( V_16 ->
V_95 ) ,
& ( V_20 ->
V_97 ) ,
V_20 ->
V_36 &
V_96 ) ;
if ( V_77 != V_20 -> V_97 )
V_76 ++ ;
}
}
}
if ( V_76 )
return 4 ;
if ( V_20 -> V_98 ) {
V_9 = F_40 ( V_20 -> V_98 [ 0 ] ) & V_99 ;
for ( V_8 = 1 ; V_8 < V_20 -> V_90 ; V_8 ++ ) {
if ( V_9 != ( F_40 ( V_20 -> V_98 [ V_8 ] ) & V_99 ) ) {
F_25 ( V_2 ,
L_3 ) ;
V_76 ++ ;
break;
}
}
}
if ( V_76 )
return 5 ;
return 0 ;
}
static int F_41 ( const struct V_19 * V_20 )
{
int V_100 ;
V_100 = V_101 ;
if ( V_20 -> V_23 == V_80 )
V_100 |= V_102 ;
switch ( V_20 -> V_78 ) {
case V_80 :
V_100 |= V_103 | V_104 ;
break;
case V_79 :
V_100 |= V_105 ;
break;
default:
break;
}
return V_100 ;
}
static int F_42 ( const struct V_19 * V_20 )
{
int V_106 ;
int V_107 ;
V_107 = F_43 ( V_20 -> V_98 [ 0 ] ) ;
V_106 = V_108 ;
if ( V_107 != V_109 )
V_106 |= V_110 ;
if ( V_107 == V_111 )
V_106 |= V_112 ;
if ( F_40 ( V_20 -> V_98 [ 0 ] ) & V_99 )
V_106 |= V_12 ;
switch ( V_20 -> V_81 ) {
case V_82 :
switch ( V_20 -> V_84 ) {
case V_83 :
V_106 |= V_113 ;
break;
case V_80 :
V_106 |= V_114 ;
break;
default:
break;
}
break;
case V_83 :
V_106 |= V_115 | V_113 ;
break;
case V_80 :
V_106 |= V_115 | V_114 ;
break;
default:
break;
}
return V_106 ;
}
static int F_44 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
int V_76 = 0 ;
if ( F_45 ( V_2 -> V_10 + V_116 , 0 , 1 , V_16 -> V_94 ,
2 ) )
V_76 ++ ;
if ( F_45 ( V_2 -> V_10 + V_116 , 0 , 2 , V_16 -> V_95 ,
2 ) )
V_76 ++ ;
if ( V_76 )
return - 1 ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 ,
const struct V_19 * V_20 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
unsigned int V_117 ;
switch ( V_20 -> V_81 ) {
case V_82 :
if ( V_20 -> V_84 == V_83 ) {
V_117 = V_20 -> V_70 ;
F_39 ( V_93 ,
& V_16 -> V_94 ,
& V_16 -> V_95 ,
& V_117 ,
V_20 -> V_36 &
V_96 ) ;
if ( F_44 ( V_2 ) < 0 )
return - 1 ;
}
break;
case V_83 :
V_117 = V_20 -> V_97 ;
F_39 ( V_93 , & V_16 -> V_94 ,
& V_16 -> V_95 , & V_117 ,
V_20 -> V_36 & V_96 ) ;
if ( F_44 ( V_2 ) < 0 )
return - 1 ;
break;
default:
break;
}
if ( V_20 -> V_23 == V_80 ) {
F_45 ( V_2 -> V_10 + V_116 , 0 , 0 , 1 , 0 ) ;
}
return 0 ;
}
static unsigned int F_47 ( const struct V_19 * V_20 )
{
unsigned int V_118 = V_119 ;
static const int V_120 = 2 ;
unsigned int V_121 = 300000000 ;
unsigned int V_122 ;
switch ( V_20 -> V_81 ) {
case V_82 :
if ( V_20 -> V_84 == V_83 )
V_118 = ( V_121 / V_20 -> V_70 ) * V_120 ;
break;
case V_83 :
V_118 = ( V_121 / ( V_20 -> V_97 * V_20 -> V_90 ) ) *
V_120 ;
break;
default:
V_118 = V_119 ;
break;
}
V_122 = V_119 ;
if ( V_20 -> V_23 == V_24 &&
V_20 -> V_92 * V_20 -> V_90 * V_120 < V_122 )
V_122 = V_20 -> V_92 * V_20 -> V_90 * V_120 ;
if ( V_118 > V_122 )
V_118 = V_122 ;
if ( V_118 < V_120 )
V_118 = V_120 ;
return V_118 ;
}
static void F_48 ( struct V_1 * V_2 , const struct V_19 * V_20 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
unsigned long V_123 ;
const int V_37 = V_16 -> V_38 & V_39 ;
if ( ( V_16 -> V_38 & V_55 ) == 0 )
return;
V_16 -> V_35 = F_47 ( V_20 ) ;
V_123 = F_15 () ;
F_11 ( V_16 -> V_42 ) ;
F_12 ( V_16 -> V_42 ) ;
F_18 ( V_16 -> V_42 , F_19 ( V_16 -> V_27 ) ) ;
F_20 ( V_16 -> V_42 , V_16 -> V_35 ) ;
V_16 -> V_40 = V_16 -> V_42 ;
V_16 -> V_41 = V_16 -> V_27 ;
F_21 ( V_16 -> V_42 ) ;
if ( V_37 ) {
F_11 ( V_16 -> V_43 ) ;
F_12 ( V_16 -> V_43 ) ;
F_18 ( V_16 -> V_43 , F_19 ( V_16 -> V_44 ) ) ;
F_20 ( V_16 -> V_43 , V_16 -> V_35 ) ;
F_21 ( V_16 -> V_43 ) ;
}
F_16 ( V_123 ) ;
return;
}
static void F_49 ( struct V_1 * V_2 ,
const struct V_19 * V_20 )
{
int V_8 , V_124 , V_125 ;
unsigned long V_126 ;
const int V_127 = 0x3 ;
const int V_128 = 8 ;
V_124 = V_20 -> V_90 ;
F_28 ( & V_2 -> V_62 , V_126 ) ;
F_22 ( V_129 , V_2 -> V_10 + V_54 ) ;
F_22 ( V_124 - 1 , V_2 -> V_10 + V_130 ) ;
for ( V_8 = 0 ; V_8 < V_124 ; V_8 ++ ) {
V_125 =
F_50 ( V_20 -> V_98 [ V_8 ] ) |
( ( F_40 ( V_20 -> V_98 [ V_8 ] ) & V_127 ) <<
V_128 ) ;
F_51 ( V_125 , V_2 -> V_10 + V_131 ) ;
}
F_22 ( V_124 - 1 , V_2 -> V_10 + V_130 ) ;
F_29 ( & V_2 -> V_62 , V_126 ) ;
return;
}
static int F_52 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
int V_132 ;
int V_100 , V_106 ;
struct V_51 * V_21 = V_14 -> V_21 ;
const struct V_19 * V_20 = & V_21 -> V_20 ;
if ( ! V_2 -> V_65 ) {
F_25 ( V_2 ,
L_4 ) ;
return - 1 ;
}
if ( V_20 -> V_36 & ( V_133 | V_134 ) )
V_16 -> V_38 &= ~ V_55 ;
else
V_16 -> V_38 |= V_16 -> V_135 ;
if ( V_20 -> V_36 & V_133 ) {
V_16 -> V_38 &= ~ V_136 ;
} else {
V_16 -> V_38 |= V_136 ;
}
if ( V_20 -> V_23 == V_24 )
V_16 -> V_25 = V_20 -> V_92 * V_20 -> V_90 ;
F_23 ( V_2 , V_14 ) ;
V_100 = F_41 ( V_20 ) ;
V_106 = F_42 ( V_20 ) ;
F_49 ( V_2 , V_20 ) ;
V_132 = F_46 ( V_2 , V_20 ) ;
if ( V_132 < 0 ) {
F_25 ( V_2 , L_5 ) ;
return V_132 ;
}
F_48 ( V_2 , V_20 ) ;
F_22 ( V_106 , V_2 -> V_10 + V_11 ) ;
if ( V_106 & V_115 ) {
F_22 ( V_20 -> V_70 / 1000 - 1 ,
V_2 -> V_10 + V_137 ) ;
F_22 ( V_20 -> V_90 - 1 , V_2 -> V_10 + V_138 ) ;
}
F_22 ( V_16 -> V_38 , V_2 -> V_10 + V_48 ) ;
F_22 ( V_100 , V_2 -> V_10 + V_49 ) ;
F_22 ( V_139 , V_2 -> V_10 + V_29 ) ;
return 0 ;
}
static int F_53 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
struct V_140 * V_141 , unsigned int * V_142 )
{
int V_8 , V_124 ;
int V_143 , V_144 , V_107 , V_125 ;
int V_145 = 1000 ;
short V_28 ;
int V_146 = 0 ;
unsigned long V_126 ;
V_107 = F_43 ( V_141 -> V_147 ) ;
V_146 |= V_108 ;
if ( V_107 != V_109 )
V_146 |= V_110 ;
if ( V_107 == V_111 )
V_146 |= V_112 ;
if ( F_40 ( V_141 -> V_147 ) & V_99 )
V_146 |= V_12 ;
F_22 ( V_146 , V_2 -> V_10 + V_11 ) ;
F_22 ( V_139 , V_2 -> V_10 + V_29 ) ;
F_22 ( 0x0 , V_2 -> V_10 + V_49 ) ;
F_22 ( V_101 , V_2 -> V_10 + V_49 ) ;
V_143 = F_50 ( V_141 -> V_147 ) ;
V_144 = F_40 ( V_141 -> V_147 ) & 0x3 ;
V_125 = V_143 | ( V_144 << 8 ) ;
F_28 ( & V_2 -> V_62 , V_126 ) ;
F_22 ( V_129 , V_2 -> V_10 + V_54 ) ;
F_22 ( 0x0 , V_2 -> V_10 + V_130 ) ;
F_51 ( V_125 , V_2 -> V_10 + V_131 ) ;
F_22 ( 0x0 , V_2 -> V_10 + V_130 ) ;
F_22 ( V_53 , V_2 -> V_10 + V_54 ) ;
for ( V_124 = 0 ; V_124 < V_141 -> V_124 ; V_124 ++ ) {
F_22 ( 0 , V_2 -> V_10 + V_26 ) ;
for ( V_8 = 0 ; V_8 < V_145 ; V_8 ++ ) {
if ( F_3 ( V_2 -> V_10 + V_29 ) & V_30 )
break;
}
if ( V_8 == V_145 ) {
F_25 ( V_2 , L_6 ) ;
V_124 = - V_148 ;
goto exit;
}
V_28 = F_8 ( V_2 -> V_10 + V_26 ) ;
if ( ( V_146 & V_12 ) == 0 )
V_28 += 1 << ( V_4 -> V_5 - 1 ) ;
V_142 [ V_124 ] = V_28 ;
}
exit:
F_29 ( & V_2 -> V_62 , V_126 ) ;
return V_124 ;
}
static int F_54 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
struct V_140 * V_141 , unsigned int * V_142 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
int V_143 = F_50 ( V_141 -> V_147 ) ;
int V_149 = V_4 -> V_150 - 1 ;
short V_151 ;
unsigned long V_126 ;
V_151 = V_142 [ 0 ] - ( 1 << ( V_4 -> V_5 - 1 ) ) ;
if ( V_143 == V_149 )
V_16 -> V_152 = V_151 ;
F_28 ( & V_2 -> V_62 , V_126 ) ;
F_22 ( F_55 ( V_143 ) , V_2 -> V_10 + V_54 ) ;
F_51 ( V_151 , V_2 -> V_10 + V_153 ) ;
if ( V_143 != V_149 ) {
F_22 ( F_55 ( V_149 ) , V_2 -> V_10 + V_54 ) ;
F_51 ( V_16 -> V_152 , V_2 -> V_10 + V_153 ) ;
}
F_29 ( & V_2 -> V_62 , V_126 ) ;
return 1 ;
}
static int F_56 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
struct V_140 * V_141 , unsigned int * V_142 )
{
V_142 [ 1 ] = F_3 ( V_2 -> V_10 + V_154 ) & 0xf ;
V_142 [ 0 ] = 0 ;
return V_141 -> V_124 ;
}
static int F_57 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
struct V_140 * V_141 , unsigned int * V_142 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
unsigned int V_155 ;
V_142 [ 0 ] &= ( 1 << V_14 -> V_156 ) - 1 ;
V_155 = V_16 -> V_157 ;
V_155 &= ~ V_142 [ 0 ] ;
V_155 |= V_142 [ 0 ] & V_142 [ 1 ] ;
V_16 -> V_157 = V_155 ;
F_22 ( V_16 -> V_157 , V_2 -> V_10 + V_154 ) ;
V_142 [ 1 ] = V_16 -> V_157 ;
return V_141 -> V_124 ;
}
static int F_58 ( struct V_1 * V_2 , unsigned int V_42 ,
unsigned int V_43 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
unsigned long V_36 ;
if ( V_2 -> V_65 && V_42 ) {
switch ( ( V_42 & 0x7 ) | ( V_43 << 4 ) ) {
case 0x5 :
V_16 -> V_135 |= V_158 ;
break;
case 0x6 :
V_16 -> V_135 |= V_159 ;
break;
case 0x7 :
V_16 -> V_135 |= V_160 ;
break;
case 0x65 :
V_16 -> V_135 |= V_161 ;
break;
case 0x76 :
V_16 -> V_135 |= V_162 ;
break;
case 0x57 :
V_16 -> V_135 |= V_163 ;
break;
default:
F_59 ( V_2 -> V_164 ,
L_7 ) ;
F_59 ( V_2 -> V_164 ,
L_8 ) ;
F_59 ( V_2 -> V_164 ,
L_9 ) ;
return - V_87 ;
break;
}
if ( F_60 ( V_42 , V_2 -> V_165 -> V_166 ) ) {
F_59 ( V_2 -> V_164 ,
L_10 , V_42 ) ;
return - V_87 ;
}
V_16 -> V_42 = V_42 ;
V_16 -> V_40 = V_42 ;
if ( V_43 ) {
if ( F_60 ( V_43 , V_2 -> V_165 -> V_166 ) ) {
F_59 ( V_2 -> V_164 ,
L_10 ,
V_43 ) ;
return - V_87 ;
}
V_16 -> V_43 = V_43 ;
}
V_16 -> V_27 = F_61 ( V_119 , V_167 | V_168 ) ;
if ( V_16 -> V_27 == NULL )
return - V_169 ;
V_16 -> V_41 = V_16 -> V_27 ;
if ( V_43 ) {
V_16 -> V_44 =
F_61 ( V_119 , V_167 | V_168 ) ;
if ( V_16 -> V_44 == NULL )
return - V_169 ;
}
V_36 = F_15 () ;
F_11 ( V_16 -> V_42 ) ;
F_62 ( V_16 -> V_42 , V_170 ) ;
if ( V_43 ) {
F_11 ( V_16 -> V_43 ) ;
F_62 ( V_16 -> V_43 , V_170 ) ;
}
F_16 ( V_36 ) ;
}
return 0 ;
}
static int F_63 ( struct V_1 * V_2 )
{
int V_171 ;
int V_172 ;
V_171 = ( F_3 ( V_2 -> V_10 + V_154 ) >> 4 ) & 0xf ;
V_172 = ( (struct V_173 * ) V_2 -> V_174 ) - V_175 ;
switch ( V_171 ) {
case 0x3 :
if ( V_172 == V_176 || V_172 == V_177 ||
V_172 == V_178 || V_172 == V_179 ) {
F_64 ( V_2 -> V_164 , L_11 ,
V_175 [ V_172 ] . V_180 ) ;
return V_172 ;
}
F_65
( L_12 ) ;
return V_181 ;
break;
case 0x4 :
if ( V_172 == V_182 || V_172 == V_183 ) {
F_64 ( V_2 -> V_164 , L_11 ,
V_175 [ V_172 ] . V_180 ) ;
return V_172 ;
}
F_65
( L_13 ) ;
return V_184 ;
break;
case 0x5 :
if ( V_172 == V_185 || V_172 == V_186 ||
V_172 == V_187 || V_172 == V_188 ) {
F_64 ( V_2 -> V_164 , L_11 ,
V_175 [ V_172 ] . V_180 ) ;
return V_172 ;
}
F_65
( L_14 ) ;
return V_185 ;
break;
case 0x6 :
if ( V_172 == V_184 || V_172 == V_189 ) {
F_64 ( V_2 -> V_164 , L_11 ,
V_175 [ V_172 ] . V_180 ) ;
return V_172 ;
}
F_65
( L_15 ) ;
return V_184 ;
break;
case 0x7 :
if ( V_172 == V_181 || V_172 == V_190 ||
V_172 == V_191 || V_172 == V_192 ) {
F_64 ( V_2 -> V_164 , L_11 ,
V_175 [ V_172 ] . V_180 ) ;
return V_172 ;
}
F_65
( L_16 ) ;
return V_181 ;
break;
case 0x8 :
if ( V_172 == V_193 || V_172 == V_194 ) {
F_64 ( V_2 -> V_164 , L_11 ,
V_175 [ V_172 ] . V_180 ) ;
return V_172 ;
}
F_65
( L_17 ) ;
return V_193 ;
break;
default:
F_65
( L_18 ,
V_171 ) ;
return V_172 ;
break;
}
return - 1 ;
}
static int F_66 ( struct V_1 * V_2 ,
struct V_195 * V_196 )
{
struct V_15 * V_16 ;
struct V_13 * V_14 ;
unsigned long V_10 = V_196 -> V_197 [ 0 ] ;
unsigned int V_65 = V_196 -> V_197 [ 1 ] ;
unsigned int V_42 = V_196 -> V_197 [ 2 ] ;
unsigned int V_43 = V_196 -> V_197 [ 3 ] ;
unsigned long V_198 ;
int V_172 ;
int V_199 ;
V_16 = F_67 ( sizeof( * V_16 ) , V_167 ) ;
if ( ! V_16 )
return - V_169 ;
V_2 -> V_17 = V_16 ;
F_65 ( V_200 L_19 , V_2 -> V_201 ,
V_2 -> V_165 -> V_166 , V_10 ) ;
if ( V_65 ) {
F_65 ( V_202 L_20 , V_65 ) ;
if ( V_42 ) {
F_65 ( V_202 L_21 , V_42 ) ;
if ( V_43 )
F_65 ( V_202 L_22 , V_43 ) ;
}
}
F_65 ( V_202 L_23 ) ;
if ( V_10 == 0 ) {
F_59 ( V_2 -> V_164 , L_24 ) ;
return - V_87 ;
}
if ( ! F_68 ( V_10 , V_203 , V_2 -> V_165 -> V_166 ) ) {
F_65
( L_25 ,
V_10 , V_10 + V_203 - 1 ) ;
return - V_204 ;
}
V_2 -> V_10 = V_10 ;
V_172 = F_63 ( V_2 ) ;
if ( V_172 < 0 ) {
F_59 ( V_2 -> V_164 , L_26 ) ;
return - V_205 ;
}
V_2 -> V_174 = V_175 + V_172 ;
V_2 -> V_206 = V_4 -> V_180 ;
if ( V_4 -> V_207 == 2 ) {
V_198 = V_10 + V_208 ;
if ( ! F_68 ( V_198 , V_203 ,
V_2 -> V_165 -> V_166 ) ) {
F_65
( L_25 ,
V_198 , V_198 + V_203 - 1 ) ;
return - V_204 ;
}
V_16 -> V_198 = V_198 ;
}
if ( V_65 ) {
if ( F_69 ( V_65 , F_30 , 0 ,
V_2 -> V_165 -> V_166 , V_2 ) ) {
F_64 ( V_2 -> V_164 , L_27 ,
V_65 ) ;
return - V_87 ;
}
}
V_2 -> V_65 = V_65 ;
switch ( V_65 ) {
case 0 :
break;
case 3 :
V_16 -> V_38 |= 0x8 ;
break;
case 5 :
V_16 -> V_38 |= 0x10 ;
break;
case 7 :
V_16 -> V_38 |= 0x18 ;
break;
case 10 :
V_16 -> V_38 |= 0x28 ;
break;
case 11 :
V_16 -> V_38 |= 0x30 ;
break;
case 15 :
V_16 -> V_38 |= 0x38 ;
break;
default:
F_59 ( V_2 -> V_164 , L_28 ) ;
return - V_87 ;
break;
}
V_199 = F_58 ( V_2 , V_42 , V_43 ) ;
if ( V_199 < 0 )
return V_199 ;
if ( V_16 -> V_27 == NULL ) {
V_16 -> V_27 =
F_61 ( V_22 * sizeof( T_1 ) , V_167 ) ;
if ( V_16 -> V_27 == NULL )
return - V_169 ;
}
V_199 = F_70 ( V_2 , 4 ) ;
if ( V_199 )
return V_199 ;
V_14 = & V_2 -> V_50 [ 0 ] ;
V_2 -> V_209 = V_14 ;
V_14 -> type = V_210 ;
V_14 -> V_211 = V_212 | V_213 | V_214 | V_215 ;
if ( V_4 -> V_216 )
V_14 -> V_211 |= V_217 ;
V_14 -> V_156 = V_4 -> V_218 ;
V_14 -> V_219 = V_4 -> V_218 ;
V_14 -> V_220 = ( 1 << V_4 -> V_5 ) - 1 ;
V_14 -> V_221 = V_4 -> V_222 ;
V_14 -> V_223 = F_52 ;
V_14 -> V_224 = F_34 ;
V_14 -> V_225 = F_53 ;
V_14 -> V_226 = F_27 ;
V_14 -> V_227 = F_23 ;
V_14 = & V_2 -> V_50 [ 1 ] ;
if ( V_4 -> V_207 == 1 ) {
V_14 -> type = V_228 ;
V_14 -> V_211 = V_229 ;
V_14 -> V_156 = V_4 -> V_150 ;
V_14 -> V_220 = ( 1 << V_4 -> V_5 ) - 1 ;
V_14 -> V_221 = & V_230 ;
V_14 -> V_231 = F_54 ;
} else {
V_14 -> type = V_232 ;
}
V_14 = & V_2 -> V_50 [ 2 ] ;
V_14 -> type = V_233 ;
V_14 -> V_211 = V_212 ;
V_14 -> V_156 = 4 ;
V_14 -> V_220 = 1 ;
V_14 -> V_221 = & V_234 ;
V_14 -> V_235 = F_56 ;
V_14 = & V_2 -> V_50 [ 3 ] ;
V_14 -> type = V_236 ;
V_14 -> V_211 = V_229 | V_212 ;
V_14 -> V_156 = V_4 -> V_237 ;
V_14 -> V_220 = 1 ;
V_14 -> V_221 = & V_234 ;
V_14 -> V_235 = F_57 ;
F_23 ( V_2 , V_2 -> V_209 ) ;
F_22 ( V_16 -> V_157 , V_2 -> V_10 + V_154 ) ;
if ( V_4 -> V_207 == 1 ) {
F_22 ( F_55 ( V_4 -> V_150 - 1 ) ,
V_2 -> V_10 + V_54 ) ;
F_51 ( V_16 -> V_152 , V_2 -> V_10 + V_153 ) ;
}
return 0 ;
}
static void F_71 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
if ( V_2 -> V_10 )
F_72 ( V_2 -> V_10 , V_203 ) ;
if ( V_2 -> V_65 )
F_73 ( V_2 -> V_65 , V_2 ) ;
if ( V_16 ) {
if ( V_16 -> V_198 )
F_72 ( V_16 -> V_198 , V_203 ) ;
if ( V_16 -> V_42 )
F_74 ( V_16 -> V_42 ) ;
if ( V_16 -> V_43 )
F_74 ( V_16 -> V_43 ) ;
F_75 ( V_16 -> V_27 ) ;
F_75 ( V_16 -> V_44 ) ;
}
}
