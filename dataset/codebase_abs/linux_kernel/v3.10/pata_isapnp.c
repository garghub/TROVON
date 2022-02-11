static int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
void T_1 * V_9 , * V_10 ;
int V_11 = 0 ;
T_2 V_12 = NULL ;
if ( F_2 ( V_2 , 0 ) == 0 )
return - V_13 ;
if ( F_3 ( V_2 , 0 ) ) {
V_11 = F_4 ( V_2 , 0 ) ;
V_12 = V_14 ;
}
V_6 = F_5 ( & V_2 -> V_15 , 1 ) ;
if ( ! V_6 )
return - V_16 ;
V_9 = F_6 ( & V_2 -> V_15 , F_7 ( V_2 , 0 ) , 8 ) ;
if ( ! V_9 )
return - V_16 ;
V_8 = V_6 -> V_17 [ 0 ] ;
V_8 -> V_18 = & V_19 ;
V_8 -> V_20 = V_21 ;
V_8 -> V_22 |= V_23 ;
V_8 -> V_24 . V_9 = V_9 ;
if ( F_2 ( V_2 , 1 ) == 0 ) {
V_10 = F_6 ( & V_2 -> V_15 ,
F_7 ( V_2 , 1 ) , 1 ) ;
V_8 -> V_24 . V_25 = V_10 ;
V_8 -> V_24 . V_10 = V_10 ;
V_8 -> V_18 = & V_26 ;
}
F_8 ( & V_8 -> V_24 ) ;
F_9 ( V_8 , L_1 ,
( unsigned long long ) F_7 ( V_2 , 0 ) ,
( unsigned long long ) F_7 ( V_2 , 1 ) ) ;
return F_10 ( V_6 , V_11 , V_12 , 0 ,
& V_27 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_28 * V_15 = & V_2 -> V_15 ;
struct V_5 * V_6 = F_12 ( V_15 ) ;
F_13 ( V_6 ) ;
}
static int T_3 F_14 ( void )
{
return F_15 ( & V_29 ) ;
}
static void T_4 F_16 ( void )
{
F_17 ( & V_29 ) ;
}
