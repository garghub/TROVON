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
int error ;
F_11 ( V_30 -> V_20 ) ;
error = F_8 ( V_30 -> V_2 , V_31 ,
V_32 |
V_33 |
V_34 ) ;
if ( error < 0 ) {
F_12 ( V_30 -> V_20 ) ;
return error ;
}
return 0 ;
}
static void F_13 ( struct V_27 * V_28 )
{
struct V_29 * V_30 = F_10 ( V_28 ) ;
F_12 ( V_30 -> V_20 ) ;
}
static T_3 F_14 ( int V_35 , void * V_36 )
{
struct V_29 * V_30 = V_36 ;
struct V_15 V_37 ;
F_3 ( V_30 -> V_2 , & V_37 ) ;
F_15 ( V_30 -> V_38 , V_39 , V_37 . V_17 ) ;
F_15 ( V_30 -> V_38 , V_40 , V_37 . V_18 ) ;
F_15 ( V_30 -> V_38 , V_41 , V_37 . V_19 ) ;
F_16 ( V_30 -> V_38 ) ;
return V_42 ;
}
static int F_17 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
int V_43 ;
T_1 V_44 ;
V_43 = F_8 ( V_2 , V_24 ,
V_45 ) ;
if ( V_43 < 0 )
return V_43 ;
V_43 = F_7 ( V_2 , V_24 ) ;
if ( V_43 < 0 )
return V_43 ;
V_43 &= ~ V_46 ;
V_43 |= V_47 ;
V_43 = F_8 ( V_2 , V_24 , V_43 ) ;
if ( V_43 < 0 )
return V_43 ;
V_43 = F_8 ( V_2 , V_48 ,
V_49 - 1 ) ;
if ( V_43 < 0 )
return V_43 ;
V_44 = V_50 ;
V_44 |= V_51 << 3 ;
V_44 |= V_52 << 5 ;
V_43 = F_8 ( V_2 , V_53 , V_44 ) ;
if ( V_43 < 0 )
return V_43 ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
const struct V_54 * V_55 )
{
struct V_29 * V_30 ;
struct V_27 * V_38 ;
int V_43 ;
int error ;
V_30 = F_19 ( sizeof( struct V_29 ) , V_56 ) ;
V_38 = F_20 () ;
if ( ! V_30 || ! V_38 ) {
F_21 ( & V_2 -> V_20 , L_2 ) ;
error = - V_57 ;
goto V_58;
}
V_30 -> V_2 = V_2 ;
V_30 -> V_20 = & V_2 -> V_20 ;
V_30 -> V_38 = V_38 ;
F_6 ( V_2 , 1 ) ;
F_22 ( 10 ) ;
V_43 = F_7 ( V_2 , V_59 ) ;
if ( V_43 < 0 ) {
F_21 ( & V_2 -> V_20 , L_3 ) ;
error = - V_60 ;
goto V_58;
}
if ( V_43 != V_61 ) {
F_21 ( & V_2 -> V_20 , L_4 ) ;
error = - V_60 ;
goto V_58;
}
V_38 -> V_62 = L_5 ;
V_38 -> V_55 . V_63 = V_64 ;
V_38 -> V_20 . V_65 = & V_2 -> V_20 ;
V_38 -> V_66 = F_9 ;
V_38 -> V_67 = F_13 ;
F_23 ( V_68 , V_38 -> V_69 ) ;
F_24 ( V_38 , V_39 ,
V_70 , V_71 , 0 , 0 ) ;
F_24 ( V_38 , V_40 ,
V_70 , V_71 , 0 , 0 ) ;
F_24 ( V_38 , V_41 ,
V_70 , V_71 , 0 , 0 ) ;
F_25 ( V_38 , V_30 ) ;
F_26 ( & V_2 -> V_20 ) ;
error = F_17 ( V_30 ) ;
if ( error )
goto V_72;
error = F_27 ( V_2 -> V_35 ,
NULL , F_14 ,
V_73 | V_74 ,
L_6 , V_30 ) ;
if ( error ) {
F_21 ( & V_2 -> V_20 ,
L_7 , V_2 -> V_35 , error ) ;
goto V_72;
}
error = F_28 ( V_38 ) ;
if ( error ) {
F_21 ( & V_2 -> V_20 , L_8 ) ;
goto V_75;
}
F_29 ( & V_2 -> V_20 ) ;
F_30 ( & V_2 -> V_20 , V_76 ) ;
return 0 ;
V_75:
F_31 ( V_2 -> V_35 , V_30 ) ;
V_72:
F_32 ( & V_2 -> V_20 ) ;
V_58:
F_33 ( V_38 ) ;
F_34 ( V_30 ) ;
return error ;
}
static int F_35 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_36 ( V_2 ) ;
F_37 ( & V_2 -> V_20 ) ;
F_32 ( & V_2 -> V_20 ) ;
F_31 ( V_2 -> V_35 , V_30 ) ;
F_38 ( V_30 -> V_38 ) ;
F_34 ( V_30 ) ;
return 0 ;
}
static int F_39 ( struct V_77 * V_20 )
{
struct V_1 * V_2 = F_40 ( V_20 ) ;
F_6 ( V_2 , 0 ) ;
return 0 ;
}
static int F_41 ( struct V_77 * V_20 )
{
struct V_1 * V_2 = F_40 ( V_20 ) ;
F_6 ( V_2 , 1 ) ;
F_22 ( 100 ) ;
return 0 ;
}
