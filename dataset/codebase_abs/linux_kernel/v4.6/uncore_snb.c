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
if ( V_2 -> V_13 -> V_14 == 0 )
F_2 ( V_15 , 0 ) ;
}
void F_6 ( void )
{
V_18 = V_19 ;
if ( V_20 . V_21 > V_22 . V_23 )
V_20 . V_21 = V_22 . V_23 ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_24 * V_25 = V_2 -> V_24 ;
int V_26 = V_27 ;
T_1 V_28 ;
T_2 V_29 ;
F_8 ( V_25 , V_26 , & V_29 ) ;
V_28 = V_29 ;
#ifdef F_9
F_8 ( V_25 , V_26 + 4 , & V_29 ) ;
V_28 |= ( ( T_1 ) V_29 << 32 ) ;
#endif
V_28 &= ~ ( V_30 - 1 ) ;
V_2 -> V_31 = F_10 ( V_28 , V_32 ) ;
V_2 -> V_33 = V_34 ;
}
static void F_11 ( struct V_1 * V_2 )
{
F_12 ( V_2 -> V_31 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{}
static void F_14 ( struct V_1 * V_2 )
{}
static void F_15 ( struct V_1 * V_2 , struct V_3 * V_4 )
{}
static void F_16 ( struct V_1 * V_2 , struct V_3 * V_4 )
{}
static T_3 F_17 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = & V_4 -> V_7 ;
return ( T_3 ) * ( unsigned int * ) ( V_2 -> V_31 + V_6 -> V_35 ) ;
}
static int F_18 ( struct V_3 * V_4 )
{
struct V_36 * V_13 ;
struct V_1 * V_2 ;
struct V_5 * V_6 = & V_4 -> V_7 ;
T_3 V_37 = V_4 -> V_38 . V_11 & V_39 ;
int V_8 , V_40 ;
if ( V_4 -> V_38 . type != V_4 -> V_13 -> type )
return - V_41 ;
V_13 = F_19 ( V_4 ) ;
if ( V_13 -> V_42 < 0 )
return - V_41 ;
if ( V_6 -> V_43 )
return - V_44 ;
if ( V_4 -> V_38 . V_45 ||
V_4 -> V_38 . V_46 ||
V_4 -> V_38 . V_47 ||
V_4 -> V_38 . V_48 ||
V_4 -> V_38 . V_49 ||
V_4 -> V_38 . V_50 ||
V_4 -> V_38 . V_43 )
return - V_44 ;
if ( V_4 -> V_51 < 0 )
return - V_44 ;
if ( V_4 -> V_38 . V_11 & ~ V_39 )
return - V_44 ;
V_2 = F_20 ( V_13 , V_4 -> V_51 ) ;
if ( ! V_2 || V_2 -> V_51 < 0 )
return - V_44 ;
V_4 -> V_51 = V_2 -> V_51 ;
V_4 -> V_52 = V_2 ;
V_4 -> V_7 . V_8 = - 1 ;
V_4 -> V_7 . V_53 = ~ 0ULL ;
V_4 -> V_7 . V_54 . V_8 = V_55 ;
V_4 -> V_7 . V_56 . V_8 = V_55 ;
switch ( V_37 ) {
case V_57 :
V_40 = V_58 ;
V_8 = V_9 ;
break;
case V_59 :
V_40 = V_60 ;
V_8 = V_9 + 1 ;
break;
default:
return - V_44 ;
}
V_4 -> V_7 . V_35 = V_40 ;
V_4 -> V_7 . V_11 = V_37 ;
V_4 -> V_7 . V_8 = V_8 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
return 0 ;
}
static void F_22 ( struct V_3 * V_4 , int V_61 )
{
struct V_1 * V_2 = F_23 ( V_4 ) ;
T_3 V_62 ;
if ( F_24 ( ! ( V_4 -> V_7 . V_63 & V_64 ) ) )
return;
V_4 -> V_7 . V_63 = 0 ;
V_2 -> V_65 ++ ;
F_25 ( & V_4 -> V_66 , & V_2 -> V_67 ) ;
V_62 = F_17 ( V_2 , V_4 ) ;
F_26 ( & V_4 -> V_7 . V_68 , V_62 ) ;
if ( V_2 -> V_65 == 1 )
F_27 ( V_2 ) ;
}
static void F_28 ( struct V_3 * V_4 , int V_61 )
{
struct V_1 * V_2 = F_23 ( V_4 ) ;
struct V_5 * V_6 = & V_4 -> V_7 ;
if ( ! ( V_6 -> V_63 & V_64 ) ) {
V_2 -> V_65 -- ;
F_24 ( V_6 -> V_63 & V_64 ) ;
V_6 -> V_63 |= V_64 ;
F_29 ( & V_4 -> V_66 ) ;
if ( V_2 -> V_65 == 0 )
F_30 ( V_2 ) ;
}
if ( ( V_61 & V_69 ) && ! ( V_6 -> V_63 & V_70 ) ) {
F_31 ( V_2 , V_4 ) ;
V_6 -> V_63 |= V_70 ;
}
}
static int F_32 ( struct V_3 * V_4 , int V_61 )
{
struct V_1 * V_2 = F_23 ( V_4 ) ;
struct V_5 * V_6 = & V_4 -> V_7 ;
if ( ! V_2 )
return - V_71 ;
V_6 -> V_63 = V_70 | V_64 ;
if ( ! ( V_61 & V_72 ) )
V_6 -> V_63 |= V_73 ;
F_22 ( V_4 , 0 ) ;
V_2 -> V_74 ++ ;
return 0 ;
}
static void F_33 ( struct V_3 * V_4 , int V_61 )
{
struct V_1 * V_2 = F_23 ( V_4 ) ;
int V_75 ;
F_28 ( V_4 , V_69 ) ;
for ( V_75 = 0 ; V_75 < V_2 -> V_74 ; V_75 ++ ) {
if ( V_4 == V_2 -> V_76 [ V_75 ] ) {
-- V_2 -> V_74 ;
break;
}
}
}
int F_34 ( int V_77 )
{
struct V_24 * V_78 = NULL ;
struct V_79 * V_80 ;
int V_81 , V_82 ;
V_78 = F_35 ( V_83 , V_77 , V_78 ) ;
if ( ! V_78 )
return - V_84 ;
V_81 = V_78 -> V_81 -> V_85 ;
V_82 = F_36 ( V_78 -> V_81 ) ;
F_37 ( & V_86 ) ;
V_80 = F_38 ( V_82 ) ;
if ( ! V_80 ) {
F_39 ( & V_86 ) ;
F_40 ( V_78 ) ;
return - V_87 ;
}
V_80 -> V_88 [ V_81 ] = 0 ;
F_39 ( & V_86 ) ;
F_40 ( V_78 ) ;
return 0 ;
}
static struct V_89 * F_41 ( void )
{
const struct V_90 * V_91 ;
int V_92 ;
F_42 (p, desktop_imc_pci_ids) {
V_92 = F_34 ( V_91 -> V_93 ) ;
if ( V_92 == 0 )
return V_91 -> V_94 ;
}
return NULL ;
}
static int F_43 ( void )
{
struct V_89 * V_95 = F_41 () ;
if ( ! V_95 )
return - V_71 ;
V_96 = V_97 ;
V_98 = V_95 ;
return 0 ;
}
int F_44 ( void )
{
return F_43 () ;
}
int F_45 ( void )
{
return F_43 () ;
}
int F_46 ( void )
{
return F_43 () ;
}
int F_47 ( void )
{
return F_43 () ;
}
int F_48 ( void )
{
return F_43 () ;
}
static void F_49 ( struct V_1 * V_2 )
{
F_2 ( V_99 , 0 ) ;
}
static void F_50 ( struct V_1 * V_2 )
{
F_2 ( V_99 , V_100 | V_101 ) ;
}
static void F_51 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = & V_4 -> V_7 ;
if ( V_6 -> V_8 < V_9 )
F_2 ( V_6 -> V_10 , V_6 -> V_11 | V_12 ) ;
else
F_2 ( V_6 -> V_10 , V_102 ) ;
}
void F_52 ( void )
{
V_18 = V_103 ;
}
