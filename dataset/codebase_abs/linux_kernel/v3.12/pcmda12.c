static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned int V_11 = F_2 ( V_6 -> V_12 ) ;
unsigned int V_13 = V_9 -> V_14 [ V_11 ] ;
unsigned long V_15 = V_2 -> V_16 + ( V_11 * 2 ) ;
int V_17 ;
for ( V_17 = 0 ; V_17 < V_6 -> V_18 ; ++ V_17 ) {
V_13 = V_7 [ V_17 ] ;
F_3 ( V_13 & 0xff , V_15 ) ;
F_3 ( ( V_13 >> 8 ) & 0xff , V_15 + 1 ) ;
if ( ! V_9 -> V_19 )
F_4 ( V_15 ) ;
}
V_9 -> V_14 [ V_11 ] = V_13 ;
return V_6 -> V_18 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned int V_11 = F_2 ( V_6 -> V_12 ) ;
int V_17 ;
if ( V_9 -> V_19 )
F_4 ( V_2 -> V_16 ) ;
for ( V_17 = 0 ; V_17 < V_6 -> V_18 ; V_17 ++ )
V_7 [ V_17 ] = V_9 -> V_14 [ V_11 ] ;
return V_6 -> V_18 ;
}
static void F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < V_4 -> V_20 ; ++ V_17 ) {
F_3 ( 0 , V_2 -> V_16 + ( V_17 * 2 ) ) ;
F_3 ( 0 , V_2 -> V_16 + ( V_17 * 2 ) + 1 ) ;
}
F_4 ( V_2 -> V_16 ) ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
struct V_8 * V_9 ;
struct V_3 * V_4 ;
int V_23 ;
V_23 = F_8 ( V_2 , V_22 -> V_24 [ 0 ] , 0x10 ) ;
if ( V_23 )
return V_23 ;
V_9 = F_9 ( V_2 , sizeof( * V_9 ) ) ;
if ( ! V_9 )
return - V_25 ;
V_9 -> V_19 = V_22 -> V_24 [ 1 ] ;
V_23 = F_10 ( V_2 , 1 ) ;
if ( V_23 )
return V_23 ;
V_4 = & V_2 -> V_26 [ 0 ] ;
V_4 -> type = V_27 ;
V_4 -> V_28 = V_29 | V_30 ;
V_4 -> V_20 = 8 ;
V_4 -> V_31 = 0x0fff ;
V_4 -> V_32 = & V_33 ;
V_4 -> V_34 = F_1 ;
V_4 -> V_35 = F_5 ;
F_6 ( V_2 , V_4 ) ;
return 0 ;
}
