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
+ F_9 ( 16 )
+ F_9 ( 16 )
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
bool V_77 = false , V_78 = false , V_79 = false ;
T_5 V_80 = 0 ;
int V_81 = 0 ;
struct V_56 * V_58 ;
int V_63 ;
F_15 (a, attr, rem) {
int type = F_16 ( V_58 ) ;
int V_82 ;
if ( type > V_83 ) {
F_7 ( log , L_14 ,
type , V_83 ) ;
return - V_65 ;
}
if ( ! F_12 ( F_17 ( V_58 ) ,
V_84 [ type ] . V_67 ) ) {
F_7 ( log , L_15 ,
type , F_17 ( V_58 ) , V_84 [ type ] . V_67 ) ;
return - V_65 ;
}
switch ( type ) {
case V_85 :
F_22 ( V_2 , V_86 . V_87 ,
F_28 ( V_58 ) , V_5 ) ;
V_80 |= V_88 ;
break;
case V_89 :
F_22 ( V_2 , V_86 . V_90 . V_78 . V_46 ,
F_29 ( V_58 ) , V_5 ) ;
V_78 = true ;
break;
case V_91 :
F_22 ( V_2 , V_86 . V_90 . V_78 . V_92 ,
F_29 ( V_58 ) , V_5 ) ;
V_78 = true ;
break;
case V_93 :
F_22 ( V_2 , V_86 . V_90 . V_79 . V_92 ,
F_30 ( V_58 ) , V_5 ) ;
V_79 = true ;
break;
case V_94 :
F_22 ( V_2 , V_86 . V_90 . V_79 . V_92 ,
F_30 ( V_58 ) , V_5 ) ;
V_79 = true ;
break;
case V_95 :
F_22 ( V_2 , V_86 . V_96 ,
F_31 ( V_58 ) , V_5 ) ;
break;
case V_97 :
F_22 ( V_2 , V_86 . V_77 ,
F_31 ( V_58 ) , V_5 ) ;
V_77 = true ;
break;
case V_98 :
V_80 |= V_99 ;
break;
case V_100 :
V_80 |= V_101 ;
break;
case V_102 :
F_22 ( V_2 , V_86 . V_103 ,
F_32 ( V_58 ) , V_5 ) ;
break;
case V_104 :
F_22 ( V_2 , V_86 . V_105 ,
F_32 ( V_58 ) , V_5 ) ;
break;
case V_106 :
V_80 |= V_107 ;
break;
case V_108 :
if ( V_81 ) {
F_7 ( log , L_16 ) ;
return - V_65 ;
}
V_82 = F_21 ( V_58 , V_2 , V_5 , log ) ;
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
V_82 = F_25 ( V_58 , V_2 , V_5 , log ) ;
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
F_22 ( V_2 , V_86 . V_80 , V_80 , V_5 ) ;
if ( V_5 )
F_33 ( V_2 , V_112 , 0xff , true ) ;
else
F_22 ( V_2 , V_112 , V_79 ? V_113 : V_114 ,
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
if ( V_79 && F_34 ( & V_2 -> V_30 -> V_86 . V_90 . V_79 . V_92 ) ) {
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
static int F_35 ( struct V_115 * V_116 ,
const void * V_69 , int V_117 )
{
const struct V_71 * V_72 = V_69 ;
struct V_56 * V_61 ;
V_61 = F_36 ( V_116 , V_110 ) ;
if ( ! V_61 )
return - V_118 ;
if ( F_37 ( V_116 , V_75 , V_72 -> V_76 ) < 0 )
return - V_118 ;
F_38 ( V_116 , V_61 ) ;
return 0 ;
}
static int F_39 ( struct V_115 * V_116 ,
const struct V_119 * V_120 ,
const void * V_69 , int V_117 ,
unsigned short V_112 )
{
if ( V_120 -> V_80 & V_88 &&
F_40 ( V_116 , V_85 , V_120 -> V_87 ) )
return - V_118 ;
switch ( V_112 ) {
case V_114 :
if ( V_120 -> V_90 . V_78 . V_46 &&
F_41 ( V_116 , V_89 ,
V_120 -> V_90 . V_78 . V_46 ) )
return - V_118 ;
if ( V_120 -> V_90 . V_78 . V_92 &&
F_41 ( V_116 , V_91 ,
V_120 -> V_90 . V_78 . V_92 ) )
return - V_118 ;
break;
case V_113 :
if ( ! F_34 ( & V_120 -> V_90 . V_79 . V_46 ) &&
F_42 ( V_116 , V_93 ,
& V_120 -> V_90 . V_79 . V_46 ) )
return - V_118 ;
if ( ! F_34 ( & V_120 -> V_90 . V_79 . V_92 ) &&
F_42 ( V_116 , V_94 ,
& V_120 -> V_90 . V_79 . V_92 ) )
return - V_118 ;
break;
}
if ( V_120 -> V_96 &&
F_43 ( V_116 , V_95 , V_120 -> V_96 ) )
return - V_118 ;
if ( F_43 ( V_116 , V_97 , V_120 -> V_77 ) )
return - V_118 ;
if ( ( V_120 -> V_80 & V_99 ) &&
F_44 ( V_116 , V_98 ) )
return - V_118 ;
if ( ( V_120 -> V_80 & V_101 ) &&
F_44 ( V_116 , V_100 ) )
return - V_118 ;
if ( V_120 -> V_103 &&
F_45 ( V_116 , V_102 , V_120 -> V_103 ) )
return - V_118 ;
if ( V_120 -> V_105 &&
F_45 ( V_116 , V_104 , V_120 -> V_105 ) )
return - V_118 ;
if ( ( V_120 -> V_80 & V_107 ) &&
F_44 ( V_116 , V_106 ) )
return - V_118 ;
if ( V_117 ) {
if ( V_120 -> V_80 & V_109 &&
F_46 ( V_116 , V_108 ,
V_117 , V_69 ) )
return - V_118 ;
else if ( V_120 -> V_80 & V_111 &&
F_35 ( V_116 , V_69 , V_117 ) )
return - V_118 ;
}
return 0 ;
}
static int F_47 ( struct V_115 * V_116 ,
const struct V_119 * V_120 ,
const void * V_69 , int V_117 ,
unsigned short V_112 )
{
struct V_56 * V_61 ;
int V_82 ;
V_61 = F_36 ( V_116 , V_27 ) ;
if ( ! V_61 )
return - V_118 ;
V_82 = F_39 ( V_116 , V_120 , V_69 , V_117 ,
V_112 ) ;
if ( V_82 )
return V_82 ;
F_38 ( V_116 , V_61 ) ;
return 0 ;
}
int F_48 ( struct V_115 * V_116 ,
struct V_121 * V_122 )
{
return F_39 ( V_116 , & V_122 -> V_30 ,
F_49 ( V_122 ) ,
V_122 -> V_123 ,
F_50 ( V_122 ) ) ;
}
static int F_51 ( struct V_124 * V_124 , struct V_1 * V_2 ,
T_2 * V_62 , const struct V_56 * * V_58 ,
bool V_5 , bool log )
{
if ( * V_62 & ( 1 << V_125 ) ) {
T_6 V_126 = F_26 ( V_58 [ V_125 ] ) ;
F_22 ( V_2 , V_127 , V_126 , V_5 ) ;
* V_62 &= ~ ( 1 << V_125 ) ;
}
if ( * V_62 & ( 1 << V_128 ) ) {
T_6 V_129 = F_26 ( V_58 [ V_128 ] ) ;
F_22 ( V_2 , V_129 , V_129 , V_5 ) ;
* V_62 &= ~ ( 1 << V_128 ) ;
}
if ( * V_62 & ( 1 << V_130 ) ) {
F_22 ( V_2 , V_131 . V_132 ,
F_26 ( V_58 [ V_130 ] ) , V_5 ) ;
* V_62 &= ~ ( 1 << V_130 ) ;
}
if ( * V_62 & ( 1 << V_28 ) ) {
T_6 V_133 = F_26 ( V_58 [ V_28 ] ) ;
if ( V_5 ) {
V_133 = 0xffffffff ;
} else if ( V_133 >= V_134 ) {
F_7 ( log , L_24 ,
V_133 , V_134 ) ;
return - V_65 ;
}
F_22 ( V_2 , V_131 . V_133 , V_133 , V_5 ) ;
* V_62 &= ~ ( 1 << V_28 ) ;
} else if ( ! V_5 ) {
F_22 ( V_2 , V_131 . V_133 , V_134 , V_5 ) ;
}
if ( * V_62 & ( 1 << V_135 ) ) {
T_7 V_136 = F_26 ( V_58 [ V_135 ] ) ;
F_22 ( V_2 , V_131 . V_137 , V_136 , V_5 ) ;
* V_62 &= ~ ( 1 << V_135 ) ;
}
if ( * V_62 & ( 1 << V_27 ) ) {
if ( F_27 ( V_58 [ V_27 ] , V_2 ,
V_5 , log ) < 0 )
return - V_65 ;
* V_62 &= ~ ( 1 << V_27 ) ;
}
if ( * V_62 & ( 1 << V_138 ) &&
F_52 ( V_124 , V_138 ) ) {
T_6 V_139 = F_26 ( V_58 [ V_138 ] ) ;
if ( V_139 & ~ V_140 ) {
F_7 ( log , L_25 ,
V_139 ) ;
return - V_65 ;
}
F_22 ( V_2 , V_141 . V_142 , V_139 , V_5 ) ;
* V_62 &= ~ ( 1ULL << V_138 ) ;
}
if ( * V_62 & ( 1 << V_143 ) &&
F_52 ( V_124 , V_143 ) ) {
T_4 V_144 = F_53 ( V_58 [ V_143 ] ) ;
F_22 ( V_2 , V_141 . V_145 , V_144 , V_5 ) ;
* V_62 &= ~ ( 1ULL << V_143 ) ;
}
if ( * V_62 & ( 1 << V_146 ) &&
F_52 ( V_124 , V_146 ) ) {
T_6 V_136 = F_26 ( V_58 [ V_146 ] ) ;
F_22 ( V_2 , V_141 . V_136 , V_136 , V_5 ) ;
* V_62 &= ~ ( 1ULL << V_146 ) ;
}
if ( * V_62 & ( 1 << V_147 ) &&
F_52 ( V_124 , V_147 ) ) {
const struct V_148 * V_149 ;
V_149 = F_18 ( V_58 [ V_147 ] ) ;
F_54 ( V_2 , V_141 . V_150 , V_149 -> V_151 ,
sizeof( * V_149 ) , V_5 ) ;
* V_62 &= ~ ( 1ULL << V_147 ) ;
}
return 0 ;
}
static int F_55 ( struct V_124 * V_124 , struct V_1 * V_2 ,
T_2 V_62 , const struct V_56 * * V_58 ,
bool V_5 , bool log )
{
int V_82 ;
V_82 = F_51 ( V_124 , V_2 , & V_62 , V_58 , V_5 , log ) ;
if ( V_82 )
return V_82 ;
if ( V_62 & ( 1 << V_14 ) ) {
const struct V_152 * V_153 ;
V_153 = F_18 ( V_58 [ V_14 ] ) ;
F_54 ( V_2 , V_31 . V_46 ,
V_153 -> V_154 , V_155 , V_5 ) ;
F_54 ( V_2 , V_31 . V_92 ,
V_153 -> V_156 , V_155 , V_5 ) ;
V_62 &= ~ ( 1 << V_14 ) ;
}
if ( V_62 & ( 1 << V_157 ) ) {
T_5 V_158 ;
V_158 = F_32 ( V_58 [ V_157 ] ) ;
if ( ! ( V_158 & F_5 ( V_159 ) ) ) {
if ( V_5 )
F_7 ( log , L_26 ) ;
else
F_7 ( log , L_27 ) ;
return - V_65 ;
}
F_22 ( V_2 , V_31 . V_158 , V_158 , V_5 ) ;
V_62 &= ~ ( 1 << V_157 ) ;
}
if ( V_62 & ( 1 << V_29 ) ) {
T_5 V_160 ;
V_160 = F_32 ( V_58 [ V_29 ] ) ;
if ( V_5 ) {
V_160 = F_5 ( 0xffff ) ;
} else if ( ! F_56 ( V_160 ) ) {
F_7 ( log , L_28 ,
F_57 ( V_160 ) , V_161 ) ;
return - V_65 ;
}
F_22 ( V_2 , V_31 . type , V_160 , V_5 ) ;
V_62 &= ~ ( 1 << V_29 ) ;
} else if ( ! V_5 ) {
F_22 ( V_2 , V_31 . type , F_5 ( V_162 ) , V_5 ) ;
}
if ( V_62 & ( 1 << V_16 ) ) {
const struct V_163 * V_164 ;
V_164 = F_18 ( V_58 [ V_16 ] ) ;
if ( ! V_5 && V_164 -> V_165 > V_166 ) {
F_7 ( log , L_29 ,
V_164 -> V_165 , V_166 ) ;
return - V_65 ;
}
F_22 ( V_2 , V_35 . V_38 ,
V_164 -> V_167 , V_5 ) ;
F_22 ( V_2 , V_35 . V_96 ,
V_164 -> V_168 , V_5 ) ;
F_22 ( V_2 , V_35 . V_77 ,
V_164 -> V_169 , V_5 ) ;
F_22 ( V_2 , V_35 . V_36 ,
V_164 -> V_165 , V_5 ) ;
F_22 ( V_2 , V_78 . V_170 . V_46 ,
V_164 -> V_171 , V_5 ) ;
F_22 ( V_2 , V_78 . V_170 . V_92 ,
V_164 -> V_172 , V_5 ) ;
V_62 &= ~ ( 1 << V_16 ) ;
}
if ( V_62 & ( 1 << V_17 ) ) {
const struct V_173 * V_174 ;
V_174 = F_18 ( V_58 [ V_17 ] ) ;
if ( ! V_5 && V_174 -> V_175 > V_166 ) {
F_7 ( log , L_30 ,
V_174 -> V_175 , V_166 ) ;
return - V_65 ;
}
if ( ! V_5 && V_174 -> V_176 & F_58 ( 0xFFF00000 ) ) {
F_7 ( log , L_31 ,
F_59 ( V_174 -> V_176 ) , ( 1 << 20 ) - 1 ) ;
return - V_65 ;
}
F_22 ( V_2 , V_79 . V_177 ,
V_174 -> V_176 , V_5 ) ;
F_22 ( V_2 , V_35 . V_38 ,
V_174 -> V_178 , V_5 ) ;
F_22 ( V_2 , V_35 . V_96 ,
V_174 -> V_179 , V_5 ) ;
F_22 ( V_2 , V_35 . V_77 ,
V_174 -> V_180 , V_5 ) ;
F_22 ( V_2 , V_35 . V_36 ,
V_174 -> V_175 , V_5 ) ;
F_54 ( V_2 , V_79 . V_170 . V_46 ,
V_174 -> V_181 ,
sizeof( V_2 -> V_30 -> V_79 . V_170 . V_46 ) ,
V_5 ) ;
F_54 ( V_2 , V_79 . V_170 . V_92 ,
V_174 -> V_182 ,
sizeof( V_2 -> V_30 -> V_79 . V_170 . V_92 ) ,
V_5 ) ;
V_62 &= ~ ( 1 << V_17 ) ;
}
if ( V_62 & ( 1 << V_24 ) ) {
const struct V_183 * V_184 ;
V_184 = F_18 ( V_58 [ V_24 ] ) ;
if ( ! V_5 && ( V_184 -> V_185 & F_5 ( 0xff00 ) ) ) {
F_7 ( log , L_32 ,
V_184 -> V_185 ) ;
return - V_65 ;
}
F_22 ( V_2 , V_78 . V_170 . V_46 ,
V_184 -> V_186 , V_5 ) ;
F_22 ( V_2 , V_78 . V_170 . V_92 ,
V_184 -> V_187 , V_5 ) ;
F_22 ( V_2 , V_35 . V_38 ,
F_57 ( V_184 -> V_185 ) , V_5 ) ;
F_54 ( V_2 , V_78 . V_188 . V_189 ,
V_184 -> V_190 , V_155 , V_5 ) ;
F_54 ( V_2 , V_78 . V_188 . V_191 ,
V_184 -> V_192 , V_155 , V_5 ) ;
V_62 &= ~ ( 1 << V_24 ) ;
}
if ( V_62 & ( 1 << V_26 ) ) {
const struct V_193 * V_194 ;
V_194 = F_18 ( V_58 [ V_26 ] ) ;
F_22 ( V_2 , V_195 . V_196 ,
V_194 -> V_197 , V_5 ) ;
V_62 &= ~ ( 1 << V_26 ) ;
}
if ( V_62 & ( 1 << V_18 ) ) {
const struct V_198 * V_199 ;
V_199 = F_18 ( V_58 [ V_18 ] ) ;
F_22 ( V_2 , V_45 . V_46 , V_199 -> V_200 , V_5 ) ;
F_22 ( V_2 , V_45 . V_92 , V_199 -> V_201 , V_5 ) ;
V_62 &= ~ ( 1 << V_18 ) ;
}
if ( V_62 & ( 1 << V_19 ) ) {
F_22 ( V_2 , V_45 . V_202 ,
F_32 ( V_58 [ V_19 ] ) ,
V_5 ) ;
V_62 &= ~ ( 1 << V_19 ) ;
}
if ( V_62 & ( 1 << V_20 ) ) {
const struct V_203 * V_204 ;
V_204 = F_18 ( V_58 [ V_20 ] ) ;
F_22 ( V_2 , V_45 . V_46 , V_204 -> V_205 , V_5 ) ;
F_22 ( V_2 , V_45 . V_92 , V_204 -> V_206 , V_5 ) ;
V_62 &= ~ ( 1 << V_20 ) ;
}
if ( V_62 & ( 1 << V_21 ) ) {
const struct V_207 * V_208 ;
V_208 = F_18 ( V_58 [ V_21 ] ) ;
F_22 ( V_2 , V_45 . V_46 , V_208 -> V_209 , V_5 ) ;
F_22 ( V_2 , V_45 . V_92 , V_208 -> V_210 , V_5 ) ;
V_62 &= ~ ( 1 << V_21 ) ;
}
if ( V_62 & ( 1 << V_22 ) ) {
const struct V_211 * V_212 ;
V_212 = F_18 ( V_58 [ V_22 ] ) ;
F_22 ( V_2 , V_45 . V_46 ,
F_5 ( V_212 -> V_213 ) , V_5 ) ;
F_22 ( V_2 , V_45 . V_92 ,
F_5 ( V_212 -> V_214 ) , V_5 ) ;
V_62 &= ~ ( 1 << V_22 ) ;
}
if ( V_62 & ( 1 << V_23 ) ) {
const struct V_215 * V_216 ;
V_216 = F_18 ( V_58 [ V_23 ] ) ;
F_22 ( V_2 , V_45 . V_46 ,
F_5 ( V_216 -> V_217 ) , V_5 ) ;
F_22 ( V_2 , V_45 . V_92 ,
F_5 ( V_216 -> V_218 ) , V_5 ) ;
V_62 &= ~ ( 1 << V_23 ) ;
}
if ( V_62 & ( 1 << V_25 ) ) {
const struct V_219 * V_220 ;
V_220 = F_18 ( V_58 [ V_25 ] ) ;
F_54 ( V_2 , V_79 . V_221 . V_222 ,
V_220 -> V_223 ,
sizeof( V_2 -> V_30 -> V_79 . V_221 . V_222 ) ,
V_5 ) ;
F_54 ( V_2 , V_79 . V_221 . V_224 ,
V_220 -> V_225 , V_155 , V_5 ) ;
F_54 ( V_2 , V_79 . V_221 . V_226 ,
V_220 -> V_227 , V_155 , V_5 ) ;
V_62 &= ~ ( 1 << V_25 ) ;
}
if ( V_62 != 0 ) {
F_7 ( log , L_33 ,
( unsigned long long ) V_62 ) ;
return - V_65 ;
}
return 0 ;
}
static void F_60 ( struct V_56 * V_57 , T_3 V_228 ,
const struct V_229 * V_230 )
{
struct V_56 * V_61 ;
int V_63 ;
F_15 (nla, attr, rem) {
if ( V_230 [ F_16 ( V_61 ) ] . V_67 == V_52 ) {
if ( V_230 [ F_16 ( V_61 ) ] . V_231 )
V_230 = V_230 [ F_16 ( V_61 ) ] . V_231 ;
F_60 ( V_61 , V_228 , V_230 ) ;
} else {
memset ( F_18 ( V_61 ) , V_228 , F_17 ( V_61 ) ) ;
}
if ( F_16 ( V_61 ) == V_138 )
* ( T_6 * ) F_18 ( V_61 ) &= V_140 ;
}
}
static void F_61 ( struct V_56 * V_57 , T_3 V_228 )
{
F_60 ( V_57 , V_228 , V_66 ) ;
}
int F_62 ( struct V_124 * V_124 , struct V_1 * V_2 ,
const struct V_56 * V_232 ,
const struct V_56 * V_233 ,
bool log )
{
const struct V_56 * V_58 [ V_64 + 1 ] ;
const struct V_56 * V_234 ;
struct V_56 * V_235 = NULL ;
T_2 V_11 = 0 ;
T_2 V_12 = 0 ;
bool V_236 = false ;
int V_82 ;
V_82 = F_20 ( V_232 , V_58 , & V_11 , log ) ;
if ( V_82 )
return V_82 ;
if ( ( V_11 & ( 1 << V_14 ) ) &&
( V_11 & ( 1 << V_29 ) ) &&
( F_32 ( V_58 [ V_29 ] ) == F_5 ( V_237 ) ) ) {
T_5 V_158 ;
if ( ! ( ( V_11 & ( 1 << V_157 ) ) &&
( V_11 & ( 1 << V_238 ) ) ) ) {
F_7 ( log , L_34 ) ;
return - V_65 ;
}
V_11 &= ~ ( 1 << V_29 ) ;
V_158 = F_32 ( V_58 [ V_157 ] ) ;
V_234 = V_58 [ V_238 ] ;
V_11 &= ~ ( 1 << V_238 ) ;
V_236 = true ;
if ( V_158 & F_5 ( V_159 ) ) {
V_82 = F_20 ( V_234 , V_58 , & V_11 , log ) ;
if ( V_82 )
return V_82 ;
} else if ( ! V_158 ) {
if ( F_17 ( V_234 ) ) {
F_7 ( log , L_35 ) ;
return - V_65 ;
}
} else {
F_7 ( log , L_36 ) ;
return - V_65 ;
}
}
V_82 = F_55 ( V_124 , V_2 , V_11 , V_58 , false , log ) ;
if ( V_82 )
return V_82 ;
if ( V_2 -> V_10 ) {
if ( ! V_233 ) {
V_235 = F_63 ( V_232 ,
F_9 ( F_17 ( V_232 ) ) ,
V_239 ) ;
if ( ! V_235 )
return - V_240 ;
F_61 ( V_235 , 0xff ) ;
if ( V_2 -> V_30 -> V_112 )
F_33 ( V_2 , V_86 ,
0xff , true ) ;
V_233 = V_235 ;
}
V_82 = F_19 ( V_233 , V_58 , & V_12 , log ) ;
if ( V_82 )
goto V_241;
F_22 ( V_2 , V_31 . V_158 , F_5 ( 0xffff ) , true ) ;
if ( V_12 & 1 << V_238 ) {
T_5 V_160 = 0 ;
T_5 V_158 = 0 ;
if ( ! V_236 ) {
F_7 ( log , L_37 ) ;
V_82 = - V_65 ;
goto V_241;
}
V_12 &= ~ ( 1 << V_238 ) ;
if ( V_58 [ V_29 ] )
V_160 = F_32 ( V_58 [ V_29 ] ) ;
if ( V_160 == F_5 ( 0xffff ) ) {
V_12 &= ~ ( 1 << V_29 ) ;
V_234 = V_58 [ V_238 ] ;
V_82 = F_19 ( V_234 , V_58 ,
& V_12 , log ) ;
if ( V_82 )
goto V_241;
} else {
F_7 ( log , L_38 ,
F_57 ( V_160 ) ) ;
V_82 = - V_65 ;
goto V_241;
}
if ( V_58 [ V_157 ] )
V_158 = F_32 ( V_58 [ V_157 ] ) ;
if ( ! ( V_158 & F_5 ( V_159 ) ) ) {
F_7 ( log , L_39 ,
F_57 ( V_158 ) ) ;
V_82 = - V_65 ;
goto V_241;
}
}
V_82 = F_55 ( V_124 , V_2 , V_12 , V_58 , true ,
log ) ;
if ( V_82 )
goto V_241;
}
if ( ! F_4 ( V_2 , V_11 , V_12 , log ) )
V_82 = - V_65 ;
V_241:
F_64 ( V_235 ) ;
return V_82 ;
}
static T_1 F_65 ( const struct V_56 * V_57 , bool log )
{
T_1 V_67 ;
if ( ! V_57 )
return 0 ;
V_67 = F_17 ( V_57 ) ;
if ( V_67 < 1 || V_67 > V_242 ) {
F_7 ( log , L_40 ,
F_17 ( V_57 ) , V_242 ) ;
return 0 ;
}
return V_67 ;
}
bool F_66 ( struct V_243 * V_244 , const struct V_56 * V_57 ,
bool log )
{
V_244 -> V_245 = F_65 ( V_57 , log ) ;
if ( V_244 -> V_245 )
memcpy ( V_244 -> V_246 , F_18 ( V_57 ) , V_244 -> V_245 ) ;
return V_244 -> V_245 ;
}
int F_67 ( struct V_243 * V_244 , const struct V_56 * V_246 ,
const struct V_247 * V_30 , bool log )
{
struct V_247 * V_248 ;
if ( F_66 ( V_244 , V_246 , log ) )
return 0 ;
V_248 = F_68 ( sizeof( * V_248 ) , V_239 ) ;
if ( ! V_248 )
return - V_240 ;
memcpy ( V_248 , V_30 , sizeof( * V_30 ) ) ;
V_244 -> V_249 = V_248 ;
return 0 ;
}
T_6 F_69 ( const struct V_56 * V_57 )
{
return V_57 ? F_26 ( V_57 ) : 0 ;
}
int F_70 ( struct V_124 * V_124 , const struct V_56 * V_57 ,
struct V_247 * V_30 ,
bool log )
{
const struct V_56 * V_58 [ V_64 + 1 ] ;
struct V_1 V_2 ;
T_2 V_62 = 0 ;
int V_82 ;
V_82 = F_20 ( V_57 , V_58 , & V_62 , log ) ;
if ( V_82 )
return - V_65 ;
memset ( & V_2 , 0 , sizeof( V_2 ) ) ;
V_2 . V_30 = V_30 ;
memset ( & V_30 -> V_141 , 0 , sizeof( V_30 -> V_141 ) ) ;
V_30 -> V_131 . V_133 = V_134 ;
return F_51 ( V_124 , & V_2 , & V_62 , V_58 , false , log ) ;
}
static int F_71 ( const struct V_247 * V_250 ,
const struct V_247 * V_120 , bool V_5 ,
struct V_115 * V_116 )
{
struct V_152 * V_153 ;
struct V_56 * V_61 , * V_234 ;
if ( F_37 ( V_116 , V_128 , V_120 -> V_129 ) )
goto V_251;
if ( F_37 ( V_116 , V_125 , V_120 -> V_127 ) )
goto V_251;
if ( F_37 ( V_116 , V_130 , V_120 -> V_131 . V_132 ) )
goto V_251;
if ( ( V_250 -> V_112 || V_5 ) ) {
const void * V_72 = NULL ;
if ( V_120 -> V_86 . V_80 & V_252 )
V_72 = F_72 ( V_120 , V_250 -> V_70 ) ;
if ( F_47 ( V_116 , & V_120 -> V_86 , V_72 ,
V_250 -> V_70 , V_250 -> V_112 ) )
goto V_251;
}
if ( V_250 -> V_131 . V_133 == V_134 ) {
if ( V_5 && ( V_120 -> V_131 . V_133 == 0xffff ) )
if ( F_37 ( V_116 , V_28 , 0xffffffff ) )
goto V_251;
} else {
T_4 V_253 ;
V_253 = ! V_5 ? 0 : 0xffff ;
if ( F_37 ( V_116 , V_28 ,
( V_253 << 16 ) | V_120 -> V_131 . V_133 ) )
goto V_251;
}
if ( F_37 ( V_116 , V_135 , V_120 -> V_131 . V_137 ) )
goto V_251;
if ( F_73 ( V_120 , V_116 ) )
goto V_251;
V_61 = F_74 ( V_116 , V_14 , sizeof( * V_153 ) ) ;
if ( ! V_61 )
goto V_251;
V_153 = F_18 ( V_61 ) ;
F_75 ( V_153 -> V_154 , V_120 -> V_31 . V_46 ) ;
F_75 ( V_153 -> V_156 , V_120 -> V_31 . V_92 ) ;
if ( V_250 -> V_31 . V_158 || V_250 -> V_31 . type == F_5 ( V_237 ) ) {
T_5 V_160 ;
V_160 = ! V_5 ? F_5 ( V_237 ) : F_5 ( 0xffff ) ;
if ( F_45 ( V_116 , V_29 , V_160 ) ||
F_45 ( V_116 , V_157 , V_120 -> V_31 . V_158 ) )
goto V_251;
V_234 = F_36 ( V_116 , V_238 ) ;
if ( ! V_250 -> V_31 . V_158 )
goto V_254;
} else
V_234 = NULL ;
if ( V_250 -> V_31 . type == F_5 ( V_162 ) ) {
if ( V_5 && V_120 -> V_31 . type )
if ( F_45 ( V_116 , V_29 ,
V_120 -> V_31 . type ) )
goto V_251;
goto V_254;
}
if ( F_45 ( V_116 , V_29 , V_120 -> V_31 . type ) )
goto V_251;
if ( V_250 -> V_31 . type == F_5 ( V_34 ) ) {
struct V_163 * V_164 ;
V_61 = F_74 ( V_116 , V_16 , sizeof( * V_164 ) ) ;
if ( ! V_61 )
goto V_251;
V_164 = F_18 ( V_61 ) ;
V_164 -> V_171 = V_120 -> V_78 . V_170 . V_46 ;
V_164 -> V_172 = V_120 -> V_78 . V_170 . V_92 ;
V_164 -> V_167 = V_120 -> V_35 . V_38 ;
V_164 -> V_168 = V_120 -> V_35 . V_96 ;
V_164 -> V_169 = V_120 -> V_35 . V_77 ;
V_164 -> V_165 = V_120 -> V_35 . V_36 ;
} else if ( V_250 -> V_31 . type == F_5 ( V_43 ) ) {
struct V_173 * V_174 ;
V_61 = F_74 ( V_116 , V_17 , sizeof( * V_174 ) ) ;
if ( ! V_61 )
goto V_251;
V_174 = F_18 ( V_61 ) ;
memcpy ( V_174 -> V_181 , & V_120 -> V_79 . V_170 . V_46 ,
sizeof( V_174 -> V_181 ) ) ;
memcpy ( V_174 -> V_182 , & V_120 -> V_79 . V_170 . V_92 ,
sizeof( V_174 -> V_182 ) ) ;
V_174 -> V_176 = V_120 -> V_79 . V_177 ;
V_174 -> V_178 = V_120 -> V_35 . V_38 ;
V_174 -> V_179 = V_120 -> V_35 . V_96 ;
V_174 -> V_180 = V_120 -> V_35 . V_77 ;
V_174 -> V_175 = V_120 -> V_35 . V_36 ;
} else if ( V_250 -> V_31 . type == F_5 ( V_32 ) ||
V_250 -> V_31 . type == F_5 ( V_33 ) ) {
struct V_183 * V_184 ;
V_61 = F_74 ( V_116 , V_24 , sizeof( * V_184 ) ) ;
if ( ! V_61 )
goto V_251;
V_184 = F_18 ( V_61 ) ;
memset ( V_184 , 0 , sizeof( struct V_183 ) ) ;
V_184 -> V_186 = V_120 -> V_78 . V_170 . V_46 ;
V_184 -> V_187 = V_120 -> V_78 . V_170 . V_92 ;
V_184 -> V_185 = F_5 ( V_120 -> V_35 . V_38 ) ;
F_75 ( V_184 -> V_190 , V_120 -> V_78 . V_188 . V_189 ) ;
F_75 ( V_184 -> V_192 , V_120 -> V_78 . V_188 . V_191 ) ;
} else if ( F_6 ( V_250 -> V_31 . type ) ) {
struct V_193 * V_194 ;
V_61 = F_74 ( V_116 , V_26 , sizeof( * V_194 ) ) ;
if ( ! V_61 )
goto V_251;
V_194 = F_18 ( V_61 ) ;
V_194 -> V_197 = V_120 -> V_195 . V_196 ;
}
if ( ( V_250 -> V_31 . type == F_5 ( V_34 ) ||
V_250 -> V_31 . type == F_5 ( V_43 ) ) &&
V_250 -> V_35 . V_36 != V_37 ) {
if ( V_250 -> V_35 . V_38 == V_41 ) {
struct V_198 * V_199 ;
V_61 = F_74 ( V_116 , V_18 , sizeof( * V_199 ) ) ;
if ( ! V_61 )
goto V_251;
V_199 = F_18 ( V_61 ) ;
V_199 -> V_200 = V_120 -> V_45 . V_46 ;
V_199 -> V_201 = V_120 -> V_45 . V_92 ;
if ( F_45 ( V_116 , V_19 ,
V_120 -> V_45 . V_202 ) )
goto V_251;
} else if ( V_250 -> V_35 . V_38 == V_39 ) {
struct V_203 * V_204 ;
V_61 = F_74 ( V_116 , V_20 , sizeof( * V_204 ) ) ;
if ( ! V_61 )
goto V_251;
V_204 = F_18 ( V_61 ) ;
V_204 -> V_205 = V_120 -> V_45 . V_46 ;
V_204 -> V_206 = V_120 -> V_45 . V_92 ;
} else if ( V_250 -> V_35 . V_38 == V_40 ) {
struct V_207 * V_208 ;
V_61 = F_74 ( V_116 , V_21 , sizeof( * V_208 ) ) ;
if ( ! V_61 )
goto V_251;
V_208 = F_18 ( V_61 ) ;
V_208 -> V_209 = V_120 -> V_45 . V_46 ;
V_208 -> V_210 = V_120 -> V_45 . V_92 ;
} else if ( V_250 -> V_31 . type == F_5 ( V_34 ) &&
V_250 -> V_35 . V_38 == V_42 ) {
struct V_211 * V_212 ;
V_61 = F_74 ( V_116 , V_22 , sizeof( * V_212 ) ) ;
if ( ! V_61 )
goto V_251;
V_212 = F_18 ( V_61 ) ;
V_212 -> V_213 = F_57 ( V_120 -> V_45 . V_46 ) ;
V_212 -> V_214 = F_57 ( V_120 -> V_45 . V_92 ) ;
} else if ( V_250 -> V_31 . type == F_5 ( V_43 ) &&
V_250 -> V_35 . V_38 == V_44 ) {
struct V_215 * V_216 ;
V_61 = F_74 ( V_116 , V_23 ,
sizeof( * V_216 ) ) ;
if ( ! V_61 )
goto V_251;
V_216 = F_18 ( V_61 ) ;
V_216 -> V_217 = F_57 ( V_120 -> V_45 . V_46 ) ;
V_216 -> V_218 = F_57 ( V_120 -> V_45 . V_92 ) ;
if ( V_216 -> V_217 == V_47 ||
V_216 -> V_217 == V_48 ) {
struct V_219 * V_220 ;
V_61 = F_74 ( V_116 , V_25 , sizeof( * V_220 ) ) ;
if ( ! V_61 )
goto V_251;
V_220 = F_18 ( V_61 ) ;
memcpy ( V_220 -> V_223 , & V_120 -> V_79 . V_221 . V_222 ,
sizeof( V_220 -> V_223 ) ) ;
F_75 ( V_220 -> V_225 , V_120 -> V_79 . V_221 . V_224 ) ;
F_75 ( V_220 -> V_227 , V_120 -> V_79 . V_221 . V_226 ) ;
}
}
}
V_254:
if ( V_234 )
F_38 ( V_116 , V_234 ) ;
return 0 ;
V_251:
return - V_118 ;
}
int F_76 ( const struct V_247 * V_250 ,
const struct V_247 * V_120 , int V_57 , bool V_5 ,
struct V_115 * V_116 )
{
int V_82 ;
struct V_56 * V_61 ;
V_61 = F_36 ( V_116 , V_57 ) ;
if ( ! V_61 )
return - V_118 ;
V_82 = F_71 ( V_250 , V_120 , V_5 , V_116 ) ;
if ( V_82 )
return V_82 ;
F_38 ( V_116 , V_61 ) ;
return 0 ;
}
int F_77 ( const struct V_255 * V_256 , struct V_115 * V_116 )
{
if ( F_78 ( & V_256 -> V_257 ) )
return F_46 ( V_116 , V_258 , V_256 -> V_257 . V_245 ,
V_256 -> V_257 . V_246 ) ;
return F_76 ( V_256 -> V_257 . V_249 , V_256 -> V_257 . V_249 ,
V_259 , false , V_116 ) ;
}
int F_79 ( const struct V_255 * V_256 , struct V_115 * V_116 )
{
return F_76 ( & V_256 -> V_30 , & V_256 -> V_30 ,
V_259 , false , V_116 ) ;
}
int F_80 ( const struct V_255 * V_256 , struct V_115 * V_116 )
{
return F_76 ( & V_256 -> V_30 , & V_256 -> V_10 -> V_30 ,
V_260 , true , V_116 ) ;
}
static struct V_261 * F_81 ( int V_4 , bool log )
{
struct V_261 * V_262 ;
if ( V_4 > V_263 ) {
F_7 ( log , L_41 , V_4 ) ;
return F_82 ( - V_65 ) ;
}
V_262 = F_68 ( sizeof( * V_262 ) + V_4 , V_239 ) ;
if ( ! V_262 )
return F_82 ( - V_240 ) ;
V_262 -> V_264 = 0 ;
return V_262 ;
}
static void F_83 ( const struct V_56 * V_58 )
{
const struct V_56 * V_265 = F_18 ( V_58 ) ;
struct V_266 * V_267 ;
switch ( F_16 ( V_265 ) ) {
case V_49 :
V_267 = F_18 ( V_265 ) ;
F_84 ( (struct V_268 * ) V_267 -> V_269 ) ;
break;
}
}
void F_85 ( struct V_261 * V_270 )
{
const struct V_56 * V_58 ;
int V_63 ;
if ( ! V_270 )
return;
F_86 (a, sf_acts->actions, sf_acts->actions_len, rem) {
switch ( F_16 ( V_58 ) ) {
case V_271 :
F_83 ( V_58 ) ;
break;
case V_272 :
F_87 ( V_58 ) ;
break;
}
}
F_64 ( V_270 ) ;
}
static void F_88 ( struct V_273 * V_274 )
{
F_85 ( F_89 ( V_274 , struct V_261 , V_275 ) ) ;
}
void F_90 ( struct V_261 * V_270 )
{
F_91 ( & V_270 -> V_275 , F_88 ) ;
}
static struct V_56 * F_92 ( struct V_261 * * V_262 ,
int V_50 , bool log )
{
struct V_261 * V_276 ;
int V_277 ;
int V_278 = F_93 ( V_50 ) ;
int V_279 = F_94 ( struct V_261 , V_280 ) +
( * V_262 ) -> V_264 ;
if ( V_278 <= ( F_95 ( * V_262 ) - V_279 ) )
goto V_281;
V_277 = F_95 ( * V_262 ) * 2 ;
if ( V_277 > V_263 ) {
if ( ( V_263 - V_279 ) < V_278 )
return F_82 ( - V_118 ) ;
V_277 = V_263 ;
}
V_276 = F_81 ( V_277 , log ) ;
if ( F_96 ( V_276 ) )
return ( void * ) V_276 ;
memcpy ( V_276 -> V_280 , ( * V_262 ) -> V_280 , ( * V_262 ) -> V_264 ) ;
V_276 -> V_264 = ( * V_262 ) -> V_264 ;
V_276 -> V_282 = ( * V_262 ) -> V_282 ;
F_64 ( * V_262 ) ;
* V_262 = V_276 ;
V_281:
( * V_262 ) -> V_264 += V_278 ;
return (struct V_56 * ) ( ( unsigned char * ) ( * V_262 ) + V_279 ) ;
}
static struct V_56 * F_97 ( struct V_261 * * V_262 ,
int V_283 , void * V_284 , int V_67 , bool log )
{
struct V_56 * V_58 ;
V_58 = F_92 ( V_262 , F_98 ( V_67 ) , log ) ;
if ( F_96 ( V_58 ) )
return V_58 ;
V_58 -> F_16 = V_283 ;
V_58 -> F_17 = F_98 ( V_67 ) ;
if ( V_284 )
memcpy ( F_18 ( V_58 ) , V_284 , V_67 ) ;
memset ( ( unsigned char * ) V_58 + V_58 -> F_17 , 0 , F_99 ( V_67 ) ) ;
return V_58 ;
}
int F_100 ( struct V_261 * * V_262 , int V_283 , void * V_284 ,
int V_67 , bool log )
{
struct V_56 * V_58 ;
V_58 = F_97 ( V_262 , V_283 , V_284 , V_67 , log ) ;
return F_101 ( V_58 ) ;
}
static inline int F_102 ( struct V_261 * * V_262 ,
int V_283 , bool log )
{
int V_285 = ( * V_262 ) -> V_264 ;
int V_82 ;
V_82 = F_100 ( V_262 , V_283 , NULL , 0 , log ) ;
if ( V_82 )
return V_82 ;
return V_285 ;
}
static inline void F_103 ( struct V_261 * V_262 ,
int V_286 )
{
struct V_56 * V_58 = (struct V_56 * ) ( ( unsigned char * ) V_262 -> V_280 +
V_286 ) ;
V_58 -> F_17 = V_262 -> V_264 - V_286 ;
}
static int F_104 ( struct V_124 * V_124 , const struct V_56 * V_57 ,
const struct V_247 * V_30 , int V_287 ,
struct V_261 * * V_262 ,
T_5 V_160 , T_5 V_288 , bool log )
{
const struct V_56 * V_62 [ V_289 + 1 ] ;
const struct V_56 * V_290 , * V_280 ;
const struct V_56 * V_58 ;
int V_63 , V_8 , V_82 , V_291 ;
memset ( V_62 , 0 , sizeof( V_62 ) ) ;
F_15 (a, attr, rem) {
int type = F_16 ( V_58 ) ;
if ( ! type || type > V_289 || V_62 [ type ] )
return - V_65 ;
V_62 [ type ] = V_58 ;
}
if ( V_63 )
return - V_65 ;
V_290 = V_62 [ V_292 ] ;
if ( ! V_290 || F_17 ( V_290 ) != sizeof( T_6 ) )
return - V_65 ;
V_280 = V_62 [ V_293 ] ;
if ( ! V_280 || ( F_17 ( V_280 ) && F_17 ( V_280 ) < V_294 ) )
return - V_65 ;
V_8 = F_102 ( V_262 , V_295 , log ) ;
if ( V_8 < 0 )
return V_8 ;
V_82 = F_100 ( V_262 , V_292 ,
F_18 ( V_290 ) , sizeof( T_6 ) , log ) ;
if ( V_82 )
return V_82 ;
V_291 = F_102 ( V_262 , V_293 , log ) ;
if ( V_291 < 0 )
return V_291 ;
V_82 = F_105 ( V_124 , V_280 , V_30 , V_287 + 1 , V_262 ,
V_160 , V_288 , log ) ;
if ( V_82 )
return V_82 ;
F_103 ( * V_262 , V_291 ) ;
F_103 ( * V_262 , V_8 ) ;
return 0 ;
}
void F_106 ( struct V_1 * V_2 ,
struct V_247 * V_30 ,
struct V_296 * V_10 )
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
static int F_107 ( struct V_247 * V_30 )
{
struct V_297 * V_298 ;
int V_299 = V_30 -> V_70 ;
bool V_300 = false ;
V_298 = (struct V_297 * ) F_72 ( V_30 , V_30 -> V_70 ) ;
while ( V_299 > 0 ) {
int V_67 ;
if ( V_299 < sizeof( * V_298 ) )
return - V_65 ;
V_67 = sizeof( * V_298 ) + V_298 -> V_301 * 4 ;
if ( V_67 > V_299 )
return - V_65 ;
V_300 |= ! ! ( V_298 -> type & V_302 ) ;
V_298 = (struct V_297 * ) ( ( T_3 * ) V_298 + V_67 ) ;
V_299 -= V_67 ;
} ;
V_30 -> V_86 . V_80 |= V_300 ? V_303 : 0 ;
return 0 ;
}
static int F_108 ( const struct V_56 * V_57 ,
struct V_261 * * V_262 , bool log )
{
struct V_1 V_2 ;
struct V_247 V_30 ;
struct V_304 * V_269 ;
struct V_121 * V_122 ;
struct V_266 * V_267 ;
struct V_56 * V_58 ;
int V_82 = 0 , V_8 , V_81 ;
F_106 ( & V_2 , & V_30 , NULL ) ;
V_81 = F_27 ( F_18 ( V_57 ) , & V_2 , false , log ) ;
if ( V_81 < 0 )
return V_81 ;
if ( V_30 . V_70 ) {
switch ( V_81 ) {
case V_108 :
V_82 = F_107 ( & V_30 ) ;
if ( V_82 < 0 )
return V_82 ;
break;
case V_110 :
break;
}
} ;
V_8 = F_102 ( V_262 , V_271 , log ) ;
if ( V_8 < 0 )
return V_8 ;
V_269 = F_109 ( V_30 . V_70 , V_239 ) ;
if ( ! V_269 )
return - V_240 ;
V_82 = F_110 ( & V_269 -> V_90 . V_122 . V_305 , V_239 ) ;
if ( V_82 ) {
F_84 ( (struct V_268 * ) V_269 ) ;
return V_82 ;
}
V_58 = F_97 ( V_262 , V_49 , NULL ,
sizeof( * V_267 ) , log ) ;
if ( F_96 ( V_58 ) ) {
F_84 ( (struct V_268 * ) V_269 ) ;
return F_111 ( V_58 ) ;
}
V_267 = F_18 ( V_58 ) ;
V_267 -> V_269 = V_269 ;
V_122 = & V_269 -> V_90 . V_122 ;
V_122 -> V_306 = V_307 ;
if ( V_30 . V_112 == V_113 )
V_122 -> V_306 |= V_308 ;
V_122 -> V_30 = V_30 . V_86 ;
F_112 ( V_122 ,
F_72 ( & V_30 , V_30 . V_70 ) ,
V_30 . V_70 ) ;
F_103 ( * V_262 , V_8 ) ;
return V_82 ;
}
static bool F_113 ( T_3 * V_284 , int V_67 )
{
T_3 * V_10 = V_284 + V_67 ;
while ( V_67 -- )
if ( * V_284 ++ & ~ * V_10 ++ )
return false ;
return true ;
}
static int F_114 ( const struct V_56 * V_58 ,
const struct V_247 * V_309 ,
struct V_261 * * V_262 ,
bool * V_310 , T_5 V_160 , bool V_311 , bool log )
{
const struct V_56 * V_265 = F_18 ( V_58 ) ;
int V_312 = F_16 ( V_265 ) ;
T_1 V_313 ;
if ( F_9 ( F_17 ( V_265 ) ) != F_17 ( V_58 ) )
return - V_65 ;
V_313 = F_17 ( V_265 ) ;
if ( V_311 )
V_313 /= 2 ;
if ( V_312 > V_64 ||
! F_12 ( V_313 , V_66 [ V_312 ] . V_67 ) )
return - V_65 ;
if ( V_311 && ! F_113 ( F_18 ( V_265 ) , V_313 ) )
return - V_65 ;
switch ( V_312 ) {
const struct V_163 * V_164 ;
const struct V_173 * V_174 ;
int V_82 ;
case V_130 :
case V_135 :
case V_146 :
case V_147 :
case V_14 :
break;
case V_27 :
if ( V_311 )
return - V_65 ;
* V_310 = true ;
V_82 = F_108 ( V_58 , V_262 , log ) ;
if ( V_82 )
return V_82 ;
break;
case V_16 :
if ( V_160 != F_5 ( V_34 ) )
return - V_65 ;
V_164 = F_18 ( V_265 ) ;
if ( V_311 ) {
const struct V_163 * V_10 = V_164 + 1 ;
if ( V_10 -> V_167 || V_10 -> V_165 )
return - V_65 ;
} else {
if ( V_164 -> V_167 != V_309 -> V_35 . V_38 )
return - V_65 ;
if ( V_164 -> V_165 != V_309 -> V_35 . V_36 )
return - V_65 ;
}
break;
case V_17 :
if ( V_160 != F_5 ( V_43 ) )
return - V_65 ;
V_174 = F_18 ( V_265 ) ;
if ( V_311 ) {
const struct V_173 * V_10 = V_174 + 1 ;
if ( V_10 -> V_178 || V_10 -> V_175 )
return - V_65 ;
if ( F_59 ( V_10 -> V_176 ) & 0xFFF00000 )
return - V_65 ;
} else {
if ( V_174 -> V_178 != V_309 -> V_35 . V_38 )
return - V_65 ;
if ( V_174 -> V_175 != V_309 -> V_35 . V_36 )
return - V_65 ;
}
if ( F_59 ( V_174 -> V_176 ) & 0xFFF00000 )
return - V_65 ;
break;
case V_18 :
if ( ( V_160 != F_5 ( V_34 ) &&
V_160 != F_5 ( V_43 ) ) ||
V_309 -> V_35 . V_38 != V_41 )
return - V_65 ;
break;
case V_20 :
if ( ( V_160 != F_5 ( V_34 ) &&
V_160 != F_5 ( V_43 ) ) ||
V_309 -> V_35 . V_38 != V_39 )
return - V_65 ;
break;
case V_26 :
if ( ! F_6 ( V_160 ) )
return - V_65 ;
break;
case V_21 :
if ( ( V_160 != F_5 ( V_34 ) &&
V_160 != F_5 ( V_43 ) ) ||
V_309 -> V_35 . V_38 != V_40 )
return - V_65 ;
break;
default:
return - V_65 ;
}
if ( ! V_311 && V_312 != V_27 ) {
int V_8 , V_67 = V_313 * 2 ;
struct V_56 * V_314 ;
* V_310 = true ;
V_8 = F_102 ( V_262 ,
V_315 ,
log ) ;
if ( V_8 < 0 )
return V_8 ;
V_314 = F_97 ( V_262 , V_312 , NULL , V_67 , log ) ;
if ( F_96 ( V_314 ) )
return F_111 ( V_314 ) ;
memcpy ( F_18 ( V_314 ) , F_18 ( V_265 ) , V_313 ) ;
memset ( F_18 ( V_314 ) + V_313 , 0xff , V_313 ) ;
if ( V_312 == V_17 ) {
struct V_173 * V_10 = F_18 ( V_314 ) + V_313 ;
V_10 -> V_176 &= F_58 ( 0x000FFFFF ) ;
}
F_103 ( * V_262 , V_8 ) ;
}
return 0 ;
}
static int F_115 ( const struct V_56 * V_57 )
{
static const struct V_316 V_317 [ V_318 + 1 ] = {
[ V_319 ] = { . type = V_320 } ,
[ V_321 ] = { . type = V_322 } ,
[ V_323 ] = { . type = V_320 } ,
} ;
struct V_56 * V_58 [ V_318 + 1 ] ;
int error ;
error = F_116 ( V_58 , V_318 ,
V_57 , V_317 ) ;
if ( error )
return error ;
if ( ! V_58 [ V_319 ] ||
! F_26 ( V_58 [ V_319 ] ) )
return - V_65 ;
return 0 ;
}
static int F_117 ( const struct V_56 * V_324 ,
struct V_261 * * V_262 , bool log )
{
int V_325 = F_93 ( V_324 -> F_17 ) ;
struct V_56 * V_326 ;
V_326 = F_92 ( V_262 , V_324 -> F_17 , log ) ;
if ( F_96 ( V_326 ) )
return F_111 ( V_326 ) ;
memcpy ( V_326 , V_324 , V_325 ) ;
return 0 ;
}
static int F_105 ( struct V_124 * V_124 , const struct V_56 * V_57 ,
const struct V_247 * V_30 ,
int V_287 , struct V_261 * * V_262 ,
T_5 V_160 , T_5 V_288 , bool log )
{
const struct V_56 * V_58 ;
int V_63 , V_82 ;
if ( V_287 >= V_327 )
return - V_328 ;
F_15 (a, attr, rem) {
static const T_6 V_329 [ V_330 + 1 ] = {
[ V_331 ] = sizeof( T_6 ) ,
[ V_332 ] = sizeof( T_6 ) ,
[ V_333 ] = ( T_6 ) - 1 ,
[ V_334 ] = sizeof( struct V_335 ) ,
[ V_336 ] = sizeof( T_5 ) ,
[ V_337 ] = sizeof( struct V_338 ) ,
[ V_339 ] = 0 ,
[ V_271 ] = ( T_6 ) - 1 ,
[ V_340 ] = ( T_6 ) - 1 ,
[ V_295 ] = ( T_6 ) - 1 ,
[ V_341 ] = sizeof( struct V_342 ) ,
[ V_272 ] = ( T_6 ) - 1 ,
} ;
const struct V_338 * V_343 ;
int type = F_16 ( V_58 ) ;
bool V_310 ;
if ( type > V_330 ||
( V_329 [ type ] != F_17 ( V_58 ) &&
V_329 [ type ] != ( T_6 ) - 1 ) )
return - V_65 ;
V_310 = false ;
switch ( type ) {
case V_344 :
return - V_65 ;
case V_333 :
V_82 = F_115 ( V_58 ) ;
if ( V_82 )
return V_82 ;
break;
case V_331 :
if ( F_26 ( V_58 ) >= V_134 )
return - V_65 ;
break;
case V_341 : {
const struct V_342 * V_345 = F_18 ( V_58 ) ;
switch ( V_345 -> V_346 ) {
case V_347 :
break;
default:
return - V_65 ;
}
break;
}
case V_339 :
V_288 = F_5 ( 0 ) ;
break;
case V_337 :
V_343 = F_18 ( V_58 ) ;
if ( V_343 -> V_348 != F_5 ( V_237 ) )
return - V_65 ;
if ( ! ( V_343 -> V_288 & F_5 ( V_159 ) ) )
return - V_65 ;
V_288 = V_343 -> V_288 ;
break;
case V_332 :
break;
case V_334 : {
const struct V_335 * V_195 = F_18 ( V_58 ) ;
if ( ! F_6 ( V_195 -> V_349 ) )
return - V_65 ;
if ( V_288 & F_5 ( V_159 ) ||
( V_160 != F_5 ( V_34 ) &&
V_160 != F_5 ( V_43 ) &&
V_160 != F_5 ( V_32 ) &&
V_160 != F_5 ( V_33 ) &&
! F_6 ( V_160 ) ) )
return - V_65 ;
V_160 = V_195 -> V_349 ;
break;
}
case V_336 :
if ( V_288 & F_5 ( V_159 ) ||
! F_6 ( V_160 ) )
return - V_65 ;
V_160 = F_5 ( 0 ) ;
break;
case V_271 :
V_82 = F_114 ( V_58 , V_30 , V_262 ,
& V_310 , V_160 , false , log ) ;
if ( V_82 )
return V_82 ;
break;
case V_340 :
V_82 = F_114 ( V_58 , V_30 , V_262 ,
& V_310 , V_160 , true , log ) ;
if ( V_82 )
return V_82 ;
break;
case V_295 :
V_82 = F_104 ( V_124 , V_58 , V_30 , V_287 , V_262 ,
V_160 , V_288 , log ) ;
if ( V_82 )
return V_82 ;
V_310 = true ;
break;
case V_272 :
V_82 = F_118 ( V_124 , V_58 , V_30 , V_262 , log ) ;
if ( V_82 )
return V_82 ;
V_310 = true ;
break;
default:
F_7 ( log , L_42 , type ) ;
return - V_65 ;
}
if ( ! V_310 ) {
V_82 = F_117 ( V_58 , V_262 , log ) ;
if ( V_82 )
return V_82 ;
}
}
if ( V_63 > 0 )
return - V_65 ;
return 0 ;
}
int F_119 ( struct V_124 * V_124 , const struct V_56 * V_57 ,
const struct V_247 * V_30 ,
struct V_261 * * V_262 , bool log )
{
int V_82 ;
* V_262 = F_81 ( F_17 ( V_57 ) , log ) ;
if ( F_96 ( * V_262 ) )
return F_111 ( * V_262 ) ;
( * V_262 ) -> V_282 = F_17 ( V_57 ) ;
V_82 = F_105 ( V_124 , V_57 , V_30 , 0 , V_262 , V_30 -> V_31 . type ,
V_30 -> V_31 . V_158 , log ) ;
if ( V_82 )
F_85 ( * V_262 ) ;
return V_82 ;
}
static int F_120 ( const struct V_56 * V_57 , struct V_115 * V_116 )
{
const struct V_56 * V_58 ;
struct V_56 * V_8 ;
int V_82 = 0 , V_63 ;
V_8 = F_36 ( V_116 , V_295 ) ;
if ( ! V_8 )
return - V_118 ;
F_15 (a, attr, rem) {
int type = F_16 ( V_58 ) ;
struct V_56 * V_350 ;
switch ( type ) {
case V_292 :
if ( F_46 ( V_116 , V_292 ,
sizeof( T_6 ) , F_18 ( V_58 ) ) )
return - V_118 ;
break;
case V_293 :
V_350 = F_36 ( V_116 , V_293 ) ;
if ( ! V_350 )
return - V_118 ;
V_82 = F_121 ( F_18 ( V_58 ) , F_17 ( V_58 ) , V_116 ) ;
if ( V_82 )
return V_82 ;
F_38 ( V_116 , V_350 ) ;
break;
}
}
F_38 ( V_116 , V_8 ) ;
return V_82 ;
}
static int F_122 ( const struct V_56 * V_58 , struct V_115 * V_116 )
{
const struct V_56 * V_265 = F_18 ( V_58 ) ;
int V_312 = F_16 ( V_265 ) ;
struct V_56 * V_8 ;
int V_82 ;
switch ( V_312 ) {
case V_49 : {
struct V_266 * V_267 = F_18 ( V_265 ) ;
struct V_121 * V_122 = & V_267 -> V_269 -> V_90 . V_122 ;
V_8 = F_36 ( V_116 , V_271 ) ;
if ( ! V_8 )
return - V_118 ;
V_82 = F_47 ( V_116 , & V_122 -> V_30 ,
F_49 ( V_122 ) ,
V_122 -> V_123 ,
F_50 ( V_122 ) ) ;
if ( V_82 )
return V_82 ;
F_38 ( V_116 , V_8 ) ;
break;
}
default:
if ( F_46 ( V_116 , V_271 , F_17 ( V_58 ) , V_265 ) )
return - V_118 ;
break;
}
return 0 ;
}
static int F_123 ( const struct V_56 * V_58 ,
struct V_115 * V_116 )
{
const struct V_56 * V_265 = F_18 ( V_58 ) ;
struct V_56 * V_61 ;
T_1 V_313 = F_17 ( V_265 ) / 2 ;
V_61 = F_36 ( V_116 , V_271 ) ;
if ( ! V_61 )
return - V_118 ;
if ( F_46 ( V_116 , F_16 ( V_265 ) , V_313 , F_18 ( V_265 ) ) )
return - V_118 ;
F_38 ( V_116 , V_61 ) ;
return 0 ;
}
int F_121 ( const struct V_56 * V_57 , int V_67 , struct V_115 * V_116 )
{
const struct V_56 * V_58 ;
int V_63 , V_82 ;
F_86 (a, attr, len, rem) {
int type = F_16 ( V_58 ) ;
switch ( type ) {
case V_271 :
V_82 = F_122 ( V_58 , V_116 ) ;
if ( V_82 )
return V_82 ;
break;
case V_315 :
V_82 = F_123 ( V_58 , V_116 ) ;
if ( V_82 )
return V_82 ;
break;
case V_295 :
V_82 = F_120 ( V_58 , V_116 ) ;
if ( V_82 )
return V_82 ;
break;
case V_272 :
V_82 = F_124 ( F_18 ( V_58 ) , V_116 ) ;
if ( V_82 )
return V_82 ;
break;
default:
if ( F_46 ( V_116 , type , F_17 ( V_58 ) , F_18 ( V_58 ) ) )
return - V_118 ;
break;
}
}
return 0 ;
}
