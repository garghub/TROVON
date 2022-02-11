static int F_1 ( struct V_1 * V_2 , int V_3 )
{
unsigned short V_4 ;
if ( V_3 ) {
V_4 = F_2 ( V_2 , V_5 ) ;
F_3 ( V_2 , V_5 , V_4 | 0x0100 ) ;
V_4 = F_2 ( V_2 , V_6 ) ;
F_3 ( V_2 , V_6 , V_4 | ( 1 << 15 ) ) ;
} else {
V_4 = F_2 ( V_2 , V_5 ) ;
F_3 ( V_2 , V_5 , V_4 & ~ 0x0100 ) ;
V_4 = F_2 ( V_2 , V_6 ) ;
F_3 ( V_2 , V_6 , V_4 & ~ ( 1 << 15 ) ) ;
}
return 0 ;
}
static int F_4 ( struct V_7 * V_8 ,
struct V_9 * V_10 , int V_11 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
return F_1 ( V_2 , F_5 ( V_11 ) ) ;
}
static int F_6 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_14 * V_15 = & V_2 -> V_15 ;
unsigned short V_4 ;
F_7 ( V_15 , F_8 ( V_16 ) ) ;
F_9 ( V_15 , F_8 ( V_17 ) ) ;
V_4 = V_2 -> V_18 -> V_19 ( V_2 , V_5 ) ;
V_2 -> V_18 -> V_20 ( V_2 , V_5 , V_4 | 0x0100 ) ;
V_4 = V_2 -> V_18 -> V_19 ( V_2 , V_21 ) ;
V_2 -> V_18 -> V_20 ( V_2 , V_21 , V_4 | 0xc000 ) ;
F_10 ( V_15 , L_1 ) ;
F_10 ( V_15 , L_2 ) ;
F_10 ( V_15 , L_3 ) ;
F_10 ( V_15 , L_4 ) ;
F_10 ( V_15 , L_5 ) ;
return 0 ;
}
static int F_11 ( struct V_22 * V_23 )
{
int V_24 ;
if ( ! F_12 () )
return - V_25 ;
F_13 ( & V_23 -> V_26 , L_6
L_7
L_8 ) ;
V_27 = F_14 ( L_9 , - 1 ) ;
if ( ! V_27 )
return - V_28 ;
F_15 ( V_27 , & V_29 ) ;
V_24 = F_16 ( V_27 ) ;
if ( ! V_24 )
return 0 ;
F_17 ( V_27 ) ;
return V_24 ;
}
static int T_1 F_18 ( struct V_22 * V_23 )
{
F_19 ( V_27 ) ;
return 0 ;
}
static int T_2 F_20 ( void )
{
return F_21 ( & V_30 ) ;
}
static void T_3 F_22 ( void )
{
F_23 ( & V_30 ) ;
}
