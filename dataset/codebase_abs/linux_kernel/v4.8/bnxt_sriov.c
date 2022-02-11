static int F_1 ( struct V_1 * V_2 , int V_3 )
{
if ( ! F_2 ( V_4 , & V_2 -> V_5 ) ) {
F_3 ( V_2 -> V_6 , L_1 ) ;
return - V_7 ;
}
if ( ! V_2 -> V_8 . V_9 ) {
F_3 ( V_2 -> V_6 , L_2 ) ;
return - V_7 ;
}
if ( V_3 >= V_2 -> V_8 . V_10 ) {
F_3 ( V_2 -> V_6 , L_3 , V_3 ) ;
return - V_7 ;
}
return 0 ;
}
int F_4 ( struct V_11 * V_6 , int V_3 , bool V_12 )
{
struct V_13 V_14 = { 0 } ;
struct V_1 * V_2 = F_5 ( V_6 ) ;
struct V_15 * V_16 ;
bool V_17 = false ;
T_1 V_18 ;
int V_19 ;
V_19 = F_1 ( V_2 , V_3 ) ;
if ( V_19 )
return V_19 ;
V_16 = & V_2 -> V_8 . V_16 [ V_3 ] ;
if ( V_16 -> V_20 & V_21 )
V_17 = true ;
if ( V_17 == V_12 )
return 0 ;
V_18 = V_16 -> V_18 ;
if ( V_12 )
V_18 |= V_22 ;
else
V_18 &= ~ V_22 ;
F_6 ( V_2 , & V_14 , V_23 , - 1 , - 1 ) ;
V_14 . V_24 = F_7 ( V_16 -> V_25 ) ;
V_14 . V_20 = F_8 ( V_18 ) ;
V_19 = F_9 ( V_2 , & V_14 , sizeof( V_14 ) , V_26 ) ;
if ( ! V_19 ) {
V_16 -> V_18 = V_18 ;
if ( V_12 )
V_16 -> V_20 |= V_21 ;
else
V_16 -> V_20 &= ~ V_21 ;
}
return V_19 ;
}
int F_10 ( struct V_11 * V_6 , int V_3 ,
struct V_27 * V_28 )
{
struct V_1 * V_2 = F_5 ( V_6 ) ;
struct V_15 * V_16 ;
int V_19 ;
V_19 = F_1 ( V_2 , V_3 ) ;
if ( V_19 )
return V_19 ;
V_28 -> V_16 = V_3 ;
V_16 = & V_2 -> V_8 . V_16 [ V_3 ] ;
memcpy ( & V_28 -> V_29 , V_16 -> V_30 , V_31 ) ;
V_28 -> V_32 = V_16 -> V_32 ;
V_28 -> V_33 = V_16 -> V_33 ;
V_28 -> V_34 = V_16 -> V_34 ;
V_28 -> V_35 = V_16 -> V_20 & V_36 ;
V_28 -> V_37 = V_16 -> V_20 & V_21 ;
if ( ! ( V_16 -> V_20 & V_38 ) )
V_28 -> V_39 = V_40 ;
else if ( V_16 -> V_20 & V_41 )
V_28 -> V_39 = V_42 ;
else
V_28 -> V_39 = V_43 ;
return 0 ;
}
int F_11 ( struct V_11 * V_6 , int V_3 , T_2 * V_29 )
{
struct V_13 V_14 = { 0 } ;
struct V_1 * V_2 = F_5 ( V_6 ) ;
struct V_15 * V_16 ;
int V_19 ;
V_19 = F_1 ( V_2 , V_3 ) ;
if ( V_19 )
return V_19 ;
if ( F_12 ( V_29 ) ) {
F_3 ( V_6 , L_4 ) ;
return - V_7 ;
}
V_16 = & V_2 -> V_8 . V_16 [ V_3 ] ;
memcpy ( V_16 -> V_30 , V_29 , V_31 ) ;
F_6 ( V_2 , & V_14 , V_23 , - 1 , - 1 ) ;
V_14 . V_24 = F_7 ( V_16 -> V_25 ) ;
V_14 . V_20 = F_8 ( V_16 -> V_18 ) ;
V_14 . V_44 = F_8 ( V_45 ) ;
memcpy ( V_14 . V_46 , V_29 , V_31 ) ;
return F_9 ( V_2 , & V_14 , sizeof( V_14 ) , V_26 ) ;
}
int F_13 ( struct V_11 * V_6 , int V_3 , T_3 V_47 , T_2 V_35 )
{
struct V_13 V_14 = { 0 } ;
struct V_1 * V_2 = F_5 ( V_6 ) ;
struct V_15 * V_16 ;
T_3 V_48 ;
int V_19 ;
if ( V_2 -> V_49 < 0x10201 )
return - V_50 ;
V_19 = F_1 ( V_2 , V_3 ) ;
if ( V_19 )
return V_19 ;
if ( V_47 > 4095 || V_35 )
return - V_7 ;
V_16 = & V_2 -> V_8 . V_16 [ V_3 ] ;
V_48 = V_47 ;
if ( V_48 == V_16 -> V_34 )
return 0 ;
F_6 ( V_2 , & V_14 , V_23 , - 1 , - 1 ) ;
V_14 . V_24 = F_7 ( V_16 -> V_25 ) ;
V_14 . V_20 = F_8 ( V_16 -> V_18 ) ;
V_14 . V_51 = F_7 ( V_48 ) ;
V_14 . V_44 = F_8 ( V_52 ) ;
V_19 = F_9 ( V_2 , & V_14 , sizeof( V_14 ) , V_26 ) ;
if ( ! V_19 )
V_16 -> V_34 = V_48 ;
return V_19 ;
}
int F_14 ( struct V_11 * V_6 , int V_3 , int V_33 ,
int V_32 )
{
struct V_13 V_14 = { 0 } ;
struct V_1 * V_2 = F_5 ( V_6 ) ;
struct V_15 * V_16 ;
T_1 V_53 ;
int V_19 ;
V_19 = F_1 ( V_2 , V_3 ) ;
if ( V_19 )
return V_19 ;
V_16 = & V_2 -> V_8 . V_16 [ V_3 ] ;
V_53 = F_15 ( V_2 -> V_54 . V_55 ) ;
if ( V_32 > V_53 ) {
F_16 ( V_2 -> V_6 , L_5 ,
V_32 , V_3 ) ;
return - V_7 ;
}
if ( V_33 > V_53 || V_33 > V_32 ) {
F_16 ( V_2 -> V_6 , L_6 ,
V_33 , V_3 ) ;
return - V_7 ;
}
if ( V_33 == V_16 -> V_33 && V_32 == V_16 -> V_32 )
return 0 ;
F_6 ( V_2 , & V_14 , V_23 , - 1 , - 1 ) ;
V_14 . V_24 = F_7 ( V_16 -> V_25 ) ;
V_14 . V_20 = F_8 ( V_16 -> V_18 ) ;
V_14 . V_44 = F_8 ( V_56 ) ;
V_14 . V_57 = F_8 ( V_32 ) ;
V_14 . V_44 |= F_8 ( V_58 ) ;
V_14 . V_59 = F_8 ( V_33 ) ;
V_19 = F_9 ( V_2 , & V_14 , sizeof( V_14 ) , V_26 ) ;
if ( ! V_19 ) {
V_16 -> V_33 = V_33 ;
V_16 -> V_32 = V_32 ;
}
return V_19 ;
}
int F_17 ( struct V_11 * V_6 , int V_3 , int V_60 )
{
struct V_1 * V_2 = F_5 ( V_6 ) ;
struct V_15 * V_16 ;
int V_19 ;
V_19 = F_1 ( V_2 , V_3 ) ;
if ( V_19 )
return V_19 ;
V_16 = & V_2 -> V_8 . V_16 [ V_3 ] ;
V_16 -> V_20 &= ~ ( V_41 | V_38 ) ;
switch ( V_60 ) {
case V_40 :
V_16 -> V_20 |= V_41 ;
break;
case V_43 :
V_16 -> V_20 |= V_38 ;
break;
case V_42 :
V_16 -> V_20 |= V_41 | V_38 ;
break;
default:
F_3 ( V_2 -> V_6 , L_7 ) ;
V_19 = - V_7 ;
break;
}
return V_19 ;
}
static int F_18 ( struct V_1 * V_2 , int V_61 )
{
int V_62 ;
struct V_15 * V_16 ;
for ( V_62 = 0 ; V_62 < V_61 ; V_62 ++ ) {
V_16 = & V_2 -> V_8 . V_16 [ V_62 ] ;
memset ( V_16 , 0 , sizeof( * V_16 ) ) ;
V_16 -> V_20 = V_36 | V_41 ;
}
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , int V_61 )
{
int V_62 , V_19 = 0 ;
struct V_63 * V_8 = & V_2 -> V_8 ;
struct V_64 V_14 = { 0 } ;
F_6 ( V_2 , & V_14 , V_65 , - 1 , - 1 ) ;
F_20 ( & V_2 -> V_66 ) ;
for ( V_62 = V_8 -> V_67 ; V_62 < V_8 -> V_67 + V_61 ; V_62 ++ ) {
V_14 . V_3 = F_7 ( V_62 ) ;
V_19 = F_21 ( V_2 , & V_14 , sizeof( V_14 ) ,
V_26 ) ;
if ( V_19 )
break;
}
F_22 ( & V_2 -> V_66 ) ;
return V_19 ;
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_68 * V_69 = V_2 -> V_69 ;
int V_62 ;
F_24 ( V_2 -> V_8 . V_70 ) ;
V_2 -> V_8 . V_70 = NULL ;
for ( V_62 = 0 ; V_62 < 4 ; V_62 ++ ) {
if ( V_2 -> V_8 . V_71 [ V_62 ] ) {
F_25 ( & V_69 -> V_6 , V_72 ,
V_2 -> V_8 . V_71 [ V_62 ] ,
V_2 -> V_8 . V_73 [ V_62 ] ) ;
V_2 -> V_8 . V_71 [ V_62 ] = NULL ;
}
}
F_24 ( V_2 -> V_8 . V_16 ) ;
V_2 -> V_8 . V_16 = NULL ;
}
static int F_26 ( struct V_1 * V_2 , int V_61 )
{
struct V_68 * V_69 = V_2 -> V_69 ;
T_1 V_74 , V_75 , V_62 , V_76 , V_77 = 0 ;
V_2 -> V_8 . V_16 = F_27 ( V_61 , sizeof( struct V_15 ) , V_78 ) ;
if ( ! V_2 -> V_8 . V_16 )
return - V_79 ;
F_18 ( V_2 , V_61 ) ;
V_75 = V_61 * V_80 ;
V_74 = V_75 / V_72 ;
if ( V_75 & ( V_72 - 1 ) )
V_74 ++ ;
for ( V_62 = 0 ; V_62 < V_74 ; V_62 ++ ) {
V_2 -> V_8 . V_71 [ V_62 ] =
F_28 ( & V_69 -> V_6 , V_72 ,
& V_2 -> V_8 . V_73 [ V_62 ] ,
V_78 ) ;
if ( ! V_2 -> V_8 . V_71 [ V_62 ] )
return - V_79 ;
for ( V_76 = 0 ; V_76 < V_81 && V_77 < V_61 ; V_76 ++ ) {
struct V_15 * V_16 = & V_2 -> V_8 . V_16 [ V_77 ] ;
V_16 -> V_71 = V_2 -> V_8 . V_71 [ V_62 ] +
V_76 * V_80 ;
V_16 -> V_73 =
V_2 -> V_8 . V_73 [ V_62 ] + V_76 *
V_80 ;
V_77 ++ ;
}
}
V_2 -> V_8 . V_70 = F_29 ( 16 , V_78 ) ;
if ( ! V_2 -> V_8 . V_70 )
return - V_79 ;
V_2 -> V_8 . V_82 = V_74 ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_83 V_14 = { 0 } ;
F_6 ( V_2 , & V_14 , V_84 , - 1 , - 1 ) ;
V_14 . V_85 = F_7 ( V_2 -> V_8 . V_82 ) ;
V_14 . V_86 = F_7 ( V_87 ) ;
V_14 . V_88 = F_7 ( V_80 ) ;
V_14 . V_89 = F_31 ( V_2 -> V_8 . V_73 [ 0 ] ) ;
V_14 . V_90 = F_31 ( V_2 -> V_8 . V_73 [ 1 ] ) ;
V_14 . V_91 = F_31 ( V_2 -> V_8 . V_73 [ 2 ] ) ;
V_14 . V_92 = F_31 ( V_2 -> V_8 . V_73 [ 3 ] ) ;
return F_9 ( V_2 , & V_14 , sizeof( V_14 ) , V_26 ) ;
}
static int F_32 ( struct V_1 * V_2 , int V_61 )
{
T_1 V_19 = 0 , V_93 , V_62 ;
T_3 V_94 , V_95 , V_96 , V_97 , V_98 ;
T_3 V_99 ;
struct V_13 V_14 = { 0 } ;
struct V_63 * V_8 = & V_2 -> V_8 ;
F_6 ( V_2 , & V_14 , V_23 , - 1 , - 1 ) ;
V_96 = F_33 ( T_3 , V_8 -> V_100 , V_8 -> V_101 ) ;
V_96 = ( V_96 - V_2 -> V_102 ) / V_61 ;
V_97 = ( V_8 -> V_101 - V_2 -> V_103 ) / V_61 ;
if ( V_2 -> V_20 & V_104 )
V_95 = ( V_8 -> V_105 - V_2 -> V_106 * 2 ) /
V_61 ;
else
V_95 = ( V_8 -> V_105 - V_2 -> V_106 ) / V_61 ;
V_99 = ( V_2 -> V_8 . V_107 - V_2 -> V_106 ) / V_61 ;
V_94 = ( V_8 -> V_108 - V_2 -> V_109 ) / V_61 ;
V_14 . V_44 = F_8 ( V_110 |
V_111 |
V_112 |
V_113 |
V_114 |
V_115 |
V_116 |
V_117 |
V_118 |
V_119 ) ;
V_93 = V_2 -> V_6 -> V_93 + V_120 + V_121 + V_122 ;
V_14 . V_123 = F_7 ( V_93 ) ;
V_14 . V_93 = F_7 ( V_93 ) ;
V_14 . V_124 = F_7 ( 1 ) ;
V_14 . V_125 = F_7 ( V_96 ) ;
V_14 . V_126 = F_7 ( V_94 ) ;
V_14 . V_127 = F_7 ( V_95 ) ;
V_14 . V_128 = F_7 ( V_99 ) ;
V_14 . V_129 = F_7 ( 4 ) ;
V_98 = 1 ;
V_14 . V_130 = F_7 ( V_98 ) ;
V_14 . V_103 = F_7 ( V_97 ) ;
F_20 ( & V_2 -> V_66 ) ;
for ( V_62 = 0 ; V_62 < V_61 ; V_62 ++ ) {
V_14 . V_24 = F_7 ( V_8 -> V_67 + V_62 ) ;
V_19 = F_21 ( V_2 , & V_14 , sizeof( V_14 ) ,
V_26 ) ;
if ( V_19 )
break;
V_8 -> V_9 = V_62 + 1 ;
V_8 -> V_16 [ V_62 ] . V_25 = F_34 ( V_14 . V_24 ) ;
}
F_22 ( & V_2 -> V_66 ) ;
if ( ! V_19 ) {
V_8 -> V_108 -= V_94 * V_61 ;
V_8 -> V_105 -= V_95 * V_61 ;
V_8 -> V_107 -= V_99 * V_61 ;
V_8 -> V_100 -= V_96 * V_61 ;
V_8 -> V_131 -= V_61 ;
V_8 -> V_101 -= V_97 * V_61 ;
V_8 -> V_132 -= V_98 * V_61 ;
}
return V_19 ;
}
static int F_35 ( struct V_1 * V_2 , int * V_61 )
{
int V_19 = 0 , V_133 ;
int V_134 , V_135 , V_136 ;
int V_137 = 0 , V_138 = 0 , V_139 = 0 ;
V_133 = * V_61 ;
while ( V_133 ) {
V_134 = V_133 ;
V_135 = V_133 ;
V_136 = V_133 ;
if ( V_2 -> V_20 & V_104 ) {
if ( V_2 -> V_8 . V_105 - V_2 -> V_106 * 2 >=
V_134 )
V_138 = 1 ;
} else {
if ( V_2 -> V_8 . V_105 - V_2 -> V_106 >=
V_134 )
V_138 = 1 ;
}
if ( V_2 -> V_8 . V_108 - V_2 -> V_109 >= V_135 )
V_137 = 1 ;
if ( V_2 -> V_8 . V_131 - V_2 -> V_140 >= V_136 )
V_139 = 1 ;
if ( V_137 && V_138 && V_139 )
break;
V_133 -- ;
}
if ( ! V_133 ) {
F_3 ( V_2 -> V_6 , L_8 ) ;
return - V_7 ;
}
if ( V_133 != * V_61 ) {
F_16 ( V_2 -> V_6 , L_9 ,
* V_61 , V_133 ) ;
* V_61 = V_133 ;
}
V_19 = F_26 ( V_2 , * V_61 ) ;
if ( V_19 )
goto V_141;
V_19 = F_32 ( V_2 , * V_61 ) ;
if ( V_19 )
goto V_142;
V_19 = F_30 ( V_2 ) ;
if ( V_19 )
goto V_142;
V_19 = F_36 ( V_2 -> V_69 , * V_61 ) ;
if ( V_19 )
goto V_142;
return 0 ;
V_142:
F_19 ( V_2 , * V_61 ) ;
V_141:
F_23 ( V_2 ) ;
return V_19 ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
T_3 V_143 )
{
int V_19 = 0 ;
struct V_144 V_14 = { 0 } ;
struct V_145 * V_146 = V_2 -> V_147 ;
struct V_148 * V_149 ;
F_6 ( V_2 , & V_14 , V_150 , - 1 , - 1 ) ;
if ( V_16 )
V_14 . V_151 = F_7 ( V_16 -> V_25 ) ;
else
V_14 . V_151 = F_7 ( 0xffff ) ;
V_149 = (struct V_148 * ) V_14 . V_152 ;
V_149 -> type =
F_7 ( V_153 ) ;
V_149 -> V_143 = F_7 ( V_143 ) ;
F_20 ( & V_2 -> V_66 ) ;
V_19 = F_21 ( V_2 , & V_14 , sizeof( V_14 ) , V_26 ) ;
if ( V_19 ) {
F_3 ( V_2 -> V_6 , L_10 ,
V_19 ) ;
goto V_154;
}
if ( V_146 -> V_155 ) {
F_3 ( V_2 -> V_6 , L_11 ,
V_146 -> V_155 ) ;
V_19 = - 1 ;
}
V_154:
F_22 ( & V_2 -> V_66 ) ;
return V_19 ;
}
void F_38 ( struct V_1 * V_2 )
{
T_3 V_61 = F_39 ( V_2 -> V_69 ) ;
if ( ! V_61 )
return;
if ( F_40 ( V_2 -> V_69 ) ) {
F_37 (
V_2 , NULL ,
V_156 ) ;
F_41 ( V_2 -> V_6 , L_12 ,
V_61 ) ;
} else {
F_42 ( V_2 -> V_69 ) ;
F_19 ( V_2 , V_61 ) ;
}
F_23 ( V_2 ) ;
V_2 -> V_8 . V_9 = 0 ;
F_43 ( V_2 ) ;
}
int F_44 ( struct V_68 * V_69 , int V_61 )
{
struct V_11 * V_6 = F_45 ( V_69 ) ;
struct V_1 * V_2 = F_5 ( V_6 ) ;
if ( ! ( V_2 -> V_20 & V_157 ) ) {
F_41 ( V_6 , L_13 ) ;
return 0 ;
}
F_46 () ;
if ( ! F_47 ( V_6 ) ) {
F_41 ( V_6 , L_14 ) ;
F_48 () ;
return 0 ;
}
V_2 -> V_158 = true ;
F_48 () ;
if ( F_40 ( V_2 -> V_69 ) ) {
F_41 ( V_6 , L_15 ) ;
V_61 = 0 ;
goto V_159;
}
if ( V_61 && V_61 == V_2 -> V_8 . V_9 )
goto V_159;
F_38 ( V_2 ) ;
if ( ! V_61 )
goto V_159;
F_35 ( V_2 , & V_61 ) ;
V_159:
V_2 -> V_158 = false ;
F_49 ( & V_2 -> V_160 ) ;
return V_61 ;
}
static int F_50 ( struct V_1 * V_2 , struct V_15 * V_16 ,
void * V_161 , T_4 V_162 ,
T_5 V_163 , T_1 V_164 )
{
int V_19 = 0 ;
struct V_165 V_14 = { 0 } ;
struct V_166 * V_146 = V_2 -> V_147 ;
F_6 ( V_2 , & V_14 , V_167 , - 1 , - 1 ) ;
V_14 . V_168 = F_7 ( V_16 -> V_25 ) ;
V_14 . V_169 = F_7 ( V_16 -> V_25 ) ;
V_14 . V_170 = F_7 ( V_164 ) ;
V_14 . V_162 = V_162 ;
V_14 . V_171 = V_163 ;
memcpy ( V_14 . V_161 , V_161 , V_164 ) ;
F_20 ( & V_2 -> V_66 ) ;
V_19 = F_21 ( V_2 , & V_14 , sizeof( V_14 ) , V_26 ) ;
if ( V_19 ) {
F_3 ( V_2 -> V_6 , L_16 , V_19 ) ;
goto V_172;
}
if ( V_146 -> V_155 ) {
F_3 ( V_2 -> V_6 , L_17 ,
V_146 -> V_155 ) ;
V_19 = - 1 ;
}
V_172:
F_22 ( & V_2 -> V_66 ) ;
return V_19 ;
}
static int F_51 ( struct V_1 * V_2 , struct V_15 * V_16 ,
T_1 V_164 )
{
int V_19 = 0 ;
struct V_173 V_14 = { 0 } ;
struct V_174 * V_146 = V_2 -> V_147 ;
F_6 ( V_2 , & V_14 , V_175 , - 1 , - 1 ) ;
V_14 . V_168 = F_7 ( V_16 -> V_25 ) ;
V_14 . V_169 = F_7 ( V_16 -> V_25 ) ;
memcpy ( V_14 . V_176 , V_16 -> V_71 , V_164 ) ;
F_20 ( & V_2 -> V_66 ) ;
V_19 = F_21 ( V_2 , & V_14 , sizeof( V_14 ) , V_26 ) ;
if ( V_19 ) {
F_3 ( V_2 -> V_6 , L_18 , V_19 ) ;
goto V_177;
}
if ( V_146 -> V_155 ) {
F_3 ( V_2 -> V_6 , L_19 ,
V_146 -> V_155 ) ;
V_19 = - 1 ;
}
V_177:
F_22 ( & V_2 -> V_66 ) ;
return V_19 ;
}
static int F_52 ( struct V_1 * V_2 , struct V_15 * V_16 ,
T_1 V_164 )
{
int V_19 = 0 ;
struct V_178 V_14 = { 0 } ;
struct V_179 * V_146 = V_2 -> V_147 ;
F_6 ( V_2 , & V_14 , V_180 , - 1 , - 1 ) ;
V_14 . V_168 = F_7 ( V_16 -> V_25 ) ;
V_14 . V_169 = F_7 ( V_16 -> V_25 ) ;
memcpy ( V_14 . V_176 , V_16 -> V_71 , V_164 ) ;
F_20 ( & V_2 -> V_66 ) ;
V_19 = F_21 ( V_2 , & V_14 , sizeof( V_14 ) , V_26 ) ;
if ( V_19 ) {
F_3 ( V_2 -> V_6 , L_20 , V_19 ) ;
goto V_181;
}
if ( V_146 -> V_155 ) {
F_3 ( V_2 -> V_6 , L_21 ,
V_146 -> V_155 ) ;
V_19 = - 1 ;
}
V_181:
F_22 ( & V_2 -> V_66 ) ;
return V_19 ;
}
static int F_53 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
T_1 V_164 = sizeof( struct V_182 ) ;
struct V_182 * V_14 =
(struct V_182 * ) V_16 -> V_71 ;
if ( ! F_54 ( V_16 -> V_30 ) ||
F_55 ( ( const T_2 * ) V_14 -> V_183 , V_16 -> V_30 ) )
return F_52 ( V_2 , V_16 , V_164 ) ;
else
return F_51 ( V_2 , V_16 , V_164 ) ;
}
static int F_56 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
int V_19 = 0 ;
if ( ! ( V_16 -> V_20 & V_38 ) ) {
V_19 = F_52 (
V_2 , V_16 , sizeof( struct V_184 ) ) ;
} else {
struct V_185 V_186 ;
struct V_184 * V_187 ;
V_187 =
(struct V_184 * ) V_16 -> V_71 ;
F_20 ( & V_2 -> V_66 ) ;
memcpy ( & V_186 , & V_2 -> V_54 . V_186 ,
sizeof( V_186 ) ) ;
F_22 ( & V_2 -> V_66 ) ;
V_186 . V_188 = V_187 -> V_188 ;
if ( V_16 -> V_20 & V_41 ) {
if ( V_186 . V_60 ==
V_189 ) {
V_186 . V_60 =
V_190 ;
V_186 . V_55 = F_7 (
V_191 ) ;
V_186 . V_192 =
V_193 ;
V_186 . V_194 =
( V_195 |
V_196 ) ;
}
} else {
V_186 . V_60 = V_189 ;
V_186 . V_55 = 0 ;
V_186 . V_192 = V_197 ;
V_186 . V_194 = 0 ;
}
V_19 = F_50 ( V_2 , V_16 , & V_186 ,
V_187 -> V_198 ,
V_187 -> V_199 ,
sizeof( V_186 ) ) ;
}
return V_19 ;
}
static int F_57 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
int V_19 = 0 ;
struct V_200 * V_201 = V_16 -> V_71 ;
T_1 V_202 = F_34 ( V_201 -> V_202 ) ;
switch ( V_202 ) {
case V_203 :
V_19 = F_53 ( V_2 , V_16 ) ;
break;
case V_23 :
V_19 = F_52 (
V_2 , V_16 , sizeof( struct V_13 ) ) ;
break;
case V_204 :
V_19 = F_56 ( V_2 , V_16 ) ;
break;
default:
break;
}
return V_19 ;
}
void F_58 ( struct V_1 * V_2 )
{
T_1 V_62 = 0 , V_9 = V_2 -> V_8 . V_9 , V_3 ;
while ( 1 ) {
V_3 = F_59 ( V_2 -> V_8 . V_70 , V_9 , V_62 ) ;
if ( V_3 >= V_9 )
break;
F_60 ( V_3 , V_2 -> V_8 . V_70 ) ;
F_57 ( V_2 , & V_2 -> V_8 . V_16 [ V_3 ] ) ;
V_62 = V_3 + 1 ;
}
}
void F_61 ( struct V_1 * V_2 )
{
struct V_205 V_14 = { 0 } ;
struct V_206 * V_146 = V_2 -> V_147 ;
F_6 ( V_2 , & V_14 , V_207 , - 1 , - 1 ) ;
V_14 . V_24 = F_7 ( 0xffff ) ;
F_20 ( & V_2 -> V_66 ) ;
if ( F_21 ( V_2 , & V_14 , sizeof( V_14 ) , V_26 ) )
goto V_208;
if ( ! F_55 ( V_146 -> V_209 , V_2 -> V_16 . V_30 ) )
memcpy ( V_2 -> V_16 . V_30 , V_146 -> V_209 , V_31 ) ;
if ( F_54 ( V_2 -> V_16 . V_30 ) )
memcpy ( V_2 -> V_6 -> V_210 , V_2 -> V_16 . V_30 , V_31 ) ;
V_208:
F_22 ( & V_2 -> V_66 ) ;
}
int F_62 ( struct V_1 * V_2 , T_2 * V_29 )
{
struct V_211 V_14 = { 0 } ;
int V_19 = 0 ;
if ( ! F_63 ( V_2 ) )
return 0 ;
if ( V_2 -> V_49 < 0x10202 ) {
if ( F_54 ( V_2 -> V_16 . V_30 ) )
V_19 = - V_212 ;
goto V_213;
}
F_6 ( V_2 , & V_14 , V_214 , - 1 , - 1 ) ;
V_14 . V_44 = F_8 ( V_215 ) ;
memcpy ( V_14 . V_46 , V_29 , V_31 ) ;
V_19 = F_9 ( V_2 , & V_14 , sizeof( V_14 ) , V_26 ) ;
V_213:
if ( V_19 ) {
V_19 = - V_212 ;
F_41 ( V_2 -> V_6 , L_22 ,
V_29 ) ;
}
return V_19 ;
}
void F_38 ( struct V_1 * V_2 )
{
}
void F_58 ( struct V_1 * V_2 )
{
F_3 ( V_2 -> V_6 , L_23 ) ;
}
void F_61 ( struct V_1 * V_2 )
{
}
int F_62 ( struct V_1 * V_2 , T_2 * V_29 )
{
return 0 ;
}
