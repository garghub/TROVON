struct V_1 * F_1 ( T_1 V_2 , T_1 V_3 ,
T_1 (* F_2) ( void * , T_1 ) , bool (* F_3) ( void * ,
void * ) ,
void (* F_4) ( void * ) )
{
struct V_1 * V_4 ;
T_1 V_5 ;
V_4 = F_5 ( sizeof( struct V_1 ) , V_6 ) ;
if ( V_4 == NULL )
return NULL ;
V_4 -> V_2 = V_2 ;
V_4 -> V_3 = V_3 ;
V_4 -> F_2 = F_2 ;
V_4 -> F_3 = F_3 ;
V_4 -> F_4 = F_4 == NULL ? V_7 : F_4 ;
V_4 -> V_8 =
F_5 ( sizeof( struct V_9 * ) * V_2 , V_6 ) ;
if ( V_4 -> V_8 == NULL ) {
F_6 ( V_4 ) ;
return NULL ;
}
for ( V_5 = 0 ; V_5 < V_2 ; V_5 ++ )
V_4 -> V_8 [ V_5 ] = NULL ;
return V_4 ;
}
void F_6 ( struct V_1 * V_4 )
{
struct V_9 * V_10 , * V_11 ;
T_1 V_5 ;
if ( V_4 != NULL ) {
if ( V_4 -> V_8 != NULL ) {
for ( V_5 = 0 ; V_5 < V_4 -> V_2 ; V_5 ++ ) {
for ( V_10 = V_4 -> V_8 [ V_5 ] ; V_10 != NULL ;
V_10 = V_11 ) {
V_11 = V_10 -> V_11 ;
(* V_4 -> F_4 ) ( V_10 -> V_12 ) ;
F_7 ( V_10 ) ;
}
}
F_7 ( V_4 -> V_8 ) ;
}
F_7 ( V_4 ) ;
}
}
void * F_8 ( struct V_1 * V_4 , void * V_13 )
{
struct V_9 * V_10 ;
V_10 = V_4 -> V_8 [ (* V_4 -> F_2 ) ( V_13 , V_4 -> V_2 ) ] ;
for (; V_10 ; V_10 = V_10 -> V_11 ) {
if ( (* V_4 -> F_3 ) ( V_13 , V_10 -> V_12 ) )
return V_10 -> V_12 ;
}
return NULL ;
}
void * F_9 ( struct V_1 * V_4 , void * V_13 , void * V_14 )
{
struct V_9 * V_10 ;
T_1 V_5 ;
char * V_15 , * V_16 ;
V_10 = F_5 ( sizeof( struct V_9 ) - 1 + V_4 -> V_3 ,
V_6 ) ;
if ( V_10 != NULL ) {
V_16 = ( char * ) V_10 -> V_12 ;
V_15 = ( char * ) V_14 ;
for ( V_5 = 0 ; V_5 < V_4 -> V_3 ; V_5 ++ )
* V_16 ++ = * V_15 ++ ;
V_5 = (* V_4 -> F_2 ) ( V_13 , V_4 -> V_2 ) ;
V_10 -> V_11 = V_4 -> V_8 [ V_5 ] ;
V_4 -> V_8 [ V_5 ] = V_10 ;
return V_10 -> V_12 ;
}
return NULL ;
}
static void V_7 ( void * V_17 )
{
V_17 = V_17 ;
}
void F_10 ( struct V_1 * V_4 ,
void (* F_11)( void * , void * ) , void * V_18 )
{
struct V_9 * V_10 ;
T_2 V_5 ;
if ( V_4 && V_4 -> V_8 )
for ( V_5 = 0 ; V_5 < V_4 -> V_2 ; V_5 ++ ) {
V_10 = V_4 -> V_8 [ V_5 ] ;
while ( V_10 ) {
F_11 ( & V_10 -> V_12 , V_18 ) ;
V_10 = V_10 -> V_11 ;
}
}
}
