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
static int F_52 ( struct V_125 * V_125 , struct V_1 * V_2 ,
T_2 * V_62 , const struct V_56 * * V_58 ,
bool V_5 , bool log )
{
if ( * V_62 & ( 1 << V_126 ) ) {
T_6 V_127 = F_27 ( V_58 [ V_126 ] ) ;
F_23 ( V_2 , V_128 , V_127 , V_5 ) ;
* V_62 &= ~ ( 1 << V_126 ) ;
}
if ( * V_62 & ( 1 << V_129 ) ) {
T_6 V_130 = F_27 ( V_58 [ V_129 ] ) ;
F_23 ( V_2 , V_130 , V_130 , V_5 ) ;
* V_62 &= ~ ( 1 << V_129 ) ;
}
if ( * V_62 & ( 1 << V_131 ) ) {
F_23 ( V_2 , V_132 . V_133 ,
F_27 ( V_58 [ V_131 ] ) , V_5 ) ;
* V_62 &= ~ ( 1 << V_131 ) ;
}
if ( * V_62 & ( 1 << V_28 ) ) {
T_6 V_134 = F_27 ( V_58 [ V_28 ] ) ;
if ( V_5 ) {
V_134 = 0xffffffff ;
} else if ( V_134 >= V_135 ) {
F_7 ( log , L_24 ,
V_134 , V_135 ) ;
return - V_65 ;
}
F_23 ( V_2 , V_132 . V_134 , V_134 , V_5 ) ;
* V_62 &= ~ ( 1 << V_28 ) ;
} else if ( ! V_5 ) {
F_23 ( V_2 , V_132 . V_134 , V_135 , V_5 ) ;
}
if ( * V_62 & ( 1 << V_136 ) ) {
T_7 V_137 = F_27 ( V_58 [ V_136 ] ) ;
F_23 ( V_2 , V_132 . V_138 , V_137 , V_5 ) ;
* V_62 &= ~ ( 1 << V_136 ) ;
}
if ( * V_62 & ( 1 << V_27 ) ) {
if ( F_28 ( V_58 [ V_27 ] , V_2 ,
V_5 , log ) < 0 )
return - V_65 ;
* V_62 &= ~ ( 1 << V_27 ) ;
}
if ( * V_62 & ( 1 << V_139 ) &&
F_53 ( V_125 , V_139 ) ) {
T_6 V_140 = F_27 ( V_58 [ V_139 ] ) ;
if ( V_140 & ~ V_141 ) {
F_7 ( log , L_25 ,
V_140 ) ;
return - V_65 ;
}
F_23 ( V_2 , V_142 . V_143 , V_140 , V_5 ) ;
* V_62 &= ~ ( 1ULL << V_139 ) ;
}
if ( * V_62 & ( 1 << V_144 ) &&
F_53 ( V_125 , V_144 ) ) {
T_4 V_145 = F_54 ( V_58 [ V_144 ] ) ;
F_23 ( V_2 , V_142 . V_146 , V_145 , V_5 ) ;
* V_62 &= ~ ( 1ULL << V_144 ) ;
}
if ( * V_62 & ( 1 << V_147 ) &&
F_53 ( V_125 , V_147 ) ) {
T_6 V_137 = F_27 ( V_58 [ V_147 ] ) ;
F_23 ( V_2 , V_142 . V_137 , V_137 , V_5 ) ;
* V_62 &= ~ ( 1ULL << V_147 ) ;
}
if ( * V_62 & ( 1 << V_148 ) &&
F_53 ( V_125 , V_148 ) ) {
const struct V_149 * V_150 ;
V_150 = F_19 ( V_58 [ V_148 ] ) ;
F_55 ( V_2 , V_142 . V_151 , V_150 -> V_152 ,
sizeof( * V_150 ) , V_5 ) ;
* V_62 &= ~ ( 1ULL << V_148 ) ;
}
return 0 ;
}
static int F_56 ( struct V_125 * V_125 , struct V_1 * V_2 ,
T_2 V_62 , const struct V_56 * * V_58 ,
bool V_5 , bool log )
{
int V_82 ;
V_82 = F_52 ( V_125 , V_2 , & V_62 , V_58 , V_5 , log ) ;
if ( V_82 )
return V_82 ;
if ( V_62 & ( 1 << V_14 ) ) {
const struct V_153 * V_154 ;
V_154 = F_19 ( V_58 [ V_14 ] ) ;
F_55 ( V_2 , V_31 . V_46 ,
V_154 -> V_155 , V_156 , V_5 ) ;
F_55 ( V_2 , V_31 . V_92 ,
V_154 -> V_157 , V_156 , V_5 ) ;
V_62 &= ~ ( 1 << V_14 ) ;
}
if ( V_62 & ( 1 << V_158 ) ) {
T_5 V_159 ;
V_159 = F_33 ( V_58 [ V_158 ] ) ;
if ( ! ( V_159 & F_5 ( V_160 ) ) ) {
if ( V_5 )
F_7 ( log , L_26 ) ;
else
F_7 ( log , L_27 ) ;
return - V_65 ;
}
F_23 ( V_2 , V_31 . V_159 , V_159 , V_5 ) ;
V_62 &= ~ ( 1 << V_158 ) ;
}
if ( V_62 & ( 1 << V_29 ) ) {
T_5 V_161 ;
V_161 = F_33 ( V_58 [ V_29 ] ) ;
if ( V_5 ) {
V_161 = F_5 ( 0xffff ) ;
} else if ( ! F_57 ( V_161 ) ) {
F_7 ( log , L_28 ,
F_58 ( V_161 ) , V_162 ) ;
return - V_65 ;
}
F_23 ( V_2 , V_31 . type , V_161 , V_5 ) ;
V_62 &= ~ ( 1 << V_29 ) ;
} else if ( ! V_5 ) {
F_23 ( V_2 , V_31 . type , F_5 ( V_163 ) , V_5 ) ;
}
if ( V_62 & ( 1 << V_16 ) ) {
const struct V_164 * V_165 ;
V_165 = F_19 ( V_58 [ V_16 ] ) ;
if ( ! V_5 && V_165 -> V_166 > V_167 ) {
F_7 ( log , L_29 ,
V_165 -> V_166 , V_167 ) ;
return - V_65 ;
}
F_23 ( V_2 , V_35 . V_38 ,
V_165 -> V_168 , V_5 ) ;
F_23 ( V_2 , V_35 . V_96 ,
V_165 -> V_169 , V_5 ) ;
F_23 ( V_2 , V_35 . V_77 ,
V_165 -> V_170 , V_5 ) ;
F_23 ( V_2 , V_35 . V_36 ,
V_165 -> V_166 , V_5 ) ;
F_23 ( V_2 , V_78 . V_171 . V_46 ,
V_165 -> V_172 , V_5 ) ;
F_23 ( V_2 , V_78 . V_171 . V_92 ,
V_165 -> V_173 , V_5 ) ;
V_62 &= ~ ( 1 << V_16 ) ;
}
if ( V_62 & ( 1 << V_17 ) ) {
const struct V_174 * V_175 ;
V_175 = F_19 ( V_58 [ V_17 ] ) ;
if ( ! V_5 && V_175 -> V_176 > V_167 ) {
F_7 ( log , L_30 ,
V_175 -> V_176 , V_167 ) ;
return - V_65 ;
}
if ( ! V_5 && V_175 -> V_177 & F_59 ( 0xFFF00000 ) ) {
F_7 ( log , L_31 ,
F_60 ( V_175 -> V_177 ) , ( 1 << 20 ) - 1 ) ;
return - V_65 ;
}
F_23 ( V_2 , V_79 . V_178 ,
V_175 -> V_177 , V_5 ) ;
F_23 ( V_2 , V_35 . V_38 ,
V_175 -> V_179 , V_5 ) ;
F_23 ( V_2 , V_35 . V_96 ,
V_175 -> V_180 , V_5 ) ;
F_23 ( V_2 , V_35 . V_77 ,
V_175 -> V_181 , V_5 ) ;
F_23 ( V_2 , V_35 . V_36 ,
V_175 -> V_176 , V_5 ) ;
F_55 ( V_2 , V_79 . V_171 . V_46 ,
V_175 -> V_182 ,
sizeof( V_2 -> V_30 -> V_79 . V_171 . V_46 ) ,
V_5 ) ;
F_55 ( V_2 , V_79 . V_171 . V_92 ,
V_175 -> V_183 ,
sizeof( V_2 -> V_30 -> V_79 . V_171 . V_92 ) ,
V_5 ) ;
V_62 &= ~ ( 1 << V_17 ) ;
}
if ( V_62 & ( 1 << V_24 ) ) {
const struct V_184 * V_185 ;
V_185 = F_19 ( V_58 [ V_24 ] ) ;
if ( ! V_5 && ( V_185 -> V_186 & F_5 ( 0xff00 ) ) ) {
F_7 ( log , L_32 ,
V_185 -> V_186 ) ;
return - V_65 ;
}
F_23 ( V_2 , V_78 . V_171 . V_46 ,
V_185 -> V_187 , V_5 ) ;
F_23 ( V_2 , V_78 . V_171 . V_92 ,
V_185 -> V_188 , V_5 ) ;
F_23 ( V_2 , V_35 . V_38 ,
F_58 ( V_185 -> V_186 ) , V_5 ) ;
F_55 ( V_2 , V_78 . V_189 . V_190 ,
V_185 -> V_191 , V_156 , V_5 ) ;
F_55 ( V_2 , V_78 . V_189 . V_192 ,
V_185 -> V_193 , V_156 , V_5 ) ;
V_62 &= ~ ( 1 << V_24 ) ;
}
if ( V_62 & ( 1 << V_26 ) ) {
const struct V_194 * V_195 ;
V_195 = F_19 ( V_58 [ V_26 ] ) ;
F_23 ( V_2 , V_196 . V_197 ,
V_195 -> V_198 , V_5 ) ;
V_62 &= ~ ( 1 << V_26 ) ;
}
if ( V_62 & ( 1 << V_18 ) ) {
const struct V_199 * V_200 ;
V_200 = F_19 ( V_58 [ V_18 ] ) ;
F_23 ( V_2 , V_45 . V_46 , V_200 -> V_201 , V_5 ) ;
F_23 ( V_2 , V_45 . V_92 , V_200 -> V_202 , V_5 ) ;
V_62 &= ~ ( 1 << V_18 ) ;
}
if ( V_62 & ( 1 << V_19 ) ) {
F_23 ( V_2 , V_45 . V_203 ,
F_33 ( V_58 [ V_19 ] ) ,
V_5 ) ;
V_62 &= ~ ( 1 << V_19 ) ;
}
if ( V_62 & ( 1 << V_20 ) ) {
const struct V_204 * V_205 ;
V_205 = F_19 ( V_58 [ V_20 ] ) ;
F_23 ( V_2 , V_45 . V_46 , V_205 -> V_206 , V_5 ) ;
F_23 ( V_2 , V_45 . V_92 , V_205 -> V_207 , V_5 ) ;
V_62 &= ~ ( 1 << V_20 ) ;
}
if ( V_62 & ( 1 << V_21 ) ) {
const struct V_208 * V_209 ;
V_209 = F_19 ( V_58 [ V_21 ] ) ;
F_23 ( V_2 , V_45 . V_46 , V_209 -> V_210 , V_5 ) ;
F_23 ( V_2 , V_45 . V_92 , V_209 -> V_211 , V_5 ) ;
V_62 &= ~ ( 1 << V_21 ) ;
}
if ( V_62 & ( 1 << V_22 ) ) {
const struct V_212 * V_213 ;
V_213 = F_19 ( V_58 [ V_22 ] ) ;
F_23 ( V_2 , V_45 . V_46 ,
F_5 ( V_213 -> V_214 ) , V_5 ) ;
F_23 ( V_2 , V_45 . V_92 ,
F_5 ( V_213 -> V_215 ) , V_5 ) ;
V_62 &= ~ ( 1 << V_22 ) ;
}
if ( V_62 & ( 1 << V_23 ) ) {
const struct V_216 * V_217 ;
V_217 = F_19 ( V_58 [ V_23 ] ) ;
F_23 ( V_2 , V_45 . V_46 ,
F_5 ( V_217 -> V_218 ) , V_5 ) ;
F_23 ( V_2 , V_45 . V_92 ,
F_5 ( V_217 -> V_219 ) , V_5 ) ;
V_62 &= ~ ( 1 << V_23 ) ;
}
if ( V_62 & ( 1 << V_25 ) ) {
const struct V_220 * V_221 ;
V_221 = F_19 ( V_58 [ V_25 ] ) ;
F_55 ( V_2 , V_79 . V_222 . V_223 ,
V_221 -> V_224 ,
sizeof( V_2 -> V_30 -> V_79 . V_222 . V_223 ) ,
V_5 ) ;
F_55 ( V_2 , V_79 . V_222 . V_225 ,
V_221 -> V_226 , V_156 , V_5 ) ;
F_55 ( V_2 , V_79 . V_222 . V_227 ,
V_221 -> V_228 , V_156 , V_5 ) ;
V_62 &= ~ ( 1 << V_25 ) ;
}
if ( V_62 != 0 ) {
F_7 ( log , L_33 ,
( unsigned long long ) V_62 ) ;
return - V_65 ;
}
return 0 ;
}
static void F_61 ( struct V_56 * V_57 , T_3 V_229 ,
const struct V_230 * V_231 )
{
struct V_56 * V_61 ;
int V_63 ;
F_16 (nla, attr, rem) {
if ( V_231 [ F_17 ( V_61 ) ] . V_67 == V_52 ) {
if ( V_231 [ F_17 ( V_61 ) ] . V_232 )
V_231 = V_231 [ F_17 ( V_61 ) ] . V_232 ;
F_61 ( V_61 , V_229 , V_231 ) ;
} else {
memset ( F_19 ( V_61 ) , V_229 , F_18 ( V_61 ) ) ;
}
if ( F_17 ( V_61 ) == V_139 )
* ( T_6 * ) F_19 ( V_61 ) &= V_141 ;
}
}
static void F_62 ( struct V_56 * V_57 , T_3 V_229 )
{
F_61 ( V_57 , V_229 , V_66 ) ;
}
int F_63 ( struct V_125 * V_125 , struct V_1 * V_2 ,
const struct V_56 * V_233 ,
const struct V_56 * V_234 ,
bool log )
{
const struct V_56 * V_58 [ V_64 + 1 ] ;
const struct V_56 * V_235 ;
struct V_56 * V_236 = NULL ;
T_2 V_11 = 0 ;
T_2 V_12 = 0 ;
bool V_237 = false ;
int V_82 ;
V_82 = F_21 ( V_233 , V_58 , & V_11 , log ) ;
if ( V_82 )
return V_82 ;
if ( ( V_11 & ( 1 << V_14 ) ) &&
( V_11 & ( 1 << V_29 ) ) &&
( F_33 ( V_58 [ V_29 ] ) == F_5 ( V_238 ) ) ) {
T_5 V_159 ;
if ( ! ( ( V_11 & ( 1 << V_158 ) ) &&
( V_11 & ( 1 << V_239 ) ) ) ) {
F_7 ( log , L_34 ) ;
return - V_65 ;
}
V_11 &= ~ ( 1 << V_29 ) ;
V_159 = F_33 ( V_58 [ V_158 ] ) ;
V_235 = V_58 [ V_239 ] ;
V_11 &= ~ ( 1 << V_239 ) ;
V_237 = true ;
if ( V_159 & F_5 ( V_160 ) ) {
V_82 = F_21 ( V_235 , V_58 , & V_11 , log ) ;
if ( V_82 )
return V_82 ;
} else if ( ! V_159 ) {
if ( F_18 ( V_235 ) ) {
F_7 ( log , L_35 ) ;
return - V_65 ;
}
} else {
F_7 ( log , L_36 ) ;
return - V_65 ;
}
}
V_82 = F_56 ( V_125 , V_2 , V_11 , V_58 , false , log ) ;
if ( V_82 )
return V_82 ;
if ( V_2 -> V_10 ) {
if ( ! V_234 ) {
V_236 = F_64 ( V_233 ,
F_10 ( F_18 ( V_233 ) ) ,
V_240 ) ;
if ( ! V_236 )
return - V_241 ;
F_62 ( V_236 , 0xff ) ;
if ( V_2 -> V_30 -> V_112 )
F_34 ( V_2 , V_86 ,
0xff , true ) ;
V_234 = V_236 ;
}
V_82 = F_20 ( V_234 , V_58 , & V_12 , log ) ;
if ( V_82 )
goto V_242;
F_23 ( V_2 , V_31 . V_159 , F_5 ( 0xffff ) , true ) ;
if ( V_12 & 1 << V_239 ) {
T_5 V_161 = 0 ;
T_5 V_159 = 0 ;
if ( ! V_237 ) {
F_7 ( log , L_37 ) ;
V_82 = - V_65 ;
goto V_242;
}
V_12 &= ~ ( 1 << V_239 ) ;
if ( V_58 [ V_29 ] )
V_161 = F_33 ( V_58 [ V_29 ] ) ;
if ( V_161 == F_5 ( 0xffff ) ) {
V_12 &= ~ ( 1 << V_29 ) ;
V_235 = V_58 [ V_239 ] ;
V_82 = F_20 ( V_235 , V_58 ,
& V_12 , log ) ;
if ( V_82 )
goto V_242;
} else {
F_7 ( log , L_38 ,
F_58 ( V_161 ) ) ;
V_82 = - V_65 ;
goto V_242;
}
if ( V_58 [ V_158 ] )
V_159 = F_33 ( V_58 [ V_158 ] ) ;
if ( ! ( V_159 & F_5 ( V_160 ) ) ) {
F_7 ( log , L_39 ,
F_58 ( V_159 ) ) ;
V_82 = - V_65 ;
goto V_242;
}
}
V_82 = F_56 ( V_125 , V_2 , V_12 , V_58 , true ,
log ) ;
if ( V_82 )
goto V_242;
}
if ( ! F_4 ( V_2 , V_11 , V_12 , log ) )
V_82 = - V_65 ;
V_242:
F_65 ( V_236 ) ;
return V_82 ;
}
static T_1 F_66 ( const struct V_56 * V_57 , bool log )
{
T_1 V_67 ;
if ( ! V_57 )
return 0 ;
V_67 = F_18 ( V_57 ) ;
if ( V_67 < 1 || V_67 > V_243 ) {
F_7 ( log , L_40 ,
F_18 ( V_57 ) , V_243 ) ;
return 0 ;
}
return V_67 ;
}
bool F_67 ( struct V_244 * V_245 , const struct V_56 * V_57 ,
bool log )
{
V_245 -> V_246 = F_66 ( V_57 , log ) ;
if ( V_245 -> V_246 )
memcpy ( V_245 -> V_247 , F_19 ( V_57 ) , V_245 -> V_246 ) ;
return V_245 -> V_246 ;
}
int F_68 ( struct V_244 * V_245 , const struct V_56 * V_247 ,
const struct V_248 * V_30 , bool log )
{
struct V_248 * V_249 ;
if ( F_67 ( V_245 , V_247 , log ) )
return 0 ;
V_249 = F_69 ( sizeof( * V_249 ) , V_240 ) ;
if ( ! V_249 )
return - V_241 ;
memcpy ( V_249 , V_30 , sizeof( * V_30 ) ) ;
V_245 -> V_250 = V_249 ;
return 0 ;
}
T_6 F_70 ( const struct V_56 * V_57 )
{
return V_57 ? F_27 ( V_57 ) : 0 ;
}
int F_71 ( struct V_125 * V_125 , const struct V_56 * V_57 ,
struct V_248 * V_30 ,
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
memset ( & V_30 -> V_142 , 0 , sizeof( V_30 -> V_142 ) ) ;
V_30 -> V_132 . V_134 = V_135 ;
return F_52 ( V_125 , & V_2 , & V_62 , V_58 , false , log ) ;
}
static int F_72 ( const struct V_248 * V_251 ,
const struct V_248 * V_120 , bool V_5 ,
struct V_115 * V_116 )
{
struct V_153 * V_154 ;
struct V_56 * V_61 , * V_235 ;
if ( F_38 ( V_116 , V_129 , V_120 -> V_130 ) )
goto V_252;
if ( F_38 ( V_116 , V_126 , V_120 -> V_128 ) )
goto V_252;
if ( F_38 ( V_116 , V_131 , V_120 -> V_132 . V_133 ) )
goto V_252;
if ( ( V_251 -> V_112 || V_5 ) ) {
const void * V_72 = NULL ;
if ( V_120 -> V_86 . V_80 & V_253 )
V_72 = F_73 ( V_120 , V_251 -> V_70 ) ;
if ( F_48 ( V_116 , & V_120 -> V_86 , V_72 ,
V_251 -> V_70 , V_251 -> V_112 ) )
goto V_252;
}
if ( V_251 -> V_132 . V_134 == V_135 ) {
if ( V_5 && ( V_120 -> V_132 . V_134 == 0xffff ) )
if ( F_38 ( V_116 , V_28 , 0xffffffff ) )
goto V_252;
} else {
T_4 V_254 ;
V_254 = ! V_5 ? 0 : 0xffff ;
if ( F_38 ( V_116 , V_28 ,
( V_254 << 16 ) | V_120 -> V_132 . V_134 ) )
goto V_252;
}
if ( F_38 ( V_116 , V_136 , V_120 -> V_132 . V_138 ) )
goto V_252;
if ( F_74 ( V_120 , V_116 ) )
goto V_252;
V_61 = F_75 ( V_116 , V_14 , sizeof( * V_154 ) ) ;
if ( ! V_61 )
goto V_252;
V_154 = F_19 ( V_61 ) ;
F_76 ( V_154 -> V_155 , V_120 -> V_31 . V_46 ) ;
F_76 ( V_154 -> V_157 , V_120 -> V_31 . V_92 ) ;
if ( V_251 -> V_31 . V_159 || V_251 -> V_31 . type == F_5 ( V_238 ) ) {
T_5 V_161 ;
V_161 = ! V_5 ? F_5 ( V_238 ) : F_5 ( 0xffff ) ;
if ( F_46 ( V_116 , V_29 , V_161 ) ||
F_46 ( V_116 , V_158 , V_120 -> V_31 . V_159 ) )
goto V_252;
V_235 = F_37 ( V_116 , V_239 ) ;
if ( ! V_251 -> V_31 . V_159 )
goto V_255;
} else
V_235 = NULL ;
if ( V_251 -> V_31 . type == F_5 ( V_163 ) ) {
if ( V_5 && V_120 -> V_31 . type )
if ( F_46 ( V_116 , V_29 ,
V_120 -> V_31 . type ) )
goto V_252;
goto V_255;
}
if ( F_46 ( V_116 , V_29 , V_120 -> V_31 . type ) )
goto V_252;
if ( V_251 -> V_31 . type == F_5 ( V_34 ) ) {
struct V_164 * V_165 ;
V_61 = F_75 ( V_116 , V_16 , sizeof( * V_165 ) ) ;
if ( ! V_61 )
goto V_252;
V_165 = F_19 ( V_61 ) ;
V_165 -> V_172 = V_120 -> V_78 . V_171 . V_46 ;
V_165 -> V_173 = V_120 -> V_78 . V_171 . V_92 ;
V_165 -> V_168 = V_120 -> V_35 . V_38 ;
V_165 -> V_169 = V_120 -> V_35 . V_96 ;
V_165 -> V_170 = V_120 -> V_35 . V_77 ;
V_165 -> V_166 = V_120 -> V_35 . V_36 ;
} else if ( V_251 -> V_31 . type == F_5 ( V_43 ) ) {
struct V_174 * V_175 ;
V_61 = F_75 ( V_116 , V_17 , sizeof( * V_175 ) ) ;
if ( ! V_61 )
goto V_252;
V_175 = F_19 ( V_61 ) ;
memcpy ( V_175 -> V_182 , & V_120 -> V_79 . V_171 . V_46 ,
sizeof( V_175 -> V_182 ) ) ;
memcpy ( V_175 -> V_183 , & V_120 -> V_79 . V_171 . V_92 ,
sizeof( V_175 -> V_183 ) ) ;
V_175 -> V_177 = V_120 -> V_79 . V_178 ;
V_175 -> V_179 = V_120 -> V_35 . V_38 ;
V_175 -> V_180 = V_120 -> V_35 . V_96 ;
V_175 -> V_181 = V_120 -> V_35 . V_77 ;
V_175 -> V_176 = V_120 -> V_35 . V_36 ;
} else if ( V_251 -> V_31 . type == F_5 ( V_32 ) ||
V_251 -> V_31 . type == F_5 ( V_33 ) ) {
struct V_184 * V_185 ;
V_61 = F_75 ( V_116 , V_24 , sizeof( * V_185 ) ) ;
if ( ! V_61 )
goto V_252;
V_185 = F_19 ( V_61 ) ;
memset ( V_185 , 0 , sizeof( struct V_184 ) ) ;
V_185 -> V_187 = V_120 -> V_78 . V_171 . V_46 ;
V_185 -> V_188 = V_120 -> V_78 . V_171 . V_92 ;
V_185 -> V_186 = F_5 ( V_120 -> V_35 . V_38 ) ;
F_76 ( V_185 -> V_191 , V_120 -> V_78 . V_189 . V_190 ) ;
F_76 ( V_185 -> V_193 , V_120 -> V_78 . V_189 . V_192 ) ;
} else if ( F_6 ( V_251 -> V_31 . type ) ) {
struct V_194 * V_195 ;
V_61 = F_75 ( V_116 , V_26 , sizeof( * V_195 ) ) ;
if ( ! V_61 )
goto V_252;
V_195 = F_19 ( V_61 ) ;
V_195 -> V_198 = V_120 -> V_196 . V_197 ;
}
if ( ( V_251 -> V_31 . type == F_5 ( V_34 ) ||
V_251 -> V_31 . type == F_5 ( V_43 ) ) &&
V_251 -> V_35 . V_36 != V_37 ) {
if ( V_251 -> V_35 . V_38 == V_41 ) {
struct V_199 * V_200 ;
V_61 = F_75 ( V_116 , V_18 , sizeof( * V_200 ) ) ;
if ( ! V_61 )
goto V_252;
V_200 = F_19 ( V_61 ) ;
V_200 -> V_201 = V_120 -> V_45 . V_46 ;
V_200 -> V_202 = V_120 -> V_45 . V_92 ;
if ( F_46 ( V_116 , V_19 ,
V_120 -> V_45 . V_203 ) )
goto V_252;
} else if ( V_251 -> V_35 . V_38 == V_39 ) {
struct V_204 * V_205 ;
V_61 = F_75 ( V_116 , V_20 , sizeof( * V_205 ) ) ;
if ( ! V_61 )
goto V_252;
V_205 = F_19 ( V_61 ) ;
V_205 -> V_206 = V_120 -> V_45 . V_46 ;
V_205 -> V_207 = V_120 -> V_45 . V_92 ;
} else if ( V_251 -> V_35 . V_38 == V_40 ) {
struct V_208 * V_209 ;
V_61 = F_75 ( V_116 , V_21 , sizeof( * V_209 ) ) ;
if ( ! V_61 )
goto V_252;
V_209 = F_19 ( V_61 ) ;
V_209 -> V_210 = V_120 -> V_45 . V_46 ;
V_209 -> V_211 = V_120 -> V_45 . V_92 ;
} else if ( V_251 -> V_31 . type == F_5 ( V_34 ) &&
V_251 -> V_35 . V_38 == V_42 ) {
struct V_212 * V_213 ;
V_61 = F_75 ( V_116 , V_22 , sizeof( * V_213 ) ) ;
if ( ! V_61 )
goto V_252;
V_213 = F_19 ( V_61 ) ;
V_213 -> V_214 = F_58 ( V_120 -> V_45 . V_46 ) ;
V_213 -> V_215 = F_58 ( V_120 -> V_45 . V_92 ) ;
} else if ( V_251 -> V_31 . type == F_5 ( V_43 ) &&
V_251 -> V_35 . V_38 == V_44 ) {
struct V_216 * V_217 ;
V_61 = F_75 ( V_116 , V_23 ,
sizeof( * V_217 ) ) ;
if ( ! V_61 )
goto V_252;
V_217 = F_19 ( V_61 ) ;
V_217 -> V_218 = F_58 ( V_120 -> V_45 . V_46 ) ;
V_217 -> V_219 = F_58 ( V_120 -> V_45 . V_92 ) ;
if ( V_217 -> V_218 == V_47 ||
V_217 -> V_218 == V_48 ) {
struct V_220 * V_221 ;
V_61 = F_75 ( V_116 , V_25 , sizeof( * V_221 ) ) ;
if ( ! V_61 )
goto V_252;
V_221 = F_19 ( V_61 ) ;
memcpy ( V_221 -> V_224 , & V_120 -> V_79 . V_222 . V_223 ,
sizeof( V_221 -> V_224 ) ) ;
F_76 ( V_221 -> V_226 , V_120 -> V_79 . V_222 . V_225 ) ;
F_76 ( V_221 -> V_228 , V_120 -> V_79 . V_222 . V_227 ) ;
}
}
}
V_255:
if ( V_235 )
F_39 ( V_116 , V_235 ) ;
return 0 ;
V_252:
return - V_118 ;
}
int F_77 ( const struct V_248 * V_251 ,
const struct V_248 * V_120 , int V_57 , bool V_5 ,
struct V_115 * V_116 )
{
int V_82 ;
struct V_56 * V_61 ;
V_61 = F_37 ( V_116 , V_57 ) ;
if ( ! V_61 )
return - V_118 ;
V_82 = F_72 ( V_251 , V_120 , V_5 , V_116 ) ;
if ( V_82 )
return V_82 ;
F_39 ( V_116 , V_61 ) ;
return 0 ;
}
int F_78 ( const struct V_256 * V_257 , struct V_115 * V_116 )
{
if ( F_79 ( & V_257 -> V_258 ) )
return F_47 ( V_116 , V_259 , V_257 -> V_258 . V_246 ,
V_257 -> V_258 . V_247 ) ;
return F_77 ( V_257 -> V_258 . V_250 , V_257 -> V_258 . V_250 ,
V_260 , false , V_116 ) ;
}
int F_80 ( const struct V_256 * V_257 , struct V_115 * V_116 )
{
return F_77 ( & V_257 -> V_30 , & V_257 -> V_30 ,
V_260 , false , V_116 ) ;
}
int F_81 ( const struct V_256 * V_257 , struct V_115 * V_116 )
{
return F_77 ( & V_257 -> V_30 , & V_257 -> V_10 -> V_30 ,
V_261 , true , V_116 ) ;
}
static struct V_262 * F_82 ( int V_4 , bool log )
{
struct V_262 * V_263 ;
if ( V_4 > V_264 ) {
F_7 ( log , L_41 , V_4 ) ;
return F_83 ( - V_65 ) ;
}
V_263 = F_69 ( sizeof( * V_263 ) + V_4 , V_240 ) ;
if ( ! V_263 )
return F_83 ( - V_241 ) ;
V_263 -> V_265 = 0 ;
return V_263 ;
}
static void F_84 ( const struct V_56 * V_58 )
{
const struct V_56 * V_266 = F_19 ( V_58 ) ;
struct V_267 * V_268 ;
switch ( F_17 ( V_266 ) ) {
case V_49 :
V_268 = F_19 ( V_266 ) ;
F_85 ( (struct V_269 * ) V_268 -> V_270 ) ;
break;
}
}
void F_86 ( struct V_262 * V_271 )
{
const struct V_56 * V_58 ;
int V_63 ;
if ( ! V_271 )
return;
F_87 (a, sf_acts->actions, sf_acts->actions_len, rem) {
switch ( F_17 ( V_58 ) ) {
case V_272 :
F_84 ( V_58 ) ;
break;
case V_273 :
F_88 ( V_58 ) ;
break;
}
}
F_65 ( V_271 ) ;
}
static void F_89 ( struct V_274 * V_275 )
{
F_86 ( F_90 ( V_275 , struct V_262 , V_276 ) ) ;
}
void F_91 ( struct V_262 * V_271 )
{
F_92 ( & V_271 -> V_276 , F_89 ) ;
}
static struct V_56 * F_93 ( struct V_262 * * V_263 ,
int V_50 , bool log )
{
struct V_262 * V_277 ;
int V_278 ;
int V_279 = F_94 ( V_50 ) ;
int V_280 = F_95 ( struct V_262 , V_281 ) +
( * V_263 ) -> V_265 ;
if ( V_279 <= ( F_96 ( * V_263 ) - V_280 ) )
goto V_282;
V_278 = F_96 ( * V_263 ) * 2 ;
if ( V_278 > V_264 ) {
if ( ( V_264 - V_280 ) < V_279 )
return F_83 ( - V_118 ) ;
V_278 = V_264 ;
}
V_277 = F_82 ( V_278 , log ) ;
if ( F_97 ( V_277 ) )
return ( void * ) V_277 ;
memcpy ( V_277 -> V_281 , ( * V_263 ) -> V_281 , ( * V_263 ) -> V_265 ) ;
V_277 -> V_265 = ( * V_263 ) -> V_265 ;
V_277 -> V_283 = ( * V_263 ) -> V_283 ;
F_65 ( * V_263 ) ;
* V_263 = V_277 ;
V_282:
( * V_263 ) -> V_265 += V_279 ;
return (struct V_56 * ) ( ( unsigned char * ) ( * V_263 ) + V_280 ) ;
}
static struct V_56 * F_98 ( struct V_262 * * V_263 ,
int V_284 , void * V_285 , int V_67 , bool log )
{
struct V_56 * V_58 ;
V_58 = F_93 ( V_263 , F_99 ( V_67 ) , log ) ;
if ( F_97 ( V_58 ) )
return V_58 ;
V_58 -> F_17 = V_284 ;
V_58 -> F_18 = F_99 ( V_67 ) ;
if ( V_285 )
memcpy ( F_19 ( V_58 ) , V_285 , V_67 ) ;
memset ( ( unsigned char * ) V_58 + V_58 -> F_18 , 0 , F_100 ( V_67 ) ) ;
return V_58 ;
}
int F_101 ( struct V_262 * * V_263 , int V_284 , void * V_285 ,
int V_67 , bool log )
{
struct V_56 * V_58 ;
V_58 = F_98 ( V_263 , V_284 , V_285 , V_67 , log ) ;
return F_102 ( V_58 ) ;
}
static inline int F_103 ( struct V_262 * * V_263 ,
int V_284 , bool log )
{
int V_286 = ( * V_263 ) -> V_265 ;
int V_82 ;
V_82 = F_101 ( V_263 , V_284 , NULL , 0 , log ) ;
if ( V_82 )
return V_82 ;
return V_286 ;
}
static inline void F_104 ( struct V_262 * V_263 ,
int V_287 )
{
struct V_56 * V_58 = (struct V_56 * ) ( ( unsigned char * ) V_263 -> V_281 +
V_287 ) ;
V_58 -> F_18 = V_263 -> V_265 - V_287 ;
}
static int F_105 ( struct V_125 * V_125 , const struct V_56 * V_57 ,
const struct V_248 * V_30 , int V_288 ,
struct V_262 * * V_263 ,
T_5 V_161 , T_5 V_289 , bool log )
{
const struct V_56 * V_62 [ V_290 + 1 ] ;
const struct V_56 * V_291 , * V_281 ;
const struct V_56 * V_58 ;
int V_63 , V_8 , V_82 , V_292 ;
memset ( V_62 , 0 , sizeof( V_62 ) ) ;
F_16 (a, attr, rem) {
int type = F_17 ( V_58 ) ;
if ( ! type || type > V_290 || V_62 [ type ] )
return - V_65 ;
V_62 [ type ] = V_58 ;
}
if ( V_63 )
return - V_65 ;
V_291 = V_62 [ V_293 ] ;
if ( ! V_291 || F_18 ( V_291 ) != sizeof( T_6 ) )
return - V_65 ;
V_281 = V_62 [ V_294 ] ;
if ( ! V_281 || ( F_18 ( V_281 ) && F_18 ( V_281 ) < V_295 ) )
return - V_65 ;
V_8 = F_103 ( V_263 , V_296 , log ) ;
if ( V_8 < 0 )
return V_8 ;
V_82 = F_101 ( V_263 , V_293 ,
F_19 ( V_291 ) , sizeof( T_6 ) , log ) ;
if ( V_82 )
return V_82 ;
V_292 = F_103 ( V_263 , V_294 , log ) ;
if ( V_292 < 0 )
return V_292 ;
V_82 = F_106 ( V_125 , V_281 , V_30 , V_288 + 1 , V_263 ,
V_161 , V_289 , log ) ;
if ( V_82 )
return V_82 ;
F_104 ( * V_263 , V_292 ) ;
F_104 ( * V_263 , V_8 ) ;
return 0 ;
}
void F_107 ( struct V_1 * V_2 ,
struct V_248 * V_30 ,
struct V_297 * V_10 )
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
static int F_108 ( struct V_248 * V_30 )
{
struct V_298 * V_299 ;
int V_300 = V_30 -> V_70 ;
bool V_301 = false ;
V_299 = (struct V_298 * ) F_73 ( V_30 , V_30 -> V_70 ) ;
while ( V_300 > 0 ) {
int V_67 ;
if ( V_300 < sizeof( * V_299 ) )
return - V_65 ;
V_67 = sizeof( * V_299 ) + V_299 -> V_302 * 4 ;
if ( V_67 > V_300 )
return - V_65 ;
V_301 |= ! ! ( V_299 -> type & V_303 ) ;
V_299 = (struct V_298 * ) ( ( T_3 * ) V_299 + V_67 ) ;
V_300 -= V_67 ;
} ;
V_30 -> V_86 . V_80 |= V_301 ? V_304 : 0 ;
return 0 ;
}
static int F_109 ( const struct V_56 * V_57 ,
struct V_262 * * V_263 , bool log )
{
struct V_1 V_2 ;
struct V_248 V_30 ;
struct V_305 * V_270 ;
struct V_122 * V_123 ;
struct V_267 * V_268 ;
struct V_56 * V_58 ;
int V_82 = 0 , V_8 , V_81 ;
F_107 ( & V_2 , & V_30 , NULL ) ;
V_81 = F_28 ( F_19 ( V_57 ) , & V_2 , false , log ) ;
if ( V_81 < 0 )
return V_81 ;
if ( V_30 . V_70 ) {
switch ( V_81 ) {
case V_108 :
V_82 = F_108 ( & V_30 ) ;
if ( V_82 < 0 )
return V_82 ;
break;
case V_110 :
break;
}
} ;
V_8 = F_103 ( V_263 , V_272 , log ) ;
if ( V_8 < 0 )
return V_8 ;
V_270 = F_110 ( V_30 . V_70 , V_240 ) ;
if ( ! V_270 )
return - V_241 ;
V_82 = F_111 ( & V_270 -> V_90 . V_123 . V_306 , V_240 ) ;
if ( V_82 ) {
F_85 ( (struct V_269 * ) V_270 ) ;
return V_82 ;
}
V_58 = F_98 ( V_263 , V_49 , NULL ,
sizeof( * V_268 ) , log ) ;
if ( F_97 ( V_58 ) ) {
F_85 ( (struct V_269 * ) V_270 ) ;
return F_112 ( V_58 ) ;
}
V_268 = F_19 ( V_58 ) ;
V_268 -> V_270 = V_270 ;
V_123 = & V_270 -> V_90 . V_123 ;
V_123 -> V_307 = V_308 ;
if ( V_30 . V_112 == V_113 )
V_123 -> V_307 |= V_309 ;
V_123 -> V_30 = V_30 . V_86 ;
F_113 ( V_123 ,
F_73 ( & V_30 , V_30 . V_70 ) ,
V_30 . V_70 ) ;
F_104 ( * V_263 , V_8 ) ;
return V_82 ;
}
static bool F_114 ( T_3 * V_285 , int V_67 )
{
T_3 * V_10 = V_285 + V_67 ;
while ( V_67 -- )
if ( * V_285 ++ & ~ * V_10 ++ )
return false ;
return true ;
}
static int F_115 ( const struct V_56 * V_58 ,
const struct V_248 * V_310 ,
struct V_262 * * V_263 ,
bool * V_311 , T_5 V_161 , bool V_312 , bool log )
{
const struct V_56 * V_266 = F_19 ( V_58 ) ;
int V_313 = F_17 ( V_266 ) ;
T_1 V_314 ;
if ( F_10 ( F_18 ( V_266 ) ) != F_18 ( V_58 ) )
return - V_65 ;
V_314 = F_18 ( V_266 ) ;
if ( V_312 )
V_314 /= 2 ;
if ( V_313 > V_64 ||
! F_13 ( V_314 , V_66 [ V_313 ] . V_67 ) )
return - V_65 ;
if ( V_312 && ! F_114 ( F_19 ( V_266 ) , V_314 ) )
return - V_65 ;
switch ( V_313 ) {
const struct V_164 * V_165 ;
const struct V_174 * V_175 ;
int V_82 ;
case V_131 :
case V_136 :
case V_147 :
case V_148 :
case V_14 :
break;
case V_27 :
if ( V_312 )
return - V_65 ;
* V_311 = true ;
V_82 = F_109 ( V_58 , V_263 , log ) ;
if ( V_82 )
return V_82 ;
break;
case V_16 :
if ( V_161 != F_5 ( V_34 ) )
return - V_65 ;
V_165 = F_19 ( V_266 ) ;
if ( V_312 ) {
const struct V_164 * V_10 = V_165 + 1 ;
if ( V_10 -> V_168 || V_10 -> V_166 )
return - V_65 ;
} else {
if ( V_165 -> V_168 != V_310 -> V_35 . V_38 )
return - V_65 ;
if ( V_165 -> V_166 != V_310 -> V_35 . V_36 )
return - V_65 ;
}
break;
case V_17 :
if ( V_161 != F_5 ( V_43 ) )
return - V_65 ;
V_175 = F_19 ( V_266 ) ;
if ( V_312 ) {
const struct V_174 * V_10 = V_175 + 1 ;
if ( V_10 -> V_179 || V_10 -> V_176 )
return - V_65 ;
if ( F_60 ( V_10 -> V_177 ) & 0xFFF00000 )
return - V_65 ;
} else {
if ( V_175 -> V_179 != V_310 -> V_35 . V_38 )
return - V_65 ;
if ( V_175 -> V_176 != V_310 -> V_35 . V_36 )
return - V_65 ;
}
if ( F_60 ( V_175 -> V_177 ) & 0xFFF00000 )
return - V_65 ;
break;
case V_18 :
if ( ( V_161 != F_5 ( V_34 ) &&
V_161 != F_5 ( V_43 ) ) ||
V_310 -> V_35 . V_38 != V_41 )
return - V_65 ;
break;
case V_20 :
if ( ( V_161 != F_5 ( V_34 ) &&
V_161 != F_5 ( V_43 ) ) ||
V_310 -> V_35 . V_38 != V_39 )
return - V_65 ;
break;
case V_26 :
if ( ! F_6 ( V_161 ) )
return - V_65 ;
break;
case V_21 :
if ( ( V_161 != F_5 ( V_34 ) &&
V_161 != F_5 ( V_43 ) ) ||
V_310 -> V_35 . V_38 != V_40 )
return - V_65 ;
break;
default:
return - V_65 ;
}
if ( ! V_312 && V_313 != V_27 ) {
int V_8 , V_67 = V_314 * 2 ;
struct V_56 * V_315 ;
* V_311 = true ;
V_8 = F_103 ( V_263 ,
V_316 ,
log ) ;
if ( V_8 < 0 )
return V_8 ;
V_315 = F_98 ( V_263 , V_313 , NULL , V_67 , log ) ;
if ( F_97 ( V_315 ) )
return F_112 ( V_315 ) ;
memcpy ( F_19 ( V_315 ) , F_19 ( V_266 ) , V_314 ) ;
memset ( F_19 ( V_315 ) + V_314 , 0xff , V_314 ) ;
if ( V_313 == V_17 ) {
struct V_174 * V_10 = F_19 ( V_315 ) + V_314 ;
V_10 -> V_177 &= F_59 ( 0x000FFFFF ) ;
}
F_104 ( * V_263 , V_8 ) ;
}
return 0 ;
}
static int F_116 ( const struct V_56 * V_57 )
{
static const struct V_317 V_318 [ V_319 + 1 ] = {
[ V_320 ] = { . type = V_321 } ,
[ V_322 ] = { . type = V_323 } ,
[ V_324 ] = { . type = V_321 } ,
} ;
struct V_56 * V_58 [ V_319 + 1 ] ;
int error ;
error = F_117 ( V_58 , V_319 ,
V_57 , V_318 ) ;
if ( error )
return error ;
if ( ! V_58 [ V_320 ] ||
! F_27 ( V_58 [ V_320 ] ) )
return - V_65 ;
return 0 ;
}
static int F_118 ( const struct V_56 * V_325 ,
struct V_262 * * V_263 , bool log )
{
int V_326 = F_94 ( V_325 -> F_18 ) ;
struct V_56 * V_327 ;
V_327 = F_93 ( V_263 , V_325 -> F_18 , log ) ;
if ( F_97 ( V_327 ) )
return F_112 ( V_327 ) ;
memcpy ( V_327 , V_325 , V_326 ) ;
return 0 ;
}
static int F_106 ( struct V_125 * V_125 , const struct V_56 * V_57 ,
const struct V_248 * V_30 ,
int V_288 , struct V_262 * * V_263 ,
T_5 V_161 , T_5 V_289 , bool log )
{
const struct V_56 * V_58 ;
int V_63 , V_82 ;
if ( V_288 >= V_328 )
return - V_329 ;
F_16 (a, attr, rem) {
static const T_6 V_330 [ V_331 + 1 ] = {
[ V_332 ] = sizeof( T_6 ) ,
[ V_333 ] = sizeof( T_6 ) ,
[ V_334 ] = ( T_6 ) - 1 ,
[ V_335 ] = sizeof( struct V_336 ) ,
[ V_337 ] = sizeof( T_5 ) ,
[ V_338 ] = sizeof( struct V_339 ) ,
[ V_340 ] = 0 ,
[ V_272 ] = ( T_6 ) - 1 ,
[ V_341 ] = ( T_6 ) - 1 ,
[ V_296 ] = ( T_6 ) - 1 ,
[ V_342 ] = sizeof( struct V_343 ) ,
[ V_273 ] = ( T_6 ) - 1 ,
[ V_344 ] = sizeof( struct V_345 ) ,
} ;
const struct V_339 * V_346 ;
int type = F_17 ( V_58 ) ;
bool V_311 ;
if ( type > V_331 ||
( V_330 [ type ] != F_18 ( V_58 ) &&
V_330 [ type ] != ( T_6 ) - 1 ) )
return - V_65 ;
V_311 = false ;
switch ( type ) {
case V_347 :
return - V_65 ;
case V_334 :
V_82 = F_116 ( V_58 ) ;
if ( V_82 )
return V_82 ;
break;
case V_332 :
if ( F_27 ( V_58 ) >= V_135 )
return - V_65 ;
break;
case V_344 : {
const struct V_345 * V_348 = F_19 ( V_58 ) ;
if ( V_348 -> V_349 < V_350 )
return - V_65 ;
break;
}
case V_342 : {
const struct V_343 * V_351 = F_19 ( V_58 ) ;
switch ( V_351 -> V_352 ) {
case V_353 :
break;
default:
return - V_65 ;
}
break;
}
case V_340 :
V_289 = F_5 ( 0 ) ;
break;
case V_338 :
V_346 = F_19 ( V_58 ) ;
if ( V_346 -> V_354 != F_5 ( V_238 ) )
return - V_65 ;
if ( ! ( V_346 -> V_289 & F_5 ( V_160 ) ) )
return - V_65 ;
V_289 = V_346 -> V_289 ;
break;
case V_333 :
break;
case V_335 : {
const struct V_336 * V_196 = F_19 ( V_58 ) ;
if ( ! F_6 ( V_196 -> V_355 ) )
return - V_65 ;
if ( V_289 & F_5 ( V_160 ) ||
( V_161 != F_5 ( V_34 ) &&
V_161 != F_5 ( V_43 ) &&
V_161 != F_5 ( V_32 ) &&
V_161 != F_5 ( V_33 ) &&
! F_6 ( V_161 ) ) )
return - V_65 ;
V_161 = V_196 -> V_355 ;
break;
}
case V_337 :
if ( V_289 & F_5 ( V_160 ) ||
! F_6 ( V_161 ) )
return - V_65 ;
V_161 = F_5 ( 0 ) ;
break;
case V_272 :
V_82 = F_115 ( V_58 , V_30 , V_263 ,
& V_311 , V_161 , false , log ) ;
if ( V_82 )
return V_82 ;
break;
case V_341 :
V_82 = F_115 ( V_58 , V_30 , V_263 ,
& V_311 , V_161 , true , log ) ;
if ( V_82 )
return V_82 ;
break;
case V_296 :
V_82 = F_105 ( V_125 , V_58 , V_30 , V_288 , V_263 ,
V_161 , V_289 , log ) ;
if ( V_82 )
return V_82 ;
V_311 = true ;
break;
case V_273 :
V_82 = F_119 ( V_125 , V_58 , V_30 , V_263 , log ) ;
if ( V_82 )
return V_82 ;
V_311 = true ;
break;
default:
F_7 ( log , L_42 , type ) ;
return - V_65 ;
}
if ( ! V_311 ) {
V_82 = F_118 ( V_58 , V_263 , log ) ;
if ( V_82 )
return V_82 ;
}
}
if ( V_63 > 0 )
return - V_65 ;
return 0 ;
}
int F_120 ( struct V_125 * V_125 , const struct V_56 * V_57 ,
const struct V_248 * V_30 ,
struct V_262 * * V_263 , bool log )
{
int V_82 ;
* V_263 = F_82 ( F_18 ( V_57 ) , log ) ;
if ( F_97 ( * V_263 ) )
return F_112 ( * V_263 ) ;
( * V_263 ) -> V_283 = F_18 ( V_57 ) ;
V_82 = F_106 ( V_125 , V_57 , V_30 , 0 , V_263 , V_30 -> V_31 . type ,
V_30 -> V_31 . V_159 , log ) ;
if ( V_82 )
F_86 ( * V_263 ) ;
return V_82 ;
}
static int F_121 ( const struct V_56 * V_57 , struct V_115 * V_116 )
{
const struct V_56 * V_58 ;
struct V_56 * V_8 ;
int V_82 = 0 , V_63 ;
V_8 = F_37 ( V_116 , V_296 ) ;
if ( ! V_8 )
return - V_118 ;
F_16 (a, attr, rem) {
int type = F_17 ( V_58 ) ;
struct V_56 * V_356 ;
switch ( type ) {
case V_293 :
if ( F_47 ( V_116 , V_293 ,
sizeof( T_6 ) , F_19 ( V_58 ) ) )
return - V_118 ;
break;
case V_294 :
V_356 = F_37 ( V_116 , V_294 ) ;
if ( ! V_356 )
return - V_118 ;
V_82 = F_122 ( F_19 ( V_58 ) , F_18 ( V_58 ) , V_116 ) ;
if ( V_82 )
return V_82 ;
F_39 ( V_116 , V_356 ) ;
break;
}
}
F_39 ( V_116 , V_8 ) ;
return V_82 ;
}
static int F_123 ( const struct V_56 * V_58 , struct V_115 * V_116 )
{
const struct V_56 * V_266 = F_19 ( V_58 ) ;
int V_313 = F_17 ( V_266 ) ;
struct V_56 * V_8 ;
int V_82 ;
switch ( V_313 ) {
case V_49 : {
struct V_267 * V_268 = F_19 ( V_266 ) ;
struct V_122 * V_123 = & V_268 -> V_270 -> V_90 . V_123 ;
V_8 = F_37 ( V_116 , V_272 ) ;
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
if ( F_47 ( V_116 , V_272 , F_18 ( V_58 ) , V_266 ) )
return - V_118 ;
break;
}
return 0 ;
}
static int F_124 ( const struct V_56 * V_58 ,
struct V_115 * V_116 )
{
const struct V_56 * V_266 = F_19 ( V_58 ) ;
struct V_56 * V_61 ;
T_1 V_314 = F_18 ( V_266 ) / 2 ;
V_61 = F_37 ( V_116 , V_272 ) ;
if ( ! V_61 )
return - V_118 ;
if ( F_47 ( V_116 , F_17 ( V_266 ) , V_314 , F_19 ( V_266 ) ) )
return - V_118 ;
F_39 ( V_116 , V_61 ) ;
return 0 ;
}
int F_122 ( const struct V_56 * V_57 , int V_67 , struct V_115 * V_116 )
{
const struct V_56 * V_58 ;
int V_63 , V_82 ;
F_87 (a, attr, len, rem) {
int type = F_17 ( V_58 ) ;
switch ( type ) {
case V_272 :
V_82 = F_123 ( V_58 , V_116 ) ;
if ( V_82 )
return V_82 ;
break;
case V_316 :
V_82 = F_124 ( V_58 , V_116 ) ;
if ( V_82 )
return V_82 ;
break;
case V_296 :
V_82 = F_121 ( V_58 , V_116 ) ;
if ( V_82 )
return V_82 ;
break;
case V_273 :
V_82 = F_125 ( F_19 ( V_58 ) , V_116 ) ;
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
