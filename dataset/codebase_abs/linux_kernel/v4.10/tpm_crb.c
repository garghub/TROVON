static int T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( V_4 -> V_5 & V_6 )
return 0 ;
F_2 ( V_7 , & V_4 -> V_8 -> V_9 ) ;
return 0 ;
}
static int T_1 F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_2 V_10 , V_11 ;
if ( V_4 -> V_5 & V_6 )
return 0 ;
F_2 ( V_12 , & V_4 -> V_8 -> V_9 ) ;
V_11 = F_4 () ;
V_10 = F_5 ( V_11 , F_6 ( V_13 ) ) ;
do {
if ( ! ( F_7 ( & V_4 -> V_8 -> V_9 ) & V_12 ) )
return 0 ;
F_8 ( 50 , 100 ) ;
} while ( F_9 ( F_4 () , V_10 ) );
if ( F_7 ( & V_4 -> V_8 -> V_9 ) & V_12 ) {
F_10 ( V_2 , L_1 ) ;
return - V_14 ;
}
return 0 ;
}
static T_3 F_11 ( struct V_15 * V_16 )
{
struct V_3 * V_4 = F_12 ( & V_16 -> V_2 ) ;
T_3 V_17 = 0 ;
if ( ( F_7 ( & V_4 -> V_8 -> V_11 ) & V_18 ) !=
V_18 )
V_17 |= V_19 ;
return V_17 ;
}
static int F_13 ( struct V_15 * V_16 , T_3 * V_20 , T_4 V_21 )
{
struct V_3 * V_4 = F_12 ( & V_16 -> V_2 ) ;
unsigned int V_22 ;
if ( V_21 < 6 )
return - V_23 ;
if ( F_7 ( & V_4 -> V_8 -> V_17 ) & V_24 )
return - V_23 ;
F_14 ( V_20 , V_4 -> V_25 , 6 ) ;
V_22 = F_15 ( ( V_26 * ) & V_20 [ 2 ] ) ;
if ( V_22 > V_21 )
return - V_23 ;
F_14 ( & V_20 [ 6 ] , & V_4 -> V_25 [ 6 ] , V_22 - 6 ) ;
return V_22 ;
}
static int F_16 ( struct V_15 * V_16 )
{
union V_27 * V_28 ;
int V_29 ;
V_28 = F_17 ( V_16 -> V_30 ,
V_31 ,
V_32 ,
V_33 ,
NULL ) ;
if ( ! V_28 )
return - V_34 ;
V_29 = V_28 -> integer . V_35 == 0 ? 0 : - V_34 ;
F_18 ( V_28 ) ;
return V_29 ;
}
static int F_19 ( struct V_15 * V_16 , T_3 * V_20 , T_4 V_36 )
{
struct V_3 * V_4 = F_12 ( & V_16 -> V_2 ) ;
int V_29 = 0 ;
F_2 ( 0 , & V_4 -> V_8 -> V_37 ) ;
if ( V_36 > V_4 -> V_38 ) {
F_20 ( & V_16 -> V_2 , L_2 ,
V_36 , V_4 -> V_38 ) ;
return - V_39 ;
}
F_21 ( V_4 -> V_40 , V_20 , V_36 ) ;
F_22 () ;
if ( V_4 -> V_5 & V_41 )
F_2 ( V_18 , & V_4 -> V_8 -> V_11 ) ;
if ( V_4 -> V_5 & V_6 )
V_29 = F_16 ( V_16 ) ;
return V_29 ;
}
static void F_23 ( struct V_15 * V_16 )
{
struct V_3 * V_4 = F_12 ( & V_16 -> V_2 ) ;
F_2 ( V_42 , & V_4 -> V_8 -> V_37 ) ;
if ( ( V_4 -> V_5 & V_6 ) && F_16 ( V_16 ) )
F_20 ( & V_16 -> V_2 , L_3 ) ;
}
static bool F_24 ( struct V_15 * V_16 , T_3 V_43 )
{
struct V_3 * V_4 = F_12 ( & V_16 -> V_2 ) ;
T_5 V_37 = F_7 ( & V_4 -> V_8 -> V_37 ) ;
return ( V_37 & V_42 ) == V_42 ;
}
static int F_25 ( struct V_44 * V_45 , void * V_46 )
{
struct V_47 * V_48 = V_46 ;
struct V_47 V_49 ;
if ( F_26 ( V_45 , & V_49 ) ) {
* V_48 = V_49 ;
V_48 -> V_50 = NULL ;
}
return 1 ;
}
static void T_6 * F_27 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_47 * V_48 , T_7 V_11 , T_5 V_51 )
{
struct V_47 V_52 = {
. V_11 = V_11 ,
. V_53 = V_11 + V_51 - 1 ,
. V_5 = V_54 ,
} ;
if ( V_11 != V_52 . V_11 )
return ( void T_6 * ) F_28 ( - V_55 ) ;
if ( ! F_29 ( V_48 , & V_52 ) )
return F_30 ( V_2 , & V_52 ) ;
return V_4 -> V_56 + ( V_52 . V_11 - V_48 -> V_11 ) ;
}
static int F_31 ( struct V_57 * V_1 , struct V_3 * V_4 ,
struct V_58 * V_20 )
{
struct V_59 V_60 ;
struct V_47 V_48 ;
struct V_1 * V_2 = & V_1 -> V_2 ;
T_5 V_61 , V_62 ;
T_7 V_63 ;
T_5 V_38 ;
T_7 V_64 ;
T_5 V_65 ;
int V_66 ;
F_32 ( & V_60 ) ;
V_66 = F_33 ( V_1 , & V_60 , F_25 ,
& V_48 ) ;
if ( V_66 < 0 )
return V_66 ;
F_34 ( & V_60 ) ;
if ( F_35 ( & V_48 ) != V_54 ) {
F_20 ( V_2 , V_67 L_4 ) ;
return - V_55 ;
}
V_4 -> V_56 = F_30 ( V_2 , & V_48 ) ;
if ( F_36 ( V_4 -> V_56 ) )
return F_37 ( V_4 -> V_56 ) ;
V_4 -> V_8 = F_27 ( V_2 , V_4 , & V_48 , V_20 -> V_68 ,
sizeof( struct V_69 ) ) ;
if ( F_36 ( V_4 -> V_8 ) )
return F_37 ( V_4 -> V_8 ) ;
V_66 = F_3 ( V_2 , V_4 ) ;
if ( V_66 )
return V_66 ;
V_61 = F_7 ( & V_4 -> V_8 -> V_70 ) ;
V_62 = F_7 ( & V_4 -> V_8 -> V_71 ) ;
V_63 = ( ( T_7 ) V_61 << 32 ) | V_62 ;
V_38 = F_7 ( & V_4 -> V_8 -> V_38 ) ;
F_38 ( V_2 , L_5 ,
V_61 , V_62 , V_38 ) ;
V_4 -> V_40 = F_27 ( V_2 , V_4 , & V_48 , V_63 , V_38 ) ;
if ( F_36 ( V_4 -> V_40 ) ) {
V_66 = F_37 ( V_4 -> V_40 ) ;
goto V_72;
}
F_14 ( & V_64 , & V_4 -> V_8 -> V_64 , 8 ) ;
V_64 = F_39 ( V_64 ) ;
V_65 = F_7 ( & V_4 -> V_8 -> V_65 ) ;
if ( V_63 != V_64 ) {
V_4 -> V_25 = F_27 ( V_2 , V_4 , & V_48 , V_64 , V_65 ) ;
V_66 = F_40 ( V_4 -> V_25 ) ;
goto V_72;
}
if ( V_38 != V_65 ) {
F_20 ( V_2 , V_67 L_6 ) ;
V_66 = - V_55 ;
goto V_72;
}
V_4 -> V_38 = V_38 ;
V_4 -> V_25 = V_4 -> V_40 ;
V_72:
F_1 ( V_2 , V_4 ) ;
return V_66 ;
}
static int F_41 ( struct V_57 * V_1 )
{
struct V_58 * V_20 ;
struct V_3 * V_4 ;
struct V_15 * V_16 ;
struct V_1 * V_2 = & V_1 -> V_2 ;
T_8 V_43 ;
T_5 V_73 ;
int V_29 ;
V_43 = F_42 ( V_74 , 1 ,
(struct V_75 * * ) & V_20 ) ;
if ( F_43 ( V_43 ) || V_20 -> V_76 . V_77 < sizeof( * V_20 ) ) {
F_20 ( V_2 , V_67 L_7 ) ;
return - V_55 ;
}
V_73 = V_20 -> V_78 ;
if ( V_73 == V_79 )
return - V_80 ;
V_4 = F_44 ( V_2 , sizeof( struct V_3 ) , V_81 ) ;
if ( ! V_4 )
return - V_82 ;
if ( V_73 == V_83 || V_73 == V_79 ||
! strcmp ( F_45 ( V_1 ) , L_8 ) )
V_4 -> V_5 |= V_41 ;
if ( V_73 == V_84 ||
V_73 == V_85 )
V_4 -> V_5 |= V_6 ;
V_29 = F_31 ( V_1 , V_4 , V_20 ) ;
if ( V_29 )
return V_29 ;
V_16 = F_46 ( V_2 , & V_86 ) ;
if ( F_36 ( V_16 ) )
return F_37 ( V_16 ) ;
F_47 ( & V_16 -> V_2 , V_4 ) ;
V_16 -> V_30 = V_1 -> V_87 ;
V_16 -> V_5 = V_88 ;
V_29 = F_3 ( V_2 , V_4 ) ;
if ( V_29 )
return V_29 ;
F_48 ( V_2 ) ;
F_49 ( V_2 ) ;
F_50 ( V_2 ) ;
V_29 = F_51 ( V_16 ) ;
if ( V_29 ) {
F_1 ( V_2 , V_4 ) ;
F_52 ( V_2 ) ;
F_53 ( V_2 ) ;
return V_29 ;
}
F_54 ( V_2 ) ;
return 0 ;
}
static int F_55 ( struct V_57 * V_1 )
{
struct V_1 * V_2 = & V_1 -> V_2 ;
struct V_15 * V_16 = F_12 ( V_2 ) ;
F_56 ( V_16 ) ;
F_53 ( V_2 ) ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = F_12 ( V_2 ) ;
struct V_3 * V_4 = F_12 ( & V_16 -> V_2 ) ;
return F_1 ( V_2 , V_4 ) ;
}
static int F_58 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = F_12 ( V_2 ) ;
struct V_3 * V_4 = F_12 ( & V_16 -> V_2 ) ;
return F_3 ( V_2 , V_4 ) ;
}
