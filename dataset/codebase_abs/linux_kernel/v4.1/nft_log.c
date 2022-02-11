static void F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
const struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_9 = F_3 ( V_6 -> V_10 ? V_6 -> V_10 : V_6 -> V_11 ) ;
F_4 ( V_9 , V_6 -> V_12 -> V_13 , V_6 -> V_12 -> V_14 , V_6 -> V_15 , V_6 -> V_10 ,
V_6 -> V_11 , & V_8 -> V_16 , L_1 , V_8 -> V_17 ) ;
}
static int F_5 ( const struct V_18 * V_19 ,
const struct V_1 * V_2 ,
const struct V_20 * const V_21 [] )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_22 * V_23 = & V_8 -> V_16 ;
const struct V_20 * V_24 ;
int V_25 ;
V_24 = V_21 [ V_26 ] ;
if ( V_24 != NULL ) {
V_8 -> V_17 = F_6 ( F_7 ( V_24 ) + 1 , V_27 ) ;
if ( V_8 -> V_17 == NULL )
return - V_28 ;
F_8 ( V_8 -> V_17 , V_24 , F_7 ( V_24 ) + 1 ) ;
} else {
V_8 -> V_17 = ( char * ) V_29 ;
}
V_23 -> type = V_30 ;
if ( V_21 [ V_31 ] != NULL &&
V_21 [ V_32 ] != NULL )
return - V_33 ;
if ( V_21 [ V_32 ] != NULL )
V_23 -> type = V_34 ;
switch ( V_23 -> type ) {
case V_30 :
if ( V_21 [ V_31 ] != NULL ) {
V_23 -> V_35 . log . V_36 =
F_9 ( F_10 ( V_21 [ V_31 ] ) ) ;
} else {
V_23 -> V_35 . log . V_36 = V_37 ;
}
if ( V_21 [ V_38 ] != NULL ) {
V_23 -> V_35 . log . V_39 =
F_9 ( F_10 ( V_21 [ V_38 ] ) ) ;
}
break;
case V_34 :
V_23 -> V_35 . V_40 . V_41 = F_11 ( F_12 ( V_21 [ V_32 ] ) ) ;
if ( V_21 [ V_42 ] != NULL ) {
V_23 -> V_35 . V_40 . V_43 =
F_9 ( F_10 ( V_21 [ V_42 ] ) ) ;
}
if ( V_21 [ V_44 ] != NULL ) {
V_23 -> V_35 . V_40 . V_45 =
F_11 ( F_12 ( V_21 [ V_44 ] ) ) ;
}
break;
}
if ( V_19 -> V_46 -> V_47 == V_48 ) {
V_25 = F_13 ( V_49 , V_23 -> type ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_13 ( V_50 , V_23 -> type ) ;
if ( V_25 < 0 ) {
F_14 ( V_49 , V_23 -> type ) ;
return V_25 ;
}
return 0 ;
}
return F_13 ( V_19 -> V_46 -> V_47 , V_23 -> type ) ;
}
static void F_15 ( const struct V_18 * V_19 ,
const struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_22 * V_23 = & V_8 -> V_16 ;
if ( V_8 -> V_17 != V_29 )
F_16 ( V_8 -> V_17 ) ;
if ( V_19 -> V_46 -> V_47 == V_48 ) {
F_14 ( V_49 , V_23 -> type ) ;
F_14 ( V_50 , V_23 -> type ) ;
} else {
F_14 ( V_19 -> V_46 -> V_47 , V_23 -> type ) ;
}
}
static int F_17 ( struct V_51 * V_15 , const struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_2 ( V_2 ) ;
const struct V_22 * V_23 = & V_8 -> V_16 ;
if ( V_8 -> V_17 != V_29 )
if ( F_18 ( V_15 , V_26 , V_8 -> V_17 ) )
goto V_52;
switch ( V_23 -> type ) {
case V_30 :
if ( F_19 ( V_15 , V_31 , F_20 ( V_23 -> V_35 . log . V_36 ) ) )
goto V_52;
if ( V_23 -> V_35 . log . V_39 ) {
if ( F_19 ( V_15 , V_38 ,
F_20 ( V_23 -> V_35 . log . V_39 ) ) )
goto V_52;
}
break;
case V_34 :
if ( F_21 ( V_15 , V_32 , F_22 ( V_23 -> V_35 . V_40 . V_41 ) ) )
goto V_52;
if ( V_23 -> V_35 . V_40 . V_43 ) {
if ( F_19 ( V_15 , V_42 ,
F_20 ( V_23 -> V_35 . V_40 . V_43 ) ) )
goto V_52;
}
if ( V_23 -> V_35 . V_40 . V_45 ) {
if ( F_21 ( V_15 , V_44 ,
F_22 ( V_23 -> V_35 . V_40 . V_45 ) ) )
goto V_52;
}
break;
}
return 0 ;
V_52:
return - 1 ;
}
static int T_1 F_23 ( void )
{
return F_24 ( & V_53 ) ;
}
static void T_2 F_25 ( void )
{
F_26 ( & V_53 ) ;
}
