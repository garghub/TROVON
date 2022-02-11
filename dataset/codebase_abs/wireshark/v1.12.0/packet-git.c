static T_1 F_1 ( T_2 * V_1 , int V_2 ,
T_3 * V_3 )
{
T_4 * V_4 ;
V_4 = F_2 ( F_3 () , V_1 , V_2 , 4 ) ;
return ( sscanf ( V_4 , L_1 , V_3 ) == 1 ) ;
}
static T_5
F_4 ( T_6 * T_7 V_5 , T_2 * V_1 , int V_2 )
{
T_3 V_6 ;
if ( ! F_1 ( V_1 , V_2 , & V_6 ) )
return 0 ;
if ( V_6 == 0 ) {
return 4 ;
}
return V_6 ;
}
static int
F_5 ( T_2 * V_1 , T_6 * T_7 , T_8 * V_7 , void * T_9 V_5 )
{
T_8 * V_8 ;
T_10 * V_9 ;
int V_2 = 0 ;
T_3 V_6 ;
F_6 ( T_7 -> V_10 , V_11 , L_2 ) ;
F_6 ( T_7 -> V_10 , V_12 , L_3 ) ;
V_9 = F_7 ( V_7 , V_13 , V_1 , V_2 , - 1 , V_14 ) ;
V_8 = F_8 ( V_9 , V_15 ) ;
if ( ! F_1 ( V_1 , 0 , & V_6 ) )
return 0 ;
if ( V_6 == 0 ) {
F_9 ( V_8 , V_16 , V_1 , V_2 ,
4 , V_6 ) ;
return 4 ;
}
if ( V_8 )
{
F_9 ( V_8 , V_17 , V_1 , V_2 ,
4 , V_6 ) ;
F_7 ( V_8 , V_18 , V_1 , V_2 + 4 ,
V_6 - 4 , V_14 ) ;
}
return F_10 ( V_1 ) ;
}
static int
F_11 ( T_2 * V_1 , T_6 * T_7 , T_8 * V_7 , void * T_9 )
{
F_12 ( V_1 , T_7 , V_7 , V_19 , 4 , F_4 ,
F_5 , T_9 ) ;
return F_10 ( V_1 ) ;
}
void
F_13 ( void )
{
static T_11 V_20 [] = {
{ & V_17 ,
{ L_4 , L_5 , V_21 , V_22 , NULL , 0x0 , NULL , V_23 } ,
} ,
{ & V_18 ,
{ L_6 , L_7 , V_24 , V_25 , NULL , 0x0 , NULL , V_23 } ,
} ,
{ & V_16 ,
{ L_8 , L_9 , V_21 , V_22 , NULL , 0x0 , NULL , V_23 } ,
} ,
} ;
static T_12 * V_26 [] = {
& V_15 ,
} ;
T_13 * V_27 ;
V_13 = F_14 ( L_3 , L_2 , L_10 ) ;
F_15 ( V_13 , V_20 , F_16 ( V_20 ) ) ;
F_17 ( V_26 , F_16 ( V_26 ) ) ;
V_28 = F_18 ( L_10 , F_11 , V_13 ) ;
V_27 = F_19 ( V_13 , NULL ) ;
F_20 ( V_27 , L_11 ,
L_12 ,
L_13
L_14 ,
& V_19 ) ;
}
void
F_21 ( void )
{
F_22 ( L_15 , V_29 , V_28 ) ;
}
