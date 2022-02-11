static int F_1 ( unsigned V_1 )
{
int V_2 ;
int V_3 = 1 ;
for ( V_2 = 0 ; V_2 < V_1 ; ++ V_2 )
V_3 = V_3 * 10 ;
return V_3 ;
}
static void F_2 ( int V_4 , int V_5 , int * V_6 ,
int * V_7 )
{
int V_8 ;
int exp = 0 ;
* V_7 = 0 ;
if ( V_5 == 0 ) {
* V_6 = 0 ;
return;
}
* V_6 = V_4 / V_5 ;
V_8 = V_4 % V_5 ;
if ( V_8 ) {
while ( V_8 <= V_5 ) {
V_8 *= 10 ;
exp ++ ;
}
* V_7 = ( V_8 / V_5 ) * F_1 ( 6 - exp ) ;
}
}
static void F_3 ( unsigned int V_9 , int exp , int * V_10 , int * V_11 )
{
* V_10 = V_9 / F_1 ( exp ) ;
* V_11 = V_9 % F_1 ( exp ) * F_1 ( 6 - exp ) ;
}
static void F_4 ( T_1 V_12 , int V_13 , int exp ,
int * V_10 , int * V_11 )
{
int V_14 = 1 ;
if ( V_12 & F_5 ( V_13 * 8 - 1 ) ) {
V_12 = ( ( 1LL << ( V_13 * 8 ) ) - V_12 ) ;
V_14 = - 1 ;
}
exp = F_6 ( exp ) ;
if ( exp >= 0 ) {
* V_10 = V_14 * V_12 * F_1 ( exp ) ;
* V_11 = 0 ;
} else {
F_3 ( V_12 , - exp , V_10 , V_11 ) ;
if ( * V_10 )
* V_10 = V_14 * ( * V_10 ) ;
else
* V_11 = V_14 * ( * V_11 ) ;
}
}
static T_1 F_7 ( int V_13 , int exp , int V_10 , int V_11 )
{
T_1 V_12 ;
int V_14 = 1 ;
if ( V_10 < 0 || V_11 < 0 )
V_14 = - 1 ;
exp = F_6 ( exp ) ;
if ( exp < 0 ) {
V_12 = abs ( V_10 ) * F_1 ( - exp ) ;
V_12 += abs ( V_11 ) / F_1 ( 6 + exp ) ;
} else
V_12 = abs ( V_10 ) / F_1 ( exp ) ;
if ( V_14 < 0 )
V_12 = ( ( 1LL << ( V_13 * 8 ) ) - V_12 ) ;
return V_12 ;
}
T_2 F_8 ( struct V_15 * V_16 )
{
T_2 V_12 = 0 ;
int V_3 ;
V_3 = F_9 ( V_16 -> V_17 ,
V_16 -> V_18 . V_19 ,
V_16 -> V_18 . V_20 , sizeof( V_12 ) , & V_12 ) ;
if ( V_3 < 0 || V_12 < 0 ) {
return - V_21 ;
} else {
if ( V_16 -> V_18 . V_22 == V_23 )
V_12 = V_12 * 1000 ;
}
return V_12 ;
}
int F_10 ( struct V_15 * V_16 ,
int * V_10 , int * V_11 )
{
T_2 V_12 ;
int V_3 ;
V_3 = F_9 ( V_16 -> V_17 ,
V_16 -> V_18 . V_19 ,
V_16 -> V_18 . V_20 , sizeof( V_12 ) , & V_12 ) ;
if ( V_3 < 0 || V_12 < 0 ) {
* V_10 = * V_11 = 0 ;
return - V_21 ;
} else {
if ( V_16 -> V_18 . V_22 == V_24 )
F_2 ( 1000 , V_12 , V_10 , V_11 ) ;
else if ( V_16 -> V_18 . V_22 == V_23 )
F_2 ( 1 , V_12 , V_10 , V_11 ) ;
else {
* V_10 = * V_11 = 0 ;
return - V_21 ;
}
}
return V_25 ;
}
int F_11 ( struct V_15 * V_16 ,
int V_10 , int V_11 )
{
T_2 V_12 ;
int V_3 ;
if ( V_10 < 0 || V_11 < 0 )
return - V_21 ;
V_12 = V_10 * F_1 ( 6 ) + V_11 ;
if ( V_12 ) {
if ( V_16 -> V_18 . V_22 == V_24 )
V_12 = F_1 ( 9 ) / V_12 ;
else if ( V_16 -> V_18 . V_22 == V_23 )
V_12 = F_1 ( 6 ) / V_12 ;
else
V_12 = 0 ;
}
V_3 = F_12 ( V_16 -> V_17 , V_16 -> V_18 . V_19 ,
V_16 -> V_18 . V_20 , sizeof( V_12 ) , & V_12 ) ;
if ( V_3 < 0 || V_12 < 0 )
return - V_21 ;
V_3 = F_9 ( V_16 -> V_17 ,
V_16 -> V_18 . V_19 ,
V_16 -> V_18 . V_20 , sizeof( V_12 ) , & V_12 ) ;
if ( V_3 < 0 || V_12 < 0 )
return - V_21 ;
V_16 -> V_26 = V_12 ;
return 0 ;
}
int F_13 ( struct V_15 * V_16 ,
int * V_10 , int * V_11 )
{
T_2 V_12 ;
int V_3 ;
V_3 = F_9 ( V_16 -> V_17 ,
V_16 -> V_27 . V_19 ,
V_16 -> V_27 . V_20 , sizeof( V_12 ) ,
& V_12 ) ;
if ( V_3 < 0 || V_12 < 0 ) {
* V_10 = * V_11 = 0 ;
return - V_21 ;
} else {
F_4 ( V_12 , V_16 -> V_27 . V_13 ,
V_16 -> V_27 . V_28 ,
V_10 , V_11 ) ;
}
return V_25 ;
}
int F_14 ( struct V_15 * V_16 ,
int V_10 , int V_11 )
{
T_2 V_12 ;
int V_3 ;
if ( V_10 < 0 || V_11 < 0 )
return - V_21 ;
V_12 = F_7 ( V_16 -> V_27 . V_13 ,
V_16 -> V_27 . V_28 ,
V_10 , V_11 ) ;
V_3 = F_12 ( V_16 -> V_17 , V_16 -> V_27 . V_19 ,
V_16 -> V_27 . V_20 , sizeof( V_12 ) ,
& V_12 ) ;
if ( V_3 < 0 || V_12 < 0 )
return - V_21 ;
V_3 = F_9 ( V_16 -> V_17 ,
V_16 -> V_27 . V_19 ,
V_16 -> V_27 . V_20 , sizeof( V_12 ) ,
& V_12 ) ;
if ( V_3 < 0 || V_12 < 0 )
return - V_21 ;
V_16 -> V_29 = V_12 ;
return 0 ;
}
static void F_15 ( int * V_30 , int * V_10 , int V_31 ,
int V_32 , int exp )
{
int V_2 ;
int V_33 ;
int V_34 ;
int V_8 ;
if ( exp > 0 ) {
* V_30 = V_31 * F_1 ( exp ) ;
V_34 = 0 ;
if ( exp > 9 ) {
* V_10 = 0 ;
return;
}
for ( V_2 = 0 ; V_2 < exp ; ++ V_2 ) {
V_33 = V_32 / F_1 ( 8 - V_2 ) ;
V_34 += ( F_1 ( exp - 1 - V_2 ) * V_33 ) ;
V_32 = V_32 % F_1 ( 8 - V_2 ) ;
}
* V_30 += V_34 ;
* V_10 = V_32 * F_1 ( exp ) ;
} else if ( exp < 0 ) {
exp = abs ( exp ) ;
if ( exp > 9 ) {
* V_30 = * V_10 = 0 ;
return;
}
* V_30 = V_31 / F_1 ( exp ) ;
V_8 = V_31 % F_1 ( exp ) ;
V_34 = 0 ;
for ( V_2 = 0 ; V_2 < ( 9 - exp ) ; ++ V_2 ) {
V_33 = V_32 / F_1 ( 8 - V_2 ) ;
V_34 += ( F_1 ( 8 - exp - V_2 ) * V_33 ) ;
V_32 = V_32 % F_1 ( 8 - V_2 ) ;
}
* V_10 = V_8 * F_1 ( 9 - exp ) + V_34 ;
} else {
* V_30 = V_31 ;
* V_10 = V_32 ;
}
}
int F_16 ( T_1 V_35 ,
struct V_36 * V_37 ,
int * V_30 , int * V_10 )
{
int V_2 ;
int exp ;
* V_30 = 1 ;
* V_10 = 0 ;
for ( V_2 = 0 ; V_2 < F_17 ( V_38 ) ; ++ V_2 ) {
if ( V_38 [ V_2 ] . V_35 == V_35 &&
V_38 [ V_2 ] . V_39 == V_37 -> V_22 ) {
exp = F_6 (
V_37 -> V_28 ) ;
F_15 ( V_30 , V_10 ,
V_38 [ V_2 ] . V_40 ,
V_38 [ V_2 ] . V_41 , exp ) ;
break;
}
}
return V_42 ;
}
T_3 F_18 ( struct V_15 * V_16 ,
T_3 V_43 )
{
return V_16 -> V_44 * V_43 ;
}
static
int F_19 ( struct V_45 * V_17 ,
T_1 V_35 ,
struct V_15 * V_16 )
{
F_20 ( V_17 ,
V_46 , V_35 ,
V_47 ,
& V_16 -> V_18 ) ;
if ( V_16 -> V_18 . V_22 == 0 )
V_16 -> V_18 . V_22 = V_24 ;
V_16 -> V_26 = - 1 ;
return 0 ;
}
static void F_21 ( struct V_45 * V_17 ,
T_1 V_35 ,
struct V_15 * V_16 )
{
F_20 ( V_17 , V_46 ,
V_35 ,
V_48 ,
& V_16 -> V_49 ) ;
F_22 ( V_17 -> V_50 , L_1 ,
V_16 -> V_49 . V_20 , V_16 -> V_49 . V_19 ) ;
}
int F_23 ( struct V_15 * V_16 )
{
int V_3 ;
int V_12 ;
V_3 = F_9 ( V_16 -> V_17 , V_16 -> V_49 . V_19 ,
V_16 -> V_49 . V_20 , sizeof( V_12 ) ,
& V_12 ) ;
if ( V_3 < 0 )
return V_3 ;
return V_12 ;
}
int F_24 ( struct V_15 * V_16 , int V_51 )
{
return F_12 ( V_16 -> V_17 , V_16 -> V_49 . V_19 ,
V_16 -> V_49 . V_20 ,
sizeof( V_51 ) , & V_51 ) ;
}
bool F_25 ( struct V_15 * V_16 )
{
return V_16 -> V_49 . V_20 > 0 && V_16 -> V_49 . V_19 > 0 ;
}
int F_26 ( struct V_45 * V_17 ,
T_1 V_35 ,
struct V_15 * V_16 )
{
struct V_36 V_52 ;
T_2 V_12 ;
int V_3 ;
F_19 ( V_17 , V_35 , V_16 ) ;
F_20 ( V_17 ,
V_46 , V_35 ,
V_53 ,
& V_16 -> V_54 ) ;
F_20 ( V_17 ,
V_46 , V_35 ,
V_55 ,
& V_16 -> V_56 ) ;
F_20 ( V_17 ,
V_46 , V_35 ,
V_57 ,
& V_16 -> V_27 ) ;
V_16 -> V_29 = - 1 ;
F_20 ( V_17 ,
V_58 , V_35 ,
V_59 ,
& V_52 ) ;
if ( V_52 . V_20 >= 0 && V_52 . V_19 ) {
int V_30 , V_10 ;
F_16 ( V_59 ,
& V_52 , & V_30 , & V_10 ) ;
V_16 -> V_44 = V_30 ;
} else
V_16 -> V_44 = 1000000000 ;
F_21 ( V_17 , V_35 , V_16 ) ;
F_22 ( V_17 -> V_50 , L_2 ,
V_16 -> V_18 . V_20 , V_16 -> V_18 . V_19 ,
V_16 -> V_54 . V_20 , V_16 -> V_54 . V_19 ,
V_16 -> V_56 . V_20 , V_16 -> V_56 . V_19 ,
V_16 -> V_27 . V_20 , V_16 -> V_27 . V_19 ,
V_52 . V_20 , V_52 . V_19 ) ;
V_3 = F_9 ( V_17 ,
V_16 -> V_56 . V_19 ,
V_16 -> V_56 . V_20 , sizeof( V_12 ) , & V_12 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_12 < 0 )
return - V_21 ;
return 0 ;
}
