static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
return sprintf ( V_5 , L_1 , V_9 -> V_10 -> V_11 ) ;
}
int F_4 ( struct V_6 * V_12 , unsigned short V_13 )
{
struct V_8 * V_14 , * V_9 ;
char V_15 [ V_16 ] ;
int V_17 ;
if ( ! F_5 ( V_18 ) )
return - V_19 ;
V_14 = F_3 ( V_12 ) ;
if ( ! F_6 () )
return F_7 () ;
F_8 ( & V_14 -> V_20 ) ;
if ( V_14 -> V_13 == V_13 ) {
V_17 = - V_21 ;
V_9 = NULL ;
goto V_22;
}
F_9 (priv, &ppriv->child_intfs, list) {
if ( V_9 -> V_13 == V_13 ) {
V_17 = - V_21 ;
V_9 = NULL ;
goto V_22;
}
}
snprintf ( V_15 , sizeof V_15 , L_2 ,
V_14 -> V_7 -> V_11 , V_13 ) ;
V_9 = F_10 ( V_15 ) ;
if ( ! V_9 ) {
V_17 = - V_23 ;
goto V_22;
}
V_9 -> V_24 = V_14 -> V_24 ;
V_9 -> V_7 -> V_25 = F_11 ( V_9 -> V_24 ) ;
V_9 -> V_26 = V_9 -> V_27 = V_9 -> V_7 -> V_25 ;
F_12 ( V_28 , & V_9 -> V_29 ) ;
V_17 = F_13 ( V_9 , V_14 -> V_30 ) ;
if ( V_17 )
goto V_22;
V_9 -> V_13 = V_13 ;
memcpy ( V_9 -> V_7 -> V_31 , V_14 -> V_7 -> V_31 , V_32 ) ;
V_9 -> V_7 -> V_33 [ 8 ] = V_13 >> 8 ;
V_9 -> V_7 -> V_33 [ 9 ] = V_13 & 0xff ;
V_17 = F_14 ( V_9 -> V_7 , V_14 -> V_30 , V_14 -> V_34 ) ;
if ( V_17 < 0 ) {
F_15 ( V_14 , L_3
L_4 ,
V_14 -> V_30 -> V_11 , V_14 -> V_34 ) ;
goto V_22;
}
V_17 = F_16 ( V_9 -> V_7 ) ;
if ( V_17 ) {
F_15 ( V_9 , L_5 , V_17 ) ;
goto V_35;
}
V_9 -> V_10 = V_14 -> V_7 ;
F_17 ( V_9 -> V_7 ) ;
if ( F_18 ( V_9 -> V_7 ) )
goto V_36;
if ( F_19 ( V_9 -> V_7 ) )
goto V_36;
if ( F_20 ( V_9 -> V_7 ) )
goto V_36;
if ( F_21 ( & V_9 -> V_7 -> V_7 , & V_37 ) )
goto V_36;
F_22 ( & V_9 -> V_38 , & V_14 -> V_39 ) ;
F_23 ( & V_14 -> V_20 ) ;
F_24 () ;
return 0 ;
V_36:
F_25 ( V_9 -> V_7 ) ;
F_26 ( V_9 -> V_7 ) ;
V_35:
F_27 ( V_9 -> V_7 ) ;
V_22:
F_23 ( & V_14 -> V_20 ) ;
F_24 () ;
if ( V_9 )
F_28 ( V_9 -> V_7 ) ;
return V_17 ;
}
int F_29 ( struct V_6 * V_12 , unsigned short V_13 )
{
struct V_8 * V_14 , * V_9 , * V_40 ;
struct V_6 * V_7 = NULL ;
if ( ! F_5 ( V_18 ) )
return - V_19 ;
V_14 = F_3 ( V_12 ) ;
if ( ! F_6 () )
return F_7 () ;
F_8 ( & V_14 -> V_20 ) ;
F_30 (priv, tpriv, &ppriv->child_intfs, list) {
if ( V_9 -> V_13 == V_13 ) {
F_26 ( V_9 -> V_7 ) ;
F_27 ( V_9 -> V_7 ) ;
F_31 ( & V_9 -> V_38 ) ;
V_7 = V_9 -> V_7 ;
break;
}
}
F_23 ( & V_14 -> V_20 ) ;
F_24 () ;
if ( V_7 ) {
F_28 ( V_7 ) ;
return 0 ;
}
return - V_41 ;
}
