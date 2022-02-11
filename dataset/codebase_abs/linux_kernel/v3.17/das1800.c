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
F_26 ( V_2 -> V_60 , L_1 ) ;
V_22 -> V_57 |= V_61 | V_62 ;
F_27 ( V_2 , V_15 ) ;
return;
}
if ( V_46 & V_63 ) {
F_23 ( V_48 & ~ V_63 , V_2 -> V_11 + V_30 ) ;
if ( V_17 -> V_39 & V_55 )
F_15 ( V_2 , V_15 ) ;
else
F_8 ( V_2 , V_15 ) ;
V_22 -> V_57 |= V_62 ;
} else if ( V_21 -> V_24 == V_25 && V_17 -> V_26 == 0 ) {
V_22 -> V_57 |= V_62 ;
}
F_27 ( V_2 , V_15 ) ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
unsigned long V_37 ;
F_29 ( & V_2 -> V_64 , V_37 ) ;
F_25 ( V_2 ) ;
F_30 ( & V_2 -> V_64 , V_37 ) ;
return F_31 ( V_15 ) ;
}
static T_2 F_32 ( int V_65 , void * V_66 )
{
struct V_1 * V_2 = V_66 ;
unsigned int V_46 ;
if ( ! V_2 -> V_67 ) {
F_26 ( V_2 -> V_60 , L_2 ) ;
return V_68 ;
}
F_33 ( & V_2 -> V_64 ) ;
V_46 = F_4 ( V_2 -> V_11 + V_30 ) ;
if ( ! ( V_46 & INT ) ) {
F_34 ( & V_2 -> V_64 ) ;
return V_69 ;
}
F_23 ( V_48 & ~ INT , V_2 -> V_11 + V_30 ) ;
F_25 ( V_2 ) ;
F_34 ( & V_2 -> V_64 ) ;
return V_68 ;
}
static unsigned int F_35 ( unsigned int V_70 , int V_37 )
{
unsigned int V_71 ;
if ( V_70 > 64000 )
V_70 = 64000 ;
switch ( V_37 & V_72 ) {
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
struct V_14 * V_15 ,
struct V_20 * V_21 )
{
unsigned int V_76 = F_37 ( V_21 -> V_77 [ 0 ] ) & V_78 ;
int V_9 ;
for ( V_9 = 1 ; V_9 < V_21 -> V_79 ; V_9 ++ ) {
unsigned int V_10 = F_37 ( V_21 -> V_77 [ V_9 ] ) & V_78 ;
if ( V_10 != V_76 ) {
F_38 ( V_2 -> V_60 ,
L_3 ) ;
return - V_80 ;
}
}
return 0 ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_20 * V_21 )
{
const struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_16 * V_17 = V_2 -> V_18 ;
int V_81 = 0 ;
unsigned int V_82 ;
V_81 |= F_40 ( & V_21 -> V_83 , V_84 | V_85 ) ;
V_81 |= F_40 ( & V_21 -> V_86 ,
V_87 | V_88 | V_85 ) ;
V_81 |= F_40 ( & V_21 -> V_89 , V_88 | V_85 ) ;
V_81 |= F_40 ( & V_21 -> V_90 , V_25 ) ;
V_81 |= F_40 ( & V_21 -> V_24 ,
V_25 | V_85 | V_91 ) ;
if ( V_81 )
return 1 ;
V_81 |= F_41 ( V_21 -> V_83 ) ;
V_81 |= F_41 ( V_21 -> V_86 ) ;
V_81 |= F_41 ( V_21 -> V_89 ) ;
V_81 |= F_41 ( V_21 -> V_24 ) ;
if ( V_21 -> V_86 != V_87 &&
V_21 -> V_89 != V_88 )
V_81 |= - V_80 ;
if ( V_81 )
return 2 ;
V_81 |= F_42 ( & V_21 -> V_92 , 0 ) ;
if ( V_21 -> V_89 == V_88 )
V_81 |= F_43 ( & V_21 -> V_70 ,
V_5 -> V_93 ) ;
V_81 |= F_43 ( & V_21 -> V_79 , 1 ) ;
V_81 |= F_42 ( & V_21 -> V_94 , V_21 -> V_79 ) ;
switch ( V_21 -> V_24 ) {
case V_25 :
V_81 |= F_43 ( & V_21 -> V_95 , 1 ) ;
break;
case V_91 :
V_81 |= F_42 ( & V_21 -> V_95 , 0 ) ;
break;
default:
break;
}
if ( V_81 )
return 3 ;
if ( V_21 -> V_86 == V_87 &&
V_21 -> V_89 == V_88 ) {
V_82 = V_21 -> V_70 ;
F_44 ( V_96 ,
& V_17 -> V_97 ,
& V_17 -> V_98 ,
& V_21 -> V_70 , V_21 -> V_37 ) ;
if ( V_82 != V_21 -> V_70 )
V_81 ++ ;
} else if ( V_21 -> V_89 == V_88 ) {
V_82 = V_21 -> V_70 ;
V_21 -> V_70 = F_35 ( V_21 -> V_70 ,
V_21 -> V_37 ) ;
if ( V_82 != V_21 -> V_70 )
V_81 ++ ;
if ( V_21 -> V_86 == V_88 ) {
V_82 = V_21 -> V_70 * V_21 -> V_79 ;
if ( V_82 > V_21 -> V_99 ) {
V_21 -> V_99 = V_82 ;
V_81 ++ ;
}
V_82 = V_21 -> V_99 ;
F_44 ( V_96 ,
& V_17 -> V_97 ,
& V_17 -> V_98 ,
& V_21 -> V_99 ,
V_21 -> V_37 ) ;
if ( V_82 != V_21 -> V_99 )
V_81 ++ ;
}
}
if ( V_81 )
return 4 ;
if ( V_21 -> V_77 && V_21 -> V_79 > 0 )
V_81 |= F_36 ( V_2 , V_15 , V_21 ) ;
if ( V_81 )
return 5 ;
return 0 ;
}
static int F_45 ( const struct V_20 * V_21 )
{
int V_100 ;
V_100 = V_101 ;
if ( V_21 -> V_24 == V_85 )
V_100 |= V_102 ;
switch ( V_21 -> V_83 ) {
case V_85 :
V_100 |= V_103 | V_104 ;
break;
case V_84 :
V_100 |= V_105 ;
break;
default:
break;
}
return V_100 ;
}
static int F_46 ( const struct V_20 * V_21 )
{
int V_106 ;
int V_107 ;
V_107 = F_47 ( V_21 -> V_77 [ 0 ] ) ;
V_106 = V_108 ;
if ( V_107 != V_109 )
V_106 |= V_110 ;
if ( V_107 == V_111 )
V_106 |= V_112 ;
if ( F_37 ( V_21 -> V_77 [ 0 ] ) & V_78 )
V_106 |= V_13 ;
switch ( V_21 -> V_86 ) {
case V_87 :
switch ( V_21 -> V_89 ) {
case V_88 :
V_106 |= V_113 ;
break;
case V_85 :
V_106 |= V_114 ;
break;
default:
break;
}
break;
case V_88 :
V_106 |= V_115 | V_113 ;
break;
case V_85 :
V_106 |= V_115 | V_114 ;
break;
default:
break;
}
return V_106 ;
}
static void F_48 ( struct V_1 * V_2 ,
const struct V_20 * V_21 )
{
struct V_16 * V_17 = V_2 -> V_18 ;
unsigned long V_116 = V_2 -> V_11 + V_117 ;
if ( ( V_21 -> V_86 == V_87 ||
V_21 -> V_86 == V_88 ) &&
V_21 -> V_89 == V_88 ) {
F_49 ( V_116 , 0 , 1 , V_118 | V_119 ) ;
F_49 ( V_116 , 0 , 2 , V_118 | V_119 ) ;
F_50 ( V_116 , 0 , 1 , V_17 -> V_97 ) ;
F_50 ( V_116 , 0 , 2 , V_17 -> V_98 ) ;
}
if ( V_21 -> V_24 == V_85 ) {
F_49 ( V_116 , 0 , 0 , V_120 | V_119 ) ;
F_50 ( V_116 , 0 , 0 , 1 ) ;
}
}
static unsigned int F_51 ( const struct V_20 * V_21 )
{
unsigned int V_121 = V_122 ;
static const int V_123 = 2 ;
unsigned int V_124 = 300000000 ;
unsigned int V_125 ;
switch ( V_21 -> V_86 ) {
case V_87 :
if ( V_21 -> V_89 == V_88 )
V_121 = ( V_124 / V_21 -> V_70 ) * V_123 ;
break;
case V_88 :
V_121 = ( V_124 / ( V_21 -> V_99 * V_21 -> V_79 ) ) *
V_123 ;
break;
default:
V_121 = V_122 ;
break;
}
V_125 = V_122 ;
if ( V_21 -> V_24 == V_25 &&
V_21 -> V_95 * V_21 -> V_79 * V_123 < V_125 )
V_125 = V_21 -> V_95 * V_21 -> V_79 * V_123 ;
if ( V_121 > V_125 )
V_121 = V_125 ;
if ( V_121 < V_123 )
V_121 = V_123 ;
return V_121 ;
}
static void F_52 ( struct V_1 * V_2 , const struct V_20 * V_21 )
{
struct V_16 * V_17 = V_2 -> V_18 ;
unsigned long V_126 ;
const int V_38 = V_17 -> V_39 & V_40 ;
if ( ( V_17 -> V_39 & V_55 ) == 0 )
return;
V_17 -> V_36 = F_51 ( V_21 ) ;
V_126 = F_16 () ;
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
F_17 ( V_126 ) ;
}
static void F_53 ( struct V_1 * V_2 ,
const struct V_20 * V_21 )
{
int V_9 , V_127 , V_128 ;
unsigned long V_129 ;
const int V_130 = 0x3 ;
const int V_131 = 8 ;
V_127 = V_21 -> V_79 ;
F_29 ( & V_2 -> V_64 , V_129 ) ;
F_23 ( V_132 , V_2 -> V_11 + V_54 ) ;
F_23 ( V_127 - 1 , V_2 -> V_11 + V_133 ) ;
for ( V_9 = 0 ; V_9 < V_127 ; V_9 ++ ) {
V_128 =
F_54 ( V_21 -> V_77 [ V_9 ] ) |
( ( F_37 ( V_21 -> V_77 [ V_9 ] ) & V_130 ) <<
V_131 ) ;
F_55 ( V_128 , V_2 -> V_11 + V_134 ) ;
}
F_23 ( V_127 - 1 , V_2 -> V_11 + V_133 ) ;
F_30 ( & V_2 -> V_64 , V_129 ) ;
}
static int F_56 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_16 * V_17 = V_2 -> V_18 ;
int V_100 , V_106 ;
struct V_52 * V_22 = V_15 -> V_22 ;
const struct V_20 * V_21 = & V_22 -> V_21 ;
if ( V_21 -> V_37 & ( V_135 | V_136 ) )
V_17 -> V_39 &= ~ V_55 ;
else
V_17 -> V_39 |= V_17 -> V_137 ;
if ( V_21 -> V_37 & V_135 ) {
V_17 -> V_39 &= ~ V_138 ;
} else {
V_17 -> V_39 |= V_138 ;
}
if ( V_21 -> V_24 == V_25 )
V_17 -> V_26 = V_21 -> V_95 * V_21 -> V_79 ;
F_24 ( V_2 , V_15 ) ;
V_100 = F_45 ( V_21 ) ;
V_106 = F_46 ( V_21 ) ;
F_53 ( V_2 , V_21 ) ;
F_48 ( V_2 , V_21 ) ;
F_52 ( V_2 , V_21 ) ;
F_23 ( V_106 , V_2 -> V_11 + V_12 ) ;
if ( V_106 & V_115 ) {
F_23 ( V_21 -> V_70 / 1000 - 1 ,
V_2 -> V_11 + V_139 ) ;
F_23 ( V_21 -> V_79 - 1 , V_2 -> V_11 + V_140 ) ;
}
F_23 ( V_17 -> V_39 , V_2 -> V_11 + V_49 ) ;
F_23 ( V_100 , V_2 -> V_11 + V_50 ) ;
F_23 ( V_141 , V_2 -> V_11 + V_30 ) ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_142 * V_143 , unsigned int * V_144 )
{
const struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_9 , V_127 ;
int V_145 , V_146 , V_107 , V_128 ;
int V_147 = 1000 ;
unsigned short V_29 ;
int V_148 = 0 ;
unsigned long V_129 ;
V_107 = F_47 ( V_143 -> V_149 ) ;
V_148 |= V_108 ;
if ( V_107 != V_109 )
V_148 |= V_110 ;
if ( V_107 == V_111 )
V_148 |= V_112 ;
if ( F_37 ( V_143 -> V_149 ) & V_78 )
V_148 |= V_13 ;
F_23 ( V_148 , V_2 -> V_11 + V_12 ) ;
F_23 ( V_141 , V_2 -> V_11 + V_30 ) ;
F_23 ( 0x0 , V_2 -> V_11 + V_50 ) ;
F_23 ( V_101 , V_2 -> V_11 + V_50 ) ;
V_145 = F_54 ( V_143 -> V_149 ) ;
V_146 = F_37 ( V_143 -> V_149 ) & 0x3 ;
V_128 = V_145 | ( V_146 << 8 ) ;
F_29 ( & V_2 -> V_64 , V_129 ) ;
F_23 ( V_132 , V_2 -> V_11 + V_54 ) ;
F_23 ( 0x0 , V_2 -> V_11 + V_133 ) ;
F_55 ( V_128 , V_2 -> V_11 + V_134 ) ;
F_23 ( 0x0 , V_2 -> V_11 + V_133 ) ;
F_23 ( V_53 , V_2 -> V_11 + V_54 ) ;
for ( V_127 = 0 ; V_127 < V_143 -> V_127 ; V_127 ++ ) {
F_23 ( 0 , V_2 -> V_11 + V_27 ) ;
for ( V_9 = 0 ; V_9 < V_147 ; V_9 ++ ) {
if ( F_4 ( V_2 -> V_11 + V_30 ) & V_31 )
break;
}
if ( V_9 == V_147 ) {
F_26 ( V_2 -> V_60 , L_4 ) ;
V_127 = - V_150 ;
goto exit;
}
V_29 = F_9 ( V_2 -> V_11 + V_27 ) ;
if ( ( V_148 & V_13 ) == 0 )
V_29 += 1 << ( V_5 -> V_6 - 1 ) ;
V_144 [ V_127 ] = V_29 ;
}
exit:
F_30 ( & V_2 -> V_64 , V_129 ) ;
return V_127 ;
}
static int F_58 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_142 * V_143 , unsigned int * V_144 )
{
const struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_16 * V_17 = V_2 -> V_18 ;
int V_145 = F_54 ( V_143 -> V_149 ) ;
int V_151 = V_5 -> V_152 - 1 ;
unsigned short V_153 ;
unsigned long V_129 ;
V_153 = V_144 [ 0 ] - ( 1 << ( V_5 -> V_6 - 1 ) ) ;
if ( V_145 == V_151 )
V_17 -> V_154 = V_153 ;
F_29 ( & V_2 -> V_64 , V_129 ) ;
F_23 ( F_59 ( V_145 ) , V_2 -> V_11 + V_54 ) ;
F_55 ( V_153 , V_2 -> V_11 + V_155 ) ;
if ( V_145 != V_151 ) {
F_23 ( F_59 ( V_151 ) , V_2 -> V_11 + V_54 ) ;
F_55 ( V_17 -> V_154 , V_2 -> V_11 + V_155 ) ;
}
F_30 ( & V_2 -> V_64 , V_129 ) ;
return 1 ;
}
static int F_60 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_142 * V_143 , unsigned int * V_144 )
{
V_144 [ 1 ] = F_4 ( V_2 -> V_11 + V_156 ) & 0xf ;
V_144 [ 0 ] = 0 ;
return V_143 -> V_127 ;
}
static int F_61 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_142 * V_143 ,
unsigned int * V_144 )
{
if ( F_62 ( V_15 , V_144 ) )
F_23 ( V_15 -> V_157 , V_2 -> V_11 + V_156 ) ;
V_144 [ 1 ] = V_15 -> V_157 ;
return V_143 -> V_127 ;
}
static int F_63 ( struct V_1 * V_2 , unsigned int V_43 ,
unsigned int V_44 )
{
struct V_16 * V_17 = V_2 -> V_18 ;
unsigned long V_37 ;
if ( V_2 -> V_65 && V_43 ) {
switch ( ( V_43 & 0x7 ) | ( V_44 << 4 ) ) {
case 0x5 :
V_17 -> V_137 |= V_158 ;
break;
case 0x6 :
V_17 -> V_137 |= V_159 ;
break;
case 0x7 :
V_17 -> V_137 |= V_160 ;
break;
case 0x65 :
V_17 -> V_137 |= V_161 ;
break;
case 0x76 :
V_17 -> V_137 |= V_162 ;
break;
case 0x57 :
V_17 -> V_137 |= V_163 ;
break;
default:
F_26 ( V_2 -> V_60 ,
L_5 ) ;
F_26 ( V_2 -> V_60 ,
L_6 ) ;
F_26 ( V_2 -> V_60 ,
L_7 ) ;
return - V_80 ;
}
if ( F_64 ( V_43 , V_2 -> V_164 -> V_165 ) ) {
F_26 ( V_2 -> V_60 ,
L_8 , V_43 ) ;
return - V_80 ;
}
V_17 -> V_43 = V_43 ;
V_17 -> V_41 = V_43 ;
if ( V_44 ) {
if ( F_64 ( V_44 , V_2 -> V_164 -> V_165 ) ) {
F_26 ( V_2 -> V_60 ,
L_8 ,
V_44 ) ;
return - V_80 ;
}
V_17 -> V_44 = V_44 ;
}
V_17 -> V_28 = F_65 ( V_122 , V_166 | V_167 ) ;
if ( V_17 -> V_28 == NULL )
return - V_168 ;
V_17 -> V_42 = V_17 -> V_28 ;
if ( V_44 ) {
V_17 -> V_45 =
F_65 ( V_122 , V_166 | V_167 ) ;
if ( V_17 -> V_45 == NULL )
return - V_168 ;
}
V_37 = F_16 () ;
F_12 ( V_17 -> V_43 ) ;
F_66 ( V_17 -> V_43 , V_169 ) ;
if ( V_44 ) {
F_12 ( V_17 -> V_44 ) ;
F_66 ( V_17 -> V_44 , V_169 ) ;
}
F_17 ( V_37 ) ;
}
return 0 ;
}
static int F_67 ( struct V_1 * V_2 )
{
const struct V_4 * V_170 = F_2 ( V_2 ) ;
int V_171 ;
int V_172 ;
V_171 = V_170 - V_173 ;
V_172 = ( F_4 ( V_2 -> V_11 + V_156 ) >> 4 ) & 0xf ;
switch ( V_172 ) {
case 0x3 :
if ( V_171 == V_174 || V_171 == V_175 ||
V_171 == V_176 || V_171 == V_177 )
return V_171 ;
V_171 = V_178 ;
break;
case 0x4 :
if ( V_171 == V_179 || V_171 == V_180 )
return V_171 ;
V_171 = V_181 ;
break;
case 0x5 :
if ( V_171 == V_182 || V_171 == V_183 ||
V_171 == V_184 || V_171 == V_185 )
return V_171 ;
V_171 = V_182 ;
break;
case 0x6 :
if ( V_171 == V_181 || V_171 == V_186 )
return V_171 ;
V_171 = V_181 ;
break;
case 0x7 :
if ( V_171 == V_178 || V_171 == V_187 ||
V_171 == V_188 || V_171 == V_189 )
return V_171 ;
V_171 = V_178 ;
break;
case 0x8 :
if ( V_171 == V_190 || V_171 == V_191 )
return V_171 ;
V_171 = V_190 ;
break;
default:
F_26 ( V_2 -> V_60 ,
L_9 ,
V_172 ) ;
break;
}
F_26 ( V_2 -> V_60 ,
L_10 ,
V_173 [ V_171 ] . V_192 ) ;
return V_171 ;
}
static int F_68 ( struct V_1 * V_2 ,
struct V_193 * V_194 )
{
const struct V_4 * V_5 ;
struct V_16 * V_17 ;
struct V_14 * V_15 ;
unsigned int V_65 = V_194 -> V_195 [ 1 ] ;
unsigned int V_43 = V_194 -> V_195 [ 2 ] ;
unsigned int V_44 = V_194 -> V_195 [ 3 ] ;
int V_170 ;
int V_196 ;
V_17 = F_69 ( V_2 , sizeof( * V_17 ) ) ;
if ( ! V_17 )
return - V_168 ;
V_196 = F_70 ( V_2 , V_194 -> V_195 [ 0 ] , V_197 ) ;
if ( V_196 )
return V_196 ;
V_170 = F_67 ( V_2 ) ;
if ( V_170 < 0 ) {
F_26 ( V_2 -> V_60 , L_11 ) ;
return - V_198 ;
}
V_2 -> V_199 = V_173 + V_170 ;
V_5 = F_2 ( V_2 ) ;
V_2 -> V_200 = V_5 -> V_192 ;
if ( V_5 -> V_201 == 2 ) {
unsigned long V_202 = V_2 -> V_11 + V_203 ;
V_196 = F_71 ( V_2 , V_202 , V_197 ) ;
if ( V_196 )
return V_196 ;
V_17 -> V_202 = V_202 ;
}
if ( V_65 == 3 || V_65 == 5 || V_65 == 7 || V_65 == 10 || V_65 == 11 ||
V_65 == 15 ) {
V_196 = F_72 ( V_65 , F_32 , 0 ,
V_2 -> V_200 , V_2 ) ;
if ( V_196 == 0 ) {
V_2 -> V_65 = V_65 ;
switch ( V_65 ) {
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
V_196 = F_63 ( V_2 , V_43 , V_44 ) ;
if ( V_196 < 0 )
return V_196 ;
if ( V_17 -> V_28 == NULL ) {
V_17 -> V_28 =
F_65 ( V_23 * sizeof( T_1 ) , V_166 ) ;
if ( V_17 -> V_28 == NULL )
return - V_168 ;
}
V_196 = F_73 ( V_2 , 4 ) ;
if ( V_196 )
return V_196 ;
V_15 = & V_2 -> V_204 [ 0 ] ;
V_15 -> type = V_205 ;
V_15 -> V_206 = V_207 | V_208 | V_209 ;
if ( V_5 -> V_210 )
V_15 -> V_206 |= V_211 ;
V_15 -> V_212 = V_5 -> V_213 ;
V_15 -> V_214 = ( 1 << V_5 -> V_6 ) - 1 ;
V_15 -> V_215 = V_5 -> V_216 ;
V_15 -> V_217 = F_57 ;
if ( V_2 -> V_65 ) {
V_2 -> V_51 = V_15 ;
V_15 -> V_206 |= V_218 ;
V_15 -> V_219 = V_15 -> V_212 ;
V_15 -> V_220 = F_56 ;
V_15 -> V_221 = F_39 ;
V_15 -> V_222 = F_28 ;
V_15 -> V_223 = F_24 ;
}
V_15 = & V_2 -> V_204 [ 1 ] ;
if ( V_5 -> V_201 == 1 ) {
V_15 -> type = V_224 ;
V_15 -> V_206 = V_225 ;
V_15 -> V_212 = V_5 -> V_152 ;
V_15 -> V_214 = ( 1 << V_5 -> V_6 ) - 1 ;
V_15 -> V_215 = & V_226 ;
V_15 -> V_227 = F_58 ;
} else {
V_15 -> type = V_228 ;
}
V_15 = & V_2 -> V_204 [ 2 ] ;
V_15 -> type = V_229 ;
V_15 -> V_206 = V_207 ;
V_15 -> V_212 = 4 ;
V_15 -> V_214 = 1 ;
V_15 -> V_215 = & V_230 ;
V_15 -> V_231 = F_60 ;
V_15 = & V_2 -> V_204 [ 3 ] ;
V_15 -> type = V_232 ;
V_15 -> V_206 = V_225 | V_207 ;
V_15 -> V_212 = V_5 -> V_233 ;
V_15 -> V_214 = 1 ;
V_15 -> V_215 = & V_230 ;
V_15 -> V_231 = F_61 ;
F_24 ( V_2 , V_2 -> V_51 ) ;
F_23 ( 0 , V_2 -> V_11 + V_156 ) ;
if ( V_5 -> V_201 == 1 ) {
F_23 ( F_59 ( V_5 -> V_152 - 1 ) ,
V_2 -> V_11 + V_54 ) ;
F_55 ( V_17 -> V_154 , V_2 -> V_11 + V_155 ) ;
}
return 0 ;
}
static void F_74 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = V_2 -> V_18 ;
if ( V_17 ) {
if ( V_17 -> V_43 )
F_75 ( V_17 -> V_43 ) ;
if ( V_17 -> V_44 )
F_75 ( V_17 -> V_44 ) ;
F_76 ( V_17 -> V_28 ) ;
F_76 ( V_17 -> V_45 ) ;
if ( V_17 -> V_202 )
F_77 ( V_17 -> V_202 , V_197 ) ;
}
F_78 ( V_2 ) ;
}
