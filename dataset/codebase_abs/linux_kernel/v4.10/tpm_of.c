int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
const T_1 * V_5 ;
const T_2 * V_6 ;
struct V_7 * log ;
log = & V_2 -> log ;
if ( V_2 -> V_8 . V_9 && V_2 -> V_8 . V_9 -> V_10 )
V_4 = V_2 -> V_8 . V_9 -> V_10 ;
else
return - V_11 ;
V_5 = F_2 ( V_4 , L_1 , NULL ) ;
V_6 = F_2 ( V_4 , L_2 , NULL ) ;
if ( V_5 == NULL && V_6 == NULL )
return - V_11 ;
if ( V_5 == NULL || V_6 == NULL )
return - V_12 ;
if ( * V_5 == 0 ) {
F_3 ( & V_2 -> V_8 , L_3 , V_13 ) ;
return - V_12 ;
}
log -> V_14 = F_4 ( * V_5 , V_15 ) ;
if ( ! log -> V_14 )
return - V_16 ;
log -> V_17 = log -> V_14 + * V_5 ;
memcpy ( log -> V_14 , F_5 ( * V_6 ) , * V_5 ) ;
return 0 ;
}
