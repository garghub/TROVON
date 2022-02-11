static void T_1 F_1 ( void )
{
struct V_1 V_2 = {
. V_3 = L_1 ,
. V_4 = - 1 ,
. V_5 = V_6 ,
. V_7 = F_2 ( V_6 ) ,
. V_8 = & V_9 ,
. V_10 = sizeof( V_9 ) ,
. V_11 = F_3 ( 32 ) ,
} ;
F_4 ( & V_2 ) ;
}
static void T_1 F_5 ( void )
{
static const struct V_12 {
const char * V_13 ;
const char * V_14 ;
const char * V_15 ;
} V_16 [] = {
{ L_2 , NULL , L_3 } ,
{ L_4 , NULL , L_5 } ,
{ L_6 , NULL , L_7 } ,
{ L_8 , NULL , L_9 } ,
{ L_10 , NULL , L_11 } ,
{ L_12 , NULL , L_13 } ,
{ L_14 , NULL , L_15 } ,
{ L_16 , NULL , L_17 } ,
{ L_18 , NULL , L_19 } ,
{ L_20 , NULL , L_21 } ,
{ L_22 , NULL , L_23 } ,
{ L_24 , L_25 , L_1 } ,
{ L_26 , L_27 , L_1 } ,
{ L_28 , L_29 , L_1 } ,
{ L_30 , L_31 , L_1 } ,
{ L_32 , L_33 , L_1 } ,
} ;
struct V_13 * V_13 ;
unsigned int V_17 ;
for ( V_17 = 0 ; V_17 < F_2 ( V_16 ) ; ++ V_17 ) {
V_13 = F_6 ( NULL , V_16 [ V_17 ] . V_13 ) ;
if ( ! F_7 ( V_13 ) ) {
F_8 ( V_13 , V_16 [ V_17 ] . V_14 ,
V_16 [ V_17 ] . V_15 ) ;
F_9 ( V_13 ) ;
}
}
F_10 () ;
F_11 ( NULL , V_18 , NULL , NULL ) ;
F_1 () ;
}
