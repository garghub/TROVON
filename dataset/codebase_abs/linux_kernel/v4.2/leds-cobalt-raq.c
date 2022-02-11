static void F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
unsigned long V_5 ;
F_2 ( & V_6 , V_5 ) ;
if ( V_4 )
V_7 |= V_8 ;
else
V_7 &= ~ V_8 ;
F_3 ( V_7 , V_9 ) ;
F_4 ( & V_6 , V_5 ) ;
}
static void F_5 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
unsigned long V_5 ;
F_2 ( & V_6 , V_5 ) ;
if ( V_4 )
V_7 |= V_10 ;
else
V_7 &= ~ V_10 ;
F_3 ( V_7 , V_9 ) ;
F_4 ( & V_6 , V_5 ) ;
}
static int F_6 ( struct V_11 * V_12 )
{
struct V_13 * V_14 ;
int V_15 ;
V_14 = F_7 ( V_12 , V_16 , 0 ) ;
if ( ! V_14 )
return - V_17 ;
V_9 = F_8 ( & V_12 -> V_18 , V_14 -> V_19 , F_9 ( V_14 ) ) ;
if ( ! V_9 )
return - V_20 ;
V_15 = F_10 ( & V_12 -> V_18 , & V_21 ) ;
if ( V_15 )
goto V_22;
V_15 = F_10 ( & V_12 -> V_18 , & V_23 ) ;
if ( V_15 )
goto V_24;
return 0 ;
V_24:
F_11 ( & V_21 ) ;
V_22:
V_9 = NULL ;
return V_15 ;
}
static int T_1 F_12 ( void )
{
return F_13 ( & V_25 ) ;
}
