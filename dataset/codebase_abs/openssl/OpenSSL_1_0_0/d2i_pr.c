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
else
{
V_4 = * V_1 ;
#ifndef F_4
if ( V_4 -> V_7 )
{
F_5 ( V_4 -> V_7 ) ;
V_4 -> V_7 = NULL ;
}
#endif
}
if ( ! F_6 ( V_4 , type ) )
{
F_3 ( V_5 , V_8 ) ;
goto V_9;
}
if ( ! V_4 -> V_10 -> V_11 ||
! V_4 -> V_10 -> V_11 ( V_4 , V_2 , V_3 ) )
{
if ( V_4 -> V_10 -> V_12 )
{
T_2 * V_13 = NULL ;
V_13 = F_7 ( NULL , V_2 , V_3 ) ;
if ( ! V_13 ) goto V_9;
F_8 ( V_4 ) ;
V_4 = F_9 ( V_13 ) ;
F_10 ( V_13 ) ;
}
else
{
F_3 ( V_5 , V_14 ) ;
goto V_9;
}
}
if ( V_1 != NULL ) ( * V_1 ) = V_4 ;
return ( V_4 ) ;
V_9:
if ( ( V_4 != NULL ) && ( ( V_1 == NULL ) || ( * V_1 != V_4 ) ) ) F_8 ( V_4 ) ;
return ( NULL ) ;
}
T_1 * F_11 ( T_1 * * V_1 , const unsigned char * * V_2 ,
long V_3 )
{
F_12 ( V_15 ) * V_16 ;
const unsigned char * V_17 ;
int V_18 ;
V_17 = * V_2 ;
V_16 = F_13 ( NULL , & V_17 , V_3 ) ;
if( F_14 ( V_16 ) == 6 )
V_18 = V_19 ;
else if ( F_14 ( V_16 ) == 4 )
V_18 = V_20 ;
else if ( F_14 ( V_16 ) == 3 )
{
T_2 * V_13 = F_7 ( NULL , V_2 , V_3 ) ;
T_1 * V_4 ;
F_15 ( V_16 , V_21 ) ;
if ( ! V_13 )
{
F_3 ( V_22 , V_23 ) ;
return NULL ;
}
V_4 = F_9 ( V_13 ) ;
F_10 ( V_13 ) ;
if ( V_1 ) {
* V_1 = V_4 ;
}
return V_4 ;
}
else V_18 = V_24 ;
F_15 ( V_16 , V_21 ) ;
return F_1 ( V_18 , V_1 , V_2 , V_3 ) ;
}
