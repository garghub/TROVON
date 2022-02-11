static const char * F_1 ( void )
{
if( V_1 )
return V_1 ;
return L_1 ;
}
static void F_2 ( void )
{
if( V_1 )
F_3 ( ( void * ) V_1 ) ;
V_1 = NULL ;
}
static long F_4 ( const char * V_2 )
{
F_2 () ;
return ( ( ( V_1 = F_5 ( V_2 ) ) != NULL ) ? 1 : 0 ) ;
}
static int F_6 ( T_1 * V_3 )
{
F_2 () ;
F_7 () ;
return 1 ;
}
static int F_8 ( T_1 * V_3 )
{
if( V_4 != NULL )
{
F_9 ( V_5 , V_6 ) ;
return 0 ;
}
V_4 = F_10 ( NULL , F_1 () , NULL ,
V_7 ) ;
if( ! V_4 )
{
F_9 ( V_5 , V_8 ) ;
return 0 ;
}
V_9 = ( V_10 * ) F_11 ( V_4 , V_11 ) ;
if( ! V_9 )
{
F_9 ( V_5 , V_12 ) ;
return 0 ;
}
return 1 ;
}
static int F_12 ( T_1 * V_3 )
{
F_2 () ;
if( V_4 == NULL )
{
F_9 ( V_13 , V_14 ) ;
return 0 ;
}
if( ! F_13 ( V_4 ) )
{
F_9 ( V_13 , V_15 ) ;
return 0 ;
}
V_4 = NULL ;
V_9 = NULL ;
return 1 ;
}
static int F_14 ( T_1 * V_3 , int V_16 , long V_17 , void * V_18 , void (* F_15)() )
{
int V_19 = ( ( V_4 == NULL ) ? 0 : 1 ) ;
switch( V_16 )
{
case V_20 :
if( V_18 == NULL )
{
F_9 ( V_21 , V_22 ) ;
return 0 ;
}
if( V_19 )
{
F_9 ( V_21 , V_6 ) ;
return 0 ;
}
return F_4 ( ( const char * ) V_18 ) ;
default:
break;
}
F_9 ( V_21 , V_23 ) ;
return 0 ;
}
static int F_16 ( T_2 * V_24 , const T_2 * V_25 , const T_2 * V_18 ,
const T_2 * V_26 , T_3 * V_27 )
{
if( ! V_4 )
{
F_9 ( V_28 , V_14 ) ;
return 0 ;
}
return V_9 ( V_24 , V_25 , V_18 , V_26 ) ;
}
static int F_17 ( T_2 * V_29 , const T_2 * V_30 , T_4 * V_31 )
{
return F_16 ( V_29 , V_30 , V_31 -> V_32 , V_31 -> V_33 , NULL ) ;
}
static int F_18 ( T_5 * V_34 , T_2 * V_35 , T_2 * V_36 ,
T_2 * V_37 , T_2 * V_38 , T_2 * V_39 , T_2 * V_26 ,
T_3 * V_27 , T_6 * V_40 )
{
T_2 V_41 ;
int V_42 = 0 ;
F_19 ( & V_41 ) ;
if ( ! F_16 ( V_35 , V_36 , V_37 , V_26 , V_27 ) )
goto V_43;
if ( ! F_16 ( & V_41 , V_38 , V_39 , V_26 , V_27 ) )
goto V_43;
if ( ! F_20 ( V_35 , V_35 , & V_41 , V_26 , V_27 ) )
goto V_43;
V_42 = 1 ;
V_43:
F_21 ( & V_41 ) ;
return V_42 ;
}
static int F_22 ( T_5 * V_34 , T_2 * V_24 , T_2 * V_25 ,
const T_2 * V_18 , const T_2 * V_26 , T_3 * V_27 ,
T_6 * V_44 )
{
return F_16 ( V_24 , V_25 , V_18 , V_26 , V_27 ) ;
}
static int F_23 ( T_2 * V_24 , const T_2 * V_25 , const T_2 * V_18 ,
const T_2 * V_26 , T_3 * V_27 , T_6 * V_44 )
{
return F_16 ( V_24 , V_25 , V_18 , V_26 , V_27 ) ;
}
static int F_24 ( const T_7 * V_45 , T_2 * V_24 ,
const T_2 * V_25 , const T_2 * V_18 ,
const T_2 * V_26 , T_3 * V_27 , T_6 * V_44 )
{
return F_16 ( V_24 , V_25 , V_18 , V_26 , V_27 ) ;
}
static int F_25 ( T_1 * V_3 )
{
#ifndef F_26
const T_8 * V_46 ;
#endif
#ifndef F_27
const T_9 * V_47 ;
#endif
#ifndef F_28
const T_10 * V_48 ;
#endif
if( ! F_29 ( V_3 , V_49 ) ||
! F_30 ( V_3 , V_50 ) ||
#ifndef F_26
! F_31 ( V_3 , & V_51 ) ||
#endif
#ifndef F_27
! F_32 ( V_3 , & V_52 ) ||
#endif
#ifndef F_28
! F_33 ( V_3 , & V_53 ) ||
#endif
! F_34 ( V_3 , F_6 ) ||
! F_35 ( V_3 , F_8 ) ||
! F_36 ( V_3 , F_12 ) ||
! F_37 ( V_3 , F_14 ) ||
! F_38 ( V_3 , V_54 ) )
return 0 ;
#ifndef F_26
V_46 = F_39 () ;
V_51 . V_55 = V_46 -> V_55 ;
V_51 . V_56 = V_46 -> V_56 ;
V_51 . V_57 = V_46 -> V_57 ;
V_51 . V_58 = V_46 -> V_58 ;
#endif
#ifndef F_27
V_47 = F_40 () ;
V_52 . V_59 = V_47 -> V_59 ;
V_52 . V_60 = V_47 -> V_60 ;
V_52 . V_61 = V_47 -> V_61 ;
#endif
#ifndef F_28
V_48 = F_41 () ;
V_53 . V_62 = V_48 -> V_62 ;
V_53 . V_63 = V_48 -> V_63 ;
#endif
F_42 () ;
return 1 ;
}
static T_1 * F_43 ( void )
{
T_1 * V_64 = F_44 () ;
if( ! V_64 )
return NULL ;
if( ! F_25 ( V_64 ) )
{
F_45 ( V_64 ) ;
return NULL ;
}
return V_64 ;
}
void F_46 ( void )
{
T_1 * V_65 = F_43 () ;
if( ! V_65 ) return;
F_47 ( V_65 ) ;
F_45 ( V_65 ) ;
F_48 () ;
}
static int F_49 ( T_1 * V_3 , const char * V_66 )
{
if( V_66 && ( strcmp ( V_66 , V_49 ) != 0 ) )
return 0 ;
if( ! F_25 ( V_3 ) )
return 0 ;
return 1 ;
}
