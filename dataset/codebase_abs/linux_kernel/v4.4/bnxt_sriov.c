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
V_14 . V_3 = F_7 ( V_16 -> V_24 ) ;
V_14 . V_20 = F_8 ( V_18 ) ;
V_19 = F_9 ( V_2 , & V_14 , sizeof( V_14 ) , V_25 ) ;
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
struct V_26 * V_27 )
{
struct V_1 * V_2 = F_5 ( V_6 ) ;
struct V_15 * V_16 ;
int V_19 ;
V_19 = F_1 ( V_2 , V_3 ) ;
if ( V_19 )
return V_19 ;
V_27 -> V_16 = V_3 ;
V_16 = & V_2 -> V_8 . V_16 [ V_3 ] ;
memcpy ( & V_27 -> V_28 , V_16 -> V_29 , V_30 ) ;
V_27 -> V_31 = V_16 -> V_31 ;
V_27 -> V_32 = V_16 -> V_32 ;
V_27 -> V_33 = V_16 -> V_33 ;
V_27 -> V_34 = V_16 -> V_20 & V_35 ;
V_27 -> V_36 = V_16 -> V_20 & V_21 ;
if ( ! ( V_16 -> V_20 & V_37 ) )
V_27 -> V_38 = V_39 ;
else if ( V_16 -> V_20 & V_40 )
V_27 -> V_38 = V_41 ;
else
V_27 -> V_38 = V_42 ;
return 0 ;
}
int F_11 ( struct V_11 * V_6 , int V_3 , T_2 * V_28 )
{
struct V_13 V_14 = { 0 } ;
struct V_1 * V_2 = F_5 ( V_6 ) ;
struct V_15 * V_16 ;
int V_19 ;
V_19 = F_1 ( V_2 , V_3 ) ;
if ( V_19 )
return V_19 ;
if ( F_12 ( V_28 ) ) {
F_3 ( V_6 , L_4 ) ;
return - V_7 ;
}
V_16 = & V_2 -> V_8 . V_16 [ V_3 ] ;
memcpy ( V_16 -> V_29 , V_28 , V_30 ) ;
F_6 ( V_2 , & V_14 , V_23 , - 1 , - 1 ) ;
V_14 . V_3 = F_7 ( V_16 -> V_24 ) ;
V_14 . V_20 = F_8 ( V_16 -> V_18 ) ;
V_14 . V_43 = F_8 ( V_44 ) ;
memcpy ( V_14 . V_45 , V_28 , V_30 ) ;
return F_9 ( V_2 , & V_14 , sizeof( V_14 ) , V_25 ) ;
}
int F_13 ( struct V_11 * V_6 , int V_3 , T_3 V_46 , T_2 V_34 )
{
struct V_13 V_14 = { 0 } ;
struct V_1 * V_2 = F_5 ( V_6 ) ;
struct V_15 * V_16 ;
T_3 V_47 ;
int V_19 ;
V_19 = F_1 ( V_2 , V_3 ) ;
if ( V_19 )
return V_19 ;
if ( V_46 > 4095 || V_34 )
return - V_7 ;
V_16 = & V_2 -> V_8 . V_16 [ V_3 ] ;
V_47 = V_46 ;
if ( V_47 == V_16 -> V_33 )
return 0 ;
F_6 ( V_2 , & V_14 , V_23 , - 1 , - 1 ) ;
V_14 . V_3 = F_7 ( V_16 -> V_24 ) ;
V_14 . V_20 = F_8 ( V_16 -> V_18 ) ;
V_14 . V_48 = F_7 ( V_47 ) ;
V_14 . V_43 = F_8 ( V_49 ) ;
V_19 = F_9 ( V_2 , & V_14 , sizeof( V_14 ) , V_25 ) ;
if ( ! V_19 )
V_16 -> V_33 = V_47 ;
return V_19 ;
}
int F_14 ( struct V_11 * V_6 , int V_3 , int V_32 ,
int V_31 )
{
struct V_13 V_14 = { 0 } ;
struct V_1 * V_2 = F_5 ( V_6 ) ;
struct V_15 * V_16 ;
T_1 V_50 ;
int V_19 ;
V_19 = F_1 ( V_2 , V_3 ) ;
if ( V_19 )
return V_19 ;
V_16 = & V_2 -> V_8 . V_16 [ V_3 ] ;
V_50 = F_15 ( V_2 -> V_51 . V_52 ) ;
if ( V_31 > V_50 ) {
F_16 ( V_2 -> V_6 , L_5 ,
V_31 , V_3 ) ;
return - V_7 ;
}
if ( V_32 > V_50 || V_32 > V_31 ) {
F_16 ( V_2 -> V_6 , L_6 ,
V_32 , V_3 ) ;
return - V_7 ;
}
if ( V_32 == V_16 -> V_32 && V_31 == V_16 -> V_31 )
return 0 ;
F_6 ( V_2 , & V_14 , V_23 , - 1 , - 1 ) ;
V_14 . V_3 = F_7 ( V_16 -> V_24 ) ;
V_14 . V_20 = F_8 ( V_16 -> V_18 ) ;
V_14 . V_43 = F_8 ( V_53 ) ;
V_14 . V_54 = F_8 ( V_31 ) ;
V_14 . V_43 |= F_8 ( V_55 ) ;
V_14 . V_56 = F_8 ( V_32 ) ;
V_19 = F_9 ( V_2 , & V_14 , sizeof( V_14 ) , V_25 ) ;
if ( ! V_19 ) {
V_16 -> V_32 = V_32 ;
V_16 -> V_31 = V_31 ;
}
return V_19 ;
}
int F_17 ( struct V_11 * V_6 , int V_3 , int V_57 )
{
struct V_1 * V_2 = F_5 ( V_6 ) ;
struct V_15 * V_16 ;
int V_19 ;
V_19 = F_1 ( V_2 , V_3 ) ;
if ( V_19 )
return V_19 ;
V_16 = & V_2 -> V_8 . V_16 [ V_3 ] ;
V_16 -> V_20 &= ~ ( V_40 | V_37 ) ;
switch ( V_57 ) {
case V_39 :
V_16 -> V_20 |= V_40 ;
break;
case V_42 :
V_16 -> V_20 |= V_37 ;
break;
case V_41 :
V_16 -> V_20 |= V_40 | V_37 ;
break;
default:
F_3 ( V_2 -> V_6 , L_7 ) ;
V_19 = - V_7 ;
break;
}
return V_19 ;
}
static int F_18 ( struct V_1 * V_2 , int V_58 )
{
int V_59 ;
struct V_15 * V_16 ;
for ( V_59 = 0 ; V_59 < V_58 ; V_59 ++ ) {
V_16 = & V_2 -> V_8 . V_16 [ V_59 ] ;
memset ( V_16 , 0 , sizeof( * V_16 ) ) ;
V_16 -> V_20 = V_35 | V_40 ;
}
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , int V_58 )
{
int V_59 , V_19 = 0 ;
struct V_60 * V_8 = & V_2 -> V_8 ;
struct V_61 V_14 = { 0 } ;
F_6 ( V_2 , & V_14 , V_62 , - 1 , - 1 ) ;
F_20 ( & V_2 -> V_63 ) ;
for ( V_59 = V_8 -> V_64 ; V_59 < V_8 -> V_64 + V_58 ; V_59 ++ ) {
V_14 . V_3 = F_7 ( V_59 ) ;
V_19 = F_21 ( V_2 , & V_14 , sizeof( V_14 ) ,
V_25 ) ;
if ( V_19 )
break;
}
F_22 ( & V_2 -> V_63 ) ;
return V_19 ;
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_65 * V_66 = V_2 -> V_66 ;
int V_59 ;
F_24 ( V_2 -> V_8 . V_67 ) ;
V_2 -> V_8 . V_67 = NULL ;
for ( V_59 = 0 ; V_59 < 4 ; V_59 ++ ) {
if ( V_2 -> V_8 . V_68 [ V_59 ] ) {
F_25 ( & V_66 -> V_6 , V_69 ,
V_2 -> V_8 . V_68 [ V_59 ] ,
V_2 -> V_8 . V_70 [ V_59 ] ) ;
V_2 -> V_8 . V_68 [ V_59 ] = NULL ;
}
}
F_24 ( V_2 -> V_8 . V_16 ) ;
V_2 -> V_8 . V_16 = NULL ;
}
static int F_26 ( struct V_1 * V_2 , int V_58 )
{
struct V_65 * V_66 = V_2 -> V_66 ;
T_1 V_71 , V_72 , V_59 , V_73 , V_74 = 0 ;
V_2 -> V_8 . V_16 = F_27 ( V_58 , sizeof( struct V_15 ) , V_75 ) ;
if ( ! V_2 -> V_8 . V_16 )
return - V_76 ;
F_18 ( V_2 , V_58 ) ;
V_72 = V_58 * V_77 ;
V_71 = V_72 / V_69 ;
if ( V_72 & ( V_69 - 1 ) )
V_71 ++ ;
for ( V_59 = 0 ; V_59 < V_71 ; V_59 ++ ) {
V_2 -> V_8 . V_68 [ V_59 ] =
F_28 ( & V_66 -> V_6 , V_69 ,
& V_2 -> V_8 . V_70 [ V_59 ] ,
V_75 ) ;
if ( ! V_2 -> V_8 . V_68 [ V_59 ] )
return - V_76 ;
for ( V_73 = 0 ; V_73 < V_78 && V_74 < V_58 ; V_73 ++ ) {
struct V_15 * V_16 = & V_2 -> V_8 . V_16 [ V_74 ] ;
V_16 -> V_68 = V_2 -> V_8 . V_68 [ V_59 ] +
V_73 * V_77 ;
V_16 -> V_70 =
V_2 -> V_8 . V_70 [ V_59 ] + V_73 *
V_77 ;
V_74 ++ ;
}
}
V_2 -> V_8 . V_67 = F_29 ( 16 , V_75 ) ;
if ( ! V_2 -> V_8 . V_67 )
return - V_76 ;
V_2 -> V_8 . V_79 = V_71 ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_80 V_14 = { 0 } ;
F_6 ( V_2 , & V_14 , V_81 , - 1 , - 1 ) ;
V_14 . V_82 = F_7 ( V_2 -> V_8 . V_79 ) ;
V_14 . V_83 = F_7 ( V_84 ) ;
V_14 . V_85 = F_7 ( V_77 ) ;
V_14 . V_86 = F_31 ( V_2 -> V_8 . V_70 [ 0 ] ) ;
V_14 . V_87 = F_31 ( V_2 -> V_8 . V_70 [ 1 ] ) ;
V_14 . V_88 = F_31 ( V_2 -> V_8 . V_70 [ 2 ] ) ;
V_14 . V_89 = F_31 ( V_2 -> V_8 . V_70 [ 3 ] ) ;
return F_9 ( V_2 , & V_14 , sizeof( V_14 ) , V_25 ) ;
}
static int F_32 ( struct V_1 * V_2 , int * V_58 )
{
T_1 V_19 = 0 , V_90 , V_59 ;
T_3 V_91 , V_92 , V_93 , V_94 , V_95 ;
struct V_13 V_14 = { 0 } ;
struct V_60 * V_8 = & V_2 -> V_8 ;
F_6 ( V_2 , & V_14 , V_23 , - 1 , - 1 ) ;
V_93 = F_33 ( T_3 , V_2 -> V_8 . V_96 , V_2 -> V_8 . V_97 ) ;
V_93 = ( V_93 - V_2 -> V_98 ) / * V_58 ;
V_94 = ( V_2 -> V_8 . V_97 - V_2 -> V_99 ) / * V_58 ;
if ( V_2 -> V_20 & V_100 )
V_92 = ( V_2 -> V_8 . V_101 - V_2 -> V_102 * 2 ) /
* V_58 ;
else
V_92 = ( V_2 -> V_8 . V_101 - V_2 -> V_102 ) /
* V_58 ;
V_91 = ( V_2 -> V_8 . V_103 - V_2 -> V_104 ) / * V_58 ;
V_14 . V_43 = F_8 ( V_105 |
V_106 |
V_107 |
V_108 |
V_109 |
V_110 |
V_111 |
V_112 |
V_113 ) ;
V_90 = V_2 -> V_6 -> V_90 + V_114 + V_115 + V_116 ;
V_14 . V_117 = F_7 ( V_90 ) ;
V_14 . V_90 = F_7 ( V_90 ) ;
V_14 . V_118 = F_7 ( 1 ) ;
V_14 . V_119 = F_7 ( V_93 ) ;
V_14 . V_120 = F_7 ( V_91 ) ;
V_14 . V_121 = F_7 ( V_92 ) ;
V_14 . V_122 = F_7 ( 4 ) ;
V_95 = 1 ;
V_14 . V_123 = F_7 ( V_95 ) ;
V_14 . V_99 = F_7 ( V_94 ) ;
F_20 ( & V_2 -> V_63 ) ;
for ( V_59 = 0 ; V_59 < * V_58 ; V_59 ++ ) {
V_14 . V_3 = F_7 ( V_8 -> V_64 + V_59 ) ;
V_19 = F_21 ( V_2 , & V_14 , sizeof( V_14 ) ,
V_25 ) ;
if ( V_19 )
break;
V_2 -> V_8 . V_9 = V_59 + 1 ;
V_2 -> V_8 . V_16 [ V_59 ] . V_24 = F_34 ( V_14 . V_3 ) ;
}
F_22 ( & V_2 -> V_63 ) ;
if ( ! V_19 ) {
V_2 -> V_8 . V_124 = V_2 -> V_104 ;
if ( V_2 -> V_20 & V_100 )
V_2 -> V_8 . V_125 = V_2 -> V_102 * 2 ;
else
V_2 -> V_8 . V_125 = V_2 -> V_102 ;
}
return V_19 ;
}
static int F_35 ( struct V_1 * V_2 , int * V_58 )
{
int V_19 = 0 , V_126 ;
int V_127 , V_128 , V_129 ;
int V_130 = 0 , V_131 = 0 , V_132 = 0 ;
V_126 = * V_58 ;
while ( V_126 ) {
V_127 = V_126 ;
V_128 = V_126 ;
V_129 = V_126 ;
if ( V_2 -> V_20 & V_100 ) {
if ( V_2 -> V_8 . V_101 - V_2 -> V_102 * 2 >=
V_127 )
V_131 = 1 ;
} else {
if ( V_2 -> V_8 . V_101 - V_2 -> V_102 >=
V_127 )
V_131 = 1 ;
}
if ( V_2 -> V_8 . V_103 - V_2 -> V_104 >= V_128 )
V_130 = 1 ;
if ( V_2 -> V_8 . V_133 - V_2 -> V_134 >= V_129 )
V_132 = 1 ;
if ( V_130 && V_131 && V_132 )
break;
V_126 -- ;
}
if ( ! V_126 ) {
F_3 ( V_2 -> V_6 , L_8 ) ;
return - V_7 ;
}
if ( V_126 != * V_58 ) {
F_16 ( V_2 -> V_6 , L_9 ,
* V_58 , V_126 ) ;
* V_58 = V_126 ;
}
V_19 = F_26 ( V_2 , * V_58 ) ;
if ( V_19 )
goto V_135;
V_19 = F_32 ( V_2 , V_58 ) ;
if ( V_19 )
goto V_136;
V_19 = F_30 ( V_2 ) ;
if ( V_19 )
goto V_136;
V_19 = F_36 ( V_2 -> V_66 , * V_58 ) ;
if ( V_19 )
goto V_136;
return 0 ;
V_136:
F_19 ( V_2 , * V_58 ) ;
V_135:
F_23 ( V_2 ) ;
return V_19 ;
}
void F_37 ( struct V_1 * V_2 )
{
T_3 V_58 = F_38 ( V_2 -> V_66 ) ;
if ( ! V_58 )
return;
if ( F_39 ( V_2 -> V_66 ) ) {
F_40 ( V_2 -> V_6 , L_10 ,
V_58 ) ;
} else {
F_41 ( V_2 -> V_66 ) ;
F_19 ( V_2 , V_58 ) ;
}
F_23 ( V_2 ) ;
V_2 -> V_8 . V_9 = 0 ;
V_2 -> V_8 . V_125 = V_2 -> V_8 . V_101 ;
V_2 -> V_8 . V_124 = V_2 -> V_8 . V_103 ;
}
int F_42 ( struct V_65 * V_66 , int V_58 )
{
struct V_11 * V_6 = F_43 ( V_66 ) ;
struct V_1 * V_2 = F_5 ( V_6 ) ;
if ( ! ( V_2 -> V_20 & V_137 ) ) {
F_40 ( V_6 , L_11 ) ;
return 0 ;
}
F_44 () ;
if ( ! F_45 ( V_6 ) ) {
F_40 ( V_6 , L_12 ) ;
F_46 () ;
return 0 ;
}
V_2 -> V_138 = true ;
F_46 () ;
if ( F_39 ( V_2 -> V_66 ) ) {
F_40 ( V_6 , L_13 ) ;
V_58 = 0 ;
goto V_139;
}
if ( V_58 && V_58 == V_2 -> V_8 . V_9 )
goto V_139;
F_37 ( V_2 ) ;
if ( ! V_58 )
goto V_139;
F_35 ( V_2 , & V_58 ) ;
V_139:
V_2 -> V_138 = false ;
F_47 ( & V_2 -> V_140 ) ;
return V_58 ;
}
static int F_48 ( struct V_1 * V_2 , struct V_15 * V_16 ,
void * V_141 , T_4 V_142 ,
T_5 V_143 , T_1 V_144 )
{
int V_19 = 0 ;
struct V_145 V_14 = { 0 } ;
struct V_146 * V_147 = V_2 -> V_148 ;
F_6 ( V_2 , & V_14 , V_149 , - 1 , - 1 ) ;
V_14 . V_150 = F_7 ( V_16 -> V_24 ) ;
V_14 . V_151 = F_7 ( V_144 ) ;
V_14 . V_142 = V_142 ;
V_14 . V_152 = V_143 ;
memcpy ( V_14 . V_141 , V_141 , V_144 ) ;
F_20 ( & V_2 -> V_63 ) ;
V_19 = F_21 ( V_2 , & V_14 , sizeof( V_14 ) , V_25 ) ;
if ( V_19 ) {
F_3 ( V_2 -> V_6 , L_14 , V_19 ) ;
goto V_153;
}
if ( V_147 -> V_154 ) {
F_3 ( V_2 -> V_6 , L_15 ,
V_147 -> V_154 ) ;
V_19 = - 1 ;
}
V_153:
F_22 ( & V_2 -> V_63 ) ;
return V_19 ;
}
static int F_49 ( struct V_1 * V_2 , struct V_15 * V_16 ,
T_1 V_144 )
{
int V_19 = 0 ;
struct V_155 V_14 = { 0 } ;
struct V_156 * V_147 = V_2 -> V_148 ;
F_6 ( V_2 , & V_14 , V_157 , - 1 , - 1 ) ;
V_14 . V_150 = F_7 ( V_16 -> V_24 ) ;
memcpy ( V_14 . V_158 , V_16 -> V_68 , V_144 ) ;
F_20 ( & V_2 -> V_63 ) ;
V_19 = F_21 ( V_2 , & V_14 , sizeof( V_14 ) , V_25 ) ;
if ( V_19 ) {
F_3 ( V_2 -> V_6 , L_16 , V_19 ) ;
goto V_159;
}
if ( V_147 -> V_154 ) {
F_3 ( V_2 -> V_6 , L_17 ,
V_147 -> V_154 ) ;
V_19 = - 1 ;
}
V_159:
F_22 ( & V_2 -> V_63 ) ;
return V_19 ;
}
static int F_50 ( struct V_1 * V_2 , struct V_15 * V_16 ,
T_1 V_144 )
{
int V_19 = 0 ;
struct V_160 V_14 = { 0 } ;
struct V_161 * V_147 = V_2 -> V_148 ;
F_6 ( V_2 , & V_14 , V_162 , - 1 , - 1 ) ;
V_14 . V_150 = F_7 ( V_16 -> V_24 ) ;
memcpy ( V_14 . V_158 , V_16 -> V_68 , V_144 ) ;
F_20 ( & V_2 -> V_63 ) ;
V_19 = F_21 ( V_2 , & V_14 , sizeof( V_14 ) , V_25 ) ;
if ( V_19 ) {
F_3 ( V_2 -> V_6 , L_18 , V_19 ) ;
goto V_163;
}
if ( V_147 -> V_154 ) {
F_3 ( V_2 -> V_6 , L_19 ,
V_147 -> V_154 ) ;
V_19 = - 1 ;
}
V_163:
F_22 ( & V_2 -> V_63 ) ;
return V_19 ;
}
static int F_51 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
T_1 V_144 = sizeof( struct V_164 ) ;
struct V_164 * V_14 =
(struct V_164 * ) V_16 -> V_68 ;
if ( ! F_52 ( V_16 -> V_29 ) ||
F_53 ( ( const T_2 * ) V_14 -> V_165 , V_16 -> V_29 ) )
return F_50 ( V_2 , V_16 , V_144 ) ;
else
return F_49 ( V_2 , V_16 , V_144 ) ;
}
static int F_54 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
int V_19 = 0 ;
if ( ! ( V_16 -> V_20 & V_37 ) ) {
V_19 = F_50 (
V_2 , V_16 , sizeof( struct V_166 ) ) ;
} else {
struct V_167 V_168 ;
struct V_166 * V_169 ;
V_169 =
(struct V_166 * ) V_16 -> V_68 ;
F_20 ( & V_2 -> V_63 ) ;
memcpy ( & V_168 , & V_2 -> V_51 . V_168 ,
sizeof( V_168 ) ) ;
F_22 ( & V_2 -> V_63 ) ;
V_168 . V_170 = V_169 -> V_170 ;
if ( V_16 -> V_20 & V_40 ) {
if ( V_168 . V_57 ==
V_171 ) {
V_168 . V_57 =
V_172 ;
if ( V_168 . V_173 )
V_168 . V_52 =
V_168 . V_173 ;
else
V_168 . V_52 =
V_168 . V_174 ;
V_168 . V_175 =
V_176 ;
V_168 . V_177 =
( V_178 |
V_179 ) ;
}
} else {
V_168 . V_57 = V_171 ;
V_168 . V_52 = 0 ;
V_168 . V_175 = V_180 ;
V_168 . V_177 = 0 ;
}
V_19 = F_48 ( V_2 , V_16 , & V_168 ,
V_169 -> V_181 ,
V_169 -> V_182 ,
sizeof( V_168 ) ) ;
}
return V_19 ;
}
static int F_55 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
int V_19 = 0 ;
struct V_183 * V_184 = V_16 -> V_68 ;
T_1 V_185 = F_56 ( V_184 -> V_186 ) & 0xffff ;
switch ( V_185 ) {
case V_187 :
V_19 = F_51 ( V_2 , V_16 ) ;
break;
case V_23 :
V_19 = F_50 (
V_2 , V_16 , sizeof( struct V_13 ) ) ;
break;
case V_188 :
V_19 = F_54 ( V_2 , V_16 ) ;
break;
default:
break;
}
return V_19 ;
}
void F_57 ( struct V_1 * V_2 )
{
T_1 V_59 = 0 , V_9 = V_2 -> V_8 . V_9 , V_3 ;
while ( 1 ) {
V_3 = F_58 ( V_2 -> V_8 . V_67 , V_9 , V_59 ) ;
if ( V_3 >= V_9 )
break;
F_59 ( V_3 , V_2 -> V_8 . V_67 ) ;
F_55 ( V_2 , & V_2 -> V_8 . V_16 [ V_3 ] ) ;
V_59 = V_3 + 1 ;
}
}
void F_60 ( struct V_1 * V_2 )
{
struct V_189 V_14 = { 0 } ;
struct V_190 * V_147 = V_2 -> V_148 ;
F_6 ( V_2 , & V_14 , V_191 , - 1 , - 1 ) ;
V_14 . V_192 = F_7 ( 0xffff ) ;
F_20 ( & V_2 -> V_63 ) ;
if ( F_21 ( V_2 , & V_14 , sizeof( V_14 ) , V_25 ) )
goto V_193;
if ( ! F_52 ( V_147 -> V_194 ) )
goto V_193;
if ( ! F_53 ( V_147 -> V_194 , V_2 -> V_16 . V_29 ) )
memcpy ( V_2 -> V_16 . V_29 , V_147 -> V_194 , V_30 ) ;
memcpy ( V_2 -> V_6 -> V_195 , V_2 -> V_16 . V_29 , V_30 ) ;
V_193:
F_22 ( & V_2 -> V_63 ) ;
}
void F_37 ( struct V_1 * V_2 )
{
}
void F_57 ( struct V_1 * V_2 )
{
F_3 ( V_2 -> V_6 , L_20 ) ;
}
void F_60 ( struct V_1 * V_2 )
{
}
