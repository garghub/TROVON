static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
if ( F_2 ( V_2 -> V_4 -> V_5 ) ) {
V_2 -> V_6 = V_7 ;
V_2 -> V_8 |= V_9 ;
}
V_10 = F_3 ( V_11 ) ;
if ( F_4 ( V_10 ) ) {
V_3 = F_5 ( V_10 ) ;
return V_3 ;
}
V_3 = F_6 ( V_2 , V_10 ) ;
if ( V_3 < 0 ) {
F_7 ( V_10 ) ;
return V_3 ;
}
return 0 ;
}
static int F_8 ( struct V_12 * V_4 )
{
struct V_13 * V_5 = V_4 -> V_5 ;
struct V_14 * V_15 ;
int V_3 ;
V_11 = F_9 ( L_1 ) ;
if ( F_4 ( V_11 ) )
return F_5 ( V_11 ) ;
V_15 = F_10 ( V_11 , struct V_14 , V_16 ) ;
F_11 ( V_15 -> V_17 , V_18 ) ;
if ( ! F_12 ( V_15 -> V_17 , V_19 ) )
F_13 ( L_2 , V_19 ) ;
if ( ! F_14 ( V_15 -> V_17 , V_20 ) )
F_13 ( L_3 , V_20 ) ;
V_3 = F_15 ( V_4 , V_21 ) ;
if ( V_3 < 0 )
goto V_22;
V_23 . V_24 = V_21 [ V_25 ] . V_26 ;
V_23 . V_27 = V_21 [ V_28 ] . V_26 ;
if ( F_2 ( V_5 ) && ! V_7 [ 0 ] ) {
struct V_29 * V_30 ;
V_30 = F_16 ( V_5 ) ;
if ( ! V_30 )
goto V_22;
F_17 ( V_5 , V_30 ) ;
V_7 [ 0 ] = V_30 ;
V_7 [ 1 ] = NULL ;
}
V_3 = F_18 ( V_4 , & V_31 ,
F_1 ) ;
if ( V_3 < 0 )
goto V_32;
F_19 ( V_4 , & V_33 ) ;
F_20 ( & V_5 -> V_34 , L_4 , V_35 ) ;
return 0 ;
V_32:
F_21 ( V_7 [ 0 ] ) ;
V_7 [ 0 ] = NULL ;
V_22:
F_22 ( V_11 ) ;
return V_3 ;
}
static int F_23 ( struct V_12 * V_4 )
{
if ( ! F_24 ( V_10 ) )
F_7 ( V_10 ) ;
if ( ! F_24 ( V_11 ) )
F_22 ( V_11 ) ;
F_21 ( V_7 [ 0 ] ) ;
V_7 [ 0 ] = NULL ;
return 0 ;
}
