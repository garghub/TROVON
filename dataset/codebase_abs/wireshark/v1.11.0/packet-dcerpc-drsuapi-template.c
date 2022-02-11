T_1
T_2
static int
F_1 ( T_3 * V_1 , int V_2 , T_4 * V_3 , T_5 * V_4 , T_6 * V_5 )
{
static T_7 V_6 ;
T_8 * V_7 ;
int V_8 ;
V_7 = ( T_8 * ) V_3 -> V_9 ;
if( V_7 -> V_10 ) {
V_8 = V_2 ;
V_2 = F_2 ( V_1 , V_2 , V_3 , NULL , V_5 , - 1 , & V_6 ) ;
V_7 -> V_11 = V_2 - 4 ;
V_7 -> V_10 = 1 ;
V_7 -> V_12 = V_2 - V_8 ;
return V_2 ;
}
V_13 ;
if ( V_4 && V_6 ) {
F_3 ( V_4 , V_14 , V_1 , V_2 ,
V_6 * 2 , V_15 | V_16 ) ;
}
V_2 += 2 * V_6 ;
return V_2 ;
}
static int
F_4 ( T_3 * V_1 , int V_2 , T_4 * V_3 , T_5 * V_4 , T_6 * V_5 , int V_17 , T_7 T_9 V_18 )
{
V_2 = F_5 ( V_1 , V_2 , V_3 , V_4 , V_5 , 1 , V_17 , FALSE , NULL ) ;
return V_2 ;
}
T_10
void
F_6 ( void )
{
static T_11 V_19 [] = {
{ & V_14 ,
{ L_1 , L_2 , V_20 , V_21 ,
NULL , 0 ,
NULL , V_22 } } ,
V_23
} ;
static T_12 * V_24 [] = {
V_25
} ;
V_26 = F_7 (
L_3 ,
L_3 , L_4 ) ;
F_8 ( V_26 , V_19 , F_9 ( V_19 ) ) ;
F_10 ( V_24 , F_9 ( V_24 ) ) ;
}
void
F_11 ( void )
{
V_27
}
