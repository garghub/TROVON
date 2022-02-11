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
int V_3 ;
int V_10 = F_7 ( V_8 -> V_11 ) ;
for ( V_3 = 0 ; V_3 < V_8 -> V_12 ; ++ V_3 ) {
F_2 ( F_8 ( V_9 [ V_3 ] ) , F_3 ( V_10 ) ) ;
F_2 ( F_9 ( V_9 [ V_3 ] ) , F_4 ( V_10 ) ) ;
V_13 -> V_14 [ V_10 ] = V_9 [ V_3 ] ;
if ( ! V_13 -> V_15 )
F_5 ( F_3 ( V_10 ) ) ;
}
return V_3 ;
}
static int F_10 ( struct V_1 * V_2 , struct V_5 * V_6 ,
struct V_7 * V_8 , unsigned int * V_9 )
{
int V_3 ;
int V_10 = F_7 ( V_8 -> V_11 ) ;
for ( V_3 = 0 ; V_3 < V_8 -> V_12 ; V_3 ++ ) {
if ( V_13 -> V_15 )
F_5 ( F_3 ( V_10 ) ) ;
V_9 [ V_3 ] = V_13 -> V_14 [ V_10 ] ;
}
return V_3 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_16 * V_17 )
{
struct V_5 * V_6 ;
unsigned long V_18 ;
V_18 = V_17 -> V_19 [ 0 ] ;
F_12 ( V_20
L_1 , V_2 -> V_21 , V_2 -> V_22 -> V_23 ,
V_18 , V_17 -> V_19 [ 1 ] ? L_2 : L_3 ) ;
if ( ! F_13 ( V_18 , V_24 , V_2 -> V_22 -> V_23 ) ) {
F_12 ( L_4 ) ;
return - V_25 ;
}
V_2 -> V_18 = V_18 ;
V_2 -> V_26 = V_27 -> V_28 ;
if ( F_14 ( V_2 , sizeof( struct V_29 ) ) < 0 ) {
F_12 ( V_30 L_5 ) ;
return - V_31 ;
}
V_13 -> V_15 = V_17 -> V_19 [ 1 ] ;
if ( F_15 ( V_2 , 1 ) < 0 ) {
F_12 ( V_30 L_6 ) ;
return - V_31 ;
}
V_6 = V_2 -> V_32 ;
V_6 -> V_33 = NULL ;
V_6 -> V_34 = ( 0x1 << V_35 ) - 1 ;
V_6 -> V_36 = & V_37 ;
V_6 -> type = V_38 ;
V_6 -> V_39 = V_40 | V_41 ;
V_6 -> V_42 = V_4 ;
V_6 -> V_43 = & F_6 ;
V_6 -> V_44 = & F_10 ;
F_1 ( V_2 ) ;
F_12 ( V_20 L_7 ) ;
return 1 ;
}
static void F_16 ( struct V_1 * V_2 )
{
if ( V_2 -> V_18 )
F_17 ( V_2 -> V_18 , V_24 ) ;
}
