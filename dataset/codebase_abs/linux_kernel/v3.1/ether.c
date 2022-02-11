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
int V_12 ;
struct V_13 * V_4 = V_3 -> V_4 ;
int V_14 ;
V_14 = F_12 ( V_3 -> V_4 , V_9 ) ;
if ( V_14 < 0 )
return V_14 ;
if ( V_10 ) {
V_15 . V_16 = L_1 ;
V_17 . V_18 = F_13 ( V_19 ) ;
V_17 . V_20 = F_13 ( V_21 ) ;
} else if ( F_8 ( V_3 -> V_4 ) ) {
V_15 . V_16 = L_2 ;
} else {
V_15 . V_16 = L_3 ;
V_17 . V_18 = F_13 ( V_22 ) ;
V_17 . V_20 = F_13 ( V_23 ) ;
if ( ! F_1 () )
V_17 . V_24 = V_25 ;
}
if ( F_1 () ) {
V_17 . V_18 = F_13 ( V_26 ) ;
V_17 . V_20 = F_13 ( V_27 ) ;
V_17 . V_28 = 2 ;
}
V_12 = F_14 ( V_4 ) ;
if ( V_12 >= 0 )
V_17 . V_29 = F_13 ( 0x0300 | V_12 ) ;
else {
F_15 ( & V_4 -> V_30 ,
L_4 ,
V_4 -> V_31 ,
V_15 . V_16 ) ;
V_17 . V_29 =
F_13 ( 0x0300 | 0x0099 ) ;
}
snprintf ( V_32 , sizeof V_32 , L_5 ,
F_16 () -> V_33 , F_16 () -> V_34 ,
V_4 -> V_31 ) ;
V_14 = F_17 ( V_3 ) ;
if ( V_14 < 0 )
goto V_35;
V_36 [ V_37 ] . V_38 = V_14 ;
V_17 . V_39 = V_14 ;
V_14 = F_17 ( V_3 ) ;
if ( V_14 < 0 )
goto V_35;
V_36 [ V_40 ] . V_38 = V_14 ;
V_17 . V_41 = V_14 ;
if ( F_1 () ) {
V_14 = F_18 ( V_3 , & V_42 ,
F_3 ) ;
if ( V_14 < 0 )
goto V_35;
}
V_14 = F_18 ( V_3 , & V_15 , F_6 ) ;
if ( V_14 < 0 )
goto V_35;
F_19 ( & V_4 -> V_30 , L_6 V_43 L_7 ,
V_44 ) ;
return 0 ;
V_35:
F_20 () ;
return V_14 ;
}
static int T_2 F_21 ( struct V_11 * V_3 )
{
F_20 () ;
return 0 ;
}
static int T_1 F_22 ( void )
{
return F_23 ( & V_45 , F_11 ) ;
}
static void T_2 F_24 ( void )
{
F_25 ( & V_45 ) ;
}
