static void F_1 ( struct V_1 * V_2 )
{
if ( F_2 ( F_3 ( V_2 ) ) )
F_4 ( V_2 ) ;
else
F_5 ( V_2 ) ;
}
static int F_6 ( struct V_3 * V_4 , unsigned int V_5 ,
T_1 V_6 )
{
struct V_7 * V_8 = V_4 -> V_9 ;
F_7 ( V_5 , V_8 , F_1 ) ;
return 0 ;
}
static void F_8 ( struct V_10 * V_11 )
{
}
static int T_2 F_9 ( struct V_12 * V_13 ,
struct V_12 * V_14 )
{
unsigned V_15 = V_16 ;
unsigned V_17 = V_18 + 1 ;
struct V_3 * V_19 ;
F_10 ( L_1 ) ;
if ( F_11 ( V_13 , L_2 ) ) {
unsigned V_20 ;
F_12 (cpu) {
void T_3 * V_21 = F_13 ( V_13 , V_20 ) ;
if ( ! V_21 ) {
F_14 ( L_3 , V_20 ) ;
return - V_22 ;
}
F_15 ( 0xffffffff , V_21 + V_23 ) ;
F_16 ( V_21 ) ;
}
V_15 = V_24 ;
}
V_25 . V_26 = F_8 ;
V_25 . V_27 = F_8 ;
V_25 . V_28 = L_4 ;
V_19 = F_17 ( V_13 , V_17 , & V_29 ,
& V_25 ) ;
if ( ! V_19 )
return - V_22 ;
F_18 ( V_19 , V_15 , V_15 , V_17 - V_15 ) ;
return 0 ;
}
