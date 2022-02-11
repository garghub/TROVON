static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
int V_7 = F_3 ( V_2 ) ;
int V_8 ;
F_4 ( F_5 ( V_2 ) , L_1 , V_9 , V_7 ) ;
F_6 ( V_4 -> V_10 ) ;
V_8 = F_7 ( V_4 -> V_10 , V_6 [ V_7 ] . V_11 ,
V_6 [ V_7 ] . V_12 ,
V_6 [ V_7 ] . V_12 ) ;
F_8 ( V_4 -> V_10 ) ;
return V_8 ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
int V_7 = F_3 ( V_2 ) ;
int V_8 ;
F_4 ( F_5 ( V_2 ) , L_1 , V_9 , V_7 ) ;
F_6 ( V_4 -> V_10 ) ;
V_8 = F_7 ( V_4 -> V_10 , V_6 [ V_7 ] . V_11 ,
V_6 [ V_7 ] . V_12 , 0 ) ;
F_8 ( V_4 -> V_10 ) ;
return V_8 ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
int V_8 , V_7 = F_3 ( V_2 ) ;
unsigned int V_13 ;
F_6 ( V_4 -> V_10 ) ;
V_8 = F_11 ( V_4 -> V_10 , V_6 [ V_7 ] . V_11 , & V_13 ) ;
F_8 ( V_4 -> V_10 ) ;
if ( V_8 )
return V_8 ;
return ( V_13 & V_6 [ V_7 ] . V_12 ) != 0 ;
}
int F_12 ( struct V_1 * V_2 ,
unsigned V_14 )
{
int V_7 = F_3 ( V_2 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
if ( V_14 >= V_6 [ V_7 ] . V_15 . V_16 )
return - V_17 ;
return V_6 [ V_7 ] . V_18 [ V_14 ] ;
}
int F_13 ( struct V_1 * V_2 ,
int V_19 , int V_20 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
int V_21 = F_3 ( V_2 ) ;
int V_22 ;
int V_23 ;
int V_24 ;
V_23 = V_25 ;
V_24 = - 1 ;
for ( V_22 = 0 ; V_22 < V_6 [ V_21 ] . V_15 . V_16 ; V_22 ++ ) {
if ( V_6 [ V_21 ] . V_18 [ V_22 ] >= V_19 &&
V_6 [ V_21 ] . V_18 [ V_22 ] < V_23 ) {
V_23 = V_6 [ V_21 ] . V_18 [ V_22 ] ;
V_24 = V_22 ;
}
}
if ( V_24 < 0 || V_23 > V_20 ) {
F_14 ( & V_2 -> V_26 , L_2 ,
V_19 , V_20 ) ;
return - V_17 ;
}
return V_24 ;
}
static int F_15 ( struct V_1 * V_2 , int V_19 ,
int V_20 , unsigned * V_14 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
int V_27 , V_7 = F_3 ( V_2 ) ;
int V_8 ;
F_4 ( F_5 ( V_2 ) , L_3 ,
V_9 , V_7 , V_19 , V_20 ) ;
V_27 = F_13 ( V_2 , V_19 , V_20 ) ;
F_4 ( F_5 ( V_2 ) , L_4 , V_9 , V_27 ) ;
if ( V_27 < 0 )
return V_27 ;
F_6 ( V_4 -> V_10 ) ;
V_8 = F_7 ( V_4 -> V_10 , V_6 [ V_7 ] . V_28 ,
V_6 [ V_7 ] . V_29 ,
V_27 << V_6 [ V_7 ] . V_30 ) ;
F_8 ( V_4 -> V_10 ) ;
return V_8 ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
int V_8 , V_7 = F_3 ( V_2 ) ;
unsigned int V_13 ;
F_4 ( F_5 ( V_2 ) , L_1 , V_9 , V_7 ) ;
F_6 ( V_4 -> V_10 ) ;
V_8 = F_11 ( V_4 -> V_10 ,
V_6 [ V_7 ] . V_28 , & V_13 ) ;
F_8 ( V_4 -> V_10 ) ;
if ( V_8 )
return V_8 ;
V_13 = ( V_13 & V_6 [ V_7 ] . V_29 )
>> V_6 [ V_7 ] . V_30 ;
F_4 ( F_5 ( V_2 ) , L_5 , V_9 , V_7 , V_13 ) ;
F_17 ( V_13 >= V_6 [ V_7 ] . V_15 . V_16 ) ;
return V_6 [ V_7 ] . V_18 [ V_13 ] ;
}
int F_18 ( struct V_1 * V_2 , int V_19 ,
int V_20 , unsigned * V_14 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
int V_7 = F_3 ( V_2 ) ;
F_4 ( F_5 ( V_2 ) , L_3 ,
V_9 , V_7 , V_19 , V_20 ) ;
if ( V_19 >= V_6 [ V_7 ] . V_18 [ 0 ] &&
V_20 <= V_6 [ V_7 ] . V_18 [ 0 ] )
return 0 ;
else
return - V_17 ;
}
int F_19 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
int V_7 = F_3 ( V_2 ) ;
F_4 ( F_5 ( V_2 ) , L_1 , V_9 , V_7 ) ;
return V_6 [ V_7 ] . V_18 [ 0 ] ;
}
int F_20 ( struct V_1 * V_2 )
{
return 1 ;
}
