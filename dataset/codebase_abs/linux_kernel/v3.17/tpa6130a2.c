static int F_1 ( int V_1 )
{
struct V_2 * V_3 ;
int V_4 ;
if ( F_2 ( ! V_5 ) )
return - V_6 ;
V_3 = F_3 ( V_5 ) ;
if ( V_3 -> V_7 ) {
V_4 = F_4 ( V_5 , V_1 ) ;
if ( V_4 < 0 )
F_5 ( & V_5 -> V_8 , L_1 ) ;
else
V_3 -> V_9 [ V_1 ] = V_4 ;
} else {
V_4 = V_3 -> V_9 [ V_1 ] ;
}
return V_4 ;
}
static int F_6 ( int V_1 , T_1 V_10 )
{
struct V_2 * V_3 ;
int V_4 = 0 ;
if ( F_2 ( ! V_5 ) )
return - V_6 ;
V_3 = F_3 ( V_5 ) ;
if ( V_3 -> V_7 ) {
V_4 = F_7 ( V_5 , V_1 , V_10 ) ;
if ( V_4 < 0 ) {
F_5 ( & V_5 -> V_8 , L_2 ) ;
return V_4 ;
}
}
V_3 -> V_9 [ V_1 ] = V_10 ;
return V_4 ;
}
static T_1 F_8 ( int V_1 )
{
struct V_2 * V_3 ;
if ( F_2 ( ! V_5 ) )
return 0 ;
V_3 = F_3 ( V_5 ) ;
return V_3 -> V_9 [ V_1 ] ;
}
static int F_9 ( void )
{
struct V_2 * V_3 ;
int V_11 , V_12 = 0 ;
if ( F_2 ( ! V_5 ) )
return - V_6 ;
V_3 = F_3 ( V_5 ) ;
for ( V_11 = 1 ; V_11 < V_13 ; V_11 ++ ) {
V_12 = F_6 ( V_11 , V_3 -> V_9 [ V_11 ] ) ;
if ( V_12 < 0 )
break;
}
return V_12 ;
}
static int F_10 ( T_1 V_14 )
{
struct V_2 * V_3 ;
T_1 V_4 ;
int V_12 = 0 ;
if ( F_2 ( ! V_5 ) )
return - V_6 ;
V_3 = F_3 ( V_5 ) ;
F_11 ( & V_3 -> V_15 ) ;
if ( V_14 == V_3 -> V_7 )
goto exit;
if ( V_14 ) {
V_12 = F_12 ( V_3 -> V_16 ) ;
if ( V_12 != 0 ) {
F_5 ( & V_5 -> V_8 ,
L_3 , V_12 ) ;
goto exit;
}
if ( V_3 -> V_17 >= 0 )
F_13 ( V_3 -> V_17 , 1 ) ;
V_3 -> V_7 = 1 ;
V_12 = F_9 () ;
if ( V_12 < 0 ) {
F_5 ( & V_5 -> V_8 ,
L_4 ) ;
if ( V_3 -> V_17 >= 0 )
F_13 ( V_3 -> V_17 , 0 ) ;
F_14 ( V_3 -> V_16 ) ;
V_3 -> V_7 = 0 ;
goto exit;
}
} else {
V_4 = F_8 ( V_18 ) ;
V_4 |= V_19 ;
F_6 ( V_18 , V_4 ) ;
if ( V_3 -> V_17 >= 0 )
F_13 ( V_3 -> V_17 , 0 ) ;
V_12 = F_14 ( V_3 -> V_16 ) ;
if ( V_12 != 0 ) {
F_5 ( & V_5 -> V_8 ,
L_5 , V_12 ) ;
goto exit;
}
V_3 -> V_7 = 0 ;
}
exit:
F_15 ( & V_3 -> V_15 ) ;
return V_12 ;
}
static int F_16 ( struct V_20 * V_21 ,
struct V_22 * V_23 )
{
struct V_24 * V_25 =
(struct V_24 * ) V_21 -> V_26 ;
struct V_2 * V_3 ;
unsigned int V_1 = V_25 -> V_1 ;
unsigned int V_27 = V_25 -> V_27 ;
int V_28 = V_25 -> V_28 ;
unsigned int V_29 = ( 1 << F_17 ( V_28 ) ) - 1 ;
unsigned int V_30 = V_25 -> V_30 ;
if ( F_2 ( ! V_5 ) )
return - V_6 ;
V_3 = F_3 ( V_5 ) ;
F_11 ( & V_3 -> V_15 ) ;
V_23 -> V_10 . integer . V_10 [ 0 ] =
( F_8 ( V_1 ) >> V_27 ) & V_29 ;
if ( V_30 )
V_23 -> V_10 . integer . V_10 [ 0 ] =
V_28 - V_23 -> V_10 . integer . V_10 [ 0 ] ;
F_15 ( & V_3 -> V_15 ) ;
return 0 ;
}
static int F_18 ( struct V_20 * V_21 ,
struct V_22 * V_23 )
{
struct V_24 * V_25 =
(struct V_24 * ) V_21 -> V_26 ;
struct V_2 * V_3 ;
unsigned int V_1 = V_25 -> V_1 ;
unsigned int V_27 = V_25 -> V_27 ;
int V_28 = V_25 -> V_28 ;
unsigned int V_29 = ( 1 << F_17 ( V_28 ) ) - 1 ;
unsigned int V_30 = V_25 -> V_30 ;
unsigned int V_4 = ( V_23 -> V_10 . integer . V_10 [ 0 ] & V_29 ) ;
unsigned int V_31 ;
if ( F_2 ( ! V_5 ) )
return - V_6 ;
V_3 = F_3 ( V_5 ) ;
if ( V_30 )
V_4 = V_28 - V_4 ;
F_11 ( & V_3 -> V_15 ) ;
V_31 = F_8 ( V_1 ) ;
if ( ( ( V_31 >> V_27 ) & V_29 ) == V_4 ) {
F_15 ( & V_3 -> V_15 ) ;
return 0 ;
}
V_31 &= ~ ( V_29 << V_27 ) ;
V_31 |= V_4 << V_27 ;
F_6 ( V_1 , V_31 ) ;
F_15 ( & V_3 -> V_15 ) ;
return 1 ;
}
static void F_19 ( T_1 V_32 , int V_33 )
{
T_1 V_4 ;
if ( V_33 ) {
V_4 = F_8 ( V_18 ) ;
V_4 |= V_32 ;
V_4 &= ~ V_19 ;
F_6 ( V_18 , V_4 ) ;
V_4 = F_8 ( V_34 ) ;
V_4 &= ~ V_32 ;
F_6 ( V_34 , V_4 ) ;
} else {
V_4 = F_8 ( V_34 ) ;
V_4 |= V_32 ;
F_6 ( V_34 , V_4 ) ;
V_4 = F_8 ( V_18 ) ;
V_4 &= ~ V_32 ;
F_6 ( V_18 , V_4 ) ;
}
}
int F_20 ( struct V_35 * V_36 , int V_33 )
{
int V_12 = 0 ;
if ( V_33 ) {
V_12 = F_10 ( 1 ) ;
if ( V_12 < 0 )
return V_12 ;
F_19 ( V_37 | V_38 ,
1 ) ;
} else {
F_19 ( V_37 | V_38 ,
0 ) ;
V_12 = F_10 ( 0 ) ;
}
return V_12 ;
}
int F_21 ( struct V_35 * V_36 )
{
struct V_2 * V_3 ;
if ( V_5 == NULL )
return - V_39 ;
V_3 = F_3 ( V_5 ) ;
if ( V_3 -> V_40 == V_41 )
return F_22 ( V_36 , V_42 ,
F_23 ( V_42 ) ) ;
else
return F_22 ( V_36 , V_43 ,
F_23 ( V_43 ) ) ;
}
static int F_24 ( struct V_44 * V_45 ,
const struct V_46 * V_40 )
{
struct V_47 * V_8 ;
struct V_2 * V_3 ;
struct V_48 * V_49 = V_45 -> V_8 . V_50 ;
struct V_51 * V_52 = V_45 -> V_8 . V_53 ;
const char * V_54 ;
int V_12 ;
V_8 = & V_45 -> V_8 ;
V_3 = F_25 ( & V_45 -> V_8 , sizeof( * V_3 ) , V_55 ) ;
if ( ! V_3 )
return - V_56 ;
if ( V_49 ) {
V_3 -> V_17 = V_49 -> V_17 ;
} else if ( V_52 ) {
V_3 -> V_17 = F_26 ( V_52 , L_6 , 0 ) ;
} else {
F_5 ( V_8 , L_7 ) ;
F_27 () ;
return - V_39 ;
}
V_5 = V_45 ;
F_28 ( V_5 , V_3 ) ;
V_3 -> V_40 = V_40 -> V_57 ;
F_29 ( & V_3 -> V_15 ) ;
V_3 -> V_9 [ V_18 ] = V_19 ;
V_3 -> V_9 [ V_34 ] = V_58 |
V_59 ;
if ( V_3 -> V_17 >= 0 ) {
V_12 = F_30 ( V_8 , V_3 -> V_17 ,
L_8 ) ;
if ( V_12 < 0 ) {
F_5 ( V_8 , L_9 ,
V_3 -> V_17 ) ;
goto V_60;
}
F_31 ( V_3 -> V_17 , 0 ) ;
}
switch ( V_3 -> V_40 ) {
default:
F_32 ( V_8 , L_10 ,
V_3 -> V_40 ) ;
case V_61 :
V_54 = L_11 ;
break;
case V_41 :
V_54 = L_12 ;
break;
}
V_3 -> V_16 = F_33 ( V_8 , V_54 ) ;
if ( F_34 ( V_3 -> V_16 ) ) {
V_12 = F_35 ( V_3 -> V_16 ) ;
F_5 ( V_8 , L_13 , V_12 ) ;
goto V_60;
}
V_12 = F_10 ( 1 ) ;
if ( V_12 != 0 )
goto V_60;
V_12 = F_1 ( V_13 ) &
V_62 ;
if ( ( V_12 != 1 ) && ( V_12 != 2 ) )
F_32 ( V_8 , L_14 , V_12 ) ;
V_12 = F_10 ( 0 ) ;
if ( V_12 != 0 )
goto V_60;
return 0 ;
V_60:
V_5 = NULL ;
return V_12 ;
}
static int F_36 ( struct V_44 * V_45 )
{
F_10 ( 0 ) ;
V_5 = NULL ;
return 0 ;
}
