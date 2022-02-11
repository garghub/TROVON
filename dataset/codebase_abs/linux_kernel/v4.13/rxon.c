void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
memset ( & V_4 -> V_5 , 0 , sizeof( V_4 -> V_5 ) ) ;
if ( ! V_4 -> V_6 ) {
V_4 -> V_5 . V_7 = V_4 -> V_8 ;
} else
switch ( V_4 -> V_6 -> type ) {
case V_9 :
V_4 -> V_5 . V_7 = V_4 -> V_10 ;
break;
case V_11 :
V_4 -> V_5 . V_7 = V_4 -> V_12 ;
V_4 -> V_5 . V_13 = V_14 ;
break;
case V_15 :
V_4 -> V_5 . V_7 = V_4 -> V_16 ;
V_4 -> V_5 . V_17 = V_18 ;
V_4 -> V_5 . V_13 = V_19 |
V_14 ;
break;
case V_20 :
V_4 -> V_5 . V_7 = V_21 ;
break;
default:
F_2 ( V_2 , L_1 ,
V_4 -> V_6 -> type ) ;
break;
}
#if 0
if (!hw_to_local(priv->hw)->short_preamble)
ctx->staging.flags &= ~RXON_FLG_SHORT_PREAMBLE_MSK;
else
ctx->staging.flags |= RXON_FLG_SHORT_PREAMBLE_MSK;
#endif
V_4 -> V_5 . V_22 =
F_3 ( V_2 -> V_23 -> V_24 . V_25 . V_26 -> V_27 ) ;
V_2 -> V_28 = V_2 -> V_23 -> V_24 . V_25 . V_26 -> V_28 ;
F_4 ( V_2 , V_4 , V_2 -> V_28 , V_4 -> V_6 ) ;
V_4 -> V_5 . V_17 &= ~ ( V_29 |
V_30 ) ;
if ( V_4 -> V_6 )
memcpy ( V_4 -> V_5 . V_31 , V_4 -> V_6 -> V_32 , V_33 ) ;
V_4 -> V_5 . V_34 = 0xff ;
V_4 -> V_5 . V_35 = 0xff ;
V_4 -> V_5 . V_36 = 0xff ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_37 * V_38 )
{
T_1 V_39 = V_38 -> V_13 ;
int V_40 ;
V_38 -> V_13 &= ~ V_41 ;
V_40 = F_6 ( V_2 , V_4 -> V_42 ,
0 , sizeof( * V_38 ) , V_38 ) ;
V_38 -> V_13 = V_39 ;
if ( V_40 )
F_7 ( V_2 ,
L_2 , V_40 ) ;
return V_40 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_37 * V_38 )
{
struct V_43 V_44 ;
T_1 V_39 = V_38 -> V_13 ;
T_2 V_45 = V_38 -> V_7 ;
int V_40 ;
static const T_3 V_46 [] = {
V_47
} ;
F_9 ( & V_2 -> V_48 , & V_44 ,
V_46 , F_10 ( V_46 ) ,
NULL , NULL ) ;
V_38 -> V_13 &= ~ V_41 ;
V_38 -> V_7 = V_49 ;
V_40 = F_6 ( V_2 , V_4 -> V_42 ,
0 , sizeof( * V_38 ) , V_38 ) ;
V_38 -> V_13 = V_39 ;
V_38 -> V_7 = V_45 ;
if ( V_40 ) {
F_2 ( V_2 , L_3 , V_40 ) ;
F_11 ( & V_2 -> V_48 , & V_44 ) ;
} else {
V_40 = F_12 ( & V_2 -> V_48 ,
& V_44 , V_50 ) ;
if ( V_40 )
F_2 ( V_2 , L_4 ) ;
}
return V_40 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_37 * V_38 )
{
T_1 V_39 = V_38 -> V_13 ;
int V_40 ;
V_38 -> V_13 &= ~ V_41 ;
V_40 = F_6 ( V_2 , V_4 -> V_42 , 0 ,
sizeof( * V_38 ) , V_38 ) ;
V_38 -> V_13 = V_39 ;
return V_40 ;
}
static void F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_40 ;
if ( ! V_4 -> V_51 )
return;
V_4 -> V_52 . V_53 . V_54 = 0 ;
if ( V_4 -> V_52 . V_55 )
V_4 -> V_52 . V_53 . V_54 |=
V_56 ;
if ( V_4 -> V_57 . V_58 )
V_4 -> V_52 . V_53 . V_54 |= V_59 ;
F_15 ( V_2 , L_5 ,
V_4 -> V_52 . V_55 ,
V_4 -> V_52 . V_53 . V_54 ) ;
V_40 = F_6 ( V_2 , V_4 -> V_60 , 0 ,
sizeof( struct V_61 ) ,
& V_4 -> V_52 . V_53 ) ;
if ( V_40 )
F_7 ( V_2 , L_6 ) ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_62 * V_6 )
{
F_17 ( & V_2 -> V_63 ) ;
F_18 ( V_2 -> V_64 ) ;
V_2 -> V_64 = F_19 ( V_2 -> V_23 , V_6 ) ;
if ( ! V_2 -> V_64 )
return - V_65 ;
return F_20 ( V_2 ) ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_40 = 0 ;
struct V_66 V_67 ;
const struct V_37 * V_68 = & V_4 -> V_5 ;
const struct V_37 * V_69 = & V_4 -> V_70 ;
if ( ( V_68 -> V_17 == V_69 -> V_17 ) &&
( V_68 -> V_13 == V_69 -> V_13 ) &&
( V_68 -> V_71 == V_69 -> V_71 ) &&
( V_68 -> V_34 ==
V_69 -> V_34 ) &&
( V_68 -> V_35 ==
V_69 -> V_35 ) &&
( V_68 -> V_36 ==
V_69 -> V_36 ) &&
( V_68 -> V_72 == V_69 -> V_72 ) &&
( V_68 -> V_73 == V_69 -> V_73 ) &&
( V_68 -> V_74 == V_69 -> V_74 ) ) {
F_15 ( V_2 , L_7 ) ;
return 0 ;
}
V_67 . V_17 = V_4 -> V_5 . V_17 ;
V_67 . V_13 = V_4 -> V_5 . V_13 ;
V_67 . V_74 = V_4 -> V_5 . V_74 ;
V_67 . V_71 = V_4 -> V_5 . V_71 ;
V_67 . V_75 = 0 ;
V_67 . V_76 = 0 ;
V_67 . V_77 = 0 ;
V_67 . V_34 =
V_4 -> V_5 . V_34 ;
V_67 . V_35 =
V_4 -> V_5 . V_35 ;
V_67 . V_78 = V_4 -> V_5 . V_73 ;
V_67 . V_36 =
V_4 -> V_5 . V_36 ;
V_67 . V_72 = V_4 -> V_5 . V_72 ;
V_40 = F_6 ( V_2 , V_4 -> V_79 ,
V_80 , sizeof( V_67 ) , & V_67 ) ;
return V_40 ;
}
static T_3 F_22 ( T_3 V_81 , T_3 V_82 )
{
T_3 V_83 ;
T_3 V_84 ;
if ( ! V_81 )
return V_85 ;
V_84 = ( V_81 + V_82 ) / V_82 ;
V_83 = V_81 / V_84 ;
if ( ! V_83 )
V_83 = V_82 ;
return V_83 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_4 V_86 ;
T_5 V_87 , V_88 ;
struct V_89 * V_24 = NULL ;
T_3 V_90 ;
struct V_62 * V_6 = V_4 -> V_6 ;
V_24 = & V_2 -> V_23 -> V_24 ;
F_17 ( & V_2 -> V_63 ) ;
memset ( & V_4 -> V_91 , 0 , sizeof( struct V_92 ) ) ;
V_4 -> V_91 . V_93 = F_24 ( V_2 -> V_93 ) ;
V_4 -> V_91 . V_94 = F_3 ( V_24 -> V_94 ) ;
V_90 = V_6 ? V_6 -> V_95 . V_90 : 0 ;
V_4 -> V_91 . V_96 = 0 ;
if ( V_4 -> V_97 == V_98 &&
( ! V_4 -> V_6 || V_4 -> V_6 -> type != V_11 ) &&
F_25 ( V_2 , V_99 ) &&
V_2 -> V_100 [ V_99 ] . V_6 &&
V_2 -> V_100 [ V_99 ] . V_6 -> V_95 . V_90 ) {
V_4 -> V_91 . V_101 =
V_2 -> V_100 [ V_99 ] . V_91 . V_101 ;
V_90 = F_26 ( V_4 -> V_91 . V_101 ) ;
} else if ( V_4 -> V_97 == V_99 &&
F_25 ( V_2 , V_98 ) &&
V_2 -> V_100 [ V_98 ] . V_6 &&
V_2 -> V_100 [ V_98 ] . V_6 -> V_95 . V_90 &&
( ! F_27 ( V_4 ) || ! V_4 -> V_6 ||
! V_4 -> V_6 -> V_95 . V_90 ) ) {
V_4 -> V_91 . V_101 =
V_2 -> V_100 [ V_98 ] . V_91 . V_101 ;
V_90 = F_26 ( V_4 -> V_91 . V_101 ) ;
} else {
V_90 = F_22 ( V_90 ,
V_102 * V_103 ) ;
V_4 -> V_91 . V_101 = F_3 ( V_90 ) ;
}
V_4 -> V_90 = V_90 ;
V_86 = V_2 -> V_93 ;
V_87 = V_90 * V_103 ;
V_88 = F_28 ( V_86 , V_87 ) ;
V_4 -> V_91 . V_104 = F_29 ( V_87 - V_88 ) ;
V_4 -> V_91 . V_105 = V_6 ? ( V_6 -> V_95 . V_105 ? : 1 ) : 1 ;
F_30 ( V_2 ,
L_8 ,
F_26 ( V_4 -> V_91 . V_101 ) ,
F_31 ( V_4 -> V_91 . V_104 ) ,
F_26 ( V_4 -> V_91 . V_96 ) ) ;
return F_6 ( V_2 , V_4 -> V_106 ,
0 , sizeof( V_4 -> V_91 ) , & V_4 -> V_91 ) ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_40 ;
struct V_37 * V_70 = ( void * ) & V_4 -> V_70 ;
if ( V_4 -> V_97 == V_99 ) {
V_40 = F_5 ( V_2 , V_4 , & V_4 -> V_5 ) ;
} else {
V_40 = F_8 ( V_2 , V_4 , & V_4 -> V_5 ) ;
if ( V_40 )
return V_40 ;
if ( V_4 -> V_6 ) {
V_40 = F_23 ( V_2 , V_4 ) ;
if ( V_40 ) {
F_2 ( V_2 , L_9 , V_40 ) ;
return V_40 ;
}
V_40 = F_13 ( V_2 , V_4 , & V_4 -> V_5 ) ;
}
}
if ( V_40 )
return V_40 ;
F_33 ( V_2 , V_4 ) ;
F_34 ( V_2 , V_4 ) ;
F_35 ( V_2 , V_4 ) ;
V_40 = F_36 ( V_2 , V_4 ) ;
if ( V_40 ) {
F_2 ( V_2 , L_10 , V_40 ) ;
return V_40 ;
}
memcpy ( V_70 , & V_4 -> V_5 , sizeof( * V_70 ) ) ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 , T_6 V_107 , bool V_108 )
{
int V_40 ;
T_6 V_109 ;
bool V_110 ;
struct V_3 * V_4 = & V_2 -> V_100 [ V_99 ] ;
if ( V_2 -> V_111 & V_112 )
return 0 ;
F_17 ( & V_2 -> V_63 ) ;
if ( V_2 -> V_113 == V_107 && ! V_108 )
return 0 ;
if ( V_107 < V_114 ) {
F_38 ( V_2 ,
L_11 ,
V_107 ,
V_114 ) ;
return - V_115 ;
}
if ( V_107 > F_39 ( V_2 -> V_116 -> V_117 , 2 ) ) {
F_38 ( V_2 ,
L_12 ,
V_107 , V_2 -> V_116 -> V_117 ) ;
return - V_115 ;
}
if ( ! F_40 ( V_2 ) )
return - V_118 ;
V_2 -> V_119 = V_107 ;
V_110 = F_41 ( V_120 , & V_2 -> V_121 ) ||
memcmp ( & V_4 -> V_70 , & V_4 -> V_5 , sizeof( V_4 -> V_5 ) ) ;
if ( V_110 && ! V_108 ) {
F_15 ( V_2 , L_13 ) ;
return 0 ;
}
V_109 = V_2 -> V_113 ;
V_2 -> V_113 = V_107 ;
V_40 = F_42 ( V_2 ) ;
if ( V_40 ) {
V_2 -> V_113 = V_109 ;
V_2 -> V_119 = V_109 ;
}
return V_40 ;
}
static int F_43 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_40 ;
struct V_37 * V_70 = ( void * ) & V_4 -> V_70 ;
if ( V_4 -> V_97 == V_99 ) {
V_40 = F_23 ( V_2 , V_4 ) ;
if ( V_40 ) {
F_2 ( V_2 , L_9 , V_40 ) ;
return V_40 ;
}
}
F_14 ( V_2 , V_4 ) ;
if ( V_4 -> V_6 && ( V_4 -> V_6 -> type == V_9 ) ) {
V_40 = F_16 ( V_2 , V_4 -> V_6 ) ;
if ( V_40 ) {
F_2 ( V_2 ,
L_14 ,
V_40 ) ;
return V_40 ;
}
}
V_2 -> V_122 = 0 ;
V_40 = F_6 ( V_2 , V_4 -> V_42 , 0 ,
sizeof( struct V_37 ) , & V_4 -> V_5 ) ;
if ( V_40 ) {
F_2 ( V_2 , L_15 , V_40 ) ;
return V_40 ;
}
memcpy ( V_70 , & V_4 -> V_5 , sizeof( * V_70 ) ) ;
if ( V_4 -> V_6 && ( V_4 -> V_6 -> type == V_15 ) )
if ( F_16 ( V_2 , V_4 -> V_6 ) )
F_2 ( V_2 , L_16 ) ;
F_44 ( V_2 ) ;
V_40 = F_37 ( V_2 , V_2 -> V_119 , true ) ;
if ( V_40 ) {
F_2 ( V_2 , L_17 , V_40 ) ;
return V_40 ;
}
return 0 ;
}
int F_45 ( struct V_1 * V_2 )
{
struct V_123 V_124 ;
struct V_3 * V_125 , * V_126 ;
int V_127 = 300 , V_128 = 0 ;
int V_40 ;
if ( V_2 -> V_129 == F_46 ( V_99 ) )
return 0 ;
F_47 ( V_130 != 2 ) ;
F_17 ( & V_2 -> V_63 ) ;
V_125 = & V_2 -> V_100 [ V_99 ] ;
V_126 = & V_2 -> V_100 [ V_98 ] ;
if ( ! V_126 -> V_51 )
return 0 ;
memset ( & V_124 , 0 , sizeof( V_124 ) ) ;
V_124 . V_131 = 2 ;
V_124 . V_132 [ 0 ] . type = 0 ;
V_124 . V_132 [ 1 ] . type = 1 ;
if ( V_125 -> V_6 && V_126 -> V_6 ) {
int V_133 = V_126 -> V_90 ;
int V_134 = V_126 -> V_6 -> V_95 . V_105 ? : 1 ;
V_124 . V_17 |= F_3 ( V_135 ) ;
if ( V_126 -> V_6 -> type == V_9 &&
V_133 &&
V_133 != V_125 -> V_90 ) {
F_2 ( V_2 ,
L_18 ,
V_125 -> V_90 , V_126 -> V_90 ) ;
} else
V_133 = F_48 ( int , V_133 ,
V_125 -> V_90 ) ;
if ( ! V_133 )
V_133 = V_85 ;
V_127 = V_133 / 2 ;
V_128 = V_133 - V_127 ;
if ( F_41 ( V_136 , & V_2 -> V_121 ) ||
( ! V_125 -> V_6 -> V_95 . V_137 &&
! V_125 -> V_6 -> V_95 . V_138 ) ) {
V_127 = V_134 * V_133 * 3 - V_139 ;
V_128 = V_139 ;
} else if ( ! V_126 -> V_6 -> V_95 . V_137 &&
! V_126 -> V_6 -> V_95 . V_138 ) {
V_128 = V_134 * V_133 * 3 - V_139 ;
V_127 = V_139 ;
}
} else if ( V_126 -> V_6 ) {
V_127 = 0 ;
V_128 = F_48 ( int , 1 , V_126 -> V_6 -> V_95 . V_105 ) *
V_126 -> V_90 ;
V_128 = F_48 ( int , V_85 , V_128 ) ;
if ( F_41 ( V_136 , & V_2 -> V_121 ) ) {
V_127 = V_128 * 3 - V_139 ;
V_128 = V_139 ;
}
}
V_124 . V_132 [ 0 ] . V_140 = F_3 ( V_127 ) ;
V_124 . V_132 [ 1 ] . V_140 = F_3 ( V_128 ) ;
V_40 = F_6 ( V_2 , V_141 , 0 ,
sizeof( V_124 ) , & V_124 ) ;
if ( V_40 )
F_2 ( V_2 , L_19 , V_40 ) ;
return V_40 ;
}
static void F_49 ( struct V_1 * V_2 ,
struct V_142 * V_143 ,
struct V_3 * V_4 )
{
struct V_37 * V_144 = & V_4 -> V_5 ;
if ( ! V_4 -> V_57 . V_58 ) {
V_144 -> V_17 &= ~ ( V_145 |
V_146 |
V_147 |
V_148 ) ;
return;
}
V_144 -> V_17 |= F_29 ( V_4 -> V_57 . V_149 <<
V_150 ) ;
V_144 -> V_17 &= ~ ( V_145 |
V_146 ) ;
if ( F_50 ( V_2 , V_4 , NULL ) ) {
if ( V_4 -> V_57 . V_149 ==
V_151 ) {
V_144 -> V_17 |= V_30 ;
switch ( V_4 -> V_57 . V_152 ) {
case V_153 :
V_144 -> V_17 &=
~ V_146 ;
break;
case V_154 :
V_144 -> V_17 |=
V_146 ;
break;
}
} else {
switch ( V_4 -> V_57 . V_152 ) {
case V_153 :
V_144 -> V_17 &=
~ ( V_146 ) ;
V_144 -> V_17 |= V_29 ;
break;
case V_154 :
V_144 -> V_17 |= V_146 ;
V_144 -> V_17 |= V_29 ;
break;
case V_155 :
default:
F_2 ( V_2 ,
L_20 ) ;
break;
}
}
} else {
V_144 -> V_17 |= V_156 ;
}
F_51 ( V_2 , V_4 ) ;
F_30 ( V_2 , L_21
L_22 ,
F_31 ( V_144 -> V_17 ) , V_4 -> V_57 . V_149 ,
V_4 -> V_57 . V_152 ) ;
}
void F_52 ( struct V_1 * V_2 , struct V_142 * V_143 )
{
struct V_3 * V_4 ;
F_53 (priv, ctx)
F_49 ( V_2 , V_143 , V_4 ) ;
}
void F_54 ( struct V_1 * V_2 , struct V_157 * V_158 ,
struct V_3 * V_4 )
{
enum V_159 V_28 = V_158 -> V_28 ;
T_3 V_22 = V_158 -> V_27 ;
if ( ( F_26 ( V_4 -> V_5 . V_22 ) == V_22 ) &&
( V_2 -> V_28 == V_28 ) )
return;
V_4 -> V_5 . V_22 = F_3 ( V_22 ) ;
if ( V_28 == V_160 )
V_4 -> V_5 . V_17 &= ~ V_161 ;
else
V_4 -> V_5 . V_17 |= V_161 ;
V_2 -> V_28 = V_28 ;
F_15 ( V_2 , L_23 , V_22 , V_28 ) ;
}
void F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
enum V_159 V_28 ,
struct V_62 * V_6 )
{
if ( V_28 == V_160 ) {
V_4 -> V_5 . V_17 &=
~ ( V_161 | V_162
| V_163 ) ;
V_4 -> V_5 . V_17 |= V_164 ;
} else {
if ( V_6 && V_6 -> V_95 . V_165 )
V_4 -> V_5 . V_17 |= V_164 ;
else
V_4 -> V_5 . V_17 &= ~ V_164 ;
V_4 -> V_5 . V_17 |= V_161 ;
V_4 -> V_5 . V_17 |= V_162 ;
V_4 -> V_5 . V_17 &= ~ V_163 ;
}
}
static void F_55 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_166 )
{
struct V_37 * V_144 = & V_4 -> V_5 ;
if ( V_166 )
V_144 -> V_13 &= ~ V_167 ;
else
V_144 -> V_13 |= V_167 ;
}
static int F_56 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_37 * V_144 = & V_4 -> V_5 ;
T_7 V_168 = 0 ;
if ( V_144 -> V_17 & V_161 ) {
if ( V_144 -> V_17 & V_169 ) {
F_38 ( V_2 , L_24 ) ;
V_168 |= F_46 ( 0 ) ;
}
if ( V_144 -> V_17 & V_170 ) {
F_38 ( V_2 , L_25 ) ;
V_168 |= F_46 ( 1 ) ;
}
} else {
if ( ! ( V_144 -> V_17 & V_164 ) ) {
F_38 ( V_2 , L_26 ) ;
V_168 |= F_46 ( 2 ) ;
}
if ( V_144 -> V_17 & V_163 ) {
F_38 ( V_2 , L_27 ) ;
V_168 |= F_46 ( 3 ) ;
}
}
if ( ( V_144 -> V_31 [ 0 ] | V_144 -> V_171 [ 0 ] ) & 0x1 ) {
F_38 ( V_2 , L_28 ) ;
V_168 |= F_46 ( 4 ) ;
}
if ( ( V_144 -> V_74 & V_172 ) == 0 &&
( V_144 -> V_71 & V_173 ) == 0 ) {
F_38 ( V_2 , L_29 ) ;
V_168 |= F_46 ( 5 ) ;
}
if ( F_26 ( V_144 -> V_174 ) > 2007 ) {
F_38 ( V_2 , L_30 ) ;
V_168 |= F_46 ( 6 ) ;
}
if ( ( V_144 -> V_17 & ( V_163 | V_164 ) )
== ( V_163 | V_164 ) ) {
F_38 ( V_2 , L_31 ) ;
V_168 |= F_46 ( 7 ) ;
}
if ( ( V_144 -> V_17 & ( V_163 | V_162 ) )
== ( V_163 | V_162 ) ) {
F_38 ( V_2 , L_32 ) ;
V_168 |= F_46 ( 8 ) ;
}
if ( ( V_144 -> V_17 & ( V_162 |
V_175 ) ) ==
V_175 ) {
F_38 ( V_2 , L_33 ) ;
V_168 |= F_46 ( 9 ) ;
}
if ( V_144 -> V_22 == 0 ) {
F_38 ( V_2 , L_34 ) ;
V_168 |= F_46 ( 10 ) ;
}
F_57 ( V_168 , L_35 ,
V_168 , F_26 ( V_144 -> V_22 ) ) ;
return V_168 ? - V_115 : 0 ;
}
static int F_58 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
const struct V_37 * V_5 = & V_4 -> V_5 ;
const struct V_37 * V_70 = & V_4 -> V_70 ;
#define F_59 ( T_8 ) \
if ((cond)) { \
IWL_DEBUG_INFO(priv, "need full RXON - " #cond "\n"); \
return 1; \
}
#define F_60 ( T_9 , T_10 ) \
if ((c1) != (c2)) { \
IWL_DEBUG_INFO(priv, "need full RXON - " \
#c1 " != " #c2 " - %d != %d\n", \
(c1), (c2)); \
return 1; \
}
F_59 ( ! F_27 ( V_4 ) ) ;
F_59 ( ! F_61 ( V_5 -> V_171 , V_70 -> V_171 ) ) ;
F_59 ( ! F_61 ( V_5 -> V_31 , V_70 -> V_31 ) ) ;
F_59 ( ! F_61 ( V_5 -> V_176 ,
V_70 -> V_176 ) ) ;
F_60 ( V_5 -> V_7 , V_70 -> V_7 ) ;
F_60 ( V_5 -> V_22 , V_70 -> V_22 ) ;
F_60 ( V_5 -> V_177 , V_70 -> V_177 ) ;
F_60 ( V_5 -> V_34 ,
V_70 -> V_34 ) ;
F_60 ( V_5 -> V_35 ,
V_70 -> V_35 ) ;
F_60 ( V_5 -> V_36 ,
V_70 -> V_36 ) ;
F_60 ( V_5 -> V_174 , V_70 -> V_174 ) ;
F_60 ( V_5 -> V_17 & V_161 ,
V_70 -> V_17 & V_161 ) ;
F_60 ( V_5 -> V_13 & V_41 ,
V_70 -> V_13 & V_41 ) ;
#undef F_59
#undef F_60
return 0 ;
}
void F_62 ( struct V_1 * V_2 ,
enum V_178 V_97 )
{
struct V_3 * V_4 = & V_2 -> V_100 [ V_97 ] ;
struct V_37 * V_144 = & V_4 -> V_5 ;
F_63 ( V_2 , L_36 ) ;
F_64 ( V_2 , V_179 , ( T_2 * ) V_144 , sizeof( * V_144 ) ) ;
F_63 ( V_2 , L_37 ,
F_26 ( V_144 -> V_22 ) ) ;
F_63 ( V_2 , L_38 ,
F_31 ( V_144 -> V_17 ) ) ;
F_63 ( V_2 , L_39 ,
F_31 ( V_144 -> V_13 ) ) ;
F_63 ( V_2 , L_40 , V_144 -> V_7 ) ;
F_63 ( V_2 , L_41 ,
V_144 -> V_74 ) ;
F_63 ( V_2 , L_42 ,
V_144 -> V_71 ) ;
F_63 ( V_2 , L_43 , V_144 -> V_31 ) ;
F_63 ( V_2 , L_44 , V_144 -> V_171 ) ;
F_63 ( V_2 , L_45 ,
F_26 ( V_144 -> V_174 ) ) ;
}
static void F_65 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_180 = 100 ;
int V_181 = 100 ;
T_2 V_182 = 0 ;
T_2 V_183 = 0 ;
if ( V_4 -> V_6 ) {
struct V_184 * V_185 ;
unsigned long V_186 = V_4 -> V_6 -> V_95 . V_187 ;
int V_188 ;
V_185 = V_2 -> V_23 -> V_189 -> V_190 [ V_2 -> V_23 -> V_24 . V_25 . V_26 -> V_28 ] ;
F_66 (i, &basic, BITS_PER_LONG) {
int V_23 = V_185 -> V_191 [ V_188 ] . V_27 ;
if ( V_23 >= V_192 ) {
V_183 |= F_46 ( V_23 - V_192 ) ;
if ( V_180 > V_23 )
V_180 = V_23 ;
} else {
F_47 ( V_193 != 0 ) ;
V_182 |= F_46 ( V_23 ) ;
if ( V_181 > V_23 )
V_181 = V_23 ;
}
}
}
if ( V_194 < V_180 )
V_183 |= V_195 >> V_192 ;
if ( V_196 < V_180 )
V_183 |= V_197 >> V_192 ;
V_183 |= V_172 >> V_192 ;
if ( V_198 < V_181 )
V_182 |= V_199 >> V_193 ;
if ( V_200 < V_181 )
V_182 |= V_201 >> V_193 ;
if ( V_202 < V_181 )
V_182 |= V_203 >> V_193 ;
V_182 |= V_173 >> V_193 ;
F_67 ( V_2 , L_46 ,
V_182 , V_183 ) ;
V_4 -> V_5 . V_71 = V_182 ;
V_4 -> V_5 . V_74 = V_183 ;
}
int F_68 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_37 * V_70 = ( void * ) & V_4 -> V_70 ;
bool V_204 = ! ! ( V_4 -> V_5 . V_13 & V_41 ) ;
int V_40 ;
F_17 ( & V_2 -> V_63 ) ;
if ( ! F_69 ( V_2 ) )
return - V_205 ;
F_47 ( V_130 != 2 ) ;
if ( ! V_4 -> V_51 )
return 0 ;
V_4 -> V_5 . V_17 |= V_206 ;
F_65 ( V_2 , V_4 ) ;
if ( ! V_2 -> V_207 . V_208 )
V_4 -> V_5 . V_17 |= V_209 ;
if ( ( V_4 -> V_6 && V_4 -> V_6 -> V_95 . V_165 ) ||
! ( V_4 -> V_5 . V_17 & V_161 ) )
V_4 -> V_5 . V_17 |= V_164 ;
else
V_4 -> V_5 . V_17 &= ~ V_164 ;
F_62 ( V_2 , V_4 -> V_97 ) ;
V_40 = F_56 ( V_2 , V_4 ) ;
if ( V_40 ) {
F_2 ( V_2 , L_47 ) ;
return - V_115 ;
}
if ( F_41 ( V_210 , & V_2 -> V_121 ) &&
( V_2 -> V_211 != V_4 -> V_5 . V_22 ) ) {
F_70 ( V_2 , L_48 ,
F_26 ( V_2 -> V_211 ) ) ;
F_71 ( V_2 , false ) ;
}
if ( ! F_58 ( V_2 , V_4 ) ) {
V_40 = F_21 ( V_2 , V_4 ) ;
if ( V_40 ) {
F_2 ( V_2 , L_49 , V_40 ) ;
return V_40 ;
}
memcpy ( V_70 , & V_4 -> V_5 , sizeof( * V_70 ) ) ;
F_37 ( V_2 , V_2 -> V_119 , false ) ;
F_72 ( V_2 , true ) ;
return 0 ;
}
F_55 ( V_2 , V_4 , ! V_212 . V_213 ) ;
F_15 ( V_2 ,
L_50
L_51
L_52
L_53 ,
( V_204 ? L_54 : L_55 ) ,
F_26 ( V_4 -> V_5 . V_22 ) ,
V_4 -> V_5 . V_171 ) ;
V_40 = F_32 ( V_2 , V_4 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_45 ( V_2 ) ;
if ( V_40 )
return V_40 ;
if ( V_204 )
return F_43 ( V_2 , V_4 ) ;
return 0 ;
}
void F_73 ( struct V_89 * V_24 ,
struct V_3 * V_4 )
{
if ( F_74 ( V_24 ) ) {
V_4 -> V_57 . V_152 =
V_154 ;
V_4 -> V_57 . V_214 = true ;
} else if ( F_75 ( V_24 ) ) {
V_4 -> V_57 . V_152 =
V_153 ;
V_4 -> V_57 . V_214 = true ;
} else {
V_4 -> V_57 . V_152 =
V_155 ;
V_4 -> V_57 . V_214 = false ;
}
}
int F_76 ( struct V_215 * V_23 , T_7 V_216 )
{
struct V_1 * V_2 = F_77 ( V_23 ) ;
struct V_3 * V_4 ;
struct V_89 * V_24 = & V_23 -> V_24 ;
struct V_157 * V_22 = V_24 -> V_25 . V_26 ;
int V_40 = 0 ;
F_78 ( V_2 , L_56 , V_216 ) ;
F_79 ( & V_2 -> V_63 ) ;
if ( F_80 ( F_41 ( V_120 , & V_2 -> V_121 ) ) ) {
F_78 ( V_2 , L_57 ) ;
goto V_217;
}
if ( ! F_81 ( V_2 ) ) {
F_78 ( V_2 , L_58 ) ;
goto V_217;
}
if ( V_216 & ( V_218 |
V_219 ) ) {
V_2 -> V_220 . V_221 = V_24 -> V_222 ;
F_53 (priv, ctx)
F_51 ( V_2 , V_4 ) ;
}
if ( V_216 & V_219 ) {
F_53 (priv, ctx) {
if ( V_4 -> V_57 . V_58 != F_82 ( V_24 ) )
V_4 -> V_57 . V_58 = F_82 ( V_24 ) ;
if ( V_4 -> V_57 . V_58 ) {
if ( ! V_4 -> V_57 . V_214 ||
! F_27 ( V_4 ) )
F_73 ( V_24 , V_4 ) ;
} else
V_4 -> V_57 . V_214 = false ;
V_4 -> V_57 . V_149 = V_223 ;
if ( F_26 ( V_4 -> V_5 . V_22 ) !=
V_22 -> V_27 )
V_4 -> V_5 . V_17 = 0 ;
F_54 ( V_2 , V_22 , V_4 ) ;
F_52 ( V_2 , & V_2 -> V_220 ) ;
F_4 ( V_2 , V_4 , V_22 -> V_28 ,
V_4 -> V_6 ) ;
}
F_83 ( V_2 ) ;
}
if ( V_216 & ( V_224 |
V_225 ) ) {
V_40 = F_72 ( V_2 , false ) ;
if ( V_40 )
F_78 ( V_2 , L_59 ) ;
}
if ( V_216 & V_226 ) {
F_78 ( V_2 , L_60 ,
V_2 -> V_113 , V_24 -> V_227 ) ;
F_37 ( V_2 , V_24 -> V_227 , false ) ;
}
F_53 (priv, ctx) {
if ( ! memcmp ( & V_4 -> V_5 , & V_4 -> V_70 , sizeof( V_4 -> V_5 ) ) )
continue;
F_68 ( V_2 , V_4 ) ;
}
V_217:
F_84 ( & V_2 -> V_63 ) ;
F_78 ( V_2 , L_61 ) ;
return V_40 ;
}
static void F_85 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_228 * V_95 )
{
struct V_62 * V_6 = V_4 -> V_6 ;
struct V_3 * V_229 ;
struct V_230 * V_231 ;
struct V_142 * V_143 = & V_2 -> V_220 ;
struct V_232 * V_233 ;
bool V_234 ;
F_17 ( & V_2 -> V_63 ) ;
switch ( V_6 -> type ) {
case V_11 :
F_86 () ;
V_231 = F_87 ( V_6 , V_95 -> V_235 ) ;
if ( ! V_231 ) {
V_234 = false ;
F_88 () ;
break;
}
V_233 = & V_231 -> V_233 ;
V_234 = true ;
if ( V_233 -> V_236 . V_237 [ 1 ] == 0 &&
V_233 -> V_236 . V_237 [ 2 ] == 0 ) {
V_234 = false ;
} else if ( ! ( V_233 -> V_236 . V_238 &
V_239 ) ) {
V_234 = false ;
} else if ( V_233 -> V_236 . V_238 &
V_240 ) {
int V_241 ;
V_241 = ( V_233 -> V_236 . V_238 &
V_242 ) ;
V_241 >>=
V_243 ;
V_241 += 1 ;
if ( V_241 <= 1 )
V_234 = false ;
}
F_88 () ;
break;
case V_15 :
V_234 = false ;
break;
default:
V_234 = true ;
break;
}
V_4 -> V_244 = V_234 ;
if ( ! V_234 ) {
F_53 (priv, tmp) {
if ( ! V_229 -> V_6 )
continue;
if ( V_229 -> V_244 ) {
V_234 = true ;
break;
}
}
}
V_143 -> V_245 = ! V_234 ;
}
static void F_89 ( struct V_1 * V_2 )
{
struct V_246 * V_247 = & V_2 -> V_248 ;
int V_40 ;
if ( V_2 -> V_111 & V_249 )
return;
if ( ( V_247 -> V_250 == V_251 ) &&
F_90 ( V_2 ) ) {
struct V_252 V_124 ;
V_247 -> V_253 = 0 ;
V_247 -> V_254 = 0 ;
V_247 -> V_255 = 0 ;
V_247 -> V_256 = 0 ;
V_247 -> V_257 = 0 ;
V_247 -> V_258 = 0 ;
V_247 -> V_259 = 0 ;
memset ( & V_124 , 0 , sizeof( V_124 ) ) ;
F_91 ( & V_124 . V_260 ,
V_2 -> V_261 ) ;
V_40 = F_6 ( V_2 ,
V_262 ,
0 , sizeof( V_124 ) , & V_124 ) ;
if ( V_40 )
F_2 ( V_2 ,
L_62 ) ;
V_247 -> V_250 = V_263 ;
F_92 ( V_2 , L_63 ) ;
}
}
void F_93 ( struct V_215 * V_23 ,
struct V_62 * V_6 ,
struct V_228 * V_95 ,
T_7 V_264 )
{
struct V_1 * V_2 = F_77 ( V_23 ) ;
struct V_3 * V_4 = F_94 ( V_6 ) ;
int V_40 ;
bool V_108 = false ;
F_79 ( & V_2 -> V_63 ) ;
if ( V_264 & V_265 && V_95 -> V_137 ) {
F_95 ( V_2 ) ;
}
if ( F_80 ( ! F_81 ( V_2 ) ) ) {
F_78 ( V_2 , L_58 ) ;
F_84 ( & V_2 -> V_63 ) ;
return;
}
if ( F_80 ( ! V_4 -> V_6 ) ) {
F_78 ( V_2 , L_64 ) ;
F_84 ( & V_2 -> V_63 ) ;
return;
}
if ( V_264 & V_266 )
V_108 = true ;
if ( V_264 & V_267 ) {
V_4 -> V_52 . V_55 = V_95 -> V_268 ;
F_14 ( V_2 , V_4 ) ;
}
V_4 -> V_5 . V_174 = F_3 ( V_6 -> V_95 . V_269 ) ;
if ( V_6 -> V_95 . V_270 )
V_4 -> V_5 . V_17 |= V_18 ;
else
V_4 -> V_5 . V_17 &= ~ V_18 ;
if ( V_264 & V_271 ) {
if ( V_95 -> V_138 ) {
V_2 -> V_93 = V_95 -> V_272 ;
V_4 -> V_5 . V_13 |= V_41 ;
} else {
V_4 -> V_5 . V_13 &= ~ V_41 ;
if ( V_4 -> V_97 == V_99 )
V_2 -> V_273 = false ;
}
F_96 ( V_2 ) ;
}
if ( V_4 -> V_57 . V_58 ) {
V_4 -> V_57 . V_149 = V_95 -> V_274 &
V_275 ;
V_4 -> V_57 . V_276 = ! ! ( V_95 -> V_274 &
V_277 ) ;
F_85 ( V_2 , V_4 , V_95 ) ;
F_52 ( V_2 , & V_2 -> V_220 ) ;
}
F_51 ( V_2 , V_4 ) ;
if ( V_95 -> V_278 && ( V_2 -> V_28 != V_160 ) )
V_4 -> V_5 . V_17 |= V_175 ;
else
V_4 -> V_5 . V_17 &= ~ V_175 ;
if ( V_95 -> V_278 )
V_4 -> V_5 . V_17 |= V_209 ;
else
V_4 -> V_5 . V_17 &= ~ V_209 ;
memcpy ( V_4 -> V_5 . V_171 , V_95 -> V_235 , V_33 ) ;
if ( V_6 -> type == V_9 ||
V_6 -> type == V_15 ) {
if ( V_6 -> V_95 . V_279 ) {
V_4 -> V_5 . V_13 |= V_41 ;
V_2 -> V_280 = V_4 ;
} else {
V_4 -> V_5 . V_13 &= ~ V_41 ;
V_2 -> V_280 = NULL ;
}
}
if ( V_6 -> type == V_11 ) {
if ( ! V_95 -> V_138 )
V_4 -> V_5 . V_13 |= V_19 ;
else
V_4 -> V_5 . V_13 &=
~ V_19 ;
}
if ( V_108 || memcmp ( & V_4 -> V_5 , & V_4 -> V_70 , sizeof( V_4 -> V_5 ) ) )
F_68 ( V_2 , V_4 ) ;
if ( V_264 & V_271 && V_95 -> V_138 ) {
if ( V_2 -> V_248 . V_250 == V_281 )
F_72 ( V_2 , false ) ;
F_89 ( V_2 ) ;
V_2 -> V_122 = 1 ;
}
if ( V_264 & V_282 ) {
V_40 = F_97 ( V_2 , V_6 ,
V_95 -> V_283 ) ;
if ( V_40 )
F_2 ( V_2 , L_65 ,
V_95 -> V_283 ? L_66 : L_67 ,
V_95 -> V_235 ) ;
}
if ( V_264 & V_284 && V_2 -> V_280 == V_4 ) {
if ( F_16 ( V_2 , V_6 ) )
F_2 ( V_2 , L_68 ) ;
}
F_84 ( & V_2 -> V_63 ) ;
}
void F_98 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_99 ( V_2 , & V_2 -> V_285 . V_286 , false ) ;
F_37 ( V_2 , V_2 -> V_119 , false ) ;
F_53 (priv, ctx)
if ( memcmp ( & V_4 -> V_5 , & V_4 -> V_70 , sizeof( V_4 -> V_5 ) ) )
F_68 ( V_2 , V_4 ) ;
F_45 ( V_2 ) ;
}
