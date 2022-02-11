static unsigned long F_1 ( struct V_1 * V_1 ,
unsigned long V_2 )
{
unsigned long V_3 = F_2 ( V_1 -> V_4 ) ;
int div ;
if ( V_2 > V_3 )
return V_3 ;
div = V_3 / V_2 ;
if ( div == 3 )
return V_3 / 3 ;
div /= 2 ;
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
V_5 &= ~ V_7 ;
if ( V_2 == V_3 ) {
V_5 &= ~ V_8 ;
} else if ( ( V_3 / V_2 ) == 3 ) {
V_5 |= V_8 ;
V_5 |= V_7 ;
} else {
V_5 &= ~ V_9 ;
V_5 |= V_8 ;
V_5 |= ( ( ( V_3 / V_2 ) / 2 ) - 1 ) ;
}
F_5 ( V_5 , V_6 ) ;
return 0 ;
}
static int F_6 ( struct V_10 * V_11 , struct V_12 * V_13 )
{
struct V_1 * V_14 ;
struct V_1 * V_15 ;
struct V_1 * V_16 ;
V_16 = F_7 ( NULL , L_1 ) ;
V_15 = F_7 ( NULL , L_2 ) ;
V_14 = F_7 ( NULL , L_3 ) ;
if ( F_8 ( V_16 ) || F_8 ( V_15 ) || F_8 ( V_14 ) ) {
F_9 ( V_17 L_4 ) ;
return - V_18 ;
}
V_19 . V_4 = V_15 ;
V_20 . V_4 = V_14 ;
F_10 ( & V_19 ) ;
F_10 ( & V_20 ) ;
F_11 ( & V_19 ) ;
return 0 ;
}
static T_1 int F_12 ( void )
{
return F_13 ( & V_21 ) ;
}
int T_1 F_14 ( void )
{
F_9 ( L_5 ) ;
#ifdef F_15
F_16 ( & V_22 ) ;
F_16 ( & V_23 ) ;
#endif
F_16 ( & V_24 ) ;
return F_17 ( & V_25 ) ;
}
void T_1 F_18 ( void )
{
F_19 () ;
V_26 . V_27 = V_28 ;
V_26 . V_29 = V_30 ;
}
