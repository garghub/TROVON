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
T_2 V_13 = 0 ;
T_2 V_14 = V_11 ;
V_14 &= ~ ( ( 1 << V_15 )
| ( 1 << V_16 )
| ( 1 << V_17 )
| ( 1 << V_18 )
| ( 1 << V_19 )
| ( 1 << V_20 )
| ( 1 << V_21 )
| ( 1 << V_22 )
| ( 1 << V_23 )
| ( 1 << V_24 )
| ( 1 << V_25 )
| ( 1 << V_26 )
| ( 1 << V_27 ) ) ;
V_14 |= ( ( 1 << V_28 )
| ( 1 << V_29 )
| ( 1 << V_30 ) ) ;
if ( V_2 -> V_31 -> V_32 . type == F_5 ( V_33 )
|| V_2 -> V_31 -> V_32 . type == F_5 ( V_34 ) ) {
V_13 |= 1 << V_25 ;
if ( V_2 -> V_10 && ( V_2 -> V_10 -> V_31 . V_32 . type == F_5 ( 0xffff ) ) )
V_14 |= 1 << V_25 ;
}
if ( F_6 ( V_2 -> V_31 -> V_32 . type ) ) {
V_13 |= 1 << V_27 ;
if ( V_2 -> V_10 && ( V_2 -> V_10 -> V_31 . V_32 . type == F_5 ( 0xffff ) ) )
V_14 |= 1 << V_27 ;
}
if ( V_2 -> V_31 -> V_32 . type == F_5 ( V_35 ) ) {
V_13 |= 1 << V_15 ;
if ( V_2 -> V_10 && V_2 -> V_10 -> V_31 . V_32 . type == F_5 ( 0xffff ) ) {
V_14 |= 1 << V_15 ;
V_14 |= 1 << V_16 ;
}
if ( V_2 -> V_31 -> V_36 . V_37 != V_38 ) {
if ( V_2 -> V_31 -> V_36 . V_39 == V_40 ) {
V_13 |= 1 << V_21 ;
if ( V_2 -> V_10 && ( V_2 -> V_10 -> V_31 . V_36 . V_39 == 0xff ) )
V_14 |= 1 << V_21 ;
}
if ( V_2 -> V_31 -> V_36 . V_39 == V_41 ) {
V_13 |= 1 << V_22 ;
if ( V_2 -> V_10 && ( V_2 -> V_10 -> V_31 . V_36 . V_39 == 0xff ) )
V_14 |= 1 << V_22 ;
}
if ( V_2 -> V_31 -> V_36 . V_39 == V_42 ) {
V_13 |= 1 << V_19 ;
V_13 |= 1 << V_20 ;
if ( V_2 -> V_10 && ( V_2 -> V_10 -> V_31 . V_36 . V_39 == 0xff ) ) {
V_14 |= 1 << V_19 ;
V_14 |= 1 << V_20 ;
}
}
if ( V_2 -> V_31 -> V_36 . V_39 == V_43 ) {
V_13 |= 1 << V_23 ;
if ( V_2 -> V_10 && ( V_2 -> V_10 -> V_31 . V_36 . V_39 == 0xff ) )
V_14 |= 1 << V_23 ;
}
}
}
if ( V_2 -> V_31 -> V_32 . type == F_5 ( V_44 ) ) {
V_13 |= 1 << V_17 ;
if ( V_2 -> V_10 && V_2 -> V_10 -> V_31 . V_32 . type == F_5 ( 0xffff ) ) {
V_14 |= 1 << V_17 ;
V_14 |= 1 << V_18 ;
}
if ( V_2 -> V_31 -> V_36 . V_37 != V_38 ) {
if ( V_2 -> V_31 -> V_36 . V_39 == V_40 ) {
V_13 |= 1 << V_21 ;
if ( V_2 -> V_10 && ( V_2 -> V_10 -> V_31 . V_36 . V_39 == 0xff ) )
V_14 |= 1 << V_21 ;
}
if ( V_2 -> V_31 -> V_36 . V_39 == V_41 ) {
V_13 |= 1 << V_22 ;
if ( V_2 -> V_10 && ( V_2 -> V_10 -> V_31 . V_36 . V_39 == 0xff ) )
V_14 |= 1 << V_22 ;
}
if ( V_2 -> V_31 -> V_36 . V_39 == V_42 ) {
V_13 |= 1 << V_19 ;
V_13 |= 1 << V_20 ;
if ( V_2 -> V_10 && ( V_2 -> V_10 -> V_31 . V_36 . V_39 == 0xff ) ) {
V_14 |= 1 << V_19 ;
V_14 |= 1 << V_20 ;
}
}
if ( V_2 -> V_31 -> V_36 . V_39 == V_45 ) {
V_13 |= 1 << V_24 ;
if ( V_2 -> V_10 && ( V_2 -> V_10 -> V_31 . V_36 . V_39 == 0xff ) )
V_14 |= 1 << V_24 ;
if ( V_2 -> V_31 -> V_46 . V_47 ==
F_5 ( V_48 ) ||
V_2 -> V_31 -> V_46 . V_47 == F_5 ( V_49 ) ) {
V_13 |= 1 << V_26 ;
V_14 &= ~ ( 1ULL << V_18 ) ;
if ( V_2 -> V_10 && ( V_2 -> V_10 -> V_31 . V_46 . V_47 == F_5 ( 0xff ) ) )
V_14 |= 1 << V_26 ;
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
if ( ( V_12 & V_14 ) != V_12 ) {
F_7 ( log , L_2 ,
( unsigned long long ) V_12 ,
( unsigned long long ) V_14 ) ;
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
F_12 ( V_50 != 28 ) ;
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
+ F_10 ( 40 )
+ F_10 ( 12 )
+ F_10 ( 2 )
+ F_10 ( 4 )
+ F_10 ( 0 )
+ F_10 ( 2 )
+ F_10 ( 40 )
+ F_10 ( 2 )
+ F_10 ( 28 ) ;
}
static bool F_13 ( unsigned int V_51 , unsigned int V_52 )
{
return V_52 == V_51 ||
V_52 == V_53 ||
V_52 == V_54 ;
}
static bool F_14 ( const T_3 * V_55 , T_1 V_4 )
{
int V_56 ;
if ( ! V_55 )
return false ;
for ( V_56 = 0 ; V_56 < V_4 ; V_56 ++ )
if ( V_55 [ V_56 ] )
return false ;
return true ;
}
static int F_15 ( const struct V_57 * V_58 ,
const struct V_57 * V_59 [] ,
T_2 * V_60 , bool log , bool V_61 )
{
const struct V_57 * V_62 ;
T_2 V_63 ;
int V_64 ;
V_63 = * V_60 ;
F_16 (nla, attr, rem) {
T_4 type = F_17 ( V_62 ) ;
int V_52 ;
if ( type > V_65 ) {
F_7 ( log , L_3 ,
type , V_65 ) ;
return - V_66 ;
}
if ( V_63 & ( 1 << type ) ) {
F_7 ( log , L_4 , type ) ;
return - V_66 ;
}
V_52 = V_67 [ type ] . V_68 ;
if ( ! F_13 ( F_18 ( V_62 ) , V_52 ) ) {
F_7 ( log , L_5 ,
type , F_18 ( V_62 ) , V_52 ) ;
return - V_66 ;
}
if ( ! V_61 || ! F_14 ( F_19 ( V_62 ) , V_52 ) ) {
V_63 |= 1 << type ;
V_59 [ type ] = V_62 ;
}
}
if ( V_64 ) {
F_7 ( log , L_6 , V_64 ) ;
return - V_66 ;
}
* V_60 = V_63 ;
return 0 ;
}
static int F_20 ( const struct V_57 * V_58 ,
const struct V_57 * V_59 [] , T_2 * V_60 ,
bool log )
{
return F_15 ( V_58 , V_59 , V_60 , log , true ) ;
}
int F_21 ( const struct V_57 * V_58 , const struct V_57 * V_59 [] ,
T_2 * V_60 , bool log )
{
return F_15 ( V_58 , V_59 , V_60 , log , false ) ;
}
static int F_22 ( const struct V_57 * V_59 ,
struct V_1 * V_2 , bool V_5 ,
bool log )
{
unsigned long V_69 ;
if ( F_18 ( V_59 ) > sizeof( V_2 -> V_31 -> V_70 ) ) {
F_7 ( log , L_7 ,
F_18 ( V_59 ) , sizeof( V_2 -> V_31 -> V_70 ) ) ;
return - V_66 ;
}
if ( F_18 ( V_59 ) % 4 != 0 ) {
F_7 ( log , L_8 ,
F_18 ( V_59 ) ) ;
return - V_66 ;
}
if ( ! V_5 ) {
F_23 ( V_2 , V_71 , F_18 ( V_59 ) ,
false ) ;
} else {
if ( V_2 -> V_31 -> V_71 != F_18 ( V_59 ) ) {
F_7 ( log , L_9 ,
V_2 -> V_31 -> V_71 , F_18 ( V_59 ) ) ;
return - V_66 ;
}
F_23 ( V_2 , V_71 , 0xff , true ) ;
}
V_69 = F_24 ( F_18 ( V_59 ) ) ;
F_25 ( V_2 , V_69 , F_19 ( V_59 ) ,
F_18 ( V_59 ) , V_5 ) ;
return 0 ;
}
static int F_26 ( const struct V_57 * V_58 ,
struct V_1 * V_2 , bool V_5 ,
bool log )
{
struct V_57 * V_59 ;
int V_64 ;
unsigned long V_69 ;
struct V_72 V_73 ;
F_12 ( sizeof( V_73 ) > sizeof( V_2 -> V_31 -> V_70 ) ) ;
memset ( & V_73 , 0 , sizeof( V_73 ) ) ;
F_16 (a, attr, rem) {
int type = F_17 ( V_59 ) ;
if ( type > V_74 ) {
F_7 ( log , L_10 ,
type , V_74 ) ;
return - V_66 ;
}
if ( ! F_13 ( F_18 ( V_59 ) ,
V_75 [ type ] . V_68 ) ) {
F_7 ( log , L_11 ,
type , F_18 ( V_59 ) ,
V_75 [ type ] . V_68 ) ;
return - V_66 ;
}
switch ( type ) {
case V_76 :
V_73 . V_77 = F_27 ( V_59 ) ;
break;
default:
F_7 ( log , L_12 ,
type ) ;
return - V_66 ;
}
}
if ( V_64 ) {
F_7 ( log , L_13 ,
V_64 ) ;
return - V_66 ;
}
if ( ! V_5 )
F_23 ( V_2 , V_71 , sizeof( V_73 ) , false ) ;
else
F_23 ( V_2 , V_71 , 0xff , true ) ;
V_69 = F_24 ( sizeof( V_73 ) ) ;
F_25 ( V_2 , V_69 , & V_73 , sizeof( V_73 ) ,
V_5 ) ;
return 0 ;
}
static int F_28 ( const struct V_57 * V_58 ,
struct V_1 * V_2 , bool V_5 ,
bool log )
{
bool V_78 = false , V_79 = false , V_80 = false ;
T_5 V_81 = 0 ;
int V_82 = 0 ;
struct V_57 * V_59 ;
int V_64 ;
F_16 (a, attr, rem) {
int type = F_17 ( V_59 ) ;
int V_83 ;
if ( type > V_84 ) {
F_7 ( log , L_14 ,
type , V_84 ) ;
return - V_66 ;
}
if ( ! F_13 ( F_18 ( V_59 ) ,
V_85 [ type ] . V_68 ) ) {
F_7 ( log , L_15 ,
type , F_18 ( V_59 ) , V_85 [ type ] . V_68 ) ;
return - V_66 ;
}
switch ( type ) {
case V_86 :
F_23 ( V_2 , V_87 . V_88 ,
F_29 ( V_59 ) , V_5 ) ;
V_81 |= V_89 ;
break;
case V_90 :
F_23 ( V_2 , V_87 . V_91 . V_79 . V_47 ,
F_30 ( V_59 ) , V_5 ) ;
V_79 = true ;
break;
case V_92 :
F_23 ( V_2 , V_87 . V_91 . V_79 . V_93 ,
F_30 ( V_59 ) , V_5 ) ;
V_79 = true ;
break;
case V_94 :
F_23 ( V_2 , V_87 . V_91 . V_80 . V_47 ,
F_31 ( V_59 ) , V_5 ) ;
V_80 = true ;
break;
case V_95 :
F_23 ( V_2 , V_87 . V_91 . V_80 . V_93 ,
F_31 ( V_59 ) , V_5 ) ;
V_80 = true ;
break;
case V_96 :
F_23 ( V_2 , V_87 . V_97 ,
F_32 ( V_59 ) , V_5 ) ;
break;
case V_98 :
F_23 ( V_2 , V_87 . V_78 ,
F_32 ( V_59 ) , V_5 ) ;
V_78 = true ;
break;
case V_99 :
V_81 |= V_100 ;
break;
case V_101 :
V_81 |= V_102 ;
break;
case V_103 :
F_23 ( V_2 , V_87 . V_104 ,
F_33 ( V_59 ) , V_5 ) ;
break;
case V_105 :
F_23 ( V_2 , V_87 . V_106 ,
F_33 ( V_59 ) , V_5 ) ;
break;
case V_107 :
V_81 |= V_108 ;
break;
case V_109 :
if ( V_82 ) {
F_7 ( log , L_16 ) ;
return - V_66 ;
}
V_83 = F_22 ( V_59 , V_2 , V_5 , log ) ;
if ( V_83 )
return V_83 ;
V_81 |= V_110 ;
V_82 = type ;
break;
case V_111 :
if ( V_82 ) {
F_7 ( log , L_16 ) ;
return - V_66 ;
}
V_83 = F_26 ( V_59 , V_2 , V_5 , log ) ;
if ( V_83 )
return V_83 ;
V_81 |= V_112 ;
V_82 = type ;
break;
case V_113 :
break;
default:
F_7 ( log , L_17 ,
type ) ;
return - V_66 ;
}
}
F_23 ( V_2 , V_87 . V_81 , V_81 , V_5 ) ;
if ( V_5 )
F_34 ( V_2 , V_114 , 0xff , true ) ;
else
F_23 ( V_2 , V_114 , V_80 ? V_115 : V_116 ,
false ) ;
if ( V_64 > 0 ) {
F_7 ( log , L_18 ,
V_64 ) ;
return - V_66 ;
}
if ( V_79 && V_80 ) {
F_7 ( log , L_19 ) ;
return - V_66 ;
}
if ( ! V_5 ) {
if ( ! V_79 && ! V_80 ) {
F_7 ( log , L_20 ) ;
return - V_66 ;
}
if ( V_79 && ! V_2 -> V_31 -> V_87 . V_91 . V_79 . V_93 ) {
F_7 ( log , L_21 ) ;
return - V_66 ;
}
if ( V_80 && F_35 ( & V_2 -> V_31 -> V_87 . V_91 . V_80 . V_93 ) ) {
F_7 ( log , L_22 ) ;
return - V_66 ;
}
if ( ! V_78 ) {
F_7 ( log , L_23 ) ;
return - V_66 ;
}
}
return V_82 ;
}
static int F_36 ( struct V_117 * V_118 ,
const void * V_70 , int V_119 )
{
const struct V_72 * V_73 = V_70 ;
struct V_57 * V_62 ;
V_62 = F_37 ( V_118 , V_111 ) ;
if ( ! V_62 )
return - V_120 ;
if ( F_38 ( V_118 , V_76 , V_73 -> V_77 ) < 0 )
return - V_120 ;
F_39 ( V_118 , V_62 ) ;
return 0 ;
}
static int F_40 ( struct V_117 * V_118 ,
const struct V_121 * V_122 ,
const void * V_70 , int V_119 ,
unsigned short V_114 )
{
if ( V_122 -> V_81 & V_89 &&
F_41 ( V_118 , V_86 , V_122 -> V_88 ,
V_113 ) )
return - V_120 ;
switch ( V_114 ) {
case V_116 :
if ( V_122 -> V_91 . V_79 . V_47 &&
F_42 ( V_118 , V_90 ,
V_122 -> V_91 . V_79 . V_47 ) )
return - V_120 ;
if ( V_122 -> V_91 . V_79 . V_93 &&
F_42 ( V_118 , V_92 ,
V_122 -> V_91 . V_79 . V_93 ) )
return - V_120 ;
break;
case V_115 :
if ( ! F_35 ( & V_122 -> V_91 . V_80 . V_47 ) &&
F_43 ( V_118 , V_94 ,
& V_122 -> V_91 . V_80 . V_47 ) )
return - V_120 ;
if ( ! F_35 ( & V_122 -> V_91 . V_80 . V_93 ) &&
F_43 ( V_118 , V_95 ,
& V_122 -> V_91 . V_80 . V_93 ) )
return - V_120 ;
break;
}
if ( V_122 -> V_97 &&
F_44 ( V_118 , V_96 , V_122 -> V_97 ) )
return - V_120 ;
if ( F_44 ( V_118 , V_98 , V_122 -> V_78 ) )
return - V_120 ;
if ( ( V_122 -> V_81 & V_100 ) &&
F_45 ( V_118 , V_99 ) )
return - V_120 ;
if ( ( V_122 -> V_81 & V_102 ) &&
F_45 ( V_118 , V_101 ) )
return - V_120 ;
if ( V_122 -> V_104 &&
F_46 ( V_118 , V_103 , V_122 -> V_104 ) )
return - V_120 ;
if ( V_122 -> V_106 &&
F_46 ( V_118 , V_105 , V_122 -> V_106 ) )
return - V_120 ;
if ( ( V_122 -> V_81 & V_108 ) &&
F_45 ( V_118 , V_107 ) )
return - V_120 ;
if ( V_119 ) {
if ( V_122 -> V_81 & V_110 &&
F_47 ( V_118 , V_109 ,
V_119 , V_70 ) )
return - V_120 ;
else if ( V_122 -> V_81 & V_112 &&
F_36 ( V_118 , V_70 , V_119 ) )
return - V_120 ;
}
return 0 ;
}
static int F_48 ( struct V_117 * V_118 ,
const struct V_121 * V_122 ,
const void * V_70 , int V_119 ,
unsigned short V_114 )
{
struct V_57 * V_62 ;
int V_83 ;
V_62 = F_37 ( V_118 , V_28 ) ;
if ( ! V_62 )
return - V_120 ;
V_83 = F_40 ( V_118 , V_122 , V_70 , V_119 ,
V_114 ) ;
if ( V_83 )
return V_83 ;
F_39 ( V_118 , V_62 ) ;
return 0 ;
}
int F_49 ( struct V_117 * V_118 ,
struct V_123 * V_124 )
{
return F_40 ( V_118 , & V_124 -> V_31 ,
F_50 ( V_124 ) ,
V_124 -> V_125 ,
F_51 ( V_124 ) ) ;
}
static int F_52 ( struct V_1 * V_2 ,
const struct V_57 * V_59 [] ,
bool V_5 , bool V_126 )
{
T_5 V_127 = 0 ;
T_5 V_128 = 0 ;
if ( V_59 [ V_129 ] )
V_127 = F_33 ( V_59 [ V_129 ] ) ;
if ( V_59 [ V_30 ] )
V_128 = F_33 ( V_59 [ V_30 ] ) ;
if ( F_53 ( ! V_126 ) ) {
F_23 ( V_2 , V_32 . V_130 . V_128 , V_128 , V_5 ) ;
F_23 ( V_2 , V_32 . V_130 . V_127 , V_127 , V_5 ) ;
} else {
F_23 ( V_2 , V_32 . V_131 . V_128 , V_128 , V_5 ) ;
F_23 ( V_2 , V_32 . V_131 . V_127 , V_127 , V_5 ) ;
}
return 0 ;
}
static int F_54 ( const struct V_1 * V_2 ,
T_2 V_11 , bool V_126 ,
const struct V_57 * * V_59 , bool log )
{
T_5 V_127 = 0 ;
if ( ! ( ( V_11 & ( 1 << V_132 ) ) &&
( V_11 & ( 1 << V_30 ) ) &&
F_55 ( F_33 ( V_59 [ V_30 ] ) ) ) ) {
return 0 ;
}
if ( ! ( ( V_11 & ( 1 << V_129 ) ) &&
( V_11 & ( 1 << V_133 ) ) ) ) {
F_7 ( log , L_24 , ( V_126 ) ? L_25 : L_26 ) ;
return - V_66 ;
}
if ( V_59 [ V_129 ] )
V_127 = F_33 ( V_59 [ V_129 ] ) ;
if ( ! ( V_127 & F_5 ( V_134 ) ) ) {
if ( V_127 ) {
F_7 ( log , L_27 ,
( V_126 ) ? L_25 : L_26 ) ;
return - V_66 ;
} else if ( F_18 ( V_59 [ V_133 ] ) ) {
F_7 ( log , L_28 ,
( V_126 ) ? L_25 : L_26 ) ;
return - V_66 ;
}
}
return 1 ;
}
static int F_56 ( const struct V_1 * V_2 ,
T_2 V_11 , bool V_126 ,
const struct V_57 * * V_59 , bool log )
{
T_5 V_127 = 0 ;
T_5 V_128 = 0 ;
bool V_135 = ! ! ( V_2 -> V_31 -> V_32 . V_130 . V_127 &
F_5 ( V_134 ) ) ;
bool V_136 = ! ! ( V_2 -> V_31 -> V_32 . V_131 . V_127 &
F_5 ( V_134 ) ) ;
if ( ! ( V_11 & ( 1 << V_133 ) ) ) {
return 0 ;
}
if ( ( ! V_126 && ! V_135 ) || ( V_126 && ! V_136 ) ) {
F_7 ( log , L_29 ,
( V_126 ) ? L_25 : L_26 ) ;
return - V_66 ;
}
if ( V_59 [ V_129 ] )
V_127 = F_33 ( V_59 [ V_129 ] ) ;
if ( V_59 [ V_30 ] )
V_128 = F_33 ( V_59 [ V_30 ] ) ;
if ( V_128 != F_5 ( 0xffff ) ) {
F_7 ( log , L_30 ,
( V_126 ) ? L_25 : L_26 , F_57 ( V_128 ) ) ;
return - V_66 ;
}
if ( ! ( V_127 & F_5 ( V_134 ) ) ) {
F_7 ( log , L_31 ,
( V_126 ) ? L_25 : L_26 ) ;
return - V_66 ;
}
return 1 ;
}
static int F_58 ( struct V_1 * V_2 ,
T_2 * V_11 , bool V_126 ,
const struct V_57 * * V_59 , bool V_5 ,
bool log )
{
int V_83 ;
const struct V_57 * V_137 ;
if ( ! V_5 )
V_83 = F_54 ( V_2 , * V_11 , V_126 ,
V_59 , log ) ;
else
V_83 = F_56 ( V_2 , * V_11 , V_126 ,
V_59 , log ) ;
if ( V_83 <= 0 )
return V_83 ;
V_83 = F_52 ( V_2 , V_59 , V_5 , V_126 ) ;
if ( V_83 )
return V_83 ;
* V_11 &= ~ ( 1 << V_133 ) ;
* V_11 &= ~ ( 1 << V_129 ) ;
* V_11 &= ~ ( 1 << V_30 ) ;
V_137 = V_59 [ V_133 ] ;
if ( ! V_5 )
V_83 = F_21 ( V_137 , V_59 , V_11 , log ) ;
else
V_83 = F_20 ( V_137 , V_59 , V_11 , log ) ;
return V_83 ;
}
static int F_59 ( struct V_1 * V_2 ,
T_2 * V_11 , const struct V_57 * * V_59 ,
bool V_5 , bool log )
{
int V_83 ;
bool V_135 = false ;
V_83 = F_58 ( V_2 , V_11 , false , V_59 ,
V_5 , log ) ;
if ( V_83 )
return V_83 ;
V_135 = ! ! ( V_2 -> V_31 -> V_32 . V_130 . V_127 & F_5 ( V_134 ) ) ;
if ( V_135 ) {
V_83 = F_58 ( V_2 , V_11 , true , V_59 ,
V_5 , log ) ;
if ( V_83 )
return V_83 ;
}
return 0 ;
}
static int F_60 ( struct V_1 * V_2 ,
T_2 * V_63 , const struct V_57 * * V_59 ,
bool V_5 , bool log )
{
T_5 V_138 ;
V_138 = F_33 ( V_59 [ V_30 ] ) ;
if ( V_5 ) {
V_138 = F_5 ( 0xffff ) ;
} else if ( ! F_61 ( V_138 ) ) {
F_7 ( log , L_32 ,
F_57 ( V_138 ) , V_139 ) ;
return - V_66 ;
}
F_23 ( V_2 , V_32 . type , V_138 , V_5 ) ;
* V_63 &= ~ ( 1 << V_30 ) ;
return 0 ;
}
static int F_62 ( struct V_140 * V_140 , struct V_1 * V_2 ,
T_2 * V_63 , const struct V_57 * * V_59 ,
bool V_5 , bool log )
{
T_3 V_141 = V_142 ;
if ( * V_63 & ( 1 << V_143 ) ) {
T_6 V_144 = F_27 ( V_59 [ V_143 ] ) ;
F_23 ( V_2 , V_145 , V_144 , V_5 ) ;
* V_63 &= ~ ( 1 << V_143 ) ;
}
if ( * V_63 & ( 1 << V_146 ) ) {
T_6 V_147 = F_27 ( V_59 [ V_146 ] ) ;
F_23 ( V_2 , V_147 , V_147 , V_5 ) ;
* V_63 &= ~ ( 1 << V_146 ) ;
}
if ( * V_63 & ( 1 << V_148 ) ) {
F_23 ( V_2 , V_149 . V_150 ,
F_27 ( V_59 [ V_148 ] ) , V_5 ) ;
* V_63 &= ~ ( 1 << V_148 ) ;
}
if ( * V_63 & ( 1 << V_29 ) ) {
T_6 V_151 = F_27 ( V_59 [ V_29 ] ) ;
if ( V_5 ) {
V_151 = 0xffffffff ;
} else if ( V_151 >= V_152 ) {
F_7 ( log , L_33 ,
V_151 , V_152 ) ;
return - V_66 ;
}
F_23 ( V_2 , V_149 . V_151 , V_151 , V_5 ) ;
* V_63 &= ~ ( 1 << V_29 ) ;
} else if ( ! V_5 ) {
F_23 ( V_2 , V_149 . V_151 , V_152 , V_5 ) ;
}
if ( * V_63 & ( 1 << V_153 ) ) {
T_7 V_154 = F_27 ( V_59 [ V_153 ] ) ;
F_23 ( V_2 , V_149 . V_155 , V_154 , V_5 ) ;
* V_63 &= ~ ( 1 << V_153 ) ;
}
if ( * V_63 & ( 1 << V_28 ) ) {
if ( F_28 ( V_59 [ V_28 ] , V_2 ,
V_5 , log ) < 0 )
return - V_66 ;
* V_63 &= ~ ( 1 << V_28 ) ;
}
if ( * V_63 & ( 1 << V_156 ) &&
F_63 ( V_140 , V_156 ) ) {
T_6 V_157 = F_27 ( V_59 [ V_156 ] ) ;
if ( V_157 & ~ V_158 ) {
F_7 ( log , L_34 ,
V_157 ) ;
return - V_66 ;
}
F_23 ( V_2 , V_157 , V_157 , V_5 ) ;
* V_63 &= ~ ( 1ULL << V_156 ) ;
}
if ( * V_63 & ( 1 << V_159 ) &&
F_63 ( V_140 , V_159 ) ) {
T_4 V_160 = F_64 ( V_59 [ V_159 ] ) ;
F_23 ( V_2 , V_160 , V_160 , V_5 ) ;
* V_63 &= ~ ( 1ULL << V_159 ) ;
}
if ( * V_63 & ( 1 << V_161 ) &&
F_63 ( V_140 , V_161 ) ) {
T_6 V_154 = F_27 ( V_59 [ V_161 ] ) ;
F_23 ( V_2 , V_162 . V_154 , V_154 , V_5 ) ;
* V_63 &= ~ ( 1ULL << V_161 ) ;
}
if ( * V_63 & ( 1 << V_163 ) &&
F_63 ( V_140 , V_163 ) ) {
const struct V_164 * V_165 ;
V_165 = F_19 ( V_59 [ V_163 ] ) ;
F_65 ( V_2 , V_162 . V_166 , V_165 -> V_167 ,
sizeof( * V_165 ) , V_5 ) ;
* V_63 &= ~ ( 1ULL << V_163 ) ;
}
if ( * V_63 & ( 1ULL << V_16 ) ) {
const struct V_168 * V_162 ;
V_162 = F_19 ( V_59 [ V_16 ] ) ;
F_23 ( V_2 , V_79 . V_169 . V_47 , V_162 -> V_170 , V_5 ) ;
F_23 ( V_2 , V_79 . V_169 . V_93 , V_162 -> V_171 , V_5 ) ;
F_23 ( V_2 , V_162 . V_172 . V_47 , V_162 -> V_173 , V_5 ) ;
F_23 ( V_2 , V_162 . V_172 . V_93 , V_162 -> V_174 , V_5 ) ;
F_23 ( V_2 , V_175 , V_162 -> V_176 , V_5 ) ;
* V_63 &= ~ ( 1ULL << V_16 ) ;
}
if ( * V_63 & ( 1ULL << V_18 ) ) {
const struct V_177 * V_162 ;
V_162 = F_19 ( V_59 [ V_18 ] ) ;
F_65 ( V_2 , V_80 . V_169 . V_47 , & V_162 -> V_178 ,
sizeof( V_2 -> V_31 -> V_80 . V_169 . V_47 ) ,
V_5 ) ;
F_65 ( V_2 , V_80 . V_169 . V_93 , & V_162 -> V_179 ,
sizeof( V_2 -> V_31 -> V_80 . V_169 . V_93 ) ,
V_5 ) ;
F_23 ( V_2 , V_162 . V_172 . V_47 , V_162 -> V_173 , V_5 ) ;
F_23 ( V_2 , V_162 . V_172 . V_93 , V_162 -> V_174 , V_5 ) ;
F_23 ( V_2 , V_175 , V_162 -> V_180 , V_5 ) ;
* V_63 &= ~ ( 1ULL << V_18 ) ;
}
if ( ! ( * V_63 & ( 1ULL << V_132 ) ) &&
( * V_63 & ( 1ULL << V_30 ) ) )
V_141 = V_181 ;
F_23 ( V_2 , V_141 , V_5 ? 0xff : V_141 , V_5 ) ;
if ( V_141 == V_181 )
return F_60 ( V_2 , V_63 , V_59 , V_5 ,
log ) ;
return 0 ;
}
static int F_66 ( struct V_140 * V_140 , struct V_1 * V_2 ,
T_2 V_63 , const struct V_57 * * V_59 ,
bool V_5 , bool log )
{
int V_83 ;
V_83 = F_62 ( V_140 , V_2 , & V_63 , V_59 , V_5 , log ) ;
if ( V_83 )
return V_83 ;
if ( V_63 & ( 1 << V_132 ) ) {
const struct V_182 * V_183 ;
V_183 = F_19 ( V_59 [ V_132 ] ) ;
F_65 ( V_2 , V_32 . V_47 ,
V_183 -> V_184 , V_185 , V_5 ) ;
F_65 ( V_2 , V_32 . V_93 ,
V_183 -> V_186 , V_185 , V_5 ) ;
V_63 &= ~ ( 1 << V_132 ) ;
if ( V_63 & ( 1 << V_129 ) ) {
F_7 ( log , L_35 ) ;
return - V_66 ;
}
if ( V_63 & ( 1 << V_30 ) ) {
V_83 = F_60 ( V_2 , & V_63 , V_59 , V_5 ,
log ) ;
if ( V_83 )
return V_83 ;
} else if ( ! V_5 ) {
F_23 ( V_2 , V_32 . type , F_5 ( V_187 ) , V_5 ) ;
}
} else if ( ! V_2 -> V_31 -> V_32 . type ) {
F_7 ( log , L_36 ) ;
return - V_66 ;
}
if ( V_63 & ( 1 << V_15 ) ) {
const struct V_188 * V_189 ;
V_189 = F_19 ( V_59 [ V_15 ] ) ;
if ( ! V_5 && V_189 -> V_190 > V_191 ) {
F_7 ( log , L_37 ,
V_189 -> V_190 , V_191 ) ;
return - V_66 ;
}
F_23 ( V_2 , V_36 . V_39 ,
V_189 -> V_176 , V_5 ) ;
F_23 ( V_2 , V_36 . V_97 ,
V_189 -> V_192 , V_5 ) ;
F_23 ( V_2 , V_36 . V_78 ,
V_189 -> V_193 , V_5 ) ;
F_23 ( V_2 , V_36 . V_37 ,
V_189 -> V_190 , V_5 ) ;
F_23 ( V_2 , V_79 . V_194 . V_47 ,
V_189 -> V_170 , V_5 ) ;
F_23 ( V_2 , V_79 . V_194 . V_93 ,
V_189 -> V_171 , V_5 ) ;
V_63 &= ~ ( 1 << V_15 ) ;
}
if ( V_63 & ( 1 << V_17 ) ) {
const struct V_195 * V_196 ;
V_196 = F_19 ( V_59 [ V_17 ] ) ;
if ( ! V_5 && V_196 -> V_197 > V_191 ) {
F_7 ( log , L_38 ,
V_196 -> V_197 , V_191 ) ;
return - V_66 ;
}
if ( ! V_5 && V_196 -> V_198 & F_67 ( 0xFFF00000 ) ) {
F_7 ( log , L_39 ,
F_68 ( V_196 -> V_198 ) , ( 1 << 20 ) - 1 ) ;
return - V_66 ;
}
F_23 ( V_2 , V_80 . V_199 ,
V_196 -> V_198 , V_5 ) ;
F_23 ( V_2 , V_36 . V_39 ,
V_196 -> V_180 , V_5 ) ;
F_23 ( V_2 , V_36 . V_97 ,
V_196 -> V_200 , V_5 ) ;
F_23 ( V_2 , V_36 . V_78 ,
V_196 -> V_201 , V_5 ) ;
F_23 ( V_2 , V_36 . V_37 ,
V_196 -> V_197 , V_5 ) ;
F_65 ( V_2 , V_80 . V_194 . V_47 ,
V_196 -> V_178 ,
sizeof( V_2 -> V_31 -> V_80 . V_194 . V_47 ) ,
V_5 ) ;
F_65 ( V_2 , V_80 . V_194 . V_93 ,
V_196 -> V_179 ,
sizeof( V_2 -> V_31 -> V_80 . V_194 . V_93 ) ,
V_5 ) ;
V_63 &= ~ ( 1 << V_17 ) ;
}
if ( V_63 & ( 1 << V_25 ) ) {
const struct V_202 * V_203 ;
V_203 = F_19 ( V_59 [ V_25 ] ) ;
if ( ! V_5 && ( V_203 -> V_204 & F_5 ( 0xff00 ) ) ) {
F_7 ( log , L_40 ,
V_203 -> V_204 ) ;
return - V_66 ;
}
F_23 ( V_2 , V_79 . V_194 . V_47 ,
V_203 -> V_205 , V_5 ) ;
F_23 ( V_2 , V_79 . V_194 . V_93 ,
V_203 -> V_206 , V_5 ) ;
F_23 ( V_2 , V_36 . V_39 ,
F_57 ( V_203 -> V_204 ) , V_5 ) ;
F_65 ( V_2 , V_79 . V_207 . V_208 ,
V_203 -> V_209 , V_185 , V_5 ) ;
F_65 ( V_2 , V_79 . V_207 . V_210 ,
V_203 -> V_211 , V_185 , V_5 ) ;
V_63 &= ~ ( 1 << V_25 ) ;
}
if ( V_63 & ( 1 << V_27 ) ) {
const struct V_212 * V_213 ;
V_213 = F_19 ( V_59 [ V_27 ] ) ;
F_23 ( V_2 , V_214 . V_215 ,
V_213 -> V_216 , V_5 ) ;
V_63 &= ~ ( 1 << V_27 ) ;
}
if ( V_63 & ( 1 << V_19 ) ) {
const struct V_217 * V_218 ;
V_218 = F_19 ( V_59 [ V_19 ] ) ;
F_23 ( V_2 , V_46 . V_47 , V_218 -> V_219 , V_5 ) ;
F_23 ( V_2 , V_46 . V_93 , V_218 -> V_220 , V_5 ) ;
V_63 &= ~ ( 1 << V_19 ) ;
}
if ( V_63 & ( 1 << V_20 ) ) {
F_23 ( V_2 , V_46 . V_221 ,
F_33 ( V_59 [ V_20 ] ) ,
V_5 ) ;
V_63 &= ~ ( 1 << V_20 ) ;
}
if ( V_63 & ( 1 << V_21 ) ) {
const struct V_222 * V_223 ;
V_223 = F_19 ( V_59 [ V_21 ] ) ;
F_23 ( V_2 , V_46 . V_47 , V_223 -> V_224 , V_5 ) ;
F_23 ( V_2 , V_46 . V_93 , V_223 -> V_225 , V_5 ) ;
V_63 &= ~ ( 1 << V_21 ) ;
}
if ( V_63 & ( 1 << V_22 ) ) {
const struct V_226 * V_227 ;
V_227 = F_19 ( V_59 [ V_22 ] ) ;
F_23 ( V_2 , V_46 . V_47 , V_227 -> V_228 , V_5 ) ;
F_23 ( V_2 , V_46 . V_93 , V_227 -> V_229 , V_5 ) ;
V_63 &= ~ ( 1 << V_22 ) ;
}
if ( V_63 & ( 1 << V_23 ) ) {
const struct V_230 * V_231 ;
V_231 = F_19 ( V_59 [ V_23 ] ) ;
F_23 ( V_2 , V_46 . V_47 ,
F_5 ( V_231 -> V_232 ) , V_5 ) ;
F_23 ( V_2 , V_46 . V_93 ,
F_5 ( V_231 -> V_233 ) , V_5 ) ;
V_63 &= ~ ( 1 << V_23 ) ;
}
if ( V_63 & ( 1 << V_24 ) ) {
const struct V_234 * V_235 ;
V_235 = F_19 ( V_59 [ V_24 ] ) ;
F_23 ( V_2 , V_46 . V_47 ,
F_5 ( V_235 -> V_236 ) , V_5 ) ;
F_23 ( V_2 , V_46 . V_93 ,
F_5 ( V_235 -> V_237 ) , V_5 ) ;
V_63 &= ~ ( 1 << V_24 ) ;
}
if ( V_63 & ( 1 << V_26 ) ) {
const struct V_238 * V_239 ;
V_239 = F_19 ( V_59 [ V_26 ] ) ;
F_65 ( V_2 , V_80 . V_240 . V_241 ,
V_239 -> V_242 ,
sizeof( V_2 -> V_31 -> V_80 . V_240 . V_241 ) ,
V_5 ) ;
F_65 ( V_2 , V_80 . V_240 . V_243 ,
V_239 -> V_244 , V_185 , V_5 ) ;
F_65 ( V_2 , V_80 . V_240 . V_245 ,
V_239 -> V_246 , V_185 , V_5 ) ;
V_63 &= ~ ( 1 << V_26 ) ;
}
if ( V_63 != 0 ) {
F_7 ( log , L_41 ,
( unsigned long long ) V_63 ) ;
return - V_66 ;
}
return 0 ;
}
static void F_69 ( struct V_57 * V_58 , T_3 V_247 ,
const struct V_248 * V_249 )
{
struct V_57 * V_62 ;
int V_64 ;
F_16 (nla, attr, rem) {
if ( V_249 [ F_17 ( V_62 ) ] . V_68 == V_53 ) {
if ( V_249 [ F_17 ( V_62 ) ] . V_250 )
V_249 = V_249 [ F_17 ( V_62 ) ] . V_250 ;
F_69 ( V_62 , V_247 , V_249 ) ;
} else {
memset ( F_19 ( V_62 ) , V_247 , F_18 ( V_62 ) ) ;
}
if ( F_17 ( V_62 ) == V_156 )
* ( T_6 * ) F_19 ( V_62 ) &= V_158 ;
}
}
static void F_70 ( struct V_57 * V_58 , T_3 V_247 )
{
F_69 ( V_58 , V_247 , V_67 ) ;
}
int F_71 ( struct V_140 * V_140 , struct V_1 * V_2 ,
const struct V_57 * V_251 ,
const struct V_57 * V_252 ,
bool log )
{
const struct V_57 * V_59 [ V_65 + 1 ] ;
struct V_57 * V_253 = NULL ;
T_2 V_11 = 0 ;
T_2 V_12 = 0 ;
int V_83 ;
V_83 = F_21 ( V_251 , V_59 , & V_11 , log ) ;
if ( V_83 )
return V_83 ;
V_83 = F_59 ( V_2 , & V_11 , V_59 , false , log ) ;
if ( V_83 )
return V_83 ;
V_83 = F_66 ( V_140 , V_2 , V_11 , V_59 , false , log ) ;
if ( V_83 )
return V_83 ;
if ( V_2 -> V_10 ) {
if ( ! V_252 ) {
V_253 = F_72 ( V_251 ,
F_10 ( F_18 ( V_251 ) ) ,
V_254 ) ;
if ( ! V_253 )
return - V_255 ;
F_70 ( V_253 , 0xff ) ;
if ( V_2 -> V_31 -> V_114 )
F_34 ( V_2 , V_87 ,
0xff , true ) ;
V_252 = V_253 ;
}
V_83 = F_20 ( V_252 , V_59 , & V_12 , log ) ;
if ( V_83 )
goto V_256;
F_23 ( V_2 , V_32 . V_130 . V_127 , F_5 ( 0xffff ) , true ) ;
F_23 ( V_2 , V_32 . V_131 . V_127 , F_5 ( 0xffff ) , true ) ;
V_83 = F_59 ( V_2 , & V_12 , V_59 , true , log ) ;
if ( V_83 )
goto V_256;
V_83 = F_66 ( V_140 , V_2 , V_12 , V_59 , true ,
log ) ;
if ( V_83 )
goto V_256;
}
if ( ! F_4 ( V_2 , V_11 , V_12 , log ) )
V_83 = - V_66 ;
V_256:
F_73 ( V_253 ) ;
return V_83 ;
}
static T_1 F_74 ( const struct V_57 * V_58 , bool log )
{
T_1 V_68 ;
if ( ! V_58 )
return 0 ;
V_68 = F_18 ( V_58 ) ;
if ( V_68 < 1 || V_68 > V_257 ) {
F_7 ( log , L_42 ,
F_18 ( V_58 ) , V_257 ) ;
return 0 ;
}
return V_68 ;
}
bool F_75 ( struct V_258 * V_259 , const struct V_57 * V_58 ,
bool log )
{
V_259 -> V_260 = F_74 ( V_58 , log ) ;
if ( V_259 -> V_260 )
memcpy ( V_259 -> V_261 , F_19 ( V_58 ) , V_259 -> V_260 ) ;
return V_259 -> V_260 ;
}
int F_76 ( struct V_258 * V_259 , const struct V_57 * V_261 ,
const struct V_262 * V_31 , bool log )
{
struct V_262 * V_263 ;
if ( F_75 ( V_259 , V_261 , log ) )
return 0 ;
V_263 = F_77 ( sizeof( * V_263 ) , V_254 ) ;
if ( ! V_263 )
return - V_255 ;
memcpy ( V_263 , V_31 , sizeof( * V_31 ) ) ;
V_259 -> V_264 = V_263 ;
return 0 ;
}
T_6 F_78 ( const struct V_57 * V_58 )
{
return V_58 ? F_27 ( V_58 ) : 0 ;
}
int F_79 ( struct V_140 * V_140 ,
const struct V_57 * V_59 [ V_65 + 1 ] ,
T_2 V_63 , struct V_262 * V_31 , bool log )
{
struct V_1 V_2 ;
memset ( & V_2 , 0 , sizeof( V_2 ) ) ;
V_2 . V_31 = V_31 ;
V_31 -> V_157 = 0 ;
V_31 -> V_160 = 0 ;
V_31 -> V_175 = 0 ;
memset ( & V_31 -> V_162 , 0 , sizeof( V_31 -> V_162 ) ) ;
memset ( & V_31 -> V_79 . V_169 , 0 , sizeof( V_31 -> V_79 . V_169 ) ) ;
memset ( & V_31 -> V_80 . V_169 , 0 , sizeof( V_31 -> V_80 . V_169 ) ) ;
V_31 -> V_149 . V_151 = V_152 ;
return F_62 ( V_140 , & V_2 , & V_63 , V_59 , false , log ) ;
}
static int F_80 ( struct V_117 * V_118 , const struct V_265 * V_266 ,
bool V_5 )
{
T_5 V_138 = ! V_5 ? V_266 -> V_128 : F_5 ( 0xffff ) ;
if ( F_46 ( V_118 , V_30 , V_138 ) ||
F_46 ( V_118 , V_129 , V_266 -> V_127 ) )
return - V_120 ;
return 0 ;
}
static int F_81 ( const struct V_262 * V_267 ,
const struct V_262 * V_122 , bool V_5 ,
struct V_117 * V_118 )
{
struct V_182 * V_183 ;
struct V_57 * V_62 ;
struct V_57 * V_137 = NULL ;
struct V_57 * V_268 = NULL ;
if ( F_38 ( V_118 , V_146 , V_122 -> V_147 ) )
goto V_269;
if ( F_38 ( V_118 , V_143 , V_122 -> V_145 ) )
goto V_269;
if ( F_38 ( V_118 , V_148 , V_122 -> V_149 . V_150 ) )
goto V_269;
if ( ( V_267 -> V_114 || V_5 ) ) {
const void * V_73 = NULL ;
if ( V_122 -> V_87 . V_81 & V_270 )
V_73 = F_82 ( V_122 , V_267 -> V_71 ) ;
if ( F_48 ( V_118 , & V_122 -> V_87 , V_73 ,
V_267 -> V_71 , V_267 -> V_114 ) )
goto V_269;
}
if ( V_267 -> V_149 . V_151 == V_152 ) {
if ( V_5 && ( V_122 -> V_149 . V_151 == 0xffff ) )
if ( F_38 ( V_118 , V_29 , 0xffffffff ) )
goto V_269;
} else {
T_4 V_271 ;
V_271 = ! V_5 ? 0 : 0xffff ;
if ( F_38 ( V_118 , V_29 ,
( V_271 << 16 ) | V_122 -> V_149 . V_151 ) )
goto V_269;
}
if ( F_38 ( V_118 , V_153 , V_122 -> V_149 . V_155 ) )
goto V_269;
if ( F_83 ( V_267 , V_122 , V_118 ) )
goto V_269;
if ( F_84 ( V_267 ) == V_142 ) {
V_62 = F_85 ( V_118 , V_132 , sizeof( * V_183 ) ) ;
if ( ! V_62 )
goto V_269;
V_183 = F_19 ( V_62 ) ;
F_86 ( V_183 -> V_184 , V_122 -> V_32 . V_47 ) ;
F_86 ( V_183 -> V_186 , V_122 -> V_32 . V_93 ) ;
if ( V_267 -> V_32 . V_130 . V_127 || F_55 ( V_267 -> V_32 . type ) ) {
if ( F_80 ( V_118 , & V_122 -> V_32 . V_130 , V_5 ) )
goto V_269;
V_137 = F_37 ( V_118 , V_133 ) ;
if ( ! V_267 -> V_32 . V_130 . V_127 )
goto V_272;
if ( V_267 -> V_32 . V_131 . V_127 || F_55 ( V_267 -> V_32 . type ) ) {
if ( F_80 ( V_118 , & V_122 -> V_32 . V_131 , V_5 ) )
goto V_269;
V_268 = F_37 ( V_118 , V_133 ) ;
if ( ! V_267 -> V_32 . V_131 . V_127 )
goto V_272;
}
}
if ( V_267 -> V_32 . type == F_5 ( V_187 ) ) {
if ( V_5 && V_122 -> V_32 . type )
if ( F_46 ( V_118 , V_30 ,
V_122 -> V_32 . type ) )
goto V_269;
goto V_272;
}
}
if ( F_46 ( V_118 , V_30 , V_122 -> V_32 . type ) )
goto V_269;
if ( F_55 ( V_267 -> V_32 . type ) ) {
F_87 ( ! ( V_137 && V_268 ) ) ;
goto V_272;
}
if ( V_267 -> V_32 . type == F_5 ( V_35 ) ) {
struct V_188 * V_189 ;
V_62 = F_85 ( V_118 , V_15 , sizeof( * V_189 ) ) ;
if ( ! V_62 )
goto V_269;
V_189 = F_19 ( V_62 ) ;
V_189 -> V_170 = V_122 -> V_79 . V_194 . V_47 ;
V_189 -> V_171 = V_122 -> V_79 . V_194 . V_93 ;
V_189 -> V_176 = V_122 -> V_36 . V_39 ;
V_189 -> V_192 = V_122 -> V_36 . V_97 ;
V_189 -> V_193 = V_122 -> V_36 . V_78 ;
V_189 -> V_190 = V_122 -> V_36 . V_37 ;
} else if ( V_267 -> V_32 . type == F_5 ( V_44 ) ) {
struct V_195 * V_196 ;
V_62 = F_85 ( V_118 , V_17 , sizeof( * V_196 ) ) ;
if ( ! V_62 )
goto V_269;
V_196 = F_19 ( V_62 ) ;
memcpy ( V_196 -> V_178 , & V_122 -> V_80 . V_194 . V_47 ,
sizeof( V_196 -> V_178 ) ) ;
memcpy ( V_196 -> V_179 , & V_122 -> V_80 . V_194 . V_93 ,
sizeof( V_196 -> V_179 ) ) ;
V_196 -> V_198 = V_122 -> V_80 . V_199 ;
V_196 -> V_180 = V_122 -> V_36 . V_39 ;
V_196 -> V_200 = V_122 -> V_36 . V_97 ;
V_196 -> V_201 = V_122 -> V_36 . V_78 ;
V_196 -> V_197 = V_122 -> V_36 . V_37 ;
} else if ( V_267 -> V_32 . type == F_5 ( V_33 ) ||
V_267 -> V_32 . type == F_5 ( V_34 ) ) {
struct V_202 * V_203 ;
V_62 = F_85 ( V_118 , V_25 , sizeof( * V_203 ) ) ;
if ( ! V_62 )
goto V_269;
V_203 = F_19 ( V_62 ) ;
memset ( V_203 , 0 , sizeof( struct V_202 ) ) ;
V_203 -> V_205 = V_122 -> V_79 . V_194 . V_47 ;
V_203 -> V_206 = V_122 -> V_79 . V_194 . V_93 ;
V_203 -> V_204 = F_5 ( V_122 -> V_36 . V_39 ) ;
F_86 ( V_203 -> V_209 , V_122 -> V_79 . V_207 . V_208 ) ;
F_86 ( V_203 -> V_211 , V_122 -> V_79 . V_207 . V_210 ) ;
} else if ( F_6 ( V_267 -> V_32 . type ) ) {
struct V_212 * V_213 ;
V_62 = F_85 ( V_118 , V_27 , sizeof( * V_213 ) ) ;
if ( ! V_62 )
goto V_269;
V_213 = F_19 ( V_62 ) ;
V_213 -> V_216 = V_122 -> V_214 . V_215 ;
}
if ( ( V_267 -> V_32 . type == F_5 ( V_35 ) ||
V_267 -> V_32 . type == F_5 ( V_44 ) ) &&
V_267 -> V_36 . V_37 != V_38 ) {
if ( V_267 -> V_36 . V_39 == V_42 ) {
struct V_217 * V_218 ;
V_62 = F_85 ( V_118 , V_19 , sizeof( * V_218 ) ) ;
if ( ! V_62 )
goto V_269;
V_218 = F_19 ( V_62 ) ;
V_218 -> V_219 = V_122 -> V_46 . V_47 ;
V_218 -> V_220 = V_122 -> V_46 . V_93 ;
if ( F_46 ( V_118 , V_20 ,
V_122 -> V_46 . V_221 ) )
goto V_269;
} else if ( V_267 -> V_36 . V_39 == V_40 ) {
struct V_222 * V_223 ;
V_62 = F_85 ( V_118 , V_21 , sizeof( * V_223 ) ) ;
if ( ! V_62 )
goto V_269;
V_223 = F_19 ( V_62 ) ;
V_223 -> V_224 = V_122 -> V_46 . V_47 ;
V_223 -> V_225 = V_122 -> V_46 . V_93 ;
} else if ( V_267 -> V_36 . V_39 == V_41 ) {
struct V_226 * V_227 ;
V_62 = F_85 ( V_118 , V_22 , sizeof( * V_227 ) ) ;
if ( ! V_62 )
goto V_269;
V_227 = F_19 ( V_62 ) ;
V_227 -> V_228 = V_122 -> V_46 . V_47 ;
V_227 -> V_229 = V_122 -> V_46 . V_93 ;
} else if ( V_267 -> V_32 . type == F_5 ( V_35 ) &&
V_267 -> V_36 . V_39 == V_43 ) {
struct V_230 * V_231 ;
V_62 = F_85 ( V_118 , V_23 , sizeof( * V_231 ) ) ;
if ( ! V_62 )
goto V_269;
V_231 = F_19 ( V_62 ) ;
V_231 -> V_232 = F_57 ( V_122 -> V_46 . V_47 ) ;
V_231 -> V_233 = F_57 ( V_122 -> V_46 . V_93 ) ;
} else if ( V_267 -> V_32 . type == F_5 ( V_44 ) &&
V_267 -> V_36 . V_39 == V_45 ) {
struct V_234 * V_235 ;
V_62 = F_85 ( V_118 , V_24 ,
sizeof( * V_235 ) ) ;
if ( ! V_62 )
goto V_269;
V_235 = F_19 ( V_62 ) ;
V_235 -> V_236 = F_57 ( V_122 -> V_46 . V_47 ) ;
V_235 -> V_237 = F_57 ( V_122 -> V_46 . V_93 ) ;
if ( V_235 -> V_236 == V_48 ||
V_235 -> V_236 == V_49 ) {
struct V_238 * V_239 ;
V_62 = F_85 ( V_118 , V_26 , sizeof( * V_239 ) ) ;
if ( ! V_62 )
goto V_269;
V_239 = F_19 ( V_62 ) ;
memcpy ( V_239 -> V_242 , & V_122 -> V_80 . V_240 . V_241 ,
sizeof( V_239 -> V_242 ) ) ;
F_86 ( V_239 -> V_244 , V_122 -> V_80 . V_240 . V_243 ) ;
F_86 ( V_239 -> V_246 , V_122 -> V_80 . V_240 . V_245 ) ;
}
}
}
V_272:
if ( V_268 )
F_39 ( V_118 , V_268 ) ;
if ( V_137 )
F_39 ( V_118 , V_137 ) ;
return 0 ;
V_269:
return - V_120 ;
}
int F_88 ( const struct V_262 * V_267 ,
const struct V_262 * V_122 , int V_58 , bool V_5 ,
struct V_117 * V_118 )
{
int V_83 ;
struct V_57 * V_62 ;
V_62 = F_37 ( V_118 , V_58 ) ;
if ( ! V_62 )
return - V_120 ;
V_83 = F_81 ( V_267 , V_122 , V_5 , V_118 ) ;
if ( V_83 )
return V_83 ;
F_39 ( V_118 , V_62 ) ;
return 0 ;
}
int F_89 ( const struct V_273 * V_274 , struct V_117 * V_118 )
{
if ( F_90 ( & V_274 -> V_275 ) )
return F_47 ( V_118 , V_276 , V_274 -> V_275 . V_260 ,
V_274 -> V_275 . V_261 ) ;
return F_88 ( V_274 -> V_275 . V_264 , V_274 -> V_275 . V_264 ,
V_277 , false , V_118 ) ;
}
int F_91 ( const struct V_273 * V_274 , struct V_117 * V_118 )
{
return F_88 ( & V_274 -> V_31 , & V_274 -> V_31 ,
V_277 , false , V_118 ) ;
}
int F_92 ( const struct V_273 * V_274 , struct V_117 * V_118 )
{
return F_88 ( & V_274 -> V_31 , & V_274 -> V_10 -> V_31 ,
V_278 , true , V_118 ) ;
}
static struct V_279 * F_93 ( int V_4 , bool log )
{
struct V_279 * V_280 ;
if ( V_4 > V_281 ) {
F_7 ( log , L_43 , V_4 ) ;
return F_94 ( - V_66 ) ;
}
V_280 = F_77 ( sizeof( * V_280 ) + V_4 , V_254 ) ;
if ( ! V_280 )
return F_94 ( - V_255 ) ;
V_280 -> V_282 = 0 ;
return V_280 ;
}
static void F_95 ( const struct V_57 * V_59 )
{
const struct V_57 * V_283 = F_19 ( V_59 ) ;
struct V_284 * V_285 ;
switch ( F_17 ( V_283 ) ) {
case V_50 :
V_285 = F_19 ( V_283 ) ;
F_96 ( (struct V_286 * ) V_285 -> V_287 ) ;
break;
}
}
void F_97 ( struct V_279 * V_288 )
{
const struct V_57 * V_59 ;
int V_64 ;
if ( ! V_288 )
return;
F_98 (a, sf_acts->actions, sf_acts->actions_len, rem) {
switch ( F_17 ( V_59 ) ) {
case V_289 :
F_95 ( V_59 ) ;
break;
case V_290 :
F_99 ( V_59 ) ;
break;
}
}
F_73 ( V_288 ) ;
}
static void F_100 ( struct V_291 * V_292 )
{
F_97 ( F_101 ( V_292 , struct V_279 , V_293 ) ) ;
}
void F_102 ( struct V_279 * V_288 )
{
F_103 ( & V_288 -> V_293 , F_100 ) ;
}
static struct V_57 * F_104 ( struct V_279 * * V_280 ,
int V_51 , bool log )
{
struct V_279 * V_294 ;
int V_295 ;
int V_296 = F_105 ( V_51 ) ;
int V_297 = F_106 ( struct V_279 , V_298 ) +
( * V_280 ) -> V_282 ;
if ( V_296 <= ( F_107 ( * V_280 ) - V_297 ) )
goto V_299;
V_295 = F_107 ( * V_280 ) * 2 ;
if ( V_295 > V_281 ) {
if ( ( V_281 - V_297 ) < V_296 )
return F_94 ( - V_120 ) ;
V_295 = V_281 ;
}
V_294 = F_93 ( V_295 , log ) ;
if ( F_108 ( V_294 ) )
return ( void * ) V_294 ;
memcpy ( V_294 -> V_298 , ( * V_280 ) -> V_298 , ( * V_280 ) -> V_282 ) ;
V_294 -> V_282 = ( * V_280 ) -> V_282 ;
V_294 -> V_300 = ( * V_280 ) -> V_300 ;
F_73 ( * V_280 ) ;
* V_280 = V_294 ;
V_299:
( * V_280 ) -> V_282 += V_296 ;
return (struct V_57 * ) ( ( unsigned char * ) ( * V_280 ) + V_297 ) ;
}
static struct V_57 * F_109 ( struct V_279 * * V_280 ,
int V_301 , void * V_302 , int V_68 , bool log )
{
struct V_57 * V_59 ;
V_59 = F_104 ( V_280 , F_110 ( V_68 ) , log ) ;
if ( F_108 ( V_59 ) )
return V_59 ;
V_59 -> F_17 = V_301 ;
V_59 -> F_18 = F_110 ( V_68 ) ;
if ( V_302 )
memcpy ( F_19 ( V_59 ) , V_302 , V_68 ) ;
memset ( ( unsigned char * ) V_59 + V_59 -> F_18 , 0 , F_111 ( V_68 ) ) ;
return V_59 ;
}
int F_112 ( struct V_279 * * V_280 , int V_301 , void * V_302 ,
int V_68 , bool log )
{
struct V_57 * V_59 ;
V_59 = F_109 ( V_280 , V_301 , V_302 , V_68 , log ) ;
return F_113 ( V_59 ) ;
}
static inline int F_114 ( struct V_279 * * V_280 ,
int V_301 , bool log )
{
int V_303 = ( * V_280 ) -> V_282 ;
int V_83 ;
V_83 = F_112 ( V_280 , V_301 , NULL , 0 , log ) ;
if ( V_83 )
return V_83 ;
return V_303 ;
}
static inline void F_115 ( struct V_279 * V_280 ,
int V_304 )
{
struct V_57 * V_59 = (struct V_57 * ) ( ( unsigned char * ) V_280 -> V_298 +
V_304 ) ;
V_59 -> F_18 = V_280 -> V_282 - V_304 ;
}
static int F_116 ( struct V_140 * V_140 , const struct V_57 * V_58 ,
const struct V_262 * V_31 , int V_305 ,
struct V_279 * * V_280 ,
T_5 V_138 , T_5 V_306 , bool log )
{
const struct V_57 * V_63 [ V_307 + 1 ] ;
const struct V_57 * V_308 , * V_298 ;
const struct V_57 * V_59 ;
int V_64 , V_8 , V_83 , V_309 ;
memset ( V_63 , 0 , sizeof( V_63 ) ) ;
F_16 (a, attr, rem) {
int type = F_17 ( V_59 ) ;
if ( ! type || type > V_307 || V_63 [ type ] )
return - V_66 ;
V_63 [ type ] = V_59 ;
}
if ( V_64 )
return - V_66 ;
V_308 = V_63 [ V_310 ] ;
if ( ! V_308 || F_18 ( V_308 ) != sizeof( T_6 ) )
return - V_66 ;
V_298 = V_63 [ V_311 ] ;
if ( ! V_298 || ( F_18 ( V_298 ) && F_18 ( V_298 ) < V_312 ) )
return - V_66 ;
V_8 = F_114 ( V_280 , V_313 , log ) ;
if ( V_8 < 0 )
return V_8 ;
V_83 = F_112 ( V_280 , V_310 ,
F_19 ( V_308 ) , sizeof( T_6 ) , log ) ;
if ( V_83 )
return V_83 ;
V_309 = F_114 ( V_280 , V_311 , log ) ;
if ( V_309 < 0 )
return V_309 ;
V_83 = F_117 ( V_140 , V_298 , V_31 , V_305 + 1 , V_280 ,
V_138 , V_306 , log ) ;
if ( V_83 )
return V_83 ;
F_115 ( * V_280 , V_309 ) ;
F_115 ( * V_280 , V_8 ) ;
return 0 ;
}
void F_118 ( struct V_1 * V_2 ,
struct V_262 * V_31 ,
bool V_314 ,
struct V_315 * V_10 )
{
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_31 = V_31 ;
V_2 -> V_10 = V_10 ;
if ( V_314 )
memset ( V_31 , 0 , sizeof( * V_31 ) ) ;
if ( V_10 ) {
memset ( & V_10 -> V_31 , 0 , sizeof( V_10 -> V_31 ) ) ;
V_10 -> V_7 . V_8 = V_10 -> V_7 . V_9 = 0 ;
}
}
static int F_119 ( struct V_262 * V_31 )
{
struct V_316 * V_317 ;
int V_318 = V_31 -> V_71 ;
bool V_319 = false ;
V_317 = (struct V_316 * ) F_82 ( V_31 , V_31 -> V_71 ) ;
while ( V_318 > 0 ) {
int V_68 ;
if ( V_318 < sizeof( * V_317 ) )
return - V_66 ;
V_68 = sizeof( * V_317 ) + V_317 -> V_320 * 4 ;
if ( V_68 > V_318 )
return - V_66 ;
V_319 |= ! ! ( V_317 -> type & V_321 ) ;
V_317 = (struct V_316 * ) ( ( T_3 * ) V_317 + V_68 ) ;
V_318 -= V_68 ;
} ;
V_31 -> V_87 . V_81 |= V_319 ? V_322 : 0 ;
return 0 ;
}
static int F_120 ( const struct V_57 * V_58 ,
struct V_279 * * V_280 , bool log )
{
struct V_1 V_2 ;
struct V_262 V_31 ;
struct V_323 * V_287 ;
struct V_123 * V_124 ;
struct V_284 * V_285 ;
struct V_57 * V_59 ;
int V_83 = 0 , V_8 , V_82 ;
F_118 ( & V_2 , & V_31 , true , NULL ) ;
V_82 = F_28 ( F_19 ( V_58 ) , & V_2 , false , log ) ;
if ( V_82 < 0 )
return V_82 ;
if ( V_31 . V_71 ) {
switch ( V_82 ) {
case V_109 :
V_83 = F_119 ( & V_31 ) ;
if ( V_83 < 0 )
return V_83 ;
break;
case V_111 :
break;
}
} ;
V_8 = F_114 ( V_280 , V_289 , log ) ;
if ( V_8 < 0 )
return V_8 ;
V_287 = F_121 ( V_31 . V_71 , V_254 ) ;
if ( ! V_287 )
return - V_255 ;
V_83 = F_122 ( & V_287 -> V_91 . V_124 . V_324 , V_254 ) ;
if ( V_83 ) {
F_96 ( (struct V_286 * ) V_287 ) ;
return V_83 ;
}
V_59 = F_109 ( V_280 , V_50 , NULL ,
sizeof( * V_285 ) , log ) ;
if ( F_108 ( V_59 ) ) {
F_96 ( (struct V_286 * ) V_287 ) ;
return F_123 ( V_59 ) ;
}
V_285 = F_19 ( V_59 ) ;
V_285 -> V_287 = V_287 ;
V_124 = & V_287 -> V_91 . V_124 ;
V_124 -> V_325 = V_326 ;
if ( V_31 . V_114 == V_115 )
V_124 -> V_325 |= V_327 ;
V_124 -> V_31 = V_31 . V_87 ;
F_124 ( V_124 ,
F_82 ( & V_31 , V_31 . V_71 ) ,
V_31 . V_71 ) ;
F_115 ( * V_280 , V_8 ) ;
return V_83 ;
}
static bool F_125 ( T_3 * V_302 , int V_68 )
{
T_3 * V_10 = V_302 + V_68 ;
while ( V_68 -- )
if ( * V_302 ++ & ~ * V_10 ++ )
return false ;
return true ;
}
static int F_126 ( const struct V_57 * V_59 ,
const struct V_262 * V_328 ,
struct V_279 * * V_280 , bool * V_329 ,
T_3 V_141 , T_5 V_138 , bool V_330 , bool log )
{
const struct V_57 * V_283 = F_19 ( V_59 ) ;
int V_331 = F_17 ( V_283 ) ;
T_1 V_332 ;
if ( F_10 ( F_18 ( V_283 ) ) != F_18 ( V_59 ) )
return - V_66 ;
V_332 = F_18 ( V_283 ) ;
if ( V_330 )
V_332 /= 2 ;
if ( V_331 > V_65 ||
! F_13 ( V_332 , V_67 [ V_331 ] . V_68 ) )
return - V_66 ;
if ( V_330 && ! F_125 ( F_19 ( V_283 ) , V_332 ) )
return - V_66 ;
switch ( V_331 ) {
const struct V_188 * V_189 ;
const struct V_195 * V_196 ;
int V_83 ;
case V_148 :
case V_153 :
case V_161 :
case V_163 :
break;
case V_132 :
if ( V_141 != V_142 )
return - V_66 ;
break;
case V_28 :
if ( V_330 )
return - V_66 ;
* V_329 = true ;
V_83 = F_120 ( V_59 , V_280 , log ) ;
if ( V_83 )
return V_83 ;
break;
case V_15 :
if ( V_138 != F_5 ( V_35 ) )
return - V_66 ;
V_189 = F_19 ( V_283 ) ;
if ( V_330 ) {
const struct V_188 * V_10 = V_189 + 1 ;
if ( V_10 -> V_176 || V_10 -> V_190 )
return - V_66 ;
} else {
if ( V_189 -> V_176 != V_328 -> V_36 . V_39 )
return - V_66 ;
if ( V_189 -> V_190 != V_328 -> V_36 . V_37 )
return - V_66 ;
}
break;
case V_17 :
if ( V_138 != F_5 ( V_44 ) )
return - V_66 ;
V_196 = F_19 ( V_283 ) ;
if ( V_330 ) {
const struct V_195 * V_10 = V_196 + 1 ;
if ( V_10 -> V_180 || V_10 -> V_197 )
return - V_66 ;
if ( F_68 ( V_10 -> V_198 ) & 0xFFF00000 )
return - V_66 ;
} else {
if ( V_196 -> V_180 != V_328 -> V_36 . V_39 )
return - V_66 ;
if ( V_196 -> V_197 != V_328 -> V_36 . V_37 )
return - V_66 ;
}
if ( F_68 ( V_196 -> V_198 ) & 0xFFF00000 )
return - V_66 ;
break;
case V_19 :
if ( ( V_138 != F_5 ( V_35 ) &&
V_138 != F_5 ( V_44 ) ) ||
V_328 -> V_36 . V_39 != V_42 )
return - V_66 ;
break;
case V_21 :
if ( ( V_138 != F_5 ( V_35 ) &&
V_138 != F_5 ( V_44 ) ) ||
V_328 -> V_36 . V_39 != V_40 )
return - V_66 ;
break;
case V_27 :
if ( ! F_6 ( V_138 ) )
return - V_66 ;
break;
case V_22 :
if ( ( V_138 != F_5 ( V_35 ) &&
V_138 != F_5 ( V_44 ) ) ||
V_328 -> V_36 . V_39 != V_41 )
return - V_66 ;
break;
default:
return - V_66 ;
}
if ( ! V_330 && V_331 != V_28 ) {
int V_8 , V_68 = V_332 * 2 ;
struct V_57 * V_333 ;
* V_329 = true ;
V_8 = F_114 ( V_280 ,
V_334 ,
log ) ;
if ( V_8 < 0 )
return V_8 ;
V_333 = F_109 ( V_280 , V_331 , NULL , V_68 , log ) ;
if ( F_108 ( V_333 ) )
return F_123 ( V_333 ) ;
memcpy ( F_19 ( V_333 ) , F_19 ( V_283 ) , V_332 ) ;
memset ( F_19 ( V_333 ) + V_332 , 0xff , V_332 ) ;
if ( V_331 == V_17 ) {
struct V_195 * V_10 = F_19 ( V_333 ) + V_332 ;
V_10 -> V_198 &= F_67 ( 0x000FFFFF ) ;
}
F_115 ( * V_280 , V_8 ) ;
}
return 0 ;
}
static int F_127 ( const struct V_57 * V_58 )
{
static const struct V_335 V_336 [ V_337 + 1 ] = {
[ V_338 ] = { . type = V_339 } ,
[ V_340 ] = { . type = V_341 } ,
[ V_342 ] = { . type = V_339 } ,
} ;
struct V_57 * V_59 [ V_337 + 1 ] ;
int error ;
error = F_128 ( V_59 , V_337 ,
V_58 , V_336 ) ;
if ( error )
return error ;
if ( ! V_59 [ V_338 ] ||
! F_27 ( V_59 [ V_338 ] ) )
return - V_66 ;
return 0 ;
}
static int F_129 ( const struct V_57 * V_343 ,
struct V_279 * * V_280 , bool log )
{
int V_344 = F_105 ( V_343 -> F_18 ) ;
struct V_57 * V_345 ;
V_345 = F_104 ( V_280 , V_343 -> F_18 , log ) ;
if ( F_108 ( V_345 ) )
return F_123 ( V_345 ) ;
memcpy ( V_345 , V_343 , V_344 ) ;
return 0 ;
}
static int F_117 ( struct V_140 * V_140 , const struct V_57 * V_58 ,
const struct V_262 * V_31 ,
int V_305 , struct V_279 * * V_280 ,
T_5 V_138 , T_5 V_306 , bool log )
{
T_3 V_141 = F_84 ( V_31 ) ;
const struct V_57 * V_59 ;
int V_64 , V_83 ;
if ( V_305 >= V_346 )
return - V_347 ;
F_16 (a, attr, rem) {
static const T_6 V_348 [ V_349 + 1 ] = {
[ V_350 ] = sizeof( T_6 ) ,
[ V_351 ] = sizeof( T_6 ) ,
[ V_352 ] = ( T_6 ) - 1 ,
[ V_353 ] = sizeof( struct V_354 ) ,
[ V_355 ] = sizeof( T_5 ) ,
[ V_356 ] = sizeof( struct V_357 ) ,
[ V_358 ] = 0 ,
[ V_289 ] = ( T_6 ) - 1 ,
[ V_359 ] = ( T_6 ) - 1 ,
[ V_313 ] = ( T_6 ) - 1 ,
[ V_360 ] = sizeof( struct V_361 ) ,
[ V_290 ] = ( T_6 ) - 1 ,
[ V_362 ] = sizeof( struct V_363 ) ,
[ V_364 ] = sizeof( struct V_365 ) ,
[ V_366 ] = 0 ,
} ;
const struct V_357 * V_130 ;
int type = F_17 ( V_59 ) ;
bool V_329 ;
if ( type > V_349 ||
( V_348 [ type ] != F_18 ( V_59 ) &&
V_348 [ type ] != ( T_6 ) - 1 ) )
return - V_66 ;
V_329 = false ;
switch ( type ) {
case V_367 :
return - V_66 ;
case V_352 :
V_83 = F_127 ( V_59 ) ;
if ( V_83 )
return V_83 ;
break;
case V_350 :
if ( F_27 ( V_59 ) >= V_152 )
return - V_66 ;
break;
case V_362 : {
const struct V_363 * V_368 = F_19 ( V_59 ) ;
if ( V_368 -> V_369 < V_370 )
return - V_66 ;
break;
}
case V_360 : {
const struct V_361 * V_371 = F_19 ( V_59 ) ;
switch ( V_371 -> V_372 ) {
case V_373 :
break;
default:
return - V_66 ;
}
break;
}
case V_358 :
if ( V_141 != V_142 )
return - V_66 ;
V_306 = F_5 ( 0 ) ;
break;
case V_356 :
if ( V_141 != V_142 )
return - V_66 ;
V_130 = F_19 ( V_59 ) ;
if ( ! F_55 ( V_130 -> V_374 ) )
return - V_66 ;
if ( ! ( V_130 -> V_306 & F_5 ( V_134 ) ) )
return - V_66 ;
V_306 = V_130 -> V_306 ;
break;
case V_351 :
break;
case V_353 : {
const struct V_354 * V_214 = F_19 ( V_59 ) ;
if ( ! F_6 ( V_214 -> V_375 ) )
return - V_66 ;
if ( V_306 & F_5 ( V_134 ) ||
( V_138 != F_5 ( V_35 ) &&
V_138 != F_5 ( V_44 ) &&
V_138 != F_5 ( V_33 ) &&
V_138 != F_5 ( V_34 ) &&
! F_6 ( V_138 ) ) )
return - V_66 ;
V_138 = V_214 -> V_375 ;
break;
}
case V_355 :
if ( V_306 & F_5 ( V_134 ) ||
! F_6 ( V_138 ) )
return - V_66 ;
V_138 = F_5 ( 0 ) ;
break;
case V_289 :
V_83 = F_126 ( V_59 , V_31 , V_280 ,
& V_329 , V_141 , V_138 ,
false , log ) ;
if ( V_83 )
return V_83 ;
break;
case V_359 :
V_83 = F_126 ( V_59 , V_31 , V_280 ,
& V_329 , V_141 , V_138 ,
true , log ) ;
if ( V_83 )
return V_83 ;
break;
case V_313 :
V_83 = F_116 ( V_140 , V_59 , V_31 , V_305 , V_280 ,
V_138 , V_306 , log ) ;
if ( V_83 )
return V_83 ;
V_329 = true ;
break;
case V_290 :
V_83 = F_130 ( V_140 , V_59 , V_31 , V_280 , log ) ;
if ( V_83 )
return V_83 ;
V_329 = true ;
break;
case V_364 :
if ( V_141 != V_181 )
return - V_66 ;
V_141 = V_181 ;
break;
case V_366 :
if ( V_141 != V_142 )
return - V_66 ;
if ( V_306 & F_5 ( V_134 ) )
return - V_66 ;
V_141 = V_142 ;
break;
default:
F_7 ( log , L_44 , type ) ;
return - V_66 ;
}
if ( ! V_329 ) {
V_83 = F_129 ( V_59 , V_280 , log ) ;
if ( V_83 )
return V_83 ;
}
}
if ( V_64 > 0 )
return - V_66 ;
return 0 ;
}
int F_131 ( struct V_140 * V_140 , const struct V_57 * V_58 ,
const struct V_262 * V_31 ,
struct V_279 * * V_280 , bool log )
{
int V_83 ;
* V_280 = F_93 ( F_18 ( V_58 ) , log ) ;
if ( F_108 ( * V_280 ) )
return F_123 ( * V_280 ) ;
( * V_280 ) -> V_300 = F_18 ( V_58 ) ;
V_83 = F_117 ( V_140 , V_58 , V_31 , 0 , V_280 , V_31 -> V_32 . type ,
V_31 -> V_32 . V_130 . V_127 , log ) ;
if ( V_83 )
F_97 ( * V_280 ) ;
return V_83 ;
}
static int F_132 ( const struct V_57 * V_58 , struct V_117 * V_118 )
{
const struct V_57 * V_59 ;
struct V_57 * V_8 ;
int V_83 = 0 , V_64 ;
V_8 = F_37 ( V_118 , V_313 ) ;
if ( ! V_8 )
return - V_120 ;
F_16 (a, attr, rem) {
int type = F_17 ( V_59 ) ;
struct V_57 * V_376 ;
switch ( type ) {
case V_310 :
if ( F_47 ( V_118 , V_310 ,
sizeof( T_6 ) , F_19 ( V_59 ) ) )
return - V_120 ;
break;
case V_311 :
V_376 = F_37 ( V_118 , V_311 ) ;
if ( ! V_376 )
return - V_120 ;
V_83 = F_133 ( F_19 ( V_59 ) , F_18 ( V_59 ) , V_118 ) ;
if ( V_83 )
return V_83 ;
F_39 ( V_118 , V_376 ) ;
break;
}
}
F_39 ( V_118 , V_8 ) ;
return V_83 ;
}
static int F_134 ( const struct V_57 * V_59 , struct V_117 * V_118 )
{
const struct V_57 * V_283 = F_19 ( V_59 ) ;
int V_331 = F_17 ( V_283 ) ;
struct V_57 * V_8 ;
int V_83 ;
switch ( V_331 ) {
case V_50 : {
struct V_284 * V_285 = F_19 ( V_283 ) ;
struct V_123 * V_124 = & V_285 -> V_287 -> V_91 . V_124 ;
V_8 = F_37 ( V_118 , V_289 ) ;
if ( ! V_8 )
return - V_120 ;
V_83 = F_48 ( V_118 , & V_124 -> V_31 ,
F_50 ( V_124 ) ,
V_124 -> V_125 ,
F_51 ( V_124 ) ) ;
if ( V_83 )
return V_83 ;
F_39 ( V_118 , V_8 ) ;
break;
}
default:
if ( F_47 ( V_118 , V_289 , F_18 ( V_59 ) , V_283 ) )
return - V_120 ;
break;
}
return 0 ;
}
static int F_135 ( const struct V_57 * V_59 ,
struct V_117 * V_118 )
{
const struct V_57 * V_283 = F_19 ( V_59 ) ;
struct V_57 * V_62 ;
T_1 V_332 = F_18 ( V_283 ) / 2 ;
V_62 = F_37 ( V_118 , V_289 ) ;
if ( ! V_62 )
return - V_120 ;
if ( F_47 ( V_118 , F_17 ( V_283 ) , V_332 , F_19 ( V_283 ) ) )
return - V_120 ;
F_39 ( V_118 , V_62 ) ;
return 0 ;
}
int F_133 ( const struct V_57 * V_58 , int V_68 , struct V_117 * V_118 )
{
const struct V_57 * V_59 ;
int V_64 , V_83 ;
F_98 (a, attr, len, rem) {
int type = F_17 ( V_59 ) ;
switch ( type ) {
case V_289 :
V_83 = F_134 ( V_59 , V_118 ) ;
if ( V_83 )
return V_83 ;
break;
case V_334 :
V_83 = F_135 ( V_59 , V_118 ) ;
if ( V_83 )
return V_83 ;
break;
case V_313 :
V_83 = F_132 ( V_59 , V_118 ) ;
if ( V_83 )
return V_83 ;
break;
case V_290 :
V_83 = F_136 ( F_19 ( V_59 ) , V_118 ) ;
if ( V_83 )
return V_83 ;
break;
default:
if ( F_47 ( V_118 , type , F_18 ( V_59 ) , F_19 ( V_59 ) ) )
return - V_120 ;
break;
}
}
return 0 ;
}
