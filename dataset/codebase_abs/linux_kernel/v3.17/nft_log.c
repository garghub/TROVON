static void F_1 ( const struct V_1 * V_2 ,
struct V_3 V_4 [ V_5 + 1 ] ,
const struct V_6 * V_7 )
{
const struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_10 * V_10 = F_3 ( V_7 -> V_11 ? V_7 -> V_11 : V_7 -> V_12 ) ;
F_4 ( V_10 , V_7 -> V_13 -> V_14 , V_7 -> V_13 -> V_15 , V_7 -> V_16 , V_7 -> V_11 ,
V_7 -> V_12 , & V_9 -> V_17 , L_1 , V_9 -> V_18 ) ;
}
static int F_5 ( const struct V_19 * V_20 ,
const struct V_1 * V_2 ,
const struct V_21 * const V_22 [] )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_23 * V_24 = & V_9 -> V_17 ;
const struct V_21 * V_25 ;
int V_26 ;
V_25 = V_22 [ V_27 ] ;
if ( V_25 != NULL ) {
V_9 -> V_18 = F_6 ( F_7 ( V_25 ) + 1 , V_28 ) ;
if ( V_9 -> V_18 == NULL )
return - V_29 ;
F_8 ( V_9 -> V_18 , V_25 , F_7 ( V_25 ) + 1 ) ;
} else {
V_9 -> V_18 = ( char * ) V_30 ;
}
V_24 -> type = V_31 ;
if ( V_22 [ V_32 ] != NULL &&
V_22 [ V_33 ] != NULL )
return - V_34 ;
if ( V_22 [ V_33 ] != NULL )
V_24 -> type = V_35 ;
switch ( V_24 -> type ) {
case V_31 :
if ( V_22 [ V_32 ] != NULL ) {
V_24 -> V_36 . log . V_37 =
F_9 ( F_10 ( V_22 [ V_32 ] ) ) ;
} else {
V_24 -> V_36 . log . V_37 = 4 ;
}
if ( V_22 [ V_38 ] != NULL ) {
V_24 -> V_36 . log . V_39 =
F_9 ( F_10 ( V_22 [ V_38 ] ) ) ;
}
break;
case V_35 :
V_24 -> V_36 . V_40 . V_41 = F_11 ( F_12 ( V_22 [ V_33 ] ) ) ;
if ( V_22 [ V_42 ] != NULL ) {
V_24 -> V_36 . V_40 . V_43 =
F_9 ( F_10 ( V_22 [ V_42 ] ) ) ;
}
if ( V_22 [ V_44 ] != NULL ) {
V_24 -> V_36 . V_40 . V_45 =
F_11 ( F_12 ( V_22 [ V_44 ] ) ) ;
}
break;
}
if ( V_20 -> V_46 -> V_47 == V_48 ) {
V_26 = F_13 ( V_49 , V_24 -> type ) ;
if ( V_26 < 0 )
return V_26 ;
V_26 = F_13 ( V_50 , V_24 -> type ) ;
if ( V_26 < 0 ) {
F_14 ( V_49 , V_24 -> type ) ;
return V_26 ;
}
return 0 ;
}
return F_13 ( V_20 -> V_46 -> V_47 , V_24 -> type ) ;
}
static void F_15 ( const struct V_19 * V_20 ,
const struct V_1 * V_2 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_23 * V_24 = & V_9 -> V_17 ;
if ( V_9 -> V_18 != V_30 )
F_16 ( V_9 -> V_18 ) ;
if ( V_20 -> V_46 -> V_47 == V_48 ) {
F_14 ( V_49 , V_24 -> type ) ;
F_14 ( V_50 , V_24 -> type ) ;
} else {
F_14 ( V_20 -> V_46 -> V_47 , V_24 -> type ) ;
}
}
static int F_17 ( struct V_51 * V_16 , const struct V_1 * V_2 )
{
const struct V_8 * V_9 = F_2 ( V_2 ) ;
const struct V_23 * V_24 = & V_9 -> V_17 ;
if ( V_9 -> V_18 != V_30 )
if ( F_18 ( V_16 , V_27 , V_9 -> V_18 ) )
goto V_52;
switch ( V_24 -> type ) {
case V_31 :
if ( F_19 ( V_16 , V_32 , F_20 ( V_24 -> V_36 . log . V_37 ) ) )
goto V_52;
if ( V_24 -> V_36 . log . V_39 ) {
if ( F_19 ( V_16 , V_38 ,
F_20 ( V_24 -> V_36 . log . V_39 ) ) )
goto V_52;
}
break;
case V_35 :
if ( F_21 ( V_16 , V_33 , F_22 ( V_24 -> V_36 . V_40 . V_41 ) ) )
goto V_52;
if ( V_24 -> V_36 . V_40 . V_43 ) {
if ( F_19 ( V_16 , V_42 ,
F_20 ( V_24 -> V_36 . V_40 . V_43 ) ) )
goto V_52;
}
if ( V_24 -> V_36 . V_40 . V_45 ) {
if ( F_21 ( V_16 , V_44 ,
F_22 ( V_24 -> V_36 . V_40 . V_45 ) ) )
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
