static int
F_1 ( T_1 * V_1 , T_2 * T_3 V_2 , T_4 * V_3 , void * T_5 V_2 )
{
return F_2 ( V_1 , V_3 , V_4 , 0 , NULL ) ;
}
static int
F_3 ( T_1 * V_1 , T_2 * T_3 V_2 , T_4 * V_3 , void * T_5 V_2 )
{
T_6 type ;
int V_5 = 0 ;
type = F_4 ( V_1 , V_5 ) ;
V_5 = F_5 ( V_1 , V_3 , V_6 , V_5 ) ;
switch( type ) {
case V_7 :
F_6 ( V_3 , V_8 ,
V_1 , V_5 , 4 , V_9 ) ;
V_5 += 4 ;
V_5 = F_5 ( V_1 , V_3 ,
V_10 , V_5 ) ;
break;
case V_11 :
V_5 = F_5 ( V_1 , V_3 ,
V_6 , V_5 ) ;
break;
}
return V_5 ;
}
static int
F_7 ( T_1 * V_1 , T_2 * T_3 V_2 , T_4 * V_3 , void * T_5 V_2 )
{
int V_5 = 0 ;
V_5 = F_2 ( V_1 , V_3 ,
V_4 , V_5 , NULL ) ;
F_6 ( V_3 , V_8 ,
V_1 , V_5 , 4 , V_9 ) ;
V_5 += 4 ;
V_5 = F_5 ( V_1 , V_3 ,
V_10 , V_5 ) ;
V_5 = F_5 ( V_1 , V_3 ,
V_12 , V_5 ) ;
return V_5 ;
}
void
F_8 ( void )
{
static T_7 V_13 [] = {
{ & V_14 , {
L_1 , L_2 , V_15 , V_16 ,
F_9 ( V_17 ) , 0 , NULL , V_18 } } ,
{ & V_19 , {
L_3 , L_4 , V_15 , V_16 ,
F_9 ( V_20 ) , 0 , NULL , V_18 } } ,
{ & V_4 , {
L_5 , L_6 , V_21 , V_22 ,
NULL , 0 , L_7 , V_18 } } ,
{ & V_6 , {
L_8 , L_9 , V_15 , V_16 ,
F_9 ( V_23 ) , 0 , NULL , V_18 } } ,
#if 0
{ &hf_ypbind_error, {
"Error", "ypbind.error", FT_UINT32, BASE_DEC,
VALS(error_vals), 0, "YPBIND Error code", HFILL }},
#endif
{ & V_8 , {
L_10 , L_11 , V_24 , V_22 ,
NULL , 0 , L_12 , V_18 } } ,
{ & V_10 , {
L_13 , L_14 , V_15 , V_16 ,
NULL , 0 , L_15 , V_18 } } ,
{ & V_12 , {
L_16 , L_17 , V_15 , V_16 ,
NULL , 0 , L_18 , V_18 } } ,
} ;
static T_8 * V_25 [] = {
& V_26 ,
} ;
V_27 = F_10 ( L_19 ,
L_20 , L_21 ) ;
F_11 ( V_27 , V_13 , F_12 ( V_13 ) ) ;
F_13 ( V_25 , F_12 ( V_25 ) ) ;
}
void
F_14 ( void )
{
F_15 ( V_27 , V_28 , V_26 ,
F_16 ( V_29 ) , V_29 ) ;
}
