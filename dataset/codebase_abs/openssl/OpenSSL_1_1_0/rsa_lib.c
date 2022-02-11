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
V_3 = F_6 () ;
#else
V_3 = F_7 () ;
#endif
}
return V_3 ;
}
const T_2 * F_8 ( const T_1 * V_4 )
{
return V_4 -> V_2 ;
}
int F_9 ( T_1 * V_4 , const T_2 * V_2 )
{
const T_2 * V_5 ;
V_5 = V_4 -> V_2 ;
if ( V_5 -> V_6 )
V_5 -> V_6 ( V_4 ) ;
#ifndef F_10
F_11 ( V_4 -> V_7 ) ;
V_4 -> V_7 = NULL ;
#endif
V_4 -> V_2 = V_2 ;
if ( V_2 -> V_8 )
V_2 -> V_8 ( V_4 ) ;
return 1 ;
}
T_1 * F_2 ( T_3 * V_7 )
{
T_1 * V_9 = F_12 ( sizeof( * V_9 ) ) ;
if ( V_9 == NULL ) {
F_13 ( V_10 , V_11 ) ;
return NULL ;
}
V_9 -> V_12 = 1 ;
V_9 -> V_13 = F_14 () ;
if ( V_9 -> V_13 == NULL ) {
F_13 ( V_10 , V_11 ) ;
F_15 ( V_9 ) ;
return NULL ;
}
V_9 -> V_2 = F_4 () ;
#ifndef F_10
V_9 -> V_14 = V_9 -> V_2 -> V_14 & ~ V_15 ;
if ( V_7 ) {
if ( ! F_16 ( V_7 ) ) {
F_13 ( V_10 , V_16 ) ;
goto V_17;
}
V_9 -> V_7 = V_7 ;
} else
V_9 -> V_7 = F_17 () ;
if ( V_9 -> V_7 ) {
V_9 -> V_2 = F_18 ( V_9 -> V_7 ) ;
if ( V_9 -> V_2 == NULL ) {
F_13 ( V_10 , V_16 ) ;
goto V_17;
}
}
#endif
V_9 -> V_14 = V_9 -> V_2 -> V_14 & ~ V_15 ;
if ( ! F_19 ( V_18 , V_9 , & V_9 -> V_19 ) ) {
goto V_17;
}
if ( ( V_9 -> V_2 -> V_8 != NULL ) && ! V_9 -> V_2 -> V_8 ( V_9 ) ) {
F_13 ( V_10 , V_20 ) ;
goto V_17;
}
return V_9 ;
V_17:
F_20 ( V_9 ) ;
return NULL ;
}
void F_20 ( T_1 * V_1 )
{
int V_21 ;
if ( V_1 == NULL )
return;
F_21 ( & V_1 -> V_12 , - 1 , & V_21 , V_1 -> V_13 ) ;
F_22 ( L_1 , V_1 ) ;
if ( V_21 > 0 )
return;
F_23 ( V_21 < 0 ) ;
if ( V_1 -> V_2 -> V_6 )
V_1 -> V_2 -> V_6 ( V_1 ) ;
#ifndef F_10
F_11 ( V_1 -> V_7 ) ;
#endif
F_24 ( V_18 , V_1 , & V_1 -> V_19 ) ;
F_25 ( V_1 -> V_13 ) ;
F_26 ( V_1 -> V_22 ) ;
F_26 ( V_1 -> V_23 ) ;
F_26 ( V_1 -> V_24 ) ;
F_26 ( V_1 -> V_25 ) ;
F_26 ( V_1 -> V_26 ) ;
F_26 ( V_1 -> V_27 ) ;
F_26 ( V_1 -> V_28 ) ;
F_26 ( V_1 -> V_29 ) ;
F_27 ( V_1 -> V_30 ) ;
F_27 ( V_1 -> V_31 ) ;
F_15 ( V_1 -> V_32 ) ;
F_15 ( V_1 ) ;
}
int F_28 ( T_1 * V_1 )
{
int V_21 ;
if ( F_21 ( & V_1 -> V_12 , 1 , & V_21 , V_1 -> V_13 ) <= 0 )
return 0 ;
F_22 ( L_1 , V_1 ) ;
F_23 ( V_21 < 2 ) ;
return ( ( V_21 > 1 ) ? 1 : 0 ) ;
}
int F_29 ( T_1 * V_1 , int V_33 , void * V_34 )
{
return ( F_30 ( & V_1 -> V_19 , V_33 , V_34 ) ) ;
}
void * F_31 ( const T_1 * V_1 , int V_33 )
{
return ( F_32 ( & V_1 -> V_19 , V_33 ) ) ;
}
int F_33 ( const T_1 * V_4 )
{
return F_34 ( F_35 ( V_4 -> V_22 ) , - 1 ) ;
}
int F_36 ( T_1 * V_1 , T_4 * V_22 , T_4 * V_23 , T_4 * V_24 )
{
if ( ( V_1 -> V_22 == NULL && V_22 == NULL )
|| ( V_1 -> V_23 == NULL && V_23 == NULL ) )
return 0 ;
if ( V_22 != NULL ) {
F_37 ( V_1 -> V_22 ) ;
V_1 -> V_22 = V_22 ;
}
if ( V_23 != NULL ) {
F_37 ( V_1 -> V_23 ) ;
V_1 -> V_23 = V_23 ;
}
if ( V_24 != NULL ) {
F_37 ( V_1 -> V_24 ) ;
V_1 -> V_24 = V_24 ;
}
return 1 ;
}
int F_38 ( T_1 * V_1 , T_4 * V_25 , T_4 * V_26 )
{
if ( ( V_1 -> V_25 == NULL && V_25 == NULL )
|| ( V_1 -> V_26 == NULL && V_26 == NULL ) )
return 0 ;
if ( V_25 != NULL ) {
F_37 ( V_1 -> V_25 ) ;
V_1 -> V_25 = V_25 ;
}
if ( V_26 != NULL ) {
F_37 ( V_1 -> V_26 ) ;
V_1 -> V_26 = V_26 ;
}
return 1 ;
}
int F_39 ( T_1 * V_1 , T_4 * V_27 , T_4 * V_28 , T_4 * V_29 )
{
if ( ( V_1 -> V_27 == NULL && V_27 == NULL )
|| ( V_1 -> V_28 == NULL && V_28 == NULL )
|| ( V_1 -> V_29 == NULL && V_29 == NULL ) )
return 0 ;
if ( V_27 != NULL ) {
F_37 ( V_1 -> V_27 ) ;
V_1 -> V_27 = V_27 ;
}
if ( V_28 != NULL ) {
F_37 ( V_1 -> V_28 ) ;
V_1 -> V_28 = V_28 ;
}
if ( V_29 != NULL ) {
F_37 ( V_1 -> V_29 ) ;
V_1 -> V_29 = V_29 ;
}
return 1 ;
}
void F_40 ( const T_1 * V_1 ,
const T_4 * * V_22 , const T_4 * * V_23 , const T_4 * * V_24 )
{
if ( V_22 != NULL )
* V_22 = V_1 -> V_22 ;
if ( V_23 != NULL )
* V_23 = V_1 -> V_23 ;
if ( V_24 != NULL )
* V_24 = V_1 -> V_24 ;
}
void F_41 ( const T_1 * V_1 , const T_4 * * V_25 , const T_4 * * V_26 )
{
if ( V_25 != NULL )
* V_25 = V_1 -> V_25 ;
if ( V_26 != NULL )
* V_26 = V_1 -> V_26 ;
}
void F_42 ( const T_1 * V_1 ,
const T_4 * * V_27 , const T_4 * * V_28 ,
const T_4 * * V_29 )
{
if ( V_27 != NULL )
* V_27 = V_1 -> V_27 ;
if ( V_28 != NULL )
* V_28 = V_1 -> V_28 ;
if ( V_29 != NULL )
* V_29 = V_1 -> V_29 ;
}
void F_43 ( T_1 * V_1 , int V_14 )
{
V_1 -> V_14 &= ~ V_14 ;
}
int F_44 ( const T_1 * V_1 , int V_14 )
{
return V_1 -> V_14 & V_14 ;
}
void F_45 ( T_1 * V_1 , int V_14 )
{
V_1 -> V_14 |= V_14 ;
}
T_3 * F_46 ( const T_1 * V_1 )
{
return V_1 -> V_7 ;
}
