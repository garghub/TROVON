static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = V_6 -> V_9 ;
void T_1 * V_10 = V_4 -> V_10 ;
void T_1 * V_11 = V_4 -> V_11 ;
static const T_2 V_12 [] = { V_13 , V_14 , V_15 } ;
int V_16 ;
T_3 V_17 ;
unsigned long V_18 ;
F_3 ( & V_4 -> V_19 , V_18 ) ;
if ( V_4 -> V_20 ++ == 0 ) {
F_4 ( V_21 , ( V_10 + V_22 ) ) ;
F_4 ( V_21 | V_23 , ( V_10 + V_22 ) ) ;
if ( V_11 ) {
T_3 V_24 = V_8 -> V_25 ? 0x41 : 0 ;
T_3 V_26 = V_8 -> V_25 ? 0x0d : 7 ;
F_4 ( V_24 , V_11 + V_27 ) ;
F_4 ( V_26 , V_11 + V_28 ) ;
}
for ( V_16 = 0 ; V_16 < 1024 ; V_16 ++ ) {
F_5 ( 10 ) ;
V_17 = F_6 ( V_10 + V_29 ) ;
if ( V_17 == ( V_30 | V_31 ) )
break;
}
if ( V_17 != ( V_30 | V_31 ) ) {
F_7 ( V_6 , L_1 ) ;
goto V_32;
}
F_4 ( V_21 | V_23 | V_33 , ( V_10 + V_22 ) ) ;
V_17 = 0 ;
if ( V_8 -> V_34 )
V_17 |= V_35 ;
if ( V_8 -> V_36 )
V_17 |= V_37 ;
for ( V_16 = 0 ; V_16 < 3 ; V_16 ++ ) {
if ( V_8 -> V_38 [ V_16 ] . V_39 )
V_17 |= V_40 << V_16 ;
if ( V_8 -> V_38 [ V_16 ] . V_41 )
V_17 |= V_12 [ V_16 ] ;
}
F_4 ( V_17 , ( V_10 + V_42 ) ) ;
F_4 ( 0x00000000 , ( V_10 + V_43 ) ) ;
F_4 ( 0x00000000 , ( V_10 + V_44 ) ) ;
}
V_32:
F_8 ( & V_4 -> V_19 , V_18 ) ;
return 0 ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
void T_1 * V_10 = V_4 -> V_10 ;
unsigned long V_18 ;
F_3 ( & V_4 -> V_19 , V_18 ) ;
if ( V_4 -> V_20 -- == 1 )
F_4 ( 0x00000000 , ( V_10 + V_22 ) ) ;
F_8 ( & V_4 -> V_19 , V_18 ) ;
}
static int F_10 ( struct V_45 * V_46 )
{
struct V_3 * V_4 ;
struct V_47 * V_48 , * V_49 ;
struct V_5 * V_6 = & V_46 -> V_6 ;
void T_1 * V_10 , * V_11 = NULL ;
int V_50 ;
if ( ! V_46 -> V_6 . V_9 ) {
F_7 ( V_6 , L_2 ) ;
return - V_51 ;
}
V_48 = F_11 ( V_46 , V_52 , 0 ) ;
if ( ! V_48 ) {
F_7 ( V_6 , L_3 ) ;
return - V_51 ;
}
V_10 = F_12 ( V_6 , V_48 ) ;
if ( F_13 ( V_10 ) )
return F_14 ( V_10 ) ;
V_49 = F_11 ( V_46 , V_52 , 1 ) ;
if ( V_49 ) {
V_11 = F_12 ( V_6 , V_49 ) ;
if ( F_13 ( V_11 ) )
return F_14 ( V_11 ) ;
}
V_4 = F_15 ( V_6 , sizeof( * V_4 ) , V_53 ) ;
if ( ! V_4 ) {
F_7 ( V_6 , L_4 ) ;
return - V_54 ;
}
V_4 -> V_10 = V_10 ;
V_4 -> V_11 = V_11 ;
V_4 -> V_20 = 0 ;
V_4 -> V_2 . V_6 = V_6 ;
V_4 -> V_2 . V_55 = F_16 ( V_6 ) ;
V_4 -> V_2 . V_56 = F_1 ;
V_4 -> V_2 . V_57 = F_9 ;
F_17 ( & V_4 -> V_19 ) ;
V_50 = F_18 ( & V_4 -> V_2 , V_58 ) ;
if ( V_50 < 0 ) {
F_7 ( V_6 , L_5 ) ;
return V_50 ;
}
F_19 ( V_46 , V_4 ) ;
return V_50 ;
}
static int F_20 ( struct V_45 * V_46 )
{
struct V_3 * V_4 = F_21 ( V_46 ) ;
F_22 ( & V_4 -> V_2 ) ;
return 0 ;
}
