static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , struct V_3 * V_7 )
{
const struct V_8 * V_9 = F_2 ( V_2 ) ;
const struct V_10 * V_11 = F_3 ( V_2 ) ;
const struct V_12 * V_13 ;
if ( V_11 -> V_14 != V_15 ||
V_11 -> V_16 != V_15 ||
V_11 -> V_17 != V_18 )
goto V_19;
if ( V_9 -> V_20 [ 5 ] >= V_21 && V_9 -> V_20 [ 5 ] <= V_22 ) {
V_13 = F_4 ( V_23 [ V_9 -> V_20 [ 5 ] -
V_21 ] ) ;
if ( V_13 &&
F_5 ( V_9 -> V_20 , V_13 -> V_24 ) )
goto V_19;
} else
V_13 = F_4 ( V_12 ) ;
if ( ! V_13 )
goto V_19;
V_13 -> V_25 ( V_13 , V_2 , V_4 ) ;
return 0 ;
V_19:
F_6 ( V_2 ) ;
return 0 ;
}
int F_7 ( const struct V_12 * V_13 )
{
int V_19 = 0 ;
F_8 ( & V_26 ) ;
if ( V_27 ++ == 0 ) {
V_28 = F_9 ( V_15 , F_1 ) ;
if ( ! V_28 ) {
V_19 = - V_29 ;
goto V_30;
}
}
if ( F_10 ( V_13 -> V_24 ) )
F_11 ( V_12 , V_13 ) ;
else
F_11 ( V_23 [ V_13 -> V_24 [ 5 ] -
V_21 ] , V_13 ) ;
V_30:
F_12 ( & V_26 ) ;
return V_19 ;
}
void F_13 ( const struct V_12 * V_13 )
{
F_8 ( & V_26 ) ;
if ( F_10 ( V_13 -> V_24 ) )
F_14 ( V_12 , NULL ) ;
else
F_14 ( V_23 [ V_13 -> V_24 [ 5 ] -
V_21 ] , NULL ) ;
F_15 () ;
if ( -- V_27 == 0 )
F_16 ( V_28 ) ;
F_12 ( & V_26 ) ;
}
