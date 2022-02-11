static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 , V_6 , V_7 , V_8 ;
bool V_9 ;
const struct V_10 * V_11 ;
int V_12 ;
if ( V_4 -> V_13 != V_14 )
return;
V_9 = ! V_4 -> V_15 ;
V_7 = F_3 ( V_2 , V_16 ) ;
if ( V_7 & V_17 )
V_7 = V_4 -> V_18 [ 1 ] ;
else
V_7 = V_4 -> V_18 [ 0 ] ;
if ( V_4 -> V_19 && V_4 -> V_19 -> V_20 ) {
V_11 = V_4 -> V_19 -> V_20 ;
V_12 = V_4 -> V_19 -> V_21 ;
} else if ( V_4 -> V_22 ) {
V_11 = V_23 ;
V_12 = F_4 ( V_23 ) ;
} else {
V_11 = V_24 ;
V_12 = F_4 ( V_24 ) ;
}
V_5 = 0 ;
for ( V_6 = 0 ; V_6 < V_12 ; V_6 ++ ) {
if ( V_11 [ V_6 ] . V_9 != V_9 )
continue;
if ( abs ( V_11 [ V_6 ] . V_7 - V_7 ) <
abs ( V_11 [ V_5 ] . V_7 - V_7 ) )
V_5 = V_6 ;
else if ( V_11 [ V_5 ] . V_9 != V_9 )
V_5 = V_6 ;
}
V_8 = V_11 [ V_5 ] . V_25 << V_26
| V_11 [ V_5 ] . V_27 << V_28 ;
F_5 ( V_2 , V_29 ,
V_30 |
V_31 , V_8 ) ;
}
static int F_6 ( struct V_1 * V_2 , int V_32 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_27 ;
int V_33 = 0 ;
int V_34 ;
if ( V_32 )
V_34 = 4 ;
else
V_34 = 0 ;
switch ( V_4 -> V_7 [ V_32 ] ) {
case V_35 :
V_27 = V_4 -> V_36 [ 0 ] ;
break;
case V_37 :
V_33 |= 0x8 ;
V_27 = V_4 -> V_36 [ 1 ] ;
break;
case V_38 :
V_33 |= 0x10 ;
V_27 = V_4 -> V_39 [ 0 ] . V_40 ;
break;
case V_41 :
V_33 |= 0x18 ;
V_27 = V_4 -> V_39 [ 1 ] . V_40 ;
break;
default:
return - V_42 ;
}
if ( V_27 >= 13500000 ) {
V_27 /= 2 ;
V_33 |= V_43 ;
F_7 ( V_2 -> V_44 , L_1 ,
V_32 + 1 , V_27 ) ;
}
V_4 -> V_18 [ V_32 ] = V_27 ;
F_5 ( V_2 , V_45 + V_34 ,
V_46 | V_43 ,
V_33 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_47 , V_48 ;
F_6 ( V_2 , 0 ) ;
F_6 ( V_2 , 1 ) ;
if ( V_4 -> V_18 [ 0 ] == V_4 -> V_18 [ 1 ] ) {
F_1 ( V_2 ) ;
return 0 ;
}
if ( V_4 -> V_18 [ 0 ] < V_4 -> V_18 [ 1 ] )
V_48 = V_17 ;
else
V_48 = 0 ;
V_47 = F_5 ( V_2 , V_16 ,
V_17 , V_48 ) ;
if ( V_47 )
F_9 ( & V_2 -> V_49 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
static int F_10 ( struct V_50 * V_51 ,
struct V_50 * V_52 )
{
int V_53 = F_3 ( V_51 -> V_2 , V_16 ) ;
const char * V_54 ;
if ( V_53 & V_17 )
V_54 = L_2 ;
else
V_54 = L_3 ;
return strcmp ( V_51 -> V_55 , V_54 ) == 0 ;
}
static int F_11 ( struct V_56 * V_57 ,
struct V_58 * V_59 )
{
struct V_60 * V_61 =
(struct V_60 * ) V_57 -> V_62 ;
struct V_1 * V_2 = F_12 ( V_57 ) ;
int V_63 , V_64 ;
if ( V_61 -> V_65 == V_66 )
V_63 = V_67 |
V_68 ;
else
V_63 = V_69 ;
V_64 = F_3 ( V_2 , V_61 -> V_53 ) ;
if ( V_64 < 0 )
return V_64 ;
if ( V_64 & V_63 )
return - V_42 ;
return F_13 ( V_57 , V_59 ) ;
}
static void F_14 ( struct V_1 * V_2 , int V_70 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_71 * V_19 = V_4 -> V_19 ;
int V_72 = V_73 [ V_70 ] ;
int V_74 = V_4 -> V_75 [ V_70 ] ;
int V_76 , V_6 ;
V_76 = F_3 ( V_2 , V_72 ) ;
V_76 &= V_77 | V_78 |
V_79 ;
for ( V_6 = 0 ; V_6 < V_80 ; V_6 ++ )
F_5 ( V_2 , V_72 + V_6 , 0xffff ,
V_19 -> V_81 [ V_74 ] . V_82 [ V_6 ] ) ;
F_5 ( V_2 , V_72 , V_77 |
V_78 |
V_79 , V_76 ) ;
}
static int F_15 ( const char * V_55 )
{
if ( strcmp ( V_55 , L_4 ) == 0 )
return 0 ;
if ( strcmp ( V_55 , L_5 ) == 0 )
return 1 ;
if ( strcmp ( V_55 , L_6 ) == 0 )
return 2 ;
return - V_42 ;
}
static int F_16 ( struct V_56 * V_57 ,
struct V_58 * V_59 )
{
struct V_1 * V_2 = F_12 ( V_57 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_71 * V_19 = V_4 -> V_19 ;
int V_70 = F_15 ( V_57 -> V_83 . V_55 ) ;
int V_84 = V_59 -> V_84 . integer . V_84 [ 0 ] ;
if ( V_70 < 0 )
return V_70 ;
if ( V_84 >= V_19 -> V_85 )
return - V_42 ;
V_4 -> V_75 [ V_70 ] = V_84 ;
F_14 ( V_2 , V_70 ) ;
return 0 ;
}
static int F_17 ( struct V_56 * V_57 ,
struct V_58 * V_59 )
{
struct V_1 * V_2 = F_12 ( V_57 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_70 = F_15 ( V_57 -> V_83 . V_55 ) ;
V_59 -> V_84 . V_86 . V_87 [ 0 ] = V_4 -> V_75 [ V_70 ] ;
return 0 ;
}
static void F_18 ( struct V_1 * V_2 , int V_88 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_71 * V_19 = V_4 -> V_19 ;
int V_72 = V_89 [ V_88 ] ;
int V_90 , V_5 , V_91 , V_76 , V_6 , V_74 ;
if ( ! V_19 || ! V_4 -> V_92 )
return;
switch ( V_88 ) {
case 0 :
case 1 :
V_90 = 0 ;
break;
case 2 :
V_90 = 1 ;
break;
default:
return;
}
V_74 = V_4 -> V_93 [ V_88 ] ;
V_5 = 0 ;
V_91 = V_94 ;
for ( V_6 = 0 ; V_6 < V_19 -> V_95 ; V_6 ++ ) {
if ( strcmp ( V_19 -> V_96 [ V_6 ] . V_55 ,
V_4 -> V_97 [ V_74 ] ) == 0 &&
abs ( V_19 -> V_96 [ V_6 ] . V_27
- V_4 -> V_98 [ V_90 ] ) < V_91 ) {
V_5 = V_6 ;
V_91 = abs ( V_19 -> V_96 [ V_6 ] . V_27
- V_4 -> V_98 [ V_90 ] ) ;
}
}
F_7 ( V_2 -> V_44 , L_7 ,
V_88 ,
V_19 -> V_96 [ V_5 ] . V_55 ,
V_19 -> V_96 [ V_5 ] . V_27 ,
V_4 -> V_98 [ V_90 ] ) ;
V_76 = F_3 ( V_2 , V_72 ) ;
V_76 &= V_99 ;
for ( V_6 = 0 ; V_6 < V_100 ; V_6 ++ )
F_5 ( V_2 , V_72 + V_6 , 0xffff ,
V_19 -> V_96 [ V_5 ] . V_82 [ V_6 ] ) ;
F_5 ( V_2 , V_72 , V_99 , V_76 ) ;
}
static int F_19 ( const char * V_55 )
{
if ( strcmp ( V_55 , L_8 ) == 0 )
return 0 ;
if ( strcmp ( V_55 , L_9 ) == 0 )
return 1 ;
if ( strcmp ( V_55 , L_10 ) == 0 )
return 2 ;
return - V_42 ;
}
static int F_20 ( struct V_56 * V_57 ,
struct V_58 * V_59 )
{
struct V_1 * V_2 = F_12 ( V_57 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_71 * V_19 = V_4 -> V_19 ;
int V_88 = F_19 ( V_57 -> V_83 . V_55 ) ;
int V_84 = V_59 -> V_84 . integer . V_84 [ 0 ] ;
if ( V_88 < 0 )
return V_88 ;
if ( V_84 >= V_19 -> V_95 )
return - V_42 ;
V_4 -> V_93 [ V_88 ] = V_84 ;
F_18 ( V_2 , V_88 ) ;
return 0 ;
}
static int F_21 ( struct V_56 * V_57 ,
struct V_58 * V_59 )
{
struct V_1 * V_2 = F_12 ( V_57 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_88 = F_19 ( V_57 -> V_83 . V_55 ) ;
V_59 -> V_84 . V_86 . V_87 [ 0 ] = V_4 -> V_93 [ V_88 ] ;
return 0 ;
}
static void F_22 ( struct V_1 * V_2 , T_1 V_101 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_102 )
V_101 = V_103 ;
F_5 ( V_2 , V_104 ,
V_105 , V_101 ) ;
if ( V_101 == V_106 )
F_23 ( 2 ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_25 ( & V_4 -> V_107 ) ;
V_4 -> V_102 ++ ;
F_7 ( V_2 -> V_44 , L_11 ,
V_4 -> V_102 ) ;
if ( V_4 -> V_102 == 1 ) {
if ( V_4 -> V_22 && V_4 -> V_13 ) {
F_5 ( V_2 , V_104 ,
V_105 ,
V_103 ) ;
F_23 ( 2 ) ;
}
}
F_26 ( & V_4 -> V_107 ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_101 ;
F_25 ( & V_4 -> V_107 ) ;
V_4 -> V_102 -- ;
F_7 ( V_2 -> V_44 , L_12 ,
V_4 -> V_102 ) ;
if ( V_4 -> V_102 == 0 ) {
if ( V_4 -> V_22 && V_4 -> V_13 ) {
if ( V_4 -> V_15 || V_4 -> V_108 )
V_101 = V_106 ;
else
V_101 = V_109 ;
F_5 ( V_2 , V_104 ,
V_105 ,
V_101 ) ;
}
}
F_26 ( & V_4 -> V_107 ) ;
}
static int F_28 ( struct V_50 * V_110 ,
struct V_56 * V_57 , int V_111 )
{
struct V_1 * V_2 = V_110 -> V_2 ;
switch ( V_111 ) {
case V_112 :
return F_8 ( V_2 ) ;
case V_113 :
F_8 ( V_2 ) ;
break;
}
return 0 ;
}
static void F_29 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_30 ( V_2 -> V_44 ) ;
V_4 -> V_114 ++ ;
F_7 ( V_2 -> V_44 , L_13 ,
V_4 -> V_114 ) ;
if ( V_4 -> V_114 == 1 ) {
F_5 ( V_2 , V_104 ,
V_115 |
V_116 |
V_117 ,
V_115 |
V_116 |
( 0x3 << V_118 ) ) ;
F_5 ( V_2 , V_119 ,
V_120 |
V_121 , 0 ) ;
F_5 ( V_2 , V_122 ,
V_123 |
V_124 ,
V_123 | 0x2 ) ;
F_23 ( 20 ) ;
}
}
static void F_31 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_114 -- ;
F_7 ( V_2 -> V_44 , L_14 ,
V_4 -> V_114 ) ;
if ( V_4 -> V_114 == 0 ) {
F_5 ( V_2 , V_104 ,
V_125 |
V_115 |
V_116 |
V_117 ,
V_125 |
V_115 |
V_116 |
( 1 << V_118 ) ) ;
F_5 ( V_2 , V_122 ,
V_123 |
V_124 , 0 ) ;
F_5 ( V_2 , V_119 ,
V_120 |
V_121 ,
V_120 |
V_121 ) ;
F_23 ( 5 ) ;
F_5 ( V_2 , V_104 ,
V_125 |
V_115 |
V_116 |
V_117 , 0 ) ;
}
F_32 ( V_2 -> V_44 ) ;
}
static int F_33 ( struct V_50 * V_110 ,
struct V_56 * V_57 , int V_111 )
{
struct V_1 * V_2 = V_110 -> V_2 ;
switch ( V_111 ) {
case V_112 :
F_29 ( V_2 ) ;
break;
case V_113 :
F_31 ( V_2 ) ;
break;
}
return 0 ;
}
static void F_34 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_126 = 1 ;
int V_51 = 0 ;
int V_53 , V_127 ;
V_53 = F_3 ( V_2 , V_128 ) ;
if ( ! ( V_53 & V_129 ) ) {
F_35 ( V_2 -> V_44 , L_15 ) ;
V_126 = 0 ;
}
V_53 = F_3 ( V_2 , V_130 ) ;
if ( ! ( V_53 & V_131 ) ) {
F_35 ( V_2 -> V_44 , L_16 ) ;
V_126 = 0 ;
}
V_53 = F_3 ( V_2 , V_132 ) ;
switch ( V_53 ) {
case V_133 :
F_35 ( V_2 -> V_44 , L_17 ) ;
V_51 = 2 << V_134 ;
break;
case V_135 :
F_35 ( V_2 -> V_44 , L_18 ) ;
V_51 = 1 << V_134 ;
break;
case V_136 :
F_35 ( V_2 -> V_44 , L_19 ) ;
V_51 = 0 << V_134 ;
break;
default:
F_35 ( V_2 -> V_44 , L_20 , V_53 ) ;
V_126 = 0 ;
break;
}
V_127 = F_3 ( V_2 , V_137 ) ;
if ( V_127 != V_53 ) {
F_35 ( V_2 -> V_44 , L_21 ) ;
V_126 = 0 ;
}
if ( V_126 ) {
F_7 ( V_2 -> V_44 , L_22 ) ;
F_5 ( V_2 , V_138 ,
V_139 |
V_140 ,
V_51 | V_139 ) ;
V_4 -> V_141 . V_142 = true ;
} else {
F_7 ( V_2 -> V_44 , L_23 ) ;
F_5 ( V_2 , V_138 ,
V_139 , 0 ) ;
V_4 -> V_141 . V_142 = false ;
}
}
static int F_36 ( struct V_50 * V_110 ,
struct V_56 * V_57 , int V_111 )
{
struct V_1 * V_2 = V_110 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
switch ( V_111 ) {
case V_112 :
if ( V_4 -> V_143 ) {
F_5 ( V_2 , V_45 ,
V_144 ,
V_145 ) ;
V_4 -> V_143 = 0 ;
}
if ( V_4 -> V_146 ) {
F_5 ( V_2 , V_147 ,
V_148 ,
V_149 ) ;
V_4 -> V_146 = 0 ;
}
break;
}
F_37 ( V_110 , V_57 , V_111 ) ;
return 0 ;
}
static int F_38 ( struct V_50 * V_110 ,
struct V_56 * V_57 , int V_111 )
{
struct V_1 * V_2 = V_110 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
switch ( V_111 ) {
case V_113 :
if ( V_4 -> V_150 ) {
F_5 ( V_2 , V_45 ,
V_144 , 0 ) ;
V_4 -> V_150 = 0 ;
}
if ( V_4 -> V_151 ) {
F_5 ( V_2 , V_147 ,
V_148 , 0 ) ;
V_4 -> V_151 = 0 ;
}
break;
}
return 0 ;
}
static int F_39 ( struct V_50 * V_110 ,
struct V_56 * V_57 , int V_111 )
{
struct V_1 * V_2 = V_110 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
switch ( V_111 ) {
case V_112 :
V_4 -> V_143 = 1 ;
break;
case V_113 :
V_4 -> V_150 = 1 ;
break;
}
return 0 ;
}
static int F_40 ( struct V_50 * V_110 ,
struct V_56 * V_57 , int V_111 )
{
struct V_1 * V_2 = V_110 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
switch ( V_111 ) {
case V_112 :
V_4 -> V_146 = 1 ;
break;
case V_113 :
V_4 -> V_151 = 1 ;
break;
}
return 0 ;
}
static int F_41 ( struct V_50 * V_110 ,
struct V_56 * V_57 , int V_111 )
{
F_36 ( V_110 , V_57 , V_111 ) ;
return 0 ;
}
static int F_42 ( struct V_50 * V_110 ,
struct V_56 * V_57 , int V_111 )
{
F_36 ( V_110 , V_57 , V_111 ) ;
return 0 ;
}
static int F_43 ( struct V_50 * V_110 ,
struct V_56 * V_57 , int V_111 )
{
struct V_1 * V_2 = V_110 -> V_2 ;
unsigned int V_63 = 1 << V_110 -> V_65 ;
F_5 ( V_2 , V_152 ,
V_63 , V_63 ) ;
return 0 ;
}
static int F_44 ( struct V_56 * V_57 ,
struct V_58 * V_59 )
{
struct V_153 * V_154 = F_12 ( V_57 ) ;
struct V_50 * V_110 = V_154 -> V_155 [ 0 ] ;
struct V_1 * V_2 = V_110 -> V_2 ;
int V_64 ;
V_64 = F_45 ( V_57 , V_59 ) ;
F_34 ( V_2 ) ;
return V_64 ;
}
static int F_46 ( struct V_50 * V_110 ,
struct V_56 * V_57 , int V_111 )
{
struct V_1 * V_2 = V_110 -> V_2 ;
F_7 ( V_2 -> V_44 , L_24 ,
F_3 ( V_2 ,
V_156 ) ) ;
return 0 ;
}
static int F_47 ( struct V_56 * V_57 ,
struct V_58 * V_59 )
{
struct V_153 * V_154 = F_12 ( V_57 ) ;
struct V_50 * V_110 = V_154 -> V_155 [ 0 ] ;
struct V_1 * V_2 = V_110 -> V_2 ;
int V_64 ;
V_64 = F_48 ( V_57 , V_59 ) ;
F_34 ( V_2 ) ;
return V_64 ;
}
static int F_49 ( struct V_157 * V_39 ,
int V_158 , int V_159 )
{
T_2 V_160 ;
unsigned int V_161 , V_162 , V_163 ;
F_50 ( L_25 , V_158 , V_159 ) ;
V_39 -> V_164 = 0 ;
while ( V_158 > 13500000 ) {
V_39 -> V_164 ++ ;
V_158 /= 2 ;
if ( V_39 -> V_164 > 3 )
return - V_42 ;
}
F_50 ( L_26 , V_39 -> V_164 , V_158 ) ;
V_39 -> V_165 = 3 ;
while ( V_159 * ( V_39 -> V_165 + 1 ) < 90000000 ) {
V_39 -> V_165 ++ ;
if ( V_39 -> V_165 > 63 )
return - V_42 ;
}
V_159 *= V_39 -> V_165 + 1 ;
F_50 ( L_27 , V_39 -> V_165 , V_159 ) ;
if ( V_158 > 1000000 ) {
V_39 -> V_166 = 0 ;
} else if ( V_158 > 256000 ) {
V_39 -> V_166 = 1 ;
V_158 *= 2 ;
} else if ( V_158 > 128000 ) {
V_39 -> V_166 = 2 ;
V_158 *= 4 ;
} else if ( V_158 > 64000 ) {
V_39 -> V_166 = 3 ;
V_158 *= 8 ;
} else {
V_39 -> V_166 = 4 ;
V_158 *= 16 ;
}
F_50 ( L_28 , V_39 -> V_166 , V_158 ) ;
V_162 = V_159 / V_158 ;
V_39 -> V_167 = V_162 ;
V_163 = V_159 % V_158 ;
F_50 ( L_29 , V_163 ) ;
V_160 = V_168 * ( long long ) V_163 ;
F_51 ( V_160 , V_158 ) ;
V_161 = V_160 & 0xFFFFFFFF ;
if ( ( V_161 % 10 ) >= 5 )
V_161 += 5 ;
V_39 -> V_169 = V_161 / 10 ;
F_50 ( L_30 , V_39 -> V_167 , V_39 -> V_169 ) ;
return 0 ;
}
static int F_52 ( struct V_1 * V_2 , int V_83 , int V_170 ,
unsigned int V_158 , unsigned int V_159 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_4 * V_171 = V_4 -> V_4 ;
int V_172 , V_64 ;
struct V_157 V_39 ;
T_1 V_53 , V_173 , V_174 ;
unsigned long V_175 ;
bool V_176 ;
V_173 = F_3 ( V_2 , V_45 )
& V_145 ;
V_174 = F_3 ( V_2 , V_147 )
& V_149 ;
switch ( V_83 ) {
case V_177 :
V_172 = 0 ;
V_83 = 0 ;
break;
case V_178 :
V_172 = 0x20 ;
V_83 = 1 ;
break;
default:
return - V_42 ;
}
V_53 = F_3 ( V_2 , V_179 + V_172 ) ;
V_176 = V_53 & V_180 ;
switch ( V_170 ) {
case 0 :
if ( V_159 )
return - V_42 ;
V_170 = V_4 -> V_39 [ V_83 ] . V_170 ;
break;
case V_181 :
case V_182 :
case V_183 :
case V_184 :
break;
default:
return - V_42 ;
}
if ( V_4 -> V_39 [ V_83 ] . V_170 == V_170 &&
V_4 -> V_39 [ V_83 ] . V_185 == V_158 && V_4 -> V_39 [ V_83 ] . V_40 == V_159 )
return 0 ;
if ( V_159 )
V_64 = F_49 ( & V_39 , V_158 , V_159 ) ;
else
V_64 = F_49 ( & V_39 , V_4 -> V_39 [ V_83 ] . V_185 ,
V_4 -> V_39 [ V_83 ] . V_40 ) ;
if ( V_64 < 0 )
return V_64 ;
F_5 ( V_2 , V_45 ,
V_145 , 0 ) ;
F_5 ( V_2 , V_147 ,
V_149 , 0 ) ;
F_5 ( V_2 , V_179 + V_172 ,
V_180 , 0 ) ;
V_53 = ( V_39 . V_165 << V_186 ) |
( V_39 . V_166 << V_187 ) ;
F_5 ( V_2 , V_188 + V_172 ,
V_189 |
V_190 , V_53 ) ;
F_53 ( V_2 , V_191 + V_172 , V_39 . V_169 ) ;
F_5 ( V_2 , V_192 + V_172 ,
V_193 ,
V_39 . V_167 << V_194 ) ;
F_5 ( V_2 , V_195 + V_172 ,
V_196 |
V_197 ,
( V_39 . V_164 << V_198 ) |
( V_170 - 1 ) ) ;
F_54 ( & V_4 -> V_199 [ V_83 ] ) ;
if ( V_159 ) {
if ( ! V_176 ) {
F_24 ( V_2 ) ;
switch ( V_171 -> type ) {
case V_200 :
F_29 ( V_2 ) ;
break;
case V_201 :
if ( V_4 -> V_202 < 1 )
F_29 ( V_2 ) ;
break;
default:
break;
}
}
if ( V_39 . V_169 )
V_53 = V_180 | V_203 ;
else
V_53 = V_180 ;
F_5 ( V_2 , V_179 + V_172 ,
V_180 | V_203 ,
V_53 ) ;
if ( V_4 -> V_204 ) {
V_175 = F_55 ( & V_4 -> V_199 [ V_83 ] ,
F_56 ( 10 ) ) ;
if ( V_175 == 0 )
F_57 ( V_2 -> V_44 ,
L_31 ) ;
} else {
F_23 ( 5 ) ;
}
} else {
if ( V_176 ) {
switch ( V_171 -> type ) {
case V_200 :
F_31 ( V_2 ) ;
break;
case V_201 :
if ( V_4 -> V_202 < 1 )
F_31 ( V_2 ) ;
break;
default:
break;
}
F_27 ( V_2 ) ;
}
}
V_4 -> V_39 [ V_83 ] . V_185 = V_158 ;
V_4 -> V_39 [ V_83 ] . V_40 = V_159 ;
V_4 -> V_39 [ V_83 ] . V_170 = V_170 ;
F_5 ( V_2 , V_45 ,
V_145 , V_173 ) ;
F_5 ( V_2 , V_147 ,
V_149 , V_174 ) ;
F_8 ( V_2 ) ;
return 0 ;
}
static T_3 F_58 ( int V_205 , void * V_206 )
{
struct V_207 * V_207 = V_206 ;
F_59 ( V_207 ) ;
return V_208 ;
}
static int F_60 ( struct V_209 * V_210 , int V_83 , int V_170 ,
unsigned int V_158 , unsigned int V_159 )
{
return F_52 ( V_210 -> V_2 , V_83 , V_170 , V_158 , V_159 ) ;
}
static int F_61 ( struct V_209 * V_210 ,
int V_211 , unsigned int V_212 , int V_213 )
{
struct V_1 * V_2 = V_210 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_6 ;
switch ( V_210 -> V_83 ) {
case 1 :
case 2 :
break;
default:
return - V_42 ;
}
switch ( V_211 ) {
case V_35 :
V_4 -> V_7 [ V_210 -> V_83 - 1 ] = V_35 ;
V_4 -> V_36 [ 0 ] = V_212 ;
F_7 ( V_210 -> V_44 , L_32 ,
V_210 -> V_83 , V_212 ) ;
break;
case V_37 :
V_4 -> V_7 [ V_210 -> V_83 - 1 ] = V_37 ;
V_4 -> V_36 [ 1 ] = V_212 ;
F_7 ( V_210 -> V_44 , L_33 ,
V_210 -> V_83 , V_212 ) ;
break;
case V_38 :
V_4 -> V_7 [ V_210 -> V_83 - 1 ] = V_38 ;
F_7 ( V_210 -> V_44 , L_34 , V_210 -> V_83 ) ;
break;
case V_41 :
V_4 -> V_7 [ V_210 -> V_83 - 1 ] = V_41 ;
F_7 ( V_210 -> V_44 , L_35 , V_210 -> V_83 ) ;
break;
case V_214 :
if ( V_212 ) {
for ( V_6 = 0 ; V_6 < F_4 ( V_215 ) ; V_6 ++ )
if ( V_215 [ V_6 ] == V_212 )
break;
if ( V_6 == F_4 ( V_215 ) )
return - V_42 ;
F_5 ( V_2 , V_216 ,
V_217 , V_6 ) ;
F_5 ( V_2 , V_218 ,
V_219 , V_219 ) ;
} else {
F_5 ( V_2 , V_218 ,
V_219 , 0 ) ;
}
default:
return - V_42 ;
}
F_8 ( V_2 ) ;
return 0 ;
}
static int F_62 ( struct V_1 * V_2 ,
enum V_220 V_221 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_4 * V_171 = V_4 -> V_4 ;
switch ( V_221 ) {
case V_222 :
break;
case V_223 :
switch ( V_171 -> type ) {
case V_201 :
case V_224 :
F_5 ( V_2 , V_225 ,
V_226 , 0 ) ;
F_5 ( V_2 , V_227 ,
V_228 , 0 ) ;
break;
default:
break;
}
if ( V_2 -> V_49 . V_229 == V_230 )
F_24 ( V_2 ) ;
break;
case V_230 :
if ( V_2 -> V_49 . V_229 == V_231 ) {
switch ( V_171 -> type ) {
case V_200 :
if ( V_4 -> V_202 < 4 ) {
F_53 ( V_2 , 0x102 , 0x3 ) ;
F_53 ( V_2 , 0x56 , 0x3 ) ;
F_53 ( V_2 , 0x817 , 0 ) ;
F_53 ( V_2 , 0x102 , 0 ) ;
}
break;
case V_201 :
if ( V_4 -> V_202 == 0 ) {
F_53 ( V_2 , 0x102 , 0x3 ) ;
F_53 ( V_2 , 0xcb , 0x81 ) ;
F_53 ( V_2 , 0x817 , 0 ) ;
F_53 ( V_2 , 0x102 , 0 ) ;
F_5 ( V_2 ,
V_232 ,
V_233 ,
V_233 ) ;
}
break;
case V_224 :
if ( V_4 -> V_202 < 2 ) {
F_53 ( V_2 , 0x102 , 0x3 ) ;
F_53 ( V_2 , 0x5d , 0x7e ) ;
F_53 ( V_2 , 0x5e , 0x0 ) ;
F_53 ( V_2 , 0x102 , 0x0 ) ;
}
break;
}
F_5 ( V_2 , V_119 ,
V_120 |
V_121 ,
V_120 |
V_121 ) ;
}
if ( V_2 -> V_49 . V_229 == V_223 )
F_27 ( V_2 ) ;
switch ( V_171 -> type ) {
case V_201 :
case V_224 :
F_5 ( V_2 , V_225 ,
V_226 ,
V_226 ) ;
F_5 ( V_2 , V_227 ,
V_228 ,
V_228 ) ;
break;
default:
break;
}
break;
case V_231 :
if ( V_2 -> V_49 . V_229 == V_230 )
V_4 -> V_234 = NULL ;
break;
}
V_2 -> V_49 . V_229 = V_221 ;
return 0 ;
}
static int F_63 ( struct V_209 * V_210 , unsigned int V_235 )
{
struct V_1 * V_2 = V_210 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_4 * V_171 = V_4 -> V_4 ;
int V_236 ;
int V_237 ;
int V_238 = 0 ;
int V_173 = 0 ;
switch ( V_210 -> V_83 ) {
case 1 :
V_236 = V_239 ;
V_237 = V_240 ;
break;
case 2 :
V_236 = V_241 ;
V_237 = V_242 ;
break;
default:
return - V_42 ;
}
switch ( V_235 & V_243 ) {
case V_244 :
break;
case V_245 :
V_238 = V_246 ;
break;
default:
return - V_42 ;
}
switch ( V_235 & V_247 ) {
case V_248 :
V_173 |= V_249 ;
case V_250 :
V_173 |= 0x18 ;
break;
case V_251 :
V_173 |= 0x10 ;
break;
case V_252 :
break;
case V_253 :
V_173 |= 0x8 ;
break;
default:
return - V_42 ;
}
switch ( V_235 & V_247 ) {
case V_250 :
case V_248 :
switch ( V_235 & V_254 ) {
case V_255 :
break;
case V_256 :
V_173 |= V_257 ;
break;
default:
return - V_42 ;
}
break;
case V_251 :
case V_252 :
case V_253 :
switch ( V_235 & V_254 ) {
case V_255 :
break;
case V_258 :
V_173 |= V_257 | V_249 ;
break;
case V_256 :
V_173 |= V_257 ;
break;
case V_259 :
V_173 |= V_249 ;
break;
default:
return - V_42 ;
}
break;
default:
return - V_42 ;
}
switch ( V_171 -> type ) {
case V_224 :
case V_201 :
if ( V_210 -> V_83 == 2 )
F_5 ( V_2 , V_260 ,
V_249 |
V_261 , V_173 ) ;
break;
default:
break;
}
F_5 ( V_2 , V_237 ,
V_257 | V_249 |
V_262 ,
V_173 ) ;
F_5 ( V_2 , V_236 , V_246 ,
V_238 ) ;
return 0 ;
}
static int F_64 ( struct V_263 * V_264 ,
struct V_265 * V_266 ,
struct V_209 * V_210 )
{
struct V_1 * V_2 = V_210 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_237 ;
int V_267 ;
int V_268 ;
int V_269 ;
int V_270 ;
int V_173 = 0 ;
int V_174 = 0 ;
int V_271 = 0 ;
int V_272 = 0 ;
int V_273 = 0 ;
int V_83 = V_210 -> V_83 - 1 ;
int V_6 , V_274 , V_91 , V_275 , V_5 ;
switch ( V_210 -> V_83 ) {
case 1 :
V_237 = V_240 ;
V_267 = V_276 ;
V_268 = V_277 ;
V_270 = V_278 ;
if ( V_264 -> V_279 == V_280 ||
V_4 -> V_281 [ 0 ] ) {
V_269 = V_282 ;
} else {
V_269 = V_283 ;
F_7 ( V_2 -> V_44 , L_36 ) ;
}
break;
case 2 :
V_237 = V_242 ;
V_267 = V_284 ;
V_268 = V_285 ;
V_270 = V_286 ;
if ( V_264 -> V_279 == V_280 ||
V_4 -> V_281 [ 1 ] ) {
V_269 = V_287 ;
} else {
V_269 = V_288 ;
F_7 ( V_2 -> V_44 , L_37 ) ;
}
break;
default:
return - V_42 ;
}
V_275 = F_65 ( V_266 ) * 2 ;
switch ( F_66 ( V_266 ) ) {
case V_289 :
V_275 *= 16 ;
break;
case V_290 :
V_275 *= 20 ;
V_173 |= 0x20 ;
break;
case V_291 :
V_275 *= 24 ;
V_173 |= 0x40 ;
break;
case V_292 :
V_275 *= 32 ;
V_173 |= 0x60 ;
break;
default:
return - V_42 ;
}
for ( V_6 = 0 ; V_6 < F_4 ( V_293 ) ; V_6 ++ )
if ( V_293 [ V_6 ] . V_27 == F_65 ( V_266 ) )
break;
if ( V_6 == F_4 ( V_293 ) )
return - V_42 ;
V_273 |= V_293 [ V_6 ] . V_8 << V_294 ;
F_7 ( V_210 -> V_44 , L_38 , V_293 [ V_6 ] . V_27 ) ;
F_7 ( V_210 -> V_44 , L_39 ,
V_210 -> V_83 , V_4 -> V_18 [ V_83 ] , V_275 ) ;
if ( F_67 ( V_266 ) == 1 &&
( F_3 ( V_2 , V_237 ) & 0x18 ) == 0x18 )
V_174 |= V_295 ;
if ( V_4 -> V_18 [ V_83 ] == 0 ) {
F_68 ( V_210 -> V_44 , L_40 , V_210 -> V_83 ) ;
return - V_42 ;
}
V_5 = 0 ;
V_91 = abs ( ( V_296 [ 0 ] * F_65 ( V_266 ) )
- V_4 -> V_18 [ V_83 ] ) ;
for ( V_6 = 1 ; V_6 < F_4 ( V_296 ) ; V_6 ++ ) {
V_274 = abs ( ( V_296 [ V_6 ] * F_65 ( V_266 ) )
- V_4 -> V_18 [ V_83 ] ) ;
if ( V_274 >= V_91 )
continue;
V_5 = V_6 ;
V_91 = V_274 ;
}
F_7 ( V_210 -> V_44 , L_41 ,
V_210 -> V_83 , V_296 [ V_5 ] ) ;
V_273 |= V_5 ;
V_5 = 0 ;
for ( V_6 = 0 ; V_6 < F_4 ( V_297 ) ; V_6 ++ ) {
V_274 = ( V_4 -> V_18 [ V_83 ] * 10 / V_297 [ V_6 ] ) - V_275 ;
if ( V_274 < 0 )
break;
V_5 = V_6 ;
}
V_275 = V_4 -> V_18 [ V_83 ] * 10 / V_297 [ V_5 ] ;
F_7 ( V_210 -> V_44 , L_42 ,
V_297 [ V_5 ] , V_275 ) ;
V_271 |= V_5 << V_298 ;
V_272 = V_275 / F_65 ( V_266 ) ;
if ( ! V_272 ) {
F_68 ( V_210 -> V_44 , L_43 ,
V_275 ) ;
return - V_42 ;
}
F_7 ( V_210 -> V_44 , L_44 ,
V_272 , V_275 / V_272 ) ;
F_5 ( V_2 , V_237 , V_299 , V_173 ) ;
F_5 ( V_2 , V_267 , V_295 , V_174 ) ;
F_5 ( V_2 , V_268 , V_300 , V_271 ) ;
F_5 ( V_2 , V_269 , V_301 ,
V_272 ) ;
F_5 ( V_2 , V_270 , V_302 |
V_303 , V_273 ) ;
if ( V_264 -> V_279 == V_280 ) {
switch ( V_210 -> V_83 ) {
case 1 :
V_4 -> V_98 [ 0 ] = F_65 ( V_266 ) ;
F_18 ( V_2 , 0 ) ;
F_18 ( V_2 , 1 ) ;
break;
case 2 :
V_4 -> V_98 [ 1 ] = F_65 ( V_266 ) ;
F_18 ( V_2 , 2 ) ;
break;
}
}
return 0 ;
}
static int F_69 ( struct V_263 * V_264 ,
struct V_265 * V_266 ,
struct V_209 * V_210 )
{
struct V_1 * V_2 = V_210 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_4 * V_171 = V_4 -> V_4 ;
int V_237 ;
int V_173 = 0 ;
switch ( V_210 -> V_83 ) {
case 3 :
switch ( V_171 -> type ) {
case V_224 :
case V_201 :
V_237 = V_260 ;
break;
default:
return 0 ;
}
default:
return 0 ;
}
switch ( F_66 ( V_266 ) ) {
case V_289 :
break;
case V_290 :
V_173 |= 0x20 ;
break;
case V_291 :
V_173 |= 0x40 ;
break;
case V_292 :
V_173 |= 0x60 ;
break;
default:
return - V_42 ;
}
return F_5 ( V_2 , V_237 , V_299 , V_173 ) ;
}
static void F_70 ( struct V_263 * V_264 ,
struct V_209 * V_210 )
{
struct V_1 * V_2 = V_210 -> V_2 ;
int V_270 = 0 ;
switch ( V_210 -> V_83 ) {
case 1 :
V_270 = V_278 ;
break;
case 2 :
V_270 = V_286 ;
break;
default:
break;
}
if ( V_270 && ! V_210 -> V_304 && ! V_210 -> V_305 )
F_5 ( V_2 , V_270 ,
V_302 |
V_303 , 0x9 ) ;
}
static int F_71 ( struct V_209 * V_306 , int V_307 )
{
struct V_1 * V_2 = V_306 -> V_2 ;
int V_308 ;
int V_53 ;
switch ( V_306 -> V_83 ) {
case 1 :
V_308 = V_309 ;
break;
case 2 :
V_308 = V_310 ;
break;
default:
return - V_42 ;
}
if ( V_307 )
V_53 = V_311 ;
else
V_53 = 0 ;
F_5 ( V_2 , V_308 , V_311 , V_53 ) ;
return 0 ;
}
static int F_72 ( struct V_209 * V_306 , int V_312 )
{
struct V_1 * V_2 = V_306 -> V_2 ;
int V_53 , V_8 , V_63 ;
switch ( V_306 -> V_83 ) {
case 1 :
V_53 = V_239 ;
V_63 = V_313 ;
break;
case 2 :
V_53 = V_241 ;
V_63 = V_314 ;
break;
case 3 :
V_53 = V_315 ;
V_63 = V_316 ;
break;
default:
return - V_42 ;
}
if ( V_312 )
V_8 = V_63 ;
else
V_8 = 0 ;
return F_5 ( V_2 , V_53 , V_63 , V_8 ) ;
}
static int F_73 ( struct V_209 * V_210 )
{
struct V_1 * V_2 = V_210 -> V_2 ;
F_5 ( V_2 , V_317 ,
V_318 | V_319 , 0 ) ;
F_5 ( V_2 , V_320 ,
V_318 | V_319 , 0 ) ;
F_5 ( V_2 , V_321 ,
V_318 | V_319 , 0 ) ;
return 0 ;
}
static int F_74 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_4 * V_171 = V_4 -> V_4 ;
int V_6 , V_64 ;
switch ( V_171 -> type ) {
case V_200 :
F_5 ( V_2 , V_322 , V_323 , 0 ) ;
break;
case V_224 :
F_5 ( V_2 , V_104 ,
V_105 , 0 ) ;
case V_201 :
F_5 ( V_2 , V_29 ,
V_324 , 0 ) ;
break;
}
for ( V_6 = 0 ; V_6 < F_4 ( V_4 -> V_39 ) ; V_6 ++ ) {
memcpy ( & V_4 -> V_325 [ V_6 ] , & V_4 -> V_39 [ V_6 ] ,
sizeof( struct V_326 ) ) ;
V_64 = F_52 ( V_2 , V_6 + 1 , 0 , 0 , 0 ) ;
if ( V_64 < 0 )
F_57 ( V_2 -> V_44 , L_45 ,
V_6 + 1 , V_64 ) ;
}
F_62 ( V_2 , V_231 ) ;
return 0 ;
}
static int F_75 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_4 * V_171 = V_4 -> V_4 ;
int V_6 , V_64 ;
unsigned int V_8 , V_63 ;
if ( V_4 -> V_202 < 4 ) {
V_64 = F_76 ( V_171 -> V_327 ,
V_152 , & V_8 ) ;
V_2 -> V_328 = 1 ;
V_63 = V_329 | V_330 |
V_331 | V_332 ;
V_8 &= V_63 ;
F_5 ( V_2 , V_152 ,
V_63 , V_8 ) ;
V_2 -> V_328 = 0 ;
}
F_62 ( V_2 , V_230 ) ;
for ( V_6 = 0 ; V_6 < F_4 ( V_4 -> V_39 ) ; V_6 ++ ) {
if ( ! V_4 -> V_325 [ V_6 ] . V_40 )
continue;
V_64 = F_52 ( V_2 , V_6 + 1 ,
V_4 -> V_325 [ V_6 ] . V_170 ,
V_4 -> V_325 [ V_6 ] . V_185 ,
V_4 -> V_325 [ V_6 ] . V_40 ) ;
if ( V_64 < 0 )
F_57 ( V_2 -> V_44 , L_46 ,
V_6 + 1 , V_64 ) ;
}
switch ( V_171 -> type ) {
case V_200 :
if ( V_4 -> V_333 [ 0 ] . V_334 || V_4 -> V_333 [ 1 ] . V_334 )
F_5 ( V_2 , V_322 ,
V_323 , V_323 ) ;
break;
case V_224 :
if ( V_4 -> V_22 && V_4 -> V_13 ) {
F_5 ( V_2 , V_104 ,
V_105 ,
V_109 ) ;
break;
}
case V_201 :
if ( V_4 -> V_13 )
F_5 ( V_2 , V_29 ,
V_324 , V_324 ) ;
break;
}
return 0 ;
}
static void F_77 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_71 * V_19 = V_4 -> V_19 ;
struct V_335 V_336 [] = {
F_78 ( L_8 ,
V_4 -> V_337 ,
F_21 ,
F_20 ) ,
F_78 ( L_9 ,
V_4 -> V_337 ,
F_21 ,
F_20 ) ,
F_78 ( L_10 ,
V_4 -> V_337 ,
F_21 ,
F_20 ) ,
} ;
int V_64 , V_6 , V_338 ;
const char * * V_339 ;
V_4 -> V_92 = 0 ;
V_4 -> V_97 = NULL ;
for ( V_6 = 0 ; V_6 < V_19 -> V_95 ; V_6 ++ ) {
for ( V_338 = 0 ; V_338 < V_4 -> V_92 ; V_338 ++ ) {
if ( strcmp ( V_19 -> V_96 [ V_6 ] . V_55 ,
V_4 -> V_97 [ V_338 ] ) == 0 )
break;
}
if ( V_338 != V_4 -> V_92 )
continue;
V_339 = F_79 ( V_4 -> V_97 ,
sizeof( char * ) *
( V_4 -> V_92 + 1 ) ,
V_340 ) ;
if ( V_339 == NULL )
continue;
V_339 [ V_4 -> V_92 ] =
V_19 -> V_96 [ V_6 ] . V_55 ;
V_4 -> V_92 ++ ;
V_4 -> V_97 = V_339 ;
}
F_7 ( V_2 -> V_44 , L_47 ,
V_4 -> V_92 ) ;
V_4 -> V_337 . V_341 = V_4 -> V_92 ;
V_4 -> V_337 . V_342 = V_4 -> V_97 ;
V_64 = F_80 ( V_4 -> V_2 , V_336 ,
F_4 ( V_336 ) ) ;
if ( V_64 != 0 )
F_68 ( V_4 -> V_2 -> V_44 ,
L_48 , V_64 ) ;
}
static void F_81 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_71 * V_19 = V_4 -> V_19 ;
int V_64 , V_6 ;
if ( ! V_19 )
return;
F_82 ( V_2 , V_19 -> V_343 ,
V_19 -> V_344 ,
V_19 -> V_345 ,
V_19 -> V_346 ,
V_19 -> V_347 ,
V_19 -> V_348 ,
V_19 -> V_349 ,
V_19 -> V_350 ) ;
F_7 ( V_2 -> V_44 , L_49 , V_19 -> V_85 ) ;
if ( V_19 -> V_85 ) {
struct V_335 V_336 [] = {
F_78 ( L_4 , V_4 -> V_351 ,
F_17 , F_16 ) ,
F_78 ( L_5 , V_4 -> V_351 ,
F_17 , F_16 ) ,
F_78 ( L_6 , V_4 -> V_351 ,
F_17 , F_16 ) ,
} ;
V_4 -> V_352 = F_83 ( V_4 -> V_2 -> V_44 ,
sizeof( char * ) * V_19 -> V_85 , V_340 ) ;
if ( ! V_4 -> V_352 ) {
F_68 ( V_4 -> V_2 -> V_44 ,
L_50 ,
V_19 -> V_85 ) ;
return;
}
for ( V_6 = 0 ; V_6 < V_19 -> V_85 ; V_6 ++ )
V_4 -> V_352 [ V_6 ] = V_19 -> V_81 [ V_6 ] . V_55 ;
V_4 -> V_351 . V_341 = V_19 -> V_85 ;
V_4 -> V_351 . V_342 = V_4 -> V_352 ;
V_64 = F_80 ( V_4 -> V_2 , V_336 ,
F_4 ( V_336 ) ) ;
if ( V_64 != 0 )
F_68 ( V_4 -> V_2 -> V_44 ,
L_51 , V_64 ) ;
for ( V_6 = 0 ; V_6 < V_353 ; V_6 ++ )
F_14 ( V_2 , V_6 ) ;
}
F_7 ( V_2 -> V_44 , L_52 ,
V_19 -> V_95 ) ;
if ( V_19 -> V_95 )
F_77 ( V_4 ) ;
else
F_80 ( V_4 -> V_2 , V_354 ,
F_4 ( V_354 ) ) ;
for ( V_6 = 0 ; V_6 < F_4 ( V_19 -> V_355 ) ; V_6 ++ ) {
if ( V_19 -> V_355 [ V_6 ] ) {
F_53 ( V_2 , V_225 + V_6 ,
V_19 -> V_355 [ V_6 ] & 0xffff ) ;
}
}
}
int F_84 ( struct V_1 * V_2 , struct V_356 * V_334 ,
int V_355 , int V_357 , int V_358 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_359 * V_333 ;
struct V_4 * V_171 = V_4 -> V_4 ;
int V_53 ;
if ( V_171 -> type != V_200 )
return - V_42 ;
switch ( V_355 ) {
case 1 :
V_333 = & V_4 -> V_333 [ 0 ] ;
break;
case 2 :
V_333 = & V_4 -> V_333 [ 1 ] ;
break;
default:
return - V_42 ;
}
F_7 ( V_2 -> V_44 , L_53 ,
V_355 , V_357 , V_358 ) ;
V_333 -> V_334 = V_334 ;
V_333 -> V_357 = V_357 ;
V_333 -> V_358 = V_358 ;
if ( V_4 -> V_333 [ 0 ] . V_334 || V_4 -> V_333 [ 1 ] . V_334 )
V_53 = V_323 ;
else
V_53 = 0 ;
F_5 ( V_2 , V_322 , V_323 , V_53 ) ;
return 0 ;
}
static T_3 F_85 ( int V_205 , void * V_206 )
{
struct V_3 * V_360 = V_206 ;
struct V_1 * V_2 = V_360 -> V_2 ;
int V_53 ;
int V_361 ;
#ifndef F_86
F_87 ( F_88 ( V_2 -> V_44 ) ) ;
#endif
V_53 = F_3 ( V_2 , V_362 ) ;
if ( V_53 < 0 ) {
F_68 ( V_2 -> V_44 , L_54 ,
V_53 ) ;
return V_208 ;
}
F_7 ( V_2 -> V_44 , L_55 , V_53 ) ;
V_361 = 0 ;
if ( V_53 & V_363 )
V_361 |= V_360 -> V_333 [ 0 ] . V_357 ;
if ( V_53 & V_364 )
V_361 |= V_360 -> V_333 [ 0 ] . V_358 ;
F_89 ( V_360 -> V_333 [ 0 ] . V_334 , V_361 ,
V_360 -> V_333 [ 0 ] . V_357 | V_360 -> V_333 [ 0 ] . V_358 ) ;
V_361 = 0 ;
if ( V_53 & V_365 )
V_361 |= V_360 -> V_333 [ 1 ] . V_357 ;
if ( V_53 & V_366 )
V_361 |= V_360 -> V_333 [ 1 ] . V_358 ;
F_89 ( V_360 -> V_333 [ 1 ] . V_334 , V_361 ,
V_360 -> V_333 [ 1 ] . V_357 | V_360 -> V_333 [ 1 ] . V_358 ) ;
return V_208 ;
}
static void V_14 ( T_1 V_367 , void * V_206 )
{
struct V_1 * V_2 = V_206 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_361 ;
F_7 ( V_2 -> V_44 , L_56 , V_367 ) ;
if ( ! ( V_367 & V_368 ) ) {
if ( ! V_4 -> V_22 ) {
F_7 ( V_2 -> V_44 , L_57 ) ;
V_4 -> V_15 = false ;
V_4 -> V_108 = true ;
F_1 ( V_2 ) ;
F_89 ( V_4 -> V_333 [ 0 ] . V_334 , 0 ,
V_4 -> V_369 |
V_370 ) ;
}
return;
}
if ( V_4 -> V_108 && ( V_367 & 0x600 ) ) {
F_7 ( V_2 -> V_44 , L_58 ) ;
V_4 -> V_108 = false ;
V_4 -> V_15 = true ;
F_1 ( V_2 ) ;
F_89 ( V_4 -> V_333 [ 0 ] . V_334 , V_370 ,
V_370 ) ;
}
if ( V_4 -> V_108 && V_367 & 0x4 ) {
F_7 ( V_2 -> V_44 , L_59 ) ;
V_4 -> V_108 = false ;
F_1 ( V_2 ) ;
F_89 ( V_4 -> V_333 [ 0 ] . V_334 , V_371 ,
V_370 ) ;
if ( V_4 -> V_22 ) {
F_5 ( V_2 , V_29 ,
V_324 , 0 ) ;
F_22 ( V_2 ,
V_109 ) ;
}
}
if ( V_4 -> V_15 ) {
V_361 = 0 ;
if ( V_367 & 0x4 )
V_361 |= V_372 ;
if ( V_367 & 0x8 )
V_361 |= V_373 ;
if ( V_367 & 0x10 )
V_361 |= V_374 ;
if ( V_367 & 0x20 )
V_361 |= V_375 ;
if ( V_367 & 0x40 )
V_361 |= V_376 ;
if ( V_367 & 0x80 )
V_361 |= V_377 ;
F_89 ( V_4 -> V_333 [ 0 ] . V_334 , V_361 ,
V_4 -> V_369 ) ;
}
}
static T_3 F_90 ( int V_205 , void * V_206 )
{
struct V_3 * V_4 = V_206 ;
struct V_1 * V_2 = V_4 -> V_2 ;
int V_53 ;
F_25 ( & V_4 -> V_107 ) ;
V_53 = F_3 ( V_2 , V_378 ) ;
if ( V_53 < 0 ) {
F_68 ( V_2 -> V_44 , L_60 , V_53 ) ;
F_26 ( & V_4 -> V_107 ) ;
return V_379 ;
}
F_7 ( V_2 -> V_44 , L_61 , V_53 ) ;
if ( V_53 & V_380 ) {
F_7 ( V_2 -> V_44 , L_62 ) ;
F_89 ( V_4 -> V_333 [ 0 ] . V_334 ,
V_381 , V_381 ) ;
V_4 -> V_108 = true ;
F_22 ( V_2 , V_106 ) ;
F_5 ( V_2 , V_29 ,
V_324 , V_324 ) ;
} else {
F_7 ( V_2 -> V_44 , L_63 ) ;
F_89 ( V_4 -> V_333 [ 0 ] . V_334 , 0 ,
V_381 | V_370 |
V_4 -> V_369 ) ;
V_4 -> V_108 = false ;
V_4 -> V_15 = false ;
F_5 ( V_2 , V_29 ,
V_324 , 0 ) ;
F_22 ( V_2 , V_109 ) ;
}
F_26 ( & V_4 -> V_107 ) ;
return V_208 ;
}
int F_91 ( struct V_1 * V_2 , struct V_356 * V_334 ,
T_4 V_382 , void * V_383 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_4 * V_171 = V_4 -> V_4 ;
T_1 V_384 ;
switch ( V_171 -> type ) {
case V_224 :
case V_201 :
break;
default:
return - V_42 ;
}
if ( V_334 ) {
if ( ! V_382 ) {
F_7 ( V_2 -> V_44 , L_64 ) ;
V_382 = V_14 ;
V_383 = V_2 ;
}
F_92 ( & V_2 -> V_49 , L_65 ) ;
V_4 -> V_333 [ 0 ] . V_334 = V_334 ;
V_4 -> V_13 = V_382 ;
V_4 -> V_385 = V_383 ;
V_4 -> V_108 = true ;
V_4 -> V_15 = false ;
F_1 ( V_2 ) ;
if ( V_4 -> V_19 -> V_384 )
V_384 = V_4 -> V_19 -> V_384 ;
else
V_384 = 0x41 ;
V_4 -> V_369 = V_372 | V_373 |
V_374 | V_375 |
V_376 | V_377 ;
F_5 ( V_2 , V_386 ,
V_387 , V_384 ) ;
F_93 ( V_2 -> V_49 . V_229 > V_230 ) ;
if ( V_4 -> V_22 ) {
F_5 ( V_2 , V_388 ,
V_389 , 0 ) ;
F_22 ( V_2 ,
V_109 ) ;
} else {
F_5 ( V_2 , V_29 ,
V_324 , V_324 ) ;
}
} else {
F_5 ( V_2 , V_29 ,
V_324 , 0 ) ;
F_94 ( & V_2 -> V_49 , L_65 ) ;
}
return 0 ;
}
static T_3 F_95 ( int V_205 , void * V_206 )
{
struct V_3 * V_4 = V_206 ;
struct V_1 * V_2 = V_4 -> V_2 ;
int V_53 , V_390 ;
F_25 ( & V_4 -> V_107 ) ;
if ( ! ( F_3 ( V_2 , V_29 ) & V_324 ) ) {
F_26 ( & V_4 -> V_107 ) ;
return V_208 ;
}
V_390 = 10 ;
do {
V_53 = F_3 ( V_2 , V_391 ) ;
if ( V_53 < 0 ) {
F_26 ( & V_4 -> V_107 ) ;
F_68 ( V_2 -> V_44 ,
L_66 ,
V_53 ) ;
return V_379 ;
}
if ( ! ( V_53 & V_392 ) ) {
F_7 ( V_2 -> V_44 , L_67 ) ;
goto V_40;
}
if ( ! ( V_53 & V_368 ) || ( V_53 & V_393 ) )
break;
F_23 ( 1 ) ;
} while ( V_390 -- );
if ( V_390 == 0 )
F_57 ( V_2 -> V_44 , L_68 ) ;
#ifndef F_86
F_87 ( F_88 ( V_2 -> V_44 ) ) ;
#endif
if ( V_4 -> V_13 )
V_4 -> V_13 ( V_53 , V_4 -> V_385 ) ;
else
F_57 ( V_2 -> V_44 , L_69 ) ;
V_40:
F_26 ( & V_4 -> V_107 ) ;
return V_208 ;
}
static T_3 F_96 ( int V_205 , void * V_206 )
{
struct V_1 * V_2 = V_206 ;
F_68 ( V_2 -> V_44 , L_70 ) ;
return V_208 ;
}
static T_3 F_97 ( int V_205 , void * V_206 )
{
struct V_1 * V_2 = V_206 ;
F_68 ( V_2 -> V_44 , L_71 ) ;
return V_208 ;
}
static T_3 F_98 ( int V_205 , void * V_206 )
{
struct V_1 * V_2 = V_206 ;
F_99 ( V_2 -> V_44 , L_72 ) ;
return V_208 ;
}
static int F_100 ( struct V_1 * V_2 )
{
struct V_4 * V_171 = F_101 ( V_2 -> V_44 -> V_394 ) ;
struct V_3 * V_4 ;
struct V_395 * V_49 = & V_2 -> V_49 ;
unsigned int V_53 ;
int V_64 , V_6 ;
V_2 -> V_396 = V_171 -> V_327 ;
V_4 = F_83 ( V_2 -> V_44 , sizeof( struct V_3 ) ,
V_340 ) ;
if ( V_4 == NULL )
return - V_397 ;
F_102 ( V_2 , V_4 ) ;
F_103 ( V_2 , 16 , 16 , V_398 ) ;
V_4 -> V_4 = F_101 ( V_2 -> V_44 -> V_394 ) ;
V_4 -> V_19 = F_104 ( V_2 -> V_44 -> V_394 ) ;
V_4 -> V_2 = V_2 ;
F_105 ( & V_4 -> V_107 ) ;
for ( V_6 = 0 ; V_6 < F_4 ( V_4 -> V_199 ) ; V_6 ++ )
F_106 ( & V_4 -> V_199 [ V_6 ] ) ;
if ( V_4 -> V_19 && V_4 -> V_19 -> V_399 )
V_4 -> V_399 = V_4 -> V_19 -> V_399 ;
else if ( V_4 -> V_19 && V_4 -> V_19 -> V_400 )
V_4 -> V_399 = V_4 -> V_19 -> V_400 +
V_401 ;
F_107 ( V_2 -> V_44 ) ;
F_108 ( V_2 -> V_44 ) ;
V_4 -> V_202 = F_3 ( V_2 , V_402 ) ;
switch ( V_171 -> type ) {
case V_200 :
switch ( V_4 -> V_202 ) {
case 2 :
case 3 :
V_4 -> V_141 . V_403 = - 5 ;
V_4 -> V_141 . V_404 = - 5 ;
V_4 -> V_141 . V_405 = 1 ;
V_4 -> V_141 . V_406 = 1 ;
V_4 -> V_141 . V_407 = 1 ;
break;
default:
V_4 -> V_141 . V_406 = 2 ;
break;
}
break;
case V_201 :
V_4 -> V_141 . V_406 = 1 ;
break;
case V_224 :
V_4 -> V_141 . V_406 = 2 ;
V_4 -> V_141 . V_408 = 1 ;
switch ( V_4 -> V_202 ) {
case 0 :
case 1 :
case 2 :
case 3 :
V_4 -> V_141 . V_403 = - 9 ;
V_4 -> V_141 . V_404 = - 5 ;
break;
default:
break;
}
F_5 ( V_2 , V_409 ,
V_410 , V_410 ) ;
break;
default:
break;
}
F_109 ( V_4 -> V_4 , V_411 ,
F_96 , L_73 , V_2 ) ;
F_109 ( V_4 -> V_4 , V_412 ,
F_97 , L_74 , V_2 ) ;
F_109 ( V_4 -> V_4 , V_413 ,
F_98 , L_75 , V_2 ) ;
V_64 = F_109 ( V_4 -> V_4 , V_414 ,
V_415 , L_76 ,
& V_4 -> V_141 ) ;
if ( V_64 == 0 )
V_4 -> V_141 . V_416 = true ;
switch ( V_171 -> type ) {
case V_200 :
if ( V_4 -> V_399 ) {
V_64 = F_110 ( V_4 -> V_399 , NULL ,
F_85 ,
V_417 ,
L_77 ,
V_4 ) ;
if ( V_64 != 0 )
F_57 ( V_2 -> V_44 ,
L_78 ,
V_64 ) ;
}
V_64 = F_109 ( V_4 -> V_4 ,
V_418 ,
F_85 , L_79 ,
V_4 ) ;
if ( V_64 != 0 )
F_57 ( V_2 -> V_44 ,
L_80 ,
V_64 ) ;
V_64 = F_109 ( V_4 -> V_4 ,
V_419 ,
F_85 , L_81 ,
V_4 ) ;
if ( V_64 != 0 )
F_57 ( V_2 -> V_44 ,
L_82 ,
V_64 ) ;
V_64 = F_109 ( V_4 -> V_4 ,
V_420 ,
F_85 , L_83 ,
V_4 ) ;
if ( V_64 != 0 )
F_57 ( V_2 -> V_44 ,
L_84 ,
V_64 ) ;
break;
case V_201 :
case V_224 :
if ( V_4 -> V_399 ) {
V_64 = F_110 ( V_4 -> V_399 , NULL ,
F_95 ,
V_417 ,
L_85 ,
V_4 ) ;
if ( V_64 != 0 )
F_57 ( V_2 -> V_44 ,
L_86 ,
V_64 ) ;
}
}
switch ( V_171 -> type ) {
case V_224 :
if ( V_4 -> V_202 > 1 ) {
V_64 = F_109 ( V_4 -> V_4 ,
F_111 ( 6 ) ,
F_90 , L_87 ,
V_4 ) ;
if ( V_64 == 0 )
V_4 -> V_22 = true ;
}
break;
default:
break;
}
V_4 -> V_204 = true ;
for ( V_6 = 0 ; V_6 < F_4 ( V_4 -> V_199 ) ; V_6 ++ ) {
V_64 = F_109 ( V_4 -> V_4 ,
V_421 + V_6 ,
F_58 , L_88 ,
& V_4 -> V_199 [ V_6 ] ) ;
if ( V_64 != 0 )
V_4 -> V_204 = false ;
}
V_64 = F_76 ( V_171 -> V_327 , V_422 , & V_53 ) ;
if ( V_64 < 0 ) {
F_68 ( V_2 -> V_44 , L_89 , V_64 ) ;
goto V_423;
}
if ( ( V_53 & V_424 ) != V_425 ) {
V_4 -> V_281 [ 0 ] = 1 ;
V_426 [ 0 ] . V_427 = 1 ;
} else {
V_4 -> V_281 [ 0 ] = 0 ;
}
V_64 = F_76 ( V_171 -> V_327 , V_428 , & V_53 ) ;
if ( V_64 < 0 ) {
F_68 ( V_2 -> V_44 , L_90 , V_64 ) ;
goto V_423;
}
if ( ( V_53 & V_424 ) != V_425 ) {
V_4 -> V_281 [ 1 ] = 1 ;
V_426 [ 1 ] . V_427 = 1 ;
} else {
V_4 -> V_281 [ 1 ] = 0 ;
}
F_62 ( V_2 , V_230 ) ;
F_5 ( V_2 , V_429 ,
V_430 , V_430 ) ;
F_5 ( V_2 , V_431 ,
V_430 , V_430 ) ;
F_5 ( V_2 , V_432 ,
V_433 , V_433 ) ;
F_5 ( V_2 , V_434 ,
V_433 , V_433 ) ;
F_5 ( V_2 , V_435 ,
V_436 , V_436 ) ;
F_5 ( V_2 , V_437 ,
V_436 , V_436 ) ;
F_5 ( V_2 , V_438 ,
V_439 , V_439 ) ;
F_5 ( V_2 , V_440 ,
V_439 , V_439 ) ;
F_5 ( V_2 , V_441 ,
V_442 , V_442 ) ;
F_5 ( V_2 , V_443 ,
V_442 , V_442 ) ;
F_5 ( V_2 , V_444 ,
V_445 , V_442 ) ;
F_5 ( V_2 , V_446 ,
V_445 , V_442 ) ;
F_5 ( V_2 , V_447 ,
V_448 , V_448 ) ;
F_5 ( V_2 , V_449 ,
V_448 , V_448 ) ;
F_5 ( V_2 , V_450 ,
V_451 , V_451 ) ;
F_5 ( V_2 , V_452 ,
V_451 , V_451 ) ;
F_5 ( V_2 , V_453 ,
1 << V_454 ,
1 << V_454 ) ;
F_5 ( V_2 , V_455 ,
1 << V_456 ,
1 << V_456 ) ;
F_5 ( V_2 , V_457 ,
1 << V_458 ,
1 << V_458 ) ;
switch ( V_171 -> type ) {
case V_200 :
case V_201 :
F_5 ( V_2 , V_240 ,
V_459 , V_459 ) ;
break;
default:
break;
}
switch ( V_171 -> type ) {
case V_201 :
case V_224 :
F_5 ( V_2 , V_225 ,
V_226 , V_226 ) ;
F_5 ( V_2 , V_227 ,
V_228 , V_228 ) ;
break;
default:
break;
}
F_34 ( V_2 ) ;
F_81 ( V_4 ) ;
F_112 ( V_2 ) ;
F_80 ( V_2 , V_460 ,
F_4 ( V_460 ) ) ;
F_113 ( V_49 , V_461 ,
F_4 ( V_461 ) ) ;
switch ( V_171 -> type ) {
case V_200 :
F_113 ( V_49 , V_462 ,
F_4 ( V_462 ) ) ;
if ( V_4 -> V_202 < 4 ) {
F_113 ( V_49 , V_463 ,
F_4 ( V_463 ) ) ;
F_113 ( V_49 , V_464 ,
F_4 ( V_464 ) ) ;
F_113 ( V_49 , V_465 ,
F_4 ( V_465 ) ) ;
} else {
F_113 ( V_49 , V_466 ,
F_4 ( V_466 ) ) ;
F_113 ( V_49 , V_467 ,
F_4 ( V_467 ) ) ;
F_113 ( V_49 , V_468 ,
F_4 ( V_468 ) ) ;
}
break;
case V_201 :
F_80 ( V_2 , V_469 ,
F_4 ( V_469 ) ) ;
F_113 ( V_49 , V_470 ,
F_4 ( V_470 ) ) ;
if ( V_4 -> V_202 < 1 ) {
F_113 ( V_49 , V_463 ,
F_4 ( V_463 ) ) ;
F_113 ( V_49 , V_464 ,
F_4 ( V_464 ) ) ;
F_113 ( V_49 , V_465 ,
F_4 ( V_465 ) ) ;
} else {
F_113 ( V_49 , V_466 ,
F_4 ( V_466 ) ) ;
F_113 ( V_49 , V_467 ,
F_4 ( V_467 ) ) ;
F_113 ( V_49 , V_468 ,
F_4 ( V_468 ) ) ;
}
break;
case V_224 :
F_80 ( V_2 , V_469 ,
F_4 ( V_469 ) ) ;
F_113 ( V_49 , V_470 ,
F_4 ( V_470 ) ) ;
F_113 ( V_49 , V_466 ,
F_4 ( V_466 ) ) ;
F_113 ( V_49 , V_467 ,
F_4 ( V_467 ) ) ;
F_113 ( V_49 , V_468 ,
F_4 ( V_468 ) ) ;
break;
}
F_114 ( V_2 , 0 , 0 ) ;
F_115 ( V_49 , V_471 , F_4 ( V_471 ) ) ;
switch ( V_171 -> type ) {
case V_200 :
F_115 ( V_49 , V_472 ,
F_4 ( V_472 ) ) ;
if ( V_4 -> V_202 < 4 ) {
F_115 ( V_49 , V_473 ,
F_4 ( V_473 ) ) ;
F_115 ( V_49 , V_474 ,
F_4 ( V_474 ) ) ;
} else {
F_115 ( V_49 , V_475 ,
F_4 ( V_475 ) ) ;
}
break;
case V_201 :
if ( V_4 -> V_202 < 1 ) {
F_115 ( V_49 , V_473 ,
F_4 ( V_473 ) ) ;
F_115 ( V_49 , V_474 ,
F_4 ( V_474 ) ) ;
} else {
F_115 ( V_49 , V_475 ,
F_4 ( V_475 ) ) ;
F_115 ( V_49 , V_476 ,
F_4 ( V_476 ) ) ;
}
F_116 ( V_2 ) ;
break;
case V_224 :
F_115 ( V_49 , V_475 ,
F_4 ( V_475 ) ) ;
F_115 ( V_49 , V_476 ,
F_4 ( V_476 ) ) ;
break;
}
return 0 ;
V_423:
if ( V_4 -> V_22 )
F_117 ( V_4 -> V_4 , F_111 ( 6 ) , V_4 ) ;
F_117 ( V_4 -> V_4 , V_420 , V_4 ) ;
F_117 ( V_4 -> V_4 , V_419 , V_4 ) ;
F_117 ( V_4 -> V_4 , V_418 , V_4 ) ;
if ( V_4 -> V_399 )
F_118 ( V_4 -> V_399 , V_4 ) ;
for ( V_6 = 0 ; V_6 < F_4 ( V_4 -> V_199 ) ; V_6 ++ )
F_117 ( V_4 -> V_4 , V_421 + V_6 ,
& V_4 -> V_199 [ V_6 ] ) ;
F_117 ( V_4 -> V_4 , V_414 ,
& V_4 -> V_141 ) ;
F_117 ( V_4 -> V_4 , V_411 , V_2 ) ;
F_117 ( V_4 -> V_4 , V_413 , V_2 ) ;
F_117 ( V_4 -> V_4 , V_412 , V_2 ) ;
return V_64 ;
}
static int F_119 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_4 * V_171 = V_4 -> V_4 ;
int V_6 ;
F_62 ( V_2 , V_231 ) ;
F_120 ( V_2 -> V_44 ) ;
for ( V_6 = 0 ; V_6 < F_4 ( V_4 -> V_199 ) ; V_6 ++ )
F_117 ( V_4 -> V_4 , V_421 + V_6 ,
& V_4 -> V_199 [ V_6 ] ) ;
F_117 ( V_4 -> V_4 , V_414 ,
& V_4 -> V_141 ) ;
F_117 ( V_4 -> V_4 , V_411 , V_2 ) ;
F_117 ( V_4 -> V_4 , V_413 , V_2 ) ;
F_117 ( V_4 -> V_4 , V_412 , V_2 ) ;
if ( V_4 -> V_22 )
F_117 ( V_4 -> V_4 , F_111 ( 6 ) , V_4 ) ;
switch ( V_171 -> type ) {
case V_200 :
if ( V_4 -> V_399 )
F_118 ( V_4 -> V_399 , V_4 ) ;
F_117 ( V_4 -> V_4 , V_419 ,
V_4 ) ;
F_117 ( V_4 -> V_4 , V_418 ,
V_4 ) ;
F_117 ( V_4 -> V_4 , V_401 ,
V_4 ) ;
break;
case V_224 :
case V_201 :
if ( V_4 -> V_399 )
F_118 ( V_4 -> V_399 , V_4 ) ;
break;
}
if ( V_4 -> V_477 )
F_121 ( V_4 -> V_477 ) ;
if ( V_4 -> V_478 )
F_121 ( V_4 -> V_478 ) ;
if ( V_4 -> V_479 )
F_121 ( V_4 -> V_479 ) ;
F_122 ( V_4 -> V_97 ) ;
return 0 ;
}
static int F_123 ( struct V_1 * V_2 ,
unsigned int V_53 )
{
return true ;
}
static int T_5 F_124 ( struct V_480 * V_481 )
{
return F_125 ( & V_481 -> V_44 , & V_482 ,
V_426 , F_4 ( V_426 ) ) ;
}
static int T_6 F_126 ( struct V_480 * V_481 )
{
F_127 ( & V_481 -> V_44 ) ;
return 0 ;
}
