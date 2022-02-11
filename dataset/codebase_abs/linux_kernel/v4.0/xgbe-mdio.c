static int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = & V_6 -> V_9 ;
int V_10 ;
F_2 ( L_1 ,
V_3 , V_4 ) ;
V_10 = V_9 -> V_11 ( V_6 , V_3 , V_4 ) ;
F_2 ( L_2 , V_10 ) ;
return V_10 ;
}
static int F_3 ( struct V_1 * V_2 , int V_3 , int V_4 ,
T_1 V_12 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = & V_6 -> V_9 ;
int V_10 = V_12 ;
F_2 ( L_3 ,
V_3 , V_4 , V_10 ) ;
V_9 -> V_13 ( V_6 , V_3 , V_4 , V_10 ) ;
F_2 ( L_4 ) ;
return 0 ;
}
void F_4 ( struct V_5 * V_6 )
{
struct V_14 * V_15 = V_6 -> V_15 ;
struct V_16 * V_17 = V_6 -> V_2 -> V_18 [ V_19 ] ;
int V_20 ;
F_5 ( V_15 , L_5 ) ;
F_5 ( V_15 , L_6 , V_21 ,
F_6 ( V_6 , V_22 , V_21 ) ) ;
F_5 ( V_15 , L_7 , V_23 ,
F_6 ( V_6 , V_22 , V_23 ) ) ;
F_5 ( V_15 , L_8 , V_24 ,
F_6 ( V_6 , V_22 , V_24 ) ) ;
F_5 ( V_15 , L_9 , V_25 ,
F_6 ( V_6 , V_22 , V_25 ) ) ;
F_5 ( V_15 , L_10 , V_26 ,
F_6 ( V_6 , V_22 , V_26 ) ) ;
F_5 ( V_15 , L_10 , V_27 ,
F_6 ( V_6 , V_22 , V_27 ) ) ;
F_5 ( V_15 , L_11 , V_21 ,
F_6 ( V_6 , V_28 , V_21 ) ) ;
F_5 ( V_15 , L_12 , V_23 ,
F_6 ( V_6 , V_28 , V_23 ) ) ;
F_5 ( V_15 , L_13 ,
V_29 ,
F_6 ( V_6 , V_28 , V_29 ) ) ;
F_5 ( V_15 , L_14 ,
V_29 + 1 ,
F_6 ( V_6 , V_28 , V_29 + 1 ) ) ;
F_5 ( V_15 , L_15 ,
V_29 + 2 ,
F_6 ( V_6 , V_28 , V_29 + 2 ) ) ;
F_5 ( V_15 , L_16 ,
V_30 ,
F_6 ( V_6 , V_28 , V_30 ) ) ;
F_5 ( V_15 , L_17 ,
V_17 -> V_31 . V_32 ) ;
for ( V_20 = 0 ; V_20 < F_7 ( V_17 -> V_31 . V_33 ) ; V_20 ++ )
F_5 ( V_15 , L_18 , V_20 ,
V_17 -> V_31 . V_33 [ V_20 ] ) ;
F_5 ( V_15 , L_19 ) ;
}
int F_8 ( struct V_5 * V_6 )
{
struct V_1 * V_2 ;
struct V_16 * V_17 ;
int V_34 = 0 ;
F_9 ( L_20 ) ;
V_2 = F_10 () ;
if ( ! V_2 ) {
F_11 ( V_6 -> V_15 , L_21 ) ;
return - V_35 ;
}
V_2 -> V_36 = V_37 ;
V_2 -> V_38 = F_1 ;
V_2 -> V_39 = F_3 ;
snprintf ( V_2 -> V_40 , sizeof( V_2 -> V_40 ) , L_22 , V_6 -> V_41 ) ;
V_2 -> V_7 = V_6 ;
V_2 -> V_42 = ~ 0 ;
V_2 -> V_43 = V_6 -> V_15 ;
V_34 = F_12 ( V_2 ) ;
if ( V_34 ) {
F_11 ( V_6 -> V_15 , L_23 ) ;
goto V_44;
}
F_9 ( L_24 , V_6 -> V_41 ) ;
V_17 = F_13 ( V_2 , V_19 , true ) ;
if ( F_14 ( V_17 ) || ! V_17 ||
! V_17 -> V_31 . V_33 [ V_22 ] ) {
F_11 ( V_6 -> V_15 , L_25 ) ;
V_34 = V_17 ? F_15 ( V_17 ) : - V_45 ;
goto V_46;
}
F_16 (MDIO_MODULE_PREFIX MDIO_ID_FMT,
MDIO_ID_ARGS(phydev->c45_ids.device_ids[MDIO_MMD_PCS])) ;
V_34 = F_17 ( V_17 ) ;
if ( V_34 ) {
F_11 ( V_6 -> V_15 , L_26 ) ;
goto V_47;
}
if ( ! V_17 -> V_15 . V_48 ) {
F_11 ( V_6 -> V_15 , L_27 ) ;
V_34 = - V_49 ;
goto V_47;
}
V_6 -> V_50 = V_17 -> V_15 . V_48 -> V_51 ;
if ( ! F_18 ( V_6 -> V_50 ) ) {
F_11 ( V_6 -> V_15 , L_28 ) ;
V_34 = - V_49 ;
goto V_47;
}
V_6 -> V_2 = V_2 ;
V_6 -> V_52 = V_22 ;
V_17 -> V_53 = V_6 -> V_54 ;
if ( V_17 -> V_53 == V_55 ) {
V_17 -> V_56 = V_6 -> V_57 ;
V_17 -> V_58 = V_59 ;
V_17 -> V_60 &= ~ V_61 ;
}
V_6 -> V_17 = V_17 ;
F_19 ( V_6 ) ;
F_9 ( L_29 ) ;
return 0 ;
V_47:
F_20 ( V_17 ) ;
V_46:
F_21 ( V_2 ) ;
V_44:
F_22 ( V_2 ) ;
return V_34 ;
}
void F_23 ( struct V_5 * V_6 )
{
F_9 ( L_30 ) ;
V_6 -> V_17 = NULL ;
F_24 ( V_6 -> V_50 ) ;
V_6 -> V_50 = NULL ;
F_21 ( V_6 -> V_2 ) ;
V_6 -> V_2 -> V_7 = NULL ;
F_22 ( V_6 -> V_2 ) ;
V_6 -> V_2 = NULL ;
F_9 ( L_31 ) ;
}
