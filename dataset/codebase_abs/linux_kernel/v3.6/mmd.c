T_1 *
F_1 ( T_2 * V_1 , T_3 * V_2 )
{
T_4 * V_3 = ( T_4 * ) V_1 -> V_4 ;
T_4 * V_5 = ( T_4 * ) & ( V_2 -> V_6 ) ;
T_5 V_7 ;
int V_8 ;
int V_9 ;
V_8 = V_1 -> V_10 == V_11 ;
V_9 = V_2 -> V_12 < 0x0100 ;
#if V_13
F_2 ( supp->len == 6 , supp->len )
F_2 ( actp->len >= 6 && actp->len%3 == 0 , actp->len )
if ( V_8 ) {
F_2 ( actp->role == COMP_ROLE_ACT, actp->role )
F_2 ( 1 <= actp->id && actp->id <= 99 , actp->id )
} else {
F_2 ( actp->role == CNV_END_SHORT(COMP_ROLE_ACT), actp->role )
F_2 ( 1 <= CNV_END_SHORT(actp->id) && CNV_END_SHORT(actp->id) <= 99 , actp->id )
}
if ( V_9 ) {
F_2 ( supp->role == COMP_ROLE_SUPL, supp->role )
F_2 ( 1 <= supp->id && supp->id <= 99 , supp->id )
F_2 ( 1 <= supp->variant && supp->variant <= 99 , supp->variant )
F_2 ( 1 <= supp->bottom && supp->bottom <= 99 , supp->bottom )
F_2 ( 1 <= supp->top && supp->top <= 99 , supp->top )
F_2 ( supp->bottom <= supp->top, supp->bottom << 8 | supp->top )
} else {
F_2 ( supp->role == CNV_END_SHORT(COMP_ROLE_SUPL), supp->role )
F_2 ( 1 <= CNV_END_SHORT(supp->id) && CNV_END_SHORT(supp->id) <= 99 , supp->id )
F_2 ( 1 <= CNV_END_SHORT(supp->variant) && CNV_END_SHORT(supp->variant) <= 99 , supp->variant )
F_2 ( 1 <= CNV_END_SHORT(supp->bottom) && CNV_END_SHORT(supp->bottom) <=99 , supp->bottom )
F_2 ( 1 <= CNV_END_SHORT(supp->top) && CNV_END_SHORT(supp->top) <=99 , supp->top )
F_2 ( CNV_END_SHORT(supp->bottom) <= CNV_END_SHORT(supp->top), supp->bottom << 8 | supp->top )
}
#endif
#if V_14 == 0
V_8 = ! V_8 ;
V_9 = ! V_9 ;
#endif
for ( V_7 = V_1 -> V_15 ; V_7 > 3 ; V_3 ++ , V_7 -= 3 ) {
F_2 ( actq->variant[act_endian] <= 99 , i<<8 | actq->variant[act_endian] )
F_2 ( actq->bottom[act_endian] <= 99 , i<<8 | actq->bottom[act_endian] )
F_2 ( actq->top[act_endian] <= 99 , i<<8 | actq->top[act_endian] )
F_2 ( actq->bottom[act_endian] <= actq->top[act_endian], i<<8 | actq->bottom[act_endian] )
if ( V_3 -> V_6 [ V_8 ] == V_5 -> V_6 [ V_9 ] &&
V_3 -> V_12 [ V_8 ] <= V_5 -> V_16 [ V_9 ] &&
V_3 -> V_16 [ V_8 ] >= V_5 -> V_12 [ V_9 ]
) break;
}
if ( V_7 <= 3 || V_2 -> V_15 != 6 ) {
V_3 = NULL ;
}
#if V_13
if ( V_3 == NULL ) {
for ( V_7 = 0 ; V_7 <= V_2 -> V_15 ; V_7 += 2 ) {
F_2 ( V_17 , F_3 ( ( ( T_5 * ) V_2 ) [ V_7 ] , ( ( T_5 * ) V_2 ) [ V_7 + 1 ] ) ) ;
}
for ( V_7 = 0 ; V_7 <= V_1 -> V_15 ; V_7 += 2 ) {
F_2 ( V_17 , F_3 ( ( ( T_5 * ) V_1 ) [ V_7 ] , ( ( T_5 * ) V_1 ) [ V_7 + 1 ] ) ) ;
}
}
#endif
return ( T_1 * ) V_3 ;
}
