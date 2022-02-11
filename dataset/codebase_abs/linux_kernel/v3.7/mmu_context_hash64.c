int F_1 ( void )
{
int V_1 ;
int V_2 ;
V_3:
if ( ! F_2 ( & V_4 , V_5 ) )
return - V_6 ;
F_3 ( & V_7 ) ;
V_2 = F_4 ( & V_4 , 1 , & V_1 ) ;
F_5 ( & V_7 ) ;
if ( V_2 == - V_8 )
goto V_3;
else if ( V_2 )
return V_2 ;
if ( V_1 > V_9 ) {
F_3 ( & V_7 ) ;
F_6 ( & V_4 , V_1 ) ;
F_5 ( & V_7 ) ;
return - V_6 ;
}
return V_1 ;
}
int F_7 ( struct V_10 * V_11 , struct V_12 * V_13 )
{
int V_1 ;
V_1 = F_1 () ;
if ( V_1 < 0 )
return V_1 ;
if ( F_8 ( V_13 ) )
F_9 ( V_13 , V_14 ) ;
F_10 ( V_13 ) ;
V_13 -> V_15 . V_16 = V_1 ;
#ifdef F_11
V_13 -> V_15 . V_17 = F_12 ( sizeof( V_18 ) , V_5 ) ;
if ( ! V_13 -> V_15 . V_17 ) {
F_13 ( V_1 ) ;
F_14 ( V_13 ) ;
V_13 -> V_15 . V_16 = V_19 ;
return - V_6 ;
}
F_15 ( V_13 -> V_15 . V_17 ) ;
#endif
return 0 ;
}
void F_13 ( int V_20 )
{
F_3 ( & V_7 ) ;
F_6 ( & V_4 , V_20 ) ;
F_5 ( & V_7 ) ;
}
void F_16 ( struct V_12 * V_13 )
{
#ifdef F_11
F_17 ( V_13 -> V_15 . V_21 , V_13 ) ;
F_18 ( V_13 -> V_15 . V_17 ) ;
V_13 -> V_15 . V_17 = NULL ;
#endif
F_13 ( V_13 -> V_15 . V_16 ) ;
F_14 ( V_13 ) ;
V_13 -> V_15 . V_16 = V_19 ;
}
