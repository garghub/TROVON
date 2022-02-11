static void F_1 ( T_1 * V_1 , T_1 V_2 , T_2 V_3 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 - V_2 % 4 ; V_4 += 4 )
F_2 ( * ( T_2 * ) ( V_1 + V_4 ) , V_3 + V_4 ) ;
for (; V_4 < V_2 ; ++ V_4 )
F_3 ( * ( V_1 + V_4 ) , V_3 + V_4 ) ;
}
static void F_4 ( T_1 * V_1 , T_1 V_2 , T_2 V_3 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 - V_2 % 4 ; V_4 += 4 )
* ( T_2 * ) ( V_1 + V_4 ) = F_5 ( V_3 + V_4 ) ;
for (; V_4 < V_2 ; ++ V_4 )
* ( V_1 + V_4 ) = F_6 ( V_3 + V_4 ) ;
}
static void F_7 ( struct V_5 * V_6 , T_1 V_7 ,
T_1 * V_1 , T_1 V_8 )
{
T_2 V_3 = V_6 -> V_9 + V_7 ;
switch ( V_8 ) {
case 1 :
* ( V_1 ) = F_6 ( V_3 ) ;
break;
case 2 :
* ( ( V_10 * ) V_1 ) = F_8 ( V_3 ) ;
break;
case 3 :
* ( ( V_10 * ) V_1 ) = F_8 ( V_3 ) ;
* ( V_1 + 2 ) = F_6 ( V_3 + 2 ) ;
break;
case 4 :
* ( ( T_2 * ) V_1 ) = F_5 ( V_3 ) ;
break;
default:
F_4 ( V_1 , V_8 , V_3 ) ;
break;
}
}
static void F_9 ( struct V_5 * V_6 , T_1 V_7 ,
T_1 * V_1 , T_1 V_8 )
{
T_2 V_3 = V_6 -> V_9 + V_7 ;
switch ( V_8 ) {
case 1 :
F_3 ( * ( V_1 ) , V_3 ) ;
break;
case 2 :
F_10 ( * ( ( V_10 * ) V_1 ) , V_3 ) ;
break;
case 3 :
F_10 ( * ( ( V_10 * ) V_1 ) , V_3 ) ;
F_3 ( * ( V_1 + 2 ) , V_3 + 2 ) ;
break;
case 4 :
F_2 ( * ( ( T_2 * ) V_1 ) , V_3 ) ;
break;
default:
F_1 ( V_1 , V_8 , V_3 ) ;
break;
}
}
static int F_11 ( struct V_5 * V_6 ,
struct V_11 * V_12 , int V_13 )
{
int V_4 ;
if ( ! V_13 ) {
F_12 ( V_6 -> V_14 , L_1 ) ;
return - V_15 ;
}
if ( F_13 ( V_12 [ 0 ] . V_3 > 0x7f ) ) {
F_12 ( V_6 -> V_14 , L_2 ,
V_12 [ 0 ] . V_3 ) ;
return - V_15 ;
}
for ( V_4 = 0 ; V_4 < V_13 ; ++ V_4 ) {
if ( F_13 ( ! V_12 [ V_4 ] . V_16 ) ) {
F_12 ( V_6 -> V_14 , L_3 ,
V_4 ) ;
return - V_15 ;
}
if ( F_13 ( V_12 [ 0 ] . V_3 != V_12 [ V_4 ] . V_3 ) ) {
F_12 ( V_6 -> V_14 , L_4 ,
V_4 ) ;
return - V_15 ;
}
}
return 0 ;
}
static int F_14 ( struct V_5 * V_6 , int * V_17 )
{
T_1 V_18 ;
F_7 ( V_6 , V_19 , & V_18 , 1 ) ;
if ( V_18 & V_20 ) {
if ( V_18 & V_21 )
* V_17 = V_22 ;
else
* V_17 = V_23 ;
return 0 ;
}
* V_17 = V_24 ;
return - V_25 ;
}
static void F_15 ( struct V_5 * V_6 ,
struct V_11 * V_12 , int V_13 ,
T_1 V_26 )
{
V_6 -> V_27 . V_28 = V_12 ;
V_6 -> V_27 . V_29 = V_13 ;
V_6 -> V_27 . V_30 = V_12 [ V_13 - 1 ] . V_31 & V_32 ;
if ( V_6 -> V_27 . V_30 == V_32 && V_26 != V_12 [ 0 ] . V_2 ) {
V_6 -> V_27 . V_33 = V_12 [ 0 ] . V_2 ;
V_6 -> V_27 . V_34 = V_26 - V_6 -> V_27 . V_33 ;
} else {
V_6 -> V_27 . V_33 = 0 ;
V_6 -> V_27 . V_34 = V_26 ;
}
}
static void F_16 ( struct V_5 * V_6 )
{
T_1 V_18 ;
F_17 ( & V_6 -> V_35 ) ;
F_7 ( V_6 , V_36 , & V_18 , 1 ) ;
V_18 &= ~ V_37 ;
F_9 ( V_6 , V_36 , & V_18 , 1 ) ;
F_18 ( & V_6 -> V_35 ) ;
}
static int F_19 ( struct V_5 * V_6 )
{
T_1 V_18 ;
F_7 ( V_6 , V_19 , & V_18 , 1 ) ;
if ( V_18 & V_20 )
return 0 ;
return - V_25 ;
}
static int F_20 ( struct V_5 * V_6 )
{
int V_38 = 0 ;
do {
if ( ! F_19 ( V_6 ) )
break;
F_21 ( V_39 / 2 , V_39 ) ;
V_38 += V_39 ;
} while ( V_38 <= V_40 );
if ( V_38 > V_40 )
return - V_41 ;
return 0 ;
}
static int F_22 ( struct V_5 * V_6 )
{
int V_17 , V_4 , V_38 = 0 ;
T_1 V_8 ;
do {
F_21 ( V_39 / 2 , V_39 ) ;
if ( ! F_14 ( V_6 , & V_17 ) )
break;
V_38 += V_39 ;
} while ( V_17 == 0 && V_38 < V_40 );
switch ( V_17 ) {
case V_24 :
return - V_41 ;
case V_23 :
if ( V_6 -> V_27 . V_30 != V_32 )
return ( V_6 -> V_27 . V_33 + V_6 -> V_27 . V_34 ) ;
if ( V_6 -> V_27 . V_29 == 1 )
V_4 = 0 ;
else
V_4 = 1 ;
if ( ! V_6 -> V_27 . V_28 [ V_4 ] . V_16 )
return - V_15 ;
V_8 = V_6 -> V_27 . V_34 ;
F_7 ( V_6 , V_42 ,
V_6 -> V_27 . V_28 [ V_4 ] . V_16 , V_8 ) ;
return V_8 ;
case V_22 :
return - V_43 ;
default:
return - V_15 ;
}
}
static void F_23 ( struct V_5 * V_6 )
{
int V_4 , V_2 = 0 ;
T_1 V_30 ;
F_9 ( V_6 , V_44 ,
& V_6 -> V_27 . V_34 , 1 ) ;
F_9 ( V_6 , V_45 ,
& V_6 -> V_27 . V_33 , 1 ) ;
for ( V_4 = 0 ; V_4 < V_6 -> V_27 . V_29 ; V_4 ++ ) {
if ( ( V_6 -> V_27 . V_28 [ V_4 ] . V_31 & V_32 ) != V_32 ) {
F_9 ( V_6 , V_42 +
V_2 , V_6 -> V_27 . V_28 [ V_4 ] . V_16 ,
V_6 -> V_27 . V_28 [ V_4 ] . V_2 ) ;
V_2 += V_6 -> V_27 . V_28 [ V_4 ] . V_2 ;
}
}
V_30 = ( V_6 -> V_27 . V_28 [ 0 ] . V_3 << 1 ) | V_6 -> V_27 . V_30 ;
F_9 ( V_6 , V_46 , & V_30 , 1 ) ;
}
static int F_24 ( struct V_47 * V_48 , struct V_11 * V_12 ,
int V_13 )
{
struct V_5 * V_6 = F_25 ( V_48 ) ;
T_1 V_26 = 0 ;
int V_4 , V_49 ;
V_49 = F_11 ( V_6 , V_12 , V_13 ) ;
if ( V_49 ) {
F_12 ( V_6 -> V_14 , L_5 ) ;
return V_49 ;
}
for ( V_4 = 0 ; V_4 < V_13 ; ++ V_4 )
V_26 += V_12 [ V_4 ] . V_2 ;
if ( F_20 ( V_6 ) ) {
F_12 ( V_6 -> V_14 , L_6 ) ;
F_16 ( V_6 ) ;
if ( F_19 ( V_6 ) ) {
F_12 ( V_6 -> V_14 , L_7 ) ;
return - V_25 ;
}
}
F_15 ( V_6 , V_12 , V_13 , V_26 ) ;
F_17 ( & V_6 -> V_35 ) ;
F_23 ( V_6 ) ;
V_49 = F_22 ( V_6 ) ;
F_18 ( & V_6 -> V_35 ) ;
return V_49 < 0 ? V_49 : V_13 ;
}
static T_2 F_26 ( struct V_47 * V_48 )
{
return V_50 | V_51 | V_52 ;
}
static int F_27 ( struct V_53 * V_54 )
{
struct V_5 * V_6 ;
int V_49 ;
V_6 = F_28 ( & V_54 -> V_14 , sizeof( * V_6 ) , V_55 ) ;
if ( ! V_6 )
return - V_56 ;
F_29 ( & V_6 -> V_35 ) ;
F_30 ( V_54 , V_6 ) ;
V_6 -> V_14 = & V_54 -> V_14 ;
V_57 . V_38 = F_31 ( V_40 ) ;
V_6 -> V_48 = V_57 ;
V_6 -> V_48 . V_14 . V_58 = & V_54 -> V_14 ;
V_6 -> V_9 = V_59 ;
F_32 ( & V_6 -> V_48 , V_6 ) ;
V_49 = F_33 ( & V_6 -> V_48 ) ;
if ( V_49 )
F_34 ( & V_6 -> V_35 ) ;
return V_49 ;
}
static int F_35 ( struct V_53 * V_54 )
{
struct V_5 * V_6 = F_36 ( V_54 ) ;
F_37 ( & V_6 -> V_48 ) ;
F_34 ( & V_6 -> V_35 ) ;
return 0 ;
}
