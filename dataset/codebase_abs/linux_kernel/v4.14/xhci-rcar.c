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
T_1 V_36 = 0 ;
const struct V_37 * V_38 ;
const char * V_39 ;
V_38 = F_10 ( V_40 ) ;
if ( V_38 )
V_36 = ( V_41 ) V_38 -> V_34 ;
if ( V_36 & V_42 )
V_39 = V_43 ;
else if ( V_36 & V_44 )
V_39 = V_45 ;
else
V_39 = V_27 -> V_39 ;
V_30 = F_11 ( & V_29 , V_39 , V_17 ) ;
if ( V_30 )
return V_30 ;
V_21 = F_7 ( V_4 + V_46 ) ;
V_21 |= V_47 ;
F_2 ( V_21 , V_4 + V_46 ) ;
for ( V_31 = 0 ; V_31 < V_29 -> V_48 ; V_31 += 4 ) {
for ( V_34 = 0 , V_32 = 3 ; V_32 >= 0 ; V_32 -- ) {
if ( ( V_32 + V_31 ) < V_29 -> V_48 )
V_34 |= V_29 -> V_34 [ V_31 + V_32 ] << ( 8 * V_32 ) ;
}
F_2 ( V_34 , V_4 + V_49 ) ;
V_21 = F_7 ( V_4 + V_46 ) ;
V_21 |= V_50 ;
F_2 ( V_21 , V_4 + V_46 ) ;
for ( time = 0 ; time < V_33 ; time ++ ) {
V_35 = F_7 ( V_4 + V_46 ) ;
if ( ( V_35 & V_50 ) == 0 )
break;
F_12 ( 1 ) ;
}
if ( time == V_33 ) {
V_30 = - V_51 ;
break;
}
}
V_21 = F_7 ( V_4 + V_46 ) ;
V_21 &= ~ V_47 ;
F_2 ( V_21 , V_4 + V_46 ) ;
for ( time = 0 ; time < V_33 ; time ++ ) {
V_35 = F_7 ( V_4 + V_46 ) ;
if ( V_35 & V_52 ) {
V_30 = 0 ;
break;
}
F_12 ( 1 ) ;
}
if ( time == V_33 )
V_30 = - V_51 ;
F_13 ( V_29 ) ;
return V_30 ;
}
int F_14 ( struct V_1 * V_2 )
{
struct V_53 * V_54 = F_15 ( V_2 ) ;
if ( ! V_2 -> V_4 )
return 0 ;
if ( F_3 ( V_2 -> V_24 . V_25 ) ||
F_5 ( V_2 -> V_24 . V_25 ) )
V_54 -> V_36 |= V_55 ;
return F_8 ( V_2 ) ;
}
int F_16 ( struct V_1 * V_2 )
{
int V_56 ;
V_56 = F_8 ( V_2 ) ;
if ( ! V_56 )
F_6 ( V_2 ) ;
return V_56 ;
}
