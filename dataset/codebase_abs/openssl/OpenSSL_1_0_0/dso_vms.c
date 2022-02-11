T_1 * F_1 ( void )
{
return NULL ;
}
T_1 * F_1 ( void )
{
return ( & V_1 ) ;
}
static int F_2 ( T_2 * V_2 )
{
void * V_3 = NULL ;
char * V_4 = F_3 ( V_2 , NULL ) ;
T_3 * V_5 ;
const char * V_6 , * V_7 ;
if( V_4 == NULL )
{
F_4 ( V_8 , V_9 ) ;
goto V_10;
}
V_6 = strrchr ( V_4 , ']' ) ;
V_7 = strrchr ( V_4 , '>' ) ;
if ( V_6 == NULL ) V_6 = V_7 ;
if ( V_7 != NULL && V_7 > V_6 ) V_6 = V_7 ;
if ( V_6 == NULL ) V_6 = strrchr ( V_4 , ':' ) ;
if ( V_6 == NULL )
V_6 = V_4 ;
else
V_6 ++ ;
V_7 = strchr ( V_6 , '.' ) ;
if ( V_7 == NULL ) V_7 = strchr ( V_6 , ';' ) ;
if ( V_7 == NULL ) V_7 = V_6 + strlen ( V_6 ) ;
if ( V_7 - V_6 > V_11
|| ( V_6 - V_4 ) + strlen ( V_7 ) > V_11 )
{
F_4 ( V_8 , V_12 ) ;
goto V_10;
}
V_5 = ( T_3 * ) F_5 ( sizeof( T_3 ) ) ;
if( V_5 == NULL )
{
F_4 ( V_8 , V_13 ) ;
goto V_10;
}
strncpy ( V_5 -> V_4 , V_6 , V_7 - V_6 ) ;
V_5 -> V_4 [ V_7 - V_6 ] = '\0' ;
strncpy ( V_5 -> V_14 , V_4 , V_6 - V_4 ) ;
V_5 -> V_14 [ V_6 - V_4 ] = '\0' ;
strcat ( V_5 -> V_14 , V_7 ) ;
V_5 -> V_15 . V_16 = strlen ( V_5 -> V_4 ) ;
V_5 -> V_15 . V_17 = V_18 ;
V_5 -> V_15 . V_19 = V_20 ;
V_5 -> V_15 . V_21 = V_5 -> V_4 ;
V_5 -> V_22 . V_16 = strlen ( V_5 -> V_14 ) ;
V_5 -> V_22 . V_17 = V_18 ;
V_5 -> V_22 . V_19 = V_20 ;
V_5 -> V_22 . V_21 = V_5 -> V_14 ;
if( ! F_6 ( V_2 -> V_23 , ( char * ) V_5 ) )
{
F_4 ( V_8 , V_24 ) ;
goto V_10;
}
V_2 -> V_25 = V_4 ;
return ( 1 ) ;
V_10:
if( V_5 != NULL )
F_7 ( V_5 ) ;
if( V_4 != NULL )
F_7 ( V_4 ) ;
return ( 0 ) ;
}
static int F_8 ( T_2 * V_2 )
{
T_3 * V_5 ;
if( V_2 == NULL )
{
F_4 ( V_26 , V_27 ) ;
return ( 0 ) ;
}
if( F_9 ( V_2 -> V_23 ) < 1 )
return ( 1 ) ;
V_5 = ( T_3 * ) F_10 ( V_2 -> V_23 ) ;
if( V_5 == NULL )
{
F_4 ( V_26 , V_28 ) ;
return ( 0 ) ;
}
F_7 ( V_5 ) ;
return ( 1 ) ;
}
static int F_11 ( T_3 * V_3 ,
struct V_29 * V_30 , void * * V_31 ,
unsigned long V_32 )
{
F_12 ( V_33 ) ;
if( V_3 -> V_22 . V_16 )
return F_13 ( & V_3 -> V_15 ,
V_30 , V_31 ,
& V_3 -> V_22 , V_32 ) ;
else
return F_13 ( & V_3 -> V_15 ,
V_30 , V_31 ,
0 , V_32 ) ;
}
void F_14 ( T_2 * V_2 , const char * V_34 , void * * V_31 )
{
T_3 * V_3 ;
int V_35 ;
#if 0
int flags = (1<<4);
#else
int V_32 = 0 ;
#endif
struct V_29 V_30 ;
* V_31 = NULL ;
V_30 . V_16 = strlen ( V_34 ) ;
V_30 . V_17 = V_18 ;
V_30 . V_19 = V_20 ;
V_30 . V_21 = ( char * ) V_34 ;
if( ( V_2 == NULL ) || ( V_34 == NULL ) )
{
F_4 ( V_36 , V_27 ) ;
return;
}
if( F_9 ( V_2 -> V_23 ) < 1 )
{
F_4 ( V_36 , V_24 ) ;
return;
}
V_3 = ( T_3 * ) F_15 ( V_2 -> V_23 ,
F_9 ( V_2 -> V_23 ) - 1 ) ;
if( V_3 == NULL )
{
F_4 ( V_36 , V_28 ) ;
return;
}
if( V_2 -> V_32 & V_37 ) V_32 = 0 ;
V_35 = F_11 ( V_3 , & V_30 , V_31 , V_32 ) ;
if( ! F_16 ( V_35 ) )
{
unsigned short V_38 ;
char V_39 [ 257 ] ;
struct V_29 V_40 ;
V_40 . V_16 = sizeof( V_39 ) ;
V_40 . V_17 = V_18 ;
V_40 . V_19 = V_20 ;
V_40 . V_21 = V_39 ;
* V_31 = NULL ;
V_35 = F_17 ( V_35 , & V_38 , & V_40 , 1 , 0 ) ;
if ( ! F_16 ( V_35 ) )
F_18 ( V_35 ) ;
else
{
V_39 [ V_38 ] = '\0' ;
F_4 ( V_36 , V_41 ) ;
if ( V_3 -> V_22 . V_16 )
F_19 ( 9 ,
L_1 , V_34 ,
L_2 , V_3 -> V_4 ,
L_3 , V_3 -> V_14 , L_4 ,
L_5 , V_39 ) ;
else
F_19 ( 6 ,
L_1 , V_34 ,
L_2 , V_3 -> V_4 ,
L_5 , V_39 ) ;
}
return;
}
return;
}
static void * F_20 ( T_2 * V_2 , const char * V_34 )
{
void * V_31 = 0 ;
F_14 ( V_2 , V_34 , & V_31 ) ;
return V_31 ;
}
static T_4 F_21 ( T_2 * V_2 , const char * V_34 )
{
T_4 V_31 = 0 ;
F_14 ( V_2 , V_34 , ( void * * ) & V_31 ) ;
return V_31 ;
}
static char * F_22 ( T_2 * V_2 , const char * V_42 , const char * V_43 )
{
int V_35 ;
int V_44 , V_45 ;
struct V_46 V_47 ;
#ifdef F_23
struct V_48 V_49 ;
char V_50 [ F_23 ] ;
#else
struct V_51 V_49 ;
char V_50 [ V_52 ] ;
#endif
char * V_53 ;
if ( ! V_42 ) V_42 = L_6 ;
if ( ! V_43 ) V_43 = L_6 ;
V_44 = strlen ( V_42 ) ;
V_45 = strlen ( V_43 ) ;
V_47 = V_54 ;
#ifdef F_23
V_49 = V_55 ;
#else
V_49 = V_56 ;
#endif
V_47 . V_57 = ( char * ) V_42 ;
V_47 . V_58 = V_44 ;
V_47 . V_59 = ( char * ) V_43 ;
V_47 . V_60 = V_45 ;
#ifdef F_23
if ( V_44 > V_52 )
{
V_47 . V_57 = 0 ;
V_47 . V_58 = 0 ;
V_49 . V_61 = ( char * ) V_42 ;
V_49 . V_62 = V_44 ;
}
if ( V_45 > V_52 )
{
V_47 . V_59 = 0 ;
V_47 . V_60 = 0 ;
V_49 . V_63 = ( char * ) V_43 ;
V_49 . V_64 = V_45 ;
}
V_49 . V_65 = V_50 ;
V_49 . V_66 = V_52 ;
V_49 . V_67 = V_50 ;
V_49 . V_68 = sizeof( V_50 ) ;
V_49 . V_69 = V_70 | V_71 ;
V_49 . V_72 = 1 ;
V_47 . V_73 = & V_49 ;
#else
V_49 . V_74 = V_50 ;
V_49 . V_75 = V_52 ;
V_49 . V_76 = V_70 | V_71 ;
V_47 . V_77 = & V_49 ;
#endif
V_35 = F_24 ( & V_47 , 0 , 0 ) ;
if( ! F_16 ( V_35 ) )
{
unsigned short V_38 ;
char V_39 [ 257 ] ;
struct V_29 V_40 ;
V_40 . V_16 = sizeof( V_39 ) ;
V_40 . V_17 = V_18 ;
V_40 . V_19 = V_20 ;
V_40 . V_21 = V_39 ;
V_35 = F_17 ( V_35 , & V_38 , & V_40 , 1 , 0 ) ;
if ( ! F_16 ( V_35 ) )
F_18 ( V_35 ) ;
else
{
V_39 [ V_38 ] = '\0' ;
F_4 ( V_78 , V_79 ) ;
F_19 ( 7 ,
L_7 , V_42 , L_8 ,
L_9 , V_43 , L_10 ,
V_39 ) ;
}
return ( NULL ) ;
}
#ifdef F_23
if ( V_49 . V_80 )
{
V_53 = F_5 ( V_49 . V_80 + 1 ) ;
if( ! V_53 )
goto V_81;
strncpy ( V_53 , V_49 . V_67 ,
V_49 . V_80 ) ;
V_53 [ V_49 . V_80 ] = '\0' ;
}
else
{
V_53 = F_5 ( V_49 . V_82 + 1 ) ;
if( ! V_53 )
goto V_81;
strncpy ( V_53 , V_49 . V_65 ,
V_49 . V_82 ) ;
V_53 [ V_49 . V_82 ] = '\0' ;
}
#else
V_53 = F_5 ( V_49 . V_83 + 1 ) ;
if( ! V_53 )
goto V_81;
strncpy ( V_53 , V_49 . V_74 ,
V_49 . V_83 ) ;
V_53 [ V_49 . V_83 ] = '\0' ;
#endif
return ( V_53 ) ;
V_81:
F_4 ( V_78 ,
V_13 ) ;
}
static char * F_25 ( T_2 * V_2 , const char * V_4 )
{
int V_84 = strlen ( V_4 ) ;
char * V_85 = F_5 ( V_84 + 1 ) ;
strcpy ( V_85 , V_4 ) ;
return ( V_85 ) ;
}
