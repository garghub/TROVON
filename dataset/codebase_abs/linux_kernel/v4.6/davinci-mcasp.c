static inline void F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 )
{
void T_2 * V_5 = V_2 -> V_6 + V_3 ;
F_2 ( F_3 ( V_5 ) | V_4 , V_5 ) ;
}
static inline void F_4 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 )
{
void T_2 * V_5 = V_2 -> V_6 + V_3 ;
F_2 ( ( F_3 ( V_5 ) & ~ ( V_4 ) ) , V_5 ) ;
}
static inline void F_5 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 , T_1 V_7 )
{
void T_2 * V_5 = V_2 -> V_6 + V_3 ;
F_2 ( ( F_3 ( V_5 ) & ~ V_7 ) | V_4 , V_5 ) ;
}
static inline void F_6 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 )
{
F_2 ( V_4 , V_2 -> V_6 + V_3 ) ;
}
static inline T_1 F_7 ( struct V_1 * V_2 , T_1 V_3 )
{
return ( T_1 ) F_3 ( V_2 -> V_6 + V_3 ) ;
}
static void F_8 ( struct V_1 * V_2 , T_1 V_8 , T_1 V_4 )
{
int V_9 = 0 ;
F_1 ( V_2 , V_8 , V_4 ) ;
for ( V_9 = 0 ; V_9 < 1000 ; V_9 ++ ) {
if ( ( F_7 ( V_2 , V_8 ) & V_4 ) == V_4 )
break;
}
if ( V_9 == 1000 && ( ( F_7 ( V_2 , V_8 ) & V_4 ) != V_4 ) )
F_9 ( V_10 L_1 ) ;
}
static bool F_10 ( struct V_1 * V_2 )
{
T_1 V_11 = F_7 ( V_2 , V_12 ) ;
T_1 V_13 = F_7 ( V_2 , V_14 ) ;
return ! ( V_13 & V_15 ) && V_11 & V_16 ;
}
static void F_11 ( struct V_1 * V_2 )
{
if ( V_2 -> V_17 ) {
T_1 V_5 = V_2 -> V_18 + V_19 ;
F_4 ( V_2 , V_5 , V_20 ) ;
F_1 ( V_2 , V_5 , V_20 ) ;
}
F_8 ( V_2 , V_21 , V_22 ) ;
F_8 ( V_2 , V_21 , V_23 ) ;
if ( F_10 ( V_2 ) ) {
F_8 ( V_2 , V_24 , V_25 ) ;
F_8 ( V_2 , V_24 , V_26 ) ;
}
F_8 ( V_2 , V_21 , V_27 ) ;
F_8 ( V_2 , V_21 , V_28 ) ;
F_8 ( V_2 , V_21 , V_29 ) ;
if ( F_10 ( V_2 ) )
F_8 ( V_2 , V_24 , V_30 ) ;
F_1 ( V_2 , V_31 ,
V_2 -> V_32 [ V_33 ] ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
T_1 V_34 ;
if ( V_2 -> V_35 ) {
T_1 V_5 = V_2 -> V_18 + V_36 ;
F_4 ( V_2 , V_5 , V_20 ) ;
F_1 ( V_2 , V_5 , V_20 ) ;
}
F_8 ( V_2 , V_24 , V_25 ) ;
F_8 ( V_2 , V_24 , V_26 ) ;
F_8 ( V_2 , V_24 , V_37 ) ;
V_34 = 0 ;
while ( ( F_7 ( V_2 , V_38 ) & V_39 ) &&
( V_34 < 100000 ) )
V_34 ++ ;
F_8 ( V_2 , V_24 , V_40 ) ;
F_8 ( V_2 , V_24 , V_30 ) ;
F_1 ( V_2 , V_41 ,
V_2 -> V_32 [ V_42 ] ) ;
}
static void F_13 ( struct V_1 * V_2 , int V_43 )
{
V_2 -> V_44 ++ ;
if ( V_43 == V_42 )
F_12 ( V_2 ) ;
else
F_11 ( V_2 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
F_4 ( V_2 , V_31 ,
V_2 -> V_32 [ V_33 ] ) ;
if ( F_10 ( V_2 ) && ! V_2 -> V_44 )
F_6 ( V_2 , V_24 , 0 ) ;
F_6 ( V_2 , V_21 , 0 ) ;
F_6 ( V_2 , V_45 , 0xFFFFFFFF ) ;
if ( V_2 -> V_17 ) {
T_1 V_5 = V_2 -> V_18 + V_19 ;
F_4 ( V_2 , V_5 , V_20 ) ;
}
}
static void F_15 ( struct V_1 * V_2 )
{
T_1 V_4 = 0 ;
F_4 ( V_2 , V_41 ,
V_2 -> V_32 [ V_42 ] ) ;
if ( F_10 ( V_2 ) && V_2 -> V_44 )
V_4 = V_25 | V_26 | V_30 ;
F_6 ( V_2 , V_24 , V_4 ) ;
F_6 ( V_2 , V_38 , 0xFFFFFFFF ) ;
if ( V_2 -> V_35 ) {
T_1 V_5 = V_2 -> V_18 + V_36 ;
F_4 ( V_2 , V_5 , V_20 ) ;
}
}
static void F_16 ( struct V_1 * V_2 , int V_43 )
{
V_2 -> V_44 -- ;
if ( V_43 == V_42 )
F_15 ( V_2 ) ;
else
F_14 ( V_2 ) ;
}
static T_3 F_17 ( int V_46 , void * V_47 )
{
struct V_1 * V_2 = (struct V_1 * ) V_47 ;
struct V_48 * V_49 ;
T_1 V_50 = V_2 -> V_32 [ V_42 ] ;
T_1 V_51 = 0 ;
T_1 V_52 ;
V_52 = F_7 ( V_2 , V_38 ) ;
if ( V_52 & V_53 & V_50 ) {
F_18 ( V_2 -> V_54 , L_2 ) ;
V_51 |= V_53 ;
V_49 = V_2 -> V_55 [ V_42 ] ;
if ( V_49 ) {
F_19 ( V_49 ) ;
if ( F_20 ( V_49 ) )
F_21 ( V_49 , V_56 ) ;
F_22 ( V_49 ) ;
}
}
if ( ! V_51 )
F_18 ( V_2 -> V_54 , L_3 ,
V_52 ) ;
if ( V_52 & V_57 )
V_51 |= V_57 ;
F_6 ( V_2 , V_38 , V_51 ) ;
return F_23 ( V_51 ) ;
}
static T_3 F_24 ( int V_46 , void * V_47 )
{
struct V_1 * V_2 = (struct V_1 * ) V_47 ;
struct V_48 * V_49 ;
T_1 V_50 = V_2 -> V_32 [ V_33 ] ;
T_1 V_51 = 0 ;
T_1 V_52 ;
V_52 = F_7 ( V_2 , V_45 ) ;
if ( V_52 & V_58 & V_50 ) {
F_18 ( V_2 -> V_54 , L_4 ) ;
V_51 |= V_58 ;
V_49 = V_2 -> V_55 [ V_33 ] ;
if ( V_49 ) {
F_19 ( V_49 ) ;
if ( F_20 ( V_49 ) )
F_21 ( V_49 , V_56 ) ;
F_22 ( V_49 ) ;
}
}
if ( ! V_51 )
F_18 ( V_2 -> V_54 , L_5 ,
V_52 ) ;
if ( V_52 & V_57 )
V_51 |= V_57 ;
F_6 ( V_2 , V_45 , V_51 ) ;
return F_23 ( V_51 ) ;
}
static T_3 F_25 ( int V_46 , void * V_47 )
{
struct V_1 * V_2 = (struct V_1 * ) V_47 ;
T_3 V_59 = V_60 ;
if ( V_2 -> V_55 [ V_42 ] )
V_59 = F_17 ( V_46 , V_47 ) ;
if ( V_2 -> V_55 [ V_33 ] )
V_59 |= F_24 ( V_46 , V_47 ) ;
return V_59 ;
}
static int F_26 ( struct V_61 * V_62 ,
unsigned int V_63 )
{
struct V_1 * V_2 = F_27 ( V_62 ) ;
int V_59 = 0 ;
T_1 V_64 ;
bool V_65 ;
bool V_66 = false ;
if ( ! V_63 )
return 0 ;
F_28 ( V_2 -> V_54 ) ;
switch ( V_63 & V_67 ) {
case V_68 :
F_4 ( V_2 , V_69 , V_70 ) ;
F_4 ( V_2 , V_12 , V_71 ) ;
V_64 = 1 ;
break;
case V_72 :
case V_73 :
F_4 ( V_2 , V_69 , V_70 ) ;
F_4 ( V_2 , V_12 , V_71 ) ;
V_64 = 0 ;
break;
case V_74 :
F_1 ( V_2 , V_69 , V_70 ) ;
F_1 ( V_2 , V_12 , V_71 ) ;
V_64 = 1 ;
V_66 = true ;
break;
case V_75 :
F_1 ( V_2 , V_69 , V_70 ) ;
F_1 ( V_2 , V_12 , V_71 ) ;
V_64 = 0 ;
break;
default:
V_59 = - V_76 ;
goto V_77;
}
F_5 ( V_2 , V_78 , F_29 ( V_64 ) ,
F_29 ( 3 ) ) ;
F_5 ( V_2 , V_79 , F_30 ( V_64 ) ,
F_30 ( 3 ) ) ;
switch ( V_63 & V_80 ) {
case V_81 :
F_1 ( V_2 , V_14 , V_82 ) ;
F_1 ( V_2 , V_69 , V_83 ) ;
F_1 ( V_2 , V_84 , V_85 ) ;
F_1 ( V_2 , V_12 , V_16 ) ;
F_1 ( V_2 , V_86 , V_87 | V_88 ) ;
F_1 ( V_2 , V_86 , V_89 | V_90 ) ;
V_2 -> V_91 = 1 ;
break;
case V_92 :
F_1 ( V_2 , V_14 , V_82 ) ;
F_4 ( V_2 , V_69 , V_83 ) ;
F_1 ( V_2 , V_84 , V_85 ) ;
F_4 ( V_2 , V_12 , V_16 ) ;
F_1 ( V_2 , V_86 , V_87 | V_88 ) ;
F_4 ( V_2 , V_86 , V_89 | V_90 ) ;
V_2 -> V_91 = 1 ;
break;
case V_93 :
F_4 ( V_2 , V_14 , V_82 ) ;
F_1 ( V_2 , V_69 , V_83 ) ;
F_4 ( V_2 , V_84 , V_85 ) ;
F_1 ( V_2 , V_12 , V_16 ) ;
F_4 ( V_2 , V_86 , V_87 | V_88 ) ;
F_1 ( V_2 , V_86 , V_89 | V_90 ) ;
V_2 -> V_91 = 0 ;
break;
case V_94 :
F_4 ( V_2 , V_14 , V_82 ) ;
F_4 ( V_2 , V_69 , V_83 ) ;
F_4 ( V_2 , V_84 , V_85 ) ;
F_4 ( V_2 , V_12 , V_16 ) ;
F_4 ( V_2 , V_86 ,
V_87 | V_95 | V_89 | V_88 | V_96 | V_90 ) ;
V_2 -> V_91 = 0 ;
break;
default:
V_59 = - V_76 ;
goto V_77;
}
switch ( V_63 & V_97 ) {
case V_98 :
F_4 ( V_2 , V_14 , V_99 ) ;
F_4 ( V_2 , V_84 , V_100 ) ;
V_65 = true ;
break;
case V_101 :
F_1 ( V_2 , V_14 , V_99 ) ;
F_1 ( V_2 , V_84 , V_100 ) ;
V_65 = false ;
break;
case V_102 :
F_4 ( V_2 , V_14 , V_99 ) ;
F_4 ( V_2 , V_84 , V_100 ) ;
V_65 = false ;
break;
case V_103 :
F_1 ( V_2 , V_14 , V_99 ) ;
F_1 ( V_2 , V_84 , V_100 ) ;
V_65 = true ;
break;
default:
V_59 = - V_76 ;
goto V_77;
}
if ( V_66 )
V_65 = ! V_65 ;
if ( V_65 ) {
F_4 ( V_2 , V_69 , V_104 ) ;
F_4 ( V_2 , V_12 , V_105 ) ;
} else {
F_1 ( V_2 , V_69 , V_104 ) ;
F_1 ( V_2 , V_12 , V_105 ) ;
}
V_2 -> V_106 = V_63 ;
V_77:
F_31 ( V_2 -> V_54 ) ;
return V_59 ;
}
static int F_32 ( struct V_61 * V_107 , int V_108 ,
int div , bool V_109 )
{
struct V_1 * V_2 = F_27 ( V_107 ) ;
F_28 ( V_2 -> V_54 ) ;
switch ( V_108 ) {
case 0 :
F_5 ( V_2 , V_110 ,
F_33 ( div - 1 ) , V_111 ) ;
F_5 ( V_2 , V_112 ,
F_34 ( div - 1 ) , V_113 ) ;
break;
case 1 :
F_5 ( V_2 , V_14 ,
F_35 ( div - 1 ) , V_114 ) ;
F_5 ( V_2 , V_84 ,
F_36 ( div - 1 ) , V_115 ) ;
if ( V_109 )
V_2 -> V_116 = div ;
break;
case 2 :
V_2 -> V_117 = div / V_2 -> V_118 ;
if ( div % V_2 -> V_118 )
F_18 ( V_2 -> V_54 ,
L_6 ,
V_119 , div , V_2 -> V_118 ) ;
break;
default:
return - V_76 ;
}
F_31 ( V_2 -> V_54 ) ;
return 0 ;
}
static int F_37 ( struct V_61 * V_107 , int V_108 ,
int div )
{
return F_32 ( V_107 , V_108 , div , 1 ) ;
}
static int F_38 ( struct V_61 * V_107 , int V_120 ,
unsigned int V_121 , int V_122 )
{
struct V_1 * V_2 = F_27 ( V_107 ) ;
F_28 ( V_2 -> V_54 ) ;
if ( V_122 == V_123 ) {
F_1 ( V_2 , V_110 , V_124 ) ;
F_1 ( V_2 , V_112 , V_125 ) ;
F_1 ( V_2 , V_86 , V_95 ) ;
} else {
F_4 ( V_2 , V_110 , V_124 ) ;
F_4 ( V_2 , V_112 , V_125 ) ;
F_4 ( V_2 , V_86 , V_95 ) ;
}
V_2 -> V_126 = V_121 ;
F_31 ( V_2 -> V_54 ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 , int V_43 ,
int V_127 )
{
struct V_128 * V_129 = & V_2 -> V_130 [ V_43 ] ;
unsigned int * V_131 = ( unsigned int * ) V_129 -> V_131 ;
int V_132 = V_2 -> V_118 ;
int V_9 , V_133 = 0 ;
if ( V_2 -> V_134 [ V_43 ] )
V_132 = F_40 ( V_2 -> V_134 [ V_43 ] ) ;
for ( V_9 = 2 ; V_9 <= V_132 ; V_9 ++ )
V_131 [ V_133 ++ ] = V_9 ;
for ( V_9 = 2 ; V_9 <= V_127 ; V_9 ++ )
V_131 [ V_133 ++ ] = V_9 * V_132 ;
V_129 -> V_133 = V_133 ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 )
{
int V_135 = 0 , V_136 = 0 , V_59 , V_9 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_137 ; V_9 ++ )
if ( V_2 -> V_138 [ V_9 ] == V_139 )
V_136 ++ ;
else if ( V_2 -> V_138 [ V_9 ] == V_140 )
V_135 ++ ;
V_59 = F_39 ( V_2 , V_42 ,
V_136 ) ;
if ( V_59 )
return V_59 ;
V_59 = F_39 ( V_2 , V_33 ,
V_135 ) ;
return V_59 ;
}
static int F_42 ( struct V_61 * V_107 ,
unsigned int V_141 ,
unsigned int V_142 ,
int V_132 , int V_117 )
{
struct V_1 * V_2 = F_27 ( V_107 ) ;
F_43 ( V_2 -> V_54 ,
L_7 ,
V_119 , V_141 , V_142 , V_132 , V_117 ) ;
if ( V_141 >= ( 1 << V_132 ) || V_142 >= ( 1 << V_132 ) ) {
F_44 ( V_2 -> V_54 ,
L_8 ,
V_141 , V_142 , V_132 ) ;
return - V_76 ;
}
if ( V_117 &&
( V_117 < 8 || V_117 > 32 || V_117 % 4 != 0 ) ) {
F_44 ( V_2 -> V_54 , L_9 ,
V_119 , V_117 ) ;
return - V_76 ;
}
V_2 -> V_118 = V_132 ;
V_2 -> V_134 [ V_42 ] = V_141 ;
V_2 -> V_134 [ V_33 ] = V_142 ;
V_2 -> V_117 = V_117 ;
return F_41 ( V_2 ) ;
}
static int F_45 ( struct V_1 * V_2 ,
int V_143 )
{
T_1 V_63 ;
T_1 V_144 = ( V_143 / 4 ) & 0x7 ;
T_1 V_7 = ( 1ULL << V_143 ) - 1 ;
T_1 V_117 = V_143 ;
T_1 V_145 = 0 ;
if ( V_2 -> V_117 ) {
V_117 = V_2 -> V_117 ;
V_145 = ( V_117 - V_143 ) / 4 ;
}
V_63 = ( V_117 >> 1 ) - 1 ;
if ( V_2 -> V_146 != V_147 ) {
F_5 ( V_2 , V_79 , F_46 ( V_63 ) ,
F_46 ( 0x0F ) ) ;
F_5 ( V_2 , V_78 , F_47 ( V_63 ) ,
F_47 ( 0x0F ) ) ;
F_5 ( V_2 , V_78 , F_48 ( V_144 ) ,
F_48 ( 7 ) ) ;
F_5 ( V_2 , V_79 , F_49 ( V_145 ) ,
F_49 ( 7 ) ) ;
F_6 ( V_2 , V_148 , V_7 ) ;
}
F_6 ( V_2 , V_149 , V_7 ) ;
return 0 ;
}
static int F_50 ( struct V_1 * V_2 , int V_43 ,
int V_150 , int V_151 )
{
struct V_152 * V_153 = & V_2 -> V_153 [ V_43 ] ;
int V_9 ;
T_4 V_154 = 0 ;
T_4 V_155 = 0 ;
T_4 V_132 = V_2 -> V_118 ;
T_4 V_156 = ( V_151 + V_132 - 1 ) / V_132 ;
int V_157 , V_158 ;
T_1 V_5 ;
if ( V_2 -> V_159 < V_160 )
F_1 ( V_2 , V_161 , V_162 ) ;
F_6 ( V_2 , V_163 , 0x00000000 ) ;
if ( V_43 == V_42 ) {
F_6 ( V_2 , V_38 , 0xFFFFFFFF ) ;
F_4 ( V_2 , V_164 , V_165 ) ;
} else {
F_6 ( V_2 , V_45 , 0xFFFFFFFF ) ;
F_4 ( V_2 , V_166 , V_167 ) ;
}
for ( V_9 = 0 ; V_9 < V_2 -> V_137 ; V_9 ++ ) {
F_1 ( V_2 , F_51 ( V_9 ) ,
V_2 -> V_138 [ V_9 ] ) ;
if ( V_2 -> V_138 [ V_9 ] == V_139 &&
V_154 < V_156 ) {
F_1 ( V_2 , V_86 , F_52 ( V_9 ) ) ;
F_5 ( V_2 , F_51 ( V_9 ) ,
V_168 , V_169 ) ;
V_154 ++ ;
} else if ( V_2 -> V_138 [ V_9 ] == V_140 &&
V_155 < V_156 ) {
F_4 ( V_2 , V_86 , F_52 ( V_9 ) ) ;
V_155 ++ ;
} else {
F_5 ( V_2 , F_51 ( V_9 ) ,
V_170 , V_171 ) ;
}
}
if ( V_43 == V_42 ) {
V_157 = V_154 ;
V_158 = V_2 -> V_35 ;
V_5 = V_2 -> V_18 + V_36 ;
} else {
V_157 = V_155 ;
V_158 = V_2 -> V_17 ;
V_5 = V_2 -> V_18 + V_19 ;
}
if ( V_157 < V_156 ) {
F_18 ( V_2 -> V_54 , L_10
L_11 , V_151 ,
V_157 * V_132 ) ;
return - V_76 ;
}
if ( ! V_158 ) {
if ( V_157 > 1 ) {
V_153 -> V_172 = V_157 ;
} else {
V_153 -> V_172 = 0 ;
}
return 0 ;
}
if ( V_150 % V_157 ) {
F_44 ( V_2 -> V_54 , L_12
L_13 , V_150 ,
V_157 ) ;
return - V_76 ;
}
V_158 = ( V_158 / V_157 ) * V_157 ;
while ( V_150 % V_158 && V_158 > 0 )
V_158 -= V_157 ;
if ( V_158 <= 0 )
V_158 = V_157 ;
F_5 ( V_2 , V_5 , V_157 , V_173 ) ;
F_5 ( V_2 , V_5 , F_53 ( V_158 ) , V_174 ) ;
if ( V_158 == 1 )
V_158 = 0 ;
V_153 -> V_172 = V_158 ;
return 0 ;
}
static int F_54 ( struct V_1 * V_2 , int V_43 ,
int V_151 )
{
int V_9 , V_175 ;
int V_176 ;
int V_157 ;
T_1 V_7 = 0 ;
T_1 V_177 = 0 ;
V_176 = V_2 -> V_118 ;
if ( V_2 -> V_134 [ V_43 ] ) {
V_175 = F_40 ( V_2 -> V_134 [ V_43 ] ) ;
V_157 = ( V_151 + V_175 - 1 ) /
V_175 ;
if ( V_157 == 1 ) {
V_175 = V_151 ;
for ( V_9 = 0 ; V_9 < V_176 ; V_9 ++ ) {
if ( ( 1 << V_9 ) & V_2 -> V_134 [ V_43 ] ) {
V_7 |= ( 1 << V_9 ) ;
if ( -- V_175 <= 0 )
break;
}
}
}
} else {
V_157 = ( V_151 + V_176 - 1 ) / V_176 ;
if ( V_157 == 1 )
V_175 = V_151 ;
else
V_175 = V_176 ;
for ( V_9 = 0 ; V_9 < V_175 ; V_9 ++ )
V_7 |= ( 1 << V_9 ) ;
}
F_4 ( V_2 , V_14 , V_15 ) ;
if ( ! V_2 -> V_178 )
V_177 = V_179 ;
if ( V_43 == V_42 ) {
F_6 ( V_2 , V_180 , V_7 ) ;
F_1 ( V_2 , V_78 , V_177 | V_181 ) ;
F_5 ( V_2 , V_69 ,
F_55 ( V_176 ) , F_55 ( 0x1FF ) ) ;
} else if ( V_43 == V_33 ) {
F_6 ( V_2 , V_182 , V_7 ) ;
F_1 ( V_2 , V_79 , V_177 | V_183 ) ;
F_5 ( V_2 , V_12 ,
F_56 ( V_176 ) , F_56 ( 0x1FF ) ) ;
if ( F_10 ( V_2 ) && ! V_2 -> V_151 )
F_5 ( V_2 , V_69 ,
F_55 ( V_176 ) , F_55 ( 0x1FF ) ) ;
}
return 0 ;
}
static int F_57 ( struct V_1 * V_2 ,
unsigned int V_184 )
{
T_1 V_185 = 0 ;
T_4 * V_186 = ( T_4 * ) & V_185 ;
F_1 ( V_2 , V_78 , F_48 ( 6 ) | F_47 ( 15 ) ) ;
F_6 ( V_2 , V_69 , V_83 | F_55 ( 0x180 ) ) ;
F_6 ( V_2 , V_180 , 0xFFFFFFFF ) ;
F_1 ( V_2 , V_14 , V_82 | V_15 ) ;
F_4 ( V_2 , V_164 , V_165 ) ;
F_1 ( V_2 , V_110 , F_33 ( 3 ) ) ;
F_1 ( V_2 , V_187 , V_188 ) ;
V_186 [ 0 ] = V_189 ;
V_186 [ 1 ] = V_190 ;
switch ( V_184 ) {
case 22050 :
V_186 [ 3 ] |= V_191 ;
break;
case 24000 :
V_186 [ 3 ] |= V_192 ;
break;
case 32000 :
V_186 [ 3 ] |= V_193 ;
break;
case 44100 :
V_186 [ 3 ] |= V_194 ;
break;
case 48000 :
V_186 [ 3 ] |= V_195 ;
break;
case 88200 :
V_186 [ 3 ] |= V_196 ;
break;
case 96000 :
V_186 [ 3 ] |= V_197 ;
break;
case 176400 :
V_186 [ 3 ] |= V_198 ;
break;
case 192000 :
V_186 [ 3 ] |= V_199 ;
break;
default:
F_9 ( V_200 L_14 , V_184 ) ;
return - V_76 ;
}
F_6 ( V_2 , V_201 , V_185 ) ;
F_6 ( V_2 , V_202 , V_185 ) ;
return 0 ;
}
static int F_58 ( struct V_1 * V_2 ,
unsigned int V_203 ,
int * V_204 )
{
int div = V_2 -> V_126 / V_203 ;
int V_205 = V_2 -> V_126 % V_203 ;
if ( V_205 != 0 ) {
if ( div == 0 ||
( ( V_2 -> V_126 / div ) - V_203 ) >
( V_203 - ( V_2 -> V_126 / ( div + 1 ) ) ) ) {
div ++ ;
V_205 = V_205 - V_203 ;
}
}
if ( V_204 )
* V_204 =
( div * 1000000 + ( int ) F_59 ( 1000000LL * V_205 ,
( int ) V_203 ) )
/ div - 1000000 ;
return div ;
}
static int F_60 ( struct V_48 * V_49 ,
struct V_206 * V_207 ,
struct V_61 * V_62 )
{
struct V_1 * V_2 = F_27 ( V_62 ) ;
int V_208 ;
int V_151 = F_61 ( V_207 ) ;
int V_209 = F_62 ( V_207 ) ;
int V_59 ;
V_59 = F_26 ( V_62 , V_2 -> V_106 ) ;
if ( V_59 )
return V_59 ;
if ( V_2 -> V_91 && V_2 -> V_116 == 0 && V_2 -> V_126 ) {
int V_132 = V_2 -> V_118 ;
int V_184 = F_63 ( V_207 ) ;
int V_210 = F_64 ( V_207 ) ;
int V_211 , div ;
if ( V_2 -> V_117 )
V_210 = V_2 -> V_117 ;
div = F_58 ( V_2 , V_184 * V_210 * V_132 ,
& V_211 ) ;
if ( V_211 )
F_65 ( V_2 -> V_54 , L_15 ,
V_211 ) ;
F_32 ( V_62 , 1 , div , 0 ) ;
}
V_59 = F_50 ( V_2 , V_49 -> V_43 ,
V_209 * V_151 , V_151 ) ;
if ( V_59 )
return V_59 ;
if ( V_2 -> V_146 == V_147 )
V_59 = F_57 ( V_2 , F_63 ( V_207 ) ) ;
else
V_59 = F_54 ( V_2 , V_49 -> V_43 ,
V_151 ) ;
if ( V_59 )
return V_59 ;
switch ( F_66 ( V_207 ) ) {
case V_212 :
case V_213 :
V_208 = 8 ;
break;
case V_214 :
case V_215 :
V_208 = 16 ;
break;
case V_216 :
case V_217 :
V_208 = 24 ;
break;
case V_218 :
case V_219 :
V_208 = 24 ;
break;
case V_220 :
case V_221 :
V_208 = 32 ;
break;
default:
F_9 ( V_200 L_16 ) ;
return - V_76 ;
}
F_45 ( V_2 , V_208 ) ;
if ( V_2 -> V_146 == V_222 )
V_2 -> V_151 = V_151 ;
return 0 ;
}
static int F_67 ( struct V_48 * V_49 ,
int V_223 , struct V_61 * V_62 )
{
struct V_1 * V_2 = F_27 ( V_62 ) ;
int V_59 = 0 ;
switch ( V_223 ) {
case V_224 :
case V_225 :
case V_226 :
F_13 ( V_2 , V_49 -> V_43 ) ;
break;
case V_227 :
case V_228 :
case V_229 :
F_16 ( V_2 , V_49 -> V_43 ) ;
break;
default:
V_59 = - V_76 ;
}
return V_59 ;
}
static int F_68 ( struct V_206 * V_207 ,
struct V_230 * V_231 )
{
struct V_232 * V_233 = V_231 -> V_234 ;
struct V_235 * V_236 =
F_69 ( V_207 , V_237 ) ;
int V_210 = F_64 ( V_207 ) ;
int V_132 = V_233 -> V_2 -> V_118 ;
struct V_235 V_238 ;
int V_9 ;
if ( V_233 -> V_2 -> V_117 )
V_210 = V_233 -> V_2 -> V_117 ;
F_70 ( & V_238 ) ;
V_238 . V_239 = 1 ;
for ( V_9 = 0 ; V_9 < F_71 ( V_240 ) ; V_9 ++ ) {
if ( F_72 ( V_236 , V_240 [ V_9 ] ) ) {
T_5 V_203 = V_210 * V_132 *
V_240 [ V_9 ] ;
int V_211 ;
F_58 ( V_233 -> V_2 , V_203 , & V_211 ) ;
if ( abs ( V_211 ) < V_241 ) {
if ( V_238 . V_239 ) {
V_238 . V_242 = V_240 [ V_9 ] ;
V_238 . V_239 = 0 ;
}
V_238 . V_243 = V_240 [ V_9 ] ;
}
}
}
F_43 ( V_233 -> V_2 -> V_54 ,
L_17 ,
V_236 -> V_242 , V_236 -> V_243 , V_238 . V_242 , V_238 . V_243 , V_210 , V_132 ) ;
return F_73 ( F_69 ( V_207 , V_231 -> V_244 ) ,
& V_238 ) ;
}
static int F_74 ( struct V_206 * V_207 ,
struct V_230 * V_231 )
{
struct V_232 * V_233 = V_231 -> V_234 ;
struct V_245 * V_63 = F_75 ( V_207 , V_246 ) ;
struct V_245 V_247 ;
int V_184 = F_63 ( V_207 ) ;
int V_132 = V_233 -> V_2 -> V_118 ;
int V_9 , V_133 = 0 ;
F_76 ( & V_247 ) ;
for ( V_9 = 0 ; V_9 < V_248 ; V_9 ++ ) {
if ( F_77 ( V_63 , V_9 ) ) {
T_5 V_210 = F_78 ( V_9 ) ;
int V_211 ;
if ( V_233 -> V_2 -> V_117 )
V_210 = V_233 -> V_2 -> V_117 ;
F_58 ( V_233 -> V_2 , V_210 * V_132 * V_184 ,
& V_211 ) ;
if ( abs ( V_211 ) < V_241 ) {
F_79 ( & V_247 , V_9 ) ;
V_133 ++ ;
}
}
}
F_43 ( V_233 -> V_2 -> V_54 ,
L_18 ,
V_133 , V_184 , V_132 ) ;
return F_80 ( V_63 , & V_247 ) ;
}
static int F_81 ( struct V_48 * V_49 ,
struct V_61 * V_62 )
{
struct V_1 * V_2 = F_27 ( V_62 ) ;
struct V_232 * V_249 =
& V_2 -> V_249 [ V_49 -> V_43 ] ;
T_1 V_250 = 0 ;
int V_9 , V_122 ;
int V_118 = V_2 -> V_118 ;
if ( V_2 -> V_134 [ V_49 -> V_43 ] )
V_118 = F_40 ( V_2 -> V_134 [ V_49 -> V_43 ] ) ;
V_2 -> V_55 [ V_49 -> V_43 ] = V_49 ;
if ( V_2 -> V_146 == V_147 )
return 0 ;
if ( V_49 -> V_43 == V_42 )
V_122 = V_139 ;
else
V_122 = V_140 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_137 ; V_9 ++ ) {
if ( V_2 -> V_138 [ V_9 ] == V_122 )
V_250 ++ ;
}
V_249 -> V_127 = V_250 ;
V_250 *= V_118 ;
if ( V_2 -> V_151 && V_2 -> V_151 < V_250 )
V_250 = V_2 -> V_151 ;
if ( V_250 < V_118 )
V_250 = V_118 ;
F_82 ( V_49 -> V_251 ,
V_252 ,
2 , V_250 ) ;
V_128 ( V_49 -> V_251 ,
0 , V_252 ,
& V_2 -> V_130 [ V_49 -> V_43 ] ) ;
if ( V_2 -> V_117 )
F_82 ( V_49 -> V_251 ,
V_253 ,
8 , V_2 -> V_117 ) ;
if ( V_2 -> V_91 && V_2 -> V_116 == 0 && V_2 -> V_126 ) {
int V_59 ;
V_249 -> V_2 = V_2 ;
V_59 = F_83 ( V_49 -> V_251 , 0 ,
V_237 ,
F_68 ,
V_249 ,
V_246 , - 1 ) ;
if ( V_59 )
return V_59 ;
V_59 = F_83 ( V_49 -> V_251 , 0 ,
V_246 ,
F_74 ,
V_249 ,
V_237 , - 1 ) ;
if ( V_59 )
return V_59 ;
}
return 0 ;
}
static void F_84 ( struct V_48 * V_49 ,
struct V_61 * V_62 )
{
struct V_1 * V_2 = F_27 ( V_62 ) ;
V_2 -> V_55 [ V_49 -> V_43 ] = NULL ;
if ( V_2 -> V_146 == V_147 )
return;
if ( ! V_62 -> V_254 )
V_2 -> V_151 = 0 ;
}
static int F_85 ( struct V_61 * V_107 )
{
struct V_1 * V_2 = F_27 ( V_107 ) ;
V_107 -> V_255 = & V_2 -> V_153 [ V_42 ] ;
V_107 -> V_256 = & V_2 -> V_153 [ V_33 ] ;
return 0 ;
}
static int F_86 ( struct V_61 * V_107 )
{
struct V_1 * V_2 = F_27 ( V_107 ) ;
struct V_257 * V_258 = & V_2 -> V_258 ;
T_1 V_5 ;
int V_9 ;
V_258 -> V_259 = F_87 ( V_2 -> V_54 ) ;
if ( ! V_258 -> V_259 )
F_28 ( V_2 -> V_54 ) ;
for ( V_9 = 0 ; V_9 < F_71 ( V_260 ) ; V_9 ++ )
V_258 -> V_261 [ V_9 ] = F_7 ( V_2 , V_260 [ V_9 ] ) ;
if ( V_2 -> V_35 ) {
V_5 = V_2 -> V_18 + V_36 ;
V_258 -> V_262 [ 0 ] = F_7 ( V_2 , V_5 ) ;
}
if ( V_2 -> V_17 ) {
V_5 = V_2 -> V_18 + V_19 ;
V_258 -> V_262 [ 1 ] = F_7 ( V_2 , V_5 ) ;
}
for ( V_9 = 0 ; V_9 < V_2 -> V_137 ; V_9 ++ )
V_258 -> V_263 [ V_9 ] = F_7 ( V_2 ,
F_51 ( V_9 ) ) ;
F_88 ( V_2 -> V_54 ) ;
return 0 ;
}
static int F_89 ( struct V_61 * V_107 )
{
struct V_1 * V_2 = F_27 ( V_107 ) ;
struct V_257 * V_258 = & V_2 -> V_258 ;
T_1 V_5 ;
int V_9 ;
F_28 ( V_2 -> V_54 ) ;
for ( V_9 = 0 ; V_9 < F_71 ( V_260 ) ; V_9 ++ )
F_6 ( V_2 , V_260 [ V_9 ] , V_258 -> V_261 [ V_9 ] ) ;
if ( V_2 -> V_35 ) {
V_5 = V_2 -> V_18 + V_36 ;
F_6 ( V_2 , V_5 , V_258 -> V_262 [ 0 ] ) ;
}
if ( V_2 -> V_17 ) {
V_5 = V_2 -> V_18 + V_19 ;
F_6 ( V_2 , V_5 , V_258 -> V_262 [ 1 ] ) ;
}
for ( V_9 = 0 ; V_9 < V_2 -> V_137 ; V_9 ++ )
F_6 ( V_2 , F_51 ( V_9 ) ,
V_258 -> V_263 [ V_9 ] ) ;
if ( ! V_258 -> V_259 )
F_88 ( V_2 -> V_54 ) ;
return 0 ;
}
static int F_90 ( struct V_264 * V_265 )
{
struct V_266 * V_267 = V_265 -> V_54 . V_268 ;
struct V_269 * V_270 , * V_271 ;
const char * V_272 ;
int V_59 ;
if ( ! V_267 )
return 0 ;
V_272 = F_91 ( V_267 , L_19 , NULL ) ;
if ( ! V_272 )
return 0 ;
F_18 ( & V_265 -> V_54 , L_20 ) ;
V_270 = F_92 ( & V_265 -> V_54 , L_21 ) ;
if ( F_93 ( V_270 ) ) {
F_44 ( & V_265 -> V_54 , L_22 ) ;
return F_94 ( V_270 ) ;
}
V_271 = F_92 ( NULL , V_272 ) ;
if ( F_93 ( V_271 ) ) {
F_44 ( & V_265 -> V_54 , L_23 ) ;
V_59 = F_94 ( V_271 ) ;
goto V_273;
}
V_59 = F_95 ( V_270 , V_271 ) ;
if ( V_59 ) {
F_44 ( & V_265 -> V_54 , L_24 ) ;
goto V_274;
}
V_274:
F_96 ( V_271 ) ;
V_273:
F_96 ( V_270 ) ;
return V_59 ;
}
static struct V_275 * F_97 (
struct V_264 * V_265 )
{
struct V_266 * V_276 = V_265 -> V_54 . V_268 ;
struct V_275 * V_277 = NULL ;
const struct V_278 * V_279 =
F_98 ( V_280 , & V_265 -> V_54 ) ;
struct V_281 V_282 ;
const T_1 * V_283 ;
T_1 V_4 ;
int V_9 , V_59 = 0 ;
if ( V_265 -> V_54 . V_284 ) {
V_277 = V_265 -> V_54 . V_284 ;
return V_277 ;
} else if ( V_279 ) {
V_277 = (struct V_275 * ) V_279 -> V_47 ;
} else {
V_59 = - V_76 ;
goto V_285;
}
V_59 = F_99 ( V_276 , L_25 , & V_4 ) ;
if ( V_59 >= 0 )
V_277 -> V_146 = V_4 ;
V_59 = F_99 ( V_276 , L_26 , & V_4 ) ;
if ( V_59 >= 0 ) {
if ( V_4 < 2 || V_4 > 32 ) {
F_44 ( & V_265 -> V_54 ,
L_27 ) ;
V_59 = - V_76 ;
goto V_285;
}
V_277 -> V_118 = V_4 ;
}
V_283 = F_91 ( V_276 , L_28 , & V_4 ) ;
V_4 /= sizeof( T_1 ) ;
if ( V_283 ) {
T_4 * V_286 = F_100 ( & V_265 -> V_54 ,
( sizeof( * V_286 ) * V_4 ) ,
V_287 ) ;
if ( ! V_286 ) {
V_59 = - V_288 ;
goto V_285;
}
for ( V_9 = 0 ; V_9 < V_4 ; V_9 ++ )
V_286 [ V_9 ] = F_101 ( & V_283 [ V_9 ] ) ;
V_277 -> V_137 = V_4 ;
V_277 -> V_138 = V_286 ;
}
V_59 = F_102 ( V_276 , L_29 , L_30 ) ;
if ( V_59 < 0 )
goto V_285;
V_59 = F_103 ( V_276 , L_31 , L_32 , V_59 ,
& V_282 ) ;
if ( V_59 < 0 )
goto V_285;
V_277 -> V_289 = V_282 . args [ 0 ] ;
if ( V_277 -> V_146 != V_147 ) {
V_59 = F_102 ( V_276 , L_29 , L_33 ) ;
if ( V_59 < 0 )
goto V_285;
V_59 = F_103 ( V_276 , L_31 , L_32 , V_59 ,
& V_282 ) ;
if ( V_59 < 0 )
goto V_285;
V_277 -> V_290 = V_282 . args [ 0 ] ;
}
V_59 = F_99 ( V_276 , L_34 , & V_4 ) ;
if ( V_59 >= 0 )
V_277 -> V_35 = V_4 ;
V_59 = F_99 ( V_276 , L_35 , & V_4 ) ;
if ( V_59 >= 0 )
V_277 -> V_17 = V_4 ;
V_59 = F_99 ( V_276 , L_36 , & V_4 ) ;
if ( V_59 >= 0 )
V_277 -> V_291 = V_4 ;
V_59 = F_99 ( V_276 , L_37 , & V_4 ) ;
if ( V_59 >= 0 )
V_277 -> V_292 = V_4 ;
return V_277 ;
V_285:
if ( V_59 < 0 ) {
F_44 ( & V_265 -> V_54 , L_38 ,
V_59 ) ;
V_277 = NULL ;
}
return V_277 ;
}
static int F_104 ( struct V_1 * V_2 )
{
struct V_293 * V_294 ;
const char * V_295 ;
int V_59 = V_296 ;
if ( ! V_2 -> V_54 -> V_268 )
return V_296 ;
V_295 = V_2 -> V_153 [ V_42 ] . V_297 ;
V_294 = F_105 ( V_2 -> V_54 , V_295 ) ;
if ( F_93 ( V_294 ) ) {
if ( F_94 ( V_294 ) != - V_298 )
F_44 ( V_2 -> V_54 ,
L_39 ,
F_94 ( V_294 ) ) ;
return F_94 ( V_294 ) ;
}
F_106 ( ! V_294 -> V_299 || ! V_294 -> V_299 -> V_54 ) ;
if ( V_294 -> V_299 -> V_54 -> V_268 )
V_59 = F_107 ( V_294 -> V_299 -> V_54 -> V_268 ,
L_40 , & V_295 ) ;
else
F_43 ( V_2 -> V_54 , L_41 ) ;
F_108 ( V_294 ) ;
if ( V_59 )
return V_59 ;
F_43 ( V_2 -> V_54 , L_42 , V_295 ) ;
if ( ! strncmp ( V_295 , V_300 , strlen ( V_300 ) ) )
return V_301 ;
return V_296 ;
}
static int F_109 ( struct V_264 * V_265 )
{
struct V_152 * V_153 ;
struct V_302 * V_303 , * V_304 , * V_305 ;
struct V_275 * V_277 ;
struct V_1 * V_2 ;
char * V_306 ;
int * V_307 ;
int V_46 ;
int V_59 ;
if ( ! V_265 -> V_54 . V_284 && ! V_265 -> V_54 . V_268 ) {
F_44 ( & V_265 -> V_54 , L_43 ) ;
return - V_76 ;
}
V_2 = F_100 ( & V_265 -> V_54 , sizeof( struct V_1 ) ,
V_287 ) ;
if ( ! V_2 )
return - V_288 ;
V_277 = F_97 ( V_265 ) ;
if ( ! V_277 ) {
F_44 ( & V_265 -> V_54 , L_44 ) ;
return - V_76 ;
}
V_303 = F_110 ( V_265 , V_308 , L_45 ) ;
if ( ! V_303 ) {
F_18 ( V_2 -> V_54 ,
L_46 ) ;
V_303 = F_111 ( V_265 , V_308 , 0 ) ;
if ( ! V_303 ) {
F_44 ( & V_265 -> V_54 , L_47 ) ;
return - V_309 ;
}
}
V_2 -> V_6 = F_112 ( & V_265 -> V_54 , V_303 ) ;
if ( F_93 ( V_2 -> V_6 ) )
return F_94 ( V_2 -> V_6 ) ;
F_113 ( & V_265 -> V_54 ) ;
V_2 -> V_146 = V_277 -> V_146 ;
if ( V_2 -> V_146 == V_222 ) {
if ( V_277 -> V_118 < 2 ) {
F_44 ( & V_265 -> V_54 , L_48 ,
V_277 -> V_118 ) ;
V_2 -> V_118 = 2 ;
} else if ( V_277 -> V_118 > 32 ) {
F_44 ( & V_265 -> V_54 , L_48 ,
V_277 -> V_118 ) ;
V_2 -> V_118 = 32 ;
} else {
V_2 -> V_118 = V_277 -> V_118 ;
}
}
V_2 -> V_137 = V_277 -> V_137 ;
#ifdef F_114
V_2 -> V_258 . V_263 = F_100 ( & V_265 -> V_54 ,
sizeof( T_1 ) * V_2 -> V_137 ,
V_287 ) ;
#endif
V_2 -> V_138 = V_277 -> V_138 ;
V_2 -> V_159 = V_277 -> V_159 ;
V_2 -> V_35 = V_277 -> V_35 ;
V_2 -> V_17 = V_277 -> V_17 ;
V_2 -> V_54 = & V_265 -> V_54 ;
V_46 = F_115 ( V_265 , L_49 ) ;
if ( V_46 >= 0 ) {
V_306 = F_116 ( & V_265 -> V_54 , V_287 , L_50 ,
F_117 ( & V_265 -> V_54 ) ) ;
V_59 = F_118 ( & V_265 -> V_54 , V_46 , NULL ,
F_25 ,
V_310 | V_311 ,
V_306 , V_2 ) ;
if ( V_59 ) {
F_44 ( & V_265 -> V_54 , L_51 ) ;
goto V_312;
}
V_2 -> V_32 [ V_42 ] = V_53 ;
V_2 -> V_32 [ V_33 ] = V_58 ;
}
V_46 = F_115 ( V_265 , L_33 ) ;
if ( V_46 >= 0 ) {
V_306 = F_116 ( & V_265 -> V_54 , V_287 , L_52 ,
F_117 ( & V_265 -> V_54 ) ) ;
V_59 = F_118 ( & V_265 -> V_54 , V_46 , NULL ,
F_24 ,
V_310 , V_306 , V_2 ) ;
if ( V_59 ) {
F_44 ( & V_265 -> V_54 , L_53 ) ;
goto V_312;
}
V_2 -> V_32 [ V_33 ] = V_58 ;
}
V_46 = F_115 ( V_265 , L_30 ) ;
if ( V_46 >= 0 ) {
V_306 = F_116 ( & V_265 -> V_54 , V_287 , L_54 ,
F_117 ( & V_265 -> V_54 ) ) ;
V_59 = F_118 ( & V_265 -> V_54 , V_46 , NULL ,
F_17 ,
V_310 , V_306 , V_2 ) ;
if ( V_59 ) {
F_44 ( & V_265 -> V_54 , L_55 ) ;
goto V_312;
}
V_2 -> V_32 [ V_42 ] = V_53 ;
}
V_305 = F_110 ( V_265 , V_308 , L_56 ) ;
if ( V_305 )
V_2 -> V_178 = true ;
V_153 = & V_2 -> V_153 [ V_42 ] ;
if ( V_305 )
V_153 -> V_313 = V_305 -> V_314 ;
else
V_153 -> V_313 = V_303 -> V_314 + V_277 -> V_315 ;
V_307 = & V_2 -> V_316 [ V_42 ] ;
V_304 = F_111 ( V_265 , V_317 , 0 ) ;
if ( V_304 )
* V_307 = V_304 -> V_314 ;
else
* V_307 = V_277 -> V_289 ;
if ( V_265 -> V_54 . V_268 )
V_153 -> V_297 = L_30 ;
else
V_153 -> V_297 = V_307 ;
if ( V_2 -> V_146 != V_147 ) {
V_153 = & V_2 -> V_153 [ V_33 ] ;
if ( V_305 )
V_153 -> V_313 = V_305 -> V_314 ;
else
V_153 -> V_313 = V_303 -> V_314 + V_277 -> V_318 ;
V_307 = & V_2 -> V_316 [ V_33 ] ;
V_304 = F_111 ( V_265 , V_317 , 1 ) ;
if ( V_304 )
* V_307 = V_304 -> V_314 ;
else
* V_307 = V_277 -> V_290 ;
if ( V_265 -> V_54 . V_268 )
V_153 -> V_297 = L_33 ;
else
V_153 -> V_297 = V_307 ;
}
if ( V_2 -> V_159 < V_160 ) {
V_2 -> V_18 = V_319 ;
V_2 -> V_178 = true ;
} else {
V_2 -> V_18 = V_320 ;
}
V_2 -> V_130 [ V_42 ] . V_131 =
F_100 ( V_2 -> V_54 , sizeof( unsigned int ) *
( 32 + V_2 -> V_137 - 2 ) ,
V_287 ) ;
V_2 -> V_130 [ V_33 ] . V_131 =
F_100 ( V_2 -> V_54 , sizeof( unsigned int ) *
( 32 + V_2 -> V_137 - 2 ) ,
V_287 ) ;
if ( ! V_2 -> V_130 [ V_42 ] . V_131 ||
! V_2 -> V_130 [ V_33 ] . V_131 )
return - V_288 ;
V_59 = F_41 ( V_2 ) ;
if ( V_59 )
goto V_312;
F_119 ( & V_265 -> V_54 , V_2 ) ;
F_90 ( V_265 ) ;
V_59 = F_120 ( & V_265 -> V_54 ,
& V_321 ,
& V_322 [ V_277 -> V_146 ] , 1 ) ;
if ( V_59 != 0 )
goto V_312;
V_59 = F_104 ( V_2 ) ;
switch ( V_59 ) {
case V_296 :
#if F_121 ( V_323 ) || \
( F_122 ( V_324 ) && \
F_122 ( V_323 ) )
V_59 = F_123 ( & V_265 -> V_54 ) ;
#else
F_44 ( & V_265 -> V_54 , L_57 ) ;
V_59 = - V_76 ;
goto V_312;
#endif
break;
case V_301 :
#if F_121 ( V_325 ) || \
( F_122 ( V_324 ) && \
F_122 ( V_325 ) )
V_59 = F_124 ( & V_265 -> V_54 ) ;
#else
F_44 ( & V_265 -> V_54 , L_58 ) ;
V_59 = - V_76 ;
goto V_312;
#endif
break;
default:
F_44 ( & V_265 -> V_54 , L_59 , V_59 ) ;
case - V_298 :
goto V_312;
break;
}
if ( V_59 ) {
F_44 ( & V_265 -> V_54 , L_60 , V_59 ) ;
goto V_312;
}
return 0 ;
V_312:
F_125 ( & V_265 -> V_54 ) ;
return V_59 ;
}
static int F_126 ( struct V_264 * V_265 )
{
F_125 ( & V_265 -> V_54 ) ;
return 0 ;
}
