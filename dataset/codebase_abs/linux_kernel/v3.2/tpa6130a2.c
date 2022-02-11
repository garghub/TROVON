static int F_1 ( int V_1 )
{
struct V_2 * V_3 ;
int V_4 ;
F_2 ( V_5 == NULL ) ;
V_3 = F_3 ( V_5 ) ;
if ( V_3 -> V_6 ) {
V_4 = F_4 ( V_5 , V_1 ) ;
if ( V_4 < 0 )
F_5 ( & V_5 -> V_7 , L_1 ) ;
else
V_3 -> V_8 [ V_1 ] = V_4 ;
} else {
V_4 = V_3 -> V_8 [ V_1 ] ;
}
return V_4 ;
}
static int F_6 ( int V_1 , T_1 V_9 )
{
struct V_2 * V_3 ;
int V_4 = 0 ;
F_2 ( V_5 == NULL ) ;
V_3 = F_3 ( V_5 ) ;
if ( V_3 -> V_6 ) {
V_4 = F_7 ( V_5 , V_1 , V_9 ) ;
if ( V_4 < 0 ) {
F_5 ( & V_5 -> V_7 , L_2 ) ;
return V_4 ;
}
}
V_3 -> V_8 [ V_1 ] = V_9 ;
return V_4 ;
}
static T_1 F_8 ( int V_1 )
{
struct V_2 * V_3 ;
F_2 ( V_5 == NULL ) ;
V_3 = F_3 ( V_5 ) ;
return V_3 -> V_8 [ V_1 ] ;
}
static int F_9 ( void )
{
struct V_2 * V_3 ;
int V_10 , V_11 = 0 ;
F_2 ( V_5 == NULL ) ;
V_3 = F_3 ( V_5 ) ;
for ( V_10 = 1 ; V_10 < V_12 ; V_10 ++ ) {
V_11 = F_6 ( V_10 , V_3 -> V_8 [ V_10 ] ) ;
if ( V_11 < 0 )
break;
}
return V_11 ;
}
static int F_10 ( T_1 V_13 )
{
struct V_2 * V_3 ;
T_1 V_4 ;
int V_11 = 0 ;
F_2 ( V_5 == NULL ) ;
V_3 = F_3 ( V_5 ) ;
F_11 ( & V_3 -> V_14 ) ;
if ( V_13 == V_3 -> V_6 )
goto exit;
if ( V_13 ) {
V_11 = F_12 ( V_3 -> V_15 ) ;
if ( V_11 != 0 ) {
F_5 ( & V_5 -> V_7 ,
L_3 , V_11 ) ;
goto exit;
}
if ( V_3 -> V_16 >= 0 )
F_13 ( V_3 -> V_16 , 1 ) ;
V_3 -> V_6 = 1 ;
V_11 = F_9 () ;
if ( V_11 < 0 ) {
F_5 ( & V_5 -> V_7 ,
L_4 ) ;
if ( V_3 -> V_16 >= 0 )
F_13 ( V_3 -> V_16 , 0 ) ;
F_14 ( V_3 -> V_15 ) ;
V_3 -> V_6 = 0 ;
goto exit;
}
} else {
V_4 = F_8 ( V_17 ) ;
V_4 |= V_18 ;
F_6 ( V_17 , V_4 ) ;
if ( V_3 -> V_16 >= 0 )
F_13 ( V_3 -> V_16 , 0 ) ;
V_11 = F_14 ( V_3 -> V_15 ) ;
if ( V_11 != 0 ) {
F_5 ( & V_5 -> V_7 ,
L_5 , V_11 ) ;
goto exit;
}
V_3 -> V_6 = 0 ;
}
exit:
F_15 ( & V_3 -> V_14 ) ;
return V_11 ;
}
static int F_16 ( struct V_19 * V_20 ,
struct V_21 * V_22 )
{
struct V_23 * V_24 =
(struct V_23 * ) V_20 -> V_25 ;
struct V_2 * V_3 ;
unsigned int V_1 = V_24 -> V_1 ;
unsigned int V_26 = V_24 -> V_26 ;
int V_27 = V_24 -> V_27 ;
unsigned int V_28 = ( 1 << F_17 ( V_27 ) ) - 1 ;
unsigned int V_29 = V_24 -> V_29 ;
F_2 ( V_5 == NULL ) ;
V_3 = F_3 ( V_5 ) ;
F_11 ( & V_3 -> V_14 ) ;
V_22 -> V_9 . integer . V_9 [ 0 ] =
( F_8 ( V_1 ) >> V_26 ) & V_28 ;
if ( V_29 )
V_22 -> V_9 . integer . V_9 [ 0 ] =
V_27 - V_22 -> V_9 . integer . V_9 [ 0 ] ;
F_15 ( & V_3 -> V_14 ) ;
return 0 ;
}
static int F_18 ( struct V_19 * V_20 ,
struct V_21 * V_22 )
{
struct V_23 * V_24 =
(struct V_23 * ) V_20 -> V_25 ;
struct V_2 * V_3 ;
unsigned int V_1 = V_24 -> V_1 ;
unsigned int V_26 = V_24 -> V_26 ;
int V_27 = V_24 -> V_27 ;
unsigned int V_28 = ( 1 << F_17 ( V_27 ) ) - 1 ;
unsigned int V_29 = V_24 -> V_29 ;
unsigned int V_4 = ( V_22 -> V_9 . integer . V_9 [ 0 ] & V_28 ) ;
unsigned int V_30 ;
F_2 ( V_5 == NULL ) ;
V_3 = F_3 ( V_5 ) ;
if ( V_29 )
V_4 = V_27 - V_4 ;
F_11 ( & V_3 -> V_14 ) ;
V_30 = F_8 ( V_1 ) ;
if ( ( ( V_30 >> V_26 ) & V_28 ) == V_4 ) {
F_15 ( & V_3 -> V_14 ) ;
return 0 ;
}
V_30 &= ~ ( V_28 << V_26 ) ;
V_30 |= V_4 << V_26 ;
F_6 ( V_1 , V_30 ) ;
F_15 ( & V_3 -> V_14 ) ;
return 1 ;
}
static void F_19 ( T_1 V_31 , int V_32 )
{
T_1 V_4 ;
if ( V_32 ) {
V_4 = F_8 ( V_17 ) ;
V_4 |= V_31 ;
V_4 &= ~ V_18 ;
F_6 ( V_17 , V_4 ) ;
V_4 = F_8 ( V_33 ) ;
V_4 &= ~ V_31 ;
F_6 ( V_33 , V_4 ) ;
} else {
V_4 = F_8 ( V_33 ) ;
V_4 |= V_31 ;
F_6 ( V_33 , V_4 ) ;
V_4 = F_8 ( V_17 ) ;
V_4 &= ~ V_31 ;
F_6 ( V_17 , V_4 ) ;
}
}
int F_20 ( struct V_34 * V_35 , int V_32 )
{
int V_11 = 0 ;
if ( V_32 ) {
V_11 = F_10 ( 1 ) ;
if ( V_11 < 0 )
return V_11 ;
F_19 ( V_36 | V_37 ,
1 ) ;
} else {
F_19 ( V_36 | V_37 ,
0 ) ;
V_11 = F_10 ( 0 ) ;
}
return V_11 ;
}
int F_21 ( struct V_34 * V_35 )
{
struct V_2 * V_3 ;
if ( V_5 == NULL )
return - V_38 ;
V_3 = F_3 ( V_5 ) ;
if ( V_3 -> V_39 == V_40 )
return F_22 ( V_35 , V_41 ,
F_23 ( V_41 ) ) ;
else
return F_22 ( V_35 , V_42 ,
F_23 ( V_42 ) ) ;
}
static int T_2 F_24 ( struct V_43 * V_44 ,
const struct V_45 * V_39 )
{
struct V_46 * V_7 ;
struct V_2 * V_3 ;
struct V_47 * V_48 ;
const char * V_49 ;
int V_11 ;
V_7 = & V_44 -> V_7 ;
if ( V_44 -> V_7 . V_50 == NULL ) {
F_5 ( V_7 , L_6 ) ;
F_25 () ;
return - V_38 ;
}
V_3 = F_26 ( sizeof( * V_3 ) , V_51 ) ;
if ( V_3 == NULL ) {
F_5 ( V_7 , L_7 ) ;
return - V_52 ;
}
V_5 = V_44 ;
F_27 ( V_5 , V_3 ) ;
V_48 = V_44 -> V_7 . V_50 ;
V_3 -> V_16 = V_48 -> V_16 ;
V_3 -> V_39 = V_39 -> V_53 ;
F_28 ( & V_3 -> V_14 ) ;
V_3 -> V_8 [ V_17 ] = V_18 ;
V_3 -> V_8 [ V_33 ] = V_54 |
V_55 ;
if ( V_3 -> V_16 >= 0 ) {
V_11 = F_29 ( V_3 -> V_16 , L_8 ) ;
if ( V_11 < 0 ) {
F_5 ( V_7 , L_9 ,
V_3 -> V_16 ) ;
goto V_56;
}
F_30 ( V_3 -> V_16 , 0 ) ;
}
switch ( V_3 -> V_39 ) {
default:
F_31 ( V_7 , L_10 ,
V_3 -> V_39 ) ;
case V_57 :
V_49 = L_11 ;
break;
case V_40 :
V_49 = L_12 ;
break;
}
V_3 -> V_15 = F_32 ( V_7 , V_49 ) ;
if ( F_33 ( V_3 -> V_15 ) ) {
V_11 = F_34 ( V_3 -> V_15 ) ;
F_5 ( V_7 , L_13 , V_11 ) ;
goto V_58;
}
V_11 = F_10 ( 1 ) ;
if ( V_11 != 0 )
goto V_59;
V_11 = F_1 ( V_12 ) &
V_60 ;
if ( ( V_11 != 1 ) && ( V_11 != 2 ) )
F_31 ( V_7 , L_14 , V_11 ) ;
V_11 = F_10 ( 0 ) ;
if ( V_11 != 0 )
goto V_59;
return 0 ;
V_59:
F_35 ( V_3 -> V_15 ) ;
V_58:
if ( V_3 -> V_16 >= 0 )
F_36 ( V_3 -> V_16 ) ;
V_56:
F_37 ( V_3 ) ;
V_5 = NULL ;
return V_11 ;
}
static int T_3 F_38 ( struct V_43 * V_44 )
{
struct V_2 * V_3 = F_3 ( V_44 ) ;
F_10 ( 0 ) ;
if ( V_3 -> V_16 >= 0 )
F_36 ( V_3 -> V_16 ) ;
F_35 ( V_3 -> V_15 ) ;
F_37 ( V_3 ) ;
V_5 = NULL ;
return 0 ;
}
static int T_4 F_39 ( void )
{
return F_40 ( & V_61 ) ;
}
static void T_5 F_41 ( void )
{
F_42 ( & V_61 ) ;
}
