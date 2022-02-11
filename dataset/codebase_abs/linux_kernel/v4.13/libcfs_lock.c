void
F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 ) ;
F_2 ( ! V_2 -> V_4 ) ;
F_3 ( V_2 -> V_3 ) ;
F_4 ( V_2 , sizeof( * V_2 ) ) ;
}
struct V_1 *
F_5 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_1 * V_2 ;
T_1 * V_9 ;
int V_10 ;
F_6 ( V_2 , sizeof( * V_2 ) ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_11 = V_6 ;
V_2 -> V_3 = F_7 ( V_6 , sizeof( * V_9 ) ) ;
if ( ! V_2 -> V_3 ) {
F_4 ( V_2 , sizeof( * V_2 ) ) ;
return NULL ;
}
if ( ! V_8 )
F_8 ( L_1 ) ;
F_9 (lock, i, pcl->pcl_locks) {
F_10 ( V_9 ) ;
if ( V_8 )
F_11 ( V_9 , & V_8 [ V_10 ] ) ;
}
return V_2 ;
}
void
V_1 ( struct V_1 * V_2 , int V_12 )
__acquires( V_2 -> V_3 )
{
int V_13 = F_12 ( V_2 -> V_11 ) ;
int V_10 ;
F_2 ( V_12 >= V_14 && V_12 < V_13 ) ;
if ( V_13 == 1 ) {
V_12 = 0 ;
} else {
while ( V_2 -> V_4 )
F_13 () ;
}
if ( F_14 ( V_12 != V_14 ) ) {
F_15 ( V_2 -> V_3 [ V_12 ] ) ;
return;
}
for ( V_10 = 0 ; V_10 < V_13 ; V_10 ++ ) {
F_15 ( V_2 -> V_3 [ V_10 ] ) ;
if ( ! V_10 ) {
F_2 ( ! V_2 -> V_4 ) ;
V_2 -> V_4 = 1 ;
}
}
}
void
F_16 ( struct V_1 * V_2 , int V_12 )
__releases( V_2 -> V_3 )
{
int V_13 = F_12 ( V_2 -> V_11 ) ;
int V_10 ;
V_12 = V_13 == 1 ? 0 : V_12 ;
if ( F_14 ( V_12 != V_14 ) ) {
F_17 ( V_2 -> V_3 [ V_12 ] ) ;
return;
}
for ( V_10 = V_13 - 1 ; V_10 >= 0 ; V_10 -- ) {
if ( ! V_10 ) {
F_2 ( V_2 -> V_4 ) ;
V_2 -> V_4 = 0 ;
}
F_17 ( V_2 -> V_3 [ V_10 ] ) ;
}
}
