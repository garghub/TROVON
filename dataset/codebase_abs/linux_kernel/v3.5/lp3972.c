static int F_1 ( struct V_1 * V_2 , char V_3 , int V_4 ,
T_1 * V_5 )
{
int V_6 ;
if ( V_4 != 1 )
return - V_7 ;
V_6 = F_2 ( V_2 , V_3 ) ;
if ( V_6 < 0 )
return V_6 ;
* V_5 = V_6 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 , char V_3 , int V_4 ,
const T_1 * V_8 )
{
if ( V_4 != 1 )
return - V_7 ;
return F_4 ( V_2 , V_3 , * V_8 ) ;
}
static T_2 F_5 ( struct V_9 * V_9 , T_2 V_3 )
{
T_1 V_10 = 0 ;
F_6 ( & V_9 -> V_11 ) ;
F_1 ( V_9 -> V_2 , V_3 , 1 , & V_10 ) ;
F_7 ( V_9 -> V_12 , L_1 , ( int ) V_3 ,
( unsigned ) V_10 & 0xff ) ;
F_8 ( & V_9 -> V_11 ) ;
return V_10 & 0xff ;
}
static int F_9 ( struct V_9 * V_9 , T_2 V_3 , T_1 V_13 , T_1 V_10 )
{
T_1 V_14 ;
int V_6 ;
F_6 ( & V_9 -> V_11 ) ;
V_6 = F_1 ( V_9 -> V_2 , V_3 , 1 , & V_14 ) ;
V_14 = ( V_14 & ~ V_13 ) | V_10 ;
if ( V_6 == 0 ) {
V_6 = F_3 ( V_9 -> V_2 , V_3 , 1 , & V_14 ) ;
F_7 ( V_9 -> V_12 , L_2 , ( int ) V_3 ,
( unsigned ) V_10 & 0xff ) ;
}
F_8 ( & V_9 -> V_11 ) ;
return V_6 ;
}
static int F_10 ( struct V_15 * V_12 , unsigned V_16 )
{
int V_17 = F_11 ( V_12 ) - V_18 ;
if ( V_16 < V_19 ( V_17 ) ||
V_16 > F_12 ( V_17 ) )
return - V_20 ;
return 1000 * F_13 ( V_17 ) [ V_16 ] ;
}
static int F_14 ( struct V_15 * V_12 )
{
struct V_9 * V_9 = F_15 ( V_12 ) ;
int V_17 = F_11 ( V_12 ) - V_18 ;
T_1 V_13 = F_16 ( V_17 ) ;
T_1 V_10 ;
V_10 = F_5 ( V_9 , F_17 ( V_17 ) ) ;
return ! ! ( V_10 & V_13 ) ;
}
static int F_18 ( struct V_15 * V_12 )
{
struct V_9 * V_9 = F_15 ( V_12 ) ;
int V_17 = F_11 ( V_12 ) - V_18 ;
T_1 V_13 = F_16 ( V_17 ) ;
return F_9 ( V_9 , F_17 ( V_17 ) ,
V_13 , V_13 ) ;
}
static int F_19 ( struct V_15 * V_12 )
{
struct V_9 * V_9 = F_15 ( V_12 ) ;
int V_17 = F_11 ( V_12 ) - V_18 ;
T_1 V_13 = F_16 ( V_17 ) ;
return F_9 ( V_9 , F_17 ( V_17 ) ,
V_13 , 0 ) ;
}
static int F_20 ( struct V_15 * V_12 )
{
struct V_9 * V_9 = F_15 ( V_12 ) ;
int V_17 = F_11 ( V_12 ) - V_18 ;
T_1 V_13 = F_21 ( V_17 ) ;
T_1 V_10 , V_3 ;
V_3 = F_5 ( V_9 , F_22 ( V_17 ) ) ;
V_10 = ( V_3 >> F_23 ( V_17 ) ) & V_13 ;
return 1000 * F_13 ( V_17 ) [ V_10 ] ;
}
static int F_24 ( struct V_15 * V_12 ,
unsigned int V_21 )
{
struct V_9 * V_9 = F_15 ( V_12 ) ;
int V_17 = F_11 ( V_12 ) - V_18 ;
int V_22 , V_6 ;
V_22 = F_23 ( V_17 ) ;
V_6 = F_9 ( V_9 , F_22 ( V_17 ) ,
F_21 ( V_17 ) << V_22 , V_21 << V_22 ) ;
if ( V_6 )
return V_6 ;
switch ( V_17 ) {
case V_18 :
case V_23 :
V_22 = F_25 ( V_17 ) ;
V_6 = F_9 ( V_9 , V_24 ,
V_25 << V_22 ,
V_26 << V_22 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_9 ( V_9 , V_24 ,
V_25 << V_22 , 0 ) ;
break;
}
return V_6 ;
}
static int F_26 ( struct V_15 * V_12 , unsigned V_16 )
{
int V_27 = F_11 ( V_12 ) - V_28 ;
if ( V_16 < V_29 ( V_27 ) ||
V_16 > F_27 ( V_27 ) )
return - V_20 ;
return 1000 * V_30 [ V_27 ] [ V_16 ] ;
}
static int F_28 ( struct V_15 * V_12 )
{
struct V_9 * V_9 = F_15 ( V_12 ) ;
int V_27 = F_11 ( V_12 ) - V_28 ;
T_1 V_13 = 1 << ( V_27 * 2 ) ;
T_1 V_10 ;
V_10 = F_5 ( V_9 , F_29 ( V_27 ) ) ;
return ! ! ( V_10 & V_13 ) ;
}
static int F_30 ( struct V_15 * V_12 )
{
struct V_9 * V_9 = F_15 ( V_12 ) ;
int V_27 = F_11 ( V_12 ) - V_28 ;
T_1 V_13 = 1 << ( V_27 * 2 ) ;
T_1 V_10 ;
V_10 = F_9 ( V_9 , F_29 ( V_27 ) ,
V_13 , V_13 ) ;
return V_10 ;
}
static int F_31 ( struct V_15 * V_12 )
{
struct V_9 * V_9 = F_15 ( V_12 ) ;
int V_27 = F_11 ( V_12 ) - V_28 ;
T_1 V_13 = 1 << ( V_27 * 2 ) ;
T_1 V_10 ;
V_10 = F_9 ( V_9 , F_29 ( V_27 ) ,
V_13 , 0 ) ;
return V_10 ;
}
static int F_32 ( struct V_15 * V_12 )
{
struct V_9 * V_9 = F_15 ( V_12 ) ;
int V_27 = F_11 ( V_12 ) - V_28 ;
T_1 V_3 ;
int V_10 ;
V_3 = F_5 ( V_9 , F_33 ( V_27 ) ) ;
V_3 &= V_31 ;
if ( V_3 <= F_27 ( V_27 ) )
V_10 = 1000 * V_30 [ V_27 ] [ V_3 ] ;
else {
V_10 = 0 ;
F_34 ( & V_12 -> V_12 , L_3
L_4 , V_3 ) ;
}
return V_10 ;
}
static int F_35 ( struct V_15 * V_12 ,
unsigned int V_21 )
{
struct V_9 * V_9 = F_15 ( V_12 ) ;
int V_27 = F_11 ( V_12 ) - V_28 ;
int V_6 ;
V_6 = F_9 ( V_9 , F_33 ( V_27 ) ,
V_31 , V_21 ) ;
if ( V_6 )
return V_6 ;
if ( V_27 != 0 )
return V_6 ;
V_6 = F_9 ( V_9 , V_24 ,
V_25 , V_26 ) ;
if ( V_6 )
return V_6 ;
return F_9 ( V_9 , V_24 ,
V_25 , 0 ) ;
}
static int T_3 F_36 ( struct V_9 * V_9 ,
struct V_32 * V_33 )
{
int V_34 , V_35 ;
V_9 -> V_36 = V_33 -> V_36 ;
V_9 -> V_37 = F_37 ( V_33 -> V_36 ,
sizeof( struct V_15 * ) , V_38 ) ;
if ( ! V_9 -> V_37 ) {
V_35 = - V_39 ;
goto V_40;
}
for ( V_34 = 0 ; V_34 < V_33 -> V_36 ; V_34 ++ ) {
struct V_41 * V_3 = & V_33 -> V_42 [ V_34 ] ;
struct V_43 V_44 = { } ;
V_44 . V_12 = V_9 -> V_12 ;
V_44 . V_45 = V_3 -> V_46 ;
V_44 . V_47 = V_9 ;
V_9 -> V_37 [ V_34 ] = F_38 ( & V_42 [ V_3 -> V_48 ] ,
& V_44 ) ;
if ( F_39 ( V_9 -> V_37 [ V_34 ] ) ) {
V_35 = F_40 ( V_9 -> V_37 [ V_34 ] ) ;
F_41 ( V_9 -> V_12 , L_5 ,
V_35 ) ;
goto error;
}
}
return 0 ;
error:
while ( -- V_34 >= 0 )
F_42 ( V_9 -> V_37 [ V_34 ] ) ;
F_43 ( V_9 -> V_37 ) ;
V_9 -> V_37 = NULL ;
V_40:
return V_35 ;
}
static int T_3 F_44 ( struct V_1 * V_2 ,
const struct V_49 * V_48 )
{
struct V_9 * V_9 ;
struct V_32 * V_33 = V_2 -> V_12 . V_50 ;
int V_6 ;
T_1 V_10 ;
if ( ! V_33 ) {
F_7 ( & V_2 -> V_12 , L_6 ) ;
return - V_51 ;
}
V_9 = F_45 ( sizeof( struct V_9 ) , V_38 ) ;
if ( ! V_9 )
return - V_39 ;
V_9 -> V_2 = V_2 ;
V_9 -> V_12 = & V_2 -> V_12 ;
F_46 ( & V_9 -> V_11 ) ;
V_6 = F_1 ( V_2 , V_52 , 1 , & V_10 ) ;
if ( V_6 == 0 &&
( V_10 & V_53 ) != V_54 ) {
V_6 = - V_51 ;
F_41 ( & V_2 -> V_12 , L_7 , V_10 ) ;
}
if ( V_6 < 0 ) {
F_41 ( & V_2 -> V_12 , L_8 , V_6 ) ;
goto V_55;
}
V_6 = F_36 ( V_9 , V_33 ) ;
if ( V_6 < 0 )
goto V_55;
F_47 ( V_2 , V_9 ) ;
return 0 ;
V_55:
F_43 ( V_9 ) ;
return V_6 ;
}
static int T_4 F_48 ( struct V_1 * V_2 )
{
struct V_9 * V_9 = F_49 ( V_2 ) ;
int V_34 ;
for ( V_34 = 0 ; V_34 < V_9 -> V_36 ; V_34 ++ )
F_42 ( V_9 -> V_37 [ V_34 ] ) ;
F_43 ( V_9 -> V_37 ) ;
F_43 ( V_9 ) ;
return 0 ;
}
static int T_5 F_50 ( void )
{
return F_51 ( & V_56 ) ;
}
static void T_6 F_52 ( void )
{
F_53 ( & V_56 ) ;
}
