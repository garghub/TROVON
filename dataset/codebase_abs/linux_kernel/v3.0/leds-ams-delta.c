static void F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
struct V_5 * V_6 =
F_2 ( V_2 , struct V_5 , V_7 ) ;
if ( V_4 )
F_3 ( V_6 -> V_8 , V_6 -> V_8 ) ;
else
F_3 ( V_6 -> V_8 , 0 ) ;
}
static int F_4 ( struct V_9 * V_10 )
{
int V_11 , V_12 ;
for ( V_11 = 0 ; V_11 < F_5 ( V_13 ) ; V_11 ++ ) {
V_13 [ V_11 ] . V_7 . V_14 |= V_15 ;
V_12 = F_6 ( & V_10 -> V_16 ,
& V_13 [ V_11 ] . V_7 ) ;
if ( V_12 < 0 )
goto V_17;
}
return 0 ;
V_17:
while ( -- V_11 >= 0 )
F_7 ( & V_13 [ V_11 ] . V_7 ) ;
return V_12 ;
}
static int F_8 ( struct V_9 * V_10 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < F_5 ( V_13 ) ; V_11 ++ )
F_7 ( & V_13 [ V_11 ] . V_7 ) ;
return 0 ;
}
static int T_1 F_9 ( void )
{
return F_10 ( & V_18 ) ;
}
static void T_2 F_11 ( void )
{
F_12 ( & V_18 ) ;
}
