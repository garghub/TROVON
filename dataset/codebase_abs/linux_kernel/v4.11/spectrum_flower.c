static int F_1 ( struct V_1 * V_1 ,
struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_6 * V_7 )
{
const struct V_8 * V_9 ;
F_2 ( V_10 ) ;
int V_11 ;
if ( F_3 ( V_7 ) )
return 0 ;
F_4 ( V_7 , & V_10 ) ;
F_5 (a, &actions, list) {
if ( F_6 ( V_9 ) ) {
V_11 = F_7 ( V_5 ) ;
if ( V_11 )
return V_11 ;
} else if ( F_8 ( V_9 ) ) {
int V_12 = F_9 ( V_9 ) ;
struct V_2 * V_13 ;
V_13 = F_10 ( F_11 ( V_3 ) , V_12 ) ;
if ( V_13 == V_3 )
V_13 = NULL ;
V_11 = F_12 ( V_1 , V_5 ,
V_13 ) ;
if ( V_11 )
return V_11 ;
} else {
F_13 ( V_1 -> V_14 -> V_3 , L_1 ) ;
return - V_15 ;
}
}
return 0 ;
}
static void F_14 ( struct V_4 * V_5 ,
struct V_16 * V_17 )
{
struct V_18 * V_19 =
F_15 ( V_17 -> V_20 ,
V_21 ,
V_17 -> V_19 ) ;
struct V_18 * V_22 =
F_15 ( V_17 -> V_20 ,
V_21 ,
V_17 -> V_22 ) ;
F_16 ( V_5 , V_23 ,
F_17 ( V_19 -> V_24 ) , F_17 ( V_22 -> V_24 ) ) ;
F_16 ( V_5 , V_25 ,
F_17 ( V_19 -> V_26 ) , F_17 ( V_22 -> V_26 ) ) ;
}
static void F_18 ( struct V_4 * V_5 ,
struct V_16 * V_17 )
{
struct V_27 * V_19 =
F_15 ( V_17 -> V_20 ,
V_28 ,
V_17 -> V_19 ) ;
struct V_27 * V_22 =
F_15 ( V_17 -> V_20 ,
V_28 ,
V_17 -> V_22 ) ;
T_1 V_29 = sizeof( V_19 -> V_24 ) / 2 ;
F_19 ( V_5 , V_30 ,
& V_19 -> V_24 . V_31 [ 0 ] ,
& V_22 -> V_24 . V_31 [ 0 ] ,
V_29 ) ;
F_19 ( V_5 , V_32 ,
& V_19 -> V_24 . V_31 [ V_29 ] ,
& V_22 -> V_24 . V_31 [ V_29 ] ,
V_29 ) ;
F_19 ( V_5 , V_33 ,
& V_19 -> V_26 . V_31 [ 0 ] ,
& V_22 -> V_26 . V_31 [ 0 ] ,
V_29 ) ;
F_19 ( V_5 , V_34 ,
& V_19 -> V_26 . V_31 [ V_29 ] ,
& V_22 -> V_26 . V_31 [ V_29 ] ,
V_29 ) ;
}
static int F_20 ( struct V_1 * V_1 ,
struct V_4 * V_5 ,
struct V_16 * V_17 ,
T_2 V_35 )
{
struct V_36 * V_19 , * V_22 ;
if ( ! F_21 ( V_17 -> V_20 , V_37 ) )
return 0 ;
if ( V_35 != V_38 && V_35 != V_39 ) {
F_13 ( V_1 -> V_14 -> V_3 , L_2 ) ;
return - V_40 ;
}
V_19 = F_15 ( V_17 -> V_20 ,
V_37 ,
V_17 -> V_19 ) ;
V_22 = F_15 ( V_17 -> V_20 ,
V_37 ,
V_17 -> V_22 ) ;
F_16 ( V_5 , V_41 ,
F_22 ( V_19 -> V_26 ) , F_22 ( V_22 -> V_26 ) ) ;
F_16 ( V_5 , V_42 ,
F_22 ( V_19 -> V_24 ) , F_22 ( V_22 -> V_24 ) ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_1 ,
struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_16 * V_17 )
{
T_3 V_43 = 0 ;
T_2 V_35 = 0 ;
int V_11 ;
if ( V_17 -> V_20 -> V_44 &
~ ( F_24 ( V_45 ) |
F_24 ( V_46 ) |
F_24 ( V_47 ) |
F_24 ( V_21 ) |
F_24 ( V_28 ) |
F_24 ( V_37 ) ) ) {
F_13 ( V_1 -> V_14 -> V_3 , L_3 ) ;
return - V_15 ;
}
F_25 ( V_5 , V_17 -> V_48 ) ;
if ( F_21 ( V_17 -> V_20 , V_45 ) ) {
struct V_49 * V_19 =
F_15 ( V_17 -> V_20 ,
V_45 ,
V_17 -> V_19 ) ;
V_43 = V_19 -> V_43 ;
}
if ( F_21 ( V_17 -> V_20 , V_46 ) ) {
struct V_50 * V_19 =
F_15 ( V_17 -> V_20 ,
V_46 ,
V_17 -> V_19 ) ;
struct V_50 * V_22 =
F_15 ( V_17 -> V_20 ,
V_46 ,
V_17 -> V_22 ) ;
T_3 V_51 = F_22 ( V_19 -> V_52 ) ;
T_3 V_53 = F_22 ( V_22 -> V_52 ) ;
if ( V_51 == V_54 ) {
V_51 = 0 ;
V_53 = 0 ;
}
F_16 ( V_5 ,
V_55 ,
V_51 , V_53 ) ;
V_35 = V_19 -> V_35 ;
F_16 ( V_5 ,
V_56 ,
V_19 -> V_35 , V_22 -> V_35 ) ;
}
if ( F_21 ( V_17 -> V_20 , V_47 ) ) {
struct V_57 * V_19 =
F_15 ( V_17 -> V_20 ,
V_47 ,
V_17 -> V_19 ) ;
struct V_57 * V_22 =
F_15 ( V_17 -> V_20 ,
V_47 ,
V_17 -> V_22 ) ;
F_19 ( V_5 ,
V_58 ,
V_19 -> V_26 , V_22 -> V_26 ,
sizeof( V_19 -> V_26 ) ) ;
F_19 ( V_5 ,
V_59 ,
V_19 -> V_24 , V_22 -> V_24 ,
sizeof( V_19 -> V_24 ) ) ;
}
if ( V_43 == V_21 )
F_14 ( V_5 , V_17 ) ;
if ( V_43 == V_28 )
F_18 ( V_5 , V_17 ) ;
V_11 = F_20 ( V_1 , V_5 , V_17 , V_35 ) ;
if ( V_11 )
return V_11 ;
return F_1 ( V_1 , V_3 , V_5 , V_17 -> V_7 ) ;
}
int F_26 ( struct V_60 * V_60 , bool V_61 ,
T_4 V_62 , struct V_16 * V_17 )
{
struct V_1 * V_1 = V_60 -> V_1 ;
struct V_2 * V_3 = V_60 -> V_3 ;
struct V_4 * V_5 ;
struct V_63 * V_64 ;
struct V_65 * V_66 ;
int V_11 ;
V_64 = F_27 ( V_1 , V_3 , V_61 ,
V_67 ) ;
if ( F_28 ( V_64 ) )
return F_29 ( V_64 ) ;
V_66 = F_30 ( V_1 , V_64 , V_17 -> V_68 ) ;
if ( F_28 ( V_66 ) ) {
V_11 = F_29 ( V_66 ) ;
goto V_69;
}
V_5 = F_31 ( V_66 ) ;
V_11 = F_23 ( V_1 , V_3 , V_5 , V_17 ) ;
if ( V_11 )
goto V_70;
V_11 = F_32 ( V_5 ) ;
if ( V_11 )
goto V_71;
V_11 = F_33 ( V_1 , V_66 ) ;
if ( V_11 )
goto V_72;
F_34 ( V_1 , V_64 ) ;
return 0 ;
V_72:
V_71:
V_70:
F_35 ( V_1 , V_66 ) ;
V_69:
F_34 ( V_1 , V_64 ) ;
return V_11 ;
}
void F_36 ( struct V_60 * V_60 , bool V_61 ,
struct V_16 * V_17 )
{
struct V_1 * V_1 = V_60 -> V_1 ;
struct V_63 * V_64 ;
struct V_65 * V_66 ;
V_64 = F_27 ( V_1 , V_60 -> V_3 ,
V_61 ,
V_67 ) ;
if ( F_28 ( V_64 ) )
return;
V_66 = F_37 ( V_1 , V_64 , V_17 -> V_68 ) ;
if ( V_66 ) {
F_38 ( V_1 , V_66 ) ;
F_35 ( V_1 , V_66 ) ;
}
F_34 ( V_1 , V_64 ) ;
}
