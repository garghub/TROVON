static void F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
const struct V_7 * V_8 = F_2 ( V_2 ) ;
const struct V_9 * V_10 = V_8 -> V_10 ;
const struct V_11 * V_12 ;
if ( V_10 -> V_13 -> V_14 ( V_10 , & V_4 -> V_15 [ V_8 -> V_16 ] , & V_12 ) ) {
if ( V_10 -> V_17 & V_18 )
F_3 ( & V_4 -> V_15 [ V_8 -> V_19 ] ,
F_4 ( V_12 ) , V_10 -> V_20 ) ;
return;
}
V_4 -> V_21 . V_22 = V_23 ;
}
static int F_5 ( const struct V_24 * V_25 ,
const struct V_1 * V_2 ,
const struct V_26 * const V_27 [] )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 ;
int V_28 ;
if ( V_27 [ V_29 ] == NULL ||
V_27 [ V_30 ] == NULL )
return - V_31 ;
V_10 = F_6 ( V_25 -> V_32 , V_27 [ V_29 ] ) ;
if ( F_7 ( V_10 ) ) {
if ( V_27 [ V_33 ] ) {
V_10 = F_8 ( V_25 -> V_34 ,
V_27 [ V_33 ] ) ;
}
if ( F_7 ( V_10 ) )
return F_9 ( V_10 ) ;
}
if ( V_10 -> V_17 & V_35 )
return - V_36 ;
V_8 -> V_16 = F_10 ( V_27 [ V_30 ] ) ;
V_28 = F_11 ( V_8 -> V_16 , V_10 -> V_37 ) ;
if ( V_28 < 0 )
return V_28 ;
if ( V_27 [ V_38 ] != NULL ) {
if ( ! ( V_10 -> V_17 & V_18 ) )
return - V_31 ;
V_8 -> V_19 = F_10 ( V_27 [ V_38 ] ) ;
V_28 = F_12 ( V_25 , V_8 -> V_19 , NULL ,
V_10 -> V_39 , V_10 -> V_20 ) ;
if ( V_28 < 0 )
return V_28 ;
} else if ( V_10 -> V_17 & V_18 )
return - V_31 ;
V_8 -> V_40 . V_17 = V_10 -> V_17 & V_18 ;
V_28 = F_13 ( V_25 , V_10 , & V_8 -> V_40 ) ;
if ( V_28 < 0 )
return V_28 ;
V_8 -> V_10 = V_10 ;
return 0 ;
}
static void F_14 ( const struct V_24 * V_25 ,
const struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
F_15 ( V_25 , V_8 -> V_10 , & V_8 -> V_40 ) ;
}
static int F_16 ( struct V_41 * V_42 , const struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( F_17 ( V_42 , V_29 , V_8 -> V_10 -> V_43 ) )
goto V_44;
if ( F_18 ( V_42 , V_30 , V_8 -> V_16 ) )
goto V_44;
if ( V_8 -> V_10 -> V_17 & V_18 )
if ( F_18 ( V_42 , V_38 , V_8 -> V_19 ) )
goto V_44;
return 0 ;
V_44:
return - 1 ;
}
int T_1 F_19 ( void )
{
return F_20 ( & V_45 ) ;
}
void F_21 ( void )
{
F_22 ( & V_45 ) ;
}
