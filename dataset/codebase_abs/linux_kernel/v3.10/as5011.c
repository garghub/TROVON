static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 ,
T_1 V_4 )
{
T_1 V_5 [ 2 ] = { V_3 , V_4 } ;
struct V_6 V_7 = {
. V_8 = V_2 -> V_8 ,
. V_9 = V_10 ,
. V_11 = 2 ,
. V_12 = ( T_1 * ) V_5
} ;
int error ;
error = F_2 ( V_2 -> V_13 , & V_7 , 1 ) ;
return error < 0 ? error : 0 ;
}
static int F_3 ( struct V_1 * V_2 ,
T_1 V_3 , signed char * V_14 )
{
T_1 V_5 [ 2 ] = { V_3 } ;
struct V_6 V_15 [ 2 ] = {
{
. V_8 = V_2 -> V_8 ,
. V_9 = V_16 ,
. V_11 = 1 ,
. V_12 = ( T_1 * ) V_5
} ,
{
. V_8 = V_2 -> V_8 ,
. V_9 = V_17 | V_18 ,
. V_11 = 1 ,
. V_12 = ( T_1 * ) V_5
}
} ;
int error ;
error = F_2 ( V_2 -> V_13 , V_15 , 2 ) ;
if ( error < 0 )
return error ;
* V_14 = V_5 [ 0 ] & 0x80 ? - 1 * ( 1 + ~ V_5 [ 0 ] ) : V_5 [ 0 ] ;
return 0 ;
}
static T_2 F_4 ( int V_19 , void * V_20 )
{
struct V_21 * V_22 = V_20 ;
int V_23 = F_5 ( V_22 -> V_24 ) ;
F_6 ( V_22 -> V_25 , V_26 , ! V_23 ) ;
F_7 ( V_22 -> V_25 ) ;
return V_27 ;
}
static T_2 F_8 ( int V_19 , void * V_20 )
{
struct V_21 * V_22 = V_20 ;
int error ;
signed char V_28 , V_29 ;
error = F_3 ( V_22 -> V_1 , V_30 , & V_28 ) ;
if ( error < 0 )
goto V_31;
error = F_3 ( V_22 -> V_1 , V_32 , & V_29 ) ;
if ( error < 0 )
goto V_31;
F_9 ( V_22 -> V_25 , V_33 , V_28 ) ;
F_9 ( V_22 -> V_25 , V_34 , V_29 ) ;
F_7 ( V_22 -> V_25 ) ;
V_31:
return V_27 ;
}
static int F_10 ( struct V_21 * V_22 ,
const struct V_35 * V_36 )
{
struct V_1 * V_2 = V_22 -> V_1 ;
int error ;
signed char V_14 ;
error = F_1 ( V_2 , V_37 ,
V_38 ) ;
if ( error < 0 ) {
F_11 ( & V_2 -> V_39 , L_1 ) ;
return error ;
}
F_12 ( 10 ) ;
error = F_1 ( V_2 , V_37 ,
V_40 |
V_41 |
V_42 ) ;
if ( error < 0 ) {
F_11 ( & V_2 -> V_39 , L_2 ) ;
return error ;
}
error = F_1 ( V_2 , V_43 ,
V_44 ) ;
if ( error < 0 ) {
F_11 ( & V_2 -> V_39 , L_3 ) ;
return error ;
}
error = F_1 ( V_2 , V_45 , V_36 -> V_46 ) ;
if ( error < 0 ) {
F_11 ( & V_2 -> V_39 , L_4 ) ;
return error ;
}
error = F_1 ( V_2 , V_47 , V_36 -> V_48 ) ;
if ( error < 0 ) {
F_11 ( & V_2 -> V_39 , L_4 ) ;
return error ;
}
error = F_1 ( V_2 , V_49 , V_36 -> V_50 ) ;
if ( error < 0 ) {
F_11 ( & V_2 -> V_39 , L_4 ) ;
return error ;
}
error = F_1 ( V_2 , V_51 , V_36 -> yn ) ;
if ( error < 0 ) {
F_11 ( & V_2 -> V_39 , L_4 ) ;
return error ;
}
error = F_3 ( V_2 , V_30 , & V_14 ) ;
if ( error < 0 ) {
F_11 ( & V_2 -> V_39 , L_5 ) ;
return error ;
}
return 0 ;
}
static int F_13 ( struct V_1 * V_2 ,
const struct V_52 * V_53 )
{
const struct V_35 * V_54 ;
struct V_21 * V_22 ;
struct V_25 * V_25 ;
int V_19 ;
int error ;
V_54 = V_2 -> V_39 . V_55 ;
if ( ! V_54 )
return - V_56 ;
if ( ! V_54 -> V_57 ) {
F_11 ( & V_2 -> V_39 , L_6 ) ;
return - V_56 ;
}
if ( ! F_14 ( V_2 -> V_13 ,
V_58 |
V_59 ) ) {
F_11 ( & V_2 -> V_39 ,
L_7 ) ;
return - V_60 ;
}
V_22 = F_15 ( sizeof( struct V_21 ) , V_61 ) ;
V_25 = F_16 () ;
if ( ! V_22 || ! V_25 ) {
F_11 ( & V_2 -> V_39 ,
L_8 ) ;
error = - V_62 ;
goto V_63;
}
V_22 -> V_1 = V_2 ;
V_22 -> V_25 = V_25 ;
V_22 -> V_24 = V_54 -> V_24 ;
V_22 -> V_57 = V_54 -> V_57 ;
V_25 -> V_64 = L_9 ;
V_25 -> V_53 . V_65 = V_66 ;
V_25 -> V_39 . V_67 = & V_2 -> V_39 ;
F_17 ( V_68 , V_25 -> V_69 ) ;
F_17 ( V_70 , V_25 -> V_69 ) ;
F_17 ( V_26 , V_25 -> V_71 ) ;
F_18 ( V_25 , V_33 ,
V_72 , V_73 , V_74 , V_75 ) ;
F_18 ( V_22 -> V_25 , V_34 ,
V_72 , V_73 , V_74 , V_75 ) ;
error = F_19 ( V_22 -> V_24 , L_10 ) ;
if ( error < 0 ) {
F_11 ( & V_2 -> V_39 , L_11 ) ;
goto V_63;
}
V_19 = F_20 ( V_22 -> V_24 ) ;
if ( V_19 < 0 ) {
F_11 ( & V_2 -> V_39 ,
L_12 ) ;
goto V_76;
}
V_22 -> V_77 = V_19 ;
error = F_21 ( V_22 -> V_77 ,
NULL , F_4 ,
V_78 |
V_79 | V_80 ,
L_13 , V_22 ) ;
if ( error < 0 ) {
F_11 ( & V_2 -> V_39 ,
L_14 , V_22 -> V_77 ) ;
goto V_76;
}
error = F_10 ( V_22 , V_54 ) ;
if ( error )
goto V_81;
error = F_21 ( V_22 -> V_57 , NULL ,
F_8 ,
V_54 -> V_82 | V_80 ,
L_15 , V_22 ) ;
if ( error ) {
F_11 ( & V_2 -> V_39 ,
L_16 , V_54 -> V_57 ) ;
goto V_81;
}
error = F_22 ( V_22 -> V_25 ) ;
if ( error ) {
F_11 ( & V_2 -> V_39 , L_17 ) ;
goto V_83;
}
F_23 ( V_2 , V_22 ) ;
return 0 ;
V_83:
F_24 ( V_22 -> V_57 , V_22 ) ;
V_81:
F_24 ( V_22 -> V_77 , V_22 ) ;
V_76:
F_25 ( V_22 -> V_24 ) ;
V_63:
F_26 ( V_25 ) ;
F_27 ( V_22 ) ;
return error ;
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = F_29 ( V_2 ) ;
F_24 ( V_22 -> V_57 , V_22 ) ;
F_24 ( V_22 -> V_77 , V_22 ) ;
F_25 ( V_22 -> V_24 ) ;
F_30 ( V_22 -> V_25 ) ;
F_27 ( V_22 ) ;
return 0 ;
}
