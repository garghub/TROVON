T_1 F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 ) ? 1 : 0 ;
}
int F_3 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
V_4 -> V_5 =
V_6 |
V_7 |
V_8 ;
V_4 -> V_9 = - 1 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , void T_2 * V_10 )
{
struct V_11 V_12 = {
. V_12 = V_13 ,
. V_14 = V_15 ,
} ;
struct V_16 V_17 [ V_15 ] ;
T_1 T_2 * V_18 ;
T_1 V_19 ;
int V_20 ;
F_5 ( V_15 * sizeof( T_1 ) > sizeof( V_21 ) ) ;
for ( V_20 = 0 ; V_20 < V_15 ; ++ V_20 ) {
V_17 [ V_20 ] . V_22 = ( T_1 ) ( V_2 -> V_23 >> ( 32 * V_20 ) ) ;
V_17 [ V_20 ] . V_24 = ( T_1 ) ( V_2 -> V_25 >> ( 32 * V_20 ) ) ;
V_17 [ V_20 ] . V_26 = ( T_1 ) ( V_2 -> V_17 >> ( 32 * V_20 ) ) ;
V_17 [ V_20 ] . V_27 =
( T_1 ) ( V_28 >> ( 32 * V_20 ) ) ;
}
V_18 = V_10 + F_6 ( struct V_11 , V_14 ) ;
if ( F_7 ( V_19 , V_18 ) )
return - V_29 ;
if ( V_19 > V_15 )
V_19 = V_15 ;
if ( F_8 ( V_10 , & V_12 , sizeof( V_12 ) ) )
return - V_29 ;
V_10 += sizeof( V_12 ) ;
if ( F_8 ( V_10 , V_17 , V_19 * sizeof( * V_17 ) ) )
return - V_29 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , void T_2 * V_10 )
{
struct V_30 V_12 ;
struct V_31 V_17 [ V_15 ] ;
V_21 V_32 = 0 , V_33 = 0 ;
int V_20 , V_34 = 0 ;
if ( F_10 ( & V_12 , V_10 , sizeof( V_12 ) ) )
return - V_29 ;
V_10 += sizeof( V_12 ) ;
if ( V_12 . V_14 != V_15 )
return - V_35 ;
if ( F_10 ( V_17 , V_10 , sizeof( V_17 ) ) )
return - V_29 ;
for ( V_20 = 0 ; V_20 < V_15 ; ++ V_20 ) {
V_33 |= ( V_21 ) V_17 [ V_20 ] . V_33 << ( 32 * V_20 ) ;
V_32 |= ( V_21 ) V_17 [ V_20 ] . V_24 << ( 32 * V_20 ) ;
}
if ( V_33 & ~ V_36 )
return - V_35 ;
if ( V_33 & ~ V_2 -> V_23 ) {
V_33 &= V_2 -> V_23 ;
V_34 |= V_37 ;
}
V_2 -> V_25 &= ~ V_33 ;
V_2 -> V_25 |= V_32 & V_33 ;
F_11 ( V_2 ) ;
if ( ( V_2 -> V_25 ^ V_2 -> V_17 ) & V_33 )
V_34 |= V_38 ;
return V_34 ;
}
static int F_12 ( struct V_1 * V_2 , int V_39 )
{
const struct V_40 * V_41 = V_2 -> V_40 ;
if ( V_39 == V_42 )
return F_13 ( V_43 ) ;
if ( V_41 -> V_44 && V_41 -> V_45 )
return V_41 -> V_44 ( V_2 , V_39 ) ;
else
return - V_46 ;
}
static void F_14 ( struct V_1 * V_2 ,
T_1 V_47 , T_3 * V_48 )
{
const struct V_40 * V_41 = V_2 -> V_40 ;
if ( V_47 == V_42 )
memcpy ( V_48 , V_43 ,
sizeof( V_43 ) ) ;
else
V_41 -> V_45 ( V_2 , V_47 , V_48 ) ;
}
static V_21 F_15 ( T_1 V_49 )
{
switch ( V_49 ) {
case V_50 :
case V_51 :
return V_52 | V_53 ;
case V_54 :
case V_55 :
return V_56 ;
case V_57 :
case V_58 :
return V_59 ;
case V_60 :
case V_61 :
return V_62 ;
case V_63 :
case V_64 :
return V_65 ;
case V_66 :
case V_67 :
return V_68 ;
case V_69 :
case V_70 :
return V_71 ;
default:
F_16 () ;
}
}
static int F_17 ( struct V_1 * V_2 ,
char T_2 * V_10 , T_1 V_72 )
{
V_21 V_73 = F_15 ( V_72 ) ;
struct V_74 V_75 = {
. V_12 = V_72 ,
. V_48 = ! ! ( V_2 -> V_17 & V_73 ) ,
} ;
if ( F_8 ( V_10 , & V_75 , sizeof( V_75 ) ) )
return - V_29 ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
void T_2 * V_10 , T_1 V_72 )
{
struct V_74 V_75 ;
V_21 V_73 ;
if ( F_10 ( & V_75 , V_10 , sizeof( V_75 ) ) )
return - V_29 ;
V_73 = F_15 ( V_72 ) ;
V_73 &= V_2 -> V_23 ;
if ( ! V_73 )
return - V_46 ;
if ( V_75 . V_48 )
V_2 -> V_25 |= V_73 ;
else
V_2 -> V_25 &= ~ V_73 ;
F_11 ( V_2 ) ;
return 0 ;
}
static T_1 F_19 ( struct V_1 * V_2 )
{
T_1 V_76 = 0 ;
if ( V_2 -> V_17 & V_77 )
V_76 |= V_78 ;
if ( V_2 -> V_17 & V_79 )
V_76 |= V_80 ;
if ( V_2 -> V_17 & V_81 )
V_76 |= V_82 ;
if ( V_2 -> V_17 & V_83 )
V_76 |= V_84 ;
if ( V_2 -> V_17 & V_85 )
V_76 |= V_86 ;
return V_76 ;
}
static int F_20 ( struct V_1 * V_2 , T_1 V_48 )
{
V_21 V_17 = 0 , V_87 ;
if ( V_48 & ~ V_88 )
return - V_35 ;
if ( V_48 & V_78 )
V_17 |= V_77 ;
if ( V_48 & V_80 )
V_17 |= V_79 ;
if ( V_48 & V_82 )
V_17 |= V_81 ;
if ( V_48 & V_84 )
V_17 |= V_83 ;
if ( V_48 & V_86 )
V_17 |= V_85 ;
V_87 = ( V_17 ^ V_2 -> V_17 ) & V_89 ;
if ( V_87 & ~ V_2 -> V_23 )
return ( V_87 & V_2 -> V_23 ) ? - V_35 : - V_46 ;
V_2 -> V_25 =
( V_2 -> V_25 & ~ V_87 ) | ( V_17 & V_87 ) ;
F_11 ( V_2 ) ;
return 0 ;
}
int F_21 ( struct V_1 * V_2 , struct V_90 * V_12 )
{
F_22 () ;
if ( ! V_2 -> V_40 -> V_91 )
return - V_46 ;
memset ( V_12 , 0 , sizeof( struct V_90 ) ) ;
V_12 -> V_12 = V_92 ;
return V_2 -> V_40 -> V_91 ( V_2 , V_12 ) ;
}
static int F_23 ( struct V_1 * V_2 , void T_2 * V_10 )
{
int V_93 ;
struct V_90 V_12 ;
V_93 = F_21 ( V_2 , & V_12 ) ;
if ( V_93 < 0 )
return V_93 ;
if ( F_8 ( V_10 , & V_12 , sizeof( V_12 ) ) )
return - V_29 ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 , void T_2 * V_10 )
{
struct V_90 V_12 ;
if ( ! V_2 -> V_40 -> V_94 )
return - V_46 ;
if ( F_10 ( & V_12 , V_10 , sizeof( V_12 ) ) )
return - V_29 ;
return V_2 -> V_40 -> V_94 ( V_2 , & V_12 ) ;
}
static T_4 int F_25 ( struct V_1 * V_2 ,
void T_2 * V_10 )
{
struct V_95 V_4 ;
const struct V_40 * V_41 = V_2 -> V_40 ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
V_4 . V_12 = V_96 ;
if ( V_41 -> V_97 ) {
V_41 -> V_97 ( V_2 , & V_4 ) ;
} else if ( V_2 -> V_2 . V_98 && V_2 -> V_2 . V_98 -> V_99 ) {
F_26 ( V_4 . V_100 , F_27 ( V_2 -> V_2 . V_98 ) ,
sizeof( V_4 . V_100 ) ) ;
F_26 ( V_4 . V_99 , V_2 -> V_2 . V_98 -> V_99 -> V_101 ,
sizeof( V_4 . V_99 ) ) ;
} else {
return - V_46 ;
}
if ( V_41 -> V_44 ) {
int V_102 ;
V_102 = V_41 -> V_44 ( V_2 , V_103 ) ;
if ( V_102 >= 0 )
V_4 . V_104 = V_102 ;
V_102 = V_41 -> V_44 ( V_2 , V_105 ) ;
if ( V_102 >= 0 )
V_4 . V_106 = V_102 ;
V_102 = V_41 -> V_44 ( V_2 , V_107 ) ;
if ( V_102 >= 0 )
V_4 . V_108 = V_102 ;
}
if ( V_41 -> V_109 )
V_4 . V_110 = V_41 -> V_109 ( V_2 ) ;
if ( V_41 -> V_111 )
V_4 . V_112 = V_41 -> V_111 ( V_2 ) ;
if ( F_8 ( V_10 , & V_4 , sizeof( V_4 ) ) )
return - V_29 ;
return 0 ;
}
static T_4 int F_28 ( struct V_1 * V_2 ,
void T_2 * V_10 )
{
struct V_113 V_4 ;
T_5 V_114 ;
int V_20 , V_115 = 0 , V_116 = 0 , V_34 , V_102 ;
T_1 * V_117 = NULL ;
if ( F_10 ( & V_4 , V_10 , sizeof( V_4 ) ) )
return - V_29 ;
V_114 = V_4 . V_114 ;
if ( ! V_114 )
return 0 ;
V_116 = F_29 ( V_114 ) ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
V_4 . V_12 = V_118 ;
V_117 = F_30 ( V_116 * sizeof( T_1 ) , V_119 ) ;
if ( ! V_117 )
return - V_120 ;
for ( V_20 = 0 ; V_20 < 64 ; V_20 ++ ) {
if ( ! ( V_114 & ( 1ULL << V_20 ) ) )
continue;
V_102 = F_12 ( V_2 , V_20 ) ;
if ( V_102 >= 0 ) {
V_4 . V_114 |= ( 1ULL << V_20 ) ;
V_117 [ V_115 ++ ] = V_102 ;
}
}
V_34 = - V_29 ;
if ( F_8 ( V_10 , & V_4 , sizeof( V_4 ) ) )
goto V_121;
V_10 += F_6 ( struct V_113 , V_48 ) ;
if ( F_8 ( V_10 , V_117 , V_115 * sizeof( T_1 ) ) )
goto V_121;
V_34 = 0 ;
V_121:
F_31 ( V_117 ) ;
return V_34 ;
}
static T_4 int F_32 ( struct V_1 * V_2 ,
T_1 V_12 , void T_2 * V_10 )
{
struct V_122 V_4 ;
T_6 V_123 = sizeof( V_4 ) ;
int V_102 ;
if ( ! V_2 -> V_40 -> V_124 )
return - V_46 ;
if ( V_12 == V_125 )
V_123 = ( F_6 ( struct V_122 , V_48 ) +
sizeof( V_4 . V_48 ) ) ;
if ( F_10 ( & V_4 , V_10 , V_123 ) )
return - V_29 ;
V_102 = V_2 -> V_40 -> V_124 ( V_2 , & V_4 ) ;
if ( V_102 )
return V_102 ;
if ( V_12 == V_126 &&
F_8 ( V_10 , & V_4 , V_123 ) )
return - V_29 ;
return 0 ;
}
static T_4 int F_33 ( struct V_1 * V_2 ,
T_1 V_12 , void T_2 * V_10 )
{
struct V_122 V_4 ;
T_6 V_123 = sizeof( V_4 ) ;
const struct V_40 * V_41 = V_2 -> V_40 ;
int V_34 ;
void * V_127 = NULL ;
if ( ! V_41 -> V_128 )
return - V_46 ;
if ( V_12 == V_129 )
V_123 = ( F_6 ( struct V_122 , V_48 ) +
sizeof( V_4 . V_48 ) ) ;
if ( F_10 ( & V_4 , V_10 , V_123 ) )
return - V_29 ;
if ( V_4 . V_12 == V_130 ) {
if ( V_4 . V_131 > 0 ) {
if ( V_4 . V_131 <= V_132 / sizeof( T_1 ) )
V_127 = F_30 ( V_4 . V_131 * sizeof( T_1 ) ,
V_119 ) ;
if ( ! V_127 )
return - V_120 ;
}
}
V_34 = V_41 -> V_128 ( V_2 , & V_4 , V_127 ) ;
if ( V_34 < 0 )
goto V_133;
V_34 = - V_29 ;
if ( F_8 ( V_10 , & V_4 , V_123 ) )
goto V_133;
if ( V_127 ) {
V_10 += F_6 ( struct V_122 , V_134 ) ;
if ( F_8 ( V_10 , V_127 ,
V_4 . V_131 * sizeof( T_1 ) ) )
goto V_133;
}
V_34 = 0 ;
V_133:
F_31 ( V_127 ) ;
return V_34 ;
}
static T_4 int F_34 ( struct V_1 * V_2 ,
void T_2 * V_10 )
{
T_1 V_135 , V_136 ;
T_1 * V_137 ;
int V_34 ;
if ( ! V_2 -> V_40 -> V_138 ||
! V_2 -> V_40 -> V_139 )
return - V_46 ;
V_136 = V_2 -> V_40 -> V_138 ( V_2 ) ;
if ( V_136 == 0 )
return - V_46 ;
if ( F_10 ( & V_135 ,
V_10 + F_6 ( struct V_140 , V_14 ) ,
sizeof( V_135 ) ) )
return - V_29 ;
if ( F_8 ( V_10 + F_6 ( struct V_140 , V_14 ) ,
& V_136 , sizeof( V_136 ) ) )
return - V_29 ;
if ( V_135 < V_136 )
return V_135 == 0 ? 0 : - V_35 ;
V_137 = F_35 ( V_136 , sizeof( V_137 [ 0 ] ) , V_119 ) ;
if ( ! V_137 )
return - V_120 ;
V_34 = V_2 -> V_40 -> V_139 ( V_2 , V_137 ) ;
if ( V_34 )
goto V_121;
if ( F_8 ( V_10 +
F_6 ( struct V_140 , V_141 [ 0 ] ) ,
V_137 , V_136 * sizeof( V_137 [ 0 ] ) ) )
V_34 = - V_29 ;
V_121:
F_31 ( V_137 ) ;
return V_34 ;
}
static T_4 int F_36 ( struct V_1 * V_2 ,
void T_2 * V_10 )
{
struct V_122 V_142 ;
T_1 V_135 , V_136 , V_20 ;
T_1 * V_137 ;
const struct V_40 * V_41 = V_2 -> V_40 ;
int V_34 ;
if ( ! V_41 -> V_138 || ! V_41 -> V_143 ||
! V_41 -> V_128 )
return - V_46 ;
V_136 = V_41 -> V_138 ( V_2 ) ;
if ( V_136 == 0 )
return - V_46 ;
if ( F_10 ( & V_135 ,
V_10 + F_6 ( struct V_140 , V_14 ) ,
sizeof( V_135 ) ) )
return - V_29 ;
if ( V_135 != 0 && V_135 != V_136 )
return - V_35 ;
V_137 = F_35 ( V_136 , sizeof( V_137 [ 0 ] ) , V_119 ) ;
if ( ! V_137 )
return - V_120 ;
V_142 . V_12 = V_144 ;
V_34 = V_41 -> V_128 ( V_2 , & V_142 , NULL ) ;
if ( V_34 )
goto V_121;
if ( V_135 == 0 ) {
for ( V_20 = 0 ; V_20 < V_136 ; V_20 ++ )
V_137 [ V_20 ] = F_37 ( V_20 , V_142 . V_48 ) ;
} else {
if ( F_10 ( V_137 ,
V_10 +
F_6 ( struct V_140 ,
V_141 [ 0 ] ) ,
V_136 * sizeof( V_137 [ 0 ] ) ) ) {
V_34 = - V_29 ;
goto V_121;
}
for ( V_20 = 0 ; V_20 < V_136 ; V_20 ++ ) {
if ( V_137 [ V_20 ] >= V_142 . V_48 ) {
V_34 = - V_35 ;
goto V_121;
}
}
}
V_34 = V_41 -> V_143 ( V_2 , V_137 ) ;
V_121:
F_31 ( V_137 ) ;
return V_34 ;
}
static int F_38 ( struct V_1 * V_2 , char T_2 * V_10 )
{
struct V_145 V_146 ;
const struct V_40 * V_41 = V_2 -> V_40 ;
void * V_147 ;
int V_148 , V_34 ;
if ( ! V_41 -> V_149 || ! V_41 -> V_109 )
return - V_46 ;
if ( F_10 ( & V_146 , V_10 , sizeof( V_146 ) ) )
return - V_29 ;
V_148 = V_41 -> V_109 ( V_2 ) ;
if ( V_146 . V_150 > V_148 )
V_146 . V_150 = V_148 ;
V_147 = F_39 ( V_148 ) ;
if ( V_148 && ! V_147 )
return - V_120 ;
V_41 -> V_149 ( V_2 , & V_146 , V_147 ) ;
V_34 = - V_29 ;
if ( F_8 ( V_10 , & V_146 , sizeof( V_146 ) ) )
goto V_121;
V_10 += F_6 ( struct V_145 , V_48 ) ;
if ( V_147 && F_8 ( V_10 , V_147 , V_146 . V_150 ) )
goto V_121;
V_34 = 0 ;
V_121:
F_40 ( V_147 ) ;
return V_34 ;
}
static int F_41 ( struct V_1 * V_2 , char T_2 * V_10 )
{
struct V_74 V_151 ;
int V_34 ;
if ( ! V_2 -> V_40 -> V_151 )
return - V_46 ;
if ( F_10 ( & V_151 , V_10 , sizeof( V_151 ) ) )
return - V_29 ;
V_34 = V_2 -> V_40 -> V_151 ( V_2 , & V_151 . V_48 ) ;
if ( V_34 )
return V_34 ;
if ( F_8 ( V_10 , & V_151 , sizeof( V_151 ) ) )
return - V_29 ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 , char T_2 * V_10 )
{
struct V_152 V_153 = { . V_12 = V_154 } ;
if ( ! V_2 -> V_40 -> V_155 )
return - V_46 ;
V_2 -> V_40 -> V_155 ( V_2 , & V_153 ) ;
if ( F_8 ( V_10 , & V_153 , sizeof( V_153 ) ) )
return - V_29 ;
return 0 ;
}
static int F_43 ( struct V_1 * V_2 , char T_2 * V_10 )
{
struct V_152 V_153 ;
if ( ! V_2 -> V_40 -> V_156 )
return - V_46 ;
if ( F_10 ( & V_153 , V_10 , sizeof( V_153 ) ) )
return - V_29 ;
return V_2 -> V_40 -> V_156 ( V_2 , & V_153 ) ;
}
static int F_44 ( struct V_1 * V_2 , char T_2 * V_10 )
{
struct V_157 V_75 ;
int V_102 ;
if ( ! V_2 -> V_40 -> V_158 )
return - V_46 ;
memset ( & V_75 , 0 , sizeof( struct V_157 ) ) ;
V_75 . V_12 = V_159 ;
V_102 = V_2 -> V_40 -> V_158 ( V_2 , & V_75 ) ;
if ( V_102 )
return V_102 ;
if ( F_8 ( V_10 , & V_75 , sizeof( V_75 ) ) )
return - V_29 ;
return 0 ;
}
static int F_45 ( struct V_1 * V_2 , char T_2 * V_10 )
{
struct V_157 V_75 ;
if ( ! V_2 -> V_40 -> V_160 )
return - V_46 ;
if ( F_10 ( & V_75 , V_10 , sizeof( V_75 ) ) )
return - V_29 ;
return V_2 -> V_40 -> V_160 ( V_2 , & V_75 ) ;
}
static int F_46 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_40 -> V_161 )
return - V_46 ;
return V_2 -> V_40 -> V_161 ( V_2 ) ;
}
static int F_47 ( struct V_1 * V_2 , char T_2 * V_10 )
{
struct V_74 V_75 = { . V_12 = V_162 } ;
if ( ! V_2 -> V_40 -> V_163 )
return - V_46 ;
V_75 . V_48 = F_48 ( V_2 ) && V_2 -> V_40 -> V_163 ( V_2 ) ;
if ( F_8 ( V_10 , & V_75 , sizeof( V_75 ) ) )
return - V_29 ;
return 0 ;
}
static int F_49 ( struct V_1 * V_2 , void T_2 * V_10 ,
int (* F_50)( struct V_1 * ,
struct V_164 * , T_3 * ) ,
T_1 V_165 )
{
struct V_164 V_166 ;
void T_2 * V_167 = V_10 + sizeof( V_166 ) ;
T_1 V_168 ;
T_3 * V_48 ;
int V_34 = 0 ;
if ( F_10 ( & V_166 , V_10 , sizeof( V_166 ) ) )
return - V_29 ;
if ( V_166 . V_169 + V_166 . V_150 <= V_166 . V_169 )
return - V_35 ;
if ( V_166 . V_169 + V_166 . V_150 > V_165 )
return - V_35 ;
V_48 = F_51 ( V_170 , V_119 ) ;
if ( ! V_48 )
return - V_120 ;
V_168 = V_166 . V_150 ;
while ( V_168 > 0 ) {
V_166 . V_150 = F_52 ( V_168 , ( T_1 ) V_170 ) ;
V_34 = F_50 ( V_2 , & V_166 , V_48 ) ;
if ( V_34 )
break;
if ( F_8 ( V_167 , V_48 , V_166 . V_150 ) ) {
V_34 = - V_29 ;
break;
}
V_167 += V_166 . V_150 ;
V_166 . V_169 += V_166 . V_150 ;
V_168 -= V_166 . V_150 ;
}
V_166 . V_150 = V_167 - ( V_10 + sizeof( V_166 ) ) ;
V_166 . V_169 -= V_166 . V_150 ;
if ( F_8 ( V_10 , & V_166 , sizeof( V_166 ) ) )
V_34 = - V_29 ;
F_31 ( V_48 ) ;
return V_34 ;
}
static int F_53 ( struct V_1 * V_2 , void T_2 * V_10 )
{
const struct V_40 * V_41 = V_2 -> V_40 ;
if ( ! V_41 -> V_171 || ! V_41 -> V_111 )
return - V_46 ;
return F_49 ( V_2 , V_10 , V_41 -> V_171 ,
V_41 -> V_111 ( V_2 ) ) ;
}
static int F_54 ( struct V_1 * V_2 , void T_2 * V_10 )
{
struct V_164 V_166 ;
const struct V_40 * V_41 = V_2 -> V_40 ;
void T_2 * V_167 = V_10 + sizeof( V_166 ) ;
T_1 V_168 ;
T_3 * V_48 ;
int V_34 = 0 ;
if ( ! V_41 -> V_172 || ! V_41 -> V_111 )
return - V_46 ;
if ( F_10 ( & V_166 , V_10 , sizeof( V_166 ) ) )
return - V_29 ;
if ( V_166 . V_169 + V_166 . V_150 <= V_166 . V_169 )
return - V_35 ;
if ( V_166 . V_169 + V_166 . V_150 > V_41 -> V_111 ( V_2 ) )
return - V_35 ;
V_48 = F_51 ( V_170 , V_119 ) ;
if ( ! V_48 )
return - V_120 ;
V_168 = V_166 . V_150 ;
while ( V_168 > 0 ) {
V_166 . V_150 = F_52 ( V_168 , ( T_1 ) V_170 ) ;
if ( F_10 ( V_48 , V_167 , V_166 . V_150 ) ) {
V_34 = - V_29 ;
break;
}
V_34 = V_41 -> V_172 ( V_2 , & V_166 , V_48 ) ;
if ( V_34 )
break;
V_167 += V_166 . V_150 ;
V_166 . V_169 += V_166 . V_150 ;
V_168 -= V_166 . V_150 ;
}
F_31 ( V_48 ) ;
return V_34 ;
}
static T_4 int F_55 ( struct V_1 * V_2 ,
void T_2 * V_10 )
{
struct V_173 V_174 = { . V_12 = V_175 } ;
if ( ! V_2 -> V_40 -> V_176 )
return - V_46 ;
V_2 -> V_40 -> V_176 ( V_2 , & V_174 ) ;
if ( F_8 ( V_10 , & V_174 , sizeof( V_174 ) ) )
return - V_29 ;
return 0 ;
}
static T_4 int F_56 ( struct V_1 * V_2 ,
void T_2 * V_10 )
{
struct V_173 V_174 ;
if ( ! V_2 -> V_40 -> V_177 )
return - V_46 ;
if ( F_10 ( & V_174 , V_10 , sizeof( V_174 ) ) )
return - V_29 ;
return V_2 -> V_40 -> V_177 ( V_2 , & V_174 ) ;
}
static int F_57 ( struct V_1 * V_2 , void T_2 * V_10 )
{
struct V_178 V_179 = { . V_12 = V_180 } ;
if ( ! V_2 -> V_40 -> V_181 )
return - V_46 ;
V_2 -> V_40 -> V_181 ( V_2 , & V_179 ) ;
if ( F_8 ( V_10 , & V_179 , sizeof( V_179 ) ) )
return - V_29 ;
return 0 ;
}
static int F_58 ( struct V_1 * V_2 , void T_2 * V_10 )
{
struct V_178 V_179 ;
if ( ! V_2 -> V_40 -> V_182 )
return - V_46 ;
if ( F_10 ( & V_179 , V_10 , sizeof( V_179 ) ) )
return - V_29 ;
return V_2 -> V_40 -> V_182 ( V_2 , & V_179 ) ;
}
static T_4 int F_59 ( struct V_1 * V_2 ,
void T_2 * V_10 )
{
struct V_183 V_184 = { . V_12 = V_185 } ;
if ( ! V_2 -> V_40 -> V_186 )
return - V_46 ;
V_2 -> V_40 -> V_186 ( V_2 , & V_184 ) ;
if ( F_8 ( V_10 , & V_184 , sizeof( V_184 ) ) )
return - V_29 ;
return 0 ;
}
static T_4 int F_60 ( struct V_1 * V_2 ,
void T_2 * V_10 )
{
struct V_183 V_184 ;
if ( ! V_2 -> V_40 -> V_187 )
return - V_46 ;
if ( F_10 ( & V_184 , V_10 , sizeof( V_184 ) ) )
return - V_29 ;
return V_2 -> V_40 -> V_187 ( V_2 , & V_184 ) ;
}
static int F_61 ( struct V_1 * V_2 , void T_2 * V_10 )
{
struct V_188 V_189 = { V_190 } ;
if ( ! V_2 -> V_40 -> V_191 )
return - V_46 ;
V_2 -> V_40 -> V_191 ( V_2 , & V_189 ) ;
if ( F_8 ( V_10 , & V_189 , sizeof( V_189 ) ) )
return - V_29 ;
return 0 ;
}
static int F_62 ( struct V_1 * V_2 , void T_2 * V_10 )
{
struct V_188 V_189 ;
if ( ! V_2 -> V_40 -> V_192 )
return - V_46 ;
if ( F_10 ( & V_189 , V_10 , sizeof( V_189 ) ) )
return - V_29 ;
return V_2 -> V_40 -> V_192 ( V_2 , & V_189 ) ;
}
static int F_63 ( struct V_1 * V_2 , char T_2 * V_10 )
{
struct V_193 V_194 ;
const struct V_40 * V_41 = V_2 -> V_40 ;
T_5 * V_48 ;
int V_34 , V_195 ;
if ( ! V_41 -> V_196 || ! V_41 -> V_44 )
return - V_46 ;
V_195 = V_41 -> V_44 ( V_2 , V_103 ) ;
if ( V_195 < 0 )
return V_195 ;
F_64 ( V_195 == 0 ) ;
if ( F_10 ( & V_194 , V_10 , sizeof( V_194 ) ) )
return - V_29 ;
V_194 . V_150 = V_195 ;
V_48 = F_51 ( V_195 * sizeof( T_5 ) , V_119 ) ;
if ( ! V_48 )
return - V_120 ;
V_41 -> V_196 ( V_2 , & V_194 , V_48 ) ;
V_34 = - V_29 ;
if ( F_8 ( V_10 , & V_194 , sizeof( V_194 ) ) )
goto V_121;
V_10 += sizeof( V_194 ) ;
if ( F_8 ( V_10 , V_48 , V_194 . V_150 * sizeof( T_5 ) ) )
goto V_121;
V_34 = 0 ;
V_121:
F_31 ( V_48 ) ;
return V_34 ;
}
static int F_65 ( struct V_1 * V_2 , void T_2 * V_10 )
{
struct V_197 V_198 ;
T_3 * V_48 ;
int V_34 ;
if ( F_10 ( & V_198 , V_10 , sizeof( V_198 ) ) )
return - V_29 ;
V_34 = F_12 ( V_2 , V_198 . V_199 ) ;
if ( V_34 < 0 )
return V_34 ;
V_198 . V_150 = V_34 ;
V_48 = F_51 ( V_198 . V_150 * V_200 , V_119 ) ;
if ( ! V_48 )
return - V_120 ;
F_14 ( V_2 , V_198 . V_199 , V_48 ) ;
V_34 = - V_29 ;
if ( F_8 ( V_10 , & V_198 , sizeof( V_198 ) ) )
goto V_121;
V_10 += sizeof( V_198 ) ;
if ( F_8 ( V_10 , V_48 , V_198 . V_150 * V_200 ) )
goto V_121;
V_34 = 0 ;
V_121:
F_31 ( V_48 ) ;
return V_34 ;
}
static int F_66 ( struct V_1 * V_2 , void T_2 * V_10 )
{
struct V_74 V_201 ;
static bool V_202 ;
const struct V_40 * V_41 = V_2 -> V_40 ;
int V_102 ;
if ( ! V_41 -> V_203 )
return - V_46 ;
if ( V_202 )
return - V_204 ;
if ( F_10 ( & V_201 , V_10 , sizeof( V_201 ) ) )
return - V_29 ;
V_102 = V_41 -> V_203 ( V_2 , V_205 ) ;
if ( V_102 < 0 )
return V_102 ;
V_202 = true ;
F_67 ( V_2 ) ;
F_68 () ;
if ( V_102 == 0 ) {
F_69 (
V_201 . V_48 ? ( V_201 . V_48 * V_206 ) : V_207 ) ;
} else {
int V_208 = V_102 * 2 , V_20 , V_209 = V_206 / V_208 ;
do {
V_20 = V_208 ;
do {
F_70 () ;
V_102 = V_41 -> V_203 ( V_2 ,
( V_20 & 1 ) ? V_210 : V_211 ) ;
F_68 () ;
if ( V_102 )
break;
F_69 ( V_209 ) ;
} while ( ! F_71 ( V_212 ) && -- V_20 != 0 );
} while ( ! F_71 ( V_212 ) &&
( V_201 . V_48 == 0 || -- V_201 . V_48 != 0 ) );
}
F_70 () ;
F_72 ( V_2 ) ;
V_202 = false ;
( void ) V_41 -> V_203 ( V_2 , V_213 ) ;
return V_102 ;
}
static int F_73 ( struct V_1 * V_2 , void T_2 * V_10 )
{
struct V_214 V_215 ;
const struct V_40 * V_41 = V_2 -> V_40 ;
T_5 * V_48 ;
int V_34 , V_106 ;
if ( ! V_41 -> V_216 || ! V_41 -> V_44 )
return - V_46 ;
V_106 = V_41 -> V_44 ( V_2 , V_105 ) ;
if ( V_106 < 0 )
return V_106 ;
F_64 ( V_106 == 0 ) ;
if ( F_10 ( & V_215 , V_10 , sizeof( V_215 ) ) )
return - V_29 ;
V_215 . V_106 = V_106 ;
V_48 = F_51 ( V_106 * sizeof( T_5 ) , V_119 ) ;
if ( ! V_48 )
return - V_120 ;
V_41 -> V_216 ( V_2 , & V_215 , V_48 ) ;
V_34 = - V_29 ;
if ( F_8 ( V_10 , & V_215 , sizeof( V_215 ) ) )
goto V_121;
V_10 += sizeof( V_215 ) ;
if ( F_8 ( V_10 , V_48 , V_215 . V_106 * sizeof( T_5 ) ) )
goto V_121;
V_34 = 0 ;
V_121:
F_31 ( V_48 ) ;
return V_34 ;
}
static int F_74 ( struct V_1 * V_2 , void T_2 * V_10 )
{
struct V_217 V_218 ;
if ( F_10 ( & V_218 , V_10 , sizeof( V_218 ) ) )
return - V_29 ;
if ( V_218 . V_14 < V_2 -> V_219 )
return - V_220 ;
V_218 . V_14 = V_2 -> V_219 ;
if ( F_8 ( V_10 , & V_218 , sizeof( V_218 ) ) )
return - V_29 ;
V_10 += sizeof( V_218 ) ;
if ( F_8 ( V_10 , V_2 -> V_221 , V_218 . V_14 ) )
return - V_29 ;
return 0 ;
}
static int F_75 ( struct V_1 * V_2 , char T_2 * V_10 ,
T_1 V_12 , T_1 (* F_76)( struct V_1 * ) )
{
struct V_74 V_75 = { . V_12 = V_12 } ;
if ( ! F_76 )
return - V_46 ;
V_75 . V_48 = F_76 ( V_2 ) ;
if ( F_8 ( V_10 , & V_75 , sizeof( V_75 ) ) )
return - V_29 ;
return 0 ;
}
static int F_77 ( struct V_1 * V_2 , char T_2 * V_10 ,
void (* F_76)( struct V_1 * , T_1 ) )
{
struct V_74 V_75 ;
if ( ! F_76 )
return - V_46 ;
if ( F_10 ( & V_75 , V_10 , sizeof( V_75 ) ) )
return - V_29 ;
F_76 ( V_2 , V_75 . V_48 ) ;
return 0 ;
}
static int F_78 ( struct V_1 * V_2 , char T_2 * V_10 ,
int (* F_76)( struct V_1 * , T_1 ) )
{
struct V_74 V_75 ;
if ( ! F_76 )
return - V_46 ;
if ( F_10 ( & V_75 , V_10 , sizeof( V_75 ) ) )
return - V_29 ;
return F_76 ( V_2 , V_75 . V_48 ) ;
}
static T_4 int F_79 ( struct V_1 * V_2 ,
char T_2 * V_10 )
{
struct V_222 V_223 ;
if ( F_10 ( & V_223 , V_10 , sizeof( V_223 ) ) )
return - V_29 ;
if ( ! V_2 -> V_40 -> V_224 )
return - V_46 ;
V_223 . V_48 [ V_225 - 1 ] = 0 ;
return V_2 -> V_40 -> V_224 ( V_2 , & V_223 ) ;
}
static int F_80 ( struct V_1 * V_2 ,
void T_2 * V_10 )
{
struct V_226 V_227 ;
if ( ! V_2 -> V_40 -> V_228 )
return - V_46 ;
if ( F_10 ( & V_227 , V_10 , sizeof( V_227 ) ) )
return - V_29 ;
return V_2 -> V_40 -> V_228 ( V_2 , & V_227 ) ;
}
static int F_81 ( struct V_1 * V_2 ,
void T_2 * V_10 )
{
int V_34 ;
struct V_226 V_227 ;
const struct V_40 * V_41 = V_2 -> V_40 ;
if ( ! V_41 -> V_229 )
return - V_46 ;
if ( F_10 ( & V_227 , V_10 , sizeof( V_227 ) ) )
return - V_29 ;
V_34 = V_41 -> V_229 ( V_2 , & V_227 ) ;
if ( V_34 )
return V_34 ;
if ( F_8 ( V_10 , & V_227 , sizeof( V_227 ) ) )
return - V_29 ;
return 0 ;
}
static int F_82 ( struct V_1 * V_2 ,
void T_2 * V_10 )
{
int V_34 ;
T_7 V_150 ;
struct V_226 V_227 , V_230 ;
const struct V_40 * V_41 = V_2 -> V_40 ;
void * V_48 = NULL ;
if ( ! V_41 -> V_231 || ! V_41 -> V_229 )
return - V_46 ;
if ( F_10 ( & V_227 , V_10 , sizeof( V_227 ) ) )
return - V_29 ;
memset ( & V_230 , 0 , sizeof( V_230 ) ) ;
V_230 . V_12 = V_232 ;
V_34 = V_41 -> V_229 ( V_2 , & V_230 ) ;
if ( V_34 )
return V_34 ;
V_150 = F_52 ( V_230 . V_150 , V_227 . V_150 ) ;
if ( ! V_150 )
return - V_29 ;
V_227 . V_150 = V_150 ;
V_48 = F_39 ( V_230 . V_150 ) ;
if ( ! V_48 )
return - V_120 ;
V_34 = V_41 -> V_231 ( V_2 , & V_227 , V_48 ) ;
if ( V_34 )
goto V_121;
F_64 ( V_227 . V_150 != V_150 && V_227 . V_150 != V_230 . V_150 ) ;
V_227 . V_150 = V_150 ;
if ( F_8 ( V_10 , & V_227 , sizeof( V_227 ) ) ) {
V_34 = - V_29 ;
goto V_121;
}
V_10 += F_6 ( struct V_226 , V_48 ) ;
if ( F_8 ( V_10 , V_48 , V_150 ) )
V_34 = - V_29 ;
V_121:
F_40 ( V_48 ) ;
return V_34 ;
}
static int F_83 ( struct V_1 * V_2 , void T_2 * V_10 )
{
int V_93 = 0 ;
struct V_3 V_4 ;
const struct V_40 * V_41 = V_2 -> V_40 ;
struct V_233 * V_234 = V_2 -> V_234 ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
V_4 . V_12 = V_235 ;
if ( V_234 && V_234 -> V_236 && V_234 -> V_236 -> V_237 ) {
V_93 = V_234 -> V_236 -> V_237 ( V_234 , & V_4 ) ;
} else if ( V_41 -> V_238 ) {
V_93 = V_41 -> V_238 ( V_2 , & V_4 ) ;
} else {
V_4 . V_5 =
V_7 |
V_8 ;
V_4 . V_9 = - 1 ;
}
if ( V_93 )
return V_93 ;
if ( F_8 ( V_10 , & V_4 , sizeof( V_4 ) ) )
V_93 = - V_29 ;
return V_93 ;
}
static int F_84 ( struct V_1 * V_2 ,
void T_2 * V_10 )
{
int V_34 ;
struct V_239 V_240 ;
const struct V_40 * V_41 = V_2 -> V_40 ;
if ( ! V_41 -> V_241 )
return - V_46 ;
if ( F_10 ( & V_240 , V_10 , sizeof( V_240 ) ) )
return - V_29 ;
V_34 = V_41 -> V_241 ( V_2 , & V_240 ) ;
if ( V_34 )
return V_34 ;
if ( F_8 ( V_10 , & V_240 , sizeof( V_240 ) ) )
return - V_29 ;
return 0 ;
}
static int F_85 ( struct V_1 * V_2 ,
void T_2 * V_10 )
{
int V_34 ;
struct V_239 V_240 ;
const struct V_40 * V_41 = V_2 -> V_40 ;
if ( ! V_41 -> V_241 || ! V_41 -> V_242 )
return - V_46 ;
V_34 = V_41 -> V_241 ( V_2 , & V_240 ) ;
if ( V_34 )
return V_34 ;
return F_49 ( V_2 , V_10 , V_41 -> V_242 ,
V_240 . V_243 ) ;
}
int F_86 ( struct V_244 * V_244 , struct V_245 * V_246 )
{
struct V_1 * V_2 = F_87 ( V_244 , V_246 -> V_247 ) ;
void T_2 * V_10 = V_246 -> V_248 ;
T_1 V_72 ;
int V_102 ;
V_21 V_249 ;
if ( ! V_2 || ! F_88 ( V_2 ) )
return - V_250 ;
if ( F_10 ( & V_72 , V_10 , sizeof( V_72 ) ) )
return - V_29 ;
switch ( V_72 ) {
case V_92 :
case V_96 :
case V_251 :
case V_162 :
case V_175 :
case V_180 :
case V_190 :
case V_54 :
case V_50 :
case V_57 :
case V_118 :
case V_252 :
case V_253 :
case V_60 :
case V_254 :
case V_63 :
case V_66 :
case V_69 :
case V_255 :
case V_256 :
case V_129 :
case V_144 :
case V_257 :
case V_258 :
case V_130 :
case V_259 :
case V_13 :
case V_185 :
case V_235 :
case V_159 :
break;
default:
if ( ! F_89 ( V_244 -> V_260 , V_261 ) )
return - V_262 ;
}
if ( V_2 -> V_40 -> V_263 ) {
V_102 = V_2 -> V_40 -> V_263 ( V_2 ) ;
if ( V_102 < 0 )
return V_102 ;
}
V_249 = V_2 -> V_17 ;
switch ( V_72 ) {
case V_92 :
V_102 = F_23 ( V_2 , V_10 ) ;
break;
case V_264 :
V_102 = F_24 ( V_2 , V_10 ) ;
break;
case V_96 :
V_102 = F_25 ( V_2 , V_10 ) ;
break;
case V_265 :
V_102 = F_38 ( V_2 , V_10 ) ;
break;
case V_154 :
V_102 = F_42 ( V_2 , V_10 ) ;
break;
case V_266 :
V_102 = F_43 ( V_2 , V_10 ) ;
break;
case V_251 :
V_102 = F_75 ( V_2 , V_10 , V_72 ,
V_2 -> V_40 -> V_267 ) ;
break;
case V_268 :
V_102 = F_77 ( V_2 , V_10 ,
V_2 -> V_40 -> V_269 ) ;
break;
case V_159 :
V_102 = F_44 ( V_2 , V_10 ) ;
break;
case V_270 :
V_102 = F_45 ( V_2 , V_10 ) ;
break;
case V_271 :
V_102 = F_46 ( V_2 ) ;
break;
case V_162 :
V_102 = F_47 ( V_2 , V_10 ) ;
break;
case V_272 :
V_102 = F_53 ( V_2 , V_10 ) ;
break;
case V_273 :
V_102 = F_54 ( V_2 , V_10 ) ;
break;
case V_175 :
V_102 = F_55 ( V_2 , V_10 ) ;
break;
case V_274 :
V_102 = F_56 ( V_2 , V_10 ) ;
break;
case V_180 :
V_102 = F_57 ( V_2 , V_10 ) ;
break;
case V_275 :
V_102 = F_58 ( V_2 , V_10 ) ;
break;
case V_190 :
V_102 = F_61 ( V_2 , V_10 ) ;
break;
case V_276 :
V_102 = F_62 ( V_2 , V_10 ) ;
break;
case V_277 :
V_102 = F_63 ( V_2 , V_10 ) ;
break;
case V_252 :
V_102 = F_65 ( V_2 , V_10 ) ;
break;
case V_278 :
V_102 = F_66 ( V_2 , V_10 ) ;
break;
case V_253 :
V_102 = F_73 ( V_2 , V_10 ) ;
break;
case V_254 :
V_102 = F_74 ( V_2 , V_10 ) ;
break;
case V_255 :
V_102 = F_75 ( V_2 , V_10 , V_72 ,
F_19 ) ;
break;
case V_279 :
V_102 = F_78 ( V_2 , V_10 , F_20 ) ;
break;
case V_256 :
V_102 = F_75 ( V_2 , V_10 , V_72 ,
V_2 -> V_40 -> V_280 ) ;
break;
case V_281 :
V_102 = F_78 ( V_2 , V_10 ,
V_2 -> V_40 -> V_282 ) ;
break;
case V_129 :
case V_144 :
case V_257 :
case V_258 :
case V_130 :
V_102 = F_33 ( V_2 , V_72 , V_10 ) ;
break;
case V_125 :
case V_283 :
case V_126 :
V_102 = F_32 ( V_2 , V_72 , V_10 ) ;
break;
case V_284 :
V_102 = F_79 ( V_2 , V_10 ) ;
break;
case V_285 :
V_102 = F_41 ( V_2 , V_10 ) ;
break;
case V_118 :
V_102 = F_28 ( V_2 , V_10 ) ;
break;
case V_259 :
V_102 = F_34 ( V_2 , V_10 ) ;
break;
case V_286 :
V_102 = F_36 ( V_2 , V_10 ) ;
break;
case V_13 :
V_102 = F_4 ( V_2 , V_10 ) ;
break;
case V_287 :
V_102 = F_9 ( V_2 , V_10 ) ;
break;
case V_50 :
case V_54 :
case V_57 :
case V_60 :
case V_63 :
case V_66 :
case V_69 :
V_102 = F_17 ( V_2 , V_10 , V_72 ) ;
break;
case V_51 :
case V_55 :
case V_58 :
case V_61 :
case V_64 :
case V_67 :
case V_70 :
V_102 = F_18 ( V_2 , V_10 , V_72 ) ;
break;
case V_185 :
V_102 = F_59 ( V_2 , V_10 ) ;
break;
case V_288 :
V_102 = F_60 ( V_2 , V_10 ) ;
break;
case V_289 :
V_102 = F_80 ( V_2 , V_10 ) ;
break;
case V_232 :
V_102 = F_81 ( V_2 , V_10 ) ;
break;
case V_290 :
V_102 = F_82 ( V_2 , V_10 ) ;
break;
case V_235 :
V_102 = F_83 ( V_2 , V_10 ) ;
break;
case V_291 :
V_102 = F_84 ( V_2 , V_10 ) ;
break;
case V_292 :
V_102 = F_85 ( V_2 , V_10 ) ;
break;
default:
V_102 = - V_46 ;
}
if ( V_2 -> V_40 -> V_293 )
V_2 -> V_40 -> V_293 ( V_2 ) ;
if ( V_249 != V_2 -> V_17 )
F_90 ( V_2 ) ;
return V_102 ;
}
