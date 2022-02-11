static bool F_1 ( const struct V_1 * V_2 )
{
struct V_1 * V_3 ;
int V_4 ;
F_2 (nla, actions, rem) {
T_1 V_5 = F_3 ( V_3 ) ;
switch ( V_5 ) {
case V_6 :
case V_7 :
case V_8 :
case V_9 :
break;
case V_10 :
case V_11 :
case V_12 :
case V_13 :
case V_14 :
case V_15 :
case V_16 :
case V_17 :
case V_18 :
case V_19 :
case V_20 :
default:
return true ;
}
}
return false ;
}
static void F_4 ( struct V_21 * V_22 ,
T_2 V_23 , T_2 V_24 , bool V_25 )
{
struct V_26 * V_27 ;
T_2 V_28 = F_5 ( V_23 , sizeof( long ) ) ;
T_2 V_29 = F_6 ( V_23 + V_24 , sizeof( long ) ) ;
if ( ! V_25 )
V_27 = & V_22 -> V_27 ;
else
V_27 = & V_22 -> V_30 -> V_27 ;
if ( V_27 -> V_28 == V_27 -> V_29 ) {
V_27 -> V_28 = V_28 ;
V_27 -> V_29 = V_29 ;
return;
}
if ( V_27 -> V_28 > V_28 )
V_27 -> V_28 = V_28 ;
if ( V_27 -> V_29 < V_29 )
V_27 -> V_29 = V_29 ;
}
static bool F_7 ( const struct V_21 * V_22 ,
T_3 V_31 , T_3 V_32 , bool log )
{
T_3 V_33 = 0 ;
T_3 V_34 = V_31 ;
V_34 &= ~ ( ( 1 << V_35 )
| ( 1 << V_36 )
| ( 1 << V_37 )
| ( 1 << V_38 )
| ( 1 << V_39 )
| ( 1 << V_40 )
| ( 1 << V_41 )
| ( 1 << V_42 )
| ( 1 << V_43 )
| ( 1 << V_44 )
| ( 1 << V_45 )
| ( 1 << V_46 )
| ( 1 << V_47 ) ) ;
V_34 |= ( ( 1 << V_48 )
| ( 1 << V_49 )
| ( 1 << V_50 ) ) ;
if ( V_22 -> V_51 -> V_52 . type == F_8 ( V_53 )
|| V_22 -> V_51 -> V_52 . type == F_8 ( V_54 ) ) {
V_33 |= 1 << V_45 ;
if ( V_22 -> V_30 && ( V_22 -> V_30 -> V_51 . V_52 . type == F_8 ( 0xffff ) ) )
V_34 |= 1 << V_45 ;
}
if ( F_9 ( V_22 -> V_51 -> V_52 . type ) ) {
V_33 |= 1 << V_47 ;
if ( V_22 -> V_30 && ( V_22 -> V_30 -> V_51 . V_52 . type == F_8 ( 0xffff ) ) )
V_34 |= 1 << V_47 ;
}
if ( V_22 -> V_51 -> V_52 . type == F_8 ( V_55 ) ) {
V_33 |= 1 << V_35 ;
if ( V_22 -> V_30 && V_22 -> V_30 -> V_51 . V_52 . type == F_8 ( 0xffff ) ) {
V_34 |= 1 << V_35 ;
V_34 |= 1 << V_36 ;
}
if ( V_22 -> V_51 -> V_56 . V_57 != V_58 ) {
if ( V_22 -> V_51 -> V_56 . V_59 == V_60 ) {
V_33 |= 1 << V_41 ;
if ( V_22 -> V_30 && ( V_22 -> V_30 -> V_51 . V_56 . V_59 == 0xff ) )
V_34 |= 1 << V_41 ;
}
if ( V_22 -> V_51 -> V_56 . V_59 == V_61 ) {
V_33 |= 1 << V_42 ;
if ( V_22 -> V_30 && ( V_22 -> V_30 -> V_51 . V_56 . V_59 == 0xff ) )
V_34 |= 1 << V_42 ;
}
if ( V_22 -> V_51 -> V_56 . V_59 == V_62 ) {
V_33 |= 1 << V_39 ;
V_33 |= 1 << V_40 ;
if ( V_22 -> V_30 && ( V_22 -> V_30 -> V_51 . V_56 . V_59 == 0xff ) ) {
V_34 |= 1 << V_39 ;
V_34 |= 1 << V_40 ;
}
}
if ( V_22 -> V_51 -> V_56 . V_59 == V_63 ) {
V_33 |= 1 << V_43 ;
if ( V_22 -> V_30 && ( V_22 -> V_30 -> V_51 . V_56 . V_59 == 0xff ) )
V_34 |= 1 << V_43 ;
}
}
}
if ( V_22 -> V_51 -> V_52 . type == F_8 ( V_64 ) ) {
V_33 |= 1 << V_37 ;
if ( V_22 -> V_30 && V_22 -> V_30 -> V_51 . V_52 . type == F_8 ( 0xffff ) ) {
V_34 |= 1 << V_37 ;
V_34 |= 1 << V_38 ;
}
if ( V_22 -> V_51 -> V_56 . V_57 != V_58 ) {
if ( V_22 -> V_51 -> V_56 . V_59 == V_60 ) {
V_33 |= 1 << V_41 ;
if ( V_22 -> V_30 && ( V_22 -> V_30 -> V_51 . V_56 . V_59 == 0xff ) )
V_34 |= 1 << V_41 ;
}
if ( V_22 -> V_51 -> V_56 . V_59 == V_61 ) {
V_33 |= 1 << V_42 ;
if ( V_22 -> V_30 && ( V_22 -> V_30 -> V_51 . V_56 . V_59 == 0xff ) )
V_34 |= 1 << V_42 ;
}
if ( V_22 -> V_51 -> V_56 . V_59 == V_62 ) {
V_33 |= 1 << V_39 ;
V_33 |= 1 << V_40 ;
if ( V_22 -> V_30 && ( V_22 -> V_30 -> V_51 . V_56 . V_59 == 0xff ) ) {
V_34 |= 1 << V_39 ;
V_34 |= 1 << V_40 ;
}
}
if ( V_22 -> V_51 -> V_56 . V_59 == V_65 ) {
V_33 |= 1 << V_44 ;
if ( V_22 -> V_30 && ( V_22 -> V_30 -> V_51 . V_56 . V_59 == 0xff ) )
V_34 |= 1 << V_44 ;
if ( V_22 -> V_51 -> V_66 . V_67 ==
F_8 ( V_68 ) ||
V_22 -> V_51 -> V_66 . V_67 == F_8 ( V_69 ) ) {
V_33 |= 1 << V_46 ;
V_34 &= ~ ( 1ULL << V_38 ) ;
if ( V_22 -> V_30 && ( V_22 -> V_30 -> V_51 . V_66 . V_67 == F_8 ( 0xff ) ) )
V_34 |= 1 << V_46 ;
}
}
}
}
if ( ( V_31 & V_33 ) != V_33 ) {
F_10 ( log , L_1 ,
( unsigned long long ) V_31 ,
( unsigned long long ) V_33 ) ;
return false ;
}
if ( ( V_32 & V_34 ) != V_32 ) {
F_10 ( log , L_2 ,
( unsigned long long ) V_32 ,
( unsigned long long ) V_34 ) ;
return false ;
}
return true ;
}
T_2 F_11 ( void )
{
return F_12 ( 8 )
+ F_13 ( 16 )
+ F_13 ( 16 )
+ F_13 ( 1 )
+ F_13 ( 1 )
+ F_13 ( 0 )
+ F_13 ( 0 )
+ F_13 ( 0 )
+ F_13 ( 256 )
+ F_13 ( 2 )
+ F_13 ( 2 ) ;
}
T_2 F_14 ( void )
{
F_15 ( V_70 != 28 ) ;
return F_13 ( 4 )
+ F_13 ( 0 )
+ F_11 ()
+ F_13 ( 4 )
+ F_13 ( 4 )
+ F_13 ( 4 )
+ F_13 ( 4 )
+ F_13 ( 4 )
+ F_13 ( 2 )
+ F_13 ( 4 )
+ F_13 ( 16 )
+ F_13 ( 40 )
+ F_13 ( 12 )
+ F_13 ( 2 )
+ F_13 ( 4 )
+ F_13 ( 0 )
+ F_13 ( 2 )
+ F_13 ( 40 )
+ F_13 ( 2 )
+ F_13 ( 28 ) ;
}
static bool F_16 ( unsigned int V_71 , unsigned int V_72 )
{
return V_72 == V_71 ||
V_72 == V_73 ||
V_72 == V_74 ;
}
static bool F_17 ( const T_4 * V_75 , T_2 V_24 )
{
int V_76 ;
if ( ! V_75 )
return false ;
for ( V_76 = 0 ; V_76 < V_24 ; V_76 ++ )
if ( V_75 [ V_76 ] )
return false ;
return true ;
}
static int F_18 ( const struct V_1 * V_77 ,
const struct V_1 * V_78 [] ,
T_3 * V_79 , bool log , bool V_80 )
{
const struct V_1 * V_3 ;
T_3 V_81 ;
int V_4 ;
V_81 = * V_79 ;
F_2 (nla, attr, rem) {
T_1 type = F_3 ( V_3 ) ;
int V_72 ;
if ( type > V_82 ) {
F_10 ( log , L_3 ,
type , V_82 ) ;
return - V_83 ;
}
if ( V_81 & ( 1 << type ) ) {
F_10 ( log , L_4 , type ) ;
return - V_83 ;
}
V_72 = V_84 [ type ] . V_85 ;
if ( ! F_16 ( F_19 ( V_3 ) , V_72 ) ) {
F_10 ( log , L_5 ,
type , F_19 ( V_3 ) , V_72 ) ;
return - V_83 ;
}
if ( ! V_80 || ! F_17 ( F_20 ( V_3 ) , V_72 ) ) {
V_81 |= 1 << type ;
V_78 [ type ] = V_3 ;
}
}
if ( V_4 ) {
F_10 ( log , L_6 , V_4 ) ;
return - V_83 ;
}
* V_79 = V_81 ;
return 0 ;
}
static int F_21 ( const struct V_1 * V_77 ,
const struct V_1 * V_78 [] , T_3 * V_79 ,
bool log )
{
return F_18 ( V_77 , V_78 , V_79 , log , true ) ;
}
int F_22 ( const struct V_1 * V_77 , const struct V_1 * V_78 [] ,
T_3 * V_79 , bool log )
{
return F_18 ( V_77 , V_78 , V_79 , log , false ) ;
}
static int F_23 ( const struct V_1 * V_78 ,
struct V_21 * V_22 , bool V_25 ,
bool log )
{
unsigned long V_86 ;
if ( F_19 ( V_78 ) > sizeof( V_22 -> V_51 -> V_87 ) ) {
F_10 ( log , L_7 ,
F_19 ( V_78 ) , sizeof( V_22 -> V_51 -> V_87 ) ) ;
return - V_83 ;
}
if ( F_19 ( V_78 ) % 4 != 0 ) {
F_10 ( log , L_8 ,
F_19 ( V_78 ) ) ;
return - V_83 ;
}
if ( ! V_25 ) {
F_24 ( V_22 , V_88 , F_19 ( V_78 ) ,
false ) ;
} else {
if ( V_22 -> V_51 -> V_88 != F_19 ( V_78 ) ) {
F_10 ( log , L_9 ,
V_22 -> V_51 -> V_88 , F_19 ( V_78 ) ) ;
return - V_83 ;
}
F_24 ( V_22 , V_88 , 0xff , true ) ;
}
V_86 = F_25 ( F_19 ( V_78 ) ) ;
F_26 ( V_22 , V_86 , F_20 ( V_78 ) ,
F_19 ( V_78 ) , V_25 ) ;
return 0 ;
}
static int F_27 ( const struct V_1 * V_77 ,
struct V_21 * V_22 , bool V_25 ,
bool log )
{
struct V_1 * V_78 ;
int V_4 ;
unsigned long V_86 ;
struct V_89 V_90 ;
F_15 ( sizeof( V_90 ) > sizeof( V_22 -> V_51 -> V_87 ) ) ;
memset ( & V_90 , 0 , sizeof( V_90 ) ) ;
F_2 (a, attr, rem) {
int type = F_3 ( V_78 ) ;
if ( type > V_91 ) {
F_10 ( log , L_10 ,
type , V_91 ) ;
return - V_83 ;
}
if ( ! F_16 ( F_19 ( V_78 ) ,
V_92 [ type ] . V_85 ) ) {
F_10 ( log , L_11 ,
type , F_19 ( V_78 ) ,
V_92 [ type ] . V_85 ) ;
return - V_83 ;
}
switch ( type ) {
case V_93 :
V_90 . V_94 = F_28 ( V_78 ) ;
break;
default:
F_10 ( log , L_12 ,
type ) ;
return - V_83 ;
}
}
if ( V_4 ) {
F_10 ( log , L_13 ,
V_4 ) ;
return - V_83 ;
}
if ( ! V_25 )
F_24 ( V_22 , V_88 , sizeof( V_90 ) , false ) ;
else
F_24 ( V_22 , V_88 , 0xff , true ) ;
V_86 = F_25 ( sizeof( V_90 ) ) ;
F_26 ( V_22 , V_86 , & V_90 , sizeof( V_90 ) ,
V_25 ) ;
return 0 ;
}
static int F_29 ( const struct V_1 * V_77 ,
struct V_21 * V_22 , bool V_25 ,
bool log )
{
bool V_95 = false , V_96 = false , V_97 = false ;
T_5 V_98 = 0 ;
int V_99 = 0 ;
struct V_1 * V_78 ;
int V_4 ;
F_2 (a, attr, rem) {
int type = F_3 ( V_78 ) ;
int V_100 ;
if ( type > V_101 ) {
F_10 ( log , L_14 ,
type , V_101 ) ;
return - V_83 ;
}
if ( ! F_16 ( F_19 ( V_78 ) ,
V_102 [ type ] . V_85 ) ) {
F_10 ( log , L_15 ,
type , F_19 ( V_78 ) , V_102 [ type ] . V_85 ) ;
return - V_83 ;
}
switch ( type ) {
case V_103 :
F_24 ( V_22 , V_104 . V_105 ,
F_30 ( V_78 ) , V_25 ) ;
V_98 |= V_106 ;
break;
case V_107 :
F_24 ( V_22 , V_104 . V_108 . V_96 . V_67 ,
F_31 ( V_78 ) , V_25 ) ;
V_96 = true ;
break;
case V_109 :
F_24 ( V_22 , V_104 . V_108 . V_96 . V_110 ,
F_31 ( V_78 ) , V_25 ) ;
V_96 = true ;
break;
case V_111 :
F_24 ( V_22 , V_104 . V_108 . V_97 . V_67 ,
F_32 ( V_78 ) , V_25 ) ;
V_97 = true ;
break;
case V_112 :
F_24 ( V_22 , V_104 . V_108 . V_97 . V_110 ,
F_32 ( V_78 ) , V_25 ) ;
V_97 = true ;
break;
case V_113 :
F_24 ( V_22 , V_104 . V_114 ,
F_33 ( V_78 ) , V_25 ) ;
break;
case V_115 :
F_24 ( V_22 , V_104 . V_95 ,
F_33 ( V_78 ) , V_25 ) ;
V_95 = true ;
break;
case V_116 :
V_98 |= V_117 ;
break;
case V_118 :
V_98 |= V_119 ;
break;
case V_120 :
F_24 ( V_22 , V_104 . V_121 ,
F_34 ( V_78 ) , V_25 ) ;
break;
case V_122 :
F_24 ( V_22 , V_104 . V_123 ,
F_34 ( V_78 ) , V_25 ) ;
break;
case V_124 :
V_98 |= V_125 ;
break;
case V_126 :
if ( V_99 ) {
F_10 ( log , L_16 ) ;
return - V_83 ;
}
V_100 = F_23 ( V_78 , V_22 , V_25 , log ) ;
if ( V_100 )
return V_100 ;
V_98 |= V_127 ;
V_99 = type ;
break;
case V_128 :
if ( V_99 ) {
F_10 ( log , L_16 ) ;
return - V_83 ;
}
V_100 = F_27 ( V_78 , V_22 , V_25 , log ) ;
if ( V_100 )
return V_100 ;
V_98 |= V_129 ;
V_99 = type ;
break;
case V_130 :
break;
default:
F_10 ( log , L_17 ,
type ) ;
return - V_83 ;
}
}
F_24 ( V_22 , V_104 . V_98 , V_98 , V_25 ) ;
if ( V_25 )
F_35 ( V_22 , V_131 , 0xff , true ) ;
else
F_24 ( V_22 , V_131 , V_97 ? V_132 : V_133 ,
false ) ;
if ( V_4 > 0 ) {
F_10 ( log , L_18 ,
V_4 ) ;
return - V_83 ;
}
if ( V_96 && V_97 ) {
F_10 ( log , L_19 ) ;
return - V_83 ;
}
if ( ! V_25 ) {
if ( ! V_96 && ! V_97 ) {
F_10 ( log , L_20 ) ;
return - V_83 ;
}
if ( V_96 && ! V_22 -> V_51 -> V_104 . V_108 . V_96 . V_110 ) {
F_10 ( log , L_21 ) ;
return - V_83 ;
}
if ( V_97 && F_36 ( & V_22 -> V_51 -> V_104 . V_108 . V_97 . V_110 ) ) {
F_10 ( log , L_22 ) ;
return - V_83 ;
}
if ( ! V_95 ) {
F_10 ( log , L_23 ) ;
return - V_83 ;
}
}
return V_99 ;
}
static int F_37 ( struct V_134 * V_135 ,
const void * V_87 , int V_136 )
{
const struct V_89 * V_90 = V_87 ;
struct V_1 * V_3 ;
V_3 = F_38 ( V_135 , V_128 ) ;
if ( ! V_3 )
return - V_137 ;
if ( F_39 ( V_135 , V_93 , V_90 -> V_94 ) < 0 )
return - V_137 ;
F_40 ( V_135 , V_3 ) ;
return 0 ;
}
static int F_41 ( struct V_134 * V_135 ,
const struct V_138 * V_139 ,
const void * V_87 , int V_136 ,
unsigned short V_131 )
{
if ( V_139 -> V_98 & V_106 &&
F_42 ( V_135 , V_103 , V_139 -> V_105 ,
V_130 ) )
return - V_137 ;
switch ( V_131 ) {
case V_133 :
if ( V_139 -> V_108 . V_96 . V_67 &&
F_43 ( V_135 , V_107 ,
V_139 -> V_108 . V_96 . V_67 ) )
return - V_137 ;
if ( V_139 -> V_108 . V_96 . V_110 &&
F_43 ( V_135 , V_109 ,
V_139 -> V_108 . V_96 . V_110 ) )
return - V_137 ;
break;
case V_132 :
if ( ! F_36 ( & V_139 -> V_108 . V_97 . V_67 ) &&
F_44 ( V_135 , V_111 ,
& V_139 -> V_108 . V_97 . V_67 ) )
return - V_137 ;
if ( ! F_36 ( & V_139 -> V_108 . V_97 . V_110 ) &&
F_44 ( V_135 , V_112 ,
& V_139 -> V_108 . V_97 . V_110 ) )
return - V_137 ;
break;
}
if ( V_139 -> V_114 &&
F_45 ( V_135 , V_113 , V_139 -> V_114 ) )
return - V_137 ;
if ( F_45 ( V_135 , V_115 , V_139 -> V_95 ) )
return - V_137 ;
if ( ( V_139 -> V_98 & V_117 ) &&
F_46 ( V_135 , V_116 ) )
return - V_137 ;
if ( ( V_139 -> V_98 & V_119 ) &&
F_46 ( V_135 , V_118 ) )
return - V_137 ;
if ( V_139 -> V_121 &&
F_47 ( V_135 , V_120 , V_139 -> V_121 ) )
return - V_137 ;
if ( V_139 -> V_123 &&
F_47 ( V_135 , V_122 , V_139 -> V_123 ) )
return - V_137 ;
if ( ( V_139 -> V_98 & V_125 ) &&
F_46 ( V_135 , V_124 ) )
return - V_137 ;
if ( V_136 ) {
if ( V_139 -> V_98 & V_127 &&
F_48 ( V_135 , V_126 ,
V_136 , V_87 ) )
return - V_137 ;
else if ( V_139 -> V_98 & V_129 &&
F_37 ( V_135 , V_87 , V_136 ) )
return - V_137 ;
}
return 0 ;
}
static int F_49 ( struct V_134 * V_135 ,
const struct V_138 * V_139 ,
const void * V_87 , int V_136 ,
unsigned short V_131 )
{
struct V_1 * V_3 ;
int V_100 ;
V_3 = F_38 ( V_135 , V_48 ) ;
if ( ! V_3 )
return - V_137 ;
V_100 = F_41 ( V_135 , V_139 , V_87 , V_136 ,
V_131 ) ;
if ( V_100 )
return V_100 ;
F_40 ( V_135 , V_3 ) ;
return 0 ;
}
int F_50 ( struct V_134 * V_135 ,
struct V_140 * V_141 )
{
return F_41 ( V_135 , & V_141 -> V_51 ,
F_51 ( V_141 ) ,
V_141 -> V_142 ,
F_52 ( V_141 ) ) ;
}
static int F_53 ( struct V_21 * V_22 ,
const struct V_1 * V_78 [] ,
bool V_25 , bool V_143 )
{
T_5 V_144 = 0 ;
T_5 V_145 = 0 ;
if ( V_78 [ V_146 ] )
V_144 = F_34 ( V_78 [ V_146 ] ) ;
if ( V_78 [ V_50 ] )
V_145 = F_34 ( V_78 [ V_50 ] ) ;
if ( F_54 ( ! V_143 ) ) {
F_24 ( V_22 , V_52 . V_147 . V_145 , V_145 , V_25 ) ;
F_24 ( V_22 , V_52 . V_147 . V_144 , V_144 , V_25 ) ;
} else {
F_24 ( V_22 , V_52 . V_148 . V_145 , V_145 , V_25 ) ;
F_24 ( V_22 , V_52 . V_148 . V_144 , V_144 , V_25 ) ;
}
return 0 ;
}
static int F_55 ( const struct V_21 * V_22 ,
T_3 V_31 , bool V_143 ,
const struct V_1 * * V_78 , bool log )
{
T_5 V_144 = 0 ;
if ( ! ( ( V_31 & ( 1 << V_149 ) ) &&
( V_31 & ( 1 << V_50 ) ) &&
F_56 ( F_34 ( V_78 [ V_50 ] ) ) ) ) {
return 0 ;
}
if ( ! ( ( V_31 & ( 1 << V_146 ) ) &&
( V_31 & ( 1 << V_150 ) ) ) ) {
F_10 ( log , L_24 , ( V_143 ) ? L_25 : L_26 ) ;
return - V_83 ;
}
if ( V_78 [ V_146 ] )
V_144 = F_34 ( V_78 [ V_146 ] ) ;
if ( ! ( V_144 & F_8 ( V_151 ) ) ) {
if ( V_144 ) {
F_10 ( log , L_27 ,
( V_143 ) ? L_25 : L_26 ) ;
return - V_83 ;
} else if ( F_19 ( V_78 [ V_150 ] ) ) {
F_10 ( log , L_28 ,
( V_143 ) ? L_25 : L_26 ) ;
return - V_83 ;
}
}
return 1 ;
}
static int F_57 ( const struct V_21 * V_22 ,
T_3 V_31 , bool V_143 ,
const struct V_1 * * V_78 , bool log )
{
T_5 V_144 = 0 ;
T_5 V_145 = 0 ;
bool V_152 = ! ! ( V_22 -> V_51 -> V_52 . V_147 . V_144 &
F_8 ( V_151 ) ) ;
bool V_153 = ! ! ( V_22 -> V_51 -> V_52 . V_148 . V_144 &
F_8 ( V_151 ) ) ;
if ( ! ( V_31 & ( 1 << V_150 ) ) ) {
return 0 ;
}
if ( ( ! V_143 && ! V_152 ) || ( V_143 && ! V_153 ) ) {
F_10 ( log , L_29 ,
( V_143 ) ? L_25 : L_26 ) ;
return - V_83 ;
}
if ( V_78 [ V_146 ] )
V_144 = F_34 ( V_78 [ V_146 ] ) ;
if ( V_78 [ V_50 ] )
V_145 = F_34 ( V_78 [ V_50 ] ) ;
if ( V_145 != F_8 ( 0xffff ) ) {
F_10 ( log , L_30 ,
( V_143 ) ? L_25 : L_26 , F_58 ( V_145 ) ) ;
return - V_83 ;
}
if ( ! ( V_144 & F_8 ( V_151 ) ) ) {
F_10 ( log , L_31 ,
( V_143 ) ? L_25 : L_26 ) ;
return - V_83 ;
}
return 1 ;
}
static int F_59 ( struct V_21 * V_22 ,
T_3 * V_31 , bool V_143 ,
const struct V_1 * * V_78 , bool V_25 ,
bool log )
{
int V_100 ;
const struct V_1 * V_154 ;
if ( ! V_25 )
V_100 = F_55 ( V_22 , * V_31 , V_143 ,
V_78 , log ) ;
else
V_100 = F_57 ( V_22 , * V_31 , V_143 ,
V_78 , log ) ;
if ( V_100 <= 0 )
return V_100 ;
V_100 = F_53 ( V_22 , V_78 , V_25 , V_143 ) ;
if ( V_100 )
return V_100 ;
* V_31 &= ~ ( 1 << V_150 ) ;
* V_31 &= ~ ( 1 << V_146 ) ;
* V_31 &= ~ ( 1 << V_50 ) ;
V_154 = V_78 [ V_150 ] ;
if ( ! V_25 )
V_100 = F_22 ( V_154 , V_78 , V_31 , log ) ;
else
V_100 = F_21 ( V_154 , V_78 , V_31 , log ) ;
return V_100 ;
}
static int F_60 ( struct V_21 * V_22 ,
T_3 * V_31 , const struct V_1 * * V_78 ,
bool V_25 , bool log )
{
int V_100 ;
bool V_152 = false ;
V_100 = F_59 ( V_22 , V_31 , false , V_78 ,
V_25 , log ) ;
if ( V_100 )
return V_100 ;
V_152 = ! ! ( V_22 -> V_51 -> V_52 . V_147 . V_144 & F_8 ( V_151 ) ) ;
if ( V_152 ) {
V_100 = F_59 ( V_22 , V_31 , true , V_78 ,
V_25 , log ) ;
if ( V_100 )
return V_100 ;
}
return 0 ;
}
static int F_61 ( struct V_21 * V_22 ,
T_3 * V_81 , const struct V_1 * * V_78 ,
bool V_25 , bool log )
{
T_5 V_155 ;
V_155 = F_34 ( V_78 [ V_50 ] ) ;
if ( V_25 ) {
V_155 = F_8 ( 0xffff ) ;
} else if ( ! F_62 ( V_155 ) ) {
F_10 ( log , L_32 ,
F_58 ( V_155 ) , V_156 ) ;
return - V_83 ;
}
F_24 ( V_22 , V_52 . type , V_155 , V_25 ) ;
* V_81 &= ~ ( 1 << V_50 ) ;
return 0 ;
}
static int F_63 ( struct V_157 * V_157 , struct V_21 * V_22 ,
T_3 * V_81 , const struct V_1 * * V_78 ,
bool V_25 , bool log )
{
T_4 V_158 = V_159 ;
if ( * V_81 & ( 1 << V_160 ) ) {
T_6 V_161 = F_28 ( V_78 [ V_160 ] ) ;
F_24 ( V_22 , V_162 , V_161 , V_25 ) ;
* V_81 &= ~ ( 1 << V_160 ) ;
}
if ( * V_81 & ( 1 << V_163 ) ) {
T_6 V_164 = F_28 ( V_78 [ V_163 ] ) ;
F_24 ( V_22 , V_164 , V_164 , V_25 ) ;
* V_81 &= ~ ( 1 << V_163 ) ;
}
if ( * V_81 & ( 1 << V_165 ) ) {
F_24 ( V_22 , V_166 . V_167 ,
F_28 ( V_78 [ V_165 ] ) , V_25 ) ;
* V_81 &= ~ ( 1 << V_165 ) ;
}
if ( * V_81 & ( 1 << V_49 ) ) {
T_6 V_168 = F_28 ( V_78 [ V_49 ] ) ;
if ( V_25 ) {
V_168 = 0xffffffff ;
} else if ( V_168 >= V_169 ) {
F_10 ( log , L_33 ,
V_168 , V_169 ) ;
return - V_83 ;
}
F_24 ( V_22 , V_166 . V_168 , V_168 , V_25 ) ;
* V_81 &= ~ ( 1 << V_49 ) ;
} else if ( ! V_25 ) {
F_24 ( V_22 , V_166 . V_168 , V_169 , V_25 ) ;
}
if ( * V_81 & ( 1 << V_170 ) ) {
T_7 V_171 = F_28 ( V_78 [ V_170 ] ) ;
F_24 ( V_22 , V_166 . V_172 , V_171 , V_25 ) ;
* V_81 &= ~ ( 1 << V_170 ) ;
}
if ( * V_81 & ( 1 << V_48 ) ) {
if ( F_29 ( V_78 [ V_48 ] , V_22 ,
V_25 , log ) < 0 )
return - V_83 ;
* V_81 &= ~ ( 1 << V_48 ) ;
}
if ( * V_81 & ( 1 << V_173 ) &&
F_64 ( V_157 , V_173 ) ) {
T_6 V_174 = F_28 ( V_78 [ V_173 ] ) ;
if ( V_174 & ~ V_175 ) {
F_10 ( log , L_34 ,
V_174 ) ;
return - V_83 ;
}
F_24 ( V_22 , V_174 , V_174 , V_25 ) ;
* V_81 &= ~ ( 1ULL << V_173 ) ;
}
if ( * V_81 & ( 1 << V_176 ) &&
F_64 ( V_157 , V_176 ) ) {
T_1 V_177 = F_65 ( V_78 [ V_176 ] ) ;
F_24 ( V_22 , V_177 , V_177 , V_25 ) ;
* V_81 &= ~ ( 1ULL << V_176 ) ;
}
if ( * V_81 & ( 1 << V_178 ) &&
F_64 ( V_157 , V_178 ) ) {
T_6 V_171 = F_28 ( V_78 [ V_178 ] ) ;
F_24 ( V_22 , V_179 . V_171 , V_171 , V_25 ) ;
* V_81 &= ~ ( 1ULL << V_178 ) ;
}
if ( * V_81 & ( 1 << V_180 ) &&
F_64 ( V_157 , V_180 ) ) {
const struct V_181 * V_182 ;
V_182 = F_20 ( V_78 [ V_180 ] ) ;
F_66 ( V_22 , V_179 . V_183 , V_182 -> V_184 ,
sizeof( * V_182 ) , V_25 ) ;
* V_81 &= ~ ( 1ULL << V_180 ) ;
}
if ( * V_81 & ( 1ULL << V_36 ) ) {
const struct V_185 * V_179 ;
V_179 = F_20 ( V_78 [ V_36 ] ) ;
F_24 ( V_22 , V_96 . V_186 . V_67 , V_179 -> V_187 , V_25 ) ;
F_24 ( V_22 , V_96 . V_186 . V_110 , V_179 -> V_188 , V_25 ) ;
F_24 ( V_22 , V_179 . V_189 . V_67 , V_179 -> V_190 , V_25 ) ;
F_24 ( V_22 , V_179 . V_189 . V_110 , V_179 -> V_191 , V_25 ) ;
F_24 ( V_22 , V_192 , V_179 -> V_193 , V_25 ) ;
* V_81 &= ~ ( 1ULL << V_36 ) ;
}
if ( * V_81 & ( 1ULL << V_38 ) ) {
const struct V_194 * V_179 ;
V_179 = F_20 ( V_78 [ V_38 ] ) ;
F_66 ( V_22 , V_97 . V_186 . V_67 , & V_179 -> V_195 ,
sizeof( V_22 -> V_51 -> V_97 . V_186 . V_67 ) ,
V_25 ) ;
F_66 ( V_22 , V_97 . V_186 . V_110 , & V_179 -> V_196 ,
sizeof( V_22 -> V_51 -> V_97 . V_186 . V_110 ) ,
V_25 ) ;
F_24 ( V_22 , V_179 . V_189 . V_67 , V_179 -> V_190 , V_25 ) ;
F_24 ( V_22 , V_179 . V_189 . V_110 , V_179 -> V_191 , V_25 ) ;
F_24 ( V_22 , V_192 , V_179 -> V_197 , V_25 ) ;
* V_81 &= ~ ( 1ULL << V_38 ) ;
}
if ( ! ( * V_81 & ( 1ULL << V_149 ) ) &&
( * V_81 & ( 1ULL << V_50 ) ) )
V_158 = V_198 ;
F_24 ( V_22 , V_158 , V_25 ? 0xff : V_158 , V_25 ) ;
if ( V_158 == V_198 )
return F_61 ( V_22 , V_81 , V_78 , V_25 ,
log ) ;
return 0 ;
}
static int F_67 ( struct V_157 * V_157 , struct V_21 * V_22 ,
T_3 V_81 , const struct V_1 * * V_78 ,
bool V_25 , bool log )
{
int V_100 ;
V_100 = F_63 ( V_157 , V_22 , & V_81 , V_78 , V_25 , log ) ;
if ( V_100 )
return V_100 ;
if ( V_81 & ( 1 << V_149 ) ) {
const struct V_199 * V_200 ;
V_200 = F_20 ( V_78 [ V_149 ] ) ;
F_66 ( V_22 , V_52 . V_67 ,
V_200 -> V_201 , V_202 , V_25 ) ;
F_66 ( V_22 , V_52 . V_110 ,
V_200 -> V_203 , V_202 , V_25 ) ;
V_81 &= ~ ( 1 << V_149 ) ;
if ( V_81 & ( 1 << V_146 ) ) {
F_10 ( log , L_35 ) ;
return - V_83 ;
}
if ( V_81 & ( 1 << V_50 ) ) {
V_100 = F_61 ( V_22 , & V_81 , V_78 , V_25 ,
log ) ;
if ( V_100 )
return V_100 ;
} else if ( ! V_25 ) {
F_24 ( V_22 , V_52 . type , F_8 ( V_204 ) , V_25 ) ;
}
} else if ( ! V_22 -> V_51 -> V_52 . type ) {
F_10 ( log , L_36 ) ;
return - V_83 ;
}
if ( V_81 & ( 1 << V_35 ) ) {
const struct V_205 * V_206 ;
V_206 = F_20 ( V_78 [ V_35 ] ) ;
if ( ! V_25 && V_206 -> V_207 > V_208 ) {
F_10 ( log , L_37 ,
V_206 -> V_207 , V_208 ) ;
return - V_83 ;
}
F_24 ( V_22 , V_56 . V_59 ,
V_206 -> V_193 , V_25 ) ;
F_24 ( V_22 , V_56 . V_114 ,
V_206 -> V_209 , V_25 ) ;
F_24 ( V_22 , V_56 . V_95 ,
V_206 -> V_210 , V_25 ) ;
F_24 ( V_22 , V_56 . V_57 ,
V_206 -> V_207 , V_25 ) ;
F_24 ( V_22 , V_96 . V_211 . V_67 ,
V_206 -> V_187 , V_25 ) ;
F_24 ( V_22 , V_96 . V_211 . V_110 ,
V_206 -> V_188 , V_25 ) ;
V_81 &= ~ ( 1 << V_35 ) ;
}
if ( V_81 & ( 1 << V_37 ) ) {
const struct V_212 * V_213 ;
V_213 = F_20 ( V_78 [ V_37 ] ) ;
if ( ! V_25 && V_213 -> V_214 > V_208 ) {
F_10 ( log , L_38 ,
V_213 -> V_214 , V_208 ) ;
return - V_83 ;
}
if ( ! V_25 && V_213 -> V_215 & F_68 ( 0xFFF00000 ) ) {
F_10 ( log , L_39 ,
F_69 ( V_213 -> V_215 ) , ( 1 << 20 ) - 1 ) ;
return - V_83 ;
}
F_24 ( V_22 , V_97 . V_216 ,
V_213 -> V_215 , V_25 ) ;
F_24 ( V_22 , V_56 . V_59 ,
V_213 -> V_197 , V_25 ) ;
F_24 ( V_22 , V_56 . V_114 ,
V_213 -> V_217 , V_25 ) ;
F_24 ( V_22 , V_56 . V_95 ,
V_213 -> V_218 , V_25 ) ;
F_24 ( V_22 , V_56 . V_57 ,
V_213 -> V_214 , V_25 ) ;
F_66 ( V_22 , V_97 . V_211 . V_67 ,
V_213 -> V_195 ,
sizeof( V_22 -> V_51 -> V_97 . V_211 . V_67 ) ,
V_25 ) ;
F_66 ( V_22 , V_97 . V_211 . V_110 ,
V_213 -> V_196 ,
sizeof( V_22 -> V_51 -> V_97 . V_211 . V_110 ) ,
V_25 ) ;
V_81 &= ~ ( 1 << V_37 ) ;
}
if ( V_81 & ( 1 << V_45 ) ) {
const struct V_219 * V_220 ;
V_220 = F_20 ( V_78 [ V_45 ] ) ;
if ( ! V_25 && ( V_220 -> V_221 & F_8 ( 0xff00 ) ) ) {
F_10 ( log , L_40 ,
V_220 -> V_221 ) ;
return - V_83 ;
}
F_24 ( V_22 , V_96 . V_211 . V_67 ,
V_220 -> V_222 , V_25 ) ;
F_24 ( V_22 , V_96 . V_211 . V_110 ,
V_220 -> V_223 , V_25 ) ;
F_24 ( V_22 , V_56 . V_59 ,
F_58 ( V_220 -> V_221 ) , V_25 ) ;
F_66 ( V_22 , V_96 . V_224 . V_225 ,
V_220 -> V_226 , V_202 , V_25 ) ;
F_66 ( V_22 , V_96 . V_224 . V_227 ,
V_220 -> V_228 , V_202 , V_25 ) ;
V_81 &= ~ ( 1 << V_45 ) ;
}
if ( V_81 & ( 1 << V_47 ) ) {
const struct V_229 * V_230 ;
V_230 = F_20 ( V_78 [ V_47 ] ) ;
F_24 ( V_22 , V_231 . V_232 ,
V_230 -> V_233 , V_25 ) ;
V_81 &= ~ ( 1 << V_47 ) ;
}
if ( V_81 & ( 1 << V_39 ) ) {
const struct V_234 * V_235 ;
V_235 = F_20 ( V_78 [ V_39 ] ) ;
F_24 ( V_22 , V_66 . V_67 , V_235 -> V_236 , V_25 ) ;
F_24 ( V_22 , V_66 . V_110 , V_235 -> V_237 , V_25 ) ;
V_81 &= ~ ( 1 << V_39 ) ;
}
if ( V_81 & ( 1 << V_40 ) ) {
F_24 ( V_22 , V_66 . V_238 ,
F_34 ( V_78 [ V_40 ] ) ,
V_25 ) ;
V_81 &= ~ ( 1 << V_40 ) ;
}
if ( V_81 & ( 1 << V_41 ) ) {
const struct V_239 * V_240 ;
V_240 = F_20 ( V_78 [ V_41 ] ) ;
F_24 ( V_22 , V_66 . V_67 , V_240 -> V_241 , V_25 ) ;
F_24 ( V_22 , V_66 . V_110 , V_240 -> V_242 , V_25 ) ;
V_81 &= ~ ( 1 << V_41 ) ;
}
if ( V_81 & ( 1 << V_42 ) ) {
const struct V_243 * V_244 ;
V_244 = F_20 ( V_78 [ V_42 ] ) ;
F_24 ( V_22 , V_66 . V_67 , V_244 -> V_245 , V_25 ) ;
F_24 ( V_22 , V_66 . V_110 , V_244 -> V_246 , V_25 ) ;
V_81 &= ~ ( 1 << V_42 ) ;
}
if ( V_81 & ( 1 << V_43 ) ) {
const struct V_247 * V_248 ;
V_248 = F_20 ( V_78 [ V_43 ] ) ;
F_24 ( V_22 , V_66 . V_67 ,
F_8 ( V_248 -> V_249 ) , V_25 ) ;
F_24 ( V_22 , V_66 . V_110 ,
F_8 ( V_248 -> V_250 ) , V_25 ) ;
V_81 &= ~ ( 1 << V_43 ) ;
}
if ( V_81 & ( 1 << V_44 ) ) {
const struct V_251 * V_252 ;
V_252 = F_20 ( V_78 [ V_44 ] ) ;
F_24 ( V_22 , V_66 . V_67 ,
F_8 ( V_252 -> V_253 ) , V_25 ) ;
F_24 ( V_22 , V_66 . V_110 ,
F_8 ( V_252 -> V_254 ) , V_25 ) ;
V_81 &= ~ ( 1 << V_44 ) ;
}
if ( V_81 & ( 1 << V_46 ) ) {
const struct V_255 * V_256 ;
V_256 = F_20 ( V_78 [ V_46 ] ) ;
F_66 ( V_22 , V_97 . V_257 . V_258 ,
V_256 -> V_259 ,
sizeof( V_22 -> V_51 -> V_97 . V_257 . V_258 ) ,
V_25 ) ;
F_66 ( V_22 , V_97 . V_257 . V_260 ,
V_256 -> V_261 , V_202 , V_25 ) ;
F_66 ( V_22 , V_97 . V_257 . V_262 ,
V_256 -> V_263 , V_202 , V_25 ) ;
V_81 &= ~ ( 1 << V_46 ) ;
}
if ( V_81 != 0 ) {
F_10 ( log , L_41 ,
( unsigned long long ) V_81 ) ;
return - V_83 ;
}
return 0 ;
}
static void F_70 ( struct V_1 * V_77 , T_4 V_264 ,
const struct V_265 * V_266 )
{
struct V_1 * V_3 ;
int V_4 ;
F_2 (nla, attr, rem) {
if ( V_266 [ F_3 ( V_3 ) ] . V_85 == V_73 ) {
if ( V_266 [ F_3 ( V_3 ) ] . V_267 )
V_266 = V_266 [ F_3 ( V_3 ) ] . V_267 ;
F_70 ( V_3 , V_264 , V_266 ) ;
} else {
memset ( F_20 ( V_3 ) , V_264 , F_19 ( V_3 ) ) ;
}
if ( F_3 ( V_3 ) == V_173 )
* ( T_6 * ) F_20 ( V_3 ) &= V_175 ;
}
}
static void F_71 ( struct V_1 * V_77 , T_4 V_264 )
{
F_70 ( V_77 , V_264 , V_84 ) ;
}
int F_72 ( struct V_157 * V_157 , struct V_21 * V_22 ,
const struct V_1 * V_268 ,
const struct V_1 * V_269 ,
bool log )
{
const struct V_1 * V_78 [ V_82 + 1 ] ;
struct V_1 * V_270 = NULL ;
T_3 V_31 = 0 ;
T_3 V_32 = 0 ;
int V_100 ;
V_100 = F_22 ( V_268 , V_78 , & V_31 , log ) ;
if ( V_100 )
return V_100 ;
V_100 = F_60 ( V_22 , & V_31 , V_78 , false , log ) ;
if ( V_100 )
return V_100 ;
V_100 = F_67 ( V_157 , V_22 , V_31 , V_78 , false , log ) ;
if ( V_100 )
return V_100 ;
if ( V_22 -> V_30 ) {
if ( ! V_269 ) {
V_270 = F_73 ( V_268 ,
F_13 ( F_19 ( V_268 ) ) ,
V_271 ) ;
if ( ! V_270 )
return - V_272 ;
F_71 ( V_270 , 0xff ) ;
if ( V_22 -> V_51 -> V_131 )
F_35 ( V_22 , V_104 ,
0xff , true ) ;
V_269 = V_270 ;
}
V_100 = F_21 ( V_269 , V_78 , & V_32 , log ) ;
if ( V_100 )
goto V_273;
F_24 ( V_22 , V_52 . V_147 . V_144 , F_8 ( 0xffff ) , true ) ;
F_24 ( V_22 , V_52 . V_148 . V_144 , F_8 ( 0xffff ) , true ) ;
V_100 = F_60 ( V_22 , & V_32 , V_78 , true , log ) ;
if ( V_100 )
goto V_273;
V_100 = F_67 ( V_157 , V_22 , V_32 , V_78 , true ,
log ) ;
if ( V_100 )
goto V_273;
}
if ( ! F_7 ( V_22 , V_31 , V_32 , log ) )
V_100 = - V_83 ;
V_273:
F_74 ( V_270 ) ;
return V_100 ;
}
static T_2 F_75 ( const struct V_1 * V_77 , bool log )
{
T_2 V_85 ;
if ( ! V_77 )
return 0 ;
V_85 = F_19 ( V_77 ) ;
if ( V_85 < 1 || V_85 > V_274 ) {
F_10 ( log , L_42 ,
F_19 ( V_77 ) , V_274 ) ;
return 0 ;
}
return V_85 ;
}
bool F_76 ( struct V_275 * V_276 , const struct V_1 * V_77 ,
bool log )
{
V_276 -> V_277 = F_75 ( V_77 , log ) ;
if ( V_276 -> V_277 )
memcpy ( V_276 -> V_278 , F_20 ( V_77 ) , V_276 -> V_277 ) ;
return V_276 -> V_277 ;
}
int F_77 ( struct V_275 * V_276 , const struct V_1 * V_278 ,
const struct V_279 * V_51 , bool log )
{
struct V_279 * V_280 ;
if ( F_76 ( V_276 , V_278 , log ) )
return 0 ;
V_280 = F_78 ( sizeof( * V_280 ) , V_271 ) ;
if ( ! V_280 )
return - V_272 ;
memcpy ( V_280 , V_51 , sizeof( * V_51 ) ) ;
V_276 -> V_281 = V_280 ;
return 0 ;
}
T_6 F_79 ( const struct V_1 * V_77 )
{
return V_77 ? F_28 ( V_77 ) : 0 ;
}
int F_80 ( struct V_157 * V_157 ,
const struct V_1 * V_78 [ V_82 + 1 ] ,
T_3 V_81 , struct V_279 * V_51 , bool log )
{
struct V_21 V_22 ;
memset ( & V_22 , 0 , sizeof( V_22 ) ) ;
V_22 . V_51 = V_51 ;
V_51 -> V_174 = 0 ;
V_51 -> V_177 = 0 ;
V_51 -> V_192 = 0 ;
memset ( & V_51 -> V_179 , 0 , sizeof( V_51 -> V_179 ) ) ;
memset ( & V_51 -> V_96 . V_186 , 0 , sizeof( V_51 -> V_96 . V_186 ) ) ;
memset ( & V_51 -> V_97 . V_186 , 0 , sizeof( V_51 -> V_97 . V_186 ) ) ;
V_51 -> V_166 . V_168 = V_169 ;
return F_63 ( V_157 , & V_22 , & V_81 , V_78 , false , log ) ;
}
static int F_81 ( struct V_134 * V_135 , const struct V_282 * V_283 ,
bool V_25 )
{
T_5 V_155 = ! V_25 ? V_283 -> V_145 : F_8 ( 0xffff ) ;
if ( F_47 ( V_135 , V_50 , V_155 ) ||
F_47 ( V_135 , V_146 , V_283 -> V_144 ) )
return - V_137 ;
return 0 ;
}
static int F_82 ( const struct V_279 * V_284 ,
const struct V_279 * V_139 , bool V_25 ,
struct V_134 * V_135 )
{
struct V_199 * V_200 ;
struct V_1 * V_3 ;
struct V_1 * V_154 = NULL ;
struct V_1 * V_285 = NULL ;
if ( F_39 ( V_135 , V_163 , V_139 -> V_164 ) )
goto V_286;
if ( F_39 ( V_135 , V_160 , V_139 -> V_162 ) )
goto V_286;
if ( F_39 ( V_135 , V_165 , V_139 -> V_166 . V_167 ) )
goto V_286;
if ( ( V_284 -> V_131 || V_25 ) ) {
const void * V_90 = NULL ;
if ( V_139 -> V_104 . V_98 & V_287 )
V_90 = F_83 ( V_139 , V_284 -> V_88 ) ;
if ( F_49 ( V_135 , & V_139 -> V_104 , V_90 ,
V_284 -> V_88 , V_284 -> V_131 ) )
goto V_286;
}
if ( V_284 -> V_166 . V_168 == V_169 ) {
if ( V_25 && ( V_139 -> V_166 . V_168 == 0xffff ) )
if ( F_39 ( V_135 , V_49 , 0xffffffff ) )
goto V_286;
} else {
T_1 V_288 ;
V_288 = ! V_25 ? 0 : 0xffff ;
if ( F_39 ( V_135 , V_49 ,
( V_288 << 16 ) | V_139 -> V_166 . V_168 ) )
goto V_286;
}
if ( F_39 ( V_135 , V_170 , V_139 -> V_166 . V_172 ) )
goto V_286;
if ( F_84 ( V_284 , V_139 , V_135 ) )
goto V_286;
if ( F_85 ( V_284 ) == V_159 ) {
V_3 = F_86 ( V_135 , V_149 , sizeof( * V_200 ) ) ;
if ( ! V_3 )
goto V_286;
V_200 = F_20 ( V_3 ) ;
F_87 ( V_200 -> V_201 , V_139 -> V_52 . V_67 ) ;
F_87 ( V_200 -> V_203 , V_139 -> V_52 . V_110 ) ;
if ( V_284 -> V_52 . V_147 . V_144 || F_56 ( V_284 -> V_52 . type ) ) {
if ( F_81 ( V_135 , & V_139 -> V_52 . V_147 , V_25 ) )
goto V_286;
V_154 = F_38 ( V_135 , V_150 ) ;
if ( ! V_284 -> V_52 . V_147 . V_144 )
goto V_289;
if ( V_284 -> V_52 . V_148 . V_144 || F_56 ( V_284 -> V_52 . type ) ) {
if ( F_81 ( V_135 , & V_139 -> V_52 . V_148 , V_25 ) )
goto V_286;
V_285 = F_38 ( V_135 , V_150 ) ;
if ( ! V_284 -> V_52 . V_148 . V_144 )
goto V_289;
}
}
if ( V_284 -> V_52 . type == F_8 ( V_204 ) ) {
if ( V_25 && V_139 -> V_52 . type )
if ( F_47 ( V_135 , V_50 ,
V_139 -> V_52 . type ) )
goto V_286;
goto V_289;
}
}
if ( F_47 ( V_135 , V_50 , V_139 -> V_52 . type ) )
goto V_286;
if ( F_56 ( V_284 -> V_52 . type ) ) {
F_88 ( ! ( V_154 && V_285 ) ) ;
goto V_289;
}
if ( V_284 -> V_52 . type == F_8 ( V_55 ) ) {
struct V_205 * V_206 ;
V_3 = F_86 ( V_135 , V_35 , sizeof( * V_206 ) ) ;
if ( ! V_3 )
goto V_286;
V_206 = F_20 ( V_3 ) ;
V_206 -> V_187 = V_139 -> V_96 . V_211 . V_67 ;
V_206 -> V_188 = V_139 -> V_96 . V_211 . V_110 ;
V_206 -> V_193 = V_139 -> V_56 . V_59 ;
V_206 -> V_209 = V_139 -> V_56 . V_114 ;
V_206 -> V_210 = V_139 -> V_56 . V_95 ;
V_206 -> V_207 = V_139 -> V_56 . V_57 ;
} else if ( V_284 -> V_52 . type == F_8 ( V_64 ) ) {
struct V_212 * V_213 ;
V_3 = F_86 ( V_135 , V_37 , sizeof( * V_213 ) ) ;
if ( ! V_3 )
goto V_286;
V_213 = F_20 ( V_3 ) ;
memcpy ( V_213 -> V_195 , & V_139 -> V_97 . V_211 . V_67 ,
sizeof( V_213 -> V_195 ) ) ;
memcpy ( V_213 -> V_196 , & V_139 -> V_97 . V_211 . V_110 ,
sizeof( V_213 -> V_196 ) ) ;
V_213 -> V_215 = V_139 -> V_97 . V_216 ;
V_213 -> V_197 = V_139 -> V_56 . V_59 ;
V_213 -> V_217 = V_139 -> V_56 . V_114 ;
V_213 -> V_218 = V_139 -> V_56 . V_95 ;
V_213 -> V_214 = V_139 -> V_56 . V_57 ;
} else if ( V_284 -> V_52 . type == F_8 ( V_53 ) ||
V_284 -> V_52 . type == F_8 ( V_54 ) ) {
struct V_219 * V_220 ;
V_3 = F_86 ( V_135 , V_45 , sizeof( * V_220 ) ) ;
if ( ! V_3 )
goto V_286;
V_220 = F_20 ( V_3 ) ;
memset ( V_220 , 0 , sizeof( struct V_219 ) ) ;
V_220 -> V_222 = V_139 -> V_96 . V_211 . V_67 ;
V_220 -> V_223 = V_139 -> V_96 . V_211 . V_110 ;
V_220 -> V_221 = F_8 ( V_139 -> V_56 . V_59 ) ;
F_87 ( V_220 -> V_226 , V_139 -> V_96 . V_224 . V_225 ) ;
F_87 ( V_220 -> V_228 , V_139 -> V_96 . V_224 . V_227 ) ;
} else if ( F_9 ( V_284 -> V_52 . type ) ) {
struct V_229 * V_230 ;
V_3 = F_86 ( V_135 , V_47 , sizeof( * V_230 ) ) ;
if ( ! V_3 )
goto V_286;
V_230 = F_20 ( V_3 ) ;
V_230 -> V_233 = V_139 -> V_231 . V_232 ;
}
if ( ( V_284 -> V_52 . type == F_8 ( V_55 ) ||
V_284 -> V_52 . type == F_8 ( V_64 ) ) &&
V_284 -> V_56 . V_57 != V_58 ) {
if ( V_284 -> V_56 . V_59 == V_62 ) {
struct V_234 * V_235 ;
V_3 = F_86 ( V_135 , V_39 , sizeof( * V_235 ) ) ;
if ( ! V_3 )
goto V_286;
V_235 = F_20 ( V_3 ) ;
V_235 -> V_236 = V_139 -> V_66 . V_67 ;
V_235 -> V_237 = V_139 -> V_66 . V_110 ;
if ( F_47 ( V_135 , V_40 ,
V_139 -> V_66 . V_238 ) )
goto V_286;
} else if ( V_284 -> V_56 . V_59 == V_60 ) {
struct V_239 * V_240 ;
V_3 = F_86 ( V_135 , V_41 , sizeof( * V_240 ) ) ;
if ( ! V_3 )
goto V_286;
V_240 = F_20 ( V_3 ) ;
V_240 -> V_241 = V_139 -> V_66 . V_67 ;
V_240 -> V_242 = V_139 -> V_66 . V_110 ;
} else if ( V_284 -> V_56 . V_59 == V_61 ) {
struct V_243 * V_244 ;
V_3 = F_86 ( V_135 , V_42 , sizeof( * V_244 ) ) ;
if ( ! V_3 )
goto V_286;
V_244 = F_20 ( V_3 ) ;
V_244 -> V_245 = V_139 -> V_66 . V_67 ;
V_244 -> V_246 = V_139 -> V_66 . V_110 ;
} else if ( V_284 -> V_52 . type == F_8 ( V_55 ) &&
V_284 -> V_56 . V_59 == V_63 ) {
struct V_247 * V_248 ;
V_3 = F_86 ( V_135 , V_43 , sizeof( * V_248 ) ) ;
if ( ! V_3 )
goto V_286;
V_248 = F_20 ( V_3 ) ;
V_248 -> V_249 = F_58 ( V_139 -> V_66 . V_67 ) ;
V_248 -> V_250 = F_58 ( V_139 -> V_66 . V_110 ) ;
} else if ( V_284 -> V_52 . type == F_8 ( V_64 ) &&
V_284 -> V_56 . V_59 == V_65 ) {
struct V_251 * V_252 ;
V_3 = F_86 ( V_135 , V_44 ,
sizeof( * V_252 ) ) ;
if ( ! V_3 )
goto V_286;
V_252 = F_20 ( V_3 ) ;
V_252 -> V_253 = F_58 ( V_139 -> V_66 . V_67 ) ;
V_252 -> V_254 = F_58 ( V_139 -> V_66 . V_110 ) ;
if ( V_252 -> V_253 == V_68 ||
V_252 -> V_253 == V_69 ) {
struct V_255 * V_256 ;
V_3 = F_86 ( V_135 , V_46 , sizeof( * V_256 ) ) ;
if ( ! V_3 )
goto V_286;
V_256 = F_20 ( V_3 ) ;
memcpy ( V_256 -> V_259 , & V_139 -> V_97 . V_257 . V_258 ,
sizeof( V_256 -> V_259 ) ) ;
F_87 ( V_256 -> V_261 , V_139 -> V_97 . V_257 . V_260 ) ;
F_87 ( V_256 -> V_263 , V_139 -> V_97 . V_257 . V_262 ) ;
}
}
}
V_289:
if ( V_285 )
F_40 ( V_135 , V_285 ) ;
if ( V_154 )
F_40 ( V_135 , V_154 ) ;
return 0 ;
V_286:
return - V_137 ;
}
int F_89 ( const struct V_279 * V_284 ,
const struct V_279 * V_139 , int V_77 , bool V_25 ,
struct V_134 * V_135 )
{
int V_100 ;
struct V_1 * V_3 ;
V_3 = F_38 ( V_135 , V_77 ) ;
if ( ! V_3 )
return - V_137 ;
V_100 = F_82 ( V_284 , V_139 , V_25 , V_135 ) ;
if ( V_100 )
return V_100 ;
F_40 ( V_135 , V_3 ) ;
return 0 ;
}
int F_90 ( const struct V_290 * V_291 , struct V_134 * V_135 )
{
if ( F_91 ( & V_291 -> V_292 ) )
return F_48 ( V_135 , V_293 , V_291 -> V_292 . V_277 ,
V_291 -> V_292 . V_278 ) ;
return F_89 ( V_291 -> V_292 . V_281 , V_291 -> V_292 . V_281 ,
V_294 , false , V_135 ) ;
}
int F_92 ( const struct V_290 * V_291 , struct V_134 * V_135 )
{
return F_89 ( & V_291 -> V_51 , & V_291 -> V_51 ,
V_294 , false , V_135 ) ;
}
int F_93 ( const struct V_290 * V_291 , struct V_134 * V_135 )
{
return F_89 ( & V_291 -> V_51 , & V_291 -> V_30 -> V_51 ,
V_295 , true , V_135 ) ;
}
static struct V_296 * F_94 ( int V_24 , bool log )
{
struct V_296 * V_297 ;
if ( V_24 > V_298 ) {
F_10 ( log , L_43 , V_24 ) ;
return F_95 ( - V_83 ) ;
}
V_297 = F_78 ( sizeof( * V_297 ) + V_24 , V_271 ) ;
if ( ! V_297 )
return F_95 ( - V_272 ) ;
V_297 -> V_299 = 0 ;
return V_297 ;
}
static void F_96 ( const struct V_1 * V_78 )
{
const struct V_1 * V_300 = F_20 ( V_78 ) ;
struct V_301 * V_302 ;
switch ( F_3 ( V_300 ) ) {
case V_70 :
V_302 = F_20 ( V_300 ) ;
F_97 ( (struct V_303 * ) V_302 -> V_304 ) ;
break;
}
}
void F_98 ( struct V_296 * V_305 )
{
const struct V_1 * V_78 ;
int V_4 ;
if ( ! V_305 )
return;
F_99 (a, sf_acts->actions, sf_acts->actions_len, rem) {
switch ( F_3 ( V_78 ) ) {
case V_19 :
F_96 ( V_78 ) ;
break;
case V_10 :
F_100 ( V_78 ) ;
break;
}
}
F_74 ( V_305 ) ;
}
static void F_101 ( struct V_306 * V_307 )
{
F_98 ( F_102 ( V_307 , struct V_296 , V_308 ) ) ;
}
void F_103 ( struct V_296 * V_305 )
{
F_104 ( & V_305 -> V_308 , F_101 ) ;
}
static struct V_1 * F_105 ( struct V_296 * * V_297 ,
int V_71 , bool log )
{
struct V_296 * V_309 ;
int V_310 ;
int V_311 = F_106 ( V_71 ) ;
int V_312 = F_107 ( struct V_296 , V_2 ) +
( * V_297 ) -> V_299 ;
if ( V_311 <= ( F_108 ( * V_297 ) - V_312 ) )
goto V_313;
V_310 = F_108 ( * V_297 ) * 2 ;
if ( V_310 > V_298 ) {
if ( ( V_298 - V_312 ) < V_311 )
return F_95 ( - V_137 ) ;
V_310 = V_298 ;
}
V_309 = F_94 ( V_310 , log ) ;
if ( F_109 ( V_309 ) )
return ( void * ) V_309 ;
memcpy ( V_309 -> V_2 , ( * V_297 ) -> V_2 , ( * V_297 ) -> V_299 ) ;
V_309 -> V_299 = ( * V_297 ) -> V_299 ;
V_309 -> V_314 = ( * V_297 ) -> V_314 ;
F_74 ( * V_297 ) ;
* V_297 = V_309 ;
V_313:
( * V_297 ) -> V_299 += V_311 ;
return (struct V_1 * ) ( ( unsigned char * ) ( * V_297 ) + V_312 ) ;
}
static struct V_1 * F_110 ( struct V_296 * * V_297 ,
int V_315 , void * V_316 , int V_85 , bool log )
{
struct V_1 * V_78 ;
V_78 = F_105 ( V_297 , F_111 ( V_85 ) , log ) ;
if ( F_109 ( V_78 ) )
return V_78 ;
V_78 -> F_3 = V_315 ;
V_78 -> F_19 = F_111 ( V_85 ) ;
if ( V_316 )
memcpy ( F_20 ( V_78 ) , V_316 , V_85 ) ;
memset ( ( unsigned char * ) V_78 + V_78 -> F_19 , 0 , F_112 ( V_85 ) ) ;
return V_78 ;
}
int F_113 ( struct V_296 * * V_297 , int V_315 , void * V_316 ,
int V_85 , bool log )
{
struct V_1 * V_78 ;
V_78 = F_110 ( V_297 , V_315 , V_316 , V_85 , log ) ;
return F_114 ( V_78 ) ;
}
static inline int F_115 ( struct V_296 * * V_297 ,
int V_315 , bool log )
{
int V_317 = ( * V_297 ) -> V_299 ;
int V_100 ;
V_100 = F_113 ( V_297 , V_315 , NULL , 0 , log ) ;
if ( V_100 )
return V_100 ;
return V_317 ;
}
static inline void F_116 ( struct V_296 * V_297 ,
int V_318 )
{
struct V_1 * V_78 = (struct V_1 * ) ( ( unsigned char * ) V_297 -> V_2 +
V_318 ) ;
V_78 -> F_19 = V_297 -> V_299 - V_318 ;
}
static int F_117 ( struct V_157 * V_157 , const struct V_1 * V_77 ,
const struct V_279 * V_51 ,
struct V_296 * * V_297 ,
T_5 V_155 , T_5 V_319 ,
bool log , bool V_320 )
{
const struct V_1 * V_81 [ V_321 + 1 ] ;
const struct V_1 * V_322 , * V_2 ;
const struct V_1 * V_78 ;
int V_4 , V_28 , V_100 ;
struct V_323 V_324 ;
memset ( V_81 , 0 , sizeof( V_81 ) ) ;
F_2 (a, attr, rem) {
int type = F_3 ( V_78 ) ;
if ( ! type || type > V_321 || V_81 [ type ] )
return - V_83 ;
V_81 [ type ] = V_78 ;
}
if ( V_4 )
return - V_83 ;
V_322 = V_81 [ V_325 ] ;
if ( ! V_322 || F_19 ( V_322 ) != sizeof( T_6 ) )
return - V_83 ;
V_2 = V_81 [ V_326 ] ;
if ( ! V_2 || ( F_19 ( V_2 ) && F_19 ( V_2 ) < V_327 ) )
return - V_83 ;
V_28 = F_115 ( V_297 , V_18 , log ) ;
if ( V_28 < 0 )
return V_28 ;
V_324 . V_328 = V_320 || ! F_1 ( V_2 ) ;
V_324 . V_322 = F_28 ( V_322 ) ;
V_100 = F_113 ( V_297 , V_329 , & V_324 , sizeof( V_324 ) ,
log ) ;
if ( V_100 )
return V_100 ;
V_100 = F_118 ( V_157 , V_2 , V_51 , V_297 ,
V_155 , V_319 , log ) ;
if ( V_100 )
return V_100 ;
F_116 ( * V_297 , V_28 ) ;
return 0 ;
}
void F_119 ( struct V_21 * V_22 ,
struct V_279 * V_51 ,
bool V_330 ,
struct V_331 * V_30 )
{
memset ( V_22 , 0 , sizeof( * V_22 ) ) ;
V_22 -> V_51 = V_51 ;
V_22 -> V_30 = V_30 ;
if ( V_330 )
memset ( V_51 , 0 , sizeof( * V_51 ) ) ;
if ( V_30 ) {
memset ( & V_30 -> V_51 , 0 , sizeof( V_30 -> V_51 ) ) ;
V_30 -> V_27 . V_28 = V_30 -> V_27 . V_29 = 0 ;
}
}
static int F_120 ( struct V_279 * V_51 )
{
struct V_332 * V_333 ;
int V_334 = V_51 -> V_88 ;
bool V_335 = false ;
V_333 = (struct V_332 * ) F_83 ( V_51 , V_51 -> V_88 ) ;
while ( V_334 > 0 ) {
int V_85 ;
if ( V_334 < sizeof( * V_333 ) )
return - V_83 ;
V_85 = sizeof( * V_333 ) + V_333 -> V_336 * 4 ;
if ( V_85 > V_334 )
return - V_83 ;
V_335 |= ! ! ( V_333 -> type & V_337 ) ;
V_333 = (struct V_332 * ) ( ( T_4 * ) V_333 + V_85 ) ;
V_334 -= V_85 ;
} ;
V_51 -> V_104 . V_98 |= V_335 ? V_338 : 0 ;
return 0 ;
}
static int F_121 ( const struct V_1 * V_77 ,
struct V_296 * * V_297 , bool log )
{
struct V_21 V_22 ;
struct V_279 V_51 ;
struct V_339 * V_304 ;
struct V_140 * V_141 ;
struct V_301 * V_302 ;
struct V_1 * V_78 ;
int V_100 = 0 , V_28 , V_99 ;
F_119 ( & V_22 , & V_51 , true , NULL ) ;
V_99 = F_29 ( F_20 ( V_77 ) , & V_22 , false , log ) ;
if ( V_99 < 0 )
return V_99 ;
if ( V_51 . V_88 ) {
switch ( V_99 ) {
case V_126 :
V_100 = F_120 ( & V_51 ) ;
if ( V_100 < 0 )
return V_100 ;
break;
case V_128 :
break;
}
} ;
V_28 = F_115 ( V_297 , V_19 , log ) ;
if ( V_28 < 0 )
return V_28 ;
V_304 = F_122 ( V_51 . V_88 , V_340 ,
V_271 ) ;
if ( ! V_304 )
return - V_272 ;
V_100 = F_123 ( & V_304 -> V_108 . V_141 . V_341 , V_271 ) ;
if ( V_100 ) {
F_97 ( (struct V_303 * ) V_304 ) ;
return V_100 ;
}
V_78 = F_110 ( V_297 , V_70 , NULL ,
sizeof( * V_302 ) , log ) ;
if ( F_109 ( V_78 ) ) {
F_97 ( (struct V_303 * ) V_304 ) ;
return F_124 ( V_78 ) ;
}
V_302 = F_20 ( V_78 ) ;
V_302 -> V_304 = V_304 ;
V_141 = & V_304 -> V_108 . V_141 ;
V_141 -> V_342 = V_343 ;
if ( V_51 . V_131 == V_132 )
V_141 -> V_342 |= V_344 ;
V_141 -> V_51 = V_51 . V_104 ;
F_125 ( V_141 ,
F_83 ( & V_51 , V_51 . V_88 ) ,
V_51 . V_88 ) ;
F_116 ( * V_297 , V_28 ) ;
return V_100 ;
}
static bool F_126 ( T_4 * V_316 , int V_85 )
{
T_4 * V_30 = V_316 + V_85 ;
while ( V_85 -- )
if ( * V_316 ++ & ~ * V_30 ++ )
return false ;
return true ;
}
static int F_127 ( const struct V_1 * V_78 ,
const struct V_279 * V_345 ,
struct V_296 * * V_297 , bool * V_346 ,
T_4 V_158 , T_5 V_155 , bool V_347 , bool log )
{
const struct V_1 * V_300 = F_20 ( V_78 ) ;
int V_348 = F_3 ( V_300 ) ;
T_2 V_349 ;
if ( F_13 ( F_19 ( V_300 ) ) != F_19 ( V_78 ) )
return - V_83 ;
V_349 = F_19 ( V_300 ) ;
if ( V_347 )
V_349 /= 2 ;
if ( V_348 > V_82 ||
! F_16 ( V_349 , V_84 [ V_348 ] . V_85 ) )
return - V_83 ;
if ( V_347 && ! F_126 ( F_20 ( V_300 ) , V_349 ) )
return - V_83 ;
switch ( V_348 ) {
const struct V_205 * V_206 ;
const struct V_212 * V_213 ;
int V_100 ;
case V_165 :
case V_170 :
case V_178 :
case V_180 :
break;
case V_149 :
if ( V_158 != V_159 )
return - V_83 ;
break;
case V_48 :
if ( V_347 )
return - V_83 ;
* V_346 = true ;
V_100 = F_121 ( V_78 , V_297 , log ) ;
if ( V_100 )
return V_100 ;
break;
case V_35 :
if ( V_155 != F_8 ( V_55 ) )
return - V_83 ;
V_206 = F_20 ( V_300 ) ;
if ( V_347 ) {
const struct V_205 * V_30 = V_206 + 1 ;
if ( V_30 -> V_193 || V_30 -> V_207 )
return - V_83 ;
} else {
if ( V_206 -> V_193 != V_345 -> V_56 . V_59 )
return - V_83 ;
if ( V_206 -> V_207 != V_345 -> V_56 . V_57 )
return - V_83 ;
}
break;
case V_37 :
if ( V_155 != F_8 ( V_64 ) )
return - V_83 ;
V_213 = F_20 ( V_300 ) ;
if ( V_347 ) {
const struct V_212 * V_30 = V_213 + 1 ;
if ( V_30 -> V_197 || V_30 -> V_214 )
return - V_83 ;
if ( F_69 ( V_30 -> V_215 ) & 0xFFF00000 )
return - V_83 ;
} else {
if ( V_213 -> V_197 != V_345 -> V_56 . V_59 )
return - V_83 ;
if ( V_213 -> V_214 != V_345 -> V_56 . V_57 )
return - V_83 ;
}
if ( F_69 ( V_213 -> V_215 ) & 0xFFF00000 )
return - V_83 ;
break;
case V_39 :
if ( ( V_155 != F_8 ( V_55 ) &&
V_155 != F_8 ( V_64 ) ) ||
V_345 -> V_56 . V_59 != V_62 )
return - V_83 ;
break;
case V_41 :
if ( ( V_155 != F_8 ( V_55 ) &&
V_155 != F_8 ( V_64 ) ) ||
V_345 -> V_56 . V_59 != V_60 )
return - V_83 ;
break;
case V_47 :
if ( ! F_9 ( V_155 ) )
return - V_83 ;
break;
case V_42 :
if ( ( V_155 != F_8 ( V_55 ) &&
V_155 != F_8 ( V_64 ) ) ||
V_345 -> V_56 . V_59 != V_61 )
return - V_83 ;
break;
default:
return - V_83 ;
}
if ( ! V_347 && V_348 != V_48 ) {
int V_28 , V_85 = V_349 * 2 ;
struct V_1 * V_350 ;
* V_346 = true ;
V_28 = F_115 ( V_297 ,
V_351 ,
log ) ;
if ( V_28 < 0 )
return V_28 ;
V_350 = F_110 ( V_297 , V_348 , NULL , V_85 , log ) ;
if ( F_109 ( V_350 ) )
return F_124 ( V_350 ) ;
memcpy ( F_20 ( V_350 ) , F_20 ( V_300 ) , V_349 ) ;
memset ( F_20 ( V_350 ) + V_349 , 0xff , V_349 ) ;
if ( V_348 == V_37 ) {
struct V_212 * V_30 = F_20 ( V_350 ) + V_349 ;
V_30 -> V_215 &= F_68 ( 0x000FFFFF ) ;
}
F_116 ( * V_297 , V_28 ) ;
}
return 0 ;
}
static int F_128 ( const struct V_1 * V_77 )
{
static const struct V_352 V_353 [ V_354 + 1 ] = {
[ V_355 ] = { . type = V_356 } ,
[ V_357 ] = { . type = V_358 } ,
[ V_359 ] = { . type = V_356 } ,
} ;
struct V_1 * V_78 [ V_354 + 1 ] ;
int error ;
error = F_129 ( V_78 , V_354 , V_77 ,
V_353 , NULL ) ;
if ( error )
return error ;
if ( ! V_78 [ V_355 ] ||
! F_28 ( V_78 [ V_355 ] ) )
return - V_83 ;
return 0 ;
}
static int F_130 ( const struct V_1 * V_360 ,
struct V_296 * * V_297 , bool log )
{
int V_361 = F_106 ( V_360 -> F_19 ) ;
struct V_1 * V_362 ;
V_362 = F_105 ( V_297 , V_360 -> F_19 , log ) ;
if ( F_109 ( V_362 ) )
return F_124 ( V_362 ) ;
memcpy ( V_362 , V_360 , V_361 ) ;
return 0 ;
}
static int F_118 ( struct V_157 * V_157 , const struct V_1 * V_77 ,
const struct V_279 * V_51 ,
struct V_296 * * V_297 ,
T_5 V_155 , T_5 V_319 , bool log )
{
T_4 V_158 = F_85 ( V_51 ) ;
const struct V_1 * V_78 ;
int V_4 , V_100 ;
F_2 (a, attr, rem) {
static const T_6 V_363 [ V_364 + 1 ] = {
[ V_6 ] = sizeof( T_6 ) ,
[ V_7 ] = sizeof( T_6 ) ,
[ V_9 ] = ( T_6 ) - 1 ,
[ V_16 ] = sizeof( struct V_365 ) ,
[ V_13 ] = sizeof( T_5 ) ,
[ V_17 ] = sizeof( struct V_366 ) ,
[ V_14 ] = 0 ,
[ V_19 ] = ( T_6 ) - 1 ,
[ V_20 ] = ( T_6 ) - 1 ,
[ V_18 ] = ( T_6 ) - 1 ,
[ V_11 ] = sizeof( struct V_367 ) ,
[ V_10 ] = ( T_6 ) - 1 ,
[ V_8 ] = sizeof( struct V_368 ) ,
[ V_15 ] = sizeof( struct V_369 ) ,
[ V_12 ] = 0 ,
} ;
const struct V_366 * V_147 ;
int type = F_3 ( V_78 ) ;
bool V_346 ;
if ( type > V_364 ||
( V_363 [ type ] != F_19 ( V_78 ) &&
V_363 [ type ] != ( T_6 ) - 1 ) )
return - V_83 ;
V_346 = false ;
switch ( type ) {
case V_370 :
return - V_83 ;
case V_9 :
V_100 = F_128 ( V_78 ) ;
if ( V_100 )
return V_100 ;
break;
case V_6 :
if ( F_28 ( V_78 ) >= V_169 )
return - V_83 ;
break;
case V_8 : {
const struct V_368 * V_371 = F_20 ( V_78 ) ;
if ( V_371 -> V_372 < V_373 )
return - V_83 ;
break;
}
case V_11 : {
const struct V_367 * V_374 = F_20 ( V_78 ) ;
switch ( V_374 -> V_375 ) {
case V_376 :
break;
default:
return - V_83 ;
}
break;
}
case V_14 :
if ( V_158 != V_159 )
return - V_83 ;
V_319 = F_8 ( 0 ) ;
break;
case V_17 :
if ( V_158 != V_159 )
return - V_83 ;
V_147 = F_20 ( V_78 ) ;
if ( ! F_56 ( V_147 -> V_377 ) )
return - V_83 ;
if ( ! ( V_147 -> V_319 & F_8 ( V_151 ) ) )
return - V_83 ;
V_319 = V_147 -> V_319 ;
break;
case V_7 :
break;
case V_16 : {
const struct V_365 * V_231 = F_20 ( V_78 ) ;
if ( ! F_9 ( V_231 -> V_378 ) )
return - V_83 ;
if ( V_319 & F_8 ( V_151 ) ||
( V_155 != F_8 ( V_55 ) &&
V_155 != F_8 ( V_64 ) &&
V_155 != F_8 ( V_53 ) &&
V_155 != F_8 ( V_54 ) &&
! F_9 ( V_155 ) ) )
return - V_83 ;
V_155 = V_231 -> V_378 ;
break;
}
case V_13 :
if ( V_319 & F_8 ( V_151 ) ||
! F_9 ( V_155 ) )
return - V_83 ;
V_155 = F_8 ( 0 ) ;
break;
case V_19 :
V_100 = F_127 ( V_78 , V_51 , V_297 ,
& V_346 , V_158 , V_155 ,
false , log ) ;
if ( V_100 )
return V_100 ;
break;
case V_20 :
V_100 = F_127 ( V_78 , V_51 , V_297 ,
& V_346 , V_158 , V_155 ,
true , log ) ;
if ( V_100 )
return V_100 ;
break;
case V_18 : {
bool V_320 = F_131 ( V_78 , V_4 ) ;
V_100 = F_117 ( V_157 , V_78 , V_51 , V_297 ,
V_155 , V_319 ,
log , V_320 ) ;
if ( V_100 )
return V_100 ;
V_346 = true ;
break;
}
case V_10 :
V_100 = F_132 ( V_157 , V_78 , V_51 , V_297 , log ) ;
if ( V_100 )
return V_100 ;
V_346 = true ;
break;
case V_15 :
if ( V_158 != V_198 )
return - V_83 ;
V_158 = V_198 ;
break;
case V_12 :
if ( V_158 != V_159 )
return - V_83 ;
if ( V_319 & F_8 ( V_151 ) )
return - V_83 ;
V_158 = V_159 ;
break;
default:
F_10 ( log , L_44 , type ) ;
return - V_83 ;
}
if ( ! V_346 ) {
V_100 = F_130 ( V_78 , V_297 , log ) ;
if ( V_100 )
return V_100 ;
}
}
if ( V_4 > 0 )
return - V_83 ;
return 0 ;
}
int F_133 ( struct V_157 * V_157 , const struct V_1 * V_77 ,
const struct V_279 * V_51 ,
struct V_296 * * V_297 , bool log )
{
int V_100 ;
* V_297 = F_94 ( F_19 ( V_77 ) , log ) ;
if ( F_109 ( * V_297 ) )
return F_124 ( * V_297 ) ;
( * V_297 ) -> V_314 = F_19 ( V_77 ) ;
V_100 = F_118 ( V_157 , V_77 , V_51 , V_297 , V_51 -> V_52 . type ,
V_51 -> V_52 . V_147 . V_144 , log ) ;
if ( V_100 )
F_98 ( * V_297 ) ;
return V_100 ;
}
static int F_134 ( const struct V_1 * V_77 ,
struct V_134 * V_135 )
{
struct V_1 * V_28 , * V_379 = NULL , * V_323 ;
int V_100 = 0 , V_4 = F_19 ( V_77 ) ;
const struct V_323 * V_324 ;
struct V_1 * V_2 ;
V_28 = F_38 ( V_135 , V_18 ) ;
if ( ! V_28 )
return - V_137 ;
V_323 = F_20 ( V_77 ) ;
V_324 = F_20 ( V_323 ) ;
V_2 = F_135 ( V_323 , & V_4 ) ;
if ( F_39 ( V_135 , V_325 , V_324 -> V_322 ) ) {
V_100 = - V_137 ;
goto V_313;
}
V_379 = F_38 ( V_135 , V_326 ) ;
if ( ! V_379 ) {
V_100 = - V_137 ;
goto V_313;
}
V_100 = F_136 ( V_2 , V_4 , V_135 ) ;
V_313:
if ( V_100 ) {
F_137 ( V_135 , V_379 ) ;
F_137 ( V_135 , V_28 ) ;
} else {
F_40 ( V_135 , V_379 ) ;
F_40 ( V_135 , V_28 ) ;
}
return V_100 ;
}
static int F_138 ( const struct V_1 * V_78 , struct V_134 * V_135 )
{
const struct V_1 * V_300 = F_20 ( V_78 ) ;
int V_348 = F_3 ( V_300 ) ;
struct V_1 * V_28 ;
int V_100 ;
switch ( V_348 ) {
case V_70 : {
struct V_301 * V_302 = F_20 ( V_300 ) ;
struct V_140 * V_141 = & V_302 -> V_304 -> V_108 . V_141 ;
V_28 = F_38 ( V_135 , V_19 ) ;
if ( ! V_28 )
return - V_137 ;
V_100 = F_49 ( V_135 , & V_141 -> V_51 ,
F_51 ( V_141 ) ,
V_141 -> V_142 ,
F_52 ( V_141 ) ) ;
if ( V_100 )
return V_100 ;
F_40 ( V_135 , V_28 ) ;
break;
}
default:
if ( F_48 ( V_135 , V_19 , F_19 ( V_78 ) , V_300 ) )
return - V_137 ;
break;
}
return 0 ;
}
static int F_139 ( const struct V_1 * V_78 ,
struct V_134 * V_135 )
{
const struct V_1 * V_300 = F_20 ( V_78 ) ;
struct V_1 * V_3 ;
T_2 V_349 = F_19 ( V_300 ) / 2 ;
V_3 = F_38 ( V_135 , V_19 ) ;
if ( ! V_3 )
return - V_137 ;
if ( F_48 ( V_135 , F_3 ( V_300 ) , V_349 , F_20 ( V_300 ) ) )
return - V_137 ;
F_40 ( V_135 , V_3 ) ;
return 0 ;
}
int F_136 ( const struct V_1 * V_77 , int V_85 , struct V_134 * V_135 )
{
const struct V_1 * V_78 ;
int V_4 , V_100 ;
F_99 (a, attr, len, rem) {
int type = F_3 ( V_78 ) ;
switch ( type ) {
case V_19 :
V_100 = F_138 ( V_78 , V_135 ) ;
if ( V_100 )
return V_100 ;
break;
case V_351 :
V_100 = F_139 ( V_78 , V_135 ) ;
if ( V_100 )
return V_100 ;
break;
case V_18 :
V_100 = F_134 ( V_78 , V_135 ) ;
if ( V_100 )
return V_100 ;
break;
case V_10 :
V_100 = F_140 ( F_20 ( V_78 ) , V_135 ) ;
if ( V_100 )
return V_100 ;
break;
default:
if ( F_48 ( V_135 , type , F_19 ( V_78 ) , F_20 ( V_78 ) ) )
return - V_137 ;
break;
}
}
return 0 ;
}
