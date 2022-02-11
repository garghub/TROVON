static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ,
struct V_3 ,
V_2 . V_2 ) ;
const struct V_5 * V_6 = V_4 -> V_6 ;
unsigned int V_7 ;
int V_8 = 0 ;
bool V_9 = true ;
int error ;
error = F_3 ( V_4 -> V_10 ,
V_6 -> V_11 ,
& V_7 ) ;
if ( error ) {
F_4 ( V_4 -> V_12 ,
L_1 , error ) ;
goto V_13;
}
if ( ! ( V_7 & V_6 -> V_14 ) ) {
error = F_5 ( V_4 -> V_10 ,
V_6 -> V_15 ,
V_6 -> V_16 ,
0 ) ;
if ( error ) {
F_4 ( V_4 -> V_12 ,
L_2 , error ) ;
goto V_13;
}
F_6 ( V_4 -> V_17 , V_18 , 0 ) ;
F_7 ( V_4 -> V_17 ) ;
V_9 = false ;
}
error = F_3 ( V_4 -> V_10 ,
V_6 -> V_19 ,
& V_8 ) ;
if ( error ) {
F_8 ( & V_4 -> V_17 -> V_12 ,
L_3 , error ) ;
} else if ( V_8 & V_6 -> V_20 ) {
error = F_9 ( V_4 -> V_10 ,
V_6 -> V_19 ,
V_6 -> V_20 ) ;
if ( error ) {
F_8 ( & V_4 -> V_17 -> V_12 ,
L_4 ,
error ) ;
} else {
F_10 ( & V_4 -> V_17 -> V_12 ,
L_5 ) ;
error = F_9 ( V_4 -> V_10 ,
V_6 -> V_21 ,
V_6 -> V_22 ) ;
if ( error )
F_4 ( & V_4 -> V_17 -> V_12 ,
L_6 ,
error ) ;
}
}
V_13:
if ( V_9 )
F_11 ( & V_4 -> V_2 , F_12 ( 50 ) ) ;
}
static T_1 F_13 ( int V_23 , void * V_24 )
{
struct V_3 * V_4 = V_24 ;
const struct V_5 * V_6 = V_4 -> V_6 ;
unsigned int V_7 ;
int error ;
error = F_3 ( V_4 -> V_10 ,
V_6 -> V_11 ,
& V_7 ) ;
if ( V_4 -> V_25 && ! error && ( V_7 & V_6 -> V_14 ) ) {
F_6 ( V_4 -> V_17 , V_18 , 1 ) ;
F_7 ( V_4 -> V_17 ) ;
F_11 ( & V_4 -> V_2 , 0 ) ;
F_10 ( V_4 -> V_12 , L_7 ) ;
} else {
F_6 ( V_4 -> V_17 , V_18 , 1 ) ;
F_7 ( V_4 -> V_17 ) ;
F_6 ( V_4 -> V_17 , V_18 , 0 ) ;
F_7 ( V_4 -> V_17 ) ;
F_10 ( V_4 -> V_12 , L_8 ) ;
}
return V_26 ;
}
static void F_14 ( void * V_24 )
{
struct V_3 * V_4 = V_24 ;
F_15 ( & V_4 -> V_2 ) ;
}
static int F_16 ( struct V_27 * V_28 )
{
struct V_29 * V_29 = F_17 ( V_28 -> V_12 . V_30 ) ;
struct V_31 * V_32 = F_18 ( V_29 -> V_12 ) ;
struct V_3 * V_4 ;
const struct V_33 * V_34 ;
int V_23 ;
int error ;
V_34 = F_19 ( V_35 ,
V_28 -> V_12 . V_36 ) ;
if ( ! V_34 )
return - V_37 ;
V_4 = F_20 ( & V_28 -> V_12 , sizeof( struct V_3 ) ,
V_38 ) ;
if ( ! V_4 ) {
F_4 ( & V_28 -> V_12 , L_9 ) ;
return - V_39 ;
}
V_4 -> V_6 = V_34 -> V_24 ;
V_4 -> V_12 = & V_28 -> V_12 ;
V_4 -> V_10 = F_21 ( V_28 -> V_12 . V_30 , NULL ) ;
if ( ! V_4 -> V_10 ) {
F_4 ( & V_28 -> V_12 , L_10 ) ;
return - V_37 ;
}
if ( V_32 )
V_4 -> V_25 = V_32 -> V_25 ;
else
V_4 -> V_25 =
! F_22 ( V_28 -> V_12 . V_36 ,
L_11 ) ;
V_4 -> V_17 = F_23 ( & V_28 -> V_12 ) ;
if ( ! V_4 -> V_17 ) {
F_4 ( & V_28 -> V_12 , L_12 ) ;
return - V_39 ;
}
V_4 -> V_17 -> V_40 = V_4 -> V_6 -> V_40 ;
snprintf ( V_4 -> V_41 , sizeof( V_4 -> V_41 ) , L_13 ,
V_4 -> V_6 -> V_40 ) ;
V_4 -> V_17 -> V_41 = V_4 -> V_41 ;
V_4 -> V_17 -> V_12 . V_30 = & V_28 -> V_12 ;
if ( V_4 -> V_25 )
F_24 ( V_4 -> V_17 , V_42 , V_18 ) ;
F_24 ( V_4 -> V_17 , V_42 , V_43 ) ;
F_25 ( & V_4 -> V_2 , F_1 ) ;
error = F_26 ( & V_28 -> V_12 , F_14 , V_4 ) ;
if ( error ) {
F_4 ( & V_28 -> V_12 ,
L_14 ,
error ) ;
return error ;
}
V_23 = F_27 ( V_28 , L_15 ) ;
if ( V_23 < 0 ) {
error = V_23 ;
F_4 ( & V_28 -> V_12 , L_16 , error ) ;
return error ;
}
error = F_28 ( & V_28 -> V_12 , V_23 ,
NULL , F_13 ,
V_44 | V_45 ,
L_15 , V_4 ) ;
if ( error ) {
F_4 ( & V_28 -> V_12 ,
L_17 , V_23 , error ) ;
return error ;
}
error = F_29 ( V_4 -> V_17 ) ;
if ( error ) {
F_4 ( & V_28 -> V_12 ,
L_18 , error ) ;
return error ;
}
F_30 ( V_28 , V_4 ) ;
return 0 ;
}
