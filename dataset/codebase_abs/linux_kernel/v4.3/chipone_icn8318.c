static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_1 V_5 = V_6 ;
struct V_7 V_8 [ 2 ] = {
{
. V_9 = V_2 -> V_9 ,
. V_10 = 1 ,
. V_11 = & V_5
} ,
{
. V_9 = V_2 -> V_9 ,
. V_12 = V_13 ,
. V_10 = sizeof( struct V_3 ) ,
. V_11 = ( T_1 * ) V_4
}
} ;
return F_2 ( V_2 -> V_14 , V_8 , 2 ) ;
}
static inline bool F_3 ( T_1 V_15 )
{
return ( V_15 == V_16 ) ||
( V_15 == V_17 ) ;
}
static T_2 F_4 ( int V_18 , void * V_19 )
{
struct V_20 * V_21 = V_19 ;
struct V_22 * V_23 = & V_21 -> V_2 -> V_23 ;
struct V_3 V_4 ;
int V_24 , V_25 , V_26 , V_27 ;
V_25 = F_1 ( V_21 -> V_2 , & V_4 ) ;
if ( V_25 < 0 ) {
F_5 ( V_23 , L_1 , V_25 ) ;
return V_28 ;
}
if ( V_4 . V_29 ) {
return V_28 ;
}
if ( V_4 . V_30 > V_31 ) {
F_6 ( V_23 , L_2 ,
V_4 . V_30 , V_31 ) ;
V_4 . V_30 = V_31 ;
}
for ( V_24 = 0 ; V_24 < V_4 . V_30 ; V_24 ++ ) {
struct V_32 * V_33 = & V_4 . V_34 [ V_24 ] ;
bool V_35 = F_3 ( V_33 -> V_15 ) ;
F_7 ( V_21 -> V_36 , V_33 -> V_37 ) ;
F_8 ( V_21 -> V_36 , V_38 , V_35 ) ;
if ( ! V_35 )
continue;
V_26 = F_9 ( V_33 -> V_26 ) ;
V_27 = F_9 ( V_33 -> V_27 ) ;
if ( V_21 -> V_39 )
V_26 = V_21 -> V_40 - V_26 ;
if ( V_21 -> V_41 )
V_27 = V_21 -> V_42 - V_27 ;
if ( ! V_21 -> V_43 ) {
F_10 ( V_21 -> V_36 , V_44 , V_45 , V_26 ) ;
F_10 ( V_21 -> V_36 , V_44 , V_46 , V_27 ) ;
} else {
F_10 ( V_21 -> V_36 , V_44 , V_45 , V_27 ) ;
F_10 ( V_21 -> V_36 , V_44 , V_46 , V_26 ) ;
}
}
F_11 ( V_21 -> V_36 ) ;
F_12 ( V_21 -> V_36 ) ;
return V_28 ;
}
static int F_13 ( struct V_47 * V_23 )
{
struct V_20 * V_21 = F_14 ( V_23 ) ;
F_15 ( V_21 -> V_2 -> V_18 ) ;
F_16 ( V_21 -> V_48 , 1 ) ;
return 0 ;
}
static void F_17 ( struct V_47 * V_23 )
{
struct V_20 * V_21 = F_14 ( V_23 ) ;
F_18 ( V_21 -> V_2 -> V_18 ) ;
F_19 ( V_21 -> V_2 , V_49 ,
V_50 ) ;
F_16 ( V_21 -> V_48 , 0 ) ;
}
static int F_20 ( struct V_22 * V_23 )
{
struct V_20 * V_21 = F_21 ( F_22 ( V_23 ) ) ;
F_23 ( & V_21 -> V_36 -> V_51 ) ;
if ( V_21 -> V_36 -> V_52 )
F_17 ( V_21 -> V_36 ) ;
F_24 ( & V_21 -> V_36 -> V_51 ) ;
return 0 ;
}
static int F_25 ( struct V_22 * V_23 )
{
struct V_20 * V_21 = F_21 ( F_22 ( V_23 ) ) ;
F_23 ( & V_21 -> V_36 -> V_51 ) ;
if ( V_21 -> V_36 -> V_52 )
F_13 ( V_21 -> V_36 ) ;
F_24 ( & V_21 -> V_36 -> V_51 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 ,
const struct V_53 * V_54 )
{
struct V_22 * V_23 = & V_2 -> V_23 ;
struct V_55 * V_56 = V_23 -> V_57 ;
struct V_20 * V_21 ;
struct V_47 * V_36 ;
T_3 V_58 = 0 , V_59 = 0 ;
int error ;
if ( ! V_2 -> V_18 ) {
F_5 ( V_23 , L_3 ) ;
return - V_60 ;
}
V_21 = F_27 ( V_23 , sizeof( * V_21 ) , V_61 ) ;
if ( ! V_21 )
return - V_62 ;
V_21 -> V_48 = F_28 ( V_23 , L_4 , V_63 ) ;
if ( F_29 ( V_21 -> V_48 ) ) {
error = F_30 ( V_21 -> V_48 ) ;
if ( error != - V_64 )
F_5 ( V_23 , L_5 , error ) ;
return error ;
}
if ( F_31 ( V_56 , L_6 , & V_21 -> V_40 ) ||
F_31 ( V_56 , L_7 , & V_21 -> V_42 ) ) {
F_5 ( V_23 , L_8 ) ;
return - V_60 ;
}
F_31 ( V_56 , L_9 , & V_58 ) ;
F_31 ( V_56 , L_10 , & V_59 ) ;
V_21 -> V_39 = F_32 ( V_56 , L_11 ) ;
V_21 -> V_41 = F_32 ( V_56 , L_12 ) ;
V_21 -> V_43 = F_32 ( V_56 , L_13 ) ;
V_36 = F_33 ( V_23 ) ;
if ( ! V_36 )
return - V_62 ;
V_36 -> V_65 = V_2 -> V_65 ;
V_36 -> V_54 . V_66 = V_67 ;
V_36 -> V_68 = F_13 ;
V_36 -> V_69 = F_17 ;
V_36 -> V_23 . V_70 = V_23 ;
if ( ! V_21 -> V_43 ) {
F_34 ( V_36 , V_45 , 0 ,
V_21 -> V_40 , V_58 , 0 ) ;
F_34 ( V_36 , V_46 , 0 ,
V_21 -> V_42 , V_59 , 0 ) ;
} else {
F_34 ( V_36 , V_45 , 0 ,
V_21 -> V_42 , V_59 , 0 ) ;
F_34 ( V_36 , V_46 , 0 ,
V_21 -> V_40 , V_58 , 0 ) ;
}
error = F_35 ( V_36 , V_31 ,
V_71 | V_72 ) ;
if ( error )
return error ;
V_21 -> V_2 = V_2 ;
V_21 -> V_36 = V_36 ;
F_36 ( V_36 , V_21 ) ;
error = F_37 ( V_23 , V_2 -> V_18 , NULL , F_4 ,
V_73 , V_2 -> V_65 , V_21 ) ;
if ( error ) {
F_5 ( V_23 , L_14 , error ) ;
return error ;
}
F_17 ( V_21 -> V_36 ) ;
error = F_38 ( V_36 ) ;
if ( error )
return error ;
F_39 ( V_2 , V_21 ) ;
return 0 ;
}
