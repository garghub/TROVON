static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 , void * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 ,
V_7 ) ;
unsigned int V_8 ;
unsigned int V_9 ;
int error ;
if ( V_6 -> V_10 == 0 )
V_8 = V_11 ;
else
V_8 = V_12 ;
error = F_3 ( V_6 -> V_13 ,
V_6 -> V_14 + V_8 ,
V_15 ,
0 ) ;
if ( error )
F_4 ( V_6 -> V_16 ,
L_1 ,
error ) ;
F_5 ( 100 , 1000 ) ;
switch ( V_3 ) {
case V_17 :
case V_18 :
V_9 = V_19 ;
break;
case V_20 :
default:
V_9 = V_21 ;
break;
}
error = F_3 ( V_6 -> V_13 ,
V_6 -> V_14 + V_11 ,
V_22 ,
V_9 ) ;
if ( error )
F_4 ( V_6 -> V_16 , L_2 ,
error ) ;
error = F_3 ( V_6 -> V_13 ,
V_6 -> V_14 + V_8 ,
V_15 ,
V_15 ) ;
if ( error )
F_4 ( V_6 -> V_16 , L_3 , error ) ;
return V_23 ;
}
static T_1 F_6 ( int V_24 , void * V_25 )
{
struct V_5 * V_6 = V_25 ;
unsigned int V_26 ;
int error ;
error = F_7 ( V_6 -> V_13 ,
V_6 -> V_14 + V_27 , & V_26 ) ;
if ( error )
return V_28 ;
F_8 ( V_6 -> V_29 , V_30 , ! ! ( V_26 & V_31 ) ) ;
F_9 ( V_6 -> V_29 ) ;
return V_28 ;
}
static int T_2 F_10 ( struct V_32 * V_16 )
{
struct V_5 * V_6 = F_11 ( V_16 ) ;
if ( F_12 ( V_16 ) )
F_13 ( V_6 -> V_24 ) ;
return 0 ;
}
static int T_2 F_14 ( struct V_32 * V_16 )
{
struct V_5 * V_6 = F_11 ( V_16 ) ;
if ( F_12 ( V_16 ) )
F_15 ( V_6 -> V_24 ) ;
return 0 ;
}
static int F_16 ( struct V_33 * V_34 )
{
struct V_5 * V_6 ;
bool V_35 ;
T_3 V_36 ;
int error ;
if ( F_17 ( V_34 -> V_16 . V_37 , L_4 , & V_36 ) )
V_36 = 15625 ;
if ( V_36 > 2000000 || V_36 == 0 ) {
F_4 ( & V_34 -> V_16 , L_5 , V_36 ) ;
return - V_38 ;
}
V_35 = F_18 ( V_34 -> V_16 . V_37 , L_6 ) ;
V_6 = F_19 ( & V_34 -> V_16 , sizeof( * V_6 ) , V_39 ) ;
if ( ! V_6 )
return - V_40 ;
V_6 -> V_16 = & V_34 -> V_16 ;
V_6 -> V_13 = F_20 ( V_34 -> V_16 . V_41 , NULL ) ;
if ( ! V_6 -> V_13 ) {
F_4 ( & V_34 -> V_16 , L_7 ) ;
return - V_42 ;
}
V_6 -> V_24 = F_21 ( V_34 , 0 ) ;
if ( V_6 -> V_24 < 0 ) {
F_4 ( & V_34 -> V_16 , L_8 ) ;
return V_6 -> V_24 ;
}
error = F_17 ( V_34 -> V_16 . V_37 , L_9 ,
& V_6 -> V_14 ) ;
if ( error )
return error ;
error = F_7 ( V_6 -> V_13 , V_6 -> V_14 + V_43 ,
& V_6 -> V_10 ) ;
if ( error ) {
F_4 ( & V_34 -> V_16 , L_10 , error ) ;
return error ;
}
V_6 -> V_29 = F_22 ( & V_34 -> V_16 ) ;
if ( ! V_6 -> V_29 ) {
F_23 ( & V_34 -> V_16 , L_11 ) ;
return - V_40 ;
}
F_24 ( V_6 -> V_29 , V_44 , V_30 ) ;
V_6 -> V_29 -> V_45 = L_12 ;
V_6 -> V_29 -> V_46 = L_13 ;
V_36 = ( V_36 << 6 ) / V_47 ;
V_36 = F_25 ( V_36 ) ;
error = F_3 ( V_6 -> V_13 ,
V_6 -> V_14 + V_48 ,
V_49 ,
V_36 ) ;
if ( error ) {
F_4 ( & V_34 -> V_16 , L_10 , error ) ;
return error ;
}
error = F_3 ( V_6 -> V_13 ,
V_6 -> V_14 + V_50 ,
V_51 ,
V_35 ? V_51 : 0 ) ;
if ( error ) {
F_4 ( & V_34 -> V_16 , L_14 , error ) ;
return error ;
}
error = F_26 ( & V_34 -> V_16 , V_6 -> V_24 ,
NULL , F_6 ,
V_52 ,
L_12 , V_6 ) ;
if ( error ) {
F_4 ( & V_34 -> V_16 , L_15 , error ) ;
return error ;
}
error = F_27 ( V_6 -> V_29 ) ;
if ( error ) {
F_4 ( & V_34 -> V_16 , L_16 ,
error ) ;
return error ;
}
V_6 -> V_7 . V_53 = F_1 ,
error = F_28 ( & V_6 -> V_7 ) ;
if ( error ) {
F_4 ( & V_34 -> V_16 , L_17 ,
error ) ;
return error ;
}
F_29 ( V_34 , V_6 ) ;
F_30 ( & V_34 -> V_16 , 1 ) ;
return 0 ;
}
static int F_31 ( struct V_33 * V_34 )
{
struct V_5 * V_6 = F_32 ( V_34 ) ;
F_30 ( & V_34 -> V_16 , 0 ) ;
F_33 ( & V_6 -> V_7 ) ;
return 0 ;
}
