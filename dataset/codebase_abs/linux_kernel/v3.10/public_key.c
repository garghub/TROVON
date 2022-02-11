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
static int F_7 ( const struct V_1 * V_1 ,
const struct V_14 * V_15 )
{
const struct V_5 * V_16 = V_1 -> V_6 . V_7 ;
if ( ! V_16 -> V_10 -> V_17 )
return - V_18 ;
if ( V_15 -> V_19 != V_16 -> V_10 -> V_20 ) {
F_8 ( L_2 ,
V_15 -> V_19 , V_16 -> V_10 -> V_20 ) ;
return - V_21 ;
}
return V_16 -> V_10 -> V_17 ( V_16 , V_15 ) ;
}
