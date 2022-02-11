static void F_1 ( unsigned int V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_6 * V_7 = F_3 ( V_3 ) ;
T_1 V_8 ;
F_4 ( V_7 , V_3 ) ;
V_8 = F_5 ( V_5 -> V_9 + V_10 ) &
~ ( F_5 ( V_5 -> V_9 + V_11 ) ) ;
if ( V_8 == 0 ) {
F_6 ( V_1 , V_3 ) ;
goto V_12;
}
do {
V_1 = F_7 ( V_8 ) - 1 ;
F_8 ( 1 << V_1 , V_5 -> V_9 + V_13 ) ;
V_8 &= ~ ( 1 << V_1 ) ;
F_9 ( F_10 ( V_5 -> V_14 , V_1 ) ) ;
} while ( V_8 );
V_12:
F_11 ( V_7 , V_3 ) ;
}
static void F_12 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = F_13 ( V_16 ) ;
struct V_4 * V_5 = V_18 -> V_19 ;
F_14 ( V_18 ) ;
V_5 -> V_20 = F_5 ( V_5 -> V_9 + V_11 ) ;
if ( V_5 -> V_21 ) {
F_8 ( ~ V_18 -> V_22 , V_5 -> V_9 + V_23 ) ;
F_8 ( V_18 -> V_22 , V_5 -> V_9 + V_24 ) ;
}
F_15 ( V_18 ) ;
}
static void F_16 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = F_13 ( V_16 ) ;
struct V_4 * V_5 = V_18 -> V_19 ;
F_14 ( V_18 ) ;
F_8 ( ~ V_5 -> V_20 & ~ V_18 -> V_22 , V_5 -> V_9 + V_13 ) ;
F_8 ( V_5 -> V_20 , V_5 -> V_9 + V_23 ) ;
F_8 ( ~ V_5 -> V_20 , V_5 -> V_9 + V_24 ) ;
F_15 ( V_18 ) ;
}
int T_2 F_17 ( struct V_25 * V_26 ,
struct V_25 * V_27 )
{
unsigned int V_28 = V_29 | V_30 | V_31 ;
struct V_4 * V_32 ;
struct V_17 * V_18 ;
struct V_33 * V_34 ;
int V_35 ;
V_32 = F_18 ( sizeof( * V_32 ) , V_36 ) ;
if ( ! V_32 )
return - V_37 ;
V_32 -> V_9 = F_19 ( V_26 , 0 ) ;
if ( ! V_32 -> V_9 ) {
F_20 ( L_1 ) ;
V_35 = - V_37 ;
goto V_38;
}
F_8 ( 0xffffffff , V_32 -> V_9 + V_23 ) ;
F_8 ( 0xffffffff , V_32 -> V_9 + V_13 ) ;
V_32 -> V_39 = F_21 ( V_26 , 0 ) ;
if ( V_32 -> V_39 < 0 ) {
F_20 ( L_2 ) ;
V_35 = V_32 -> V_39 ;
goto V_40;
}
V_32 -> V_14 = F_22 ( V_26 , 32 ,
& V_41 , NULL ) ;
if ( ! V_32 -> V_14 ) {
V_35 = - V_37 ;
goto V_40;
}
V_35 = F_23 ( V_32 -> V_14 , 32 , 1 ,
V_26 -> V_42 , V_43 , V_28 , 0 , 0 ) ;
if ( V_35 ) {
F_20 ( L_3 ) ;
goto V_44;
}
F_24 ( V_32 -> V_39 , V_32 ) ;
F_25 ( V_32 -> V_39 , F_1 ) ;
V_18 = F_26 ( V_32 -> V_14 , 0 ) ;
V_18 -> V_45 = V_32 -> V_9 ;
V_18 -> V_19 = V_32 ;
V_34 = V_18 -> V_46 ;
V_34 -> V_7 . V_47 = V_48 ;
V_34 -> V_49 . V_50 = V_13 ;
V_34 -> V_7 . V_51 = V_52 ;
V_34 -> V_49 . V_53 = V_23 ;
V_34 -> V_7 . V_54 = V_55 ;
V_34 -> V_49 . V_56 = V_24 ;
V_34 -> V_7 . V_57 = F_12 ;
V_34 -> V_7 . V_58 = F_16 ;
if ( F_27 ( V_26 , L_4 ) ) {
V_32 -> V_21 = true ;
V_18 -> V_59 = 0xffffffff ;
V_34 -> V_7 . V_60 = V_61 ;
}
F_28 ( L_5 ,
V_32 -> V_9 , V_32 -> V_39 ) ;
return 0 ;
V_44:
F_29 ( V_32 -> V_14 ) ;
V_40:
F_30 ( V_32 -> V_9 ) ;
V_38:
F_31 ( V_32 ) ;
return V_35 ;
}
