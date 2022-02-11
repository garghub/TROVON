static int F_1 ( unsigned int V_1 )
{
return ( V_1 * 255 / 5600 ) ;
}
static void F_2 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_3 ( V_3 , struct V_4 , V_3 ) ;
int error ;
F_4 ( V_5 -> V_6 , 1 ) ;
F_5 ( 250 ) ;
error = F_6 ( V_5 -> V_7 ,
V_8 , V_9 ) ;
if ( error ) {
F_7 ( & V_5 -> V_10 -> V_11 ,
L_1 , error ) ;
} else {
error = F_6 ( V_5 -> V_7 ,
V_12 , V_5 -> V_13 ) ;
if ( error )
F_7 ( & V_5 -> V_10 -> V_11 ,
L_2 , error ) ;
}
}
static int F_8 ( struct V_14 * V_15 , void * V_16 ,
struct V_17 * V_18 )
{
struct V_4 * V_5 = F_9 ( V_15 ) ;
V_5 -> V_19 = V_20 ;
if ( V_18 -> V_21 . V_22 . V_23 > 0 )
V_5 -> V_13 = V_18 -> V_21 . V_22 . V_23 ;
else if ( V_18 -> V_21 . V_22 . V_24 > 0 )
V_5 -> V_13 = V_18 -> V_21 . V_22 . V_24 ;
else
V_5 -> V_13 = 0 ;
F_10 ( & V_5 -> V_3 ) ;
return 0 ;
}
static void F_11 ( struct V_14 * V_15 )
{
struct V_4 * V_5 = F_9 ( V_15 ) ;
int error ;
F_12 ( & V_5 -> V_3 ) ;
error = F_6 ( V_5 -> V_7 , V_8 , V_25 ) ;
if ( error )
F_7 ( & V_5 -> V_10 -> V_11 ,
L_3 , error ) ;
F_4 ( V_5 -> V_6 , 0 ) ;
}
static int F_13 ( struct V_4 * V_5 )
{
int error ;
unsigned int V_26 ;
error = F_6 ( V_5 -> V_7 ,
V_27 , V_5 -> V_28 ) ;
if ( error ) {
F_7 ( & V_5 -> V_10 -> V_11 ,
L_4 ,
error ) ;
return error ;
}
error = F_6 ( V_5 -> V_7 ,
V_29 , V_5 -> V_30 ) ;
if ( error ) {
F_7 ( & V_5 -> V_10 -> V_11 ,
L_5 ,
error ) ;
return error ;
}
switch ( V_5 -> V_19 ) {
case V_31 :
error = F_14 ( V_5 -> V_7 ,
V_32 ,
F_15 ( V_32 ) ) ;
if ( error ) {
F_7 ( & V_5 -> V_10 -> V_11 ,
L_6 ,
error ) ;
return error ;
}
break;
case V_33 :
error = F_14 ( V_5 -> V_7 ,
V_34 ,
F_15 ( V_34 ) ) ;
if ( error ) {
F_7 ( & V_5 -> V_10 -> V_11 ,
L_7 ,
error ) ;
return error ;
}
error = F_16 ( V_5 -> V_7 , V_35 ,
V_36 ,
V_5 -> V_37 ) ;
if ( error ) {
F_7 ( & V_5 -> V_10 -> V_11 ,
L_8 ,
error ) ;
return error ;
}
break;
default:
error = F_14 ( V_5 -> V_7 ,
V_38 ,
F_15 ( V_38 ) ) ;
if ( error ) {
F_7 ( & V_5 -> V_10 -> V_11 ,
L_9 ,
error ) ;
return error ;
}
error = F_16 ( V_5 -> V_7 , V_35 ,
V_36 ,
V_5 -> V_37 ) ;
if ( error ) {
F_7 ( & V_5 -> V_10 -> V_11 ,
L_8 ,
error ) ;
return error ;
}
return 0 ;
}
error = F_6 ( V_5 -> V_7 , V_39 , V_40 ) ;
if ( error ) {
F_7 ( & V_5 -> V_10 -> V_11 ,
L_10 ,
error ) ;
return error ;
}
do {
error = F_17 ( V_5 -> V_7 , V_39 , & V_26 ) ;
if ( error ) {
F_7 ( & V_5 -> V_10 -> V_11 ,
L_11 ,
error ) ;
return error ;
}
} while ( V_26 == V_40 );
return 0 ;
}
static int F_18 ( struct V_41 * V_10 ,
const struct V_42 * V_43 )
{
struct V_44 * V_11 = & V_10 -> V_11 ;
struct V_4 * V_5 ;
T_1 V_1 ;
int error ;
V_5 = F_19 ( V_11 , sizeof( * V_5 ) , V_45 ) ;
if ( ! V_5 )
return - V_46 ;
error = F_20 ( V_11 , L_12 , & V_5 -> V_19 ) ;
if ( error ) {
F_7 ( V_11 , L_13 , error ) ;
return error ;
}
if ( V_5 -> V_19 < V_31 ||
V_5 -> V_19 > V_33 ) {
F_7 ( V_11 , L_14 , V_5 -> V_19 ) ;
return - V_47 ;
}
error = F_20 ( V_11 , L_15 , & V_5 -> V_37 ) ;
if ( error ) {
F_7 ( V_11 , L_16 , error ) ;
return error ;
}
if ( V_5 -> V_37 < V_48 ||
V_5 -> V_37 > V_49 ) {
F_7 ( V_11 ,
L_17 , V_5 -> V_37 ) ;
return - V_47 ;
}
if ( V_5 -> V_19 == V_31 &&
V_5 -> V_37 != V_48 &&
V_5 -> V_37 != V_50 ) {
F_7 ( V_11 , L_18 ) ;
return - V_47 ;
}
if ( V_5 -> V_19 == V_33 &&
( V_5 -> V_37 == V_48 ||
V_5 -> V_37 == V_50 ) ) {
F_7 ( V_11 , L_19 ) ;
return - V_47 ;
}
error = F_20 ( V_11 , L_20 , & V_1 ) ;
V_5 -> V_28 = error ? V_51 :
F_1 ( V_1 ) ;
error = F_20 ( V_11 , L_21 , & V_1 ) ;
V_5 -> V_30 = error ? V_52 :
F_1 ( V_1 ) ;
V_5 -> V_53 = F_21 ( V_11 , L_22 ) ;
if ( F_22 ( V_5 -> V_53 ) ) {
error = F_23 ( V_5 -> V_53 ) ;
F_7 ( V_11 , L_23 , error ) ;
return error ;
}
V_5 -> V_6 = F_24 ( V_11 , L_24 ,
V_54 ) ;
if ( F_22 ( V_5 -> V_6 ) )
return F_23 ( V_5 -> V_6 ) ;
V_5 -> V_14 = F_25 ( V_11 ) ;
if ( ! V_5 -> V_14 ) {
F_7 ( V_11 , L_25 ) ;
return - V_46 ;
}
V_5 -> V_14 -> V_55 = L_26 ;
V_5 -> V_14 -> V_56 = F_11 ;
F_26 ( V_5 -> V_14 , V_5 ) ;
F_27 ( V_5 -> V_14 , V_57 , V_58 ) ;
error = F_28 ( V_5 -> V_14 , NULL ,
F_8 ) ;
if ( error ) {
F_7 ( V_11 , L_27 , error ) ;
return error ;
}
F_29 ( & V_5 -> V_3 , F_2 ) ;
V_5 -> V_10 = V_10 ;
F_30 ( V_10 , V_5 ) ;
V_5 -> V_7 = F_31 ( V_10 , & V_59 ) ;
if ( F_22 ( V_5 -> V_7 ) ) {
error = F_23 ( V_5 -> V_7 ) ;
F_7 ( V_11 , L_28 , error ) ;
return error ;
}
error = F_13 ( V_5 ) ;
if ( error ) {
F_7 ( V_11 , L_29 , error ) ;
return error ;
}
error = F_32 ( V_5 -> V_14 ) ;
if ( error ) {
F_7 ( V_11 , L_30 , error ) ;
return error ;
}
return 0 ;
}
static int T_2 F_33 ( struct V_44 * V_11 )
{
struct V_4 * V_5 = F_34 ( V_11 ) ;
int V_60 = 0 ;
F_35 ( & V_5 -> V_14 -> V_61 ) ;
if ( V_5 -> V_14 -> V_62 ) {
V_60 = F_16 ( V_5 -> V_7 ,
V_8 ,
V_63 ,
V_25 ) ;
if ( V_60 ) {
F_7 ( V_11 , L_31 ) ;
goto V_64;
}
F_4 ( V_5 -> V_6 , 0 ) ;
V_60 = F_36 ( V_5 -> V_53 ) ;
if ( V_60 ) {
F_7 ( V_11 , L_32 ) ;
F_16 ( V_5 -> V_7 ,
V_8 ,
V_63 , 0 ) ;
}
}
V_64:
F_37 ( & V_5 -> V_14 -> V_61 ) ;
return V_60 ;
}
static int T_2 F_38 ( struct V_44 * V_11 )
{
struct V_4 * V_5 = F_34 ( V_11 ) ;
int V_60 = 0 ;
F_35 ( & V_5 -> V_14 -> V_61 ) ;
if ( V_5 -> V_14 -> V_62 ) {
V_60 = F_39 ( V_5 -> V_53 ) ;
if ( V_60 ) {
F_7 ( V_11 , L_33 ) ;
goto V_64;
}
V_60 = F_16 ( V_5 -> V_7 ,
V_8 ,
V_63 , 0 ) ;
if ( V_60 ) {
F_7 ( V_11 , L_34 ) ;
F_36 ( V_5 -> V_53 ) ;
goto V_64;
}
F_4 ( V_5 -> V_6 , 1 ) ;
}
V_64:
F_37 ( & V_5 -> V_14 -> V_61 ) ;
return V_60 ;
}
