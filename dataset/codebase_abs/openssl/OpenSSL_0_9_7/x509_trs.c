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
int F_10 ( int * V_16 , int V_3 )
{
if( F_3 ( V_3 ) == - 1 ) {
F_11 ( V_17 , V_18 ) ;
return 0 ;
}
* V_16 = V_3 ;
return 1 ;
}
int F_12 ( int V_5 , int V_6 , int (* F_13)( T_1 * , T_2 * , int ) ,
char * V_19 , int V_20 , void * V_21 )
{
int V_8 ;
T_1 * V_22 ;
V_6 &= ~ V_23 ;
V_6 |= V_24 ;
V_8 = F_3 ( V_5 ) ;
if( V_8 == - 1 ) {
if( ! ( V_22 = F_14 ( sizeof( T_1 ) ) ) ) {
F_11 ( V_25 , V_26 ) ;
return 0 ;
}
V_22 -> V_6 = V_23 ;
} else V_22 = F_5 ( V_8 ) ;
if( V_22 -> V_6 & V_24 ) F_15 ( V_22 -> V_19 ) ;
if( ! ( V_22 -> V_19 = F_16 ( V_19 ) ) ) {
F_11 ( V_25 , V_26 ) ;
return 0 ;
}
V_22 -> V_6 &= V_23 ;
V_22 -> V_6 |= V_6 ;
V_22 -> V_3 = V_5 ;
V_22 -> V_9 = F_13 ;
V_22 -> V_20 = V_20 ;
V_22 -> V_21 = V_21 ;
if( V_8 == - 1 ) {
if( ! V_10 && ! ( V_10 = F_17 ( F_1 ) ) ) {
F_11 ( V_25 , V_26 ) ;
return 0 ;
}
if ( ! F_18 ( V_10 , V_22 ) ) {
F_11 ( V_25 , V_26 ) ;
return 0 ;
}
}
return 1 ;
}
static void F_19 ( T_1 * V_27 )
{
if( ! V_27 ) return;
if ( V_27 -> V_6 & V_23 )
{
if ( V_27 -> V_6 & V_24 )
F_15 ( V_27 -> V_19 ) ;
F_15 ( V_27 ) ;
}
}
void F_20 ( void )
{
int V_28 ;
for( V_28 = 0 ; V_28 < V_11 ; V_28 ++ ) F_19 ( V_12 + V_28 ) ;
F_21 ( V_10 , F_19 ) ;
V_10 = NULL ;
}
int F_22 ( T_1 * V_29 )
{
return V_29 -> V_6 ;
}
char * F_23 ( T_1 * V_29 )
{
return V_29 -> V_19 ;
}
int F_24 ( T_1 * V_29 )
{
return V_29 -> V_3 ;
}
static int F_25 ( T_1 * V_3 , T_2 * V_4 , int V_6 )
{
if( V_4 -> V_30 && ( V_4 -> V_30 -> V_3 || V_4 -> V_30 -> V_31 ) )
return F_26 ( V_3 -> V_20 , V_4 , V_6 ) ;
return F_27 ( V_3 , V_4 , V_6 ) ;
}
static int F_28 ( T_1 * V_3 , T_2 * V_4 , int V_6 )
{
if( V_4 -> V_30 ) return F_26 ( V_3 -> V_20 , V_4 , V_6 ) ;
return V_32 ;
}
static int F_27 ( T_1 * V_3 , T_2 * V_4 , int V_6 )
{
F_29 ( V_4 , - 1 , 0 ) ;
if( V_4 -> V_33 & V_34 ) return V_35 ;
else return V_32 ;
}
static int F_26 ( int V_5 , T_2 * V_4 , int V_6 )
{
T_3 * V_36 ;
int V_28 ;
T_4 * V_37 ;
V_37 = V_4 -> V_30 ;
if( ! V_37 ) return V_32 ;
if( V_37 -> V_31 ) {
for( V_28 = 0 ; V_28 < F_30 ( V_37 -> V_31 ) ; V_28 ++ ) {
V_36 = F_31 ( V_37 -> V_31 , V_28 ) ;
if( F_32 ( V_36 ) == V_5 ) return V_38 ;
}
}
if( V_37 -> V_3 ) {
for( V_28 = 0 ; V_28 < F_30 ( V_37 -> V_3 ) ; V_28 ++ ) {
V_36 = F_31 ( V_37 -> V_3 , V_28 ) ;
if( F_32 ( V_36 ) == V_5 ) return V_35 ;
}
}
return V_32 ;
}
