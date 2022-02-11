static int F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 /= V_4 ;
return 0 ;
}
static void F_2 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
int V_9 ;
unsigned int V_10 ;
T_1 V_3 ;
if ( V_6 -> clock == 0 )
return;
if ( V_6 -> V_11 == V_12 &&
V_6 -> V_13 == V_14 )
V_10 = 2 * V_6 -> clock * V_4 ;
else
V_10 = V_6 -> clock * V_4 ;
V_9 = F_3 ( V_2 -> V_15 , V_10 ) ;
if ( V_9 )
F_4 ( V_2 -> V_16 , L_1 , V_6 -> clock ) ;
V_3 = F_5 ( V_2 -> V_15 ) / V_4 ;
if ( V_3 != V_2 -> V_3 ) {
V_2 -> V_3 = V_3 ;
V_2 -> V_17 = 0 ;
}
if ( ! F_6 ( V_8 -> V_18 ) )
F_7 ( V_8 -> V_18 , V_8 -> V_19 ) ;
}
static int F_8 ( struct V_20 * V_21 , T_1 V_22 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_23 * V_24 = V_21 -> V_24 ;
int V_9 = 0 ;
int V_25 ;
bool V_26 , V_27 = 0 , V_28 ;
struct V_29 {
int V_30 ;
int V_31 ;
};
struct V_29 * V_32 ;
unsigned int V_33 = 0 ;
int V_34 = - 1 ;
int V_35 = - 1 ;
int V_36 ;
if ( F_6 ( V_8 -> V_18 ) ) {
F_9 ( V_2 -> V_16 , L_2 ) ;
return - V_37 ;
}
V_32 = F_10 ( V_38 / 2 + 1 , sizeof( * V_32 ) , V_39 ) ;
if ( ! V_32 )
return - V_40 ;
for ( V_25 = 0 ; V_25 < V_38 ; ) {
F_7 ( V_8 -> V_18 , F_11 ( V_25 ) ) ;
V_26 = ! F_12 ( V_24 , V_22 , NULL ) ;
if ( V_25 == 0 )
V_28 = V_26 ;
if ( ( ! V_27 ) && V_26 ) {
V_33 ++ ;
V_32 [ V_33 - 1 ] . V_30 = V_25 ;
}
if ( V_26 ) {
V_32 [ V_33 - 1 ] . V_31 = V_25 ;
V_25 ++ ;
} else if ( V_25 == V_38 - 1 ) {
V_25 ++ ;
} else {
V_25 += F_13 ( 20 * V_38 , 360 ) ;
if ( V_25 >= V_38 )
V_25 = V_38 - 1 ;
}
V_27 = V_26 ;
}
if ( V_33 == 0 ) {
F_4 ( V_2 -> V_16 , L_3 ) ;
V_9 = - V_37 ;
goto free;
}
if ( ( V_33 > 1 ) && V_28 && V_26 ) {
V_32 [ 0 ] . V_30 = V_32 [ V_33 - 1 ] . V_30 ;
V_33 -- ;
}
if ( V_32 [ 0 ] . V_30 == 0 && V_32 [ 0 ] . V_31 == V_38 - 1 ) {
F_7 ( V_8 -> V_18 , V_8 -> V_19 ) ;
F_14 ( V_2 -> V_16 , L_4 ,
V_8 -> V_19 ) ;
goto free;
}
for ( V_25 = 0 ; V_25 < V_33 ; V_25 ++ ) {
int V_41 = ( V_32 [ V_25 ] . V_31 - V_32 [ V_25 ] . V_30 + 1 ) ;
if ( V_41 < 0 )
V_41 += V_38 ;
if ( V_34 < V_41 ) {
V_34 = V_41 ;
V_35 = V_25 ;
}
F_15 ( V_2 -> V_16 , L_5 ,
F_11 ( V_32 [ V_25 ] . V_30 ) ,
F_11 ( V_32 [ V_25 ] . V_31 ) ,
V_41
) ;
}
F_15 ( V_2 -> V_16 , L_6 ,
F_11 ( V_32 [ V_35 ] . V_30 ) ,
F_11 ( V_32 [ V_35 ] . V_31 ) ,
V_34
) ;
V_36 = V_32 [ V_35 ] . V_30 + V_34 / 2 ;
V_36 %= V_38 ;
F_14 ( V_2 -> V_16 , L_7 ,
F_11 ( V_36 ) ) ;
F_7 ( V_8 -> V_18 ,
F_11 ( V_36 ) ) ;
free:
F_16 ( V_32 ) ;
return V_9 ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_42 * V_43 = V_2 -> V_16 -> V_44 ;
struct V_7 * V_8 ;
V_8 = F_18 ( V_2 -> V_16 , sizeof( * V_8 ) , V_39 ) ;
if ( ! V_8 )
return - V_40 ;
if ( F_19 ( V_43 , L_8 ,
& V_8 -> V_19 ) )
V_8 -> V_19 = 0 ;
V_8 -> V_45 = F_20 ( V_2 -> V_16 , L_9 ) ;
if ( F_6 ( V_8 -> V_45 ) )
F_15 ( V_2 -> V_16 , L_10 ) ;
V_8 -> V_18 = F_20 ( V_2 -> V_16 , L_11 ) ;
if ( F_6 ( V_8 -> V_18 ) )
F_15 ( V_2 -> V_16 , L_12 ) ;
V_2 -> V_8 = V_8 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 )
{
V_2 -> V_46 = 8 ;
V_2 -> V_47 -> V_48 |= V_49 ;
return 0 ;
}
static int F_22 ( struct V_50 * V_51 )
{
const struct V_52 * V_53 ;
const struct V_54 * V_55 ;
if ( ! V_51 -> V_16 . V_44 )
return - V_56 ;
V_55 = F_23 ( V_57 , V_51 -> V_16 . V_44 ) ;
V_53 = V_55 -> V_58 ;
return F_24 ( V_51 , V_53 ) ;
}
static int F_25 ( struct V_59 * V_16 )
{
struct V_1 * V_2 = F_26 ( V_16 ) ;
return F_27 ( V_2 ) ;
}
static int F_28 ( struct V_59 * V_16 )
{
struct V_1 * V_2 = F_26 ( V_16 ) ;
return F_29 ( V_2 ) ;
}
