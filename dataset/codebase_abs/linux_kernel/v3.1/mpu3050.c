static int F_1 ( struct V_1 * V_2 ,
T_1 * V_3 , int V_4 )
{
char V_5 = V_6 ;
struct V_7 V_8 [] = {
{
. V_9 = V_2 -> V_9 ,
. V_10 = 0 ,
. V_11 = 1 ,
. V_12 = & V_5 ,
} ,
{
. V_9 = V_2 -> V_9 ,
. V_10 = V_13 ,
. V_11 = V_4 ,
. V_12 = V_3 ,
} ,
} ;
return F_2 ( V_2 -> V_14 , V_8 , 2 ) ;
}
static void F_3 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
T_2 V_3 [ 3 ] ;
F_1 ( V_2 , ( T_1 * ) V_3 , 6 ) ;
V_16 -> V_17 = F_4 ( V_3 [ 0 ] ) ;
V_16 -> V_18 = F_4 ( V_3 [ 1 ] ) ;
V_16 -> V_19 = F_4 ( V_3 [ 2 ] ) ;
F_5 ( & V_2 -> V_20 , L_1 , V_21 ,
V_16 -> V_17 , V_16 -> V_18 , V_16 -> V_19 ) ;
}
static void F_6 ( struct V_1 * V_2 , T_1 V_22 )
{
T_1 V_23 ;
V_23 = F_7 ( V_2 , V_24 ) ;
V_23 = ( V_23 & ~ V_25 ) |
( ( ( V_22 << V_26 ) & V_25 ) ^
V_25 ) ;
F_8 ( V_2 , V_24 , V_23 ) ;
}
static int F_9 ( struct V_27 * V_28 )
{
struct V_29 * V_30 = F_10 ( V_28 ) ;
F_11 ( V_30 -> V_20 ) ;
return 0 ;
}
static void F_12 ( struct V_27 * V_28 )
{
struct V_29 * V_30 = F_10 ( V_28 ) ;
F_13 ( V_30 -> V_20 ) ;
}
static T_3 F_14 ( int V_31 , void * V_32 )
{
struct V_29 * V_30 = V_32 ;
struct V_15 V_33 ;
F_3 ( V_30 -> V_2 , & V_33 ) ;
F_15 ( V_30 -> V_34 , V_35 , V_33 . V_17 ) ;
F_15 ( V_30 -> V_34 , V_36 , V_33 . V_18 ) ;
F_15 ( V_30 -> V_34 , V_37 , V_33 . V_19 ) ;
F_16 ( V_30 -> V_34 ) ;
return V_38 ;
}
static int T_4 F_17 ( struct V_1 * V_2 ,
const struct V_39 * V_40 )
{
struct V_29 * V_30 ;
struct V_27 * V_34 ;
int V_41 ;
int error ;
V_30 = F_18 ( sizeof( struct V_29 ) , V_42 ) ;
V_34 = F_19 () ;
if ( ! V_30 || ! V_34 ) {
F_20 ( & V_2 -> V_20 , L_2 ) ;
error = - V_43 ;
goto V_44;
}
V_30 -> V_2 = V_2 ;
V_30 -> V_20 = & V_2 -> V_20 ;
V_30 -> V_34 = V_34 ;
F_6 ( V_2 , 1 ) ;
F_21 ( 10 ) ;
V_41 = F_7 ( V_2 , V_45 ) ;
if ( V_41 < 0 ) {
F_20 ( & V_2 -> V_20 , L_3 ) ;
error = - V_46 ;
goto V_44;
}
if ( V_41 != V_47 ) {
F_20 ( & V_2 -> V_20 , L_4 ) ;
error = - V_46 ;
goto V_44;
}
V_34 -> V_48 = L_5 ;
V_34 -> V_40 . V_49 = V_50 ;
V_34 -> V_20 . V_51 = & V_2 -> V_20 ;
V_34 -> V_52 = F_9 ;
V_34 -> V_53 = F_12 ;
F_22 ( V_54 , V_34 -> V_55 ) ;
F_23 ( V_34 , V_35 ,
V_56 , V_57 , 0 , 0 ) ;
F_23 ( V_34 , V_36 ,
V_56 , V_57 , 0 , 0 ) ;
F_23 ( V_34 , V_37 ,
V_56 , V_57 , 0 , 0 ) ;
F_24 ( V_34 , V_30 ) ;
F_25 ( & V_2 -> V_20 ) ;
error = F_26 ( V_2 -> V_31 ,
NULL , F_14 ,
V_58 ,
L_6 , V_30 ) ;
if ( error ) {
F_20 ( & V_2 -> V_20 ,
L_7 , V_2 -> V_31 , error ) ;
goto V_59;
}
error = F_27 ( V_34 ) ;
if ( error ) {
F_20 ( & V_2 -> V_20 , L_8 ) ;
goto V_60;
}
F_28 ( & V_2 -> V_20 ) ;
F_29 ( & V_2 -> V_20 , V_61 ) ;
return 0 ;
V_60:
F_30 ( V_2 -> V_31 , V_30 ) ;
V_59:
F_31 ( & V_2 -> V_20 ) ;
V_44:
F_32 ( V_34 ) ;
F_33 ( V_30 ) ;
return error ;
}
static int T_5 F_34 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_35 ( V_2 ) ;
F_36 ( & V_2 -> V_20 ) ;
F_31 ( & V_2 -> V_20 ) ;
F_30 ( V_2 -> V_31 , V_30 ) ;
F_37 ( V_30 -> V_34 ) ;
F_33 ( V_30 ) ;
return 0 ;
}
static int F_38 ( struct V_62 * V_20 )
{
struct V_1 * V_2 = F_39 ( V_20 ) ;
F_6 ( V_2 , 0 ) ;
return 0 ;
}
static int F_40 ( struct V_62 * V_20 )
{
struct V_1 * V_2 = F_39 ( V_20 ) ;
F_6 ( V_2 , 1 ) ;
F_21 ( 100 ) ;
return 0 ;
}
static int T_6 F_41 ( void )
{
return F_42 ( & V_63 ) ;
}
static void T_7 F_43 ( void )
{
F_44 ( & V_63 ) ;
}
