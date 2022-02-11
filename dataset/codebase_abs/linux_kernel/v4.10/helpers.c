int F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
int V_4 ;
V_4 = F_2 ( V_2 -> V_5 , V_2 -> V_6 -> V_7 , & V_3 ) ;
if ( V_4 != 0 )
return V_4 ;
V_3 &= V_2 -> V_6 -> V_8 ;
if ( V_2 -> V_6 -> V_9 ) {
if ( V_2 -> V_6 -> V_10 )
return V_3 != V_2 -> V_6 -> V_10 ;
return V_3 == 0 ;
} else {
if ( V_2 -> V_6 -> V_10 )
return V_3 == V_2 -> V_6 -> V_10 ;
return V_3 != 0 ;
}
}
int F_3 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
if ( V_2 -> V_6 -> V_9 ) {
V_3 = V_2 -> V_6 -> V_11 ;
} else {
V_3 = V_2 -> V_6 -> V_10 ;
if ( ! V_3 )
V_3 = V_2 -> V_6 -> V_8 ;
}
return F_4 ( V_2 -> V_5 , V_2 -> V_6 -> V_7 ,
V_2 -> V_6 -> V_8 , V_3 ) ;
}
int F_5 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
if ( V_2 -> V_6 -> V_9 ) {
V_3 = V_2 -> V_6 -> V_10 ;
if ( ! V_3 )
V_3 = V_2 -> V_6 -> V_8 ;
} else {
V_3 = V_2 -> V_6 -> V_11 ;
}
return F_4 ( V_2 -> V_5 , V_2 -> V_6 -> V_7 ,
V_2 -> V_6 -> V_8 , V_3 ) ;
}
int F_6 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
int V_4 ;
V_4 = F_2 ( V_2 -> V_5 , V_2 -> V_6 -> V_12 , & V_3 ) ;
if ( V_4 != 0 )
return V_4 ;
V_3 &= V_2 -> V_6 -> V_13 ;
V_3 >>= F_7 ( V_2 -> V_6 -> V_13 ) - 1 ;
return V_3 ;
}
int F_8 ( struct V_1 * V_2 , unsigned V_14 )
{
int V_4 ;
V_14 <<= F_7 ( V_2 -> V_6 -> V_13 ) - 1 ;
V_4 = F_4 ( V_2 -> V_5 , V_2 -> V_6 -> V_12 ,
V_2 -> V_6 -> V_13 , V_14 ) ;
if ( V_4 )
return V_4 ;
if ( V_2 -> V_6 -> V_15 )
V_4 = F_4 ( V_2 -> V_5 , V_2 -> V_6 -> V_16 ,
V_2 -> V_6 -> V_15 ,
V_2 -> V_6 -> V_15 ) ;
return V_4 ;
}
int F_9 ( struct V_1 * V_2 ,
int V_17 , int V_18 )
{
int V_19 = V_20 ;
int V_21 = 0 ;
int V_22 , V_4 ;
for ( V_22 = 0 ; V_22 < V_2 -> V_6 -> V_23 ; V_22 ++ ) {
V_4 = V_2 -> V_6 -> V_24 -> V_25 ( V_2 , V_22 ) ;
if ( V_4 < 0 )
continue;
if ( V_4 < V_19 && V_4 >= V_17 && V_4 <= V_18 ) {
V_19 = V_4 ;
V_21 = V_22 ;
}
}
if ( V_19 != V_20 )
return V_21 ;
else
return - V_26 ;
}
int F_10 ( struct V_1 * V_2 ,
int V_17 , int V_18 )
{
int V_22 , V_4 ;
for ( V_22 = 0 ; V_22 < V_2 -> V_6 -> V_23 ; V_22 ++ ) {
V_4 = V_2 -> V_6 -> V_24 -> V_25 ( V_2 , V_22 ) ;
if ( V_4 < 0 )
continue;
if ( V_4 > V_18 )
break;
if ( V_4 >= V_17 && V_4 <= V_18 )
return V_22 ;
}
return - V_26 ;
}
int F_11 ( struct V_1 * V_2 ,
int V_17 , int V_18 )
{
int V_4 , V_27 ;
if ( V_2 -> V_6 -> V_23 == 1 && V_2 -> V_6 -> V_28 == 0 ) {
if ( V_17 <= V_2 -> V_6 -> V_17 && V_2 -> V_6 -> V_17 <= V_18 )
return 0 ;
else
return - V_26 ;
}
if ( ! V_2 -> V_6 -> V_28 ) {
F_12 ( ! V_2 -> V_6 -> V_28 ) ;
return - V_26 ;
}
if ( V_17 < V_2 -> V_6 -> V_17 )
V_17 = V_2 -> V_6 -> V_17 ;
V_4 = F_13 ( V_17 - V_2 -> V_6 -> V_17 , V_2 -> V_6 -> V_28 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 += V_2 -> V_6 -> V_29 ;
V_27 = V_2 -> V_6 -> V_24 -> V_25 ( V_2 , V_4 ) ;
if ( V_27 < V_17 || V_27 > V_18 )
return - V_26 ;
return V_4 ;
}
int F_14 ( struct V_1 * V_2 ,
int V_17 , int V_18 )
{
const struct V_30 * V_31 ;
int V_4 = - V_26 ;
int V_27 , V_22 ;
if ( ! V_2 -> V_6 -> V_32 ) {
F_12 ( ! V_2 -> V_6 -> V_32 ) ;
return - V_26 ;
}
for ( V_22 = 0 ; V_22 < V_2 -> V_6 -> V_32 ; V_22 ++ ) {
int V_33 ;
V_31 = & V_2 -> V_6 -> V_34 [ V_22 ] ;
V_33 = V_31 -> V_17 +
( V_31 -> V_35 - V_31 -> V_36 ) * V_31 -> V_28 ;
if ( ! ( V_17 <= V_33 && V_18 >= V_31 -> V_17 ) )
continue;
if ( V_17 <= V_31 -> V_17 )
V_17 = V_31 -> V_17 ;
if ( V_31 -> V_28 == 0 ) {
V_4 = 0 ;
} else {
V_4 = F_13 ( V_17 - V_31 -> V_17 ,
V_31 -> V_28 ) ;
if ( V_4 < 0 )
return V_4 ;
}
V_4 += V_31 -> V_36 ;
break;
}
if ( V_22 == V_2 -> V_6 -> V_32 )
return - V_26 ;
V_27 = V_2 -> V_6 -> V_24 -> V_25 ( V_2 , V_4 ) ;
if ( V_27 < V_17 || V_27 > V_18 )
return - V_26 ;
return V_4 ;
}
int F_15 ( struct V_1 * V_2 ,
unsigned int V_21 )
{
if ( V_21 >= V_2 -> V_6 -> V_23 )
return - V_26 ;
if ( V_21 < V_2 -> V_6 -> V_29 )
return 0 ;
V_21 -= V_2 -> V_6 -> V_29 ;
return V_2 -> V_6 -> V_17 + ( V_2 -> V_6 -> V_28 * V_21 ) ;
}
int F_16 ( struct V_1 * V_2 ,
unsigned int V_21 )
{
const struct V_30 * V_31 ;
int V_22 ;
if ( ! V_2 -> V_6 -> V_32 ) {
F_12 ( ! V_2 -> V_6 -> V_32 ) ;
return - V_26 ;
}
for ( V_22 = 0 ; V_22 < V_2 -> V_6 -> V_32 ; V_22 ++ ) {
V_31 = & V_2 -> V_6 -> V_34 [ V_22 ] ;
if ( ! ( V_21 >= V_31 -> V_36 &&
V_21 <= V_31 -> V_35 ) )
continue;
V_21 -= V_31 -> V_36 ;
return V_31 -> V_17 + ( V_31 -> V_28 * V_21 ) ;
}
return - V_26 ;
}
int F_17 ( struct V_1 * V_2 ,
unsigned int V_21 )
{
if ( ! V_2 -> V_6 -> V_37 ) {
F_12 ( ! V_2 -> V_6 -> V_37 ) ;
return - V_26 ;
}
if ( V_21 >= V_2 -> V_6 -> V_23 )
return - V_26 ;
return V_2 -> V_6 -> V_37 [ V_21 ] ;
}
int F_18 ( struct V_1 * V_2 , bool V_38 )
{
unsigned int V_3 ;
if ( V_38 ) {
V_3 = V_2 -> V_6 -> V_39 ;
if ( ! V_3 )
V_3 = V_2 -> V_6 -> V_40 ;
} else {
V_3 = V_2 -> V_6 -> V_41 ;
}
return F_4 ( V_2 -> V_5 , V_2 -> V_6 -> V_42 ,
V_2 -> V_6 -> V_40 , V_3 ) ;
}
int F_19 ( struct V_1 * V_2 , bool * V_38 )
{
unsigned int V_3 ;
unsigned int V_43 = V_2 -> V_6 -> V_39 ;
int V_4 ;
V_4 = F_2 ( V_2 -> V_5 , V_2 -> V_6 -> V_42 , & V_3 ) ;
if ( V_4 != 0 )
return V_4 ;
if ( ! V_43 )
V_43 = V_2 -> V_6 -> V_40 ;
* V_38 = ( V_3 & V_2 -> V_6 -> V_40 ) == V_43 ;
return 0 ;
}
int F_20 ( struct V_1 * V_2 ,
bool V_38 )
{
unsigned int V_3 ;
if ( V_38 )
V_3 = V_2 -> V_6 -> V_44 ;
else
V_3 = V_2 -> V_6 -> V_45 ;
return F_4 ( V_2 -> V_5 ,
V_2 -> V_6 -> V_46 ,
V_2 -> V_6 -> V_47 , V_3 ) ;
}
