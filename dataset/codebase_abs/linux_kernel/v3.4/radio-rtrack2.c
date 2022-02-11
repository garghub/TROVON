static struct V_1 * F_1 ( void )
{
return F_2 ( sizeof( struct V_1 ) , V_2 ) ;
}
static void F_3 ( struct V_1 * V_3 )
{
F_4 ( 1 , V_3 -> V_4 ) ;
F_4 ( 3 , V_3 -> V_4 ) ;
F_4 ( 1 , V_3 -> V_4 ) ;
}
static void F_5 ( struct V_1 * V_3 )
{
F_4 ( 5 , V_3 -> V_4 ) ;
F_4 ( 7 , V_3 -> V_4 ) ;
F_4 ( 5 , V_3 -> V_4 ) ;
}
static int F_6 ( struct V_1 * V_3 , T_1 V_5 )
{
int V_6 ;
V_5 = V_5 / 200 + 856 ;
F_4 ( 0xc8 , V_3 -> V_4 ) ;
F_4 ( 0xc9 , V_3 -> V_4 ) ;
F_4 ( 0xc9 , V_3 -> V_4 ) ;
for ( V_6 = 0 ; V_6 < 10 ; V_6 ++ )
F_3 ( V_3 ) ;
for ( V_6 = 14 ; V_6 >= 0 ; V_6 -- )
if ( V_5 & ( 1 << V_6 ) )
F_5 ( V_3 ) ;
else
F_3 ( V_3 ) ;
F_4 ( 0xc8 , V_3 -> V_4 ) ;
if ( ! F_7 ( V_3 -> V_7 ) )
F_4 ( 0 , V_3 -> V_4 ) ;
return 0 ;
}
static T_1 F_8 ( struct V_1 * V_3 )
{
return ( F_9 ( V_3 -> V_4 ) & 2 ) ? 0 : 0xffff ;
}
static int F_10 ( struct V_1 * V_3 , bool V_7 , int V_8 )
{
F_11 ( V_7 , V_3 -> V_4 ) ;
return 0 ;
}
static int T_2 F_12 ( void )
{
return F_13 ( & V_9 . V_10 , V_11 ) ;
}
static void T_3 F_14 ( void )
{
F_15 ( & V_9 . V_10 ) ;
}
