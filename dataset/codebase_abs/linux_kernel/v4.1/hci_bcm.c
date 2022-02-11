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
F_7 ( V_4 -> V_9 ) ;
F_8 ( V_4 ) ;
V_2 -> V_8 = NULL ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_8 ;
F_2 ( L_1 , V_2 ) ;
F_6 ( & V_4 -> V_7 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
F_2 ( L_1 , V_2 ) ;
V_2 -> V_10 -> V_11 = V_12 ;
return F_11 ( V_2 -> V_10 ) ;
}
static int F_12 ( struct V_1 * V_2 , const void * V_13 , int V_14 )
{
struct V_3 * V_4 = V_2 -> V_8 ;
if ( ! F_13 ( V_15 , & V_2 -> V_16 ) )
return - V_17 ;
V_4 -> V_9 = F_14 ( V_2 -> V_10 , V_4 -> V_9 , V_13 , V_14 ,
V_18 , F_15 ( V_18 ) ) ;
if ( F_16 ( V_4 -> V_9 ) ) {
int V_19 = F_17 ( V_4 -> V_9 ) ;
F_18 ( L_2 , V_2 -> V_10 -> V_20 , V_19 ) ;
return V_19 ;
}
return V_14 ;
}
static int F_19 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
struct V_3 * V_4 = V_2 -> V_8 ;
F_2 ( L_3 , V_2 , V_22 ) ;
memcpy ( F_20 ( V_22 , 1 ) , & F_21 ( V_22 ) -> V_23 , 1 ) ;
F_22 ( & V_4 -> V_7 , V_22 ) ;
return 0 ;
}
static struct V_21 * F_23 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_8 ;
return F_24 ( & V_4 -> V_7 ) ;
}
int T_1 F_25 ( void )
{
return F_26 ( & V_24 ) ;
}
int T_2 F_27 ( void )
{
return F_28 ( & V_24 ) ;
}
