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
int V_24 , V_25 ;
V_25 = F_1 ( V_21 -> V_2 , & V_4 ) ;
if ( V_25 < 0 ) {
F_5 ( V_23 , L_1 , V_25 ) ;
return V_26 ;
}
if ( V_4 . V_27 ) {
return V_26 ;
}
if ( V_4 . V_28 > V_29 ) {
F_6 ( V_23 , L_2 ,
V_4 . V_28 , V_29 ) ;
V_4 . V_28 = V_29 ;
}
for ( V_24 = 0 ; V_24 < V_4 . V_28 ; V_24 ++ ) {
struct V_30 * V_31 = & V_4 . V_32 [ V_24 ] ;
bool V_33 = F_3 ( V_31 -> V_15 ) ;
F_7 ( V_21 -> V_34 , V_31 -> V_35 ) ;
F_8 ( V_21 -> V_34 , V_36 , V_33 ) ;
if ( ! V_33 )
continue;
F_9 ( V_21 -> V_34 , & V_21 -> V_37 ,
F_10 ( V_31 -> V_38 ) ,
F_10 ( V_31 -> V_39 ) , true ) ;
}
F_11 ( V_21 -> V_34 ) ;
F_12 ( V_21 -> V_34 ) ;
return V_26 ;
}
static int F_13 ( struct V_40 * V_23 )
{
struct V_20 * V_21 = F_14 ( V_23 ) ;
F_15 ( V_21 -> V_2 -> V_18 ) ;
F_16 ( V_21 -> V_41 , 1 ) ;
return 0 ;
}
static void F_17 ( struct V_40 * V_23 )
{
struct V_20 * V_21 = F_14 ( V_23 ) ;
F_18 ( V_21 -> V_2 -> V_18 ) ;
F_19 ( V_21 -> V_2 , V_42 ,
V_43 ) ;
F_16 ( V_21 -> V_41 , 0 ) ;
}
static int F_20 ( struct V_22 * V_23 )
{
struct V_20 * V_21 = F_21 ( F_22 ( V_23 ) ) ;
F_23 ( & V_21 -> V_34 -> V_44 ) ;
if ( V_21 -> V_34 -> V_45 )
F_17 ( V_21 -> V_34 ) ;
F_24 ( & V_21 -> V_34 -> V_44 ) ;
return 0 ;
}
static int F_25 ( struct V_22 * V_23 )
{
struct V_20 * V_21 = F_21 ( F_22 ( V_23 ) ) ;
F_23 ( & V_21 -> V_34 -> V_44 ) ;
if ( V_21 -> V_34 -> V_45 )
F_13 ( V_21 -> V_34 ) ;
F_24 ( & V_21 -> V_34 -> V_44 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 ,
const struct V_46 * V_47 )
{
struct V_22 * V_23 = & V_2 -> V_23 ;
struct V_20 * V_21 ;
struct V_40 * V_34 ;
int error ;
if ( ! V_2 -> V_18 ) {
F_5 ( V_23 , L_3 ) ;
return - V_48 ;
}
V_21 = F_27 ( V_23 , sizeof( * V_21 ) , V_49 ) ;
if ( ! V_21 )
return - V_50 ;
V_21 -> V_41 = F_28 ( V_23 , L_4 , V_51 ) ;
if ( F_29 ( V_21 -> V_41 ) ) {
error = F_30 ( V_21 -> V_41 ) ;
if ( error != - V_52 )
F_5 ( V_23 , L_5 , error ) ;
return error ;
}
V_34 = F_31 ( V_23 ) ;
if ( ! V_34 )
return - V_50 ;
V_34 -> V_53 = V_2 -> V_53 ;
V_34 -> V_47 . V_54 = V_55 ;
V_34 -> V_56 = F_13 ;
V_34 -> V_57 = F_17 ;
V_34 -> V_23 . V_58 = V_23 ;
F_32 ( V_34 , V_59 , V_60 ) ;
F_32 ( V_34 , V_59 , V_61 ) ;
F_33 ( V_34 , true , & V_21 -> V_37 ) ;
if ( ! F_34 ( V_34 , V_60 ) ||
! F_34 ( V_34 , V_61 ) ) {
F_5 ( V_23 , L_6 ) ;
return - V_48 ;
}
error = F_35 ( V_34 , V_29 ,
V_62 | V_63 ) ;
if ( error )
return error ;
V_21 -> V_2 = V_2 ;
V_21 -> V_34 = V_34 ;
F_36 ( V_34 , V_21 ) ;
error = F_37 ( V_23 , V_2 -> V_18 , NULL , F_4 ,
V_64 , V_2 -> V_53 , V_21 ) ;
if ( error ) {
F_5 ( V_23 , L_7 , error ) ;
return error ;
}
F_17 ( V_21 -> V_34 ) ;
error = F_38 ( V_34 ) ;
if ( error )
return error ;
F_39 ( V_2 , V_21 ) ;
return 0 ;
}
