static int T_1 F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
T_2 * V_5 ;
int V_6 ;
V_6 = F_2 ( V_2 ) ;
if ( V_6 )
return V_6 ;
if ( ! ( V_5 = F_3 ( sizeof( T_2 ) , V_7 ) ) ) {
F_4 ( V_8 L_1 ) ;
V_6 = - V_9 ;
goto V_10;
}
V_5 -> V_11 = V_12 ;
V_5 -> V_13 = V_2 -> V_13 -> V_14 ;
V_5 -> V_15 = V_2 -> V_15 ;
V_5 -> V_16 = V_2 -> V_17 ;
V_5 -> V_18 = V_2 -> V_18 ;
V_5 -> V_19 = F_5 ( V_2 , V_20 ) ;
V_5 -> V_21 = F_5 ( V_2 , V_22 ) ;
V_5 -> V_23 = F_5 ( V_2 , V_24 ) ;
V_5 -> V_25 = V_26 ;
V_5 -> V_27 = V_28 ;
V_5 -> V_29 = 0 ;
V_5 -> V_30 = 2 ;
V_5 -> V_25 = V_4 -> V_31 ;
if ( F_6 ( V_5 ) ) {
F_4 ( V_32 L_2 , V_5 -> V_19 ) ;
V_6 = - V_33 ;
goto V_34;
}
V_12 ++ ;
V_5 -> V_35 = NULL ;
if ( V_36 )
V_36 -> V_35 = V_5 ;
else
V_37 = V_5 ;
V_36 = V_5 ;
F_7 ( V_2 , V_5 ) ;
return 0 ;
V_34:
F_8 ( V_5 ) ;
V_10:
F_9 ( V_2 ) ;
return V_6 ;
}
static void T_3 F_10 ( struct V_1 * V_2 )
{
T_2 * V_5 = F_11 ( V_2 ) ;
F_7 ( V_2 , NULL ) ;
if ( V_5 -> V_38 )
V_5 -> V_38 ( V_5 ) ;
#ifdef F_12
F_13 ( V_5 ) ;
#endif
if ( V_5 -> V_39 )
V_5 -> V_39 ( V_5 ) ;
if ( V_5 == V_37 ) {
V_37 = V_37 -> V_35 ;
if ( ! V_37 )
V_36 = NULL ;
} else {
T_2 * V_40 = V_37 ;
while ( V_40 ) {
if ( V_40 -> V_35 == V_5 )
V_40 -> V_35 = V_5 -> V_35 ;
V_36 = V_40 ;
V_40 = V_40 -> V_35 ;
}
}
F_8 ( V_5 ) ;
F_9 ( V_2 ) ;
}
static int T_4
F_14 ( void )
{
int V_6 ;
F_4 ( V_41 L_3 ) ;
V_6 = F_15 ( & V_42 ) ;
if ( V_6 )
return V_6 ;
F_4 ( V_43 L_4 , V_12 ) ;
if ( ! F_16 () )
V_44 = 1 ;
#ifdef F_12
if ( V_12 > 0 ) {
if ( F_17 () ) {
F_4 ( V_8 L_5 ) ;
if ( V_44 )
F_18 () ;
F_19 ( & V_42 ) ;
return - V_45 ;
}
}
#endif
return 0 ;
}
static void T_5
F_20 ( void )
{
if ( V_44 )
F_18 () ;
F_19 ( & V_42 ) ;
#ifdef F_12
F_21 () ;
#endif
F_4 ( V_41 L_6 ) ;
}
