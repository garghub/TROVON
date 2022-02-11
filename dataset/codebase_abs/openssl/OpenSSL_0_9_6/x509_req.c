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
V_5 -> V_12 -> V_14 = ( unsigned char * ) F_4 ( 1 ) ;
if ( V_5 -> V_12 -> V_14 == NULL ) goto V_10;
V_5 -> V_12 -> V_14 [ 0 ] = 0 ;
if ( ! F_5 ( V_4 , F_6 ( V_1 ) ) )
goto V_10;
V_7 = F_7 ( V_1 ) ;
V_6 = F_8 ( V_4 , V_7 ) ;
F_9 ( V_7 ) ;
if ( ! V_6 ) goto V_10;
if ( V_2 != NULL )
{
if ( ! F_10 ( V_4 , V_2 , V_3 ) )
goto V_10;
}
return ( V_4 ) ;
V_10:
F_11 ( V_4 ) ;
return ( NULL ) ;
}
T_3 * F_12 ( T_1 * V_15 )
{
if ( ( V_15 == NULL ) || ( V_15 -> V_11 == NULL ) )
return ( NULL ) ;
return ( F_13 ( V_15 -> V_11 -> V_16 ) ) ;
}
int F_14 ( int V_17 )
{
int V_6 , V_18 ;
for( V_6 = 0 ; ; V_6 ++ ) {
V_18 = V_19 [ V_6 ] ;
if( V_18 == V_20 ) return 0 ;
else if ( V_17 == V_18 ) return 1 ;
}
}
int * F_15 ( void )
{
return V_19 ;
}
void F_16 ( int * V_21 )
{
V_19 = V_21 ;
}
int F_17 ( const T_1 * V_15 )
{
return F_18 ( V_15 -> V_11 -> V_22 ) ;
}
int F_19 ( const T_1 * V_15 , int V_18 ,
int V_23 )
{
return F_20 ( V_15 -> V_11 -> V_22 , V_18 , V_23 ) ;
}
int F_21 ( const T_1 * V_15 , T_6 * V_24 ,
int V_23 )
{
return F_22 ( V_15 -> V_11 -> V_22 , V_24 , V_23 ) ;
}
T_7 * F_23 ( const T_1 * V_15 , int V_25 )
{
return F_24 ( V_15 -> V_11 -> V_22 , V_25 ) ;
}
T_7 * F_25 ( T_1 * V_15 , int V_25 )
{
return F_26 ( V_15 -> V_11 -> V_22 , V_25 ) ;
}
int F_27 ( T_1 * V_15 , T_7 * V_26 )
{
if( F_28 ( & V_15 -> V_11 -> V_22 , V_26 ) ) return 1 ;
return 0 ;
}
int F_29 ( T_1 * V_15 ,
T_6 * V_24 , int type ,
unsigned char * V_27 , int V_28 )
{
if( F_30 ( & V_15 -> V_11 -> V_22 , V_24 ,
type , V_27 , V_28 ) ) return 1 ;
return 0 ;
}
int F_31 ( T_1 * V_15 ,
int V_18 , int type ,
unsigned char * V_27 , int V_28 )
{
if( F_32 ( & V_15 -> V_11 -> V_22 , V_18 ,
type , V_27 , V_28 ) ) return 1 ;
return 0 ;
}
int F_33 ( T_1 * V_15 ,
char * V_29 , int type ,
unsigned char * V_27 , int V_28 )
{
if( F_34 ( & V_15 -> V_11 -> V_22 , V_29 ,
type , V_27 , V_28 ) ) return 1 ;
return 0 ;
}
