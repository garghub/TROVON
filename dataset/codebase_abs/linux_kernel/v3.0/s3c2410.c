static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned long V_5 = F_2 ( V_2 , V_6 ) ;
if ( strcmp ( V_4 -> V_7 , L_1 ) == 0 )
V_5 |= V_8 ;
else
V_5 &= ~ V_8 ;
F_3 ( V_2 , V_6 , V_5 ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned long V_5 = F_2 ( V_2 , V_6 ) ;
V_4 -> V_9 = 1 ;
V_4 -> V_7 = ( V_5 & V_8 ) ? L_1 : L_2 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
F_6 ( L_3 ,
V_2 , V_2 -> V_12 , V_11 ) ;
F_3 ( V_2 , V_6 , V_11 -> V_5 ) ;
F_3 ( V_2 , V_13 , V_11 -> V_14 ) ;
F_3 ( V_2 , V_15 , V_11 -> V_16 | V_17 ) ;
F_3 ( V_2 , V_15 , V_11 -> V_16 ) ;
return 0 ;
}
static int F_7 ( struct V_18 * V_19 )
{
return F_8 ( V_19 , & V_20 ) ;
}
static int T_1 F_9 ( void )
{
return F_10 ( & V_21 , & V_20 ) ;
}
static void T_2 F_11 ( void )
{
F_12 ( & V_21 ) ;
}
