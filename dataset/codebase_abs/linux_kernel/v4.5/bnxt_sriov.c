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
V_14 . V_49 = F_7 ( V_48 ) ;
V_14 . V_44 = F_8 ( V_50 ) ;
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
T_1 V_51 ;
int V_19 ;
V_19 = F_1 ( V_2 , V_3 ) ;
if ( V_19 )
return V_19 ;
V_16 = & V_2 -> V_8 . V_16 [ V_3 ] ;
V_51 = F_15 ( V_2 -> V_52 . V_53 ) ;
if ( V_32 > V_51 ) {
F_16 ( V_2 -> V_6 , L_5 ,
V_32 , V_3 ) ;
return - V_7 ;
}
if ( V_33 > V_51 || V_33 > V_32 ) {
F_16 ( V_2 -> V_6 , L_6 ,
V_33 , V_3 ) ;
return - V_7 ;
}
if ( V_33 == V_16 -> V_33 && V_32 == V_16 -> V_32 )
return 0 ;
F_6 ( V_2 , & V_14 , V_23 , - 1 , - 1 ) ;
V_14 . V_24 = F_7 ( V_16 -> V_25 ) ;
V_14 . V_20 = F_8 ( V_16 -> V_18 ) ;
V_14 . V_44 = F_8 ( V_54 ) ;
V_14 . V_55 = F_8 ( V_32 ) ;
V_14 . V_44 |= F_8 ( V_56 ) ;
V_14 . V_57 = F_8 ( V_33 ) ;
V_19 = F_9 ( V_2 , & V_14 , sizeof( V_14 ) , V_26 ) ;
if ( ! V_19 ) {
V_16 -> V_33 = V_33 ;
V_16 -> V_32 = V_32 ;
}
return V_19 ;
}
int F_17 ( struct V_11 * V_6 , int V_3 , int V_58 )
{
struct V_1 * V_2 = F_5 ( V_6 ) ;
struct V_15 * V_16 ;
int V_19 ;
V_19 = F_1 ( V_2 , V_3 ) ;
if ( V_19 )
return V_19 ;
V_16 = & V_2 -> V_8 . V_16 [ V_3 ] ;
V_16 -> V_20 &= ~ ( V_41 | V_38 ) ;
switch ( V_58 ) {
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
static int F_18 ( struct V_1 * V_2 , int V_59 )
{
int V_60 ;
struct V_15 * V_16 ;
for ( V_60 = 0 ; V_60 < V_59 ; V_60 ++ ) {
V_16 = & V_2 -> V_8 . V_16 [ V_60 ] ;
memset ( V_16 , 0 , sizeof( * V_16 ) ) ;
V_16 -> V_20 = V_36 | V_41 ;
}
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , int V_59 )
{
int V_60 , V_19 = 0 ;
struct V_61 * V_8 = & V_2 -> V_8 ;
struct V_62 V_14 = { 0 } ;
F_6 ( V_2 , & V_14 , V_63 , - 1 , - 1 ) ;
F_20 ( & V_2 -> V_64 ) ;
for ( V_60 = V_8 -> V_65 ; V_60 < V_8 -> V_65 + V_59 ; V_60 ++ ) {
V_14 . V_3 = F_7 ( V_60 ) ;
V_19 = F_21 ( V_2 , & V_14 , sizeof( V_14 ) ,
V_26 ) ;
if ( V_19 )
break;
}
F_22 ( & V_2 -> V_64 ) ;
return V_19 ;
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_66 * V_67 = V_2 -> V_67 ;
int V_60 ;
F_24 ( V_2 -> V_8 . V_68 ) ;
V_2 -> V_8 . V_68 = NULL ;
for ( V_60 = 0 ; V_60 < 4 ; V_60 ++ ) {
if ( V_2 -> V_8 . V_69 [ V_60 ] ) {
F_25 ( & V_67 -> V_6 , V_70 ,
V_2 -> V_8 . V_69 [ V_60 ] ,
V_2 -> V_8 . V_71 [ V_60 ] ) ;
V_2 -> V_8 . V_69 [ V_60 ] = NULL ;
}
}
F_24 ( V_2 -> V_8 . V_16 ) ;
V_2 -> V_8 . V_16 = NULL ;
}
static int F_26 ( struct V_1 * V_2 , int V_59 )
{
struct V_66 * V_67 = V_2 -> V_67 ;
T_1 V_72 , V_73 , V_60 , V_74 , V_75 = 0 ;
V_2 -> V_8 . V_16 = F_27 ( V_59 , sizeof( struct V_15 ) , V_76 ) ;
if ( ! V_2 -> V_8 . V_16 )
return - V_77 ;
F_18 ( V_2 , V_59 ) ;
V_73 = V_59 * V_78 ;
V_72 = V_73 / V_70 ;
if ( V_73 & ( V_70 - 1 ) )
V_72 ++ ;
for ( V_60 = 0 ; V_60 < V_72 ; V_60 ++ ) {
V_2 -> V_8 . V_69 [ V_60 ] =
F_28 ( & V_67 -> V_6 , V_70 ,
& V_2 -> V_8 . V_71 [ V_60 ] ,
V_76 ) ;
if ( ! V_2 -> V_8 . V_69 [ V_60 ] )
return - V_77 ;
for ( V_74 = 0 ; V_74 < V_79 && V_75 < V_59 ; V_74 ++ ) {
struct V_15 * V_16 = & V_2 -> V_8 . V_16 [ V_75 ] ;
V_16 -> V_69 = V_2 -> V_8 . V_69 [ V_60 ] +
V_74 * V_78 ;
V_16 -> V_71 =
V_2 -> V_8 . V_71 [ V_60 ] + V_74 *
V_78 ;
V_75 ++ ;
}
}
V_2 -> V_8 . V_68 = F_29 ( 16 , V_76 ) ;
if ( ! V_2 -> V_8 . V_68 )
return - V_77 ;
V_2 -> V_8 . V_80 = V_72 ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_81 V_14 = { 0 } ;
F_6 ( V_2 , & V_14 , V_82 , - 1 , - 1 ) ;
V_14 . V_83 = F_7 ( V_2 -> V_8 . V_80 ) ;
V_14 . V_84 = F_7 ( V_85 ) ;
V_14 . V_86 = F_7 ( V_78 ) ;
V_14 . V_87 = F_31 ( V_2 -> V_8 . V_71 [ 0 ] ) ;
V_14 . V_88 = F_31 ( V_2 -> V_8 . V_71 [ 1 ] ) ;
V_14 . V_89 = F_31 ( V_2 -> V_8 . V_71 [ 2 ] ) ;
V_14 . V_90 = F_31 ( V_2 -> V_8 . V_71 [ 3 ] ) ;
return F_9 ( V_2 , & V_14 , sizeof( V_14 ) , V_26 ) ;
}
static int F_32 ( struct V_1 * V_2 , int V_59 )
{
T_1 V_19 = 0 , V_91 , V_60 ;
T_3 V_92 , V_93 , V_94 , V_95 , V_96 ;
T_3 V_97 ;
struct V_13 V_14 = { 0 } ;
struct V_61 * V_8 = & V_2 -> V_8 ;
F_6 ( V_2 , & V_14 , V_23 , - 1 , - 1 ) ;
V_94 = F_33 ( T_3 , V_8 -> V_98 , V_8 -> V_99 ) ;
V_94 = ( V_94 - V_2 -> V_100 ) / V_59 ;
V_95 = ( V_8 -> V_99 - V_2 -> V_101 ) / V_59 ;
if ( V_2 -> V_20 & V_102 )
V_93 = ( V_8 -> V_103 - V_2 -> V_104 * 2 ) /
V_59 ;
else
V_93 = ( V_8 -> V_103 - V_2 -> V_104 ) / V_59 ;
V_97 = ( V_2 -> V_8 . V_105 - V_2 -> V_104 ) / V_59 ;
V_92 = ( V_8 -> V_106 - V_2 -> V_107 ) / V_59 ;
V_14 . V_44 = F_8 ( V_108 |
V_109 |
V_110 |
V_111 |
V_112 |
V_113 |
V_114 |
V_115 |
V_116 |
V_117 ) ;
V_91 = V_2 -> V_6 -> V_91 + V_118 + V_119 + V_120 ;
V_14 . V_121 = F_7 ( V_91 ) ;
V_14 . V_91 = F_7 ( V_91 ) ;
V_14 . V_122 = F_7 ( 1 ) ;
V_14 . V_123 = F_7 ( V_94 ) ;
V_14 . V_124 = F_7 ( V_92 ) ;
V_14 . V_125 = F_7 ( V_93 ) ;
V_14 . V_126 = F_7 ( V_97 ) ;
V_14 . V_127 = F_7 ( 4 ) ;
V_96 = 1 ;
V_14 . V_128 = F_7 ( V_96 ) ;
V_14 . V_101 = F_7 ( V_95 ) ;
F_20 ( & V_2 -> V_64 ) ;
for ( V_60 = 0 ; V_60 < V_59 ; V_60 ++ ) {
V_14 . V_24 = F_7 ( V_8 -> V_65 + V_60 ) ;
V_19 = F_21 ( V_2 , & V_14 , sizeof( V_14 ) ,
V_26 ) ;
if ( V_19 )
break;
V_8 -> V_9 = V_60 + 1 ;
V_8 -> V_16 [ V_60 ] . V_25 = F_34 ( V_14 . V_24 ) ;
}
F_22 ( & V_2 -> V_64 ) ;
if ( ! V_19 ) {
V_8 -> V_106 -= V_92 * V_59 ;
V_8 -> V_103 -= V_93 * V_59 ;
V_8 -> V_105 -= V_97 * V_59 ;
V_8 -> V_98 -= V_94 * V_59 ;
V_8 -> V_129 -= V_59 ;
V_8 -> V_99 -= V_95 * V_59 ;
V_8 -> V_130 -= V_96 * V_59 ;
}
return V_19 ;
}
static int F_35 ( struct V_1 * V_2 , int * V_59 )
{
int V_19 = 0 , V_131 ;
int V_132 , V_133 , V_134 ;
int V_135 = 0 , V_136 = 0 , V_137 = 0 ;
V_131 = * V_59 ;
while ( V_131 ) {
V_132 = V_131 ;
V_133 = V_131 ;
V_134 = V_131 ;
if ( V_2 -> V_20 & V_102 ) {
if ( V_2 -> V_8 . V_103 - V_2 -> V_104 * 2 >=
V_132 )
V_136 = 1 ;
} else {
if ( V_2 -> V_8 . V_103 - V_2 -> V_104 >=
V_132 )
V_136 = 1 ;
}
if ( V_2 -> V_8 . V_106 - V_2 -> V_107 >= V_133 )
V_135 = 1 ;
if ( V_2 -> V_8 . V_129 - V_2 -> V_138 >= V_134 )
V_137 = 1 ;
if ( V_135 && V_136 && V_137 )
break;
V_131 -- ;
}
if ( ! V_131 ) {
F_3 ( V_2 -> V_6 , L_8 ) ;
return - V_7 ;
}
if ( V_131 != * V_59 ) {
F_16 ( V_2 -> V_6 , L_9 ,
* V_59 , V_131 ) ;
* V_59 = V_131 ;
}
V_19 = F_26 ( V_2 , * V_59 ) ;
if ( V_19 )
goto V_139;
V_19 = F_32 ( V_2 , * V_59 ) ;
if ( V_19 )
goto V_140;
V_19 = F_30 ( V_2 ) ;
if ( V_19 )
goto V_140;
V_19 = F_36 ( V_2 -> V_67 , * V_59 ) ;
if ( V_19 )
goto V_140;
return 0 ;
V_140:
F_19 ( V_2 , * V_59 ) ;
V_139:
F_23 ( V_2 ) ;
return V_19 ;
}
void F_37 ( struct V_1 * V_2 )
{
T_3 V_59 = F_38 ( V_2 -> V_67 ) ;
if ( ! V_59 )
return;
if ( F_39 ( V_2 -> V_67 ) ) {
F_40 ( V_2 -> V_6 , L_10 ,
V_59 ) ;
} else {
F_41 ( V_2 -> V_67 ) ;
F_19 ( V_2 , V_59 ) ;
}
F_23 ( V_2 ) ;
V_2 -> V_8 . V_9 = 0 ;
F_42 ( V_2 ) ;
}
int F_43 ( struct V_66 * V_67 , int V_59 )
{
struct V_11 * V_6 = F_44 ( V_67 ) ;
struct V_1 * V_2 = F_5 ( V_6 ) ;
if ( ! ( V_2 -> V_20 & V_141 ) ) {
F_40 ( V_6 , L_11 ) ;
return 0 ;
}
F_45 () ;
if ( ! F_46 ( V_6 ) ) {
F_40 ( V_6 , L_12 ) ;
F_47 () ;
return 0 ;
}
V_2 -> V_142 = true ;
F_47 () ;
if ( F_39 ( V_2 -> V_67 ) ) {
F_40 ( V_6 , L_13 ) ;
V_59 = 0 ;
goto V_143;
}
if ( V_59 && V_59 == V_2 -> V_8 . V_9 )
goto V_143;
F_37 ( V_2 ) ;
if ( ! V_59 )
goto V_143;
F_35 ( V_2 , & V_59 ) ;
V_143:
V_2 -> V_142 = false ;
F_48 ( & V_2 -> V_144 ) ;
return V_59 ;
}
static int F_49 ( struct V_1 * V_2 , struct V_15 * V_16 ,
void * V_145 , T_4 V_146 ,
T_5 V_147 , T_1 V_148 )
{
int V_19 = 0 ;
struct V_149 V_14 = { 0 } ;
struct V_150 * V_151 = V_2 -> V_152 ;
F_6 ( V_2 , & V_14 , V_153 , - 1 , - 1 ) ;
V_14 . V_154 = F_7 ( V_16 -> V_25 ) ;
V_14 . V_155 = F_7 ( V_16 -> V_25 ) ;
V_14 . V_156 = F_7 ( V_148 ) ;
V_14 . V_146 = V_146 ;
V_14 . V_157 = V_147 ;
memcpy ( V_14 . V_145 , V_145 , V_148 ) ;
F_20 ( & V_2 -> V_64 ) ;
V_19 = F_21 ( V_2 , & V_14 , sizeof( V_14 ) , V_26 ) ;
if ( V_19 ) {
F_3 ( V_2 -> V_6 , L_14 , V_19 ) ;
goto V_158;
}
if ( V_151 -> V_159 ) {
F_3 ( V_2 -> V_6 , L_15 ,
V_151 -> V_159 ) ;
V_19 = - 1 ;
}
V_158:
F_22 ( & V_2 -> V_64 ) ;
return V_19 ;
}
static int F_50 ( struct V_1 * V_2 , struct V_15 * V_16 ,
T_1 V_148 )
{
int V_19 = 0 ;
struct V_160 V_14 = { 0 } ;
struct V_161 * V_151 = V_2 -> V_152 ;
F_6 ( V_2 , & V_14 , V_162 , - 1 , - 1 ) ;
V_14 . V_154 = F_7 ( V_16 -> V_25 ) ;
V_14 . V_155 = F_7 ( V_16 -> V_25 ) ;
memcpy ( V_14 . V_163 , V_16 -> V_69 , V_148 ) ;
F_20 ( & V_2 -> V_64 ) ;
V_19 = F_21 ( V_2 , & V_14 , sizeof( V_14 ) , V_26 ) ;
if ( V_19 ) {
F_3 ( V_2 -> V_6 , L_16 , V_19 ) ;
goto V_164;
}
if ( V_151 -> V_159 ) {
F_3 ( V_2 -> V_6 , L_17 ,
V_151 -> V_159 ) ;
V_19 = - 1 ;
}
V_164:
F_22 ( & V_2 -> V_64 ) ;
return V_19 ;
}
static int F_51 ( struct V_1 * V_2 , struct V_15 * V_16 ,
T_1 V_148 )
{
int V_19 = 0 ;
struct V_165 V_14 = { 0 } ;
struct V_166 * V_151 = V_2 -> V_152 ;
F_6 ( V_2 , & V_14 , V_167 , - 1 , - 1 ) ;
V_14 . V_154 = F_7 ( V_16 -> V_25 ) ;
V_14 . V_155 = F_7 ( V_16 -> V_25 ) ;
memcpy ( V_14 . V_163 , V_16 -> V_69 , V_148 ) ;
F_20 ( & V_2 -> V_64 ) ;
V_19 = F_21 ( V_2 , & V_14 , sizeof( V_14 ) , V_26 ) ;
if ( V_19 ) {
F_3 ( V_2 -> V_6 , L_18 , V_19 ) ;
goto V_168;
}
if ( V_151 -> V_159 ) {
F_3 ( V_2 -> V_6 , L_19 ,
V_151 -> V_159 ) ;
V_19 = - 1 ;
}
V_168:
F_22 ( & V_2 -> V_64 ) ;
return V_19 ;
}
static int F_52 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
T_1 V_148 = sizeof( struct V_169 ) ;
struct V_169 * V_14 =
(struct V_169 * ) V_16 -> V_69 ;
if ( ! F_53 ( V_16 -> V_30 ) ||
F_54 ( ( const T_2 * ) V_14 -> V_170 , V_16 -> V_30 ) )
return F_51 ( V_2 , V_16 , V_148 ) ;
else
return F_50 ( V_2 , V_16 , V_148 ) ;
}
static int F_55 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
int V_19 = 0 ;
if ( ! ( V_16 -> V_20 & V_38 ) ) {
V_19 = F_51 (
V_2 , V_16 , sizeof( struct V_171 ) ) ;
} else {
struct V_172 V_173 ;
struct V_171 * V_174 ;
V_174 =
(struct V_171 * ) V_16 -> V_69 ;
F_20 ( & V_2 -> V_64 ) ;
memcpy ( & V_173 , & V_2 -> V_52 . V_173 ,
sizeof( V_173 ) ) ;
F_22 ( & V_2 -> V_64 ) ;
V_173 . V_175 = V_174 -> V_175 ;
if ( V_16 -> V_20 & V_41 ) {
if ( V_173 . V_58 ==
V_176 ) {
V_173 . V_58 =
V_177 ;
if ( V_173 . V_178 )
V_173 . V_53 =
V_173 . V_178 ;
else
V_173 . V_53 =
V_173 . V_179 ;
V_173 . V_180 =
V_181 ;
V_173 . V_182 =
( V_183 |
V_184 ) ;
}
} else {
V_173 . V_58 = V_176 ;
V_173 . V_53 = 0 ;
V_173 . V_180 = V_185 ;
V_173 . V_182 = 0 ;
}
V_19 = F_49 ( V_2 , V_16 , & V_173 ,
V_174 -> V_186 ,
V_174 -> V_187 ,
sizeof( V_173 ) ) ;
}
return V_19 ;
}
static int F_56 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
int V_19 = 0 ;
struct V_188 * V_189 = V_16 -> V_69 ;
T_1 V_190 = F_57 ( V_189 -> V_191 ) & 0xffff ;
switch ( V_190 ) {
case V_192 :
V_19 = F_52 ( V_2 , V_16 ) ;
break;
case V_23 :
V_19 = F_51 (
V_2 , V_16 , sizeof( struct V_13 ) ) ;
break;
case V_193 :
V_19 = F_55 ( V_2 , V_16 ) ;
break;
default:
break;
}
return V_19 ;
}
void F_58 ( struct V_1 * V_2 )
{
T_1 V_60 = 0 , V_9 = V_2 -> V_8 . V_9 , V_3 ;
while ( 1 ) {
V_3 = F_59 ( V_2 -> V_8 . V_68 , V_9 , V_60 ) ;
if ( V_3 >= V_9 )
break;
F_60 ( V_3 , V_2 -> V_8 . V_68 ) ;
F_56 ( V_2 , & V_2 -> V_8 . V_16 [ V_3 ] ) ;
V_60 = V_3 + 1 ;
}
}
void F_61 ( struct V_1 * V_2 )
{
struct V_194 V_14 = { 0 } ;
struct V_195 * V_151 = V_2 -> V_152 ;
F_6 ( V_2 , & V_14 , V_196 , - 1 , - 1 ) ;
V_14 . V_24 = F_7 ( 0xffff ) ;
F_20 ( & V_2 -> V_64 ) ;
if ( F_21 ( V_2 , & V_14 , sizeof( V_14 ) , V_26 ) )
goto V_197;
if ( ! F_53 ( V_151 -> V_198 ) )
goto V_197;
if ( ! F_54 ( V_151 -> V_198 , V_2 -> V_16 . V_30 ) )
memcpy ( V_2 -> V_16 . V_30 , V_151 -> V_198 , V_31 ) ;
memcpy ( V_2 -> V_6 -> V_199 , V_2 -> V_16 . V_30 , V_31 ) ;
V_197:
F_22 ( & V_2 -> V_64 ) ;
}
void F_37 ( struct V_1 * V_2 )
{
}
void F_58 ( struct V_1 * V_2 )
{
F_3 ( V_2 -> V_6 , L_20 ) ;
}
void F_61 ( struct V_1 * V_2 )
{
}
