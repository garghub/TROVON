static void F_1 ( struct V_1 * V_2 )
{
* ( V_2 -> V_3 + ( V_2 -> V_4 >> 2 ) ) = F_2 ( 0 ) ;
}
static void F_3 ( struct V_5 * V_6 , T_1 V_7 ,
T_1 V_8 , T_1 V_9 , T_1 V_10 )
{
struct V_11 * V_11 = F_4 ( V_6 ) ;
struct V_1 * V_2 = & V_6 -> V_1 ;
T_1 V_12 ;
for ( V_12 = 0 ; V_12 < V_8 ; V_12 ++ )
F_5 ( V_6 -> V_13 . V_14 ) ;
F_6 ( V_6 -> V_13 . V_14 ) ;
while ( V_10 -- ) {
T_1 * V_15 = ( T_1 * ) ( ( T_1 ) V_2 -> V_3 + V_7 ) ;
* ( V_15 ++ ) = V_16 ;
* ( V_15 ++ ) = V_16 ;
F_7 ( V_11 -> V_17 , L_1 , V_18 ,
V_2 -> V_19 + V_7 ) ;
V_7 = ( V_7 + 8 ) & ( V_2 -> V_4 - 1 ) ;
}
F_8 () ;
}
static void F_9 ( struct V_5 * V_6 )
{
struct V_20 * V_21 = F_10 ( V_6 ) ;
if ( V_6 -> V_22 )
return;
V_6 -> V_23 = V_6 -> V_1 . V_24 ;
F_11 ( V_21 , V_25 ,
V_26 ) ;
F_11 ( V_21 , V_6 -> V_1 . V_19 , V_27 ) ;
F_11 ( V_21 , V_6 -> V_1 . V_24 , V_28 ) ;
F_11 ( V_21 , V_6 -> V_1 . V_19 +
V_6 -> V_1 . V_4 + 4 ,
V_29 ) ;
F_11 ( V_21 , V_25 |
V_30 |
V_31 ,
V_26 ) ;
F_11 ( V_21 , 0 , V_26 ) ;
V_6 -> V_22 = true ;
}
static void F_12 ( struct V_5 * V_6 , T_1 V_7 )
{
struct V_11 * V_11 = F_4 ( V_6 ) ;
struct V_20 * V_21 = F_10 ( V_6 ) ;
if ( V_6 -> V_22 )
return;
V_6 -> V_23 = V_6 -> V_1 . V_24 ;
F_11 ( V_21 , V_25 ,
V_26 ) ;
F_11 ( V_21 , V_6 -> V_1 . V_19 , V_27 ) ;
F_11 ( V_21 , V_6 -> V_1 . V_19 +
V_6 -> V_1 . V_4 ,
V_29 ) ;
F_11 ( V_21 , V_7 , V_28 ) ;
F_11 ( V_21 , V_25 |
V_30 |
V_31 ,
V_26 ) ;
F_7 ( V_11 -> V_17 ,
L_2 , V_18 ,
F_13 ( V_21 , V_32 ) ,
F_13 ( V_21 , V_28 ) ,
V_6 -> V_23 ) ;
F_11 ( V_21 , V_25 ,
V_26 ) ;
F_11 ( V_21 , V_6 -> V_1 . V_24 , V_28 ) ;
F_11 ( V_21 , 0 , V_26 ) ;
V_6 -> V_22 = true ;
}
static void F_14 ( struct V_5 * V_6 )
{
struct V_20 * V_21 = F_10 ( V_6 ) ;
if ( V_6 -> V_1 . V_24 != V_6 -> V_23 ) {
F_11 ( V_21 , V_6 -> V_1 . V_24 ,
V_28 ) ;
V_6 -> V_23 = V_6 -> V_1 . V_24 ;
}
}
static void F_15 ( struct V_5 * V_6 )
{
struct V_20 * V_21 = F_10 ( V_6 ) ;
F_16 ( & V_6 -> V_33 ) ;
if ( V_6 -> V_22 ) {
F_17 ( V_6 , V_34 ) ;
F_11 ( V_21 , V_25 ,
V_26 ) ;
V_6 -> V_22 = false ;
}
F_18 ( & V_6 -> V_33 ) ;
}
static void F_19 ( struct V_5 * V_6 )
{
struct V_11 * V_35 = F_4 ( V_6 ) ;
struct V_20 * V_21 = F_10 ( V_6 ) ;
T_1 V_36 ;
if ( V_6 -> V_37 && ! V_6 -> V_22 ) {
F_20 ( V_35 -> V_17 , L_3 ) ;
return;
}
F_7 ( V_35 -> V_17 , L_4 , V_21 -> V_38 ) ;
V_36 = F_21 ( V_35 , V_39 ) ;
V_36 |= F_22 ( V_21 -> V_38 ) ;
F_23 ( V_35 , V_36 , V_39 ) ;
F_7 ( V_35 -> V_17 , L_2 ,
V_18 , F_13 ( V_21 , V_32 ) ,
F_13 ( V_21 , V_28 ) ,
V_6 -> V_23 ) ;
F_11 ( V_21 , V_25 ,
V_26 ) ;
F_23 ( V_35 , F_22 ( V_21 -> V_38 ) , V_40 ) ;
V_6 -> V_22 = false ;
V_6 -> V_37 = true ;
}
static void F_24 ( struct V_5 * V_6 , T_1 V_7 )
{
struct V_11 * V_11 = F_4 ( V_6 ) ;
struct V_20 * V_21 = F_10 ( V_6 ) ;
T_1 V_36 ;
F_7 ( V_11 -> V_17 ,
L_5 ,
V_21 -> V_38 , V_7 ) ;
V_36 = F_21 ( V_11 , V_39 ) ;
V_36 &= ~ ( F_22 ( V_21 -> V_38 ) ) ;
F_23 ( V_11 , V_36 , V_39 ) ;
V_6 -> V_37 = false ;
F_12 ( V_6 , V_7 ) ;
}
static void F_25 ( struct V_41 * V_42 )
{
struct V_5 * V_6 ;
struct V_11 * V_11 ;
struct V_20 * V_21 ;
T_1 V_43 ;
T_1 V_44 , V_36 ;
V_6 = F_26 ( F_27 ( V_42 ) , struct V_5 ,
V_13 . V_45 ) ;
V_11 = F_4 ( V_6 ) ;
V_21 = F_10 ( V_6 ) ;
F_28 ( F_4 ( V_6 ) ) ;
F_16 ( & V_6 -> V_33 ) ;
if ( ! V_6 -> V_13 . V_46 ) {
F_7 ( V_11 -> V_17 ,
L_6 ) ;
F_18 ( & V_6 -> V_33 ) ;
return;
}
V_44 = F_21 ( V_11 , V_39 ) ;
V_36 = V_44 | F_22 ( V_21 -> V_38 ) ;
F_23 ( V_11 , V_36 , V_39 ) ;
F_7 ( V_11 -> V_17 , L_7 ,
V_44 , V_36 ) ;
V_43 = F_6 ( V_6 -> V_13 . V_14 ) ;
if ( ( V_47 ) ( V_43 - V_6 -> V_13 . V_43 ) >= 0 ) {
F_7 ( V_11 -> V_17 ,
L_8 ) ;
V_36 = V_44 & ~ ( F_22 ( V_21 -> V_38 ) ) ;
F_23 ( V_11 , V_36 ,
V_39 ) ;
F_18 ( & V_6 -> V_33 ) ;
return;
}
F_20 ( V_11 -> V_17 , L_9 ,
V_18 , V_6 -> V_13 . V_14 -> V_38 , V_6 -> V_13 . V_14 -> V_48 ,
V_43 , V_6 -> V_13 . V_43 ) ;
F_29 ( V_11 , V_6 ) ;
F_30 ( V_6 , V_21 -> V_17 ) ;
F_18 ( & V_6 -> V_33 ) ;
}
static int F_31 ( struct V_5 * V_6 , T_1 V_49 )
{
F_32 ( & V_6 -> V_13 . V_45 , F_25 ) ;
V_6 -> V_13 . V_50 = true ;
return 0 ;
}
static void F_33 ( struct V_5 * V_6 )
{
if ( V_6 -> V_13 . V_50 )
F_34 ( & V_6 -> V_13 . V_45 ) ;
V_6 -> V_13 . V_50 = false ;
}
