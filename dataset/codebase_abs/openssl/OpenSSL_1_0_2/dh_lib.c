void F_1 ( const T_1 * V_1 )
{
V_2 = V_1 ;
}
const T_1 * F_2 ( void )
{
if ( ! V_2 ) {
#ifdef F_3
if ( F_4 () )
return F_5 () ;
else
return F_6 () ;
#else
V_2 = F_6 () ;
#endif
}
return V_2 ;
}
int F_7 ( T_2 * V_3 , const T_1 * V_1 )
{
const T_1 * V_4 ;
V_4 = V_3 -> V_1 ;
if ( V_4 -> V_5 )
V_4 -> V_5 ( V_3 ) ;
#ifndef F_8
if ( V_3 -> V_6 ) {
F_9 ( V_3 -> V_6 ) ;
V_3 -> V_6 = NULL ;
}
#endif
V_3 -> V_1 = V_1 ;
if ( V_1 -> V_7 )
V_1 -> V_7 ( V_3 ) ;
return 1 ;
}
T_2 * F_10 ( void )
{
return F_11 ( NULL ) ;
}
T_2 * F_11 ( T_3 * V_6 )
{
T_2 * V_8 ;
V_8 = ( T_2 * ) F_12 ( sizeof( T_2 ) ) ;
if ( V_8 == NULL ) {
F_13 ( V_9 , V_10 ) ;
return ( NULL ) ;
}
V_8 -> V_1 = F_2 () ;
#ifndef F_8
if ( V_6 ) {
if ( ! F_14 ( V_6 ) ) {
F_13 ( V_9 , V_11 ) ;
F_15 ( V_8 ) ;
return NULL ;
}
V_8 -> V_6 = V_6 ;
} else
V_8 -> V_6 = F_16 () ;
if ( V_8 -> V_6 ) {
V_8 -> V_1 = F_17 ( V_8 -> V_6 ) ;
if ( ! V_8 -> V_1 ) {
F_13 ( V_9 , V_11 ) ;
F_9 ( V_8 -> V_6 ) ;
F_15 ( V_8 ) ;
return NULL ;
}
}
#endif
V_8 -> V_12 = 0 ;
V_8 -> V_13 = 0 ;
V_8 -> V_14 = NULL ;
V_8 -> V_15 = NULL ;
V_8 -> V_16 = 0 ;
V_8 -> V_17 = NULL ;
V_8 -> V_18 = NULL ;
V_8 -> V_19 = NULL ;
V_8 -> V_20 = NULL ;
V_8 -> V_21 = NULL ;
V_8 -> V_22 = 0 ;
V_8 -> V_23 = NULL ;
V_8 -> V_24 = NULL ;
V_8 -> V_25 = 1 ;
V_8 -> V_26 = V_8 -> V_1 -> V_26 & ~ V_27 ;
F_18 ( V_28 , V_8 , & V_8 -> V_29 ) ;
if ( ( V_8 -> V_1 -> V_7 != NULL ) && ! V_8 -> V_1 -> V_7 ( V_8 ) ) {
#ifndef F_8
if ( V_8 -> V_6 )
F_9 ( V_8 -> V_6 ) ;
#endif
F_19 ( V_28 , V_8 , & V_8 -> V_29 ) ;
F_15 ( V_8 ) ;
V_8 = NULL ;
}
return ( V_8 ) ;
}
void F_20 ( T_2 * V_30 )
{
int V_31 ;
if ( V_30 == NULL )
return;
V_31 = F_21 ( & V_30 -> V_25 , - 1 , V_32 ) ;
#ifdef F_22
F_22 ( L_1 , V_30 ) ;
#endif
if ( V_31 > 0 )
return;
#ifdef F_23
if ( V_31 < 0 ) {
fprintf ( V_33 , L_2 ) ;
abort () ;
}
#endif
if ( V_30 -> V_1 -> V_5 )
V_30 -> V_1 -> V_5 ( V_30 ) ;
#ifndef F_8
if ( V_30 -> V_6 )
F_9 ( V_30 -> V_6 ) ;
#endif
F_19 ( V_28 , V_30 , & V_30 -> V_29 ) ;
if ( V_30 -> V_14 != NULL )
F_24 ( V_30 -> V_14 ) ;
if ( V_30 -> V_15 != NULL )
F_24 ( V_30 -> V_15 ) ;
if ( V_30 -> V_19 != NULL )
F_24 ( V_30 -> V_19 ) ;
if ( V_30 -> V_20 != NULL )
F_24 ( V_30 -> V_20 ) ;
if ( V_30 -> V_21 )
F_15 ( V_30 -> V_21 ) ;
if ( V_30 -> V_23 != NULL )
F_24 ( V_30 -> V_23 ) ;
if ( V_30 -> V_17 != NULL )
F_24 ( V_30 -> V_17 ) ;
if ( V_30 -> V_18 != NULL )
F_24 ( V_30 -> V_18 ) ;
F_15 ( V_30 ) ;
}
int F_25 ( T_2 * V_30 )
{
int V_31 = F_21 ( & V_30 -> V_25 , 1 , V_32 ) ;
#ifdef F_22
F_22 ( L_1 , V_30 ) ;
#endif
#ifdef F_23
if ( V_31 < 2 ) {
fprintf ( V_33 , L_3 ) ;
abort () ;
}
#endif
return ( ( V_31 > 1 ) ? 1 : 0 ) ;
}
int F_26 ( long V_34 , void * V_35 , T_4 * V_36 ,
T_5 * V_37 , T_6 * V_38 )
{
return F_27 ( V_28 , V_34 , V_35 ,
V_36 , V_37 , V_38 ) ;
}
int F_28 ( T_2 * V_39 , int V_40 , void * V_41 )
{
return ( F_29 ( & V_39 -> V_29 , V_40 , V_41 ) ) ;
}
void * F_30 ( T_2 * V_39 , int V_40 )
{
return ( F_31 ( & V_39 -> V_29 , V_40 ) ) ;
}
int F_32 ( const T_2 * V_3 )
{
return ( F_33 ( V_3 -> V_14 ) ) ;
}
