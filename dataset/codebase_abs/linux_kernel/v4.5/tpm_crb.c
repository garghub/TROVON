static T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
T_1 V_6 = 0 ;
if ( ( F_2 ( F_3 ( & V_4 -> V_7 -> V_8 ) ) & V_9 ) !=
V_9 )
V_6 |= V_10 ;
return V_6 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 * V_11 , T_2 V_12 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
unsigned int V_13 ;
if ( V_12 < 6 )
return - V_14 ;
if ( F_2 ( F_3 ( & V_4 -> V_7 -> V_6 ) ) & V_15 )
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
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
int V_20 = 0 ;
if ( V_27 > F_2 ( F_3 ( & V_4 -> V_7 -> V_28 ) ) ) {
F_11 ( & V_2 -> V_29 ,
L_1 ,
( unsigned int ) V_27 ,
( T_2 ) F_2 ( F_3 ( & V_4 -> V_7 -> V_28 ) ) ) ;
return - V_30 ;
}
F_12 ( V_4 -> V_31 , V_11 , V_27 ) ;
F_13 () ;
if ( V_4 -> V_32 & V_33 )
F_14 ( F_15 ( V_9 ) , & V_4 -> V_7 -> V_8 ) ;
if ( V_4 -> V_32 & V_34 )
V_20 = F_7 ( V_2 ) ;
return V_20 ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
F_14 ( F_15 ( V_35 ) , & V_4 -> V_7 -> V_36 ) ;
F_13 () ;
if ( ( V_4 -> V_32 & V_34 ) && F_7 ( V_2 ) )
F_11 ( & V_2 -> V_29 , L_2 ) ;
F_14 ( 0 , & V_4 -> V_7 -> V_36 ) ;
}
static bool F_17 ( struct V_1 * V_2 , T_1 V_37 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
T_3 V_36 = F_2 ( F_3 ( & V_4 -> V_7 -> V_36 ) ) ;
return ( V_36 & V_35 ) == V_35 ;
}
static int F_18 ( struct V_38 * V_39 )
{
struct V_1 * V_2 ;
struct V_40 * V_11 ;
struct V_3 * V_4 ;
struct V_39 * V_29 = & V_39 -> V_29 ;
T_4 V_37 ;
T_3 V_41 ;
T_5 V_42 ;
int V_20 ;
V_37 = F_19 ( V_43 , 1 ,
(struct V_44 * * ) & V_11 ) ;
if ( F_20 ( V_37 ) ) {
F_11 ( V_29 , L_3 ) ;
return - V_45 ;
}
if ( V_11 -> V_46 == V_47 )
return - V_45 ;
V_2 = F_21 ( V_29 , & V_48 ) ;
if ( F_22 ( V_2 ) )
return F_23 ( V_2 ) ;
V_2 -> V_32 = V_49 ;
if ( V_11 -> V_50 . V_51 < sizeof( struct V_40 ) ) {
F_11 ( V_29 , L_4 ) ;
return - V_52 ;
}
V_4 = (struct V_3 * ) F_24 ( V_29 , sizeof( struct V_3 ) ,
V_53 ) ;
if ( ! V_4 ) {
F_11 ( V_29 , L_5 ) ;
return - V_54 ;
}
V_41 = F_2 ( V_11 -> V_46 ) ;
if ( V_41 == V_55 || V_41 == V_47 ||
! strcmp ( F_25 ( V_39 ) , L_6 ) )
V_4 -> V_32 |= V_33 ;
if ( V_41 == V_56 || V_41 == V_57 )
V_4 -> V_32 |= V_34 ;
V_4 -> V_7 = (struct V_58 V_59 * )
F_26 ( V_29 , V_11 -> V_60 , 0x1000 ) ;
if ( ! V_4 -> V_7 ) {
F_11 ( V_29 , L_7 ) ;
return - V_54 ;
}
V_42 = ( ( T_5 ) F_2 ( F_3 ( & V_4 -> V_7 -> V_61 ) ) << 32 ) |
( T_5 ) F_2 ( F_3 ( & V_4 -> V_7 -> V_62 ) ) ;
V_4 -> V_31 = F_26 ( V_29 , V_42 ,
F_3 ( & V_4 -> V_7 -> V_28 ) ) ;
if ( ! V_4 -> V_31 ) {
F_11 ( V_29 , L_8 ) ;
return - V_54 ;
}
F_5 ( & V_42 , & V_4 -> V_7 -> V_63 , 8 ) ;
V_42 = F_27 ( V_42 ) ;
V_4 -> V_16 = F_26 ( V_29 , V_42 ,
F_3 ( & V_4 -> V_7 -> V_64 ) ) ;
if ( ! V_4 -> V_16 ) {
F_11 ( V_29 , L_9 ) ;
return - V_54 ;
}
V_2 -> V_5 . V_4 = V_4 ;
V_20 = F_28 ( V_2 ) ;
if ( V_20 )
return V_20 ;
V_2 -> V_21 = V_39 -> V_65 ;
V_20 = F_29 ( V_2 ) ;
if ( V_20 )
return V_20 ;
return F_30 ( V_2 ) ;
}
static int F_31 ( struct V_38 * V_39 )
{
struct V_39 * V_29 = & V_39 -> V_29 ;
struct V_1 * V_2 = F_32 ( V_29 ) ;
F_33 ( V_2 ) ;
if ( V_2 -> V_32 & V_49 )
F_34 ( V_2 , V_66 ) ;
return 0 ;
}
