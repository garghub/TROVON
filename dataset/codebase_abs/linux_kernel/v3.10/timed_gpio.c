static enum V_1 F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 =
F_2 ( V_3 , struct V_4 , V_3 ) ;
F_3 ( V_5 -> V_6 , V_5 -> V_7 ? 1 : 0 ) ;
return V_8 ;
}
static int F_4 ( struct V_9 * V_10 )
{
struct V_4 * V_5 =
F_2 ( V_10 , struct V_4 , V_10 ) ;
if ( F_5 ( & V_5 -> V_3 ) ) {
T_1 V_11 = F_6 ( & V_5 -> V_3 ) ;
struct V_12 V_13 = F_7 ( V_11 ) ;
return V_13 . V_14 * 1000 + V_13 . V_15 / 1000 ;
} else
return 0 ;
}
static void F_8 ( struct V_9 * V_10 , int V_16 )
{
struct V_4 * V_5 =
F_2 ( V_10 , struct V_4 , V_10 ) ;
unsigned long V_17 ;
F_9 ( & V_5 -> V_18 , V_17 ) ;
F_10 ( & V_5 -> V_3 ) ;
F_3 ( V_5 -> V_6 , V_5 -> V_7 ? ! V_16 : ! ! V_16 ) ;
if ( V_16 > 0 ) {
if ( V_16 > V_5 -> V_19 )
V_16 = V_5 -> V_19 ;
F_11 ( & V_5 -> V_3 ,
F_12 ( V_16 / 1000 , ( V_16 % 1000 ) * 1000000 ) ,
V_20 ) ;
}
F_13 ( & V_5 -> V_18 , V_17 ) ;
}
static int F_14 ( struct V_21 * V_22 )
{
struct V_23 * V_24 = V_22 -> V_10 . V_25 ;
struct V_26 * V_27 ;
struct V_4 * V_28 , * V_29 ;
int V_30 , V_31 ;
if ( ! V_24 )
return - V_32 ;
V_28 = F_15 ( sizeof( struct V_4 ) * V_24 -> V_33 ,
V_34 ) ;
if ( ! V_28 )
return - V_35 ;
for ( V_30 = 0 ; V_30 < V_24 -> V_33 ; V_30 ++ ) {
V_27 = & V_24 -> V_36 [ V_30 ] ;
V_29 = & V_28 [ V_30 ] ;
F_16 ( & V_29 -> V_3 , V_37 ,
V_20 ) ;
V_29 -> V_3 . V_38 = F_1 ;
F_17 ( & V_29 -> V_18 ) ;
V_29 -> V_10 . V_39 = V_27 -> V_39 ;
V_29 -> V_10 . V_40 = F_4 ;
V_29 -> V_10 . V_41 = F_8 ;
V_31 = F_18 ( V_27 -> V_6 , V_27 -> V_39 ) ;
if ( V_31 < 0 )
goto V_42;
V_31 = F_19 ( & V_29 -> V_10 ) ;
if ( V_31 < 0 ) {
F_20 ( V_27 -> V_6 ) ;
goto V_42;
}
V_29 -> V_6 = V_27 -> V_6 ;
V_29 -> V_19 = V_27 -> V_19 ;
V_29 -> V_7 = V_27 -> V_7 ;
F_3 ( V_29 -> V_6 , V_29 -> V_7 ) ;
}
F_21 ( V_22 , V_28 ) ;
return 0 ;
V_42:
while ( -- V_30 >= 0 ) {
F_22 ( & V_28 [ V_30 ] . V_10 ) ;
F_20 ( V_28 [ V_30 ] . V_6 ) ;
}
F_23 ( V_28 ) ;
return V_31 ;
}
static int F_24 ( struct V_21 * V_22 )
{
struct V_23 * V_24 = V_22 -> V_10 . V_25 ;
struct V_4 * V_28 = F_25 ( V_22 ) ;
int V_30 ;
for ( V_30 = 0 ; V_30 < V_24 -> V_33 ; V_30 ++ ) {
F_22 ( & V_28 [ V_30 ] . V_10 ) ;
F_20 ( V_28 [ V_30 ] . V_6 ) ;
}
F_23 ( V_28 ) ;
return 0 ;
}
