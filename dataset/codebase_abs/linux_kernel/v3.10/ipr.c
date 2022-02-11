static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
return F_3 ( V_5 , struct V_1 , V_5 ) ;
}
static void F_4 ( struct V_2 * V_3 )
{
struct V_6 * V_7 = F_5 ( V_3 ) ;
unsigned long V_8 = F_1 ( V_3 ) -> V_9 [ V_7 -> V_10 ] ;
F_6 ( F_7 ( V_8 ) & ( 0xffff ^ ( 0xf << V_7 -> V_11 ) ) , V_8 ) ;
( void ) F_7 ( V_8 ) ;
}
static void F_8 ( struct V_2 * V_3 )
{
struct V_6 * V_7 = F_5 ( V_3 ) ;
unsigned long V_8 = F_1 ( V_3 ) -> V_9 [ V_7 -> V_10 ] ;
F_6 ( F_7 ( V_8 ) | ( V_7 -> V_12 << V_7 -> V_11 ) , V_8 ) ;
}
void F_9 ( struct V_1 * V_13 )
{
int V_14 ;
V_13 -> V_5 . V_15 = F_4 ;
V_13 -> V_5 . V_16 = F_8 ;
for ( V_14 = 0 ; V_14 < V_13 -> V_17 ; V_14 ++ ) {
struct V_6 * V_7 = V_13 -> V_6 + V_14 ;
int V_18 ;
F_10 ( V_7 -> V_10 >= V_13 -> V_19 ) ;
F_10 ( ! V_13 -> V_9 [ V_7 -> V_10 ] ) ;
V_18 = F_11 ( V_7 -> V_20 , F_12 () ) ;
if ( F_13 ( V_18 != V_7 -> V_20 && V_18 != - V_21 ) ) {
F_14 ( V_22 L_1 ,
V_7 -> V_20 ) ;
continue;
}
F_15 ( V_7 -> V_20 ) ;
F_16 ( V_7 -> V_20 , & V_13 -> V_5 ,
V_23 , L_2 ) ;
F_17 ( V_7 -> V_20 , V_7 ) ;
F_4 ( F_18 ( V_7 -> V_20 ) ) ;
}
}
