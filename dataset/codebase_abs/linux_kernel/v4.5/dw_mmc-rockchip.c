static void F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
* V_3 |= V_4 ;
}
static int F_2 ( struct V_1 * V_2 )
{
V_2 -> V_5 /= V_6 ;
return 0 ;
}
static void F_3 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
struct V_9 * V_10 = V_2 -> V_10 ;
int V_11 ;
unsigned int V_12 ;
T_1 V_5 ;
if ( V_8 -> clock == 0 )
return;
if ( V_8 -> V_13 == V_14 &&
V_8 -> V_15 == V_16 )
V_12 = 2 * V_8 -> clock * V_6 ;
else
V_12 = V_8 -> clock * V_6 ;
V_11 = F_4 ( V_2 -> V_17 , V_12 ) ;
if ( V_11 )
F_5 ( V_2 -> V_18 , L_1 , V_8 -> clock ) ;
V_5 = F_6 ( V_2 -> V_17 ) / V_6 ;
if ( V_5 != V_2 -> V_5 ) {
V_2 -> V_5 = V_5 ;
V_2 -> V_19 = 0 ;
}
if ( ! F_7 ( V_10 -> V_20 ) )
F_8 ( V_10 -> V_20 , V_10 -> V_21 ) ;
}
static int F_9 ( struct V_22 * V_23 , T_1 V_24 )
{
struct V_1 * V_2 = V_23 -> V_2 ;
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_25 * V_26 = V_23 -> V_26 ;
int V_11 = 0 ;
int V_27 ;
bool V_28 , V_29 = 0 , V_30 ;
struct V_31 {
int V_32 ;
int V_33 ;
};
struct V_31 * V_34 ;
unsigned int V_35 = 0 ;
int V_36 = - 1 ;
int V_37 = - 1 ;
int V_38 ;
if ( F_7 ( V_10 -> V_20 ) ) {
F_10 ( V_2 -> V_18 , L_2 ) ;
return - V_39 ;
}
V_34 = F_11 ( V_40 / 2 + 1 , sizeof( * V_34 ) , V_41 ) ;
if ( ! V_34 )
return - V_42 ;
for ( V_27 = 0 ; V_27 < V_40 ; ) {
F_8 ( V_10 -> V_20 , F_12 ( V_27 ) ) ;
V_28 = ! F_13 ( V_26 , V_24 , NULL ) ;
if ( V_27 == 0 )
V_30 = V_28 ;
if ( ( ! V_29 ) && V_28 ) {
V_35 ++ ;
V_34 [ V_35 - 1 ] . V_32 = V_27 ;
}
if ( V_28 ) {
V_34 [ V_35 - 1 ] . V_33 = V_27 ;
V_27 ++ ;
} else if ( V_27 == V_40 - 1 ) {
V_27 ++ ;
} else {
V_27 += F_14 ( 20 * V_40 , 360 ) ;
if ( V_27 >= V_40 )
V_27 = V_40 - 1 ;
}
V_29 = V_28 ;
}
if ( V_35 == 0 ) {
F_5 ( V_2 -> V_18 , L_3 ) ;
V_11 = - V_39 ;
goto free;
}
if ( ( V_35 > 1 ) && V_30 && V_28 ) {
V_34 [ 0 ] . V_32 = V_34 [ V_35 - 1 ] . V_32 ;
V_35 -- ;
}
if ( V_34 [ 0 ] . V_32 == 0 && V_34 [ 0 ] . V_33 == V_40 - 1 ) {
F_8 ( V_10 -> V_20 , V_10 -> V_21 ) ;
F_15 ( V_2 -> V_18 , L_4 ,
V_10 -> V_21 ) ;
goto free;
}
for ( V_27 = 0 ; V_27 < V_35 ; V_27 ++ ) {
int V_43 = ( V_34 [ V_27 ] . V_33 - V_34 [ V_27 ] . V_32 + 1 ) ;
if ( V_43 < 0 )
V_43 += V_40 ;
if ( V_36 < V_43 ) {
V_36 = V_43 ;
V_37 = V_27 ;
}
F_16 ( V_2 -> V_18 , L_5 ,
F_12 ( V_34 [ V_27 ] . V_32 ) ,
F_12 ( V_34 [ V_27 ] . V_33 ) ,
V_43
) ;
}
F_16 ( V_2 -> V_18 , L_6 ,
F_12 ( V_34 [ V_37 ] . V_32 ) ,
F_12 ( V_34 [ V_37 ] . V_33 ) ,
V_36
) ;
V_38 = V_34 [ V_37 ] . V_32 + V_36 / 2 ;
V_38 %= V_40 ;
F_15 ( V_2 -> V_18 , L_7 ,
F_12 ( V_38 ) ) ;
F_8 ( V_10 -> V_20 ,
F_12 ( V_38 ) ) ;
free:
F_17 ( V_34 ) ;
return V_11 ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_44 * V_45 = V_2 -> V_18 -> V_46 ;
struct V_9 * V_10 ;
V_10 = F_19 ( V_2 -> V_18 , sizeof( * V_10 ) , V_41 ) ;
if ( ! V_10 )
return - V_42 ;
if ( F_20 ( V_45 , L_8 ,
& V_10 -> V_21 ) )
V_10 -> V_21 = 0 ;
V_10 -> V_47 = F_21 ( V_2 -> V_18 , L_9 ) ;
if ( F_7 ( V_10 -> V_47 ) )
F_16 ( V_2 -> V_18 , L_10 ) ;
V_10 -> V_20 = F_21 ( V_2 -> V_18 , L_11 ) ;
if ( F_7 ( V_10 -> V_20 ) )
F_16 ( V_2 -> V_18 , L_12 ) ;
V_2 -> V_10 = V_10 ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 )
{
V_2 -> V_48 = 8 ;
V_2 -> V_49 -> V_50 |= V_51 ;
return 0 ;
}
static int F_23 ( struct V_52 * V_53 )
{
const struct V_54 * V_55 ;
const struct V_56 * V_57 ;
if ( ! V_53 -> V_18 . V_46 )
return - V_58 ;
V_57 = F_24 ( V_59 , V_53 -> V_18 . V_46 ) ;
V_55 = V_57 -> V_60 ;
return F_25 ( V_53 , V_55 ) ;
}
static int F_26 ( struct V_61 * V_18 )
{
struct V_1 * V_2 = F_27 ( V_18 ) ;
return F_28 ( V_2 ) ;
}
static int F_29 ( struct V_61 * V_18 )
{
struct V_1 * V_2 = F_27 ( V_18 ) ;
return F_30 ( V_2 ) ;
}
