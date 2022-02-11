const T_1 * F_1 ( void )
{
#ifdef F_2
return F_3 () ;
#else
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
0 , 0 , 0 ,
V_21 ,
V_22 ,
V_23 ,
V_24 ,
V_25 ,
V_26 ,
V_27 ,
V_28 ,
0 ,
0 ,
0 ,
V_29 ,
V_30 ,
0 ,
V_31 ,
V_32 ,
V_33 } ;
return & V_1 ;
#endif
}
int V_4 ( T_2 * V_34 )
{
int V_35 ;
V_35 = F_4 ( V_34 ) ;
V_34 -> V_36 = NULL ;
V_34 -> V_37 = NULL ;
return V_35 ;
}
void V_5 ( T_2 * V_34 )
{
if ( V_34 -> V_36 != NULL )
{
F_5 ( V_34 -> V_36 ) ;
V_34 -> V_36 = NULL ;
}
if ( V_34 -> V_37 != NULL )
{
F_6 ( V_34 -> V_37 ) ;
V_34 -> V_37 = NULL ;
}
F_7 ( V_34 ) ;
}
void V_6 ( T_2 * V_34 )
{
if ( V_34 -> V_36 != NULL )
{
F_5 ( V_34 -> V_36 ) ;
V_34 -> V_36 = NULL ;
}
if ( V_34 -> V_37 != NULL )
{
F_8 ( V_34 -> V_37 ) ;
V_34 -> V_37 = NULL ;
}
F_9 ( V_34 ) ;
}
int V_7 ( T_2 * V_38 , const T_2 * V_39 )
{
if ( V_38 -> V_36 != NULL )
{
F_5 ( V_38 -> V_36 ) ;
V_38 -> V_36 = NULL ;
}
if ( V_38 -> V_37 != NULL )
{
F_8 ( V_38 -> V_37 ) ;
V_38 -> V_37 = NULL ;
}
if ( ! F_10 ( V_38 , V_39 ) ) return 0 ;
if ( V_39 -> V_36 != NULL )
{
V_38 -> V_36 = F_11 () ;
if ( V_38 -> V_36 == NULL ) return 0 ;
if ( ! F_12 ( V_38 -> V_36 , V_39 -> V_36 ) ) goto V_40;
}
if ( V_39 -> V_37 != NULL )
{
V_38 -> V_37 = F_13 ( V_39 -> V_37 ) ;
if ( V_38 -> V_37 == NULL ) goto V_40;
}
return 1 ;
V_40:
if ( V_38 -> V_36 != NULL )
{
F_5 ( V_38 -> V_36 ) ;
V_38 -> V_36 = NULL ;
}
return 0 ;
}
int V_8 ( T_2 * V_34 , const T_3 * V_41 , const T_3 * V_42 , const T_3 * V_43 , T_4 * V_44 )
{
T_4 * V_45 = NULL ;
T_5 * V_46 = NULL ;
T_3 * V_47 = NULL ;
int V_1 = 0 ;
if ( V_34 -> V_36 != NULL )
{
F_5 ( V_34 -> V_36 ) ;
V_34 -> V_36 = NULL ;
}
if ( V_34 -> V_37 != NULL )
{
F_6 ( V_34 -> V_37 ) ;
V_34 -> V_37 = NULL ;
}
if ( V_44 == NULL )
{
V_44 = V_45 = F_14 () ;
if ( V_44 == NULL )
return 0 ;
}
V_46 = F_11 () ;
if ( V_46 == NULL ) goto V_40;
if ( ! F_15 ( V_46 , V_41 , V_44 ) )
{
F_16 ( V_48 , V_49 ) ;
goto V_40;
}
V_47 = F_17 () ;
if ( V_47 == NULL ) goto V_40;
if ( ! F_18 ( V_47 , F_19 () , V_46 , V_44 ) ) goto V_40;
V_34 -> V_36 = V_46 ;
V_46 = NULL ;
V_34 -> V_37 = V_47 ;
V_47 = NULL ;
V_1 = F_20 ( V_34 , V_41 , V_42 , V_43 , V_44 ) ;
if ( ! V_1 )
{
F_5 ( V_34 -> V_36 ) ;
V_34 -> V_36 = NULL ;
F_6 ( V_34 -> V_37 ) ;
V_34 -> V_37 = NULL ;
}
V_40:
if ( V_45 != NULL )
F_21 ( V_45 ) ;
if ( V_46 != NULL )
F_5 ( V_46 ) ;
return V_1 ;
}
int V_29 ( const T_2 * V_34 , T_3 * V_50 , const T_3 * V_42 , const T_3 * V_43 , T_4 * V_44 )
{
if ( V_34 -> V_36 == NULL )
{
F_16 ( V_51 , V_52 ) ;
return 0 ;
}
return F_22 ( V_50 , V_42 , V_43 , V_34 -> V_36 , V_44 ) ;
}
int V_30 ( const T_2 * V_34 , T_3 * V_50 , const T_3 * V_42 , T_4 * V_44 )
{
if ( V_34 -> V_36 == NULL )
{
F_16 ( V_53 , V_52 ) ;
return 0 ;
}
return F_22 ( V_50 , V_42 , V_42 , V_34 -> V_36 , V_44 ) ;
}
int V_31 ( const T_2 * V_34 , T_3 * V_50 , const T_3 * V_42 , T_4 * V_44 )
{
if ( V_34 -> V_36 == NULL )
{
F_16 ( V_54 , V_52 ) ;
return 0 ;
}
return F_18 ( V_50 , V_42 , ( T_5 * ) V_34 -> V_36 , V_44 ) ;
}
int V_32 ( const T_2 * V_34 , T_3 * V_50 , const T_3 * V_42 , T_4 * V_44 )
{
if ( V_34 -> V_36 == NULL )
{
F_16 ( V_55 , V_52 ) ;
return 0 ;
}
return F_23 ( V_50 , V_42 , V_34 -> V_36 , V_44 ) ;
}
int V_33 ( const T_2 * V_34 , T_3 * V_50 , T_4 * V_44 )
{
if ( V_34 -> V_37 == NULL )
{
F_16 ( V_56 , V_52 ) ;
return 0 ;
}
if ( ! F_24 ( V_50 , V_34 -> V_37 ) ) return 0 ;
return 1 ;
}
