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
T_2 * F_4 ( void )
{
return F_5 ( NULL ) ;
}
int F_6 ( T_2 * V_3 , const T_1 * V_1 )
{
const T_1 * V_4 ;
V_4 = V_3 -> V_1 ;
if ( V_4 -> V_5 )
V_4 -> V_5 ( V_3 ) ;
#ifndef F_7
F_8 ( V_3 -> V_6 ) ;
V_3 -> V_6 = NULL ;
#endif
V_3 -> V_1 = V_1 ;
if ( V_1 -> V_7 )
V_1 -> V_7 ( V_3 ) ;
return 1 ;
}
const T_1 * F_9 ( T_2 * V_8 )
{
return V_8 -> V_1 ;
}
T_2 * F_5 ( T_3 * V_6 )
{
T_2 * V_9 = F_10 ( sizeof( * V_9 ) ) ;
if ( V_9 == NULL ) {
F_11 ( V_10 , V_11 ) ;
return NULL ;
}
V_9 -> V_12 = 1 ;
V_9 -> V_13 = F_12 () ;
if ( V_9 -> V_13 == NULL ) {
F_11 ( V_10 , V_11 ) ;
F_13 ( V_9 ) ;
return NULL ;
}
V_9 -> V_1 = F_2 () ;
#ifndef F_7
V_9 -> V_14 = V_9 -> V_1 -> V_14 & ~ V_15 ;
if ( V_6 ) {
if ( ! F_14 ( V_6 ) ) {
F_11 ( V_10 , V_16 ) ;
goto V_17;
}
V_9 -> V_6 = V_6 ;
} else
V_9 -> V_6 = F_15 () ;
if ( V_9 -> V_6 ) {
V_9 -> V_1 = F_16 ( V_9 -> V_6 ) ;
if ( V_9 -> V_1 == NULL ) {
F_11 ( V_10 , V_16 ) ;
goto V_17;
}
}
#endif
V_9 -> V_14 = V_9 -> V_1 -> V_14 & ~ V_15 ;
if ( ! F_17 ( V_18 , V_9 , & V_9 -> V_19 ) )
goto V_17;
if ( ( V_9 -> V_1 -> V_7 != NULL ) && ! V_9 -> V_1 -> V_7 ( V_9 ) ) {
F_11 ( V_10 , V_20 ) ;
V_17:
F_18 ( V_9 ) ;
V_9 = NULL ;
}
return V_9 ;
}
void F_18 ( T_2 * V_21 )
{
int V_22 ;
if ( V_21 == NULL )
return;
F_19 ( & V_21 -> V_12 , - 1 , & V_22 , V_21 -> V_13 ) ;
F_20 ( L_1 , V_21 ) ;
if ( V_22 > 0 )
return;
F_21 ( V_22 < 0 ) ;
if ( V_21 -> V_1 -> V_5 )
V_21 -> V_1 -> V_5 ( V_21 ) ;
#ifndef F_7
F_8 ( V_21 -> V_6 ) ;
#endif
F_22 ( V_18 , V_21 , & V_21 -> V_19 ) ;
F_23 ( V_21 -> V_13 ) ;
F_24 ( V_21 -> V_23 ) ;
F_24 ( V_21 -> V_24 ) ;
F_24 ( V_21 -> V_25 ) ;
F_24 ( V_21 -> V_26 ) ;
F_24 ( V_21 -> V_27 ) ;
F_13 ( V_21 ) ;
}
int F_25 ( T_2 * V_21 )
{
int V_22 ;
if ( F_19 ( & V_21 -> V_12 , 1 , & V_22 , V_21 -> V_13 ) <= 0 )
return 0 ;
F_20 ( L_1 , V_21 ) ;
F_21 ( V_22 < 2 ) ;
return ( ( V_22 > 1 ) ? 1 : 0 ) ;
}
int F_26 ( const T_2 * V_21 )
{
int V_9 , V_22 ;
T_4 V_28 ;
unsigned char V_29 [ 4 ] ;
V_22 = F_27 ( V_21 -> V_24 ) ;
V_28 . V_30 = ( V_22 + 7 ) / 8 ;
V_28 . V_31 = V_29 ;
V_28 . type = V_32 ;
V_29 [ 0 ] = 0xff ;
V_22 = F_28 ( & V_28 , NULL ) ;
V_22 += V_22 ;
V_9 = F_29 ( 1 , V_22 , V_33 ) ;
return ( V_9 ) ;
}
int F_30 ( T_2 * V_8 , int V_34 , void * V_35 )
{
return ( F_31 ( & V_8 -> V_19 , V_34 , V_35 ) ) ;
}
void * F_32 ( T_2 * V_8 , int V_34 )
{
return ( F_33 ( & V_8 -> V_19 , V_34 ) ) ;
}
int F_34 ( const T_2 * V_8 )
{
if ( V_8 -> V_23 && V_8 -> V_24 )
return F_35 ( F_27 ( V_8 -> V_23 ) , F_27 ( V_8 -> V_24 ) ) ;
return - 1 ;
}
T_5 * F_36 ( const T_2 * V_21 )
{
T_5 * V_9 = NULL ;
T_6 * V_23 = NULL , * V_24 = NULL , * V_25 = NULL , * V_26 = NULL , * V_27 = NULL ;
if ( V_21 == NULL )
goto V_17;
V_9 = F_37 () ;
if ( V_9 == NULL )
goto V_17;
if ( V_21 -> V_23 != NULL || V_21 -> V_25 != NULL || V_21 -> V_24 != NULL ) {
if ( V_21 -> V_23 == NULL || V_21 -> V_25 == NULL || V_21 -> V_24 == NULL ) {
goto V_17;
}
V_23 = F_38 ( V_21 -> V_23 ) ;
V_25 = F_38 ( V_21 -> V_25 ) ;
V_24 = F_38 ( V_21 -> V_24 ) ;
if ( V_23 == NULL || V_25 == NULL || V_24 == NULL || ! F_39 ( V_9 , V_23 , V_24 , V_25 ) )
goto V_17;
V_23 = V_25 = V_24 = NULL ;
}
if ( V_21 -> V_26 != NULL ) {
V_26 = F_38 ( V_21 -> V_26 ) ;
if ( V_26 == NULL )
goto V_17;
if ( V_21 -> V_27 != NULL ) {
V_27 = F_38 ( V_21 -> V_27 ) ;
if ( V_27 == NULL )
goto V_17;
}
if ( ! F_40 ( V_9 , V_26 , V_27 ) )
goto V_17;
} else if ( V_21 -> V_27 != NULL ) {
goto V_17;
}
return V_9 ;
V_17:
F_41 ( V_23 ) ;
F_41 ( V_25 ) ;
F_41 ( V_24 ) ;
F_41 ( V_26 ) ;
F_41 ( V_27 ) ;
F_42 ( V_9 ) ;
return NULL ;
}
void F_43 ( const T_2 * V_8 ,
const T_6 * * V_23 , const T_6 * * V_24 , const T_6 * * V_25 )
{
if ( V_23 != NULL )
* V_23 = V_8 -> V_23 ;
if ( V_24 != NULL )
* V_24 = V_8 -> V_24 ;
if ( V_25 != NULL )
* V_25 = V_8 -> V_25 ;
}
int F_44 ( T_2 * V_8 , T_6 * V_23 , T_6 * V_24 , T_6 * V_25 )
{
if ( ( V_8 -> V_23 == NULL && V_23 == NULL )
|| ( V_8 -> V_24 == NULL && V_24 == NULL )
|| ( V_8 -> V_25 == NULL && V_25 == NULL ) )
return 0 ;
if ( V_23 != NULL ) {
F_41 ( V_8 -> V_23 ) ;
V_8 -> V_23 = V_23 ;
}
if ( V_24 != NULL ) {
F_41 ( V_8 -> V_24 ) ;
V_8 -> V_24 = V_24 ;
}
if ( V_25 != NULL ) {
F_41 ( V_8 -> V_25 ) ;
V_8 -> V_25 = V_25 ;
}
return 1 ;
}
void F_45 ( const T_2 * V_8 ,
const T_6 * * V_26 , const T_6 * * V_27 )
{
if ( V_26 != NULL )
* V_26 = V_8 -> V_26 ;
if ( V_27 != NULL )
* V_27 = V_8 -> V_27 ;
}
int F_46 ( T_2 * V_8 , T_6 * V_26 , T_6 * V_27 )
{
if ( V_8 -> V_26 == NULL && V_26 == NULL )
return 0 ;
if ( V_26 != NULL ) {
F_41 ( V_8 -> V_26 ) ;
V_8 -> V_26 = V_26 ;
}
if ( V_27 != NULL ) {
F_41 ( V_8 -> V_27 ) ;
V_8 -> V_27 = V_27 ;
}
return 1 ;
}
void F_47 ( T_2 * V_8 , int V_14 )
{
V_8 -> V_14 &= ~ V_14 ;
}
int F_48 ( const T_2 * V_8 , int V_14 )
{
return V_8 -> V_14 & V_14 ;
}
void F_49 ( T_2 * V_8 , int V_14 )
{
V_8 -> V_14 |= V_14 ;
}
T_3 * F_50 ( T_2 * V_8 )
{
return V_8 -> V_6 ;
}
int F_51 ( const T_2 * V_3 )
{
return F_27 ( V_3 -> V_23 ) ;
}
