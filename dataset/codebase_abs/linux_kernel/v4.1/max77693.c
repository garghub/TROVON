static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
unsigned int V_4 ;
V_3 = F_2 ( V_2 -> V_5 , V_2 -> V_6 -> V_7 , & V_4 ) ;
if ( V_3 )
return V_3 ;
return ( V_4 & V_2 -> V_6 -> V_8 ) == V_2 -> V_6 -> V_8 ;
}
static int F_3 ( struct V_1 * V_2 )
{
unsigned int V_9 = V_2 -> V_10 -> V_11 ;
unsigned int V_12 = V_2 -> V_10 -> V_13 ;
unsigned int V_14 , V_15 ;
unsigned int V_4 ;
int V_3 ;
V_3 = F_2 ( V_2 -> V_5 , V_16 , & V_14 ) ;
if ( V_3 < 0 )
return V_3 ;
V_15 = V_14 & V_17 ;
if ( V_15 <= 3 )
V_15 = 0 ;
else
V_15 -= 3 ;
V_4 = V_9 + V_18 * V_15 ;
if ( V_4 > V_12 )
return - V_19 ;
return V_4 ;
}
static int F_4 ( struct V_1 * V_2 ,
int V_11 , int V_13 )
{
unsigned int V_9 = V_2 -> V_10 -> V_11 ;
int V_15 = 0 ;
while ( V_9 + V_18 * V_15 < V_11 )
V_15 ++ ;
if ( V_9 + V_18 * V_15 > V_13 )
return - V_19 ;
V_15 += 3 ;
return F_5 ( V_2 -> V_5 ,
V_16 , V_15 ) ;
}
static int F_6 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = F_7 ( V_21 -> V_24 . V_25 ) ;
int V_26 ;
struct V_27 V_28 = { } ;
V_28 . V_24 = V_23 -> V_24 ;
V_28 . V_5 = V_23 -> V_5 ;
for ( V_26 = 0 ; V_26 < F_8 ( V_29 ) ; V_26 ++ ) {
struct V_1 * V_2 ;
V_2 = F_9 ( & V_21 -> V_24 ,
& V_29 [ V_26 ] , & V_28 ) ;
if ( F_10 ( V_2 ) ) {
F_11 ( & V_21 -> V_24 ,
L_1 , V_26 ) ;
return F_12 ( V_2 ) ;
}
}
return 0 ;
}
