static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
int V_9 = 0 , V_10 ;
unsigned long V_11 ;
V_4 = F_2 ( & V_12 ,
& V_2 -> V_13 , L_1 ) ;
if ( ! V_4 ) {
V_9 = - V_14 ;
goto V_15;
}
V_8 = F_3 ( V_2 , V_16 , 0 ) ;
V_4 -> V_17 = F_4 ( & V_2 -> V_13 , V_8 ) ;
if ( F_5 ( V_4 -> V_17 ) ) {
V_9 = F_6 ( V_4 -> V_17 ) ;
goto V_18;
}
V_4 -> V_19 = V_8 -> V_20 ;
V_4 -> V_21 = F_7 ( V_8 ) ;
V_6 = F_8 ( V_4 ) ;
V_6 -> V_22 = V_4 -> V_17 ;
V_6 -> V_17 = V_4 -> V_17 +
F_9 ( V_6 , F_10 ( V_6 , & V_6 -> V_22 -> V_23 ) ) ;
V_11 = F_11 ( V_6 -> V_17 + V_24 ) ;
V_11 |= V_25 ;
F_12 ( V_11 , V_6 -> V_17 + V_24 ) ;
V_11 = F_11 ( V_6 -> V_17 + V_26 ) ;
V_11 |= V_25 ;
F_12 ( V_11 , V_6 -> V_17 + V_26 ) ;
V_10 = F_13 ( V_2 , 0 ) ;
if ( V_10 < 0 ) {
V_9 = V_10 ;
goto V_18;
}
V_9 = F_14 ( V_4 , V_10 , V_27 ) ;
if ( V_9 != 0 )
goto V_18;
F_15 ( V_4 -> V_28 . V_29 ) ;
return V_9 ;
V_18:
F_16 ( V_4 ) ;
V_15:
return V_9 ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_18 ( V_2 ) ;
F_19 ( V_4 ) ;
F_16 ( V_4 ) ;
return 0 ;
}
static int T_1 F_20 ( void )
{
if ( F_21 () )
return - V_30 ;
F_22 ( L_2 V_31 L_3 , V_32 ) ;
F_23 ( & V_12 , NULL ) ;
return F_24 ( & V_33 ) ;
}
static void T_2 F_25 ( void )
{
F_26 ( & V_33 ) ;
}
