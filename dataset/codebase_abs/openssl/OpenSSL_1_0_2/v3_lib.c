int F_1 ( T_1 * V_1 )
{
if ( ! V_2 && ! ( V_2 = F_2 ( V_3 ) ) ) {
F_3 ( V_4 , V_5 ) ;
return 0 ;
}
if ( ! F_4 ( V_2 , V_1 ) ) {
F_3 ( V_4 , V_5 ) ;
return 0 ;
}
return 1 ;
}
static int V_3 ( const T_1 * const * V_6 ,
const T_1 * const * V_7 )
{
return ( ( * V_6 ) -> V_8 - ( * V_7 ) -> V_8 ) ;
}
const T_1 * F_5 ( int V_9 )
{
T_1 V_10 ;
const T_1 * V_11 = & V_10 , * const * V_12 ;
int V_13 ;
if ( V_9 < 0 )
return NULL ;
V_10 . V_8 = V_9 ;
V_12 = F_6 ( & V_11 , V_14 , V_15 ) ;
if ( V_12 )
return * V_12 ;
if ( ! V_2 )
return NULL ;
V_13 = F_7 ( V_2 , & V_10 ) ;
if ( V_13 == - 1 )
return NULL ;
return F_8 ( V_2 , V_13 ) ;
}
const T_1 * F_9 ( T_2 * V_1 )
{
int V_9 ;
if ( ( V_9 = F_10 ( V_1 -> V_16 ) ) == V_17 )
return NULL ;
return F_5 ( V_9 ) ;
}
int F_11 ( int V_9 , void * V_18 )
{
const T_1 * V_19 = F_5 ( V_9 ) ;
if ( V_19 == NULL ) {
F_3 ( V_20 ,
V_21 ) ;
return 0 ;
}
if ( V_19 -> V_22 != NULL )
F_12 ( V_18 , F_13 ( V_19 -> V_22 ) ) ;
else if ( V_19 -> V_23 != NULL )
V_19 -> V_23 ( V_18 ) ;
else {
F_3 ( V_20 ,
V_21 ) ;
return 0 ;
}
return 1 ;
}
int F_14 ( T_1 * V_24 )
{
for (; V_24 -> V_8 != - 1 ; V_24 ++ )
if ( ! F_1 ( V_24 ) )
return 0 ;
return 1 ;
}
int F_15 ( int V_25 , int V_26 )
{
const T_1 * V_1 ;
T_1 * V_27 ;
if ( ! ( V_1 = F_5 ( V_26 ) ) ) {
F_3 ( V_28 ,
V_29 ) ;
return 0 ;
}
if ( !
( V_27 =
( T_1 * ) F_16 ( sizeof( T_1 ) ) ) ) {
F_3 ( V_28 , V_5 ) ;
return 0 ;
}
* V_27 = * V_1 ;
V_27 -> V_8 = V_25 ;
V_27 -> V_30 |= V_31 ;
return F_1 ( V_27 ) ;
}
void F_17 ( void )
{
F_18 ( V_2 , V_32 ) ;
V_2 = NULL ;
}
static void V_32 ( T_1 * V_1 )
{
if ( V_1 -> V_30 & V_31 )
F_19 ( V_1 ) ;
}
int F_20 ( void )
{
return 1 ;
}
void * F_21 ( T_2 * V_1 )
{
const T_1 * V_33 ;
const unsigned char * V_34 ;
if ( ! ( V_33 = F_9 ( V_1 ) ) )
return NULL ;
V_34 = V_1 -> V_35 -> V_36 ;
if ( V_33 -> V_22 )
return F_22 ( NULL , & V_34 , V_1 -> V_35 -> V_37 ,
F_13 ( V_33 -> V_22 ) ) ;
return V_33 -> V_38 ( NULL , & V_34 , V_1 -> V_35 -> V_37 ) ;
}
