static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
return sprintf ( V_5 , L_1 , V_9 -> V_10 -> V_11 ) ;
}
int F_4 ( struct V_8 * V_12 , struct V_8 * V_9 ,
T_2 V_13 , int type )
{
int V_14 ;
V_9 -> V_15 = V_12 -> V_15 ;
V_9 -> V_7 -> V_16 = F_5 ( V_9 -> V_15 ) ;
V_9 -> V_17 = V_9 -> V_18 = V_9 -> V_7 -> V_16 ;
V_9 -> V_10 = V_12 -> V_7 ;
F_6 ( V_19 , & V_9 -> V_20 ) ;
V_14 = F_7 ( V_9 , V_12 -> V_21 ) ;
if ( V_14 )
goto V_22;
V_9 -> V_13 = V_13 ;
memcpy ( V_9 -> V_7 -> V_23 , V_12 -> V_7 -> V_23 , V_24 ) ;
memcpy ( & V_9 -> V_25 , & V_12 -> V_25 , sizeof( V_9 -> V_25 ) ) ;
F_6 ( V_26 , & V_9 -> V_20 ) ;
V_9 -> V_7 -> V_27 [ 8 ] = V_13 >> 8 ;
V_9 -> V_7 -> V_27 [ 9 ] = V_13 & 0xff ;
V_14 = F_8 ( V_9 -> V_7 , V_12 -> V_21 , V_12 -> V_28 ) ;
if ( V_14 < 0 ) {
F_9 ( V_12 , L_2
L_3 ,
V_12 -> V_21 -> V_11 , V_12 -> V_28 ) ;
goto V_22;
}
V_14 = F_10 ( V_9 -> V_7 ) ;
if ( V_14 ) {
F_9 ( V_9 , L_4 , V_14 ) ;
goto V_29;
}
F_11 ( V_9 -> V_7 ) ;
if ( type == V_30 ) {
if ( F_12 ( V_9 -> V_7 ) )
goto V_31;
if ( F_13 ( V_9 -> V_7 ) )
goto V_31;
if ( F_14 ( V_9 -> V_7 ) )
goto V_31;
if ( F_15 ( & V_9 -> V_7 -> V_7 , & V_32 ) )
goto V_31;
}
V_9 -> V_33 = type ;
F_16 ( & V_9 -> V_34 , & V_12 -> V_35 ) ;
return 0 ;
V_31:
V_14 = - V_36 ;
F_17 ( V_9 -> V_7 ) ;
F_18 ( V_9 -> V_7 ) ;
V_29:
F_19 ( V_9 -> V_7 ) ;
V_22:
return V_14 ;
}
int F_20 ( struct V_6 * V_37 , unsigned short V_13 )
{
struct V_8 * V_12 , * V_9 ;
char V_38 [ V_39 ] ;
struct V_8 * V_40 ;
int V_14 ;
if ( ! F_21 ( V_41 ) )
return - V_42 ;
V_12 = F_3 ( V_37 ) ;
if ( F_22 ( V_43 , & V_12 -> V_20 ) )
return - V_42 ;
snprintf ( V_38 , sizeof V_38 , L_5 ,
V_12 -> V_7 -> V_11 , V_13 ) ;
V_9 = F_23 ( V_38 ) ;
if ( ! V_9 )
return - V_36 ;
if ( ! F_24 () )
return F_25 () ;
F_26 ( & V_12 -> V_44 ) ;
if ( V_12 -> V_13 == V_13 ) {
V_14 = - V_45 ;
goto V_46;
}
F_27 (tpriv, &ppriv->child_intfs, list) {
if ( V_40 -> V_13 == V_13 &&
V_40 -> V_33 == V_30 ) {
V_14 = - V_45 ;
goto V_46;
}
}
V_14 = F_4 ( V_12 , V_9 , V_13 , V_30 ) ;
V_46:
F_28 ( & V_12 -> V_44 ) ;
if ( V_14 )
F_29 ( V_9 -> V_7 ) ;
F_30 () ;
return V_14 ;
}
int F_31 ( struct V_6 * V_37 , unsigned short V_13 )
{
struct V_8 * V_12 , * V_9 , * V_40 ;
struct V_6 * V_7 = NULL ;
if ( ! F_21 ( V_41 ) )
return - V_42 ;
V_12 = F_3 ( V_37 ) ;
if ( F_22 ( V_43 , & V_12 -> V_20 ) )
return - V_42 ;
if ( ! F_24 () )
return F_25 () ;
F_26 ( & V_12 -> V_44 ) ;
F_32 (priv, tpriv, &ppriv->child_intfs, list) {
if ( V_9 -> V_13 == V_13 &&
V_9 -> V_33 == V_30 ) {
F_18 ( V_9 -> V_7 ) ;
F_33 ( & V_9 -> V_34 ) ;
V_7 = V_9 -> V_7 ;
break;
}
}
F_28 ( & V_12 -> V_44 ) ;
F_30 () ;
if ( V_7 ) {
F_29 ( V_7 ) ;
return 0 ;
}
return - V_47 ;
}
