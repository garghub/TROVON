T_1 * F_1 ( void )
{
return ( & V_1 ) ;
}
T_2 * F_2 ( int V_2 , int V_3 )
{
T_2 * V_4 ;
V_4 = F_3 ( F_1 () ) ;
if ( V_4 == NULL ) return ( NULL ) ;
F_4 ( V_4 , V_2 , V_3 ) ;
return ( V_4 ) ;
}
static int F_5 ( T_2 * V_5 )
{
T_3 * V_6 = NULL ;
V_5 -> V_7 = 0 ;
V_5 -> V_8 = 0 ;
V_6 = F_6 ( sizeof( T_3 ) ) ;
if ( V_6 == NULL )
return 0 ;
memset ( V_6 , 0x00 , sizeof( T_3 ) ) ;
V_5 -> V_9 = V_6 ;
V_5 -> V_10 = 0 ;
return ( 1 ) ;
}
static int F_7 ( T_2 * V_11 )
{
T_3 * V_6 ;
if ( V_11 == NULL ) return ( 0 ) ;
if ( ! F_8 ( V_11 ) )
return 0 ;
V_6 = ( T_3 * ) V_11 -> V_9 ;
if( V_6 != NULL ) F_9 ( V_6 ) ;
return ( 1 ) ;
}
static int F_8 ( T_2 * V_11 )
{
if ( V_11 == NULL ) return ( 0 ) ;
if ( V_11 -> V_12 )
{
if ( V_11 -> V_7 )
{
F_10 ( V_11 -> V_8 ) ;
}
V_11 -> V_7 = 0 ;
V_11 -> V_10 = 0 ;
}
return ( 1 ) ;
}
static int F_11 ( T_2 * V_13 , char * V_14 , int V_15 )
{
int V_4 = 0 ;
T_3 * V_6 = ( T_3 * ) V_13 -> V_9 ;
struct V_16 V_17 ;
int V_18 = sizeof( V_17 ) ;
if ( V_14 != NULL )
{
F_12 () ;
memset ( & V_17 , 0x00 , V_18 ) ;
V_4 = F_13 ( V_13 -> V_8 , V_14 , V_15 , 0 , & V_17 , ( void * ) & V_18 ) ;
if ( ! V_6 -> V_19 && V_4 > 0 )
F_14 ( V_13 , V_20 , 0 , & V_17 ) ;
F_15 ( V_13 ) ;
if ( V_4 <= 0 )
{
if ( F_16 ( V_4 ) )
{
F_17 ( V_13 ) ;
V_6 -> V_21 = F_18 () ;
}
}
}
return ( V_4 ) ;
}
static int F_19 ( T_2 * V_13 , const char * V_22 , int V_23 )
{
int V_4 ;
T_3 * V_6 = ( T_3 * ) V_13 -> V_9 ;
F_12 () ;
if ( V_6 -> V_19 )
V_4 = F_20 ( V_13 -> V_8 , V_22 , V_23 , 0 ) ;
else
V_4 = F_21 ( V_13 -> V_8 , V_22 , V_23 , 0 , & V_6 -> V_17 , sizeof( V_6 -> V_17 ) ) ;
F_15 ( V_13 ) ;
if ( V_4 <= 0 )
{
if ( F_22 ( V_4 ) )
{
F_23 ( V_13 ) ;
V_6 -> V_21 = F_18 () ;
#if 0
if ( data->_errno == EMSGSIZE)
BIO_ctrl(b, BIO_CTRL_DGRAM_QUERY_MTU, 0, NULL);
#endif
}
}
return ( V_4 ) ;
}
static long F_24 ( T_2 * V_13 , int V_24 , long V_8 , void * V_9 )
{
long V_4 = 1 ;
int * V_25 ;
struct V_16 * V_26 = NULL ;
T_3 * V_6 = NULL ;
long V_27 = 0 ;
unsigned int V_28 = 0 ;
V_6 = ( T_3 * ) V_13 -> V_9 ;
switch ( V_24 )
{
case V_29 :
V_8 = 0 ;
case V_30 :
V_4 = 0 ;
break;
case V_31 :
case V_32 :
V_4 = 0 ;
break;
case V_33 :
F_8 ( V_13 ) ;
V_13 -> V_8 = * ( ( int * ) V_9 ) ;
V_13 -> V_12 = ( int ) V_8 ;
V_13 -> V_7 = 1 ;
break;
case V_34 :
if ( V_13 -> V_7 )
{
V_25 = ( int * ) V_9 ;
if ( V_25 != NULL ) * V_25 = V_13 -> V_8 ;
V_4 = V_13 -> V_8 ;
}
else
V_4 = - 1 ;
break;
case V_35 :
V_4 = V_13 -> V_12 ;
break;
case V_36 :
V_13 -> V_12 = ( int ) V_8 ;
break;
case V_37 :
case V_38 :
V_4 = 0 ;
break;
case V_39 :
case V_40 :
V_4 = 1 ;
break;
case V_20 :
V_26 = (struct V_16 * ) V_9 ;
#if 0
if (connect(b->num, to, sizeof(struct sockaddr)) < 0)
{ perror("connect"); ret = 0; }
else
{
#endif
memcpy ( & ( V_6 -> V_17 ) , V_26 , sizeof( struct V_16 ) ) ;
#if 0
}
#endif
break;
#ifdef F_25
case V_41 :
V_27 = V_42 ;
if ( ( V_4 = F_26 ( V_13 -> V_8 , V_43 , F_25 ,
& V_27 , sizeof( V_27 ) ) ) < 0 )
perror ( L_1 ) ;
break;
#endif
case V_44 :
V_28 = sizeof( V_27 ) ;
if ( ( V_4 = F_27 ( V_13 -> V_8 , V_43 , V_45 , ( void * ) & V_27 ,
& V_28 ) ) < 0 || V_27 < 0 )
{ V_4 = 0 ; }
else
{
V_6 -> V_46 = V_27 ;
V_4 = V_6 -> V_46 ;
}
break;
case V_47 :
return V_6 -> V_46 ;
break;
case V_48 :
V_6 -> V_46 = V_8 ;
V_4 = V_8 ;
break;
case V_49 :
V_26 = (struct V_16 * ) V_9 ;
if ( V_26 != NULL )
{
V_6 -> V_19 = 1 ;
memcpy ( & ( V_6 -> V_17 ) , V_26 , sizeof( struct V_16 ) ) ;
}
else
{
V_6 -> V_19 = 0 ;
memset ( & ( V_6 -> V_17 ) , 0x00 , sizeof( struct V_16 ) ) ;
}
break;
case V_50 :
V_26 = (struct V_16 * ) V_9 ;
memcpy ( & ( V_6 -> V_17 ) , V_26 , sizeof( struct V_16 ) ) ;
break;
case V_51 :
if ( F_26 ( V_13 -> V_8 , V_52 , V_53 , V_9 ,
sizeof( struct V_54 ) ) < 0 )
{ perror ( L_1 ) ; V_4 = - 1 ; }
break;
case V_55 :
if ( F_27 ( V_13 -> V_8 , V_52 , V_53 ,
V_9 , ( void * ) & V_4 ) < 0 )
{ perror ( L_2 ) ; V_4 = - 1 ; }
break;
case V_56 :
if ( F_26 ( V_13 -> V_8 , V_52 , V_57 , V_9 ,
sizeof( struct V_54 ) ) < 0 )
{ perror ( L_1 ) ; V_4 = - 1 ; }
break;
case V_58 :
if ( F_27 ( V_13 -> V_8 , V_52 , V_57 ,
V_9 , ( void * ) & V_4 ) < 0 )
{ perror ( L_2 ) ; V_4 = - 1 ; }
break;
case V_59 :
case V_60 :
if ( V_6 -> V_21 == V_61 )
{
V_4 = 1 ;
V_6 -> V_21 = 0 ;
}
else
V_4 = 0 ;
break;
#ifdef F_28
case V_62 :
if ( V_6 -> V_21 == F_28 )
{
V_4 = 1 ;
V_6 -> V_21 = 0 ;
}
else
V_4 = 0 ;
break;
#endif
default:
V_4 = 0 ;
break;
}
return ( V_4 ) ;
}
static int F_29 ( T_2 * V_63 , const char * V_64 )
{
int V_65 , V_4 ;
V_65 = strlen ( V_64 ) ;
V_4 = F_19 ( V_63 , V_64 , V_65 ) ;
return ( V_4 ) ;
}
int F_16 ( int V_66 )
{
int V_67 ;
if ( ( V_66 == 0 ) || ( V_66 == - 1 ) )
{
V_67 = F_18 () ;
#if F_30 ( V_68 ) && 0
if ( ( V_66 == - 1 ) && ( V_67 == 0 ) )
return ( 1 ) ;
#endif
return ( F_31 ( V_67 ) ) ;
}
return ( 0 ) ;
}
int F_31 ( int V_67 )
{
switch ( V_67 )
{
#if F_30 ( V_68 )
# if F_30 ( V_69 )
case V_69 :
# endif
# if 0
# if F_30 ( V_70 )
case WSAENOTCONN:
# endif
# endif
#endif
#ifdef F_32
# ifdef V_69
# if V_69 != F_32
case F_32 :
# endif
# else
case F_32 :
# endif
#endif
#if F_30 ( V_71 )
case V_71 :
#endif
#ifdef F_33
case F_33 :
#endif
#ifdef V_61
#if F_32 != V_61
case V_61 :
# endif
#endif
#ifdef F_34
case F_34 :
#endif
#ifdef F_35
case F_35 :
#endif
#ifdef F_36
case F_36 :
#endif
#ifdef F_28
case F_28 :
#endif
return ( 1 ) ;
default:
break;
}
return ( 0 ) ;
}
