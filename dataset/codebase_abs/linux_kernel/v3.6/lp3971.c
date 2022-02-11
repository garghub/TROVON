static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
int V_4 = F_3 ( V_2 ) - V_5 ;
T_1 V_6 = 1 << ( 1 + V_4 ) ;
T_1 V_7 ;
V_7 = F_4 ( V_3 , V_8 ) ;
return ( V_7 & V_6 ) != 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
int V_4 = F_3 ( V_2 ) - V_5 ;
T_1 V_6 = 1 << ( 1 + V_4 ) ;
return F_6 ( V_3 , V_8 , V_6 , V_6 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
int V_4 = F_3 ( V_2 ) - V_5 ;
T_1 V_6 = 1 << ( 1 + V_4 ) ;
return F_6 ( V_3 , V_8 , V_6 , 0 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
int V_4 = F_3 ( V_2 ) - V_5 ;
T_1 V_7 , V_9 ;
V_9 = F_4 ( V_3 , F_9 ( V_4 ) ) ;
V_7 = ( V_9 >> F_10 ( V_4 ) ) & V_10 ;
return V_2 -> V_11 -> V_12 [ V_7 ] ;
}
static int F_11 ( struct V_1 * V_2 ,
unsigned int V_13 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
int V_4 = F_3 ( V_2 ) - V_5 ;
return F_6 ( V_3 , F_9 ( V_4 ) ,
V_10 << F_10 ( V_4 ) ,
V_13 << F_10 ( V_4 ) ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
int V_14 = F_3 ( V_2 ) - V_15 ;
T_1 V_6 = 1 << ( V_14 * 2 ) ;
T_1 V_7 ;
V_7 = F_4 ( V_3 , V_16 ) ;
return ( V_7 & V_6 ) != 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
int V_14 = F_3 ( V_2 ) - V_15 ;
T_1 V_6 = 1 << ( V_14 * 2 ) ;
return F_6 ( V_3 , V_16 , V_6 , V_6 ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
int V_14 = F_3 ( V_2 ) - V_15 ;
T_1 V_6 = 1 << ( V_14 * 2 ) ;
return F_6 ( V_3 , V_16 , V_6 , 0 ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
int V_14 = F_3 ( V_2 ) - V_15 ;
T_1 V_9 ;
int V_7 ;
V_9 = F_4 ( V_3 , F_16 ( V_14 ) ) ;
V_9 &= V_17 ;
if ( V_9 <= V_18 )
V_7 = V_19 [ V_9 ] ;
else {
V_7 = 0 ;
F_17 ( & V_2 -> V_2 , L_1 ) ;
}
return V_7 ;
}
static int F_18 ( struct V_1 * V_2 ,
unsigned int V_13 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
int V_14 = F_3 ( V_2 ) - V_15 ;
int V_20 ;
V_20 = F_6 ( V_3 , F_16 ( V_14 ) ,
V_17 , V_13 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_6 ( V_3 , V_21 ,
V_22 << F_19 ( V_14 ) ,
V_23 << F_19 ( V_14 ) ) ;
if ( V_20 )
return V_20 ;
return F_6 ( V_3 , V_21 ,
V_22 << F_19 ( V_14 ) ,
0 << F_19 ( V_14 ) ) ;
}
static int F_20 ( struct V_24 * V_25 , char V_9 , int V_26 ,
T_1 * V_27 )
{
int V_20 ;
if ( V_26 != 1 )
return - V_28 ;
V_20 = F_21 ( V_25 , V_9 ) ;
if ( V_20 < 0 )
return - V_28 ;
* V_27 = V_20 ;
return 0 ;
}
static int F_22 ( struct V_24 * V_25 , char V_9 , int V_26 ,
const T_1 * V_29 )
{
if ( V_26 != 1 )
return - V_28 ;
return F_23 ( V_25 , V_9 , * V_29 ) ;
}
static T_2 F_4 ( struct V_3 * V_3 , T_2 V_9 )
{
T_1 V_7 = 0 ;
F_24 ( & V_3 -> V_30 ) ;
F_20 ( V_3 -> V_25 , V_9 , 1 , & V_7 ) ;
F_25 ( V_3 -> V_2 , L_2 , ( int ) V_9 ,
( unsigned ) V_7 & 0xff ) ;
F_26 ( & V_3 -> V_30 ) ;
return V_7 & 0xff ;
}
static int F_6 ( struct V_3 * V_3 , T_2 V_9 , T_1 V_6 , T_1 V_7 )
{
T_1 V_31 ;
int V_20 ;
F_24 ( & V_3 -> V_30 ) ;
V_20 = F_20 ( V_3 -> V_25 , V_9 , 1 , & V_31 ) ;
V_31 = ( V_31 & ~ V_6 ) | V_7 ;
if ( V_20 == 0 ) {
V_20 = F_22 ( V_3 -> V_25 , V_9 , 1 , & V_31 ) ;
F_25 ( V_3 -> V_2 , L_3 , ( int ) V_9 ,
( unsigned ) V_7 & 0xff ) ;
}
F_26 ( & V_3 -> V_30 ) ;
return V_20 ;
}
static int T_3 F_27 ( struct V_3 * V_3 ,
struct V_32 * V_33 )
{
int V_34 , V_35 ;
V_3 -> V_36 = V_33 -> V_36 ;
V_3 -> V_37 = F_28 ( V_33 -> V_36 ,
sizeof( struct V_1 * ) , V_38 ) ;
if ( ! V_3 -> V_37 ) {
V_35 = - V_39 ;
goto V_40;
}
for ( V_34 = 0 ; V_34 < V_33 -> V_36 ; V_34 ++ ) {
struct V_41 V_42 = { } ;
struct V_43 * V_9 = & V_33 -> V_44 [ V_34 ] ;
V_42 . V_2 = V_3 -> V_2 ;
V_42 . V_45 = V_9 -> V_46 ;
V_42 . V_47 = V_3 ;
V_3 -> V_37 [ V_34 ] = F_29 ( & V_44 [ V_9 -> V_48 ] ,
& V_42 ) ;
if ( F_30 ( V_3 -> V_37 [ V_34 ] ) ) {
V_35 = F_31 ( V_3 -> V_37 [ V_34 ] ) ;
F_32 ( V_3 -> V_2 , L_4 ,
V_35 ) ;
goto error;
}
}
return 0 ;
error:
while ( -- V_34 >= 0 )
F_33 ( V_3 -> V_37 [ V_34 ] ) ;
F_34 ( V_3 -> V_37 ) ;
V_3 -> V_37 = NULL ;
V_40:
return V_35 ;
}
static int T_3 F_35 ( struct V_24 * V_25 ,
const struct V_49 * V_48 )
{
struct V_3 * V_3 ;
struct V_32 * V_33 = V_25 -> V_2 . V_50 ;
int V_20 ;
T_1 V_7 ;
if ( ! V_33 ) {
F_25 ( & V_25 -> V_2 , L_5 ) ;
return - V_51 ;
}
V_3 = F_36 ( sizeof( struct V_3 ) , V_38 ) ;
if ( V_3 == NULL )
return - V_39 ;
V_3 -> V_25 = V_25 ;
V_3 -> V_2 = & V_25 -> V_2 ;
F_37 ( & V_3 -> V_30 ) ;
V_20 = F_20 ( V_25 , V_52 , 1 , & V_7 ) ;
if ( V_20 == 0 && ( V_7 & V_53 ) != V_54 )
V_20 = - V_51 ;
if ( V_20 < 0 ) {
F_32 ( & V_25 -> V_2 , L_6 ) ;
goto V_55;
}
V_20 = F_27 ( V_3 , V_33 ) ;
if ( V_20 < 0 )
goto V_55;
F_38 ( V_25 , V_3 ) ;
return 0 ;
V_55:
F_34 ( V_3 ) ;
return V_20 ;
}
static int T_4 F_39 ( struct V_24 * V_25 )
{
struct V_3 * V_3 = F_40 ( V_25 ) ;
int V_34 ;
for ( V_34 = 0 ; V_34 < V_3 -> V_36 ; V_34 ++ )
F_33 ( V_3 -> V_37 [ V_34 ] ) ;
F_34 ( V_3 -> V_37 ) ;
F_34 ( V_3 ) ;
return 0 ;
}
