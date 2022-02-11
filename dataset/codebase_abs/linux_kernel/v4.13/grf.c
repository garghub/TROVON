static int T_1 F_1 ( void )
{
const struct V_1 * V_2 ;
const struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
int V_9 , V_10 ;
V_6 = F_2 ( NULL , V_11 ,
& V_4 ) ;
if ( ! V_6 )
return - V_12 ;
if ( ! V_4 || ! V_4 -> V_13 ) {
F_3 ( L_1 , V_14 ) ;
return - V_15 ;
}
V_2 = V_4 -> V_13 ;
V_8 = F_4 ( V_6 ) ;
if ( F_5 ( V_8 ) ) {
F_3 ( L_2 , V_14 ) ;
return F_6 ( V_8 ) ;
}
for ( V_10 = 0 ; V_10 < V_2 -> V_16 ; V_10 ++ ) {
const struct V_17 * V_18 = & V_2 -> V_19 [ V_10 ] ;
F_7 ( L_3 , V_14 ,
V_18 -> V_20 , V_18 -> V_21 , V_18 -> V_18 ) ;
V_9 = F_8 ( V_8 , V_18 -> V_21 , V_18 -> V_18 ) ;
if ( V_9 < 0 )
F_3 ( L_4 ,
V_14 , V_18 -> V_21 , V_9 ) ;
}
return 0 ;
}
