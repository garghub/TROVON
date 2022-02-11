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
0 ,
0 ,
0 } ;
return & V_1 ;
#endif
}
int V_7 ( T_2 * V_31 , const T_2 * V_32 )
{
V_31 -> V_33 = V_32 -> V_33 ;
return F_4 ( V_31 , V_32 ) ;
}
int V_8 ( T_2 * V_34 , const T_3 * V_35 ,
const T_3 * V_36 , const T_3 * V_37 , T_4 * V_38 )
{
int V_1 = 0 ;
T_4 * V_39 = NULL ;
T_3 * V_40 ;
if ( V_38 == NULL )
if ( ( V_38 = V_39 = F_5 () ) == NULL ) return 0 ;
F_6 ( V_38 ) ;
if ( ( V_40 = F_7 ( V_38 ) ) == NULL ) goto V_41;
if ( F_8 ( F_9 () , V_35 ) == 0 )
V_34 -> V_33 = V_42 ;
else if ( F_8 ( F_10 () , V_35 ) == 0 )
V_34 -> V_33 = V_43 ;
else if ( F_8 ( F_11 () , V_35 ) == 0 )
V_34 -> V_33 = V_44 ;
else if ( F_8 ( F_12 () , V_35 ) == 0 )
V_34 -> V_33 = V_45 ;
else if ( F_8 ( F_13 () , V_35 ) == 0 )
V_34 -> V_33 = V_46 ;
else
{
F_14 ( V_47 , V_48 ) ;
goto V_41;
}
V_1 = F_15 ( V_34 , V_35 , V_36 , V_37 , V_38 ) ;
V_41:
F_16 ( V_38 ) ;
if ( V_39 != NULL )
F_17 ( V_39 ) ;
return V_1 ;
}
int V_29 ( const T_2 * V_34 , T_3 * V_49 , const T_3 * V_36 ,
const T_3 * V_37 , T_4 * V_38 )
{
int V_1 = 0 ;
T_4 * V_50 = NULL ;
if ( ! V_34 || ! V_49 || ! V_36 || ! V_37 )
{
F_14 ( V_51 , V_52 ) ;
goto V_41;
}
if ( ! V_38 )
if ( ( V_50 = V_38 = F_5 () ) == NULL ) goto V_41;
if ( ! F_18 ( V_49 , V_36 , V_37 , V_38 ) ) goto V_41;
if ( ! V_34 -> V_33 ( V_49 , V_49 , & V_34 -> V_53 , V_38 ) )
goto V_41;
V_1 = 1 ;
V_41:
if ( V_50 )
F_17 ( V_50 ) ;
return V_1 ;
}
int V_30 ( const T_2 * V_34 , T_3 * V_49 , const T_3 * V_36 ,
T_4 * V_38 )
{
int V_1 = 0 ;
T_4 * V_50 = NULL ;
if ( ! V_34 || ! V_49 || ! V_36 )
{
F_14 ( V_54 , V_55 ) ;
goto V_41;
}
if ( ! V_38 )
if ( ( V_50 = V_38 = F_5 () ) == NULL ) goto V_41;
if ( ! F_19 ( V_49 , V_36 , V_38 ) ) goto V_41;
if ( ! V_34 -> V_33 ( V_49 , V_49 , & V_34 -> V_53 , V_38 ) )
goto V_41;
V_1 = 1 ;
V_41:
if ( V_50 )
F_17 ( V_50 ) ;
return V_1 ;
}
