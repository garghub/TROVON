int F_1 ( T_1 * V_1 )
{
return F_2 ( V_1 -> V_2 -> V_3 ) ;
}
T_2 * F_3 ( T_1 * V_1 , int V_4 )
{
return F_4 ( V_1 -> V_2 -> V_3 , V_4 ) ;
}
T_3 * F_5 ( T_2 * V_5 )
{
return V_5 -> V_6 ;
}
int F_6 ( T_4 * * V_7 , T_5 * * V_8 ,
T_4 * * V_9 ,
T_6 * * V_10 , T_3 * V_11 )
{
if ( ! V_11 ) return 0 ;
if ( V_8 ) * V_8 = V_11 -> V_12 -> V_13 ;
if( V_7 ) * V_7 = V_11 -> V_14 ;
if ( V_9 ) * V_9 = V_11 -> V_15 ;
if ( V_10 ) * V_10 = V_11 -> V_16 ;
return 1 ;
}
int F_7 ( T_1 * V_1 )
{
if( V_1 -> V_17 ) return 1 ;
return 0 ;
}
T_7 * F_8 ( int V_18 , T_8 * V_19 )
{
T_7 * V_20 = NULL ;
if ( ! ( V_20 = F_9 () ) ) goto V_21;
if ( ! ( F_10 ( V_20 -> V_22 , V_18 ) ) ) goto V_21;
if ( ! V_19 ) return V_20 ;
if ( ! ( V_20 -> V_23 = F_11 () ) ) goto V_21;
V_20 -> V_23 -> V_24 = F_12 ( V_25 ) ;
if ( ! F_13 ( V_19 , F_14 ( T_8 ) , & V_20 -> V_23 -> V_26 ) )
goto V_21;
return V_20 ;
V_21:
if ( V_20 ) F_15 ( V_20 ) ;
return NULL ;
}
T_9 * F_16 ( T_8 * V_20 ,
T_3 * V_11 ,
int V_18 , int V_27 ,
T_10 * V_28 ,
T_10 * V_29 , T_10 * V_30 )
{
T_9 * V_31 = NULL ;
T_11 * V_32 ;
T_12 * V_33 ;
if( ! V_20 -> V_34 -> V_35 &&
! ( V_20 -> V_34 -> V_35 = F_17 () ) )
goto V_21;
if ( ! ( V_31 = F_18 () ) )
goto V_21;
if ( ! F_19 ( V_29 , & V_31 -> V_36 ) )
goto V_21;
if ( V_30 &&
! F_19 ( V_30 , & V_31 -> V_37 ) )
goto V_21;
F_20 ( V_31 -> V_38 ) ;
if( ! ( V_31 -> V_38 = F_21 ( V_11 ) ) )
goto V_21;
V_32 = V_31 -> V_39 ;
switch( V_32 -> type = V_18 )
{
case V_40 :
if ( ! V_28 )
{
F_22 ( V_41 , V_42 ) ;
goto V_21;
}
if ( ! ( V_32 -> V_43 . V_44 = V_33 = F_23 () ) ) goto V_21;
if ( ! F_19 ( V_28 , & V_33 -> V_45 ) )
goto V_21;
if ( V_27 != V_46 )
{
if ( ! ( V_33 -> V_47 = F_24 () ) )
goto V_21;
if ( ! ( F_10 ( V_33 -> V_47 ,
V_27 ) ) )
goto V_21;
}
break;
case V_48 :
V_32 -> V_43 . V_49 = F_25 () ;
break;
case V_50 :
V_32 -> V_43 . V_51 = F_25 () ;
break;
default:
goto V_21;
}
if ( ! ( F_26 ( V_20 -> V_34 -> V_35 , V_31 ) ) )
goto V_21;
return V_31 ;
V_21:
F_27 ( V_31 ) ;
return NULL ;
}
int F_28 ( T_8 * V_52 , T_13 * V_53 )
{
if ( ! V_52 -> V_54 && ! ( V_52 -> V_54 = F_29 () ) )
return 0 ;
if( ! F_30 ( V_52 -> V_54 , V_53 ) ) return 0 ;
F_31 ( & V_53 -> V_55 , 1 , V_56 ) ;
return 1 ;
}
