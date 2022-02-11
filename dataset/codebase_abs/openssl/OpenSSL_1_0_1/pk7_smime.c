int F_1 ( T_1 * V_1 , T_2 * V_2 , int V_3 )
{
T_2 * V_4 ;
int V_5 = 0 ;
if ( ! ( V_4 = F_2 ( V_1 , NULL ) ) )
{
F_3 ( V_6 , V_7 ) ;
return 0 ;
}
F_4 ( V_2 , V_4 , V_3 ) ;
( void ) F_5 ( V_4 ) ;
if ( ! F_6 ( V_1 , V_4 ) )
{
F_3 ( V_6 , V_8 ) ;
goto V_9;
}
V_5 = 1 ;
V_9:
F_7 ( V_4 ) ;
return V_5 ;
}
T_3 * F_8 ( T_1 * V_1 , T_4 * V_10 ,
T_5 * V_11 , const T_6 * V_12 ,
int V_3 )
{
T_3 * V_13 = NULL ;
F_9 ( V_14 ) * V_15 = NULL ;
if( ! F_10 ( V_10 , V_11 ) )
{
F_3 ( V_16 ,
V_17 ) ;
return NULL ;
}
if ( ! ( V_13 = F_11 ( V_1 , V_10 , V_11 , V_12 ) ) )
{
F_3 ( V_16 ,
V_18 ) ;
return NULL ;
}
if( ! ( V_3 & V_19 ) )
{
if ( ! F_12 ( V_1 , V_10 ) )
goto V_9;
}
if( ! ( V_3 & V_20 ) )
{
if ( ! F_13 ( V_13 , NULL ) )
goto V_9;
if( ! ( V_3 & V_21 ) )
{
if( ! ( V_15 = F_14 () ) )
{
F_3 ( V_16 ,
V_7 ) ;
goto V_9;
}
if ( ! F_15 ( V_15 , V_22 , - 1 )
|| ! F_16 ( V_15 , V_23 , - 1 )
|| ! F_15 ( V_15 , V_24 , - 1 )
|| ! F_15 ( V_15 , V_25 , - 1 )
|| ! F_15 ( V_15 , V_26 , - 1 )
|| ! F_15 ( V_15 , V_27 , - 1 )
|| ! F_15 ( V_15 , V_28 , 128 )
|| ! F_15 ( V_15 , V_28 , 64 )
|| ! F_15 ( V_15 , V_29 , - 1 )
|| ! F_15 ( V_15 , V_28 , 40 )
|| ! F_17 ( V_13 , V_15 ) )
goto V_9;
F_18 ( V_15 , V_30 ) ;
V_15 = NULL ;
}
if ( V_3 & V_31 )
{
if ( ! F_19 ( V_1 , V_13 ) )
goto V_9;
if ( ! ( V_3 & V_32 ) &&
! F_20 ( V_13 ) )
goto V_9;
}
}
return V_13 ;
V_9:
if ( V_15 )
F_18 ( V_15 , V_30 ) ;
return NULL ;
}
static int F_19 ( T_1 * V_1 , T_3 * V_13 )
{
int V_33 ;
F_9 ( T_3 ) * V_34 ;
T_3 * V_35 ;
T_7 * V_36 = NULL ;
V_34 = F_21 ( V_1 ) ;
for ( V_33 = 0 ; V_33 < F_22 ( V_34 ) ; V_33 ++ )
{
V_35 = F_23 ( V_34 , V_33 ) ;
if ( V_13 == V_35 )
break;
if ( F_24 ( V_35 -> V_37 ) <= 0 )
continue;
if ( ! F_25 ( V_13 -> V_38 -> V_39 ,
V_35 -> V_38 -> V_39 ) )
{
V_36 = F_26 ( V_35 -> V_37 ) ;
break;
}
}
if ( V_36 )
return F_27 ( V_13 , V_36 -> V_2 , V_36 -> V_40 ) ;
F_3 ( V_41 ,
V_42 ) ;
return 0 ;
}
