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
return V_25 -> V_26 . type == V_27 ;
}
static inline struct V_23 * F_8 ( struct V_19 * V_25 )
{
if ( F_7 ( V_25 ) )
return F_6 ( V_25 , struct V_23 , V_28 ) ;
else
return F_6 ( V_25 , struct V_23 , V_25 ) ;
}
static T_3 F_9 ( struct V_23 * V_29 , T_3 V_30 )
{
struct V_31 * V_32 = F_10 ( & V_29 -> V_25 ) ;
T_4 V_33 , V_34 ;
T_3 V_35 ;
struct V_36 V_37 [] = {
{ . V_30 = V_32 -> V_30 , . V_38 = 0 ,
. V_39 = 2 , . V_40 = ( V_41 * ) & V_33 } ,
{ . V_30 = V_32 -> V_30 , . V_38 = V_42 ,
. V_39 = 2 , . V_40 = ( V_41 * ) & V_34 } ,
} ;
int V_11 ;
if ( V_29 -> error )
return 0 ;
V_33 = F_11 ( V_30 ) ;
V_11 = F_12 ( V_32 -> V_43 , V_37 , 2 ) ;
V_35 = F_13 ( V_34 ) ;
F_14 ( 3 , V_44 , V_32 , L_5 , V_30 , V_35 ) ;
if ( V_11 != 2 ) {
F_15 ( V_32 , L_6 , V_11 ) ;
V_29 -> error = V_11 ;
}
return V_35 ;
}
static void F_16 ( struct V_23 * V_29 , T_3 V_30 , T_3 V_45 )
{
V_41 V_40 [ 4 ] = { V_30 >> 8 , V_30 & 0xFF , V_45 >> 8 , V_45 & 0xFF } ;
struct V_31 * V_32 = F_10 ( & V_29 -> V_25 ) ;
int V_11 ;
if ( V_29 -> error )
return;
V_11 = F_17 ( V_32 , V_40 , 4 ) ;
F_14 ( 3 , V_44 , V_32 , L_7 , V_30 , V_45 ) ;
if ( V_11 != 4 ) {
F_15 ( V_32 , L_8 , V_11 ) ;
V_29 -> error = V_11 ;
}
}
static T_3 F_18 ( struct V_23 * V_29 , T_3 V_30 )
{
F_16 ( V_29 , V_46 , V_30 ) ;
return F_9 ( V_29 , V_47 ) ;
}
static void F_19 ( struct V_23 * V_29 , T_3 V_30 , T_3 V_45 )
{
F_16 ( V_29 , V_48 , V_30 ) ;
F_16 ( V_29 , V_47 , V_45 ) ;
}
static void F_20 ( struct V_23 * V_29 , T_3 V_30 ,
T_3 V_5 , const T_3 * V_17 )
{
struct V_31 * V_32 = F_10 ( & V_29 -> V_25 ) ;
T_4 V_40 [ 65 ] ;
F_16 ( V_29 , V_48 , V_30 ) ;
if ( V_29 -> error )
return;
F_14 ( 3 , V_44 , V_32 , L_9 , V_5 ,
F_21 ( 2 * V_5 , 64 ) , V_17 ) ;
V_40 [ 0 ] = F_11 ( V_47 ) ;
while ( V_5 > 0 ) {
int V_49 = F_22 ( int , V_5 , F_23 ( V_40 ) - 1 ) ;
int V_11 , V_9 ;
for ( V_9 = 1 ; V_9 <= V_49 ; ++ V_9 )
V_40 [ V_9 ] = F_11 ( * V_17 ++ ) ;
V_9 *= 2 ;
V_11 = F_17 ( V_32 , ( char * ) V_40 , V_9 ) ;
if ( V_11 != V_9 ) {
F_15 ( V_32 , L_10 , V_11 ) ;
V_29 -> error = V_11 ;
break;
}
V_5 -= V_49 ;
}
}
static void F_24 ( struct V_23 * V_29 , const T_3 * V_50 )
{
int V_5 ;
while ( ( V_5 = * V_50 ++ ) ) {
T_3 V_30 = * V_50 ++ ;
-- V_5 ;
F_20 ( V_29 , V_30 , V_5 , V_50 ) ;
V_50 += V_5 ;
}
}
static void F_25 ( struct V_23 * V_29 , int V_51 , T_3 V_30 )
{
unsigned long V_10 = V_52 + F_26 ( V_51 ) ;
T_3 V_53 ;
F_19 ( V_29 , V_30 , 1 ) ;
do {
V_53 = F_18 ( V_29 , V_30 ) ;
if ( V_29 -> error || ! V_53 )
return;
F_27 ( 5000 , 10000 ) ;
} while ( F_28 ( V_10 ) );
F_15 ( & V_29 -> V_25 , L_11 , V_30 ) ;
V_29 -> error = - V_54 ;
}
static T_3 * F_29 ( struct V_23 * V_29 , T_3 V_55 )
{
struct V_3 * V_4 = V_29 -> V_4 ;
T_3 * V_6 ;
int V_9 ;
if ( V_4 == NULL )
return NULL ;
V_6 = V_4 -> V_6 + 2 * V_4 -> V_5 ;
for ( V_9 = 0 ; V_9 < V_4 -> V_5 ; ++ V_9 ) {
if ( V_4 -> V_17 [ V_9 ] . V_56 == V_55 )
return V_6 + V_4 -> V_17 [ V_9 ] . V_18 ;
}
return NULL ;
}
static void F_30 ( struct V_23 * V_29 )
{
T_3 * V_17 = F_29 ( V_29 , V_57 ) ;
if ( V_17 )
F_24 ( V_29 , V_17 ) ;
}
static void F_31 ( struct V_23 * V_29 )
{
unsigned long V_58 = V_29 -> V_59 / 1000 ;
T_3 V_60 ;
static const T_3 V_61 [] = {
F_32 ( V_62 ,
V_63 , V_64 , 0 ,
V_65 / 4 , V_66 / 4 , V_67 / 4 ,
V_68 / 4 , V_66 / 4 , V_67 / 4 ) ,
F_32 ( V_69 , 1 ) ,
0
} ;
F_33 ( V_29 , V_70 , V_58 & 0xffff , V_58 >> 16 ) ;
F_24 ( V_29 , V_61 ) ;
F_25 ( V_29 , 250 , V_71 ) ;
V_60 = F_18 ( V_29 , V_72 ) ;
if ( ! V_29 -> error && V_60 ) {
F_15 ( & V_29 -> V_25 , L_12 , V_60 ) ;
V_29 -> error = - V_13 ;
}
}
static void F_34 ( struct V_23 * V_29 )
{
T_3 * V_17 = F_29 ( V_29 , V_73 ) ;
if ( V_17 )
F_24 ( V_29 , V_17 ) ;
}
static void F_35 ( struct V_23 * V_29 )
{
T_3 * V_17 = F_29 ( V_29 , V_74 ) ;
if ( ! V_17 )
return;
F_16 ( V_29 , V_75 , V_76 ) ;
F_24 ( V_29 , V_17 ) ;
F_16 ( V_29 , V_75 , V_77 ) ;
}
static void F_36 ( struct V_23 * V_29 )
{
F_19 ( V_29 , V_78 , 1 ) ;
if ( V_29 -> V_79 ) {
F_19 ( V_29 , V_80 , 1 ) ;
F_19 ( V_29 , V_81 , 1 ) ;
}
F_25 ( V_29 , 500 , V_82 ) ;
}
static void F_37 ( struct V_23 * V_29 )
{
T_3 V_83 = V_29 -> V_24 . V_84 -> V_45 | ( V_29 -> V_24 . V_84 -> V_45 << 1 ) ;
F_19 ( V_29 , F_38 ( 0 ) , V_83 ) ;
if ( V_29 -> V_85 )
F_36 ( V_29 ) ;
}
static void F_39 ( struct V_23 * V_29 , T_3 V_86 , bool V_87 )
{
T_3 V_88 , V_89 ;
if ( ! V_29 -> V_90 )
V_88 = F_18 ( V_29 , V_91 ) ;
else
V_88 = V_29 -> V_92 ;
V_89 = V_87 ? ( V_88 | V_86 ) : ( V_88 & ~ V_86 ) ;
if ( V_89 != V_88 )
F_19 ( V_29 , V_91 , V_89 ) ;
if ( V_29 -> error )
return;
V_29 -> V_90 = 1 ;
V_29 -> V_92 = V_89 ;
}
static void F_40 ( struct V_23 * V_29 , int V_93 )
{
struct V_94 * V_24 = & V_29 -> V_24 ;
if ( ! V_93 )
F_33 ( V_29 , V_95 ,
V_24 -> V_96 -> V_45 , 1 ,
V_97 , 1 ,
V_24 -> V_98 -> V_45 , 1 ,
1 ) ;
F_39 ( V_29 , V_99 , V_93 ) ;
}
static void F_41 ( struct V_23 * V_29 , int V_100 )
{
unsigned int time = V_100 / 10 ;
F_33 ( V_29 , V_101 ,
time & 0xffff , time >> 16 , 1 ) ;
}
static void F_42 ( struct V_23 * V_29 , int V_102 )
{
F_33 ( V_29 , V_103 , V_102 , 1 ) ;
}
static void F_43 ( struct V_23 * V_29 , int V_104 )
{
if ( V_104 == V_105 ) {
F_39 ( V_29 , V_106 | V_107 , true ) ;
} else {
unsigned int V_108 = V_29 -> V_24 . V_100 -> V_45 ;
F_41 ( V_29 , V_108 ) ;
F_42 ( V_29 , V_29 -> V_24 . V_102 -> V_45 ) ;
F_39 ( V_29 , V_106 | V_107 , false ) ;
}
}
static void F_44 ( struct V_23 * V_29 , int V_109 )
{
if ( V_109 == V_110 ) {
F_39 ( V_29 , V_111 , true ) ;
} else {
F_33 ( V_29 , V_112 , V_109 , 1 ) ;
F_39 ( V_29 , V_111 , false ) ;
}
}
static void F_45 ( struct V_23 * V_29 , int V_45 )
{
static const T_3 V_113 [] = {
[ V_114 ] = 0 ,
[ V_115 ] = 1 ,
[ V_116 ] = 2 ,
[ V_117 ] = 3 ,
[ V_118 ] = 4 ,
[ V_119 ] = 5 ,
} ;
F_19 ( V_29 , V_120 , V_113 [ V_45 ] ) ;
}
static int F_46 ( struct V_121 * V_122 )
{
int V_9 , V_32 = - 1 ;
for ( V_9 = 0 ; V_9 < F_23 ( V_123 ) ; V_9 ++ ) {
if ( V_122 -> V_124 != V_123 [ V_9 ] . V_124 )
continue;
if ( V_122 -> V_125 == V_123 [ V_9 ] . V_125 )
return V_9 ;
if ( V_32 < 0 )
V_32 = V_9 ;
}
return ( V_32 < 0 ) ? 0 : V_32 ;
}
static int F_47 ( struct V_23 * V_29 )
{
int V_11 = V_29 -> error ;
V_29 -> error = 0 ;
return V_11 ;
}
static int F_48 ( struct V_23 * V_29 )
{
T_3 V_126 ;
if ( V_29 -> V_127 == V_128 )
V_126 = V_129 ;
else
V_126 = 0 ;
F_33 ( V_29 , V_130 ,
V_29 -> V_131 , V_126 , 1 ) ;
return F_47 ( V_29 ) ;
}
static T_3 F_49 ( struct V_23 * V_29 )
{
T_3 V_132 = F_18 ( V_29 , V_133 ) ;
if ( V_132 )
F_19 ( V_29 , V_133 , 0 ) ;
return V_132 ;
}
static void F_50 ( struct V_23 * V_29 , T_3 V_134 )
{
F_19 ( V_29 , F_51 ( 0 ) , V_134 ) ;
F_36 ( V_29 ) ;
}
static void F_52 ( struct V_23 * V_29 )
{
T_3 V_132 , V_134 ;
int V_49 ;
V_134 = F_18 ( V_29 , V_135 ) ;
if ( V_29 -> error )
return;
for ( V_49 = 5 ; V_49 > 0 ; -- V_49 ) {
F_50 ( V_29 , V_134 ) ;
V_132 = F_49 ( V_29 ) ;
if ( V_29 -> error )
return;
switch ( V_132 ) {
case V_136 :
++ V_134 ;
break;
case 0 :
V_29 -> V_134 = V_134 ;
F_53 ( & V_29 -> V_25 ,
L_13 , V_134 ) ;
return;
default:
F_15 ( & V_29 -> V_25 ,
L_14 , V_132 ) ;
V_29 -> error = - V_13 ;
}
}
F_15 ( & V_29 -> V_25 , L_15 ) ;
V_29 -> error = - V_137 ;
}
static void F_54 ( struct V_23 * V_29 )
{
T_3 V_132 ;
V_132 = F_49 ( V_29 ) ;
if ( V_29 -> error )
return;
switch ( V_132 ) {
case 0 :
V_29 -> V_138 = 1 ;
return;
case V_136 :
F_52 ( V_29 ) ;
if ( ! V_29 -> error )
V_29 -> V_138 = 1 ;
return;
default:
F_15 ( & V_29 -> V_25 ,
L_16 , V_132 ) ;
V_29 -> error = - V_13 ;
}
}
static void F_55 ( struct V_139 * V_34 , const struct V_139 * V_109 ,
const struct V_139 * V_49 ,
const struct V_139 * V_8 )
{
V_34 -> V_140 = V_109 -> V_140 * V_49 -> V_141 / V_8 -> V_141 ;
V_34 -> V_142 = V_109 -> V_142 * V_49 -> V_143 / V_8 -> V_143 ;
V_34 -> V_141 = V_109 -> V_141 * V_49 -> V_141 / V_8 -> V_141 ;
V_34 -> V_143 = V_109 -> V_143 * V_49 -> V_143 / V_8 -> V_143 ;
}
static int F_56 ( struct V_23 * V_29 )
{
struct V_139 * V_144 , V_34 ;
T_3 V_132 ;
int V_11 ;
V_144 = & V_29 -> V_145 ;
F_33 ( V_29 , V_146 , V_144 -> V_141 , V_144 -> V_143 ,
V_144 -> V_140 , V_144 -> V_142 ) ;
F_55 ( & V_34 , & V_29 -> V_147 , & V_29 -> V_145 ,
& V_29 -> V_148 ) ;
F_33 ( V_29 , V_149 , V_34 . V_141 , V_34 . V_143 ,
V_34 . V_140 , V_34 . V_142 ) ;
F_25 ( V_29 , 500 , V_80 ) ;
F_25 ( V_29 , 500 , V_81 ) ;
V_132 = F_49 ( V_29 ) ;
V_11 = F_47 ( V_29 ) ;
if ( V_11 < 0 )
return V_11 ;
switch ( V_132 ) {
case 0 :
break;
case V_136 :
F_50 ( V_29 , V_150 ) ;
V_132 = F_49 ( V_29 ) ;
V_11 = F_47 ( V_29 ) ;
if ( V_11 < 0 )
return V_11 ;
if ( V_132 ) {
F_15 ( & V_29 -> V_25 ,
L_17 , V_132 ) ;
V_29 -> error = - V_13 ;
}
F_50 ( V_29 , V_29 -> V_151 ) ;
F_54 ( V_29 ) ;
break;
default:
F_15 ( & V_29 -> V_25 , L_18 , V_132 ) ;
return - V_13 ;
}
if ( ! V_29 -> V_138 )
return 0 ;
V_144 = & V_29 -> V_147 ;
F_33 ( V_29 , F_57 ( 0 ) , V_144 -> V_141 , V_144 -> V_143 ) ;
F_50 ( V_29 , V_29 -> V_151 ) ;
F_54 ( V_29 ) ;
return F_47 ( V_29 ) ;
}
static void F_58 ( struct V_23 * V_29 )
{
T_3 V_152 = V_123 [ V_29 -> V_153 ] . V_154 ;
struct V_139 * V_34 = & V_29 -> V_147 ;
F_33 ( V_29 , F_57 ( 0 ) ,
V_34 -> V_141 , V_34 -> V_143 , V_152 ,
V_67 >> 2 , V_66 >> 2 ,
V_155 , V_156 ,
V_157 , V_158 ,
V_29 -> V_151 , V_159 ) ;
F_36 ( V_29 ) ;
F_54 ( V_29 ) ;
}
static void F_59 ( struct V_23 * V_29 , int V_56 )
{
F_16 ( V_29 , V_160 , 800 ) ;
F_16 ( V_29 , V_161 , 511 ) ;
F_16 ( V_29 , V_162 , 0 ) ;
F_16 ( V_29 , V_163 , V_56 ) ;
}
static void F_60 ( struct V_23 * V_29 , int V_56 )
{
struct V_164 * V_165 = & V_29 -> V_166 [ V_56 ] ;
F_61 ( V_165 -> V_165 , V_165 -> V_167 ) ;
}
static void F_62 ( struct V_23 * V_29 , int V_56 )
{
struct V_164 * V_165 = & V_29 -> V_166 [ V_56 ] ;
F_61 ( V_165 -> V_165 , ! V_165 -> V_167 ) ;
}
static int F_63 ( struct V_23 * V_29 )
{
int V_11 ;
V_11 = F_64 ( V_168 , V_29 -> V_169 ) ;
if ( V_11 < 0 )
goto V_132;
V_11 = F_65 ( V_29 -> clock , V_29 -> V_59 ) ;
if ( V_11 < 0 )
goto V_170;
V_11 = F_66 ( V_29 -> clock ) ;
if ( V_11 < 0 )
goto V_170;
F_14 ( 1 , V_44 , & V_29 -> V_25 , L_19 ,
F_67 ( V_29 -> clock ) ) ;
F_62 ( V_29 , V_171 ) ;
F_27 ( 50 , 100 ) ;
F_62 ( V_29 , V_172 ) ;
return 0 ;
V_170:
F_68 ( V_168 , V_29 -> V_169 ) ;
V_132:
F_15 ( & V_29 -> V_25 , L_20 , V_173 , V_11 ) ;
return V_11 ;
}
static int F_69 ( struct V_23 * V_29 )
{
int V_11 ;
V_29 -> V_85 = 0 ;
V_29 -> V_138 = 0 ;
V_29 -> V_79 = 0 ;
F_60 ( V_29 , V_172 ) ;
F_60 ( V_29 , V_171 ) ;
if ( ! F_70 ( V_29 -> clock ) )
F_71 ( V_29 -> clock ) ;
V_11 = F_68 ( V_168 ,
V_29 -> V_169 ) ;
if ( V_11 < 0 )
F_15 ( & V_29 -> V_25 , L_21 ) ;
return 0 ;
}
static void F_72 ( struct V_23 * V_29 )
{
F_16 ( V_29 , V_174 , V_76 ) ;
F_16 ( V_29 , V_175 , 0 ) ;
F_16 ( V_29 , V_176 , 1 ) ;
F_16 ( V_29 , V_177 , V_77 ) ;
F_16 ( V_29 , V_75 , V_77 ) ;
}
static void F_73 ( struct V_23 * V_29 )
{
V_29 -> V_153 = 0 ;
V_29 -> V_151 = 10000 / 15 ;
V_29 -> V_134 = V_29 -> V_151 ;
V_29 -> V_90 = 0 ;
}
static int F_74 ( struct V_23 * V_29 )
{
struct V_31 * V_32 = F_10 ( & V_29 -> V_25 ) ;
const struct V_178 * V_4 ;
int V_11 ;
V_11 = F_75 ( & V_4 , V_179 , & V_32 -> V_2 ) ;
if ( V_11 < 0 ) {
F_76 ( & V_32 -> V_2 , L_22 ,
V_179 ) ;
return V_11 ;
}
V_11 = F_1 ( & V_32 -> V_2 , & V_29 -> V_4 , V_4 -> V_180 / 2 ,
( T_2 * ) V_4 -> V_6 ) ;
F_77 ( V_4 ) ;
return V_11 ;
}
static int F_78 ( struct V_19 * V_25 , int V_181 )
{
struct V_23 * V_29 = F_8 ( V_25 ) ;
int V_11 = 0 ;
F_79 ( & V_29 -> V_182 ) ;
if ( V_29 -> V_183 != ! V_181 )
goto V_184;
if ( V_181 ) {
if ( V_29 -> V_4 == NULL )
F_74 ( V_29 ) ;
F_73 ( V_29 ) ;
V_11 = F_63 ( V_29 ) ;
if ( V_11 < 0 )
goto V_184;
F_72 ( V_29 ) ;
F_30 ( V_29 ) ;
F_16 ( V_29 , V_185 , 1 ) ;
F_31 ( V_29 ) ;
V_11 = F_48 ( V_29 ) ;
if ( V_11 < 0 )
goto V_184;
F_35 ( V_29 ) ;
F_34 ( V_29 ) ;
V_11 = F_47 ( V_29 ) ;
if ( ! V_11 )
V_29 -> V_183 ++ ;
} else {
F_69 ( V_29 ) ;
V_29 -> V_183 -- ;
}
V_184:
F_80 ( & V_29 -> V_182 ) ;
if ( ! V_11 && V_181 )
V_11 = F_81 ( & V_29 -> V_24 . V_22 ) ;
return V_11 ;
}
static void F_82 ( struct V_23 * V_29 , int V_87 )
{
F_33 ( V_29 , V_186 , V_87 , 1 ) ;
}
static int F_83 ( struct V_19 * V_25 , int V_181 )
{
struct V_23 * V_29 = F_8 ( V_25 ) ;
int V_11 ;
F_79 ( & V_29 -> V_182 ) ;
if ( V_29 -> V_85 == ! ! V_181 ) {
V_11 = 0 ;
goto V_184;
}
if ( V_181 ) {
F_58 ( V_29 ) ;
V_11 = F_56 ( V_29 ) ;
if ( V_11 < 0 )
goto V_184;
F_82 ( V_29 , 1 ) ;
F_16 ( V_29 , 0xb0cc , 0x000b ) ;
} else {
F_82 ( V_29 , 0 ) ;
}
V_11 = F_47 ( V_29 ) ;
if ( ! V_11 )
V_29 -> V_85 = ! V_29 -> V_85 ;
V_184:
F_80 ( & V_29 -> V_182 ) ;
return V_11 ;
}
static int F_84 ( struct V_19 * V_25 ,
struct V_187 * V_188 )
{
struct V_23 * V_29 = F_8 ( V_25 ) ;
F_79 ( & V_29 -> V_182 ) ;
V_188 -> V_189 . V_190 = V_29 -> V_134 ;
V_188 -> V_189 . V_191 = 10000 ;
F_80 ( & V_29 -> V_182 ) ;
return 0 ;
}
static void F_85 ( struct V_23 * V_29 ,
struct V_187 * V_188 )
{
struct V_192 * V_9 = & V_188 -> V_189 ;
if ( V_188 -> V_189 . V_191 == 0 )
V_29 -> V_151 = V_150 ;
else
V_29 -> V_151 = F_86 ( V_193 ,
V_9 -> V_190 * 10000 / V_9 -> V_191 ,
V_159 ,
V_150 ) ;
V_29 -> V_134 = V_29 -> V_151 ;
if ( V_29 -> V_138 ) {
F_50 ( V_29 , V_29 -> V_151 ) ;
F_54 ( V_29 ) ;
}
* V_9 = (struct V_192 ) { V_29 -> V_134 , 10000 } ;
if ( V_29 -> V_134 == V_29 -> V_151 )
F_53 ( & V_29 -> V_25 , L_23 ,
V_29 -> V_134 ) ;
}
static int F_87 ( struct V_19 * V_25 ,
struct V_187 * V_188 )
{
struct V_23 * V_29 = F_8 ( V_25 ) ;
F_79 ( & V_29 -> V_182 ) ;
F_85 ( V_29 , V_188 ) ;
F_80 ( & V_29 -> V_182 ) ;
return 0 ;
}
static int F_88 ( struct V_19 * V_25 ,
struct V_194 * V_195 ,
struct V_196 * V_197 )
{
if ( V_197 -> V_198 > V_150 - V_159 ||
V_197 -> V_199 != V_200 )
return - V_13 ;
F_89 ( & V_197 -> V_141 , V_201 ,
V_202 , 1 ,
& V_197 -> V_143 , V_203 ,
V_204 , 1 , 0 ) ;
V_197 -> V_189 . V_190 = V_159 + V_197 -> V_198 ;
V_197 -> V_189 . V_191 = 10000 ;
return 0 ;
}
static int F_90 ( struct V_19 * V_25 ,
struct V_194 * V_195 ,
struct V_205 * V_125 )
{
if ( V_125 -> V_199 == V_200 ) {
if ( V_125 -> V_198 > 0 )
return - V_13 ;
V_125 -> V_125 = V_206 ;
return 0 ;
}
if ( V_125 -> V_198 >= F_23 ( V_123 ) )
return - V_13 ;
V_125 -> V_125 = V_123 [ V_125 -> V_198 ] . V_125 ;
return 0 ;
}
static int F_91 ( struct V_19 * V_25 ,
struct V_194 * V_195 ,
struct V_207 * V_208 )
{
int V_9 ;
if ( V_208 -> V_198 > 0 )
return - V_13 ;
if ( V_208 -> V_199 == V_200 ) {
V_208 -> V_125 = V_206 ;
V_208 -> V_209 = V_202 ;
V_208 -> V_210 = V_202 ;
V_208 -> V_211 = V_204 ;
V_208 -> V_212 = V_204 ;
return 0 ;
}
V_9 = F_23 ( V_123 ) ;
while ( -- V_9 )
if ( V_208 -> V_125 == V_123 [ V_9 ] . V_125 )
break;
V_208 -> V_125 = V_123 [ V_9 ] . V_125 ;
V_208 -> V_209 = V_201 ;
V_208 -> V_210 = V_202 ;
V_208 -> V_212 = V_203 ;
V_208 -> V_211 = V_204 ;
return 0 ;
}
static void F_92 ( struct V_121 * V_122 )
{
V_122 -> V_141 = V_202 ;
V_122 -> V_143 = V_204 ;
V_122 -> V_125 = V_206 ;
V_122 -> V_124 = V_213 ;
V_122 -> V_214 = V_215 ;
}
static int F_93 ( struct V_121 * V_122 )
{
int V_153 ;
F_89 ( & V_122 -> V_141 , V_201 ,
V_202 , 1 ,
& V_122 -> V_143 , V_203 ,
V_204 , 1 , 0 ) ;
V_153 = F_46 ( V_122 ) ;
V_122 -> V_124 = V_123 [ V_153 ] . V_124 ;
V_122 -> V_125 = V_123 [ V_153 ] . V_125 ;
V_122 -> V_214 = V_215 ;
return V_153 ;
}
static int F_94 ( struct V_19 * V_25 , struct V_194 * V_195 ,
struct V_216 * V_217 )
{
struct V_23 * V_29 = F_8 ( V_25 ) ;
const struct V_218 * V_153 ;
struct V_121 * V_122 ;
if ( V_217 -> V_219 == V_220 ) {
V_122 = F_95 ( V_25 , V_195 , V_217 -> V_199 ) ;
V_217 -> V_221 = * V_122 ;
return 0 ;
}
V_122 = & V_217 -> V_221 ;
if ( V_217 -> V_199 == V_200 ) {
F_92 ( V_122 ) ;
return 0 ;
}
V_122 -> V_214 = V_215 ;
F_79 ( & V_29 -> V_182 ) ;
V_153 = & V_123 [ V_29 -> V_153 ] ;
V_122 -> V_141 = V_29 -> V_147 . V_141 ;
V_122 -> V_143 = V_29 -> V_147 . V_143 ;
V_122 -> V_125 = V_153 -> V_125 ;
V_122 -> V_124 = V_153 -> V_124 ;
F_80 ( & V_29 -> V_182 ) ;
return 0 ;
}
static int F_96 ( struct V_19 * V_25 , struct V_194 * V_195 ,
struct V_216 * V_217 )
{
struct V_121 * V_122 = & V_217 -> V_221 ;
struct V_23 * V_29 = F_8 ( V_25 ) ;
const struct V_218 * V_153 ;
int V_11 = 0 ;
V_122 -> V_214 = V_215 ;
if ( V_217 -> V_219 == V_220 ) {
* F_95 ( V_25 , V_195 , V_217 -> V_199 ) = * V_122 ;
return 0 ;
}
if ( V_217 -> V_199 == V_200 ) {
F_92 ( V_122 ) ;
return 0 ;
}
F_79 ( & V_29 -> V_182 ) ;
if ( V_29 -> V_85 ) {
F_80 ( & V_29 -> V_182 ) ;
return - V_222 ;
}
V_29 -> V_153 = F_93 ( V_122 ) ;
V_153 = & V_123 [ V_29 -> V_153 ] ;
V_122 -> V_125 = V_153 -> V_125 ;
V_122 -> V_124 = V_153 -> V_124 ;
V_122 -> V_141 = V_29 -> V_147 . V_141 ;
V_122 -> V_143 = V_29 -> V_147 . V_143 ;
F_80 ( & V_29 -> V_182 ) ;
return V_11 ;
}
static enum V_223 F_97 ( V_193 V_199 , V_193 V_224 )
{
switch ( V_224 ) {
case V_225 :
return V_199 ? V_226 : V_227 ;
case V_228 :
return V_199 ? V_229 : V_230 ;
case V_231 :
return V_199 ? V_232 : V_230 ;
case V_233 :
return V_199 ? V_232 : V_226 ;
default:
return V_232 ;
}
}
static int F_98 ( V_193 V_224 )
{
return V_224 == V_225 ||
V_224 == V_231 ;
}
static int F_99 ( struct V_19 * V_25 ,
struct V_194 * V_195 ,
struct V_234 * V_235 )
{
static enum V_223 V_236 ;
struct V_23 * V_29 = F_8 ( V_25 ) ;
V_236 = F_97 ( V_235 -> V_199 , V_235 -> V_224 ) ;
switch ( V_236 ) {
case V_232 :
return - V_13 ;
case V_227 :
V_235 -> V_34 = V_237 ;
return 0 ;
default:
break;
}
if ( V_235 -> V_219 == V_220 ) {
if ( V_236 == V_226 )
V_235 -> V_34 = * F_100 ( V_25 , V_195 , V_235 -> V_199 ) ;
else
V_235 -> V_34 = * F_101 ( V_25 , V_195 , V_235 -> V_199 ) ;
return 0 ;
}
F_79 ( & V_29 -> V_182 ) ;
switch ( V_236 ) {
case V_230 :
V_235 -> V_34 = V_29 -> V_145 ;
break;
case V_226 :
V_235 -> V_34 = V_29 -> V_148 ;
break;
case V_229 :
V_235 -> V_34 = V_29 -> V_147 ;
break;
default:
break;
}
if ( F_98 ( V_235 -> V_224 ) ) {
V_235 -> V_34 . V_140 = 0 ;
V_235 -> V_34 . V_142 = 0 ;
}
F_80 ( & V_29 -> V_182 ) ;
return 0 ;
}
static void F_102 ( V_193 * V_238 , V_193 * V_39 , V_193 V_239 )
{
if ( * V_39 > V_239 )
* V_39 = V_239 ;
if ( * V_238 + * V_39 > V_239 )
* V_238 = V_239 - * V_39 ;
* V_238 &= ~ 1 ;
* V_39 &= ~ 1 ;
if ( * V_39 < V_201 )
* V_39 = V_201 ;
}
static void F_103 ( struct V_139 * V_34 , V_193 V_141 , V_193 V_143 )
{
F_102 ( & V_34 -> V_140 , & V_34 -> V_141 , V_141 ) ;
F_102 ( & V_34 -> V_142 , & V_34 -> V_143 , V_143 ) ;
}
static void F_104 ( struct V_139 * * V_240 ,
enum V_223 V_241 ,
struct V_139 * V_109 )
{
struct V_139 * V_34 , * V_242 ;
enum V_223 V_9 = V_241 ;
* V_240 [ V_241 ] = * V_109 ;
do {
V_34 = V_240 [ V_9 ] ;
V_242 = V_240 [ V_9 - 1 ] ;
F_103 ( V_34 , V_242 -> V_141 , V_242 -> V_143 ) ;
} while ( ++ V_9 != V_232 );
* V_109 = * V_240 [ V_241 ] ;
}
static bool F_105 ( const struct V_139 * V_243 ,
const struct V_139 * V_244 )
{
return ! memcmp ( V_243 , V_244 , sizeof( * V_243 ) ) ;
}
static int F_106 ( struct V_19 * V_25 ,
struct V_194 * V_195 ,
struct V_234 * V_235 )
{
static enum V_223 V_236 ;
struct V_23 * V_29 = F_8 ( V_25 ) ;
struct V_139 * * V_240 ;
int V_11 = 0 ;
V_236 = F_97 ( V_235 -> V_199 , V_235 -> V_224 ) ;
if ( V_236 == V_232 || F_98 ( V_235 -> V_224 ) )
return - V_13 ;
if ( V_236 == V_226 ) {
V_235 -> V_34 . V_140 = 0 ;
V_235 -> V_34 . V_142 = 0 ;
}
if ( V_235 -> V_219 == V_220 ) {
V_240 = (struct V_139 * [] ) {
& V_237 ,
F_101 ( V_25 , V_195 , V_200 ) ,
F_100 ( V_25 , V_195 , V_200 ) ,
F_101 (sd, cfg, PAD_OUT)
} ;
F_104 ( V_240 , V_236 , & V_235 -> V_34 ) ;
return 0 ;
}
V_240 = (struct V_139 * [] ) {
& V_237 ,
& V_29 -> V_145 ,
& V_29 -> V_148 ,
& V_29 -> V_147
} ;
F_79 ( & V_29 -> V_182 ) ;
if ( V_29 -> V_85 ) {
if ( V_236 < V_229 ) {
if ( V_235 -> V_34 . V_141 < V_29 -> V_147 . V_141 )
V_235 -> V_34 . V_141 = V_29 -> V_147 . V_141 ;
if ( V_235 -> V_34 . V_143 < V_29 -> V_147 . V_143 )
V_235 -> V_34 . V_143 = V_29 -> V_147 . V_143 ;
} else {
V_235 -> V_34 . V_141 = V_29 -> V_147 . V_141 ;
V_235 -> V_34 . V_143 = V_29 -> V_147 . V_143 ;
}
}
F_104 ( V_240 , V_236 , & V_235 -> V_34 ) ;
if ( ! F_105 ( & V_29 -> V_145 , & V_237 ) ||
! F_105 ( & V_29 -> V_148 , & V_237 ) )
V_29 -> V_79 = 1 ;
if ( V_29 -> V_85 )
V_11 = F_56 ( V_29 ) ;
F_80 ( & V_29 -> V_182 ) ;
return V_11 ;
}
static int F_107 ( struct V_20 * V_21 )
{
struct V_19 * V_25 = F_5 ( V_21 ) ;
struct V_23 * V_29 = F_8 ( V_25 ) ;
int V_11 ;
F_14 ( 1 , V_44 , V_25 , L_24 , V_21 -> V_245 , V_21 -> V_45 ) ;
F_79 ( & V_29 -> V_182 ) ;
if ( V_29 -> V_183 == 0 )
goto V_246;
switch ( V_21 -> V_56 ) {
case V_247 :
F_40 ( V_29 , V_21 -> V_45 ) ;
break;
case V_248 :
F_19 ( V_29 , V_249 , V_21 -> V_45 ) ;
break;
case V_250 :
F_45 ( V_29 , V_21 -> V_45 ) ;
break;
case V_251 :
F_19 ( V_29 , V_252 , V_21 -> V_45 ) ;
break;
case V_253 :
F_43 ( V_29 , V_21 -> V_45 ) ;
break;
case V_254 :
F_37 ( V_29 ) ;
break;
case V_255 :
F_44 ( V_29 , V_21 -> V_45 ) ;
break;
case V_256 :
F_19 ( V_29 , V_257 , V_21 -> V_45 ) ;
break;
case V_258 :
F_19 ( V_29 , V_259 , V_21 -> V_45 ) ;
break;
case V_260 :
F_19 ( V_29 , F_108 ( 0 ) , V_21 -> V_45 ) ;
if ( V_29 -> V_138 )
F_36 ( V_29 ) ;
break;
case V_261 :
F_59 ( V_29 , V_21 -> V_45 ) ;
break;
}
V_246:
V_11 = F_47 ( V_29 ) ;
F_80 ( & V_29 -> V_182 ) ;
return V_11 ;
}
static int F_109 ( struct V_23 * V_29 )
{
const struct V_262 * V_263 = & V_264 ;
struct V_94 * V_24 = & V_29 -> V_24 ;
struct V_265 * V_266 = & V_24 -> V_22 ;
int V_11 ;
V_11 = F_110 ( V_266 , 16 ) ;
if ( V_11 < 0 ) {
F_15 ( & V_29 -> V_25 , L_25 , V_11 ) ;
return V_11 ;
}
V_24 -> V_93 = F_111 ( V_266 , V_263 , V_247 ,
0 , 1 , 1 , 1 ) ;
V_24 -> V_96 = F_111 ( V_266 , V_263 , V_267 ,
0 , 255 , 1 , V_268 ) ;
V_24 -> V_98 = F_111 ( V_266 , V_263 , V_269 ,
0 , 255 , 1 , V_270 ) ;
F_112 ( 3 , & V_24 -> V_93 , 0 , false ) ;
V_24 -> V_271 = F_111 ( V_266 , V_263 , V_254 , 0 , 1 , 1 , 0 ) ;
V_24 -> V_84 = F_111 ( V_266 , V_263 , V_272 , 0 , 1 , 1 , 0 ) ;
F_113 ( 2 , & V_24 -> V_271 ) ;
V_24 -> V_273 = F_114 ( V_266 , V_263 ,
V_253 ,
V_274 , 0 , V_105 ) ;
V_24 -> V_100 = F_111 ( V_266 , V_263 , V_275 ,
0 , 6000000U , 1 , 100000U ) ;
V_24 -> V_102 = F_111 ( V_266 , V_263 , V_276 ,
0 , 256 , 1 , 256 ) ;
F_112 ( 3 , & V_24 -> V_273 , 0 , false ) ;
F_114 ( V_266 , V_263 , V_255 ,
V_110 , 0 ,
V_110 ) ;
F_114 ( V_266 , V_263 , V_250 ,
V_118 , ~ 0x6f , V_114 ) ;
F_111 ( V_266 , V_263 , V_260 ,
0 , 256 , 1 , 0 ) ;
F_111 ( V_266 , V_263 , V_256 , - 127 , 127 , 1 , 0 ) ;
F_111 ( V_266 , V_263 , V_248 , - 127 , 127 , 1 , 0 ) ;
F_111 ( V_266 , V_263 , V_251 , - 127 , 127 , 1 , 0 ) ;
F_111 ( V_266 , V_263 , V_258 , - 127 , 127 , 1 , 0 ) ;
F_115 ( V_266 , V_263 , V_261 ,
F_23 ( V_277 ) - 1 ,
0 , 0 , V_277 ) ;
if ( V_266 -> error ) {
F_15 ( & V_29 -> V_25 , L_26 ,
V_266 -> error ) ;
V_11 = V_266 -> error ;
F_116 ( V_266 ) ;
return V_11 ;
}
V_29 -> V_25 . V_278 = V_266 ;
return 0 ;
}
static int F_117 ( struct V_19 * V_25 , struct V_279 * V_280 )
{
struct V_121 * V_122 ;
V_122 = F_95 ( V_25 , V_280 -> V_199 , V_200 ) ;
F_92 ( V_122 ) ;
if ( F_7 ( V_25 ) )
return 0 ;
V_122 = F_95 ( V_25 , V_280 -> V_199 , V_281 ) ;
V_122 -> V_124 = V_123 [ 0 ] . V_124 ;
V_122 -> V_125 = V_123 [ 0 ] . V_125 ;
V_122 -> V_141 = V_237 . V_141 ;
V_122 -> V_143 = V_237 . V_143 ;
V_122 -> V_214 = V_215 ;
* F_101 ( V_25 , V_280 -> V_199 , V_200 ) = V_237 ;
* F_100 ( V_25 , V_280 -> V_199 , V_200 ) = V_237 ;
* F_101 ( V_25 , V_280 -> V_199 , V_281 ) = V_237 ;
return 0 ;
}
static int F_118 ( struct V_23 * V_29 )
{
T_3 V_282 = 0 , V_283 = 0 , V_284 = 0 ;
int V_11 ;
V_282 = F_18 ( V_29 , V_285 ) ;
V_283 = F_18 ( V_29 , V_286 ) & 0xff ;
V_284 = F_18 ( V_29 , V_287 ) ;
V_11 = F_47 ( V_29 ) ;
if ( V_11 < 0 )
return V_11 ;
F_53 ( & V_29 -> V_25 , L_27 ,
V_282 , V_283 , V_284 ) ;
if ( V_282 != V_288 ) {
F_15 ( & V_29 -> V_25 , L_28 ) ;
return - V_289 ;
}
return 0 ;
}
static int F_119 ( struct V_19 * V_25 )
{
struct V_23 * V_29 = F_8 ( V_25 ) ;
int V_11 ;
V_11 = F_120 ( V_25 -> V_290 , & V_29 -> V_28 ) ;
if ( V_11 < 0 )
F_15 ( V_25 , L_29 ,
V_29 -> V_28 . V_245 ) ;
else
V_11 = F_121 ( & V_29 -> V_28 . V_26 , V_200 ,
& V_29 -> V_25 . V_26 , V_200 ,
V_291 |
V_292 ) ;
return V_11 ;
}
static void F_122 ( struct V_19 * V_25 )
{
struct V_23 * V_29 = F_8 ( V_25 ) ;
F_123 ( & V_29 -> V_28 ) ;
}
static int F_124 ( struct V_23 * V_29 )
{
static const char * const V_245 [] = { L_30 , L_31 } ;
struct V_31 * V_32 = F_10 ( & V_29 -> V_25 ) ;
struct V_164 * V_293 = V_29 -> V_166 ;
int V_11 , V_9 ;
for ( V_9 = 0 ; V_9 < V_294 ; ++ V_9 ) {
int V_38 = V_295 ;
if ( V_293 [ V_9 ] . V_167 )
V_38 |= V_296 ;
V_11 = F_125 ( & V_32 -> V_2 , V_293 [ V_9 ] . V_165 , V_38 , V_245 [ V_9 ] ) ;
if ( V_11 < 0 ) {
F_15 ( V_32 , L_32 , V_245 [ V_9 ] ) ;
return V_11 ;
}
}
return 0 ;
}
static int F_126 ( struct V_164 * V_166 , struct V_1 * V_2 )
{
static const char * const V_297 [] = {
L_33 ,
L_34 ,
} ;
struct V_298 * V_299 = V_2 -> V_300 ;
enum V_301 V_38 ;
int V_11 , V_9 ;
for ( V_9 = 0 ; V_9 < V_294 ; ++ V_9 ) {
V_11 = F_127 ( V_299 , V_297 [ V_9 ] , 0 , & V_38 ) ;
if ( V_11 < 0 ) {
F_2 ( V_2 , L_35 , V_297 [ V_9 ] ) ;
return V_11 ;
}
V_166 [ V_9 ] . V_165 = V_11 ;
V_166 [ V_9 ] . V_167 = ! ( V_38 & V_302 ) ;
}
return 0 ;
}
static int F_128 ( struct V_23 * V_29 , struct V_1 * V_2 )
{
struct V_298 * V_299 = V_2 -> V_300 ;
struct V_298 * V_303 ;
struct V_304 V_305 ;
int V_11 ;
if ( ! V_299 ) {
F_2 ( V_2 , L_36 ) ;
return - V_13 ;
}
V_11 = F_129 ( V_299 , L_37 ,
& V_29 -> V_59 ) ;
if ( V_11 < 0 ) {
V_29 -> V_59 = V_306 ;
F_130 ( V_2 , L_38 ,
V_29 -> V_59 ) ;
}
V_11 = F_126 ( V_29 -> V_166 , V_2 ) ;
if ( V_11 < 0 )
return V_11 ;
V_303 = F_131 ( V_299 , NULL ) ;
if ( ! V_303 ) {
F_2 ( V_2 , L_39 ,
V_299 -> V_307 ) ;
return - V_13 ;
}
F_132 ( V_303 , & V_305 ) ;
F_133 ( V_303 ) ;
V_29 -> V_127 = V_305 . V_127 ;
switch ( V_29 -> V_127 ) {
case V_128 :
V_29 -> V_131 = V_305 . V_308 . V_309 . V_310 ;
break;
case V_311 :
break;
default:
F_2 ( V_2 , L_40 ,
V_299 -> V_307 ) ;
return - V_13 ;
}
return 0 ;
}
static int F_134 ( struct V_23 * V_29 ,
struct V_31 * V_32 )
{
struct V_19 * V_25 ;
int V_11 ;
V_25 = & V_29 -> V_28 ;
F_135 ( V_25 , & V_312 ) ;
V_25 -> V_313 = V_314 ;
F_136 ( V_25 , V_29 ) ;
snprintf ( V_25 -> V_245 , sizeof( V_25 -> V_245 ) , L_41 ,
F_137 ( V_32 -> V_43 ) , V_32 -> V_30 ) ;
V_25 -> V_315 = & V_316 ;
V_25 -> V_38 |= V_317 ;
V_29 -> V_318 . V_38 = V_319 ;
V_25 -> V_26 . type = V_27 ;
V_11 = F_138 ( & V_25 -> V_26 , V_320 , & V_29 -> V_318 , 0 ) ;
if ( V_11 < 0 )
goto V_132;
V_25 = & V_29 -> V_25 ;
F_139 ( V_25 , V_32 , & V_321 ) ;
snprintf ( V_25 -> V_245 , sizeof( V_25 -> V_245 ) , L_42 ,
F_137 ( V_32 -> V_43 ) , V_32 -> V_30 ) ;
V_25 -> V_315 = & V_322 ;
V_25 -> V_38 |= V_317 ;
V_29 -> V_323 [ V_200 ] . V_38 = V_324 ;
V_29 -> V_323 [ V_281 ] . V_38 = V_319 ;
V_25 -> V_26 . type = V_325 ;
V_11 = F_138 ( & V_25 -> V_26 , V_326 , V_29 -> V_323 , 0 ) ;
if ( ! V_11 )
return 0 ;
F_140 ( & V_29 -> V_28 . V_26 ) ;
V_132:
F_2 ( & V_32 -> V_2 , L_43 , V_25 -> V_245 ) ;
return V_11 ;
}
static int F_141 ( struct V_23 * V_29 )
{
struct V_31 * V_32 = F_10 ( & V_29 -> V_25 ) ;
int V_11 ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_168 ; V_9 ++ )
V_29 -> V_169 [ V_9 ] . V_327 = V_328 [ V_9 ] ;
V_11 = F_142 ( & V_32 -> V_2 , V_168 ,
V_29 -> V_169 ) ;
if ( V_11 < 0 )
F_15 ( V_32 , L_44 ) ;
return V_11 ;
}
static int F_143 ( struct V_31 * V_32 ,
const struct V_329 * V_56 )
{
struct V_23 * V_29 ;
int V_11 ;
V_29 = F_3 ( & V_32 -> V_2 , sizeof( * V_29 ) , V_15 ) ;
if ( ! V_29 )
return - V_16 ;
F_144 ( & V_29 -> V_182 ) ;
V_29 -> V_145 = V_237 ;
V_29 -> V_148 = V_237 ;
V_29 -> V_147 = V_237 ;
V_11 = F_128 ( V_29 , & V_32 -> V_2 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_134 ( V_29 , V_32 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_124 ( V_29 ) ;
if ( V_11 < 0 )
goto V_330;
V_11 = F_141 ( V_29 ) ;
if ( V_11 < 0 )
goto V_330;
V_29 -> clock = F_145 ( V_29 -> V_25 . V_2 , V_331 ) ;
if ( F_70 ( V_29 -> clock ) ) {
V_11 = - V_332 ;
goto V_330;
}
V_11 = F_63 ( V_29 ) ;
if ( V_11 < 0 ) {
V_11 = - V_332 ;
goto V_330;
}
F_72 ( V_29 ) ;
V_11 = F_118 ( V_29 ) ;
F_69 ( V_29 ) ;
if ( V_11 < 0 )
goto V_330;
V_11 = F_109 ( V_29 ) ;
if ( V_11 < 0 )
goto V_330;
V_11 = F_146 ( & V_29 -> V_25 ) ;
if ( V_11 < 0 )
goto V_333;
return 0 ;
V_333:
F_116 ( V_29 -> V_25 . V_278 ) ;
V_330:
F_140 ( & V_29 -> V_25 . V_26 ) ;
F_140 ( & V_29 -> V_28 . V_26 ) ;
return V_11 ;
}
static int F_147 ( struct V_31 * V_32 )
{
struct V_19 * V_25 = F_148 ( V_32 ) ;
struct V_23 * V_29 = F_8 ( V_25 ) ;
F_149 ( V_25 ) ;
F_116 ( V_25 -> V_278 ) ;
F_140 ( & V_25 -> V_26 ) ;
V_25 = & V_29 -> V_28 ;
F_123 ( V_25 ) ;
F_140 ( & V_25 -> V_26 ) ;
return 0 ;
}
