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
if ( V_39 == V_44 )
return F_13 ( V_45 ) ;
if ( V_41 -> V_46 && V_41 -> V_47 )
return V_41 -> V_46 ( V_2 , V_39 ) ;
else
return - V_48 ;
}
static void F_14 ( struct V_1 * V_2 ,
T_1 V_49 , T_3 * V_50 )
{
const struct V_40 * V_41 = V_2 -> V_40 ;
if ( V_49 == V_42 )
memcpy ( V_50 , V_43 ,
sizeof( V_43 ) ) ;
else if ( V_49 == V_44 )
memcpy ( V_50 , V_45 ,
sizeof( V_45 ) ) ;
else
V_41 -> V_47 ( V_2 , V_49 , V_50 ) ;
}
static V_21 F_15 ( T_1 V_51 )
{
switch ( V_51 ) {
case V_52 :
case V_53 :
return V_54 | V_55 ;
case V_56 :
case V_57 :
return V_58 ;
case V_59 :
case V_60 :
return V_61 ;
case V_62 :
case V_63 :
return V_64 ;
case V_65 :
case V_66 :
return V_67 ;
case V_68 :
case V_69 :
return V_70 ;
case V_71 :
case V_72 :
return V_73 ;
default:
F_16 () ;
}
}
static int F_17 ( struct V_1 * V_2 ,
char T_2 * V_10 , T_1 V_74 )
{
V_21 V_75 = F_15 ( V_74 ) ;
struct V_76 V_77 = {
. V_12 = V_74 ,
. V_50 = ! ! ( V_2 -> V_17 & V_75 ) ,
} ;
if ( F_8 ( V_10 , & V_77 , sizeof( V_77 ) ) )
return - V_29 ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
void T_2 * V_10 , T_1 V_74 )
{
struct V_76 V_77 ;
V_21 V_75 ;
if ( F_10 ( & V_77 , V_10 , sizeof( V_77 ) ) )
return - V_29 ;
V_75 = F_15 ( V_74 ) ;
V_75 &= V_2 -> V_23 ;
if ( ! V_75 )
return - V_48 ;
if ( V_77 . V_50 )
V_2 -> V_25 |= V_75 ;
else
V_2 -> V_25 &= ~ V_75 ;
F_11 ( V_2 ) ;
return 0 ;
}
static T_1 F_19 ( struct V_1 * V_2 )
{
T_1 V_78 = 0 ;
if ( V_2 -> V_17 & V_79 )
V_78 |= V_80 ;
if ( V_2 -> V_17 & V_81 )
V_78 |= V_82 ;
if ( V_2 -> V_17 & V_83 )
V_78 |= V_84 ;
if ( V_2 -> V_17 & V_85 )
V_78 |= V_86 ;
if ( V_2 -> V_17 & V_87 )
V_78 |= V_88 ;
return V_78 ;
}
static int F_20 ( struct V_1 * V_2 , T_1 V_50 )
{
V_21 V_17 = 0 , V_89 ;
if ( V_50 & ~ V_90 )
return - V_35 ;
if ( V_50 & V_80 )
V_17 |= V_79 ;
if ( V_50 & V_82 )
V_17 |= V_81 ;
if ( V_50 & V_84 )
V_17 |= V_83 ;
if ( V_50 & V_86 )
V_17 |= V_85 ;
if ( V_50 & V_88 )
V_17 |= V_87 ;
V_89 = ( V_17 ^ V_2 -> V_17 ) & V_91 ;
if ( V_89 & ~ V_2 -> V_23 )
return ( V_89 & V_2 -> V_23 ) ? - V_35 : - V_48 ;
V_2 -> V_25 =
( V_2 -> V_25 & ~ V_89 ) | ( V_17 & V_89 ) ;
F_11 ( V_2 ) ;
return 0 ;
}
int F_21 ( struct V_1 * V_2 , struct V_92 * V_12 )
{
F_22 () ;
if ( ! V_2 -> V_40 -> V_93 )
return - V_48 ;
memset ( V_12 , 0 , sizeof( struct V_92 ) ) ;
V_12 -> V_12 = V_94 ;
return V_2 -> V_40 -> V_93 ( V_2 , V_12 ) ;
}
static int F_23 ( struct V_1 * V_2 , void T_2 * V_10 )
{
int V_95 ;
struct V_92 V_12 ;
V_95 = F_21 ( V_2 , & V_12 ) ;
if ( V_95 < 0 )
return V_95 ;
if ( F_8 ( V_10 , & V_12 , sizeof( V_12 ) ) )
return - V_29 ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 , void T_2 * V_10 )
{
struct V_92 V_12 ;
if ( ! V_2 -> V_40 -> V_96 )
return - V_48 ;
if ( F_10 ( & V_12 , V_10 , sizeof( V_12 ) ) )
return - V_29 ;
return V_2 -> V_40 -> V_96 ( V_2 , & V_12 ) ;
}
static T_4 int F_25 ( struct V_1 * V_2 ,
void T_2 * V_10 )
{
struct V_97 V_4 ;
const struct V_40 * V_41 = V_2 -> V_40 ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
V_4 . V_12 = V_98 ;
if ( V_41 -> V_99 ) {
V_41 -> V_99 ( V_2 , & V_4 ) ;
} else if ( V_2 -> V_2 . V_100 && V_2 -> V_2 . V_100 -> V_101 ) {
F_26 ( V_4 . V_102 , F_27 ( V_2 -> V_2 . V_100 ) ,
sizeof( V_4 . V_102 ) ) ;
F_26 ( V_4 . V_101 , V_2 -> V_2 . V_100 -> V_101 -> V_103 ,
sizeof( V_4 . V_101 ) ) ;
} else {
return - V_48 ;
}
if ( V_41 -> V_46 ) {
int V_104 ;
V_104 = V_41 -> V_46 ( V_2 , V_105 ) ;
if ( V_104 >= 0 )
V_4 . V_106 = V_104 ;
V_104 = V_41 -> V_46 ( V_2 , V_107 ) ;
if ( V_104 >= 0 )
V_4 . V_108 = V_104 ;
V_104 = V_41 -> V_46 ( V_2 , V_109 ) ;
if ( V_104 >= 0 )
V_4 . V_110 = V_104 ;
}
if ( V_41 -> V_111 )
V_4 . V_112 = V_41 -> V_111 ( V_2 ) ;
if ( V_41 -> V_113 )
V_4 . V_114 = V_41 -> V_113 ( V_2 ) ;
if ( F_8 ( V_10 , & V_4 , sizeof( V_4 ) ) )
return - V_29 ;
return 0 ;
}
static T_4 int F_28 ( struct V_1 * V_2 ,
void T_2 * V_10 )
{
struct V_115 V_4 ;
T_5 V_116 ;
int V_20 , V_117 = 0 , V_118 = 0 , V_34 , V_104 ;
T_1 * V_119 = NULL ;
if ( F_10 ( & V_4 , V_10 , sizeof( V_4 ) ) )
return - V_29 ;
V_116 = V_4 . V_116 ;
if ( ! V_116 )
return 0 ;
V_118 = F_29 ( V_116 ) ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
V_4 . V_12 = V_120 ;
V_119 = F_30 ( V_118 * sizeof( T_1 ) , V_121 ) ;
if ( ! V_119 )
return - V_122 ;
for ( V_20 = 0 ; V_20 < 64 ; V_20 ++ ) {
if ( ! ( V_116 & ( 1ULL << V_20 ) ) )
continue;
V_104 = F_12 ( V_2 , V_20 ) ;
if ( V_104 >= 0 ) {
V_4 . V_116 |= ( 1ULL << V_20 ) ;
V_119 [ V_117 ++ ] = V_104 ;
}
}
V_34 = - V_29 ;
if ( F_8 ( V_10 , & V_4 , sizeof( V_4 ) ) )
goto V_123;
V_10 += F_6 ( struct V_115 , V_50 ) ;
if ( F_8 ( V_10 , V_119 , V_117 * sizeof( T_1 ) ) )
goto V_123;
V_34 = 0 ;
V_123:
F_31 ( V_119 ) ;
return V_34 ;
}
static T_4 int F_32 ( struct V_1 * V_2 ,
T_1 V_12 , void T_2 * V_10 )
{
struct V_124 V_4 ;
T_6 V_125 = sizeof( V_4 ) ;
int V_104 ;
if ( ! V_2 -> V_40 -> V_126 )
return - V_48 ;
if ( V_12 == V_127 )
V_125 = ( F_6 ( struct V_124 , V_50 ) +
sizeof( V_4 . V_50 ) ) ;
if ( F_10 ( & V_4 , V_10 , V_125 ) )
return - V_29 ;
V_104 = V_2 -> V_40 -> V_126 ( V_2 , & V_4 ) ;
if ( V_104 )
return V_104 ;
if ( V_12 == V_128 &&
F_8 ( V_10 , & V_4 , V_125 ) )
return - V_29 ;
return 0 ;
}
static T_4 int F_33 ( struct V_1 * V_2 ,
T_1 V_12 , void T_2 * V_10 )
{
struct V_124 V_4 ;
T_6 V_125 = sizeof( V_4 ) ;
const struct V_40 * V_41 = V_2 -> V_40 ;
int V_34 ;
void * V_129 = NULL ;
if ( ! V_41 -> V_130 )
return - V_48 ;
if ( V_12 == V_131 )
V_125 = ( F_6 ( struct V_124 , V_50 ) +
sizeof( V_4 . V_50 ) ) ;
if ( F_10 ( & V_4 , V_10 , V_125 ) )
return - V_29 ;
if ( V_4 . V_12 == V_132 ) {
if ( V_4 . V_133 > 0 ) {
if ( V_4 . V_133 <= V_134 / sizeof( T_1 ) )
V_129 = F_30 ( V_4 . V_133 * sizeof( T_1 ) ,
V_121 ) ;
if ( ! V_129 )
return - V_122 ;
}
}
V_34 = V_41 -> V_130 ( V_2 , & V_4 , V_129 ) ;
if ( V_34 < 0 )
goto V_135;
V_34 = - V_29 ;
if ( F_8 ( V_10 , & V_4 , V_125 ) )
goto V_135;
if ( V_129 ) {
V_10 += F_6 ( struct V_124 , V_136 ) ;
if ( F_8 ( V_10 , V_129 ,
V_4 . V_133 * sizeof( T_1 ) ) )
goto V_135;
}
V_34 = 0 ;
V_135:
F_31 ( V_129 ) ;
return V_34 ;
}
static int F_34 ( T_1 * V_137 , void T_2 * V_10 ,
struct V_124 * V_138 ,
T_1 V_14 )
{
int V_20 ;
if ( F_10 ( V_137 , V_10 , V_14 * sizeof( V_137 [ 0 ] ) ) )
return - V_29 ;
for ( V_20 = 0 ; V_20 < V_14 ; V_20 ++ )
if ( V_137 [ V_20 ] >= V_138 -> V_50 )
return - V_35 ;
return 0 ;
}
void F_35 ( void * V_139 , T_6 V_140 )
{
F_36 ( V_140 > sizeof( V_141 ) ) ;
F_37 ( V_141 , sizeof( V_141 ) ) ;
memcpy ( V_139 , V_141 , V_140 ) ;
}
static T_4 int F_38 ( struct V_1 * V_2 ,
void T_2 * V_10 )
{
T_1 V_142 , V_143 ;
T_1 * V_137 ;
int V_34 ;
if ( ! V_2 -> V_40 -> V_144 ||
! V_2 -> V_40 -> V_145 )
return - V_48 ;
V_143 = V_2 -> V_40 -> V_144 ( V_2 ) ;
if ( V_143 == 0 )
return - V_48 ;
if ( F_10 ( & V_142 ,
V_10 + F_6 ( struct V_146 , V_14 ) ,
sizeof( V_142 ) ) )
return - V_29 ;
if ( F_8 ( V_10 + F_6 ( struct V_146 , V_14 ) ,
& V_143 , sizeof( V_143 ) ) )
return - V_29 ;
if ( V_142 < V_143 )
return V_142 == 0 ? 0 : - V_35 ;
V_137 = F_39 ( V_143 , sizeof( V_137 [ 0 ] ) , V_121 ) ;
if ( ! V_137 )
return - V_122 ;
V_34 = V_2 -> V_40 -> V_145 ( V_2 , V_137 , NULL , NULL ) ;
if ( V_34 )
goto V_123;
if ( F_8 ( V_10 +
F_6 ( struct V_146 , V_147 [ 0 ] ) ,
V_137 , V_143 * sizeof( V_137 [ 0 ] ) ) )
V_34 = - V_29 ;
V_123:
F_31 ( V_137 ) ;
return V_34 ;
}
static T_4 int F_40 ( struct V_1 * V_2 ,
void T_2 * V_10 )
{
struct V_124 V_138 ;
T_1 V_142 , V_143 , V_20 ;
T_1 * V_137 ;
const struct V_40 * V_41 = V_2 -> V_40 ;
int V_34 ;
T_1 V_148 = F_6 ( struct V_146 , V_147 [ 0 ] ) ;
if ( ! V_41 -> V_144 || ! V_41 -> V_149 ||
! V_41 -> V_130 )
return - V_48 ;
V_143 = V_41 -> V_144 ( V_2 ) ;
if ( V_143 == 0 )
return - V_48 ;
if ( F_10 ( & V_142 ,
V_10 + F_6 ( struct V_146 , V_14 ) ,
sizeof( V_142 ) ) )
return - V_29 ;
if ( V_142 != 0 && V_142 != V_143 )
return - V_35 ;
V_137 = F_39 ( V_143 , sizeof( V_137 [ 0 ] ) , V_121 ) ;
if ( ! V_137 )
return - V_122 ;
V_138 . V_12 = V_150 ;
V_34 = V_41 -> V_130 ( V_2 , & V_138 , NULL ) ;
if ( V_34 )
goto V_123;
if ( V_142 == 0 ) {
for ( V_20 = 0 ; V_20 < V_143 ; V_20 ++ )
V_137 [ V_20 ] = F_41 ( V_20 , V_138 . V_50 ) ;
} else {
V_34 = F_34 ( V_137 ,
V_10 + V_148 ,
& V_138 ,
V_143 ) ;
if ( V_34 )
goto V_123;
}
V_34 = V_41 -> V_149 ( V_2 , V_137 , NULL , V_151 ) ;
V_123:
F_31 ( V_137 ) ;
return V_34 ;
}
static T_4 int F_42 ( struct V_1 * V_2 ,
void T_2 * V_10 )
{
int V_34 ;
const struct V_40 * V_41 = V_2 -> V_40 ;
T_1 V_152 , V_153 ;
T_1 V_154 = 0 , V_155 = 0 ;
struct V_156 V_157 ;
T_1 V_158 ;
T_1 V_159 ;
T_1 * V_137 = NULL ;
T_3 V_160 = 0 ;
T_3 * V_161 = NULL ;
T_3 * V_162 ;
if ( ! V_41 -> V_145 )
return - V_48 ;
if ( V_41 -> V_144 )
V_154 = V_41 -> V_144 ( V_2 ) ;
if ( V_41 -> V_163 )
V_155 = V_41 -> V_163 ( V_2 ) ;
if ( F_10 ( & V_157 , V_10 , sizeof( V_157 ) ) )
return - V_29 ;
V_152 = V_157 . V_164 ;
V_153 = V_157 . V_165 ;
if ( V_157 . V_166 || V_157 . V_167 [ 0 ] || V_157 . V_167 [ 1 ] ||
V_157 . V_167 [ 2 ] || V_157 . V_168 )
return - V_35 ;
V_157 . V_164 = V_154 ;
V_157 . V_165 = V_155 ;
if ( F_8 ( V_10 , & V_157 , sizeof( V_157 ) ) )
return - V_29 ;
if ( ( V_152 && ( V_152 != V_154 ) ) ||
( V_153 && ( V_153 != V_155 ) ) )
return - V_35 ;
V_159 = V_152 * sizeof( V_137 [ 0 ] ) ;
V_158 = V_159 + V_153 ;
V_162 = F_30 ( V_158 , V_121 ) ;
if ( ! V_162 )
return - V_122 ;
if ( V_152 )
V_137 = ( T_1 * ) V_162 ;
if ( V_153 )
V_161 = V_162 + V_159 ;
V_34 = V_2 -> V_40 -> V_145 ( V_2 , V_137 , V_161 , & V_160 ) ;
if ( V_34 )
goto V_123;
if ( F_8 ( V_10 + F_6 ( struct V_156 , V_169 ) ,
& V_160 , sizeof( V_157 . V_169 ) ) ) {
V_34 = - V_29 ;
} else if ( F_8 ( V_10 +
F_6 ( struct V_156 , V_162 [ 0 ] ) ,
V_162 , V_158 ) ) {
V_34 = - V_29 ;
}
V_123:
F_31 ( V_162 ) ;
return V_34 ;
}
static T_4 int F_43 ( struct V_1 * V_2 ,
void T_2 * V_10 )
{
int V_34 ;
const struct V_40 * V_41 = V_2 -> V_40 ;
struct V_124 V_138 ;
struct V_156 V_157 ;
T_1 V_154 = 0 , V_155 = 0 , V_20 ;
T_1 * V_137 = NULL , V_159 = 0 ;
T_3 * V_161 = NULL ;
T_3 * V_162 ;
T_1 V_170 = F_6 ( struct V_156 , V_162 [ 0 ] ) ;
if ( ! V_41 -> V_130 || ! V_41 -> V_149 )
return - V_48 ;
if ( V_41 -> V_144 )
V_154 = V_41 -> V_144 ( V_2 ) ;
if ( V_41 -> V_163 )
V_155 = V_2 -> V_40 -> V_163 ( V_2 ) ;
if ( F_10 ( & V_157 , V_10 , sizeof( V_157 ) ) )
return - V_29 ;
if ( V_157 . V_166 || V_157 . V_167 [ 0 ] || V_157 . V_167 [ 1 ] ||
V_157 . V_167 [ 2 ] || V_157 . V_168 )
return - V_35 ;
if ( ( V_157 . V_164 &&
V_157 . V_164 != V_171 &&
V_157 . V_164 != V_154 ) ||
( V_157 . V_165 && ( V_157 . V_165 != V_155 ) ) ||
( V_157 . V_164 == V_171 &&
V_157 . V_165 == 0 && V_157 . V_169 == V_151 ) )
return - V_35 ;
if ( V_157 . V_164 != V_171 )
V_159 = V_154 * sizeof( V_137 [ 0 ] ) ;
V_162 = F_30 ( V_159 + V_157 . V_165 , V_121 ) ;
if ( ! V_162 )
return - V_122 ;
V_138 . V_12 = V_150 ;
V_34 = V_41 -> V_130 ( V_2 , & V_138 , NULL ) ;
if ( V_34 )
goto V_123;
if ( V_157 . V_164 &&
V_157 . V_164 != V_171 ) {
V_137 = ( T_1 * ) V_162 ;
V_34 = F_34 ( V_137 ,
V_10 + V_170 ,
& V_138 ,
V_157 . V_164 ) ;
if ( V_34 )
goto V_123;
} else if ( V_157 . V_164 == 0 ) {
V_137 = ( T_1 * ) V_162 ;
for ( V_20 = 0 ; V_20 < V_154 ; V_20 ++ )
V_137 [ V_20 ] = F_41 ( V_20 , V_138 . V_50 ) ;
}
if ( V_157 . V_165 ) {
V_161 = V_162 + V_159 ;
if ( F_10 ( V_161 ,
V_10 + V_170 + V_159 ,
V_157 . V_165 ) ) {
V_34 = - V_29 ;
goto V_123;
}
}
V_34 = V_41 -> V_149 ( V_2 , V_137 , V_161 , V_157 . V_169 ) ;
V_123:
F_31 ( V_162 ) ;
return V_34 ;
}
static int F_44 ( struct V_1 * V_2 , char T_2 * V_10 )
{
struct V_172 V_173 ;
const struct V_40 * V_41 = V_2 -> V_40 ;
void * V_174 ;
int V_175 , V_34 ;
if ( ! V_41 -> V_176 || ! V_41 -> V_111 )
return - V_48 ;
if ( F_10 ( & V_173 , V_10 , sizeof( V_173 ) ) )
return - V_29 ;
V_175 = V_41 -> V_111 ( V_2 ) ;
if ( V_173 . V_140 > V_175 )
V_173 . V_140 = V_175 ;
V_174 = F_45 ( V_175 ) ;
if ( V_175 && ! V_174 )
return - V_122 ;
V_41 -> V_176 ( V_2 , & V_173 , V_174 ) ;
V_34 = - V_29 ;
if ( F_8 ( V_10 , & V_173 , sizeof( V_173 ) ) )
goto V_123;
V_10 += F_6 ( struct V_172 , V_50 ) ;
if ( V_174 && F_8 ( V_10 , V_174 , V_173 . V_140 ) )
goto V_123;
V_34 = 0 ;
V_123:
F_46 ( V_174 ) ;
return V_34 ;
}
static int F_47 ( struct V_1 * V_2 , char T_2 * V_10 )
{
struct V_76 V_177 ;
int V_34 ;
if ( ! V_2 -> V_40 -> V_177 )
return - V_48 ;
if ( F_10 ( & V_177 , V_10 , sizeof( V_177 ) ) )
return - V_29 ;
V_34 = V_2 -> V_40 -> V_177 ( V_2 , & V_177 . V_50 ) ;
if ( V_34 )
return V_34 ;
if ( F_8 ( V_10 , & V_177 , sizeof( V_177 ) ) )
return - V_29 ;
return 0 ;
}
static int F_48 ( struct V_1 * V_2 , char T_2 * V_10 )
{
struct V_178 V_179 = { . V_12 = V_180 } ;
if ( ! V_2 -> V_40 -> V_181 )
return - V_48 ;
V_2 -> V_40 -> V_181 ( V_2 , & V_179 ) ;
if ( F_8 ( V_10 , & V_179 , sizeof( V_179 ) ) )
return - V_29 ;
return 0 ;
}
static int F_49 ( struct V_1 * V_2 , char T_2 * V_10 )
{
struct V_178 V_179 ;
if ( ! V_2 -> V_40 -> V_182 )
return - V_48 ;
if ( F_10 ( & V_179 , V_10 , sizeof( V_179 ) ) )
return - V_29 ;
return V_2 -> V_40 -> V_182 ( V_2 , & V_179 ) ;
}
static int F_50 ( struct V_1 * V_2 , char T_2 * V_10 )
{
struct V_183 V_77 ;
int V_104 ;
if ( ! V_2 -> V_40 -> V_184 )
return - V_48 ;
memset ( & V_77 , 0 , sizeof( struct V_183 ) ) ;
V_77 . V_12 = V_185 ;
V_104 = V_2 -> V_40 -> V_184 ( V_2 , & V_77 ) ;
if ( V_104 )
return V_104 ;
if ( F_8 ( V_10 , & V_77 , sizeof( V_77 ) ) )
return - V_29 ;
return 0 ;
}
static int F_51 ( struct V_1 * V_2 , char T_2 * V_10 )
{
struct V_183 V_77 ;
if ( ! V_2 -> V_40 -> V_186 )
return - V_48 ;
if ( F_10 ( & V_77 , V_10 , sizeof( V_77 ) ) )
return - V_29 ;
return V_2 -> V_40 -> V_186 ( V_2 , & V_77 ) ;
}
static int F_52 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_40 -> V_187 )
return - V_48 ;
return V_2 -> V_40 -> V_187 ( V_2 ) ;
}
static int F_53 ( struct V_1 * V_2 , char T_2 * V_10 )
{
struct V_76 V_77 = { . V_12 = V_188 } ;
if ( ! V_2 -> V_40 -> V_189 )
return - V_48 ;
V_77 . V_50 = F_54 ( V_2 ) && V_2 -> V_40 -> V_189 ( V_2 ) ;
if ( F_8 ( V_10 , & V_77 , sizeof( V_77 ) ) )
return - V_29 ;
return 0 ;
}
static int F_55 ( struct V_1 * V_2 , void T_2 * V_10 ,
int (* F_56)( struct V_1 * ,
struct V_190 * , T_3 * ) ,
T_1 V_191 )
{
struct V_190 V_192 ;
void T_2 * V_193 = V_10 + sizeof( V_192 ) ;
T_1 V_194 ;
T_3 * V_50 ;
int V_34 = 0 ;
if ( F_10 ( & V_192 , V_10 , sizeof( V_192 ) ) )
return - V_29 ;
if ( V_192 . V_195 + V_192 . V_140 <= V_192 . V_195 )
return - V_35 ;
if ( V_192 . V_195 + V_192 . V_140 > V_191 )
return - V_35 ;
V_50 = F_57 ( V_196 , V_121 ) ;
if ( ! V_50 )
return - V_122 ;
V_194 = V_192 . V_140 ;
while ( V_194 > 0 ) {
V_192 . V_140 = F_58 ( V_194 , ( T_1 ) V_196 ) ;
V_34 = F_56 ( V_2 , & V_192 , V_50 ) ;
if ( V_34 )
break;
if ( F_8 ( V_193 , V_50 , V_192 . V_140 ) ) {
V_34 = - V_29 ;
break;
}
V_193 += V_192 . V_140 ;
V_192 . V_195 += V_192 . V_140 ;
V_194 -= V_192 . V_140 ;
}
V_192 . V_140 = V_193 - ( V_10 + sizeof( V_192 ) ) ;
V_192 . V_195 -= V_192 . V_140 ;
if ( F_8 ( V_10 , & V_192 , sizeof( V_192 ) ) )
V_34 = - V_29 ;
F_31 ( V_50 ) ;
return V_34 ;
}
static int F_59 ( struct V_1 * V_2 , void T_2 * V_10 )
{
const struct V_40 * V_41 = V_2 -> V_40 ;
if ( ! V_41 -> V_197 || ! V_41 -> V_113 ||
! V_41 -> V_113 ( V_2 ) )
return - V_48 ;
return F_55 ( V_2 , V_10 , V_41 -> V_197 ,
V_41 -> V_113 ( V_2 ) ) ;
}
static int F_60 ( struct V_1 * V_2 , void T_2 * V_10 )
{
struct V_190 V_192 ;
const struct V_40 * V_41 = V_2 -> V_40 ;
void T_2 * V_193 = V_10 + sizeof( V_192 ) ;
T_1 V_194 ;
T_3 * V_50 ;
int V_34 = 0 ;
if ( ! V_41 -> V_198 || ! V_41 -> V_113 ||
! V_41 -> V_113 ( V_2 ) )
return - V_48 ;
if ( F_10 ( & V_192 , V_10 , sizeof( V_192 ) ) )
return - V_29 ;
if ( V_192 . V_195 + V_192 . V_140 <= V_192 . V_195 )
return - V_35 ;
if ( V_192 . V_195 + V_192 . V_140 > V_41 -> V_113 ( V_2 ) )
return - V_35 ;
V_50 = F_57 ( V_196 , V_121 ) ;
if ( ! V_50 )
return - V_122 ;
V_194 = V_192 . V_140 ;
while ( V_194 > 0 ) {
V_192 . V_140 = F_58 ( V_194 , ( T_1 ) V_196 ) ;
if ( F_10 ( V_50 , V_193 , V_192 . V_140 ) ) {
V_34 = - V_29 ;
break;
}
V_34 = V_41 -> V_198 ( V_2 , & V_192 , V_50 ) ;
if ( V_34 )
break;
V_193 += V_192 . V_140 ;
V_192 . V_195 += V_192 . V_140 ;
V_194 -= V_192 . V_140 ;
}
F_31 ( V_50 ) ;
return V_34 ;
}
static T_4 int F_61 ( struct V_1 * V_2 ,
void T_2 * V_10 )
{
struct V_199 V_200 = { . V_12 = V_201 } ;
if ( ! V_2 -> V_40 -> V_202 )
return - V_48 ;
V_2 -> V_40 -> V_202 ( V_2 , & V_200 ) ;
if ( F_8 ( V_10 , & V_200 , sizeof( V_200 ) ) )
return - V_29 ;
return 0 ;
}
static T_4 int F_62 ( struct V_1 * V_2 ,
void T_2 * V_10 )
{
struct V_199 V_200 ;
if ( ! V_2 -> V_40 -> V_203 )
return - V_48 ;
if ( F_10 ( & V_200 , V_10 , sizeof( V_200 ) ) )
return - V_29 ;
return V_2 -> V_40 -> V_203 ( V_2 , & V_200 ) ;
}
static int F_63 ( struct V_1 * V_2 , void T_2 * V_10 )
{
struct V_204 V_205 = { . V_12 = V_206 } ;
if ( ! V_2 -> V_40 -> V_207 )
return - V_48 ;
V_2 -> V_40 -> V_207 ( V_2 , & V_205 ) ;
if ( F_8 ( V_10 , & V_205 , sizeof( V_205 ) ) )
return - V_29 ;
return 0 ;
}
static int F_64 ( struct V_1 * V_2 , void T_2 * V_10 )
{
struct V_204 V_205 ;
if ( ! V_2 -> V_40 -> V_208 )
return - V_48 ;
if ( F_10 ( & V_205 , V_10 , sizeof( V_205 ) ) )
return - V_29 ;
return V_2 -> V_40 -> V_208 ( V_2 , & V_205 ) ;
}
static T_4 int F_65 ( struct V_1 * V_2 ,
void T_2 * V_10 )
{
struct V_209 V_210 = { . V_12 = V_211 } ;
if ( ! V_2 -> V_40 -> V_212 )
return - V_48 ;
V_2 -> V_40 -> V_212 ( V_2 , & V_210 ) ;
if ( F_8 ( V_10 , & V_210 , sizeof( V_210 ) ) )
return - V_29 ;
return 0 ;
}
static T_4 int F_66 ( struct V_1 * V_2 ,
void T_2 * V_10 )
{
struct V_209 V_210 ;
if ( ! V_2 -> V_40 -> V_213 )
return - V_48 ;
if ( F_10 ( & V_210 , V_10 , sizeof( V_210 ) ) )
return - V_29 ;
return V_2 -> V_40 -> V_213 ( V_2 , & V_210 ) ;
}
static int F_67 ( struct V_1 * V_2 , void T_2 * V_10 )
{
struct V_214 V_215 = { V_216 } ;
if ( ! V_2 -> V_40 -> V_217 )
return - V_48 ;
V_2 -> V_40 -> V_217 ( V_2 , & V_215 ) ;
if ( F_8 ( V_10 , & V_215 , sizeof( V_215 ) ) )
return - V_29 ;
return 0 ;
}
static int F_68 ( struct V_1 * V_2 , void T_2 * V_10 )
{
struct V_214 V_215 ;
if ( ! V_2 -> V_40 -> V_218 )
return - V_48 ;
if ( F_10 ( & V_215 , V_10 , sizeof( V_215 ) ) )
return - V_29 ;
return V_2 -> V_40 -> V_218 ( V_2 , & V_215 ) ;
}
static int F_69 ( struct V_1 * V_2 , char T_2 * V_10 )
{
struct V_219 V_220 ;
const struct V_40 * V_41 = V_2 -> V_40 ;
T_5 * V_50 ;
int V_34 , V_221 ;
if ( ! V_41 -> V_222 || ! V_41 -> V_46 )
return - V_48 ;
V_221 = V_41 -> V_46 ( V_2 , V_105 ) ;
if ( V_221 < 0 )
return V_221 ;
F_70 ( V_221 == 0 ) ;
if ( F_10 ( & V_220 , V_10 , sizeof( V_220 ) ) )
return - V_29 ;
V_220 . V_140 = V_221 ;
V_50 = F_57 ( V_221 * sizeof( T_5 ) , V_121 ) ;
if ( ! V_50 )
return - V_122 ;
V_41 -> V_222 ( V_2 , & V_220 , V_50 ) ;
V_34 = - V_29 ;
if ( F_8 ( V_10 , & V_220 , sizeof( V_220 ) ) )
goto V_123;
V_10 += sizeof( V_220 ) ;
if ( F_8 ( V_10 , V_50 , V_220 . V_140 * sizeof( T_5 ) ) )
goto V_123;
V_34 = 0 ;
V_123:
F_31 ( V_50 ) ;
return V_34 ;
}
static int F_71 ( struct V_1 * V_2 , void T_2 * V_10 )
{
struct V_223 V_224 ;
T_3 * V_50 ;
int V_34 ;
if ( F_10 ( & V_224 , V_10 , sizeof( V_224 ) ) )
return - V_29 ;
V_34 = F_12 ( V_2 , V_224 . V_225 ) ;
if ( V_34 < 0 )
return V_34 ;
V_224 . V_140 = V_34 ;
V_50 = F_57 ( V_224 . V_140 * V_226 , V_121 ) ;
if ( ! V_50 )
return - V_122 ;
F_14 ( V_2 , V_224 . V_225 , V_50 ) ;
V_34 = - V_29 ;
if ( F_8 ( V_10 , & V_224 , sizeof( V_224 ) ) )
goto V_123;
V_10 += sizeof( V_224 ) ;
if ( F_8 ( V_10 , V_50 , V_224 . V_140 * V_226 ) )
goto V_123;
V_34 = 0 ;
V_123:
F_31 ( V_50 ) ;
return V_34 ;
}
static int F_72 ( struct V_1 * V_2 , void T_2 * V_10 )
{
struct V_76 V_227 ;
static bool V_228 ;
const struct V_40 * V_41 = V_2 -> V_40 ;
int V_104 ;
if ( ! V_41 -> V_229 )
return - V_48 ;
if ( V_228 )
return - V_230 ;
if ( F_10 ( & V_227 , V_10 , sizeof( V_227 ) ) )
return - V_29 ;
V_104 = V_41 -> V_229 ( V_2 , V_231 ) ;
if ( V_104 < 0 )
return V_104 ;
V_228 = true ;
F_73 ( V_2 ) ;
F_74 () ;
if ( V_104 == 0 ) {
F_75 (
V_227 . V_50 ? ( V_227 . V_50 * V_232 ) : V_233 ) ;
} else {
int V_234 = V_104 * 2 , V_20 , V_235 = V_232 / V_234 ;
do {
V_20 = V_234 ;
do {
F_76 () ;
V_104 = V_41 -> V_229 ( V_2 ,
( V_20 & 1 ) ? V_236 : V_237 ) ;
F_74 () ;
if ( V_104 )
break;
F_75 ( V_235 ) ;
} while ( ! F_77 ( V_238 ) && -- V_20 != 0 );
} while ( ! F_77 ( V_238 ) &&
( V_227 . V_50 == 0 || -- V_227 . V_50 != 0 ) );
}
F_76 () ;
F_78 ( V_2 ) ;
V_228 = false ;
( void ) V_41 -> V_229 ( V_2 , V_239 ) ;
return V_104 ;
}
static int F_79 ( struct V_1 * V_2 , void T_2 * V_10 )
{
struct V_240 V_241 ;
const struct V_40 * V_41 = V_2 -> V_40 ;
T_5 * V_50 ;
int V_34 , V_108 ;
if ( ! V_41 -> V_242 || ! V_41 -> V_46 )
return - V_48 ;
V_108 = V_41 -> V_46 ( V_2 , V_107 ) ;
if ( V_108 < 0 )
return V_108 ;
F_70 ( V_108 == 0 ) ;
if ( F_10 ( & V_241 , V_10 , sizeof( V_241 ) ) )
return - V_29 ;
V_241 . V_108 = V_108 ;
V_50 = F_57 ( V_108 * sizeof( T_5 ) , V_121 ) ;
if ( ! V_50 )
return - V_122 ;
V_41 -> V_242 ( V_2 , & V_241 , V_50 ) ;
V_34 = - V_29 ;
if ( F_8 ( V_10 , & V_241 , sizeof( V_241 ) ) )
goto V_123;
V_10 += sizeof( V_241 ) ;
if ( F_8 ( V_10 , V_50 , V_241 . V_108 * sizeof( T_5 ) ) )
goto V_123;
V_34 = 0 ;
V_123:
F_31 ( V_50 ) ;
return V_34 ;
}
static int F_80 ( struct V_1 * V_2 , void T_2 * V_10 )
{
struct V_243 V_244 ;
if ( F_10 ( & V_244 , V_10 , sizeof( V_244 ) ) )
return - V_29 ;
if ( V_244 . V_14 < V_2 -> V_245 )
return - V_246 ;
V_244 . V_14 = V_2 -> V_245 ;
if ( F_8 ( V_10 , & V_244 , sizeof( V_244 ) ) )
return - V_29 ;
V_10 += sizeof( V_244 ) ;
if ( F_8 ( V_10 , V_2 -> V_247 , V_244 . V_14 ) )
return - V_29 ;
return 0 ;
}
static int F_81 ( struct V_1 * V_2 , char T_2 * V_10 ,
T_1 V_12 , T_1 (* F_82)( struct V_1 * ) )
{
struct V_76 V_77 = { . V_12 = V_12 } ;
if ( ! F_82 )
return - V_48 ;
V_77 . V_50 = F_82 ( V_2 ) ;
if ( F_8 ( V_10 , & V_77 , sizeof( V_77 ) ) )
return - V_29 ;
return 0 ;
}
static int F_83 ( struct V_1 * V_2 , char T_2 * V_10 ,
void (* F_82)( struct V_1 * , T_1 ) )
{
struct V_76 V_77 ;
if ( ! F_82 )
return - V_48 ;
if ( F_10 ( & V_77 , V_10 , sizeof( V_77 ) ) )
return - V_29 ;
F_82 ( V_2 , V_77 . V_50 ) ;
return 0 ;
}
static int F_84 ( struct V_1 * V_2 , char T_2 * V_10 ,
int (* F_82)( struct V_1 * , T_1 ) )
{
struct V_76 V_77 ;
if ( ! F_82 )
return - V_48 ;
if ( F_10 ( & V_77 , V_10 , sizeof( V_77 ) ) )
return - V_29 ;
return F_82 ( V_2 , V_77 . V_50 ) ;
}
static T_4 int F_85 ( struct V_1 * V_2 ,
char T_2 * V_10 )
{
struct V_248 V_249 ;
if ( F_10 ( & V_249 , V_10 , sizeof( V_249 ) ) )
return - V_29 ;
if ( ! V_2 -> V_40 -> V_250 )
return - V_48 ;
V_249 . V_50 [ V_251 - 1 ] = 0 ;
return V_2 -> V_40 -> V_250 ( V_2 , & V_249 ) ;
}
static int F_86 ( struct V_1 * V_2 ,
void T_2 * V_10 )
{
struct V_252 V_253 ;
if ( ! V_2 -> V_40 -> V_254 )
return - V_48 ;
if ( F_10 ( & V_253 , V_10 , sizeof( V_253 ) ) )
return - V_29 ;
return V_2 -> V_40 -> V_254 ( V_2 , & V_253 ) ;
}
static int F_87 ( struct V_1 * V_2 ,
void T_2 * V_10 )
{
int V_34 ;
struct V_252 V_253 ;
const struct V_40 * V_41 = V_2 -> V_40 ;
if ( ! V_41 -> V_255 )
return - V_48 ;
if ( F_10 ( & V_253 , V_10 , sizeof( V_253 ) ) )
return - V_29 ;
V_34 = V_41 -> V_255 ( V_2 , & V_253 ) ;
if ( V_34 )
return V_34 ;
if ( F_8 ( V_10 , & V_253 , sizeof( V_253 ) ) )
return - V_29 ;
return 0 ;
}
static int F_88 ( struct V_1 * V_2 ,
void T_2 * V_10 )
{
int V_34 ;
T_7 V_140 ;
struct V_252 V_253 , V_256 ;
const struct V_40 * V_41 = V_2 -> V_40 ;
void * V_50 = NULL ;
if ( ! V_41 -> V_257 || ! V_41 -> V_255 )
return - V_48 ;
if ( F_10 ( & V_253 , V_10 , sizeof( V_253 ) ) )
return - V_29 ;
memset ( & V_256 , 0 , sizeof( V_256 ) ) ;
V_256 . V_12 = V_258 ;
V_34 = V_41 -> V_255 ( V_2 , & V_256 ) ;
if ( V_34 )
return V_34 ;
V_140 = F_58 ( V_256 . V_140 , V_253 . V_140 ) ;
if ( ! V_140 )
return - V_29 ;
V_253 . V_140 = V_140 ;
V_50 = F_45 ( V_256 . V_140 ) ;
if ( ! V_50 )
return - V_122 ;
V_34 = V_41 -> V_257 ( V_2 , & V_253 , V_50 ) ;
if ( V_34 )
goto V_123;
F_70 ( V_253 . V_140 != V_140 && V_253 . V_140 != V_256 . V_140 ) ;
V_253 . V_140 = V_140 ;
if ( F_8 ( V_10 , & V_253 , sizeof( V_253 ) ) ) {
V_34 = - V_29 ;
goto V_123;
}
V_10 += F_6 ( struct V_252 , V_50 ) ;
if ( F_8 ( V_10 , V_50 , V_140 ) )
V_34 = - V_29 ;
V_123:
F_46 ( V_50 ) ;
return V_34 ;
}
static int F_89 ( struct V_1 * V_2 , void T_2 * V_10 )
{
int V_95 = 0 ;
struct V_3 V_4 ;
const struct V_40 * V_41 = V_2 -> V_40 ;
struct V_259 * V_260 = V_2 -> V_260 ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
V_4 . V_12 = V_261 ;
if ( V_260 && V_260 -> V_262 && V_260 -> V_262 -> V_263 ) {
V_95 = V_260 -> V_262 -> V_263 ( V_260 , & V_4 ) ;
} else if ( V_41 -> V_264 ) {
V_95 = V_41 -> V_264 ( V_2 , & V_4 ) ;
} else {
V_4 . V_5 =
V_7 |
V_8 ;
V_4 . V_9 = - 1 ;
}
if ( V_95 )
return V_95 ;
if ( F_8 ( V_10 , & V_4 , sizeof( V_4 ) ) )
V_95 = - V_29 ;
return V_95 ;
}
static int F_90 ( struct V_1 * V_2 ,
struct V_265 * V_266 )
{
const struct V_40 * V_41 = V_2 -> V_40 ;
struct V_259 * V_260 = V_2 -> V_260 ;
if ( V_260 && V_260 -> V_262 && V_260 -> V_262 -> V_267 )
return V_260 -> V_262 -> V_267 ( V_260 , V_266 ) ;
if ( V_41 -> V_268 )
return V_41 -> V_268 ( V_2 , V_266 ) ;
return - V_48 ;
}
static int F_91 ( struct V_1 * V_2 ,
void T_2 * V_10 )
{
int V_34 ;
struct V_265 V_266 ;
if ( F_10 ( & V_266 , V_10 , sizeof( V_266 ) ) )
return - V_29 ;
V_34 = F_90 ( V_2 , & V_266 ) ;
if ( V_34 )
return V_34 ;
if ( F_8 ( V_10 , & V_266 , sizeof( V_266 ) ) )
return - V_29 ;
return 0 ;
}
static int F_92 ( struct V_1 * V_2 ,
struct V_190 * V_269 , T_3 * V_50 )
{
const struct V_40 * V_41 = V_2 -> V_40 ;
struct V_259 * V_260 = V_2 -> V_260 ;
if ( V_260 && V_260 -> V_262 && V_260 -> V_262 -> V_270 )
return V_260 -> V_262 -> V_270 ( V_260 , V_269 , V_50 ) ;
if ( V_41 -> V_271 )
return V_41 -> V_271 ( V_2 , V_269 , V_50 ) ;
return - V_48 ;
}
static int F_93 ( struct V_1 * V_2 ,
void T_2 * V_10 )
{
int V_34 ;
struct V_265 V_266 ;
V_34 = F_90 ( V_2 , & V_266 ) ;
if ( V_34 )
return V_34 ;
return F_55 ( V_2 , V_10 ,
F_92 ,
V_266 . V_272 ) ;
}
static int F_94 ( const struct V_273 * V_274 )
{
switch ( V_274 -> V_227 ) {
case V_275 :
case V_276 :
if ( V_274 -> V_140 != sizeof( T_1 ) ||
V_274 -> V_277 != V_278 )
return - V_35 ;
break;
default:
return - V_35 ;
}
return 0 ;
}
static int F_95 ( struct V_1 * V_2 , void T_2 * V_10 )
{
int V_34 ;
struct V_273 V_274 ;
const struct V_40 * V_41 = V_2 -> V_40 ;
void * V_50 ;
if ( ! V_41 -> V_279 )
return - V_48 ;
if ( F_10 ( & V_274 , V_10 , sizeof( V_274 ) ) )
return - V_29 ;
V_34 = F_94 ( & V_274 ) ;
if ( V_34 )
return V_34 ;
V_50 = F_57 ( V_274 . V_140 , V_121 ) ;
if ( ! V_50 )
return - V_122 ;
V_34 = V_41 -> V_279 ( V_2 , & V_274 , V_50 ) ;
if ( V_34 )
goto V_123;
V_10 += sizeof( V_274 ) ;
V_34 = - V_29 ;
if ( F_8 ( V_10 , V_50 , V_274 . V_140 ) )
goto V_123;
V_34 = 0 ;
V_123:
F_31 ( V_50 ) ;
return V_34 ;
}
static int F_96 ( struct V_1 * V_2 , void T_2 * V_10 )
{
int V_34 ;
struct V_273 V_274 ;
const struct V_40 * V_41 = V_2 -> V_40 ;
void * V_50 ;
if ( ! V_41 -> V_280 )
return - V_48 ;
if ( F_10 ( & V_274 , V_10 , sizeof( V_274 ) ) )
return - V_29 ;
V_34 = F_94 ( & V_274 ) ;
if ( V_34 )
return V_34 ;
V_50 = F_57 ( V_274 . V_140 , V_121 ) ;
if ( ! V_50 )
return - V_122 ;
V_10 += sizeof( V_274 ) ;
V_34 = - V_29 ;
if ( F_10 ( V_50 , V_10 , V_274 . V_140 ) )
goto V_123;
V_34 = V_41 -> V_280 ( V_2 , & V_274 , V_50 ) ;
V_123:
F_31 ( V_50 ) ;
return V_34 ;
}
int F_97 ( struct V_281 * V_281 , struct V_282 * V_283 )
{
struct V_1 * V_2 = F_98 ( V_281 , V_283 -> V_284 ) ;
void T_2 * V_10 = V_283 -> V_285 ;
T_1 V_74 ;
int V_104 ;
V_21 V_286 ;
if ( ! V_2 || ! F_99 ( V_2 ) )
return - V_287 ;
if ( F_10 ( & V_74 , V_10 , sizeof( V_74 ) ) )
return - V_29 ;
switch ( V_74 ) {
case V_94 :
case V_98 :
case V_288 :
case V_188 :
case V_201 :
case V_206 :
case V_216 :
case V_56 :
case V_52 :
case V_59 :
case V_120 :
case V_289 :
case V_290 :
case V_62 :
case V_291 :
case V_65 :
case V_68 :
case V_71 :
case V_292 :
case V_293 :
case V_131 :
case V_150 :
case V_294 :
case V_295 :
case V_132 :
case V_296 :
case V_297 :
case V_13 :
case V_211 :
case V_261 :
case V_185 :
case V_298 :
break;
default:
if ( ! F_100 ( V_281 -> V_299 , V_300 ) )
return - V_301 ;
}
if ( V_2 -> V_40 -> V_302 ) {
V_104 = V_2 -> V_40 -> V_302 ( V_2 ) ;
if ( V_104 < 0 )
return V_104 ;
}
V_286 = V_2 -> V_17 ;
switch ( V_74 ) {
case V_94 :
V_104 = F_23 ( V_2 , V_10 ) ;
break;
case V_303 :
V_104 = F_24 ( V_2 , V_10 ) ;
break;
case V_98 :
V_104 = F_25 ( V_2 , V_10 ) ;
break;
case V_304 :
V_104 = F_44 ( V_2 , V_10 ) ;
break;
case V_180 :
V_104 = F_48 ( V_2 , V_10 ) ;
break;
case V_305 :
V_104 = F_49 ( V_2 , V_10 ) ;
break;
case V_288 :
V_104 = F_81 ( V_2 , V_10 , V_74 ,
V_2 -> V_40 -> V_306 ) ;
break;
case V_307 :
V_104 = F_83 ( V_2 , V_10 ,
V_2 -> V_40 -> V_308 ) ;
break;
case V_185 :
V_104 = F_50 ( V_2 , V_10 ) ;
break;
case V_309 :
V_104 = F_51 ( V_2 , V_10 ) ;
break;
case V_310 :
V_104 = F_52 ( V_2 ) ;
break;
case V_188 :
V_104 = F_53 ( V_2 , V_10 ) ;
break;
case V_311 :
V_104 = F_59 ( V_2 , V_10 ) ;
break;
case V_312 :
V_104 = F_60 ( V_2 , V_10 ) ;
break;
case V_201 :
V_104 = F_61 ( V_2 , V_10 ) ;
break;
case V_313 :
V_104 = F_62 ( V_2 , V_10 ) ;
break;
case V_206 :
V_104 = F_63 ( V_2 , V_10 ) ;
break;
case V_314 :
V_104 = F_64 ( V_2 , V_10 ) ;
break;
case V_216 :
V_104 = F_67 ( V_2 , V_10 ) ;
break;
case V_315 :
V_104 = F_68 ( V_2 , V_10 ) ;
break;
case V_316 :
V_104 = F_69 ( V_2 , V_10 ) ;
break;
case V_289 :
V_104 = F_71 ( V_2 , V_10 ) ;
break;
case V_317 :
V_104 = F_72 ( V_2 , V_10 ) ;
break;
case V_290 :
V_104 = F_79 ( V_2 , V_10 ) ;
break;
case V_291 :
V_104 = F_80 ( V_2 , V_10 ) ;
break;
case V_292 :
V_104 = F_81 ( V_2 , V_10 , V_74 ,
F_19 ) ;
break;
case V_318 :
V_104 = F_84 ( V_2 , V_10 , F_20 ) ;
break;
case V_293 :
V_104 = F_81 ( V_2 , V_10 , V_74 ,
V_2 -> V_40 -> V_319 ) ;
break;
case V_320 :
V_104 = F_84 ( V_2 , V_10 ,
V_2 -> V_40 -> V_321 ) ;
break;
case V_131 :
case V_150 :
case V_294 :
case V_295 :
case V_132 :
V_104 = F_33 ( V_2 , V_74 , V_10 ) ;
break;
case V_127 :
case V_322 :
case V_128 :
V_104 = F_32 ( V_2 , V_74 , V_10 ) ;
break;
case V_323 :
V_104 = F_85 ( V_2 , V_10 ) ;
break;
case V_324 :
V_104 = F_47 ( V_2 , V_10 ) ;
break;
case V_120 :
V_104 = F_28 ( V_2 , V_10 ) ;
break;
case V_296 :
V_104 = F_38 ( V_2 , V_10 ) ;
break;
case V_325 :
V_104 = F_40 ( V_2 , V_10 ) ;
break;
case V_297 :
V_104 = F_42 ( V_2 , V_10 ) ;
break;
case V_326 :
V_104 = F_43 ( V_2 , V_10 ) ;
break;
case V_13 :
V_104 = F_4 ( V_2 , V_10 ) ;
break;
case V_327 :
V_104 = F_9 ( V_2 , V_10 ) ;
break;
case V_52 :
case V_56 :
case V_59 :
case V_62 :
case V_65 :
case V_68 :
case V_71 :
V_104 = F_17 ( V_2 , V_10 , V_74 ) ;
break;
case V_53 :
case V_57 :
case V_60 :
case V_63 :
case V_66 :
case V_69 :
case V_72 :
V_104 = F_18 ( V_2 , V_10 , V_74 ) ;
break;
case V_211 :
V_104 = F_65 ( V_2 , V_10 ) ;
break;
case V_328 :
V_104 = F_66 ( V_2 , V_10 ) ;
break;
case V_329 :
V_104 = F_86 ( V_2 , V_10 ) ;
break;
case V_258 :
V_104 = F_87 ( V_2 , V_10 ) ;
break;
case V_330 :
V_104 = F_88 ( V_2 , V_10 ) ;
break;
case V_261 :
V_104 = F_89 ( V_2 , V_10 ) ;
break;
case V_331 :
V_104 = F_91 ( V_2 , V_10 ) ;
break;
case V_332 :
V_104 = F_93 ( V_2 , V_10 ) ;
break;
case V_298 :
V_104 = F_95 ( V_2 , V_10 ) ;
break;
case V_333 :
V_104 = F_96 ( V_2 , V_10 ) ;
break;
default:
V_104 = - V_48 ;
}
if ( V_2 -> V_40 -> V_334 )
V_2 -> V_40 -> V_334 ( V_2 ) ;
if ( V_286 != V_2 -> V_17 )
F_101 ( V_2 ) ;
return V_104 ;
}
