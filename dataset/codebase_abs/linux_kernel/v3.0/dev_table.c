int F_1 ( int V_1 , char * V_2 , struct V_3 * V_4 ,
int V_5 , int V_6 , unsigned int V_7 ,
void * V_8 , int V_9 , int V_10 )
{
struct V_3 * V_11 ;
struct V_12 * V_13 ;
int V_14 ;
if ( V_1 != V_15 || V_5 > sizeof( struct V_3 ) ) {
F_2 ( V_16 L_1 , V_2 ) ;
return - ( V_17 ) ;
}
V_14 = F_3 () ;
if ( V_14 == - 1 ) {
F_2 ( V_16 L_2 ) ;
return - ( V_18 ) ;
}
V_11 = (struct V_3 * ) ( V_19 [ V_20 ] = F_4 ( sizeof( struct V_3 ) ) ) ;
V_20 ++ ;
if ( V_20 >= V_21 )
V_20 = V_21 - 1 ;
V_13 = (struct V_12 * ) ( V_19 [ V_20 ] = F_5 ( sizeof( struct V_12 ) ) ) ;
V_20 ++ ;
if ( V_20 >= V_21 )
V_20 = V_21 - 1 ;
if ( V_11 == NULL || V_13 == NULL ) {
F_2 ( V_16 L_3 , V_2 ) ;
F_6 ( V_14 ) ;
return - ( V_22 ) ;
}
F_7 ( & V_13 -> V_23 ) ;
F_7 ( & V_13 -> V_24 ) ;
F_7 ( & V_13 -> V_25 ) ;
if ( V_5 < sizeof( struct V_3 ) )
memset ( ( char * ) V_11 , 0 , sizeof( struct V_3 ) ) ;
memcpy ( ( char * ) V_11 , ( char * ) V_4 , V_5 ) ;
V_13 -> V_11 = V_11 ;
F_8 ( V_13 -> V_2 , V_2 , sizeof( V_13 -> V_2 ) ) ;
V_13 -> V_6 = V_6 ;
V_13 -> V_7 = V_7 ;
V_13 -> V_8 = V_8 ;
V_26 [ V_14 ] = V_13 ;
F_9 ( V_14 , V_9 , V_10 ) ;
F_10 () ;
return V_14 ;
}
int F_11 ( int V_1 , char * V_2 , struct V_27 * V_4 ,
int V_5 , void * V_8 )
{
struct V_27 * V_13 ;
int V_28 = F_12 () ;
if ( V_28 == - 1 ) {
F_2 ( V_16 L_4 ) ;
return - V_18 ;
}
if ( V_1 != V_29 ||
V_5 > sizeof( struct V_27 ) ) {
F_2 ( V_16 L_5 , V_2 ) ;
return - V_17 ;
}
V_13 = (struct V_27 * ) ( V_19 [ V_20 ] = F_5 ( sizeof( struct V_27 ) ) ) ;
V_20 ++ ;
if ( V_20 >= V_21 )
V_20 = V_21 - 1 ;
if ( V_13 == NULL ) {
F_2 ( V_16 L_6 , V_2 ) ;
return - V_22 ;
}
memcpy ( ( char * ) V_13 , ( char * ) V_4 , V_5 ) ;
F_8 ( V_13 -> V_2 , V_2 , sizeof( V_13 -> V_2 ) ) ;
V_13 -> V_8 = V_8 ;
V_30 [ V_28 ] = V_13 ;
return V_28 ;
}
void F_6 ( int V_31 )
{
if ( V_31 != - 1 ) {
F_13 ( V_31 ) ;
V_26 [ V_31 ] = NULL ;
F_14 ( ( V_31 << 4 ) + 3 ) ;
}
}
static int F_3 ( void )
{
int V_32 = F_15 ( & V_33 , - 1 ) ;
if( V_32 == - 1 )
return V_32 ;
V_32 >>= 4 ;
if( V_32 >= V_34 )
V_34 = V_32 + 1 ;
return V_32 ;
}
int F_16 ( void )
{
int V_32 = F_17 ( & V_33 , - 1 ) ;
if( V_32 == - 1 )
return V_32 ;
V_32 >>= 4 ;
if( V_32 >= V_35 )
V_35 = V_32 + 1 ;
return V_32 ;
}
int F_18 ( void )
{
int V_32 ;
for ( V_32 = 0 ; V_32 < V_36 ; V_32 ++ ) {
if ( V_37 [ V_32 ] == NULL ) {
if ( V_32 >= V_38 )
V_38 ++ ;
return V_32 ;
}
}
return - 1 ;
}
int F_12 ( void )
{
int V_32 = F_19 ( & V_33 , - 1 ) ;
if( V_32 == - 1 )
return - 1 ;
V_32 >>= 4 ;
if( V_32 >= V_39 )
V_39 = V_32 + 1 ;
return V_32 ;
}
int F_20 ( void )
{
int V_32 ;
for ( V_32 = 0 ; V_32 < V_40 ; V_32 ++ ) {
if ( V_41 [ V_32 ] == NULL ) {
if ( V_32 >= V_42 )
V_42 ++ ;
return V_32 ;
}
}
return - 1 ;
}
void F_21 ( int V_31 )
{
if ( V_31 != - 1 ) {
V_30 [ V_31 ] = NULL ;
F_22 ( V_31 << 4 ) ;
V_39 -- ;
}
}
void F_23 ( int V_31 )
{
if ( V_31 != - 1 ) {
V_43 [ V_31 ] = NULL ;
F_24 ( ( V_31 << 4 ) + 2 ) ;
}
}
void F_25 ( int V_31 )
{
if ( V_31 != - 1 )
V_37 [ V_31 ] = NULL ;
}
void F_26 ( int V_31 )
{
if ( V_31 != - 1 )
V_41 [ V_31 ] = NULL ;
}
