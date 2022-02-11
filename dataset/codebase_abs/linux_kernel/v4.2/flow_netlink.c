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
V_60 = V_63 [ type ] . V_64 ;
if ( F_16 ( V_57 ) != V_60 && V_60 != V_65 ) {
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
unsigned long V_66 ;
if ( F_16 ( V_54 ) > sizeof( V_2 -> V_30 -> V_67 ) ) {
F_7 ( log , L_7 ,
F_16 ( V_54 ) , sizeof( V_2 -> V_30 -> V_67 ) ) ;
return - V_62 ;
}
if ( F_16 ( V_54 ) % 4 != 0 ) {
F_7 ( log , L_8 ,
F_16 ( V_54 ) ) ;
return - V_62 ;
}
if ( ! V_5 ) {
F_21 ( V_2 , V_68 , F_16 ( V_54 ) ,
false ) ;
} else {
if ( V_2 -> V_30 -> V_68 != F_16 ( V_54 ) ) {
F_7 ( log , L_9 ,
V_2 -> V_30 -> V_68 , F_16 ( V_54 ) ) ;
return - V_62 ;
}
F_21 ( V_2 , V_68 , 0xff , true ) ;
}
V_66 = F_22 ( F_16 ( V_54 ) ) ;
F_23 ( V_2 , V_66 , F_17 ( V_54 ) ,
F_16 ( V_54 ) , V_5 ) ;
return 0 ;
}
static int F_24 ( const struct V_52 * V_54 ,
struct V_1 * V_2 , bool V_5 ,
bool log )
{
struct V_52 * V_69 [ V_70 + 1 ] ;
unsigned long V_66 ;
struct V_71 V_72 ;
int V_73 ;
F_11 ( sizeof( V_72 ) > sizeof( V_2 -> V_30 -> V_67 ) ) ;
V_73 = F_25 ( V_69 , V_70 , V_54 , V_74 ) ;
if ( V_73 < 0 )
return V_73 ;
memset ( & V_72 , 0 , sizeof( V_72 ) ) ;
if ( V_69 [ V_75 ] )
V_72 . V_76 = F_26 ( V_69 [ V_75 ] ) ;
if ( ! V_5 )
F_21 ( V_2 , V_68 , sizeof( V_72 ) , false ) ;
else
F_21 ( V_2 , V_68 , 0xff , true ) ;
V_66 = F_22 ( sizeof( V_72 ) ) ;
F_23 ( V_2 , V_66 , & V_72 , sizeof( V_72 ) ,
V_5 ) ;
return 0 ;
}
static int F_27 ( const struct V_52 * V_53 ,
struct V_1 * V_2 , bool V_5 ,
bool log )
{
struct V_52 * V_54 ;
int V_59 ;
bool V_77 = false ;
T_5 V_78 = 0 ;
int V_79 = 0 ;
F_14 (a, attr, rem) {
int type = F_15 ( V_54 ) ;
int V_73 ;
if ( type > V_80 ) {
F_7 ( log , L_10 ,
type , V_80 ) ;
return - V_62 ;
}
if ( V_81 [ type ] . V_64 != F_16 ( V_54 ) &&
V_81 [ type ] . V_64 != V_65 ) {
F_7 ( log , L_11 ,
type , F_16 ( V_54 ) , V_81 [ type ] . V_64 ) ;
return - V_62 ;
}
switch ( type ) {
case V_82 :
F_21 ( V_2 , V_83 . V_84 ,
F_28 ( V_54 ) , V_5 ) ;
V_78 |= V_85 ;
break;
case V_86 :
F_21 ( V_2 , V_83 . V_87 ,
F_29 ( V_54 ) , V_5 ) ;
break;
case V_88 :
F_21 ( V_2 , V_83 . V_89 ,
F_29 ( V_54 ) , V_5 ) ;
break;
case V_90 :
F_21 ( V_2 , V_83 . V_91 ,
F_30 ( V_54 ) , V_5 ) ;
break;
case V_92 :
F_21 ( V_2 , V_83 . V_93 ,
F_30 ( V_54 ) , V_5 ) ;
V_77 = true ;
break;
case V_94 :
V_78 |= V_95 ;
break;
case V_96 :
V_78 |= V_97 ;
break;
case V_98 :
F_21 ( V_2 , V_83 . V_99 ,
F_31 ( V_54 ) , V_5 ) ;
break;
case V_100 :
F_21 ( V_2 , V_83 . V_101 ,
F_31 ( V_54 ) , V_5 ) ;
break;
case V_102 :
V_78 |= V_103 ;
break;
case V_104 :
if ( V_79 ) {
F_7 ( log , L_12 ) ;
return - V_62 ;
}
V_73 = F_20 ( V_54 , V_2 , V_5 , log ) ;
if ( V_73 )
return V_73 ;
V_78 |= V_105 ;
V_79 = type ;
break;
case V_106 :
if ( V_79 ) {
F_7 ( log , L_12 ) ;
return - V_62 ;
}
V_73 = F_24 ( V_54 , V_2 , V_5 , log ) ;
if ( V_73 )
return V_73 ;
V_78 |= V_107 ;
V_79 = type ;
break;
default:
F_7 ( log , L_13 ,
type ) ;
return - V_62 ;
}
}
F_21 ( V_2 , V_83 . V_78 , V_78 , V_5 ) ;
if ( V_59 > 0 ) {
F_7 ( log , L_14 ,
V_59 ) ;
return - V_62 ;
}
if ( ! V_5 ) {
if ( ! V_2 -> V_30 -> V_83 . V_89 ) {
F_7 ( log , L_15 ) ;
return - V_62 ;
}
if ( ! V_77 ) {
F_7 ( log , L_16 ) ;
return - V_62 ;
}
}
return V_79 ;
}
static int F_32 ( struct V_108 * V_109 ,
const void * V_67 , int V_110 )
{
const struct V_71 * V_72 = V_67 ;
struct V_52 * V_57 ;
V_57 = F_33 ( V_109 , V_106 ) ;
if ( ! V_57 )
return - V_111 ;
if ( F_34 ( V_109 , V_75 , V_72 -> V_76 ) < 0 )
return - V_111 ;
F_35 ( V_109 , V_57 ) ;
return 0 ;
}
static int F_36 ( struct V_108 * V_109 ,
const struct V_112 * V_113 ,
const void * V_67 , int V_110 )
{
if ( V_113 -> V_78 & V_85 &&
F_37 ( V_109 , V_82 , V_113 -> V_84 ) )
return - V_111 ;
if ( V_113 -> V_87 &&
F_38 ( V_109 , V_86 ,
V_113 -> V_87 ) )
return - V_111 ;
if ( V_113 -> V_89 &&
F_38 ( V_109 , V_88 ,
V_113 -> V_89 ) )
return - V_111 ;
if ( V_113 -> V_91 &&
F_39 ( V_109 , V_90 , V_113 -> V_91 ) )
return - V_111 ;
if ( F_39 ( V_109 , V_92 , V_113 -> V_93 ) )
return - V_111 ;
if ( ( V_113 -> V_78 & V_95 ) &&
F_40 ( V_109 , V_94 ) )
return - V_111 ;
if ( ( V_113 -> V_78 & V_97 ) &&
F_40 ( V_109 , V_96 ) )
return - V_111 ;
if ( V_113 -> V_99 &&
F_41 ( V_109 , V_98 , V_113 -> V_99 ) )
return - V_111 ;
if ( V_113 -> V_101 &&
F_41 ( V_109 , V_100 , V_113 -> V_101 ) )
return - V_111 ;
if ( ( V_113 -> V_78 & V_103 ) &&
F_40 ( V_109 , V_102 ) )
return - V_111 ;
if ( V_67 ) {
if ( V_113 -> V_78 & V_105 &&
F_42 ( V_109 , V_104 ,
V_110 , V_67 ) )
return - V_111 ;
else if ( V_113 -> V_78 & V_107 &&
F_32 ( V_109 , V_67 , V_110 ) )
return - V_111 ;
}
return 0 ;
}
static int F_43 ( struct V_108 * V_109 ,
const struct V_112 * V_113 ,
const void * V_67 , int V_110 )
{
struct V_52 * V_57 ;
int V_73 ;
V_57 = F_33 ( V_109 , V_27 ) ;
if ( ! V_57 )
return - V_111 ;
V_73 = F_36 ( V_109 , V_113 , V_67 , V_110 ) ;
if ( V_73 )
return V_73 ;
F_35 ( V_109 , V_57 ) ;
return 0 ;
}
int F_44 ( struct V_108 * V_109 ,
const struct V_114 * V_115 )
{
return F_36 ( V_109 , & V_115 -> V_116 ,
V_115 -> V_117 ,
V_115 -> V_118 ) ;
}
static int F_45 ( struct V_1 * V_2 , T_2 * V_58 ,
const struct V_52 * * V_54 , bool V_5 ,
bool log )
{
if ( * V_58 & ( 1 << V_119 ) ) {
T_6 V_120 = F_26 ( V_54 [ V_119 ] ) ;
F_21 ( V_2 , V_121 , V_120 , V_5 ) ;
* V_58 &= ~ ( 1 << V_119 ) ;
}
if ( * V_58 & ( 1 << V_122 ) ) {
T_6 V_123 = F_26 ( V_54 [ V_122 ] ) ;
F_21 ( V_2 , V_123 , V_123 , V_5 ) ;
* V_58 &= ~ ( 1 << V_122 ) ;
}
if ( * V_58 & ( 1 << V_124 ) ) {
F_21 ( V_2 , V_125 . V_126 ,
F_26 ( V_54 [ V_124 ] ) , V_5 ) ;
* V_58 &= ~ ( 1 << V_124 ) ;
}
if ( * V_58 & ( 1 << V_28 ) ) {
T_6 V_127 = F_26 ( V_54 [ V_28 ] ) ;
if ( V_5 ) {
V_127 = 0xffffffff ;
} else if ( V_127 >= V_128 ) {
F_7 ( log , L_17 ,
V_127 , V_128 ) ;
return - V_62 ;
}
F_21 ( V_2 , V_125 . V_127 , V_127 , V_5 ) ;
* V_58 &= ~ ( 1 << V_28 ) ;
} else if ( ! V_5 ) {
F_21 ( V_2 , V_125 . V_127 , V_128 , V_5 ) ;
}
if ( * V_58 & ( 1 << V_129 ) ) {
T_7 V_130 = F_26 ( V_54 [ V_129 ] ) ;
F_21 ( V_2 , V_125 . V_131 , V_130 , V_5 ) ;
* V_58 &= ~ ( 1 << V_129 ) ;
}
if ( * V_58 & ( 1 << V_27 ) ) {
if ( F_27 ( V_54 [ V_27 ] , V_2 ,
V_5 , log ) < 0 )
return - V_62 ;
* V_58 &= ~ ( 1 << V_27 ) ;
}
return 0 ;
}
static int F_46 ( struct V_1 * V_2 , T_2 V_58 ,
const struct V_52 * * V_54 , bool V_5 ,
bool log )
{
int V_73 ;
V_73 = F_45 ( V_2 , & V_58 , V_54 , V_5 , log ) ;
if ( V_73 )
return V_73 ;
if ( V_58 & ( 1 << V_14 ) ) {
const struct V_132 * V_133 ;
V_133 = F_17 ( V_54 [ V_14 ] ) ;
F_47 ( V_2 , V_31 . V_46 ,
V_133 -> V_134 , V_135 , V_5 ) ;
F_47 ( V_2 , V_31 . V_136 ,
V_133 -> V_137 , V_135 , V_5 ) ;
V_58 &= ~ ( 1 << V_14 ) ;
}
if ( V_58 & ( 1 << V_138 ) ) {
T_5 V_139 ;
V_139 = F_31 ( V_54 [ V_138 ] ) ;
if ( ! ( V_139 & F_5 ( V_140 ) ) ) {
if ( V_5 )
F_7 ( log , L_18 ) ;
else
F_7 ( log , L_19 ) ;
return - V_62 ;
}
F_21 ( V_2 , V_31 . V_139 , V_139 , V_5 ) ;
V_58 &= ~ ( 1 << V_138 ) ;
}
if ( V_58 & ( 1 << V_29 ) ) {
T_5 V_141 ;
V_141 = F_31 ( V_54 [ V_29 ] ) ;
if ( V_5 ) {
V_141 = F_5 ( 0xffff ) ;
} else if ( ! F_48 ( V_141 ) ) {
F_7 ( log , L_20 ,
F_49 ( V_141 ) , V_142 ) ;
return - V_62 ;
}
F_21 ( V_2 , V_31 . type , V_141 , V_5 ) ;
V_58 &= ~ ( 1 << V_29 ) ;
} else if ( ! V_5 ) {
F_21 ( V_2 , V_31 . type , F_5 ( V_143 ) , V_5 ) ;
}
if ( V_58 & ( 1 << V_16 ) ) {
const struct V_144 * V_145 ;
V_145 = F_17 ( V_54 [ V_16 ] ) ;
if ( ! V_5 && V_145 -> V_146 > V_147 ) {
F_7 ( log , L_21 ,
V_145 -> V_146 , V_147 ) ;
return - V_62 ;
}
F_21 ( V_2 , V_35 . V_38 ,
V_145 -> V_148 , V_5 ) ;
F_21 ( V_2 , V_35 . V_149 ,
V_145 -> V_91 , V_5 ) ;
F_21 ( V_2 , V_35 . V_77 ,
V_145 -> V_93 , V_5 ) ;
F_21 ( V_2 , V_35 . V_36 ,
V_145 -> V_146 , V_5 ) ;
F_21 ( V_2 , V_150 . V_151 . V_46 ,
V_145 -> V_87 , V_5 ) ;
F_21 ( V_2 , V_150 . V_151 . V_136 ,
V_145 -> V_89 , V_5 ) ;
V_58 &= ~ ( 1 << V_16 ) ;
}
if ( V_58 & ( 1 << V_17 ) ) {
const struct V_152 * V_153 ;
V_153 = F_17 ( V_54 [ V_17 ] ) ;
if ( ! V_5 && V_153 -> V_154 > V_147 ) {
F_7 ( log , L_22 ,
V_153 -> V_154 , V_147 ) ;
return - V_62 ;
}
if ( ! V_5 && V_153 -> V_155 & F_50 ( 0xFFF00000 ) ) {
F_7 ( log , L_23 ,
F_51 ( V_153 -> V_155 ) , ( 1 << 20 ) - 1 ) ;
return - V_62 ;
}
F_21 ( V_2 , V_156 . V_157 ,
V_153 -> V_155 , V_5 ) ;
F_21 ( V_2 , V_35 . V_38 ,
V_153 -> V_158 , V_5 ) ;
F_21 ( V_2 , V_35 . V_149 ,
V_153 -> V_159 , V_5 ) ;
F_21 ( V_2 , V_35 . V_77 ,
V_153 -> V_160 , V_5 ) ;
F_21 ( V_2 , V_35 . V_36 ,
V_153 -> V_154 , V_5 ) ;
F_47 ( V_2 , V_156 . V_151 . V_46 ,
V_153 -> V_161 ,
sizeof( V_2 -> V_30 -> V_156 . V_151 . V_46 ) ,
V_5 ) ;
F_47 ( V_2 , V_156 . V_151 . V_136 ,
V_153 -> V_162 ,
sizeof( V_2 -> V_30 -> V_156 . V_151 . V_136 ) ,
V_5 ) ;
V_58 &= ~ ( 1 << V_17 ) ;
}
if ( V_58 & ( 1 << V_24 ) ) {
const struct V_163 * V_164 ;
V_164 = F_17 ( V_54 [ V_24 ] ) ;
if ( ! V_5 && ( V_164 -> V_165 & F_5 ( 0xff00 ) ) ) {
F_7 ( log , L_24 ,
V_164 -> V_165 ) ;
return - V_62 ;
}
F_21 ( V_2 , V_150 . V_151 . V_46 ,
V_164 -> V_166 , V_5 ) ;
F_21 ( V_2 , V_150 . V_151 . V_136 ,
V_164 -> V_167 , V_5 ) ;
F_21 ( V_2 , V_35 . V_38 ,
F_49 ( V_164 -> V_165 ) , V_5 ) ;
F_47 ( V_2 , V_150 . V_168 . V_169 ,
V_164 -> V_170 , V_135 , V_5 ) ;
F_47 ( V_2 , V_150 . V_168 . V_171 ,
V_164 -> V_172 , V_135 , V_5 ) ;
V_58 &= ~ ( 1 << V_24 ) ;
}
if ( V_58 & ( 1 << V_26 ) ) {
const struct V_173 * V_174 ;
V_174 = F_17 ( V_54 [ V_26 ] ) ;
F_21 ( V_2 , V_175 . V_176 ,
V_174 -> V_177 , V_5 ) ;
V_58 &= ~ ( 1 << V_26 ) ;
}
if ( V_58 & ( 1 << V_18 ) ) {
const struct V_178 * V_179 ;
V_179 = F_17 ( V_54 [ V_18 ] ) ;
F_21 ( V_2 , V_45 . V_46 , V_179 -> V_180 , V_5 ) ;
F_21 ( V_2 , V_45 . V_136 , V_179 -> V_181 , V_5 ) ;
V_58 &= ~ ( 1 << V_18 ) ;
}
if ( V_58 & ( 1 << V_19 ) ) {
F_21 ( V_2 , V_45 . V_182 ,
F_31 ( V_54 [ V_19 ] ) ,
V_5 ) ;
V_58 &= ~ ( 1 << V_19 ) ;
}
if ( V_58 & ( 1 << V_20 ) ) {
const struct V_183 * V_184 ;
V_184 = F_17 ( V_54 [ V_20 ] ) ;
F_21 ( V_2 , V_45 . V_46 , V_184 -> V_185 , V_5 ) ;
F_21 ( V_2 , V_45 . V_136 , V_184 -> V_186 , V_5 ) ;
V_58 &= ~ ( 1 << V_20 ) ;
}
if ( V_58 & ( 1 << V_21 ) ) {
const struct V_187 * V_188 ;
V_188 = F_17 ( V_54 [ V_21 ] ) ;
F_21 ( V_2 , V_45 . V_46 , V_188 -> V_189 , V_5 ) ;
F_21 ( V_2 , V_45 . V_136 , V_188 -> V_190 , V_5 ) ;
V_58 &= ~ ( 1 << V_21 ) ;
}
if ( V_58 & ( 1 << V_22 ) ) {
const struct V_191 * V_192 ;
V_192 = F_17 ( V_54 [ V_22 ] ) ;
F_21 ( V_2 , V_45 . V_46 ,
F_5 ( V_192 -> V_193 ) , V_5 ) ;
F_21 ( V_2 , V_45 . V_136 ,
F_5 ( V_192 -> V_194 ) , V_5 ) ;
V_58 &= ~ ( 1 << V_22 ) ;
}
if ( V_58 & ( 1 << V_23 ) ) {
const struct V_195 * V_196 ;
V_196 = F_17 ( V_54 [ V_23 ] ) ;
F_21 ( V_2 , V_45 . V_46 ,
F_5 ( V_196 -> V_197 ) , V_5 ) ;
F_21 ( V_2 , V_45 . V_136 ,
F_5 ( V_196 -> V_198 ) , V_5 ) ;
V_58 &= ~ ( 1 << V_23 ) ;
}
if ( V_58 & ( 1 << V_25 ) ) {
const struct V_199 * V_200 ;
V_200 = F_17 ( V_54 [ V_25 ] ) ;
F_47 ( V_2 , V_156 . V_201 . V_202 ,
V_200 -> V_203 ,
sizeof( V_2 -> V_30 -> V_156 . V_201 . V_202 ) ,
V_5 ) ;
F_47 ( V_2 , V_156 . V_201 . V_204 ,
V_200 -> V_205 , V_135 , V_5 ) ;
F_47 ( V_2 , V_156 . V_201 . V_206 ,
V_200 -> V_207 , V_135 , V_5 ) ;
V_58 &= ~ ( 1 << V_25 ) ;
}
if ( V_58 != 0 ) {
F_7 ( log , L_25 ,
( unsigned long long ) V_58 ) ;
return - V_62 ;
}
return 0 ;
}
static void F_52 ( struct V_52 * V_53 , T_3 V_208 ,
const struct V_209 * V_210 )
{
struct V_52 * V_57 ;
int V_59 ;
F_14 (nla, attr, rem) {
if ( V_210 && V_210 [ F_15 ( V_57 ) ] . V_64 == V_65 )
F_52 ( V_57 , V_208 , V_210 [ F_15 ( V_57 ) ] . V_211 ) ;
else
memset ( F_17 ( V_57 ) , V_208 , F_16 ( V_57 ) ) ;
}
}
static void F_53 ( struct V_52 * V_53 , T_3 V_208 )
{
F_52 ( V_53 , V_208 , V_63 ) ;
}
int F_54 ( struct V_1 * V_2 ,
const struct V_52 * V_212 ,
const struct V_52 * V_213 ,
bool log )
{
const struct V_52 * V_54 [ V_61 + 1 ] ;
const struct V_52 * V_214 ;
struct V_52 * V_215 = NULL ;
T_2 V_11 = 0 ;
T_2 V_12 = 0 ;
bool V_216 = false ;
int V_73 ;
V_73 = F_19 ( V_212 , V_54 , & V_11 , log ) ;
if ( V_73 )
return V_73 ;
if ( ( V_11 & ( 1 << V_14 ) ) &&
( V_11 & ( 1 << V_29 ) ) &&
( F_31 ( V_54 [ V_29 ] ) == F_5 ( V_217 ) ) ) {
T_5 V_139 ;
if ( ! ( ( V_11 & ( 1 << V_138 ) ) &&
( V_11 & ( 1 << V_218 ) ) ) ) {
F_7 ( log , L_26 ) ;
return - V_62 ;
}
V_11 &= ~ ( 1 << V_29 ) ;
V_139 = F_31 ( V_54 [ V_138 ] ) ;
V_214 = V_54 [ V_218 ] ;
V_11 &= ~ ( 1 << V_218 ) ;
V_216 = true ;
if ( V_139 & F_5 ( V_140 ) ) {
V_73 = F_19 ( V_214 , V_54 , & V_11 , log ) ;
if ( V_73 )
return V_73 ;
} else if ( ! V_139 ) {
if ( F_16 ( V_214 ) ) {
F_7 ( log , L_27 ) ;
return - V_62 ;
}
} else {
F_7 ( log , L_28 ) ;
return - V_62 ;
}
}
V_73 = F_46 ( V_2 , V_11 , V_54 , false , log ) ;
if ( V_73 )
return V_73 ;
if ( V_2 -> V_10 ) {
if ( ! V_213 ) {
V_215 = F_55 ( V_212 ,
F_9 ( F_16 ( V_212 ) ) ,
V_219 ) ;
if ( ! V_215 )
return - V_220 ;
F_53 ( V_215 , 0xff ) ;
if ( V_2 -> V_30 -> V_83 . V_89 )
F_56 ( V_2 , V_83 ,
0xff , true ) ;
V_213 = V_215 ;
}
V_73 = F_18 ( V_213 , V_54 , & V_12 , log ) ;
if ( V_73 )
goto V_221;
F_21 ( V_2 , V_31 . V_139 , F_5 ( 0xffff ) , true ) ;
if ( V_12 & 1 << V_218 ) {
T_5 V_141 = 0 ;
T_5 V_139 = 0 ;
if ( ! V_216 ) {
F_7 ( log , L_29 ) ;
V_73 = - V_62 ;
goto V_221;
}
V_12 &= ~ ( 1 << V_218 ) ;
if ( V_54 [ V_29 ] )
V_141 = F_31 ( V_54 [ V_29 ] ) ;
if ( V_141 == F_5 ( 0xffff ) ) {
V_12 &= ~ ( 1 << V_29 ) ;
V_214 = V_54 [ V_218 ] ;
V_73 = F_18 ( V_214 , V_54 ,
& V_12 , log ) ;
if ( V_73 )
goto V_221;
} else {
F_7 ( log , L_30 ,
F_49 ( V_141 ) ) ;
V_73 = - V_62 ;
goto V_221;
}
if ( V_54 [ V_138 ] )
V_139 = F_31 ( V_54 [ V_138 ] ) ;
if ( ! ( V_139 & F_5 ( V_140 ) ) ) {
F_7 ( log , L_31 ,
F_49 ( V_139 ) ) ;
V_73 = - V_62 ;
goto V_221;
}
}
V_73 = F_46 ( V_2 , V_12 , V_54 , true , log ) ;
if ( V_73 )
goto V_221;
}
if ( ! F_4 ( V_2 , V_11 , V_12 , log ) )
V_73 = - V_62 ;
V_221:
F_57 ( V_215 ) ;
return V_73 ;
}
static T_1 F_58 ( const struct V_52 * V_53 , bool log )
{
T_1 V_64 ;
if ( ! V_53 )
return 0 ;
V_64 = F_16 ( V_53 ) ;
if ( V_64 < 1 || V_64 > V_222 ) {
F_7 ( log , L_32 ,
F_16 ( V_53 ) , V_222 ) ;
return 0 ;
}
return V_64 ;
}
bool F_59 ( struct V_223 * V_224 , const struct V_52 * V_53 ,
bool log )
{
V_224 -> V_225 = F_58 ( V_53 , log ) ;
if ( V_224 -> V_225 )
memcpy ( V_224 -> V_226 , F_17 ( V_53 ) , V_224 -> V_225 ) ;
return V_224 -> V_225 ;
}
int F_60 ( struct V_223 * V_224 , const struct V_52 * V_226 ,
const struct V_227 * V_30 , bool log )
{
struct V_227 * V_228 ;
if ( F_59 ( V_224 , V_226 , log ) )
return 0 ;
V_228 = F_61 ( sizeof( * V_228 ) , V_219 ) ;
if ( ! V_228 )
return - V_220 ;
memcpy ( V_228 , V_30 , sizeof( * V_30 ) ) ;
V_224 -> V_229 = V_228 ;
return 0 ;
}
T_6 F_62 ( const struct V_52 * V_53 )
{
return V_53 ? F_26 ( V_53 ) : 0 ;
}
int F_63 ( const struct V_52 * V_53 ,
struct V_227 * V_30 ,
bool log )
{
const struct V_52 * V_54 [ V_61 + 1 ] ;
struct V_1 V_2 ;
T_2 V_58 = 0 ;
int V_73 ;
V_73 = F_19 ( V_53 , V_54 , & V_58 , log ) ;
if ( V_73 )
return - V_62 ;
memset ( & V_2 , 0 , sizeof( V_2 ) ) ;
V_2 . V_30 = V_30 ;
V_30 -> V_125 . V_127 = V_128 ;
return F_45 ( & V_2 , & V_58 , V_54 , false , log ) ;
}
static int F_64 ( const struct V_227 * V_230 ,
const struct V_227 * V_113 , bool V_5 ,
struct V_108 * V_109 )
{
struct V_132 * V_133 ;
struct V_52 * V_57 , * V_214 ;
if ( F_34 ( V_109 , V_122 , V_113 -> V_123 ) )
goto V_231;
if ( F_34 ( V_109 , V_119 , V_113 -> V_121 ) )
goto V_231;
if ( F_34 ( V_109 , V_124 , V_113 -> V_125 . V_126 ) )
goto V_231;
if ( ( V_230 -> V_83 . V_89 || V_5 ) ) {
const void * V_72 = NULL ;
if ( V_113 -> V_83 . V_78 & V_232 )
V_72 = F_65 ( V_113 , V_230 -> V_68 ) ;
if ( F_43 ( V_109 , & V_113 -> V_83 , V_72 ,
V_230 -> V_68 ) )
goto V_231;
}
if ( V_230 -> V_125 . V_127 == V_128 ) {
if ( V_5 && ( V_113 -> V_125 . V_127 == 0xffff ) )
if ( F_34 ( V_109 , V_28 , 0xffffffff ) )
goto V_231;
} else {
T_4 V_233 ;
V_233 = ! V_5 ? 0 : 0xffff ;
if ( F_34 ( V_109 , V_28 ,
( V_233 << 16 ) | V_113 -> V_125 . V_127 ) )
goto V_231;
}
if ( F_34 ( V_109 , V_129 , V_113 -> V_125 . V_131 ) )
goto V_231;
V_57 = F_66 ( V_109 , V_14 , sizeof( * V_133 ) ) ;
if ( ! V_57 )
goto V_231;
V_133 = F_17 ( V_57 ) ;
F_67 ( V_133 -> V_134 , V_113 -> V_31 . V_46 ) ;
F_67 ( V_133 -> V_137 , V_113 -> V_31 . V_136 ) ;
if ( V_230 -> V_31 . V_139 || V_230 -> V_31 . type == F_5 ( V_217 ) ) {
T_5 V_141 ;
V_141 = ! V_5 ? F_5 ( V_217 ) : F_5 ( 0xffff ) ;
if ( F_41 ( V_109 , V_29 , V_141 ) ||
F_41 ( V_109 , V_138 , V_113 -> V_31 . V_139 ) )
goto V_231;
V_214 = F_33 ( V_109 , V_218 ) ;
if ( ! V_230 -> V_31 . V_139 )
goto V_234;
} else
V_214 = NULL ;
if ( V_230 -> V_31 . type == F_5 ( V_143 ) ) {
if ( V_5 && V_113 -> V_31 . type )
if ( F_41 ( V_109 , V_29 ,
V_113 -> V_31 . type ) )
goto V_231;
goto V_234;
}
if ( F_41 ( V_109 , V_29 , V_113 -> V_31 . type ) )
goto V_231;
if ( V_230 -> V_31 . type == F_5 ( V_34 ) ) {
struct V_144 * V_145 ;
V_57 = F_66 ( V_109 , V_16 , sizeof( * V_145 ) ) ;
if ( ! V_57 )
goto V_231;
V_145 = F_17 ( V_57 ) ;
V_145 -> V_87 = V_113 -> V_150 . V_151 . V_46 ;
V_145 -> V_89 = V_113 -> V_150 . V_151 . V_136 ;
V_145 -> V_148 = V_113 -> V_35 . V_38 ;
V_145 -> V_91 = V_113 -> V_35 . V_149 ;
V_145 -> V_93 = V_113 -> V_35 . V_77 ;
V_145 -> V_146 = V_113 -> V_35 . V_36 ;
} else if ( V_230 -> V_31 . type == F_5 ( V_43 ) ) {
struct V_152 * V_153 ;
V_57 = F_66 ( V_109 , V_17 , sizeof( * V_153 ) ) ;
if ( ! V_57 )
goto V_231;
V_153 = F_17 ( V_57 ) ;
memcpy ( V_153 -> V_161 , & V_113 -> V_156 . V_151 . V_46 ,
sizeof( V_153 -> V_161 ) ) ;
memcpy ( V_153 -> V_162 , & V_113 -> V_156 . V_151 . V_136 ,
sizeof( V_153 -> V_162 ) ) ;
V_153 -> V_155 = V_113 -> V_156 . V_157 ;
V_153 -> V_158 = V_113 -> V_35 . V_38 ;
V_153 -> V_159 = V_113 -> V_35 . V_149 ;
V_153 -> V_160 = V_113 -> V_35 . V_77 ;
V_153 -> V_154 = V_113 -> V_35 . V_36 ;
} else if ( V_230 -> V_31 . type == F_5 ( V_32 ) ||
V_230 -> V_31 . type == F_5 ( V_33 ) ) {
struct V_163 * V_164 ;
V_57 = F_66 ( V_109 , V_24 , sizeof( * V_164 ) ) ;
if ( ! V_57 )
goto V_231;
V_164 = F_17 ( V_57 ) ;
memset ( V_164 , 0 , sizeof( struct V_163 ) ) ;
V_164 -> V_166 = V_113 -> V_150 . V_151 . V_46 ;
V_164 -> V_167 = V_113 -> V_150 . V_151 . V_136 ;
V_164 -> V_165 = F_5 ( V_113 -> V_35 . V_38 ) ;
F_67 ( V_164 -> V_170 , V_113 -> V_150 . V_168 . V_169 ) ;
F_67 ( V_164 -> V_172 , V_113 -> V_150 . V_168 . V_171 ) ;
} else if ( F_6 ( V_230 -> V_31 . type ) ) {
struct V_173 * V_174 ;
V_57 = F_66 ( V_109 , V_26 , sizeof( * V_174 ) ) ;
if ( ! V_57 )
goto V_231;
V_174 = F_17 ( V_57 ) ;
V_174 -> V_177 = V_113 -> V_175 . V_176 ;
}
if ( ( V_230 -> V_31 . type == F_5 ( V_34 ) ||
V_230 -> V_31 . type == F_5 ( V_43 ) ) &&
V_230 -> V_35 . V_36 != V_37 ) {
if ( V_230 -> V_35 . V_38 == V_41 ) {
struct V_178 * V_179 ;
V_57 = F_66 ( V_109 , V_18 , sizeof( * V_179 ) ) ;
if ( ! V_57 )
goto V_231;
V_179 = F_17 ( V_57 ) ;
V_179 -> V_180 = V_113 -> V_45 . V_46 ;
V_179 -> V_181 = V_113 -> V_45 . V_136 ;
if ( F_41 ( V_109 , V_19 ,
V_113 -> V_45 . V_182 ) )
goto V_231;
} else if ( V_230 -> V_35 . V_38 == V_39 ) {
struct V_183 * V_184 ;
V_57 = F_66 ( V_109 , V_20 , sizeof( * V_184 ) ) ;
if ( ! V_57 )
goto V_231;
V_184 = F_17 ( V_57 ) ;
V_184 -> V_185 = V_113 -> V_45 . V_46 ;
V_184 -> V_186 = V_113 -> V_45 . V_136 ;
} else if ( V_230 -> V_35 . V_38 == V_40 ) {
struct V_187 * V_188 ;
V_57 = F_66 ( V_109 , V_21 , sizeof( * V_188 ) ) ;
if ( ! V_57 )
goto V_231;
V_188 = F_17 ( V_57 ) ;
V_188 -> V_189 = V_113 -> V_45 . V_46 ;
V_188 -> V_190 = V_113 -> V_45 . V_136 ;
} else if ( V_230 -> V_31 . type == F_5 ( V_34 ) &&
V_230 -> V_35 . V_38 == V_42 ) {
struct V_191 * V_192 ;
V_57 = F_66 ( V_109 , V_22 , sizeof( * V_192 ) ) ;
if ( ! V_57 )
goto V_231;
V_192 = F_17 ( V_57 ) ;
V_192 -> V_193 = F_49 ( V_113 -> V_45 . V_46 ) ;
V_192 -> V_194 = F_49 ( V_113 -> V_45 . V_136 ) ;
} else if ( V_230 -> V_31 . type == F_5 ( V_43 ) &&
V_230 -> V_35 . V_38 == V_44 ) {
struct V_195 * V_196 ;
V_57 = F_66 ( V_109 , V_23 ,
sizeof( * V_196 ) ) ;
if ( ! V_57 )
goto V_231;
V_196 = F_17 ( V_57 ) ;
V_196 -> V_197 = F_49 ( V_113 -> V_45 . V_46 ) ;
V_196 -> V_198 = F_49 ( V_113 -> V_45 . V_136 ) ;
if ( V_196 -> V_197 == V_47 ||
V_196 -> V_197 == V_48 ) {
struct V_199 * V_200 ;
V_57 = F_66 ( V_109 , V_25 , sizeof( * V_200 ) ) ;
if ( ! V_57 )
goto V_231;
V_200 = F_17 ( V_57 ) ;
memcpy ( V_200 -> V_203 , & V_113 -> V_156 . V_201 . V_202 ,
sizeof( V_200 -> V_203 ) ) ;
F_67 ( V_200 -> V_205 , V_113 -> V_156 . V_201 . V_204 ) ;
F_67 ( V_200 -> V_207 , V_113 -> V_156 . V_201 . V_206 ) ;
}
}
}
V_234:
if ( V_214 )
F_35 ( V_109 , V_214 ) ;
return 0 ;
V_231:
return - V_111 ;
}
int F_68 ( const struct V_227 * V_230 ,
const struct V_227 * V_113 , int V_53 , bool V_5 ,
struct V_108 * V_109 )
{
int V_73 ;
struct V_52 * V_57 ;
V_57 = F_33 ( V_109 , V_53 ) ;
if ( ! V_57 )
return - V_111 ;
V_73 = F_64 ( V_230 , V_113 , V_5 , V_109 ) ;
if ( V_73 )
return V_73 ;
F_35 ( V_109 , V_57 ) ;
return 0 ;
}
int F_69 ( const struct V_235 * V_236 , struct V_108 * V_109 )
{
if ( F_70 ( & V_236 -> V_237 ) )
return F_42 ( V_109 , V_238 , V_236 -> V_237 . V_225 ,
V_236 -> V_237 . V_226 ) ;
return F_68 ( V_236 -> V_237 . V_229 , V_236 -> V_237 . V_229 ,
V_239 , false , V_109 ) ;
}
int F_71 ( const struct V_235 * V_236 , struct V_108 * V_109 )
{
return F_68 ( & V_236 -> V_30 , & V_236 -> V_30 ,
V_239 , false , V_109 ) ;
}
int F_72 ( const struct V_235 * V_236 , struct V_108 * V_109 )
{
return F_68 ( & V_236 -> V_30 , & V_236 -> V_10 -> V_30 ,
V_240 , true , V_109 ) ;
}
static struct V_241 * F_73 ( int V_4 , bool log )
{
struct V_241 * V_242 ;
if ( V_4 > V_243 ) {
F_7 ( log , L_33 , V_4 ) ;
return F_74 ( - V_62 ) ;
}
V_242 = F_61 ( sizeof( * V_242 ) + V_4 , V_219 ) ;
if ( ! V_242 )
return F_74 ( - V_220 ) ;
V_242 -> V_244 = 0 ;
return V_242 ;
}
void F_75 ( struct V_241 * V_245 )
{
F_76 ( V_245 , V_246 ) ;
}
static struct V_52 * F_77 ( struct V_241 * * V_242 ,
int V_247 , bool log )
{
struct V_241 * V_248 ;
int V_249 ;
int V_250 = F_78 ( V_247 ) ;
int V_251 = F_79 ( struct V_241 , V_252 ) +
( * V_242 ) -> V_244 ;
if ( V_250 <= ( F_80 ( * V_242 ) - V_251 ) )
goto V_253;
V_249 = F_80 ( * V_242 ) * 2 ;
if ( V_249 > V_243 ) {
if ( ( V_243 - V_251 ) < V_250 )
return F_74 ( - V_111 ) ;
V_249 = V_243 ;
}
V_248 = F_73 ( V_249 , log ) ;
if ( F_81 ( V_248 ) )
return ( void * ) V_248 ;
memcpy ( V_248 -> V_252 , ( * V_242 ) -> V_252 , ( * V_242 ) -> V_244 ) ;
V_248 -> V_244 = ( * V_242 ) -> V_244 ;
F_57 ( * V_242 ) ;
* V_242 = V_248 ;
V_253:
( * V_242 ) -> V_244 += V_250 ;
return (struct V_52 * ) ( ( unsigned char * ) ( * V_242 ) + V_251 ) ;
}
static struct V_52 * F_82 ( struct V_241 * * V_242 ,
int V_254 , void * V_255 , int V_64 , bool log )
{
struct V_52 * V_54 ;
V_54 = F_77 ( V_242 , F_83 ( V_64 ) , log ) ;
if ( F_81 ( V_54 ) )
return V_54 ;
V_54 -> F_15 = V_254 ;
V_54 -> F_16 = F_83 ( V_64 ) ;
if ( V_255 )
memcpy ( F_17 ( V_54 ) , V_255 , V_64 ) ;
memset ( ( unsigned char * ) V_54 + V_54 -> F_16 , 0 , F_84 ( V_64 ) ) ;
return V_54 ;
}
static int F_85 ( struct V_241 * * V_242 , int V_254 ,
void * V_255 , int V_64 , bool log )
{
struct V_52 * V_54 ;
V_54 = F_82 ( V_242 , V_254 , V_255 , V_64 , log ) ;
return F_86 ( V_54 ) ;
}
static inline int F_87 ( struct V_241 * * V_242 ,
int V_254 , bool log )
{
int V_256 = ( * V_242 ) -> V_244 ;
int V_73 ;
V_73 = F_85 ( V_242 , V_254 , NULL , 0 , log ) ;
if ( V_73 )
return V_73 ;
return V_256 ;
}
static inline void F_88 ( struct V_241 * V_242 ,
int V_257 )
{
struct V_52 * V_54 = (struct V_52 * ) ( ( unsigned char * ) V_242 -> V_252 +
V_257 ) ;
V_54 -> F_16 = V_242 -> V_244 - V_257 ;
}
static int F_89 ( const struct V_52 * V_53 ,
const struct V_227 * V_30 , int V_258 ,
struct V_241 * * V_242 ,
T_5 V_141 , T_5 V_259 , bool log )
{
const struct V_52 * V_58 [ V_260 + 1 ] ;
const struct V_52 * V_261 , * V_252 ;
const struct V_52 * V_54 ;
int V_59 , V_8 , V_73 , V_262 ;
memset ( V_58 , 0 , sizeof( V_58 ) ) ;
F_14 (a, attr, rem) {
int type = F_15 ( V_54 ) ;
if ( ! type || type > V_260 || V_58 [ type ] )
return - V_62 ;
V_58 [ type ] = V_54 ;
}
if ( V_59 )
return - V_62 ;
V_261 = V_58 [ V_263 ] ;
if ( ! V_261 || F_16 ( V_261 ) != sizeof( T_6 ) )
return - V_62 ;
V_252 = V_58 [ V_264 ] ;
if ( ! V_252 || ( F_16 ( V_252 ) && F_16 ( V_252 ) < V_265 ) )
return - V_62 ;
V_8 = F_87 ( V_242 , V_266 , log ) ;
if ( V_8 < 0 )
return V_8 ;
V_73 = F_85 ( V_242 , V_263 ,
F_17 ( V_261 ) , sizeof( T_6 ) , log ) ;
if ( V_73 )
return V_73 ;
V_262 = F_87 ( V_242 , V_264 , log ) ;
if ( V_262 < 0 )
return V_262 ;
V_73 = F_90 ( V_252 , V_30 , V_258 + 1 , V_242 ,
V_141 , V_259 , log ) ;
if ( V_73 )
return V_73 ;
F_88 ( * V_242 , V_262 ) ;
F_88 ( * V_242 , V_8 ) ;
return 0 ;
}
void F_91 ( struct V_1 * V_2 ,
struct V_227 * V_30 ,
struct V_267 * V_10 )
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
static int F_92 ( struct V_227 * V_30 )
{
struct V_268 * V_269 ;
int V_270 = V_30 -> V_68 ;
bool V_271 = false ;
V_269 = (struct V_268 * ) F_65 ( V_30 , V_30 -> V_68 ) ;
while ( V_270 > 0 ) {
int V_64 ;
if ( V_270 < sizeof( * V_269 ) )
return - V_62 ;
V_64 = sizeof( * V_269 ) + V_269 -> V_272 * 4 ;
if ( V_64 > V_270 )
return - V_62 ;
V_271 |= ! ! ( V_269 -> type & V_273 ) ;
V_269 = (struct V_268 * ) ( ( T_3 * ) V_269 + V_64 ) ;
V_270 -= V_64 ;
} ;
V_30 -> V_83 . V_78 |= V_271 ? V_274 : 0 ;
return 0 ;
}
static int F_93 ( const struct V_52 * V_53 ,
struct V_241 * * V_242 , bool log )
{
struct V_1 V_2 ;
struct V_227 V_30 ;
struct V_114 * V_275 ;
struct V_52 * V_54 ;
int V_73 = 0 , V_8 , V_79 ;
F_91 ( & V_2 , & V_30 , NULL ) ;
V_79 = F_27 ( F_17 ( V_53 ) , & V_2 , false , log ) ;
if ( V_79 < 0 )
return V_79 ;
if ( V_30 . V_68 ) {
switch ( V_79 ) {
case V_104 :
V_73 = F_92 ( & V_30 ) ;
if ( V_73 < 0 )
return V_73 ;
break;
case V_106 :
break;
}
} ;
V_8 = F_87 ( V_242 , V_276 , log ) ;
if ( V_8 < 0 )
return V_8 ;
V_54 = F_82 ( V_242 , V_49 , NULL ,
sizeof( * V_275 ) + V_30 . V_68 , log ) ;
if ( F_81 ( V_54 ) )
return F_94 ( V_54 ) ;
V_275 = F_17 ( V_54 ) ;
V_275 -> V_116 = V_30 . V_83 ;
V_275 -> V_118 = V_30 . V_68 ;
if ( V_275 -> V_118 ) {
memcpy ( ( V_275 + 1 ) ,
F_65 ( & V_30 , V_30 . V_68 ) , V_30 . V_68 ) ;
V_275 -> V_117 = ( V_275 + 1 ) ;
} else {
V_275 -> V_117 = NULL ;
}
F_88 ( * V_242 , V_8 ) ;
return V_73 ;
}
static bool F_95 ( T_3 * V_255 , int V_64 )
{
T_3 * V_10 = V_255 + V_64 ;
while ( V_64 -- )
if ( * V_255 ++ & ~ * V_10 ++ )
return false ;
return true ;
}
static int F_96 ( const struct V_52 * V_54 ,
const struct V_227 * V_277 ,
struct V_241 * * V_242 ,
bool * V_278 , T_5 V_141 , bool V_279 , bool log )
{
const struct V_52 * V_280 = F_17 ( V_54 ) ;
int V_281 = F_15 ( V_280 ) ;
T_1 V_282 ;
if ( F_9 ( F_16 ( V_280 ) ) != F_16 ( V_54 ) )
return - V_62 ;
V_282 = F_16 ( V_280 ) ;
if ( V_279 )
V_282 /= 2 ;
if ( V_281 > V_61 ||
( V_63 [ V_281 ] . V_64 != V_282 &&
V_63 [ V_281 ] . V_64 != V_65 ) )
return - V_62 ;
if ( V_279 && ! F_95 ( F_17 ( V_280 ) , V_282 ) )
return - V_62 ;
switch ( V_281 ) {
const struct V_144 * V_145 ;
const struct V_152 * V_153 ;
int V_73 ;
case V_124 :
case V_129 :
case V_14 :
break;
case V_27 :
if ( F_6 ( V_141 ) )
return - V_62 ;
if ( V_279 )
return - V_62 ;
* V_278 = true ;
V_73 = F_93 ( V_54 , V_242 , log ) ;
if ( V_73 )
return V_73 ;
break;
case V_16 :
if ( V_141 != F_5 ( V_34 ) )
return - V_62 ;
V_145 = F_17 ( V_280 ) ;
if ( V_279 ) {
const struct V_144 * V_10 = V_145 + 1 ;
if ( V_10 -> V_148 || V_10 -> V_146 )
return - V_62 ;
} else {
if ( V_145 -> V_148 != V_277 -> V_35 . V_38 )
return - V_62 ;
if ( V_145 -> V_146 != V_277 -> V_35 . V_36 )
return - V_62 ;
}
break;
case V_17 :
if ( V_141 != F_5 ( V_43 ) )
return - V_62 ;
V_153 = F_17 ( V_280 ) ;
if ( V_279 ) {
const struct V_152 * V_10 = V_153 + 1 ;
if ( V_10 -> V_158 || V_10 -> V_154 )
return - V_62 ;
if ( F_51 ( V_10 -> V_155 ) & 0xFFF00000 )
return - V_62 ;
} else {
if ( V_153 -> V_158 != V_277 -> V_35 . V_38 )
return - V_62 ;
if ( V_153 -> V_154 != V_277 -> V_35 . V_36 )
return - V_62 ;
}
if ( F_51 ( V_153 -> V_155 ) & 0xFFF00000 )
return - V_62 ;
break;
case V_18 :
if ( ( V_141 != F_5 ( V_34 ) &&
V_141 != F_5 ( V_43 ) ) ||
V_277 -> V_35 . V_38 != V_41 )
return - V_62 ;
break;
case V_20 :
if ( ( V_141 != F_5 ( V_34 ) &&
V_141 != F_5 ( V_43 ) ) ||
V_277 -> V_35 . V_38 != V_39 )
return - V_62 ;
break;
case V_26 :
if ( ! F_6 ( V_141 ) )
return - V_62 ;
break;
case V_21 :
if ( ( V_141 != F_5 ( V_34 ) &&
V_141 != F_5 ( V_43 ) ) ||
V_277 -> V_35 . V_38 != V_40 )
return - V_62 ;
break;
default:
return - V_62 ;
}
if ( ! V_279 && V_281 != V_27 ) {
int V_8 , V_64 = V_282 * 2 ;
struct V_52 * V_283 ;
* V_278 = true ;
V_8 = F_87 ( V_242 ,
V_284 ,
log ) ;
if ( V_8 < 0 )
return V_8 ;
V_283 = F_82 ( V_242 , V_281 , NULL , V_64 , log ) ;
if ( F_81 ( V_283 ) )
return F_94 ( V_283 ) ;
memcpy ( F_17 ( V_283 ) , F_17 ( V_280 ) , V_282 ) ;
memset ( F_17 ( V_283 ) + V_282 , 0xff , V_282 ) ;
if ( V_281 == V_17 ) {
struct V_152 * V_10 = F_17 ( V_283 ) + V_282 ;
V_10 -> V_155 &= F_50 ( 0x000FFFFF ) ;
}
F_88 ( * V_242 , V_8 ) ;
}
return 0 ;
}
static int F_97 ( const struct V_52 * V_53 )
{
static const struct V_285 V_286 [ V_287 + 1 ] = {
[ V_288 ] = { . type = V_289 } ,
[ V_290 ] = { . type = V_291 } ,
[ V_292 ] = { . type = V_289 } ,
} ;
struct V_52 * V_54 [ V_287 + 1 ] ;
int error ;
error = F_25 ( V_54 , V_287 ,
V_53 , V_286 ) ;
if ( error )
return error ;
if ( ! V_54 [ V_288 ] ||
! F_26 ( V_54 [ V_288 ] ) )
return - V_62 ;
return 0 ;
}
static int F_98 ( const struct V_52 * V_293 ,
struct V_241 * * V_242 , bool log )
{
int V_294 = F_78 ( V_293 -> F_16 ) ;
struct V_52 * V_295 ;
V_295 = F_77 ( V_242 , V_293 -> F_16 , log ) ;
if ( F_81 ( V_295 ) )
return F_94 ( V_295 ) ;
memcpy ( V_295 , V_293 , V_294 ) ;
return 0 ;
}
static int F_90 ( const struct V_52 * V_53 ,
const struct V_227 * V_30 ,
int V_258 , struct V_241 * * V_242 ,
T_5 V_141 , T_5 V_259 , bool log )
{
const struct V_52 * V_54 ;
int V_59 , V_73 ;
if ( V_258 >= V_296 )
return - V_297 ;
F_14 (a, attr, rem) {
static const T_6 V_298 [ V_299 + 1 ] = {
[ V_300 ] = sizeof( T_6 ) ,
[ V_301 ] = sizeof( T_6 ) ,
[ V_302 ] = ( T_6 ) - 1 ,
[ V_303 ] = sizeof( struct V_304 ) ,
[ V_305 ] = sizeof( T_5 ) ,
[ V_306 ] = sizeof( struct V_307 ) ,
[ V_308 ] = 0 ,
[ V_276 ] = ( T_6 ) - 1 ,
[ V_309 ] = ( T_6 ) - 1 ,
[ V_266 ] = ( T_6 ) - 1 ,
[ V_310 ] = sizeof(struct V_311 )
} ;
const struct V_307 * V_312 ;
int type = F_15 ( V_54 ) ;
bool V_278 ;
if ( type > V_299 ||
( V_298 [ type ] != F_16 ( V_54 ) &&
V_298 [ type ] != ( T_6 ) - 1 ) )
return - V_62 ;
V_278 = false ;
switch ( type ) {
case V_313 :
return - V_62 ;
case V_302 :
V_73 = F_97 ( V_54 ) ;
if ( V_73 )
return V_73 ;
break;
case V_300 :
if ( F_26 ( V_54 ) >= V_128 )
return - V_62 ;
break;
case V_310 : {
const struct V_311 * V_314 = F_17 ( V_54 ) ;
switch ( V_314 -> V_315 ) {
case V_316 :
break;
default:
return - V_62 ;
}
break;
}
case V_308 :
V_259 = F_5 ( 0 ) ;
break;
case V_306 :
V_312 = F_17 ( V_54 ) ;
if ( V_312 -> V_317 != F_5 ( V_217 ) )
return - V_62 ;
if ( ! ( V_312 -> V_259 & F_5 ( V_140 ) ) )
return - V_62 ;
V_259 = V_312 -> V_259 ;
break;
case V_301 :
break;
case V_303 : {
const struct V_304 * V_175 = F_17 ( V_54 ) ;
if ( ! F_6 ( V_175 -> V_318 ) )
return - V_62 ;
if ( V_259 & F_5 ( V_140 ) ||
( V_141 != F_5 ( V_34 ) &&
V_141 != F_5 ( V_43 ) &&
V_141 != F_5 ( V_32 ) &&
V_141 != F_5 ( V_33 ) &&
! F_6 ( V_141 ) ) )
return - V_62 ;
V_141 = V_175 -> V_318 ;
break;
}
case V_305 :
if ( V_259 & F_5 ( V_140 ) ||
! F_6 ( V_141 ) )
return - V_62 ;
V_141 = F_5 ( 0 ) ;
break;
case V_276 :
V_73 = F_96 ( V_54 , V_30 , V_242 ,
& V_278 , V_141 , false , log ) ;
if ( V_73 )
return V_73 ;
break;
case V_309 :
V_73 = F_96 ( V_54 , V_30 , V_242 ,
& V_278 , V_141 , true , log ) ;
if ( V_73 )
return V_73 ;
break;
case V_266 :
V_73 = F_89 ( V_54 , V_30 , V_258 , V_242 ,
V_141 , V_259 , log ) ;
if ( V_73 )
return V_73 ;
V_278 = true ;
break;
default:
F_7 ( log , L_34 , type ) ;
return - V_62 ;
}
if ( ! V_278 ) {
V_73 = F_98 ( V_54 , V_242 , log ) ;
if ( V_73 )
return V_73 ;
}
}
if ( V_59 > 0 )
return - V_62 ;
return 0 ;
}
int F_99 ( const struct V_52 * V_53 ,
const struct V_227 * V_30 ,
struct V_241 * * V_242 , bool log )
{
int V_73 ;
* V_242 = F_73 ( F_16 ( V_53 ) , log ) ;
if ( F_81 ( * V_242 ) )
return F_94 ( * V_242 ) ;
V_73 = F_90 ( V_53 , V_30 , 0 , V_242 , V_30 -> V_31 . type ,
V_30 -> V_31 . V_139 , log ) ;
if ( V_73 )
F_57 ( * V_242 ) ;
return V_73 ;
}
static int F_100 ( const struct V_52 * V_53 , struct V_108 * V_109 )
{
const struct V_52 * V_54 ;
struct V_52 * V_8 ;
int V_73 = 0 , V_59 ;
V_8 = F_33 ( V_109 , V_266 ) ;
if ( ! V_8 )
return - V_111 ;
F_14 (a, attr, rem) {
int type = F_15 ( V_54 ) ;
struct V_52 * V_319 ;
switch ( type ) {
case V_263 :
if ( F_42 ( V_109 , V_263 ,
sizeof( T_6 ) , F_17 ( V_54 ) ) )
return - V_111 ;
break;
case V_264 :
V_319 = F_33 ( V_109 , V_264 ) ;
if ( ! V_319 )
return - V_111 ;
V_73 = F_101 ( F_17 ( V_54 ) , F_16 ( V_54 ) , V_109 ) ;
if ( V_73 )
return V_73 ;
F_35 ( V_109 , V_319 ) ;
break;
}
}
F_35 ( V_109 , V_8 ) ;
return V_73 ;
}
static int F_102 ( const struct V_52 * V_54 , struct V_108 * V_109 )
{
const struct V_52 * V_280 = F_17 ( V_54 ) ;
int V_281 = F_15 ( V_280 ) ;
struct V_52 * V_8 ;
int V_73 ;
switch ( V_281 ) {
case V_49 : {
struct V_114 * V_275 = F_17 ( V_280 ) ;
V_8 = F_33 ( V_109 , V_276 ) ;
if ( ! V_8 )
return - V_111 ;
V_73 = F_43 ( V_109 , & V_275 -> V_116 ,
V_275 -> V_118 ?
V_275 -> V_117 : NULL ,
V_275 -> V_118 ) ;
if ( V_73 )
return V_73 ;
F_35 ( V_109 , V_8 ) ;
break;
}
default:
if ( F_42 ( V_109 , V_276 , F_16 ( V_54 ) , V_280 ) )
return - V_111 ;
break;
}
return 0 ;
}
static int F_103 ( const struct V_52 * V_54 ,
struct V_108 * V_109 )
{
const struct V_52 * V_280 = F_17 ( V_54 ) ;
struct V_52 * V_57 ;
T_1 V_282 = F_16 ( V_280 ) / 2 ;
V_57 = F_33 ( V_109 , V_276 ) ;
if ( ! V_57 )
return - V_111 ;
if ( F_42 ( V_109 , F_15 ( V_280 ) , V_282 , F_17 ( V_280 ) ) )
return - V_111 ;
F_35 ( V_109 , V_57 ) ;
return 0 ;
}
int F_101 ( const struct V_52 * V_53 , int V_64 , struct V_108 * V_109 )
{
const struct V_52 * V_54 ;
int V_59 , V_73 ;
F_104 (a, attr, len, rem) {
int type = F_15 ( V_54 ) ;
switch ( type ) {
case V_276 :
V_73 = F_102 ( V_54 , V_109 ) ;
if ( V_73 )
return V_73 ;
break;
case V_284 :
V_73 = F_103 ( V_54 , V_109 ) ;
if ( V_73 )
return V_73 ;
break;
case V_266 :
V_73 = F_100 ( V_54 , V_109 ) ;
if ( V_73 )
return V_73 ;
break;
default:
if ( F_42 ( V_109 , type , F_16 ( V_54 ) , F_17 ( V_54 ) ) )
return - V_111 ;
break;
}
}
return 0 ;
}
