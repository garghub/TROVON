static bool F_1 ( struct V_1 * V_2 )
{
return ( V_2 -> V_3 -> V_4 &
V_5 ) != 0 ;
}
void F_2 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_9 ;
struct V_10 * V_11 = & V_7 -> V_12 . V_13 ;
T_1 V_14 = V_7 -> V_15 . V_16 . V_17 * 1024 / 2500 ;
T_1 V_18 ;
T_1 V_19 ;
F_3 ( & V_11 -> V_20 ) ;
if ( V_11 -> V_21 < V_14 ) {
F_4 ( V_7 , L_1 ,
( long long ) V_11 -> V_21 ) ;
V_19 = - V_11 -> V_21 ;
V_11 -> V_21 = 0 ;
} else {
F_4 ( V_7 , L_2 ,
( long long ) V_11 -> V_21 ,
( unsigned long long ) V_14 ) ;
V_19 = - V_14 ;
V_11 -> V_21 -= V_14 ;
}
F_5 ( & V_11 -> V_20 ) ;
if ( V_9 -> V_22 -> V_23 ) {
F_6 ( V_9 , V_7 , V_19 ) ;
} else {
V_18 = F_7 ( V_9 , V_7 ) ;
if ( V_18 != - 1ULL )
F_8 ( V_9 , V_7 , V_18 + V_19 ) ;
}
}
static void F_9 ( struct V_6 * V_7 ,
T_2 V_24 ,
struct V_25 * V_26 ,
struct V_1 * V_27 ,
struct V_28 * V_29 )
{
struct V_10 * V_11 = & V_7 -> V_12 . V_13 ;
struct V_8 * V_9 = V_7 -> V_9 ;
struct V_30 * V_31 ;
T_1 V_32 , V_33 ;
F_10 ( V_11 -> V_34 != V_35 ) ;
if ( V_24 != V_36 )
return;
if ( F_11 ( V_29 ) )
V_33 = F_12 ( V_9 , V_29 ,
24 + 12 +
V_27 -> V_37 +
V_38 ,
24 ) ;
else
V_33 = F_7 ( V_9 , V_7 ) ;
F_13 () ;
V_31 = F_14 ( V_7 , V_26 -> V_39 ) ;
if ( ! V_31 )
goto V_40;
if ( V_27 -> V_3 && F_1 ( V_27 ) ) {
F_15 ( V_31 , V_41 ) ;
F_4 ( V_7 , L_3 ,
V_31 -> V_31 . V_42 ) ;
goto V_40;
}
V_32 = F_16 ( V_26 -> V_12 . V_43 . V_44 ) ;
V_31 -> V_13 -> V_45 = V_32 - V_33 ;
if ( F_17 ( V_31 , V_41 ) ) {
T_3 V_46 = V_31 -> V_13 -> V_47 - V_31 -> V_13 -> V_45 ;
F_4 ( V_7 ,
L_4 ,
V_31 -> V_31 . V_42 , ( long long ) V_31 -> V_13 -> V_45 ,
( long long ) V_31 -> V_13 -> V_47 ,
( long long ) V_46 ) ;
if ( V_46 > V_48 ||
V_46 < - V_48 ) {
F_4 ( V_7 ,
L_5 ,
V_31 -> V_31 . V_42 ,
( long long ) V_46 ) ;
F_15 ( V_31 , V_41 ) ;
goto V_40;
}
F_3 ( & V_11 -> V_20 ) ;
if ( V_46 > V_11 -> V_21 )
V_11 -> V_21 = V_46 ;
F_5 ( & V_11 -> V_20 ) ;
} else {
V_31 -> V_13 -> V_47 = V_31 -> V_13 -> V_45 - V_49 ;
F_18 ( V_31 , V_41 ) ;
F_4 ( V_7 ,
L_6 ,
V_31 -> V_31 . V_42 ,
( long long ) V_31 -> V_13 -> V_45 ) ;
}
V_40:
F_19 () ;
}
static void F_20 ( struct V_6 * V_7 ,
struct V_50 * V_43 )
{
struct V_10 * V_11 = & V_7 -> V_12 . V_13 ;
T_4 V_51 ;
F_10 ( V_11 -> V_34 != V_35 ) ;
F_10 ( ! F_21 () ) ;
V_51 = V_43 -> V_52 -> V_4 ;
F_3 ( & V_11 -> V_20 ) ;
if ( V_11 -> V_21 > V_53 ) {
F_4 ( V_7 ,
L_7 ,
V_11 -> V_21 ) ;
F_22 ( V_54 , & V_11 -> V_55 ) ;
V_11 -> V_56 = true ;
} else {
F_4 ( V_7 ,
L_8 ,
( long long ) V_11 -> V_21 ) ;
V_11 -> V_21 = 0 ;
V_11 -> V_56 = false ;
}
F_5 ( & V_11 -> V_20 ) ;
V_43 -> V_52 -> V_4 = V_11 -> V_56 ?
V_5 | V_51 :
~ V_5 & V_51 ;
}
const struct V_57 * F_23 ( T_4 V_58 )
{
int V_59 ;
for ( V_59 = 0 ; V_59 < F_24 ( V_60 ) ; ++ V_59 ) {
if ( V_60 [ V_59 ] . V_58 == V_58 )
return & V_60 [ V_59 ] . V_22 ;
}
return NULL ;
}
