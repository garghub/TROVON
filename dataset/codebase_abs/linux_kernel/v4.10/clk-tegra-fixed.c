int T_1 F_1 ( void T_2 * V_1 , struct V_2 * V_3 ,
unsigned long * V_4 , unsigned int V_5 ,
unsigned int V_6 , unsigned long * V_7 ,
unsigned long * V_8 )
{
struct V_9 * V_9 , * V_10 ;
struct V_9 * * V_11 ;
T_3 V_12 , V_13 ;
unsigned V_14 ;
V_12 = F_2 ( V_1 + V_15 ) ;
V_14 = V_12 >> V_16 ;
if ( V_14 < V_5 )
* V_7 = V_4 [ V_14 ] ;
else
* V_7 = 0 ;
if ( ! * V_7 ) {
F_3 ( 1 ) ;
return - V_17 ;
}
V_10 = F_4 ( NULL , L_1 , NULL , 0 , * V_7 ) ;
V_11 = F_5 ( V_18 , V_3 ) ;
if ( ! V_11 )
return 0 ;
V_9 = F_6 ( NULL , L_2 , L_1 ,
0 , 1 , V_6 ) ;
* V_11 = V_9 ;
V_12 = ( V_12 >> V_19 ) & 3 ;
V_13 = 1 << V_12 ;
V_11 = F_5 ( V_20 , V_3 ) ;
if ( ! V_11 )
return 0 ;
V_9 = F_6 ( NULL , L_3 , L_1 ,
0 , 1 , V_13 ) ;
* V_11 = V_9 ;
if ( V_8 )
* V_8 = * V_7 / V_13 ;
return 0 ;
}
void T_1 F_7 ( struct V_2 * V_21 )
{
struct V_9 * V_9 ;
struct V_9 * * V_11 ;
V_11 = F_5 ( V_22 , V_21 ) ;
if ( V_11 ) {
V_9 = F_4 ( NULL , L_4 , NULL , 0 , 32768 ) ;
* V_11 = V_9 ;
}
V_11 = F_5 ( V_23 , V_21 ) ;
if ( V_11 ) {
V_9 = F_6 ( NULL , L_5 , L_2 ,
V_24 , 1 , 2 ) ;
* V_11 = V_9 ;
}
V_11 = F_5 ( V_25 , V_21 ) ;
if ( V_11 ) {
V_9 = F_6 ( NULL , L_6 , L_2 ,
V_24 , 1 , 4 ) ;
* V_11 = V_9 ;
}
}
