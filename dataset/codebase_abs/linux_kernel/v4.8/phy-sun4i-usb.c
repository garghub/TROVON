static void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
struct V_5 * V_1 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_1 ) ;
T_1 V_8 ;
V_8 = F_4 ( V_7 -> V_9 + V_10 ) ;
V_8 &= ~ V_3 ;
V_8 |= V_4 ;
F_5 ( V_8 , V_7 -> V_9 + V_10 ) ;
}
static void F_6 ( struct V_1 * V_1 , T_1 V_11 )
{
if ( V_11 )
V_11 = V_12 ;
else
V_11 = V_13 ;
F_1 ( V_1 , V_14 , V_11 ) ;
}
static void F_7 ( struct V_1 * V_1 , T_1 V_11 )
{
if ( V_11 )
V_11 = V_15 ;
else
V_11 = V_16 ;
F_1 ( V_1 , V_17 , V_11 ) ;
}
static void F_8 ( struct V_5 * V_1 , T_1 V_18 , T_1 V_7 ,
int V_19 )
{
struct V_6 * V_20 = F_3 ( V_1 ) ;
T_1 V_21 , V_22 = F_9 ( V_1 -> V_23 * 2 ) ;
void T_2 * V_24 = V_20 -> V_9 + V_20 -> V_25 -> V_26 ;
int V_27 ;
F_10 ( & V_20 -> V_28 ) ;
if ( V_20 -> V_25 -> type == V_29 ) {
F_5 ( 0 , V_24 ) ;
}
for ( V_27 = 0 ; V_27 < V_19 ; V_27 ++ ) {
V_21 = F_4 ( V_24 ) ;
V_21 &= ~ ( 0xff << 8 ) ;
V_21 |= ( ( V_18 + V_27 ) << 8 ) ;
F_5 ( V_21 , V_24 ) ;
V_21 = F_11 ( V_24 ) ;
if ( V_7 & 0x1 )
V_21 |= V_30 ;
else
V_21 &= ~ V_30 ;
V_21 &= ~ V_22 ;
F_12 ( V_21 , V_24 ) ;
V_21 = F_11 ( V_24 ) ;
V_21 |= V_22 ;
F_12 ( V_21 , V_24 ) ;
V_21 = F_11 ( V_24 ) ;
V_21 &= ~ V_22 ;
F_12 ( V_21 , V_24 ) ;
V_7 >>= 1 ;
}
F_13 ( & V_20 -> V_28 ) ;
}
static void F_14 ( struct V_5 * V_1 , int V_31 )
{
T_1 V_32 , V_33 ;
if ( ! V_1 -> V_34 )
return;
V_32 = V_35 | V_36 |
V_37 | V_38 ;
V_33 = F_4 ( V_1 -> V_34 ) ;
if ( V_31 )
V_33 |= V_32 ;
else
V_33 &= ~ V_32 ;
F_5 ( V_33 , V_1 -> V_34 ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_5 * V_1 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_1 ) ;
int V_39 ;
T_1 V_11 ;
V_39 = F_16 ( V_1 -> V_40 ) ;
if ( V_39 )
return V_39 ;
V_39 = F_17 ( V_1 -> V_41 ) ;
if ( V_39 ) {
F_18 ( V_1 -> V_40 ) ;
return V_39 ;
}
if ( V_7 -> V_25 -> type == V_42 ) {
if ( V_1 -> V_23 == 0 ) {
V_11 = F_4 ( V_7 -> V_9 + V_43 ) ;
F_5 ( V_11 & ~ 1 , V_7 -> V_9 + V_43 ) ;
}
V_11 = F_4 ( V_1 -> V_34 + V_44 ) ;
F_5 ( V_11 & ~ 2 , V_1 -> V_34 + V_44 ) ;
} else {
if ( V_1 -> V_23 == 0 )
F_8 ( V_1 , V_45 , 0x01 , 1 ) ;
F_8 ( V_1 , V_46 , 0x14 , 5 ) ;
F_8 ( V_1 , V_47 ,
V_7 -> V_25 -> V_48 , 2 ) ;
}
F_14 ( V_1 , 1 ) ;
if ( V_1 -> V_23 == 0 ) {
V_7 -> V_49 = true ;
F_1 ( V_2 , 0 , V_50 ) ;
F_1 ( V_2 , 0 , V_51 ) ;
V_7 -> V_52 = - 1 ;
V_7 -> V_53 = - 1 ;
F_19 ( V_54 , & V_7 -> V_55 , 0 ) ;
}
return 0 ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_5 * V_1 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_1 ) ;
if ( V_1 -> V_23 == 0 ) {
F_1 ( V_2 , V_50 , 0 ) ;
F_1 ( V_2 , V_51 , 0 ) ;
V_7 -> V_49 = false ;
}
F_14 ( V_1 , 0 ) ;
F_21 ( V_1 -> V_41 ) ;
F_18 ( V_1 -> V_40 ) ;
return 0 ;
}
static int F_22 ( struct V_6 * V_7 )
{
switch ( V_7 -> V_56 ) {
case V_57 :
return F_23 ( V_7 -> V_58 ) ;
case V_59 :
return 0 ;
case V_60 :
default:
return 1 ;
}
}
static int F_24 ( struct V_6 * V_7 )
{
if ( V_7 -> V_61 )
return F_23 ( V_7 -> V_61 ) ;
if ( V_7 -> V_62 ) {
union V_63 V_11 ;
int V_64 ;
V_64 = F_25 ( V_7 -> V_62 ,
V_65 , & V_11 ) ;
if ( V_64 == 0 )
return V_11 . V_66 ;
}
return 1 ;
}
static bool F_26 ( struct V_6 * V_7 )
{
return V_7 -> V_61 || V_7 -> V_62 ;
}
static bool F_27 ( struct V_6 * V_7 )
{
if ( ( V_7 -> V_58 && V_7 -> V_67 <= 0 ) ||
( V_7 -> V_61 && V_7 -> V_68 <= 0 ) )
return true ;
if ( V_7 -> V_25 -> type == V_69 &&
V_7 -> V_62 && V_7 -> V_70 [ 0 ] . V_71 )
return true ;
return false ;
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_5 * V_1 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_1 ) ;
int V_39 ;
if ( ! V_1 -> V_72 || V_1 -> V_71 )
return 0 ;
if ( V_1 -> V_23 == 0 && F_26 ( V_7 ) &&
V_7 -> V_53 )
return 0 ;
V_39 = F_29 ( V_1 -> V_72 ) ;
if ( V_39 )
return V_39 ;
V_1 -> V_71 = true ;
if ( V_1 -> V_23 == 0 && F_27 ( V_7 ) )
F_30 ( V_54 , & V_7 -> V_55 , V_73 ) ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_5 * V_1 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_1 ) ;
if ( ! V_1 -> V_72 || ! V_1 -> V_71 )
return 0 ;
F_32 ( V_1 -> V_72 ) ;
V_1 -> V_71 = false ;
if ( V_1 -> V_23 == 0 && ! F_27 ( V_7 ) )
F_30 ( V_54 , & V_7 -> V_55 , V_74 ) ;
return 0 ;
}
void F_33 ( struct V_1 * V_2 , bool V_75 )
{
struct V_5 * V_1 = F_2 ( V_2 ) ;
F_8 ( V_1 , V_76 , V_75 ? 0 : 2 , 2 ) ;
}
static void F_34 ( struct V_77 * V_78 )
{
struct V_6 * V_7 =
F_35 ( V_78 , struct V_6 , V_55 . V_78 ) ;
struct V_1 * V_79 = V_7 -> V_70 [ 0 ] . V_1 ;
int V_52 , V_53 , V_80 = 0 , V_81 = 0 ;
if ( V_79 == NULL )
return;
V_52 = F_22 ( V_7 ) ;
V_53 = F_24 ( V_7 ) ;
F_10 ( & V_79 -> V_28 ) ;
if ( ! V_7 -> V_49 ) {
F_13 ( & V_79 -> V_28 ) ;
return;
}
if ( V_52 != V_7 -> V_52 ) {
if ( V_7 -> V_56 == V_57 &&
! F_26 ( V_7 ) && V_52 == 0 ) {
F_7 ( V_79 , 0 ) ;
F_36 ( 200 ) ;
F_7 ( V_79 , 1 ) ;
}
F_6 ( V_79 , V_52 ) ;
V_7 -> V_52 = V_52 ;
V_80 = 1 ;
}
if ( V_53 != V_7 -> V_53 ) {
F_7 ( V_79 , V_53 ) ;
V_7 -> V_53 = V_53 ;
V_81 = 1 ;
}
F_13 ( & V_79 -> V_28 ) ;
if ( V_80 ) {
F_37 ( V_7 -> V_82 , V_83 ,
! V_52 ) ;
if ( V_7 -> V_56 == V_57 &&
! F_26 ( V_7 ) && V_52 == 1 ) {
F_10 ( & V_79 -> V_28 ) ;
F_7 ( V_79 , 0 ) ;
F_36 ( 1000 ) ;
F_7 ( V_79 , 1 ) ;
F_13 ( & V_79 -> V_28 ) ;
}
}
if ( V_81 )
F_37 ( V_7 -> V_82 , V_84 , V_53 ) ;
if ( F_27 ( V_7 ) )
F_19 ( V_54 , & V_7 -> V_55 , V_74 ) ;
}
static T_3 F_38 ( int V_85 , void * V_86 )
{
struct V_6 * V_7 = V_86 ;
F_30 ( V_54 , & V_7 -> V_55 , V_73 ) ;
return V_87 ;
}
static int F_39 ( struct V_88 * V_89 ,
unsigned long V_11 , void * V_90 )
{
struct V_6 * V_7 =
F_35 ( V_89 , struct V_6 , V_91 ) ;
struct V_92 * V_93 = V_90 ;
if ( V_11 == V_94 && V_93 == V_7 -> V_62 )
F_30 ( V_54 , & V_7 -> V_55 , V_73 ) ;
return V_95 ;
}
static struct V_1 * F_40 ( struct V_96 * V_97 ,
struct V_98 * args )
{
struct V_6 * V_7 = F_41 ( V_97 ) ;
if ( args -> args [ 0 ] < V_7 -> V_99 ||
args -> args [ 0 ] >= V_7 -> V_25 -> V_100 )
return F_42 ( - V_101 ) ;
return V_7 -> V_70 [ args -> args [ 0 ] ] . V_1 ;
}
static int F_43 ( struct V_102 * V_103 )
{
struct V_96 * V_97 = & V_103 -> V_97 ;
struct V_6 * V_7 = F_41 ( V_97 ) ;
if ( V_7 -> V_104 )
F_44 ( & V_7 -> V_91 ) ;
if ( V_7 -> V_67 > 0 )
F_45 ( V_97 , V_7 -> V_67 , V_7 ) ;
if ( V_7 -> V_68 > 0 )
F_45 ( V_97 , V_7 -> V_68 , V_7 ) ;
F_46 ( & V_7 -> V_55 ) ;
return 0 ;
}
static int F_47 ( struct V_102 * V_103 )
{
struct V_6 * V_7 ;
struct V_96 * V_97 = & V_103 -> V_97 ;
struct V_105 * V_106 = V_97 -> V_107 ;
struct V_108 * V_108 ;
struct V_109 * V_110 ;
int V_27 , V_39 ;
V_7 = F_48 ( V_97 , sizeof( * V_7 ) , V_111 ) ;
if ( ! V_7 )
return - V_112 ;
F_49 ( & V_7 -> V_28 ) ;
F_50 ( & V_7 -> V_55 , F_34 ) ;
F_51 ( V_97 , V_7 ) ;
V_7 -> V_25 = F_52 ( V_97 ) ;
if ( ! V_7 -> V_25 )
return - V_113 ;
V_110 = F_53 ( V_103 , V_114 , L_1 ) ;
V_7 -> V_9 = F_54 ( V_97 , V_110 ) ;
if ( F_55 ( V_7 -> V_9 ) )
return F_56 ( V_7 -> V_9 ) ;
V_7 -> V_58 = F_57 ( V_97 , L_2 ,
V_115 ) ;
if ( F_55 ( V_7 -> V_58 ) )
return F_56 ( V_7 -> V_58 ) ;
V_7 -> V_61 = F_57 ( V_97 , L_3 ,
V_115 ) ;
if ( F_55 ( V_7 -> V_61 ) )
return F_56 ( V_7 -> V_61 ) ;
if ( F_58 ( V_106 , L_4 , NULL ) ) {
V_7 -> V_62 = F_59 ( V_97 ,
L_4 ) ;
if ( F_55 ( V_7 -> V_62 ) )
return F_56 ( V_7 -> V_62 ) ;
if ( ! V_7 -> V_62 )
return - V_116 ;
}
V_7 -> V_56 = F_60 ( V_106 , 0 ) ;
switch ( V_7 -> V_56 ) {
case V_57 :
if ( ! V_7 -> V_58 ) {
F_61 ( V_97 , L_5 ) ;
return - V_101 ;
}
case V_59 :
case V_60 :
V_7 -> V_82 = F_62 ( V_97 ,
V_117 ) ;
if ( F_55 ( V_7 -> V_82 ) )
return F_56 ( V_7 -> V_82 ) ;
V_39 = F_63 ( V_97 , V_7 -> V_82 ) ;
if ( V_39 ) {
F_61 ( V_97 , L_6 , V_39 ) ;
return V_39 ;
}
break;
default:
F_64 ( V_97 , L_7 ) ;
V_7 -> V_99 = 1 ;
}
for ( V_27 = V_7 -> V_99 ; V_27 < V_7 -> V_25 -> V_100 ; V_27 ++ ) {
struct V_5 * V_1 = V_7 -> V_70 + V_27 ;
char V_118 [ 16 ] ;
snprintf ( V_118 , sizeof( V_118 ) , L_8 , V_27 ) ;
V_1 -> V_72 = F_65 ( V_97 , V_118 ) ;
if ( F_55 ( V_1 -> V_72 ) ) {
if ( F_56 ( V_1 -> V_72 ) == - V_116 )
return - V_116 ;
V_1 -> V_72 = NULL ;
}
if ( V_7 -> V_25 -> V_119 )
snprintf ( V_118 , sizeof( V_118 ) , L_9 , V_27 ) ;
else
F_66 ( V_118 , L_10 , sizeof( V_118 ) ) ;
V_1 -> V_40 = F_67 ( V_97 , V_118 ) ;
if ( F_55 ( V_1 -> V_40 ) ) {
F_61 ( V_97 , L_11 , V_118 ) ;
return F_56 ( V_1 -> V_40 ) ;
}
snprintf ( V_118 , sizeof( V_118 ) , L_12 , V_27 ) ;
V_1 -> V_41 = F_68 ( V_97 , V_118 ) ;
if ( F_55 ( V_1 -> V_41 ) ) {
F_61 ( V_97 , L_13 , V_118 ) ;
return F_56 ( V_1 -> V_41 ) ;
}
if ( V_27 ) {
snprintf ( V_118 , sizeof( V_118 ) , L_14 , V_27 ) ;
V_110 = F_53 ( V_103 ,
V_114 , V_118 ) ;
V_1 -> V_34 = F_54 ( V_97 , V_110 ) ;
if ( F_55 ( V_1 -> V_34 ) )
return F_56 ( V_1 -> V_34 ) ;
}
V_1 -> V_1 = F_69 ( V_97 , NULL , & V_120 ) ;
if ( F_55 ( V_1 -> V_1 ) ) {
F_61 ( V_97 , L_15 , V_27 ) ;
return F_56 ( V_1 -> V_1 ) ;
}
V_1 -> V_23 = V_27 ;
F_70 ( V_1 -> V_1 , & V_7 -> V_70 [ V_27 ] ) ;
}
V_7 -> V_67 = F_71 ( V_7 -> V_58 ) ;
if ( V_7 -> V_67 > 0 ) {
V_39 = F_72 ( V_97 , V_7 -> V_67 ,
F_38 ,
V_121 | V_122 ,
L_16 , V_7 ) ;
if ( V_39 ) {
F_61 ( V_97 , L_17 , V_39 ) ;
return V_39 ;
}
}
V_7 -> V_68 = F_71 ( V_7 -> V_61 ) ;
if ( V_7 -> V_68 > 0 ) {
V_39 = F_72 ( V_97 , V_7 -> V_68 ,
F_38 ,
V_121 | V_122 ,
L_18 , V_7 ) ;
if ( V_39 ) {
F_61 ( V_97 , L_19 , V_39 ) ;
V_7 -> V_68 = - 1 ;
F_43 ( V_103 ) ;
return V_39 ;
}
}
if ( V_7 -> V_62 ) {
V_7 -> V_91 . V_123 = F_39 ;
V_7 -> V_91 . V_124 = 0 ;
V_39 = F_73 ( & V_7 -> V_91 ) ;
if ( V_39 ) {
F_43 ( V_103 ) ;
return V_39 ;
}
V_7 -> V_104 = true ;
}
V_108 = F_74 ( V_97 , F_40 ) ;
if ( F_55 ( V_108 ) ) {
F_43 ( V_103 ) ;
return F_56 ( V_108 ) ;
}
return 0 ;
}
