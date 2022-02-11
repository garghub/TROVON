static void F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
const struct V_7 * V_8 = F_2 ( V_2 ) ;
F_3 ( V_6 -> V_9 , V_6 -> V_10 , V_6 -> V_11 , V_6 -> V_12 , V_6 -> V_13 ,
V_6 -> V_14 , & V_8 -> V_15 , L_1 , V_8 -> V_16 ) ;
}
static int F_4 ( const struct V_17 * V_18 ,
const struct V_1 * V_2 ,
const struct V_19 * const V_20 [] )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_21 * V_22 = & V_8 -> V_15 ;
const struct V_19 * V_23 ;
int V_24 ;
V_22 -> type = V_25 ;
if ( V_20 [ V_26 ] != NULL &&
V_20 [ V_27 ] != NULL )
return - V_28 ;
if ( V_20 [ V_27 ] != NULL )
V_22 -> type = V_29 ;
V_23 = V_20 [ V_30 ] ;
if ( V_23 != NULL ) {
V_8 -> V_16 = F_5 ( F_6 ( V_23 ) + 1 , V_31 ) ;
if ( V_8 -> V_16 == NULL )
return - V_32 ;
F_7 ( V_8 -> V_16 , V_23 , F_6 ( V_23 ) + 1 ) ;
} else {
V_8 -> V_16 = ( char * ) V_33 ;
}
switch ( V_22 -> type ) {
case V_25 :
if ( V_20 [ V_26 ] != NULL ) {
V_22 -> V_34 . log . V_35 =
F_8 ( F_9 ( V_20 [ V_26 ] ) ) ;
} else {
V_22 -> V_34 . log . V_35 = V_36 ;
}
if ( V_22 -> V_34 . log . V_35 > V_37 ) {
V_24 = - V_28 ;
goto V_38;
}
if ( V_20 [ V_39 ] != NULL ) {
V_22 -> V_34 . log . V_40 =
F_8 ( F_9 ( V_20 [ V_39 ] ) ) ;
}
break;
case V_29 :
V_22 -> V_34 . V_41 . V_42 = F_10 ( F_11 ( V_20 [ V_27 ] ) ) ;
if ( V_20 [ V_43 ] != NULL ) {
V_22 -> V_34 . V_41 . V_44 |= V_45 ;
V_22 -> V_34 . V_41 . V_46 =
F_8 ( F_9 ( V_20 [ V_43 ] ) ) ;
}
if ( V_20 [ V_47 ] != NULL ) {
V_22 -> V_34 . V_41 . V_48 =
F_10 ( F_11 ( V_20 [ V_47 ] ) ) ;
}
break;
}
V_24 = F_12 ( V_18 -> V_49 -> V_50 , V_22 -> type ) ;
if ( V_24 < 0 )
goto V_38;
return 0 ;
V_38:
if ( V_8 -> V_16 != V_33 )
F_13 ( V_8 -> V_16 ) ;
return V_24 ;
}
static void F_14 ( const struct V_17 * V_18 ,
const struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_21 * V_22 = & V_8 -> V_15 ;
if ( V_8 -> V_16 != V_33 )
F_13 ( V_8 -> V_16 ) ;
F_15 ( V_18 -> V_49 -> V_50 , V_22 -> type ) ;
}
static int F_16 ( struct V_51 * V_12 , const struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_2 ( V_2 ) ;
const struct V_21 * V_22 = & V_8 -> V_15 ;
if ( V_8 -> V_16 != V_33 )
if ( F_17 ( V_12 , V_30 , V_8 -> V_16 ) )
goto V_52;
switch ( V_22 -> type ) {
case V_25 :
if ( F_18 ( V_12 , V_26 , F_19 ( V_22 -> V_34 . log . V_35 ) ) )
goto V_52;
if ( V_22 -> V_34 . log . V_40 ) {
if ( F_18 ( V_12 , V_39 ,
F_19 ( V_22 -> V_34 . log . V_40 ) ) )
goto V_52;
}
break;
case V_29 :
if ( F_20 ( V_12 , V_27 , F_21 ( V_22 -> V_34 . V_41 . V_42 ) ) )
goto V_52;
if ( V_22 -> V_34 . V_41 . V_44 & V_45 ) {
if ( F_18 ( V_12 , V_43 ,
F_19 ( V_22 -> V_34 . V_41 . V_46 ) ) )
goto V_52;
}
if ( V_22 -> V_34 . V_41 . V_48 ) {
if ( F_20 ( V_12 , V_47 ,
F_21 ( V_22 -> V_34 . V_41 . V_48 ) ) )
goto V_52;
}
break;
}
return 0 ;
V_52:
return - 1 ;
}
static int T_1 F_22 ( void )
{
return F_23 ( & V_53 ) ;
}
static void T_2 F_24 ( void )
{
F_25 ( & V_53 ) ;
}
