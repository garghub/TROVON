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
* V_25 = V_2 -> V_19 * V_2 -> V_27 - V_2 -> V_28 ;
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
T_1 V_42 = 15 ;
T_1 V_43 = 1 ;
V_2 = F_22 ( V_23 , sizeof( struct V_1 ) , V_44 ) ;
if ( ! V_2 )
return - V_45 ;
V_2 -> V_23 = V_23 ;
V_2 -> V_9 = true ;
V_2 -> V_19 = - 1 ;
if ( F_23 ( V_37 , L_3 ) ) {
V_2 -> V_28 = 271000 ;
V_2 -> V_27 = 167 ;
} else if ( F_23 ( V_37 , L_4 ) ) {
V_2 -> V_28 = 257000 ;
V_2 -> V_27 = 133 ;
} else {
V_2 -> V_28 = 144700 ;
V_2 -> V_27 = 100 ;
}
V_41 = F_24 ( V_37 , L_5 ) ;
if ( V_41 ) {
V_2 -> V_10 = F_25 ( V_23 ) ;
if ( ! V_2 -> V_10 )
return - V_45 ;
V_2 -> V_10 -> V_46 = V_35 -> V_46 ;
V_2 -> V_10 -> V_47 = L_6 ;
V_2 -> V_10 -> V_48 = F_8 ;
V_2 -> V_10 -> V_49 = F_15 ;
V_2 -> V_10 -> V_50 . V_51 = V_52 ;
V_2 -> V_10 -> V_50 . V_53 = 0x0001 ;
V_2 -> V_10 -> V_50 . V_54 = 0x0001 ;
V_2 -> V_10 -> V_50 . V_55 = 0x0100 ;
V_2 -> V_10 -> V_56 [ 0 ] = F_26 ( V_57 ) | F_26 ( V_58 ) | F_26 ( V_59 ) ;
F_27 ( V_13 , V_2 -> V_10 -> V_60 ) ;
F_28 ( V_2 -> V_10 , V_11 , 0 , 4095 , 0 , 0 ) ;
F_28 ( V_2 -> V_10 , V_12 , 0 , 4095 , 0 , 0 ) ;
F_29 ( V_2 -> V_10 , V_2 ) ;
}
V_2 -> V_7 = F_30 ( V_23 ,
F_31 ( V_35 , V_61 , 0 ) ) ;
if ( F_32 ( V_2 -> V_7 ) )
return F_33 ( V_2 -> V_7 ) ;
V_2 -> V_15 = F_34 ( V_35 , 0 ) ;
error = F_35 ( V_23 , V_2 -> V_15 , F_6 , 0 , L_7 , V_2 ) ;
if ( error )
return error ;
F_7 ( F_36 ( 0 ) | F_37 ( 2 ) | F_38 ( 7 ) | F_39 ( 63 ) ,
V_2 -> V_7 + V_62 ) ;
F_40 ( V_37 , L_8 ,
& V_42 ) ;
F_7 ( F_41 ( V_42 ) | F_42 ( 0 ) ,
V_2 -> V_7 + V_63 ) ;
F_40 ( V_37 , L_9 , & V_43 ) ;
F_7 ( F_43 ( 1 ) | F_44 ( V_43 ) , V_2 -> V_7 + V_64 ) ;
F_7 ( F_45 ( 1 ) | F_46 ( 1953 ) , V_2 -> V_7 + V_65 ) ;
V_40 = F_47 ( 5 ) | F_48 ( 1 ) ;
if ( F_23 ( V_37 , L_3 ) )
V_40 |= F_49 ( 1 ) ;
else
V_40 |= F_50 ( 1 ) ;
F_7 ( V_40 , V_2 -> V_7 + V_66 ) ;
V_39 = F_51 ( V_2 -> V_23 , L_10 ,
V_2 , V_67 ) ;
if ( F_32 ( V_39 ) )
return F_33 ( V_39 ) ;
V_2 -> V_68 = F_52 ( V_2 -> V_23 , 0 , V_2 ,
& V_69 ) ;
if ( F_32 ( V_2 -> V_68 ) )
V_2 -> V_68 = NULL ;
F_7 ( F_10 ( 1 ) , V_2 -> V_7 + V_24 ) ;
if ( V_41 ) {
error = F_53 ( V_2 -> V_10 ) ;
if ( error ) {
F_7 ( 0 , V_2 -> V_7 + V_24 ) ;
F_54 ( V_2 -> V_23 , V_2 -> V_68 ) ;
return error ;
}
}
F_55 ( V_35 , V_2 ) ;
return 0 ;
}
static int F_56 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = F_57 ( V_35 ) ;
if ( V_2 -> V_10 )
F_58 ( V_2 -> V_10 ) ;
F_54 ( V_2 -> V_23 , V_2 -> V_68 ) ;
F_7 ( 0 , V_2 -> V_7 + V_24 ) ;
return 0 ;
}
