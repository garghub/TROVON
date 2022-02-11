static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 ,
T_1 V_4 )
{
T_1 V_5 [ 2 ] = { V_3 , V_4 } ;
struct V_6 V_7 = {
V_2 -> V_8 , V_9 , 2 , ( T_1 * ) V_5
} ;
int error ;
error = F_2 ( V_2 -> V_10 , & V_7 , 1 ) ;
return error < 0 ? error : 0 ;
}
static int F_3 ( struct V_1 * V_2 ,
T_1 V_3 , signed char * V_11 )
{
T_1 V_5 [ 2 ] = { V_3 } ;
struct V_6 V_12 [ 2 ] = {
{ V_2 -> V_8 , V_13 , 1 , ( T_1 * ) V_5 } ,
{ V_2 -> V_8 , V_14 | V_15 , 1 , ( T_1 * ) V_5 }
} ;
int error ;
error = F_2 ( V_2 -> V_10 , V_12 , 2 ) ;
if ( error < 0 )
return error ;
* V_11 = V_5 [ 0 ] & 0x80 ? - 1 * ( 1 + ~ V_5 [ 0 ] ) : V_5 [ 0 ] ;
return 0 ;
}
static T_2 F_4 ( int V_16 , void * V_17 )
{
struct V_18 * V_19 = V_17 ;
int V_20 = F_5 ( V_19 -> V_21 ) ;
F_6 ( V_19 -> V_22 , V_23 , ! V_20 ) ;
F_7 ( V_19 -> V_22 ) ;
return V_24 ;
}
static T_2 F_8 ( int V_16 , void * V_17 )
{
struct V_18 * V_19 = V_17 ;
int error ;
signed char V_25 , V_26 ;
error = F_3 ( V_19 -> V_1 , V_27 , & V_25 ) ;
if ( error < 0 )
goto V_28;
error = F_3 ( V_19 -> V_1 , V_29 , & V_26 ) ;
if ( error < 0 )
goto V_28;
F_9 ( V_19 -> V_22 , V_30 , V_25 ) ;
F_9 ( V_19 -> V_22 , V_31 , V_26 ) ;
F_7 ( V_19 -> V_22 ) ;
V_28:
return V_24 ;
}
static int T_3 F_10 ( struct V_18 * V_19 ,
const struct V_32 * V_33 )
{
struct V_1 * V_2 = V_19 -> V_1 ;
int error ;
signed char V_11 ;
error = F_1 ( V_2 , V_34 ,
V_35 ) ;
if ( error < 0 ) {
F_11 ( & V_2 -> V_36 , L_1 ) ;
return error ;
}
F_12 ( 10 ) ;
error = F_1 ( V_2 , V_34 ,
V_37 |
V_38 |
V_39 ) ;
if ( error < 0 ) {
F_11 ( & V_2 -> V_36 , L_2 ) ;
return error ;
}
error = F_1 ( V_2 , V_40 ,
V_41 ) ;
if ( error < 0 ) {
F_11 ( & V_2 -> V_36 , L_3 ) ;
return error ;
}
error = F_1 ( V_2 , V_42 , V_33 -> V_43 ) ;
if ( error < 0 ) {
F_11 ( & V_2 -> V_36 , L_4 ) ;
return error ;
}
error = F_1 ( V_2 , V_44 , V_33 -> V_45 ) ;
if ( error < 0 ) {
F_11 ( & V_2 -> V_36 , L_4 ) ;
return error ;
}
error = F_1 ( V_2 , V_46 , V_33 -> V_47 ) ;
if ( error < 0 ) {
F_11 ( & V_2 -> V_36 , L_4 ) ;
return error ;
}
error = F_1 ( V_2 , V_48 , V_33 -> yn ) ;
if ( error < 0 ) {
F_11 ( & V_2 -> V_36 , L_4 ) ;
return error ;
}
error = F_3 ( V_2 , V_27 , & V_11 ) ;
if ( error < 0 ) {
F_11 ( & V_2 -> V_36 , L_5 ) ;
return error ;
}
return 0 ;
}
static int T_3 F_13 ( struct V_1 * V_2 ,
const struct V_49 * V_50 )
{
const struct V_32 * V_51 ;
struct V_18 * V_19 ;
struct V_22 * V_22 ;
int V_16 ;
int error ;
V_51 = V_2 -> V_36 . V_52 ;
if ( ! V_51 )
return - V_53 ;
if ( ! V_51 -> V_54 ) {
F_11 ( & V_2 -> V_36 , L_6 ) ;
return - V_53 ;
}
if ( ! F_14 ( V_2 -> V_10 ,
V_55 ) ) {
F_11 ( & V_2 -> V_36 ,
L_7 ) ;
return - V_56 ;
}
V_19 = F_15 ( sizeof( struct V_18 ) , V_57 ) ;
V_22 = F_16 () ;
if ( ! V_19 || ! V_22 ) {
F_11 ( & V_2 -> V_36 ,
L_8 ) ;
error = - V_58 ;
goto V_59;
}
V_19 -> V_1 = V_2 ;
V_19 -> V_22 = V_22 ;
V_19 -> V_21 = V_51 -> V_21 ;
V_19 -> V_54 = V_51 -> V_54 ;
V_22 -> V_60 = L_9 ;
V_22 -> V_50 . V_61 = V_62 ;
V_22 -> V_36 . V_63 = & V_2 -> V_36 ;
F_17 ( V_64 , V_22 -> V_65 ) ;
F_17 ( V_66 , V_22 -> V_65 ) ;
F_17 ( V_23 , V_22 -> V_67 ) ;
F_18 ( V_22 , V_30 ,
V_68 , V_69 , V_70 , V_71 ) ;
F_18 ( V_19 -> V_22 , V_31 ,
V_68 , V_69 , V_70 , V_71 ) ;
error = F_19 ( V_19 -> V_21 , L_10 ) ;
if ( error < 0 ) {
F_11 ( & V_2 -> V_36 , L_11 ) ;
goto V_59;
}
V_16 = F_20 ( V_19 -> V_21 ) ;
if ( V_16 < 0 ) {
F_11 ( & V_2 -> V_36 ,
L_12 ) ;
goto V_72;
}
V_19 -> V_73 = V_16 ;
error = F_21 ( V_19 -> V_73 ,
NULL , F_4 ,
V_74 | V_75 ,
L_13 , V_19 ) ;
if ( error < 0 ) {
F_11 ( & V_2 -> V_36 ,
L_14 , V_19 -> V_73 ) ;
goto V_72;
}
error = F_10 ( V_19 , V_51 ) ;
if ( error )
goto V_76;
error = F_21 ( V_19 -> V_54 , NULL ,
F_8 ,
V_51 -> V_77 ,
L_15 , V_19 ) ;
if ( error ) {
F_11 ( & V_2 -> V_36 ,
L_16 , V_51 -> V_54 ) ;
goto V_76;
}
error = F_22 ( V_19 -> V_22 ) ;
if ( error ) {
F_11 ( & V_2 -> V_36 , L_17 ) ;
goto V_78;
}
F_23 ( V_2 , V_19 ) ;
return 0 ;
V_78:
F_24 ( V_19 -> V_54 , V_19 ) ;
V_76:
F_24 ( V_19 -> V_73 , V_19 ) ;
V_72:
F_25 ( V_19 -> V_21 ) ;
V_59:
F_26 ( V_22 ) ;
F_27 ( V_19 ) ;
return error ;
}
static int T_4 F_28 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = F_29 ( V_2 ) ;
F_24 ( V_19 -> V_54 , V_19 ) ;
F_24 ( V_19 -> V_73 , V_19 ) ;
F_25 ( V_19 -> V_21 ) ;
F_30 ( V_19 -> V_22 ) ;
F_27 ( V_19 ) ;
return 0 ;
}
static int T_5 F_31 ( void )
{
return F_32 ( & V_79 ) ;
}
static void T_6 F_33 ( void )
{
F_34 ( & V_79 ) ;
}
