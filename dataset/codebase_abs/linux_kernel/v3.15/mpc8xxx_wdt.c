static void F_1 ( void )
{
F_2 ( & V_1 ) ;
F_3 ( & V_2 -> V_3 , 0x556c ) ;
F_3 ( & V_2 -> V_3 , 0xaa39 ) ;
F_4 ( & V_1 ) ;
}
static void F_5 ( unsigned long V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_4 ;
F_1 () ;
F_6 ( & V_7 , V_8 + V_9 * V_6 -> V_10 / 2 ) ;
}
static int F_7 ( struct V_5 * V_6 )
{
T_1 V_11 = V_12 ;
if ( V_13 )
V_11 |= V_14 ;
if ( V_15 )
V_11 |= V_16 ;
V_11 |= V_10 << 16 ;
F_8 ( & V_2 -> V_17 , V_11 ) ;
F_9 ( & V_7 ) ;
return 0 ;
}
static int F_10 ( struct V_5 * V_6 )
{
F_1 () ;
return 0 ;
}
static int F_11 ( struct V_5 * V_6 )
{
F_6 ( & V_7 , V_8 ) ;
return 0 ;
}
static int F_12 ( struct V_18 * V_19 )
{
int V_20 ;
const struct V_21 * V_22 ;
struct V_23 * V_24 = V_19 -> V_25 . V_26 ;
const struct V_27 * V_28 ;
T_1 V_29 = F_13 () ;
bool V_30 ;
unsigned int V_31 ;
V_22 = F_14 ( V_32 , & V_19 -> V_25 ) ;
if ( ! V_22 )
return - V_33 ;
V_28 = V_22 -> V_34 ;
if ( ! V_29 || V_29 == - 1 )
return - V_33 ;
V_2 = F_15 ( V_24 , 0 ) ;
if ( ! V_2 )
return - V_35 ;
V_30 = F_16 ( & V_2 -> V_17 ) & V_12 ;
if ( ! V_30 && V_28 -> V_36 ) {
F_17 ( L_1 ) ;
V_20 = - V_37 ;
goto V_38;
}
if ( V_13 )
V_31 = ( V_10 * V_28 -> V_39 ) / V_29 ;
else
V_31 = V_10 / V_29 ;
V_40 . V_10 = V_31 ;
#ifdef F_18
V_20 = F_19 () ;
if ( V_20 )
goto V_38;
#endif
F_17 ( L_2 ,
V_15 ? L_3 : L_4 , V_10 , V_31 ) ;
if ( V_30 )
F_6 ( & V_7 , V_8 ) ;
return 0 ;
V_38:
F_20 ( V_2 ) ;
V_2 = NULL ;
return V_20 ;
}
static int F_21 ( struct V_18 * V_19 )
{
F_22 ( L_5 ,
V_15 ? L_3 : L_6 ) ;
F_9 ( & V_7 ) ;
F_23 ( & V_40 ) ;
F_20 ( V_2 ) ;
return 0 ;
}
static int F_19 ( void )
{
int V_20 ;
if ( ! V_2 )
return - V_41 ;
F_24 ( & V_40 , V_42 ) ;
V_20 = F_25 ( & V_40 ) ;
if ( V_20 ) {
F_26 ( L_7 , V_20 ) ;
return V_20 ;
}
return 0 ;
}
static int T_2 F_27 ( void )
{
return F_28 ( & V_43 ) ;
}
static void T_3 F_29 ( void )
{
F_30 ( & V_43 ) ;
}
