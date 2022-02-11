static void F_1 ( void )
{
union V_1 V_2 ;
F_2 () ;
V_2 . V_3 = F_3 ( F_4 ( 0 ) ) ;
V_2 . V_4 . V_5 = 1 ;
V_2 . V_4 . V_6 = 0 ;
V_2 . V_4 . V_7 = 1 ;
V_2 . V_4 . V_8 = 1 ;
F_5 ( F_4 ( 0 ) , V_2 . V_3 ) ;
}
static void F_6 ( void )
{
F_7 () ;
}
static int F_8 ( struct V_9 * V_10 )
{
struct V_11 * V_12 ;
struct V_13 * V_14 ;
struct V_15 * V_16 ;
int V_17 ;
int V_18 ;
if ( F_9 () )
return - V_19 ;
V_17 = F_10 ( V_10 , 0 ) ;
if ( V_17 < 0 ) {
F_11 ( & V_10 -> V_20 , L_1 ) ;
return - V_19 ;
}
V_16 = F_12 ( V_10 , V_21 , 0 ) ;
if ( V_16 == NULL ) {
F_11 ( & V_10 -> V_20 , L_2 ) ;
return - V_19 ;
}
V_10 -> V_20 . V_22 = & V_23 ;
V_18 = F_13 ( & V_10 -> V_20 , F_14 ( 32 ) ) ;
if ( V_18 )
return V_18 ;
V_12 = F_15 ( & V_24 , & V_10 -> V_20 , L_3 ) ;
if ( ! V_12 )
return - V_25 ;
V_12 -> V_26 = V_16 -> V_27 ;
V_12 -> V_28 = F_16 ( V_16 ) ;
V_12 -> V_29 = F_17 ( & V_10 -> V_20 , V_16 ) ;
if ( F_18 ( V_12 -> V_29 ) ) {
V_18 = F_19 ( V_12 -> V_29 ) ;
goto V_30;
}
F_1 () ;
V_14 = F_20 ( V_12 ) ;
#ifdef F_21
V_14 -> V_31 = 1 ;
#endif
V_14 -> V_32 = V_12 -> V_29 ;
V_18 = F_22 ( V_12 , V_17 , V_33 ) ;
if ( V_18 ) {
F_23 ( & V_10 -> V_20 , L_4 , V_18 ) ;
goto V_34;
}
F_24 ( V_12 -> V_35 . V_36 ) ;
F_25 ( V_10 , V_12 ) ;
return 0 ;
V_34:
F_6 () ;
V_30:
F_26 ( V_12 ) ;
return V_18 ;
}
static int F_27 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_28 ( V_10 ) ;
F_29 ( V_12 ) ;
F_6 () ;
F_26 ( V_12 ) ;
return 0 ;
}
