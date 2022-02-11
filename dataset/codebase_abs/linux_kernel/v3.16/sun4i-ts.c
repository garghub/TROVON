static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_4 , V_5 ;
if ( V_3 & V_6 ) {
V_4 = F_2 ( V_2 -> V_7 + V_8 ) ;
V_5 = F_2 ( V_2 -> V_7 + V_8 ) ;
if ( ! V_2 -> V_9 ) {
F_3 ( V_2 -> V_10 , V_11 , V_4 ) ;
F_3 ( V_2 -> V_10 , V_12 , V_5 ) ;
F_4 ( V_2 -> V_10 , V_13 , 1 ) ;
F_5 ( V_2 -> V_10 ) ;
} else {
V_2 -> V_9 = false ;
}
}
if ( V_3 & V_14 ) {
V_2 -> V_9 = true ;
F_4 ( V_2 -> V_10 , V_13 , 0 ) ;
F_5 ( V_2 -> V_10 ) ;
}
}
static T_2 F_6 ( int V_15 , void * V_16 )
{
struct V_1 * V_2 = V_16 ;
T_1 V_3 ;
V_3 = F_2 ( V_2 -> V_7 + V_17 ) ;
if ( V_3 & V_18 )
V_2 -> V_19 = F_2 ( V_2 -> V_7 + V_20 ) ;
if ( V_2 -> V_10 )
F_1 ( V_2 , V_3 ) ;
F_7 ( V_3 , V_2 -> V_7 + V_17 ) ;
return V_21 ;
}
static int F_8 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = F_9 ( V_23 ) ;
F_7 ( F_10 ( 1 ) | F_11 ( 1 ) | F_12 ( 1 ) | F_13 ( 1 ) |
F_14 ( 1 ) , V_2 -> V_7 + V_24 ) ;
return 0 ;
}
static void F_15 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = F_9 ( V_23 ) ;
F_7 ( F_10 ( 1 ) , V_2 -> V_7 + V_24 ) ;
}
static T_3 F_16 ( struct V_25 * V_23 , struct V_26 * V_27 ,
char * V_28 )
{
struct V_1 * V_2 = F_17 ( V_23 ) ;
if ( V_2 -> V_19 == - 1 )
return - V_29 ;
return sprintf ( V_28 , L_1 , ( V_2 -> V_19 - 1447 ) * 100 ) ;
}
static T_3 F_18 ( struct V_25 * V_23 ,
struct V_26 * V_27 , char * V_28 )
{
return sprintf ( V_28 , L_2 ) ;
}
static int F_19 ( struct V_30 * V_31 )
{
struct V_1 * V_2 ;
struct V_25 * V_23 = & V_31 -> V_23 ;
struct V_32 * V_33 = V_23 -> V_34 ;
struct V_25 * V_35 ;
int error ;
bool V_36 ;
V_2 = F_20 ( V_23 , sizeof( struct V_1 ) , V_37 ) ;
if ( ! V_2 )
return - V_38 ;
V_2 -> V_23 = V_23 ;
V_2 -> V_9 = true ;
V_2 -> V_19 = - 1 ;
V_36 = F_21 ( V_33 , L_3 ) ;
if ( V_36 ) {
V_2 -> V_10 = F_22 ( V_23 ) ;
if ( ! V_2 -> V_10 )
return - V_38 ;
V_2 -> V_10 -> V_39 = V_31 -> V_39 ;
V_2 -> V_10 -> V_40 = L_4 ;
V_2 -> V_10 -> V_41 = F_8 ;
V_2 -> V_10 -> V_42 = F_15 ;
V_2 -> V_10 -> V_43 . V_44 = V_45 ;
V_2 -> V_10 -> V_43 . V_46 = 0x0001 ;
V_2 -> V_10 -> V_43 . V_47 = 0x0001 ;
V_2 -> V_10 -> V_43 . V_48 = 0x0100 ;
V_2 -> V_10 -> V_49 [ 0 ] = F_23 ( V_50 ) | F_23 ( V_51 ) | F_23 ( V_52 ) ;
F_24 ( V_13 , V_2 -> V_10 -> V_53 ) ;
F_25 ( V_2 -> V_10 , V_11 , 0 , 4095 , 0 , 0 ) ;
F_25 ( V_2 -> V_10 , V_12 , 0 , 4095 , 0 , 0 ) ;
F_26 ( V_2 -> V_10 , V_2 ) ;
}
V_2 -> V_7 = F_27 ( V_23 ,
F_28 ( V_31 , V_54 , 0 ) ) ;
if ( F_29 ( V_2 -> V_7 ) )
return F_30 ( V_2 -> V_7 ) ;
V_2 -> V_15 = F_31 ( V_31 , 0 ) ;
error = F_32 ( V_23 , V_2 -> V_15 , F_6 , 0 , L_5 , V_2 ) ;
if ( error )
return error ;
F_7 ( F_33 ( 0 ) | F_34 ( 2 ) | F_35 ( 7 ) | F_36 ( 63 ) ,
V_2 -> V_7 + V_55 ) ;
F_7 ( F_37 ( 15 ) | F_38 ( 0 ) ,
V_2 -> V_7 + V_56 ) ;
F_7 ( F_39 ( 1 ) | F_40 ( 1 ) , V_2 -> V_7 + V_57 ) ;
F_7 ( F_41 ( 1 ) | F_42 ( 1953 ) , V_2 -> V_7 + V_58 ) ;
F_7 ( F_43 ( 5 ) | F_44 ( 1 ) | F_45 ( 1 ) ,
V_2 -> V_7 + V_59 ) ;
V_35 = F_46 ( V_2 -> V_23 , L_6 ,
V_2 , V_60 ) ;
if ( F_29 ( V_35 ) )
return F_30 ( V_35 ) ;
F_7 ( F_10 ( 1 ) , V_2 -> V_7 + V_24 ) ;
if ( V_36 ) {
error = F_47 ( V_2 -> V_10 ) ;
if ( error ) {
F_7 ( 0 , V_2 -> V_7 + V_24 ) ;
return error ;
}
}
F_48 ( V_31 , V_2 ) ;
return 0 ;
}
static int F_49 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = F_50 ( V_31 ) ;
if ( V_2 -> V_10 )
F_51 ( V_2 -> V_10 ) ;
F_7 ( 0 , V_2 -> V_7 + V_24 ) ;
return 0 ;
}
