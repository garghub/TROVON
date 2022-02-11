T_1 * F_1 ( void )
{
T_1 * V_1 = F_2 ( NULL ) ;
return V_1 ;
}
void F_3 ( const T_2 * V_2 )
{
V_3 = V_2 ;
}
const T_2 * F_4 ( void )
{
if ( V_3 == NULL ) {
#ifdef F_5
if ( F_6 () )
return F_7 () ;
else
return F_8 () ;
#else
# ifdef F_9
V_3 = F_10 () ;
# else
V_3 = F_8 () ;
# endif
#endif
}
return V_3 ;
}
const T_2 * F_11 ( const T_1 * V_4 )
{
return V_4 -> V_2 ;
}
int F_12 ( T_1 * V_4 , const T_2 * V_2 )
{
const T_2 * V_5 ;
V_5 = V_4 -> V_2 ;
if ( V_5 -> V_6 )
V_5 -> V_6 ( V_4 ) ;
#ifndef F_13
if ( V_4 -> V_7 ) {
F_14 ( V_4 -> V_7 ) ;
V_4 -> V_7 = NULL ;
}
#endif
V_4 -> V_2 = V_2 ;
if ( V_2 -> V_8 )
V_2 -> V_8 ( V_4 ) ;
return 1 ;
}
T_1 * F_2 ( T_3 * V_7 )
{
T_1 * V_9 ;
V_9 = ( T_1 * ) F_15 ( sizeof( T_1 ) ) ;
if ( V_9 == NULL ) {
F_16 ( V_10 , V_11 ) ;
return NULL ;
}
V_9 -> V_2 = F_4 () ;
#ifndef F_13
if ( V_7 ) {
if ( ! F_17 ( V_7 ) ) {
F_16 ( V_10 , V_12 ) ;
F_18 ( V_9 ) ;
return NULL ;
}
V_9 -> V_7 = V_7 ;
} else
V_9 -> V_7 = F_19 () ;
if ( V_9 -> V_7 ) {
V_9 -> V_2 = F_20 ( V_9 -> V_7 ) ;
if ( ! V_9 -> V_2 ) {
F_16 ( V_10 , V_12 ) ;
F_14 ( V_9 -> V_7 ) ;
F_18 ( V_9 ) ;
return NULL ;
}
}
#endif
V_9 -> V_13 = 0 ;
V_9 -> V_14 = 0 ;
V_9 -> V_15 = NULL ;
V_9 -> V_16 = NULL ;
V_9 -> V_17 = NULL ;
V_9 -> V_18 = NULL ;
V_9 -> V_19 = NULL ;
V_9 -> V_20 = NULL ;
V_9 -> V_21 = NULL ;
V_9 -> V_22 = NULL ;
V_9 -> V_23 = 1 ;
V_9 -> V_24 = NULL ;
V_9 -> V_25 = NULL ;
V_9 -> V_26 = NULL ;
V_9 -> V_27 = NULL ;
V_9 -> V_28 = NULL ;
V_9 -> V_29 = NULL ;
V_9 -> V_30 = V_9 -> V_2 -> V_30 & ~ V_31 ;
if ( ! F_21 ( V_32 , V_9 , & V_9 -> V_33 ) ) {
#ifndef F_13
if ( V_9 -> V_7 )
F_14 ( V_9 -> V_7 ) ;
#endif
F_18 ( V_9 ) ;
return ( NULL ) ;
}
if ( ( V_9 -> V_2 -> V_8 != NULL ) && ! V_9 -> V_2 -> V_8 ( V_9 ) ) {
#ifndef F_13
if ( V_9 -> V_7 )
F_14 ( V_9 -> V_7 ) ;
#endif
F_22 ( V_32 , V_9 , & V_9 -> V_33 ) ;
F_18 ( V_9 ) ;
V_9 = NULL ;
}
return ( V_9 ) ;
}
void F_23 ( T_1 * V_1 )
{
int V_34 ;
if ( V_1 == NULL )
return;
V_34 = F_24 ( & V_1 -> V_23 , - 1 , V_35 ) ;
#ifdef F_25
F_25 ( L_1 , V_1 ) ;
#endif
if ( V_34 > 0 )
return;
#ifdef F_26
if ( V_34 < 0 ) {
fprintf ( V_36 , L_2 ) ;
abort () ;
}
#endif
if ( V_1 -> V_2 -> V_6 )
V_1 -> V_2 -> V_6 ( V_1 ) ;
#ifndef F_13
if ( V_1 -> V_7 )
F_14 ( V_1 -> V_7 ) ;
#endif
F_22 ( V_32 , V_1 , & V_1 -> V_33 ) ;
if ( V_1 -> V_15 != NULL )
F_27 ( V_1 -> V_15 ) ;
if ( V_1 -> V_16 != NULL )
F_27 ( V_1 -> V_16 ) ;
if ( V_1 -> V_17 != NULL )
F_27 ( V_1 -> V_17 ) ;
if ( V_1 -> V_18 != NULL )
F_27 ( V_1 -> V_18 ) ;
if ( V_1 -> V_19 != NULL )
F_27 ( V_1 -> V_19 ) ;
if ( V_1 -> V_20 != NULL )
F_27 ( V_1 -> V_20 ) ;
if ( V_1 -> V_21 != NULL )
F_27 ( V_1 -> V_21 ) ;
if ( V_1 -> V_22 != NULL )
F_27 ( V_1 -> V_22 ) ;
if ( V_1 -> V_27 != NULL )
F_28 ( V_1 -> V_27 ) ;
if ( V_1 -> V_28 != NULL )
F_28 ( V_1 -> V_28 ) ;
if ( V_1 -> V_29 != NULL )
F_29 ( V_1 -> V_29 ) ;
F_18 ( V_1 ) ;
}
int F_30 ( T_1 * V_1 )
{
int V_34 = F_24 ( & V_1 -> V_23 , 1 , V_35 ) ;
#ifdef F_25
F_25 ( L_1 , V_1 ) ;
#endif
#ifdef F_26
if ( V_34 < 2 ) {
fprintf ( V_36 , L_3 ) ;
abort () ;
}
#endif
return ( ( V_34 > 1 ) ? 1 : 0 ) ;
}
int F_31 ( long V_37 , void * V_38 , T_4 * V_39 ,
T_5 * V_40 , T_6 * V_41 )
{
return F_32 ( V_32 , V_37 , V_38 ,
V_39 , V_40 , V_41 ) ;
}
int F_33 ( T_1 * V_1 , int V_42 , void * V_43 )
{
return ( F_34 ( & V_1 -> V_33 , V_42 , V_43 ) ) ;
}
void * F_35 ( const T_1 * V_1 , int V_42 )
{
return ( F_36 ( & V_1 -> V_33 , V_42 ) ) ;
}
int F_37 ( T_1 * V_1 )
{
int V_34 , V_44 , V_45 , V_46 ;
char * V_18 ;
T_7 * V_47 , * * V_48 [ 6 ] , * V_49 ;
T_8 * V_50 ;
if ( V_1 -> V_17 == NULL )
return ( 1 ) ;
V_48 [ 0 ] = & V_1 -> V_17 ;
V_48 [ 1 ] = & V_1 -> V_18 ;
V_48 [ 2 ] = & V_1 -> V_19 ;
V_48 [ 3 ] = & V_1 -> V_20 ;
V_48 [ 4 ] = & V_1 -> V_21 ;
V_48 [ 5 ] = & V_1 -> V_22 ;
V_45 = sizeof( T_7 ) * 6 ;
V_46 = V_45 / sizeof( T_8 ) + 1 ;
V_44 = 1 ;
for ( V_34 = 0 ; V_34 < 6 ; V_34 ++ )
V_44 += ( * V_48 [ V_34 ] ) -> V_51 ;
if ( ( V_18 = F_38 ( ( V_46 + V_44 ) * sizeof( T_8 ) ) ) == NULL ) {
F_16 ( V_52 , V_11 ) ;
return ( 0 ) ;
}
V_47 = ( T_7 * ) V_18 ;
V_50 = ( T_8 * ) & ( V_18 [ V_46 ] ) ;
for ( V_34 = 0 ; V_34 < 6 ; V_34 ++ ) {
V_49 = * ( V_48 [ V_34 ] ) ;
* ( V_48 [ V_34 ] ) = & ( V_47 [ V_34 ] ) ;
memcpy ( ( char * ) & ( V_47 [ V_34 ] ) , ( char * ) V_49 , sizeof( T_7 ) ) ;
V_47 [ V_34 ] . V_30 = V_53 ;
V_47 [ V_34 ] . V_17 = V_50 ;
memcpy ( ( char * ) V_50 , V_49 -> V_17 , sizeof( T_8 ) * V_49 -> V_51 ) ;
V_50 += V_49 -> V_51 ;
F_27 ( V_49 ) ;
}
V_1 -> V_30 &= ~ ( V_54 | V_55 ) ;
V_1 -> V_29 = V_18 ;
return ( 1 ) ;
}
