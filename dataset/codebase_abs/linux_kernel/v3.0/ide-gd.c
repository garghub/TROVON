static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = NULL ;
F_2 ( & V_5 ) ;
V_4 = F_3 ( V_3 , V_1 ) ;
if ( V_4 ) {
if ( F_4 ( V_4 -> V_6 ) )
V_4 = NULL ;
else
F_5 ( & V_4 -> V_7 ) ;
}
F_6 ( & V_5 ) ;
return V_4 ;
}
static void F_7 ( struct V_1 * V_4 )
{
T_1 * V_6 = V_4 -> V_6 ;
F_2 ( & V_5 ) ;
F_8 ( & V_4 -> V_7 ) ;
F_9 ( V_6 ) ;
F_6 ( & V_5 ) ;
}
T_2 F_10 ( T_1 * V_6 )
{
return V_6 -> V_8 ;
}
static void F_11 ( T_1 * V_6 )
{
struct V_1 * V_4 = V_6 -> V_9 ;
struct V_2 * V_10 = V_4 -> V_3 ;
F_12 ( V_6 , V_4 -> V_11 ) ;
F_13 ( & V_4 -> V_7 ) ;
F_14 ( V_10 ) ;
V_6 -> V_12 -> V_13 ( V_6 ) ;
F_2 ( & V_5 ) ;
F_8 ( & V_4 -> V_7 ) ;
F_6 ( & V_5 ) ;
}
static void F_15 ( struct V_14 * V_7 )
{
struct V_1 * V_4 = F_16 ( V_7 , V_1 ) ;
T_1 * V_6 = V_4 -> V_6 ;
struct V_2 * V_10 = V_4 -> V_3 ;
V_6 -> V_12 = NULL ;
V_6 -> V_9 = NULL ;
V_10 -> V_15 = NULL ;
F_17 ( V_10 ) ;
F_18 ( V_4 ) ;
}
static void F_19 ( T_1 * V_6 )
{
if ( F_20 ( V_6 -> V_16 ) )
( void ) V_6 -> V_12 -> V_17 ( V_6 ) ;
}
static T_3 * F_21 ( T_1 * V_6 )
{
return ( V_6 -> V_18 == V_19 ) ? V_20 : V_21 ;
}
static const struct V_22 * F_22 ( T_1 * V_6 )
{
return ( V_6 -> V_18 == V_19 ) ? V_23
: V_24 ;
}
static T_4 F_23 ( T_1 * V_6 ,
struct V_25 * V_26 , T_2 V_27 )
{
return V_6 -> V_12 -> V_28 ( V_6 , V_26 , V_27 ) ;
}
static int F_24 ( struct V_29 * V_30 , T_5 V_31 )
{
struct V_2 * V_3 = V_30 -> V_32 ;
struct V_1 * V_4 ;
T_1 * V_6 ;
int V_33 = 0 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_34 ;
V_6 = V_4 -> V_6 ;
F_25 ( V_35 , L_1 ) ;
V_4 -> V_36 ++ ;
if ( ( V_6 -> V_37 & V_38 ) && V_4 -> V_36 == 1 ) {
V_6 -> V_37 &= ~ V_39 ;
V_33 = V_6 -> V_12 -> V_40 ( V_6 , V_3 ) ;
if ( V_33 && ( V_31 & V_41 ) == 0 ) {
V_33 = - V_42 ;
goto V_43;
}
if ( ( V_6 -> V_37 & V_44 ) && ( V_31 & V_45 ) ) {
V_33 = - V_46 ;
goto V_43;
}
V_6 -> V_12 -> V_47 ( V_6 , V_3 , 1 ) ;
V_6 -> V_37 |= V_48 ;
F_26 ( V_30 ) ;
} else if ( V_6 -> V_37 & V_39 ) {
V_33 = - V_49 ;
goto V_43;
}
return 0 ;
V_43:
V_4 -> V_36 -- ;
F_7 ( V_4 ) ;
return V_33 ;
}
static int F_27 ( struct V_29 * V_30 , T_5 V_31 )
{
int V_33 ;
F_2 ( & V_50 ) ;
V_33 = F_24 ( V_30 , V_31 ) ;
F_6 ( & V_50 ) ;
return V_33 ;
}
static int F_28 ( struct V_2 * V_3 , T_5 V_31 )
{
struct V_1 * V_4 = F_3 ( V_3 , V_1 ) ;
T_1 * V_6 = V_4 -> V_6 ;
F_25 ( V_35 , L_1 ) ;
F_2 ( & V_50 ) ;
if ( V_4 -> V_36 == 1 )
V_6 -> V_12 -> V_13 ( V_6 ) ;
if ( ( V_6 -> V_37 & V_38 ) && V_4 -> V_36 == 1 ) {
V_6 -> V_12 -> V_47 ( V_6 , V_3 , 0 ) ;
V_6 -> V_37 &= ~ V_39 ;
}
V_4 -> V_36 -- ;
F_7 ( V_4 ) ;
F_6 ( & V_50 ) ;
return 0 ;
}
static int F_29 ( struct V_29 * V_30 , struct V_51 * V_52 )
{
struct V_1 * V_4 = F_3 ( V_30 -> V_32 , V_1 ) ;
T_1 * V_6 = V_4 -> V_6 ;
V_52 -> V_53 = V_6 -> V_54 ;
V_52 -> V_55 = V_6 -> V_56 ;
V_52 -> V_57 = ( V_58 ) V_6 -> V_59 ;
return 0 ;
}
static unsigned int F_30 ( struct V_2 * V_3 ,
unsigned int V_60 )
{
struct V_1 * V_4 = F_3 ( V_3 , V_1 ) ;
T_1 * V_6 = V_4 -> V_6 ;
bool V_33 ;
if ( V_6 -> V_37 & V_61 ) {
V_6 -> V_37 &= ~ V_61 ;
return 0 ;
}
V_33 = V_6 -> V_37 & V_48 ;
V_6 -> V_37 &= ~ V_48 ;
return V_33 ? V_62 : 0 ;
}
static void F_31 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_3 ( V_3 , V_1 ) ;
T_1 * V_6 = V_4 -> V_6 ;
const struct V_63 * V_12 = V_6 -> V_12 ;
if ( V_12 -> V_64 )
V_12 -> V_64 ( V_6 ) ;
}
static int F_32 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_3 ( V_3 , V_1 ) ;
T_1 * V_6 = V_4 -> V_6 ;
if ( F_30 ( V_3 , 0 ) )
V_6 -> V_12 -> V_17 ( V_6 ) ;
F_33 ( V_3 , F_10 ( V_6 ) ) ;
return 0 ;
}
static int F_34 ( struct V_29 * V_30 , T_5 V_31 ,
unsigned int V_65 , unsigned long V_66 )
{
struct V_1 * V_4 = F_3 ( V_30 -> V_32 , V_1 ) ;
T_1 * V_6 = V_4 -> V_6 ;
return V_6 -> V_12 -> V_67 ( V_6 , V_30 , V_31 , V_65 , V_66 ) ;
}
static int F_35 ( T_1 * V_6 )
{
const struct V_63 * V_12 = NULL ;
struct V_1 * V_4 ;
struct V_2 * V_10 ;
if ( ! strstr ( L_2 , V_6 -> V_68 ) )
goto V_69;
#ifdef F_36
if ( V_6 -> V_18 == V_19 )
V_12 = & V_70 ;
#endif
#ifdef F_37
if ( V_6 -> V_18 == V_71 )
V_12 = & V_72 ;
#endif
if ( V_12 == NULL )
goto V_69;
if ( V_12 -> V_73 ( V_6 , V_74 ) == 0 ) {
F_38 (KERN_ERR PFX L_3 ,
drive->name) ;
goto V_69;
}
V_4 = F_39 ( sizeof( * V_4 ) , V_75 ) ;
if ( ! V_4 ) {
F_38 (KERN_ERR PFX L_4 ,
drive->name) ;
goto V_69;
}
V_10 = F_40 ( V_76 , F_41 ( V_6 -> V_77 ) ) ;
if ( ! V_10 )
goto V_78;
F_42 ( V_10 , V_6 ) ;
V_4 -> V_7 . V_79 = & V_6 -> V_80 ;
V_4 -> V_7 . V_81 = F_15 ;
F_43 ( & V_4 -> V_7 , F_44 ( & V_6 -> V_80 ) ) ;
if ( F_45 ( & V_4 -> V_7 ) )
goto V_82;
V_4 -> V_6 = V_6 ;
V_4 -> V_11 = & V_83 ;
V_4 -> V_3 = V_10 ;
V_10 -> V_15 = & V_4 -> V_11 ;
V_6 -> V_9 = V_4 ;
V_6 -> V_84 = V_84 ;
V_6 -> V_12 = V_12 ;
V_12 -> V_85 ( V_6 ) ;
F_33 ( V_10 , F_10 ( V_6 ) ) ;
V_10 -> V_86 = V_76 ;
V_10 -> V_87 = & V_6 -> V_80 ;
V_10 -> V_88 |= V_89 ;
if ( V_6 -> V_37 & V_38 )
V_10 -> V_88 = V_90 ;
V_10 -> V_91 = & V_92 ;
F_46 ( V_10 ) ;
return 0 ;
V_82:
F_17 ( V_10 ) ;
V_78:
F_18 ( V_4 ) ;
V_69:
return - V_93 ;
}
static int T_6 F_47 ( void )
{
F_38 (KERN_INFO DRV_NAME L_5 IDE_GD_VERSION L_6 ) ;
return F_48 ( & V_83 . V_94 ) ;
}
static void T_7 F_49 ( void )
{
F_50 ( & V_83 . V_94 ) ;
}
