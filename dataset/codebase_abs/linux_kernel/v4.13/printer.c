static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_4 ;
int V_6 = 0 ;
F_2 ( V_4 ) ;
F_3 ( V_4 ) ;
if ( F_4 ( V_4 ) ) {
V_7 . V_8 = V_9 ;
V_7 . V_10 |= V_11 ;
}
V_12 = F_5 ( V_13 ) ;
if ( F_6 ( V_12 ) )
return F_7 ( V_12 ) ;
V_6 = F_8 ( V_2 , V_12 ) ;
if ( V_6 < 0 )
F_9 ( V_12 ) ;
return V_6 ;
}
static int F_10 ( struct V_14 * V_5 )
{
struct V_15 * V_16 ;
int V_17 ;
V_13 = F_11 ( L_1 ) ;
if ( F_6 ( V_13 ) )
return F_7 ( V_13 ) ;
V_16 = F_12 ( V_13 , struct V_15 , V_18 ) ;
V_16 -> V_19 = 0 ;
V_16 -> V_20 = V_21 ;
if ( V_22 ) {
V_16 -> V_23 = F_13 ( V_22 , V_24 ) ;
if ( ! V_16 -> V_23 ) {
V_17 = - V_25 ;
goto V_26;
}
V_16 -> V_27 = true ;
} else {
V_16 -> V_23 = V_23 ;
}
V_17 = F_14 ( V_5 , V_28 ) ;
if ( V_17 < 0 )
goto V_26;
V_29 . V_30 = V_28 [ V_31 ] . V_32 ;
V_29 . V_33 = V_28 [ V_34 ] . V_32 ;
V_29 . V_35 = V_28 [ V_36 ] . V_32 ;
if ( F_4 ( V_5 -> V_4 ) && ! V_9 [ 0 ] ) {
struct V_37 * V_38 ;
V_38 = F_15 ( V_5 -> V_4 ) ;
if ( ! V_38 ) {
V_17 = - V_25 ;
goto V_26;
}
F_16 ( V_5 -> V_4 , V_38 ) ;
V_9 [ 0 ] = V_38 ;
V_9 [ 1 ] = NULL ;
}
V_17 = F_17 ( V_5 , & V_7 , F_1 ) ;
if ( V_17 )
goto V_39;
F_18 ( V_5 , & V_40 ) ;
return V_17 ;
V_39:
F_19 ( V_9 [ 0 ] ) ;
V_9 [ 0 ] = NULL ;
V_26:
F_20 ( V_13 ) ;
return V_17 ;
}
static int F_21 ( struct V_14 * V_5 )
{
F_9 ( V_12 ) ;
F_20 ( V_13 ) ;
F_19 ( V_9 [ 0 ] ) ;
V_9 [ 0 ] = NULL ;
return 0 ;
}
