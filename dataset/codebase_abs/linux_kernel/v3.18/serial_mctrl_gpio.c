void F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
enum V_4 V_5 ;
if ( F_2 ( V_2 ) )
return;
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ )
if ( ! F_2 ( V_2 -> V_7 [ V_5 ] ) &&
V_8 [ V_5 ] . V_9 )
F_3 ( V_2 -> V_7 [ V_5 ] ,
! ! ( V_3 & V_8 [ V_5 ] . V_3 ) ) ;
}
struct V_10 * F_4 ( struct V_1 * V_2 ,
enum V_4 V_11 )
{
if ( ! F_2 ( V_2 ) && ! F_2 ( V_2 -> V_7 [ V_11 ] ) )
return V_2 -> V_7 [ V_11 ] ;
else
return NULL ;
}
unsigned int F_5 ( struct V_1 * V_2 , unsigned int * V_3 )
{
enum V_4 V_5 ;
if ( F_2 ( V_2 ) )
return * V_3 ;
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ ) {
if ( ! F_2 ( V_2 -> V_7 [ V_5 ] ) &&
! V_8 [ V_5 ] . V_9 ) {
if ( F_6 ( V_2 -> V_7 [ V_5 ] ) )
* V_3 |= V_8 [ V_5 ] . V_3 ;
else
* V_3 &= ~ V_8 [ V_5 ] . V_3 ;
}
}
return * V_3 ;
}
struct V_1 * F_7 ( struct V_12 * V_13 , unsigned int V_14 )
{
struct V_1 * V_2 ;
enum V_4 V_5 ;
int V_15 ;
V_2 = F_8 ( V_13 , sizeof( * V_2 ) , V_16 ) ;
if ( ! V_2 )
return F_9 ( - V_17 ) ;
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ ) {
V_2 -> V_7 [ V_5 ] = F_10 ( V_13 ,
V_8 [ V_5 ] . V_18 ,
V_14 ) ;
if ( F_2 ( V_2 -> V_7 [ V_5 ] ) )
continue;
if ( V_8 [ V_5 ] . V_9 )
V_15 = F_11 ( V_2 -> V_7 [ V_5 ] , 0 ) ;
else
V_15 = F_12 ( V_2 -> V_7 [ V_5 ] ) ;
if ( V_15 ) {
F_13 ( V_13 , L_1 ,
V_8 [ V_5 ] . V_18 ) ;
F_14 ( V_13 , V_2 -> V_7 [ V_5 ] ) ;
V_2 -> V_7 [ V_5 ] = NULL ;
}
}
return V_2 ;
}
void F_15 ( struct V_12 * V_13 , struct V_1 * V_2 )
{
enum V_4 V_5 ;
if ( F_2 ( V_2 ) )
return;
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ )
if ( ! F_2 ( V_2 -> V_7 [ V_5 ] ) )
F_14 ( V_13 , V_2 -> V_7 [ V_5 ] ) ;
F_16 ( V_13 , V_2 ) ;
}
