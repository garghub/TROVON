static void F_1 ( struct V_1 * V_2 , int V_3 ,
struct V_4 * V_5 )
{
F_2 ( V_2 -> V_6 , F_3 ( 0 , V_3 , 1 ) ,
V_5 -> V_7 ) ;
F_2 ( V_2 -> V_6 , F_3 ( 0 , V_3 , 0 ) , V_5 -> V_8 ) ;
}
static void F_4 ( struct V_1 * V_2 , int V_3 ,
struct V_4 * V_5 )
{
V_5 -> V_7 = 0ull ;
V_5 -> V_8 = V_9 ;
F_1 ( V_2 , V_3 , V_5 ) ;
}
static void F_5 ( struct V_1 * V_2 , T_1 V_3 )
{
F_2 ( V_2 -> V_6 , F_6 ( 0 , 0 ) , ( 1 << V_3 ) ) ;
}
static void F_7 ( struct V_1 * V_2 , int V_3 , T_1 V_10 )
{
union V_11 V_12 ;
V_12 . V_13 = F_8 ( V_2 -> V_6 , F_9 ( 0 , V_3 ) ) ;
V_12 . V_14 . V_10 = V_10 ;
V_12 . V_14 . V_15 = true ;
F_2 ( V_2 -> V_6 , F_9 ( 0 , V_3 ) , V_12 . V_13 ) ;
}
static void F_10 ( struct V_1 * V_2 , int V_3 , T_1 V_16 )
{
union V_11 V_12 ;
V_12 . V_13 = F_8 ( V_2 -> V_6 , F_9 ( 0 , V_3 ) ) ;
V_12 . V_14 . V_16 = V_16 ;
F_2 ( V_2 -> V_6 , F_9 ( 0 , V_3 ) , V_12 . V_13 ) ;
}
static int F_11 ( struct V_1 * V_2 , T_2 V_17 , T_2 V_18 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
union V_11 V_12 ;
struct V_21 * V_22 = & V_2 -> V_23 -> V_22 ;
if ( V_17 >= V_24 ) {
F_12 ( V_22 , L_1 ) ;
return - V_25 ;
}
if ( V_18 >= V_26 ) {
F_12 ( V_22 , L_2 ) ;
return - V_25 ;
}
if ( V_18 >= V_2 -> V_27 ) {
F_12 ( V_22 , L_3 ) ;
return - V_25 ;
}
V_12 . V_13 = F_8 ( V_2 -> V_6 , F_9 ( 0 , V_17 ) ) ;
V_12 . V_14 . V_18 = V_20 [ V_18 ] . V_28 ;
F_2 ( V_2 -> V_6 , F_9 ( 0 , V_17 ) , V_12 . V_13 ) ;
F_13 ( V_22 , L_4 , V_17 , ( V_20 [ V_18 ] . V_29 ? L_5 : L_6 ) ) ;
return V_20 [ V_18 ] . V_29 ? V_30 : V_31 ;
}
static void F_14 ( struct V_1 * V_2 , int V_3 )
{
struct V_32 * V_33 = & V_2 -> V_34 [ V_3 ] ;
struct V_4 V_5 = {} ;
int V_35 ;
struct V_21 * V_22 = & V_2 -> V_23 -> V_22 ;
V_5 . V_8 = F_8 ( V_2 -> V_6 , F_3 ( 0 , V_3 , 0 ) ) ;
V_5 . V_7 = F_8 ( V_2 -> V_6 , F_3 ( 0 , V_3 , 1 ) ) ;
F_13 ( V_22 , L_7 , V_36 , V_5 . V_8 , V_3 ) ;
switch ( V_5 . V_8 ) {
case V_37 :
V_33 -> V_38 = V_39 ;
F_15 ( V_40 ) ;
F_4 ( V_2 , V_3 , & V_5 ) ;
break;
case V_41 :
V_5 . V_8 = V_41 ;
V_5 . V_7 = V_3 ;
F_1 ( V_2 , V_3 , & V_5 ) ;
break;
case V_42 :
V_33 -> V_38 = V_43 ;
F_16 ( V_40 ) ;
F_4 ( V_2 , V_3 , & V_5 ) ;
break;
case V_44 :
V_33 -> V_45 = V_5 . V_7 ;
F_7 ( V_2 , V_3 , V_33 -> V_45 ) ;
F_4 ( V_2 , V_3 , & V_5 ) ;
break;
case V_46 :
V_35 = F_11 ( V_2 , V_3 , ( T_2 ) V_5 . V_7 ) ;
if ( ( V_35 != V_30 ) && ( V_35 != V_31 ) )
F_12 ( V_22 , L_8 ,
V_3 , V_5 . V_7 ) ;
else {
F_13 ( V_22 , L_9 ,
V_3 , V_5 . V_7 ) ;
V_5 . V_8 = V_46 ;
V_5 . V_7 = V_35 ;
F_1 ( V_2 , V_3 , & V_5 ) ;
}
break;
case V_47 :
V_33 -> V_48 = V_5 . V_7 ;
F_10 ( V_2 , V_3 , V_33 -> V_48 ) ;
F_4 ( V_2 , V_3 , & V_5 ) ;
break;
default:
F_12 ( & V_2 -> V_23 -> V_22 , L_10 ,
V_3 , V_5 . V_8 ) ;
break;
}
}
void F_17 ( struct V_1 * V_2 , int V_5 )
{
T_3 V_49 ;
T_2 V_3 ;
V_49 = F_8 ( V_2 -> V_6 , F_6 ( 0 , 0 ) ) ;
F_13 ( & V_2 -> V_23 -> V_22 , L_11 , V_5 , V_49 ) ;
for ( V_3 = 0 ; V_3 < V_24 ; V_3 ++ ) {
if ( V_49 & ( 1ULL << V_3 ) ) {
F_13 ( & V_2 -> V_23 -> V_22 , L_12 , V_3 ) ;
F_14 ( V_2 , V_3 ) ;
F_5 ( V_2 , V_3 ) ;
}
}
}
