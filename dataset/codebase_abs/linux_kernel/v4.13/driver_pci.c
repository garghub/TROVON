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
static T_2 F_8 ( struct V_1 * V_2 , T_2 V_20 , T_3 V_3 )
{
int V_21 = 10 ;
T_2 V_22 = 0 ;
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
T_3 V_3 , T_2 V_6 )
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
static T_2 F_10 ( struct V_1 * V_2 , T_2 V_20 ,
T_3 V_3 , T_2 V_6 )
{
F_9 ( V_2 , V_20 , V_3 , V_6 ) ;
return F_8 ( V_2 , V_20 , V_3 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_31 * V_25 = V_2 -> V_25 ;
T_2 V_32 , V_33 ;
T_4 V_34 ;
V_34 = F_12 ( V_35 ) ;
V_33 = ( T_2 ) V_25 -> V_33 ;
V_32 = F_13 ( V_2 , V_34 ) ;
if ( ( ( V_32 & V_36 ) >> V_37 )
!= V_33 ) {
V_32 = ( V_33 << V_37 ) |
( V_32 & ~ V_36 ) ;
F_14 ( V_2 , V_34 , V_32 ) ;
}
}
void F_15 ( struct V_1 * V_2 )
{
if ( V_2 -> V_38 )
return;
V_2 -> V_39 = F_16 ( V_2 ) ;
if ( V_2 -> V_39 )
goto V_40;
F_11 ( V_2 ) ;
V_40:
V_2 -> V_38 = true ;
}
static T_3 F_17 ( struct V_1 * V_2 )
{
T_1 V_41 ;
V_41 = F_1 ( V_2 , V_42 ) ;
if ( V_41 & V_43 )
return V_44 |
V_45 ;
else
return V_44 ;
}
static void F_18 ( struct V_1 * V_2 )
{
T_2 V_41 ;
F_9 ( V_2 , V_46 ,
V_47 ,
F_17 ( V_2 ) ) ;
V_41 = F_8 ( V_2 , V_48 ,
V_49 ) ;
if ( V_41 & V_50 )
F_9 ( V_2 , V_48 ,
V_49 ,
V_41 & ~ V_50 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
T_2 V_32 ;
T_4 V_34 ;
V_34 = F_12 ( V_51 ) ;
V_32 = F_13 ( V_2 , V_34 ) ;
if ( ! ( V_32 & V_52 ) ) {
V_32 |= V_52 ;
F_14 ( V_2 , V_34 , V_32 ) ;
}
}
static void F_20 ( struct V_1 * V_2 )
{
F_18 ( V_2 ) ;
F_19 ( V_2 ) ;
}
void F_21 ( struct V_1 * V_2 )
{
if ( V_2 -> V_53 )
return;
F_15 ( V_2 ) ;
if ( V_2 -> V_39 )
F_22 ( V_2 ) ;
else
F_20 ( V_2 ) ;
}
void F_23 ( struct V_54 * V_55 , bool V_56 )
{
struct V_1 * V_2 ;
T_2 V_6 ;
if ( V_55 -> V_57 != V_58 )
return;
V_2 = & V_55 -> V_59 [ 0 ] ;
if ( V_2 -> V_25 -> V_26 . V_27 >= 15 && V_2 -> V_25 -> V_26 . V_27 <= 20 ) {
V_6 = V_56 ? 0x74 : 0x7C ;
F_10 ( V_2 , V_60 ,
V_61 , 0x7F64 ) ;
F_10 ( V_2 , V_60 ,
V_62 , V_6 ) ;
} else if ( V_2 -> V_25 -> V_26 . V_27 >= 21 && V_2 -> V_25 -> V_26 . V_27 <= 22 ) {
V_6 = V_56 ? 0x75 : 0x7D ;
F_10 ( V_2 , V_60 ,
V_61 , 0x7E65 ) ;
F_10 ( V_2 , V_60 ,
V_62 , V_6 ) ;
}
}
static void F_24 ( struct V_1 * V_2 , bool V_63 )
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
void F_25 ( struct V_1 * V_2 )
{
F_24 ( V_2 , true ) ;
}
void F_26 ( struct V_1 * V_2 )
{
F_24 ( V_2 , false ) ;
}
