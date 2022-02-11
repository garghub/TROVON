static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_5 ;
int V_6 ;
V_5 = F_2 ( sizeof( struct V_5 ) , V_7 ) ;
if ( V_5 == NULL )
return - V_8 ;
F_3 ( V_2 , V_5 ) ;
V_5 -> V_9 = & V_2 -> V_9 ;
V_5 -> V_10 = F_4 ( V_2 , & V_11 ) ;
if ( F_5 ( V_5 -> V_10 ) ) {
V_6 = F_6 ( V_5 -> V_10 ) ;
F_7 ( V_5 -> V_9 , L_1 ,
V_6 ) ;
F_8 ( V_5 ) ;
return V_6 ;
}
return F_9 ( V_5 , V_4 -> V_12 , V_2 -> V_13 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_11 ( V_2 ) ;
F_12 ( V_5 ) ;
return 0 ;
}
static int F_13 ( struct V_14 * V_9 )
{
struct V_5 * V_5 = F_14 ( V_9 ) ;
return F_15 ( V_5 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_11 ( V_2 ) ;
F_17 ( V_5 ) ;
}
static int T_1 F_18 ( void )
{
int V_6 ;
V_6 = F_19 ( & V_15 ) ;
if ( V_6 != 0 )
F_20 ( L_2 , V_6 ) ;
return V_6 ;
}
static void T_2 F_21 ( void )
{
F_22 ( & V_15 ) ;
}
