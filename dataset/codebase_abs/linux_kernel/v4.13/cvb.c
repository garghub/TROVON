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
static int F_7 ( struct V_18 * V_19 , const struct V_20 * V_21 ,
int V_22 , unsigned long V_23 )
{
const struct V_10 * V_11 = & V_21 -> V_24 ;
int V_25 , V_26 , V_27 , V_28 , V_29 ;
V_28 = F_6 ( V_21 -> V_30 , V_11 , V_31 ) ;
V_29 = F_6 ( V_21 -> V_32 , V_11 , V_33 ) ;
for ( V_25 = 0 ; V_25 < V_34 ; V_25 ++ ) {
const struct V_35 * V_36 = & V_21 -> V_37 [ V_25 ] ;
if ( ! V_36 -> V_38 || ( V_36 -> V_38 > V_23 ) )
break;
V_27 = F_1 ( V_22 , V_21 -> V_39 ,
& V_36 -> V_40 ) ;
V_27 = F_3 ( V_27 , V_21 -> V_41 ,
V_11 ) ;
V_27 = F_8 ( V_27 , V_28 , V_29 ) ;
V_26 = F_9 ( V_19 , V_36 -> V_38 , V_27 * 1000 ) ;
if ( V_26 )
return V_26 ;
}
return 0 ;
}
const struct V_20 *
F_10 ( struct V_18 * V_19 , const struct V_20 * V_42 ,
T_1 V_43 , int V_44 , int V_45 ,
int V_22 , unsigned long V_23 )
{
T_1 V_25 ;
int V_26 ;
for ( V_25 = 0 ; V_25 < V_43 ; V_25 ++ ) {
const struct V_20 * V_21 = & V_42 [ V_25 ] ;
if ( V_21 -> V_45 != - 1 && V_21 -> V_45 != V_45 )
continue;
if ( V_21 -> V_44 != - 1 && V_21 -> V_44 != V_44 )
continue;
V_26 = F_7 ( V_19 , V_21 , V_22 , V_23 ) ;
return V_26 ? F_11 ( V_26 ) : V_21 ;
}
return F_11 ( - V_46 ) ;
}
void F_12 ( struct V_18 * V_19 ,
const struct V_20 * V_21 ,
unsigned long V_23 )
{
unsigned int V_25 ;
for ( V_25 = 0 ; V_25 < V_34 ; V_25 ++ ) {
const struct V_35 * V_36 = & V_21 -> V_37 [ V_25 ] ;
if ( ! V_36 -> V_38 || ( V_36 -> V_38 > V_23 ) )
break;
F_13 ( V_19 , V_36 -> V_38 ) ;
}
}
