int F_1 ( T_1 * V_1 )
{
if( ! V_2 && ! ( V_2 = F_2 ( V_3 ) ) ) {
F_3 ( V_4 , V_5 ) ;
return 0 ;
}
if( ! F_4 ( V_2 , V_1 ) ) {
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
if( V_9 < 0 ) return NULL ;
V_10 . V_8 = V_9 ;
V_12 = F_6 ( & V_11 , V_14 , V_15 ) ;
if( V_12 ) return * V_12 ;
if( ! V_2 ) return NULL ;
V_13 = F_7 ( V_2 , & V_10 ) ;
if( V_13 == - 1 ) return NULL ;
return F_8 ( V_2 , V_13 ) ;
}
const T_1 * F_9 ( T_2 * V_1 )
{
int V_9 ;
if( ( V_9 = F_10 ( V_1 -> V_16 ) ) == V_17 ) return NULL ;
return F_5 ( V_9 ) ;
}
int F_11 ( T_1 * V_18 )
{
for(; V_18 -> V_8 != - 1 ; V_18 ++ )
if( ! F_1 ( V_18 ) ) return 0 ;
return 1 ;
}
int F_12 ( int V_19 , int V_20 )
{
const T_1 * V_1 ;
T_1 * V_21 ;
if( ! ( V_1 = F_5 ( V_20 ) ) ) {
F_3 ( V_22 , V_23 ) ;
return 0 ;
}
if( ! ( V_21 = ( T_1 * ) F_13 ( sizeof( T_1 ) ) ) ) {
F_3 ( V_22 , V_5 ) ;
return 0 ;
}
* V_21 = * V_1 ;
V_21 -> V_8 = V_19 ;
V_21 -> V_24 |= V_25 ;
return F_1 ( V_21 ) ;
}
void F_14 ( void )
{
F_15 ( V_2 , V_26 ) ;
V_2 = NULL ;
}
static void V_26 ( T_1 * V_1 )
{
if( V_1 -> V_24 & V_25 ) F_16 ( V_1 ) ;
}
int F_17 ( void )
{
return 1 ;
}
void * F_18 ( T_2 * V_1 )
{
const T_1 * V_27 ;
const unsigned char * V_28 ;
if( ! ( V_27 = F_9 ( V_1 ) ) ) return NULL ;
V_28 = V_1 -> V_29 -> V_30 ;
if( V_27 -> V_31 ) return F_19 ( NULL , & V_28 , V_1 -> V_29 -> V_32 , F_20 ( V_27 -> V_31 ) ) ;
return V_27 -> V_33 ( NULL , & V_28 , V_1 -> V_29 -> V_32 ) ;
}
