static unsigned int
F_1 ( void * V_1 , struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
return F_2 ( V_3 , V_5 , V_5 -> V_6 -> V_7 . V_8 ) ;
}
static int T_1 F_3 ( struct V_6 * V_6 )
{
struct V_9 * V_10 ;
int V_11 ;
if ( V_6 -> V_7 . V_8 )
return 0 ;
V_10 = F_4 ( & V_12 ) ;
if ( V_10 == NULL )
return - V_13 ;
( (struct V_14 * ) V_10 -> V_15 ) [ 1 ] . V_16 . V_17 =
V_18 ? - V_19 - 1 : - V_20 - 1 ;
V_11 = F_5 ( V_6 , & V_12 , V_10 , V_21 ,
& V_6 -> V_7 . V_8 ) ;
F_6 ( V_10 ) ;
return V_11 ;
}
static int T_1 F_7 ( struct V_6 * V_6 )
{
if ( V_6 == & V_22 || ! V_18 )
return F_3 ( V_6 ) ;
return 0 ;
}
static void T_2 F_8 ( struct V_6 * V_6 )
{
if ( ! V_6 -> V_7 . V_8 )
return;
F_9 ( V_6 , V_6 -> V_7 . V_8 , V_21 ) ;
V_6 -> V_7 . V_8 = NULL ;
}
static int T_3 F_10 ( void )
{
int V_23 ;
V_21 = F_11 ( & V_12 , F_1 ) ;
if ( F_12 ( V_21 ) )
return F_13 ( V_21 ) ;
V_23 = F_14 ( & V_24 ) ;
if ( V_23 < 0 )
F_6 ( V_21 ) ;
return V_23 ;
}
static void T_4 F_15 ( void )
{
F_16 ( & V_24 ) ;
F_6 ( V_21 ) ;
}
