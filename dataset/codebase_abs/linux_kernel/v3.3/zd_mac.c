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
V_13 = F_39 ( V_16 ) ;
if ( V_13 < 0 )
goto V_20;
V_13 = F_40 ( V_16 ) ;
if ( V_13 < 0 )
goto V_40;
V_13 = F_41 ( V_16 ) ;
if ( V_13 < 0 )
goto V_41;
F_42 ( V_11 ) ;
F_43 ( V_11 ) ;
F_44 ( V_42 , & V_11 -> V_25 ) ;
return 0 ;
V_41:
F_45 ( V_16 ) ;
V_40:
F_46 ( V_16 ) ;
V_20:
F_20 ( V_16 ) ;
V_19:
return V_13 ;
}
void F_47 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = F_4 ( V_9 ) ;
struct V_17 * V_16 = & V_11 -> V_16 ;
struct V_43 * V_44 ;
struct V_45 * V_46 = & V_11 -> V_46 ;
F_48 ( V_42 , & V_11 -> V_25 ) ;
F_45 ( V_16 ) ;
F_49 ( V_11 ) ;
F_50 ( V_11 ) ;
F_22 ( V_24 ) ;
F_51 ( V_16 ) ;
F_46 ( V_16 ) ;
F_20 ( V_16 ) ;
while ( ( V_44 = F_52 ( V_46 ) ) )
F_53 ( V_44 ) ;
}
int F_54 ( struct V_10 * V_11 )
{
struct V_43 * V_47 ;
struct V_33 V_48 ;
unsigned int V_49 ;
int V_13 , V_50 , V_51 ;
T_1 V_52 ;
F_55 ( F_6 ( V_11 ) , L_3 ) ;
F_16 ( & V_11 -> V_21 ) ;
V_48 = V_11 -> V_48 ;
V_49 = V_11 -> V_49 ;
V_50 = V_11 -> V_47 . V_53 ;
V_51 = V_11 -> V_47 . V_54 ;
V_52 = V_11 -> V_52 ;
F_17 ( & V_11 -> V_21 ) ;
V_13 = F_30 ( V_11 ) ;
if ( V_13 < 0 ) {
F_55 ( F_6 ( V_11 ) , L_4 , V_13 ) ;
return V_13 ;
}
V_13 = F_56 ( & V_11 -> V_16 , V_52 ) ;
if ( V_13 < 0 ) {
F_55 ( F_6 ( V_11 ) , L_5 ,
V_13 ) ;
return V_13 ;
}
F_57 ( V_11 , V_49 ) ;
V_13 = F_35 ( & V_11 -> V_16 , & V_48 ) ;
if ( V_13 < 0 ) {
F_55 ( F_6 ( V_11 ) ,
L_6 , V_13 ) ;
return V_13 ;
}
if ( V_11 -> type == V_55 ||
V_11 -> type == V_56 ||
V_11 -> type == V_32 ) {
if ( V_11 -> V_31 != NULL ) {
V_47 = F_58 ( V_11 -> V_9 , V_11 -> V_31 ) ;
if ( V_47 )
F_59 ( V_11 -> V_9 , V_47 , false ) ;
}
F_60 ( & V_11 -> V_16 , V_50 ,
V_51 , V_11 -> type ) ;
F_16 ( & V_11 -> V_21 ) ;
V_11 -> V_47 . V_57 = V_58 ;
F_17 ( & V_11 -> V_21 ) ;
}
return 0 ;
}
static void F_61 ( struct V_8 * V_9 , struct V_43 * V_44 ,
int V_59 , struct V_60 * V_60 )
{
struct V_61 * V_62 = F_62 ( V_44 ) ;
int V_3 ;
int V_63 = 1 , V_64 = 1 ;
int V_65 ;
const struct V_66 * V_67 ;
F_63 ( V_62 ) ;
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
F_64 ( V_9 , V_44 ) ;
}
void F_65 ( struct V_78 * V_78 )
{
struct V_8 * V_9 = F_66 ( V_78 -> V_79 ) ;
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
F_67 (q, skb) {
struct V_84 * V_85 ;
struct V_61 * V_62 ;
int V_65 , V_86 ;
const struct V_66 * V_67 ;
T_1 V_87 ;
V_83 ++ ;
if ( V_60 -> V_68 && V_11 -> V_88 &&
F_68 ( V_80 , V_44 ) ) {
continue;
}
V_85 = (struct V_84 * ) V_44 -> V_89 ;
if ( F_69 ( memcmp ( V_85 -> V_90 , V_60 -> V_11 , V_15 ) ) ) {
continue;
}
V_62 = F_62 ( V_44 ) ;
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
V_44 = F_70 ( V_80 ) ;
F_61 ( V_9 , V_44 ,
V_11 -> V_88 ? V_11 -> V_77 : 0 ,
V_3 == V_83 ? V_60 : NULL ) ;
V_11 -> V_88 = 0 ;
}
}
F_28 ( & V_80 -> V_21 , V_25 ) ;
}
void F_71 ( struct V_43 * V_44 , int error )
{
struct V_61 * V_62 = F_62 ( V_44 ) ;
struct V_8 * V_9 = V_62 -> V_93 [ 0 ] ;
struct V_10 * V_11 = F_4 ( V_9 ) ;
F_63 ( V_62 ) ;
F_72 ( V_44 , sizeof( struct V_94 ) ) ;
if ( F_69 ( error ||
( V_62 -> V_25 & V_95 ) ) ) {
F_64 ( V_9 , V_44 ) ;
} else {
struct V_45 * V_80 = & V_11 -> V_46 ;
F_73 ( V_80 , V_44 ) ;
while ( F_74 ( V_80 ) > V_96 ) {
F_61 ( V_9 , F_52 ( V_80 ) ,
V_11 -> V_88 ? V_11 -> V_77 : 0 ,
NULL ) ;
V_11 -> V_88 = 0 ;
}
}
}
static int F_75 ( T_1 * V_97 , T_1 V_98 , T_3 V_99 )
{
static const T_1 V_100 [] = {
[ F_76 ( V_101 ) ] = 1 ,
[ F_76 ( V_102 ) ] = 2 ,
[ F_76 ( V_103 ) ] = 11 ,
[ F_76 ( V_104 ) ] = 11 ,
[ F_76 ( V_105 ) ] = 6 ,
[ F_76 ( V_106 ) ] = 9 ,
[ F_76 ( V_107 ) ] = 12 ,
[ F_76 ( V_108 ) ] = 18 ,
[ F_76 ( V_109 ) ] = 24 ,
[ F_76 ( V_110 ) ] = 36 ,
[ F_76 ( V_111 ) ] = 48 ,
[ F_76 ( V_112 ) ] = 54 ,
} ;
T_2 V_113 = ( T_2 ) V_99 * 8 ;
T_2 V_114 ;
V_114 = V_100 [ F_76 ( V_98 ) ] ;
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
static void F_77 ( struct V_10 * V_11 , struct V_94 * V_118 ,
struct V_84 * V_119 ,
struct V_61 * V_62 )
{
V_118 -> V_120 = 0 ;
if ( V_62 -> V_25 & V_121 )
V_118 -> V_120 |= V_122 ;
if ( V_62 -> V_25 & V_95 )
V_118 -> V_120 |= V_123 ;
if ( F_78 ( V_119 -> V_124 ) )
V_118 -> V_120 |= V_125 ;
if ( V_62 -> V_120 . V_71 [ 0 ] . V_25 & V_126 )
V_118 -> V_120 |= V_127 ;
if ( V_62 -> V_120 . V_71 [ 0 ] . V_25 & V_128 )
V_118 -> V_120 |= V_129 ;
}
static bool F_79 ( struct V_10 * V_11 , struct V_43 * V_47 )
{
if ( ! V_11 -> V_47 . V_130 )
return false ;
if ( V_11 -> V_47 . V_130 -> V_131 != V_47 -> V_131 )
return false ;
return ! memcmp ( V_47 -> V_89 , V_11 -> V_47 . V_130 -> V_89 , V_47 -> V_131 ) ;
}
static void F_80 ( struct V_10 * V_11 )
{
F_13 ( F_81 ( & V_11 -> V_16 . V_132 ) ) ;
F_82 ( V_11 -> V_47 . V_130 ) ;
V_11 -> V_47 . V_130 = NULL ;
}
static void F_83 ( struct V_10 * V_11 )
{
F_84 ( & V_11 -> V_16 . V_132 ) ;
F_80 ( V_11 ) ;
F_85 ( & V_11 -> V_16 . V_132 ) ;
}
static int F_59 ( struct V_8 * V_9 , struct V_43 * V_47 ,
bool V_133 )
{
struct V_10 * V_11 = F_4 ( V_9 ) ;
int V_13 , V_134 , V_135 , V_136 = 0 ;
T_2 V_137 , V_138 = 0 ;
T_2 V_139 = V_47 -> V_131 + 4 ;
unsigned long V_140 , V_141 ;
struct V_142 * V_143 ;
F_84 ( & V_11 -> V_16 . V_132 ) ;
if ( F_79 ( V_11 , V_47 ) ) {
V_13 = 0 ;
goto V_144;
}
V_135 = 1 + F_86 ( & V_11 -> V_16 ) + V_139 ;
V_143 = F_87 ( V_135 * sizeof( struct V_142 ) , V_145 ) ;
if ( ! V_143 ) {
V_13 = - V_146 ;
goto V_144;
}
V_13 = F_88 ( & V_11 -> V_16 , 0 , V_147 ) ;
if ( V_13 < 0 )
goto V_19;
V_13 = F_89 ( & V_11 -> V_16 , & V_137 , V_147 ) ;
if ( V_13 < 0 )
goto V_148;
if ( V_133 && V_137 & 0x2 ) {
V_13 = - V_149 ;
goto V_148;
}
V_140 = V_58 + V_150 / 2 ;
V_141 = V_58 + V_150 / 10 ;
while ( V_137 & 0x2 ) {
V_13 = F_89 ( & V_11 -> V_16 , & V_137 , V_147 ) ;
if ( V_13 < 0 )
goto V_148;
if ( F_90 ( V_141 ) ) {
V_141 = V_58 + V_150 / 10 ;
F_91 ( F_6 ( V_11 ) ,
L_7 ) ;
if ( F_90 ( V_140 ) ) {
F_91 ( F_6 ( V_11 ) ,
L_8 ) ;
V_13 = - V_151 ;
goto V_152;
}
}
F_92 ( 20 ) ;
}
V_143 [ V_136 ] . V_14 = V_153 ;
V_143 [ V_136 ] . V_154 = V_139 - 1 ;
V_136 ++ ;
if ( F_86 ( & V_11 -> V_16 ) ) {
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
F_93 ( V_136 != V_135 ) ;
V_13 = F_94 ( & V_11 -> V_16 , V_143 , V_135 ) ;
V_148:
V_140 = V_58 + V_150 / 2 ;
V_134 = F_88 ( & V_11 -> V_16 , 1 , V_147 ) ;
while ( V_134 < 0 ) {
if ( V_133 || F_90 ( V_140 ) ) {
V_134 = - V_151 ;
break;
}
F_92 ( 20 ) ;
V_134 = F_88 ( & V_11 -> V_16 , 1 , V_147 ) ;
}
if ( V_134 < 0 )
F_91 ( F_6 ( V_11 ) , L_9
L_10 ) ;
if ( V_13 < 0 || V_134 < 0 ) {
if ( V_13 >= 0 )
V_13 = V_134 ;
F_80 ( V_11 ) ;
goto V_19;
}
F_80 ( V_11 ) ;
V_11 -> V_47 . V_130 = V_47 ;
V_47 = NULL ;
V_13 = F_88 ( & V_11 -> V_16 , 0x00000400 | ( V_139 << 19 ) ,
V_156 ) ;
V_19:
F_95 ( V_143 ) ;
V_144:
F_82 ( V_47 ) ;
F_85 ( & V_11 -> V_16 . V_132 ) ;
return V_13 ;
V_152:
F_80 ( V_11 ) ;
F_82 ( V_47 ) ;
F_85 ( & V_11 -> V_16 . V_132 ) ;
F_95 ( V_143 ) ;
F_96 ( F_6 ( V_11 ) , L_11
L_12 ) ;
F_97 ( V_11 -> V_16 . V_36 . V_157 ) ;
return V_13 ;
}
static int F_98 ( struct V_10 * V_11 ,
struct V_43 * V_44 )
{
int V_13 ;
struct V_84 * V_158 = (struct V_84 * ) V_44 -> V_89 ;
unsigned int V_159 = V_44 -> V_131 + V_160 ;
unsigned int V_161 ;
struct V_162 * V_163 ;
struct V_94 * V_118 = (struct V_94 * )
F_99 ( V_44 , sizeof( struct V_94 ) ) ;
struct V_61 * V_62 = F_62 ( V_44 ) ;
F_13 ( V_159 <= 0xffff ) ;
if ( ! F_78 ( V_158 -> V_124 ) )
V_158 -> V_164 = 0 ;
V_163 = F_100 ( V_11 -> V_9 , V_62 ) ;
V_118 -> V_165 = V_163 -> V_92 ;
if ( V_62 -> V_120 . V_71 [ 0 ] . V_25 & V_166 )
V_118 -> V_165 = V_163 -> V_167 ;
V_118 -> V_99 = F_101 ( V_159 ) ;
F_77 ( V_11 , V_118 , V_158 , V_62 ) ;
V_161 = V_159 + sizeof( struct V_94 ) + 10 ;
F_13 ( V_161 <= 0xffff ) ;
V_118 -> V_161 = F_101 ( F_86 ( & V_11 -> V_16 ) ?
V_161 - V_159 : V_161 ) ;
V_118 -> V_97 = 0 ;
V_13 = F_75 ( & V_118 -> V_97 , F_102 ( V_118 -> V_165 ) ,
F_103 ( V_118 -> V_99 ) ) ;
if ( V_13 < 0 )
return V_13 ;
V_118 -> V_168 = F_101 ( V_13 ) ;
V_118 -> V_169 = 0 ;
return 0 ;
}
static void F_104 ( struct V_8 * V_9 , struct V_43 * V_44 )
{
struct V_10 * V_11 = F_4 ( V_9 ) ;
struct V_61 * V_62 = F_62 ( V_44 ) ;
int V_13 ;
V_13 = F_98 ( V_11 , V_44 ) ;
if ( V_13 )
goto V_170;
V_62 -> V_93 [ 0 ] = V_9 ;
V_13 = F_105 ( & V_11 -> V_16 . V_36 , V_44 ) ;
if ( V_13 )
goto V_170;
return;
V_170:
F_106 ( V_44 ) ;
}
static int F_107 ( struct V_8 * V_9 , struct V_84 * V_171 ,
struct V_172 * V_173 )
{
struct V_10 * V_11 = F_4 ( V_9 ) ;
struct V_43 * V_44 ;
struct V_45 * V_80 ;
unsigned long V_25 ;
int V_82 = 0 ;
int V_3 , V_83 = 0 ;
if ( ! F_108 ( V_171 -> V_124 ) )
return 0 ;
V_80 = & V_11 -> V_46 ;
F_27 ( & V_80 -> V_21 , V_25 ) ;
F_67 (q, skb) {
struct V_84 * V_85 ;
V_83 ++ ;
if ( V_11 -> V_88 && F_68 ( V_80 , V_44 ) )
continue;
V_85 = (struct V_84 * ) V_44 -> V_89 ;
if ( F_109 ( ! memcmp ( V_85 -> V_174 , V_171 -> V_90 , V_15 ) ) )
{
V_82 = 1 ;
break;
}
}
if ( V_82 ) {
for ( V_3 = 1 ; V_3 < V_83 ; V_3 ++ ) {
V_44 = F_70 ( V_80 ) ;
F_61 ( V_9 , V_44 ,
V_11 -> V_88 ? V_11 -> V_77 : 0 ,
NULL ) ;
V_11 -> V_88 = 0 ;
}
V_11 -> V_88 = 1 ;
V_11 -> V_77 = V_173 -> signal ;
if ( V_11 -> type == V_32 ) {
V_44 = F_70 ( V_80 ) ;
F_61 ( V_9 , V_44 , V_11 -> V_77 , NULL ) ;
V_11 -> V_88 = 0 ;
}
}
F_28 ( & V_80 -> V_21 , V_25 ) ;
return 1 ;
}
int F_110 ( struct V_8 * V_9 , const T_1 * V_175 , unsigned int V_176 )
{
struct V_10 * V_11 = F_4 ( V_9 ) ;
struct V_172 V_173 ;
const struct V_177 * V_70 ;
struct V_43 * V_44 ;
int V_178 = 0 ;
T_4 V_179 ;
int V_180 ;
int V_3 ;
T_1 V_75 ;
if ( V_176 < V_181 + 10 +
V_160 + sizeof( struct V_177 ) )
return - V_115 ;
memset ( & V_173 , 0 , sizeof( V_173 ) ) ;
V_70 = (struct V_177 * )
( V_175 + ( V_176 - sizeof( struct V_177 ) ) ) ;
if ( V_70 -> V_182 & V_183 ) {
if ( V_11 -> V_184 &&
( V_70 -> V_182 & V_185 ) ) {
V_173 . V_186 |= V_187 ;
V_178 = 1 ;
} else {
return - V_115 ;
}
}
V_173 . V_188 = V_189 [ F_111 ( & V_11 -> V_16 ) - 1 ] . V_190 ;
V_173 . V_191 = V_192 ;
V_173 . signal = F_3 ( V_9 , V_70 -> V_193 ) ;
V_75 = F_112 ( V_175 , V_70 ) ;
for ( V_3 = 0 ; V_3 < V_11 -> V_191 . V_194 ; V_3 ++ )
if ( V_75 == V_11 -> V_191 . V_195 [ V_3 ] . V_92 )
V_173 . V_196 = V_3 ;
V_176 -= V_181 + sizeof( struct V_177 ) ;
V_175 += V_181 ;
if ( ! V_178 &&
F_107 ( V_9 , (struct V_84 * ) V_175 , & V_173 )
&& ! V_11 -> V_28 )
return 0 ;
V_179 = F_113 ( ( T_4 * ) V_175 ) ;
V_180 = F_114 ( V_179 ) ^ F_115 ( V_179 ) ;
V_44 = F_116 ( V_176 + ( V_180 ? 2 : 0 ) ) ;
if ( V_44 == NULL )
return - V_146 ;
if ( V_180 ) {
F_117 ( V_44 , 2 ) ;
}
memcpy ( F_118 ( V_44 , V_176 ) , V_175 , V_176 ) ;
memcpy ( F_119 ( V_44 ) , & V_173 , sizeof( V_173 ) ) ;
F_120 ( V_9 , V_44 ) ;
return 0 ;
}
static int F_121 ( struct V_8 * V_9 ,
struct V_197 * V_31 )
{
struct V_10 * V_11 = F_4 ( V_9 ) ;
if ( V_11 -> type != V_198 )
return - V_199 ;
switch ( V_31 -> type ) {
case V_200 :
case V_55 :
case V_201 :
case V_56 :
case V_32 :
V_11 -> type = V_31 -> type ;
break;
default:
return - V_199 ;
}
V_11 -> V_31 = V_31 ;
return F_30 ( V_11 ) ;
}
static void F_122 ( struct V_8 * V_9 ,
struct V_197 * V_31 )
{
struct V_10 * V_11 = F_4 ( V_9 ) ;
V_11 -> type = V_198 ;
V_11 -> V_31 = NULL ;
F_60 ( & V_11 -> V_16 , 0 , 0 , V_198 ) ;
F_31 ( & V_11 -> V_16 , NULL ) ;
F_83 ( V_11 ) ;
}
static int F_123 ( struct V_8 * V_9 , T_2 V_202 )
{
struct V_10 * V_11 = F_4 ( V_9 ) ;
struct V_203 * V_204 = & V_9 -> V_204 ;
F_16 ( & V_11 -> V_21 ) ;
V_11 -> V_52 = V_204 -> V_52 -> V_92 ;
F_17 ( & V_11 -> V_21 ) ;
return F_56 ( & V_11 -> V_16 , V_204 -> V_52 -> V_92 ) ;
}
static void F_124 ( struct V_10 * V_11 )
{
struct V_43 * V_44 , * V_47 ;
if ( ! F_125 ( V_42 , & V_11 -> V_25 ) )
return;
if ( ! V_11 -> V_31 || V_11 -> V_31 -> type != V_32 )
return;
while ( ! F_126 ( V_11 -> V_9 , 0 ) ) {
V_44 = F_127 ( V_11 -> V_9 , V_11 -> V_31 ) ;
if ( ! V_44 )
break;
F_104 ( V_11 -> V_9 , V_44 ) ;
}
V_47 = F_58 ( V_11 -> V_9 , V_11 -> V_31 ) ;
if ( V_47 )
F_59 ( V_11 -> V_9 , V_47 , true ) ;
F_16 ( & V_11 -> V_21 ) ;
V_11 -> V_47 . V_57 = V_58 ;
F_17 ( & V_11 -> V_21 ) ;
}
static void F_128 ( struct V_205 * V_206 )
{
T_3 V_207 ;
unsigned long V_25 ;
struct V_10 * V_11 = F_129 ( V_206 , struct V_10 , V_208 ) ;
F_27 ( & V_11 -> V_21 , V_25 ) ;
V_207 = F_103 ( * ( T_4 * ) ( V_11 -> V_209 + 4 ) ) ;
F_28 ( & V_11 -> V_21 , V_25 ) ;
if ( V_207 & V_210 ) {
F_124 ( V_11 ) ;
} else {
F_55 ( F_6 ( V_11 ) , L_13 ) ;
}
F_41 ( & V_11 -> V_16 ) ;
}
static T_5 F_130 ( struct V_8 * V_9 ,
struct V_211 * V_212 )
{
struct V_10 * V_11 = F_4 ( V_9 ) ;
struct V_33 V_34 ;
struct V_213 * V_214 ;
F_34 ( & V_34 ) ;
F_131 (ha, mc_list) {
F_55 ( F_6 ( V_11 ) , L_14 , V_214 -> V_14 ) ;
F_132 ( & V_34 , V_214 -> V_14 ) ;
}
return V_34 . V_215 | ( ( T_5 ) V_34 . V_216 << 32 ) ;
}
static void F_133 ( struct V_8 * V_9 ,
unsigned int V_217 ,
unsigned int * V_218 ,
T_5 V_219 )
{
struct V_33 V_34 = {
. V_215 = V_219 ,
. V_216 = V_219 >> 32 ,
} ;
struct V_10 * V_11 = F_4 ( V_9 ) ;
unsigned long V_25 ;
int V_13 ;
V_217 &= V_220 ;
* V_218 &= V_220 ;
if ( * V_218 & ( V_221 | V_222 ) )
F_134 ( & V_34 ) ;
F_27 ( & V_11 -> V_21 , V_25 ) ;
V_11 -> V_184 = ! ! ( * V_218 & V_223 ) ;
V_11 -> V_28 = ! ! ( * V_218 & V_224 ) ;
V_11 -> V_48 = V_34 ;
F_28 ( & V_11 -> V_21 , V_25 ) ;
F_35 ( & V_11 -> V_16 , & V_34 ) ;
if ( V_217 & V_224 ) {
V_13 = F_26 ( V_11 ) ;
if ( V_13 )
F_91 ( F_6 ( V_11 ) , L_15 , V_13 ) ;
}
}
static void F_57 ( struct V_10 * V_11 , unsigned int V_49 )
{
F_84 ( & V_11 -> V_16 . V_132 ) ;
F_135 ( & V_11 -> V_16 , V_49 ) ;
F_85 ( & V_11 -> V_16 . V_132 ) ;
}
static void F_136 ( struct V_8 * V_9 ,
struct V_197 * V_31 ,
struct V_225 * V_226 ,
T_2 V_227 )
{
struct V_10 * V_11 = F_4 ( V_9 ) ;
int V_228 ;
F_55 ( F_6 ( V_11 ) , L_16 , V_227 ) ;
if ( V_11 -> type == V_55 ||
V_11 -> type == V_56 ||
V_11 -> type == V_32 ) {
V_228 = true ;
if ( V_227 & V_229 ) {
struct V_43 * V_47 = F_58 ( V_9 , V_31 ) ;
if ( V_47 ) {
F_51 ( & V_11 -> V_16 ) ;
F_59 ( V_9 , V_47 , false ) ;
F_41 ( & V_11 -> V_16 ) ;
}
}
if ( V_227 & V_230 ) {
T_3 V_53 = 0 ;
T_1 V_54 = 0 ;
if ( V_226 -> V_231 ) {
V_54 = V_226 -> V_232 ;
V_53 = V_226 -> V_233 ;
}
F_16 ( & V_11 -> V_21 ) ;
V_11 -> V_47 . V_54 = V_54 ;
V_11 -> V_47 . V_53 = V_53 ;
V_11 -> V_47 . V_57 = V_58 ;
F_17 ( & V_11 -> V_21 ) ;
F_60 ( & V_11 -> V_16 , V_53 , V_54 ,
V_11 -> type ) ;
}
} else
V_228 = F_137 ( V_226 -> V_234 ) ;
F_16 ( & V_11 -> V_21 ) ;
V_11 -> V_228 = V_228 ;
F_17 ( & V_11 -> V_21 ) ;
if ( V_227 & V_235 ) {
F_16 ( & V_11 -> V_21 ) ;
V_11 -> V_49 = V_226 -> V_236 ;
F_17 ( & V_11 -> V_21 ) ;
F_57 ( V_11 , V_226 -> V_236 ) ;
}
}
static T_5 F_138 ( struct V_8 * V_9 , struct V_197 * V_31 )
{
struct V_10 * V_11 = F_4 ( V_9 ) ;
return F_139 ( & V_11 -> V_16 ) ;
}
struct V_8 * F_140 ( struct V_237 * V_157 )
{
struct V_10 * V_11 ;
struct V_8 * V_9 ;
V_9 = F_141 ( sizeof( struct V_10 ) , & V_238 ) ;
if ( ! V_9 ) {
F_55 ( & V_157 -> V_239 , L_17 ) ;
return NULL ;
}
V_11 = F_4 ( V_9 ) ;
memset ( V_11 , 0 , sizeof( * V_11 ) ) ;
F_142 ( & V_11 -> V_21 ) ;
V_11 -> V_9 = V_9 ;
V_11 -> type = V_198 ;
memcpy ( V_11 -> V_240 , V_189 , sizeof( V_189 ) ) ;
memcpy ( V_11 -> V_71 , V_91 , sizeof( V_91 ) ) ;
V_11 -> V_191 . V_194 = F_2 ( V_91 ) ;
V_11 -> V_191 . V_195 = V_11 -> V_71 ;
V_11 -> V_191 . V_241 = F_2 ( V_189 ) ;
V_11 -> V_191 . V_240 = V_11 -> V_240 ;
V_9 -> V_23 -> V_242 [ V_192 ] = & V_11 -> V_191 ;
V_9 -> V_25 = V_243 |
V_244 |
V_245 ;
V_9 -> V_23 -> V_246 =
F_143 ( V_55 ) |
F_143 ( V_201 ) |
F_143 ( V_56 ) |
F_143 ( V_32 ) ;
V_9 -> V_247 = 100 ;
V_9 -> V_248 = 1 ;
V_9 -> V_249 = sizeof( struct V_94 ) ;
V_9 -> V_250 = V_76 ;
V_9 -> V_251 = 18 ;
F_144 ( & V_11 -> V_46 ) ;
V_11 -> V_88 = 0 ;
F_145 ( & V_11 -> V_16 , V_9 , V_157 ) ;
F_146 ( V_11 ) ;
F_147 ( V_11 ) ;
F_148 ( & V_11 -> V_208 , F_128 ) ;
F_149 ( V_9 , & V_157 -> V_239 ) ;
return V_9 ;
}
static void F_150 ( struct V_205 * V_206 )
{
struct V_10 * V_11 =
F_129 ( V_206 , struct V_10 , V_47 . V_252 . V_206 ) ;
struct V_43 * V_47 ;
unsigned long V_253 ;
int V_53 , V_54 ;
if ( ! F_125 ( V_42 , & V_11 -> V_25 ) )
goto V_254;
if ( V_11 -> type != V_32 || ! V_11 -> V_31 )
goto V_254;
F_16 ( & V_11 -> V_21 ) ;
V_53 = V_11 -> V_47 . V_53 ;
V_54 = V_11 -> V_47 . V_54 ;
V_253 = V_11 -> V_47 . V_57 +
F_151 ( V_53 * 1024 / 1000 ) * 3 ;
F_17 ( & V_11 -> V_21 ) ;
if ( V_53 > 0 && F_152 ( V_253 ) ) {
F_55 ( F_6 ( V_11 ) , L_18
L_19
L_20 ,
V_53 , V_54 ) ;
F_51 ( & V_11 -> V_16 ) ;
V_47 = F_58 ( V_11 -> V_9 , V_11 -> V_31 ) ;
if ( V_47 ) {
F_83 ( V_11 ) ;
F_59 ( V_11 -> V_9 , V_47 , false ) ;
}
F_60 ( & V_11 -> V_16 , V_53 , V_54 , V_11 -> type ) ;
F_41 ( & V_11 -> V_16 ) ;
F_16 ( & V_11 -> V_21 ) ;
V_11 -> V_47 . V_57 = V_58 ;
F_17 ( & V_11 -> V_21 ) ;
}
V_254:
F_153 ( V_24 , & V_11 -> V_47 . V_252 ,
V_255 ) ;
}
static void F_147 ( struct V_10 * V_11 )
{
F_154 ( & V_11 -> V_47 . V_252 , F_150 ) ;
}
static void F_43 ( struct V_10 * V_11 )
{
F_55 ( F_6 ( V_11 ) , L_3 ) ;
V_11 -> V_47 . V_57 = V_58 ;
F_153 ( V_24 , & V_11 -> V_47 . V_252 ,
V_255 ) ;
}
static void F_49 ( struct V_10 * V_11 )
{
F_55 ( F_6 ( V_11 ) , L_3 ) ;
F_155 ( & V_11 -> V_47 . V_252 ) ;
F_83 ( V_11 ) ;
}
static void F_156 ( struct V_205 * V_206 )
{
struct V_10 * V_11 =
F_129 ( V_206 , struct V_10 , V_256 . V_257 . V_206 ) ;
struct V_17 * V_16 = & V_11 -> V_16 ;
int V_258 ;
int V_13 ;
if ( ! F_125 ( V_42 , & V_11 -> V_25 ) )
goto V_259;
F_16 ( & V_11 -> V_21 ) ;
V_258 = V_11 -> V_228 ;
F_17 ( & V_11 -> V_21 ) ;
V_13 = F_157 ( V_16 ,
V_258 ? V_260 : V_261 ) ;
if ( V_13 )
F_55 ( F_6 ( V_11 ) , L_21 , V_13 ) ;
V_259:
F_153 ( V_24 , & V_11 -> V_256 . V_257 ,
V_262 ) ;
}
static void F_146 ( struct V_10 * V_11 )
{
F_154 ( & V_11 -> V_256 . V_257 , F_156 ) ;
}
static void F_42 ( struct V_10 * V_11 )
{
F_55 ( F_6 ( V_11 ) , L_3 ) ;
F_153 ( V_24 , & V_11 -> V_256 . V_257 ,
0 ) ;
}
static void F_50 ( struct V_10 * V_11 )
{
F_55 ( F_6 ( V_11 ) , L_3 ) ;
F_155 ( & V_11 -> V_256 . V_257 ) ;
F_157 ( & V_11 -> V_16 , V_263 ) ;
}
