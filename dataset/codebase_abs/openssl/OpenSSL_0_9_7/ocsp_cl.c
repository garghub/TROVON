T_1 * F_1 ( T_2 * V_1 , T_3 * V_2 )
{
T_1 * V_3 = NULL ;
if ( ! ( V_3 = F_2 () ) ) goto V_4;
if ( V_3 -> V_5 ) F_3 ( V_3 -> V_5 ) ;
V_3 -> V_5 = V_2 ;
if ( V_1 &&
! F_4 ( V_1 -> V_6 -> V_7 , V_3 ) )
goto V_4;
return V_3 ;
V_4:
F_5 ( V_3 ) ;
return NULL ;
}
int F_6 ( T_2 * V_1 , T_4 * V_8 )
{
T_5 * V_9 ;
V_9 = F_7 () ;
if ( ! F_8 ( & V_9 -> V_10 . V_11 , V_8 ) )
{
F_9 ( V_9 ) ;
return 0 ;
}
V_9 -> type = V_12 ;
if ( V_1 -> V_6 -> V_13 )
F_9 ( V_1 -> V_6 -> V_13 ) ;
V_1 -> V_6 -> V_13 = V_9 ;
return 1 ;
}
int F_10 ( T_2 * V_1 , T_6 * V_14 )
{
T_7 * V_15 ;
if ( ! V_1 -> V_16 )
V_1 -> V_16 = F_11 () ;
V_15 = V_1 -> V_16 ;
if ( ! V_15 ) return 0 ;
if ( ! V_14 ) return 1 ;
if ( ! V_15 -> V_17 && ! ( V_15 -> V_17 = F_12 () ) )
return 0 ;
if( ! F_13 ( V_15 -> V_17 , V_14 ) ) return 0 ;
F_14 ( & V_14 -> V_18 , 1 , V_19 ) ;
return 1 ;
}
int F_15 ( T_8 * V_20 )
{
return F_16 ( V_20 -> V_21 ) ;
}
T_9 * F_17 ( T_8 * V_20 )
{
T_10 * V_22 ;
V_22 = V_20 -> V_23 ;
if ( ! V_22 )
{
F_18 ( V_24 , V_25 ) ;
return NULL ;
}
if ( F_19 ( V_22 -> V_26 ) != V_27 )
{
F_18 ( V_24 , V_28 ) ;
return NULL ;
}
return F_20 ( V_22 -> V_29 , F_21 ( T_9 ) ) ;
}
int F_22 ( T_9 * V_30 )
{
if ( ! V_30 ) return - 1 ;
return F_23 ( V_30 -> V_31 -> V_32 ) ;
}
T_11 * F_24 ( T_9 * V_30 , int V_33 )
{
if ( ! V_30 ) return NULL ;
return F_25 ( V_30 -> V_31 -> V_32 , V_33 ) ;
}
int F_26 ( T_9 * V_30 , T_3 * V_34 , int V_35 )
{
int V_36 ;
F_27 ( T_11 ) * V_37 ;
T_11 * V_38 ;
if ( ! V_30 ) return - 1 ;
if ( V_35 < 0 ) V_35 = 0 ;
else V_35 ++ ;
V_37 = V_30 -> V_31 -> V_32 ;
for ( V_36 = V_35 ; V_36 < F_23 ( V_37 ) ; V_36 ++ )
{
V_38 = F_25 ( V_37 , V_36 ) ;
if ( ! F_28 ( V_34 , V_38 -> V_39 ) ) return V_36 ;
}
return - 1 ;
}
int F_29 ( T_11 * V_38 , int * V_40 ,
T_12 * * V_41 ,
T_12 * * V_42 ,
T_12 * * V_43 )
{
int V_44 ;
T_13 * V_45 ;
if( ! V_38 ) return - 1 ;
V_45 = V_38 -> V_46 ;
V_44 = V_45 -> type ;
if ( V_44 == V_47 )
{
T_14 * V_48 = V_45 -> V_49 . V_50 ;
if ( V_41 ) * V_41 = V_48 -> V_51 ;
if ( V_40 )
{
if( V_48 -> V_52 )
* V_40 = F_16 ( V_48 -> V_52 ) ;
else * V_40 = - 1 ;
}
}
if( V_42 ) * V_42 = V_38 -> V_53 ;
if( V_43 ) * V_43 = V_38 -> V_54 ;
return V_44 ;
}
int F_30 ( T_9 * V_30 , T_3 * V_34 , int * V_55 ,
int * V_40 ,
T_12 * * V_41 ,
T_12 * * V_42 ,
T_12 * * V_43 )
{
int V_36 ;
T_11 * V_38 ;
V_36 = F_26 ( V_30 , V_34 , - 1 ) ;
if( V_36 < 0 ) return 0 ;
V_38 = F_24 ( V_30 , V_36 ) ;
V_36 = F_29 ( V_38 , V_40 , V_41 , V_42 , V_43 ) ;
if( V_55 ) * V_55 = V_36 ;
return 1 ;
}
int F_31 ( T_12 * V_42 , T_12 * V_43 , long V_56 , long V_57 )
{
int V_44 = 1 ;
T_15 V_58 , V_59 ;
time ( & V_58 ) ;
if ( ! F_32 ( V_42 ) )
{
F_18 ( V_60 , V_61 ) ;
V_44 = 0 ;
}
else
{
V_59 = V_58 + V_56 ;
if ( F_33 ( V_42 , & V_59 ) > 0 )
{
F_18 ( V_60 , V_62 ) ;
V_44 = 0 ;
}
if ( V_57 >= 0 )
{
V_59 = V_58 - V_57 ;
if ( F_33 ( V_42 , & V_59 ) < 0 )
{
F_18 ( V_60 , V_63 ) ;
V_44 = 0 ;
}
}
}
if ( ! V_43 ) return V_44 ;
if ( ! F_32 ( V_43 ) )
{
F_18 ( V_60 , V_64 ) ;
V_44 = 0 ;
}
else
{
V_59 = V_58 - V_56 ;
if ( F_33 ( V_43 , & V_59 ) < 0 )
{
F_18 ( V_60 , V_65 ) ;
V_44 = 0 ;
}
}
if ( F_34 ( V_43 , V_42 ) < 0 )
{
F_18 ( V_60 , V_66 ) ;
V_44 = 0 ;
}
return V_44 ;
}
