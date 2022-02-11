const T_1 * F_1 ( void )
{
static const T_1 V_1 = {
V_2 ,
V_3 ,
V_4 ,
V_5 ,
V_6 ,
V_7 ,
V_8 ,
V_9 ,
V_10 ,
V_11 ,
V_12 ,
V_13 ,
V_14 ,
V_15 ,
V_16 ,
V_17 ,
V_18 ,
V_19 ,
V_20 ,
V_21 ,
V_22 ,
V_23 ,
V_24 ,
V_25 ,
V_26 ,
V_27 ,
V_28 ,
V_29 ,
V_30 ,
V_31 ,
V_32 ,
V_33 ,
V_34 ,
V_35 ,
V_36 } ;
return & V_1 ;
}
int V_2 ( T_2 * V_37 )
{
int V_38 ;
V_38 = F_2 ( V_37 ) ;
V_37 -> V_39 = NULL ;
V_37 -> V_40 = NULL ;
return V_38 ;
}
int V_6 ( T_2 * V_37 , const T_3 * V_41 , const T_3 * V_42 , const T_3 * V_43 , T_4 * V_44 )
{
T_4 * V_45 = NULL ;
T_5 * V_46 = NULL ;
T_3 * V_47 = NULL ;
int V_1 = 0 ;
if ( V_37 -> V_39 != NULL )
{
F_3 ( V_37 -> V_39 ) ;
V_37 -> V_39 = NULL ;
}
if ( V_37 -> V_40 != NULL )
{
F_4 ( V_37 -> V_40 ) ;
V_37 -> V_40 = NULL ;
}
if ( V_44 == NULL )
{
V_44 = V_45 = F_5 () ;
if ( V_44 == NULL )
return 0 ;
}
V_46 = F_6 () ;
if ( V_46 == NULL ) goto V_48;
if ( ! F_7 ( V_46 , V_41 , V_44 ) )
{
F_8 ( V_49 , V_50 ) ;
goto V_48;
}
V_47 = F_9 () ;
if ( V_47 == NULL ) goto V_48;
if ( ! F_10 ( V_47 , F_11 () , V_46 , V_44 ) ) goto V_48;
V_37 -> V_39 = V_46 ;
V_46 = NULL ;
V_37 -> V_40 = V_47 ;
V_47 = NULL ;
V_1 = F_12 ( V_37 , V_41 , V_42 , V_43 , V_44 ) ;
if ( ! V_1 )
{
F_3 ( V_37 -> V_39 ) ;
V_37 -> V_39 = NULL ;
F_4 ( V_37 -> V_40 ) ;
V_37 -> V_40 = NULL ;
}
V_48:
if ( V_45 != NULL )
F_13 ( V_45 ) ;
if ( V_46 != NULL )
F_3 ( V_46 ) ;
return V_1 ;
}
void V_3 ( T_2 * V_37 )
{
if ( V_37 -> V_39 != NULL )
{
F_3 ( V_37 -> V_39 ) ;
V_37 -> V_39 = NULL ;
}
if ( V_37 -> V_40 != NULL )
{
F_4 ( V_37 -> V_40 ) ;
V_37 -> V_40 = NULL ;
}
F_14 ( V_37 ) ;
}
void V_4 ( T_2 * V_37 )
{
if ( V_37 -> V_39 != NULL )
{
F_3 ( V_37 -> V_39 ) ;
V_37 -> V_39 = NULL ;
}
if ( V_37 -> V_40 != NULL )
{
F_15 ( V_37 -> V_40 ) ;
V_37 -> V_40 = NULL ;
}
F_16 ( V_37 ) ;
}
int V_5 ( T_2 * V_51 , const T_2 * V_52 )
{
if ( V_51 -> V_39 != NULL )
{
F_3 ( V_51 -> V_39 ) ;
V_51 -> V_39 = NULL ;
}
if ( V_51 -> V_40 != NULL )
{
F_15 ( V_51 -> V_40 ) ;
V_51 -> V_40 = NULL ;
}
if ( ! F_17 ( V_51 , V_52 ) ) return 0 ;
if ( V_52 -> V_39 != NULL )
{
V_51 -> V_39 = F_6 () ;
if ( V_51 -> V_39 == NULL ) return 0 ;
if ( ! F_18 ( V_51 -> V_39 , V_52 -> V_39 ) ) goto V_48;
}
if ( V_52 -> V_40 != NULL )
{
V_51 -> V_40 = F_19 ( V_52 -> V_40 ) ;
if ( V_51 -> V_40 == NULL ) goto V_48;
}
return 1 ;
V_48:
if ( V_51 -> V_39 != NULL )
{
F_3 ( V_51 -> V_39 ) ;
V_51 -> V_39 = NULL ;
}
return 0 ;
}
int V_32 ( const T_2 * V_37 , T_3 * V_53 , const T_3 * V_42 , const T_3 * V_43 , T_4 * V_44 )
{
if ( V_37 -> V_39 == NULL )
{
F_8 ( V_54 , V_55 ) ;
return 0 ;
}
return F_20 ( V_53 , V_42 , V_43 , V_37 -> V_39 , V_44 ) ;
}
int V_33 ( const T_2 * V_37 , T_3 * V_53 , const T_3 * V_42 , T_4 * V_44 )
{
if ( V_37 -> V_39 == NULL )
{
F_8 ( V_56 , V_55 ) ;
return 0 ;
}
return F_20 ( V_53 , V_42 , V_42 , V_37 -> V_39 , V_44 ) ;
}
int V_34 ( const T_2 * V_37 , T_3 * V_53 , const T_3 * V_42 , T_4 * V_44 )
{
if ( V_37 -> V_39 == NULL )
{
F_8 ( V_57 , V_55 ) ;
return 0 ;
}
return F_10 ( V_53 , V_42 , ( T_5 * ) V_37 -> V_39 , V_44 ) ;
}
int V_35 ( const T_2 * V_37 , T_3 * V_53 , const T_3 * V_42 , T_4 * V_44 )
{
if ( V_37 -> V_39 == NULL )
{
F_8 ( V_58 , V_55 ) ;
return 0 ;
}
return F_21 ( V_53 , V_42 , V_37 -> V_39 , V_44 ) ;
}
int V_36 ( const T_2 * V_37 , T_3 * V_53 , T_4 * V_44 )
{
if ( V_37 -> V_40 == NULL )
{
F_8 ( V_58 , V_55 ) ;
return 0 ;
}
if ( ! F_22 ( V_53 , V_37 -> V_40 ) ) return 0 ;
return 1 ;
}
