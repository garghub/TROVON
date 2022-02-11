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
V_5 = F_2 ( V_4 , L_1 , NULL ) ;
V_6 = F_2 ( V_4 , L_2 , NULL ) ;
if ( V_5 == NULL && V_6 == NULL )
return - V_13 ;
if ( V_5 == NULL || V_6 == NULL )
return - V_14 ;
if ( F_3 ( V_4 , L_3 , L_4 ) < 0 ) {
V_8 = F_4 ( V_5 ) ;
V_9 = F_5 ( V_6 ) ;
} else {
V_8 = * V_5 ;
V_9 = * V_6 ;
}
if ( V_8 == 0 ) {
F_6 ( & V_2 -> V_10 , L_5 , V_15 ) ;
return - V_14 ;
}
log -> V_16 = F_7 ( V_8 , V_17 ) ;
if ( ! log -> V_16 )
return - V_18 ;
log -> V_19 = log -> V_16 + V_8 ;
memcpy ( log -> V_16 , F_8 ( V_9 ) , V_8 ) ;
return 0 ;
}
