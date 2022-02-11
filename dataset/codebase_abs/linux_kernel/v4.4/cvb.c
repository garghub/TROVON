static inline int F_1 ( int V_1 , int V_2 ,
const struct V_3 * V_4 )
{
int V_5 ;
V_5 = F_2 ( V_4 -> V_6 * V_1 , V_2 ) ;
V_5 = F_2 ( ( V_5 + V_4 -> V_7 ) * V_1 , V_2 ) + V_4 -> V_8 ;
return V_5 ;
}
static int F_3 ( int V_5 , int V_9 ,
const struct V_10 * V_11 )
{
int V_12 ;
int V_13 = ( V_11 -> V_14 ? : 1000 ) * V_9 ;
int V_15 = V_11 -> V_16 * V_9 ;
V_12 = F_4 ( V_5 * 1000 , V_15 ) - V_15 ;
V_12 = F_5 ( V_12 , V_13 ) * V_11 -> V_14 + V_11 -> V_16 ;
return V_12 / 1000 ;
}
static int F_6 ( int V_5 , const struct V_10 * V_11 , int V_17 )
{
if ( V_11 -> V_14 ) {
int V_12 ;
V_12 = F_4 ( V_5 * 1000 , V_11 -> V_16 ) - V_11 -> V_16 ;
V_12 = ( V_12 + ( V_17 ? V_11 -> V_14 - 1 : 0 ) ) / V_11 -> V_14 ;
return ( V_12 * V_11 -> V_14 + V_11 -> V_16 ) / 1000 ;
}
return V_5 ;
}
static int F_7 ( const struct V_18 * V_19 ,
int V_20 ,
unsigned long V_21 ,
struct V_22 * V_23 )
{
int V_24 , V_25 , V_26 , V_27 , V_28 ;
const struct V_29 * V_30 = NULL ;
const struct V_10 * V_11 = & V_19 -> V_31 ;
V_27 = F_6 ( V_19 -> V_32 , V_11 , V_33 ) ;
V_28 = F_6 ( V_19 -> V_34 , V_11 , V_35 ) ;
for ( V_24 = 0 ; V_24 < V_36 ; V_24 ++ ) {
V_30 = & V_19 -> V_18 [ V_24 ] ;
if ( ! V_30 -> V_37 || ( V_30 -> V_37 > V_21 ) )
break;
V_26 = F_1 (
V_20 , V_19 -> V_38 , & V_30 -> V_39 ) ;
V_26 = F_3 ( V_26 , V_19 -> V_40 , V_11 ) ;
V_26 = F_8 ( V_26 , V_27 , V_28 ) ;
V_25 = F_9 ( V_23 , V_30 -> V_37 , V_26 * 1000 ) ;
if ( V_25 )
return V_25 ;
}
return 0 ;
}
const struct V_18 * F_10 (
const struct V_18 * V_41 ,
T_1 V_42 , int V_43 ,
int V_44 , int V_20 ,
unsigned long V_45 ,
struct V_22 * V_23 )
{
int V_24 , V_25 ;
for ( V_24 = 0 ; V_24 < V_42 ; V_24 ++ ) {
const struct V_18 * V_19 = & V_41 [ V_24 ] ;
if ( V_19 -> V_44 != - 1 && V_19 -> V_44 != V_44 )
continue;
if ( V_19 -> V_43 != - 1 && V_19 -> V_43 != V_43 )
continue;
V_25 = F_7 ( V_19 , V_20 , V_45 , V_23 ) ;
return V_25 ? F_11 ( V_25 ) : V_19 ;
}
return F_11 ( - V_46 ) ;
}
