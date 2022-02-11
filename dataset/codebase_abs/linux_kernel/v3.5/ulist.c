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
struct V_1 * F_5 ( T_1 V_7 )
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
int F_8 ( struct V_1 * V_1 , T_2 V_8 , unsigned long V_9 ,
T_1 V_7 )
{
return F_9 ( V_1 , V_8 , V_9 , NULL , V_7 ) ;
}
int F_9 ( struct V_1 * V_1 , T_2 V_8 , unsigned long V_9 ,
unsigned long * V_10 , T_1 V_7 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_1 -> V_2 ; ++ V_11 ) {
if ( V_1 -> V_3 [ V_11 ] . V_8 == V_8 ) {
if ( V_10 )
* V_10 = V_1 -> V_3 [ V_11 ] . V_9 ;
return 0 ;
}
}
if ( V_1 -> V_2 >= V_1 -> V_5 ) {
T_2 V_12 = V_1 -> V_5 + 128 ;
struct V_13 * V_14 ;
void * V_15 = NULL ;
if ( V_1 -> V_5 > V_6 )
V_15 = V_1 -> V_3 ;
V_14 = F_10 ( V_15 , sizeof( * V_14 ) * V_12 ,
V_7 ) ;
if ( ! V_14 )
return - V_16 ;
if ( ! V_15 )
memcpy ( V_14 , V_1 -> V_4 ,
sizeof( V_1 -> V_4 ) ) ;
V_1 -> V_3 = V_14 ;
V_1 -> V_5 = V_12 ;
}
V_1 -> V_3 [ V_1 -> V_2 ] . V_8 = V_8 ;
V_1 -> V_3 [ V_1 -> V_2 ] . V_9 = V_9 ;
++ V_1 -> V_2 ;
return 1 ;
}
struct V_13 * F_11 ( struct V_1 * V_1 , struct V_17 * V_18 )
{
if ( V_1 -> V_2 == 0 )
return NULL ;
if ( V_18 -> V_11 < 0 || V_18 -> V_11 >= V_1 -> V_2 )
return NULL ;
return & V_1 -> V_3 [ V_18 -> V_11 ++ ] ;
}
