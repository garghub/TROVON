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
static int F_16 ( const struct V_1 * V_2 , long * V_25 )
{
if ( V_2 -> V_19 == - 1 )
return - V_26 ;
* V_25 = ( V_2 -> V_19 - V_2 -> V_27 ) * V_2 -> V_28 ;
return 0 ;
}
static int F_17 ( void * V_29 , long * V_25 )
{
return F_16 ( V_29 , V_25 ) ;
}
static T_3 F_18 ( struct V_30 * V_23 , struct V_31 * V_32 ,
char * V_33 )
{
struct V_1 * V_2 = F_19 ( V_23 ) ;
long V_25 ;
int error ;
error = F_16 ( V_2 , & V_25 ) ;
if ( error )
return error ;
return sprintf ( V_33 , L_1 , V_25 ) ;
}
static T_3 F_20 ( struct V_30 * V_23 ,
struct V_31 * V_32 , char * V_33 )
{
return sprintf ( V_33 , L_2 ) ;
}
static int F_21 ( struct V_34 * V_35 )
{
struct V_1 * V_2 ;
struct V_30 * V_23 = & V_35 -> V_23 ;
struct V_36 * V_37 = V_23 -> V_38 ;
struct V_30 * V_39 ;
int error ;
T_1 V_40 ;
bool V_41 ;
V_2 = F_22 ( V_23 , sizeof( struct V_1 ) , V_42 ) ;
if ( ! V_2 )
return - V_43 ;
V_2 -> V_23 = V_23 ;
V_2 -> V_9 = true ;
V_2 -> V_19 = - 1 ;
if ( F_23 ( V_37 , L_3 ) ) {
V_2 -> V_27 = 1626 ;
V_2 -> V_28 = 167 ;
} else {
V_2 -> V_27 = 1447 ;
V_2 -> V_28 = 100 ;
}
V_41 = F_24 ( V_37 , L_4 ) ;
if ( V_41 ) {
V_2 -> V_10 = F_25 ( V_23 ) ;
if ( ! V_2 -> V_10 )
return - V_43 ;
V_2 -> V_10 -> V_44 = V_35 -> V_44 ;
V_2 -> V_10 -> V_45 = L_5 ;
V_2 -> V_10 -> V_46 = F_8 ;
V_2 -> V_10 -> V_47 = F_15 ;
V_2 -> V_10 -> V_48 . V_49 = V_50 ;
V_2 -> V_10 -> V_48 . V_51 = 0x0001 ;
V_2 -> V_10 -> V_48 . V_52 = 0x0001 ;
V_2 -> V_10 -> V_48 . V_53 = 0x0100 ;
V_2 -> V_10 -> V_54 [ 0 ] = F_26 ( V_55 ) | F_26 ( V_56 ) | F_26 ( V_57 ) ;
F_27 ( V_13 , V_2 -> V_10 -> V_58 ) ;
F_28 ( V_2 -> V_10 , V_11 , 0 , 4095 , 0 , 0 ) ;
F_28 ( V_2 -> V_10 , V_12 , 0 , 4095 , 0 , 0 ) ;
F_29 ( V_2 -> V_10 , V_2 ) ;
}
V_2 -> V_7 = F_30 ( V_23 ,
F_31 ( V_35 , V_59 , 0 ) ) ;
if ( F_32 ( V_2 -> V_7 ) )
return F_33 ( V_2 -> V_7 ) ;
V_2 -> V_15 = F_34 ( V_35 , 0 ) ;
error = F_35 ( V_23 , V_2 -> V_15 , F_6 , 0 , L_6 , V_2 ) ;
if ( error )
return error ;
F_7 ( F_36 ( 0 ) | F_37 ( 2 ) | F_38 ( 7 ) | F_39 ( 63 ) ,
V_2 -> V_7 + V_60 ) ;
F_7 ( F_40 ( 15 ) | F_41 ( 0 ) ,
V_2 -> V_7 + V_61 ) ;
F_7 ( F_42 ( 1 ) | F_43 ( 1 ) , V_2 -> V_7 + V_62 ) ;
F_7 ( F_44 ( 1 ) | F_45 ( 1953 ) , V_2 -> V_7 + V_63 ) ;
V_40 = F_46 ( 5 ) | F_47 ( 1 ) ;
if ( F_23 ( V_37 , L_7 ) )
V_40 |= F_48 ( 1 ) ;
else
V_40 |= F_49 ( 1 ) ;
F_7 ( V_40 , V_2 -> V_7 + V_64 ) ;
V_39 = F_50 ( V_2 -> V_23 , L_8 ,
V_2 , V_65 ) ;
if ( F_32 ( V_39 ) )
return F_33 ( V_39 ) ;
V_2 -> V_66 = F_51 ( V_2 -> V_23 , 0 , V_2 ,
& V_67 ) ;
if ( F_32 ( V_2 -> V_66 ) )
V_2 -> V_66 = NULL ;
F_7 ( F_10 ( 1 ) , V_2 -> V_7 + V_24 ) ;
if ( V_41 ) {
error = F_52 ( V_2 -> V_10 ) ;
if ( error ) {
F_7 ( 0 , V_2 -> V_7 + V_24 ) ;
F_53 ( V_2 -> V_23 , V_2 -> V_66 ) ;
return error ;
}
}
F_54 ( V_35 , V_2 ) ;
return 0 ;
}
static int F_55 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = F_56 ( V_35 ) ;
if ( V_2 -> V_10 )
F_57 ( V_2 -> V_10 ) ;
F_53 ( V_2 -> V_23 , V_2 -> V_66 ) ;
F_7 ( 0 , V_2 -> V_7 + V_24 ) ;
return 0 ;
}
