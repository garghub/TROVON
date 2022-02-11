static void F_1 ( struct V_1 * V_1 , int error )
{
struct V_1 * V_2 = V_1 -> V_3 ;
V_2 -> V_4 = V_1 -> V_4 ;
V_2 -> V_5 = V_1 -> V_5 ;
F_2 ( V_1 ) ;
F_3 ( V_2 ) ;
}
static int F_4 ( struct V_6 * V_7 , int V_8 )
{
if ( V_7 -> V_9 [ V_8 ] == 0 &&
F_5 ( & V_7 -> V_10 [ V_8 ] ) <= 0 )
return 0 ;
if ( F_6 ( & V_7 -> V_10 [ V_8 ] ) ) {
if ( V_7 -> V_9 [ V_8 ] )
F_7 ( & V_7 -> V_10 [ V_8 ] , V_7 -> V_9 [ V_8 ] ) ;
return 1 ;
}
return 0 ;
}
static int F_8 ( struct V_6 * V_7 , T_1 V_11 , T_1 V_12 , int V_13 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < V_7 -> V_15 ; V_14 ++ )
if ( V_7 -> V_16 [ V_14 ] >= V_11 &&
V_7 -> V_16 [ V_14 ] < V_12 ) {
switch ( V_7 -> V_17 [ V_14 ] * 2 + V_13 ) {
case V_18 * 2 + V_19 : return 1 ;
case V_20 * 2 + V_21 : return 1 ;
case V_22 * 2 + V_21 : return 1 ;
case V_22 * 2 + V_19 :
V_7 -> V_17 [ V_14 ] = V_23 ;
return 0 ;
case V_24 * 2 + V_21 :
case V_24 * 2 + V_19 : return 1 ;
default:
return 0 ;
}
}
return 0 ;
}
static void F_9 ( struct V_6 * V_7 , T_1 V_11 , int V_8 )
{
int V_14 ;
int V_25 = V_7 -> V_15 ;
for ( V_14 = 0 ; V_14 < V_7 -> V_15 ; V_14 ++ )
if ( V_7 -> V_16 [ V_14 ] == V_11 ) {
switch( V_8 ) {
case V_23 : V_7 -> V_17 [ V_14 ] = V_8 ; return;
case V_18 :
if ( V_7 -> V_17 [ V_14 ] == V_20 ||
V_7 -> V_17 [ V_14 ] == V_22 )
V_7 -> V_17 [ V_14 ] = V_24 ;
else
V_7 -> V_17 [ V_14 ] = V_18 ;
return;
case V_20 :
if ( V_7 -> V_17 [ V_14 ] == V_18 )
V_7 -> V_17 [ V_14 ] = V_24 ;
else
V_7 -> V_17 [ V_14 ] = V_20 ;
return;
case V_22 :
if ( V_7 -> V_17 [ V_14 ] == V_18 ||
V_7 -> V_17 [ V_14 ] == V_20 )
V_7 -> V_17 [ V_14 ] = V_24 ;
else
V_7 -> V_17 [ V_14 ] = V_22 ;
return;
}
} else if ( V_7 -> V_17 [ V_14 ] == V_23 )
V_25 = V_14 ;
if ( V_25 >= V_26 )
return;
V_7 -> V_16 [ V_25 ] = V_11 ;
V_7 -> V_17 [ V_25 ] = V_8 ;
if ( V_7 -> V_15 == V_25 )
V_7 -> V_15 = V_25 + 1 ;
}
static void F_10 ( struct V_27 * V_27 , struct V_1 * V_1 )
{
struct V_6 * V_7 = V_27 -> V_28 ;
int V_29 = 0 ;
if ( F_11 ( V_1 ) == V_19 ) {
if ( F_5 ( & V_7 -> V_10 [ V_30 ] ) ) {
F_12 ( V_1 , - V_31 ) ;
return;
}
if ( F_8 ( V_7 , V_1 -> V_5 , V_1 -> V_5 + ( V_1 -> V_4 >> 9 ) ,
V_19 ) )
V_29 = 1 ;
if ( F_4 ( V_7 , V_18 ) ) {
F_9 ( V_7 , V_1 -> V_5 , V_18 ) ;
V_29 = 1 ;
}
if ( F_4 ( V_7 , V_32 ) )
V_29 = 1 ;
} else {
if ( F_8 ( V_7 , V_1 -> V_5 , V_1 -> V_5 + ( V_1 -> V_4 >> 9 ) ,
V_21 ) )
V_29 = 1 ;
if ( F_4 ( V_7 , V_33 ) )
V_29 = 1 ;
if ( F_4 ( V_7 , V_20 ) ) {
F_9 ( V_7 , V_1 -> V_5 , V_20 ) ;
V_29 = 1 ;
}
if ( F_4 ( V_7 , V_22 ) ) {
F_9 ( V_7 , V_1 -> V_5 , V_22 ) ;
V_29 = 1 ;
}
}
if ( V_29 ) {
struct V_1 * V_2 = F_13 ( V_1 , V_34 , V_27 ) ;
V_2 -> V_35 = V_7 -> V_36 -> V_37 ;
V_2 -> V_3 = V_1 ;
V_2 -> V_38 = F_1 ;
V_1 = V_2 ;
} else
V_1 -> V_35 = V_7 -> V_36 -> V_37 ;
F_14 ( V_1 ) ;
}
static void F_15 ( struct V_39 * V_40 , struct V_27 * V_27 )
{
struct V_6 * V_7 = V_27 -> V_28 ;
int V_25 ;
if ( ( V_25 = F_5 ( & V_7 -> V_10 [ V_32 ] ) ) != 0 )
F_16 ( V_40 , L_1 ,
V_25 , V_7 -> V_9 [ V_32 ] ) ;
if ( ( V_25 = F_5 ( & V_7 -> V_10 [ V_33 ] ) ) != 0 )
F_16 ( V_40 , L_2 ,
V_25 , V_7 -> V_9 [ V_33 ] ) ;
if ( ( V_25 = F_5 ( & V_7 -> V_10 [ V_18 ] ) ) != 0 )
F_16 ( V_40 , L_3 ,
V_25 , V_7 -> V_9 [ V_18 ] ) ;
if ( ( V_25 = F_5 ( & V_7 -> V_10 [ V_20 ] ) ) != 0 )
F_16 ( V_40 , L_4 ,
V_25 , V_7 -> V_9 [ V_20 ] ) ;
if ( ( V_25 = F_5 ( & V_7 -> V_10 [ V_22 ] ) ) != 0 )
F_16 ( V_40 , L_5 ,
V_25 , V_7 -> V_9 [ V_22 ] ) ;
if ( ( V_25 = F_5 ( & V_7 -> V_10 [ V_30 ] ) ) != 0 )
F_16 ( V_40 , L_6 ) ;
F_16 ( V_40 , L_7 , V_7 -> V_15 ) ;
}
static int F_17 ( struct V_27 * V_27 )
{
int V_8 = V_27 -> V_41 & V_42 ;
int V_43 = V_27 -> V_41 >> V_44 ;
struct V_6 * V_7 = V_27 -> V_28 ;
if ( V_27 -> V_41 < 0 )
return 0 ;
if ( V_8 == V_45 )
V_7 -> V_15 = 0 ;
else if ( V_8 == V_46 ) {
int V_14 ;
for ( V_14 = 0 ; V_14 < V_47 ; V_14 ++ ) {
V_7 -> V_9 [ V_14 ] = 0 ;
F_7 ( & V_7 -> V_10 [ V_14 ] , 0 ) ;
}
} else if ( V_8 < V_47 ) {
V_7 -> V_9 [ V_8 ] = V_43 ;
if ( ! V_43 ) V_43 ++ ;
F_7 ( & V_7 -> V_10 [ V_8 ] , V_43 ) ;
} else
return - V_48 ;
V_27 -> V_41 = - 1 ;
V_27 -> V_49 = - 1 ;
return 0 ;
}
static T_1 F_18 ( struct V_27 * V_27 , T_1 V_50 , int V_51 )
{
F_19 ( V_51 ,
L_8 , V_52 ) ;
if ( V_50 == 0 )
return V_27 -> V_53 ;
return V_50 ;
}
static int F_20 ( struct V_27 * V_27 )
{
struct V_54 * V_36 ;
int V_14 ;
struct V_6 * V_7 ;
if ( F_21 ( V_27 ) )
return - V_48 ;
V_7 = F_22 ( sizeof( * V_7 ) , V_55 ) ;
if ( ! V_7 )
return - V_56 ;
for ( V_14 = 0 ; V_14 < V_47 ; V_14 ++ ) {
F_7 ( & V_7 -> V_10 [ V_14 ] , 0 ) ;
V_7 -> V_9 [ V_14 ] = 0 ;
}
V_7 -> V_15 = 0 ;
F_23 (rdev, mddev)
V_7 -> V_36 = V_36 ;
F_24 ( V_27 , F_18 ( V_27 , 0 , 0 ) ) ;
V_27 -> V_28 = V_7 ;
F_17 ( V_27 ) ;
return 0 ;
}
static int F_25 ( struct V_27 * V_27 )
{
struct V_6 * V_7 = V_27 -> V_28 ;
F_26 ( V_7 ) ;
V_27 -> V_28 = NULL ;
return 0 ;
}
static int T_2 F_27 ( void )
{
return F_28 ( & V_57 ) ;
}
static void F_29 ( void )
{
F_30 ( & V_57 ) ;
}
