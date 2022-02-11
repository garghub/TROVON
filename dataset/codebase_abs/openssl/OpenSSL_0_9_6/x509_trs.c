static int F_1 ( const T_1 * const * V_1 ,
const T_1 * const * V_2 )
{
return ( * V_1 ) -> V_3 - ( * V_2 ) -> V_3 ;
}
int F_2 ( T_2 * V_4 , int V_5 , int V_6 )
{
T_1 * V_7 ;
int V_8 ;
if( V_5 == - 1 ) return 1 ;
V_8 = F_3 ( V_5 ) ;
if( V_8 == - 1 ) return F_4 ( V_5 , V_4 , V_6 ) ;
V_7 = F_5 ( V_8 ) ;
return V_7 -> V_9 ( V_7 , V_4 , V_6 ) ;
}
int F_6 ( void )
{
if( ! V_10 ) return V_11 ;
return F_7 ( V_10 ) + V_11 ;
}
T_1 * F_5 ( int V_8 )
{
if( V_8 < 0 ) return NULL ;
if( V_8 < V_11 ) return V_12 + V_8 ;
return F_8 ( V_10 , V_8 - V_11 ) ;
}
int F_3 ( int V_5 )
{
T_1 V_13 ;
int V_8 ;
if( ( V_5 >= V_14 ) && ( V_5 <= V_15 ) )
return V_5 - V_14 ;
V_13 . V_3 = V_5 ;
if( ! V_10 ) return - 1 ;
V_8 = F_9 ( V_10 , & V_13 ) ;
if( V_8 == - 1 ) return - 1 ;
return V_8 + V_11 ;
}
int F_10 ( int V_5 , int V_6 , int (* F_11)( T_1 * , T_2 * , int ) ,
char * V_16 , int V_17 , void * V_18 )
{
int V_8 ;
T_1 * V_19 ;
V_6 &= ~ V_20 ;
V_6 |= V_21 ;
V_8 = F_3 ( V_5 ) ;
if( V_8 == - 1 ) {
if( ! ( V_19 = F_12 ( sizeof( T_1 ) ) ) ) {
F_13 ( V_22 , V_23 ) ;
return 0 ;
}
V_19 -> V_6 = V_20 ;
} else V_19 = F_5 ( V_8 ) ;
if( V_19 -> V_6 & V_21 ) F_14 ( V_19 -> V_16 ) ;
if( ! ( V_19 -> V_16 = F_15 ( V_16 ) ) ) {
F_13 ( V_22 , V_23 ) ;
return 0 ;
}
V_19 -> V_6 &= V_20 ;
V_19 -> V_6 |= V_6 ;
V_19 -> V_3 = V_5 ;
V_19 -> V_9 = F_11 ;
V_19 -> V_17 = V_17 ;
V_19 -> V_18 = V_18 ;
if( V_8 == - 1 ) {
if( ! V_10 && ! ( V_10 = F_16 ( F_1 ) ) ) {
F_13 ( V_22 , V_23 ) ;
return 0 ;
}
if ( ! F_17 ( V_10 , V_19 ) ) {
F_13 ( V_22 , V_23 ) ;
return 0 ;
}
}
return 1 ;
}
static void F_18 ( T_1 * V_24 )
{
if( ! V_24 ) return;
if ( V_24 -> V_6 & V_20 )
{
if ( V_24 -> V_6 & V_21 )
F_14 ( V_24 -> V_16 ) ;
F_14 ( V_24 ) ;
}
}
void F_19 ( void )
{
int V_25 ;
for( V_25 = 0 ; V_25 < V_11 ; V_25 ++ ) F_18 ( V_12 + V_25 ) ;
F_20 ( V_10 , F_18 ) ;
V_10 = NULL ;
}
int F_21 ( T_1 * V_26 )
{
return V_26 -> V_6 ;
}
char * F_22 ( T_1 * V_26 )
{
return V_26 -> V_16 ;
}
int F_23 ( T_1 * V_26 )
{
return V_26 -> V_3 ;
}
static int F_24 ( T_1 * V_3 , T_2 * V_4 , int V_6 )
{
if( V_4 -> V_27 ) return F_25 ( V_3 -> V_17 , V_4 , V_6 ) ;
return F_26 ( V_3 , V_4 , V_6 ) ;
}
static int F_26 ( T_1 * V_3 , T_2 * V_4 , int V_6 )
{
F_27 ( V_4 , - 1 , 0 ) ;
if( V_4 -> V_28 & V_29 ) return V_30 ;
else return V_31 ;
}
static int F_25 ( int V_5 , T_2 * V_4 , int V_6 )
{
T_3 * V_32 ;
int V_25 ;
T_4 * V_33 ;
V_33 = V_4 -> V_27 ;
if( ! V_33 ) return V_31 ;
if( V_33 -> V_34 ) {
for( V_25 = 0 ; V_25 < F_28 ( V_33 -> V_34 ) ; V_25 ++ ) {
V_32 = F_29 ( V_33 -> V_34 , V_25 ) ;
if( F_30 ( V_32 ) == V_5 ) return V_35 ;
}
}
if( V_33 -> V_3 ) {
for( V_25 = 0 ; V_25 < F_28 ( V_33 -> V_3 ) ; V_25 ++ ) {
V_32 = F_29 ( V_33 -> V_3 , V_25 ) ;
if( F_30 ( V_32 ) == V_5 ) return V_30 ;
}
}
return V_31 ;
}
