static int F_1 ( struct V_1 * V_1 ,
struct V_2 * V_3 ,
const void * V_4 , int V_5 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
const struct V_10 * V_11 = V_4 ;
struct V_12 * V_13 ;
int V_14 , V_15 , V_16 ;
void * V_17 = NULL , * V_18 ;
T_1 V_19 , V_20 = V_21 - 0x100 ;
if ( V_5 < sizeof( * V_11 ) ) {
F_2 ( L_1 , V_5 ) ;
return - V_22 ;
}
V_7 = F_3 ( V_3 , struct V_6 , V_3 ) ;
V_9 = V_7 -> V_9 ;
F_4 ( V_23 , L_2 , V_9 -> V_24 , V_11 -> V_25 ) ;
if ( V_11 -> V_26 > V_5 ) {
F_2 ( L_3 , V_11 -> V_26 , V_5 ) ;
return - V_22 ;
}
V_5 -= V_11 -> V_26 ;
V_16 = V_11 -> V_5 ;
if ( V_16 > 0 || V_5 > 0 ) {
if ( V_5 > V_27 ) {
F_2 ( L_4 , V_5 ) ;
V_5 = V_27 ;
}
if ( V_16 > V_27 ) {
F_2 ( L_5 , V_16 ) ;
V_16 = V_27 ;
}
V_15 = F_5 ( V_16 , V_5 ) + 1 ;
V_17 = F_6 ( V_15 ) ;
if ( NULL == V_17 )
return - V_28 ;
memcpy ( V_17 , ( void * ) V_11 + V_11 -> V_26 , V_5 ) ;
* ( char * ) ( V_17 + V_5 ) = '\0' ;
}
if ( V_11 -> V_29 )
V_14 = F_7 ( V_9 , V_11 -> V_25 , V_17 ,
V_16 ) ;
else
V_14 = F_8 ( V_9 , V_11 -> V_25 , V_17 ,
V_16 ) ;
if ( V_14 != 0 )
goto exit;
V_18 = V_17 ;
while ( V_16 > 0 ) {
V_19 = V_16 > V_20 ? V_20 : V_16 ;
V_16 -= V_19 ;
V_15 = V_19 + sizeof( V_19 ) ;
V_13 = F_9 ( V_1 , V_15 ) ;
if ( NULL == V_13 ) {
V_14 = - V_28 ;
break;
}
if ( F_10 ( V_13 , V_30 , V_19 , V_18 ) ||
F_11 ( V_13 , V_31 , V_19 ) ) {
F_12 ( V_13 ) ;
V_14 = - V_32 ;
break;
}
V_14 = F_13 ( V_13 ) ;
if ( V_14 )
break;
V_18 += V_19 ;
}
exit:
F_14 ( V_17 ) ;
return V_14 ;
}
