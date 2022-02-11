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
return F_5 ( V_2 , V_9 , V_10 ) ;
}
static int T_1 F_6 ( struct V_1 * V_2 )
{
if ( F_4 ( V_2 -> V_3 -> V_4 ) ) {
V_2 -> V_5 = V_6 ;
V_2 -> V_7 |= V_8 ;
}
if ( V_11 )
return F_7 ( V_2 , V_10 ) ;
else if ( F_8 ( V_2 -> V_3 -> V_4 ) )
return F_9 ( V_2 , V_9 , V_10 ) ;
else
return F_10 ( V_2 , V_9 , V_10 ) ;
}
static int T_1 F_11 ( struct V_12 * V_3 )
{
struct V_13 * V_4 = V_3 -> V_4 ;
int V_14 ;
V_10 = F_12 ( V_3 -> V_4 , V_9 ) ;
if ( F_13 ( V_10 ) )
return F_14 ( V_10 ) ;
if ( V_11 ) {
V_15 . V_16 = L_1 ;
V_17 . V_18 = F_15 ( V_19 ) ;
V_17 . V_20 = F_15 ( V_21 ) ;
} else if ( F_8 ( V_3 -> V_4 ) ) {
V_15 . V_16 = L_2 ;
} else {
V_15 . V_16 = L_3 ;
V_17 . V_18 = F_15 ( V_22 ) ;
V_17 . V_20 = F_15 ( V_23 ) ;
if ( ! F_1 () )
V_17 . V_24 = V_25 ;
}
if ( F_1 () ) {
V_17 . V_18 = F_15 ( V_26 ) ;
V_17 . V_20 = F_15 ( V_27 ) ;
V_17 . V_28 = 2 ;
}
V_14 = F_16 ( V_3 , V_29 ) ;
if ( V_14 < 0 )
goto V_30;
V_17 . V_31 = V_29 [ V_32 ] . V_33 ;
V_17 . V_34 = V_29 [ V_35 ] . V_33 ;
if ( F_1 () ) {
V_14 = F_17 ( V_3 , & V_36 ,
F_3 ) ;
if ( V_14 < 0 )
goto V_30;
}
V_14 = F_17 ( V_3 , & V_15 , F_6 ) ;
if ( V_14 < 0 )
goto V_30;
F_18 ( V_3 , & V_37 ) ;
F_19 ( & V_4 -> V_38 , L_4 V_39 L_5 ,
V_40 ) ;
return 0 ;
V_30:
F_20 ( V_10 ) ;
return V_14 ;
}
static int T_2 F_21 ( struct V_12 * V_3 )
{
F_20 ( V_10 ) ;
return 0 ;
}
static int T_1 F_22 ( void )
{
return F_23 ( & V_41 ) ;
}
static void T_2 F_24 ( void )
{
F_25 ( & V_41 ) ;
}
