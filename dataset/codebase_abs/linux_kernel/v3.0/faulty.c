static void F_1 ( struct V_1 * V_1 , int error )
{
struct V_1 * V_2 = V_1 -> V_3 ;
V_2 -> V_4 = V_1 -> V_4 ;
V_2 -> V_5 = V_1 -> V_5 ;
F_2 ( V_1 ) ;
F_3 ( V_2 ) ;
}
static int F_4 ( T_1 * V_6 , int V_7 )
{
if ( V_6 -> V_8 [ V_7 ] == 0 &&
F_5 ( & V_6 -> V_9 [ V_7 ] ) <= 0 )
return 0 ;
if ( F_6 ( & V_6 -> V_9 [ V_7 ] ) ) {
if ( V_6 -> V_8 [ V_7 ] )
F_7 ( & V_6 -> V_9 [ V_7 ] , V_6 -> V_8 [ V_7 ] ) ;
return 1 ;
}
return 0 ;
}
static int F_8 ( T_1 * V_6 , T_2 V_10 , T_2 V_11 , int V_12 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < V_6 -> V_14 ; V_13 ++ )
if ( V_6 -> V_15 [ V_13 ] >= V_10 &&
V_6 -> V_15 [ V_13 ] < V_11 ) {
switch ( V_6 -> V_16 [ V_13 ] * 2 + V_12 ) {
case V_17 * 2 + V_18 : return 1 ;
case V_19 * 2 + V_20 : return 1 ;
case V_21 * 2 + V_20 : return 1 ;
case V_21 * 2 + V_18 :
V_6 -> V_16 [ V_13 ] = V_22 ;
return 0 ;
case V_23 * 2 + V_20 :
case V_23 * 2 + V_18 : return 1 ;
default:
return 0 ;
}
}
return 0 ;
}
static void F_9 ( T_1 * V_6 , T_2 V_10 , int V_7 )
{
int V_13 ;
int V_24 = V_6 -> V_14 ;
for ( V_13 = 0 ; V_13 < V_6 -> V_14 ; V_13 ++ )
if ( V_6 -> V_15 [ V_13 ] == V_10 ) {
switch( V_7 ) {
case V_22 : V_6 -> V_16 [ V_13 ] = V_7 ; return;
case V_17 :
if ( V_6 -> V_16 [ V_13 ] == V_19 ||
V_6 -> V_16 [ V_13 ] == V_21 )
V_6 -> V_16 [ V_13 ] = V_23 ;
else
V_6 -> V_16 [ V_13 ] = V_17 ;
return;
case V_19 :
if ( V_6 -> V_16 [ V_13 ] == V_17 )
V_6 -> V_16 [ V_13 ] = V_23 ;
else
V_6 -> V_16 [ V_13 ] = V_19 ;
return;
case V_21 :
if ( V_6 -> V_16 [ V_13 ] == V_17 ||
V_6 -> V_16 [ V_13 ] == V_19 )
V_6 -> V_16 [ V_13 ] = V_23 ;
else
V_6 -> V_16 [ V_13 ] = V_21 ;
return;
}
} else if ( V_6 -> V_16 [ V_13 ] == V_22 )
V_24 = V_13 ;
if ( V_24 >= V_25 )
return;
V_6 -> V_15 [ V_24 ] = V_10 ;
V_6 -> V_16 [ V_24 ] = V_7 ;
if ( V_6 -> V_14 == V_24 )
V_6 -> V_14 = V_24 + 1 ;
}
static int F_10 ( T_3 * V_26 , struct V_1 * V_1 )
{
T_1 * V_6 = V_26 -> V_27 ;
int V_28 = 0 ;
if ( F_11 ( V_1 ) == V_18 ) {
if ( F_5 ( & V_6 -> V_9 [ V_29 ] ) ) {
F_12 ( V_1 , - V_30 ) ;
return 0 ;
}
if ( F_8 ( V_6 , V_1 -> V_5 , V_1 -> V_5 + ( V_1 -> V_4 >> 9 ) ,
V_18 ) )
V_28 = 1 ;
if ( F_4 ( V_6 , V_17 ) ) {
F_9 ( V_6 , V_1 -> V_5 , V_17 ) ;
V_28 = 1 ;
}
if ( F_4 ( V_6 , V_31 ) )
V_28 = 1 ;
} else {
if ( F_8 ( V_6 , V_1 -> V_5 , V_1 -> V_5 + ( V_1 -> V_4 >> 9 ) ,
V_20 ) )
V_28 = 1 ;
if ( F_4 ( V_6 , V_32 ) )
V_28 = 1 ;
if ( F_4 ( V_6 , V_19 ) ) {
F_9 ( V_6 , V_1 -> V_5 , V_19 ) ;
V_28 = 1 ;
}
if ( F_4 ( V_6 , V_21 ) ) {
F_9 ( V_6 , V_1 -> V_5 , V_21 ) ;
V_28 = 1 ;
}
}
if ( V_28 ) {
struct V_1 * V_2 = F_13 ( V_1 , V_33 , V_26 ) ;
V_2 -> V_34 = V_6 -> V_35 -> V_36 ;
V_2 -> V_3 = V_1 ;
V_2 -> V_37 = F_1 ;
F_14 ( V_2 ) ;
return 0 ;
} else {
V_1 -> V_34 = V_6 -> V_35 -> V_36 ;
return 1 ;
}
}
static void F_15 ( struct V_38 * V_39 , T_3 * V_26 )
{
T_1 * V_6 = V_26 -> V_27 ;
int V_24 ;
if ( ( V_24 = F_5 ( & V_6 -> V_9 [ V_31 ] ) ) != 0 )
F_16 ( V_39 , L_1 ,
V_24 , V_6 -> V_8 [ V_31 ] ) ;
if ( ( V_24 = F_5 ( & V_6 -> V_9 [ V_32 ] ) ) != 0 )
F_16 ( V_39 , L_2 ,
V_24 , V_6 -> V_8 [ V_32 ] ) ;
if ( ( V_24 = F_5 ( & V_6 -> V_9 [ V_17 ] ) ) != 0 )
F_16 ( V_39 , L_3 ,
V_24 , V_6 -> V_8 [ V_17 ] ) ;
if ( ( V_24 = F_5 ( & V_6 -> V_9 [ V_19 ] ) ) != 0 )
F_16 ( V_39 , L_4 ,
V_24 , V_6 -> V_8 [ V_19 ] ) ;
if ( ( V_24 = F_5 ( & V_6 -> V_9 [ V_21 ] ) ) != 0 )
F_16 ( V_39 , L_5 ,
V_24 , V_6 -> V_8 [ V_21 ] ) ;
if ( ( V_24 = F_5 ( & V_6 -> V_9 [ V_29 ] ) ) != 0 )
F_16 ( V_39 , L_6 ) ;
F_16 ( V_39 , L_7 , V_6 -> V_14 ) ;
}
static int F_17 ( T_3 * V_26 )
{
int V_7 = V_26 -> V_40 & V_41 ;
int V_42 = V_26 -> V_40 >> V_43 ;
T_1 * V_6 = V_26 -> V_27 ;
if ( V_26 -> V_40 < 0 )
return 0 ;
if ( V_7 == V_44 )
V_6 -> V_14 = 0 ;
else if ( V_7 == V_45 ) {
int V_13 ;
for ( V_13 = 0 ; V_13 < V_46 ; V_13 ++ ) {
V_6 -> V_8 [ V_13 ] = 0 ;
F_7 ( & V_6 -> V_9 [ V_13 ] , 0 ) ;
}
} else if ( V_7 < V_46 ) {
V_6 -> V_8 [ V_7 ] = V_42 ;
if ( ! V_42 ) V_42 ++ ;
F_7 ( & V_6 -> V_9 [ V_7 ] , V_42 ) ;
} else
return - V_47 ;
V_26 -> V_40 = - 1 ;
V_26 -> V_48 = - 1 ;
return 0 ;
}
static T_2 F_18 ( T_3 * V_26 , T_2 V_49 , int V_50 )
{
F_19 ( V_50 ,
L_8 , V_51 ) ;
if ( V_49 == 0 )
return V_26 -> V_52 ;
return V_49 ;
}
static int F_20 ( T_3 * V_26 )
{
T_4 * V_35 ;
int V_13 ;
T_1 * V_6 ;
if ( F_21 ( V_26 ) )
return - V_47 ;
V_6 = F_22 ( sizeof( * V_6 ) , V_53 ) ;
if ( ! V_6 )
return - V_54 ;
for ( V_13 = 0 ; V_13 < V_46 ; V_13 ++ ) {
F_7 ( & V_6 -> V_9 [ V_13 ] , 0 ) ;
V_6 -> V_8 [ V_13 ] = 0 ;
}
V_6 -> V_14 = 0 ;
F_23 (rdev, &mddev->disks, same_set)
V_6 -> V_35 = V_35 ;
F_24 ( V_26 , F_18 ( V_26 , 0 , 0 ) ) ;
V_26 -> V_27 = V_6 ;
F_17 ( V_26 ) ;
return 0 ;
}
static int F_25 ( T_3 * V_26 )
{
T_1 * V_6 = V_26 -> V_27 ;
F_26 ( V_6 ) ;
V_26 -> V_27 = NULL ;
return 0 ;
}
static int T_5 F_27 ( void )
{
return F_28 ( & V_55 ) ;
}
static void F_29 ( void )
{
F_30 ( & V_55 ) ;
}
