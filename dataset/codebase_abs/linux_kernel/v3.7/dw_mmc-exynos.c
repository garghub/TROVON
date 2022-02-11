static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_5 ;
V_4 = F_2 ( V_2 -> V_6 , sizeof( * V_4 ) , V_7 ) ;
if ( ! V_4 ) {
F_3 ( V_2 -> V_6 , L_1 ) ;
return - V_8 ;
}
for ( V_5 = 0 ; V_5 < F_4 ( V_9 ) ; V_5 ++ ) {
if ( F_5 ( V_2 -> V_6 -> V_10 ,
V_9 [ V_5 ] . V_11 ) )
V_4 -> V_12 = V_9 [ V_5 ] . V_12 ;
}
V_2 -> V_4 = V_4 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_4 -> V_12 == V_13 )
V_2 -> V_14 /= ( V_4 -> V_15 + 1 ) ;
else if ( V_4 -> V_12 == V_16 )
V_2 -> V_14 /= V_17 ;
else if ( V_4 -> V_12 == V_18 )
V_2 -> V_14 /= V_19 ;
return 0 ;
}
static void F_7 ( struct V_1 * V_2 , T_1 * V_20 )
{
if ( F_8 ( F_9 ( V_2 , V_21 ) ) )
* V_20 |= V_22 ;
}
static void F_10 ( struct V_1 * V_2 , struct V_23 * V_24 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_24 -> V_25 == V_26 )
F_11 ( V_2 , V_21 , V_4 -> V_27 ) ;
else
F_11 ( V_2 , V_21 , V_4 -> V_28 ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_29 * V_30 = V_2 -> V_6 -> V_10 ;
T_1 V_25 [ 2 ] ;
T_1 div = 0 ;
int V_31 ;
F_13 ( V_30 , L_2 , & div ) ;
V_4 -> V_15 = div ;
V_31 = F_14 ( V_30 ,
L_3 , V_25 , 2 ) ;
if ( V_31 )
return V_31 ;
V_4 -> V_28 = F_15 ( V_25 [ 0 ] , V_25 [ 1 ] , div ) ;
V_31 = F_14 ( V_30 ,
L_4 , V_25 , 2 ) ;
if ( V_31 )
return V_31 ;
V_4 -> V_27 = F_15 ( V_25 [ 0 ] , V_25 [ 1 ] , div ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_29 * V_32 , T_2 V_33 )
{
int V_5 , V_34 , V_31 ;
if ( ! V_32 )
return - V_35 ;
for ( V_5 = 0 ; V_5 < F_17 ( V_33 ) ; V_5 ++ ) {
V_34 = F_18 ( V_32 , V_5 ) ;
if ( ! F_19 ( V_34 ) ) {
F_3 ( V_2 -> V_6 , L_5 , V_34 ) ;
return - V_35 ;
}
V_31 = F_20 ( V_2 -> V_6 , V_34 , L_6 ) ;
if ( V_31 ) {
F_3 ( V_2 -> V_6 , L_7 , V_34 ) ;
return - V_36 ;
}
}
V_34 = F_21 ( V_32 , L_8 , 0 ) ;
if ( F_19 ( V_34 ) ) {
if ( F_20 ( V_2 -> V_6 , V_34 , L_9 ) )
F_22 ( V_2 -> V_6 , L_7 ,
V_34 ) ;
} else {
F_22 ( V_2 -> V_6 , L_10 ) ;
V_2 -> V_37 -> V_38 |= V_39 ;
}
if ( V_2 -> V_37 -> V_38 & V_40 )
return 0 ;
V_34 = F_21 ( V_32 , L_11 , 0 ) ;
if ( F_19 ( V_34 ) ) {
if ( F_20 ( V_2 -> V_6 , V_34 , L_12 ) )
F_3 ( V_2 -> V_6 , L_7 , V_34 ) ;
} else {
F_22 ( V_2 -> V_6 , L_13 ) ;
}
return 0 ;
}
int F_23 ( struct V_41 * V_42 )
{
const struct V_43 * V_44 ;
const struct V_45 * V_46 ;
V_46 = F_24 ( V_47 , V_42 -> V_6 . V_10 ) ;
V_44 = V_46 -> V_48 ;
return F_25 ( V_42 , V_44 ) ;
}
