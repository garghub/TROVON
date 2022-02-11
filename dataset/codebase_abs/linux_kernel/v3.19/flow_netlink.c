static void F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 , bool V_5 )
{
struct V_6 * V_7 ;
T_1 V_8 = F_2 ( V_3 , sizeof( long ) ) ;
T_1 V_9 = F_3 ( V_3 + V_4 , sizeof( long ) ) ;
if ( ! V_5 )
V_7 = & V_2 -> V_7 ;
else
V_7 = & V_2 -> V_10 -> V_7 ;
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
T_2 V_11 , T_2 V_12 , bool log )
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
| ( 1 << V_25 )
| ( 1 << V_26 ) ) ;
V_15 |= ( ( 1 << V_27 )
| ( 1 << V_28 )
| ( 1 << V_29 ) ) ;
if ( V_2 -> V_30 -> V_31 . type == F_5 ( V_32 )
|| V_2 -> V_30 -> V_31 . type == F_5 ( V_33 ) ) {
V_13 |= 1 << V_24 ;
if ( V_2 -> V_10 && ( V_2 -> V_10 -> V_30 . V_31 . type == F_5 ( 0xffff ) ) )
V_15 |= 1 << V_24 ;
}
if ( F_6 ( V_2 -> V_30 -> V_31 . type ) ) {
V_13 |= 1 << V_26 ;
if ( V_2 -> V_10 && ( V_2 -> V_10 -> V_30 . V_31 . type == F_5 ( 0xffff ) ) )
V_15 |= 1 << V_26 ;
}
if ( V_2 -> V_30 -> V_31 . type == F_5 ( V_34 ) ) {
V_13 |= 1 << V_16 ;
if ( V_2 -> V_10 && ( V_2 -> V_10 -> V_30 . V_31 . type == F_5 ( 0xffff ) ) )
V_15 |= 1 << V_16 ;
if ( V_2 -> V_30 -> V_35 . V_36 != V_37 ) {
if ( V_2 -> V_30 -> V_35 . V_38 == V_39 ) {
V_13 |= 1 << V_20 ;
if ( V_2 -> V_10 && ( V_2 -> V_10 -> V_30 . V_35 . V_38 == 0xff ) )
V_15 |= 1 << V_20 ;
}
if ( V_2 -> V_30 -> V_35 . V_38 == V_40 ) {
V_13 |= 1 << V_21 ;
if ( V_2 -> V_10 && ( V_2 -> V_10 -> V_30 . V_35 . V_38 == 0xff ) )
V_15 |= 1 << V_21 ;
}
if ( V_2 -> V_30 -> V_35 . V_38 == V_41 ) {
V_13 |= 1 << V_18 ;
V_13 |= 1 << V_19 ;
if ( V_2 -> V_10 && ( V_2 -> V_10 -> V_30 . V_35 . V_38 == 0xff ) ) {
V_15 |= 1 << V_18 ;
V_15 |= 1 << V_19 ;
}
}
if ( V_2 -> V_30 -> V_35 . V_38 == V_42 ) {
V_13 |= 1 << V_22 ;
if ( V_2 -> V_10 && ( V_2 -> V_10 -> V_30 . V_35 . V_38 == 0xff ) )
V_15 |= 1 << V_22 ;
}
}
}
if ( V_2 -> V_30 -> V_31 . type == F_5 ( V_43 ) ) {
V_13 |= 1 << V_17 ;
if ( V_2 -> V_10 && ( V_2 -> V_10 -> V_30 . V_31 . type == F_5 ( 0xffff ) ) )
V_15 |= 1 << V_17 ;
if ( V_2 -> V_30 -> V_35 . V_36 != V_37 ) {
if ( V_2 -> V_30 -> V_35 . V_38 == V_39 ) {
V_13 |= 1 << V_20 ;
if ( V_2 -> V_10 && ( V_2 -> V_10 -> V_30 . V_35 . V_38 == 0xff ) )
V_15 |= 1 << V_20 ;
}
if ( V_2 -> V_30 -> V_35 . V_38 == V_40 ) {
V_13 |= 1 << V_21 ;
if ( V_2 -> V_10 && ( V_2 -> V_10 -> V_30 . V_35 . V_38 == 0xff ) )
V_15 |= 1 << V_21 ;
}
if ( V_2 -> V_30 -> V_35 . V_38 == V_41 ) {
V_13 |= 1 << V_18 ;
V_13 |= 1 << V_19 ;
if ( V_2 -> V_10 && ( V_2 -> V_10 -> V_30 . V_35 . V_38 == 0xff ) ) {
V_15 |= 1 << V_18 ;
V_15 |= 1 << V_19 ;
}
}
if ( V_2 -> V_30 -> V_35 . V_38 == V_44 ) {
V_13 |= 1 << V_23 ;
if ( V_2 -> V_10 && ( V_2 -> V_10 -> V_30 . V_35 . V_38 == 0xff ) )
V_15 |= 1 << V_23 ;
if ( V_2 -> V_30 -> V_45 . V_46 ==
F_5 ( V_47 ) ||
V_2 -> V_30 -> V_45 . V_46 == F_5 ( V_48 ) ) {
V_13 |= 1 << V_25 ;
if ( V_2 -> V_10 && ( V_2 -> V_10 -> V_30 . V_45 . V_46 == F_5 ( 0xff ) ) )
V_15 |= 1 << V_25 ;
}
}
}
}
if ( ( V_11 & V_13 ) != V_13 ) {
F_7 ( log , L_1 ,
( unsigned long long ) V_11 ,
( unsigned long long ) V_13 ) ;
return false ;
}
if ( ( V_12 & V_15 ) != V_12 ) {
F_7 ( log , L_2 ,
( unsigned long long ) V_12 ,
( unsigned long long ) V_15 ) ;
return false ;
}
return true ;
}
T_1 F_8 ( void )
{
return F_9 ( 8 )
+ F_9 ( 4 )
+ F_9 ( 4 )
+ F_9 ( 1 )
+ F_9 ( 1 )
+ F_9 ( 0 )
+ F_9 ( 0 )
+ F_9 ( 0 )
+ F_9 ( 256 )
+ F_9 ( 2 )
+ F_9 ( 2 ) ;
}
T_1 F_10 ( void )
{
F_11 ( V_49 != 22 ) ;
return F_9 ( 4 )
+ F_9 ( 0 )
+ F_8 ()
+ F_9 ( 4 )
+ F_9 ( 4 )
+ F_9 ( 4 )
+ F_9 ( 4 )
+ F_9 ( 12 )
+ F_9 ( 2 )
+ F_9 ( 4 )
+ F_9 ( 0 )
+ F_9 ( 2 )
+ F_9 ( 40 )
+ F_9 ( 2 )
+ F_9 ( 28 ) ;
}
static bool F_12 ( const T_3 * V_50 , T_1 V_4 )
{
int V_51 ;
if ( ! V_50 )
return false ;
for ( V_51 = 0 ; V_51 < V_4 ; V_51 ++ )
if ( V_50 [ V_51 ] )
return false ;
return true ;
}
static int F_13 ( const struct V_52 * V_53 ,
const struct V_52 * V_54 [] ,
T_2 * V_55 , bool log , bool V_56 )
{
const struct V_52 * V_57 ;
T_2 V_58 ;
int V_59 ;
V_58 = * V_55 ;
F_14 (nla, attr, rem) {
T_4 type = F_15 ( V_57 ) ;
int V_60 ;
if ( type > V_61 ) {
F_7 ( log , L_3 ,
type , V_61 ) ;
return - V_62 ;
}
if ( V_58 & ( 1 << type ) ) {
F_7 ( log , L_4 , type ) ;
return - V_62 ;
}
V_60 = V_63 [ type ] ;
if ( F_16 ( V_57 ) != V_60 && V_60 != - 1 ) {
F_7 ( log , L_5 ,
type , F_16 ( V_57 ) , V_60 ) ;
return - V_62 ;
}
if ( ! V_56 || ! F_12 ( F_17 ( V_57 ) , V_60 ) ) {
V_58 |= 1 << type ;
V_54 [ type ] = V_57 ;
}
}
if ( V_59 ) {
F_7 ( log , L_6 , V_59 ) ;
return - V_62 ;
}
* V_55 = V_58 ;
return 0 ;
}
static int F_18 ( const struct V_52 * V_53 ,
const struct V_52 * V_54 [] , T_2 * V_55 ,
bool log )
{
return F_13 ( V_53 , V_54 , V_55 , log , true ) ;
}
static int F_19 ( const struct V_52 * V_53 ,
const struct V_52 * V_54 [] , T_2 * V_55 ,
bool log )
{
return F_13 ( V_53 , V_54 , V_55 , log , false ) ;
}
static int F_20 ( const struct V_52 * V_54 ,
struct V_1 * V_2 , bool V_5 ,
bool log )
{
unsigned long V_64 ;
if ( F_16 ( V_54 ) > sizeof( V_2 -> V_30 -> V_65 ) ) {
F_7 ( log , L_7 ,
F_16 ( V_54 ) , sizeof( V_2 -> V_30 -> V_65 ) ) ;
return - V_62 ;
}
if ( F_16 ( V_54 ) % 4 != 0 ) {
F_7 ( log , L_8 ,
F_16 ( V_54 ) ) ;
return - V_62 ;
}
if ( ! V_5 ) {
F_21 ( V_2 , V_66 , F_16 ( V_54 ) ,
false ) ;
} else {
if ( V_2 -> V_30 -> V_66 != F_16 ( V_54 ) ) {
F_7 ( log , L_9 ,
V_2 -> V_30 -> V_66 , F_16 ( V_54 ) ) ;
return - V_62 ;
}
F_21 ( V_2 , V_66 , 0xff , true ) ;
}
V_64 = ( unsigned long ) F_22 ( (struct V_67 * ) 0 ,
F_16 ( V_54 ) ) ;
F_23 ( V_2 , V_64 , F_17 ( V_54 ) ,
F_16 ( V_54 ) , V_5 ) ;
return 0 ;
}
static int F_24 ( const struct V_52 * V_53 ,
struct V_1 * V_2 , bool V_5 ,
bool log )
{
struct V_52 * V_54 ;
int V_59 ;
bool V_68 = false ;
T_5 V_69 = 0 ;
F_14 (a, attr, rem) {
int type = F_15 ( V_54 ) ;
int V_70 ;
static const T_6 V_71 [ V_72 + 1 ] = {
[ V_73 ] = sizeof( T_2 ) ,
[ V_74 ] = sizeof( T_6 ) ,
[ V_75 ] = sizeof( T_6 ) ,
[ V_76 ] = 1 ,
[ V_77 ] = 1 ,
[ V_78 ] = 0 ,
[ V_79 ] = 0 ,
[ V_80 ] = sizeof( T_4 ) ,
[ V_81 ] = sizeof( T_4 ) ,
[ V_82 ] = 0 ,
[ V_83 ] = - 1 ,
} ;
if ( type > V_72 ) {
F_7 ( log , L_10 ,
type , V_72 ) ;
return - V_62 ;
}
if ( V_71 [ type ] != F_16 ( V_54 ) &&
V_71 [ type ] != - 1 ) {
F_7 ( log , L_11 ,
type , F_16 ( V_54 ) , V_71 [ type ] ) ;
return - V_62 ;
}
switch ( type ) {
case V_73 :
F_21 ( V_2 , V_84 . V_85 ,
F_25 ( V_54 ) , V_5 ) ;
V_69 |= V_86 ;
break;
case V_74 :
F_21 ( V_2 , V_84 . V_87 ,
F_26 ( V_54 ) , V_5 ) ;
break;
case V_75 :
F_21 ( V_2 , V_84 . V_88 ,
F_26 ( V_54 ) , V_5 ) ;
break;
case V_76 :
F_21 ( V_2 , V_84 . V_89 ,
F_27 ( V_54 ) , V_5 ) ;
break;
case V_77 :
F_21 ( V_2 , V_84 . V_90 ,
F_27 ( V_54 ) , V_5 ) ;
V_68 = true ;
break;
case V_78 :
V_69 |= V_91 ;
break;
case V_79 :
V_69 |= V_92 ;
break;
case V_80 :
F_21 ( V_2 , V_84 . V_93 ,
F_28 ( V_54 ) , V_5 ) ;
break;
case V_81 :
F_21 ( V_2 , V_84 . V_94 ,
F_28 ( V_54 ) , V_5 ) ;
break;
case V_82 :
V_69 |= V_95 ;
break;
case V_83 :
V_70 = F_20 ( V_54 , V_2 , V_5 , log ) ;
if ( V_70 )
return V_70 ;
V_69 |= V_96 ;
break;
default:
F_7 ( log , L_12 ,
type ) ;
return - V_62 ;
}
}
F_21 ( V_2 , V_84 . V_69 , V_69 , V_5 ) ;
if ( V_59 > 0 ) {
F_7 ( log , L_13 ,
V_59 ) ;
return - V_62 ;
}
if ( ! V_5 ) {
if ( ! V_2 -> V_30 -> V_84 . V_88 ) {
F_7 ( log , L_14 ) ;
return - V_62 ;
}
if ( ! V_68 ) {
F_7 ( log , L_15 ) ;
return - V_62 ;
}
}
return 0 ;
}
static int F_29 ( struct V_97 * V_98 ,
const struct V_99 * V_100 ,
const struct V_101 * V_65 ,
int V_102 )
{
if ( V_100 -> V_69 & V_86 &&
F_30 ( V_98 , V_73 , V_100 -> V_85 ) )
return - V_103 ;
if ( V_100 -> V_87 &&
F_31 ( V_98 , V_74 , V_100 -> V_87 ) )
return - V_103 ;
if ( V_100 -> V_88 &&
F_31 ( V_98 , V_75 , V_100 -> V_88 ) )
return - V_103 ;
if ( V_100 -> V_89 &&
F_32 ( V_98 , V_76 , V_100 -> V_89 ) )
return - V_103 ;
if ( F_32 ( V_98 , V_77 , V_100 -> V_90 ) )
return - V_103 ;
if ( ( V_100 -> V_69 & V_91 ) &&
F_33 ( V_98 , V_78 ) )
return - V_103 ;
if ( ( V_100 -> V_69 & V_92 ) &&
F_33 ( V_98 , V_79 ) )
return - V_103 ;
if ( V_100 -> V_93 &&
F_34 ( V_98 , V_80 , V_100 -> V_93 ) )
return - V_103 ;
if ( V_100 -> V_94 &&
F_34 ( V_98 , V_81 , V_100 -> V_94 ) )
return - V_103 ;
if ( ( V_100 -> V_69 & V_95 ) &&
F_33 ( V_98 , V_82 ) )
return - V_103 ;
if ( V_65 &&
F_35 ( V_98 , V_83 ,
V_102 , V_65 ) )
return - V_103 ;
return 0 ;
}
static int F_36 ( struct V_97 * V_98 ,
const struct V_99 * V_100 ,
const struct V_101 * V_65 ,
int V_102 )
{
struct V_52 * V_57 ;
int V_70 ;
V_57 = F_37 ( V_98 , V_27 ) ;
if ( ! V_57 )
return - V_103 ;
V_70 = F_29 ( V_98 , V_100 , V_65 , V_102 ) ;
if ( V_70 )
return V_70 ;
F_38 ( V_98 , V_57 ) ;
return 0 ;
}
int F_39 ( struct V_97 * V_98 ,
const struct V_104 * V_105 )
{
return F_29 ( V_98 , & V_105 -> V_106 ,
V_105 -> V_107 ,
V_105 -> V_108 ) ;
}
static int F_40 ( struct V_1 * V_2 , T_2 * V_58 ,
const struct V_52 * * V_54 , bool V_5 ,
bool log )
{
if ( * V_58 & ( 1 << V_109 ) ) {
T_6 V_110 = F_41 ( V_54 [ V_109 ] ) ;
F_21 ( V_2 , V_111 , V_110 , V_5 ) ;
* V_58 &= ~ ( 1 << V_109 ) ;
}
if ( * V_58 & ( 1 << V_112 ) ) {
T_6 V_113 = F_41 ( V_54 [ V_112 ] ) ;
F_21 ( V_2 , V_113 , V_113 , V_5 ) ;
* V_58 &= ~ ( 1 << V_112 ) ;
}
if ( * V_58 & ( 1 << V_114 ) ) {
F_21 ( V_2 , V_115 . V_116 ,
F_41 ( V_54 [ V_114 ] ) , V_5 ) ;
* V_58 &= ~ ( 1 << V_114 ) ;
}
if ( * V_58 & ( 1 << V_28 ) ) {
T_6 V_117 = F_41 ( V_54 [ V_28 ] ) ;
if ( V_5 ) {
V_117 = 0xffffffff ;
} else if ( V_117 >= V_118 ) {
F_7 ( log , L_16 ,
V_117 , V_118 ) ;
return - V_62 ;
}
F_21 ( V_2 , V_115 . V_117 , V_117 , V_5 ) ;
* V_58 &= ~ ( 1 << V_28 ) ;
} else if ( ! V_5 ) {
F_21 ( V_2 , V_115 . V_117 , V_118 , V_5 ) ;
}
if ( * V_58 & ( 1 << V_119 ) ) {
T_7 V_120 = F_41 ( V_54 [ V_119 ] ) ;
F_21 ( V_2 , V_115 . V_121 , V_120 , V_5 ) ;
* V_58 &= ~ ( 1 << V_119 ) ;
}
if ( * V_58 & ( 1 << V_27 ) ) {
if ( F_24 ( V_54 [ V_27 ] , V_2 ,
V_5 , log ) )
return - V_62 ;
* V_58 &= ~ ( 1 << V_27 ) ;
}
return 0 ;
}
static int F_42 ( struct V_1 * V_2 , T_2 V_58 ,
const struct V_52 * * V_54 , bool V_5 ,
bool log )
{
int V_70 ;
V_70 = F_40 ( V_2 , & V_58 , V_54 , V_5 , log ) ;
if ( V_70 )
return V_70 ;
if ( V_58 & ( 1 << V_14 ) ) {
const struct V_122 * V_123 ;
V_123 = F_17 ( V_54 [ V_14 ] ) ;
F_43 ( V_2 , V_31 . V_46 ,
V_123 -> V_124 , V_125 , V_5 ) ;
F_43 ( V_2 , V_31 . V_126 ,
V_123 -> V_127 , V_125 , V_5 ) ;
V_58 &= ~ ( 1 << V_14 ) ;
}
if ( V_58 & ( 1 << V_128 ) ) {
T_5 V_129 ;
V_129 = F_28 ( V_54 [ V_128 ] ) ;
if ( ! ( V_129 & F_5 ( V_130 ) ) ) {
if ( V_5 )
F_7 ( log , L_17 ) ;
else
F_7 ( log , L_18 ) ;
return - V_62 ;
}
F_21 ( V_2 , V_31 . V_129 , V_129 , V_5 ) ;
V_58 &= ~ ( 1 << V_128 ) ;
}
if ( V_58 & ( 1 << V_29 ) ) {
T_5 V_131 ;
V_131 = F_28 ( V_54 [ V_29 ] ) ;
if ( V_5 ) {
V_131 = F_5 ( 0xffff ) ;
} else if ( F_44 ( V_131 ) < V_132 ) {
F_7 ( log , L_19 ,
F_44 ( V_131 ) , V_132 ) ;
return - V_62 ;
}
F_21 ( V_2 , V_31 . type , V_131 , V_5 ) ;
V_58 &= ~ ( 1 << V_29 ) ;
} else if ( ! V_5 ) {
F_21 ( V_2 , V_31 . type , F_5 ( V_133 ) , V_5 ) ;
}
if ( V_58 & ( 1 << V_16 ) ) {
const struct V_134 * V_135 ;
V_135 = F_17 ( V_54 [ V_16 ] ) ;
if ( ! V_5 && V_135 -> V_136 > V_137 ) {
F_7 ( log , L_20 ,
V_135 -> V_136 , V_137 ) ;
return - V_62 ;
}
F_21 ( V_2 , V_35 . V_38 ,
V_135 -> V_138 , V_5 ) ;
F_21 ( V_2 , V_35 . V_139 ,
V_135 -> V_89 , V_5 ) ;
F_21 ( V_2 , V_35 . V_68 ,
V_135 -> V_90 , V_5 ) ;
F_21 ( V_2 , V_35 . V_36 ,
V_135 -> V_136 , V_5 ) ;
F_21 ( V_2 , V_140 . V_141 . V_46 ,
V_135 -> V_87 , V_5 ) ;
F_21 ( V_2 , V_140 . V_141 . V_126 ,
V_135 -> V_88 , V_5 ) ;
V_58 &= ~ ( 1 << V_16 ) ;
}
if ( V_58 & ( 1 << V_17 ) ) {
const struct V_142 * V_143 ;
V_143 = F_17 ( V_54 [ V_17 ] ) ;
if ( ! V_5 && V_143 -> V_144 > V_137 ) {
F_7 ( log , L_21 ,
V_143 -> V_144 , V_137 ) ;
return - V_62 ;
}
if ( ! V_5 && V_143 -> V_145 & F_45 ( 0xFFF00000 ) ) {
F_7 ( log , L_22 ,
F_46 ( V_143 -> V_145 ) , ( 1 << 20 ) - 1 ) ;
return - V_62 ;
}
F_21 ( V_2 , V_146 . V_147 ,
V_143 -> V_145 , V_5 ) ;
F_21 ( V_2 , V_35 . V_38 ,
V_143 -> V_148 , V_5 ) ;
F_21 ( V_2 , V_35 . V_139 ,
V_143 -> V_149 , V_5 ) ;
F_21 ( V_2 , V_35 . V_68 ,
V_143 -> V_150 , V_5 ) ;
F_21 ( V_2 , V_35 . V_36 ,
V_143 -> V_144 , V_5 ) ;
F_43 ( V_2 , V_146 . V_141 . V_46 ,
V_143 -> V_151 ,
sizeof( V_2 -> V_30 -> V_146 . V_141 . V_46 ) ,
V_5 ) ;
F_43 ( V_2 , V_146 . V_141 . V_126 ,
V_143 -> V_152 ,
sizeof( V_2 -> V_30 -> V_146 . V_141 . V_126 ) ,
V_5 ) ;
V_58 &= ~ ( 1 << V_17 ) ;
}
if ( V_58 & ( 1 << V_24 ) ) {
const struct V_153 * V_154 ;
V_154 = F_17 ( V_54 [ V_24 ] ) ;
if ( ! V_5 && ( V_154 -> V_155 & F_5 ( 0xff00 ) ) ) {
F_7 ( log , L_23 ,
V_154 -> V_155 ) ;
return - V_62 ;
}
F_21 ( V_2 , V_140 . V_141 . V_46 ,
V_154 -> V_156 , V_5 ) ;
F_21 ( V_2 , V_140 . V_141 . V_126 ,
V_154 -> V_157 , V_5 ) ;
F_21 ( V_2 , V_35 . V_38 ,
F_44 ( V_154 -> V_155 ) , V_5 ) ;
F_43 ( V_2 , V_140 . V_158 . V_159 ,
V_154 -> V_160 , V_125 , V_5 ) ;
F_43 ( V_2 , V_140 . V_158 . V_161 ,
V_154 -> V_162 , V_125 , V_5 ) ;
V_58 &= ~ ( 1 << V_24 ) ;
}
if ( V_58 & ( 1 << V_26 ) ) {
const struct V_163 * V_164 ;
V_164 = F_17 ( V_54 [ V_26 ] ) ;
F_21 ( V_2 , V_165 . V_166 ,
V_164 -> V_167 , V_5 ) ;
V_58 &= ~ ( 1 << V_26 ) ;
}
if ( V_58 & ( 1 << V_18 ) ) {
const struct V_168 * V_169 ;
V_169 = F_17 ( V_54 [ V_18 ] ) ;
F_21 ( V_2 , V_45 . V_46 , V_169 -> V_170 , V_5 ) ;
F_21 ( V_2 , V_45 . V_126 , V_169 -> V_171 , V_5 ) ;
V_58 &= ~ ( 1 << V_18 ) ;
}
if ( V_58 & ( 1 << V_19 ) ) {
F_21 ( V_2 , V_45 . V_172 ,
F_28 ( V_54 [ V_19 ] ) ,
V_5 ) ;
V_58 &= ~ ( 1 << V_19 ) ;
}
if ( V_58 & ( 1 << V_20 ) ) {
const struct V_173 * V_174 ;
V_174 = F_17 ( V_54 [ V_20 ] ) ;
F_21 ( V_2 , V_45 . V_46 , V_174 -> V_175 , V_5 ) ;
F_21 ( V_2 , V_45 . V_126 , V_174 -> V_176 , V_5 ) ;
V_58 &= ~ ( 1 << V_20 ) ;
}
if ( V_58 & ( 1 << V_21 ) ) {
const struct V_177 * V_178 ;
V_178 = F_17 ( V_54 [ V_21 ] ) ;
F_21 ( V_2 , V_45 . V_46 , V_178 -> V_179 , V_5 ) ;
F_21 ( V_2 , V_45 . V_126 , V_178 -> V_180 , V_5 ) ;
V_58 &= ~ ( 1 << V_21 ) ;
}
if ( V_58 & ( 1 << V_22 ) ) {
const struct V_181 * V_182 ;
V_182 = F_17 ( V_54 [ V_22 ] ) ;
F_21 ( V_2 , V_45 . V_46 ,
F_5 ( V_182 -> V_183 ) , V_5 ) ;
F_21 ( V_2 , V_45 . V_126 ,
F_5 ( V_182 -> V_184 ) , V_5 ) ;
V_58 &= ~ ( 1 << V_22 ) ;
}
if ( V_58 & ( 1 << V_23 ) ) {
const struct V_185 * V_186 ;
V_186 = F_17 ( V_54 [ V_23 ] ) ;
F_21 ( V_2 , V_45 . V_46 ,
F_5 ( V_186 -> V_187 ) , V_5 ) ;
F_21 ( V_2 , V_45 . V_126 ,
F_5 ( V_186 -> V_188 ) , V_5 ) ;
V_58 &= ~ ( 1 << V_23 ) ;
}
if ( V_58 & ( 1 << V_25 ) ) {
const struct V_189 * V_190 ;
V_190 = F_17 ( V_54 [ V_25 ] ) ;
F_43 ( V_2 , V_146 . V_191 . V_192 ,
V_190 -> V_193 ,
sizeof( V_2 -> V_30 -> V_146 . V_191 . V_192 ) ,
V_5 ) ;
F_43 ( V_2 , V_146 . V_191 . V_194 ,
V_190 -> V_195 , V_125 , V_5 ) ;
F_43 ( V_2 , V_146 . V_191 . V_196 ,
V_190 -> V_197 , V_125 , V_5 ) ;
V_58 &= ~ ( 1 << V_25 ) ;
}
if ( V_58 != 0 ) {
F_7 ( log , L_24 ,
( unsigned long long ) V_58 ) ;
return - V_62 ;
}
return 0 ;
}
static void F_47 ( struct V_52 * V_53 , T_3 V_198 , bool V_199 )
{
struct V_52 * V_57 ;
int V_59 ;
F_14 (nla, attr, rem) {
if ( V_199 && V_63 [ F_15 ( V_57 ) ] == - 1 )
F_47 ( V_57 , V_198 , false ) ;
else
memset ( F_17 ( V_57 ) , V_198 , F_16 ( V_57 ) ) ;
}
}
static void F_48 ( struct V_52 * V_53 , T_3 V_198 )
{
F_47 ( V_53 , V_198 , true ) ;
}
int F_49 ( struct V_1 * V_2 ,
const struct V_52 * V_200 ,
const struct V_52 * V_201 ,
bool log )
{
const struct V_52 * V_54 [ V_61 + 1 ] ;
const struct V_52 * V_202 ;
struct V_52 * V_203 = NULL ;
T_2 V_11 = 0 ;
T_2 V_12 = 0 ;
bool V_204 = false ;
int V_70 ;
V_70 = F_19 ( V_200 , V_54 , & V_11 , log ) ;
if ( V_70 )
return V_70 ;
if ( ( V_11 & ( 1 << V_14 ) ) &&
( V_11 & ( 1 << V_29 ) ) &&
( F_28 ( V_54 [ V_29 ] ) == F_5 ( V_205 ) ) ) {
T_5 V_129 ;
if ( ! ( ( V_11 & ( 1 << V_128 ) ) &&
( V_11 & ( 1 << V_206 ) ) ) ) {
F_7 ( log , L_25 ) ;
return - V_62 ;
}
V_11 &= ~ ( 1 << V_29 ) ;
V_129 = F_28 ( V_54 [ V_128 ] ) ;
V_202 = V_54 [ V_206 ] ;
V_11 &= ~ ( 1 << V_206 ) ;
V_204 = true ;
if ( V_129 & F_5 ( V_130 ) ) {
V_70 = F_19 ( V_202 , V_54 , & V_11 , log ) ;
if ( V_70 )
return V_70 ;
} else if ( ! V_129 ) {
if ( F_16 ( V_202 ) ) {
F_7 ( log , L_26 ) ;
return - V_62 ;
}
} else {
F_7 ( log , L_27 ) ;
return - V_62 ;
}
}
V_70 = F_42 ( V_2 , V_11 , V_54 , false , log ) ;
if ( V_70 )
return V_70 ;
if ( V_2 -> V_10 ) {
if ( ! V_201 ) {
V_203 = F_50 ( V_200 ,
F_9 ( F_16 ( V_200 ) ) ,
V_207 ) ;
if ( ! V_203 )
return - V_208 ;
F_48 ( V_203 , 0xff ) ;
if ( V_2 -> V_30 -> V_84 . V_88 )
F_51 ( V_2 , V_84 ,
0xff , true ) ;
V_201 = V_203 ;
}
V_70 = F_18 ( V_201 , V_54 , & V_12 , log ) ;
if ( V_70 )
goto V_209;
F_21 ( V_2 , V_31 . V_129 , F_5 ( 0xffff ) , true ) ;
if ( V_12 & 1 << V_206 ) {
T_5 V_131 = 0 ;
T_5 V_129 = 0 ;
if ( ! V_204 ) {
F_7 ( log , L_28 ) ;
V_70 = - V_62 ;
goto V_209;
}
V_12 &= ~ ( 1 << V_206 ) ;
if ( V_54 [ V_29 ] )
V_131 = F_28 ( V_54 [ V_29 ] ) ;
if ( V_131 == F_5 ( 0xffff ) ) {
V_12 &= ~ ( 1 << V_29 ) ;
V_202 = V_54 [ V_206 ] ;
V_70 = F_18 ( V_202 , V_54 ,
& V_12 , log ) ;
if ( V_70 )
goto V_209;
} else {
F_7 ( log , L_29 ,
F_44 ( V_131 ) ) ;
V_70 = - V_62 ;
goto V_209;
}
if ( V_54 [ V_128 ] )
V_129 = F_28 ( V_54 [ V_128 ] ) ;
if ( ! ( V_129 & F_5 ( V_130 ) ) ) {
F_7 ( log , L_30 ,
F_44 ( V_129 ) ) ;
V_70 = - V_62 ;
goto V_209;
}
}
V_70 = F_42 ( V_2 , V_12 , V_54 , true , log ) ;
if ( V_70 )
goto V_209;
}
if ( ! F_4 ( V_2 , V_11 , V_12 , log ) )
V_70 = - V_62 ;
V_209:
F_52 ( V_203 ) ;
return V_70 ;
}
int F_53 ( const struct V_52 * V_53 ,
struct V_67 * V_30 ,
bool log )
{
const struct V_52 * V_54 [ V_61 + 1 ] ;
struct V_1 V_2 ;
T_2 V_58 = 0 ;
int V_70 ;
V_70 = F_19 ( V_53 , V_54 , & V_58 , log ) ;
if ( V_70 )
return - V_62 ;
memset ( & V_2 , 0 , sizeof( V_2 ) ) ;
V_2 . V_30 = V_30 ;
V_30 -> V_115 . V_117 = V_118 ;
return F_40 ( & V_2 , & V_58 , V_54 , false , log ) ;
}
int F_54 ( const struct V_67 * V_210 ,
const struct V_67 * V_100 , struct V_97 * V_98 )
{
struct V_122 * V_123 ;
struct V_52 * V_57 , * V_202 ;
bool V_5 = ( V_210 != V_100 ) ;
if ( F_55 ( V_98 , V_112 , V_100 -> V_113 ) )
goto V_211;
if ( F_55 ( V_98 , V_109 , V_100 -> V_111 ) )
goto V_211;
if ( F_55 ( V_98 , V_114 , V_100 -> V_115 . V_116 ) )
goto V_211;
if ( ( V_210 -> V_84 . V_88 || V_5 ) ) {
const struct V_101 * V_212 = NULL ;
if ( V_100 -> V_84 . V_69 & V_96 )
V_212 = F_22 ( V_100 , V_210 -> V_66 ) ;
if ( F_36 ( V_98 , & V_100 -> V_84 , V_212 ,
V_210 -> V_66 ) )
goto V_211;
}
if ( V_210 -> V_115 . V_117 == V_118 ) {
if ( V_5 && ( V_100 -> V_115 . V_117 == 0xffff ) )
if ( F_55 ( V_98 , V_28 , 0xffffffff ) )
goto V_211;
} else {
T_4 V_213 ;
V_213 = ! V_5 ? 0 : 0xffff ;
if ( F_55 ( V_98 , V_28 ,
( V_213 << 16 ) | V_100 -> V_115 . V_117 ) )
goto V_211;
}
if ( F_55 ( V_98 , V_119 , V_100 -> V_115 . V_121 ) )
goto V_211;
V_57 = F_56 ( V_98 , V_14 , sizeof( * V_123 ) ) ;
if ( ! V_57 )
goto V_211;
V_123 = F_17 ( V_57 ) ;
F_57 ( V_123 -> V_124 , V_100 -> V_31 . V_46 ) ;
F_57 ( V_123 -> V_127 , V_100 -> V_31 . V_126 ) ;
if ( V_210 -> V_31 . V_129 || V_210 -> V_31 . type == F_5 ( V_205 ) ) {
T_5 V_131 ;
V_131 = ! V_5 ? F_5 ( V_205 ) : F_5 ( 0xffff ) ;
if ( F_34 ( V_98 , V_29 , V_131 ) ||
F_34 ( V_98 , V_128 , V_100 -> V_31 . V_129 ) )
goto V_211;
V_202 = F_37 ( V_98 , V_206 ) ;
if ( ! V_210 -> V_31 . V_129 )
goto V_214;
} else
V_202 = NULL ;
if ( V_210 -> V_31 . type == F_5 ( V_133 ) ) {
if ( V_5 && V_100 -> V_31 . type )
if ( F_34 ( V_98 , V_29 ,
V_100 -> V_31 . type ) )
goto V_211;
goto V_214;
}
if ( F_34 ( V_98 , V_29 , V_100 -> V_31 . type ) )
goto V_211;
if ( V_210 -> V_31 . type == F_5 ( V_34 ) ) {
struct V_134 * V_135 ;
V_57 = F_56 ( V_98 , V_16 , sizeof( * V_135 ) ) ;
if ( ! V_57 )
goto V_211;
V_135 = F_17 ( V_57 ) ;
V_135 -> V_87 = V_100 -> V_140 . V_141 . V_46 ;
V_135 -> V_88 = V_100 -> V_140 . V_141 . V_126 ;
V_135 -> V_138 = V_100 -> V_35 . V_38 ;
V_135 -> V_89 = V_100 -> V_35 . V_139 ;
V_135 -> V_90 = V_100 -> V_35 . V_68 ;
V_135 -> V_136 = V_100 -> V_35 . V_36 ;
} else if ( V_210 -> V_31 . type == F_5 ( V_43 ) ) {
struct V_142 * V_143 ;
V_57 = F_56 ( V_98 , V_17 , sizeof( * V_143 ) ) ;
if ( ! V_57 )
goto V_211;
V_143 = F_17 ( V_57 ) ;
memcpy ( V_143 -> V_151 , & V_100 -> V_146 . V_141 . V_46 ,
sizeof( V_143 -> V_151 ) ) ;
memcpy ( V_143 -> V_152 , & V_100 -> V_146 . V_141 . V_126 ,
sizeof( V_143 -> V_152 ) ) ;
V_143 -> V_145 = V_100 -> V_146 . V_147 ;
V_143 -> V_148 = V_100 -> V_35 . V_38 ;
V_143 -> V_149 = V_100 -> V_35 . V_139 ;
V_143 -> V_150 = V_100 -> V_35 . V_68 ;
V_143 -> V_144 = V_100 -> V_35 . V_36 ;
} else if ( V_210 -> V_31 . type == F_5 ( V_32 ) ||
V_210 -> V_31 . type == F_5 ( V_33 ) ) {
struct V_153 * V_154 ;
V_57 = F_56 ( V_98 , V_24 , sizeof( * V_154 ) ) ;
if ( ! V_57 )
goto V_211;
V_154 = F_17 ( V_57 ) ;
memset ( V_154 , 0 , sizeof( struct V_153 ) ) ;
V_154 -> V_156 = V_100 -> V_140 . V_141 . V_46 ;
V_154 -> V_157 = V_100 -> V_140 . V_141 . V_126 ;
V_154 -> V_155 = F_5 ( V_100 -> V_35 . V_38 ) ;
F_57 ( V_154 -> V_160 , V_100 -> V_140 . V_158 . V_159 ) ;
F_57 ( V_154 -> V_162 , V_100 -> V_140 . V_158 . V_161 ) ;
} else if ( F_6 ( V_210 -> V_31 . type ) ) {
struct V_163 * V_164 ;
V_57 = F_56 ( V_98 , V_26 , sizeof( * V_164 ) ) ;
if ( ! V_57 )
goto V_211;
V_164 = F_17 ( V_57 ) ;
V_164 -> V_167 = V_100 -> V_165 . V_166 ;
}
if ( ( V_210 -> V_31 . type == F_5 ( V_34 ) ||
V_210 -> V_31 . type == F_5 ( V_43 ) ) &&
V_210 -> V_35 . V_36 != V_37 ) {
if ( V_210 -> V_35 . V_38 == V_41 ) {
struct V_168 * V_169 ;
V_57 = F_56 ( V_98 , V_18 , sizeof( * V_169 ) ) ;
if ( ! V_57 )
goto V_211;
V_169 = F_17 ( V_57 ) ;
V_169 -> V_170 = V_100 -> V_45 . V_46 ;
V_169 -> V_171 = V_100 -> V_45 . V_126 ;
if ( F_34 ( V_98 , V_19 ,
V_100 -> V_45 . V_172 ) )
goto V_211;
} else if ( V_210 -> V_35 . V_38 == V_39 ) {
struct V_173 * V_174 ;
V_57 = F_56 ( V_98 , V_20 , sizeof( * V_174 ) ) ;
if ( ! V_57 )
goto V_211;
V_174 = F_17 ( V_57 ) ;
V_174 -> V_175 = V_100 -> V_45 . V_46 ;
V_174 -> V_176 = V_100 -> V_45 . V_126 ;
} else if ( V_210 -> V_35 . V_38 == V_40 ) {
struct V_177 * V_178 ;
V_57 = F_56 ( V_98 , V_21 , sizeof( * V_178 ) ) ;
if ( ! V_57 )
goto V_211;
V_178 = F_17 ( V_57 ) ;
V_178 -> V_179 = V_100 -> V_45 . V_46 ;
V_178 -> V_180 = V_100 -> V_45 . V_126 ;
} else if ( V_210 -> V_31 . type == F_5 ( V_34 ) &&
V_210 -> V_35 . V_38 == V_42 ) {
struct V_181 * V_182 ;
V_57 = F_56 ( V_98 , V_22 , sizeof( * V_182 ) ) ;
if ( ! V_57 )
goto V_211;
V_182 = F_17 ( V_57 ) ;
V_182 -> V_183 = F_44 ( V_100 -> V_45 . V_46 ) ;
V_182 -> V_184 = F_44 ( V_100 -> V_45 . V_126 ) ;
} else if ( V_210 -> V_31 . type == F_5 ( V_43 ) &&
V_210 -> V_35 . V_38 == V_44 ) {
struct V_185 * V_186 ;
V_57 = F_56 ( V_98 , V_23 ,
sizeof( * V_186 ) ) ;
if ( ! V_57 )
goto V_211;
V_186 = F_17 ( V_57 ) ;
V_186 -> V_187 = F_44 ( V_100 -> V_45 . V_46 ) ;
V_186 -> V_188 = F_44 ( V_100 -> V_45 . V_126 ) ;
if ( V_186 -> V_187 == V_47 ||
V_186 -> V_187 == V_48 ) {
struct V_189 * V_190 ;
V_57 = F_56 ( V_98 , V_25 , sizeof( * V_190 ) ) ;
if ( ! V_57 )
goto V_211;
V_190 = F_17 ( V_57 ) ;
memcpy ( V_190 -> V_193 , & V_100 -> V_146 . V_191 . V_192 ,
sizeof( V_190 -> V_193 ) ) ;
F_57 ( V_190 -> V_195 , V_100 -> V_146 . V_191 . V_194 ) ;
F_57 ( V_190 -> V_197 , V_100 -> V_146 . V_191 . V_196 ) ;
}
}
}
V_214:
if ( V_202 )
F_38 ( V_98 , V_202 ) ;
return 0 ;
V_211:
return - V_103 ;
}
static struct V_215 * F_58 ( int V_4 , bool log )
{
struct V_215 * V_216 ;
if ( V_4 > V_217 ) {
F_7 ( log , L_31 , V_4 ) ;
return F_59 ( - V_62 ) ;
}
V_216 = F_60 ( sizeof( * V_216 ) + V_4 , V_207 ) ;
if ( ! V_216 )
return F_59 ( - V_208 ) ;
V_216 -> V_218 = 0 ;
return V_216 ;
}
void F_61 ( struct V_215 * V_219 )
{
F_62 ( V_219 , V_220 ) ;
}
static struct V_52 * F_63 ( struct V_215 * * V_216 ,
int V_221 , bool log )
{
struct V_215 * V_222 ;
int V_223 ;
int V_224 = F_64 ( V_221 ) ;
int V_225 = F_65 ( struct V_215 , V_226 ) +
( * V_216 ) -> V_218 ;
if ( V_224 <= ( F_66 ( * V_216 ) - V_225 ) )
goto V_227;
V_223 = F_66 ( * V_216 ) * 2 ;
if ( V_223 > V_217 ) {
if ( ( V_217 - V_225 ) < V_224 )
return F_59 ( - V_103 ) ;
V_223 = V_217 ;
}
V_222 = F_58 ( V_223 , log ) ;
if ( F_67 ( V_222 ) )
return ( void * ) V_222 ;
memcpy ( V_222 -> V_226 , ( * V_216 ) -> V_226 , ( * V_216 ) -> V_218 ) ;
V_222 -> V_218 = ( * V_216 ) -> V_218 ;
F_52 ( * V_216 ) ;
* V_216 = V_222 ;
V_227:
( * V_216 ) -> V_218 += V_224 ;
return (struct V_52 * ) ( ( unsigned char * ) ( * V_216 ) + V_225 ) ;
}
static struct V_52 * F_68 ( struct V_215 * * V_216 ,
int V_228 , void * V_229 , int V_230 , bool log )
{
struct V_52 * V_54 ;
V_54 = F_63 ( V_216 , F_69 ( V_230 ) , log ) ;
if ( F_67 ( V_54 ) )
return V_54 ;
V_54 -> F_15 = V_228 ;
V_54 -> F_16 = F_69 ( V_230 ) ;
if ( V_229 )
memcpy ( F_17 ( V_54 ) , V_229 , V_230 ) ;
memset ( ( unsigned char * ) V_54 + V_54 -> F_16 , 0 , F_70 ( V_230 ) ) ;
return V_54 ;
}
static int F_71 ( struct V_215 * * V_216 , int V_228 ,
void * V_229 , int V_230 , bool log )
{
struct V_52 * V_54 ;
V_54 = F_68 ( V_216 , V_228 , V_229 , V_230 , log ) ;
return F_72 ( V_54 ) ;
}
static inline int F_73 ( struct V_215 * * V_216 ,
int V_228 , bool log )
{
int V_231 = ( * V_216 ) -> V_218 ;
int V_70 ;
V_70 = F_71 ( V_216 , V_228 , NULL , 0 , log ) ;
if ( V_70 )
return V_70 ;
return V_231 ;
}
static inline void F_74 ( struct V_215 * V_216 ,
int V_232 )
{
struct V_52 * V_54 = (struct V_52 * ) ( ( unsigned char * ) V_216 -> V_226 +
V_232 ) ;
V_54 -> F_16 = V_216 -> V_218 - V_232 ;
}
static int F_75 ( const struct V_52 * V_53 ,
const struct V_67 * V_30 , int V_233 ,
struct V_215 * * V_216 ,
T_5 V_131 , T_5 V_234 , bool log )
{
const struct V_52 * V_58 [ V_235 + 1 ] ;
const struct V_52 * V_236 , * V_226 ;
const struct V_52 * V_54 ;
int V_59 , V_8 , V_70 , V_237 ;
memset ( V_58 , 0 , sizeof( V_58 ) ) ;
F_14 (a, attr, rem) {
int type = F_15 ( V_54 ) ;
if ( ! type || type > V_235 || V_58 [ type ] )
return - V_62 ;
V_58 [ type ] = V_54 ;
}
if ( V_59 )
return - V_62 ;
V_236 = V_58 [ V_238 ] ;
if ( ! V_236 || F_16 ( V_236 ) != sizeof( T_6 ) )
return - V_62 ;
V_226 = V_58 [ V_239 ] ;
if ( ! V_226 || ( F_16 ( V_226 ) && F_16 ( V_226 ) < V_240 ) )
return - V_62 ;
V_8 = F_73 ( V_216 , V_241 , log ) ;
if ( V_8 < 0 )
return V_8 ;
V_70 = F_71 ( V_216 , V_238 ,
F_17 ( V_236 ) , sizeof( T_6 ) , log ) ;
if ( V_70 )
return V_70 ;
V_237 = F_73 ( V_216 , V_239 , log ) ;
if ( V_237 < 0 )
return V_237 ;
V_70 = F_76 ( V_226 , V_30 , V_233 + 1 , V_216 ,
V_131 , V_234 , log ) ;
if ( V_70 )
return V_70 ;
F_74 ( * V_216 , V_237 ) ;
F_74 ( * V_216 , V_8 ) ;
return 0 ;
}
static int F_77 ( const struct V_67 * V_242 ,
T_5 V_131 )
{
if ( ( V_131 == F_5 ( V_34 ) || V_131 == F_5 ( V_43 ) ) &&
( V_242 -> V_45 . V_46 || V_242 -> V_45 . V_126 ) )
return 0 ;
return - V_62 ;
}
void F_78 ( struct V_1 * V_2 ,
struct V_67 * V_30 ,
struct V_243 * V_10 )
{
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_30 = V_30 ;
V_2 -> V_10 = V_10 ;
memset ( V_30 , 0 , sizeof( * V_30 ) ) ;
if ( V_10 ) {
memset ( & V_10 -> V_30 , 0 , sizeof( V_10 -> V_30 ) ) ;
V_10 -> V_7 . V_8 = V_10 -> V_7 . V_9 = 0 ;
}
}
static int F_79 ( const struct V_52 * V_53 ,
struct V_215 * * V_216 , bool log )
{
struct V_1 V_2 ;
struct V_67 V_30 ;
struct V_104 * V_244 ;
struct V_52 * V_54 ;
int V_70 , V_8 ;
F_78 ( & V_2 , & V_30 , NULL ) ;
V_70 = F_24 ( F_17 ( V_53 ) , & V_2 , false , log ) ;
if ( V_70 )
return V_70 ;
if ( V_30 . V_66 ) {
struct V_101 * V_245 = F_22 ( & V_30 ,
V_30 . V_66 ) ;
int V_246 = V_30 . V_66 ;
bool V_247 = false ;
while ( V_246 > 0 ) {
int V_230 ;
if ( V_246 < sizeof( * V_245 ) )
return - V_62 ;
V_230 = sizeof( * V_245 ) + V_245 -> V_248 * 4 ;
if ( V_230 > V_246 )
return - V_62 ;
V_247 |= ! ! ( V_245 -> type & V_249 ) ;
V_245 = (struct V_101 * ) ( ( T_3 * ) V_245 + V_230 ) ;
V_246 -= V_230 ;
} ;
V_30 . V_84 . V_69 |= V_247 ? V_250 : 0 ;
} ;
V_8 = F_73 ( V_216 , V_251 , log ) ;
if ( V_8 < 0 )
return V_8 ;
V_54 = F_68 ( V_216 , V_49 , NULL ,
sizeof( * V_244 ) + V_30 . V_66 , log ) ;
if ( F_67 ( V_54 ) )
return F_80 ( V_54 ) ;
V_244 = F_17 ( V_54 ) ;
V_244 -> V_106 = V_30 . V_84 ;
V_244 -> V_108 = V_30 . V_66 ;
if ( V_244 -> V_108 ) {
memcpy ( ( V_244 + 1 ) , F_22 ( & V_30 , V_30 . V_66 ) ,
V_30 . V_66 ) ;
V_244 -> V_107 = (struct V_101 * ) ( V_244 + 1 ) ;
} else {
V_244 -> V_107 = NULL ;
}
F_74 ( * V_216 , V_8 ) ;
return V_70 ;
}
static int F_81 ( const struct V_52 * V_54 ,
const struct V_67 * V_242 ,
struct V_215 * * V_216 ,
bool * V_252 , T_5 V_131 , bool log )
{
const struct V_52 * V_253 = F_17 ( V_54 ) ;
int V_254 = F_15 ( V_253 ) ;
if ( F_9 ( F_16 ( V_253 ) ) != F_16 ( V_54 ) )
return - V_62 ;
if ( V_254 > V_61 ||
( V_63 [ V_254 ] != F_16 ( V_253 ) &&
V_63 [ V_254 ] != - 1 ) )
return - V_62 ;
switch ( V_254 ) {
const struct V_134 * V_135 ;
const struct V_142 * V_143 ;
int V_70 ;
case V_114 :
case V_119 :
case V_14 :
break;
case V_27 :
if ( F_6 ( V_131 ) )
return - V_62 ;
* V_252 = true ;
V_70 = F_79 ( V_54 , V_216 , log ) ;
if ( V_70 )
return V_70 ;
break;
case V_16 :
if ( V_131 != F_5 ( V_34 ) )
return - V_62 ;
if ( ! V_242 -> V_35 . V_38 )
return - V_62 ;
V_135 = F_17 ( V_253 ) ;
if ( V_135 -> V_138 != V_242 -> V_35 . V_38 )
return - V_62 ;
if ( V_135 -> V_136 != V_242 -> V_35 . V_36 )
return - V_62 ;
break;
case V_17 :
if ( V_131 != F_5 ( V_43 ) )
return - V_62 ;
if ( ! V_242 -> V_35 . V_38 )
return - V_62 ;
V_143 = F_17 ( V_253 ) ;
if ( V_143 -> V_148 != V_242 -> V_35 . V_38 )
return - V_62 ;
if ( V_143 -> V_144 != V_242 -> V_35 . V_36 )
return - V_62 ;
if ( F_46 ( V_143 -> V_145 ) & 0xFFF00000 )
return - V_62 ;
break;
case V_18 :
if ( V_242 -> V_35 . V_38 != V_41 )
return - V_62 ;
return F_77 ( V_242 , V_131 ) ;
case V_20 :
if ( V_242 -> V_35 . V_38 != V_39 )
return - V_62 ;
return F_77 ( V_242 , V_131 ) ;
case V_26 :
if ( ! F_6 ( V_131 ) )
return - V_62 ;
break;
case V_21 :
if ( V_242 -> V_35 . V_38 != V_40 )
return - V_62 ;
return F_77 ( V_242 , V_131 ) ;
default:
return - V_62 ;
}
return 0 ;
}
static int F_82 ( const struct V_52 * V_53 )
{
static const struct V_255 V_256 [ V_257 + 1 ] = {
[ V_258 ] = { . type = V_259 } ,
[ V_260 ] = { . type = V_261 } ,
[ V_262 ] = { . type = V_259 } ,
} ;
struct V_52 * V_54 [ V_257 + 1 ] ;
int error ;
error = F_83 ( V_54 , V_257 ,
V_53 , V_256 ) ;
if ( error )
return error ;
if ( ! V_54 [ V_258 ] ||
! F_41 ( V_54 [ V_258 ] ) )
return - V_62 ;
return 0 ;
}
static int F_84 ( const struct V_52 * V_263 ,
struct V_215 * * V_216 , bool log )
{
int V_264 = F_64 ( V_263 -> F_16 ) ;
struct V_52 * V_265 ;
V_265 = F_63 ( V_216 , V_263 -> F_16 , log ) ;
if ( F_67 ( V_265 ) )
return F_80 ( V_265 ) ;
memcpy ( V_265 , V_263 , V_264 ) ;
return 0 ;
}
static int F_76 ( const struct V_52 * V_53 ,
const struct V_67 * V_30 ,
int V_233 , struct V_215 * * V_216 ,
T_5 V_131 , T_5 V_234 , bool log )
{
const struct V_52 * V_54 ;
int V_59 , V_70 ;
if ( V_233 >= V_266 )
return - V_267 ;
F_14 (a, attr, rem) {
static const T_6 V_268 [ V_269 + 1 ] = {
[ V_270 ] = sizeof( T_6 ) ,
[ V_271 ] = sizeof( T_6 ) ,
[ V_272 ] = ( T_6 ) - 1 ,
[ V_273 ] = sizeof( struct V_274 ) ,
[ V_275 ] = sizeof( T_5 ) ,
[ V_276 ] = sizeof( struct V_277 ) ,
[ V_278 ] = 0 ,
[ V_251 ] = ( T_6 ) - 1 ,
[ V_241 ] = ( T_6 ) - 1 ,
[ V_279 ] = sizeof(struct V_280 )
} ;
const struct V_277 * V_281 ;
int type = F_15 ( V_54 ) ;
bool V_282 ;
if ( type > V_269 ||
( V_268 [ type ] != F_16 ( V_54 ) &&
V_268 [ type ] != ( T_6 ) - 1 ) )
return - V_62 ;
V_282 = false ;
switch ( type ) {
case V_283 :
return - V_62 ;
case V_272 :
V_70 = F_82 ( V_54 ) ;
if ( V_70 )
return V_70 ;
break;
case V_270 :
if ( F_41 ( V_54 ) >= V_118 )
return - V_62 ;
break;
case V_279 : {
const struct V_280 * V_284 = F_17 ( V_54 ) ;
switch ( V_284 -> V_285 ) {
case V_286 :
break;
default:
return - V_62 ;
}
break;
}
case V_278 :
V_234 = F_5 ( 0 ) ;
break;
case V_276 :
V_281 = F_17 ( V_54 ) ;
if ( V_281 -> V_287 != F_5 ( V_205 ) )
return - V_62 ;
if ( ! ( V_281 -> V_234 & F_5 ( V_130 ) ) )
return - V_62 ;
V_234 = V_281 -> V_234 ;
break;
case V_271 :
break;
case V_273 : {
const struct V_274 * V_165 = F_17 ( V_54 ) ;
if ( ! F_6 ( V_165 -> V_288 ) )
return - V_62 ;
if ( V_234 & F_5 ( V_130 ) ||
( V_131 != F_5 ( V_34 ) &&
V_131 != F_5 ( V_43 ) &&
V_131 != F_5 ( V_32 ) &&
V_131 != F_5 ( V_33 ) &&
! F_6 ( V_131 ) ) )
return - V_62 ;
V_131 = V_165 -> V_288 ;
break;
}
case V_275 :
if ( V_234 & F_5 ( V_130 ) ||
! F_6 ( V_131 ) )
return - V_62 ;
V_131 = F_5 ( 0 ) ;
break;
case V_251 :
V_70 = F_81 ( V_54 , V_30 , V_216 ,
& V_282 , V_131 , log ) ;
if ( V_70 )
return V_70 ;
break;
case V_241 :
V_70 = F_75 ( V_54 , V_30 , V_233 , V_216 ,
V_131 , V_234 , log ) ;
if ( V_70 )
return V_70 ;
V_282 = true ;
break;
default:
F_7 ( log , L_32 , type ) ;
return - V_62 ;
}
if ( ! V_282 ) {
V_70 = F_84 ( V_54 , V_216 , log ) ;
if ( V_70 )
return V_70 ;
}
}
if ( V_59 > 0 )
return - V_62 ;
return 0 ;
}
int F_85 ( const struct V_52 * V_53 ,
const struct V_67 * V_30 ,
struct V_215 * * V_216 , bool log )
{
int V_70 ;
* V_216 = F_58 ( F_16 ( V_53 ) , log ) ;
if ( F_67 ( * V_216 ) )
return F_80 ( * V_216 ) ;
V_70 = F_76 ( V_53 , V_30 , 0 , V_216 , V_30 -> V_31 . type ,
V_30 -> V_31 . V_129 , log ) ;
if ( V_70 )
F_52 ( * V_216 ) ;
return V_70 ;
}
static int F_86 ( const struct V_52 * V_53 , struct V_97 * V_98 )
{
const struct V_52 * V_54 ;
struct V_52 * V_8 ;
int V_70 = 0 , V_59 ;
V_8 = F_37 ( V_98 , V_241 ) ;
if ( ! V_8 )
return - V_103 ;
F_14 (a, attr, rem) {
int type = F_15 ( V_54 ) ;
struct V_52 * V_289 ;
switch ( type ) {
case V_238 :
if ( F_35 ( V_98 , V_238 ,
sizeof( T_6 ) , F_17 ( V_54 ) ) )
return - V_103 ;
break;
case V_239 :
V_289 = F_37 ( V_98 , V_239 ) ;
if ( ! V_289 )
return - V_103 ;
V_70 = F_87 ( F_17 ( V_54 ) , F_16 ( V_54 ) , V_98 ) ;
if ( V_70 )
return V_70 ;
F_38 ( V_98 , V_289 ) ;
break;
}
}
F_38 ( V_98 , V_8 ) ;
return V_70 ;
}
static int F_88 ( const struct V_52 * V_54 , struct V_97 * V_98 )
{
const struct V_52 * V_253 = F_17 ( V_54 ) ;
int V_254 = F_15 ( V_253 ) ;
struct V_52 * V_8 ;
int V_70 ;
switch ( V_254 ) {
case V_49 : {
struct V_104 * V_244 = F_17 ( V_253 ) ;
V_8 = F_37 ( V_98 , V_251 ) ;
if ( ! V_8 )
return - V_103 ;
V_70 = F_36 ( V_98 , & V_244 -> V_106 ,
V_244 -> V_108 ?
V_244 -> V_107 : NULL ,
V_244 -> V_108 ) ;
if ( V_70 )
return V_70 ;
F_38 ( V_98 , V_8 ) ;
break;
}
default:
if ( F_35 ( V_98 , V_251 , F_16 ( V_54 ) , V_253 ) )
return - V_103 ;
break;
}
return 0 ;
}
int F_87 ( const struct V_52 * V_53 , int V_230 , struct V_97 * V_98 )
{
const struct V_52 * V_54 ;
int V_59 , V_70 ;
F_89 (a, attr, len, rem) {
int type = F_15 ( V_54 ) ;
switch ( type ) {
case V_251 :
V_70 = F_88 ( V_54 , V_98 ) ;
if ( V_70 )
return V_70 ;
break;
case V_241 :
V_70 = F_86 ( V_54 , V_98 ) ;
if ( V_70 )
return V_70 ;
break;
default:
if ( F_35 ( V_98 , type , F_16 ( V_54 ) , F_17 ( V_54 ) ) )
return - V_103 ;
break;
}
}
return 0 ;
}
