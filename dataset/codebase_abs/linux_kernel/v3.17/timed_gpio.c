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
struct V_11 V_12 ;
V_5 = F_2 ( V_10 , struct V_4 , V_10 ) ;
if ( ! F_5 ( & V_5 -> V_3 ) )
return 0 ;
V_12 = F_6 ( F_7 ( & V_5 -> V_3 ) ) ;
return V_12 . V_13 * 1000 + V_12 . V_14 / 1000 ;
}
static void F_8 ( struct V_9 * V_10 , int V_15 )
{
struct V_4 * V_5 =
F_2 ( V_10 , struct V_4 , V_10 ) ;
unsigned long V_16 ;
F_9 ( & V_5 -> V_17 , V_16 ) ;
F_10 ( & V_5 -> V_3 ) ;
F_3 ( V_5 -> V_6 , V_5 -> V_7 ? ! V_15 : ! ! V_15 ) ;
if ( V_15 > 0 ) {
if ( V_15 > V_5 -> V_18 )
V_15 = V_5 -> V_18 ;
F_11 ( & V_5 -> V_3 ,
F_12 ( V_15 / 1000 , ( V_15 % 1000 ) * 1000000 ) ,
V_19 ) ;
}
F_13 ( & V_5 -> V_17 , V_16 ) ;
}
static int F_14 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = V_21 -> V_10 . V_24 ;
struct V_25 * V_26 ;
struct V_4 * V_27 , * V_28 ;
int V_29 , V_30 ;
if ( ! V_23 )
return - V_31 ;
V_27 = F_15 ( & V_21 -> V_10 ,
sizeof( struct V_4 ) * V_23 -> V_32 ,
V_33 ) ;
if ( ! V_27 )
return - V_34 ;
for ( V_29 = 0 ; V_29 < V_23 -> V_32 ; V_29 ++ ) {
V_26 = & V_23 -> V_35 [ V_29 ] ;
V_28 = & V_27 [ V_29 ] ;
F_16 ( & V_28 -> V_3 , V_36 ,
V_19 ) ;
V_28 -> V_3 . V_37 = F_1 ;
F_17 ( & V_28 -> V_17 ) ;
V_28 -> V_10 . V_38 = V_26 -> V_38 ;
V_28 -> V_10 . V_39 = F_4 ;
V_28 -> V_10 . V_40 = F_8 ;
V_30 = F_18 ( V_26 -> V_6 , V_26 -> V_38 ) ;
if ( V_30 < 0 )
goto V_41;
V_30 = F_19 ( & V_28 -> V_10 ) ;
if ( V_30 < 0 ) {
F_20 ( V_26 -> V_6 ) ;
goto V_41;
}
V_28 -> V_6 = V_26 -> V_6 ;
V_28 -> V_18 = V_26 -> V_18 ;
V_28 -> V_7 = V_26 -> V_7 ;
F_3 ( V_28 -> V_6 , V_28 -> V_7 ) ;
}
F_21 ( V_21 , V_27 ) ;
return 0 ;
V_41:
while ( -- V_29 >= 0 ) {
F_22 ( & V_27 [ V_29 ] . V_10 ) ;
F_20 ( V_27 [ V_29 ] . V_6 ) ;
}
return V_30 ;
}
static int F_23 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = V_21 -> V_10 . V_24 ;
struct V_4 * V_27 = F_24 ( V_21 ) ;
int V_29 ;
for ( V_29 = 0 ; V_29 < V_23 -> V_32 ; V_29 ++ ) {
F_22 ( & V_27 [ V_29 ] . V_10 ) ;
F_20 ( V_27 [ V_29 ] . V_6 ) ;
}
return 0 ;
}
