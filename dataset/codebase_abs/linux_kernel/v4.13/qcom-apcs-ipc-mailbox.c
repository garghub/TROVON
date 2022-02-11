static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ,
struct V_4 , V_6 ) ;
unsigned long V_7 = ( unsigned long ) V_2 -> V_8 ;
F_3 ( F_4 ( V_7 ) , V_5 -> V_9 ) ;
return 0 ;
}
static int F_5 ( struct V_10 * V_11 )
{
struct V_4 * V_5 ;
struct V_12 * V_13 ;
unsigned long V_14 ;
void T_1 * V_15 ;
unsigned long V_16 ;
int V_17 ;
V_5 = F_6 ( & V_11 -> V_18 , sizeof( * V_5 ) , V_19 ) ;
if ( ! V_5 )
return - V_20 ;
V_13 = F_7 ( V_11 , V_21 , 0 ) ;
V_15 = F_8 ( & V_11 -> V_18 , V_13 ) ;
if ( F_9 ( V_15 ) )
return F_10 ( V_15 ) ;
V_14 = ( unsigned long ) F_11 ( & V_11 -> V_18 ) ;
V_5 -> V_9 = V_15 + V_14 ;
for ( V_16 = 0 ; V_16 < F_12 ( V_5 -> V_22 ) ; V_16 ++ )
V_5 -> V_22 [ V_16 ] . V_8 = ( void * ) V_16 ;
V_5 -> V_6 . V_18 = & V_11 -> V_18 ;
V_5 -> V_6 . V_23 = & V_24 ;
V_5 -> V_6 . V_25 = V_5 -> V_22 ;
V_5 -> V_6 . V_26 = F_12 ( V_5 -> V_22 ) ;
V_17 = F_13 ( & V_5 -> V_6 ) ;
if ( V_17 ) {
F_14 ( & V_11 -> V_18 , L_1 ) ;
return V_17 ;
}
F_15 ( V_11 , V_5 ) ;
return 0 ;
}
static int F_16 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = F_17 ( V_11 ) ;
F_18 ( & V_5 -> V_6 ) ;
return 0 ;
}
static int T_2 F_19 ( void )
{
return F_20 ( & V_27 ) ;
}
static void T_3 F_21 ( void )
{
F_22 ( & V_27 ) ;
}
