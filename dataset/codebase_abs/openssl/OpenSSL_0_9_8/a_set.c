static int F_1 ( const void * V_1 , const void * V_2 )
{
const T_1 * V_3 = ( const T_1 * ) V_1 ;
const T_1 * V_4 = ( const T_1 * ) V_2 ;
int V_5 ;
V_5 = memcmp ( V_3 -> V_6 , V_4 -> V_6 ,
V_3 -> V_7 < V_4 -> V_7 ? V_3 -> V_7 : V_4 -> V_7 ) ;
if( V_5 != 0 )
return V_5 ;
return V_3 -> V_7 - V_4 -> V_7 ;
}
int F_2 ( T_2 * V_8 , unsigned char * * V_9 , T_3 * V_10 , int V_11 ,
int V_12 , int V_13 )
{
int V_14 = 0 , V_5 ;
int V_15 ;
unsigned char * V_16 ;
unsigned char * V_17 , * V_18 ;
T_1 * V_19 ;
int V_20 ;
if ( V_8 == NULL ) return ( 0 ) ;
for ( V_15 = F_3 ( V_8 ) - 1 ; V_15 >= 0 ; V_15 -- )
V_14 += V_10 ( F_4 ( V_8 , V_15 ) , NULL ) ;
V_5 = F_5 ( 1 , V_14 , V_11 ) ;
if ( V_9 == NULL ) return ( V_5 ) ;
V_16 = * V_9 ;
F_6 ( & V_16 , 1 , V_14 , V_11 , V_12 ) ;
if( ! V_13 || ( F_3 ( V_8 ) < 2 ) )
{
for ( V_15 = 0 ; V_15 < F_3 ( V_8 ) ; V_15 ++ )
V_10 ( F_4 ( V_8 , V_15 ) , & V_16 ) ;
* V_9 = V_16 ;
return ( V_5 ) ;
}
V_17 = V_16 ;
V_19 = ( T_1 * ) F_7 ( F_3 ( V_8 ) * sizeof( T_1 ) ) ;
if ( V_19 == NULL )
{
F_8 ( V_21 , V_22 ) ;
return ( 0 ) ;
}
for ( V_15 = 0 ; V_15 < F_3 ( V_8 ) ; V_15 ++ )
{
V_19 [ V_15 ] . V_6 = V_16 ;
V_10 ( F_4 ( V_8 , V_15 ) , & V_16 ) ;
V_19 [ V_15 ] . V_7 = V_16 - V_19 [ V_15 ] . V_6 ;
}
* V_9 = V_16 ;
V_20 = V_16 - V_17 ;
qsort ( V_19 , F_3 ( V_8 ) , sizeof( T_1 ) , F_1 ) ;
if ( ! ( V_18 = F_7 ( V_20 ) ) )
{
F_8 ( V_21 , V_22 ) ;
return ( 0 ) ;
}
V_16 = V_18 ;
for( V_15 = 0 ; V_15 < F_3 ( V_8 ) ; ++ V_15 )
{
memcpy ( V_16 , V_19 [ V_15 ] . V_6 , V_19 [ V_15 ] . V_7 ) ;
V_16 += V_19 [ V_15 ] . V_7 ;
}
memcpy ( V_17 , V_18 , V_20 ) ;
F_9 ( V_18 ) ;
F_9 ( V_19 ) ;
return ( V_5 ) ;
}
T_2 * F_10 ( T_2 * * V_8 , const unsigned char * * V_9 , long V_23 ,
T_4 * V_24 , void (* F_11)( void * ) , int V_11 ,
int V_12 )
{
T_5 V_25 ;
T_2 * V_14 = NULL ;
if ( ( V_8 == NULL ) || ( ( * V_8 ) == NULL ) )
{
if ( ( V_14 = F_12 () ) == NULL )
{
F_8 ( V_26 , V_22 ) ;
goto V_27;
}
}
else
V_14 = ( * V_8 ) ;
V_25 . V_16 = * V_9 ;
V_25 . V_28 = ( V_23 == 0 ) ? 0 : ( V_25 . V_16 + V_23 ) ;
V_25 . V_29 = F_13 ( & V_25 . V_16 , & V_25 . V_30 , & V_25 . V_31 , & V_25 . V_32 , V_25 . V_28 - V_25 . V_16 ) ;
if ( V_25 . V_29 & 0x80 ) goto V_27;
if ( V_12 != V_25 . V_32 )
{
F_8 ( V_26 , V_33 ) ;
goto V_27;
}
if ( V_11 != V_25 . V_31 )
{
F_8 ( V_26 , V_34 ) ;
goto V_27;
}
if ( ( V_25 . V_30 + V_25 . V_16 ) > V_25 . V_28 )
{
F_8 ( V_26 , V_35 ) ;
goto V_27;
}
if ( V_25 . V_29 == ( V_36 + 1 ) )
V_25 . V_30 = V_23 + * V_9 - V_25 . V_16 ;
V_25 . V_28 = V_25 . V_16 + V_25 . V_30 ;
while ( V_25 . V_16 < V_25 . V_28 )
{
char * V_37 ;
if ( F_14 () ) break;
if ( ( V_37 = V_24 ( NULL , & V_25 . V_16 , V_25 . V_30 ) ) == NULL )
{
F_8 ( V_26 , V_38 ) ;
F_15 ( * V_9 , ( int ) ( V_25 . V_39 - * V_9 ) ) ;
goto V_27;
}
if ( ! F_16 ( V_14 , V_37 ) ) goto V_27;
}
if ( V_8 != NULL ) ( * V_8 ) = V_14 ;
* V_9 = V_25 . V_16 ;
return ( V_14 ) ;
V_27:
if ( ( V_14 != NULL ) && ( ( V_8 == NULL ) || ( * V_8 != V_14 ) ) )
{
if ( F_11 != NULL )
F_17 ( V_14 , F_11 ) ;
else
F_18 ( V_14 ) ;
}
return ( NULL ) ;
}
