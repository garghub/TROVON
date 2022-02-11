int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
T_1 V_5 ;
void T_2 * V_6 ;
T_3 V_7 , V_8 ;
struct V_9 * log ;
log = & V_2 -> log ;
if ( ! V_2 -> V_10 )
return - V_11 ;
V_5 = F_2 ( V_12 , 1 ,
(struct V_13 * * ) & V_4 ) ;
if ( F_3 ( V_5 ) )
return - V_11 ;
switch( V_4 -> V_14 ) {
case V_15 :
V_7 = V_4 -> V_16 . V_17 ;
V_8 = V_4 -> V_16 . V_18 ;
break;
case V_19 :
default:
V_7 = V_4 -> V_20 . V_17 ;
V_8 = V_4 -> V_20 . V_18 ;
break;
}
if ( ! V_7 ) {
F_4 ( & V_2 -> V_21 , L_1 , V_22 ) ;
return - V_23 ;
}
log -> V_24 = F_5 ( V_7 , V_25 ) ;
if ( ! log -> V_24 )
return - V_26 ;
log -> V_27 = log -> V_24 + V_7 ;
V_6 = F_6 ( V_8 , V_7 ) ;
if ( ! V_6 )
goto V_28;
F_7 ( log -> V_24 , V_6 , V_7 ) ;
F_8 ( V_6 , V_7 ) ;
return 0 ;
V_28:
F_9 ( log -> V_24 ) ;
log -> V_24 = NULL ;
return - V_23 ;
}
