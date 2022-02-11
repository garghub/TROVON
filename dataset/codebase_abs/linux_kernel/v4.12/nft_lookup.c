static void F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
const struct V_7 * V_8 = F_2 ( V_2 ) ;
const struct V_9 * V_10 = V_8 -> V_10 ;
const struct V_11 * V_12 ;
bool V_13 ;
V_13 = V_10 -> V_14 -> V_15 ( F_3 ( V_6 ) , V_10 , & V_4 -> V_16 [ V_8 -> V_17 ] ,
& V_12 ) ^ V_8 -> V_18 ;
if ( ! V_13 ) {
V_4 -> V_19 . V_20 = V_21 ;
return;
}
if ( V_10 -> V_22 & V_23 )
F_4 ( & V_4 -> V_16 [ V_8 -> V_24 ] ,
F_5 ( V_12 ) , V_10 -> V_25 ) ;
}
static int F_6 ( const struct V_26 * V_27 ,
const struct V_1 * V_2 ,
const struct V_28 * const V_29 [] )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
T_1 V_30 = F_7 ( V_27 -> V_31 ) ;
struct V_9 * V_10 ;
T_2 V_22 ;
int V_32 ;
if ( V_29 [ V_33 ] == NULL ||
V_29 [ V_34 ] == NULL )
return - V_35 ;
V_10 = F_8 ( V_27 -> V_31 , V_27 -> V_36 , V_29 [ V_33 ] ,
V_29 [ V_37 ] , V_30 ) ;
if ( F_9 ( V_10 ) )
return F_10 ( V_10 ) ;
if ( V_10 -> V_22 & V_38 )
return - V_39 ;
V_8 -> V_17 = F_11 ( V_29 [ V_34 ] ) ;
V_32 = F_12 ( V_8 -> V_17 , V_10 -> V_40 ) ;
if ( V_32 < 0 )
return V_32 ;
if ( V_29 [ V_41 ] ) {
V_22 = F_13 ( F_14 ( V_29 [ V_41 ] ) ) ;
if ( V_22 & ~ V_42 )
return - V_35 ;
if ( V_22 & V_42 ) {
if ( V_10 -> V_22 & V_23 )
return - V_35 ;
V_8 -> V_18 = true ;
}
}
if ( V_29 [ V_43 ] != NULL ) {
if ( V_8 -> V_18 )
return - V_35 ;
if ( ! ( V_10 -> V_22 & V_23 ) )
return - V_35 ;
V_8 -> V_24 = F_11 ( V_29 [ V_43 ] ) ;
V_32 = F_15 ( V_27 , V_8 -> V_24 , NULL ,
V_10 -> V_44 , V_10 -> V_25 ) ;
if ( V_32 < 0 )
return V_32 ;
} else if ( V_10 -> V_22 & V_23 )
return - V_35 ;
V_8 -> V_45 . V_22 = V_10 -> V_22 & V_23 ;
V_32 = F_16 ( V_27 , V_10 , & V_8 -> V_45 ) ;
if ( V_32 < 0 )
return V_32 ;
V_8 -> V_10 = V_10 ;
return 0 ;
}
static void F_17 ( const struct V_26 * V_27 ,
const struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
F_18 ( V_27 , V_8 -> V_10 , & V_8 -> V_45 ) ;
}
static int F_19 ( struct V_46 * V_47 , const struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_2 ( V_2 ) ;
T_2 V_22 = V_8 -> V_18 ? V_42 : 0 ;
if ( F_20 ( V_47 , V_33 , V_8 -> V_10 -> V_48 ) )
goto V_49;
if ( F_21 ( V_47 , V_34 , V_8 -> V_17 ) )
goto V_49;
if ( V_8 -> V_10 -> V_22 & V_23 )
if ( F_21 ( V_47 , V_43 , V_8 -> V_24 ) )
goto V_49;
if ( F_22 ( V_47 , V_41 , F_23 ( V_22 ) ) )
goto V_49;
return 0 ;
V_49:
return - 1 ;
}
