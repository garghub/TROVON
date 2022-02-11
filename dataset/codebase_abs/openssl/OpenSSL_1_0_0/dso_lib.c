T_1 * F_1 ( void )
{
return ( F_2 ( NULL ) ) ;
}
void F_3 ( T_2 * V_1 )
{
V_2 = V_1 ;
}
T_2 * F_4 ( void )
{
return ( V_2 ) ;
}
T_2 * F_5 ( T_1 * V_3 )
{
return ( V_3 -> V_1 ) ;
}
T_2 * F_6 ( T_1 * V_3 , T_2 * V_1 )
{
T_2 * V_4 ;
V_4 = V_3 -> V_1 ;
V_3 -> V_1 = V_1 ;
return ( V_4 ) ;
}
T_1 * F_2 ( T_2 * V_1 )
{
T_1 * V_5 ;
if( V_2 == NULL )
V_2 = F_7 () ;
V_5 = ( T_1 * ) F_8 ( sizeof( T_1 ) ) ;
if( V_5 == NULL )
{
F_9 ( V_6 , V_7 ) ;
return ( NULL ) ;
}
memset ( V_5 , 0 , sizeof( T_1 ) ) ;
V_5 -> V_8 = F_10 () ;
if( V_5 -> V_8 == NULL )
{
F_9 ( V_6 , V_7 ) ;
F_11 ( V_5 ) ;
return ( NULL ) ;
}
if( V_1 == NULL )
V_5 -> V_1 = V_2 ;
else
V_5 -> V_1 = V_1 ;
V_5 -> V_9 = 1 ;
if( ( V_5 -> V_1 -> V_10 != NULL ) && ! V_5 -> V_1 -> V_10 ( V_5 ) )
{
F_11 ( V_5 ) ;
V_5 = NULL ;
}
return ( V_5 ) ;
}
int F_12 ( T_1 * V_3 )
{
int V_11 ;
if( V_3 == NULL )
{
F_9 ( V_12 , V_13 ) ;
return ( 0 ) ;
}
V_11 = F_13 ( & V_3 -> V_9 , - 1 , V_14 ) ;
#ifdef F_14
F_14 ( L_1 , V_3 ) ;
#endif
if( V_11 > 0 ) return ( 1 ) ;
#ifdef F_15
if( V_11 < 0 )
{
fprintf ( V_15 , L_2 ) ;
abort () ;
}
#endif
if( ( V_3 -> V_1 -> V_16 != NULL ) && ! V_3 -> V_1 -> V_16 ( V_3 ) )
{
F_9 ( V_12 , V_17 ) ;
return ( 0 ) ;
}
if( ( V_3 -> V_1 -> V_18 != NULL ) && ! V_3 -> V_1 -> V_18 ( V_3 ) )
{
F_9 ( V_12 , V_19 ) ;
return ( 0 ) ;
}
F_16 ( V_3 -> V_8 ) ;
if( V_3 -> V_20 != NULL )
F_11 ( V_3 -> V_20 ) ;
if( V_3 -> V_21 != NULL )
F_11 ( V_3 -> V_21 ) ;
F_11 ( V_3 ) ;
return ( 1 ) ;
}
int F_17 ( T_1 * V_3 )
{
return ( ( V_3 == NULL ) ? 0 : V_3 -> V_22 ) ;
}
int F_18 ( T_1 * V_3 )
{
if ( V_3 == NULL )
{
F_9 ( V_23 , V_13 ) ;
return ( 0 ) ;
}
F_13 ( & V_3 -> V_9 , 1 , V_14 ) ;
return ( 1 ) ;
}
T_1 * F_19 ( T_1 * V_3 , const char * V_20 , T_2 * V_1 , int V_22 )
{
T_1 * V_5 ;
int V_24 = 0 ;
if( V_3 == NULL )
{
V_5 = F_2 ( V_1 ) ;
if( V_5 == NULL )
{
F_9 ( V_25 , V_7 ) ;
goto V_26;
}
V_24 = 1 ;
if( F_20 ( V_5 , V_27 , V_22 , NULL ) < 0 )
{
F_9 ( V_25 , V_28 ) ;
goto V_26;
}
}
else
V_5 = V_3 ;
if( V_5 -> V_20 != NULL )
{
F_9 ( V_25 , V_29 ) ;
goto V_26;
}
if( V_20 != NULL )
if( ! F_21 ( V_5 , V_20 ) )
{
F_9 ( V_25 , V_30 ) ;
goto V_26;
}
V_20 = V_5 -> V_20 ;
if( V_20 == NULL )
{
F_9 ( V_25 , V_31 ) ;
goto V_26;
}
if( V_5 -> V_1 -> V_32 == NULL )
{
F_9 ( V_25 , V_33 ) ;
goto V_26;
}
if( ! V_5 -> V_1 -> V_32 ( V_5 ) )
{
F_9 ( V_25 , V_34 ) ;
goto V_26;
}
return ( V_5 ) ;
V_26:
if( V_24 )
F_12 ( V_5 ) ;
return ( NULL ) ;
}
void * F_22 ( T_1 * V_3 , const char * V_35 )
{
void * V_5 = NULL ;
if( ( V_3 == NULL ) || ( V_35 == NULL ) )
{
F_9 ( V_36 , V_13 ) ;
return ( NULL ) ;
}
if( V_3 -> V_1 -> V_37 == NULL )
{
F_9 ( V_36 , V_33 ) ;
return ( NULL ) ;
}
if( ( V_5 = V_3 -> V_1 -> V_37 ( V_3 , V_35 ) ) == NULL )
{
F_9 ( V_36 , V_38 ) ;
return ( NULL ) ;
}
return ( V_5 ) ;
}
T_3 F_23 ( T_1 * V_3 , const char * V_35 )
{
T_3 V_5 = NULL ;
if( ( V_3 == NULL ) || ( V_35 == NULL ) )
{
F_9 ( V_39 , V_13 ) ;
return ( NULL ) ;
}
if( V_3 -> V_1 -> V_40 == NULL )
{
F_9 ( V_39 , V_33 ) ;
return ( NULL ) ;
}
if( ( V_5 = V_3 -> V_1 -> V_40 ( V_3 , V_35 ) ) == NULL )
{
F_9 ( V_39 , V_38 ) ;
return ( NULL ) ;
}
return ( V_5 ) ;
}
long F_20 ( T_1 * V_3 , int V_41 , long V_42 , void * V_43 )
{
if( V_3 == NULL )
{
F_9 ( V_44 , V_13 ) ;
return ( - 1 ) ;
}
switch( V_41 )
{
case V_45 :
return V_3 -> V_22 ;
case V_27 :
V_3 -> V_22 = ( int ) V_42 ;
return ( 0 ) ;
case V_46 :
V_3 -> V_22 |= ( int ) V_42 ;
return ( 0 ) ;
default:
break;
}
if( ( V_3 -> V_1 == NULL ) || ( V_3 -> V_1 -> V_47 == NULL ) )
{
F_9 ( V_44 , V_33 ) ;
return ( - 1 ) ;
}
return ( V_3 -> V_1 -> V_47 ( V_3 , V_41 , V_42 , V_43 ) ) ;
}
int F_24 ( T_1 * V_3 , T_4 V_48 ,
T_4 * V_49 )
{
if( V_3 == NULL )
{
F_9 ( V_50 ,
V_13 ) ;
return ( 0 ) ;
}
if( V_49 )
* V_49 = V_3 -> V_51 ;
V_3 -> V_51 = V_48 ;
return ( 1 ) ;
}
const char * F_25 ( T_1 * V_3 )
{
if( V_3 == NULL )
{
F_9 ( V_52 , V_13 ) ;
return ( NULL ) ;
}
return ( V_3 -> V_20 ) ;
}
int F_21 ( T_1 * V_3 , const char * V_20 )
{
char * V_53 ;
if( ( V_3 == NULL ) || ( V_20 == NULL ) )
{
F_9 ( V_54 , V_13 ) ;
return ( 0 ) ;
}
if( V_3 -> V_21 )
{
F_9 ( V_54 , V_29 ) ;
return ( 0 ) ;
}
V_53 = F_8 ( strlen ( V_20 ) + 1 ) ;
if( V_53 == NULL )
{
F_9 ( V_54 , V_7 ) ;
return ( 0 ) ;
}
F_26 ( V_53 , V_20 , strlen ( V_20 ) + 1 ) ;
if( V_3 -> V_20 )
F_11 ( V_3 -> V_20 ) ;
V_3 -> V_20 = V_53 ;
return ( 1 ) ;
}
char * F_27 ( T_1 * V_3 , const char * V_55 , const char * V_56 )
{
char * V_57 = NULL ;
if( V_3 == NULL || V_55 == NULL )
{
F_9 ( V_58 , V_13 ) ;
return ( NULL ) ;
}
if( ( V_3 -> V_22 & V_59 ) == 0 )
{
if( V_3 -> V_60 != NULL )
V_57 = V_3 -> V_60 ( V_3 , V_55 , V_56 ) ;
else if( V_3 -> V_1 -> V_61 != NULL )
V_57 = V_3 -> V_1 -> V_61 ( V_3 ,
V_55 , V_56 ) ;
}
return ( V_57 ) ;
}
char * F_28 ( T_1 * V_3 , const char * V_20 )
{
char * V_57 = NULL ;
if( V_3 == NULL )
{
F_9 ( V_62 , V_13 ) ;
return ( NULL ) ;
}
if( V_20 == NULL )
V_20 = V_3 -> V_20 ;
if( V_20 == NULL )
{
F_9 ( V_62 , V_31 ) ;
return ( NULL ) ;
}
if( ( V_3 -> V_22 & V_59 ) == 0 )
{
if( V_3 -> V_51 != NULL )
V_57 = V_3 -> V_51 ( V_3 , V_20 ) ;
else if( V_3 -> V_1 -> V_63 != NULL )
V_57 = V_3 -> V_1 -> V_63 ( V_3 , V_20 ) ;
}
if( V_57 == NULL )
{
V_57 = F_8 ( strlen ( V_20 ) + 1 ) ;
if( V_57 == NULL )
{
F_9 ( V_62 ,
V_7 ) ;
return ( NULL ) ;
}
F_26 ( V_57 , V_20 , strlen ( V_20 ) + 1 ) ;
}
return ( V_57 ) ;
}
const char * F_29 ( T_1 * V_3 )
{
if( V_3 == NULL )
{
F_9 ( V_64 ,
V_13 ) ;
return ( NULL ) ;
}
return ( V_3 -> V_21 ) ;
}
int F_30 ( void * V_65 , char * V_66 , int V_67 )
{
T_2 * V_1 = V_2 ;
if ( V_1 == NULL ) V_1 = F_7 () ;
if ( V_1 -> V_68 == NULL )
{
F_9 ( V_69 , V_33 ) ;
return - 1 ;
}
return (* V_1 -> V_68 )( V_65 , V_66 , V_67 ) ;
}
void * F_31 ( const char * V_70 )
{
T_2 * V_1 = V_2 ;
if ( V_1 == NULL ) V_1 = F_7 () ;
if ( V_1 -> V_71 == NULL )
{
F_9 ( V_72 , V_33 ) ;
return NULL ;
}
return (* V_1 -> V_71 )( V_70 ) ;
}
