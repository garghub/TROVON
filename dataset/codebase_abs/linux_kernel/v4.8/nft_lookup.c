static void F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
const struct V_7 * V_8 = F_2 ( V_2 ) ;
const struct V_9 * V_10 = V_8 -> V_10 ;
const struct V_11 * V_12 ;
bool V_13 ;
V_13 = V_10 -> V_14 -> V_15 ( V_6 -> V_16 , V_10 , & V_4 -> V_17 [ V_8 -> V_18 ] , & V_12 ) ^
V_8 -> V_19 ;
if ( ! V_13 ) {
V_4 -> V_20 . V_21 = V_22 ;
return;
}
if ( V_13 && V_10 -> V_23 & V_24 )
F_3 ( & V_4 -> V_17 [ V_8 -> V_25 ] ,
F_4 ( V_12 ) , V_10 -> V_26 ) ;
}
static int F_5 ( const struct V_27 * V_28 ,
const struct V_1 * V_2 ,
const struct V_29 * const V_30 [] )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
T_1 V_31 = F_6 ( V_28 -> V_16 ) ;
struct V_9 * V_10 ;
T_2 V_23 ;
int V_32 ;
if ( V_30 [ V_33 ] == NULL ||
V_30 [ V_34 ] == NULL )
return - V_35 ;
V_10 = F_7 ( V_28 -> V_36 , V_30 [ V_33 ] , V_31 ) ;
if ( F_8 ( V_10 ) ) {
if ( V_30 [ V_37 ] ) {
V_10 = F_9 ( V_28 -> V_16 ,
V_30 [ V_37 ] ,
V_31 ) ;
}
if ( F_8 ( V_10 ) )
return F_10 ( V_10 ) ;
}
if ( V_10 -> V_23 & V_38 )
return - V_39 ;
V_8 -> V_18 = F_11 ( V_30 [ V_34 ] ) ;
V_32 = F_12 ( V_8 -> V_18 , V_10 -> V_40 ) ;
if ( V_32 < 0 )
return V_32 ;
if ( V_30 [ V_41 ] ) {
V_23 = F_13 ( F_14 ( V_30 [ V_41 ] ) ) ;
if ( V_23 & ~ V_42 )
return - V_35 ;
if ( V_23 & V_42 ) {
if ( V_10 -> V_23 & V_24 )
return - V_35 ;
V_8 -> V_19 = true ;
}
}
if ( V_30 [ V_43 ] != NULL ) {
if ( V_8 -> V_19 )
return - V_35 ;
if ( ! ( V_10 -> V_23 & V_24 ) )
return - V_35 ;
V_8 -> V_25 = F_11 ( V_30 [ V_43 ] ) ;
V_32 = F_15 ( V_28 , V_8 -> V_25 , NULL ,
V_10 -> V_44 , V_10 -> V_26 ) ;
if ( V_32 < 0 )
return V_32 ;
} else if ( V_10 -> V_23 & V_24 )
return - V_35 ;
V_8 -> V_45 . V_23 = V_10 -> V_23 & V_24 ;
V_32 = F_16 ( V_28 , V_10 , & V_8 -> V_45 ) ;
if ( V_32 < 0 )
return V_32 ;
V_8 -> V_10 = V_10 ;
return 0 ;
}
static void F_17 ( const struct V_27 * V_28 ,
const struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
F_18 ( V_28 , V_8 -> V_10 , & V_8 -> V_45 ) ;
}
static int F_19 ( struct V_46 * V_47 , const struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_2 ( V_2 ) ;
T_2 V_23 = V_8 -> V_19 ? V_42 : 0 ;
if ( F_20 ( V_47 , V_33 , V_8 -> V_10 -> V_48 ) )
goto V_49;
if ( F_21 ( V_47 , V_34 , V_8 -> V_18 ) )
goto V_49;
if ( V_8 -> V_10 -> V_23 & V_24 )
if ( F_21 ( V_47 , V_43 , V_8 -> V_25 ) )
goto V_49;
if ( F_22 ( V_47 , V_41 , F_23 ( V_23 ) ) )
goto V_49;
return 0 ;
V_49:
return - 1 ;
}
int T_3 F_24 ( void )
{
return F_25 ( & V_50 ) ;
}
void F_26 ( void )
{
F_27 ( & V_50 ) ;
}
