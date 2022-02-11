static void F_1 ( void )
{
int V_1 ;
if ( ! V_2 ) {
F_2 ( L_1 ) ;
return;
}
V_1 = F_3 ( V_2 -> V_3 ,
V_4 , V_5 , V_5 ) ;
if ( V_1 < 0 )
F_4 ( V_2 -> V_6 ,
L_2 , V_1 ) ;
}
static int F_5 ( struct V_7 * V_8 )
{
struct V_9 * V_9 ;
struct V_10 * V_11 = V_8 -> V_6 . V_12 -> V_13 ;
if ( ! V_11 )
return - V_14 ;
if ( ! F_6 ( V_11 , L_3 ) )
return 0 ;
V_9 = F_7 ( & V_8 -> V_6 , sizeof( * V_9 ) ,
V_15 ) ;
if ( ! V_9 )
return - V_16 ;
V_9 -> V_3 = F_8 ( V_8 -> V_6 . V_12 ) ;
V_9 -> V_6 = & V_8 -> V_6 ;
V_2 = V_9 ;
if ( ! V_17 )
V_17 = F_1 ;
return 0 ;
}
static int F_9 ( struct V_7 * V_8 )
{
if ( V_17 == F_1 )
V_17 = NULL ;
V_2 = NULL ;
return 0 ;
}
