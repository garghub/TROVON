static void F_1 ( struct V_1 * V_2 , int V_3 )
{
T_1 V_4 ;
V_4 = F_2 ( V_2 , V_5 ) ;
V_4 &= ~ ( V_6 | V_7 ) ;
if ( V_3 == V_8 )
V_4 |= V_7 ;
else if ( V_3 == V_9 )
V_4 |= V_6 ;
F_3 ( V_2 , V_4 , V_5 ) ;
}
static T_2 F_4 ( struct V_1 * V_2 , int V_10 )
{
T_2 V_11 = F_5 ( V_2 -> V_12 + V_10 ) ;
if ( F_6 ( ( V_10 == V_13 ) &&
( V_2 -> V_14 -> V_15 & V_16 ) ) ) {
V_11 = V_17 |
V_18 | V_19 ;
}
if ( F_6 ( V_10 == V_20 ) ) {
T_2 V_21 = V_11 ;
V_21 &= ~ ( 0xFF << 16 ) ;
V_11 = V_21 | ( V_22 << 16 ) ;
}
return V_11 ;
}
static T_3 F_7 ( struct V_1 * V_2 , int V_10 )
{
T_3 V_23 = 0 ;
V_23 = F_8 ( V_2 -> V_12 + V_10 ) ;
if ( F_6 ( V_10 == V_24 ) ) {
V_23 = F_8 ( V_2 -> V_12 + V_24 ) ;
V_23 |= V_22 ;
}
return V_23 ;
}
static int F_9 ( struct V_1 * V_2 , T_2 V_25 )
{
int V_26 = 3 ;
int V_27 ;
T_1 V_28 = 0 ;
int V_29 = 0 , V_30 = 0 ;
int V_31 = - 1 , V_32 = 0 , V_33 = - 1 , V_34 = 0 ;
T_3 V_35 ;
struct V_36 * V_14 = V_2 -> V_14 ;
V_35 = F_10 ( V_2 , V_37 ) ;
V_35 &= ~ 0x3fff ;
V_38:
V_27 = 0 ;
V_28 = 0 ;
do {
F_11 ( V_2 ,
V_35 | V_27 ,
V_37 ) ;
if ( ! F_12 ( V_14 , V_25 , NULL ) ) {
V_28 ++ ;
F_13 ( F_14 ( V_14 ) , L_1 ,
F_15 ( V_14 ) , V_27 ) ;
if ( V_31 == - 1 )
V_31 = V_27 ;
V_32 = V_27 ;
V_34 ++ ;
if ( V_27 == ( V_39 - 1 )
&& V_34 > V_30 )
V_33 = ( V_31 + V_32 ) / 2 ;
} else {
F_13 ( F_14 ( V_14 ) , L_2 ,
F_15 ( V_14 ) , V_27 ) ;
if ( V_34 > V_30 ) {
V_33 = ( V_31 + V_32 ) / 2 ;
V_30 = V_34 ;
}
V_31 = - 1 ;
V_32 = V_34 = 0 ;
}
} while ( ++ V_27 < V_39 );
if ( V_28 && V_33 > 0 ) {
V_27 = V_33 ;
F_11 ( V_2 ,
V_35 | V_27 ,
V_37 ) ;
F_13 ( F_14 ( V_14 ) , L_3 ,
F_15 ( V_14 ) , V_27 ) ;
} else {
if ( -- V_26 )
goto V_38;
F_13 ( F_14 ( V_14 ) , L_4 ,
F_15 ( V_14 ) ) ;
V_29 = - V_40 ;
}
return V_29 ;
}
static int F_16 ( struct V_41 * V_42 )
{
struct V_1 * V_2 ;
struct V_43 * V_44 ;
struct V_45 * V_46 ;
struct V_47 * V_47 ;
int V_48 ;
int V_23 ;
V_47 = F_17 ( & V_42 -> V_49 , NULL ) ;
if ( F_18 ( V_47 ) ) {
F_19 ( & V_42 -> V_49 , L_5 ) ;
return F_20 ( V_47 ) ;
}
if ( V_42 -> V_49 . V_50 )
V_48 = F_21 ( V_42 -> V_49 . V_50 , L_6 , 0 ) ;
else
V_48 = - V_51 ;
V_2 = F_22 ( V_42 , & V_52 , sizeof( struct V_45 ) ) ;
if ( F_18 ( V_2 ) )
return F_20 ( V_2 ) ;
V_44 = F_23 ( V_2 ) ;
V_44 -> V_47 = V_47 ;
V_46 = F_24 ( V_44 ) ;
V_46 -> V_48 = V_48 ;
F_25 ( V_42 ) ;
V_23 = F_26 ( V_44 -> V_47 ) ;
if ( V_23 )
goto V_53;
V_23 = F_27 ( V_2 ) ;
if ( V_23 )
goto V_54;
if ( F_28 ( V_46 -> V_48 ) ) {
V_23 = F_29 ( V_2 -> V_14 , V_46 -> V_48 , 0 ) ;
if ( V_23 ) {
F_19 ( & V_42 -> V_49 , L_7 ,
V_23 ) ;
goto V_55;
}
F_30 ( V_2 -> V_14 ) ;
}
return 0 ;
V_55:
F_31 ( V_2 , 0 ) ;
V_54:
F_32 ( V_44 -> V_47 ) ;
V_53:
F_33 ( V_42 ) ;
return V_23 ;
}
