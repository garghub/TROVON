static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
void T_1 * V_9 = V_4 -> V_9 ;
void T_1 * V_10 = V_4 -> V_10 ;
static const T_2 V_11 [] = { V_12 , V_13 , V_14 } ;
int V_15 ;
T_3 V_16 ;
unsigned long V_17 ;
F_4 ( & V_4 -> V_18 , V_17 ) ;
if ( V_4 -> V_19 ++ == 0 ) {
F_5 ( V_20 , ( V_9 + V_21 ) ) ;
F_5 ( V_20 | V_22 , ( V_9 + V_21 ) ) ;
if ( V_10 ) {
T_3 V_23 = V_8 -> V_24 ? 0x41 : 0 ;
T_3 V_25 = V_8 -> V_24 ? 0x0d : 7 ;
F_5 ( V_23 , V_10 + V_26 ) ;
F_5 ( V_25 , V_10 + V_27 ) ;
}
for ( V_15 = 0 ; V_15 < 1024 ; V_15 ++ ) {
F_6 ( 10 ) ;
V_16 = F_7 ( V_9 + V_28 ) ;
if ( V_16 == ( V_29 | V_30 ) )
break;
}
if ( V_16 != ( V_29 | V_30 ) ) {
F_8 ( V_6 , L_1 ) ;
goto V_31;
}
F_5 ( V_20 | V_22 | V_32 , ( V_9 + V_21 ) ) ;
V_16 = 0 ;
if ( V_8 -> V_33 )
V_16 |= V_34 ;
if ( V_8 -> V_35 )
V_16 |= V_36 ;
for ( V_15 = 0 ; V_15 < 3 ; V_15 ++ ) {
if ( V_8 -> V_37 [ V_15 ] . V_38 )
V_16 |= V_39 << V_15 ;
if ( V_8 -> V_37 [ V_15 ] . V_40 )
V_16 |= V_11 [ V_15 ] ;
}
F_5 ( V_16 , ( V_9 + V_41 ) ) ;
F_5 ( 0x00000000 , ( V_9 + V_42 ) ) ;
F_5 ( 0x00000000 , ( V_9 + V_43 ) ) ;
}
V_31:
F_9 ( & V_4 -> V_18 , V_17 ) ;
return 0 ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
void T_1 * V_9 = V_4 -> V_9 ;
unsigned long V_17 ;
F_4 ( & V_4 -> V_18 , V_17 ) ;
if ( V_4 -> V_19 -- == 1 )
F_5 ( 0x00000000 , ( V_9 + V_21 ) ) ;
F_9 ( & V_4 -> V_18 , V_17 ) ;
}
static int F_11 ( struct V_44 * V_45 )
{
struct V_3 * V_4 ;
struct V_46 * V_47 , * V_48 ;
struct V_5 * V_6 = & V_45 -> V_6 ;
void T_1 * V_9 , * V_10 = NULL ;
int V_49 ;
if ( ! F_3 ( & V_45 -> V_6 ) ) {
F_8 ( V_6 , L_2 ) ;
return - V_50 ;
}
V_47 = F_12 ( V_45 , V_51 , 0 ) ;
V_9 = F_13 ( V_6 , V_47 ) ;
if ( F_14 ( V_9 ) )
return F_15 ( V_9 ) ;
V_48 = F_12 ( V_45 , V_51 , 1 ) ;
V_10 = F_13 ( V_6 , V_48 ) ;
if ( F_14 ( V_10 ) )
return F_15 ( V_10 ) ;
V_4 = F_16 ( V_6 , sizeof( * V_4 ) , V_52 ) ;
if ( ! V_4 )
return - V_53 ;
V_4 -> V_9 = V_9 ;
V_4 -> V_10 = V_10 ;
V_4 -> V_19 = 0 ;
V_4 -> V_2 . V_6 = V_6 ;
V_4 -> V_2 . V_54 = F_17 ( V_6 ) ;
V_4 -> V_2 . V_55 = F_1 ;
V_4 -> V_2 . V_56 = F_10 ;
F_18 ( & V_4 -> V_18 ) ;
V_49 = F_19 ( & V_4 -> V_2 , V_57 ) ;
if ( V_49 < 0 ) {
F_8 ( V_6 , L_3 ) ;
return V_49 ;
}
F_20 ( V_45 , V_4 ) ;
return V_49 ;
}
static int F_21 ( struct V_44 * V_45 )
{
struct V_3 * V_4 = F_22 ( V_45 ) ;
F_23 ( & V_4 -> V_2 ) ;
return 0 ;
}
