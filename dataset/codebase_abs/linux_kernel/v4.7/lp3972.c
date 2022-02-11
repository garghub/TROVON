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
if ( V_6 == 0 ) {
V_14 = ( V_14 & ~ V_13 ) | V_10 ;
V_6 = F_3 ( V_9 -> V_2 , V_3 , 1 , & V_14 ) ;
F_7 ( V_9 -> V_12 , L_2 , ( int ) V_3 ,
( unsigned ) V_10 & 0xff ) ;
}
F_8 ( & V_9 -> V_11 ) ;
return V_6 ;
}
static int F_10 ( struct V_15 * V_12 )
{
struct V_9 * V_9 = F_11 ( V_12 ) ;
int V_16 = F_12 ( V_12 ) - V_17 ;
T_1 V_13 = F_13 ( V_16 ) ;
T_1 V_10 ;
V_10 = F_5 ( V_9 , F_14 ( V_16 ) ) ;
return ! ! ( V_10 & V_13 ) ;
}
static int F_15 ( struct V_15 * V_12 )
{
struct V_9 * V_9 = F_11 ( V_12 ) ;
int V_16 = F_12 ( V_12 ) - V_17 ;
T_1 V_13 = F_13 ( V_16 ) ;
return F_9 ( V_9 , F_14 ( V_16 ) ,
V_13 , V_13 ) ;
}
static int F_16 ( struct V_15 * V_12 )
{
struct V_9 * V_9 = F_11 ( V_12 ) ;
int V_16 = F_12 ( V_12 ) - V_17 ;
T_1 V_13 = F_13 ( V_16 ) ;
return F_9 ( V_9 , F_14 ( V_16 ) ,
V_13 , 0 ) ;
}
static int F_17 ( struct V_15 * V_12 )
{
struct V_9 * V_9 = F_11 ( V_12 ) ;
int V_16 = F_12 ( V_12 ) - V_17 ;
T_1 V_13 = F_18 ( V_16 ) ;
T_1 V_10 , V_3 ;
V_3 = F_5 ( V_9 , F_19 ( V_16 ) ) ;
V_10 = ( V_3 >> F_20 ( V_16 ) ) & V_13 ;
return V_10 ;
}
static int F_21 ( struct V_15 * V_12 ,
unsigned int V_18 )
{
struct V_9 * V_9 = F_11 ( V_12 ) ;
int V_16 = F_12 ( V_12 ) - V_17 ;
int V_19 , V_6 ;
V_19 = F_20 ( V_16 ) ;
V_6 = F_9 ( V_9 , F_19 ( V_16 ) ,
F_18 ( V_16 ) << V_19 , V_18 << V_19 ) ;
if ( V_6 )
return V_6 ;
switch ( V_16 ) {
case V_17 :
case V_20 :
V_19 = F_22 ( V_16 ) ;
V_6 = F_9 ( V_9 , V_21 ,
V_22 << V_19 ,
V_23 << V_19 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_9 ( V_9 , V_21 ,
V_22 << V_19 , 0 ) ;
break;
}
return V_6 ;
}
static int F_23 ( struct V_15 * V_12 )
{
struct V_9 * V_9 = F_11 ( V_12 ) ;
int V_24 = F_12 ( V_12 ) - V_25 ;
T_1 V_13 = 1 << ( V_24 * 2 ) ;
T_1 V_10 ;
V_10 = F_5 ( V_9 , F_24 ( V_24 ) ) ;
return ! ! ( V_10 & V_13 ) ;
}
static int F_25 ( struct V_15 * V_12 )
{
struct V_9 * V_9 = F_11 ( V_12 ) ;
int V_24 = F_12 ( V_12 ) - V_25 ;
T_1 V_13 = 1 << ( V_24 * 2 ) ;
T_1 V_10 ;
V_10 = F_9 ( V_9 , F_24 ( V_24 ) ,
V_13 , V_13 ) ;
return V_10 ;
}
static int F_26 ( struct V_15 * V_12 )
{
struct V_9 * V_9 = F_11 ( V_12 ) ;
int V_24 = F_12 ( V_12 ) - V_25 ;
T_1 V_13 = 1 << ( V_24 * 2 ) ;
T_1 V_10 ;
V_10 = F_9 ( V_9 , F_24 ( V_24 ) ,
V_13 , 0 ) ;
return V_10 ;
}
static int F_27 ( struct V_15 * V_12 )
{
struct V_9 * V_9 = F_11 ( V_12 ) ;
int V_24 = F_12 ( V_12 ) - V_25 ;
T_1 V_3 ;
V_3 = F_5 ( V_9 , F_28 ( V_24 ) ) ;
V_3 &= V_26 ;
return V_3 ;
}
static int F_29 ( struct V_15 * V_12 ,
unsigned int V_18 )
{
struct V_9 * V_9 = F_11 ( V_12 ) ;
int V_24 = F_12 ( V_12 ) - V_25 ;
int V_6 ;
V_6 = F_9 ( V_9 , F_28 ( V_24 ) ,
V_26 , V_18 ) ;
if ( V_6 )
return V_6 ;
if ( V_24 != 0 )
return V_6 ;
V_6 = F_9 ( V_9 , V_21 ,
V_22 , V_23 ) ;
if ( V_6 )
return V_6 ;
return F_9 ( V_9 , V_21 ,
V_22 , 0 ) ;
}
static int F_30 ( struct V_9 * V_9 ,
struct V_27 * V_28 )
{
int V_29 , V_30 ;
for ( V_29 = 0 ; V_29 < V_28 -> V_31 ; V_29 ++ ) {
struct V_32 * V_3 = & V_28 -> V_33 [ V_29 ] ;
struct V_34 V_35 = { } ;
struct V_15 * V_36 ;
V_35 . V_12 = V_9 -> V_12 ;
V_35 . V_37 = V_3 -> V_38 ;
V_35 . V_39 = V_9 ;
V_36 = F_31 ( V_9 -> V_12 ,
& V_33 [ V_3 -> V_40 ] , & V_35 ) ;
if ( F_32 ( V_36 ) ) {
V_30 = F_33 ( V_36 ) ;
F_34 ( V_9 -> V_12 , L_3 ,
V_30 ) ;
return V_30 ;
}
}
return 0 ;
}
static int F_35 ( struct V_1 * V_2 ,
const struct V_41 * V_40 )
{
struct V_9 * V_9 ;
struct V_27 * V_28 = F_36 ( & V_2 -> V_12 ) ;
int V_6 ;
T_1 V_10 ;
if ( ! V_28 ) {
F_7 ( & V_2 -> V_12 , L_4 ) ;
return - V_42 ;
}
V_9 = F_37 ( & V_2 -> V_12 , sizeof( struct V_9 ) , V_43 ) ;
if ( ! V_9 )
return - V_44 ;
V_9 -> V_2 = V_2 ;
V_9 -> V_12 = & V_2 -> V_12 ;
F_38 ( & V_9 -> V_11 ) ;
V_6 = F_1 ( V_2 , V_45 , 1 , & V_10 ) ;
if ( V_6 == 0 &&
( V_10 & V_46 ) != V_47 ) {
V_6 = - V_42 ;
F_34 ( & V_2 -> V_12 , L_5 , V_10 ) ;
}
if ( V_6 < 0 ) {
F_34 ( & V_2 -> V_12 , L_6 , V_6 ) ;
return V_6 ;
}
V_6 = F_30 ( V_9 , V_28 ) ;
if ( V_6 < 0 )
return V_6 ;
F_39 ( V_2 , V_9 ) ;
return 0 ;
}
static int T_3 F_40 ( void )
{
return F_41 ( & V_48 ) ;
}
static void T_4 F_42 ( void )
{
F_43 ( & V_48 ) ;
}
