void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
const struct V_5 * V_6 ;
memset ( & V_4 -> V_7 , 0 , sizeof( V_4 -> V_7 ) ) ;
if ( ! V_4 -> V_8 ) {
V_4 -> V_7 . V_9 = V_4 -> V_10 ;
} else
switch ( V_4 -> V_8 -> type ) {
case V_11 :
V_4 -> V_7 . V_9 = V_4 -> V_12 ;
break;
case V_13 :
V_4 -> V_7 . V_9 = V_4 -> V_14 ;
V_4 -> V_7 . V_15 = V_16 ;
break;
case V_17 :
V_4 -> V_7 . V_9 = V_4 -> V_18 ;
V_4 -> V_7 . V_19 = V_20 ;
V_4 -> V_7 . V_15 = V_21 |
V_16 ;
break;
case V_22 :
V_4 -> V_7 . V_9 = V_23 ;
break;
default:
F_2 ( V_2 , L_1 ,
V_4 -> V_8 -> type ) ;
break;
}
#if 0
if (!hw_to_local(priv->hw)->short_preamble)
ctx->staging.flags &= ~RXON_FLG_SHORT_PREAMBLE_MSK;
else
ctx->staging.flags |= RXON_FLG_SHORT_PREAMBLE_MSK;
#endif
V_6 = F_3 ( V_2 , V_2 -> V_24 ,
F_4 ( V_4 -> V_25 . V_26 ) ) ;
if ( ! V_6 )
V_6 = & V_2 -> V_27 [ 0 ] ;
V_4 -> V_7 . V_26 = F_5 ( V_6 -> V_26 ) ;
V_2 -> V_24 = V_6 -> V_24 ;
F_6 ( V_2 , V_4 , V_2 -> V_24 , V_4 -> V_8 ) ;
V_4 -> V_7 . V_19 &= ~ ( V_28 |
V_29 ) ;
if ( V_4 -> V_8 )
memcpy ( V_4 -> V_7 . V_30 , V_4 -> V_8 -> V_31 , V_32 ) ;
V_4 -> V_7 . V_33 = 0xff ;
V_4 -> V_7 . V_34 = 0xff ;
V_4 -> V_7 . V_35 = 0xff ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_36 * V_37 )
{
T_1 V_38 = V_37 -> V_15 ;
int V_39 ;
V_37 -> V_15 &= ~ V_40 ;
V_39 = F_8 ( V_2 , V_4 -> V_41 ,
V_42 , sizeof( * V_37 ) , V_37 ) ;
V_37 -> V_15 = V_38 ;
if ( V_39 )
F_9 ( V_2 ,
L_2 , V_39 ) ;
return V_39 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_36 * V_37 )
{
struct V_43 V_44 ;
T_1 V_38 = V_37 -> V_15 ;
T_2 V_45 = V_37 -> V_9 ;
int V_39 ;
static const T_2 V_46 [] = {
V_47
} ;
F_11 ( & V_2 -> V_48 , & V_44 ,
V_46 , F_12 ( V_46 ) ,
NULL , NULL ) ;
V_37 -> V_15 &= ~ V_40 ;
V_37 -> V_9 = V_49 ;
V_39 = F_8 ( V_2 , V_4 -> V_41 ,
V_42 , sizeof( * V_37 ) , V_37 ) ;
V_37 -> V_15 = V_38 ;
V_37 -> V_9 = V_45 ;
if ( V_39 ) {
F_2 ( V_2 , L_3 , V_39 ) ;
F_13 ( & V_2 -> V_48 , & V_44 ) ;
} else {
V_39 = F_14 ( & V_2 -> V_48 ,
& V_44 , V_50 ) ;
if ( V_39 )
F_2 ( V_2 , L_4 ) ;
}
return V_39 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_36 * V_37 )
{
T_1 V_38 = V_37 -> V_15 ;
int V_39 ;
V_37 -> V_15 &= ~ V_40 ;
V_39 = F_8 ( V_2 , V_4 -> V_41 , V_42 ,
sizeof( * V_37 ) , V_37 ) ;
V_37 -> V_15 = V_38 ;
return V_39 ;
}
void F_16 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_39 ;
if ( ! V_4 -> V_51 )
return;
V_4 -> V_52 . V_53 . V_54 = 0 ;
if ( V_4 -> V_52 . V_55 )
V_4 -> V_52 . V_53 . V_54 |=
V_56 ;
if ( V_4 -> V_57 . V_58 )
V_4 -> V_52 . V_53 . V_54 |= V_59 ;
F_17 ( V_2 , L_5 ,
V_4 -> V_52 . V_55 ,
V_4 -> V_52 . V_53 . V_54 ) ;
V_39 = F_8 ( V_2 , V_4 -> V_60 , V_42 ,
sizeof( struct V_61 ) ,
& V_4 -> V_52 . V_53 ) ;
if ( V_39 )
F_9 ( V_2 , L_6 ) ;
}
int F_18 ( struct V_1 * V_2 ,
struct V_62 * V_8 )
{
F_19 ( & V_2 -> V_63 ) ;
F_20 ( V_2 -> V_64 ) ;
V_2 -> V_64 = F_21 ( V_2 -> V_65 , V_8 ) ;
if ( ! V_2 -> V_64 )
return - V_66 ;
return F_22 ( V_2 ) ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_39 = 0 ;
struct V_67 V_68 ;
const struct V_36 * V_69 = & V_4 -> V_7 ;
const struct V_36 * V_70 = & V_4 -> V_25 ;
if ( ( V_69 -> V_19 == V_70 -> V_19 ) &&
( V_69 -> V_15 == V_70 -> V_15 ) &&
( V_69 -> V_71 == V_70 -> V_71 ) &&
( V_69 -> V_33 ==
V_70 -> V_33 ) &&
( V_69 -> V_34 ==
V_70 -> V_34 ) &&
( V_69 -> V_35 ==
V_70 -> V_35 ) &&
( V_69 -> V_72 == V_70 -> V_72 ) &&
( V_69 -> V_73 == V_70 -> V_73 ) &&
( V_69 -> V_74 == V_70 -> V_74 ) ) {
F_17 ( V_2 , L_7 ) ;
return 0 ;
}
V_68 . V_19 = V_4 -> V_7 . V_19 ;
V_68 . V_15 = V_4 -> V_7 . V_15 ;
V_68 . V_74 = V_4 -> V_7 . V_74 ;
V_68 . V_71 = V_4 -> V_7 . V_71 ;
V_68 . V_75 = 0 ;
V_68 . V_76 = 0 ;
V_68 . V_77 = 0 ;
V_68 . V_33 =
V_4 -> V_7 . V_33 ;
V_68 . V_34 =
V_4 -> V_7 . V_34 ;
V_68 . V_78 = V_4 -> V_7 . V_73 ;
V_68 . V_35 =
V_4 -> V_7 . V_35 ;
V_68 . V_72 = V_4 -> V_7 . V_72 ;
V_39 = F_8 ( V_2 , V_4 -> V_79 ,
V_80 , sizeof( V_68 ) , & V_68 ) ;
return V_39 ;
}
static T_3 F_24 ( T_3 V_81 , T_3 V_82 )
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
static int F_25 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_4 V_86 ;
T_5 V_87 , V_88 ;
struct V_89 * V_90 = NULL ;
T_3 V_91 ;
struct V_62 * V_8 = V_4 -> V_8 ;
V_90 = & V_2 -> V_65 -> V_90 ;
F_19 ( & V_2 -> V_63 ) ;
memset ( & V_4 -> V_92 , 0 , sizeof( struct V_93 ) ) ;
V_4 -> V_92 . V_94 = F_26 ( V_2 -> V_94 ) ;
V_4 -> V_92 . V_95 = F_5 ( V_90 -> V_95 ) ;
V_91 = V_8 ? V_8 -> V_96 . V_91 : 0 ;
V_4 -> V_92 . V_97 = 0 ;
if ( V_4 -> V_98 == V_99 &&
( ! V_4 -> V_8 || V_4 -> V_8 -> type != V_13 ) &&
F_27 ( V_2 , V_100 ) &&
V_2 -> V_101 [ V_100 ] . V_8 &&
V_2 -> V_101 [ V_100 ] . V_8 -> V_96 . V_91 ) {
V_4 -> V_92 . V_102 =
V_2 -> V_101 [ V_100 ] . V_92 . V_102 ;
V_91 = F_4 ( V_4 -> V_92 . V_102 ) ;
} else if ( V_4 -> V_98 == V_100 &&
F_27 ( V_2 , V_99 ) &&
V_2 -> V_101 [ V_99 ] . V_8 &&
V_2 -> V_101 [ V_99 ] . V_8 -> V_96 . V_91 &&
( ! F_28 ( V_4 ) || ! V_4 -> V_8 ||
! V_4 -> V_8 -> V_96 . V_91 ) ) {
V_4 -> V_92 . V_102 =
V_2 -> V_101 [ V_99 ] . V_92 . V_102 ;
V_91 = F_4 ( V_4 -> V_92 . V_102 ) ;
} else {
V_91 = F_24 ( V_91 ,
V_103 * V_104 ) ;
V_4 -> V_92 . V_102 = F_5 ( V_91 ) ;
}
V_4 -> V_91 = V_91 ;
V_86 = V_2 -> V_94 ;
V_87 = V_91 * V_104 ;
V_88 = F_29 ( V_86 , V_87 ) ;
V_4 -> V_92 . V_105 = F_30 ( V_87 - V_88 ) ;
V_4 -> V_92 . V_106 = V_8 ? ( V_8 -> V_96 . V_106 ? : 1 ) : 1 ;
F_31 ( V_2 ,
L_8 ,
F_4 ( V_4 -> V_92 . V_102 ) ,
F_32 ( V_4 -> V_92 . V_105 ) ,
F_4 ( V_4 -> V_92 . V_97 ) ) ;
return F_8 ( V_2 , V_4 -> V_107 ,
V_42 , sizeof( V_4 -> V_92 ) , & V_4 -> V_92 ) ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_39 ;
struct V_36 * V_25 = ( void * ) & V_4 -> V_25 ;
if ( V_4 -> V_98 == V_100 ) {
V_39 = F_7 ( V_2 , V_4 , & V_4 -> V_7 ) ;
} else {
V_39 = F_10 ( V_2 , V_4 , & V_4 -> V_7 ) ;
if ( V_39 )
return V_39 ;
if ( V_4 -> V_8 ) {
V_39 = F_25 ( V_2 , V_4 ) ;
if ( V_39 ) {
F_2 ( V_2 , L_9 , V_39 ) ;
return V_39 ;
}
V_39 = F_15 ( V_2 , V_4 , & V_4 -> V_7 ) ;
}
}
if ( V_39 )
return V_39 ;
F_34 ( V_2 , V_4 ) ;
F_35 ( V_2 , V_4 ) ;
F_36 ( V_2 , V_4 ) ;
V_39 = F_37 ( V_2 , V_4 ) ;
if ( V_39 ) {
F_2 ( V_2 , L_10 , V_39 ) ;
return V_39 ;
}
memcpy ( V_25 , & V_4 -> V_7 , sizeof( * V_25 ) ) ;
return 0 ;
}
static int F_38 ( struct V_1 * V_2 , T_6 V_108 , bool V_109 )
{
int V_39 ;
T_6 V_110 ;
bool V_111 ;
struct V_3 * V_4 = & V_2 -> V_101 [ V_100 ] ;
if ( V_2 -> V_112 & V_113 )
return 0 ;
F_19 ( & V_2 -> V_63 ) ;
if ( V_2 -> V_114 == V_108 && ! V_109 )
return 0 ;
if ( V_108 < V_115 ) {
F_39 ( V_2 ,
L_11 ,
V_108 ,
V_115 ) ;
return - V_116 ;
}
if ( V_108 > V_2 -> V_117 ) {
F_39 ( V_2 ,
L_12 ,
V_108 , V_2 -> V_117 ) ;
return - V_116 ;
}
if ( ! F_40 ( V_2 ) )
return - V_118 ;
V_2 -> V_119 = V_108 ;
V_111 = F_41 ( V_120 , & V_2 -> V_121 ) ||
memcmp ( & V_4 -> V_25 , & V_4 -> V_7 , sizeof( V_4 -> V_7 ) ) ;
if ( V_111 && ! V_109 ) {
F_17 ( V_2 , L_13 ) ;
return 0 ;
}
V_110 = V_2 -> V_114 ;
V_2 -> V_114 = V_108 ;
V_39 = F_42 ( V_2 ) ;
if ( V_39 ) {
V_2 -> V_114 = V_110 ;
V_2 -> V_119 = V_110 ;
}
return V_39 ;
}
static int F_43 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_39 ;
struct V_36 * V_25 = ( void * ) & V_4 -> V_25 ;
if ( V_4 -> V_98 == V_100 ) {
V_39 = F_25 ( V_2 , V_4 ) ;
if ( V_39 ) {
F_2 ( V_2 , L_9 , V_39 ) ;
return V_39 ;
}
}
F_16 ( V_2 , V_4 ) ;
if ( V_4 -> V_8 && ( V_4 -> V_8 -> type == V_11 ) ) {
V_39 = F_18 ( V_2 , V_4 -> V_8 ) ;
if ( V_39 ) {
F_2 ( V_2 ,
L_14 ,
V_39 ) ;
return V_39 ;
}
}
V_2 -> V_122 = 0 ;
V_39 = F_8 ( V_2 , V_4 -> V_41 , V_42 ,
sizeof( struct V_36 ) , & V_4 -> V_7 ) ;
if ( V_39 ) {
F_2 ( V_2 , L_15 , V_39 ) ;
return V_39 ;
}
memcpy ( V_25 , & V_4 -> V_7 , sizeof( * V_25 ) ) ;
if ( V_4 -> V_8 && ( V_4 -> V_8 -> type == V_17 ) )
if ( F_18 ( V_2 , V_4 -> V_8 ) )
F_2 ( V_2 , L_16 ) ;
F_44 ( V_2 ) ;
V_39 = F_38 ( V_2 , V_2 -> V_119 , true ) ;
if ( V_39 ) {
F_2 ( V_2 , L_17 , V_39 ) ;
return V_39 ;
}
if ( V_4 -> V_8 && V_4 -> V_8 -> type == V_13 &&
V_2 -> V_123 -> V_124 && V_2 -> V_123 -> V_124 -> V_125 )
F_45 ( V_4 -> V_8 ,
V_2 -> V_123 -> V_124 -> V_125 ) ;
return 0 ;
}
int F_46 ( struct V_1 * V_2 )
{
struct V_126 V_127 ;
struct V_3 * V_128 , * V_129 ;
int V_130 = 300 , V_131 = 0 ;
int V_39 ;
if ( V_2 -> V_132 == F_47 ( V_100 ) )
return 0 ;
F_48 ( V_133 != 2 ) ;
F_19 ( & V_2 -> V_63 ) ;
V_128 = & V_2 -> V_101 [ V_100 ] ;
V_129 = & V_2 -> V_101 [ V_99 ] ;
if ( ! V_129 -> V_51 )
return 0 ;
memset ( & V_127 , 0 , sizeof( V_127 ) ) ;
V_127 . V_134 = 2 ;
V_127 . V_135 [ 0 ] . type = 0 ;
V_127 . V_135 [ 1 ] . type = 1 ;
if ( V_2 -> V_136 ) {
V_131 = V_137 ;
V_130 = 3000 ;
} else if ( V_128 -> V_8 && V_129 -> V_8 ) {
int V_138 = V_129 -> V_91 ;
int V_139 = V_129 -> V_8 -> V_96 . V_106 ? : 1 ;
V_127 . V_19 |= F_5 ( V_140 ) ;
if ( V_129 -> V_8 -> type == V_11 &&
V_138 &&
V_138 != V_128 -> V_91 ) {
F_2 ( V_2 ,
L_18 ,
V_128 -> V_91 , V_129 -> V_91 ) ;
} else
V_138 = F_49 ( int , V_138 ,
V_128 -> V_91 ) ;
if ( ! V_138 )
V_138 = V_85 ;
V_130 = V_138 / 2 ;
V_131 = V_138 - V_130 ;
if ( F_41 ( V_141 , & V_2 -> V_121 ) ||
( ! V_128 -> V_8 -> V_96 . V_142 &&
! V_128 -> V_8 -> V_96 . V_143 ) ) {
V_130 = V_139 * V_138 * 3 - V_137 ;
V_131 = V_137 ;
} else if ( ! V_129 -> V_8 -> V_96 . V_142 &&
! V_129 -> V_8 -> V_96 . V_143 ) {
V_131 = V_139 * V_138 * 3 - V_137 ;
V_130 = V_137 ;
}
} else if ( V_129 -> V_8 ) {
V_130 = 0 ;
V_131 = F_49 ( int , 1 , V_129 -> V_8 -> V_96 . V_106 ) *
V_129 -> V_91 ;
V_131 = F_49 ( int , V_85 , V_131 ) ;
if ( F_41 ( V_141 , & V_2 -> V_121 ) ) {
V_130 = V_131 * 3 - V_137 ;
V_131 = V_137 ;
}
}
V_127 . V_135 [ 0 ] . V_144 = F_5 ( V_130 ) ;
V_127 . V_135 [ 1 ] . V_144 = F_5 ( V_131 ) ;
V_39 = F_8 ( V_2 , V_145 , V_42 ,
sizeof( V_127 ) , & V_127 ) ;
if ( V_39 )
F_2 ( V_2 , L_19 , V_39 ) ;
return V_39 ;
}
static void F_50 ( struct V_1 * V_2 ,
struct V_146 * V_147 ,
struct V_3 * V_4 )
{
struct V_36 * V_148 = & V_4 -> V_7 ;
if ( ! V_4 -> V_57 . V_58 ) {
V_148 -> V_19 &= ~ ( V_149 |
V_150 |
V_151 |
V_152 ) ;
return;
}
V_148 -> V_19 |= F_30 ( V_4 -> V_57 . V_153 <<
V_154 ) ;
V_148 -> V_19 &= ~ ( V_149 |
V_150 ) ;
if ( F_51 ( V_2 , V_4 , NULL ) ) {
if ( V_4 -> V_57 . V_153 ==
V_155 ) {
V_148 -> V_19 |= V_29 ;
switch ( V_4 -> V_57 . V_156 ) {
case V_157 :
V_148 -> V_19 &=
~ V_150 ;
break;
case V_158 :
V_148 -> V_19 |=
V_150 ;
break;
}
} else {
switch ( V_4 -> V_57 . V_156 ) {
case V_157 :
V_148 -> V_19 &=
~ ( V_150 ) ;
V_148 -> V_19 |= V_28 ;
break;
case V_158 :
V_148 -> V_19 |= V_150 ;
V_148 -> V_19 |= V_28 ;
break;
case V_159 :
default:
F_2 ( V_2 ,
L_20 ) ;
break;
}
}
} else {
V_148 -> V_19 |= V_160 ;
}
F_52 ( V_2 , V_4 ) ;
F_31 ( V_2 , L_21
L_22 ,
F_32 ( V_148 -> V_19 ) , V_4 -> V_57 . V_153 ,
V_4 -> V_57 . V_156 ) ;
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
enum V_163 V_24 = V_162 -> V_24 ;
T_3 V_26 = V_162 -> V_164 ;
if ( ( F_4 ( V_4 -> V_7 . V_26 ) == V_26 ) &&
( V_2 -> V_24 == V_24 ) )
return;
V_4 -> V_7 . V_26 = F_5 ( V_26 ) ;
if ( V_24 == V_165 )
V_4 -> V_7 . V_19 &= ~ V_166 ;
else
V_4 -> V_7 . V_19 |= V_166 ;
V_2 -> V_24 = V_24 ;
F_17 ( V_2 , L_23 , V_26 , V_24 ) ;
}
void F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
enum V_163 V_24 ,
struct V_62 * V_8 )
{
if ( V_24 == V_165 ) {
V_4 -> V_7 . V_19 &=
~ ( V_166 | V_167
| V_168 ) ;
V_4 -> V_7 . V_19 |= V_169 ;
} else {
if ( V_8 && V_8 -> V_96 . V_170 )
V_4 -> V_7 . V_19 |= V_169 ;
else
V_4 -> V_7 . V_19 &= ~ V_169 ;
V_4 -> V_7 . V_19 |= V_166 ;
V_4 -> V_7 . V_19 |= V_167 ;
V_4 -> V_7 . V_19 &= ~ V_168 ;
}
}
static void F_56 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_171 )
{
struct V_36 * V_148 = & V_4 -> V_7 ;
if ( V_171 )
V_148 -> V_15 &= ~ V_172 ;
else
V_148 -> V_15 |= V_172 ;
}
static int F_57 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_36 * V_148 = & V_4 -> V_7 ;
T_7 V_173 = 0 ;
if ( V_148 -> V_19 & V_166 ) {
if ( V_148 -> V_19 & V_174 ) {
F_39 ( V_2 , L_24 ) ;
V_173 |= F_47 ( 0 ) ;
}
if ( V_148 -> V_19 & V_175 ) {
F_39 ( V_2 , L_25 ) ;
V_173 |= F_47 ( 1 ) ;
}
} else {
if ( ! ( V_148 -> V_19 & V_169 ) ) {
F_39 ( V_2 , L_26 ) ;
V_173 |= F_47 ( 2 ) ;
}
if ( V_148 -> V_19 & V_168 ) {
F_39 ( V_2 , L_27 ) ;
V_173 |= F_47 ( 3 ) ;
}
}
if ( ( V_148 -> V_30 [ 0 ] | V_148 -> V_176 [ 0 ] ) & 0x1 ) {
F_39 ( V_2 , L_28 ) ;
V_173 |= F_47 ( 4 ) ;
}
if ( ( V_148 -> V_74 & V_177 ) == 0 &&
( V_148 -> V_71 & V_178 ) == 0 ) {
F_39 ( V_2 , L_29 ) ;
V_173 |= F_47 ( 5 ) ;
}
if ( F_4 ( V_148 -> V_179 ) > 2007 ) {
F_39 ( V_2 , L_30 ) ;
V_173 |= F_47 ( 6 ) ;
}
if ( ( V_148 -> V_19 & ( V_168 | V_169 ) )
== ( V_168 | V_169 ) ) {
F_39 ( V_2 , L_31 ) ;
V_173 |= F_47 ( 7 ) ;
}
if ( ( V_148 -> V_19 & ( V_168 | V_167 ) )
== ( V_168 | V_167 ) ) {
F_39 ( V_2 , L_32 ) ;
V_173 |= F_47 ( 8 ) ;
}
if ( ( V_148 -> V_19 & ( V_167 |
V_180 ) ) ==
V_180 ) {
F_39 ( V_2 , L_33 ) ;
V_173 |= F_47 ( 9 ) ;
}
if ( V_148 -> V_26 == 0 ) {
F_39 ( V_2 , L_34 ) ;
V_173 |= F_47 ( 10 ) ;
}
F_58 ( V_173 , L_35 ,
V_173 , F_4 ( V_148 -> V_26 ) ) ;
return V_173 ? - V_116 : 0 ;
}
int F_59 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
const struct V_36 * V_7 = & V_4 -> V_7 ;
const struct V_36 * V_25 = & V_4 -> V_25 ;
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
F_60 ( ! F_28 ( V_4 ) ) ;
F_60 ( ! F_62 ( V_7 -> V_176 , V_25 -> V_176 ) ) ;
F_60 ( ! F_62 ( V_7 -> V_30 , V_25 -> V_30 ) ) ;
F_60 ( ! F_62 ( V_7 -> V_181 ,
V_25 -> V_181 ) ) ;
F_61 ( V_7 -> V_9 , V_25 -> V_9 ) ;
F_61 ( V_7 -> V_26 , V_25 -> V_26 ) ;
F_61 ( V_7 -> V_182 , V_25 -> V_182 ) ;
F_61 ( V_7 -> V_33 ,
V_25 -> V_33 ) ;
F_61 ( V_7 -> V_34 ,
V_25 -> V_34 ) ;
F_61 ( V_7 -> V_35 ,
V_25 -> V_35 ) ;
F_61 ( V_7 -> V_179 , V_25 -> V_179 ) ;
F_61 ( V_7 -> V_19 & V_166 ,
V_25 -> V_19 & V_166 ) ;
F_61 ( V_7 -> V_15 & V_40 ,
V_25 -> V_15 & V_40 ) ;
#undef F_60
#undef F_61
return 0 ;
}
void F_63 ( struct V_1 * V_2 ,
enum V_183 V_98 )
{
struct V_3 * V_4 = & V_2 -> V_101 [ V_98 ] ;
struct V_36 * V_148 = & V_4 -> V_7 ;
F_64 ( V_2 , L_36 ) ;
F_65 ( V_2 , V_184 , ( T_2 * ) V_148 , sizeof( * V_148 ) ) ;
F_64 ( V_2 , L_37 ,
F_4 ( V_148 -> V_26 ) ) ;
F_64 ( V_2 , L_38 ,
F_32 ( V_148 -> V_19 ) ) ;
F_64 ( V_2 , L_39 ,
F_32 ( V_148 -> V_15 ) ) ;
F_64 ( V_2 , L_40 , V_148 -> V_9 ) ;
F_64 ( V_2 , L_41 ,
V_148 -> V_74 ) ;
F_64 ( V_2 , L_42 ,
V_148 -> V_71 ) ;
F_64 ( V_2 , L_43 , V_148 -> V_30 ) ;
F_64 ( V_2 , L_44 , V_148 -> V_176 ) ;
F_64 ( V_2 , L_45 ,
F_4 ( V_148 -> V_179 ) ) ;
}
static void F_66 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_185 = 100 ;
int V_186 = 100 ;
T_2 V_187 = 0 ;
T_2 V_188 = 0 ;
if ( V_4 -> V_8 ) {
struct V_189 * V_190 ;
unsigned long V_191 = V_4 -> V_8 -> V_96 . V_192 ;
int V_193 ;
V_190 = V_2 -> V_65 -> V_194 -> V_195 [ V_2 -> V_65 -> V_90 . V_26 -> V_24 ] ;
F_67 (i, &basic, BITS_PER_LONG) {
int V_65 = V_190 -> V_196 [ V_193 ] . V_164 ;
if ( V_65 >= V_197 ) {
V_188 |= F_47 ( V_65 - V_197 ) ;
if ( V_185 > V_65 )
V_185 = V_65 ;
} else {
F_48 ( V_198 != 0 ) ;
V_187 |= F_47 ( V_65 ) ;
if ( V_186 > V_65 )
V_186 = V_65 ;
}
}
}
if ( V_199 < V_185 )
V_188 |= V_200 >> V_197 ;
if ( V_201 < V_185 )
V_188 |= V_202 >> V_197 ;
V_188 |= V_177 >> V_197 ;
if ( V_203 < V_185 )
V_188 |= V_204 >> V_198 ;
if ( V_205 < V_185 )
V_188 |= V_206 >> V_198 ;
if ( V_207 < V_185 )
V_188 |= V_208 >> V_198 ;
V_187 |= V_178 >> V_198 ;
F_68 ( V_2 , L_46 ,
V_187 , V_188 ) ;
V_4 -> V_7 . V_71 = V_187 ;
V_4 -> V_7 . V_74 = V_188 ;
}
int F_69 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_36 * V_25 = ( void * ) & V_4 -> V_25 ;
bool V_209 = ! ! ( V_4 -> V_7 . V_15 & V_40 ) ;
int V_39 ;
F_19 ( & V_2 -> V_63 ) ;
if ( ! F_70 ( V_2 ) )
return - V_210 ;
F_48 ( V_133 != 2 ) ;
if ( ! V_4 -> V_51 )
return 0 ;
V_4 -> V_7 . V_19 |= V_211 ;
F_66 ( V_2 , V_4 ) ;
if ( ! V_2 -> V_212 . V_213 )
V_4 -> V_7 . V_19 |= V_214 ;
if ( ( V_4 -> V_8 && V_4 -> V_8 -> V_96 . V_170 ) ||
! ( V_4 -> V_7 . V_19 & V_166 ) )
V_4 -> V_7 . V_19 |= V_169 ;
else
V_4 -> V_7 . V_19 &= ~ V_169 ;
F_63 ( V_2 , V_4 -> V_98 ) ;
V_39 = F_57 ( V_2 , V_4 ) ;
if ( V_39 ) {
F_2 ( V_2 , L_47 ) ;
return - V_116 ;
}
if ( F_41 ( V_215 , & V_2 -> V_121 ) &&
( V_2 -> V_216 != V_4 -> V_7 . V_26 ) ) {
F_71 ( V_2 , L_48 ,
F_4 ( V_2 -> V_216 ) ) ;
F_72 ( V_2 , false ) ;
}
if ( ! F_59 ( V_2 , V_4 ) ) {
V_39 = F_23 ( V_2 , V_4 ) ;
if ( V_39 ) {
F_2 ( V_2 , L_49 , V_39 ) ;
return V_39 ;
}
memcpy ( V_25 , & V_4 -> V_7 , sizeof( * V_25 ) ) ;
F_38 ( V_2 , V_2 -> V_119 , false ) ;
F_73 ( V_2 , true ) ;
return 0 ;
}
F_56 ( V_2 , V_4 , ! V_217 . V_218 ) ;
F_17 ( V_2 ,
L_50
L_51
L_52
L_53 ,
( V_209 ? L_54 : L_55 ) ,
F_4 ( V_4 -> V_7 . V_26 ) ,
V_4 -> V_7 . V_176 ) ;
V_39 = F_33 ( V_2 , V_4 ) ;
if ( V_39 )
return V_39 ;
V_39 = F_46 ( V_2 ) ;
if ( V_39 )
return V_39 ;
if ( V_209 )
return F_43 ( V_2 , V_4 ) ;
return 0 ;
}
void F_74 ( struct V_89 * V_90 ,
struct V_3 * V_4 )
{
if ( F_75 ( V_90 ) ) {
V_4 -> V_57 . V_156 =
V_158 ;
V_4 -> V_57 . V_219 = true ;
} else if ( F_76 ( V_90 ) ) {
V_4 -> V_57 . V_156 =
V_157 ;
V_4 -> V_57 . V_219 = true ;
} else {
V_4 -> V_57 . V_156 =
V_159 ;
V_4 -> V_57 . V_219 = false ;
}
}
int F_77 ( struct V_220 * V_65 , T_7 V_221 )
{
struct V_1 * V_2 = F_78 ( V_65 ) ;
struct V_3 * V_4 ;
struct V_89 * V_90 = & V_65 -> V_90 ;
struct V_161 * V_26 = V_90 -> V_26 ;
const struct V_5 * V_6 ;
int V_39 = 0 ;
F_79 ( V_2 , L_56 , V_221 ) ;
F_80 ( & V_2 -> V_63 ) ;
if ( F_81 ( F_41 ( V_120 , & V_2 -> V_121 ) ) ) {
F_79 ( V_2 , L_57 ) ;
goto V_222;
}
if ( ! F_82 ( V_2 ) ) {
F_79 ( V_2 , L_58 ) ;
goto V_222;
}
if ( V_221 & ( V_223 |
V_224 ) ) {
V_2 -> V_225 . V_226 = V_90 -> V_125 ;
F_54 (priv, ctx)
F_52 ( V_2 , V_4 ) ;
}
if ( V_221 & V_224 ) {
V_6 = F_3 ( V_2 , V_26 -> V_24 ,
V_26 -> V_164 ) ;
if ( ! F_83 ( V_6 ) ) {
F_79 ( V_2 , L_59 ) ;
V_39 = - V_116 ;
goto V_222;
}
F_54 (priv, ctx) {
if ( V_4 -> V_57 . V_58 != F_84 ( V_90 ) )
V_4 -> V_57 . V_58 = F_84 ( V_90 ) ;
if ( V_4 -> V_57 . V_58 ) {
if ( ! V_4 -> V_57 . V_219 ||
! F_28 ( V_4 ) )
F_74 ( V_90 , V_4 ) ;
} else
V_4 -> V_57 . V_219 = false ;
V_4 -> V_57 . V_153 = V_227 ;
if ( F_4 ( V_4 -> V_7 . V_26 ) !=
V_26 -> V_164 )
V_4 -> V_7 . V_19 = 0 ;
F_55 ( V_2 , V_26 , V_4 ) ;
F_53 ( V_2 , & V_2 -> V_225 ) ;
F_6 ( V_2 , V_4 , V_26 -> V_24 ,
V_4 -> V_8 ) ;
}
F_85 ( V_2 ) ;
}
if ( V_221 & ( V_228 |
V_229 ) ) {
V_39 = F_73 ( V_2 , false ) ;
if ( V_39 )
F_79 ( V_2 , L_60 ) ;
}
if ( V_221 & V_230 ) {
F_79 ( V_2 , L_61 ,
V_2 -> V_114 , V_90 -> V_231 ) ;
F_38 ( V_2 , V_90 -> V_231 , false ) ;
}
F_54 (priv, ctx) {
if ( ! memcmp ( & V_4 -> V_7 , & V_4 -> V_25 , sizeof( V_4 -> V_7 ) ) )
continue;
F_69 ( V_2 , V_4 ) ;
}
V_222:
F_86 ( & V_2 -> V_63 ) ;
F_79 ( V_2 , L_62 ) ;
return V_39 ;
}
void F_87 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_232 * V_96 )
{
struct V_62 * V_8 = V_4 -> V_8 ;
struct V_3 * V_233 ;
struct V_234 * V_235 ;
struct V_146 * V_147 = & V_2 -> V_225 ;
struct V_236 * V_237 ;
bool V_238 ;
F_19 ( & V_2 -> V_63 ) ;
switch ( V_8 -> type ) {
case V_13 :
F_88 () ;
V_235 = F_89 ( V_8 , V_96 -> V_239 ) ;
if ( ! V_235 ) {
V_238 = false ;
F_90 () ;
break;
}
V_237 = & V_235 -> V_237 ;
V_238 = true ;
if ( V_237 -> V_240 . V_241 [ 1 ] == 0 &&
V_237 -> V_240 . V_241 [ 2 ] == 0 ) {
V_238 = false ;
} else if ( ! ( V_237 -> V_240 . V_242 &
V_243 ) ) {
V_238 = false ;
} else if ( V_237 -> V_240 . V_242 &
V_244 ) {
int V_245 ;
V_245 = ( V_237 -> V_240 . V_242 &
V_246 ) ;
V_245 >>=
V_247 ;
V_245 += 1 ;
if ( V_245 <= 1 )
V_238 = false ;
}
F_90 () ;
break;
case V_17 :
V_238 = false ;
break;
default:
V_238 = true ;
break;
}
V_4 -> V_248 = V_238 ;
if ( ! V_238 ) {
F_54 (priv, tmp) {
if ( ! V_233 -> V_8 )
continue;
if ( V_233 -> V_248 ) {
V_238 = true ;
break;
}
}
}
V_147 -> V_249 = ! V_238 ;
}
void F_91 ( struct V_1 * V_2 )
{
struct V_250 * V_251 = & V_2 -> V_252 ;
int V_39 ;
if ( ! ( V_2 -> V_112 & V_253 ) )
return;
if ( ( V_251 -> V_254 == V_255 ) &&
F_92 ( V_2 ) ) {
struct V_256 V_127 ;
V_251 -> V_257 = 0 ;
V_251 -> V_258 = 0 ;
V_251 -> V_259 = 0 ;
V_251 -> V_260 = 0 ;
V_251 -> V_261 = 0 ;
V_251 -> V_262 = 0 ;
V_251 -> V_263 = 0 ;
memset ( & V_127 , 0 , sizeof( V_127 ) ) ;
F_93 ( & V_127 . V_264 ,
V_2 -> V_265 ) ;
V_39 = F_8 ( V_2 ,
V_266 ,
V_42 , sizeof( V_127 ) , & V_127 ) ;
if ( V_39 )
F_2 ( V_2 ,
L_63 ) ;
V_251 -> V_254 = V_267 ;
F_94 ( V_2 , L_64 ) ;
}
}
void F_95 ( struct V_220 * V_65 ,
struct V_62 * V_8 ,
struct V_232 * V_96 ,
T_7 V_268 )
{
struct V_1 * V_2 = F_78 ( V_65 ) ;
struct V_3 * V_4 = F_96 ( V_8 ) ;
int V_39 ;
bool V_109 = false ;
F_80 ( & V_2 -> V_63 ) ;
if ( F_81 ( ! F_82 ( V_2 ) ) ) {
F_79 ( V_2 , L_58 ) ;
F_86 ( & V_2 -> V_63 ) ;
return;
}
if ( F_81 ( ! V_4 -> V_8 ) ) {
F_79 ( V_2 , L_65 ) ;
F_86 ( & V_2 -> V_63 ) ;
return;
}
if ( V_268 & V_269 )
V_109 = true ;
if ( V_268 & V_270 ) {
V_4 -> V_52 . V_55 = V_96 -> V_271 ;
F_16 ( V_2 , V_4 ) ;
}
V_4 -> V_7 . V_179 = F_5 ( V_8 -> V_96 . V_272 ) ;
if ( V_8 -> V_96 . V_273 )
V_4 -> V_7 . V_19 |= V_20 ;
else
V_4 -> V_7 . V_19 &= ~ V_20 ;
if ( V_268 & V_274 ) {
if ( V_96 -> V_143 ) {
V_2 -> V_94 = V_96 -> V_275 ;
V_4 -> V_7 . V_15 |= V_40 ;
} else {
F_97 ( V_2 ) ;
V_4 -> V_7 . V_15 &= ~ V_40 ;
if ( V_4 -> V_98 == V_100 )
V_2 -> V_276 = false ;
}
F_98 ( V_2 ) ;
}
if ( V_4 -> V_57 . V_58 ) {
V_4 -> V_57 . V_153 = V_96 -> V_277 &
V_278 ;
V_4 -> V_57 . V_279 = ! ! ( V_96 -> V_277 &
V_280 ) ;
F_87 ( V_2 , V_4 , V_96 ) ;
F_53 ( V_2 , & V_2 -> V_225 ) ;
}
F_52 ( V_2 , V_4 ) ;
if ( V_96 -> V_281 && ( V_2 -> V_24 != V_165 ) )
V_4 -> V_7 . V_19 |= V_180 ;
else
V_4 -> V_7 . V_19 &= ~ V_180 ;
if ( V_96 -> V_281 )
V_4 -> V_7 . V_19 |= V_214 ;
else
V_4 -> V_7 . V_19 &= ~ V_214 ;
memcpy ( V_4 -> V_7 . V_176 , V_96 -> V_239 , V_32 ) ;
if ( V_8 -> type == V_11 ||
V_8 -> type == V_17 ) {
if ( V_8 -> V_96 . V_282 ) {
V_4 -> V_7 . V_15 |= V_40 ;
V_2 -> V_283 = V_4 ;
} else {
V_4 -> V_7 . V_15 &= ~ V_40 ;
V_2 -> V_283 = NULL ;
}
}
if ( V_8 -> type == V_13 ) {
if ( ! V_96 -> V_143 )
V_4 -> V_7 . V_15 |= V_21 ;
else
V_4 -> V_7 . V_15 &=
~ V_21 ;
}
if ( V_109 || memcmp ( & V_4 -> V_7 , & V_4 -> V_25 , sizeof( V_4 -> V_7 ) ) )
F_69 ( V_2 , V_4 ) ;
if ( V_268 & V_274 && V_96 -> V_143 ) {
if ( V_2 -> V_252 . V_254 == V_284 )
F_73 ( V_2 , false ) ;
F_91 ( V_2 ) ;
V_2 -> V_122 = 1 ;
}
if ( V_268 & V_285 ) {
V_39 = F_99 ( V_2 , V_8 ,
V_96 -> V_286 ) ;
if ( V_39 )
F_2 ( V_2 , L_66 ,
V_96 -> V_286 ? L_67 : L_68 ,
V_96 -> V_239 ) ;
}
if ( V_268 & V_287 && V_8 -> type == V_17 &&
V_2 -> V_283 ) {
if ( F_18 ( V_2 , V_8 ) )
F_2 ( V_2 , L_16 ) ;
}
F_86 ( & V_2 -> V_63 ) ;
}
void F_100 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_101 ( V_2 , & V_2 -> V_288 . V_289 , false ) ;
F_38 ( V_2 , V_2 -> V_119 , false ) ;
F_54 (priv, ctx)
if ( memcmp ( & V_4 -> V_7 , & V_4 -> V_25 , sizeof( V_4 -> V_7 ) ) )
F_69 ( V_2 , V_4 ) ;
F_46 ( V_2 ) ;
}
