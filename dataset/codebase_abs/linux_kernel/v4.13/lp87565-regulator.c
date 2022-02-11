static int F_1 ( struct V_1 * V_2 ,
int V_3 )
{
int V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = F_3 ( V_2 ) ;
unsigned int V_6 ;
int V_7 ;
if ( V_3 <= 470 )
V_6 = 7 ;
else if ( V_3 <= 940 )
V_6 = 6 ;
else if ( V_3 <= 1900 )
V_6 = 5 ;
else if ( V_3 <= 3800 )
V_6 = 4 ;
else if ( V_3 <= 7500 )
V_6 = 3 ;
else if ( V_3 <= 10000 )
V_6 = 2 ;
else if ( V_3 <= 15000 )
V_6 = 1 ;
else
V_6 = 0 ;
V_7 = F_4 ( V_5 -> V_8 , V_9 [ V_4 ] . V_10 ,
V_11 ,
V_6 << F_5 ( V_11 ) ) ;
if ( V_7 ) {
F_6 ( V_5 -> V_12 , L_1 , V_7 ) ;
return V_7 ;
}
V_2 -> V_13 -> V_3 = V_14 [ V_6 ] ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
int V_15 , int V_16 )
{
int V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = F_3 ( V_2 ) ;
int V_17 ;
for ( V_17 = F_8 ( V_18 ) - 1 ; V_17 >= 0 ; V_17 -- ) {
if ( V_18 [ V_17 ] >= V_15 &&
V_18 [ V_17 ] <= V_16 )
return F_4 ( V_5 -> V_8 ,
V_9 [ V_4 ] . V_10 ,
V_19 ,
V_17 << F_5 ( V_19 ) ) ;
}
return - V_20 ;
}
static int F_9 ( struct V_1 * V_2 )
{
int V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = F_3 ( V_2 ) ;
int V_7 ;
unsigned int V_21 ;
V_7 = F_10 ( V_5 -> V_8 , V_9 [ V_4 ] . V_10 , & V_21 ) ;
if ( V_7 )
return V_7 ;
V_21 = ( V_21 & V_19 ) >>
F_5 ( V_19 ) ;
return ( V_21 < F_8 ( V_18 ) ) ?
V_18 [ V_21 ] : - V_20 ;
}
static int F_11 ( struct V_22 * V_23 )
{
struct V_5 * V_5 = F_12 ( V_23 -> V_12 . V_24 ) ;
struct V_25 V_26 = { } ;
struct V_1 * V_2 ;
int V_17 , V_27 = V_28 , V_29 = V_30 ;
F_13 ( V_23 , V_5 ) ;
V_26 . V_12 = & V_23 -> V_12 ;
V_26 . V_12 -> V_31 = V_5 -> V_12 -> V_31 ;
V_26 . V_32 = V_5 ;
V_26 . V_8 = V_5 -> V_8 ;
if ( V_5 -> V_33 == V_34 ) {
V_27 = V_35 ;
V_29 = V_36 ;
}
for ( V_17 = V_27 ; V_17 <= V_29 ; V_17 ++ ) {
V_2 = F_14 ( & V_23 -> V_12 , & V_9 [ V_17 ] . V_37 ,
& V_26 ) ;
if ( F_15 ( V_2 ) ) {
F_6 ( V_5 -> V_12 , L_2 ,
V_23 -> V_38 ) ;
return F_16 ( V_2 ) ;
}
}
return 0 ;
}
