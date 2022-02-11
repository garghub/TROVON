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
if ( ( V_93 & V_102 ) &&
( V_6 -> V_62 & V_103 ) ) {
unsigned short V_3 ;
int V_71 ;
for ( V_71 = 0 ; V_71 < V_33 -> V_104 ; V_71 ++ ) {
V_3 = F_17 ( V_2 -> V_58 + V_105 ) ;
F_37 ( V_31 , & V_3 , 1 ) ;
}
V_6 -> V_62 |= V_103 ;
F_13 ( V_6 -> V_62 , V_2 -> V_58 + V_106 ) ;
}
if ( V_93 & V_107 ) {
F_10 ( V_2 ) ;
}
if ( V_93 & V_108 ) {
F_4 ( V_109 , V_6 -> V_15 + V_26 ) ;
F_33 ( V_2 , V_31 ) ;
}
if ( V_33 -> V_42 == V_43 && V_34 -> V_88 >= V_33 -> V_44 )
V_34 -> V_83 |= V_110 ;
F_39 ( V_2 , V_31 ) ;
return V_111 ;
}
static int F_40 ( struct V_1 * V_2 ,
struct V_30 * V_31 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_32 * V_33 = & V_31 -> V_34 -> V_33 ;
unsigned int V_53 ;
V_6 -> V_62 = V_112 |
V_113 ;
F_4 ( V_109 , V_6 -> V_15 + V_26 ) ;
V_6 -> V_80 = 0 ;
F_24 ( V_2 , V_31 , V_33 -> V_104 , V_33 -> V_70 ) ;
if ( V_33 -> V_114 == V_115 )
F_23 ( V_2 , true ) ;
if ( V_33 -> V_116 == V_117 ) {
V_53 = F_7 ( V_2 , 1 , V_33 -> V_118 ,
V_33 -> V_45 ) ;
F_18 ( V_2 , 1 , V_119 ) ;
F_12 ( V_2 , 1 , V_53 ) ;
}
V_53 = F_7 ( V_2 , 0 , V_33 -> V_120 , V_33 -> V_45 ) ;
F_18 ( V_2 , 0 , V_119 ) ;
F_12 ( V_2 , 0 , V_53 ) ;
if ( V_6 -> V_121 )
F_5 ( V_2 , V_31 ) ;
else
V_6 -> V_62 |= V_103 ;
F_13 ( V_6 -> V_62 , V_2 -> V_58 + V_106 ) ;
if ( V_33 -> V_116 == V_117 )
F_21 ( V_2 , 1 , true ) ;
F_21 ( V_2 , 0 , true ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 ,
struct V_30 * V_31 ,
struct V_32 * V_33 )
{
unsigned int V_122 ;
int V_123 = 0 ;
V_123 |= F_42 ( & V_33 -> V_114 , V_124 | V_115 ) ;
V_123 |= F_42 ( & V_33 -> V_116 ,
V_117 | V_125 ) ;
V_123 |= F_42 ( & V_33 -> V_126 , V_117 ) ;
V_123 |= F_42 ( & V_33 -> V_127 , V_43 ) ;
V_123 |= F_42 ( & V_33 -> V_42 , V_43 | V_128 ) ;
if ( V_123 )
return 1 ;
V_123 |= F_43 ( V_33 -> V_114 ) ;
V_123 |= F_43 ( V_33 -> V_116 ) ;
V_123 |= F_43 ( V_33 -> V_42 ) ;
if ( V_123 )
return 2 ;
V_123 |= F_44 ( & V_33 -> V_129 , 0 ) ;
if ( V_33 -> V_116 == V_117 ) {
V_123 |= F_45 ( & V_33 -> V_118 ,
100000 ) ;
}
V_123 |= F_45 ( & V_33 -> V_120 , 10000 ) ;
V_123 |= F_45 ( & V_33 -> V_104 , 1 ) ;
V_123 |= F_44 ( & V_33 -> V_41 ,
V_33 -> V_104 ) ;
if ( V_33 -> V_42 == V_43 )
V_123 |= F_45 ( & V_33 -> V_44 , 1 ) ;
else
V_123 |= F_44 ( & V_33 -> V_44 , 0 ) ;
if ( V_123 )
return 3 ;
if ( V_33 -> V_116 == V_117 ) {
V_122 = V_33 -> V_120 * V_33 -> V_41 ;
V_123 |= F_45 ( & V_33 -> V_118 , V_122 ) ;
}
if ( V_123 )
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
F_13 ( V_6 -> V_62 , V_2 -> V_58 + V_106 ) ;
F_17 ( V_2 -> V_58 + V_95 ) ;
V_6 -> V_80 = 0 ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 ,
struct V_30 * V_31 ,
struct V_130 * V_131 ,
unsigned long V_132 )
{
unsigned int V_93 ;
V_93 = F_17 ( V_2 -> V_58 + V_95 ) ;
if ( ( V_93 & V_133 ) == 0 )
return 0 ;
return - V_134 ;
}
static int F_48 ( struct V_1 * V_2 ,
struct V_30 * V_31 ,
struct V_130 * V_131 ,
unsigned int * V_135 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_53 ;
int V_136 ;
int V_71 ;
V_6 -> V_62 = V_112 |
V_113 ;
F_13 ( V_6 -> V_62 , V_2 -> V_58 + V_106 ) ;
F_24 ( V_2 , V_31 , 1 , & V_131 -> V_137 ) ;
F_18 ( V_2 , 0 , V_138 ) ;
F_21 ( V_2 , 0 , true ) ;
V_53 = F_7 ( V_2 , 0 , 10000 , V_57 ) ;
for ( V_71 = 0 ; V_71 < V_131 -> V_139 ; V_71 ++ ) {
F_12 ( V_2 , 0 , V_53 ) ;
V_136 = F_49 ( V_2 , V_31 , V_131 , F_47 , 0 ) ;
if ( V_136 )
return V_136 ;
V_135 [ V_71 ] = F_17 ( V_2 -> V_58 + V_105 ) ;
}
return V_131 -> V_139 ;
}
static int F_50 ( struct V_1 * V_2 ,
struct V_30 * V_31 ,
struct V_130 * V_131 ,
unsigned long V_132 )
{
unsigned int V_93 ;
V_93 = F_17 ( V_2 -> V_58 + V_95 ) ;
if ( V_93 & V_140 )
return 0 ;
return - V_134 ;
}
static int F_51 ( struct V_1 * V_2 ,
struct V_30 * V_31 ,
struct V_130 * V_131 ,
unsigned int * V_135 )
{
unsigned int V_72 = F_25 ( V_131 -> V_137 ) ;
int V_71 ;
for ( V_71 = 0 ; V_71 < V_131 -> V_139 ; V_71 ++ ) {
unsigned int V_3 = V_135 [ V_71 ] ;
int V_136 ;
V_136 = F_49 ( V_2 , V_31 , V_131 , F_50 , 0 ) ;
if ( V_136 )
return V_136 ;
F_2 ( F_52 ( V_72 ) | F_53 ( V_3 ) ,
V_2 -> V_58 + F_54 ( V_72 ) ) ;
V_31 -> V_141 [ V_72 ] = V_3 ;
}
return V_131 -> V_139 ;
}
static int F_55 ( struct V_1 * V_2 ,
struct V_30 * V_31 ,
struct V_130 * V_131 ,
unsigned int * V_135 )
{
unsigned int V_93 ;
V_93 = F_17 ( V_2 -> V_58 + V_95 ) ;
V_135 [ 1 ] = F_56 ( V_93 ) ;
return V_131 -> V_139 ;
}
static int F_57 ( struct V_1 * V_2 ,
struct V_30 * V_31 ,
struct V_130 * V_131 ,
unsigned int * V_135 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( F_58 ( V_31 , V_135 ) ) {
V_6 -> V_60 = V_31 -> V_142 ;
F_13 ( F_14 ( V_6 -> V_60 ) ,
V_2 -> V_58 + V_59 ) ;
}
V_135 [ 1 ] = V_31 -> V_142 ;
return V_131 -> V_139 ;
}
static int F_59 ( struct V_1 * V_2 ,
struct V_30 * V_31 ,
struct V_130 * V_131 ,
unsigned int * V_135 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_53 ;
unsigned int V_93 ;
unsigned int V_62 ;
unsigned int V_63 ;
switch ( V_135 [ 0 ] ) {
case V_143 :
F_10 ( V_2 ) ;
V_53 = F_7 ( V_2 , 2 , V_135 [ 1 ] ,
V_56 ) ;
F_12 ( V_2 , 2 , V_53 ) ;
F_21 ( V_2 , 2 , true ) ;
break;
case V_144 :
F_21 ( V_2 , 2 , false ) ;
F_10 ( V_2 ) ;
break;
case V_145 :
V_135 [ 1 ] = 0 ;
V_135 [ 2 ] = V_146 | V_147 |
V_148 ;
if ( V_6 -> V_66 & F_22 ( 2 ) ) {
V_135 [ 1 ] |= V_146 ;
V_135 [ 1 ] |= V_147 ;
}
V_93 = F_17 ( V_2 -> V_58 + V_95 ) ;
if ( V_93 & V_107 ) {
V_135 [ 1 ] &= ~ V_147 ;
V_135 [ 1 ] |= V_148 ;
}
break;
case V_149 :
switch ( V_135 [ 1 ] ) {
case V_150 :
V_62 = V_151 ;
V_63 = V_152 ;
break;
case V_153 :
V_62 = V_113 ;
V_63 = V_119 ;
break;
case V_154 :
V_62 = V_113 ;
V_63 = V_138 ;
break;
case V_155 :
V_62 = V_156 ;
V_63 = V_157 ;
break;
default:
return - V_158 ;
}
F_21 ( V_2 , 2 , false ) ;
F_10 ( V_2 ) ;
F_18 ( V_2 , 2 , V_63 ) ;
V_6 -> V_62 &= ~ V_159 ;
V_6 -> V_62 |= V_62 ;
F_13 ( V_6 -> V_62 , V_2 -> V_58 + V_106 ) ;
break;
default:
return - V_158 ;
}
return V_131 -> V_139 ;
}
static int F_60 ( struct V_1 * V_2 ,
struct V_30 * V_31 ,
struct V_130 * V_131 ,
unsigned int * V_135 )
{
int V_71 ;
for ( V_71 = 0 ; V_71 < V_131 -> V_139 ; V_71 ++ )
V_135 [ V_71 ] = F_16 ( V_2 , 2 ) ;
return V_131 -> V_139 ;
}
static void F_61 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_11 * V_12 ;
int V_160 ;
int V_71 ;
for ( V_71 = 0 ; V_71 < 2 ; V_71 ++ ) {
V_12 = & V_6 -> V_12 [ V_71 ] ;
for ( V_160 = 2 ; V_160 >= 0 ; V_160 -- ) {
V_12 -> V_85 = F_62 ( V_2 -> V_161 ,
V_162 << V_160 ,
& V_12 -> V_20 ,
V_163 ) ;
if ( V_12 -> V_85 )
break;
}
if ( ! V_12 -> V_85 )
break;
V_12 -> V_38 = V_162 << V_160 ;
if ( V_71 == 0 )
V_6 -> V_121 = 1 ;
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
F_64 ( V_2 -> V_161 , V_12 -> V_38 ,
V_12 -> V_85 , V_12 -> V_20 ) ;
}
}
}
static void F_65 ( struct V_1 * V_2 )
{
F_13 ( 0 , V_2 -> V_58 + V_106 ) ;
F_2 ( 0 , V_2 -> V_58 + V_67 ) ;
F_17 ( V_2 -> V_58 + V_95 ) ;
}
static int F_66 ( struct V_1 * V_2 ,
unsigned long V_132 )
{
struct V_164 * V_165 = F_67 ( V_2 ) ;
const struct V_166 * V_167 = NULL ;
struct V_5 * V_6 ;
struct V_30 * V_31 ;
unsigned int V_93 ;
int V_136 ;
if ( V_132 < F_68 ( V_168 ) )
V_167 = & V_168 [ V_132 ] ;
if ( ! V_167 )
return - V_169 ;
V_2 -> V_170 = V_167 ;
V_2 -> V_171 = V_167 -> V_172 ;
V_6 = F_69 ( V_2 , sizeof( * V_6 ) ) ;
if ( ! V_6 )
return - V_173 ;
V_136 = F_70 ( V_2 ) ;
if ( V_136 )
return V_136 ;
F_71 ( V_165 ) ;
V_2 -> V_58 = F_72 ( V_165 , 1 ) ;
V_6 -> V_15 = F_72 ( V_165 , 0 ) ;
V_6 -> V_8 = F_72 ( V_165 , 2 ) ;
F_65 ( V_2 ) ;
if ( V_165 -> V_90 > 0 ) {
V_136 = F_73 ( V_165 -> V_90 , F_38 , V_174 ,
V_2 -> V_171 , V_2 ) ;
if ( V_136 == 0 ) {
V_2 -> V_90 = V_165 -> V_90 ;
F_61 ( V_2 ) ;
}
}
V_93 = F_17 ( V_2 -> V_58 + V_95 ) ;
if ( F_74 ( V_93 ) == V_175 ||
V_132 == V_176 )
V_6 -> V_52 = V_177 ;
else
V_6 -> V_52 = V_178 ;
V_136 = F_75 ( V_2 , 5 ) ;
if ( V_136 )
return V_136 ;
V_31 = & V_2 -> V_179 [ 0 ] ;
V_31 -> type = V_180 ;
V_31 -> V_181 = V_182 | V_183 | V_184 | V_185 ;
V_31 -> V_69 = 16 ;
V_31 -> V_186 = V_167 -> V_187 ? 0xffff : 0x0fff ;
V_31 -> V_188 = & V_189 ;
V_31 -> V_190 = F_48 ;
if ( V_2 -> V_90 ) {
V_2 -> V_92 = V_31 ;
V_31 -> V_181 |= V_191 ;
V_31 -> V_192 = V_31 -> V_69 ;
V_31 -> V_193 = F_41 ;
V_31 -> V_194 = F_40 ;
V_31 -> V_195 = F_46 ;
}
V_31 = & V_2 -> V_179 [ 1 ] ;
if ( V_167 -> V_196 ) {
V_31 -> type = V_197 ;
V_31 -> V_181 = V_198 | V_184 | V_183 ;
V_31 -> V_69 = 8 ;
V_31 -> V_186 = 0x3fff ;
V_31 -> V_188 = & V_199 ;
V_31 -> V_200 = F_51 ;
V_136 = F_76 ( V_31 ) ;
if ( V_136 )
return V_136 ;
} else {
V_31 -> type = V_201 ;
}
V_31 = & V_2 -> V_179 [ 2 ] ;
V_31 -> type = V_202 ;
V_31 -> V_181 = V_182 ;
V_31 -> V_69 = 4 ;
V_31 -> V_186 = 1 ;
V_31 -> V_188 = & V_203 ;
V_31 -> V_204 = F_55 ;
V_31 = & V_2 -> V_179 [ 3 ] ;
V_31 -> type = V_205 ;
V_31 -> V_181 = V_198 ;
V_31 -> V_69 = 4 ;
V_31 -> V_186 = 1 ;
V_31 -> V_188 = & V_203 ;
V_31 -> V_204 = F_57 ;
V_31 = & V_2 -> V_179 [ 4 ] ;
V_31 -> type = V_206 ;
V_31 -> V_181 = V_182 ;
V_31 -> V_69 = 1 ;
V_31 -> V_186 = 0x00ffffff ;
V_31 -> V_207 = F_59 ;
V_31 -> V_190 = F_60 ;
return 0 ;
}
static void F_77 ( struct V_1 * V_2 )
{
F_78 ( V_2 ) ;
F_63 ( V_2 ) ;
}
static int F_79 ( struct V_164 * V_2 ,
const struct V_208 * V_209 )
{
return F_80 ( V_2 , & V_210 , V_209 -> V_211 ) ;
}
