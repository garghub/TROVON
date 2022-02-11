static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
int V_4 = F_2 ( V_2 ) - V_5 ;
if ( V_3 > V_6 )
return - V_7 ;
return 1000 * F_3 ( V_4 ) [ V_3 ] ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_8 * V_8 = F_5 ( V_2 ) ;
int V_4 = F_2 ( V_2 ) - V_5 ;
T_1 V_9 = 1 << ( 1 + V_4 ) ;
T_1 V_10 ;
V_10 = F_6 ( V_8 , V_11 ) ;
return ( V_10 & V_9 ) != 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_8 * V_8 = F_5 ( V_2 ) ;
int V_4 = F_2 ( V_2 ) - V_5 ;
T_1 V_9 = 1 << ( 1 + V_4 ) ;
return F_8 ( V_8 , V_11 , V_9 , V_9 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_8 * V_8 = F_5 ( V_2 ) ;
int V_4 = F_2 ( V_2 ) - V_5 ;
T_1 V_9 = 1 << ( 1 + V_4 ) ;
return F_8 ( V_8 , V_11 , V_9 , 0 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_8 * V_8 = F_5 ( V_2 ) ;
int V_4 = F_2 ( V_2 ) - V_5 ;
T_1 V_10 , V_12 ;
V_12 = F_6 ( V_8 , F_11 ( V_4 ) ) ;
V_10 = ( V_12 >> F_12 ( V_4 ) ) & V_13 ;
return 1000 * F_3 ( V_4 ) [ V_10 ] ;
}
static int F_13 ( struct V_1 * V_2 ,
unsigned int V_14 )
{
struct V_8 * V_8 = F_5 ( V_2 ) ;
int V_4 = F_2 ( V_2 ) - V_5 ;
return F_8 ( V_8 , F_11 ( V_4 ) ,
V_13 << F_12 ( V_4 ) ,
V_14 << F_12 ( V_4 ) ) ;
}
static int F_14 ( struct V_1 * V_2 , unsigned V_3 )
{
if ( V_3 < V_15 || V_3 > V_16 )
return - V_7 ;
return 1000 * V_17 [ V_3 ] ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_8 * V_8 = F_5 ( V_2 ) ;
int V_18 = F_2 ( V_2 ) - V_19 ;
T_1 V_9 = 1 << ( V_18 * 2 ) ;
T_1 V_10 ;
V_10 = F_6 ( V_8 , V_20 ) ;
return ( V_10 & V_9 ) != 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_8 * V_8 = F_5 ( V_2 ) ;
int V_18 = F_2 ( V_2 ) - V_19 ;
T_1 V_9 = 1 << ( V_18 * 2 ) ;
return F_8 ( V_8 , V_20 , V_9 , V_9 ) ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_8 * V_8 = F_5 ( V_2 ) ;
int V_18 = F_2 ( V_2 ) - V_19 ;
T_1 V_9 = 1 << ( V_18 * 2 ) ;
return F_8 ( V_8 , V_20 , V_9 , 0 ) ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_8 * V_8 = F_5 ( V_2 ) ;
int V_18 = F_2 ( V_2 ) - V_19 ;
T_1 V_12 ;
int V_10 ;
V_12 = F_6 ( V_8 , F_19 ( V_18 ) ) ;
V_12 &= V_21 ;
if ( V_12 <= V_16 )
V_10 = 1000 * V_17 [ V_12 ] ;
else {
V_10 = 0 ;
F_20 ( & V_2 -> V_2 , L_1 ) ;
}
return V_10 ;
}
static int F_21 ( struct V_1 * V_2 ,
unsigned int V_14 )
{
struct V_8 * V_8 = F_5 ( V_2 ) ;
int V_18 = F_2 ( V_2 ) - V_19 ;
int V_22 ;
V_22 = F_8 ( V_8 , F_19 ( V_18 ) ,
V_21 , V_14 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_8 ( V_8 , V_23 ,
V_24 << F_22 ( V_18 ) ,
V_25 << F_22 ( V_18 ) ) ;
if ( V_22 )
return V_22 ;
return F_8 ( V_8 , V_23 ,
V_24 << F_22 ( V_18 ) ,
0 << F_22 ( V_18 ) ) ;
}
static int F_23 ( struct V_26 * V_27 , char V_12 , int V_28 ,
T_1 * V_29 )
{
int V_22 ;
if ( V_28 != 1 )
return - V_30 ;
V_22 = F_24 ( V_27 , V_12 ) ;
if ( V_22 < 0 )
return - V_30 ;
* V_29 = V_22 ;
return 0 ;
}
static int F_25 ( struct V_26 * V_27 , char V_12 , int V_28 ,
const T_1 * V_31 )
{
if ( V_28 != 1 )
return - V_30 ;
return F_26 ( V_27 , V_12 , * V_31 ) ;
}
static T_2 F_6 ( struct V_8 * V_8 , T_2 V_12 )
{
T_1 V_10 = 0 ;
F_27 ( & V_8 -> V_32 ) ;
F_23 ( V_8 -> V_27 , V_12 , 1 , & V_10 ) ;
F_28 ( V_8 -> V_2 , L_2 , ( int ) V_12 ,
( unsigned ) V_10 & 0xff ) ;
F_29 ( & V_8 -> V_32 ) ;
return V_10 & 0xff ;
}
static int F_8 ( struct V_8 * V_8 , T_2 V_12 , T_1 V_9 , T_1 V_10 )
{
T_1 V_33 ;
int V_22 ;
F_27 ( & V_8 -> V_32 ) ;
V_22 = F_23 ( V_8 -> V_27 , V_12 , 1 , & V_33 ) ;
V_33 = ( V_33 & ~ V_9 ) | V_10 ;
if ( V_22 == 0 ) {
V_22 = F_25 ( V_8 -> V_27 , V_12 , 1 , & V_33 ) ;
F_28 ( V_8 -> V_2 , L_3 , ( int ) V_12 ,
( unsigned ) V_10 & 0xff ) ;
}
F_29 ( & V_8 -> V_32 ) ;
return V_22 ;
}
static int T_3 F_30 ( struct V_8 * V_8 ,
struct V_34 * V_35 )
{
int V_36 , V_37 ;
V_8 -> V_38 = V_35 -> V_38 ;
V_8 -> V_39 = F_31 ( V_35 -> V_38 ,
sizeof( struct V_1 * ) , V_40 ) ;
if ( ! V_8 -> V_39 ) {
V_37 = - V_41 ;
goto V_42;
}
for ( V_36 = 0 ; V_36 < V_35 -> V_38 ; V_36 ++ ) {
struct V_43 V_44 = { } ;
struct V_45 * V_12 = & V_35 -> V_46 [ V_36 ] ;
V_44 . V_2 = V_8 -> V_2 ;
V_44 . V_47 = V_12 -> V_48 ;
V_44 . V_49 = V_8 ;
V_8 -> V_39 [ V_36 ] = F_32 ( & V_46 [ V_12 -> V_50 ] ,
& V_44 ) ;
if ( F_33 ( V_8 -> V_39 [ V_36 ] ) ) {
V_37 = F_34 ( V_8 -> V_39 [ V_36 ] ) ;
F_35 ( V_8 -> V_2 , L_4 ,
V_37 ) ;
goto error;
}
}
return 0 ;
error:
while ( -- V_36 >= 0 )
F_36 ( V_8 -> V_39 [ V_36 ] ) ;
F_37 ( V_8 -> V_39 ) ;
V_8 -> V_39 = NULL ;
V_42:
return V_37 ;
}
static int T_3 F_38 ( struct V_26 * V_27 ,
const struct V_51 * V_50 )
{
struct V_8 * V_8 ;
struct V_34 * V_35 = V_27 -> V_2 . V_52 ;
int V_22 ;
T_1 V_10 ;
if ( ! V_35 ) {
F_28 ( & V_27 -> V_2 , L_5 ) ;
return - V_53 ;
}
V_8 = F_39 ( sizeof( struct V_8 ) , V_40 ) ;
if ( V_8 == NULL )
return - V_41 ;
V_8 -> V_27 = V_27 ;
V_8 -> V_2 = & V_27 -> V_2 ;
F_40 ( & V_8 -> V_32 ) ;
V_22 = F_23 ( V_27 , V_54 , 1 , & V_10 ) ;
if ( V_22 == 0 && ( V_10 & V_55 ) != V_56 )
V_22 = - V_53 ;
if ( V_22 < 0 ) {
F_35 ( & V_27 -> V_2 , L_6 ) ;
goto V_57;
}
V_22 = F_30 ( V_8 , V_35 ) ;
if ( V_22 < 0 )
goto V_57;
F_41 ( V_27 , V_8 ) ;
return 0 ;
V_57:
F_37 ( V_8 ) ;
return V_22 ;
}
static int T_4 F_42 ( struct V_26 * V_27 )
{
struct V_8 * V_8 = F_43 ( V_27 ) ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_8 -> V_38 ; V_36 ++ )
F_36 ( V_8 -> V_39 [ V_36 ] ) ;
F_37 ( V_8 -> V_39 ) ;
F_37 ( V_8 ) ;
return 0 ;
}
