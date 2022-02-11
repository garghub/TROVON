static inline bool F_1 ( void )
{
#ifdef F_2
return true ;
#else
return false ;
#endif
}
static int T_1 F_3 ( struct V_1 * V_2 )
{
if ( F_4 ( V_2 -> V_3 -> V_4 ) ) {
V_2 -> V_5 = V_6 ;
V_2 -> V_7 |= V_8 ;
}
return F_5 ( V_2 , V_9 ) ;
}
static int T_1 F_6 ( struct V_1 * V_2 )
{
if ( F_4 ( V_2 -> V_3 -> V_4 ) ) {
V_2 -> V_5 = V_6 ;
V_2 -> V_7 |= V_8 ;
}
if ( V_10 )
return F_7 ( V_2 ) ;
else if ( F_8 ( V_2 -> V_3 -> V_4 ) )
return F_9 ( V_2 , V_9 ) ;
else
return F_10 ( V_2 , V_9 ) ;
}
static int T_1 F_11 ( struct V_11 * V_3 )
{
struct V_12 * V_4 = V_3 -> V_4 ;
int V_13 ;
V_13 = F_12 ( V_3 -> V_4 , V_9 ) ;
if ( V_13 < 0 )
return V_13 ;
if ( V_10 ) {
V_14 . V_15 = L_1 ;
V_16 . V_17 = F_13 ( V_18 ) ;
V_16 . V_19 = F_13 ( V_20 ) ;
} else if ( F_8 ( V_3 -> V_4 ) ) {
V_14 . V_15 = L_2 ;
} else {
V_14 . V_15 = L_3 ;
V_16 . V_17 = F_13 ( V_21 ) ;
V_16 . V_19 = F_13 ( V_22 ) ;
if ( ! F_1 () )
V_16 . V_23 = V_24 ;
}
if ( F_1 () ) {
V_16 . V_17 = F_13 ( V_25 ) ;
V_16 . V_19 = F_13 ( V_26 ) ;
V_16 . V_27 = 2 ;
}
V_13 = F_14 ( V_3 , V_28 ) ;
if ( V_13 < 0 )
goto V_29;
V_16 . V_30 = V_28 [ V_31 ] . V_32 ;
V_16 . V_33 = V_28 [ V_34 ] . V_32 ;
if ( F_1 () ) {
V_13 = F_15 ( V_3 , & V_35 ,
F_3 ) ;
if ( V_13 < 0 )
goto V_29;
}
V_13 = F_15 ( V_3 , & V_14 , F_6 ) ;
if ( V_13 < 0 )
goto V_29;
F_16 ( V_3 , & V_36 ) ;
F_17 ( & V_4 -> V_37 , L_4 V_38 L_5 ,
V_39 ) ;
return 0 ;
V_29:
F_18 () ;
return V_13 ;
}
static int T_2 F_19 ( struct V_11 * V_3 )
{
F_18 () ;
return 0 ;
}
static int T_1 F_20 ( void )
{
return F_21 ( & V_40 ) ;
}
static void T_2 F_22 ( void )
{
F_23 ( & V_40 ) ;
}
