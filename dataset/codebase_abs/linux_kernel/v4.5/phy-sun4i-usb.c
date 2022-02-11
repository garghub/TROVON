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
void * V_24 = V_20 -> V_9 + V_20 -> V_25 -> V_26 ;
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
if ( V_7 -> V_52 ) {
V_7 -> V_53 = - 1 ;
V_7 -> V_54 = - 1 ;
F_19 ( V_55 , & V_7 -> V_56 , 0 ) ;
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
if ( V_7 -> V_57 )
return F_23 ( V_7 -> V_57 ) ;
if ( V_7 -> V_58 ) {
union V_59 V_11 ;
int V_60 ;
V_60 = F_24 ( V_7 -> V_58 ,
V_61 , & V_11 ) ;
if ( V_60 == 0 )
return V_11 . V_62 ;
}
return 1 ;
}
static bool F_25 ( struct V_6 * V_7 )
{
return V_7 -> V_57 || V_7 -> V_58 ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_5 * V_1 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_1 ) ;
int V_39 ;
if ( ! V_1 -> V_63 || V_1 -> V_64 )
return 0 ;
if ( V_1 -> V_23 == 0 && F_25 ( V_7 ) &&
V_7 -> V_54 )
return 0 ;
V_39 = F_27 ( V_1 -> V_63 ) ;
if ( V_39 )
return V_39 ;
V_1 -> V_64 = true ;
if ( V_1 -> V_23 == 0 && V_7 -> V_57 && V_7 -> V_65 )
F_28 ( V_55 , & V_7 -> V_56 , V_66 ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_5 * V_1 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_1 ) ;
if ( ! V_1 -> V_63 || ! V_1 -> V_64 )
return 0 ;
F_30 ( V_1 -> V_63 ) ;
V_1 -> V_64 = false ;
if ( V_1 -> V_23 == 0 && V_7 -> V_57 && ! V_7 -> V_65 )
F_28 ( V_55 , & V_7 -> V_56 , V_67 ) ;
return 0 ;
}
void F_31 ( struct V_1 * V_2 , bool V_68 )
{
struct V_5 * V_1 = F_2 ( V_2 ) ;
F_8 ( V_1 , V_69 , V_68 ? 0 : 2 , 2 ) ;
}
static void F_32 ( struct V_70 * V_71 )
{
struct V_6 * V_7 =
F_33 ( V_71 , struct V_6 , V_56 . V_71 ) ;
struct V_1 * V_72 = V_7 -> V_73 [ 0 ] . V_1 ;
int V_53 , V_54 , V_74 = 0 , V_75 = 0 ;
V_53 = F_23 ( V_7 -> V_52 ) ;
V_54 = F_22 ( V_7 ) ;
F_10 ( & V_72 -> V_28 ) ;
if ( ! V_7 -> V_49 ) {
F_13 ( & V_72 -> V_28 ) ;
return;
}
if ( V_53 != V_7 -> V_53 ) {
if ( ! F_25 ( V_7 ) && V_53 == 0 ) {
F_7 ( V_72 , 0 ) ;
F_34 ( 200 ) ;
F_7 ( V_72 , 1 ) ;
}
F_6 ( V_72 , V_53 ) ;
V_7 -> V_53 = V_53 ;
V_74 = 1 ;
}
if ( V_54 != V_7 -> V_54 ) {
F_7 ( V_72 , V_54 ) ;
V_7 -> V_54 = V_54 ;
V_75 = 1 ;
}
F_13 ( & V_72 -> V_28 ) ;
if ( V_74 ) {
F_35 ( V_7 -> V_76 , V_77 ,
! V_53 ) ;
if ( ! F_25 ( V_7 ) && V_53 == 1 ) {
F_10 ( & V_72 -> V_28 ) ;
F_7 ( V_72 , 0 ) ;
F_34 ( 1000 ) ;
F_7 ( V_72 , 1 ) ;
F_13 ( & V_72 -> V_28 ) ;
}
}
if ( V_75 )
F_35 ( V_7 -> V_76 , V_78 , V_54 ) ;
if ( V_7 -> V_65 )
F_19 ( V_55 , & V_7 -> V_56 , V_67 ) ;
}
static T_2 F_36 ( int V_79 , void * V_80 )
{
struct V_6 * V_7 = V_80 ;
F_28 ( V_55 , & V_7 -> V_56 , V_66 ) ;
return V_81 ;
}
static int F_37 ( struct V_82 * V_83 ,
unsigned long V_11 , void * V_84 )
{
struct V_6 * V_7 =
F_33 ( V_83 , struct V_6 , V_85 ) ;
struct V_86 * V_87 = V_84 ;
if ( V_11 == V_88 && V_87 == V_7 -> V_58 )
F_28 ( V_55 , & V_7 -> V_56 , V_66 ) ;
return V_89 ;
}
static struct V_1 * F_38 ( struct V_90 * V_91 ,
struct V_92 * args )
{
struct V_6 * V_7 = F_39 ( V_91 ) ;
if ( args -> args [ 0 ] >= V_7 -> V_25 -> V_93 )
return F_40 ( - V_94 ) ;
return V_7 -> V_73 [ args -> args [ 0 ] ] . V_1 ;
}
static int F_41 ( struct V_95 * V_96 )
{
struct V_90 * V_91 = & V_96 -> V_91 ;
struct V_6 * V_7 = F_39 ( V_91 ) ;
if ( V_7 -> V_97 )
F_42 ( & V_7 -> V_85 ) ;
if ( V_7 -> V_98 >= 0 )
F_43 ( V_91 , V_7 -> V_98 , V_7 ) ;
if ( V_7 -> V_99 >= 0 )
F_43 ( V_91 , V_7 -> V_99 , V_7 ) ;
F_44 ( & V_7 -> V_56 ) ;
return 0 ;
}
static int F_45 ( struct V_95 * V_96 )
{
struct V_6 * V_7 ;
struct V_90 * V_91 = & V_96 -> V_91 ;
struct V_100 * V_101 = V_91 -> V_102 ;
struct V_103 * V_103 ;
struct V_104 * V_105 ;
int V_27 , V_39 ;
V_7 = F_46 ( V_91 , sizeof( * V_7 ) , V_106 ) ;
if ( ! V_7 )
return - V_107 ;
F_47 ( & V_7 -> V_28 ) ;
F_48 ( & V_7 -> V_56 , F_32 ) ;
F_49 ( V_91 , V_7 ) ;
V_7 -> V_25 = F_50 ( V_91 ) ;
if ( ! V_7 -> V_25 )
return - V_108 ;
V_105 = F_51 ( V_96 , V_109 , L_1 ) ;
V_7 -> V_9 = F_52 ( V_91 , V_105 ) ;
if ( F_53 ( V_7 -> V_9 ) )
return F_54 ( V_7 -> V_9 ) ;
V_7 -> V_52 = F_55 ( V_91 , L_2 ,
V_110 ) ;
if ( F_53 ( V_7 -> V_52 ) )
return F_54 ( V_7 -> V_52 ) ;
V_7 -> V_57 = F_55 ( V_91 , L_3 ,
V_110 ) ;
if ( F_53 ( V_7 -> V_57 ) )
return F_54 ( V_7 -> V_57 ) ;
if ( F_56 ( V_101 , L_4 , NULL ) ) {
V_7 -> V_58 = F_57 ( V_91 ,
L_4 ) ;
if ( F_53 ( V_7 -> V_58 ) )
return F_54 ( V_7 -> V_58 ) ;
if ( ! V_7 -> V_58 )
return - V_111 ;
}
if ( F_25 ( V_7 ) && ! V_7 -> V_52 ) {
F_58 ( V_91 , L_5 ) ;
return - V_94 ;
}
if ( V_7 -> V_52 ) {
V_7 -> V_76 = F_59 ( V_91 ,
V_112 ) ;
if ( F_53 ( V_7 -> V_76 ) )
return F_54 ( V_7 -> V_76 ) ;
V_39 = F_60 ( V_91 , V_7 -> V_76 ) ;
if ( V_39 ) {
F_58 ( V_91 , L_6 , V_39 ) ;
return V_39 ;
}
}
for ( V_27 = 0 ; V_27 < V_7 -> V_25 -> V_93 ; V_27 ++ ) {
struct V_5 * V_1 = V_7 -> V_73 + V_27 ;
char V_113 [ 16 ] ;
snprintf ( V_113 , sizeof( V_113 ) , L_7 , V_27 ) ;
V_1 -> V_63 = F_61 ( V_91 , V_113 ) ;
if ( F_53 ( V_1 -> V_63 ) ) {
if ( F_54 ( V_1 -> V_63 ) == - V_111 )
return - V_111 ;
V_1 -> V_63 = NULL ;
}
if ( V_7 -> V_25 -> V_114 )
snprintf ( V_113 , sizeof( V_113 ) , L_8 , V_27 ) ;
else
F_62 ( V_113 , L_9 , sizeof( V_113 ) ) ;
V_1 -> V_40 = F_63 ( V_91 , V_113 ) ;
if ( F_53 ( V_1 -> V_40 ) ) {
F_58 ( V_91 , L_10 , V_113 ) ;
return F_54 ( V_1 -> V_40 ) ;
}
snprintf ( V_113 , sizeof( V_113 ) , L_11 , V_27 ) ;
V_1 -> V_41 = F_64 ( V_91 , V_113 ) ;
if ( F_53 ( V_1 -> V_41 ) ) {
F_58 ( V_91 , L_12 , V_113 ) ;
return F_54 ( V_1 -> V_41 ) ;
}
if ( V_27 ) {
snprintf ( V_113 , sizeof( V_113 ) , L_13 , V_27 ) ;
V_105 = F_51 ( V_96 ,
V_109 , V_113 ) ;
V_1 -> V_34 = F_52 ( V_91 , V_105 ) ;
if ( F_53 ( V_1 -> V_34 ) )
return F_54 ( V_1 -> V_34 ) ;
}
V_1 -> V_1 = F_65 ( V_91 , NULL , & V_115 ) ;
if ( F_53 ( V_1 -> V_1 ) ) {
F_58 ( V_91 , L_14 , V_27 ) ;
return F_54 ( V_1 -> V_1 ) ;
}
V_1 -> V_23 = V_27 ;
F_66 ( V_1 -> V_1 , & V_7 -> V_73 [ V_27 ] ) ;
}
V_7 -> V_98 = F_67 ( V_7 -> V_52 ) ;
V_7 -> V_99 = F_67 ( V_7 -> V_57 ) ;
if ( ( V_7 -> V_52 && V_7 -> V_98 < 0 ) ||
( V_7 -> V_57 && V_7 -> V_99 < 0 ) )
V_7 -> V_65 = true ;
if ( V_7 -> V_98 >= 0 ) {
V_39 = F_68 ( V_91 , V_7 -> V_98 ,
F_36 ,
V_116 | V_117 ,
L_15 , V_7 ) ;
if ( V_39 ) {
F_58 ( V_91 , L_16 , V_39 ) ;
return V_39 ;
}
}
if ( V_7 -> V_99 >= 0 ) {
V_39 = F_68 ( V_91 , V_7 -> V_99 ,
F_36 ,
V_116 | V_117 ,
L_17 , V_7 ) ;
if ( V_39 ) {
F_58 ( V_91 , L_18 , V_39 ) ;
V_7 -> V_99 = - 1 ;
F_41 ( V_96 ) ;
return V_39 ;
}
}
if ( V_7 -> V_58 ) {
V_7 -> V_85 . V_118 = F_37 ;
V_7 -> V_85 . V_119 = 0 ;
V_39 = F_69 ( & V_7 -> V_85 ) ;
if ( V_39 ) {
F_41 ( V_96 ) ;
return V_39 ;
}
V_7 -> V_97 = true ;
}
V_103 = F_70 ( V_91 , F_38 ) ;
if ( F_53 ( V_103 ) ) {
F_41 ( V_96 ) ;
return F_54 ( V_103 ) ;
}
return 0 ;
}
