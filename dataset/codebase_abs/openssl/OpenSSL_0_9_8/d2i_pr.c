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
if ( ( V_4 -> V_9 . V_14 = F_8 ( NULL ,
( const unsigned char * * ) V_2 , V_3 ) ) == NULL )
{
F_3 ( V_5 , V_11 ) ;
goto V_12;
}
break;
#endif
#ifndef F_9
case V_15 :
if ( ( V_4 -> V_9 . V_16 = F_10 ( NULL ,
( const unsigned char * * ) V_2 , V_3 ) ) == NULL )
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
T_1 * F_12 ( T_1 * * V_1 , const unsigned char * * V_2 ,
long V_3 )
{
F_13 ( V_18 ) * V_19 ;
const unsigned char * V_20 ;
int V_21 ;
V_20 = * V_2 ;
V_19 = F_14 ( NULL , & V_20 , V_3 , V_22 ,
V_23 , V_24 , V_25 ) ;
if( F_15 ( V_19 ) == 6 )
V_21 = V_13 ;
else if ( F_15 ( V_19 ) == 4 )
V_21 = V_15 ;
else V_21 = V_8 ;
F_16 ( V_19 , V_23 ) ;
return F_1 ( V_21 , V_1 , V_2 , V_3 ) ;
}
