T_1 F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 ) ? 1 : 0 ;
}
static int F_3 ( struct V_1 * V_2 , void T_2 * V_3 )
{
struct V_4 V_5 = {
. V_5 = V_6 ,
. V_7 = V_8 ,
} ;
struct V_9 V_10 [ V_8 ] ;
T_1 T_2 * V_11 ;
T_1 V_12 ;
int V_13 ;
F_4 ( V_8 * sizeof( T_1 ) > sizeof( V_14 ) ) ;
for ( V_13 = 0 ; V_13 < V_8 ; ++ V_13 ) {
V_10 [ V_13 ] . V_15 = ( T_1 ) ( V_2 -> V_16 >> ( 32 * V_13 ) ) ;
V_10 [ V_13 ] . V_17 = ( T_1 ) ( V_2 -> V_18 >> ( 32 * V_13 ) ) ;
V_10 [ V_13 ] . V_19 = ( T_1 ) ( V_2 -> V_10 >> ( 32 * V_13 ) ) ;
V_10 [ V_13 ] . V_20 =
( T_1 ) ( V_21 >> ( 32 * V_13 ) ) ;
}
V_11 = V_3 + F_5 ( struct V_4 , V_7 ) ;
if ( F_6 ( V_12 , V_11 ) )
return - V_22 ;
if ( V_12 > V_8 )
V_12 = V_8 ;
if ( F_7 ( V_3 , & V_5 , sizeof( V_5 ) ) )
return - V_22 ;
V_3 += sizeof( V_5 ) ;
if ( F_7 ( V_3 , V_10 , V_12 * sizeof( * V_10 ) ) )
return - V_22 ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , void T_2 * V_3 )
{
struct V_23 V_5 ;
struct V_24 V_10 [ V_8 ] ;
V_14 V_25 = 0 , V_26 = 0 ;
int V_13 , V_27 = 0 ;
if ( F_9 ( & V_5 , V_3 , sizeof( V_5 ) ) )
return - V_22 ;
V_3 += sizeof( V_5 ) ;
if ( V_5 . V_7 != V_8 )
return - V_28 ;
if ( F_9 ( V_10 , V_3 , sizeof( V_10 ) ) )
return - V_22 ;
for ( V_13 = 0 ; V_13 < V_8 ; ++ V_13 ) {
V_26 |= ( V_14 ) V_10 [ V_13 ] . V_26 << ( 32 * V_13 ) ;
V_25 |= ( V_14 ) V_10 [ V_13 ] . V_17 << ( 32 * V_13 ) ;
}
if ( V_26 & ~ V_29 )
return - V_28 ;
if ( V_26 & ~ V_2 -> V_16 ) {
V_26 &= V_2 -> V_16 ;
V_27 |= V_30 ;
}
V_2 -> V_18 &= ~ V_26 ;
V_2 -> V_18 |= V_25 & V_26 ;
F_10 ( V_2 ) ;
if ( ( V_2 -> V_18 ^ V_2 -> V_10 ) & V_26 )
V_27 |= V_31 ;
return V_27 ;
}
static int F_11 ( struct V_1 * V_2 , int V_32 )
{
const struct V_33 * V_34 = V_2 -> V_33 ;
if ( V_32 == V_35 )
return F_12 ( V_36 ) ;
if ( V_34 && V_34 -> V_37 && V_34 -> V_38 )
return V_34 -> V_37 ( V_2 , V_32 ) ;
else
return - V_39 ;
}
static void F_13 ( struct V_1 * V_2 ,
T_1 V_40 , T_3 * V_41 )
{
const struct V_33 * V_34 = V_2 -> V_33 ;
if ( V_40 == V_35 )
memcpy ( V_41 , V_36 ,
sizeof( V_36 ) ) ;
else
V_34 -> V_38 ( V_2 , V_40 , V_41 ) ;
}
static V_14 F_14 ( T_1 V_42 )
{
switch ( V_42 ) {
case V_43 :
case V_44 :
return V_45 | V_46 ;
case V_47 :
case V_48 :
return V_49 ;
case V_50 :
case V_51 :
return V_52 ;
case V_53 :
case V_54 :
return V_55 ;
case V_56 :
case V_57 :
return V_58 ;
case V_59 :
case V_60 :
return V_61 ;
case V_62 :
case V_63 :
return V_64 ;
default:
F_15 () ;
}
}
static int F_16 ( struct V_1 * V_2 ,
char T_2 * V_3 , T_1 V_65 )
{
V_14 V_66 = F_14 ( V_65 ) ;
struct V_67 V_68 = {
. V_5 = V_65 ,
. V_41 = ! ! ( V_2 -> V_10 & V_66 ) ,
} ;
if ( F_7 ( V_3 , & V_68 , sizeof( V_68 ) ) )
return - V_22 ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
void T_2 * V_3 , T_1 V_65 )
{
struct V_67 V_68 ;
V_14 V_66 ;
if ( F_9 ( & V_68 , V_3 , sizeof( V_68 ) ) )
return - V_22 ;
V_66 = F_14 ( V_65 ) ;
V_66 &= V_2 -> V_16 ;
if ( ! V_66 )
return - V_39 ;
if ( V_68 . V_41 )
V_2 -> V_18 |= V_66 ;
else
V_2 -> V_18 &= ~ V_66 ;
F_10 ( V_2 ) ;
return 0 ;
}
static T_1 F_18 ( struct V_1 * V_2 )
{
T_1 V_69 = 0 ;
if ( V_2 -> V_10 & V_70 ) V_69 |= V_71 ;
if ( V_2 -> V_10 & V_72 ) V_69 |= V_73 ;
if ( V_2 -> V_10 & V_74 ) V_69 |= V_75 ;
if ( V_2 -> V_10 & V_76 ) V_69 |= V_77 ;
if ( V_2 -> V_10 & V_78 ) V_69 |= V_79 ;
return V_69 ;
}
static int F_19 ( struct V_1 * V_2 , T_1 V_41 )
{
V_14 V_10 = 0 , V_80 ;
if ( V_41 & ~ V_81 )
return - V_28 ;
if ( V_41 & V_71 ) V_10 |= V_70 ;
if ( V_41 & V_73 ) V_10 |= V_72 ;
if ( V_41 & V_75 ) V_10 |= V_74 ;
if ( V_41 & V_77 ) V_10 |= V_76 ;
if ( V_41 & V_79 ) V_10 |= V_78 ;
V_80 = ( V_10 ^ V_2 -> V_10 ) & V_82 ;
if ( V_80 & ~ V_2 -> V_16 )
return ( V_80 & V_2 -> V_16 ) ? - V_28 : - V_39 ;
V_2 -> V_18 =
( V_2 -> V_18 & ~ V_80 ) | ( V_10 & V_80 ) ;
F_10 ( V_2 ) ;
return 0 ;
}
int F_20 ( struct V_1 * V_2 , struct V_83 * V_5 )
{
F_21 () ;
if ( ! V_2 -> V_33 || ! V_2 -> V_33 -> V_84 )
return - V_39 ;
memset ( V_5 , 0 , sizeof( struct V_83 ) ) ;
V_5 -> V_5 = V_85 ;
return V_2 -> V_33 -> V_84 ( V_2 , V_5 ) ;
}
static int F_22 ( struct V_1 * V_2 , void T_2 * V_3 )
{
int V_86 ;
struct V_83 V_5 ;
V_86 = F_20 ( V_2 , & V_5 ) ;
if ( V_86 < 0 )
return V_86 ;
if ( F_7 ( V_3 , & V_5 , sizeof( V_5 ) ) )
return - V_22 ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 , void T_2 * V_3 )
{
struct V_83 V_5 ;
if ( ! V_2 -> V_33 -> V_87 )
return - V_39 ;
if ( F_9 ( & V_5 , V_3 , sizeof( V_5 ) ) )
return - V_22 ;
return V_2 -> V_33 -> V_87 ( V_2 , & V_5 ) ;
}
static T_4 int F_24 ( struct V_1 * V_2 ,
void T_2 * V_3 )
{
struct V_88 V_89 ;
const struct V_33 * V_34 = V_2 -> V_33 ;
memset ( & V_89 , 0 , sizeof( V_89 ) ) ;
V_89 . V_5 = V_90 ;
if ( V_34 && V_34 -> V_91 ) {
V_34 -> V_91 ( V_2 , & V_89 ) ;
} else if ( V_2 -> V_2 . V_92 && V_2 -> V_2 . V_92 -> V_93 ) {
F_25 ( V_89 . V_94 , F_26 ( V_2 -> V_2 . V_92 ) ,
sizeof( V_89 . V_94 ) ) ;
F_25 ( V_89 . V_93 , V_2 -> V_2 . V_92 -> V_93 -> V_95 ,
sizeof( V_89 . V_93 ) ) ;
} else {
return - V_39 ;
}
if ( V_34 && V_34 -> V_37 ) {
int V_96 ;
V_96 = V_34 -> V_37 ( V_2 , V_97 ) ;
if ( V_96 >= 0 )
V_89 . V_98 = V_96 ;
V_96 = V_34 -> V_37 ( V_2 , V_99 ) ;
if ( V_96 >= 0 )
V_89 . V_100 = V_96 ;
V_96 = V_34 -> V_37 ( V_2 , V_101 ) ;
if ( V_96 >= 0 )
V_89 . V_102 = V_96 ;
}
if ( V_34 && V_34 -> V_103 )
V_89 . V_104 = V_34 -> V_103 ( V_2 ) ;
if ( V_34 && V_34 -> V_105 )
V_89 . V_106 = V_34 -> V_105 ( V_2 ) ;
if ( F_7 ( V_3 , & V_89 , sizeof( V_89 ) ) )
return - V_22 ;
return 0 ;
}
static T_4 int F_27 ( struct V_1 * V_2 ,
void T_2 * V_3 )
{
struct V_107 V_89 ;
T_5 V_108 ;
int V_13 , V_109 = 0 , V_110 = 0 , V_27 , V_96 ;
T_1 * V_111 = NULL ;
if ( F_9 ( & V_89 , V_3 , sizeof( V_89 ) ) )
return - V_22 ;
V_108 = V_89 . V_108 ;
if ( ! V_108 )
return 0 ;
V_110 = F_28 ( V_108 ) ;
memset ( & V_89 , 0 , sizeof( V_89 ) ) ;
V_89 . V_5 = V_112 ;
V_111 = F_29 ( V_110 * sizeof( T_1 ) , V_113 ) ;
if ( ! V_111 )
return - V_114 ;
for ( V_13 = 0 ; V_13 < 64 ; V_13 ++ ) {
if ( ! ( V_108 & ( 1ULL << V_13 ) ) )
continue;
V_96 = F_11 ( V_2 , V_13 ) ;
if ( V_96 >= 0 ) {
V_89 . V_108 |= ( 1ULL << V_13 ) ;
V_111 [ V_109 ++ ] = V_96 ;
}
}
V_27 = - V_22 ;
if ( F_7 ( V_3 , & V_89 , sizeof( V_89 ) ) )
goto V_115;
V_3 += F_5 ( struct V_107 , V_41 ) ;
if ( F_7 ( V_3 , V_111 , V_109 * sizeof( T_1 ) ) )
goto V_115;
V_27 = 0 ;
V_115:
F_30 ( V_111 ) ;
return V_27 ;
}
static T_4 int F_31 ( struct V_1 * V_2 ,
T_1 V_5 , void T_2 * V_3 )
{
struct V_116 V_89 ;
T_6 V_117 = sizeof( V_89 ) ;
int V_96 ;
if ( ! V_2 -> V_33 -> V_118 )
return - V_39 ;
if ( V_5 == V_119 )
V_117 = ( F_5 ( struct V_116 , V_41 ) +
sizeof( V_89 . V_41 ) ) ;
if ( F_9 ( & V_89 , V_3 , V_117 ) )
return - V_22 ;
V_96 = V_2 -> V_33 -> V_118 ( V_2 , & V_89 ) ;
if ( V_96 )
return V_96 ;
if ( V_5 == V_120 &&
F_7 ( V_3 , & V_89 , V_117 ) )
return - V_22 ;
return 0 ;
}
static T_4 int F_32 ( struct V_1 * V_2 ,
T_1 V_5 , void T_2 * V_3 )
{
struct V_116 V_89 ;
T_6 V_117 = sizeof( V_89 ) ;
const struct V_33 * V_34 = V_2 -> V_33 ;
int V_27 ;
void * V_121 = NULL ;
if ( ! V_34 -> V_122 )
return - V_39 ;
if ( V_5 == V_123 )
V_117 = ( F_5 ( struct V_116 , V_41 ) +
sizeof( V_89 . V_41 ) ) ;
if ( F_9 ( & V_89 , V_3 , V_117 ) )
return - V_22 ;
if ( V_89 . V_5 == V_124 ) {
if ( V_89 . V_125 > 0 ) {
if ( V_89 . V_125 <= V_126 / sizeof( T_1 ) )
V_121 = F_29 ( V_89 . V_125 * sizeof( T_1 ) ,
V_113 ) ;
if ( ! V_121 )
return - V_114 ;
}
}
V_27 = V_34 -> V_122 ( V_2 , & V_89 , V_121 ) ;
if ( V_27 < 0 )
goto V_127;
V_27 = - V_22 ;
if ( F_7 ( V_3 , & V_89 , V_117 ) )
goto V_127;
if ( V_121 ) {
V_3 += F_5 ( struct V_116 , V_128 ) ;
if ( F_7 ( V_3 , V_121 ,
V_89 . V_125 * sizeof( T_1 ) ) )
goto V_127;
}
V_27 = 0 ;
V_127:
F_30 ( V_121 ) ;
return V_27 ;
}
static T_4 int F_33 ( struct V_1 * V_2 ,
void T_2 * V_3 )
{
T_1 V_129 , V_130 ;
T_1 * V_131 ;
int V_27 ;
if ( ! V_2 -> V_33 -> V_132 ||
! V_2 -> V_33 -> V_133 )
return - V_39 ;
V_130 = V_2 -> V_33 -> V_132 ( V_2 ) ;
if ( V_130 == 0 )
return - V_39 ;
if ( F_9 ( & V_129 ,
V_3 + F_5 ( struct V_134 , V_7 ) ,
sizeof( V_129 ) ) )
return - V_22 ;
if ( F_7 ( V_3 + F_5 ( struct V_134 , V_7 ) ,
& V_130 , sizeof( V_130 ) ) )
return - V_22 ;
if ( V_129 < V_130 )
return V_129 == 0 ? 0 : - V_28 ;
V_131 = F_34 ( V_130 , sizeof( V_131 [ 0 ] ) , V_113 ) ;
if ( ! V_131 )
return - V_114 ;
V_27 = V_2 -> V_33 -> V_133 ( V_2 , V_131 ) ;
if ( V_27 )
goto V_115;
if ( F_7 ( V_3 +
F_5 ( struct V_134 , V_135 [ 0 ] ) ,
V_131 , V_130 * sizeof( V_131 [ 0 ] ) ) )
V_27 = - V_22 ;
V_115:
F_30 ( V_131 ) ;
return V_27 ;
}
static T_4 int F_35 ( struct V_1 * V_2 ,
void T_2 * V_3 )
{
struct V_116 V_136 ;
T_1 V_129 , V_130 , V_13 ;
T_1 * V_131 ;
int V_27 ;
if ( ! V_2 -> V_33 -> V_132 ||
! V_2 -> V_33 -> V_137 ||
! V_2 -> V_33 -> V_122 )
return - V_39 ;
V_130 = V_2 -> V_33 -> V_132 ( V_2 ) ;
if ( V_130 == 0 )
return - V_39 ;
if ( F_9 ( & V_129 ,
V_3 + F_5 ( struct V_134 , V_7 ) ,
sizeof( V_129 ) ) )
return - V_22 ;
if ( V_129 != 0 && V_129 != V_130 )
return - V_28 ;
V_131 = F_34 ( V_130 , sizeof( V_131 [ 0 ] ) , V_113 ) ;
if ( ! V_131 )
return - V_114 ;
V_136 . V_5 = V_138 ;
V_27 = V_2 -> V_33 -> V_122 ( V_2 , & V_136 , NULL ) ;
if ( V_27 )
goto V_115;
if ( V_129 == 0 ) {
for ( V_13 = 0 ; V_13 < V_130 ; V_13 ++ )
V_131 [ V_13 ] = F_36 ( V_13 , V_136 . V_41 ) ;
} else {
if ( F_9 ( V_131 ,
V_3 +
F_5 ( struct V_134 ,
V_135 [ 0 ] ) ,
V_130 * sizeof( V_131 [ 0 ] ) ) ) {
V_27 = - V_22 ;
goto V_115;
}
for ( V_13 = 0 ; V_13 < V_130 ; V_13 ++ ) {
if ( V_131 [ V_13 ] >= V_136 . V_41 ) {
V_27 = - V_28 ;
goto V_115;
}
}
}
V_27 = V_2 -> V_33 -> V_137 ( V_2 , V_131 ) ;
V_115:
F_30 ( V_131 ) ;
return V_27 ;
}
static int F_37 ( struct V_1 * V_2 , char T_2 * V_3 )
{
struct V_139 V_140 ;
const struct V_33 * V_34 = V_2 -> V_33 ;
void * V_141 ;
int V_142 , V_27 ;
if ( ! V_34 -> V_143 || ! V_34 -> V_103 )
return - V_39 ;
if ( F_9 ( & V_140 , V_3 , sizeof( V_140 ) ) )
return - V_22 ;
V_142 = V_34 -> V_103 ( V_2 ) ;
if ( V_140 . V_144 > V_142 )
V_140 . V_144 = V_142 ;
V_141 = F_38 ( V_142 ) ;
if ( V_142 && ! V_141 )
return - V_114 ;
V_34 -> V_143 ( V_2 , & V_140 , V_141 ) ;
V_27 = - V_22 ;
if ( F_7 ( V_3 , & V_140 , sizeof( V_140 ) ) )
goto V_115;
V_3 += F_5 ( struct V_139 , V_41 ) ;
if ( V_141 && F_7 ( V_3 , V_141 , V_140 . V_144 ) )
goto V_115;
V_27 = 0 ;
V_115:
F_39 ( V_141 ) ;
return V_27 ;
}
static int F_40 ( struct V_1 * V_2 , char T_2 * V_3 )
{
struct V_67 V_145 ;
int V_27 ;
if ( ! V_2 -> V_33 -> V_145 )
return - V_39 ;
if ( F_9 ( & V_145 , V_3 , sizeof( V_145 ) ) )
return - V_22 ;
V_27 = V_2 -> V_33 -> V_145 ( V_2 , & V_145 . V_41 ) ;
if ( V_27 )
return V_27 ;
if ( F_7 ( V_3 , & V_145 , sizeof( V_145 ) ) )
return - V_22 ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 , char T_2 * V_3 )
{
struct V_146 V_147 = { . V_5 = V_148 } ;
if ( ! V_2 -> V_33 -> V_149 )
return - V_39 ;
V_2 -> V_33 -> V_149 ( V_2 , & V_147 ) ;
if ( F_7 ( V_3 , & V_147 , sizeof( V_147 ) ) )
return - V_22 ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 , char T_2 * V_3 )
{
struct V_146 V_147 ;
if ( ! V_2 -> V_33 -> V_150 )
return - V_39 ;
if ( F_9 ( & V_147 , V_3 , sizeof( V_147 ) ) )
return - V_22 ;
return V_2 -> V_33 -> V_150 ( V_2 , & V_147 ) ;
}
static int F_43 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_33 -> V_151 )
return - V_39 ;
return V_2 -> V_33 -> V_151 ( V_2 ) ;
}
static int F_44 ( struct V_1 * V_2 , char T_2 * V_3 )
{
struct V_67 V_68 = { . V_5 = V_152 } ;
if ( ! V_2 -> V_33 -> V_153 )
return - V_39 ;
V_68 . V_41 = F_45 ( V_2 ) && V_2 -> V_33 -> V_153 ( V_2 ) ;
if ( F_7 ( V_3 , & V_68 , sizeof( V_68 ) ) )
return - V_22 ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 , void T_2 * V_3 )
{
struct V_154 V_155 ;
const struct V_33 * V_34 = V_2 -> V_33 ;
void T_2 * V_156 = V_3 + sizeof( V_155 ) ;
T_1 V_157 ;
T_3 * V_41 ;
int V_27 = 0 ;
if ( ! V_34 -> V_158 || ! V_34 -> V_105 )
return - V_39 ;
if ( F_9 ( & V_155 , V_3 , sizeof( V_155 ) ) )
return - V_22 ;
if ( V_155 . V_159 + V_155 . V_144 <= V_155 . V_159 )
return - V_28 ;
if ( V_155 . V_159 + V_155 . V_144 > V_34 -> V_105 ( V_2 ) )
return - V_28 ;
V_41 = F_47 ( V_160 , V_113 ) ;
if ( ! V_41 )
return - V_114 ;
V_157 = V_155 . V_144 ;
while ( V_157 > 0 ) {
V_155 . V_144 = F_48 ( V_157 , ( T_1 ) V_160 ) ;
V_27 = V_34 -> V_158 ( V_2 , & V_155 , V_41 ) ;
if ( V_27 )
break;
if ( F_7 ( V_156 , V_41 , V_155 . V_144 ) ) {
V_27 = - V_22 ;
break;
}
V_156 += V_155 . V_144 ;
V_155 . V_159 += V_155 . V_144 ;
V_157 -= V_155 . V_144 ;
}
V_155 . V_144 = V_156 - ( V_3 + sizeof( V_155 ) ) ;
V_155 . V_159 -= V_155 . V_144 ;
if ( F_7 ( V_3 , & V_155 , sizeof( V_155 ) ) )
V_27 = - V_22 ;
F_30 ( V_41 ) ;
return V_27 ;
}
static int F_49 ( struct V_1 * V_2 , void T_2 * V_3 )
{
struct V_154 V_155 ;
const struct V_33 * V_34 = V_2 -> V_33 ;
void T_2 * V_156 = V_3 + sizeof( V_155 ) ;
T_1 V_157 ;
T_3 * V_41 ;
int V_27 = 0 ;
if ( ! V_34 -> V_161 || ! V_34 -> V_105 )
return - V_39 ;
if ( F_9 ( & V_155 , V_3 , sizeof( V_155 ) ) )
return - V_22 ;
if ( V_155 . V_159 + V_155 . V_144 <= V_155 . V_159 )
return - V_28 ;
if ( V_155 . V_159 + V_155 . V_144 > V_34 -> V_105 ( V_2 ) )
return - V_28 ;
V_41 = F_47 ( V_160 , V_113 ) ;
if ( ! V_41 )
return - V_114 ;
V_157 = V_155 . V_144 ;
while ( V_157 > 0 ) {
V_155 . V_144 = F_48 ( V_157 , ( T_1 ) V_160 ) ;
if ( F_9 ( V_41 , V_156 , V_155 . V_144 ) ) {
V_27 = - V_22 ;
break;
}
V_27 = V_34 -> V_161 ( V_2 , & V_155 , V_41 ) ;
if ( V_27 )
break;
V_156 += V_155 . V_144 ;
V_155 . V_159 += V_155 . V_144 ;
V_157 -= V_155 . V_144 ;
}
F_30 ( V_41 ) ;
return V_27 ;
}
static T_4 int F_50 ( struct V_1 * V_2 ,
void T_2 * V_3 )
{
struct V_162 V_163 = { . V_5 = V_164 } ;
if ( ! V_2 -> V_33 -> V_165 )
return - V_39 ;
V_2 -> V_33 -> V_165 ( V_2 , & V_163 ) ;
if ( F_7 ( V_3 , & V_163 , sizeof( V_163 ) ) )
return - V_22 ;
return 0 ;
}
static T_4 int F_51 ( struct V_1 * V_2 ,
void T_2 * V_3 )
{
struct V_162 V_163 ;
if ( ! V_2 -> V_33 -> V_166 )
return - V_39 ;
if ( F_9 ( & V_163 , V_3 , sizeof( V_163 ) ) )
return - V_22 ;
return V_2 -> V_33 -> V_166 ( V_2 , & V_163 ) ;
}
static int F_52 ( struct V_1 * V_2 , void T_2 * V_3 )
{
struct V_167 V_168 = { . V_5 = V_169 } ;
if ( ! V_2 -> V_33 -> V_170 )
return - V_39 ;
V_2 -> V_33 -> V_170 ( V_2 , & V_168 ) ;
if ( F_7 ( V_3 , & V_168 , sizeof( V_168 ) ) )
return - V_22 ;
return 0 ;
}
static int F_53 ( struct V_1 * V_2 , void T_2 * V_3 )
{
struct V_167 V_168 ;
if ( ! V_2 -> V_33 -> V_171 )
return - V_39 ;
if ( F_9 ( & V_168 , V_3 , sizeof( V_168 ) ) )
return - V_22 ;
return V_2 -> V_33 -> V_171 ( V_2 , & V_168 ) ;
}
static T_4 int F_54 ( struct V_1 * V_2 ,
void T_2 * V_3 )
{
struct V_172 V_173 = { . V_5 = V_174 } ;
if ( ! V_2 -> V_33 -> V_175 )
return - V_39 ;
V_2 -> V_33 -> V_175 ( V_2 , & V_173 ) ;
if ( F_7 ( V_3 , & V_173 , sizeof( V_173 ) ) )
return - V_22 ;
return 0 ;
}
static T_4 int F_55 ( struct V_1 * V_2 ,
void T_2 * V_3 )
{
struct V_172 V_173 ;
if ( ! V_2 -> V_33 -> V_176 )
return - V_39 ;
if ( F_9 ( & V_173 , V_3 , sizeof( V_173 ) ) )
return - V_22 ;
return V_2 -> V_33 -> V_176 ( V_2 , & V_173 ) ;
}
static int F_56 ( struct V_1 * V_2 , void T_2 * V_3 )
{
struct V_177 V_178 = { V_179 } ;
if ( ! V_2 -> V_33 -> V_180 )
return - V_39 ;
V_2 -> V_33 -> V_180 ( V_2 , & V_178 ) ;
if ( F_7 ( V_3 , & V_178 , sizeof( V_178 ) ) )
return - V_22 ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 , void T_2 * V_3 )
{
struct V_177 V_178 ;
if ( ! V_2 -> V_33 -> V_181 )
return - V_39 ;
if ( F_9 ( & V_178 , V_3 , sizeof( V_178 ) ) )
return - V_22 ;
return V_2 -> V_33 -> V_181 ( V_2 , & V_178 ) ;
}
static int F_58 ( struct V_1 * V_2 , char T_2 * V_3 )
{
struct V_182 V_183 ;
const struct V_33 * V_34 = V_2 -> V_33 ;
T_5 * V_41 ;
int V_27 , V_184 ;
if ( ! V_34 -> V_185 || ! V_34 -> V_37 )
return - V_39 ;
V_184 = V_34 -> V_37 ( V_2 , V_97 ) ;
if ( V_184 < 0 )
return V_184 ;
F_59 ( V_184 == 0 ) ;
if ( F_9 ( & V_183 , V_3 , sizeof( V_183 ) ) )
return - V_22 ;
V_183 . V_144 = V_184 ;
V_41 = F_47 ( V_184 * sizeof( T_5 ) , V_113 ) ;
if ( ! V_41 )
return - V_114 ;
V_34 -> V_185 ( V_2 , & V_183 , V_41 ) ;
V_27 = - V_22 ;
if ( F_7 ( V_3 , & V_183 , sizeof( V_183 ) ) )
goto V_115;
V_3 += sizeof( V_183 ) ;
if ( F_7 ( V_3 , V_41 , V_183 . V_144 * sizeof( T_5 ) ) )
goto V_115;
V_27 = 0 ;
V_115:
F_30 ( V_41 ) ;
return V_27 ;
}
static int F_60 ( struct V_1 * V_2 , void T_2 * V_3 )
{
struct V_186 V_187 ;
T_3 * V_41 ;
int V_27 ;
if ( F_9 ( & V_187 , V_3 , sizeof( V_187 ) ) )
return - V_22 ;
V_27 = F_11 ( V_2 , V_187 . V_188 ) ;
if ( V_27 < 0 )
return V_27 ;
V_187 . V_144 = V_27 ;
V_41 = F_47 ( V_187 . V_144 * V_189 , V_113 ) ;
if ( ! V_41 )
return - V_114 ;
F_13 ( V_2 , V_187 . V_188 , V_41 ) ;
V_27 = - V_22 ;
if ( F_7 ( V_3 , & V_187 , sizeof( V_187 ) ) )
goto V_115;
V_3 += sizeof( V_187 ) ;
if ( F_7 ( V_3 , V_41 , V_187 . V_144 * V_189 ) )
goto V_115;
V_27 = 0 ;
V_115:
F_30 ( V_41 ) ;
return V_27 ;
}
static int F_61 ( struct V_1 * V_2 , void T_2 * V_3 )
{
struct V_67 V_190 ;
static bool V_191 ;
int V_96 ;
if ( ! V_2 -> V_33 -> V_192 )
return - V_39 ;
if ( V_191 )
return - V_193 ;
if ( F_9 ( & V_190 , V_3 , sizeof( V_190 ) ) )
return - V_22 ;
V_96 = V_2 -> V_33 -> V_192 ( V_2 , V_194 ) ;
if ( V_96 < 0 )
return V_96 ;
V_191 = true ;
F_62 ( V_2 ) ;
F_63 () ;
if ( V_96 == 0 ) {
F_64 (
V_190 . V_41 ? ( V_190 . V_41 * V_195 ) : V_196 ) ;
} else {
int V_197 = V_96 * 2 , V_13 , V_198 = V_195 / V_197 ;
do {
V_13 = V_197 ;
do {
F_65 () ;
V_96 = V_2 -> V_33 -> V_192 ( V_2 ,
( V_13 & 1 ) ? V_199 : V_200 ) ;
F_63 () ;
if ( V_96 )
break;
F_64 ( V_198 ) ;
} while ( ! F_66 ( V_201 ) && -- V_13 != 0 );
} while ( ! F_66 ( V_201 ) &&
( V_190 . V_41 == 0 || -- V_190 . V_41 != 0 ) );
}
F_65 () ;
F_67 ( V_2 ) ;
V_191 = false ;
( void ) V_2 -> V_33 -> V_192 ( V_2 , V_202 ) ;
return V_96 ;
}
static int F_68 ( struct V_1 * V_2 , void T_2 * V_3 )
{
struct V_203 V_204 ;
const struct V_33 * V_34 = V_2 -> V_33 ;
T_5 * V_41 ;
int V_27 , V_100 ;
if ( ! V_34 -> V_205 || ! V_34 -> V_37 )
return - V_39 ;
V_100 = V_34 -> V_37 ( V_2 , V_99 ) ;
if ( V_100 < 0 )
return V_100 ;
F_59 ( V_100 == 0 ) ;
if ( F_9 ( & V_204 , V_3 , sizeof( V_204 ) ) )
return - V_22 ;
V_204 . V_100 = V_100 ;
V_41 = F_47 ( V_100 * sizeof( T_5 ) , V_113 ) ;
if ( ! V_41 )
return - V_114 ;
V_34 -> V_205 ( V_2 , & V_204 , V_41 ) ;
V_27 = - V_22 ;
if ( F_7 ( V_3 , & V_204 , sizeof( V_204 ) ) )
goto V_115;
V_3 += sizeof( V_204 ) ;
if ( F_7 ( V_3 , V_41 , V_204 . V_100 * sizeof( T_5 ) ) )
goto V_115;
V_27 = 0 ;
V_115:
F_30 ( V_41 ) ;
return V_27 ;
}
static int F_69 ( struct V_1 * V_2 , void T_2 * V_3 )
{
struct V_206 V_207 ;
if ( F_9 ( & V_207 , V_3 , sizeof( V_207 ) ) )
return - V_22 ;
if ( V_207 . V_7 < V_2 -> V_208 )
return - V_209 ;
V_207 . V_7 = V_2 -> V_208 ;
if ( F_7 ( V_3 , & V_207 , sizeof( V_207 ) ) )
return - V_22 ;
V_3 += sizeof( V_207 ) ;
if ( F_7 ( V_3 , V_2 -> V_210 , V_207 . V_7 ) )
return - V_22 ;
return 0 ;
}
static int F_70 ( struct V_1 * V_2 , char T_2 * V_3 ,
T_1 V_5 , T_1 (* F_71)( struct V_1 * ) )
{
struct V_67 V_68 = { . V_5 = V_5 } ;
if ( ! F_71 )
return - V_39 ;
V_68 . V_41 = F_71 ( V_2 ) ;
if ( F_7 ( V_3 , & V_68 , sizeof( V_68 ) ) )
return - V_22 ;
return 0 ;
}
static int F_72 ( struct V_1 * V_2 , char T_2 * V_3 ,
void (* F_71)( struct V_1 * , T_1 ) )
{
struct V_67 V_68 ;
if ( ! F_71 )
return - V_39 ;
if ( F_9 ( & V_68 , V_3 , sizeof( V_68 ) ) )
return - V_22 ;
F_71 ( V_2 , V_68 . V_41 ) ;
return 0 ;
}
static int F_73 ( struct V_1 * V_2 , char T_2 * V_3 ,
int (* F_71)( struct V_1 * , T_1 ) )
{
struct V_67 V_68 ;
if ( ! F_71 )
return - V_39 ;
if ( F_9 ( & V_68 , V_3 , sizeof( V_68 ) ) )
return - V_22 ;
return F_71 ( V_2 , V_68 . V_41 ) ;
}
static T_4 int F_74 ( struct V_1 * V_2 ,
char T_2 * V_3 )
{
struct V_211 V_212 ;
if ( F_9 ( & V_212 , V_3 , sizeof( V_212 ) ) )
return - V_22 ;
if ( ! V_2 -> V_33 -> V_213 )
return - V_39 ;
V_212 . V_41 [ V_214 - 1 ] = 0 ;
return V_2 -> V_33 -> V_213 ( V_2 , & V_212 ) ;
}
static int F_75 ( struct V_1 * V_2 ,
void T_2 * V_3 )
{
struct V_215 V_216 ;
if ( ! V_2 -> V_33 -> V_217 )
return - V_39 ;
if ( F_9 ( & V_216 , V_3 , sizeof( V_216 ) ) )
return - V_22 ;
return V_2 -> V_33 -> V_217 ( V_2 , & V_216 ) ;
}
static int F_76 ( struct V_1 * V_2 ,
void T_2 * V_3 )
{
int V_27 ;
struct V_215 V_216 ;
const struct V_33 * V_34 = V_2 -> V_33 ;
if ( ! V_2 -> V_33 -> V_218 )
return - V_39 ;
if ( F_9 ( & V_216 , V_3 , sizeof( V_216 ) ) )
return - V_22 ;
V_27 = V_34 -> V_218 ( V_2 , & V_216 ) ;
if ( V_27 )
return V_27 ;
if ( F_7 ( V_3 , & V_216 , sizeof( V_216 ) ) )
return - V_22 ;
return 0 ;
}
static int F_77 ( struct V_1 * V_2 ,
void T_2 * V_3 )
{
int V_27 ;
T_7 V_144 ;
struct V_215 V_216 , V_219 ;
const struct V_33 * V_34 = V_2 -> V_33 ;
void * V_41 = NULL ;
if ( ! V_2 -> V_33 -> V_220 ||
! V_2 -> V_33 -> V_218 )
return - V_39 ;
if ( F_9 ( & V_216 , V_3 , sizeof( V_216 ) ) )
return - V_22 ;
memset ( & V_219 , 0 , sizeof( V_219 ) ) ;
V_219 . V_5 = V_221 ;
V_27 = V_34 -> V_218 ( V_2 , & V_219 ) ;
if ( V_27 )
return V_27 ;
V_144 = ( V_219 . V_144 > V_216 . V_144 ) ? V_216 . V_144 : V_219 . V_144 ;
if ( ! V_144 )
return - V_22 ;
V_41 = F_38 ( V_219 . V_144 ) ;
if ( ! V_41 )
return - V_114 ;
V_27 = V_34 -> V_220 ( V_2 , & V_216 , V_41 ) ;
if ( V_27 )
goto V_115;
if ( F_7 ( V_3 , & V_216 , sizeof( V_216 ) ) ) {
V_27 = - V_22 ;
goto V_115;
}
V_3 += F_5 ( struct V_215 , V_41 ) ;
if ( F_7 ( V_3 , V_41 , V_144 ) )
V_27 = - V_22 ;
V_115:
F_39 ( V_41 ) ;
return V_27 ;
}
int F_78 ( struct V_222 * V_222 , struct V_223 * V_224 )
{
struct V_1 * V_2 = F_79 ( V_222 , V_224 -> V_225 ) ;
void T_2 * V_3 = V_224 -> V_226 ;
T_1 V_65 ;
int V_96 ;
T_1 V_227 ;
if ( ! V_2 || ! F_80 ( V_2 ) )
return - V_228 ;
if ( F_9 ( & V_65 , V_3 , sizeof( V_65 ) ) )
return - V_22 ;
if ( ! V_2 -> V_33 ) {
if ( V_65 == V_90 )
return F_24 ( V_2 , V_3 ) ;
else
return - V_39 ;
}
switch ( V_65 ) {
case V_85 :
case V_90 :
case V_229 :
case V_164 :
case V_169 :
case V_179 :
case V_47 :
case V_43 :
case V_50 :
case V_112 :
case V_230 :
case V_53 :
case V_231 :
case V_56 :
case V_59 :
case V_62 :
case V_232 :
case V_233 :
case V_123 :
case V_138 :
case V_234 :
case V_235 :
case V_124 :
case V_6 :
break;
default:
if ( ! F_81 ( V_236 ) )
return - V_237 ;
}
if ( V_2 -> V_33 -> V_238 ) {
V_96 = V_2 -> V_33 -> V_238 ( V_2 ) ;
if ( V_96 < 0 )
return V_96 ;
}
V_227 = V_2 -> V_10 ;
switch ( V_65 ) {
case V_85 :
V_96 = F_22 ( V_2 , V_3 ) ;
break;
case V_239 :
V_96 = F_23 ( V_2 , V_3 ) ;
break;
case V_90 :
V_96 = F_24 ( V_2 , V_3 ) ;
break;
case V_240 :
V_96 = F_37 ( V_2 , V_3 ) ;
break;
case V_148 :
V_96 = F_41 ( V_2 , V_3 ) ;
break;
case V_241 :
V_96 = F_42 ( V_2 , V_3 ) ;
break;
case V_229 :
V_96 = F_70 ( V_2 , V_3 , V_65 ,
V_2 -> V_33 -> V_242 ) ;
break;
case V_243 :
V_96 = F_72 ( V_2 , V_3 ,
V_2 -> V_33 -> V_244 ) ;
break;
case V_245 :
V_96 = F_43 ( V_2 ) ;
break;
case V_152 :
V_96 = F_44 ( V_2 , V_3 ) ;
break;
case V_246 :
V_96 = F_46 ( V_2 , V_3 ) ;
break;
case V_247 :
V_96 = F_49 ( V_2 , V_3 ) ;
break;
case V_164 :
V_96 = F_50 ( V_2 , V_3 ) ;
break;
case V_248 :
V_96 = F_51 ( V_2 , V_3 ) ;
break;
case V_169 :
V_96 = F_52 ( V_2 , V_3 ) ;
break;
case V_249 :
V_96 = F_53 ( V_2 , V_3 ) ;
break;
case V_179 :
V_96 = F_56 ( V_2 , V_3 ) ;
break;
case V_250 :
V_96 = F_57 ( V_2 , V_3 ) ;
break;
case V_251 :
V_96 = F_58 ( V_2 , V_3 ) ;
break;
case V_230 :
V_96 = F_60 ( V_2 , V_3 ) ;
break;
case V_252 :
V_96 = F_61 ( V_2 , V_3 ) ;
break;
case V_253 :
V_96 = F_68 ( V_2 , V_3 ) ;
break;
case V_231 :
V_96 = F_69 ( V_2 , V_3 ) ;
break;
case V_232 :
V_96 = F_70 ( V_2 , V_3 , V_65 ,
F_18 ) ;
break;
case V_254 :
V_96 = F_73 ( V_2 , V_3 , F_19 ) ;
break;
case V_233 :
V_96 = F_70 ( V_2 , V_3 , V_65 ,
V_2 -> V_33 -> V_255 ) ;
break;
case V_256 :
V_96 = F_73 ( V_2 , V_3 ,
V_2 -> V_33 -> V_257 ) ;
break;
case V_123 :
case V_138 :
case V_234 :
case V_235 :
case V_124 :
V_96 = F_32 ( V_2 , V_65 , V_3 ) ;
break;
case V_119 :
case V_258 :
case V_120 :
V_96 = F_31 ( V_2 , V_65 , V_3 ) ;
break;
case V_259 :
V_96 = F_74 ( V_2 , V_3 ) ;
break;
case V_260 :
V_96 = F_40 ( V_2 , V_3 ) ;
break;
case V_112 :
V_96 = F_27 ( V_2 , V_3 ) ;
break;
case V_261 :
V_96 = F_33 ( V_2 , V_3 ) ;
break;
case V_262 :
V_96 = F_35 ( V_2 , V_3 ) ;
break;
case V_6 :
V_96 = F_3 ( V_2 , V_3 ) ;
break;
case V_263 :
V_96 = F_8 ( V_2 , V_3 ) ;
break;
case V_43 :
case V_47 :
case V_50 :
case V_53 :
case V_56 :
case V_59 :
case V_62 :
V_96 = F_16 ( V_2 , V_3 , V_65 ) ;
break;
case V_44 :
case V_48 :
case V_51 :
case V_54 :
case V_57 :
case V_60 :
case V_63 :
V_96 = F_17 ( V_2 , V_3 , V_65 ) ;
break;
case V_174 :
V_96 = F_54 ( V_2 , V_3 ) ;
break;
case V_264 :
V_96 = F_55 ( V_2 , V_3 ) ;
break;
case V_265 :
V_96 = F_75 ( V_2 , V_3 ) ;
break;
case V_221 :
V_96 = F_76 ( V_2 , V_3 ) ;
break;
case V_266 :
V_96 = F_77 ( V_2 , V_3 ) ;
break;
default:
V_96 = - V_39 ;
}
if ( V_2 -> V_33 -> V_267 )
V_2 -> V_33 -> V_267 ( V_2 ) ;
if ( V_227 != V_2 -> V_10 )
F_82 ( V_2 ) ;
return V_96 ;
}
