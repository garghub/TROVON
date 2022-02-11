static T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( & V_2 -> V_5 ) ;
T_1 V_6 = 0 ;
if ( ( F_3 ( & V_4 -> V_7 -> V_8 ) & V_9 ) !=
V_9 )
V_6 |= V_10 ;
return V_6 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 * V_11 , T_2 V_12 )
{
struct V_3 * V_4 = F_2 ( & V_2 -> V_5 ) ;
unsigned int V_13 ;
if ( V_12 < 6 )
return - V_14 ;
if ( F_3 ( & V_4 -> V_7 -> V_6 ) & V_15 )
return - V_14 ;
F_5 ( V_11 , V_4 -> V_16 , 6 ) ;
V_13 = F_6 ( ( V_17 * ) & V_11 [ 2 ] ) ;
if ( V_13 > V_12 )
return - V_14 ;
F_5 ( & V_11 [ 6 ] , & V_4 -> V_16 [ 6 ] , V_13 - 6 ) ;
return V_13 ;
}
static int F_7 ( struct V_1 * V_2 )
{
union V_18 * V_19 ;
int V_20 ;
V_19 = F_8 ( V_2 -> V_21 ,
V_22 ,
V_23 ,
V_24 ,
NULL ) ;
if ( ! V_19 )
return - V_25 ;
V_20 = V_19 -> integer . V_26 == 0 ? 0 : - V_25 ;
F_9 ( V_19 ) ;
return V_20 ;
}
static int F_10 ( struct V_1 * V_2 , T_1 * V_11 , T_2 V_27 )
{
struct V_3 * V_4 = F_2 ( & V_2 -> V_5 ) ;
int V_20 = 0 ;
if ( V_27 > F_3 ( & V_4 -> V_7 -> V_28 ) ) {
F_11 ( & V_2 -> V_5 ,
L_1 ,
( unsigned int ) V_27 ,
( T_2 ) F_3 ( & V_4 -> V_7 -> V_28 ) ) ;
return - V_29 ;
}
F_12 ( V_4 -> V_30 , V_11 , V_27 ) ;
F_13 () ;
if ( V_4 -> V_31 & V_32 )
F_14 ( F_15 ( V_9 ) , & V_4 -> V_7 -> V_8 ) ;
if ( V_4 -> V_31 & V_33 )
V_20 = F_7 ( V_2 ) ;
return V_20 ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( & V_2 -> V_5 ) ;
F_14 ( F_15 ( V_34 ) , & V_4 -> V_7 -> V_35 ) ;
F_13 () ;
if ( ( V_4 -> V_31 & V_33 ) && F_7 ( V_2 ) )
F_11 ( & V_2 -> V_5 , L_2 ) ;
F_14 ( 0 , & V_4 -> V_7 -> V_35 ) ;
}
static bool F_17 ( struct V_1 * V_2 , T_1 V_36 )
{
struct V_3 * V_4 = F_2 ( & V_2 -> V_5 ) ;
T_3 V_35 = F_3 ( & V_4 -> V_7 -> V_35 ) ;
return ( V_35 & V_34 ) == V_34 ;
}
static int F_18 ( struct V_37 * V_38 , struct V_3 * V_4 )
{
struct V_1 * V_2 ;
V_2 = F_19 ( & V_38 -> V_5 , & V_39 ) ;
if ( F_20 ( V_2 ) )
return F_21 ( V_2 ) ;
F_22 ( & V_2 -> V_5 , V_4 ) ;
V_2 -> V_21 = V_38 -> V_40 ;
V_2 -> V_31 = V_41 ;
return F_23 ( V_2 ) ;
}
static int F_24 ( struct V_42 * V_43 , void * V_44 )
{
struct V_45 * V_46 = V_44 ;
struct V_45 V_47 ;
if ( F_25 ( V_43 , & V_47 ) ) {
* V_46 = V_47 ;
V_46 -> V_48 = NULL ;
}
return 1 ;
}
static void T_4 * F_26 ( struct V_38 * V_5 , struct V_3 * V_4 ,
struct V_45 * V_46 , T_5 V_8 , T_3 V_49 )
{
struct V_45 V_50 = {
. V_8 = V_8 ,
. V_51 = V_8 + V_49 - 1 ,
. V_31 = V_52 ,
} ;
if ( V_8 != V_50 . V_8 )
return ( void T_4 * ) F_27 ( - V_53 ) ;
if ( ! F_28 ( V_46 , & V_50 ) )
return F_29 ( V_5 , & V_50 ) ;
return V_4 -> V_54 + ( V_50 . V_8 - V_46 -> V_8 ) ;
}
static int F_30 ( struct V_37 * V_38 , struct V_3 * V_4 ,
struct V_55 * V_11 )
{
struct V_56 V_57 ;
struct V_45 V_46 ;
struct V_38 * V_5 = & V_38 -> V_5 ;
T_5 V_58 ;
T_3 V_28 ;
T_5 V_59 ;
T_3 V_60 ;
int V_61 ;
F_31 ( & V_57 ) ;
V_61 = F_32 ( V_38 , & V_57 , F_24 ,
& V_46 ) ;
if ( V_61 < 0 )
return V_61 ;
F_33 ( & V_57 ) ;
if ( F_34 ( & V_46 ) != V_52 ) {
F_11 ( V_5 ,
V_62 L_3 ) ;
return - V_53 ;
}
V_4 -> V_54 = F_29 ( V_5 , & V_46 ) ;
if ( F_20 ( V_4 -> V_54 ) )
return F_21 ( V_4 -> V_54 ) ;
V_4 -> V_7 = F_26 ( V_5 , V_4 , & V_46 , V_11 -> V_63 ,
sizeof( struct V_64 ) ) ;
if ( F_20 ( V_4 -> V_7 ) )
return F_21 ( V_4 -> V_7 ) ;
V_58 = ( ( T_5 ) F_3 ( & V_4 -> V_7 -> V_65 ) << 32 ) |
( T_5 ) F_3 ( & V_4 -> V_7 -> V_66 ) ;
V_28 = F_3 ( & V_4 -> V_7 -> V_28 ) ;
V_4 -> V_30 = F_26 ( V_5 , V_4 , & V_46 , V_58 , V_28 ) ;
if ( F_20 ( V_4 -> V_30 ) )
return F_21 ( V_4 -> V_30 ) ;
F_5 ( & V_59 , & V_4 -> V_7 -> V_59 , 8 ) ;
V_59 = F_35 ( V_59 ) ;
V_60 = F_3 ( & V_4 -> V_7 -> V_60 ) ;
if ( V_58 != V_59 ) {
V_4 -> V_16 = F_26 ( V_5 , V_4 , & V_46 , V_59 , V_60 ) ;
return F_36 ( V_4 -> V_16 ) ;
}
if ( V_28 != V_60 ) {
F_11 ( V_5 , V_62 L_4 ) ;
return - V_53 ;
}
V_4 -> V_16 = V_4 -> V_30 ;
return 0 ;
}
static int F_37 ( struct V_37 * V_38 )
{
struct V_55 * V_11 ;
struct V_3 * V_4 ;
struct V_38 * V_5 = & V_38 -> V_5 ;
T_6 V_36 ;
T_3 V_67 ;
int V_20 ;
V_36 = F_38 ( V_68 , 1 ,
(struct V_69 * * ) & V_11 ) ;
if ( F_39 ( V_36 ) || V_11 -> V_70 . V_71 < sizeof( * V_11 ) ) {
F_11 ( V_5 , V_62 L_5 ) ;
return - V_53 ;
}
V_67 = V_11 -> V_72 ;
if ( V_67 == V_73 )
return - V_74 ;
V_4 = F_40 ( V_5 , sizeof( struct V_3 ) , V_75 ) ;
if ( ! V_4 )
return - V_76 ;
if ( V_67 == V_77 || V_67 == V_73 ||
! strcmp ( F_41 ( V_38 ) , L_6 ) )
V_4 -> V_31 |= V_32 ;
if ( V_67 == V_78 ||
V_67 == V_79 )
V_4 -> V_31 |= V_33 ;
V_20 = F_30 ( V_38 , V_4 , V_11 ) ;
if ( V_20 )
return V_20 ;
return F_18 ( V_38 , V_4 ) ;
}
static int F_42 ( struct V_37 * V_38 )
{
struct V_38 * V_5 = & V_38 -> V_5 ;
struct V_1 * V_2 = F_2 ( V_5 ) ;
F_43 ( V_2 ) ;
return 0 ;
}
