static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline struct V_4 *
F_3 ( struct V_5 * V_6 )
{
return F_2 ( V_6 , struct V_4 , V_7 ) ;
}
static int F_4 ( struct V_2 * V_8 , struct V_5 * V_9 )
{
return ! strncmp ( F_5 ( V_8 ) , V_9 -> V_10 , 4 ) ;
}
static int F_6 ( struct V_2 * V_11 )
{
struct V_1 * V_3 = F_1 ( V_11 ) ;
struct V_4 * V_6 = F_3 ( V_3 -> V_3 . V_7 ) ;
return V_6 -> V_12 ( V_3 ) ;
}
static int F_7 ( struct V_2 * V_11 )
{
struct V_1 * V_3 = F_1 ( V_11 ) ;
struct V_4 * V_6 = F_3 ( V_3 -> V_3 . V_7 ) ;
V_6 -> remove ( V_3 ) ;
return 0 ;
}
int F_8 ( struct V_4 * V_7 )
{
V_7 -> V_7 . V_13 = & V_14 ;
return F_9 ( & V_7 -> V_7 ) ;
}
void F_10 ( struct V_4 * V_7 )
{
F_11 ( & V_7 -> V_7 ) ;
}
static void F_12 ( struct V_2 * V_11 )
{
struct V_1 * V_15 = F_1 ( V_11 ) ;
struct V_16 * V_17 = & V_16 [ V_15 -> V_18 ] ;
F_13 ( V_17 ) ;
F_14 ( V_15 ) ;
}
struct V_1 *
F_15 ( struct V_16 * V_17 )
{
int V_19 ;
struct V_1 * V_20 ;
V_20 = F_16 ( sizeof( * V_20 ) , V_21 ) ;
if ( ! V_20 )
return F_17 ( - V_22 ) ;
V_20 -> V_3 . V_23 = V_17 -> V_15 -> V_3 . V_23 ;
V_20 -> V_3 . V_24 = F_12 ;
V_20 -> V_18 = V_17 -> V_25 ;
V_20 -> V_3 . V_13 = & V_14 ;
F_18 ( & V_20 -> V_3 , L_1 , V_20 -> V_18 ) ;
V_19 = F_19 ( & V_20 -> V_3 ) ;
if ( V_19 )
goto V_26;
return V_20 ;
V_26:
F_14 ( V_20 ) ;
return F_17 ( V_19 ) ;
}
void F_20 ( struct V_1 * V_15 )
{
F_21 ( & V_15 -> V_3 ) ;
}
int F_22 ( void )
{
return F_23 ( & V_14 ) ;
}
void F_24 ( void )
{
F_25 ( & V_14 ) ;
}
