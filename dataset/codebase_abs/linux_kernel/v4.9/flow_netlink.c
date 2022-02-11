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
+ F_10 ( 16 )
+ F_10 ( 16 )
+ F_10 ( 1 )
+ F_10 ( 1 )
+ F_10 ( 0 )
+ F_10 ( 0 )
+ F_10 ( 0 )
+ F_10 ( 256 )
+ F_10 ( 2 )
+ F_10 ( 2 ) ;
}
T_1 F_11 ( void )
{
F_12 ( V_49 != 26 ) ;
return F_10 ( 4 )
+ F_10 ( 0 )
+ F_8 ()
+ F_10 ( 4 )
+ F_10 ( 4 )
+ F_10 ( 4 )
+ F_10 ( 4 )
+ F_10 ( 4 )
+ F_10 ( 2 )
+ F_10 ( 4 )
+ F_10 ( 16 )
+ F_10 ( 12 )
+ F_10 ( 2 )
+ F_10 ( 4 )
+ F_10 ( 0 )
+ F_10 ( 2 )
+ F_10 ( 40 )
+ F_10 ( 2 )
+ F_10 ( 28 ) ;
}
static bool F_13 ( unsigned int V_50 , unsigned int V_51 )
{
return V_51 == V_50 ||
V_51 == V_52 ||
V_51 == V_53 ;
}
static bool F_14 ( const T_3 * V_54 , T_1 V_4 )
{
int V_55 ;
if ( ! V_54 )
return false ;
for ( V_55 = 0 ; V_55 < V_4 ; V_55 ++ )
if ( V_54 [ V_55 ] )
return false ;
return true ;
}
static int F_15 ( const struct V_56 * V_57 ,
const struct V_56 * V_58 [] ,
T_2 * V_59 , bool log , bool V_60 )
{
const struct V_56 * V_61 ;
T_2 V_62 ;
int V_63 ;
V_62 = * V_59 ;
F_16 (nla, attr, rem) {
T_4 type = F_17 ( V_61 ) ;
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
if ( ! F_13 ( F_18 ( V_61 ) , V_51 ) ) {
F_7 ( log , L_5 ,
type , F_18 ( V_61 ) , V_51 ) ;
return - V_65 ;
}
if ( ! V_60 || ! F_14 ( F_19 ( V_61 ) , V_51 ) ) {
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
static int F_20 ( const struct V_56 * V_57 ,
const struct V_56 * V_58 [] , T_2 * V_59 ,
bool log )
{
return F_15 ( V_57 , V_58 , V_59 , log , true ) ;
}
static int F_21 ( const struct V_56 * V_57 ,
const struct V_56 * V_58 [] , T_2 * V_59 ,
bool log )
{
return F_15 ( V_57 , V_58 , V_59 , log , false ) ;
}
static int F_22 ( const struct V_56 * V_58 ,
struct V_1 * V_2 , bool V_5 ,
bool log )
{
unsigned long V_68 ;
if ( F_18 ( V_58 ) > sizeof( V_2 -> V_30 -> V_69 ) ) {
F_7 ( log , L_7 ,
F_18 ( V_58 ) , sizeof( V_2 -> V_30 -> V_69 ) ) ;
return - V_65 ;
}
if ( F_18 ( V_58 ) % 4 != 0 ) {
F_7 ( log , L_8 ,
F_18 ( V_58 ) ) ;
return - V_65 ;
}
if ( ! V_5 ) {
F_23 ( V_2 , V_70 , F_18 ( V_58 ) ,
false ) ;
} else {
if ( V_2 -> V_30 -> V_70 != F_18 ( V_58 ) ) {
F_7 ( log , L_9 ,
V_2 -> V_30 -> V_70 , F_18 ( V_58 ) ) ;
return - V_65 ;
}
F_23 ( V_2 , V_70 , 0xff , true ) ;
}
V_68 = F_24 ( F_18 ( V_58 ) ) ;
F_25 ( V_2 , V_68 , F_19 ( V_58 ) ,
F_18 ( V_58 ) , V_5 ) ;
return 0 ;
}
static int F_26 ( const struct V_56 * V_57 ,
struct V_1 * V_2 , bool V_5 ,
bool log )
{
struct V_56 * V_58 ;
int V_63 ;
unsigned long V_68 ;
struct V_71 V_72 ;
F_12 ( sizeof( V_72 ) > sizeof( V_2 -> V_30 -> V_69 ) ) ;
memset ( & V_72 , 0 , sizeof( V_72 ) ) ;
F_16 (a, attr, rem) {
int type = F_17 ( V_58 ) ;
if ( type > V_73 ) {
F_7 ( log , L_10 ,
type , V_73 ) ;
return - V_65 ;
}
if ( ! F_13 ( F_18 ( V_58 ) ,
V_74 [ type ] . V_67 ) ) {
F_7 ( log , L_11 ,
type , F_18 ( V_58 ) ,
V_74 [ type ] . V_67 ) ;
return - V_65 ;
}
switch ( type ) {
case V_75 :
V_72 . V_76 = F_27 ( V_58 ) ;
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
F_23 ( V_2 , V_70 , sizeof( V_72 ) , false ) ;
else
F_23 ( V_2 , V_70 , 0xff , true ) ;
V_68 = F_24 ( sizeof( V_72 ) ) ;
F_25 ( V_2 , V_68 , & V_72 , sizeof( V_72 ) ,
V_5 ) ;
return 0 ;
}
static int F_28 ( const struct V_56 * V_57 ,
struct V_1 * V_2 , bool V_5 ,
bool log )
{
bool V_77 = false , V_78 = false , V_79 = false ;
T_5 V_80 = 0 ;
int V_81 = 0 ;
struct V_56 * V_58 ;
int V_63 ;
F_16 (a, attr, rem) {
int type = F_17 ( V_58 ) ;
int V_82 ;
if ( type > V_83 ) {
F_7 ( log , L_14 ,
type , V_83 ) ;
return - V_65 ;
}
if ( ! F_13 ( F_18 ( V_58 ) ,
V_84 [ type ] . V_67 ) ) {
F_7 ( log , L_15 ,
type , F_18 ( V_58 ) , V_84 [ type ] . V_67 ) ;
return - V_65 ;
}
switch ( type ) {
case V_85 :
F_23 ( V_2 , V_86 . V_87 ,
F_29 ( V_58 ) , V_5 ) ;
V_80 |= V_88 ;
break;
case V_89 :
F_23 ( V_2 , V_86 . V_90 . V_78 . V_46 ,
F_30 ( V_58 ) , V_5 ) ;
V_78 = true ;
break;
case V_91 :
F_23 ( V_2 , V_86 . V_90 . V_78 . V_92 ,
F_30 ( V_58 ) , V_5 ) ;
V_78 = true ;
break;
case V_93 :
F_23 ( V_2 , V_86 . V_90 . V_79 . V_92 ,
F_31 ( V_58 ) , V_5 ) ;
V_79 = true ;
break;
case V_94 :
F_23 ( V_2 , V_86 . V_90 . V_79 . V_92 ,
F_31 ( V_58 ) , V_5 ) ;
V_79 = true ;
break;
case V_95 :
F_23 ( V_2 , V_86 . V_96 ,
F_32 ( V_58 ) , V_5 ) ;
break;
case V_97 :
F_23 ( V_2 , V_86 . V_77 ,
F_32 ( V_58 ) , V_5 ) ;
V_77 = true ;
break;
case V_98 :
V_80 |= V_99 ;
break;
case V_100 :
V_80 |= V_101 ;
break;
case V_102 :
F_23 ( V_2 , V_86 . V_103 ,
F_33 ( V_58 ) , V_5 ) ;
break;
case V_104 :
F_23 ( V_2 , V_86 . V_105 ,
F_33 ( V_58 ) , V_5 ) ;
break;
case V_106 :
V_80 |= V_107 ;
break;
case V_108 :
if ( V_81 ) {
F_7 ( log , L_16 ) ;
return - V_65 ;
}
V_82 = F_22 ( V_58 , V_2 , V_5 , log ) ;
if ( V_82 )
return V_82 ;
V_80 |= V_109 ;
V_81 = type ;
break;
case V_110 :
if ( V_81 ) {
F_7 ( log , L_16 ) ;
return - V_65 ;
}
V_82 = F_26 ( V_58 , V_2 , V_5 , log ) ;
if ( V_82 )
return V_82 ;
V_80 |= V_111 ;
V_81 = type ;
break;
default:
F_7 ( log , L_17 ,
type ) ;
return - V_65 ;
}
}
F_23 ( V_2 , V_86 . V_80 , V_80 , V_5 ) ;
if ( V_5 )
F_34 ( V_2 , V_112 , 0xff , true ) ;
else
F_23 ( V_2 , V_112 , V_79 ? V_113 : V_114 ,
false ) ;
if ( V_63 > 0 ) {
F_7 ( log , L_18 ,
V_63 ) ;
return - V_65 ;
}
if ( V_78 && V_79 ) {
F_7 ( log , L_19 ) ;
return - V_65 ;
}
if ( ! V_5 ) {
if ( ! V_78 && ! V_79 ) {
F_7 ( log , L_20 ) ;
return - V_65 ;
}
if ( V_78 && ! V_2 -> V_30 -> V_86 . V_90 . V_78 . V_92 ) {
F_7 ( log , L_21 ) ;
return - V_65 ;
}
if ( V_79 && F_35 ( & V_2 -> V_30 -> V_86 . V_90 . V_79 . V_92 ) ) {
F_7 ( log , L_22 ) ;
return - V_65 ;
}
if ( ! V_77 ) {
F_7 ( log , L_23 ) ;
return - V_65 ;
}
}
return V_81 ;
}
static int F_36 ( struct V_115 * V_116 ,
const void * V_69 , int V_117 )
{
const struct V_71 * V_72 = V_69 ;
struct V_56 * V_61 ;
V_61 = F_37 ( V_116 , V_110 ) ;
if ( ! V_61 )
return - V_118 ;
if ( F_38 ( V_116 , V_75 , V_72 -> V_76 ) < 0 )
return - V_118 ;
F_39 ( V_116 , V_61 ) ;
return 0 ;
}
static int F_40 ( struct V_115 * V_116 ,
const struct V_119 * V_120 ,
const void * V_69 , int V_117 ,
unsigned short V_112 )
{
if ( V_120 -> V_80 & V_88 &&
F_41 ( V_116 , V_85 , V_120 -> V_87 ,
V_121 ) )
return - V_118 ;
switch ( V_112 ) {
case V_114 :
if ( V_120 -> V_90 . V_78 . V_46 &&
F_42 ( V_116 , V_89 ,
V_120 -> V_90 . V_78 . V_46 ) )
return - V_118 ;
if ( V_120 -> V_90 . V_78 . V_92 &&
F_42 ( V_116 , V_91 ,
V_120 -> V_90 . V_78 . V_92 ) )
return - V_118 ;
break;
case V_113 :
if ( ! F_35 ( & V_120 -> V_90 . V_79 . V_46 ) &&
F_43 ( V_116 , V_93 ,
& V_120 -> V_90 . V_79 . V_46 ) )
return - V_118 ;
if ( ! F_35 ( & V_120 -> V_90 . V_79 . V_92 ) &&
F_43 ( V_116 , V_94 ,
& V_120 -> V_90 . V_79 . V_92 ) )
return - V_118 ;
break;
}
if ( V_120 -> V_96 &&
F_44 ( V_116 , V_95 , V_120 -> V_96 ) )
return - V_118 ;
if ( F_44 ( V_116 , V_97 , V_120 -> V_77 ) )
return - V_118 ;
if ( ( V_120 -> V_80 & V_99 ) &&
F_45 ( V_116 , V_98 ) )
return - V_118 ;
if ( ( V_120 -> V_80 & V_101 ) &&
F_45 ( V_116 , V_100 ) )
return - V_118 ;
if ( V_120 -> V_103 &&
F_46 ( V_116 , V_102 , V_120 -> V_103 ) )
return - V_118 ;
if ( V_120 -> V_105 &&
F_46 ( V_116 , V_104 , V_120 -> V_105 ) )
return - V_118 ;
if ( ( V_120 -> V_80 & V_107 ) &&
F_45 ( V_116 , V_106 ) )
return - V_118 ;
if ( V_117 ) {
if ( V_120 -> V_80 & V_109 &&
F_47 ( V_116 , V_108 ,
V_117 , V_69 ) )
return - V_118 ;
else if ( V_120 -> V_80 & V_111 &&
F_36 ( V_116 , V_69 , V_117 ) )
return - V_118 ;
}
return 0 ;
}
static int F_48 ( struct V_115 * V_116 ,
const struct V_119 * V_120 ,
const void * V_69 , int V_117 ,
unsigned short V_112 )
{
struct V_56 * V_61 ;
int V_82 ;
V_61 = F_37 ( V_116 , V_27 ) ;
if ( ! V_61 )
return - V_118 ;
V_82 = F_40 ( V_116 , V_120 , V_69 , V_117 ,
V_112 ) ;
if ( V_82 )
return V_82 ;
F_39 ( V_116 , V_61 ) ;
return 0 ;
}
int F_49 ( struct V_115 * V_116 ,
struct V_122 * V_123 )
{
return F_40 ( V_116 , & V_123 -> V_30 ,
F_50 ( V_123 ) ,
V_123 -> V_124 ,
F_51 ( V_123 ) ) ;
}
static int F_52 ( struct V_1 * V_2 ,
const struct V_56 * V_58 [] ,
bool V_5 , bool V_125 )
{
T_5 V_126 = 0 ;
T_5 V_127 = 0 ;
if ( V_58 [ V_128 ] )
V_126 = F_33 ( V_58 [ V_128 ] ) ;
if ( V_58 [ V_29 ] )
V_127 = F_33 ( V_58 [ V_29 ] ) ;
if ( F_53 ( ! V_125 ) ) {
F_23 ( V_2 , V_31 . V_129 . V_127 , V_127 , V_5 ) ;
F_23 ( V_2 , V_31 . V_129 . V_126 , V_126 , V_5 ) ;
} else {
F_23 ( V_2 , V_31 . V_130 . V_127 , V_127 , V_5 ) ;
F_23 ( V_2 , V_31 . V_130 . V_126 , V_126 , V_5 ) ;
}
return 0 ;
}
static int F_54 ( const struct V_1 * V_2 ,
T_2 V_11 , bool V_125 ,
const struct V_56 * * V_58 , bool log )
{
T_5 V_126 = 0 ;
if ( ! ( ( V_11 & ( 1 << V_14 ) ) &&
( V_11 & ( 1 << V_29 ) ) &&
F_55 ( F_33 ( V_58 [ V_29 ] ) ) ) ) {
return 0 ;
}
if ( ! ( ( V_11 & ( 1 << V_128 ) ) &&
( V_11 & ( 1 << V_131 ) ) ) ) {
F_7 ( log , L_24 , ( V_125 ) ? L_25 : L_26 ) ;
return - V_65 ;
}
if ( V_58 [ V_128 ] )
V_126 = F_33 ( V_58 [ V_128 ] ) ;
if ( ! ( V_126 & F_5 ( V_132 ) ) ) {
if ( V_126 ) {
F_7 ( log , L_27 ,
( V_125 ) ? L_25 : L_26 ) ;
return - V_65 ;
} else if ( F_18 ( V_58 [ V_131 ] ) ) {
F_7 ( log , L_28 ,
( V_125 ) ? L_25 : L_26 ) ;
return - V_65 ;
}
}
return 1 ;
}
static int F_56 ( const struct V_1 * V_2 ,
T_2 V_11 , bool V_125 ,
const struct V_56 * * V_58 , bool log )
{
T_5 V_126 = 0 ;
T_5 V_127 = 0 ;
bool V_133 = ! ! ( V_2 -> V_30 -> V_31 . V_129 . V_126 &
F_5 ( V_132 ) ) ;
bool V_134 = ! ! ( V_2 -> V_30 -> V_31 . V_130 . V_126 &
F_5 ( V_132 ) ) ;
if ( ! ( V_11 & ( 1 << V_131 ) ) ) {
return 0 ;
}
if ( ( ! V_125 && ! V_133 ) || ( V_125 && ! V_134 ) ) {
F_7 ( log , L_29 ,
( V_125 ) ? L_25 : L_26 ) ;
return - V_65 ;
}
if ( V_58 [ V_128 ] )
V_126 = F_33 ( V_58 [ V_128 ] ) ;
if ( V_58 [ V_29 ] )
V_127 = F_33 ( V_58 [ V_29 ] ) ;
if ( V_127 != F_5 ( 0xffff ) ) {
F_7 ( log , L_30 ,
( V_125 ) ? L_25 : L_26 , F_57 ( V_127 ) ) ;
return - V_65 ;
}
if ( ! ( V_126 & F_5 ( V_132 ) ) ) {
F_7 ( log , L_31 ,
( V_125 ) ? L_25 : L_26 ) ;
return - V_65 ;
}
return 1 ;
}
static int F_58 ( struct V_1 * V_2 ,
T_2 * V_11 , bool V_125 ,
const struct V_56 * * V_58 , bool V_5 ,
bool log )
{
int V_82 ;
const struct V_56 * V_135 ;
if ( ! V_5 )
V_82 = F_54 ( V_2 , * V_11 , V_125 ,
V_58 , log ) ;
else
V_82 = F_56 ( V_2 , * V_11 , V_125 ,
V_58 , log ) ;
if ( V_82 <= 0 )
return V_82 ;
V_82 = F_52 ( V_2 , V_58 , V_5 , V_125 ) ;
if ( V_82 )
return V_82 ;
* V_11 &= ~ ( 1 << V_131 ) ;
* V_11 &= ~ ( 1 << V_128 ) ;
* V_11 &= ~ ( 1 << V_29 ) ;
V_135 = V_58 [ V_131 ] ;
if ( ! V_5 )
V_82 = F_21 ( V_135 , V_58 , V_11 , log ) ;
else
V_82 = F_20 ( V_135 , V_58 , V_11 , log ) ;
return V_82 ;
}
static int F_59 ( struct V_1 * V_2 ,
T_2 * V_11 , const struct V_56 * * V_58 ,
bool V_5 , bool log )
{
int V_82 ;
bool V_133 = false ;
V_82 = F_58 ( V_2 , V_11 , false , V_58 ,
V_5 , log ) ;
if ( V_82 )
return V_82 ;
V_133 = ! ! ( V_2 -> V_30 -> V_31 . V_129 . V_126 & F_5 ( V_132 ) ) ;
if ( V_133 ) {
V_82 = F_58 ( V_2 , V_11 , true , V_58 ,
V_5 , log ) ;
if ( V_82 )
return V_82 ;
}
return 0 ;
}
static int F_60 ( struct V_136 * V_136 , struct V_1 * V_2 ,
T_2 * V_62 , const struct V_56 * * V_58 ,
bool V_5 , bool log )
{
if ( * V_62 & ( 1 << V_137 ) ) {
T_6 V_138 = F_27 ( V_58 [ V_137 ] ) ;
F_23 ( V_2 , V_139 , V_138 , V_5 ) ;
* V_62 &= ~ ( 1 << V_137 ) ;
}
if ( * V_62 & ( 1 << V_140 ) ) {
T_6 V_141 = F_27 ( V_58 [ V_140 ] ) ;
F_23 ( V_2 , V_141 , V_141 , V_5 ) ;
* V_62 &= ~ ( 1 << V_140 ) ;
}
if ( * V_62 & ( 1 << V_142 ) ) {
F_23 ( V_2 , V_143 . V_144 ,
F_27 ( V_58 [ V_142 ] ) , V_5 ) ;
* V_62 &= ~ ( 1 << V_142 ) ;
}
if ( * V_62 & ( 1 << V_28 ) ) {
T_6 V_145 = F_27 ( V_58 [ V_28 ] ) ;
if ( V_5 ) {
V_145 = 0xffffffff ;
} else if ( V_145 >= V_146 ) {
F_7 ( log , L_32 ,
V_145 , V_146 ) ;
return - V_65 ;
}
F_23 ( V_2 , V_143 . V_145 , V_145 , V_5 ) ;
* V_62 &= ~ ( 1 << V_28 ) ;
} else if ( ! V_5 ) {
F_23 ( V_2 , V_143 . V_145 , V_146 , V_5 ) ;
}
if ( * V_62 & ( 1 << V_147 ) ) {
T_7 V_148 = F_27 ( V_58 [ V_147 ] ) ;
F_23 ( V_2 , V_143 . V_149 , V_148 , V_5 ) ;
* V_62 &= ~ ( 1 << V_147 ) ;
}
if ( * V_62 & ( 1 << V_27 ) ) {
if ( F_28 ( V_58 [ V_27 ] , V_2 ,
V_5 , log ) < 0 )
return - V_65 ;
* V_62 &= ~ ( 1 << V_27 ) ;
}
if ( * V_62 & ( 1 << V_150 ) &&
F_61 ( V_136 , V_150 ) ) {
T_6 V_151 = F_27 ( V_58 [ V_150 ] ) ;
if ( V_151 & ~ V_152 ) {
F_7 ( log , L_33 ,
V_151 ) ;
return - V_65 ;
}
F_23 ( V_2 , V_153 . V_154 , V_151 , V_5 ) ;
* V_62 &= ~ ( 1ULL << V_150 ) ;
}
if ( * V_62 & ( 1 << V_155 ) &&
F_61 ( V_136 , V_155 ) ) {
T_4 V_156 = F_62 ( V_58 [ V_155 ] ) ;
F_23 ( V_2 , V_153 . V_157 , V_156 , V_5 ) ;
* V_62 &= ~ ( 1ULL << V_155 ) ;
}
if ( * V_62 & ( 1 << V_158 ) &&
F_61 ( V_136 , V_158 ) ) {
T_6 V_148 = F_27 ( V_58 [ V_158 ] ) ;
F_23 ( V_2 , V_153 . V_148 , V_148 , V_5 ) ;
* V_62 &= ~ ( 1ULL << V_158 ) ;
}
if ( * V_62 & ( 1 << V_159 ) &&
F_61 ( V_136 , V_159 ) ) {
const struct V_160 * V_161 ;
V_161 = F_19 ( V_58 [ V_159 ] ) ;
F_63 ( V_2 , V_153 . V_162 , V_161 -> V_163 ,
sizeof( * V_161 ) , V_5 ) ;
* V_62 &= ~ ( 1ULL << V_159 ) ;
}
return 0 ;
}
static int F_64 ( struct V_136 * V_136 , struct V_1 * V_2 ,
T_2 V_62 , const struct V_56 * * V_58 ,
bool V_5 , bool log )
{
int V_82 ;
V_82 = F_60 ( V_136 , V_2 , & V_62 , V_58 , V_5 , log ) ;
if ( V_82 )
return V_82 ;
if ( V_62 & ( 1 << V_14 ) ) {
const struct V_164 * V_165 ;
V_165 = F_19 ( V_58 [ V_14 ] ) ;
F_63 ( V_2 , V_31 . V_46 ,
V_165 -> V_166 , V_167 , V_5 ) ;
F_63 ( V_2 , V_31 . V_92 ,
V_165 -> V_168 , V_167 , V_5 ) ;
V_62 &= ~ ( 1 << V_14 ) ;
}
if ( V_62 & ( 1 << V_128 ) ) {
F_7 ( log , L_34 ) ;
return - V_65 ;
}
if ( V_62 & ( 1 << V_29 ) ) {
T_5 V_169 ;
V_169 = F_33 ( V_58 [ V_29 ] ) ;
if ( V_5 ) {
V_169 = F_5 ( 0xffff ) ;
} else if ( ! F_65 ( V_169 ) ) {
F_7 ( log , L_35 ,
F_57 ( V_169 ) , V_170 ) ;
return - V_65 ;
}
F_23 ( V_2 , V_31 . type , V_169 , V_5 ) ;
V_62 &= ~ ( 1 << V_29 ) ;
} else if ( ! V_5 ) {
F_23 ( V_2 , V_31 . type , F_5 ( V_171 ) , V_5 ) ;
}
if ( V_62 & ( 1 << V_16 ) ) {
const struct V_172 * V_173 ;
V_173 = F_19 ( V_58 [ V_16 ] ) ;
if ( ! V_5 && V_173 -> V_174 > V_175 ) {
F_7 ( log , L_36 ,
V_173 -> V_174 , V_175 ) ;
return - V_65 ;
}
F_23 ( V_2 , V_35 . V_38 ,
V_173 -> V_176 , V_5 ) ;
F_23 ( V_2 , V_35 . V_96 ,
V_173 -> V_177 , V_5 ) ;
F_23 ( V_2 , V_35 . V_77 ,
V_173 -> V_178 , V_5 ) ;
F_23 ( V_2 , V_35 . V_36 ,
V_173 -> V_174 , V_5 ) ;
F_23 ( V_2 , V_78 . V_179 . V_46 ,
V_173 -> V_180 , V_5 ) ;
F_23 ( V_2 , V_78 . V_179 . V_92 ,
V_173 -> V_181 , V_5 ) ;
V_62 &= ~ ( 1 << V_16 ) ;
}
if ( V_62 & ( 1 << V_17 ) ) {
const struct V_182 * V_183 ;
V_183 = F_19 ( V_58 [ V_17 ] ) ;
if ( ! V_5 && V_183 -> V_184 > V_175 ) {
F_7 ( log , L_37 ,
V_183 -> V_184 , V_175 ) ;
return - V_65 ;
}
if ( ! V_5 && V_183 -> V_185 & F_66 ( 0xFFF00000 ) ) {
F_7 ( log , L_38 ,
F_67 ( V_183 -> V_185 ) , ( 1 << 20 ) - 1 ) ;
return - V_65 ;
}
F_23 ( V_2 , V_79 . V_186 ,
V_183 -> V_185 , V_5 ) ;
F_23 ( V_2 , V_35 . V_38 ,
V_183 -> V_187 , V_5 ) ;
F_23 ( V_2 , V_35 . V_96 ,
V_183 -> V_188 , V_5 ) ;
F_23 ( V_2 , V_35 . V_77 ,
V_183 -> V_189 , V_5 ) ;
F_23 ( V_2 , V_35 . V_36 ,
V_183 -> V_184 , V_5 ) ;
F_63 ( V_2 , V_79 . V_179 . V_46 ,
V_183 -> V_190 ,
sizeof( V_2 -> V_30 -> V_79 . V_179 . V_46 ) ,
V_5 ) ;
F_63 ( V_2 , V_79 . V_179 . V_92 ,
V_183 -> V_191 ,
sizeof( V_2 -> V_30 -> V_79 . V_179 . V_92 ) ,
V_5 ) ;
V_62 &= ~ ( 1 << V_17 ) ;
}
if ( V_62 & ( 1 << V_24 ) ) {
const struct V_192 * V_193 ;
V_193 = F_19 ( V_58 [ V_24 ] ) ;
if ( ! V_5 && ( V_193 -> V_194 & F_5 ( 0xff00 ) ) ) {
F_7 ( log , L_39 ,
V_193 -> V_194 ) ;
return - V_65 ;
}
F_23 ( V_2 , V_78 . V_179 . V_46 ,
V_193 -> V_195 , V_5 ) ;
F_23 ( V_2 , V_78 . V_179 . V_92 ,
V_193 -> V_196 , V_5 ) ;
F_23 ( V_2 , V_35 . V_38 ,
F_57 ( V_193 -> V_194 ) , V_5 ) ;
F_63 ( V_2 , V_78 . V_197 . V_198 ,
V_193 -> V_199 , V_167 , V_5 ) ;
F_63 ( V_2 , V_78 . V_197 . V_200 ,
V_193 -> V_201 , V_167 , V_5 ) ;
V_62 &= ~ ( 1 << V_24 ) ;
}
if ( V_62 & ( 1 << V_26 ) ) {
const struct V_202 * V_203 ;
V_203 = F_19 ( V_58 [ V_26 ] ) ;
F_23 ( V_2 , V_204 . V_205 ,
V_203 -> V_206 , V_5 ) ;
V_62 &= ~ ( 1 << V_26 ) ;
}
if ( V_62 & ( 1 << V_18 ) ) {
const struct V_207 * V_208 ;
V_208 = F_19 ( V_58 [ V_18 ] ) ;
F_23 ( V_2 , V_45 . V_46 , V_208 -> V_209 , V_5 ) ;
F_23 ( V_2 , V_45 . V_92 , V_208 -> V_210 , V_5 ) ;
V_62 &= ~ ( 1 << V_18 ) ;
}
if ( V_62 & ( 1 << V_19 ) ) {
F_23 ( V_2 , V_45 . V_211 ,
F_33 ( V_58 [ V_19 ] ) ,
V_5 ) ;
V_62 &= ~ ( 1 << V_19 ) ;
}
if ( V_62 & ( 1 << V_20 ) ) {
const struct V_212 * V_213 ;
V_213 = F_19 ( V_58 [ V_20 ] ) ;
F_23 ( V_2 , V_45 . V_46 , V_213 -> V_214 , V_5 ) ;
F_23 ( V_2 , V_45 . V_92 , V_213 -> V_215 , V_5 ) ;
V_62 &= ~ ( 1 << V_20 ) ;
}
if ( V_62 & ( 1 << V_21 ) ) {
const struct V_216 * V_217 ;
V_217 = F_19 ( V_58 [ V_21 ] ) ;
F_23 ( V_2 , V_45 . V_46 , V_217 -> V_218 , V_5 ) ;
F_23 ( V_2 , V_45 . V_92 , V_217 -> V_219 , V_5 ) ;
V_62 &= ~ ( 1 << V_21 ) ;
}
if ( V_62 & ( 1 << V_22 ) ) {
const struct V_220 * V_221 ;
V_221 = F_19 ( V_58 [ V_22 ] ) ;
F_23 ( V_2 , V_45 . V_46 ,
F_5 ( V_221 -> V_222 ) , V_5 ) ;
F_23 ( V_2 , V_45 . V_92 ,
F_5 ( V_221 -> V_223 ) , V_5 ) ;
V_62 &= ~ ( 1 << V_22 ) ;
}
if ( V_62 & ( 1 << V_23 ) ) {
const struct V_224 * V_225 ;
V_225 = F_19 ( V_58 [ V_23 ] ) ;
F_23 ( V_2 , V_45 . V_46 ,
F_5 ( V_225 -> V_226 ) , V_5 ) ;
F_23 ( V_2 , V_45 . V_92 ,
F_5 ( V_225 -> V_227 ) , V_5 ) ;
V_62 &= ~ ( 1 << V_23 ) ;
}
if ( V_62 & ( 1 << V_25 ) ) {
const struct V_228 * V_229 ;
V_229 = F_19 ( V_58 [ V_25 ] ) ;
F_63 ( V_2 , V_79 . V_230 . V_231 ,
V_229 -> V_232 ,
sizeof( V_2 -> V_30 -> V_79 . V_230 . V_231 ) ,
V_5 ) ;
F_63 ( V_2 , V_79 . V_230 . V_233 ,
V_229 -> V_234 , V_167 , V_5 ) ;
F_63 ( V_2 , V_79 . V_230 . V_235 ,
V_229 -> V_236 , V_167 , V_5 ) ;
V_62 &= ~ ( 1 << V_25 ) ;
}
if ( V_62 != 0 ) {
F_7 ( log , L_40 ,
( unsigned long long ) V_62 ) ;
return - V_65 ;
}
return 0 ;
}
static void F_68 ( struct V_56 * V_57 , T_3 V_237 ,
const struct V_238 * V_239 )
{
struct V_56 * V_61 ;
int V_63 ;
F_16 (nla, attr, rem) {
if ( V_239 [ F_17 ( V_61 ) ] . V_67 == V_52 ) {
if ( V_239 [ F_17 ( V_61 ) ] . V_240 )
V_239 = V_239 [ F_17 ( V_61 ) ] . V_240 ;
F_68 ( V_61 , V_237 , V_239 ) ;
} else {
memset ( F_19 ( V_61 ) , V_237 , F_18 ( V_61 ) ) ;
}
if ( F_17 ( V_61 ) == V_150 )
* ( T_6 * ) F_19 ( V_61 ) &= V_152 ;
}
}
static void F_69 ( struct V_56 * V_57 , T_3 V_237 )
{
F_68 ( V_57 , V_237 , V_66 ) ;
}
int F_70 ( struct V_136 * V_136 , struct V_1 * V_2 ,
const struct V_56 * V_241 ,
const struct V_56 * V_242 ,
bool log )
{
const struct V_56 * V_58 [ V_64 + 1 ] ;
struct V_56 * V_243 = NULL ;
T_2 V_11 = 0 ;
T_2 V_12 = 0 ;
int V_82 ;
V_82 = F_21 ( V_241 , V_58 , & V_11 , log ) ;
if ( V_82 )
return V_82 ;
V_82 = F_59 ( V_2 , & V_11 , V_58 , false , log ) ;
if ( V_82 )
return V_82 ;
V_82 = F_64 ( V_136 , V_2 , V_11 , V_58 , false , log ) ;
if ( V_82 )
return V_82 ;
if ( V_2 -> V_10 ) {
if ( ! V_242 ) {
V_243 = F_71 ( V_241 ,
F_10 ( F_18 ( V_241 ) ) ,
V_244 ) ;
if ( ! V_243 )
return - V_245 ;
F_69 ( V_243 , 0xff ) ;
if ( V_2 -> V_30 -> V_112 )
F_34 ( V_2 , V_86 ,
0xff , true ) ;
V_242 = V_243 ;
}
V_82 = F_20 ( V_242 , V_58 , & V_12 , log ) ;
if ( V_82 )
goto V_246;
F_23 ( V_2 , V_31 . V_129 . V_126 , F_5 ( 0xffff ) , true ) ;
F_23 ( V_2 , V_31 . V_130 . V_126 , F_5 ( 0xffff ) , true ) ;
V_82 = F_59 ( V_2 , & V_12 , V_58 , true , log ) ;
if ( V_82 )
goto V_246;
V_82 = F_64 ( V_136 , V_2 , V_12 , V_58 , true ,
log ) ;
if ( V_82 )
goto V_246;
}
if ( ! F_4 ( V_2 , V_11 , V_12 , log ) )
V_82 = - V_65 ;
V_246:
F_72 ( V_243 ) ;
return V_82 ;
}
static T_1 F_73 ( const struct V_56 * V_57 , bool log )
{
T_1 V_67 ;
if ( ! V_57 )
return 0 ;
V_67 = F_18 ( V_57 ) ;
if ( V_67 < 1 || V_67 > V_247 ) {
F_7 ( log , L_41 ,
F_18 ( V_57 ) , V_247 ) ;
return 0 ;
}
return V_67 ;
}
bool F_74 ( struct V_248 * V_249 , const struct V_56 * V_57 ,
bool log )
{
V_249 -> V_250 = F_73 ( V_57 , log ) ;
if ( V_249 -> V_250 )
memcpy ( V_249 -> V_251 , F_19 ( V_57 ) , V_249 -> V_250 ) ;
return V_249 -> V_250 ;
}
int F_75 ( struct V_248 * V_249 , const struct V_56 * V_251 ,
const struct V_252 * V_30 , bool log )
{
struct V_252 * V_253 ;
if ( F_74 ( V_249 , V_251 , log ) )
return 0 ;
V_253 = F_76 ( sizeof( * V_253 ) , V_244 ) ;
if ( ! V_253 )
return - V_245 ;
memcpy ( V_253 , V_30 , sizeof( * V_30 ) ) ;
V_249 -> V_254 = V_253 ;
return 0 ;
}
T_6 F_77 ( const struct V_56 * V_57 )
{
return V_57 ? F_27 ( V_57 ) : 0 ;
}
int F_78 ( struct V_136 * V_136 , const struct V_56 * V_57 ,
struct V_252 * V_30 ,
bool log )
{
const struct V_56 * V_58 [ V_64 + 1 ] ;
struct V_1 V_2 ;
T_2 V_62 = 0 ;
int V_82 ;
V_82 = F_21 ( V_57 , V_58 , & V_62 , log ) ;
if ( V_82 )
return - V_65 ;
memset ( & V_2 , 0 , sizeof( V_2 ) ) ;
V_2 . V_30 = V_30 ;
memset ( & V_30 -> V_153 , 0 , sizeof( V_30 -> V_153 ) ) ;
V_30 -> V_143 . V_145 = V_146 ;
return F_60 ( V_136 , & V_2 , & V_62 , V_58 , false , log ) ;
}
static int F_79 ( struct V_115 * V_116 , const struct V_255 * V_256 ,
bool V_5 )
{
T_5 V_169 = ! V_5 ? V_256 -> V_127 : F_5 ( 0xffff ) ;
if ( F_46 ( V_116 , V_29 , V_169 ) ||
F_46 ( V_116 , V_128 , V_256 -> V_126 ) )
return - V_118 ;
return 0 ;
}
static int F_80 ( const struct V_252 * V_257 ,
const struct V_252 * V_120 , bool V_5 ,
struct V_115 * V_116 )
{
struct V_164 * V_165 ;
struct V_56 * V_61 ;
struct V_56 * V_135 = NULL ;
struct V_56 * V_258 = NULL ;
if ( F_38 ( V_116 , V_140 , V_120 -> V_141 ) )
goto V_259;
if ( F_38 ( V_116 , V_137 , V_120 -> V_139 ) )
goto V_259;
if ( F_38 ( V_116 , V_142 , V_120 -> V_143 . V_144 ) )
goto V_259;
if ( ( V_257 -> V_112 || V_5 ) ) {
const void * V_72 = NULL ;
if ( V_120 -> V_86 . V_80 & V_260 )
V_72 = F_81 ( V_120 , V_257 -> V_70 ) ;
if ( F_48 ( V_116 , & V_120 -> V_86 , V_72 ,
V_257 -> V_70 , V_257 -> V_112 ) )
goto V_259;
}
if ( V_257 -> V_143 . V_145 == V_146 ) {
if ( V_5 && ( V_120 -> V_143 . V_145 == 0xffff ) )
if ( F_38 ( V_116 , V_28 , 0xffffffff ) )
goto V_259;
} else {
T_4 V_261 ;
V_261 = ! V_5 ? 0 : 0xffff ;
if ( F_38 ( V_116 , V_28 ,
( V_261 << 16 ) | V_120 -> V_143 . V_145 ) )
goto V_259;
}
if ( F_38 ( V_116 , V_147 , V_120 -> V_143 . V_149 ) )
goto V_259;
if ( F_82 ( V_120 , V_116 ) )
goto V_259;
V_61 = F_83 ( V_116 , V_14 , sizeof( * V_165 ) ) ;
if ( ! V_61 )
goto V_259;
V_165 = F_19 ( V_61 ) ;
F_84 ( V_165 -> V_166 , V_120 -> V_31 . V_46 ) ;
F_84 ( V_165 -> V_168 , V_120 -> V_31 . V_92 ) ;
if ( V_257 -> V_31 . V_129 . V_126 || F_55 ( V_257 -> V_31 . type ) ) {
if ( F_79 ( V_116 , & V_120 -> V_31 . V_129 , V_5 ) )
goto V_259;
V_135 = F_37 ( V_116 , V_131 ) ;
if ( ! V_257 -> V_31 . V_129 . V_126 )
goto V_262;
if ( V_257 -> V_31 . V_130 . V_126 || F_55 ( V_257 -> V_31 . type ) ) {
if ( F_79 ( V_116 , & V_120 -> V_31 . V_130 , V_5 ) )
goto V_259;
V_258 = F_37 ( V_116 , V_131 ) ;
if ( ! V_257 -> V_31 . V_130 . V_126 )
goto V_262;
}
}
if ( V_257 -> V_31 . type == F_5 ( V_171 ) ) {
if ( V_5 && V_120 -> V_31 . type )
if ( F_46 ( V_116 , V_29 ,
V_120 -> V_31 . type ) )
goto V_259;
goto V_262;
}
if ( F_46 ( V_116 , V_29 , V_120 -> V_31 . type ) )
goto V_259;
if ( F_55 ( V_257 -> V_31 . type ) ) {
F_85 ( ! ( V_135 && V_258 ) ) ;
goto V_262;
}
if ( V_257 -> V_31 . type == F_5 ( V_34 ) ) {
struct V_172 * V_173 ;
V_61 = F_83 ( V_116 , V_16 , sizeof( * V_173 ) ) ;
if ( ! V_61 )
goto V_259;
V_173 = F_19 ( V_61 ) ;
V_173 -> V_180 = V_120 -> V_78 . V_179 . V_46 ;
V_173 -> V_181 = V_120 -> V_78 . V_179 . V_92 ;
V_173 -> V_176 = V_120 -> V_35 . V_38 ;
V_173 -> V_177 = V_120 -> V_35 . V_96 ;
V_173 -> V_178 = V_120 -> V_35 . V_77 ;
V_173 -> V_174 = V_120 -> V_35 . V_36 ;
} else if ( V_257 -> V_31 . type == F_5 ( V_43 ) ) {
struct V_182 * V_183 ;
V_61 = F_83 ( V_116 , V_17 , sizeof( * V_183 ) ) ;
if ( ! V_61 )
goto V_259;
V_183 = F_19 ( V_61 ) ;
memcpy ( V_183 -> V_190 , & V_120 -> V_79 . V_179 . V_46 ,
sizeof( V_183 -> V_190 ) ) ;
memcpy ( V_183 -> V_191 , & V_120 -> V_79 . V_179 . V_92 ,
sizeof( V_183 -> V_191 ) ) ;
V_183 -> V_185 = V_120 -> V_79 . V_186 ;
V_183 -> V_187 = V_120 -> V_35 . V_38 ;
V_183 -> V_188 = V_120 -> V_35 . V_96 ;
V_183 -> V_189 = V_120 -> V_35 . V_77 ;
V_183 -> V_184 = V_120 -> V_35 . V_36 ;
} else if ( V_257 -> V_31 . type == F_5 ( V_32 ) ||
V_257 -> V_31 . type == F_5 ( V_33 ) ) {
struct V_192 * V_193 ;
V_61 = F_83 ( V_116 , V_24 , sizeof( * V_193 ) ) ;
if ( ! V_61 )
goto V_259;
V_193 = F_19 ( V_61 ) ;
memset ( V_193 , 0 , sizeof( struct V_192 ) ) ;
V_193 -> V_195 = V_120 -> V_78 . V_179 . V_46 ;
V_193 -> V_196 = V_120 -> V_78 . V_179 . V_92 ;
V_193 -> V_194 = F_5 ( V_120 -> V_35 . V_38 ) ;
F_84 ( V_193 -> V_199 , V_120 -> V_78 . V_197 . V_198 ) ;
F_84 ( V_193 -> V_201 , V_120 -> V_78 . V_197 . V_200 ) ;
} else if ( F_6 ( V_257 -> V_31 . type ) ) {
struct V_202 * V_203 ;
V_61 = F_83 ( V_116 , V_26 , sizeof( * V_203 ) ) ;
if ( ! V_61 )
goto V_259;
V_203 = F_19 ( V_61 ) ;
V_203 -> V_206 = V_120 -> V_204 . V_205 ;
}
if ( ( V_257 -> V_31 . type == F_5 ( V_34 ) ||
V_257 -> V_31 . type == F_5 ( V_43 ) ) &&
V_257 -> V_35 . V_36 != V_37 ) {
if ( V_257 -> V_35 . V_38 == V_41 ) {
struct V_207 * V_208 ;
V_61 = F_83 ( V_116 , V_18 , sizeof( * V_208 ) ) ;
if ( ! V_61 )
goto V_259;
V_208 = F_19 ( V_61 ) ;
V_208 -> V_209 = V_120 -> V_45 . V_46 ;
V_208 -> V_210 = V_120 -> V_45 . V_92 ;
if ( F_46 ( V_116 , V_19 ,
V_120 -> V_45 . V_211 ) )
goto V_259;
} else if ( V_257 -> V_35 . V_38 == V_39 ) {
struct V_212 * V_213 ;
V_61 = F_83 ( V_116 , V_20 , sizeof( * V_213 ) ) ;
if ( ! V_61 )
goto V_259;
V_213 = F_19 ( V_61 ) ;
V_213 -> V_214 = V_120 -> V_45 . V_46 ;
V_213 -> V_215 = V_120 -> V_45 . V_92 ;
} else if ( V_257 -> V_35 . V_38 == V_40 ) {
struct V_216 * V_217 ;
V_61 = F_83 ( V_116 , V_21 , sizeof( * V_217 ) ) ;
if ( ! V_61 )
goto V_259;
V_217 = F_19 ( V_61 ) ;
V_217 -> V_218 = V_120 -> V_45 . V_46 ;
V_217 -> V_219 = V_120 -> V_45 . V_92 ;
} else if ( V_257 -> V_31 . type == F_5 ( V_34 ) &&
V_257 -> V_35 . V_38 == V_42 ) {
struct V_220 * V_221 ;
V_61 = F_83 ( V_116 , V_22 , sizeof( * V_221 ) ) ;
if ( ! V_61 )
goto V_259;
V_221 = F_19 ( V_61 ) ;
V_221 -> V_222 = F_57 ( V_120 -> V_45 . V_46 ) ;
V_221 -> V_223 = F_57 ( V_120 -> V_45 . V_92 ) ;
} else if ( V_257 -> V_31 . type == F_5 ( V_43 ) &&
V_257 -> V_35 . V_38 == V_44 ) {
struct V_224 * V_225 ;
V_61 = F_83 ( V_116 , V_23 ,
sizeof( * V_225 ) ) ;
if ( ! V_61 )
goto V_259;
V_225 = F_19 ( V_61 ) ;
V_225 -> V_226 = F_57 ( V_120 -> V_45 . V_46 ) ;
V_225 -> V_227 = F_57 ( V_120 -> V_45 . V_92 ) ;
if ( V_225 -> V_226 == V_47 ||
V_225 -> V_226 == V_48 ) {
struct V_228 * V_229 ;
V_61 = F_83 ( V_116 , V_25 , sizeof( * V_229 ) ) ;
if ( ! V_61 )
goto V_259;
V_229 = F_19 ( V_61 ) ;
memcpy ( V_229 -> V_232 , & V_120 -> V_79 . V_230 . V_231 ,
sizeof( V_229 -> V_232 ) ) ;
F_84 ( V_229 -> V_234 , V_120 -> V_79 . V_230 . V_233 ) ;
F_84 ( V_229 -> V_236 , V_120 -> V_79 . V_230 . V_235 ) ;
}
}
}
V_262:
if ( V_258 )
F_39 ( V_116 , V_258 ) ;
if ( V_135 )
F_39 ( V_116 , V_135 ) ;
return 0 ;
V_259:
return - V_118 ;
}
int F_86 ( const struct V_252 * V_257 ,
const struct V_252 * V_120 , int V_57 , bool V_5 ,
struct V_115 * V_116 )
{
int V_82 ;
struct V_56 * V_61 ;
V_61 = F_37 ( V_116 , V_57 ) ;
if ( ! V_61 )
return - V_118 ;
V_82 = F_80 ( V_257 , V_120 , V_5 , V_116 ) ;
if ( V_82 )
return V_82 ;
F_39 ( V_116 , V_61 ) ;
return 0 ;
}
int F_87 ( const struct V_263 * V_264 , struct V_115 * V_116 )
{
if ( F_88 ( & V_264 -> V_265 ) )
return F_47 ( V_116 , V_266 , V_264 -> V_265 . V_250 ,
V_264 -> V_265 . V_251 ) ;
return F_86 ( V_264 -> V_265 . V_254 , V_264 -> V_265 . V_254 ,
V_267 , false , V_116 ) ;
}
int F_89 ( const struct V_263 * V_264 , struct V_115 * V_116 )
{
return F_86 ( & V_264 -> V_30 , & V_264 -> V_30 ,
V_267 , false , V_116 ) ;
}
int F_90 ( const struct V_263 * V_264 , struct V_115 * V_116 )
{
return F_86 ( & V_264 -> V_30 , & V_264 -> V_10 -> V_30 ,
V_268 , true , V_116 ) ;
}
static struct V_269 * F_91 ( int V_4 , bool log )
{
struct V_269 * V_270 ;
if ( V_4 > V_271 ) {
F_7 ( log , L_42 , V_4 ) ;
return F_92 ( - V_65 ) ;
}
V_270 = F_76 ( sizeof( * V_270 ) + V_4 , V_244 ) ;
if ( ! V_270 )
return F_92 ( - V_245 ) ;
V_270 -> V_272 = 0 ;
return V_270 ;
}
static void F_93 ( const struct V_56 * V_58 )
{
const struct V_56 * V_273 = F_19 ( V_58 ) ;
struct V_274 * V_275 ;
switch ( F_17 ( V_273 ) ) {
case V_49 :
V_275 = F_19 ( V_273 ) ;
F_94 ( (struct V_276 * ) V_275 -> V_277 ) ;
break;
}
}
void F_95 ( struct V_269 * V_278 )
{
const struct V_56 * V_58 ;
int V_63 ;
if ( ! V_278 )
return;
F_96 (a, sf_acts->actions, sf_acts->actions_len, rem) {
switch ( F_17 ( V_58 ) ) {
case V_279 :
F_93 ( V_58 ) ;
break;
case V_280 :
F_97 ( V_58 ) ;
break;
}
}
F_72 ( V_278 ) ;
}
static void F_98 ( struct V_281 * V_282 )
{
F_95 ( F_99 ( V_282 , struct V_269 , V_283 ) ) ;
}
void F_100 ( struct V_269 * V_278 )
{
F_101 ( & V_278 -> V_283 , F_98 ) ;
}
static struct V_56 * F_102 ( struct V_269 * * V_270 ,
int V_50 , bool log )
{
struct V_269 * V_284 ;
int V_285 ;
int V_286 = F_103 ( V_50 ) ;
int V_287 = F_104 ( struct V_269 , V_288 ) +
( * V_270 ) -> V_272 ;
if ( V_286 <= ( F_105 ( * V_270 ) - V_287 ) )
goto V_289;
V_285 = F_105 ( * V_270 ) * 2 ;
if ( V_285 > V_271 ) {
if ( ( V_271 - V_287 ) < V_286 )
return F_92 ( - V_118 ) ;
V_285 = V_271 ;
}
V_284 = F_91 ( V_285 , log ) ;
if ( F_106 ( V_284 ) )
return ( void * ) V_284 ;
memcpy ( V_284 -> V_288 , ( * V_270 ) -> V_288 , ( * V_270 ) -> V_272 ) ;
V_284 -> V_272 = ( * V_270 ) -> V_272 ;
V_284 -> V_290 = ( * V_270 ) -> V_290 ;
F_72 ( * V_270 ) ;
* V_270 = V_284 ;
V_289:
( * V_270 ) -> V_272 += V_286 ;
return (struct V_56 * ) ( ( unsigned char * ) ( * V_270 ) + V_287 ) ;
}
static struct V_56 * F_107 ( struct V_269 * * V_270 ,
int V_291 , void * V_292 , int V_67 , bool log )
{
struct V_56 * V_58 ;
V_58 = F_102 ( V_270 , F_108 ( V_67 ) , log ) ;
if ( F_106 ( V_58 ) )
return V_58 ;
V_58 -> F_17 = V_291 ;
V_58 -> F_18 = F_108 ( V_67 ) ;
if ( V_292 )
memcpy ( F_19 ( V_58 ) , V_292 , V_67 ) ;
memset ( ( unsigned char * ) V_58 + V_58 -> F_18 , 0 , F_109 ( V_67 ) ) ;
return V_58 ;
}
int F_110 ( struct V_269 * * V_270 , int V_291 , void * V_292 ,
int V_67 , bool log )
{
struct V_56 * V_58 ;
V_58 = F_107 ( V_270 , V_291 , V_292 , V_67 , log ) ;
return F_111 ( V_58 ) ;
}
static inline int F_112 ( struct V_269 * * V_270 ,
int V_291 , bool log )
{
int V_293 = ( * V_270 ) -> V_272 ;
int V_82 ;
V_82 = F_110 ( V_270 , V_291 , NULL , 0 , log ) ;
if ( V_82 )
return V_82 ;
return V_293 ;
}
static inline void F_113 ( struct V_269 * V_270 ,
int V_294 )
{
struct V_56 * V_58 = (struct V_56 * ) ( ( unsigned char * ) V_270 -> V_288 +
V_294 ) ;
V_58 -> F_18 = V_270 -> V_272 - V_294 ;
}
static int F_114 ( struct V_136 * V_136 , const struct V_56 * V_57 ,
const struct V_252 * V_30 , int V_295 ,
struct V_269 * * V_270 ,
T_5 V_169 , T_5 V_296 , bool log )
{
const struct V_56 * V_62 [ V_297 + 1 ] ;
const struct V_56 * V_298 , * V_288 ;
const struct V_56 * V_58 ;
int V_63 , V_8 , V_82 , V_299 ;
memset ( V_62 , 0 , sizeof( V_62 ) ) ;
F_16 (a, attr, rem) {
int type = F_17 ( V_58 ) ;
if ( ! type || type > V_297 || V_62 [ type ] )
return - V_65 ;
V_62 [ type ] = V_58 ;
}
if ( V_63 )
return - V_65 ;
V_298 = V_62 [ V_300 ] ;
if ( ! V_298 || F_18 ( V_298 ) != sizeof( T_6 ) )
return - V_65 ;
V_288 = V_62 [ V_301 ] ;
if ( ! V_288 || ( F_18 ( V_288 ) && F_18 ( V_288 ) < V_302 ) )
return - V_65 ;
V_8 = F_112 ( V_270 , V_303 , log ) ;
if ( V_8 < 0 )
return V_8 ;
V_82 = F_110 ( V_270 , V_300 ,
F_19 ( V_298 ) , sizeof( T_6 ) , log ) ;
if ( V_82 )
return V_82 ;
V_299 = F_112 ( V_270 , V_301 , log ) ;
if ( V_299 < 0 )
return V_299 ;
V_82 = F_115 ( V_136 , V_288 , V_30 , V_295 + 1 , V_270 ,
V_169 , V_296 , log ) ;
if ( V_82 )
return V_82 ;
F_113 ( * V_270 , V_299 ) ;
F_113 ( * V_270 , V_8 ) ;
return 0 ;
}
void F_116 ( struct V_1 * V_2 ,
struct V_252 * V_30 ,
bool V_304 ,
struct V_305 * V_10 )
{
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_30 = V_30 ;
V_2 -> V_10 = V_10 ;
if ( V_304 )
memset ( V_30 , 0 , sizeof( * V_30 ) ) ;
if ( V_10 ) {
memset ( & V_10 -> V_30 , 0 , sizeof( V_10 -> V_30 ) ) ;
V_10 -> V_7 . V_8 = V_10 -> V_7 . V_9 = 0 ;
}
}
static int F_117 ( struct V_252 * V_30 )
{
struct V_306 * V_307 ;
int V_308 = V_30 -> V_70 ;
bool V_309 = false ;
V_307 = (struct V_306 * ) F_81 ( V_30 , V_30 -> V_70 ) ;
while ( V_308 > 0 ) {
int V_67 ;
if ( V_308 < sizeof( * V_307 ) )
return - V_65 ;
V_67 = sizeof( * V_307 ) + V_307 -> V_310 * 4 ;
if ( V_67 > V_308 )
return - V_65 ;
V_309 |= ! ! ( V_307 -> type & V_311 ) ;
V_307 = (struct V_306 * ) ( ( T_3 * ) V_307 + V_67 ) ;
V_308 -= V_67 ;
} ;
V_30 -> V_86 . V_80 |= V_309 ? V_312 : 0 ;
return 0 ;
}
static int F_118 ( const struct V_56 * V_57 ,
struct V_269 * * V_270 , bool log )
{
struct V_1 V_2 ;
struct V_252 V_30 ;
struct V_313 * V_277 ;
struct V_122 * V_123 ;
struct V_274 * V_275 ;
struct V_56 * V_58 ;
int V_82 = 0 , V_8 , V_81 ;
F_116 ( & V_2 , & V_30 , true , NULL ) ;
V_81 = F_28 ( F_19 ( V_57 ) , & V_2 , false , log ) ;
if ( V_81 < 0 )
return V_81 ;
if ( V_30 . V_70 ) {
switch ( V_81 ) {
case V_108 :
V_82 = F_117 ( & V_30 ) ;
if ( V_82 < 0 )
return V_82 ;
break;
case V_110 :
break;
}
} ;
V_8 = F_112 ( V_270 , V_279 , log ) ;
if ( V_8 < 0 )
return V_8 ;
V_277 = F_119 ( V_30 . V_70 , V_244 ) ;
if ( ! V_277 )
return - V_245 ;
V_82 = F_120 ( & V_277 -> V_90 . V_123 . V_314 , V_244 ) ;
if ( V_82 ) {
F_94 ( (struct V_276 * ) V_277 ) ;
return V_82 ;
}
V_58 = F_107 ( V_270 , V_49 , NULL ,
sizeof( * V_275 ) , log ) ;
if ( F_106 ( V_58 ) ) {
F_94 ( (struct V_276 * ) V_277 ) ;
return F_121 ( V_58 ) ;
}
V_275 = F_19 ( V_58 ) ;
V_275 -> V_277 = V_277 ;
V_123 = & V_277 -> V_90 . V_123 ;
V_123 -> V_315 = V_316 ;
if ( V_30 . V_112 == V_113 )
V_123 -> V_315 |= V_317 ;
V_123 -> V_30 = V_30 . V_86 ;
F_122 ( V_123 ,
F_81 ( & V_30 , V_30 . V_70 ) ,
V_30 . V_70 ) ;
F_113 ( * V_270 , V_8 ) ;
return V_82 ;
}
static bool F_123 ( T_3 * V_292 , int V_67 )
{
T_3 * V_10 = V_292 + V_67 ;
while ( V_67 -- )
if ( * V_292 ++ & ~ * V_10 ++ )
return false ;
return true ;
}
static int F_124 ( const struct V_56 * V_58 ,
const struct V_252 * V_318 ,
struct V_269 * * V_270 ,
bool * V_319 , T_5 V_169 , bool V_320 , bool log )
{
const struct V_56 * V_273 = F_19 ( V_58 ) ;
int V_321 = F_17 ( V_273 ) ;
T_1 V_322 ;
if ( F_10 ( F_18 ( V_273 ) ) != F_18 ( V_58 ) )
return - V_65 ;
V_322 = F_18 ( V_273 ) ;
if ( V_320 )
V_322 /= 2 ;
if ( V_321 > V_64 ||
! F_13 ( V_322 , V_66 [ V_321 ] . V_67 ) )
return - V_65 ;
if ( V_320 && ! F_123 ( F_19 ( V_273 ) , V_322 ) )
return - V_65 ;
switch ( V_321 ) {
const struct V_172 * V_173 ;
const struct V_182 * V_183 ;
int V_82 ;
case V_142 :
case V_147 :
case V_158 :
case V_159 :
case V_14 :
break;
case V_27 :
if ( V_320 )
return - V_65 ;
* V_319 = true ;
V_82 = F_118 ( V_58 , V_270 , log ) ;
if ( V_82 )
return V_82 ;
break;
case V_16 :
if ( V_169 != F_5 ( V_34 ) )
return - V_65 ;
V_173 = F_19 ( V_273 ) ;
if ( V_320 ) {
const struct V_172 * V_10 = V_173 + 1 ;
if ( V_10 -> V_176 || V_10 -> V_174 )
return - V_65 ;
} else {
if ( V_173 -> V_176 != V_318 -> V_35 . V_38 )
return - V_65 ;
if ( V_173 -> V_174 != V_318 -> V_35 . V_36 )
return - V_65 ;
}
break;
case V_17 :
if ( V_169 != F_5 ( V_43 ) )
return - V_65 ;
V_183 = F_19 ( V_273 ) ;
if ( V_320 ) {
const struct V_182 * V_10 = V_183 + 1 ;
if ( V_10 -> V_187 || V_10 -> V_184 )
return - V_65 ;
if ( F_67 ( V_10 -> V_185 ) & 0xFFF00000 )
return - V_65 ;
} else {
if ( V_183 -> V_187 != V_318 -> V_35 . V_38 )
return - V_65 ;
if ( V_183 -> V_184 != V_318 -> V_35 . V_36 )
return - V_65 ;
}
if ( F_67 ( V_183 -> V_185 ) & 0xFFF00000 )
return - V_65 ;
break;
case V_18 :
if ( ( V_169 != F_5 ( V_34 ) &&
V_169 != F_5 ( V_43 ) ) ||
V_318 -> V_35 . V_38 != V_41 )
return - V_65 ;
break;
case V_20 :
if ( ( V_169 != F_5 ( V_34 ) &&
V_169 != F_5 ( V_43 ) ) ||
V_318 -> V_35 . V_38 != V_39 )
return - V_65 ;
break;
case V_26 :
if ( ! F_6 ( V_169 ) )
return - V_65 ;
break;
case V_21 :
if ( ( V_169 != F_5 ( V_34 ) &&
V_169 != F_5 ( V_43 ) ) ||
V_318 -> V_35 . V_38 != V_40 )
return - V_65 ;
break;
default:
return - V_65 ;
}
if ( ! V_320 && V_321 != V_27 ) {
int V_8 , V_67 = V_322 * 2 ;
struct V_56 * V_323 ;
* V_319 = true ;
V_8 = F_112 ( V_270 ,
V_324 ,
log ) ;
if ( V_8 < 0 )
return V_8 ;
V_323 = F_107 ( V_270 , V_321 , NULL , V_67 , log ) ;
if ( F_106 ( V_323 ) )
return F_121 ( V_323 ) ;
memcpy ( F_19 ( V_323 ) , F_19 ( V_273 ) , V_322 ) ;
memset ( F_19 ( V_323 ) + V_322 , 0xff , V_322 ) ;
if ( V_321 == V_17 ) {
struct V_182 * V_10 = F_19 ( V_323 ) + V_322 ;
V_10 -> V_185 &= F_66 ( 0x000FFFFF ) ;
}
F_113 ( * V_270 , V_8 ) ;
}
return 0 ;
}
static int F_125 ( const struct V_56 * V_57 )
{
static const struct V_325 V_326 [ V_327 + 1 ] = {
[ V_328 ] = { . type = V_329 } ,
[ V_330 ] = { . type = V_331 } ,
[ V_332 ] = { . type = V_329 } ,
} ;
struct V_56 * V_58 [ V_327 + 1 ] ;
int error ;
error = F_126 ( V_58 , V_327 ,
V_57 , V_326 ) ;
if ( error )
return error ;
if ( ! V_58 [ V_328 ] ||
! F_27 ( V_58 [ V_328 ] ) )
return - V_65 ;
return 0 ;
}
static int F_127 ( const struct V_56 * V_333 ,
struct V_269 * * V_270 , bool log )
{
int V_334 = F_103 ( V_333 -> F_18 ) ;
struct V_56 * V_335 ;
V_335 = F_102 ( V_270 , V_333 -> F_18 , log ) ;
if ( F_106 ( V_335 ) )
return F_121 ( V_335 ) ;
memcpy ( V_335 , V_333 , V_334 ) ;
return 0 ;
}
static int F_115 ( struct V_136 * V_136 , const struct V_56 * V_57 ,
const struct V_252 * V_30 ,
int V_295 , struct V_269 * * V_270 ,
T_5 V_169 , T_5 V_296 , bool log )
{
const struct V_56 * V_58 ;
int V_63 , V_82 ;
if ( V_295 >= V_336 )
return - V_337 ;
F_16 (a, attr, rem) {
static const T_6 V_338 [ V_339 + 1 ] = {
[ V_340 ] = sizeof( T_6 ) ,
[ V_341 ] = sizeof( T_6 ) ,
[ V_342 ] = ( T_6 ) - 1 ,
[ V_343 ] = sizeof( struct V_344 ) ,
[ V_345 ] = sizeof( T_5 ) ,
[ V_346 ] = sizeof( struct V_347 ) ,
[ V_348 ] = 0 ,
[ V_279 ] = ( T_6 ) - 1 ,
[ V_349 ] = ( T_6 ) - 1 ,
[ V_303 ] = ( T_6 ) - 1 ,
[ V_350 ] = sizeof( struct V_351 ) ,
[ V_280 ] = ( T_6 ) - 1 ,
[ V_352 ] = sizeof( struct V_353 ) ,
} ;
const struct V_347 * V_129 ;
int type = F_17 ( V_58 ) ;
bool V_319 ;
if ( type > V_339 ||
( V_338 [ type ] != F_18 ( V_58 ) &&
V_338 [ type ] != ( T_6 ) - 1 ) )
return - V_65 ;
V_319 = false ;
switch ( type ) {
case V_354 :
return - V_65 ;
case V_342 :
V_82 = F_125 ( V_58 ) ;
if ( V_82 )
return V_82 ;
break;
case V_340 :
if ( F_27 ( V_58 ) >= V_146 )
return - V_65 ;
break;
case V_352 : {
const struct V_353 * V_355 = F_19 ( V_58 ) ;
if ( V_355 -> V_356 < V_357 )
return - V_65 ;
break;
}
case V_350 : {
const struct V_351 * V_358 = F_19 ( V_58 ) ;
switch ( V_358 -> V_359 ) {
case V_360 :
break;
default:
return - V_65 ;
}
break;
}
case V_348 :
V_296 = F_5 ( 0 ) ;
break;
case V_346 :
V_129 = F_19 ( V_58 ) ;
if ( ! F_55 ( V_129 -> V_361 ) )
return - V_65 ;
if ( ! ( V_129 -> V_296 & F_5 ( V_132 ) ) )
return - V_65 ;
V_296 = V_129 -> V_296 ;
break;
case V_341 :
break;
case V_343 : {
const struct V_344 * V_204 = F_19 ( V_58 ) ;
if ( ! F_6 ( V_204 -> V_362 ) )
return - V_65 ;
if ( V_296 & F_5 ( V_132 ) ||
( V_169 != F_5 ( V_34 ) &&
V_169 != F_5 ( V_43 ) &&
V_169 != F_5 ( V_32 ) &&
V_169 != F_5 ( V_33 ) &&
! F_6 ( V_169 ) ) )
return - V_65 ;
V_169 = V_204 -> V_362 ;
break;
}
case V_345 :
if ( V_296 & F_5 ( V_132 ) ||
! F_6 ( V_169 ) )
return - V_65 ;
V_169 = F_5 ( 0 ) ;
break;
case V_279 :
V_82 = F_124 ( V_58 , V_30 , V_270 ,
& V_319 , V_169 , false , log ) ;
if ( V_82 )
return V_82 ;
break;
case V_349 :
V_82 = F_124 ( V_58 , V_30 , V_270 ,
& V_319 , V_169 , true , log ) ;
if ( V_82 )
return V_82 ;
break;
case V_303 :
V_82 = F_114 ( V_136 , V_58 , V_30 , V_295 , V_270 ,
V_169 , V_296 , log ) ;
if ( V_82 )
return V_82 ;
V_319 = true ;
break;
case V_280 :
V_82 = F_128 ( V_136 , V_58 , V_30 , V_270 , log ) ;
if ( V_82 )
return V_82 ;
V_319 = true ;
break;
default:
F_7 ( log , L_43 , type ) ;
return - V_65 ;
}
if ( ! V_319 ) {
V_82 = F_127 ( V_58 , V_270 , log ) ;
if ( V_82 )
return V_82 ;
}
}
if ( V_63 > 0 )
return - V_65 ;
return 0 ;
}
int F_129 ( struct V_136 * V_136 , const struct V_56 * V_57 ,
const struct V_252 * V_30 ,
struct V_269 * * V_270 , bool log )
{
int V_82 ;
* V_270 = F_91 ( F_18 ( V_57 ) , log ) ;
if ( F_106 ( * V_270 ) )
return F_121 ( * V_270 ) ;
( * V_270 ) -> V_290 = F_18 ( V_57 ) ;
V_82 = F_115 ( V_136 , V_57 , V_30 , 0 , V_270 , V_30 -> V_31 . type ,
V_30 -> V_31 . V_129 . V_126 , log ) ;
if ( V_82 )
F_95 ( * V_270 ) ;
return V_82 ;
}
static int F_130 ( const struct V_56 * V_57 , struct V_115 * V_116 )
{
const struct V_56 * V_58 ;
struct V_56 * V_8 ;
int V_82 = 0 , V_63 ;
V_8 = F_37 ( V_116 , V_303 ) ;
if ( ! V_8 )
return - V_118 ;
F_16 (a, attr, rem) {
int type = F_17 ( V_58 ) ;
struct V_56 * V_363 ;
switch ( type ) {
case V_300 :
if ( F_47 ( V_116 , V_300 ,
sizeof( T_6 ) , F_19 ( V_58 ) ) )
return - V_118 ;
break;
case V_301 :
V_363 = F_37 ( V_116 , V_301 ) ;
if ( ! V_363 )
return - V_118 ;
V_82 = F_131 ( F_19 ( V_58 ) , F_18 ( V_58 ) , V_116 ) ;
if ( V_82 )
return V_82 ;
F_39 ( V_116 , V_363 ) ;
break;
}
}
F_39 ( V_116 , V_8 ) ;
return V_82 ;
}
static int F_132 ( const struct V_56 * V_58 , struct V_115 * V_116 )
{
const struct V_56 * V_273 = F_19 ( V_58 ) ;
int V_321 = F_17 ( V_273 ) ;
struct V_56 * V_8 ;
int V_82 ;
switch ( V_321 ) {
case V_49 : {
struct V_274 * V_275 = F_19 ( V_273 ) ;
struct V_122 * V_123 = & V_275 -> V_277 -> V_90 . V_123 ;
V_8 = F_37 ( V_116 , V_279 ) ;
if ( ! V_8 )
return - V_118 ;
V_82 = F_48 ( V_116 , & V_123 -> V_30 ,
F_50 ( V_123 ) ,
V_123 -> V_124 ,
F_51 ( V_123 ) ) ;
if ( V_82 )
return V_82 ;
F_39 ( V_116 , V_8 ) ;
break;
}
default:
if ( F_47 ( V_116 , V_279 , F_18 ( V_58 ) , V_273 ) )
return - V_118 ;
break;
}
return 0 ;
}
static int F_133 ( const struct V_56 * V_58 ,
struct V_115 * V_116 )
{
const struct V_56 * V_273 = F_19 ( V_58 ) ;
struct V_56 * V_61 ;
T_1 V_322 = F_18 ( V_273 ) / 2 ;
V_61 = F_37 ( V_116 , V_279 ) ;
if ( ! V_61 )
return - V_118 ;
if ( F_47 ( V_116 , F_17 ( V_273 ) , V_322 , F_19 ( V_273 ) ) )
return - V_118 ;
F_39 ( V_116 , V_61 ) ;
return 0 ;
}
int F_131 ( const struct V_56 * V_57 , int V_67 , struct V_115 * V_116 )
{
const struct V_56 * V_58 ;
int V_63 , V_82 ;
F_96 (a, attr, len, rem) {
int type = F_17 ( V_58 ) ;
switch ( type ) {
case V_279 :
V_82 = F_132 ( V_58 , V_116 ) ;
if ( V_82 )
return V_82 ;
break;
case V_324 :
V_82 = F_133 ( V_58 , V_116 ) ;
if ( V_82 )
return V_82 ;
break;
case V_303 :
V_82 = F_130 ( V_58 , V_116 ) ;
if ( V_82 )
return V_82 ;
break;
case V_280 :
V_82 = F_134 ( F_19 ( V_58 ) , V_116 ) ;
if ( V_82 )
return V_82 ;
break;
default:
if ( F_47 ( V_116 , type , F_18 ( V_58 ) , F_19 ( V_58 ) ) )
return - V_118 ;
break;
}
}
return 0 ;
}
