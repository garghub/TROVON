static int F_1 ( const T_1 * V_1 , const T_1 * V_2 )
{
return V_1 -> V_3 - V_2 -> V_3 ;
}
static int F_2 ( const T_1 * const * V_1 , const T_1 * const * V_2 )
{
return ( * V_1 ) -> V_3 - ( * V_2 ) -> V_3 ;
}
static int F_3 ( const T_1 * const * V_1 , const T_1 * const * V_2 )
{
int V_4 ;
V_4 = ( * V_1 ) -> V_5 - ( * V_2 ) -> V_5 ;
if ( V_4 )
return V_4 ;
return ( * V_1 ) -> V_6 - ( * V_2 ) -> V_6 ;
}
int F_4 ( int V_7 , int * V_8 , int * V_9 )
{
T_1 V_10 ;
const T_1 * V_11 = NULL ;
V_10 . V_3 = V_7 ;
if ( V_12 )
{
int V_13 = F_5 ( V_12 , & V_10 ) ;
if ( V_13 >= 0 )
V_11 = F_6 ( V_12 , V_13 ) ;
}
#ifndef F_7
if ( V_11 == NULL )
{
V_11 = F_8 ( & V_10 , V_14 ,
sizeof( V_14 ) / sizeof( T_1 ) ) ;
}
#endif
if ( V_11 == NULL )
return 0 ;
if ( V_8 )
* V_8 = V_11 -> V_5 ;
if ( V_9 )
* V_9 = V_11 -> V_6 ;
return 1 ;
}
int F_9 ( int * V_15 , int V_16 , int V_17 )
{
T_1 V_10 ;
const T_1 * V_18 = & V_10 ;
const T_1 * * V_11 = NULL ;
V_10 . V_5 = V_16 ;
V_10 . V_6 = V_17 ;
if ( V_19 )
{
int V_13 = F_5 ( V_19 , & V_10 ) ;
if ( V_13 >= 0 )
{
V_18 = F_6 ( V_19 , V_13 ) ;
V_11 = & V_18 ;
}
}
#ifndef F_7
if ( V_11 == NULL )
{
V_11 = F_10 ( & V_18 , V_20 ,
sizeof( V_20 ) / sizeof( T_1 * )
) ;
}
#endif
if ( V_11 == NULL )
return 0 ;
if ( V_15 )
* V_15 = ( * V_11 ) -> V_3 ;
return 1 ;
}
int F_11 ( int V_7 , int V_21 , int V_6 )
{
T_1 * V_22 ;
if ( ! V_12 )
V_12 = F_12 ( F_2 ) ;
if ( ! V_12 )
return 0 ;
if ( ! V_19 )
V_19 = F_12 ( F_3 ) ;
if ( ! V_19 )
return 0 ;
V_22 = F_13 ( sizeof( int ) * 3 ) ;
if ( ! V_22 )
return 0 ;
V_22 -> V_3 = V_7 ;
V_22 -> V_5 = V_21 ;
V_22 -> V_6 = V_6 ;
if ( ! F_14 ( V_12 , V_22 ) )
{
F_15 ( V_22 ) ;
return 0 ;
}
if ( ! F_14 ( V_19 , V_22 ) )
return 0 ;
F_16 ( V_12 ) ;
F_16 ( V_19 ) ;
return 1 ;
}
static void F_17 ( T_1 * V_23 )
{
F_15 ( V_23 ) ;
}
void F_18 ( void )
{
if ( V_12 )
{
F_19 ( V_12 , F_17 ) ;
V_12 = NULL ;
}
if ( V_19 )
{
F_20 ( V_19 ) ;
V_19 = NULL ;
}
}
main ()
{
int V_24 , V_25 , V_26 ;
int V_27 , V_11 ;
#ifdef F_7
for ( V_27 = 0 ; V_27 < sizeof( V_14 ) / sizeof( T_1 ) ; V_27 ++ )
{
F_11 ( V_14 [ V_27 ] [ 0 ] , V_14 [ V_27 ] [ 1 ] ,
V_14 [ V_27 ] [ 2 ] ) ;
}
#endif
for ( V_27 = 0 ; V_27 < sizeof( V_14 ) / sizeof( T_1 ) ; V_27 ++ )
{
V_24 = V_14 [ V_27 ] [ 0 ] ;
V_11 = F_4 ( V_24 , & V_25 , & V_26 ) ;
printf ( L_1 , V_11 ,
F_21 ( V_24 ) , F_21 ( V_25 ) , F_21 ( V_26 ) ) ;
V_24 = 0 ;
V_11 = F_9 ( & V_24 , V_25 , V_26 ) ;
printf ( L_2 , V_11 ,
F_21 ( V_24 ) , F_21 ( V_25 ) , F_21 ( V_26 ) ) ;
}
}
