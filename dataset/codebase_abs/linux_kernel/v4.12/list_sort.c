static struct V_1 * F_1 ( void * V_2 ,
int (* F_2)( void * V_2 , struct V_1 * V_3 ,
struct V_1 * V_4 ) ,
struct V_1 * V_3 , struct V_1 * V_4 )
{
struct V_1 V_5 , * V_6 = & V_5 ;
while ( V_3 && V_4 ) {
if ( (* F_2)( V_2 , V_3 , V_4 ) <= 0 ) {
V_6 -> V_7 = V_3 ;
V_3 = V_3 -> V_7 ;
} else {
V_6 -> V_7 = V_4 ;
V_4 = V_4 -> V_7 ;
}
V_6 = V_6 -> V_7 ;
}
V_6 -> V_7 = V_3 ? : V_4 ;
return V_5 . V_7 ;
}
static void F_3 ( void * V_2 ,
int (* F_2)( void * V_2 , struct V_1 * V_3 ,
struct V_1 * V_4 ) ,
struct V_1 * V_5 ,
struct V_1 * V_3 , struct V_1 * V_4 )
{
struct V_1 * V_6 = V_5 ;
T_1 V_8 = 0 ;
while ( V_3 && V_4 ) {
if ( (* F_2)( V_2 , V_3 , V_4 ) <= 0 ) {
V_6 -> V_7 = V_3 ;
V_3 -> V_9 = V_6 ;
V_3 = V_3 -> V_7 ;
} else {
V_6 -> V_7 = V_4 ;
V_4 -> V_9 = V_6 ;
V_4 = V_4 -> V_7 ;
}
V_6 = V_6 -> V_7 ;
}
V_6 -> V_7 = V_3 ? : V_4 ;
do {
if ( F_4 ( ! ( ++ V_8 ) ) )
(* F_2)( V_2 , V_6 -> V_7 , V_6 -> V_7 ) ;
V_6 -> V_7 -> V_9 = V_6 ;
V_6 = V_6 -> V_7 ;
} while ( V_6 -> V_7 );
V_6 -> V_7 = V_5 ;
V_5 -> V_9 = V_6 ;
}
void F_5 ( void * V_2 , struct V_1 * V_5 ,
int (* F_2)( void * V_2 , struct V_1 * V_3 ,
struct V_1 * V_4 ) )
{
struct V_1 * V_10 [ V_11 + 1 ] ;
int V_12 ;
int V_13 = 0 ;
struct V_1 * V_14 ;
if ( F_6 ( V_5 ) )
return;
memset ( V_10 , 0 , sizeof( V_10 ) ) ;
V_5 -> V_9 -> V_7 = NULL ;
V_14 = V_5 -> V_7 ;
while ( V_14 ) {
struct V_1 * V_15 = V_14 ;
V_14 = V_14 -> V_7 ;
V_15 -> V_7 = NULL ;
for ( V_12 = 0 ; V_10 [ V_12 ] ; V_12 ++ ) {
V_15 = F_1 ( V_2 , F_2 , V_10 [ V_12 ] , V_15 ) ;
V_10 [ V_12 ] = NULL ;
}
if ( V_12 > V_13 ) {
if ( F_4 ( V_12 >= F_7 ( V_10 ) - 1 ) ) {
F_8 ( V_16 L_1 ) ;
V_12 -- ;
}
V_13 = V_12 ;
}
V_10 [ V_12 ] = V_15 ;
}
for ( V_12 = 0 ; V_12 < V_13 ; V_12 ++ )
if ( V_10 [ V_12 ] )
V_14 = F_1 ( V_2 , F_2 , V_10 [ V_12 ] , V_14 ) ;
F_3 ( V_2 , F_2 , V_5 , V_10 [ V_13 ] , V_14 ) ;
}
