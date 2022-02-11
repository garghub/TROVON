static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_3 , V_2 -> V_4 + V_5 ) ;
F_2 ( V_6 , V_2 -> V_4 + V_7 ) ;
F_2 ( V_8 , V_2 -> V_4 + V_9 ) ;
F_2 ( V_10 , V_2 -> V_4 + V_11 ) ;
F_2 ( V_12 , V_2 -> V_4 + V_13 ) ;
F_2 ( V_14 , V_2 -> V_4 + V_15 ) ;
}
void F_3 ( struct V_1 * V_2 )
{
T_1 V_16 ;
if ( V_2 -> V_4 != NULL ) {
V_16 = F_4 ( V_2 -> V_4 + V_17 ) ;
V_16 |= V_18 ;
F_2 ( V_16 , V_2 -> V_4 + V_17 ) ;
if ( F_5 ( V_2 , V_19 ) )
F_1 ( V_2 ) ;
}
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = V_2 -> V_22 . V_23 ;
void T_2 * V_4 = V_2 -> V_4 ;
struct V_24 * V_25 = F_7 ( V_2 ) ;
const struct V_26 * V_27 ;
int V_28 , V_29 , V_30 , time ;
int V_31 = 10000 ;
T_1 V_32 , V_33 , V_16 ;
V_28 = F_8 ( & V_27 , V_25 -> V_34 , V_21 ) ;
if ( V_28 )
return V_28 ;
V_16 = F_4 ( V_4 + V_35 ) ;
V_16 |= V_36 ;
F_2 ( V_16 , V_4 + V_35 ) ;
for ( V_29 = 0 ; V_29 < V_27 -> V_37 ; V_29 += 4 ) {
for ( V_32 = 0 , V_30 = 3 ; V_30 >= 0 ; V_30 -- ) {
if ( ( V_30 + V_29 ) < V_27 -> V_37 )
V_32 |= V_27 -> V_32 [ V_29 + V_30 ] << ( 8 * V_30 ) ;
}
F_2 ( V_32 , V_4 + V_38 ) ;
V_16 = F_4 ( V_4 + V_35 ) ;
V_16 |= V_39 ;
F_2 ( V_16 , V_4 + V_35 ) ;
for ( time = 0 ; time < V_31 ; time ++ ) {
V_33 = F_4 ( V_4 + V_35 ) ;
if ( ( V_33 & V_39 ) == 0 )
break;
F_9 ( 1 ) ;
}
if ( time == V_31 ) {
V_28 = - V_40 ;
break;
}
}
V_16 = F_4 ( V_4 + V_35 ) ;
V_16 &= ~ V_36 ;
F_2 ( V_16 , V_4 + V_35 ) ;
for ( time = 0 ; time < V_31 ; time ++ ) {
V_33 = F_4 ( V_4 + V_35 ) ;
if ( V_33 & V_41 ) {
V_28 = 0 ;
break;
}
F_9 ( 1 ) ;
}
if ( time == V_31 )
V_28 = - V_40 ;
F_10 ( V_27 ) ;
return V_28 ;
}
int F_11 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_4 )
return 0 ;
return F_6 ( V_2 ) ;
}
