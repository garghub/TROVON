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
V_3 = - V_21 ;
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
V_3 = - V_21 ;
return V_3 ;
}
int F_13 ( struct V_15 * V_16 ,
int * V_10 , int * V_11 )
{
T_2 V_12 ;
int V_3 ;
V_3 = F_9 ( V_16 -> V_17 ,
V_16 -> V_26 . V_19 ,
V_16 -> V_26 . V_20 , sizeof( V_12 ) ,
& V_12 ) ;
if ( V_3 < 0 || V_12 < 0 ) {
* V_10 = * V_11 = 0 ;
return - V_21 ;
} else {
F_4 ( V_12 , V_16 -> V_26 . V_13 ,
V_16 -> V_26 . V_27 ,
V_10 , V_11 ) ;
}
return V_25 ;
}
int F_14 ( struct V_15 * V_16 ,
int V_10 , int V_11 )
{
T_2 V_12 ;
int V_3 ;
V_12 = F_7 ( V_16 -> V_26 . V_13 ,
V_16 -> V_26 . V_27 ,
V_10 , V_11 ) ;
V_3 = F_12 ( V_16 -> V_17 , V_16 -> V_26 . V_19 ,
V_16 -> V_26 . V_20 , sizeof( V_12 ) ,
& V_12 ) ;
if ( V_3 < 0 || V_12 < 0 )
V_3 = - V_21 ;
return V_3 ;
}
static void F_15 ( int * V_28 , int * V_10 , int V_29 ,
int V_30 , int exp )
{
int V_2 ;
int V_31 ;
int V_32 ;
int V_8 ;
if ( exp > 0 ) {
* V_28 = V_29 * F_1 ( exp ) ;
V_32 = 0 ;
if ( exp > 9 ) {
* V_10 = 0 ;
return;
}
for ( V_2 = 0 ; V_2 < exp ; ++ V_2 ) {
V_31 = V_30 / F_1 ( 8 - V_2 ) ;
V_32 += ( F_1 ( exp - 1 - V_2 ) * V_31 ) ;
V_30 = V_30 % F_1 ( 8 - V_2 ) ;
}
* V_28 += V_32 ;
* V_10 = V_30 * F_1 ( exp ) ;
} else if ( exp < 0 ) {
exp = abs ( exp ) ;
if ( exp > 9 ) {
* V_28 = * V_10 = 0 ;
return;
}
* V_28 = V_29 / F_1 ( exp ) ;
V_8 = V_29 % F_1 ( exp ) ;
V_32 = 0 ;
for ( V_2 = 0 ; V_2 < ( 9 - exp ) ; ++ V_2 ) {
V_31 = V_30 / F_1 ( 8 - V_2 ) ;
V_32 += ( F_1 ( 8 - exp - V_2 ) * V_31 ) ;
V_30 = V_30 % F_1 ( 8 - V_2 ) ;
}
* V_10 = V_8 * F_1 ( 9 - exp ) + V_32 ;
} else {
* V_28 = V_29 ;
* V_10 = V_30 ;
}
}
int F_16 ( T_1 V_33 ,
struct V_34 * V_35 ,
int * V_28 , int * V_10 )
{
int V_2 ;
int exp ;
* V_28 = 1 ;
* V_10 = 0 ;
for ( V_2 = 0 ; V_2 < F_17 ( V_36 ) ; ++ V_2 ) {
if ( V_36 [ V_2 ] . V_33 == V_33 &&
V_36 [ V_2 ] . V_37 == V_35 -> V_22 ) {
exp = F_6 (
V_35 -> V_27 ) ;
F_15 ( V_28 , V_10 ,
V_36 [ V_2 ] . V_38 ,
V_36 [ V_2 ] . V_39 , exp ) ;
break;
}
}
return V_40 ;
}
static
int F_18 ( struct V_41 * V_17 ,
T_1 V_33 ,
struct V_15 * V_16 )
{
F_19 ( V_17 ,
V_42 , V_33 ,
V_43 ,
& V_16 -> V_18 ) ;
if ( V_16 -> V_18 . V_22 == 0 )
V_16 -> V_18 . V_22 = V_24 ;
return 0 ;
}
int F_20 ( struct V_41 * V_17 ,
T_1 V_33 ,
struct V_15 * V_16 )
{
F_18 ( V_17 , V_33 , V_16 ) ;
F_19 ( V_17 ,
V_42 , V_33 ,
V_44 ,
& V_16 -> V_45 ) ;
F_19 ( V_17 ,
V_42 , V_33 ,
V_46 ,
& V_16 -> V_47 ) ;
F_19 ( V_17 ,
V_42 , V_33 ,
V_48 ,
& V_16 -> V_26 ) ;
F_21 ( V_17 -> V_49 , L_1 ,
V_16 -> V_18 . V_20 , V_16 -> V_18 . V_19 ,
V_16 -> V_45 . V_20 , V_16 -> V_45 . V_19 ,
V_16 -> V_47 . V_20 , V_16 -> V_47 . V_19 ,
V_16 -> V_26 . V_20 , V_16 -> V_26 . V_19 ) ;
return 0 ;
}
