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
static int F_18 ( struct V_41 * V_11 ,
struct V_4 * V_5 )
{
struct V_42 * V_43 = V_11 -> V_44 ;
unsigned int V_1 ;
int error ;
error = F_19 ( V_43 , L_12 , & V_5 -> V_19 ) ;
if ( error ) {
F_7 ( V_11 , L_13 , V_45 ) ;
return error ;
}
error = F_19 ( V_43 , L_14 , & V_5 -> V_37 ) ;
if ( error ) {
F_7 ( V_11 , L_15 ,
V_45 ) ;
return error ;
}
error = F_19 ( V_43 , L_16 , & V_1 ) ;
if ( ! error )
V_5 -> V_28 = F_1 ( V_1 ) ;
error = F_19 ( V_43 , L_17 , & V_1 ) ;
if ( ! error )
V_5 -> V_30 = F_1 ( V_1 ) ;
return 0 ;
}
static inline int F_18 ( struct V_41 * V_11 ,
struct V_4 * V_5 )
{
F_7 ( V_11 , L_18 ) ;
return - V_46 ;
}
static int F_20 ( struct V_47 * V_10 ,
const struct V_48 * V_49 )
{
const struct V_50 * V_51 = F_21 ( & V_10 -> V_11 ) ;
struct V_4 * V_5 ;
int error ;
V_5 = F_22 ( & V_10 -> V_11 , sizeof( * V_5 ) , V_52 ) ;
if ( ! V_5 )
return - V_53 ;
V_5 -> V_28 = V_54 ;
V_5 -> V_28 = V_55 ;
if ( V_51 ) {
V_5 -> V_19 = V_51 -> V_19 ;
V_5 -> V_37 = V_51 -> V_56 ;
if ( V_51 -> V_57 )
V_5 -> V_30 = F_1 ( V_51 -> V_57 ) ;
if ( V_51 -> V_58 )
V_5 -> V_28 = F_1 ( V_51 -> V_58 ) ;
} else if ( V_10 -> V_11 . V_44 ) {
error = F_18 ( & V_10 -> V_11 , V_5 ) ;
if ( error )
return error ;
} else {
F_7 ( & V_10 -> V_11 , L_19 ) ;
return - V_59 ;
}
if ( V_5 -> V_19 < V_31 ||
V_5 -> V_19 > V_33 ) {
F_7 ( & V_10 -> V_11 ,
L_20 ,
V_5 -> V_19 ) ;
return - V_46 ;
}
if ( V_5 -> V_37 < V_60 ||
V_5 -> V_37 > V_61 ) {
F_7 ( & V_10 -> V_11 ,
L_21 , V_5 -> V_37 ) ;
return - V_46 ;
}
if ( V_5 -> V_19 == V_31 &&
V_5 -> V_37 != V_60 &&
V_5 -> V_37 != V_62 ) {
F_7 ( & V_10 -> V_11 ,
L_22 ) ;
return - V_46 ;
}
if ( V_5 -> V_19 == V_33 &&
( V_5 -> V_37 == V_60 ||
V_5 -> V_37 == V_62 ) ) {
F_7 ( & V_10 -> V_11 ,
L_23 ) ;
return - V_46 ;
}
V_5 -> V_63 = F_23 ( & V_10 -> V_11 , L_24 ) ;
if ( F_24 ( V_5 -> V_63 ) ) {
error = F_25 ( V_5 -> V_63 ) ;
F_7 ( & V_10 -> V_11 ,
L_25 , error ) ;
return error ;
}
V_5 -> V_6 = F_26 ( & V_10 -> V_11 , L_26 ) ;
if ( F_24 ( V_5 -> V_6 ) ) {
error = F_25 ( V_5 -> V_6 ) ;
if ( error != - V_64 && error != - V_65 )
return error ;
V_5 -> V_6 = NULL ;
} else {
F_27 ( V_5 -> V_6 , 1 ) ;
}
V_5 -> V_14 = F_28 ( & V_10 -> V_11 ) ;
if ( ! V_5 -> V_14 ) {
F_7 ( & V_10 -> V_11 , L_27 ) ;
return - V_53 ;
}
V_5 -> V_14 -> V_66 = L_28 ;
V_5 -> V_14 -> V_11 . V_67 = V_10 -> V_11 . V_67 ;
V_5 -> V_14 -> V_68 = F_11 ;
F_29 ( V_5 -> V_14 , V_5 ) ;
F_30 ( V_5 -> V_14 , V_69 , V_70 ) ;
error = F_31 ( V_5 -> V_14 , NULL ,
F_8 ) ;
if ( error ) {
F_7 ( & V_10 -> V_11 , L_29 ,
error ) ;
return error ;
}
F_32 ( & V_5 -> V_3 , F_2 ) ;
V_5 -> V_10 = V_10 ;
F_33 ( V_10 , V_5 ) ;
V_5 -> V_7 = F_34 ( V_10 , & V_71 ) ;
if ( F_24 ( V_5 -> V_7 ) ) {
error = F_25 ( V_5 -> V_7 ) ;
F_7 ( & V_10 -> V_11 , L_30 ,
error ) ;
return error ;
}
error = F_13 ( V_5 ) ;
if ( error ) {
F_7 ( & V_10 -> V_11 , L_31 , error ) ;
return error ;
}
error = F_35 ( V_5 -> V_14 ) ;
if ( error ) {
F_7 ( & V_10 -> V_11 , L_32 ,
error ) ;
return error ;
}
return 0 ;
}
static int F_36 ( struct V_41 * V_11 )
{
struct V_4 * V_5 = F_37 ( V_11 ) ;
int V_72 = 0 ;
F_38 ( & V_5 -> V_14 -> V_73 ) ;
if ( V_5 -> V_14 -> V_74 ) {
V_72 = F_16 ( V_5 -> V_7 ,
V_8 ,
V_75 ,
V_25 ) ;
if ( V_72 ) {
F_7 ( V_11 , L_33 ) ;
goto V_76;
}
F_4 ( V_5 -> V_6 , 0 ) ;
V_72 = F_39 ( V_5 -> V_63 ) ;
if ( V_72 ) {
F_7 ( V_11 , L_34 ) ;
F_16 ( V_5 -> V_7 ,
V_8 ,
V_75 , 0 ) ;
}
}
V_76:
F_40 ( & V_5 -> V_14 -> V_73 ) ;
return V_72 ;
}
static int F_41 ( struct V_41 * V_11 )
{
struct V_4 * V_5 = F_37 ( V_11 ) ;
int V_72 = 0 ;
F_38 ( & V_5 -> V_14 -> V_73 ) ;
if ( V_5 -> V_14 -> V_74 ) {
V_72 = F_42 ( V_5 -> V_63 ) ;
if ( V_72 ) {
F_7 ( V_11 , L_35 ) ;
goto V_76;
}
V_72 = F_16 ( V_5 -> V_7 ,
V_8 ,
V_75 , 0 ) ;
if ( V_72 ) {
F_7 ( V_11 , L_36 ) ;
F_39 ( V_5 -> V_63 ) ;
goto V_76;
}
F_4 ( V_5 -> V_6 , 1 ) ;
}
V_76:
F_40 ( & V_5 -> V_14 -> V_73 ) ;
return V_72 ;
}
