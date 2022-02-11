int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
unsigned long * V_5 )
{
int V_6 ;
switch ( V_4 -> V_7 . V_8 ) {
case V_9 :
case V_10 :
case V_11 :
case V_12 :
case V_13 :
case V_14 :
if ( V_5 )
F_2 ( V_5 , V_15 ) ;
V_6 = V_16 ;
break;
case V_17 :
if ( V_5 )
F_2 ( V_5 , V_18 ) ;
V_6 = V_19 ;
break;
case V_20 :
if ( V_4 -> V_7 . V_21 ) {
if ( V_5 )
F_2 ( V_5 , V_18 ) ;
V_6 = V_19 ;
break;
}
case V_22 :
case V_23 :
case V_24 :
case V_25 :
case V_26 :
case V_27 :
case V_28 :
V_6 = V_29 ;
break;
default:
F_3 ( V_2 -> V_30 , L_1 ,
V_4 -> V_7 . V_8 ) ;
V_6 = V_29 ;
break;
}
return V_6 ;
}
T_1 F_4 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
T_1 V_31 ;
switch ( V_4 -> V_7 . V_32 ) {
case V_33 :
V_31 = V_34 ;
break;
case V_35 :
if ( ! V_4 -> V_7 . V_21 &&
! V_4 -> V_7 . V_36 &&
! V_4 -> V_7 . V_37 )
V_31 = V_38 ;
else
V_31 = V_39 ;
break;
default:
V_31 = V_40 ;
F_5 ( V_2 -> V_30 ,
L_2 ) ;
break;
}
return V_31 ;
}
void F_6 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
unsigned long * V_5 )
{
F_2 ( V_5 , V_41 ) ;
F_2 ( V_5 , V_42 ) ;
F_2 ( V_5 , V_43 ) ;
if ( V_4 -> V_7 . V_44 )
F_2 ( V_5 , 10000baseSR_Full ) ;
if ( V_4 -> V_7 . V_45 )
F_2 ( V_5 , 10000baseLR_Full ) ;
if ( V_4 -> V_7 . V_46 )
F_2 ( V_5 , 10000baseLRM_Full ) ;
if ( V_4 -> V_7 . V_47 )
F_2 ( V_5 , 10000baseER_Full ) ;
if ( V_4 -> V_7 . V_48 ||
V_4 -> V_7 . V_49 ||
V_4 -> V_7 . V_50 )
F_2 ( V_5 , 1000baseX_Full ) ;
if ( V_4 -> V_7 . V_21 ) {
F_2 ( V_5 , 1000baseT_Half ) ;
F_2 ( V_5 , 1000baseT_Full ) ;
}
switch ( V_4 -> V_7 . V_51 ) {
case 0x00 :
break;
case 0x02 :
F_2 ( V_5 , 100000baseSR4_Full ) ;
F_2 ( V_5 , 25000baseSR_Full ) ;
break;
case 0x03 :
case 0x04 :
F_2 ( V_5 , 100000baseLR4_ER4_Full ) ;
break;
case 0x0b :
case 0x0c :
case 0x0d :
F_2 ( V_5 , 100000baseCR4_Full ) ;
F_2 ( V_5 , 25000baseCR_Full ) ;
break;
default:
F_3 ( V_2 -> V_30 ,
L_3 ,
V_4 -> V_7 . V_51 ) ;
break;
}
if ( V_4 -> V_7 . V_52 ||
V_4 -> V_7 . V_53 ||
V_4 -> V_7 . V_54 ) {
if ( V_4 -> V_7 . V_55 >= 31 )
F_2 ( V_5 , 2500baseX_Full ) ;
if ( V_4 -> V_7 . V_55 >= 12 )
F_2 ( V_5 , 1000baseX_Full ) ;
}
switch ( V_4 -> V_7 . V_8 ) {
case V_9 :
case V_10 :
case V_11 :
case V_12 :
case V_13 :
case V_14 :
break;
case V_20 :
if ( V_4 -> V_7 . V_21 )
break;
case V_22 :
case V_23 :
case V_24 :
case V_25 :
case V_26 :
case V_27 :
case V_28 :
default:
F_3 ( V_2 -> V_30 ,
L_4 ) ;
F_2 ( V_5 , 1000baseT_Half ) ;
F_2 ( V_5 , 1000baseT_Full ) ;
break;
}
}
static const struct V_56 * F_7 ( struct V_1 * V_2 )
{
return V_2 -> V_57 ? V_2 -> V_58 : NULL ;
}
static struct V_1 * F_8 ( struct V_59 * V_60 )
{
struct V_1 * V_61 , * V_62 , * V_63 = NULL ;
V_62 = F_9 ( sizeof( * V_62 ) , V_64 ) ;
F_10 ( & V_65 ) ;
F_11 (sfp, &sfp_buses, node) {
if ( V_61 -> V_59 == V_60 ) {
F_12 ( & V_61 -> V_66 ) ;
V_63 = V_61 ;
break;
}
}
if ( ! V_63 && V_62 ) {
F_13 ( & V_62 -> V_66 ) ;
V_62 -> V_59 = V_60 ;
F_14 ( & V_62 -> V_67 , & V_68 ) ;
V_63 = V_62 ;
V_62 = NULL ;
}
F_15 ( & V_65 ) ;
F_16 ( V_62 ) ;
return V_63 ;
}
static void F_17 ( struct V_66 * V_66 ) __releases( V_65 )
{
struct V_1 * V_2 = F_18 ( V_66 , struct V_1 , V_66 ) ;
F_19 ( & V_2 -> V_67 ) ;
F_15 ( & V_65 ) ;
F_16 ( V_2 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
F_21 ( & V_2 -> V_66 , F_17 , & V_65 ) ;
}
static int F_22 ( struct V_1 * V_2 )
{
const struct V_56 * V_69 = V_2 -> V_58 ;
int V_70 ;
if ( V_69 ) {
if ( V_69 -> V_71 )
V_69 -> V_71 ( V_2 -> V_72 ) ;
if ( V_69 -> V_73 && V_2 -> V_74 ) {
V_70 = V_69 -> V_73 ( V_2 -> V_72 , V_2 -> V_74 ) ;
if ( V_70 )
return V_70 ;
}
}
if ( V_2 -> V_75 )
V_2 -> V_76 -> V_77 ( V_2 -> V_61 ) ;
V_2 -> V_57 = true ;
return 0 ;
}
static void F_23 ( struct V_1 * V_2 )
{
const struct V_56 * V_69 = V_2 -> V_58 ;
if ( V_2 -> V_57 ) {
if ( V_2 -> V_75 )
V_2 -> V_76 -> V_78 ( V_2 -> V_61 ) ;
if ( V_2 -> V_74 && V_69 && V_69 -> V_79 )
V_69 -> V_79 ( V_2 -> V_72 ) ;
}
V_2 -> V_57 = false ;
}
int F_24 ( struct V_1 * V_2 , struct V_80 * V_81 )
{
if ( ! V_2 -> V_57 )
return - V_82 ;
return V_2 -> V_76 -> V_83 ( V_2 -> V_61 , V_81 ) ;
}
int F_25 ( struct V_1 * V_2 , struct V_84 * V_85 ,
T_2 * V_86 )
{
if ( ! V_2 -> V_57 )
return - V_82 ;
return V_2 -> V_76 -> V_87 ( V_2 -> V_61 , V_85 , V_86 ) ;
}
void F_26 ( struct V_1 * V_2 )
{
if ( V_2 -> V_57 )
V_2 -> V_76 -> V_77 ( V_2 -> V_61 ) ;
V_2 -> V_75 = true ;
}
void F_27 ( struct V_1 * V_2 )
{
if ( V_2 -> V_57 )
V_2 -> V_76 -> V_78 ( V_2 -> V_61 ) ;
V_2 -> V_75 = false ;
}
struct V_1 * F_28 ( struct V_59 * V_60 ,
struct V_88 * V_89 , void * V_72 ,
const struct V_56 * V_69 )
{
struct V_1 * V_2 = F_8 ( V_60 ) ;
int V_70 = 0 ;
if ( V_2 ) {
F_29 () ;
V_2 -> V_58 = V_69 ;
V_2 -> V_72 = V_72 ;
V_2 -> V_90 = V_89 ;
if ( V_2 -> V_61 )
V_70 = F_22 ( V_2 ) ;
F_30 () ;
}
if ( V_70 ) {
F_20 ( V_2 ) ;
V_2 = NULL ;
}
return V_2 ;
}
void F_31 ( struct V_1 * V_2 )
{
F_29 () ;
F_23 ( V_2 ) ;
V_2 -> V_72 = NULL ;
V_2 -> V_90 = NULL ;
F_30 () ;
F_20 ( V_2 ) ;
}
int F_32 ( struct V_1 * V_2 , struct V_91 * V_74 )
{
const struct V_56 * V_69 = F_7 ( V_2 ) ;
int V_70 = 0 ;
if ( V_69 && V_69 -> V_73 )
V_70 = V_69 -> V_73 ( V_2 -> V_72 , V_74 ) ;
if ( V_70 == 0 )
V_2 -> V_74 = V_74 ;
return V_70 ;
}
void F_33 ( struct V_1 * V_2 )
{
const struct V_56 * V_69 = F_7 ( V_2 ) ;
if ( V_69 && V_69 -> V_79 )
V_69 -> V_79 ( V_2 -> V_72 ) ;
V_2 -> V_74 = NULL ;
}
void F_34 ( struct V_1 * V_2 )
{
const struct V_56 * V_69 = F_7 ( V_2 ) ;
if ( V_69 && V_69 -> V_92 )
V_69 -> V_92 ( V_2 -> V_72 ) ;
}
void F_35 ( struct V_1 * V_2 )
{
const struct V_56 * V_69 = F_7 ( V_2 ) ;
if ( V_69 && V_69 -> V_71 )
V_69 -> V_71 ( V_2 -> V_72 ) ;
}
int F_36 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_56 * V_69 = F_7 ( V_2 ) ;
int V_70 = 0 ;
if ( V_69 && V_69 -> V_93 )
V_70 = V_69 -> V_93 ( V_2 -> V_72 , V_4 ) ;
return V_70 ;
}
void F_37 ( struct V_1 * V_2 )
{
const struct V_56 * V_69 = F_7 ( V_2 ) ;
if ( V_69 && V_69 -> V_94 )
V_69 -> V_94 ( V_2 -> V_72 ) ;
}
struct V_1 * F_38 ( struct V_95 * V_96 , struct V_61 * V_61 ,
const struct V_97 * V_69 )
{
struct V_1 * V_2 = F_8 ( V_96 -> V_98 ) ;
int V_70 = 0 ;
if ( V_2 ) {
F_29 () ;
V_2 -> V_30 = V_96 ;
V_2 -> V_61 = V_61 ;
V_2 -> V_76 = V_69 ;
if ( V_2 -> V_90 )
V_70 = F_22 ( V_2 ) ;
F_30 () ;
}
if ( V_70 ) {
F_20 ( V_2 ) ;
V_2 = NULL ;
}
return V_2 ;
}
void F_39 ( struct V_1 * V_2 )
{
F_29 () ;
F_23 ( V_2 ) ;
V_2 -> V_30 = NULL ;
V_2 -> V_61 = NULL ;
V_2 -> V_76 = NULL ;
F_30 () ;
F_20 ( V_2 ) ;
}
