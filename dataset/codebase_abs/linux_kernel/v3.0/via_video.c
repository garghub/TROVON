void F_1 ( T_1 * V_1 )
{
unsigned int V_2 ;
F_2 ( L_1 ) ;
for ( V_2 = 0 ; V_2 < V_3 ; ++ V_2 ) {
F_3 ( & ( V_1 -> V_4 [ V_2 ] ) ) ;
F_4 ( V_1 -> V_5 , V_2 ) -> V_6 = 0 ;
}
}
void F_5 ( T_1 * V_1 )
{
}
void F_6 ( T_1 * V_1 , int V_7 )
{
unsigned int V_2 ;
volatile int * V_6 ;
if ( ! V_1 -> V_5 )
return;
for ( V_2 = 0 ; V_2 < V_3 ; ++ V_2 ) {
V_6 = ( volatile int * ) F_4 ( V_1 -> V_5 , V_2 ) ;
if ( ( F_7 ( * V_6 ) == V_7 ) ) {
if ( F_8 ( * V_6 )
&& ( * V_6 & V_8 ) ) {
F_9 ( & ( V_1 -> V_4 [ V_2 ] ) ) ;
}
* V_6 = 0 ;
}
}
}
int F_10 ( struct V_9 * V_10 , void * V_11 , struct V_12 * V_13 )
{
T_2 * V_14 = V_11 ;
volatile int * V_6 ;
T_1 * V_1 = ( T_1 * ) V_10 -> V_15 ;
T_3 * V_16 = V_1 -> V_5 ;
int V_17 = 0 ;
F_2 ( L_1 ) ;
if ( V_14 -> V_6 >= V_3 )
return - V_18 ;
V_6 = ( volatile int * ) F_4 ( V_16 , V_14 -> V_6 ) ;
switch ( V_14 -> V_19 ) {
case V_20 :
F_11 ( V_17 , V_1 -> V_4 [ V_14 -> V_6 ] ,
( V_14 -> V_21 / 10 ) * ( V_22 / 100 ) , * V_6 != V_14 -> V_23 ) ;
return V_17 ;
case V_24 :
F_9 ( & ( V_1 -> V_4 [ V_14 -> V_6 ] ) ) ;
return 0 ;
}
return 0 ;
}
