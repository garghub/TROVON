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
V_11 = V_17 | V_18 ;
}
if ( F_6 ( V_10 == V_19 ) ) {
T_2 V_20 = V_11 ;
V_20 &= ~ ( 0xFF << 16 ) ;
V_11 = V_20 | ( V_21 << 16 ) ;
}
return V_11 ;
}
static T_3 F_7 ( struct V_1 * V_2 , int V_10 )
{
T_3 V_22 = 0 ;
V_22 = F_8 ( V_2 -> V_12 + V_10 ) ;
if ( F_6 ( V_10 == V_23 ) ) {
V_22 = F_8 ( V_2 -> V_12 + V_23 ) ;
V_22 |= V_21 ;
}
return V_22 ;
}
static int F_9 ( struct V_1 * V_2 , T_2 V_24 )
{
int V_25 = 3 ;
int V_26 ;
T_1 V_27 = 0 ;
int V_28 = 0 , V_29 = 0 ;
int V_30 = - 1 , V_31 = 0 , V_32 = - 1 , V_33 = 0 ;
T_3 V_34 ;
struct V_35 * V_14 = V_2 -> V_14 ;
V_34 = F_10 ( V_2 , V_36 ) ;
V_34 &= ~ 0x3fff ;
V_37:
V_26 = 0 ;
V_27 = 0 ;
do {
F_11 ( V_2 ,
V_34 | V_26 ,
V_36 ) ;
if ( ! F_12 ( V_14 ) ) {
V_27 ++ ;
F_13 ( F_14 ( V_14 ) , L_1 ,
F_15 ( V_14 ) , V_26 ) ;
if ( V_30 == - 1 )
V_30 = V_26 ;
V_31 = V_26 ;
V_33 ++ ;
if ( V_26 == ( V_38 - 1 )
&& V_33 > V_29 )
V_32 = ( V_30 + V_31 ) / 2 ;
} else {
F_13 ( F_14 ( V_14 ) , L_2 ,
F_15 ( V_14 ) , V_26 ) ;
if ( V_33 > V_29 ) {
V_32 = ( V_30 + V_31 ) / 2 ;
V_29 = V_33 ;
}
V_30 = - 1 ;
V_31 = V_33 = 0 ;
}
} while ( ++ V_26 < V_38 );
if ( V_27 && V_32 > 0 ) {
V_26 = V_32 ;
F_11 ( V_2 ,
V_34 | V_26 ,
V_36 ) ;
F_13 ( F_14 ( V_14 ) , L_3 ,
F_15 ( V_14 ) , V_26 ) ;
} else {
if ( -- V_25 )
goto V_37;
F_13 ( F_14 ( V_14 ) , L_4 ,
F_15 ( V_14 ) ) ;
V_28 = - V_39 ;
}
return V_28 ;
}
static int F_16 ( struct V_40 * V_41 )
{
struct V_1 * V_2 ;
struct V_42 * V_43 ;
struct V_44 * V_45 ;
struct V_46 * V_46 ;
int V_47 ;
int V_22 ;
V_46 = F_17 ( & V_41 -> V_48 , NULL ) ;
if ( F_18 ( V_46 ) ) {
F_19 ( & V_41 -> V_48 , L_5 ) ;
return F_20 ( V_46 ) ;
}
if ( V_41 -> V_48 . V_49 )
V_47 = F_21 ( V_41 -> V_48 . V_49 , L_6 , 0 ) ;
else
V_47 = - V_50 ;
V_2 = F_22 ( V_41 , & V_51 , sizeof( struct V_44 ) ) ;
if ( F_18 ( V_2 ) )
return F_20 ( V_2 ) ;
V_43 = F_23 ( V_2 ) ;
V_43 -> V_46 = V_46 ;
V_45 = F_24 ( V_43 ) ;
V_45 -> V_47 = V_47 ;
F_25 ( V_41 ) ;
V_22 = F_26 ( V_43 -> V_46 ) ;
if ( V_22 )
goto V_52;
V_22 = F_27 ( V_2 ) ;
if ( V_22 )
goto V_53;
if ( F_28 ( V_45 -> V_47 ) ) {
V_22 = F_29 ( V_2 -> V_14 , V_45 -> V_47 , 0 ) ;
if ( V_22 ) {
F_19 ( & V_41 -> V_48 , L_7 ,
V_22 ) ;
goto V_54;
}
F_30 ( V_2 -> V_14 ) ;
}
return 0 ;
V_54:
F_31 ( V_2 , 0 ) ;
V_53:
F_32 ( V_43 -> V_46 ) ;
V_52:
F_33 ( V_41 ) ;
return V_22 ;
}
static int F_34 ( struct V_55 * V_48 )
{
struct V_1 * V_2 = F_35 ( V_48 ) ;
struct V_42 * V_43 = F_23 ( V_2 ) ;
int V_22 ;
V_22 = F_36 ( V_2 ) ;
if ( V_22 )
return V_22 ;
F_37 ( V_43 -> V_46 ) ;
return 0 ;
}
static int F_38 ( struct V_55 * V_48 )
{
struct V_1 * V_2 = F_35 ( V_48 ) ;
struct V_42 * V_43 = F_23 ( V_2 ) ;
int V_22 ;
V_22 = F_39 ( V_43 -> V_46 ) ;
if ( V_22 ) {
F_13 ( V_48 , L_8 ) ;
return V_22 ;
}
return F_40 ( V_2 ) ;
}
