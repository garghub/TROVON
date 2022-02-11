static T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
T_1 V_6 = 0 ;
if ( ( F_2 ( & V_4 -> V_7 -> V_8 ) & V_9 ) !=
V_9 )
V_6 |= V_10 ;
return V_6 ;
}
static int F_3 ( struct V_1 * V_2 , T_1 * V_11 , T_2 V_12 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
unsigned int V_13 ;
if ( V_12 < 6 )
return - V_14 ;
if ( F_2 ( & V_4 -> V_7 -> V_6 ) & V_15 )
return - V_14 ;
F_4 ( V_11 , V_4 -> V_16 , 6 ) ;
V_13 = F_5 ( ( V_17 * ) & V_11 [ 2 ] ) ;
if ( V_13 > V_12 )
return - V_14 ;
F_4 ( & V_11 [ 6 ] , & V_4 -> V_16 [ 6 ] , V_13 - 6 ) ;
return V_13 ;
}
static int F_6 ( struct V_1 * V_2 )
{
union V_18 * V_19 ;
int V_20 ;
V_19 = F_7 ( V_2 -> V_21 ,
V_22 ,
V_23 ,
V_24 ,
NULL ) ;
if ( ! V_19 )
return - V_25 ;
V_20 = V_19 -> integer . V_26 == 0 ? 0 : - V_25 ;
F_8 ( V_19 ) ;
return V_20 ;
}
static int F_9 ( struct V_1 * V_2 , T_1 * V_11 , T_2 V_27 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
int V_20 = 0 ;
if ( V_27 > F_2 ( & V_4 -> V_7 -> V_28 ) ) {
F_10 ( & V_2 -> V_29 ,
L_1 ,
( unsigned int ) V_27 ,
( T_2 ) F_2 ( & V_4 -> V_7 -> V_28 ) ) ;
return - V_30 ;
}
F_11 ( V_4 -> V_31 , V_11 , V_27 ) ;
F_12 () ;
if ( V_4 -> V_32 & V_33 )
F_13 ( F_14 ( V_9 ) , & V_4 -> V_7 -> V_8 ) ;
if ( V_4 -> V_32 & V_34 )
V_20 = F_6 ( V_2 ) ;
return V_20 ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
F_13 ( F_14 ( V_35 ) , & V_4 -> V_7 -> V_36 ) ;
F_12 () ;
if ( ( V_4 -> V_32 & V_34 ) && F_6 ( V_2 ) )
F_10 ( & V_2 -> V_29 , L_2 ) ;
F_13 ( 0 , & V_4 -> V_7 -> V_36 ) ;
}
static bool F_16 ( struct V_1 * V_2 , T_1 V_37 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
T_3 V_36 = F_2 ( & V_4 -> V_7 -> V_36 ) ;
return ( V_36 & V_35 ) == V_35 ;
}
static int F_17 ( struct V_38 * V_39 , struct V_3 * V_4 )
{
struct V_1 * V_2 ;
int V_20 ;
V_2 = F_18 ( & V_39 -> V_29 , & V_40 ) ;
if ( F_19 ( V_2 ) )
return F_20 ( V_2 ) ;
V_2 -> V_5 . V_4 = V_4 ;
V_2 -> V_21 = V_39 -> V_41 ;
V_2 -> V_32 = V_42 ;
V_20 = F_21 ( V_2 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_22 ( V_2 ) ;
if ( V_20 )
return V_20 ;
return F_23 ( V_2 ) ;
}
static int F_24 ( struct V_43 * V_44 , void * V_45 )
{
struct V_3 * V_4 = V_45 ;
struct V_46 V_47 ;
if ( F_25 ( V_44 , & V_47 ) ) {
V_4 -> V_47 = V_47 ;
V_4 -> V_47 . V_48 = NULL ;
}
return 1 ;
}
static void T_4 * F_26 ( struct V_39 * V_29 , struct V_3 * V_4 ,
T_5 V_8 , T_3 V_49 )
{
struct V_46 V_50 = {
. V_8 = V_8 ,
. V_51 = V_8 + V_49 - 1 ,
. V_32 = V_52 ,
} ;
if ( V_8 != V_50 . V_8 )
return F_27 ( - V_53 ) ;
if ( ! F_28 ( & V_4 -> V_47 , & V_50 ) )
return F_29 ( V_29 , & V_50 ) ;
return V_4 -> V_54 + ( V_50 . V_8 - V_4 -> V_47 . V_8 ) ;
}
static int F_30 ( struct V_38 * V_39 , struct V_3 * V_4 ,
struct V_55 * V_11 )
{
struct V_56 V_57 ;
struct V_39 * V_29 = & V_39 -> V_29 ;
T_5 V_58 ;
int V_59 ;
F_31 ( & V_57 ) ;
V_59 = F_32 ( V_39 , & V_57 , F_24 ,
V_4 ) ;
if ( V_59 < 0 )
return V_59 ;
F_33 ( & V_57 ) ;
if ( F_34 ( & V_4 -> V_47 ) != V_52 ) {
F_10 ( V_29 ,
V_60 L_3 ) ;
return - V_53 ;
}
V_4 -> V_54 = F_29 ( V_29 , & V_4 -> V_47 ) ;
if ( F_19 ( V_4 -> V_54 ) )
return F_20 ( V_4 -> V_54 ) ;
V_4 -> V_7 = F_26 ( V_29 , V_4 , V_11 -> V_61 , 0x1000 ) ;
if ( F_19 ( V_4 -> V_7 ) )
return F_20 ( V_4 -> V_7 ) ;
V_58 = ( ( T_5 ) F_2 ( & V_4 -> V_7 -> V_62 ) << 32 ) |
( T_5 ) F_2 ( & V_4 -> V_7 -> V_63 ) ;
V_4 -> V_31 = F_26 ( V_29 , V_4 , V_58 , F_2 ( & V_4 -> V_7 -> V_28 ) ) ;
if ( F_19 ( V_4 -> V_31 ) )
return F_20 ( V_4 -> V_31 ) ;
F_4 ( & V_58 , & V_4 -> V_7 -> V_64 , 8 ) ;
V_58 = F_35 ( V_58 ) ;
V_4 -> V_16 = F_26 ( V_29 , V_4 , V_58 , F_2 ( & V_4 -> V_7 -> V_65 ) ) ;
return F_36 ( V_4 -> V_16 ) ;
}
static int F_37 ( struct V_38 * V_39 )
{
struct V_55 * V_11 ;
struct V_3 * V_4 ;
struct V_39 * V_29 = & V_39 -> V_29 ;
T_6 V_37 ;
T_3 V_66 ;
int V_20 ;
V_37 = F_38 ( V_67 , 1 ,
(struct V_68 * * ) & V_11 ) ;
if ( F_39 ( V_37 ) || V_11 -> V_69 . V_70 < sizeof( * V_11 ) ) {
F_10 ( V_29 , V_60 L_4 ) ;
return - V_53 ;
}
V_66 = V_11 -> V_71 ;
if ( V_66 == V_72 )
return - V_73 ;
V_4 = F_40 ( V_29 , sizeof( struct V_3 ) , V_74 ) ;
if ( ! V_4 )
return - V_75 ;
if ( V_66 == V_76 || V_66 == V_72 ||
! strcmp ( F_41 ( V_39 ) , L_5 ) )
V_4 -> V_32 |= V_33 ;
if ( V_66 == V_77 ||
V_66 == V_78 )
V_4 -> V_32 |= V_34 ;
V_20 = F_30 ( V_39 , V_4 , V_11 ) ;
if ( V_20 )
return V_20 ;
return F_17 ( V_39 , V_4 ) ;
}
static int F_42 ( struct V_38 * V_39 )
{
struct V_39 * V_29 = & V_39 -> V_29 ;
struct V_1 * V_2 = F_43 ( V_29 ) ;
if ( V_2 -> V_32 & V_42 )
F_44 ( V_2 , V_79 ) ;
F_45 ( V_2 ) ;
return 0 ;
}
