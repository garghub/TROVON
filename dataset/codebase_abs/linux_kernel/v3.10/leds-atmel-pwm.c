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
V_13 = V_11 -> V_17 . V_18 ;
if ( ! V_13 || V_13 -> V_19 < 1 )
return - V_20 ;
V_14 = F_5 ( & V_11 -> V_17 , V_13 -> V_19 * sizeof( * V_14 ) ,
V_21 ) ;
if ( ! V_14 )
return - V_22 ;
for ( V_15 = 0 ; V_15 < V_13 -> V_19 ; V_15 ++ ) {
struct V_5 * V_6 = V_14 + V_15 ;
const struct V_23 * V_24 = V_13 -> V_14 + V_15 ;
T_1 V_25 ;
V_6 -> V_2 . V_26 = V_24 -> V_26 ;
V_6 -> V_2 . V_27 = V_28 ;
V_6 -> V_2 . V_29 = F_1 ;
V_6 -> V_2 . V_30 = V_24 -> V_30 ;
V_6 -> V_31 = V_24 -> V_31 ;
V_16 = F_6 ( V_24 -> V_32 , & V_6 -> V_7 ) ;
if ( V_16 < 0 )
goto V_33;
V_25 = 5 ;
if ( ! V_6 -> V_31 )
V_25 |= V_34 ;
F_3 ( & V_6 -> V_7 , V_35 , V_25 ) ;
V_25 = ( V_6 -> V_7 . V_36 / ( 1 << 5 ) ) / 100 ;
V_25 /= 255 ;
V_6 -> V_9 = V_25 ;
F_3 ( & V_6 -> V_7 , V_37 ,
V_6 -> V_2 . V_27 * 255 ) ;
F_3 ( & V_6 -> V_7 , V_38 ,
V_39 * V_25 ) ;
F_7 ( & V_6 -> V_7 ) ;
V_16 = F_8 ( & V_11 -> V_17 , & V_6 -> V_2 ) ;
if ( V_16 < 0 ) {
F_9 ( & V_6 -> V_7 ) ;
goto V_33;
}
}
F_10 ( V_11 , V_14 ) ;
return 0 ;
V_33:
if ( V_15 > 0 ) {
for ( V_15 = V_15 - 1 ; V_15 >= 0 ; V_15 -- ) {
F_11 ( & V_14 [ V_15 ] . V_2 ) ;
F_9 ( & V_14 [ V_15 ] . V_7 ) ;
}
}
return V_16 ;
}
static int F_12 ( struct V_10 * V_11 )
{
const struct V_12 * V_13 ;
struct V_5 * V_14 ;
unsigned V_15 ;
V_13 = V_11 -> V_17 . V_18 ;
V_14 = F_13 ( V_11 ) ;
for ( V_15 = 0 ; V_15 < V_13 -> V_19 ; V_15 ++ ) {
struct V_5 * V_6 = V_14 + V_15 ;
F_11 ( & V_6 -> V_2 ) ;
F_9 ( & V_6 -> V_7 ) ;
}
F_10 ( V_11 , NULL ) ;
return 0 ;
}
