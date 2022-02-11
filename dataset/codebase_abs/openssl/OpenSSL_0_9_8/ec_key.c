T_1 * F_1 ( void )
{
T_1 * V_1 ;
V_1 = ( T_1 * ) F_2 ( sizeof( T_1 ) ) ;
if ( V_1 == NULL )
{
F_3 ( V_2 , V_3 ) ;
return ( NULL ) ;
}
V_1 -> V_4 = 1 ;
V_1 -> V_5 = NULL ;
V_1 -> V_6 = NULL ;
V_1 -> V_7 = NULL ;
V_1 -> V_8 = 0 ;
V_1 -> V_9 = V_10 ;
V_1 -> V_11 = 1 ;
V_1 -> V_12 = NULL ;
return ( V_1 ) ;
}
T_1 * F_4 ( int V_13 )
{
T_1 * V_1 = F_1 () ;
if ( V_1 == NULL )
return NULL ;
V_1 -> V_5 = F_5 ( V_13 ) ;
if ( V_1 -> V_5 == NULL )
{
F_6 ( V_1 ) ;
return NULL ;
}
return V_1 ;
}
void F_6 ( T_1 * V_14 )
{
int V_15 ;
if ( V_14 == NULL ) return;
V_15 = F_7 ( & V_14 -> V_11 , - 1 , V_16 ) ;
#ifdef F_8
F_8 ( L_1 , V_14 ) ;
#endif
if ( V_15 > 0 ) return;
#ifdef F_9
if ( V_15 < 0 )
{
fprintf ( V_17 , L_2 ) ;
abort () ;
}
#endif
if ( V_14 -> V_5 != NULL )
F_10 ( V_14 -> V_5 ) ;
if ( V_14 -> V_6 != NULL )
F_11 ( V_14 -> V_6 ) ;
if ( V_14 -> V_7 != NULL )
F_12 ( V_14 -> V_7 ) ;
F_13 ( & V_14 -> V_12 ) ;
F_14 ( ( void * ) V_14 , sizeof( T_1 ) ) ;
F_15 ( V_14 ) ;
}
T_1 * F_16 ( T_1 * V_18 , const T_1 * V_19 )
{
T_2 * V_20 ;
if ( V_18 == NULL || V_19 == NULL )
{
F_3 ( V_21 , V_22 ) ;
return NULL ;
}
if ( V_19 -> V_5 )
{
const T_3 * V_23 = F_17 ( V_19 -> V_5 ) ;
if ( V_18 -> V_5 )
F_10 ( V_18 -> V_5 ) ;
V_18 -> V_5 = F_18 ( V_23 ) ;
if ( V_18 -> V_5 == NULL )
return NULL ;
if ( ! F_19 ( V_18 -> V_5 , V_19 -> V_5 ) )
return NULL ;
}
if ( V_19 -> V_6 && V_19 -> V_5 )
{
if ( V_18 -> V_6 )
F_11 ( V_18 -> V_6 ) ;
V_18 -> V_6 = F_20 ( V_19 -> V_5 ) ;
if ( V_18 -> V_6 == NULL )
return NULL ;
if ( ! F_21 ( V_18 -> V_6 , V_19 -> V_6 ) )
return NULL ;
}
if ( V_19 -> V_7 )
{
if ( V_18 -> V_7 == NULL )
{
V_18 -> V_7 = F_22 () ;
if ( V_18 -> V_7 == NULL )
return NULL ;
}
if ( ! F_23 ( V_18 -> V_7 , V_19 -> V_7 ) )
return NULL ;
}
F_13 ( & V_18 -> V_12 ) ;
for ( V_20 = V_19 -> V_12 ; V_20 != NULL ; V_20 = V_20 -> V_24 )
{
void * V_25 = V_20 -> V_26 ( V_20 -> V_27 ) ;
if ( V_25 == NULL )
return 0 ;
if ( ! F_24 ( & V_18 -> V_12 , V_25 , V_20 -> V_26 , V_20 -> V_28 , V_20 -> V_29 ) )
return 0 ;
}
V_18 -> V_8 = V_19 -> V_8 ;
V_18 -> V_9 = V_19 -> V_9 ;
V_18 -> V_4 = V_19 -> V_4 ;
return V_18 ;
}
T_1 * F_25 ( const T_1 * V_30 )
{
T_1 * V_1 = F_1 () ;
if ( V_1 == NULL )
return NULL ;
if ( F_16 ( V_1 , V_30 ) == NULL )
{
F_6 ( V_1 ) ;
return NULL ;
}
return V_1 ;
}
int F_26 ( T_1 * V_14 )
{
int V_15 = F_7 ( & V_14 -> V_11 , 1 , V_16 ) ;
#ifdef F_8
F_8 ( L_1 , V_14 ) ;
#endif
#ifdef F_9
if ( V_15 < 2 )
{
fprintf ( V_17 , L_3 ) ;
abort () ;
}
#endif
return ( ( V_15 > 1 ) ? 1 : 0 ) ;
}
int F_27 ( T_1 * V_31 )
{
int V_32 = 0 ;
T_4 * V_33 = NULL ;
T_5 * V_7 = NULL , * V_34 = NULL ;
T_6 * V_6 = NULL ;
if ( ! V_31 || ! V_31 -> V_5 )
{
F_3 ( V_35 , V_22 ) ;
return 0 ;
}
if ( ( V_34 = F_22 () ) == NULL ) goto V_36;
if ( ( V_33 = F_28 () ) == NULL ) goto V_36;
if ( V_31 -> V_7 == NULL )
{
V_7 = F_22 () ;
if ( V_7 == NULL )
goto V_36;
}
else
V_7 = V_31 -> V_7 ;
if ( ! F_29 ( V_31 -> V_5 , V_34 , V_33 ) )
goto V_36;
do
if ( ! F_30 ( V_7 , V_34 ) )
goto V_36;
while ( F_31 ( V_7 ) );
if ( V_31 -> V_6 == NULL )
{
V_6 = F_20 ( V_31 -> V_5 ) ;
if ( V_6 == NULL )
goto V_36;
}
else
V_6 = V_31 -> V_6 ;
if ( ! F_32 ( V_31 -> V_5 , V_6 , V_7 , NULL , NULL , V_33 ) )
goto V_36;
V_31 -> V_7 = V_7 ;
V_31 -> V_6 = V_6 ;
V_32 = 1 ;
V_36:
if ( V_34 )
F_33 ( V_34 ) ;
if ( V_6 != NULL && V_31 -> V_6 == NULL )
F_11 ( V_6 ) ;
if ( V_7 != NULL && V_31 -> V_7 == NULL )
F_33 ( V_7 ) ;
if ( V_33 != NULL )
F_34 ( V_33 ) ;
return ( V_32 ) ;
}
int F_35 ( const T_1 * V_31 )
{
int V_32 = 0 ;
T_4 * V_33 = NULL ;
T_5 * V_34 = NULL ;
T_6 * V_37 = NULL ;
if ( ! V_31 || ! V_31 -> V_5 || ! V_31 -> V_6 )
{
F_3 ( V_38 , V_22 ) ;
return 0 ;
}
if ( ( V_33 = F_28 () ) == NULL )
goto V_36;
if ( ( V_34 = F_22 () ) == NULL )
goto V_36;
if ( ( V_37 = F_20 ( V_31 -> V_5 ) ) == NULL )
goto V_36;
if ( ! F_36 ( V_31 -> V_5 , V_31 -> V_6 , V_33 ) )
{
F_3 ( V_38 , V_39 ) ;
goto V_36;
}
if ( ! F_29 ( V_31 -> V_5 , V_34 , V_33 ) )
{
F_3 ( V_38 , V_40 ) ;
goto V_36;
}
if ( ! F_21 ( V_37 , V_31 -> V_6 ) )
{
F_3 ( V_38 , V_41 ) ;
goto V_36;
}
if ( ! F_32 ( V_31 -> V_5 , V_37 , V_34 , NULL , NULL , V_33 ) )
{
F_3 ( V_38 , V_41 ) ;
goto V_36;
}
if ( ! F_37 ( V_31 -> V_5 , V_37 ) )
{
F_3 ( V_38 , V_42 ) ;
goto V_36;
}
if ( V_31 -> V_7 )
{
if ( F_38 ( V_31 -> V_7 , V_34 ) >= 0 )
{
F_3 ( V_38 , V_42 ) ;
goto V_36;
}
if ( ! F_32 ( V_31 -> V_5 , V_37 , V_31 -> V_7 ,
NULL , NULL , V_33 ) )
{
F_3 ( V_38 , V_41 ) ;
goto V_36;
}
if ( F_39 ( V_31 -> V_5 , V_37 , V_31 -> V_6 ,
V_33 ) != 0 )
{
F_3 ( V_38 , V_43 ) ;
goto V_36;
}
}
V_32 = 1 ;
V_36:
if ( V_33 != NULL )
F_34 ( V_33 ) ;
if ( V_34 != NULL )
F_33 ( V_34 ) ;
if ( V_37 != NULL )
F_11 ( V_37 ) ;
return ( V_32 ) ;
}
const T_7 * F_40 ( const T_1 * V_44 )
{
return V_44 -> V_5 ;
}
int F_41 ( T_1 * V_44 , const T_7 * V_5 )
{
if ( V_44 -> V_5 != NULL )
F_10 ( V_44 -> V_5 ) ;
V_44 -> V_5 = F_42 ( V_5 ) ;
return ( V_44 -> V_5 == NULL ) ? 0 : 1 ;
}
const T_5 * F_43 ( const T_1 * V_44 )
{
return V_44 -> V_7 ;
}
int F_44 ( T_1 * V_44 , const T_5 * V_7 )
{
if ( V_44 -> V_7 )
F_12 ( V_44 -> V_7 ) ;
V_44 -> V_7 = F_45 ( V_7 ) ;
return ( V_44 -> V_7 == NULL ) ? 0 : 1 ;
}
const T_6 * F_46 ( const T_1 * V_44 )
{
return V_44 -> V_6 ;
}
int F_47 ( T_1 * V_44 , const T_6 * V_6 )
{
if ( V_44 -> V_6 != NULL )
F_11 ( V_44 -> V_6 ) ;
V_44 -> V_6 = F_48 ( V_6 , V_44 -> V_5 ) ;
return ( V_44 -> V_6 == NULL ) ? 0 : 1 ;
}
unsigned int F_49 ( const T_1 * V_44 )
{
return V_44 -> V_8 ;
}
void F_50 ( T_1 * V_44 , unsigned int V_45 )
{
V_44 -> V_8 = V_45 ;
}
T_8 F_51 ( const T_1 * V_44 )
{
return V_44 -> V_9 ;
}
void F_52 ( T_1 * V_44 , T_8 V_46 )
{
V_44 -> V_9 = V_46 ;
if ( V_44 -> V_5 != NULL )
F_53 ( V_44 -> V_5 , V_46 ) ;
}
void * F_54 ( T_1 * V_44 ,
void * (* V_26)( void * ) , void (* V_28)( void * ) , void (* V_29)( void * ) )
{
return F_55 ( V_44 -> V_12 , V_26 , V_28 , V_29 ) ;
}
void F_56 ( T_1 * V_44 , void * V_27 ,
void * (* V_26)( void * ) , void (* V_28)( void * ) , void (* V_29)( void * ) )
{
T_2 * V_47 ;
F_57 ( V_16 ) ;
V_47 = F_55 ( V_44 -> V_12 , V_26 , V_28 , V_29 ) ;
if ( V_47 == NULL )
F_24 ( & V_44 -> V_12 , V_27 , V_26 , V_28 , V_29 ) ;
F_58 ( V_16 ) ;
}
void F_59 ( T_1 * V_44 , int V_48 )
{
if ( V_44 -> V_5 != NULL )
F_60 ( V_44 -> V_5 , V_48 ) ;
}
int F_61 ( T_1 * V_44 , T_4 * V_33 )
{
if ( V_44 -> V_5 == NULL )
return 0 ;
return F_62 ( V_44 -> V_5 , V_33 ) ;
}
