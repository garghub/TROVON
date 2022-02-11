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
if ( V_2 -> V_29 -> V_44 . V_45 . V_46 ==
F_6 ( V_47 ) ||
V_2 -> V_29 -> V_44 . V_45 . V_46 == F_6 ( V_48 ) ) {
V_13 |= 1 << V_25 ;
if ( V_2 -> V_10 && ( V_2 -> V_10 -> V_29 . V_44 . V_45 . V_46 == F_6 ( 0xffff ) ) )
V_15 |= 1 << V_25 ;
}
}
}
}
if ( ( V_11 & V_13 ) != V_13 ) {
F_7 ( L_1 ,
V_11 , V_13 ) ;
return false ;
}
if ( ( V_12 & V_15 ) != V_12 ) {
F_7 ( L_2 ,
V_12 , V_15 ) ;
return false ;
}
return true ;
}
static bool F_8 ( const T_4 * V_49 , T_1 V_4 )
{
int V_50 ;
if ( ! V_49 )
return false ;
for ( V_50 = 0 ; V_50 < V_4 ; V_50 ++ )
if ( V_49 [ V_50 ] )
return false ;
return true ;
}
static bool F_9 ( const T_4 * V_49 , T_1 V_4 )
{
int V_50 ;
if ( ! V_49 )
return false ;
for ( V_50 = 0 ; V_50 < V_4 ; V_50 ++ )
if ( V_49 [ V_50 ] != 0xff )
return false ;
return true ;
}
static int F_10 ( const struct V_51 * V_52 ,
const struct V_51 * V_53 [] ,
T_3 * V_54 , bool V_55 )
{
const struct V_51 * V_56 ;
T_3 V_57 ;
int V_58 ;
V_57 = * V_54 ;
F_11 (nla, attr, rem) {
T_2 type = F_12 ( V_56 ) ;
int V_59 ;
if ( type > V_60 ) {
F_7 ( L_3 ,
type , V_60 ) ;
return - V_61 ;
}
if ( V_57 & ( 1 << type ) ) {
F_7 ( L_4 , type ) ;
return - V_61 ;
}
V_59 = V_62 [ type ] ;
if ( F_13 ( V_56 ) != V_59 && V_59 != - 1 ) {
F_7 ( L_5
L_6 , type ,
F_13 ( V_56 ) , V_59 ) ;
return - V_61 ;
}
if ( ! V_55 || ! F_8 ( F_14 ( V_56 ) , V_59 ) ) {
V_57 |= 1 << type ;
V_53 [ type ] = V_56 ;
}
}
if ( V_58 ) {
F_7 ( L_7 , V_58 ) ;
return - V_61 ;
}
* V_54 = V_57 ;
return 0 ;
}
static int F_15 ( const struct V_51 * V_52 ,
const struct V_51 * V_53 [] , T_3 * V_54 )
{
return F_10 ( V_52 , V_53 , V_54 , true ) ;
}
static int F_16 ( const struct V_51 * V_52 ,
const struct V_51 * V_53 [] , T_3 * V_54 )
{
return F_10 ( V_52 , V_53 , V_54 , false ) ;
}
static int F_17 ( const struct V_51 * V_52 ,
struct V_1 * V_2 , bool V_5 )
{
struct V_51 * V_53 ;
int V_58 ;
bool V_63 = false ;
T_5 V_64 = 0 ;
F_11 (a, attr, rem) {
int type = F_12 ( V_53 ) ;
static const T_6 V_65 [ V_66 + 1 ] = {
[ V_67 ] = sizeof( T_3 ) ,
[ V_68 ] = sizeof( T_6 ) ,
[ V_69 ] = sizeof( T_6 ) ,
[ V_70 ] = 1 ,
[ V_71 ] = 1 ,
[ V_72 ] = 0 ,
[ V_73 ] = 0 ,
} ;
if ( type > V_66 ) {
F_7 ( L_8 ,
type , V_66 ) ;
return - V_61 ;
}
if ( V_65 [ type ] != F_13 ( V_53 ) ) {
F_7 ( L_9
L_10 ,
type , F_13 ( V_53 ) , V_65 [ type ] ) ;
return - V_61 ;
}
switch ( type ) {
case V_67 :
F_18 ( V_2 , V_74 . V_75 ,
F_19 ( V_53 ) , V_5 ) ;
V_64 |= V_76 ;
break;
case V_68 :
F_18 ( V_2 , V_74 . V_77 ,
F_20 ( V_53 ) , V_5 ) ;
break;
case V_69 :
F_18 ( V_2 , V_74 . V_78 ,
F_20 ( V_53 ) , V_5 ) ;
break;
case V_70 :
F_18 ( V_2 , V_74 . V_79 ,
F_21 ( V_53 ) , V_5 ) ;
break;
case V_71 :
F_18 ( V_2 , V_74 . V_80 ,
F_21 ( V_53 ) , V_5 ) ;
V_63 = true ;
break;
case V_72 :
V_64 |= V_81 ;
break;
case V_73 :
V_64 |= V_82 ;
break;
default:
return - V_61 ;
}
}
F_18 ( V_2 , V_74 . V_64 , V_64 , V_5 ) ;
if ( V_58 > 0 ) {
F_7 ( L_11 , V_58 ) ;
return - V_61 ;
}
if ( ! V_5 ) {
if ( ! V_2 -> V_29 -> V_74 . V_78 ) {
F_7 ( L_12 ) ;
return - V_61 ;
}
if ( ! V_63 ) {
F_7 ( L_13 ) ;
return - V_61 ;
}
}
return 0 ;
}
static int F_22 ( struct V_83 * V_84 ,
const struct V_85 * V_74 ,
const struct V_85 * V_86 )
{
struct V_51 * V_56 ;
V_56 = F_23 ( V_84 , V_26 ) ;
if ( ! V_56 )
return - V_87 ;
if ( V_86 -> V_64 & V_76 &&
F_24 ( V_84 , V_67 , V_86 -> V_75 ) )
return - V_87 ;
if ( V_86 -> V_77 &&
F_25 ( V_84 , V_68 , V_86 -> V_77 ) )
return - V_87 ;
if ( V_86 -> V_78 &&
F_25 ( V_84 , V_69 , V_86 -> V_78 ) )
return - V_87 ;
if ( V_86 -> V_79 &&
F_26 ( V_84 , V_70 , V_86 -> V_79 ) )
return - V_87 ;
if ( F_26 ( V_84 , V_71 , V_86 -> V_80 ) )
return - V_87 ;
if ( ( V_86 -> V_64 & V_81 ) &&
F_27 ( V_84 , V_72 ) )
return - V_87 ;
if ( ( V_86 -> V_64 & V_82 ) &&
F_27 ( V_84 , V_73 ) )
return - V_87 ;
F_28 ( V_84 , V_56 ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 , T_3 * V_57 ,
const struct V_51 * * V_53 , bool V_5 )
{
if ( * V_57 & ( 1 << V_88 ) ) {
F_18 ( V_2 , V_89 . V_90 ,
F_30 ( V_53 [ V_88 ] ) , V_5 ) ;
* V_57 &= ~ ( 1 << V_88 ) ;
}
if ( * V_57 & ( 1 << V_27 ) ) {
T_6 V_91 = F_30 ( V_53 [ V_27 ] ) ;
if ( V_5 )
V_91 = 0xffffffff ;
else if ( V_91 >= V_92 )
return - V_61 ;
F_18 ( V_2 , V_89 . V_91 , V_91 , V_5 ) ;
* V_57 &= ~ ( 1 << V_27 ) ;
} else if ( ! V_5 ) {
F_18 ( V_2 , V_89 . V_91 , V_92 , V_5 ) ;
}
if ( * V_57 & ( 1 << V_93 ) ) {
T_7 V_94 = F_30 ( V_53 [ V_93 ] ) ;
F_18 ( V_2 , V_89 . V_95 , V_94 , V_5 ) ;
* V_57 &= ~ ( 1 << V_93 ) ;
}
if ( * V_57 & ( 1 << V_26 ) ) {
if ( F_17 ( V_53 [ V_26 ] , V_2 ,
V_5 ) )
return - V_61 ;
* V_57 &= ~ ( 1 << V_26 ) ;
}
return 0 ;
}
static int F_31 ( struct V_1 * V_2 , bool * V_96 ,
T_3 V_57 , const struct V_51 * * V_53 ,
bool V_5 )
{
int V_97 ;
T_3 V_98 = V_57 ;
V_97 = F_29 ( V_2 , & V_57 , V_53 , V_5 ) ;
if ( V_97 )
return V_97 ;
if ( V_57 & ( 1 << V_14 ) ) {
const struct V_99 * V_100 ;
V_100 = F_14 ( V_53 [ V_14 ] ) ;
F_32 ( V_2 , V_30 . V_46 ,
V_100 -> V_101 , V_102 , V_5 ) ;
F_32 ( V_2 , V_30 . V_103 ,
V_100 -> V_104 , V_102 , V_5 ) ;
V_57 &= ~ ( 1 << V_14 ) ;
}
if ( V_57 & ( 1 << V_105 ) ) {
T_5 V_106 ;
V_106 = F_33 ( V_53 [ V_105 ] ) ;
if ( ! ( V_106 & F_6 ( V_107 ) ) ) {
if ( V_5 )
F_7 ( L_14 ) ;
else
F_7 ( L_15 ) ;
return - V_61 ;
}
F_18 ( V_2 , V_30 . V_106 , V_106 , V_5 ) ;
V_57 &= ~ ( 1 << V_105 ) ;
} else if ( ! V_5 )
F_18 ( V_2 , V_30 . V_106 , F_6 ( 0xffff ) , true ) ;
if ( V_57 & ( 1 << V_28 ) ) {
T_5 V_108 ;
V_108 = F_33 ( V_53 [ V_28 ] ) ;
if ( V_5 ) {
V_108 = F_6 ( 0xffff ) ;
} else if ( F_34 ( V_108 ) < V_109 ) {
F_7 ( L_16 ,
F_34 ( V_108 ) , V_109 ) ;
return - V_61 ;
}
F_18 ( V_2 , V_30 . type , V_108 , V_5 ) ;
V_57 &= ~ ( 1 << V_28 ) ;
} else if ( ! V_5 ) {
F_18 ( V_2 , V_30 . type , F_6 ( V_110 ) , V_5 ) ;
}
if ( V_5 && V_96 ) {
if ( V_2 -> V_10 -> V_29 . V_30 . type != F_6 ( 0xffff ) )
* V_96 = false ;
}
if ( V_57 & ( 1 << V_16 ) ) {
const struct V_111 * V_112 ;
V_112 = F_14 ( V_53 [ V_16 ] ) ;
if ( ! V_5 && V_112 -> V_113 > V_114 ) {
F_7 ( L_17 ,
V_112 -> V_113 , V_114 ) ;
return - V_61 ;
}
F_18 ( V_2 , V_34 . V_37 ,
V_112 -> V_115 , V_5 ) ;
F_18 ( V_2 , V_34 . V_116 ,
V_112 -> V_79 , V_5 ) ;
F_18 ( V_2 , V_34 . V_63 ,
V_112 -> V_80 , V_5 ) ;
F_18 ( V_2 , V_34 . V_35 ,
V_112 -> V_113 , V_5 ) ;
F_18 ( V_2 , V_117 . V_118 . V_46 ,
V_112 -> V_77 , V_5 ) ;
F_18 ( V_2 , V_117 . V_118 . V_103 ,
V_112 -> V_78 , V_5 ) ;
V_57 &= ~ ( 1 << V_16 ) ;
if ( V_5 && V_96 && * V_96 ) {
if ( V_112 -> V_115 != 0xff ||
V_112 -> V_77 != F_35 ( 0xffffffff ) ||
V_112 -> V_78 != F_35 ( 0xffffffff ) )
* V_96 = false ;
}
}
if ( V_57 & ( 1 << V_17 ) ) {
const struct V_119 * V_120 ;
V_120 = F_14 ( V_53 [ V_17 ] ) ;
if ( ! V_5 && V_120 -> V_121 > V_114 ) {
F_7 ( L_18 ,
V_120 -> V_121 , V_114 ) ;
return - V_61 ;
}
F_18 ( V_2 , V_44 . V_122 ,
V_120 -> V_123 , V_5 ) ;
F_18 ( V_2 , V_34 . V_37 ,
V_120 -> V_124 , V_5 ) ;
F_18 ( V_2 , V_34 . V_116 ,
V_120 -> V_125 , V_5 ) ;
F_18 ( V_2 , V_34 . V_63 ,
V_120 -> V_126 , V_5 ) ;
F_18 ( V_2 , V_34 . V_35 ,
V_120 -> V_121 , V_5 ) ;
F_32 ( V_2 , V_44 . V_118 . V_46 ,
V_120 -> V_127 ,
sizeof( V_2 -> V_29 -> V_44 . V_118 . V_46 ) ,
V_5 ) ;
F_32 ( V_2 , V_44 . V_118 . V_103 ,
V_120 -> V_128 ,
sizeof( V_2 -> V_29 -> V_44 . V_118 . V_103 ) ,
V_5 ) ;
V_57 &= ~ ( 1 << V_17 ) ;
if ( V_5 && V_96 && * V_96 ) {
if ( V_120 -> V_124 != 0xff ||
! F_9 ( ( T_4 * ) V_120 -> V_127 , sizeof( V_2 -> V_29 -> V_44 . V_118 . V_46 ) ) ||
! F_9 ( ( T_4 * ) V_120 -> V_128 , sizeof( V_2 -> V_29 -> V_44 . V_118 . V_103 ) ) )
* V_96 = false ;
}
}
if ( V_57 & ( 1 << V_24 ) ) {
const struct V_129 * V_130 ;
V_130 = F_14 ( V_53 [ V_24 ] ) ;
if ( ! V_5 && ( V_130 -> V_131 & F_6 ( 0xff00 ) ) ) {
F_7 ( L_19 ,
V_130 -> V_131 ) ;
return - V_61 ;
}
F_18 ( V_2 , V_117 . V_118 . V_46 ,
V_130 -> V_132 , V_5 ) ;
F_18 ( V_2 , V_117 . V_118 . V_103 ,
V_130 -> V_133 , V_5 ) ;
F_18 ( V_2 , V_34 . V_37 ,
F_34 ( V_130 -> V_131 ) , V_5 ) ;
F_32 ( V_2 , V_117 . V_134 . V_135 ,
V_130 -> V_136 , V_102 , V_5 ) ;
F_32 ( V_2 , V_117 . V_134 . V_137 ,
V_130 -> V_138 , V_102 , V_5 ) ;
V_57 &= ~ ( 1 << V_24 ) ;
}
if ( V_57 & ( 1 << V_18 ) ) {
const struct V_139 * V_140 ;
V_140 = F_14 ( V_53 [ V_18 ] ) ;
if ( V_98 & ( 1 << V_16 ) ) {
F_18 ( V_2 , V_117 . V_45 . V_46 ,
V_140 -> V_141 , V_5 ) ;
F_18 ( V_2 , V_117 . V_45 . V_103 ,
V_140 -> V_142 , V_5 ) ;
} else {
F_18 ( V_2 , V_44 . V_45 . V_46 ,
V_140 -> V_141 , V_5 ) ;
F_18 ( V_2 , V_44 . V_45 . V_103 ,
V_140 -> V_142 , V_5 ) ;
}
V_57 &= ~ ( 1 << V_18 ) ;
if ( V_5 && V_96 && * V_96 &&
( V_140 -> V_141 != F_6 ( 0xffff ) ||
V_140 -> V_142 != F_6 ( 0xffff ) ) )
* V_96 = false ;
}
if ( V_57 & ( 1 << V_19 ) ) {
if ( V_98 & ( 1 << V_16 ) ) {
F_18 ( V_2 , V_117 . V_45 . V_143 ,
F_33 ( V_53 [ V_19 ] ) ,
V_5 ) ;
} else {
F_18 ( V_2 , V_44 . V_45 . V_143 ,
F_33 ( V_53 [ V_19 ] ) ,
V_5 ) ;
}
V_57 &= ~ ( 1 << V_19 ) ;
}
if ( V_57 & ( 1 << V_20 ) ) {
const struct V_144 * V_145 ;
V_145 = F_14 ( V_53 [ V_20 ] ) ;
if ( V_98 & ( 1 << V_16 ) ) {
F_18 ( V_2 , V_117 . V_45 . V_46 ,
V_145 -> V_146 , V_5 ) ;
F_18 ( V_2 , V_117 . V_45 . V_103 ,
V_145 -> V_147 , V_5 ) ;
} else {
F_18 ( V_2 , V_44 . V_45 . V_46 ,
V_145 -> V_146 , V_5 ) ;
F_18 ( V_2 , V_44 . V_45 . V_103 ,
V_145 -> V_147 , V_5 ) ;
}
V_57 &= ~ ( 1 << V_20 ) ;
if ( V_5 && V_96 && * V_96 &&
( V_145 -> V_146 != F_6 ( 0xffff ) ||
V_145 -> V_147 != F_6 ( 0xffff ) ) )
* V_96 = false ;
}
if ( V_57 & ( 1 << V_21 ) ) {
const struct V_148 * V_149 ;
V_149 = F_14 ( V_53 [ V_21 ] ) ;
if ( V_98 & ( 1 << V_16 ) ) {
F_18 ( V_2 , V_117 . V_45 . V_46 ,
V_149 -> V_150 , V_5 ) ;
F_18 ( V_2 , V_117 . V_45 . V_103 ,
V_149 -> V_151 , V_5 ) ;
} else {
F_18 ( V_2 , V_44 . V_45 . V_46 ,
V_149 -> V_150 , V_5 ) ;
F_18 ( V_2 , V_44 . V_45 . V_103 ,
V_149 -> V_151 , V_5 ) ;
}
V_57 &= ~ ( 1 << V_21 ) ;
}
if ( V_57 & ( 1 << V_22 ) ) {
const struct V_152 * V_153 ;
V_153 = F_14 ( V_53 [ V_22 ] ) ;
F_18 ( V_2 , V_117 . V_45 . V_46 ,
F_6 ( V_153 -> V_154 ) , V_5 ) ;
F_18 ( V_2 , V_117 . V_45 . V_103 ,
F_6 ( V_153 -> V_155 ) , V_5 ) ;
V_57 &= ~ ( 1 << V_22 ) ;
}
if ( V_57 & ( 1 << V_23 ) ) {
const struct V_156 * V_157 ;
V_157 = F_14 ( V_53 [ V_23 ] ) ;
F_18 ( V_2 , V_44 . V_45 . V_46 ,
F_6 ( V_157 -> V_158 ) , V_5 ) ;
F_18 ( V_2 , V_44 . V_45 . V_103 ,
F_6 ( V_157 -> V_159 ) , V_5 ) ;
V_57 &= ~ ( 1 << V_23 ) ;
}
if ( V_57 & ( 1 << V_25 ) ) {
const struct V_160 * V_161 ;
V_161 = F_14 ( V_53 [ V_25 ] ) ;
F_32 ( V_2 , V_44 . V_162 . V_163 ,
V_161 -> V_164 ,
sizeof( V_2 -> V_29 -> V_44 . V_162 . V_163 ) ,
V_5 ) ;
F_32 ( V_2 , V_44 . V_162 . V_165 ,
V_161 -> V_166 , V_102 , V_5 ) ;
F_32 ( V_2 , V_44 . V_162 . V_167 ,
V_161 -> V_168 , V_102 , V_5 ) ;
V_57 &= ~ ( 1 << V_25 ) ;
}
if ( V_57 != 0 )
return - V_61 ;
return 0 ;
}
static void F_36 ( struct V_169 * V_10 ,
struct V_6 * V_7 , T_4 V_170 )
{
T_4 * V_171 = ( T_4 * ) & V_10 -> V_29 + V_7 -> V_8 ;
V_10 -> V_7 = * V_7 ;
memset ( V_171 , V_170 , F_4 ( V_7 ) ) ;
}
int F_37 ( struct V_1 * V_2 ,
bool * V_96 ,
const struct V_51 * V_29 ,
const struct V_51 * V_10 )
{
const struct V_51 * V_53 [ V_60 + 1 ] ;
const struct V_51 * V_172 ;
T_3 V_11 = 0 ;
T_3 V_12 = 0 ;
bool V_173 = false ;
int V_97 ;
V_97 = F_16 ( V_29 , V_53 , & V_11 ) ;
if ( V_97 )
return V_97 ;
if ( ( V_11 & ( 1 << V_14 ) ) &&
( V_11 & ( 1 << V_28 ) ) &&
( F_33 ( V_53 [ V_28 ] ) == F_6 ( V_174 ) ) ) {
T_5 V_106 ;
if ( ! ( ( V_11 & ( 1 << V_105 ) ) &&
( V_11 & ( 1 << V_175 ) ) ) ) {
F_7 ( L_20 ) ;
return - V_61 ;
}
V_11 &= ~ ( 1 << V_28 ) ;
V_106 = F_33 ( V_53 [ V_105 ] ) ;
V_172 = V_53 [ V_175 ] ;
V_11 &= ~ ( 1 << V_175 ) ;
V_173 = true ;
if ( V_106 & F_6 ( V_107 ) ) {
V_97 = F_16 ( V_172 , V_53 , & V_11 ) ;
if ( V_97 )
return V_97 ;
} else if ( ! V_106 ) {
if ( F_13 ( V_172 ) ) {
F_7 ( L_21 ) ;
return - V_61 ;
}
} else {
F_7 ( L_22 ) ;
return - V_61 ;
}
}
V_97 = F_31 ( V_2 , NULL , V_11 , V_53 , false ) ;
if ( V_97 )
return V_97 ;
if ( V_96 )
* V_96 = true ;
if ( V_10 ) {
V_97 = F_15 ( V_10 , V_53 , & V_12 ) ;
if ( V_97 )
return V_97 ;
if ( V_12 & 1 << V_175 ) {
T_5 V_108 = 0 ;
T_5 V_106 = 0 ;
if ( ! V_173 ) {
F_7 ( L_23 ) ;
return - V_61 ;
}
V_12 &= ~ ( 1 << V_175 ) ;
if ( V_53 [ V_28 ] )
V_108 = F_33 ( V_53 [ V_28 ] ) ;
if ( V_108 == F_6 ( 0xffff ) ) {
V_12 &= ~ ( 1 << V_28 ) ;
V_172 = V_53 [ V_175 ] ;
V_97 = F_15 ( V_172 , V_53 , & V_12 ) ;
} else {
F_7 ( L_24 ,
F_34 ( V_108 ) ) ;
return - V_61 ;
}
if ( V_53 [ V_105 ] )
V_106 = F_33 ( V_53 [ V_105 ] ) ;
if ( ! ( V_106 & F_6 ( V_107 ) ) ) {
F_7 ( L_25 , F_34 ( V_106 ) ) ;
return - V_61 ;
}
}
V_97 = F_31 ( V_2 , V_96 , V_12 , V_53 , true ) ;
if ( V_97 )
return V_97 ;
} else {
if ( V_2 -> V_10 )
F_36 ( V_2 -> V_10 , & V_2 -> V_7 , 0xff ) ;
}
if ( ! F_5 ( V_2 , V_11 , V_12 ) )
return - V_61 ;
return 0 ;
}
int F_38 ( struct V_176 * V_177 ,
const struct V_51 * V_52 )
{
struct V_85 * V_74 = & V_177 -> V_29 . V_74 ;
const struct V_51 * V_53 [ V_60 + 1 ] ;
T_3 V_57 = 0 ;
int V_97 ;
struct V_1 V_2 ;
V_177 -> V_29 . V_89 . V_91 = V_92 ;
V_177 -> V_29 . V_89 . V_90 = 0 ;
V_177 -> V_29 . V_89 . V_95 = 0 ;
memset ( V_74 , 0 , sizeof( V_177 -> V_29 . V_74 ) ) ;
V_97 = F_16 ( V_52 , V_53 , & V_57 ) ;
if ( V_97 )
return - V_61 ;
memset ( & V_2 , 0 , sizeof( V_2 ) ) ;
V_2 . V_29 = & V_177 -> V_29 ;
V_97 = F_29 ( & V_2 , & V_57 , V_53 , false ) ;
if ( V_97 )
return V_97 ;
return 0 ;
}
int F_39 ( const struct V_178 * V_179 ,
const struct V_178 * V_86 , struct V_83 * V_84 )
{
struct V_99 * V_100 ;
struct V_51 * V_56 , * V_172 ;
bool V_5 = ( V_179 != V_86 ) ;
if ( F_40 ( V_84 , V_88 , V_86 -> V_89 . V_90 ) )
goto V_180;
if ( ( V_179 -> V_74 . V_78 || V_5 ) &&
F_22 ( V_84 , & V_179 -> V_74 , & V_86 -> V_74 ) )
goto V_180;
if ( V_179 -> V_89 . V_91 == V_92 ) {
if ( V_5 && ( V_86 -> V_89 . V_91 == 0xffff ) )
if ( F_40 ( V_84 , V_27 , 0xffffffff ) )
goto V_180;
} else {
T_2 V_181 ;
V_181 = ! V_5 ? 0 : 0xffff ;
if ( F_40 ( V_84 , V_27 ,
( V_181 << 16 ) | V_86 -> V_89 . V_91 ) )
goto V_180;
}
if ( F_40 ( V_84 , V_93 , V_86 -> V_89 . V_95 ) )
goto V_180;
V_56 = F_41 ( V_84 , V_14 , sizeof( * V_100 ) ) ;
if ( ! V_56 )
goto V_180;
V_100 = F_14 ( V_56 ) ;
memcpy ( V_100 -> V_101 , V_86 -> V_30 . V_46 , V_102 ) ;
memcpy ( V_100 -> V_104 , V_86 -> V_30 . V_103 , V_102 ) ;
if ( V_179 -> V_30 . V_106 || V_179 -> V_30 . type == F_6 ( V_174 ) ) {
T_5 V_108 ;
V_108 = ! V_5 ? F_6 ( V_174 ) : F_6 ( 0xffff ) ;
if ( F_42 ( V_84 , V_28 , V_108 ) ||
F_42 ( V_84 , V_105 , V_86 -> V_30 . V_106 ) )
goto V_180;
V_172 = F_23 ( V_84 , V_175 ) ;
if ( ! V_179 -> V_30 . V_106 )
goto V_182;
} else
V_172 = NULL ;
if ( V_179 -> V_30 . type == F_6 ( V_110 ) ) {
if ( V_5 && V_86 -> V_30 . type )
if ( F_42 ( V_84 , V_28 ,
V_86 -> V_30 . type ) )
goto V_180;
goto V_182;
}
if ( F_42 ( V_84 , V_28 , V_86 -> V_30 . type ) )
goto V_180;
if ( V_179 -> V_30 . type == F_6 ( V_33 ) ) {
struct V_111 * V_112 ;
V_56 = F_41 ( V_84 , V_16 , sizeof( * V_112 ) ) ;
if ( ! V_56 )
goto V_180;
V_112 = F_14 ( V_56 ) ;
V_112 -> V_77 = V_86 -> V_117 . V_118 . V_46 ;
V_112 -> V_78 = V_86 -> V_117 . V_118 . V_103 ;
V_112 -> V_115 = V_86 -> V_34 . V_37 ;
V_112 -> V_79 = V_86 -> V_34 . V_116 ;
V_112 -> V_80 = V_86 -> V_34 . V_63 ;
V_112 -> V_113 = V_86 -> V_34 . V_35 ;
} else if ( V_179 -> V_30 . type == F_6 ( V_42 ) ) {
struct V_119 * V_120 ;
V_56 = F_41 ( V_84 , V_17 , sizeof( * V_120 ) ) ;
if ( ! V_56 )
goto V_180;
V_120 = F_14 ( V_56 ) ;
memcpy ( V_120 -> V_127 , & V_86 -> V_44 . V_118 . V_46 ,
sizeof( V_120 -> V_127 ) ) ;
memcpy ( V_120 -> V_128 , & V_86 -> V_44 . V_118 . V_103 ,
sizeof( V_120 -> V_128 ) ) ;
V_120 -> V_123 = V_86 -> V_44 . V_122 ;
V_120 -> V_124 = V_86 -> V_34 . V_37 ;
V_120 -> V_125 = V_86 -> V_34 . V_116 ;
V_120 -> V_126 = V_86 -> V_34 . V_63 ;
V_120 -> V_121 = V_86 -> V_34 . V_35 ;
} else if ( V_179 -> V_30 . type == F_6 ( V_31 ) ||
V_179 -> V_30 . type == F_6 ( V_32 ) ) {
struct V_129 * V_130 ;
V_56 = F_41 ( V_84 , V_24 , sizeof( * V_130 ) ) ;
if ( ! V_56 )
goto V_180;
V_130 = F_14 ( V_56 ) ;
memset ( V_130 , 0 , sizeof( struct V_129 ) ) ;
V_130 -> V_132 = V_86 -> V_117 . V_118 . V_46 ;
V_130 -> V_133 = V_86 -> V_117 . V_118 . V_103 ;
V_130 -> V_131 = F_6 ( V_86 -> V_34 . V_37 ) ;
memcpy ( V_130 -> V_136 , V_86 -> V_117 . V_134 . V_135 , V_102 ) ;
memcpy ( V_130 -> V_138 , V_86 -> V_117 . V_134 . V_137 , V_102 ) ;
}
if ( ( V_179 -> V_30 . type == F_6 ( V_33 ) ||
V_179 -> V_30 . type == F_6 ( V_42 ) ) &&
V_179 -> V_34 . V_35 != V_36 ) {
if ( V_179 -> V_34 . V_37 == V_40 ) {
struct V_139 * V_140 ;
V_56 = F_41 ( V_84 , V_18 , sizeof( * V_140 ) ) ;
if ( ! V_56 )
goto V_180;
V_140 = F_14 ( V_56 ) ;
if ( V_179 -> V_30 . type == F_6 ( V_33 ) ) {
V_140 -> V_141 = V_86 -> V_117 . V_45 . V_46 ;
V_140 -> V_142 = V_86 -> V_117 . V_45 . V_103 ;
if ( F_42 ( V_84 , V_19 ,
V_86 -> V_117 . V_45 . V_143 ) )
goto V_180;
} else if ( V_179 -> V_30 . type == F_6 ( V_42 ) ) {
V_140 -> V_141 = V_86 -> V_44 . V_45 . V_46 ;
V_140 -> V_142 = V_86 -> V_44 . V_45 . V_103 ;
if ( F_42 ( V_84 , V_19 ,
V_86 -> V_44 . V_45 . V_143 ) )
goto V_180;
}
} else if ( V_179 -> V_34 . V_37 == V_38 ) {
struct V_144 * V_145 ;
V_56 = F_41 ( V_84 , V_20 , sizeof( * V_145 ) ) ;
if ( ! V_56 )
goto V_180;
V_145 = F_14 ( V_56 ) ;
if ( V_179 -> V_30 . type == F_6 ( V_33 ) ) {
V_145 -> V_146 = V_86 -> V_117 . V_45 . V_46 ;
V_145 -> V_147 = V_86 -> V_117 . V_45 . V_103 ;
} else if ( V_179 -> V_30 . type == F_6 ( V_42 ) ) {
V_145 -> V_146 = V_86 -> V_44 . V_45 . V_46 ;
V_145 -> V_147 = V_86 -> V_44 . V_45 . V_103 ;
}
} else if ( V_179 -> V_34 . V_37 == V_39 ) {
struct V_148 * V_149 ;
V_56 = F_41 ( V_84 , V_21 , sizeof( * V_149 ) ) ;
if ( ! V_56 )
goto V_180;
V_149 = F_14 ( V_56 ) ;
if ( V_179 -> V_30 . type == F_6 ( V_33 ) ) {
V_149 -> V_150 = V_179 -> V_117 . V_45 . V_46 ;
V_149 -> V_151 = V_179 -> V_117 . V_45 . V_103 ;
} else if ( V_179 -> V_30 . type == F_6 ( V_42 ) ) {
V_149 -> V_150 = V_179 -> V_44 . V_45 . V_46 ;
V_149 -> V_151 = V_179 -> V_44 . V_45 . V_103 ;
}
} else if ( V_179 -> V_30 . type == F_6 ( V_33 ) &&
V_179 -> V_34 . V_37 == V_41 ) {
struct V_152 * V_153 ;
V_56 = F_41 ( V_84 , V_22 , sizeof( * V_153 ) ) ;
if ( ! V_56 )
goto V_180;
V_153 = F_14 ( V_56 ) ;
V_153 -> V_154 = F_34 ( V_86 -> V_117 . V_45 . V_46 ) ;
V_153 -> V_155 = F_34 ( V_86 -> V_117 . V_45 . V_103 ) ;
} else if ( V_179 -> V_30 . type == F_6 ( V_42 ) &&
V_179 -> V_34 . V_37 == V_43 ) {
struct V_156 * V_157 ;
V_56 = F_41 ( V_84 , V_23 ,
sizeof( * V_157 ) ) ;
if ( ! V_56 )
goto V_180;
V_157 = F_14 ( V_56 ) ;
V_157 -> V_158 = F_34 ( V_86 -> V_44 . V_45 . V_46 ) ;
V_157 -> V_159 = F_34 ( V_86 -> V_44 . V_45 . V_103 ) ;
if ( V_157 -> V_158 == V_47 ||
V_157 -> V_158 == V_48 ) {
struct V_160 * V_161 ;
V_56 = F_41 ( V_84 , V_25 , sizeof( * V_161 ) ) ;
if ( ! V_56 )
goto V_180;
V_161 = F_14 ( V_56 ) ;
memcpy ( V_161 -> V_164 , & V_86 -> V_44 . V_162 . V_163 ,
sizeof( V_161 -> V_164 ) ) ;
memcpy ( V_161 -> V_166 , V_86 -> V_44 . V_162 . V_165 , V_102 ) ;
memcpy ( V_161 -> V_168 , V_86 -> V_44 . V_162 . V_167 , V_102 ) ;
}
}
}
V_182:
if ( V_172 )
F_28 ( V_84 , V_172 ) ;
return 0 ;
V_180:
return - V_87 ;
}
struct V_183 * F_43 ( int V_4 )
{
struct V_183 * V_184 ;
if ( V_4 > V_185 )
return F_44 ( - V_61 ) ;
V_184 = F_45 ( sizeof( * V_184 ) + V_4 , V_186 ) ;
if ( ! V_184 )
return F_44 ( - V_187 ) ;
V_184 -> V_188 = 0 ;
return V_184 ;
}
void F_46 ( struct V_183 * V_189 )
{
F_47 ( V_189 , V_190 ) ;
}
static struct V_51 * F_48 ( struct V_183 * * V_184 ,
int V_191 )
{
struct V_183 * V_192 ;
int V_193 ;
int V_194 = F_49 ( V_191 ) ;
int V_195 = F_50 ( struct V_183 , V_196 ) +
( * V_184 ) -> V_188 ;
if ( V_194 <= ( F_51 ( * V_184 ) - V_195 ) )
goto V_197;
V_193 = F_51 ( * V_184 ) * 2 ;
if ( V_193 > V_185 ) {
if ( ( V_185 - V_195 ) < V_194 )
return F_44 ( - V_87 ) ;
V_193 = V_185 ;
}
V_192 = F_43 ( V_193 ) ;
if ( F_52 ( V_192 ) )
return ( void * ) V_192 ;
memcpy ( V_192 -> V_196 , ( * V_184 ) -> V_196 , ( * V_184 ) -> V_188 ) ;
V_192 -> V_188 = ( * V_184 ) -> V_188 ;
F_53 ( * V_184 ) ;
* V_184 = V_192 ;
V_197:
( * V_184 ) -> V_188 += V_194 ;
return (struct V_51 * ) ( ( unsigned char * ) ( * V_184 ) + V_195 ) ;
}
static int F_54 ( struct V_183 * * V_184 , int V_198 , void * V_199 , int V_200 )
{
struct V_51 * V_53 ;
V_53 = F_48 ( V_184 , F_55 ( V_200 ) ) ;
if ( F_52 ( V_53 ) )
return F_56 ( V_53 ) ;
V_53 -> F_12 = V_198 ;
V_53 -> F_13 = F_55 ( V_200 ) ;
if ( V_199 )
memcpy ( F_14 ( V_53 ) , V_199 , V_200 ) ;
memset ( ( unsigned char * ) V_53 + V_53 -> F_13 , 0 , F_57 ( V_200 ) ) ;
return 0 ;
}
static inline int F_58 ( struct V_183 * * V_184 ,
int V_198 )
{
int V_201 = ( * V_184 ) -> V_188 ;
int V_97 ;
V_97 = F_54 ( V_184 , V_198 , NULL , 0 ) ;
if ( V_97 )
return V_97 ;
return V_201 ;
}
static inline void F_59 ( struct V_183 * V_184 ,
int V_202 )
{
struct V_51 * V_53 = (struct V_51 * ) ( ( unsigned char * ) V_184 -> V_196 +
V_202 ) ;
V_53 -> F_13 = V_184 -> V_188 - V_202 ;
}
static int F_60 ( const struct V_51 * V_52 ,
const struct V_178 * V_29 , int V_203 ,
struct V_183 * * V_184 )
{
const struct V_51 * V_57 [ V_204 + 1 ] ;
const struct V_51 * V_205 , * V_196 ;
const struct V_51 * V_53 ;
int V_58 , V_8 , V_97 , V_206 ;
memset ( V_57 , 0 , sizeof( V_57 ) ) ;
F_11 (a, attr, rem) {
int type = F_12 ( V_53 ) ;
if ( ! type || type > V_204 || V_57 [ type ] )
return - V_61 ;
V_57 [ type ] = V_53 ;
}
if ( V_58 )
return - V_61 ;
V_205 = V_57 [ V_207 ] ;
if ( ! V_205 || F_13 ( V_205 ) != sizeof( T_6 ) )
return - V_61 ;
V_196 = V_57 [ V_208 ] ;
if ( ! V_196 || ( F_13 ( V_196 ) && F_13 ( V_196 ) < V_209 ) )
return - V_61 ;
V_8 = F_58 ( V_184 , V_210 ) ;
if ( V_8 < 0 )
return V_8 ;
V_97 = F_54 ( V_184 , V_207 ,
F_14 ( V_205 ) , sizeof( T_6 ) ) ;
if ( V_97 )
return V_97 ;
V_206 = F_58 ( V_184 , V_208 ) ;
if ( V_206 < 0 )
return V_206 ;
V_97 = F_61 ( V_196 , V_29 , V_203 + 1 , V_184 ) ;
if ( V_97 )
return V_97 ;
F_59 ( * V_184 , V_206 ) ;
F_59 ( * V_184 , V_8 ) ;
return 0 ;
}
static int F_62 ( const struct V_178 * V_211 )
{
if ( V_211 -> V_30 . type == F_6 ( V_33 ) ) {
if ( V_211 -> V_117 . V_45 . V_46 || V_211 -> V_117 . V_45 . V_103 )
return 0 ;
} else if ( V_211 -> V_30 . type == F_6 ( V_42 ) ) {
if ( V_211 -> V_44 . V_45 . V_46 || V_211 -> V_44 . V_45 . V_103 )
return 0 ;
}
return - V_61 ;
}
void F_63 ( struct V_1 * V_2 ,
struct V_178 * V_29 ,
struct V_169 * V_10 )
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
static int F_64 ( const struct V_51 * V_52 ,
struct V_183 * * V_184 )
{
struct V_1 V_2 ;
struct V_178 V_29 ;
int V_97 , V_8 ;
F_63 ( & V_2 , & V_29 , NULL ) ;
V_97 = F_17 ( F_14 ( V_52 ) , & V_2 , false ) ;
if ( V_97 )
return V_97 ;
V_8 = F_58 ( V_184 , V_212 ) ;
if ( V_8 < 0 )
return V_8 ;
V_97 = F_54 ( V_184 , V_213 , & V_2 . V_29 -> V_74 ,
sizeof( V_2 . V_29 -> V_74 ) ) ;
F_59 ( * V_184 , V_8 ) ;
return V_97 ;
}
static int F_65 ( const struct V_51 * V_53 ,
const struct V_178 * V_211 ,
struct V_183 * * V_184 ,
bool * V_214 )
{
const struct V_51 * V_215 = F_14 ( V_53 ) ;
int V_216 = F_12 ( V_215 ) ;
if ( F_66 ( F_13 ( V_215 ) ) != F_13 ( V_53 ) )
return - V_61 ;
if ( V_216 > V_60 ||
( V_62 [ V_216 ] != F_13 ( V_215 ) &&
V_62 [ V_216 ] != - 1 ) )
return - V_61 ;
switch ( V_216 ) {
const struct V_111 * V_112 ;
const struct V_119 * V_120 ;
int V_97 ;
case V_88 :
case V_93 :
case V_14 :
break;
case V_26 :
* V_214 = true ;
V_97 = F_64 ( V_53 , V_184 ) ;
if ( V_97 )
return V_97 ;
break;
case V_16 :
if ( V_211 -> V_30 . type != F_6 ( V_33 ) )
return - V_61 ;
if ( ! V_211 -> V_34 . V_37 )
return - V_61 ;
V_112 = F_14 ( V_215 ) ;
if ( V_112 -> V_115 != V_211 -> V_34 . V_37 )
return - V_61 ;
if ( V_112 -> V_113 != V_211 -> V_34 . V_35 )
return - V_61 ;
break;
case V_17 :
if ( V_211 -> V_30 . type != F_6 ( V_42 ) )
return - V_61 ;
if ( ! V_211 -> V_34 . V_37 )
return - V_61 ;
V_120 = F_14 ( V_215 ) ;
if ( V_120 -> V_124 != V_211 -> V_34 . V_37 )
return - V_61 ;
if ( V_120 -> V_121 != V_211 -> V_34 . V_35 )
return - V_61 ;
if ( F_67 ( V_120 -> V_123 ) & 0xFFF00000 )
return - V_61 ;
break;
case V_18 :
if ( V_211 -> V_34 . V_37 != V_40 )
return - V_61 ;
return F_62 ( V_211 ) ;
case V_20 :
if ( V_211 -> V_34 . V_37 != V_38 )
return - V_61 ;
return F_62 ( V_211 ) ;
case V_21 :
if ( V_211 -> V_34 . V_37 != V_39 )
return - V_61 ;
return F_62 ( V_211 ) ;
default:
return - V_61 ;
}
return 0 ;
}
static int F_68 ( const struct V_51 * V_52 )
{
static const struct V_217 V_218 [ V_219 + 1 ] = {
[ V_220 ] = { . type = V_221 } ,
[ V_222 ] = { . type = V_223 } ,
} ;
struct V_51 * V_53 [ V_219 + 1 ] ;
int error ;
error = F_69 ( V_53 , V_219 ,
V_52 , V_218 ) ;
if ( error )
return error ;
if ( ! V_53 [ V_220 ] ||
! F_30 ( V_53 [ V_220 ] ) )
return - V_61 ;
return 0 ;
}
static int F_70 ( const struct V_51 * V_224 ,
struct V_183 * * V_184 )
{
int V_225 = F_49 ( V_224 -> F_13 ) ;
struct V_51 * V_226 ;
V_226 = F_48 ( V_184 , V_224 -> F_13 ) ;
if ( F_52 ( V_226 ) )
return F_56 ( V_226 ) ;
memcpy ( V_226 , V_224 , V_225 ) ;
return 0 ;
}
int F_61 ( const struct V_51 * V_52 ,
const struct V_178 * V_29 ,
int V_203 ,
struct V_183 * * V_184 )
{
const struct V_51 * V_53 ;
int V_58 , V_97 ;
if ( V_203 >= V_227 )
return - V_228 ;
F_11 (a, attr, rem) {
static const T_6 V_229 [ V_230 + 1 ] = {
[ V_231 ] = sizeof( T_6 ) ,
[ V_232 ] = ( T_6 ) - 1 ,
[ V_233 ] = sizeof( struct V_234 ) ,
[ V_235 ] = 0 ,
[ V_212 ] = ( T_6 ) - 1 ,
[ V_210 ] = ( T_6 ) - 1
} ;
const struct V_234 * V_236 ;
int type = F_12 ( V_53 ) ;
bool V_237 ;
if ( type > V_230 ||
( V_229 [ type ] != F_13 ( V_53 ) &&
V_229 [ type ] != ( T_6 ) - 1 ) )
return - V_61 ;
V_237 = false ;
switch ( type ) {
case V_238 :
return - V_61 ;
case V_232 :
V_97 = F_68 ( V_53 ) ;
if ( V_97 )
return V_97 ;
break;
case V_231 :
if ( F_30 ( V_53 ) >= V_92 )
return - V_61 ;
break;
case V_235 :
break;
case V_233 :
V_236 = F_14 ( V_53 ) ;
if ( V_236 -> V_239 != F_6 ( V_174 ) )
return - V_61 ;
if ( ! ( V_236 -> V_240 & F_6 ( V_107 ) ) )
return - V_61 ;
break;
case V_212 :
V_97 = F_65 ( V_53 , V_29 , V_184 , & V_237 ) ;
if ( V_97 )
return V_97 ;
break;
case V_210 :
V_97 = F_60 ( V_53 , V_29 , V_203 , V_184 ) ;
if ( V_97 )
return V_97 ;
V_237 = true ;
break;
default:
return - V_61 ;
}
if ( ! V_237 ) {
V_97 = F_70 ( V_53 , V_184 ) ;
if ( V_97 )
return V_97 ;
}
}
if ( V_58 > 0 )
return - V_61 ;
return 0 ;
}
static int F_71 ( const struct V_51 * V_52 , struct V_83 * V_84 )
{
const struct V_51 * V_53 ;
struct V_51 * V_8 ;
int V_97 = 0 , V_58 ;
V_8 = F_23 ( V_84 , V_210 ) ;
if ( ! V_8 )
return - V_87 ;
F_11 (a, attr, rem) {
int type = F_12 ( V_53 ) ;
struct V_51 * V_241 ;
switch ( type ) {
case V_207 :
if ( F_72 ( V_84 , V_207 ,
sizeof( T_6 ) , F_14 ( V_53 ) ) )
return - V_87 ;
break;
case V_208 :
V_241 = F_23 ( V_84 , V_208 ) ;
if ( ! V_241 )
return - V_87 ;
V_97 = F_73 ( F_14 ( V_53 ) , F_13 ( V_53 ) , V_84 ) ;
if ( V_97 )
return V_97 ;
F_28 ( V_84 , V_241 ) ;
break;
}
}
F_28 ( V_84 , V_8 ) ;
return V_97 ;
}
static int F_74 ( const struct V_51 * V_53 , struct V_83 * V_84 )
{
const struct V_51 * V_215 = F_14 ( V_53 ) ;
int V_216 = F_12 ( V_215 ) ;
struct V_51 * V_8 ;
int V_97 ;
switch ( V_216 ) {
case V_213 :
V_8 = F_23 ( V_84 , V_212 ) ;
if ( ! V_8 )
return - V_87 ;
V_97 = F_22 ( V_84 , F_14 ( V_215 ) ,
F_14 ( V_215 ) ) ;
if ( V_97 )
return V_97 ;
F_28 ( V_84 , V_8 ) ;
break;
default:
if ( F_72 ( V_84 , V_212 , F_13 ( V_53 ) , V_215 ) )
return - V_87 ;
break;
}
return 0 ;
}
int F_73 ( const struct V_51 * V_52 , int V_200 , struct V_83 * V_84 )
{
const struct V_51 * V_53 ;
int V_58 , V_97 ;
F_75 (a, attr, len, rem) {
int type = F_12 ( V_53 ) ;
switch ( type ) {
case V_212 :
V_97 = F_74 ( V_53 , V_84 ) ;
if ( V_97 )
return V_97 ;
break;
case V_210 :
V_97 = F_71 ( V_53 , V_84 ) ;
if ( V_97 )
return V_97 ;
break;
default:
if ( F_72 ( V_84 , type , F_13 ( V_53 ) , F_14 ( V_53 ) ) )
return - V_87 ;
break;
}
}
return 0 ;
}
