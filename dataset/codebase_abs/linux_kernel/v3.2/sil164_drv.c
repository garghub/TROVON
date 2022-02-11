static void
F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
T_1 V_5 [] = { V_3 , V_4 } ;
int V_6 ;
V_6 = F_2 ( V_2 , V_5 , F_3 ( V_5 ) ) ;
if ( V_6 < 0 )
F_4 ( V_2 , L_1 ,
V_6 , V_3 ) ;
}
static T_1
F_5 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_4 ;
int V_6 ;
V_6 = F_2 ( V_2 , & V_3 , sizeof( V_3 ) ) ;
if ( V_6 < 0 )
goto V_7;
V_6 = F_6 ( V_2 , & V_4 , sizeof( V_4 ) ) ;
if ( V_6 < 0 )
goto V_7;
return V_4 ;
V_7:
F_4 ( V_2 , L_2 ,
V_6 , V_3 ) ;
return 0 ;
}
static void
F_7 ( struct V_1 * V_2 , T_1 * V_8 )
{
int V_9 ;
for ( V_9 = 0x8 ; V_9 <= 0xe ; V_9 ++ )
V_8 [ V_9 ] = F_5 ( V_2 , V_9 ) ;
}
static void
F_8 ( struct V_1 * V_2 , T_1 * V_8 )
{
int V_9 ;
for ( V_9 = 0x8 ; V_9 <= 0xe ; V_9 ++ )
F_1 ( V_2 , V_9 , V_8 [ V_9 ] ) ;
}
static void
F_9 ( struct V_1 * V_2 , bool V_10 )
{
T_1 V_11 = F_5 ( V_2 , V_12 ) ;
if ( V_10 )
V_11 |= V_13 ;
else
V_11 &= ~ V_13 ;
F_1 ( V_2 , V_12 , V_11 ) ;
}
static void
F_10 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
bool V_16 )
{
F_1 ( V_2 , V_12 ,
V_17 |
V_18 |
( V_15 -> V_19 ? V_20 : 0 ) |
( V_15 -> V_21 ? V_22 : 0 ) |
( V_15 -> V_23 ? V_24 : 0 ) ) ;
F_1 ( V_2 , V_25 ,
V_26 |
V_27 ) ;
F_1 ( V_2 , V_28 ,
( V_15 -> V_29 ? V_30 : 0 ) |
( ( ( V_15 -> V_29 + 4 ) & 0x7 )
<< V_31 ) ) ;
F_1 ( V_2 , V_32 ,
V_33 |
( V_15 -> V_34 ? 0 : V_35 ) |
( 4 << V_36 ) ) ;
F_1 ( V_2 , V_37 , 0 ) ;
if ( V_16 )
F_1 ( V_2 , V_38 ,
V_39 |
( ( ( V_15 -> V_40 + 4 ) & 0x7 )
<< V_41 ) ) ;
else
F_1 ( V_2 , V_38 , 0 ) ;
}
static void
F_11 ( struct V_42 * V_43 , void * V_44 )
{
struct V_45 * V_46 = F_12 ( V_43 ) ;
V_46 -> V_15 = * (struct V_14 * ) V_44 ;
}
static void
F_13 ( struct V_42 * V_43 , int V_47 )
{
struct V_45 * V_46 = F_12 ( V_43 ) ;
bool V_10 = ( V_47 == V_48 ) ;
bool V_16 = ( V_10 && V_43 -> V_49 -> V_47 . clock > 165000 ) ;
F_9 ( F_14 ( V_43 ) , V_10 ) ;
if ( V_46 -> V_50 )
F_9 ( V_46 -> V_50 , V_16 ) ;
}
static void
F_15 ( struct V_42 * V_43 )
{
struct V_45 * V_46 = F_12 ( V_43 ) ;
F_7 ( F_14 ( V_43 ) ,
V_46 -> V_51 ) ;
if ( V_46 -> V_50 )
F_7 ( V_46 -> V_50 ,
V_46 -> V_52 ) ;
}
static void
F_16 ( struct V_42 * V_43 )
{
struct V_45 * V_46 = F_12 ( V_43 ) ;
F_8 ( F_14 ( V_43 ) ,
V_46 -> V_51 ) ;
if ( V_46 -> V_50 )
F_8 ( V_46 -> V_50 ,
V_46 -> V_52 ) ;
}
static bool
F_17 ( struct V_42 * V_43 ,
struct V_53 * V_47 ,
struct V_53 * V_54 )
{
return true ;
}
static int
F_18 ( struct V_42 * V_43 ,
struct V_53 * V_47 )
{
struct V_45 * V_46 = F_12 ( V_43 ) ;
if ( V_47 -> clock < 32000 )
return V_55 ;
if ( V_47 -> clock > 330000 ||
( V_47 -> clock > 165000 && ! V_46 -> V_50 ) )
return V_56 ;
return V_57 ;
}
static void
F_19 ( struct V_42 * V_43 ,
struct V_53 * V_47 ,
struct V_53 * V_54 )
{
struct V_45 * V_46 = F_12 ( V_43 ) ;
bool V_16 = V_54 -> clock > 165000 ;
F_10 ( F_14 ( V_43 ) ,
& V_46 -> V_15 , V_16 ) ;
if ( V_46 -> V_50 )
F_10 ( V_46 -> V_50 ,
& V_46 -> V_15 , V_16 ) ;
F_13 ( V_43 , V_48 ) ;
}
static enum V_58
F_20 ( struct V_42 * V_43 ,
struct V_59 * V_60 )
{
struct V_1 * V_2 = F_14 ( V_43 ) ;
if ( F_5 ( V_2 , V_25 ) & V_61 )
return V_62 ;
else
return V_63 ;
}
static int
F_21 ( struct V_42 * V_43 ,
struct V_59 * V_60 )
{
return 0 ;
}
static int
F_22 ( struct V_42 * V_43 ,
struct V_59 * V_60 )
{
return 0 ;
}
static int
F_23 ( struct V_42 * V_43 ,
struct V_59 * V_60 ,
struct V_64 * V_65 ,
T_2 V_4 )
{
return 0 ;
}
static void
F_24 ( struct V_42 * V_43 )
{
struct V_45 * V_46 = F_12 ( V_43 ) ;
if ( V_46 -> V_50 )
F_25 ( V_46 -> V_50 ) ;
F_26 ( V_46 ) ;
F_27 ( V_43 ) ;
}
static int
F_28 ( struct V_1 * V_2 , const struct V_66 * V_67 )
{
int V_68 = F_5 ( V_2 , V_69 ) << 8 |
F_5 ( V_2 , V_70 ) ;
int V_71 = F_5 ( V_2 , V_72 ) << 8 |
F_5 ( V_2 , V_73 ) ;
int V_74 = F_5 ( V_2 , V_75 ) ;
if ( V_68 != 0x1 || V_71 != 0x6 ) {
F_29 ( V_2 , L_3 ,
V_68 , V_71 , V_74 ) ;
return - V_76 ;
}
F_30 ( V_2 , L_4 ,
V_68 , V_71 , V_74 ) ;
return 0 ;
}
static int
F_31 ( struct V_1 * V_2 )
{
return 0 ;
}
static struct V_1 *
F_32 ( struct V_1 * V_2 )
{
struct V_77 * V_78 = V_2 -> V_79 ;
struct V_80 V_81 = {
. V_3 = V_82 ,
. V_83 = 0 ,
} ;
const struct V_84 V_85 = {
F_33 ( L_5 , SIL164_I2C_ADDR_SLAVE)
} ;
if ( F_34 ( V_78 , & V_81 , 1 ) != 1 ) {
F_29 ( V_78 , L_6 ) ;
return NULL ;
}
return F_35 ( V_78 , & V_85 ) ;
}
static int
F_36 ( struct V_1 * V_2 ,
struct V_86 * V_87 ,
struct V_88 * V_43 )
{
struct V_45 * V_46 ;
V_46 = F_37 ( sizeof( * V_46 ) , V_89 ) ;
if ( ! V_46 )
return - V_90 ;
V_43 -> V_91 = V_46 ;
V_43 -> V_92 = & V_93 ;
V_46 -> V_50 = F_32 ( V_2 ) ;
return 0 ;
}
static int T_3
F_38 ( void )
{
return F_39 ( V_94 , & V_95 ) ;
}
static void T_4
F_40 ( void )
{
F_41 ( & V_95 ) ;
}
