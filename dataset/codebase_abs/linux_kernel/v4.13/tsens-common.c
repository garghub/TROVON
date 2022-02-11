char * F_1 ( struct V_1 * V_2 , const char * V_3 )
{
struct V_4 * V_5 ;
T_1 V_6 ;
char * V_7 ;
V_5 = F_2 ( V_2 , V_3 ) ;
if ( F_3 ( V_5 ) )
return F_4 ( V_5 ) ;
V_7 = F_5 ( V_5 , & V_6 ) ;
F_6 ( V_5 ) ;
return V_7 ;
}
void F_7 ( struct V_8 * V_9 , T_2 * V_10 ,
T_2 * V_11 , T_2 V_12 )
{
int V_13 ;
int V_14 , V_15 ;
for ( V_13 = 0 ; V_13 < V_9 -> V_16 ; V_13 ++ ) {
F_8 ( V_9 -> V_2 ,
L_1 ,
V_13 , V_10 [ V_13 ] , V_11 [ V_13 ] ) ;
V_9 -> V_17 [ V_13 ] . V_18 = V_19 ;
if ( V_12 == V_20 ) {
V_14 = V_11 [ V_13 ] - V_10 [ V_13 ] ;
V_14 *= V_21 ;
V_15 = V_22 - V_23 ;
V_9 -> V_17 [ V_13 ] . V_18 = V_14 / V_15 ;
}
V_9 -> V_17 [ V_13 ] . V_24 = ( V_10 [ V_13 ] * V_21 ) -
( V_23 *
V_9 -> V_17 [ V_13 ] . V_18 ) ;
F_8 ( V_9 -> V_2 , L_2 , V_9 -> V_17 [ V_13 ] . V_24 ) ;
}
}
static inline int F_9 ( T_2 V_25 , const struct V_26 * V_27 )
{
int V_28 , V_14 , V_15 ;
V_14 = ( V_25 * V_21 ) - V_27 -> V_24 ;
V_15 = V_27 -> V_18 ;
if ( V_14 > 0 )
V_28 = V_14 + ( V_15 / 2 ) ;
else if ( V_14 < 0 )
V_28 = V_14 - ( V_15 / 2 ) ;
else
V_28 = V_14 ;
V_28 /= V_15 ;
return V_28 ;
}
int F_10 ( struct V_8 * V_9 , int V_29 , int * V_30 )
{
struct V_26 * V_27 = & V_9 -> V_17 [ V_29 ] ;
T_2 V_31 ;
unsigned int V_32 ;
int V_33 = 0 , V_7 ;
V_32 = V_34 + V_27 -> V_35 * V_36 ;
V_7 = F_11 ( V_9 -> V_37 , V_32 , & V_31 ) ;
if ( V_7 )
return V_7 ;
V_33 = V_31 & V_38 ;
* V_30 = F_9 ( V_33 , V_27 ) * 1000 ;
return 0 ;
}
int T_3 F_12 ( struct V_8 * V_9 )
{
void T_4 * V_39 ;
V_39 = F_13 ( V_9 -> V_2 -> V_40 , 0 ) ;
if ( ! V_39 )
return - V_41 ;
V_9 -> V_37 = F_14 ( V_9 -> V_2 , V_39 , & V_42 ) ;
if ( F_3 ( V_9 -> V_37 ) ) {
F_15 ( V_39 ) ;
return F_16 ( V_9 -> V_37 ) ;
}
return 0 ;
}
