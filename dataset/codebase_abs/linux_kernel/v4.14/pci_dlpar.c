struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
F_2 ( L_1 , V_3 ) ;
V_4 = F_3 ( V_3 ) ;
if ( ! V_4 )
return NULL ;
F_4 ( V_4 ) ;
F_5 ( V_4 , V_3 , 0 ) ;
V_4 -> V_5 = V_6 ;
F_6 ( V_4 ) ;
F_7 ( V_4 ) ;
if ( V_3 -> V_7 )
F_8 ( F_9 ( V_3 ) ) ;
F_10 ( V_4 ) ;
F_11 ( V_4 -> V_8 ) ;
return V_4 ;
}
int F_12 ( struct V_1 * V_4 )
{
struct V_9 * V_10 = V_4 -> V_8 ;
struct V_11 * V_12 ;
int V_13 , V_14 ;
F_2 ( L_2 ,
F_13 ( V_10 ) , V_10 -> V_15 ) ;
if ( ! ( F_14 ( & V_10 -> V_16 ) && F_14 ( & V_10 -> V_17 ) ) )
return - V_18 ;
V_12 = & V_4 -> V_19 ;
if ( V_12 -> V_20 & V_21 ) {
V_13 = F_15 ( V_10 ) ;
if ( V_13 ) {
F_16 ( V_22 L_3 ,
V_23 , V_10 -> V_24 ) ;
return 1 ;
}
}
V_4 -> V_8 = NULL ;
F_17 ( V_10 ) ;
F_18 ( V_10 -> V_25 ) ;
if ( V_12 -> V_20 & V_21 )
F_19 ( V_12 ) ;
for ( V_14 = 0 ; V_14 < 3 ; ++ V_14 ) {
V_12 = & V_4 -> V_26 [ V_14 ] ;
if ( ! ( V_12 -> V_20 & V_27 ) )
continue;
F_19 ( V_12 ) ;
}
return 0 ;
}
