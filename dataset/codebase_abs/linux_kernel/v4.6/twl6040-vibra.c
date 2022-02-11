static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
struct V_5 * V_5 = V_4 -> V_5 ;
T_2 V_6 ;
V_6 = F_2 ( V_5 , V_7 ) ;
if ( V_6 & V_8 ) {
F_3 ( V_4 -> V_9 , L_1 ) ;
F_4 ( V_5 , V_10 ,
V_11 ) ;
}
if ( V_6 & V_12 ) {
F_3 ( V_4 -> V_9 , L_2 ) ;
F_4 ( V_5 , V_13 ,
V_11 ) ;
}
return V_14 ;
}
static void F_5 ( struct V_3 * V_4 )
{
struct V_5 * V_5 = V_4 -> V_5 ;
int V_15 ;
V_15 = F_6 ( F_7 ( V_4 -> V_16 ) , V_4 -> V_16 ) ;
if ( V_15 ) {
F_8 ( V_4 -> V_9 , L_3 , V_15 ) ;
return;
}
F_9 ( V_4 -> V_5 , 1 ) ;
if ( F_10 ( V_5 ) <= V_17 ) {
F_11 ( V_5 , V_10 ,
V_11 | V_18 ) ;
F_11 ( V_5 , V_13 ,
V_11 | V_18 ) ;
F_12 ( 3000 , 3500 ) ;
}
F_11 ( V_5 , V_10 ,
V_11 ) ;
F_11 ( V_5 , V_13 ,
V_11 ) ;
V_4 -> V_19 = true ;
}
static void F_13 ( struct V_3 * V_4 )
{
struct V_5 * V_5 = V_4 -> V_5 ;
F_11 ( V_5 , V_10 , 0x00 ) ;
F_11 ( V_5 , V_13 , 0x00 ) ;
F_9 ( V_4 -> V_5 , 0 ) ;
F_14 ( F_7 ( V_4 -> V_16 ) , V_4 -> V_16 ) ;
V_4 -> V_19 = false ;
}
static T_2 F_15 ( int V_20 , int V_21 , int V_22 ,
int V_23 , int V_24 )
{
int V_25 , V_26 ;
T_2 V_27 ;
V_25 = ( V_20 * V_22 * V_28 ) /
( 100 * ( V_21 + V_22 ) ) ;
V_26 = V_25 / 50 ;
if ( V_26 > V_29 )
V_26 = V_29 ;
V_27 = ( T_2 ) ( ( V_23 * V_26 ) / V_30 ) ;
V_27 *= V_24 ;
return V_27 ;
}
static void F_16 ( struct V_3 * V_4 )
{
struct V_5 * V_5 = V_4 -> V_5 ;
T_2 V_31 , V_32 ;
int V_33 ;
V_33 = F_17 ( V_4 -> V_16 [ 0 ] . V_34 ) / 1000 ;
V_31 = F_15 ( V_33 , V_4 -> V_35 ,
V_4 -> V_36 ,
V_4 -> V_37 , V_4 -> V_24 ) ;
V_33 = F_17 ( V_4 -> V_16 [ 1 ] . V_34 ) / 1000 ;
V_32 = F_15 ( V_33 , V_4 -> V_38 ,
V_4 -> V_39 ,
V_4 -> V_40 , V_4 -> V_24 ) ;
F_11 ( V_5 , V_41 , V_31 ) ;
F_11 ( V_5 , V_42 , V_32 ) ;
}
static void F_18 ( struct V_43 * V_44 )
{
struct V_3 * V_4 = F_19 ( V_44 ,
struct V_3 , V_45 ) ;
int V_15 ;
V_15 = F_20 ( V_4 -> V_5 ) ;
if ( V_15 & V_46 ) {
F_21 ( V_4 -> V_9 , L_4 ) ;
return;
}
F_22 ( & V_4 -> V_47 ) ;
if ( V_4 -> V_37 || V_4 -> V_40 ) {
if ( ! V_4 -> V_19 )
F_5 ( V_4 ) ;
F_16 ( V_4 ) ;
} else if ( V_4 -> V_19 )
F_13 ( V_4 ) ;
F_23 ( & V_4 -> V_47 ) ;
}
static int F_24 ( struct V_48 * V_49 , void * V_2 ,
struct V_50 * V_51 )
{
struct V_3 * V_4 = F_25 ( V_49 ) ;
V_4 -> V_37 = V_51 -> V_52 . V_53 . V_54 ;
V_4 -> V_40 = V_51 -> V_52 . V_53 . V_55 ;
V_4 -> V_24 = V_51 -> V_24 < V_56 ? 1 : - 1 ;
F_26 ( & V_4 -> V_45 ) ;
return 0 ;
}
static void F_27 ( struct V_48 * V_49 )
{
struct V_3 * V_4 = F_25 ( V_49 ) ;
F_28 ( & V_4 -> V_45 ) ;
F_22 ( & V_4 -> V_47 ) ;
if ( V_4 -> V_19 )
F_13 ( V_4 ) ;
F_23 ( & V_4 -> V_47 ) ;
}
static int T_3 F_29 ( struct V_57 * V_9 )
{
struct V_58 * V_59 = F_30 ( V_9 ) ;
struct V_3 * V_4 = F_31 ( V_59 ) ;
F_22 ( & V_4 -> V_47 ) ;
if ( V_4 -> V_19 )
F_13 ( V_4 ) ;
F_23 ( & V_4 -> V_47 ) ;
return 0 ;
}
static int F_32 ( struct V_58 * V_59 )
{
struct V_57 * V_60 = V_59 -> V_9 . V_61 ;
struct V_62 * V_63 ;
struct V_3 * V_4 ;
int V_64 = 0 ;
int V_65 = 0 ;
int error ;
F_33 ( V_60 -> V_66 ) ;
V_63 = F_34 ( V_60 -> V_66 ,
L_5 ) ;
if ( ! V_63 ) {
F_8 ( & V_59 -> V_9 , L_6 ) ;
return - V_67 ;
}
V_4 = F_35 ( & V_59 -> V_9 , sizeof( * V_4 ) , V_68 ) ;
if ( ! V_4 ) {
F_36 ( V_63 ) ;
F_8 ( & V_59 -> V_9 , L_7 ) ;
return - V_69 ;
}
V_4 -> V_9 = & V_59 -> V_9 ;
V_4 -> V_5 = F_37 ( V_59 -> V_9 . V_61 ) ;
F_38 ( V_63 , L_8 ,
& V_4 -> V_35 ) ;
F_38 ( V_63 , L_9 ,
& V_4 -> V_38 ) ;
F_38 ( V_63 , L_10 ,
& V_4 -> V_36 ) ;
F_38 ( V_63 , L_11 ,
& V_4 -> V_39 ) ;
F_38 ( V_63 , L_12 , & V_64 ) ;
F_38 ( V_63 , L_13 , & V_65 ) ;
F_36 ( V_63 ) ;
if ( ( ! V_4 -> V_35 && ! V_4 -> V_36 ) ||
( ! V_4 -> V_38 && ! V_4 -> V_39 ) ) {
F_8 ( V_4 -> V_9 , L_14 ) ;
return - V_67 ;
}
V_4 -> V_1 = F_39 ( V_59 , 0 ) ;
if ( V_4 -> V_1 < 0 ) {
F_8 ( V_4 -> V_9 , L_15 ) ;
return - V_67 ;
}
F_40 ( & V_4 -> V_47 ) ;
error = F_41 ( & V_59 -> V_9 , V_4 -> V_1 , NULL ,
F_1 ,
V_70 ,
L_16 , V_4 ) ;
if ( error ) {
F_8 ( V_4 -> V_9 , L_17 , error ) ;
return error ;
}
V_4 -> V_16 [ 0 ] . V_71 = L_18 ;
V_4 -> V_16 [ 1 ] . V_71 = L_19 ;
error = F_42 ( V_60 ,
F_7 ( V_4 -> V_16 ) ,
V_4 -> V_16 ) ;
if ( error ) {
F_8 ( V_4 -> V_9 , L_20 , error ) ;
return error ;
}
if ( V_64 ) {
error = F_43 ( V_4 -> V_16 [ 0 ] . V_34 ,
V_64 , V_64 ) ;
if ( error ) {
F_8 ( V_4 -> V_9 , L_21 ,
error ) ;
return error ;
}
}
if ( V_65 ) {
error = F_43 ( V_4 -> V_16 [ 1 ] . V_34 ,
V_65 , V_65 ) ;
if ( error ) {
F_8 ( V_4 -> V_9 , L_22 ,
error ) ;
return error ;
}
}
F_44 ( & V_4 -> V_45 , F_18 ) ;
V_4 -> V_48 = F_45 ( & V_59 -> V_9 ) ;
if ( ! V_4 -> V_48 ) {
F_8 ( V_4 -> V_9 , L_23 ) ;
return - V_69 ;
}
F_46 ( V_4 -> V_48 , V_4 ) ;
V_4 -> V_48 -> V_72 = L_24 ;
V_4 -> V_48 -> V_73 . V_74 = 1 ;
V_4 -> V_48 -> V_75 = F_27 ;
F_47 ( V_76 , V_4 -> V_48 -> V_77 ) ;
error = F_48 ( V_4 -> V_48 , NULL , F_24 ) ;
if ( error ) {
F_8 ( V_4 -> V_9 , L_25 ) ;
return error ;
}
error = F_49 ( V_4 -> V_48 ) ;
if ( error ) {
F_8 ( V_4 -> V_9 , L_26 ) ;
return error ;
}
F_50 ( V_59 , V_4 ) ;
return 0 ;
}
