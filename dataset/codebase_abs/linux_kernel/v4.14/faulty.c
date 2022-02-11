static void F_1 ( struct V_1 * V_1 )
{
struct V_1 * V_2 = V_1 -> V_3 ;
V_2 -> V_4 . V_5 = V_1 -> V_4 . V_5 ;
V_2 -> V_4 . V_6 = V_1 -> V_4 . V_6 ;
F_2 ( V_1 ) ;
F_3 ( V_2 ) ;
}
static int F_4 ( struct V_7 * V_8 , int V_9 )
{
if ( V_8 -> V_10 [ V_9 ] == 0 &&
F_5 ( & V_8 -> V_11 [ V_9 ] ) <= 0 )
return 0 ;
if ( F_6 ( & V_8 -> V_11 [ V_9 ] ) ) {
if ( V_8 -> V_10 [ V_9 ] )
F_7 ( & V_8 -> V_11 [ V_9 ] , V_8 -> V_10 [ V_9 ] ) ;
return 1 ;
}
return 0 ;
}
static int F_8 ( struct V_7 * V_8 , T_1 V_12 , T_1 V_13 , int V_14 )
{
int V_15 ;
for ( V_15 = 0 ; V_15 < V_8 -> V_16 ; V_15 ++ )
if ( V_8 -> V_17 [ V_15 ] >= V_12 &&
V_8 -> V_17 [ V_15 ] < V_13 ) {
switch ( V_8 -> V_18 [ V_15 ] * 2 + V_14 ) {
case V_19 * 2 + V_20 : return 1 ;
case V_21 * 2 + V_22 : return 1 ;
case V_23 * 2 + V_22 : return 1 ;
case V_23 * 2 + V_20 :
V_8 -> V_18 [ V_15 ] = V_24 ;
return 0 ;
case V_25 * 2 + V_22 :
case V_25 * 2 + V_20 : return 1 ;
default:
return 0 ;
}
}
return 0 ;
}
static void F_9 ( struct V_7 * V_8 , T_1 V_12 , int V_9 )
{
int V_15 ;
int V_26 = V_8 -> V_16 ;
for ( V_15 = 0 ; V_15 < V_8 -> V_16 ; V_15 ++ )
if ( V_8 -> V_17 [ V_15 ] == V_12 ) {
switch( V_9 ) {
case V_24 : V_8 -> V_18 [ V_15 ] = V_9 ; return;
case V_19 :
if ( V_8 -> V_18 [ V_15 ] == V_21 ||
V_8 -> V_18 [ V_15 ] == V_23 )
V_8 -> V_18 [ V_15 ] = V_25 ;
else
V_8 -> V_18 [ V_15 ] = V_19 ;
return;
case V_21 :
if ( V_8 -> V_18 [ V_15 ] == V_19 )
V_8 -> V_18 [ V_15 ] = V_25 ;
else
V_8 -> V_18 [ V_15 ] = V_21 ;
return;
case V_23 :
if ( V_8 -> V_18 [ V_15 ] == V_19 ||
V_8 -> V_18 [ V_15 ] == V_21 )
V_8 -> V_18 [ V_15 ] = V_25 ;
else
V_8 -> V_18 [ V_15 ] = V_23 ;
return;
}
} else if ( V_8 -> V_18 [ V_15 ] == V_24 )
V_26 = V_15 ;
if ( V_26 >= V_27 )
return;
V_8 -> V_17 [ V_26 ] = V_12 ;
V_8 -> V_18 [ V_26 ] = V_9 ;
if ( V_8 -> V_16 == V_26 )
V_8 -> V_16 = V_26 + 1 ;
}
static bool F_10 ( struct V_28 * V_28 , struct V_1 * V_1 )
{
struct V_7 * V_8 = V_28 -> V_29 ;
int V_30 = 0 ;
if ( F_11 ( V_1 ) == V_20 ) {
if ( F_5 ( & V_8 -> V_11 [ V_31 ] ) ) {
F_3 ( V_1 ) ;
return true ;
}
if ( F_8 ( V_8 , V_1 -> V_4 . V_6 ,
F_12 ( V_1 ) , V_20 ) )
V_30 = 1 ;
if ( F_4 ( V_8 , V_19 ) ) {
F_9 ( V_8 , V_1 -> V_4 . V_6 ,
V_19 ) ;
V_30 = 1 ;
}
if ( F_4 ( V_8 , V_32 ) )
V_30 = 1 ;
} else {
if ( F_8 ( V_8 , V_1 -> V_4 . V_6 ,
F_12 ( V_1 ) , V_22 ) )
V_30 = 1 ;
if ( F_4 ( V_8 , V_33 ) )
V_30 = 1 ;
if ( F_4 ( V_8 , V_21 ) ) {
F_9 ( V_8 , V_1 -> V_4 . V_6 ,
V_21 ) ;
V_30 = 1 ;
}
if ( F_4 ( V_8 , V_23 ) ) {
F_9 ( V_8 , V_1 -> V_4 . V_6 ,
V_23 ) ;
V_30 = 1 ;
}
}
if ( V_30 ) {
struct V_1 * V_2 = F_13 ( V_1 , V_34 , V_28 -> V_35 ) ;
F_14 ( V_2 , V_8 -> V_36 -> V_37 ) ;
V_2 -> V_3 = V_1 ;
V_2 -> V_38 = F_1 ;
V_1 = V_2 ;
} else
F_14 ( V_1 , V_8 -> V_36 -> V_37 ) ;
F_15 ( V_1 ) ;
return true ;
}
static void F_16 ( struct V_39 * V_40 , struct V_28 * V_28 )
{
struct V_7 * V_8 = V_28 -> V_29 ;
int V_26 ;
if ( ( V_26 = F_5 ( & V_8 -> V_11 [ V_32 ] ) ) != 0 )
F_17 ( V_40 , L_1 ,
V_26 , V_8 -> V_10 [ V_32 ] ) ;
if ( ( V_26 = F_5 ( & V_8 -> V_11 [ V_33 ] ) ) != 0 )
F_17 ( V_40 , L_2 ,
V_26 , V_8 -> V_10 [ V_33 ] ) ;
if ( ( V_26 = F_5 ( & V_8 -> V_11 [ V_19 ] ) ) != 0 )
F_17 ( V_40 , L_3 ,
V_26 , V_8 -> V_10 [ V_19 ] ) ;
if ( ( V_26 = F_5 ( & V_8 -> V_11 [ V_21 ] ) ) != 0 )
F_17 ( V_40 , L_4 ,
V_26 , V_8 -> V_10 [ V_21 ] ) ;
if ( ( V_26 = F_5 ( & V_8 -> V_11 [ V_23 ] ) ) != 0 )
F_17 ( V_40 , L_5 ,
V_26 , V_8 -> V_10 [ V_23 ] ) ;
if ( ( V_26 = F_5 ( & V_8 -> V_11 [ V_31 ] ) ) != 0 )
F_17 ( V_40 , L_6 ) ;
F_17 ( V_40 , L_7 , V_8 -> V_16 ) ;
}
static int F_18 ( struct V_28 * V_28 )
{
int V_9 = V_28 -> V_41 & V_42 ;
int V_43 = V_28 -> V_41 >> V_44 ;
struct V_7 * V_8 = V_28 -> V_29 ;
if ( V_28 -> V_41 < 0 )
return 0 ;
if ( V_9 == V_45 )
V_8 -> V_16 = 0 ;
else if ( V_9 == V_46 ) {
int V_15 ;
for ( V_15 = 0 ; V_15 < V_47 ; V_15 ++ ) {
V_8 -> V_10 [ V_15 ] = 0 ;
F_7 ( & V_8 -> V_11 [ V_15 ] , 0 ) ;
}
} else if ( V_9 < V_47 ) {
V_8 -> V_10 [ V_9 ] = V_43 ;
if ( ! V_43 ) V_43 ++ ;
F_7 ( & V_8 -> V_11 [ V_9 ] , V_43 ) ;
} else
return - V_48 ;
V_28 -> V_41 = - 1 ;
V_28 -> V_49 = - 1 ;
return 0 ;
}
static T_1 F_19 ( struct V_28 * V_28 , T_1 V_50 , int V_51 )
{
F_20 ( V_51 ,
L_8 , V_52 ) ;
if ( V_50 == 0 )
return V_28 -> V_53 ;
return V_50 ;
}
static int F_21 ( struct V_28 * V_28 )
{
struct V_54 * V_36 ;
int V_15 ;
struct V_7 * V_8 ;
if ( F_22 ( V_28 ) )
return - V_48 ;
V_8 = F_23 ( sizeof( * V_8 ) , V_55 ) ;
if ( ! V_8 )
return - V_56 ;
for ( V_15 = 0 ; V_15 < V_47 ; V_15 ++ ) {
F_7 ( & V_8 -> V_11 [ V_15 ] , 0 ) ;
V_8 -> V_10 [ V_15 ] = 0 ;
}
V_8 -> V_16 = 0 ;
F_24 (rdev, mddev) {
V_8 -> V_36 = V_36 ;
F_25 ( V_28 -> V_57 , V_36 -> V_37 ,
V_36 -> V_58 << 9 ) ;
}
F_26 ( V_28 , F_19 ( V_28 , 0 , 0 ) ) ;
V_28 -> V_29 = V_8 ;
F_18 ( V_28 ) ;
return 0 ;
}
static void F_27 ( struct V_28 * V_28 , void * V_59 )
{
struct V_7 * V_8 = V_59 ;
F_28 ( V_8 ) ;
}
static int T_2 F_29 ( void )
{
return F_30 ( & V_60 ) ;
}
static void F_31 ( void )
{
F_32 ( & V_60 ) ;
}
