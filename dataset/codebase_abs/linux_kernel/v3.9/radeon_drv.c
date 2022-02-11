static inline void F_1 ( void ) {}
static inline void F_2 ( void ) {}
static int F_3 ( struct V_1 * V_2 , T_1 V_3 )
{
T_2 * V_4 = V_2 -> V_5 ;
if ( ( V_4 -> V_6 & V_7 ) >= V_8 )
return 0 ;
if ( ( V_4 -> V_6 & V_7 ) >= V_9 )
F_4 ( V_10 , 0 ) ;
F_4 ( V_11 , 0 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
T_2 * V_4 = V_2 -> V_5 ;
if ( ( V_4 -> V_6 & V_7 ) >= V_8 )
return 0 ;
if ( ( V_4 -> V_6 & V_7 ) >= V_9 )
F_4 ( V_10 , V_4 -> V_12 ) ;
F_4 ( V_11 , V_4 -> V_13 ) ;
return 0 ;
}
static int F_6 ( struct V_14 * V_15 )
{
struct V_16 * V_17 ;
bool V_18 = false ;
V_17 = F_7 ( 1 ) ;
if ( ! V_17 )
return - V_19 ;
V_17 -> V_20 [ 0 ] . V_21 = F_8 ( V_15 , 0 ) ;
V_17 -> V_20 [ 0 ] . V_22 = F_9 ( V_15 , 0 ) ;
#ifdef F_10
V_18 = V_15 -> V_23 [ V_24 ] . V_6 & V_25 ;
#endif
F_11 ( V_17 , L_1 , V_18 ) ;
F_12 ( V_17 ) ;
return 0 ;
}
static int F_13 ( struct V_14 * V_15 ,
const struct V_26 * V_27 )
{
int V_28 ;
V_28 = F_6 ( V_15 ) ;
if ( V_28 )
return V_28 ;
return F_14 ( V_15 , V_27 , & V_29 ) ;
}
static void
F_15 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_16 ( V_15 ) ;
F_17 ( V_2 ) ;
}
static int
F_18 ( struct V_14 * V_15 , T_1 V_3 )
{
struct V_1 * V_2 = F_16 ( V_15 ) ;
return F_19 ( V_2 , V_3 ) ;
}
static int
F_20 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_16 ( V_15 ) ;
return F_21 ( V_2 ) ;
}
static int T_3 F_22 ( void )
{
if ( V_30 == 1 ) {
F_23 ( L_2 ) ;
V_31 = & V_29 ;
V_32 = & V_33 ;
V_31 -> V_34 |= V_35 ;
V_31 -> V_36 = V_37 ;
F_1 () ;
} else {
#ifdef F_24
F_23 ( L_3 ) ;
V_31 = & V_38 ;
V_32 = & V_39 ;
V_31 -> V_34 &= ~ V_35 ;
V_31 -> V_36 = V_40 ;
#else
F_25 ( L_4 ) ;
return - V_41 ;
#endif
}
return F_26 ( V_31 , V_32 ) ;
}
static void T_4 F_27 ( void )
{
F_28 ( V_31 , V_32 ) ;
F_2 () ;
}
