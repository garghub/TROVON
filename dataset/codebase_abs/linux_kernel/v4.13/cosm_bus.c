static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 -> V_4 . V_7 ) ;
return V_6 -> V_8 ( V_4 ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 -> V_4 . V_7 ) ;
V_6 -> remove ( V_4 ) ;
return 0 ;
}
int F_5 ( struct V_5 * V_7 )
{
V_7 -> V_7 . V_9 = & V_10 ;
return F_6 ( & V_7 -> V_7 ) ;
}
void F_7 ( struct V_5 * V_7 )
{
F_8 ( & V_7 -> V_7 ) ;
}
static inline void F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_11 = F_2 ( V_2 ) ;
F_10 ( V_11 ) ;
}
struct V_3 *
F_11 ( struct V_1 * V_12 , struct V_13 * V_14 )
{
struct V_3 * V_11 ;
int V_15 ;
V_11 = F_12 ( sizeof( * V_11 ) , V_16 ) ;
if ( ! V_11 )
return F_13 ( - V_17 ) ;
V_11 -> V_4 . V_18 = V_12 ;
V_11 -> V_4 . V_19 = F_9 ;
V_11 -> V_14 = V_14 ;
F_14 ( & V_11 -> V_4 , V_11 ) ;
V_11 -> V_4 . V_9 = & V_10 ;
V_15 = F_15 ( & V_20 , 0 , 0 , V_16 ) ;
if ( V_15 < 0 )
goto V_21;
V_11 -> V_22 = V_15 ;
V_11 -> V_4 . V_23 = V_15 ;
F_16 ( & V_11 -> V_4 , L_1 , V_11 -> V_22 ) ;
V_15 = F_17 ( & V_11 -> V_4 ) ;
if ( V_15 )
goto V_24;
return V_11 ;
V_24:
F_18 ( & V_20 , V_11 -> V_22 ) ;
V_21:
F_19 ( & V_11 -> V_4 ) ;
return F_13 ( V_15 ) ;
}
void F_20 ( struct V_3 * V_4 )
{
int V_22 = V_4 -> V_22 ;
F_21 ( & V_4 -> V_4 ) ;
F_18 ( & V_20 , V_22 ) ;
}
struct V_3 * F_22 ( int V_23 )
{
struct V_1 * V_4 = F_23 ( & V_10 , V_23 , NULL ) ;
return V_4 ? F_24 ( V_4 , struct V_3 , V_4 ) : NULL ;
}
static int T_1 F_25 ( void )
{
return F_26 ( & V_10 ) ;
}
static void T_2 F_27 ( void )
{
F_28 ( & V_10 ) ;
F_29 ( & V_20 ) ;
}
