int F_1 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
V_4 = & V_2 -> V_4 ;
V_5 = V_2 ;
V_4 -> V_6 = F_2 ( & V_2 -> V_7 -> V_2 , V_8 ) ;
if ( F_3 ( V_4 -> V_6 ) ) {
F_4 ( L_1 ) ;
V_3 = F_5 ( V_4 -> V_6 ) ;
goto V_9;
}
V_3 = F_6 ( V_4 -> V_6 ) ;
if ( V_3 ) {
F_4 ( L_2 ) ;
goto V_10;
}
if ( V_2 -> V_11 -> V_12 != V_13 ) {
V_4 -> clock = F_2 ( & V_2 -> V_7 -> V_2 , V_14 ) ;
if ( F_3 ( V_4 -> clock ) ) {
F_7 ( L_3 ) ;
V_4 -> clock = NULL ;
} else {
F_8 ( V_4 -> clock , V_15 ) ;
V_3 = F_9 ( V_4 -> clock ) ;
if ( V_3 ) {
F_4 ( L_4 ) ;
goto V_16;
}
}
}
F_10 ( & V_4 -> V_17 , 0 ) ;
#ifdef F_11
V_4 -> V_18 = & V_2 -> V_7 -> V_2 ;
F_12 ( V_4 -> V_18 ) ;
#endif
#ifdef F_13
F_10 ( & V_19 , 0 ) ;
#endif
return 0 ;
V_16:
F_14 ( V_4 -> clock ) ;
V_4 -> clock = NULL ;
V_10:
F_14 ( V_4 -> V_6 ) ;
V_4 -> V_6 = NULL ;
V_9:
return V_3 ;
}
void F_15 ( struct V_1 * V_2 )
{
if ( V_2 -> V_11 -> V_12 != V_13 &&
V_4 -> clock ) {
F_16 ( V_4 -> clock ) ;
F_14 ( V_4 -> clock ) ;
V_4 -> clock = NULL ;
}
F_17 ( V_4 -> V_6 ) ;
F_14 ( V_4 -> V_6 ) ;
V_4 -> V_6 = NULL ;
#ifdef F_11
F_18 ( V_4 -> V_18 ) ;
#endif
}
int F_19 ( void )
{
int V_3 = 0 ;
#ifdef F_13
F_20 ( & V_19 ) ;
F_21 ( 3 , L_5 , F_22 ( & V_19 ) ) ;
#endif
if ( ! F_23 ( V_4 -> V_6 ) )
V_3 = F_24 ( V_4 -> V_6 ) ;
return V_3 ;
}
void F_25 ( void )
{
#ifdef F_13
F_26 ( & V_19 ) ;
F_21 ( 3 , L_6 , F_22 ( & V_19 ) ) ;
#endif
if ( ! F_23 ( V_4 -> V_6 ) )
F_27 ( V_4 -> V_6 ) ;
}
int F_28 ( void )
{
#ifdef F_11
return F_29 ( V_4 -> V_18 ) ;
#else
F_10 ( & V_4 -> V_17 , 1 ) ;
return 0 ;
#endif
}
int F_30 ( void )
{
#ifdef F_11
return F_31 ( V_4 -> V_18 ) ;
#else
F_10 ( & V_4 -> V_17 , 0 ) ;
return 0 ;
#endif
}
