static struct V_1 *
F_1 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
return & V_5 -> V_6 -> V_7 ;
}
static int F_2 ( struct V_1 * V_8 )
{
return & V_9 -> V_4 -> V_6 -> V_7 == V_8 ;
}
static int F_3 ( struct V_2 * V_3 ,
struct V_4 * V_4 ,
struct V_10 * V_11 )
{
if ( F_4 ( V_12 ) ) {
int V_13 = ( V_11 -> V_13 >> 6 ) & 7 ;
return ( V_13 << 6 ) | ( V_13 << 3 ) | V_13 ;
}
return V_11 -> V_13 ;
}
static int F_5 ( struct V_2 * V_3 ,
struct V_4 * V_5 , struct V_10 * V_11 )
{
if ( F_6 ( V_5 -> V_6 , & V_14 ) )
return V_11 -> V_13 ;
else
return V_11 -> V_13 & ~ 0222 ;
}
static int T_1 F_7 ( struct V_15 * V_15 )
{
F_8 ( & V_15 -> V_7 , & V_16 , F_2 ) ;
return 0 ;
}
static void T_2 F_9 ( struct V_15 * V_15 )
{
F_10 ( & V_15 -> V_7 ) ;
}
static T_3 int F_11 ( void )
{
int V_17 ;
V_17 = F_12 ( & V_18 ) ;
if ( V_17 )
goto V_19;
F_8 ( & V_20 . V_21 , & V_20 , NULL ) ;
F_13 ( & V_20 ) ;
F_13 ( & V_16 ) ;
V_19:
return V_17 ;
}
struct V_22 * F_14 ( struct V_15 * V_15 ,
const struct V_23 * V_24 , struct V_10 * V_11 )
{
return F_15 ( & V_15 -> V_7 , V_24 , V_11 ) ;
}
struct V_22 * F_16 ( const
struct V_23 * V_24 , struct V_10 * V_11 )
{
return F_15 ( & V_20 . V_21 ,
V_24 , V_11 ) ;
}
void F_17 ( struct V_22 * V_25 )
{
F_18 ( V_25 ) ;
}
