T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
F_2 ( V_2 , V_4 , V_3 ) ;
F_3 ( V_2 , V_4 ) ;
return F_3 ( V_2 , V_5 ) ;
}
static void F_4 ( struct V_1 * V_2 , T_2 V_6 )
{
T_1 V_7 ;
int V_8 ;
V_7 = V_9 ;
V_7 |= V_10 ;
V_7 |= ( V_11 <<
V_12 ) ;
V_7 |= ( V_13 <<
V_14 ) ;
V_7 |= V_15 ;
V_7 |= ( V_6 << 4 ) ;
F_2 ( V_2 , V_16 , V_7 ) ;
F_5 ( 10 ) ;
for ( V_8 = 0 ; V_8 < 200 ; V_8 ++ ) {
V_7 = F_3 ( V_2 , V_17 ) ;
if ( V_7 & V_18 )
break;
F_6 ( 1 ) ;
}
}
static T_3 F_7 ( struct V_1 * V_2 , T_2 V_19 , T_2 V_3 )
{
int V_20 = 10 ;
T_3 V_21 = 0 ;
T_1 V_7 ;
int V_8 ;
V_7 = V_22 ;
V_7 |= V_23 ;
F_2 ( V_2 , V_17 , V_7 ) ;
if ( V_2 -> V_24 -> V_25 . V_26 >= 10 ) {
V_20 = 200 ;
F_4 ( V_2 , V_19 ) ;
V_7 = ( V_11 <<
V_12 ) ;
V_7 |= ( V_3 << V_14 ) ;
} else {
V_7 = ( V_19 << V_27 ) ;
V_7 |= ( V_3 << V_28 ) ;
}
V_7 = V_9 ;
V_7 |= V_29 ;
V_7 |= V_15 ;
F_2 ( V_2 , V_16 , V_7 ) ;
F_5 ( 10 ) ;
for ( V_8 = 0 ; V_8 < V_20 ; V_8 ++ ) {
V_7 = F_3 ( V_2 , V_17 ) ;
if ( V_7 & V_18 ) {
F_5 ( 10 ) ;
V_21 = F_3 ( V_2 , V_16 ) ;
break;
}
F_6 ( 1 ) ;
}
F_2 ( V_2 , V_17 , 0 ) ;
return V_21 ;
}
static void F_8 ( struct V_1 * V_2 , T_2 V_19 ,
T_2 V_3 , T_3 V_30 )
{
int V_20 = 10 ;
T_1 V_7 ;
int V_8 ;
V_7 = V_22 ;
V_7 |= V_23 ;
F_2 ( V_2 , V_17 , V_7 ) ;
if ( V_2 -> V_24 -> V_25 . V_26 >= 10 ) {
V_20 = 200 ;
F_4 ( V_2 , V_19 ) ;
V_7 = ( V_11 <<
V_12 ) ;
V_7 |= ( V_3 << V_14 ) ;
} else {
V_7 = ( V_19 << V_27 ) ;
V_7 |= ( V_3 << V_28 ) ;
}
V_7 = V_9 ;
V_7 |= V_10 ;
V_7 |= V_15 ;
V_7 |= V_30 ;
F_2 ( V_2 , V_16 , V_7 ) ;
F_5 ( 10 ) ;
for ( V_8 = 0 ; V_8 < V_20 ; V_8 ++ ) {
V_7 = F_3 ( V_2 , V_17 ) ;
if ( V_7 & V_18 )
break;
F_6 ( 1 ) ;
}
F_2 ( V_2 , V_17 , 0 ) ;
}
static T_2 F_9 ( struct V_1 * V_2 )
{
T_1 V_31 ;
V_31 = F_1 ( V_2 , V_32 ) ;
if ( V_31 & V_33 )
return V_34 |
V_35 ;
else
return V_34 ;
}
static void F_10 ( struct V_1 * V_2 )
{
T_3 V_31 ;
F_8 ( V_2 , V_36 ,
V_37 ,
F_9 ( V_2 ) ) ;
V_31 = F_7 ( V_2 , V_38 ,
V_39 ) ;
if ( V_31 & V_40 )
F_8 ( V_2 , V_38 ,
V_39 ,
V_31 & ~ V_40 ) ;
}
static void T_4 F_11 ( struct V_1 * V_2 )
{
F_10 ( V_2 ) ;
}
void T_4 F_12 ( struct V_1 * V_2 )
{
if ( V_2 -> V_41 )
return;
#ifdef F_13
V_2 -> V_42 = F_14 ( V_2 ) ;
if ( V_2 -> V_42 )
F_15 ( V_2 ) ;
#endif
if ( ! V_2 -> V_42 )
F_11 ( V_2 ) ;
}
int F_16 ( struct V_1 * V_2 , struct V_43 * V_24 ,
bool V_44 )
{
struct V_45 * V_46 = V_2 -> V_24 -> V_47 -> V_48 ;
T_1 V_49 , V_31 ;
int V_50 = 0 ;
if ( V_24 -> V_47 -> V_51 != V_52 ) {
goto V_53;
}
V_50 = F_17 ( V_46 , V_54 , & V_31 ) ;
if ( V_50 )
goto V_53;
V_49 = F_18 ( V_24 -> V_55 ) << 8 ;
if ( V_44 )
V_31 |= V_49 ;
else
V_31 &= ~ V_49 ;
V_50 = F_19 ( V_46 , V_54 , V_31 ) ;
V_53:
return V_50 ;
}
