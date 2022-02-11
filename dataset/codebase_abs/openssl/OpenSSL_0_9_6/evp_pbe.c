int F_1 ( T_1 * V_1 , const char * V_2 , int V_3 ,
T_2 * V_4 , T_3 * V_5 , int V_6 )
{
T_4 * V_7 , V_8 ;
int V_9 ;
V_8 . V_10 = F_2 ( V_1 ) ;
if ( V_8 . V_10 != V_11 ) V_9 = F_3 ( V_12 , ( char * ) & V_8 ) ;
else V_9 = - 1 ;
if ( V_9 == - 1 ) {
char V_13 [ 80 ] ;
F_4 ( V_14 , V_15 ) ;
if ( ! V_1 ) strcpy ( V_13 , L_1 ) ;
else F_5 ( V_13 , 80 , V_1 ) ;
F_6 ( 2 , L_2 , V_13 ) ;
return 0 ;
}
if( ! V_2 ) V_3 = 0 ;
else if ( V_3 == - 1 ) V_3 = strlen ( V_2 ) ;
V_7 = ( T_4 * ) F_7 ( V_12 , V_9 ) ;
V_9 = (* V_7 -> V_16 )( V_5 , V_2 , V_3 , V_4 , V_7 -> V_17 ,
V_7 -> V_18 , V_6 ) ;
if ( ! V_9 ) {
F_4 ( V_14 , V_19 ) ;
return 0 ;
}
return 1 ;
}
static int F_8 ( const char * const * V_20 , const char * const * V_21 )
{
T_4 * * V_22 = ( T_4 * * ) V_20 , * * V_23 = ( T_4 * * ) V_21 ;
return ( ( * V_22 ) -> V_10 - ( * V_23 ) -> V_10 ) ;
}
int F_9 ( int V_24 , T_5 * V_17 , T_6 * V_18 ,
T_7 * V_16 )
{
T_4 * V_25 ;
if ( ! V_12 ) V_12 = F_10 ( F_8 ) ;
if ( ! ( V_25 = ( T_4 * ) F_11 ( sizeof( T_4 ) ) ) ) {
F_4 ( V_26 , V_27 ) ;
return 0 ;
}
V_25 -> V_10 = V_24 ;
V_25 -> V_17 = V_17 ;
V_25 -> V_18 = V_18 ;
V_25 -> V_16 = V_16 ;
F_12 ( V_12 , ( char * ) V_25 ) ;
return 1 ;
}
void F_13 ( void )
{
F_14 ( V_12 , V_28 ) ;
V_12 = NULL ;
}
