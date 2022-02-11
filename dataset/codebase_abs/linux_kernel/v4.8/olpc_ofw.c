void T_1 F_1 ( void )
{
T_2 * V_1 , * V_2 ;
if ( ! V_3 )
return;
V_1 = F_2 ( V_4 , sizeof( V_4 ) * V_5 ) ;
if ( ! V_1 ) {
F_3 ( V_6 L_1 ) ;
V_3 = NULL ;
return;
}
V_2 = & V_1 [ V_7 ] ;
F_4 ( & V_8 [ V_7 ] , * V_2 ) ;
F_5 ( V_1 , sizeof( V_4 ) * V_5 ) ;
}
int F_6 ( const char * V_9 , int V_10 , const void * * args , int V_11 ,
void * * V_12 )
{
int V_13 [ V_14 + 3 ] ;
unsigned long V_15 ;
int V_16 , V_17 , * V_18 ;
F_7 ( V_10 + V_11 > V_14 ) ;
if ( ! V_3 )
return - V_19 ;
V_13 [ 0 ] = ( int ) V_9 ;
V_13 [ 1 ] = V_10 ;
V_13 [ 2 ] = V_11 ;
V_18 = & V_13 [ 3 ] ;
for ( V_17 = 0 ; V_17 < V_10 ; V_17 ++ , V_18 ++ )
* V_18 = ( int ) args [ V_17 ] ;
F_8 ( & V_20 , V_15 ) ;
V_16 = V_3 ( V_13 ) ;
F_9 ( & V_20 , V_15 ) ;
if ( ! V_16 ) {
for ( V_17 = 0 ; V_17 < V_11 ; V_17 ++ , V_18 ++ )
* ( ( int * ) V_12 [ V_17 ] ) = * V_18 ;
}
return V_16 ;
}
bool F_10 ( void )
{
return V_3 != NULL ;
}
void T_1 F_11 ( void )
{
struct V_21 * V_22 = & V_23 . V_21 ;
unsigned long V_24 ;
if ( V_22 -> V_25 != V_26 )
return;
V_3 = ( int ( * ) ( int * ) ) V_22 -> V_27 ;
if ( ( unsigned long ) V_3 < V_28 ) {
F_3 ( V_6 L_2 ,
( unsigned long ) V_3 ) ;
V_3 = NULL ;
return;
}
V_24 = F_12 ( ( unsigned long ) V_3 , V_29 ) ;
F_3 ( V_30 L_3 ,
( unsigned long ) V_3 , ( - V_24 ) >> 20 ) ;
F_13 ( - V_24 ) ;
}
bool T_1 F_14 ( void )
{
return V_3 != NULL ;
}
