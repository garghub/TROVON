static void
F_1 ( struct V_1 * V_2 , enum V_3 V_4 )
{
int V_5 ;
struct V_6 * V_7 = F_2 ( V_2 ,
struct V_6 , V_8 ) ;
F_3 ( & V_9 ) ;
V_5 = F_4 ( V_7 -> V_10 ,
V_11 ) ;
if ( V_5 < 0 )
goto V_12;
if ( V_4 == V_13 )
V_5 &= ~ V_7 -> V_14 ;
else
V_5 |= V_7 -> V_14 ;
F_5 ( V_7 -> V_10 ,
V_11 , V_5 ) ;
V_12:
F_6 ( & V_9 ) ;
}
static int F_7 ( struct V_15 * V_16 )
{
int V_17 ;
int V_18 ;
struct V_10 * V_10 = F_8 ( V_16 -> V_19 . V_20 ) ;
for ( V_17 = 0 ; V_17 < F_9 ( V_21 ) ; V_17 ++ ) {
V_21 [ V_17 ] . V_8 . V_22 = V_21 [ V_17 ] . V_22 ;
V_21 [ V_17 ] . V_8 . V_23 = F_1 ;
V_21 [ V_17 ] . V_10 = V_10 ;
V_18 = F_10 ( & V_16 -> V_19 , & V_21 [ V_17 ] . V_8 ) ;
if ( V_18 < 0 ) {
F_11 ( & V_16 -> V_19 , L_1 ) ;
return V_18 ;
}
}
F_12 ( & V_16 -> V_19 , L_2 ) ;
return 0 ;
}
