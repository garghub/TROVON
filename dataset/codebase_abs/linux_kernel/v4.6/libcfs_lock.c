void
F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 ) ;
F_2 ( ! V_2 -> V_4 ) ;
F_3 ( V_2 -> V_3 ) ;
F_4 ( V_2 , sizeof( * V_2 ) ) ;
}
struct V_1 *
F_5 ( struct V_5 * V_6 )
{
struct V_1 * V_2 ;
T_1 * V_7 ;
int V_8 ;
F_6 ( V_2 , sizeof( * V_2 ) ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_9 = V_6 ;
V_2 -> V_3 = F_7 ( V_6 , sizeof( * V_7 ) ) ;
if ( ! V_2 -> V_3 ) {
F_4 ( V_2 , sizeof( * V_2 ) ) ;
return NULL ;
}
F_8 (lock, i, pcl->pcl_locks)
F_9 ( V_7 ) ;
return V_2 ;
}
void
V_1 ( struct V_1 * V_2 , int V_10 )
__acquires( V_2 -> V_3 )
{
int V_11 = F_10 ( V_2 -> V_9 ) ;
int V_8 ;
F_2 ( V_10 >= V_12 && V_10 < V_11 ) ;
if ( V_11 == 1 ) {
V_10 = 0 ;
} else {
while ( V_2 -> V_4 )
F_11 () ;
}
if ( F_12 ( V_10 != V_12 ) ) {
F_13 ( V_2 -> V_3 [ V_10 ] ) ;
return;
}
for ( V_8 = 0 ; V_8 < V_11 ; V_8 ++ ) {
F_13 ( V_2 -> V_3 [ V_8 ] ) ;
if ( V_8 == 0 ) {
F_2 ( ! V_2 -> V_4 ) ;
V_2 -> V_4 = 1 ;
}
}
}
void
F_14 ( struct V_1 * V_2 , int V_10 )
__releases( V_2 -> V_3 )
{
int V_11 = F_10 ( V_2 -> V_9 ) ;
int V_8 ;
V_10 = V_11 == 1 ? 0 : V_10 ;
if ( F_12 ( V_10 != V_12 ) ) {
F_15 ( V_2 -> V_3 [ V_10 ] ) ;
return;
}
for ( V_8 = V_11 - 1 ; V_8 >= 0 ; V_8 -- ) {
if ( V_8 == 0 ) {
F_2 ( V_2 -> V_4 ) ;
V_2 -> V_4 = 0 ;
}
F_15 ( V_2 -> V_3 [ V_8 ] ) ;
}
}
void
F_16 ( T_2 * * V_13 )
{
F_3 ( V_13 ) ;
}
T_2 * *
F_17 ( struct V_5 * V_6 , int V_14 )
{
T_2 * * V_13 ;
T_2 * V_15 ;
int V_8 ;
V_13 = F_7 ( V_6 , sizeof( * V_15 ) ) ;
if ( ! V_13 )
return NULL ;
F_8 (ref, i, refs)
F_18 ( V_15 , V_14 ) ;
return V_13 ;
}
int
F_19 ( T_2 * * V_13 )
{
T_2 * V_15 ;
int V_8 ;
int V_16 = 0 ;
F_8 (ref, i, refs)
V_16 += F_20 ( V_15 ) ;
return V_16 ;
}
