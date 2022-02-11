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
V_4 -> V_5 . V_22 = F_3 ( V_2 -> V_23 -> V_24 . V_22 -> V_25 ) ;
V_2 -> V_26 = V_2 -> V_23 -> V_24 . V_22 -> V_26 ;
F_4 ( V_2 , V_4 , V_2 -> V_26 , V_4 -> V_6 ) ;
V_4 -> V_5 . V_17 &= ~ ( V_27 |
V_28 ) ;
if ( V_4 -> V_6 )
memcpy ( V_4 -> V_5 . V_29 , V_4 -> V_6 -> V_30 , V_31 ) ;
V_4 -> V_5 . V_32 = 0xff ;
V_4 -> V_5 . V_33 = 0xff ;
V_4 -> V_5 . V_34 = 0xff ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_35 * V_36 )
{
T_1 V_37 = V_36 -> V_13 ;
int V_38 ;
V_36 -> V_13 &= ~ V_39 ;
V_38 = F_6 ( V_2 , V_4 -> V_40 ,
V_41 , sizeof( * V_36 ) , V_36 ) ;
V_36 -> V_13 = V_37 ;
if ( V_38 )
F_7 ( V_2 ,
L_2 , V_38 ) ;
return V_38 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_35 * V_36 )
{
struct V_42 V_43 ;
T_1 V_37 = V_36 -> V_13 ;
T_2 V_44 = V_36 -> V_7 ;
int V_38 ;
static const T_2 V_45 [] = {
V_46
} ;
F_9 ( & V_2 -> V_47 , & V_43 ,
V_45 , F_10 ( V_45 ) ,
NULL , NULL ) ;
V_36 -> V_13 &= ~ V_39 ;
V_36 -> V_7 = V_48 ;
V_38 = F_6 ( V_2 , V_4 -> V_40 ,
V_41 , sizeof( * V_36 ) , V_36 ) ;
V_36 -> V_13 = V_37 ;
V_36 -> V_7 = V_44 ;
if ( V_38 ) {
F_2 ( V_2 , L_3 , V_38 ) ;
F_11 ( & V_2 -> V_47 , & V_43 ) ;
} else {
V_38 = F_12 ( & V_2 -> V_47 ,
& V_43 , V_49 ) ;
if ( V_38 )
F_2 ( V_2 , L_4 ) ;
}
return V_38 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_35 * V_36 )
{
T_1 V_37 = V_36 -> V_13 ;
int V_38 ;
V_36 -> V_13 &= ~ V_39 ;
V_38 = F_6 ( V_2 , V_4 -> V_40 , V_41 ,
sizeof( * V_36 ) , V_36 ) ;
V_36 -> V_13 = V_37 ;
return V_38 ;
}
static void F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_38 ;
if ( ! V_4 -> V_50 )
return;
V_4 -> V_51 . V_52 . V_53 = 0 ;
if ( V_4 -> V_51 . V_54 )
V_4 -> V_51 . V_52 . V_53 |=
V_55 ;
if ( V_4 -> V_56 . V_57 )
V_4 -> V_51 . V_52 . V_53 |= V_58 ;
F_15 ( V_2 , L_5 ,
V_4 -> V_51 . V_54 ,
V_4 -> V_51 . V_52 . V_53 ) ;
V_38 = F_6 ( V_2 , V_4 -> V_59 , V_41 ,
sizeof( struct V_60 ) ,
& V_4 -> V_51 . V_52 ) ;
if ( V_38 )
F_7 ( V_2 , L_6 ) ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_61 * V_6 )
{
F_17 ( & V_2 -> V_62 ) ;
F_18 ( V_2 -> V_63 ) ;
V_2 -> V_63 = F_19 ( V_2 -> V_23 , V_6 ) ;
if ( ! V_2 -> V_63 )
return - V_64 ;
return F_20 ( V_2 ) ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_38 = 0 ;
struct V_65 V_66 ;
const struct V_35 * V_67 = & V_4 -> V_5 ;
const struct V_35 * V_68 = & V_4 -> V_69 ;
if ( ( V_67 -> V_17 == V_68 -> V_17 ) &&
( V_67 -> V_13 == V_68 -> V_13 ) &&
( V_67 -> V_70 == V_68 -> V_70 ) &&
( V_67 -> V_32 ==
V_68 -> V_32 ) &&
( V_67 -> V_33 ==
V_68 -> V_33 ) &&
( V_67 -> V_34 ==
V_68 -> V_34 ) &&
( V_67 -> V_71 == V_68 -> V_71 ) &&
( V_67 -> V_72 == V_68 -> V_72 ) &&
( V_67 -> V_73 == V_68 -> V_73 ) ) {
F_15 ( V_2 , L_7 ) ;
return 0 ;
}
V_66 . V_17 = V_4 -> V_5 . V_17 ;
V_66 . V_13 = V_4 -> V_5 . V_13 ;
V_66 . V_73 = V_4 -> V_5 . V_73 ;
V_66 . V_70 = V_4 -> V_5 . V_70 ;
V_66 . V_74 = 0 ;
V_66 . V_75 = 0 ;
V_66 . V_76 = 0 ;
V_66 . V_32 =
V_4 -> V_5 . V_32 ;
V_66 . V_33 =
V_4 -> V_5 . V_33 ;
V_66 . V_77 = V_4 -> V_5 . V_72 ;
V_66 . V_34 =
V_4 -> V_5 . V_34 ;
V_66 . V_71 = V_4 -> V_5 . V_71 ;
V_38 = F_6 ( V_2 , V_4 -> V_78 ,
V_79 , sizeof( V_66 ) , & V_66 ) ;
return V_38 ;
}
static T_3 F_22 ( T_3 V_80 , T_3 V_81 )
{
T_3 V_82 ;
T_3 V_83 ;
if ( ! V_80 )
return V_84 ;
V_83 = ( V_80 + V_81 ) / V_81 ;
V_82 = V_80 / V_83 ;
if ( ! V_82 )
V_82 = V_81 ;
return V_82 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_4 V_85 ;
T_5 V_86 , V_87 ;
struct V_88 * V_24 = NULL ;
T_3 V_89 ;
struct V_61 * V_6 = V_4 -> V_6 ;
V_24 = & V_2 -> V_23 -> V_24 ;
F_17 ( & V_2 -> V_62 ) ;
memset ( & V_4 -> V_90 , 0 , sizeof( struct V_91 ) ) ;
V_4 -> V_90 . V_92 = F_24 ( V_2 -> V_92 ) ;
V_4 -> V_90 . V_93 = F_3 ( V_24 -> V_93 ) ;
V_89 = V_6 ? V_6 -> V_94 . V_89 : 0 ;
V_4 -> V_90 . V_95 = 0 ;
if ( V_4 -> V_96 == V_97 &&
( ! V_4 -> V_6 || V_4 -> V_6 -> type != V_11 ) &&
F_25 ( V_2 , V_98 ) &&
V_2 -> V_99 [ V_98 ] . V_6 &&
V_2 -> V_99 [ V_98 ] . V_6 -> V_94 . V_89 ) {
V_4 -> V_90 . V_100 =
V_2 -> V_99 [ V_98 ] . V_90 . V_100 ;
V_89 = F_26 ( V_4 -> V_90 . V_100 ) ;
} else if ( V_4 -> V_96 == V_98 &&
F_25 ( V_2 , V_97 ) &&
V_2 -> V_99 [ V_97 ] . V_6 &&
V_2 -> V_99 [ V_97 ] . V_6 -> V_94 . V_89 &&
( ! F_27 ( V_4 ) || ! V_4 -> V_6 ||
! V_4 -> V_6 -> V_94 . V_89 ) ) {
V_4 -> V_90 . V_100 =
V_2 -> V_99 [ V_97 ] . V_90 . V_100 ;
V_89 = F_26 ( V_4 -> V_90 . V_100 ) ;
} else {
V_89 = F_22 ( V_89 ,
V_101 * V_102 ) ;
V_4 -> V_90 . V_100 = F_3 ( V_89 ) ;
}
V_4 -> V_89 = V_89 ;
V_85 = V_2 -> V_92 ;
V_86 = V_89 * V_102 ;
V_87 = F_28 ( V_85 , V_86 ) ;
V_4 -> V_90 . V_103 = F_29 ( V_86 - V_87 ) ;
V_4 -> V_90 . V_104 = V_6 ? ( V_6 -> V_94 . V_104 ? : 1 ) : 1 ;
F_30 ( V_2 ,
L_8 ,
F_26 ( V_4 -> V_90 . V_100 ) ,
F_31 ( V_4 -> V_90 . V_103 ) ,
F_26 ( V_4 -> V_90 . V_95 ) ) ;
return F_6 ( V_2 , V_4 -> V_105 ,
V_41 , sizeof( V_4 -> V_90 ) , & V_4 -> V_90 ) ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_38 ;
struct V_35 * V_69 = ( void * ) & V_4 -> V_69 ;
if ( V_4 -> V_96 == V_98 ) {
V_38 = F_5 ( V_2 , V_4 , & V_4 -> V_5 ) ;
} else {
V_38 = F_8 ( V_2 , V_4 , & V_4 -> V_5 ) ;
if ( V_38 )
return V_38 ;
if ( V_4 -> V_6 ) {
V_38 = F_23 ( V_2 , V_4 ) ;
if ( V_38 ) {
F_2 ( V_2 , L_9 , V_38 ) ;
return V_38 ;
}
V_38 = F_13 ( V_2 , V_4 , & V_4 -> V_5 ) ;
}
}
if ( V_38 )
return V_38 ;
F_33 ( V_2 , V_4 ) ;
F_34 ( V_2 , V_4 ) ;
F_35 ( V_2 , V_4 ) ;
V_38 = F_36 ( V_2 , V_4 ) ;
if ( V_38 ) {
F_2 ( V_2 , L_10 , V_38 ) ;
return V_38 ;
}
memcpy ( V_69 , & V_4 -> V_5 , sizeof( * V_69 ) ) ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 , T_6 V_106 , bool V_107 )
{
int V_38 ;
T_6 V_108 ;
bool V_109 ;
struct V_3 * V_4 = & V_2 -> V_99 [ V_98 ] ;
if ( V_2 -> V_110 & V_111 )
return 0 ;
F_17 ( & V_2 -> V_62 ) ;
if ( V_2 -> V_112 == V_106 && ! V_107 )
return 0 ;
if ( V_106 < V_113 ) {
F_38 ( V_2 ,
L_11 ,
V_106 ,
V_113 ) ;
return - V_114 ;
}
if ( V_106 > F_39 ( V_2 -> V_115 -> V_116 , 2 ) ) {
F_38 ( V_2 ,
L_12 ,
V_106 , V_2 -> V_115 -> V_116 ) ;
return - V_114 ;
}
if ( ! F_40 ( V_2 ) )
return - V_117 ;
V_2 -> V_118 = V_106 ;
V_109 = F_41 ( V_119 , & V_2 -> V_120 ) ||
memcmp ( & V_4 -> V_69 , & V_4 -> V_5 , sizeof( V_4 -> V_5 ) ) ;
if ( V_109 && ! V_107 ) {
F_15 ( V_2 , L_13 ) ;
return 0 ;
}
V_108 = V_2 -> V_112 ;
V_2 -> V_112 = V_106 ;
V_38 = F_42 ( V_2 ) ;
if ( V_38 ) {
V_2 -> V_112 = V_108 ;
V_2 -> V_118 = V_108 ;
}
return V_38 ;
}
static int F_43 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_38 ;
struct V_35 * V_69 = ( void * ) & V_4 -> V_69 ;
if ( V_4 -> V_96 == V_98 ) {
V_38 = F_23 ( V_2 , V_4 ) ;
if ( V_38 ) {
F_2 ( V_2 , L_9 , V_38 ) ;
return V_38 ;
}
}
F_14 ( V_2 , V_4 ) ;
if ( V_4 -> V_6 && ( V_4 -> V_6 -> type == V_9 ) ) {
V_38 = F_16 ( V_2 , V_4 -> V_6 ) ;
if ( V_38 ) {
F_2 ( V_2 ,
L_14 ,
V_38 ) ;
return V_38 ;
}
}
V_2 -> V_121 = 0 ;
V_38 = F_6 ( V_2 , V_4 -> V_40 , V_41 ,
sizeof( struct V_35 ) , & V_4 -> V_5 ) ;
if ( V_38 ) {
F_2 ( V_2 , L_15 , V_38 ) ;
return V_38 ;
}
memcpy ( V_69 , & V_4 -> V_5 , sizeof( * V_69 ) ) ;
if ( V_4 -> V_6 && ( V_4 -> V_6 -> type == V_15 ) )
if ( F_16 ( V_2 , V_4 -> V_6 ) )
F_2 ( V_2 , L_16 ) ;
F_44 ( V_2 ) ;
V_38 = F_37 ( V_2 , V_2 -> V_118 , true ) ;
if ( V_38 ) {
F_2 ( V_2 , L_17 , V_38 ) ;
return V_38 ;
}
if ( V_4 -> V_6 && V_4 -> V_6 -> type == V_11 &&
V_2 -> V_122 -> V_123 && V_2 -> V_122 -> V_123 -> V_124 )
F_45 ( V_4 -> V_6 ,
V_2 -> V_122 -> V_123 -> V_124 ) ;
return 0 ;
}
int F_46 ( struct V_1 * V_2 )
{
struct V_125 V_126 ;
struct V_3 * V_127 , * V_128 ;
int V_129 = 300 , V_130 = 0 ;
int V_38 ;
if ( V_2 -> V_131 == F_47 ( V_98 ) )
return 0 ;
F_48 ( V_132 != 2 ) ;
F_17 ( & V_2 -> V_62 ) ;
V_127 = & V_2 -> V_99 [ V_98 ] ;
V_128 = & V_2 -> V_99 [ V_97 ] ;
if ( ! V_128 -> V_50 )
return 0 ;
memset ( & V_126 , 0 , sizeof( V_126 ) ) ;
V_126 . V_133 = 2 ;
V_126 . V_134 [ 0 ] . type = 0 ;
V_126 . V_134 [ 1 ] . type = 1 ;
if ( V_2 -> V_135 ) {
V_130 = V_136 ;
V_129 = 3000 ;
} else if ( V_127 -> V_6 && V_128 -> V_6 ) {
int V_137 = V_128 -> V_89 ;
int V_138 = V_128 -> V_6 -> V_94 . V_104 ? : 1 ;
V_126 . V_17 |= F_3 ( V_139 ) ;
if ( V_128 -> V_6 -> type == V_9 &&
V_137 &&
V_137 != V_127 -> V_89 ) {
F_2 ( V_2 ,
L_18 ,
V_127 -> V_89 , V_128 -> V_89 ) ;
} else
V_137 = F_49 ( int , V_137 ,
V_127 -> V_89 ) ;
if ( ! V_137 )
V_137 = V_84 ;
V_129 = V_137 / 2 ;
V_130 = V_137 - V_129 ;
if ( F_41 ( V_140 , & V_2 -> V_120 ) ||
( ! V_127 -> V_6 -> V_94 . V_141 &&
! V_127 -> V_6 -> V_94 . V_142 ) ) {
V_129 = V_138 * V_137 * 3 - V_136 ;
V_130 = V_136 ;
} else if ( ! V_128 -> V_6 -> V_94 . V_141 &&
! V_128 -> V_6 -> V_94 . V_142 ) {
V_130 = V_138 * V_137 * 3 - V_136 ;
V_129 = V_136 ;
}
} else if ( V_128 -> V_6 ) {
V_129 = 0 ;
V_130 = F_49 ( int , 1 , V_128 -> V_6 -> V_94 . V_104 ) *
V_128 -> V_89 ;
V_130 = F_49 ( int , V_84 , V_130 ) ;
if ( F_41 ( V_140 , & V_2 -> V_120 ) ) {
V_129 = V_130 * 3 - V_136 ;
V_130 = V_136 ;
}
}
V_126 . V_134 [ 0 ] . V_143 = F_3 ( V_129 ) ;
V_126 . V_134 [ 1 ] . V_143 = F_3 ( V_130 ) ;
V_38 = F_6 ( V_2 , V_144 , V_41 ,
sizeof( V_126 ) , & V_126 ) ;
if ( V_38 )
F_2 ( V_2 , L_19 , V_38 ) ;
return V_38 ;
}
static void F_50 ( struct V_1 * V_2 ,
struct V_145 * V_146 ,
struct V_3 * V_4 )
{
struct V_35 * V_147 = & V_4 -> V_5 ;
if ( ! V_4 -> V_56 . V_57 ) {
V_147 -> V_17 &= ~ ( V_148 |
V_149 |
V_150 |
V_151 ) ;
return;
}
V_147 -> V_17 |= F_29 ( V_4 -> V_56 . V_152 <<
V_153 ) ;
V_147 -> V_17 &= ~ ( V_148 |
V_149 ) ;
if ( F_51 ( V_2 , V_4 , NULL ) ) {
if ( V_4 -> V_56 . V_152 ==
V_154 ) {
V_147 -> V_17 |= V_28 ;
switch ( V_4 -> V_56 . V_155 ) {
case V_156 :
V_147 -> V_17 &=
~ V_149 ;
break;
case V_157 :
V_147 -> V_17 |=
V_149 ;
break;
}
} else {
switch ( V_4 -> V_56 . V_155 ) {
case V_156 :
V_147 -> V_17 &=
~ ( V_149 ) ;
V_147 -> V_17 |= V_27 ;
break;
case V_157 :
V_147 -> V_17 |= V_149 ;
V_147 -> V_17 |= V_27 ;
break;
case V_158 :
default:
F_2 ( V_2 ,
L_20 ) ;
break;
}
}
} else {
V_147 -> V_17 |= V_159 ;
}
F_52 ( V_2 , V_4 ) ;
F_30 ( V_2 , L_21
L_22 ,
F_31 ( V_147 -> V_17 ) , V_4 -> V_56 . V_152 ,
V_4 -> V_56 . V_155 ) ;
}
void F_53 ( struct V_1 * V_2 , struct V_145 * V_146 )
{
struct V_3 * V_4 ;
F_54 (priv, ctx)
F_50 ( V_2 , V_146 , V_4 ) ;
}
void F_55 ( struct V_1 * V_2 , struct V_160 * V_161 ,
struct V_3 * V_4 )
{
enum V_162 V_26 = V_161 -> V_26 ;
T_3 V_22 = V_161 -> V_25 ;
if ( ( F_26 ( V_4 -> V_5 . V_22 ) == V_22 ) &&
( V_2 -> V_26 == V_26 ) )
return;
V_4 -> V_5 . V_22 = F_3 ( V_22 ) ;
if ( V_26 == V_163 )
V_4 -> V_5 . V_17 &= ~ V_164 ;
else
V_4 -> V_5 . V_17 |= V_164 ;
V_2 -> V_26 = V_26 ;
F_15 ( V_2 , L_23 , V_22 , V_26 ) ;
}
void F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
enum V_162 V_26 ,
struct V_61 * V_6 )
{
if ( V_26 == V_163 ) {
V_4 -> V_5 . V_17 &=
~ ( V_164 | V_165
| V_166 ) ;
V_4 -> V_5 . V_17 |= V_167 ;
} else {
if ( V_6 && V_6 -> V_94 . V_168 )
V_4 -> V_5 . V_17 |= V_167 ;
else
V_4 -> V_5 . V_17 &= ~ V_167 ;
V_4 -> V_5 . V_17 |= V_164 ;
V_4 -> V_5 . V_17 |= V_165 ;
V_4 -> V_5 . V_17 &= ~ V_166 ;
}
}
static void F_56 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_169 )
{
struct V_35 * V_147 = & V_4 -> V_5 ;
if ( V_169 )
V_147 -> V_13 &= ~ V_170 ;
else
V_147 -> V_13 |= V_170 ;
}
static int F_57 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_35 * V_147 = & V_4 -> V_5 ;
T_7 V_171 = 0 ;
if ( V_147 -> V_17 & V_164 ) {
if ( V_147 -> V_17 & V_172 ) {
F_38 ( V_2 , L_24 ) ;
V_171 |= F_47 ( 0 ) ;
}
if ( V_147 -> V_17 & V_173 ) {
F_38 ( V_2 , L_25 ) ;
V_171 |= F_47 ( 1 ) ;
}
} else {
if ( ! ( V_147 -> V_17 & V_167 ) ) {
F_38 ( V_2 , L_26 ) ;
V_171 |= F_47 ( 2 ) ;
}
if ( V_147 -> V_17 & V_166 ) {
F_38 ( V_2 , L_27 ) ;
V_171 |= F_47 ( 3 ) ;
}
}
if ( ( V_147 -> V_29 [ 0 ] | V_147 -> V_174 [ 0 ] ) & 0x1 ) {
F_38 ( V_2 , L_28 ) ;
V_171 |= F_47 ( 4 ) ;
}
if ( ( V_147 -> V_73 & V_175 ) == 0 &&
( V_147 -> V_70 & V_176 ) == 0 ) {
F_38 ( V_2 , L_29 ) ;
V_171 |= F_47 ( 5 ) ;
}
if ( F_26 ( V_147 -> V_177 ) > 2007 ) {
F_38 ( V_2 , L_30 ) ;
V_171 |= F_47 ( 6 ) ;
}
if ( ( V_147 -> V_17 & ( V_166 | V_167 ) )
== ( V_166 | V_167 ) ) {
F_38 ( V_2 , L_31 ) ;
V_171 |= F_47 ( 7 ) ;
}
if ( ( V_147 -> V_17 & ( V_166 | V_165 ) )
== ( V_166 | V_165 ) ) {
F_38 ( V_2 , L_32 ) ;
V_171 |= F_47 ( 8 ) ;
}
if ( ( V_147 -> V_17 & ( V_165 |
V_178 ) ) ==
V_178 ) {
F_38 ( V_2 , L_33 ) ;
V_171 |= F_47 ( 9 ) ;
}
if ( V_147 -> V_22 == 0 ) {
F_38 ( V_2 , L_34 ) ;
V_171 |= F_47 ( 10 ) ;
}
F_58 ( V_171 , L_35 ,
V_171 , F_26 ( V_147 -> V_22 ) ) ;
return V_171 ? - V_114 : 0 ;
}
static int F_59 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
const struct V_35 * V_5 = & V_4 -> V_5 ;
const struct V_35 * V_69 = & V_4 -> V_69 ;
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
F_60 ( ! F_62 ( V_5 -> V_174 , V_69 -> V_174 ) ) ;
F_60 ( ! F_62 ( V_5 -> V_29 , V_69 -> V_29 ) ) ;
F_60 ( ! F_62 ( V_5 -> V_179 ,
V_69 -> V_179 ) ) ;
F_61 ( V_5 -> V_7 , V_69 -> V_7 ) ;
F_61 ( V_5 -> V_22 , V_69 -> V_22 ) ;
F_61 ( V_5 -> V_180 , V_69 -> V_180 ) ;
F_61 ( V_5 -> V_32 ,
V_69 -> V_32 ) ;
F_61 ( V_5 -> V_33 ,
V_69 -> V_33 ) ;
F_61 ( V_5 -> V_34 ,
V_69 -> V_34 ) ;
F_61 ( V_5 -> V_177 , V_69 -> V_177 ) ;
F_61 ( V_5 -> V_17 & V_164 ,
V_69 -> V_17 & V_164 ) ;
F_61 ( V_5 -> V_13 & V_39 ,
V_69 -> V_13 & V_39 ) ;
#undef F_60
#undef F_61
return 0 ;
}
void F_63 ( struct V_1 * V_2 ,
enum V_181 V_96 )
{
struct V_3 * V_4 = & V_2 -> V_99 [ V_96 ] ;
struct V_35 * V_147 = & V_4 -> V_5 ;
F_64 ( V_2 , L_36 ) ;
F_65 ( V_2 , V_182 , ( T_2 * ) V_147 , sizeof( * V_147 ) ) ;
F_64 ( V_2 , L_37 ,
F_26 ( V_147 -> V_22 ) ) ;
F_64 ( V_2 , L_38 ,
F_31 ( V_147 -> V_17 ) ) ;
F_64 ( V_2 , L_39 ,
F_31 ( V_147 -> V_13 ) ) ;
F_64 ( V_2 , L_40 , V_147 -> V_7 ) ;
F_64 ( V_2 , L_41 ,
V_147 -> V_73 ) ;
F_64 ( V_2 , L_42 ,
V_147 -> V_70 ) ;
F_64 ( V_2 , L_43 , V_147 -> V_29 ) ;
F_64 ( V_2 , L_44 , V_147 -> V_174 ) ;
F_64 ( V_2 , L_45 ,
F_26 ( V_147 -> V_177 ) ) ;
}
static void F_66 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_183 = 100 ;
int V_184 = 100 ;
T_2 V_185 = 0 ;
T_2 V_186 = 0 ;
if ( V_4 -> V_6 ) {
struct V_187 * V_188 ;
unsigned long V_189 = V_4 -> V_6 -> V_94 . V_190 ;
int V_191 ;
V_188 = V_2 -> V_23 -> V_192 -> V_193 [ V_2 -> V_23 -> V_24 . V_22 -> V_26 ] ;
F_67 (i, &basic, BITS_PER_LONG) {
int V_23 = V_188 -> V_194 [ V_191 ] . V_25 ;
if ( V_23 >= V_195 ) {
V_186 |= F_47 ( V_23 - V_195 ) ;
if ( V_183 > V_23 )
V_183 = V_23 ;
} else {
F_48 ( V_196 != 0 ) ;
V_185 |= F_47 ( V_23 ) ;
if ( V_184 > V_23 )
V_184 = V_23 ;
}
}
}
if ( V_197 < V_183 )
V_186 |= V_198 >> V_195 ;
if ( V_199 < V_183 )
V_186 |= V_200 >> V_195 ;
V_186 |= V_175 >> V_195 ;
if ( V_201 < V_183 )
V_186 |= V_202 >> V_196 ;
if ( V_203 < V_183 )
V_186 |= V_204 >> V_196 ;
if ( V_205 < V_183 )
V_186 |= V_206 >> V_196 ;
V_185 |= V_176 >> V_196 ;
F_68 ( V_2 , L_46 ,
V_185 , V_186 ) ;
V_4 -> V_5 . V_70 = V_185 ;
V_4 -> V_5 . V_73 = V_186 ;
}
int F_69 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_35 * V_69 = ( void * ) & V_4 -> V_69 ;
bool V_207 = ! ! ( V_4 -> V_5 . V_13 & V_39 ) ;
int V_38 ;
F_17 ( & V_2 -> V_62 ) ;
if ( ! F_70 ( V_2 ) )
return - V_208 ;
F_48 ( V_132 != 2 ) ;
if ( ! V_4 -> V_50 )
return 0 ;
V_4 -> V_5 . V_17 |= V_209 ;
F_66 ( V_2 , V_4 ) ;
if ( ! V_2 -> V_210 . V_211 )
V_4 -> V_5 . V_17 |= V_212 ;
if ( ( V_4 -> V_6 && V_4 -> V_6 -> V_94 . V_168 ) ||
! ( V_4 -> V_5 . V_17 & V_164 ) )
V_4 -> V_5 . V_17 |= V_167 ;
else
V_4 -> V_5 . V_17 &= ~ V_167 ;
F_63 ( V_2 , V_4 -> V_96 ) ;
V_38 = F_57 ( V_2 , V_4 ) ;
if ( V_38 ) {
F_2 ( V_2 , L_47 ) ;
return - V_114 ;
}
if ( F_41 ( V_213 , & V_2 -> V_120 ) &&
( V_2 -> V_214 != V_4 -> V_5 . V_22 ) ) {
F_71 ( V_2 , L_48 ,
F_26 ( V_2 -> V_214 ) ) ;
F_72 ( V_2 , false ) ;
}
if ( ! F_59 ( V_2 , V_4 ) ) {
V_38 = F_21 ( V_2 , V_4 ) ;
if ( V_38 ) {
F_2 ( V_2 , L_49 , V_38 ) ;
return V_38 ;
}
memcpy ( V_69 , & V_4 -> V_5 , sizeof( * V_69 ) ) ;
F_37 ( V_2 , V_2 -> V_118 , false ) ;
F_73 ( V_2 , true ) ;
return 0 ;
}
F_56 ( V_2 , V_4 , ! V_215 . V_216 ) ;
F_15 ( V_2 ,
L_50
L_51
L_52
L_53 ,
( V_207 ? L_54 : L_55 ) ,
F_26 ( V_4 -> V_5 . V_22 ) ,
V_4 -> V_5 . V_174 ) ;
V_38 = F_32 ( V_2 , V_4 ) ;
if ( V_38 )
return V_38 ;
V_38 = F_46 ( V_2 ) ;
if ( V_38 )
return V_38 ;
if ( V_207 )
return F_43 ( V_2 , V_4 ) ;
return 0 ;
}
void F_74 ( struct V_88 * V_24 ,
struct V_3 * V_4 )
{
if ( F_75 ( V_24 ) ) {
V_4 -> V_56 . V_155 =
V_157 ;
V_4 -> V_56 . V_217 = true ;
} else if ( F_76 ( V_24 ) ) {
V_4 -> V_56 . V_155 =
V_156 ;
V_4 -> V_56 . V_217 = true ;
} else {
V_4 -> V_56 . V_155 =
V_158 ;
V_4 -> V_56 . V_217 = false ;
}
}
int F_77 ( struct V_218 * V_23 , T_7 V_219 )
{
struct V_1 * V_2 = F_78 ( V_23 ) ;
struct V_3 * V_4 ;
struct V_88 * V_24 = & V_23 -> V_24 ;
struct V_160 * V_22 = V_24 -> V_22 ;
int V_38 = 0 ;
F_79 ( V_2 , L_56 , V_219 ) ;
F_80 ( & V_2 -> V_62 ) ;
if ( F_81 ( F_41 ( V_119 , & V_2 -> V_120 ) ) ) {
F_79 ( V_2 , L_57 ) ;
goto V_220;
}
if ( ! F_82 ( V_2 ) ) {
F_79 ( V_2 , L_58 ) ;
goto V_220;
}
if ( V_219 & ( V_221 |
V_222 ) ) {
V_2 -> V_223 . V_224 = V_24 -> V_124 ;
F_54 (priv, ctx)
F_52 ( V_2 , V_4 ) ;
}
if ( V_219 & V_222 ) {
F_54 (priv, ctx) {
if ( V_4 -> V_56 . V_57 != F_83 ( V_24 ) )
V_4 -> V_56 . V_57 = F_83 ( V_24 ) ;
if ( V_4 -> V_56 . V_57 ) {
if ( ! V_4 -> V_56 . V_217 ||
! F_27 ( V_4 ) )
F_74 ( V_24 , V_4 ) ;
} else
V_4 -> V_56 . V_217 = false ;
V_4 -> V_56 . V_152 = V_225 ;
if ( F_26 ( V_4 -> V_5 . V_22 ) !=
V_22 -> V_25 )
V_4 -> V_5 . V_17 = 0 ;
F_55 ( V_2 , V_22 , V_4 ) ;
F_53 ( V_2 , & V_2 -> V_223 ) ;
F_4 ( V_2 , V_4 , V_22 -> V_26 ,
V_4 -> V_6 ) ;
}
F_84 ( V_2 ) ;
}
if ( V_219 & ( V_226 |
V_227 ) ) {
V_38 = F_73 ( V_2 , false ) ;
if ( V_38 )
F_79 ( V_2 , L_59 ) ;
}
if ( V_219 & V_228 ) {
F_79 ( V_2 , L_60 ,
V_2 -> V_112 , V_24 -> V_229 ) ;
F_37 ( V_2 , V_24 -> V_229 , false ) ;
}
F_54 (priv, ctx) {
if ( ! memcmp ( & V_4 -> V_5 , & V_4 -> V_69 , sizeof( V_4 -> V_5 ) ) )
continue;
F_69 ( V_2 , V_4 ) ;
}
V_220:
F_85 ( & V_2 -> V_62 ) ;
F_79 ( V_2 , L_61 ) ;
return V_38 ;
}
static void F_86 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_230 * V_94 )
{
struct V_61 * V_6 = V_4 -> V_6 ;
struct V_3 * V_231 ;
struct V_232 * V_233 ;
struct V_145 * V_146 = & V_2 -> V_223 ;
struct V_234 * V_235 ;
bool V_236 ;
F_17 ( & V_2 -> V_62 ) ;
switch ( V_6 -> type ) {
case V_11 :
F_87 () ;
V_233 = F_88 ( V_6 , V_94 -> V_237 ) ;
if ( ! V_233 ) {
V_236 = false ;
F_89 () ;
break;
}
V_235 = & V_233 -> V_235 ;
V_236 = true ;
if ( V_235 -> V_238 . V_239 [ 1 ] == 0 &&
V_235 -> V_238 . V_239 [ 2 ] == 0 ) {
V_236 = false ;
} else if ( ! ( V_235 -> V_238 . V_240 &
V_241 ) ) {
V_236 = false ;
} else if ( V_235 -> V_238 . V_240 &
V_242 ) {
int V_243 ;
V_243 = ( V_235 -> V_238 . V_240 &
V_244 ) ;
V_243 >>=
V_245 ;
V_243 += 1 ;
if ( V_243 <= 1 )
V_236 = false ;
}
F_89 () ;
break;
case V_15 :
V_236 = false ;
break;
default:
V_236 = true ;
break;
}
V_4 -> V_246 = V_236 ;
if ( ! V_236 ) {
F_54 (priv, tmp) {
if ( ! V_231 -> V_6 )
continue;
if ( V_231 -> V_246 ) {
V_236 = true ;
break;
}
}
}
V_146 -> V_247 = ! V_236 ;
}
static void F_90 ( struct V_1 * V_2 )
{
struct V_248 * V_249 = & V_2 -> V_250 ;
int V_38 ;
if ( ! ( V_2 -> V_110 & V_251 ) )
return;
if ( ( V_249 -> V_252 == V_253 ) &&
F_91 ( V_2 ) ) {
struct V_254 V_126 ;
V_249 -> V_255 = 0 ;
V_249 -> V_256 = 0 ;
V_249 -> V_257 = 0 ;
V_249 -> V_258 = 0 ;
V_249 -> V_259 = 0 ;
V_249 -> V_260 = 0 ;
V_249 -> V_261 = 0 ;
memset ( & V_126 , 0 , sizeof( V_126 ) ) ;
F_92 ( & V_126 . V_262 ,
V_2 -> V_263 ) ;
V_38 = F_6 ( V_2 ,
V_264 ,
V_41 , sizeof( V_126 ) , & V_126 ) ;
if ( V_38 )
F_2 ( V_2 ,
L_62 ) ;
V_249 -> V_252 = V_265 ;
F_93 ( V_2 , L_63 ) ;
}
}
void F_94 ( struct V_218 * V_23 ,
struct V_61 * V_6 ,
struct V_230 * V_94 ,
T_7 V_266 )
{
struct V_1 * V_2 = F_78 ( V_23 ) ;
struct V_3 * V_4 = F_95 ( V_6 ) ;
int V_38 ;
bool V_107 = false ;
F_80 ( & V_2 -> V_62 ) ;
if ( F_81 ( ! F_82 ( V_2 ) ) ) {
F_79 ( V_2 , L_58 ) ;
F_85 ( & V_2 -> V_62 ) ;
return;
}
if ( F_81 ( ! V_4 -> V_6 ) ) {
F_79 ( V_2 , L_64 ) ;
F_85 ( & V_2 -> V_62 ) ;
return;
}
if ( V_266 & V_267 )
V_107 = true ;
if ( V_266 & V_268 ) {
V_4 -> V_51 . V_54 = V_94 -> V_269 ;
F_14 ( V_2 , V_4 ) ;
}
V_4 -> V_5 . V_177 = F_3 ( V_6 -> V_94 . V_270 ) ;
if ( V_6 -> V_94 . V_271 )
V_4 -> V_5 . V_17 |= V_18 ;
else
V_4 -> V_5 . V_17 &= ~ V_18 ;
if ( V_266 & V_272 ) {
if ( V_94 -> V_142 ) {
V_2 -> V_92 = V_94 -> V_273 ;
V_4 -> V_5 . V_13 |= V_39 ;
} else {
F_96 ( V_2 ) ;
V_4 -> V_5 . V_13 &= ~ V_39 ;
if ( V_4 -> V_96 == V_98 )
V_2 -> V_274 = false ;
}
F_97 ( V_2 ) ;
}
if ( V_4 -> V_56 . V_57 ) {
V_4 -> V_56 . V_152 = V_94 -> V_275 &
V_276 ;
V_4 -> V_56 . V_277 = ! ! ( V_94 -> V_275 &
V_278 ) ;
F_86 ( V_2 , V_4 , V_94 ) ;
F_53 ( V_2 , & V_2 -> V_223 ) ;
}
F_52 ( V_2 , V_4 ) ;
if ( V_94 -> V_279 && ( V_2 -> V_26 != V_163 ) )
V_4 -> V_5 . V_17 |= V_178 ;
else
V_4 -> V_5 . V_17 &= ~ V_178 ;
if ( V_94 -> V_279 )
V_4 -> V_5 . V_17 |= V_212 ;
else
V_4 -> V_5 . V_17 &= ~ V_212 ;
memcpy ( V_4 -> V_5 . V_174 , V_94 -> V_237 , V_31 ) ;
if ( V_6 -> type == V_9 ||
V_6 -> type == V_15 ) {
if ( V_6 -> V_94 . V_280 ) {
V_4 -> V_5 . V_13 |= V_39 ;
V_2 -> V_281 = V_4 ;
} else {
V_4 -> V_5 . V_13 &= ~ V_39 ;
V_2 -> V_281 = NULL ;
}
}
if ( V_6 -> type == V_11 ) {
if ( ! V_94 -> V_142 )
V_4 -> V_5 . V_13 |= V_19 ;
else
V_4 -> V_5 . V_13 &=
~ V_19 ;
}
if ( V_107 || memcmp ( & V_4 -> V_5 , & V_4 -> V_69 , sizeof( V_4 -> V_5 ) ) )
F_69 ( V_2 , V_4 ) ;
if ( V_266 & V_272 && V_94 -> V_142 ) {
if ( V_2 -> V_250 . V_252 == V_282 )
F_73 ( V_2 , false ) ;
F_90 ( V_2 ) ;
V_2 -> V_121 = 1 ;
}
if ( V_266 & V_283 ) {
V_38 = F_98 ( V_2 , V_6 ,
V_94 -> V_284 ) ;
if ( V_38 )
F_2 ( V_2 , L_65 ,
V_94 -> V_284 ? L_66 : L_67 ,
V_94 -> V_237 ) ;
}
if ( V_266 & V_285 && V_6 -> type == V_15 &&
V_2 -> V_281 ) {
if ( F_16 ( V_2 , V_6 ) )
F_2 ( V_2 , L_16 ) ;
}
F_85 ( & V_2 -> V_62 ) ;
}
void F_99 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_100 ( V_2 , & V_2 -> V_286 . V_287 , false ) ;
F_37 ( V_2 , V_2 -> V_118 , false ) ;
F_54 (priv, ctx)
if ( memcmp ( & V_4 -> V_5 , & V_4 -> V_69 , sizeof( V_4 -> V_5 ) ) )
F_69 ( V_2 , V_4 ) ;
F_46 ( V_2 ) ;
}
