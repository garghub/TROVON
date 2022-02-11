static int F_1 ( const T_1 * const * V_1 , const T_1 * const * V_2 )
{
return ( * V_1 ) -> V_3 - ( * V_2 ) -> V_3 ;
}
int F_2 ( T_2 * V_4 , int V_5 , int V_6 )
{
T_1 * V_7 ;
int V_8 ;
if ( V_5 == - 1 )
return 1 ;
if ( V_5 == 0 ) {
int V_9 ;
V_9 = F_3 ( V_10 , V_4 , 0 ) ;
if ( V_9 != V_11 )
return V_9 ;
return F_4 ( NULL , V_4 , 0 ) ;
}
V_8 = F_5 ( V_5 ) ;
if ( V_8 == - 1 )
return F_6 ( V_5 , V_4 , V_6 ) ;
V_7 = F_7 ( V_8 ) ;
return V_7 -> V_12 ( V_7 , V_4 , V_6 ) ;
}
int F_8 ( void )
{
if ( ! V_13 )
return V_14 ;
return F_9 ( V_13 ) + V_14 ;
}
T_1 * F_7 ( int V_8 )
{
if ( V_8 < 0 )
return NULL ;
if ( V_8 < ( int ) V_14 )
return V_15 + V_8 ;
return F_10 ( V_13 , V_8 - V_14 ) ;
}
int F_5 ( int V_5 )
{
T_1 V_16 ;
int V_8 ;
if ( ( V_5 >= V_17 ) && ( V_5 <= V_18 ) )
return V_5 - V_17 ;
V_16 . V_3 = V_5 ;
if ( ! V_13 )
return - 1 ;
V_8 = F_11 ( V_13 , & V_16 ) ;
if ( V_8 == - 1 )
return - 1 ;
return V_8 + V_14 ;
}
int F_12 ( int * V_19 , int V_3 )
{
if ( F_5 ( V_3 ) == - 1 ) {
F_13 ( V_20 , V_21 ) ;
return 0 ;
}
* V_19 = V_3 ;
return 1 ;
}
int F_14 ( int V_5 , int V_6 , int (* F_15) ( T_1 * , T_2 * , int ) ,
char * V_22 , int V_23 , void * V_24 )
{
int V_8 ;
T_1 * V_25 ;
V_6 &= ~ V_26 ;
V_6 |= V_27 ;
V_8 = F_5 ( V_5 ) ;
if ( V_8 == - 1 ) {
if ( ! ( V_25 = F_16 ( sizeof( T_1 ) ) ) ) {
F_13 ( V_28 , V_29 ) ;
return 0 ;
}
V_25 -> V_6 = V_26 ;
} else
V_25 = F_7 ( V_8 ) ;
if ( V_25 -> V_6 & V_27 )
F_17 ( V_25 -> V_22 ) ;
if ( ! ( V_25 -> V_22 = F_18 ( V_22 ) ) ) {
F_13 ( V_28 , V_29 ) ;
return 0 ;
}
V_25 -> V_6 &= V_26 ;
V_25 -> V_6 |= V_6 ;
V_25 -> V_3 = V_5 ;
V_25 -> V_12 = F_15 ;
V_25 -> V_23 = V_23 ;
V_25 -> V_24 = V_24 ;
if ( V_8 == - 1 ) {
if ( ! V_13 && ! ( V_13 = F_19 ( F_1 ) ) ) {
F_13 ( V_28 , V_29 ) ;
return 0 ;
}
if ( ! F_20 ( V_13 , V_25 ) ) {
F_13 ( V_28 , V_29 ) ;
return 0 ;
}
}
return 1 ;
}
static void F_21 ( T_1 * V_30 )
{
if ( ! V_30 )
return;
if ( V_30 -> V_6 & V_26 ) {
if ( V_30 -> V_6 & V_27 )
F_17 ( V_30 -> V_22 ) ;
F_17 ( V_30 ) ;
}
}
void F_22 ( void )
{
unsigned int V_31 ;
for ( V_31 = 0 ; V_31 < V_14 ; V_31 ++ )
F_21 ( V_15 + V_31 ) ;
F_23 ( V_13 , F_21 ) ;
V_13 = NULL ;
}
int F_24 ( T_1 * V_32 )
{
return V_32 -> V_6 ;
}
char * F_25 ( T_1 * V_32 )
{
return V_32 -> V_22 ;
}
int F_26 ( T_1 * V_32 )
{
return V_32 -> V_3 ;
}
static int F_27 ( T_1 * V_3 , T_2 * V_4 , int V_6 )
{
if ( V_4 -> V_33 && ( V_4 -> V_33 -> V_3 || V_4 -> V_33 -> V_34 ) )
return F_3 ( V_3 -> V_23 , V_4 , V_6 ) ;
return F_4 ( V_3 , V_4 , V_6 ) ;
}
static int F_28 ( T_1 * V_3 , T_2 * V_4 , int V_6 )
{
if ( V_4 -> V_33 )
return F_3 ( V_3 -> V_23 , V_4 , V_6 ) ;
return V_11 ;
}
static int F_4 ( T_1 * V_3 , T_2 * V_4 , int V_6 )
{
F_29 ( V_4 , - 1 , 0 ) ;
if ( V_4 -> V_35 & V_36 )
return V_37 ;
else
return V_11 ;
}
static int F_3 ( int V_5 , T_2 * V_4 , int V_6 )
{
T_3 * V_38 ;
int V_31 ;
T_4 * V_39 ;
V_39 = V_4 -> V_33 ;
if ( ! V_39 )
return V_11 ;
if ( V_39 -> V_34 ) {
for ( V_31 = 0 ; V_31 < F_30 ( V_39 -> V_34 ) ; V_31 ++ ) {
V_38 = F_31 ( V_39 -> V_34 , V_31 ) ;
if ( F_32 ( V_38 ) == V_5 )
return V_40 ;
}
}
if ( V_39 -> V_3 ) {
for ( V_31 = 0 ; V_31 < F_30 ( V_39 -> V_3 ) ; V_31 ++ ) {
V_38 = F_31 ( V_39 -> V_3 , V_31 ) ;
if ( F_32 ( V_38 ) == V_5 )
return V_37 ;
}
}
return V_11 ;
}
