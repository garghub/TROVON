static int F_1 ( struct V_1 * V_2 , struct V_3 * * V_4 ,
T_1 V_5 , const T_2 * V_6 )
{
struct V_3 * V_7 ;
T_2 * V_8 , V_9 , * V_10 ;
int V_11 ;
if ( V_5 < V_12 + 1 ) {
F_2 ( V_2 , L_1 , V_5 ) ;
return - V_13 ;
}
V_11 = memcmp ( V_6 , V_14 , V_12 * sizeof( T_2 ) ) ;
if ( V_11 != 0 ) {
F_2 ( V_2 , L_2 ) ;
return - V_13 ;
}
V_6 += V_12 ;
V_5 -= V_12 ;
V_8 = F_3 ( V_2 , V_5 * sizeof( T_2 ) , V_15 ) ;
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
static T_2 F_9 ( struct V_22 * V_28 , T_2 V_29 )
{
struct V_30 * V_31 = F_10 ( & V_28 -> V_24 ) ;
T_3 V_32 , V_33 ;
struct V_34 V_35 [] = {
{ . V_29 = V_31 -> V_29 , . V_36 = 0 ,
. V_37 = 2 , . V_38 = ( V_39 * ) & V_32 } ,
{ . V_29 = V_31 -> V_29 , . V_36 = V_40 ,
. V_37 = 2 , . V_38 = ( V_39 * ) & V_33 } ,
} ;
int V_11 ;
if ( V_28 -> error )
return 0 ;
V_32 = F_11 ( V_29 ) ;
V_11 = F_12 ( V_31 -> V_41 , V_35 , 2 ) ;
V_33 = F_13 ( V_33 ) ;
F_14 ( 3 , V_42 , V_31 , L_5 , V_29 , V_33 ) ;
if ( V_11 != 2 ) {
F_15 ( V_31 , L_6 , V_11 ) ;
V_28 -> error = V_11 ;
}
return V_33 ;
}
static void F_16 ( struct V_22 * V_28 , T_2 V_29 , T_2 V_43 )
{
V_39 V_38 [ 4 ] = { V_29 >> 8 , V_29 & 0xFF , V_43 >> 8 , V_43 & 0xFF } ;
struct V_30 * V_31 = F_10 ( & V_28 -> V_24 ) ;
int V_11 ;
if ( V_28 -> error )
return;
V_11 = F_17 ( V_31 , V_38 , 4 ) ;
F_14 ( 3 , V_42 , V_31 , L_7 , V_29 , V_43 ) ;
if ( V_11 != 4 ) {
F_15 ( V_31 , L_8 , V_11 ) ;
V_28 -> error = V_11 ;
}
}
static T_2 F_18 ( struct V_22 * V_28 , T_2 V_29 )
{
F_16 ( V_28 , V_44 , V_29 ) ;
return F_9 ( V_28 , V_45 ) ;
}
static void F_19 ( struct V_22 * V_28 , T_2 V_29 , T_2 V_43 )
{
F_16 ( V_28 , V_46 , V_29 ) ;
F_16 ( V_28 , V_45 , V_43 ) ;
}
static void F_20 ( struct V_22 * V_28 , T_2 V_29 ,
T_2 V_5 , const T_2 * V_16 )
{
struct V_30 * V_31 = F_10 ( & V_28 -> V_24 ) ;
T_3 V_38 [ 65 ] ;
F_16 ( V_28 , V_46 , V_29 ) ;
if ( V_28 -> error )
return;
F_14 ( 3 , V_42 , V_31 , L_9 , V_5 ,
F_21 ( 2 * V_5 , 64 ) , V_16 ) ;
V_38 [ 0 ] = F_22 ( V_45 ) ;
while ( V_5 > 0 ) {
int V_47 = F_23 ( int , V_5 , F_24 ( V_38 ) - 1 ) ;
int V_11 , V_9 ;
for ( V_9 = 1 ; V_9 <= V_47 ; ++ V_9 )
V_38 [ V_9 ] = F_11 ( * V_16 ++ ) ;
V_9 *= 2 ;
V_11 = F_17 ( V_31 , ( char * ) V_38 , V_9 ) ;
if ( V_11 != V_9 ) {
F_15 ( V_31 , L_10 , V_11 ) ;
V_28 -> error = V_11 ;
break;
}
V_5 -= V_47 ;
}
}
static void F_25 ( struct V_22 * V_28 , const T_2 * V_48 )
{
int V_5 ;
while ( ( V_5 = * V_48 ++ ) ) {
T_2 V_29 = * V_48 ++ ;
-- V_5 ;
F_20 ( V_28 , V_29 , V_5 , V_48 ) ;
V_48 += V_5 ;
}
}
static void F_26 ( struct V_22 * V_28 , int V_49 , T_2 V_29 )
{
unsigned long V_10 = V_50 + F_27 ( V_49 ) ;
T_2 V_51 ;
F_19 ( V_28 , V_29 , 1 ) ;
do {
V_51 = F_18 ( V_28 , V_29 ) ;
if ( V_28 -> error || ! V_51 )
return;
F_28 ( 5000 , 10000 ) ;
} while ( F_29 ( V_10 ) );
F_15 ( & V_28 -> V_24 , L_11 , V_29 ) ;
V_28 -> error = - V_52 ;
}
static T_2 * F_30 ( struct V_22 * V_28 , T_2 V_53 )
{
struct V_3 * V_4 = V_28 -> V_4 ;
T_2 * V_6 ;
int V_9 ;
if ( V_4 == NULL )
return NULL ;
V_6 = V_4 -> V_6 + 2 * V_4 -> V_5 ;
for ( V_9 = 0 ; V_9 < V_4 -> V_5 ; ++ V_9 ) {
if ( V_4 -> V_16 [ V_9 ] . V_54 == V_53 )
return V_6 + V_4 -> V_16 [ V_9 ] . V_17 ;
}
return NULL ;
}
static void F_31 ( struct V_22 * V_28 )
{
T_2 * V_16 = F_30 ( V_28 , V_55 ) ;
if ( V_16 )
F_25 ( V_28 , V_16 ) ;
}
static void F_32 ( struct V_22 * V_28 )
{
unsigned long V_56 = V_28 -> V_57 / 1000 ;
T_2 V_58 ;
static const T_2 V_59 [] = {
F_33 ( V_60 ,
V_61 , V_62 , 0 ,
V_63 / 4 , V_64 / 4 , V_65 / 4 ,
V_66 / 4 , V_64 / 4 , V_65 / 4 ) ,
F_33 ( V_67 , 1 ) ,
0
} ;
F_34 ( V_28 , V_68 , V_56 & 0xffff , V_56 >> 16 ) ;
F_25 ( V_28 , V_59 ) ;
F_26 ( V_28 , 250 , V_69 ) ;
V_58 = F_18 ( V_28 , V_70 ) ;
if ( ! V_28 -> error && V_58 ) {
F_15 ( & V_28 -> V_24 , L_12 , V_58 ) ;
V_28 -> error = - V_13 ;
}
}
static void F_35 ( struct V_22 * V_28 )
{
T_2 * V_16 = F_30 ( V_28 , V_71 ) ;
if ( V_16 )
F_25 ( V_28 , V_16 ) ;
}
static void F_36 ( struct V_22 * V_28 )
{
T_2 * V_16 = F_30 ( V_28 , V_72 ) ;
if ( ! V_16 )
return;
F_16 ( V_28 , V_73 , V_74 ) ;
F_25 ( V_28 , V_16 ) ;
F_16 ( V_28 , V_73 , V_75 ) ;
}
static void F_37 ( struct V_22 * V_28 )
{
F_19 ( V_28 , V_76 , 1 ) ;
if ( V_28 -> V_77 ) {
F_19 ( V_28 , V_78 , 1 ) ;
F_19 ( V_28 , V_79 , 1 ) ;
}
F_26 ( V_28 , 500 , V_80 ) ;
}
static void F_38 ( struct V_22 * V_28 )
{
T_2 V_81 = V_28 -> V_23 . V_82 -> V_43 | ( V_28 -> V_23 . V_82 -> V_43 << 1 ) ;
F_19 ( V_28 , F_39 ( 0 ) , V_81 ) ;
if ( V_28 -> V_83 )
F_37 ( V_28 ) ;
}
static void F_40 ( struct V_22 * V_28 , T_2 V_84 , bool V_85 )
{
T_2 V_86 , V_87 ;
if ( ! V_28 -> V_88 )
V_86 = F_18 ( V_28 , V_89 ) ;
else
V_86 = V_28 -> V_90 ;
V_87 = V_85 ? ( V_86 | V_84 ) : ( V_86 & ~ V_84 ) ;
if ( V_87 != V_86 )
F_19 ( V_28 , V_89 , V_87 ) ;
if ( V_28 -> error )
return;
V_28 -> V_88 = 1 ;
V_28 -> V_90 = V_87 ;
}
static void F_41 ( struct V_22 * V_28 , int V_91 )
{
struct V_92 * V_23 = & V_28 -> V_23 ;
if ( ! V_91 )
F_34 ( V_28 , V_93 ,
V_23 -> V_94 -> V_43 , 1 ,
V_95 , 1 ,
V_23 -> V_96 -> V_43 , 1 ,
1 ) ;
F_40 ( V_28 , V_97 , V_91 ) ;
}
static void F_42 ( struct V_22 * V_28 , int V_98 )
{
unsigned int time = V_98 / 10 ;
F_34 ( V_28 , V_99 ,
time & 0xffff , time >> 16 , 1 ) ;
}
static void F_43 ( struct V_22 * V_28 , int V_100 )
{
F_34 ( V_28 , V_101 , V_100 , 1 ) ;
}
static void F_44 ( struct V_22 * V_28 , int V_102 )
{
if ( V_102 == V_103 ) {
F_40 ( V_28 , V_104 | V_105 , true ) ;
} else {
unsigned int V_106 = V_28 -> V_23 . V_98 -> V_43 ;
F_42 ( V_28 , V_106 ) ;
F_43 ( V_28 , V_28 -> V_23 . V_100 -> V_43 ) ;
F_40 ( V_28 , V_104 | V_105 , false ) ;
}
}
static void F_45 ( struct V_22 * V_28 , int V_107 )
{
if ( V_107 == V_108 ) {
F_40 ( V_28 , V_109 , true ) ;
} else {
F_34 ( V_28 , V_110 , V_107 , 1 ) ;
F_40 ( V_28 , V_109 , false ) ;
}
}
static void F_46 ( struct V_22 * V_28 , int V_43 )
{
static const T_2 V_111 [] = {
[ V_112 ] = 0 ,
[ V_113 ] = 1 ,
[ V_114 ] = 2 ,
[ V_115 ] = 3 ,
[ V_116 ] = 4 ,
[ V_117 ] = 5 ,
} ;
F_19 ( V_28 , V_118 , V_111 [ V_43 ] ) ;
}
static int F_47 ( struct V_119 * V_120 )
{
int V_9 , V_31 = - 1 ;
for ( V_9 = 0 ; V_9 < F_24 ( V_121 ) ; V_9 ++ ) {
if ( V_120 -> V_122 != V_121 [ V_9 ] . V_122 )
continue;
if ( V_120 -> V_123 == V_121 [ V_9 ] . V_123 )
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
T_2 V_124 ;
if ( V_28 -> V_125 == V_126 )
V_124 = V_127 ;
else
V_124 = 0 ;
F_34 ( V_28 , V_128 ,
V_28 -> V_129 , V_124 , 1 ) ;
return F_48 ( V_28 ) ;
}
static T_2 F_50 ( struct V_22 * V_28 )
{
T_2 V_130 = F_18 ( V_28 , V_131 ) ;
if ( V_130 )
F_19 ( V_28 , V_131 , 0 ) ;
return V_130 ;
}
static void F_51 ( struct V_22 * V_28 , T_2 V_132 )
{
F_19 ( V_28 , F_52 ( 0 ) , V_132 ) ;
F_37 ( V_28 ) ;
}
static void F_53 ( struct V_22 * V_28 )
{
T_2 V_130 , V_132 ;
int V_47 ;
V_132 = F_18 ( V_28 , V_133 ) ;
if ( V_28 -> error )
return;
for ( V_47 = 5 ; V_47 > 0 ; -- V_47 ) {
F_51 ( V_28 , V_132 ) ;
V_130 = F_50 ( V_28 ) ;
if ( V_28 -> error )
return;
switch ( V_130 ) {
case V_134 :
++ V_132 ;
break;
case 0 :
V_28 -> V_132 = V_132 ;
F_54 ( & V_28 -> V_24 ,
L_13 , V_132 ) ;
return;
default:
F_15 ( & V_28 -> V_24 ,
L_14 , V_130 ) ;
V_28 -> error = - V_13 ;
}
} ;
F_15 ( & V_28 -> V_24 , L_15 ) ;
V_28 -> error = - V_135 ;
}
static void F_55 ( struct V_22 * V_28 )
{
T_2 V_130 ;
V_130 = F_50 ( V_28 ) ;
if ( V_28 -> error )
return;
switch ( V_130 ) {
case 0 :
V_28 -> V_136 = 1 ;
return;
case V_134 :
F_53 ( V_28 ) ;
if ( ! V_28 -> error )
V_28 -> V_136 = 1 ;
return;
default:
F_15 ( & V_28 -> V_24 ,
L_16 , V_130 ) ;
V_28 -> error = - V_13 ;
}
}
static void F_56 ( struct V_137 * V_33 , const struct V_137 * V_107 ,
const struct V_137 * V_47 ,
const struct V_137 * V_8 )
{
V_33 -> V_138 = V_107 -> V_138 * V_47 -> V_139 / V_8 -> V_139 ;
V_33 -> V_140 = V_107 -> V_140 * V_47 -> V_141 / V_8 -> V_141 ;
V_33 -> V_139 = V_107 -> V_139 * V_47 -> V_139 / V_8 -> V_139 ;
V_33 -> V_141 = V_107 -> V_141 * V_47 -> V_141 / V_8 -> V_141 ;
}
static int F_57 ( struct V_22 * V_28 )
{
struct V_137 * V_142 , V_33 ;
T_2 V_130 ;
int V_11 ;
V_142 = & V_28 -> V_143 ;
F_34 ( V_28 , V_144 , V_142 -> V_139 , V_142 -> V_141 ,
V_142 -> V_138 , V_142 -> V_140 ) ;
F_56 ( & V_33 , & V_28 -> V_145 , & V_28 -> V_143 ,
& V_28 -> V_146 ) ;
F_34 ( V_28 , V_147 , V_33 . V_139 , V_33 . V_141 ,
V_33 . V_138 , V_33 . V_140 ) ;
F_26 ( V_28 , 500 , V_78 ) ;
F_26 ( V_28 , 500 , V_79 ) ;
V_130 = F_50 ( V_28 ) ;
V_11 = F_48 ( V_28 ) ;
if ( V_11 < 0 )
return V_11 ;
switch ( V_130 ) {
case 0 :
break;
case V_134 :
F_51 ( V_28 , V_148 ) ;
V_130 = F_50 ( V_28 ) ;
V_11 = F_48 ( V_28 ) ;
if ( V_11 < 0 )
return V_11 ;
if ( V_130 ) {
F_15 ( & V_28 -> V_24 ,
L_17 , V_130 ) ;
V_28 -> error = - V_13 ;
}
F_51 ( V_28 , V_28 -> V_149 ) ;
F_55 ( V_28 ) ;
break;
default:
F_15 ( & V_28 -> V_24 , L_18 , V_130 ) ;
return - V_13 ;
}
if ( ! V_28 -> V_136 )
return 0 ;
V_142 = & V_28 -> V_145 ;
F_34 ( V_28 , F_58 ( 0 ) , V_142 -> V_139 , V_142 -> V_141 ) ;
F_51 ( V_28 , V_28 -> V_149 ) ;
F_55 ( V_28 ) ;
return F_48 ( V_28 ) ;
}
static void F_59 ( struct V_22 * V_28 )
{
T_2 V_150 = V_121 [ V_28 -> V_151 ] . V_152 ;
struct V_137 * V_33 = & V_28 -> V_145 ;
F_34 ( V_28 , F_58 ( 0 ) ,
V_33 -> V_139 , V_33 -> V_141 , V_150 ,
V_65 >> 2 , V_64 >> 2 ,
V_153 , V_154 ,
V_155 , V_156 ,
V_28 -> V_149 , V_157 ) ;
F_37 ( V_28 ) ;
F_55 ( V_28 ) ;
}
static void F_60 ( struct V_22 * V_28 , int V_54 )
{
F_16 ( V_28 , V_158 , 800 ) ;
F_16 ( V_28 , V_159 , 511 ) ;
F_16 ( V_28 , V_160 , 0 ) ;
F_16 ( V_28 , V_161 , V_54 ) ;
}
static void F_61 ( struct V_22 * V_28 , int V_54 )
{
struct V_162 * V_163 = & V_28 -> V_164 [ V_54 ] ;
F_62 ( V_163 -> V_163 , V_163 -> V_165 ) ;
}
static void F_63 ( struct V_22 * V_28 , int V_54 )
{
struct V_162 * V_163 = & V_28 -> V_164 [ V_54 ] ;
F_62 ( V_163 -> V_163 , ! V_163 -> V_165 ) ;
}
static int F_64 ( struct V_22 * V_28 )
{
int V_11 ;
V_11 = F_65 ( V_166 , V_28 -> V_167 ) ;
if ( V_11 < 0 )
goto V_130;
V_11 = F_66 ( V_28 -> clock , V_28 -> V_57 ) ;
if ( V_11 < 0 )
goto V_168;
V_11 = F_67 ( V_28 -> clock ) ;
if ( V_11 < 0 )
goto V_168;
F_14 ( 1 , V_42 , & V_28 -> V_24 , L_19 ,
F_68 ( V_28 -> clock ) ) ;
F_63 ( V_28 , V_169 ) ;
F_28 ( 50 , 100 ) ;
F_63 ( V_28 , V_170 ) ;
return 0 ;
V_168:
F_69 ( V_166 , V_28 -> V_167 ) ;
V_130:
F_15 ( & V_28 -> V_24 , L_20 , V_171 , V_11 ) ;
return V_11 ;
}
static int F_70 ( struct V_22 * V_28 )
{
int V_11 ;
V_28 -> V_83 = 0 ;
V_28 -> V_136 = 0 ;
V_28 -> V_77 = 0 ;
F_61 ( V_28 , V_170 ) ;
F_61 ( V_28 , V_169 ) ;
if ( ! F_71 ( V_28 -> clock ) )
F_72 ( V_28 -> clock ) ;
V_11 = F_69 ( V_166 ,
V_28 -> V_167 ) ;
if ( V_11 < 0 )
F_15 ( & V_28 -> V_24 , L_21 ) ;
return 0 ;
}
static void F_73 ( struct V_22 * V_28 )
{
F_16 ( V_28 , V_172 , V_74 ) ;
F_16 ( V_28 , V_173 , 0 ) ;
F_16 ( V_28 , V_174 , 1 ) ;
F_16 ( V_28 , V_175 , V_75 ) ;
F_16 ( V_28 , V_73 , V_75 ) ;
}
static void F_74 ( struct V_22 * V_28 )
{
V_28 -> V_151 = 0 ;
V_28 -> V_149 = 10000 / 15 ;
V_28 -> V_132 = V_28 -> V_149 ;
V_28 -> V_88 = 0 ;
}
static int F_75 ( struct V_22 * V_28 )
{
struct V_30 * V_31 = F_10 ( & V_28 -> V_24 ) ;
const struct V_176 * V_4 ;
int V_11 ;
V_11 = F_76 ( & V_4 , V_177 , & V_31 -> V_2 ) ;
if ( V_11 < 0 ) {
F_77 ( & V_31 -> V_2 , L_22 ,
V_177 ) ;
return V_11 ;
}
V_11 = F_1 ( & V_31 -> V_2 , & V_28 -> V_4 , V_4 -> V_178 / 2 ,
( T_2 * ) V_4 -> V_6 ) ;
F_78 ( V_4 ) ;
return V_11 ;
}
static int F_79 ( struct V_18 * V_24 , int V_179 )
{
struct V_22 * V_28 = F_8 ( V_24 ) ;
int V_11 = 0 ;
F_80 ( & V_28 -> V_180 ) ;
if ( ! V_179 != V_28 -> V_181 )
goto V_182;
if ( V_179 ) {
if ( V_28 -> V_4 == NULL )
F_75 ( V_28 ) ;
F_74 ( V_28 ) ;
V_11 = F_64 ( V_28 ) ;
if ( V_11 < 0 )
goto V_182;
F_73 ( V_28 ) ;
F_31 ( V_28 ) ;
F_16 ( V_28 , V_183 , 1 ) ;
F_32 ( V_28 ) ;
V_11 = F_49 ( V_28 ) ;
if ( V_11 < 0 )
goto V_182;
F_36 ( V_28 ) ;
F_35 ( V_28 ) ;
V_11 = F_48 ( V_28 ) ;
if ( ! V_11 )
V_28 -> V_181 ++ ;
} else {
F_70 ( V_28 ) ;
V_28 -> V_181 -- ;
}
V_182:
F_81 ( & V_28 -> V_180 ) ;
if ( ! V_11 && V_179 )
V_11 = F_82 ( & V_28 -> V_23 . V_21 ) ;
return V_11 ;
}
static void F_83 ( struct V_22 * V_28 , int V_85 )
{
F_34 ( V_28 , V_184 , V_85 , 1 ) ;
}
static int F_84 ( struct V_18 * V_24 , int V_179 )
{
struct V_22 * V_28 = F_8 ( V_24 ) ;
int V_11 ;
F_80 ( & V_28 -> V_180 ) ;
if ( V_28 -> V_83 == ! ! V_179 ) {
V_11 = 0 ;
goto V_182;
}
if ( V_179 ) {
F_59 ( V_28 ) ;
V_11 = F_57 ( V_28 ) ;
if ( V_11 < 0 )
goto V_182;
F_83 ( V_28 , 1 ) ;
F_16 ( V_28 , 0xb0cc , 0x000b ) ;
} else {
F_83 ( V_28 , 0 ) ;
}
V_11 = F_48 ( V_28 ) ;
if ( ! V_11 )
V_28 -> V_83 = ! V_28 -> V_83 ;
V_182:
F_81 ( & V_28 -> V_180 ) ;
return V_11 ;
}
static int F_85 ( struct V_18 * V_24 ,
struct V_185 * V_186 )
{
struct V_22 * V_28 = F_8 ( V_24 ) ;
F_80 ( & V_28 -> V_180 ) ;
V_186 -> V_187 . V_188 = V_28 -> V_132 ;
V_186 -> V_187 . V_189 = 10000 ;
F_81 ( & V_28 -> V_180 ) ;
return 0 ;
}
static void F_86 ( struct V_22 * V_28 ,
struct V_185 * V_186 )
{
struct V_190 * V_9 = & V_186 -> V_187 ;
if ( V_186 -> V_187 . V_189 == 0 )
V_28 -> V_149 = V_148 ;
else
V_28 -> V_149 = F_87 ( V_191 ,
V_9 -> V_188 * 10000 / V_9 -> V_189 ,
V_157 ,
V_148 ) ;
V_28 -> V_132 = V_28 -> V_149 ;
if ( V_28 -> V_136 ) {
F_51 ( V_28 , V_28 -> V_149 ) ;
F_55 ( V_28 ) ;
}
* V_9 = (struct V_190 ) { V_28 -> V_132 , 10000 } ;
if ( V_28 -> V_132 == V_28 -> V_149 )
F_54 ( & V_28 -> V_24 , L_23 ,
V_28 -> V_132 ) ;
}
static int F_88 ( struct V_18 * V_24 ,
struct V_185 * V_186 )
{
struct V_22 * V_28 = F_8 ( V_24 ) ;
F_80 ( & V_28 -> V_180 ) ;
F_86 ( V_28 , V_186 ) ;
F_81 ( & V_28 -> V_180 ) ;
return 0 ;
}
static int F_89 ( struct V_18 * V_24 ,
struct V_192 * V_193 ,
struct V_194 * V_195 )
{
if ( V_195 -> V_196 > V_148 - V_157 ||
V_195 -> V_197 != V_198 )
return - V_13 ;
F_90 ( & V_195 -> V_139 , V_199 ,
V_200 , 1 ,
& V_195 -> V_141 , V_201 ,
V_202 , 1 , 0 ) ;
V_195 -> V_187 . V_188 = V_157 + V_195 -> V_196 ;
V_195 -> V_187 . V_189 = 10000 ;
return 0 ;
}
static int F_91 ( struct V_18 * V_24 ,
struct V_192 * V_193 ,
struct V_203 * V_123 )
{
if ( V_123 -> V_197 == V_198 ) {
if ( V_123 -> V_196 > 0 )
return - V_13 ;
V_123 -> V_123 = V_204 ;
return 0 ;
}
if ( V_123 -> V_196 >= F_24 ( V_121 ) )
return - V_13 ;
V_123 -> V_123 = V_121 [ V_123 -> V_196 ] . V_123 ;
return 0 ;
}
static int F_92 ( struct V_18 * V_24 ,
struct V_192 * V_193 ,
struct V_205 * V_206 )
{
int V_9 ;
if ( V_206 -> V_196 > 0 )
return - V_13 ;
if ( V_206 -> V_197 == V_198 ) {
V_206 -> V_123 = V_204 ;
V_206 -> V_207 = V_200 ;
V_206 -> V_208 = V_200 ;
V_206 -> V_209 = V_202 ;
V_206 -> V_210 = V_202 ;
return 0 ;
}
V_9 = F_24 ( V_121 ) ;
while ( -- V_9 )
if ( V_206 -> V_123 == V_121 [ V_9 ] . V_123 )
break;
V_206 -> V_123 = V_121 [ V_9 ] . V_123 ;
V_206 -> V_207 = V_199 ;
V_206 -> V_208 = V_200 ;
V_206 -> V_210 = V_201 ;
V_206 -> V_209 = V_202 ;
return 0 ;
}
static void F_93 ( struct V_119 * V_120 )
{
V_120 -> V_139 = V_200 ;
V_120 -> V_141 = V_202 ;
V_120 -> V_123 = V_204 ;
V_120 -> V_122 = V_211 ;
V_120 -> V_212 = V_213 ;
}
static int F_94 ( struct V_119 * V_120 )
{
int V_151 ;
F_90 ( & V_120 -> V_139 , V_199 ,
V_200 , 1 ,
& V_120 -> V_141 , V_201 ,
V_202 , 1 , 0 ) ;
V_151 = F_47 ( V_120 ) ;
V_120 -> V_122 = V_121 [ V_151 ] . V_122 ;
V_120 -> V_123 = V_121 [ V_151 ] . V_123 ;
V_120 -> V_212 = V_213 ;
return V_151 ;
}
static int F_95 ( struct V_18 * V_24 , struct V_192 * V_193 ,
struct V_214 * V_215 )
{
struct V_22 * V_28 = F_8 ( V_24 ) ;
const struct V_216 * V_151 ;
struct V_119 * V_120 ;
if ( V_215 -> V_217 == V_218 ) {
V_120 = F_96 ( V_193 , V_215 -> V_197 ) ;
V_215 -> V_219 = * V_120 ;
return 0 ;
}
V_120 = & V_215 -> V_219 ;
if ( V_215 -> V_197 == V_198 ) {
F_93 ( V_120 ) ;
return 0 ;
}
V_120 -> V_212 = V_213 ;
F_80 ( & V_28 -> V_180 ) ;
V_151 = & V_121 [ V_28 -> V_151 ] ;
V_120 -> V_139 = V_28 -> V_145 . V_139 ;
V_120 -> V_141 = V_28 -> V_145 . V_141 ;
V_120 -> V_123 = V_151 -> V_123 ;
V_120 -> V_122 = V_151 -> V_122 ;
F_81 ( & V_28 -> V_180 ) ;
return 0 ;
}
static int F_97 ( struct V_18 * V_24 , struct V_192 * V_193 ,
struct V_214 * V_215 )
{
struct V_119 * V_120 = & V_215 -> V_219 ;
struct V_22 * V_28 = F_8 ( V_24 ) ;
const struct V_216 * V_151 ;
int V_11 = 0 ;
if ( V_215 -> V_217 == V_218 ) {
* F_96 ( V_193 , V_215 -> V_197 ) = * V_120 ;
return 0 ;
}
if ( V_215 -> V_197 == V_198 ) {
F_93 ( V_120 ) ;
return 0 ;
}
F_80 ( & V_28 -> V_180 ) ;
if ( V_28 -> V_83 ) {
F_81 ( & V_28 -> V_180 ) ;
return - V_220 ;
}
V_28 -> V_151 = F_94 ( V_120 ) ;
V_151 = & V_121 [ V_28 -> V_151 ] ;
V_120 -> V_123 = V_151 -> V_123 ;
V_120 -> V_122 = V_151 -> V_122 ;
V_120 -> V_139 = V_28 -> V_145 . V_139 ;
V_120 -> V_141 = V_28 -> V_145 . V_141 ;
F_81 ( & V_28 -> V_180 ) ;
return V_11 ;
}
static enum V_221 F_98 ( V_191 V_197 , V_191 V_222 )
{
switch ( V_222 ) {
case V_223 :
return V_197 ? V_224 : V_225 ;
case V_226 :
return V_197 ? V_227 : V_228 ;
case V_229 :
return V_197 ? V_230 : V_228 ;
case V_231 :
return V_197 ? V_230 : V_224 ;
default:
return V_230 ;
}
}
static int F_99 ( V_191 V_222 )
{
return V_222 == V_223 ||
V_222 == V_229 ;
}
static int F_100 ( struct V_18 * V_24 ,
struct V_192 * V_193 ,
struct V_232 * V_233 )
{
static enum V_221 V_234 ;
struct V_22 * V_28 = F_8 ( V_24 ) ;
V_234 = F_98 ( V_233 -> V_197 , V_233 -> V_222 ) ;
switch ( V_234 ) {
case V_230 :
return - V_13 ;
case V_225 :
V_233 -> V_33 = V_235 ;
return 0 ;
default:
break;
}
if ( V_233 -> V_217 == V_218 ) {
if ( V_234 == V_224 )
V_233 -> V_33 = * F_101 ( V_193 , V_233 -> V_197 ) ;
else
V_233 -> V_33 = * F_102 ( V_193 , V_233 -> V_197 ) ;
return 0 ;
}
F_80 ( & V_28 -> V_180 ) ;
switch ( V_234 ) {
case V_228 :
V_233 -> V_33 = V_28 -> V_143 ;
break;
case V_224 :
V_233 -> V_33 = V_28 -> V_146 ;
break;
case V_227 :
V_233 -> V_33 = V_28 -> V_145 ;
break;
default:
break;
}
if ( F_99 ( V_233 -> V_222 ) ) {
V_233 -> V_33 . V_138 = 0 ;
V_233 -> V_33 . V_140 = 0 ;
}
F_81 ( & V_28 -> V_180 ) ;
return 0 ;
}
static void F_103 ( V_191 * V_236 , V_191 * V_37 , V_191 V_237 )
{
if ( * V_37 > V_237 )
* V_37 = V_237 ;
if ( * V_236 + * V_37 > V_237 )
* V_236 = V_237 - * V_37 ;
* V_236 &= ~ 1 ;
* V_37 &= ~ 1 ;
if ( * V_37 < V_199 )
* V_37 = V_199 ;
}
static void F_104 ( struct V_137 * V_33 , V_191 V_139 , V_191 V_141 )
{
F_103 ( & V_33 -> V_138 , & V_33 -> V_139 , V_139 ) ;
F_103 ( & V_33 -> V_140 , & V_33 -> V_141 , V_141 ) ;
}
static void F_105 ( struct V_137 * * V_238 ,
enum V_221 V_239 ,
struct V_137 * V_107 )
{
struct V_137 * V_33 , * V_240 ;
enum V_221 V_9 = V_239 ;
* V_238 [ V_239 ] = * V_107 ;
do {
V_33 = V_238 [ V_9 ] ;
V_240 = V_238 [ V_9 - 1 ] ;
F_104 ( V_33 , V_240 -> V_139 , V_240 -> V_141 ) ;
} while ( ++ V_9 != V_230 );
* V_107 = * V_238 [ V_239 ] ;
}
static bool F_106 ( const struct V_137 * V_241 ,
const struct V_137 * V_242 )
{
return ! memcmp ( V_241 , V_242 , sizeof( * V_241 ) ) ;
}
static int F_107 ( struct V_18 * V_24 ,
struct V_192 * V_193 ,
struct V_232 * V_233 )
{
static enum V_221 V_234 ;
struct V_22 * V_28 = F_8 ( V_24 ) ;
struct V_137 * * V_238 ;
int V_11 = 0 ;
V_234 = F_98 ( V_233 -> V_197 , V_233 -> V_222 ) ;
if ( V_234 == V_230 || F_99 ( V_233 -> V_222 ) )
return - V_13 ;
if ( V_234 == V_224 ) {
V_233 -> V_33 . V_138 = 0 ;
V_233 -> V_33 . V_140 = 0 ;
}
if ( V_233 -> V_217 == V_218 ) {
V_238 = (struct V_137 * [] ) {
& V_235 ,
F_102 ( V_193 , V_198 ) ,
F_101 ( V_193 , V_198 ) ,
F_102 (fh, PAD_OUT)
} ;
F_105 ( V_238 , V_234 , & V_233 -> V_33 ) ;
return 0 ;
}
V_238 = (struct V_137 * [] ) {
& V_235 ,
& V_28 -> V_143 ,
& V_28 -> V_146 ,
& V_28 -> V_145
} ;
F_80 ( & V_28 -> V_180 ) ;
if ( V_28 -> V_83 ) {
if ( V_234 < V_227 ) {
if ( V_233 -> V_33 . V_139 < V_28 -> V_145 . V_139 )
V_233 -> V_33 . V_139 = V_28 -> V_145 . V_139 ;
if ( V_233 -> V_33 . V_141 < V_28 -> V_145 . V_141 )
V_233 -> V_33 . V_141 = V_28 -> V_145 . V_141 ;
} else {
V_233 -> V_33 . V_139 = V_28 -> V_145 . V_139 ;
V_233 -> V_33 . V_141 = V_28 -> V_145 . V_141 ;
}
}
F_105 ( V_238 , V_234 , & V_233 -> V_33 ) ;
if ( ! F_106 ( & V_28 -> V_143 , & V_235 ) ||
! F_106 ( & V_28 -> V_146 , & V_235 ) )
V_28 -> V_77 = 1 ;
if ( V_28 -> V_83 )
V_11 = F_57 ( V_28 ) ;
F_81 ( & V_28 -> V_180 ) ;
return V_11 ;
}
static int F_108 ( struct V_19 * V_20 )
{
struct V_18 * V_24 = F_5 ( V_20 ) ;
struct V_22 * V_28 = F_8 ( V_24 ) ;
int V_11 ;
F_14 ( 1 , V_42 , V_24 , L_24 , V_20 -> V_243 , V_20 -> V_43 ) ;
F_80 ( & V_28 -> V_180 ) ;
if ( V_28 -> V_181 == 0 )
goto V_244;
switch ( V_20 -> V_54 ) {
case V_245 :
F_41 ( V_28 , V_20 -> V_43 ) ;
break;
case V_246 :
F_19 ( V_28 , V_247 , V_20 -> V_43 ) ;
break;
case V_248 :
F_46 ( V_28 , V_20 -> V_43 ) ;
break;
case V_249 :
F_19 ( V_28 , V_250 , V_20 -> V_43 ) ;
break;
case V_251 :
F_44 ( V_28 , V_20 -> V_43 ) ;
break;
case V_252 :
F_38 ( V_28 ) ;
break;
case V_253 :
F_45 ( V_28 , V_20 -> V_43 ) ;
break;
case V_254 :
F_19 ( V_28 , V_255 , V_20 -> V_43 ) ;
break;
case V_256 :
F_19 ( V_28 , V_257 , V_20 -> V_43 ) ;
break;
case V_258 :
F_19 ( V_28 , F_109 ( 0 ) , V_20 -> V_43 ) ;
if ( V_28 -> V_136 )
F_37 ( V_28 ) ;
break;
case V_259 :
F_60 ( V_28 , V_20 -> V_43 ) ;
break;
}
V_244:
V_11 = F_48 ( V_28 ) ;
F_81 ( & V_28 -> V_180 ) ;
return V_11 ;
}
static int F_110 ( struct V_22 * V_28 )
{
const struct V_260 * V_261 = & V_262 ;
struct V_92 * V_23 = & V_28 -> V_23 ;
struct V_263 * V_264 = & V_23 -> V_21 ;
int V_11 ;
V_11 = F_111 ( V_264 , 16 ) ;
if ( V_11 < 0 ) {
F_15 ( & V_28 -> V_24 , L_25 , V_11 ) ;
return V_11 ;
}
V_23 -> V_91 = F_112 ( V_264 , V_261 , V_245 ,
0 , 1 , 1 , 1 ) ;
V_23 -> V_94 = F_112 ( V_264 , V_261 , V_265 ,
0 , 255 , 1 , V_266 ) ;
V_23 -> V_96 = F_112 ( V_264 , V_261 , V_267 ,
0 , 255 , 1 , V_268 ) ;
F_113 ( 3 , & V_23 -> V_91 , 0 , false ) ;
V_23 -> V_269 = F_112 ( V_264 , V_261 , V_252 , 0 , 1 , 1 , 0 ) ;
V_23 -> V_82 = F_112 ( V_264 , V_261 , V_270 , 0 , 1 , 1 , 0 ) ;
F_114 ( 2 , & V_23 -> V_269 ) ;
V_23 -> V_271 = F_115 ( V_264 , V_261 ,
V_251 ,
V_272 , 0 , V_103 ) ;
V_23 -> V_98 = F_112 ( V_264 , V_261 , V_273 ,
0 , 6000000U , 1 , 100000U ) ;
V_23 -> V_100 = F_112 ( V_264 , V_261 , V_274 ,
0 , 256 , 1 , 256 ) ;
F_113 ( 3 , & V_23 -> V_271 , 0 , false ) ;
F_115 ( V_264 , V_261 , V_253 ,
V_108 , 0 ,
V_108 ) ;
F_115 ( V_264 , V_261 , V_248 ,
V_116 , ~ 0x6f , V_112 ) ;
F_112 ( V_264 , V_261 , V_258 ,
0 , 256 , 1 , 0 ) ;
F_112 ( V_264 , V_261 , V_254 , - 127 , 127 , 1 , 0 ) ;
F_112 ( V_264 , V_261 , V_246 , - 127 , 127 , 1 , 0 ) ;
F_112 ( V_264 , V_261 , V_249 , - 127 , 127 , 1 , 0 ) ;
F_112 ( V_264 , V_261 , V_256 , - 127 , 127 , 1 , 0 ) ;
F_116 ( V_264 , V_261 , V_259 ,
F_24 ( V_275 ) - 1 ,
0 , 0 , V_275 ) ;
if ( V_264 -> error ) {
F_15 ( & V_28 -> V_24 , L_26 ,
V_264 -> error ) ;
V_11 = V_264 -> error ;
F_117 ( V_264 ) ;
return V_11 ;
}
V_28 -> V_24 . V_276 = V_264 ;
return 0 ;
}
static int F_118 ( struct V_18 * V_24 , struct V_192 * V_193 )
{
struct V_119 * V_120 ;
V_120 = F_96 ( V_193 , V_198 ) ;
F_93 ( V_120 ) ;
if ( F_7 ( V_24 ) )
return 0 ;
V_120 = F_96 ( V_193 , V_277 ) ;
V_120 -> V_122 = V_121 [ 0 ] . V_122 ;
V_120 -> V_123 = V_121 [ 0 ] . V_123 ;
V_120 -> V_139 = V_235 . V_139 ;
V_120 -> V_141 = V_235 . V_141 ;
V_120 -> V_212 = V_213 ;
* F_102 ( V_193 , V_198 ) = V_235 ;
* F_101 ( V_193 , V_198 ) = V_235 ;
* F_102 ( V_193 , V_277 ) = V_235 ;
return 0 ;
}
static int F_119 ( struct V_22 * V_28 )
{
T_2 V_278 = 0 , V_279 = 0 , V_280 = 0 ;
int V_11 ;
V_278 = F_18 ( V_28 , V_281 ) ;
V_279 = F_18 ( V_28 , V_282 ) & 0xff ;
V_280 = F_18 ( V_28 , V_283 ) ;
V_11 = F_48 ( V_28 ) ;
if ( V_11 < 0 )
return V_11 ;
F_54 ( & V_28 -> V_24 , L_27 ,
V_278 , V_279 , V_280 ) ;
if ( V_278 != V_284 ) {
F_15 ( & V_28 -> V_24 , L_28 ) ;
return - V_285 ;
}
return 0 ;
}
static int F_120 ( struct V_18 * V_24 )
{
struct V_22 * V_28 = F_8 ( V_24 ) ;
int V_11 ;
V_11 = F_121 ( V_24 -> V_286 , & V_28 -> V_27 ) ;
if ( V_11 < 0 )
F_15 ( V_24 , L_29 ,
V_28 -> V_27 . V_243 ) ;
else
V_11 = F_122 ( & V_28 -> V_27 . V_25 , V_198 ,
& V_28 -> V_24 . V_25 , V_198 ,
V_287 |
V_288 ) ;
return V_11 ;
}
static void F_123 ( struct V_18 * V_24 )
{
struct V_22 * V_28 = F_8 ( V_24 ) ;
F_124 ( & V_28 -> V_27 ) ;
}
static int F_125 ( struct V_22 * V_28 )
{
static const char const * V_243 [] = { L_30 , L_31 } ;
struct V_30 * V_31 = F_10 ( & V_28 -> V_24 ) ;
struct V_162 * V_289 = V_28 -> V_164 ;
int V_11 , V_9 ;
for ( V_9 = 0 ; V_9 < V_290 ; ++ V_9 ) {
int V_36 = V_291 ;
if ( V_289 [ V_9 ] . V_165 )
V_36 |= V_292 ;
V_11 = F_126 ( & V_31 -> V_2 , V_289 [ V_9 ] . V_163 , V_36 , V_243 [ V_9 ] ) ;
if ( V_11 < 0 ) {
F_15 ( V_31 , L_32 , V_243 [ V_9 ] ) ;
return V_11 ;
}
}
return 0 ;
}
static int F_127 ( struct V_162 * V_164 , struct V_1 * V_2 )
{
static const char * const V_293 [] = {
L_33 ,
L_34 ,
} ;
struct V_294 * V_295 = V_2 -> V_296 ;
enum V_297 V_36 ;
int V_11 , V_9 ;
for ( V_9 = 0 ; V_9 < V_290 ; ++ V_9 ) {
V_11 = F_128 ( V_295 , V_293 [ V_9 ] , 0 , & V_36 ) ;
if ( V_11 < 0 ) {
F_2 ( V_2 , L_35 , V_293 [ V_9 ] ) ;
return V_11 ;
}
V_164 [ V_9 ] . V_163 = V_11 ;
V_164 [ V_9 ] . V_165 = ! ( V_36 & V_298 ) ;
}
return 0 ;
}
static int F_129 ( struct V_22 * V_28 , struct V_1 * V_2 )
{
struct V_294 * V_295 = V_2 -> V_296 ;
struct V_294 * V_299 ;
struct V_300 V_301 ;
int V_11 ;
if ( ! V_295 ) {
F_2 ( V_2 , L_36 ) ;
return - V_13 ;
}
V_11 = F_130 ( V_295 , L_37 ,
& V_28 -> V_57 ) ;
if ( V_11 < 0 ) {
V_28 -> V_57 = V_302 ;
F_131 ( V_2 , L_38 ,
V_28 -> V_57 ) ;
}
V_11 = F_127 ( V_28 -> V_164 , V_2 ) ;
if ( V_11 < 0 )
return V_11 ;
V_299 = F_132 ( V_295 , NULL ) ;
if ( ! V_299 ) {
F_2 ( V_2 , L_39 ,
V_295 -> V_303 ) ;
return - V_13 ;
}
F_133 ( V_299 , & V_301 ) ;
F_134 ( V_299 ) ;
V_28 -> V_125 = V_301 . V_125 ;
switch ( V_28 -> V_125 ) {
case V_126 :
V_28 -> V_129 = V_301 . V_304 . V_305 . V_306 ;
break;
case V_307 :
break;
default:
F_2 ( V_2 , L_40 ,
V_295 -> V_303 ) ;
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
F_136 ( V_24 , & V_308 ) ;
V_24 -> V_309 = V_310 ;
F_137 ( V_24 , V_28 ) ;
snprintf ( V_24 -> V_243 , sizeof( V_24 -> V_243 ) , L_41 ,
F_138 ( V_31 -> V_41 ) , V_31 -> V_29 ) ;
V_24 -> V_311 = & V_312 ;
V_24 -> V_36 |= V_313 ;
V_28 -> V_314 . V_36 = V_315 ;
V_24 -> V_25 . type = V_26 ;
V_11 = F_139 ( & V_24 -> V_25 , V_316 , & V_28 -> V_314 , 0 ) ;
if ( V_11 < 0 )
goto V_130;
V_24 = & V_28 -> V_24 ;
F_140 ( V_24 , V_31 , & V_317 ) ;
snprintf ( V_24 -> V_243 , sizeof( V_24 -> V_243 ) , L_42 ,
F_138 ( V_31 -> V_41 ) , V_31 -> V_29 ) ;
V_24 -> V_311 = & V_318 ;
V_24 -> V_36 |= V_313 ;
V_28 -> V_319 [ V_198 ] . V_36 = V_320 ;
V_28 -> V_319 [ V_277 ] . V_36 = V_315 ;
V_24 -> V_25 . type = V_321 ;
V_11 = F_139 ( & V_24 -> V_25 , V_322 , V_28 -> V_319 , 0 ) ;
if ( ! V_11 )
return 0 ;
F_141 ( & V_28 -> V_27 . V_25 ) ;
V_130:
F_2 ( & V_31 -> V_2 , L_43 , V_24 -> V_243 ) ;
return V_11 ;
}
static int F_142 ( struct V_22 * V_28 )
{
struct V_30 * V_31 = F_10 ( & V_28 -> V_24 ) ;
int V_11 ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_166 ; V_9 ++ )
V_28 -> V_167 [ V_9 ] . V_323 = V_324 [ V_9 ] ;
V_11 = F_143 ( & V_31 -> V_2 , V_166 ,
V_28 -> V_167 ) ;
if ( V_11 < 0 )
F_15 ( V_31 , L_44 ) ;
return V_11 ;
}
static int F_144 ( struct V_30 * V_31 ,
const struct V_325 * V_54 )
{
struct V_22 * V_28 ;
int V_11 ;
V_28 = F_3 ( & V_31 -> V_2 , sizeof( * V_28 ) , V_15 ) ;
if ( ! V_28 )
return - V_326 ;
F_145 ( & V_28 -> V_180 ) ;
V_28 -> V_143 = V_235 ;
V_28 -> V_146 = V_235 ;
V_28 -> V_145 = V_235 ;
V_11 = F_129 ( V_28 , & V_31 -> V_2 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_135 ( V_28 , V_31 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_125 ( V_28 ) ;
if ( V_11 < 0 )
goto V_327;
V_11 = F_142 ( V_28 ) ;
if ( V_11 < 0 )
goto V_327;
V_28 -> clock = F_146 ( V_28 -> V_24 . V_2 , V_328 ) ;
if ( F_71 ( V_28 -> clock ) ) {
V_11 = - V_329 ;
goto V_327;
}
V_11 = F_64 ( V_28 ) ;
if ( V_11 < 0 ) {
V_11 = - V_329 ;
goto V_327;
}
F_73 ( V_28 ) ;
V_11 = F_119 ( V_28 ) ;
F_70 ( V_28 ) ;
if ( V_11 < 0 )
goto V_327;
V_11 = F_110 ( V_28 ) ;
if ( V_11 < 0 )
goto V_327;
V_11 = F_147 ( & V_28 -> V_24 ) ;
if ( V_11 < 0 )
goto V_330;
return 0 ;
V_330:
F_117 ( V_28 -> V_24 . V_276 ) ;
V_327:
F_141 ( & V_28 -> V_24 . V_25 ) ;
F_141 ( & V_28 -> V_27 . V_25 ) ;
return V_11 ;
}
static int F_148 ( struct V_30 * V_31 )
{
struct V_18 * V_24 = F_149 ( V_31 ) ;
struct V_22 * V_28 = F_8 ( V_24 ) ;
F_150 ( V_24 ) ;
F_117 ( V_24 -> V_276 ) ;
F_141 ( & V_24 -> V_25 ) ;
V_24 = & V_28 -> V_27 ;
F_124 ( V_24 ) ;
F_141 ( & V_24 -> V_25 ) ;
return 0 ;
}
