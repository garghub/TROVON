static void F_1 ( struct V_1 * V_1 , int error )
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
static void F_10 ( struct V_28 * V_28 , struct V_1 * V_1 )
{
struct V_7 * V_8 = V_28 -> V_29 ;
int V_30 = 0 ;
if ( F_11 ( V_1 ) == V_20 ) {
if ( F_5 ( & V_8 -> V_11 [ V_31 ] ) ) {
F_12 ( V_1 , - V_32 ) ;
return;
}
if ( F_8 ( V_8 , V_1 -> V_4 . V_6 ,
F_13 ( V_1 ) , V_20 ) )
V_30 = 1 ;
if ( F_4 ( V_8 , V_19 ) ) {
F_9 ( V_8 , V_1 -> V_4 . V_6 ,
V_19 ) ;
V_30 = 1 ;
}
if ( F_4 ( V_8 , V_33 ) )
V_30 = 1 ;
} else {
if ( F_8 ( V_8 , V_1 -> V_4 . V_6 ,
F_13 ( V_1 ) , V_22 ) )
V_30 = 1 ;
if ( F_4 ( V_8 , V_34 ) )
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
struct V_1 * V_2 = F_14 ( V_1 , V_35 , V_28 ) ;
V_2 -> V_36 = V_8 -> V_37 -> V_38 ;
V_2 -> V_3 = V_1 ;
V_2 -> V_39 = F_1 ;
V_1 = V_2 ;
} else
V_1 -> V_36 = V_8 -> V_37 -> V_38 ;
F_15 ( V_1 ) ;
}
static void F_16 ( struct V_40 * V_41 , struct V_28 * V_28 )
{
struct V_7 * V_8 = V_28 -> V_29 ;
int V_26 ;
if ( ( V_26 = F_5 ( & V_8 -> V_11 [ V_33 ] ) ) != 0 )
F_17 ( V_41 , L_1 ,
V_26 , V_8 -> V_10 [ V_33 ] ) ;
if ( ( V_26 = F_5 ( & V_8 -> V_11 [ V_34 ] ) ) != 0 )
F_17 ( V_41 , L_2 ,
V_26 , V_8 -> V_10 [ V_34 ] ) ;
if ( ( V_26 = F_5 ( & V_8 -> V_11 [ V_19 ] ) ) != 0 )
F_17 ( V_41 , L_3 ,
V_26 , V_8 -> V_10 [ V_19 ] ) ;
if ( ( V_26 = F_5 ( & V_8 -> V_11 [ V_21 ] ) ) != 0 )
F_17 ( V_41 , L_4 ,
V_26 , V_8 -> V_10 [ V_21 ] ) ;
if ( ( V_26 = F_5 ( & V_8 -> V_11 [ V_23 ] ) ) != 0 )
F_17 ( V_41 , L_5 ,
V_26 , V_8 -> V_10 [ V_23 ] ) ;
if ( ( V_26 = F_5 ( & V_8 -> V_11 [ V_31 ] ) ) != 0 )
F_17 ( V_41 , L_6 ) ;
F_17 ( V_41 , L_7 , V_8 -> V_16 ) ;
}
static int F_18 ( struct V_28 * V_28 )
{
int V_9 = V_28 -> V_42 & V_43 ;
int V_44 = V_28 -> V_42 >> V_45 ;
struct V_7 * V_8 = V_28 -> V_29 ;
if ( V_28 -> V_42 < 0 )
return 0 ;
if ( V_9 == V_46 )
V_8 -> V_16 = 0 ;
else if ( V_9 == V_47 ) {
int V_15 ;
for ( V_15 = 0 ; V_15 < V_48 ; V_15 ++ ) {
V_8 -> V_10 [ V_15 ] = 0 ;
F_7 ( & V_8 -> V_11 [ V_15 ] , 0 ) ;
}
} else if ( V_9 < V_48 ) {
V_8 -> V_10 [ V_9 ] = V_44 ;
if ( ! V_44 ) V_44 ++ ;
F_7 ( & V_8 -> V_11 [ V_9 ] , V_44 ) ;
} else
return - V_49 ;
V_28 -> V_42 = - 1 ;
V_28 -> V_50 = - 1 ;
return 0 ;
}
static T_1 F_19 ( struct V_28 * V_28 , T_1 V_51 , int V_52 )
{
F_20 ( V_52 ,
L_8 , V_53 ) ;
if ( V_51 == 0 )
return V_28 -> V_54 ;
return V_51 ;
}
static int F_21 ( struct V_28 * V_28 )
{
struct V_55 * V_37 ;
int V_15 ;
struct V_7 * V_8 ;
if ( F_22 ( V_28 ) )
return - V_49 ;
V_8 = F_23 ( sizeof( * V_8 ) , V_56 ) ;
if ( ! V_8 )
return - V_57 ;
for ( V_15 = 0 ; V_15 < V_48 ; V_15 ++ ) {
F_7 ( & V_8 -> V_11 [ V_15 ] , 0 ) ;
V_8 -> V_10 [ V_15 ] = 0 ;
}
V_8 -> V_16 = 0 ;
F_24 (rdev, mddev) {
V_8 -> V_37 = V_37 ;
F_25 ( V_28 -> V_58 , V_37 -> V_38 ,
V_37 -> V_59 << 9 ) ;
}
F_26 ( V_28 , F_19 ( V_28 , 0 , 0 ) ) ;
V_28 -> V_29 = V_8 ;
F_18 ( V_28 ) ;
return 0 ;
}
static void F_27 ( struct V_28 * V_28 , void * V_60 )
{
struct V_7 * V_8 = V_60 ;
F_28 ( V_8 ) ;
}
static int T_2 F_29 ( void )
{
return F_30 ( & V_61 ) ;
}
static void F_31 ( void )
{
F_32 ( & V_61 ) ;
}
