int F_1 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
V_4 = & V_2 -> V_4 ;
V_5 = V_2 ;
V_4 -> V_6 = F_2 ( & V_2 -> V_7 -> V_2 , V_8 ) ;
if ( F_3 ( V_4 -> V_6 ) ) {
F_4 ( L_1 ) ;
V_3 = - V_9 ;
goto V_10;
}
V_4 -> clock = F_2 ( & V_2 -> V_7 -> V_2 , V_11 ) ;
if ( F_3 ( V_4 -> clock ) ) {
F_4 ( L_2 ) ;
V_3 = - V_9 ;
goto V_12;
}
F_5 ( & V_4 -> V_13 , 0 ) ;
#ifdef F_6
V_4 -> V_14 = & V_2 -> V_7 -> V_2 ;
F_7 ( V_4 -> V_14 ) ;
#endif
#ifdef F_8
F_5 ( & V_15 , 0 ) ;
#endif
return 0 ;
V_12:
F_9 ( V_4 -> V_6 ) ;
V_10:
return V_3 ;
}
void F_10 ( struct V_1 * V_2 )
{
F_9 ( V_4 -> V_6 ) ;
F_9 ( V_4 -> clock ) ;
#ifdef F_6
F_11 ( V_4 -> V_14 ) ;
#endif
}
int F_12 ( void )
{
int V_3 ;
#ifdef F_8
F_13 ( & V_15 ) ;
F_14 ( 3 , L_3 , F_15 ( & V_15 ) ) ;
#endif
V_3 = F_16 ( V_4 -> V_6 ) ;
return V_3 ;
}
void F_17 ( void )
{
#ifdef F_8
F_18 ( & V_15 ) ;
F_14 ( 3 , L_4 , F_15 ( & V_15 ) ) ;
#endif
F_19 ( V_4 -> V_6 ) ;
}
int F_20 ( void )
{
#ifdef F_6
return F_21 ( V_4 -> V_14 ) ;
#else
F_5 ( & V_4 -> V_13 , 1 ) ;
return 0 ;
#endif
}
int F_22 ( void )
{
#ifdef F_6
return F_23 ( V_4 -> V_14 ) ;
#else
F_5 ( & V_4 -> V_13 , 0 ) ;
return 0 ;
#endif
}
