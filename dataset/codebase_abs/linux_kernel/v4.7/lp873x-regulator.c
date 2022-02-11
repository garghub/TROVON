static int F_1 ( struct V_1 * V_2 ,
int V_3 )
{
int V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_2 ) ;
unsigned int V_7 ;
int V_8 ;
if ( V_3 <= 470 )
V_7 = 7 ;
else if ( V_3 <= 940 )
V_7 = 6 ;
else if ( V_3 <= 1900 )
V_7 = 5 ;
else if ( V_3 <= 3800 )
V_7 = 4 ;
else if ( V_3 <= 7500 )
V_7 = 3 ;
else if ( V_3 <= 10000 )
V_7 = 2 ;
else if ( V_3 <= 15000 )
V_7 = 1 ;
else
V_7 = 0 ;
V_8 = F_4 ( V_6 -> V_9 , V_10 [ V_4 ] . V_11 ,
V_12 ,
V_7 << F_5 ( V_12 ) ) ;
if ( V_8 ) {
F_6 ( V_6 -> V_13 , L_1 , V_8 ) ;
return V_8 ;
}
V_2 -> V_14 -> V_3 = V_15 [ V_7 ] ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
int V_16 , int V_17 )
{
int V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_2 ) ;
int V_18 ;
for ( V_18 = F_8 ( V_19 ) - 1 ; V_18 >= 0 ; V_18 -- ) {
if ( V_19 [ V_18 ] >= V_16 &&
V_19 [ V_18 ] <= V_17 )
return F_4 ( V_6 -> V_9 ,
V_10 [ V_4 ] . V_11 ,
V_20 ,
V_18 << F_5 ( V_20 ) ) ;
}
return - V_21 ;
}
static int F_9 ( struct V_1 * V_2 )
{
int V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_2 ) ;
int V_8 ;
unsigned int V_22 ;
V_8 = F_10 ( V_6 -> V_9 , V_10 [ V_4 ] . V_11 , & V_22 ) ;
if ( V_8 )
return V_8 ;
V_22 = ( V_22 & V_20 ) >>
F_5 ( V_20 ) ;
return ( V_22 < F_8 ( V_19 ) ) ?
V_19 [ V_22 ] : - V_21 ;
}
static int F_11 ( struct V_23 * V_24 )
{
struct V_5 * V_6 = F_12 ( V_24 -> V_13 . V_25 ) ;
struct V_26 V_27 = { } ;
struct V_1 * V_2 ;
int V_18 ;
F_13 ( V_24 , V_6 ) ;
V_27 . V_13 = & V_24 -> V_13 ;
V_27 . V_13 -> V_28 = V_6 -> V_13 -> V_28 ;
V_27 . V_29 = V_6 ;
V_27 . V_9 = V_6 -> V_9 ;
for ( V_18 = 0 ; V_18 < F_8 ( V_10 ) ; V_18 ++ ) {
V_2 = F_14 ( & V_24 -> V_13 , & V_10 [ V_18 ] . V_30 ,
& V_27 ) ;
if ( F_15 ( V_2 ) ) {
F_6 ( V_6 -> V_13 , L_2 ,
V_24 -> V_31 ) ;
return F_16 ( V_2 ) ;
}
}
return 0 ;
}
