int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
const T_1 * V_5 ;
const T_2 * V_6 ;
struct V_7 * log ;
T_1 V_8 ;
T_2 V_9 ;
log = & V_2 -> log ;
if ( V_2 -> V_10 . V_11 && V_2 -> V_10 . V_11 -> V_12 )
V_4 = V_2 -> V_10 . V_11 -> V_12 ;
else
return - V_13 ;
if ( F_2 ( V_4 , L_1 ) )
V_2 -> V_14 |= V_15 ;
V_5 = F_3 ( V_4 , L_2 , NULL ) ;
V_6 = F_3 ( V_4 , L_3 , NULL ) ;
if ( V_5 == NULL && V_6 == NULL )
return - V_13 ;
if ( V_5 == NULL || V_6 == NULL )
return - V_16 ;
if ( F_4 ( V_4 , L_4 , L_5 ) < 0 ) {
V_8 = F_5 ( V_5 ) ;
V_9 = F_6 ( V_6 ) ;
} else {
V_8 = * V_5 ;
V_9 = * V_6 ;
}
if ( V_8 == 0 ) {
F_7 ( & V_2 -> V_10 , L_6 , V_17 ) ;
return - V_16 ;
}
log -> V_18 = F_8 ( V_8 , V_19 ) ;
if ( ! log -> V_18 )
return - V_20 ;
log -> V_21 = log -> V_18 + V_8 ;
memcpy ( log -> V_18 , F_9 ( V_9 ) , V_8 ) ;
return 0 ;
}
