static int F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 ;
V_3 = F_2 ( V_4 , sizeof( V_4 ) ,
V_5 ) ;
if ( ! V_3 )
goto V_6;
V_3 [ 0 ] . V_7 = & V_1 -> V_8 . V_9 ;
if ( V_1 -> V_10 != & V_11 )
V_3 [ 0 ] . V_12 = NULL ;
V_1 -> V_8 . V_13 = F_3 ( V_1 , L_1 ,
V_3 ) ;
if ( ! V_1 -> V_8 . V_13 ) {
F_4 ( V_14 L_2 ) ;
goto V_15;
}
return 0 ;
V_15:
F_5 ( V_3 ) ;
V_6:
return - V_16 ;
}
static void F_6 ( struct V_1 * V_1 )
{
struct V_2 * V_3 ;
V_3 = V_1 -> V_8 . V_13 -> V_17 ;
F_7 ( V_1 -> V_8 . V_13 ) ;
F_5 ( V_3 ) ;
}
static int F_1 ( struct V_1 * V_1 )
{
return 0 ;
}
static void F_6 ( struct V_1 * V_1 )
{
}
int F_8 ( struct V_1 * V_1 )
{
V_1 -> V_8 . V_9 = V_18 ;
return F_1 ( V_1 ) ;
}
void F_9 ( struct V_1 * V_1 )
{
F_6 ( V_1 ) ;
F_10 ( & V_19 ) ;
}
int F_11 ( void )
{
int V_20 ;
V_20 = F_12 ( & V_19 ) ;
if ( V_20 < 0 )
F_13 ( L_3 ) ;
return V_20 ;
}
void F_14 ( void )
{
F_10 ( & V_19 ) ;
}
