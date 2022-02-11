unsigned int F_1 ( void )
{
return V_1 ;
}
void F_2 ( unsigned int V_2 )
{
V_1 = V_2 ;
}
static unsigned long F_3 ( const T_1 * V_3 )
{
return V_3 -> V_4 ;
}
static int F_4 ( const T_1 * V_5 , const T_1 * V_6 )
{
return V_5 -> V_4 - V_6 -> V_4 ;
}
static int F_5 ( T_2 * * V_7 , int V_8 )
{
F_6 ( T_1 ) * V_9 ;
if ( * V_7 )
return 1 ;
if ( ! V_8 )
return 0 ;
if ( ( V_9 = F_7 ( F_3 , F_4 ) ) == NULL )
return 0 ;
* V_7 = ( T_2 * ) V_9 ;
return 1 ;
}
int F_8 ( T_2 * * V_10 , T_3 * V_11 ,
T_4 * V_12 , const int * V_13 , int V_14 ,
int V_15 )
{
int V_16 = 0 , V_17 = 0 ;
T_1 V_18 , * V_19 ;
F_9 ( V_20 ) ;
if ( ! ( * V_10 ) )
V_17 = 1 ;
if ( ! F_5 ( V_10 , 1 ) )
goto V_21;
if ( V_17 )
F_10 ( V_11 ) ;
while ( V_14 -- ) {
V_18 . V_4 = * V_13 ;
V_19 = F_11 ( & ( * V_10 ) -> V_22 , & V_18 ) ;
if ( ! V_19 ) {
V_19 = F_12 ( sizeof( * V_19 ) ) ;
if ( V_19 == NULL )
goto V_21;
V_19 -> V_23 = 1 ;
V_19 -> V_4 = * V_13 ;
V_19 -> V_24 = F_13 () ;
if ( ! V_19 -> V_24 ) {
F_14 ( V_19 ) ;
goto V_21;
}
V_19 -> V_25 = NULL ;
( void ) F_15 ( & ( * V_10 ) -> V_22 , V_19 ) ;
}
( void ) F_16 ( V_19 -> V_24 , V_12 ) ;
if ( ! F_17 ( V_19 -> V_24 , V_12 ) )
goto V_21;
V_19 -> V_23 = 0 ;
if ( V_15 ) {
if ( ! F_18 ( V_12 ) ) {
F_19 ( V_26 ,
V_27 ) ;
goto V_21;
}
if ( V_19 -> V_25 )
F_20 ( V_19 -> V_25 , 0 ) ;
V_19 -> V_25 = V_12 ;
V_19 -> V_23 = 1 ;
}
V_13 ++ ;
}
V_16 = 1 ;
V_21:
F_21 ( V_20 ) ;
return V_16 ;
}
static void F_22 ( T_1 * V_28 , T_4 * V_12 )
{
int V_29 ;
while ( ( V_29 = F_23 ( V_28 -> V_24 , V_12 ) ) >= 0 ) {
( void ) F_24 ( V_28 -> V_24 , V_29 ) ;
V_28 -> V_23 = 0 ;
}
if ( V_28 -> V_25 == V_12 ) {
F_20 ( V_12 , 0 ) ;
V_28 -> V_25 = NULL ;
}
}
void F_25 ( T_2 * * V_10 , T_4 * V_12 )
{
F_9 ( V_20 ) ;
if ( F_5 ( V_10 , 0 ) )
F_26 ( & ( * V_10 ) -> V_22 , F_22 , V_12 ) ;
F_21 ( V_20 ) ;
}
static void F_27 ( T_1 * V_30 )
{
if ( ! V_30 )
return;
F_28 ( V_30 -> V_24 ) ;
if ( V_30 -> V_25 )
F_20 ( V_30 -> V_25 , 0 ) ;
F_14 ( V_30 ) ;
}
void F_29 ( T_2 * * V_10 )
{
F_9 ( V_20 ) ;
if ( * V_10 ) {
F_30 ( & ( * V_10 ) -> V_22 , F_27 ) ;
F_31 ( & ( * V_10 ) -> V_22 ) ;
* V_10 = NULL ;
}
F_21 ( V_20 ) ;
}
static void F_32 ( const T_1 * V_28 , T_5 * V_31 )
{
V_31 -> V_32 ( V_28 -> V_4 , V_28 -> V_24 , V_28 -> V_25 , V_31 -> V_33 ) ;
}
void F_33 ( T_2 * V_10 , T_6 * V_32 ,
void * V_33 )
{
T_5 V_31 ;
V_31 . V_32 = V_32 ;
V_31 . V_33 = V_33 ;
if ( V_10 )
F_34 ( & V_10 -> V_22 , F_32 , & V_31 ) ;
}
