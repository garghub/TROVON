static int F_1 ( T_1 V_1 , char * V_2 )
{
unsigned int V_3 ;
struct V_4 * V_5 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_6 ) ; V_3 ++ ) {
V_5 = & V_6 [ V_3 ] ;
if ( V_1 == V_5 -> V_7 ) {
V_2 [ 0 ] = V_5 -> V_2 [ 0 ] ;
V_2 [ 1 ] = V_5 -> V_2 [ 1 ] ;
return 0 ;
}
}
return 1 ;
}
static int F_3 ( struct V_8 * V_9 , int signal )
{
struct V_10 * V_11 = F_4 ( V_9 ) ;
F_5 ( F_6 ( V_11 ) , signal < 0 || signal > 100 ,
L_1
L_2 , V_12 , signal ) ;
if ( signal < 0 )
signal = 0 ;
else if ( signal > 100 )
signal = 100 ;
return signal ;
}
int F_7 ( struct V_8 * V_9 )
{
int V_13 ;
T_1 V_14 [ V_15 ] ;
struct V_10 * V_11 = F_4 ( V_9 ) ;
V_13 = F_8 ( & V_11 -> V_16 , V_14 ) ;
if ( V_13 )
return V_13 ;
F_9 ( V_9 , V_14 ) ;
return 0 ;
}
int F_10 ( struct V_8 * V_9 )
{
int V_13 ;
struct V_10 * V_11 = F_4 ( V_9 ) ;
struct V_17 * V_16 = & V_11 -> V_16 ;
char V_2 [ 2 ] ;
T_1 V_18 ;
V_13 = F_11 ( V_16 ) ;
if ( V_13 )
goto V_19;
V_13 = F_12 ( V_16 ) ;
if ( V_13 )
goto V_20;
F_13 ( ! F_14 () ) ;
V_13 = F_15 ( V_16 , & V_18 ) ;
if ( V_13 )
goto V_20;
F_16 ( & V_11 -> V_21 ) ;
V_11 -> V_1 = V_11 -> V_18 = V_18 ;
F_17 ( & V_11 -> V_21 ) ;
V_13 = F_18 ( V_16 , V_22 ) ;
if ( V_13 )
goto V_20;
V_13 = F_1 ( V_11 -> V_1 , V_2 ) ;
if ( V_13 )
goto V_20;
V_13 = F_19 ( V_9 -> V_23 , V_2 ) ;
V_20:
F_20 ( V_16 ) ;
V_19:
return V_13 ;
}
void F_21 ( struct V_10 * V_11 )
{
F_22 ( V_24 ) ;
F_23 ( & V_11 -> V_16 ) ;
F_13 ( ! F_24 ( & V_11 -> V_21 ) ) ;
F_25 ( V_11 , sizeof( struct V_10 ) ) ;
}
static int F_26 ( struct V_10 * V_11 )
{
unsigned long V_25 ;
T_2 V_26 = V_27 ;
F_27 ( & V_11 -> V_21 , V_25 ) ;
if ( V_11 -> V_28 )
V_26 |= V_29 ;
F_28 ( & V_11 -> V_21 , V_25 ) ;
return F_29 ( & V_11 -> V_16 , V_30 , V_26 ) ;
}
static int F_30 ( struct V_10 * V_11 )
{
int V_13 ;
if ( ! V_11 -> V_31 )
return - 1 ;
V_13 = F_31 ( & V_11 -> V_16 , V_11 -> V_31 -> V_14 ) ;
if ( V_13 )
return V_13 ;
if ( V_11 -> type != V_32 )
return F_26 ( V_11 ) ;
else
return F_32 ( & V_11 -> V_16 , V_11 -> V_31 -> V_14 ) ;
}
static int F_33 ( struct V_10 * V_11 )
{
struct V_33 V_34 ;
F_34 ( & V_34 ) ;
return F_35 ( & V_11 -> V_16 , & V_34 ) ;
}
int F_36 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = F_4 ( V_9 ) ;
struct V_17 * V_16 = & V_11 -> V_16 ;
struct V_35 * V_36 = & V_16 -> V_36 ;
int V_13 ;
if ( ! V_36 -> V_37 ) {
V_13 = F_37 ( V_36 ) ;
if ( V_13 )
goto V_19;
}
V_13 = F_11 ( V_16 ) ;
if ( V_13 < 0 )
goto V_19;
V_13 = F_38 ( V_16 , V_38 | V_39 ) ;
if ( V_13 < 0 )
goto V_20;
V_13 = F_26 ( V_11 ) ;
if ( V_13 )
goto V_20;
V_13 = F_33 ( V_11 ) ;
if ( V_13 )
goto V_20;
F_39 ( 10 ) ;
V_13 = F_40 ( V_16 ) ;
if ( V_13 < 0 ) {
F_41 ( F_42 ( V_16 ) ,
L_3 , V_12 ) ;
goto V_20;
}
V_13 = F_43 ( V_16 ) ;
if ( V_13 < 0 )
goto V_40;
V_13 = F_44 ( V_16 ) ;
if ( V_13 < 0 )
goto V_41;
F_45 ( V_11 ) ;
F_46 ( V_11 ) ;
F_47 ( V_42 , & V_11 -> V_25 ) ;
return 0 ;
V_41:
F_48 ( V_16 ) ;
V_40:
F_49 ( V_16 ) ;
V_20:
F_20 ( V_16 ) ;
V_19:
return V_13 ;
}
void F_50 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = F_4 ( V_9 ) ;
struct V_17 * V_16 = & V_11 -> V_16 ;
struct V_43 * V_44 ;
struct V_45 * V_46 = & V_11 -> V_46 ;
F_51 ( V_42 , & V_11 -> V_25 ) ;
F_48 ( V_16 ) ;
F_52 ( V_11 ) ;
F_53 ( V_11 ) ;
F_22 ( V_24 ) ;
F_54 ( V_16 ) ;
F_49 ( V_16 ) ;
F_20 ( V_16 ) ;
while ( ( V_44 = F_55 ( V_46 ) ) )
F_56 ( V_44 ) ;
}
int F_57 ( struct V_10 * V_11 )
{
struct V_43 * V_47 ;
struct V_33 V_48 ;
unsigned int V_49 ;
int V_13 , V_50 , V_51 ;
T_1 V_52 ;
F_58 ( F_6 ( V_11 ) , L_4 ) ;
F_16 ( & V_11 -> V_21 ) ;
V_48 = V_11 -> V_48 ;
V_49 = V_11 -> V_49 ;
V_50 = V_11 -> V_47 . V_53 ;
V_51 = V_11 -> V_47 . V_54 ;
V_52 = V_11 -> V_52 ;
F_17 ( & V_11 -> V_21 ) ;
V_13 = F_30 ( V_11 ) ;
if ( V_13 < 0 ) {
F_58 ( F_6 ( V_11 ) , L_5 , V_13 ) ;
return V_13 ;
}
V_13 = F_59 ( & V_11 -> V_16 , V_52 ) ;
if ( V_13 < 0 ) {
F_58 ( F_6 ( V_11 ) , L_6 ,
V_13 ) ;
return V_13 ;
}
F_60 ( V_11 , V_49 ) ;
V_13 = F_35 ( & V_11 -> V_16 , & V_48 ) ;
if ( V_13 < 0 ) {
F_58 ( F_6 ( V_11 ) ,
L_7 , V_13 ) ;
return V_13 ;
}
if ( V_11 -> type == V_55 ||
V_11 -> type == V_56 ||
V_11 -> type == V_32 ) {
if ( V_11 -> V_31 != NULL ) {
V_47 = F_61 ( V_11 -> V_9 , V_11 -> V_31 ) ;
if ( V_47 )
F_62 ( V_11 -> V_9 , V_47 , false ) ;
}
F_63 ( & V_11 -> V_16 , V_50 ,
V_51 , V_11 -> type ) ;
F_16 ( & V_11 -> V_21 ) ;
V_11 -> V_47 . V_57 = V_58 ;
F_17 ( & V_11 -> V_21 ) ;
}
return 0 ;
}
static void F_64 ( struct V_8 * V_9 , struct V_43 * V_44 ,
int V_59 , struct V_60 * V_60 )
{
struct V_61 * V_62 = F_65 ( V_44 ) ;
int V_3 ;
int V_63 = 1 , V_64 = 1 ;
int V_65 ;
const struct V_66 * V_67 ;
F_66 ( V_62 ) ;
if ( V_60 ) {
V_63 = ! V_60 -> V_68 ;
V_64 = V_60 -> V_64 + V_63 ;
}
if ( V_63 ) {
V_62 -> V_25 |= V_69 ;
} else {
V_62 -> V_25 &= ~ V_69 ;
}
V_65 = V_62 -> V_70 . V_71 [ 0 ] . V_72 ;
F_13 ( 0 <= V_65 && V_65 < F_2 ( V_73 ) ) ;
V_67 = & V_73 [ V_65 ] ;
F_13 ( 1 <= V_64 && V_64 <= V_67 -> V_74 ) ;
V_62 -> V_70 . V_71 [ 0 ] . V_72 = V_67 -> V_75 [ 0 ] ;
V_62 -> V_70 . V_71 [ 0 ] . V_74 = 1 ;
for ( V_3 = 1 ; V_3 < V_76 - 1 && V_3 < V_64 ; V_3 ++ ) {
V_62 -> V_70 . V_71 [ V_3 ] . V_72 = V_67 -> V_75 [ V_3 ] ;
V_62 -> V_70 . V_71 [ V_3 ] . V_74 = 1 ;
}
for (; V_3 < V_76 && V_3 < V_64 ; V_3 ++ ) {
V_62 -> V_70 . V_71 [ V_3 ] . V_72 = V_67 -> V_75 [ V_64 - 1 ] ;
V_62 -> V_70 . V_71 [ V_3 ] . V_74 = 1 ;
}
if ( V_3 < V_76 )
V_62 -> V_70 . V_71 [ V_3 ] . V_72 = - 1 ;
V_62 -> V_70 . V_77 = F_3 ( V_9 , V_59 ) ;
F_67 ( V_9 , V_44 ) ;
}
void F_68 ( struct V_78 * V_78 )
{
struct V_8 * V_9 = F_69 ( V_78 -> V_79 ) ;
struct V_10 * V_11 = F_4 ( V_9 ) ;
struct V_45 * V_80 = & V_11 -> V_46 ;
struct V_43 * V_44 ;
struct V_60 * V_60 = (struct V_60 * ) V_78 -> V_81 ;
unsigned long V_25 ;
int V_63 = ! V_60 -> V_68 ;
int V_64 = V_60 -> V_64 + V_63 ;
int V_82 = 0 ;
int V_3 , V_83 = 0 ;
V_80 = & V_11 -> V_46 ;
F_27 ( & V_80 -> V_21 , V_25 ) ;
F_70 (q, skb) {
struct V_84 * V_85 ;
struct V_61 * V_62 ;
int V_65 , V_86 ;
const struct V_66 * V_67 ;
T_1 V_87 ;
V_83 ++ ;
if ( V_60 -> V_68 && V_11 -> V_88 &&
F_71 ( V_80 , V_44 ) ) {
continue;
}
V_85 = (struct V_84 * ) V_44 -> V_89 ;
if ( F_72 ( memcmp ( V_85 -> V_90 , V_60 -> V_11 , V_15 ) ) ) {
continue;
}
V_62 = F_65 ( V_44 ) ;
V_65 = V_62 -> V_70 . V_71 [ 0 ] . V_72 ;
F_13 ( 0 <= V_65 && V_65 < F_2 ( V_73 ) ) ;
V_67 = & V_73 [ V_65 ] ;
if ( V_64 <= 0 || V_64 > V_67 -> V_74 )
continue;
V_86 = V_67 -> V_75 [ V_64 - 1 ] ;
V_87 = V_91 [ V_86 ] . V_92 ;
if ( V_87 != V_60 -> V_75 ) {
continue;
}
V_82 = 1 ;
break;
}
if ( V_82 ) {
for ( V_3 = 1 ; V_3 <= V_83 ; V_3 ++ ) {
V_44 = F_73 ( V_80 ) ;
F_64 ( V_9 , V_44 ,
V_11 -> V_88 ? V_11 -> V_77 : 0 ,
V_3 == V_83 ? V_60 : NULL ) ;
V_11 -> V_88 = 0 ;
}
}
F_28 ( & V_80 -> V_21 , V_25 ) ;
}
void F_74 ( struct V_43 * V_44 , int error )
{
struct V_61 * V_62 = F_65 ( V_44 ) ;
struct V_8 * V_9 = V_62 -> V_93 [ 0 ] ;
struct V_10 * V_11 = F_4 ( V_9 ) ;
F_66 ( V_62 ) ;
F_75 ( V_44 , sizeof( struct V_94 ) ) ;
if ( F_72 ( error ||
( V_62 -> V_25 & V_95 ) ) ) {
F_67 ( V_9 , V_44 ) ;
} else {
struct V_45 * V_80 = & V_11 -> V_46 ;
F_76 ( V_80 , V_44 ) ;
while ( F_77 ( V_80 ) > V_96 ) {
F_64 ( V_9 , F_55 ( V_80 ) ,
V_11 -> V_88 ? V_11 -> V_77 : 0 ,
NULL ) ;
V_11 -> V_88 = 0 ;
}
}
}
static int F_78 ( T_1 * V_97 , T_1 V_98 , T_3 V_99 )
{
static const T_1 V_100 [] = {
[ F_79 ( V_101 ) ] = 1 ,
[ F_79 ( V_102 ) ] = 2 ,
[ F_79 ( V_103 ) ] = 11 ,
[ F_79 ( V_104 ) ] = 11 ,
[ F_79 ( V_105 ) ] = 6 ,
[ F_79 ( V_106 ) ] = 9 ,
[ F_79 ( V_107 ) ] = 12 ,
[ F_79 ( V_108 ) ] = 18 ,
[ F_79 ( V_109 ) ] = 24 ,
[ F_79 ( V_110 ) ] = 36 ,
[ F_79 ( V_111 ) ] = 48 ,
[ F_79 ( V_112 ) ] = 54 ,
} ;
T_2 V_113 = ( T_2 ) V_99 * 8 ;
T_2 V_114 ;
V_114 = V_100 [ F_79 ( V_98 ) ] ;
if ( V_114 == 0 )
return - V_115 ;
switch ( V_98 ) {
case V_103 :
V_113 = ( 2 * V_113 ) + 10 ;
break;
case V_104 :
if ( V_97 ) {
T_2 V_116 = V_113 % 11 ;
* V_97 &= ~ V_117 ;
if ( 0 < V_116 && V_116 <= 3 ) {
* V_97 |= V_117 ;
}
}
V_113 += 10 ;
break;
}
return V_113 / V_114 ;
}
static void F_80 ( struct V_10 * V_11 , struct V_94 * V_118 ,
struct V_84 * V_119 ,
struct V_61 * V_62 )
{
V_118 -> V_120 = 0 ;
if ( V_62 -> V_25 & V_121 )
V_118 -> V_120 |= V_122 ;
if ( V_62 -> V_25 & V_95 )
V_118 -> V_120 |= V_123 ;
if ( F_81 ( V_119 -> V_124 ) )
V_118 -> V_120 |= V_125 ;
if ( V_62 -> V_120 . V_71 [ 0 ] . V_25 & V_126 )
V_118 -> V_120 |= V_127 ;
if ( V_62 -> V_120 . V_71 [ 0 ] . V_25 & V_128 )
V_118 -> V_120 |= V_129 ;
}
static bool F_82 ( struct V_10 * V_11 , struct V_43 * V_47 )
{
if ( ! V_11 -> V_47 . V_130 )
return false ;
if ( V_11 -> V_47 . V_130 -> V_131 != V_47 -> V_131 )
return false ;
return ! memcmp ( V_47 -> V_89 , V_11 -> V_47 . V_130 -> V_89 , V_47 -> V_131 ) ;
}
static void F_83 ( struct V_10 * V_11 )
{
F_13 ( F_84 ( & V_11 -> V_16 . V_132 ) ) ;
F_85 ( V_11 -> V_47 . V_130 ) ;
V_11 -> V_47 . V_130 = NULL ;
}
static void F_86 ( struct V_10 * V_11 )
{
F_87 ( & V_11 -> V_16 . V_132 ) ;
F_83 ( V_11 ) ;
F_88 ( & V_11 -> V_16 . V_132 ) ;
}
static int F_62 ( struct V_8 * V_9 , struct V_43 * V_47 ,
bool V_133 )
{
struct V_10 * V_11 = F_4 ( V_9 ) ;
int V_13 , V_134 , V_135 , V_136 = 0 ;
T_2 V_137 , V_138 = 0 ;
T_2 V_139 = V_47 -> V_131 + 4 ;
unsigned long V_140 , V_141 ;
struct V_142 * V_143 ;
F_87 ( & V_11 -> V_16 . V_132 ) ;
if ( F_82 ( V_11 , V_47 ) ) {
V_13 = 0 ;
goto V_144;
}
V_135 = 1 + F_89 ( & V_11 -> V_16 ) + V_139 ;
V_143 = F_90 ( V_135 * sizeof( struct V_142 ) , V_145 ) ;
if ( ! V_143 ) {
V_13 = - V_146 ;
goto V_144;
}
V_13 = F_91 ( & V_11 -> V_16 , 0 , V_147 ) ;
if ( V_13 < 0 )
goto V_19;
V_13 = F_92 ( & V_11 -> V_16 , & V_137 , V_147 ) ;
if ( V_13 < 0 )
goto V_148;
if ( V_133 && V_137 & 0x2 ) {
V_13 = - V_149 ;
goto V_148;
}
V_140 = V_58 + V_150 / 2 ;
V_141 = V_58 + V_150 / 10 ;
while ( V_137 & 0x2 ) {
V_13 = F_92 ( & V_11 -> V_16 , & V_137 , V_147 ) ;
if ( V_13 < 0 )
goto V_148;
if ( F_93 ( V_141 ) ) {
V_141 = V_58 + V_150 / 10 ;
F_41 ( F_6 ( V_11 ) ,
L_8 ) ;
if ( F_93 ( V_140 ) ) {
F_41 ( F_6 ( V_11 ) ,
L_9 ) ;
V_13 = - V_151 ;
goto V_152;
}
}
F_39 ( 20 ) ;
}
V_143 [ V_136 ] . V_14 = V_153 ;
V_143 [ V_136 ] . V_154 = V_139 - 1 ;
V_136 ++ ;
if ( F_89 ( & V_11 -> V_16 ) ) {
V_143 [ V_136 ] . V_14 = V_155 ;
V_143 [ V_136 ] . V_154 = V_139 - 1 ;
V_136 ++ ;
}
for ( V_138 = 0 ; V_138 < V_47 -> V_131 ; V_138 ++ ) {
V_143 [ V_136 ] . V_14 = V_153 ;
V_143 [ V_136 ] . V_154 = * ( ( T_1 * ) ( V_47 -> V_89 + V_138 ) ) ;
V_136 ++ ;
}
for ( V_138 = 0 ; V_138 < 4 ; V_138 ++ ) {
V_143 [ V_136 ] . V_14 = V_153 ;
V_143 [ V_136 ] . V_154 = 0x0 ;
V_136 ++ ;
}
F_94 ( V_136 != V_135 ) ;
V_13 = F_95 ( & V_11 -> V_16 , V_143 , V_135 ) ;
V_148:
V_140 = V_58 + V_150 / 2 ;
V_134 = F_91 ( & V_11 -> V_16 , 1 , V_147 ) ;
while ( V_134 < 0 ) {
if ( V_133 || F_93 ( V_140 ) ) {
V_134 = - V_151 ;
break;
}
F_39 ( 20 ) ;
V_134 = F_91 ( & V_11 -> V_16 , 1 , V_147 ) ;
}
if ( V_134 < 0 )
F_41 ( F_6 ( V_11 ) , L_10
L_11 ) ;
if ( V_13 < 0 || V_134 < 0 ) {
if ( V_13 >= 0 )
V_13 = V_134 ;
F_83 ( V_11 ) ;
goto V_19;
}
F_83 ( V_11 ) ;
V_11 -> V_47 . V_130 = V_47 ;
V_47 = NULL ;
V_13 = F_91 ( & V_11 -> V_16 , 0x00000400 | ( V_139 << 19 ) ,
V_156 ) ;
V_19:
F_96 ( V_143 ) ;
V_144:
F_85 ( V_47 ) ;
F_88 ( & V_11 -> V_16 . V_132 ) ;
return V_13 ;
V_152:
F_83 ( V_11 ) ;
F_85 ( V_47 ) ;
F_88 ( & V_11 -> V_16 . V_132 ) ;
F_96 ( V_143 ) ;
F_97 ( F_6 ( V_11 ) , L_12
L_13 ) ;
F_98 ( V_11 -> V_16 . V_36 . V_157 ) ;
return V_13 ;
}
static int F_99 ( struct V_10 * V_11 ,
struct V_43 * V_44 )
{
int V_13 ;
struct V_84 * V_158 = (struct V_84 * ) V_44 -> V_89 ;
unsigned int V_159 = V_44 -> V_131 + V_160 ;
unsigned int V_161 ;
struct V_162 * V_163 ;
struct V_94 * V_118 = (struct V_94 * )
F_100 ( V_44 , sizeof( struct V_94 ) ) ;
struct V_61 * V_62 = F_65 ( V_44 ) ;
F_13 ( V_159 <= 0xffff ) ;
if ( ! F_81 ( V_158 -> V_124 ) )
V_158 -> V_164 = 0 ;
V_163 = F_101 ( V_11 -> V_9 , V_62 ) ;
V_118 -> V_165 = V_163 -> V_92 ;
if ( V_62 -> V_120 . V_71 [ 0 ] . V_25 & V_166 )
V_118 -> V_165 = V_163 -> V_167 ;
V_118 -> V_99 = F_102 ( V_159 ) ;
F_80 ( V_11 , V_118 , V_158 , V_62 ) ;
V_161 = V_159 + sizeof( struct V_94 ) + 10 ;
F_13 ( V_161 <= 0xffff ) ;
V_118 -> V_161 = F_102 ( F_89 ( & V_11 -> V_16 ) ?
V_161 - V_159 : V_161 ) ;
V_118 -> V_97 = 0 ;
V_13 = F_78 ( & V_118 -> V_97 , F_103 ( V_118 -> V_165 ) ,
F_104 ( V_118 -> V_99 ) ) ;
if ( V_13 < 0 )
return V_13 ;
V_118 -> V_168 = F_102 ( V_13 ) ;
V_118 -> V_169 = 0 ;
return 0 ;
}
static void F_105 ( struct V_8 * V_9 ,
struct V_170 * V_120 ,
struct V_43 * V_44 )
{
struct V_10 * V_11 = F_4 ( V_9 ) ;
struct V_61 * V_62 = F_65 ( V_44 ) ;
int V_13 ;
V_13 = F_99 ( V_11 , V_44 ) ;
if ( V_13 )
goto V_171;
V_62 -> V_93 [ 0 ] = V_9 ;
V_13 = F_106 ( & V_11 -> V_16 . V_36 , V_44 ) ;
if ( V_13 )
goto V_171;
return;
V_171:
F_107 ( V_44 ) ;
}
static int F_108 ( struct V_8 * V_9 , struct V_84 * V_172 ,
struct V_173 * V_174 )
{
struct V_10 * V_11 = F_4 ( V_9 ) ;
struct V_43 * V_44 ;
struct V_45 * V_80 ;
unsigned long V_25 ;
int V_82 = 0 ;
int V_3 , V_83 = 0 ;
if ( ! F_109 ( V_172 -> V_124 ) )
return 0 ;
V_80 = & V_11 -> V_46 ;
F_27 ( & V_80 -> V_21 , V_25 ) ;
F_70 (q, skb) {
struct V_84 * V_85 ;
V_83 ++ ;
if ( V_11 -> V_88 && F_71 ( V_80 , V_44 ) )
continue;
V_85 = (struct V_84 * ) V_44 -> V_89 ;
if ( F_110 ( ! memcmp ( V_85 -> V_175 , V_172 -> V_90 , V_15 ) ) )
{
V_82 = 1 ;
break;
}
}
if ( V_82 ) {
for ( V_3 = 1 ; V_3 < V_83 ; V_3 ++ ) {
V_44 = F_73 ( V_80 ) ;
F_64 ( V_9 , V_44 ,
V_11 -> V_88 ? V_11 -> V_77 : 0 ,
NULL ) ;
V_11 -> V_88 = 0 ;
}
V_11 -> V_88 = 1 ;
V_11 -> V_77 = V_174 -> signal ;
if ( V_11 -> type == V_32 ) {
V_44 = F_73 ( V_80 ) ;
F_64 ( V_9 , V_44 , V_11 -> V_77 , NULL ) ;
V_11 -> V_88 = 0 ;
}
}
F_28 ( & V_80 -> V_21 , V_25 ) ;
return 1 ;
}
int F_111 ( struct V_8 * V_9 , const T_1 * V_176 , unsigned int V_177 )
{
struct V_10 * V_11 = F_4 ( V_9 ) ;
struct V_173 V_174 ;
const struct V_178 * V_70 ;
struct V_43 * V_44 ;
int V_179 = 0 ;
T_4 V_180 ;
int V_181 ;
int V_3 ;
T_1 V_75 ;
if ( V_177 < V_182 + 10 +
V_160 + sizeof( struct V_178 ) )
return - V_115 ;
memset ( & V_174 , 0 , sizeof( V_174 ) ) ;
V_70 = (struct V_178 * )
( V_176 + ( V_177 - sizeof( struct V_178 ) ) ) ;
if ( V_70 -> V_183 & V_184 ) {
if ( V_11 -> V_185 &&
( V_70 -> V_183 & V_186 ) ) {
V_174 . V_187 |= V_188 ;
V_179 = 1 ;
} else {
return - V_115 ;
}
}
V_174 . V_189 = V_190 [ F_112 ( & V_11 -> V_16 ) - 1 ] . V_191 ;
V_174 . V_192 = V_193 ;
V_174 . signal = F_3 ( V_9 , V_70 -> V_194 ) ;
V_75 = F_113 ( V_176 , V_70 ) ;
for ( V_3 = 0 ; V_3 < V_11 -> V_192 . V_195 ; V_3 ++ )
if ( V_75 == V_11 -> V_192 . V_196 [ V_3 ] . V_92 )
V_174 . V_197 = V_3 ;
V_177 -= V_182 + sizeof( struct V_178 ) ;
V_176 += V_182 ;
if ( ! V_179 &&
F_108 ( V_9 , (struct V_84 * ) V_176 , & V_174 )
&& ! V_11 -> V_28 )
return 0 ;
V_180 = F_114 ( ( T_4 * ) V_176 ) ;
V_181 = F_115 ( V_180 ) ^ F_116 ( V_180 ) ;
V_44 = F_117 ( V_177 + ( V_181 ? 2 : 0 ) ) ;
if ( V_44 == NULL )
return - V_146 ;
if ( V_181 ) {
F_118 ( V_44 , 2 ) ;
}
memcpy ( F_119 ( V_44 , V_177 ) , V_176 , V_177 ) ;
memcpy ( F_120 ( V_44 ) , & V_174 , sizeof( V_174 ) ) ;
F_121 ( V_9 , V_44 ) ;
return 0 ;
}
static int F_122 ( struct V_8 * V_9 ,
struct V_198 * V_31 )
{
struct V_10 * V_11 = F_4 ( V_9 ) ;
if ( V_11 -> type != V_199 )
return - V_200 ;
switch ( V_31 -> type ) {
case V_201 :
case V_55 :
case V_202 :
case V_56 :
case V_32 :
V_11 -> type = V_31 -> type ;
break;
default:
return - V_200 ;
}
V_11 -> V_31 = V_31 ;
return F_30 ( V_11 ) ;
}
static void F_123 ( struct V_8 * V_9 ,
struct V_198 * V_31 )
{
struct V_10 * V_11 = F_4 ( V_9 ) ;
V_11 -> type = V_199 ;
V_11 -> V_31 = NULL ;
F_63 ( & V_11 -> V_16 , 0 , 0 , V_199 ) ;
F_31 ( & V_11 -> V_16 , NULL ) ;
F_86 ( V_11 ) ;
}
static int F_124 ( struct V_8 * V_9 , T_2 V_203 )
{
struct V_10 * V_11 = F_4 ( V_9 ) ;
struct V_204 * V_205 = & V_9 -> V_205 ;
F_16 ( & V_11 -> V_21 ) ;
V_11 -> V_52 = V_205 -> V_206 . V_207 -> V_92 ;
F_17 ( & V_11 -> V_21 ) ;
return F_59 ( & V_11 -> V_16 , V_205 -> V_206 . V_207 -> V_92 ) ;
}
static void F_125 ( struct V_10 * V_11 )
{
struct V_43 * V_44 , * V_47 ;
if ( ! F_126 ( V_42 , & V_11 -> V_25 ) )
return;
if ( ! V_11 -> V_31 || V_11 -> V_31 -> type != V_32 )
return;
while ( ! F_127 ( V_11 -> V_9 , 0 ) ) {
V_44 = F_128 ( V_11 -> V_9 , V_11 -> V_31 ) ;
if ( ! V_44 )
break;
F_105 ( V_11 -> V_9 , NULL , V_44 ) ;
}
V_47 = F_61 ( V_11 -> V_9 , V_11 -> V_31 ) ;
if ( V_47 )
F_62 ( V_11 -> V_9 , V_47 , true ) ;
F_16 ( & V_11 -> V_21 ) ;
V_11 -> V_47 . V_57 = V_58 ;
F_17 ( & V_11 -> V_21 ) ;
}
static void F_129 ( struct V_208 * V_209 )
{
T_3 V_210 ;
unsigned long V_25 ;
struct V_10 * V_11 = F_130 ( V_209 , struct V_10 , V_211 ) ;
F_27 ( & V_11 -> V_21 , V_25 ) ;
V_210 = F_104 ( * ( T_4 * ) ( V_11 -> V_212 + 4 ) ) ;
F_28 ( & V_11 -> V_21 , V_25 ) ;
if ( V_210 & V_213 ) {
F_125 ( V_11 ) ;
} else {
F_58 ( F_6 ( V_11 ) , L_14 ) ;
}
F_44 ( & V_11 -> V_16 ) ;
}
static T_5 F_131 ( struct V_8 * V_9 ,
struct V_214 * V_215 )
{
struct V_10 * V_11 = F_4 ( V_9 ) ;
struct V_33 V_34 ;
struct V_216 * V_217 ;
F_34 ( & V_34 ) ;
F_132 (ha, mc_list) {
F_58 ( F_6 ( V_11 ) , L_15 , V_217 -> V_14 ) ;
F_133 ( & V_34 , V_217 -> V_14 ) ;
}
return V_34 . V_218 | ( ( T_5 ) V_34 . V_219 << 32 ) ;
}
static void F_134 ( struct V_8 * V_9 ,
unsigned int V_220 ,
unsigned int * V_221 ,
T_5 V_222 )
{
struct V_33 V_34 = {
. V_218 = V_222 ,
. V_219 = V_222 >> 32 ,
} ;
struct V_10 * V_11 = F_4 ( V_9 ) ;
unsigned long V_25 ;
int V_13 ;
V_220 &= V_223 ;
* V_221 &= V_223 ;
if ( * V_221 & ( V_224 | V_225 ) )
F_135 ( & V_34 ) ;
F_27 ( & V_11 -> V_21 , V_25 ) ;
V_11 -> V_185 = ! ! ( * V_221 & V_226 ) ;
V_11 -> V_28 = ! ! ( * V_221 & V_227 ) ;
V_11 -> V_48 = V_34 ;
F_28 ( & V_11 -> V_21 , V_25 ) ;
F_35 ( & V_11 -> V_16 , & V_34 ) ;
if ( V_220 & V_227 ) {
V_13 = F_26 ( V_11 ) ;
if ( V_13 )
F_41 ( F_6 ( V_11 ) , L_16 , V_13 ) ;
}
}
static void F_60 ( struct V_10 * V_11 , unsigned int V_49 )
{
F_87 ( & V_11 -> V_16 . V_132 ) ;
F_136 ( & V_11 -> V_16 , V_49 ) ;
F_88 ( & V_11 -> V_16 . V_132 ) ;
}
static void F_137 ( struct V_8 * V_9 ,
struct V_198 * V_31 ,
struct V_228 * V_229 ,
T_2 V_230 )
{
struct V_10 * V_11 = F_4 ( V_9 ) ;
int V_231 ;
F_58 ( F_6 ( V_11 ) , L_17 , V_230 ) ;
if ( V_11 -> type == V_55 ||
V_11 -> type == V_56 ||
V_11 -> type == V_32 ) {
V_231 = true ;
if ( V_230 & V_232 ) {
struct V_43 * V_47 = F_61 ( V_9 , V_31 ) ;
if ( V_47 ) {
F_54 ( & V_11 -> V_16 ) ;
F_62 ( V_9 , V_47 , false ) ;
F_44 ( & V_11 -> V_16 ) ;
}
}
if ( V_230 & V_233 ) {
T_3 V_53 = 0 ;
T_1 V_54 = 0 ;
if ( V_229 -> V_234 ) {
V_54 = V_229 -> V_235 ;
V_53 = V_229 -> V_236 ;
}
F_16 ( & V_11 -> V_21 ) ;
V_11 -> V_47 . V_54 = V_54 ;
V_11 -> V_47 . V_53 = V_53 ;
V_11 -> V_47 . V_57 = V_58 ;
F_17 ( & V_11 -> V_21 ) ;
F_63 ( & V_11 -> V_16 , V_53 , V_54 ,
V_11 -> type ) ;
}
} else
V_231 = F_138 ( V_229 -> V_237 ) ;
F_16 ( & V_11 -> V_21 ) ;
V_11 -> V_231 = V_231 ;
F_17 ( & V_11 -> V_21 ) ;
if ( V_230 & V_238 ) {
F_16 ( & V_11 -> V_21 ) ;
V_11 -> V_49 = V_229 -> V_239 ;
F_17 ( & V_11 -> V_21 ) ;
F_60 ( V_11 , V_229 -> V_239 ) ;
}
}
static T_5 F_139 ( struct V_8 * V_9 , struct V_198 * V_31 )
{
struct V_10 * V_11 = F_4 ( V_9 ) ;
return F_140 ( & V_11 -> V_16 ) ;
}
struct V_8 * F_141 ( struct V_240 * V_157 )
{
struct V_10 * V_11 ;
struct V_8 * V_9 ;
V_9 = F_142 ( sizeof( struct V_10 ) , & V_241 ) ;
if ( ! V_9 ) {
F_58 ( & V_157 -> V_242 , L_18 ) ;
return NULL ;
}
V_11 = F_4 ( V_9 ) ;
memset ( V_11 , 0 , sizeof( * V_11 ) ) ;
F_143 ( & V_11 -> V_21 ) ;
V_11 -> V_9 = V_9 ;
V_11 -> type = V_199 ;
memcpy ( V_11 -> V_243 , V_190 , sizeof( V_190 ) ) ;
memcpy ( V_11 -> V_71 , V_91 , sizeof( V_91 ) ) ;
V_11 -> V_192 . V_195 = F_2 ( V_91 ) ;
V_11 -> V_192 . V_196 = V_11 -> V_71 ;
V_11 -> V_192 . V_244 = F_2 ( V_190 ) ;
V_11 -> V_192 . V_243 = V_11 -> V_243 ;
V_9 -> V_23 -> V_245 [ V_193 ] = & V_11 -> V_192 ;
V_9 -> V_25 = V_246 |
V_247 |
V_248 |
V_249 ;
V_9 -> V_23 -> V_250 =
F_144 ( V_55 ) |
F_144 ( V_202 ) |
F_144 ( V_56 ) |
F_144 ( V_32 ) ;
V_9 -> V_251 = 100 ;
V_9 -> V_252 = 1 ;
V_9 -> V_253 = sizeof( struct V_94 ) ;
V_9 -> V_254 = V_76 ;
V_9 -> V_255 = 18 ;
F_145 ( & V_11 -> V_46 ) ;
V_11 -> V_88 = 0 ;
F_146 ( & V_11 -> V_16 , V_9 , V_157 ) ;
F_147 ( V_11 ) ;
F_148 ( V_11 ) ;
F_149 ( & V_11 -> V_211 , F_129 ) ;
F_150 ( V_9 , & V_157 -> V_242 ) ;
return V_9 ;
}
static void F_151 ( struct V_208 * V_209 )
{
struct V_10 * V_11 =
F_130 ( V_209 , struct V_10 , V_47 . V_256 . V_209 ) ;
struct V_43 * V_47 ;
unsigned long V_257 ;
int V_53 , V_54 ;
if ( ! F_126 ( V_42 , & V_11 -> V_25 ) )
goto V_258;
if ( V_11 -> type != V_32 || ! V_11 -> V_31 )
goto V_258;
F_16 ( & V_11 -> V_21 ) ;
V_53 = V_11 -> V_47 . V_53 ;
V_54 = V_11 -> V_47 . V_54 ;
V_257 = V_11 -> V_47 . V_57 +
F_152 ( V_53 * 1024 / 1000 ) * 3 ;
F_17 ( & V_11 -> V_21 ) ;
if ( V_53 > 0 && F_153 ( V_257 ) ) {
F_58 ( F_6 ( V_11 ) , L_19
L_20
L_21 ,
V_53 , V_54 ) ;
F_54 ( & V_11 -> V_16 ) ;
V_47 = F_61 ( V_11 -> V_9 , V_11 -> V_31 ) ;
if ( V_47 ) {
F_86 ( V_11 ) ;
F_62 ( V_11 -> V_9 , V_47 , false ) ;
}
F_63 ( & V_11 -> V_16 , V_53 , V_54 , V_11 -> type ) ;
F_44 ( & V_11 -> V_16 ) ;
F_16 ( & V_11 -> V_21 ) ;
V_11 -> V_47 . V_57 = V_58 ;
F_17 ( & V_11 -> V_21 ) ;
}
V_258:
F_154 ( V_24 , & V_11 -> V_47 . V_256 ,
V_259 ) ;
}
static void F_148 ( struct V_10 * V_11 )
{
F_155 ( & V_11 -> V_47 . V_256 , F_151 ) ;
}
static void F_46 ( struct V_10 * V_11 )
{
F_58 ( F_6 ( V_11 ) , L_4 ) ;
V_11 -> V_47 . V_57 = V_58 ;
F_154 ( V_24 , & V_11 -> V_47 . V_256 ,
V_259 ) ;
}
static void F_52 ( struct V_10 * V_11 )
{
F_58 ( F_6 ( V_11 ) , L_4 ) ;
F_156 ( & V_11 -> V_47 . V_256 ) ;
F_86 ( V_11 ) ;
}
static void F_157 ( struct V_208 * V_209 )
{
struct V_10 * V_11 =
F_130 ( V_209 , struct V_10 , V_260 . V_261 . V_209 ) ;
struct V_17 * V_16 = & V_11 -> V_16 ;
int V_262 ;
int V_13 ;
if ( ! F_126 ( V_42 , & V_11 -> V_25 ) )
goto V_263;
F_16 ( & V_11 -> V_21 ) ;
V_262 = V_11 -> V_231 ;
F_17 ( & V_11 -> V_21 ) ;
V_13 = F_158 ( V_16 ,
V_262 ? V_264 : V_265 ) ;
if ( V_13 )
F_58 ( F_6 ( V_11 ) , L_22 , V_13 ) ;
V_263:
F_154 ( V_24 , & V_11 -> V_260 . V_261 ,
V_266 ) ;
}
static void F_147 ( struct V_10 * V_11 )
{
F_155 ( & V_11 -> V_260 . V_261 , F_157 ) ;
}
static void F_45 ( struct V_10 * V_11 )
{
F_58 ( F_6 ( V_11 ) , L_4 ) ;
F_154 ( V_24 , & V_11 -> V_260 . V_261 ,
0 ) ;
}
static void F_53 ( struct V_10 * V_11 )
{
F_58 ( F_6 ( V_11 ) , L_4 ) ;
F_156 ( & V_11 -> V_260 . V_261 ) ;
F_158 ( & V_11 -> V_16 , V_267 ) ;
}
