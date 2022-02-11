T_1 * F_1 ( int type , T_1 * * V_1 , const unsigned char * * V_2 ,
long V_3 )
{
T_1 * V_4 ;
if ( ( V_1 == NULL ) || ( * V_1 == NULL ) )
{
if ( ( V_4 = F_2 () ) == NULL )
{
F_3 ( V_5 , V_6 ) ;
return ( NULL ) ;
}
}
else V_4 = * V_1 ;
V_4 -> V_7 = type ;
V_4 -> type = F_4 ( type ) ;
switch ( V_4 -> type )
{
#ifndef F_5
case V_8 :
if ( ( V_4 -> V_9 . V_10 = F_6 ( NULL ,
( const unsigned char * * ) V_2 , V_3 ) ) == NULL )
{
F_3 ( V_5 , V_11 ) ;
goto V_12;
}
break;
#endif
#ifndef F_7
case V_13 :
if ( ! F_8 ( & ( V_4 -> V_9 . V_14 ) ,
( const unsigned char * * ) V_2 , V_3 ) )
{
F_3 ( V_5 , V_11 ) ;
goto V_12;
}
break;
#endif
#ifndef F_9
case V_15 :
if ( ! F_10 ( & ( V_4 -> V_9 . V_16 ) ,
( const unsigned char * * ) V_2 , V_3 ) )
{
F_3 ( V_5 , V_11 ) ;
goto V_12;
}
break;
#endif
default:
F_3 ( V_5 , V_17 ) ;
goto V_12;
}
if ( V_1 != NULL ) ( * V_1 ) = V_4 ;
return ( V_4 ) ;
V_12:
if ( ( V_4 != NULL ) && ( ( V_1 == NULL ) || ( * V_1 != V_4 ) ) ) F_11 ( V_4 ) ;
return ( NULL ) ;
}
