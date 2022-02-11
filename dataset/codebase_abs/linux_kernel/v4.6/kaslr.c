static T_1 T_2 F_1 ( void * V_1 )
{
int V_2 , V_3 ;
T_2 * V_4 ;
T_2 V_5 ;
V_2 = F_2 ( V_1 , L_1 ) ;
if ( V_2 < 0 )
return 0 ;
V_4 = F_3 ( V_1 , V_2 , L_2 , & V_3 ) ;
if ( ! V_4 || V_3 != sizeof( T_2 ) )
return 0 ;
V_5 = F_4 ( * V_4 ) ;
* V_4 = 0 ;
return V_5 ;
}
static T_1 const T_3 * F_5 ( void * V_1 )
{
static T_4 const T_3 V_6 [] = V_7 ;
if ( ! F_6 ( V_8 ) ) {
int V_2 ;
const T_3 * V_4 ;
V_2 = F_2 ( V_1 , L_1 ) ;
if ( V_2 < 0 )
goto V_9;
V_4 = F_7 ( V_1 , V_2 , L_3 , NULL ) ;
if ( ! V_4 )
goto V_9;
return V_4 ;
}
V_9:
return V_6 ;
}
T_2 T_1 F_8 ( T_2 V_10 )
{
void * V_1 ;
T_2 V_11 , V_12 , V_13 , V_14 ;
const T_3 * V_15 , * V_16 ;
int V_17 ;
V_18 = ( T_2 ) V_19 - V_20 ;
F_9 () ;
V_1 = F_10 ( V_10 , & V_17 , V_21 ) ;
if ( ! V_1 )
return 0 ;
V_11 = F_1 ( V_1 ) ;
if ( ! V_11 )
return 0 ;
V_15 = F_5 ( V_1 ) ;
V_16 = strstr ( V_15 , L_4 ) ;
if ( V_16 == V_15 || ( V_16 > V_15 && * ( V_16 - 1 ) == ' ' ) )
return 0 ;
V_13 = ( ( 1UL << ( V_22 - 2 ) ) - 1 ) & ~ ( V_23 - 1 ) ;
V_12 = V_11 & V_13 ;
V_24 = V_11 >> 48 ;
if ( ( ( ( T_2 ) V_25 + V_12 ) >> V_26 ) !=
( ( ( T_2 ) V_27 + V_12 ) >> V_26 ) )
V_12 = ( V_12 + ( T_2 ) ( V_27 - V_25 ) ) & V_13 ;
if ( F_6 ( V_28 ) )
return V_12 ;
if ( F_6 ( V_29 ) ) {
V_14 = V_30 - V_31 - V_20 ;
V_18 = V_31 ;
} else {
V_14 = V_20 - ( T_2 ) ( V_19 - V_32 ) ;
V_18 = ( T_2 ) V_19 + V_12 - V_20 ;
}
V_18 += ( V_14 * ( V_11 & ( ( 1 << 21 ) - 1 ) ) ) >> 21 ;
V_18 &= V_33 ;
return V_12 ;
}
