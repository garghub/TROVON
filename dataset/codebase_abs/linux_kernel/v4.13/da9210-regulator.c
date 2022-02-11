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
F_8 ( & V_6 -> V_2 -> V_23 ) ;
if ( V_18 & V_24 ) {
F_9 ( V_6 -> V_2 ,
V_25 ,
NULL ) ;
V_19 |= V_24 ;
}
if ( V_18 & V_26 ) {
F_9 ( V_6 -> V_2 ,
V_27 ,
NULL ) ;
V_19 |= V_26 ;
}
if ( V_18 & ( V_28 | V_29 ) ) {
F_9 ( V_6 -> V_2 ,
V_30 , NULL ) ;
V_19 |= V_18 & ( V_28 | V_29 ) ;
}
if ( V_18 & V_31 ) {
F_9 ( V_6 -> V_2 ,
V_32 ,
NULL ) ;
V_19 |= V_31 ;
}
F_10 ( & V_6 -> V_2 -> V_23 ) ;
if ( V_19 ) {
error = F_11 ( V_6 -> V_11 , V_21 , V_19 ) ;
if ( error < 0 )
goto V_22;
V_16 = V_33 ;
}
return V_16 ;
V_22:
F_12 ( F_13 ( V_6 -> V_11 ) , L_1 , error ) ;
return V_16 ;
}
static int F_14 ( struct V_34 * V_35 ,
const struct V_36 * V_37 )
{
struct V_5 * V_6 ;
struct V_38 * V_39 = & V_35 -> V_39 ;
struct V_40 * V_41 = F_15 ( V_39 ) ;
struct V_1 * V_2 = NULL ;
struct V_42 V_43 = { } ;
int error ;
const struct V_44 * V_45 ;
if ( V_35 -> V_39 . V_46 && ! V_41 ) {
V_45 = F_16 ( F_17 ( V_47 ) ,
& V_35 -> V_39 ) ;
if ( ! V_45 ) {
F_12 ( & V_35 -> V_39 , L_2 ) ;
return - V_48 ;
}
}
V_6 = F_18 ( & V_35 -> V_39 , sizeof( struct V_5 ) , V_49 ) ;
if ( ! V_6 )
return - V_50 ;
V_6 -> V_11 = F_19 ( V_35 , & V_51 ) ;
if ( F_20 ( V_6 -> V_11 ) ) {
error = F_21 ( V_6 -> V_11 ) ;
F_12 ( & V_35 -> V_39 , L_3 ,
error ) ;
return error ;
}
V_43 . V_39 = & V_35 -> V_39 ;
V_43 . V_52 = V_41 ? & V_41 -> V_53 :
F_22 ( V_39 , V_39 -> V_46 , & V_54 ) ;
V_43 . V_55 = V_6 ;
V_43 . V_11 = V_6 -> V_11 ;
V_43 . V_46 = V_39 -> V_46 ;
error = F_11 ( V_6 -> V_11 , V_56 , ~ 0 ) ;
if ( ! error )
error = F_11 ( V_6 -> V_11 , V_57 , ~ 0 ) ;
if ( error ) {
F_12 ( & V_35 -> V_39 , L_4 , error ) ;
return error ;
}
V_2 = F_23 ( & V_35 -> V_39 , & V_54 , & V_43 ) ;
if ( F_20 ( V_2 ) ) {
F_12 ( & V_35 -> V_39 , L_5 ) ;
return F_21 ( V_2 ) ;
}
V_6 -> V_2 = V_2 ;
if ( V_35 -> V_17 ) {
error = F_24 ( & V_35 -> V_39 , V_35 -> V_17 , NULL ,
F_7 ,
V_58 |
V_59 | V_60 ,
L_6 , V_6 ) ;
if ( error ) {
F_12 ( & V_35 -> V_39 , L_7 ,
V_35 -> V_17 , error ) ;
return error ;
}
error = F_4 ( V_6 -> V_11 , V_57 ,
V_61 | V_62 |
V_63 |
V_64 | V_65 , 0 ) ;
if ( error < 0 ) {
F_12 ( & V_35 -> V_39 , L_8 ,
error ) ;
return error ;
}
} else {
F_25 ( & V_35 -> V_39 , L_9 ) ;
}
F_26 ( V_35 , V_6 ) ;
return 0 ;
}
