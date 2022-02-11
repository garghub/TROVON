static void F_1 ( const struct V_1 * V_2 ,
struct V_3 V_4 [ V_5 + 1 ] ,
const struct V_6 * V_7 )
{
const struct V_8 * V_9 = F_2 ( V_2 ) ;
const struct V_10 * V_11 = V_9 -> V_11 ;
if ( V_11 -> V_12 -> V_13 ( V_11 , & V_4 [ V_9 -> V_14 ] , & V_4 [ V_9 -> V_15 ] ) )
return;
V_4 [ V_16 ] . V_17 = V_18 ;
}
static int F_3 ( const struct V_19 * V_20 ,
const struct V_1 * V_2 ,
const struct V_21 * const V_22 [] )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_10 * V_11 ;
int V_23 ;
if ( V_22 [ V_24 ] == NULL ||
V_22 [ V_25 ] == NULL )
return - V_26 ;
V_11 = F_4 ( V_20 -> V_27 , V_22 [ V_24 ] ) ;
if ( F_5 ( V_11 ) ) {
if ( V_22 [ V_28 ] ) {
V_11 = F_6 ( V_20 -> V_29 ,
V_22 [ V_28 ] ) ;
}
if ( F_5 ( V_11 ) )
return F_7 ( V_11 ) ;
}
V_9 -> V_14 = F_8 ( F_9 ( V_22 [ V_25 ] ) ) ;
V_23 = F_10 ( V_9 -> V_14 ) ;
if ( V_23 < 0 )
return V_23 ;
if ( V_22 [ V_30 ] != NULL ) {
if ( ! ( V_11 -> V_31 & V_32 ) )
return - V_26 ;
V_9 -> V_15 = F_8 ( F_9 ( V_22 [ V_30 ] ) ) ;
V_23 = F_11 ( V_9 -> V_15 ) ;
if ( V_23 < 0 )
return V_23 ;
if ( V_9 -> V_15 == V_16 ) {
if ( V_11 -> V_33 != V_34 )
return - V_26 ;
} else if ( V_11 -> V_33 == V_34 )
return - V_26 ;
} else if ( V_11 -> V_31 & V_32 )
return - V_26 ;
V_23 = F_12 ( V_20 , V_11 , & V_9 -> V_35 ) ;
if ( V_23 < 0 )
return V_23 ;
V_9 -> V_11 = V_11 ;
return 0 ;
}
static void F_13 ( const struct V_19 * V_20 ,
const struct V_1 * V_2 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_14 ( V_20 , V_9 -> V_11 , & V_9 -> V_35 ) ;
}
static int F_15 ( struct V_36 * V_37 , const struct V_1 * V_2 )
{
const struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( F_16 ( V_37 , V_24 , V_9 -> V_11 -> V_38 ) )
goto V_39;
if ( F_17 ( V_37 , V_25 , F_18 ( V_9 -> V_14 ) ) )
goto V_39;
if ( V_9 -> V_11 -> V_31 & V_32 )
if ( F_17 ( V_37 , V_30 , F_18 ( V_9 -> V_15 ) ) )
goto V_39;
return 0 ;
V_39:
return - 1 ;
}
int T_1 F_19 ( void )
{
return F_20 ( & V_40 ) ;
}
void F_21 ( void )
{
F_22 ( & V_40 ) ;
}
