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
void F_5 ( void )
{
V_18 = V_19 ;
if ( V_20 . V_21 > V_22 . V_23 )
V_20 . V_21 = V_22 . V_23 ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_24 * V_25 = V_2 -> V_24 ;
int V_26 = V_27 ;
T_1 V_28 ;
T_2 V_29 ;
F_7 ( V_25 , V_26 , & V_29 ) ;
V_28 = V_29 ;
#ifdef F_8
F_7 ( V_25 , V_26 + 4 , & V_29 ) ;
V_28 |= ( ( T_1 ) V_29 << 32 ) ;
#endif
V_28 &= ~ ( V_30 - 1 ) ;
V_2 -> V_31 = F_9 ( V_28 , V_32 ) ;
V_2 -> V_33 = V_34 ;
}
static void F_10 ( struct V_1 * V_2 )
{}
static void F_11 ( struct V_1 * V_2 )
{}
static void F_12 ( struct V_1 * V_2 , struct V_3 * V_4 )
{}
static void F_13 ( struct V_1 * V_2 , struct V_3 * V_4 )
{}
static T_3 F_14 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = & V_4 -> V_7 ;
return ( T_3 ) * ( unsigned int * ) ( V_2 -> V_31 + V_6 -> V_35 ) ;
}
static int F_15 ( struct V_3 * V_4 )
{
struct V_36 * V_13 ;
struct V_1 * V_2 ;
struct V_5 * V_6 = & V_4 -> V_7 ;
T_3 V_37 = V_4 -> V_38 . V_11 & V_39 ;
int V_8 , V_40 ;
if ( V_4 -> V_38 . type != V_4 -> V_13 -> type )
return - V_41 ;
V_13 = F_16 ( V_4 ) ;
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
V_2 = F_17 ( V_13 , V_4 -> V_51 ) ;
if ( ! V_2 || V_2 -> V_51 < 0 )
return - V_44 ;
V_4 -> V_51 = V_2 -> V_51 ;
V_4 -> V_7 . V_8 = - 1 ;
V_4 -> V_7 . V_52 = ~ 0ULL ;
V_4 -> V_7 . V_53 . V_8 = V_54 ;
V_4 -> V_7 . V_55 . V_8 = V_54 ;
switch ( V_37 ) {
case V_56 :
V_40 = V_57 ;
V_8 = V_9 ;
break;
case V_58 :
V_40 = V_59 ;
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
static int F_18 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
return 0 ;
}
static void F_19 ( struct V_3 * V_4 , int V_60 )
{
struct V_1 * V_2 = F_20 ( V_4 ) ;
T_3 V_61 ;
if ( F_21 ( ! ( V_4 -> V_7 . V_62 & V_63 ) ) )
return;
V_4 -> V_7 . V_62 = 0 ;
V_2 -> V_64 ++ ;
F_22 ( & V_4 -> V_65 , & V_2 -> V_66 ) ;
V_61 = F_14 ( V_2 , V_4 ) ;
F_23 ( & V_4 -> V_7 . V_67 , V_61 ) ;
if ( V_2 -> V_64 == 1 )
F_24 ( V_2 ) ;
}
static void F_25 ( struct V_3 * V_4 , int V_60 )
{
struct V_1 * V_2 = F_20 ( V_4 ) ;
struct V_5 * V_6 = & V_4 -> V_7 ;
if ( ! ( V_6 -> V_62 & V_63 ) ) {
V_2 -> V_64 -- ;
F_21 ( V_6 -> V_62 & V_63 ) ;
V_6 -> V_62 |= V_63 ;
F_26 ( & V_4 -> V_65 ) ;
if ( V_2 -> V_64 == 0 )
F_27 ( V_2 ) ;
}
if ( ( V_60 & V_68 ) && ! ( V_6 -> V_62 & V_69 ) ) {
F_28 ( V_2 , V_4 ) ;
V_6 -> V_62 |= V_69 ;
}
}
static int F_29 ( struct V_3 * V_4 , int V_60 )
{
struct V_1 * V_2 = F_20 ( V_4 ) ;
struct V_5 * V_6 = & V_4 -> V_7 ;
if ( ! V_2 )
return - V_70 ;
V_6 -> V_62 = V_69 | V_63 ;
if ( ! ( V_60 & V_71 ) )
V_6 -> V_62 |= V_72 ;
F_19 ( V_4 , 0 ) ;
V_2 -> V_73 ++ ;
return 0 ;
}
static void F_30 ( struct V_3 * V_4 , int V_60 )
{
struct V_1 * V_2 = F_20 ( V_4 ) ;
int V_74 ;
F_25 ( V_4 , V_68 ) ;
for ( V_74 = 0 ; V_74 < V_2 -> V_73 ; V_74 ++ ) {
if ( V_4 == V_2 -> V_75 [ V_74 ] ) {
-- V_2 -> V_73 ;
break;
}
}
}
static int F_31 ( int V_76 )
{
struct V_24 * V_77 = NULL ;
int V_78 ;
V_77 = F_32 ( V_79 , V_76 , V_77 ) ;
if ( ! V_77 )
return - V_80 ;
V_78 = V_77 -> V_78 -> V_81 ;
V_82 [ V_78 ] = 0 ;
F_33 ( V_77 ) ;
return 0 ;
}
static struct V_83 * F_34 ( void )
{
const struct V_84 * V_85 ;
int V_86 ;
F_35 (p, desktop_imc_pci_ids) {
V_86 = F_31 ( V_85 -> V_87 ) ;
if ( V_86 == 0 )
return V_85 -> V_88 ;
}
return NULL ;
}
static int F_36 ( void )
{
struct V_83 * V_89 = F_34 () ;
if ( ! V_89 )
return - V_70 ;
V_90 = V_91 ;
V_92 = V_89 ;
return 0 ;
}
int F_37 ( void )
{
return F_36 () ;
}
int F_38 ( void )
{
return F_36 () ;
}
int F_39 ( void )
{
return F_36 () ;
}
static void F_40 ( struct V_1 * V_2 )
{
F_2 ( V_93 , 0 ) ;
}
static void F_41 ( struct V_1 * V_2 )
{
F_2 ( V_93 , V_94 | V_95 ) ;
}
static void F_42 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = & V_4 -> V_7 ;
if ( V_6 -> V_8 < V_9 )
F_2 ( V_6 -> V_10 , V_6 -> V_11 | V_12 ) ;
else
F_2 ( V_6 -> V_10 , V_96 ) ;
}
void F_43 ( void )
{
V_18 = V_97 ;
}
