static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_2 ( L_1 , V_2 ) ;
V_4 = F_3 ( sizeof( * V_4 ) , V_5 ) ;
if ( ! V_4 )
return - V_6 ;
F_4 ( & V_4 -> V_7 ) ;
V_2 -> V_8 = V_4 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_8 ;
F_2 ( L_1 , V_2 ) ;
F_6 ( & V_4 -> V_7 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_8 ;
V_2 -> V_8 = NULL ;
F_2 ( L_1 , V_2 ) ;
F_6 ( & V_4 -> V_7 ) ;
F_8 ( V_4 -> V_9 ) ;
V_2 -> V_8 = NULL ;
F_9 ( V_4 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_3 * V_4 = V_2 -> V_8 ;
F_2 ( L_2 , V_2 , V_11 ) ;
memcpy ( F_11 ( V_11 , 1 ) , & F_12 ( V_11 ) -> V_12 , 1 ) ;
F_13 ( & V_4 -> V_7 , V_11 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , void * V_13 , int V_14 )
{
int V_15 ;
if ( ! F_15 ( V_16 , & V_2 -> V_17 ) )
return - V_18 ;
V_15 = F_16 ( V_2 -> V_19 , V_13 , V_14 ) ;
if ( V_15 < 0 ) {
F_17 ( L_3 ) ;
return V_15 ;
}
return V_14 ;
}
static struct V_10 * F_18 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_8 ;
return F_19 ( & V_4 -> V_7 ) ;
}
int T_1 F_20 ( void )
{
int V_20 = F_21 ( & V_21 ) ;
if ( ! V_20 )
F_22 ( L_4 ) ;
else
F_17 ( L_5 ) ;
return V_20 ;
}
int T_2 F_23 ( void )
{
return F_24 ( & V_21 ) ;
}
