struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
F_2 ( L_1 , V_3 -> V_5 ) ;
V_4 = F_3 ( V_3 ) ;
if ( ! V_4 )
return NULL ;
F_4 ( V_4 ) ;
F_5 ( V_4 , V_3 , 0 ) ;
V_4 -> V_6 = V_7 ;
F_6 ( V_4 ) ;
F_7 ( V_4 ) ;
if ( V_3 -> V_8 )
F_8 ( F_9 ( V_3 ) ) ;
F_10 ( V_4 ) ;
F_11 ( V_4 -> V_9 ) ;
return V_4 ;
}
int F_12 ( struct V_1 * V_4 )
{
struct V_10 * V_11 = V_4 -> V_9 ;
struct V_12 * V_13 ;
int V_14 , V_15 ;
F_2 ( L_2 ,
F_13 ( V_11 ) , V_11 -> V_16 ) ;
if ( ! ( F_14 ( & V_11 -> V_17 ) && F_14 ( & V_11 -> V_18 ) ) )
return - V_19 ;
V_13 = & V_4 -> V_20 ;
if ( V_13 -> V_21 & V_22 ) {
V_14 = F_15 ( V_11 ) ;
if ( V_14 ) {
F_16 ( V_23 L_3 ,
V_24 , V_11 -> V_25 ) ;
return 1 ;
}
}
V_4 -> V_9 = NULL ;
F_17 ( V_11 ) ;
F_18 ( V_11 -> V_26 ) ;
if ( V_13 -> V_21 & V_22 )
F_19 ( V_13 ) ;
for ( V_15 = 0 ; V_15 < 3 ; ++ V_15 ) {
V_13 = & V_4 -> V_27 [ V_15 ] ;
if ( ! ( V_13 -> V_21 & V_28 ) )
continue;
F_19 ( V_13 ) ;
}
F_20 ( V_4 ) ;
return 0 ;
}
