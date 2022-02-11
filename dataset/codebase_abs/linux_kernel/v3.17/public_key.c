static void F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_1 = V_2 -> V_6 . V_7 ;
if ( V_1 )
F_2 ( V_4 , L_1 ,
V_8 [ V_1 -> V_9 ] , V_1 -> V_10 -> V_11 ) ;
}
void F_3 ( void * V_6 )
{
struct V_5 * V_1 = V_6 ;
int V_12 ;
if ( V_1 ) {
for ( V_12 = 0 ; V_12 < F_4 ( V_1 -> V_13 ) ; V_12 ++ )
F_5 ( V_1 -> V_13 [ V_12 ] ) ;
F_6 ( V_1 ) ;
}
}
int F_7 ( const struct V_5 * V_14 ,
const struct V_15 * V_16 )
{
const struct V_17 * V_10 ;
F_8 ( ! V_14 ) ;
F_8 ( ! V_14 -> V_13 [ 0 ] ) ;
F_8 ( ! V_14 -> V_13 [ 1 ] ) ;
F_8 ( ! V_16 ) ;
F_8 ( ! V_16 -> V_18 ) ;
F_8 ( ! V_16 -> V_13 [ 0 ] ) ;
V_10 = V_14 -> V_10 ;
if ( ! V_10 ) {
if ( V_14 -> V_19 >= V_20 )
return - V_21 ;
V_10 = V_19 [ V_14 -> V_19 ] ;
if ( ! V_10 )
return - V_21 ;
}
if ( ! V_10 -> V_22 )
return - V_23 ;
if ( V_16 -> V_24 != V_10 -> V_25 ) {
F_9 ( L_2 ,
V_16 -> V_24 , V_10 -> V_25 ) ;
return - V_26 ;
}
return V_10 -> V_22 ( V_14 , V_16 ) ;
}
static int F_10 ( const struct V_1 * V_1 ,
const struct V_15 * V_16 )
{
const struct V_5 * V_14 = V_1 -> V_6 . V_7 ;
return F_7 ( V_14 , V_16 ) ;
}
