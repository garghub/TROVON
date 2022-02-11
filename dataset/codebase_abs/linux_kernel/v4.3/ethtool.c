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
if ( V_39 == V_46 )
return F_13 ( V_47 ) ;
if ( V_41 -> V_48 && V_41 -> V_49 )
return V_41 -> V_48 ( V_2 , V_39 ) ;
else
return - V_50 ;
}
static void F_14 ( struct V_1 * V_2 ,
T_1 V_51 , T_3 * V_52 )
{
const struct V_40 * V_41 = V_2 -> V_40 ;
if ( V_51 == V_42 )
memcpy ( V_52 , V_43 ,
sizeof( V_43 ) ) ;
else if ( V_51 == V_44 )
memcpy ( V_52 , V_45 ,
sizeof( V_45 ) ) ;
else if ( V_51 == V_46 )
memcpy ( V_52 , V_47 , sizeof( V_47 ) ) ;
else
V_41 -> V_49 ( V_2 , V_51 , V_52 ) ;
}
static V_21 F_15 ( T_1 V_53 )
{
switch ( V_53 ) {
case V_54 :
case V_55 :
return V_56 | V_57 ;
case V_58 :
case V_59 :
return V_60 ;
case V_61 :
case V_62 :
return V_63 ;
case V_64 :
case V_65 :
return V_66 ;
case V_67 :
case V_68 :
return V_69 ;
case V_70 :
case V_71 :
return V_72 ;
case V_73 :
case V_74 :
return V_75 ;
default:
F_16 () ;
}
}
static int F_17 ( struct V_1 * V_2 ,
char T_2 * V_10 , T_1 V_76 )
{
V_21 V_77 = F_15 ( V_76 ) ;
struct V_78 V_79 = {
. V_12 = V_76 ,
. V_52 = ! ! ( V_2 -> V_17 & V_77 ) ,
} ;
if ( F_8 ( V_10 , & V_79 , sizeof( V_79 ) ) )
return - V_29 ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
void T_2 * V_10 , T_1 V_76 )
{
struct V_78 V_79 ;
V_21 V_77 ;
if ( F_10 ( & V_79 , V_10 , sizeof( V_79 ) ) )
return - V_29 ;
V_77 = F_15 ( V_76 ) ;
V_77 &= V_2 -> V_23 ;
if ( ! V_77 )
return - V_50 ;
if ( V_79 . V_52 )
V_2 -> V_25 |= V_77 ;
else
V_2 -> V_25 &= ~ V_77 ;
F_11 ( V_2 ) ;
return 0 ;
}
static T_1 F_19 ( struct V_1 * V_2 )
{
T_1 V_80 = 0 ;
if ( V_2 -> V_17 & V_81 )
V_80 |= V_82 ;
if ( V_2 -> V_17 & V_83 )
V_80 |= V_84 ;
if ( V_2 -> V_17 & V_85 )
V_80 |= V_86 ;
if ( V_2 -> V_17 & V_87 )
V_80 |= V_88 ;
if ( V_2 -> V_17 & V_89 )
V_80 |= V_90 ;
return V_80 ;
}
static int F_20 ( struct V_1 * V_2 , T_1 V_52 )
{
V_21 V_17 = 0 , V_91 ;
if ( V_52 & ~ V_92 )
return - V_35 ;
if ( V_52 & V_82 )
V_17 |= V_81 ;
if ( V_52 & V_84 )
V_17 |= V_83 ;
if ( V_52 & V_86 )
V_17 |= V_85 ;
if ( V_52 & V_88 )
V_17 |= V_87 ;
if ( V_52 & V_90 )
V_17 |= V_89 ;
V_91 = ( V_17 ^ V_2 -> V_17 ) & V_93 ;
if ( V_91 & ~ V_2 -> V_23 )
return ( V_91 & V_2 -> V_23 ) ? - V_35 : - V_50 ;
V_2 -> V_25 =
( V_2 -> V_25 & ~ V_91 ) | ( V_17 & V_91 ) ;
F_11 ( V_2 ) ;
return 0 ;
}
int F_21 ( struct V_1 * V_2 , struct V_94 * V_12 )
{
F_22 () ;
if ( ! V_2 -> V_40 -> V_95 )
return - V_50 ;
memset ( V_12 , 0 , sizeof( struct V_94 ) ) ;
V_12 -> V_12 = V_96 ;
return V_2 -> V_40 -> V_95 ( V_2 , V_12 ) ;
}
static int F_23 ( struct V_1 * V_2 , void T_2 * V_10 )
{
int V_97 ;
struct V_94 V_12 ;
V_97 = F_21 ( V_2 , & V_12 ) ;
if ( V_97 < 0 )
return V_97 ;
if ( F_8 ( V_10 , & V_12 , sizeof( V_12 ) ) )
return - V_29 ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 , void T_2 * V_10 )
{
struct V_94 V_12 ;
if ( ! V_2 -> V_40 -> V_98 )
return - V_50 ;
if ( F_10 ( & V_12 , V_10 , sizeof( V_12 ) ) )
return - V_29 ;
return V_2 -> V_40 -> V_98 ( V_2 , & V_12 ) ;
}
static T_4 int F_25 ( struct V_1 * V_2 ,
void T_2 * V_10 )
{
struct V_99 V_4 ;
const struct V_40 * V_41 = V_2 -> V_40 ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
V_4 . V_12 = V_100 ;
if ( V_41 -> V_101 ) {
V_41 -> V_101 ( V_2 , & V_4 ) ;
} else if ( V_2 -> V_2 . V_102 && V_2 -> V_2 . V_102 -> V_103 ) {
F_26 ( V_4 . V_104 , F_27 ( V_2 -> V_2 . V_102 ) ,
sizeof( V_4 . V_104 ) ) ;
F_26 ( V_4 . V_103 , V_2 -> V_2 . V_102 -> V_103 -> V_105 ,
sizeof( V_4 . V_103 ) ) ;
} else {
return - V_50 ;
}
if ( V_41 -> V_48 ) {
int V_106 ;
V_106 = V_41 -> V_48 ( V_2 , V_107 ) ;
if ( V_106 >= 0 )
V_4 . V_108 = V_106 ;
V_106 = V_41 -> V_48 ( V_2 , V_109 ) ;
if ( V_106 >= 0 )
V_4 . V_110 = V_106 ;
V_106 = V_41 -> V_48 ( V_2 , V_111 ) ;
if ( V_106 >= 0 )
V_4 . V_112 = V_106 ;
}
if ( V_41 -> V_113 )
V_4 . V_114 = V_41 -> V_113 ( V_2 ) ;
if ( V_41 -> V_115 )
V_4 . V_116 = V_41 -> V_115 ( V_2 ) ;
if ( F_8 ( V_10 , & V_4 , sizeof( V_4 ) ) )
return - V_29 ;
return 0 ;
}
static T_4 int F_28 ( struct V_1 * V_2 ,
void T_2 * V_10 )
{
struct V_117 V_4 ;
T_5 V_118 ;
int V_20 , V_119 = 0 , V_120 = 0 , V_34 , V_106 ;
T_1 * V_121 = NULL ;
if ( F_10 ( & V_4 , V_10 , sizeof( V_4 ) ) )
return - V_29 ;
V_118 = V_4 . V_118 ;
if ( ! V_118 )
return 0 ;
V_120 = F_29 ( V_118 ) ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
V_4 . V_12 = V_122 ;
V_121 = F_30 ( V_120 * sizeof( T_1 ) , V_123 ) ;
if ( ! V_121 )
return - V_124 ;
for ( V_20 = 0 ; V_20 < 64 ; V_20 ++ ) {
if ( ! ( V_118 & ( 1ULL << V_20 ) ) )
continue;
V_106 = F_12 ( V_2 , V_20 ) ;
if ( V_106 >= 0 ) {
V_4 . V_118 |= ( 1ULL << V_20 ) ;
V_121 [ V_119 ++ ] = V_106 ;
}
}
V_34 = - V_29 ;
if ( F_8 ( V_10 , & V_4 , sizeof( V_4 ) ) )
goto V_125;
V_10 += F_6 ( struct V_117 , V_52 ) ;
if ( F_8 ( V_10 , V_121 , V_119 * sizeof( T_1 ) ) )
goto V_125;
V_34 = 0 ;
V_125:
F_31 ( V_121 ) ;
return V_34 ;
}
static T_4 int F_32 ( struct V_1 * V_2 ,
T_1 V_12 , void T_2 * V_10 )
{
struct V_126 V_4 ;
T_6 V_127 = sizeof( V_4 ) ;
int V_106 ;
if ( ! V_2 -> V_40 -> V_128 )
return - V_50 ;
if ( V_12 == V_129 )
V_127 = ( F_6 ( struct V_126 , V_52 ) +
sizeof( V_4 . V_52 ) ) ;
if ( F_10 ( & V_4 , V_10 , V_127 ) )
return - V_29 ;
V_106 = V_2 -> V_40 -> V_128 ( V_2 , & V_4 ) ;
if ( V_106 )
return V_106 ;
if ( V_12 == V_130 &&
F_8 ( V_10 , & V_4 , V_127 ) )
return - V_29 ;
return 0 ;
}
static T_4 int F_33 ( struct V_1 * V_2 ,
T_1 V_12 , void T_2 * V_10 )
{
struct V_126 V_4 ;
T_6 V_127 = sizeof( V_4 ) ;
const struct V_40 * V_41 = V_2 -> V_40 ;
int V_34 ;
void * V_131 = NULL ;
if ( ! V_41 -> V_132 )
return - V_50 ;
if ( V_12 == V_133 )
V_127 = ( F_6 ( struct V_126 , V_52 ) +
sizeof( V_4 . V_52 ) ) ;
if ( F_10 ( & V_4 , V_10 , V_127 ) )
return - V_29 ;
if ( V_4 . V_12 == V_134 ) {
if ( V_4 . V_135 > 0 ) {
if ( V_4 . V_135 <= V_136 / sizeof( T_1 ) )
V_131 = F_30 ( V_4 . V_135 * sizeof( T_1 ) ,
V_123 ) ;
if ( ! V_131 )
return - V_124 ;
}
}
V_34 = V_41 -> V_132 ( V_2 , & V_4 , V_131 ) ;
if ( V_34 < 0 )
goto V_137;
V_34 = - V_29 ;
if ( F_8 ( V_10 , & V_4 , V_127 ) )
goto V_137;
if ( V_131 ) {
V_10 += F_6 ( struct V_126 , V_138 ) ;
if ( F_8 ( V_10 , V_131 ,
V_4 . V_135 * sizeof( T_1 ) ) )
goto V_137;
}
V_34 = 0 ;
V_137:
F_31 ( V_131 ) ;
return V_34 ;
}
static int F_34 ( T_1 * V_139 , void T_2 * V_10 ,
struct V_126 * V_140 ,
T_1 V_14 )
{
int V_20 ;
if ( F_10 ( V_139 , V_10 , V_14 * sizeof( V_139 [ 0 ] ) ) )
return - V_29 ;
for ( V_20 = 0 ; V_20 < V_14 ; V_20 ++ )
if ( V_139 [ V_20 ] >= V_140 -> V_52 )
return - V_35 ;
return 0 ;
}
void F_35 ( void * V_141 , T_6 V_142 )
{
F_36 ( V_142 > sizeof( V_143 ) ) ;
F_37 ( V_143 , sizeof( V_143 ) ) ;
memcpy ( V_141 , V_143 , V_142 ) ;
}
static T_4 int F_38 ( struct V_1 * V_2 ,
void T_2 * V_10 )
{
T_1 V_144 , V_145 ;
T_1 * V_139 ;
int V_34 ;
if ( ! V_2 -> V_40 -> V_146 ||
! V_2 -> V_40 -> V_147 )
return - V_50 ;
V_145 = V_2 -> V_40 -> V_146 ( V_2 ) ;
if ( V_145 == 0 )
return - V_50 ;
if ( F_10 ( & V_144 ,
V_10 + F_6 ( struct V_148 , V_14 ) ,
sizeof( V_144 ) ) )
return - V_29 ;
if ( F_8 ( V_10 + F_6 ( struct V_148 , V_14 ) ,
& V_145 , sizeof( V_145 ) ) )
return - V_29 ;
if ( V_144 < V_145 )
return V_144 == 0 ? 0 : - V_35 ;
V_139 = F_39 ( V_145 , sizeof( V_139 [ 0 ] ) , V_123 ) ;
if ( ! V_139 )
return - V_124 ;
V_34 = V_2 -> V_40 -> V_147 ( V_2 , V_139 , NULL , NULL ) ;
if ( V_34 )
goto V_125;
if ( F_8 ( V_10 +
F_6 ( struct V_148 , V_149 [ 0 ] ) ,
V_139 , V_145 * sizeof( V_139 [ 0 ] ) ) )
V_34 = - V_29 ;
V_125:
F_31 ( V_139 ) ;
return V_34 ;
}
static T_4 int F_40 ( struct V_1 * V_2 ,
void T_2 * V_10 )
{
struct V_126 V_140 ;
T_1 V_144 , V_145 , V_20 ;
T_1 * V_139 ;
const struct V_40 * V_41 = V_2 -> V_40 ;
int V_34 ;
T_1 V_150 = F_6 ( struct V_148 , V_149 [ 0 ] ) ;
if ( ! V_41 -> V_146 || ! V_41 -> V_151 ||
! V_41 -> V_132 )
return - V_50 ;
V_145 = V_41 -> V_146 ( V_2 ) ;
if ( V_145 == 0 )
return - V_50 ;
if ( F_10 ( & V_144 ,
V_10 + F_6 ( struct V_148 , V_14 ) ,
sizeof( V_144 ) ) )
return - V_29 ;
if ( V_144 != 0 && V_144 != V_145 )
return - V_35 ;
V_139 = F_39 ( V_145 , sizeof( V_139 [ 0 ] ) , V_123 ) ;
if ( ! V_139 )
return - V_124 ;
V_140 . V_12 = V_152 ;
V_34 = V_41 -> V_132 ( V_2 , & V_140 , NULL ) ;
if ( V_34 )
goto V_125;
if ( V_144 == 0 ) {
for ( V_20 = 0 ; V_20 < V_145 ; V_20 ++ )
V_139 [ V_20 ] = F_41 ( V_20 , V_140 . V_52 ) ;
} else {
V_34 = F_34 ( V_139 ,
V_10 + V_150 ,
& V_140 ,
V_145 ) ;
if ( V_34 )
goto V_125;
}
V_34 = V_41 -> V_151 ( V_2 , V_139 , NULL , V_153 ) ;
V_125:
F_31 ( V_139 ) ;
return V_34 ;
}
static T_4 int F_42 ( struct V_1 * V_2 ,
void T_2 * V_10 )
{
int V_34 ;
const struct V_40 * V_41 = V_2 -> V_40 ;
T_1 V_154 , V_155 ;
T_1 V_156 = 0 , V_157 = 0 ;
struct V_158 V_159 ;
T_1 V_160 ;
T_1 V_161 ;
T_1 * V_139 = NULL ;
T_3 V_162 = 0 ;
T_3 * V_163 = NULL ;
T_3 * V_164 ;
if ( ! V_41 -> V_147 )
return - V_50 ;
if ( V_41 -> V_146 )
V_156 = V_41 -> V_146 ( V_2 ) ;
if ( V_41 -> V_165 )
V_157 = V_41 -> V_165 ( V_2 ) ;
if ( F_10 ( & V_159 , V_10 , sizeof( V_159 ) ) )
return - V_29 ;
V_154 = V_159 . V_166 ;
V_155 = V_159 . V_167 ;
if ( V_159 . V_168 || V_159 . V_169 [ 0 ] || V_159 . V_169 [ 1 ] ||
V_159 . V_169 [ 2 ] || V_159 . V_170 )
return - V_35 ;
V_159 . V_166 = V_156 ;
V_159 . V_167 = V_157 ;
if ( F_8 ( V_10 , & V_159 , sizeof( V_159 ) ) )
return - V_29 ;
if ( ( V_154 && ( V_154 != V_156 ) ) ||
( V_155 && ( V_155 != V_157 ) ) )
return - V_35 ;
V_161 = V_154 * sizeof( V_139 [ 0 ] ) ;
V_160 = V_161 + V_155 ;
V_164 = F_30 ( V_160 , V_123 ) ;
if ( ! V_164 )
return - V_124 ;
if ( V_154 )
V_139 = ( T_1 * ) V_164 ;
if ( V_155 )
V_163 = V_164 + V_161 ;
V_34 = V_2 -> V_40 -> V_147 ( V_2 , V_139 , V_163 , & V_162 ) ;
if ( V_34 )
goto V_125;
if ( F_8 ( V_10 + F_6 ( struct V_158 , V_171 ) ,
& V_162 , sizeof( V_159 . V_171 ) ) ) {
V_34 = - V_29 ;
} else if ( F_8 ( V_10 +
F_6 ( struct V_158 , V_164 [ 0 ] ) ,
V_164 , V_160 ) ) {
V_34 = - V_29 ;
}
V_125:
F_31 ( V_164 ) ;
return V_34 ;
}
static T_4 int F_43 ( struct V_1 * V_2 ,
void T_2 * V_10 )
{
int V_34 ;
const struct V_40 * V_41 = V_2 -> V_40 ;
struct V_126 V_140 ;
struct V_158 V_159 ;
T_1 V_156 = 0 , V_157 = 0 , V_20 ;
T_1 * V_139 = NULL , V_161 = 0 ;
T_3 * V_163 = NULL ;
T_3 * V_164 ;
T_1 V_172 = F_6 ( struct V_158 , V_164 [ 0 ] ) ;
if ( ! V_41 -> V_132 || ! V_41 -> V_151 )
return - V_50 ;
if ( V_41 -> V_146 )
V_156 = V_41 -> V_146 ( V_2 ) ;
if ( V_41 -> V_165 )
V_157 = V_41 -> V_165 ( V_2 ) ;
if ( F_10 ( & V_159 , V_10 , sizeof( V_159 ) ) )
return - V_29 ;
if ( V_159 . V_168 || V_159 . V_169 [ 0 ] || V_159 . V_169 [ 1 ] ||
V_159 . V_169 [ 2 ] || V_159 . V_170 )
return - V_35 ;
if ( ( V_159 . V_166 &&
V_159 . V_166 != V_173 &&
V_159 . V_166 != V_156 ) ||
( V_159 . V_167 && ( V_159 . V_167 != V_157 ) ) ||
( V_159 . V_166 == V_173 &&
V_159 . V_167 == 0 && V_159 . V_171 == V_153 ) )
return - V_35 ;
if ( V_159 . V_166 != V_173 )
V_161 = V_156 * sizeof( V_139 [ 0 ] ) ;
V_164 = F_30 ( V_161 + V_159 . V_167 , V_123 ) ;
if ( ! V_164 )
return - V_124 ;
V_140 . V_12 = V_152 ;
V_34 = V_41 -> V_132 ( V_2 , & V_140 , NULL ) ;
if ( V_34 )
goto V_125;
if ( V_159 . V_166 &&
V_159 . V_166 != V_173 ) {
V_139 = ( T_1 * ) V_164 ;
V_34 = F_34 ( V_139 ,
V_10 + V_172 ,
& V_140 ,
V_159 . V_166 ) ;
if ( V_34 )
goto V_125;
} else if ( V_159 . V_166 == 0 ) {
V_139 = ( T_1 * ) V_164 ;
for ( V_20 = 0 ; V_20 < V_156 ; V_20 ++ )
V_139 [ V_20 ] = F_41 ( V_20 , V_140 . V_52 ) ;
}
if ( V_159 . V_167 ) {
V_163 = V_164 + V_161 ;
if ( F_10 ( V_163 ,
V_10 + V_172 + V_161 ,
V_159 . V_167 ) ) {
V_34 = - V_29 ;
goto V_125;
}
}
V_34 = V_41 -> V_151 ( V_2 , V_139 , V_163 , V_159 . V_171 ) ;
V_125:
F_31 ( V_164 ) ;
return V_34 ;
}
static int F_44 ( struct V_1 * V_2 , char T_2 * V_10 )
{
struct V_174 V_175 ;
const struct V_40 * V_41 = V_2 -> V_40 ;
void * V_176 ;
int V_177 , V_34 ;
if ( ! V_41 -> V_178 || ! V_41 -> V_113 )
return - V_50 ;
if ( F_10 ( & V_175 , V_10 , sizeof( V_175 ) ) )
return - V_29 ;
V_177 = V_41 -> V_113 ( V_2 ) ;
if ( V_175 . V_142 > V_177 )
V_175 . V_142 = V_177 ;
V_176 = F_45 ( V_177 ) ;
if ( V_177 && ! V_176 )
return - V_124 ;
V_41 -> V_178 ( V_2 , & V_175 , V_176 ) ;
V_34 = - V_29 ;
if ( F_8 ( V_10 , & V_175 , sizeof( V_175 ) ) )
goto V_125;
V_10 += F_6 ( struct V_174 , V_52 ) ;
if ( V_176 && F_8 ( V_10 , V_176 , V_175 . V_142 ) )
goto V_125;
V_34 = 0 ;
V_125:
F_46 ( V_176 ) ;
return V_34 ;
}
static int F_47 ( struct V_1 * V_2 , char T_2 * V_10 )
{
struct V_78 V_179 ;
int V_34 ;
if ( ! V_2 -> V_40 -> V_179 )
return - V_50 ;
if ( F_10 ( & V_179 , V_10 , sizeof( V_179 ) ) )
return - V_29 ;
V_34 = V_2 -> V_40 -> V_179 ( V_2 , & V_179 . V_52 ) ;
if ( V_34 )
return V_34 ;
if ( F_8 ( V_10 , & V_179 , sizeof( V_179 ) ) )
return - V_29 ;
return 0 ;
}
static int F_48 ( struct V_1 * V_2 , char T_2 * V_10 )
{
struct V_180 V_181 = { . V_12 = V_182 } ;
if ( ! V_2 -> V_40 -> V_183 )
return - V_50 ;
V_2 -> V_40 -> V_183 ( V_2 , & V_181 ) ;
if ( F_8 ( V_10 , & V_181 , sizeof( V_181 ) ) )
return - V_29 ;
return 0 ;
}
static int F_49 ( struct V_1 * V_2 , char T_2 * V_10 )
{
struct V_180 V_181 ;
if ( ! V_2 -> V_40 -> V_184 )
return - V_50 ;
if ( F_10 ( & V_181 , V_10 , sizeof( V_181 ) ) )
return - V_29 ;
return V_2 -> V_40 -> V_184 ( V_2 , & V_181 ) ;
}
static int F_50 ( struct V_1 * V_2 , char T_2 * V_10 )
{
struct V_185 V_79 ;
int V_106 ;
if ( ! V_2 -> V_40 -> V_186 )
return - V_50 ;
memset ( & V_79 , 0 , sizeof( struct V_185 ) ) ;
V_79 . V_12 = V_187 ;
V_106 = V_2 -> V_40 -> V_186 ( V_2 , & V_79 ) ;
if ( V_106 )
return V_106 ;
if ( F_8 ( V_10 , & V_79 , sizeof( V_79 ) ) )
return - V_29 ;
return 0 ;
}
static int F_51 ( struct V_1 * V_2 , char T_2 * V_10 )
{
struct V_185 V_79 ;
if ( ! V_2 -> V_40 -> V_188 )
return - V_50 ;
if ( F_10 ( & V_79 , V_10 , sizeof( V_79 ) ) )
return - V_29 ;
return V_2 -> V_40 -> V_188 ( V_2 , & V_79 ) ;
}
static int F_52 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_40 -> V_189 )
return - V_50 ;
return V_2 -> V_40 -> V_189 ( V_2 ) ;
}
static int F_53 ( struct V_1 * V_2 , char T_2 * V_10 )
{
struct V_78 V_79 = { . V_12 = V_190 } ;
if ( ! V_2 -> V_40 -> V_191 )
return - V_50 ;
V_79 . V_52 = F_54 ( V_2 ) && V_2 -> V_40 -> V_191 ( V_2 ) ;
if ( F_8 ( V_10 , & V_79 , sizeof( V_79 ) ) )
return - V_29 ;
return 0 ;
}
static int F_55 ( struct V_1 * V_2 , void T_2 * V_10 ,
int (* F_56)( struct V_1 * ,
struct V_192 * , T_3 * ) ,
T_1 V_193 )
{
struct V_192 V_194 ;
void T_2 * V_195 = V_10 + sizeof( V_194 ) ;
T_1 V_196 ;
T_3 * V_52 ;
int V_34 = 0 ;
if ( F_10 ( & V_194 , V_10 , sizeof( V_194 ) ) )
return - V_29 ;
if ( V_194 . V_197 + V_194 . V_142 <= V_194 . V_197 )
return - V_35 ;
if ( V_194 . V_197 + V_194 . V_142 > V_193 )
return - V_35 ;
V_52 = F_57 ( V_198 , V_123 ) ;
if ( ! V_52 )
return - V_124 ;
V_196 = V_194 . V_142 ;
while ( V_196 > 0 ) {
V_194 . V_142 = F_58 ( V_196 , ( T_1 ) V_198 ) ;
V_34 = F_56 ( V_2 , & V_194 , V_52 ) ;
if ( V_34 )
break;
if ( F_8 ( V_195 , V_52 , V_194 . V_142 ) ) {
V_34 = - V_29 ;
break;
}
V_195 += V_194 . V_142 ;
V_194 . V_197 += V_194 . V_142 ;
V_196 -= V_194 . V_142 ;
}
V_194 . V_142 = V_195 - ( V_10 + sizeof( V_194 ) ) ;
V_194 . V_197 -= V_194 . V_142 ;
if ( F_8 ( V_10 , & V_194 , sizeof( V_194 ) ) )
V_34 = - V_29 ;
F_31 ( V_52 ) ;
return V_34 ;
}
static int F_59 ( struct V_1 * V_2 , void T_2 * V_10 )
{
const struct V_40 * V_41 = V_2 -> V_40 ;
if ( ! V_41 -> V_199 || ! V_41 -> V_115 ||
! V_41 -> V_115 ( V_2 ) )
return - V_50 ;
return F_55 ( V_2 , V_10 , V_41 -> V_199 ,
V_41 -> V_115 ( V_2 ) ) ;
}
static int F_60 ( struct V_1 * V_2 , void T_2 * V_10 )
{
struct V_192 V_194 ;
const struct V_40 * V_41 = V_2 -> V_40 ;
void T_2 * V_195 = V_10 + sizeof( V_194 ) ;
T_1 V_196 ;
T_3 * V_52 ;
int V_34 = 0 ;
if ( ! V_41 -> V_200 || ! V_41 -> V_115 ||
! V_41 -> V_115 ( V_2 ) )
return - V_50 ;
if ( F_10 ( & V_194 , V_10 , sizeof( V_194 ) ) )
return - V_29 ;
if ( V_194 . V_197 + V_194 . V_142 <= V_194 . V_197 )
return - V_35 ;
if ( V_194 . V_197 + V_194 . V_142 > V_41 -> V_115 ( V_2 ) )
return - V_35 ;
V_52 = F_57 ( V_198 , V_123 ) ;
if ( ! V_52 )
return - V_124 ;
V_196 = V_194 . V_142 ;
while ( V_196 > 0 ) {
V_194 . V_142 = F_58 ( V_196 , ( T_1 ) V_198 ) ;
if ( F_10 ( V_52 , V_195 , V_194 . V_142 ) ) {
V_34 = - V_29 ;
break;
}
V_34 = V_41 -> V_200 ( V_2 , & V_194 , V_52 ) ;
if ( V_34 )
break;
V_195 += V_194 . V_142 ;
V_194 . V_197 += V_194 . V_142 ;
V_196 -= V_194 . V_142 ;
}
F_31 ( V_52 ) ;
return V_34 ;
}
static T_4 int F_61 ( struct V_1 * V_2 ,
void T_2 * V_10 )
{
struct V_201 V_202 = { . V_12 = V_203 } ;
if ( ! V_2 -> V_40 -> V_204 )
return - V_50 ;
V_2 -> V_40 -> V_204 ( V_2 , & V_202 ) ;
if ( F_8 ( V_10 , & V_202 , sizeof( V_202 ) ) )
return - V_29 ;
return 0 ;
}
static T_4 int F_62 ( struct V_1 * V_2 ,
void T_2 * V_10 )
{
struct V_201 V_202 ;
if ( ! V_2 -> V_40 -> V_205 )
return - V_50 ;
if ( F_10 ( & V_202 , V_10 , sizeof( V_202 ) ) )
return - V_29 ;
return V_2 -> V_40 -> V_205 ( V_2 , & V_202 ) ;
}
static int F_63 ( struct V_1 * V_2 , void T_2 * V_10 )
{
struct V_206 V_207 = { . V_12 = V_208 } ;
if ( ! V_2 -> V_40 -> V_209 )
return - V_50 ;
V_2 -> V_40 -> V_209 ( V_2 , & V_207 ) ;
if ( F_8 ( V_10 , & V_207 , sizeof( V_207 ) ) )
return - V_29 ;
return 0 ;
}
static int F_64 ( struct V_1 * V_2 , void T_2 * V_10 )
{
struct V_206 V_207 ;
if ( ! V_2 -> V_40 -> V_210 )
return - V_50 ;
if ( F_10 ( & V_207 , V_10 , sizeof( V_207 ) ) )
return - V_29 ;
return V_2 -> V_40 -> V_210 ( V_2 , & V_207 ) ;
}
static T_4 int F_65 ( struct V_1 * V_2 ,
void T_2 * V_10 )
{
struct V_211 V_212 = { . V_12 = V_213 } ;
if ( ! V_2 -> V_40 -> V_214 )
return - V_50 ;
V_2 -> V_40 -> V_214 ( V_2 , & V_212 ) ;
if ( F_8 ( V_10 , & V_212 , sizeof( V_212 ) ) )
return - V_29 ;
return 0 ;
}
static T_4 int F_66 ( struct V_1 * V_2 ,
void T_2 * V_10 )
{
struct V_211 V_212 ;
if ( ! V_2 -> V_40 -> V_215 )
return - V_50 ;
if ( F_10 ( & V_212 , V_10 , sizeof( V_212 ) ) )
return - V_29 ;
return V_2 -> V_40 -> V_215 ( V_2 , & V_212 ) ;
}
static int F_67 ( struct V_1 * V_2 , void T_2 * V_10 )
{
struct V_216 V_217 = { V_218 } ;
if ( ! V_2 -> V_40 -> V_219 )
return - V_50 ;
V_2 -> V_40 -> V_219 ( V_2 , & V_217 ) ;
if ( F_8 ( V_10 , & V_217 , sizeof( V_217 ) ) )
return - V_29 ;
return 0 ;
}
static int F_68 ( struct V_1 * V_2 , void T_2 * V_10 )
{
struct V_216 V_217 ;
if ( ! V_2 -> V_40 -> V_220 )
return - V_50 ;
if ( F_10 ( & V_217 , V_10 , sizeof( V_217 ) ) )
return - V_29 ;
return V_2 -> V_40 -> V_220 ( V_2 , & V_217 ) ;
}
static int F_69 ( struct V_1 * V_2 , char T_2 * V_10 )
{
struct V_221 V_222 ;
const struct V_40 * V_41 = V_2 -> V_40 ;
T_5 * V_52 ;
int V_34 , V_223 ;
if ( ! V_41 -> V_224 || ! V_41 -> V_48 )
return - V_50 ;
V_223 = V_41 -> V_48 ( V_2 , V_107 ) ;
if ( V_223 < 0 )
return V_223 ;
F_70 ( V_223 == 0 ) ;
if ( F_10 ( & V_222 , V_10 , sizeof( V_222 ) ) )
return - V_29 ;
V_222 . V_142 = V_223 ;
V_52 = F_57 ( V_223 * sizeof( T_5 ) , V_123 ) ;
if ( ! V_52 )
return - V_124 ;
V_41 -> V_224 ( V_2 , & V_222 , V_52 ) ;
V_34 = - V_29 ;
if ( F_8 ( V_10 , & V_222 , sizeof( V_222 ) ) )
goto V_125;
V_10 += sizeof( V_222 ) ;
if ( F_8 ( V_10 , V_52 , V_222 . V_142 * sizeof( T_5 ) ) )
goto V_125;
V_34 = 0 ;
V_125:
F_31 ( V_52 ) ;
return V_34 ;
}
static int F_71 ( struct V_1 * V_2 , void T_2 * V_10 )
{
struct V_225 V_226 ;
T_3 * V_52 ;
int V_34 ;
if ( F_10 ( & V_226 , V_10 , sizeof( V_226 ) ) )
return - V_29 ;
V_34 = F_12 ( V_2 , V_226 . V_227 ) ;
if ( V_34 < 0 )
return V_34 ;
V_226 . V_142 = V_34 ;
V_52 = F_39 ( V_226 . V_142 , V_228 , V_123 ) ;
if ( ! V_52 )
return - V_124 ;
F_14 ( V_2 , V_226 . V_227 , V_52 ) ;
V_34 = - V_29 ;
if ( F_8 ( V_10 , & V_226 , sizeof( V_226 ) ) )
goto V_125;
V_10 += sizeof( V_226 ) ;
if ( F_8 ( V_10 , V_52 , V_226 . V_142 * V_228 ) )
goto V_125;
V_34 = 0 ;
V_125:
F_31 ( V_52 ) ;
return V_34 ;
}
static int F_72 ( struct V_1 * V_2 , void T_2 * V_10 )
{
struct V_78 V_229 ;
static bool V_230 ;
const struct V_40 * V_41 = V_2 -> V_40 ;
int V_106 ;
if ( ! V_41 -> V_231 )
return - V_50 ;
if ( V_230 )
return - V_232 ;
if ( F_10 ( & V_229 , V_10 , sizeof( V_229 ) ) )
return - V_29 ;
V_106 = V_41 -> V_231 ( V_2 , V_233 ) ;
if ( V_106 < 0 )
return V_106 ;
V_230 = true ;
F_73 ( V_2 ) ;
F_74 () ;
if ( V_106 == 0 ) {
F_75 (
V_229 . V_52 ? ( V_229 . V_52 * V_234 ) : V_235 ) ;
} else {
int V_236 = V_106 * 2 , V_20 , V_237 = V_234 / V_236 ;
do {
V_20 = V_236 ;
do {
F_76 () ;
V_106 = V_41 -> V_231 ( V_2 ,
( V_20 & 1 ) ? V_238 : V_239 ) ;
F_74 () ;
if ( V_106 )
break;
F_75 ( V_237 ) ;
} while ( ! F_77 ( V_240 ) && -- V_20 != 0 );
} while ( ! F_77 ( V_240 ) &&
( V_229 . V_52 == 0 || -- V_229 . V_52 != 0 ) );
}
F_76 () ;
F_78 ( V_2 ) ;
V_230 = false ;
( void ) V_41 -> V_231 ( V_2 , V_241 ) ;
return V_106 ;
}
static int F_79 ( struct V_1 * V_2 , void T_2 * V_10 )
{
struct V_242 V_243 ;
const struct V_40 * V_41 = V_2 -> V_40 ;
T_5 * V_52 ;
int V_34 , V_110 ;
if ( ! V_41 -> V_244 || ! V_41 -> V_48 )
return - V_50 ;
V_110 = V_41 -> V_48 ( V_2 , V_109 ) ;
if ( V_110 < 0 )
return V_110 ;
F_70 ( V_110 == 0 ) ;
if ( F_10 ( & V_243 , V_10 , sizeof( V_243 ) ) )
return - V_29 ;
V_243 . V_110 = V_110 ;
V_52 = F_57 ( V_110 * sizeof( T_5 ) , V_123 ) ;
if ( ! V_52 )
return - V_124 ;
V_41 -> V_244 ( V_2 , & V_243 , V_52 ) ;
V_34 = - V_29 ;
if ( F_8 ( V_10 , & V_243 , sizeof( V_243 ) ) )
goto V_125;
V_10 += sizeof( V_243 ) ;
if ( F_8 ( V_10 , V_52 , V_243 . V_110 * sizeof( T_5 ) ) )
goto V_125;
V_34 = 0 ;
V_125:
F_31 ( V_52 ) ;
return V_34 ;
}
static int F_80 ( struct V_1 * V_2 , void T_2 * V_10 )
{
struct V_245 V_246 ;
if ( F_10 ( & V_246 , V_10 , sizeof( V_246 ) ) )
return - V_29 ;
if ( V_246 . V_14 < V_2 -> V_247 )
return - V_248 ;
V_246 . V_14 = V_2 -> V_247 ;
if ( F_8 ( V_10 , & V_246 , sizeof( V_246 ) ) )
return - V_29 ;
V_10 += sizeof( V_246 ) ;
if ( F_8 ( V_10 , V_2 -> V_249 , V_246 . V_14 ) )
return - V_29 ;
return 0 ;
}
static int F_81 ( struct V_1 * V_2 , char T_2 * V_10 ,
T_1 V_12 , T_1 (* F_82)( struct V_1 * ) )
{
struct V_78 V_79 = { . V_12 = V_12 } ;
if ( ! F_82 )
return - V_50 ;
V_79 . V_52 = F_82 ( V_2 ) ;
if ( F_8 ( V_10 , & V_79 , sizeof( V_79 ) ) )
return - V_29 ;
return 0 ;
}
static int F_83 ( struct V_1 * V_2 , char T_2 * V_10 ,
void (* F_82)( struct V_1 * , T_1 ) )
{
struct V_78 V_79 ;
if ( ! F_82 )
return - V_50 ;
if ( F_10 ( & V_79 , V_10 , sizeof( V_79 ) ) )
return - V_29 ;
F_82 ( V_2 , V_79 . V_52 ) ;
return 0 ;
}
static int F_84 ( struct V_1 * V_2 , char T_2 * V_10 ,
int (* F_82)( struct V_1 * , T_1 ) )
{
struct V_78 V_79 ;
if ( ! F_82 )
return - V_50 ;
if ( F_10 ( & V_79 , V_10 , sizeof( V_79 ) ) )
return - V_29 ;
return F_82 ( V_2 , V_79 . V_52 ) ;
}
static T_4 int F_85 ( struct V_1 * V_2 ,
char T_2 * V_10 )
{
struct V_250 V_251 ;
if ( F_10 ( & V_251 , V_10 , sizeof( V_251 ) ) )
return - V_29 ;
if ( ! V_2 -> V_40 -> V_252 )
return - V_50 ;
V_251 . V_52 [ V_253 - 1 ] = 0 ;
return V_2 -> V_40 -> V_252 ( V_2 , & V_251 ) ;
}
static int F_86 ( struct V_1 * V_2 ,
void T_2 * V_10 )
{
struct V_254 V_255 ;
if ( ! V_2 -> V_40 -> V_256 )
return - V_50 ;
if ( F_10 ( & V_255 , V_10 , sizeof( V_255 ) ) )
return - V_29 ;
return V_2 -> V_40 -> V_256 ( V_2 , & V_255 ) ;
}
static int F_87 ( struct V_1 * V_2 ,
void T_2 * V_10 )
{
int V_34 ;
struct V_254 V_255 ;
const struct V_40 * V_41 = V_2 -> V_40 ;
if ( ! V_41 -> V_257 )
return - V_50 ;
if ( F_10 ( & V_255 , V_10 , sizeof( V_255 ) ) )
return - V_29 ;
V_34 = V_41 -> V_257 ( V_2 , & V_255 ) ;
if ( V_34 )
return V_34 ;
if ( F_8 ( V_10 , & V_255 , sizeof( V_255 ) ) )
return - V_29 ;
return 0 ;
}
static int F_88 ( struct V_1 * V_2 ,
void T_2 * V_10 )
{
int V_34 ;
T_7 V_142 ;
struct V_254 V_255 , V_258 ;
const struct V_40 * V_41 = V_2 -> V_40 ;
void * V_52 = NULL ;
if ( ! V_41 -> V_259 || ! V_41 -> V_257 )
return - V_50 ;
if ( F_10 ( & V_255 , V_10 , sizeof( V_255 ) ) )
return - V_29 ;
memset ( & V_258 , 0 , sizeof( V_258 ) ) ;
V_258 . V_12 = V_260 ;
V_34 = V_41 -> V_257 ( V_2 , & V_258 ) ;
if ( V_34 )
return V_34 ;
V_142 = F_58 ( V_258 . V_142 , V_255 . V_142 ) ;
if ( ! V_142 )
return - V_29 ;
V_255 . V_142 = V_142 ;
V_52 = F_45 ( V_258 . V_142 ) ;
if ( ! V_52 )
return - V_124 ;
V_34 = V_41 -> V_259 ( V_2 , & V_255 , V_52 ) ;
if ( V_34 )
goto V_125;
F_70 ( V_255 . V_142 != V_142 && V_255 . V_142 != V_258 . V_142 ) ;
V_255 . V_142 = V_142 ;
if ( F_8 ( V_10 , & V_255 , sizeof( V_255 ) ) ) {
V_34 = - V_29 ;
goto V_125;
}
V_10 += F_6 ( struct V_254 , V_52 ) ;
if ( F_8 ( V_10 , V_52 , V_142 ) )
V_34 = - V_29 ;
V_125:
F_46 ( V_52 ) ;
return V_34 ;
}
static int F_89 ( struct V_1 * V_2 , void T_2 * V_10 )
{
int V_97 = 0 ;
struct V_3 V_4 ;
const struct V_40 * V_41 = V_2 -> V_40 ;
struct V_261 * V_262 = V_2 -> V_262 ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
V_4 . V_12 = V_263 ;
if ( V_262 && V_262 -> V_264 && V_262 -> V_264 -> V_265 ) {
V_97 = V_262 -> V_264 -> V_265 ( V_262 , & V_4 ) ;
} else if ( V_41 -> V_266 ) {
V_97 = V_41 -> V_266 ( V_2 , & V_4 ) ;
} else {
V_4 . V_5 =
V_7 |
V_8 ;
V_4 . V_9 = - 1 ;
}
if ( V_97 )
return V_97 ;
if ( F_8 ( V_10 , & V_4 , sizeof( V_4 ) ) )
V_97 = - V_29 ;
return V_97 ;
}
static int F_90 ( struct V_1 * V_2 ,
struct V_267 * V_268 )
{
const struct V_40 * V_41 = V_2 -> V_40 ;
struct V_261 * V_262 = V_2 -> V_262 ;
if ( V_262 && V_262 -> V_264 && V_262 -> V_264 -> V_269 )
return V_262 -> V_264 -> V_269 ( V_262 , V_268 ) ;
if ( V_41 -> V_270 )
return V_41 -> V_270 ( V_2 , V_268 ) ;
return - V_50 ;
}
static int F_91 ( struct V_1 * V_2 ,
void T_2 * V_10 )
{
int V_34 ;
struct V_267 V_268 ;
if ( F_10 ( & V_268 , V_10 , sizeof( V_268 ) ) )
return - V_29 ;
V_34 = F_90 ( V_2 , & V_268 ) ;
if ( V_34 )
return V_34 ;
if ( F_8 ( V_10 , & V_268 , sizeof( V_268 ) ) )
return - V_29 ;
return 0 ;
}
static int F_92 ( struct V_1 * V_2 ,
struct V_192 * V_271 , T_3 * V_52 )
{
const struct V_40 * V_41 = V_2 -> V_40 ;
struct V_261 * V_262 = V_2 -> V_262 ;
if ( V_262 && V_262 -> V_264 && V_262 -> V_264 -> V_272 )
return V_262 -> V_264 -> V_272 ( V_262 , V_271 , V_52 ) ;
if ( V_41 -> V_273 )
return V_41 -> V_273 ( V_2 , V_271 , V_52 ) ;
return - V_50 ;
}
static int F_93 ( struct V_1 * V_2 ,
void T_2 * V_10 )
{
int V_34 ;
struct V_267 V_268 ;
V_34 = F_90 ( V_2 , & V_268 ) ;
if ( V_34 )
return V_34 ;
return F_55 ( V_2 , V_10 ,
F_92 ,
V_268 . V_274 ) ;
}
static int F_94 ( const struct V_275 * V_276 )
{
switch ( V_276 -> V_229 ) {
case V_277 :
case V_278 :
if ( V_276 -> V_142 != sizeof( T_1 ) ||
V_276 -> V_279 != V_280 )
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
struct V_275 V_276 ;
const struct V_40 * V_41 = V_2 -> V_40 ;
void * V_52 ;
if ( ! V_41 -> V_281 )
return - V_50 ;
if ( F_10 ( & V_276 , V_10 , sizeof( V_276 ) ) )
return - V_29 ;
V_34 = F_94 ( & V_276 ) ;
if ( V_34 )
return V_34 ;
V_52 = F_57 ( V_276 . V_142 , V_123 ) ;
if ( ! V_52 )
return - V_124 ;
V_34 = V_41 -> V_281 ( V_2 , & V_276 , V_52 ) ;
if ( V_34 )
goto V_125;
V_10 += sizeof( V_276 ) ;
V_34 = - V_29 ;
if ( F_8 ( V_10 , V_52 , V_276 . V_142 ) )
goto V_125;
V_34 = 0 ;
V_125:
F_31 ( V_52 ) ;
return V_34 ;
}
static int F_96 ( struct V_1 * V_2 , void T_2 * V_10 )
{
int V_34 ;
struct V_275 V_276 ;
const struct V_40 * V_41 = V_2 -> V_40 ;
void * V_52 ;
if ( ! V_41 -> V_282 )
return - V_50 ;
if ( F_10 ( & V_276 , V_10 , sizeof( V_276 ) ) )
return - V_29 ;
V_34 = F_94 ( & V_276 ) ;
if ( V_34 )
return V_34 ;
V_52 = F_57 ( V_276 . V_142 , V_123 ) ;
if ( ! V_52 )
return - V_124 ;
V_10 += sizeof( V_276 ) ;
V_34 = - V_29 ;
if ( F_10 ( V_52 , V_10 , V_276 . V_142 ) )
goto V_125;
V_34 = V_41 -> V_282 ( V_2 , & V_276 , V_52 ) ;
V_125:
F_31 ( V_52 ) ;
return V_34 ;
}
int F_97 ( struct V_283 * V_283 , struct V_284 * V_285 )
{
struct V_1 * V_2 = F_98 ( V_283 , V_285 -> V_286 ) ;
void T_2 * V_10 = V_285 -> V_287 ;
T_1 V_76 ;
int V_106 ;
V_21 V_288 ;
if ( ! V_2 || ! F_99 ( V_2 ) )
return - V_289 ;
if ( F_10 ( & V_76 , V_10 , sizeof( V_76 ) ) )
return - V_29 ;
switch ( V_76 ) {
case V_96 :
case V_100 :
case V_290 :
case V_190 :
case V_203 :
case V_208 :
case V_218 :
case V_58 :
case V_54 :
case V_61 :
case V_122 :
case V_291 :
case V_292 :
case V_64 :
case V_293 :
case V_67 :
case V_70 :
case V_73 :
case V_294 :
case V_295 :
case V_133 :
case V_152 :
case V_296 :
case V_297 :
case V_134 :
case V_298 :
case V_299 :
case V_13 :
case V_213 :
case V_263 :
case V_187 :
case V_300 :
break;
default:
if ( ! F_100 ( V_283 -> V_301 , V_302 ) )
return - V_303 ;
}
if ( V_2 -> V_40 -> V_304 ) {
V_106 = V_2 -> V_40 -> V_304 ( V_2 ) ;
if ( V_106 < 0 )
return V_106 ;
}
V_288 = V_2 -> V_17 ;
switch ( V_76 ) {
case V_96 :
V_106 = F_23 ( V_2 , V_10 ) ;
break;
case V_305 :
V_106 = F_24 ( V_2 , V_10 ) ;
break;
case V_100 :
V_106 = F_25 ( V_2 , V_10 ) ;
break;
case V_306 :
V_106 = F_44 ( V_2 , V_10 ) ;
break;
case V_182 :
V_106 = F_48 ( V_2 , V_10 ) ;
break;
case V_307 :
V_106 = F_49 ( V_2 , V_10 ) ;
break;
case V_290 :
V_106 = F_81 ( V_2 , V_10 , V_76 ,
V_2 -> V_40 -> V_308 ) ;
break;
case V_309 :
V_106 = F_83 ( V_2 , V_10 ,
V_2 -> V_40 -> V_310 ) ;
break;
case V_187 :
V_106 = F_50 ( V_2 , V_10 ) ;
break;
case V_311 :
V_106 = F_51 ( V_2 , V_10 ) ;
break;
case V_312 :
V_106 = F_52 ( V_2 ) ;
break;
case V_190 :
V_106 = F_53 ( V_2 , V_10 ) ;
break;
case V_313 :
V_106 = F_59 ( V_2 , V_10 ) ;
break;
case V_314 :
V_106 = F_60 ( V_2 , V_10 ) ;
break;
case V_203 :
V_106 = F_61 ( V_2 , V_10 ) ;
break;
case V_315 :
V_106 = F_62 ( V_2 , V_10 ) ;
break;
case V_208 :
V_106 = F_63 ( V_2 , V_10 ) ;
break;
case V_316 :
V_106 = F_64 ( V_2 , V_10 ) ;
break;
case V_218 :
V_106 = F_67 ( V_2 , V_10 ) ;
break;
case V_317 :
V_106 = F_68 ( V_2 , V_10 ) ;
break;
case V_318 :
V_106 = F_69 ( V_2 , V_10 ) ;
break;
case V_291 :
V_106 = F_71 ( V_2 , V_10 ) ;
break;
case V_319 :
V_106 = F_72 ( V_2 , V_10 ) ;
break;
case V_292 :
V_106 = F_79 ( V_2 , V_10 ) ;
break;
case V_293 :
V_106 = F_80 ( V_2 , V_10 ) ;
break;
case V_294 :
V_106 = F_81 ( V_2 , V_10 , V_76 ,
F_19 ) ;
break;
case V_320 :
V_106 = F_84 ( V_2 , V_10 , F_20 ) ;
break;
case V_295 :
V_106 = F_81 ( V_2 , V_10 , V_76 ,
V_2 -> V_40 -> V_321 ) ;
break;
case V_322 :
V_106 = F_84 ( V_2 , V_10 ,
V_2 -> V_40 -> V_323 ) ;
break;
case V_133 :
case V_152 :
case V_296 :
case V_297 :
case V_134 :
V_106 = F_33 ( V_2 , V_76 , V_10 ) ;
break;
case V_129 :
case V_324 :
case V_130 :
V_106 = F_32 ( V_2 , V_76 , V_10 ) ;
break;
case V_325 :
V_106 = F_85 ( V_2 , V_10 ) ;
break;
case V_326 :
V_106 = F_47 ( V_2 , V_10 ) ;
break;
case V_122 :
V_106 = F_28 ( V_2 , V_10 ) ;
break;
case V_298 :
V_106 = F_38 ( V_2 , V_10 ) ;
break;
case V_327 :
V_106 = F_40 ( V_2 , V_10 ) ;
break;
case V_299 :
V_106 = F_42 ( V_2 , V_10 ) ;
break;
case V_328 :
V_106 = F_43 ( V_2 , V_10 ) ;
break;
case V_13 :
V_106 = F_4 ( V_2 , V_10 ) ;
break;
case V_329 :
V_106 = F_9 ( V_2 , V_10 ) ;
break;
case V_54 :
case V_58 :
case V_61 :
case V_64 :
case V_67 :
case V_70 :
case V_73 :
V_106 = F_17 ( V_2 , V_10 , V_76 ) ;
break;
case V_55 :
case V_59 :
case V_62 :
case V_65 :
case V_68 :
case V_71 :
case V_74 :
V_106 = F_18 ( V_2 , V_10 , V_76 ) ;
break;
case V_213 :
V_106 = F_65 ( V_2 , V_10 ) ;
break;
case V_330 :
V_106 = F_66 ( V_2 , V_10 ) ;
break;
case V_331 :
V_106 = F_86 ( V_2 , V_10 ) ;
break;
case V_260 :
V_106 = F_87 ( V_2 , V_10 ) ;
break;
case V_332 :
V_106 = F_88 ( V_2 , V_10 ) ;
break;
case V_263 :
V_106 = F_89 ( V_2 , V_10 ) ;
break;
case V_333 :
V_106 = F_91 ( V_2 , V_10 ) ;
break;
case V_334 :
V_106 = F_93 ( V_2 , V_10 ) ;
break;
case V_300 :
V_106 = F_95 ( V_2 , V_10 ) ;
break;
case V_335 :
V_106 = F_96 ( V_2 , V_10 ) ;
break;
default:
V_106 = - V_50 ;
}
if ( V_2 -> V_40 -> V_336 )
V_2 -> V_40 -> V_336 ( V_2 ) ;
if ( V_288 != V_2 -> V_17 )
F_101 ( V_2 ) ;
return V_106 ;
}
