static void F_1 ( void )
{
union V_1 V_2 ;
F_2 () ;
V_2 . V_3 = F_3 ( F_4 ( 0 ) ) ;
V_2 . V_4 . V_5 = 0 ;
V_2 . V_4 . V_6 = 1 ;
V_2 . V_4 . V_7 = 1 ;
F_5 ( F_4 ( 0 ) , V_2 . V_3 ) ;
}
static void F_6 ( void )
{
F_7 () ;
}
static int T_1 F_8 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = F_9 ( V_9 ) ;
int V_12 ;
V_12 = F_10 ( V_11 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_11 ( V_11 ) ;
if ( V_12 < 0 ) {
F_12 ( V_11 , L_1 , V_9 -> V_13 . V_14 ) ;
F_13 ( V_9 ) ;
return V_12 ;
}
return 0 ;
}
static int F_14 ( struct V_15 * V_16 )
{
struct V_8 * V_9 ;
struct V_10 * V_11 ;
void * V_17 ;
struct V_18 * V_19 ;
int V_20 ;
int V_12 ;
if ( F_15 () )
return - V_21 ;
V_20 = F_16 ( V_16 , 0 ) ;
if ( V_20 < 0 ) {
F_17 ( & V_16 -> V_22 , L_2 ) ;
return - V_21 ;
}
V_19 = F_18 ( V_16 , V_23 , 0 ) ;
if ( V_19 == NULL ) {
F_17 ( & V_16 -> V_22 , L_3 ) ;
return - V_21 ;
}
V_16 -> V_22 . V_24 = F_19 ( 32 ) ;
V_16 -> V_22 . V_25 = & V_16 -> V_22 . V_24 ;
V_9 = F_20 ( & V_26 , & V_16 -> V_22 , L_4 ) ;
if ( ! V_9 )
return - V_27 ;
V_9 -> V_28 = V_19 -> V_29 ;
V_9 -> V_30 = F_21 ( V_19 ) ;
if ( ! F_22 ( V_9 -> V_28 , V_9 -> V_30 ,
V_31 ) ) {
F_17 ( & V_16 -> V_22 , L_5 ) ;
V_12 = - V_32 ;
goto V_33;
}
V_17 = F_23 ( V_9 -> V_28 , V_9 -> V_30 ) ;
if ( ! V_17 ) {
F_17 ( & V_16 -> V_22 , L_6 ) ;
V_12 = - V_27 ;
goto V_34;
}
F_1 () ;
V_9 -> V_35 = V_17 ;
V_11 = F_9 ( V_9 ) ;
#ifdef F_24
V_11 -> V_36 |= V_37 ;
#endif
F_25 ( V_11 ) ;
V_12 = F_26 ( V_9 , V_20 , V_38 ) ;
if ( V_12 ) {
F_27 ( & V_16 -> V_22 , L_7 , V_12 ) ;
goto V_39;
}
F_28 ( V_16 , V_9 ) ;
return 0 ;
V_39:
F_6 () ;
F_29 ( V_9 -> V_35 ) ;
V_34:
F_30 ( V_9 -> V_28 , V_9 -> V_30 ) ;
V_33:
F_31 ( V_9 ) ;
return V_12 ;
}
static int F_32 ( struct V_15 * V_16 )
{
struct V_8 * V_9 = F_33 ( V_16 ) ;
F_34 ( V_9 ) ;
F_6 () ;
F_29 ( V_9 -> V_35 ) ;
F_30 ( V_9 -> V_28 , V_9 -> V_30 ) ;
F_31 ( V_9 ) ;
F_28 ( V_16 , NULL ) ;
return 0 ;
}
