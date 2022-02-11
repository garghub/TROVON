static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 -> V_7 ;
return F_2 ( F_3 ( V_5 -> V_8 ) ) ;
}
static void F_4 ( struct V_2 * V_3 )
{
struct V_9 * V_9 = F_5 ( V_3 ) ;
F_6 ( V_3 ) ;
F_7 ( V_9 ) ;
}
static bool F_8 ( struct V_2 * V_3 ,
const struct V_10 * V_11 ,
struct V_10 * V_12 )
{
return true ;
}
static void F_9 ( struct V_2 * V_3 ,
struct V_10 * V_11 ,
struct V_10 * V_12 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_1 V_13 , V_14 , V_15 , V_16 ;
T_1 V_17 , V_18 ;
T_1 V_19 , V_20 ;
V_11 = V_12 ;
F_10 ( L_1 ,
V_11 -> V_21 . V_22 , V_11 -> V_23 ,
V_11 -> V_24 , V_11 -> clock ,
V_11 -> V_25 , V_11 -> V_26 ,
V_11 -> V_27 , V_11 -> V_28 ,
V_11 -> V_29 , V_11 -> V_30 ,
V_11 -> V_31 , V_11 -> V_32 ,
V_11 -> type , V_11 -> V_33 ) ;
V_16 = 0 ;
if ( V_11 -> V_33 & V_34 )
V_16 |= V_35 ;
if ( V_11 -> V_33 & V_36 )
V_16 |= V_37 ;
V_13 = 0 ;
V_19 = ( V_11 -> V_28 - V_11 -> V_26 ) ;
V_20 = V_11 -> V_28 - ( V_11 -> V_26 - V_11 -> V_25 ) - 1 ;
V_14 = V_11 -> V_32 * V_11 -> V_28 ;
V_15 = ( V_11 -> V_31 - V_11 -> V_30 ) * V_11 -> V_28 ;
V_17 = ( V_11 -> V_32 - V_11 -> V_30 ) * V_11 -> V_28 + V_13 ;
V_18 = V_14 - ( ( V_11 -> V_30 - V_11 -> V_29 ) * V_11 -> V_28 ) + V_13 - 1 ;
F_11 ( V_1 , V_38 ,
F_12 ( V_11 -> V_27 - V_11 -> V_26 ) |
F_13 ( V_11 -> V_28 ) ) ;
F_11 ( V_1 , V_39 , V_14 ) ;
F_11 ( V_1 , V_40 , V_15 ) ;
F_11 ( V_1 , V_41 ,
F_14 ( V_19 ) |
F_15 ( V_20 ) ) ;
F_11 ( V_1 , V_42 , V_17 ) ;
F_11 ( V_1 , V_43 , V_18 ) ;
F_11 ( V_1 , V_44 , V_16 ) ;
F_11 ( V_1 , V_45 ,
V_46 |
F_16 ( 0xff ) ) ;
F_11 ( V_1 , V_47 ,
F_17 ( 0 ) |
F_18 ( 0 ) ) ;
F_11 ( V_1 , V_48 , V_13 ) ;
F_11 ( V_1 , V_49 , 0 ) ;
F_11 ( V_1 , V_50 , 0 ) ;
F_11 ( V_1 , V_51 , 0 ) ;
}
static void F_19 ( struct V_2 * V_3 )
{
struct V_9 * V_9 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
if ( ! V_9 -> V_52 )
return;
F_11 ( V_1 , V_53 , 0 ) ;
F_20 ( & V_1 -> V_21 , V_54 ) ;
V_9 -> V_52 = false ;
}
static void F_21 ( struct V_2 * V_3 )
{
struct V_9 * V_9 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
if ( V_9 -> V_52 )
return;
F_22 ( V_3 -> V_55 ,
V_56 |
V_57 |
V_58 |
F_23 ( V_59 ) |
F_24 ( V_59 ) |
F_25 ( V_59 ) |
F_26 ( 0x21 ) ) ;
F_27 ( V_3 -> V_55 , V_60 , 0 ) ;
F_11 ( V_1 , V_53 , 1 ) ;
V_9 -> V_52 = true ;
}
struct V_2 * F_28 ( struct V_61 * V_6 )
{
struct V_2 * V_3 = NULL ;
struct V_9 * V_9 ;
int V_62 ;
V_9 = F_29 ( sizeof( * V_9 ) , V_63 ) ;
if ( ! V_9 ) {
V_62 = - V_64 ;
goto V_65;
}
V_3 = & V_9 -> V_21 ;
F_30 ( V_6 , V_3 , & V_66 ,
V_67 , NULL ) ;
F_31 ( V_3 , & V_68 ) ;
return V_3 ;
V_65:
if ( V_3 )
F_4 ( V_3 ) ;
return F_32 ( V_62 ) ;
}
