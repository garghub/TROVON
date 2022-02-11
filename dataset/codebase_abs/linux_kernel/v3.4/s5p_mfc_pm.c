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
V_4 -> clock = F_2 ( & V_2 -> V_7 -> V_2 , V_11 ) ;
if ( F_3 ( V_4 -> clock ) ) {
F_4 ( L_3 ) ;
V_3 = F_5 ( V_4 -> clock ) ;
goto V_12;
}
V_3 = F_6 ( V_4 -> clock ) ;
if ( V_3 ) {
F_4 ( L_4 ) ;
goto V_13;
}
F_7 ( & V_4 -> V_14 , 0 ) ;
#ifdef F_8
V_4 -> V_15 = & V_2 -> V_7 -> V_2 ;
F_9 ( V_4 -> V_15 ) ;
#endif
#ifdef F_10
F_7 ( & V_16 , 0 ) ;
#endif
return 0 ;
V_13:
F_11 ( V_4 -> clock ) ;
V_12:
F_12 ( V_4 -> V_6 ) ;
V_10:
F_11 ( V_4 -> V_6 ) ;
V_9:
return V_3 ;
}
void F_13 ( struct V_1 * V_2 )
{
F_12 ( V_4 -> V_6 ) ;
F_11 ( V_4 -> V_6 ) ;
F_12 ( V_4 -> clock ) ;
F_11 ( V_4 -> clock ) ;
#ifdef F_8
F_14 ( V_4 -> V_15 ) ;
#endif
}
int F_15 ( void )
{
int V_3 ;
#ifdef F_10
F_16 ( & V_16 ) ;
F_17 ( 3 , L_5 , F_18 ( & V_16 ) ) ;
#endif
V_3 = F_19 ( V_4 -> V_6 ) ;
return V_3 ;
}
void F_20 ( void )
{
#ifdef F_10
F_21 ( & V_16 ) ;
F_17 ( 3 , L_6 , F_18 ( & V_16 ) ) ;
#endif
F_22 ( V_4 -> V_6 ) ;
}
int F_23 ( void )
{
#ifdef F_8
return F_24 ( V_4 -> V_15 ) ;
#else
F_7 ( & V_4 -> V_14 , 1 ) ;
return 0 ;
#endif
}
int F_25 ( void )
{
#ifdef F_8
return F_26 ( V_4 -> V_15 ) ;
#else
F_7 ( & V_4 -> V_14 , 0 ) ;
return 0 ;
#endif
}
