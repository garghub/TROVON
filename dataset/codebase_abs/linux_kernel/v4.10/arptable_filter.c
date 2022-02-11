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
V_11 = F_5 ( V_6 , & V_12 , V_10 , V_14 ,
& V_6 -> V_7 . V_8 ) ;
F_6 ( V_10 ) ;
return V_11 ;
}
static void T_2 F_7 ( struct V_6 * V_6 )
{
if ( ! V_6 -> V_7 . V_8 )
return;
F_8 ( V_6 , V_6 -> V_7 . V_8 , V_14 ) ;
V_6 -> V_7 . V_8 = NULL ;
}
static int T_3 F_9 ( void )
{
int V_15 ;
V_14 = F_10 ( & V_12 , F_1 ) ;
if ( F_11 ( V_14 ) )
return F_12 ( V_14 ) ;
V_15 = F_13 ( & V_16 ) ;
if ( V_15 < 0 ) {
F_6 ( V_14 ) ;
return V_15 ;
}
V_15 = F_3 ( & V_17 ) ;
if ( V_15 ) {
F_14 ( & V_16 ) ;
F_6 ( V_14 ) ;
}
return V_15 ;
}
static void T_4 F_15 ( void )
{
F_14 ( & V_16 ) ;
F_6 ( V_14 ) ;
}
