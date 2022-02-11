static void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_4 ; ++ V_3 ) {
F_2 ( 0 , F_3 ( V_3 ) ) ;
F_2 ( 0 , F_4 ( V_3 ) ) ;
}
F_5 ( F_3 ( 0 ) ) ;
}
static int F_6 ( struct V_1 * V_2 , struct V_5 * V_6 ,
struct V_7 * V_8 , unsigned int * V_9 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
int V_3 ;
int V_13 = F_7 ( V_8 -> V_14 ) ;
for ( V_3 = 0 ; V_3 < V_8 -> V_15 ; ++ V_3 ) {
F_2 ( F_8 ( V_9 [ V_3 ] ) , F_3 ( V_13 ) ) ;
F_2 ( F_9 ( V_9 [ V_3 ] ) , F_4 ( V_13 ) ) ;
V_11 -> V_16 [ V_13 ] = V_9 [ V_3 ] ;
if ( ! V_11 -> V_17 )
F_5 ( F_3 ( V_13 ) ) ;
}
return V_3 ;
}
static int F_10 ( struct V_1 * V_2 , struct V_5 * V_6 ,
struct V_7 * V_8 , unsigned int * V_9 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
int V_3 ;
int V_13 = F_7 ( V_8 -> V_14 ) ;
for ( V_3 = 0 ; V_3 < V_8 -> V_15 ; V_3 ++ ) {
if ( V_11 -> V_17 )
F_5 ( F_3 ( V_13 ) ) ;
V_9 [ V_3 ] = V_11 -> V_16 [ V_13 ] ;
}
return V_3 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_18 * V_19 )
{
struct V_10 * V_11 ;
struct V_5 * V_6 ;
int V_20 ;
V_20 = F_12 ( V_2 , V_19 -> V_21 [ 0 ] , V_22 ) ;
if ( V_20 )
return V_20 ;
V_11 = F_13 ( sizeof( * V_11 ) , V_23 ) ;
if ( ! V_11 )
return - V_24 ;
V_2 -> V_12 = V_11 ;
V_11 -> V_17 = V_19 -> V_21 [ 1 ] ;
V_20 = F_14 ( V_2 , 1 ) ;
if ( V_20 )
return V_20 ;
V_6 = & V_2 -> V_25 [ 0 ] ;
V_6 -> V_12 = NULL ;
V_6 -> V_26 = ( 0x1 << V_27 ) - 1 ;
V_6 -> V_28 = & V_29 ;
V_6 -> type = V_30 ;
V_6 -> V_31 = V_32 | V_33 ;
V_6 -> V_34 = V_4 ;
V_6 -> V_35 = & F_6 ;
V_6 -> V_36 = & F_10 ;
F_1 ( V_2 ) ;
return 1 ;
}
