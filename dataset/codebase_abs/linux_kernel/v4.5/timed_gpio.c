static enum V_1 F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 =
F_2 ( V_3 , struct V_4 , V_3 ) ;
F_3 ( V_5 -> V_6 , V_5 -> V_7 ? 1 : 0 ) ;
return V_8 ;
}
static int F_4 ( struct V_9 * V_10 )
{
struct V_4 * V_5 ;
T_1 V_11 ;
V_5 = F_2 ( V_10 , struct V_4 , V_10 ) ;
if ( ! F_5 ( & V_5 -> V_3 ) )
return 0 ;
V_11 = F_6 ( & V_5 -> V_3 ) ;
return F_7 ( V_11 ) ;
}
static void F_8 ( struct V_9 * V_10 , int V_12 )
{
struct V_4 * V_5 =
F_2 ( V_10 , struct V_4 , V_10 ) ;
unsigned long V_13 ;
F_9 ( & V_5 -> V_14 , V_13 ) ;
F_10 ( & V_5 -> V_3 ) ;
F_3 ( V_5 -> V_6 , V_5 -> V_7 ? ! V_12 : ! ! V_12 ) ;
if ( V_12 > 0 ) {
if ( V_12 > V_5 -> V_15 )
V_12 = V_5 -> V_15 ;
F_11 ( & V_5 -> V_3 ,
F_12 ( V_12 / 1000 , ( V_12 % 1000 ) * 1000000 ) ,
V_16 ) ;
}
F_13 ( & V_5 -> V_14 , V_13 ) ;
}
static int F_14 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = V_18 -> V_10 . V_21 ;
struct V_22 * V_23 ;
struct V_4 * V_24 , * V_25 ;
int V_26 , V_27 ;
if ( ! V_20 )
return - V_28 ;
V_24 = F_15 ( & V_18 -> V_10 ,
sizeof( * V_24 ) * V_20 -> V_29 ,
V_30 ) ;
if ( ! V_24 )
return - V_31 ;
for ( V_26 = 0 ; V_26 < V_20 -> V_29 ; V_26 ++ ) {
V_23 = & V_20 -> V_32 [ V_26 ] ;
V_25 = & V_24 [ V_26 ] ;
F_16 ( & V_25 -> V_3 , V_33 ,
V_16 ) ;
V_25 -> V_3 . V_34 = F_1 ;
F_17 ( & V_25 -> V_14 ) ;
V_25 -> V_10 . V_35 = V_23 -> V_35 ;
V_25 -> V_10 . V_36 = F_4 ;
V_25 -> V_10 . V_37 = F_8 ;
V_27 = F_18 ( V_23 -> V_6 , V_23 -> V_35 ) ;
if ( V_27 < 0 )
goto V_38;
V_27 = F_19 ( & V_25 -> V_10 ) ;
if ( V_27 < 0 ) {
F_20 ( V_23 -> V_6 ) ;
goto V_38;
}
V_25 -> V_6 = V_23 -> V_6 ;
V_25 -> V_15 = V_23 -> V_15 ;
V_25 -> V_7 = V_23 -> V_7 ;
F_3 ( V_25 -> V_6 , V_25 -> V_7 ) ;
}
F_21 ( V_18 , V_24 ) ;
return 0 ;
V_38:
while ( -- V_26 >= 0 ) {
F_22 ( & V_24 [ V_26 ] . V_10 ) ;
F_20 ( V_24 [ V_26 ] . V_6 ) ;
}
return V_27 ;
}
static int F_23 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = V_18 -> V_10 . V_21 ;
struct V_4 * V_24 = F_24 ( V_18 ) ;
int V_26 ;
for ( V_26 = 0 ; V_26 < V_20 -> V_29 ; V_26 ++ ) {
F_22 ( & V_24 [ V_26 ] . V_10 ) ;
F_20 ( V_24 [ V_26 ] . V_6 ) ;
}
return 0 ;
}
