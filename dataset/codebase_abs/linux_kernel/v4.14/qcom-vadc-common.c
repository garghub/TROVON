static int F_1 ( const struct V_1 * V_2 ,
T_1 V_3 , T_2 V_4 , T_3 * V_5 )
{
bool V_6 = 1 ;
T_1 V_7 = 0 ;
if ( ! V_2 )
return - V_8 ;
if ( V_3 > 1 ) {
if ( V_2 [ 0 ] . V_9 < V_2 [ 1 ] . V_9 )
V_6 = 0 ;
}
while ( V_7 < V_3 ) {
if ( ( V_6 ) && ( V_2 [ V_7 ] . V_9 < V_4 ) ) {
break;
} else if ( ( ! V_6 ) &&
( V_2 [ V_7 ] . V_9 > V_4 ) ) {
break;
}
V_7 ++ ;
}
if ( V_7 == 0 ) {
* V_5 = V_2 [ 0 ] . V_10 ;
} else if ( V_7 == V_3 ) {
* V_5 = V_2 [ V_3 - 1 ] . V_10 ;
} else {
* V_5 = ( ( ( T_2 ) ( ( V_2 [ V_7 ] . V_10 - V_2 [ V_7 - 1 ] . V_10 ) *
( V_4 - V_2 [ V_7 - 1 ] . V_9 ) ) /
( V_2 [ V_7 ] . V_9 - V_2 [ V_7 - 1 ] . V_9 ) ) +
V_2 [ V_7 - 1 ] . V_10 ) ;
}
return 0 ;
}
static void F_2 ( const struct V_11 * V_12 ,
T_4 V_13 ,
bool V_14 ,
T_3 * V_15 )
{
* V_15 = ( V_13 - V_12 -> V_16 ) ;
* V_15 *= V_12 -> V_17 ;
* V_15 = F_3 ( * V_15 , V_12 -> V_18 ) ;
if ( V_14 )
* V_15 += V_12 -> V_17 ;
if ( * V_15 < 0 )
* V_15 = 0 ;
}
static int F_4 ( const struct V_11 * V_12 ,
const struct V_19 * V_20 ,
bool V_14 , T_4 V_13 ,
int * V_21 )
{
T_3 V_22 = 0 , V_23 = 0 ;
F_2 ( V_12 , V_13 , V_14 , & V_22 ) ;
V_22 = V_22 * V_20 -> V_24 ;
V_23 = F_3 ( V_22 , V_20 -> V_25 ) ;
* V_21 = V_23 ;
return 0 ;
}
static int F_5 ( const struct V_11 * V_12 ,
const struct V_19 * V_20 ,
bool V_14 , T_4 V_13 ,
int * V_26 )
{
T_3 V_22 = 0 , V_23 = 0 ;
int V_27 ;
F_2 ( V_12 , V_13 , V_14 , & V_22 ) ;
if ( V_14 )
V_22 = F_3 ( V_22 , 1000 ) ;
V_27 = F_1 ( V_28 ,
F_6 ( V_28 ) ,
V_22 , & V_23 ) ;
if ( V_27 )
return V_27 ;
V_23 *= 1000 ;
* V_26 = V_23 ;
return 0 ;
}
static int F_7 ( const struct V_11 * V_12 ,
const struct V_19 * V_20 ,
bool V_14 ,
T_4 V_13 , int * V_26 )
{
T_3 V_22 = 0 ;
T_5 V_29 ;
F_2 ( V_12 , V_13 , V_14 , & V_22 ) ;
if ( V_22 > 0 ) {
V_29 = V_22 * V_20 -> V_24 ;
F_8 ( V_29 , V_20 -> V_25 * 2 ) ;
V_22 = V_29 ;
} else {
V_22 = 0 ;
}
V_22 -= V_30 ;
* V_26 = V_22 ;
return 0 ;
}
static int F_9 ( const struct V_11 * V_12 ,
const struct V_19 * V_20 ,
bool V_14 ,
T_4 V_13 , int * V_26 )
{
T_3 V_22 = 0 , V_23 = 0 ;
F_2 ( V_12 , V_13 , V_14 , & V_22 ) ;
V_22 = V_22 * V_20 -> V_24 ;
V_22 = F_3 ( V_22 , V_20 -> V_25 ) ;
V_22 = ( ( V_31 ) * ( V_22 * 2 ) ) ;
V_22 = ( V_22 + V_32 ) ;
V_23 = F_3 ( V_22 , 1000000 ) ;
* V_26 = V_23 ;
return 0 ;
}
int F_10 ( enum V_33 V_34 ,
const struct V_11 * V_12 ,
const struct V_19 * V_20 ,
bool V_14 ,
T_4 V_13 , int * V_23 )
{
switch ( V_34 ) {
case V_35 :
return F_4 ( V_12 , V_20 ,
V_14 , V_13 ,
V_23 ) ;
case V_36 :
case V_37 :
return F_5 ( V_12 , V_20 ,
V_14 , V_13 ,
V_23 ) ;
case V_38 :
return F_7 ( V_12 , V_20 ,
V_14 , V_13 ,
V_23 ) ;
case V_39 :
return F_9 ( V_12 , V_20 ,
V_14 , V_13 ,
V_23 ) ;
default:
return - V_8 ;
}
}
int F_11 ( T_1 V_40 )
{
if ( ! F_12 ( V_40 ) || V_40 < V_41 ||
V_40 > V_42 )
return - V_8 ;
return F_13 ( V_40 / V_41 ) ;
}
