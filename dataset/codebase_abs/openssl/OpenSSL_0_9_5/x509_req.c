T_1 * F_1 ( T_2 * V_1 , T_3 * V_2 , const T_4 * V_3 )
{
T_1 * V_4 ;
T_5 * V_5 ;
int V_6 ;
T_3 * V_7 ;
V_4 = F_2 () ;
if ( V_4 == NULL )
{
F_3 ( V_8 , V_9 ) ;
goto V_10;
}
V_5 = V_4 -> V_11 ;
V_5 -> V_12 -> V_13 = 1 ;
V_5 -> V_12 -> V_14 = ( unsigned char * ) Malloc ( 1 ) ;
if ( V_5 -> V_12 -> V_14 == NULL ) goto V_10;
V_5 -> V_12 -> V_14 [ 0 ] = 0 ;
if ( ! F_4 ( V_4 , F_5 ( V_1 ) ) )
goto V_10;
V_7 = F_6 ( V_1 ) ;
V_6 = F_7 ( V_4 , V_7 ) ;
F_8 ( V_7 ) ;
if ( ! V_6 ) goto V_10;
if ( V_2 != NULL )
{
if ( ! F_9 ( V_4 , V_2 , V_3 ) )
goto V_10;
}
return ( V_4 ) ;
V_10:
F_10 ( V_4 ) ;
return ( NULL ) ;
}
T_3 * F_11 ( T_1 * V_15 )
{
if ( ( V_15 == NULL ) || ( V_15 -> V_11 == NULL ) )
return ( NULL ) ;
return ( F_12 ( V_15 -> V_11 -> V_16 ) ) ;
}
int F_13 ( int V_17 )
{
int V_6 , V_18 ;
for( V_6 = 0 ; ; V_6 ++ ) {
V_18 = V_19 [ V_6 ] ;
if( V_18 == V_20 ) return 0 ;
else if ( V_17 == V_18 ) return 1 ;
}
}
int * F_14 ( void )
{
return V_19 ;
}
void F_15 ( int * V_21 )
{
V_19 = V_21 ;
}
int F_16 ( const T_1 * V_15 )
{
return F_17 ( V_15 -> V_11 -> V_22 ) ;
}
int F_18 ( const T_1 * V_15 , int V_18 ,
int V_23 )
{
return F_19 ( V_15 -> V_11 -> V_22 , V_18 , V_23 ) ;
}
int F_20 ( const T_1 * V_15 , T_6 * V_24 ,
int V_23 )
{
return F_21 ( V_15 -> V_11 -> V_22 , V_24 , V_23 ) ;
}
T_7 * F_22 ( const T_1 * V_15 , int V_25 )
{
return F_23 ( V_15 -> V_11 -> V_22 , V_25 ) ;
}
T_7 * F_24 ( T_1 * V_15 , int V_25 )
{
return F_25 ( V_15 -> V_11 -> V_22 , V_25 ) ;
}
int F_26 ( T_1 * V_15 , T_7 * V_26 )
{
if( F_27 ( & V_15 -> V_11 -> V_22 , V_26 ) ) return 1 ;
return 0 ;
}
int F_28 ( T_1 * V_15 ,
T_6 * V_24 , int type ,
unsigned char * V_27 , int V_28 )
{
if( F_29 ( & V_15 -> V_11 -> V_22 , V_24 ,
type , V_27 , V_28 ) ) return 1 ;
return 0 ;
}
int F_30 ( T_1 * V_15 ,
int V_18 , int type ,
unsigned char * V_27 , int V_28 )
{
if( F_31 ( & V_15 -> V_11 -> V_22 , V_18 ,
type , V_27 , V_28 ) ) return 1 ;
return 0 ;
}
int F_32 ( T_1 * V_15 ,
char * V_29 , int type ,
unsigned char * V_27 , int V_28 )
{
if( F_33 ( & V_15 -> V_11 -> V_22 , V_29 ,
type , V_27 , V_28 ) ) return 1 ;
return 0 ;
}
