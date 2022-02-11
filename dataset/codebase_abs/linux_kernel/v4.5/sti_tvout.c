static T_1 F_1 ( struct V_1 * V_2 , int V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static void F_3 ( struct V_1 * V_2 , T_1 V_5 , int V_3 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 , int V_6 ,
T_1 V_7 , T_1 V_8 , T_1 V_9 )
{
T_1 V_5 = F_1 ( V_2 , V_6 ) ;
V_5 &= ~ ( V_10 << V_11 ) ;
V_5 &= ~ ( V_10 << V_12 ) ;
V_5 &= ~ ( V_10 << V_13 ) ;
V_5 |= V_7 << V_11 ;
V_5 |= V_8 << V_12 ;
V_5 |= V_9 << V_13 ;
F_3 ( V_2 , V_5 , V_6 ) ;
}
static void F_6 ( struct V_1 * V_2 , int V_6 , T_1 V_14 )
{
T_1 V_5 = F_1 ( V_2 , V_6 ) ;
V_5 &= ~ ( V_15 << V_16 ) ;
V_5 |= V_14 << V_16 ;
F_3 ( V_2 , V_5 , V_6 ) ;
}
static void F_7 ( struct V_1 * V_2 , int V_6 , T_1 V_17 )
{
T_1 V_5 = F_1 ( V_2 , V_6 ) ;
V_5 &= ~ ( V_18 << V_19 ) ;
V_5 |= V_17 << V_19 ;
F_3 ( V_2 , V_5 , V_6 ) ;
}
static void F_8 ( struct V_1 * V_2 ,
int V_6 ,
bool V_20 ,
bool V_21 ,
enum V_22 V_23 )
{
T_1 V_24 ;
T_1 V_5 = F_1 ( V_2 , V_6 ) ;
if ( V_20 )
V_24 = V_25 ;
else
V_24 = V_26 ;
switch ( V_23 ) {
case V_27 :
V_24 |= V_28 ;
break;
case V_29 :
V_24 &= ~ V_28 ;
break;
}
if ( V_21 )
V_24 = V_24 ^ V_30 ;
V_5 &= ~ V_31 ;
V_5 |= V_24 ;
F_3 ( V_2 , V_5 , V_6 ) ;
}
static void F_9 ( struct V_1 * V_2 ,
int V_6 , T_1 V_32 )
{
T_1 V_5 = F_1 ( V_2 , V_6 ) ;
V_5 &= ~ V_33 ;
V_5 |= V_32 ;
F_3 ( V_2 , V_5 , V_6 ) ;
}
static void F_10 ( struct V_1 * V_2 , bool V_20 )
{
struct V_34 * V_35 = V_2 -> V_36 -> V_37 ;
bool V_21 = false ;
T_1 V_38 ;
int V_5 ;
F_11 ( V_2 -> V_36 , L_1 , V_39 ) ;
if ( V_20 ) {
F_12 ( L_2 ) ;
V_5 = V_40 << V_41 ;
V_5 |= V_40 << V_42 ;
V_5 |= V_40 ;
F_3 ( V_2 , V_5 , V_43 ) ;
V_38 = V_44 ;
} else {
F_12 ( L_3 ) ;
V_5 = V_45 << V_41 ;
V_5 |= V_45 << V_42 ;
V_5 |= V_45 ;
F_3 ( V_2 , V_5 , V_43 ) ;
V_38 = V_46 ;
}
F_5 ( V_2 , V_47 ,
V_48 ,
V_49 ,
V_50 ) ;
F_6 ( V_2 , V_47 ,
V_51 ) ;
F_7 ( V_2 , V_47 , V_52 ) ;
if ( F_13 ( V_35 , L_4 ) ) {
F_9 ( V_2 , V_38 ,
V_33 ) ;
V_21 = true ;
}
F_8 ( V_2 , V_47 , V_20 ,
V_21 ,
V_27 ) ;
}
static void F_14 ( struct V_1 * V_2 , bool V_20 )
{
struct V_34 * V_35 = V_2 -> V_36 -> V_37 ;
bool V_21 = false ;
T_1 V_38 ;
F_11 ( V_2 -> V_36 , L_1 , V_39 ) ;
if ( V_20 ) {
F_12 ( L_5 ) ;
F_3 ( V_2 , V_53 , V_54 ) ;
V_38 = V_44 ;
} else {
F_12 ( L_6 ) ;
F_3 ( V_2 , V_55 , V_54 ) ;
V_38 = V_46 ;
}
F_5 ( V_2 , V_56 ,
V_48 ,
V_49 ,
V_50 ) ;
F_6 ( V_2 , V_56 ,
V_51 ) ;
F_7 ( V_2 , V_56 , V_52 ) ;
if ( F_13 ( V_35 , L_4 ) ) {
F_9 ( V_2 , V_38 ,
V_33 ) ;
V_21 = true ;
}
F_8 ( V_2 , V_56 , V_20 ,
V_21 , V_27 ) ;
}
static void F_15 ( struct V_1 * V_2 , bool V_20 )
{
struct V_34 * V_35 = V_2 -> V_36 -> V_37 ;
bool V_21 = false ;
T_1 V_38 ;
int V_5 ;
F_11 ( V_2 -> V_36 , L_1 , V_39 ) ;
if ( V_20 ) {
V_5 = V_57 << V_58 ;
V_5 |= V_59 ;
F_3 ( V_2 , V_5 , V_60 ) ;
V_38 = V_44 ;
} else {
V_5 = V_61 << V_58 ;
V_5 |= V_62 ;
F_3 ( V_2 , V_5 , V_60 ) ;
V_38 = V_46 ;
}
F_5 ( V_2 , V_63 ,
V_48 ,
V_49 ,
V_50 ) ;
F_6 ( V_2 , V_63 , V_64 ) ;
F_7 ( V_2 , V_63 , V_65 ) ;
if ( F_13 ( V_35 , L_4 ) ) {
F_9 ( V_2 ,
V_38 , V_33 ) ;
V_21 = true ;
}
F_8 ( V_2 , V_63 , V_20 ,
V_21 ,
V_29 ) ;
F_3 ( V_2 , 0 , V_66 ) ;
}
static void F_16 ( struct V_67 * V_68 , int V_69 )
{
}
static bool F_17 ( struct V_67 * V_68 ,
const struct V_70 * V_69 ,
struct V_70 * V_71 )
{
return true ;
}
static void F_18 ( struct V_67 * V_68 ,
struct V_70 * V_69 ,
struct V_70 * V_71 )
{
}
static void F_19 ( struct V_67 * V_68 )
{
}
static void F_20 ( struct V_67 * V_68 )
{
struct V_72 * V_73 = F_21 ( V_68 ) ;
F_22 ( V_68 ) ;
F_23 ( V_73 ) ;
}
static void F_24 ( struct V_67 * V_68 )
{
struct V_1 * V_2 = F_25 ( V_68 ) ;
F_10 ( V_2 , F_26 ( V_68 -> V_74 ) ) ;
}
static void F_27 ( struct V_67 * V_68 )
{
struct V_1 * V_2 = F_25 ( V_68 ) ;
F_3 ( V_2 , 0x0 , V_47 ) ;
}
static struct V_67 *
F_28 ( struct V_75 * V_36 ,
struct V_1 * V_2 )
{
struct V_72 * V_68 ;
struct V_67 * V_67 ;
V_68 = F_29 ( V_2 -> V_36 , sizeof( * V_68 ) , V_76 ) ;
if ( ! V_68 )
return NULL ;
V_68 -> V_2 = V_2 ;
V_67 = (struct V_67 * ) V_68 ;
V_67 -> V_77 = V_78 ;
V_67 -> V_79 = 1 << 0 ;
F_30 ( V_36 , V_67 ,
& V_80 , V_81 ,
NULL ) ;
F_31 ( V_67 , & V_82 ) ;
return V_67 ;
}
static void F_32 ( struct V_67 * V_68 )
{
struct V_1 * V_2 = F_25 ( V_68 ) ;
F_15 ( V_2 , F_26 ( V_68 -> V_74 ) ) ;
}
static void F_33 ( struct V_67 * V_68 )
{
struct V_1 * V_2 = F_25 ( V_68 ) ;
F_3 ( V_2 , 0x0 , V_63 ) ;
F_3 ( V_2 , 1 , V_66 ) ;
}
static struct V_67 * F_34 ( struct V_75 * V_36 ,
struct V_1 * V_2 )
{
struct V_72 * V_68 ;
struct V_67 * V_67 ;
V_68 = F_29 ( V_2 -> V_36 , sizeof( * V_68 ) , V_76 ) ;
if ( ! V_68 )
return NULL ;
V_68 -> V_2 = V_2 ;
V_67 = (struct V_67 * ) V_68 ;
V_67 -> V_77 = V_78 ;
V_67 -> V_79 = 1 << 0 ;
F_30 ( V_36 , V_67 ,
& V_80 , V_83 , NULL ) ;
F_31 ( V_67 , & V_84 ) ;
return V_67 ;
}
static void F_35 ( struct V_67 * V_68 )
{
struct V_1 * V_2 = F_25 ( V_68 ) ;
F_14 ( V_2 , F_26 ( V_68 -> V_74 ) ) ;
}
static void F_36 ( struct V_67 * V_68 )
{
struct V_1 * V_2 = F_25 ( V_68 ) ;
F_3 ( V_2 , 0x0 , V_56 ) ;
}
static struct V_67 * F_37 ( struct V_75 * V_36 ,
struct V_1 * V_2 )
{
struct V_72 * V_68 ;
struct V_67 * V_67 ;
V_68 = F_29 ( V_2 -> V_36 , sizeof( * V_68 ) , V_76 ) ;
if ( ! V_68 )
return NULL ;
V_68 -> V_2 = V_2 ;
V_67 = (struct V_67 * ) V_68 ;
V_67 -> V_77 = V_78 ;
V_67 -> V_79 = 1 << 1 ;
F_30 ( V_36 , V_67 ,
& V_80 , V_85 , NULL ) ;
F_31 ( V_67 , & V_86 ) ;
return V_67 ;
}
static void F_38 ( struct V_75 * V_36 ,
struct V_1 * V_2 )
{
V_2 -> V_87 = F_37 ( V_36 , V_2 ) ;
V_2 -> V_88 = F_34 ( V_36 , V_2 ) ;
V_2 -> V_89 = F_28 ( V_36 , V_2 ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
if ( V_2 -> V_87 )
F_22 ( V_2 -> V_87 ) ;
V_2 -> V_87 = NULL ;
if ( V_2 -> V_88 )
F_22 ( V_2 -> V_88 ) ;
V_2 -> V_88 = NULL ;
}
static int F_40 ( struct V_90 * V_36 , struct V_90 * V_91 , void * V_92 )
{
struct V_1 * V_2 = F_41 ( V_36 ) ;
struct V_75 * V_93 = V_92 ;
unsigned int V_94 ;
V_2 -> V_93 = V_93 ;
for ( V_94 = 0 ; V_94 < 8 ; V_94 ++ ) {
F_3 ( V_2 , V_95 [ V_94 ] ,
V_96 + ( V_94 * 4 ) ) ;
F_3 ( V_2 , V_95 [ V_94 ] ,
V_97 + ( V_94 * 4 ) ) ;
}
F_38 ( V_93 , V_2 ) ;
return 0 ;
}
static void F_42 ( struct V_90 * V_36 , struct V_90 * V_91 ,
void * V_92 )
{
struct V_1 * V_2 = F_41 ( V_36 ) ;
F_39 ( V_2 ) ;
}
static int F_43 ( struct V_98 * V_99 )
{
struct V_90 * V_36 = & V_99 -> V_36 ;
struct V_34 * V_35 = V_36 -> V_37 ;
struct V_1 * V_2 ;
struct V_100 * V_101 ;
F_44 ( L_1 , V_39 ) ;
if ( ! V_35 )
return - V_102 ;
V_2 = F_29 ( V_36 , sizeof( * V_2 ) , V_76 ) ;
if ( ! V_2 )
return - V_103 ;
V_2 -> V_36 = V_36 ;
V_101 = F_45 ( V_99 , V_104 , L_7 ) ;
if ( ! V_101 ) {
F_46 ( L_8 ) ;
return - V_103 ;
}
V_2 -> V_4 = F_47 ( V_36 , V_101 -> V_105 , F_48 ( V_101 ) ) ;
if ( ! V_2 -> V_4 )
return - V_103 ;
V_2 -> V_106 = F_49 ( V_36 , L_9 ) ;
if ( ! F_50 ( V_2 -> V_106 ) )
F_51 ( V_2 -> V_106 ) ;
F_52 ( V_99 , V_2 ) ;
return F_53 ( V_36 , & V_107 ) ;
}
static int F_54 ( struct V_98 * V_99 )
{
F_55 ( & V_99 -> V_36 , & V_107 ) ;
return 0 ;
}
