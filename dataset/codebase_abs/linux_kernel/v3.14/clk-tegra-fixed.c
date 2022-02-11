int T_1 F_1 ( void T_2 * V_1 ,
struct V_2 * V_3 ,
unsigned long * V_4 , int V_5 ,
unsigned long * V_6 ,
unsigned long * V_7 )
{
struct V_8 * V_8 ;
struct V_8 * * V_9 ;
T_3 V_10 , V_11 ;
unsigned V_12 ;
V_10 = F_2 ( V_1 + V_13 ) ;
V_12 = V_10 >> V_14 ;
if ( V_12 < V_5 )
* V_6 = V_4 [ V_12 ] ;
else
* V_6 = 0 ;
if ( ! * V_6 ) {
F_3 ( 1 ) ;
return - V_15 ;
}
V_9 = F_4 ( V_16 , V_3 ) ;
if ( ! V_9 )
return 0 ;
V_8 = F_5 ( NULL , L_1 , NULL , V_17 ,
* V_6 ) ;
* V_9 = V_8 ;
V_10 = ( V_10 >> V_18 ) & 3 ;
V_11 = 1 << V_10 ;
V_9 = F_4 ( V_19 , V_3 ) ;
if ( ! V_9 )
return 0 ;
V_8 = F_6 ( NULL , L_2 , L_1 ,
0 , 1 , V_11 ) ;
* V_9 = V_8 ;
if ( V_7 )
* V_7 = * V_6 / V_11 ;
return 0 ;
}
void T_1 F_7 ( struct V_2 * V_3 )
{
struct V_8 * V_8 ;
struct V_8 * * V_9 ;
V_9 = F_4 ( V_20 , V_3 ) ;
if ( V_9 ) {
V_8 = F_5 ( NULL , L_3 , NULL ,
V_17 , 32768 ) ;
* V_9 = V_8 ;
}
V_9 = F_4 ( V_21 , V_3 ) ;
if ( V_9 ) {
V_8 = F_6 ( NULL , L_4 , L_1 ,
V_22 , 1 , 2 ) ;
* V_9 = V_8 ;
}
V_9 = F_4 ( V_23 , V_3 ) ;
if ( V_9 ) {
V_8 = F_6 ( NULL , L_5 , L_1 ,
V_22 , 1 , 4 ) ;
* V_9 = V_8 ;
}
}
