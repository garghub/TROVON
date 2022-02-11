static int F_1 ( struct V_1 * V_2 , struct V_3 * * V_4 ,
T_1 V_5 , const T_2 * V_6 )
{
struct V_3 * V_7 ;
T_3 * V_8 , V_9 , * V_10 ;
int V_11 ;
if ( V_5 < V_12 + 1 ) {
F_2 ( V_2 , L_1 , V_5 ) ;
return - V_13 ;
}
V_11 = memcmp ( V_6 , V_14 , V_12 * sizeof( T_3 ) ) ;
if ( V_11 != 0 ) {
F_2 ( V_2 , L_2 ) ;
return - V_13 ;
}
V_6 += V_12 ;
V_5 -= V_12 ;
V_8 = F_3 ( V_2 , V_5 * sizeof( T_3 ) , V_15 ) ;
if ( ! V_8 )
return - V_16 ;
for ( V_9 = 0 ; V_9 < V_5 ; ++ V_9 )
V_8 [ V_9 ] = F_4 ( V_6 [ V_9 ] ) ;
V_7 = (struct V_3 * ) V_8 ;
if ( V_5 < 1 + 2 * V_7 -> V_5 ) {
F_2 ( V_2 , L_3 ,
V_7 -> V_5 , 2 * ( V_5 + V_12 ) ) ;
return - V_13 ;
}
V_10 = V_8 + V_5 ;
V_8 += 1 + 2 * V_7 -> V_5 ;
for ( V_9 = 0 ; V_9 < V_7 -> V_5 ; ++ V_9 ) {
if ( V_7 -> V_17 [ V_9 ] . V_18 + V_8 <= V_10 )
continue;
F_2 ( V_2 , L_4 , V_9 ) ;
return - V_13 ;
}
* V_4 = V_7 ;
return 0 ;
}
static inline struct V_19 * F_5 ( struct V_20 * V_21 )
{
return & F_6 ( V_21 -> V_22 , struct V_23 , V_24 . V_22 ) -> V_25 ;
}
static inline bool F_7 ( struct V_19 * V_25 )
{
return V_25 -> V_26 . V_27 == V_28 ;
}
static inline struct V_23 * F_8 ( struct V_19 * V_25 )
{
if ( F_7 ( V_25 ) )
return F_6 ( V_25 , struct V_23 , V_29 ) ;
else
return F_6 ( V_25 , struct V_23 , V_25 ) ;
}
static T_3 F_9 ( struct V_23 * V_30 , T_3 V_31 )
{
struct V_32 * V_33 = F_10 ( & V_30 -> V_25 ) ;
T_4 V_34 , V_35 ;
T_3 V_36 ;
struct V_37 V_38 [] = {
{ . V_31 = V_33 -> V_31 , . V_39 = 0 ,
. V_40 = 2 , . V_41 = ( V_42 * ) & V_34 } ,
{ . V_31 = V_33 -> V_31 , . V_39 = V_43 ,
. V_40 = 2 , . V_41 = ( V_42 * ) & V_35 } ,
} ;
int V_11 ;
if ( V_30 -> error )
return 0 ;
V_34 = F_11 ( V_31 ) ;
V_11 = F_12 ( V_33 -> V_44 , V_38 , 2 ) ;
V_36 = F_13 ( V_35 ) ;
F_14 ( 3 , V_45 , V_33 , L_5 , V_31 , V_36 ) ;
if ( V_11 != 2 ) {
F_15 ( V_33 , L_6 , V_11 ) ;
V_30 -> error = V_11 ;
}
return V_36 ;
}
static void F_16 ( struct V_23 * V_30 , T_3 V_31 , T_3 V_46 )
{
V_42 V_41 [ 4 ] = { V_31 >> 8 , V_31 & 0xFF , V_46 >> 8 , V_46 & 0xFF } ;
struct V_32 * V_33 = F_10 ( & V_30 -> V_25 ) ;
int V_11 ;
if ( V_30 -> error )
return;
V_11 = F_17 ( V_33 , V_41 , 4 ) ;
F_14 ( 3 , V_45 , V_33 , L_7 , V_31 , V_46 ) ;
if ( V_11 != 4 ) {
F_15 ( V_33 , L_8 , V_11 ) ;
V_30 -> error = V_11 ;
}
}
static T_3 F_18 ( struct V_23 * V_30 , T_3 V_31 )
{
F_16 ( V_30 , V_47 , V_31 ) ;
return F_9 ( V_30 , V_48 ) ;
}
static void F_19 ( struct V_23 * V_30 , T_3 V_31 , T_3 V_46 )
{
F_16 ( V_30 , V_49 , V_31 ) ;
F_16 ( V_30 , V_48 , V_46 ) ;
}
static void F_20 ( struct V_23 * V_30 , T_3 V_31 ,
T_3 V_5 , const T_3 * V_17 )
{
struct V_32 * V_33 = F_10 ( & V_30 -> V_25 ) ;
T_4 V_41 [ 65 ] ;
F_16 ( V_30 , V_49 , V_31 ) ;
if ( V_30 -> error )
return;
F_14 ( 3 , V_45 , V_33 , L_9 , V_5 ,
F_21 ( 2 * V_5 , 64 ) , V_17 ) ;
V_41 [ 0 ] = F_11 ( V_48 ) ;
while ( V_5 > 0 ) {
int V_50 = F_22 ( int , V_5 , F_23 ( V_41 ) - 1 ) ;
int V_11 , V_9 ;
for ( V_9 = 1 ; V_9 <= V_50 ; ++ V_9 )
V_41 [ V_9 ] = F_11 ( * V_17 ++ ) ;
V_9 *= 2 ;
V_11 = F_17 ( V_33 , ( char * ) V_41 , V_9 ) ;
if ( V_11 != V_9 ) {
F_15 ( V_33 , L_10 , V_11 ) ;
V_30 -> error = V_11 ;
break;
}
V_5 -= V_50 ;
}
}
static void F_24 ( struct V_23 * V_30 , const T_3 * V_51 )
{
int V_5 ;
while ( ( V_5 = * V_51 ++ ) ) {
T_3 V_31 = * V_51 ++ ;
-- V_5 ;
F_20 ( V_30 , V_31 , V_5 , V_51 ) ;
V_51 += V_5 ;
}
}
static void F_25 ( struct V_23 * V_30 , int V_52 , T_3 V_31 )
{
unsigned long V_10 = V_53 + F_26 ( V_52 ) ;
T_3 V_54 ;
F_19 ( V_30 , V_31 , 1 ) ;
do {
V_54 = F_18 ( V_30 , V_31 ) ;
if ( V_30 -> error || ! V_54 )
return;
F_27 ( 5000 , 10000 ) ;
} while ( F_28 ( V_10 ) );
F_15 ( & V_30 -> V_25 , L_11 , V_31 ) ;
V_30 -> error = - V_55 ;
}
static T_3 * F_29 ( struct V_23 * V_30 , T_3 V_56 )
{
struct V_3 * V_4 = V_30 -> V_4 ;
T_3 * V_6 ;
int V_9 ;
if ( V_4 == NULL )
return NULL ;
V_6 = V_4 -> V_6 + 2 * V_4 -> V_5 ;
for ( V_9 = 0 ; V_9 < V_4 -> V_5 ; ++ V_9 ) {
if ( V_4 -> V_17 [ V_9 ] . V_57 == V_56 )
return V_6 + V_4 -> V_17 [ V_9 ] . V_18 ;
}
return NULL ;
}
static void F_30 ( struct V_23 * V_30 )
{
T_3 * V_17 = F_29 ( V_30 , V_58 ) ;
if ( V_17 )
F_24 ( V_30 , V_17 ) ;
}
static void F_31 ( struct V_23 * V_30 )
{
unsigned long V_59 = V_30 -> V_60 / 1000 ;
T_3 V_61 ;
static const T_3 V_62 [] = {
F_32 ( V_63 ,
V_64 , V_65 , 0 ,
V_66 / 4 , V_67 / 4 , V_68 / 4 ,
V_69 / 4 , V_67 / 4 , V_68 / 4 ) ,
F_32 ( V_70 , 1 ) ,
0
} ;
F_33 ( V_30 , V_71 , V_59 & 0xffff , V_59 >> 16 ) ;
F_24 ( V_30 , V_62 ) ;
F_25 ( V_30 , 250 , V_72 ) ;
V_61 = F_18 ( V_30 , V_73 ) ;
if ( ! V_30 -> error && V_61 ) {
F_15 ( & V_30 -> V_25 , L_12 , V_61 ) ;
V_30 -> error = - V_13 ;
}
}
static void F_34 ( struct V_23 * V_30 )
{
T_3 * V_17 = F_29 ( V_30 , V_74 ) ;
if ( V_17 )
F_24 ( V_30 , V_17 ) ;
}
static void F_35 ( struct V_23 * V_30 )
{
T_3 * V_17 = F_29 ( V_30 , V_75 ) ;
if ( ! V_17 )
return;
F_16 ( V_30 , V_76 , V_77 ) ;
F_24 ( V_30 , V_17 ) ;
F_16 ( V_30 , V_76 , V_78 ) ;
}
static void F_36 ( struct V_23 * V_30 )
{
F_19 ( V_30 , V_79 , 1 ) ;
if ( V_30 -> V_80 ) {
F_19 ( V_30 , V_81 , 1 ) ;
F_19 ( V_30 , V_82 , 1 ) ;
}
F_25 ( V_30 , 500 , V_83 ) ;
}
static void F_37 ( struct V_23 * V_30 )
{
T_3 V_84 = V_30 -> V_24 . V_85 -> V_46 | ( V_30 -> V_24 . V_85 -> V_46 << 1 ) ;
F_19 ( V_30 , F_38 ( 0 ) , V_84 ) ;
if ( V_30 -> V_86 )
F_36 ( V_30 ) ;
}
static void F_39 ( struct V_23 * V_30 , T_3 V_87 , bool V_88 )
{
T_3 V_89 , V_90 ;
if ( ! V_30 -> V_91 )
V_89 = F_18 ( V_30 , V_92 ) ;
else
V_89 = V_30 -> V_93 ;
V_90 = V_88 ? ( V_89 | V_87 ) : ( V_89 & ~ V_87 ) ;
if ( V_90 != V_89 )
F_19 ( V_30 , V_92 , V_90 ) ;
if ( V_30 -> error )
return;
V_30 -> V_91 = 1 ;
V_30 -> V_93 = V_90 ;
}
static void F_40 ( struct V_23 * V_30 , int V_94 )
{
struct V_95 * V_24 = & V_30 -> V_24 ;
if ( ! V_94 )
F_33 ( V_30 , V_96 ,
V_24 -> V_97 -> V_46 , 1 ,
V_98 , 1 ,
V_24 -> V_99 -> V_46 , 1 ,
1 ) ;
F_39 ( V_30 , V_100 , V_94 ) ;
}
static void F_41 ( struct V_23 * V_30 , int V_101 )
{
unsigned int time = V_101 / 10 ;
F_33 ( V_30 , V_102 ,
time & 0xffff , time >> 16 , 1 ) ;
}
static void F_42 ( struct V_23 * V_30 , int V_103 )
{
F_33 ( V_30 , V_104 , V_103 , 1 ) ;
}
static void F_43 ( struct V_23 * V_30 , int V_105 )
{
if ( V_105 == V_106 ) {
F_39 ( V_30 , V_107 | V_108 , true ) ;
} else {
unsigned int V_109 = V_30 -> V_24 . V_101 -> V_46 ;
F_41 ( V_30 , V_109 ) ;
F_42 ( V_30 , V_30 -> V_24 . V_103 -> V_46 ) ;
F_39 ( V_30 , V_107 | V_108 , false ) ;
}
}
static void F_44 ( struct V_23 * V_30 , int V_110 )
{
if ( V_110 == V_111 ) {
F_39 ( V_30 , V_112 , true ) ;
} else {
F_33 ( V_30 , V_113 , V_110 , 1 ) ;
F_39 ( V_30 , V_112 , false ) ;
}
}
static void F_45 ( struct V_23 * V_30 , int V_46 )
{
static const T_3 V_114 [] = {
[ V_115 ] = 0 ,
[ V_116 ] = 1 ,
[ V_117 ] = 2 ,
[ V_118 ] = 3 ,
[ V_119 ] = 4 ,
[ V_120 ] = 5 ,
} ;
F_19 ( V_30 , V_121 , V_114 [ V_46 ] ) ;
}
static int F_46 ( struct V_122 * V_123 )
{
int V_9 , V_33 = - 1 ;
for ( V_9 = 0 ; V_9 < F_23 ( V_124 ) ; V_9 ++ ) {
if ( V_123 -> V_125 != V_124 [ V_9 ] . V_125 )
continue;
if ( V_123 -> V_126 == V_124 [ V_9 ] . V_126 )
return V_9 ;
if ( V_33 < 0 )
V_33 = V_9 ;
}
return ( V_33 < 0 ) ? 0 : V_33 ;
}
static int F_47 ( struct V_23 * V_30 )
{
int V_11 = V_30 -> error ;
V_30 -> error = 0 ;
return V_11 ;
}
static int F_48 ( struct V_23 * V_30 )
{
T_3 V_127 ;
if ( V_30 -> V_128 == V_129 )
V_127 = V_130 ;
else
V_127 = 0 ;
F_33 ( V_30 , V_131 ,
V_30 -> V_132 , V_127 , 1 ) ;
return F_47 ( V_30 ) ;
}
static T_3 F_49 ( struct V_23 * V_30 )
{
T_3 V_133 = F_18 ( V_30 , V_134 ) ;
if ( V_133 )
F_19 ( V_30 , V_134 , 0 ) ;
return V_133 ;
}
static void F_50 ( struct V_23 * V_30 , T_3 V_135 )
{
F_19 ( V_30 , F_51 ( 0 ) , V_135 ) ;
F_36 ( V_30 ) ;
}
static void F_52 ( struct V_23 * V_30 )
{
T_3 V_133 , V_135 ;
int V_50 ;
V_135 = F_18 ( V_30 , V_136 ) ;
if ( V_30 -> error )
return;
for ( V_50 = 5 ; V_50 > 0 ; -- V_50 ) {
F_50 ( V_30 , V_135 ) ;
V_133 = F_49 ( V_30 ) ;
if ( V_30 -> error )
return;
switch ( V_133 ) {
case V_137 :
++ V_135 ;
break;
case 0 :
V_30 -> V_135 = V_135 ;
F_53 ( & V_30 -> V_25 ,
L_13 , V_135 ) ;
return;
default:
F_15 ( & V_30 -> V_25 ,
L_14 , V_133 ) ;
V_30 -> error = - V_13 ;
}
}
F_15 ( & V_30 -> V_25 , L_15 ) ;
V_30 -> error = - V_138 ;
}
static void F_54 ( struct V_23 * V_30 )
{
T_3 V_133 ;
V_133 = F_49 ( V_30 ) ;
if ( V_30 -> error )
return;
switch ( V_133 ) {
case 0 :
V_30 -> V_139 = 1 ;
return;
case V_137 :
F_52 ( V_30 ) ;
if ( ! V_30 -> error )
V_30 -> V_139 = 1 ;
return;
default:
F_15 ( & V_30 -> V_25 ,
L_16 , V_133 ) ;
V_30 -> error = - V_13 ;
}
}
static void F_55 ( struct V_140 * V_35 , const struct V_140 * V_110 ,
const struct V_140 * V_50 ,
const struct V_140 * V_8 )
{
V_35 -> V_141 = V_110 -> V_141 * V_50 -> V_142 / V_8 -> V_142 ;
V_35 -> V_143 = V_110 -> V_143 * V_50 -> V_144 / V_8 -> V_144 ;
V_35 -> V_142 = V_110 -> V_142 * V_50 -> V_142 / V_8 -> V_142 ;
V_35 -> V_144 = V_110 -> V_144 * V_50 -> V_144 / V_8 -> V_144 ;
}
static int F_56 ( struct V_23 * V_30 )
{
struct V_140 * V_145 , V_35 ;
T_3 V_133 ;
int V_11 ;
V_145 = & V_30 -> V_146 ;
F_33 ( V_30 , V_147 , V_145 -> V_142 , V_145 -> V_144 ,
V_145 -> V_141 , V_145 -> V_143 ) ;
F_55 ( & V_35 , & V_30 -> V_148 , & V_30 -> V_146 ,
& V_30 -> V_149 ) ;
F_33 ( V_30 , V_150 , V_35 . V_142 , V_35 . V_144 ,
V_35 . V_141 , V_35 . V_143 ) ;
F_25 ( V_30 , 500 , V_81 ) ;
F_25 ( V_30 , 500 , V_82 ) ;
V_133 = F_49 ( V_30 ) ;
V_11 = F_47 ( V_30 ) ;
if ( V_11 < 0 )
return V_11 ;
switch ( V_133 ) {
case 0 :
break;
case V_137 :
F_50 ( V_30 , V_151 ) ;
V_133 = F_49 ( V_30 ) ;
V_11 = F_47 ( V_30 ) ;
if ( V_11 < 0 )
return V_11 ;
if ( V_133 ) {
F_15 ( & V_30 -> V_25 ,
L_17 , V_133 ) ;
V_30 -> error = - V_13 ;
}
F_50 ( V_30 , V_30 -> V_152 ) ;
F_54 ( V_30 ) ;
break;
default:
F_15 ( & V_30 -> V_25 , L_18 , V_133 ) ;
return - V_13 ;
}
if ( ! V_30 -> V_139 )
return 0 ;
V_145 = & V_30 -> V_148 ;
F_33 ( V_30 , F_57 ( 0 ) , V_145 -> V_142 , V_145 -> V_144 ) ;
F_50 ( V_30 , V_30 -> V_152 ) ;
F_54 ( V_30 ) ;
return F_47 ( V_30 ) ;
}
static void F_58 ( struct V_23 * V_30 )
{
T_3 V_153 = V_124 [ V_30 -> V_154 ] . V_155 ;
struct V_140 * V_35 = & V_30 -> V_148 ;
F_33 ( V_30 , F_57 ( 0 ) ,
V_35 -> V_142 , V_35 -> V_144 , V_153 ,
V_68 >> 2 , V_67 >> 2 ,
V_156 , V_157 ,
V_158 , V_159 ,
V_30 -> V_152 , V_160 ) ;
F_36 ( V_30 ) ;
F_54 ( V_30 ) ;
}
static void F_59 ( struct V_23 * V_30 , int V_57 )
{
F_16 ( V_30 , V_161 , 800 ) ;
F_16 ( V_30 , V_162 , 511 ) ;
F_16 ( V_30 , V_163 , 0 ) ;
F_16 ( V_30 , V_164 , V_57 ) ;
}
static void F_60 ( struct V_23 * V_30 , int V_57 )
{
struct V_165 * V_166 = & V_30 -> V_167 [ V_57 ] ;
F_61 ( V_166 -> V_166 , V_166 -> V_168 ) ;
}
static void F_62 ( struct V_23 * V_30 , int V_57 )
{
struct V_165 * V_166 = & V_30 -> V_167 [ V_57 ] ;
F_61 ( V_166 -> V_166 , ! V_166 -> V_168 ) ;
}
static int F_63 ( struct V_23 * V_30 )
{
int V_11 ;
V_11 = F_64 ( V_169 , V_30 -> V_170 ) ;
if ( V_11 < 0 )
goto V_133;
V_11 = F_65 ( V_30 -> clock , V_30 -> V_60 ) ;
if ( V_11 < 0 )
goto V_171;
V_11 = F_66 ( V_30 -> clock ) ;
if ( V_11 < 0 )
goto V_171;
F_14 ( 1 , V_45 , & V_30 -> V_25 , L_19 ,
F_67 ( V_30 -> clock ) ) ;
F_62 ( V_30 , V_172 ) ;
F_27 ( 50 , 100 ) ;
F_62 ( V_30 , V_173 ) ;
return 0 ;
V_171:
F_68 ( V_169 , V_30 -> V_170 ) ;
V_133:
F_15 ( & V_30 -> V_25 , L_20 , V_174 , V_11 ) ;
return V_11 ;
}
static int F_69 ( struct V_23 * V_30 )
{
int V_11 ;
V_30 -> V_86 = 0 ;
V_30 -> V_139 = 0 ;
V_30 -> V_80 = 0 ;
F_60 ( V_30 , V_173 ) ;
F_60 ( V_30 , V_172 ) ;
if ( ! F_70 ( V_30 -> clock ) )
F_71 ( V_30 -> clock ) ;
V_11 = F_68 ( V_169 ,
V_30 -> V_170 ) ;
if ( V_11 < 0 )
F_15 ( & V_30 -> V_25 , L_21 ) ;
return 0 ;
}
static void F_72 ( struct V_23 * V_30 )
{
F_16 ( V_30 , V_175 , V_77 ) ;
F_16 ( V_30 , V_176 , 0 ) ;
F_16 ( V_30 , V_177 , 1 ) ;
F_16 ( V_30 , V_178 , V_78 ) ;
F_16 ( V_30 , V_76 , V_78 ) ;
}
static void F_73 ( struct V_23 * V_30 )
{
V_30 -> V_154 = 0 ;
V_30 -> V_152 = 10000 / 15 ;
V_30 -> V_135 = V_30 -> V_152 ;
V_30 -> V_91 = 0 ;
}
static int F_74 ( struct V_23 * V_30 )
{
struct V_32 * V_33 = F_10 ( & V_30 -> V_25 ) ;
const struct V_179 * V_4 ;
int V_11 ;
V_11 = F_75 ( & V_4 , V_180 , & V_33 -> V_2 ) ;
if ( V_11 < 0 ) {
F_76 ( & V_33 -> V_2 , L_22 ,
V_180 ) ;
return V_11 ;
}
V_11 = F_1 ( & V_33 -> V_2 , & V_30 -> V_4 , V_4 -> V_181 / 2 ,
( T_2 * ) V_4 -> V_6 ) ;
F_77 ( V_4 ) ;
return V_11 ;
}
static int F_78 ( struct V_19 * V_25 , int V_182 )
{
struct V_23 * V_30 = F_8 ( V_25 ) ;
int V_11 = 0 ;
F_79 ( & V_30 -> V_183 ) ;
if ( V_30 -> V_184 != ! V_182 )
goto V_185;
if ( V_182 ) {
if ( V_30 -> V_4 == NULL )
F_74 ( V_30 ) ;
F_73 ( V_30 ) ;
V_11 = F_63 ( V_30 ) ;
if ( V_11 < 0 )
goto V_185;
F_72 ( V_30 ) ;
F_30 ( V_30 ) ;
F_16 ( V_30 , V_186 , 1 ) ;
F_31 ( V_30 ) ;
V_11 = F_48 ( V_30 ) ;
if ( V_11 < 0 )
goto V_185;
F_35 ( V_30 ) ;
F_34 ( V_30 ) ;
V_11 = F_47 ( V_30 ) ;
if ( ! V_11 )
V_30 -> V_184 ++ ;
} else {
F_69 ( V_30 ) ;
V_30 -> V_184 -- ;
}
V_185:
F_80 ( & V_30 -> V_183 ) ;
if ( ! V_11 && V_182 )
V_11 = F_81 ( & V_30 -> V_24 . V_22 ) ;
return V_11 ;
}
static void F_82 ( struct V_23 * V_30 , int V_88 )
{
F_33 ( V_30 , V_187 , V_88 , 1 ) ;
}
static int F_83 ( struct V_19 * V_25 , int V_182 )
{
struct V_23 * V_30 = F_8 ( V_25 ) ;
int V_11 ;
F_79 ( & V_30 -> V_183 ) ;
if ( V_30 -> V_86 == ! ! V_182 ) {
V_11 = 0 ;
goto V_185;
}
if ( V_182 ) {
F_58 ( V_30 ) ;
V_11 = F_56 ( V_30 ) ;
if ( V_11 < 0 )
goto V_185;
F_82 ( V_30 , 1 ) ;
F_16 ( V_30 , 0xb0cc , 0x000b ) ;
} else {
F_82 ( V_30 , 0 ) ;
}
V_11 = F_47 ( V_30 ) ;
if ( ! V_11 )
V_30 -> V_86 = ! V_30 -> V_86 ;
V_185:
F_80 ( & V_30 -> V_183 ) ;
return V_11 ;
}
static int F_84 ( struct V_19 * V_25 ,
struct V_188 * V_189 )
{
struct V_23 * V_30 = F_8 ( V_25 ) ;
F_79 ( & V_30 -> V_183 ) ;
V_189 -> V_190 . V_191 = V_30 -> V_135 ;
V_189 -> V_190 . V_192 = 10000 ;
F_80 ( & V_30 -> V_183 ) ;
return 0 ;
}
static void F_85 ( struct V_23 * V_30 ,
struct V_188 * V_189 )
{
struct V_193 * V_9 = & V_189 -> V_190 ;
if ( V_189 -> V_190 . V_192 == 0 )
V_30 -> V_152 = V_151 ;
else
V_30 -> V_152 = F_86 ( V_194 ,
V_9 -> V_191 * 10000 / V_9 -> V_192 ,
V_160 ,
V_151 ) ;
V_30 -> V_135 = V_30 -> V_152 ;
if ( V_30 -> V_139 ) {
F_50 ( V_30 , V_30 -> V_152 ) ;
F_54 ( V_30 ) ;
}
* V_9 = (struct V_193 ) { V_30 -> V_135 , 10000 } ;
if ( V_30 -> V_135 == V_30 -> V_152 )
F_53 ( & V_30 -> V_25 , L_23 ,
V_30 -> V_135 ) ;
}
static int F_87 ( struct V_19 * V_25 ,
struct V_188 * V_189 )
{
struct V_23 * V_30 = F_8 ( V_25 ) ;
F_79 ( & V_30 -> V_183 ) ;
F_85 ( V_30 , V_189 ) ;
F_80 ( & V_30 -> V_183 ) ;
return 0 ;
}
static int F_88 ( struct V_19 * V_25 ,
struct V_195 * V_196 ,
struct V_197 * V_198 )
{
if ( V_198 -> V_199 > V_151 - V_160 ||
V_198 -> V_200 != V_201 )
return - V_13 ;
F_89 ( & V_198 -> V_142 , V_202 ,
V_203 , 1 ,
& V_198 -> V_144 , V_204 ,
V_205 , 1 , 0 ) ;
V_198 -> V_190 . V_191 = V_160 + V_198 -> V_199 ;
V_198 -> V_190 . V_192 = 10000 ;
return 0 ;
}
static int F_90 ( struct V_19 * V_25 ,
struct V_195 * V_196 ,
struct V_206 * V_126 )
{
if ( V_126 -> V_200 == V_201 ) {
if ( V_126 -> V_199 > 0 )
return - V_13 ;
V_126 -> V_126 = V_207 ;
return 0 ;
}
if ( V_126 -> V_199 >= F_23 ( V_124 ) )
return - V_13 ;
V_126 -> V_126 = V_124 [ V_126 -> V_199 ] . V_126 ;
return 0 ;
}
static int F_91 ( struct V_19 * V_25 ,
struct V_195 * V_196 ,
struct V_208 * V_209 )
{
int V_9 ;
if ( V_209 -> V_199 > 0 )
return - V_13 ;
if ( V_209 -> V_200 == V_201 ) {
V_209 -> V_126 = V_207 ;
V_209 -> V_210 = V_203 ;
V_209 -> V_211 = V_203 ;
V_209 -> V_212 = V_205 ;
V_209 -> V_213 = V_205 ;
return 0 ;
}
V_9 = F_23 ( V_124 ) ;
while ( -- V_9 )
if ( V_209 -> V_126 == V_124 [ V_9 ] . V_126 )
break;
V_209 -> V_126 = V_124 [ V_9 ] . V_126 ;
V_209 -> V_210 = V_202 ;
V_209 -> V_211 = V_203 ;
V_209 -> V_213 = V_204 ;
V_209 -> V_212 = V_205 ;
return 0 ;
}
static void F_92 ( struct V_122 * V_123 )
{
V_123 -> V_142 = V_203 ;
V_123 -> V_144 = V_205 ;
V_123 -> V_126 = V_207 ;
V_123 -> V_125 = V_214 ;
V_123 -> V_215 = V_216 ;
}
static int F_93 ( struct V_122 * V_123 )
{
int V_154 ;
F_89 ( & V_123 -> V_142 , V_202 ,
V_203 , 1 ,
& V_123 -> V_144 , V_204 ,
V_205 , 1 , 0 ) ;
V_154 = F_46 ( V_123 ) ;
V_123 -> V_125 = V_124 [ V_154 ] . V_125 ;
V_123 -> V_126 = V_124 [ V_154 ] . V_126 ;
V_123 -> V_215 = V_216 ;
return V_154 ;
}
static int F_94 ( struct V_19 * V_25 , struct V_195 * V_196 ,
struct V_217 * V_218 )
{
struct V_23 * V_30 = F_8 ( V_25 ) ;
const struct V_219 * V_154 ;
struct V_122 * V_123 ;
if ( V_218 -> V_220 == V_221 ) {
V_123 = F_95 ( V_25 , V_196 , V_218 -> V_200 ) ;
V_218 -> V_222 = * V_123 ;
return 0 ;
}
V_123 = & V_218 -> V_222 ;
if ( V_218 -> V_200 == V_201 ) {
F_92 ( V_123 ) ;
return 0 ;
}
V_123 -> V_215 = V_216 ;
F_79 ( & V_30 -> V_183 ) ;
V_154 = & V_124 [ V_30 -> V_154 ] ;
V_123 -> V_142 = V_30 -> V_148 . V_142 ;
V_123 -> V_144 = V_30 -> V_148 . V_144 ;
V_123 -> V_126 = V_154 -> V_126 ;
V_123 -> V_125 = V_154 -> V_125 ;
F_80 ( & V_30 -> V_183 ) ;
return 0 ;
}
static int F_96 ( struct V_19 * V_25 , struct V_195 * V_196 ,
struct V_217 * V_218 )
{
struct V_122 * V_123 = & V_218 -> V_222 ;
struct V_23 * V_30 = F_8 ( V_25 ) ;
const struct V_219 * V_154 ;
int V_11 = 0 ;
V_123 -> V_215 = V_216 ;
if ( V_218 -> V_220 == V_221 ) {
* F_95 ( V_25 , V_196 , V_218 -> V_200 ) = * V_123 ;
return 0 ;
}
if ( V_218 -> V_200 == V_201 ) {
F_92 ( V_123 ) ;
return 0 ;
}
F_79 ( & V_30 -> V_183 ) ;
if ( V_30 -> V_86 ) {
F_80 ( & V_30 -> V_183 ) ;
return - V_223 ;
}
V_30 -> V_154 = F_93 ( V_123 ) ;
V_154 = & V_124 [ V_30 -> V_154 ] ;
V_123 -> V_126 = V_154 -> V_126 ;
V_123 -> V_125 = V_154 -> V_125 ;
V_123 -> V_142 = V_30 -> V_148 . V_142 ;
V_123 -> V_144 = V_30 -> V_148 . V_144 ;
F_80 ( & V_30 -> V_183 ) ;
return V_11 ;
}
static enum V_224 F_97 ( V_194 V_200 , V_194 V_225 )
{
switch ( V_225 ) {
case V_226 :
return V_200 ? V_227 : V_228 ;
case V_229 :
return V_200 ? V_230 : V_231 ;
case V_232 :
return V_200 ? V_233 : V_231 ;
case V_234 :
return V_200 ? V_233 : V_227 ;
default:
return V_233 ;
}
}
static int F_98 ( V_194 V_225 )
{
return V_225 == V_226 ||
V_225 == V_232 ;
}
static int F_99 ( struct V_19 * V_25 ,
struct V_195 * V_196 ,
struct V_235 * V_236 )
{
static enum V_224 V_237 ;
struct V_23 * V_30 = F_8 ( V_25 ) ;
V_237 = F_97 ( V_236 -> V_200 , V_236 -> V_225 ) ;
switch ( V_237 ) {
case V_233 :
return - V_13 ;
case V_228 :
V_236 -> V_35 = V_238 ;
return 0 ;
default:
break;
}
if ( V_236 -> V_220 == V_221 ) {
if ( V_237 == V_227 )
V_236 -> V_35 = * F_100 ( V_25 , V_196 , V_236 -> V_200 ) ;
else
V_236 -> V_35 = * F_101 ( V_25 , V_196 , V_236 -> V_200 ) ;
return 0 ;
}
F_79 ( & V_30 -> V_183 ) ;
switch ( V_237 ) {
case V_231 :
V_236 -> V_35 = V_30 -> V_146 ;
break;
case V_227 :
V_236 -> V_35 = V_30 -> V_149 ;
break;
case V_230 :
V_236 -> V_35 = V_30 -> V_148 ;
break;
default:
break;
}
if ( F_98 ( V_236 -> V_225 ) ) {
V_236 -> V_35 . V_141 = 0 ;
V_236 -> V_35 . V_143 = 0 ;
}
F_80 ( & V_30 -> V_183 ) ;
return 0 ;
}
static void F_102 ( V_194 * V_239 , V_194 * V_40 , V_194 V_240 )
{
if ( * V_40 > V_240 )
* V_40 = V_240 ;
if ( * V_239 + * V_40 > V_240 )
* V_239 = V_240 - * V_40 ;
* V_239 &= ~ 1 ;
* V_40 &= ~ 1 ;
if ( * V_40 < V_202 )
* V_40 = V_202 ;
}
static void F_103 ( struct V_140 * V_35 , V_194 V_142 , V_194 V_144 )
{
F_102 ( & V_35 -> V_141 , & V_35 -> V_142 , V_142 ) ;
F_102 ( & V_35 -> V_143 , & V_35 -> V_144 , V_144 ) ;
}
static void F_104 ( struct V_140 * * V_241 ,
enum V_224 V_242 ,
struct V_140 * V_110 )
{
struct V_140 * V_35 , * V_243 ;
enum V_224 V_9 = V_242 ;
* V_241 [ V_242 ] = * V_110 ;
do {
V_35 = V_241 [ V_9 ] ;
V_243 = V_241 [ V_9 - 1 ] ;
F_103 ( V_35 , V_243 -> V_142 , V_243 -> V_144 ) ;
} while ( ++ V_9 != V_233 );
* V_110 = * V_241 [ V_242 ] ;
}
static bool F_105 ( const struct V_140 * V_244 ,
const struct V_140 * V_245 )
{
return ! memcmp ( V_244 , V_245 , sizeof( * V_244 ) ) ;
}
static int F_106 ( struct V_19 * V_25 ,
struct V_195 * V_196 ,
struct V_235 * V_236 )
{
static enum V_224 V_237 ;
struct V_23 * V_30 = F_8 ( V_25 ) ;
struct V_140 * * V_241 ;
int V_11 = 0 ;
V_237 = F_97 ( V_236 -> V_200 , V_236 -> V_225 ) ;
if ( V_237 == V_233 || F_98 ( V_236 -> V_225 ) )
return - V_13 ;
if ( V_237 == V_227 ) {
V_236 -> V_35 . V_141 = 0 ;
V_236 -> V_35 . V_143 = 0 ;
}
if ( V_236 -> V_220 == V_221 ) {
V_241 = (struct V_140 * [] ) {
& V_238 ,
F_101 ( V_25 , V_196 , V_201 ) ,
F_100 ( V_25 , V_196 , V_201 ) ,
F_101 (sd, cfg, PAD_OUT)
} ;
F_104 ( V_241 , V_237 , & V_236 -> V_35 ) ;
return 0 ;
}
V_241 = (struct V_140 * [] ) {
& V_238 ,
& V_30 -> V_146 ,
& V_30 -> V_149 ,
& V_30 -> V_148
} ;
F_79 ( & V_30 -> V_183 ) ;
if ( V_30 -> V_86 ) {
if ( V_237 < V_230 ) {
if ( V_236 -> V_35 . V_142 < V_30 -> V_148 . V_142 )
V_236 -> V_35 . V_142 = V_30 -> V_148 . V_142 ;
if ( V_236 -> V_35 . V_144 < V_30 -> V_148 . V_144 )
V_236 -> V_35 . V_144 = V_30 -> V_148 . V_144 ;
} else {
V_236 -> V_35 . V_142 = V_30 -> V_148 . V_142 ;
V_236 -> V_35 . V_144 = V_30 -> V_148 . V_144 ;
}
}
F_104 ( V_241 , V_237 , & V_236 -> V_35 ) ;
if ( ! F_105 ( & V_30 -> V_146 , & V_238 ) ||
! F_105 ( & V_30 -> V_149 , & V_238 ) )
V_30 -> V_80 = 1 ;
if ( V_30 -> V_86 )
V_11 = F_56 ( V_30 ) ;
F_80 ( & V_30 -> V_183 ) ;
return V_11 ;
}
static int F_107 ( struct V_20 * V_21 )
{
struct V_19 * V_25 = F_5 ( V_21 ) ;
struct V_23 * V_30 = F_8 ( V_25 ) ;
int V_11 ;
F_14 ( 1 , V_45 , V_25 , L_24 , V_21 -> V_246 , V_21 -> V_46 ) ;
F_79 ( & V_30 -> V_183 ) ;
if ( V_30 -> V_184 == 0 )
goto V_247;
switch ( V_21 -> V_57 ) {
case V_248 :
F_40 ( V_30 , V_21 -> V_46 ) ;
break;
case V_249 :
F_19 ( V_30 , V_250 , V_21 -> V_46 ) ;
break;
case V_251 :
F_45 ( V_30 , V_21 -> V_46 ) ;
break;
case V_252 :
F_19 ( V_30 , V_253 , V_21 -> V_46 ) ;
break;
case V_254 :
F_43 ( V_30 , V_21 -> V_46 ) ;
break;
case V_255 :
F_37 ( V_30 ) ;
break;
case V_256 :
F_44 ( V_30 , V_21 -> V_46 ) ;
break;
case V_257 :
F_19 ( V_30 , V_258 , V_21 -> V_46 ) ;
break;
case V_259 :
F_19 ( V_30 , V_260 , V_21 -> V_46 ) ;
break;
case V_261 :
F_19 ( V_30 , F_108 ( 0 ) , V_21 -> V_46 ) ;
if ( V_30 -> V_139 )
F_36 ( V_30 ) ;
break;
case V_262 :
F_59 ( V_30 , V_21 -> V_46 ) ;
break;
}
V_247:
V_11 = F_47 ( V_30 ) ;
F_80 ( & V_30 -> V_183 ) ;
return V_11 ;
}
static int F_109 ( struct V_23 * V_30 )
{
const struct V_263 * V_264 = & V_265 ;
struct V_95 * V_24 = & V_30 -> V_24 ;
struct V_266 * V_267 = & V_24 -> V_22 ;
int V_11 ;
V_11 = F_110 ( V_267 , 16 ) ;
if ( V_11 < 0 ) {
F_15 ( & V_30 -> V_25 , L_25 , V_11 ) ;
return V_11 ;
}
V_24 -> V_94 = F_111 ( V_267 , V_264 , V_248 ,
0 , 1 , 1 , 1 ) ;
V_24 -> V_97 = F_111 ( V_267 , V_264 , V_268 ,
0 , 255 , 1 , V_269 ) ;
V_24 -> V_99 = F_111 ( V_267 , V_264 , V_270 ,
0 , 255 , 1 , V_271 ) ;
F_112 ( 3 , & V_24 -> V_94 , 0 , false ) ;
V_24 -> V_272 = F_111 ( V_267 , V_264 , V_255 , 0 , 1 , 1 , 0 ) ;
V_24 -> V_85 = F_111 ( V_267 , V_264 , V_273 , 0 , 1 , 1 , 0 ) ;
F_113 ( 2 , & V_24 -> V_272 ) ;
V_24 -> V_274 = F_114 ( V_267 , V_264 ,
V_254 ,
V_275 , 0 , V_106 ) ;
V_24 -> V_101 = F_111 ( V_267 , V_264 , V_276 ,
0 , 6000000U , 1 , 100000U ) ;
V_24 -> V_103 = F_111 ( V_267 , V_264 , V_277 ,
0 , 256 , 1 , 256 ) ;
F_112 ( 3 , & V_24 -> V_274 , 0 , false ) ;
F_114 ( V_267 , V_264 , V_256 ,
V_111 , 0 ,
V_111 ) ;
F_114 ( V_267 , V_264 , V_251 ,
V_119 , ~ 0x6f , V_115 ) ;
F_111 ( V_267 , V_264 , V_261 ,
0 , 256 , 1 , 0 ) ;
F_111 ( V_267 , V_264 , V_257 , - 127 , 127 , 1 , 0 ) ;
F_111 ( V_267 , V_264 , V_249 , - 127 , 127 , 1 , 0 ) ;
F_111 ( V_267 , V_264 , V_252 , - 127 , 127 , 1 , 0 ) ;
F_111 ( V_267 , V_264 , V_259 , - 127 , 127 , 1 , 0 ) ;
F_115 ( V_267 , V_264 , V_262 ,
F_23 ( V_278 ) - 1 ,
0 , 0 , V_278 ) ;
if ( V_267 -> error ) {
F_15 ( & V_30 -> V_25 , L_26 ,
V_267 -> error ) ;
V_11 = V_267 -> error ;
F_116 ( V_267 ) ;
return V_11 ;
}
V_30 -> V_25 . V_279 = V_267 ;
return 0 ;
}
static int F_117 ( struct V_19 * V_25 , struct V_280 * V_281 )
{
struct V_122 * V_123 ;
V_123 = F_95 ( V_25 , V_281 -> V_200 , V_201 ) ;
F_92 ( V_123 ) ;
if ( F_7 ( V_25 ) )
return 0 ;
V_123 = F_95 ( V_25 , V_281 -> V_200 , V_282 ) ;
V_123 -> V_125 = V_124 [ 0 ] . V_125 ;
V_123 -> V_126 = V_124 [ 0 ] . V_126 ;
V_123 -> V_142 = V_238 . V_142 ;
V_123 -> V_144 = V_238 . V_144 ;
V_123 -> V_215 = V_216 ;
* F_101 ( V_25 , V_281 -> V_200 , V_201 ) = V_238 ;
* F_100 ( V_25 , V_281 -> V_200 , V_201 ) = V_238 ;
* F_101 ( V_25 , V_281 -> V_200 , V_282 ) = V_238 ;
return 0 ;
}
static int F_118 ( struct V_23 * V_30 )
{
T_3 V_283 = 0 , V_284 = 0 , V_285 = 0 ;
int V_11 ;
V_283 = F_18 ( V_30 , V_286 ) ;
V_284 = F_18 ( V_30 , V_287 ) & 0xff ;
V_285 = F_18 ( V_30 , V_288 ) ;
V_11 = F_47 ( V_30 ) ;
if ( V_11 < 0 )
return V_11 ;
F_53 ( & V_30 -> V_25 , L_27 ,
V_283 , V_284 , V_285 ) ;
if ( V_283 != V_289 ) {
F_15 ( & V_30 -> V_25 , L_28 ) ;
return - V_290 ;
}
return 0 ;
}
static int F_119 ( struct V_19 * V_25 )
{
struct V_23 * V_30 = F_8 ( V_25 ) ;
int V_11 ;
V_11 = F_120 ( V_25 -> V_291 , & V_30 -> V_29 ) ;
if ( V_11 < 0 )
F_15 ( V_25 , L_29 ,
V_30 -> V_29 . V_246 ) ;
else
V_11 = F_121 ( & V_30 -> V_29 . V_26 , V_201 ,
& V_30 -> V_25 . V_26 , V_201 ,
V_292 |
V_293 ) ;
return V_11 ;
}
static void F_122 ( struct V_19 * V_25 )
{
struct V_23 * V_30 = F_8 ( V_25 ) ;
F_123 ( & V_30 -> V_29 ) ;
}
static int F_124 ( struct V_23 * V_30 )
{
static const char * const V_246 [] = { L_30 , L_31 } ;
struct V_32 * V_33 = F_10 ( & V_30 -> V_25 ) ;
struct V_165 * V_294 = V_30 -> V_167 ;
int V_11 , V_9 ;
for ( V_9 = 0 ; V_9 < V_295 ; ++ V_9 ) {
int V_39 = V_296 ;
if ( V_294 [ V_9 ] . V_168 )
V_39 |= V_297 ;
V_11 = F_125 ( & V_33 -> V_2 , V_294 [ V_9 ] . V_166 , V_39 , V_246 [ V_9 ] ) ;
if ( V_11 < 0 ) {
F_15 ( V_33 , L_32 , V_246 [ V_9 ] ) ;
return V_11 ;
}
}
return 0 ;
}
static int F_126 ( struct V_165 * V_167 , struct V_1 * V_2 )
{
static const char * const V_298 [] = {
L_33 ,
L_34 ,
} ;
struct V_299 * V_300 = V_2 -> V_301 ;
enum V_302 V_39 ;
int V_11 , V_9 ;
for ( V_9 = 0 ; V_9 < V_295 ; ++ V_9 ) {
V_11 = F_127 ( V_300 , V_298 [ V_9 ] , 0 , & V_39 ) ;
if ( V_11 < 0 ) {
F_2 ( V_2 , L_35 , V_298 [ V_9 ] ) ;
return V_11 ;
}
V_167 [ V_9 ] . V_166 = V_11 ;
V_167 [ V_9 ] . V_168 = ! ( V_39 & V_303 ) ;
}
return 0 ;
}
static int F_128 ( struct V_23 * V_30 , struct V_1 * V_2 )
{
struct V_299 * V_300 = V_2 -> V_301 ;
struct V_299 * V_304 ;
struct V_305 V_306 ;
int V_11 ;
if ( ! V_300 ) {
F_2 ( V_2 , L_36 ) ;
return - V_13 ;
}
V_11 = F_129 ( V_300 , L_37 ,
& V_30 -> V_60 ) ;
if ( V_11 < 0 ) {
V_30 -> V_60 = V_307 ;
F_130 ( V_2 , L_38 ,
V_30 -> V_60 ) ;
}
V_11 = F_126 ( V_30 -> V_167 , V_2 ) ;
if ( V_11 < 0 )
return V_11 ;
V_304 = F_131 ( V_300 , NULL ) ;
if ( ! V_304 ) {
F_2 ( V_2 , L_39 ,
V_300 -> V_308 ) ;
return - V_13 ;
}
V_11 = F_132 ( F_133 ( V_304 ) , & V_306 ) ;
F_134 ( V_304 ) ;
if ( V_11 )
return V_11 ;
V_30 -> V_128 = V_306 . V_128 ;
switch ( V_30 -> V_128 ) {
case V_129 :
V_30 -> V_132 = V_306 . V_309 . V_310 . V_311 ;
break;
case V_312 :
break;
default:
F_2 ( V_2 , L_40 ,
V_300 -> V_308 ) ;
return - V_13 ;
}
return 0 ;
}
static int F_135 ( struct V_23 * V_30 ,
struct V_32 * V_33 )
{
struct V_19 * V_25 ;
int V_11 ;
V_25 = & V_30 -> V_29 ;
F_136 ( V_25 , & V_313 ) ;
V_25 -> V_314 = V_315 ;
F_137 ( V_25 , V_30 ) ;
snprintf ( V_25 -> V_246 , sizeof( V_25 -> V_246 ) , L_41 ,
F_138 ( V_33 -> V_44 ) , V_33 -> V_31 ) ;
V_25 -> V_316 = & V_317 ;
V_25 -> V_39 |= V_318 ;
V_30 -> V_319 . V_39 = V_320 ;
V_25 -> V_26 . V_27 = V_28 ;
V_11 = F_139 ( & V_25 -> V_26 , V_321 , & V_30 -> V_319 ) ;
if ( V_11 < 0 )
goto V_133;
V_25 = & V_30 -> V_25 ;
F_140 ( V_25 , V_33 , & V_322 ) ;
snprintf ( V_25 -> V_246 , sizeof( V_25 -> V_246 ) , L_42 ,
F_138 ( V_33 -> V_44 ) , V_33 -> V_31 ) ;
V_25 -> V_316 = & V_323 ;
V_25 -> V_39 |= V_318 ;
V_30 -> V_324 [ V_201 ] . V_39 = V_325 ;
V_30 -> V_324 [ V_282 ] . V_39 = V_320 ;
V_25 -> V_26 . V_27 = V_326 ;
V_11 = F_139 ( & V_25 -> V_26 , V_327 , V_30 -> V_324 ) ;
if ( ! V_11 )
return 0 ;
F_141 ( & V_30 -> V_29 . V_26 ) ;
V_133:
F_2 ( & V_33 -> V_2 , L_43 , V_25 -> V_246 ) ;
return V_11 ;
}
static int F_142 ( struct V_23 * V_30 )
{
struct V_32 * V_33 = F_10 ( & V_30 -> V_25 ) ;
int V_11 ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_169 ; V_9 ++ )
V_30 -> V_170 [ V_9 ] . V_328 = V_329 [ V_9 ] ;
V_11 = F_143 ( & V_33 -> V_2 , V_169 ,
V_30 -> V_170 ) ;
if ( V_11 < 0 )
F_15 ( V_33 , L_44 ) ;
return V_11 ;
}
static int F_144 ( struct V_32 * V_33 ,
const struct V_330 * V_57 )
{
struct V_23 * V_30 ;
int V_11 ;
V_30 = F_3 ( & V_33 -> V_2 , sizeof( * V_30 ) , V_15 ) ;
if ( ! V_30 )
return - V_16 ;
F_145 ( & V_30 -> V_183 ) ;
V_30 -> V_146 = V_238 ;
V_30 -> V_149 = V_238 ;
V_30 -> V_148 = V_238 ;
V_11 = F_128 ( V_30 , & V_33 -> V_2 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_135 ( V_30 , V_33 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_124 ( V_30 ) ;
if ( V_11 < 0 )
goto V_331;
V_11 = F_142 ( V_30 ) ;
if ( V_11 < 0 )
goto V_331;
V_30 -> clock = F_146 ( V_30 -> V_25 . V_2 , V_332 ) ;
if ( F_70 ( V_30 -> clock ) ) {
V_11 = - V_333 ;
goto V_331;
}
V_11 = F_63 ( V_30 ) ;
if ( V_11 < 0 ) {
V_11 = - V_333 ;
goto V_331;
}
F_72 ( V_30 ) ;
V_11 = F_118 ( V_30 ) ;
F_69 ( V_30 ) ;
if ( V_11 < 0 )
goto V_331;
V_11 = F_109 ( V_30 ) ;
if ( V_11 < 0 )
goto V_331;
V_11 = F_147 ( & V_30 -> V_25 ) ;
if ( V_11 < 0 )
goto V_334;
return 0 ;
V_334:
F_116 ( V_30 -> V_25 . V_279 ) ;
V_331:
F_141 ( & V_30 -> V_25 . V_26 ) ;
F_141 ( & V_30 -> V_29 . V_26 ) ;
return V_11 ;
}
static int F_148 ( struct V_32 * V_33 )
{
struct V_19 * V_25 = F_149 ( V_33 ) ;
struct V_23 * V_30 = F_8 ( V_25 ) ;
F_150 ( V_25 ) ;
F_116 ( V_25 -> V_279 ) ;
F_141 ( & V_25 -> V_26 ) ;
V_25 = & V_30 -> V_29 ;
F_123 ( V_25 ) ;
F_141 ( & V_25 -> V_26 ) ;
return 0 ;
}
