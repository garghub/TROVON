int F_1 ( struct V_1 * log )
{
struct V_2 * V_3 ;
T_1 V_4 ;
void T_2 * V_5 ;
T_3 V_6 , V_7 ;
if ( log -> V_8 != NULL ) {
F_2 ( V_9
L_1 ,
V_10 ) ;
return - V_11 ;
}
V_4 = F_3 ( V_12 , 1 ,
(struct V_13 * * ) & V_3 ) ;
if ( F_4 ( V_4 ) ) {
F_2 ( V_9 L_2 ,
V_10 ) ;
return - V_14 ;
}
switch( V_3 -> V_15 ) {
case V_16 :
V_6 = V_3 -> V_17 . V_18 ;
V_7 = V_3 -> V_17 . V_19 ;
break;
case V_20 :
default:
V_6 = V_3 -> V_21 . V_18 ;
V_7 = V_3 -> V_21 . V_19 ;
break;
}
if ( ! V_6 ) {
F_2 ( V_9 L_3 , V_10 ) ;
return - V_14 ;
}
log -> V_8 = F_5 ( V_6 , V_22 ) ;
if ( ! log -> V_8 ) {
F_2 ( L_4 ,
V_10 ) ;
return - V_23 ;
}
log -> V_24 = log -> V_8 + V_6 ;
V_5 = F_6 ( V_7 , V_6 ) ;
if ( ! V_5 ) {
F_7 ( log -> V_8 ) ;
F_2 ( L_5 , V_10 ) ;
return - V_14 ;
}
F_8 ( log -> V_8 , V_5 , V_6 ) ;
F_9 ( V_5 , V_6 ) ;
return 0 ;
}
