static T_1 * F_1 ( void )
{
T_1 * V_1 = NULL ;
V_1 = F_2 ( sizeof ( T_1 ) ) ;
if ( V_1 == NULL ) {
F_3 ( V_2 , V_3 ) ;
goto V_4;
}
F_4 ( & V_1 -> V_5 ) ;
V_1 -> V_6 = NULL ;
V_1 -> V_7 = 0 ;
if ( ! F_5 ( & V_8 , V_1 ) )
goto V_4;
return V_1 ;
V_4:
F_6 ( V_1 ) ;
return NULL ;
}
T_1 * F_7 ( void )
{
if ( ! F_8 ( V_9 , NULL ) )
return NULL ;
return ( T_1 * ) F_9 ( & V_8 ) ;
}
static int F_10 ( void )
{
T_1 * V_10 ;
V_10 = F_7 () ;
if ( ! F_5 ( & V_8 , NULL ) )
return 0 ;
F_6 ( V_10 ) ;
return 1 ;
}
static T_2 * F_11 ( void )
{
T_2 * V_11 = NULL ;
V_11 = F_12 ( sizeof ( T_2 ) ) ;
if ( V_11 == NULL ) {
F_3 ( V_12 , V_3 ) ;
return NULL ;
}
V_11 -> V_13 = V_14 ;
return V_11 ;
}
static void F_13 ( T_2 * V_11 )
{
if ( V_11 != NULL ) {
F_6 ( V_11 -> V_15 ) ;
F_14 ( & V_11 -> V_16 ) ;
F_6 ( V_11 ) ;
}
}
static T_2 * F_15 ( void ) {
T_2 * V_11 ;
T_3 * V_17 ;
V_17 = ( T_3 * ) F_9 ( & V_18 ) ;
if ( V_17 == NULL ) {
if ( F_16 ( 0 , 0 ) == 0 )
return NULL ;
V_17 = ( T_3 * ) F_9 ( & V_18 ) ;
}
V_11 = F_17 ( V_17 -> V_19 ) ;
if ( V_11 == NULL ) {
if ( ( V_17 -> V_20 != 0 ) && ( V_17 -> V_21 >= V_17 -> V_20 ) )
return NULL ;
V_11 = F_11 () ;
if ( V_11 != NULL ) {
if ( ! F_18 ( & V_11 -> V_16 ) ) {
F_13 ( V_11 ) ;
return NULL ;
}
V_17 -> V_21 ++ ;
}
}
return V_11 ;
}
static void F_19 ( T_2 * V_11 ) {
T_3 * V_17 ;
V_17 = ( T_3 * ) F_9 ( & V_18 ) ;
F_6 ( V_11 -> V_15 ) ;
V_11 -> V_15 = NULL ;
F_20 ( V_17 -> V_19 , V_11 ) ;
}
void F_21 ( void )
{
T_2 * V_11 ;
T_1 * V_10 = F_7 () ;
while ( 1 ) {
V_11 = V_10 -> V_6 ;
V_11 -> V_22 = V_11 -> V_23 ( V_11 -> V_15 ) ;
V_11 -> V_13 = V_24 ;
if ( ! F_22 ( & V_11 -> V_16 ,
& V_10 -> V_5 , 1 ) ) {
F_3 ( V_25 , V_26 ) ;
}
}
}
int F_23 ( T_2 * * V_11 , T_4 * V_27 , int * V_22 ,
int (* V_23)( void * ) , void * args , T_5 V_28 )
{
T_1 * V_10 = F_7 () ;
if ( V_10 == NULL )
V_10 = F_1 () ;
if ( V_10 == NULL ) {
return V_29 ;
}
if ( * V_11 ) {
V_10 -> V_6 = * V_11 ;
}
for (; ; ) {
if ( V_10 -> V_6 != NULL ) {
if ( V_10 -> V_6 -> V_13 == V_24 ) {
* V_22 = V_10 -> V_6 -> V_22 ;
V_10 -> V_6 -> V_30 = NULL ;
F_19 ( V_10 -> V_6 ) ;
V_10 -> V_6 = NULL ;
* V_11 = NULL ;
return V_31 ;
}
if ( V_10 -> V_6 -> V_13 == V_32 ) {
* V_11 = V_10 -> V_6 ;
V_10 -> V_6 -> V_13 = V_33 ;
V_10 -> V_6 = NULL ;
return V_34 ;
}
if ( V_10 -> V_6 -> V_13 == V_33 ) {
V_10 -> V_6 = * V_11 ;
if ( ! F_22 ( & V_10 -> V_5 ,
& V_10 -> V_6 -> V_16 , 1 ) ) {
F_3 ( V_35 ,
V_26 ) ;
goto V_4;
}
continue;
}
F_3 ( V_35 , V_36 ) ;
F_19 ( V_10 -> V_6 ) ;
V_10 -> V_6 = NULL ;
* V_11 = NULL ;
return V_29 ;
}
if ( ( V_10 -> V_6 = F_15 () ) == NULL ) {
return V_37 ;
}
if ( args != NULL ) {
V_10 -> V_6 -> V_15 = F_2 ( V_28 ) ;
if ( V_10 -> V_6 -> V_15 == NULL ) {
F_3 ( V_35 , V_3 ) ;
F_19 ( V_10 -> V_6 ) ;
V_10 -> V_6 = NULL ;
return V_29 ;
}
memcpy ( V_10 -> V_6 -> V_15 , args , V_28 ) ;
} else {
V_10 -> V_6 -> V_15 = NULL ;
}
V_10 -> V_6 -> V_23 = V_23 ;
V_10 -> V_6 -> V_30 = V_27 ;
if ( ! F_22 ( & V_10 -> V_5 ,
& V_10 -> V_6 -> V_16 , 1 ) ) {
F_3 ( V_35 , V_26 ) ;
goto V_4;
}
}
V_4:
F_19 ( V_10 -> V_6 ) ;
V_10 -> V_6 = NULL ;
* V_11 = NULL ;
return V_29 ;
}
int F_24 ( void )
{
T_2 * V_11 ;
T_1 * V_10 = F_7 () ;
if ( V_10 == NULL
|| V_10 -> V_6 == NULL
|| V_10 -> V_7 ) {
return 1 ;
}
V_11 = V_10 -> V_6 ;
V_11 -> V_13 = V_32 ;
if ( ! F_22 ( & V_11 -> V_16 ,
& V_10 -> V_5 , 1 ) ) {
F_3 ( V_38 , V_26 ) ;
return 0 ;
}
F_25 ( V_11 -> V_30 ) ;
return 1 ;
}
static void F_26 ( T_3 * V_17 )
{
T_2 * V_11 ;
if ( ! V_17 || ! V_17 -> V_19 )
return;
do {
V_11 = F_17 ( V_17 -> V_19 ) ;
F_13 ( V_11 ) ;
} while ( V_11 );
}
int F_27 ( void )
{
if ( ! F_28 ( & V_8 , NULL ) )
return 0 ;
if ( ! F_28 ( & V_18 , NULL ) ) {
F_29 ( & V_8 ) ;
return 0 ;
}
return 1 ;
}
void F_30 ( void )
{
F_29 ( & V_8 ) ;
F_29 ( & V_18 ) ;
}
int F_16 ( T_5 V_20 , T_5 V_39 )
{
T_3 * V_17 ;
T_5 V_21 = 0 ;
if ( V_39 > V_20 ) {
F_3 ( V_40 , V_41 ) ;
return 0 ;
}
if ( ! F_8 ( V_9 , NULL ) ) {
return 0 ;
}
if ( ! F_31 ( V_42 ) ) {
return 0 ;
}
V_17 = F_12 ( sizeof *V_17 ) ;
if ( V_17 == NULL ) {
F_3 ( V_40 , V_3 ) ;
return 0 ;
}
V_17 -> V_19 = F_32 () ;
if ( V_17 -> V_19 == NULL ) {
F_3 ( V_40 , V_3 ) ;
F_6 ( V_17 ) ;
return 0 ;
}
V_17 -> V_20 = V_20 ;
while ( V_39 -- ) {
T_2 * V_11 ;
V_11 = F_11 () ;
if ( V_11 == NULL || ! F_18 ( & V_11 -> V_16 ) ) {
F_13 ( V_11 ) ;
break;
}
V_11 -> V_15 = NULL ;
F_20 ( V_17 -> V_19 , V_11 ) ;
V_21 ++ ;
}
V_17 -> V_21 = V_21 ;
if ( ! F_5 ( & V_18 , V_17 ) ) {
F_3 ( V_40 , V_43 ) ;
goto V_4;
}
return 1 ;
V_4:
F_33 ( V_17 ) ;
return 0 ;
}
static void F_33 ( T_3 * V_17 )
{
if ( V_17 == NULL )
return;
F_26 ( V_17 ) ;
F_34 ( V_17 -> V_19 ) ;
F_6 ( V_17 ) ;
F_5 ( & V_18 , NULL ) ;
F_35 () ;
F_10 () ;
}
void F_36 ( void )
{
F_33 ( ( T_3 * ) F_9 ( & V_18 ) ) ;
}
T_2 * F_37 ( void )
{
T_1 * V_10 ;
V_10 = F_7 () ;
if ( V_10 == NULL )
return NULL ;
return V_10 -> V_6 ;
}
T_4 * F_38 ( T_2 * V_11 )
{
return V_11 -> V_30 ;
}
void F_39 ( void )
{
T_1 * V_10 = F_7 () ;
if ( V_10 == NULL || V_10 -> V_6 == NULL ) {
return;
}
V_10 -> V_7 ++ ;
}
void F_40 ( void )
{
T_1 * V_10 = F_7 () ;
if ( V_10 == NULL || V_10 -> V_6 == NULL ) {
return;
}
if ( V_10 -> V_7 > 0 )
V_10 -> V_7 -- ;
}
