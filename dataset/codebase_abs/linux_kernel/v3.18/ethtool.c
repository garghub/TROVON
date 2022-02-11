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
static int F_34 ( T_1 * V_135 , void T_2 * V_10 ,
struct V_122 * V_136 ,
T_1 V_14 )
{
int V_20 ;
if ( F_10 ( V_135 , V_10 , V_14 * sizeof( V_135 [ 0 ] ) ) )
return - V_29 ;
for ( V_20 = 0 ; V_20 < V_14 ; V_20 ++ )
if ( V_135 [ V_20 ] >= V_136 -> V_48 )
return - V_35 ;
return 0 ;
}
static T_4 int F_35 ( struct V_1 * V_2 ,
void T_2 * V_10 )
{
T_1 V_137 , V_138 ;
T_1 * V_135 ;
int V_34 ;
if ( ! V_2 -> V_40 -> V_139 ||
! V_2 -> V_40 -> V_140 )
return - V_46 ;
V_138 = V_2 -> V_40 -> V_139 ( V_2 ) ;
if ( V_138 == 0 )
return - V_46 ;
if ( F_10 ( & V_137 ,
V_10 + F_6 ( struct V_141 , V_14 ) ,
sizeof( V_137 ) ) )
return - V_29 ;
if ( F_8 ( V_10 + F_6 ( struct V_141 , V_14 ) ,
& V_138 , sizeof( V_138 ) ) )
return - V_29 ;
if ( V_137 < V_138 )
return V_137 == 0 ? 0 : - V_35 ;
V_135 = F_36 ( V_138 , sizeof( V_135 [ 0 ] ) , V_119 ) ;
if ( ! V_135 )
return - V_120 ;
V_34 = V_2 -> V_40 -> V_140 ( V_2 , V_135 , NULL ) ;
if ( V_34 )
goto V_121;
if ( F_8 ( V_10 +
F_6 ( struct V_141 , V_142 [ 0 ] ) ,
V_135 , V_138 * sizeof( V_135 [ 0 ] ) ) )
V_34 = - V_29 ;
V_121:
F_31 ( V_135 ) ;
return V_34 ;
}
static T_4 int F_37 ( struct V_1 * V_2 ,
void T_2 * V_10 )
{
struct V_122 V_136 ;
T_1 V_137 , V_138 , V_20 ;
T_1 * V_135 ;
const struct V_40 * V_41 = V_2 -> V_40 ;
int V_34 ;
T_1 V_143 = F_6 ( struct V_141 , V_142 [ 0 ] ) ;
if ( ! V_41 -> V_139 || ! V_41 -> V_144 ||
! V_41 -> V_128 )
return - V_46 ;
V_138 = V_41 -> V_139 ( V_2 ) ;
if ( V_138 == 0 )
return - V_46 ;
if ( F_10 ( & V_137 ,
V_10 + F_6 ( struct V_141 , V_14 ) ,
sizeof( V_137 ) ) )
return - V_29 ;
if ( V_137 != 0 && V_137 != V_138 )
return - V_35 ;
V_135 = F_36 ( V_138 , sizeof( V_135 [ 0 ] ) , V_119 ) ;
if ( ! V_135 )
return - V_120 ;
V_136 . V_12 = V_145 ;
V_34 = V_41 -> V_128 ( V_2 , & V_136 , NULL ) ;
if ( V_34 )
goto V_121;
if ( V_137 == 0 ) {
for ( V_20 = 0 ; V_20 < V_138 ; V_20 ++ )
V_135 [ V_20 ] = F_38 ( V_20 , V_136 . V_48 ) ;
} else {
V_34 = F_34 ( V_135 ,
V_10 + V_143 ,
& V_136 ,
V_138 ) ;
if ( V_34 )
goto V_121;
}
V_34 = V_41 -> V_144 ( V_2 , V_135 , NULL ) ;
V_121:
F_31 ( V_135 ) ;
return V_34 ;
}
static T_4 int F_39 ( struct V_1 * V_2 ,
void T_2 * V_10 )
{
int V_34 ;
const struct V_40 * V_41 = V_2 -> V_40 ;
T_1 V_146 , V_147 ;
T_1 V_148 = 0 , V_149 = 0 ;
struct V_150 V_151 ;
T_1 V_152 ;
T_1 V_153 ;
T_1 * V_135 = NULL ;
T_3 * V_154 = NULL ;
T_3 * V_155 ;
if ( ! ( V_2 -> V_40 -> V_139 ||
V_2 -> V_40 -> V_156 ) ||
! V_2 -> V_40 -> V_140 )
return - V_46 ;
if ( V_41 -> V_139 )
V_148 = V_41 -> V_139 ( V_2 ) ;
if ( V_41 -> V_156 )
V_149 = V_41 -> V_156 ( V_2 ) ;
if ( ( V_149 + V_148 ) == 0 )
return - V_46 ;
if ( F_10 ( & V_151 , V_10 , sizeof( V_151 ) ) )
return - V_29 ;
V_146 = V_151 . V_157 ;
V_147 = V_151 . V_158 ;
if ( V_151 . V_159 || V_151 . V_160 [ 0 ] || V_151 . V_160 [ 1 ] )
return - V_35 ;
V_151 . V_157 = V_148 ;
V_151 . V_158 = V_149 ;
if ( F_8 ( V_10 , & V_151 , sizeof( V_151 ) ) )
return - V_29 ;
if ( ! V_146 && ! V_147 )
return 0 ;
if ( ( V_146 && ( V_146 != V_148 ) ) ||
( V_147 && ( V_147 != V_149 ) ) )
return - V_35 ;
V_153 = V_146 * sizeof( V_135 [ 0 ] ) ;
V_152 = V_153 + V_147 ;
V_155 = F_30 ( V_152 , V_119 ) ;
if ( ! V_155 )
return - V_120 ;
if ( V_146 )
V_135 = ( T_1 * ) V_155 ;
if ( V_147 )
V_154 = V_155 + V_153 ;
V_34 = V_2 -> V_40 -> V_140 ( V_2 , V_135 , V_154 ) ;
if ( ! V_34 ) {
if ( F_8 ( V_10 +
F_6 ( struct V_150 , V_155 [ 0 ] ) ,
V_155 , V_152 ) )
V_34 = - V_29 ;
}
F_31 ( V_155 ) ;
return V_34 ;
}
static T_4 int F_40 ( struct V_1 * V_2 ,
void T_2 * V_10 )
{
int V_34 ;
const struct V_40 * V_41 = V_2 -> V_40 ;
struct V_122 V_136 ;
struct V_150 V_151 ;
T_1 V_148 = 0 , V_149 = 0 , V_20 ;
T_1 * V_135 = NULL , V_153 = 0 ;
T_3 * V_154 = NULL ;
T_3 * V_155 ;
T_1 V_161 = F_6 ( struct V_150 , V_155 [ 0 ] ) ;
if ( ! ( V_41 -> V_139 || V_41 -> V_156 ) ||
! V_41 -> V_128 || ! V_41 -> V_144 )
return - V_46 ;
if ( V_41 -> V_139 )
V_148 = V_41 -> V_139 ( V_2 ) ;
if ( V_41 -> V_156 )
V_149 = V_2 -> V_40 -> V_156 ( V_2 ) ;
if ( ( V_149 + V_148 ) == 0 )
return - V_46 ;
if ( F_10 ( & V_151 , V_10 , sizeof( V_151 ) ) )
return - V_29 ;
if ( V_151 . V_159 || V_151 . V_160 [ 0 ] || V_151 . V_160 [ 1 ] )
return - V_35 ;
if ( ( V_151 . V_157 &&
V_151 . V_157 != V_162 &&
V_151 . V_157 != V_148 ) ||
( V_151 . V_158 && ( V_151 . V_158 != V_149 ) ) ||
( V_151 . V_157 == V_162 &&
V_151 . V_158 == 0 ) )
return - V_35 ;
if ( V_151 . V_157 != V_162 )
V_153 = V_148 * sizeof( V_135 [ 0 ] ) ;
V_155 = F_30 ( V_153 + V_151 . V_158 , V_119 ) ;
if ( ! V_155 )
return - V_120 ;
V_136 . V_12 = V_145 ;
V_34 = V_41 -> V_128 ( V_2 , & V_136 , NULL ) ;
if ( V_34 )
goto V_121;
if ( V_151 . V_157 &&
V_151 . V_157 != V_162 ) {
V_135 = ( T_1 * ) V_155 ;
V_34 = F_34 ( V_135 ,
V_10 + V_161 ,
& V_136 ,
V_151 . V_157 ) ;
if ( V_34 )
goto V_121;
} else if ( V_151 . V_157 == 0 ) {
V_135 = ( T_1 * ) V_155 ;
for ( V_20 = 0 ; V_20 < V_148 ; V_20 ++ )
V_135 [ V_20 ] = F_38 ( V_20 , V_136 . V_48 ) ;
}
if ( V_151 . V_158 ) {
V_154 = V_155 + V_153 ;
if ( F_10 ( V_154 ,
V_10 + V_161 + V_153 ,
V_151 . V_158 ) ) {
V_34 = - V_29 ;
goto V_121;
}
}
V_34 = V_41 -> V_144 ( V_2 , V_135 , V_154 ) ;
V_121:
F_31 ( V_155 ) ;
return V_34 ;
}
static int F_41 ( struct V_1 * V_2 , char T_2 * V_10 )
{
struct V_163 V_164 ;
const struct V_40 * V_41 = V_2 -> V_40 ;
void * V_165 ;
int V_166 , V_34 ;
if ( ! V_41 -> V_167 || ! V_41 -> V_109 )
return - V_46 ;
if ( F_10 ( & V_164 , V_10 , sizeof( V_164 ) ) )
return - V_29 ;
V_166 = V_41 -> V_109 ( V_2 ) ;
if ( V_164 . V_168 > V_166 )
V_164 . V_168 = V_166 ;
V_165 = F_42 ( V_166 ) ;
if ( V_166 && ! V_165 )
return - V_120 ;
V_41 -> V_167 ( V_2 , & V_164 , V_165 ) ;
V_34 = - V_29 ;
if ( F_8 ( V_10 , & V_164 , sizeof( V_164 ) ) )
goto V_121;
V_10 += F_6 ( struct V_163 , V_48 ) ;
if ( V_165 && F_8 ( V_10 , V_165 , V_164 . V_168 ) )
goto V_121;
V_34 = 0 ;
V_121:
F_43 ( V_165 ) ;
return V_34 ;
}
static int F_44 ( struct V_1 * V_2 , char T_2 * V_10 )
{
struct V_74 V_169 ;
int V_34 ;
if ( ! V_2 -> V_40 -> V_169 )
return - V_46 ;
if ( F_10 ( & V_169 , V_10 , sizeof( V_169 ) ) )
return - V_29 ;
V_34 = V_2 -> V_40 -> V_169 ( V_2 , & V_169 . V_48 ) ;
if ( V_34 )
return V_34 ;
if ( F_8 ( V_10 , & V_169 , sizeof( V_169 ) ) )
return - V_29 ;
return 0 ;
}
static int F_45 ( struct V_1 * V_2 , char T_2 * V_10 )
{
struct V_170 V_171 = { . V_12 = V_172 } ;
if ( ! V_2 -> V_40 -> V_173 )
return - V_46 ;
V_2 -> V_40 -> V_173 ( V_2 , & V_171 ) ;
if ( F_8 ( V_10 , & V_171 , sizeof( V_171 ) ) )
return - V_29 ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 , char T_2 * V_10 )
{
struct V_170 V_171 ;
if ( ! V_2 -> V_40 -> V_174 )
return - V_46 ;
if ( F_10 ( & V_171 , V_10 , sizeof( V_171 ) ) )
return - V_29 ;
return V_2 -> V_40 -> V_174 ( V_2 , & V_171 ) ;
}
static int F_47 ( struct V_1 * V_2 , char T_2 * V_10 )
{
struct V_175 V_75 ;
int V_102 ;
if ( ! V_2 -> V_40 -> V_176 )
return - V_46 ;
memset ( & V_75 , 0 , sizeof( struct V_175 ) ) ;
V_75 . V_12 = V_177 ;
V_102 = V_2 -> V_40 -> V_176 ( V_2 , & V_75 ) ;
if ( V_102 )
return V_102 ;
if ( F_8 ( V_10 , & V_75 , sizeof( V_75 ) ) )
return - V_29 ;
return 0 ;
}
static int F_48 ( struct V_1 * V_2 , char T_2 * V_10 )
{
struct V_175 V_75 ;
if ( ! V_2 -> V_40 -> V_178 )
return - V_46 ;
if ( F_10 ( & V_75 , V_10 , sizeof( V_75 ) ) )
return - V_29 ;
return V_2 -> V_40 -> V_178 ( V_2 , & V_75 ) ;
}
static int F_49 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_40 -> V_179 )
return - V_46 ;
return V_2 -> V_40 -> V_179 ( V_2 ) ;
}
static int F_50 ( struct V_1 * V_2 , char T_2 * V_10 )
{
struct V_74 V_75 = { . V_12 = V_180 } ;
if ( ! V_2 -> V_40 -> V_181 )
return - V_46 ;
V_75 . V_48 = F_51 ( V_2 ) && V_2 -> V_40 -> V_181 ( V_2 ) ;
if ( F_8 ( V_10 , & V_75 , sizeof( V_75 ) ) )
return - V_29 ;
return 0 ;
}
static int F_52 ( struct V_1 * V_2 , void T_2 * V_10 ,
int (* F_53)( struct V_1 * ,
struct V_182 * , T_3 * ) ,
T_1 V_183 )
{
struct V_182 V_184 ;
void T_2 * V_185 = V_10 + sizeof( V_184 ) ;
T_1 V_186 ;
T_3 * V_48 ;
int V_34 = 0 ;
if ( F_10 ( & V_184 , V_10 , sizeof( V_184 ) ) )
return - V_29 ;
if ( V_184 . V_187 + V_184 . V_168 <= V_184 . V_187 )
return - V_35 ;
if ( V_184 . V_187 + V_184 . V_168 > V_183 )
return - V_35 ;
V_48 = F_54 ( V_188 , V_119 ) ;
if ( ! V_48 )
return - V_120 ;
V_186 = V_184 . V_168 ;
while ( V_186 > 0 ) {
V_184 . V_168 = F_55 ( V_186 , ( T_1 ) V_188 ) ;
V_34 = F_53 ( V_2 , & V_184 , V_48 ) ;
if ( V_34 )
break;
if ( F_8 ( V_185 , V_48 , V_184 . V_168 ) ) {
V_34 = - V_29 ;
break;
}
V_185 += V_184 . V_168 ;
V_184 . V_187 += V_184 . V_168 ;
V_186 -= V_184 . V_168 ;
}
V_184 . V_168 = V_185 - ( V_10 + sizeof( V_184 ) ) ;
V_184 . V_187 -= V_184 . V_168 ;
if ( F_8 ( V_10 , & V_184 , sizeof( V_184 ) ) )
V_34 = - V_29 ;
F_31 ( V_48 ) ;
return V_34 ;
}
static int F_56 ( struct V_1 * V_2 , void T_2 * V_10 )
{
const struct V_40 * V_41 = V_2 -> V_40 ;
if ( ! V_41 -> V_189 || ! V_41 -> V_111 ||
! V_41 -> V_111 ( V_2 ) )
return - V_46 ;
return F_52 ( V_2 , V_10 , V_41 -> V_189 ,
V_41 -> V_111 ( V_2 ) ) ;
}
static int F_57 ( struct V_1 * V_2 , void T_2 * V_10 )
{
struct V_182 V_184 ;
const struct V_40 * V_41 = V_2 -> V_40 ;
void T_2 * V_185 = V_10 + sizeof( V_184 ) ;
T_1 V_186 ;
T_3 * V_48 ;
int V_34 = 0 ;
if ( ! V_41 -> V_190 || ! V_41 -> V_111 ||
! V_41 -> V_111 ( V_2 ) )
return - V_46 ;
if ( F_10 ( & V_184 , V_10 , sizeof( V_184 ) ) )
return - V_29 ;
if ( V_184 . V_187 + V_184 . V_168 <= V_184 . V_187 )
return - V_35 ;
if ( V_184 . V_187 + V_184 . V_168 > V_41 -> V_111 ( V_2 ) )
return - V_35 ;
V_48 = F_54 ( V_188 , V_119 ) ;
if ( ! V_48 )
return - V_120 ;
V_186 = V_184 . V_168 ;
while ( V_186 > 0 ) {
V_184 . V_168 = F_55 ( V_186 , ( T_1 ) V_188 ) ;
if ( F_10 ( V_48 , V_185 , V_184 . V_168 ) ) {
V_34 = - V_29 ;
break;
}
V_34 = V_41 -> V_190 ( V_2 , & V_184 , V_48 ) ;
if ( V_34 )
break;
V_185 += V_184 . V_168 ;
V_184 . V_187 += V_184 . V_168 ;
V_186 -= V_184 . V_168 ;
}
F_31 ( V_48 ) ;
return V_34 ;
}
static T_4 int F_58 ( struct V_1 * V_2 ,
void T_2 * V_10 )
{
struct V_191 V_192 = { . V_12 = V_193 } ;
if ( ! V_2 -> V_40 -> V_194 )
return - V_46 ;
V_2 -> V_40 -> V_194 ( V_2 , & V_192 ) ;
if ( F_8 ( V_10 , & V_192 , sizeof( V_192 ) ) )
return - V_29 ;
return 0 ;
}
static T_4 int F_59 ( struct V_1 * V_2 ,
void T_2 * V_10 )
{
struct V_191 V_192 ;
if ( ! V_2 -> V_40 -> V_195 )
return - V_46 ;
if ( F_10 ( & V_192 , V_10 , sizeof( V_192 ) ) )
return - V_29 ;
return V_2 -> V_40 -> V_195 ( V_2 , & V_192 ) ;
}
static int F_60 ( struct V_1 * V_2 , void T_2 * V_10 )
{
struct V_196 V_197 = { . V_12 = V_198 } ;
if ( ! V_2 -> V_40 -> V_199 )
return - V_46 ;
V_2 -> V_40 -> V_199 ( V_2 , & V_197 ) ;
if ( F_8 ( V_10 , & V_197 , sizeof( V_197 ) ) )
return - V_29 ;
return 0 ;
}
static int F_61 ( struct V_1 * V_2 , void T_2 * V_10 )
{
struct V_196 V_197 ;
if ( ! V_2 -> V_40 -> V_200 )
return - V_46 ;
if ( F_10 ( & V_197 , V_10 , sizeof( V_197 ) ) )
return - V_29 ;
return V_2 -> V_40 -> V_200 ( V_2 , & V_197 ) ;
}
static T_4 int F_62 ( struct V_1 * V_2 ,
void T_2 * V_10 )
{
struct V_201 V_202 = { . V_12 = V_203 } ;
if ( ! V_2 -> V_40 -> V_204 )
return - V_46 ;
V_2 -> V_40 -> V_204 ( V_2 , & V_202 ) ;
if ( F_8 ( V_10 , & V_202 , sizeof( V_202 ) ) )
return - V_29 ;
return 0 ;
}
static T_4 int F_63 ( struct V_1 * V_2 ,
void T_2 * V_10 )
{
struct V_201 V_202 ;
if ( ! V_2 -> V_40 -> V_205 )
return - V_46 ;
if ( F_10 ( & V_202 , V_10 , sizeof( V_202 ) ) )
return - V_29 ;
return V_2 -> V_40 -> V_205 ( V_2 , & V_202 ) ;
}
static int F_64 ( struct V_1 * V_2 , void T_2 * V_10 )
{
struct V_206 V_207 = { V_208 } ;
if ( ! V_2 -> V_40 -> V_209 )
return - V_46 ;
V_2 -> V_40 -> V_209 ( V_2 , & V_207 ) ;
if ( F_8 ( V_10 , & V_207 , sizeof( V_207 ) ) )
return - V_29 ;
return 0 ;
}
static int F_65 ( struct V_1 * V_2 , void T_2 * V_10 )
{
struct V_206 V_207 ;
if ( ! V_2 -> V_40 -> V_210 )
return - V_46 ;
if ( F_10 ( & V_207 , V_10 , sizeof( V_207 ) ) )
return - V_29 ;
return V_2 -> V_40 -> V_210 ( V_2 , & V_207 ) ;
}
static int F_66 ( struct V_1 * V_2 , char T_2 * V_10 )
{
struct V_211 V_212 ;
const struct V_40 * V_41 = V_2 -> V_40 ;
T_5 * V_48 ;
int V_34 , V_213 ;
if ( ! V_41 -> V_214 || ! V_41 -> V_44 )
return - V_46 ;
V_213 = V_41 -> V_44 ( V_2 , V_103 ) ;
if ( V_213 < 0 )
return V_213 ;
F_67 ( V_213 == 0 ) ;
if ( F_10 ( & V_212 , V_10 , sizeof( V_212 ) ) )
return - V_29 ;
V_212 . V_168 = V_213 ;
V_48 = F_54 ( V_213 * sizeof( T_5 ) , V_119 ) ;
if ( ! V_48 )
return - V_120 ;
V_41 -> V_214 ( V_2 , & V_212 , V_48 ) ;
V_34 = - V_29 ;
if ( F_8 ( V_10 , & V_212 , sizeof( V_212 ) ) )
goto V_121;
V_10 += sizeof( V_212 ) ;
if ( F_8 ( V_10 , V_48 , V_212 . V_168 * sizeof( T_5 ) ) )
goto V_121;
V_34 = 0 ;
V_121:
F_31 ( V_48 ) ;
return V_34 ;
}
static int F_68 ( struct V_1 * V_2 , void T_2 * V_10 )
{
struct V_215 V_216 ;
T_3 * V_48 ;
int V_34 ;
if ( F_10 ( & V_216 , V_10 , sizeof( V_216 ) ) )
return - V_29 ;
V_34 = F_12 ( V_2 , V_216 . V_217 ) ;
if ( V_34 < 0 )
return V_34 ;
V_216 . V_168 = V_34 ;
V_48 = F_54 ( V_216 . V_168 * V_218 , V_119 ) ;
if ( ! V_48 )
return - V_120 ;
F_14 ( V_2 , V_216 . V_217 , V_48 ) ;
V_34 = - V_29 ;
if ( F_8 ( V_10 , & V_216 , sizeof( V_216 ) ) )
goto V_121;
V_10 += sizeof( V_216 ) ;
if ( F_8 ( V_10 , V_48 , V_216 . V_168 * V_218 ) )
goto V_121;
V_34 = 0 ;
V_121:
F_31 ( V_48 ) ;
return V_34 ;
}
static int F_69 ( struct V_1 * V_2 , void T_2 * V_10 )
{
struct V_74 V_219 ;
static bool V_220 ;
const struct V_40 * V_41 = V_2 -> V_40 ;
int V_102 ;
if ( ! V_41 -> V_221 )
return - V_46 ;
if ( V_220 )
return - V_222 ;
if ( F_10 ( & V_219 , V_10 , sizeof( V_219 ) ) )
return - V_29 ;
V_102 = V_41 -> V_221 ( V_2 , V_223 ) ;
if ( V_102 < 0 )
return V_102 ;
V_220 = true ;
F_70 ( V_2 ) ;
F_71 () ;
if ( V_102 == 0 ) {
F_72 (
V_219 . V_48 ? ( V_219 . V_48 * V_224 ) : V_225 ) ;
} else {
int V_226 = V_102 * 2 , V_20 , V_227 = V_224 / V_226 ;
do {
V_20 = V_226 ;
do {
F_73 () ;
V_102 = V_41 -> V_221 ( V_2 ,
( V_20 & 1 ) ? V_228 : V_229 ) ;
F_71 () ;
if ( V_102 )
break;
F_72 ( V_227 ) ;
} while ( ! F_74 ( V_230 ) && -- V_20 != 0 );
} while ( ! F_74 ( V_230 ) &&
( V_219 . V_48 == 0 || -- V_219 . V_48 != 0 ) );
}
F_73 () ;
F_75 ( V_2 ) ;
V_220 = false ;
( void ) V_41 -> V_221 ( V_2 , V_231 ) ;
return V_102 ;
}
static int F_76 ( struct V_1 * V_2 , void T_2 * V_10 )
{
struct V_232 V_233 ;
const struct V_40 * V_41 = V_2 -> V_40 ;
T_5 * V_48 ;
int V_34 , V_106 ;
if ( ! V_41 -> V_234 || ! V_41 -> V_44 )
return - V_46 ;
V_106 = V_41 -> V_44 ( V_2 , V_105 ) ;
if ( V_106 < 0 )
return V_106 ;
F_67 ( V_106 == 0 ) ;
if ( F_10 ( & V_233 , V_10 , sizeof( V_233 ) ) )
return - V_29 ;
V_233 . V_106 = V_106 ;
V_48 = F_54 ( V_106 * sizeof( T_5 ) , V_119 ) ;
if ( ! V_48 )
return - V_120 ;
V_41 -> V_234 ( V_2 , & V_233 , V_48 ) ;
V_34 = - V_29 ;
if ( F_8 ( V_10 , & V_233 , sizeof( V_233 ) ) )
goto V_121;
V_10 += sizeof( V_233 ) ;
if ( F_8 ( V_10 , V_48 , V_233 . V_106 * sizeof( T_5 ) ) )
goto V_121;
V_34 = 0 ;
V_121:
F_31 ( V_48 ) ;
return V_34 ;
}
static int F_77 ( struct V_1 * V_2 , void T_2 * V_10 )
{
struct V_235 V_236 ;
if ( F_10 ( & V_236 , V_10 , sizeof( V_236 ) ) )
return - V_29 ;
if ( V_236 . V_14 < V_2 -> V_237 )
return - V_238 ;
V_236 . V_14 = V_2 -> V_237 ;
if ( F_8 ( V_10 , & V_236 , sizeof( V_236 ) ) )
return - V_29 ;
V_10 += sizeof( V_236 ) ;
if ( F_8 ( V_10 , V_2 -> V_239 , V_236 . V_14 ) )
return - V_29 ;
return 0 ;
}
static int F_78 ( struct V_1 * V_2 , char T_2 * V_10 ,
T_1 V_12 , T_1 (* F_79)( struct V_1 * ) )
{
struct V_74 V_75 = { . V_12 = V_12 } ;
if ( ! F_79 )
return - V_46 ;
V_75 . V_48 = F_79 ( V_2 ) ;
if ( F_8 ( V_10 , & V_75 , sizeof( V_75 ) ) )
return - V_29 ;
return 0 ;
}
static int F_80 ( struct V_1 * V_2 , char T_2 * V_10 ,
void (* F_79)( struct V_1 * , T_1 ) )
{
struct V_74 V_75 ;
if ( ! F_79 )
return - V_46 ;
if ( F_10 ( & V_75 , V_10 , sizeof( V_75 ) ) )
return - V_29 ;
F_79 ( V_2 , V_75 . V_48 ) ;
return 0 ;
}
static int F_81 ( struct V_1 * V_2 , char T_2 * V_10 ,
int (* F_79)( struct V_1 * , T_1 ) )
{
struct V_74 V_75 ;
if ( ! F_79 )
return - V_46 ;
if ( F_10 ( & V_75 , V_10 , sizeof( V_75 ) ) )
return - V_29 ;
return F_79 ( V_2 , V_75 . V_48 ) ;
}
static T_4 int F_82 ( struct V_1 * V_2 ,
char T_2 * V_10 )
{
struct V_240 V_241 ;
if ( F_10 ( & V_241 , V_10 , sizeof( V_241 ) ) )
return - V_29 ;
if ( ! V_2 -> V_40 -> V_242 )
return - V_46 ;
V_241 . V_48 [ V_243 - 1 ] = 0 ;
return V_2 -> V_40 -> V_242 ( V_2 , & V_241 ) ;
}
static int F_83 ( struct V_1 * V_2 ,
void T_2 * V_10 )
{
struct V_244 V_245 ;
if ( ! V_2 -> V_40 -> V_246 )
return - V_46 ;
if ( F_10 ( & V_245 , V_10 , sizeof( V_245 ) ) )
return - V_29 ;
return V_2 -> V_40 -> V_246 ( V_2 , & V_245 ) ;
}
static int F_84 ( struct V_1 * V_2 ,
void T_2 * V_10 )
{
int V_34 ;
struct V_244 V_245 ;
const struct V_40 * V_41 = V_2 -> V_40 ;
if ( ! V_41 -> V_247 )
return - V_46 ;
if ( F_10 ( & V_245 , V_10 , sizeof( V_245 ) ) )
return - V_29 ;
V_34 = V_41 -> V_247 ( V_2 , & V_245 ) ;
if ( V_34 )
return V_34 ;
if ( F_8 ( V_10 , & V_245 , sizeof( V_245 ) ) )
return - V_29 ;
return 0 ;
}
static int F_85 ( struct V_1 * V_2 ,
void T_2 * V_10 )
{
int V_34 ;
T_7 V_168 ;
struct V_244 V_245 , V_248 ;
const struct V_40 * V_41 = V_2 -> V_40 ;
void * V_48 = NULL ;
if ( ! V_41 -> V_249 || ! V_41 -> V_247 )
return - V_46 ;
if ( F_10 ( & V_245 , V_10 , sizeof( V_245 ) ) )
return - V_29 ;
memset ( & V_248 , 0 , sizeof( V_248 ) ) ;
V_248 . V_12 = V_250 ;
V_34 = V_41 -> V_247 ( V_2 , & V_248 ) ;
if ( V_34 )
return V_34 ;
V_168 = F_55 ( V_248 . V_168 , V_245 . V_168 ) ;
if ( ! V_168 )
return - V_29 ;
V_245 . V_168 = V_168 ;
V_48 = F_42 ( V_248 . V_168 ) ;
if ( ! V_48 )
return - V_120 ;
V_34 = V_41 -> V_249 ( V_2 , & V_245 , V_48 ) ;
if ( V_34 )
goto V_121;
F_67 ( V_245 . V_168 != V_168 && V_245 . V_168 != V_248 . V_168 ) ;
V_245 . V_168 = V_168 ;
if ( F_8 ( V_10 , & V_245 , sizeof( V_245 ) ) ) {
V_34 = - V_29 ;
goto V_121;
}
V_10 += F_6 ( struct V_244 , V_48 ) ;
if ( F_8 ( V_10 , V_48 , V_168 ) )
V_34 = - V_29 ;
V_121:
F_43 ( V_48 ) ;
return V_34 ;
}
static int F_86 ( struct V_1 * V_2 , void T_2 * V_10 )
{
int V_93 = 0 ;
struct V_3 V_4 ;
const struct V_40 * V_41 = V_2 -> V_40 ;
struct V_251 * V_252 = V_2 -> V_252 ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
V_4 . V_12 = V_253 ;
if ( V_252 && V_252 -> V_254 && V_252 -> V_254 -> V_255 ) {
V_93 = V_252 -> V_254 -> V_255 ( V_252 , & V_4 ) ;
} else if ( V_41 -> V_256 ) {
V_93 = V_41 -> V_256 ( V_2 , & V_4 ) ;
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
static int F_87 ( struct V_1 * V_2 ,
void T_2 * V_10 )
{
int V_34 ;
struct V_257 V_258 ;
const struct V_40 * V_41 = V_2 -> V_40 ;
if ( ! V_41 -> V_259 )
return - V_46 ;
if ( F_10 ( & V_258 , V_10 , sizeof( V_258 ) ) )
return - V_29 ;
V_34 = V_41 -> V_259 ( V_2 , & V_258 ) ;
if ( V_34 )
return V_34 ;
if ( F_8 ( V_10 , & V_258 , sizeof( V_258 ) ) )
return - V_29 ;
return 0 ;
}
static int F_88 ( struct V_1 * V_2 ,
void T_2 * V_10 )
{
int V_34 ;
struct V_257 V_258 ;
const struct V_40 * V_41 = V_2 -> V_40 ;
if ( ! V_41 -> V_259 || ! V_41 -> V_260 )
return - V_46 ;
V_34 = V_41 -> V_259 ( V_2 , & V_258 ) ;
if ( V_34 )
return V_34 ;
return F_52 ( V_2 , V_10 , V_41 -> V_260 ,
V_258 . V_261 ) ;
}
static int F_89 ( const struct V_262 * V_263 )
{
switch ( V_263 -> V_219 ) {
case V_264 :
case V_265 :
if ( V_263 -> V_168 != sizeof( T_1 ) ||
V_263 -> V_266 != V_267 )
return - V_35 ;
break;
default:
return - V_35 ;
}
return 0 ;
}
static int F_90 ( struct V_1 * V_2 , void T_2 * V_10 )
{
int V_34 ;
struct V_262 V_263 ;
const struct V_40 * V_41 = V_2 -> V_40 ;
void * V_48 ;
if ( ! V_41 -> V_268 )
return - V_46 ;
if ( F_10 ( & V_263 , V_10 , sizeof( V_263 ) ) )
return - V_29 ;
V_34 = F_89 ( & V_263 ) ;
if ( V_34 )
return V_34 ;
V_48 = F_54 ( V_263 . V_168 , V_119 ) ;
if ( ! V_48 )
return - V_120 ;
V_34 = V_41 -> V_268 ( V_2 , & V_263 , V_48 ) ;
if ( V_34 )
goto V_121;
V_10 += sizeof( V_263 ) ;
V_34 = - V_29 ;
if ( F_8 ( V_10 , V_48 , V_263 . V_168 ) )
goto V_121;
V_34 = 0 ;
V_121:
F_31 ( V_48 ) ;
return V_34 ;
}
static int F_91 ( struct V_1 * V_2 , void T_2 * V_10 )
{
int V_34 ;
struct V_262 V_263 ;
const struct V_40 * V_41 = V_2 -> V_40 ;
void * V_48 ;
if ( ! V_41 -> V_269 )
return - V_46 ;
if ( F_10 ( & V_263 , V_10 , sizeof( V_263 ) ) )
return - V_29 ;
V_34 = F_89 ( & V_263 ) ;
if ( V_34 )
return V_34 ;
V_48 = F_54 ( V_263 . V_168 , V_119 ) ;
if ( ! V_48 )
return - V_120 ;
V_10 += sizeof( V_263 ) ;
V_34 = - V_29 ;
if ( F_10 ( V_48 , V_10 , V_263 . V_168 ) )
goto V_121;
V_34 = V_41 -> V_269 ( V_2 , & V_263 , V_48 ) ;
V_121:
F_31 ( V_48 ) ;
return V_34 ;
}
int F_92 ( struct V_270 * V_270 , struct V_271 * V_272 )
{
struct V_1 * V_2 = F_93 ( V_270 , V_272 -> V_273 ) ;
void T_2 * V_10 = V_272 -> V_274 ;
T_1 V_72 ;
int V_102 ;
V_21 V_275 ;
if ( ! V_2 || ! F_94 ( V_2 ) )
return - V_276 ;
if ( F_10 ( & V_72 , V_10 , sizeof( V_72 ) ) )
return - V_29 ;
switch ( V_72 ) {
case V_92 :
case V_96 :
case V_277 :
case V_180 :
case V_193 :
case V_198 :
case V_208 :
case V_54 :
case V_50 :
case V_57 :
case V_118 :
case V_278 :
case V_279 :
case V_60 :
case V_280 :
case V_63 :
case V_66 :
case V_69 :
case V_281 :
case V_282 :
case V_129 :
case V_145 :
case V_283 :
case V_284 :
case V_130 :
case V_285 :
case V_286 :
case V_13 :
case V_203 :
case V_253 :
case V_177 :
case V_287 :
break;
default:
if ( ! F_95 ( V_270 -> V_288 , V_289 ) )
return - V_290 ;
}
if ( V_2 -> V_40 -> V_291 ) {
V_102 = V_2 -> V_40 -> V_291 ( V_2 ) ;
if ( V_102 < 0 )
return V_102 ;
}
V_275 = V_2 -> V_17 ;
switch ( V_72 ) {
case V_92 :
V_102 = F_23 ( V_2 , V_10 ) ;
break;
case V_292 :
V_102 = F_24 ( V_2 , V_10 ) ;
break;
case V_96 :
V_102 = F_25 ( V_2 , V_10 ) ;
break;
case V_293 :
V_102 = F_41 ( V_2 , V_10 ) ;
break;
case V_172 :
V_102 = F_45 ( V_2 , V_10 ) ;
break;
case V_294 :
V_102 = F_46 ( V_2 , V_10 ) ;
break;
case V_277 :
V_102 = F_78 ( V_2 , V_10 , V_72 ,
V_2 -> V_40 -> V_295 ) ;
break;
case V_296 :
V_102 = F_80 ( V_2 , V_10 ,
V_2 -> V_40 -> V_297 ) ;
break;
case V_177 :
V_102 = F_47 ( V_2 , V_10 ) ;
break;
case V_298 :
V_102 = F_48 ( V_2 , V_10 ) ;
break;
case V_299 :
V_102 = F_49 ( V_2 ) ;
break;
case V_180 :
V_102 = F_50 ( V_2 , V_10 ) ;
break;
case V_300 :
V_102 = F_56 ( V_2 , V_10 ) ;
break;
case V_301 :
V_102 = F_57 ( V_2 , V_10 ) ;
break;
case V_193 :
V_102 = F_58 ( V_2 , V_10 ) ;
break;
case V_302 :
V_102 = F_59 ( V_2 , V_10 ) ;
break;
case V_198 :
V_102 = F_60 ( V_2 , V_10 ) ;
break;
case V_303 :
V_102 = F_61 ( V_2 , V_10 ) ;
break;
case V_208 :
V_102 = F_64 ( V_2 , V_10 ) ;
break;
case V_304 :
V_102 = F_65 ( V_2 , V_10 ) ;
break;
case V_305 :
V_102 = F_66 ( V_2 , V_10 ) ;
break;
case V_278 :
V_102 = F_68 ( V_2 , V_10 ) ;
break;
case V_306 :
V_102 = F_69 ( V_2 , V_10 ) ;
break;
case V_279 :
V_102 = F_76 ( V_2 , V_10 ) ;
break;
case V_280 :
V_102 = F_77 ( V_2 , V_10 ) ;
break;
case V_281 :
V_102 = F_78 ( V_2 , V_10 , V_72 ,
F_19 ) ;
break;
case V_307 :
V_102 = F_81 ( V_2 , V_10 , F_20 ) ;
break;
case V_282 :
V_102 = F_78 ( V_2 , V_10 , V_72 ,
V_2 -> V_40 -> V_308 ) ;
break;
case V_309 :
V_102 = F_81 ( V_2 , V_10 ,
V_2 -> V_40 -> V_310 ) ;
break;
case V_129 :
case V_145 :
case V_283 :
case V_284 :
case V_130 :
V_102 = F_33 ( V_2 , V_72 , V_10 ) ;
break;
case V_125 :
case V_311 :
case V_126 :
V_102 = F_32 ( V_2 , V_72 , V_10 ) ;
break;
case V_312 :
V_102 = F_82 ( V_2 , V_10 ) ;
break;
case V_313 :
V_102 = F_44 ( V_2 , V_10 ) ;
break;
case V_118 :
V_102 = F_28 ( V_2 , V_10 ) ;
break;
case V_285 :
V_102 = F_35 ( V_2 , V_10 ) ;
break;
case V_314 :
V_102 = F_37 ( V_2 , V_10 ) ;
break;
case V_286 :
V_102 = F_39 ( V_2 , V_10 ) ;
break;
case V_315 :
V_102 = F_40 ( V_2 , V_10 ) ;
break;
case V_13 :
V_102 = F_4 ( V_2 , V_10 ) ;
break;
case V_316 :
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
case V_203 :
V_102 = F_62 ( V_2 , V_10 ) ;
break;
case V_317 :
V_102 = F_63 ( V_2 , V_10 ) ;
break;
case V_318 :
V_102 = F_83 ( V_2 , V_10 ) ;
break;
case V_250 :
V_102 = F_84 ( V_2 , V_10 ) ;
break;
case V_319 :
V_102 = F_85 ( V_2 , V_10 ) ;
break;
case V_253 :
V_102 = F_86 ( V_2 , V_10 ) ;
break;
case V_320 :
V_102 = F_87 ( V_2 , V_10 ) ;
break;
case V_321 :
V_102 = F_88 ( V_2 , V_10 ) ;
break;
case V_287 :
V_102 = F_90 ( V_2 , V_10 ) ;
break;
case V_322 :
V_102 = F_91 ( V_2 , V_10 ) ;
break;
default:
V_102 = - V_46 ;
}
if ( V_2 -> V_40 -> V_323 )
V_2 -> V_40 -> V_323 ( V_2 ) ;
if ( V_275 != V_2 -> V_17 )
F_96 ( V_2 ) ;
return V_102 ;
}
