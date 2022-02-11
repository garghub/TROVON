static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 ,
V_2 . V_2 ) ;
unsigned int V_5 ;
int V_6 = 0 ;
bool V_7 = true ;
int error ;
error = F_3 ( V_4 -> V_8 -> V_9 , V_10 , & V_5 ) ;
if ( error ) {
F_4 ( V_4 -> V_11 ,
L_1 , error ) ;
goto V_12;
}
if ( ! ( V_5 & V_13 ) ) {
error = F_5 ( V_4 -> V_8 -> V_9 ,
V_14 ,
V_15 , 0 ) ;
if ( error ) {
F_4 ( V_4 -> V_11 ,
L_2 , error ) ;
goto V_12;
}
F_6 ( V_4 -> V_16 , V_17 , 0 ) ;
F_7 ( V_4 -> V_16 ) ;
V_7 = false ;
}
error = F_3 ( V_4 -> V_8 -> V_9 ,
V_18 , & V_6 ) ;
if ( error ) {
F_8 ( & V_4 -> V_16 -> V_11 ,
L_3 , error ) ;
} else if ( V_6 & V_19 ) {
error = F_9 ( V_4 -> V_8 -> V_9 ,
V_18 ,
V_19 ) ;
if ( error ) {
F_8 ( & V_4 -> V_16 -> V_11 ,
L_4 ,
error ) ;
} else {
F_10 ( & V_4 -> V_16 -> V_11 ,
L_5 ) ;
error = F_9 ( V_4 -> V_8 -> V_9 ,
V_20 ,
V_21 ) ;
if ( error )
F_4 ( & V_4 -> V_16 -> V_11 ,
L_6 ,
error ) ;
}
}
V_12:
if ( V_7 )
F_11 ( & V_4 -> V_2 , F_12 ( 50 ) ) ;
}
static T_1 F_13 ( int V_22 , void * V_23 )
{
struct V_3 * V_4 = V_23 ;
unsigned int V_5 ;
int error ;
error = F_3 ( V_4 -> V_8 -> V_9 , V_10 , & V_5 ) ;
if ( V_4 -> V_24 && ! error && ( V_5 & V_13 ) ) {
F_6 ( V_4 -> V_16 , V_17 , 1 ) ;
F_7 ( V_4 -> V_16 ) ;
F_11 ( & V_4 -> V_2 , 0 ) ;
F_10 ( V_4 -> V_11 , L_7 ) ;
} else {
F_6 ( V_4 -> V_16 , V_25 , 1 ) ;
F_7 ( V_4 -> V_16 ) ;
F_6 ( V_4 -> V_16 , V_25 , 0 ) ;
F_7 ( V_4 -> V_16 ) ;
F_10 ( V_4 -> V_11 , L_8 ) ;
}
return V_26 ;
}
static void F_14 ( void * V_23 )
{
struct V_3 * V_4 = V_23 ;
F_15 ( & V_4 -> V_2 ) ;
}
static int F_16 ( struct V_27 * V_28 )
{
struct V_29 * V_29 = F_17 ( V_28 -> V_11 . V_30 ) ;
struct V_31 * V_32 = F_18 ( V_29 -> V_11 ) ;
struct V_3 * V_4 ;
int V_22 ;
int error ;
V_4 = F_19 ( & V_28 -> V_11 , sizeof( struct V_3 ) ,
V_33 ) ;
if ( ! V_4 ) {
F_4 ( & V_28 -> V_11 , L_9 ) ;
return - V_34 ;
}
V_4 -> V_11 = & V_28 -> V_11 ;
V_4 -> V_8 = V_29 ;
if ( V_32 )
V_4 -> V_24 = V_32 -> V_24 ;
else
V_4 -> V_24 =
! F_20 ( V_28 -> V_11 . V_35 ,
L_10 ) ;
V_4 -> V_16 = F_21 ( & V_28 -> V_11 ) ;
if ( ! V_4 -> V_16 ) {
F_4 ( & V_28 -> V_11 , L_11 ) ;
return - V_34 ;
}
V_4 -> V_16 -> V_36 = V_37 ;
V_4 -> V_16 -> V_38 = V_37 L_12 ;
V_4 -> V_16 -> V_11 . V_30 = & V_28 -> V_11 ;
if ( V_4 -> V_24 )
F_22 ( V_4 -> V_16 , V_39 , V_17 ) ;
F_22 ( V_4 -> V_16 , V_39 , V_25 ) ;
F_23 ( & V_4 -> V_2 , F_1 ) ;
error = F_24 ( & V_28 -> V_11 , F_14 , V_4 ) ;
if ( error ) {
F_4 ( & V_28 -> V_11 ,
L_13 ,
error ) ;
return error ;
}
V_22 = F_25 ( V_28 , L_14 ) ;
if ( V_22 < 0 ) {
error = V_22 ;
F_4 ( & V_28 -> V_11 , L_15 , error ) ;
return error ;
}
error = F_26 ( & V_28 -> V_11 , V_22 ,
NULL , F_13 ,
V_40 | V_41 ,
L_14 , V_4 ) ;
if ( error ) {
F_4 ( & V_28 -> V_11 ,
L_16 , V_22 , error ) ;
return error ;
}
error = F_27 ( V_4 -> V_16 ) ;
if ( error ) {
F_4 ( & V_28 -> V_11 ,
L_17 , error ) ;
return error ;
}
F_28 ( V_28 , V_4 ) ;
return 0 ;
}
