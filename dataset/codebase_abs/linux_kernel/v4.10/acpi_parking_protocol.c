void T_1 F_1 ( int V_1 ,
struct V_2 * V_3 )
{
struct V_4 * V_5 = & V_6 [ V_1 ] ;
V_5 -> V_7 = V_3 -> V_8 ;
V_5 -> V_9 = V_3 -> V_10 ;
V_5 -> V_11 = V_3 -> V_12 ;
}
bool F_2 ( int V_1 )
{
struct V_4 * V_5 = & V_6 [ V_1 ] ;
return V_5 -> V_7 && V_5 -> V_9 ;
}
static int F_3 ( unsigned int V_1 )
{
F_4 ( L_1 , V_13 ,
V_6 [ V_1 ] . V_7 ) ;
return 0 ;
}
static int F_5 ( unsigned int V_1 )
{
return 0 ;
}
static int F_6 ( unsigned int V_1 )
{
struct V_4 * V_5 = & V_6 [ V_1 ] ;
struct V_14 T_2 * V_15 ;
T_3 V_16 ;
V_15 = F_7 ( V_5 -> V_7 , sizeof( * V_15 ) ) ;
if ( ! V_15 )
return - V_17 ;
V_16 = F_8 ( & V_15 -> V_16 ) ;
if ( V_16 != ~ 0U ) {
F_9 ( V_15 ) ;
return - V_18 ;
}
V_5 -> V_15 = V_15 ;
F_10 ( F_11 ( V_19 ) , & V_15 -> V_20 ) ;
F_12 ( V_5 -> V_11 , & V_15 -> V_16 ) ;
F_13 ( F_14 ( V_1 ) ) ;
return 0 ;
}
static void F_15 ( void )
{
int V_1 = F_16 () ;
struct V_4 * V_5 = & V_6 [ V_1 ] ;
struct V_14 T_2 * V_15 = V_5 -> V_15 ;
T_4 V_20 ;
V_20 = F_8 ( & V_15 -> V_20 ) ;
F_17 ( V_20 ) ;
}
