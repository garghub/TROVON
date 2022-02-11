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
| ( 1 << V_25 ) ) ;
V_14 |= ( ( 1 << V_26 )
| ( 1 << V_27 )
| ( 1 << V_28 ) ) ;
if ( V_2 -> V_29 -> V_30 . type == F_5 ( V_31 )
|| V_2 -> V_29 -> V_30 . type == F_5 ( V_32 ) ) {
V_13 |= 1 << V_23 ;
if ( V_2 -> V_10 && ( V_2 -> V_10 -> V_29 . V_30 . type == F_5 ( 0xffff ) ) )
V_14 |= 1 << V_23 ;
}
if ( F_6 ( V_2 -> V_29 -> V_30 . type ) ) {
V_13 |= 1 << V_25 ;
if ( V_2 -> V_10 && ( V_2 -> V_10 -> V_29 . V_30 . type == F_5 ( 0xffff ) ) )
V_14 |= 1 << V_25 ;
}
if ( V_2 -> V_29 -> V_30 . type == F_5 ( V_33 ) ) {
V_13 |= 1 << V_15 ;
if ( V_2 -> V_10 && ( V_2 -> V_10 -> V_29 . V_30 . type == F_5 ( 0xffff ) ) )
V_14 |= 1 << V_15 ;
if ( V_2 -> V_29 -> V_34 . V_35 != V_36 ) {
if ( V_2 -> V_29 -> V_34 . V_37 == V_38 ) {
V_13 |= 1 << V_19 ;
if ( V_2 -> V_10 && ( V_2 -> V_10 -> V_29 . V_34 . V_37 == 0xff ) )
V_14 |= 1 << V_19 ;
}
if ( V_2 -> V_29 -> V_34 . V_37 == V_39 ) {
V_13 |= 1 << V_20 ;
if ( V_2 -> V_10 && ( V_2 -> V_10 -> V_29 . V_34 . V_37 == 0xff ) )
V_14 |= 1 << V_20 ;
}
if ( V_2 -> V_29 -> V_34 . V_37 == V_40 ) {
V_13 |= 1 << V_17 ;
V_13 |= 1 << V_18 ;
if ( V_2 -> V_10 && ( V_2 -> V_10 -> V_29 . V_34 . V_37 == 0xff ) ) {
V_14 |= 1 << V_17 ;
V_14 |= 1 << V_18 ;
}
}
if ( V_2 -> V_29 -> V_34 . V_37 == V_41 ) {
V_13 |= 1 << V_21 ;
if ( V_2 -> V_10 && ( V_2 -> V_10 -> V_29 . V_34 . V_37 == 0xff ) )
V_14 |= 1 << V_21 ;
}
}
}
if ( V_2 -> V_29 -> V_30 . type == F_5 ( V_42 ) ) {
V_13 |= 1 << V_16 ;
if ( V_2 -> V_10 && ( V_2 -> V_10 -> V_29 . V_30 . type == F_5 ( 0xffff ) ) )
V_14 |= 1 << V_16 ;
if ( V_2 -> V_29 -> V_34 . V_35 != V_36 ) {
if ( V_2 -> V_29 -> V_34 . V_37 == V_38 ) {
V_13 |= 1 << V_19 ;
if ( V_2 -> V_10 && ( V_2 -> V_10 -> V_29 . V_34 . V_37 == 0xff ) )
V_14 |= 1 << V_19 ;
}
if ( V_2 -> V_29 -> V_34 . V_37 == V_39 ) {
V_13 |= 1 << V_20 ;
if ( V_2 -> V_10 && ( V_2 -> V_10 -> V_29 . V_34 . V_37 == 0xff ) )
V_14 |= 1 << V_20 ;
}
if ( V_2 -> V_29 -> V_34 . V_37 == V_40 ) {
V_13 |= 1 << V_17 ;
V_13 |= 1 << V_18 ;
if ( V_2 -> V_10 && ( V_2 -> V_10 -> V_29 . V_34 . V_37 == 0xff ) ) {
V_14 |= 1 << V_17 ;
V_14 |= 1 << V_18 ;
}
}
if ( V_2 -> V_29 -> V_34 . V_37 == V_43 ) {
V_13 |= 1 << V_22 ;
if ( V_2 -> V_10 && ( V_2 -> V_10 -> V_29 . V_34 . V_37 == 0xff ) )
V_14 |= 1 << V_22 ;
if ( V_2 -> V_29 -> V_44 . V_45 ==
F_5 ( V_46 ) ||
V_2 -> V_29 -> V_44 . V_45 == F_5 ( V_47 ) ) {
V_13 |= 1 << V_24 ;
if ( V_2 -> V_10 && ( V_2 -> V_10 -> V_29 . V_44 . V_45 == F_5 ( 0xff ) ) )
V_14 |= 1 << V_24 ;
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
F_12 ( V_48 != 26 ) ;
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
static bool F_13 ( unsigned int V_49 , unsigned int V_50 )
{
return V_50 == V_49 ||
V_50 == V_51 ||
V_50 == V_52 ;
}
static bool F_14 ( const T_3 * V_53 , T_1 V_4 )
{
int V_54 ;
if ( ! V_53 )
return false ;
for ( V_54 = 0 ; V_54 < V_4 ; V_54 ++ )
if ( V_53 [ V_54 ] )
return false ;
return true ;
}
static int F_15 ( const struct V_55 * V_56 ,
const struct V_55 * V_57 [] ,
T_2 * V_58 , bool log , bool V_59 )
{
const struct V_55 * V_60 ;
T_2 V_61 ;
int V_62 ;
V_61 = * V_58 ;
F_16 (nla, attr, rem) {
T_4 type = F_17 ( V_60 ) ;
int V_50 ;
if ( type > V_63 ) {
F_7 ( log , L_3 ,
type , V_63 ) ;
return - V_64 ;
}
if ( V_61 & ( 1 << type ) ) {
F_7 ( log , L_4 , type ) ;
return - V_64 ;
}
V_50 = V_65 [ type ] . V_66 ;
if ( ! F_13 ( F_18 ( V_60 ) , V_50 ) ) {
F_7 ( log , L_5 ,
type , F_18 ( V_60 ) , V_50 ) ;
return - V_64 ;
}
if ( ! V_59 || ! F_14 ( F_19 ( V_60 ) , V_50 ) ) {
V_61 |= 1 << type ;
V_57 [ type ] = V_60 ;
}
}
if ( V_62 ) {
F_7 ( log , L_6 , V_62 ) ;
return - V_64 ;
}
* V_58 = V_61 ;
return 0 ;
}
static int F_20 ( const struct V_55 * V_56 ,
const struct V_55 * V_57 [] , T_2 * V_58 ,
bool log )
{
return F_15 ( V_56 , V_57 , V_58 , log , true ) ;
}
static int F_21 ( const struct V_55 * V_56 ,
const struct V_55 * V_57 [] , T_2 * V_58 ,
bool log )
{
return F_15 ( V_56 , V_57 , V_58 , log , false ) ;
}
static int F_22 ( const struct V_55 * V_57 ,
struct V_1 * V_2 , bool V_5 ,
bool log )
{
unsigned long V_67 ;
if ( F_18 ( V_57 ) > sizeof( V_2 -> V_29 -> V_68 ) ) {
F_7 ( log , L_7 ,
F_18 ( V_57 ) , sizeof( V_2 -> V_29 -> V_68 ) ) ;
return - V_64 ;
}
if ( F_18 ( V_57 ) % 4 != 0 ) {
F_7 ( log , L_8 ,
F_18 ( V_57 ) ) ;
return - V_64 ;
}
if ( ! V_5 ) {
F_23 ( V_2 , V_69 , F_18 ( V_57 ) ,
false ) ;
} else {
if ( V_2 -> V_29 -> V_69 != F_18 ( V_57 ) ) {
F_7 ( log , L_9 ,
V_2 -> V_29 -> V_69 , F_18 ( V_57 ) ) ;
return - V_64 ;
}
F_23 ( V_2 , V_69 , 0xff , true ) ;
}
V_67 = F_24 ( F_18 ( V_57 ) ) ;
F_25 ( V_2 , V_67 , F_19 ( V_57 ) ,
F_18 ( V_57 ) , V_5 ) ;
return 0 ;
}
static int F_26 ( const struct V_55 * V_56 ,
struct V_1 * V_2 , bool V_5 ,
bool log )
{
struct V_55 * V_57 ;
int V_62 ;
unsigned long V_67 ;
struct V_70 V_71 ;
F_12 ( sizeof( V_71 ) > sizeof( V_2 -> V_29 -> V_68 ) ) ;
memset ( & V_71 , 0 , sizeof( V_71 ) ) ;
F_16 (a, attr, rem) {
int type = F_17 ( V_57 ) ;
if ( type > V_72 ) {
F_7 ( log , L_10 ,
type , V_72 ) ;
return - V_64 ;
}
if ( ! F_13 ( F_18 ( V_57 ) ,
V_73 [ type ] . V_66 ) ) {
F_7 ( log , L_11 ,
type , F_18 ( V_57 ) ,
V_73 [ type ] . V_66 ) ;
return - V_64 ;
}
switch ( type ) {
case V_74 :
V_71 . V_75 = F_27 ( V_57 ) ;
break;
default:
F_7 ( log , L_12 ,
type ) ;
return - V_64 ;
}
}
if ( V_62 ) {
F_7 ( log , L_13 ,
V_62 ) ;
return - V_64 ;
}
if ( ! V_5 )
F_23 ( V_2 , V_69 , sizeof( V_71 ) , false ) ;
else
F_23 ( V_2 , V_69 , 0xff , true ) ;
V_67 = F_24 ( sizeof( V_71 ) ) ;
F_25 ( V_2 , V_67 , & V_71 , sizeof( V_71 ) ,
V_5 ) ;
return 0 ;
}
static int F_28 ( const struct V_55 * V_56 ,
struct V_1 * V_2 , bool V_5 ,
bool log )
{
bool V_76 = false , V_77 = false , V_78 = false ;
T_5 V_79 = 0 ;
int V_80 = 0 ;
struct V_55 * V_57 ;
int V_62 ;
F_16 (a, attr, rem) {
int type = F_17 ( V_57 ) ;
int V_81 ;
if ( type > V_82 ) {
F_7 ( log , L_14 ,
type , V_82 ) ;
return - V_64 ;
}
if ( ! F_13 ( F_18 ( V_57 ) ,
V_83 [ type ] . V_66 ) ) {
F_7 ( log , L_15 ,
type , F_18 ( V_57 ) , V_83 [ type ] . V_66 ) ;
return - V_64 ;
}
switch ( type ) {
case V_84 :
F_23 ( V_2 , V_85 . V_86 ,
F_29 ( V_57 ) , V_5 ) ;
V_79 |= V_87 ;
break;
case V_88 :
F_23 ( V_2 , V_85 . V_89 . V_77 . V_45 ,
F_30 ( V_57 ) , V_5 ) ;
V_77 = true ;
break;
case V_90 :
F_23 ( V_2 , V_85 . V_89 . V_77 . V_91 ,
F_30 ( V_57 ) , V_5 ) ;
V_77 = true ;
break;
case V_92 :
F_23 ( V_2 , V_85 . V_89 . V_78 . V_91 ,
F_31 ( V_57 ) , V_5 ) ;
V_78 = true ;
break;
case V_93 :
F_23 ( V_2 , V_85 . V_89 . V_78 . V_91 ,
F_31 ( V_57 ) , V_5 ) ;
V_78 = true ;
break;
case V_94 :
F_23 ( V_2 , V_85 . V_95 ,
F_32 ( V_57 ) , V_5 ) ;
break;
case V_96 :
F_23 ( V_2 , V_85 . V_76 ,
F_32 ( V_57 ) , V_5 ) ;
V_76 = true ;
break;
case V_97 :
V_79 |= V_98 ;
break;
case V_99 :
V_79 |= V_100 ;
break;
case V_101 :
F_23 ( V_2 , V_85 . V_102 ,
F_33 ( V_57 ) , V_5 ) ;
break;
case V_103 :
F_23 ( V_2 , V_85 . V_104 ,
F_33 ( V_57 ) , V_5 ) ;
break;
case V_105 :
V_79 |= V_106 ;
break;
case V_107 :
if ( V_80 ) {
F_7 ( log , L_16 ) ;
return - V_64 ;
}
V_81 = F_22 ( V_57 , V_2 , V_5 , log ) ;
if ( V_81 )
return V_81 ;
V_79 |= V_108 ;
V_80 = type ;
break;
case V_109 :
if ( V_80 ) {
F_7 ( log , L_16 ) ;
return - V_64 ;
}
V_81 = F_26 ( V_57 , V_2 , V_5 , log ) ;
if ( V_81 )
return V_81 ;
V_79 |= V_110 ;
V_80 = type ;
break;
default:
F_7 ( log , L_17 ,
type ) ;
return - V_64 ;
}
}
F_23 ( V_2 , V_85 . V_79 , V_79 , V_5 ) ;
if ( V_5 )
F_34 ( V_2 , V_111 , 0xff , true ) ;
else
F_23 ( V_2 , V_111 , V_78 ? V_112 : V_113 ,
false ) ;
if ( V_62 > 0 ) {
F_7 ( log , L_18 ,
V_62 ) ;
return - V_64 ;
}
if ( V_77 && V_78 ) {
F_7 ( log , L_19 ) ;
return - V_64 ;
}
if ( ! V_5 ) {
if ( ! V_77 && ! V_78 ) {
F_7 ( log , L_20 ) ;
return - V_64 ;
}
if ( V_77 && ! V_2 -> V_29 -> V_85 . V_89 . V_77 . V_91 ) {
F_7 ( log , L_21 ) ;
return - V_64 ;
}
if ( V_78 && F_35 ( & V_2 -> V_29 -> V_85 . V_89 . V_78 . V_91 ) ) {
F_7 ( log , L_22 ) ;
return - V_64 ;
}
if ( ! V_76 ) {
F_7 ( log , L_23 ) ;
return - V_64 ;
}
}
return V_80 ;
}
static int F_36 ( struct V_114 * V_115 ,
const void * V_68 , int V_116 )
{
const struct V_70 * V_71 = V_68 ;
struct V_55 * V_60 ;
V_60 = F_37 ( V_115 , V_109 ) ;
if ( ! V_60 )
return - V_117 ;
if ( F_38 ( V_115 , V_74 , V_71 -> V_75 ) < 0 )
return - V_117 ;
F_39 ( V_115 , V_60 ) ;
return 0 ;
}
static int F_40 ( struct V_114 * V_115 ,
const struct V_118 * V_119 ,
const void * V_68 , int V_116 ,
unsigned short V_111 )
{
if ( V_119 -> V_79 & V_87 &&
F_41 ( V_115 , V_84 , V_119 -> V_86 ,
V_120 ) )
return - V_117 ;
switch ( V_111 ) {
case V_113 :
if ( V_119 -> V_89 . V_77 . V_45 &&
F_42 ( V_115 , V_88 ,
V_119 -> V_89 . V_77 . V_45 ) )
return - V_117 ;
if ( V_119 -> V_89 . V_77 . V_91 &&
F_42 ( V_115 , V_90 ,
V_119 -> V_89 . V_77 . V_91 ) )
return - V_117 ;
break;
case V_112 :
if ( ! F_35 ( & V_119 -> V_89 . V_78 . V_45 ) &&
F_43 ( V_115 , V_92 ,
& V_119 -> V_89 . V_78 . V_45 ) )
return - V_117 ;
if ( ! F_35 ( & V_119 -> V_89 . V_78 . V_91 ) &&
F_43 ( V_115 , V_93 ,
& V_119 -> V_89 . V_78 . V_91 ) )
return - V_117 ;
break;
}
if ( V_119 -> V_95 &&
F_44 ( V_115 , V_94 , V_119 -> V_95 ) )
return - V_117 ;
if ( F_44 ( V_115 , V_96 , V_119 -> V_76 ) )
return - V_117 ;
if ( ( V_119 -> V_79 & V_98 ) &&
F_45 ( V_115 , V_97 ) )
return - V_117 ;
if ( ( V_119 -> V_79 & V_100 ) &&
F_45 ( V_115 , V_99 ) )
return - V_117 ;
if ( V_119 -> V_102 &&
F_46 ( V_115 , V_101 , V_119 -> V_102 ) )
return - V_117 ;
if ( V_119 -> V_104 &&
F_46 ( V_115 , V_103 , V_119 -> V_104 ) )
return - V_117 ;
if ( ( V_119 -> V_79 & V_106 ) &&
F_45 ( V_115 , V_105 ) )
return - V_117 ;
if ( V_116 ) {
if ( V_119 -> V_79 & V_108 &&
F_47 ( V_115 , V_107 ,
V_116 , V_68 ) )
return - V_117 ;
else if ( V_119 -> V_79 & V_110 &&
F_36 ( V_115 , V_68 , V_116 ) )
return - V_117 ;
}
return 0 ;
}
static int F_48 ( struct V_114 * V_115 ,
const struct V_118 * V_119 ,
const void * V_68 , int V_116 ,
unsigned short V_111 )
{
struct V_55 * V_60 ;
int V_81 ;
V_60 = F_37 ( V_115 , V_26 ) ;
if ( ! V_60 )
return - V_117 ;
V_81 = F_40 ( V_115 , V_119 , V_68 , V_116 ,
V_111 ) ;
if ( V_81 )
return V_81 ;
F_39 ( V_115 , V_60 ) ;
return 0 ;
}
int F_49 ( struct V_114 * V_115 ,
struct V_121 * V_122 )
{
return F_40 ( V_115 , & V_122 -> V_29 ,
F_50 ( V_122 ) ,
V_122 -> V_123 ,
F_51 ( V_122 ) ) ;
}
static int F_52 ( struct V_1 * V_2 ,
const struct V_55 * V_57 [] ,
bool V_5 , bool V_124 )
{
T_5 V_125 = 0 ;
T_5 V_126 = 0 ;
if ( V_57 [ V_127 ] )
V_125 = F_33 ( V_57 [ V_127 ] ) ;
if ( V_57 [ V_28 ] )
V_126 = F_33 ( V_57 [ V_28 ] ) ;
if ( F_53 ( ! V_124 ) ) {
F_23 ( V_2 , V_30 . V_128 . V_126 , V_126 , V_5 ) ;
F_23 ( V_2 , V_30 . V_128 . V_125 , V_125 , V_5 ) ;
} else {
F_23 ( V_2 , V_30 . V_129 . V_126 , V_126 , V_5 ) ;
F_23 ( V_2 , V_30 . V_129 . V_125 , V_125 , V_5 ) ;
}
return 0 ;
}
static int F_54 ( const struct V_1 * V_2 ,
T_2 V_11 , bool V_124 ,
const struct V_55 * * V_57 , bool log )
{
T_5 V_125 = 0 ;
if ( ! ( ( V_11 & ( 1 << V_130 ) ) &&
( V_11 & ( 1 << V_28 ) ) &&
F_55 ( F_33 ( V_57 [ V_28 ] ) ) ) ) {
return 0 ;
}
if ( ! ( ( V_11 & ( 1 << V_127 ) ) &&
( V_11 & ( 1 << V_131 ) ) ) ) {
F_7 ( log , L_24 , ( V_124 ) ? L_25 : L_26 ) ;
return - V_64 ;
}
if ( V_57 [ V_127 ] )
V_125 = F_33 ( V_57 [ V_127 ] ) ;
if ( ! ( V_125 & F_5 ( V_132 ) ) ) {
if ( V_125 ) {
F_7 ( log , L_27 ,
( V_124 ) ? L_25 : L_26 ) ;
return - V_64 ;
} else if ( F_18 ( V_57 [ V_131 ] ) ) {
F_7 ( log , L_28 ,
( V_124 ) ? L_25 : L_26 ) ;
return - V_64 ;
}
}
return 1 ;
}
static int F_56 ( const struct V_1 * V_2 ,
T_2 V_11 , bool V_124 ,
const struct V_55 * * V_57 , bool log )
{
T_5 V_125 = 0 ;
T_5 V_126 = 0 ;
bool V_133 = ! ! ( V_2 -> V_29 -> V_30 . V_128 . V_125 &
F_5 ( V_132 ) ) ;
bool V_134 = ! ! ( V_2 -> V_29 -> V_30 . V_129 . V_125 &
F_5 ( V_132 ) ) ;
if ( ! ( V_11 & ( 1 << V_131 ) ) ) {
return 0 ;
}
if ( ( ! V_124 && ! V_133 ) || ( V_124 && ! V_134 ) ) {
F_7 ( log , L_29 ,
( V_124 ) ? L_25 : L_26 ) ;
return - V_64 ;
}
if ( V_57 [ V_127 ] )
V_125 = F_33 ( V_57 [ V_127 ] ) ;
if ( V_57 [ V_28 ] )
V_126 = F_33 ( V_57 [ V_28 ] ) ;
if ( V_126 != F_5 ( 0xffff ) ) {
F_7 ( log , L_30 ,
( V_124 ) ? L_25 : L_26 , F_57 ( V_126 ) ) ;
return - V_64 ;
}
if ( ! ( V_125 & F_5 ( V_132 ) ) ) {
F_7 ( log , L_31 ,
( V_124 ) ? L_25 : L_26 ) ;
return - V_64 ;
}
return 1 ;
}
static int F_58 ( struct V_1 * V_2 ,
T_2 * V_11 , bool V_124 ,
const struct V_55 * * V_57 , bool V_5 ,
bool log )
{
int V_81 ;
const struct V_55 * V_135 ;
if ( ! V_5 )
V_81 = F_54 ( V_2 , * V_11 , V_124 ,
V_57 , log ) ;
else
V_81 = F_56 ( V_2 , * V_11 , V_124 ,
V_57 , log ) ;
if ( V_81 <= 0 )
return V_81 ;
V_81 = F_52 ( V_2 , V_57 , V_5 , V_124 ) ;
if ( V_81 )
return V_81 ;
* V_11 &= ~ ( 1 << V_131 ) ;
* V_11 &= ~ ( 1 << V_127 ) ;
* V_11 &= ~ ( 1 << V_28 ) ;
V_135 = V_57 [ V_131 ] ;
if ( ! V_5 )
V_81 = F_21 ( V_135 , V_57 , V_11 , log ) ;
else
V_81 = F_20 ( V_135 , V_57 , V_11 , log ) ;
return V_81 ;
}
static int F_59 ( struct V_1 * V_2 ,
T_2 * V_11 , const struct V_55 * * V_57 ,
bool V_5 , bool log )
{
int V_81 ;
bool V_133 = false ;
V_81 = F_58 ( V_2 , V_11 , false , V_57 ,
V_5 , log ) ;
if ( V_81 )
return V_81 ;
V_133 = ! ! ( V_2 -> V_29 -> V_30 . V_128 . V_125 & F_5 ( V_132 ) ) ;
if ( V_133 ) {
V_81 = F_58 ( V_2 , V_11 , true , V_57 ,
V_5 , log ) ;
if ( V_81 )
return V_81 ;
}
return 0 ;
}
static int F_60 ( struct V_1 * V_2 ,
T_2 * V_61 , const struct V_55 * * V_57 ,
bool V_5 , bool log )
{
T_5 V_136 ;
V_136 = F_33 ( V_57 [ V_28 ] ) ;
if ( V_5 ) {
V_136 = F_5 ( 0xffff ) ;
} else if ( ! F_61 ( V_136 ) ) {
F_7 ( log , L_32 ,
F_57 ( V_136 ) , V_137 ) ;
return - V_64 ;
}
F_23 ( V_2 , V_30 . type , V_136 , V_5 ) ;
* V_61 &= ~ ( 1 << V_28 ) ;
return 0 ;
}
static int F_62 ( struct V_138 * V_138 , struct V_1 * V_2 ,
T_2 * V_61 , const struct V_55 * * V_57 ,
bool V_5 , bool log )
{
T_3 V_139 = V_140 ;
if ( * V_61 & ( 1 << V_141 ) ) {
T_6 V_142 = F_27 ( V_57 [ V_141 ] ) ;
F_23 ( V_2 , V_143 , V_142 , V_5 ) ;
* V_61 &= ~ ( 1 << V_141 ) ;
}
if ( * V_61 & ( 1 << V_144 ) ) {
T_6 V_145 = F_27 ( V_57 [ V_144 ] ) ;
F_23 ( V_2 , V_145 , V_145 , V_5 ) ;
* V_61 &= ~ ( 1 << V_144 ) ;
}
if ( * V_61 & ( 1 << V_146 ) ) {
F_23 ( V_2 , V_147 . V_148 ,
F_27 ( V_57 [ V_146 ] ) , V_5 ) ;
* V_61 &= ~ ( 1 << V_146 ) ;
}
if ( * V_61 & ( 1 << V_27 ) ) {
T_6 V_149 = F_27 ( V_57 [ V_27 ] ) ;
if ( V_5 ) {
V_149 = 0xffffffff ;
} else if ( V_149 >= V_150 ) {
F_7 ( log , L_33 ,
V_149 , V_150 ) ;
return - V_64 ;
}
F_23 ( V_2 , V_147 . V_149 , V_149 , V_5 ) ;
* V_61 &= ~ ( 1 << V_27 ) ;
} else if ( ! V_5 ) {
F_23 ( V_2 , V_147 . V_149 , V_150 , V_5 ) ;
}
if ( * V_61 & ( 1 << V_151 ) ) {
T_7 V_152 = F_27 ( V_57 [ V_151 ] ) ;
F_23 ( V_2 , V_147 . V_153 , V_152 , V_5 ) ;
* V_61 &= ~ ( 1 << V_151 ) ;
}
if ( * V_61 & ( 1 << V_26 ) ) {
if ( F_28 ( V_57 [ V_26 ] , V_2 ,
V_5 , log ) < 0 )
return - V_64 ;
* V_61 &= ~ ( 1 << V_26 ) ;
}
if ( * V_61 & ( 1 << V_154 ) &&
F_63 ( V_138 , V_154 ) ) {
T_6 V_155 = F_27 ( V_57 [ V_154 ] ) ;
if ( V_155 & ~ V_156 ) {
F_7 ( log , L_34 ,
V_155 ) ;
return - V_64 ;
}
F_23 ( V_2 , V_157 . V_158 , V_155 , V_5 ) ;
* V_61 &= ~ ( 1ULL << V_154 ) ;
}
if ( * V_61 & ( 1 << V_159 ) &&
F_63 ( V_138 , V_159 ) ) {
T_4 V_160 = F_64 ( V_57 [ V_159 ] ) ;
F_23 ( V_2 , V_157 . V_161 , V_160 , V_5 ) ;
* V_61 &= ~ ( 1ULL << V_159 ) ;
}
if ( * V_61 & ( 1 << V_162 ) &&
F_63 ( V_138 , V_162 ) ) {
T_6 V_152 = F_27 ( V_57 [ V_162 ] ) ;
F_23 ( V_2 , V_157 . V_152 , V_152 , V_5 ) ;
* V_61 &= ~ ( 1ULL << V_162 ) ;
}
if ( * V_61 & ( 1 << V_163 ) &&
F_63 ( V_138 , V_163 ) ) {
const struct V_164 * V_165 ;
V_165 = F_19 ( V_57 [ V_163 ] ) ;
F_65 ( V_2 , V_157 . V_166 , V_165 -> V_167 ,
sizeof( * V_165 ) , V_5 ) ;
* V_61 &= ~ ( 1ULL << V_163 ) ;
}
if ( ! ( * V_61 & ( 1ULL << V_130 ) ) &&
( * V_61 & ( 1ULL << V_28 ) ) )
V_139 = V_168 ;
F_23 ( V_2 , V_139 , V_5 ? 0xff : V_139 , V_5 ) ;
if ( V_139 == V_168 )
return F_60 ( V_2 , V_61 , V_57 , V_5 ,
log ) ;
return 0 ;
}
static int F_66 ( struct V_138 * V_138 , struct V_1 * V_2 ,
T_2 V_61 , const struct V_55 * * V_57 ,
bool V_5 , bool log )
{
int V_81 ;
V_81 = F_62 ( V_138 , V_2 , & V_61 , V_57 , V_5 , log ) ;
if ( V_81 )
return V_81 ;
if ( V_61 & ( 1 << V_130 ) ) {
const struct V_169 * V_170 ;
V_170 = F_19 ( V_57 [ V_130 ] ) ;
F_65 ( V_2 , V_30 . V_45 ,
V_170 -> V_171 , V_172 , V_5 ) ;
F_65 ( V_2 , V_30 . V_91 ,
V_170 -> V_173 , V_172 , V_5 ) ;
V_61 &= ~ ( 1 << V_130 ) ;
if ( V_61 & ( 1 << V_127 ) ) {
F_7 ( log , L_35 ) ;
return - V_64 ;
}
if ( V_61 & ( 1 << V_28 ) ) {
V_81 = F_60 ( V_2 , & V_61 , V_57 , V_5 ,
log ) ;
if ( V_81 )
return V_81 ;
} else if ( ! V_5 ) {
F_23 ( V_2 , V_30 . type , F_5 ( V_174 ) , V_5 ) ;
}
} else if ( ! V_2 -> V_29 -> V_30 . type ) {
F_7 ( log , L_36 ) ;
return - V_64 ;
}
if ( V_61 & ( 1 << V_15 ) ) {
const struct V_175 * V_176 ;
V_176 = F_19 ( V_57 [ V_15 ] ) ;
if ( ! V_5 && V_176 -> V_177 > V_178 ) {
F_7 ( log , L_37 ,
V_176 -> V_177 , V_178 ) ;
return - V_64 ;
}
F_23 ( V_2 , V_34 . V_37 ,
V_176 -> V_179 , V_5 ) ;
F_23 ( V_2 , V_34 . V_95 ,
V_176 -> V_180 , V_5 ) ;
F_23 ( V_2 , V_34 . V_76 ,
V_176 -> V_181 , V_5 ) ;
F_23 ( V_2 , V_34 . V_35 ,
V_176 -> V_177 , V_5 ) ;
F_23 ( V_2 , V_77 . V_182 . V_45 ,
V_176 -> V_183 , V_5 ) ;
F_23 ( V_2 , V_77 . V_182 . V_91 ,
V_176 -> V_184 , V_5 ) ;
V_61 &= ~ ( 1 << V_15 ) ;
}
if ( V_61 & ( 1 << V_16 ) ) {
const struct V_185 * V_186 ;
V_186 = F_19 ( V_57 [ V_16 ] ) ;
if ( ! V_5 && V_186 -> V_187 > V_178 ) {
F_7 ( log , L_38 ,
V_186 -> V_187 , V_178 ) ;
return - V_64 ;
}
if ( ! V_5 && V_186 -> V_188 & F_67 ( 0xFFF00000 ) ) {
F_7 ( log , L_39 ,
F_68 ( V_186 -> V_188 ) , ( 1 << 20 ) - 1 ) ;
return - V_64 ;
}
F_23 ( V_2 , V_78 . V_189 ,
V_186 -> V_188 , V_5 ) ;
F_23 ( V_2 , V_34 . V_37 ,
V_186 -> V_190 , V_5 ) ;
F_23 ( V_2 , V_34 . V_95 ,
V_186 -> V_191 , V_5 ) ;
F_23 ( V_2 , V_34 . V_76 ,
V_186 -> V_192 , V_5 ) ;
F_23 ( V_2 , V_34 . V_35 ,
V_186 -> V_187 , V_5 ) ;
F_65 ( V_2 , V_78 . V_182 . V_45 ,
V_186 -> V_193 ,
sizeof( V_2 -> V_29 -> V_78 . V_182 . V_45 ) ,
V_5 ) ;
F_65 ( V_2 , V_78 . V_182 . V_91 ,
V_186 -> V_194 ,
sizeof( V_2 -> V_29 -> V_78 . V_182 . V_91 ) ,
V_5 ) ;
V_61 &= ~ ( 1 << V_16 ) ;
}
if ( V_61 & ( 1 << V_23 ) ) {
const struct V_195 * V_196 ;
V_196 = F_19 ( V_57 [ V_23 ] ) ;
if ( ! V_5 && ( V_196 -> V_197 & F_5 ( 0xff00 ) ) ) {
F_7 ( log , L_40 ,
V_196 -> V_197 ) ;
return - V_64 ;
}
F_23 ( V_2 , V_77 . V_182 . V_45 ,
V_196 -> V_198 , V_5 ) ;
F_23 ( V_2 , V_77 . V_182 . V_91 ,
V_196 -> V_199 , V_5 ) ;
F_23 ( V_2 , V_34 . V_37 ,
F_57 ( V_196 -> V_197 ) , V_5 ) ;
F_65 ( V_2 , V_77 . V_200 . V_201 ,
V_196 -> V_202 , V_172 , V_5 ) ;
F_65 ( V_2 , V_77 . V_200 . V_203 ,
V_196 -> V_204 , V_172 , V_5 ) ;
V_61 &= ~ ( 1 << V_23 ) ;
}
if ( V_61 & ( 1 << V_25 ) ) {
const struct V_205 * V_206 ;
V_206 = F_19 ( V_57 [ V_25 ] ) ;
F_23 ( V_2 , V_207 . V_208 ,
V_206 -> V_209 , V_5 ) ;
V_61 &= ~ ( 1 << V_25 ) ;
}
if ( V_61 & ( 1 << V_17 ) ) {
const struct V_210 * V_211 ;
V_211 = F_19 ( V_57 [ V_17 ] ) ;
F_23 ( V_2 , V_44 . V_45 , V_211 -> V_212 , V_5 ) ;
F_23 ( V_2 , V_44 . V_91 , V_211 -> V_213 , V_5 ) ;
V_61 &= ~ ( 1 << V_17 ) ;
}
if ( V_61 & ( 1 << V_18 ) ) {
F_23 ( V_2 , V_44 . V_214 ,
F_33 ( V_57 [ V_18 ] ) ,
V_5 ) ;
V_61 &= ~ ( 1 << V_18 ) ;
}
if ( V_61 & ( 1 << V_19 ) ) {
const struct V_215 * V_216 ;
V_216 = F_19 ( V_57 [ V_19 ] ) ;
F_23 ( V_2 , V_44 . V_45 , V_216 -> V_217 , V_5 ) ;
F_23 ( V_2 , V_44 . V_91 , V_216 -> V_218 , V_5 ) ;
V_61 &= ~ ( 1 << V_19 ) ;
}
if ( V_61 & ( 1 << V_20 ) ) {
const struct V_219 * V_220 ;
V_220 = F_19 ( V_57 [ V_20 ] ) ;
F_23 ( V_2 , V_44 . V_45 , V_220 -> V_221 , V_5 ) ;
F_23 ( V_2 , V_44 . V_91 , V_220 -> V_222 , V_5 ) ;
V_61 &= ~ ( 1 << V_20 ) ;
}
if ( V_61 & ( 1 << V_21 ) ) {
const struct V_223 * V_224 ;
V_224 = F_19 ( V_57 [ V_21 ] ) ;
F_23 ( V_2 , V_44 . V_45 ,
F_5 ( V_224 -> V_225 ) , V_5 ) ;
F_23 ( V_2 , V_44 . V_91 ,
F_5 ( V_224 -> V_226 ) , V_5 ) ;
V_61 &= ~ ( 1 << V_21 ) ;
}
if ( V_61 & ( 1 << V_22 ) ) {
const struct V_227 * V_228 ;
V_228 = F_19 ( V_57 [ V_22 ] ) ;
F_23 ( V_2 , V_44 . V_45 ,
F_5 ( V_228 -> V_229 ) , V_5 ) ;
F_23 ( V_2 , V_44 . V_91 ,
F_5 ( V_228 -> V_230 ) , V_5 ) ;
V_61 &= ~ ( 1 << V_22 ) ;
}
if ( V_61 & ( 1 << V_24 ) ) {
const struct V_231 * V_232 ;
V_232 = F_19 ( V_57 [ V_24 ] ) ;
F_65 ( V_2 , V_78 . V_233 . V_234 ,
V_232 -> V_235 ,
sizeof( V_2 -> V_29 -> V_78 . V_233 . V_234 ) ,
V_5 ) ;
F_65 ( V_2 , V_78 . V_233 . V_236 ,
V_232 -> V_237 , V_172 , V_5 ) ;
F_65 ( V_2 , V_78 . V_233 . V_238 ,
V_232 -> V_239 , V_172 , V_5 ) ;
V_61 &= ~ ( 1 << V_24 ) ;
}
if ( V_61 != 0 ) {
F_7 ( log , L_41 ,
( unsigned long long ) V_61 ) ;
return - V_64 ;
}
return 0 ;
}
static void F_69 ( struct V_55 * V_56 , T_3 V_240 ,
const struct V_241 * V_242 )
{
struct V_55 * V_60 ;
int V_62 ;
F_16 (nla, attr, rem) {
if ( V_242 [ F_17 ( V_60 ) ] . V_66 == V_51 ) {
if ( V_242 [ F_17 ( V_60 ) ] . V_243 )
V_242 = V_242 [ F_17 ( V_60 ) ] . V_243 ;
F_69 ( V_60 , V_240 , V_242 ) ;
} else {
memset ( F_19 ( V_60 ) , V_240 , F_18 ( V_60 ) ) ;
}
if ( F_17 ( V_60 ) == V_154 )
* ( T_6 * ) F_19 ( V_60 ) &= V_156 ;
}
}
static void F_70 ( struct V_55 * V_56 , T_3 V_240 )
{
F_69 ( V_56 , V_240 , V_65 ) ;
}
int F_71 ( struct V_138 * V_138 , struct V_1 * V_2 ,
const struct V_55 * V_244 ,
const struct V_55 * V_245 ,
bool log )
{
const struct V_55 * V_57 [ V_63 + 1 ] ;
struct V_55 * V_246 = NULL ;
T_2 V_11 = 0 ;
T_2 V_12 = 0 ;
int V_81 ;
V_81 = F_21 ( V_244 , V_57 , & V_11 , log ) ;
if ( V_81 )
return V_81 ;
V_81 = F_59 ( V_2 , & V_11 , V_57 , false , log ) ;
if ( V_81 )
return V_81 ;
V_81 = F_66 ( V_138 , V_2 , V_11 , V_57 , false , log ) ;
if ( V_81 )
return V_81 ;
if ( V_2 -> V_10 ) {
if ( ! V_245 ) {
V_246 = F_72 ( V_244 ,
F_10 ( F_18 ( V_244 ) ) ,
V_247 ) ;
if ( ! V_246 )
return - V_248 ;
F_70 ( V_246 , 0xff ) ;
if ( V_2 -> V_29 -> V_111 )
F_34 ( V_2 , V_85 ,
0xff , true ) ;
V_245 = V_246 ;
}
V_81 = F_20 ( V_245 , V_57 , & V_12 , log ) ;
if ( V_81 )
goto V_249;
F_23 ( V_2 , V_30 . V_128 . V_125 , F_5 ( 0xffff ) , true ) ;
F_23 ( V_2 , V_30 . V_129 . V_125 , F_5 ( 0xffff ) , true ) ;
V_81 = F_59 ( V_2 , & V_12 , V_57 , true , log ) ;
if ( V_81 )
goto V_249;
V_81 = F_66 ( V_138 , V_2 , V_12 , V_57 , true ,
log ) ;
if ( V_81 )
goto V_249;
}
if ( ! F_4 ( V_2 , V_11 , V_12 , log ) )
V_81 = - V_64 ;
V_249:
F_73 ( V_246 ) ;
return V_81 ;
}
static T_1 F_74 ( const struct V_55 * V_56 , bool log )
{
T_1 V_66 ;
if ( ! V_56 )
return 0 ;
V_66 = F_18 ( V_56 ) ;
if ( V_66 < 1 || V_66 > V_250 ) {
F_7 ( log , L_42 ,
F_18 ( V_56 ) , V_250 ) ;
return 0 ;
}
return V_66 ;
}
bool F_75 ( struct V_251 * V_252 , const struct V_55 * V_56 ,
bool log )
{
V_252 -> V_253 = F_74 ( V_56 , log ) ;
if ( V_252 -> V_253 )
memcpy ( V_252 -> V_254 , F_19 ( V_56 ) , V_252 -> V_253 ) ;
return V_252 -> V_253 ;
}
int F_76 ( struct V_251 * V_252 , const struct V_55 * V_254 ,
const struct V_255 * V_29 , bool log )
{
struct V_255 * V_256 ;
if ( F_75 ( V_252 , V_254 , log ) )
return 0 ;
V_256 = F_77 ( sizeof( * V_256 ) , V_247 ) ;
if ( ! V_256 )
return - V_248 ;
memcpy ( V_256 , V_29 , sizeof( * V_29 ) ) ;
V_252 -> V_257 = V_256 ;
return 0 ;
}
T_6 F_78 ( const struct V_55 * V_56 )
{
return V_56 ? F_27 ( V_56 ) : 0 ;
}
int F_79 ( struct V_138 * V_138 , const struct V_55 * V_56 ,
struct V_255 * V_29 ,
bool log )
{
const struct V_55 * V_57 [ V_63 + 1 ] ;
struct V_1 V_2 ;
T_2 V_61 = 0 ;
int V_81 ;
V_81 = F_21 ( V_56 , V_57 , & V_61 , log ) ;
if ( V_81 )
return - V_64 ;
memset ( & V_2 , 0 , sizeof( V_2 ) ) ;
V_2 . V_29 = V_29 ;
memset ( & V_29 -> V_157 , 0 , sizeof( V_29 -> V_157 ) ) ;
V_29 -> V_147 . V_149 = V_150 ;
return F_62 ( V_138 , & V_2 , & V_61 , V_57 , false , log ) ;
}
static int F_80 ( struct V_114 * V_115 , const struct V_258 * V_259 ,
bool V_5 )
{
T_5 V_136 = ! V_5 ? V_259 -> V_126 : F_5 ( 0xffff ) ;
if ( F_46 ( V_115 , V_28 , V_136 ) ||
F_46 ( V_115 , V_127 , V_259 -> V_125 ) )
return - V_117 ;
return 0 ;
}
static int F_81 ( const struct V_255 * V_260 ,
const struct V_255 * V_119 , bool V_5 ,
struct V_114 * V_115 )
{
struct V_169 * V_170 ;
struct V_55 * V_60 ;
struct V_55 * V_135 = NULL ;
struct V_55 * V_261 = NULL ;
if ( F_38 ( V_115 , V_144 , V_119 -> V_145 ) )
goto V_262;
if ( F_38 ( V_115 , V_141 , V_119 -> V_143 ) )
goto V_262;
if ( F_38 ( V_115 , V_146 , V_119 -> V_147 . V_148 ) )
goto V_262;
if ( ( V_260 -> V_111 || V_5 ) ) {
const void * V_71 = NULL ;
if ( V_119 -> V_85 . V_79 & V_263 )
V_71 = F_82 ( V_119 , V_260 -> V_69 ) ;
if ( F_48 ( V_115 , & V_119 -> V_85 , V_71 ,
V_260 -> V_69 , V_260 -> V_111 ) )
goto V_262;
}
if ( V_260 -> V_147 . V_149 == V_150 ) {
if ( V_5 && ( V_119 -> V_147 . V_149 == 0xffff ) )
if ( F_38 ( V_115 , V_27 , 0xffffffff ) )
goto V_262;
} else {
T_4 V_264 ;
V_264 = ! V_5 ? 0 : 0xffff ;
if ( F_38 ( V_115 , V_27 ,
( V_264 << 16 ) | V_119 -> V_147 . V_149 ) )
goto V_262;
}
if ( F_38 ( V_115 , V_151 , V_119 -> V_147 . V_153 ) )
goto V_262;
if ( F_83 ( V_119 , V_115 ) )
goto V_262;
if ( F_84 ( V_260 ) == V_140 ) {
V_60 = F_85 ( V_115 , V_130 , sizeof( * V_170 ) ) ;
if ( ! V_60 )
goto V_262;
V_170 = F_19 ( V_60 ) ;
F_86 ( V_170 -> V_171 , V_119 -> V_30 . V_45 ) ;
F_86 ( V_170 -> V_173 , V_119 -> V_30 . V_91 ) ;
if ( V_260 -> V_30 . V_128 . V_125 || F_55 ( V_260 -> V_30 . type ) ) {
if ( F_80 ( V_115 , & V_119 -> V_30 . V_128 , V_5 ) )
goto V_262;
V_135 = F_37 ( V_115 , V_131 ) ;
if ( ! V_260 -> V_30 . V_128 . V_125 )
goto V_265;
if ( V_260 -> V_30 . V_129 . V_125 || F_55 ( V_260 -> V_30 . type ) ) {
if ( F_80 ( V_115 , & V_119 -> V_30 . V_129 , V_5 ) )
goto V_262;
V_261 = F_37 ( V_115 , V_131 ) ;
if ( ! V_260 -> V_30 . V_129 . V_125 )
goto V_265;
}
}
if ( V_260 -> V_30 . type == F_5 ( V_174 ) ) {
if ( V_5 && V_119 -> V_30 . type )
if ( F_46 ( V_115 , V_28 ,
V_119 -> V_30 . type ) )
goto V_262;
goto V_265;
}
}
if ( F_46 ( V_115 , V_28 , V_119 -> V_30 . type ) )
goto V_262;
if ( F_55 ( V_260 -> V_30 . type ) ) {
F_87 ( ! ( V_135 && V_261 ) ) ;
goto V_265;
}
if ( V_260 -> V_30 . type == F_5 ( V_33 ) ) {
struct V_175 * V_176 ;
V_60 = F_85 ( V_115 , V_15 , sizeof( * V_176 ) ) ;
if ( ! V_60 )
goto V_262;
V_176 = F_19 ( V_60 ) ;
V_176 -> V_183 = V_119 -> V_77 . V_182 . V_45 ;
V_176 -> V_184 = V_119 -> V_77 . V_182 . V_91 ;
V_176 -> V_179 = V_119 -> V_34 . V_37 ;
V_176 -> V_180 = V_119 -> V_34 . V_95 ;
V_176 -> V_181 = V_119 -> V_34 . V_76 ;
V_176 -> V_177 = V_119 -> V_34 . V_35 ;
} else if ( V_260 -> V_30 . type == F_5 ( V_42 ) ) {
struct V_185 * V_186 ;
V_60 = F_85 ( V_115 , V_16 , sizeof( * V_186 ) ) ;
if ( ! V_60 )
goto V_262;
V_186 = F_19 ( V_60 ) ;
memcpy ( V_186 -> V_193 , & V_119 -> V_78 . V_182 . V_45 ,
sizeof( V_186 -> V_193 ) ) ;
memcpy ( V_186 -> V_194 , & V_119 -> V_78 . V_182 . V_91 ,
sizeof( V_186 -> V_194 ) ) ;
V_186 -> V_188 = V_119 -> V_78 . V_189 ;
V_186 -> V_190 = V_119 -> V_34 . V_37 ;
V_186 -> V_191 = V_119 -> V_34 . V_95 ;
V_186 -> V_192 = V_119 -> V_34 . V_76 ;
V_186 -> V_187 = V_119 -> V_34 . V_35 ;
} else if ( V_260 -> V_30 . type == F_5 ( V_31 ) ||
V_260 -> V_30 . type == F_5 ( V_32 ) ) {
struct V_195 * V_196 ;
V_60 = F_85 ( V_115 , V_23 , sizeof( * V_196 ) ) ;
if ( ! V_60 )
goto V_262;
V_196 = F_19 ( V_60 ) ;
memset ( V_196 , 0 , sizeof( struct V_195 ) ) ;
V_196 -> V_198 = V_119 -> V_77 . V_182 . V_45 ;
V_196 -> V_199 = V_119 -> V_77 . V_182 . V_91 ;
V_196 -> V_197 = F_5 ( V_119 -> V_34 . V_37 ) ;
F_86 ( V_196 -> V_202 , V_119 -> V_77 . V_200 . V_201 ) ;
F_86 ( V_196 -> V_204 , V_119 -> V_77 . V_200 . V_203 ) ;
} else if ( F_6 ( V_260 -> V_30 . type ) ) {
struct V_205 * V_206 ;
V_60 = F_85 ( V_115 , V_25 , sizeof( * V_206 ) ) ;
if ( ! V_60 )
goto V_262;
V_206 = F_19 ( V_60 ) ;
V_206 -> V_209 = V_119 -> V_207 . V_208 ;
}
if ( ( V_260 -> V_30 . type == F_5 ( V_33 ) ||
V_260 -> V_30 . type == F_5 ( V_42 ) ) &&
V_260 -> V_34 . V_35 != V_36 ) {
if ( V_260 -> V_34 . V_37 == V_40 ) {
struct V_210 * V_211 ;
V_60 = F_85 ( V_115 , V_17 , sizeof( * V_211 ) ) ;
if ( ! V_60 )
goto V_262;
V_211 = F_19 ( V_60 ) ;
V_211 -> V_212 = V_119 -> V_44 . V_45 ;
V_211 -> V_213 = V_119 -> V_44 . V_91 ;
if ( F_46 ( V_115 , V_18 ,
V_119 -> V_44 . V_214 ) )
goto V_262;
} else if ( V_260 -> V_34 . V_37 == V_38 ) {
struct V_215 * V_216 ;
V_60 = F_85 ( V_115 , V_19 , sizeof( * V_216 ) ) ;
if ( ! V_60 )
goto V_262;
V_216 = F_19 ( V_60 ) ;
V_216 -> V_217 = V_119 -> V_44 . V_45 ;
V_216 -> V_218 = V_119 -> V_44 . V_91 ;
} else if ( V_260 -> V_34 . V_37 == V_39 ) {
struct V_219 * V_220 ;
V_60 = F_85 ( V_115 , V_20 , sizeof( * V_220 ) ) ;
if ( ! V_60 )
goto V_262;
V_220 = F_19 ( V_60 ) ;
V_220 -> V_221 = V_119 -> V_44 . V_45 ;
V_220 -> V_222 = V_119 -> V_44 . V_91 ;
} else if ( V_260 -> V_30 . type == F_5 ( V_33 ) &&
V_260 -> V_34 . V_37 == V_41 ) {
struct V_223 * V_224 ;
V_60 = F_85 ( V_115 , V_21 , sizeof( * V_224 ) ) ;
if ( ! V_60 )
goto V_262;
V_224 = F_19 ( V_60 ) ;
V_224 -> V_225 = F_57 ( V_119 -> V_44 . V_45 ) ;
V_224 -> V_226 = F_57 ( V_119 -> V_44 . V_91 ) ;
} else if ( V_260 -> V_30 . type == F_5 ( V_42 ) &&
V_260 -> V_34 . V_37 == V_43 ) {
struct V_227 * V_228 ;
V_60 = F_85 ( V_115 , V_22 ,
sizeof( * V_228 ) ) ;
if ( ! V_60 )
goto V_262;
V_228 = F_19 ( V_60 ) ;
V_228 -> V_229 = F_57 ( V_119 -> V_44 . V_45 ) ;
V_228 -> V_230 = F_57 ( V_119 -> V_44 . V_91 ) ;
if ( V_228 -> V_229 == V_46 ||
V_228 -> V_229 == V_47 ) {
struct V_231 * V_232 ;
V_60 = F_85 ( V_115 , V_24 , sizeof( * V_232 ) ) ;
if ( ! V_60 )
goto V_262;
V_232 = F_19 ( V_60 ) ;
memcpy ( V_232 -> V_235 , & V_119 -> V_78 . V_233 . V_234 ,
sizeof( V_232 -> V_235 ) ) ;
F_86 ( V_232 -> V_237 , V_119 -> V_78 . V_233 . V_236 ) ;
F_86 ( V_232 -> V_239 , V_119 -> V_78 . V_233 . V_238 ) ;
}
}
}
V_265:
if ( V_261 )
F_39 ( V_115 , V_261 ) ;
if ( V_135 )
F_39 ( V_115 , V_135 ) ;
return 0 ;
V_262:
return - V_117 ;
}
int F_88 ( const struct V_255 * V_260 ,
const struct V_255 * V_119 , int V_56 , bool V_5 ,
struct V_114 * V_115 )
{
int V_81 ;
struct V_55 * V_60 ;
V_60 = F_37 ( V_115 , V_56 ) ;
if ( ! V_60 )
return - V_117 ;
V_81 = F_81 ( V_260 , V_119 , V_5 , V_115 ) ;
if ( V_81 )
return V_81 ;
F_39 ( V_115 , V_60 ) ;
return 0 ;
}
int F_89 ( const struct V_266 * V_267 , struct V_114 * V_115 )
{
if ( F_90 ( & V_267 -> V_268 ) )
return F_47 ( V_115 , V_269 , V_267 -> V_268 . V_253 ,
V_267 -> V_268 . V_254 ) ;
return F_88 ( V_267 -> V_268 . V_257 , V_267 -> V_268 . V_257 ,
V_270 , false , V_115 ) ;
}
int F_91 ( const struct V_266 * V_267 , struct V_114 * V_115 )
{
return F_88 ( & V_267 -> V_29 , & V_267 -> V_29 ,
V_270 , false , V_115 ) ;
}
int F_92 ( const struct V_266 * V_267 , struct V_114 * V_115 )
{
return F_88 ( & V_267 -> V_29 , & V_267 -> V_10 -> V_29 ,
V_271 , true , V_115 ) ;
}
static struct V_272 * F_93 ( int V_4 , bool log )
{
struct V_272 * V_273 ;
if ( V_4 > V_274 ) {
F_7 ( log , L_43 , V_4 ) ;
return F_94 ( - V_64 ) ;
}
V_273 = F_77 ( sizeof( * V_273 ) + V_4 , V_247 ) ;
if ( ! V_273 )
return F_94 ( - V_248 ) ;
V_273 -> V_275 = 0 ;
return V_273 ;
}
static void F_95 ( const struct V_55 * V_57 )
{
const struct V_55 * V_276 = F_19 ( V_57 ) ;
struct V_277 * V_278 ;
switch ( F_17 ( V_276 ) ) {
case V_48 :
V_278 = F_19 ( V_276 ) ;
F_96 ( (struct V_279 * ) V_278 -> V_280 ) ;
break;
}
}
void F_97 ( struct V_272 * V_281 )
{
const struct V_55 * V_57 ;
int V_62 ;
if ( ! V_281 )
return;
F_98 (a, sf_acts->actions, sf_acts->actions_len, rem) {
switch ( F_17 ( V_57 ) ) {
case V_282 :
F_95 ( V_57 ) ;
break;
case V_283 :
F_99 ( V_57 ) ;
break;
}
}
F_73 ( V_281 ) ;
}
static void F_100 ( struct V_284 * V_285 )
{
F_97 ( F_101 ( V_285 , struct V_272 , V_286 ) ) ;
}
void F_102 ( struct V_272 * V_281 )
{
F_103 ( & V_281 -> V_286 , F_100 ) ;
}
static struct V_55 * F_104 ( struct V_272 * * V_273 ,
int V_49 , bool log )
{
struct V_272 * V_287 ;
int V_288 ;
int V_289 = F_105 ( V_49 ) ;
int V_290 = F_106 ( struct V_272 , V_291 ) +
( * V_273 ) -> V_275 ;
if ( V_289 <= ( F_107 ( * V_273 ) - V_290 ) )
goto V_292;
V_288 = F_107 ( * V_273 ) * 2 ;
if ( V_288 > V_274 ) {
if ( ( V_274 - V_290 ) < V_289 )
return F_94 ( - V_117 ) ;
V_288 = V_274 ;
}
V_287 = F_93 ( V_288 , log ) ;
if ( F_108 ( V_287 ) )
return ( void * ) V_287 ;
memcpy ( V_287 -> V_291 , ( * V_273 ) -> V_291 , ( * V_273 ) -> V_275 ) ;
V_287 -> V_275 = ( * V_273 ) -> V_275 ;
V_287 -> V_293 = ( * V_273 ) -> V_293 ;
F_73 ( * V_273 ) ;
* V_273 = V_287 ;
V_292:
( * V_273 ) -> V_275 += V_289 ;
return (struct V_55 * ) ( ( unsigned char * ) ( * V_273 ) + V_290 ) ;
}
static struct V_55 * F_109 ( struct V_272 * * V_273 ,
int V_294 , void * V_295 , int V_66 , bool log )
{
struct V_55 * V_57 ;
V_57 = F_104 ( V_273 , F_110 ( V_66 ) , log ) ;
if ( F_108 ( V_57 ) )
return V_57 ;
V_57 -> F_17 = V_294 ;
V_57 -> F_18 = F_110 ( V_66 ) ;
if ( V_295 )
memcpy ( F_19 ( V_57 ) , V_295 , V_66 ) ;
memset ( ( unsigned char * ) V_57 + V_57 -> F_18 , 0 , F_111 ( V_66 ) ) ;
return V_57 ;
}
int F_112 ( struct V_272 * * V_273 , int V_294 , void * V_295 ,
int V_66 , bool log )
{
struct V_55 * V_57 ;
V_57 = F_109 ( V_273 , V_294 , V_295 , V_66 , log ) ;
return F_113 ( V_57 ) ;
}
static inline int F_114 ( struct V_272 * * V_273 ,
int V_294 , bool log )
{
int V_296 = ( * V_273 ) -> V_275 ;
int V_81 ;
V_81 = F_112 ( V_273 , V_294 , NULL , 0 , log ) ;
if ( V_81 )
return V_81 ;
return V_296 ;
}
static inline void F_115 ( struct V_272 * V_273 ,
int V_297 )
{
struct V_55 * V_57 = (struct V_55 * ) ( ( unsigned char * ) V_273 -> V_291 +
V_297 ) ;
V_57 -> F_18 = V_273 -> V_275 - V_297 ;
}
static int F_116 ( struct V_138 * V_138 , const struct V_55 * V_56 ,
const struct V_255 * V_29 , int V_298 ,
struct V_272 * * V_273 ,
T_5 V_136 , T_5 V_299 , bool log )
{
const struct V_55 * V_61 [ V_300 + 1 ] ;
const struct V_55 * V_301 , * V_291 ;
const struct V_55 * V_57 ;
int V_62 , V_8 , V_81 , V_302 ;
memset ( V_61 , 0 , sizeof( V_61 ) ) ;
F_16 (a, attr, rem) {
int type = F_17 ( V_57 ) ;
if ( ! type || type > V_300 || V_61 [ type ] )
return - V_64 ;
V_61 [ type ] = V_57 ;
}
if ( V_62 )
return - V_64 ;
V_301 = V_61 [ V_303 ] ;
if ( ! V_301 || F_18 ( V_301 ) != sizeof( T_6 ) )
return - V_64 ;
V_291 = V_61 [ V_304 ] ;
if ( ! V_291 || ( F_18 ( V_291 ) && F_18 ( V_291 ) < V_305 ) )
return - V_64 ;
V_8 = F_114 ( V_273 , V_306 , log ) ;
if ( V_8 < 0 )
return V_8 ;
V_81 = F_112 ( V_273 , V_303 ,
F_19 ( V_301 ) , sizeof( T_6 ) , log ) ;
if ( V_81 )
return V_81 ;
V_302 = F_114 ( V_273 , V_304 , log ) ;
if ( V_302 < 0 )
return V_302 ;
V_81 = F_117 ( V_138 , V_291 , V_29 , V_298 + 1 , V_273 ,
V_136 , V_299 , log ) ;
if ( V_81 )
return V_81 ;
F_115 ( * V_273 , V_302 ) ;
F_115 ( * V_273 , V_8 ) ;
return 0 ;
}
void F_118 ( struct V_1 * V_2 ,
struct V_255 * V_29 ,
bool V_307 ,
struct V_308 * V_10 )
{
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_29 = V_29 ;
V_2 -> V_10 = V_10 ;
if ( V_307 )
memset ( V_29 , 0 , sizeof( * V_29 ) ) ;
if ( V_10 ) {
memset ( & V_10 -> V_29 , 0 , sizeof( V_10 -> V_29 ) ) ;
V_10 -> V_7 . V_8 = V_10 -> V_7 . V_9 = 0 ;
}
}
static int F_119 ( struct V_255 * V_29 )
{
struct V_309 * V_310 ;
int V_311 = V_29 -> V_69 ;
bool V_312 = false ;
V_310 = (struct V_309 * ) F_82 ( V_29 , V_29 -> V_69 ) ;
while ( V_311 > 0 ) {
int V_66 ;
if ( V_311 < sizeof( * V_310 ) )
return - V_64 ;
V_66 = sizeof( * V_310 ) + V_310 -> V_313 * 4 ;
if ( V_66 > V_311 )
return - V_64 ;
V_312 |= ! ! ( V_310 -> type & V_314 ) ;
V_310 = (struct V_309 * ) ( ( T_3 * ) V_310 + V_66 ) ;
V_311 -= V_66 ;
} ;
V_29 -> V_85 . V_79 |= V_312 ? V_315 : 0 ;
return 0 ;
}
static int F_120 ( const struct V_55 * V_56 ,
struct V_272 * * V_273 , bool log )
{
struct V_1 V_2 ;
struct V_255 V_29 ;
struct V_316 * V_280 ;
struct V_121 * V_122 ;
struct V_277 * V_278 ;
struct V_55 * V_57 ;
int V_81 = 0 , V_8 , V_80 ;
F_118 ( & V_2 , & V_29 , true , NULL ) ;
V_80 = F_28 ( F_19 ( V_56 ) , & V_2 , false , log ) ;
if ( V_80 < 0 )
return V_80 ;
if ( V_29 . V_69 ) {
switch ( V_80 ) {
case V_107 :
V_81 = F_119 ( & V_29 ) ;
if ( V_81 < 0 )
return V_81 ;
break;
case V_109 :
break;
}
} ;
V_8 = F_114 ( V_273 , V_282 , log ) ;
if ( V_8 < 0 )
return V_8 ;
V_280 = F_121 ( V_29 . V_69 , V_247 ) ;
if ( ! V_280 )
return - V_248 ;
V_81 = F_122 ( & V_280 -> V_89 . V_122 . V_317 , V_247 ) ;
if ( V_81 ) {
F_96 ( (struct V_279 * ) V_280 ) ;
return V_81 ;
}
V_57 = F_109 ( V_273 , V_48 , NULL ,
sizeof( * V_278 ) , log ) ;
if ( F_108 ( V_57 ) ) {
F_96 ( (struct V_279 * ) V_280 ) ;
return F_123 ( V_57 ) ;
}
V_278 = F_19 ( V_57 ) ;
V_278 -> V_280 = V_280 ;
V_122 = & V_280 -> V_89 . V_122 ;
V_122 -> V_318 = V_319 ;
if ( V_29 . V_111 == V_112 )
V_122 -> V_318 |= V_320 ;
V_122 -> V_29 = V_29 . V_85 ;
F_124 ( V_122 ,
F_82 ( & V_29 , V_29 . V_69 ) ,
V_29 . V_69 ) ;
F_115 ( * V_273 , V_8 ) ;
return V_81 ;
}
static bool F_125 ( T_3 * V_295 , int V_66 )
{
T_3 * V_10 = V_295 + V_66 ;
while ( V_66 -- )
if ( * V_295 ++ & ~ * V_10 ++ )
return false ;
return true ;
}
static int F_126 ( const struct V_55 * V_57 ,
const struct V_255 * V_321 ,
struct V_272 * * V_273 , bool * V_322 ,
T_3 V_139 , T_5 V_136 , bool V_323 , bool log )
{
const struct V_55 * V_276 = F_19 ( V_57 ) ;
int V_324 = F_17 ( V_276 ) ;
T_1 V_325 ;
if ( F_10 ( F_18 ( V_276 ) ) != F_18 ( V_57 ) )
return - V_64 ;
V_325 = F_18 ( V_276 ) ;
if ( V_323 )
V_325 /= 2 ;
if ( V_324 > V_63 ||
! F_13 ( V_325 , V_65 [ V_324 ] . V_66 ) )
return - V_64 ;
if ( V_323 && ! F_125 ( F_19 ( V_276 ) , V_325 ) )
return - V_64 ;
switch ( V_324 ) {
const struct V_175 * V_176 ;
const struct V_185 * V_186 ;
int V_81 ;
case V_146 :
case V_151 :
case V_162 :
case V_163 :
break;
case V_130 :
if ( V_139 != V_140 )
return - V_64 ;
break;
case V_26 :
if ( V_323 )
return - V_64 ;
* V_322 = true ;
V_81 = F_120 ( V_57 , V_273 , log ) ;
if ( V_81 )
return V_81 ;
break;
case V_15 :
if ( V_136 != F_5 ( V_33 ) )
return - V_64 ;
V_176 = F_19 ( V_276 ) ;
if ( V_323 ) {
const struct V_175 * V_10 = V_176 + 1 ;
if ( V_10 -> V_179 || V_10 -> V_177 )
return - V_64 ;
} else {
if ( V_176 -> V_179 != V_321 -> V_34 . V_37 )
return - V_64 ;
if ( V_176 -> V_177 != V_321 -> V_34 . V_35 )
return - V_64 ;
}
break;
case V_16 :
if ( V_136 != F_5 ( V_42 ) )
return - V_64 ;
V_186 = F_19 ( V_276 ) ;
if ( V_323 ) {
const struct V_185 * V_10 = V_186 + 1 ;
if ( V_10 -> V_190 || V_10 -> V_187 )
return - V_64 ;
if ( F_68 ( V_10 -> V_188 ) & 0xFFF00000 )
return - V_64 ;
} else {
if ( V_186 -> V_190 != V_321 -> V_34 . V_37 )
return - V_64 ;
if ( V_186 -> V_187 != V_321 -> V_34 . V_35 )
return - V_64 ;
}
if ( F_68 ( V_186 -> V_188 ) & 0xFFF00000 )
return - V_64 ;
break;
case V_17 :
if ( ( V_136 != F_5 ( V_33 ) &&
V_136 != F_5 ( V_42 ) ) ||
V_321 -> V_34 . V_37 != V_40 )
return - V_64 ;
break;
case V_19 :
if ( ( V_136 != F_5 ( V_33 ) &&
V_136 != F_5 ( V_42 ) ) ||
V_321 -> V_34 . V_37 != V_38 )
return - V_64 ;
break;
case V_25 :
if ( ! F_6 ( V_136 ) )
return - V_64 ;
break;
case V_20 :
if ( ( V_136 != F_5 ( V_33 ) &&
V_136 != F_5 ( V_42 ) ) ||
V_321 -> V_34 . V_37 != V_39 )
return - V_64 ;
break;
default:
return - V_64 ;
}
if ( ! V_323 && V_324 != V_26 ) {
int V_8 , V_66 = V_325 * 2 ;
struct V_55 * V_326 ;
* V_322 = true ;
V_8 = F_114 ( V_273 ,
V_327 ,
log ) ;
if ( V_8 < 0 )
return V_8 ;
V_326 = F_109 ( V_273 , V_324 , NULL , V_66 , log ) ;
if ( F_108 ( V_326 ) )
return F_123 ( V_326 ) ;
memcpy ( F_19 ( V_326 ) , F_19 ( V_276 ) , V_325 ) ;
memset ( F_19 ( V_326 ) + V_325 , 0xff , V_325 ) ;
if ( V_324 == V_16 ) {
struct V_185 * V_10 = F_19 ( V_326 ) + V_325 ;
V_10 -> V_188 &= F_67 ( 0x000FFFFF ) ;
}
F_115 ( * V_273 , V_8 ) ;
}
return 0 ;
}
static int F_127 ( const struct V_55 * V_56 )
{
static const struct V_328 V_329 [ V_330 + 1 ] = {
[ V_331 ] = { . type = V_332 } ,
[ V_333 ] = { . type = V_334 } ,
[ V_335 ] = { . type = V_332 } ,
} ;
struct V_55 * V_57 [ V_330 + 1 ] ;
int error ;
error = F_128 ( V_57 , V_330 ,
V_56 , V_329 ) ;
if ( error )
return error ;
if ( ! V_57 [ V_331 ] ||
! F_27 ( V_57 [ V_331 ] ) )
return - V_64 ;
return 0 ;
}
static int F_129 ( const struct V_55 * V_336 ,
struct V_272 * * V_273 , bool log )
{
int V_337 = F_105 ( V_336 -> F_18 ) ;
struct V_55 * V_338 ;
V_338 = F_104 ( V_273 , V_336 -> F_18 , log ) ;
if ( F_108 ( V_338 ) )
return F_123 ( V_338 ) ;
memcpy ( V_338 , V_336 , V_337 ) ;
return 0 ;
}
static int F_117 ( struct V_138 * V_138 , const struct V_55 * V_56 ,
const struct V_255 * V_29 ,
int V_298 , struct V_272 * * V_273 ,
T_5 V_136 , T_5 V_299 , bool log )
{
T_3 V_139 = F_84 ( V_29 ) ;
const struct V_55 * V_57 ;
int V_62 , V_81 ;
if ( V_298 >= V_339 )
return - V_340 ;
F_16 (a, attr, rem) {
static const T_6 V_341 [ V_342 + 1 ] = {
[ V_343 ] = sizeof( T_6 ) ,
[ V_344 ] = sizeof( T_6 ) ,
[ V_345 ] = ( T_6 ) - 1 ,
[ V_346 ] = sizeof( struct V_347 ) ,
[ V_348 ] = sizeof( T_5 ) ,
[ V_349 ] = sizeof( struct V_350 ) ,
[ V_351 ] = 0 ,
[ V_282 ] = ( T_6 ) - 1 ,
[ V_352 ] = ( T_6 ) - 1 ,
[ V_306 ] = ( T_6 ) - 1 ,
[ V_353 ] = sizeof( struct V_354 ) ,
[ V_283 ] = ( T_6 ) - 1 ,
[ V_355 ] = sizeof( struct V_356 ) ,
[ V_357 ] = sizeof( struct V_358 ) ,
[ V_359 ] = 0 ,
} ;
const struct V_350 * V_128 ;
int type = F_17 ( V_57 ) ;
bool V_322 ;
if ( type > V_342 ||
( V_341 [ type ] != F_18 ( V_57 ) &&
V_341 [ type ] != ( T_6 ) - 1 ) )
return - V_64 ;
V_322 = false ;
switch ( type ) {
case V_360 :
return - V_64 ;
case V_345 :
V_81 = F_127 ( V_57 ) ;
if ( V_81 )
return V_81 ;
break;
case V_343 :
if ( F_27 ( V_57 ) >= V_150 )
return - V_64 ;
break;
case V_355 : {
const struct V_356 * V_361 = F_19 ( V_57 ) ;
if ( V_361 -> V_362 < V_363 )
return - V_64 ;
break;
}
case V_353 : {
const struct V_354 * V_364 = F_19 ( V_57 ) ;
switch ( V_364 -> V_365 ) {
case V_366 :
break;
default:
return - V_64 ;
}
break;
}
case V_351 :
if ( V_139 != V_140 )
return - V_64 ;
V_299 = F_5 ( 0 ) ;
break;
case V_349 :
if ( V_139 != V_140 )
return - V_64 ;
V_128 = F_19 ( V_57 ) ;
if ( ! F_55 ( V_128 -> V_367 ) )
return - V_64 ;
if ( ! ( V_128 -> V_299 & F_5 ( V_132 ) ) )
return - V_64 ;
V_299 = V_128 -> V_299 ;
break;
case V_344 :
break;
case V_346 : {
const struct V_347 * V_207 = F_19 ( V_57 ) ;
if ( ! F_6 ( V_207 -> V_368 ) )
return - V_64 ;
if ( V_299 & F_5 ( V_132 ) ||
( V_136 != F_5 ( V_33 ) &&
V_136 != F_5 ( V_42 ) &&
V_136 != F_5 ( V_31 ) &&
V_136 != F_5 ( V_32 ) &&
! F_6 ( V_136 ) ) )
return - V_64 ;
V_136 = V_207 -> V_368 ;
break;
}
case V_348 :
if ( V_299 & F_5 ( V_132 ) ||
! F_6 ( V_136 ) )
return - V_64 ;
V_136 = F_5 ( 0 ) ;
break;
case V_282 :
V_81 = F_126 ( V_57 , V_29 , V_273 ,
& V_322 , V_139 , V_136 ,
false , log ) ;
if ( V_81 )
return V_81 ;
break;
case V_352 :
V_81 = F_126 ( V_57 , V_29 , V_273 ,
& V_322 , V_139 , V_136 ,
true , log ) ;
if ( V_81 )
return V_81 ;
break;
case V_306 :
V_81 = F_116 ( V_138 , V_57 , V_29 , V_298 , V_273 ,
V_136 , V_299 , log ) ;
if ( V_81 )
return V_81 ;
V_322 = true ;
break;
case V_283 :
V_81 = F_130 ( V_138 , V_57 , V_29 , V_273 , log ) ;
if ( V_81 )
return V_81 ;
V_322 = true ;
break;
case V_357 :
if ( V_139 != V_168 )
return - V_64 ;
V_139 = V_168 ;
break;
case V_359 :
if ( V_139 != V_140 )
return - V_64 ;
if ( V_299 & F_5 ( V_132 ) )
return - V_64 ;
V_139 = V_140 ;
break;
default:
F_7 ( log , L_44 , type ) ;
return - V_64 ;
}
if ( ! V_322 ) {
V_81 = F_129 ( V_57 , V_273 , log ) ;
if ( V_81 )
return V_81 ;
}
}
if ( V_62 > 0 )
return - V_64 ;
return 0 ;
}
int F_131 ( struct V_138 * V_138 , const struct V_55 * V_56 ,
const struct V_255 * V_29 ,
struct V_272 * * V_273 , bool log )
{
int V_81 ;
* V_273 = F_93 ( F_18 ( V_56 ) , log ) ;
if ( F_108 ( * V_273 ) )
return F_123 ( * V_273 ) ;
( * V_273 ) -> V_293 = F_18 ( V_56 ) ;
V_81 = F_117 ( V_138 , V_56 , V_29 , 0 , V_273 , V_29 -> V_30 . type ,
V_29 -> V_30 . V_128 . V_125 , log ) ;
if ( V_81 )
F_97 ( * V_273 ) ;
return V_81 ;
}
static int F_132 ( const struct V_55 * V_56 , struct V_114 * V_115 )
{
const struct V_55 * V_57 ;
struct V_55 * V_8 ;
int V_81 = 0 , V_62 ;
V_8 = F_37 ( V_115 , V_306 ) ;
if ( ! V_8 )
return - V_117 ;
F_16 (a, attr, rem) {
int type = F_17 ( V_57 ) ;
struct V_55 * V_369 ;
switch ( type ) {
case V_303 :
if ( F_47 ( V_115 , V_303 ,
sizeof( T_6 ) , F_19 ( V_57 ) ) )
return - V_117 ;
break;
case V_304 :
V_369 = F_37 ( V_115 , V_304 ) ;
if ( ! V_369 )
return - V_117 ;
V_81 = F_133 ( F_19 ( V_57 ) , F_18 ( V_57 ) , V_115 ) ;
if ( V_81 )
return V_81 ;
F_39 ( V_115 , V_369 ) ;
break;
}
}
F_39 ( V_115 , V_8 ) ;
return V_81 ;
}
static int F_134 ( const struct V_55 * V_57 , struct V_114 * V_115 )
{
const struct V_55 * V_276 = F_19 ( V_57 ) ;
int V_324 = F_17 ( V_276 ) ;
struct V_55 * V_8 ;
int V_81 ;
switch ( V_324 ) {
case V_48 : {
struct V_277 * V_278 = F_19 ( V_276 ) ;
struct V_121 * V_122 = & V_278 -> V_280 -> V_89 . V_122 ;
V_8 = F_37 ( V_115 , V_282 ) ;
if ( ! V_8 )
return - V_117 ;
V_81 = F_48 ( V_115 , & V_122 -> V_29 ,
F_50 ( V_122 ) ,
V_122 -> V_123 ,
F_51 ( V_122 ) ) ;
if ( V_81 )
return V_81 ;
F_39 ( V_115 , V_8 ) ;
break;
}
default:
if ( F_47 ( V_115 , V_282 , F_18 ( V_57 ) , V_276 ) )
return - V_117 ;
break;
}
return 0 ;
}
static int F_135 ( const struct V_55 * V_57 ,
struct V_114 * V_115 )
{
const struct V_55 * V_276 = F_19 ( V_57 ) ;
struct V_55 * V_60 ;
T_1 V_325 = F_18 ( V_276 ) / 2 ;
V_60 = F_37 ( V_115 , V_282 ) ;
if ( ! V_60 )
return - V_117 ;
if ( F_47 ( V_115 , F_17 ( V_276 ) , V_325 , F_19 ( V_276 ) ) )
return - V_117 ;
F_39 ( V_115 , V_60 ) ;
return 0 ;
}
int F_133 ( const struct V_55 * V_56 , int V_66 , struct V_114 * V_115 )
{
const struct V_55 * V_57 ;
int V_62 , V_81 ;
F_98 (a, attr, len, rem) {
int type = F_17 ( V_57 ) ;
switch ( type ) {
case V_282 :
V_81 = F_134 ( V_57 , V_115 ) ;
if ( V_81 )
return V_81 ;
break;
case V_327 :
V_81 = F_135 ( V_57 , V_115 ) ;
if ( V_81 )
return V_81 ;
break;
case V_306 :
V_81 = F_132 ( V_57 , V_115 ) ;
if ( V_81 )
return V_81 ;
break;
case V_283 :
V_81 = F_136 ( F_19 ( V_57 ) , V_115 ) ;
if ( V_81 )
return V_81 ;
break;
default:
if ( F_47 ( V_115 , type , F_18 ( V_57 ) , F_19 ( V_57 ) ) )
return - V_117 ;
break;
}
}
return 0 ;
}
