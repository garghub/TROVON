bool F_1 ( struct V_1 * V_2 , T_1 type , const void * V_3 ,
T_1 V_4 )
{
bool V_5 = true ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_2 V_8 = 0 , V_9 = 0 ;
struct V_10 * V_11 ;
unsigned char * V_12 ;
struct V_13 * V_14 ;
T_3 V_15 ;
struct V_16 * V_17 = NULL ;
F_3 ( V_18 , L_1 , V_19 , V_4 ) ;
do {
if ( ( V_4 - V_9 ) > V_20 ) {
V_8 = V_20 ;
V_15 = 0 ;
} else {
V_8 = ( T_2 ) ( V_4 - V_9 ) ;
V_15 = 1 ;
}
if ( type == V_21 )
V_11 = F_4 ( V_8 +
V_7 -> V_22 -> V_23 + 4 ) ;
else
V_11 = F_4 ( V_8 + 4 ) ;
if ( ! V_11 ) {
V_5 = false ;
goto V_24;
}
memcpy ( ( unsigned char * ) ( V_11 -> V_25 ) , & V_2 , sizeof( V_2 ) ) ;
V_14 = (struct V_13 * ) ( V_11 -> V_25 + V_26 ) ;
V_14 -> V_27 = V_28 ;
V_14 -> V_29 = type ;
V_14 -> V_15 = V_15 ;
if ( type == V_21 ) {
V_14 -> V_30 = V_8 ;
V_12 = F_5 ( V_11 , V_7 -> V_22 -> V_23 ) ;
V_17 = (struct V_16 * ) V_12 ;
memset ( V_17 , 0 , sizeof( struct V_16 ) ) ;
memset ( V_17 , 0x12 , 8 ) ;
} else {
V_14 -> V_31 = ( T_2 ) V_8 ;
}
V_12 = F_5 ( V_11 , V_8 ) ;
memcpy ( V_12 , V_3 , ( T_1 ) V_8 ) ;
if ( type == V_32 &&
( ! V_7 -> V_22 -> V_33 ( V_2 , V_28 ) ||
( ! F_6 ( & V_7 -> V_22 -> V_34 [ V_28 ] ) ) ||
( V_7 -> V_22 -> V_35 ) ) ) {
F_7 ( & V_7 -> V_22 -> V_34 [ V_28 ] ,
V_11 ) ;
} else {
V_7 -> V_22 -> V_36 ( V_11 , V_2 ) ;
}
V_3 += V_8 ;
V_9 += V_8 ;
} while ( V_9 < V_4 );
F_8 ( V_2 , V_37 , V_38 ) ;
V_24:
return V_5 ;
}
