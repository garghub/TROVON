static inline T_1 F_1 ( const struct V_1 * V_2 ,
T_1 V_3 )
{
const struct V_4 * V_5 = F_2 ( V_2 ) ;
V_3 += 1 << ( V_5 -> V_6 - 1 ) ;
return V_3 ;
}
static void F_3 ( struct V_1 * V_2 , T_1 * V_7 ,
unsigned int V_8 )
{
unsigned int V_9 ;
int V_10 ;
V_10 = F_4 ( V_2 -> V_11 + V_12 ) & V_13 ;
if ( ! V_10 ) {
for ( V_9 = 0 ; V_9 < V_8 ; V_9 ++ )
V_7 [ V_9 ] = F_1 ( V_2 , V_7 [ V_9 ] ) ;
}
}
static void F_5 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_16 * V_17 = V_2 -> V_18 ;
int V_19 = 0 ;
struct V_20 * V_21 = & V_15 -> V_22 -> V_21 ;
V_19 = V_23 / 2 ;
if ( V_21 -> V_24 == V_25 && V_17 -> V_26 < V_19 )
V_19 = V_17 -> V_26 ;
F_6 ( V_2 -> V_11 + V_27 , V_17 -> V_28 , V_19 ) ;
F_3 ( V_2 , V_17 -> V_28 , V_19 ) ;
F_7 ( V_15 , V_17 -> V_28 ,
V_19 * sizeof( V_17 -> V_28 [ 0 ] ) ) ;
if ( V_21 -> V_24 == V_25 )
V_17 -> V_26 -= V_19 ;
return;
}
static void F_8 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_16 * V_17 = V_2 -> V_18 ;
short V_29 ;
int V_10 ;
struct V_20 * V_21 = & V_15 -> V_22 -> V_21 ;
V_10 = F_4 ( V_2 -> V_11 + V_12 ) & V_13 ;
while ( F_4 ( V_2 -> V_11 + V_30 ) & V_31 ) {
if ( V_21 -> V_24 == V_25 && V_17 -> V_26 == 0 )
break;
V_29 = F_9 ( V_2 -> V_11 + V_27 ) ;
if ( ! V_10 )
;
V_29 = F_1 ( V_2 , V_29 ) ;
F_10 ( V_15 , V_29 ) ;
if ( V_21 -> V_24 == V_25 )
V_17 -> V_26 -- ;
}
return;
}
static void F_11 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
unsigned int V_32 , T_1 * V_33 )
{
struct V_16 * V_17 = V_2 -> V_18 ;
unsigned int V_34 , V_35 ;
struct V_20 * V_21 = & V_15 -> V_22 -> V_21 ;
F_12 ( V_32 ) ;
F_13 ( V_32 ) ;
V_34 = V_17 -> V_36 - F_14 ( V_32 ) ;
V_35 = V_34 / sizeof( short ) ;
if ( V_21 -> V_24 == V_25 && V_17 -> V_26 < V_35 )
V_35 = V_17 -> V_26 ;
F_3 ( V_2 , V_33 , V_35 ) ;
F_7 ( V_15 , V_33 , V_34 ) ;
if ( V_15 -> V_22 -> V_21 . V_24 == V_25 )
V_17 -> V_26 -= V_35 ;
return;
}
static void F_15 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_16 * V_17 = V_2 -> V_18 ;
unsigned long V_37 ;
const int V_38 = V_17 -> V_39 & V_40 ;
V_37 = F_16 () ;
F_11 ( V_2 , V_15 , V_17 -> V_41 ,
V_17 -> V_42 ) ;
if ( V_38 ) {
if ( V_17 -> V_41 == V_17 -> V_43 ) {
V_17 -> V_41 = V_17 -> V_44 ;
V_17 -> V_42 = V_17 -> V_45 ;
} else {
V_17 -> V_41 = V_17 -> V_43 ;
V_17 -> V_42 = V_17 -> V_28 ;
}
F_11 ( V_2 , V_15 , V_17 -> V_41 ,
V_17 -> V_42 ) ;
}
F_17 ( V_37 ) ;
F_8 ( V_2 , V_15 ) ;
return;
}
static void F_18 ( struct V_1 * V_2 ,
struct V_14 * V_15 , unsigned int V_46 )
{
struct V_16 * V_17 = V_2 -> V_18 ;
unsigned long V_37 ;
const int V_38 = V_17 -> V_39 & V_40 ;
V_37 = F_16 () ;
F_11 ( V_2 , V_15 , V_17 -> V_41 ,
V_17 -> V_42 ) ;
F_19 ( V_17 -> V_41 ,
F_20 ( V_17 -> V_42 ) ) ;
F_21 ( V_17 -> V_41 , V_17 -> V_36 ) ;
F_22 ( V_17 -> V_41 ) ;
F_17 ( V_37 ) ;
if ( V_46 & V_47 ) {
F_23 ( V_48 & ~ V_47 , V_2 -> V_11 + V_30 ) ;
if ( V_38 ) {
if ( V_17 -> V_41 == V_17 -> V_43 ) {
V_17 -> V_41 = V_17 -> V_44 ;
V_17 -> V_42 = V_17 -> V_45 ;
} else {
V_17 -> V_41 = V_17 -> V_43 ;
V_17 -> V_42 = V_17 -> V_28 ;
}
}
}
return;
}
static int F_24 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
struct V_16 * V_17 = V_2 -> V_18 ;
F_23 ( 0x0 , V_2 -> V_11 + V_30 ) ;
F_23 ( 0x0 , V_2 -> V_11 + V_49 ) ;
F_23 ( 0x0 , V_2 -> V_11 + V_50 ) ;
if ( V_17 -> V_43 )
F_12 ( V_17 -> V_43 ) ;
if ( V_17 -> V_44 )
F_12 ( V_17 -> V_44 ) ;
return 0 ;
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = V_2 -> V_18 ;
struct V_14 * V_15 = & V_2 -> V_51 [ 0 ] ;
struct V_52 * V_22 = V_15 -> V_22 ;
struct V_20 * V_21 = & V_22 -> V_21 ;
unsigned int V_46 = F_4 ( V_2 -> V_11 + V_30 ) ;
V_22 -> V_53 = 0 ;
F_23 ( V_54 , V_2 -> V_11 + V_55 ) ;
if ( V_17 -> V_39 & V_56 ) {
F_18 ( V_2 , V_15 , V_46 ) ;
} else if ( V_46 & V_57 ) {
F_5 ( V_2 , V_15 ) ;
} else if ( V_46 & V_31 ) {
F_8 ( V_2 , V_15 ) ;
}
V_22 -> V_53 |= V_58 ;
if ( V_46 & V_59 ) {
F_23 ( V_48 & ~ V_59 , V_2 -> V_11 + V_30 ) ;
F_26 ( V_2 , L_1 ) ;
F_24 ( V_2 , V_15 ) ;
V_22 -> V_53 |= V_60 | V_61 ;
F_27 ( V_2 , V_15 ) ;
return;
}
if ( V_46 & V_62 ) {
F_23 ( V_48 & ~ V_62 , V_2 -> V_11 + V_30 ) ;
if ( V_17 -> V_39 & V_56 )
F_15 ( V_2 , V_15 ) ;
else
F_8 ( V_2 , V_15 ) ;
F_24 ( V_2 , V_15 ) ;
V_22 -> V_53 |= V_61 ;
} else if ( V_21 -> V_24 == V_25 && V_17 -> V_26 == 0 ) {
F_24 ( V_2 , V_15 ) ;
V_22 -> V_53 |= V_61 ;
}
F_27 ( V_2 , V_15 ) ;
return;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
unsigned long V_37 ;
F_29 ( & V_2 -> V_63 , V_37 ) ;
F_25 ( V_2 ) ;
F_30 ( & V_2 -> V_63 , V_37 ) ;
return V_15 -> V_22 -> V_64 - V_15 -> V_22 -> V_65 ;
}
static T_2 F_31 ( int V_66 , void * V_67 )
{
struct V_1 * V_2 = V_67 ;
unsigned int V_46 ;
if ( ! V_2 -> V_68 ) {
F_26 ( V_2 , L_2 ) ;
return V_69 ;
}
F_32 ( & V_2 -> V_63 ) ;
V_46 = F_4 ( V_2 -> V_11 + V_30 ) ;
if ( ! ( V_46 & INT ) ) {
F_33 ( & V_2 -> V_63 ) ;
return V_70 ;
}
F_23 ( V_48 & ~ INT , V_2 -> V_11 + V_30 ) ;
F_25 ( V_2 ) ;
F_33 ( & V_2 -> V_63 ) ;
return V_69 ;
}
static unsigned int F_34 ( unsigned int V_71 , int V_72 )
{
unsigned int V_73 ;
if ( V_71 > 64000 )
V_71 = 64000 ;
switch ( V_72 ) {
case V_74 :
default:
V_73 = ( V_71 + 500 ) / 1000 ;
break;
case V_75 :
V_73 = V_71 / 1000 ;
break;
case V_76 :
V_73 = ( V_71 - 1 ) / 1000 + 1 ;
break;
}
return V_73 * 1000 ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_20 * V_21 )
{
const struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_16 * V_17 = V_2 -> V_18 ;
int V_77 = 0 ;
unsigned int V_78 ;
int V_9 ;
int V_10 ;
V_77 |= F_36 ( & V_21 -> V_79 , V_80 | V_81 ) ;
V_77 |= F_36 ( & V_21 -> V_82 ,
V_83 | V_84 | V_81 ) ;
V_77 |= F_36 ( & V_21 -> V_85 , V_84 | V_81 ) ;
V_77 |= F_36 ( & V_21 -> V_86 , V_25 ) ;
V_77 |= F_36 ( & V_21 -> V_24 ,
V_25 | V_81 | V_87 ) ;
if ( V_77 )
return 1 ;
V_77 |= F_37 ( V_21 -> V_79 ) ;
V_77 |= F_37 ( V_21 -> V_82 ) ;
V_77 |= F_37 ( V_21 -> V_85 ) ;
V_77 |= F_37 ( V_21 -> V_24 ) ;
if ( V_21 -> V_82 != V_83 &&
V_21 -> V_85 != V_84 )
V_77 |= - V_88 ;
if ( V_77 )
return 2 ;
V_77 |= F_38 ( & V_21 -> V_89 , 0 ) ;
if ( V_21 -> V_85 == V_84 )
V_77 |= F_39 ( & V_21 -> V_71 ,
V_5 -> V_90 ) ;
V_77 |= F_39 ( & V_21 -> V_91 , 1 ) ;
V_77 |= F_38 ( & V_21 -> V_92 , V_21 -> V_91 ) ;
switch ( V_21 -> V_24 ) {
case V_25 :
V_77 |= F_39 ( & V_21 -> V_93 , 1 ) ;
break;
case V_87 :
V_77 |= F_38 ( & V_21 -> V_93 , 0 ) ;
break;
default:
break;
}
if ( V_77 )
return 3 ;
if ( V_21 -> V_85 == V_84 ) {
if ( V_21 -> V_82 == V_83 ) {
V_78 = V_21 -> V_71 ;
F_40 ( V_94 ,
& ( V_17 -> V_95 ) ,
& ( V_17 -> V_96 ) ,
& ( V_21 -> V_71 ) ,
V_21 ->
V_37 & V_97 ) ;
if ( V_78 != V_21 -> V_71 )
V_77 ++ ;
}
else {
V_78 = V_21 -> V_71 ;
V_21 -> V_71 =
F_34 ( V_21 -> V_71 ,
V_21 -> V_37 & V_97 ) ;
if ( V_78 != V_21 -> V_71 )
V_77 ++ ;
if ( V_21 -> V_82 == V_84 ) {
if ( V_21 -> V_71 * V_21 -> V_91 >
V_21 -> V_98 ) {
V_21 -> V_98 =
V_21 -> V_71 *
V_21 -> V_91 ;
V_77 ++ ;
}
V_78 = V_21 -> V_98 ;
F_40 ( V_94 ,
& ( V_17 ->
V_95 ) ,
& ( V_17 ->
V_96 ) ,
& ( V_21 ->
V_98 ) ,
V_21 ->
V_37 &
V_97 ) ;
if ( V_78 != V_21 -> V_98 )
V_77 ++ ;
}
}
}
if ( V_77 )
return 4 ;
if ( V_21 -> V_99 ) {
V_10 = F_41 ( V_21 -> V_99 [ 0 ] ) & V_100 ;
for ( V_9 = 1 ; V_9 < V_21 -> V_91 ; V_9 ++ ) {
if ( V_10 != ( F_41 ( V_21 -> V_99 [ V_9 ] ) & V_100 ) ) {
F_26 ( V_2 ,
L_3 ) ;
V_77 ++ ;
break;
}
}
}
if ( V_77 )
return 5 ;
return 0 ;
}
static int F_42 ( const struct V_20 * V_21 )
{
int V_101 ;
V_101 = V_102 ;
if ( V_21 -> V_24 == V_81 )
V_101 |= V_103 ;
switch ( V_21 -> V_79 ) {
case V_81 :
V_101 |= V_104 | V_105 ;
break;
case V_80 :
V_101 |= V_106 ;
break;
default:
break;
}
return V_101 ;
}
static int F_43 ( const struct V_20 * V_21 )
{
int V_107 ;
int V_108 ;
V_108 = F_44 ( V_21 -> V_99 [ 0 ] ) ;
V_107 = V_109 ;
if ( V_108 != V_110 )
V_107 |= V_111 ;
if ( V_108 == V_112 )
V_107 |= V_113 ;
if ( F_41 ( V_21 -> V_99 [ 0 ] ) & V_100 )
V_107 |= V_13 ;
switch ( V_21 -> V_82 ) {
case V_83 :
switch ( V_21 -> V_85 ) {
case V_84 :
V_107 |= V_114 ;
break;
case V_81 :
V_107 |= V_115 ;
break;
default:
break;
}
break;
case V_84 :
V_107 |= V_116 | V_114 ;
break;
case V_81 :
V_107 |= V_116 | V_115 ;
break;
default:
break;
}
return V_107 ;
}
static int F_45 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = V_2 -> V_18 ;
int V_77 = 0 ;
if ( F_46 ( V_2 -> V_11 + V_117 , 0 , 1 , V_17 -> V_95 ,
2 ) )
V_77 ++ ;
if ( F_46 ( V_2 -> V_11 + V_117 , 0 , 2 , V_17 -> V_96 ,
2 ) )
V_77 ++ ;
if ( V_77 )
return - 1 ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 ,
const struct V_20 * V_21 )
{
struct V_16 * V_17 = V_2 -> V_18 ;
unsigned int V_118 ;
switch ( V_21 -> V_82 ) {
case V_83 :
if ( V_21 -> V_85 == V_84 ) {
V_118 = V_21 -> V_71 ;
F_40 ( V_94 ,
& V_17 -> V_95 ,
& V_17 -> V_96 ,
& V_118 ,
V_21 -> V_37 &
V_97 ) ;
if ( F_45 ( V_2 ) < 0 )
return - 1 ;
}
break;
case V_84 :
V_118 = V_21 -> V_98 ;
F_40 ( V_94 , & V_17 -> V_95 ,
& V_17 -> V_96 , & V_118 ,
V_21 -> V_37 & V_97 ) ;
if ( F_45 ( V_2 ) < 0 )
return - 1 ;
break;
default:
break;
}
if ( V_21 -> V_24 == V_81 ) {
F_46 ( V_2 -> V_11 + V_117 , 0 , 0 , 1 , 0 ) ;
}
return 0 ;
}
static unsigned int F_48 ( const struct V_20 * V_21 )
{
unsigned int V_119 = V_120 ;
static const int V_121 = 2 ;
unsigned int V_122 = 300000000 ;
unsigned int V_123 ;
switch ( V_21 -> V_82 ) {
case V_83 :
if ( V_21 -> V_85 == V_84 )
V_119 = ( V_122 / V_21 -> V_71 ) * V_121 ;
break;
case V_84 :
V_119 = ( V_122 / ( V_21 -> V_98 * V_21 -> V_91 ) ) *
V_121 ;
break;
default:
V_119 = V_120 ;
break;
}
V_123 = V_120 ;
if ( V_21 -> V_24 == V_25 &&
V_21 -> V_93 * V_21 -> V_91 * V_121 < V_123 )
V_123 = V_21 -> V_93 * V_21 -> V_91 * V_121 ;
if ( V_119 > V_123 )
V_119 = V_123 ;
if ( V_119 < V_121 )
V_119 = V_121 ;
return V_119 ;
}
static void F_49 ( struct V_1 * V_2 , const struct V_20 * V_21 )
{
struct V_16 * V_17 = V_2 -> V_18 ;
unsigned long V_124 ;
const int V_38 = V_17 -> V_39 & V_40 ;
if ( ( V_17 -> V_39 & V_56 ) == 0 )
return;
V_17 -> V_36 = F_48 ( V_21 ) ;
V_124 = F_16 () ;
F_12 ( V_17 -> V_43 ) ;
F_13 ( V_17 -> V_43 ) ;
F_19 ( V_17 -> V_43 , F_20 ( V_17 -> V_28 ) ) ;
F_21 ( V_17 -> V_43 , V_17 -> V_36 ) ;
V_17 -> V_41 = V_17 -> V_43 ;
V_17 -> V_42 = V_17 -> V_28 ;
F_22 ( V_17 -> V_43 ) ;
if ( V_38 ) {
F_12 ( V_17 -> V_44 ) ;
F_13 ( V_17 -> V_44 ) ;
F_19 ( V_17 -> V_44 , F_20 ( V_17 -> V_45 ) ) ;
F_21 ( V_17 -> V_44 , V_17 -> V_36 ) ;
F_22 ( V_17 -> V_44 ) ;
}
F_17 ( V_124 ) ;
return;
}
static void F_50 ( struct V_1 * V_2 ,
const struct V_20 * V_21 )
{
int V_9 , V_125 , V_126 ;
unsigned long V_127 ;
const int V_128 = 0x3 ;
const int V_129 = 8 ;
V_125 = V_21 -> V_91 ;
F_29 ( & V_2 -> V_63 , V_127 ) ;
F_23 ( V_130 , V_2 -> V_11 + V_55 ) ;
F_23 ( V_125 - 1 , V_2 -> V_11 + V_131 ) ;
for ( V_9 = 0 ; V_9 < V_125 ; V_9 ++ ) {
V_126 =
F_51 ( V_21 -> V_99 [ V_9 ] ) |
( ( F_41 ( V_21 -> V_99 [ V_9 ] ) & V_128 ) <<
V_129 ) ;
F_52 ( V_126 , V_2 -> V_11 + V_132 ) ;
}
F_23 ( V_125 - 1 , V_2 -> V_11 + V_131 ) ;
F_30 ( & V_2 -> V_63 , V_127 ) ;
return;
}
static int F_53 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_16 * V_17 = V_2 -> V_18 ;
int V_133 ;
int V_101 , V_107 ;
struct V_52 * V_22 = V_15 -> V_22 ;
const struct V_20 * V_21 = & V_22 -> V_21 ;
if ( ! V_2 -> V_66 ) {
F_26 ( V_2 ,
L_4 ) ;
return - 1 ;
}
if ( V_21 -> V_37 & ( V_134 | V_135 ) )
V_17 -> V_39 &= ~ V_56 ;
else
V_17 -> V_39 |= V_17 -> V_136 ;
if ( V_21 -> V_37 & V_134 ) {
V_17 -> V_39 &= ~ V_137 ;
} else {
V_17 -> V_39 |= V_137 ;
}
if ( V_21 -> V_24 == V_25 )
V_17 -> V_26 = V_21 -> V_93 * V_21 -> V_91 ;
F_24 ( V_2 , V_15 ) ;
V_101 = F_42 ( V_21 ) ;
V_107 = F_43 ( V_21 ) ;
F_50 ( V_2 , V_21 ) ;
V_133 = F_47 ( V_2 , V_21 ) ;
if ( V_133 < 0 ) {
F_26 ( V_2 , L_5 ) ;
return V_133 ;
}
F_49 ( V_2 , V_21 ) ;
F_23 ( V_107 , V_2 -> V_11 + V_12 ) ;
if ( V_107 & V_116 ) {
F_23 ( V_21 -> V_71 / 1000 - 1 ,
V_2 -> V_11 + V_138 ) ;
F_23 ( V_21 -> V_91 - 1 , V_2 -> V_11 + V_139 ) ;
}
F_23 ( V_17 -> V_39 , V_2 -> V_11 + V_49 ) ;
F_23 ( V_101 , V_2 -> V_11 + V_50 ) ;
F_23 ( V_140 , V_2 -> V_11 + V_30 ) ;
return 0 ;
}
static int F_54 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_141 * V_142 , unsigned int * V_143 )
{
const struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_9 , V_125 ;
int V_144 , V_145 , V_108 , V_126 ;
int V_146 = 1000 ;
short V_29 ;
int V_147 = 0 ;
unsigned long V_127 ;
V_108 = F_44 ( V_142 -> V_148 ) ;
V_147 |= V_109 ;
if ( V_108 != V_110 )
V_147 |= V_111 ;
if ( V_108 == V_112 )
V_147 |= V_113 ;
if ( F_41 ( V_142 -> V_148 ) & V_100 )
V_147 |= V_13 ;
F_23 ( V_147 , V_2 -> V_11 + V_12 ) ;
F_23 ( V_140 , V_2 -> V_11 + V_30 ) ;
F_23 ( 0x0 , V_2 -> V_11 + V_50 ) ;
F_23 ( V_102 , V_2 -> V_11 + V_50 ) ;
V_144 = F_51 ( V_142 -> V_148 ) ;
V_145 = F_41 ( V_142 -> V_148 ) & 0x3 ;
V_126 = V_144 | ( V_145 << 8 ) ;
F_29 ( & V_2 -> V_63 , V_127 ) ;
F_23 ( V_130 , V_2 -> V_11 + V_55 ) ;
F_23 ( 0x0 , V_2 -> V_11 + V_131 ) ;
F_52 ( V_126 , V_2 -> V_11 + V_132 ) ;
F_23 ( 0x0 , V_2 -> V_11 + V_131 ) ;
F_23 ( V_54 , V_2 -> V_11 + V_55 ) ;
for ( V_125 = 0 ; V_125 < V_142 -> V_125 ; V_125 ++ ) {
F_23 ( 0 , V_2 -> V_11 + V_27 ) ;
for ( V_9 = 0 ; V_9 < V_146 ; V_9 ++ ) {
if ( F_4 ( V_2 -> V_11 + V_30 ) & V_31 )
break;
}
if ( V_9 == V_146 ) {
F_26 ( V_2 , L_6 ) ;
V_125 = - V_149 ;
goto exit;
}
V_29 = F_9 ( V_2 -> V_11 + V_27 ) ;
if ( ( V_147 & V_13 ) == 0 )
V_29 += 1 << ( V_5 -> V_6 - 1 ) ;
V_143 [ V_125 ] = V_29 ;
}
exit:
F_30 ( & V_2 -> V_63 , V_127 ) ;
return V_125 ;
}
static int F_55 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_141 * V_142 , unsigned int * V_143 )
{
const struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_16 * V_17 = V_2 -> V_18 ;
int V_144 = F_51 ( V_142 -> V_148 ) ;
int V_150 = V_5 -> V_151 - 1 ;
short V_152 ;
unsigned long V_127 ;
V_152 = V_143 [ 0 ] - ( 1 << ( V_5 -> V_6 - 1 ) ) ;
if ( V_144 == V_150 )
V_17 -> V_153 = V_152 ;
F_29 ( & V_2 -> V_63 , V_127 ) ;
F_23 ( F_56 ( V_144 ) , V_2 -> V_11 + V_55 ) ;
F_52 ( V_152 , V_2 -> V_11 + V_154 ) ;
if ( V_144 != V_150 ) {
F_23 ( F_56 ( V_150 ) , V_2 -> V_11 + V_55 ) ;
F_52 ( V_17 -> V_153 , V_2 -> V_11 + V_154 ) ;
}
F_30 ( & V_2 -> V_63 , V_127 ) ;
return 1 ;
}
static int F_57 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_141 * V_142 , unsigned int * V_143 )
{
V_143 [ 1 ] = F_4 ( V_2 -> V_11 + V_155 ) & 0xf ;
V_143 [ 0 ] = 0 ;
return V_142 -> V_125 ;
}
static int F_58 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_141 * V_142 , unsigned int * V_143 )
{
struct V_16 * V_17 = V_2 -> V_18 ;
unsigned int V_156 ;
V_143 [ 0 ] &= ( 1 << V_15 -> V_157 ) - 1 ;
V_156 = V_17 -> V_158 ;
V_156 &= ~ V_143 [ 0 ] ;
V_156 |= V_143 [ 0 ] & V_143 [ 1 ] ;
V_17 -> V_158 = V_156 ;
F_23 ( V_17 -> V_158 , V_2 -> V_11 + V_155 ) ;
V_143 [ 1 ] = V_17 -> V_158 ;
return V_142 -> V_125 ;
}
static int F_59 ( struct V_1 * V_2 , unsigned int V_43 ,
unsigned int V_44 )
{
struct V_16 * V_17 = V_2 -> V_18 ;
unsigned long V_37 ;
if ( V_2 -> V_66 && V_43 ) {
switch ( ( V_43 & 0x7 ) | ( V_44 << 4 ) ) {
case 0x5 :
V_17 -> V_136 |= V_159 ;
break;
case 0x6 :
V_17 -> V_136 |= V_160 ;
break;
case 0x7 :
V_17 -> V_136 |= V_161 ;
break;
case 0x65 :
V_17 -> V_136 |= V_162 ;
break;
case 0x76 :
V_17 -> V_136 |= V_163 ;
break;
case 0x57 :
V_17 -> V_136 |= V_164 ;
break;
default:
F_60 ( V_2 -> V_165 ,
L_7 ) ;
F_60 ( V_2 -> V_165 ,
L_8 ) ;
F_60 ( V_2 -> V_165 ,
L_9 ) ;
return - V_88 ;
break;
}
if ( F_61 ( V_43 , V_2 -> V_166 -> V_167 ) ) {
F_60 ( V_2 -> V_165 ,
L_10 , V_43 ) ;
return - V_88 ;
}
V_17 -> V_43 = V_43 ;
V_17 -> V_41 = V_43 ;
if ( V_44 ) {
if ( F_61 ( V_44 , V_2 -> V_166 -> V_167 ) ) {
F_60 ( V_2 -> V_165 ,
L_10 ,
V_44 ) ;
return - V_88 ;
}
V_17 -> V_44 = V_44 ;
}
V_17 -> V_28 = F_62 ( V_120 , V_168 | V_169 ) ;
if ( V_17 -> V_28 == NULL )
return - V_170 ;
V_17 -> V_42 = V_17 -> V_28 ;
if ( V_44 ) {
V_17 -> V_45 =
F_62 ( V_120 , V_168 | V_169 ) ;
if ( V_17 -> V_45 == NULL )
return - V_170 ;
}
V_37 = F_16 () ;
F_12 ( V_17 -> V_43 ) ;
F_63 ( V_17 -> V_43 , V_171 ) ;
if ( V_44 ) {
F_12 ( V_17 -> V_44 ) ;
F_63 ( V_17 -> V_44 , V_171 ) ;
}
F_17 ( V_37 ) ;
}
return 0 ;
}
static int F_64 ( struct V_1 * V_2 )
{
int V_172 ;
int V_173 ;
V_172 = ( F_4 ( V_2 -> V_11 + V_155 ) >> 4 ) & 0xf ;
V_173 = ( (struct V_4 * ) V_2 -> V_174 ) - V_175 ;
switch ( V_172 ) {
case 0x3 :
if ( V_173 == V_176 || V_173 == V_177 ||
V_173 == V_178 || V_173 == V_179 ) {
F_65 ( V_2 -> V_165 , L_11 ,
V_175 [ V_173 ] . V_180 ) ;
return V_173 ;
}
F_66
( L_12 ) ;
return V_181 ;
break;
case 0x4 :
if ( V_173 == V_182 || V_173 == V_183 ) {
F_65 ( V_2 -> V_165 , L_11 ,
V_175 [ V_173 ] . V_180 ) ;
return V_173 ;
}
F_66
( L_13 ) ;
return V_184 ;
break;
case 0x5 :
if ( V_173 == V_185 || V_173 == V_186 ||
V_173 == V_187 || V_173 == V_188 ) {
F_65 ( V_2 -> V_165 , L_11 ,
V_175 [ V_173 ] . V_180 ) ;
return V_173 ;
}
F_66
( L_14 ) ;
return V_185 ;
break;
case 0x6 :
if ( V_173 == V_184 || V_173 == V_189 ) {
F_65 ( V_2 -> V_165 , L_11 ,
V_175 [ V_173 ] . V_180 ) ;
return V_173 ;
}
F_66
( L_15 ) ;
return V_184 ;
break;
case 0x7 :
if ( V_173 == V_181 || V_173 == V_190 ||
V_173 == V_191 || V_173 == V_192 ) {
F_65 ( V_2 -> V_165 , L_11 ,
V_175 [ V_173 ] . V_180 ) ;
return V_173 ;
}
F_66
( L_16 ) ;
return V_181 ;
break;
case 0x8 :
if ( V_173 == V_193 || V_173 == V_194 ) {
F_65 ( V_2 -> V_165 , L_11 ,
V_175 [ V_173 ] . V_180 ) ;
return V_173 ;
}
F_66
( L_17 ) ;
return V_193 ;
break;
default:
F_66
( L_18 ,
V_172 ) ;
return V_173 ;
break;
}
return - 1 ;
}
static int F_67 ( struct V_1 * V_2 ,
struct V_195 * V_196 )
{
const struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_16 * V_17 ;
struct V_14 * V_15 ;
unsigned int V_66 = V_196 -> V_197 [ 1 ] ;
unsigned int V_43 = V_196 -> V_197 [ 2 ] ;
unsigned int V_44 = V_196 -> V_197 [ 3 ] ;
int V_173 ;
int V_133 ;
V_17 = F_68 ( V_2 , sizeof( * V_17 ) ) ;
if ( ! V_17 )
return - V_170 ;
V_133 = F_69 ( V_2 , V_196 -> V_197 [ 0 ] , V_198 ) ;
if ( V_133 )
return V_133 ;
V_173 = F_64 ( V_2 ) ;
if ( V_173 < 0 ) {
F_60 ( V_2 -> V_165 , L_19 ) ;
return - V_199 ;
}
V_2 -> V_174 = V_175 + V_173 ;
V_5 = F_2 ( V_2 ) ;
V_2 -> V_200 = V_5 -> V_180 ;
if ( V_5 -> V_201 == 2 ) {
unsigned long V_202 = V_2 -> V_11 + V_203 ;
V_133 = F_70 ( V_2 , V_202 , V_198 ) ;
if ( V_133 )
return V_133 ;
V_17 -> V_202 = V_202 ;
}
if ( V_66 ) {
if ( F_71 ( V_66 , F_31 , 0 ,
V_2 -> V_166 -> V_167 , V_2 ) ) {
F_65 ( V_2 -> V_165 , L_20 ,
V_66 ) ;
return - V_88 ;
}
}
V_2 -> V_66 = V_66 ;
switch ( V_66 ) {
case 0 :
break;
case 3 :
V_17 -> V_39 |= 0x8 ;
break;
case 5 :
V_17 -> V_39 |= 0x10 ;
break;
case 7 :
V_17 -> V_39 |= 0x18 ;
break;
case 10 :
V_17 -> V_39 |= 0x28 ;
break;
case 11 :
V_17 -> V_39 |= 0x30 ;
break;
case 15 :
V_17 -> V_39 |= 0x38 ;
break;
default:
F_60 ( V_2 -> V_165 , L_21 ) ;
return - V_88 ;
break;
}
V_133 = F_59 ( V_2 , V_43 , V_44 ) ;
if ( V_133 < 0 )
return V_133 ;
if ( V_17 -> V_28 == NULL ) {
V_17 -> V_28 =
F_62 ( V_23 * sizeof( T_1 ) , V_168 ) ;
if ( V_17 -> V_28 == NULL )
return - V_170 ;
}
V_133 = F_72 ( V_2 , 4 ) ;
if ( V_133 )
return V_133 ;
V_15 = & V_2 -> V_51 [ 0 ] ;
V_2 -> V_204 = V_15 ;
V_15 -> type = V_205 ;
V_15 -> V_206 = V_207 | V_208 | V_209 | V_210 ;
if ( V_5 -> V_211 )
V_15 -> V_206 |= V_212 ;
V_15 -> V_157 = V_5 -> V_213 ;
V_15 -> V_214 = V_5 -> V_213 ;
V_15 -> V_215 = ( 1 << V_5 -> V_6 ) - 1 ;
V_15 -> V_216 = V_5 -> V_217 ;
V_15 -> V_218 = F_53 ;
V_15 -> V_219 = F_35 ;
V_15 -> V_220 = F_54 ;
V_15 -> V_221 = F_28 ;
V_15 -> V_222 = F_24 ;
V_15 = & V_2 -> V_51 [ 1 ] ;
if ( V_5 -> V_201 == 1 ) {
V_15 -> type = V_223 ;
V_15 -> V_206 = V_224 ;
V_15 -> V_157 = V_5 -> V_151 ;
V_15 -> V_215 = ( 1 << V_5 -> V_6 ) - 1 ;
V_15 -> V_216 = & V_225 ;
V_15 -> V_226 = F_55 ;
} else {
V_15 -> type = V_227 ;
}
V_15 = & V_2 -> V_51 [ 2 ] ;
V_15 -> type = V_228 ;
V_15 -> V_206 = V_207 ;
V_15 -> V_157 = 4 ;
V_15 -> V_215 = 1 ;
V_15 -> V_216 = & V_229 ;
V_15 -> V_230 = F_57 ;
V_15 = & V_2 -> V_51 [ 3 ] ;
V_15 -> type = V_231 ;
V_15 -> V_206 = V_224 | V_207 ;
V_15 -> V_157 = V_5 -> V_232 ;
V_15 -> V_215 = 1 ;
V_15 -> V_216 = & V_229 ;
V_15 -> V_230 = F_58 ;
F_24 ( V_2 , V_2 -> V_204 ) ;
F_23 ( V_17 -> V_158 , V_2 -> V_11 + V_155 ) ;
if ( V_5 -> V_201 == 1 ) {
F_23 ( F_56 ( V_5 -> V_151 - 1 ) ,
V_2 -> V_11 + V_55 ) ;
F_52 ( V_17 -> V_153 , V_2 -> V_11 + V_154 ) ;
}
return 0 ;
}
static void F_73 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = V_2 -> V_18 ;
if ( V_17 ) {
if ( V_17 -> V_43 )
F_74 ( V_17 -> V_43 ) ;
if ( V_17 -> V_44 )
F_74 ( V_17 -> V_44 ) ;
F_75 ( V_17 -> V_28 ) ;
F_75 ( V_17 -> V_45 ) ;
if ( V_17 -> V_202 )
F_76 ( V_17 -> V_202 , V_198 ) ;
}
F_77 ( V_2 ) ;
}
