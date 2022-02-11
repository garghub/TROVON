static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
int V_7 ;
unsigned int V_8 ;
T_1 V_9 ;
if ( V_4 -> clock == 0 )
return;
if ( V_4 -> V_10 == V_11 &&
V_4 -> V_12 == V_13 )
V_8 = 2 * V_4 -> clock * V_14 ;
else
V_8 = V_4 -> clock * V_14 ;
V_7 = F_2 ( V_2 -> V_15 , V_8 ) ;
if ( V_7 )
F_3 ( V_2 -> V_16 , L_1 , V_4 -> clock ) ;
V_9 = F_4 ( V_2 -> V_15 ) / V_14 ;
if ( V_9 != V_2 -> V_9 ) {
V_2 -> V_9 = V_9 ;
V_2 -> V_17 = 0 ;
}
if ( ! F_5 ( V_6 -> V_18 ) )
F_6 ( V_6 -> V_18 , V_6 -> V_19 ) ;
if ( ! F_5 ( V_6 -> V_20 ) ) {
int V_21 ;
V_21 = 90 ;
switch ( V_4 -> V_12 ) {
case V_13 :
if ( V_4 -> V_10 == V_11 )
V_21 = 180 ;
break;
case V_22 :
case V_23 :
V_21 = 180 ;
break;
}
F_6 ( V_6 -> V_20 , V_21 ) ;
}
}
static int F_7 ( struct V_24 * V_25 , T_1 V_26 )
{
struct V_1 * V_2 = V_25 -> V_2 ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_27 * V_28 = V_25 -> V_28 ;
int V_7 = 0 ;
int V_29 ;
bool V_30 , V_31 = 0 , V_32 ;
struct V_33 {
int V_34 ;
int V_35 ;
};
struct V_33 * V_36 ;
unsigned int V_37 = 0 ;
int V_38 = - 1 ;
int V_39 = - 1 ;
int V_40 ;
if ( F_5 ( V_6 -> V_18 ) ) {
F_8 ( V_2 -> V_16 , L_2 ) ;
return - V_41 ;
}
V_36 = F_9 ( V_42 / 2 + 1 , sizeof( * V_36 ) , V_43 ) ;
if ( ! V_36 )
return - V_44 ;
for ( V_29 = 0 ; V_29 < V_42 ; ) {
F_6 ( V_6 -> V_18 , F_10 ( V_29 ) ) ;
V_30 = ! F_11 ( V_28 , V_26 , NULL ) ;
if ( V_29 == 0 )
V_32 = V_30 ;
if ( ( ! V_31 ) && V_30 ) {
V_37 ++ ;
V_36 [ V_37 - 1 ] . V_34 = V_29 ;
}
if ( V_30 ) {
V_36 [ V_37 - 1 ] . V_35 = V_29 ;
V_29 ++ ;
} else if ( V_29 == V_42 - 1 ) {
V_29 ++ ;
} else {
V_29 += F_12 ( 20 * V_42 , 360 ) ;
if ( V_29 >= V_42 )
V_29 = V_42 - 1 ;
}
V_31 = V_30 ;
}
if ( V_37 == 0 ) {
F_3 ( V_2 -> V_16 , L_3 ) ;
V_7 = - V_41 ;
goto free;
}
if ( ( V_37 > 1 ) && V_32 && V_30 ) {
V_36 [ 0 ] . V_34 = V_36 [ V_37 - 1 ] . V_34 ;
V_37 -- ;
}
if ( V_36 [ 0 ] . V_34 == 0 && V_36 [ 0 ] . V_35 == V_42 - 1 ) {
F_6 ( V_6 -> V_18 , V_6 -> V_19 ) ;
F_13 ( V_2 -> V_16 , L_4 ,
V_6 -> V_19 ) ;
goto free;
}
for ( V_29 = 0 ; V_29 < V_37 ; V_29 ++ ) {
int V_45 = ( V_36 [ V_29 ] . V_35 - V_36 [ V_29 ] . V_34 + 1 ) ;
if ( V_45 < 0 )
V_45 += V_42 ;
if ( V_38 < V_45 ) {
V_38 = V_45 ;
V_39 = V_29 ;
}
F_14 ( V_2 -> V_16 , L_5 ,
F_10 ( V_36 [ V_29 ] . V_34 ) ,
F_10 ( V_36 [ V_29 ] . V_35 ) ,
V_45
) ;
}
F_14 ( V_2 -> V_16 , L_6 ,
F_10 ( V_36 [ V_39 ] . V_34 ) ,
F_10 ( V_36 [ V_39 ] . V_35 ) ,
V_38
) ;
V_40 = V_36 [ V_39 ] . V_34 + V_38 / 2 ;
V_40 %= V_42 ;
F_13 ( V_2 -> V_16 , L_7 ,
F_10 ( V_40 ) ) ;
F_6 ( V_6 -> V_18 ,
F_10 ( V_40 ) ) ;
free:
F_15 ( V_36 ) ;
return V_7 ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_46 * V_47 = V_2 -> V_16 -> V_48 ;
struct V_5 * V_6 ;
V_6 = F_17 ( V_2 -> V_16 , sizeof( * V_6 ) , V_43 ) ;
if ( ! V_6 )
return - V_44 ;
if ( F_18 ( V_47 , L_8 ,
& V_6 -> V_19 ) )
V_6 -> V_19 = 0 ;
V_6 -> V_20 = F_19 ( V_2 -> V_16 , L_9 ) ;
if ( F_5 ( V_6 -> V_20 ) )
F_14 ( V_2 -> V_16 , L_10 ) ;
V_6 -> V_18 = F_19 ( V_2 -> V_16 , L_11 ) ;
if ( F_5 ( V_6 -> V_18 ) )
F_14 ( V_2 -> V_16 , L_12 ) ;
V_2 -> V_6 = V_6 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 )
{
V_2 -> V_49 = 8 ;
if ( F_21 ( V_2 -> V_16 -> V_48 ,
L_13 ) )
V_2 -> V_9 /= V_14 ;
return 0 ;
}
static int F_22 ( struct V_50 * V_51 )
{
const struct V_52 * V_53 ;
const struct V_54 * V_55 ;
if ( ! V_51 -> V_16 . V_48 )
return - V_56 ;
V_55 = F_23 ( V_57 , V_51 -> V_16 . V_48 ) ;
V_53 = V_55 -> V_58 ;
return F_24 ( V_51 , V_53 ) ;
}
