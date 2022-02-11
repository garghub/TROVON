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
return 1000 * F_12 ( V_17 ) [ V_16 ] ;
}
static int F_13 ( struct V_15 * V_12 )
{
struct V_9 * V_9 = F_14 ( V_12 ) ;
int V_17 = F_11 ( V_12 ) - V_18 ;
T_1 V_13 = F_15 ( V_17 ) ;
T_1 V_10 ;
V_10 = F_5 ( V_9 , F_16 ( V_17 ) ) ;
return ! ! ( V_10 & V_13 ) ;
}
static int F_17 ( struct V_15 * V_12 )
{
struct V_9 * V_9 = F_14 ( V_12 ) ;
int V_17 = F_11 ( V_12 ) - V_18 ;
T_1 V_13 = F_15 ( V_17 ) ;
return F_9 ( V_9 , F_16 ( V_17 ) ,
V_13 , V_13 ) ;
}
static int F_18 ( struct V_15 * V_12 )
{
struct V_9 * V_9 = F_14 ( V_12 ) ;
int V_17 = F_11 ( V_12 ) - V_18 ;
T_1 V_13 = F_15 ( V_17 ) ;
return F_9 ( V_9 , F_16 ( V_17 ) ,
V_13 , 0 ) ;
}
static int F_19 ( struct V_15 * V_12 )
{
struct V_9 * V_9 = F_14 ( V_12 ) ;
int V_17 = F_11 ( V_12 ) - V_18 ;
T_1 V_13 = F_20 ( V_17 ) ;
T_1 V_10 , V_3 ;
V_3 = F_5 ( V_9 , F_21 ( V_17 ) ) ;
V_10 = ( V_3 >> F_22 ( V_17 ) ) & V_13 ;
return 1000 * F_12 ( V_17 ) [ V_10 ] ;
}
static int F_23 ( struct V_15 * V_12 ,
int V_19 , int V_20 ,
unsigned int * V_21 )
{
struct V_9 * V_9 = F_14 ( V_12 ) ;
int V_17 = F_11 ( V_12 ) - V_18 ;
int V_22 = V_19 / 1000 , V_23 = V_20 / 1000 ;
const int * V_24 = F_12 ( V_17 ) ;
T_1 V_10 ;
int V_25 , V_6 ;
if ( V_22 < V_24 [ F_24 ( V_17 ) ] ||
V_22 > V_24 [ F_25 ( V_17 ) ] )
return - V_26 ;
for ( V_10 = F_24 ( V_17 ) ;
V_10 <= F_25 ( V_17 ) ; V_10 ++ )
if ( V_24 [ V_10 ] >= V_22 )
break;
if ( V_10 > F_25 ( V_17 ) || V_24 [ V_10 ] > V_23 )
return - V_26 ;
* V_21 = V_10 ;
V_25 = F_22 ( V_17 ) ;
V_6 = F_9 ( V_9 , F_21 ( V_17 ) ,
F_20 ( V_17 ) << V_25 , V_10 << V_25 ) ;
if ( V_6 )
return V_6 ;
switch ( V_17 ) {
case V_18 :
case V_27 :
V_25 = F_26 ( V_17 ) ;
V_6 = F_9 ( V_9 , V_28 ,
V_29 << V_25 ,
V_30 << V_25 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_9 ( V_9 , V_28 ,
V_29 << V_25 , 0 ) ;
break;
}
return V_6 ;
}
static int F_27 ( struct V_15 * V_12 , unsigned V_16 )
{
int V_31 = F_11 ( V_12 ) - V_32 ;
return 1000 * V_33 [ V_31 ] [ V_16 ] ;
}
static int F_28 ( struct V_15 * V_12 )
{
struct V_9 * V_9 = F_14 ( V_12 ) ;
int V_31 = F_11 ( V_12 ) - V_32 ;
T_1 V_13 = 1 << ( V_31 * 2 ) ;
T_1 V_10 ;
V_10 = F_5 ( V_9 , F_29 ( V_31 ) ) ;
return ! ! ( V_10 & V_13 ) ;
}
static int F_30 ( struct V_15 * V_12 )
{
struct V_9 * V_9 = F_14 ( V_12 ) ;
int V_31 = F_11 ( V_12 ) - V_32 ;
T_1 V_13 = 1 << ( V_31 * 2 ) ;
T_1 V_10 ;
V_10 = F_9 ( V_9 , F_29 ( V_31 ) ,
V_13 , V_13 ) ;
return V_10 ;
}
static int F_31 ( struct V_15 * V_12 )
{
struct V_9 * V_9 = F_14 ( V_12 ) ;
int V_31 = F_11 ( V_12 ) - V_32 ;
T_1 V_13 = 1 << ( V_31 * 2 ) ;
T_1 V_10 ;
V_10 = F_9 ( V_9 , F_29 ( V_31 ) ,
V_13 , 0 ) ;
return V_10 ;
}
static int F_32 ( struct V_15 * V_12 )
{
struct V_9 * V_9 = F_14 ( V_12 ) ;
int V_31 = F_11 ( V_12 ) - V_32 ;
T_1 V_3 ;
int V_10 ;
V_3 = F_5 ( V_9 , F_33 ( V_31 ) ) ;
V_3 &= V_34 ;
if ( V_3 <= F_34 ( V_31 ) )
V_10 = 1000 * V_33 [ V_31 ] [ V_3 ] ;
else {
V_10 = 0 ;
F_35 ( & V_12 -> V_12 , L_3
L_4 , V_3 ) ;
}
return V_10 ;
}
static int F_36 ( struct V_15 * V_12 ,
int V_19 , int V_20 ,
unsigned int * V_21 )
{
struct V_9 * V_9 = F_14 ( V_12 ) ;
int V_31 = F_11 ( V_12 ) - V_32 ;
int V_22 = V_19 / 1000 , V_23 = V_20 / 1000 ;
const int * V_24 = V_33 [ V_31 ] ;
T_1 V_10 ;
int V_6 ;
if ( V_22 < V_24 [ F_37 ( V_31 ) ] ||
V_22 > V_24 [ F_34 ( V_31 ) ] )
return - V_26 ;
for ( V_10 = F_37 ( V_31 ) ;
V_10 <= F_34 ( V_31 ) ; V_10 ++ )
if ( V_24 [ V_10 ] >= V_22 )
break;
if ( V_10 > F_34 ( V_31 ) ||
V_24 [ V_10 ] > V_23 )
return - V_26 ;
* V_21 = V_10 ;
V_6 = F_9 ( V_9 , F_33 ( V_31 ) ,
V_34 , V_10 ) ;
if ( V_6 )
return V_6 ;
if ( V_31 != 0 )
return V_6 ;
V_6 = F_9 ( V_9 , V_28 ,
V_29 , V_30 ) ;
if ( V_6 )
return V_6 ;
return F_9 ( V_9 , V_28 ,
V_29 , 0 ) ;
}
static int T_3 F_38 ( struct V_9 * V_9 ,
struct V_35 * V_36 )
{
int V_37 , V_38 ;
V_9 -> V_39 = V_36 -> V_39 ;
V_9 -> V_40 = F_39 ( V_36 -> V_39 ,
sizeof( struct V_15 * ) , V_41 ) ;
if ( ! V_9 -> V_40 ) {
V_38 = - V_42 ;
goto V_43;
}
for ( V_37 = 0 ; V_37 < V_36 -> V_39 ; V_37 ++ ) {
struct V_44 * V_3 = & V_36 -> V_45 [ V_37 ] ;
V_9 -> V_40 [ V_37 ] = F_40 ( & V_45 [ V_3 -> V_46 ] ,
V_9 -> V_12 , V_3 -> V_47 , V_9 ) ;
if ( F_41 ( V_9 -> V_40 [ V_37 ] ) ) {
V_38 = F_42 ( V_9 -> V_40 [ V_37 ] ) ;
F_43 ( V_9 -> V_12 , L_5 ,
V_38 ) ;
goto error;
}
}
return 0 ;
error:
while ( -- V_37 >= 0 )
F_44 ( V_9 -> V_40 [ V_37 ] ) ;
F_45 ( V_9 -> V_40 ) ;
V_9 -> V_40 = NULL ;
V_43:
return V_38 ;
}
static int T_3 F_46 ( struct V_1 * V_2 ,
const struct V_48 * V_46 )
{
struct V_9 * V_9 ;
struct V_35 * V_36 = V_2 -> V_12 . V_49 ;
int V_6 ;
T_1 V_10 ;
if ( ! V_36 ) {
F_7 ( & V_2 -> V_12 , L_6 ) ;
return - V_50 ;
}
V_9 = F_47 ( sizeof( struct V_9 ) , V_41 ) ;
if ( ! V_9 )
return - V_42 ;
V_9 -> V_2 = V_2 ;
V_9 -> V_12 = & V_2 -> V_12 ;
F_48 ( & V_9 -> V_11 ) ;
V_6 = F_1 ( V_2 , V_51 , 1 , & V_10 ) ;
if ( V_6 == 0 &&
( V_10 & V_52 ) != V_53 ) {
V_6 = - V_50 ;
F_43 ( & V_2 -> V_12 , L_7 , V_10 ) ;
}
if ( V_6 < 0 ) {
F_43 ( & V_2 -> V_12 , L_8 , V_6 ) ;
goto V_54;
}
V_6 = F_38 ( V_9 , V_36 ) ;
if ( V_6 < 0 )
goto V_54;
F_49 ( V_2 , V_9 ) ;
return 0 ;
V_54:
F_45 ( V_9 ) ;
return V_6 ;
}
static int T_4 F_50 ( struct V_1 * V_2 )
{
struct V_9 * V_9 = F_51 ( V_2 ) ;
int V_37 ;
for ( V_37 = 0 ; V_37 < V_9 -> V_39 ; V_37 ++ )
F_44 ( V_9 -> V_40 [ V_37 ] ) ;
F_45 ( V_9 -> V_40 ) ;
F_45 ( V_9 ) ;
return 0 ;
}
static int T_5 F_52 ( void )
{
return F_53 ( & V_55 ) ;
}
static void T_6 F_54 ( void )
{
F_55 ( & V_55 ) ;
}
