T_1
T_2
static int
F_1 ( T_3 * V_1 , int V_2 , T_4 * V_3 , T_5 * V_4 , T_6 * V_5 , T_7 * V_6 )
{
static T_8 V_7 ;
int V_8 ;
if( V_5 -> V_9 ) {
V_8 = V_2 ;
V_2 = F_2 ( V_1 , V_2 , V_3 , NULL , V_6 , - 1 , & V_7 ) ;
V_5 -> V_10 = V_2 - 4 ;
V_5 -> V_9 = 1 ;
V_5 -> V_11 = V_2 - V_8 ;
return V_2 ;
}
V_12 ;
if ( V_4 && V_7 ) {
F_3 ( V_4 , V_13 , V_1 , V_2 ,
V_7 * 2 , V_14 | V_15 ) ;
}
V_2 += 2 * V_7 ;
return V_2 ;
}
static int
F_4 ( T_3 * V_1 , int V_2 , T_4 * V_3 , T_5 * V_4 , T_6 * V_5 , T_7 * V_6 , int V_16 , T_8 T_9 V_17 )
{
V_2 = F_5 ( V_1 , V_2 , V_3 , V_4 , V_5 , V_6 , 1 , V_16 , FALSE , NULL ) ;
return V_2 ;
}
T_10
void
F_6 ( void )
{
static T_11 V_18 [] = {
{ & V_13 ,
{ L_1 , L_2 , V_19 , V_20 ,
NULL , 0 ,
NULL , V_21 } } ,
V_22
} ;
static T_12 * V_23 [] = {
V_24
} ;
V_25 = F_7 (
L_3 ,
L_3 , L_4 ) ;
F_8 ( V_25 , V_18 , F_9 ( V_18 ) ) ;
F_10 ( V_23 , F_9 ( V_23 ) ) ;
}
void
F_11 ( void )
{
V_26
}
