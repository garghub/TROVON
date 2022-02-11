static int F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 = V_2 -> V_4 -> V_5 ;
unsigned int V_6 = V_2 -> V_4 -> V_7 ;
unsigned int V_8 , V_9 ;
unsigned int V_10 ;
int V_11 ;
V_11 = F_2 ( V_2 -> V_12 , V_13 , & V_8 ) ;
if ( V_11 < 0 )
return V_11 ;
V_9 = V_8 & V_14 ;
if ( V_9 <= 3 )
V_9 = 0 ;
else
V_9 -= 3 ;
V_10 = V_3 + V_15 * V_9 ;
if ( V_10 > V_6 )
return - V_16 ;
return V_10 ;
}
static int F_3 ( struct V_1 * V_2 ,
int V_5 , int V_7 )
{
unsigned int V_3 = V_2 -> V_4 -> V_5 ;
int V_9 = 0 ;
while ( V_3 + V_15 * V_9 < V_5 )
V_9 ++ ;
if ( V_3 + V_15 * V_9 > V_7 )
return - V_16 ;
V_9 += 3 ;
return F_4 ( V_2 -> V_12 ,
V_13 , V_9 ) ;
}
static int F_5 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = F_6 ( V_18 -> V_21 . V_22 ) ;
int V_23 ;
struct V_24 V_25 = { } ;
V_25 . V_21 = V_20 -> V_21 ;
V_25 . V_12 = V_20 -> V_12 ;
for ( V_23 = 0 ; V_23 < F_7 ( V_26 ) ; V_23 ++ ) {
struct V_1 * V_2 ;
V_2 = F_8 ( & V_18 -> V_21 ,
& V_26 [ V_23 ] , & V_25 ) ;
if ( F_9 ( V_2 ) ) {
F_10 ( & V_18 -> V_21 ,
L_1 , V_23 ) ;
return F_11 ( V_2 ) ;
}
}
return 0 ;
}
