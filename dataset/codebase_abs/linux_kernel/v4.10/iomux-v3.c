int F_1 ( T_1 V_1 )
{
T_2 V_2 = ( V_1 & V_3 ) >> V_4 ;
T_2 V_5 = ( V_1 & V_6 ) >> V_7 ;
T_2 V_8 = ( V_1 & V_9 ) >> V_10 ;
T_2 V_11 = ( V_1 & V_12 ) >> V_13 ;
T_2 V_14 = ( V_1 & V_15 ) >> V_16 ;
T_2 V_17 = ( V_1 & V_18 ) >> V_19 ;
if ( V_2 )
F_2 ( V_5 , V_20 + V_2 ) ;
if ( V_8 )
F_2 ( V_11 , V_20 + V_8 ) ;
if ( ! ( V_17 & V_21 ) && V_14 )
F_2 ( V_17 , V_20 + V_14 ) ;
return 0 ;
}
int F_3 ( const T_1 * V_22 ,
unsigned V_23 )
{
const T_1 * V_24 = V_22 ;
int V_25 ;
int V_26 ;
for ( V_25 = 0 ; V_25 < V_23 ; V_25 ++ ) {
V_26 = F_1 ( * V_24 ) ;
if ( V_26 )
return V_26 ;
V_24 ++ ;
}
return 0 ;
}
void F_4 ( void T_3 * V_27 )
{
V_20 = V_27 ;
}
