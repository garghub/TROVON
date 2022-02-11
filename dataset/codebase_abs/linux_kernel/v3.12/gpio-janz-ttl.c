static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
T_1 * V_7 ;
int V_8 ;
if ( V_3 < 8 ) {
V_7 = & V_5 -> V_9 ;
} else if ( V_3 < 16 ) {
V_7 = & V_5 -> V_10 ;
V_3 -= 8 ;
} else {
V_7 = & V_5 -> V_11 ;
V_3 -= 16 ;
}
F_3 ( & V_5 -> V_12 ) ;
V_8 = * V_7 & ( 1 << V_3 ) ;
F_4 ( & V_5 -> V_12 ) ;
return V_8 ;
}
static void F_5 ( struct V_1 * V_2 , unsigned V_3 , int V_13 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
void T_2 * V_14 ;
T_1 * V_7 ;
if ( V_3 < 8 ) {
V_14 = & V_5 -> V_15 -> V_16 ;
V_7 = & V_5 -> V_9 ;
} else if ( V_3 < 16 ) {
V_14 = & V_5 -> V_15 -> V_17 ;
V_7 = & V_5 -> V_10 ;
V_3 -= 8 ;
} else {
V_14 = & V_5 -> V_15 -> V_18 ;
V_7 = & V_5 -> V_11 ;
V_3 -= 16 ;
}
F_3 ( & V_5 -> V_12 ) ;
if ( V_13 )
* V_7 |= ( 1 << V_3 ) ;
else
* V_7 &= ~ ( 1 << V_3 ) ;
F_6 ( * V_7 , V_14 ) ;
F_4 ( & V_5 -> V_12 ) ;
}
static void F_7 ( struct V_4 * V_5 , T_1 V_19 , T_3 V_20 )
{
F_6 ( V_19 , & V_5 -> V_15 -> V_21 ) ;
F_6 ( V_20 , & V_5 -> V_15 -> V_21 ) ;
}
static void F_8 ( struct V_4 * V_5 )
{
F_6 ( 0x0000 , & V_5 -> V_15 -> V_21 ) ;
F_6 ( 0x0001 , & V_5 -> V_15 -> V_21 ) ;
F_6 ( 0x0000 , & V_5 -> V_15 -> V_21 ) ;
F_7 ( V_5 , V_22 , 0x00ff ) ;
F_7 ( V_5 , V_23 , 0x00ff ) ;
F_7 ( V_5 , V_24 , 0x000f ) ;
F_7 ( V_5 , V_25 , 0x0000 ) ;
F_7 ( V_5 , V_26 , 0x0000 ) ;
F_7 ( V_5 , V_27 , 0x0000 ) ;
F_6 ( 0x0000 , & V_5 -> V_15 -> V_16 ) ;
F_6 ( 0x0000 , & V_5 -> V_15 -> V_17 ) ;
F_6 ( 0x0000 , & V_5 -> V_15 -> V_18 ) ;
F_7 ( V_5 , V_28 , V_29 | V_30 | V_31 ) ;
}
static int F_9 ( struct V_32 * V_33 )
{
struct V_34 * V_35 ;
struct V_36 * V_6 = & V_33 -> V_6 ;
struct V_4 * V_5 ;
struct V_1 * V_2 ;
struct V_37 * V_38 ;
int V_8 ;
V_35 = F_10 ( & V_33 -> V_6 ) ;
if ( ! V_35 ) {
F_11 ( V_6 , L_1 ) ;
V_8 = - V_39 ;
goto V_40;
}
V_5 = F_12 ( sizeof( * V_5 ) , V_41 ) ;
if ( ! V_5 ) {
F_11 ( V_6 , L_2 ) ;
V_8 = - V_42 ;
goto V_40;
}
F_13 ( V_33 , V_5 ) ;
F_14 ( & V_5 -> V_12 ) ;
V_38 = F_15 ( V_33 , V_43 , 0 ) ;
if ( ! V_38 ) {
F_11 ( V_6 , L_3 ) ;
V_8 = - V_44 ;
goto V_45;
}
V_5 -> V_15 = F_16 ( V_38 -> V_46 , F_17 ( V_38 ) ) ;
if ( ! V_5 -> V_15 ) {
F_11 ( V_6 , L_4 ) ;
V_8 = - V_42 ;
goto V_45;
}
F_8 ( V_5 ) ;
V_2 = & V_5 -> V_2 ;
V_2 -> V_6 = & V_33 -> V_6 ;
V_2 -> V_47 = V_33 -> V_48 ;
V_2 -> V_49 = F_1 ;
V_2 -> V_50 = F_5 ;
V_2 -> V_51 = V_52 ;
V_2 -> V_53 = - 1 ;
V_2 -> V_54 = 20 ;
V_8 = F_18 ( V_2 ) ;
if ( V_8 ) {
F_11 ( V_6 , L_5 ) ;
goto V_55;
}
return 0 ;
V_55:
F_19 ( V_5 -> V_15 ) ;
V_45:
F_20 ( V_5 ) ;
V_40:
return V_8 ;
}
static int F_21 ( struct V_32 * V_33 )
{
struct V_4 * V_5 = F_22 ( V_33 ) ;
struct V_36 * V_6 = & V_33 -> V_6 ;
int V_8 ;
V_8 = F_23 ( & V_5 -> V_2 ) ;
if ( V_8 ) {
F_11 ( V_6 , L_6 ) ;
return V_8 ;
}
F_19 ( V_5 -> V_15 ) ;
F_20 ( V_5 ) ;
return 0 ;
}
