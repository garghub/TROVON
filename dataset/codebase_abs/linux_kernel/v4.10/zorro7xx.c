static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
unsigned long V_11 , V_12 ;
V_11 = F_2 ( V_2 ) ;
V_10 = (struct V_9 * ) V_4 -> V_13 ;
if ( V_10 -> V_14 ) {
V_12 = V_10 -> V_15 ;
} else {
V_12 = V_11 + V_10 -> V_15 ;
}
if ( ! F_3 ( V_2 , V_10 -> V_16 ) ) {
F_4 ( V_17 L_1 ,
V_11 ) ;
return - V_18 ;
}
V_8 = F_5 ( sizeof( struct V_7 ) , V_19 ) ;
if ( ! V_8 ) {
F_4 ( V_17 L_2 ) ;
goto V_20;
}
if ( V_12 > 0x01000000 )
V_8 -> V_21 = F_6 ( V_12 , F_7 ( V_2 ) ) ;
else
V_8 -> V_21 = F_8 ( V_12 ) ;
V_8 -> clock = 50 ;
V_8 -> V_22 = 1 ;
V_8 -> V_23 = V_24 ;
V_25 . V_16 = V_10 -> V_16 ;
V_6 = F_9 ( & V_25 , V_8 ,
& V_2 -> V_26 ) ;
if ( ! V_6 ) {
F_4 ( V_17 L_3
L_4 ) ;
goto V_27;
}
V_6 -> V_28 = 7 ;
V_6 -> V_21 = V_12 ;
V_6 -> V_29 = V_30 ;
if ( F_10 ( V_6 -> V_29 , V_31 , V_32 , L_5 ,
V_6 ) ) {
F_4 ( V_17 L_6 ) ;
goto V_33;
}
F_11 ( V_2 , V_6 ) ;
F_12 ( V_6 ) ;
return 0 ;
V_33:
F_13 ( V_6 ) ;
V_27:
if ( V_12 > 0x01000000 )
F_14 ( V_8 -> V_21 ) ;
F_15 ( V_8 ) ;
V_20:
F_16 ( V_2 ) ;
return - V_34 ;
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_18 ( V_2 ) ;
struct V_7 * V_8 = F_19 ( V_6 ) ;
F_20 ( V_6 ) ;
F_21 ( V_6 ) ;
F_15 ( V_8 ) ;
F_22 ( V_6 -> V_29 , V_6 ) ;
F_16 ( V_2 ) ;
}
static int T_1 F_23 ( void )
{
return F_24 ( & V_35 ) ;
}
static void T_2 F_25 ( void )
{
F_26 ( & V_35 ) ;
}
