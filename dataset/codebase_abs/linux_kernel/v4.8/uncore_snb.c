static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = & V_4 -> V_7 ;
if ( V_6 -> V_8 < V_9 )
F_2 ( V_6 -> V_10 , V_6 -> V_11 | V_12 ) ;
else
F_2 ( V_6 -> V_10 , V_12 ) ;
}
static void F_3 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_2 ( V_4 -> V_7 . V_10 , 0 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
if ( V_2 -> V_13 -> V_14 == 0 ) {
F_2 ( V_15 ,
V_16 | V_17 ) ;
}
}
static void F_5 ( struct V_1 * V_2 )
{
F_2 ( V_15 ,
V_16 | V_17 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
if ( V_2 -> V_13 -> V_14 == 0 )
F_2 ( V_15 , 0 ) ;
}
void F_7 ( void )
{
V_18 = V_19 ;
if ( V_20 . V_21 > V_22 . V_23 )
V_20 . V_21 = V_22 . V_23 ;
}
static void F_8 ( struct V_1 * V_2 )
{
if ( V_2 -> V_13 -> V_14 == 0 ) {
F_2 ( V_24 ,
V_16 | V_25 ) ;
}
}
static void F_9 ( struct V_1 * V_2 )
{
F_2 ( V_24 ,
V_16 | V_25 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
if ( V_2 -> V_13 -> V_14 == 0 )
F_2 ( V_24 , 0 ) ;
}
void F_11 ( void )
{
V_18 = V_26 ;
if ( V_27 . V_21 > V_22 . V_23 )
V_27 . V_21 = V_22 . V_23 ;
V_28 . V_29 = & V_30 ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_31 * V_32 = V_2 -> V_31 ;
int V_33 = V_34 ;
T_1 V_35 ;
T_2 V_36 ;
F_13 ( V_32 , V_33 , & V_36 ) ;
V_35 = V_36 ;
#ifdef F_14
F_13 ( V_32 , V_33 + 4 , & V_36 ) ;
V_35 |= ( ( T_1 ) V_36 << 32 ) ;
#endif
V_35 &= ~ ( V_37 - 1 ) ;
V_2 -> V_38 = F_15 ( V_35 , V_39 ) ;
V_2 -> V_40 = V_41 ;
}
static void F_16 ( struct V_1 * V_2 )
{
F_17 ( V_2 -> V_38 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{}
static void F_19 ( struct V_1 * V_2 )
{}
static void F_20 ( struct V_1 * V_2 , struct V_3 * V_4 )
{}
static void F_21 ( struct V_1 * V_2 , struct V_3 * V_4 )
{}
static T_3 F_22 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = & V_4 -> V_7 ;
return ( T_3 ) * ( unsigned int * ) ( V_2 -> V_38 + V_6 -> V_42 ) ;
}
static int F_23 ( struct V_3 * V_4 )
{
struct V_43 * V_13 ;
struct V_1 * V_2 ;
struct V_5 * V_6 = & V_4 -> V_7 ;
T_3 V_44 = V_4 -> V_45 . V_11 & V_46 ;
int V_8 , V_47 ;
if ( V_4 -> V_45 . type != V_4 -> V_13 -> type )
return - V_48 ;
V_13 = F_24 ( V_4 ) ;
if ( V_13 -> V_49 < 0 )
return - V_48 ;
if ( V_6 -> V_50 )
return - V_51 ;
if ( V_4 -> V_45 . V_52 ||
V_4 -> V_45 . V_53 ||
V_4 -> V_45 . V_54 ||
V_4 -> V_45 . V_55 ||
V_4 -> V_45 . V_56 ||
V_4 -> V_45 . V_57 ||
V_4 -> V_45 . V_50 )
return - V_51 ;
if ( V_4 -> V_58 < 0 )
return - V_51 ;
if ( V_4 -> V_45 . V_11 & ~ V_46 )
return - V_51 ;
V_2 = F_25 ( V_13 , V_4 -> V_58 ) ;
if ( ! V_2 || V_2 -> V_58 < 0 )
return - V_51 ;
V_4 -> V_58 = V_2 -> V_58 ;
V_4 -> V_59 = V_2 ;
V_4 -> V_7 . V_8 = - 1 ;
V_4 -> V_7 . V_60 = ~ 0ULL ;
V_4 -> V_7 . V_61 . V_8 = V_62 ;
V_4 -> V_7 . V_63 . V_8 = V_62 ;
switch ( V_44 ) {
case V_64 :
V_47 = V_65 ;
V_8 = V_9 ;
break;
case V_66 :
V_47 = V_67 ;
V_8 = V_9 + 1 ;
break;
default:
return - V_51 ;
}
V_4 -> V_7 . V_42 = V_47 ;
V_4 -> V_7 . V_11 = V_44 ;
V_4 -> V_7 . V_8 = V_8 ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
return 0 ;
}
static void F_27 ( struct V_3 * V_4 , int V_68 )
{
struct V_1 * V_2 = F_28 ( V_4 ) ;
T_3 V_69 ;
if ( F_29 ( ! ( V_4 -> V_7 . V_70 & V_71 ) ) )
return;
V_4 -> V_7 . V_70 = 0 ;
V_2 -> V_72 ++ ;
F_30 ( & V_4 -> V_73 , & V_2 -> V_74 ) ;
V_69 = F_22 ( V_2 , V_4 ) ;
F_31 ( & V_4 -> V_7 . V_75 , V_69 ) ;
if ( V_2 -> V_72 == 1 )
F_32 ( V_2 ) ;
}
static void F_33 ( struct V_3 * V_4 , int V_68 )
{
struct V_1 * V_2 = F_28 ( V_4 ) ;
struct V_5 * V_6 = & V_4 -> V_7 ;
if ( ! ( V_6 -> V_70 & V_71 ) ) {
V_2 -> V_72 -- ;
F_29 ( V_6 -> V_70 & V_71 ) ;
V_6 -> V_70 |= V_71 ;
F_34 ( & V_4 -> V_73 ) ;
if ( V_2 -> V_72 == 0 )
F_35 ( V_2 ) ;
}
if ( ( V_68 & V_76 ) && ! ( V_6 -> V_70 & V_77 ) ) {
F_36 ( V_2 , V_4 ) ;
V_6 -> V_70 |= V_77 ;
}
}
static int F_37 ( struct V_3 * V_4 , int V_68 )
{
struct V_1 * V_2 = F_28 ( V_4 ) ;
struct V_5 * V_6 = & V_4 -> V_7 ;
if ( ! V_2 )
return - V_78 ;
V_6 -> V_70 = V_77 | V_71 ;
if ( ! ( V_68 & V_79 ) )
V_6 -> V_70 |= V_80 ;
F_27 ( V_4 , 0 ) ;
V_2 -> V_81 ++ ;
return 0 ;
}
static void F_38 ( struct V_3 * V_4 , int V_68 )
{
struct V_1 * V_2 = F_28 ( V_4 ) ;
int V_82 ;
F_33 ( V_4 , V_76 ) ;
for ( V_82 = 0 ; V_82 < V_2 -> V_81 ; V_82 ++ ) {
if ( V_4 == V_2 -> V_83 [ V_82 ] ) {
-- V_2 -> V_81 ;
break;
}
}
}
int F_39 ( int V_84 )
{
struct V_31 * V_85 = NULL ;
struct V_86 * V_87 ;
int V_88 , V_89 ;
V_85 = F_40 ( V_90 , V_84 , V_85 ) ;
if ( ! V_85 )
return - V_91 ;
V_88 = V_85 -> V_88 -> V_92 ;
V_89 = F_41 ( V_85 -> V_88 ) ;
F_42 ( & V_93 ) ;
V_87 = F_43 ( V_89 ) ;
if ( ! V_87 ) {
F_44 ( & V_93 ) ;
F_45 ( V_85 ) ;
return - V_94 ;
}
V_87 -> V_95 [ V_88 ] = 0 ;
F_44 ( & V_93 ) ;
F_45 ( V_85 ) ;
return 0 ;
}
static struct V_96 * F_46 ( void )
{
const struct V_97 * V_98 ;
int V_99 ;
F_47 (p, desktop_imc_pci_ids) {
V_99 = F_39 ( V_98 -> V_100 ) ;
if ( V_99 == 0 )
return V_98 -> V_101 ;
}
return NULL ;
}
static int F_48 ( void )
{
struct V_96 * V_102 = F_46 () ;
if ( ! V_102 )
return - V_78 ;
V_103 = V_104 ;
V_105 = V_102 ;
return 0 ;
}
int F_49 ( void )
{
return F_48 () ;
}
int F_50 ( void )
{
return F_48 () ;
}
int F_51 ( void )
{
return F_48 () ;
}
int F_52 ( void )
{
return F_48 () ;
}
int F_53 ( void )
{
return F_48 () ;
}
static void F_54 ( struct V_1 * V_2 )
{
F_2 ( V_106 , 0 ) ;
}
static void F_55 ( struct V_1 * V_2 )
{
F_2 ( V_106 , V_107 | V_108 ) ;
}
static void F_56 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = & V_4 -> V_7 ;
if ( V_6 -> V_8 < V_9 )
F_2 ( V_6 -> V_10 , V_6 -> V_11 | V_12 ) ;
else
F_2 ( V_6 -> V_10 , V_109 ) ;
}
void F_57 ( void )
{
V_18 = V_110 ;
}
