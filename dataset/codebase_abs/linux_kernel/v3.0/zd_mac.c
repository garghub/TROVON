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
int F_3 ( struct V_8 * V_9 )
{
int V_10 ;
T_1 V_11 [ V_12 ] ;
struct V_13 * V_14 = F_4 ( V_9 ) ;
V_10 = F_5 ( & V_14 -> V_15 , V_11 ) ;
if ( V_10 )
return V_10 ;
F_6 ( V_9 , V_11 ) ;
return 0 ;
}
int F_7 ( struct V_8 * V_9 )
{
int V_10 ;
struct V_13 * V_14 = F_4 ( V_9 ) ;
struct V_16 * V_15 = & V_14 -> V_15 ;
char V_2 [ 2 ] ;
T_1 V_17 ;
V_10 = F_8 ( V_15 ) ;
if ( V_10 )
goto V_18;
V_10 = F_9 ( V_15 ) ;
if ( V_10 )
goto V_19;
F_10 ( ! F_11 () ) ;
V_10 = F_12 ( V_15 , & V_17 ) ;
if ( V_10 )
goto V_19;
F_13 ( & V_14 -> V_20 ) ;
V_14 -> V_1 = V_14 -> V_17 = V_17 ;
F_14 ( & V_14 -> V_20 ) ;
V_10 = F_15 ( V_15 , V_21 ) ;
if ( V_10 )
goto V_19;
V_10 = F_1 ( V_14 -> V_1 , V_2 ) ;
if ( V_10 )
goto V_19;
V_10 = F_16 ( V_9 -> V_22 , V_2 ) ;
V_19:
F_17 ( V_15 ) ;
V_18:
return V_10 ;
}
void F_18 ( struct V_13 * V_14 )
{
F_19 ( V_23 ) ;
F_20 ( & V_14 -> V_15 ) ;
F_10 ( ! F_21 ( & V_14 -> V_20 ) ) ;
F_22 ( V_14 , sizeof( struct V_13 ) ) ;
}
static int F_23 ( struct V_13 * V_14 )
{
unsigned long V_24 ;
T_2 V_25 = V_26 ;
F_24 ( & V_14 -> V_20 , V_24 ) ;
if ( V_14 -> V_27 )
V_25 |= V_28 ;
F_25 ( & V_14 -> V_20 , V_24 ) ;
return F_26 ( & V_14 -> V_15 , V_29 , V_25 ) ;
}
static int F_27 ( struct V_13 * V_14 )
{
int V_10 ;
if ( ! V_14 -> V_30 )
return - 1 ;
V_10 = F_28 ( & V_14 -> V_15 , V_14 -> V_30 -> V_11 ) ;
if ( V_10 )
return V_10 ;
if ( V_14 -> type != V_31 )
return F_23 ( V_14 ) ;
else
return F_29 ( & V_14 -> V_15 , V_14 -> V_30 -> V_11 ) ;
}
static int F_30 ( struct V_13 * V_14 )
{
struct V_32 V_33 ;
F_31 ( & V_33 ) ;
return F_32 ( & V_14 -> V_15 , & V_33 ) ;
}
int F_33 ( struct V_8 * V_9 )
{
struct V_13 * V_14 = F_4 ( V_9 ) ;
struct V_16 * V_15 = & V_14 -> V_15 ;
struct V_34 * V_35 = & V_15 -> V_35 ;
int V_10 ;
if ( ! V_35 -> V_36 ) {
V_10 = F_34 ( V_35 ) ;
if ( V_10 )
goto V_18;
}
V_10 = F_8 ( V_15 ) ;
if ( V_10 < 0 )
goto V_18;
V_10 = F_35 ( V_15 , V_37 | V_38 ) ;
if ( V_10 < 0 )
goto V_19;
V_10 = F_23 ( V_14 ) ;
if ( V_10 )
goto V_19;
V_10 = F_30 ( V_14 ) ;
if ( V_10 )
goto V_19;
V_10 = F_36 ( V_15 ) ;
if ( V_10 < 0 )
goto V_19;
V_10 = F_37 ( V_15 ) ;
if ( V_10 < 0 )
goto V_39;
V_10 = F_38 ( V_15 ) ;
if ( V_10 < 0 )
goto V_40;
F_39 ( V_14 ) ;
F_40 ( V_14 ) ;
F_41 ( V_41 , & V_14 -> V_24 ) ;
return 0 ;
V_40:
F_42 ( V_15 ) ;
V_39:
F_43 ( V_15 ) ;
V_19:
F_17 ( V_15 ) ;
V_18:
return V_10 ;
}
void F_44 ( struct V_8 * V_9 )
{
struct V_13 * V_14 = F_4 ( V_9 ) ;
struct V_16 * V_15 = & V_14 -> V_15 ;
struct V_42 * V_43 ;
struct V_44 * V_45 = & V_14 -> V_45 ;
F_45 ( V_41 , & V_14 -> V_24 ) ;
F_42 ( V_15 ) ;
F_46 ( V_14 ) ;
F_47 ( V_14 ) ;
F_19 ( V_23 ) ;
F_48 ( V_15 ) ;
F_43 ( V_15 ) ;
F_17 ( V_15 ) ;
while ( ( V_43 = F_49 ( V_45 ) ) )
F_50 ( V_43 ) ;
}
int F_51 ( struct V_13 * V_14 )
{
struct V_42 * V_46 ;
struct V_32 V_47 ;
unsigned int V_48 ;
int V_10 , V_49 , V_50 ;
T_1 V_51 ;
F_52 ( F_53 ( V_14 ) , L_1 ) ;
F_13 ( & V_14 -> V_20 ) ;
V_47 = V_14 -> V_47 ;
V_48 = V_14 -> V_48 ;
V_49 = V_14 -> V_46 . V_52 ;
V_50 = V_14 -> V_46 . V_53 ;
V_51 = V_14 -> V_51 ;
F_14 ( & V_14 -> V_20 ) ;
V_10 = F_27 ( V_14 ) ;
if ( V_10 < 0 ) {
F_52 ( F_53 ( V_14 ) , L_2 , V_10 ) ;
return V_10 ;
}
V_10 = F_54 ( & V_14 -> V_15 , V_51 ) ;
if ( V_10 < 0 ) {
F_52 ( F_53 ( V_14 ) , L_3 ,
V_10 ) ;
return V_10 ;
}
F_55 ( V_14 , V_48 ) ;
V_10 = F_32 ( & V_14 -> V_15 , & V_47 ) ;
if ( V_10 < 0 ) {
F_52 ( F_53 ( V_14 ) ,
L_4 , V_10 ) ;
return V_10 ;
}
if ( V_14 -> type == V_54 ||
V_14 -> type == V_55 ||
V_14 -> type == V_31 ) {
if ( V_14 -> V_30 != NULL ) {
V_46 = F_56 ( V_14 -> V_9 , V_14 -> V_30 ) ;
if ( V_46 ) {
F_57 ( V_14 -> V_9 , V_46 ) ;
F_58 ( V_46 ) ;
}
}
F_59 ( & V_14 -> V_15 , V_49 ,
V_50 , V_14 -> type ) ;
F_13 ( & V_14 -> V_20 ) ;
V_14 -> V_46 . V_56 = V_57 ;
F_14 ( & V_14 -> V_20 ) ;
}
return 0 ;
}
static void F_60 ( struct V_8 * V_9 , struct V_42 * V_43 ,
int V_58 , struct V_59 * V_59 )
{
struct V_60 * V_61 = F_61 ( V_43 ) ;
int V_3 ;
int V_62 = 1 , V_63 = 1 ;
int V_64 ;
const struct V_65 * V_66 ;
F_62 ( V_61 ) ;
if ( V_59 ) {
V_62 = ! V_59 -> V_67 ;
V_63 = V_59 -> V_63 + V_62 ;
}
if ( V_62 ) {
V_61 -> V_24 |= V_68 ;
} else {
V_61 -> V_24 &= ~ V_68 ;
}
V_64 = V_61 -> V_69 . V_70 [ 0 ] . V_71 ;
F_10 ( 0 <= V_64 && V_64 < F_2 ( V_72 ) ) ;
V_66 = & V_72 [ V_64 ] ;
F_10 ( 1 <= V_63 && V_63 <= V_66 -> V_73 ) ;
V_61 -> V_69 . V_70 [ 0 ] . V_71 = V_66 -> V_74 [ 0 ] ;
V_61 -> V_69 . V_70 [ 0 ] . V_73 = 1 ;
for ( V_3 = 1 ; V_3 < V_75 - 1 && V_3 < V_63 ; V_3 ++ ) {
V_61 -> V_69 . V_70 [ V_3 ] . V_71 = V_66 -> V_74 [ V_3 ] ;
V_61 -> V_69 . V_70 [ V_3 ] . V_73 = 1 ;
}
for (; V_3 < V_75 && V_3 < V_63 ; V_3 ++ ) {
V_61 -> V_69 . V_70 [ V_3 ] . V_71 = V_66 -> V_74 [ V_63 - 1 ] ;
V_61 -> V_69 . V_70 [ V_3 ] . V_73 = 1 ;
}
if ( V_3 < V_75 )
V_61 -> V_69 . V_70 [ V_3 ] . V_71 = - 1 ;
V_61 -> V_69 . V_76 = V_58 ;
F_63 ( V_9 , V_43 ) ;
}
void F_64 ( struct V_77 * V_77 )
{
struct V_8 * V_9 = F_65 ( V_77 -> V_78 ) ;
struct V_13 * V_14 = F_4 ( V_9 ) ;
struct V_44 * V_79 = & V_14 -> V_45 ;
struct V_42 * V_43 ;
struct V_59 * V_59 = (struct V_59 * ) V_77 -> V_80 ;
unsigned long V_24 ;
int V_62 = ! V_59 -> V_67 ;
int V_63 = V_59 -> V_63 + V_62 ;
int V_81 = 0 ;
int V_3 , V_82 = 0 ;
V_79 = & V_14 -> V_45 ;
F_24 ( & V_79 -> V_20 , V_24 ) ;
F_66 (q, skb) {
struct V_83 * V_84 ;
struct V_60 * V_61 ;
int V_64 , V_85 ;
const struct V_65 * V_66 ;
T_1 V_86 ;
V_82 ++ ;
if ( V_59 -> V_67 && V_14 -> V_87 &&
F_67 ( V_79 , V_43 ) ) {
continue;
}
V_84 = (struct V_83 * ) V_43 -> V_88 ;
if ( F_68 ( memcmp ( V_84 -> V_89 , V_59 -> V_14 , V_12 ) ) ) {
continue;
}
V_61 = F_61 ( V_43 ) ;
V_64 = V_61 -> V_69 . V_70 [ 0 ] . V_71 ;
F_10 ( 0 <= V_64 && V_64 < F_2 ( V_72 ) ) ;
V_66 = & V_72 [ V_64 ] ;
if ( V_63 <= 0 || V_63 > V_66 -> V_73 )
continue;
V_85 = V_66 -> V_74 [ V_63 - 1 ] ;
V_86 = V_90 [ V_85 ] . V_91 ;
if ( V_86 != V_59 -> V_74 ) {
continue;
}
V_81 = 1 ;
break;
}
if ( V_81 ) {
for ( V_3 = 1 ; V_3 <= V_82 ; V_3 ++ ) {
V_43 = F_69 ( V_79 ) ;
F_60 ( V_9 , V_43 ,
V_14 -> V_87 ? V_14 -> V_76 : 0 ,
V_3 == V_82 ? V_59 : NULL ) ;
V_14 -> V_87 = 0 ;
}
}
F_25 ( & V_79 -> V_20 , V_24 ) ;
}
void F_70 ( struct V_42 * V_43 , int error )
{
struct V_60 * V_61 = F_61 ( V_43 ) ;
struct V_8 * V_9 = V_61 -> V_92 [ 0 ] ;
struct V_13 * V_14 = F_4 ( V_9 ) ;
F_62 ( V_61 ) ;
F_71 ( V_43 , sizeof( struct V_93 ) ) ;
if ( F_68 ( error ||
( V_61 -> V_24 & V_94 ) ) ) {
F_63 ( V_9 , V_43 ) ;
} else {
struct V_44 * V_79 = & V_14 -> V_45 ;
F_72 ( V_79 , V_43 ) ;
while ( F_73 ( V_79 ) > V_95 ) {
F_60 ( V_9 , F_49 ( V_79 ) ,
V_14 -> V_87 ? V_14 -> V_76 : 0 ,
NULL ) ;
V_14 -> V_87 = 0 ;
}
}
}
static int F_74 ( T_1 * V_96 , T_1 V_97 , T_3 V_98 )
{
static const T_1 V_99 [] = {
[ F_75 ( V_100 ) ] = 1 ,
[ F_75 ( V_101 ) ] = 2 ,
[ F_75 ( V_102 ) ] = 11 ,
[ F_75 ( V_103 ) ] = 11 ,
[ F_75 ( V_104 ) ] = 6 ,
[ F_75 ( V_105 ) ] = 9 ,
[ F_75 ( V_106 ) ] = 12 ,
[ F_75 ( V_107 ) ] = 18 ,
[ F_75 ( V_108 ) ] = 24 ,
[ F_75 ( V_109 ) ] = 36 ,
[ F_75 ( V_110 ) ] = 48 ,
[ F_75 ( V_111 ) ] = 54 ,
} ;
T_2 V_112 = ( T_2 ) V_98 * 8 ;
T_2 V_113 ;
V_113 = V_99 [ F_75 ( V_97 ) ] ;
if ( V_113 == 0 )
return - V_114 ;
switch ( V_97 ) {
case V_102 :
V_112 = ( 2 * V_112 ) + 10 ;
break;
case V_103 :
if ( V_96 ) {
T_2 V_115 = V_112 % 11 ;
* V_96 &= ~ V_116 ;
if ( 0 < V_115 && V_115 <= 3 ) {
* V_96 |= V_116 ;
}
}
V_112 += 10 ;
break;
}
return V_112 / V_113 ;
}
static void F_76 ( struct V_13 * V_14 , struct V_93 * V_117 ,
struct V_83 * V_118 ,
struct V_60 * V_61 )
{
V_117 -> V_119 = 0 ;
if ( V_61 -> V_24 & V_120 )
V_117 -> V_119 |= V_121 ;
if ( V_61 -> V_24 & V_94 )
V_117 -> V_119 |= V_122 ;
if ( F_77 ( V_118 -> V_123 ) )
V_117 -> V_119 |= V_124 ;
if ( V_61 -> V_119 . V_70 [ 0 ] . V_24 & V_125 )
V_117 -> V_119 |= V_126 ;
if ( V_61 -> V_119 . V_70 [ 0 ] . V_24 & V_127 )
V_117 -> V_119 |= V_128 ;
}
static int F_57 ( struct V_8 * V_9 , struct V_42 * V_46 )
{
struct V_13 * V_14 = F_4 ( V_9 ) ;
int V_10 , V_129 , V_130 , V_131 = 0 ;
T_2 V_132 , V_133 = 0 ;
T_2 V_134 = V_46 -> V_135 + 4 ;
unsigned long V_136 , V_137 ;
struct V_138 * V_139 ;
V_130 = 1 + F_78 ( & V_14 -> V_15 ) + V_134 ;
V_139 = F_79 ( V_130 * sizeof( struct V_138 ) , V_140 ) ;
if ( ! V_139 )
return - V_141 ;
F_80 ( & V_14 -> V_15 . V_142 ) ;
V_10 = F_81 ( & V_14 -> V_15 , 0 , V_143 ) ;
if ( V_10 < 0 )
goto V_18;
V_10 = F_82 ( & V_14 -> V_15 , & V_132 , V_143 ) ;
if ( V_10 < 0 )
goto V_144;
V_136 = V_57 + V_145 / 2 ;
V_137 = V_57 + V_145 / 10 ;
while ( V_132 & 0x2 ) {
V_10 = F_82 ( & V_14 -> V_15 , & V_132 , V_143 ) ;
if ( V_10 < 0 )
goto V_144;
if ( F_83 ( V_137 ) ) {
V_137 = V_57 + V_145 / 10 ;
F_84 ( F_53 ( V_14 ) ,
L_5 ) ;
if ( F_83 ( V_136 ) ) {
F_84 ( F_53 ( V_14 ) ,
L_6 ) ;
V_10 = - V_146 ;
goto V_147;
}
}
F_85 ( 20 ) ;
}
V_139 [ V_131 ] . V_11 = V_148 ;
V_139 [ V_131 ] . V_149 = V_134 - 1 ;
V_131 ++ ;
if ( F_78 ( & V_14 -> V_15 ) ) {
V_139 [ V_131 ] . V_11 = V_150 ;
V_139 [ V_131 ] . V_149 = V_134 - 1 ;
V_131 ++ ;
}
for ( V_133 = 0 ; V_133 < V_46 -> V_135 ; V_133 ++ ) {
V_139 [ V_131 ] . V_11 = V_148 ;
V_139 [ V_131 ] . V_149 = * ( ( T_1 * ) ( V_46 -> V_88 + V_133 ) ) ;
V_131 ++ ;
}
for ( V_133 = 0 ; V_133 < 4 ; V_133 ++ ) {
V_139 [ V_131 ] . V_11 = V_148 ;
V_139 [ V_131 ] . V_149 = 0x0 ;
V_131 ++ ;
}
F_86 ( V_131 != V_130 ) ;
V_10 = F_87 ( & V_14 -> V_15 , V_139 , V_130 ) ;
V_144:
V_136 = V_57 + V_145 / 2 ;
V_129 = F_81 ( & V_14 -> V_15 , 1 , V_143 ) ;
while ( V_129 < 0 ) {
if ( F_83 ( V_136 ) ) {
V_129 = - V_146 ;
break;
}
F_85 ( 20 ) ;
V_129 = F_81 ( & V_14 -> V_15 , 1 , V_143 ) ;
}
if ( V_129 < 0 )
F_84 ( F_53 ( V_14 ) , L_7
L_8 ) ;
if ( V_10 < 0 || V_129 < 0 ) {
if ( V_10 >= 0 )
V_10 = V_129 ;
goto V_18;
}
V_10 = F_81 ( & V_14 -> V_15 , 0x00000400 | ( V_134 << 19 ) ,
V_151 ) ;
V_18:
F_88 ( & V_14 -> V_15 . V_142 ) ;
F_89 ( V_139 ) ;
return V_10 ;
V_147:
F_88 ( & V_14 -> V_15 . V_142 ) ;
F_89 ( V_139 ) ;
F_90 ( F_53 ( V_14 ) , L_9
L_10 ) ;
F_91 ( V_14 -> V_15 . V_35 . V_152 ) ;
return V_10 ;
}
static int F_92 ( struct V_13 * V_14 ,
struct V_42 * V_43 )
{
int V_10 ;
struct V_83 * V_153 = (struct V_83 * ) V_43 -> V_88 ;
unsigned int V_154 = V_43 -> V_135 + V_155 ;
unsigned int V_156 ;
struct V_157 * V_158 ;
struct V_93 * V_117 = (struct V_93 * )
F_93 ( V_43 , sizeof( struct V_93 ) ) ;
struct V_60 * V_61 = F_61 ( V_43 ) ;
F_10 ( V_154 <= 0xffff ) ;
V_158 = F_94 ( V_14 -> V_9 , V_61 ) ;
V_117 -> V_159 = V_158 -> V_91 ;
if ( V_61 -> V_119 . V_70 [ 0 ] . V_24 & V_160 )
V_117 -> V_159 = V_158 -> V_161 ;
V_117 -> V_98 = F_95 ( V_154 ) ;
F_76 ( V_14 , V_117 , V_153 , V_61 ) ;
V_156 = V_154 + sizeof( struct V_93 ) + 10 ;
F_10 ( V_156 <= 0xffff ) ;
V_117 -> V_156 = F_95 ( F_78 ( & V_14 -> V_15 ) ?
V_156 - V_154 : V_156 ) ;
V_117 -> V_96 = 0 ;
V_10 = F_74 ( & V_117 -> V_96 , F_96 ( V_117 -> V_159 ) ,
F_97 ( V_117 -> V_98 ) ) ;
if ( V_10 < 0 )
return V_10 ;
V_117 -> V_162 = F_95 ( V_10 ) ;
V_117 -> V_163 = 0 ;
return 0 ;
}
static void F_98 ( struct V_8 * V_9 , struct V_42 * V_43 )
{
struct V_13 * V_14 = F_4 ( V_9 ) ;
struct V_60 * V_61 = F_61 ( V_43 ) ;
int V_10 ;
V_10 = F_92 ( V_14 , V_43 ) ;
if ( V_10 )
goto V_164;
V_61 -> V_92 [ 0 ] = V_9 ;
V_10 = F_99 ( & V_14 -> V_15 . V_35 , V_43 ) ;
if ( V_10 )
goto V_164;
return;
V_164:
F_100 ( V_43 ) ;
}
static int F_101 ( struct V_8 * V_9 , struct V_83 * V_165 ,
struct V_166 * V_167 )
{
struct V_13 * V_14 = F_4 ( V_9 ) ;
struct V_42 * V_43 ;
struct V_44 * V_79 ;
unsigned long V_24 ;
int V_81 = 0 ;
int V_3 , V_82 = 0 ;
if ( ! F_102 ( V_165 -> V_123 ) )
return 0 ;
V_79 = & V_14 -> V_45 ;
F_24 ( & V_79 -> V_20 , V_24 ) ;
F_66 (q, skb) {
struct V_83 * V_84 ;
V_82 ++ ;
if ( V_14 -> V_87 && F_67 ( V_79 , V_43 ) )
continue;
V_84 = (struct V_83 * ) V_43 -> V_88 ;
if ( F_103 ( ! memcmp ( V_84 -> V_168 , V_165 -> V_89 , V_12 ) ) )
{
V_81 = 1 ;
break;
}
}
if ( V_81 ) {
for ( V_3 = 1 ; V_3 < V_82 ; V_3 ++ ) {
V_43 = F_69 ( V_79 ) ;
F_60 ( V_9 , V_43 ,
V_14 -> V_87 ? V_14 -> V_76 : 0 ,
NULL ) ;
V_14 -> V_87 = 0 ;
}
V_14 -> V_87 = 1 ;
V_14 -> V_76 = V_167 -> signal ;
if ( V_14 -> type == V_31 ) {
V_43 = F_69 ( V_79 ) ;
F_60 ( V_9 , V_43 , V_14 -> V_76 , NULL ) ;
V_14 -> V_87 = 0 ;
}
}
F_25 ( & V_79 -> V_20 , V_24 ) ;
return 1 ;
}
int F_104 ( struct V_8 * V_9 , const T_1 * V_169 , unsigned int V_170 )
{
struct V_13 * V_14 = F_4 ( V_9 ) ;
struct V_166 V_167 ;
const struct V_171 * V_69 ;
struct V_42 * V_43 ;
int V_172 = 0 ;
T_4 V_173 ;
int V_174 ;
int V_3 ;
T_1 V_74 ;
if ( V_170 < V_175 + 10 +
V_155 + sizeof( struct V_171 ) )
return - V_114 ;
memset ( & V_167 , 0 , sizeof( V_167 ) ) ;
V_69 = (struct V_171 * )
( V_169 + ( V_170 - sizeof( struct V_171 ) ) ) ;
if ( V_69 -> V_176 & V_177 ) {
if ( V_14 -> V_178 &&
( V_69 -> V_176 & V_179 ) ) {
V_167 . V_180 |= V_181 ;
V_172 = 1 ;
} else {
return - V_114 ;
}
}
V_167 . V_182 = V_183 [ F_105 ( & V_14 -> V_15 ) - 1 ] . V_184 ;
V_167 . V_185 = V_186 ;
V_167 . signal = V_69 -> V_187 ;
V_74 = F_106 ( V_169 , V_69 ) ;
for ( V_3 = 0 ; V_3 < V_14 -> V_185 . V_188 ; V_3 ++ )
if ( V_74 == V_14 -> V_185 . V_189 [ V_3 ] . V_91 )
V_167 . V_190 = V_3 ;
V_170 -= V_175 + sizeof( struct V_171 ) ;
V_169 += V_175 ;
if ( ! V_172 &&
F_101 ( V_9 , (struct V_83 * ) V_169 , & V_167 )
&& ! V_14 -> V_27 )
return 0 ;
V_173 = F_107 ( ( T_4 * ) V_169 ) ;
V_174 = F_108 ( V_173 ) ^ F_109 ( V_173 ) ;
V_43 = F_110 ( V_170 + ( V_174 ? 2 : 0 ) ) ;
if ( V_43 == NULL )
return - V_141 ;
if ( V_174 ) {
F_111 ( V_43 , 2 ) ;
}
memcpy ( F_112 ( V_43 , V_170 ) , V_169 , V_170 ) ;
memcpy ( F_113 ( V_43 ) , & V_167 , sizeof( V_167 ) ) ;
F_114 ( V_9 , V_43 ) ;
return 0 ;
}
static int F_115 ( struct V_8 * V_9 ,
struct V_191 * V_30 )
{
struct V_13 * V_14 = F_4 ( V_9 ) ;
if ( V_14 -> type != V_192 )
return - V_193 ;
switch ( V_30 -> type ) {
case V_194 :
case V_54 :
case V_195 :
case V_55 :
case V_31 :
V_14 -> type = V_30 -> type ;
break;
default:
return - V_193 ;
}
V_14 -> V_30 = V_30 ;
return F_27 ( V_14 ) ;
}
static void F_116 ( struct V_8 * V_9 ,
struct V_191 * V_30 )
{
struct V_13 * V_14 = F_4 ( V_9 ) ;
V_14 -> type = V_192 ;
V_14 -> V_30 = NULL ;
F_59 ( & V_14 -> V_15 , 0 , 0 , V_192 ) ;
F_28 ( & V_14 -> V_15 , NULL ) ;
}
static int F_117 ( struct V_8 * V_9 , T_2 V_196 )
{
struct V_13 * V_14 = F_4 ( V_9 ) ;
struct V_197 * V_198 = & V_9 -> V_198 ;
F_13 ( & V_14 -> V_20 ) ;
V_14 -> V_51 = V_198 -> V_51 -> V_91 ;
F_14 ( & V_14 -> V_20 ) ;
return F_54 ( & V_14 -> V_15 , V_198 -> V_51 -> V_91 ) ;
}
static void F_118 ( struct V_13 * V_14 )
{
struct V_42 * V_43 , * V_46 ;
if ( ! F_119 ( V_41 , & V_14 -> V_24 ) )
return;
if ( ! V_14 -> V_30 || V_14 -> V_30 -> type != V_31 )
return;
while ( ! F_120 ( V_14 -> V_9 , 0 ) ) {
V_43 = F_121 ( V_14 -> V_9 , V_14 -> V_30 ) ;
if ( ! V_43 )
break;
F_98 ( V_14 -> V_9 , V_43 ) ;
}
V_46 = F_56 ( V_14 -> V_9 , V_14 -> V_30 ) ;
if ( V_46 ) {
F_57 ( V_14 -> V_9 , V_46 ) ;
F_58 ( V_46 ) ;
}
F_13 ( & V_14 -> V_20 ) ;
V_14 -> V_46 . V_56 = V_57 ;
F_14 ( & V_14 -> V_20 ) ;
}
static void F_122 ( struct V_199 * V_200 )
{
T_3 V_201 ;
unsigned long V_24 ;
struct V_13 * V_14 = F_123 ( V_200 , struct V_13 , V_202 ) ;
F_24 ( & V_14 -> V_20 , V_24 ) ;
V_201 = F_97 ( * ( T_4 * ) ( V_14 -> V_203 + 4 ) ) ;
F_25 ( & V_14 -> V_20 , V_24 ) ;
if ( V_201 & V_204 ) {
F_118 ( V_14 ) ;
} else {
F_52 ( F_53 ( V_14 ) , L_11 ) ;
}
F_38 ( & V_14 -> V_15 ) ;
}
static T_5 F_124 ( struct V_8 * V_9 ,
struct V_205 * V_206 )
{
struct V_13 * V_14 = F_4 ( V_9 ) ;
struct V_32 V_33 ;
struct V_207 * V_208 ;
F_31 ( & V_33 ) ;
F_125 (ha, mc_list) {
F_52 ( F_53 ( V_14 ) , L_12 , V_208 -> V_11 ) ;
F_126 ( & V_33 , V_208 -> V_11 ) ;
}
return V_33 . V_209 | ( ( T_5 ) V_33 . V_210 << 32 ) ;
}
static void F_127 ( struct V_8 * V_9 ,
unsigned int V_211 ,
unsigned int * V_212 ,
T_5 V_213 )
{
struct V_32 V_33 = {
. V_209 = V_213 ,
. V_210 = V_213 >> 32 ,
} ;
struct V_13 * V_14 = F_4 ( V_9 ) ;
unsigned long V_24 ;
int V_10 ;
V_211 &= V_214 ;
* V_212 &= V_214 ;
if ( * V_212 & ( V_215 | V_216 ) )
F_128 ( & V_33 ) ;
F_24 ( & V_14 -> V_20 , V_24 ) ;
V_14 -> V_178 = ! ! ( * V_212 & V_217 ) ;
V_14 -> V_27 = ! ! ( * V_212 & V_218 ) ;
V_14 -> V_47 = V_33 ;
F_25 ( & V_14 -> V_20 , V_24 ) ;
F_32 ( & V_14 -> V_15 , & V_33 ) ;
if ( V_211 & V_218 ) {
V_10 = F_23 ( V_14 ) ;
if ( V_10 )
F_84 ( F_53 ( V_14 ) , L_13 , V_10 ) ;
}
}
static void F_55 ( struct V_13 * V_14 , unsigned int V_48 )
{
F_80 ( & V_14 -> V_15 . V_142 ) ;
F_129 ( & V_14 -> V_15 , V_48 ) ;
F_88 ( & V_14 -> V_15 . V_142 ) ;
}
static void F_130 ( struct V_8 * V_9 ,
struct V_191 * V_30 ,
struct V_219 * V_220 ,
T_2 V_221 )
{
struct V_13 * V_14 = F_4 ( V_9 ) ;
int V_222 ;
F_52 ( F_53 ( V_14 ) , L_14 , V_221 ) ;
if ( V_14 -> type == V_54 ||
V_14 -> type == V_55 ||
V_14 -> type == V_31 ) {
V_222 = true ;
if ( V_221 & V_223 ) {
struct V_42 * V_46 = F_56 ( V_9 , V_30 ) ;
if ( V_46 ) {
F_48 ( & V_14 -> V_15 ) ;
F_57 ( V_9 , V_46 ) ;
F_38 ( & V_14 -> V_15 ) ;
F_58 ( V_46 ) ;
}
}
if ( V_221 & V_224 ) {
T_3 V_52 = 0 ;
T_1 V_53 = 0 ;
if ( V_220 -> V_225 ) {
V_53 = V_220 -> V_226 ;
V_52 = V_220 -> V_227 ;
}
F_13 ( & V_14 -> V_20 ) ;
V_14 -> V_46 . V_53 = V_53 ;
V_14 -> V_46 . V_52 = V_52 ;
V_14 -> V_46 . V_56 = V_57 ;
F_14 ( & V_14 -> V_20 ) ;
F_59 ( & V_14 -> V_15 , V_52 , V_53 ,
V_14 -> type ) ;
}
} else
V_222 = F_131 ( V_220 -> V_228 ) ;
F_13 ( & V_14 -> V_20 ) ;
V_14 -> V_222 = V_222 ;
F_14 ( & V_14 -> V_20 ) ;
if ( V_221 & V_229 ) {
F_13 ( & V_14 -> V_20 ) ;
V_14 -> V_48 = V_220 -> V_230 ;
F_14 ( & V_14 -> V_20 ) ;
F_55 ( V_14 , V_220 -> V_230 ) ;
}
}
static T_5 F_132 ( struct V_8 * V_9 )
{
struct V_13 * V_14 = F_4 ( V_9 ) ;
return F_133 ( & V_14 -> V_15 ) ;
}
struct V_8 * F_134 ( struct V_231 * V_152 )
{
struct V_13 * V_14 ;
struct V_8 * V_9 ;
V_9 = F_135 ( sizeof( struct V_13 ) , & V_232 ) ;
if ( ! V_9 ) {
F_52 ( & V_152 -> V_233 , L_15 ) ;
return NULL ;
}
V_14 = F_4 ( V_9 ) ;
memset ( V_14 , 0 , sizeof( * V_14 ) ) ;
F_136 ( & V_14 -> V_20 ) ;
V_14 -> V_9 = V_9 ;
V_14 -> type = V_192 ;
memcpy ( V_14 -> V_234 , V_183 , sizeof( V_183 ) ) ;
memcpy ( V_14 -> V_70 , V_90 , sizeof( V_90 ) ) ;
V_14 -> V_185 . V_188 = F_2 ( V_90 ) ;
V_14 -> V_185 . V_189 = V_14 -> V_70 ;
V_14 -> V_185 . V_235 = F_2 ( V_183 ) ;
V_14 -> V_185 . V_234 = V_14 -> V_234 ;
V_9 -> V_22 -> V_236 [ V_186 ] = & V_14 -> V_185 ;
V_9 -> V_24 = V_237 |
V_238 |
V_239 ;
V_9 -> V_22 -> V_240 =
F_137 ( V_54 ) |
F_137 ( V_195 ) |
F_137 ( V_55 ) |
F_137 ( V_31 ) ;
V_9 -> V_241 = 100 ;
V_9 -> V_242 = 1 ;
V_9 -> V_243 = sizeof( struct V_93 ) ;
V_9 -> V_244 = V_75 ;
V_9 -> V_245 = 18 ;
F_138 ( & V_14 -> V_45 ) ;
V_14 -> V_87 = 0 ;
F_139 ( & V_14 -> V_15 , V_9 , V_152 ) ;
F_140 ( V_14 ) ;
F_141 ( V_14 ) ;
F_142 ( & V_14 -> V_202 , F_122 ) ;
F_143 ( V_9 , & V_152 -> V_233 ) ;
return V_9 ;
}
static void F_144 ( struct V_199 * V_200 )
{
struct V_13 * V_14 =
F_123 ( V_200 , struct V_13 , V_46 . V_246 . V_200 ) ;
struct V_42 * V_46 ;
unsigned long V_247 ;
int V_52 , V_53 ;
if ( ! F_119 ( V_41 , & V_14 -> V_24 ) )
goto V_248;
if ( V_14 -> type != V_31 || ! V_14 -> V_30 )
goto V_248;
F_13 ( & V_14 -> V_20 ) ;
V_52 = V_14 -> V_46 . V_52 ;
V_53 = V_14 -> V_46 . V_53 ;
V_247 = V_14 -> V_46 . V_56 + F_145 ( V_52 ) + V_145 ;
F_14 ( & V_14 -> V_20 ) ;
if ( V_52 > 0 && F_146 ( V_247 ) ) {
F_52 ( F_53 ( V_14 ) , L_16
L_17
L_18 ,
V_52 , V_53 ) ;
F_48 ( & V_14 -> V_15 ) ;
V_46 = F_56 ( V_14 -> V_9 , V_14 -> V_30 ) ;
if ( V_46 ) {
F_57 ( V_14 -> V_9 , V_46 ) ;
F_58 ( V_46 ) ;
}
F_59 ( & V_14 -> V_15 , V_52 , V_53 , V_14 -> type ) ;
F_38 ( & V_14 -> V_15 ) ;
F_13 ( & V_14 -> V_20 ) ;
V_14 -> V_46 . V_56 = V_57 ;
F_14 ( & V_14 -> V_20 ) ;
}
V_248:
F_147 ( V_23 , & V_14 -> V_46 . V_246 ,
V_249 ) ;
}
static void F_141 ( struct V_13 * V_14 )
{
F_148 ( & V_14 -> V_46 . V_246 , F_144 ) ;
}
static void F_40 ( struct V_13 * V_14 )
{
F_52 ( F_53 ( V_14 ) , L_1 ) ;
V_14 -> V_46 . V_56 = V_57 ;
F_147 ( V_23 , & V_14 -> V_46 . V_246 ,
V_249 ) ;
}
static void F_46 ( struct V_13 * V_14 )
{
F_52 ( F_53 ( V_14 ) , L_1 ) ;
F_149 ( & V_14 -> V_46 . V_246 ) ;
}
static void F_150 ( struct V_199 * V_200 )
{
struct V_13 * V_14 =
F_123 ( V_200 , struct V_13 , V_250 . V_251 . V_200 ) ;
struct V_16 * V_15 = & V_14 -> V_15 ;
int V_252 ;
int V_10 ;
if ( ! F_119 ( V_41 , & V_14 -> V_24 ) )
goto V_253;
F_13 ( & V_14 -> V_20 ) ;
V_252 = V_14 -> V_222 ;
F_14 ( & V_14 -> V_20 ) ;
V_10 = F_151 ( V_15 ,
V_252 ? V_254 : V_255 ) ;
if ( V_10 )
F_52 ( F_53 ( V_14 ) , L_19 , V_10 ) ;
V_253:
F_147 ( V_23 , & V_14 -> V_250 . V_251 ,
V_256 ) ;
}
static void F_140 ( struct V_13 * V_14 )
{
F_148 ( & V_14 -> V_250 . V_251 , F_150 ) ;
}
static void F_39 ( struct V_13 * V_14 )
{
F_52 ( F_53 ( V_14 ) , L_1 ) ;
F_147 ( V_23 , & V_14 -> V_250 . V_251 ,
0 ) ;
}
static void F_47 ( struct V_13 * V_14 )
{
F_52 ( F_53 ( V_14 ) , L_1 ) ;
F_149 ( & V_14 -> V_250 . V_251 ) ;
F_151 ( & V_14 -> V_15 , V_257 ) ;
}
