int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
T_1 V_5 ;
void T_2 * V_6 ;
T_3 V_7 , V_8 ;
struct V_9 * log ;
if ( V_2 -> V_10 & V_11 )
return - V_12 ;
log = & V_2 -> log ;
if ( ! V_2 -> V_13 )
return - V_12 ;
V_5 = F_2 ( V_14 , 1 ,
(struct V_15 * * ) & V_4 ) ;
if ( F_3 ( V_5 ) )
return - V_12 ;
switch( V_4 -> V_16 ) {
case V_17 :
V_7 = V_4 -> V_18 . V_19 ;
V_8 = V_4 -> V_18 . V_20 ;
break;
case V_21 :
default:
V_7 = V_4 -> V_22 . V_19 ;
V_8 = V_4 -> V_22 . V_20 ;
break;
}
if ( ! V_7 ) {
F_4 ( & V_2 -> V_23 , L_1 , V_24 ) ;
return - V_25 ;
}
log -> V_26 = F_5 ( V_7 , V_27 ) ;
if ( ! log -> V_26 )
return - V_28 ;
log -> V_29 = log -> V_26 + V_7 ;
V_6 = F_6 ( V_8 , V_7 ) ;
if ( ! V_6 )
goto V_30;
F_7 ( log -> V_26 , V_6 , V_7 ) ;
F_8 ( V_6 , V_7 ) ;
return 0 ;
V_30:
F_9 ( log -> V_26 ) ;
log -> V_26 = NULL ;
return - V_25 ;
}
