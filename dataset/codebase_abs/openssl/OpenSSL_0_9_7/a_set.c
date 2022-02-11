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
int F_2 ( T_2 * V_8 , unsigned char * * V_9 , int (* F_3)() , int V_10 ,
int V_11 , int V_12 )
{
int V_13 = 0 , V_5 ;
int V_14 ;
unsigned char * V_15 ;
unsigned char * V_16 , * V_17 ;
T_1 * V_18 ;
int V_19 ;
if ( V_8 == NULL ) return ( 0 ) ;
for ( V_14 = F_4 ( V_8 ) - 1 ; V_14 >= 0 ; V_14 -- )
V_13 += F_3 ( F_5 ( V_8 , V_14 ) , NULL ) ;
V_5 = F_6 ( 1 , V_13 , V_10 ) ;
if ( V_9 == NULL ) return ( V_5 ) ;
V_15 = * V_9 ;
F_7 ( & V_15 , 1 , V_13 , V_10 , V_11 ) ;
if( ! V_12 || ( F_4 ( V_8 ) < 2 ) )
{
for ( V_14 = 0 ; V_14 < F_4 ( V_8 ) ; V_14 ++ )
F_3 ( F_5 ( V_8 , V_14 ) , & V_15 ) ;
* V_9 = V_15 ;
return ( V_5 ) ;
}
V_16 = V_15 ;
if ( ! ( V_18 = ( T_1 * ) F_8 ( F_4 ( V_8 ) * sizeof( T_1 ) ) ) ) return 0 ;
for ( V_14 = 0 ; V_14 < F_4 ( V_8 ) ; V_14 ++ )
{
V_18 [ V_14 ] . V_6 = V_15 ;
F_3 ( F_5 ( V_8 , V_14 ) , & V_15 ) ;
V_18 [ V_14 ] . V_7 = V_15 - V_18 [ V_14 ] . V_6 ;
}
* V_9 = V_15 ;
V_19 = V_15 - V_16 ;
qsort ( V_18 , F_4 ( V_8 ) , sizeof( T_1 ) , F_1 ) ;
if ( ! ( V_17 = F_8 ( V_19 ) ) ) return 0 ;
V_15 = V_17 ;
for( V_14 = 0 ; V_14 < F_4 ( V_8 ) ; ++ V_14 )
{
memcpy ( V_15 , V_18 [ V_14 ] . V_6 , V_18 [ V_14 ] . V_7 ) ;
V_15 += V_18 [ V_14 ] . V_7 ;
}
memcpy ( V_16 , V_17 , V_19 ) ;
F_9 ( V_17 ) ;
F_9 ( V_18 ) ;
return ( V_5 ) ;
}
T_2 * F_10 ( T_2 * * V_8 , unsigned char * * V_9 , long V_20 ,
char * (* F_3)() , void (* F_11)( void * ) , int V_10 , int V_11 )
{
T_3 V_21 ;
T_2 * V_13 = NULL ;
if ( ( V_8 == NULL ) || ( ( * V_8 ) == NULL ) )
{ if ( ( V_13 = F_12 () ) == NULL ) goto V_22; }
else
V_13 = ( * V_8 ) ;
V_21 . V_15 = * V_9 ;
V_21 . V_23 = ( V_20 == 0 ) ? 0 : ( V_21 . V_15 + V_20 ) ;
V_21 . V_24 = F_13 ( & V_21 . V_15 , & V_21 . V_25 , & V_21 . V_26 , & V_21 . V_27 , V_21 . V_23 - V_21 . V_15 ) ;
if ( V_21 . V_24 & 0x80 ) goto V_22;
if ( V_11 != V_21 . V_27 )
{
F_14 ( V_28 , V_29 ) ;
goto V_22;
}
if ( V_10 != V_21 . V_26 )
{
F_14 ( V_28 , V_30 ) ;
goto V_22;
}
if ( ( V_21 . V_25 + V_21 . V_15 ) > V_21 . V_23 )
{
F_14 ( V_28 , V_31 ) ;
goto V_22;
}
if ( V_21 . V_24 == ( V_32 + 1 ) )
V_21 . V_25 = V_20 + * V_9 - V_21 . V_15 ;
V_21 . V_23 = V_21 . V_15 + V_21 . V_25 ;
while ( V_21 . V_15 < V_21 . V_23 )
{
char * V_33 ;
if ( F_15 () ) break;
if ( ( V_33 = F_3 ( NULL , & V_21 . V_15 , V_21 . V_25 , V_21 . V_23 - V_21 . V_15 ) ) == NULL )
{
F_14 ( V_28 , V_34 ) ;
F_16 ( * V_9 , ( int ) ( V_21 . V_35 - * V_9 ) ) ;
goto V_22;
}
if ( ! F_17 ( V_13 , V_33 ) ) goto V_22;
}
if ( V_8 != NULL ) ( * V_8 ) = V_13 ;
* V_9 = V_21 . V_15 ;
return ( V_13 ) ;
V_22:
if ( ( V_13 != NULL ) && ( ( V_8 == NULL ) || ( * V_8 != V_13 ) ) )
{
if ( F_11 != NULL )
F_18 ( V_13 , F_11 ) ;
else
F_19 ( V_13 ) ;
}
return ( NULL ) ;
}
