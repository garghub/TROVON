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
static bool F_4 ( const struct V_1 * V_2 ,
T_2 V_11 , T_2 V_12 )
{
T_2 V_13 = 1 << V_14 ;
T_2 V_15 = V_11 ;
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
if ( V_2 -> V_29 -> V_30 . type == F_5 ( V_31 )
|| V_2 -> V_29 -> V_30 . type == F_5 ( V_32 ) ) {
V_13 |= 1 << V_24 ;
if ( V_2 -> V_10 && ( V_2 -> V_10 -> V_29 . V_33 . V_34 == F_5 ( 0xff ) ) )
V_15 |= 1 << V_24 ;
}
if ( V_2 -> V_29 -> V_30 . type == F_5 ( V_35 ) ) {
V_13 |= 1 << V_16 ;
if ( V_2 -> V_10 && ( V_2 -> V_10 -> V_29 . V_30 . type == F_5 ( 0xffff ) ) )
V_15 |= 1 << V_16 ;
if ( V_2 -> V_29 -> V_36 . V_37 != V_38 ) {
if ( V_2 -> V_29 -> V_36 . V_39 == V_40 ) {
V_13 |= 1 << V_20 ;
if ( V_2 -> V_10 && ( V_2 -> V_10 -> V_29 . V_36 . V_39 == 0xff ) )
V_15 |= 1 << V_20 ;
}
if ( V_2 -> V_29 -> V_36 . V_39 == V_41 ) {
V_13 |= 1 << V_21 ;
if ( V_2 -> V_10 && ( V_2 -> V_10 -> V_29 . V_36 . V_39 == 0xff ) )
V_15 |= 1 << V_21 ;
}
if ( V_2 -> V_29 -> V_36 . V_39 == V_42 ) {
V_13 |= 1 << V_18 ;
V_13 |= 1 << V_19 ;
if ( V_2 -> V_10 && ( V_2 -> V_10 -> V_29 . V_36 . V_39 == 0xff ) ) {
V_15 |= 1 << V_18 ;
V_15 |= 1 << V_19 ;
}
}
if ( V_2 -> V_29 -> V_36 . V_39 == V_43 ) {
V_13 |= 1 << V_22 ;
if ( V_2 -> V_10 && ( V_2 -> V_10 -> V_29 . V_36 . V_39 == 0xff ) )
V_15 |= 1 << V_22 ;
}
}
}
if ( V_2 -> V_29 -> V_30 . type == F_5 ( V_44 ) ) {
V_13 |= 1 << V_17 ;
if ( V_2 -> V_10 && ( V_2 -> V_10 -> V_29 . V_30 . type == F_5 ( 0xffff ) ) )
V_15 |= 1 << V_17 ;
if ( V_2 -> V_29 -> V_36 . V_37 != V_38 ) {
if ( V_2 -> V_29 -> V_36 . V_39 == V_40 ) {
V_13 |= 1 << V_20 ;
if ( V_2 -> V_10 && ( V_2 -> V_10 -> V_29 . V_36 . V_39 == 0xff ) )
V_15 |= 1 << V_20 ;
}
if ( V_2 -> V_29 -> V_36 . V_39 == V_41 ) {
V_13 |= 1 << V_21 ;
if ( V_2 -> V_10 && ( V_2 -> V_10 -> V_29 . V_36 . V_39 == 0xff ) )
V_15 |= 1 << V_21 ;
}
if ( V_2 -> V_29 -> V_36 . V_39 == V_42 ) {
V_13 |= 1 << V_18 ;
V_13 |= 1 << V_19 ;
if ( V_2 -> V_10 && ( V_2 -> V_10 -> V_29 . V_36 . V_39 == 0xff ) ) {
V_15 |= 1 << V_18 ;
V_15 |= 1 << V_19 ;
}
}
if ( V_2 -> V_29 -> V_36 . V_39 == V_45 ) {
V_13 |= 1 << V_23 ;
if ( V_2 -> V_10 && ( V_2 -> V_10 -> V_29 . V_36 . V_39 == 0xff ) )
V_15 |= 1 << V_23 ;
if ( V_2 -> V_29 -> V_33 . V_34 ==
F_5 ( V_46 ) ||
V_2 -> V_29 -> V_33 . V_34 == F_5 ( V_47 ) ) {
V_13 |= 1 << V_25 ;
if ( V_2 -> V_10 && ( V_2 -> V_10 -> V_29 . V_33 . V_34 == F_5 ( 0xffff ) ) )
V_15 |= 1 << V_25 ;
}
}
}
}
if ( ( V_11 & V_13 ) != V_13 ) {
F_6 ( L_1 ,
( unsigned long long ) V_11 , ( unsigned long long ) V_13 ) ;
return false ;
}
if ( ( V_12 & V_15 ) != V_12 ) {
F_6 ( L_2 ,
( unsigned long long ) V_12 , ( unsigned long long ) V_15 ) ;
return false ;
}
return true ;
}
static bool F_7 ( const T_3 * V_48 , T_1 V_4 )
{
int V_49 ;
if ( ! V_48 )
return false ;
for ( V_49 = 0 ; V_49 < V_4 ; V_49 ++ )
if ( V_48 [ V_49 ] )
return false ;
return true ;
}
static int F_8 ( const struct V_50 * V_51 ,
const struct V_50 * V_52 [] ,
T_2 * V_53 , bool V_54 )
{
const struct V_50 * V_55 ;
T_2 V_56 ;
int V_57 ;
V_56 = * V_53 ;
F_9 (nla, attr, rem) {
T_4 type = F_10 ( V_55 ) ;
int V_58 ;
if ( type > V_59 ) {
F_6 ( L_3 ,
type , V_59 ) ;
return - V_60 ;
}
if ( V_56 & ( 1 << type ) ) {
F_6 ( L_4 , type ) ;
return - V_60 ;
}
V_58 = V_61 [ type ] ;
if ( F_11 ( V_55 ) != V_58 && V_58 != - 1 ) {
F_6 ( L_5
L_6 , type ,
F_11 ( V_55 ) , V_58 ) ;
return - V_60 ;
}
if ( ! V_54 || ! F_7 ( F_12 ( V_55 ) , V_58 ) ) {
V_56 |= 1 << type ;
V_52 [ type ] = V_55 ;
}
}
if ( V_57 ) {
F_6 ( L_7 , V_57 ) ;
return - V_60 ;
}
* V_53 = V_56 ;
return 0 ;
}
static int F_13 ( const struct V_50 * V_51 ,
const struct V_50 * V_52 [] , T_2 * V_53 )
{
return F_8 ( V_51 , V_52 , V_53 , true ) ;
}
static int F_14 ( const struct V_50 * V_51 ,
const struct V_50 * V_52 [] , T_2 * V_53 )
{
return F_8 ( V_51 , V_52 , V_53 , false ) ;
}
static int F_15 ( const struct V_50 * V_51 ,
struct V_1 * V_2 , bool V_5 )
{
struct V_50 * V_52 ;
int V_57 ;
bool V_62 = false ;
T_5 V_63 = 0 ;
unsigned long V_64 ;
F_9 (a, attr, rem) {
int type = F_10 ( V_52 ) ;
static const T_6 V_65 [ V_66 + 1 ] = {
[ V_67 ] = sizeof( T_2 ) ,
[ V_68 ] = sizeof( T_6 ) ,
[ V_69 ] = sizeof( T_6 ) ,
[ V_70 ] = 1 ,
[ V_71 ] = 1 ,
[ V_72 ] = 0 ,
[ V_73 ] = 0 ,
[ V_74 ] = 0 ,
[ V_75 ] = - 1 ,
} ;
if ( type > V_66 ) {
F_6 ( L_8 ,
type , V_66 ) ;
return - V_60 ;
}
if ( V_65 [ type ] != F_11 ( V_52 ) &&
V_65 [ type ] != - 1 ) {
F_6 ( L_9
L_10 ,
type , F_11 ( V_52 ) , V_65 [ type ] ) ;
return - V_60 ;
}
switch ( type ) {
case V_67 :
F_16 ( V_2 , V_76 . V_77 ,
F_17 ( V_52 ) , V_5 ) ;
V_63 |= V_78 ;
break;
case V_68 :
F_16 ( V_2 , V_76 . V_79 ,
F_18 ( V_52 ) , V_5 ) ;
break;
case V_69 :
F_16 ( V_2 , V_76 . V_80 ,
F_18 ( V_52 ) , V_5 ) ;
break;
case V_70 :
F_16 ( V_2 , V_76 . V_81 ,
F_19 ( V_52 ) , V_5 ) ;
break;
case V_71 :
F_16 ( V_2 , V_76 . V_82 ,
F_19 ( V_52 ) , V_5 ) ;
V_62 = true ;
break;
case V_72 :
V_63 |= V_83 ;
break;
case V_73 :
V_63 |= V_84 ;
break;
case V_74 :
V_63 |= V_85 ;
break;
case V_75 :
V_63 |= V_86 ;
if ( F_11 ( V_52 ) > sizeof( V_2 -> V_29 -> V_87 ) ) {
F_6 ( L_11 ,
F_11 ( V_52 ) ,
sizeof( V_2 -> V_29 -> V_87 ) ) ;
return - V_60 ;
}
if ( F_11 ( V_52 ) % 4 != 0 ) {
F_6 ( L_12 ,
F_11 ( V_52 ) ) ;
return - V_60 ;
}
if ( ! V_5 ) {
F_16 ( V_2 , V_88 , F_11 ( V_52 ) ,
false ) ;
} else {
if ( V_2 -> V_29 -> V_88 != F_11 ( V_52 ) ) {
F_6 ( L_13 ,
V_2 -> V_29 -> V_88 ,
F_11 ( V_52 ) ) ;
return - V_60 ;
}
F_16 ( V_2 , V_88 , 0xff ,
true ) ;
}
V_64 = ( unsigned long ) F_20 (
(struct V_89 * ) 0 ,
F_11 ( V_52 ) ) ;
F_21 ( V_2 , V_64 ,
F_12 ( V_52 ) , F_11 ( V_52 ) ,
V_5 ) ;
break;
default:
F_6 ( L_14 ,
type ) ;
return - V_60 ;
}
}
F_16 ( V_2 , V_76 . V_63 , V_63 , V_5 ) ;
if ( V_57 > 0 ) {
F_6 ( L_15 , V_57 ) ;
return - V_60 ;
}
if ( ! V_5 ) {
if ( ! V_2 -> V_29 -> V_76 . V_80 ) {
F_6 ( L_16 ) ;
return - V_60 ;
}
if ( ! V_62 ) {
F_6 ( L_17 ) ;
return - V_60 ;
}
}
return 0 ;
}
static int F_22 ( struct V_90 * V_91 ,
const struct V_92 * V_93 ,
const struct V_94 * V_87 ,
int V_95 )
{
if ( V_93 -> V_63 & V_78 &&
F_23 ( V_91 , V_67 , V_93 -> V_77 ) )
return - V_96 ;
if ( V_93 -> V_79 &&
F_24 ( V_91 , V_68 , V_93 -> V_79 ) )
return - V_96 ;
if ( V_93 -> V_80 &&
F_24 ( V_91 , V_69 , V_93 -> V_80 ) )
return - V_96 ;
if ( V_93 -> V_81 &&
F_25 ( V_91 , V_70 , V_93 -> V_81 ) )
return - V_96 ;
if ( F_25 ( V_91 , V_71 , V_93 -> V_82 ) )
return - V_96 ;
if ( ( V_93 -> V_63 & V_83 ) &&
F_26 ( V_91 , V_72 ) )
return - V_96 ;
if ( ( V_93 -> V_63 & V_84 ) &&
F_26 ( V_91 , V_73 ) )
return - V_96 ;
if ( ( V_93 -> V_63 & V_85 ) &&
F_26 ( V_91 , V_74 ) )
return - V_96 ;
if ( V_87 &&
F_27 ( V_91 , V_75 ,
V_95 , V_87 ) )
return - V_96 ;
return 0 ;
}
static int F_28 ( struct V_90 * V_91 ,
const struct V_92 * V_93 ,
const struct V_94 * V_87 ,
int V_95 )
{
struct V_50 * V_55 ;
int V_97 ;
V_55 = F_29 ( V_91 , V_26 ) ;
if ( ! V_55 )
return - V_96 ;
V_97 = F_22 ( V_91 , V_93 , V_87 , V_95 ) ;
if ( V_97 )
return V_97 ;
F_30 ( V_91 , V_55 ) ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 , T_2 * V_56 ,
const struct V_50 * * V_52 , bool V_5 )
{
if ( * V_56 & ( 1 << V_98 ) ) {
T_6 V_99 = F_32 ( V_52 [ V_98 ] ) ;
F_16 ( V_2 , V_100 , V_99 , V_5 ) ;
* V_56 &= ~ ( 1 << V_98 ) ;
}
if ( * V_56 & ( 1 << V_101 ) ) {
T_6 V_102 = F_32 ( V_52 [ V_101 ] ) ;
F_16 ( V_2 , V_102 , V_102 , V_5 ) ;
* V_56 &= ~ ( 1 << V_101 ) ;
}
if ( * V_56 & ( 1 << V_103 ) ) {
F_16 ( V_2 , V_104 . V_105 ,
F_32 ( V_52 [ V_103 ] ) , V_5 ) ;
* V_56 &= ~ ( 1 << V_103 ) ;
}
if ( * V_56 & ( 1 << V_27 ) ) {
T_6 V_106 = F_32 ( V_52 [ V_27 ] ) ;
if ( V_5 )
V_106 = 0xffffffff ;
else if ( V_106 >= V_107 )
return - V_60 ;
F_16 ( V_2 , V_104 . V_106 , V_106 , V_5 ) ;
* V_56 &= ~ ( 1 << V_27 ) ;
} else if ( ! V_5 ) {
F_16 ( V_2 , V_104 . V_106 , V_107 , V_5 ) ;
}
if ( * V_56 & ( 1 << V_108 ) ) {
T_7 V_109 = F_32 ( V_52 [ V_108 ] ) ;
F_16 ( V_2 , V_104 . V_110 , V_109 , V_5 ) ;
* V_56 &= ~ ( 1 << V_108 ) ;
}
if ( * V_56 & ( 1 << V_26 ) ) {
if ( F_15 ( V_52 [ V_26 ] , V_2 ,
V_5 ) )
return - V_60 ;
* V_56 &= ~ ( 1 << V_26 ) ;
}
return 0 ;
}
static int F_33 ( struct V_1 * V_2 , T_2 V_56 ,
const struct V_50 * * V_52 , bool V_5 )
{
int V_97 ;
T_2 V_111 = V_56 ;
V_97 = F_31 ( V_2 , & V_56 , V_52 , V_5 ) ;
if ( V_97 )
return V_97 ;
if ( V_56 & ( 1 << V_14 ) ) {
const struct V_112 * V_113 ;
V_113 = F_12 ( V_52 [ V_14 ] ) ;
F_34 ( V_2 , V_30 . V_34 ,
V_113 -> V_114 , V_115 , V_5 ) ;
F_34 ( V_2 , V_30 . V_116 ,
V_113 -> V_117 , V_115 , V_5 ) ;
V_56 &= ~ ( 1 << V_14 ) ;
}
if ( V_56 & ( 1 << V_118 ) ) {
T_5 V_119 ;
V_119 = F_35 ( V_52 [ V_118 ] ) ;
if ( ! ( V_119 & F_5 ( V_120 ) ) ) {
if ( V_5 )
F_6 ( L_18 ) ;
else
F_6 ( L_19 ) ;
return - V_60 ;
}
F_16 ( V_2 , V_30 . V_119 , V_119 , V_5 ) ;
V_56 &= ~ ( 1 << V_118 ) ;
} else if ( ! V_5 )
F_16 ( V_2 , V_30 . V_119 , F_5 ( 0xffff ) , true ) ;
if ( V_56 & ( 1 << V_28 ) ) {
T_5 V_121 ;
V_121 = F_35 ( V_52 [ V_28 ] ) ;
if ( V_5 ) {
V_121 = F_5 ( 0xffff ) ;
} else if ( F_36 ( V_121 ) < V_122 ) {
F_6 ( L_20 ,
F_36 ( V_121 ) , V_122 ) ;
return - V_60 ;
}
F_16 ( V_2 , V_30 . type , V_121 , V_5 ) ;
V_56 &= ~ ( 1 << V_28 ) ;
} else if ( ! V_5 ) {
F_16 ( V_2 , V_30 . type , F_5 ( V_123 ) , V_5 ) ;
}
if ( V_56 & ( 1 << V_16 ) ) {
const struct V_124 * V_125 ;
V_125 = F_12 ( V_52 [ V_16 ] ) ;
if ( ! V_5 && V_125 -> V_126 > V_127 ) {
F_6 ( L_21 ,
V_125 -> V_126 , V_127 ) ;
return - V_60 ;
}
F_16 ( V_2 , V_36 . V_39 ,
V_125 -> V_128 , V_5 ) ;
F_16 ( V_2 , V_36 . V_129 ,
V_125 -> V_81 , V_5 ) ;
F_16 ( V_2 , V_36 . V_62 ,
V_125 -> V_82 , V_5 ) ;
F_16 ( V_2 , V_36 . V_37 ,
V_125 -> V_126 , V_5 ) ;
F_16 ( V_2 , V_130 . V_131 . V_34 ,
V_125 -> V_79 , V_5 ) ;
F_16 ( V_2 , V_130 . V_131 . V_116 ,
V_125 -> V_80 , V_5 ) ;
V_56 &= ~ ( 1 << V_16 ) ;
}
if ( V_56 & ( 1 << V_17 ) ) {
const struct V_132 * V_133 ;
V_133 = F_12 ( V_52 [ V_17 ] ) ;
if ( ! V_5 && V_133 -> V_134 > V_127 ) {
F_6 ( L_22 ,
V_133 -> V_134 , V_127 ) ;
return - V_60 ;
}
if ( ! V_5 && V_133 -> V_135 & F_37 ( 0xFFF00000 ) ) {
F_6 ( L_23 ,
F_38 ( V_133 -> V_135 ) , ( 1 << 20 ) - 1 ) ;
return - V_60 ;
}
F_16 ( V_2 , V_136 . V_137 ,
V_133 -> V_135 , V_5 ) ;
F_16 ( V_2 , V_36 . V_39 ,
V_133 -> V_138 , V_5 ) ;
F_16 ( V_2 , V_36 . V_129 ,
V_133 -> V_139 , V_5 ) ;
F_16 ( V_2 , V_36 . V_62 ,
V_133 -> V_140 , V_5 ) ;
F_16 ( V_2 , V_36 . V_37 ,
V_133 -> V_134 , V_5 ) ;
F_34 ( V_2 , V_136 . V_131 . V_34 ,
V_133 -> V_141 ,
sizeof( V_2 -> V_29 -> V_136 . V_131 . V_34 ) ,
V_5 ) ;
F_34 ( V_2 , V_136 . V_131 . V_116 ,
V_133 -> V_142 ,
sizeof( V_2 -> V_29 -> V_136 . V_131 . V_116 ) ,
V_5 ) ;
V_56 &= ~ ( 1 << V_17 ) ;
}
if ( V_56 & ( 1 << V_24 ) ) {
const struct V_143 * V_144 ;
V_144 = F_12 ( V_52 [ V_24 ] ) ;
if ( ! V_5 && ( V_144 -> V_145 & F_5 ( 0xff00 ) ) ) {
F_6 ( L_24 ,
V_144 -> V_145 ) ;
return - V_60 ;
}
F_16 ( V_2 , V_130 . V_131 . V_34 ,
V_144 -> V_146 , V_5 ) ;
F_16 ( V_2 , V_130 . V_131 . V_116 ,
V_144 -> V_147 , V_5 ) ;
F_16 ( V_2 , V_36 . V_39 ,
F_36 ( V_144 -> V_145 ) , V_5 ) ;
F_34 ( V_2 , V_130 . V_148 . V_149 ,
V_144 -> V_150 , V_115 , V_5 ) ;
F_34 ( V_2 , V_130 . V_148 . V_151 ,
V_144 -> V_152 , V_115 , V_5 ) ;
V_56 &= ~ ( 1 << V_24 ) ;
}
if ( V_56 & ( 1 << V_18 ) ) {
const struct V_153 * V_154 ;
V_154 = F_12 ( V_52 [ V_18 ] ) ;
F_16 ( V_2 , V_33 . V_34 , V_154 -> V_155 , V_5 ) ;
F_16 ( V_2 , V_33 . V_116 , V_154 -> V_156 , V_5 ) ;
V_56 &= ~ ( 1 << V_18 ) ;
}
if ( V_56 & ( 1 << V_19 ) ) {
if ( V_111 & ( 1 << V_16 ) ) {
F_16 ( V_2 , V_33 . V_157 ,
F_35 ( V_52 [ V_19 ] ) ,
V_5 ) ;
} else {
F_16 ( V_2 , V_33 . V_157 ,
F_35 ( V_52 [ V_19 ] ) ,
V_5 ) ;
}
V_56 &= ~ ( 1 << V_19 ) ;
}
if ( V_56 & ( 1 << V_20 ) ) {
const struct V_158 * V_159 ;
V_159 = F_12 ( V_52 [ V_20 ] ) ;
F_16 ( V_2 , V_33 . V_34 , V_159 -> V_160 , V_5 ) ;
F_16 ( V_2 , V_33 . V_116 , V_159 -> V_161 , V_5 ) ;
V_56 &= ~ ( 1 << V_20 ) ;
}
if ( V_56 & ( 1 << V_21 ) ) {
const struct V_162 * V_163 ;
V_163 = F_12 ( V_52 [ V_21 ] ) ;
F_16 ( V_2 , V_33 . V_34 , V_163 -> V_164 , V_5 ) ;
F_16 ( V_2 , V_33 . V_116 , V_163 -> V_165 , V_5 ) ;
V_56 &= ~ ( 1 << V_21 ) ;
}
if ( V_56 & ( 1 << V_22 ) ) {
const struct V_166 * V_167 ;
V_167 = F_12 ( V_52 [ V_22 ] ) ;
F_16 ( V_2 , V_33 . V_34 ,
F_5 ( V_167 -> V_168 ) , V_5 ) ;
F_16 ( V_2 , V_33 . V_116 ,
F_5 ( V_167 -> V_169 ) , V_5 ) ;
V_56 &= ~ ( 1 << V_22 ) ;
}
if ( V_56 & ( 1 << V_23 ) ) {
const struct V_170 * V_171 ;
V_171 = F_12 ( V_52 [ V_23 ] ) ;
F_16 ( V_2 , V_33 . V_34 ,
F_5 ( V_171 -> V_172 ) , V_5 ) ;
F_16 ( V_2 , V_33 . V_116 ,
F_5 ( V_171 -> V_173 ) , V_5 ) ;
V_56 &= ~ ( 1 << V_23 ) ;
}
if ( V_56 & ( 1 << V_25 ) ) {
const struct V_174 * V_175 ;
V_175 = F_12 ( V_52 [ V_25 ] ) ;
F_34 ( V_2 , V_136 . V_176 . V_177 ,
V_175 -> V_178 ,
sizeof( V_2 -> V_29 -> V_136 . V_176 . V_177 ) ,
V_5 ) ;
F_34 ( V_2 , V_136 . V_176 . V_179 ,
V_175 -> V_180 , V_115 , V_5 ) ;
F_34 ( V_2 , V_136 . V_176 . V_181 ,
V_175 -> V_182 , V_115 , V_5 ) ;
V_56 &= ~ ( 1 << V_25 ) ;
}
if ( V_56 != 0 )
return - V_60 ;
return 0 ;
}
static void F_39 ( struct V_50 * V_51 , T_3 V_183 , bool V_184 )
{
struct V_50 * V_55 ;
int V_57 ;
F_9 (nla, attr, rem) {
if ( V_184 && V_61 [ F_10 ( V_55 ) ] == - 1 )
F_39 ( V_55 , V_183 , false ) ;
else
memset ( F_12 ( V_55 ) , V_183 , F_11 ( V_55 ) ) ;
}
}
static void F_40 ( struct V_50 * V_51 , T_3 V_183 )
{
F_39 ( V_51 , V_183 , true ) ;
}
int F_41 ( struct V_1 * V_2 ,
const struct V_50 * V_29 ,
const struct V_50 * V_10 )
{
const struct V_50 * V_52 [ V_59 + 1 ] ;
const struct V_50 * V_185 ;
struct V_50 * V_186 = NULL ;
T_2 V_11 = 0 ;
T_2 V_12 = 0 ;
bool V_187 = false ;
int V_97 ;
V_97 = F_14 ( V_29 , V_52 , & V_11 ) ;
if ( V_97 )
return V_97 ;
if ( ( V_11 & ( 1 << V_14 ) ) &&
( V_11 & ( 1 << V_28 ) ) &&
( F_35 ( V_52 [ V_28 ] ) == F_5 ( V_188 ) ) ) {
T_5 V_119 ;
if ( ! ( ( V_11 & ( 1 << V_118 ) ) &&
( V_11 & ( 1 << V_189 ) ) ) ) {
F_6 ( L_25 ) ;
return - V_60 ;
}
V_11 &= ~ ( 1 << V_28 ) ;
V_119 = F_35 ( V_52 [ V_118 ] ) ;
V_185 = V_52 [ V_189 ] ;
V_11 &= ~ ( 1 << V_189 ) ;
V_187 = true ;
if ( V_119 & F_5 ( V_120 ) ) {
V_97 = F_14 ( V_185 , V_52 , & V_11 ) ;
if ( V_97 )
return V_97 ;
} else if ( ! V_119 ) {
if ( F_11 ( V_185 ) ) {
F_6 ( L_26 ) ;
return - V_60 ;
}
} else {
F_6 ( L_27 ) ;
return - V_60 ;
}
}
V_97 = F_33 ( V_2 , V_11 , V_52 , false ) ;
if ( V_97 )
return V_97 ;
if ( V_2 -> V_10 && ! V_10 ) {
V_186 = F_42 ( V_29 , F_43 ( F_11 ( V_29 ) ) ,
V_190 ) ;
if ( ! V_186 )
return - V_191 ;
F_40 ( V_186 , 0xff ) ;
if ( V_2 -> V_29 -> V_76 . V_80 )
F_44 ( V_2 , V_76 , 0xff , true ) ;
V_10 = V_186 ;
}
if ( V_10 ) {
V_97 = F_13 ( V_10 , V_52 , & V_12 ) ;
if ( V_97 )
goto V_192;
if ( V_12 & 1 << V_189 ) {
T_5 V_121 = 0 ;
T_5 V_119 = 0 ;
if ( ! V_187 ) {
F_6 ( L_28 ) ;
V_97 = - V_60 ;
goto V_192;
}
V_12 &= ~ ( 1 << V_189 ) ;
if ( V_52 [ V_28 ] )
V_121 = F_35 ( V_52 [ V_28 ] ) ;
if ( V_121 == F_5 ( 0xffff ) ) {
V_12 &= ~ ( 1 << V_28 ) ;
V_185 = V_52 [ V_189 ] ;
V_97 = F_13 ( V_185 , V_52 , & V_12 ) ;
if ( V_97 )
goto V_192;
} else {
F_6 ( L_29 ,
F_36 ( V_121 ) ) ;
V_97 = - V_60 ;
goto V_192;
}
if ( V_52 [ V_118 ] )
V_119 = F_35 ( V_52 [ V_118 ] ) ;
if ( ! ( V_119 & F_5 ( V_120 ) ) ) {
F_6 ( L_30 , F_36 ( V_119 ) ) ;
V_97 = - V_60 ;
goto V_192;
}
}
V_97 = F_33 ( V_2 , V_12 , V_52 , true ) ;
if ( V_97 )
goto V_192;
}
if ( ! F_4 ( V_2 , V_11 , V_12 ) )
V_97 = - V_60 ;
V_192:
F_45 ( V_186 ) ;
return V_97 ;
}
int F_46 ( const struct V_50 * V_51 ,
struct V_89 * V_29 )
{
const struct V_50 * V_52 [ V_59 + 1 ] ;
struct V_1 V_2 ;
T_2 V_56 = 0 ;
int V_97 ;
V_97 = F_14 ( V_51 , V_52 , & V_56 ) ;
if ( V_97 )
return - V_60 ;
memset ( & V_2 , 0 , sizeof( V_2 ) ) ;
V_2 . V_29 = V_29 ;
V_29 -> V_104 . V_106 = V_107 ;
return F_31 ( & V_2 , & V_56 , V_52 , false ) ;
}
int F_47 ( const struct V_89 * V_193 ,
const struct V_89 * V_93 , struct V_90 * V_91 )
{
struct V_112 * V_113 ;
struct V_50 * V_55 , * V_185 ;
bool V_5 = ( V_193 != V_93 ) ;
if ( F_48 ( V_91 , V_101 , V_93 -> V_102 ) )
goto V_194;
if ( F_48 ( V_91 , V_98 , V_93 -> V_100 ) )
goto V_194;
if ( F_48 ( V_91 , V_103 , V_93 -> V_104 . V_105 ) )
goto V_194;
if ( ( V_193 -> V_76 . V_80 || V_5 ) ) {
const struct V_94 * V_195 = NULL ;
if ( V_93 -> V_76 . V_63 & V_86 )
V_195 = F_20 ( V_93 , V_193 -> V_88 ) ;
if ( F_28 ( V_91 , & V_93 -> V_76 , V_195 ,
V_193 -> V_88 ) )
goto V_194;
}
if ( V_193 -> V_104 . V_106 == V_107 ) {
if ( V_5 && ( V_93 -> V_104 . V_106 == 0xffff ) )
if ( F_48 ( V_91 , V_27 , 0xffffffff ) )
goto V_194;
} else {
T_4 V_196 ;
V_196 = ! V_5 ? 0 : 0xffff ;
if ( F_48 ( V_91 , V_27 ,
( V_196 << 16 ) | V_93 -> V_104 . V_106 ) )
goto V_194;
}
if ( F_48 ( V_91 , V_108 , V_93 -> V_104 . V_110 ) )
goto V_194;
V_55 = F_49 ( V_91 , V_14 , sizeof( * V_113 ) ) ;
if ( ! V_55 )
goto V_194;
V_113 = F_12 ( V_55 ) ;
F_50 ( V_113 -> V_114 , V_93 -> V_30 . V_34 ) ;
F_50 ( V_113 -> V_117 , V_93 -> V_30 . V_116 ) ;
if ( V_193 -> V_30 . V_119 || V_193 -> V_30 . type == F_5 ( V_188 ) ) {
T_5 V_121 ;
V_121 = ! V_5 ? F_5 ( V_188 ) : F_5 ( 0xffff ) ;
if ( F_51 ( V_91 , V_28 , V_121 ) ||
F_51 ( V_91 , V_118 , V_93 -> V_30 . V_119 ) )
goto V_194;
V_185 = F_29 ( V_91 , V_189 ) ;
if ( ! V_193 -> V_30 . V_119 )
goto V_197;
} else
V_185 = NULL ;
if ( V_193 -> V_30 . type == F_5 ( V_123 ) ) {
if ( V_5 && V_93 -> V_30 . type )
if ( F_51 ( V_91 , V_28 ,
V_93 -> V_30 . type ) )
goto V_194;
goto V_197;
}
if ( F_51 ( V_91 , V_28 , V_93 -> V_30 . type ) )
goto V_194;
if ( V_193 -> V_30 . type == F_5 ( V_35 ) ) {
struct V_124 * V_125 ;
V_55 = F_49 ( V_91 , V_16 , sizeof( * V_125 ) ) ;
if ( ! V_55 )
goto V_194;
V_125 = F_12 ( V_55 ) ;
V_125 -> V_79 = V_93 -> V_130 . V_131 . V_34 ;
V_125 -> V_80 = V_93 -> V_130 . V_131 . V_116 ;
V_125 -> V_128 = V_93 -> V_36 . V_39 ;
V_125 -> V_81 = V_93 -> V_36 . V_129 ;
V_125 -> V_82 = V_93 -> V_36 . V_62 ;
V_125 -> V_126 = V_93 -> V_36 . V_37 ;
} else if ( V_193 -> V_30 . type == F_5 ( V_44 ) ) {
struct V_132 * V_133 ;
V_55 = F_49 ( V_91 , V_17 , sizeof( * V_133 ) ) ;
if ( ! V_55 )
goto V_194;
V_133 = F_12 ( V_55 ) ;
memcpy ( V_133 -> V_141 , & V_93 -> V_136 . V_131 . V_34 ,
sizeof( V_133 -> V_141 ) ) ;
memcpy ( V_133 -> V_142 , & V_93 -> V_136 . V_131 . V_116 ,
sizeof( V_133 -> V_142 ) ) ;
V_133 -> V_135 = V_93 -> V_136 . V_137 ;
V_133 -> V_138 = V_93 -> V_36 . V_39 ;
V_133 -> V_139 = V_93 -> V_36 . V_129 ;
V_133 -> V_140 = V_93 -> V_36 . V_62 ;
V_133 -> V_134 = V_93 -> V_36 . V_37 ;
} else if ( V_193 -> V_30 . type == F_5 ( V_31 ) ||
V_193 -> V_30 . type == F_5 ( V_32 ) ) {
struct V_143 * V_144 ;
V_55 = F_49 ( V_91 , V_24 , sizeof( * V_144 ) ) ;
if ( ! V_55 )
goto V_194;
V_144 = F_12 ( V_55 ) ;
memset ( V_144 , 0 , sizeof( struct V_143 ) ) ;
V_144 -> V_146 = V_93 -> V_130 . V_131 . V_34 ;
V_144 -> V_147 = V_93 -> V_130 . V_131 . V_116 ;
V_144 -> V_145 = F_5 ( V_93 -> V_36 . V_39 ) ;
F_50 ( V_144 -> V_150 , V_93 -> V_130 . V_148 . V_149 ) ;
F_50 ( V_144 -> V_152 , V_93 -> V_130 . V_148 . V_151 ) ;
}
if ( ( V_193 -> V_30 . type == F_5 ( V_35 ) ||
V_193 -> V_30 . type == F_5 ( V_44 ) ) &&
V_193 -> V_36 . V_37 != V_38 ) {
if ( V_193 -> V_36 . V_39 == V_42 ) {
struct V_153 * V_154 ;
V_55 = F_49 ( V_91 , V_18 , sizeof( * V_154 ) ) ;
if ( ! V_55 )
goto V_194;
V_154 = F_12 ( V_55 ) ;
V_154 -> V_155 = V_93 -> V_33 . V_34 ;
V_154 -> V_156 = V_93 -> V_33 . V_116 ;
if ( F_51 ( V_91 , V_19 ,
V_93 -> V_33 . V_157 ) )
goto V_194;
} else if ( V_193 -> V_36 . V_39 == V_40 ) {
struct V_158 * V_159 ;
V_55 = F_49 ( V_91 , V_20 , sizeof( * V_159 ) ) ;
if ( ! V_55 )
goto V_194;
V_159 = F_12 ( V_55 ) ;
V_159 -> V_160 = V_93 -> V_33 . V_34 ;
V_159 -> V_161 = V_93 -> V_33 . V_116 ;
} else if ( V_193 -> V_36 . V_39 == V_41 ) {
struct V_162 * V_163 ;
V_55 = F_49 ( V_91 , V_21 , sizeof( * V_163 ) ) ;
if ( ! V_55 )
goto V_194;
V_163 = F_12 ( V_55 ) ;
V_163 -> V_164 = V_93 -> V_33 . V_34 ;
V_163 -> V_165 = V_93 -> V_33 . V_116 ;
} else if ( V_193 -> V_30 . type == F_5 ( V_35 ) &&
V_193 -> V_36 . V_39 == V_43 ) {
struct V_166 * V_167 ;
V_55 = F_49 ( V_91 , V_22 , sizeof( * V_167 ) ) ;
if ( ! V_55 )
goto V_194;
V_167 = F_12 ( V_55 ) ;
V_167 -> V_168 = F_36 ( V_93 -> V_33 . V_34 ) ;
V_167 -> V_169 = F_36 ( V_93 -> V_33 . V_116 ) ;
} else if ( V_193 -> V_30 . type == F_5 ( V_44 ) &&
V_193 -> V_36 . V_39 == V_45 ) {
struct V_170 * V_171 ;
V_55 = F_49 ( V_91 , V_23 ,
sizeof( * V_171 ) ) ;
if ( ! V_55 )
goto V_194;
V_171 = F_12 ( V_55 ) ;
V_171 -> V_172 = F_36 ( V_93 -> V_33 . V_34 ) ;
V_171 -> V_173 = F_36 ( V_93 -> V_33 . V_116 ) ;
if ( V_171 -> V_172 == V_46 ||
V_171 -> V_172 == V_47 ) {
struct V_174 * V_175 ;
V_55 = F_49 ( V_91 , V_25 , sizeof( * V_175 ) ) ;
if ( ! V_55 )
goto V_194;
V_175 = F_12 ( V_55 ) ;
memcpy ( V_175 -> V_178 , & V_93 -> V_136 . V_176 . V_177 ,
sizeof( V_175 -> V_178 ) ) ;
F_50 ( V_175 -> V_180 , V_93 -> V_136 . V_176 . V_179 ) ;
F_50 ( V_175 -> V_182 , V_93 -> V_136 . V_176 . V_181 ) ;
}
}
}
V_197:
if ( V_185 )
F_30 ( V_91 , V_185 ) ;
return 0 ;
V_194:
return - V_96 ;
}
struct V_198 * F_52 ( int V_4 )
{
struct V_198 * V_199 ;
if ( V_4 > V_200 )
return F_53 ( - V_60 ) ;
V_199 = F_54 ( sizeof( * V_199 ) + V_4 , V_190 ) ;
if ( ! V_199 )
return F_53 ( - V_191 ) ;
V_199 -> V_201 = 0 ;
return V_199 ;
}
void F_55 ( struct V_198 * V_202 )
{
F_56 ( V_202 , V_203 ) ;
}
static struct V_50 * F_57 ( struct V_198 * * V_199 ,
int V_204 )
{
struct V_198 * V_205 ;
int V_206 ;
int V_207 = F_58 ( V_204 ) ;
int V_208 = F_59 ( struct V_198 , V_209 ) +
( * V_199 ) -> V_201 ;
if ( V_207 <= ( F_60 ( * V_199 ) - V_208 ) )
goto V_210;
V_206 = F_60 ( * V_199 ) * 2 ;
if ( V_206 > V_200 ) {
if ( ( V_200 - V_208 ) < V_207 )
return F_53 ( - V_96 ) ;
V_206 = V_200 ;
}
V_205 = F_52 ( V_206 ) ;
if ( F_61 ( V_205 ) )
return ( void * ) V_205 ;
memcpy ( V_205 -> V_209 , ( * V_199 ) -> V_209 , ( * V_199 ) -> V_201 ) ;
V_205 -> V_201 = ( * V_199 ) -> V_201 ;
F_45 ( * V_199 ) ;
* V_199 = V_205 ;
V_210:
( * V_199 ) -> V_201 += V_207 ;
return (struct V_50 * ) ( ( unsigned char * ) ( * V_199 ) + V_208 ) ;
}
static struct V_50 * F_62 ( struct V_198 * * V_199 ,
int V_211 , void * V_212 , int V_213 )
{
struct V_50 * V_52 ;
V_52 = F_57 ( V_199 , F_63 ( V_213 ) ) ;
if ( F_61 ( V_52 ) )
return V_52 ;
V_52 -> F_10 = V_211 ;
V_52 -> F_11 = F_63 ( V_213 ) ;
if ( V_212 )
memcpy ( F_12 ( V_52 ) , V_212 , V_213 ) ;
memset ( ( unsigned char * ) V_52 + V_52 -> F_11 , 0 , F_64 ( V_213 ) ) ;
return V_52 ;
}
static int F_65 ( struct V_198 * * V_199 , int V_211 ,
void * V_212 , int V_213 )
{
struct V_50 * V_52 ;
V_52 = F_62 ( V_199 , V_211 , V_212 , V_213 ) ;
if ( F_61 ( V_52 ) )
return F_66 ( V_52 ) ;
return 0 ;
}
static inline int F_67 ( struct V_198 * * V_199 ,
int V_211 )
{
int V_214 = ( * V_199 ) -> V_201 ;
int V_97 ;
V_97 = F_65 ( V_199 , V_211 , NULL , 0 ) ;
if ( V_97 )
return V_97 ;
return V_214 ;
}
static inline void F_68 ( struct V_198 * V_199 ,
int V_215 )
{
struct V_50 * V_52 = (struct V_50 * ) ( ( unsigned char * ) V_199 -> V_209 +
V_215 ) ;
V_52 -> F_11 = V_199 -> V_201 - V_215 ;
}
static int F_69 ( const struct V_50 * V_51 ,
const struct V_89 * V_29 , int V_216 ,
struct V_198 * * V_199 )
{
const struct V_50 * V_56 [ V_217 + 1 ] ;
const struct V_50 * V_218 , * V_209 ;
const struct V_50 * V_52 ;
int V_57 , V_8 , V_97 , V_219 ;
memset ( V_56 , 0 , sizeof( V_56 ) ) ;
F_9 (a, attr, rem) {
int type = F_10 ( V_52 ) ;
if ( ! type || type > V_217 || V_56 [ type ] )
return - V_60 ;
V_56 [ type ] = V_52 ;
}
if ( V_57 )
return - V_60 ;
V_218 = V_56 [ V_220 ] ;
if ( ! V_218 || F_11 ( V_218 ) != sizeof( T_6 ) )
return - V_60 ;
V_209 = V_56 [ V_221 ] ;
if ( ! V_209 || ( F_11 ( V_209 ) && F_11 ( V_209 ) < V_222 ) )
return - V_60 ;
V_8 = F_67 ( V_199 , V_223 ) ;
if ( V_8 < 0 )
return V_8 ;
V_97 = F_65 ( V_199 , V_220 ,
F_12 ( V_218 ) , sizeof( T_6 ) ) ;
if ( V_97 )
return V_97 ;
V_219 = F_67 ( V_199 , V_221 ) ;
if ( V_219 < 0 )
return V_219 ;
V_97 = F_70 ( V_209 , V_29 , V_216 + 1 , V_199 ) ;
if ( V_97 )
return V_97 ;
F_68 ( * V_199 , V_219 ) ;
F_68 ( * V_199 , V_8 ) ;
return 0 ;
}
static int F_71 ( const struct V_89 * V_224 )
{
if ( ( V_224 -> V_30 . type == F_5 ( V_35 ) ||
V_224 -> V_30 . type == F_5 ( V_44 ) ) &&
( V_224 -> V_33 . V_34 || V_224 -> V_33 . V_116 ) )
return 0 ;
return - V_60 ;
}
void F_72 ( struct V_1 * V_2 ,
struct V_89 * V_29 ,
struct V_225 * V_10 )
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
static int F_73 ( const struct V_50 * V_51 ,
struct V_198 * * V_199 )
{
struct V_1 V_2 ;
struct V_89 V_29 ;
struct V_226 * V_227 ;
struct V_50 * V_52 ;
int V_97 , V_8 ;
F_72 ( & V_2 , & V_29 , NULL ) ;
V_97 = F_15 ( F_12 ( V_51 ) , & V_2 , false ) ;
if ( V_97 )
return V_97 ;
if ( V_29 . V_88 ) {
struct V_94 * V_228 = F_20 ( & V_29 ,
V_29 . V_88 ) ;
int V_229 = V_29 . V_88 ;
bool V_230 = false ;
while ( V_229 > 0 ) {
int V_213 ;
if ( V_229 < sizeof( * V_228 ) )
return - V_60 ;
V_213 = sizeof( * V_228 ) + V_228 -> V_231 * 4 ;
if ( V_213 > V_229 )
return - V_60 ;
V_230 |= ! ! ( V_228 -> type & V_232 ) ;
V_228 = (struct V_94 * ) ( ( T_3 * ) V_228 + V_213 ) ;
V_229 -= V_213 ;
} ;
V_29 . V_76 . V_63 |= V_230 ? V_233 : 0 ;
} ;
V_8 = F_67 ( V_199 , V_234 ) ;
if ( V_8 < 0 )
return V_8 ;
V_52 = F_62 ( V_199 , V_235 , NULL ,
sizeof( * V_227 ) + V_29 . V_88 ) ;
if ( F_61 ( V_52 ) )
return F_66 ( V_52 ) ;
V_227 = F_12 ( V_52 ) ;
V_227 -> V_236 = V_29 . V_76 ;
V_227 -> V_237 = V_29 . V_88 ;
if ( V_227 -> V_237 ) {
memcpy ( ( V_227 + 1 ) , F_20 ( & V_29 , V_29 . V_88 ) ,
V_29 . V_88 ) ;
V_227 -> V_238 = (struct V_94 * ) ( V_227 + 1 ) ;
} else {
V_227 -> V_238 = NULL ;
}
F_68 ( * V_199 , V_8 ) ;
return V_97 ;
}
static int F_74 ( const struct V_50 * V_52 ,
const struct V_89 * V_224 ,
struct V_198 * * V_199 ,
bool * V_239 )
{
const struct V_50 * V_240 = F_12 ( V_52 ) ;
int V_241 = F_10 ( V_240 ) ;
if ( F_43 ( F_11 ( V_240 ) ) != F_11 ( V_52 ) )
return - V_60 ;
if ( V_241 > V_59 ||
( V_61 [ V_241 ] != F_11 ( V_240 ) &&
V_61 [ V_241 ] != - 1 ) )
return - V_60 ;
switch ( V_241 ) {
const struct V_124 * V_125 ;
const struct V_132 * V_133 ;
int V_97 ;
case V_103 :
case V_108 :
case V_14 :
break;
case V_26 :
* V_239 = true ;
V_97 = F_73 ( V_52 , V_199 ) ;
if ( V_97 )
return V_97 ;
break;
case V_16 :
if ( V_224 -> V_30 . type != F_5 ( V_35 ) )
return - V_60 ;
if ( ! V_224 -> V_36 . V_39 )
return - V_60 ;
V_125 = F_12 ( V_240 ) ;
if ( V_125 -> V_128 != V_224 -> V_36 . V_39 )
return - V_60 ;
if ( V_125 -> V_126 != V_224 -> V_36 . V_37 )
return - V_60 ;
break;
case V_17 :
if ( V_224 -> V_30 . type != F_5 ( V_44 ) )
return - V_60 ;
if ( ! V_224 -> V_36 . V_39 )
return - V_60 ;
V_133 = F_12 ( V_240 ) ;
if ( V_133 -> V_138 != V_224 -> V_36 . V_39 )
return - V_60 ;
if ( V_133 -> V_134 != V_224 -> V_36 . V_37 )
return - V_60 ;
if ( F_38 ( V_133 -> V_135 ) & 0xFFF00000 )
return - V_60 ;
break;
case V_18 :
if ( V_224 -> V_36 . V_39 != V_42 )
return - V_60 ;
return F_71 ( V_224 ) ;
case V_20 :
if ( V_224 -> V_36 . V_39 != V_40 )
return - V_60 ;
return F_71 ( V_224 ) ;
case V_21 :
if ( V_224 -> V_36 . V_39 != V_41 )
return - V_60 ;
return F_71 ( V_224 ) ;
default:
return - V_60 ;
}
return 0 ;
}
static int F_75 ( const struct V_50 * V_51 )
{
static const struct V_242 V_243 [ V_244 + 1 ] = {
[ V_245 ] = { . type = V_246 } ,
[ V_247 ] = { . type = V_248 } ,
} ;
struct V_50 * V_52 [ V_244 + 1 ] ;
int error ;
error = F_76 ( V_52 , V_244 ,
V_51 , V_243 ) ;
if ( error )
return error ;
if ( ! V_52 [ V_245 ] ||
! F_32 ( V_52 [ V_245 ] ) )
return - V_60 ;
return 0 ;
}
static int F_77 ( const struct V_50 * V_249 ,
struct V_198 * * V_199 )
{
int V_250 = F_58 ( V_249 -> F_11 ) ;
struct V_50 * V_251 ;
V_251 = F_57 ( V_199 , V_249 -> F_11 ) ;
if ( F_61 ( V_251 ) )
return F_66 ( V_251 ) ;
memcpy ( V_251 , V_249 , V_250 ) ;
return 0 ;
}
int F_70 ( const struct V_50 * V_51 ,
const struct V_89 * V_29 ,
int V_216 ,
struct V_198 * * V_199 )
{
const struct V_50 * V_52 ;
int V_57 , V_97 ;
if ( V_216 >= V_252 )
return - V_253 ;
F_9 (a, attr, rem) {
static const T_6 V_254 [ V_255 + 1 ] = {
[ V_256 ] = sizeof( T_6 ) ,
[ V_257 ] = sizeof( T_6 ) ,
[ V_258 ] = ( T_6 ) - 1 ,
[ V_259 ] = sizeof( struct V_260 ) ,
[ V_261 ] = 0 ,
[ V_234 ] = ( T_6 ) - 1 ,
[ V_223 ] = ( T_6 ) - 1 ,
[ V_262 ] = sizeof(struct V_263 )
} ;
const struct V_260 * V_264 ;
int type = F_10 ( V_52 ) ;
bool V_265 ;
if ( type > V_255 ||
( V_254 [ type ] != F_11 ( V_52 ) &&
V_254 [ type ] != ( T_6 ) - 1 ) )
return - V_60 ;
V_265 = false ;
switch ( type ) {
case V_266 :
return - V_60 ;
case V_258 :
V_97 = F_75 ( V_52 ) ;
if ( V_97 )
return V_97 ;
break;
case V_256 :
if ( F_32 ( V_52 ) >= V_107 )
return - V_60 ;
break;
case V_262 : {
const struct V_263 * V_267 = F_12 ( V_52 ) ;
switch ( V_267 -> V_268 ) {
case V_269 :
break;
default:
return - V_60 ;
}
break;
}
case V_261 :
break;
case V_259 :
V_264 = F_12 ( V_52 ) ;
if ( V_264 -> V_270 != F_5 ( V_188 ) )
return - V_60 ;
if ( ! ( V_264 -> V_271 & F_5 ( V_120 ) ) )
return - V_60 ;
break;
case V_257 :
break;
case V_234 :
V_97 = F_74 ( V_52 , V_29 , V_199 , & V_265 ) ;
if ( V_97 )
return V_97 ;
break;
case V_223 :
V_97 = F_69 ( V_52 , V_29 , V_216 , V_199 ) ;
if ( V_97 )
return V_97 ;
V_265 = true ;
break;
default:
return - V_60 ;
}
if ( ! V_265 ) {
V_97 = F_77 ( V_52 , V_199 ) ;
if ( V_97 )
return V_97 ;
}
}
if ( V_57 > 0 )
return - V_60 ;
return 0 ;
}
static int F_78 ( const struct V_50 * V_51 , struct V_90 * V_91 )
{
const struct V_50 * V_52 ;
struct V_50 * V_8 ;
int V_97 = 0 , V_57 ;
V_8 = F_29 ( V_91 , V_223 ) ;
if ( ! V_8 )
return - V_96 ;
F_9 (a, attr, rem) {
int type = F_10 ( V_52 ) ;
struct V_50 * V_272 ;
switch ( type ) {
case V_220 :
if ( F_27 ( V_91 , V_220 ,
sizeof( T_6 ) , F_12 ( V_52 ) ) )
return - V_96 ;
break;
case V_221 :
V_272 = F_29 ( V_91 , V_221 ) ;
if ( ! V_272 )
return - V_96 ;
V_97 = F_79 ( F_12 ( V_52 ) , F_11 ( V_52 ) , V_91 ) ;
if ( V_97 )
return V_97 ;
F_30 ( V_91 , V_272 ) ;
break;
}
}
F_30 ( V_91 , V_8 ) ;
return V_97 ;
}
static int F_80 ( const struct V_50 * V_52 , struct V_90 * V_91 )
{
const struct V_50 * V_240 = F_12 ( V_52 ) ;
int V_241 = F_10 ( V_240 ) ;
struct V_50 * V_8 ;
int V_97 ;
switch ( V_241 ) {
case V_235 : {
struct V_226 * V_227 = F_12 ( V_240 ) ;
V_8 = F_29 ( V_91 , V_234 ) ;
if ( ! V_8 )
return - V_96 ;
V_97 = F_28 ( V_91 , & V_227 -> V_236 ,
V_227 -> V_237 ?
V_227 -> V_238 : NULL ,
V_227 -> V_237 ) ;
if ( V_97 )
return V_97 ;
F_30 ( V_91 , V_8 ) ;
break;
}
default:
if ( F_27 ( V_91 , V_234 , F_11 ( V_52 ) , V_240 ) )
return - V_96 ;
break;
}
return 0 ;
}
int F_79 ( const struct V_50 * V_51 , int V_213 , struct V_90 * V_91 )
{
const struct V_50 * V_52 ;
int V_57 , V_97 ;
F_81 (a, attr, len, rem) {
int type = F_10 ( V_52 ) ;
switch ( type ) {
case V_234 :
V_97 = F_80 ( V_52 , V_91 ) ;
if ( V_97 )
return V_97 ;
break;
case V_223 :
V_97 = F_78 ( V_52 , V_91 ) ;
if ( V_97 )
return V_97 ;
break;
default:
if ( F_27 ( V_91 , type , F_11 ( V_52 ) , F_12 ( V_52 ) ) )
return - V_96 ;
break;
}
}
return 0 ;
}
