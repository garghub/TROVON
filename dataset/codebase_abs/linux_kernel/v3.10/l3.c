static void F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < 8 ; V_4 ++ ) {
V_2 -> V_5 ( 0 ) ;
F_2 ( V_2 -> V_6 ) ;
V_2 -> V_7 ( V_3 & 1 ) ;
F_2 ( V_2 -> V_8 ) ;
V_2 -> V_5 ( 1 ) ;
F_2 ( V_2 -> V_9 ) ;
V_3 >>= 1 ;
}
}
static void F_3 ( struct V_1 * V_2 , const T_1 * V_10 ,
int V_11 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_11 ; V_4 ++ ) {
if ( V_4 ) {
F_2 ( V_2 -> V_12 ) ;
V_2 -> V_13 ( 0 ) ;
F_2 ( V_2 -> V_14 ) ;
}
V_2 -> V_13 ( 1 ) ;
F_2 ( V_2 -> V_15 ) ;
F_1 ( V_2 , V_10 [ V_4 ] ) ;
}
}
int F_4 ( struct V_1 * V_2 , T_1 V_16 , T_1 * V_17 , int V_11 )
{
V_2 -> V_5 ( 1 ) ;
V_2 -> V_7 ( 1 ) ;
V_2 -> V_13 ( 1 ) ;
F_2 ( V_2 -> V_14 ) ;
V_2 -> V_13 ( 0 ) ;
F_2 ( V_2 -> V_15 ) ;
F_1 ( V_2 , V_16 ) ;
F_2 ( V_2 -> V_12 ) ;
F_3 ( V_2 , V_17 , V_11 ) ;
V_2 -> V_5 ( 1 ) ;
V_2 -> V_7 ( 1 ) ;
V_2 -> V_13 ( 0 ) ;
return V_11 ;
}
