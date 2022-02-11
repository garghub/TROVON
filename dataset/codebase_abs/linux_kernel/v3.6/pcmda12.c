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
const struct V_18 * V_19 = F_12 ( V_2 ) ;
struct V_5 * V_6 ;
unsigned long V_20 ;
int V_21 ;
V_20 = V_17 -> V_22 [ 0 ] ;
F_13 ( V_23
L_1 , V_2 -> V_24 , V_2 -> V_25 -> V_26 ,
V_20 , V_17 -> V_22 [ 1 ] ? L_2 : L_3 ) ;
if ( ! F_14 ( V_20 , V_27 , V_2 -> V_25 -> V_26 ) ) {
F_13 ( L_4 ) ;
return - V_28 ;
}
V_2 -> V_20 = V_20 ;
V_2 -> V_29 = V_19 -> V_30 ;
if ( F_15 ( V_2 , sizeof( struct V_31 ) ) < 0 ) {
F_13 ( V_32 L_5 ) ;
return - V_33 ;
}
V_13 -> V_15 = V_17 -> V_22 [ 1 ] ;
V_21 = F_16 ( V_2 , 1 ) ;
if ( V_21 )
return V_21 ;
V_6 = V_2 -> V_34 ;
V_6 -> V_35 = NULL ;
V_6 -> V_36 = ( 0x1 << V_37 ) - 1 ;
V_6 -> V_38 = & V_39 ;
V_6 -> type = V_40 ;
V_6 -> V_41 = V_42 | V_43 ;
V_6 -> V_44 = V_4 ;
V_6 -> V_45 = & F_6 ;
V_6 -> V_46 = & F_10 ;
F_1 ( V_2 ) ;
F_13 ( V_23 L_6 ) ;
return 1 ;
}
static void F_17 ( struct V_1 * V_2 )
{
if ( V_2 -> V_20 )
F_18 ( V_2 -> V_20 , V_27 ) ;
}
