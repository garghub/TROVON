void F_1 ( struct V_1 * V_1 )
{
V_1 -> V_2 = 0 ;
V_1 -> V_3 = V_1 -> V_4 ;
V_1 -> V_5 = V_6 ;
}
void F_2 ( struct V_1 * V_1 )
{
if ( V_1 -> V_5 > V_6 )
F_3 ( V_1 -> V_3 ) ;
V_1 -> V_5 = 0 ;
}
void F_4 ( struct V_1 * V_1 )
{
F_2 ( V_1 ) ;
F_1 ( V_1 ) ;
}
struct V_1 * F_5 ( unsigned long V_7 )
{
struct V_1 * V_1 = F_6 ( sizeof( * V_1 ) , V_7 ) ;
if ( ! V_1 )
return NULL ;
F_1 ( V_1 ) ;
return V_1 ;
}
void F_7 ( struct V_1 * V_1 )
{
if ( ! V_1 )
return;
F_2 ( V_1 ) ;
F_3 ( V_1 ) ;
}
int F_8 ( struct V_1 * V_1 , T_1 V_8 , unsigned long V_9 ,
unsigned long V_7 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_1 -> V_2 ; ++ V_10 ) {
if ( V_1 -> V_3 [ V_10 ] . V_8 == V_8 )
return 0 ;
}
if ( V_1 -> V_2 >= V_1 -> V_5 ) {
T_1 V_11 = V_1 -> V_5 + 128 ;
struct V_12 * V_13 ;
void * V_14 = NULL ;
if ( V_1 -> V_5 > V_6 )
V_14 = V_1 -> V_3 ;
V_13 = F_9 ( V_14 , sizeof( * V_13 ) * V_11 ,
V_7 ) ;
if ( ! V_13 )
return - V_15 ;
if ( ! V_14 )
memcpy ( V_13 , V_1 -> V_4 ,
sizeof( V_1 -> V_4 ) ) ;
V_1 -> V_3 = V_13 ;
V_1 -> V_5 = V_11 ;
}
V_1 -> V_3 [ V_1 -> V_2 ] . V_8 = V_8 ;
V_1 -> V_3 [ V_1 -> V_2 ] . V_9 = V_9 ;
++ V_1 -> V_2 ;
return 1 ;
}
struct V_12 * F_10 ( struct V_1 * V_1 , struct V_12 * V_16 )
{
int V_17 ;
if ( V_1 -> V_2 == 0 )
return NULL ;
if ( ! V_16 )
return & V_1 -> V_3 [ 0 ] ;
V_17 = ( V_16 - V_1 -> V_3 ) + 1 ;
if ( V_17 < 0 || V_17 >= V_1 -> V_2 )
return NULL ;
return & V_1 -> V_3 [ V_17 ] ;
}
