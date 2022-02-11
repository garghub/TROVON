T_1 * F_1 ( T_2 * V_1 )
{
T_1 * V_2 ;
V_2 = ( T_1 * ) Malloc ( sizeof( T_1 ) ) ;
if ( V_2 == NULL ) return ( NULL ) ;
V_2 -> V_3 = 0 ;
V_2 -> V_4 = 0 ;
V_2 -> V_1 = V_1 ;
V_2 -> V_5 = NULL ;
V_2 -> V_6 = NULL ;
if ( ( V_1 -> V_7 != NULL ) && ! V_1 -> V_7 ( V_2 ) )
{
Free ( V_2 ) ;
return ( NULL ) ;
}
return ( V_2 ) ;
}
void F_2 ( T_1 * V_8 )
{
if ( V_8 == NULL ) return;
if ( ( V_8 -> V_1 != NULL ) &&
( V_8 -> V_1 -> free != NULL ) )
V_8 -> V_1 -> free ( V_8 ) ;
Free ( V_8 ) ;
}
int F_3 ( T_1 * V_8 )
{
if ( V_8 -> V_1 == NULL ) return ( 0 ) ;
if ( V_8 -> V_1 -> V_3 != NULL )
return ( V_8 -> V_1 -> V_3 ( V_8 ) ) ;
else
return ( 1 ) ;
}
int F_4 ( T_1 * V_8 )
{
if ( V_8 -> V_1 == NULL ) return ( 0 ) ;
if ( V_8 -> V_1 -> V_9 != NULL )
return ( V_8 -> V_1 -> V_9 ( V_8 ) ) ;
else
return ( 1 ) ;
}
int F_5 ( T_1 * V_8 , int V_10 , const char * V_11 , long V_12 ,
char * * V_2 )
{
if ( V_8 -> V_1 == NULL ) return ( - 1 ) ;
if ( V_8 -> V_1 -> V_13 != NULL )
return ( V_8 -> V_1 -> V_13 ( V_8 , V_10 , V_11 , V_12 , V_2 ) ) ;
else
return ( 1 ) ;
}
int F_6 ( T_1 * V_8 , int type , T_3 * V_14 ,
T_4 * V_2 )
{
if ( ( V_8 -> V_1 == NULL ) || ( V_8 -> V_1 -> V_15 == NULL ) )
return ( V_16 ) ;
if ( V_8 -> V_4 ) return ( 0 ) ;
return ( V_8 -> V_1 -> V_15 ( V_8 , type , V_14 , V_2 ) ) ;
}
int F_7 ( T_1 * V_8 , int type , T_3 * V_14 ,
T_5 * V_17 , T_4 * V_2 )
{
if ( ( V_8 -> V_1 == NULL ) ||
( V_8 -> V_1 -> V_18 == NULL ) )
return ( V_16 ) ;
return ( V_8 -> V_1 -> V_18 ( V_8 , type , V_14 , V_17 , V_2 ) ) ;
}
int F_8 ( T_1 * V_8 , int type ,
unsigned char * V_19 , int V_20 , T_4 * V_2 )
{
if ( ( V_8 -> V_1 == NULL ) || ( V_8 -> V_1 -> V_21 == NULL ) )
return ( V_16 ) ;
return ( V_8 -> V_1 -> V_21 ( V_8 , type , V_19 , V_20 , V_2 ) ) ;
}
int F_9 ( T_1 * V_8 , int type , char * V_22 , int V_20 ,
T_4 * V_2 )
{
if ( ( V_8 -> V_1 == NULL ) || ( V_8 -> V_1 -> V_23 == NULL ) )
return ( V_16 ) ;
return ( V_8 -> V_1 -> V_23 ( V_8 , type , V_22 , V_20 , V_2 ) ) ;
}
static unsigned long F_10 ( T_4 * V_24 )
{
unsigned long V_25 ;
switch ( V_24 -> type )
{
case V_26 :
V_25 = F_11 ( V_24 -> V_27 . V_28 -> V_29 -> V_30 ) ;
break;
case V_31 :
V_25 = F_11 ( V_24 -> V_27 . V_32 -> V_32 -> V_33 ) ;
break;
default:
abort () ;
}
return ( V_25 ) ;
}
static int F_12 ( T_4 * V_24 , T_4 * V_34 )
{
int V_2 ;
V_2 = ( V_24 -> type - V_34 -> type ) ;
if ( V_2 ) return ( V_2 ) ;
switch ( V_24 -> type )
{
case V_26 :
V_2 = F_13 ( V_24 -> V_27 . V_28 , V_34 -> V_27 . V_28 ) ;
break;
case V_31 :
V_2 = F_14 ( V_24 -> V_27 . V_32 , V_34 -> V_27 . V_32 ) ;
break;
default:
abort () ;
}
return ( V_2 ) ;
}
T_6 * F_15 ( void )
{
T_6 * V_2 ;
if ( ( V_2 = ( T_6 * ) Malloc ( sizeof( T_6 ) ) ) == NULL )
return ( NULL ) ;
V_2 -> V_35 = F_16 ( F_10 , F_12 ) ;
V_2 -> V_36 = 1 ;
V_2 -> V_37 = F_17 () ;
V_2 -> V_38 = NULL ;
V_2 -> V_39 = NULL ;
memset ( & V_2 -> V_40 , 0 , sizeof( V_41 ) ) ;
V_2 -> V_42 = 1 ;
V_2 -> V_43 = 0 ;
return ( V_2 ) ;
}
static void F_18 ( T_4 * V_24 )
{
if ( V_24 -> type == V_26 )
{
F_19 ( V_24 -> V_27 . V_28 ) ;
}
else if ( V_24 -> type == V_31 )
{
F_20 ( V_24 -> V_27 . V_32 ) ;
}
else
abort () ;
Free ( V_24 ) ;
}
void F_21 ( T_6 * V_44 )
{
int V_45 ;
F_22 ( T_1 ) * V_46 ;
T_1 * V_47 ;
if( V_44 == NULL )
return;
V_46 = V_44 -> V_37 ;
for ( V_45 = 0 ; V_45 < F_23 ( V_46 ) ; V_45 ++ )
{
V_47 = F_24 ( V_46 , V_45 ) ;
F_4 ( V_47 ) ;
F_2 ( V_47 ) ;
}
F_25 ( V_46 ) ;
F_26 ( V_48 , ( char * ) V_44 , & V_44 -> V_40 ) ;
F_27 ( V_44 -> V_35 , F_18 ) ;
F_28 ( V_44 -> V_35 ) ;
Free ( V_44 ) ;
}
T_1 * F_29 ( T_6 * V_49 , T_2 * V_50 )
{
int V_45 ;
F_22 ( T_1 ) * V_46 ;
T_1 * V_47 ;
V_46 = V_49 -> V_37 ;
for ( V_45 = 0 ; V_45 < F_23 ( V_46 ) ; V_45 ++ )
{
V_47 = F_24 ( V_46 , V_45 ) ;
if ( V_50 == V_47 -> V_1 )
{
return ( V_47 ) ;
}
}
V_47 = F_1 ( V_50 ) ;
if ( V_47 == NULL )
return ( NULL ) ;
else
{
V_47 -> V_6 = V_49 ;
if ( F_30 ( V_49 -> V_37 , V_47 ) )
return ( V_47 ) ;
else
{
F_2 ( V_47 ) ;
return ( NULL ) ;
}
}
}
int F_31 ( T_7 * V_51 , int type , T_3 * V_14 ,
T_4 * V_2 )
{
T_6 * V_8 = V_51 -> V_8 ;
T_1 * V_47 ;
T_4 V_52 , * V_53 ;
int V_45 , V_54 ;
V_53 = F_32 ( V_8 -> V_35 , type , V_14 ) ;
if ( V_53 == NULL )
{
for ( V_45 = V_51 -> V_55 ; V_45 < F_23 ( V_8 -> V_37 ) ; V_45 ++ )
{
V_47 = F_24 ( V_8 -> V_37 , V_45 ) ;
V_54 = F_6 ( V_47 , type , V_14 , & V_52 ) ;
if ( V_54 < 0 )
{
V_51 -> V_55 = V_54 ;
return ( V_54 ) ;
}
else if ( V_54 )
{
V_53 = & V_52 ;
break;
}
}
V_51 -> V_55 = 0 ;
if ( V_53 == NULL )
return ( 0 ) ;
}
V_2 -> type = V_53 -> type ;
V_2 -> V_27 . V_56 = V_53 -> V_27 . V_56 ;
F_33 ( V_2 ) ;
return ( 1 ) ;
}
void F_33 ( T_4 * V_24 )
{
switch ( V_24 -> type )
{
case V_26 :
F_34 ( & V_24 -> V_27 . V_28 -> V_42 , 1 , V_57 ) ;
break;
case V_31 :
F_34 ( & V_24 -> V_27 . V_32 -> V_42 , 1 , V_58 ) ;
break;
}
}
void F_35 ( T_4 * V_24 )
{
switch ( V_24 -> type )
{
case V_26 :
F_19 ( V_24 -> V_27 . V_28 ) ;
break;
case V_31 :
F_20 ( V_24 -> V_27 . V_32 ) ;
break;
}
}
T_4 * F_32 ( T_8 * V_25 , int type ,
T_3 * V_14 )
{
T_4 V_52 , * V_53 ;
T_9 V_59 ;
T_10 V_60 ;
T_11 V_61 ;
T_12 V_62 ;
V_52 . type = type ;
switch ( type )
{
case V_26 :
V_52 . V_27 . V_28 = & V_59 ;
V_59 . V_29 = & V_60 ;
V_60 . V_30 = V_14 ;
break;
case V_31 :
V_52 . V_27 . V_32 = & V_61 ;
V_61 . V_32 = & V_62 ;
V_62 . V_33 = V_14 ;
break;
default:
abort () ;
}
V_53 = ( T_4 * ) F_36 ( V_25 , ( char * ) & V_52 ) ;
return ( V_53 ) ;
}
void F_37 ( T_7 * V_8 )
{
if ( V_8 -> V_63 != NULL )
{
F_38 ( V_8 -> V_63 , F_19 ) ;
V_8 -> V_63 = NULL ;
}
F_26 ( V_64 , ( char * ) V_8 , & ( V_8 -> V_40 ) ) ;
memset ( & V_8 -> V_40 , 0 , sizeof( V_41 ) ) ;
}
