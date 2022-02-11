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
unsigned short V_29 ;
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
if ( V_21 -> V_24 == V_25 )
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
struct V_14 * V_15 = V_2 -> V_51 ;
struct V_52 * V_22 = V_15 -> V_22 ;
struct V_20 * V_21 = & V_22 -> V_21 ;
unsigned int V_46 = F_4 ( V_2 -> V_11 + V_30 ) ;
F_23 ( V_53 , V_2 -> V_11 + V_54 ) ;
if ( V_17 -> V_39 & V_55 ) {
F_18 ( V_2 , V_15 , V_46 ) ;
} else if ( V_46 & V_56 ) {
F_5 ( V_2 , V_15 ) ;
} else if ( V_46 & V_31 ) {
F_8 ( V_2 , V_15 ) ;
}
V_22 -> V_57 |= V_58 ;
if ( V_46 & V_59 ) {
F_23 ( V_48 & ~ V_59 , V_2 -> V_11 + V_30 ) ;
F_26 ( V_2 , L_1 ) ;
V_22 -> V_57 |= V_60 | V_61 ;
F_27 ( V_2 , V_15 ) ;
return;
}
if ( V_46 & V_62 ) {
F_23 ( V_48 & ~ V_62 , V_2 -> V_11 + V_30 ) ;
if ( V_17 -> V_39 & V_55 )
F_15 ( V_2 , V_15 ) ;
else
F_8 ( V_2 , V_15 ) ;
V_22 -> V_57 |= V_61 ;
} else if ( V_21 -> V_24 == V_25 && V_17 -> V_26 == 0 ) {
V_22 -> V_57 |= V_61 ;
}
F_27 ( V_2 , V_15 ) ;
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
static unsigned int F_34 ( unsigned int V_71 , int V_37 )
{
unsigned int V_72 ;
if ( V_71 > 64000 )
V_71 = 64000 ;
switch ( V_37 & V_73 ) {
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
struct V_14 * V_15 ,
struct V_20 * V_21 )
{
unsigned int V_77 = F_36 ( V_21 -> V_78 [ 0 ] ) & V_79 ;
int V_9 ;
for ( V_9 = 1 ; V_9 < V_21 -> V_80 ; V_9 ++ ) {
unsigned int V_10 = F_36 ( V_21 -> V_78 [ V_9 ] ) & V_79 ;
if ( V_10 != V_77 ) {
F_37 ( V_2 -> V_81 ,
L_3 ) ;
return - V_82 ;
}
}
return 0 ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_20 * V_21 )
{
const struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_16 * V_17 = V_2 -> V_18 ;
int V_83 = 0 ;
unsigned int V_84 ;
V_83 |= F_39 ( & V_21 -> V_85 , V_86 | V_87 ) ;
V_83 |= F_39 ( & V_21 -> V_88 ,
V_89 | V_90 | V_87 ) ;
V_83 |= F_39 ( & V_21 -> V_91 , V_90 | V_87 ) ;
V_83 |= F_39 ( & V_21 -> V_92 , V_25 ) ;
V_83 |= F_39 ( & V_21 -> V_24 ,
V_25 | V_87 | V_93 ) ;
if ( V_83 )
return 1 ;
V_83 |= F_40 ( V_21 -> V_85 ) ;
V_83 |= F_40 ( V_21 -> V_88 ) ;
V_83 |= F_40 ( V_21 -> V_91 ) ;
V_83 |= F_40 ( V_21 -> V_24 ) ;
if ( V_21 -> V_88 != V_89 &&
V_21 -> V_91 != V_90 )
V_83 |= - V_82 ;
if ( V_83 )
return 2 ;
V_83 |= F_41 ( & V_21 -> V_94 , 0 ) ;
if ( V_21 -> V_91 == V_90 )
V_83 |= F_42 ( & V_21 -> V_71 ,
V_5 -> V_95 ) ;
V_83 |= F_42 ( & V_21 -> V_80 , 1 ) ;
V_83 |= F_41 ( & V_21 -> V_96 , V_21 -> V_80 ) ;
switch ( V_21 -> V_24 ) {
case V_25 :
V_83 |= F_42 ( & V_21 -> V_97 , 1 ) ;
break;
case V_93 :
V_83 |= F_41 ( & V_21 -> V_97 , 0 ) ;
break;
default:
break;
}
if ( V_83 )
return 3 ;
if ( V_21 -> V_88 == V_89 &&
V_21 -> V_91 == V_90 ) {
V_84 = V_21 -> V_71 ;
F_43 ( V_98 ,
& V_17 -> V_99 ,
& V_17 -> V_100 ,
& V_21 -> V_71 , V_21 -> V_37 ) ;
if ( V_84 != V_21 -> V_71 )
V_83 ++ ;
} else if ( V_21 -> V_91 == V_90 ) {
V_84 = V_21 -> V_71 ;
V_21 -> V_71 = F_34 ( V_21 -> V_71 ,
V_21 -> V_37 ) ;
if ( V_84 != V_21 -> V_71 )
V_83 ++ ;
if ( V_21 -> V_88 == V_90 ) {
V_84 = V_21 -> V_71 * V_21 -> V_80 ;
if ( V_84 > V_21 -> V_101 ) {
V_21 -> V_101 = V_84 ;
V_83 ++ ;
}
V_84 = V_21 -> V_101 ;
F_43 ( V_98 ,
& V_17 -> V_99 ,
& V_17 -> V_100 ,
& V_21 -> V_101 ,
V_21 -> V_37 ) ;
if ( V_84 != V_21 -> V_101 )
V_83 ++ ;
}
}
if ( V_83 )
return 4 ;
if ( V_21 -> V_78 && V_21 -> V_80 > 0 )
V_83 |= F_35 ( V_2 , V_15 , V_21 ) ;
if ( V_83 )
return 5 ;
return 0 ;
}
static int F_44 ( const struct V_20 * V_21 )
{
int V_102 ;
V_102 = V_103 ;
if ( V_21 -> V_24 == V_87 )
V_102 |= V_104 ;
switch ( V_21 -> V_85 ) {
case V_87 :
V_102 |= V_105 | V_106 ;
break;
case V_86 :
V_102 |= V_107 ;
break;
default:
break;
}
return V_102 ;
}
static int F_45 ( const struct V_20 * V_21 )
{
int V_108 ;
int V_109 ;
V_109 = F_46 ( V_21 -> V_78 [ 0 ] ) ;
V_108 = V_110 ;
if ( V_109 != V_111 )
V_108 |= V_112 ;
if ( V_109 == V_113 )
V_108 |= V_114 ;
if ( F_36 ( V_21 -> V_78 [ 0 ] ) & V_79 )
V_108 |= V_13 ;
switch ( V_21 -> V_88 ) {
case V_89 :
switch ( V_21 -> V_91 ) {
case V_90 :
V_108 |= V_115 ;
break;
case V_87 :
V_108 |= V_116 ;
break;
default:
break;
}
break;
case V_90 :
V_108 |= V_117 | V_115 ;
break;
case V_87 :
V_108 |= V_117 | V_116 ;
break;
default:
break;
}
return V_108 ;
}
static void F_47 ( struct V_1 * V_2 ,
const struct V_20 * V_21 )
{
struct V_16 * V_17 = V_2 -> V_18 ;
unsigned long V_118 = V_2 -> V_11 + V_119 ;
if ( ( V_21 -> V_88 == V_89 ||
V_21 -> V_88 == V_90 ) &&
V_21 -> V_91 == V_90 ) {
F_48 ( V_118 , 0 , 1 , V_120 | V_121 ) ;
F_48 ( V_118 , 0 , 2 , V_120 | V_121 ) ;
F_49 ( V_118 , 0 , 1 , V_17 -> V_99 ) ;
F_49 ( V_118 , 0 , 2 , V_17 -> V_100 ) ;
}
if ( V_21 -> V_24 == V_87 ) {
F_48 ( V_118 , 0 , 0 , V_122 | V_121 ) ;
F_49 ( V_118 , 0 , 0 , 1 ) ;
}
}
static unsigned int F_50 ( const struct V_20 * V_21 )
{
unsigned int V_123 = V_124 ;
static const int V_125 = 2 ;
unsigned int V_126 = 300000000 ;
unsigned int V_127 ;
switch ( V_21 -> V_88 ) {
case V_89 :
if ( V_21 -> V_91 == V_90 )
V_123 = ( V_126 / V_21 -> V_71 ) * V_125 ;
break;
case V_90 :
V_123 = ( V_126 / ( V_21 -> V_101 * V_21 -> V_80 ) ) *
V_125 ;
break;
default:
V_123 = V_124 ;
break;
}
V_127 = V_124 ;
if ( V_21 -> V_24 == V_25 &&
V_21 -> V_97 * V_21 -> V_80 * V_125 < V_127 )
V_127 = V_21 -> V_97 * V_21 -> V_80 * V_125 ;
if ( V_123 > V_127 )
V_123 = V_127 ;
if ( V_123 < V_125 )
V_123 = V_125 ;
return V_123 ;
}
static void F_51 ( struct V_1 * V_2 , const struct V_20 * V_21 )
{
struct V_16 * V_17 = V_2 -> V_18 ;
unsigned long V_128 ;
const int V_38 = V_17 -> V_39 & V_40 ;
if ( ( V_17 -> V_39 & V_55 ) == 0 )
return;
V_17 -> V_36 = F_50 ( V_21 ) ;
V_128 = F_16 () ;
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
F_17 ( V_128 ) ;
return;
}
static void F_52 ( struct V_1 * V_2 ,
const struct V_20 * V_21 )
{
int V_9 , V_129 , V_130 ;
unsigned long V_131 ;
const int V_132 = 0x3 ;
const int V_133 = 8 ;
V_129 = V_21 -> V_80 ;
F_29 ( & V_2 -> V_63 , V_131 ) ;
F_23 ( V_134 , V_2 -> V_11 + V_54 ) ;
F_23 ( V_129 - 1 , V_2 -> V_11 + V_135 ) ;
for ( V_9 = 0 ; V_9 < V_129 ; V_9 ++ ) {
V_130 =
F_53 ( V_21 -> V_78 [ V_9 ] ) |
( ( F_36 ( V_21 -> V_78 [ V_9 ] ) & V_132 ) <<
V_133 ) ;
F_54 ( V_130 , V_2 -> V_11 + V_136 ) ;
}
F_23 ( V_129 - 1 , V_2 -> V_11 + V_135 ) ;
F_30 ( & V_2 -> V_63 , V_131 ) ;
return;
}
static int F_55 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_16 * V_17 = V_2 -> V_18 ;
int V_102 , V_108 ;
struct V_52 * V_22 = V_15 -> V_22 ;
const struct V_20 * V_21 = & V_22 -> V_21 ;
if ( V_21 -> V_37 & ( V_137 | V_138 ) )
V_17 -> V_39 &= ~ V_55 ;
else
V_17 -> V_39 |= V_17 -> V_139 ;
if ( V_21 -> V_37 & V_137 ) {
V_17 -> V_39 &= ~ V_140 ;
} else {
V_17 -> V_39 |= V_140 ;
}
if ( V_21 -> V_24 == V_25 )
V_17 -> V_26 = V_21 -> V_97 * V_21 -> V_80 ;
F_24 ( V_2 , V_15 ) ;
V_102 = F_44 ( V_21 ) ;
V_108 = F_45 ( V_21 ) ;
F_52 ( V_2 , V_21 ) ;
F_47 ( V_2 , V_21 ) ;
F_51 ( V_2 , V_21 ) ;
F_23 ( V_108 , V_2 -> V_11 + V_12 ) ;
if ( V_108 & V_117 ) {
F_23 ( V_21 -> V_71 / 1000 - 1 ,
V_2 -> V_11 + V_141 ) ;
F_23 ( V_21 -> V_80 - 1 , V_2 -> V_11 + V_142 ) ;
}
F_23 ( V_17 -> V_39 , V_2 -> V_11 + V_49 ) ;
F_23 ( V_102 , V_2 -> V_11 + V_50 ) ;
F_23 ( V_143 , V_2 -> V_11 + V_30 ) ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_144 * V_145 , unsigned int * V_146 )
{
const struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_9 , V_129 ;
int V_147 , V_148 , V_109 , V_130 ;
int V_149 = 1000 ;
unsigned short V_29 ;
int V_150 = 0 ;
unsigned long V_131 ;
V_109 = F_46 ( V_145 -> V_151 ) ;
V_150 |= V_110 ;
if ( V_109 != V_111 )
V_150 |= V_112 ;
if ( V_109 == V_113 )
V_150 |= V_114 ;
if ( F_36 ( V_145 -> V_151 ) & V_79 )
V_150 |= V_13 ;
F_23 ( V_150 , V_2 -> V_11 + V_12 ) ;
F_23 ( V_143 , V_2 -> V_11 + V_30 ) ;
F_23 ( 0x0 , V_2 -> V_11 + V_50 ) ;
F_23 ( V_103 , V_2 -> V_11 + V_50 ) ;
V_147 = F_53 ( V_145 -> V_151 ) ;
V_148 = F_36 ( V_145 -> V_151 ) & 0x3 ;
V_130 = V_147 | ( V_148 << 8 ) ;
F_29 ( & V_2 -> V_63 , V_131 ) ;
F_23 ( V_134 , V_2 -> V_11 + V_54 ) ;
F_23 ( 0x0 , V_2 -> V_11 + V_135 ) ;
F_54 ( V_130 , V_2 -> V_11 + V_136 ) ;
F_23 ( 0x0 , V_2 -> V_11 + V_135 ) ;
F_23 ( V_53 , V_2 -> V_11 + V_54 ) ;
for ( V_129 = 0 ; V_129 < V_145 -> V_129 ; V_129 ++ ) {
F_23 ( 0 , V_2 -> V_11 + V_27 ) ;
for ( V_9 = 0 ; V_9 < V_149 ; V_9 ++ ) {
if ( F_4 ( V_2 -> V_11 + V_30 ) & V_31 )
break;
}
if ( V_9 == V_149 ) {
F_26 ( V_2 , L_4 ) ;
V_129 = - V_152 ;
goto exit;
}
V_29 = F_9 ( V_2 -> V_11 + V_27 ) ;
if ( ( V_150 & V_13 ) == 0 )
V_29 += 1 << ( V_5 -> V_6 - 1 ) ;
V_146 [ V_129 ] = V_29 ;
}
exit:
F_30 ( & V_2 -> V_63 , V_131 ) ;
return V_129 ;
}
static int F_57 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_144 * V_145 , unsigned int * V_146 )
{
const struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_16 * V_17 = V_2 -> V_18 ;
int V_147 = F_53 ( V_145 -> V_151 ) ;
int V_153 = V_5 -> V_154 - 1 ;
unsigned short V_155 ;
unsigned long V_131 ;
V_155 = V_146 [ 0 ] - ( 1 << ( V_5 -> V_6 - 1 ) ) ;
if ( V_147 == V_153 )
V_17 -> V_156 = V_155 ;
F_29 ( & V_2 -> V_63 , V_131 ) ;
F_23 ( F_58 ( V_147 ) , V_2 -> V_11 + V_54 ) ;
F_54 ( V_155 , V_2 -> V_11 + V_157 ) ;
if ( V_147 != V_153 ) {
F_23 ( F_58 ( V_153 ) , V_2 -> V_11 + V_54 ) ;
F_54 ( V_17 -> V_156 , V_2 -> V_11 + V_157 ) ;
}
F_30 ( & V_2 -> V_63 , V_131 ) ;
return 1 ;
}
static int F_59 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_144 * V_145 , unsigned int * V_146 )
{
V_146 [ 1 ] = F_4 ( V_2 -> V_11 + V_158 ) & 0xf ;
V_146 [ 0 ] = 0 ;
return V_145 -> V_129 ;
}
static int F_60 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_144 * V_145 ,
unsigned int * V_146 )
{
if ( F_61 ( V_15 , V_146 ) )
F_23 ( V_15 -> V_159 , V_2 -> V_11 + V_158 ) ;
V_146 [ 1 ] = V_15 -> V_159 ;
return V_145 -> V_129 ;
}
static int F_62 ( struct V_1 * V_2 , unsigned int V_43 ,
unsigned int V_44 )
{
struct V_16 * V_17 = V_2 -> V_18 ;
unsigned long V_37 ;
if ( V_2 -> V_66 && V_43 ) {
switch ( ( V_43 & 0x7 ) | ( V_44 << 4 ) ) {
case 0x5 :
V_17 -> V_139 |= V_160 ;
break;
case 0x6 :
V_17 -> V_139 |= V_161 ;
break;
case 0x7 :
V_17 -> V_139 |= V_162 ;
break;
case 0x65 :
V_17 -> V_139 |= V_163 ;
break;
case 0x76 :
V_17 -> V_139 |= V_164 ;
break;
case 0x57 :
V_17 -> V_139 |= V_165 ;
break;
default:
F_63 ( V_2 -> V_81 ,
L_5 ) ;
F_63 ( V_2 -> V_81 ,
L_6 ) ;
F_63 ( V_2 -> V_81 ,
L_7 ) ;
return - V_82 ;
break;
}
if ( F_64 ( V_43 , V_2 -> V_166 -> V_167 ) ) {
F_63 ( V_2 -> V_81 ,
L_8 , V_43 ) ;
return - V_82 ;
}
V_17 -> V_43 = V_43 ;
V_17 -> V_41 = V_43 ;
if ( V_44 ) {
if ( F_64 ( V_44 , V_2 -> V_166 -> V_167 ) ) {
F_63 ( V_2 -> V_81 ,
L_8 ,
V_44 ) ;
return - V_82 ;
}
V_17 -> V_44 = V_44 ;
}
V_17 -> V_28 = F_65 ( V_124 , V_168 | V_169 ) ;
if ( V_17 -> V_28 == NULL )
return - V_170 ;
V_17 -> V_42 = V_17 -> V_28 ;
if ( V_44 ) {
V_17 -> V_45 =
F_65 ( V_124 , V_168 | V_169 ) ;
if ( V_17 -> V_45 == NULL )
return - V_170 ;
}
V_37 = F_16 () ;
F_12 ( V_17 -> V_43 ) ;
F_66 ( V_17 -> V_43 , V_171 ) ;
if ( V_44 ) {
F_12 ( V_17 -> V_44 ) ;
F_66 ( V_17 -> V_44 , V_171 ) ;
}
F_17 ( V_37 ) ;
}
return 0 ;
}
static int F_67 ( struct V_1 * V_2 )
{
int V_172 ;
int V_173 ;
V_172 = ( F_4 ( V_2 -> V_11 + V_158 ) >> 4 ) & 0xf ;
V_173 = ( (struct V_4 * ) V_2 -> V_174 ) - V_175 ;
switch ( V_172 ) {
case 0x3 :
if ( V_173 == V_176 || V_173 == V_177 ||
V_173 == V_178 || V_173 == V_179 ) {
F_37 ( V_2 -> V_81 , L_9 ,
V_175 [ V_173 ] . V_180 ) ;
return V_173 ;
}
F_68
( L_10 ) ;
return V_181 ;
break;
case 0x4 :
if ( V_173 == V_182 || V_173 == V_183 ) {
F_37 ( V_2 -> V_81 , L_9 ,
V_175 [ V_173 ] . V_180 ) ;
return V_173 ;
}
F_68
( L_11 ) ;
return V_184 ;
break;
case 0x5 :
if ( V_173 == V_185 || V_173 == V_186 ||
V_173 == V_187 || V_173 == V_188 ) {
F_37 ( V_2 -> V_81 , L_9 ,
V_175 [ V_173 ] . V_180 ) ;
return V_173 ;
}
F_68
( L_12 ) ;
return V_185 ;
break;
case 0x6 :
if ( V_173 == V_184 || V_173 == V_189 ) {
F_37 ( V_2 -> V_81 , L_9 ,
V_175 [ V_173 ] . V_180 ) ;
return V_173 ;
}
F_68
( L_13 ) ;
return V_184 ;
break;
case 0x7 :
if ( V_173 == V_181 || V_173 == V_190 ||
V_173 == V_191 || V_173 == V_192 ) {
F_37 ( V_2 -> V_81 , L_9 ,
V_175 [ V_173 ] . V_180 ) ;
return V_173 ;
}
F_68
( L_14 ) ;
return V_181 ;
break;
case 0x8 :
if ( V_173 == V_193 || V_173 == V_194 ) {
F_37 ( V_2 -> V_81 , L_9 ,
V_175 [ V_173 ] . V_180 ) ;
return V_173 ;
}
F_68
( L_15 ) ;
return V_193 ;
break;
default:
F_68
( L_16 ,
V_172 ) ;
return V_173 ;
break;
}
return - 1 ;
}
static int F_69 ( struct V_1 * V_2 ,
struct V_195 * V_196 )
{
const struct V_4 * V_5 ;
struct V_16 * V_17 ;
struct V_14 * V_15 ;
unsigned int V_66 = V_196 -> V_197 [ 1 ] ;
unsigned int V_43 = V_196 -> V_197 [ 2 ] ;
unsigned int V_44 = V_196 -> V_197 [ 3 ] ;
int V_173 ;
int V_198 ;
V_17 = F_70 ( V_2 , sizeof( * V_17 ) ) ;
if ( ! V_17 )
return - V_170 ;
V_198 = F_71 ( V_2 , V_196 -> V_197 [ 0 ] , V_199 ) ;
if ( V_198 )
return V_198 ;
V_173 = F_67 ( V_2 ) ;
if ( V_173 < 0 ) {
F_63 ( V_2 -> V_81 , L_17 ) ;
return - V_200 ;
}
V_2 -> V_174 = V_175 + V_173 ;
V_5 = F_2 ( V_2 ) ;
V_2 -> V_201 = V_5 -> V_180 ;
if ( V_5 -> V_202 == 2 ) {
unsigned long V_203 = V_2 -> V_11 + V_204 ;
V_198 = F_72 ( V_2 , V_203 , V_199 ) ;
if ( V_198 )
return V_198 ;
V_17 -> V_203 = V_203 ;
}
if ( V_66 == 3 || V_66 == 5 || V_66 == 7 || V_66 == 10 || V_66 == 11 ||
V_66 == 15 ) {
V_198 = F_73 ( V_66 , F_31 , 0 ,
V_2 -> V_201 , V_2 ) ;
if ( V_198 == 0 ) {
V_2 -> V_66 = V_66 ;
switch ( V_66 ) {
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
}
}
}
V_198 = F_62 ( V_2 , V_43 , V_44 ) ;
if ( V_198 < 0 )
return V_198 ;
if ( V_17 -> V_28 == NULL ) {
V_17 -> V_28 =
F_65 ( V_23 * sizeof( T_1 ) , V_168 ) ;
if ( V_17 -> V_28 == NULL )
return - V_170 ;
}
V_198 = F_74 ( V_2 , 4 ) ;
if ( V_198 )
return V_198 ;
V_15 = & V_2 -> V_205 [ 0 ] ;
V_15 -> type = V_206 ;
V_15 -> V_207 = V_208 | V_209 | V_210 ;
if ( V_5 -> V_211 )
V_15 -> V_207 |= V_212 ;
V_15 -> V_213 = V_5 -> V_214 ;
V_15 -> V_215 = ( 1 << V_5 -> V_6 ) - 1 ;
V_15 -> V_216 = V_5 -> V_217 ;
V_15 -> V_218 = F_56 ;
if ( V_2 -> V_66 ) {
V_2 -> V_51 = V_15 ;
V_15 -> V_207 |= V_219 ;
V_15 -> V_220 = V_15 -> V_213 ;
V_15 -> V_221 = F_55 ;
V_15 -> V_222 = F_38 ;
V_15 -> V_223 = F_28 ;
V_15 -> V_224 = F_24 ;
}
V_15 = & V_2 -> V_205 [ 1 ] ;
if ( V_5 -> V_202 == 1 ) {
V_15 -> type = V_225 ;
V_15 -> V_207 = V_226 ;
V_15 -> V_213 = V_5 -> V_154 ;
V_15 -> V_215 = ( 1 << V_5 -> V_6 ) - 1 ;
V_15 -> V_216 = & V_227 ;
V_15 -> V_228 = F_57 ;
} else {
V_15 -> type = V_229 ;
}
V_15 = & V_2 -> V_205 [ 2 ] ;
V_15 -> type = V_230 ;
V_15 -> V_207 = V_208 ;
V_15 -> V_213 = 4 ;
V_15 -> V_215 = 1 ;
V_15 -> V_216 = & V_231 ;
V_15 -> V_232 = F_59 ;
V_15 = & V_2 -> V_205 [ 3 ] ;
V_15 -> type = V_233 ;
V_15 -> V_207 = V_226 | V_208 ;
V_15 -> V_213 = V_5 -> V_234 ;
V_15 -> V_215 = 1 ;
V_15 -> V_216 = & V_231 ;
V_15 -> V_232 = F_60 ;
F_24 ( V_2 , V_2 -> V_51 ) ;
F_23 ( 0 , V_2 -> V_11 + V_158 ) ;
if ( V_5 -> V_202 == 1 ) {
F_23 ( F_58 ( V_5 -> V_154 - 1 ) ,
V_2 -> V_11 + V_54 ) ;
F_54 ( V_17 -> V_156 , V_2 -> V_11 + V_157 ) ;
}
return 0 ;
}
static void F_75 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = V_2 -> V_18 ;
if ( V_17 ) {
if ( V_17 -> V_43 )
F_76 ( V_17 -> V_43 ) ;
if ( V_17 -> V_44 )
F_76 ( V_17 -> V_44 ) ;
F_77 ( V_17 -> V_28 ) ;
F_77 ( V_17 -> V_45 ) ;
if ( V_17 -> V_203 )
F_78 ( V_17 -> V_203 , V_199 ) ;
}
F_79 ( V_2 ) ;
}
