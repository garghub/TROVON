void F_1 ( void )
{
V_1 = F_2 ( V_2 , NULL ) ;
if ( F_3 ( V_1 ) )
V_1 = NULL ;
}
void F_4 ( void )
{
if ( ! V_1 )
return;
F_5 ( V_1 ) ;
V_1 = NULL ;
}
static int F_6 ( struct V_3 * V_4 , void * V_5 )
{
struct V_6 * V_7 = F_7 ( V_4 -> V_8 ) ;
F_8 ( V_4 , L_1 ,
V_7 -> V_9 , V_7 -> V_9 , V_7 -> V_10 ) ;
return 0 ;
}
int F_9 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = V_12 -> V_15 -> V_14 ;
if ( ! V_1 )
return - V_16 ;
V_12 -> V_17 = F_2 ( F_10 ( V_14 ) , V_1 ) ;
F_11 ( V_12 , L_2 , F_6 ) ;
return F_12 ( V_12 -> V_17 ) ;
}
void F_13 ( struct V_11 * V_12 )
{
if ( ! F_14 ( V_12 -> V_17 ) )
F_5 ( V_12 -> V_17 ) ;
}
struct V_18 * F_15 ( struct V_11 * V_12 )
{
return V_12 -> V_17 ;
}
static int F_16 ( struct V_19 * V_19 , struct V_20 * V_21 )
{
struct V_22 * V_23 = V_19 -> V_24 ;
return F_17 ( V_21 , V_23 -> V_25 , V_23 -> V_12 -> V_15 -> V_14 ) ;
}
int F_11 ( struct V_11 * V_12 , const char * V_26 ,
int (* F_18)( struct V_3 * V_4 , void * V_5 ) )
{
struct V_18 * V_18 = V_12 -> V_17 ;
struct V_22 * V_23 ;
if ( F_14 ( V_18 ) )
return - V_27 ;
V_23 = F_19 ( V_12 -> V_15 -> V_14 , sizeof( * V_23 ) , V_28 ) ;
if ( ! V_23 )
return - V_29 ;
V_23 -> V_25 = F_18 ;
V_23 -> V_12 = V_12 ;
V_18 = F_20 ( V_26 , V_30 , V_18 , V_23 ,
& V_31 ) ;
return F_12 ( V_18 ) ;
}
