void F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
F_2 ( V_2 , V_5 , V_6 , 1 << V_3 , V_4 ) ;
}
void F_3 ( struct V_1 * V_2 , int V_3 , int V_7 )
{
F_2 ( V_2 , V_5 , V_8 , 1 << V_3 , V_7 ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
int V_9 = F_5 ( V_2 , V_10 ,
V_11 / V_12 ,
V_12 ) ;
if ( V_9 < 0 )
goto V_13;
V_9 = F_6 ( V_2 , V_14 ) ;
if ( V_9 < 0 )
goto V_13;
return 0 ;
V_13:
F_7 ( V_2 , V_15 , V_2 -> V_16 , V_17 L_1 ) ;
return V_9 ;
}
static int F_8 ( struct V_1 * V_2 , int V_18 , int V_19 )
{
int V_20 , V_21 ;
int V_22 ;
int V_9 = 0 ;
V_20 = F_9 ( V_2 , V_23 , V_24 ) ;
V_20 |= ( 1 << V_25 ) ;
F_10 ( V_2 , V_23 , V_24 , V_20 ) ;
V_21 = ( V_19 << V_26 ) ;
F_10 ( V_2 , V_18 , V_27 , V_21 ) ;
V_21 |= ( 1 << V_28 ) ;
F_10 ( V_2 , V_18 , V_27 , V_21 ) ;
F_10 ( V_2 , V_18 , V_27 ,
V_21 | ( 1 << V_29 ) ) ;
F_11 ( V_30 ) ;
V_21 |= ( 1 << V_31 ) ;
F_10 ( V_2 , V_18 , V_27 , V_21 ) ;
while ( V_21 & ( 1 << V_31 ) )
V_21 = F_9 ( V_2 , V_18 , V_27 ) ;
for ( V_22 = 0 ; V_22 < 4 ; V_22 ++ ) {
int V_32 = F_9 ( V_2 , V_18 , V_33 + V_22 ) ;
if ( V_32 != 0 ) {
F_7 ( V_2 , V_15 , V_2 -> V_16 , V_17 L_2
L_3 , V_22 , V_32 ) ;
V_9 = - V_34 ;
}
V_32 = F_9 ( V_2 , V_18 , V_35 + V_22 ) ;
if ( V_32 == 0 ) {
F_7 ( V_2 , V_15 , V_2 -> V_16 , V_17 L_2
L_4 , V_22 ) ;
V_9 = - V_34 ;
}
}
if ( V_9 == 0 )
F_12 ( V_2 , V_15 , V_2 -> V_16 , V_17 L_5 ) ;
F_10 ( V_2 , V_18 , V_27 , 0 ) ;
V_20 &= ~ ( 1 << V_25 ) ;
F_10 ( V_2 , V_23 , V_24 , V_20 ) ;
return V_9 ;
}
static int F_13 ( struct V_1 * V_2 )
{
return F_8 ( V_2 , V_23 , V_36 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
int V_37 ;
F_10 ( V_2 , V_5 , V_38 , V_39 ) ;
F_10 ( V_2 , V_5 , V_40 , V_39 ) ;
F_10 ( V_2 , V_5 ,
V_41 , V_42 ) ;
F_10 ( V_2 , V_5 ,
V_43 , V_42 ) ;
F_10 ( V_2 , V_10 ,
V_38 , V_44 ) ;
F_10 ( V_2 , V_10 ,
V_40 , V_44 ) ;
F_10 ( V_2 , V_10 ,
V_41 , V_45 ) ;
F_10 ( V_2 , V_10 ,
V_43 , V_45 ) ;
V_37 = F_9 ( V_2 , V_5 , V_46 ) ;
V_37 &= ~ ( ( 1 << V_47 ) | ( 1 << V_48 ) ) ;
F_10 ( V_2 , V_5 , V_46 , V_37 ) ;
F_15 ( V_2 ) ;
F_16 ( V_2 ) -> type -> V_49 ( V_2 ) ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_50 * V_51 ;
V_51 = F_18 ( sizeof( * V_51 ) , V_52 ) ;
if ( ! V_51 )
return - V_53 ;
V_2 -> V_51 = V_51 ;
V_51 -> V_54 = V_2 -> V_54 ;
V_2 -> V_55 . V_56 = V_14 ;
V_2 -> V_55 . V_57 = V_58 | V_59 ;
V_2 -> V_60 = V_61 | V_62 ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
int V_9 ;
V_9 = F_4 ( V_2 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = F_13 ( V_2 ) ;
if ( V_9 < 0 )
return V_9 ;
F_14 ( V_2 ) ;
return 0 ;
}
static void F_20 ( struct V_1 * V_2 , int V_18 )
{
int V_63 = ( 1 << V_64 ) | ( 1 << V_65 ) ;
int V_66 = F_9 ( V_2 , V_18 , V_67 ) ;
if ( ! ( V_2 -> V_54 & V_68 ) )
V_66 &= ~ V_63 ;
else
V_66 |= V_63 ;
F_10 ( V_2 , V_18 , V_67 , V_66 ) ;
}
static void F_21 ( struct V_1 * V_2 , int V_18 )
{
int V_69 = ( 1 << V_70 ) | ( 1 << V_71 )
| ( 1 << V_72 ) | ( 1 << V_73 ) ;
int V_74 = ( 1 << V_75 ) | ( 1 << V_76 )
| ( 1 << V_77 ) | ( 1 << V_78 ) ;
int V_79 = F_9 ( V_2 , V_18 , V_80 ) ;
int V_81 = F_9 ( V_2 , V_18 , V_82 ) ;
if ( ! ( V_2 -> V_54 & V_68 ) ) {
V_79 &= ~ V_69 ;
V_81 &= ~ V_74 ;
} else {
V_79 |= V_69 ;
V_81 |= V_74 ;
}
F_10 ( V_2 , V_18 , V_80 , V_79 ) ;
F_10 ( V_2 , V_18 , V_82 , V_81 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
F_23 ( V_2 ,
! ! ( V_2 -> V_54 & V_68 ) ,
V_14 ) ;
F_20 ( V_2 , V_23 ) ;
F_20 ( V_2 , V_5 ) ;
F_21 ( V_2 , V_10 ) ;
F_21 ( V_2 , V_5 ) ;
}
static void F_24 ( struct V_1 * V_2 , int V_18 )
{
int V_83 = F_9 ( V_2 , V_18 , V_67 ) ;
int V_84 = 50 ;
V_83 |= ( 1 << V_85 ) ;
F_10 ( V_2 , V_18 , V_67 , V_83 ) ;
while ( V_84 -- ) {
V_83 = F_9 ( V_2 , V_18 , V_67 ) ;
if ( ! ( V_83 & ( 1 << V_85 ) ) )
break;
F_11 ( 1 ) ;
}
if ( ! V_84 )
F_12 ( V_2 , V_15 , V_2 -> V_16 ,
V_17 L_6 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
F_24 ( V_2 , V_23 ) ;
}
static bool F_25 ( struct V_1 * V_2 )
{
return F_26 ( V_2 , V_14 ) ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_50 * V_51 = V_2 -> V_51 ;
enum V_86 V_87 = V_2 -> V_54 ^ V_51 -> V_54 ;
bool V_88 = F_28 ( V_51 , V_2 , V_61 ) ;
if ( V_2 -> V_54 & V_87 & V_89 ) {
F_4 ( V_2 ) ;
F_14 ( V_2 ) ;
F_29 ( V_2 ) ;
V_87 &= ~ V_89 ;
}
F_30 ( V_2 ) ;
F_31 ( V_2 ) ;
if ( V_87 & V_68 )
F_22 ( V_2 ) ;
if ( V_88 || V_87 )
F_15 ( V_2 ) ;
V_51 -> V_54 = V_2 -> V_54 ;
V_51 -> V_90 = V_2 -> V_90 ;
return 0 ;
}
static void F_32 ( struct V_1 * V_2 )
{
F_10 ( V_2 , V_10 , V_91 , 0 ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
F_34 ( V_2 -> V_51 ) ;
V_2 -> V_51 = NULL ;
}
static bool F_35 ( struct V_1 * V_2 )
{
struct V_50 * V_92 = V_2 -> V_51 ;
bool V_93 = V_2 -> V_94 . V_95 ;
V_2 -> V_94 . V_95 = F_25 ( V_2 ) ;
V_2 -> V_94 . V_96 = 10000 ;
V_2 -> V_94 . V_97 = true ;
V_2 -> V_94 . V_98 = V_2 -> V_99 ;
if ( V_2 -> V_94 . V_95 || ( V_2 -> V_90 != V_100 ) ) {
V_92 -> V_101 = V_102 ;
} else {
if ( F_36 ( V_102 , ( V_92 -> V_101 +
V_103 ) ) ) {
V_92 -> V_101 = V_102 ;
F_15 ( V_2 ) ;
}
}
return V_2 -> V_94 . V_95 != V_93 ;
}
static const char * F_37 ( struct V_1 * V_2 , unsigned int V_104 )
{
if ( V_104 < F_38 ( V_105 ) )
return V_105 [ V_104 ] ;
return NULL ;
}
static int F_39 ( struct V_1 * V_2 , int * V_106 , unsigned V_107 )
{
int V_9 ;
if ( ! ( V_107 & V_108 ) )
return 0 ;
V_9 = F_4 ( V_2 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = F_13 ( V_2 ) ;
F_14 ( V_2 ) ;
V_106 [ 0 ] = V_9 ? - 1 : 1 ;
return V_9 ;
}
static void F_40 ( struct V_1 * V_2 , struct V_109 * V_110 )
{
F_41 ( & V_2 -> V_55 , V_110 ) ;
}
