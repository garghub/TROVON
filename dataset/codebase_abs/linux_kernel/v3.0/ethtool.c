T_1 F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 ) ? 1 : 0 ;
}
T_1 F_3 ( struct V_1 * V_2 )
{
return ( V_2 -> V_3 & V_4 ) != 0 ;
}
int F_4 ( struct V_1 * V_2 , T_1 V_5 )
{
if ( V_5 )
V_2 -> V_3 |= V_6 ;
else
V_2 -> V_3 &= ~ V_6 ;
return 0 ;
}
int F_5 ( struct V_1 * V_2 , T_1 V_5 )
{
if ( V_5 )
V_2 -> V_3 |= V_7 ;
else
V_2 -> V_3 &= ~ V_7 ;
return 0 ;
}
int F_6 ( struct V_1 * V_2 , T_1 V_5 )
{
if ( V_5 )
V_2 -> V_3 |= V_6 | V_8 ;
else
V_2 -> V_3 &= ~ ( V_6 | V_8 ) ;
return 0 ;
}
T_1 F_7 ( struct V_1 * V_2 )
{
return ( V_2 -> V_3 & V_9 ) != 0 ;
}
int F_8 ( struct V_1 * V_2 , T_1 V_5 )
{
if ( V_5 )
V_2 -> V_3 |= V_9 ;
else
V_2 -> V_3 &= ~ V_9 ;
return 0 ;
}
T_1 F_9 ( struct V_1 * V_2 )
{
return ( V_2 -> V_3 & V_10 ) != 0 ;
}
int F_10 ( struct V_1 * V_2 , T_1 V_5 )
{
if ( V_5 )
V_2 -> V_3 |= V_10 ;
else
V_2 -> V_3 &= ~ V_10 ;
return 0 ;
}
T_1 F_11 ( struct V_1 * V_2 )
{
return ( V_2 -> V_3 & V_11 ) != 0 ;
}
int F_12 ( struct V_1 * V_2 , T_1 V_5 )
{
if ( V_5 )
V_2 -> V_3 |= V_11 ;
else
V_2 -> V_3 &= ~ V_11 ;
return 0 ;
}
T_1 F_13 ( struct V_1 * V_2 )
{
return V_2 -> V_3 & V_12 ;
}
bool F_14 ( struct V_1 * V_2 , T_1 V_5 , T_1 V_13 )
{
T_1 V_3 = V_2 -> V_3 & V_12 ;
return ( V_3 & ~ V_13 ) != ( V_5 & ~ V_13 ) ;
}
int F_15 ( struct V_1 * V_2 , T_1 V_5 , T_1 V_13 )
{
if ( F_14 ( V_2 , V_5 , V_13 ) )
return - V_14 ;
V_2 -> V_3 = ( ( V_2 -> V_3 & ~ V_12 ) |
( V_5 & V_12 ) ) ;
return 0 ;
}
void F_16 ( struct V_1 * V_2 )
{
struct V_15 * V_16 , * V_17 ;
F_17 (fsc, f, &dev->ethtool_ntuple_list.list, list) {
F_18 ( & V_16 -> V_18 ) ;
F_19 ( V_16 ) ;
}
V_2 -> V_19 . V_20 = 0 ;
}
static void F_20 ( struct V_1 * V_2 ,
struct V_21 * V_3 )
{
if ( ! V_2 -> V_22 )
return;
if ( V_2 -> V_22 -> V_23 )
if ( V_2 -> V_22 -> V_23 ( V_2 ) )
V_3 [ 0 ] . V_24 |= V_25 ;
if ( V_2 -> V_22 -> V_26 )
V_3 [ 0 ] . V_27 |= V_9 ;
if ( V_2 -> V_22 -> V_28 )
V_3 [ 0 ] . V_27 |= V_4 ;
if ( V_2 -> V_22 -> V_29 )
V_3 [ 0 ] . V_27 |= V_30 ;
if ( V_2 -> V_22 -> V_31 )
V_3 [ 0 ] . V_27 |= V_25 ;
if ( V_2 -> V_22 -> V_32 )
V_3 [ 0 ] . V_27 |= V_12 ;
}
static int F_21 ( struct V_1 * V_2 ,
int (* F_22)( struct V_1 * , T_1 ) ,
struct V_33 * V_3 , T_1 V_34 )
{
T_1 V_35 ;
if ( ! F_22 )
return 0 ;
if ( ! ( V_3 [ 0 ] . V_36 & V_34 ) )
return 0 ;
V_3 [ 0 ] . V_36 &= ~ V_34 ;
V_35 = ! ! ( V_3 [ 0 ] . V_37 & V_34 ) ;
if ( F_22 ( V_2 , V_35 ) < 0 )
F_23 ( V_2 ,
L_1 ,
V_35 ? L_2 : L_3 , V_34 ) ;
return 1 ;
}
static int F_24 ( struct V_1 * V_2 ,
int (* F_22)( struct V_1 * , T_1 ) ,
struct V_33 * V_3 , T_1 V_34 )
{
T_1 V_38 ;
if ( ! F_22 )
return 0 ;
if ( ! ( V_3 [ 0 ] . V_36 & V_34 ) )
return 0 ;
V_38 = V_2 -> V_3 & ~ V_3 [ 0 ] . V_36 ;
V_38 |= V_3 [ 0 ] . V_37 ;
V_3 [ 0 ] . V_36 &= ~ V_34 ;
if ( F_22 ( V_2 , V_38 & V_34 ) < 0 )
F_23 ( V_2 , L_4 ) ;
return 1 ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_33 * V_3 )
{
int V_39 ;
if ( ! V_2 -> V_22 )
return 0 ;
V_39 = F_21 ( V_2 , V_2 -> V_22 -> V_26 ,
V_3 , V_9 ) ;
V_39 |= F_21 ( V_2 , V_2 -> V_22 -> V_28 ,
V_3 , V_4 ) ;
V_39 |= F_21 ( V_2 , V_2 -> V_22 -> V_29 ,
V_3 , V_30 ) ;
V_39 |= F_21 ( V_2 , V_2 -> V_22 -> V_31 ,
V_3 , V_25 ) ;
V_39 |= F_24 ( V_2 , V_2 -> V_22 -> V_32 ,
V_3 , V_12 ) ;
return V_39 ;
}
static int F_26 ( struct V_1 * V_2 , void T_2 * V_40 )
{
struct V_41 V_42 = {
. V_42 = V_43 ,
. V_44 = V_45 ,
} ;
struct V_21 V_3 [ V_45 ] = {
{
. V_27 = V_2 -> V_46 ,
. V_37 = V_2 -> V_47 ,
. V_24 = V_2 -> V_3 ,
. V_48 = V_49 ,
} ,
} ;
T_1 T_2 * V_50 ;
T_1 V_51 ;
F_20 ( V_2 , V_3 ) ;
V_50 = V_40 + F_27 ( struct V_41 , V_44 ) ;
if ( F_28 ( V_51 , V_50 ) )
return - V_52 ;
if ( V_51 > V_45 )
V_51 = V_45 ;
if ( F_29 ( V_40 , & V_42 , sizeof( V_42 ) ) )
return - V_52 ;
V_40 += sizeof( V_42 ) ;
if ( F_29 ( V_40 , V_3 , V_51 * sizeof( * V_3 ) ) )
return - V_52 ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 , void T_2 * V_40 )
{
struct V_53 V_42 ;
struct V_33 V_3 [ V_45 ] ;
int V_54 = 0 ;
if ( F_31 ( & V_42 , V_40 , sizeof( V_42 ) ) )
return - V_52 ;
V_40 += sizeof( V_42 ) ;
if ( V_42 . V_44 != V_45 )
return - V_14 ;
if ( F_31 ( V_3 , V_40 , sizeof( V_3 ) ) )
return - V_52 ;
if ( V_3 [ 0 ] . V_36 & ~ V_55 )
return - V_14 ;
if ( F_25 ( V_2 , V_3 ) )
V_54 |= V_56 ;
if ( V_3 [ 0 ] . V_36 & ~ V_2 -> V_46 ) {
V_3 [ 0 ] . V_36 &= V_2 -> V_46 ;
V_54 |= V_57 ;
}
V_2 -> V_47 &= ~ V_3 [ 0 ] . V_36 ;
V_2 -> V_47 |= V_3 [ 0 ] . V_36 & V_3 [ 0 ] . V_37 ;
F_32 ( V_2 ) ;
if ( ( V_2 -> V_47 ^ V_2 -> V_3 ) & V_3 [ 0 ] . V_36 )
V_54 |= V_58 ;
return V_54 ;
}
static int F_33 ( struct V_1 * V_2 , int V_59 )
{
const struct V_22 * V_60 = V_2 -> V_22 ;
if ( V_59 == V_61 )
return F_34 ( V_62 ) ;
if ( V_60 && V_60 -> V_63 && V_60 -> V_64 )
return V_60 -> V_63 ( V_2 , V_59 ) ;
else
return - V_65 ;
}
static void F_35 ( struct V_1 * V_2 ,
T_1 V_66 , T_3 * V_5 )
{
const struct V_22 * V_60 = V_2 -> V_22 ;
if ( V_66 == V_61 )
memcpy ( V_5 , V_62 ,
sizeof( V_62 ) ) ;
else
V_60 -> V_64 ( V_2 , V_66 , V_5 ) ;
}
static T_1 F_36 ( T_1 V_67 )
{
switch ( V_67 ) {
case V_68 :
case V_69 :
return V_4 | V_70 ;
case V_71 :
case V_72 :
return V_25 ;
case V_73 :
case V_74 :
return V_9 ;
case V_75 :
case V_76 :
return V_30 ;
case V_77 :
case V_78 :
return V_11 ;
case V_79 :
case V_80 :
return V_81 ;
case V_82 :
case V_83 :
return V_84 ;
default:
F_37 () ;
}
}
static void * F_38 ( struct V_1 * V_2 , T_1 V_85 )
{
const struct V_22 * V_60 = V_2 -> V_22 ;
if ( ! V_60 )
return NULL ;
switch ( V_85 ) {
case V_68 :
return V_60 -> V_86 ;
case V_71 :
return V_60 -> V_23 ;
case V_74 :
return V_60 -> V_87 ;
case V_76 :
return V_60 -> V_88 ;
case V_78 :
return V_60 -> V_89 ;
default:
return NULL ;
}
}
static T_1 F_39 ( struct V_1 * V_2 )
{
return ! ! ( V_2 -> V_3 & V_4 ) ;
}
static int F_40 ( struct V_1 * V_2 ,
char T_2 * V_40 , T_1 V_85 )
{
T_1 V_34 = F_36 ( V_85 ) ;
struct V_90 V_91 = {
. V_42 = V_85 ,
. V_5 = ! ! ( V_2 -> V_3 & V_34 ) ,
} ;
if ( ! ( V_2 -> V_46 & V_34 ) ) {
T_1 (* F_41)( struct V_1 * );
F_41 = F_38 ( V_2 , V_85 ) ;
if ( V_85 == V_71 && ! F_41 )
F_41 = F_39 ;
if ( F_41 )
V_91 . V_5 = F_41 ( V_2 ) ;
}
if ( F_29 ( V_40 , & V_91 , sizeof( V_91 ) ) )
return - V_52 ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 ,
void T_2 * V_40 , T_1 V_85 )
{
struct V_90 V_91 ;
T_1 V_34 ;
if ( F_31 ( & V_91 , V_40 , sizeof( V_91 ) ) )
return - V_52 ;
V_34 = F_36 ( V_85 ) ;
V_34 &= V_2 -> V_46 ;
if ( V_34 ) {
if ( V_91 . V_5 )
V_2 -> V_47 |= V_34 ;
else
V_2 -> V_47 &= ~ V_34 ;
F_32 ( V_2 ) ;
return 0 ;
}
switch ( V_85 ) {
case V_69 :
return F_43 ( V_2 , V_91 . V_5 ) ;
case V_72 :
return F_44 ( V_2 , V_91 . V_5 ) ;
case V_74 :
return F_45 ( V_2 , V_91 . V_5 ) ;
case V_76 :
return F_46 ( V_2 , V_91 . V_5 ) ;
case V_78 :
return F_47 ( V_2 , V_91 . V_5 ) ;
default:
return - V_65 ;
}
}
int F_48 ( struct V_1 * V_2 , T_1 V_5 )
{
T_1 V_92 ;
if ( V_5 & ~ V_12 )
return - V_14 ;
if ( V_2 -> V_22 -> V_32 ) {
if ( F_49 ( V_2 -> V_46 & V_12 ) )
F_50 ( V_2 ,
L_5 ) ;
return V_2 -> V_22 -> V_32 ( V_2 , V_5 ) ;
}
V_92 = ( V_5 ^ V_2 -> V_3 ) & V_12 ;
if ( V_92 & ~ V_2 -> V_46 )
return ( V_92 & V_2 -> V_46 ) ? - V_14 : - V_65 ;
V_2 -> V_47 =
( V_2 -> V_47 & ~ V_92 ) | ( V_5 & V_2 -> V_46 ) ;
F_32 ( V_2 ) ;
return 0 ;
}
static int F_51 ( struct V_1 * V_2 , void T_2 * V_40 )
{
struct V_93 V_42 = { . V_42 = V_94 } ;
int V_95 ;
if ( ! V_2 -> V_22 -> V_96 )
return - V_65 ;
V_95 = V_2 -> V_22 -> V_96 ( V_2 , & V_42 ) ;
if ( V_95 < 0 )
return V_95 ;
if ( F_29 ( V_40 , & V_42 , sizeof( V_42 ) ) )
return - V_52 ;
return 0 ;
}
static int F_52 ( struct V_1 * V_2 , void T_2 * V_40 )
{
struct V_93 V_42 ;
if ( ! V_2 -> V_22 -> V_97 )
return - V_65 ;
if ( F_31 ( & V_42 , V_40 , sizeof( V_42 ) ) )
return - V_52 ;
return V_2 -> V_22 -> V_97 ( V_2 , & V_42 ) ;
}
static T_4 int F_53 ( struct V_1 * V_2 ,
void T_2 * V_40 )
{
struct V_98 V_99 ;
const struct V_22 * V_60 = V_2 -> V_22 ;
memset ( & V_99 , 0 , sizeof( V_99 ) ) ;
V_99 . V_42 = V_100 ;
if ( V_60 && V_60 -> V_101 ) {
V_60 -> V_101 ( V_2 , & V_99 ) ;
} else if ( V_2 -> V_2 . V_102 && V_2 -> V_2 . V_102 -> V_103 ) {
F_54 ( V_99 . V_104 , F_55 ( V_2 -> V_2 . V_102 ) ,
sizeof( V_99 . V_104 ) ) ;
F_54 ( V_99 . V_103 , V_2 -> V_2 . V_102 -> V_103 -> V_105 ,
sizeof( V_99 . V_103 ) ) ;
} else {
return - V_65 ;
}
if ( V_60 && V_60 -> V_63 ) {
int V_106 ;
V_106 = V_60 -> V_63 ( V_2 , V_107 ) ;
if ( V_106 >= 0 )
V_99 . V_108 = V_106 ;
V_106 = V_60 -> V_63 ( V_2 , V_109 ) ;
if ( V_106 >= 0 )
V_99 . V_110 = V_106 ;
V_106 = V_60 -> V_63 ( V_2 , V_111 ) ;
if ( V_106 >= 0 )
V_99 . V_112 = V_106 ;
}
if ( V_60 && V_60 -> V_113 )
V_99 . V_114 = V_60 -> V_113 ( V_2 ) ;
if ( V_60 && V_60 -> V_115 )
V_99 . V_116 = V_60 -> V_115 ( V_2 ) ;
if ( F_29 ( V_40 , & V_99 , sizeof( V_99 ) ) )
return - V_52 ;
return 0 ;
}
static T_4 int F_56 ( struct V_1 * V_2 ,
void T_2 * V_40 )
{
struct V_117 V_99 ;
T_5 V_118 ;
int V_119 , V_120 = 0 , V_121 = 0 , V_54 , V_106 ;
T_1 * V_122 = NULL ;
if ( F_31 ( & V_99 , V_40 , sizeof( V_99 ) ) )
return - V_52 ;
V_118 = V_99 . V_118 ;
if ( ! V_118 )
return 0 ;
V_121 = F_57 ( V_118 ) ;
memset ( & V_99 , 0 , sizeof( V_99 ) ) ;
V_99 . V_42 = V_123 ;
V_122 = F_58 ( V_121 * sizeof( T_1 ) , V_124 ) ;
if ( ! V_122 )
return - V_125 ;
for ( V_119 = 0 ; V_119 < 64 ; V_119 ++ ) {
if ( ! ( V_118 & ( 1ULL << V_119 ) ) )
continue;
V_106 = F_33 ( V_2 , V_119 ) ;
if ( V_106 >= 0 ) {
V_99 . V_118 |= ( 1ULL << V_119 ) ;
V_122 [ V_120 ++ ] = V_106 ;
}
}
V_54 = - V_52 ;
if ( F_29 ( V_40 , & V_99 , sizeof( V_99 ) ) )
goto V_126;
V_40 += F_27 ( struct V_117 , V_5 ) ;
if ( F_29 ( V_40 , V_122 , V_120 * sizeof( T_1 ) ) )
goto V_126;
V_54 = 0 ;
V_126:
F_19 ( V_122 ) ;
return V_54 ;
}
static T_4 int F_59 ( struct V_1 * V_2 ,
T_1 V_42 , void T_2 * V_40 )
{
struct V_127 V_99 ;
T_6 V_128 = sizeof( V_99 ) ;
if ( ! V_2 -> V_22 -> V_129 )
return - V_65 ;
if ( V_42 == V_130 )
V_128 = ( F_27 ( struct V_127 , V_5 ) +
sizeof( V_99 . V_5 ) ) ;
if ( F_31 ( & V_99 , V_40 , V_128 ) )
return - V_52 ;
return V_2 -> V_22 -> V_129 ( V_2 , & V_99 ) ;
}
static T_4 int F_60 ( struct V_1 * V_2 ,
T_1 V_42 , void T_2 * V_40 )
{
struct V_127 V_99 ;
T_6 V_128 = sizeof( V_99 ) ;
const struct V_22 * V_60 = V_2 -> V_22 ;
int V_54 ;
void * V_131 = NULL ;
if ( ! V_60 -> V_132 )
return - V_65 ;
if ( V_42 == V_133 )
V_128 = ( F_27 ( struct V_127 , V_5 ) +
sizeof( V_99 . V_5 ) ) ;
if ( F_31 ( & V_99 , V_40 , V_128 ) )
return - V_52 ;
if ( V_99 . V_42 == V_134 ) {
if ( V_99 . V_135 > 0 ) {
if ( V_99 . V_135 <= V_136 / sizeof( T_1 ) )
V_131 = F_58 ( V_99 . V_135 * sizeof( T_1 ) ,
V_124 ) ;
if ( ! V_131 )
return - V_125 ;
}
}
V_54 = V_60 -> V_132 ( V_2 , & V_99 , V_131 ) ;
if ( V_54 < 0 )
goto V_137;
V_54 = - V_52 ;
if ( F_29 ( V_40 , & V_99 , V_128 ) )
goto V_137;
if ( V_131 ) {
V_40 += F_27 ( struct V_127 , V_138 ) ;
if ( F_29 ( V_40 , V_131 ,
V_99 . V_135 * sizeof( T_1 ) ) )
goto V_137;
}
V_54 = 0 ;
V_137:
F_19 ( V_131 ) ;
return V_54 ;
}
static T_4 int F_61 ( struct V_1 * V_2 ,
void T_2 * V_40 )
{
struct V_139 * V_140 ;
T_1 V_141 ;
T_6 V_142 ;
int V_54 ;
if ( ! V_2 -> V_22 -> V_143 )
return - V_65 ;
if ( F_31 ( & V_141 ,
V_40 + F_27 ( struct V_139 , V_44 ) ,
sizeof( V_141 ) ) )
return - V_52 ;
if ( V_141 >
( V_136 - sizeof( * V_140 ) ) / sizeof( * V_140 -> V_144 ) )
return - V_125 ;
V_142 = sizeof( * V_140 ) + sizeof( * V_140 -> V_144 ) * V_141 ;
V_140 = F_58 ( V_142 , V_124 ) ;
if ( ! V_140 )
return - V_125 ;
V_140 -> V_42 = V_145 ;
V_140 -> V_44 = V_141 ;
V_54 = V_2 -> V_22 -> V_143 ( V_2 , V_140 ) ;
if ( V_54 )
goto V_126;
if ( F_29 ( V_40 , V_140 , V_142 ) )
V_54 = - V_52 ;
V_126:
F_19 ( V_140 ) ;
return V_54 ;
}
static T_4 int F_62 ( struct V_1 * V_2 ,
void T_2 * V_40 )
{
struct V_139 * V_140 ;
T_1 V_141 ;
T_6 V_142 ;
int V_54 ;
if ( ! V_2 -> V_22 -> V_146 )
return - V_65 ;
if ( F_31 ( & V_141 ,
V_40 + F_27 ( struct V_139 , V_44 ) ,
sizeof( V_141 ) ) )
return - V_52 ;
if ( V_141 >
( V_136 - sizeof( * V_140 ) ) / sizeof( * V_140 -> V_144 ) )
return - V_125 ;
V_142 = sizeof( * V_140 ) + sizeof( * V_140 -> V_144 ) * V_141 ;
V_140 = F_63 ( V_142 , V_124 ) ;
if ( ! V_140 )
return - V_125 ;
if ( F_31 ( V_140 , V_40 , V_142 ) ) {
V_54 = - V_52 ;
goto V_126;
}
V_54 = V_2 -> V_22 -> V_146 ( V_2 , V_140 ) ;
V_126:
F_19 ( V_140 ) ;
return V_54 ;
}
static void F_64 ( struct V_147 * V_18 ,
struct V_148 * V_149 ,
struct V_15 * V_16 )
{
if ( V_18 -> V_20 >= V_150 ) {
F_19 ( V_16 ) ;
return;
}
V_16 -> V_151 . V_152 = V_149 -> V_152 ;
memcpy ( & V_16 -> V_151 . V_153 , & V_149 -> V_153 , sizeof( V_149 -> V_153 ) ) ;
memcpy ( & V_16 -> V_151 . V_154 , & V_149 -> V_154 , sizeof( V_149 -> V_154 ) ) ;
V_16 -> V_151 . V_155 = V_149 -> V_155 ;
V_16 -> V_151 . V_156 = V_149 -> V_156 ;
V_16 -> V_151 . V_5 = V_149 -> V_5 ;
V_16 -> V_151 . V_157 = V_149 -> V_157 ;
V_16 -> V_151 . V_158 = V_149 -> V_158 ;
F_65 ( & V_16 -> V_18 , & V_18 -> V_18 ) ;
V_18 -> V_20 ++ ;
}
static void F_66 ( struct V_148 * V_151 )
{
struct V_159 * V_160 = & V_151 -> V_153 . V_161 ;
struct V_159 * V_34 = & V_151 -> V_154 . V_161 ;
if ( V_151 -> V_152 != V_162 &&
V_151 -> V_152 != V_163 &&
V_151 -> V_152 != V_164 )
return;
if ( ! ( V_160 -> V_165 | V_34 -> V_165 ) )
V_34 -> V_165 = F_67 ( 0xffffffff ) ;
if ( ! ( V_160 -> V_166 | V_34 -> V_166 ) )
V_34 -> V_166 = F_67 ( 0xffffffff ) ;
if ( ! ( V_160 -> V_167 | V_34 -> V_167 ) )
V_34 -> V_167 = F_68 ( 0xffff ) ;
if ( ! ( V_160 -> V_168 | V_34 -> V_168 ) )
V_34 -> V_168 = F_68 ( 0xffff ) ;
if ( ! ( V_160 -> V_169 | V_34 -> V_169 ) )
V_34 -> V_169 = 0xff ;
if ( ! ( V_151 -> V_155 | V_151 -> V_156 ) )
V_151 -> V_156 = 0xffff ;
if ( ! ( V_151 -> V_5 | V_151 -> V_157 ) )
V_151 -> V_157 = 0xffffffffffffffffULL ;
}
static T_4 int F_69 ( struct V_1 * V_2 ,
void T_2 * V_40 )
{
struct V_170 V_42 ;
const struct V_22 * V_60 = V_2 -> V_22 ;
struct V_15 * V_16 = NULL ;
int V_54 ;
if ( ! V_60 -> V_171 )
return - V_65 ;
if ( ! ( V_2 -> V_3 & V_172 ) )
return - V_14 ;
if ( F_31 ( & V_42 , V_40 , sizeof( V_42 ) ) )
return - V_52 ;
F_66 ( & V_42 . V_151 ) ;
if ( ! V_60 -> V_173 ) {
V_16 = F_63 ( sizeof( * V_16 ) , V_174 ) ;
if ( ! V_16 )
return - V_125 ;
}
V_54 = V_60 -> V_171 ( V_2 , & V_42 ) ;
if ( V_54 ) {
F_19 ( V_16 ) ;
return V_54 ;
}
if ( ! V_60 -> V_173 )
F_64 ( & V_2 -> V_19 , & V_42 . V_151 , V_16 ) ;
return V_54 ;
}
static int F_70 ( struct V_1 * V_2 , void T_2 * V_40 )
{
struct V_175 V_176 ;
const struct V_22 * V_60 = V_2 -> V_22 ;
struct V_15 * V_16 ;
T_3 * V_5 ;
char * V_177 ;
int V_54 , V_119 , V_178 = 0 ;
if ( ! V_60 -> V_63 )
return - V_65 ;
if ( F_31 ( & V_176 , V_40 , sizeof( V_176 ) ) )
return - V_52 ;
V_54 = V_60 -> V_63 ( V_2 , V_176 . V_179 ) ;
if ( V_54 < 0 )
return V_54 ;
V_176 . V_180 = V_54 ;
V_5 = F_58 ( V_176 . V_180 * V_181 , V_124 ) ;
if ( ! V_5 )
return - V_125 ;
if ( V_60 -> V_173 ) {
V_54 = V_60 -> V_173 ( V_2 , V_176 . V_179 , V_5 ) ;
goto V_182;
}
V_119 = 0 ;
V_177 = ( char * ) V_5 ;
F_71 (fsc, &dev->ethtool_ntuple_list.list, list) {
sprintf ( V_177 , L_6 , V_119 ) ;
V_177 += V_181 ;
V_178 ++ ;
switch ( V_16 -> V_151 . V_152 ) {
case V_162 :
sprintf ( V_177 , L_7 ) ;
V_177 += V_181 ;
V_178 ++ ;
break;
case V_163 :
sprintf ( V_177 , L_8 ) ;
V_177 += V_181 ;
V_178 ++ ;
break;
case V_164 :
sprintf ( V_177 , L_9 ) ;
V_177 += V_181 ;
V_178 ++ ;
break;
case V_183 :
sprintf ( V_177 , L_10 ) ;
V_177 += V_181 ;
V_178 ++ ;
break;
case V_184 :
sprintf ( V_177 , L_11 ) ;
V_177 += V_181 ;
V_178 ++ ;
break;
case V_185 :
sprintf ( V_177 , L_12 ) ;
V_177 += V_181 ;
V_178 ++ ;
break;
case V_186 :
sprintf ( V_177 , L_13 ) ;
V_177 += V_181 ;
V_178 ++ ;
break;
default:
sprintf ( V_177 , L_14 ) ;
V_177 += V_181 ;
V_178 ++ ;
goto V_187;
}
switch ( V_16 -> V_151 . V_152 ) {
case V_162 :
case V_163 :
case V_164 :
sprintf ( V_177 , L_15 ,
V_16 -> V_151 . V_153 . V_161 . V_165 ) ;
V_177 += V_181 ;
V_178 ++ ;
sprintf ( V_177 , L_16 ,
V_16 -> V_151 . V_154 . V_161 . V_165 ) ;
V_177 += V_181 ;
V_178 ++ ;
sprintf ( V_177 , L_17 ,
V_16 -> V_151 . V_153 . V_161 . V_166 ) ;
V_177 += V_181 ;
V_178 ++ ;
sprintf ( V_177 , L_18 ,
V_16 -> V_151 . V_154 . V_161 . V_166 ) ;
V_177 += V_181 ;
V_178 ++ ;
sprintf ( V_177 , L_19 ,
V_16 -> V_151 . V_153 . V_161 . V_167 ,
V_16 -> V_151 . V_154 . V_161 . V_167 ) ;
V_177 += V_181 ;
V_178 ++ ;
sprintf ( V_177 , L_20 ,
V_16 -> V_151 . V_153 . V_161 . V_168 ,
V_16 -> V_151 . V_154 . V_161 . V_168 ) ;
V_177 += V_181 ;
V_178 ++ ;
sprintf ( V_177 , L_21 ,
V_16 -> V_151 . V_153 . V_161 . V_169 ,
V_16 -> V_151 . V_154 . V_161 . V_169 ) ;
V_177 += V_181 ;
V_178 ++ ;
break;
case V_183 :
case V_184 :
sprintf ( V_177 , L_15 ,
V_16 -> V_151 . V_153 . V_188 . V_165 ) ;
V_177 += V_181 ;
V_178 ++ ;
sprintf ( V_177 , L_16 ,
V_16 -> V_151 . V_154 . V_188 . V_165 ) ;
V_177 += V_181 ;
V_178 ++ ;
sprintf ( V_177 , L_17 ,
V_16 -> V_151 . V_153 . V_188 . V_166 ) ;
V_177 += V_181 ;
V_178 ++ ;
sprintf ( V_177 , L_18 ,
V_16 -> V_151 . V_154 . V_188 . V_166 ) ;
V_177 += V_181 ;
V_178 ++ ;
sprintf ( V_177 , L_22 ,
V_16 -> V_151 . V_153 . V_188 . V_189 ,
V_16 -> V_151 . V_154 . V_188 . V_189 ) ;
V_177 += V_181 ;
V_178 ++ ;
sprintf ( V_177 , L_21 ,
V_16 -> V_151 . V_153 . V_188 . V_169 ,
V_16 -> V_151 . V_154 . V_188 . V_169 ) ;
V_177 += V_181 ;
V_178 ++ ;
break;
case V_185 :
sprintf ( V_177 , L_15 ,
V_16 -> V_151 . V_153 . V_190 . V_165 ) ;
V_177 += V_181 ;
V_178 ++ ;
sprintf ( V_177 , L_16 ,
V_16 -> V_151 . V_154 . V_190 . V_165 ) ;
V_177 += V_181 ;
V_178 ++ ;
sprintf ( V_177 , L_17 ,
V_16 -> V_151 . V_153 . V_190 . V_166 ) ;
V_177 += V_181 ;
V_178 ++ ;
sprintf ( V_177 , L_18 ,
V_16 -> V_151 . V_154 . V_190 . V_166 ) ;
V_177 += V_181 ;
V_178 ++ ;
break;
case V_186 :
sprintf ( V_177 , L_15 ,
V_16 -> V_151 . V_153 . V_190 . V_165 ) ;
V_177 += V_181 ;
V_178 ++ ;
sprintf ( V_177 , L_16 ,
V_16 -> V_151 . V_154 . V_190 . V_165 ) ;
V_177 += V_181 ;
V_178 ++ ;
sprintf ( V_177 , L_17 ,
V_16 -> V_151 . V_153 . V_190 . V_166 ) ;
V_177 += V_181 ;
V_178 ++ ;
sprintf ( V_177 , L_18 ,
V_16 -> V_151 . V_154 . V_190 . V_166 ) ;
V_177 += V_181 ;
V_178 ++ ;
sprintf ( V_177 , L_23 ,
V_16 -> V_151 . V_153 . V_190 . V_191 ,
V_16 -> V_151 . V_154 . V_190 . V_191 ) ;
V_177 += V_181 ;
V_178 ++ ;
sprintf ( V_177 , L_21 ,
V_16 -> V_151 . V_153 . V_190 . V_169 ,
V_16 -> V_151 . V_154 . V_190 . V_169 ) ;
V_177 += V_181 ;
V_178 ++ ;
sprintf ( V_177 , L_24 ,
V_16 -> V_151 . V_153 . V_190 . V_192 ,
V_16 -> V_151 . V_154 . V_190 . V_192 ) ;
V_177 += V_181 ;
V_178 ++ ;
sprintf ( V_177 , L_25 ,
V_16 -> V_151 . V_153 . V_190 . V_193 ,
V_16 -> V_151 . V_154 . V_190 . V_193 ) ;
V_177 += V_181 ;
V_178 ++ ;
break;
}
sprintf ( V_177 , L_26 ,
V_16 -> V_151 . V_155 , V_16 -> V_151 . V_156 ) ;
V_177 += V_181 ;
V_178 ++ ;
sprintf ( V_177 , L_27 , V_16 -> V_151 . V_5 ) ;
V_177 += V_181 ;
V_178 ++ ;
sprintf ( V_177 , L_28 , V_16 -> V_151 . V_157 ) ;
V_177 += V_181 ;
V_178 ++ ;
if ( V_16 -> V_151 . V_158 == V_194 )
sprintf ( V_177 , L_29 ) ;
else
sprintf ( V_177 , L_30 ,
V_16 -> V_151 . V_158 ) ;
V_177 += V_181 ;
V_178 ++ ;
V_187:
V_119 ++ ;
}
V_182:
V_176 . V_180 = V_178 ;
V_54 = - V_52 ;
if ( F_29 ( V_40 , & V_176 , sizeof( V_176 ) ) )
goto V_126;
V_40 += sizeof( V_176 ) ;
if ( F_29 ( V_40 , V_5 , V_176 . V_180 * V_181 ) )
goto V_126;
V_54 = 0 ;
V_126:
F_19 ( V_5 ) ;
return V_54 ;
}
static int F_72 ( struct V_1 * V_2 , char T_2 * V_40 )
{
struct V_195 V_196 ;
const struct V_22 * V_60 = V_2 -> V_22 ;
void * V_197 ;
int V_198 , V_54 ;
if ( ! V_60 -> V_199 || ! V_60 -> V_113 )
return - V_65 ;
if ( F_31 ( & V_196 , V_40 , sizeof( V_196 ) ) )
return - V_52 ;
V_198 = V_60 -> V_113 ( V_2 ) ;
if ( V_196 . V_180 > V_198 )
V_196 . V_180 = V_198 ;
V_197 = F_73 ( V_198 ) ;
if ( ! V_197 )
return - V_125 ;
V_60 -> V_199 ( V_2 , & V_196 , V_197 ) ;
V_54 = - V_52 ;
if ( F_29 ( V_40 , & V_196 , sizeof( V_196 ) ) )
goto V_126;
V_40 += F_27 ( struct V_195 , V_5 ) ;
if ( F_29 ( V_40 , V_197 , V_196 . V_180 ) )
goto V_126;
V_54 = 0 ;
V_126:
F_74 ( V_197 ) ;
return V_54 ;
}
static int F_75 ( struct V_1 * V_2 , char T_2 * V_40 )
{
struct V_90 V_200 ;
int V_54 ;
if ( ! V_2 -> V_22 -> V_200 )
return - V_65 ;
if ( F_31 ( & V_200 , V_40 , sizeof( V_200 ) ) )
return - V_52 ;
V_54 = V_2 -> V_22 -> V_200 ( V_2 , & V_200 . V_5 ) ;
if ( V_54 )
return V_54 ;
if ( F_29 ( V_40 , & V_200 , sizeof( V_200 ) ) )
return - V_52 ;
return 0 ;
}
static int F_76 ( struct V_1 * V_2 , char T_2 * V_40 )
{
struct V_201 V_202 = { . V_42 = V_203 } ;
if ( ! V_2 -> V_22 -> V_204 )
return - V_65 ;
V_2 -> V_22 -> V_204 ( V_2 , & V_202 ) ;
if ( F_29 ( V_40 , & V_202 , sizeof( V_202 ) ) )
return - V_52 ;
return 0 ;
}
static int F_77 ( struct V_1 * V_2 , char T_2 * V_40 )
{
struct V_201 V_202 ;
if ( ! V_2 -> V_22 -> V_205 )
return - V_65 ;
if ( F_31 ( & V_202 , V_40 , sizeof( V_202 ) ) )
return - V_52 ;
return V_2 -> V_22 -> V_205 ( V_2 , & V_202 ) ;
}
static int F_78 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_22 -> V_206 )
return - V_65 ;
return V_2 -> V_22 -> V_206 ( V_2 ) ;
}
static int F_79 ( struct V_1 * V_2 , char T_2 * V_40 )
{
struct V_90 V_91 = { . V_42 = V_207 } ;
if ( ! V_2 -> V_22 -> V_208 )
return - V_65 ;
V_91 . V_5 = F_80 ( V_2 ) && V_2 -> V_22 -> V_208 ( V_2 ) ;
if ( F_29 ( V_40 , & V_91 , sizeof( V_91 ) ) )
return - V_52 ;
return 0 ;
}
static int F_81 ( struct V_1 * V_2 , void T_2 * V_40 )
{
struct V_209 V_210 ;
const struct V_22 * V_60 = V_2 -> V_22 ;
void T_2 * V_211 = V_40 + sizeof( V_210 ) ;
T_1 V_212 ;
T_3 * V_5 ;
int V_54 = 0 ;
if ( ! V_60 -> V_213 || ! V_60 -> V_115 )
return - V_65 ;
if ( F_31 ( & V_210 , V_40 , sizeof( V_210 ) ) )
return - V_52 ;
if ( V_210 . V_214 + V_210 . V_180 <= V_210 . V_214 )
return - V_14 ;
if ( V_210 . V_214 + V_210 . V_180 > V_60 -> V_115 ( V_2 ) )
return - V_14 ;
V_5 = F_63 ( V_215 , V_124 ) ;
if ( ! V_5 )
return - V_125 ;
V_212 = V_210 . V_180 ;
while ( V_212 > 0 ) {
V_210 . V_180 = F_82 ( V_212 , ( T_1 ) V_215 ) ;
V_54 = V_60 -> V_213 ( V_2 , & V_210 , V_5 ) ;
if ( V_54 )
break;
if ( F_29 ( V_211 , V_5 , V_210 . V_180 ) ) {
V_54 = - V_52 ;
break;
}
V_211 += V_210 . V_180 ;
V_210 . V_214 += V_210 . V_180 ;
V_212 -= V_210 . V_180 ;
}
V_210 . V_180 = V_211 - ( V_40 + sizeof( V_210 ) ) ;
V_210 . V_214 -= V_210 . V_180 ;
if ( F_29 ( V_40 , & V_210 , sizeof( V_210 ) ) )
V_54 = - V_52 ;
F_19 ( V_5 ) ;
return V_54 ;
}
static int F_83 ( struct V_1 * V_2 , void T_2 * V_40 )
{
struct V_209 V_210 ;
const struct V_22 * V_60 = V_2 -> V_22 ;
void T_2 * V_211 = V_40 + sizeof( V_210 ) ;
T_1 V_212 ;
T_3 * V_5 ;
int V_54 = 0 ;
if ( ! V_60 -> V_216 || ! V_60 -> V_115 )
return - V_65 ;
if ( F_31 ( & V_210 , V_40 , sizeof( V_210 ) ) )
return - V_52 ;
if ( V_210 . V_214 + V_210 . V_180 <= V_210 . V_214 )
return - V_14 ;
if ( V_210 . V_214 + V_210 . V_180 > V_60 -> V_115 ( V_2 ) )
return - V_14 ;
V_5 = F_63 ( V_215 , V_124 ) ;
if ( ! V_5 )
return - V_125 ;
V_212 = V_210 . V_180 ;
while ( V_212 > 0 ) {
V_210 . V_180 = F_82 ( V_212 , ( T_1 ) V_215 ) ;
if ( F_31 ( V_5 , V_211 , V_210 . V_180 ) ) {
V_54 = - V_52 ;
break;
}
V_54 = V_60 -> V_216 ( V_2 , & V_210 , V_5 ) ;
if ( V_54 )
break;
V_211 += V_210 . V_180 ;
V_210 . V_214 += V_210 . V_180 ;
V_212 -= V_210 . V_180 ;
}
F_19 ( V_5 ) ;
return V_54 ;
}
static T_4 int F_84 ( struct V_1 * V_2 ,
void T_2 * V_40 )
{
struct V_217 V_218 = { . V_42 = V_219 } ;
if ( ! V_2 -> V_22 -> V_220 )
return - V_65 ;
V_2 -> V_22 -> V_220 ( V_2 , & V_218 ) ;
if ( F_29 ( V_40 , & V_218 , sizeof( V_218 ) ) )
return - V_52 ;
return 0 ;
}
static T_4 int F_85 ( struct V_1 * V_2 ,
void T_2 * V_40 )
{
struct V_217 V_218 ;
if ( ! V_2 -> V_22 -> V_221 )
return - V_65 ;
if ( F_31 ( & V_218 , V_40 , sizeof( V_218 ) ) )
return - V_52 ;
return V_2 -> V_22 -> V_221 ( V_2 , & V_218 ) ;
}
static int F_86 ( struct V_1 * V_2 , void T_2 * V_40 )
{
struct V_222 V_223 = { . V_42 = V_224 } ;
if ( ! V_2 -> V_22 -> V_225 )
return - V_65 ;
V_2 -> V_22 -> V_225 ( V_2 , & V_223 ) ;
if ( F_29 ( V_40 , & V_223 , sizeof( V_223 ) ) )
return - V_52 ;
return 0 ;
}
static int F_87 ( struct V_1 * V_2 , void T_2 * V_40 )
{
struct V_222 V_223 ;
if ( ! V_2 -> V_22 -> V_226 )
return - V_65 ;
if ( F_31 ( & V_223 , V_40 , sizeof( V_223 ) ) )
return - V_52 ;
return V_2 -> V_22 -> V_226 ( V_2 , & V_223 ) ;
}
static T_4 int F_88 ( struct V_1 * V_2 ,
void T_2 * V_40 )
{
struct V_227 V_228 = { . V_42 = V_229 } ;
if ( ! V_2 -> V_22 -> V_230 )
return - V_65 ;
V_2 -> V_22 -> V_230 ( V_2 , & V_228 ) ;
if ( F_29 ( V_40 , & V_228 , sizeof( V_228 ) ) )
return - V_52 ;
return 0 ;
}
static T_4 int F_89 ( struct V_1 * V_2 ,
void T_2 * V_40 )
{
struct V_227 V_228 ;
if ( ! V_2 -> V_22 -> V_231 )
return - V_65 ;
if ( F_31 ( & V_228 , V_40 , sizeof( V_228 ) ) )
return - V_52 ;
return V_2 -> V_22 -> V_231 ( V_2 , & V_228 ) ;
}
static int F_90 ( struct V_1 * V_2 , void T_2 * V_40 )
{
struct V_232 V_233 = { V_234 } ;
if ( ! V_2 -> V_22 -> V_235 )
return - V_65 ;
V_2 -> V_22 -> V_235 ( V_2 , & V_233 ) ;
if ( F_29 ( V_40 , & V_233 , sizeof( V_233 ) ) )
return - V_52 ;
return 0 ;
}
static int F_91 ( struct V_1 * V_2 , void T_2 * V_40 )
{
struct V_232 V_233 ;
if ( ! V_2 -> V_22 -> V_236 )
return - V_65 ;
if ( F_31 ( & V_233 , V_40 , sizeof( V_233 ) ) )
return - V_52 ;
return V_2 -> V_22 -> V_236 ( V_2 , & V_233 ) ;
}
static int F_45 ( struct V_1 * V_2 , T_1 V_5 )
{
int V_95 ;
if ( ! V_2 -> V_22 -> V_26 )
return - V_65 ;
if ( V_5 && ! ( V_2 -> V_3 & V_4 ) )
return - V_14 ;
if ( ! V_5 && V_2 -> V_22 -> V_29 ) {
V_95 = V_2 -> V_22 -> V_29 ( V_2 , 0 ) ;
if ( V_95 )
return V_95 ;
}
if ( ! V_5 && V_2 -> V_22 -> V_237 ) {
V_95 = V_2 -> V_22 -> V_237 ( V_2 , 0 ) ;
if ( V_95 )
return V_95 ;
}
return V_2 -> V_22 -> V_26 ( V_2 , V_5 ) ;
}
static int F_43 ( struct V_1 * V_2 , T_1 V_5 )
{
int V_95 ;
if ( ! V_2 -> V_22 -> V_28 )
return - V_65 ;
if ( ! V_5 && V_2 -> V_22 -> V_26 ) {
V_95 = F_45 ( V_2 , 0 ) ;
if ( V_95 )
return V_95 ;
}
return V_2 -> V_22 -> V_28 ( V_2 , V_5 ) ;
}
static int F_44 ( struct V_1 * V_2 , T_1 V_5 )
{
if ( ! V_2 -> V_22 -> V_31 )
return - V_65 ;
if ( ! V_5 )
V_2 -> V_3 &= ~ V_84 ;
return V_2 -> V_22 -> V_31 ( V_2 , V_5 ) ;
}
static int F_46 ( struct V_1 * V_2 , T_1 V_5 )
{
if ( ! V_2 -> V_22 -> V_29 )
return - V_65 ;
if ( V_5 && ! ( V_2 -> V_3 & V_9 ) )
return - V_14 ;
return V_2 -> V_22 -> V_29 ( V_2 , V_5 ) ;
}
static int F_47 ( struct V_1 * V_2 , T_1 V_5 )
{
if ( ! V_2 -> V_22 -> V_237 )
return - V_65 ;
if ( V_5 && ! ( V_2 -> V_3 & V_9 ) )
return - V_14 ;
if ( V_5 && ! ( ( V_2 -> V_3 & V_238 ) ||
( V_2 -> V_3 & ( V_6 | V_8 ) )
== ( V_6 | V_8 ) ) )
return - V_14 ;
return V_2 -> V_22 -> V_237 ( V_2 , V_5 ) ;
}
static int F_92 ( struct V_1 * V_2 , char T_2 * V_40 )
{
struct V_239 V_240 ;
const struct V_22 * V_60 = V_2 -> V_22 ;
T_5 * V_5 ;
int V_54 , V_241 ;
if ( ! V_60 -> V_242 || ! V_60 -> V_63 )
return - V_65 ;
V_241 = V_60 -> V_63 ( V_2 , V_107 ) ;
if ( V_241 < 0 )
return V_241 ;
F_93 ( V_241 == 0 ) ;
if ( F_31 ( & V_240 , V_40 , sizeof( V_240 ) ) )
return - V_52 ;
V_240 . V_180 = V_241 ;
V_5 = F_63 ( V_241 * sizeof( T_5 ) , V_124 ) ;
if ( ! V_5 )
return - V_125 ;
V_60 -> V_242 ( V_2 , & V_240 , V_5 ) ;
V_54 = - V_52 ;
if ( F_29 ( V_40 , & V_240 , sizeof( V_240 ) ) )
goto V_126;
V_40 += sizeof( V_240 ) ;
if ( F_29 ( V_40 , V_5 , V_240 . V_180 * sizeof( T_5 ) ) )
goto V_126;
V_54 = 0 ;
V_126:
F_19 ( V_5 ) ;
return V_54 ;
}
static int F_94 ( struct V_1 * V_2 , void T_2 * V_40 )
{
struct V_175 V_176 ;
T_3 * V_5 ;
int V_54 ;
if ( F_31 ( & V_176 , V_40 , sizeof( V_176 ) ) )
return - V_52 ;
V_54 = F_33 ( V_2 , V_176 . V_179 ) ;
if ( V_54 < 0 )
return V_54 ;
V_176 . V_180 = V_54 ;
V_5 = F_63 ( V_176 . V_180 * V_181 , V_124 ) ;
if ( ! V_5 )
return - V_125 ;
F_35 ( V_2 , V_176 . V_179 , V_5 ) ;
V_54 = - V_52 ;
if ( F_29 ( V_40 , & V_176 , sizeof( V_176 ) ) )
goto V_126;
V_40 += sizeof( V_176 ) ;
if ( F_29 ( V_40 , V_5 , V_176 . V_180 * V_181 ) )
goto V_126;
V_54 = 0 ;
V_126:
F_19 ( V_5 ) ;
return V_54 ;
}
static int F_95 ( struct V_1 * V_2 , void T_2 * V_40 )
{
struct V_90 V_243 ;
static bool V_244 ;
int V_106 ;
if ( ! V_2 -> V_22 -> V_245 )
return - V_65 ;
if ( V_244 )
return - V_246 ;
if ( F_31 ( & V_243 , V_40 , sizeof( V_243 ) ) )
return - V_52 ;
V_106 = V_2 -> V_22 -> V_245 ( V_2 , V_247 ) ;
if ( V_106 < 0 )
return V_106 ;
V_244 = true ;
F_96 ( V_2 ) ;
F_97 () ;
if ( V_106 == 0 ) {
F_98 (
V_243 . V_5 ? ( V_243 . V_5 * V_248 ) : V_249 ) ;
} else {
int V_250 = V_106 * 2 , V_119 , V_251 = V_248 / V_250 ;
do {
V_119 = V_250 ;
do {
F_99 () ;
V_106 = V_2 -> V_22 -> V_245 ( V_2 ,
( V_119 & 1 ) ? V_252 : V_253 ) ;
F_97 () ;
if ( V_106 )
break;
F_98 ( V_251 ) ;
} while ( ! F_100 ( V_254 ) && -- V_119 != 0 );
} while ( ! F_100 ( V_254 ) &&
( V_243 . V_5 == 0 || -- V_243 . V_5 != 0 ) );
}
F_99 () ;
F_101 ( V_2 ) ;
V_244 = false ;
( void ) V_2 -> V_22 -> V_245 ( V_2 , V_255 ) ;
return V_106 ;
}
static int F_102 ( struct V_1 * V_2 , void T_2 * V_40 )
{
struct V_256 V_257 ;
const struct V_22 * V_60 = V_2 -> V_22 ;
T_5 * V_5 ;
int V_54 , V_110 ;
if ( ! V_60 -> V_258 || ! V_60 -> V_63 )
return - V_65 ;
V_110 = V_60 -> V_63 ( V_2 , V_109 ) ;
if ( V_110 < 0 )
return V_110 ;
F_93 ( V_110 == 0 ) ;
if ( F_31 ( & V_257 , V_40 , sizeof( V_257 ) ) )
return - V_52 ;
V_257 . V_110 = V_110 ;
V_5 = F_63 ( V_110 * sizeof( T_5 ) , V_124 ) ;
if ( ! V_5 )
return - V_125 ;
V_60 -> V_258 ( V_2 , & V_257 , V_5 ) ;
V_54 = - V_52 ;
if ( F_29 ( V_40 , & V_257 , sizeof( V_257 ) ) )
goto V_126;
V_40 += sizeof( V_257 ) ;
if ( F_29 ( V_40 , V_5 , V_257 . V_110 * sizeof( T_5 ) ) )
goto V_126;
V_54 = 0 ;
V_126:
F_19 ( V_5 ) ;
return V_54 ;
}
static int F_103 ( struct V_1 * V_2 , void T_2 * V_40 )
{
struct V_259 V_260 ;
if ( F_31 ( & V_260 , V_40 , sizeof( V_260 ) ) )
return - V_52 ;
if ( V_260 . V_44 < V_2 -> V_261 )
return - V_262 ;
V_260 . V_44 = V_2 -> V_261 ;
if ( F_29 ( V_40 , & V_260 , sizeof( V_260 ) ) )
return - V_52 ;
V_40 += sizeof( V_260 ) ;
if ( F_29 ( V_40 , V_2 -> V_263 , V_260 . V_44 ) )
return - V_52 ;
return 0 ;
}
static int F_104 ( struct V_1 * V_2 , char T_2 * V_40 ,
T_1 V_42 , T_1 (* F_41)( struct V_1 * ) )
{
struct V_90 V_91 = { . V_42 = V_42 } ;
if ( ! F_41 )
return - V_65 ;
V_91 . V_5 = F_41 ( V_2 ) ;
if ( F_29 ( V_40 , & V_91 , sizeof( V_91 ) ) )
return - V_52 ;
return 0 ;
}
static int F_105 ( struct V_1 * V_2 , char T_2 * V_40 ,
void (* F_41)( struct V_1 * , T_1 ) )
{
struct V_90 V_91 ;
if ( ! F_41 )
return - V_65 ;
if ( F_31 ( & V_91 , V_40 , sizeof( V_91 ) ) )
return - V_52 ;
F_41 ( V_2 , V_91 . V_5 ) ;
return 0 ;
}
static int F_106 ( struct V_1 * V_2 , char T_2 * V_40 ,
int (* F_41)( struct V_1 * , T_1 ) )
{
struct V_90 V_91 ;
if ( ! F_41 )
return - V_65 ;
if ( F_31 ( & V_91 , V_40 , sizeof( V_91 ) ) )
return - V_52 ;
return F_41 ( V_2 , V_91 . V_5 ) ;
}
static T_4 int F_107 ( struct V_1 * V_2 ,
char T_2 * V_40 )
{
struct V_264 V_265 ;
if ( F_31 ( & V_265 , V_40 , sizeof( V_265 ) ) )
return - V_52 ;
if ( ! V_2 -> V_22 -> V_266 )
return - V_65 ;
return V_2 -> V_22 -> V_266 ( V_2 , & V_265 ) ;
}
static int F_108 ( struct V_1 * V_2 ,
void T_2 * V_40 )
{
struct V_267 V_268 ;
if ( ! V_2 -> V_22 -> V_269 )
return - V_65 ;
if ( F_31 ( & V_268 , V_40 , sizeof( V_268 ) ) )
return - V_52 ;
return V_2 -> V_22 -> V_269 ( V_2 , & V_268 ) ;
}
static int F_109 ( struct V_1 * V_2 ,
void T_2 * V_40 )
{
int V_54 ;
struct V_267 V_268 ;
const struct V_22 * V_60 = V_2 -> V_22 ;
if ( ! V_2 -> V_22 -> V_270 )
return - V_65 ;
if ( F_31 ( & V_268 , V_40 , sizeof( V_268 ) ) )
return - V_52 ;
V_54 = V_60 -> V_270 ( V_2 , & V_268 ) ;
if ( V_54 )
return V_54 ;
if ( F_29 ( V_40 , & V_268 , sizeof( V_268 ) ) )
return - V_52 ;
return 0 ;
}
static int F_110 ( struct V_1 * V_2 ,
void T_2 * V_40 )
{
int V_54 ;
T_7 V_180 ;
struct V_267 V_268 , V_271 ;
const struct V_22 * V_60 = V_2 -> V_22 ;
void * V_5 = NULL ;
if ( ! V_2 -> V_22 -> V_272 ||
! V_2 -> V_22 -> V_270 )
return - V_65 ;
if ( F_31 ( & V_268 , V_40 , sizeof( V_268 ) ) )
return - V_52 ;
memset ( & V_271 , 0 , sizeof( V_271 ) ) ;
V_271 . V_42 = V_273 ;
V_54 = V_60 -> V_270 ( V_2 , & V_271 ) ;
if ( V_54 )
return V_54 ;
V_180 = ( V_271 . V_180 > V_268 . V_180 ) ? V_268 . V_180 : V_271 . V_180 ;
if ( ! V_180 )
return - V_52 ;
V_5 = F_73 ( V_271 . V_180 ) ;
if ( ! V_5 )
return - V_125 ;
V_54 = V_60 -> V_272 ( V_2 , & V_268 , V_5 ) ;
if ( V_54 )
goto V_126;
if ( F_29 ( V_40 , & V_268 , sizeof( V_268 ) ) ) {
V_54 = - V_52 ;
goto V_126;
}
V_40 += F_27 ( struct V_267 , V_5 ) ;
if ( F_29 ( V_40 , V_5 , V_180 ) )
V_54 = - V_52 ;
V_126:
F_74 ( V_5 ) ;
return V_54 ;
}
int F_111 ( struct V_274 * V_274 , struct V_275 * V_276 )
{
struct V_1 * V_2 = F_112 ( V_274 , V_276 -> V_277 ) ;
void T_2 * V_40 = V_276 -> V_278 ;
T_1 V_85 ;
int V_106 ;
T_1 V_279 ;
if ( ! V_2 || ! F_113 ( V_2 ) )
return - V_280 ;
if ( F_31 ( & V_85 , V_40 , sizeof( V_85 ) ) )
return - V_52 ;
if ( ! V_2 -> V_22 ) {
if ( V_85 == V_100 )
return F_53 ( V_2 , V_40 ) ;
else
return - V_65 ;
}
switch ( V_85 ) {
case V_94 :
case V_100 :
case V_281 :
case V_219 :
case V_224 :
case V_234 :
case V_71 :
case V_68 :
case V_73 :
case V_282 :
case V_75 :
case V_283 :
case V_77 :
case V_79 :
case V_82 :
case V_284 :
case V_285 :
case V_133 :
case V_286 :
case V_287 :
case V_288 :
case V_134 :
case V_43 :
break;
default:
if ( ! F_114 ( V_289 ) )
return - V_290 ;
}
if ( V_2 -> V_22 -> V_291 ) {
V_106 = V_2 -> V_22 -> V_291 ( V_2 ) ;
if ( V_106 < 0 )
return V_106 ;
}
V_279 = V_2 -> V_3 ;
switch ( V_85 ) {
case V_94 :
V_106 = F_51 ( V_2 , V_40 ) ;
break;
case V_292 :
V_106 = F_52 ( V_2 , V_40 ) ;
break;
case V_100 :
V_106 = F_53 ( V_2 , V_40 ) ;
break;
case V_293 :
V_106 = F_72 ( V_2 , V_40 ) ;
break;
case V_203 :
V_106 = F_76 ( V_2 , V_40 ) ;
break;
case V_294 :
V_106 = F_77 ( V_2 , V_40 ) ;
break;
case V_281 :
V_106 = F_104 ( V_2 , V_40 , V_85 ,
V_2 -> V_22 -> V_295 ) ;
break;
case V_296 :
V_106 = F_105 ( V_2 , V_40 ,
V_2 -> V_22 -> V_297 ) ;
break;
case V_298 :
V_106 = F_78 ( V_2 ) ;
break;
case V_207 :
V_106 = F_79 ( V_2 , V_40 ) ;
break;
case V_299 :
V_106 = F_81 ( V_2 , V_40 ) ;
break;
case V_300 :
V_106 = F_83 ( V_2 , V_40 ) ;
break;
case V_219 :
V_106 = F_84 ( V_2 , V_40 ) ;
break;
case V_301 :
V_106 = F_85 ( V_2 , V_40 ) ;
break;
case V_224 :
V_106 = F_86 ( V_2 , V_40 ) ;
break;
case V_302 :
V_106 = F_87 ( V_2 , V_40 ) ;
break;
case V_234 :
V_106 = F_90 ( V_2 , V_40 ) ;
break;
case V_303 :
V_106 = F_91 ( V_2 , V_40 ) ;
break;
case V_304 :
V_106 = F_92 ( V_2 , V_40 ) ;
break;
case V_282 :
V_106 = F_94 ( V_2 , V_40 ) ;
break;
case V_305 :
V_106 = F_95 ( V_2 , V_40 ) ;
break;
case V_306 :
V_106 = F_102 ( V_2 , V_40 ) ;
break;
case V_283 :
V_106 = F_103 ( V_2 , V_40 ) ;
break;
case V_284 :
V_106 = F_104 ( V_2 , V_40 , V_85 ,
( V_2 -> V_22 -> V_307 ?
V_2 -> V_22 -> V_307 :
F_13 ) ) ;
break;
case V_308 :
V_106 = F_106 ( V_2 , V_40 , F_48 ) ;
break;
case V_285 :
V_106 = F_104 ( V_2 , V_40 , V_85 ,
V_2 -> V_22 -> V_309 ) ;
break;
case V_310 :
V_106 = F_106 ( V_2 , V_40 ,
V_2 -> V_22 -> V_311 ) ;
break;
case V_133 :
case V_286 :
case V_287 :
case V_288 :
case V_134 :
V_106 = F_60 ( V_2 , V_85 , V_40 ) ;
break;
case V_130 :
case V_312 :
case V_313 :
V_106 = F_59 ( V_2 , V_85 , V_40 ) ;
break;
case V_314 :
V_106 = F_107 ( V_2 , V_40 ) ;
break;
case V_315 :
V_106 = F_75 ( V_2 , V_40 ) ;
break;
case V_316 :
V_106 = F_69 ( V_2 , V_40 ) ;
break;
case V_317 :
V_106 = F_70 ( V_2 , V_40 ) ;
break;
case V_123 :
V_106 = F_56 ( V_2 , V_40 ) ;
break;
case V_145 :
V_106 = F_61 ( V_2 , V_40 ) ;
break;
case V_318 :
V_106 = F_62 ( V_2 , V_40 ) ;
break;
case V_43 :
V_106 = F_26 ( V_2 , V_40 ) ;
break;
case V_319 :
V_106 = F_30 ( V_2 , V_40 ) ;
break;
case V_68 :
case V_71 :
case V_73 :
case V_75 :
case V_77 :
case V_79 :
case V_82 :
V_106 = F_40 ( V_2 , V_40 , V_85 ) ;
break;
case V_69 :
case V_72 :
case V_74 :
case V_76 :
case V_78 :
case V_80 :
case V_83 :
V_106 = F_42 ( V_2 , V_40 , V_85 ) ;
break;
case V_229 :
V_106 = F_88 ( V_2 , V_40 ) ;
break;
case V_320 :
V_106 = F_89 ( V_2 , V_40 ) ;
break;
case V_321 :
V_106 = F_108 ( V_2 , V_40 ) ;
break;
case V_273 :
V_106 = F_109 ( V_2 , V_40 ) ;
break;
case V_322 :
V_106 = F_110 ( V_2 , V_40 ) ;
break;
default:
V_106 = - V_65 ;
}
if ( V_2 -> V_22 -> V_323 )
V_2 -> V_22 -> V_323 ( V_2 ) ;
if ( V_279 != V_2 -> V_3 )
F_115 ( V_2 ) ;
return V_106 ;
}
