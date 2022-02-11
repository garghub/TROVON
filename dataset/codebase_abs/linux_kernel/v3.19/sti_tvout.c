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
F_11 ( V_2 -> V_36 , L_1 , V_39 ) ;
if ( V_20 ) {
F_12 ( L_2 ) ;
F_3 ( V_2 , V_40 , V_41 ) ;
V_38 = V_42 ;
} else {
F_12 ( L_3 ) ;
F_3 ( V_2 , V_43 , V_41 ) ;
V_38 = V_44 ;
}
F_5 ( V_2 , V_45 ,
V_46 ,
V_47 ,
V_48 ) ;
F_6 ( V_2 , V_45 ,
V_49 ) ;
F_7 ( V_2 , V_45 , V_50 ) ;
if ( F_13 ( V_35 , L_4 ) ) {
F_9 ( V_2 , V_38 ,
V_33 ) ;
V_21 = true ;
}
F_8 ( V_2 , V_45 , V_20 ,
V_21 , V_27 ) ;
}
static void F_14 ( struct V_1 * V_2 , bool V_20 )
{
struct V_34 * V_35 = V_2 -> V_36 -> V_37 ;
bool V_21 = false ;
T_1 V_38 ;
int V_5 ;
F_11 ( V_2 -> V_36 , L_1 , V_39 ) ;
if ( V_20 ) {
V_5 = V_51 << V_52 ;
V_5 |= V_53 ;
F_3 ( V_2 , V_5 , V_54 ) ;
V_38 = V_42 ;
} else {
V_5 = V_55 << V_52 ;
V_5 |= V_56 ;
F_3 ( V_2 , V_5 , V_54 ) ;
V_38 = V_44 ;
}
F_5 ( V_2 , V_57 ,
V_46 ,
V_47 ,
V_48 ) ;
F_6 ( V_2 , V_57 , V_58 ) ;
F_7 ( V_2 , V_57 , V_59 ) ;
if ( F_13 ( V_35 , L_4 ) ) {
F_9 ( V_2 ,
V_38 , V_33 ) ;
V_21 = true ;
}
F_8 ( V_2 , V_57 , V_20 ,
V_21 ,
V_29 ) ;
F_3 ( V_2 , 0 , V_60 ) ;
}
static void F_15 ( struct V_61 * V_62 , int V_63 )
{
}
static bool F_16 ( struct V_61 * V_62 ,
const struct V_64 * V_63 ,
struct V_64 * V_65 )
{
return true ;
}
static void F_17 ( struct V_61 * V_62 ,
struct V_64 * V_63 ,
struct V_64 * V_65 )
{
}
static void F_18 ( struct V_61 * V_62 )
{
}
static void F_19 ( struct V_61 * V_62 )
{
struct V_66 * V_67 = F_20 ( V_62 ) ;
F_21 ( V_62 ) ;
F_22 ( V_67 ) ;
}
static void F_23 ( struct V_61 * V_62 )
{
struct V_1 * V_2 = F_24 ( V_62 ) ;
F_14 ( V_2 , F_25 ( V_62 -> V_68 ) ) ;
}
static void F_26 ( struct V_61 * V_62 )
{
struct V_1 * V_2 = F_24 ( V_62 ) ;
F_3 ( V_2 , 0x0 , V_57 ) ;
F_3 ( V_2 , 1 , V_60 ) ;
}
static struct V_61 * F_27 ( struct V_69 * V_36 ,
struct V_1 * V_2 )
{
struct V_66 * V_62 ;
struct V_61 * V_61 ;
V_62 = F_28 ( V_2 -> V_36 , sizeof( * V_62 ) , V_70 ) ;
if ( ! V_62 )
return NULL ;
V_62 -> V_2 = V_2 ;
V_61 = (struct V_61 * ) V_62 ;
V_61 -> V_71 = V_72 ;
V_61 -> V_73 = 1 << 0 ;
F_29 ( V_36 , V_61 ,
& V_74 , V_75 ) ;
F_30 ( V_61 , & V_76 ) ;
return V_61 ;
}
static void F_31 ( struct V_61 * V_62 )
{
struct V_1 * V_2 = F_24 ( V_62 ) ;
F_10 ( V_2 , F_25 ( V_62 -> V_68 ) ) ;
}
static void F_32 ( struct V_61 * V_62 )
{
struct V_1 * V_2 = F_24 ( V_62 ) ;
F_3 ( V_2 , 0x0 , V_45 ) ;
}
static struct V_61 * F_33 ( struct V_69 * V_36 ,
struct V_1 * V_2 )
{
struct V_66 * V_62 ;
struct V_61 * V_61 ;
V_62 = F_28 ( V_2 -> V_36 , sizeof( * V_62 ) , V_70 ) ;
if ( ! V_62 )
return NULL ;
V_62 -> V_2 = V_2 ;
V_61 = (struct V_61 * ) V_62 ;
V_61 -> V_71 = V_72 ;
V_61 -> V_73 = 1 << 1 ;
F_29 ( V_36 , V_61 ,
& V_74 , V_77 ) ;
F_30 ( V_61 , & V_78 ) ;
return V_61 ;
}
static void F_34 ( struct V_69 * V_36 ,
struct V_1 * V_2 )
{
V_2 -> V_79 = F_33 ( V_36 , V_2 ) ;
V_2 -> V_80 = F_27 ( V_36 , V_2 ) ;
}
static void F_35 ( struct V_1 * V_2 )
{
if ( V_2 -> V_79 )
F_21 ( V_2 -> V_79 ) ;
V_2 -> V_79 = NULL ;
if ( V_2 -> V_80 )
F_21 ( V_2 -> V_80 ) ;
V_2 -> V_80 = NULL ;
}
static int F_36 ( struct V_81 * V_36 , struct V_81 * V_82 , void * V_83 )
{
struct V_1 * V_2 = F_37 ( V_36 ) ;
struct V_69 * V_84 = V_83 ;
unsigned int V_85 ;
int V_86 ;
V_2 -> V_84 = V_84 ;
for ( V_85 = 0 ; V_85 < 8 ; V_85 ++ ) {
F_3 ( V_2 , V_87 [ V_85 ] ,
V_88 + ( V_85 * 4 ) ) ;
F_3 ( V_2 , V_87 [ V_85 ] ,
V_89 + ( V_85 * 4 ) ) ;
}
F_34 ( V_84 , V_2 ) ;
V_86 = F_38 ( V_36 , V_84 ) ;
if ( V_86 )
F_35 ( V_2 ) ;
return V_86 ;
}
static void F_39 ( struct V_81 * V_36 , struct V_81 * V_82 ,
void * V_83 )
{
}
static int F_40 ( struct V_81 * V_36 , void * V_83 )
{
return V_36 -> V_37 == V_83 ;
}
static int F_41 ( struct V_81 * V_36 )
{
return 0 ;
}
static void F_42 ( struct V_81 * V_36 )
{
}
static int F_43 ( struct V_90 * V_91 )
{
struct V_81 * V_36 = & V_91 -> V_36 ;
struct V_34 * V_35 = V_36 -> V_37 ;
struct V_1 * V_2 ;
struct V_92 * V_93 ;
struct V_34 * V_94 ;
struct V_95 * V_96 = NULL ;
F_44 ( L_1 , V_39 ) ;
if ( ! V_35 )
return - V_97 ;
V_2 = F_28 ( V_36 , sizeof( * V_2 ) , V_70 ) ;
if ( ! V_2 )
return - V_98 ;
V_2 -> V_36 = V_36 ;
V_93 = F_45 ( V_91 , V_99 , L_5 ) ;
if ( ! V_93 ) {
F_46 ( L_6 ) ;
return - V_98 ;
}
V_2 -> V_4 = F_47 ( V_36 , V_93 -> V_100 , F_48 ( V_93 ) ) ;
if ( ! V_2 -> V_4 )
return - V_98 ;
V_2 -> V_101 = F_49 ( V_36 , L_7 ) ;
if ( ! F_50 ( V_2 -> V_101 ) )
F_51 ( V_2 -> V_101 ) ;
F_52 ( V_91 , V_2 ) ;
F_53 ( V_35 , NULL , NULL , V_36 ) ;
V_94 = F_54 ( V_35 , NULL ) ;
while ( V_94 ) {
F_55 ( V_36 , & V_96 , F_40 , V_94 ) ;
F_56 ( V_94 ) ;
V_94 = F_54 ( V_35 , V_94 ) ;
}
F_57 ( V_36 , & V_102 , V_96 ) ;
return F_58 ( V_36 , & V_103 ) ;
}
static int F_59 ( struct V_90 * V_91 )
{
F_60 ( & V_91 -> V_36 , & V_102 ) ;
F_61 ( & V_91 -> V_36 , & V_103 ) ;
return 0 ;
}
