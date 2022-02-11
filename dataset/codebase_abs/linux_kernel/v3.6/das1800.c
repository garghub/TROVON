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
int V_15 = 0 ;
struct V_16 * V_17 = & V_14 -> V_18 -> V_17 ;
V_15 = V_19 / 2 ;
if ( V_17 -> V_20 == V_21 && V_22 -> V_23 < V_15 )
V_15 = V_22 -> V_23 ;
F_5 ( V_2 -> V_10 + V_24 , V_22 -> V_25 , V_15 ) ;
F_2 ( V_2 , V_22 -> V_25 , V_15 ) ;
F_6 ( V_14 , V_22 -> V_25 ,
V_15 * sizeof( V_22 -> V_25 [ 0 ] ) ) ;
if ( V_17 -> V_20 == V_21 )
V_22 -> V_23 -= V_15 ;
return;
}
static void F_7 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
short V_26 ;
int V_9 ;
struct V_16 * V_17 = & V_14 -> V_18 -> V_17 ;
V_9 = F_3 ( V_2 -> V_10 + V_11 ) & V_12 ;
while ( F_3 ( V_2 -> V_10 + V_27 ) & V_28 ) {
if ( V_17 -> V_20 == V_21 && V_22 -> V_23 == 0 )
break;
V_26 = F_8 ( V_2 -> V_10 + V_24 ) ;
if ( ! V_9 )
;
V_26 = F_1 ( V_2 , V_26 ) ;
F_9 ( V_14 , V_26 ) ;
if ( V_17 -> V_20 == V_21 )
V_22 -> V_23 -- ;
}
return;
}
static void F_10 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
unsigned int V_29 , T_1 * V_30 )
{
unsigned int V_31 , V_32 ;
struct V_16 * V_17 = & V_14 -> V_18 -> V_17 ;
F_11 ( V_29 ) ;
F_12 ( V_29 ) ;
V_31 = V_22 -> V_33 - F_13 ( V_29 ) ;
V_32 = V_31 / sizeof( short ) ;
if ( V_17 -> V_20 == V_21 && V_22 -> V_23 < V_32 )
V_32 = V_22 -> V_23 ;
F_2 ( V_2 , V_30 , V_32 ) ;
F_6 ( V_14 , V_30 , V_31 ) ;
if ( V_14 -> V_18 -> V_17 . V_20 == V_21 )
V_22 -> V_23 -= V_32 ;
return;
}
static void F_14 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
unsigned long V_34 ;
const int V_35 = V_22 -> V_36 & V_37 ;
V_34 = F_15 () ;
F_10 ( V_2 , V_14 , V_22 -> V_38 ,
V_22 -> V_39 ) ;
if ( V_35 ) {
if ( V_22 -> V_38 == V_22 -> V_40 ) {
V_22 -> V_38 = V_22 -> V_41 ;
V_22 -> V_39 = V_22 -> V_42 ;
} else {
V_22 -> V_38 = V_22 -> V_40 ;
V_22 -> V_39 = V_22 -> V_25 ;
}
F_10 ( V_2 , V_14 , V_22 -> V_38 ,
V_22 -> V_39 ) ;
}
F_16 ( V_34 ) ;
F_7 ( V_2 , V_14 ) ;
return;
}
static void F_17 ( struct V_1 * V_2 ,
struct V_13 * V_14 , unsigned int V_43 )
{
unsigned long V_34 ;
const int V_35 = V_22 -> V_36 & V_37 ;
V_34 = F_15 () ;
F_10 ( V_2 , V_14 , V_22 -> V_38 ,
V_22 -> V_39 ) ;
F_18 ( V_22 -> V_38 ,
F_19 ( V_22 -> V_39 ) ) ;
F_20 ( V_22 -> V_38 , V_22 -> V_33 ) ;
F_21 ( V_22 -> V_38 ) ;
F_16 ( V_34 ) ;
if ( V_43 & V_44 ) {
F_22 ( V_45 & ~ V_44 , V_2 -> V_10 + V_27 ) ;
if ( V_35 ) {
if ( V_22 -> V_38 == V_22 -> V_40 ) {
V_22 -> V_38 = V_22 -> V_41 ;
V_22 -> V_39 = V_22 -> V_42 ;
} else {
V_22 -> V_38 = V_22 -> V_40 ;
V_22 -> V_39 = V_22 -> V_25 ;
}
}
}
return;
}
static int F_23 ( struct V_1 * V_2 , struct V_13 * V_14 )
{
F_22 ( 0x0 , V_2 -> V_10 + V_27 ) ;
F_22 ( 0x0 , V_2 -> V_10 + V_46 ) ;
F_22 ( 0x0 , V_2 -> V_10 + V_47 ) ;
if ( V_22 -> V_40 )
F_11 ( V_22 -> V_40 ) ;
if ( V_22 -> V_41 )
F_11 ( V_22 -> V_41 ) ;
return 0 ;
}
static void F_24 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_48 + 0 ;
struct V_49 * V_18 = V_14 -> V_18 ;
struct V_16 * V_17 = & V_18 -> V_17 ;
unsigned int V_43 = F_3 ( V_2 -> V_10 + V_27 ) ;
V_18 -> V_50 = 0 ;
F_22 ( V_51 , V_2 -> V_10 + V_52 ) ;
if ( V_22 -> V_36 & V_53 ) {
F_17 ( V_2 , V_14 , V_43 ) ;
} else if ( V_43 & V_54 ) {
F_4 ( V_2 , V_14 ) ;
} else if ( V_43 & V_28 ) {
F_7 ( V_2 , V_14 ) ;
}
V_18 -> V_50 |= V_55 ;
if ( V_43 & V_56 ) {
F_22 ( V_45 & ~ V_56 , V_2 -> V_10 + V_27 ) ;
F_25 ( V_2 , L_1 ) ;
F_23 ( V_2 , V_14 ) ;
V_18 -> V_50 |= V_57 | V_58 ;
F_26 ( V_2 , V_14 ) ;
return;
}
if ( V_43 & V_59 ) {
F_22 ( V_45 & ~ V_59 , V_2 -> V_10 + V_27 ) ;
if ( V_22 -> V_36 & V_53 )
F_14 ( V_2 , V_14 ) ;
else
F_7 ( V_2 , V_14 ) ;
F_23 ( V_2 , V_14 ) ;
V_18 -> V_50 |= V_58 ;
} else if ( V_17 -> V_20 == V_21 && V_22 -> V_23 == 0 ) {
F_23 ( V_2 , V_14 ) ;
V_18 -> V_50 |= V_58 ;
}
F_26 ( V_2 , V_14 ) ;
return;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
unsigned long V_34 ;
F_28 ( & V_2 -> V_60 , V_34 ) ;
F_24 ( V_2 ) ;
F_29 ( & V_2 -> V_60 , V_34 ) ;
return V_14 -> V_18 -> V_61 - V_14 -> V_18 -> V_62 ;
}
static T_2 F_30 ( int V_63 , void * V_64 )
{
struct V_1 * V_2 = V_64 ;
unsigned int V_43 ;
if ( V_2 -> V_65 == 0 ) {
F_25 ( V_2 , L_2 ) ;
return V_66 ;
}
F_31 ( & V_2 -> V_60 ) ;
V_43 = F_3 ( V_2 -> V_10 + V_27 ) ;
if ( ! ( V_43 & INT ) ) {
F_32 ( & V_2 -> V_60 ) ;
return V_67 ;
}
F_22 ( V_45 & ~ INT , V_2 -> V_10 + V_27 ) ;
F_24 ( V_2 ) ;
F_32 ( & V_2 -> V_60 ) ;
return V_66 ;
}
static unsigned int F_33 ( unsigned int V_68 , int V_69 )
{
unsigned int V_70 ;
if ( V_68 > 64000 )
V_68 = 64000 ;
switch ( V_69 ) {
case V_71 :
default:
V_70 = ( V_68 + 500 ) / 1000 ;
break;
case V_72 :
V_70 = V_68 / 1000 ;
break;
case V_73 :
V_70 = ( V_68 - 1 ) / 1000 + 1 ;
break;
}
return V_70 * 1000 ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
struct V_16 * V_17 )
{
int V_74 = 0 ;
int V_75 ;
unsigned int V_76 ;
int V_8 ;
int V_9 ;
V_75 = V_17 -> V_77 ;
V_17 -> V_77 &= V_78 | V_79 ;
if ( ! V_17 -> V_77 || V_75 != V_17 -> V_77 )
V_74 ++ ;
V_75 = V_17 -> V_80 ;
V_17 -> V_80 &= V_81 | V_82 | V_79 ;
if ( ! V_17 -> V_80 || V_75 != V_17 -> V_80 )
V_74 ++ ;
V_75 = V_17 -> V_83 ;
V_17 -> V_83 &= V_82 | V_79 ;
if ( ! V_17 -> V_83 || V_75 != V_17 -> V_83 )
V_74 ++ ;
V_75 = V_17 -> V_84 ;
V_17 -> V_84 &= V_21 ;
if ( ! V_17 -> V_84 || V_75 != V_17 -> V_84 )
V_74 ++ ;
V_75 = V_17 -> V_20 ;
V_17 -> V_20 &= V_21 | V_79 | V_85 ;
if ( ! V_17 -> V_20 || V_75 != V_17 -> V_20 )
V_74 ++ ;
if ( V_74 )
return 1 ;
if ( V_17 -> V_77 != V_78 && V_17 -> V_77 != V_79 )
V_74 ++ ;
if ( V_17 -> V_80 != V_81 &&
V_17 -> V_80 != V_82 &&
V_17 -> V_80 != V_79 )
V_74 ++ ;
if ( V_17 -> V_83 != V_82 && V_17 -> V_83 != V_79 )
V_74 ++ ;
if ( V_17 -> V_20 != V_21 &&
V_17 -> V_20 != V_85 && V_17 -> V_20 != V_79 )
V_74 ++ ;
if ( V_17 -> V_80 != V_81 &&
V_17 -> V_83 != V_82 )
V_74 ++ ;
if ( V_74 )
return 2 ;
if ( V_17 -> V_86 != 0 ) {
V_17 -> V_86 = 0 ;
V_74 ++ ;
}
if ( V_17 -> V_83 == V_82 ) {
if ( V_17 -> V_68 < V_4 -> V_87 ) {
V_17 -> V_68 = V_4 -> V_87 ;
V_74 ++ ;
}
}
if ( ! V_17 -> V_88 ) {
V_17 -> V_88 = 1 ;
V_74 ++ ;
}
if ( V_17 -> V_89 != V_17 -> V_88 ) {
V_17 -> V_89 = V_17 -> V_88 ;
V_74 ++ ;
}
switch ( V_17 -> V_20 ) {
case V_21 :
if ( ! V_17 -> V_90 ) {
V_17 -> V_90 = 1 ;
V_74 ++ ;
}
break;
case V_85 :
if ( V_17 -> V_90 != 0 ) {
V_17 -> V_90 = 0 ;
V_74 ++ ;
}
break;
default:
break;
}
if ( V_74 )
return 3 ;
if ( V_17 -> V_83 == V_82 ) {
if ( V_17 -> V_80 == V_81 ) {
V_76 = V_17 -> V_68 ;
F_35 ( V_91 ,
& ( V_22 -> V_92 ) ,
& ( V_22 -> V_93 ) ,
& ( V_17 -> V_68 ) ,
V_17 ->
V_34 & V_94 ) ;
if ( V_76 != V_17 -> V_68 )
V_74 ++ ;
}
else {
V_76 = V_17 -> V_68 ;
V_17 -> V_68 =
F_33 ( V_17 -> V_68 ,
V_17 -> V_34 & V_94 ) ;
if ( V_76 != V_17 -> V_68 )
V_74 ++ ;
if ( V_17 -> V_80 == V_82 ) {
if ( V_17 -> V_68 * V_17 -> V_88 >
V_17 -> V_95 ) {
V_17 -> V_95 =
V_17 -> V_68 *
V_17 -> V_88 ;
V_74 ++ ;
}
V_76 = V_17 -> V_95 ;
F_35 ( V_91 ,
& ( V_22 ->
V_92 ) ,
& ( V_22 ->
V_93 ) ,
& ( V_17 ->
V_95 ) ,
V_17 ->
V_34 &
V_94 ) ;
if ( V_76 != V_17 -> V_95 )
V_74 ++ ;
}
}
}
if ( V_74 )
return 4 ;
if ( V_17 -> V_96 ) {
V_9 = F_36 ( V_17 -> V_96 [ 0 ] ) & V_97 ;
for ( V_8 = 1 ; V_8 < V_17 -> V_88 ; V_8 ++ ) {
if ( V_9 != ( F_36 ( V_17 -> V_96 [ V_8 ] ) & V_97 ) ) {
F_25 ( V_2 ,
L_3 ) ;
V_74 ++ ;
break;
}
}
}
if ( V_74 )
return 5 ;
return 0 ;
}
static int F_37 ( struct V_16 V_17 )
{
int V_98 ;
V_98 = V_99 ;
if ( V_17 . V_20 == V_79 )
V_98 |= V_100 ;
switch ( V_17 . V_77 ) {
case V_79 :
V_98 |= V_101 | V_102 ;
break;
case V_78 :
V_98 |= V_103 ;
break;
default:
break;
}
return V_98 ;
}
static int F_38 ( struct V_16 V_17 )
{
int V_104 ;
int V_105 ;
V_105 = F_39 ( V_17 . V_96 [ 0 ] ) ;
V_104 = V_106 ;
if ( V_105 != V_107 )
V_104 |= V_108 ;
if ( V_105 == V_109 )
V_104 |= V_110 ;
if ( F_36 ( V_17 . V_96 [ 0 ] ) & V_97 )
V_104 |= V_12 ;
switch ( V_17 . V_80 ) {
case V_81 :
switch ( V_17 . V_83 ) {
case V_82 :
V_104 |= V_111 ;
break;
case V_79 :
V_104 |= V_112 ;
break;
default:
break;
}
break;
case V_82 :
V_104 |= V_113 | V_111 ;
break;
case V_79 :
V_104 |= V_113 | V_112 ;
break;
default:
break;
}
return V_104 ;
}
static int F_40 ( struct V_1 * V_2 )
{
int V_74 = 0 ;
if ( F_41 ( V_2 -> V_10 + V_114 , 0 , 1 , V_22 -> V_92 ,
2 ) )
V_74 ++ ;
if ( F_41 ( V_2 -> V_10 + V_114 , 0 , 2 , V_22 -> V_93 ,
2 ) )
V_74 ++ ;
if ( V_74 )
return - 1 ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 , struct V_16 V_17 )
{
switch ( V_17 . V_80 ) {
case V_81 :
if ( V_17 . V_83 == V_82 ) {
F_35 ( V_91 ,
& ( V_22 -> V_92 ) ,
& ( V_22 -> V_93 ) ,
& ( V_17 . V_68 ) ,
V_17 .
V_34 & V_94 ) ;
if ( F_40 ( V_2 ) < 0 )
return - 1 ;
}
break;
case V_82 :
F_35 ( V_91 , & ( V_22 -> V_92 ) ,
& ( V_22 -> V_93 ) ,
& ( V_17 . V_95 ) ,
V_17 . V_34 & V_94 ) ;
if ( F_40 ( V_2 ) < 0 )
return - 1 ;
break;
default:
break;
}
if ( V_17 . V_20 == V_79 ) {
F_41 ( V_2 -> V_10 + V_114 , 0 , 0 , 1 , 0 ) ;
}
return 0 ;
}
static unsigned int F_43 ( struct V_16 * V_17 )
{
unsigned int V_115 = V_116 ;
static const int V_117 = 2 ;
unsigned int V_118 = 300000000 ;
unsigned int V_119 ;
switch ( V_17 -> V_80 ) {
case V_81 :
if ( V_17 -> V_83 == V_82 )
V_115 = ( V_118 / V_17 -> V_68 ) * V_117 ;
break;
case V_82 :
V_115 = ( V_118 / ( V_17 -> V_95 * V_17 -> V_88 ) ) *
V_117 ;
break;
default:
V_115 = V_116 ;
break;
}
V_119 = V_116 ;
if ( V_17 -> V_20 == V_21 &&
V_17 -> V_90 * V_17 -> V_88 * V_117 < V_119 )
V_119 = V_17 -> V_90 * V_17 -> V_88 * V_117 ;
if ( V_115 > V_119 )
V_115 = V_119 ;
if ( V_115 < V_117 )
V_115 = V_117 ;
return V_115 ;
}
static void F_44 ( struct V_1 * V_2 , struct V_16 V_17 )
{
unsigned long V_120 ;
const int V_35 = V_22 -> V_36 & V_37 ;
if ( ( V_22 -> V_36 & V_53 ) == 0 )
return;
V_22 -> V_33 = F_43 ( & V_17 ) ;
V_120 = F_15 () ;
F_11 ( V_22 -> V_40 ) ;
F_12 ( V_22 -> V_40 ) ;
F_18 ( V_22 -> V_40 , F_19 ( V_22 -> V_25 ) ) ;
F_20 ( V_22 -> V_40 , V_22 -> V_33 ) ;
V_22 -> V_38 = V_22 -> V_40 ;
V_22 -> V_39 = V_22 -> V_25 ;
F_21 ( V_22 -> V_40 ) ;
if ( V_35 ) {
F_11 ( V_22 -> V_41 ) ;
F_12 ( V_22 -> V_41 ) ;
F_18 ( V_22 -> V_41 , F_19 ( V_22 -> V_42 ) ) ;
F_20 ( V_22 -> V_41 , V_22 -> V_33 ) ;
F_21 ( V_22 -> V_41 ) ;
}
F_16 ( V_120 ) ;
return;
}
static void F_45 ( struct V_1 * V_2 , struct V_16 V_17 )
{
int V_8 , V_121 , V_122 ;
unsigned long V_123 ;
const int V_124 = 0x3 ;
const int V_125 = 8 ;
V_121 = V_17 . V_88 ;
F_28 ( & V_2 -> V_60 , V_123 ) ;
F_22 ( V_126 , V_2 -> V_10 + V_52 ) ;
F_22 ( V_121 - 1 , V_2 -> V_10 + V_127 ) ;
for ( V_8 = 0 ; V_8 < V_121 ; V_8 ++ ) {
V_122 =
F_46 ( V_17 .
V_96 [ V_8 ] ) | ( ( F_36 ( V_17 . V_96 [ V_8 ] ) &
V_124 ) << V_125 ) ;
F_47 ( V_122 , V_2 -> V_10 + V_128 ) ;
}
F_22 ( V_121 - 1 , V_2 -> V_10 + V_127 ) ;
F_29 ( & V_2 -> V_60 , V_123 ) ;
return;
}
static int F_48 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
int V_129 ;
int V_98 , V_104 ;
struct V_49 * V_18 = V_14 -> V_18 ;
struct V_16 V_17 = V_18 -> V_17 ;
if ( ! V_2 -> V_63 ) {
F_25 ( V_2 ,
L_4 ) ;
return - 1 ;
}
if ( V_17 . V_34 & ( V_130 | V_131 ) )
V_22 -> V_36 &= ~ V_53 ;
else
V_22 -> V_36 |= V_22 -> V_132 ;
if ( V_17 . V_34 & V_130 ) {
V_22 -> V_36 &= ~ V_133 ;
} else {
V_22 -> V_36 |= V_133 ;
}
if ( V_17 . V_20 == V_21 )
V_22 -> V_23 = V_17 . V_90 * V_17 . V_88 ;
F_23 ( V_2 , V_14 ) ;
V_98 = F_37 ( V_17 ) ;
V_104 = F_38 ( V_17 ) ;
F_45 ( V_2 , V_17 ) ;
V_129 = F_42 ( V_2 , V_17 ) ;
if ( V_129 < 0 ) {
F_25 ( V_2 , L_5 ) ;
return V_129 ;
}
F_44 ( V_2 , V_17 ) ;
F_22 ( V_104 , V_2 -> V_10 + V_11 ) ;
if ( V_104 & V_113 ) {
F_22 ( V_17 . V_68 / 1000 - 1 ,
V_2 -> V_10 + V_134 ) ;
F_22 ( V_17 . V_88 - 1 , V_2 -> V_10 + V_135 ) ;
}
F_22 ( V_22 -> V_36 , V_2 -> V_10 + V_46 ) ;
F_22 ( V_98 , V_2 -> V_10 + V_47 ) ;
F_22 ( V_136 , V_2 -> V_10 + V_27 ) ;
return 0 ;
}
static int F_49 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
struct V_137 * V_138 , unsigned int * V_139 )
{
int V_8 , V_121 ;
int V_140 , V_141 , V_105 , V_122 ;
int V_142 = 1000 ;
short V_26 ;
int V_143 = 0 ;
unsigned long V_123 ;
V_105 = F_39 ( V_138 -> V_144 ) ;
V_143 |= V_106 ;
if ( V_105 != V_107 )
V_143 |= V_108 ;
if ( V_105 == V_109 )
V_143 |= V_110 ;
if ( F_36 ( V_138 -> V_144 ) & V_97 )
V_143 |= V_12 ;
F_22 ( V_143 , V_2 -> V_10 + V_11 ) ;
F_22 ( V_136 , V_2 -> V_10 + V_27 ) ;
F_22 ( 0x0 , V_2 -> V_10 + V_47 ) ;
F_22 ( V_99 , V_2 -> V_10 + V_47 ) ;
V_140 = F_46 ( V_138 -> V_144 ) ;
V_141 = F_36 ( V_138 -> V_144 ) & 0x3 ;
V_122 = V_140 | ( V_141 << 8 ) ;
F_28 ( & V_2 -> V_60 , V_123 ) ;
F_22 ( V_126 , V_2 -> V_10 + V_52 ) ;
F_22 ( 0x0 , V_2 -> V_10 + V_127 ) ;
F_47 ( V_122 , V_2 -> V_10 + V_128 ) ;
F_22 ( 0x0 , V_2 -> V_10 + V_127 ) ;
F_22 ( V_51 , V_2 -> V_10 + V_52 ) ;
for ( V_121 = 0 ; V_121 < V_138 -> V_121 ; V_121 ++ ) {
F_22 ( 0 , V_2 -> V_10 + V_24 ) ;
for ( V_8 = 0 ; V_8 < V_142 ; V_8 ++ ) {
if ( F_3 ( V_2 -> V_10 + V_27 ) & V_28 )
break;
}
if ( V_8 == V_142 ) {
F_25 ( V_2 , L_6 ) ;
V_121 = - V_145 ;
goto exit;
}
V_26 = F_8 ( V_2 -> V_10 + V_24 ) ;
if ( ( V_143 & V_12 ) == 0 )
V_26 += 1 << ( V_4 -> V_5 - 1 ) ;
V_139 [ V_121 ] = V_26 ;
}
exit:
F_29 ( & V_2 -> V_60 , V_123 ) ;
return V_121 ;
}
static int F_50 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
struct V_137 * V_138 , unsigned int * V_139 )
{
int V_140 = F_46 ( V_138 -> V_144 ) ;
int V_146 = V_4 -> V_147 - 1 ;
short V_148 ;
unsigned long V_123 ;
V_148 = V_139 [ 0 ] - ( 1 << ( V_4 -> V_5 - 1 ) ) ;
if ( V_140 == V_146 )
V_22 -> V_149 = V_148 ;
F_28 ( & V_2 -> V_60 , V_123 ) ;
F_22 ( F_51 ( V_140 ) , V_2 -> V_10 + V_52 ) ;
F_47 ( V_148 , V_2 -> V_10 + V_150 ) ;
if ( V_140 != V_146 ) {
F_22 ( F_51 ( V_146 ) , V_2 -> V_10 + V_52 ) ;
F_47 ( V_22 -> V_149 , V_2 -> V_10 + V_150 ) ;
}
F_29 ( & V_2 -> V_60 , V_123 ) ;
return 1 ;
}
static int F_52 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
struct V_137 * V_138 , unsigned int * V_139 )
{
V_139 [ 1 ] = F_3 ( V_2 -> V_10 + V_151 ) & 0xf ;
V_139 [ 0 ] = 0 ;
return V_138 -> V_121 ;
}
static int F_53 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
struct V_137 * V_138 , unsigned int * V_139 )
{
unsigned int V_152 ;
V_139 [ 0 ] &= ( 1 << V_14 -> V_153 ) - 1 ;
V_152 = V_22 -> V_154 ;
V_152 &= ~ V_139 [ 0 ] ;
V_152 |= V_139 [ 0 ] & V_139 [ 1 ] ;
V_22 -> V_154 = V_152 ;
F_22 ( V_22 -> V_154 , V_2 -> V_10 + V_151 ) ;
V_139 [ 1 ] = V_22 -> V_154 ;
return V_138 -> V_121 ;
}
static int F_54 ( struct V_1 * V_2 , unsigned int V_40 ,
unsigned int V_41 )
{
unsigned long V_34 ;
if ( V_2 -> V_63 && V_40 ) {
switch ( ( V_40 & 0x7 ) | ( V_41 << 4 ) ) {
case 0x5 :
V_22 -> V_132 |= V_155 ;
break;
case 0x6 :
V_22 -> V_132 |= V_156 ;
break;
case 0x7 :
V_22 -> V_132 |= V_157 ;
break;
case 0x65 :
V_22 -> V_132 |= V_158 ;
break;
case 0x76 :
V_22 -> V_132 |= V_159 ;
break;
case 0x57 :
V_22 -> V_132 |= V_160 ;
break;
default:
F_55 ( V_2 -> V_161 ,
L_7 ) ;
F_55 ( V_2 -> V_161 ,
L_8 ) ;
F_55 ( V_2 -> V_161 ,
L_9 ) ;
return - V_162 ;
break;
}
if ( F_56 ( V_40 , V_2 -> V_163 -> V_164 ) ) {
F_55 ( V_2 -> V_161 ,
L_10 , V_40 ) ;
return - V_162 ;
}
V_22 -> V_40 = V_40 ;
V_22 -> V_38 = V_40 ;
if ( V_41 ) {
if ( F_56 ( V_41 , V_2 -> V_163 -> V_164 ) ) {
F_55 ( V_2 -> V_161 ,
L_10 ,
V_41 ) ;
return - V_162 ;
}
V_22 -> V_41 = V_41 ;
}
V_22 -> V_25 = F_57 ( V_116 , V_165 | V_166 ) ;
if ( V_22 -> V_25 == NULL )
return - V_167 ;
V_22 -> V_39 = V_22 -> V_25 ;
if ( V_41 ) {
V_22 -> V_42 =
F_57 ( V_116 , V_165 | V_166 ) ;
if ( V_22 -> V_42 == NULL )
return - V_167 ;
}
V_34 = F_15 () ;
F_11 ( V_22 -> V_40 ) ;
F_58 ( V_22 -> V_40 , V_168 ) ;
if ( V_41 ) {
F_11 ( V_22 -> V_41 ) ;
F_58 ( V_22 -> V_41 , V_168 ) ;
}
F_16 ( V_34 ) ;
}
return 0 ;
}
static int F_59 ( struct V_1 * V_2 )
{
int V_169 ;
int V_170 ;
V_169 = ( F_3 ( V_2 -> V_10 + V_151 ) >> 4 ) & 0xf ;
V_170 = ( (struct V_171 * ) V_2 -> V_172 ) - V_173 ;
switch ( V_169 ) {
case 0x3 :
if ( V_170 == V_174 || V_170 == V_175 ||
V_170 == V_176 || V_170 == V_177 ) {
F_60 ( V_2 -> V_161 , L_11 ,
V_173 [ V_170 ] . V_178 ) ;
return V_170 ;
}
F_61
( L_12 ) ;
return V_179 ;
break;
case 0x4 :
if ( V_170 == V_180 || V_170 == V_181 ) {
F_60 ( V_2 -> V_161 , L_11 ,
V_173 [ V_170 ] . V_178 ) ;
return V_170 ;
}
F_61
( L_13 ) ;
return V_182 ;
break;
case 0x5 :
if ( V_170 == V_183 || V_170 == V_184 ||
V_170 == V_185 || V_170 == V_186 ) {
F_60 ( V_2 -> V_161 , L_11 ,
V_173 [ V_170 ] . V_178 ) ;
return V_170 ;
}
F_61
( L_14 ) ;
return V_183 ;
break;
case 0x6 :
if ( V_170 == V_182 || V_170 == V_187 ) {
F_60 ( V_2 -> V_161 , L_11 ,
V_173 [ V_170 ] . V_178 ) ;
return V_170 ;
}
F_61
( L_15 ) ;
return V_182 ;
break;
case 0x7 :
if ( V_170 == V_179 || V_170 == V_188 ||
V_170 == V_189 || V_170 == V_190 ) {
F_60 ( V_2 -> V_161 , L_11 ,
V_173 [ V_170 ] . V_178 ) ;
return V_170 ;
}
F_61
( L_16 ) ;
return V_179 ;
break;
case 0x8 :
if ( V_170 == V_191 || V_170 == V_192 ) {
F_60 ( V_2 -> V_161 , L_11 ,
V_173 [ V_170 ] . V_178 ) ;
return V_170 ;
}
F_61
( L_17 ) ;
return V_191 ;
break;
default:
F_61
( L_18 ,
V_169 ) ;
return V_170 ;
break;
}
return - 1 ;
}
static int F_62 ( struct V_1 * V_2 ,
struct V_193 * V_194 )
{
struct V_13 * V_14 ;
unsigned long V_10 = V_194 -> V_195 [ 0 ] ;
unsigned int V_63 = V_194 -> V_195 [ 1 ] ;
unsigned int V_40 = V_194 -> V_195 [ 2 ] ;
unsigned int V_41 = V_194 -> V_195 [ 3 ] ;
unsigned long V_196 ;
int V_170 ;
int V_197 ;
if ( F_63 ( V_2 , sizeof( struct V_198 ) ) < 0 )
return - V_167 ;
F_61 ( V_199 L_19 , V_2 -> V_200 ,
V_2 -> V_163 -> V_164 , V_10 ) ;
if ( V_63 ) {
F_61 ( V_201 L_20 , V_63 ) ;
if ( V_40 ) {
F_61 ( V_201 L_21 , V_40 ) ;
if ( V_41 )
F_61 ( V_201 L_22 , V_41 ) ;
}
}
F_61 ( V_201 L_23 ) ;
if ( V_10 == 0 ) {
F_55 ( V_2 -> V_161 , L_24 ) ;
return - V_162 ;
}
if ( ! F_64 ( V_10 , V_202 , V_2 -> V_163 -> V_164 ) ) {
F_61
( L_25 ,
V_10 , V_10 + V_202 - 1 ) ;
return - V_203 ;
}
V_2 -> V_10 = V_10 ;
V_170 = F_59 ( V_2 ) ;
if ( V_170 < 0 ) {
F_55 ( V_2 -> V_161 , L_26 ) ;
return - V_204 ;
}
V_2 -> V_172 = V_173 + V_170 ;
V_2 -> V_205 = V_4 -> V_178 ;
if ( V_4 -> V_206 == 2 ) {
V_196 = V_10 + V_207 ;
if ( ! F_64 ( V_196 , V_202 ,
V_2 -> V_163 -> V_164 ) ) {
F_61
( L_25 ,
V_196 , V_196 + V_202 - 1 ) ;
return - V_203 ;
}
V_22 -> V_196 = V_196 ;
}
if ( V_63 ) {
if ( F_65 ( V_63 , F_30 , 0 ,
V_2 -> V_163 -> V_164 , V_2 ) ) {
F_60 ( V_2 -> V_161 , L_27 ,
V_63 ) ;
return - V_162 ;
}
}
V_2 -> V_63 = V_63 ;
switch ( V_63 ) {
case 0 :
break;
case 3 :
V_22 -> V_36 |= 0x8 ;
break;
case 5 :
V_22 -> V_36 |= 0x10 ;
break;
case 7 :
V_22 -> V_36 |= 0x18 ;
break;
case 10 :
V_22 -> V_36 |= 0x28 ;
break;
case 11 :
V_22 -> V_36 |= 0x30 ;
break;
case 15 :
V_22 -> V_36 |= 0x38 ;
break;
default:
F_55 ( V_2 -> V_161 , L_28 ) ;
return - V_162 ;
break;
}
V_197 = F_54 ( V_2 , V_40 , V_41 ) ;
if ( V_197 < 0 )
return V_197 ;
if ( V_22 -> V_25 == NULL ) {
V_22 -> V_25 =
F_57 ( V_19 * sizeof( T_1 ) , V_165 ) ;
if ( V_22 -> V_25 == NULL )
return - V_167 ;
}
V_197 = F_66 ( V_2 , 4 ) ;
if ( V_197 )
return V_197 ;
V_14 = V_2 -> V_48 + 0 ;
V_2 -> V_208 = V_14 ;
V_14 -> type = V_209 ;
V_14 -> V_210 = V_211 | V_212 | V_213 | V_214 ;
if ( V_4 -> V_215 )
V_14 -> V_210 |= V_216 ;
V_14 -> V_153 = V_4 -> V_217 ;
V_14 -> V_218 = V_4 -> V_217 ;
V_14 -> V_219 = ( 1 << V_4 -> V_5 ) - 1 ;
V_14 -> V_220 = V_4 -> V_221 ;
V_14 -> V_222 = F_48 ;
V_14 -> V_223 = F_34 ;
V_14 -> V_224 = F_49 ;
V_14 -> V_225 = F_27 ;
V_14 -> V_226 = F_23 ;
V_14 = V_2 -> V_48 + 1 ;
if ( V_4 -> V_206 == 1 ) {
V_14 -> type = V_227 ;
V_14 -> V_210 = V_228 ;
V_14 -> V_153 = V_4 -> V_147 ;
V_14 -> V_219 = ( 1 << V_4 -> V_5 ) - 1 ;
V_14 -> V_220 = & V_229 ;
V_14 -> V_230 = F_50 ;
} else {
V_14 -> type = V_231 ;
}
V_14 = V_2 -> V_48 + 2 ;
V_14 -> type = V_232 ;
V_14 -> V_210 = V_211 ;
V_14 -> V_153 = 4 ;
V_14 -> V_219 = 1 ;
V_14 -> V_220 = & V_233 ;
V_14 -> V_234 = F_52 ;
V_14 = V_2 -> V_48 + 3 ;
V_14 -> type = V_235 ;
V_14 -> V_210 = V_228 | V_211 ;
V_14 -> V_153 = V_4 -> V_236 ;
V_14 -> V_219 = 1 ;
V_14 -> V_220 = & V_233 ;
V_14 -> V_234 = F_53 ;
F_23 ( V_2 , V_2 -> V_208 ) ;
F_22 ( V_22 -> V_154 , V_2 -> V_10 + V_151 ) ;
if ( V_4 -> V_206 == 1 ) {
F_22 ( F_51 ( V_4 -> V_147 - 1 ) ,
V_2 -> V_10 + V_52 ) ;
F_47 ( V_22 -> V_149 , V_2 -> V_10 + V_150 ) ;
}
return 0 ;
}
static void F_67 ( struct V_1 * V_2 )
{
if ( V_2 -> V_10 )
F_68 ( V_2 -> V_10 , V_202 ) ;
if ( V_2 -> V_63 )
F_69 ( V_2 -> V_63 , V_2 ) ;
if ( V_2 -> V_237 ) {
if ( V_22 -> V_196 )
F_68 ( V_22 -> V_196 , V_202 ) ;
if ( V_22 -> V_40 )
F_70 ( V_22 -> V_40 ) ;
if ( V_22 -> V_41 )
F_70 ( V_22 -> V_41 ) ;
F_71 ( V_22 -> V_25 ) ;
F_71 ( V_22 -> V_42 ) ;
}
}
