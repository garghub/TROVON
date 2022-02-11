static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_3 ) ;
F_3 ( 2 + V_2 -> V_4 , V_2 -> V_5 . V_6 ) ;
F_3 ( 64 + 2 + V_2 -> V_4 , V_2 -> V_5 . V_6 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
F_2 ( V_3 ) ;
F_3 ( 128 + 2 + V_2 -> V_4 , V_2 -> V_5 . V_6 ) ;
F_3 ( 128 + 64 + 2 + V_2 -> V_4 , V_2 -> V_5 . V_6 ) ;
}
static struct V_7 * F_5 ( void )
{
struct V_1 * V_2 = F_6 ( sizeof( * V_2 ) , V_8 ) ;
return V_2 ? & V_2 -> V_5 : NULL ;
}
static int F_7 ( struct V_7 * V_5 , T_1 V_9 )
{
struct V_1 * V_2 = F_8 ( V_5 , struct V_1 , V_5 ) ;
int V_10 ;
V_9 += 171200 ;
V_9 /= 800 ;
F_1 ( V_2 ) ;
for ( V_10 = 0 ; V_10 < 13 ; V_10 ++ )
if ( V_9 & ( 1 << V_10 ) )
F_4 ( V_2 ) ;
else
F_1 ( V_2 ) ;
F_1 ( V_2 ) ;
F_1 ( V_2 ) ;
F_1 ( V_2 ) ;
if ( V_5 -> V_11 )
F_4 ( V_2 ) ;
else
F_1 ( V_2 ) ;
F_4 ( V_2 ) ;
F_1 ( V_2 ) ;
F_1 ( V_2 ) ;
F_4 ( V_2 ) ;
F_1 ( V_2 ) ;
F_4 ( V_2 ) ;
F_2 ( V_3 ) ;
F_3 ( 128 + 64 + V_2 -> V_4 , V_2 -> V_5 . V_6 ) ;
return 0 ;
}
static T_1 F_9 ( struct V_7 * V_5 )
{
if ( F_10 ( V_5 -> V_6 ) & 1 )
return V_12 ;
return V_13 ;
}
static int F_11 ( struct V_7 * V_5 , bool V_11 )
{
return F_7 ( V_5 , V_5 -> V_9 ) ;
}
static int F_12 ( struct V_7 * V_5 , bool V_14 , int V_15 )
{
struct V_1 * V_2 = F_8 ( V_5 , struct V_1 , V_5 ) ;
if ( V_14 )
V_15 = 0 ;
V_2 -> V_4 = ( V_15 & 1 ) + ( ( V_15 & 2 ) << 1 ) ;
F_13 ( V_2 -> V_4 , V_5 -> V_6 ) ;
return 0 ;
}
static int T_2 F_14 ( void )
{
return F_15 ( & V_16 . V_17 , V_18 ) ;
}
static void T_3 F_16 ( void )
{
F_17 ( & V_16 . V_17 ) ;
}
