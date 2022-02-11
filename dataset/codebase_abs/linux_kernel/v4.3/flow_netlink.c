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
F_11 ( V_49 != 26 ) ;
return F_9 ( 4 )
+ F_9 ( 0 )
+ F_8 ()
+ F_9 ( 4 )
+ F_9 ( 4 )
+ F_9 ( 4 )
+ F_9 ( 4 )
+ F_9 ( 4 )
+ F_9 ( 2 )
+ F_9 ( 4 )
+ F_9 ( 16 )
+ F_9 ( 12 )
+ F_9 ( 2 )
+ F_9 ( 4 )
+ F_9 ( 0 )
+ F_9 ( 2 )
+ F_9 ( 40 )
+ F_9 ( 2 )
+ F_9 ( 28 ) ;
}
static bool F_12 ( unsigned int V_50 , unsigned int V_51 )
{
return V_51 == V_50 ||
V_51 == V_52 ||
V_51 == V_53 ;
}
static bool F_13 ( const T_3 * V_54 , T_1 V_4 )
{
int V_55 ;
if ( ! V_54 )
return false ;
for ( V_55 = 0 ; V_55 < V_4 ; V_55 ++ )
if ( V_54 [ V_55 ] )
return false ;
return true ;
}
static int F_14 ( const struct V_56 * V_57 ,
const struct V_56 * V_58 [] ,
T_2 * V_59 , bool log , bool V_60 )
{
const struct V_56 * V_61 ;
T_2 V_62 ;
int V_63 ;
V_62 = * V_59 ;
F_15 (nla, attr, rem) {
T_4 type = F_16 ( V_61 ) ;
int V_51 ;
if ( type > V_64 ) {
F_7 ( log , L_3 ,
type , V_64 ) ;
return - V_65 ;
}
if ( V_62 & ( 1 << type ) ) {
F_7 ( log , L_4 , type ) ;
return - V_65 ;
}
V_51 = V_66 [ type ] . V_67 ;
if ( ! F_12 ( F_17 ( V_61 ) , V_51 ) ) {
F_7 ( log , L_5 ,
type , F_17 ( V_61 ) , V_51 ) ;
return - V_65 ;
}
if ( ! V_60 || ! F_13 ( F_18 ( V_61 ) , V_51 ) ) {
V_62 |= 1 << type ;
V_58 [ type ] = V_61 ;
}
}
if ( V_63 ) {
F_7 ( log , L_6 , V_63 ) ;
return - V_65 ;
}
* V_59 = V_62 ;
return 0 ;
}
static int F_19 ( const struct V_56 * V_57 ,
const struct V_56 * V_58 [] , T_2 * V_59 ,
bool log )
{
return F_14 ( V_57 , V_58 , V_59 , log , true ) ;
}
static int F_20 ( const struct V_56 * V_57 ,
const struct V_56 * V_58 [] , T_2 * V_59 ,
bool log )
{
return F_14 ( V_57 , V_58 , V_59 , log , false ) ;
}
static int F_21 ( const struct V_56 * V_58 ,
struct V_1 * V_2 , bool V_5 ,
bool log )
{
unsigned long V_68 ;
if ( F_17 ( V_58 ) > sizeof( V_2 -> V_30 -> V_69 ) ) {
F_7 ( log , L_7 ,
F_17 ( V_58 ) , sizeof( V_2 -> V_30 -> V_69 ) ) ;
return - V_65 ;
}
if ( F_17 ( V_58 ) % 4 != 0 ) {
F_7 ( log , L_8 ,
F_17 ( V_58 ) ) ;
return - V_65 ;
}
if ( ! V_5 ) {
F_22 ( V_2 , V_70 , F_17 ( V_58 ) ,
false ) ;
} else {
if ( V_2 -> V_30 -> V_70 != F_17 ( V_58 ) ) {
F_7 ( log , L_9 ,
V_2 -> V_30 -> V_70 , F_17 ( V_58 ) ) ;
return - V_65 ;
}
F_22 ( V_2 , V_70 , 0xff , true ) ;
}
V_68 = F_23 ( F_17 ( V_58 ) ) ;
F_24 ( V_2 , V_68 , F_18 ( V_58 ) ,
F_17 ( V_58 ) , V_5 ) ;
return 0 ;
}
static int F_25 ( const struct V_56 * V_57 ,
struct V_1 * V_2 , bool V_5 ,
bool log )
{
struct V_56 * V_58 ;
int V_63 ;
unsigned long V_68 ;
struct V_71 V_72 ;
F_11 ( sizeof( V_72 ) > sizeof( V_2 -> V_30 -> V_69 ) ) ;
memset ( & V_72 , 0 , sizeof( V_72 ) ) ;
F_15 (a, attr, rem) {
int type = F_16 ( V_58 ) ;
if ( type > V_73 ) {
F_7 ( log , L_10 ,
type , V_73 ) ;
return - V_65 ;
}
if ( ! F_12 ( F_17 ( V_58 ) ,
V_74 [ type ] . V_67 ) ) {
F_7 ( log , L_11 ,
type , F_17 ( V_58 ) ,
V_74 [ type ] . V_67 ) ;
return - V_65 ;
}
switch ( type ) {
case V_75 :
V_72 . V_76 = F_26 ( V_58 ) ;
break;
default:
F_7 ( log , L_12 ,
type ) ;
return - V_65 ;
}
}
if ( V_63 ) {
F_7 ( log , L_13 ,
V_63 ) ;
return - V_65 ;
}
if ( ! V_5 )
F_22 ( V_2 , V_70 , sizeof( V_72 ) , false ) ;
else
F_22 ( V_2 , V_70 , 0xff , true ) ;
V_68 = F_23 ( sizeof( V_72 ) ) ;
F_24 ( V_2 , V_68 , & V_72 , sizeof( V_72 ) ,
V_5 ) ;
return 0 ;
}
static int F_27 ( const struct V_56 * V_57 ,
struct V_1 * V_2 , bool V_5 ,
bool log )
{
struct V_56 * V_58 ;
int V_63 ;
bool V_77 = false ;
T_5 V_78 = 0 ;
int V_79 = 0 ;
F_15 (a, attr, rem) {
int type = F_16 ( V_58 ) ;
int V_80 ;
if ( type > V_81 ) {
F_7 ( log , L_14 ,
type , V_81 ) ;
return - V_65 ;
}
if ( ! F_12 ( F_17 ( V_58 ) ,
V_82 [ type ] . V_67 ) ) {
F_7 ( log , L_15 ,
type , F_17 ( V_58 ) , V_82 [ type ] . V_67 ) ;
return - V_65 ;
}
switch ( type ) {
case V_83 :
F_22 ( V_2 , V_84 . V_85 ,
F_28 ( V_58 ) , V_5 ) ;
V_78 |= V_86 ;
break;
case V_87 :
F_22 ( V_2 , V_84 . V_88 . V_89 . V_46 ,
F_29 ( V_58 ) , V_5 ) ;
break;
case V_90 :
F_22 ( V_2 , V_84 . V_88 . V_89 . V_91 ,
F_29 ( V_58 ) , V_5 ) ;
break;
case V_92 :
F_22 ( V_2 , V_84 . V_93 ,
F_30 ( V_58 ) , V_5 ) ;
break;
case V_94 :
F_22 ( V_2 , V_84 . V_77 ,
F_30 ( V_58 ) , V_5 ) ;
V_77 = true ;
break;
case V_95 :
V_78 |= V_96 ;
break;
case V_97 :
V_78 |= V_98 ;
break;
case V_99 :
F_22 ( V_2 , V_84 . V_100 ,
F_31 ( V_58 ) , V_5 ) ;
break;
case V_101 :
F_22 ( V_2 , V_84 . V_102 ,
F_31 ( V_58 ) , V_5 ) ;
break;
case V_103 :
V_78 |= V_104 ;
break;
case V_105 :
if ( V_79 ) {
F_7 ( log , L_16 ) ;
return - V_65 ;
}
V_80 = F_21 ( V_58 , V_2 , V_5 , log ) ;
if ( V_80 )
return V_80 ;
V_78 |= V_106 ;
V_79 = type ;
break;
case V_107 :
if ( V_79 ) {
F_7 ( log , L_16 ) ;
return - V_65 ;
}
V_80 = F_25 ( V_58 , V_2 , V_5 , log ) ;
if ( V_80 )
return V_80 ;
V_78 |= V_108 ;
V_79 = type ;
break;
default:
F_7 ( log , L_17 ,
type ) ;
return - V_65 ;
}
}
F_22 ( V_2 , V_84 . V_78 , V_78 , V_5 ) ;
if ( V_63 > 0 ) {
F_7 ( log , L_18 ,
V_63 ) ;
return - V_65 ;
}
if ( ! V_5 ) {
if ( ! V_2 -> V_30 -> V_84 . V_88 . V_89 . V_91 ) {
F_7 ( log , L_19 ) ;
return - V_65 ;
}
if ( ! V_77 ) {
F_7 ( log , L_20 ) ;
return - V_65 ;
}
}
return V_79 ;
}
static int F_32 ( struct V_109 * V_110 ,
const void * V_69 , int V_111 )
{
const struct V_71 * V_72 = V_69 ;
struct V_56 * V_61 ;
V_61 = F_33 ( V_110 , V_107 ) ;
if ( ! V_61 )
return - V_112 ;
if ( F_34 ( V_110 , V_75 , V_72 -> V_76 ) < 0 )
return - V_112 ;
F_35 ( V_110 , V_61 ) ;
return 0 ;
}
static int F_36 ( struct V_109 * V_110 ,
const struct V_113 * V_114 ,
const void * V_69 , int V_111 )
{
if ( V_114 -> V_78 & V_86 &&
F_37 ( V_110 , V_83 , V_114 -> V_85 ) )
return - V_112 ;
if ( V_114 -> V_88 . V_89 . V_46 &&
F_38 ( V_110 , V_87 ,
V_114 -> V_88 . V_89 . V_46 ) )
return - V_112 ;
if ( V_114 -> V_88 . V_89 . V_91 &&
F_38 ( V_110 , V_90 ,
V_114 -> V_88 . V_89 . V_91 ) )
return - V_112 ;
if ( V_114 -> V_93 &&
F_39 ( V_110 , V_92 , V_114 -> V_93 ) )
return - V_112 ;
if ( F_39 ( V_110 , V_94 , V_114 -> V_77 ) )
return - V_112 ;
if ( ( V_114 -> V_78 & V_96 ) &&
F_40 ( V_110 , V_95 ) )
return - V_112 ;
if ( ( V_114 -> V_78 & V_98 ) &&
F_40 ( V_110 , V_97 ) )
return - V_112 ;
if ( V_114 -> V_100 &&
F_41 ( V_110 , V_99 , V_114 -> V_100 ) )
return - V_112 ;
if ( V_114 -> V_102 &&
F_41 ( V_110 , V_101 , V_114 -> V_102 ) )
return - V_112 ;
if ( ( V_114 -> V_78 & V_104 ) &&
F_40 ( V_110 , V_103 ) )
return - V_112 ;
if ( V_111 ) {
if ( V_114 -> V_78 & V_106 &&
F_42 ( V_110 , V_105 ,
V_111 , V_69 ) )
return - V_112 ;
else if ( V_114 -> V_78 & V_108 &&
F_32 ( V_110 , V_69 , V_111 ) )
return - V_112 ;
}
return 0 ;
}
static int F_43 ( struct V_109 * V_110 ,
const struct V_113 * V_114 ,
const void * V_69 , int V_111 )
{
struct V_56 * V_61 ;
int V_80 ;
V_61 = F_33 ( V_110 , V_27 ) ;
if ( ! V_61 )
return - V_112 ;
V_80 = F_36 ( V_110 , V_114 , V_69 , V_111 ) ;
if ( V_80 )
return V_80 ;
F_35 ( V_110 , V_61 ) ;
return 0 ;
}
int F_44 ( struct V_109 * V_110 ,
struct V_115 * V_116 )
{
return F_36 ( V_110 , & V_116 -> V_30 ,
F_45 ( V_116 ) ,
V_116 -> V_117 ) ;
}
static int F_46 ( struct V_118 * V_118 , struct V_1 * V_2 ,
T_2 * V_62 , const struct V_56 * * V_58 ,
bool V_5 , bool log )
{
if ( * V_62 & ( 1 << V_119 ) ) {
T_6 V_120 = F_26 ( V_58 [ V_119 ] ) ;
F_22 ( V_2 , V_121 , V_120 , V_5 ) ;
* V_62 &= ~ ( 1 << V_119 ) ;
}
if ( * V_62 & ( 1 << V_122 ) ) {
T_6 V_123 = F_26 ( V_58 [ V_122 ] ) ;
F_22 ( V_2 , V_123 , V_123 , V_5 ) ;
* V_62 &= ~ ( 1 << V_122 ) ;
}
if ( * V_62 & ( 1 << V_124 ) ) {
F_22 ( V_2 , V_125 . V_126 ,
F_26 ( V_58 [ V_124 ] ) , V_5 ) ;
* V_62 &= ~ ( 1 << V_124 ) ;
}
if ( * V_62 & ( 1 << V_28 ) ) {
T_6 V_127 = F_26 ( V_58 [ V_28 ] ) ;
if ( V_5 ) {
V_127 = 0xffffffff ;
} else if ( V_127 >= V_128 ) {
F_7 ( log , L_21 ,
V_127 , V_128 ) ;
return - V_65 ;
}
F_22 ( V_2 , V_125 . V_127 , V_127 , V_5 ) ;
* V_62 &= ~ ( 1 << V_28 ) ;
} else if ( ! V_5 ) {
F_22 ( V_2 , V_125 . V_127 , V_128 , V_5 ) ;
}
if ( * V_62 & ( 1 << V_129 ) ) {
T_7 V_130 = F_26 ( V_58 [ V_129 ] ) ;
F_22 ( V_2 , V_125 . V_131 , V_130 , V_5 ) ;
* V_62 &= ~ ( 1 << V_129 ) ;
}
if ( * V_62 & ( 1 << V_27 ) ) {
if ( F_27 ( V_58 [ V_27 ] , V_2 ,
V_5 , log ) < 0 )
return - V_65 ;
* V_62 &= ~ ( 1 << V_27 ) ;
}
if ( * V_62 & ( 1 << V_132 ) &&
F_47 ( V_118 , V_132 ) ) {
T_6 V_133 = F_26 ( V_58 [ V_132 ] ) ;
if ( V_133 & ~ V_134 ) {
F_7 ( log , L_22 ,
V_133 ) ;
return - V_65 ;
}
F_22 ( V_2 , V_135 . V_136 , V_133 , V_5 ) ;
* V_62 &= ~ ( 1ULL << V_132 ) ;
}
if ( * V_62 & ( 1 << V_137 ) &&
F_47 ( V_118 , V_137 ) ) {
T_4 V_138 = F_48 ( V_58 [ V_137 ] ) ;
F_22 ( V_2 , V_135 . V_139 , V_138 , V_5 ) ;
* V_62 &= ~ ( 1ULL << V_137 ) ;
}
if ( * V_62 & ( 1 << V_140 ) &&
F_47 ( V_118 , V_140 ) ) {
T_6 V_130 = F_26 ( V_58 [ V_140 ] ) ;
F_22 ( V_2 , V_135 . V_130 , V_130 , V_5 ) ;
* V_62 &= ~ ( 1ULL << V_140 ) ;
}
if ( * V_62 & ( 1 << V_141 ) &&
F_47 ( V_118 , V_141 ) ) {
const struct V_142 * V_143 ;
V_143 = F_18 ( V_58 [ V_141 ] ) ;
F_49 ( V_2 , V_135 . V_144 , V_143 -> V_145 ,
sizeof( * V_143 ) , V_5 ) ;
* V_62 &= ~ ( 1ULL << V_141 ) ;
}
return 0 ;
}
static int F_50 ( struct V_118 * V_118 , struct V_1 * V_2 ,
T_2 V_62 , const struct V_56 * * V_58 ,
bool V_5 , bool log )
{
int V_80 ;
V_80 = F_46 ( V_118 , V_2 , & V_62 , V_58 , V_5 , log ) ;
if ( V_80 )
return V_80 ;
if ( V_62 & ( 1 << V_14 ) ) {
const struct V_146 * V_147 ;
V_147 = F_18 ( V_58 [ V_14 ] ) ;
F_49 ( V_2 , V_31 . V_46 ,
V_147 -> V_148 , V_149 , V_5 ) ;
F_49 ( V_2 , V_31 . V_91 ,
V_147 -> V_150 , V_149 , V_5 ) ;
V_62 &= ~ ( 1 << V_14 ) ;
}
if ( V_62 & ( 1 << V_151 ) ) {
T_5 V_152 ;
V_152 = F_31 ( V_58 [ V_151 ] ) ;
if ( ! ( V_152 & F_5 ( V_153 ) ) ) {
if ( V_5 )
F_7 ( log , L_23 ) ;
else
F_7 ( log , L_24 ) ;
return - V_65 ;
}
F_22 ( V_2 , V_31 . V_152 , V_152 , V_5 ) ;
V_62 &= ~ ( 1 << V_151 ) ;
}
if ( V_62 & ( 1 << V_29 ) ) {
T_5 V_154 ;
V_154 = F_31 ( V_58 [ V_29 ] ) ;
if ( V_5 ) {
V_154 = F_5 ( 0xffff ) ;
} else if ( ! F_51 ( V_154 ) ) {
F_7 ( log , L_25 ,
F_52 ( V_154 ) , V_155 ) ;
return - V_65 ;
}
F_22 ( V_2 , V_31 . type , V_154 , V_5 ) ;
V_62 &= ~ ( 1 << V_29 ) ;
} else if ( ! V_5 ) {
F_22 ( V_2 , V_31 . type , F_5 ( V_156 ) , V_5 ) ;
}
if ( V_62 & ( 1 << V_16 ) ) {
const struct V_157 * V_158 ;
V_158 = F_18 ( V_58 [ V_16 ] ) ;
if ( ! V_5 && V_158 -> V_159 > V_160 ) {
F_7 ( log , L_26 ,
V_158 -> V_159 , V_160 ) ;
return - V_65 ;
}
F_22 ( V_2 , V_35 . V_38 ,
V_158 -> V_161 , V_5 ) ;
F_22 ( V_2 , V_35 . V_93 ,
V_158 -> V_162 , V_5 ) ;
F_22 ( V_2 , V_35 . V_77 ,
V_158 -> V_163 , V_5 ) ;
F_22 ( V_2 , V_35 . V_36 ,
V_158 -> V_159 , V_5 ) ;
F_22 ( V_2 , V_89 . V_164 . V_46 ,
V_158 -> V_165 , V_5 ) ;
F_22 ( V_2 , V_89 . V_164 . V_91 ,
V_158 -> V_166 , V_5 ) ;
V_62 &= ~ ( 1 << V_16 ) ;
}
if ( V_62 & ( 1 << V_17 ) ) {
const struct V_167 * V_168 ;
V_168 = F_18 ( V_58 [ V_17 ] ) ;
if ( ! V_5 && V_168 -> V_169 > V_160 ) {
F_7 ( log , L_27 ,
V_168 -> V_169 , V_160 ) ;
return - V_65 ;
}
if ( ! V_5 && V_168 -> V_170 & F_53 ( 0xFFF00000 ) ) {
F_7 ( log , L_28 ,
F_54 ( V_168 -> V_170 ) , ( 1 << 20 ) - 1 ) ;
return - V_65 ;
}
F_22 ( V_2 , V_171 . V_172 ,
V_168 -> V_170 , V_5 ) ;
F_22 ( V_2 , V_35 . V_38 ,
V_168 -> V_173 , V_5 ) ;
F_22 ( V_2 , V_35 . V_93 ,
V_168 -> V_174 , V_5 ) ;
F_22 ( V_2 , V_35 . V_77 ,
V_168 -> V_175 , V_5 ) ;
F_22 ( V_2 , V_35 . V_36 ,
V_168 -> V_169 , V_5 ) ;
F_49 ( V_2 , V_171 . V_164 . V_46 ,
V_168 -> V_176 ,
sizeof( V_2 -> V_30 -> V_171 . V_164 . V_46 ) ,
V_5 ) ;
F_49 ( V_2 , V_171 . V_164 . V_91 ,
V_168 -> V_177 ,
sizeof( V_2 -> V_30 -> V_171 . V_164 . V_91 ) ,
V_5 ) ;
V_62 &= ~ ( 1 << V_17 ) ;
}
if ( V_62 & ( 1 << V_24 ) ) {
const struct V_178 * V_179 ;
V_179 = F_18 ( V_58 [ V_24 ] ) ;
if ( ! V_5 && ( V_179 -> V_180 & F_5 ( 0xff00 ) ) ) {
F_7 ( log , L_29 ,
V_179 -> V_180 ) ;
return - V_65 ;
}
F_22 ( V_2 , V_89 . V_164 . V_46 ,
V_179 -> V_181 , V_5 ) ;
F_22 ( V_2 , V_89 . V_164 . V_91 ,
V_179 -> V_182 , V_5 ) ;
F_22 ( V_2 , V_35 . V_38 ,
F_52 ( V_179 -> V_180 ) , V_5 ) ;
F_49 ( V_2 , V_89 . V_183 . V_184 ,
V_179 -> V_185 , V_149 , V_5 ) ;
F_49 ( V_2 , V_89 . V_183 . V_186 ,
V_179 -> V_187 , V_149 , V_5 ) ;
V_62 &= ~ ( 1 << V_24 ) ;
}
if ( V_62 & ( 1 << V_26 ) ) {
const struct V_188 * V_189 ;
V_189 = F_18 ( V_58 [ V_26 ] ) ;
F_22 ( V_2 , V_190 . V_191 ,
V_189 -> V_192 , V_5 ) ;
V_62 &= ~ ( 1 << V_26 ) ;
}
if ( V_62 & ( 1 << V_18 ) ) {
const struct V_193 * V_194 ;
V_194 = F_18 ( V_58 [ V_18 ] ) ;
F_22 ( V_2 , V_45 . V_46 , V_194 -> V_195 , V_5 ) ;
F_22 ( V_2 , V_45 . V_91 , V_194 -> V_196 , V_5 ) ;
V_62 &= ~ ( 1 << V_18 ) ;
}
if ( V_62 & ( 1 << V_19 ) ) {
F_22 ( V_2 , V_45 . V_197 ,
F_31 ( V_58 [ V_19 ] ) ,
V_5 ) ;
V_62 &= ~ ( 1 << V_19 ) ;
}
if ( V_62 & ( 1 << V_20 ) ) {
const struct V_198 * V_199 ;
V_199 = F_18 ( V_58 [ V_20 ] ) ;
F_22 ( V_2 , V_45 . V_46 , V_199 -> V_200 , V_5 ) ;
F_22 ( V_2 , V_45 . V_91 , V_199 -> V_201 , V_5 ) ;
V_62 &= ~ ( 1 << V_20 ) ;
}
if ( V_62 & ( 1 << V_21 ) ) {
const struct V_202 * V_203 ;
V_203 = F_18 ( V_58 [ V_21 ] ) ;
F_22 ( V_2 , V_45 . V_46 , V_203 -> V_204 , V_5 ) ;
F_22 ( V_2 , V_45 . V_91 , V_203 -> V_205 , V_5 ) ;
V_62 &= ~ ( 1 << V_21 ) ;
}
if ( V_62 & ( 1 << V_22 ) ) {
const struct V_206 * V_207 ;
V_207 = F_18 ( V_58 [ V_22 ] ) ;
F_22 ( V_2 , V_45 . V_46 ,
F_5 ( V_207 -> V_208 ) , V_5 ) ;
F_22 ( V_2 , V_45 . V_91 ,
F_5 ( V_207 -> V_209 ) , V_5 ) ;
V_62 &= ~ ( 1 << V_22 ) ;
}
if ( V_62 & ( 1 << V_23 ) ) {
const struct V_210 * V_211 ;
V_211 = F_18 ( V_58 [ V_23 ] ) ;
F_22 ( V_2 , V_45 . V_46 ,
F_5 ( V_211 -> V_212 ) , V_5 ) ;
F_22 ( V_2 , V_45 . V_91 ,
F_5 ( V_211 -> V_213 ) , V_5 ) ;
V_62 &= ~ ( 1 << V_23 ) ;
}
if ( V_62 & ( 1 << V_25 ) ) {
const struct V_214 * V_215 ;
V_215 = F_18 ( V_58 [ V_25 ] ) ;
F_49 ( V_2 , V_171 . V_216 . V_217 ,
V_215 -> V_218 ,
sizeof( V_2 -> V_30 -> V_171 . V_216 . V_217 ) ,
V_5 ) ;
F_49 ( V_2 , V_171 . V_216 . V_219 ,
V_215 -> V_220 , V_149 , V_5 ) ;
F_49 ( V_2 , V_171 . V_216 . V_221 ,
V_215 -> V_222 , V_149 , V_5 ) ;
V_62 &= ~ ( 1 << V_25 ) ;
}
if ( V_62 != 0 ) {
F_7 ( log , L_30 ,
( unsigned long long ) V_62 ) ;
return - V_65 ;
}
return 0 ;
}
static void F_55 ( struct V_56 * V_57 , T_3 V_223 ,
const struct V_224 * V_225 )
{
struct V_56 * V_61 ;
int V_63 ;
F_15 (nla, attr, rem) {
if ( V_225 [ F_16 ( V_61 ) ] . V_67 == V_52 ) {
if ( V_225 [ F_16 ( V_61 ) ] . V_226 )
V_225 = V_225 [ F_16 ( V_61 ) ] . V_226 ;
F_55 ( V_61 , V_223 , V_225 ) ;
} else {
memset ( F_18 ( V_61 ) , V_223 , F_17 ( V_61 ) ) ;
}
if ( F_16 ( V_61 ) == V_132 )
* ( T_6 * ) F_18 ( V_61 ) &= V_134 ;
}
}
static void F_56 ( struct V_56 * V_57 , T_3 V_223 )
{
F_55 ( V_57 , V_223 , V_66 ) ;
}
int F_57 ( struct V_118 * V_118 , struct V_1 * V_2 ,
const struct V_56 * V_227 ,
const struct V_56 * V_228 ,
bool log )
{
const struct V_56 * V_58 [ V_64 + 1 ] ;
const struct V_56 * V_229 ;
struct V_56 * V_230 = NULL ;
T_2 V_11 = 0 ;
T_2 V_12 = 0 ;
bool V_231 = false ;
int V_80 ;
V_80 = F_20 ( V_227 , V_58 , & V_11 , log ) ;
if ( V_80 )
return V_80 ;
if ( ( V_11 & ( 1 << V_14 ) ) &&
( V_11 & ( 1 << V_29 ) ) &&
( F_31 ( V_58 [ V_29 ] ) == F_5 ( V_232 ) ) ) {
T_5 V_152 ;
if ( ! ( ( V_11 & ( 1 << V_151 ) ) &&
( V_11 & ( 1 << V_233 ) ) ) ) {
F_7 ( log , L_31 ) ;
return - V_65 ;
}
V_11 &= ~ ( 1 << V_29 ) ;
V_152 = F_31 ( V_58 [ V_151 ] ) ;
V_229 = V_58 [ V_233 ] ;
V_11 &= ~ ( 1 << V_233 ) ;
V_231 = true ;
if ( V_152 & F_5 ( V_153 ) ) {
V_80 = F_20 ( V_229 , V_58 , & V_11 , log ) ;
if ( V_80 )
return V_80 ;
} else if ( ! V_152 ) {
if ( F_17 ( V_229 ) ) {
F_7 ( log , L_32 ) ;
return - V_65 ;
}
} else {
F_7 ( log , L_33 ) ;
return - V_65 ;
}
}
V_80 = F_50 ( V_118 , V_2 , V_11 , V_58 , false , log ) ;
if ( V_80 )
return V_80 ;
if ( V_2 -> V_10 ) {
if ( ! V_228 ) {
V_230 = F_58 ( V_227 ,
F_9 ( F_17 ( V_227 ) ) ,
V_234 ) ;
if ( ! V_230 )
return - V_235 ;
F_56 ( V_230 , 0xff ) ;
if ( V_2 -> V_30 -> V_84 . V_88 . V_89 . V_91 )
F_59 ( V_2 , V_84 ,
0xff , true ) ;
V_228 = V_230 ;
}
V_80 = F_19 ( V_228 , V_58 , & V_12 , log ) ;
if ( V_80 )
goto V_236;
F_22 ( V_2 , V_31 . V_152 , F_5 ( 0xffff ) , true ) ;
if ( V_12 & 1 << V_233 ) {
T_5 V_154 = 0 ;
T_5 V_152 = 0 ;
if ( ! V_231 ) {
F_7 ( log , L_34 ) ;
V_80 = - V_65 ;
goto V_236;
}
V_12 &= ~ ( 1 << V_233 ) ;
if ( V_58 [ V_29 ] )
V_154 = F_31 ( V_58 [ V_29 ] ) ;
if ( V_154 == F_5 ( 0xffff ) ) {
V_12 &= ~ ( 1 << V_29 ) ;
V_229 = V_58 [ V_233 ] ;
V_80 = F_19 ( V_229 , V_58 ,
& V_12 , log ) ;
if ( V_80 )
goto V_236;
} else {
F_7 ( log , L_35 ,
F_52 ( V_154 ) ) ;
V_80 = - V_65 ;
goto V_236;
}
if ( V_58 [ V_151 ] )
V_152 = F_31 ( V_58 [ V_151 ] ) ;
if ( ! ( V_152 & F_5 ( V_153 ) ) ) {
F_7 ( log , L_36 ,
F_52 ( V_152 ) ) ;
V_80 = - V_65 ;
goto V_236;
}
}
V_80 = F_50 ( V_118 , V_2 , V_12 , V_58 , true ,
log ) ;
if ( V_80 )
goto V_236;
}
if ( ! F_4 ( V_2 , V_11 , V_12 , log ) )
V_80 = - V_65 ;
V_236:
F_60 ( V_230 ) ;
return V_80 ;
}
static T_1 F_61 ( const struct V_56 * V_57 , bool log )
{
T_1 V_67 ;
if ( ! V_57 )
return 0 ;
V_67 = F_17 ( V_57 ) ;
if ( V_67 < 1 || V_67 > V_237 ) {
F_7 ( log , L_37 ,
F_17 ( V_57 ) , V_237 ) ;
return 0 ;
}
return V_67 ;
}
bool F_62 ( struct V_238 * V_239 , const struct V_56 * V_57 ,
bool log )
{
V_239 -> V_240 = F_61 ( V_57 , log ) ;
if ( V_239 -> V_240 )
memcpy ( V_239 -> V_241 , F_18 ( V_57 ) , V_239 -> V_240 ) ;
return V_239 -> V_240 ;
}
int F_63 ( struct V_238 * V_239 , const struct V_56 * V_241 ,
const struct V_242 * V_30 , bool log )
{
struct V_242 * V_243 ;
if ( F_62 ( V_239 , V_241 , log ) )
return 0 ;
V_243 = F_64 ( sizeof( * V_243 ) , V_234 ) ;
if ( ! V_243 )
return - V_235 ;
memcpy ( V_243 , V_30 , sizeof( * V_30 ) ) ;
V_239 -> V_244 = V_243 ;
return 0 ;
}
T_6 F_65 ( const struct V_56 * V_57 )
{
return V_57 ? F_26 ( V_57 ) : 0 ;
}
int F_66 ( struct V_118 * V_118 , const struct V_56 * V_57 ,
struct V_242 * V_30 ,
bool log )
{
const struct V_56 * V_58 [ V_64 + 1 ] ;
struct V_1 V_2 ;
T_2 V_62 = 0 ;
int V_80 ;
V_80 = F_20 ( V_57 , V_58 , & V_62 , log ) ;
if ( V_80 )
return - V_65 ;
memset ( & V_2 , 0 , sizeof( V_2 ) ) ;
V_2 . V_30 = V_30 ;
memset ( & V_30 -> V_135 , 0 , sizeof( V_30 -> V_135 ) ) ;
V_30 -> V_125 . V_127 = V_128 ;
return F_46 ( V_118 , & V_2 , & V_62 , V_58 , false , log ) ;
}
static int F_67 ( const struct V_242 * V_245 ,
const struct V_242 * V_114 , bool V_5 ,
struct V_109 * V_110 )
{
struct V_146 * V_147 ;
struct V_56 * V_61 , * V_229 ;
if ( F_34 ( V_110 , V_122 , V_114 -> V_123 ) )
goto V_246;
if ( F_34 ( V_110 , V_119 , V_114 -> V_121 ) )
goto V_246;
if ( F_34 ( V_110 , V_124 , V_114 -> V_125 . V_126 ) )
goto V_246;
if ( ( V_245 -> V_84 . V_88 . V_89 . V_91 || V_5 ) ) {
const void * V_72 = NULL ;
if ( V_114 -> V_84 . V_78 & V_247 )
V_72 = F_68 ( V_114 , V_245 -> V_70 ) ;
if ( F_43 ( V_110 , & V_114 -> V_84 , V_72 ,
V_245 -> V_70 ) )
goto V_246;
}
if ( V_245 -> V_125 . V_127 == V_128 ) {
if ( V_5 && ( V_114 -> V_125 . V_127 == 0xffff ) )
if ( F_34 ( V_110 , V_28 , 0xffffffff ) )
goto V_246;
} else {
T_4 V_248 ;
V_248 = ! V_5 ? 0 : 0xffff ;
if ( F_34 ( V_110 , V_28 ,
( V_248 << 16 ) | V_114 -> V_125 . V_127 ) )
goto V_246;
}
if ( F_34 ( V_110 , V_129 , V_114 -> V_125 . V_131 ) )
goto V_246;
if ( F_69 ( V_114 , V_110 ) )
goto V_246;
V_61 = F_70 ( V_110 , V_14 , sizeof( * V_147 ) ) ;
if ( ! V_61 )
goto V_246;
V_147 = F_18 ( V_61 ) ;
F_71 ( V_147 -> V_148 , V_114 -> V_31 . V_46 ) ;
F_71 ( V_147 -> V_150 , V_114 -> V_31 . V_91 ) ;
if ( V_245 -> V_31 . V_152 || V_245 -> V_31 . type == F_5 ( V_232 ) ) {
T_5 V_154 ;
V_154 = ! V_5 ? F_5 ( V_232 ) : F_5 ( 0xffff ) ;
if ( F_41 ( V_110 , V_29 , V_154 ) ||
F_41 ( V_110 , V_151 , V_114 -> V_31 . V_152 ) )
goto V_246;
V_229 = F_33 ( V_110 , V_233 ) ;
if ( ! V_245 -> V_31 . V_152 )
goto V_249;
} else
V_229 = NULL ;
if ( V_245 -> V_31 . type == F_5 ( V_156 ) ) {
if ( V_5 && V_114 -> V_31 . type )
if ( F_41 ( V_110 , V_29 ,
V_114 -> V_31 . type ) )
goto V_246;
goto V_249;
}
if ( F_41 ( V_110 , V_29 , V_114 -> V_31 . type ) )
goto V_246;
if ( V_245 -> V_31 . type == F_5 ( V_34 ) ) {
struct V_157 * V_158 ;
V_61 = F_70 ( V_110 , V_16 , sizeof( * V_158 ) ) ;
if ( ! V_61 )
goto V_246;
V_158 = F_18 ( V_61 ) ;
V_158 -> V_165 = V_114 -> V_89 . V_164 . V_46 ;
V_158 -> V_166 = V_114 -> V_89 . V_164 . V_91 ;
V_158 -> V_161 = V_114 -> V_35 . V_38 ;
V_158 -> V_162 = V_114 -> V_35 . V_93 ;
V_158 -> V_163 = V_114 -> V_35 . V_77 ;
V_158 -> V_159 = V_114 -> V_35 . V_36 ;
} else if ( V_245 -> V_31 . type == F_5 ( V_43 ) ) {
struct V_167 * V_168 ;
V_61 = F_70 ( V_110 , V_17 , sizeof( * V_168 ) ) ;
if ( ! V_61 )
goto V_246;
V_168 = F_18 ( V_61 ) ;
memcpy ( V_168 -> V_176 , & V_114 -> V_171 . V_164 . V_46 ,
sizeof( V_168 -> V_176 ) ) ;
memcpy ( V_168 -> V_177 , & V_114 -> V_171 . V_164 . V_91 ,
sizeof( V_168 -> V_177 ) ) ;
V_168 -> V_170 = V_114 -> V_171 . V_172 ;
V_168 -> V_173 = V_114 -> V_35 . V_38 ;
V_168 -> V_174 = V_114 -> V_35 . V_93 ;
V_168 -> V_175 = V_114 -> V_35 . V_77 ;
V_168 -> V_169 = V_114 -> V_35 . V_36 ;
} else if ( V_245 -> V_31 . type == F_5 ( V_32 ) ||
V_245 -> V_31 . type == F_5 ( V_33 ) ) {
struct V_178 * V_179 ;
V_61 = F_70 ( V_110 , V_24 , sizeof( * V_179 ) ) ;
if ( ! V_61 )
goto V_246;
V_179 = F_18 ( V_61 ) ;
memset ( V_179 , 0 , sizeof( struct V_178 ) ) ;
V_179 -> V_181 = V_114 -> V_89 . V_164 . V_46 ;
V_179 -> V_182 = V_114 -> V_89 . V_164 . V_91 ;
V_179 -> V_180 = F_5 ( V_114 -> V_35 . V_38 ) ;
F_71 ( V_179 -> V_185 , V_114 -> V_89 . V_183 . V_184 ) ;
F_71 ( V_179 -> V_187 , V_114 -> V_89 . V_183 . V_186 ) ;
} else if ( F_6 ( V_245 -> V_31 . type ) ) {
struct V_188 * V_189 ;
V_61 = F_70 ( V_110 , V_26 , sizeof( * V_189 ) ) ;
if ( ! V_61 )
goto V_246;
V_189 = F_18 ( V_61 ) ;
V_189 -> V_192 = V_114 -> V_190 . V_191 ;
}
if ( ( V_245 -> V_31 . type == F_5 ( V_34 ) ||
V_245 -> V_31 . type == F_5 ( V_43 ) ) &&
V_245 -> V_35 . V_36 != V_37 ) {
if ( V_245 -> V_35 . V_38 == V_41 ) {
struct V_193 * V_194 ;
V_61 = F_70 ( V_110 , V_18 , sizeof( * V_194 ) ) ;
if ( ! V_61 )
goto V_246;
V_194 = F_18 ( V_61 ) ;
V_194 -> V_195 = V_114 -> V_45 . V_46 ;
V_194 -> V_196 = V_114 -> V_45 . V_91 ;
if ( F_41 ( V_110 , V_19 ,
V_114 -> V_45 . V_197 ) )
goto V_246;
} else if ( V_245 -> V_35 . V_38 == V_39 ) {
struct V_198 * V_199 ;
V_61 = F_70 ( V_110 , V_20 , sizeof( * V_199 ) ) ;
if ( ! V_61 )
goto V_246;
V_199 = F_18 ( V_61 ) ;
V_199 -> V_200 = V_114 -> V_45 . V_46 ;
V_199 -> V_201 = V_114 -> V_45 . V_91 ;
} else if ( V_245 -> V_35 . V_38 == V_40 ) {
struct V_202 * V_203 ;
V_61 = F_70 ( V_110 , V_21 , sizeof( * V_203 ) ) ;
if ( ! V_61 )
goto V_246;
V_203 = F_18 ( V_61 ) ;
V_203 -> V_204 = V_114 -> V_45 . V_46 ;
V_203 -> V_205 = V_114 -> V_45 . V_91 ;
} else if ( V_245 -> V_31 . type == F_5 ( V_34 ) &&
V_245 -> V_35 . V_38 == V_42 ) {
struct V_206 * V_207 ;
V_61 = F_70 ( V_110 , V_22 , sizeof( * V_207 ) ) ;
if ( ! V_61 )
goto V_246;
V_207 = F_18 ( V_61 ) ;
V_207 -> V_208 = F_52 ( V_114 -> V_45 . V_46 ) ;
V_207 -> V_209 = F_52 ( V_114 -> V_45 . V_91 ) ;
} else if ( V_245 -> V_31 . type == F_5 ( V_43 ) &&
V_245 -> V_35 . V_38 == V_44 ) {
struct V_210 * V_211 ;
V_61 = F_70 ( V_110 , V_23 ,
sizeof( * V_211 ) ) ;
if ( ! V_61 )
goto V_246;
V_211 = F_18 ( V_61 ) ;
V_211 -> V_212 = F_52 ( V_114 -> V_45 . V_46 ) ;
V_211 -> V_213 = F_52 ( V_114 -> V_45 . V_91 ) ;
if ( V_211 -> V_212 == V_47 ||
V_211 -> V_212 == V_48 ) {
struct V_214 * V_215 ;
V_61 = F_70 ( V_110 , V_25 , sizeof( * V_215 ) ) ;
if ( ! V_61 )
goto V_246;
V_215 = F_18 ( V_61 ) ;
memcpy ( V_215 -> V_218 , & V_114 -> V_171 . V_216 . V_217 ,
sizeof( V_215 -> V_218 ) ) ;
F_71 ( V_215 -> V_220 , V_114 -> V_171 . V_216 . V_219 ) ;
F_71 ( V_215 -> V_222 , V_114 -> V_171 . V_216 . V_221 ) ;
}
}
}
V_249:
if ( V_229 )
F_35 ( V_110 , V_229 ) ;
return 0 ;
V_246:
return - V_112 ;
}
int F_72 ( const struct V_242 * V_245 ,
const struct V_242 * V_114 , int V_57 , bool V_5 ,
struct V_109 * V_110 )
{
int V_80 ;
struct V_56 * V_61 ;
V_61 = F_33 ( V_110 , V_57 ) ;
if ( ! V_61 )
return - V_112 ;
V_80 = F_67 ( V_245 , V_114 , V_5 , V_110 ) ;
if ( V_80 )
return V_80 ;
F_35 ( V_110 , V_61 ) ;
return 0 ;
}
int F_73 ( const struct V_250 * V_251 , struct V_109 * V_110 )
{
if ( F_74 ( & V_251 -> V_252 ) )
return F_42 ( V_110 , V_253 , V_251 -> V_252 . V_240 ,
V_251 -> V_252 . V_241 ) ;
return F_72 ( V_251 -> V_252 . V_244 , V_251 -> V_252 . V_244 ,
V_254 , false , V_110 ) ;
}
int F_75 ( const struct V_250 * V_251 , struct V_109 * V_110 )
{
return F_72 ( & V_251 -> V_30 , & V_251 -> V_30 ,
V_254 , false , V_110 ) ;
}
int F_76 ( const struct V_250 * V_251 , struct V_109 * V_110 )
{
return F_72 ( & V_251 -> V_30 , & V_251 -> V_10 -> V_30 ,
V_255 , true , V_110 ) ;
}
static struct V_256 * F_77 ( int V_4 , bool log )
{
struct V_256 * V_257 ;
if ( V_4 > V_258 ) {
F_7 ( log , L_38 , V_4 ) ;
return F_78 ( - V_65 ) ;
}
V_257 = F_64 ( sizeof( * V_257 ) + V_4 , V_234 ) ;
if ( ! V_257 )
return F_78 ( - V_235 ) ;
V_257 -> V_259 = 0 ;
return V_257 ;
}
static void F_79 ( const struct V_56 * V_58 )
{
const struct V_56 * V_260 = F_18 ( V_58 ) ;
struct V_261 * V_262 ;
switch ( F_16 ( V_260 ) ) {
case V_49 :
V_262 = F_18 ( V_260 ) ;
F_80 ( (struct V_263 * ) V_262 -> V_264 ) ;
break;
}
}
void F_81 ( struct V_256 * V_265 )
{
const struct V_56 * V_58 ;
int V_63 ;
if ( ! V_265 )
return;
F_82 (a, sf_acts->actions, sf_acts->actions_len, rem) {
switch ( F_16 ( V_58 ) ) {
case V_266 :
F_79 ( V_58 ) ;
break;
case V_267 :
F_83 ( V_58 ) ;
break;
}
}
F_60 ( V_265 ) ;
}
static void F_84 ( struct V_268 * V_269 )
{
F_81 ( F_85 ( V_269 , struct V_256 , V_270 ) ) ;
}
void F_86 ( struct V_256 * V_265 )
{
F_87 ( & V_265 -> V_270 , F_84 ) ;
}
static struct V_56 * F_88 ( struct V_256 * * V_257 ,
int V_50 , bool log )
{
struct V_256 * V_271 ;
int V_272 ;
int V_273 = F_89 ( V_50 ) ;
int V_274 = F_90 ( struct V_256 , V_275 ) +
( * V_257 ) -> V_259 ;
if ( V_273 <= ( F_91 ( * V_257 ) - V_274 ) )
goto V_276;
V_272 = F_91 ( * V_257 ) * 2 ;
if ( V_272 > V_258 ) {
if ( ( V_258 - V_274 ) < V_273 )
return F_78 ( - V_112 ) ;
V_272 = V_258 ;
}
V_271 = F_77 ( V_272 , log ) ;
if ( F_92 ( V_271 ) )
return ( void * ) V_271 ;
memcpy ( V_271 -> V_275 , ( * V_257 ) -> V_275 , ( * V_257 ) -> V_259 ) ;
V_271 -> V_259 = ( * V_257 ) -> V_259 ;
V_271 -> V_277 = ( * V_257 ) -> V_277 ;
F_60 ( * V_257 ) ;
* V_257 = V_271 ;
V_276:
( * V_257 ) -> V_259 += V_273 ;
return (struct V_56 * ) ( ( unsigned char * ) ( * V_257 ) + V_274 ) ;
}
static struct V_56 * F_93 ( struct V_256 * * V_257 ,
int V_278 , void * V_279 , int V_67 , bool log )
{
struct V_56 * V_58 ;
V_58 = F_88 ( V_257 , F_94 ( V_67 ) , log ) ;
if ( F_92 ( V_58 ) )
return V_58 ;
V_58 -> F_16 = V_278 ;
V_58 -> F_17 = F_94 ( V_67 ) ;
if ( V_279 )
memcpy ( F_18 ( V_58 ) , V_279 , V_67 ) ;
memset ( ( unsigned char * ) V_58 + V_58 -> F_17 , 0 , F_95 ( V_67 ) ) ;
return V_58 ;
}
int F_96 ( struct V_256 * * V_257 , int V_278 , void * V_279 ,
int V_67 , bool log )
{
struct V_56 * V_58 ;
V_58 = F_93 ( V_257 , V_278 , V_279 , V_67 , log ) ;
return F_97 ( V_58 ) ;
}
static inline int F_98 ( struct V_256 * * V_257 ,
int V_278 , bool log )
{
int V_280 = ( * V_257 ) -> V_259 ;
int V_80 ;
V_80 = F_96 ( V_257 , V_278 , NULL , 0 , log ) ;
if ( V_80 )
return V_80 ;
return V_280 ;
}
static inline void F_99 ( struct V_256 * V_257 ,
int V_281 )
{
struct V_56 * V_58 = (struct V_56 * ) ( ( unsigned char * ) V_257 -> V_275 +
V_281 ) ;
V_58 -> F_17 = V_257 -> V_259 - V_281 ;
}
static int F_100 ( struct V_118 * V_118 , const struct V_56 * V_57 ,
const struct V_242 * V_30 , int V_282 ,
struct V_256 * * V_257 ,
T_5 V_154 , T_5 V_283 , bool log )
{
const struct V_56 * V_62 [ V_284 + 1 ] ;
const struct V_56 * V_285 , * V_275 ;
const struct V_56 * V_58 ;
int V_63 , V_8 , V_80 , V_286 ;
memset ( V_62 , 0 , sizeof( V_62 ) ) ;
F_15 (a, attr, rem) {
int type = F_16 ( V_58 ) ;
if ( ! type || type > V_284 || V_62 [ type ] )
return - V_65 ;
V_62 [ type ] = V_58 ;
}
if ( V_63 )
return - V_65 ;
V_285 = V_62 [ V_287 ] ;
if ( ! V_285 || F_17 ( V_285 ) != sizeof( T_6 ) )
return - V_65 ;
V_275 = V_62 [ V_288 ] ;
if ( ! V_275 || ( F_17 ( V_275 ) && F_17 ( V_275 ) < V_289 ) )
return - V_65 ;
V_8 = F_98 ( V_257 , V_290 , log ) ;
if ( V_8 < 0 )
return V_8 ;
V_80 = F_96 ( V_257 , V_287 ,
F_18 ( V_285 ) , sizeof( T_6 ) , log ) ;
if ( V_80 )
return V_80 ;
V_286 = F_98 ( V_257 , V_288 , log ) ;
if ( V_286 < 0 )
return V_286 ;
V_80 = F_101 ( V_118 , V_275 , V_30 , V_282 + 1 , V_257 ,
V_154 , V_283 , log ) ;
if ( V_80 )
return V_80 ;
F_99 ( * V_257 , V_286 ) ;
F_99 ( * V_257 , V_8 ) ;
return 0 ;
}
void F_102 ( struct V_1 * V_2 ,
struct V_242 * V_30 ,
struct V_291 * V_10 )
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
static int F_103 ( struct V_242 * V_30 )
{
struct V_292 * V_293 ;
int V_294 = V_30 -> V_70 ;
bool V_295 = false ;
V_293 = (struct V_292 * ) F_68 ( V_30 , V_30 -> V_70 ) ;
while ( V_294 > 0 ) {
int V_67 ;
if ( V_294 < sizeof( * V_293 ) )
return - V_65 ;
V_67 = sizeof( * V_293 ) + V_293 -> V_296 * 4 ;
if ( V_67 > V_294 )
return - V_65 ;
V_295 |= ! ! ( V_293 -> type & V_297 ) ;
V_293 = (struct V_292 * ) ( ( T_3 * ) V_293 + V_67 ) ;
V_294 -= V_67 ;
} ;
V_30 -> V_84 . V_78 |= V_295 ? V_298 : 0 ;
return 0 ;
}
static int F_104 ( const struct V_56 * V_57 ,
struct V_256 * * V_257 , bool log )
{
struct V_1 V_2 ;
struct V_242 V_30 ;
struct V_299 * V_264 ;
struct V_115 * V_116 ;
struct V_261 * V_262 ;
struct V_56 * V_58 ;
int V_80 = 0 , V_8 , V_79 ;
F_102 ( & V_2 , & V_30 , NULL ) ;
V_79 = F_27 ( F_18 ( V_57 ) , & V_2 , false , log ) ;
if ( V_79 < 0 )
return V_79 ;
if ( V_30 . V_70 ) {
switch ( V_79 ) {
case V_105 :
V_80 = F_103 ( & V_30 ) ;
if ( V_80 < 0 )
return V_80 ;
break;
case V_107 :
break;
}
} ;
V_8 = F_98 ( V_257 , V_266 , log ) ;
if ( V_8 < 0 )
return V_8 ;
V_264 = F_105 ( V_30 . V_70 , V_234 ) ;
if ( ! V_264 )
return - V_235 ;
V_58 = F_93 ( V_257 , V_49 , NULL ,
sizeof( * V_262 ) , log ) ;
if ( F_92 ( V_58 ) ) {
F_80 ( (struct V_263 * ) V_264 ) ;
return F_106 ( V_58 ) ;
}
V_262 = F_18 ( V_58 ) ;
V_262 -> V_264 = V_264 ;
V_116 = & V_264 -> V_88 . V_116 ;
V_116 -> V_300 = V_301 ;
V_116 -> V_30 = V_30 . V_84 ;
F_107 ( V_116 ,
F_68 ( & V_30 , V_30 . V_70 ) ,
V_30 . V_70 ) ;
F_99 ( * V_257 , V_8 ) ;
return V_80 ;
}
static bool F_108 ( T_3 * V_279 , int V_67 )
{
T_3 * V_10 = V_279 + V_67 ;
while ( V_67 -- )
if ( * V_279 ++ & ~ * V_10 ++ )
return false ;
return true ;
}
static int F_109 ( const struct V_56 * V_58 ,
const struct V_242 * V_302 ,
struct V_256 * * V_257 ,
bool * V_303 , T_5 V_154 , bool V_304 , bool log )
{
const struct V_56 * V_260 = F_18 ( V_58 ) ;
int V_305 = F_16 ( V_260 ) ;
T_1 V_306 ;
if ( F_9 ( F_17 ( V_260 ) ) != F_17 ( V_58 ) )
return - V_65 ;
V_306 = F_17 ( V_260 ) ;
if ( V_304 )
V_306 /= 2 ;
if ( V_305 > V_64 ||
! F_12 ( V_306 , V_66 [ V_305 ] . V_67 ) )
return - V_65 ;
if ( V_304 && ! F_108 ( F_18 ( V_260 ) , V_306 ) )
return - V_65 ;
switch ( V_305 ) {
const struct V_157 * V_158 ;
const struct V_167 * V_168 ;
int V_80 ;
case V_124 :
case V_129 :
case V_140 :
case V_141 :
case V_14 :
break;
case V_27 :
if ( F_6 ( V_154 ) )
return - V_65 ;
if ( V_304 )
return - V_65 ;
* V_303 = true ;
V_80 = F_104 ( V_58 , V_257 , log ) ;
if ( V_80 )
return V_80 ;
break;
case V_16 :
if ( V_154 != F_5 ( V_34 ) )
return - V_65 ;
V_158 = F_18 ( V_260 ) ;
if ( V_304 ) {
const struct V_157 * V_10 = V_158 + 1 ;
if ( V_10 -> V_161 || V_10 -> V_159 )
return - V_65 ;
} else {
if ( V_158 -> V_161 != V_302 -> V_35 . V_38 )
return - V_65 ;
if ( V_158 -> V_159 != V_302 -> V_35 . V_36 )
return - V_65 ;
}
break;
case V_17 :
if ( V_154 != F_5 ( V_43 ) )
return - V_65 ;
V_168 = F_18 ( V_260 ) ;
if ( V_304 ) {
const struct V_167 * V_10 = V_168 + 1 ;
if ( V_10 -> V_173 || V_10 -> V_169 )
return - V_65 ;
if ( F_54 ( V_10 -> V_170 ) & 0xFFF00000 )
return - V_65 ;
} else {
if ( V_168 -> V_173 != V_302 -> V_35 . V_38 )
return - V_65 ;
if ( V_168 -> V_169 != V_302 -> V_35 . V_36 )
return - V_65 ;
}
if ( F_54 ( V_168 -> V_170 ) & 0xFFF00000 )
return - V_65 ;
break;
case V_18 :
if ( ( V_154 != F_5 ( V_34 ) &&
V_154 != F_5 ( V_43 ) ) ||
V_302 -> V_35 . V_38 != V_41 )
return - V_65 ;
break;
case V_20 :
if ( ( V_154 != F_5 ( V_34 ) &&
V_154 != F_5 ( V_43 ) ) ||
V_302 -> V_35 . V_38 != V_39 )
return - V_65 ;
break;
case V_26 :
if ( ! F_6 ( V_154 ) )
return - V_65 ;
break;
case V_21 :
if ( ( V_154 != F_5 ( V_34 ) &&
V_154 != F_5 ( V_43 ) ) ||
V_302 -> V_35 . V_38 != V_40 )
return - V_65 ;
break;
default:
return - V_65 ;
}
if ( ! V_304 && V_305 != V_27 ) {
int V_8 , V_67 = V_306 * 2 ;
struct V_56 * V_307 ;
* V_303 = true ;
V_8 = F_98 ( V_257 ,
V_308 ,
log ) ;
if ( V_8 < 0 )
return V_8 ;
V_307 = F_93 ( V_257 , V_305 , NULL , V_67 , log ) ;
if ( F_92 ( V_307 ) )
return F_106 ( V_307 ) ;
memcpy ( F_18 ( V_307 ) , F_18 ( V_260 ) , V_306 ) ;
memset ( F_18 ( V_307 ) + V_306 , 0xff , V_306 ) ;
if ( V_305 == V_17 ) {
struct V_167 * V_10 = F_18 ( V_307 ) + V_306 ;
V_10 -> V_170 &= F_53 ( 0x000FFFFF ) ;
}
F_99 ( * V_257 , V_8 ) ;
}
return 0 ;
}
static int F_110 ( const struct V_56 * V_57 )
{
static const struct V_309 V_310 [ V_311 + 1 ] = {
[ V_312 ] = { . type = V_313 } ,
[ V_314 ] = { . type = V_315 } ,
[ V_316 ] = { . type = V_313 } ,
} ;
struct V_56 * V_58 [ V_311 + 1 ] ;
int error ;
error = F_111 ( V_58 , V_311 ,
V_57 , V_310 ) ;
if ( error )
return error ;
if ( ! V_58 [ V_312 ] ||
! F_26 ( V_58 [ V_312 ] ) )
return - V_65 ;
return 0 ;
}
static int F_112 ( const struct V_56 * V_317 ,
struct V_256 * * V_257 , bool log )
{
int V_318 = F_89 ( V_317 -> F_17 ) ;
struct V_56 * V_319 ;
V_319 = F_88 ( V_257 , V_317 -> F_17 , log ) ;
if ( F_92 ( V_319 ) )
return F_106 ( V_319 ) ;
memcpy ( V_319 , V_317 , V_318 ) ;
return 0 ;
}
static int F_101 ( struct V_118 * V_118 , const struct V_56 * V_57 ,
const struct V_242 * V_30 ,
int V_282 , struct V_256 * * V_257 ,
T_5 V_154 , T_5 V_283 , bool log )
{
const struct V_56 * V_58 ;
int V_63 , V_80 ;
if ( V_282 >= V_320 )
return - V_321 ;
F_15 (a, attr, rem) {
static const T_6 V_322 [ V_323 + 1 ] = {
[ V_324 ] = sizeof( T_6 ) ,
[ V_325 ] = sizeof( T_6 ) ,
[ V_326 ] = ( T_6 ) - 1 ,
[ V_327 ] = sizeof( struct V_328 ) ,
[ V_329 ] = sizeof( T_5 ) ,
[ V_330 ] = sizeof( struct V_331 ) ,
[ V_332 ] = 0 ,
[ V_266 ] = ( T_6 ) - 1 ,
[ V_333 ] = ( T_6 ) - 1 ,
[ V_290 ] = ( T_6 ) - 1 ,
[ V_334 ] = sizeof( struct V_335 ) ,
[ V_267 ] = ( T_6 ) - 1 ,
} ;
const struct V_331 * V_336 ;
int type = F_16 ( V_58 ) ;
bool V_303 ;
if ( type > V_323 ||
( V_322 [ type ] != F_17 ( V_58 ) &&
V_322 [ type ] != ( T_6 ) - 1 ) )
return - V_65 ;
V_303 = false ;
switch ( type ) {
case V_337 :
return - V_65 ;
case V_326 :
V_80 = F_110 ( V_58 ) ;
if ( V_80 )
return V_80 ;
break;
case V_324 :
if ( F_26 ( V_58 ) >= V_128 )
return - V_65 ;
break;
case V_334 : {
const struct V_335 * V_338 = F_18 ( V_58 ) ;
switch ( V_338 -> V_339 ) {
case V_340 :
break;
default:
return - V_65 ;
}
break;
}
case V_332 :
V_283 = F_5 ( 0 ) ;
break;
case V_330 :
V_336 = F_18 ( V_58 ) ;
if ( V_336 -> V_341 != F_5 ( V_232 ) )
return - V_65 ;
if ( ! ( V_336 -> V_283 & F_5 ( V_153 ) ) )
return - V_65 ;
V_283 = V_336 -> V_283 ;
break;
case V_325 :
break;
case V_327 : {
const struct V_328 * V_190 = F_18 ( V_58 ) ;
if ( ! F_6 ( V_190 -> V_342 ) )
return - V_65 ;
if ( V_283 & F_5 ( V_153 ) ||
( V_154 != F_5 ( V_34 ) &&
V_154 != F_5 ( V_43 ) &&
V_154 != F_5 ( V_32 ) &&
V_154 != F_5 ( V_33 ) &&
! F_6 ( V_154 ) ) )
return - V_65 ;
V_154 = V_190 -> V_342 ;
break;
}
case V_329 :
if ( V_283 & F_5 ( V_153 ) ||
! F_6 ( V_154 ) )
return - V_65 ;
V_154 = F_5 ( 0 ) ;
break;
case V_266 :
V_80 = F_109 ( V_58 , V_30 , V_257 ,
& V_303 , V_154 , false , log ) ;
if ( V_80 )
return V_80 ;
break;
case V_333 :
V_80 = F_109 ( V_58 , V_30 , V_257 ,
& V_303 , V_154 , true , log ) ;
if ( V_80 )
return V_80 ;
break;
case V_290 :
V_80 = F_100 ( V_118 , V_58 , V_30 , V_282 , V_257 ,
V_154 , V_283 , log ) ;
if ( V_80 )
return V_80 ;
V_303 = true ;
break;
case V_267 :
V_80 = F_113 ( V_118 , V_58 , V_30 , V_257 , log ) ;
if ( V_80 )
return V_80 ;
V_303 = true ;
break;
default:
F_7 ( log , L_39 , type ) ;
return - V_65 ;
}
if ( ! V_303 ) {
V_80 = F_112 ( V_58 , V_257 , log ) ;
if ( V_80 )
return V_80 ;
}
}
if ( V_63 > 0 )
return - V_65 ;
return 0 ;
}
int F_114 ( struct V_118 * V_118 , const struct V_56 * V_57 ,
const struct V_242 * V_30 ,
struct V_256 * * V_257 , bool log )
{
int V_80 ;
* V_257 = F_77 ( F_17 ( V_57 ) , log ) ;
if ( F_92 ( * V_257 ) )
return F_106 ( * V_257 ) ;
( * V_257 ) -> V_277 = F_17 ( V_57 ) ;
V_80 = F_101 ( V_118 , V_57 , V_30 , 0 , V_257 , V_30 -> V_31 . type ,
V_30 -> V_31 . V_152 , log ) ;
if ( V_80 )
F_81 ( * V_257 ) ;
return V_80 ;
}
static int F_115 ( const struct V_56 * V_57 , struct V_109 * V_110 )
{
const struct V_56 * V_58 ;
struct V_56 * V_8 ;
int V_80 = 0 , V_63 ;
V_8 = F_33 ( V_110 , V_290 ) ;
if ( ! V_8 )
return - V_112 ;
F_15 (a, attr, rem) {
int type = F_16 ( V_58 ) ;
struct V_56 * V_343 ;
switch ( type ) {
case V_287 :
if ( F_42 ( V_110 , V_287 ,
sizeof( T_6 ) , F_18 ( V_58 ) ) )
return - V_112 ;
break;
case V_288 :
V_343 = F_33 ( V_110 , V_288 ) ;
if ( ! V_343 )
return - V_112 ;
V_80 = F_116 ( F_18 ( V_58 ) , F_17 ( V_58 ) , V_110 ) ;
if ( V_80 )
return V_80 ;
F_35 ( V_110 , V_343 ) ;
break;
}
}
F_35 ( V_110 , V_8 ) ;
return V_80 ;
}
static int F_117 ( const struct V_56 * V_58 , struct V_109 * V_110 )
{
const struct V_56 * V_260 = F_18 ( V_58 ) ;
int V_305 = F_16 ( V_260 ) ;
struct V_56 * V_8 ;
int V_80 ;
switch ( V_305 ) {
case V_49 : {
struct V_261 * V_262 = F_18 ( V_260 ) ;
struct V_115 * V_116 = & V_262 -> V_264 -> V_88 . V_116 ;
V_8 = F_33 ( V_110 , V_266 ) ;
if ( ! V_8 )
return - V_112 ;
V_80 = F_44 ( V_110 , V_116 ) ;
if ( V_80 )
return V_80 ;
F_35 ( V_110 , V_8 ) ;
break;
}
default:
if ( F_42 ( V_110 , V_266 , F_17 ( V_58 ) , V_260 ) )
return - V_112 ;
break;
}
return 0 ;
}
static int F_118 ( const struct V_56 * V_58 ,
struct V_109 * V_110 )
{
const struct V_56 * V_260 = F_18 ( V_58 ) ;
struct V_56 * V_61 ;
T_1 V_306 = F_17 ( V_260 ) / 2 ;
V_61 = F_33 ( V_110 , V_266 ) ;
if ( ! V_61 )
return - V_112 ;
if ( F_42 ( V_110 , F_16 ( V_260 ) , V_306 , F_18 ( V_260 ) ) )
return - V_112 ;
F_35 ( V_110 , V_61 ) ;
return 0 ;
}
int F_116 ( const struct V_56 * V_57 , int V_67 , struct V_109 * V_110 )
{
const struct V_56 * V_58 ;
int V_63 , V_80 ;
F_82 (a, attr, len, rem) {
int type = F_16 ( V_58 ) ;
switch ( type ) {
case V_266 :
V_80 = F_117 ( V_58 , V_110 ) ;
if ( V_80 )
return V_80 ;
break;
case V_308 :
V_80 = F_118 ( V_58 , V_110 ) ;
if ( V_80 )
return V_80 ;
break;
case V_290 :
V_80 = F_115 ( V_58 , V_110 ) ;
if ( V_80 )
return V_80 ;
break;
case V_267 :
V_80 = F_119 ( F_18 ( V_58 ) , V_110 ) ;
if ( V_80 )
return V_80 ;
break;
default:
if ( F_42 ( V_110 , type , F_17 ( V_58 ) , F_18 ( V_58 ) ) )
return - V_112 ;
break;
}
}
return 0 ;
}
