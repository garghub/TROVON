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
int F_8 ( struct V_15 * V_16 ,
int * V_10 , int * V_11 )
{
T_2 V_12 ;
int V_3 ;
V_3 = F_9 ( V_16 -> V_17 ,
V_16 -> V_18 . V_19 ,
V_16 -> V_18 . V_20 , & V_12 ) ;
if ( V_3 < 0 || V_12 < 0 ) {
* V_10 = * V_11 = 0 ;
return - V_21 ;
} else {
if ( V_16 -> V_18 . V_22 == V_23 )
F_2 ( 1000 , V_12 , V_10 , V_11 ) ;
else if ( V_16 -> V_18 . V_22 == V_24 )
F_2 ( 1 , V_12 , V_10 , V_11 ) ;
else {
* V_10 = * V_11 = 0 ;
return - V_21 ;
}
}
return V_25 ;
}
int F_10 ( struct V_15 * V_16 ,
int V_10 , int V_11 )
{
T_2 V_12 ;
int V_3 ;
if ( V_10 < 0 || V_11 < 0 )
V_3 = - V_21 ;
V_12 = V_10 * F_1 ( 6 ) + V_11 ;
if ( V_12 ) {
if ( V_16 -> V_18 . V_22 == V_23 )
V_12 = F_1 ( 9 ) / V_12 ;
else if ( V_16 -> V_18 . V_22 == V_24 )
V_12 = F_1 ( 6 ) / V_12 ;
else
V_12 = 0 ;
}
V_3 = F_11 ( V_16 -> V_17 ,
V_16 -> V_18 . V_19 ,
V_16 -> V_18 . V_20 , V_12 ) ;
if ( V_3 < 0 || V_12 < 0 )
V_3 = - V_21 ;
return V_3 ;
}
int F_12 ( struct V_15 * V_16 ,
int * V_10 , int * V_11 )
{
T_2 V_12 ;
int V_3 ;
V_3 = F_9 ( V_16 -> V_17 ,
V_16 -> V_26 . V_19 ,
V_16 -> V_26 . V_20 , & V_12 ) ;
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
int F_13 ( struct V_15 * V_16 ,
int V_10 , int V_11 )
{
T_2 V_12 ;
int V_3 ;
V_12 = F_7 ( V_16 -> V_26 . V_13 ,
V_16 -> V_26 . V_27 ,
V_10 , V_11 ) ;
V_3 = F_11 ( V_16 -> V_17 ,
V_16 -> V_26 . V_19 ,
V_16 -> V_26 . V_20 , V_12 ) ;
if ( V_3 < 0 || V_12 < 0 )
V_3 = - V_21 ;
return V_3 ;
}
int F_14 ( struct V_28 * V_17 ,
T_1 V_29 ,
struct V_15 * V_16 )
{
F_15 ( V_17 ,
V_30 , V_29 ,
V_31 ,
& V_16 -> V_18 ) ;
F_15 ( V_17 ,
V_30 , V_29 ,
V_32 ,
& V_16 -> V_33 ) ;
F_15 ( V_17 ,
V_30 , V_29 ,
V_34 ,
& V_16 -> V_35 ) ;
F_15 ( V_17 ,
V_30 , V_29 ,
V_36 ,
& V_16 -> V_26 ) ;
F_16 ( V_17 -> V_37 , L_1 ,
V_16 -> V_18 . V_20 , V_16 -> V_18 . V_19 ,
V_16 -> V_33 . V_20 , V_16 -> V_33 . V_19 ,
V_16 -> V_35 . V_20 , V_16 -> V_35 . V_19 ,
V_16 -> V_26 . V_20 , V_16 -> V_26 . V_19 ) ;
return 0 ;
}
