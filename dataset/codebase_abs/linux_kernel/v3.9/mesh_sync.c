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
V_18 = F_6 ( V_9 , V_7 ) ;
if ( V_18 != - 1ULL )
F_7 ( V_9 , V_7 , V_18 + V_19 ) ;
}
static void F_8 ( struct V_6 * V_7 ,
T_2 V_22 ,
struct V_23 * V_24 ,
struct V_1 * V_25 ,
struct V_26 * V_27 )
{
struct V_10 * V_11 = & V_7 -> V_12 . V_13 ;
struct V_8 * V_9 = V_7 -> V_9 ;
struct V_28 * V_29 ;
T_1 V_30 , V_31 ;
F_9 ( V_11 -> V_32 != V_33 ) ;
if ( V_22 != V_34 )
return;
V_31 = F_6 ( V_9 , V_7 ) ;
F_10 () ;
V_29 = F_11 ( V_7 , V_24 -> V_35 ) ;
if ( ! V_29 )
goto V_36;
if ( V_25 -> V_3 && F_1 ( V_25 ) ) {
F_12 ( V_29 , V_37 ) ;
F_4 ( V_7 , L_3 ,
V_29 -> V_29 . V_38 ) ;
goto V_36;
}
if ( F_13 ( V_27 ) )
V_31 = F_14 ( V_9 , V_27 ,
24 + 12 +
V_25 -> V_39 +
V_40 ,
24 ) ;
V_30 = F_15 ( V_24 -> V_12 . V_41 . V_42 ) ;
V_29 -> V_43 = V_30 - V_31 ;
if ( F_16 ( V_29 , V_37 ) ) {
T_3 V_44 = V_29 -> V_45 - V_29 -> V_43 ;
F_4 ( V_7 ,
L_4 ,
V_29 -> V_29 . V_38 , ( long long ) V_29 -> V_43 ,
( long long ) V_29 -> V_45 ,
( long long ) V_44 ) ;
if ( V_44 > V_46 ||
V_44 < - V_46 ) {
F_4 ( V_7 ,
L_5 ,
V_29 -> V_29 . V_38 ,
( long long ) V_44 ) ;
F_12 ( V_29 , V_37 ) ;
goto V_36;
}
F_3 ( & V_11 -> V_20 ) ;
if ( V_44 > V_11 -> V_21 )
V_11 -> V_21 = V_44 ;
F_5 ( & V_11 -> V_20 ) ;
} else {
V_29 -> V_45 = V_29 -> V_43 - V_47 ;
F_17 ( V_29 , V_37 ) ;
F_4 ( V_7 ,
L_6 ,
V_29 -> V_29 . V_38 ,
( long long ) V_29 -> V_43 ) ;
}
V_36:
F_18 () ;
}
static void F_19 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = & V_7 -> V_12 . V_13 ;
F_9 ( V_11 -> V_32 != V_33 ) ;
F_20 ( ! F_21 () ) ;
F_3 ( & V_11 -> V_20 ) ;
if ( V_11 -> V_21 > V_48 ) {
F_4 ( V_7 ,
L_7 ,
V_11 -> V_21 ) ;
F_22 ( V_49 , & V_11 -> V_50 ) ;
V_11 -> V_51 = true ;
} else {
F_4 ( V_7 ,
L_8 ,
( long long ) V_11 -> V_21 ) ;
V_11 -> V_21 = 0 ;
V_11 -> V_51 = false ;
}
F_5 ( & V_11 -> V_20 ) ;
}
const struct V_52 * F_23 ( T_4 V_53 )
{
int V_54 ;
for ( V_54 = 0 ; V_54 < F_24 ( V_55 ) ; ++ V_54 ) {
if ( V_55 [ V_54 ] . V_53 == V_53 )
return & V_55 [ V_54 ] . V_56 ;
}
return NULL ;
}
