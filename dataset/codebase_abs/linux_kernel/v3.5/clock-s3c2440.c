static unsigned long F_1 ( struct V_1 * V_1 ,
unsigned long V_2 )
{
unsigned long V_3 = F_2 ( V_1 -> V_4 ) ;
int div ;
if ( V_2 > V_3 )
return V_3 ;
div = ( V_3 / V_2 ) / 2 ;
if ( div < 1 )
div = 1 ;
else if ( div > 16 )
div = 16 ;
return V_3 / ( div * 2 ) ;
}
static int F_3 ( struct V_1 * V_1 , unsigned long V_2 )
{
unsigned long V_3 = F_2 ( V_1 -> V_4 ) ;
unsigned long V_5 = F_4 ( V_6 ) ;
V_2 = F_1 ( V_1 , V_2 ) ;
V_5 &= ~ ( V_7 | V_8 ) ;
if ( V_2 != V_3 ) {
V_5 |= V_7 ;
V_5 |= ( ( ( V_3 / V_2 ) / 2 ) - 1 ) ;
}
F_5 ( V_5 , V_6 ) ;
return 0 ;
}
static unsigned long F_6 ( struct V_1 * V_1 )
{
unsigned long V_9 , V_10 , V_11 , V_12 ;
V_9 = F_4 ( V_13 + V_14 ) ;
V_10 = F_4 ( V_15 + V_14 ) ;
V_11 = F_4 ( V_16 + V_14 ) ;
V_9 &= V_17 ;
V_10 &= V_18 ;
V_11 &= V_19 ;
if ( V_9 != 0 )
V_12 = ( V_9 >> V_20 ) + 6 ;
else if ( V_10 != 0 )
V_12 = ( V_10 >> V_20 ) + 21 ;
else if ( V_11 != 0 )
V_12 = ( V_11 >> V_20 ) + 36 ;
else
V_12 = 9 ;
return F_2 ( V_1 -> V_4 ) / V_12 ;
}
static int F_7 ( struct V_21 * V_22 , struct V_23 * V_24 )
{
struct V_1 * V_25 ;
struct V_1 * V_26 ;
struct V_1 * V_27 ;
V_27 = F_8 ( NULL , L_1 ) ;
V_26 = F_8 ( NULL , L_2 ) ;
V_25 = F_8 ( NULL , L_3 ) ;
if ( F_9 ( V_27 ) || F_9 ( V_26 ) || F_9 ( V_25 ) ) {
F_10 ( V_28 L_4 ) ;
return - V_29 ;
}
V_30 . V_4 = V_26 ;
V_31 . V_4 = V_27 ;
V_32 . V_4 = V_25 ;
F_11 ( & V_33 ) ;
F_11 ( & V_31 ) ;
F_11 ( & V_30 ) ;
F_11 ( & V_32 ) ;
F_12 ( V_34 , F_13 ( V_34 ) ) ;
F_14 ( & V_31 ) ;
F_14 ( & V_30 ) ;
return 0 ;
}
static T_1 int F_15 ( void )
{
return F_16 ( & V_35 ) ;
}
