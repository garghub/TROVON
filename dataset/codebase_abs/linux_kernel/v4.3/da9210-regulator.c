static int F_1 ( struct V_1 * V_2 , int V_3 ,
int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_7 ;
int V_8 ;
for ( V_8 = F_3 ( V_9 ) - 1 ; V_8 >= 0 ; V_8 -- ) {
if ( V_3 <= V_9 [ V_8 ] &&
V_4 >= V_9 [ V_8 ] ) {
V_7 = V_8 ;
V_7 = V_7 << V_10 ;
return F_4 ( V_6 -> V_11 ,
V_12 ,
V_13 , V_7 ) ;
}
}
return - V_14 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_15 ;
unsigned int V_7 ;
int V_16 ;
V_16 = F_6 ( V_6 -> V_11 , V_12 , & V_15 ) ;
if ( V_16 < 0 )
return V_16 ;
V_7 = ( V_15 & V_13 ) >> V_10 ;
return V_9 [ V_7 ] ;
}
static T_1 F_7 ( int V_17 , void * V_15 )
{
struct V_5 * V_6 = V_15 ;
unsigned int V_18 , V_19 = 0 ;
int error , V_16 = V_20 ;
error = F_6 ( V_6 -> V_11 , V_21 , & V_18 ) ;
if ( error < 0 )
goto V_22;
if ( V_18 & V_23 ) {
F_8 ( V_6 -> V_2 ,
V_24 ,
NULL ) ;
V_19 |= V_23 ;
}
if ( V_18 & V_25 ) {
F_8 ( V_6 -> V_2 ,
V_26 ,
NULL ) ;
V_19 |= V_25 ;
}
if ( V_18 & ( V_27 | V_28 ) ) {
F_8 ( V_6 -> V_2 ,
V_29 , NULL ) ;
V_19 |= V_18 & ( V_27 | V_28 ) ;
}
if ( V_18 & V_30 ) {
F_8 ( V_6 -> V_2 ,
V_31 ,
NULL ) ;
V_19 |= V_30 ;
}
if ( V_19 ) {
error = F_9 ( V_6 -> V_11 , V_21 , V_19 ) ;
if ( error < 0 )
goto V_22;
V_16 = V_32 ;
}
return V_16 ;
V_22:
F_10 ( F_11 ( V_6 -> V_11 ) , L_1 , error ) ;
return V_16 ;
}
static int F_12 ( struct V_33 * V_34 ,
const struct V_35 * V_36 )
{
struct V_5 * V_6 ;
struct V_37 * V_38 = & V_34 -> V_38 ;
struct V_39 * V_40 = F_13 ( V_38 ) ;
struct V_1 * V_2 = NULL ;
struct V_41 V_42 = { } ;
int error ;
V_6 = F_14 ( & V_34 -> V_38 , sizeof( struct V_5 ) , V_43 ) ;
if ( ! V_6 )
return - V_44 ;
V_6 -> V_11 = F_15 ( V_34 , & V_45 ) ;
if ( F_16 ( V_6 -> V_11 ) ) {
error = F_17 ( V_6 -> V_11 ) ;
F_10 ( & V_34 -> V_38 , L_2 ,
error ) ;
return error ;
}
V_42 . V_38 = & V_34 -> V_38 ;
V_42 . V_46 = V_40 ? & V_40 -> V_47 :
F_18 ( V_38 , V_38 -> V_48 , & V_49 ) ;
V_42 . V_50 = V_6 ;
V_42 . V_11 = V_6 -> V_11 ;
V_42 . V_48 = V_38 -> V_48 ;
error = F_9 ( V_6 -> V_11 , V_51 , ~ 0 ) ;
if ( ! error )
error = F_9 ( V_6 -> V_11 , V_52 , ~ 0 ) ;
if ( error ) {
F_10 ( & V_34 -> V_38 , L_3 , error ) ;
return error ;
}
V_2 = F_19 ( & V_34 -> V_38 , & V_49 , & V_42 ) ;
if ( F_16 ( V_2 ) ) {
F_10 ( & V_34 -> V_38 , L_4 ) ;
return F_17 ( V_2 ) ;
}
V_6 -> V_2 = V_2 ;
if ( V_34 -> V_17 ) {
error = F_20 ( & V_34 -> V_38 , V_34 -> V_17 , NULL ,
F_7 ,
V_53 |
V_54 | V_55 ,
L_5 , V_6 ) ;
if ( error ) {
F_10 ( & V_34 -> V_38 , L_6 ,
V_34 -> V_17 , error ) ;
return error ;
}
error = F_4 ( V_6 -> V_11 , V_52 ,
V_56 | V_57 |
V_58 |
V_59 | V_60 , 0 ) ;
if ( error < 0 ) {
F_10 ( & V_34 -> V_38 , L_7 ,
error ) ;
return error ;
}
} else {
F_21 ( & V_34 -> V_38 , L_8 ) ;
}
F_22 ( V_34 , V_6 ) ;
return 0 ;
}
