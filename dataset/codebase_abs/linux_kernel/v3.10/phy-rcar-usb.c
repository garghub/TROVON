static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
void T_1 * V_7 = V_4 -> V_7 ;
void T_1 * V_8 = V_4 -> V_8 ;
int V_9 ;
T_2 V_10 ;
unsigned long V_11 ;
F_3 ( & V_4 -> V_12 , V_11 ) ;
if ( V_4 -> V_13 ++ == 0 ) {
F_4 ( V_14 , ( V_7 + V_15 ) ) ;
F_4 ( V_14 | V_16 , ( V_7 + V_15 ) ) ;
for ( V_9 = 0 ; V_9 < 1024 ; V_9 ++ ) {
F_5 ( 10 ) ;
V_10 = F_6 ( V_7 + V_17 ) ;
if ( V_10 == ( V_18 | V_19 ) )
break;
}
if ( V_10 != ( V_18 | V_19 ) ) {
F_7 ( V_6 , L_1 ) ;
goto V_20;
}
F_4 ( V_14 | V_16 | V_21 , ( V_7 + V_15 ) ) ;
F_4 ( 0x00000000 , ( V_7 + V_22 ) ) ;
F_4 ( 0x00ff0040 , ( V_7 + V_23 ) ) ;
F_4 ( 0x00ff0040 , ( V_8 + V_23 ) ) ;
F_4 ( 0x00000001 , ( V_7 + V_24 ) ) ;
F_4 ( 0x00000001 , ( V_8 + V_24 ) ) ;
F_4 ( 0x00000000 , ( V_7 + V_25 ) ) ;
F_4 ( 0x00000000 , ( V_7 + V_26 ) ) ;
}
V_20:
F_8 ( & V_4 -> V_12 , V_11 ) ;
return 0 ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
void T_1 * V_7 = V_4 -> V_7 ;
unsigned long V_11 ;
F_3 ( & V_4 -> V_12 , V_11 ) ;
if ( V_4 -> V_13 -- == 1 ) {
F_4 ( 0x00000000 , ( V_7 + V_22 ) ) ;
F_4 ( 0x00000000 , ( V_7 + V_15 ) ) ;
}
F_8 ( & V_4 -> V_12 , V_11 ) ;
}
static int F_10 ( struct V_27 * V_28 )
{
struct V_3 * V_4 ;
struct V_29 * V_30 , * V_31 ;
struct V_5 * V_6 = & V_28 -> V_6 ;
void T_1 * V_7 , * V_8 ;
int V_32 ;
V_30 = F_11 ( V_28 , V_33 , 0 ) ;
V_31 = F_11 ( V_28 , V_33 , 1 ) ;
if ( ! V_30 || ! V_31 ) {
F_7 ( V_6 , L_2 ) ;
return - V_34 ;
}
V_7 = F_12 ( V_6 , V_30 -> V_35 , F_13 ( V_30 ) ) ;
V_8 = F_12 ( V_6 , V_31 -> V_35 , F_13 ( V_31 ) ) ;
if ( ! V_7 || ! V_8 ) {
F_7 ( V_6 , L_3 ) ;
return - V_36 ;
}
V_4 = F_14 ( V_6 , sizeof( * V_4 ) , V_37 ) ;
if ( ! V_4 ) {
F_7 ( V_6 , L_4 ) ;
return - V_36 ;
}
V_4 -> V_7 = V_7 ;
V_4 -> V_8 = V_8 ;
V_4 -> V_13 = 0 ;
V_4 -> V_2 . V_6 = V_6 ;
V_4 -> V_2 . V_38 = F_15 ( V_6 ) ;
V_4 -> V_2 . V_39 = F_1 ;
V_4 -> V_2 . V_40 = F_9 ;
F_16 ( & V_4 -> V_12 ) ;
V_32 = F_17 ( & V_4 -> V_2 , V_41 ) ;
if ( V_32 < 0 ) {
F_7 ( V_6 , L_5 ) ;
return V_32 ;
}
F_18 ( V_28 , V_4 ) ;
return V_32 ;
}
static int F_19 ( struct V_27 * V_28 )
{
struct V_3 * V_4 = F_20 ( V_28 ) ;
F_21 ( & V_4 -> V_2 ) ;
return 0 ;
}
