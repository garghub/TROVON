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
while ( ! ( F_7 ( V_2 , V_38 ) &
~ V_39 ) && ( V_34 < 100000 ) )
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
V_77:
F_31 ( V_2 -> V_54 ) ;
return V_59 ;
}
static int F_32 ( struct V_61 * V_106 , int V_107 ,
int div , bool V_108 )
{
struct V_1 * V_2 = F_27 ( V_106 ) ;
F_28 ( V_2 -> V_54 ) ;
switch ( V_107 ) {
case 0 :
F_5 ( V_2 , V_109 ,
F_33 ( div - 1 ) , V_110 ) ;
F_5 ( V_2 , V_111 ,
F_34 ( div - 1 ) , V_112 ) ;
break;
case 1 :
F_5 ( V_2 , V_14 ,
F_35 ( div - 1 ) , V_113 ) ;
F_5 ( V_2 , V_84 ,
F_36 ( div - 1 ) , V_114 ) ;
if ( V_108 )
V_2 -> V_115 = div ;
break;
case 2 :
V_2 -> V_116 = div ;
break;
default:
return - V_76 ;
}
F_31 ( V_2 -> V_54 ) ;
return 0 ;
}
static int F_37 ( struct V_61 * V_106 , int V_107 ,
int div )
{
return F_32 ( V_106 , V_107 , div , 1 ) ;
}
static int F_38 ( struct V_61 * V_106 , int V_117 ,
unsigned int V_118 , int V_119 )
{
struct V_1 * V_2 = F_27 ( V_106 ) ;
F_28 ( V_2 -> V_54 ) ;
if ( V_119 == V_120 ) {
F_1 ( V_2 , V_109 , V_121 ) ;
F_1 ( V_2 , V_111 , V_122 ) ;
F_1 ( V_2 , V_86 , V_95 ) ;
} else {
F_4 ( V_2 , V_109 , V_121 ) ;
F_4 ( V_2 , V_111 , V_122 ) ;
F_4 ( V_2 , V_86 , V_95 ) ;
}
V_2 -> V_123 = V_118 ;
F_31 ( V_2 -> V_54 ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 ,
int V_124 )
{
T_1 V_63 ;
T_1 V_125 = ( V_124 / 4 ) & 0x7 ;
T_1 V_7 = ( 1ULL << V_124 ) - 1 ;
T_1 V_126 = 0 ;
if ( V_2 -> V_116 ) {
T_1 V_127 = V_2 -> V_116 / V_2 -> V_128 ;
V_126 = ( V_127 - V_124 ) / 4 ;
V_124 = V_127 ;
}
V_63 = ( V_124 >> 1 ) - 1 ;
if ( V_2 -> V_129 != V_130 ) {
F_5 ( V_2 , V_79 , F_40 ( V_63 ) ,
F_40 ( 0x0F ) ) ;
F_5 ( V_2 , V_78 , F_41 ( V_63 ) ,
F_41 ( 0x0F ) ) ;
F_5 ( V_2 , V_78 , F_42 ( V_125 ) ,
F_42 ( 7 ) ) ;
F_5 ( V_2 , V_79 , F_43 ( V_126 ) ,
F_43 ( 7 ) ) ;
F_6 ( V_2 , V_131 , V_7 ) ;
}
F_6 ( V_2 , V_132 , V_7 ) ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 , int V_43 ,
int V_133 , int V_134 )
{
struct V_135 * V_136 = & V_2 -> V_136 [ V_43 ] ;
int V_9 ;
T_4 V_137 = 0 ;
T_4 V_138 = 0 ;
T_4 V_139 = V_2 -> V_128 ;
T_4 V_140 = ( V_134 + V_139 - 1 ) / V_139 ;
int V_141 , V_142 , V_143 ;
T_1 V_5 ;
if ( V_2 -> V_144 < V_145 )
F_1 ( V_2 , V_146 , V_147 ) ;
F_6 ( V_2 , V_148 , 0x00000000 ) ;
if ( V_43 == V_42 ) {
F_6 ( V_2 , V_38 , 0xFFFFFFFF ) ;
F_4 ( V_2 , V_149 , V_150 ) ;
} else {
F_6 ( V_2 , V_45 , 0xFFFFFFFF ) ;
F_4 ( V_2 , V_151 , V_152 ) ;
}
for ( V_9 = 0 ; V_9 < V_2 -> V_153 ; V_9 ++ ) {
F_1 ( V_2 , F_45 ( V_9 ) ,
V_2 -> V_154 [ V_9 ] ) ;
if ( V_2 -> V_154 [ V_9 ] == V_155 &&
V_137 < V_140 ) {
F_1 ( V_2 , V_86 , F_46 ( V_9 ) ) ;
V_137 ++ ;
} else if ( V_2 -> V_154 [ V_9 ] == V_156 &&
V_138 < V_140 ) {
F_4 ( V_2 , V_86 , F_46 ( V_9 ) ) ;
V_138 ++ ;
} else {
F_5 ( V_2 , F_45 ( V_9 ) ,
V_157 , V_158 ) ;
}
}
if ( V_43 == V_42 ) {
V_141 = V_137 ;
V_142 = V_2 -> V_35 ;
V_5 = V_2 -> V_18 + V_36 ;
} else {
V_141 = V_138 ;
V_142 = V_2 -> V_17 ;
V_5 = V_2 -> V_18 + V_19 ;
}
if ( V_141 < V_140 ) {
F_18 ( V_2 -> V_54 , L_6
L_7 , V_134 ,
V_141 * V_139 ) ;
return - V_76 ;
}
if ( ! V_142 ) {
if ( V_141 > 1 ) {
V_136 -> V_159 = V_141 ;
} else {
V_136 -> V_159 = 0 ;
}
return 0 ;
}
if ( V_133 % V_141 ) {
F_47 ( V_2 -> V_54 , L_8
L_9 , V_133 ,
V_141 ) ;
return - V_76 ;
}
V_143 = V_142 % V_141 ;
if ( V_143 )
V_142 += ( V_141 - V_143 ) ;
while ( V_133 % V_142 && V_142 > 0 )
V_142 -= V_141 ;
if ( V_142 <= 0 )
V_142 = V_141 ;
F_5 ( V_2 , V_5 , V_141 , V_160 ) ;
F_5 ( V_2 , V_5 , F_48 ( V_142 ) , V_161 ) ;
if ( V_142 == 1 )
V_142 = 0 ;
V_136 -> V_159 = V_142 ;
return 0 ;
}
static int F_49 ( struct V_1 * V_2 , int V_43 ,
int V_134 )
{
int V_9 , V_162 ;
int V_163 ;
int V_141 ;
T_1 V_7 = 0 ;
T_1 V_164 = 0 ;
V_163 = V_2 -> V_128 ;
V_141 = ( V_134 + V_163 - 1 ) / V_163 ;
if ( V_141 == 1 )
V_162 = V_134 ;
else
V_162 = V_163 ;
for ( V_9 = 0 ; V_9 < V_162 ; V_9 ++ )
V_7 |= ( 1 << V_9 ) ;
F_4 ( V_2 , V_14 , V_15 ) ;
if ( ! V_2 -> V_165 )
V_164 = V_166 ;
F_6 ( V_2 , V_167 , V_7 ) ;
F_1 ( V_2 , V_78 , V_164 | V_168 ) ;
F_5 ( V_2 , V_69 ,
F_50 ( V_163 ) , F_50 ( 0x1FF ) ) ;
F_6 ( V_2 , V_169 , V_7 ) ;
F_1 ( V_2 , V_79 , V_164 | V_170 ) ;
F_5 ( V_2 , V_12 ,
F_51 ( V_163 ) , F_51 ( 0x1FF ) ) ;
return 0 ;
}
static int F_52 ( struct V_1 * V_2 ,
unsigned int V_171 )
{
T_1 V_172 = 0 ;
T_4 * V_173 = ( T_4 * ) & V_172 ;
F_1 ( V_2 , V_78 , F_42 ( 6 ) | F_41 ( 15 ) ) ;
F_6 ( V_2 , V_69 , V_83 | F_50 ( 0x180 ) ) ;
F_6 ( V_2 , V_167 , 0xFFFFFFFF ) ;
F_1 ( V_2 , V_14 , V_82 | V_15 ) ;
F_4 ( V_2 , V_149 , V_150 ) ;
F_1 ( V_2 , V_109 , F_33 ( 3 ) ) ;
F_1 ( V_2 , V_174 , V_175 ) ;
V_173 [ 0 ] = V_176 ;
V_173 [ 1 ] = V_177 ;
switch ( V_171 ) {
case 22050 :
V_173 [ 3 ] |= V_178 ;
break;
case 24000 :
V_173 [ 3 ] |= V_179 ;
break;
case 32000 :
V_173 [ 3 ] |= V_180 ;
break;
case 44100 :
V_173 [ 3 ] |= V_181 ;
break;
case 48000 :
V_173 [ 3 ] |= V_182 ;
break;
case 88200 :
V_173 [ 3 ] |= V_183 ;
break;
case 96000 :
V_173 [ 3 ] |= V_184 ;
break;
case 176400 :
V_173 [ 3 ] |= V_185 ;
break;
case 192000 :
V_173 [ 3 ] |= V_186 ;
break;
default:
F_9 ( V_187 L_10 , V_171 ) ;
return - V_76 ;
}
F_6 ( V_2 , V_188 , V_172 ) ;
F_6 ( V_2 , V_189 , V_172 ) ;
return 0 ;
}
static int F_53 ( struct V_1 * V_2 ,
unsigned int V_190 ,
int * V_191 )
{
int div = V_2 -> V_123 / V_190 ;
int V_192 = V_2 -> V_123 % V_190 ;
if ( V_192 != 0 ) {
if ( div == 0 ||
( ( V_2 -> V_123 / div ) - V_190 ) >
( V_190 - ( V_2 -> V_123 / ( div + 1 ) ) ) ) {
div ++ ;
V_192 = V_192 - V_190 ;
}
}
if ( V_191 )
* V_191 =
( div * 1000000 + ( int ) F_54 ( 1000000LL * V_192 ,
( int ) V_190 ) )
/ div - 1000000 ;
return div ;
}
static int F_55 ( struct V_48 * V_49 ,
struct V_193 * V_194 ,
struct V_61 * V_62 )
{
struct V_1 * V_2 = F_27 ( V_62 ) ;
int V_124 ;
int V_134 = F_56 ( V_194 ) ;
int V_195 = F_57 ( V_194 ) ;
int V_59 ;
if ( V_2 -> V_91 && V_2 -> V_115 == 0 && V_2 -> V_123 ) {
int V_134 = F_56 ( V_194 ) ;
int V_171 = F_58 ( V_194 ) ;
int V_196 = F_59 ( V_194 ) ;
int V_197 , div ;
if ( V_134 > V_2 -> V_128 )
V_134 = V_2 -> V_128 ;
div = F_53 ( V_2 , V_171 * V_196 * V_134 ,
& V_197 ) ;
if ( V_197 )
F_60 ( V_2 -> V_54 , L_11 ,
V_197 ) ;
F_32 ( V_62 , 1 , div , 0 ) ;
}
V_59 = F_44 ( V_2 , V_49 -> V_43 ,
V_195 * V_134 , V_134 ) ;
if ( V_59 )
return V_59 ;
if ( V_2 -> V_129 == V_130 )
V_59 = F_52 ( V_2 , F_58 ( V_194 ) ) ;
else
V_59 = F_49 ( V_2 , V_49 -> V_43 ,
V_134 ) ;
if ( V_59 )
return V_59 ;
switch ( F_61 ( V_194 ) ) {
case V_198 :
case V_199 :
V_124 = 8 ;
break;
case V_200 :
case V_201 :
V_124 = 16 ;
break;
case V_202 :
case V_203 :
V_124 = 24 ;
break;
case V_204 :
case V_205 :
V_124 = 24 ;
break;
case V_206 :
case V_207 :
V_124 = 32 ;
break;
default:
F_9 ( V_187 L_12 ) ;
return - V_76 ;
}
F_39 ( V_2 , V_124 ) ;
if ( V_2 -> V_129 == V_208 )
V_2 -> V_134 = V_134 ;
return 0 ;
}
static int F_62 ( struct V_48 * V_49 ,
int V_209 , struct V_61 * V_62 )
{
struct V_1 * V_2 = F_27 ( V_62 ) ;
int V_59 = 0 ;
switch ( V_209 ) {
case V_210 :
case V_211 :
case V_212 :
F_13 ( V_2 , V_49 -> V_43 ) ;
break;
case V_213 :
case V_214 :
case V_215 :
F_16 ( V_2 , V_49 -> V_43 ) ;
break;
default:
V_59 = - V_76 ;
}
return V_59 ;
}
static int F_63 ( struct V_193 * V_194 ,
struct V_216 * V_217 )
{
struct V_218 * V_219 = V_217 -> V_220 ;
struct V_221 * V_222 =
F_64 ( V_194 , V_223 ) ;
int V_196 = F_59 ( V_194 ) ;
int V_134 = F_56 ( V_194 ) ;
unsigned int V_224 [ F_65 ( V_225 ) ] ;
int V_9 , V_226 = 0 ;
if ( V_134 > V_219 -> V_2 -> V_128 )
V_134 = V_219 -> V_2 -> V_128 ;
for ( V_9 = 0 ; V_9 < F_65 ( V_225 ) ; V_9 ++ ) {
if ( V_222 -> V_227 <= V_225 [ V_9 ] &&
V_222 -> V_228 >= V_225 [ V_9 ] ) {
T_5 V_190 = V_196 * V_134 *
V_225 [ V_9 ] ;
int V_197 ;
F_53 ( V_219 -> V_2 , V_190 , & V_197 ) ;
if ( abs ( V_197 ) < V_229 )
V_224 [ V_226 ++ ] = V_225 [ V_9 ] ;
}
}
F_66 ( V_219 -> V_2 -> V_54 ,
L_13 ,
V_226 , V_222 -> V_227 , V_222 -> V_228 , V_196 , V_134 ) ;
return F_67 ( F_64 ( V_194 , V_217 -> V_230 ) ,
V_226 , V_224 , 0 ) ;
}
static int F_68 ( struct V_193 * V_194 ,
struct V_216 * V_217 )
{
struct V_218 * V_219 = V_217 -> V_220 ;
struct V_231 * V_63 = F_69 ( V_194 , V_232 ) ;
struct V_231 V_233 ;
int V_171 = F_58 ( V_194 ) ;
int V_134 = F_56 ( V_194 ) ;
int V_9 , V_226 = 0 ;
F_70 ( & V_233 ) ;
if ( V_134 > V_219 -> V_2 -> V_128 )
V_134 = V_219 -> V_2 -> V_128 ;
for ( V_9 = 0 ; V_9 < V_234 ; V_9 ++ ) {
if ( F_71 ( V_63 , V_9 ) ) {
T_5 V_190 = F_72 ( V_9 ) * V_134 * V_171 ;
int V_197 ;
F_53 ( V_219 -> V_2 , V_190 , & V_197 ) ;
if ( abs ( V_197 ) < V_229 ) {
F_73 ( & V_233 , V_9 ) ;
V_226 ++ ;
}
}
}
F_66 ( V_219 -> V_2 -> V_54 ,
L_14 ,
V_226 , V_171 , V_134 ) ;
return F_74 ( V_63 , & V_233 ) ;
}
static int F_75 ( struct V_193 * V_194 ,
struct V_216 * V_217 )
{
struct V_218 * V_219 = V_217 -> V_220 ;
struct V_221 * V_235 =
F_64 ( V_194 , V_236 ) ;
int V_196 = F_59 ( V_194 ) ;
int V_171 = F_58 ( V_194 ) ;
int V_237 = V_219 -> V_2 -> V_128 < V_235 -> V_228 ?
V_219 -> V_2 -> V_128 : V_235 -> V_228 ;
unsigned int V_224 [ V_235 -> V_228 - V_235 -> V_227 + 1 ] ;
int V_238 , V_239 , V_226 = 0 ;
for ( V_238 = V_235 -> V_227 ; V_238 <= V_237 ; V_238 ++ ) {
T_5 V_190 = V_238 * V_196 * V_171 ;
int V_197 ;
F_53 ( V_219 -> V_2 , V_190 , & V_197 ) ;
if ( abs ( V_197 ) < V_229 ) {
if ( V_238 == V_219 -> V_2 -> V_128 ) {
for ( V_239 = V_238 ; V_239 <= V_219 -> V_240 * V_238 &&
V_239 <= V_235 -> V_228 ; V_239 ++ )
V_224 [ V_226 ++ ] = V_239 ;
} else {
V_224 [ V_226 ++ ] = V_238 ;
}
}
}
F_66 ( V_219 -> V_2 -> V_54 ,
L_15 ,
V_226 , V_235 -> V_227 , V_235 -> V_228 , V_171 , V_196 ) ;
return F_67 ( F_64 ( V_194 , V_217 -> V_230 ) ,
V_226 , V_224 , 0 ) ;
}
static int F_76 ( struct V_48 * V_49 ,
struct V_61 * V_62 )
{
struct V_1 * V_2 = F_27 ( V_62 ) ;
struct V_218 * V_241 =
& V_2 -> V_241 [ V_49 -> V_43 ] ;
T_1 V_242 = 0 ;
int V_9 , V_119 ;
V_2 -> V_55 [ V_49 -> V_43 ] = V_49 ;
if ( V_2 -> V_129 == V_130 )
return 0 ;
if ( V_49 -> V_43 == V_42 )
V_119 = V_155 ;
else
V_119 = V_156 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_153 ; V_9 ++ ) {
if ( V_2 -> V_154 [ V_9 ] == V_119 )
V_242 ++ ;
}
V_241 -> V_240 = V_242 ;
V_242 *= V_2 -> V_128 ;
if ( V_2 -> V_134 && V_2 -> V_134 < V_242 )
V_242 = V_2 -> V_134 ;
F_77 ( V_49 -> V_243 ,
V_236 ,
2 , V_242 ) ;
if ( V_2 -> V_91 && V_2 -> V_115 == 0 && V_2 -> V_123 ) {
int V_59 ;
V_241 -> V_2 = V_2 ;
V_59 = F_78 ( V_49 -> V_243 , 0 ,
V_223 ,
F_63 ,
V_241 ,
V_232 ,
V_236 , - 1 ) ;
if ( V_59 )
return V_59 ;
V_59 = F_78 ( V_49 -> V_243 , 0 ,
V_232 ,
F_68 ,
V_241 ,
V_223 ,
V_236 , - 1 ) ;
if ( V_59 )
return V_59 ;
V_59 = F_78 ( V_49 -> V_243 , 0 ,
V_236 ,
F_75 ,
V_241 ,
V_223 ,
V_232 , - 1 ) ;
if ( V_59 )
return V_59 ;
}
return 0 ;
}
static void F_79 ( struct V_48 * V_49 ,
struct V_61 * V_62 )
{
struct V_1 * V_2 = F_27 ( V_62 ) ;
V_2 -> V_55 [ V_49 -> V_43 ] = NULL ;
if ( V_2 -> V_129 == V_130 )
return;
if ( ! V_62 -> V_244 )
V_2 -> V_134 = 0 ;
}
static int F_80 ( struct V_61 * V_106 )
{
struct V_1 * V_2 = F_27 ( V_106 ) ;
V_106 -> V_245 = & V_2 -> V_136 [ V_42 ] ;
V_106 -> V_246 = & V_2 -> V_136 [ V_33 ] ;
return 0 ;
}
static int F_81 ( struct V_61 * V_106 )
{
struct V_1 * V_2 = F_27 ( V_106 ) ;
struct V_247 * V_248 = & V_2 -> V_248 ;
T_1 V_5 ;
int V_9 ;
V_248 -> V_249 = F_82 ( V_2 -> V_54 ) ;
if ( ! V_248 -> V_249 )
F_28 ( V_2 -> V_54 ) ;
for ( V_9 = 0 ; V_9 < F_65 ( V_250 ) ; V_9 ++ )
V_248 -> V_251 [ V_9 ] = F_7 ( V_2 , V_250 [ V_9 ] ) ;
if ( V_2 -> V_35 ) {
V_5 = V_2 -> V_18 + V_36 ;
V_248 -> V_252 [ 0 ] = F_7 ( V_2 , V_5 ) ;
}
if ( V_2 -> V_17 ) {
V_5 = V_2 -> V_18 + V_19 ;
V_248 -> V_252 [ 1 ] = F_7 ( V_2 , V_5 ) ;
}
for ( V_9 = 0 ; V_9 < V_2 -> V_153 ; V_9 ++ )
V_248 -> V_253 [ V_9 ] = F_7 ( V_2 ,
F_45 ( V_9 ) ) ;
F_83 ( V_2 -> V_54 ) ;
return 0 ;
}
static int F_84 ( struct V_61 * V_106 )
{
struct V_1 * V_2 = F_27 ( V_106 ) ;
struct V_247 * V_248 = & V_2 -> V_248 ;
T_1 V_5 ;
int V_9 ;
F_28 ( V_2 -> V_54 ) ;
for ( V_9 = 0 ; V_9 < F_65 ( V_250 ) ; V_9 ++ )
F_6 ( V_2 , V_250 [ V_9 ] , V_248 -> V_251 [ V_9 ] ) ;
if ( V_2 -> V_35 ) {
V_5 = V_2 -> V_18 + V_36 ;
F_6 ( V_2 , V_5 , V_248 -> V_252 [ 0 ] ) ;
}
if ( V_2 -> V_17 ) {
V_5 = V_2 -> V_18 + V_19 ;
F_6 ( V_2 , V_5 , V_248 -> V_252 [ 1 ] ) ;
}
for ( V_9 = 0 ; V_9 < V_2 -> V_153 ; V_9 ++ )
F_6 ( V_2 , F_45 ( V_9 ) ,
V_248 -> V_253 [ V_9 ] ) ;
if ( ! V_248 -> V_249 )
F_83 ( V_2 -> V_54 ) ;
return 0 ;
}
static int F_85 ( struct V_254 * V_255 )
{
struct V_256 * V_257 = V_255 -> V_54 . V_258 ;
struct V_259 * V_260 , * V_261 ;
const char * V_262 ;
int V_59 ;
if ( ! V_257 )
return 0 ;
V_262 = F_86 ( V_257 , L_16 , NULL ) ;
if ( ! V_262 )
return 0 ;
V_260 = F_87 ( & V_255 -> V_54 , L_17 ) ;
if ( F_88 ( V_260 ) ) {
F_47 ( & V_255 -> V_54 , L_18 ) ;
return F_89 ( V_260 ) ;
}
V_261 = F_87 ( NULL , V_262 ) ;
if ( F_88 ( V_261 ) ) {
F_47 ( & V_255 -> V_54 , L_19 ) ;
V_59 = F_89 ( V_261 ) ;
goto V_263;
}
V_59 = F_90 ( V_260 , V_261 ) ;
if ( V_59 ) {
F_47 ( & V_255 -> V_54 , L_20 ) ;
goto V_264;
}
V_264:
F_91 ( V_261 ) ;
V_263:
F_91 ( V_260 ) ;
return V_59 ;
}
static struct V_265 * F_92 (
struct V_254 * V_255 )
{
struct V_256 * V_266 = V_255 -> V_54 . V_258 ;
struct V_265 * V_267 = NULL ;
const struct V_268 * V_269 =
F_93 ( V_270 , & V_255 -> V_54 ) ;
struct V_271 V_272 ;
const T_1 * V_273 ;
T_1 V_4 ;
int V_9 , V_59 = 0 ;
if ( V_255 -> V_54 . V_274 ) {
V_267 = V_255 -> V_54 . V_274 ;
return V_267 ;
} else if ( V_269 ) {
V_267 = (struct V_265 * ) V_269 -> V_47 ;
} else {
V_59 = - V_76 ;
goto V_275;
}
V_59 = F_94 ( V_266 , L_21 , & V_4 ) ;
if ( V_59 >= 0 )
V_267 -> V_129 = V_4 ;
V_59 = F_94 ( V_266 , L_22 , & V_4 ) ;
if ( V_59 >= 0 ) {
if ( V_4 < 2 || V_4 > 32 ) {
F_47 ( & V_255 -> V_54 ,
L_23 ) ;
V_59 = - V_76 ;
goto V_275;
}
V_267 -> V_128 = V_4 ;
}
V_273 = F_86 ( V_266 , L_24 , & V_4 ) ;
V_4 /= sizeof( T_1 ) ;
if ( V_273 ) {
T_4 * V_276 = F_95 ( & V_255 -> V_54 ,
( sizeof( * V_276 ) * V_4 ) ,
V_277 ) ;
if ( ! V_276 ) {
V_59 = - V_278 ;
goto V_275;
}
for ( V_9 = 0 ; V_9 < V_4 ; V_9 ++ )
V_276 [ V_9 ] = F_96 ( & V_273 [ V_9 ] ) ;
V_267 -> V_153 = V_4 ;
V_267 -> V_154 = V_276 ;
}
V_59 = F_97 ( V_266 , L_25 , L_26 ) ;
if ( V_59 < 0 )
goto V_275;
V_59 = F_98 ( V_266 , L_27 , L_28 , V_59 ,
& V_272 ) ;
if ( V_59 < 0 )
goto V_275;
V_267 -> V_279 = V_272 . args [ 0 ] ;
if ( V_267 -> V_129 != V_130 ) {
V_59 = F_97 ( V_266 , L_25 , L_29 ) ;
if ( V_59 < 0 )
goto V_275;
V_59 = F_98 ( V_266 , L_27 , L_28 , V_59 ,
& V_272 ) ;
if ( V_59 < 0 )
goto V_275;
V_267 -> V_280 = V_272 . args [ 0 ] ;
}
V_59 = F_94 ( V_266 , L_30 , & V_4 ) ;
if ( V_59 >= 0 )
V_267 -> V_35 = V_4 ;
V_59 = F_94 ( V_266 , L_31 , & V_4 ) ;
if ( V_59 >= 0 )
V_267 -> V_17 = V_4 ;
V_59 = F_94 ( V_266 , L_32 , & V_4 ) ;
if ( V_59 >= 0 )
V_267 -> V_281 = V_4 ;
V_59 = F_94 ( V_266 , L_33 , & V_4 ) ;
if ( V_59 >= 0 )
V_267 -> V_282 = V_4 ;
return V_267 ;
V_275:
if ( V_59 < 0 ) {
F_47 ( & V_255 -> V_54 , L_34 ,
V_59 ) ;
V_267 = NULL ;
}
return V_267 ;
}
static int F_99 ( struct V_254 * V_255 )
{
struct V_135 * V_136 ;
struct V_283 * V_284 , * V_285 , * V_286 , * V_287 ;
struct V_265 * V_267 ;
struct V_1 * V_2 ;
char * V_288 ;
int * V_289 ;
int V_46 ;
int V_59 ;
if ( ! V_255 -> V_54 . V_274 && ! V_255 -> V_54 . V_258 ) {
F_47 ( & V_255 -> V_54 , L_35 ) ;
return - V_76 ;
}
V_2 = F_95 ( & V_255 -> V_54 , sizeof( struct V_1 ) ,
V_277 ) ;
if ( ! V_2 )
return - V_278 ;
V_267 = F_92 ( V_255 ) ;
if ( ! V_267 ) {
F_47 ( & V_255 -> V_54 , L_36 ) ;
return - V_76 ;
}
V_284 = F_100 ( V_255 , V_290 , L_37 ) ;
if ( ! V_284 ) {
F_18 ( V_2 -> V_54 ,
L_38 ) ;
V_284 = F_101 ( V_255 , V_290 , 0 ) ;
if ( ! V_284 ) {
F_47 ( & V_255 -> V_54 , L_39 ) ;
return - V_291 ;
}
}
V_285 = F_102 ( & V_255 -> V_54 , V_284 -> V_292 ,
F_103 ( V_284 ) , V_255 -> V_293 ) ;
if ( ! V_285 ) {
F_47 ( & V_255 -> V_54 , L_40 ) ;
return - V_294 ;
}
F_104 ( & V_255 -> V_54 ) ;
V_2 -> V_6 = F_105 ( & V_255 -> V_54 , V_284 -> V_292 , F_103 ( V_284 ) ) ;
if ( ! V_2 -> V_6 ) {
F_47 ( & V_255 -> V_54 , L_41 ) ;
V_59 = - V_278 ;
goto V_295;
}
V_2 -> V_129 = V_267 -> V_129 ;
if ( V_2 -> V_129 == V_208 ) {
if ( V_267 -> V_128 < 2 ) {
F_47 ( & V_255 -> V_54 , L_42 ,
V_267 -> V_128 ) ;
V_2 -> V_128 = 2 ;
} else if ( V_267 -> V_128 > 32 ) {
F_47 ( & V_255 -> V_54 , L_42 ,
V_267 -> V_128 ) ;
V_2 -> V_128 = 32 ;
} else {
V_2 -> V_128 = V_267 -> V_128 ;
}
}
V_2 -> V_153 = V_267 -> V_153 ;
#ifdef F_106
V_2 -> V_248 . V_253 = F_95 ( & V_255 -> V_54 ,
sizeof( T_1 ) * V_2 -> V_153 ,
V_277 ) ;
#endif
V_2 -> V_154 = V_267 -> V_154 ;
V_2 -> V_144 = V_267 -> V_144 ;
V_2 -> V_35 = V_267 -> V_35 ;
V_2 -> V_17 = V_267 -> V_17 ;
V_2 -> V_54 = & V_255 -> V_54 ;
V_46 = F_107 ( V_255 , L_43 ) ;
if ( V_46 >= 0 ) {
V_288 = F_108 ( & V_255 -> V_54 , V_277 , L_44 ,
F_109 ( & V_255 -> V_54 ) ) ;
V_59 = F_110 ( & V_255 -> V_54 , V_46 , NULL ,
F_25 ,
V_296 | V_297 ,
V_288 , V_2 ) ;
if ( V_59 ) {
F_47 ( & V_255 -> V_54 , L_45 ) ;
goto V_295;
}
V_2 -> V_32 [ V_42 ] = V_53 ;
V_2 -> V_32 [ V_33 ] = V_58 ;
}
V_46 = F_107 ( V_255 , L_29 ) ;
if ( V_46 >= 0 ) {
V_288 = F_108 ( & V_255 -> V_54 , V_277 , L_46 ,
F_109 ( & V_255 -> V_54 ) ) ;
V_59 = F_110 ( & V_255 -> V_54 , V_46 , NULL ,
F_24 ,
V_296 , V_288 , V_2 ) ;
if ( V_59 ) {
F_47 ( & V_255 -> V_54 , L_47 ) ;
goto V_295;
}
V_2 -> V_32 [ V_33 ] = V_58 ;
}
V_46 = F_107 ( V_255 , L_26 ) ;
if ( V_46 >= 0 ) {
V_288 = F_108 ( & V_255 -> V_54 , V_277 , L_48 ,
F_109 ( & V_255 -> V_54 ) ) ;
V_59 = F_110 ( & V_255 -> V_54 , V_46 , NULL ,
F_17 ,
V_296 , V_288 , V_2 ) ;
if ( V_59 ) {
F_47 ( & V_255 -> V_54 , L_49 ) ;
goto V_295;
}
V_2 -> V_32 [ V_42 ] = V_53 ;
}
V_287 = F_100 ( V_255 , V_290 , L_50 ) ;
if ( V_287 )
V_2 -> V_165 = true ;
V_136 = & V_2 -> V_136 [ V_42 ] ;
if ( V_287 )
V_136 -> V_298 = V_287 -> V_292 ;
else
V_136 -> V_298 = V_284 -> V_292 + V_267 -> V_299 ;
V_289 = & V_2 -> V_300 [ V_42 ] ;
V_286 = F_101 ( V_255 , V_301 , 0 ) ;
if ( V_286 )
* V_289 = V_286 -> V_292 ;
else
* V_289 = V_267 -> V_279 ;
if ( V_255 -> V_54 . V_258 )
V_136 -> V_302 = L_26 ;
else
V_136 -> V_302 = V_289 ;
if ( V_2 -> V_129 != V_130 ) {
V_136 = & V_2 -> V_136 [ V_33 ] ;
if ( V_287 )
V_136 -> V_298 = V_287 -> V_292 ;
else
V_136 -> V_298 = V_284 -> V_292 + V_267 -> V_303 ;
V_289 = & V_2 -> V_300 [ V_33 ] ;
V_286 = F_101 ( V_255 , V_301 , 1 ) ;
if ( V_286 )
* V_289 = V_286 -> V_292 ;
else
* V_289 = V_267 -> V_280 ;
if ( V_255 -> V_54 . V_258 )
V_136 -> V_302 = L_29 ;
else
V_136 -> V_302 = V_289 ;
}
if ( V_2 -> V_144 < V_145 ) {
V_2 -> V_18 = V_304 ;
V_2 -> V_165 = true ;
} else {
V_2 -> V_18 = V_305 ;
}
F_111 ( & V_255 -> V_54 , V_2 ) ;
F_85 ( V_255 ) ;
V_59 = F_112 ( & V_255 -> V_54 ,
& V_306 ,
& V_307 [ V_267 -> V_129 ] , 1 ) ;
if ( V_59 != 0 )
goto V_295;
switch ( V_2 -> V_144 ) {
#if F_113 ( V_308 ) || \
( F_114 ( V_309 ) && \
F_114 ( V_308 ) )
case V_310 :
case V_311 :
case V_145 :
V_59 = F_115 ( & V_255 -> V_54 ) ;
break;
#endif
#if F_113 ( V_312 ) || \
( F_114 ( V_309 ) && \
F_114 ( V_312 ) )
case V_313 :
V_59 = F_116 ( & V_255 -> V_54 ) ;
break;
#endif
default:
F_47 ( & V_255 -> V_54 , L_51 ,
V_2 -> V_144 ) ;
V_59 = - V_76 ;
break;
}
if ( V_59 ) {
F_47 ( & V_255 -> V_54 , L_52 , V_59 ) ;
goto V_295;
}
return 0 ;
V_295:
F_117 ( & V_255 -> V_54 ) ;
return V_59 ;
}
static int F_118 ( struct V_254 * V_255 )
{
F_117 ( & V_255 -> V_54 ) ;
return 0 ;
}
