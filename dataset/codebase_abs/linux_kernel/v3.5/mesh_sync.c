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
F_4 ( L_1 ,
( long long ) V_11 -> V_21 ) ;
V_19 = - V_11 -> V_21 ;
V_11 -> V_21 = 0 ;
} else {
F_4 ( L_2 ,
( long long ) V_11 -> V_21 ,
( unsigned long long ) V_14 ) ;
V_19 = - V_14 ;
V_11 -> V_21 -= V_14 ;
}
V_18 = F_5 ( V_9 , V_7 ) ;
if ( V_18 != - 1ULL )
F_6 ( V_9 , V_7 , V_18 + V_19 ) ;
F_7 ( & V_11 -> V_20 ) ;
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
V_31 = F_5 ( V_9 , V_7 ) ;
F_10 () ;
V_29 = F_11 ( V_7 , V_24 -> V_35 ) ;
if ( ! V_29 )
goto V_36;
if ( V_25 -> V_3 && F_1 ( V_25 ) ) {
F_12 ( V_29 , V_37 ) ;
F_4 ( L_3 , V_29 -> V_29 . V_38 ) ;
goto V_36;
}
if ( V_27 -> V_39 & V_40 && V_27 -> V_41 ) {
int V_42 ;
if ( V_27 -> V_39 & V_43 ) {
goto V_36;
} else
V_42 = V_9 -> V_44 . V_45 -> V_46 [ V_27 -> V_47 ] ->
V_48 [ V_27 -> V_49 ] . V_50 ;
V_31 = V_27 -> V_41 + ( 24 * 8 * 10 / V_42 ) ;
}
V_30 = F_13 ( V_24 -> V_12 . V_51 . V_52 ) ;
V_29 -> V_53 = V_30 - V_31 ;
if ( F_14 ( V_29 , V_37 ) ) {
T_3 V_54 = V_29 -> V_55
- V_29 -> V_53 ;
F_4 ( L_4 ,
V_29 -> V_29 . V_38 ,
( long long ) V_29 -> V_53 ,
( long long )
V_29 -> V_55 ,
( long long ) V_54 ) ;
if ( V_54 > V_56 ||
V_54 < - V_56 ) {
F_4 ( L_5 ,
V_29 -> V_29 . V_38 ,
( long long ) V_54 ) ;
F_12 ( V_29 , V_37 ) ;
goto V_36;
}
F_15 () ;
F_3 ( & V_11 -> V_20 ) ;
if ( V_54 >
V_11 -> V_21 )
V_11 -> V_21
= V_54 ;
F_7 ( & V_11 -> V_20 ) ;
} else {
V_29 -> V_55 = V_29 -> V_53 - V_57 ;
F_16 ( V_29 , V_37 ) ;
F_4 ( L_6
L_7 ,
V_29 -> V_29 . V_38 ,
( long long ) V_29 -> V_53 ) ;
F_15 () ;
}
return;
V_36:
F_15 () ;
}
static void F_17 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = & V_7 -> V_12 . V_13 ;
F_9 ( V_11 -> V_32
!= V_33 ) ;
F_18 ( ! F_19 () ) ;
F_3 ( & V_11 -> V_20 ) ;
if ( V_11 -> V_21 >
V_58 ) {
F_4 ( L_8
L_9
L_10 ,
V_11 -> V_21 ) ;
F_20 ( V_59 ,
& V_11 -> V_60 ) ;
} else {
F_4 ( L_11
L_12 ,
( long long )
V_11 -> V_21 ) ;
V_11 -> V_21 = 0 ;
}
F_7 ( & V_11 -> V_20 ) ;
}
static const T_4 * F_21 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = & V_7 -> V_12 . V_13 ;
T_4 V_61 ;
if ( ! V_11 -> V_2 || ! V_11 -> V_62 )
return NULL ;
V_61 = F_22 ( V_11 -> V_2 ,
V_11 -> V_62 , 0 ) ;
if ( ! V_61 )
return NULL ;
return V_11 -> V_2 + V_61 + 2 ;
}
static void F_23 ( struct V_6 * V_7 ,
T_2 V_22 ,
struct V_23 * V_24 ,
struct V_1 * V_25 ,
struct V_26 * V_27 )
{
const T_4 * V_63 ;
F_9 ( V_7 -> V_12 . V_13 . V_32 != V_64 ) ;
F_4 ( L_13 ) ;
V_63 = F_21 ( V_7 ) ;
}
static void F_24 ( struct V_6 * V_7 )
{
const T_4 * V_63 ;
F_9 ( V_7 -> V_12 . V_13 . V_32 != V_64 ) ;
F_4 ( L_14 ) ;
V_63 = F_21 ( V_7 ) ;
}
struct V_65 * F_25 ( T_4 V_66 )
{
struct V_65 * V_67 = NULL ;
T_4 V_68 ;
for ( V_68 = 0 ; V_68 < F_26 ( V_69 ) ; ++ V_68 ) {
if ( V_69 [ V_68 ] . V_66 == V_66 ) {
V_67 = & V_69 [ V_68 ] . V_67 ;
break;
}
}
return V_67 ;
}
