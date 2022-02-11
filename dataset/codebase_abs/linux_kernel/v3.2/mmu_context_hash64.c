void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_3 , V_2 -> V_4 . V_5 ) ;
F_2 ( V_6 , V_2 -> V_4 . V_7 ) ;
}
static int F_3 ( struct V_8 * V_8 , int V_9 , int V_10 ,
T_1 * V_11 )
{
int V_12 ;
int V_13 ;
V_14:
if ( ! F_4 ( V_8 , V_15 ) )
return - V_16 ;
F_5 ( V_11 ) ;
V_13 = F_6 ( V_8 , V_9 , & V_12 ) ;
F_7 ( V_11 ) ;
if ( V_13 == - V_17 )
goto V_14;
else if ( V_13 )
return V_13 ;
if ( V_12 > V_10 ) {
F_5 ( V_11 ) ;
F_8 ( V_8 , V_12 ) ;
F_7 ( V_11 ) ;
return - V_16 ;
}
return V_12 ;
}
static void F_9 ( void * V_18 )
{
struct V_1 * V_19 = V_18 ;
if ( V_19 == V_20 -> V_21 )
F_1 ( V_20 -> V_21 ) ;
}
int F_10 ( unsigned long V_7 , struct V_1 * V_19 )
{
int V_22 ;
if ( ! F_11 ( V_23 ) )
return - V_24 ;
if ( ! V_19 || ! V_7 )
return - V_25 ;
F_5 ( & V_19 -> V_26 ) ;
F_5 ( V_19 -> V_4 . V_27 ) ;
if ( V_19 -> V_4 . V_5 == V_28 ) {
V_22 = F_3 ( & V_29 , V_30 , V_31 ,
& V_32 ) ;
if ( V_22 < 0 )
goto V_33;
V_19 -> V_4 . V_5 = V_22 ;
}
V_19 -> V_4 . V_7 |= V_7 ;
F_9 ( V_19 ) ;
if ( F_12 ( & V_19 -> V_34 ) > 1 )
F_13 ( F_9 , V_19 , 1 ) ;
V_22 = V_19 -> V_4 . V_5 ;
V_33:
F_7 ( V_19 -> V_4 . V_27 ) ;
F_7 ( & V_19 -> V_26 ) ;
return V_22 ;
}
void F_14 ( unsigned long V_7 , struct V_1 * V_19 )
{
int V_35 = V_28 ;
if ( ! F_11 ( V_23 ) )
return;
if ( F_15 ( ! V_19 ) )
return;
F_5 ( & V_19 -> V_26 ) ;
F_5 ( V_19 -> V_4 . V_27 ) ;
V_19 -> V_4 . V_7 &= ~ V_7 ;
if ( ( ! V_19 -> V_4 . V_7 ) && ( V_19 -> V_4 . V_5 != V_28 ) ) {
V_35 = V_19 -> V_4 . V_5 ;
V_19 -> V_4 . V_5 = V_28 ;
}
F_9 ( V_19 ) ;
if ( F_12 ( & V_19 -> V_34 ) > 1 )
F_13 ( F_9 , V_19 , 1 ) ;
if ( V_35 != V_28 ) {
F_5 ( & V_32 ) ;
F_8 ( & V_29 , V_35 ) ;
F_7 ( & V_32 ) ;
}
F_7 ( V_19 -> V_4 . V_27 ) ;
F_7 ( & V_19 -> V_26 ) ;
}
int F_16 ( void )
{
int V_12 ;
int V_13 ;
V_14:
if ( ! F_4 ( & V_36 , V_15 ) )
return - V_16 ;
F_5 ( & V_37 ) ;
V_13 = F_6 ( & V_36 , 1 , & V_12 ) ;
F_7 ( & V_37 ) ;
if ( V_13 == - V_17 )
goto V_14;
else if ( V_13 )
return V_13 ;
if ( V_12 > V_38 ) {
F_5 ( & V_37 ) ;
F_8 ( & V_36 , V_12 ) ;
F_7 ( & V_37 ) ;
return - V_16 ;
}
return V_12 ;
}
int F_17 ( struct V_39 * V_40 , struct V_1 * V_19 )
{
int V_12 ;
V_12 = F_16 () ;
if ( V_12 < 0 )
return V_12 ;
if ( F_18 ( V_19 ) )
F_19 ( V_19 , V_41 ) ;
F_20 ( V_19 ) ;
V_19 -> V_4 . V_42 = V_12 ;
#ifdef F_21
V_19 -> V_4 . V_27 = F_22 ( sizeof( T_1 ) , V_15 ) ;
if ( ! V_19 -> V_4 . V_27 ) {
F_23 ( V_12 ) ;
F_24 ( V_19 ) ;
V_19 -> V_4 . V_42 = V_43 ;
return - V_16 ;
}
F_25 ( V_19 -> V_4 . V_27 ) ;
#endif
return 0 ;
}
void F_23 ( int V_44 )
{
F_5 ( & V_37 ) ;
F_8 ( & V_36 , V_44 ) ;
F_7 ( & V_37 ) ;
}
void F_26 ( struct V_1 * V_19 )
{
#ifdef F_21
F_14 ( V_19 -> V_4 . V_7 , V_19 ) ;
F_27 ( V_19 -> V_4 . V_27 ) ;
V_19 -> V_4 . V_27 = NULL ;
#endif
F_23 ( V_19 -> V_4 . V_42 ) ;
F_24 ( V_19 ) ;
V_19 -> V_4 . V_42 = V_43 ;
}
