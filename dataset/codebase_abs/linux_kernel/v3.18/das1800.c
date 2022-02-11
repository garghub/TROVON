static inline T_1 F_1 ( const struct V_1 * V_2 ,
T_1 V_3 )
{
const struct V_4 * V_5 = V_2 -> V_6 ;
V_3 += 1 << ( V_5 -> V_7 - 1 ) ;
return V_3 ;
}
static void F_2 ( struct V_1 * V_2 , T_1 * V_8 ,
unsigned int V_9 )
{
unsigned int V_10 ;
int V_11 ;
V_11 = F_3 ( V_2 -> V_12 + V_13 ) & V_14 ;
if ( ! V_11 ) {
for ( V_10 = 0 ; V_10 < V_9 ; V_10 ++ )
V_8 [ V_10 ] = F_1 ( V_2 , V_8 [ V_10 ] ) ;
}
}
static void F_4 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
struct V_17 * V_18 = V_2 -> V_19 ;
int V_20 = 0 ;
struct V_21 * V_22 = & V_16 -> V_23 -> V_22 ;
V_20 = V_24 / 2 ;
if ( V_22 -> V_25 == V_26 && V_18 -> V_27 < V_20 )
V_20 = V_18 -> V_27 ;
F_5 ( V_2 -> V_12 + V_28 , V_18 -> V_29 , V_20 ) ;
F_2 ( V_2 , V_18 -> V_29 , V_20 ) ;
F_6 ( V_16 , V_18 -> V_29 ,
V_20 * sizeof( V_18 -> V_29 [ 0 ] ) ) ;
if ( V_22 -> V_25 == V_26 )
V_18 -> V_27 -= V_20 ;
}
static void F_7 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
struct V_17 * V_18 = V_2 -> V_19 ;
unsigned short V_30 ;
int V_11 ;
struct V_21 * V_22 = & V_16 -> V_23 -> V_22 ;
V_11 = F_3 ( V_2 -> V_12 + V_13 ) & V_14 ;
while ( F_3 ( V_2 -> V_12 + V_31 ) & V_32 ) {
if ( V_22 -> V_25 == V_26 && V_18 -> V_27 == 0 )
break;
V_30 = F_8 ( V_2 -> V_12 + V_28 ) ;
if ( ! V_11 )
;
V_30 = F_1 ( V_2 , V_30 ) ;
F_9 ( V_16 , V_30 ) ;
if ( V_22 -> V_25 == V_26 )
V_18 -> V_27 -- ;
}
}
static void F_10 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
unsigned int V_33 , T_1 * V_34 )
{
struct V_17 * V_18 = V_2 -> V_19 ;
unsigned int V_35 , V_36 ;
struct V_21 * V_22 = & V_16 -> V_23 -> V_22 ;
F_11 ( V_33 ) ;
F_12 ( V_33 ) ;
V_35 = V_18 -> V_37 - F_13 ( V_33 ) ;
V_36 = V_35 / sizeof( short ) ;
if ( V_22 -> V_25 == V_26 && V_18 -> V_27 < V_36 )
V_36 = V_18 -> V_27 ;
F_2 ( V_2 , V_34 , V_36 ) ;
F_6 ( V_16 , V_34 , V_35 ) ;
if ( V_22 -> V_25 == V_26 )
V_18 -> V_27 -= V_36 ;
}
static void F_14 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
struct V_17 * V_18 = V_2 -> V_19 ;
unsigned long V_38 ;
const int V_39 = V_18 -> V_40 & V_41 ;
V_38 = F_15 () ;
F_10 ( V_2 , V_16 , V_18 -> V_42 ,
V_18 -> V_43 ) ;
if ( V_39 ) {
if ( V_18 -> V_42 == V_18 -> V_44 ) {
V_18 -> V_42 = V_18 -> V_45 ;
V_18 -> V_43 = V_18 -> V_46 ;
} else {
V_18 -> V_42 = V_18 -> V_44 ;
V_18 -> V_43 = V_18 -> V_29 ;
}
F_10 ( V_2 , V_16 , V_18 -> V_42 ,
V_18 -> V_43 ) ;
}
F_16 ( V_38 ) ;
F_7 ( V_2 , V_16 ) ;
}
static void F_17 ( struct V_1 * V_2 ,
struct V_15 * V_16 , unsigned int V_47 )
{
struct V_17 * V_18 = V_2 -> V_19 ;
unsigned long V_38 ;
const int V_39 = V_18 -> V_40 & V_41 ;
V_38 = F_15 () ;
F_10 ( V_2 , V_16 , V_18 -> V_42 ,
V_18 -> V_43 ) ;
F_18 ( V_18 -> V_42 ,
F_19 ( V_18 -> V_43 ) ) ;
F_20 ( V_18 -> V_42 , V_18 -> V_37 ) ;
F_21 ( V_18 -> V_42 ) ;
F_16 ( V_38 ) ;
if ( V_47 & V_48 ) {
F_22 ( V_49 & ~ V_48 , V_2 -> V_12 + V_31 ) ;
if ( V_39 ) {
if ( V_18 -> V_42 == V_18 -> V_44 ) {
V_18 -> V_42 = V_18 -> V_45 ;
V_18 -> V_43 = V_18 -> V_46 ;
} else {
V_18 -> V_42 = V_18 -> V_44 ;
V_18 -> V_43 = V_18 -> V_29 ;
}
}
}
}
static int F_23 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
struct V_17 * V_18 = V_2 -> V_19 ;
F_22 ( 0x0 , V_2 -> V_12 + V_31 ) ;
F_22 ( 0x0 , V_2 -> V_12 + V_50 ) ;
F_22 ( 0x0 , V_2 -> V_12 + V_51 ) ;
if ( V_18 -> V_44 )
F_11 ( V_18 -> V_44 ) ;
if ( V_18 -> V_45 )
F_11 ( V_18 -> V_45 ) ;
return 0 ;
}
static void F_24 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_19 ;
struct V_15 * V_16 = V_2 -> V_52 ;
struct V_53 * V_23 = V_16 -> V_23 ;
struct V_21 * V_22 = & V_23 -> V_22 ;
unsigned int V_47 = F_3 ( V_2 -> V_12 + V_31 ) ;
F_22 ( V_54 , V_2 -> V_12 + V_55 ) ;
if ( V_18 -> V_40 & V_56 ) {
F_17 ( V_2 , V_16 , V_47 ) ;
} else if ( V_47 & V_57 ) {
F_4 ( V_2 , V_16 ) ;
} else if ( V_47 & V_32 ) {
F_7 ( V_2 , V_16 ) ;
}
V_23 -> V_58 |= V_59 ;
if ( V_47 & V_60 ) {
F_22 ( V_49 & ~ V_60 , V_2 -> V_12 + V_31 ) ;
F_25 ( V_2 -> V_61 , L_1 ) ;
V_23 -> V_58 |= V_62 | V_63 ;
F_26 ( V_2 , V_16 ) ;
return;
}
if ( V_47 & V_64 ) {
F_22 ( V_49 & ~ V_64 , V_2 -> V_12 + V_31 ) ;
if ( V_18 -> V_40 & V_56 )
F_14 ( V_2 , V_16 ) ;
else
F_7 ( V_2 , V_16 ) ;
V_23 -> V_58 |= V_63 ;
} else if ( V_22 -> V_25 == V_26 && V_18 -> V_27 == 0 ) {
V_23 -> V_58 |= V_63 ;
}
F_26 ( V_2 , V_16 ) ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
unsigned long V_38 ;
F_28 ( & V_2 -> V_65 , V_38 ) ;
F_24 ( V_2 ) ;
F_29 ( & V_2 -> V_65 , V_38 ) ;
return F_30 ( V_16 ) ;
}
static T_2 F_31 ( int V_66 , void * V_67 )
{
struct V_1 * V_2 = V_67 ;
unsigned int V_47 ;
if ( ! V_2 -> V_68 ) {
F_25 ( V_2 -> V_61 , L_2 ) ;
return V_69 ;
}
F_32 ( & V_2 -> V_65 ) ;
V_47 = F_3 ( V_2 -> V_12 + V_31 ) ;
if ( ! ( V_47 & INT ) ) {
F_33 ( & V_2 -> V_65 ) ;
return V_70 ;
}
F_22 ( V_49 & ~ INT , V_2 -> V_12 + V_31 ) ;
F_24 ( V_2 ) ;
F_33 ( & V_2 -> V_65 ) ;
return V_69 ;
}
static unsigned int F_34 ( unsigned int V_71 , int V_38 )
{
unsigned int V_72 ;
if ( V_71 > 64000 )
V_71 = 64000 ;
switch ( V_38 & V_73 ) {
case V_74 :
default:
V_72 = ( V_71 + 500 ) / 1000 ;
break;
case V_75 :
V_72 = V_71 / 1000 ;
break;
case V_76 :
V_72 = ( V_71 - 1 ) / 1000 + 1 ;
break;
}
return V_72 * 1000 ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_21 * V_22 )
{
unsigned int V_77 = F_36 ( V_22 -> V_78 [ 0 ] ) & V_79 ;
int V_10 ;
for ( V_10 = 1 ; V_10 < V_22 -> V_80 ; V_10 ++ ) {
unsigned int V_11 = F_36 ( V_22 -> V_78 [ V_10 ] ) & V_79 ;
if ( V_11 != V_77 ) {
F_37 ( V_2 -> V_61 ,
L_3 ) ;
return - V_81 ;
}
}
return 0 ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_21 * V_22 )
{
const struct V_4 * V_5 = V_2 -> V_6 ;
struct V_17 * V_18 = V_2 -> V_19 ;
int V_82 = 0 ;
unsigned int V_83 ;
V_82 |= F_39 ( & V_22 -> V_84 , V_85 | V_86 ) ;
V_82 |= F_39 ( & V_22 -> V_87 ,
V_88 | V_89 | V_86 ) ;
V_82 |= F_39 ( & V_22 -> V_90 , V_89 | V_86 ) ;
V_82 |= F_39 ( & V_22 -> V_91 , V_26 ) ;
V_82 |= F_39 ( & V_22 -> V_25 ,
V_26 | V_86 | V_92 ) ;
if ( V_82 )
return 1 ;
V_82 |= F_40 ( V_22 -> V_84 ) ;
V_82 |= F_40 ( V_22 -> V_87 ) ;
V_82 |= F_40 ( V_22 -> V_90 ) ;
V_82 |= F_40 ( V_22 -> V_25 ) ;
if ( V_22 -> V_87 != V_88 &&
V_22 -> V_90 != V_89 )
V_82 |= - V_81 ;
if ( V_82 )
return 2 ;
V_82 |= F_41 ( & V_22 -> V_93 , 0 ) ;
if ( V_22 -> V_90 == V_89 )
V_82 |= F_42 ( & V_22 -> V_71 ,
V_5 -> V_94 ) ;
V_82 |= F_42 ( & V_22 -> V_80 , 1 ) ;
V_82 |= F_41 ( & V_22 -> V_95 , V_22 -> V_80 ) ;
switch ( V_22 -> V_25 ) {
case V_26 :
V_82 |= F_42 ( & V_22 -> V_96 , 1 ) ;
break;
case V_92 :
V_82 |= F_41 ( & V_22 -> V_96 , 0 ) ;
break;
default:
break;
}
if ( V_82 )
return 3 ;
if ( V_22 -> V_87 == V_88 &&
V_22 -> V_90 == V_89 ) {
V_83 = V_22 -> V_71 ;
F_43 ( V_97 ,
& V_18 -> V_98 ,
& V_18 -> V_99 ,
& V_22 -> V_71 , V_22 -> V_38 ) ;
if ( V_83 != V_22 -> V_71 )
V_82 ++ ;
} else if ( V_22 -> V_90 == V_89 ) {
V_83 = V_22 -> V_71 ;
V_22 -> V_71 = F_34 ( V_22 -> V_71 ,
V_22 -> V_38 ) ;
if ( V_83 != V_22 -> V_71 )
V_82 ++ ;
if ( V_22 -> V_87 == V_89 ) {
V_83 = V_22 -> V_71 * V_22 -> V_80 ;
if ( V_83 > V_22 -> V_100 ) {
V_22 -> V_100 = V_83 ;
V_82 ++ ;
}
V_83 = V_22 -> V_100 ;
F_43 ( V_97 ,
& V_18 -> V_98 ,
& V_18 -> V_99 ,
& V_22 -> V_100 ,
V_22 -> V_38 ) ;
if ( V_83 != V_22 -> V_100 )
V_82 ++ ;
}
}
if ( V_82 )
return 4 ;
if ( V_22 -> V_78 && V_22 -> V_80 > 0 )
V_82 |= F_35 ( V_2 , V_16 , V_22 ) ;
if ( V_82 )
return 5 ;
return 0 ;
}
static int F_44 ( const struct V_21 * V_22 )
{
int V_101 ;
V_101 = V_102 ;
if ( V_22 -> V_25 == V_86 )
V_101 |= V_103 ;
switch ( V_22 -> V_84 ) {
case V_86 :
V_101 |= V_104 | V_105 ;
break;
case V_85 :
V_101 |= V_106 ;
break;
default:
break;
}
return V_101 ;
}
static int F_45 ( const struct V_21 * V_22 )
{
int V_107 ;
int V_108 ;
V_108 = F_46 ( V_22 -> V_78 [ 0 ] ) ;
V_107 = V_109 ;
if ( V_108 != V_110 )
V_107 |= V_111 ;
if ( V_108 == V_112 )
V_107 |= V_113 ;
if ( F_36 ( V_22 -> V_78 [ 0 ] ) & V_79 )
V_107 |= V_14 ;
switch ( V_22 -> V_87 ) {
case V_88 :
switch ( V_22 -> V_90 ) {
case V_89 :
V_107 |= V_114 ;
break;
case V_86 :
V_107 |= V_115 ;
break;
default:
break;
}
break;
case V_89 :
V_107 |= V_116 | V_114 ;
break;
case V_86 :
V_107 |= V_116 | V_115 ;
break;
default:
break;
}
return V_107 ;
}
static void F_47 ( struct V_1 * V_2 ,
const struct V_21 * V_22 )
{
struct V_17 * V_18 = V_2 -> V_19 ;
unsigned long V_117 = V_2 -> V_12 + V_118 ;
if ( ( V_22 -> V_87 == V_88 ||
V_22 -> V_87 == V_89 ) &&
V_22 -> V_90 == V_89 ) {
F_48 ( V_117 , 0 , 1 , V_119 | V_120 ) ;
F_48 ( V_117 , 0 , 2 , V_119 | V_120 ) ;
F_49 ( V_117 , 0 , 1 , V_18 -> V_98 ) ;
F_49 ( V_117 , 0 , 2 , V_18 -> V_99 ) ;
}
if ( V_22 -> V_25 == V_86 ) {
F_48 ( V_117 , 0 , 0 , V_121 | V_120 ) ;
F_49 ( V_117 , 0 , 0 , 1 ) ;
}
}
static unsigned int F_50 ( const struct V_21 * V_22 )
{
unsigned int V_122 = V_123 ;
static const int V_124 = 2 ;
unsigned int V_125 = 300000000 ;
unsigned int V_126 ;
switch ( V_22 -> V_87 ) {
case V_88 :
if ( V_22 -> V_90 == V_89 )
V_122 = ( V_125 / V_22 -> V_71 ) * V_124 ;
break;
case V_89 :
V_122 = ( V_125 / ( V_22 -> V_100 * V_22 -> V_80 ) ) *
V_124 ;
break;
default:
V_122 = V_123 ;
break;
}
V_126 = V_123 ;
if ( V_22 -> V_25 == V_26 &&
V_22 -> V_96 * V_22 -> V_80 * V_124 < V_126 )
V_126 = V_22 -> V_96 * V_22 -> V_80 * V_124 ;
if ( V_122 > V_126 )
V_122 = V_126 ;
if ( V_122 < V_124 )
V_122 = V_124 ;
return V_122 ;
}
static void F_51 ( struct V_1 * V_2 , const struct V_21 * V_22 )
{
struct V_17 * V_18 = V_2 -> V_19 ;
unsigned long V_127 ;
const int V_39 = V_18 -> V_40 & V_41 ;
if ( ( V_18 -> V_40 & V_56 ) == 0 )
return;
V_18 -> V_37 = F_50 ( V_22 ) ;
V_127 = F_15 () ;
F_11 ( V_18 -> V_44 ) ;
F_12 ( V_18 -> V_44 ) ;
F_18 ( V_18 -> V_44 , F_19 ( V_18 -> V_29 ) ) ;
F_20 ( V_18 -> V_44 , V_18 -> V_37 ) ;
V_18 -> V_42 = V_18 -> V_44 ;
V_18 -> V_43 = V_18 -> V_29 ;
F_21 ( V_18 -> V_44 ) ;
if ( V_39 ) {
F_11 ( V_18 -> V_45 ) ;
F_12 ( V_18 -> V_45 ) ;
F_18 ( V_18 -> V_45 , F_19 ( V_18 -> V_46 ) ) ;
F_20 ( V_18 -> V_45 , V_18 -> V_37 ) ;
F_21 ( V_18 -> V_45 ) ;
}
F_16 ( V_127 ) ;
}
static void F_52 ( struct V_1 * V_2 ,
const struct V_21 * V_22 )
{
int V_10 , V_128 , V_129 ;
unsigned long V_130 ;
const int V_131 = 0x3 ;
const int V_132 = 8 ;
V_128 = V_22 -> V_80 ;
F_28 ( & V_2 -> V_65 , V_130 ) ;
F_22 ( V_133 , V_2 -> V_12 + V_55 ) ;
F_22 ( V_128 - 1 , V_2 -> V_12 + V_134 ) ;
for ( V_10 = 0 ; V_10 < V_128 ; V_10 ++ ) {
V_129 =
F_53 ( V_22 -> V_78 [ V_10 ] ) |
( ( F_36 ( V_22 -> V_78 [ V_10 ] ) & V_131 ) <<
V_132 ) ;
F_54 ( V_129 , V_2 -> V_12 + V_135 ) ;
}
F_22 ( V_128 - 1 , V_2 -> V_12 + V_134 ) ;
F_29 ( & V_2 -> V_65 , V_130 ) ;
}
static int F_55 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
struct V_17 * V_18 = V_2 -> V_19 ;
int V_101 , V_107 ;
struct V_53 * V_23 = V_16 -> V_23 ;
const struct V_21 * V_22 = & V_23 -> V_22 ;
if ( V_22 -> V_38 & ( V_136 | V_137 ) )
V_18 -> V_40 &= ~ V_56 ;
else
V_18 -> V_40 |= V_18 -> V_138 ;
if ( V_22 -> V_38 & V_136 ) {
V_18 -> V_40 &= ~ V_139 ;
} else {
V_18 -> V_40 |= V_139 ;
}
if ( V_22 -> V_25 == V_26 )
V_18 -> V_27 = V_22 -> V_96 * V_22 -> V_80 ;
F_23 ( V_2 , V_16 ) ;
V_101 = F_44 ( V_22 ) ;
V_107 = F_45 ( V_22 ) ;
F_52 ( V_2 , V_22 ) ;
F_47 ( V_2 , V_22 ) ;
F_51 ( V_2 , V_22 ) ;
F_22 ( V_107 , V_2 -> V_12 + V_13 ) ;
if ( V_107 & V_116 ) {
F_22 ( V_22 -> V_71 / 1000 - 1 ,
V_2 -> V_12 + V_140 ) ;
F_22 ( V_22 -> V_80 - 1 , V_2 -> V_12 + V_141 ) ;
}
F_22 ( V_18 -> V_40 , V_2 -> V_12 + V_50 ) ;
F_22 ( V_101 , V_2 -> V_12 + V_51 ) ;
F_22 ( V_142 , V_2 -> V_12 + V_31 ) ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_143 * V_144 , unsigned int * V_145 )
{
const struct V_4 * V_5 = V_2 -> V_6 ;
int V_10 , V_128 ;
int V_146 , V_147 , V_108 , V_129 ;
int V_148 = 1000 ;
unsigned short V_30 ;
int V_149 = 0 ;
unsigned long V_130 ;
V_108 = F_46 ( V_144 -> V_150 ) ;
V_149 |= V_109 ;
if ( V_108 != V_110 )
V_149 |= V_111 ;
if ( V_108 == V_112 )
V_149 |= V_113 ;
if ( F_36 ( V_144 -> V_150 ) & V_79 )
V_149 |= V_14 ;
F_22 ( V_149 , V_2 -> V_12 + V_13 ) ;
F_22 ( V_142 , V_2 -> V_12 + V_31 ) ;
F_22 ( 0x0 , V_2 -> V_12 + V_51 ) ;
F_22 ( V_102 , V_2 -> V_12 + V_51 ) ;
V_146 = F_53 ( V_144 -> V_150 ) ;
V_147 = F_36 ( V_144 -> V_150 ) & 0x3 ;
V_129 = V_146 | ( V_147 << 8 ) ;
F_28 ( & V_2 -> V_65 , V_130 ) ;
F_22 ( V_133 , V_2 -> V_12 + V_55 ) ;
F_22 ( 0x0 , V_2 -> V_12 + V_134 ) ;
F_54 ( V_129 , V_2 -> V_12 + V_135 ) ;
F_22 ( 0x0 , V_2 -> V_12 + V_134 ) ;
F_22 ( V_54 , V_2 -> V_12 + V_55 ) ;
for ( V_128 = 0 ; V_128 < V_144 -> V_128 ; V_128 ++ ) {
F_22 ( 0 , V_2 -> V_12 + V_28 ) ;
for ( V_10 = 0 ; V_10 < V_148 ; V_10 ++ ) {
if ( F_3 ( V_2 -> V_12 + V_31 ) & V_32 )
break;
}
if ( V_10 == V_148 ) {
F_25 ( V_2 -> V_61 , L_4 ) ;
V_128 = - V_151 ;
goto exit;
}
V_30 = F_8 ( V_2 -> V_12 + V_28 ) ;
if ( ( V_149 & V_14 ) == 0 )
V_30 += 1 << ( V_5 -> V_7 - 1 ) ;
V_145 [ V_128 ] = V_30 ;
}
exit:
F_29 ( & V_2 -> V_65 , V_130 ) ;
return V_128 ;
}
static int F_57 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_143 * V_144 , unsigned int * V_145 )
{
const struct V_4 * V_5 = V_2 -> V_6 ;
struct V_17 * V_18 = V_2 -> V_19 ;
int V_146 = F_53 ( V_144 -> V_150 ) ;
int V_152 = V_5 -> V_153 - 1 ;
unsigned short V_154 ;
unsigned long V_130 ;
V_154 = V_145 [ 0 ] - ( 1 << ( V_5 -> V_7 - 1 ) ) ;
if ( V_146 == V_152 )
V_18 -> V_155 = V_154 ;
F_28 ( & V_2 -> V_65 , V_130 ) ;
F_22 ( F_58 ( V_146 ) , V_2 -> V_12 + V_55 ) ;
F_54 ( V_154 , V_2 -> V_12 + V_156 ) ;
if ( V_146 != V_152 ) {
F_22 ( F_58 ( V_152 ) , V_2 -> V_12 + V_55 ) ;
F_54 ( V_18 -> V_155 , V_2 -> V_12 + V_156 ) ;
}
F_29 ( & V_2 -> V_65 , V_130 ) ;
return 1 ;
}
static int F_59 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_143 * V_144 , unsigned int * V_145 )
{
V_145 [ 1 ] = F_3 ( V_2 -> V_12 + V_157 ) & 0xf ;
V_145 [ 0 ] = 0 ;
return V_144 -> V_128 ;
}
static int F_60 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_143 * V_144 ,
unsigned int * V_145 )
{
if ( F_61 ( V_16 , V_145 ) )
F_22 ( V_16 -> V_158 , V_2 -> V_12 + V_157 ) ;
V_145 [ 1 ] = V_16 -> V_158 ;
return V_144 -> V_128 ;
}
static int F_62 ( struct V_1 * V_2 , unsigned int V_44 ,
unsigned int V_45 )
{
struct V_17 * V_18 = V_2 -> V_19 ;
unsigned long V_38 ;
if ( V_2 -> V_66 && V_44 ) {
switch ( ( V_44 & 0x7 ) | ( V_45 << 4 ) ) {
case 0x5 :
V_18 -> V_138 |= V_159 ;
break;
case 0x6 :
V_18 -> V_138 |= V_160 ;
break;
case 0x7 :
V_18 -> V_138 |= V_161 ;
break;
case 0x65 :
V_18 -> V_138 |= V_162 ;
break;
case 0x76 :
V_18 -> V_138 |= V_163 ;
break;
case 0x57 :
V_18 -> V_138 |= V_164 ;
break;
default:
F_25 ( V_2 -> V_61 ,
L_5 ) ;
F_25 ( V_2 -> V_61 ,
L_6 ) ;
F_25 ( V_2 -> V_61 ,
L_7 ) ;
return - V_81 ;
}
if ( F_63 ( V_44 , V_2 -> V_165 -> V_166 ) ) {
F_25 ( V_2 -> V_61 ,
L_8 , V_44 ) ;
return - V_81 ;
}
V_18 -> V_44 = V_44 ;
V_18 -> V_42 = V_44 ;
if ( V_45 ) {
if ( F_63 ( V_45 , V_2 -> V_165 -> V_166 ) ) {
F_25 ( V_2 -> V_61 ,
L_8 ,
V_45 ) ;
return - V_81 ;
}
V_18 -> V_45 = V_45 ;
}
V_18 -> V_29 = F_64 ( V_123 , V_167 | V_168 ) ;
if ( V_18 -> V_29 == NULL )
return - V_169 ;
V_18 -> V_43 = V_18 -> V_29 ;
if ( V_45 ) {
V_18 -> V_46 =
F_64 ( V_123 , V_167 | V_168 ) ;
if ( V_18 -> V_46 == NULL )
return - V_169 ;
}
V_38 = F_15 () ;
F_11 ( V_18 -> V_44 ) ;
F_65 ( V_18 -> V_44 , V_170 ) ;
if ( V_45 ) {
F_11 ( V_18 -> V_45 ) ;
F_65 ( V_18 -> V_45 , V_170 ) ;
}
F_16 ( V_38 ) ;
}
return 0 ;
}
static int F_66 ( struct V_1 * V_2 )
{
const struct V_4 * V_171 = V_2 -> V_6 ;
int V_172 ;
int V_173 ;
V_172 = V_171 - V_174 ;
V_173 = ( F_3 ( V_2 -> V_12 + V_157 ) >> 4 ) & 0xf ;
switch ( V_173 ) {
case 0x3 :
if ( V_172 == V_175 || V_172 == V_176 ||
V_172 == V_177 || V_172 == V_178 )
return V_172 ;
V_172 = V_179 ;
break;
case 0x4 :
if ( V_172 == V_180 || V_172 == V_181 )
return V_172 ;
V_172 = V_182 ;
break;
case 0x5 :
if ( V_172 == V_183 || V_172 == V_184 ||
V_172 == V_185 || V_172 == V_186 )
return V_172 ;
V_172 = V_183 ;
break;
case 0x6 :
if ( V_172 == V_182 || V_172 == V_187 )
return V_172 ;
V_172 = V_182 ;
break;
case 0x7 :
if ( V_172 == V_179 || V_172 == V_188 ||
V_172 == V_189 || V_172 == V_190 )
return V_172 ;
V_172 = V_179 ;
break;
case 0x8 :
if ( V_172 == V_191 || V_172 == V_192 )
return V_172 ;
V_172 = V_191 ;
break;
default:
F_25 ( V_2 -> V_61 ,
L_9 ,
V_173 ) ;
break;
}
F_25 ( V_2 -> V_61 ,
L_10 ,
V_174 [ V_172 ] . V_193 ) ;
return V_172 ;
}
static int F_67 ( struct V_1 * V_2 ,
struct V_194 * V_195 )
{
const struct V_4 * V_5 ;
struct V_17 * V_18 ;
struct V_15 * V_16 ;
unsigned int V_66 = V_195 -> V_196 [ 1 ] ;
unsigned int V_44 = V_195 -> V_196 [ 2 ] ;
unsigned int V_45 = V_195 -> V_196 [ 3 ] ;
int V_171 ;
int V_197 ;
V_18 = F_68 ( V_2 , sizeof( * V_18 ) ) ;
if ( ! V_18 )
return - V_169 ;
V_197 = F_69 ( V_2 , V_195 -> V_196 [ 0 ] , V_198 ) ;
if ( V_197 )
return V_197 ;
V_171 = F_66 ( V_2 ) ;
if ( V_171 < 0 ) {
F_25 ( V_2 -> V_61 , L_11 ) ;
return - V_199 ;
}
V_2 -> V_6 = V_174 + V_171 ;
V_5 = V_2 -> V_6 ;
V_2 -> V_200 = V_5 -> V_193 ;
if ( V_5 -> V_201 == 2 ) {
unsigned long V_202 = V_2 -> V_12 + V_203 ;
V_197 = F_70 ( V_2 , V_202 , V_198 ) ;
if ( V_197 )
return V_197 ;
V_18 -> V_202 = V_202 ;
}
if ( V_66 == 3 || V_66 == 5 || V_66 == 7 || V_66 == 10 || V_66 == 11 ||
V_66 == 15 ) {
V_197 = F_71 ( V_66 , F_31 , 0 ,
V_2 -> V_200 , V_2 ) ;
if ( V_197 == 0 ) {
V_2 -> V_66 = V_66 ;
switch ( V_66 ) {
case 3 :
V_18 -> V_40 |= 0x8 ;
break;
case 5 :
V_18 -> V_40 |= 0x10 ;
break;
case 7 :
V_18 -> V_40 |= 0x18 ;
break;
case 10 :
V_18 -> V_40 |= 0x28 ;
break;
case 11 :
V_18 -> V_40 |= 0x30 ;
break;
case 15 :
V_18 -> V_40 |= 0x38 ;
break;
}
}
}
V_197 = F_62 ( V_2 , V_44 , V_45 ) ;
if ( V_197 < 0 )
return V_197 ;
if ( V_18 -> V_29 == NULL ) {
V_18 -> V_29 =
F_64 ( V_24 * sizeof( T_1 ) , V_167 ) ;
if ( V_18 -> V_29 == NULL )
return - V_169 ;
}
V_197 = F_72 ( V_2 , 4 ) ;
if ( V_197 )
return V_197 ;
V_16 = & V_2 -> V_204 [ 0 ] ;
V_16 -> type = V_205 ;
V_16 -> V_206 = V_207 | V_208 | V_209 ;
if ( V_5 -> V_210 )
V_16 -> V_206 |= V_211 ;
V_16 -> V_212 = V_5 -> V_213 ;
V_16 -> V_214 = ( 1 << V_5 -> V_7 ) - 1 ;
V_16 -> V_215 = V_5 -> V_216 ;
V_16 -> V_217 = F_56 ;
if ( V_2 -> V_66 ) {
V_2 -> V_52 = V_16 ;
V_16 -> V_206 |= V_218 ;
V_16 -> V_219 = V_16 -> V_212 ;
V_16 -> V_220 = F_55 ;
V_16 -> V_221 = F_38 ;
V_16 -> V_222 = F_27 ;
V_16 -> V_223 = F_23 ;
}
V_16 = & V_2 -> V_204 [ 1 ] ;
if ( V_5 -> V_201 == 1 ) {
V_16 -> type = V_224 ;
V_16 -> V_206 = V_225 ;
V_16 -> V_212 = V_5 -> V_153 ;
V_16 -> V_214 = ( 1 << V_5 -> V_7 ) - 1 ;
V_16 -> V_215 = & V_226 ;
V_16 -> V_227 = F_57 ;
} else {
V_16 -> type = V_228 ;
}
V_16 = & V_2 -> V_204 [ 2 ] ;
V_16 -> type = V_229 ;
V_16 -> V_206 = V_207 ;
V_16 -> V_212 = 4 ;
V_16 -> V_214 = 1 ;
V_16 -> V_215 = & V_230 ;
V_16 -> V_231 = F_59 ;
V_16 = & V_2 -> V_204 [ 3 ] ;
V_16 -> type = V_232 ;
V_16 -> V_206 = V_225 | V_207 ;
V_16 -> V_212 = V_5 -> V_233 ;
V_16 -> V_214 = 1 ;
V_16 -> V_215 = & V_230 ;
V_16 -> V_231 = F_60 ;
F_23 ( V_2 , V_2 -> V_52 ) ;
F_22 ( 0 , V_2 -> V_12 + V_157 ) ;
if ( V_5 -> V_201 == 1 ) {
F_22 ( F_58 ( V_5 -> V_153 - 1 ) ,
V_2 -> V_12 + V_55 ) ;
F_54 ( V_18 -> V_155 , V_2 -> V_12 + V_156 ) ;
}
return 0 ;
}
static void F_73 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_19 ;
if ( V_18 ) {
if ( V_18 -> V_44 )
F_74 ( V_18 -> V_44 ) ;
if ( V_18 -> V_45 )
F_74 ( V_18 -> V_45 ) ;
F_75 ( V_18 -> V_29 ) ;
F_75 ( V_18 -> V_46 ) ;
if ( V_18 -> V_202 )
F_76 ( V_18 -> V_202 , V_198 ) ;
}
F_77 ( V_2 ) ;
}
