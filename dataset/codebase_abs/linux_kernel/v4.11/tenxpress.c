static int F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 , V_3 , V_4 ,
1 << V_5 ) ;
F_3 ( V_2 , V_6 , V_7 ,
1 << V_8 , true ) ;
F_2 ( V_2 , V_6 , V_9 ,
V_10 ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
V_12 = F_5 ( sizeof( * V_12 ) , V_13 ) ;
if ( ! V_12 )
return - V_14 ;
V_2 -> V_12 = V_12 ;
V_12 -> V_15 = V_2 -> V_15 ;
V_2 -> V_16 . V_17 = V_18 ;
V_2 -> V_16 . V_19 = V_20 ;
V_2 -> V_21 = V_22 | V_23 ;
V_2 -> V_24 = ( V_25 | V_26 |
V_27 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_28 ;
F_7 ( V_2 ) -> type -> V_29 ( V_2 ) ;
if ( ! ( V_2 -> V_15 & V_30 ) ) {
V_28 = F_8 ( V_2 , V_18 ) ;
if ( V_28 < 0 )
return V_28 ;
V_28 = F_9 ( V_2 , V_18 ) ;
if ( V_28 < 0 )
return V_28 ;
}
V_28 = F_1 ( V_2 ) ;
if ( V_28 < 0 )
return V_28 ;
F_10 ( V_2 , V_2 -> V_31 ) ;
F_11 ( V_2 ) ;
F_12 ( V_32 / 5 ) ;
F_13 ( V_2 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
int V_28 , V_33 ;
F_15 ( V_2 ) ;
V_33 = F_16 ( V_2 , V_6 , V_34 ) ;
V_33 |= ( 1 << V_35 ) ;
F_2 ( V_2 , V_6 , V_34 , V_33 ) ;
F_17 ( 200 ) ;
V_28 = F_8 ( V_2 , V_18 ) ;
if ( V_28 < 0 )
goto V_36;
V_28 = F_1 ( V_2 ) ;
if ( V_28 < 0 )
goto V_36;
F_17 ( 10 ) ;
V_36:
F_18 ( V_2 ) ;
return V_28 ;
}
static void F_19 ( struct V_1 * V_2 , bool V_37 )
{
struct V_11 * V_38 = V_2 -> V_12 ;
bool V_39 ;
int V_33 ;
if ( V_37 ) {
V_39 = false ;
} else {
V_33 = F_16 ( V_2 , V_40 , V_41 ) ;
if ( ! ( V_33 & V_42 ) )
return;
V_39 = ! ( V_33 & V_43 ) ;
if ( V_39 )
V_38 -> V_44 ++ ;
}
if ( ! V_38 -> V_44 )
return;
if ( ! V_39 || V_38 -> V_44 == V_45 ) {
V_33 = F_16 ( V_2 , V_6 ,
V_9 ) ;
V_33 &= ~ ( V_46 << V_47 ) ;
if ( ! V_39 ) {
V_33 |= V_48 << V_47 ;
} else {
V_33 |= V_49 << V_47 ;
F_20 ( V_2 , V_50 , V_2 -> V_51 ,
L_1
L_2
L_3
L_4 ) ;
}
F_2 ( V_2 , V_6 ,
V_9 , V_33 ) ;
V_38 -> V_44 = V_39 ;
}
}
static bool F_21 ( struct V_1 * V_2 )
{
return F_22 ( V_2 ,
V_52 |
V_53 |
V_54 ) ;
}
static void F_23 ( struct V_1 * V_2 )
{
F_3 ( V_2 , V_55 , V_56 ,
1 << V_57 ,
V_2 -> V_58 == V_59 ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
F_25 (
V_2 , ! ! ( V_2 -> V_15 & V_60 ) ,
V_18 ) ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
bool V_61 , V_62 ;
if ( V_2 -> V_15 & ( V_63 | V_30 ) ) {
V_12 -> V_15 = V_2 -> V_15 ;
return 0 ;
}
V_61 = ( V_2 -> V_15 == V_64 &&
V_12 -> V_15 != V_64 ) ;
V_62 = ( F_27 ( V_12 , V_2 , F_28 ( V_2 ) ) ||
F_29 ( V_12 , V_2 , 1 << V_65 ) ) ;
if ( V_62 || V_61 ) {
F_14 ( V_2 ) ;
F_13 ( V_2 ) ;
}
F_24 ( V_2 ) ;
F_30 ( V_2 ) ;
F_31 ( V_2 ) ;
F_23 ( V_2 ) ;
F_11 ( V_2 ) ;
V_12 -> V_58 = V_2 -> V_58 ;
V_12 -> V_15 = V_2 -> V_15 ;
return 0 ;
}
static bool F_32 ( struct V_1 * V_2 )
{
struct V_66 V_67 = V_2 -> V_68 ;
V_2 -> V_68 . V_69 = F_21 ( V_2 ) ;
V_2 -> V_68 . V_70 = 10000 ;
V_2 -> V_68 . V_71 = true ;
V_2 -> V_68 . V_72 = F_33 ( V_2 ) ;
F_19 ( V_2 , V_2 -> V_68 . V_69 ) ;
return ! F_34 ( & V_2 -> V_68 , & V_67 ) ;
}
static void F_35 ( struct V_1 * V_2 )
{
int V_33 ;
V_33 = ( 1 << V_73 ) ;
F_2 ( V_2 , V_6 , V_34 , V_33 ) ;
F_12 ( V_74 ) ;
}
static void F_36 ( struct V_1 * V_2 )
{
F_37 ( V_2 -> V_12 ) ;
V_2 -> V_12 = NULL ;
}
void F_38 ( struct V_1 * V_2 , enum V_75 V_76 )
{
int V_33 ;
switch ( V_76 ) {
case V_77 :
V_33 = ( V_48 << V_78 ) |
( V_48 << V_47 ) |
( V_48 << V_79 ) ;
break;
case V_80 :
V_33 = ( V_81 << V_78 ) |
( V_81 << V_47 ) |
( V_81 << V_79 ) ;
break;
default:
V_33 = V_10 ;
break;
}
F_2 ( V_2 , V_6 , V_9 , V_33 ) ;
}
static const char * F_39 ( struct V_1 * V_2 , unsigned int V_82 )
{
if ( V_82 < F_40 ( V_83 ) )
return V_83 [ V_82 ] ;
return NULL ;
}
static int
F_41 ( struct V_1 * V_2 , int * V_84 , unsigned V_85 )
{
int V_28 ;
if ( ! ( V_85 & V_86 ) )
return 0 ;
V_28 = F_14 ( V_2 ) ;
V_84 [ 0 ] = V_28 ? - 1 : 1 ;
F_11 ( V_2 ) ;
return V_28 ;
}
static void
F_42 ( struct V_1 * V_2 ,
struct V_87 * V_88 )
{
T_1 V_89 = 0 , V_90 = 0 ;
int V_33 ;
V_33 = F_16 ( V_2 , V_40 , V_91 ) ;
if ( V_33 & V_92 )
V_89 |= V_27 ;
V_33 = F_16 ( V_2 , V_40 , V_93 ) ;
if ( V_33 & V_94 )
V_90 |= V_27 ;
F_43 ( & V_2 -> V_16 , V_88 , V_89 , V_90 ) ;
if ( F_44 ( V_2 ) )
V_88 -> V_95 . V_70 = V_96 ;
}
static int
F_45 ( struct V_1 * V_2 ,
const struct V_87 * V_88 )
{
if ( ! V_88 -> V_95 . V_97 )
return - V_98 ;
return F_46 ( V_2 , V_88 ) ;
}
static void F_47 ( struct V_1 * V_2 , T_1 V_99 )
{
F_3 ( V_2 , V_40 , V_91 ,
V_92 ,
V_99 & V_27 ) ;
}
