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
void * V_24 ;
int V_25 ;
F_10 ( & V_20 -> V_26 ) ;
if ( V_20 -> V_27 ) {
V_24 = V_20 -> V_9 + V_28 ;
F_5 ( 0 , V_24 ) ;
} else {
V_24 = V_20 -> V_9 + V_29 ;
}
for ( V_25 = 0 ; V_25 < V_19 ; V_25 ++ ) {
V_21 = F_4 ( V_24 ) ;
V_21 &= ~ ( 0xff << 8 ) ;
V_21 |= ( ( V_18 + V_25 ) << 8 ) ;
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
F_13 ( & V_20 -> V_26 ) ;
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
V_39 = F_16 ( V_1 -> V_40 ) ;
if ( V_39 )
return V_39 ;
V_39 = F_17 ( V_1 -> V_41 ) ;
if ( V_39 ) {
F_18 ( V_1 -> V_40 ) ;
return V_39 ;
}
if ( V_1 -> V_23 == 0 )
F_8 ( V_1 , V_42 , 0x01 , 1 ) ;
F_8 ( V_1 , V_43 , 0x14 , 5 ) ;
F_8 ( V_1 , V_44 , V_7 -> V_45 , 2 ) ;
F_14 ( V_1 , 1 ) ;
if ( V_1 -> V_23 == 0 ) {
V_7 -> V_46 = true ;
F_1 ( V_2 , 0 , V_47 ) ;
F_1 ( V_2 , 0 , V_48 ) ;
if ( V_7 -> V_49 ) {
V_7 -> V_50 = - 1 ;
V_7 -> V_51 = - 1 ;
F_19 ( V_52 , & V_7 -> V_53 , 0 ) ;
} else {
F_6 ( V_2 , 0 ) ;
F_7 ( V_2 , 1 ) ;
}
}
return 0 ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_5 * V_1 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_1 ) ;
if ( V_1 -> V_23 == 0 ) {
F_1 ( V_2 , V_47 , 0 ) ;
F_1 ( V_2 , V_48 , 0 ) ;
V_7 -> V_46 = false ;
}
F_14 ( V_1 , 0 ) ;
F_21 ( V_1 -> V_41 ) ;
F_18 ( V_1 -> V_40 ) ;
return 0 ;
}
static int F_22 ( struct V_6 * V_7 )
{
if ( V_7 -> V_54 )
return F_23 ( V_7 -> V_54 ) ;
if ( V_7 -> V_55 ) {
union V_56 V_11 ;
int V_57 ;
V_57 = F_24 ( V_7 -> V_55 ,
V_58 , & V_11 ) ;
if ( V_57 == 0 )
return V_11 . V_59 ;
}
return 1 ;
}
static bool F_25 ( struct V_6 * V_7 )
{
return V_7 -> V_54 || V_7 -> V_55 ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_5 * V_1 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_1 ) ;
int V_39 ;
if ( ! V_1 -> V_60 || V_1 -> V_61 )
return 0 ;
if ( V_1 -> V_23 == 0 && F_25 ( V_7 ) &&
V_7 -> V_51 )
return 0 ;
V_39 = F_27 ( V_1 -> V_60 ) ;
if ( V_39 )
return V_39 ;
V_1 -> V_61 = true ;
if ( V_1 -> V_23 == 0 && V_7 -> V_54 && V_7 -> V_62 )
F_28 ( V_52 , & V_7 -> V_53 , V_63 ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_5 * V_1 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_1 ) ;
if ( ! V_1 -> V_60 || ! V_1 -> V_61 )
return 0 ;
F_30 ( V_1 -> V_60 ) ;
V_1 -> V_61 = false ;
if ( V_1 -> V_23 == 0 && V_7 -> V_54 && ! V_7 -> V_62 )
F_28 ( V_52 , & V_7 -> V_53 , V_64 ) ;
return 0 ;
}
void F_31 ( struct V_1 * V_2 , bool V_65 )
{
struct V_5 * V_1 = F_2 ( V_2 ) ;
F_8 ( V_1 , V_66 , V_65 ? 0 : 2 , 2 ) ;
}
static void F_32 ( struct V_67 * V_68 )
{
struct V_6 * V_7 =
F_33 ( V_68 , struct V_6 , V_53 . V_68 ) ;
struct V_1 * V_69 = V_7 -> V_70 [ 0 ] . V_1 ;
int V_50 , V_51 , V_71 = 0 , V_72 = 0 ;
V_50 = F_23 ( V_7 -> V_49 ) ;
V_51 = F_22 ( V_7 ) ;
F_10 ( & V_69 -> V_26 ) ;
if ( ! V_7 -> V_46 ) {
F_13 ( & V_69 -> V_26 ) ;
return;
}
if ( V_50 != V_7 -> V_50 ) {
if ( ! F_25 ( V_7 ) && V_50 == 0 ) {
F_7 ( V_69 , 0 ) ;
F_34 ( 200 ) ;
F_7 ( V_69 , 1 ) ;
}
F_6 ( V_69 , V_50 ) ;
V_7 -> V_50 = V_50 ;
V_71 = 1 ;
}
if ( V_51 != V_7 -> V_51 ) {
F_7 ( V_69 , V_51 ) ;
V_7 -> V_51 = V_51 ;
V_72 = 1 ;
}
F_13 ( & V_69 -> V_26 ) ;
if ( V_71 ) {
F_35 ( V_7 -> V_73 , V_74 ,
! V_50 ) ;
if ( ! F_25 ( V_7 ) && V_50 == 1 ) {
F_10 ( & V_69 -> V_26 ) ;
F_7 ( V_69 , 0 ) ;
F_34 ( 1000 ) ;
F_7 ( V_69 , 1 ) ;
F_13 ( & V_69 -> V_26 ) ;
}
}
if ( V_72 )
F_35 ( V_7 -> V_73 , V_75 , V_51 ) ;
if ( V_7 -> V_62 )
F_19 ( V_52 , & V_7 -> V_53 , V_64 ) ;
}
static T_2 F_36 ( int V_76 , void * V_77 )
{
struct V_6 * V_7 = V_77 ;
F_28 ( V_52 , & V_7 -> V_53 , V_63 ) ;
return V_78 ;
}
static int F_37 ( struct V_79 * V_80 ,
unsigned long V_11 , void * V_81 )
{
struct V_6 * V_7 =
F_33 ( V_80 , struct V_6 , V_82 ) ;
struct V_83 * V_84 = V_81 ;
if ( V_11 == V_85 && V_84 == V_7 -> V_55 )
F_28 ( V_52 , & V_7 -> V_53 , V_63 ) ;
return V_86 ;
}
static struct V_1 * F_38 ( struct V_87 * V_88 ,
struct V_89 * args )
{
struct V_6 * V_7 = F_39 ( V_88 ) ;
if ( args -> args [ 0 ] >= V_7 -> V_90 )
return F_40 ( - V_91 ) ;
return V_7 -> V_70 [ args -> args [ 0 ] ] . V_1 ;
}
static int F_41 ( struct V_92 * V_93 )
{
struct V_87 * V_88 = & V_93 -> V_88 ;
struct V_6 * V_7 = F_39 ( V_88 ) ;
if ( V_7 -> V_94 )
F_42 ( & V_7 -> V_82 ) ;
if ( V_7 -> V_95 >= 0 )
F_43 ( V_88 , V_7 -> V_95 , V_7 ) ;
if ( V_7 -> V_96 >= 0 )
F_43 ( V_88 , V_7 -> V_96 , V_7 ) ;
F_44 ( & V_7 -> V_53 ) ;
return 0 ;
}
static int F_45 ( struct V_92 * V_93 )
{
struct V_6 * V_7 ;
struct V_87 * V_88 = & V_93 -> V_88 ;
struct V_97 * V_98 = V_88 -> V_99 ;
struct V_100 * V_100 ;
bool V_101 ;
struct V_102 * V_103 ;
int V_25 , V_39 ;
V_7 = F_46 ( V_88 , sizeof( * V_7 ) , V_104 ) ;
if ( ! V_7 )
return - V_105 ;
F_47 ( & V_7 -> V_26 ) ;
F_48 ( & V_7 -> V_53 , F_32 ) ;
F_49 ( V_88 , V_7 ) ;
if ( F_50 ( V_98 , L_1 ) ||
F_50 ( V_98 , L_2 ) ||
F_50 ( V_98 , L_3 ) )
V_7 -> V_90 = 2 ;
else
V_7 -> V_90 = 3 ;
if ( F_50 ( V_98 , L_1 ) ||
F_50 ( V_98 , L_4 ) )
V_7 -> V_45 = 2 ;
else
V_7 -> V_45 = 3 ;
if ( F_50 ( V_98 , L_5 ) ||
F_50 ( V_98 , L_2 ) ||
F_50 ( V_98 , L_3 ) )
V_101 = true ;
else
V_101 = false ;
if ( F_50 ( V_98 , L_3 ) )
V_7 -> V_27 = true ;
V_103 = F_51 ( V_93 , V_106 , L_6 ) ;
V_7 -> V_9 = F_52 ( V_88 , V_103 ) ;
if ( F_53 ( V_7 -> V_9 ) )
return F_54 ( V_7 -> V_9 ) ;
V_7 -> V_49 = F_55 ( V_88 , L_7 ,
V_107 ) ;
if ( F_53 ( V_7 -> V_49 ) )
return F_54 ( V_7 -> V_49 ) ;
V_7 -> V_54 = F_55 ( V_88 , L_8 ,
V_107 ) ;
if ( F_53 ( V_7 -> V_54 ) )
return F_54 ( V_7 -> V_54 ) ;
if ( F_56 ( V_98 , L_9 , NULL ) ) {
V_7 -> V_55 = F_57 ( V_88 ,
L_9 ) ;
if ( F_53 ( V_7 -> V_55 ) )
return F_54 ( V_7 -> V_55 ) ;
if ( ! V_7 -> V_55 )
return - V_108 ;
}
if ( F_25 ( V_7 ) && ! V_7 -> V_49 ) {
F_58 ( V_88 , L_10 ) ;
return - V_91 ;
}
if ( V_7 -> V_49 ) {
V_7 -> V_73 = F_59 ( V_88 ,
V_109 ) ;
if ( F_53 ( V_7 -> V_73 ) )
return F_54 ( V_7 -> V_73 ) ;
V_39 = F_60 ( V_88 , V_7 -> V_73 ) ;
if ( V_39 ) {
F_58 ( V_88 , L_11 , V_39 ) ;
return V_39 ;
}
}
for ( V_25 = 0 ; V_25 < V_7 -> V_90 ; V_25 ++ ) {
struct V_5 * V_1 = V_7 -> V_70 + V_25 ;
char V_110 [ 16 ] ;
snprintf ( V_110 , sizeof( V_110 ) , L_12 , V_25 ) ;
V_1 -> V_60 = F_61 ( V_88 , V_110 ) ;
if ( F_53 ( V_1 -> V_60 ) ) {
if ( F_54 ( V_1 -> V_60 ) == - V_108 )
return - V_108 ;
V_1 -> V_60 = NULL ;
}
if ( V_101 )
snprintf ( V_110 , sizeof( V_110 ) , L_13 , V_25 ) ;
else
F_62 ( V_110 , L_14 , sizeof( V_110 ) ) ;
V_1 -> V_40 = F_63 ( V_88 , V_110 ) ;
if ( F_53 ( V_1 -> V_40 ) ) {
F_58 ( V_88 , L_15 , V_110 ) ;
return F_54 ( V_1 -> V_40 ) ;
}
snprintf ( V_110 , sizeof( V_110 ) , L_16 , V_25 ) ;
V_1 -> V_41 = F_64 ( V_88 , V_110 ) ;
if ( F_53 ( V_1 -> V_41 ) ) {
F_58 ( V_88 , L_17 , V_110 ) ;
return F_54 ( V_1 -> V_41 ) ;
}
if ( V_25 ) {
snprintf ( V_110 , sizeof( V_110 ) , L_18 , V_25 ) ;
V_103 = F_51 ( V_93 ,
V_106 , V_110 ) ;
V_1 -> V_34 = F_52 ( V_88 , V_103 ) ;
if ( F_53 ( V_1 -> V_34 ) )
return F_54 ( V_1 -> V_34 ) ;
}
V_1 -> V_1 = F_65 ( V_88 , NULL , & V_111 ) ;
if ( F_53 ( V_1 -> V_1 ) ) {
F_58 ( V_88 , L_19 , V_25 ) ;
return F_54 ( V_1 -> V_1 ) ;
}
V_1 -> V_23 = V_25 ;
F_66 ( V_1 -> V_1 , & V_7 -> V_70 [ V_25 ] ) ;
}
V_7 -> V_95 = F_67 ( V_7 -> V_49 ) ;
V_7 -> V_96 = F_67 ( V_7 -> V_54 ) ;
if ( ( V_7 -> V_49 && V_7 -> V_95 < 0 ) ||
( V_7 -> V_54 && V_7 -> V_96 < 0 ) )
V_7 -> V_62 = true ;
if ( V_7 -> V_95 >= 0 ) {
V_39 = F_68 ( V_88 , V_7 -> V_95 ,
F_36 ,
V_112 | V_113 ,
L_20 , V_7 ) ;
if ( V_39 ) {
F_58 ( V_88 , L_21 , V_39 ) ;
return V_39 ;
}
}
if ( V_7 -> V_96 >= 0 ) {
V_39 = F_68 ( V_88 , V_7 -> V_96 ,
F_36 ,
V_112 | V_113 ,
L_22 , V_7 ) ;
if ( V_39 ) {
F_58 ( V_88 , L_23 , V_39 ) ;
V_7 -> V_96 = - 1 ;
F_41 ( V_93 ) ;
return V_39 ;
}
}
if ( V_7 -> V_55 ) {
V_7 -> V_82 . V_114 = F_37 ;
V_7 -> V_82 . V_115 = 0 ;
V_39 = F_69 ( & V_7 -> V_82 ) ;
if ( V_39 ) {
F_41 ( V_93 ) ;
return V_39 ;
}
V_7 -> V_94 = true ;
}
V_100 = F_70 ( V_88 , F_38 ) ;
if ( F_53 ( V_100 ) ) {
F_41 ( V_93 ) ;
return F_54 ( V_100 ) ;
}
return 0 ;
}
