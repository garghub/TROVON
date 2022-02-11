struct V_1 * F_1 ( T_1 (* F_2)( struct V_1 * V_2 , const void * V_3 ) ,
int (* F_3)( struct V_1 * V_2 , const void * V_4 , const void * V_5 ) ,
T_1 V_6 )
{
struct V_1 * V_7 ;
T_1 V_8 ;
V_7 = F_4 ( sizeof( * V_7 ) , V_9 ) ;
if ( V_7 == NULL )
return V_7 ;
V_7 -> V_6 = V_6 ;
V_7 -> V_10 = 0 ;
V_7 -> F_2 = F_2 ;
V_7 -> F_3 = F_3 ;
V_7 -> V_11 = F_5 ( sizeof( * ( V_7 -> V_11 ) ) * V_6 , V_9 ) ;
if ( V_7 -> V_11 == NULL ) {
F_6 ( V_7 ) ;
return NULL ;
}
for ( V_8 = 0 ; V_8 < V_6 ; V_8 ++ )
V_7 -> V_11 [ V_8 ] = NULL ;
return V_7 ;
}
int F_7 ( struct V_1 * V_2 , void * V_3 , void * V_12 )
{
T_1 V_13 ;
struct V_14 * V_15 , * V_16 , * V_17 ;
if ( ! V_2 || V_2 -> V_10 == V_18 )
return - V_19 ;
V_13 = V_2 -> F_2 ( V_2 , V_3 ) ;
V_15 = NULL ;
V_16 = V_2 -> V_11 [ V_13 ] ;
while ( V_16 && V_2 -> F_3 ( V_2 , V_3 , V_16 -> V_3 ) > 0 ) {
V_15 = V_16 ;
V_16 = V_16 -> V_20 ;
}
if ( V_16 && ( V_2 -> F_3 ( V_2 , V_3 , V_16 -> V_3 ) == 0 ) )
return - V_21 ;
V_17 = F_4 ( sizeof( * V_17 ) , V_9 ) ;
if ( V_17 == NULL )
return - V_22 ;
V_17 -> V_3 = V_3 ;
V_17 -> V_12 = V_12 ;
if ( V_15 ) {
V_17 -> V_20 = V_15 -> V_20 ;
V_15 -> V_20 = V_17 ;
} else {
V_17 -> V_20 = V_2 -> V_11 [ V_13 ] ;
V_2 -> V_11 [ V_13 ] = V_17 ;
}
V_2 -> V_10 ++ ;
return 0 ;
}
void * F_8 ( struct V_1 * V_2 , const void * V_3 )
{
T_1 V_13 ;
struct V_14 * V_16 ;
if ( ! V_2 )
return NULL ;
V_13 = V_2 -> F_2 ( V_2 , V_3 ) ;
V_16 = V_2 -> V_11 [ V_13 ] ;
while ( V_16 && V_2 -> F_3 ( V_2 , V_3 , V_16 -> V_3 ) > 0 )
V_16 = V_16 -> V_20 ;
if ( V_16 == NULL || ( V_2 -> F_3 ( V_2 , V_3 , V_16 -> V_3 ) != 0 ) )
return NULL ;
return V_16 -> V_12 ;
}
void F_9 ( struct V_1 * V_2 )
{
T_1 V_8 ;
struct V_14 * V_16 , * V_23 ;
if ( ! V_2 )
return;
for ( V_8 = 0 ; V_8 < V_2 -> V_6 ; V_8 ++ ) {
V_16 = V_2 -> V_11 [ V_8 ] ;
while ( V_16 ) {
V_23 = V_16 ;
V_16 = V_16 -> V_20 ;
F_6 ( V_23 ) ;
}
V_2 -> V_11 [ V_8 ] = NULL ;
}
F_6 ( V_2 -> V_11 ) ;
V_2 -> V_11 = NULL ;
F_6 ( V_2 ) ;
}
int F_10 ( struct V_1 * V_2 ,
int (* F_11)( void * V_24 , void * V_25 , void * args ) ,
void * args )
{
T_1 V_8 ;
int V_26 ;
struct V_14 * V_16 ;
if ( ! V_2 )
return 0 ;
for ( V_8 = 0 ; V_8 < V_2 -> V_6 ; V_8 ++ ) {
V_16 = V_2 -> V_11 [ V_8 ] ;
while ( V_16 ) {
V_26 = F_11 ( V_16 -> V_3 , V_16 -> V_12 , args ) ;
if ( V_26 )
return V_26 ;
V_16 = V_16 -> V_20 ;
}
}
return 0 ;
}
void F_12 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
T_1 V_8 , V_29 , V_30 , V_31 ;
struct V_14 * V_16 ;
V_30 = 0 ;
V_31 = 0 ;
for ( V_30 = V_31 = V_8 = 0 ; V_8 < V_2 -> V_6 ; V_8 ++ ) {
V_16 = V_2 -> V_11 [ V_8 ] ;
if ( V_16 ) {
V_30 ++ ;
V_29 = 0 ;
while ( V_16 ) {
V_29 ++ ;
V_16 = V_16 -> V_20 ;
}
if ( V_29 > V_31 )
V_31 = V_29 ;
}
}
V_28 -> V_30 = V_30 ;
V_28 -> V_31 = V_31 ;
}
