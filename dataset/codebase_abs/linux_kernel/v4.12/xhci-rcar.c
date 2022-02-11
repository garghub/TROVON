static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_3 , V_2 -> V_4 + V_5 ) ;
F_2 ( V_6 , V_2 -> V_4 + V_7 ) ;
F_2 ( V_8 , V_2 -> V_4 + V_9 ) ;
F_2 ( V_10 , V_2 -> V_4 + V_11 ) ;
F_2 ( V_12 , V_2 -> V_4 + V_13 ) ;
F_2 ( V_14 , V_2 -> V_4 + V_15 ) ;
}
static int F_3 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = V_17 -> V_20 ;
return F_4 ( V_19 , L_1 ) ||
F_4 ( V_19 , L_2 ) ||
F_4 ( V_19 , L_3 ) ||
F_4 ( V_19 , L_4 ) ;
}
static int F_5 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = V_17 -> V_20 ;
return F_4 ( V_19 , L_5 ) ||
F_4 ( V_19 , L_6 ) ||
F_4 ( V_19 , L_7 ) ;
}
void F_6 ( struct V_1 * V_2 )
{
T_1 V_21 ;
if ( V_2 -> V_4 != NULL ) {
V_21 = F_7 ( V_2 -> V_4 + V_22 ) ;
V_21 |= V_23 ;
F_2 ( V_21 , V_2 -> V_4 + V_22 ) ;
if ( F_3 ( V_2 -> V_24 . V_25 ) )
F_1 ( V_2 ) ;
}
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = V_2 -> V_24 . V_25 ;
void T_2 * V_4 = V_2 -> V_4 ;
struct V_26 * V_27 = F_9 ( V_2 ) ;
const struct V_28 * V_29 ;
int V_30 , V_31 , V_32 , time ;
int V_33 = 10000 ;
T_1 V_34 , V_35 , V_21 ;
V_30 = F_10 ( & V_29 , V_27 -> V_36 , V_17 ) ;
if ( V_30 )
return V_30 ;
V_21 = F_7 ( V_4 + V_37 ) ;
V_21 |= V_38 ;
F_2 ( V_21 , V_4 + V_37 ) ;
for ( V_31 = 0 ; V_31 < V_29 -> V_39 ; V_31 += 4 ) {
for ( V_34 = 0 , V_32 = 3 ; V_32 >= 0 ; V_32 -- ) {
if ( ( V_32 + V_31 ) < V_29 -> V_39 )
V_34 |= V_29 -> V_34 [ V_31 + V_32 ] << ( 8 * V_32 ) ;
}
F_2 ( V_34 , V_4 + V_40 ) ;
V_21 = F_7 ( V_4 + V_37 ) ;
V_21 |= V_41 ;
F_2 ( V_21 , V_4 + V_37 ) ;
for ( time = 0 ; time < V_33 ; time ++ ) {
V_35 = F_7 ( V_4 + V_37 ) ;
if ( ( V_35 & V_41 ) == 0 )
break;
F_11 ( 1 ) ;
}
if ( time == V_33 ) {
V_30 = - V_42 ;
break;
}
}
V_21 = F_7 ( V_4 + V_37 ) ;
V_21 &= ~ V_38 ;
F_2 ( V_21 , V_4 + V_37 ) ;
for ( time = 0 ; time < V_33 ; time ++ ) {
V_35 = F_7 ( V_4 + V_37 ) ;
if ( V_35 & V_43 ) {
V_30 = 0 ;
break;
}
F_11 ( 1 ) ;
}
if ( time == V_33 )
V_30 = - V_42 ;
F_12 ( V_29 ) ;
return V_30 ;
}
int F_13 ( struct V_1 * V_2 )
{
struct V_44 * V_45 = F_14 ( V_2 ) ;
if ( ! V_2 -> V_4 )
return 0 ;
if ( F_3 ( V_2 -> V_24 . V_25 ) ||
F_5 ( V_2 -> V_24 . V_25 ) )
V_45 -> V_46 |= V_47 ;
return F_8 ( V_2 ) ;
}
int F_15 ( struct V_1 * V_2 )
{
int V_48 ;
V_48 = F_8 ( V_2 ) ;
if ( ! V_48 )
F_6 ( V_2 ) ;
return V_48 ;
}
