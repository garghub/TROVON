static void
F_1 ( struct V_1 * V_2 , int V_3 , int V_4 ,
unsigned int V_5 )
{
const struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = V_2 -> V_11 ;
unsigned short V_12 ;
F_2 ( 1 << V_3 , V_2 -> V_13 + V_14 ) ;
V_10 -> V_15 = F_3 ( V_10 -> V_15 , V_7 -> V_16 [ V_4 ] ,
V_17 |
V_18 ) ;
F_2 ( V_10 -> V_15 | V_19 ,
V_2 -> V_13 + V_20 ) ;
V_12 = ( unsigned short ) V_5 << ( 16 - V_7 -> V_21 ) ;
if ( ( V_10 -> V_15 & V_17 ) ==
V_22 ) {
V_12 ^= 0x8000 ;
}
F_2 ( V_12 , V_2 -> V_13 + V_23 ) ;
F_4 ( V_2 -> V_13 + V_24 ) ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_25 * V_26 ,
struct V_27 * V_28 ,
unsigned int * V_5 )
{
unsigned int V_3 = F_6 ( V_28 -> V_29 ) ;
unsigned int V_4 = F_7 ( V_28 -> V_29 ) ;
unsigned int V_30 = V_26 -> V_31 [ V_3 ] ;
int V_32 ;
for ( V_32 = 0 ; V_32 < V_28 -> V_33 ; V_32 ++ ) {
V_30 = V_5 [ V_32 ] ;
F_1 ( V_2 , V_3 , V_4 , V_30 ) ;
}
V_26 -> V_31 [ V_3 ] = V_30 ;
return V_28 -> V_33 ;
}
static void F_8 ( struct V_1 * V_2 ,
struct V_25 * V_26 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
unsigned long V_34 ;
if ( ! F_9 ( V_35 , & V_10 -> V_36 ) )
return;
F_10 ( & V_10 -> V_37 , V_34 ) ;
V_10 -> V_38 = 0 ;
F_11 ( 0 , V_10 -> V_39 + V_40 ) ;
while ( V_10 -> V_41 && V_10 -> V_42 != V_43 ) {
F_12 ( & V_10 -> V_37 , V_34 ) ;
F_10 ( & V_10 -> V_37 , V_34 ) ;
}
F_12 ( & V_10 -> V_37 , V_34 ) ;
F_2 ( 0 , V_2 -> V_13 + V_14 ) ;
V_10 -> V_15 =
F_3 ( V_10 -> V_15 ,
V_44 | V_45 ,
V_46 | V_47 ) ;
F_2 ( V_10 -> V_15 | V_19 ,
V_2 -> V_13 + V_20 ) ;
}
static void F_13 ( struct V_1 * V_2 ,
struct V_25 * V_26 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
struct V_48 * V_49 = & V_26 -> V_50 -> V_49 ;
unsigned long V_34 ;
F_14 ( V_35 , & V_10 -> V_36 ) ;
F_10 ( & V_10 -> V_37 , V_34 ) ;
if ( V_49 -> V_51 == V_52 )
V_10 -> V_38 = V_53 | V_54 ;
else
V_10 -> V_38 = V_54 ;
F_11 ( V_10 -> V_38 , V_10 -> V_39 + V_40 ) ;
F_12 ( & V_10 -> V_37 , V_34 ) ;
}
static void F_15 ( struct V_1 * V_2 ,
struct V_25 * V_26 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
struct V_48 * V_49 = & V_26 -> V_50 -> V_49 ;
unsigned int V_55 = F_16 ( V_26 ) ;
unsigned int V_56 ;
unsigned int V_57 ;
unsigned short V_58 ;
unsigned int V_32 , V_33 ;
V_56 = F_17 ( V_26 ) / V_55 ;
if ( V_49 -> V_51 == V_59 ) {
if ( V_56 > V_10 -> V_60 )
V_56 = V_10 -> V_60 ;
}
V_58 = F_4 ( V_2 -> V_13 + V_20 ) ;
switch ( V_58 & V_61 ) {
case V_62 :
V_57 = V_63 ;
if ( V_49 -> V_51 == V_59 &&
V_10 -> V_60 == 0 ) {
V_26 -> V_50 -> V_64 |= V_65 ;
F_18 ( V_2 , V_26 ) ;
return;
}
break;
case V_66 :
V_57 = V_67 ;
break;
case V_68 :
V_57 = V_69 ;
break;
default:
V_57 = V_70 ;
break;
}
if ( V_57 >= V_67 ) {
if ( V_56 == 0 ) {
F_19 ( V_2 -> V_71 , L_1 ) ;
V_26 -> V_50 -> V_64 |= V_72 ;
}
}
V_57 /= V_49 -> V_73 ;
if ( V_56 > V_57 )
V_56 = V_57 ;
for ( V_33 = 0 ; V_33 < V_56 ; V_33 ++ ) {
F_20 ( V_26 , & V_10 -> V_74 [ 0 ] ,
V_55 ) ;
for ( V_32 = 0 ; V_32 < V_49 -> V_73 ; V_32 ++ ) {
F_2 ( V_10 -> V_74 [ V_10 -> V_75 [ V_32 ] ] ,
V_2 -> V_13 + V_23 ) ;
}
}
if ( V_49 -> V_51 == V_59 ) {
V_10 -> V_60 -= V_56 ;
if ( V_10 -> V_60 == 0 ) {
V_10 -> V_15 = F_3 ( V_10 -> V_15 ,
V_45 ,
V_47 ) ;
F_2 ( V_10 -> V_15 , V_2 -> V_13 + V_20 ) ;
}
}
if ( ( V_10 -> V_15 & V_46 ) ==
V_76 ) {
unsigned short V_77 ;
if ( V_49 -> V_78 == V_79 ) {
V_77 = V_80 ;
} else {
if ( V_49 -> V_81 & V_82 )
V_77 = V_83 ;
else
V_77 = V_84 ;
}
V_10 -> V_15 =
F_3 ( V_10 -> V_15 , V_77 , V_46 ) ;
F_2 ( V_10 -> V_15 , V_2 -> V_13 + V_20 ) ;
}
F_18 ( V_2 , V_26 ) ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_25 * V_26 ,
unsigned int V_85 )
{
struct V_48 * V_49 = & V_26 -> V_50 -> V_49 ;
if ( V_85 != V_49 -> V_86 )
return - V_87 ;
V_26 -> V_50 -> V_88 = NULL ;
F_13 ( V_2 , V_26 ) ;
return 1 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_25 * V_26 ,
struct V_48 * V_49 )
{
const struct V_6 * V_7 = V_2 -> V_8 ;
unsigned int V_89 ;
unsigned int V_90 = 0 ;
int V_32 ;
V_89 = V_7 -> V_91 [ F_7 ( V_49 -> V_92 [ 0 ] ) ] ;
for ( V_32 = 0 ; V_32 < V_49 -> V_73 ; V_32 ++ ) {
unsigned int V_3 = F_6 ( V_49 -> V_92 [ V_32 ] ) ;
if ( V_90 & ( 1 << V_3 ) ) {
F_23 ( V_2 -> V_71 ,
L_2 ,
V_93 ) ;
return - V_87 ;
}
V_90 |= 1 << V_3 ;
if ( V_7 -> V_91 [ F_7 ( V_49 -> V_92 [ V_32 ] ) ] !=
V_89 ) {
F_23 ( V_2 -> V_71 ,
L_3 ,
V_93 ) ;
return - V_87 ;
}
}
return 0 ;
}
static int
F_24 ( struct V_1 * V_2 , struct V_25 * V_26 ,
struct V_48 * V_49 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
int V_94 = 0 ;
unsigned int V_95 ;
V_94 |= F_25 ( & V_49 -> V_96 , V_97 | V_52 ) ;
V_94 |= F_25 ( & V_49 -> V_78 ,
V_52 | V_79 ) ;
V_94 |= F_25 ( & V_49 -> V_98 , V_99 ) ;
V_94 |= F_25 ( & V_49 -> V_100 , V_59 ) ;
V_94 |= F_25 ( & V_49 -> V_51 ,
V_59 | V_52 | V_101 ) ;
if ( V_94 )
return 1 ;
V_94 |= F_26 ( V_49 -> V_96 ) ;
V_94 |= F_26 ( V_49 -> V_78 ) ;
V_94 |= F_26 ( V_49 -> V_51 ) ;
V_95 = 0 ;
if ( V_49 -> V_96 & V_52 )
V_95 ++ ;
if ( V_49 -> V_78 & V_52 )
V_95 ++ ;
if ( V_49 -> V_51 & V_52 )
V_95 ++ ;
if ( V_95 > 1 )
V_94 |= - V_87 ;
if ( V_94 )
return 2 ;
switch ( V_49 -> V_96 ) {
case V_97 :
V_94 |= F_27 ( & V_49 -> V_86 , 0 ) ;
break;
case V_52 :
if ( V_49 -> V_86 & ~ V_102 ) {
V_49 -> V_86 =
F_3 ( V_49 -> V_86 , 0 , ~ V_102 ) ;
V_94 |= - V_87 ;
}
if ( V_49 -> V_86 & V_102 & ~ V_103 ) {
V_49 -> V_86 = F_3 ( V_49 -> V_86 , 0 ,
V_102 & ~ V_103 ) ;
V_94 |= - V_87 ;
}
break;
}
switch ( V_49 -> V_78 ) {
case V_79 :
V_94 |= F_28 ( & V_49 -> V_81 ,
V_104 ) ;
V_95 = V_49 -> V_73 * V_105 ;
if ( V_95 < V_106 )
V_95 = V_106 ;
V_94 |= F_29 ( & V_49 -> V_81 , V_95 ) ;
break;
case V_52 :
if ( V_49 -> V_81 & ~ V_102 ) {
V_49 -> V_81 =
F_3 ( V_49 -> V_81 , 0 , ~ V_102 ) ;
V_94 |= - V_87 ;
}
if ( V_49 -> V_81 & V_102 &
~ ( V_103 | V_82 ) ) {
V_49 -> V_81 =
F_3 ( V_49 -> V_81 , 0 ,
V_102 & ~ ( V_103 | V_82 ) ) ;
V_94 |= - V_87 ;
}
break;
}
V_94 |= F_27 ( & V_49 -> V_107 , 0 ) ;
V_94 |= F_27 ( & V_49 -> V_108 , V_49 -> V_73 ) ;
switch ( V_49 -> V_51 ) {
case V_59 :
V_94 |= F_29 ( & V_49 -> V_109 , 1 ) ;
break;
case V_52 :
if ( V_49 -> V_109 & ~ V_102 ) {
V_49 -> V_109 =
F_3 ( V_49 -> V_109 , 0 , ~ V_102 ) ;
V_94 |= - V_87 ;
}
if ( V_49 -> V_109 & V_102 & ~ V_103 ) {
V_49 -> V_109 =
F_3 ( V_49 -> V_109 , 0 , V_102 & ~ V_103 ) ;
}
break;
case V_101 :
V_94 |= F_27 ( & V_49 -> V_109 , 0 ) ;
break;
}
if ( V_94 )
return 3 ;
if ( V_49 -> V_78 == V_79 ) {
V_95 = V_49 -> V_81 ;
F_30 ( V_110 ,
& V_10 -> V_111 ,
& V_10 -> V_112 ,
& V_95 , V_49 -> V_34 ) ;
V_94 |= F_27 ( & V_49 -> V_81 , V_95 ) ;
}
if ( V_94 )
return 4 ;
if ( V_49 -> V_92 && V_49 -> V_73 > 0 )
V_94 |= F_22 ( V_2 , V_26 , V_49 ) ;
if ( V_94 )
return 5 ;
return 0 ;
}
static void F_31 ( struct V_1 * V_2 ,
struct V_25 * V_26 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
unsigned long V_113 = V_10 -> V_39 + V_114 ;
F_11 ( F_32 ( 0 , V_115 ) , V_10 -> V_39 + V_116 ) ;
F_11 ( F_32 ( 2 , V_115 ) , V_10 -> V_39 + V_116 ) ;
F_11 ( F_33 ( 2 , V_117 ) , V_10 -> V_39 + V_118 ) ;
F_34 ( V_113 , 0 , 2 , V_119 | V_120 ) ;
F_35 ( V_113 , 0 , 2 , V_10 -> V_111 ) ;
F_11 ( F_33 ( 0 , V_121 ) , V_10 -> V_39 + V_118 ) ;
F_34 ( V_113 , 0 , 0 , V_119 | V_120 ) ;
F_35 ( V_113 , 0 , 0 , V_10 -> V_112 ) ;
}
static int F_36 ( struct V_1 * V_2 , struct V_25 * V_26 )
{
const struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = V_2 -> V_11 ;
struct V_48 * V_49 = & V_26 -> V_50 -> V_49 ;
int V_4 ;
unsigned int V_32 , V_122 ;
unsigned int V_123 ;
unsigned int V_124 ;
unsigned long V_34 ;
if ( V_49 -> V_92 == NULL || V_49 -> V_73 == 0 )
return - V_87 ;
V_10 -> V_125 = 0 ;
for ( V_32 = 0 ; V_32 < V_49 -> V_73 ; V_32 ++ ) {
V_123 = F_6 ( V_49 -> V_92 [ V_32 ] ) ;
V_10 -> V_125 |= 1U << V_123 ;
V_124 = 0 ;
for ( V_122 = 0 ; V_122 < V_49 -> V_73 ; V_122 ++ ) {
if ( F_6 ( V_49 -> V_92 [ V_122 ] ) < V_123 )
V_124 ++ ;
}
V_10 -> V_75 [ V_124 ] = V_32 ;
}
F_2 ( V_10 -> V_125 , V_2 -> V_13 + V_14 ) ;
V_4 = F_7 ( V_49 -> V_92 [ 0 ] ) ;
V_10 -> V_15 =
F_3 ( V_10 -> V_15 ,
V_7 -> V_16 [ V_4 ] | V_76 |
V_126 ,
V_17 | V_18 |
V_46 | V_47 ) ;
F_2 ( V_10 -> V_15 | V_19 ,
V_2 -> V_13 + V_20 ) ;
if ( V_49 -> V_78 == V_79 )
F_31 ( V_2 , V_26 ) ;
if ( V_49 -> V_51 == V_59 )
V_10 -> V_60 = V_49 -> V_109 ;
else
V_10 -> V_60 = 0 ;
F_10 ( & V_10 -> V_37 , V_34 ) ;
if ( V_49 -> V_96 == V_97 ) {
V_26 -> V_50 -> V_88 = F_21 ;
} else {
V_10 -> V_38 |= V_53 ;
F_11 ( V_10 -> V_38 , V_10 -> V_39 + V_40 ) ;
}
F_12 ( & V_10 -> V_37 , V_34 ) ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_25 * V_26 )
{
F_8 ( V_2 , V_26 ) ;
return 0 ;
}
static void
F_38 ( struct V_1 * V_2 , struct V_25 * V_26 ,
void * V_5 , unsigned int V_127 , unsigned int V_128 )
{
const struct V_6 * V_7 = V_2 -> V_8 ;
struct V_48 * V_49 = & V_26 -> V_50 -> V_49 ;
unsigned short * V_129 = V_5 ;
unsigned int V_130 = V_127 / sizeof( * V_129 ) ;
unsigned int V_131 ;
unsigned int V_132 ;
unsigned int V_32 ;
V_132 = 16 - V_7 -> V_21 ;
if ( ( V_7 -> V_16 [ F_7 ( V_49 -> V_92 [ 0 ] ) ] &
V_17 ) == V_133 ) {
V_131 = 0 ;
} else {
V_131 = 32768 ;
}
for ( V_32 = 0 ; V_32 < V_130 ; V_32 ++ )
V_129 [ V_32 ] = ( V_129 [ V_32 ] << V_132 ) - V_131 ;
}
static T_1 F_39 ( int V_134 , void * V_135 )
{
struct V_1 * V_2 = V_135 ;
struct V_9 * V_10 = V_2 -> V_11 ;
struct V_25 * V_26 = V_2 -> V_136 ;
struct V_48 * V_49 ;
unsigned char V_137 , V_138 ;
unsigned char V_139 ;
int V_140 = 0 ;
unsigned long V_34 ;
V_137 = F_40 ( V_10 -> V_39 + V_40 ) & 0x3F ;
if ( V_137 ) {
V_140 = 1 ;
F_10 ( & V_10 -> V_37 , V_34 ) ;
V_138 = V_10 -> V_38 & V_137 ;
V_139 = V_10 -> V_38 & ~ V_137 ;
F_11 ( V_139 , V_10 -> V_39 + V_40 ) ;
V_10 -> V_41 = 1 ;
V_10 -> V_42 = V_43 ;
F_12 ( & V_10 -> V_37 , V_34 ) ;
if ( V_138 ) {
V_49 = & V_26 -> V_50 -> V_49 ;
if ( V_138 & V_53 ) {
V_10 -> V_38 &= ~ V_53 ;
if ( V_49 -> V_96 == V_52 )
F_13 ( V_2 , V_26 ) ;
else if ( V_49 -> V_51 == V_52 )
F_8 ( V_2 , V_26 ) ;
}
if ( V_138 & V_54 )
F_15 ( V_2 , V_26 ) ;
}
F_10 ( & V_10 -> V_37 , V_34 ) ;
if ( V_139 != V_10 -> V_38 ) {
F_11 ( V_10 -> V_38 ,
V_10 -> V_39 + V_40 ) ;
}
V_10 -> V_41 = 0 ;
F_12 ( & V_10 -> V_37 , V_34 ) ;
}
return F_41 ( V_140 ) ;
}
static int
F_42 ( struct V_1 * V_2 , unsigned long V_141 )
{
struct V_142 * V_142 = F_43 ( V_2 ) ;
const struct V_6 * V_7 = NULL ;
struct V_9 * V_10 ;
struct V_25 * V_26 ;
unsigned int V_134 ;
int V_143 ;
if ( V_141 < F_44 ( V_144 ) )
V_7 = & V_144 [ V_141 ] ;
if ( ! V_7 || ! V_7 -> V_145 ) {
F_19 ( V_2 -> V_71 ,
L_4 ) ;
return - V_87 ;
}
V_2 -> V_8 = V_7 ;
V_2 -> V_146 = V_7 -> V_145 ;
F_45 ( V_2 -> V_71 , L_5 ,
F_46 ( V_142 ) , V_2 -> V_146 ) ;
V_10 = F_47 ( V_2 , sizeof( * V_10 ) ) ;
if ( ! V_10 )
return - V_147 ;
V_143 = F_48 ( V_2 ) ;
if ( V_143 )
return V_143 ;
F_49 ( & V_10 -> V_37 ) ;
V_10 -> V_39 = F_50 ( V_142 , 2 ) ;
V_2 -> V_13 = F_50 ( V_142 , 3 ) ;
V_134 = V_142 -> V_134 ;
V_10 -> V_74 = F_51 ( sizeof( V_10 -> V_74 [ 0 ] ) *
V_7 -> V_148 , V_149 ) ;
if ( ! V_10 -> V_74 )
return - V_147 ;
V_10 -> V_75 = F_51 ( sizeof( V_10 -> V_75 [ 0 ] ) *
V_7 -> V_148 , V_149 ) ;
if ( ! V_10 -> V_75 )
return - V_147 ;
V_10 -> V_38 = 0 ;
F_11 ( 0 , V_10 -> V_39 + V_40 ) ;
F_2 ( V_150 , V_2 -> V_13 + V_20 ) ;
F_2 ( 0 , V_2 -> V_13 + V_14 ) ;
F_2 ( 0 , V_2 -> V_13 + V_151 ) ;
V_10 -> V_15 = V_44 | V_22 |
V_152 | V_45 ;
F_2 ( V_10 -> V_15 | V_19 ,
V_2 -> V_13 + V_20 ) ;
V_143 = F_52 ( V_2 , 1 ) ;
if ( V_143 )
return V_143 ;
V_26 = & V_2 -> V_153 [ 0 ] ;
V_26 -> type = V_154 ;
V_26 -> V_155 = V_156 | V_157 | V_158 ;
V_26 -> V_159 = V_7 -> V_148 ;
V_26 -> V_160 = ( 1 << V_7 -> V_21 ) - 1 ;
V_26 -> V_161 = V_7 -> V_162 ;
V_26 -> V_163 = F_5 ;
V_26 -> V_164 = V_165 ;
V_26 -> V_166 = V_26 -> V_159 ;
V_2 -> V_136 = V_26 ;
V_26 -> V_167 = F_36 ;
V_26 -> V_168 = F_24 ;
V_26 -> V_169 = F_37 ;
V_26 -> V_170 = F_38 ;
V_143 = F_53 ( V_26 ) ;
if ( V_143 )
return V_143 ;
if ( V_134 ) {
V_143 = F_54 ( V_134 , F_39 , V_171 ,
V_2 -> V_146 , V_2 ) ;
if ( V_143 < 0 ) {
F_19 ( V_2 -> V_71 ,
L_6 , V_134 ) ;
return V_143 ;
}
V_2 -> V_134 = V_134 ;
}
return 0 ;
}
static void F_55 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
F_56 ( V_2 ) ;
if ( V_10 ) {
F_57 ( V_10 -> V_74 ) ;
F_57 ( V_10 -> V_75 ) ;
}
}
static int F_58 ( struct V_142 * V_2 ,
const struct V_172 * V_173 )
{
return F_59 ( V_2 , & V_174 ,
V_173 -> V_175 ) ;
}
