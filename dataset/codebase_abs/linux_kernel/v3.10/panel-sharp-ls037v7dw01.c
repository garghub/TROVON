static inline struct V_1
* F_1 ( const struct V_2 * V_3 )
{
return (struct V_1 * ) V_3 -> V_4 ;
}
static int F_2 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
int V_6 ;
if ( ! V_5 )
return - V_7 ;
V_3 -> V_8 . V_9 = V_10 ;
if ( F_3 ( V_5 -> V_11 ) ) {
V_6 = F_4 ( & V_3 -> V_12 , V_5 -> V_11 ,
V_13 , L_1 ) ;
if ( V_6 )
return V_6 ;
}
if ( F_3 ( V_5 -> V_14 ) ) {
V_6 = F_4 ( & V_3 -> V_12 , V_5 -> V_14 ,
V_15 , L_2 ) ;
if ( V_6 )
return V_6 ;
}
if ( F_3 ( V_5 -> V_16 ) ) {
V_6 = F_4 ( & V_3 -> V_12 , V_5 -> V_16 ,
V_15 , L_3 ) ;
if ( V_6 )
return V_6 ;
}
if ( F_3 ( V_5 -> V_17 ) ) {
V_6 = F_4 ( & V_3 -> V_12 , V_5 -> V_17 ,
V_13 , L_4 ) ;
if ( V_6 )
return V_6 ;
}
if ( F_3 ( V_5 -> V_18 ) ) {
V_6 = F_4 ( & V_3 -> V_12 , V_5 -> V_18 ,
V_13 , L_5 ) ;
if ( V_6 )
return V_6 ;
}
return 0 ;
}
static void T_1 F_5 ( struct V_2 * V_3 )
{
}
static int F_6 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
int V_6 = 0 ;
if ( V_3 -> V_19 == V_20 )
return 0 ;
F_7 ( V_3 , & V_3 -> V_8 . V_9 ) ;
F_8 ( V_3 , V_3 -> V_21 . V_22 . V_23 ) ;
V_6 = F_9 ( V_3 ) ;
if ( V_6 )
goto V_24;
F_10 ( 50 ) ;
if ( F_3 ( V_5 -> V_17 ) )
F_11 ( V_5 -> V_17 , 1 ) ;
if ( F_3 ( V_5 -> V_18 ) )
F_11 ( V_5 -> V_18 , 1 ) ;
return 0 ;
V_24:
return V_6 ;
}
static void F_12 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
if ( V_3 -> V_19 != V_20 )
return;
if ( F_3 ( V_5 -> V_18 ) )
F_11 ( V_5 -> V_18 , 0 ) ;
if ( F_3 ( V_5 -> V_17 ) )
F_11 ( V_5 -> V_17 , 0 ) ;
F_10 ( 100 ) ;
F_13 ( V_3 ) ;
}
static int F_14 ( struct V_2 * V_3 )
{
int V_6 ;
V_6 = F_6 ( V_3 ) ;
V_3 -> V_19 = V_20 ;
return V_6 ;
}
static void F_15 ( struct V_2 * V_3 )
{
F_12 ( V_3 ) ;
V_3 -> V_19 = V_25 ;
}
static int T_2 F_16 ( void )
{
return F_17 ( & V_26 ) ;
}
static void T_1 F_18 ( void )
{
F_19 ( & V_26 ) ;
}
