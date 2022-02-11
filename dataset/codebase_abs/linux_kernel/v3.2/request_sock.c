int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
T_1 V_4 = sizeof( struct V_5 ) ;
struct V_5 * V_6 ;
V_3 = F_2 ( V_7 , V_3 , V_8 ) ;
V_3 = F_3 ( V_7 , V_3 , 8 ) ;
V_3 = F_4 ( V_3 + 1 ) ;
V_4 += V_3 * sizeof( struct V_9 * ) ;
if ( V_4 > V_10 )
V_6 = F_5 ( V_4 ) ;
else
V_6 = F_6 ( V_4 , V_11 ) ;
if ( V_6 == NULL )
return - V_12 ;
for ( V_6 -> V_13 = 3 ;
( 1 << V_6 -> V_13 ) < V_3 ;
V_6 -> V_13 ++ ) ;
F_7 ( & V_6 -> V_14 , sizeof( V_6 -> V_14 ) ) ;
F_8 ( & V_2 -> V_15 ) ;
V_2 -> V_16 = NULL ;
V_6 -> V_3 = V_3 ;
F_9 ( & V_2 -> V_15 ) ;
V_2 -> V_17 = V_6 ;
F_10 ( & V_2 -> V_15 ) ;
return 0 ;
}
void F_11 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
T_1 V_4 ;
V_6 = V_2 -> V_17 ;
V_4 = sizeof( struct V_5 ) +
V_6 -> V_3 * sizeof( struct V_9 * ) ;
if ( V_4 > V_10 )
F_12 ( V_6 ) ;
else
F_13 ( V_6 ) ;
}
static inline struct V_5 * F_14 (
struct V_1 * V_2 )
{
struct V_5 * V_6 ;
F_9 ( & V_2 -> V_15 ) ;
V_6 = V_2 -> V_17 ;
V_2 -> V_17 = NULL ;
F_10 ( & V_2 -> V_15 ) ;
return V_6 ;
}
void F_15 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_14 ( V_2 ) ;
T_1 V_4 = sizeof( struct V_5 ) +
V_6 -> V_3 * sizeof( struct V_9 * ) ;
if ( V_6 -> V_18 != 0 ) {
unsigned int V_19 ;
for ( V_19 = 0 ; V_19 < V_6 -> V_3 ; V_19 ++ ) {
struct V_9 * V_20 ;
while ( ( V_20 = V_6 -> V_21 [ V_19 ] ) != NULL ) {
V_6 -> V_21 [ V_19 ] = V_20 -> V_22 ;
V_6 -> V_18 -- ;
F_16 ( V_20 ) ;
}
}
}
F_17 ( V_6 -> V_18 != 0 ) ;
if ( V_4 > V_10 )
F_12 ( V_6 ) ;
else
F_13 ( V_6 ) ;
}
