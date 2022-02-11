static void F_1 ( unsigned int V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_6 * V_7 = F_3 ( V_5 -> V_8 , 0 ) ;
struct V_9 * V_10 = F_4 ( V_3 ) ;
T_1 V_11 ;
F_5 ( V_10 , V_3 ) ;
V_11 = F_6 ( V_7 , V_12 ) &
~ ( F_6 ( V_7 , V_13 ) ) ;
if ( V_11 == 0 ) {
F_7 ( & V_3 -> V_14 ) ;
F_8 ( V_1 , V_3 ) ;
F_9 ( & V_3 -> V_14 ) ;
goto V_15;
}
do {
V_1 = F_10 ( V_11 ) - 1 ;
F_11 ( V_7 , 1 << V_1 , V_16 ) ;
V_11 &= ~ ( 1 << V_1 ) ;
F_12 ( F_13 ( V_5 -> V_8 , V_1 ) ) ;
} while ( V_11 );
V_15:
F_14 ( V_10 , V_3 ) ;
}
static void F_15 ( struct V_17 * V_18 )
{
struct V_6 * V_7 = F_16 ( V_18 ) ;
struct V_4 * V_5 = V_7 -> V_19 ;
F_17 ( V_7 ) ;
V_5 -> V_20 = F_6 ( V_7 , V_13 ) ;
if ( V_5 -> V_21 ) {
F_11 ( V_7 , ~ V_7 -> V_22 , V_23 ) ;
F_11 ( V_7 , V_7 -> V_22 , V_24 ) ;
}
F_18 ( V_7 ) ;
}
static void F_19 ( struct V_17 * V_18 )
{
struct V_6 * V_7 = F_16 ( V_18 ) ;
struct V_4 * V_5 = V_7 -> V_19 ;
F_17 ( V_7 ) ;
F_11 ( V_7 , ~ V_5 -> V_20 & ~ V_7 -> V_22 , V_16 ) ;
F_11 ( V_7 , V_5 -> V_20 , V_23 ) ;
F_11 ( V_7 , ~ V_5 -> V_20 , V_24 ) ;
F_18 ( V_7 ) ;
}
int T_2 F_20 ( struct V_25 * V_26 ,
struct V_25 * V_27 )
{
unsigned int V_28 = V_29 | V_30 | V_31 ;
struct V_4 * V_32 ;
struct V_6 * V_7 ;
struct V_33 * V_34 ;
int V_35 ;
unsigned int V_36 ;
V_32 = F_21 ( sizeof( * V_32 ) , V_37 ) ;
if ( ! V_32 )
return - V_38 ;
V_32 -> V_39 = F_22 ( V_26 , 0 ) ;
if ( ! V_32 -> V_39 ) {
F_23 ( L_1 ) ;
V_35 = - V_38 ;
goto V_40;
}
F_24 ( 0xffffffff , V_32 -> V_39 + V_23 ) ;
F_24 ( 0xffffffff , V_32 -> V_39 + V_16 ) ;
V_32 -> V_41 = F_25 ( V_26 , 0 ) ;
if ( ! V_32 -> V_41 ) {
F_23 ( L_2 ) ;
V_35 = - V_42 ;
goto V_43;
}
V_32 -> V_8 = F_26 ( V_26 , 32 ,
& V_44 , NULL ) ;
if ( ! V_32 -> V_8 ) {
V_35 = - V_38 ;
goto V_43;
}
V_36 = 0 ;
if ( F_27 ( V_45 ) && F_27 ( V_46 ) )
V_36 |= V_47 ;
V_35 = F_28 ( V_32 -> V_8 , 32 , 1 ,
V_26 -> V_48 , V_49 , V_28 , 0 , V_36 ) ;
if ( V_35 ) {
F_23 ( L_3 ) ;
goto V_50;
}
F_29 ( V_32 -> V_41 , V_32 ) ;
F_30 ( V_32 -> V_41 , F_1 ) ;
V_7 = F_3 ( V_32 -> V_8 , 0 ) ;
V_7 -> V_51 = V_32 -> V_39 ;
V_7 -> V_19 = V_32 ;
V_34 = V_7 -> V_52 ;
V_34 -> V_10 . V_53 = V_54 ;
V_34 -> V_55 . V_56 = V_16 ;
V_34 -> V_10 . V_57 = V_58 ;
V_34 -> V_55 . V_59 = V_23 ;
V_34 -> V_10 . V_60 = V_61 ;
V_34 -> V_55 . V_62 = V_24 ;
V_34 -> V_10 . V_63 = F_15 ;
V_34 -> V_10 . V_64 = F_19 ;
if ( F_31 ( V_26 , L_4 ) ) {
V_32 -> V_21 = true ;
V_7 -> V_65 = 0xffffffff ;
V_34 -> V_10 . V_66 = V_67 ;
}
F_32 ( L_5 ,
V_32 -> V_39 , V_32 -> V_41 ) ;
return 0 ;
V_50:
F_33 ( V_32 -> V_8 ) ;
V_43:
F_34 ( V_32 -> V_39 ) ;
V_40:
F_35 ( V_32 ) ;
return V_35 ;
}
