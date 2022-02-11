void F_1 ( const T_1 * V_1 )
{
V_2 = V_1 ;
}
const T_1 * F_2 ( void )
{
if ( ! V_2 )
V_2 = F_3 () ;
return V_2 ;
}
int F_4 ( T_2 * V_3 , const T_1 * V_1 )
{
const T_1 * V_4 ;
V_4 = V_3 -> V_1 ;
if ( V_4 -> V_5 )
V_4 -> V_5 ( V_3 ) ;
#ifndef F_5
F_6 ( V_3 -> V_6 ) ;
V_3 -> V_6 = NULL ;
#endif
V_3 -> V_1 = V_1 ;
if ( V_1 -> V_7 )
V_1 -> V_7 ( V_3 ) ;
return 1 ;
}
T_2 * F_7 ( void )
{
return F_8 ( NULL ) ;
}
T_2 * F_8 ( T_3 * V_6 )
{
T_2 * V_8 = F_9 ( sizeof( * V_8 ) ) ;
if ( V_8 == NULL ) {
F_10 ( V_9 , V_10 ) ;
return NULL ;
}
V_8 -> V_11 = 1 ;
V_8 -> V_12 = F_11 () ;
if ( V_8 -> V_12 == NULL ) {
F_10 ( V_9 , V_10 ) ;
F_12 ( V_8 ) ;
return NULL ;
}
V_8 -> V_1 = F_2 () ;
#ifndef F_5
V_8 -> V_13 = V_8 -> V_1 -> V_13 ;
if ( V_6 ) {
if ( ! F_13 ( V_6 ) ) {
F_10 ( V_9 , V_14 ) ;
goto V_15;
}
V_8 -> V_6 = V_6 ;
} else
V_8 -> V_6 = F_14 () ;
if ( V_8 -> V_6 ) {
V_8 -> V_1 = F_15 ( V_8 -> V_6 ) ;
if ( V_8 -> V_1 == NULL ) {
F_10 ( V_9 , V_14 ) ;
goto V_15;
}
}
#endif
V_8 -> V_13 = V_8 -> V_1 -> V_13 ;
if ( ! F_16 ( V_16 , V_8 , & V_8 -> V_17 ) )
goto V_15;
if ( ( V_8 -> V_1 -> V_7 != NULL ) && ! V_8 -> V_1 -> V_7 ( V_8 ) ) {
F_10 ( V_9 , V_18 ) ;
V_15:
F_17 ( V_8 ) ;
V_8 = NULL ;
}
return V_8 ;
}
void F_17 ( T_2 * V_19 )
{
int V_20 ;
if ( V_19 == NULL )
return;
F_18 ( & V_19 -> V_11 , - 1 , & V_20 , V_19 -> V_12 ) ;
F_19 ( L_1 , V_19 ) ;
if ( V_20 > 0 )
return;
F_20 ( V_20 < 0 ) ;
if ( V_19 -> V_1 -> V_5 )
V_19 -> V_1 -> V_5 ( V_19 ) ;
#ifndef F_5
F_6 ( V_19 -> V_6 ) ;
#endif
F_21 ( V_16 , V_19 , & V_19 -> V_17 ) ;
F_22 ( V_19 -> V_12 ) ;
F_23 ( V_19 -> V_21 ) ;
F_23 ( V_19 -> V_22 ) ;
F_23 ( V_19 -> V_23 ) ;
F_23 ( V_19 -> V_24 ) ;
F_12 ( V_19 -> V_25 ) ;
F_23 ( V_19 -> V_26 ) ;
F_23 ( V_19 -> V_27 ) ;
F_23 ( V_19 -> V_28 ) ;
F_12 ( V_19 ) ;
}
int F_24 ( T_2 * V_19 )
{
int V_20 ;
if ( F_18 ( & V_19 -> V_11 , 1 , & V_20 , V_19 -> V_12 ) <= 0 )
return 0 ;
F_19 ( L_1 , V_19 ) ;
F_20 ( V_20 < 2 ) ;
return ( ( V_20 > 1 ) ? 1 : 0 ) ;
}
int F_25 ( T_2 * V_29 , int V_30 , void * V_31 )
{
return ( F_26 ( & V_29 -> V_17 , V_30 , V_31 ) ) ;
}
void * F_27 ( T_2 * V_29 , int V_30 )
{
return ( F_28 ( & V_29 -> V_17 , V_30 ) ) ;
}
int F_29 ( const T_2 * V_3 )
{
return F_30 ( V_3 -> V_21 ) ;
}
int F_31 ( const T_2 * V_3 )
{
return ( F_32 ( V_3 -> V_21 ) ) ;
}
int F_33 ( const T_2 * V_3 )
{
int V_32 ;
if ( V_3 -> V_23 )
V_32 = F_30 ( V_3 -> V_23 ) ;
else if ( V_3 -> V_33 )
V_32 = V_3 -> V_33 ;
else
V_32 = - 1 ;
return F_34 ( F_30 ( V_3 -> V_21 ) , V_32 ) ;
}
void F_35 ( const T_2 * V_3 ,
const T_4 * * V_21 , const T_4 * * V_23 , const T_4 * * V_22 )
{
if ( V_21 != NULL )
* V_21 = V_3 -> V_21 ;
if ( V_23 != NULL )
* V_23 = V_3 -> V_23 ;
if ( V_22 != NULL )
* V_22 = V_3 -> V_22 ;
}
int F_36 ( T_2 * V_3 , T_4 * V_21 , T_4 * V_23 , T_4 * V_22 )
{
if ( ( V_3 -> V_21 == NULL && V_21 == NULL )
|| ( V_3 -> V_22 == NULL && V_22 == NULL ) )
return 0 ;
if ( V_21 != NULL ) {
F_37 ( V_3 -> V_21 ) ;
V_3 -> V_21 = V_21 ;
}
if ( V_23 != NULL ) {
F_37 ( V_3 -> V_23 ) ;
V_3 -> V_23 = V_23 ;
}
if ( V_22 != NULL ) {
F_37 ( V_3 -> V_22 ) ;
V_3 -> V_22 = V_22 ;
}
if ( V_23 != NULL ) {
V_3 -> V_33 = F_30 ( V_23 ) ;
}
return 1 ;
}
long F_38 ( const T_2 * V_3 )
{
return V_3 -> V_33 ;
}
int F_39 ( T_2 * V_3 , long V_33 )
{
V_3 -> V_33 = V_33 ;
return 1 ;
}
void F_40 ( const T_2 * V_3 , const T_4 * * V_27 , const T_4 * * V_28 )
{
if ( V_27 != NULL )
* V_27 = V_3 -> V_27 ;
if ( V_28 != NULL )
* V_28 = V_3 -> V_28 ;
}
int F_41 ( T_2 * V_3 , T_4 * V_27 , T_4 * V_28 )
{
if ( V_3 -> V_27 == NULL && V_27 == NULL )
return 0 ;
if ( V_27 != NULL ) {
F_37 ( V_3 -> V_27 ) ;
V_3 -> V_27 = V_27 ;
}
if ( V_28 != NULL ) {
F_37 ( V_3 -> V_28 ) ;
V_3 -> V_28 = V_28 ;
}
return 1 ;
}
void F_42 ( T_2 * V_3 , int V_13 )
{
V_3 -> V_13 &= ~ V_13 ;
}
int F_43 ( const T_2 * V_3 , int V_13 )
{
return V_3 -> V_13 & V_13 ;
}
void F_44 ( T_2 * V_3 , int V_13 )
{
V_3 -> V_13 |= V_13 ;
}
T_3 * F_45 ( T_2 * V_3 )
{
return V_3 -> V_6 ;
}
