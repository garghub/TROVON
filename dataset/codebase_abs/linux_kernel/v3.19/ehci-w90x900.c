static int F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
int V_11 = 0 , V_12 ;
unsigned long V_13 ;
V_6 = F_2 ( V_2 , & V_4 -> V_14 , L_1 ) ;
if ( ! V_6 ) {
V_11 = - V_15 ;
goto V_16;
}
V_10 = F_3 ( V_4 , V_17 , 0 ) ;
V_6 -> V_18 = F_4 ( & V_4 -> V_14 , V_10 ) ;
if ( F_5 ( V_6 -> V_18 ) ) {
V_11 = F_6 ( V_6 -> V_18 ) ;
goto V_19;
}
V_6 -> V_20 = V_10 -> V_21 ;
V_6 -> V_22 = F_7 ( V_10 ) ;
V_8 = F_8 ( V_6 ) ;
V_8 -> V_23 = V_6 -> V_18 ;
V_8 -> V_18 = V_6 -> V_18 +
F_9 ( V_8 , F_10 ( V_8 , & V_8 -> V_23 -> V_24 ) ) ;
V_13 = F_11 ( V_8 -> V_18 + V_25 ) ;
V_13 |= V_26 ;
F_12 ( V_13 , V_8 -> V_18 + V_25 ) ;
V_13 = F_11 ( V_8 -> V_18 + V_27 ) ;
V_13 |= V_26 ;
F_12 ( V_13 , V_8 -> V_18 + V_27 ) ;
V_12 = F_13 ( V_4 , 0 ) ;
if ( V_12 < 0 ) {
V_11 = V_12 ;
goto V_19;
}
V_11 = F_14 ( V_6 , V_12 , V_28 ) ;
if ( V_11 != 0 )
goto V_19;
F_15 ( V_6 -> V_29 . V_30 ) ;
return V_11 ;
V_19:
F_16 ( V_6 ) ;
V_16:
return V_11 ;
}
static void F_17 ( struct V_5 * V_6 ,
struct V_3 * V_4 )
{
F_18 ( V_6 ) ;
F_16 ( V_6 ) ;
}
static int F_19 ( struct V_3 * V_4 )
{
if ( F_20 () )
return - V_31 ;
return F_1 ( & V_32 , V_4 ) ;
}
static int F_21 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_22 ( V_4 ) ;
F_17 ( V_6 , V_4 ) ;
return 0 ;
}
static int T_1 F_23 ( void )
{
if ( F_20 () )
return - V_31 ;
F_24 ( L_2 V_33 L_3 , V_34 ) ;
F_25 ( & V_32 , NULL ) ;
return F_26 ( & V_35 ) ;
}
static void T_2 F_27 ( void )
{
F_28 ( & V_35 ) ;
}
