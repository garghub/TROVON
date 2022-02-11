static void F_1 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_2 ( V_4 , V_6 -> V_8 + V_9 ) ;
F_2 ( V_3 & 0xffff , V_6 -> V_8 + V_10 ) ;
F_2 ( V_4 + 2 , V_6 -> V_8 + V_9 ) ;
F_2 ( ( V_3 >> 16 ) & 0xffff , V_6 -> V_8 + V_10 ) ;
}
static void F_3 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_4 ( V_13 | V_14 ,
V_6 -> V_15 + V_16 ) ;
F_1 ( V_2 , V_13 | V_14 ,
V_16 ) ;
F_4 ( V_17 | V_18 ,
V_6 -> V_15 + V_19 ) ;
F_1 ( V_2 , V_12 -> V_20 , V_21 ) ;
F_1 ( V_2 , V_12 -> V_22 , V_23 ) ;
F_4 ( V_24 | V_25 ,
V_6 -> V_15 + V_26 ) ;
F_2 ( V_27 | V_28 ,
V_6 -> V_8 + V_29 ) ;
}
static void F_5 ( struct V_1 * V_2 ,
struct V_30 * V_31 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_32 * V_33 = & V_31 -> V_34 -> V_33 ;
struct V_11 * V_35 = & V_6 -> V_12 [ 0 ] ;
struct V_11 * V_36 = & V_6 -> V_12 [ 1 ] ;
unsigned int V_37 = V_35 -> V_38 ;
unsigned int V_39 = V_36 -> V_38 ;
unsigned int V_40 ;
V_40 = F_6 ( V_31 , V_33 -> V_41 ) ;
if ( V_33 -> V_42 == V_43 ) {
if ( V_37 > ( V_33 -> V_44 * V_40 ) )
V_37 = V_33 -> V_44 * V_40 ;
else if ( V_39 > ( V_33 -> V_44 * V_40 - V_37 ) )
V_39 = V_33 -> V_44 * V_40 - V_37 ;
}
if ( V_33 -> V_45 & V_46 ) {
if ( V_37 > V_40 ) {
V_37 = V_40 ;
if ( V_33 -> V_41 & 1 )
V_37 += 2 ;
}
if ( V_39 > V_40 ) {
V_39 = V_40 ;
if ( V_33 -> V_41 & 1 )
V_39 -= 2 ;
if ( V_39 < 4 )
V_39 = 4 ;
}
} else {
if ( V_37 > V_31 -> V_34 -> V_47 )
V_37 = V_31 -> V_34 -> V_47 ;
if ( V_39 > V_31 -> V_34 -> V_47 )
V_39 = V_31 -> V_34 -> V_47 ;
}
V_35 -> V_22 = V_37 ;
V_36 -> V_22 = V_39 ;
F_3 ( V_2 , V_35 ) ;
}
static unsigned int F_7 ( struct V_1 * V_2 ,
unsigned int V_48 ,
unsigned int V_49 ,
unsigned int V_45 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_50 = ( V_48 == 0 ) ? 10 : 1000 ;
unsigned int V_51 = V_6 -> V_52 * V_50 ;
unsigned int V_53 ;
switch ( V_45 & V_54 ) {
case V_55 :
V_53 = F_8 ( V_49 , V_51 ) ;
break;
case V_56 :
V_53 = V_49 / V_51 ;
break;
case V_57 :
default:
V_53 = F_9 ( V_49 , V_51 ) ;
break;
}
if ( V_48 == 2 ) {
if ( V_53 > 0x00ffffff )
V_53 = 0x00ffffff ;
} else {
if ( V_53 > 0xffff )
V_53 = 0xffff ;
}
if ( V_53 < 2 )
V_53 = 2 ;
return V_53 ;
}
static void F_10 ( struct V_1 * V_2 )
{
F_11 ( V_2 -> V_58 + V_59 ) ;
}
static void F_12 ( struct V_1 * V_2 ,
unsigned int V_48 , unsigned int V_3 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_13 ( F_14 ( V_6 -> V_60 ) |
F_15 ( V_48 ) ,
V_2 -> V_58 + V_59 ) ;
F_2 ( V_3 & 0xffff , V_2 -> V_58 + V_61 ) ;
if ( V_48 == 2 ) {
F_13 ( F_14 ( V_6 -> V_60 ) |
F_15 ( V_48 + 1 ) ,
V_2 -> V_58 + V_59 ) ;
F_2 ( ( V_3 >> 16 ) & 0xffff , V_2 -> V_58 + V_61 ) ;
}
}
static unsigned int F_16 ( struct V_1 * V_2 ,
unsigned int V_48 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_3 ;
F_13 ( F_14 ( V_6 -> V_60 ) |
F_15 ( V_48 ) ,
V_2 -> V_58 + V_59 ) ;
V_3 = F_17 ( V_2 -> V_58 + V_61 ) ;
if ( V_48 == 2 ) {
F_13 ( F_14 ( V_6 -> V_60 ) |
F_15 ( V_48 + 1 ) ,
V_2 -> V_58 + V_59 ) ;
V_3 |= ( F_17 ( V_2 -> V_58 + V_61 ) << 16 ) ;
}
return V_3 ;
}
static void F_18 ( struct V_1 * V_2 ,
unsigned int V_48 , unsigned int V_62 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
V_6 -> V_63 &= ~ F_19 ( V_48 ) ;
V_6 -> V_63 |= F_20 ( V_48 , V_62 ) ;
F_13 ( V_6 -> V_63 , V_2 -> V_58 + V_64 ) ;
}
static void F_21 ( struct V_1 * V_2 ,
unsigned int V_48 , bool V_65 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_65 )
V_6 -> V_66 |= F_22 ( V_48 ) ;
else
V_6 -> V_66 &= ~ F_22 ( V_48 ) ;
F_2 ( V_6 -> V_66 , V_2 -> V_58 + V_67 ) ;
}
static void F_23 ( struct V_1 * V_2 , bool V_65 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_65 )
V_6 -> V_66 |= V_68 ;
else
V_6 -> V_66 &= ~ V_68 ;
F_2 ( V_6 -> V_66 , V_2 -> V_58 + V_67 ) ;
}
static void F_24 ( struct V_1 * V_2 ,
struct V_30 * V_31 ,
int V_69 , unsigned int * V_70 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_71 ;
for ( V_71 = 0 ; V_71 < V_69 ; V_71 ++ ) {
unsigned int V_72 = F_25 ( V_70 [ V_71 ] ) ;
unsigned int V_73 = F_26 ( V_70 [ V_71 ] ) ;
unsigned int V_3 ;
V_3 = F_27 ( V_72 ) |
F_28 ( V_73 ) |
F_29 ( V_71 ) ;
if ( F_30 ( V_31 , V_73 ) )
V_3 |= V_74 ;
F_2 ( V_3 , V_2 -> V_58 + V_75 ) ;
}
F_17 ( V_2 -> V_58 + V_64 ) ;
V_6 -> V_66 = F_31 ( V_69 - 1 ) | F_32 ( 0 ) ;
F_2 ( V_6 -> V_66 , V_2 -> V_58 + V_67 ) ;
if ( V_69 > 1 )
V_6 -> V_62 |= V_76 ;
}
static void F_33 ( struct V_1 * V_2 ,
struct V_30 * V_31 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_77 * V_34 = V_31 -> V_34 ;
struct V_32 * V_33 = & V_34 -> V_33 ;
struct V_11 * V_12 ;
unsigned int V_78 ;
unsigned int V_79 ;
V_12 = & V_6 -> V_12 [ V_6 -> V_80 ] ;
V_78 = V_12 -> V_22 - F_34 ( V_6 -> V_15 + V_81 ) ;
if ( V_78 < V_12 -> V_22 )
F_35 ( V_2 -> V_82 , L_1 ) ;
if ( V_78 & 1 ) {
F_35 ( V_2 -> V_82 , L_2 ) ;
V_34 -> V_83 |= V_84 ;
return;
}
V_79 = F_36 ( V_31 , V_78 ) ;
if ( V_79 ) {
F_37 ( V_31 , V_12 -> V_85 , V_79 ) ;
if ( ! ( V_33 -> V_45 & V_46 ) )
V_34 -> V_83 |= V_86 ;
}
if ( ( V_34 -> V_83 & V_87 ) ||
( V_33 -> V_42 == V_43 && V_34 -> V_88 >= V_33 -> V_44 ) )
return;
if ( V_6 -> V_89 ) {
V_6 -> V_80 = ! V_6 -> V_80 ;
V_12 = & V_6 -> V_12 [ V_6 -> V_80 ] ;
F_3 ( V_2 , V_12 ) ;
} else {
F_3 ( V_2 , V_12 ) ;
}
}
static T_1 F_38 ( int V_90 , void * V_91 )
{
struct V_1 * V_2 = V_91 ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_30 * V_31 = V_2 -> V_92 ;
struct V_77 * V_34 = V_31 -> V_34 ;
struct V_32 * V_33 = & V_34 -> V_33 ;
unsigned int V_93 ;
unsigned int V_94 ;
V_93 = F_17 ( V_2 -> V_58 + V_95 ) ;
V_94 = F_34 ( V_6 -> V_15 + V_26 ) ;
if ( ! ( V_93 & V_96 ) &&
! ( V_94 & V_97 ) ) {
F_35 ( V_2 -> V_82 , L_3 ) ;
return V_98 ;
}
F_4 ( V_94 | V_99 , V_6 -> V_15 + V_26 ) ;
if ( V_6 -> V_66 & V_68 )
F_23 ( V_2 , false ) ;
if ( V_94 & V_100 )
F_35 ( V_2 -> V_82 , L_4 ) ;
if ( V_94 & V_101 )
F_35 ( V_2 -> V_82 , L_5 ) ;
if ( ( V_93 & V_102 ) == 0 &&
( V_6 -> V_62 & V_103 ) ) {
}
if ( ( V_93 & V_104 ) &&
( V_6 -> V_62 & V_105 ) ) {
unsigned short V_3 ;
int V_71 ;
for ( V_71 = 0 ; V_71 < V_33 -> V_106 ; V_71 ++ ) {
V_3 = F_17 ( V_2 -> V_58 + V_107 ) ;
F_37 ( V_31 , & V_3 , 1 ) ;
}
V_6 -> V_62 |= V_105 ;
F_13 ( V_6 -> V_62 , V_2 -> V_58 + V_108 ) ;
}
if ( V_93 & V_109 ) {
F_10 ( V_2 ) ;
}
if ( V_93 & V_110 ) {
F_4 ( V_111 , V_6 -> V_15 + V_26 ) ;
F_33 ( V_2 , V_31 ) ;
}
if ( V_33 -> V_42 == V_43 && V_34 -> V_88 >= V_33 -> V_44 )
V_34 -> V_83 |= V_112 ;
F_39 ( V_2 , V_31 ) ;
return V_113 ;
}
static int F_40 ( struct V_1 * V_2 ,
struct V_30 * V_31 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_32 * V_33 = & V_31 -> V_34 -> V_33 ;
unsigned int V_53 ;
V_6 -> V_62 = V_114 |
V_115 ;
F_4 ( V_111 , V_6 -> V_15 + V_26 ) ;
V_6 -> V_80 = 0 ;
F_24 ( V_2 , V_31 , V_33 -> V_106 , V_33 -> V_70 ) ;
if ( V_33 -> V_116 == V_117 )
F_23 ( V_2 , true ) ;
if ( V_33 -> V_118 == V_119 ) {
V_53 = F_7 ( V_2 , 1 , V_33 -> V_120 ,
V_33 -> V_45 ) ;
F_18 ( V_2 , 1 , V_121 ) ;
F_12 ( V_2 , 1 , V_53 ) ;
}
V_53 = F_7 ( V_2 , 0 , V_33 -> V_122 , V_33 -> V_45 ) ;
F_18 ( V_2 , 0 , V_121 ) ;
F_12 ( V_2 , 0 , V_53 ) ;
if ( V_6 -> V_123 )
F_5 ( V_2 , V_31 ) ;
else
V_6 -> V_62 |= V_105 ;
F_13 ( V_6 -> V_62 , V_2 -> V_58 + V_108 ) ;
if ( V_33 -> V_118 == V_119 )
F_21 ( V_2 , 1 , true ) ;
F_21 ( V_2 , 0 , true ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 ,
struct V_30 * V_31 ,
struct V_32 * V_33 )
{
unsigned int V_124 ;
int V_125 = 0 ;
V_125 |= F_42 ( & V_33 -> V_116 , V_126 | V_117 ) ;
V_125 |= F_42 ( & V_33 -> V_118 ,
V_119 | V_127 ) ;
V_125 |= F_42 ( & V_33 -> V_128 , V_119 ) ;
V_125 |= F_42 ( & V_33 -> V_129 , V_43 ) ;
V_125 |= F_42 ( & V_33 -> V_42 , V_43 | V_130 ) ;
if ( V_125 )
return 1 ;
V_125 |= F_43 ( V_33 -> V_116 ) ;
V_125 |= F_43 ( V_33 -> V_118 ) ;
V_125 |= F_43 ( V_33 -> V_42 ) ;
if ( V_125 )
return 2 ;
V_125 |= F_44 ( & V_33 -> V_131 , 0 ) ;
if ( V_33 -> V_118 == V_119 ) {
V_125 |= F_45 ( & V_33 -> V_120 ,
100000 ) ;
}
V_125 |= F_45 ( & V_33 -> V_122 , 10000 ) ;
V_125 |= F_45 ( & V_33 -> V_106 , 1 ) ;
V_125 |= F_44 ( & V_33 -> V_41 ,
V_33 -> V_106 ) ;
if ( V_33 -> V_42 == V_43 )
V_125 |= F_45 ( & V_33 -> V_44 , 1 ) ;
else
V_125 |= F_44 ( & V_33 -> V_44 , 0 ) ;
if ( V_125 )
return 3 ;
if ( V_33 -> V_118 == V_119 ) {
V_124 = V_33 -> V_122 * V_33 -> V_41 ;
V_125 |= F_45 ( & V_33 -> V_120 , V_124 ) ;
}
if ( V_125 )
return 4 ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 ,
struct V_30 * V_31 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_2 ( 0 , V_6 -> V_8 + 4 ) ;
F_1 ( V_2 , 0 , V_16 ) ;
F_4 ( 0 , V_6 -> V_15 + V_19 ) ;
V_6 -> V_66 = 0 ;
F_2 ( V_6 -> V_66 , V_2 -> V_58 + V_67 ) ;
V_6 -> V_62 = 0 ;
F_13 ( V_6 -> V_62 , V_2 -> V_58 + V_108 ) ;
F_17 ( V_2 -> V_58 + V_95 ) ;
V_6 -> V_80 = 0 ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 ,
struct V_30 * V_31 ,
struct V_132 * V_133 ,
unsigned long V_134 )
{
unsigned int V_93 ;
V_93 = F_17 ( V_2 -> V_58 + V_95 ) ;
if ( ( V_93 & V_102 ) == 0 )
return 0 ;
return - V_135 ;
}
static int F_48 ( struct V_1 * V_2 ,
struct V_30 * V_31 ,
struct V_132 * V_133 ,
unsigned int * V_136 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_53 ;
int V_137 ;
int V_71 ;
V_6 -> V_62 = V_114 |
V_115 ;
F_13 ( V_6 -> V_62 , V_2 -> V_58 + V_108 ) ;
F_24 ( V_2 , V_31 , 1 , & V_133 -> V_138 ) ;
F_18 ( V_2 , 0 , V_139 ) ;
F_21 ( V_2 , 0 , true ) ;
V_53 = F_7 ( V_2 , 0 , 10000 , V_57 ) ;
for ( V_71 = 0 ; V_71 < V_133 -> V_140 ; V_71 ++ ) {
F_12 ( V_2 , 0 , V_53 ) ;
V_137 = F_49 ( V_2 , V_31 , V_133 , F_47 , 0 ) ;
if ( V_137 )
return V_137 ;
V_136 [ V_71 ] = F_17 ( V_2 -> V_58 + V_107 ) ;
}
return V_133 -> V_140 ;
}
static int F_50 ( struct V_1 * V_2 ,
struct V_30 * V_31 ,
struct V_132 * V_133 ,
unsigned long V_134 )
{
unsigned int V_93 ;
V_93 = F_17 ( V_2 -> V_58 + V_95 ) ;
if ( V_93 & V_141 )
return 0 ;
return - V_135 ;
}
static int F_51 ( struct V_1 * V_2 ,
struct V_30 * V_31 ,
struct V_132 * V_133 ,
unsigned int * V_136 )
{
unsigned int V_72 = F_25 ( V_133 -> V_138 ) ;
int V_71 ;
for ( V_71 = 0 ; V_71 < V_133 -> V_140 ; V_71 ++ ) {
unsigned int V_3 = V_136 [ V_71 ] ;
int V_137 ;
V_137 = F_49 ( V_2 , V_31 , V_133 , F_50 , 0 ) ;
if ( V_137 )
return V_137 ;
F_2 ( F_52 ( V_72 ) | F_53 ( V_3 ) ,
V_2 -> V_58 + F_54 ( V_72 ) ) ;
V_31 -> V_142 [ V_72 ] = V_3 ;
}
return V_133 -> V_140 ;
}
static int F_55 ( struct V_1 * V_2 ,
struct V_30 * V_31 ,
struct V_132 * V_133 ,
unsigned int * V_136 )
{
unsigned int V_93 ;
V_93 = F_17 ( V_2 -> V_58 + V_95 ) ;
V_136 [ 1 ] = F_56 ( V_93 ) ;
return V_133 -> V_140 ;
}
static int F_57 ( struct V_1 * V_2 ,
struct V_30 * V_31 ,
struct V_132 * V_133 ,
unsigned int * V_136 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( F_58 ( V_31 , V_136 ) ) {
V_6 -> V_60 = V_31 -> V_143 ;
F_13 ( F_14 ( V_6 -> V_60 ) ,
V_2 -> V_58 + V_59 ) ;
}
V_136 [ 1 ] = V_31 -> V_143 ;
return V_133 -> V_140 ;
}
static int F_59 ( struct V_1 * V_2 ,
struct V_30 * V_31 ,
struct V_132 * V_133 ,
unsigned int * V_136 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_53 ;
unsigned int V_93 ;
unsigned int V_62 ;
unsigned int V_63 ;
switch ( V_136 [ 0 ] ) {
case V_144 :
F_10 ( V_2 ) ;
V_53 = F_7 ( V_2 , 2 , V_136 [ 1 ] ,
V_56 ) ;
F_12 ( V_2 , 2 , V_53 ) ;
F_21 ( V_2 , 2 , true ) ;
break;
case V_145 :
F_21 ( V_2 , 2 , false ) ;
F_10 ( V_2 ) ;
break;
case V_146 :
V_136 [ 1 ] = 0 ;
V_136 [ 2 ] = V_147 | V_148 |
V_149 ;
if ( V_6 -> V_66 & F_22 ( 2 ) ) {
V_136 [ 1 ] |= V_147 ;
V_136 [ 1 ] |= V_148 ;
}
V_93 = F_17 ( V_2 -> V_58 + V_95 ) ;
if ( V_93 & V_109 ) {
V_136 [ 1 ] &= ~ V_148 ;
V_136 [ 1 ] |= V_149 ;
}
break;
case V_150 :
switch ( V_136 [ 1 ] ) {
case V_151 :
V_62 = V_152 ;
V_63 = V_153 ;
break;
case V_154 :
V_62 = V_115 ;
V_63 = V_121 ;
break;
case V_155 :
V_62 = V_115 ;
V_63 = V_139 ;
break;
case V_156 :
V_62 = V_157 ;
V_63 = V_158 ;
break;
default:
return - V_159 ;
}
F_21 ( V_2 , 2 , false ) ;
F_10 ( V_2 ) ;
F_18 ( V_2 , 2 , V_63 ) ;
V_6 -> V_62 &= ~ V_160 ;
V_6 -> V_62 |= V_62 ;
F_13 ( V_6 -> V_62 , V_2 -> V_58 + V_108 ) ;
break;
default:
return - V_159 ;
}
return V_133 -> V_140 ;
}
static int F_60 ( struct V_1 * V_2 ,
struct V_30 * V_31 ,
struct V_132 * V_133 ,
unsigned int * V_136 )
{
int V_71 ;
for ( V_71 = 0 ; V_71 < V_133 -> V_140 ; V_71 ++ )
V_136 [ V_71 ] = F_16 ( V_2 , 2 ) ;
return V_133 -> V_140 ;
}
static void F_61 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_11 * V_12 ;
int V_161 ;
int V_71 ;
for ( V_71 = 0 ; V_71 < 2 ; V_71 ++ ) {
V_12 = & V_6 -> V_12 [ V_71 ] ;
for ( V_161 = 2 ; V_161 >= 0 ; V_161 -- ) {
V_12 -> V_85 = F_62 ( V_2 -> V_162 ,
V_163 << V_161 ,
& V_12 -> V_20 ,
V_164 ) ;
if ( V_12 -> V_85 )
break;
}
if ( ! V_12 -> V_85 )
break;
V_12 -> V_38 = V_163 << V_161 ;
if ( V_71 == 0 )
V_6 -> V_123 = 1 ;
if ( V_71 == 1 )
V_6 -> V_89 = 1 ;
}
}
static void F_63 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_11 * V_12 ;
int V_71 ;
if ( ! V_6 )
return;
for ( V_71 = 0 ; V_71 < 2 ; V_71 ++ ) {
V_12 = & V_6 -> V_12 [ V_71 ] ;
if ( V_12 -> V_85 ) {
F_64 ( V_2 -> V_162 , V_12 -> V_38 ,
V_12 -> V_85 , V_12 -> V_20 ) ;
}
}
}
static void F_65 ( struct V_1 * V_2 )
{
F_13 ( 0 , V_2 -> V_58 + V_108 ) ;
F_2 ( 0 , V_2 -> V_58 + V_67 ) ;
F_17 ( V_2 -> V_58 + V_95 ) ;
}
static int F_66 ( struct V_1 * V_2 ,
unsigned long V_134 )
{
struct V_165 * V_166 = F_67 ( V_2 ) ;
const struct V_167 * V_168 = NULL ;
struct V_5 * V_6 ;
struct V_30 * V_31 ;
unsigned int V_93 ;
int V_137 ;
if ( V_134 < F_68 ( V_169 ) )
V_168 = & V_169 [ V_134 ] ;
if ( ! V_168 )
return - V_170 ;
V_2 -> V_171 = V_168 ;
V_2 -> V_172 = V_168 -> V_173 ;
V_6 = F_69 ( V_2 , sizeof( * V_6 ) ) ;
if ( ! V_6 )
return - V_174 ;
V_137 = F_70 ( V_2 ) ;
if ( V_137 )
return V_137 ;
F_71 ( V_166 ) ;
V_2 -> V_58 = F_72 ( V_166 , 1 ) ;
V_6 -> V_15 = F_72 ( V_166 , 0 ) ;
V_6 -> V_8 = F_72 ( V_166 , 2 ) ;
F_65 ( V_2 ) ;
if ( V_166 -> V_90 > 0 ) {
V_137 = F_73 ( V_166 -> V_90 , F_38 , V_175 ,
V_2 -> V_172 , V_2 ) ;
if ( V_137 == 0 ) {
V_2 -> V_90 = V_166 -> V_90 ;
F_61 ( V_2 ) ;
}
}
V_93 = F_17 ( V_2 -> V_58 + V_95 ) ;
if ( F_74 ( V_93 ) == V_176 ||
V_134 == V_177 )
V_6 -> V_52 = V_178 ;
else
V_6 -> V_52 = V_179 ;
V_137 = F_75 ( V_2 , 5 ) ;
if ( V_137 )
return V_137 ;
V_31 = & V_2 -> V_180 [ 0 ] ;
V_31 -> type = V_181 ;
V_31 -> V_182 = V_183 | V_184 | V_185 | V_186 ;
V_31 -> V_69 = 16 ;
V_31 -> V_187 = V_168 -> V_188 ? 0xffff : 0x0fff ;
V_31 -> V_189 = & V_190 ;
V_31 -> V_191 = F_48 ;
if ( V_2 -> V_90 ) {
V_2 -> V_92 = V_31 ;
V_31 -> V_182 |= V_192 ;
V_31 -> V_193 = V_31 -> V_69 ;
V_31 -> V_194 = F_41 ;
V_31 -> V_195 = F_40 ;
V_31 -> V_196 = F_46 ;
}
V_31 = & V_2 -> V_180 [ 1 ] ;
if ( V_168 -> V_197 ) {
V_31 -> type = V_198 ;
V_31 -> V_182 = V_199 | V_185 | V_184 ;
V_31 -> V_69 = 8 ;
V_31 -> V_187 = 0x3fff ;
V_31 -> V_189 = & V_200 ;
V_31 -> V_201 = F_51 ;
V_137 = F_76 ( V_31 ) ;
if ( V_137 )
return V_137 ;
} else {
V_31 -> type = V_202 ;
}
V_31 = & V_2 -> V_180 [ 2 ] ;
V_31 -> type = V_203 ;
V_31 -> V_182 = V_183 ;
V_31 -> V_69 = 4 ;
V_31 -> V_187 = 1 ;
V_31 -> V_189 = & V_204 ;
V_31 -> V_205 = F_55 ;
V_31 = & V_2 -> V_180 [ 3 ] ;
V_31 -> type = V_206 ;
V_31 -> V_182 = V_199 ;
V_31 -> V_69 = 4 ;
V_31 -> V_187 = 1 ;
V_31 -> V_189 = & V_204 ;
V_31 -> V_205 = F_57 ;
V_31 = & V_2 -> V_180 [ 4 ] ;
V_31 -> type = V_207 ;
V_31 -> V_182 = V_183 ;
V_31 -> V_69 = 1 ;
V_31 -> V_187 = 0x00ffffff ;
V_31 -> V_208 = F_59 ;
V_31 -> V_191 = F_60 ;
return 0 ;
}
static void F_77 ( struct V_1 * V_2 )
{
F_78 ( V_2 ) ;
F_63 ( V_2 ) ;
}
static int F_79 ( struct V_165 * V_2 ,
const struct V_209 * V_210 )
{
return F_80 ( V_2 , & V_211 , V_210 -> V_212 ) ;
}
