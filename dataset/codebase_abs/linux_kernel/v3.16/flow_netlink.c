static void F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 , bool V_5 )
{
struct V_6 * V_7 = NULL ;
T_1 V_8 = F_2 ( V_3 , sizeof( long ) ) ;
T_1 V_9 = F_3 ( V_3 + V_4 , sizeof( long ) ) ;
if ( ! V_5 )
V_7 = & V_2 -> V_7 ;
else if ( V_2 -> V_10 )
V_7 = & V_2 -> V_10 -> V_7 ;
if ( ! V_7 )
return;
if ( V_7 -> V_8 == V_7 -> V_9 ) {
V_7 -> V_8 = V_8 ;
V_7 -> V_9 = V_9 ;
return;
}
if ( V_7 -> V_8 > V_8 )
V_7 -> V_8 = V_8 ;
if ( V_7 -> V_9 < V_9 )
V_7 -> V_9 = V_9 ;
}
static T_2 F_4 ( const struct V_6 * V_7 )
{
return V_7 -> V_9 - V_7 -> V_8 ;
}
static bool F_5 ( const struct V_1 * V_2 ,
T_3 V_11 , T_3 V_12 )
{
T_3 V_13 = 1 << V_14 ;
T_3 V_15 = V_11 ;
V_15 &= ~ ( ( 1 << V_16 )
| ( 1 << V_17 )
| ( 1 << V_18 )
| ( 1 << V_19 )
| ( 1 << V_20 )
| ( 1 << V_21 )
| ( 1 << V_22 )
| ( 1 << V_23 )
| ( 1 << V_24 )
| ( 1 << V_25 ) ) ;
V_15 |= ( ( 1 << V_26 )
| ( 1 << V_27 )
| ( 1 << V_28 ) ) ;
if ( V_2 -> V_29 -> V_30 . type == F_6 ( V_31 )
|| V_2 -> V_29 -> V_30 . type == F_6 ( V_32 ) ) {
V_13 |= 1 << V_24 ;
if ( V_2 -> V_10 && ( V_2 -> V_10 -> V_29 . V_30 . type == F_6 ( 0xffff ) ) )
V_15 |= 1 << V_24 ;
}
if ( V_2 -> V_29 -> V_30 . type == F_6 ( V_33 ) ) {
V_13 |= 1 << V_16 ;
if ( V_2 -> V_10 && ( V_2 -> V_10 -> V_29 . V_30 . type == F_6 ( 0xffff ) ) )
V_15 |= 1 << V_16 ;
if ( V_2 -> V_29 -> V_34 . V_35 != V_36 ) {
if ( V_2 -> V_29 -> V_34 . V_37 == V_38 ) {
V_13 |= 1 << V_20 ;
if ( V_2 -> V_10 && ( V_2 -> V_10 -> V_29 . V_34 . V_37 == 0xff ) )
V_15 |= 1 << V_20 ;
}
if ( V_2 -> V_29 -> V_34 . V_37 == V_39 ) {
V_13 |= 1 << V_21 ;
if ( V_2 -> V_10 && ( V_2 -> V_10 -> V_29 . V_34 . V_37 == 0xff ) )
V_15 |= 1 << V_21 ;
}
if ( V_2 -> V_29 -> V_34 . V_37 == V_40 ) {
V_13 |= 1 << V_18 ;
V_13 |= 1 << V_19 ;
if ( V_2 -> V_10 && ( V_2 -> V_10 -> V_29 . V_34 . V_37 == 0xff ) ) {
V_15 |= 1 << V_18 ;
V_15 |= 1 << V_19 ;
}
}
if ( V_2 -> V_29 -> V_34 . V_37 == V_41 ) {
V_13 |= 1 << V_22 ;
if ( V_2 -> V_10 && ( V_2 -> V_10 -> V_29 . V_34 . V_37 == 0xff ) )
V_15 |= 1 << V_22 ;
}
}
}
if ( V_2 -> V_29 -> V_30 . type == F_6 ( V_42 ) ) {
V_13 |= 1 << V_17 ;
if ( V_2 -> V_10 && ( V_2 -> V_10 -> V_29 . V_30 . type == F_6 ( 0xffff ) ) )
V_15 |= 1 << V_17 ;
if ( V_2 -> V_29 -> V_34 . V_35 != V_36 ) {
if ( V_2 -> V_29 -> V_34 . V_37 == V_38 ) {
V_13 |= 1 << V_20 ;
if ( V_2 -> V_10 && ( V_2 -> V_10 -> V_29 . V_34 . V_37 == 0xff ) )
V_15 |= 1 << V_20 ;
}
if ( V_2 -> V_29 -> V_34 . V_37 == V_39 ) {
V_13 |= 1 << V_21 ;
if ( V_2 -> V_10 && ( V_2 -> V_10 -> V_29 . V_34 . V_37 == 0xff ) )
V_15 |= 1 << V_21 ;
}
if ( V_2 -> V_29 -> V_34 . V_37 == V_40 ) {
V_13 |= 1 << V_18 ;
V_13 |= 1 << V_19 ;
if ( V_2 -> V_10 && ( V_2 -> V_10 -> V_29 . V_34 . V_37 == 0xff ) ) {
V_15 |= 1 << V_18 ;
V_15 |= 1 << V_19 ;
}
}
if ( V_2 -> V_29 -> V_34 . V_37 == V_43 ) {
V_13 |= 1 << V_23 ;
if ( V_2 -> V_10 && ( V_2 -> V_10 -> V_29 . V_34 . V_37 == 0xff ) )
V_15 |= 1 << V_23 ;
if ( V_2 -> V_29 -> V_44 . V_45 ==
F_6 ( V_46 ) ||
V_2 -> V_29 -> V_44 . V_45 == F_6 ( V_47 ) ) {
V_13 |= 1 << V_25 ;
if ( V_2 -> V_10 && ( V_2 -> V_10 -> V_29 . V_44 . V_45 == F_6 ( 0xffff ) ) )
V_15 |= 1 << V_25 ;
}
}
}
}
if ( ( V_11 & V_13 ) != V_13 ) {
F_7 ( L_1 ,
( unsigned long long ) V_11 , ( unsigned long long ) V_13 ) ;
return false ;
}
if ( ( V_12 & V_15 ) != V_12 ) {
F_7 ( L_2 ,
( unsigned long long ) V_12 , ( unsigned long long ) V_15 ) ;
return false ;
}
return true ;
}
static bool F_8 ( const T_4 * V_48 , T_1 V_4 )
{
int V_49 ;
if ( ! V_48 )
return false ;
for ( V_49 = 0 ; V_49 < V_4 ; V_49 ++ )
if ( V_48 [ V_49 ] )
return false ;
return true ;
}
static int F_9 ( const struct V_50 * V_51 ,
const struct V_50 * V_52 [] ,
T_3 * V_53 , bool V_54 )
{
const struct V_50 * V_55 ;
T_3 V_56 ;
int V_57 ;
V_56 = * V_53 ;
F_10 (nla, attr, rem) {
T_2 type = F_11 ( V_55 ) ;
int V_58 ;
if ( type > V_59 ) {
F_7 ( L_3 ,
type , V_59 ) ;
return - V_60 ;
}
if ( V_56 & ( 1 << type ) ) {
F_7 ( L_4 , type ) ;
return - V_60 ;
}
V_58 = V_61 [ type ] ;
if ( F_12 ( V_55 ) != V_58 && V_58 != - 1 ) {
F_7 ( L_5
L_6 , type ,
F_12 ( V_55 ) , V_58 ) ;
return - V_60 ;
}
if ( ! V_54 || ! F_8 ( F_13 ( V_55 ) , V_58 ) ) {
V_56 |= 1 << type ;
V_52 [ type ] = V_55 ;
}
}
if ( V_57 ) {
F_7 ( L_7 , V_57 ) ;
return - V_60 ;
}
* V_53 = V_56 ;
return 0 ;
}
static int F_14 ( const struct V_50 * V_51 ,
const struct V_50 * V_52 [] , T_3 * V_53 )
{
return F_9 ( V_51 , V_52 , V_53 , true ) ;
}
static int F_15 ( const struct V_50 * V_51 ,
const struct V_50 * V_52 [] , T_3 * V_53 )
{
return F_9 ( V_51 , V_52 , V_53 , false ) ;
}
static int F_16 ( const struct V_50 * V_51 ,
struct V_1 * V_2 , bool V_5 )
{
struct V_50 * V_52 ;
int V_57 ;
bool V_62 = false ;
T_5 V_63 = 0 ;
F_10 (a, attr, rem) {
int type = F_11 ( V_52 ) ;
static const T_6 V_64 [ V_65 + 1 ] = {
[ V_66 ] = sizeof( T_3 ) ,
[ V_67 ] = sizeof( T_6 ) ,
[ V_68 ] = sizeof( T_6 ) ,
[ V_69 ] = 1 ,
[ V_70 ] = 1 ,
[ V_71 ] = 0 ,
[ V_72 ] = 0 ,
} ;
if ( type > V_65 ) {
F_7 ( L_8 ,
type , V_65 ) ;
return - V_60 ;
}
if ( V_64 [ type ] != F_12 ( V_52 ) ) {
F_7 ( L_9
L_10 ,
type , F_12 ( V_52 ) , V_64 [ type ] ) ;
return - V_60 ;
}
switch ( type ) {
case V_66 :
F_17 ( V_2 , V_73 . V_74 ,
F_18 ( V_52 ) , V_5 ) ;
V_63 |= V_75 ;
break;
case V_67 :
F_17 ( V_2 , V_73 . V_76 ,
F_19 ( V_52 ) , V_5 ) ;
break;
case V_68 :
F_17 ( V_2 , V_73 . V_77 ,
F_19 ( V_52 ) , V_5 ) ;
break;
case V_69 :
F_17 ( V_2 , V_73 . V_78 ,
F_20 ( V_52 ) , V_5 ) ;
break;
case V_70 :
F_17 ( V_2 , V_73 . V_79 ,
F_20 ( V_52 ) , V_5 ) ;
V_62 = true ;
break;
case V_71 :
V_63 |= V_80 ;
break;
case V_72 :
V_63 |= V_81 ;
break;
default:
return - V_60 ;
}
}
F_17 ( V_2 , V_73 . V_63 , V_63 , V_5 ) ;
if ( V_57 > 0 ) {
F_7 ( L_11 , V_57 ) ;
return - V_60 ;
}
if ( ! V_5 ) {
if ( ! V_2 -> V_29 -> V_73 . V_77 ) {
F_7 ( L_12 ) ;
return - V_60 ;
}
if ( ! V_62 ) {
F_7 ( L_13 ) ;
return - V_60 ;
}
}
return 0 ;
}
static int F_21 ( struct V_82 * V_83 ,
const struct V_84 * V_73 ,
const struct V_84 * V_85 )
{
struct V_50 * V_55 ;
V_55 = F_22 ( V_83 , V_26 ) ;
if ( ! V_55 )
return - V_86 ;
if ( V_85 -> V_63 & V_75 &&
F_23 ( V_83 , V_66 , V_85 -> V_74 ) )
return - V_86 ;
if ( V_85 -> V_76 &&
F_24 ( V_83 , V_67 , V_85 -> V_76 ) )
return - V_86 ;
if ( V_85 -> V_77 &&
F_24 ( V_83 , V_68 , V_85 -> V_77 ) )
return - V_86 ;
if ( V_85 -> V_78 &&
F_25 ( V_83 , V_69 , V_85 -> V_78 ) )
return - V_86 ;
if ( F_25 ( V_83 , V_70 , V_85 -> V_79 ) )
return - V_86 ;
if ( ( V_85 -> V_63 & V_80 ) &&
F_26 ( V_83 , V_71 ) )
return - V_86 ;
if ( ( V_85 -> V_63 & V_81 ) &&
F_26 ( V_83 , V_72 ) )
return - V_86 ;
F_27 ( V_83 , V_55 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 , T_3 * V_56 ,
const struct V_50 * * V_52 , bool V_5 )
{
if ( * V_56 & ( 1 << V_87 ) ) {
F_17 ( V_2 , V_88 . V_89 ,
F_29 ( V_52 [ V_87 ] ) , V_5 ) ;
* V_56 &= ~ ( 1 << V_87 ) ;
}
if ( * V_56 & ( 1 << V_27 ) ) {
T_6 V_90 = F_29 ( V_52 [ V_27 ] ) ;
if ( V_5 )
V_90 = 0xffffffff ;
else if ( V_90 >= V_91 )
return - V_60 ;
F_17 ( V_2 , V_88 . V_90 , V_90 , V_5 ) ;
* V_56 &= ~ ( 1 << V_27 ) ;
} else if ( ! V_5 ) {
F_17 ( V_2 , V_88 . V_90 , V_91 , V_5 ) ;
}
if ( * V_56 & ( 1 << V_92 ) ) {
T_7 V_93 = F_29 ( V_52 [ V_92 ] ) ;
F_17 ( V_2 , V_88 . V_94 , V_93 , V_5 ) ;
* V_56 &= ~ ( 1 << V_92 ) ;
}
if ( * V_56 & ( 1 << V_26 ) ) {
if ( F_16 ( V_52 [ V_26 ] , V_2 ,
V_5 ) )
return - V_60 ;
* V_56 &= ~ ( 1 << V_26 ) ;
}
return 0 ;
}
static int F_30 ( struct V_1 * V_2 , T_3 V_56 ,
const struct V_50 * * V_52 , bool V_5 )
{
int V_95 ;
T_3 V_96 = V_56 ;
V_95 = F_28 ( V_2 , & V_56 , V_52 , V_5 ) ;
if ( V_95 )
return V_95 ;
if ( V_56 & ( 1 << V_14 ) ) {
const struct V_97 * V_98 ;
V_98 = F_13 ( V_52 [ V_14 ] ) ;
F_31 ( V_2 , V_30 . V_45 ,
V_98 -> V_99 , V_100 , V_5 ) ;
F_31 ( V_2 , V_30 . V_101 ,
V_98 -> V_102 , V_100 , V_5 ) ;
V_56 &= ~ ( 1 << V_14 ) ;
}
if ( V_56 & ( 1 << V_103 ) ) {
T_5 V_104 ;
V_104 = F_32 ( V_52 [ V_103 ] ) ;
if ( ! ( V_104 & F_6 ( V_105 ) ) ) {
if ( V_5 )
F_7 ( L_14 ) ;
else
F_7 ( L_15 ) ;
return - V_60 ;
}
F_17 ( V_2 , V_30 . V_104 , V_104 , V_5 ) ;
V_56 &= ~ ( 1 << V_103 ) ;
} else if ( ! V_5 )
F_17 ( V_2 , V_30 . V_104 , F_6 ( 0xffff ) , true ) ;
if ( V_56 & ( 1 << V_28 ) ) {
T_5 V_106 ;
V_106 = F_32 ( V_52 [ V_28 ] ) ;
if ( V_5 ) {
V_106 = F_6 ( 0xffff ) ;
} else if ( F_33 ( V_106 ) < V_107 ) {
F_7 ( L_16 ,
F_33 ( V_106 ) , V_107 ) ;
return - V_60 ;
}
F_17 ( V_2 , V_30 . type , V_106 , V_5 ) ;
V_56 &= ~ ( 1 << V_28 ) ;
} else if ( ! V_5 ) {
F_17 ( V_2 , V_30 . type , F_6 ( V_108 ) , V_5 ) ;
}
if ( V_56 & ( 1 << V_16 ) ) {
const struct V_109 * V_110 ;
V_110 = F_13 ( V_52 [ V_16 ] ) ;
if ( ! V_5 && V_110 -> V_111 > V_112 ) {
F_7 ( L_17 ,
V_110 -> V_111 , V_112 ) ;
return - V_60 ;
}
F_17 ( V_2 , V_34 . V_37 ,
V_110 -> V_113 , V_5 ) ;
F_17 ( V_2 , V_34 . V_114 ,
V_110 -> V_78 , V_5 ) ;
F_17 ( V_2 , V_34 . V_62 ,
V_110 -> V_79 , V_5 ) ;
F_17 ( V_2 , V_34 . V_35 ,
V_110 -> V_111 , V_5 ) ;
F_17 ( V_2 , V_115 . V_116 . V_45 ,
V_110 -> V_76 , V_5 ) ;
F_17 ( V_2 , V_115 . V_116 . V_101 ,
V_110 -> V_77 , V_5 ) ;
V_56 &= ~ ( 1 << V_16 ) ;
}
if ( V_56 & ( 1 << V_17 ) ) {
const struct V_117 * V_118 ;
V_118 = F_13 ( V_52 [ V_17 ] ) ;
if ( ! V_5 && V_118 -> V_119 > V_112 ) {
F_7 ( L_18 ,
V_118 -> V_119 , V_112 ) ;
return - V_60 ;
}
F_17 ( V_2 , V_120 . V_121 ,
V_118 -> V_122 , V_5 ) ;
F_17 ( V_2 , V_34 . V_37 ,
V_118 -> V_123 , V_5 ) ;
F_17 ( V_2 , V_34 . V_114 ,
V_118 -> V_124 , V_5 ) ;
F_17 ( V_2 , V_34 . V_62 ,
V_118 -> V_125 , V_5 ) ;
F_17 ( V_2 , V_34 . V_35 ,
V_118 -> V_119 , V_5 ) ;
F_31 ( V_2 , V_120 . V_116 . V_45 ,
V_118 -> V_126 ,
sizeof( V_2 -> V_29 -> V_120 . V_116 . V_45 ) ,
V_5 ) ;
F_31 ( V_2 , V_120 . V_116 . V_101 ,
V_118 -> V_127 ,
sizeof( V_2 -> V_29 -> V_120 . V_116 . V_101 ) ,
V_5 ) ;
V_56 &= ~ ( 1 << V_17 ) ;
}
if ( V_56 & ( 1 << V_24 ) ) {
const struct V_128 * V_129 ;
V_129 = F_13 ( V_52 [ V_24 ] ) ;
if ( ! V_5 && ( V_129 -> V_130 & F_6 ( 0xff00 ) ) ) {
F_7 ( L_19 ,
V_129 -> V_130 ) ;
return - V_60 ;
}
F_17 ( V_2 , V_115 . V_116 . V_45 ,
V_129 -> V_131 , V_5 ) ;
F_17 ( V_2 , V_115 . V_116 . V_101 ,
V_129 -> V_132 , V_5 ) ;
F_17 ( V_2 , V_34 . V_37 ,
F_33 ( V_129 -> V_130 ) , V_5 ) ;
F_31 ( V_2 , V_115 . V_133 . V_134 ,
V_129 -> V_135 , V_100 , V_5 ) ;
F_31 ( V_2 , V_115 . V_133 . V_136 ,
V_129 -> V_137 , V_100 , V_5 ) ;
V_56 &= ~ ( 1 << V_24 ) ;
}
if ( V_56 & ( 1 << V_18 ) ) {
const struct V_138 * V_139 ;
V_139 = F_13 ( V_52 [ V_18 ] ) ;
F_17 ( V_2 , V_44 . V_45 , V_139 -> V_140 , V_5 ) ;
F_17 ( V_2 , V_44 . V_101 , V_139 -> V_141 , V_5 ) ;
V_56 &= ~ ( 1 << V_18 ) ;
}
if ( V_56 & ( 1 << V_19 ) ) {
if ( V_96 & ( 1 << V_16 ) ) {
F_17 ( V_2 , V_44 . V_142 ,
F_32 ( V_52 [ V_19 ] ) ,
V_5 ) ;
} else {
F_17 ( V_2 , V_44 . V_142 ,
F_32 ( V_52 [ V_19 ] ) ,
V_5 ) ;
}
V_56 &= ~ ( 1 << V_19 ) ;
}
if ( V_56 & ( 1 << V_20 ) ) {
const struct V_143 * V_144 ;
V_144 = F_13 ( V_52 [ V_20 ] ) ;
F_17 ( V_2 , V_44 . V_45 , V_144 -> V_145 , V_5 ) ;
F_17 ( V_2 , V_44 . V_101 , V_144 -> V_146 , V_5 ) ;
V_56 &= ~ ( 1 << V_20 ) ;
}
if ( V_56 & ( 1 << V_21 ) ) {
const struct V_147 * V_148 ;
V_148 = F_13 ( V_52 [ V_21 ] ) ;
F_17 ( V_2 , V_44 . V_45 , V_148 -> V_149 , V_5 ) ;
F_17 ( V_2 , V_44 . V_101 , V_148 -> V_150 , V_5 ) ;
V_56 &= ~ ( 1 << V_21 ) ;
}
if ( V_56 & ( 1 << V_22 ) ) {
const struct V_151 * V_152 ;
V_152 = F_13 ( V_52 [ V_22 ] ) ;
F_17 ( V_2 , V_44 . V_45 ,
F_6 ( V_152 -> V_153 ) , V_5 ) ;
F_17 ( V_2 , V_44 . V_101 ,
F_6 ( V_152 -> V_154 ) , V_5 ) ;
V_56 &= ~ ( 1 << V_22 ) ;
}
if ( V_56 & ( 1 << V_23 ) ) {
const struct V_155 * V_156 ;
V_156 = F_13 ( V_52 [ V_23 ] ) ;
F_17 ( V_2 , V_44 . V_45 ,
F_6 ( V_156 -> V_157 ) , V_5 ) ;
F_17 ( V_2 , V_44 . V_101 ,
F_6 ( V_156 -> V_158 ) , V_5 ) ;
V_56 &= ~ ( 1 << V_23 ) ;
}
if ( V_56 & ( 1 << V_25 ) ) {
const struct V_159 * V_160 ;
V_160 = F_13 ( V_52 [ V_25 ] ) ;
F_31 ( V_2 , V_120 . V_161 . V_162 ,
V_160 -> V_163 ,
sizeof( V_2 -> V_29 -> V_120 . V_161 . V_162 ) ,
V_5 ) ;
F_31 ( V_2 , V_120 . V_161 . V_164 ,
V_160 -> V_165 , V_100 , V_5 ) ;
F_31 ( V_2 , V_120 . V_161 . V_166 ,
V_160 -> V_167 , V_100 , V_5 ) ;
V_56 &= ~ ( 1 << V_25 ) ;
}
if ( V_56 != 0 )
return - V_60 ;
return 0 ;
}
static void F_34 ( struct V_168 * V_10 ,
struct V_6 * V_7 , T_4 V_169 )
{
T_4 * V_170 = ( T_4 * ) & V_10 -> V_29 + V_7 -> V_8 ;
V_10 -> V_7 = * V_7 ;
memset ( V_170 , V_169 , F_4 ( V_7 ) ) ;
}
int F_35 ( struct V_1 * V_2 ,
const struct V_50 * V_29 ,
const struct V_50 * V_10 )
{
const struct V_50 * V_52 [ V_59 + 1 ] ;
const struct V_50 * V_171 ;
T_3 V_11 = 0 ;
T_3 V_12 = 0 ;
bool V_172 = false ;
int V_95 ;
V_95 = F_15 ( V_29 , V_52 , & V_11 ) ;
if ( V_95 )
return V_95 ;
if ( ( V_11 & ( 1 << V_14 ) ) &&
( V_11 & ( 1 << V_28 ) ) &&
( F_32 ( V_52 [ V_28 ] ) == F_6 ( V_173 ) ) ) {
T_5 V_104 ;
if ( ! ( ( V_11 & ( 1 << V_103 ) ) &&
( V_11 & ( 1 << V_174 ) ) ) ) {
F_7 ( L_20 ) ;
return - V_60 ;
}
V_11 &= ~ ( 1 << V_28 ) ;
V_104 = F_32 ( V_52 [ V_103 ] ) ;
V_171 = V_52 [ V_174 ] ;
V_11 &= ~ ( 1 << V_174 ) ;
V_172 = true ;
if ( V_104 & F_6 ( V_105 ) ) {
V_95 = F_15 ( V_171 , V_52 , & V_11 ) ;
if ( V_95 )
return V_95 ;
} else if ( ! V_104 ) {
if ( F_12 ( V_171 ) ) {
F_7 ( L_21 ) ;
return - V_60 ;
}
} else {
F_7 ( L_22 ) ;
return - V_60 ;
}
}
V_95 = F_30 ( V_2 , V_11 , V_52 , false ) ;
if ( V_95 )
return V_95 ;
if ( V_10 ) {
V_95 = F_14 ( V_10 , V_52 , & V_12 ) ;
if ( V_95 )
return V_95 ;
if ( V_12 & 1 << V_174 ) {
T_5 V_106 = 0 ;
T_5 V_104 = 0 ;
if ( ! V_172 ) {
F_7 ( L_23 ) ;
return - V_60 ;
}
V_12 &= ~ ( 1 << V_174 ) ;
if ( V_52 [ V_28 ] )
V_106 = F_32 ( V_52 [ V_28 ] ) ;
if ( V_106 == F_6 ( 0xffff ) ) {
V_12 &= ~ ( 1 << V_28 ) ;
V_171 = V_52 [ V_174 ] ;
V_95 = F_14 ( V_171 , V_52 , & V_12 ) ;
} else {
F_7 ( L_24 ,
F_33 ( V_106 ) ) ;
return - V_60 ;
}
if ( V_52 [ V_103 ] )
V_104 = F_32 ( V_52 [ V_103 ] ) ;
if ( ! ( V_104 & F_6 ( V_105 ) ) ) {
F_7 ( L_25 , F_33 ( V_104 ) ) ;
return - V_60 ;
}
}
V_95 = F_30 ( V_2 , V_12 , V_52 , true ) ;
if ( V_95 )
return V_95 ;
} else {
if ( V_2 -> V_10 )
F_34 ( V_2 -> V_10 , & V_2 -> V_7 , 0xff ) ;
}
if ( ! F_5 ( V_2 , V_11 , V_12 ) )
return - V_60 ;
return 0 ;
}
int F_36 ( struct V_175 * V_176 ,
const struct V_50 * V_51 )
{
struct V_84 * V_73 = & V_176 -> V_29 . V_73 ;
const struct V_50 * V_52 [ V_59 + 1 ] ;
T_3 V_56 = 0 ;
int V_95 ;
struct V_1 V_2 ;
V_176 -> V_29 . V_88 . V_90 = V_91 ;
V_176 -> V_29 . V_88 . V_89 = 0 ;
V_176 -> V_29 . V_88 . V_94 = 0 ;
memset ( V_73 , 0 , sizeof( V_176 -> V_29 . V_73 ) ) ;
V_95 = F_15 ( V_51 , V_52 , & V_56 ) ;
if ( V_95 )
return - V_60 ;
memset ( & V_2 , 0 , sizeof( V_2 ) ) ;
V_2 . V_29 = & V_176 -> V_29 ;
V_95 = F_28 ( & V_2 , & V_56 , V_52 , false ) ;
if ( V_95 )
return V_95 ;
return 0 ;
}
int F_37 ( const struct V_177 * V_178 ,
const struct V_177 * V_85 , struct V_82 * V_83 )
{
struct V_97 * V_98 ;
struct V_50 * V_55 , * V_171 ;
bool V_5 = ( V_178 != V_85 ) ;
if ( F_38 ( V_83 , V_87 , V_85 -> V_88 . V_89 ) )
goto V_179;
if ( ( V_178 -> V_73 . V_77 || V_5 ) &&
F_21 ( V_83 , & V_178 -> V_73 , & V_85 -> V_73 ) )
goto V_179;
if ( V_178 -> V_88 . V_90 == V_91 ) {
if ( V_5 && ( V_85 -> V_88 . V_90 == 0xffff ) )
if ( F_38 ( V_83 , V_27 , 0xffffffff ) )
goto V_179;
} else {
T_2 V_180 ;
V_180 = ! V_5 ? 0 : 0xffff ;
if ( F_38 ( V_83 , V_27 ,
( V_180 << 16 ) | V_85 -> V_88 . V_90 ) )
goto V_179;
}
if ( F_38 ( V_83 , V_92 , V_85 -> V_88 . V_94 ) )
goto V_179;
V_55 = F_39 ( V_83 , V_14 , sizeof( * V_98 ) ) ;
if ( ! V_55 )
goto V_179;
V_98 = F_13 ( V_55 ) ;
F_40 ( V_98 -> V_99 , V_85 -> V_30 . V_45 ) ;
F_40 ( V_98 -> V_102 , V_85 -> V_30 . V_101 ) ;
if ( V_178 -> V_30 . V_104 || V_178 -> V_30 . type == F_6 ( V_173 ) ) {
T_5 V_106 ;
V_106 = ! V_5 ? F_6 ( V_173 ) : F_6 ( 0xffff ) ;
if ( F_41 ( V_83 , V_28 , V_106 ) ||
F_41 ( V_83 , V_103 , V_85 -> V_30 . V_104 ) )
goto V_179;
V_171 = F_22 ( V_83 , V_174 ) ;
if ( ! V_178 -> V_30 . V_104 )
goto V_181;
} else
V_171 = NULL ;
if ( V_178 -> V_30 . type == F_6 ( V_108 ) ) {
if ( V_5 && V_85 -> V_30 . type )
if ( F_41 ( V_83 , V_28 ,
V_85 -> V_30 . type ) )
goto V_179;
goto V_181;
}
if ( F_41 ( V_83 , V_28 , V_85 -> V_30 . type ) )
goto V_179;
if ( V_178 -> V_30 . type == F_6 ( V_33 ) ) {
struct V_109 * V_110 ;
V_55 = F_39 ( V_83 , V_16 , sizeof( * V_110 ) ) ;
if ( ! V_55 )
goto V_179;
V_110 = F_13 ( V_55 ) ;
V_110 -> V_76 = V_85 -> V_115 . V_116 . V_45 ;
V_110 -> V_77 = V_85 -> V_115 . V_116 . V_101 ;
V_110 -> V_113 = V_85 -> V_34 . V_37 ;
V_110 -> V_78 = V_85 -> V_34 . V_114 ;
V_110 -> V_79 = V_85 -> V_34 . V_62 ;
V_110 -> V_111 = V_85 -> V_34 . V_35 ;
} else if ( V_178 -> V_30 . type == F_6 ( V_42 ) ) {
struct V_117 * V_118 ;
V_55 = F_39 ( V_83 , V_17 , sizeof( * V_118 ) ) ;
if ( ! V_55 )
goto V_179;
V_118 = F_13 ( V_55 ) ;
memcpy ( V_118 -> V_126 , & V_85 -> V_120 . V_116 . V_45 ,
sizeof( V_118 -> V_126 ) ) ;
memcpy ( V_118 -> V_127 , & V_85 -> V_120 . V_116 . V_101 ,
sizeof( V_118 -> V_127 ) ) ;
V_118 -> V_122 = V_85 -> V_120 . V_121 ;
V_118 -> V_123 = V_85 -> V_34 . V_37 ;
V_118 -> V_124 = V_85 -> V_34 . V_114 ;
V_118 -> V_125 = V_85 -> V_34 . V_62 ;
V_118 -> V_119 = V_85 -> V_34 . V_35 ;
} else if ( V_178 -> V_30 . type == F_6 ( V_31 ) ||
V_178 -> V_30 . type == F_6 ( V_32 ) ) {
struct V_128 * V_129 ;
V_55 = F_39 ( V_83 , V_24 , sizeof( * V_129 ) ) ;
if ( ! V_55 )
goto V_179;
V_129 = F_13 ( V_55 ) ;
memset ( V_129 , 0 , sizeof( struct V_128 ) ) ;
V_129 -> V_131 = V_85 -> V_115 . V_116 . V_45 ;
V_129 -> V_132 = V_85 -> V_115 . V_116 . V_101 ;
V_129 -> V_130 = F_6 ( V_85 -> V_34 . V_37 ) ;
F_40 ( V_129 -> V_135 , V_85 -> V_115 . V_133 . V_134 ) ;
F_40 ( V_129 -> V_137 , V_85 -> V_115 . V_133 . V_136 ) ;
}
if ( ( V_178 -> V_30 . type == F_6 ( V_33 ) ||
V_178 -> V_30 . type == F_6 ( V_42 ) ) &&
V_178 -> V_34 . V_35 != V_36 ) {
if ( V_178 -> V_34 . V_37 == V_40 ) {
struct V_138 * V_139 ;
V_55 = F_39 ( V_83 , V_18 , sizeof( * V_139 ) ) ;
if ( ! V_55 )
goto V_179;
V_139 = F_13 ( V_55 ) ;
V_139 -> V_140 = V_85 -> V_44 . V_45 ;
V_139 -> V_141 = V_85 -> V_44 . V_101 ;
if ( F_41 ( V_83 , V_19 ,
V_85 -> V_44 . V_142 ) )
goto V_179;
} else if ( V_178 -> V_34 . V_37 == V_38 ) {
struct V_143 * V_144 ;
V_55 = F_39 ( V_83 , V_20 , sizeof( * V_144 ) ) ;
if ( ! V_55 )
goto V_179;
V_144 = F_13 ( V_55 ) ;
V_144 -> V_145 = V_85 -> V_44 . V_45 ;
V_144 -> V_146 = V_85 -> V_44 . V_101 ;
} else if ( V_178 -> V_34 . V_37 == V_39 ) {
struct V_147 * V_148 ;
V_55 = F_39 ( V_83 , V_21 , sizeof( * V_148 ) ) ;
if ( ! V_55 )
goto V_179;
V_148 = F_13 ( V_55 ) ;
V_148 -> V_149 = V_85 -> V_44 . V_45 ;
V_148 -> V_150 = V_85 -> V_44 . V_101 ;
} else if ( V_178 -> V_30 . type == F_6 ( V_33 ) &&
V_178 -> V_34 . V_37 == V_41 ) {
struct V_151 * V_152 ;
V_55 = F_39 ( V_83 , V_22 , sizeof( * V_152 ) ) ;
if ( ! V_55 )
goto V_179;
V_152 = F_13 ( V_55 ) ;
V_152 -> V_153 = F_33 ( V_85 -> V_44 . V_45 ) ;
V_152 -> V_154 = F_33 ( V_85 -> V_44 . V_101 ) ;
} else if ( V_178 -> V_30 . type == F_6 ( V_42 ) &&
V_178 -> V_34 . V_37 == V_43 ) {
struct V_155 * V_156 ;
V_55 = F_39 ( V_83 , V_23 ,
sizeof( * V_156 ) ) ;
if ( ! V_55 )
goto V_179;
V_156 = F_13 ( V_55 ) ;
V_156 -> V_157 = F_33 ( V_85 -> V_44 . V_45 ) ;
V_156 -> V_158 = F_33 ( V_85 -> V_44 . V_101 ) ;
if ( V_156 -> V_157 == V_46 ||
V_156 -> V_157 == V_47 ) {
struct V_159 * V_160 ;
V_55 = F_39 ( V_83 , V_25 , sizeof( * V_160 ) ) ;
if ( ! V_55 )
goto V_179;
V_160 = F_13 ( V_55 ) ;
memcpy ( V_160 -> V_163 , & V_85 -> V_120 . V_161 . V_162 ,
sizeof( V_160 -> V_163 ) ) ;
F_40 ( V_160 -> V_165 , V_85 -> V_120 . V_161 . V_164 ) ;
F_40 ( V_160 -> V_167 , V_85 -> V_120 . V_161 . V_166 ) ;
}
}
}
V_181:
if ( V_171 )
F_27 ( V_83 , V_171 ) ;
return 0 ;
V_179:
return - V_86 ;
}
struct V_182 * F_42 ( int V_4 )
{
struct V_182 * V_183 ;
if ( V_4 > V_184 )
return F_43 ( - V_60 ) ;
V_183 = F_44 ( sizeof( * V_183 ) + V_4 , V_185 ) ;
if ( ! V_183 )
return F_43 ( - V_186 ) ;
V_183 -> V_187 = 0 ;
return V_183 ;
}
void F_45 ( struct V_182 * V_188 )
{
F_46 ( V_188 , V_189 ) ;
}
static struct V_50 * F_47 ( struct V_182 * * V_183 ,
int V_190 )
{
struct V_182 * V_191 ;
int V_192 ;
int V_193 = F_48 ( V_190 ) ;
int V_194 = F_49 ( struct V_182 , V_195 ) +
( * V_183 ) -> V_187 ;
if ( V_193 <= ( F_50 ( * V_183 ) - V_194 ) )
goto V_196;
V_192 = F_50 ( * V_183 ) * 2 ;
if ( V_192 > V_184 ) {
if ( ( V_184 - V_194 ) < V_193 )
return F_43 ( - V_86 ) ;
V_192 = V_184 ;
}
V_191 = F_42 ( V_192 ) ;
if ( F_51 ( V_191 ) )
return ( void * ) V_191 ;
memcpy ( V_191 -> V_195 , ( * V_183 ) -> V_195 , ( * V_183 ) -> V_187 ) ;
V_191 -> V_187 = ( * V_183 ) -> V_187 ;
F_52 ( * V_183 ) ;
* V_183 = V_191 ;
V_196:
( * V_183 ) -> V_187 += V_193 ;
return (struct V_50 * ) ( ( unsigned char * ) ( * V_183 ) + V_194 ) ;
}
static int F_53 ( struct V_182 * * V_183 , int V_197 , void * V_198 , int V_199 )
{
struct V_50 * V_52 ;
V_52 = F_47 ( V_183 , F_54 ( V_199 ) ) ;
if ( F_51 ( V_52 ) )
return F_55 ( V_52 ) ;
V_52 -> F_11 = V_197 ;
V_52 -> F_12 = F_54 ( V_199 ) ;
if ( V_198 )
memcpy ( F_13 ( V_52 ) , V_198 , V_199 ) ;
memset ( ( unsigned char * ) V_52 + V_52 -> F_12 , 0 , F_56 ( V_199 ) ) ;
return 0 ;
}
static inline int F_57 ( struct V_182 * * V_183 ,
int V_197 )
{
int V_200 = ( * V_183 ) -> V_187 ;
int V_95 ;
V_95 = F_53 ( V_183 , V_197 , NULL , 0 ) ;
if ( V_95 )
return V_95 ;
return V_200 ;
}
static inline void F_58 ( struct V_182 * V_183 ,
int V_201 )
{
struct V_50 * V_52 = (struct V_50 * ) ( ( unsigned char * ) V_183 -> V_195 +
V_201 ) ;
V_52 -> F_12 = V_183 -> V_187 - V_201 ;
}
static int F_59 ( const struct V_50 * V_51 ,
const struct V_177 * V_29 , int V_202 ,
struct V_182 * * V_183 )
{
const struct V_50 * V_56 [ V_203 + 1 ] ;
const struct V_50 * V_204 , * V_195 ;
const struct V_50 * V_52 ;
int V_57 , V_8 , V_95 , V_205 ;
memset ( V_56 , 0 , sizeof( V_56 ) ) ;
F_10 (a, attr, rem) {
int type = F_11 ( V_52 ) ;
if ( ! type || type > V_203 || V_56 [ type ] )
return - V_60 ;
V_56 [ type ] = V_52 ;
}
if ( V_57 )
return - V_60 ;
V_204 = V_56 [ V_206 ] ;
if ( ! V_204 || F_12 ( V_204 ) != sizeof( T_6 ) )
return - V_60 ;
V_195 = V_56 [ V_207 ] ;
if ( ! V_195 || ( F_12 ( V_195 ) && F_12 ( V_195 ) < V_208 ) )
return - V_60 ;
V_8 = F_57 ( V_183 , V_209 ) ;
if ( V_8 < 0 )
return V_8 ;
V_95 = F_53 ( V_183 , V_206 ,
F_13 ( V_204 ) , sizeof( T_6 ) ) ;
if ( V_95 )
return V_95 ;
V_205 = F_57 ( V_183 , V_207 ) ;
if ( V_205 < 0 )
return V_205 ;
V_95 = F_60 ( V_195 , V_29 , V_202 + 1 , V_183 ) ;
if ( V_95 )
return V_95 ;
F_58 ( * V_183 , V_205 ) ;
F_58 ( * V_183 , V_8 ) ;
return 0 ;
}
static int F_61 ( const struct V_177 * V_210 )
{
if ( ( V_210 -> V_30 . type == F_6 ( V_33 ) ||
V_210 -> V_30 . type == F_6 ( V_42 ) ) &&
( V_210 -> V_44 . V_45 || V_210 -> V_44 . V_101 ) )
return 0 ;
return - V_60 ;
}
void F_62 ( struct V_1 * V_2 ,
struct V_177 * V_29 ,
struct V_168 * V_10 )
{
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_29 = V_29 ;
V_2 -> V_10 = V_10 ;
memset ( V_29 , 0 , sizeof( * V_29 ) ) ;
if ( V_10 ) {
memset ( & V_10 -> V_29 , 0 , sizeof( V_10 -> V_29 ) ) ;
V_10 -> V_7 . V_8 = V_10 -> V_7 . V_9 = 0 ;
}
}
static int F_63 ( const struct V_50 * V_51 ,
struct V_182 * * V_183 )
{
struct V_1 V_2 ;
struct V_177 V_29 ;
int V_95 , V_8 ;
F_62 ( & V_2 , & V_29 , NULL ) ;
V_95 = F_16 ( F_13 ( V_51 ) , & V_2 , false ) ;
if ( V_95 )
return V_95 ;
V_8 = F_57 ( V_183 , V_211 ) ;
if ( V_8 < 0 )
return V_8 ;
V_95 = F_53 ( V_183 , V_212 , & V_2 . V_29 -> V_73 ,
sizeof( V_2 . V_29 -> V_73 ) ) ;
F_58 ( * V_183 , V_8 ) ;
return V_95 ;
}
static int F_64 ( const struct V_50 * V_52 ,
const struct V_177 * V_210 ,
struct V_182 * * V_183 ,
bool * V_213 )
{
const struct V_50 * V_214 = F_13 ( V_52 ) ;
int V_215 = F_11 ( V_214 ) ;
if ( F_65 ( F_12 ( V_214 ) ) != F_12 ( V_52 ) )
return - V_60 ;
if ( V_215 > V_59 ||
( V_61 [ V_215 ] != F_12 ( V_214 ) &&
V_61 [ V_215 ] != - 1 ) )
return - V_60 ;
switch ( V_215 ) {
const struct V_109 * V_110 ;
const struct V_117 * V_118 ;
int V_95 ;
case V_87 :
case V_92 :
case V_14 :
break;
case V_26 :
* V_213 = true ;
V_95 = F_63 ( V_52 , V_183 ) ;
if ( V_95 )
return V_95 ;
break;
case V_16 :
if ( V_210 -> V_30 . type != F_6 ( V_33 ) )
return - V_60 ;
if ( ! V_210 -> V_34 . V_37 )
return - V_60 ;
V_110 = F_13 ( V_214 ) ;
if ( V_110 -> V_113 != V_210 -> V_34 . V_37 )
return - V_60 ;
if ( V_110 -> V_111 != V_210 -> V_34 . V_35 )
return - V_60 ;
break;
case V_17 :
if ( V_210 -> V_30 . type != F_6 ( V_42 ) )
return - V_60 ;
if ( ! V_210 -> V_34 . V_37 )
return - V_60 ;
V_118 = F_13 ( V_214 ) ;
if ( V_118 -> V_123 != V_210 -> V_34 . V_37 )
return - V_60 ;
if ( V_118 -> V_119 != V_210 -> V_34 . V_35 )
return - V_60 ;
if ( F_66 ( V_118 -> V_122 ) & 0xFFF00000 )
return - V_60 ;
break;
case V_18 :
if ( V_210 -> V_34 . V_37 != V_40 )
return - V_60 ;
return F_61 ( V_210 ) ;
case V_20 :
if ( V_210 -> V_34 . V_37 != V_38 )
return - V_60 ;
return F_61 ( V_210 ) ;
case V_21 :
if ( V_210 -> V_34 . V_37 != V_39 )
return - V_60 ;
return F_61 ( V_210 ) ;
default:
return - V_60 ;
}
return 0 ;
}
static int F_67 ( const struct V_50 * V_51 )
{
static const struct V_216 V_217 [ V_218 + 1 ] = {
[ V_219 ] = { . type = V_220 } ,
[ V_221 ] = { . type = V_222 } ,
} ;
struct V_50 * V_52 [ V_218 + 1 ] ;
int error ;
error = F_68 ( V_52 , V_218 ,
V_51 , V_217 ) ;
if ( error )
return error ;
if ( ! V_52 [ V_219 ] ||
! F_29 ( V_52 [ V_219 ] ) )
return - V_60 ;
return 0 ;
}
static int F_69 ( const struct V_50 * V_223 ,
struct V_182 * * V_183 )
{
int V_224 = F_48 ( V_223 -> F_12 ) ;
struct V_50 * V_225 ;
V_225 = F_47 ( V_183 , V_223 -> F_12 ) ;
if ( F_51 ( V_225 ) )
return F_55 ( V_225 ) ;
memcpy ( V_225 , V_223 , V_224 ) ;
return 0 ;
}
int F_60 ( const struct V_50 * V_51 ,
const struct V_177 * V_29 ,
int V_202 ,
struct V_182 * * V_183 )
{
const struct V_50 * V_52 ;
int V_57 , V_95 ;
if ( V_202 >= V_226 )
return - V_227 ;
F_10 (a, attr, rem) {
static const T_6 V_228 [ V_229 + 1 ] = {
[ V_230 ] = sizeof( T_6 ) ,
[ V_231 ] = ( T_6 ) - 1 ,
[ V_232 ] = sizeof( struct V_233 ) ,
[ V_234 ] = 0 ,
[ V_211 ] = ( T_6 ) - 1 ,
[ V_209 ] = ( T_6 ) - 1
} ;
const struct V_233 * V_235 ;
int type = F_11 ( V_52 ) ;
bool V_236 ;
if ( type > V_229 ||
( V_228 [ type ] != F_12 ( V_52 ) &&
V_228 [ type ] != ( T_6 ) - 1 ) )
return - V_60 ;
V_236 = false ;
switch ( type ) {
case V_237 :
return - V_60 ;
case V_231 :
V_95 = F_67 ( V_52 ) ;
if ( V_95 )
return V_95 ;
break;
case V_230 :
if ( F_29 ( V_52 ) >= V_91 )
return - V_60 ;
break;
case V_234 :
break;
case V_232 :
V_235 = F_13 ( V_52 ) ;
if ( V_235 -> V_238 != F_6 ( V_173 ) )
return - V_60 ;
if ( ! ( V_235 -> V_239 & F_6 ( V_105 ) ) )
return - V_60 ;
break;
case V_211 :
V_95 = F_64 ( V_52 , V_29 , V_183 , & V_236 ) ;
if ( V_95 )
return V_95 ;
break;
case V_209 :
V_95 = F_59 ( V_52 , V_29 , V_202 , V_183 ) ;
if ( V_95 )
return V_95 ;
V_236 = true ;
break;
default:
return - V_60 ;
}
if ( ! V_236 ) {
V_95 = F_69 ( V_52 , V_183 ) ;
if ( V_95 )
return V_95 ;
}
}
if ( V_57 > 0 )
return - V_60 ;
return 0 ;
}
static int F_70 ( const struct V_50 * V_51 , struct V_82 * V_83 )
{
const struct V_50 * V_52 ;
struct V_50 * V_8 ;
int V_95 = 0 , V_57 ;
V_8 = F_22 ( V_83 , V_209 ) ;
if ( ! V_8 )
return - V_86 ;
F_10 (a, attr, rem) {
int type = F_11 ( V_52 ) ;
struct V_50 * V_240 ;
switch ( type ) {
case V_206 :
if ( F_71 ( V_83 , V_206 ,
sizeof( T_6 ) , F_13 ( V_52 ) ) )
return - V_86 ;
break;
case V_207 :
V_240 = F_22 ( V_83 , V_207 ) ;
if ( ! V_240 )
return - V_86 ;
V_95 = F_72 ( F_13 ( V_52 ) , F_12 ( V_52 ) , V_83 ) ;
if ( V_95 )
return V_95 ;
F_27 ( V_83 , V_240 ) ;
break;
}
}
F_27 ( V_83 , V_8 ) ;
return V_95 ;
}
static int F_73 ( const struct V_50 * V_52 , struct V_82 * V_83 )
{
const struct V_50 * V_214 = F_13 ( V_52 ) ;
int V_215 = F_11 ( V_214 ) ;
struct V_50 * V_8 ;
int V_95 ;
switch ( V_215 ) {
case V_212 :
V_8 = F_22 ( V_83 , V_211 ) ;
if ( ! V_8 )
return - V_86 ;
V_95 = F_21 ( V_83 , F_13 ( V_214 ) ,
F_13 ( V_214 ) ) ;
if ( V_95 )
return V_95 ;
F_27 ( V_83 , V_8 ) ;
break;
default:
if ( F_71 ( V_83 , V_211 , F_12 ( V_52 ) , V_214 ) )
return - V_86 ;
break;
}
return 0 ;
}
int F_72 ( const struct V_50 * V_51 , int V_199 , struct V_82 * V_83 )
{
const struct V_50 * V_52 ;
int V_57 , V_95 ;
F_74 (a, attr, len, rem) {
int type = F_11 ( V_52 ) ;
switch ( type ) {
case V_211 :
V_95 = F_73 ( V_52 , V_83 ) ;
if ( V_95 )
return V_95 ;
break;
case V_209 :
V_95 = F_70 ( V_52 , V_83 ) ;
if ( V_95 )
return V_95 ;
break;
default:
if ( F_71 ( V_83 , type , F_12 ( V_52 ) , F_13 ( V_52 ) ) )
return - V_86 ;
break;
}
}
return 0 ;
}
