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
if ( V_7 -> V_16 [ V_9 ] . V_17 + V_8 <= V_10 )
continue;
F_2 ( V_2 , L_4 , V_9 ) ;
return - V_13 ;
}
* V_4 = V_7 ;
return 0 ;
}
static inline struct V_18 * F_5 ( struct V_19 * V_20 )
{
return & F_6 ( V_20 -> V_21 , struct V_22 , V_23 . V_21 ) -> V_24 ;
}
static inline bool F_7 ( struct V_18 * V_24 )
{
return V_24 -> V_25 . type == V_26 ;
}
static inline struct V_22 * F_8 ( struct V_18 * V_24 )
{
if ( F_7 ( V_24 ) )
return F_6 ( V_24 , struct V_22 , V_27 ) ;
else
return F_6 ( V_24 , struct V_22 , V_24 ) ;
}
static T_3 F_9 ( struct V_22 * V_28 , T_3 V_29 )
{
struct V_30 * V_31 = F_10 ( & V_28 -> V_24 ) ;
T_4 V_32 , V_33 ;
T_3 V_34 ;
struct V_35 V_36 [] = {
{ . V_29 = V_31 -> V_29 , . V_37 = 0 ,
. V_38 = 2 , . V_39 = ( V_40 * ) & V_32 } ,
{ . V_29 = V_31 -> V_29 , . V_37 = V_41 ,
. V_38 = 2 , . V_39 = ( V_40 * ) & V_33 } ,
} ;
int V_11 ;
if ( V_28 -> error )
return 0 ;
V_32 = F_11 ( V_29 ) ;
V_11 = F_12 ( V_31 -> V_42 , V_36 , 2 ) ;
V_34 = F_13 ( V_33 ) ;
F_14 ( 3 , V_43 , V_31 , L_5 , V_29 , V_34 ) ;
if ( V_11 != 2 ) {
F_15 ( V_31 , L_6 , V_11 ) ;
V_28 -> error = V_11 ;
}
return V_34 ;
}
static void F_16 ( struct V_22 * V_28 , T_3 V_29 , T_3 V_44 )
{
V_40 V_39 [ 4 ] = { V_29 >> 8 , V_29 & 0xFF , V_44 >> 8 , V_44 & 0xFF } ;
struct V_30 * V_31 = F_10 ( & V_28 -> V_24 ) ;
int V_11 ;
if ( V_28 -> error )
return;
V_11 = F_17 ( V_31 , V_39 , 4 ) ;
F_14 ( 3 , V_43 , V_31 , L_7 , V_29 , V_44 ) ;
if ( V_11 != 4 ) {
F_15 ( V_31 , L_8 , V_11 ) ;
V_28 -> error = V_11 ;
}
}
static T_3 F_18 ( struct V_22 * V_28 , T_3 V_29 )
{
F_16 ( V_28 , V_45 , V_29 ) ;
return F_9 ( V_28 , V_46 ) ;
}
static void F_19 ( struct V_22 * V_28 , T_3 V_29 , T_3 V_44 )
{
F_16 ( V_28 , V_47 , V_29 ) ;
F_16 ( V_28 , V_46 , V_44 ) ;
}
static void F_20 ( struct V_22 * V_28 , T_3 V_29 ,
T_3 V_5 , const T_3 * V_16 )
{
struct V_30 * V_31 = F_10 ( & V_28 -> V_24 ) ;
T_4 V_39 [ 65 ] ;
F_16 ( V_28 , V_47 , V_29 ) ;
if ( V_28 -> error )
return;
F_14 ( 3 , V_43 , V_31 , L_9 , V_5 ,
F_21 ( 2 * V_5 , 64 ) , V_16 ) ;
V_39 [ 0 ] = F_22 ( V_46 ) ;
while ( V_5 > 0 ) {
int V_48 = F_23 ( int , V_5 , F_24 ( V_39 ) - 1 ) ;
int V_11 , V_9 ;
for ( V_9 = 1 ; V_9 <= V_48 ; ++ V_9 )
V_39 [ V_9 ] = F_11 ( * V_16 ++ ) ;
V_9 *= 2 ;
V_11 = F_17 ( V_31 , ( char * ) V_39 , V_9 ) ;
if ( V_11 != V_9 ) {
F_15 ( V_31 , L_10 , V_11 ) ;
V_28 -> error = V_11 ;
break;
}
V_5 -= V_48 ;
}
}
static void F_25 ( struct V_22 * V_28 , const T_3 * V_49 )
{
int V_5 ;
while ( ( V_5 = * V_49 ++ ) ) {
T_3 V_29 = * V_49 ++ ;
-- V_5 ;
F_20 ( V_28 , V_29 , V_5 , V_49 ) ;
V_49 += V_5 ;
}
}
static void F_26 ( struct V_22 * V_28 , int V_50 , T_3 V_29 )
{
unsigned long V_10 = V_51 + F_27 ( V_50 ) ;
T_3 V_52 ;
F_19 ( V_28 , V_29 , 1 ) ;
do {
V_52 = F_18 ( V_28 , V_29 ) ;
if ( V_28 -> error || ! V_52 )
return;
F_28 ( 5000 , 10000 ) ;
} while ( F_29 ( V_10 ) );
F_15 ( & V_28 -> V_24 , L_11 , V_29 ) ;
V_28 -> error = - V_53 ;
}
static T_3 * F_30 ( struct V_22 * V_28 , T_3 V_54 )
{
struct V_3 * V_4 = V_28 -> V_4 ;
T_3 * V_6 ;
int V_9 ;
if ( V_4 == NULL )
return NULL ;
V_6 = V_4 -> V_6 + 2 * V_4 -> V_5 ;
for ( V_9 = 0 ; V_9 < V_4 -> V_5 ; ++ V_9 ) {
if ( V_4 -> V_16 [ V_9 ] . V_55 == V_54 )
return V_6 + V_4 -> V_16 [ V_9 ] . V_17 ;
}
return NULL ;
}
static void F_31 ( struct V_22 * V_28 )
{
T_3 * V_16 = F_30 ( V_28 , V_56 ) ;
if ( V_16 )
F_25 ( V_28 , V_16 ) ;
}
static void F_32 ( struct V_22 * V_28 )
{
unsigned long V_57 = V_28 -> V_58 / 1000 ;
T_3 V_59 ;
static const T_3 V_60 [] = {
F_33 ( V_61 ,
V_62 , V_63 , 0 ,
V_64 / 4 , V_65 / 4 , V_66 / 4 ,
V_67 / 4 , V_65 / 4 , V_66 / 4 ) ,
F_33 ( V_68 , 1 ) ,
0
} ;
F_34 ( V_28 , V_69 , V_57 & 0xffff , V_57 >> 16 ) ;
F_25 ( V_28 , V_60 ) ;
F_26 ( V_28 , 250 , V_70 ) ;
V_59 = F_18 ( V_28 , V_71 ) ;
if ( ! V_28 -> error && V_59 ) {
F_15 ( & V_28 -> V_24 , L_12 , V_59 ) ;
V_28 -> error = - V_13 ;
}
}
static void F_35 ( struct V_22 * V_28 )
{
T_3 * V_16 = F_30 ( V_28 , V_72 ) ;
if ( V_16 )
F_25 ( V_28 , V_16 ) ;
}
static void F_36 ( struct V_22 * V_28 )
{
T_3 * V_16 = F_30 ( V_28 , V_73 ) ;
if ( ! V_16 )
return;
F_16 ( V_28 , V_74 , V_75 ) ;
F_25 ( V_28 , V_16 ) ;
F_16 ( V_28 , V_74 , V_76 ) ;
}
static void F_37 ( struct V_22 * V_28 )
{
F_19 ( V_28 , V_77 , 1 ) ;
if ( V_28 -> V_78 ) {
F_19 ( V_28 , V_79 , 1 ) ;
F_19 ( V_28 , V_80 , 1 ) ;
}
F_26 ( V_28 , 500 , V_81 ) ;
}
static void F_38 ( struct V_22 * V_28 )
{
T_3 V_82 = V_28 -> V_23 . V_83 -> V_44 | ( V_28 -> V_23 . V_83 -> V_44 << 1 ) ;
F_19 ( V_28 , F_39 ( 0 ) , V_82 ) ;
if ( V_28 -> V_84 )
F_37 ( V_28 ) ;
}
static void F_40 ( struct V_22 * V_28 , T_3 V_85 , bool V_86 )
{
T_3 V_87 , V_88 ;
if ( ! V_28 -> V_89 )
V_87 = F_18 ( V_28 , V_90 ) ;
else
V_87 = V_28 -> V_91 ;
V_88 = V_86 ? ( V_87 | V_85 ) : ( V_87 & ~ V_85 ) ;
if ( V_88 != V_87 )
F_19 ( V_28 , V_90 , V_88 ) ;
if ( V_28 -> error )
return;
V_28 -> V_89 = 1 ;
V_28 -> V_91 = V_88 ;
}
static void F_41 ( struct V_22 * V_28 , int V_92 )
{
struct V_93 * V_23 = & V_28 -> V_23 ;
if ( ! V_92 )
F_34 ( V_28 , V_94 ,
V_23 -> V_95 -> V_44 , 1 ,
V_96 , 1 ,
V_23 -> V_97 -> V_44 , 1 ,
1 ) ;
F_40 ( V_28 , V_98 , V_92 ) ;
}
static void F_42 ( struct V_22 * V_28 , int V_99 )
{
unsigned int time = V_99 / 10 ;
F_34 ( V_28 , V_100 ,
time & 0xffff , time >> 16 , 1 ) ;
}
static void F_43 ( struct V_22 * V_28 , int V_101 )
{
F_34 ( V_28 , V_102 , V_101 , 1 ) ;
}
static void F_44 ( struct V_22 * V_28 , int V_103 )
{
if ( V_103 == V_104 ) {
F_40 ( V_28 , V_105 | V_106 , true ) ;
} else {
unsigned int V_107 = V_28 -> V_23 . V_99 -> V_44 ;
F_42 ( V_28 , V_107 ) ;
F_43 ( V_28 , V_28 -> V_23 . V_101 -> V_44 ) ;
F_40 ( V_28 , V_105 | V_106 , false ) ;
}
}
static void F_45 ( struct V_22 * V_28 , int V_108 )
{
if ( V_108 == V_109 ) {
F_40 ( V_28 , V_110 , true ) ;
} else {
F_34 ( V_28 , V_111 , V_108 , 1 ) ;
F_40 ( V_28 , V_110 , false ) ;
}
}
static void F_46 ( struct V_22 * V_28 , int V_44 )
{
static const T_3 V_112 [] = {
[ V_113 ] = 0 ,
[ V_114 ] = 1 ,
[ V_115 ] = 2 ,
[ V_116 ] = 3 ,
[ V_117 ] = 4 ,
[ V_118 ] = 5 ,
} ;
F_19 ( V_28 , V_119 , V_112 [ V_44 ] ) ;
}
static int F_47 ( struct V_120 * V_121 )
{
int V_9 , V_31 = - 1 ;
for ( V_9 = 0 ; V_9 < F_24 ( V_122 ) ; V_9 ++ ) {
if ( V_121 -> V_123 != V_122 [ V_9 ] . V_123 )
continue;
if ( V_121 -> V_124 == V_122 [ V_9 ] . V_124 )
return V_9 ;
if ( V_31 < 0 )
V_31 = V_9 ;
}
return ( V_31 < 0 ) ? 0 : V_31 ;
}
static int F_48 ( struct V_22 * V_28 )
{
int V_11 = V_28 -> error ;
V_28 -> error = 0 ;
return V_11 ;
}
static int F_49 ( struct V_22 * V_28 )
{
T_3 V_125 ;
if ( V_28 -> V_126 == V_127 )
V_125 = V_128 ;
else
V_125 = 0 ;
F_34 ( V_28 , V_129 ,
V_28 -> V_130 , V_125 , 1 ) ;
return F_48 ( V_28 ) ;
}
static T_3 F_50 ( struct V_22 * V_28 )
{
T_3 V_131 = F_18 ( V_28 , V_132 ) ;
if ( V_131 )
F_19 ( V_28 , V_132 , 0 ) ;
return V_131 ;
}
static void F_51 ( struct V_22 * V_28 , T_3 V_133 )
{
F_19 ( V_28 , F_52 ( 0 ) , V_133 ) ;
F_37 ( V_28 ) ;
}
static void F_53 ( struct V_22 * V_28 )
{
T_3 V_131 , V_133 ;
int V_48 ;
V_133 = F_18 ( V_28 , V_134 ) ;
if ( V_28 -> error )
return;
for ( V_48 = 5 ; V_48 > 0 ; -- V_48 ) {
F_51 ( V_28 , V_133 ) ;
V_131 = F_50 ( V_28 ) ;
if ( V_28 -> error )
return;
switch ( V_131 ) {
case V_135 :
++ V_133 ;
break;
case 0 :
V_28 -> V_133 = V_133 ;
F_54 ( & V_28 -> V_24 ,
L_13 , V_133 ) ;
return;
default:
F_15 ( & V_28 -> V_24 ,
L_14 , V_131 ) ;
V_28 -> error = - V_13 ;
}
}
F_15 ( & V_28 -> V_24 , L_15 ) ;
V_28 -> error = - V_136 ;
}
static void F_55 ( struct V_22 * V_28 )
{
T_3 V_131 ;
V_131 = F_50 ( V_28 ) ;
if ( V_28 -> error )
return;
switch ( V_131 ) {
case 0 :
V_28 -> V_137 = 1 ;
return;
case V_135 :
F_53 ( V_28 ) ;
if ( ! V_28 -> error )
V_28 -> V_137 = 1 ;
return;
default:
F_15 ( & V_28 -> V_24 ,
L_16 , V_131 ) ;
V_28 -> error = - V_13 ;
}
}
static void F_56 ( struct V_138 * V_33 , const struct V_138 * V_108 ,
const struct V_138 * V_48 ,
const struct V_138 * V_8 )
{
V_33 -> V_139 = V_108 -> V_139 * V_48 -> V_140 / V_8 -> V_140 ;
V_33 -> V_141 = V_108 -> V_141 * V_48 -> V_142 / V_8 -> V_142 ;
V_33 -> V_140 = V_108 -> V_140 * V_48 -> V_140 / V_8 -> V_140 ;
V_33 -> V_142 = V_108 -> V_142 * V_48 -> V_142 / V_8 -> V_142 ;
}
static int F_57 ( struct V_22 * V_28 )
{
struct V_138 * V_143 , V_33 ;
T_3 V_131 ;
int V_11 ;
V_143 = & V_28 -> V_144 ;
F_34 ( V_28 , V_145 , V_143 -> V_140 , V_143 -> V_142 ,
V_143 -> V_139 , V_143 -> V_141 ) ;
F_56 ( & V_33 , & V_28 -> V_146 , & V_28 -> V_144 ,
& V_28 -> V_147 ) ;
F_34 ( V_28 , V_148 , V_33 . V_140 , V_33 . V_142 ,
V_33 . V_139 , V_33 . V_141 ) ;
F_26 ( V_28 , 500 , V_79 ) ;
F_26 ( V_28 , 500 , V_80 ) ;
V_131 = F_50 ( V_28 ) ;
V_11 = F_48 ( V_28 ) ;
if ( V_11 < 0 )
return V_11 ;
switch ( V_131 ) {
case 0 :
break;
case V_135 :
F_51 ( V_28 , V_149 ) ;
V_131 = F_50 ( V_28 ) ;
V_11 = F_48 ( V_28 ) ;
if ( V_11 < 0 )
return V_11 ;
if ( V_131 ) {
F_15 ( & V_28 -> V_24 ,
L_17 , V_131 ) ;
V_28 -> error = - V_13 ;
}
F_51 ( V_28 , V_28 -> V_150 ) ;
F_55 ( V_28 ) ;
break;
default:
F_15 ( & V_28 -> V_24 , L_18 , V_131 ) ;
return - V_13 ;
}
if ( ! V_28 -> V_137 )
return 0 ;
V_143 = & V_28 -> V_146 ;
F_34 ( V_28 , F_58 ( 0 ) , V_143 -> V_140 , V_143 -> V_142 ) ;
F_51 ( V_28 , V_28 -> V_150 ) ;
F_55 ( V_28 ) ;
return F_48 ( V_28 ) ;
}
static void F_59 ( struct V_22 * V_28 )
{
T_3 V_151 = V_122 [ V_28 -> V_152 ] . V_153 ;
struct V_138 * V_33 = & V_28 -> V_146 ;
F_34 ( V_28 , F_58 ( 0 ) ,
V_33 -> V_140 , V_33 -> V_142 , V_151 ,
V_66 >> 2 , V_65 >> 2 ,
V_154 , V_155 ,
V_156 , V_157 ,
V_28 -> V_150 , V_158 ) ;
F_37 ( V_28 ) ;
F_55 ( V_28 ) ;
}
static void F_60 ( struct V_22 * V_28 , int V_55 )
{
F_16 ( V_28 , V_159 , 800 ) ;
F_16 ( V_28 , V_160 , 511 ) ;
F_16 ( V_28 , V_161 , 0 ) ;
F_16 ( V_28 , V_162 , V_55 ) ;
}
static void F_61 ( struct V_22 * V_28 , int V_55 )
{
struct V_163 * V_164 = & V_28 -> V_165 [ V_55 ] ;
F_62 ( V_164 -> V_164 , V_164 -> V_166 ) ;
}
static void F_63 ( struct V_22 * V_28 , int V_55 )
{
struct V_163 * V_164 = & V_28 -> V_165 [ V_55 ] ;
F_62 ( V_164 -> V_164 , ! V_164 -> V_166 ) ;
}
static int F_64 ( struct V_22 * V_28 )
{
int V_11 ;
V_11 = F_65 ( V_167 , V_28 -> V_168 ) ;
if ( V_11 < 0 )
goto V_131;
V_11 = F_66 ( V_28 -> clock , V_28 -> V_58 ) ;
if ( V_11 < 0 )
goto V_169;
V_11 = F_67 ( V_28 -> clock ) ;
if ( V_11 < 0 )
goto V_169;
F_14 ( 1 , V_43 , & V_28 -> V_24 , L_19 ,
F_68 ( V_28 -> clock ) ) ;
F_63 ( V_28 , V_170 ) ;
F_28 ( 50 , 100 ) ;
F_63 ( V_28 , V_171 ) ;
return 0 ;
V_169:
F_69 ( V_167 , V_28 -> V_168 ) ;
V_131:
F_15 ( & V_28 -> V_24 , L_20 , V_172 , V_11 ) ;
return V_11 ;
}
static int F_70 ( struct V_22 * V_28 )
{
int V_11 ;
V_28 -> V_84 = 0 ;
V_28 -> V_137 = 0 ;
V_28 -> V_78 = 0 ;
F_61 ( V_28 , V_171 ) ;
F_61 ( V_28 , V_170 ) ;
if ( ! F_71 ( V_28 -> clock ) )
F_72 ( V_28 -> clock ) ;
V_11 = F_69 ( V_167 ,
V_28 -> V_168 ) ;
if ( V_11 < 0 )
F_15 ( & V_28 -> V_24 , L_21 ) ;
return 0 ;
}
static void F_73 ( struct V_22 * V_28 )
{
F_16 ( V_28 , V_173 , V_75 ) ;
F_16 ( V_28 , V_174 , 0 ) ;
F_16 ( V_28 , V_175 , 1 ) ;
F_16 ( V_28 , V_176 , V_76 ) ;
F_16 ( V_28 , V_74 , V_76 ) ;
}
static void F_74 ( struct V_22 * V_28 )
{
V_28 -> V_152 = 0 ;
V_28 -> V_150 = 10000 / 15 ;
V_28 -> V_133 = V_28 -> V_150 ;
V_28 -> V_89 = 0 ;
}
static int F_75 ( struct V_22 * V_28 )
{
struct V_30 * V_31 = F_10 ( & V_28 -> V_24 ) ;
const struct V_177 * V_4 ;
int V_11 ;
V_11 = F_76 ( & V_4 , V_178 , & V_31 -> V_2 ) ;
if ( V_11 < 0 ) {
F_77 ( & V_31 -> V_2 , L_22 ,
V_178 ) ;
return V_11 ;
}
V_11 = F_1 ( & V_31 -> V_2 , & V_28 -> V_4 , V_4 -> V_179 / 2 ,
( T_2 * ) V_4 -> V_6 ) ;
F_78 ( V_4 ) ;
return V_11 ;
}
static int F_79 ( struct V_18 * V_24 , int V_180 )
{
struct V_22 * V_28 = F_8 ( V_24 ) ;
int V_11 = 0 ;
F_80 ( & V_28 -> V_181 ) ;
if ( ! V_180 != V_28 -> V_182 )
goto V_183;
if ( V_180 ) {
if ( V_28 -> V_4 == NULL )
F_75 ( V_28 ) ;
F_74 ( V_28 ) ;
V_11 = F_64 ( V_28 ) ;
if ( V_11 < 0 )
goto V_183;
F_73 ( V_28 ) ;
F_31 ( V_28 ) ;
F_16 ( V_28 , V_184 , 1 ) ;
F_32 ( V_28 ) ;
V_11 = F_49 ( V_28 ) ;
if ( V_11 < 0 )
goto V_183;
F_36 ( V_28 ) ;
F_35 ( V_28 ) ;
V_11 = F_48 ( V_28 ) ;
if ( ! V_11 )
V_28 -> V_182 ++ ;
} else {
F_70 ( V_28 ) ;
V_28 -> V_182 -- ;
}
V_183:
F_81 ( & V_28 -> V_181 ) ;
if ( ! V_11 && V_180 )
V_11 = F_82 ( & V_28 -> V_23 . V_21 ) ;
return V_11 ;
}
static void F_83 ( struct V_22 * V_28 , int V_86 )
{
F_34 ( V_28 , V_185 , V_86 , 1 ) ;
}
static int F_84 ( struct V_18 * V_24 , int V_180 )
{
struct V_22 * V_28 = F_8 ( V_24 ) ;
int V_11 ;
F_80 ( & V_28 -> V_181 ) ;
if ( V_28 -> V_84 == ! ! V_180 ) {
V_11 = 0 ;
goto V_183;
}
if ( V_180 ) {
F_59 ( V_28 ) ;
V_11 = F_57 ( V_28 ) ;
if ( V_11 < 0 )
goto V_183;
F_83 ( V_28 , 1 ) ;
F_16 ( V_28 , 0xb0cc , 0x000b ) ;
} else {
F_83 ( V_28 , 0 ) ;
}
V_11 = F_48 ( V_28 ) ;
if ( ! V_11 )
V_28 -> V_84 = ! V_28 -> V_84 ;
V_183:
F_81 ( & V_28 -> V_181 ) ;
return V_11 ;
}
static int F_85 ( struct V_18 * V_24 ,
struct V_186 * V_187 )
{
struct V_22 * V_28 = F_8 ( V_24 ) ;
F_80 ( & V_28 -> V_181 ) ;
V_187 -> V_188 . V_189 = V_28 -> V_133 ;
V_187 -> V_188 . V_190 = 10000 ;
F_81 ( & V_28 -> V_181 ) ;
return 0 ;
}
static void F_86 ( struct V_22 * V_28 ,
struct V_186 * V_187 )
{
struct V_191 * V_9 = & V_187 -> V_188 ;
if ( V_187 -> V_188 . V_190 == 0 )
V_28 -> V_150 = V_149 ;
else
V_28 -> V_150 = F_87 ( V_192 ,
V_9 -> V_189 * 10000 / V_9 -> V_190 ,
V_158 ,
V_149 ) ;
V_28 -> V_133 = V_28 -> V_150 ;
if ( V_28 -> V_137 ) {
F_51 ( V_28 , V_28 -> V_150 ) ;
F_55 ( V_28 ) ;
}
* V_9 = (struct V_191 ) { V_28 -> V_133 , 10000 } ;
if ( V_28 -> V_133 == V_28 -> V_150 )
F_54 ( & V_28 -> V_24 , L_23 ,
V_28 -> V_133 ) ;
}
static int F_88 ( struct V_18 * V_24 ,
struct V_186 * V_187 )
{
struct V_22 * V_28 = F_8 ( V_24 ) ;
F_80 ( & V_28 -> V_181 ) ;
F_86 ( V_28 , V_187 ) ;
F_81 ( & V_28 -> V_181 ) ;
return 0 ;
}
static int F_89 ( struct V_18 * V_24 ,
struct V_193 * V_194 ,
struct V_195 * V_196 )
{
if ( V_196 -> V_197 > V_149 - V_158 ||
V_196 -> V_198 != V_199 )
return - V_13 ;
F_90 ( & V_196 -> V_140 , V_200 ,
V_201 , 1 ,
& V_196 -> V_142 , V_202 ,
V_203 , 1 , 0 ) ;
V_196 -> V_188 . V_189 = V_158 + V_196 -> V_197 ;
V_196 -> V_188 . V_190 = 10000 ;
return 0 ;
}
static int F_91 ( struct V_18 * V_24 ,
struct V_193 * V_194 ,
struct V_204 * V_124 )
{
if ( V_124 -> V_198 == V_199 ) {
if ( V_124 -> V_197 > 0 )
return - V_13 ;
V_124 -> V_124 = V_205 ;
return 0 ;
}
if ( V_124 -> V_197 >= F_24 ( V_122 ) )
return - V_13 ;
V_124 -> V_124 = V_122 [ V_124 -> V_197 ] . V_124 ;
return 0 ;
}
static int F_92 ( struct V_18 * V_24 ,
struct V_193 * V_194 ,
struct V_206 * V_207 )
{
int V_9 ;
if ( V_207 -> V_197 > 0 )
return - V_13 ;
if ( V_207 -> V_198 == V_199 ) {
V_207 -> V_124 = V_205 ;
V_207 -> V_208 = V_201 ;
V_207 -> V_209 = V_201 ;
V_207 -> V_210 = V_203 ;
V_207 -> V_211 = V_203 ;
return 0 ;
}
V_9 = F_24 ( V_122 ) ;
while ( -- V_9 )
if ( V_207 -> V_124 == V_122 [ V_9 ] . V_124 )
break;
V_207 -> V_124 = V_122 [ V_9 ] . V_124 ;
V_207 -> V_208 = V_200 ;
V_207 -> V_209 = V_201 ;
V_207 -> V_211 = V_202 ;
V_207 -> V_210 = V_203 ;
return 0 ;
}
static void F_93 ( struct V_120 * V_121 )
{
V_121 -> V_140 = V_201 ;
V_121 -> V_142 = V_203 ;
V_121 -> V_124 = V_205 ;
V_121 -> V_123 = V_212 ;
V_121 -> V_213 = V_214 ;
}
static int F_94 ( struct V_120 * V_121 )
{
int V_152 ;
F_90 ( & V_121 -> V_140 , V_200 ,
V_201 , 1 ,
& V_121 -> V_142 , V_202 ,
V_203 , 1 , 0 ) ;
V_152 = F_47 ( V_121 ) ;
V_121 -> V_123 = V_122 [ V_152 ] . V_123 ;
V_121 -> V_124 = V_122 [ V_152 ] . V_124 ;
V_121 -> V_213 = V_214 ;
return V_152 ;
}
static int F_95 ( struct V_18 * V_24 , struct V_193 * V_194 ,
struct V_215 * V_216 )
{
struct V_22 * V_28 = F_8 ( V_24 ) ;
const struct V_217 * V_152 ;
struct V_120 * V_121 ;
if ( V_216 -> V_218 == V_219 ) {
V_121 = F_96 ( V_194 , V_216 -> V_198 ) ;
V_216 -> V_220 = * V_121 ;
return 0 ;
}
V_121 = & V_216 -> V_220 ;
if ( V_216 -> V_198 == V_199 ) {
F_93 ( V_121 ) ;
return 0 ;
}
V_121 -> V_213 = V_214 ;
F_80 ( & V_28 -> V_181 ) ;
V_152 = & V_122 [ V_28 -> V_152 ] ;
V_121 -> V_140 = V_28 -> V_146 . V_140 ;
V_121 -> V_142 = V_28 -> V_146 . V_142 ;
V_121 -> V_124 = V_152 -> V_124 ;
V_121 -> V_123 = V_152 -> V_123 ;
F_81 ( & V_28 -> V_181 ) ;
return 0 ;
}
static int F_97 ( struct V_18 * V_24 , struct V_193 * V_194 ,
struct V_215 * V_216 )
{
struct V_120 * V_121 = & V_216 -> V_220 ;
struct V_22 * V_28 = F_8 ( V_24 ) ;
const struct V_217 * V_152 ;
int V_11 = 0 ;
V_121 -> V_213 = V_214 ;
if ( V_216 -> V_218 == V_219 ) {
* F_96 ( V_194 , V_216 -> V_198 ) = * V_121 ;
return 0 ;
}
if ( V_216 -> V_198 == V_199 ) {
F_93 ( V_121 ) ;
return 0 ;
}
F_80 ( & V_28 -> V_181 ) ;
if ( V_28 -> V_84 ) {
F_81 ( & V_28 -> V_181 ) ;
return - V_221 ;
}
V_28 -> V_152 = F_94 ( V_121 ) ;
V_152 = & V_122 [ V_28 -> V_152 ] ;
V_121 -> V_124 = V_152 -> V_124 ;
V_121 -> V_123 = V_152 -> V_123 ;
V_121 -> V_140 = V_28 -> V_146 . V_140 ;
V_121 -> V_142 = V_28 -> V_146 . V_142 ;
F_81 ( & V_28 -> V_181 ) ;
return V_11 ;
}
static enum V_222 F_98 ( V_192 V_198 , V_192 V_223 )
{
switch ( V_223 ) {
case V_224 :
return V_198 ? V_225 : V_226 ;
case V_227 :
return V_198 ? V_228 : V_229 ;
case V_230 :
return V_198 ? V_231 : V_229 ;
case V_232 :
return V_198 ? V_231 : V_225 ;
default:
return V_231 ;
}
}
static int F_99 ( V_192 V_223 )
{
return V_223 == V_224 ||
V_223 == V_230 ;
}
static int F_100 ( struct V_18 * V_24 ,
struct V_193 * V_194 ,
struct V_233 * V_234 )
{
static enum V_222 V_235 ;
struct V_22 * V_28 = F_8 ( V_24 ) ;
V_235 = F_98 ( V_234 -> V_198 , V_234 -> V_223 ) ;
switch ( V_235 ) {
case V_231 :
return - V_13 ;
case V_226 :
V_234 -> V_33 = V_236 ;
return 0 ;
default:
break;
}
if ( V_234 -> V_218 == V_219 ) {
if ( V_235 == V_225 )
V_234 -> V_33 = * F_101 ( V_194 , V_234 -> V_198 ) ;
else
V_234 -> V_33 = * F_102 ( V_194 , V_234 -> V_198 ) ;
return 0 ;
}
F_80 ( & V_28 -> V_181 ) ;
switch ( V_235 ) {
case V_229 :
V_234 -> V_33 = V_28 -> V_144 ;
break;
case V_225 :
V_234 -> V_33 = V_28 -> V_147 ;
break;
case V_228 :
V_234 -> V_33 = V_28 -> V_146 ;
break;
default:
break;
}
if ( F_99 ( V_234 -> V_223 ) ) {
V_234 -> V_33 . V_139 = 0 ;
V_234 -> V_33 . V_141 = 0 ;
}
F_81 ( & V_28 -> V_181 ) ;
return 0 ;
}
static void F_103 ( V_192 * V_237 , V_192 * V_38 , V_192 V_238 )
{
if ( * V_38 > V_238 )
* V_38 = V_238 ;
if ( * V_237 + * V_38 > V_238 )
* V_237 = V_238 - * V_38 ;
* V_237 &= ~ 1 ;
* V_38 &= ~ 1 ;
if ( * V_38 < V_200 )
* V_38 = V_200 ;
}
static void F_104 ( struct V_138 * V_33 , V_192 V_140 , V_192 V_142 )
{
F_103 ( & V_33 -> V_139 , & V_33 -> V_140 , V_140 ) ;
F_103 ( & V_33 -> V_141 , & V_33 -> V_142 , V_142 ) ;
}
static void F_105 ( struct V_138 * * V_239 ,
enum V_222 V_240 ,
struct V_138 * V_108 )
{
struct V_138 * V_33 , * V_241 ;
enum V_222 V_9 = V_240 ;
* V_239 [ V_240 ] = * V_108 ;
do {
V_33 = V_239 [ V_9 ] ;
V_241 = V_239 [ V_9 - 1 ] ;
F_104 ( V_33 , V_241 -> V_140 , V_241 -> V_142 ) ;
} while ( ++ V_9 != V_231 );
* V_108 = * V_239 [ V_240 ] ;
}
static bool F_106 ( const struct V_138 * V_242 ,
const struct V_138 * V_243 )
{
return ! memcmp ( V_242 , V_243 , sizeof( * V_242 ) ) ;
}
static int F_107 ( struct V_18 * V_24 ,
struct V_193 * V_194 ,
struct V_233 * V_234 )
{
static enum V_222 V_235 ;
struct V_22 * V_28 = F_8 ( V_24 ) ;
struct V_138 * * V_239 ;
int V_11 = 0 ;
V_235 = F_98 ( V_234 -> V_198 , V_234 -> V_223 ) ;
if ( V_235 == V_231 || F_99 ( V_234 -> V_223 ) )
return - V_13 ;
if ( V_235 == V_225 ) {
V_234 -> V_33 . V_139 = 0 ;
V_234 -> V_33 . V_141 = 0 ;
}
if ( V_234 -> V_218 == V_219 ) {
V_239 = (struct V_138 * [] ) {
& V_236 ,
F_102 ( V_194 , V_199 ) ,
F_101 ( V_194 , V_199 ) ,
F_102 (fh, PAD_OUT)
} ;
F_105 ( V_239 , V_235 , & V_234 -> V_33 ) ;
return 0 ;
}
V_239 = (struct V_138 * [] ) {
& V_236 ,
& V_28 -> V_144 ,
& V_28 -> V_147 ,
& V_28 -> V_146
} ;
F_80 ( & V_28 -> V_181 ) ;
if ( V_28 -> V_84 ) {
if ( V_235 < V_228 ) {
if ( V_234 -> V_33 . V_140 < V_28 -> V_146 . V_140 )
V_234 -> V_33 . V_140 = V_28 -> V_146 . V_140 ;
if ( V_234 -> V_33 . V_142 < V_28 -> V_146 . V_142 )
V_234 -> V_33 . V_142 = V_28 -> V_146 . V_142 ;
} else {
V_234 -> V_33 . V_140 = V_28 -> V_146 . V_140 ;
V_234 -> V_33 . V_142 = V_28 -> V_146 . V_142 ;
}
}
F_105 ( V_239 , V_235 , & V_234 -> V_33 ) ;
if ( ! F_106 ( & V_28 -> V_144 , & V_236 ) ||
! F_106 ( & V_28 -> V_147 , & V_236 ) )
V_28 -> V_78 = 1 ;
if ( V_28 -> V_84 )
V_11 = F_57 ( V_28 ) ;
F_81 ( & V_28 -> V_181 ) ;
return V_11 ;
}
static int F_108 ( struct V_19 * V_20 )
{
struct V_18 * V_24 = F_5 ( V_20 ) ;
struct V_22 * V_28 = F_8 ( V_24 ) ;
int V_11 ;
F_14 ( 1 , V_43 , V_24 , L_24 , V_20 -> V_244 , V_20 -> V_44 ) ;
F_80 ( & V_28 -> V_181 ) ;
if ( V_28 -> V_182 == 0 )
goto V_245;
switch ( V_20 -> V_55 ) {
case V_246 :
F_41 ( V_28 , V_20 -> V_44 ) ;
break;
case V_247 :
F_19 ( V_28 , V_248 , V_20 -> V_44 ) ;
break;
case V_249 :
F_46 ( V_28 , V_20 -> V_44 ) ;
break;
case V_250 :
F_19 ( V_28 , V_251 , V_20 -> V_44 ) ;
break;
case V_252 :
F_44 ( V_28 , V_20 -> V_44 ) ;
break;
case V_253 :
F_38 ( V_28 ) ;
break;
case V_254 :
F_45 ( V_28 , V_20 -> V_44 ) ;
break;
case V_255 :
F_19 ( V_28 , V_256 , V_20 -> V_44 ) ;
break;
case V_257 :
F_19 ( V_28 , V_258 , V_20 -> V_44 ) ;
break;
case V_259 :
F_19 ( V_28 , F_109 ( 0 ) , V_20 -> V_44 ) ;
if ( V_28 -> V_137 )
F_37 ( V_28 ) ;
break;
case V_260 :
F_60 ( V_28 , V_20 -> V_44 ) ;
break;
}
V_245:
V_11 = F_48 ( V_28 ) ;
F_81 ( & V_28 -> V_181 ) ;
return V_11 ;
}
static int F_110 ( struct V_22 * V_28 )
{
const struct V_261 * V_262 = & V_263 ;
struct V_93 * V_23 = & V_28 -> V_23 ;
struct V_264 * V_265 = & V_23 -> V_21 ;
int V_11 ;
V_11 = F_111 ( V_265 , 16 ) ;
if ( V_11 < 0 ) {
F_15 ( & V_28 -> V_24 , L_25 , V_11 ) ;
return V_11 ;
}
V_23 -> V_92 = F_112 ( V_265 , V_262 , V_246 ,
0 , 1 , 1 , 1 ) ;
V_23 -> V_95 = F_112 ( V_265 , V_262 , V_266 ,
0 , 255 , 1 , V_267 ) ;
V_23 -> V_97 = F_112 ( V_265 , V_262 , V_268 ,
0 , 255 , 1 , V_269 ) ;
F_113 ( 3 , & V_23 -> V_92 , 0 , false ) ;
V_23 -> V_270 = F_112 ( V_265 , V_262 , V_253 , 0 , 1 , 1 , 0 ) ;
V_23 -> V_83 = F_112 ( V_265 , V_262 , V_271 , 0 , 1 , 1 , 0 ) ;
F_114 ( 2 , & V_23 -> V_270 ) ;
V_23 -> V_272 = F_115 ( V_265 , V_262 ,
V_252 ,
V_273 , 0 , V_104 ) ;
V_23 -> V_99 = F_112 ( V_265 , V_262 , V_274 ,
0 , 6000000U , 1 , 100000U ) ;
V_23 -> V_101 = F_112 ( V_265 , V_262 , V_275 ,
0 , 256 , 1 , 256 ) ;
F_113 ( 3 , & V_23 -> V_272 , 0 , false ) ;
F_115 ( V_265 , V_262 , V_254 ,
V_109 , 0 ,
V_109 ) ;
F_115 ( V_265 , V_262 , V_249 ,
V_117 , ~ 0x6f , V_113 ) ;
F_112 ( V_265 , V_262 , V_259 ,
0 , 256 , 1 , 0 ) ;
F_112 ( V_265 , V_262 , V_255 , - 127 , 127 , 1 , 0 ) ;
F_112 ( V_265 , V_262 , V_247 , - 127 , 127 , 1 , 0 ) ;
F_112 ( V_265 , V_262 , V_250 , - 127 , 127 , 1 , 0 ) ;
F_112 ( V_265 , V_262 , V_257 , - 127 , 127 , 1 , 0 ) ;
F_116 ( V_265 , V_262 , V_260 ,
F_24 ( V_276 ) - 1 ,
0 , 0 , V_276 ) ;
if ( V_265 -> error ) {
F_15 ( & V_28 -> V_24 , L_26 ,
V_265 -> error ) ;
V_11 = V_265 -> error ;
F_117 ( V_265 ) ;
return V_11 ;
}
V_28 -> V_24 . V_277 = V_265 ;
return 0 ;
}
static int F_118 ( struct V_18 * V_24 , struct V_193 * V_194 )
{
struct V_120 * V_121 ;
V_121 = F_96 ( V_194 , V_199 ) ;
F_93 ( V_121 ) ;
if ( F_7 ( V_24 ) )
return 0 ;
V_121 = F_96 ( V_194 , V_278 ) ;
V_121 -> V_123 = V_122 [ 0 ] . V_123 ;
V_121 -> V_124 = V_122 [ 0 ] . V_124 ;
V_121 -> V_140 = V_236 . V_140 ;
V_121 -> V_142 = V_236 . V_142 ;
V_121 -> V_213 = V_214 ;
* F_102 ( V_194 , V_199 ) = V_236 ;
* F_101 ( V_194 , V_199 ) = V_236 ;
* F_102 ( V_194 , V_278 ) = V_236 ;
return 0 ;
}
static int F_119 ( struct V_22 * V_28 )
{
T_3 V_279 = 0 , V_280 = 0 , V_281 = 0 ;
int V_11 ;
V_279 = F_18 ( V_28 , V_282 ) ;
V_280 = F_18 ( V_28 , V_283 ) & 0xff ;
V_281 = F_18 ( V_28 , V_284 ) ;
V_11 = F_48 ( V_28 ) ;
if ( V_11 < 0 )
return V_11 ;
F_54 ( & V_28 -> V_24 , L_27 ,
V_279 , V_280 , V_281 ) ;
if ( V_279 != V_285 ) {
F_15 ( & V_28 -> V_24 , L_28 ) ;
return - V_286 ;
}
return 0 ;
}
static int F_120 ( struct V_18 * V_24 )
{
struct V_22 * V_28 = F_8 ( V_24 ) ;
int V_11 ;
V_11 = F_121 ( V_24 -> V_287 , & V_28 -> V_27 ) ;
if ( V_11 < 0 )
F_15 ( V_24 , L_29 ,
V_28 -> V_27 . V_244 ) ;
else
V_11 = F_122 ( & V_28 -> V_27 . V_25 , V_199 ,
& V_28 -> V_24 . V_25 , V_199 ,
V_288 |
V_289 ) ;
return V_11 ;
}
static void F_123 ( struct V_18 * V_24 )
{
struct V_22 * V_28 = F_8 ( V_24 ) ;
F_124 ( & V_28 -> V_27 ) ;
}
static int F_125 ( struct V_22 * V_28 )
{
static const char * const V_244 [] = { L_30 , L_31 } ;
struct V_30 * V_31 = F_10 ( & V_28 -> V_24 ) ;
struct V_163 * V_290 = V_28 -> V_165 ;
int V_11 , V_9 ;
for ( V_9 = 0 ; V_9 < V_291 ; ++ V_9 ) {
int V_37 = V_292 ;
if ( V_290 [ V_9 ] . V_166 )
V_37 |= V_293 ;
V_11 = F_126 ( & V_31 -> V_2 , V_290 [ V_9 ] . V_164 , V_37 , V_244 [ V_9 ] ) ;
if ( V_11 < 0 ) {
F_15 ( V_31 , L_32 , V_244 [ V_9 ] ) ;
return V_11 ;
}
}
return 0 ;
}
static int F_127 ( struct V_163 * V_165 , struct V_1 * V_2 )
{
static const char * const V_294 [] = {
L_33 ,
L_34 ,
} ;
struct V_295 * V_296 = V_2 -> V_297 ;
enum V_298 V_37 ;
int V_11 , V_9 ;
for ( V_9 = 0 ; V_9 < V_291 ; ++ V_9 ) {
V_11 = F_128 ( V_296 , V_294 [ V_9 ] , 0 , & V_37 ) ;
if ( V_11 < 0 ) {
F_2 ( V_2 , L_35 , V_294 [ V_9 ] ) ;
return V_11 ;
}
V_165 [ V_9 ] . V_164 = V_11 ;
V_165 [ V_9 ] . V_166 = ! ( V_37 & V_299 ) ;
}
return 0 ;
}
static int F_129 ( struct V_22 * V_28 , struct V_1 * V_2 )
{
struct V_295 * V_296 = V_2 -> V_297 ;
struct V_295 * V_300 ;
struct V_301 V_302 ;
int V_11 ;
if ( ! V_296 ) {
F_2 ( V_2 , L_36 ) ;
return - V_13 ;
}
V_11 = F_130 ( V_296 , L_37 ,
& V_28 -> V_58 ) ;
if ( V_11 < 0 ) {
V_28 -> V_58 = V_303 ;
F_131 ( V_2 , L_38 ,
V_28 -> V_58 ) ;
}
V_11 = F_127 ( V_28 -> V_165 , V_2 ) ;
if ( V_11 < 0 )
return V_11 ;
V_300 = F_132 ( V_296 , NULL ) ;
if ( ! V_300 ) {
F_2 ( V_2 , L_39 ,
V_296 -> V_304 ) ;
return - V_13 ;
}
F_133 ( V_300 , & V_302 ) ;
F_134 ( V_300 ) ;
V_28 -> V_126 = V_302 . V_126 ;
switch ( V_28 -> V_126 ) {
case V_127 :
V_28 -> V_130 = V_302 . V_305 . V_306 . V_307 ;
break;
case V_308 :
break;
default:
F_2 ( V_2 , L_40 ,
V_296 -> V_304 ) ;
return - V_13 ;
}
return 0 ;
}
static int F_135 ( struct V_22 * V_28 ,
struct V_30 * V_31 )
{
struct V_18 * V_24 ;
int V_11 ;
V_24 = & V_28 -> V_27 ;
F_136 ( V_24 , & V_309 ) ;
V_24 -> V_310 = V_311 ;
F_137 ( V_24 , V_28 ) ;
snprintf ( V_24 -> V_244 , sizeof( V_24 -> V_244 ) , L_41 ,
F_138 ( V_31 -> V_42 ) , V_31 -> V_29 ) ;
V_24 -> V_312 = & V_313 ;
V_24 -> V_37 |= V_314 ;
V_28 -> V_315 . V_37 = V_316 ;
V_24 -> V_25 . type = V_26 ;
V_11 = F_139 ( & V_24 -> V_25 , V_317 , & V_28 -> V_315 , 0 ) ;
if ( V_11 < 0 )
goto V_131;
V_24 = & V_28 -> V_24 ;
F_140 ( V_24 , V_31 , & V_318 ) ;
snprintf ( V_24 -> V_244 , sizeof( V_24 -> V_244 ) , L_42 ,
F_138 ( V_31 -> V_42 ) , V_31 -> V_29 ) ;
V_24 -> V_312 = & V_319 ;
V_24 -> V_37 |= V_314 ;
V_28 -> V_320 [ V_199 ] . V_37 = V_321 ;
V_28 -> V_320 [ V_278 ] . V_37 = V_316 ;
V_24 -> V_25 . type = V_322 ;
V_11 = F_139 ( & V_24 -> V_25 , V_323 , V_28 -> V_320 , 0 ) ;
if ( ! V_11 )
return 0 ;
F_141 ( & V_28 -> V_27 . V_25 ) ;
V_131:
F_2 ( & V_31 -> V_2 , L_43 , V_24 -> V_244 ) ;
return V_11 ;
}
static int F_142 ( struct V_22 * V_28 )
{
struct V_30 * V_31 = F_10 ( & V_28 -> V_24 ) ;
int V_11 ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_167 ; V_9 ++ )
V_28 -> V_168 [ V_9 ] . V_324 = V_325 [ V_9 ] ;
V_11 = F_143 ( & V_31 -> V_2 , V_167 ,
V_28 -> V_168 ) ;
if ( V_11 < 0 )
F_15 ( V_31 , L_44 ) ;
return V_11 ;
}
static int F_144 ( struct V_30 * V_31 ,
const struct V_326 * V_55 )
{
struct V_22 * V_28 ;
int V_11 ;
V_28 = F_3 ( & V_31 -> V_2 , sizeof( * V_28 ) , V_15 ) ;
if ( ! V_28 )
return - V_327 ;
F_145 ( & V_28 -> V_181 ) ;
V_28 -> V_144 = V_236 ;
V_28 -> V_147 = V_236 ;
V_28 -> V_146 = V_236 ;
V_11 = F_129 ( V_28 , & V_31 -> V_2 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_135 ( V_28 , V_31 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_125 ( V_28 ) ;
if ( V_11 < 0 )
goto V_328;
V_11 = F_142 ( V_28 ) ;
if ( V_11 < 0 )
goto V_328;
V_28 -> clock = F_146 ( V_28 -> V_24 . V_2 , V_329 ) ;
if ( F_71 ( V_28 -> clock ) ) {
V_11 = - V_330 ;
goto V_328;
}
V_11 = F_64 ( V_28 ) ;
if ( V_11 < 0 ) {
V_11 = - V_330 ;
goto V_328;
}
F_73 ( V_28 ) ;
V_11 = F_119 ( V_28 ) ;
F_70 ( V_28 ) ;
if ( V_11 < 0 )
goto V_328;
V_11 = F_110 ( V_28 ) ;
if ( V_11 < 0 )
goto V_328;
V_11 = F_147 ( & V_28 -> V_24 ) ;
if ( V_11 < 0 )
goto V_331;
return 0 ;
V_331:
F_117 ( V_28 -> V_24 . V_277 ) ;
V_328:
F_141 ( & V_28 -> V_24 . V_25 ) ;
F_141 ( & V_28 -> V_27 . V_25 ) ;
return V_11 ;
}
static int F_148 ( struct V_30 * V_31 )
{
struct V_18 * V_24 = F_149 ( V_31 ) ;
struct V_22 * V_28 = F_8 ( V_24 ) ;
F_150 ( V_24 ) ;
F_117 ( V_24 -> V_277 ) ;
F_141 ( & V_24 -> V_25 ) ;
V_24 = & V_28 -> V_27 ;
F_124 ( V_24 ) ;
F_141 ( & V_24 -> V_25 ) ;
return 0 ;
}
