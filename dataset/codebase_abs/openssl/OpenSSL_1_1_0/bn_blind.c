T_1 * F_1 ( const T_2 * V_1 , const T_2 * V_2 , T_2 * V_3 )
{
T_1 * V_4 = NULL ;
F_2 ( V_3 ) ;
if ( ( V_4 = F_3 ( sizeof( * V_4 ) ) ) == NULL ) {
F_4 ( V_5 , V_6 ) ;
return NULL ;
}
V_4 -> V_7 = F_5 () ;
if ( V_4 -> V_7 == NULL ) {
F_4 ( V_5 , V_6 ) ;
F_6 ( V_4 ) ;
return NULL ;
}
F_7 ( V_4 ) ;
if ( V_1 != NULL ) {
if ( ( V_4 -> V_1 = F_8 ( V_1 ) ) == NULL )
goto V_8;
}
if ( V_2 != NULL ) {
if ( ( V_4 -> V_2 = F_8 ( V_2 ) ) == NULL )
goto V_8;
}
if ( ( V_4 -> V_3 = F_8 ( V_3 ) ) == NULL )
goto V_8;
if ( F_9 ( V_3 , V_9 ) != 0 )
F_10 ( V_4 -> V_3 , V_9 ) ;
V_4 -> V_10 = - 1 ;
return V_4 ;
V_8:
F_11 ( V_4 ) ;
return NULL ;
}
void F_11 ( T_1 * V_11 )
{
if ( V_11 == NULL )
return;
F_12 ( V_11 -> V_1 ) ;
F_12 ( V_11 -> V_2 ) ;
F_12 ( V_11 -> V_12 ) ;
F_12 ( V_11 -> V_3 ) ;
F_13 ( V_11 -> V_7 ) ;
F_6 ( V_11 ) ;
}
int F_14 ( T_1 * V_13 , T_3 * V_14 )
{
int V_4 = 0 ;
if ( ( V_13 -> V_1 == NULL ) || ( V_13 -> V_2 == NULL ) ) {
F_4 ( V_15 , V_16 ) ;
goto V_8;
}
if ( V_13 -> V_10 == - 1 )
V_13 -> V_10 = 0 ;
if ( ++ V_13 -> V_10 == V_17 && V_13 -> V_12 != NULL &&
! ( V_13 -> V_18 & V_19 ) ) {
if ( ! F_15 ( V_13 , NULL , NULL , V_14 , NULL , NULL ) )
goto V_8;
} else if ( ! ( V_13 -> V_18 & V_20 ) ) {
if ( ! F_16 ( V_13 -> V_1 , V_13 -> V_1 , V_13 -> V_1 , V_13 -> V_3 , V_14 ) )
goto V_8;
if ( ! F_16 ( V_13 -> V_2 , V_13 -> V_2 , V_13 -> V_2 , V_13 -> V_3 , V_14 ) )
goto V_8;
}
V_4 = 1 ;
V_8:
if ( V_13 -> V_10 == V_17 )
V_13 -> V_10 = 0 ;
return ( V_4 ) ;
}
int F_17 ( T_2 * V_21 , T_1 * V_13 , T_3 * V_14 )
{
return F_18 ( V_21 , NULL , V_13 , V_14 ) ;
}
int F_18 ( T_2 * V_21 , T_2 * V_11 , T_1 * V_13 , T_3 * V_14 )
{
int V_4 = 1 ;
F_2 ( V_21 ) ;
if ( ( V_13 -> V_1 == NULL ) || ( V_13 -> V_2 == NULL ) ) {
F_4 ( V_22 , V_16 ) ;
return ( 0 ) ;
}
if ( V_13 -> V_10 == - 1 )
V_13 -> V_10 = 0 ;
else if ( ! F_14 ( V_13 , V_14 ) )
return ( 0 ) ;
if ( V_11 != NULL ) {
if ( ! F_19 ( V_11 , V_13 -> V_2 ) )
V_4 = 0 ;
}
if ( ! F_16 ( V_21 , V_21 , V_13 -> V_1 , V_13 -> V_3 , V_14 ) )
V_4 = 0 ;
return V_4 ;
}
int F_20 ( T_2 * V_21 , T_1 * V_13 , T_3 * V_14 )
{
return F_21 ( V_21 , NULL , V_13 , V_14 ) ;
}
int F_21 ( T_2 * V_21 , const T_2 * V_11 , T_1 * V_13 ,
T_3 * V_14 )
{
int V_4 ;
F_2 ( V_21 ) ;
if ( V_11 != NULL )
V_4 = F_16 ( V_21 , V_21 , V_11 , V_13 -> V_3 , V_14 ) ;
else {
if ( V_13 -> V_2 == NULL ) {
F_4 ( V_23 , V_16 ) ;
return ( 0 ) ;
}
V_4 = F_16 ( V_21 , V_21 , V_13 -> V_2 , V_13 -> V_3 , V_14 ) ;
}
F_2 ( V_21 ) ;
return ( V_4 ) ;
}
int F_22 ( T_1 * V_13 )
{
return F_23 ( F_24 () , V_13 -> V_24 ) ;
}
void F_7 ( T_1 * V_13 )
{
V_13 -> V_24 = F_24 () ;
}
int F_25 ( T_1 * V_13 )
{
return F_26 ( V_13 -> V_7 ) ;
}
int F_27 ( T_1 * V_13 )
{
return F_28 ( V_13 -> V_7 ) ;
}
unsigned long F_29 ( const T_1 * V_13 )
{
return V_13 -> V_18 ;
}
void F_30 ( T_1 * V_13 , unsigned long V_18 )
{
V_13 -> V_18 = V_18 ;
}
T_1 * F_15 ( T_1 * V_13 ,
const T_2 * V_12 , T_2 * V_25 , T_3 * V_14 ,
int (* F_31) ( T_2 * V_11 ,
const T_2 * V_26 ,
const T_2 * V_27 ,
const T_2 * V_25 ,
T_3 * V_14 ,
T_4 * V_28 ) ,
T_4 * V_28 )
{
int V_29 = 32 ;
T_1 * V_4 = NULL ;
if ( V_13 == NULL )
V_4 = F_1 ( NULL , NULL , V_25 ) ;
else
V_4 = V_13 ;
if ( V_4 == NULL )
goto V_8;
if ( V_4 -> V_1 == NULL && ( V_4 -> V_1 = F_32 () ) == NULL )
goto V_8;
if ( V_4 -> V_2 == NULL && ( V_4 -> V_2 = F_32 () ) == NULL )
goto V_8;
if ( V_12 != NULL ) {
F_12 ( V_4 -> V_12 ) ;
V_4 -> V_12 = F_8 ( V_12 ) ;
}
if ( V_4 -> V_12 == NULL )
goto V_8;
if ( F_31 != NULL )
V_4 -> F_31 = F_31 ;
if ( V_28 != NULL )
V_4 -> V_28 = V_28 ;
do {
int V_30 ;
if ( ! F_33 ( V_4 -> V_1 , V_4 -> V_3 ) )
goto V_8;
if ( ! F_34 ( V_4 -> V_2 , V_4 -> V_1 , V_4 -> V_3 , V_14 , & V_30 ) ) {
if ( V_30 ) {
if ( V_29 -- == 0 ) {
F_4 ( V_31 ,
V_32 ) ;
goto V_8;
}
} else
goto V_8;
} else
break;
} while ( 1 );
if ( V_4 -> F_31 != NULL && V_4 -> V_28 != NULL ) {
if ( ! V_4 -> F_31
( V_4 -> V_1 , V_4 -> V_1 , V_4 -> V_12 , V_4 -> V_3 , V_14 , V_4 -> V_28 ) )
goto V_8;
} else {
if ( ! F_35 ( V_4 -> V_1 , V_4 -> V_1 , V_4 -> V_12 , V_4 -> V_3 , V_14 ) )
goto V_8;
}
return V_4 ;
V_8:
if ( V_13 == NULL ) {
F_11 ( V_4 ) ;
V_4 = NULL ;
}
return V_4 ;
}
