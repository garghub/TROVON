static int F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
struct V_4 T_1 * V_5 )
{
int V_6 = - V_7 ;
struct V_8 * V_9 ;
V_9 = F_2 ( sizeof( * V_9 ) , V_10 ) ;
if ( ! V_9 )
return - V_11 ;
if ( F_3 ( V_9 , V_5 , sizeof( * V_5 ) ) ||
F_4 ( V_9 -> V_12 , & V_5 -> V_12 ) ||
F_4 ( V_9 -> V_13 , & V_5 -> V_13 ) )
goto error;
V_9 -> V_14 = NULL ;
V_6 = F_5 ( V_2 -> V_15 , V_3 , V_9 ) ;
if ( V_6 < 0 )
goto error;
if ( F_6 ( V_5 , V_9 , sizeof( * V_5 ) ) ||
F_7 ( V_9 -> V_12 , & V_5 -> V_12 ) ||
F_7 ( V_9 -> V_13 , & V_5 -> V_13 ) )
V_6 = - V_7 ;
error:
F_8 ( V_9 ) ;
return V_6 ;
}
static long F_9 ( struct V_16 * V_16 , unsigned int V_3 , unsigned long V_17 )
{
struct V_1 * V_2 = V_16 -> V_18 ;
void T_1 * V_19 = F_10 ( V_17 ) ;
if ( F_11 ( ! V_2 ) )
return - V_20 ;
switch ( V_3 ) {
case V_21 :
case V_22 :
case V_23 :
case V_24 :
case V_25 :
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
case V_31 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
case V_38 :
case V_39 :
case V_40 :
case V_41 :
case V_42 :
case V_43 :
case V_44 :
case V_45 :
case V_46 :
return F_12 ( V_16 , V_3 , V_17 ) ;
case V_47 :
return F_1 ( V_2 , V_48 , V_19 ) ;
case V_49 :
return F_1 ( V_2 , V_50 , V_19 ) ;
case V_51 :
return F_1 ( V_2 , V_52 , V_19 ) ;
case V_53 :
return F_1 ( V_2 , V_54 , V_19 ) ;
case V_55 :
return F_1 ( V_2 , V_56 , V_19 ) ;
}
return - V_57 ;
}
