void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 = 0 ;
F_3 ( 2500 , 3000 ) ;
V_5 = F_4 ( V_2 , V_6 ) ;
V_5 |= V_7 ;
F_5 ( V_2 , V_5 , V_6 ) ;
V_5 |= V_8 ;
F_5 ( V_2 , V_5 , V_6 ) ;
V_5 &= ~ V_7 ;
F_5 ( V_2 , V_5 , V_6 ) ;
F_3 ( 2500 , 3000 ) ;
if ( V_4 -> V_9 ) {
F_6 ( V_4 -> V_10 , L_1 , V_11 ) ;
V_5 = F_4 ( V_2 , V_12 ) ;
V_5 |= V_4 -> V_9 ;
F_5 ( V_2 , V_5 , V_12 ) ;
}
V_5 = F_4 ( V_2 , V_13 ) ;
V_5 |= V_14 ;
F_5 ( V_2 , V_5 , V_13 ) ;
}
unsigned int F_7 ( struct V_1 * V_2 )
{
return V_15 ;
}
void F_8 ( struct V_1 * V_2 , T_2 V_16 )
{
if ( F_9 ( V_2 , V_17 ) == 0 )
F_10 ( V_2 , 0xBC01 , V_17 ) ;
F_11 ( V_2 , V_16 ) ;
}
static int F_12 ( struct V_18 * V_19 )
{
struct V_1 * V_2 ;
struct V_20 * V_10 = & V_19 -> V_10 ;
struct V_21 * V_22 ;
int V_23 , V_5 = 0 , V_24 = 0 ;
struct V_3 * V_4 ;
T_1 V_25 = 0 ;
V_23 = F_13 ( V_19 , 0 ) ;
if ( V_23 < 0 ) {
F_14 ( V_10 , L_2 , V_11 ) ;
return V_23 ;
}
V_2 = F_15 ( V_10 , sizeof( struct V_1 ) +
sizeof( struct V_3 ) ) ;
if ( F_16 ( V_2 ) )
return F_17 ( V_2 ) ;
V_4 = F_2 ( V_2 ) ;
V_4 -> V_10 = V_10 ;
V_2 -> V_26 = V_27 |
V_28 ;
V_2 -> V_29 = V_30 |
V_31 ;
V_24 = F_18 ( V_2 -> V_32 ) ;
if ( V_24 )
goto V_33;
F_19 ( V_19 , V_2 ) ;
F_20 ( V_19 ) ;
V_2 -> V_34 = L_3 ;
V_2 -> V_35 = & V_36 ;
V_2 -> V_23 = V_23 ;
V_22 = F_21 ( V_19 , V_37 , 0 ) ;
V_2 -> V_38 = F_22 ( & V_19 -> V_10 , V_22 ) ;
if ( F_16 ( V_2 -> V_38 ) ) {
V_24 = F_17 ( V_2 -> V_38 ) ;
goto V_33;
}
V_4 -> V_39 = F_23 ( & V_19 -> V_10 , L_4 ) ;
if ( F_16 ( V_4 -> V_39 ) ) {
V_24 = F_17 ( V_4 -> V_39 ) ;
goto V_33;
}
V_24 = F_24 ( V_4 -> V_39 ) ;
if ( V_24 )
goto V_33;
V_4 -> V_40 = F_23 ( & V_19 -> V_10 , L_5 ) ;
if ( F_16 ( V_4 -> V_40 ) ) {
V_24 = F_17 ( V_4 -> V_40 ) ;
goto V_41;
}
V_24 = F_24 ( V_4 -> V_40 ) ;
if ( V_24 )
goto V_41;
V_5 = F_9 ( V_2 , V_42 ) ;
V_5 |= V_43 | V_44 | V_45 |
V_46 ;
V_5 &= ~ ( V_47 | V_48 ) ;
F_10 ( V_2 , V_5 , V_42 ) ;
V_25 = F_4 ( V_2 , V_12 ) ;
F_5 ( V_2 , V_25 & ~ V_49 , V_12 ) ;
F_25 ( 20 ) ;
F_5 ( V_2 , V_25 | V_49 , V_12 ) ;
V_25 = F_4 ( V_2 , V_50 ) ;
if ( V_25 & V_51 )
V_4 -> V_9 = V_52 ;
V_24 = F_26 ( V_2 ) ;
if ( V_24 )
goto V_53;
return 0 ;
V_53:
F_27 ( V_4 -> V_40 ) ;
V_41:
F_27 ( V_4 -> V_39 ) ;
V_33:
F_28 ( V_2 ) ;
return V_24 ;
}
static int F_29 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_30 ( V_19 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_31 ( V_2 , F_32 ( V_2 -> V_38 + V_54 ) ==
0xffffffff ) ;
F_27 ( V_4 -> V_39 ) ;
F_27 ( V_4 -> V_40 ) ;
F_28 ( V_2 ) ;
F_19 ( V_19 , NULL ) ;
return 0 ;
}
