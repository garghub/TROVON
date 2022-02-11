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
V_43 , sizeof( * V_38 ) , V_38 ) ;
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
struct V_44 V_45 ;
T_1 V_39 = V_38 -> V_13 ;
T_2 V_46 = V_38 -> V_7 ;
int V_40 ;
static const T_2 V_47 [] = {
V_48
} ;
F_9 ( & V_2 -> V_49 , & V_45 ,
V_47 , F_10 ( V_47 ) ,
NULL , NULL ) ;
V_38 -> V_13 &= ~ V_41 ;
V_38 -> V_7 = V_50 ;
V_40 = F_6 ( V_2 , V_4 -> V_42 ,
V_43 , sizeof( * V_38 ) , V_38 ) ;
V_38 -> V_13 = V_39 ;
V_38 -> V_7 = V_46 ;
if ( V_40 ) {
F_2 ( V_2 , L_3 , V_40 ) ;
F_11 ( & V_2 -> V_49 , & V_45 ) ;
} else {
V_40 = F_12 ( & V_2 -> V_49 ,
& V_45 , V_51 ) ;
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
V_40 = F_6 ( V_2 , V_4 -> V_42 , V_43 ,
sizeof( * V_38 ) , V_38 ) ;
V_38 -> V_13 = V_39 ;
return V_40 ;
}
static void F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_40 ;
if ( ! V_4 -> V_52 )
return;
V_4 -> V_53 . V_54 . V_55 = 0 ;
if ( V_4 -> V_53 . V_56 )
V_4 -> V_53 . V_54 . V_55 |=
V_57 ;
if ( V_4 -> V_58 . V_59 )
V_4 -> V_53 . V_54 . V_55 |= V_60 ;
F_15 ( V_2 , L_5 ,
V_4 -> V_53 . V_56 ,
V_4 -> V_53 . V_54 . V_55 ) ;
V_40 = F_6 ( V_2 , V_4 -> V_61 , V_43 ,
sizeof( struct V_62 ) ,
& V_4 -> V_53 . V_54 ) ;
if ( V_40 )
F_7 ( V_2 , L_6 ) ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_63 * V_6 )
{
F_17 ( & V_2 -> V_64 ) ;
F_18 ( V_2 -> V_65 ) ;
V_2 -> V_65 = F_19 ( V_2 -> V_23 , V_6 ) ;
if ( ! V_2 -> V_65 )
return - V_66 ;
return F_20 ( V_2 ) ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_40 = 0 ;
struct V_67 V_68 ;
const struct V_37 * V_69 = & V_4 -> V_5 ;
const struct V_37 * V_70 = & V_4 -> V_71 ;
if ( ( V_69 -> V_17 == V_70 -> V_17 ) &&
( V_69 -> V_13 == V_70 -> V_13 ) &&
( V_69 -> V_72 == V_70 -> V_72 ) &&
( V_69 -> V_34 ==
V_70 -> V_34 ) &&
( V_69 -> V_35 ==
V_70 -> V_35 ) &&
( V_69 -> V_36 ==
V_70 -> V_36 ) &&
( V_69 -> V_73 == V_70 -> V_73 ) &&
( V_69 -> V_74 == V_70 -> V_74 ) &&
( V_69 -> V_75 == V_70 -> V_75 ) ) {
F_15 ( V_2 , L_7 ) ;
return 0 ;
}
V_68 . V_17 = V_4 -> V_5 . V_17 ;
V_68 . V_13 = V_4 -> V_5 . V_13 ;
V_68 . V_75 = V_4 -> V_5 . V_75 ;
V_68 . V_72 = V_4 -> V_5 . V_72 ;
V_68 . V_76 = 0 ;
V_68 . V_77 = 0 ;
V_68 . V_78 = 0 ;
V_68 . V_34 =
V_4 -> V_5 . V_34 ;
V_68 . V_35 =
V_4 -> V_5 . V_35 ;
V_68 . V_79 = V_4 -> V_5 . V_74 ;
V_68 . V_36 =
V_4 -> V_5 . V_36 ;
V_68 . V_73 = V_4 -> V_5 . V_73 ;
V_40 = F_6 ( V_2 , V_4 -> V_80 ,
V_81 , sizeof( V_68 ) , & V_68 ) ;
return V_40 ;
}
static T_3 F_22 ( T_3 V_82 , T_3 V_83 )
{
T_3 V_84 ;
T_3 V_85 ;
if ( ! V_82 )
return V_86 ;
V_85 = ( V_82 + V_83 ) / V_83 ;
V_84 = V_82 / V_85 ;
if ( ! V_84 )
V_84 = V_83 ;
return V_84 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_4 V_87 ;
T_5 V_88 , V_89 ;
struct V_90 * V_24 = NULL ;
T_3 V_91 ;
struct V_63 * V_6 = V_4 -> V_6 ;
V_24 = & V_2 -> V_23 -> V_24 ;
F_17 ( & V_2 -> V_64 ) ;
memset ( & V_4 -> V_92 , 0 , sizeof( struct V_93 ) ) ;
V_4 -> V_92 . V_94 = F_24 ( V_2 -> V_94 ) ;
V_4 -> V_92 . V_95 = F_3 ( V_24 -> V_95 ) ;
V_91 = V_6 ? V_6 -> V_96 . V_91 : 0 ;
V_4 -> V_92 . V_97 = 0 ;
if ( V_4 -> V_98 == V_99 &&
( ! V_4 -> V_6 || V_4 -> V_6 -> type != V_11 ) &&
F_25 ( V_2 , V_100 ) &&
V_2 -> V_101 [ V_100 ] . V_6 &&
V_2 -> V_101 [ V_100 ] . V_6 -> V_96 . V_91 ) {
V_4 -> V_92 . V_102 =
V_2 -> V_101 [ V_100 ] . V_92 . V_102 ;
V_91 = F_26 ( V_4 -> V_92 . V_102 ) ;
} else if ( V_4 -> V_98 == V_100 &&
F_25 ( V_2 , V_99 ) &&
V_2 -> V_101 [ V_99 ] . V_6 &&
V_2 -> V_101 [ V_99 ] . V_6 -> V_96 . V_91 &&
( ! F_27 ( V_4 ) || ! V_4 -> V_6 ||
! V_4 -> V_6 -> V_96 . V_91 ) ) {
V_4 -> V_92 . V_102 =
V_2 -> V_101 [ V_99 ] . V_92 . V_102 ;
V_91 = F_26 ( V_4 -> V_92 . V_102 ) ;
} else {
V_91 = F_22 ( V_91 ,
V_103 * V_104 ) ;
V_4 -> V_92 . V_102 = F_3 ( V_91 ) ;
}
V_4 -> V_91 = V_91 ;
V_87 = V_2 -> V_94 ;
V_88 = V_91 * V_104 ;
V_89 = F_28 ( V_87 , V_88 ) ;
V_4 -> V_92 . V_105 = F_29 ( V_88 - V_89 ) ;
V_4 -> V_92 . V_106 = V_6 ? ( V_6 -> V_96 . V_106 ? : 1 ) : 1 ;
F_30 ( V_2 ,
L_8 ,
F_26 ( V_4 -> V_92 . V_102 ) ,
F_31 ( V_4 -> V_92 . V_105 ) ,
F_26 ( V_4 -> V_92 . V_97 ) ) ;
return F_6 ( V_2 , V_4 -> V_107 ,
V_43 , sizeof( V_4 -> V_92 ) , & V_4 -> V_92 ) ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_40 ;
struct V_37 * V_71 = ( void * ) & V_4 -> V_71 ;
if ( V_4 -> V_98 == V_100 ) {
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
memcpy ( V_71 , & V_4 -> V_5 , sizeof( * V_71 ) ) ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 , T_6 V_108 , bool V_109 )
{
int V_40 ;
T_6 V_110 ;
bool V_111 ;
struct V_3 * V_4 = & V_2 -> V_101 [ V_100 ] ;
if ( V_2 -> V_112 & V_113 )
return 0 ;
F_17 ( & V_2 -> V_64 ) ;
if ( V_2 -> V_114 == V_108 && ! V_109 )
return 0 ;
if ( V_108 < V_115 ) {
F_38 ( V_2 ,
L_11 ,
V_108 ,
V_115 ) ;
return - V_116 ;
}
if ( V_108 > F_39 ( V_2 -> V_117 -> V_118 , 2 ) ) {
F_38 ( V_2 ,
L_12 ,
V_108 , V_2 -> V_117 -> V_118 ) ;
return - V_116 ;
}
if ( ! F_40 ( V_2 ) )
return - V_119 ;
V_2 -> V_120 = V_108 ;
V_111 = F_41 ( V_121 , & V_2 -> V_122 ) ||
memcmp ( & V_4 -> V_71 , & V_4 -> V_5 , sizeof( V_4 -> V_5 ) ) ;
if ( V_111 && ! V_109 ) {
F_15 ( V_2 , L_13 ) ;
return 0 ;
}
V_110 = V_2 -> V_114 ;
V_2 -> V_114 = V_108 ;
V_40 = F_42 ( V_2 ) ;
if ( V_40 ) {
V_2 -> V_114 = V_110 ;
V_2 -> V_120 = V_110 ;
}
return V_40 ;
}
static int F_43 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_40 ;
struct V_37 * V_71 = ( void * ) & V_4 -> V_71 ;
if ( V_4 -> V_98 == V_100 ) {
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
V_2 -> V_123 = 0 ;
V_40 = F_6 ( V_2 , V_4 -> V_42 , V_43 ,
sizeof( struct V_37 ) , & V_4 -> V_5 ) ;
if ( V_40 ) {
F_2 ( V_2 , L_15 , V_40 ) ;
return V_40 ;
}
memcpy ( V_71 , & V_4 -> V_5 , sizeof( * V_71 ) ) ;
if ( V_4 -> V_6 && ( V_4 -> V_6 -> type == V_15 ) )
if ( F_16 ( V_2 , V_4 -> V_6 ) )
F_2 ( V_2 , L_16 ) ;
F_44 ( V_2 ) ;
V_40 = F_37 ( V_2 , V_2 -> V_120 , true ) ;
if ( V_40 ) {
F_2 ( V_2 , L_17 , V_40 ) ;
return V_40 ;
}
if ( V_4 -> V_6 && V_4 -> V_6 -> type == V_11 &&
V_2 -> V_124 -> V_125 && V_2 -> V_124 -> V_125 -> V_126 )
F_45 ( V_4 -> V_6 ,
V_2 -> V_124 -> V_125 -> V_126 ) ;
return 0 ;
}
int F_46 ( struct V_1 * V_2 )
{
struct V_127 V_128 ;
struct V_3 * V_129 , * V_130 ;
int V_131 = 300 , V_132 = 0 ;
int V_40 ;
if ( V_2 -> V_133 == F_47 ( V_100 ) )
return 0 ;
F_48 ( V_134 != 2 ) ;
F_17 ( & V_2 -> V_64 ) ;
V_129 = & V_2 -> V_101 [ V_100 ] ;
V_130 = & V_2 -> V_101 [ V_99 ] ;
if ( ! V_130 -> V_52 )
return 0 ;
memset ( & V_128 , 0 , sizeof( V_128 ) ) ;
V_128 . V_135 = 2 ;
V_128 . V_136 [ 0 ] . type = 0 ;
V_128 . V_136 [ 1 ] . type = 1 ;
if ( V_129 -> V_6 && V_130 -> V_6 ) {
int V_137 = V_130 -> V_91 ;
int V_138 = V_130 -> V_6 -> V_96 . V_106 ? : 1 ;
V_128 . V_17 |= F_3 ( V_139 ) ;
if ( V_130 -> V_6 -> type == V_9 &&
V_137 &&
V_137 != V_129 -> V_91 ) {
F_2 ( V_2 ,
L_18 ,
V_129 -> V_91 , V_130 -> V_91 ) ;
} else
V_137 = F_49 ( int , V_137 ,
V_129 -> V_91 ) ;
if ( ! V_137 )
V_137 = V_86 ;
V_131 = V_137 / 2 ;
V_132 = V_137 - V_131 ;
if ( F_41 ( V_140 , & V_2 -> V_122 ) ||
( ! V_129 -> V_6 -> V_96 . V_141 &&
! V_129 -> V_6 -> V_96 . V_142 ) ) {
V_131 = V_138 * V_137 * 3 - V_143 ;
V_132 = V_143 ;
} else if ( ! V_130 -> V_6 -> V_96 . V_141 &&
! V_130 -> V_6 -> V_96 . V_142 ) {
V_132 = V_138 * V_137 * 3 - V_143 ;
V_131 = V_143 ;
}
} else if ( V_130 -> V_6 ) {
V_131 = 0 ;
V_132 = F_49 ( int , 1 , V_130 -> V_6 -> V_96 . V_106 ) *
V_130 -> V_91 ;
V_132 = F_49 ( int , V_86 , V_132 ) ;
if ( F_41 ( V_140 , & V_2 -> V_122 ) ) {
V_131 = V_132 * 3 - V_143 ;
V_132 = V_143 ;
}
}
V_128 . V_136 [ 0 ] . V_144 = F_3 ( V_131 ) ;
V_128 . V_136 [ 1 ] . V_144 = F_3 ( V_132 ) ;
V_40 = F_6 ( V_2 , V_145 , V_43 ,
sizeof( V_128 ) , & V_128 ) ;
if ( V_40 )
F_2 ( V_2 , L_19 , V_40 ) ;
return V_40 ;
}
static void F_50 ( struct V_1 * V_2 ,
struct V_146 * V_147 ,
struct V_3 * V_4 )
{
struct V_37 * V_148 = & V_4 -> V_5 ;
if ( ! V_4 -> V_58 . V_59 ) {
V_148 -> V_17 &= ~ ( V_149 |
V_150 |
V_151 |
V_152 ) ;
return;
}
V_148 -> V_17 |= F_29 ( V_4 -> V_58 . V_153 <<
V_154 ) ;
V_148 -> V_17 &= ~ ( V_149 |
V_150 ) ;
if ( F_51 ( V_2 , V_4 , NULL ) ) {
if ( V_4 -> V_58 . V_153 ==
V_155 ) {
V_148 -> V_17 |= V_30 ;
switch ( V_4 -> V_58 . V_156 ) {
case V_157 :
V_148 -> V_17 &=
~ V_150 ;
break;
case V_158 :
V_148 -> V_17 |=
V_150 ;
break;
}
} else {
switch ( V_4 -> V_58 . V_156 ) {
case V_157 :
V_148 -> V_17 &=
~ ( V_150 ) ;
V_148 -> V_17 |= V_29 ;
break;
case V_158 :
V_148 -> V_17 |= V_150 ;
V_148 -> V_17 |= V_29 ;
break;
case V_159 :
default:
F_2 ( V_2 ,
L_20 ) ;
break;
}
}
} else {
V_148 -> V_17 |= V_160 ;
}
F_52 ( V_2 , V_4 ) ;
F_30 ( V_2 , L_21
L_22 ,
F_31 ( V_148 -> V_17 ) , V_4 -> V_58 . V_153 ,
V_4 -> V_58 . V_156 ) ;
}
void F_53 ( struct V_1 * V_2 , struct V_146 * V_147 )
{
struct V_3 * V_4 ;
F_54 (priv, ctx)
F_50 ( V_2 , V_147 , V_4 ) ;
}
void F_55 ( struct V_1 * V_2 , struct V_161 * V_162 ,
struct V_3 * V_4 )
{
enum V_163 V_28 = V_162 -> V_28 ;
T_3 V_22 = V_162 -> V_27 ;
if ( ( F_26 ( V_4 -> V_5 . V_22 ) == V_22 ) &&
( V_2 -> V_28 == V_28 ) )
return;
V_4 -> V_5 . V_22 = F_3 ( V_22 ) ;
if ( V_28 == V_164 )
V_4 -> V_5 . V_17 &= ~ V_165 ;
else
V_4 -> V_5 . V_17 |= V_165 ;
V_2 -> V_28 = V_28 ;
F_15 ( V_2 , L_23 , V_22 , V_28 ) ;
}
void F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
enum V_163 V_28 ,
struct V_63 * V_6 )
{
if ( V_28 == V_164 ) {
V_4 -> V_5 . V_17 &=
~ ( V_165 | V_166
| V_167 ) ;
V_4 -> V_5 . V_17 |= V_168 ;
} else {
if ( V_6 && V_6 -> V_96 . V_169 )
V_4 -> V_5 . V_17 |= V_168 ;
else
V_4 -> V_5 . V_17 &= ~ V_168 ;
V_4 -> V_5 . V_17 |= V_165 ;
V_4 -> V_5 . V_17 |= V_166 ;
V_4 -> V_5 . V_17 &= ~ V_167 ;
}
}
static void F_56 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_170 )
{
struct V_37 * V_148 = & V_4 -> V_5 ;
if ( V_170 )
V_148 -> V_13 &= ~ V_171 ;
else
V_148 -> V_13 |= V_171 ;
}
static int F_57 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_37 * V_148 = & V_4 -> V_5 ;
T_7 V_172 = 0 ;
if ( V_148 -> V_17 & V_165 ) {
if ( V_148 -> V_17 & V_173 ) {
F_38 ( V_2 , L_24 ) ;
V_172 |= F_47 ( 0 ) ;
}
if ( V_148 -> V_17 & V_174 ) {
F_38 ( V_2 , L_25 ) ;
V_172 |= F_47 ( 1 ) ;
}
} else {
if ( ! ( V_148 -> V_17 & V_168 ) ) {
F_38 ( V_2 , L_26 ) ;
V_172 |= F_47 ( 2 ) ;
}
if ( V_148 -> V_17 & V_167 ) {
F_38 ( V_2 , L_27 ) ;
V_172 |= F_47 ( 3 ) ;
}
}
if ( ( V_148 -> V_31 [ 0 ] | V_148 -> V_175 [ 0 ] ) & 0x1 ) {
F_38 ( V_2 , L_28 ) ;
V_172 |= F_47 ( 4 ) ;
}
if ( ( V_148 -> V_75 & V_176 ) == 0 &&
( V_148 -> V_72 & V_177 ) == 0 ) {
F_38 ( V_2 , L_29 ) ;
V_172 |= F_47 ( 5 ) ;
}
if ( F_26 ( V_148 -> V_178 ) > 2007 ) {
F_38 ( V_2 , L_30 ) ;
V_172 |= F_47 ( 6 ) ;
}
if ( ( V_148 -> V_17 & ( V_167 | V_168 ) )
== ( V_167 | V_168 ) ) {
F_38 ( V_2 , L_31 ) ;
V_172 |= F_47 ( 7 ) ;
}
if ( ( V_148 -> V_17 & ( V_167 | V_166 ) )
== ( V_167 | V_166 ) ) {
F_38 ( V_2 , L_32 ) ;
V_172 |= F_47 ( 8 ) ;
}
if ( ( V_148 -> V_17 & ( V_166 |
V_179 ) ) ==
V_179 ) {
F_38 ( V_2 , L_33 ) ;
V_172 |= F_47 ( 9 ) ;
}
if ( V_148 -> V_22 == 0 ) {
F_38 ( V_2 , L_34 ) ;
V_172 |= F_47 ( 10 ) ;
}
F_58 ( V_172 , L_35 ,
V_172 , F_26 ( V_148 -> V_22 ) ) ;
return V_172 ? - V_116 : 0 ;
}
static int F_59 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
const struct V_37 * V_5 = & V_4 -> V_5 ;
const struct V_37 * V_71 = & V_4 -> V_71 ;
#define F_60 ( T_8 ) \
if ((cond)) { \
IWL_DEBUG_INFO(priv, "need full RXON - " #cond "\n"); \
return 1; \
}
#define F_61 ( T_9 , T_10 ) \
if ((c1) != (c2)) { \
IWL_DEBUG_INFO(priv, "need full RXON - " \
#c1 " != " #c2 " - %d != %d\n", \
(c1), (c2)); \
return 1; \
}
F_60 ( ! F_27 ( V_4 ) ) ;
F_60 ( ! F_62 ( V_5 -> V_175 , V_71 -> V_175 ) ) ;
F_60 ( ! F_62 ( V_5 -> V_31 , V_71 -> V_31 ) ) ;
F_60 ( ! F_62 ( V_5 -> V_180 ,
V_71 -> V_180 ) ) ;
F_61 ( V_5 -> V_7 , V_71 -> V_7 ) ;
F_61 ( V_5 -> V_22 , V_71 -> V_22 ) ;
F_61 ( V_5 -> V_181 , V_71 -> V_181 ) ;
F_61 ( V_5 -> V_34 ,
V_71 -> V_34 ) ;
F_61 ( V_5 -> V_35 ,
V_71 -> V_35 ) ;
F_61 ( V_5 -> V_36 ,
V_71 -> V_36 ) ;
F_61 ( V_5 -> V_178 , V_71 -> V_178 ) ;
F_61 ( V_5 -> V_17 & V_165 ,
V_71 -> V_17 & V_165 ) ;
F_61 ( V_5 -> V_13 & V_41 ,
V_71 -> V_13 & V_41 ) ;
#undef F_60
#undef F_61
return 0 ;
}
void F_63 ( struct V_1 * V_2 ,
enum V_182 V_98 )
{
struct V_3 * V_4 = & V_2 -> V_101 [ V_98 ] ;
struct V_37 * V_148 = & V_4 -> V_5 ;
F_64 ( V_2 , L_36 ) ;
F_65 ( V_2 , V_183 , ( T_2 * ) V_148 , sizeof( * V_148 ) ) ;
F_64 ( V_2 , L_37 ,
F_26 ( V_148 -> V_22 ) ) ;
F_64 ( V_2 , L_38 ,
F_31 ( V_148 -> V_17 ) ) ;
F_64 ( V_2 , L_39 ,
F_31 ( V_148 -> V_13 ) ) ;
F_64 ( V_2 , L_40 , V_148 -> V_7 ) ;
F_64 ( V_2 , L_41 ,
V_148 -> V_75 ) ;
F_64 ( V_2 , L_42 ,
V_148 -> V_72 ) ;
F_64 ( V_2 , L_43 , V_148 -> V_31 ) ;
F_64 ( V_2 , L_44 , V_148 -> V_175 ) ;
F_64 ( V_2 , L_45 ,
F_26 ( V_148 -> V_178 ) ) ;
}
static void F_66 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_184 = 100 ;
int V_185 = 100 ;
T_2 V_186 = 0 ;
T_2 V_187 = 0 ;
if ( V_4 -> V_6 ) {
struct V_188 * V_189 ;
unsigned long V_190 = V_4 -> V_6 -> V_96 . V_191 ;
int V_192 ;
V_189 = V_2 -> V_23 -> V_193 -> V_194 [ V_2 -> V_23 -> V_24 . V_25 . V_26 -> V_28 ] ;
F_67 (i, &basic, BITS_PER_LONG) {
int V_23 = V_189 -> V_195 [ V_192 ] . V_27 ;
if ( V_23 >= V_196 ) {
V_187 |= F_47 ( V_23 - V_196 ) ;
if ( V_184 > V_23 )
V_184 = V_23 ;
} else {
F_48 ( V_197 != 0 ) ;
V_186 |= F_47 ( V_23 ) ;
if ( V_185 > V_23 )
V_185 = V_23 ;
}
}
}
if ( V_198 < V_184 )
V_187 |= V_199 >> V_196 ;
if ( V_200 < V_184 )
V_187 |= V_201 >> V_196 ;
V_187 |= V_176 >> V_196 ;
if ( V_202 < V_185 )
V_186 |= V_203 >> V_197 ;
if ( V_204 < V_185 )
V_186 |= V_205 >> V_197 ;
if ( V_206 < V_185 )
V_186 |= V_207 >> V_197 ;
V_186 |= V_177 >> V_197 ;
F_68 ( V_2 , L_46 ,
V_186 , V_187 ) ;
V_4 -> V_5 . V_72 = V_186 ;
V_4 -> V_5 . V_75 = V_187 ;
}
int F_69 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_37 * V_71 = ( void * ) & V_4 -> V_71 ;
bool V_208 = ! ! ( V_4 -> V_5 . V_13 & V_41 ) ;
int V_40 ;
F_17 ( & V_2 -> V_64 ) ;
if ( ! F_70 ( V_2 ) )
return - V_209 ;
F_48 ( V_134 != 2 ) ;
if ( ! V_4 -> V_52 )
return 0 ;
V_4 -> V_5 . V_17 |= V_210 ;
F_66 ( V_2 , V_4 ) ;
if ( ! V_2 -> V_211 . V_212 )
V_4 -> V_5 . V_17 |= V_213 ;
if ( ( V_4 -> V_6 && V_4 -> V_6 -> V_96 . V_169 ) ||
! ( V_4 -> V_5 . V_17 & V_165 ) )
V_4 -> V_5 . V_17 |= V_168 ;
else
V_4 -> V_5 . V_17 &= ~ V_168 ;
F_63 ( V_2 , V_4 -> V_98 ) ;
V_40 = F_57 ( V_2 , V_4 ) ;
if ( V_40 ) {
F_2 ( V_2 , L_47 ) ;
return - V_116 ;
}
if ( F_41 ( V_214 , & V_2 -> V_122 ) &&
( V_2 -> V_215 != V_4 -> V_5 . V_22 ) ) {
F_71 ( V_2 , L_48 ,
F_26 ( V_2 -> V_215 ) ) ;
F_72 ( V_2 , false ) ;
}
if ( ! F_59 ( V_2 , V_4 ) ) {
V_40 = F_21 ( V_2 , V_4 ) ;
if ( V_40 ) {
F_2 ( V_2 , L_49 , V_40 ) ;
return V_40 ;
}
memcpy ( V_71 , & V_4 -> V_5 , sizeof( * V_71 ) ) ;
F_37 ( V_2 , V_2 -> V_120 , false ) ;
F_73 ( V_2 , true ) ;
return 0 ;
}
F_56 ( V_2 , V_4 , ! V_216 . V_217 ) ;
F_15 ( V_2 ,
L_50
L_51
L_52
L_53 ,
( V_208 ? L_54 : L_55 ) ,
F_26 ( V_4 -> V_5 . V_22 ) ,
V_4 -> V_5 . V_175 ) ;
V_40 = F_32 ( V_2 , V_4 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_46 ( V_2 ) ;
if ( V_40 )
return V_40 ;
if ( V_208 )
return F_43 ( V_2 , V_4 ) ;
return 0 ;
}
void F_74 ( struct V_90 * V_24 ,
struct V_3 * V_4 )
{
if ( F_75 ( V_24 ) ) {
V_4 -> V_58 . V_156 =
V_158 ;
V_4 -> V_58 . V_218 = true ;
} else if ( F_76 ( V_24 ) ) {
V_4 -> V_58 . V_156 =
V_157 ;
V_4 -> V_58 . V_218 = true ;
} else {
V_4 -> V_58 . V_156 =
V_159 ;
V_4 -> V_58 . V_218 = false ;
}
}
int F_77 ( struct V_219 * V_23 , T_7 V_220 )
{
struct V_1 * V_2 = F_78 ( V_23 ) ;
struct V_3 * V_4 ;
struct V_90 * V_24 = & V_23 -> V_24 ;
struct V_161 * V_22 = V_24 -> V_25 . V_26 ;
int V_40 = 0 ;
F_79 ( V_2 , L_56 , V_220 ) ;
F_80 ( & V_2 -> V_64 ) ;
if ( F_81 ( F_41 ( V_121 , & V_2 -> V_122 ) ) ) {
F_79 ( V_2 , L_57 ) ;
goto V_221;
}
if ( ! F_82 ( V_2 ) ) {
F_79 ( V_2 , L_58 ) ;
goto V_221;
}
if ( V_220 & ( V_222 |
V_223 ) ) {
V_2 -> V_224 . V_225 = V_24 -> V_126 ;
F_54 (priv, ctx)
F_52 ( V_2 , V_4 ) ;
}
if ( V_220 & V_223 ) {
F_54 (priv, ctx) {
if ( V_4 -> V_58 . V_59 != F_83 ( V_24 ) )
V_4 -> V_58 . V_59 = F_83 ( V_24 ) ;
if ( V_4 -> V_58 . V_59 ) {
if ( ! V_4 -> V_58 . V_218 ||
! F_27 ( V_4 ) )
F_74 ( V_24 , V_4 ) ;
} else
V_4 -> V_58 . V_218 = false ;
V_4 -> V_58 . V_153 = V_226 ;
if ( F_26 ( V_4 -> V_5 . V_22 ) !=
V_22 -> V_27 )
V_4 -> V_5 . V_17 = 0 ;
F_55 ( V_2 , V_22 , V_4 ) ;
F_53 ( V_2 , & V_2 -> V_224 ) ;
F_4 ( V_2 , V_4 , V_22 -> V_28 ,
V_4 -> V_6 ) ;
}
F_84 ( V_2 ) ;
}
if ( V_220 & ( V_227 |
V_228 ) ) {
V_40 = F_73 ( V_2 , false ) ;
if ( V_40 )
F_79 ( V_2 , L_59 ) ;
}
if ( V_220 & V_229 ) {
F_79 ( V_2 , L_60 ,
V_2 -> V_114 , V_24 -> V_230 ) ;
F_37 ( V_2 , V_24 -> V_230 , false ) ;
}
F_54 (priv, ctx) {
if ( ! memcmp ( & V_4 -> V_5 , & V_4 -> V_71 , sizeof( V_4 -> V_5 ) ) )
continue;
F_69 ( V_2 , V_4 ) ;
}
V_221:
F_85 ( & V_2 -> V_64 ) ;
F_79 ( V_2 , L_61 ) ;
return V_40 ;
}
static void F_86 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_231 * V_96 )
{
struct V_63 * V_6 = V_4 -> V_6 ;
struct V_3 * V_232 ;
struct V_233 * V_234 ;
struct V_146 * V_147 = & V_2 -> V_224 ;
struct V_235 * V_236 ;
bool V_237 ;
F_17 ( & V_2 -> V_64 ) ;
switch ( V_6 -> type ) {
case V_11 :
F_87 () ;
V_234 = F_88 ( V_6 , V_96 -> V_238 ) ;
if ( ! V_234 ) {
V_237 = false ;
F_89 () ;
break;
}
V_236 = & V_234 -> V_236 ;
V_237 = true ;
if ( V_236 -> V_239 . V_240 [ 1 ] == 0 &&
V_236 -> V_239 . V_240 [ 2 ] == 0 ) {
V_237 = false ;
} else if ( ! ( V_236 -> V_239 . V_241 &
V_242 ) ) {
V_237 = false ;
} else if ( V_236 -> V_239 . V_241 &
V_243 ) {
int V_244 ;
V_244 = ( V_236 -> V_239 . V_241 &
V_245 ) ;
V_244 >>=
V_246 ;
V_244 += 1 ;
if ( V_244 <= 1 )
V_237 = false ;
}
F_89 () ;
break;
case V_15 :
V_237 = false ;
break;
default:
V_237 = true ;
break;
}
V_4 -> V_247 = V_237 ;
if ( ! V_237 ) {
F_54 (priv, tmp) {
if ( ! V_232 -> V_6 )
continue;
if ( V_232 -> V_247 ) {
V_237 = true ;
break;
}
}
}
V_147 -> V_248 = ! V_237 ;
}
static void F_90 ( struct V_1 * V_2 )
{
struct V_249 * V_250 = & V_2 -> V_251 ;
int V_40 ;
if ( V_2 -> V_112 & V_252 )
return;
if ( ( V_250 -> V_253 == V_254 ) &&
F_91 ( V_2 ) ) {
struct V_255 V_128 ;
V_250 -> V_256 = 0 ;
V_250 -> V_257 = 0 ;
V_250 -> V_258 = 0 ;
V_250 -> V_259 = 0 ;
V_250 -> V_260 = 0 ;
V_250 -> V_261 = 0 ;
V_250 -> V_262 = 0 ;
memset ( & V_128 , 0 , sizeof( V_128 ) ) ;
F_92 ( & V_128 . V_263 ,
V_2 -> V_264 ) ;
V_40 = F_6 ( V_2 ,
V_265 ,
V_43 , sizeof( V_128 ) , & V_128 ) ;
if ( V_40 )
F_2 ( V_2 ,
L_62 ) ;
V_250 -> V_253 = V_266 ;
F_93 ( V_2 , L_63 ) ;
}
}
void F_94 ( struct V_219 * V_23 ,
struct V_63 * V_6 ,
struct V_231 * V_96 ,
T_7 V_267 )
{
struct V_1 * V_2 = F_78 ( V_23 ) ;
struct V_3 * V_4 = F_95 ( V_6 ) ;
int V_40 ;
bool V_109 = false ;
F_80 ( & V_2 -> V_64 ) ;
if ( V_267 & V_268 && V_96 -> V_141 ) {
F_96 ( V_2 ) ;
}
if ( F_81 ( ! F_82 ( V_2 ) ) ) {
F_79 ( V_2 , L_58 ) ;
F_85 ( & V_2 -> V_64 ) ;
return;
}
if ( F_81 ( ! V_4 -> V_6 ) ) {
F_79 ( V_2 , L_64 ) ;
F_85 ( & V_2 -> V_64 ) ;
return;
}
if ( V_267 & V_269 )
V_109 = true ;
if ( V_267 & V_270 ) {
V_4 -> V_53 . V_56 = V_96 -> V_271 ;
F_14 ( V_2 , V_4 ) ;
}
V_4 -> V_5 . V_178 = F_3 ( V_6 -> V_96 . V_272 ) ;
if ( V_6 -> V_96 . V_273 )
V_4 -> V_5 . V_17 |= V_18 ;
else
V_4 -> V_5 . V_17 &= ~ V_18 ;
if ( V_267 & V_274 ) {
if ( V_96 -> V_142 ) {
V_2 -> V_94 = V_96 -> V_275 ;
V_4 -> V_5 . V_13 |= V_41 ;
} else {
V_4 -> V_5 . V_13 &= ~ V_41 ;
if ( V_4 -> V_98 == V_100 )
V_2 -> V_276 = false ;
}
F_97 ( V_2 ) ;
}
if ( V_4 -> V_58 . V_59 ) {
V_4 -> V_58 . V_153 = V_96 -> V_277 &
V_278 ;
V_4 -> V_58 . V_279 = ! ! ( V_96 -> V_277 &
V_280 ) ;
F_86 ( V_2 , V_4 , V_96 ) ;
F_53 ( V_2 , & V_2 -> V_224 ) ;
}
F_52 ( V_2 , V_4 ) ;
if ( V_96 -> V_281 && ( V_2 -> V_28 != V_164 ) )
V_4 -> V_5 . V_17 |= V_179 ;
else
V_4 -> V_5 . V_17 &= ~ V_179 ;
if ( V_96 -> V_281 )
V_4 -> V_5 . V_17 |= V_213 ;
else
V_4 -> V_5 . V_17 &= ~ V_213 ;
memcpy ( V_4 -> V_5 . V_175 , V_96 -> V_238 , V_33 ) ;
if ( V_6 -> type == V_9 ||
V_6 -> type == V_15 ) {
if ( V_6 -> V_96 . V_282 ) {
V_4 -> V_5 . V_13 |= V_41 ;
V_2 -> V_283 = V_4 ;
} else {
V_4 -> V_5 . V_13 &= ~ V_41 ;
V_2 -> V_283 = NULL ;
}
}
if ( V_6 -> type == V_11 ) {
if ( ! V_96 -> V_142 )
V_4 -> V_5 . V_13 |= V_19 ;
else
V_4 -> V_5 . V_13 &=
~ V_19 ;
}
if ( V_109 || memcmp ( & V_4 -> V_5 , & V_4 -> V_71 , sizeof( V_4 -> V_5 ) ) )
F_69 ( V_2 , V_4 ) ;
if ( V_267 & V_274 && V_96 -> V_142 ) {
if ( V_2 -> V_251 . V_253 == V_284 )
F_73 ( V_2 , false ) ;
F_90 ( V_2 ) ;
V_2 -> V_123 = 1 ;
}
if ( V_267 & V_285 ) {
V_40 = F_98 ( V_2 , V_6 ,
V_96 -> V_286 ) ;
if ( V_40 )
F_2 ( V_2 , L_65 ,
V_96 -> V_286 ? L_66 : L_67 ,
V_96 -> V_238 ) ;
}
if ( V_267 & V_287 && V_2 -> V_283 == V_4 ) {
if ( F_16 ( V_2 , V_6 ) )
F_2 ( V_2 , L_68 ) ;
}
F_85 ( & V_2 -> V_64 ) ;
}
void F_99 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_100 ( V_2 , & V_2 -> V_288 . V_289 , false ) ;
F_37 ( V_2 , V_2 -> V_120 , false ) ;
F_54 (priv, ctx)
if ( memcmp ( & V_4 -> V_5 , & V_4 -> V_71 , sizeof( V_4 -> V_5 ) ) )
F_69 ( V_2 , V_4 ) ;
F_46 ( V_2 ) ;
}
