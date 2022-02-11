T_1 * F_1 ( void )
{
return ( & V_1 ) ;
}
static int F_2 ( T_2 * V_2 )
{
T_3 * V_3 ;
V_3 = ( T_3 * ) Malloc ( sizeof( T_3 ) ) ;
if ( V_3 == NULL )
{
F_3 ( V_4 , V_5 ) ;
return ( 0 ) ;
}
memset ( V_3 , 0 , sizeof( T_3 ) ) ;
V_2 -> V_6 = 0 ;
V_2 -> V_7 = ( char * ) V_3 ;
V_2 -> V_8 = 0 ;
return ( 1 ) ;
}
static int F_4 ( T_2 * V_9 )
{
T_3 * V_3 ;
if ( V_9 == NULL ) return ( 0 ) ;
V_3 = ( T_3 * ) V_9 -> V_7 ;
if ( V_3 -> V_10 != NULL ) F_5 ( V_3 -> V_10 ) ;
if ( V_9 -> V_11 )
{
if ( V_9 -> V_6 && ( V_3 -> V_10 != NULL ) )
F_6 ( V_3 -> V_10 ) ;
V_9 -> V_6 = 0 ;
V_9 -> V_8 = 0 ;
}
if ( V_9 -> V_7 != NULL )
Free ( V_9 -> V_7 ) ;
return ( 1 ) ;
}
static int F_7 ( T_2 * V_12 , char * V_13 , int V_14 )
{
int V_15 = 1 ;
T_3 * V_16 ;
T_4 * V_10 ;
int V_17 = 0 ;
int V_18 = 0 ;
if ( V_13 == NULL ) return ( 0 ) ;
V_16 = ( T_3 * ) V_12 -> V_7 ;
V_10 = V_16 -> V_10 ;
F_8 ( V_12 ) ;
#if 0
if (!SSL_is_init_finished(ssl))
{
if (ret > 0)
{
outflags=(BIO_FLAGS_READ|BIO_FLAGS_SHOULD_RETRY);
ret= -1;
goto end;
}
}
#endif
V_15 = F_9 ( V_10 , V_13 , V_14 ) ;
switch ( F_10 ( V_10 , V_15 ) )
{
case V_19 :
if ( V_15 <= 0 ) break;
if ( V_16 -> V_20 > 0 )
{
V_16 -> V_21 += V_15 ;
if ( V_16 -> V_21 > V_16 -> V_20 )
{
V_16 -> V_21 = 0 ;
V_16 -> V_22 ++ ;
F_11 ( V_10 ) ;
V_18 = 1 ;
}
}
if ( ( V_16 -> V_23 > 0 ) && ( ! V_18 ) )
{
unsigned long V_24 ;
V_24 = ( unsigned long ) time ( NULL ) ;
if ( V_24 > V_16 -> V_25 + V_16 -> V_23 )
{
V_16 -> V_25 = V_24 ;
V_16 -> V_22 ++ ;
F_11 ( V_10 ) ;
}
}
break;
case V_26 :
F_12 ( V_12 ) ;
break;
case V_27 :
F_13 ( V_12 ) ;
break;
case V_28 :
F_14 ( V_12 ) ;
V_17 = V_29 ;
break;
case V_30 :
F_14 ( V_12 ) ;
V_17 = V_31 ;
break;
case V_32 :
case V_33 :
case V_34 :
default:
break;
}
V_12 -> V_17 = V_17 ;
return ( V_15 ) ;
}
static int F_15 ( T_2 * V_12 , char * V_13 , int V_14 )
{
int V_15 , V_18 = 0 ;
int V_17 = 0 ;
T_4 * V_10 ;
T_3 * V_3 ;
if ( V_13 == NULL ) return ( 0 ) ;
V_3 = ( T_3 * ) V_12 -> V_7 ;
V_10 = V_3 -> V_10 ;
F_8 ( V_12 ) ;
V_15 = F_16 ( V_10 , V_13 , V_14 ) ;
switch ( F_10 ( V_10 , V_15 ) )
{
case V_19 :
if ( V_15 <= 0 ) break;
if ( V_3 -> V_20 > 0 )
{
V_3 -> V_21 += V_15 ;
if ( V_3 -> V_21 > V_3 -> V_20 )
{
V_3 -> V_21 = 0 ;
V_3 -> V_22 ++ ;
F_11 ( V_10 ) ;
V_18 = 1 ;
}
}
if ( ( V_3 -> V_23 > 0 ) && ( ! V_18 ) )
{
unsigned long V_24 ;
V_24 = ( unsigned long ) time ( NULL ) ;
if ( V_24 > V_3 -> V_25 + V_3 -> V_23 )
{
V_3 -> V_25 = V_24 ;
V_3 -> V_22 ++ ;
F_11 ( V_10 ) ;
}
}
break;
case V_27 :
F_13 ( V_12 ) ;
break;
case V_26 :
F_12 ( V_12 ) ;
break;
case V_28 :
F_14 ( V_12 ) ;
V_17 = V_29 ;
break;
case V_30 :
F_14 ( V_12 ) ;
V_17 = V_31 ;
case V_32 :
case V_33 :
default:
break;
}
V_12 -> V_17 = V_17 ;
return ( V_15 ) ;
}
static long F_17 ( T_2 * V_12 , int V_35 , long V_36 , char * V_7 )
{
T_4 * * V_37 , * V_10 ;
T_3 * V_3 ;
T_2 * V_38 , * V_39 ;
long V_15 = 1 ;
V_3 = ( T_3 * ) V_12 -> V_7 ;
V_10 = V_3 -> V_10 ;
if ( ( V_10 == NULL ) && ( V_35 != V_40 ) )
return ( 0 ) ;
switch ( V_35 )
{
case V_41 :
F_5 ( V_10 ) ;
if ( V_10 -> V_42 == V_10 -> V_43 -> V_44 )
F_18 ( V_10 ) ;
else if ( V_10 -> V_42 == V_10 -> V_43 -> V_45 )
F_19 ( V_10 ) ;
F_20 ( V_10 ) ;
if ( V_12 -> V_46 != NULL )
V_15 = F_21 ( V_12 -> V_46 , V_35 , V_36 , V_7 ) ;
else if ( V_10 -> V_47 != NULL )
V_15 = F_21 ( V_10 -> V_47 , V_35 , V_36 , V_7 ) ;
else
V_15 = 1 ;
break;
case V_48 :
V_15 = 0 ;
break;
case V_49 :
if ( V_36 )
F_18 ( V_10 ) ;
else
F_19 ( V_10 ) ;
break;
case V_50 :
V_15 = V_3 -> V_23 ;
if ( V_36 < 60 ) V_36 = 5 ;
V_3 -> V_23 = ( unsigned long ) V_36 ;
V_3 -> V_25 = ( unsigned long ) time ( NULL ) ;
break;
case V_51 :
V_15 = V_3 -> V_20 ;
if ( ( long ) V_36 >= 512 )
V_3 -> V_20 = ( unsigned long ) V_36 ;
break;
case V_52 :
V_15 = V_3 -> V_22 ;
break;
case V_40 :
if ( V_10 != NULL )
F_4 ( V_12 ) ;
V_12 -> V_11 = ( int ) V_36 ;
V_10 = ( T_4 * ) V_7 ;
( ( T_3 * ) V_12 -> V_7 ) -> V_10 = V_10 ;
V_39 = F_22 ( V_10 ) ;
if ( V_39 != NULL )
{
if ( V_12 -> V_46 != NULL )
F_23 ( V_39 , V_12 -> V_46 ) ;
V_12 -> V_46 = V_39 ;
F_24 ( & V_39 -> V_53 , 1 , V_54 ) ;
}
V_12 -> V_6 = 1 ;
break;
case V_55 :
if ( V_7 != NULL )
{
V_37 = ( T_4 * * ) V_7 ;
* V_37 = V_10 ;
}
else
V_15 = 0 ;
break;
case V_56 :
V_15 = V_12 -> V_11 ;
break;
case V_57 :
V_12 -> V_11 = ( int ) V_36 ;
break;
case V_58 :
V_15 = F_21 ( V_10 -> V_59 , V_35 , V_36 , V_7 ) ;
break;
case V_60 :
V_15 = F_25 ( V_10 ) ;
if ( V_15 == 0 )
V_15 = F_26 ( V_10 -> V_47 ) ;
break;
case V_61 :
F_8 ( V_12 ) ;
V_15 = F_21 ( V_10 -> V_59 , V_35 , V_36 , V_7 ) ;
F_27 ( V_12 ) ;
break;
case V_62 :
if ( ( V_12 -> V_46 != NULL ) && ( V_12 -> V_46 != V_10 -> V_47 ) )
{
F_28 ( V_10 , V_12 -> V_46 , V_12 -> V_46 ) ;
F_24 ( & V_12 -> V_46 -> V_53 , 1 , V_54 ) ;
}
break;
case V_63 :
if ( V_10 -> V_47 != V_10 -> V_59 )
{
F_29 ( V_10 -> V_59 ) ;
}
V_10 -> V_59 = NULL ;
V_10 -> V_47 = NULL ;
break;
case V_64 :
F_8 ( V_12 ) ;
V_12 -> V_17 = 0 ;
V_15 = ( int ) F_30 ( V_10 ) ;
switch ( F_10 ( V_10 , ( int ) V_15 ) )
{
case V_26 :
F_31 ( V_12 ,
V_65 | V_66 ) ;
break;
case V_27 :
F_31 ( V_12 ,
V_67 | V_66 ) ;
break;
case V_30 :
F_31 ( V_12 ,
V_68 | V_66 ) ;
V_12 -> V_17 = V_12 -> V_46 -> V_17 ;
break;
default:
break;
}
break;
case V_69 :
V_38 = ( T_2 * ) V_7 ;
if ( ( ( T_3 * ) V_38 -> V_7 ) -> V_10 != NULL )
F_6 ( ( ( T_3 * ) V_38 -> V_7 ) -> V_10 ) ;
( ( T_3 * ) V_38 -> V_7 ) -> V_10 = F_32 ( V_10 ) ;
( ( T_3 * ) V_38 -> V_7 ) -> V_20 =
( ( T_3 * ) V_12 -> V_7 ) -> V_20 ;
( ( T_3 * ) V_38 -> V_7 ) -> V_21 =
( ( T_3 * ) V_12 -> V_7 ) -> V_21 ;
( ( T_3 * ) V_38 -> V_7 ) -> V_23 =
( ( T_3 * ) V_12 -> V_7 ) -> V_23 ;
( ( T_3 * ) V_38 -> V_7 ) -> V_25 =
( ( T_3 * ) V_12 -> V_7 ) -> V_25 ;
V_15 = ( ( ( T_3 * ) V_38 -> V_7 ) -> V_10 != NULL ) ;
break;
case V_70 :
V_15 = F_21 ( V_10 -> V_47 , V_35 , V_36 , V_7 ) ;
break;
case V_71 :
{
#if 0
BIOerr(SSL_F_SSL_CTRL, ERR_R_SHOULD_NOT_HAVE_BEEN_CALLED);
ret = -1;
#else
V_15 = 0 ;
#endif
}
break;
case V_72 :
{
void (* * F_33)();
F_33 = ( void ( * * ) () ) V_7 ;
* F_33 = F_34 ( V_10 ) ;
}
break;
default:
V_15 = F_21 ( V_10 -> V_47 , V_35 , V_36 , V_7 ) ;
break;
}
return ( V_15 ) ;
}
static long F_35 ( T_2 * V_12 , int V_35 , void (* F_36)() )
{
T_4 * V_10 ;
T_3 * V_3 ;
long V_15 = 1 ;
V_3 = ( T_3 * ) V_12 -> V_7 ;
V_10 = V_3 -> V_10 ;
switch ( V_35 )
{
case V_71 :
{
F_37 ( V_10 , F_36 ) ;
}
break;
default:
V_15 = F_38 ( V_10 -> V_47 , V_35 , F_36 ) ;
break;
}
return ( V_15 ) ;
}
static int F_39 ( T_2 * V_73 , char * V_74 )
{
int V_75 , V_15 ;
V_75 = strlen ( V_74 ) ;
V_15 = F_40 ( V_73 , V_74 , V_75 ) ;
return ( V_15 ) ;
}
T_2 * F_41 ( T_5 * V_76 )
{
T_2 * V_15 = NULL , * V_77 = NULL , * V_10 = NULL ;
if ( ( V_77 = F_42 ( F_43 () ) ) == NULL )
return ( NULL ) ;
if ( ( V_10 = F_44 ( V_76 ) ) == NULL )
goto V_78;
if ( ( V_15 = F_23 ( V_77 , V_10 ) ) == NULL )
goto V_78;
return ( V_15 ) ;
V_78:
if ( V_77 != NULL ) F_45 ( V_77 ) ;
if ( V_10 != NULL ) F_45 ( V_10 ) ;
return ( NULL ) ;
}
T_2 * F_44 ( T_5 * V_76 )
{
T_2 * V_15 = NULL , * V_79 = NULL , * V_10 = NULL ;
if ( ( V_79 = F_42 ( F_46 () ) ) == NULL )
return ( NULL ) ;
if ( ( V_10 = F_47 ( V_76 , 1 ) ) == NULL )
goto V_78;
if ( ( V_15 = F_23 ( V_10 , V_79 ) ) == NULL )
goto V_78;
return ( V_15 ) ;
V_78:
if ( V_79 != NULL ) F_45 ( V_79 ) ;
if ( V_15 != NULL ) F_45 ( V_15 ) ;
return ( NULL ) ;
}
T_2 * F_47 ( T_5 * V_76 , int V_80 )
{
T_2 * V_15 ;
T_4 * V_10 ;
if ( ( V_15 = F_42 ( F_1 () ) ) == NULL )
return ( NULL ) ;
if ( ( V_10 = F_48 ( V_76 ) ) == NULL )
{
F_45 ( V_15 ) ;
return ( NULL ) ;
}
if ( V_80 )
F_18 ( V_10 ) ;
else
F_19 ( V_10 ) ;
F_49 ( V_15 , V_10 , V_81 ) ;
return ( V_15 ) ;
}
int F_50 ( T_2 * V_82 , T_2 * V_83 )
{
V_82 = F_51 ( V_82 , V_84 ) ;
V_83 = F_51 ( V_83 , V_84 ) ;
if ( ( V_82 == NULL ) || ( V_83 == NULL ) )
return ( 0 ) ;
if ( ( ( ( T_3 * ) V_82 -> V_7 ) -> V_10 == NULL ) ||
( ( ( T_3 * ) V_83 -> V_7 ) -> V_10 == NULL ) )
return ( 0 ) ;
F_52 ( ( ( T_3 * ) V_82 -> V_7 ) -> V_10 , ( ( T_3 * ) V_83 -> V_7 ) -> V_10 ) ;
return ( 1 ) ;
}
void F_53 ( T_2 * V_12 )
{
T_4 * V_85 ;
while ( V_12 != NULL )
{
if ( V_12 -> V_43 -> type == V_84 )
{
V_85 = ( ( T_3 * ) V_12 -> V_7 ) -> V_10 ;
F_5 ( V_85 ) ;
break;
}
V_12 = V_12 -> V_46 ;
}
}
