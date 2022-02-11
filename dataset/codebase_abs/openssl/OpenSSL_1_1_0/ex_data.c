static T_1 * F_1 ( int V_1 )
{
T_1 * V_2 ;
if ( V_1 < 0 || V_1 >= V_3 ) {
F_2 ( V_4 , V_5 ) ;
return NULL ;
}
if ( ! F_3 ( & V_6 , V_7 ) ) {
F_2 ( V_4 , V_8 ) ;
return NULL ;
}
if ( V_9 == NULL ) {
return NULL ;
}
V_2 = & V_10 [ V_1 ] ;
F_4 ( V_9 ) ;
return V_2 ;
}
static void F_5 ( T_2 * V_11 )
{
F_6 ( V_11 ) ;
}
void F_7 ( void )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_3 ; ++ V_12 ) {
T_1 * V_2 = & V_10 [ V_12 ] ;
F_8 ( V_2 -> V_13 , F_5 ) ;
V_2 -> V_13 = NULL ;
}
F_9 ( V_9 ) ;
V_9 = NULL ;
}
static void F_10 ( void * V_14 , void * V_15 , T_3 * V_16 , int V_17 ,
long V_18 , void * V_19 )
{
}
static void F_11 ( void * V_14 , void * V_15 , T_3 * V_16 , int V_17 ,
long V_18 , void * V_19 )
{
}
static int F_12 ( T_3 * V_20 , const T_3 * V_21 ,
void * V_22 , int V_17 ,
long V_18 , void * V_19 )
{
return 0 ;
}
int F_13 ( int V_1 , int V_17 )
{
T_1 * V_2 = F_1 ( V_1 ) ;
T_2 * V_23 ;
int V_24 = 0 ;
if ( V_2 == NULL )
return 0 ;
if ( V_17 < 0 || V_17 >= F_14 ( V_2 -> V_13 ) )
goto V_25;
V_23 = F_15 ( V_2 -> V_13 , V_17 ) ;
if ( V_23 == NULL )
goto V_25;
V_23 -> V_26 = F_10 ;
V_23 -> V_27 = F_12 ;
V_23 -> V_28 = F_11 ;
V_24 = 1 ;
V_25:
F_16 ( V_9 ) ;
return V_24 ;
}
int F_17 ( int V_1 , long V_18 , void * V_19 ,
T_4 * V_26 , T_5 * V_27 ,
T_6 * V_28 )
{
int V_24 = - 1 ;
T_2 * V_23 ;
T_1 * V_2 = F_1 ( V_1 ) ;
if ( V_2 == NULL )
return - 1 ;
if ( V_2 -> V_13 == NULL ) {
V_2 -> V_13 = F_18 () ;
if ( V_2 -> V_13 == NULL
|| ! F_19 ( V_2 -> V_13 , NULL ) ) {
F_2 ( V_29 , V_8 ) ;
goto V_25;
}
}
V_23 = ( T_2 * ) F_20 ( sizeof( * V_23 ) ) ;
if ( V_23 == NULL ) {
F_2 ( V_29 , V_8 ) ;
goto V_25;
}
V_23 -> V_18 = V_18 ;
V_23 -> V_19 = V_19 ;
V_23 -> V_26 = V_26 ;
V_23 -> V_27 = V_27 ;
V_23 -> V_28 = V_28 ;
if ( ! F_19 ( V_2 -> V_13 , NULL ) ) {
F_2 ( V_29 , V_8 ) ;
F_6 ( V_23 ) ;
goto V_25;
}
V_24 = F_14 ( V_2 -> V_13 ) - 1 ;
( void ) F_21 ( V_2 -> V_13 , V_24 , V_23 ) ;
V_25:
F_16 ( V_9 ) ;
return V_24 ;
}
int F_22 ( int V_1 , void * V_30 , T_3 * V_16 )
{
int V_31 , V_12 ;
void * V_15 ;
T_2 * * V_32 = NULL ;
T_2 * V_33 [ 10 ] ;
T_1 * V_2 = F_1 ( V_1 ) ;
if ( V_2 == NULL )
return 0 ;
V_16 -> V_34 = NULL ;
V_31 = F_14 ( V_2 -> V_13 ) ;
if ( V_31 > 0 ) {
if ( V_31 < ( int ) F_23 ( V_33 ) )
V_32 = V_33 ;
else
V_32 = F_20 ( sizeof( * V_32 ) * V_31 ) ;
if ( V_32 != NULL )
for ( V_12 = 0 ; V_12 < V_31 ; V_12 ++ )
V_32 [ V_12 ] = F_15 ( V_2 -> V_13 , V_12 ) ;
}
F_16 ( V_9 ) ;
if ( V_31 > 0 && V_32 == NULL ) {
F_2 ( V_35 , V_8 ) ;
return 0 ;
}
for ( V_12 = 0 ; V_12 < V_31 ; V_12 ++ ) {
if ( V_32 [ V_12 ] && V_32 [ V_12 ] -> V_26 ) {
V_15 = F_24 ( V_16 , V_12 ) ;
V_32 [ V_12 ] -> V_26 ( V_30 , V_15 , V_16 , V_12 ,
V_32 [ V_12 ] -> V_18 , V_32 [ V_12 ] -> V_19 ) ;
}
}
if ( V_32 != V_33 )
F_6 ( V_32 ) ;
return 1 ;
}
int F_25 ( int V_1 , T_3 * V_20 ,
const T_3 * V_21 )
{
int V_31 , V_36 , V_12 ;
char * V_15 ;
T_2 * V_33 [ 10 ] ;
T_2 * * V_32 = NULL ;
T_1 * V_2 ;
if ( V_21 -> V_34 == NULL )
return 1 ;
if ( ( V_2 = F_1 ( V_1 ) ) == NULL )
return 0 ;
V_31 = F_14 ( V_2 -> V_13 ) ;
V_36 = F_26 ( V_21 -> V_34 ) ;
if ( V_36 < V_31 )
V_31 = V_36 ;
if ( V_31 > 0 ) {
if ( V_31 < ( int ) F_23 ( V_33 ) )
V_32 = V_33 ;
else
V_32 = F_20 ( sizeof( * V_32 ) * V_31 ) ;
if ( V_32 != NULL )
for ( V_12 = 0 ; V_12 < V_31 ; V_12 ++ )
V_32 [ V_12 ] = F_15 ( V_2 -> V_13 , V_12 ) ;
}
F_16 ( V_9 ) ;
if ( V_31 > 0 && V_32 == NULL ) {
F_2 ( V_37 , V_8 ) ;
return 0 ;
}
for ( V_12 = 0 ; V_12 < V_31 ; V_12 ++ ) {
V_15 = F_24 ( V_21 , V_12 ) ;
if ( V_32 [ V_12 ] && V_32 [ V_12 ] -> V_27 )
V_32 [ V_12 ] -> V_27 ( V_20 , V_21 , & V_15 , V_12 ,
V_32 [ V_12 ] -> V_18 , V_32 [ V_12 ] -> V_19 ) ;
F_27 ( V_20 , V_12 , V_15 ) ;
}
if ( V_32 != V_33 )
F_6 ( V_32 ) ;
return 1 ;
}
void F_28 ( int V_1 , void * V_30 , T_3 * V_16 )
{
int V_31 , V_12 ;
T_1 * V_2 ;
void * V_15 ;
T_2 * V_33 [ 10 ] ;
T_2 * * V_32 = NULL ;
if ( ( V_2 = F_1 ( V_1 ) ) == NULL )
return;
V_31 = F_14 ( V_2 -> V_13 ) ;
if ( V_31 > 0 ) {
if ( V_31 < ( int ) F_23 ( V_33 ) )
V_32 = V_33 ;
else
V_32 = F_20 ( sizeof( * V_32 ) * V_31 ) ;
if ( V_32 != NULL )
for ( V_12 = 0 ; V_12 < V_31 ; V_12 ++ )
V_32 [ V_12 ] = F_15 ( V_2 -> V_13 , V_12 ) ;
}
F_16 ( V_9 ) ;
if ( V_31 > 0 && V_32 == NULL ) {
F_2 ( V_38 , V_8 ) ;
return;
}
for ( V_12 = 0 ; V_12 < V_31 ; V_12 ++ ) {
if ( V_32 [ V_12 ] && V_32 [ V_12 ] -> V_28 ) {
V_15 = F_24 ( V_16 , V_12 ) ;
V_32 [ V_12 ] -> V_28 ( V_30 , V_15 , V_16 , V_12 ,
V_32 [ V_12 ] -> V_18 , V_32 [ V_12 ] -> V_19 ) ;
}
}
if ( V_32 != V_33 )
F_6 ( V_32 ) ;
F_29 ( V_16 -> V_34 ) ;
V_16 -> V_34 = NULL ;
}
int F_27 ( T_3 * V_16 , int V_17 , void * V_39 )
{
int V_12 ;
if ( V_16 -> V_34 == NULL ) {
if ( ( V_16 -> V_34 = F_30 () ) == NULL ) {
F_2 ( V_40 , V_8 ) ;
return 0 ;
}
}
for ( V_12 = F_26 ( V_16 -> V_34 ) ; V_12 <= V_17 ; ++ V_12 ) {
if ( ! F_31 ( V_16 -> V_34 , NULL ) ) {
F_2 ( V_40 , V_8 ) ;
return 0 ;
}
}
F_32 ( V_16 -> V_34 , V_17 , V_39 ) ;
return 1 ;
}
void * F_24 ( const T_3 * V_16 , int V_17 )
{
if ( V_16 -> V_34 == NULL || V_17 >= F_26 ( V_16 -> V_34 ) )
return NULL ;
return F_33 ( V_16 -> V_34 , V_17 ) ;
}
