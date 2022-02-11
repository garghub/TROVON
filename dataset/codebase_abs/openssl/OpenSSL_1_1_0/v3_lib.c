int F_1 ( T_1 * V_1 )
{
if ( V_2 == NULL
&& ( V_2 = F_2 ( V_3 ) ) == NULL ) {
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
if ( ( V_9 = F_10 ( F_11 ( V_1 ) ) ) == V_16 )
return NULL ;
return F_5 ( V_9 ) ;
}
int F_12 ( T_1 * V_17 )
{
for (; V_17 -> V_8 != - 1 ; V_17 ++ )
if ( ! F_1 ( V_17 ) )
return 0 ;
return 1 ;
}
int F_13 ( int V_18 , int V_19 )
{
const T_1 * V_1 ;
T_1 * V_20 ;
if ( ( V_1 = F_5 ( V_19 ) ) == NULL ) {
F_3 ( V_21 , V_22 ) ;
return 0 ;
}
if ( ( V_20 = F_14 ( sizeof( * V_20 ) ) ) == NULL ) {
F_3 ( V_21 , V_5 ) ;
return 0 ;
}
* V_20 = * V_1 ;
V_20 -> V_8 = V_18 ;
V_20 -> V_23 |= V_24 ;
return F_1 ( V_20 ) ;
}
void F_15 ( void )
{
F_16 ( V_2 , V_25 ) ;
V_2 = NULL ;
}
static void V_25 ( T_1 * V_1 )
{
if ( V_1 -> V_23 & V_24 )
F_17 ( V_1 ) ;
}
int F_18 ( void )
{
return 1 ;
}
void * F_19 ( T_2 * V_1 )
{
const T_1 * V_26 ;
const unsigned char * V_27 ;
T_3 * V_28 ;
int V_29 ;
if ( ( V_26 = F_9 ( V_1 ) ) == NULL )
return NULL ;
V_28 = F_20 ( V_1 ) ;
V_27 = F_21 ( V_28 ) ;
V_29 = F_22 ( V_28 ) ;
if ( V_26 -> V_30 )
return F_23 ( NULL , & V_27 , V_29 , F_24 ( V_26 -> V_30 ) ) ;
return V_26 -> V_31 ( NULL , & V_27 , V_29 ) ;
}
