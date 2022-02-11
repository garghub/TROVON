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
return V_12 -> V_18 -> V_19 [ V_10 ] ;
}
static int F_21 ( struct V_15 * V_12 ,
unsigned int V_20 )
{
struct V_9 * V_9 = F_11 ( V_12 ) ;
int V_16 = F_12 ( V_12 ) - V_17 ;
int V_21 , V_6 ;
V_21 = F_20 ( V_16 ) ;
V_6 = F_9 ( V_9 , F_19 ( V_16 ) ,
F_18 ( V_16 ) << V_21 , V_20 << V_21 ) ;
if ( V_6 )
return V_6 ;
switch ( V_16 ) {
case V_17 :
case V_22 :
V_21 = F_22 ( V_16 ) ;
V_6 = F_9 ( V_9 , V_23 ,
V_24 << V_21 ,
V_25 << V_21 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_9 ( V_9 , V_23 ,
V_24 << V_21 , 0 ) ;
break;
}
return V_6 ;
}
static int F_23 ( struct V_15 * V_12 )
{
struct V_9 * V_9 = F_11 ( V_12 ) ;
int V_26 = F_12 ( V_12 ) - V_27 ;
T_1 V_13 = 1 << ( V_26 * 2 ) ;
T_1 V_10 ;
V_10 = F_5 ( V_9 , F_24 ( V_26 ) ) ;
return ! ! ( V_10 & V_13 ) ;
}
static int F_25 ( struct V_15 * V_12 )
{
struct V_9 * V_9 = F_11 ( V_12 ) ;
int V_26 = F_12 ( V_12 ) - V_27 ;
T_1 V_13 = 1 << ( V_26 * 2 ) ;
T_1 V_10 ;
V_10 = F_9 ( V_9 , F_24 ( V_26 ) ,
V_13 , V_13 ) ;
return V_10 ;
}
static int F_26 ( struct V_15 * V_12 )
{
struct V_9 * V_9 = F_11 ( V_12 ) ;
int V_26 = F_12 ( V_12 ) - V_27 ;
T_1 V_13 = 1 << ( V_26 * 2 ) ;
T_1 V_10 ;
V_10 = F_9 ( V_9 , F_24 ( V_26 ) ,
V_13 , 0 ) ;
return V_10 ;
}
static int F_27 ( struct V_15 * V_12 )
{
struct V_9 * V_9 = F_11 ( V_12 ) ;
int V_26 = F_12 ( V_12 ) - V_27 ;
T_1 V_3 ;
int V_10 ;
V_3 = F_5 ( V_9 , F_28 ( V_26 ) ) ;
V_3 &= V_28 ;
if ( V_3 <= F_29 ( V_26 ) )
V_10 = V_12 -> V_18 -> V_19 [ V_3 ] ;
else {
V_10 = 0 ;
F_30 ( & V_12 -> V_12 , L_3
L_4 , V_3 ) ;
}
return V_10 ;
}
static int F_31 ( struct V_15 * V_12 ,
unsigned int V_20 )
{
struct V_9 * V_9 = F_11 ( V_12 ) ;
int V_26 = F_12 ( V_12 ) - V_27 ;
int V_6 ;
V_6 = F_9 ( V_9 , F_28 ( V_26 ) ,
V_28 , V_20 ) ;
if ( V_6 )
return V_6 ;
if ( V_26 != 0 )
return V_6 ;
V_6 = F_9 ( V_9 , V_23 ,
V_24 , V_25 ) ;
if ( V_6 )
return V_6 ;
return F_9 ( V_9 , V_23 ,
V_24 , 0 ) ;
}
static int T_3 F_32 ( struct V_9 * V_9 ,
struct V_29 * V_30 )
{
int V_31 , V_32 ;
V_9 -> V_33 = V_30 -> V_33 ;
V_9 -> V_34 = F_33 ( V_30 -> V_33 ,
sizeof( struct V_15 * ) , V_35 ) ;
if ( ! V_9 -> V_34 ) {
V_32 = - V_36 ;
goto V_37;
}
for ( V_31 = 0 ; V_31 < V_30 -> V_33 ; V_31 ++ ) {
struct V_38 * V_3 = & V_30 -> V_39 [ V_31 ] ;
struct V_40 V_41 = { } ;
V_41 . V_12 = V_9 -> V_12 ;
V_41 . V_42 = V_3 -> V_43 ;
V_41 . V_44 = V_9 ;
V_9 -> V_34 [ V_31 ] = F_34 ( & V_39 [ V_3 -> V_45 ] ,
& V_41 ) ;
if ( F_35 ( V_9 -> V_34 [ V_31 ] ) ) {
V_32 = F_36 ( V_9 -> V_34 [ V_31 ] ) ;
F_37 ( V_9 -> V_12 , L_5 ,
V_32 ) ;
goto error;
}
}
return 0 ;
error:
while ( -- V_31 >= 0 )
F_38 ( V_9 -> V_34 [ V_31 ] ) ;
F_39 ( V_9 -> V_34 ) ;
V_9 -> V_34 = NULL ;
V_37:
return V_32 ;
}
static int T_3 F_40 ( struct V_1 * V_2 ,
const struct V_46 * V_45 )
{
struct V_9 * V_9 ;
struct V_29 * V_30 = V_2 -> V_12 . V_47 ;
int V_6 ;
T_1 V_10 ;
if ( ! V_30 ) {
F_7 ( & V_2 -> V_12 , L_6 ) ;
return - V_48 ;
}
V_9 = F_41 ( sizeof( struct V_9 ) , V_35 ) ;
if ( ! V_9 )
return - V_36 ;
V_9 -> V_2 = V_2 ;
V_9 -> V_12 = & V_2 -> V_12 ;
F_42 ( & V_9 -> V_11 ) ;
V_6 = F_1 ( V_2 , V_49 , 1 , & V_10 ) ;
if ( V_6 == 0 &&
( V_10 & V_50 ) != V_51 ) {
V_6 = - V_48 ;
F_37 ( & V_2 -> V_12 , L_7 , V_10 ) ;
}
if ( V_6 < 0 ) {
F_37 ( & V_2 -> V_12 , L_8 , V_6 ) ;
goto V_52;
}
V_6 = F_32 ( V_9 , V_30 ) ;
if ( V_6 < 0 )
goto V_52;
F_43 ( V_2 , V_9 ) ;
return 0 ;
V_52:
F_39 ( V_9 ) ;
return V_6 ;
}
static int T_4 F_44 ( struct V_1 * V_2 )
{
struct V_9 * V_9 = F_45 ( V_2 ) ;
int V_31 ;
for ( V_31 = 0 ; V_31 < V_9 -> V_33 ; V_31 ++ )
F_38 ( V_9 -> V_34 [ V_31 ] ) ;
F_39 ( V_9 -> V_34 ) ;
F_39 ( V_9 ) ;
return 0 ;
}
static int T_5 F_46 ( void )
{
return F_47 ( & V_53 ) ;
}
static void T_6 F_48 ( void )
{
F_49 ( & V_53 ) ;
}
