static void F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
struct V_5 * V_6 =
F_2 ( V_2 , struct V_5 , V_7 ) ;
unsigned int V_8 = V_6 -> V_7 . V_9 ;
unsigned int V_10 = V_6 -> V_10 ;
if ( V_4 == 0 ) {
F_3 ( V_6 -> V_11 , 0 , V_10 ) ;
F_4 ( V_6 -> V_11 ) ;
} else {
F_3 ( V_6 -> V_11 , V_4 * V_10 / V_8 , V_10 ) ;
F_5 ( V_6 -> V_11 ) ;
}
}
static int F_6 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = V_13 -> V_16 . V_17 ;
struct V_18 * V_19 ;
struct V_5 * V_20 , * V_6 ;
int V_21 , V_22 = 0 ;
if ( ! V_15 )
return - V_23 ;
V_20 = F_7 ( & V_13 -> V_16 ,
sizeof( struct V_5 ) * V_15 -> V_24 ,
V_25 ) ;
if ( ! V_20 )
return - V_26 ;
for ( V_21 = 0 ; V_21 < V_15 -> V_24 ; V_21 ++ ) {
V_19 = & V_15 -> V_27 [ V_21 ] ;
V_6 = & V_20 [ V_21 ] ;
V_6 -> V_11 = F_8 ( V_19 -> V_28 ,
V_19 -> V_29 ) ;
if ( F_9 ( V_6 -> V_11 ) ) {
V_22 = F_10 ( V_6 -> V_11 ) ;
F_11 ( & V_13 -> V_16 , L_1 ,
V_19 -> V_28 ) ;
goto V_30;
}
V_6 -> V_7 . V_29 = V_19 -> V_29 ;
V_6 -> V_7 . V_31 = V_19 -> V_31 ;
V_6 -> V_32 = V_19 -> V_32 ;
V_6 -> V_10 = V_19 -> V_33 ;
V_6 -> V_7 . V_34 = F_1 ;
V_6 -> V_7 . V_4 = V_35 ;
V_6 -> V_7 . V_9 = V_19 -> V_9 ;
V_6 -> V_7 . V_36 |= V_37 ;
V_22 = F_12 ( & V_13 -> V_16 , & V_6 -> V_7 ) ;
if ( V_22 < 0 ) {
F_13 ( V_6 -> V_11 ) ;
goto V_30;
}
}
F_14 ( V_13 , V_20 ) ;
return 0 ;
V_30:
if ( V_21 > 0 ) {
for ( V_21 = V_21 - 1 ; V_21 >= 0 ; V_21 -- ) {
F_15 ( & V_20 [ V_21 ] . V_7 ) ;
F_13 ( V_20 [ V_21 ] . V_11 ) ;
}
}
return V_22 ;
}
static int T_1 F_16 ( struct V_12 * V_13 )
{
int V_21 ;
struct V_14 * V_15 = V_13 -> V_16 . V_17 ;
struct V_5 * V_20 ;
V_20 = F_17 ( V_13 ) ;
for ( V_21 = 0 ; V_21 < V_15 -> V_24 ; V_21 ++ ) {
F_15 ( & V_20 [ V_21 ] . V_7 ) ;
F_13 ( V_20 [ V_21 ] . V_11 ) ;
}
return 0 ;
}
