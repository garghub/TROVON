bool F_1 ( struct V_1 * V_2 , T_1 * V_3 ,
T_2 V_4 , T_2 V_5 )
{
bool V_6 = true ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
T_3 V_9 ;
T_3 V_10 = 0 , V_11 = 0 ;
struct V_12 * V_13 = V_8 -> V_14 ;
struct V_15 * V_16 ;
unsigned char * V_17 ;
struct V_18 * V_19 ;
T_1 V_20 ;
struct V_21 * V_22 = NULL ;
F_3 ( V_23 , L_1 , V_24 , V_5 ) ;
F_4 ( V_2 ) ;
V_9 = V_13 -> V_25 ;
do {
if ( ( V_5 - V_11 ) > V_9 ) {
V_10 = V_9 ;
V_20 = 0 ;
} else {
V_10 = ( T_3 ) ( V_5 - V_11 ) ;
V_20 = 1 ;
}
V_16 = F_5 ( V_10 +
V_8 -> V_26 -> V_27 + 4 ) ;
if ( V_16 == NULL ) {
V_6 = false ;
goto V_28;
}
memcpy ( ( unsigned char * ) ( V_16 -> V_29 ) , & V_2 , sizeof( V_2 ) ) ;
V_19 = (struct V_18 * ) ( V_16 -> V_29 + V_30 ) ;
V_19 -> V_31 = V_32 ;
V_19 -> V_33 = V_34 ;
V_19 -> V_20 = V_20 ;
V_19 -> V_35 = V_10 ;
V_17 = F_6 ( V_16 , V_8 -> V_26 -> V_27 ) ;
V_22 = (struct V_21 * ) V_17 ;
memset ( V_22 , 0 , sizeof( struct V_21 ) ) ;
memset ( V_22 , 0x12 , 8 ) ;
V_17 = F_6 ( V_16 , V_10 ) ;
memcpy ( V_17 , V_3 , ( T_2 ) V_10 ) ;
V_8 -> V_26 -> V_36 ( V_16 , V_2 ) ;
V_3 += V_10 ;
V_11 += V_10 ;
} while ( V_11 < V_5 );
F_7 ( V_2 , V_37 , V_38 ) ;
V_28:
return V_6 ;
}
