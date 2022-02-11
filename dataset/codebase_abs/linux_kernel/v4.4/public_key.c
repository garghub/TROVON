static void F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_1 = V_2 -> V_6 . V_7 [ V_8 ] ;
if ( V_1 )
F_2 ( V_4 , L_1 ,
V_9 [ V_1 -> V_10 ] , V_1 -> V_11 -> V_12 ) ;
}
void F_3 ( void * V_6 )
{
struct V_5 * V_1 = V_6 ;
int V_13 ;
if ( V_1 ) {
for ( V_13 = 0 ; V_13 < F_4 ( V_1 -> V_14 ) ; V_13 ++ )
F_5 ( V_1 -> V_14 [ V_13 ] ) ;
F_6 ( V_1 ) ;
}
}
int F_7 ( const struct V_5 * V_15 ,
const struct V_16 * V_17 )
{
const struct V_18 * V_11 ;
F_8 ( ! V_15 ) ;
F_8 ( ! V_15 -> V_14 [ 0 ] ) ;
F_8 ( ! V_15 -> V_14 [ 1 ] ) ;
F_8 ( ! V_17 ) ;
F_8 ( ! V_17 -> V_19 ) ;
F_8 ( ! V_17 -> V_14 [ 0 ] ) ;
V_11 = V_15 -> V_11 ;
if ( ! V_11 ) {
if ( V_15 -> V_20 >= V_21 )
return - V_22 ;
V_11 = V_20 [ V_15 -> V_20 ] ;
if ( ! V_11 )
return - V_22 ;
}
if ( ! V_11 -> V_23 )
return - V_24 ;
if ( V_17 -> V_25 != V_11 -> V_26 ) {
F_9 ( L_2 ,
V_17 -> V_25 , V_11 -> V_26 ) ;
return - V_27 ;
}
return V_11 -> V_23 ( V_15 , V_17 ) ;
}
static int F_10 ( const struct V_1 * V_1 ,
const struct V_16 * V_17 )
{
const struct V_5 * V_15 = V_1 -> V_6 . V_7 [ V_8 ] ;
return F_7 ( V_15 , V_17 ) ;
}
