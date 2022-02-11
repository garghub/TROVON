static void F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
const struct V_7 * V_8 = F_2 ( V_2 ) ;
F_3 ( F_4 ( V_6 ) , F_5 ( V_6 ) , F_6 ( V_6 ) , V_6 -> V_9 ,
F_7 ( V_6 ) , F_8 ( V_6 ) , & V_8 -> V_10 , L_1 ,
V_8 -> V_11 ) ;
}
static int F_9 ( const struct V_12 * V_13 ,
const struct V_1 * V_2 ,
const struct V_14 * const V_15 [] )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_16 * V_17 = & V_8 -> V_10 ;
const struct V_14 * V_18 ;
int V_19 ;
V_17 -> type = V_20 ;
if ( V_15 [ V_21 ] != NULL &&
V_15 [ V_22 ] != NULL )
return - V_23 ;
if ( V_15 [ V_22 ] != NULL ) {
V_17 -> type = V_24 ;
if ( V_15 [ V_25 ] != NULL )
return - V_23 ;
}
V_18 = V_15 [ V_26 ] ;
if ( V_18 != NULL ) {
V_8 -> V_11 = F_10 ( F_11 ( V_18 ) + 1 , V_27 ) ;
if ( V_8 -> V_11 == NULL )
return - V_28 ;
F_12 ( V_8 -> V_11 , V_18 , F_11 ( V_18 ) + 1 ) ;
} else {
V_8 -> V_11 = ( char * ) V_29 ;
}
switch ( V_17 -> type ) {
case V_20 :
if ( V_15 [ V_21 ] != NULL ) {
V_17 -> V_30 . log . V_31 =
F_13 ( F_14 ( V_15 [ V_21 ] ) ) ;
} else {
V_17 -> V_30 . log . V_31 = V_32 ;
}
if ( V_17 -> V_30 . log . V_31 > V_33 ) {
V_19 = - V_23 ;
goto V_34;
}
if ( V_15 [ V_25 ] != NULL ) {
V_17 -> V_30 . log . V_35 =
F_13 ( F_14 ( V_15 [ V_25 ] ) ) ;
if ( V_17 -> V_30 . log . V_35 & ~ V_36 ) {
V_19 = - V_23 ;
goto V_34;
}
}
break;
case V_24 :
V_17 -> V_30 . V_37 . V_38 = F_15 ( F_16 ( V_15 [ V_22 ] ) ) ;
if ( V_15 [ V_39 ] != NULL ) {
V_17 -> V_30 . V_37 . V_40 |= V_41 ;
V_17 -> V_30 . V_37 . V_42 =
F_13 ( F_14 ( V_15 [ V_39 ] ) ) ;
}
if ( V_15 [ V_43 ] != NULL ) {
V_17 -> V_30 . V_37 . V_44 =
F_15 ( F_16 ( V_15 [ V_43 ] ) ) ;
}
break;
}
V_19 = F_17 ( V_13 -> V_45 -> V_46 , V_17 -> type ) ;
if ( V_19 < 0 )
goto V_34;
return 0 ;
V_34:
if ( V_8 -> V_11 != V_29 )
F_18 ( V_8 -> V_11 ) ;
return V_19 ;
}
static void F_19 ( const struct V_12 * V_13 ,
const struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_16 * V_17 = & V_8 -> V_10 ;
if ( V_8 -> V_11 != V_29 )
F_18 ( V_8 -> V_11 ) ;
F_20 ( V_13 -> V_45 -> V_46 , V_17 -> type ) ;
}
static int F_21 ( struct V_47 * V_9 , const struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_2 ( V_2 ) ;
const struct V_16 * V_17 = & V_8 -> V_10 ;
if ( V_8 -> V_11 != V_29 )
if ( F_22 ( V_9 , V_26 , V_8 -> V_11 ) )
goto V_48;
switch ( V_17 -> type ) {
case V_20 :
if ( F_23 ( V_9 , V_21 , F_24 ( V_17 -> V_30 . log . V_31 ) ) )
goto V_48;
if ( V_17 -> V_30 . log . V_35 ) {
if ( F_23 ( V_9 , V_25 ,
F_24 ( V_17 -> V_30 . log . V_35 ) ) )
goto V_48;
}
break;
case V_24 :
if ( F_25 ( V_9 , V_22 , F_26 ( V_17 -> V_30 . V_37 . V_38 ) ) )
goto V_48;
if ( V_17 -> V_30 . V_37 . V_40 & V_41 ) {
if ( F_23 ( V_9 , V_39 ,
F_24 ( V_17 -> V_30 . V_37 . V_42 ) ) )
goto V_48;
}
if ( V_17 -> V_30 . V_37 . V_44 ) {
if ( F_25 ( V_9 , V_43 ,
F_26 ( V_17 -> V_30 . V_37 . V_44 ) ) )
goto V_48;
}
break;
}
return 0 ;
V_48:
return - 1 ;
}
static int T_1 F_27 ( void )
{
return F_28 ( & V_49 ) ;
}
static void T_2 F_29 ( void )
{
F_30 ( & V_49 ) ;
}
