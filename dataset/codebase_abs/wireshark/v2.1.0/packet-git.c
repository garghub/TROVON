static T_1 F_1 ( T_2 * V_1 , int V_2 ,
T_3 * V_3 )
{
T_4 * V_4 ;
V_4 = F_2 ( F_3 () , V_1 , V_2 , 4 , V_5 ) ;
return ( sscanf ( V_4 , L_1 , V_3 ) == 1 ) ;
}
static T_5
F_4 ( T_6 * T_7 V_6 , T_2 * V_1 , int V_2 , void * T_8 V_6 )
{
T_3 V_7 ;
if ( ! F_1 ( V_1 , V_2 , & V_7 ) )
return 0 ;
if ( V_7 == 0 ) {
return 4 ;
}
return V_7 ;
}
static int
F_5 ( T_2 * V_1 , T_6 * T_7 , T_9 * V_8 , void * T_8 V_6 )
{
T_9 * V_9 ;
T_10 * V_10 ;
int V_2 = 0 ;
T_3 V_7 ;
F_6 ( T_7 -> V_11 , V_12 , V_13 ) ;
F_6 ( T_7 -> V_11 , V_14 , V_15 ) ;
V_10 = F_7 ( V_8 , V_16 , V_1 , V_2 , - 1 , V_17 ) ;
V_9 = F_8 ( V_10 , V_18 ) ;
if ( ! F_1 ( V_1 , 0 , & V_7 ) )
return 0 ;
if ( V_7 == 0 ) {
F_9 ( V_9 , V_19 , V_1 , V_2 ,
4 , V_7 ) ;
return 4 ;
}
if ( V_9 )
{
F_9 ( V_9 , V_20 , V_1 , V_2 ,
4 , V_7 ) ;
F_7 ( V_9 , V_21 , V_1 , V_2 + 4 ,
V_7 - 4 , V_17 ) ;
}
return F_10 ( V_1 ) ;
}
static int
F_11 ( T_2 * V_1 , T_6 * T_7 , T_9 * V_8 , void * T_8 )
{
F_12 ( V_1 , T_7 , V_8 , V_22 , 4 , F_4 ,
F_5 , T_8 ) ;
return F_10 ( V_1 ) ;
}
void
F_13 ( void )
{
static T_11 V_23 [] = {
{ & V_20 ,
{ L_2 , L_3 , V_24 , V_25 , NULL , 0x0 , NULL , V_26 } ,
} ,
{ & V_21 ,
{ L_4 , L_5 , V_27 , V_28 , NULL , 0x0 , NULL , V_26 } ,
} ,
{ & V_19 ,
{ L_6 , L_7 , V_24 , V_25 , NULL , 0x0 , NULL , V_26 } ,
} ,
} ;
static T_12 * V_29 [] = {
& V_18 ,
} ;
T_13 * V_30 ;
V_16 = F_14 ( V_15 , V_13 , V_31 ) ;
F_15 ( V_16 , V_23 , F_16 ( V_23 ) ) ;
F_17 ( V_29 , F_16 ( V_29 ) ) ;
V_32 = F_18 ( V_31 , F_11 , V_16 ) ;
V_30 = F_19 ( V_16 , NULL ) ;
F_20 ( V_30 , L_8 ,
L_9 ,
L_10
L_11 ,
& V_22 ) ;
}
void
F_21 ( void )
{
F_22 ( L_12 , V_33 , V_32 ) ;
}
