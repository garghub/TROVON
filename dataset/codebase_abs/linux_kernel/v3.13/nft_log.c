static void F_1 ( const struct V_1 * V_2 ,
struct V_3 V_4 [ V_5 + 1 ] ,
const struct V_6 * V_7 )
{
const struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_10 * V_10 = F_3 ( V_7 -> V_11 ? V_7 -> V_11 : V_7 -> V_12 ) ;
F_4 ( V_10 , V_9 -> V_13 , V_7 -> V_14 , V_7 -> V_15 , V_7 -> V_11 ,
V_7 -> V_12 , & V_9 -> V_16 , L_1 , V_9 -> V_17 ) ;
}
static int F_5 ( const struct V_18 * V_19 ,
const struct V_1 * V_2 ,
const struct V_20 * const V_21 [] )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_22 * V_23 = & V_9 -> V_16 ;
const struct V_20 * V_24 ;
V_9 -> V_13 = V_19 -> V_25 -> V_13 ;
V_24 = V_21 [ V_26 ] ;
if ( V_24 != NULL ) {
V_9 -> V_17 = F_6 ( F_7 ( V_24 ) + 1 , V_27 ) ;
if ( V_9 -> V_17 == NULL )
return - V_28 ;
F_8 ( V_9 -> V_17 , V_24 , F_7 ( V_24 ) + 1 ) ;
} else
V_9 -> V_17 = ( char * ) V_29 ;
V_23 -> type = V_30 ;
if ( V_21 [ V_31 ] != NULL )
V_23 -> V_32 . V_33 . V_34 = F_9 ( F_10 ( V_21 [ V_31 ] ) ) ;
if ( V_21 [ V_35 ] != NULL )
V_23 -> V_32 . V_33 . V_36 = F_11 ( F_12 ( V_21 [ V_35 ] ) ) ;
if ( V_21 [ V_37 ] != NULL ) {
V_23 -> V_32 . V_33 . V_38 =
F_9 ( F_10 ( V_21 [ V_37 ] ) ) ;
}
return 0 ;
}
static void F_13 ( const struct V_1 * V_2 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_9 -> V_17 != V_29 )
F_14 ( V_9 -> V_17 ) ;
}
static int F_15 ( struct V_39 * V_15 , const struct V_1 * V_2 )
{
const struct V_8 * V_9 = F_2 ( V_2 ) ;
const struct V_22 * V_23 = & V_9 -> V_16 ;
if ( V_9 -> V_17 != V_29 )
if ( F_16 ( V_15 , V_26 , V_9 -> V_17 ) )
goto V_40;
if ( V_23 -> V_32 . V_33 . V_34 )
if ( F_17 ( V_15 , V_31 , F_18 ( V_23 -> V_32 . V_33 . V_34 ) ) )
goto V_40;
if ( V_23 -> V_32 . V_33 . V_36 )
if ( F_19 ( V_15 , V_35 ,
F_20 ( V_23 -> V_32 . V_33 . V_36 ) ) )
goto V_40;
if ( V_23 -> V_32 . V_33 . V_38 )
if ( F_17 ( V_15 , V_37 ,
F_18 ( V_23 -> V_32 . V_33 . V_38 ) ) )
goto V_40;
return 0 ;
V_40:
return - 1 ;
}
static int T_1 F_21 ( void )
{
return F_22 ( & V_41 ) ;
}
static void T_2 F_23 ( void )
{
F_24 ( & V_41 ) ;
}
