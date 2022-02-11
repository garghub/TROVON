int F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
int V_4 ;
V_4 = F_2 ( V_2 -> V_5 , V_2 -> V_6 -> V_7 , & V_3 ) ;
if ( V_4 != 0 )
return V_4 ;
if ( V_2 -> V_6 -> V_8 )
return ( V_3 & V_2 -> V_6 -> V_9 ) == 0 ;
else
return ( V_3 & V_2 -> V_6 -> V_9 ) != 0 ;
}
int F_3 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
if ( V_2 -> V_6 -> V_8 )
V_3 = 0 ;
else
V_3 = V_2 -> V_6 -> V_9 ;
return F_4 ( V_2 -> V_5 , V_2 -> V_6 -> V_7 ,
V_2 -> V_6 -> V_9 , V_3 ) ;
}
int F_5 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
if ( V_2 -> V_6 -> V_8 )
V_3 = V_2 -> V_6 -> V_9 ;
else
V_3 = 0 ;
return F_4 ( V_2 -> V_5 , V_2 -> V_6 -> V_7 ,
V_2 -> V_6 -> V_9 , V_3 ) ;
}
int F_6 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
int V_4 ;
V_4 = F_2 ( V_2 -> V_5 , V_2 -> V_6 -> V_10 , & V_3 ) ;
if ( V_4 != 0 )
return V_4 ;
V_3 &= V_2 -> V_6 -> V_11 ;
V_3 >>= F_7 ( V_2 -> V_6 -> V_11 ) - 1 ;
return V_3 ;
}
int F_8 ( struct V_1 * V_2 , unsigned V_12 )
{
int V_4 ;
V_12 <<= F_7 ( V_2 -> V_6 -> V_11 ) - 1 ;
V_4 = F_4 ( V_2 -> V_5 , V_2 -> V_6 -> V_10 ,
V_2 -> V_6 -> V_11 , V_12 ) ;
if ( V_4 )
return V_4 ;
if ( V_2 -> V_6 -> V_13 )
V_4 = F_4 ( V_2 -> V_5 , V_2 -> V_6 -> V_14 ,
V_2 -> V_6 -> V_13 ,
V_2 -> V_6 -> V_13 ) ;
return V_4 ;
}
int F_9 ( struct V_1 * V_2 ,
int V_15 , int V_16 )
{
int V_17 = V_18 ;
int V_19 = 0 ;
int V_20 , V_4 ;
for ( V_20 = 0 ; V_20 < V_2 -> V_6 -> V_21 ; V_20 ++ ) {
V_4 = V_2 -> V_6 -> V_22 -> V_23 ( V_2 , V_20 ) ;
if ( V_4 < 0 )
continue;
if ( V_4 < V_17 && V_4 >= V_15 && V_4 <= V_16 ) {
V_17 = V_4 ;
V_19 = V_20 ;
}
}
if ( V_17 != V_18 )
return V_19 ;
else
return - V_24 ;
}
int F_10 ( struct V_1 * V_2 ,
int V_15 , int V_16 )
{
int V_20 , V_4 ;
for ( V_20 = 0 ; V_20 < V_2 -> V_6 -> V_21 ; V_20 ++ ) {
V_4 = V_2 -> V_6 -> V_22 -> V_23 ( V_2 , V_20 ) ;
if ( V_4 < 0 )
continue;
if ( V_4 > V_16 )
break;
if ( V_4 >= V_15 && V_4 <= V_16 )
return V_20 ;
}
return - V_24 ;
}
int F_11 ( struct V_1 * V_2 ,
int V_15 , int V_16 )
{
int V_4 , V_25 ;
if ( V_2 -> V_6 -> V_21 == 1 && V_2 -> V_6 -> V_26 == 0 ) {
if ( V_15 <= V_2 -> V_6 -> V_15 && V_2 -> V_6 -> V_15 <= V_16 )
return 0 ;
else
return - V_24 ;
}
if ( ! V_2 -> V_6 -> V_26 ) {
F_12 ( ! V_2 -> V_6 -> V_26 ) ;
return - V_24 ;
}
if ( V_15 < V_2 -> V_6 -> V_15 )
V_15 = V_2 -> V_6 -> V_15 ;
V_4 = F_13 ( V_15 - V_2 -> V_6 -> V_15 , V_2 -> V_6 -> V_26 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 += V_2 -> V_6 -> V_27 ;
V_25 = V_2 -> V_6 -> V_22 -> V_23 ( V_2 , V_4 ) ;
if ( V_25 < V_15 || V_25 > V_16 )
return - V_24 ;
return V_4 ;
}
int F_14 ( struct V_1 * V_2 ,
int V_15 , int V_16 )
{
const struct V_28 * V_29 ;
int V_4 = - V_24 ;
int V_25 , V_20 ;
if ( ! V_2 -> V_6 -> V_30 ) {
F_12 ( ! V_2 -> V_6 -> V_30 ) ;
return - V_24 ;
}
for ( V_20 = 0 ; V_20 < V_2 -> V_6 -> V_30 ; V_20 ++ ) {
int V_31 ;
V_29 = & V_2 -> V_6 -> V_32 [ V_20 ] ;
V_31 = V_29 -> V_15 +
( V_29 -> V_33 - V_29 -> V_34 ) * V_29 -> V_26 ;
if ( ! ( V_15 <= V_31 && V_16 >= V_29 -> V_15 ) )
continue;
if ( V_15 <= V_29 -> V_15 )
V_15 = V_29 -> V_15 ;
if ( V_29 -> V_26 == 0 ) {
V_4 = 0 ;
} else {
V_4 = F_13 ( V_15 - V_29 -> V_15 ,
V_29 -> V_26 ) ;
if ( V_4 < 0 )
return V_4 ;
}
V_4 += V_29 -> V_34 ;
break;
}
if ( V_20 == V_2 -> V_6 -> V_30 )
return - V_24 ;
V_25 = V_2 -> V_6 -> V_22 -> V_23 ( V_2 , V_4 ) ;
if ( V_25 < V_15 || V_25 > V_16 )
return - V_24 ;
return V_4 ;
}
int F_15 ( struct V_1 * V_2 ,
unsigned int V_19 )
{
if ( V_19 >= V_2 -> V_6 -> V_21 )
return - V_24 ;
if ( V_19 < V_2 -> V_6 -> V_27 )
return 0 ;
V_19 -= V_2 -> V_6 -> V_27 ;
return V_2 -> V_6 -> V_15 + ( V_2 -> V_6 -> V_26 * V_19 ) ;
}
int F_16 ( struct V_1 * V_2 ,
unsigned int V_19 )
{
const struct V_28 * V_29 ;
int V_20 ;
if ( ! V_2 -> V_6 -> V_30 ) {
F_12 ( ! V_2 -> V_6 -> V_30 ) ;
return - V_24 ;
}
for ( V_20 = 0 ; V_20 < V_2 -> V_6 -> V_30 ; V_20 ++ ) {
V_29 = & V_2 -> V_6 -> V_32 [ V_20 ] ;
if ( ! ( V_19 >= V_29 -> V_34 &&
V_19 <= V_29 -> V_33 ) )
continue;
V_19 -= V_29 -> V_34 ;
return V_29 -> V_15 + ( V_29 -> V_26 * V_19 ) ;
}
return - V_24 ;
}
int F_17 ( struct V_1 * V_2 ,
unsigned int V_19 )
{
if ( ! V_2 -> V_6 -> V_35 ) {
F_12 ( ! V_2 -> V_6 -> V_35 ) ;
return - V_24 ;
}
if ( V_19 >= V_2 -> V_6 -> V_21 )
return - V_24 ;
return V_2 -> V_6 -> V_35 [ V_19 ] ;
}
int F_18 ( struct V_1 * V_2 , bool V_36 )
{
unsigned int V_3 ;
if ( V_36 )
V_3 = V_2 -> V_6 -> V_37 ;
else
V_3 = 0 ;
return F_4 ( V_2 -> V_5 , V_2 -> V_6 -> V_38 ,
V_2 -> V_6 -> V_37 , V_3 ) ;
}
int F_19 ( struct V_1 * V_2 , bool * V_36 )
{
unsigned int V_3 ;
int V_4 ;
V_4 = F_2 ( V_2 -> V_5 , V_2 -> V_6 -> V_38 , & V_3 ) ;
if ( V_4 != 0 )
return V_4 ;
* V_36 = V_3 & V_2 -> V_6 -> V_37 ;
return 0 ;
}
