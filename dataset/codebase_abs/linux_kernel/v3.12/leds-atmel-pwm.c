static void F_1 ( struct V_1 * V_2 , enum V_3 V_4 )
{
struct V_5 * V_6 ;
V_6 = F_2 ( V_2 , struct V_5 , V_2 ) ;
F_3 ( & V_6 -> V_7 , V_8 , V_6 -> V_9 * ( unsigned ) V_4 ) ;
}
static int F_4 ( struct V_10 * V_11 )
{
const struct V_12 * V_13 ;
struct V_5 * V_14 ;
int V_15 ;
int V_16 ;
V_13 = F_5 ( & V_11 -> V_17 ) ;
if ( ! V_13 || V_13 -> V_18 < 1 )
return - V_19 ;
V_14 = F_6 ( & V_11 -> V_17 , V_13 -> V_18 * sizeof( * V_14 ) ,
V_20 ) ;
if ( ! V_14 )
return - V_21 ;
for ( V_15 = 0 ; V_15 < V_13 -> V_18 ; V_15 ++ ) {
struct V_5 * V_6 = V_14 + V_15 ;
const struct V_22 * V_23 = V_13 -> V_14 + V_15 ;
T_1 V_24 ;
V_6 -> V_2 . V_25 = V_23 -> V_25 ;
V_6 -> V_2 . V_26 = V_27 ;
V_6 -> V_2 . V_28 = F_1 ;
V_6 -> V_2 . V_29 = V_23 -> V_29 ;
V_6 -> V_30 = V_23 -> V_30 ;
V_16 = F_7 ( V_23 -> V_31 , & V_6 -> V_7 ) ;
if ( V_16 < 0 )
goto V_32;
V_24 = 5 ;
if ( ! V_6 -> V_30 )
V_24 |= V_33 ;
F_3 ( & V_6 -> V_7 , V_34 , V_24 ) ;
V_24 = ( V_6 -> V_7 . V_35 / ( 1 << 5 ) ) / 100 ;
V_24 /= 255 ;
V_6 -> V_9 = V_24 ;
F_3 ( & V_6 -> V_7 , V_36 ,
V_6 -> V_2 . V_26 * 255 ) ;
F_3 ( & V_6 -> V_7 , V_37 ,
V_38 * V_24 ) ;
F_8 ( & V_6 -> V_7 ) ;
V_16 = F_9 ( & V_11 -> V_17 , & V_6 -> V_2 ) ;
if ( V_16 < 0 ) {
F_10 ( & V_6 -> V_7 ) ;
goto V_32;
}
}
F_11 ( V_11 , V_14 ) ;
return 0 ;
V_32:
if ( V_15 > 0 ) {
for ( V_15 = V_15 - 1 ; V_15 >= 0 ; V_15 -- ) {
F_12 ( & V_14 [ V_15 ] . V_2 ) ;
F_10 ( & V_14 [ V_15 ] . V_7 ) ;
}
}
return V_16 ;
}
static int F_13 ( struct V_10 * V_11 )
{
const struct V_12 * V_13 ;
struct V_5 * V_14 ;
unsigned V_15 ;
V_13 = F_5 ( & V_11 -> V_17 ) ;
V_14 = F_14 ( V_11 ) ;
for ( V_15 = 0 ; V_15 < V_13 -> V_18 ; V_15 ++ ) {
struct V_5 * V_6 = V_14 + V_15 ;
F_12 ( & V_6 -> V_2 ) ;
F_10 ( & V_6 -> V_7 ) ;
}
return 0 ;
}
