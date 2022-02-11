static int F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_3 ) ;
F_3 ( V_4 , F_4 ( V_5 ) ) ;
while ( F_5 ( F_6 ( V_5 ) ) )
F_7 () ;
F_3 ( V_6 | V_7 | V_8 , F_8 ( V_5 ) ) ;
F_3 ( V_9 , F_9 ( V_5 ) ) ;
F_3 ( V_10 , F_10 ( V_5 ) ) ;
F_3 ( 0xFFFF , F_11 ( V_5 ) ) ;
F_3 ( V_2 -> V_11 * V_12 , F_12 ( V_5 ) ) ;
F_3 ( V_13 | V_14 , F_4 ( V_5 ) ) ;
F_13 ( & V_3 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
F_2 ( & V_3 ) ;
F_3 ( 0 , F_4 ( V_5 ) ) ;
F_13 ( & V_3 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 ,
unsigned int V_15 )
{
V_2 -> V_11 = V_15 ;
return 0 ;
}
static int T_1 F_16 ( struct V_16 * V_17 )
{
struct V_18 * V_19 ;
int V_20 = 0 ;
if ( V_21 < 1 || V_21 > V_22 )
V_21 = V_23 ;
V_19 = F_17 ( V_17 , V_24 , 0 ) ;
V_5 = F_18 ( & V_17 -> V_25 , V_19 ) ;
if ( ! V_5 )
return - V_26 ;
V_27 = F_19 ( & V_17 -> V_25 , NULL ) ;
if ( F_20 ( V_27 ) )
return F_21 ( V_27 ) ;
V_20 = F_22 ( V_27 ) ;
if ( V_20 )
goto V_28;
V_29 . V_11 = V_21 ;
V_29 . V_30 = ( F_5 ( F_23 ( V_5 ) ) & V_31 ) ?
V_32 : 0 ;
F_24 ( & V_29 , V_33 ) ;
F_14 ( & V_29 ) ;
V_20 = F_25 ( & V_29 ) ;
if ( V_20 < 0 ) {
F_26 ( & V_17 -> V_25 , L_1 ) ;
goto V_34;
}
F_27 ( & V_17 -> V_25 , L_2 ,
V_21 ) ;
return 0 ;
V_34:
F_28 ( V_27 ) ;
V_28:
F_29 ( V_27 ) ;
return V_20 ;
}
static int T_2 F_30 ( struct V_16 * V_17 )
{
F_31 ( & V_29 ) ;
F_28 ( V_27 ) ;
F_29 ( V_27 ) ;
return 0 ;
}
