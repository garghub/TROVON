T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
F_2 ( V_2 , V_4 , V_3 ) ;
F_3 ( V_2 , V_4 ) ;
return F_3 ( V_2 , V_5 ) ;
}
static void F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_6 )
{
F_2 ( V_2 , V_4 , V_3 ) ;
F_3 ( V_2 , V_4 ) ;
F_2 ( V_2 , V_5 , V_6 ) ;
}
static void F_5 ( struct V_1 * V_2 , T_2 V_7 )
{
T_1 V_8 ;
int V_9 ;
V_8 = V_10 ;
V_8 |= V_11 ;
V_8 |= ( V_12 <<
V_13 ) ;
V_8 |= ( V_14 <<
V_15 ) ;
V_8 |= V_16 ;
V_8 |= ( V_7 << 4 ) ;
F_2 ( V_2 , V_17 , V_8 ) ;
F_6 ( 10 ) ;
for ( V_9 = 0 ; V_9 < 200 ; V_9 ++ ) {
V_8 = F_3 ( V_2 , V_18 ) ;
if ( V_8 & V_19 )
break;
F_7 ( 1000 , 2000 ) ;
}
}
static T_3 F_8 ( struct V_1 * V_2 , T_2 V_20 , T_2 V_3 )
{
int V_21 = 10 ;
T_3 V_22 = 0 ;
T_1 V_8 ;
int V_9 ;
V_8 = V_23 ;
V_8 |= V_24 ;
F_2 ( V_2 , V_18 , V_8 ) ;
if ( V_2 -> V_25 -> V_26 . V_27 >= 10 ) {
V_21 = 200 ;
F_5 ( V_2 , V_20 ) ;
V_8 = ( V_12 <<
V_13 ) ;
V_8 |= ( V_3 << V_15 ) ;
} else {
V_8 = ( V_20 << V_28 ) ;
V_8 |= ( V_3 << V_29 ) ;
}
V_8 = V_10 ;
V_8 |= V_30 ;
V_8 |= V_16 ;
F_2 ( V_2 , V_17 , V_8 ) ;
F_6 ( 10 ) ;
for ( V_9 = 0 ; V_9 < V_21 ; V_9 ++ ) {
V_8 = F_3 ( V_2 , V_18 ) ;
if ( V_8 & V_19 ) {
F_6 ( 10 ) ;
V_22 = F_3 ( V_2 , V_17 ) ;
break;
}
F_7 ( 1000 , 2000 ) ;
}
F_2 ( V_2 , V_18 , 0 ) ;
return V_22 ;
}
static void F_9 ( struct V_1 * V_2 , T_2 V_20 ,
T_2 V_3 , T_3 V_6 )
{
int V_21 = 10 ;
T_1 V_8 ;
int V_9 ;
V_8 = V_23 ;
V_8 |= V_24 ;
F_2 ( V_2 , V_18 , V_8 ) ;
if ( V_2 -> V_25 -> V_26 . V_27 >= 10 ) {
V_21 = 200 ;
F_5 ( V_2 , V_20 ) ;
V_8 = ( V_12 <<
V_13 ) ;
V_8 |= ( V_3 << V_15 ) ;
} else {
V_8 = ( V_20 << V_28 ) ;
V_8 |= ( V_3 << V_29 ) ;
}
V_8 = V_10 ;
V_8 |= V_11 ;
V_8 |= V_16 ;
V_8 |= V_6 ;
F_2 ( V_2 , V_17 , V_8 ) ;
F_6 ( 10 ) ;
for ( V_9 = 0 ; V_9 < V_21 ; V_9 ++ ) {
V_8 = F_3 ( V_2 , V_18 ) ;
if ( V_8 & V_19 )
break;
F_7 ( 1000 , 2000 ) ;
}
F_2 ( V_2 , V_18 , 0 ) ;
}
static T_2 F_10 ( struct V_1 * V_2 )
{
T_1 V_31 ;
V_31 = F_1 ( V_2 , V_32 ) ;
if ( V_31 & V_33 )
return V_34 |
V_35 ;
else
return V_34 ;
}
static void F_11 ( struct V_1 * V_2 )
{
T_3 V_31 ;
F_9 ( V_2 , V_36 ,
V_37 ,
F_10 ( V_2 ) ) ;
V_31 = F_8 ( V_2 , V_38 ,
V_39 ) ;
if ( V_31 & V_40 )
F_9 ( V_2 , V_38 ,
V_39 ,
V_31 & ~ V_40 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_41 * V_25 = V_2 -> V_25 ;
T_3 V_42 , V_43 ;
T_4 V_44 ;
V_44 = F_13 ( V_45 ) ;
V_43 = ( T_3 ) V_25 -> V_43 ;
V_42 = F_14 ( V_2 , V_44 ) ;
if ( ( ( V_42 & V_46 ) >> V_47 )
!= V_43 ) {
V_42 = ( V_43 << V_47 ) |
( V_42 & ~ V_46 ) ;
F_15 ( V_2 , V_44 , V_42 ) ;
}
}
static void F_16 ( struct V_1 * V_2 )
{
T_3 V_42 ;
T_4 V_44 ;
V_44 = F_13 ( V_48 ) ;
V_42 = F_14 ( V_2 , V_44 ) ;
if ( ! ( V_42 & V_49 ) ) {
V_42 |= V_49 ;
F_15 ( V_2 , V_44 , V_42 ) ;
}
}
static void F_17 ( struct V_1 * V_2 )
{
F_12 ( V_2 ) ;
F_11 ( V_2 ) ;
F_16 ( V_2 ) ;
}
void F_18 ( struct V_1 * V_2 )
{
if ( V_2 -> V_50 )
return;
#ifdef F_19
V_2 -> V_51 = F_20 ( V_2 ) ;
if ( V_2 -> V_51 )
F_21 ( V_2 ) ;
#endif
if ( ! V_2 -> V_51 )
F_17 ( V_2 ) ;
}
int F_22 ( struct V_1 * V_2 , struct V_41 * V_25 ,
bool V_52 )
{
struct V_53 * V_54 ;
T_1 V_55 , V_31 ;
int V_56 = 0 ;
if ( ! V_2 || V_25 -> V_57 -> V_58 != V_59 ) {
goto V_60;
}
V_54 = V_2 -> V_25 -> V_57 -> V_61 ;
V_56 = F_23 ( V_54 , V_62 , & V_31 ) ;
if ( V_56 )
goto V_60;
V_55 = F_24 ( V_25 -> V_43 ) << 8 ;
if ( V_52 )
V_31 |= V_55 ;
else
V_31 &= ~ V_55 ;
V_56 = F_25 ( V_54 , V_62 , V_31 ) ;
V_60:
return V_56 ;
}
void F_26 ( struct V_1 * V_2 , bool V_63 )
{
T_1 V_64 ;
V_64 = F_1 ( V_2 , V_65 ) ;
if ( V_63 )
V_64 |= V_66 ;
else
V_64 &= ~ V_66 ;
F_4 ( V_2 , V_65 , V_64 ) ;
F_1 ( V_2 , V_65 ) ;
}
