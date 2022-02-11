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
F_8 ( & V_15 -> V_7 ,
& V_16 . V_17 ,
F_2 ) ;
return 0 ;
}
static void T_2 F_9 ( struct V_15 * V_15 )
{
F_10 ( ! F_11 ( & V_15 -> V_7 . V_18 ) ) ;
}
static T_3 int F_12 ( void )
{
int V_19 ;
V_19 = F_13 ( & V_20 ) ;
if ( V_19 )
goto V_21;
F_14 ( & V_22 ) ;
F_8 ( & V_16 . V_17 , NULL , NULL ) ;
F_14 ( & V_16 ) ;
V_21:
return V_19 ;
}
struct V_23 * F_15 ( struct V_15 * V_15 ,
const struct V_24 * V_25 , struct V_10 * V_11 )
{
struct V_4 V_5 ;
V_5 = * V_9 -> V_4 ;
V_5 . V_6 = V_15 ;
return F_16 ( & V_22 ,
& V_5 , V_25 , V_11 ) ;
}
struct V_23 * F_17 ( const
struct V_24 * V_25 , struct V_10 * V_11 )
{
return F_16 ( & V_16 ,
& V_26 , V_25 , V_11 ) ;
}
void F_18 ( struct V_23 * V_27 )
{
F_19 ( V_27 ) ;
}
