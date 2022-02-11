static void F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 , V_7 ) ;
T_1 * V_8 ;
unsigned long V_9 ;
F_3 ( & V_10 , V_9 ) ;
if ( V_6 -> V_11 == 0x49 )
V_8 = & V_12 ;
else if ( V_6 -> V_11 == 0x5a )
V_8 = & V_13 ;
else
F_4 () ;
if ( V_4 == V_14 )
* V_8 &= ~ V_6 -> V_15 ;
else
* V_8 |= V_6 -> V_15 ;
F_5 ( * V_8 , V_6 -> V_11 ) ;
F_6 ( & V_10 , V_9 ) ;
}
static int T_2 F_7 ( struct V_16 * V_17 )
{
int V_18 ;
int V_19 ;
for ( V_18 = 0 ; V_18 < F_8 ( V_20 ) ; V_18 ++ ) {
V_20 [ V_18 ] . V_7 . V_21 = V_20 [ V_18 ] . V_21 ;
V_20 [ V_18 ] . V_7 . V_22 = F_1 ;
V_19 = F_9 ( & V_17 -> V_23 , & V_20 [ V_18 ] . V_7 ) ;
if ( V_19 < 0 )
goto V_24;
}
V_12 = 0 ;
V_13 = F_10 ( 1 ) ;
F_5 ( V_12 , 0x49 ) ;
F_5 ( V_13 , 0x5a ) ;
return 0 ;
V_24:
for ( V_18 = V_18 - 1 ; V_18 >= 0 ; V_18 -- )
F_11 ( & V_20 [ V_18 ] . V_7 ) ;
return V_19 ;
}
static int T_3 F_12 ( struct V_16 * V_17 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < F_8 ( V_20 ) ; V_18 ++ )
F_11 ( & V_20 [ V_18 ] . V_7 ) ;
return 0 ;
}
