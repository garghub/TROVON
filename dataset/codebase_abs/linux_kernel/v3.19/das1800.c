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
unsigned int V_20 = F_5 ( V_16 , V_21 / 2 ) ;
F_6 ( V_2 -> V_12 + V_22 , V_18 -> V_23 , V_20 ) ;
F_2 ( V_2 , V_18 -> V_23 , V_20 ) ;
F_7 ( V_16 , V_18 -> V_23 , V_20 ) ;
}
static void F_8 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
struct V_24 * V_25 = & V_16 -> V_26 -> V_25 ;
unsigned short V_27 ;
int V_11 ;
V_11 = F_3 ( V_2 -> V_12 + V_13 ) & V_14 ;
while ( F_3 ( V_2 -> V_12 + V_28 ) & V_29 ) {
V_27 = F_9 ( V_2 -> V_12 + V_22 ) ;
if ( ! V_11 )
;
V_27 = F_1 ( V_2 , V_27 ) ;
F_7 ( V_16 , & V_27 , 1 ) ;
if ( V_25 -> V_30 == V_31 &&
V_16 -> V_26 -> V_32 >= V_25 -> V_33 )
break;
}
}
static void F_10 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
unsigned int V_34 , T_1 * V_35 )
{
struct V_17 * V_18 = V_2 -> V_19 ;
unsigned int V_36 ;
unsigned int V_20 ;
F_11 ( V_34 ) ;
F_12 ( V_34 ) ;
V_36 = V_18 -> V_37 - F_13 ( V_34 ) ;
V_20 = F_14 ( V_16 , V_36 ) ;
V_20 = F_5 ( V_16 , V_20 ) ;
F_2 ( V_2 , V_35 , V_20 ) ;
F_7 ( V_16 , V_35 , V_20 ) ;
}
static void F_15 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
struct V_17 * V_18 = V_2 -> V_19 ;
unsigned long V_38 ;
const int V_39 = V_18 -> V_40 & V_41 ;
V_38 = F_16 () ;
F_10 ( V_2 , V_16 , V_18 -> V_42 ,
V_18 -> V_43 ) ;
if ( V_39 ) {
if ( V_18 -> V_42 == V_18 -> V_44 ) {
V_18 -> V_42 = V_18 -> V_45 ;
V_18 -> V_43 = V_18 -> V_46 ;
} else {
V_18 -> V_42 = V_18 -> V_44 ;
V_18 -> V_43 = V_18 -> V_23 ;
}
F_10 ( V_2 , V_16 , V_18 -> V_42 ,
V_18 -> V_43 ) ;
}
F_17 ( V_38 ) ;
F_8 ( V_2 , V_16 ) ;
}
static void F_18 ( struct V_1 * V_2 ,
struct V_15 * V_16 , unsigned int V_47 )
{
struct V_17 * V_18 = V_2 -> V_19 ;
unsigned long V_38 ;
const int V_39 = V_18 -> V_40 & V_41 ;
V_38 = F_16 () ;
F_10 ( V_2 , V_16 , V_18 -> V_42 ,
V_18 -> V_43 ) ;
F_19 ( V_18 -> V_42 ,
F_20 ( V_18 -> V_43 ) ) ;
F_21 ( V_18 -> V_42 , V_18 -> V_37 ) ;
F_22 ( V_18 -> V_42 ) ;
F_17 ( V_38 ) ;
if ( V_47 & V_48 ) {
F_23 ( V_49 & ~ V_48 , V_2 -> V_12 + V_28 ) ;
if ( V_39 ) {
if ( V_18 -> V_42 == V_18 -> V_44 ) {
V_18 -> V_42 = V_18 -> V_45 ;
V_18 -> V_43 = V_18 -> V_46 ;
} else {
V_18 -> V_42 = V_18 -> V_44 ;
V_18 -> V_43 = V_18 -> V_23 ;
}
}
}
}
static int F_24 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
struct V_17 * V_18 = V_2 -> V_19 ;
F_23 ( 0x0 , V_2 -> V_12 + V_28 ) ;
F_23 ( 0x0 , V_2 -> V_12 + V_50 ) ;
F_23 ( 0x0 , V_2 -> V_12 + V_51 ) ;
if ( V_18 -> V_44 )
F_11 ( V_18 -> V_44 ) ;
if ( V_18 -> V_45 )
F_11 ( V_18 -> V_45 ) ;
return 0 ;
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_19 ;
struct V_15 * V_16 = V_2 -> V_52 ;
struct V_53 * V_26 = V_16 -> V_26 ;
struct V_24 * V_25 = & V_26 -> V_25 ;
unsigned int V_47 = F_3 ( V_2 -> V_12 + V_28 ) ;
F_23 ( V_54 , V_2 -> V_12 + V_55 ) ;
if ( V_18 -> V_40 & V_56 ) {
F_18 ( V_2 , V_16 , V_47 ) ;
} else if ( V_47 & V_57 ) {
F_4 ( V_2 , V_16 ) ;
} else if ( V_47 & V_29 ) {
F_8 ( V_2 , V_16 ) ;
}
if ( V_47 & V_58 ) {
F_23 ( V_49 & ~ V_58 , V_2 -> V_12 + V_28 ) ;
F_26 ( V_2 -> V_59 , L_1 ) ;
V_26 -> V_60 |= V_61 | V_62 ;
F_27 ( V_2 , V_16 ) ;
return;
}
if ( V_47 & V_63 ) {
F_23 ( V_49 & ~ V_63 , V_2 -> V_12 + V_28 ) ;
if ( V_18 -> V_40 & V_56 )
F_15 ( V_2 , V_16 ) ;
else
F_8 ( V_2 , V_16 ) ;
V_26 -> V_60 |= V_62 ;
} else if ( V_25 -> V_30 == V_31 &&
V_26 -> V_32 >= V_25 -> V_33 ) {
V_26 -> V_60 |= V_62 ;
}
F_27 ( V_2 , V_16 ) ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
unsigned long V_38 ;
F_29 ( & V_2 -> V_64 , V_38 ) ;
F_25 ( V_2 ) ;
F_30 ( & V_2 -> V_64 , V_38 ) ;
return F_31 ( V_16 ) ;
}
static T_2 F_32 ( int V_65 , void * V_66 )
{
struct V_1 * V_2 = V_66 ;
unsigned int V_47 ;
if ( ! V_2 -> V_67 ) {
F_26 ( V_2 -> V_59 , L_2 ) ;
return V_68 ;
}
F_33 ( & V_2 -> V_64 ) ;
V_47 = F_3 ( V_2 -> V_12 + V_28 ) ;
if ( ! ( V_47 & INT ) ) {
F_34 ( & V_2 -> V_64 ) ;
return V_69 ;
}
F_23 ( V_49 & ~ INT , V_2 -> V_12 + V_28 ) ;
F_25 ( V_2 ) ;
F_34 ( & V_2 -> V_64 ) ;
return V_68 ;
}
static unsigned int F_35 ( unsigned int V_70 , int V_38 )
{
unsigned int V_71 ;
if ( V_70 > 64000 )
V_70 = 64000 ;
switch ( V_38 & V_72 ) {
case V_73 :
default:
V_71 = ( V_70 + 500 ) / 1000 ;
break;
case V_74 :
V_71 = V_70 / 1000 ;
break;
case V_75 :
V_71 = ( V_70 - 1 ) / 1000 + 1 ;
break;
}
return V_71 * 1000 ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_24 * V_25 )
{
unsigned int V_76 = F_37 ( V_25 -> V_77 [ 0 ] ) & V_78 ;
int V_10 ;
for ( V_10 = 1 ; V_10 < V_25 -> V_79 ; V_10 ++ ) {
unsigned int V_11 = F_37 ( V_25 -> V_77 [ V_10 ] ) & V_78 ;
if ( V_11 != V_76 ) {
F_38 ( V_2 -> V_59 ,
L_3 ) ;
return - V_80 ;
}
}
return 0 ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_24 * V_25 )
{
const struct V_4 * V_5 = V_2 -> V_6 ;
struct V_17 * V_18 = V_2 -> V_19 ;
int V_81 = 0 ;
unsigned int V_82 ;
V_81 |= F_40 ( & V_25 -> V_83 , V_84 | V_85 ) ;
V_81 |= F_40 ( & V_25 -> V_86 ,
V_87 | V_88 | V_85 ) ;
V_81 |= F_40 ( & V_25 -> V_89 , V_88 | V_85 ) ;
V_81 |= F_40 ( & V_25 -> V_90 , V_31 ) ;
V_81 |= F_40 ( & V_25 -> V_30 ,
V_31 | V_85 | V_91 ) ;
if ( V_81 )
return 1 ;
V_81 |= F_41 ( V_25 -> V_83 ) ;
V_81 |= F_41 ( V_25 -> V_86 ) ;
V_81 |= F_41 ( V_25 -> V_89 ) ;
V_81 |= F_41 ( V_25 -> V_30 ) ;
if ( V_25 -> V_86 != V_87 &&
V_25 -> V_89 != V_88 )
V_81 |= - V_80 ;
if ( V_81 )
return 2 ;
V_81 |= F_42 ( & V_25 -> V_92 , 0 ) ;
if ( V_25 -> V_89 == V_88 )
V_81 |= F_43 ( & V_25 -> V_70 ,
V_5 -> V_93 ) ;
V_81 |= F_43 ( & V_25 -> V_79 , 1 ) ;
V_81 |= F_42 ( & V_25 -> V_94 , V_25 -> V_79 ) ;
switch ( V_25 -> V_30 ) {
case V_31 :
V_81 |= F_43 ( & V_25 -> V_33 , 1 ) ;
break;
case V_91 :
V_81 |= F_42 ( & V_25 -> V_33 , 0 ) ;
break;
default:
break;
}
if ( V_81 )
return 3 ;
if ( V_25 -> V_86 == V_87 &&
V_25 -> V_89 == V_88 ) {
V_82 = V_25 -> V_70 ;
F_44 ( V_95 ,
& V_18 -> V_96 ,
& V_18 -> V_97 ,
& V_25 -> V_70 , V_25 -> V_38 ) ;
if ( V_82 != V_25 -> V_70 )
V_81 ++ ;
} else if ( V_25 -> V_89 == V_88 ) {
V_82 = V_25 -> V_70 ;
V_25 -> V_70 = F_35 ( V_25 -> V_70 ,
V_25 -> V_38 ) ;
if ( V_82 != V_25 -> V_70 )
V_81 ++ ;
if ( V_25 -> V_86 == V_88 ) {
V_82 = V_25 -> V_70 * V_25 -> V_79 ;
if ( V_82 > V_25 -> V_98 ) {
V_25 -> V_98 = V_82 ;
V_81 ++ ;
}
V_82 = V_25 -> V_98 ;
F_44 ( V_95 ,
& V_18 -> V_96 ,
& V_18 -> V_97 ,
& V_25 -> V_98 ,
V_25 -> V_38 ) ;
if ( V_82 != V_25 -> V_98 )
V_81 ++ ;
}
}
if ( V_81 )
return 4 ;
if ( V_25 -> V_77 && V_25 -> V_79 > 0 )
V_81 |= F_36 ( V_2 , V_16 , V_25 ) ;
if ( V_81 )
return 5 ;
return 0 ;
}
static int F_45 ( const struct V_24 * V_25 )
{
int V_99 ;
V_99 = V_100 ;
if ( V_25 -> V_30 == V_85 )
V_99 |= V_101 ;
switch ( V_25 -> V_83 ) {
case V_85 :
V_99 |= V_102 | V_103 ;
break;
case V_84 :
V_99 |= V_104 ;
break;
default:
break;
}
return V_99 ;
}
static int F_46 ( const struct V_24 * V_25 )
{
int V_105 ;
int V_106 ;
V_106 = F_47 ( V_25 -> V_77 [ 0 ] ) ;
V_105 = V_107 ;
if ( V_106 != V_108 )
V_105 |= V_109 ;
if ( V_106 == V_110 )
V_105 |= V_111 ;
if ( F_37 ( V_25 -> V_77 [ 0 ] ) & V_78 )
V_105 |= V_14 ;
switch ( V_25 -> V_86 ) {
case V_87 :
switch ( V_25 -> V_89 ) {
case V_88 :
V_105 |= V_112 ;
break;
case V_85 :
V_105 |= V_113 ;
break;
default:
break;
}
break;
case V_88 :
V_105 |= V_114 | V_112 ;
break;
case V_85 :
V_105 |= V_114 | V_113 ;
break;
default:
break;
}
return V_105 ;
}
static void F_48 ( struct V_1 * V_2 ,
const struct V_24 * V_25 )
{
struct V_17 * V_18 = V_2 -> V_19 ;
unsigned long V_115 = V_2 -> V_12 + V_116 ;
if ( ( V_25 -> V_86 == V_87 ||
V_25 -> V_86 == V_88 ) &&
V_25 -> V_89 == V_88 ) {
F_49 ( V_115 , 0 , 1 , V_117 | V_118 ) ;
F_49 ( V_115 , 0 , 2 , V_117 | V_118 ) ;
F_50 ( V_115 , 0 , 1 , V_18 -> V_96 ) ;
F_50 ( V_115 , 0 , 2 , V_18 -> V_97 ) ;
}
if ( V_25 -> V_30 == V_85 ) {
F_49 ( V_115 , 0 , 0 , V_119 | V_118 ) ;
F_50 ( V_115 , 0 , 0 , 1 ) ;
}
}
static unsigned int F_51 ( const struct V_24 * V_25 )
{
unsigned int V_120 = V_121 ;
static const int V_122 = 2 ;
unsigned int V_123 = 300000000 ;
unsigned int V_124 ;
switch ( V_25 -> V_86 ) {
case V_87 :
if ( V_25 -> V_89 == V_88 )
V_120 = ( V_123 / V_25 -> V_70 ) * V_122 ;
break;
case V_88 :
V_120 = ( V_123 / ( V_25 -> V_98 * V_25 -> V_79 ) ) *
V_122 ;
break;
default:
V_120 = V_121 ;
break;
}
V_124 = V_121 ;
if ( V_25 -> V_30 == V_31 &&
V_25 -> V_33 * V_25 -> V_79 * V_122 < V_124 )
V_124 = V_25 -> V_33 * V_25 -> V_79 * V_122 ;
if ( V_120 > V_124 )
V_120 = V_124 ;
if ( V_120 < V_122 )
V_120 = V_122 ;
return V_120 ;
}
static void F_52 ( struct V_1 * V_2 , const struct V_24 * V_25 )
{
struct V_17 * V_18 = V_2 -> V_19 ;
unsigned long V_125 ;
const int V_39 = V_18 -> V_40 & V_41 ;
if ( ( V_18 -> V_40 & V_56 ) == 0 )
return;
V_18 -> V_37 = F_51 ( V_25 ) ;
V_125 = F_16 () ;
F_11 ( V_18 -> V_44 ) ;
F_12 ( V_18 -> V_44 ) ;
F_19 ( V_18 -> V_44 , F_20 ( V_18 -> V_23 ) ) ;
F_21 ( V_18 -> V_44 , V_18 -> V_37 ) ;
V_18 -> V_42 = V_18 -> V_44 ;
V_18 -> V_43 = V_18 -> V_23 ;
F_22 ( V_18 -> V_44 ) ;
if ( V_39 ) {
F_11 ( V_18 -> V_45 ) ;
F_12 ( V_18 -> V_45 ) ;
F_19 ( V_18 -> V_45 , F_20 ( V_18 -> V_46 ) ) ;
F_21 ( V_18 -> V_45 , V_18 -> V_37 ) ;
F_22 ( V_18 -> V_45 ) ;
}
F_17 ( V_125 ) ;
}
static void F_53 ( struct V_1 * V_2 ,
const struct V_24 * V_25 )
{
int V_10 , V_126 , V_127 ;
unsigned long V_128 ;
const int V_129 = 0x3 ;
const int V_130 = 8 ;
V_126 = V_25 -> V_79 ;
F_29 ( & V_2 -> V_64 , V_128 ) ;
F_23 ( V_131 , V_2 -> V_12 + V_55 ) ;
F_23 ( V_126 - 1 , V_2 -> V_12 + V_132 ) ;
for ( V_10 = 0 ; V_10 < V_126 ; V_10 ++ ) {
V_127 =
F_54 ( V_25 -> V_77 [ V_10 ] ) |
( ( F_37 ( V_25 -> V_77 [ V_10 ] ) & V_129 ) <<
V_130 ) ;
F_55 ( V_127 , V_2 -> V_12 + V_133 ) ;
}
F_23 ( V_126 - 1 , V_2 -> V_12 + V_132 ) ;
F_30 ( & V_2 -> V_64 , V_128 ) ;
}
static int F_56 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
struct V_17 * V_18 = V_2 -> V_19 ;
int V_99 , V_105 ;
struct V_53 * V_26 = V_16 -> V_26 ;
const struct V_24 * V_25 = & V_26 -> V_25 ;
if ( V_25 -> V_38 & ( V_134 | V_135 ) )
V_18 -> V_40 &= ~ V_56 ;
else
V_18 -> V_40 |= V_18 -> V_136 ;
if ( V_25 -> V_38 & V_134 ) {
V_18 -> V_40 &= ~ V_137 ;
} else {
V_18 -> V_40 |= V_137 ;
}
F_24 ( V_2 , V_16 ) ;
V_99 = F_45 ( V_25 ) ;
V_105 = F_46 ( V_25 ) ;
F_53 ( V_2 , V_25 ) ;
F_48 ( V_2 , V_25 ) ;
F_52 ( V_2 , V_25 ) ;
F_23 ( V_105 , V_2 -> V_12 + V_13 ) ;
if ( V_105 & V_114 ) {
F_23 ( V_25 -> V_70 / 1000 - 1 ,
V_2 -> V_12 + V_138 ) ;
F_23 ( V_25 -> V_79 - 1 , V_2 -> V_12 + V_139 ) ;
}
F_23 ( V_18 -> V_40 , V_2 -> V_12 + V_50 ) ;
F_23 ( V_99 , V_2 -> V_12 + V_51 ) ;
F_23 ( V_140 , V_2 -> V_12 + V_28 ) ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_141 * V_142 , unsigned int * V_143 )
{
const struct V_4 * V_5 = V_2 -> V_6 ;
int V_10 , V_126 ;
int V_144 , V_145 , V_106 , V_127 ;
int V_146 = 1000 ;
unsigned short V_27 ;
int V_147 = 0 ;
unsigned long V_128 ;
V_106 = F_47 ( V_142 -> V_148 ) ;
V_147 |= V_107 ;
if ( V_106 != V_108 )
V_147 |= V_109 ;
if ( V_106 == V_110 )
V_147 |= V_111 ;
if ( F_37 ( V_142 -> V_148 ) & V_78 )
V_147 |= V_14 ;
F_23 ( V_147 , V_2 -> V_12 + V_13 ) ;
F_23 ( V_140 , V_2 -> V_12 + V_28 ) ;
F_23 ( 0x0 , V_2 -> V_12 + V_51 ) ;
F_23 ( V_100 , V_2 -> V_12 + V_51 ) ;
V_144 = F_54 ( V_142 -> V_148 ) ;
V_145 = F_37 ( V_142 -> V_148 ) & 0x3 ;
V_127 = V_144 | ( V_145 << 8 ) ;
F_29 ( & V_2 -> V_64 , V_128 ) ;
F_23 ( V_131 , V_2 -> V_12 + V_55 ) ;
F_23 ( 0x0 , V_2 -> V_12 + V_132 ) ;
F_55 ( V_127 , V_2 -> V_12 + V_133 ) ;
F_23 ( 0x0 , V_2 -> V_12 + V_132 ) ;
F_23 ( V_54 , V_2 -> V_12 + V_55 ) ;
for ( V_126 = 0 ; V_126 < V_142 -> V_126 ; V_126 ++ ) {
F_23 ( 0 , V_2 -> V_12 + V_22 ) ;
for ( V_10 = 0 ; V_10 < V_146 ; V_10 ++ ) {
if ( F_3 ( V_2 -> V_12 + V_28 ) & V_29 )
break;
}
if ( V_10 == V_146 ) {
F_26 ( V_2 -> V_59 , L_4 ) ;
V_126 = - V_149 ;
goto exit;
}
V_27 = F_9 ( V_2 -> V_12 + V_22 ) ;
if ( ( V_147 & V_14 ) == 0 )
V_27 += 1 << ( V_5 -> V_7 - 1 ) ;
V_143 [ V_126 ] = V_27 ;
}
exit:
F_30 ( & V_2 -> V_64 , V_128 ) ;
return V_126 ;
}
static int F_58 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_141 * V_142 , unsigned int * V_143 )
{
const struct V_4 * V_5 = V_2 -> V_6 ;
struct V_17 * V_18 = V_2 -> V_19 ;
int V_144 = F_54 ( V_142 -> V_148 ) ;
int V_150 = V_5 -> V_151 - 1 ;
unsigned short V_152 ;
unsigned long V_128 ;
V_152 = V_143 [ 0 ] - ( 1 << ( V_5 -> V_7 - 1 ) ) ;
if ( V_144 == V_150 )
V_18 -> V_153 = V_152 ;
F_29 ( & V_2 -> V_64 , V_128 ) ;
F_23 ( F_59 ( V_144 ) , V_2 -> V_12 + V_55 ) ;
F_55 ( V_152 , V_2 -> V_12 + V_154 ) ;
if ( V_144 != V_150 ) {
F_23 ( F_59 ( V_150 ) , V_2 -> V_12 + V_55 ) ;
F_55 ( V_18 -> V_153 , V_2 -> V_12 + V_154 ) ;
}
F_30 ( & V_2 -> V_64 , V_128 ) ;
return 1 ;
}
static int F_60 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_141 * V_142 , unsigned int * V_143 )
{
V_143 [ 1 ] = F_3 ( V_2 -> V_12 + V_155 ) & 0xf ;
V_143 [ 0 ] = 0 ;
return V_142 -> V_126 ;
}
static int F_61 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_141 * V_142 ,
unsigned int * V_143 )
{
if ( F_62 ( V_16 , V_143 ) )
F_23 ( V_16 -> V_156 , V_2 -> V_12 + V_155 ) ;
V_143 [ 1 ] = V_16 -> V_156 ;
return V_142 -> V_126 ;
}
static int F_63 ( struct V_1 * V_2 , unsigned int V_44 ,
unsigned int V_45 )
{
struct V_17 * V_18 = V_2 -> V_19 ;
unsigned long V_38 ;
if ( V_2 -> V_65 && V_44 ) {
switch ( ( V_44 & 0x7 ) | ( V_45 << 4 ) ) {
case 0x5 :
V_18 -> V_136 |= V_157 ;
break;
case 0x6 :
V_18 -> V_136 |= V_158 ;
break;
case 0x7 :
V_18 -> V_136 |= V_159 ;
break;
case 0x65 :
V_18 -> V_136 |= V_160 ;
break;
case 0x76 :
V_18 -> V_136 |= V_161 ;
break;
case 0x57 :
V_18 -> V_136 |= V_162 ;
break;
default:
F_26 ( V_2 -> V_59 ,
L_5 ) ;
F_26 ( V_2 -> V_59 ,
L_6 ) ;
F_26 ( V_2 -> V_59 ,
L_7 ) ;
return - V_80 ;
}
if ( F_64 ( V_44 , V_2 -> V_163 -> V_164 ) ) {
F_26 ( V_2 -> V_59 ,
L_8 , V_44 ) ;
return - V_80 ;
}
V_18 -> V_44 = V_44 ;
V_18 -> V_42 = V_44 ;
if ( V_45 ) {
if ( F_64 ( V_45 , V_2 -> V_163 -> V_164 ) ) {
F_26 ( V_2 -> V_59 ,
L_8 ,
V_45 ) ;
return - V_80 ;
}
V_18 -> V_45 = V_45 ;
}
V_18 -> V_23 = F_65 ( V_121 , V_165 | V_166 ) ;
if ( V_18 -> V_23 == NULL )
return - V_167 ;
V_18 -> V_43 = V_18 -> V_23 ;
if ( V_45 ) {
V_18 -> V_46 =
F_65 ( V_121 , V_165 | V_166 ) ;
if ( V_18 -> V_46 == NULL )
return - V_167 ;
}
V_38 = F_16 () ;
F_11 ( V_18 -> V_44 ) ;
F_66 ( V_18 -> V_44 , V_168 ) ;
if ( V_45 ) {
F_11 ( V_18 -> V_45 ) ;
F_66 ( V_18 -> V_45 , V_168 ) ;
}
F_17 ( V_38 ) ;
}
return 0 ;
}
static int F_67 ( struct V_1 * V_2 )
{
const struct V_4 * V_169 = V_2 -> V_6 ;
int V_170 ;
int V_171 ;
V_170 = V_169 - V_172 ;
V_171 = ( F_3 ( V_2 -> V_12 + V_155 ) >> 4 ) & 0xf ;
switch ( V_171 ) {
case 0x3 :
if ( V_170 == V_173 || V_170 == V_174 ||
V_170 == V_175 || V_170 == V_176 )
return V_170 ;
V_170 = V_177 ;
break;
case 0x4 :
if ( V_170 == V_178 || V_170 == V_179 )
return V_170 ;
V_170 = V_180 ;
break;
case 0x5 :
if ( V_170 == V_181 || V_170 == V_182 ||
V_170 == V_183 || V_170 == V_184 )
return V_170 ;
V_170 = V_181 ;
break;
case 0x6 :
if ( V_170 == V_180 || V_170 == V_185 )
return V_170 ;
V_170 = V_180 ;
break;
case 0x7 :
if ( V_170 == V_177 || V_170 == V_186 ||
V_170 == V_187 || V_170 == V_188 )
return V_170 ;
V_170 = V_177 ;
break;
case 0x8 :
if ( V_170 == V_189 || V_170 == V_190 )
return V_170 ;
V_170 = V_189 ;
break;
default:
F_26 ( V_2 -> V_59 ,
L_9 ,
V_171 ) ;
break;
}
F_26 ( V_2 -> V_59 ,
L_10 ,
V_172 [ V_170 ] . V_191 ) ;
return V_170 ;
}
static int F_68 ( struct V_1 * V_2 ,
struct V_192 * V_193 )
{
const struct V_4 * V_5 ;
struct V_17 * V_18 ;
struct V_15 * V_16 ;
unsigned int V_65 = V_193 -> V_194 [ 1 ] ;
unsigned int V_44 = V_193 -> V_194 [ 2 ] ;
unsigned int V_45 = V_193 -> V_194 [ 3 ] ;
int V_169 ;
int V_195 ;
V_18 = F_69 ( V_2 , sizeof( * V_18 ) ) ;
if ( ! V_18 )
return - V_167 ;
V_195 = F_70 ( V_2 , V_193 -> V_194 [ 0 ] , V_196 ) ;
if ( V_195 )
return V_195 ;
V_169 = F_67 ( V_2 ) ;
if ( V_169 < 0 ) {
F_26 ( V_2 -> V_59 , L_11 ) ;
return - V_197 ;
}
V_2 -> V_6 = V_172 + V_169 ;
V_5 = V_2 -> V_6 ;
V_2 -> V_198 = V_5 -> V_191 ;
if ( V_5 -> V_199 == 2 ) {
unsigned long V_200 = V_2 -> V_12 + V_201 ;
V_195 = F_71 ( V_2 , V_200 , V_196 ) ;
if ( V_195 )
return V_195 ;
V_18 -> V_200 = V_200 ;
}
if ( V_65 == 3 || V_65 == 5 || V_65 == 7 || V_65 == 10 || V_65 == 11 ||
V_65 == 15 ) {
V_195 = F_72 ( V_65 , F_32 , 0 ,
V_2 -> V_198 , V_2 ) ;
if ( V_195 == 0 ) {
V_2 -> V_65 = V_65 ;
switch ( V_65 ) {
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
V_195 = F_63 ( V_2 , V_44 , V_45 ) ;
if ( V_195 < 0 )
return V_195 ;
if ( V_18 -> V_23 == NULL ) {
V_18 -> V_23 =
F_65 ( V_21 * sizeof( T_1 ) , V_165 ) ;
if ( V_18 -> V_23 == NULL )
return - V_167 ;
}
V_195 = F_73 ( V_2 , 4 ) ;
if ( V_195 )
return V_195 ;
V_16 = & V_2 -> V_202 [ 0 ] ;
V_16 -> type = V_203 ;
V_16 -> V_204 = V_205 | V_206 | V_207 ;
if ( V_5 -> V_208 )
V_16 -> V_204 |= V_209 ;
V_16 -> V_210 = V_5 -> V_211 ;
V_16 -> V_212 = ( 1 << V_5 -> V_7 ) - 1 ;
V_16 -> V_213 = V_5 -> V_214 ;
V_16 -> V_215 = F_57 ;
if ( V_2 -> V_65 ) {
V_2 -> V_52 = V_16 ;
V_16 -> V_204 |= V_216 ;
V_16 -> V_217 = V_16 -> V_210 ;
V_16 -> V_218 = F_56 ;
V_16 -> V_219 = F_39 ;
V_16 -> V_220 = F_28 ;
V_16 -> V_221 = F_24 ;
}
V_16 = & V_2 -> V_202 [ 1 ] ;
if ( V_5 -> V_199 == 1 ) {
V_16 -> type = V_222 ;
V_16 -> V_204 = V_223 ;
V_16 -> V_210 = V_5 -> V_151 ;
V_16 -> V_212 = ( 1 << V_5 -> V_7 ) - 1 ;
V_16 -> V_213 = & V_224 ;
V_16 -> V_225 = F_58 ;
} else {
V_16 -> type = V_226 ;
}
V_16 = & V_2 -> V_202 [ 2 ] ;
V_16 -> type = V_227 ;
V_16 -> V_204 = V_205 ;
V_16 -> V_210 = 4 ;
V_16 -> V_212 = 1 ;
V_16 -> V_213 = & V_228 ;
V_16 -> V_229 = F_60 ;
V_16 = & V_2 -> V_202 [ 3 ] ;
V_16 -> type = V_230 ;
V_16 -> V_204 = V_223 ;
V_16 -> V_210 = V_5 -> V_231 ;
V_16 -> V_212 = 1 ;
V_16 -> V_213 = & V_228 ;
V_16 -> V_229 = F_61 ;
F_24 ( V_2 , V_2 -> V_52 ) ;
F_23 ( 0 , V_2 -> V_12 + V_155 ) ;
if ( V_5 -> V_199 == 1 ) {
F_23 ( F_59 ( V_5 -> V_151 - 1 ) ,
V_2 -> V_12 + V_55 ) ;
F_55 ( V_18 -> V_153 , V_2 -> V_12 + V_154 ) ;
}
return 0 ;
}
static void F_74 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_19 ;
if ( V_18 ) {
if ( V_18 -> V_44 )
F_75 ( V_18 -> V_44 ) ;
if ( V_18 -> V_45 )
F_75 ( V_18 -> V_45 ) ;
F_76 ( V_18 -> V_23 ) ;
F_76 ( V_18 -> V_46 ) ;
if ( V_18 -> V_200 )
F_77 ( V_18 -> V_200 , V_196 ) ;
}
F_78 ( V_2 ) ;
}
