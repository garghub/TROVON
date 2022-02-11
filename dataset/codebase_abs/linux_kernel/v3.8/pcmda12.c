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
unsigned long V_20 ;
int V_21 ;
V_20 = V_19 -> V_22 [ 0 ] ;
F_12 ( V_23
L_1 , V_2 -> V_24 , V_2 -> V_25 -> V_26 ,
V_20 , V_19 -> V_22 [ 1 ] ? L_2 : L_3 ) ;
if ( ! F_13 ( V_20 , V_27 , V_2 -> V_25 -> V_26 ) ) {
F_12 ( L_4 ) ;
return - V_28 ;
}
V_2 -> V_20 = V_20 ;
V_2 -> V_29 = V_2 -> V_25 -> V_26 ;
V_11 = F_14 ( sizeof( * V_11 ) , V_30 ) ;
if ( ! V_11 )
return - V_31 ;
V_2 -> V_12 = V_11 ;
V_11 -> V_17 = V_19 -> V_22 [ 1 ] ;
V_21 = F_15 ( V_2 , 1 ) ;
if ( V_21 )
return V_21 ;
V_6 = & V_2 -> V_32 [ 0 ] ;
V_6 -> V_12 = NULL ;
V_6 -> V_33 = ( 0x1 << V_34 ) - 1 ;
V_6 -> V_35 = & V_36 ;
V_6 -> type = V_37 ;
V_6 -> V_38 = V_39 | V_40 ;
V_6 -> V_41 = V_4 ;
V_6 -> V_42 = & F_6 ;
V_6 -> V_43 = & F_10 ;
F_1 ( V_2 ) ;
F_12 ( V_23 L_5 ) ;
return 1 ;
}
static void F_16 ( struct V_1 * V_2 )
{
if ( V_2 -> V_20 )
F_17 ( V_2 -> V_20 , V_27 ) ;
}
