void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
if ( V_2 -> V_4 != NULL ) {
V_3 = F_2 ( V_2 -> V_4 + V_5 ) ;
V_3 |= V_6 ;
F_3 ( V_3 , V_2 -> V_4 + V_5 ) ;
F_3 ( V_7 , V_2 -> V_4 + V_8 ) ;
F_3 ( V_9 , V_2 -> V_4 + V_10 ) ;
F_3 ( V_11 , V_2 -> V_4 + V_12 ) ;
F_3 ( V_13 , V_2 -> V_4 + V_14 ) ;
F_3 ( V_15 , V_2 -> V_4 + V_16 ) ;
F_3 ( V_17 , V_2 -> V_4 + V_18 ) ;
}
}
static int F_4 ( struct V_19 * V_20 , void T_2 * V_4 )
{
const struct V_21 * V_22 ;
int V_23 , V_24 , V_25 , time ;
int V_26 = 10000 ;
T_1 V_27 , V_28 , V_3 ;
V_23 = F_5 ( & V_22 , V_29 , V_20 ) ;
if ( V_23 )
return V_23 ;
V_3 = F_2 ( V_4 + V_30 ) ;
V_3 |= V_31 ;
F_3 ( V_3 , V_4 + V_30 ) ;
for ( V_24 = 0 ; V_24 < V_22 -> V_32 ; V_24 += 4 ) {
for ( V_27 = 0 , V_25 = 3 ; V_25 >= 0 ; V_25 -- ) {
if ( ( V_25 + V_24 ) < V_22 -> V_32 )
V_27 |= V_22 -> V_27 [ V_24 + V_25 ] << ( 8 * V_25 ) ;
}
F_3 ( V_27 , V_4 + V_33 ) ;
V_3 = F_2 ( V_4 + V_30 ) ;
V_3 |= V_34 ;
F_3 ( V_3 , V_4 + V_30 ) ;
for ( time = 0 ; time < V_26 ; time ++ ) {
V_28 = F_2 ( V_4 + V_30 ) ;
if ( ( V_28 & V_34 ) == 0 )
break;
F_6 ( 1 ) ;
}
if ( time == V_26 ) {
V_23 = - V_35 ;
break;
}
}
V_3 = F_2 ( V_4 + V_30 ) ;
V_3 &= ~ V_31 ;
F_3 ( V_3 , V_4 + V_30 ) ;
for ( time = 0 ; time < V_26 ; time ++ ) {
V_28 = F_2 ( V_4 + V_30 ) ;
if ( V_28 & V_36 ) {
V_23 = 0 ;
break;
}
F_6 ( 1 ) ;
}
if ( time == V_26 )
V_23 = - V_35 ;
F_7 ( V_22 ) ;
return V_23 ;
}
int F_8 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_4 )
return 0 ;
return F_4 ( V_2 -> V_37 . V_38 , V_2 -> V_4 ) ;
}
