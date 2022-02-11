static T_1 F_1 ( struct V_1 * V_2 , int V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static void F_3 ( struct V_1 * V_2 , T_1 V_5 , int V_3 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 ,
T_1 V_6 , T_1 V_7 , T_1 V_8 )
{
T_1 V_5 = F_1 ( V_2 , V_9 ) ;
V_5 &= ~ ( V_10 << V_11 ) ;
V_5 &= ~ ( V_10 << V_12 ) ;
V_5 &= ~ ( V_10 << V_13 ) ;
V_5 |= V_6 << V_11 ;
V_5 |= V_7 << V_12 ;
V_5 |= V_8 << V_13 ;
F_3 ( V_2 , V_5 , V_9 ) ;
}
static void F_6 ( struct V_1 * V_2 , T_1 V_14 )
{
T_1 V_5 = F_1 ( V_2 , V_9 ) ;
V_5 &= ~ ( V_15 << V_16 ) ;
V_5 |= V_14 << V_16 ;
F_3 ( V_2 , V_5 , V_9 ) ;
}
static void F_7 ( struct V_1 * V_2 , T_1 V_17 )
{
T_1 V_5 = F_1 ( V_2 , V_9 ) ;
V_5 &= ~ ( V_18 << V_19 ) ;
V_5 |= V_17 << V_19 ;
F_3 ( V_2 , V_5 , V_9 ) ;
}
static void F_8 ( struct V_1 * V_2 ,
bool V_20 ,
bool V_21 ,
enum V_22 V_23 )
{
T_1 V_24 ;
T_1 V_5 = F_1 ( V_2 , V_9 ) ;
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
F_3 ( V_2 , V_5 , V_9 ) ;
}
static void F_9 ( struct V_1 * V_2 , T_1 V_32 )
{
T_1 V_5 = F_1 ( V_2 , V_9 ) ;
V_5 &= ~ V_33 ;
V_5 |= V_32 ;
F_3 ( V_2 , V_5 , V_34 ) ;
}
static void F_10 ( struct V_1 * V_2 , bool V_20 )
{
struct V_35 * V_36 = V_2 -> V_37 -> V_38 ;
bool V_21 = false ;
F_11 ( V_2 -> V_37 , L_1 , V_39 ) ;
if ( V_20 ) {
F_12 ( L_2 ) ;
F_3 ( V_2 , V_40 , V_41 ) ;
} else {
F_12 ( L_3 ) ;
F_3 ( V_2 , V_42 , V_41 ) ;
}
F_5 ( V_2 ,
V_43 ,
V_44 ,
V_45 ) ;
F_6 ( V_2 , V_46 ) ;
F_7 ( V_2 , V_47 ) ;
if ( F_13 ( V_36 , L_4 ) ) {
F_9 ( V_2 -> V_4 + V_34 ,
V_33 ) ;
V_21 = true ;
}
F_8 ( V_2 , V_20 ,
V_21 , V_27 ) ;
}
static void F_14 ( struct V_1 * V_2 , bool V_20 )
{
struct V_35 * V_36 = V_2 -> V_37 -> V_38 ;
bool V_21 = false ;
F_11 ( V_2 -> V_37 , L_1 , V_39 ) ;
if ( ! V_20 ) {
F_15 ( L_5 ) ;
return;
}
F_12 ( L_6 ) ;
F_5 ( V_2 -> V_4 + V_48 ,
V_43 ,
V_44 ,
V_45 ) ;
F_6 ( V_2 -> V_4 + V_48 ,
V_49 ) ;
F_7 ( V_2 -> V_4 + V_48 , V_50 ) ;
if ( F_13 ( V_36 , L_4 ) ) {
F_9 ( V_2 , V_33 ) ;
V_21 = true ;
}
F_8 ( V_2 -> V_4 + V_48 ,
V_20 ,
V_21 ,
V_29 ) ;
F_3 ( V_2 ,
( V_51 << V_52 )
| V_53 ,
V_54 ) ;
F_3 ( V_2 , 0 , V_55 ) ;
}
static void F_16 ( struct V_56 * V_57 , int V_58 )
{
}
static bool F_17 ( struct V_56 * V_57 ,
const struct V_59 * V_58 ,
struct V_59 * V_60 )
{
return true ;
}
static void F_18 ( struct V_56 * V_57 ,
struct V_59 * V_58 ,
struct V_59 * V_60 )
{
}
static void F_19 ( struct V_56 * V_57 )
{
}
static void F_20 ( struct V_56 * V_57 )
{
struct V_61 * V_62 = F_21 ( V_57 ) ;
F_22 ( V_57 ) ;
F_23 ( V_62 ) ;
}
static void F_24 ( struct V_56 * V_57 )
{
struct V_1 * V_2 = F_25 ( V_57 ) ;
F_14 ( V_2 , true ) ;
}
static void F_26 ( struct V_56 * V_57 )
{
struct V_1 * V_2 = F_25 ( V_57 ) ;
F_3 ( V_2 , 0x0 , V_48 ) ;
F_3 ( V_2 , 1 , V_55 ) ;
}
static struct V_56 * F_27 ( struct V_63 * V_37 ,
struct V_1 * V_2 )
{
struct V_61 * V_57 ;
struct V_56 * V_56 ;
V_57 = F_28 ( V_2 -> V_37 , sizeof( * V_57 ) , V_64 ) ;
if ( ! V_57 )
return NULL ;
V_57 -> V_2 = V_2 ;
V_56 = (struct V_56 * ) V_57 ;
V_56 -> V_65 = V_66 ;
V_56 -> V_67 = 1 << 0 ;
F_29 ( V_37 , V_56 ,
& V_68 , V_69 ) ;
F_30 ( V_56 , & V_70 ) ;
return V_56 ;
}
static void F_31 ( struct V_56 * V_57 )
{
struct V_1 * V_2 = F_25 ( V_57 ) ;
F_10 ( V_2 , true ) ;
}
static void F_32 ( struct V_56 * V_57 )
{
struct V_1 * V_2 = F_25 ( V_57 ) ;
F_3 ( V_2 , 0x0 , V_9 ) ;
}
static struct V_56 * F_33 ( struct V_63 * V_37 ,
struct V_1 * V_2 )
{
struct V_61 * V_57 ;
struct V_56 * V_56 ;
V_57 = F_28 ( V_2 -> V_37 , sizeof( * V_57 ) , V_64 ) ;
if ( ! V_57 )
return NULL ;
V_57 -> V_2 = V_2 ;
V_56 = (struct V_56 * ) V_57 ;
V_56 -> V_65 = V_66 ;
V_56 -> V_67 = 1 << 1 ;
F_29 ( V_37 , V_56 ,
& V_68 , V_71 ) ;
F_30 ( V_56 , & V_72 ) ;
return V_56 ;
}
static void F_34 ( struct V_63 * V_37 ,
struct V_1 * V_2 )
{
V_2 -> V_73 = F_33 ( V_37 , V_2 ) ;
V_2 -> V_74 = F_27 ( V_37 , V_2 ) ;
}
static void F_35 ( struct V_1 * V_2 )
{
if ( V_2 -> V_73 )
F_22 ( V_2 -> V_73 ) ;
V_2 -> V_73 = NULL ;
if ( V_2 -> V_74 )
F_22 ( V_2 -> V_74 ) ;
V_2 -> V_74 = NULL ;
}
static int F_36 ( struct V_75 * V_37 , struct V_75 * V_76 , void * V_77 )
{
struct V_1 * V_2 = F_37 ( V_37 ) ;
struct V_63 * V_78 = V_77 ;
unsigned int V_79 ;
int V_80 ;
V_2 -> V_78 = V_78 ;
for ( V_79 = 0 ; V_79 < 8 ; V_79 ++ ) {
F_3 ( V_2 , V_81 [ V_79 ] ,
V_82 + ( V_79 * 4 ) ) ;
F_3 ( V_2 , V_81 [ V_79 ] ,
V_83 + ( V_79 * 4 ) ) ;
}
F_34 ( V_78 , V_2 ) ;
V_80 = F_38 ( V_37 , V_78 ) ;
if ( V_80 )
F_35 ( V_2 ) ;
return V_80 ;
}
static void F_39 ( struct V_75 * V_37 , struct V_75 * V_76 ,
void * V_77 )
{
}
static int F_40 ( struct V_75 * V_37 , void * V_77 )
{
return V_37 -> V_38 == V_77 ;
}
static int F_41 ( struct V_75 * V_37 )
{
return 0 ;
}
static void F_42 ( struct V_75 * V_37 )
{
}
static int F_43 ( struct V_84 * V_85 )
{
struct V_75 * V_37 = & V_85 -> V_37 ;
struct V_35 * V_36 = V_37 -> V_38 ;
struct V_1 * V_2 ;
struct V_86 * V_87 ;
struct V_35 * V_88 ;
struct V_89 * V_90 = NULL ;
F_44 ( L_1 , V_39 ) ;
if ( ! V_36 )
return - V_91 ;
V_2 = F_28 ( V_37 , sizeof( * V_2 ) , V_64 ) ;
if ( ! V_2 )
return - V_92 ;
V_2 -> V_37 = V_37 ;
V_87 = F_45 ( V_85 , V_93 , L_7 ) ;
if ( ! V_87 ) {
F_15 ( L_8 ) ;
return - V_92 ;
}
V_2 -> V_4 = F_46 ( V_37 , V_87 -> V_94 , F_47 ( V_87 ) ) ;
if ( ! V_2 -> V_4 )
return - V_92 ;
V_2 -> V_95 = F_48 ( V_37 , L_9 ) ;
if ( ! F_49 ( V_2 -> V_95 ) )
F_50 ( V_2 -> V_95 ) ;
F_51 ( V_85 , V_2 ) ;
F_52 ( V_36 , NULL , NULL , V_37 ) ;
V_88 = F_53 ( V_36 , NULL ) ;
while ( V_88 ) {
F_54 ( V_37 , & V_90 , F_40 , V_88 ) ;
F_55 ( V_88 ) ;
V_88 = F_53 ( V_36 , V_88 ) ;
}
F_56 ( V_37 , & V_96 , V_90 ) ;
return F_57 ( V_37 , & V_97 ) ;
}
static int F_58 ( struct V_84 * V_85 )
{
F_59 ( & V_85 -> V_37 , & V_96 ) ;
F_60 ( & V_85 -> V_37 , & V_97 ) ;
return 0 ;
}
