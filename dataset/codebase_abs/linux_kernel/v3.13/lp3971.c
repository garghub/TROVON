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
return V_7 ;
}
static int F_11 ( struct V_1 * V_2 ,
unsigned int V_11 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
int V_4 = F_3 ( V_2 ) - V_5 ;
return F_6 ( V_3 , F_9 ( V_4 ) ,
V_10 << F_10 ( V_4 ) ,
V_11 << F_10 ( V_4 ) ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
int V_12 = F_3 ( V_2 ) - V_13 ;
T_1 V_6 = 1 << ( V_12 * 2 ) ;
T_1 V_7 ;
V_7 = F_4 ( V_3 , V_14 ) ;
return ( V_7 & V_6 ) != 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
int V_12 = F_3 ( V_2 ) - V_13 ;
T_1 V_6 = 1 << ( V_12 * 2 ) ;
return F_6 ( V_3 , V_14 , V_6 , V_6 ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
int V_12 = F_3 ( V_2 ) - V_13 ;
T_1 V_6 = 1 << ( V_12 * 2 ) ;
return F_6 ( V_3 , V_14 , V_6 , 0 ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
int V_12 = F_3 ( V_2 ) - V_13 ;
T_1 V_9 ;
V_9 = F_4 ( V_3 , F_16 ( V_12 ) ) ;
V_9 &= V_15 ;
return V_9 ;
}
static int F_17 ( struct V_1 * V_2 ,
unsigned int V_11 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
int V_12 = F_3 ( V_2 ) - V_13 ;
int V_16 ;
V_16 = F_6 ( V_3 , F_16 ( V_12 ) ,
V_15 , V_11 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_6 ( V_3 , V_17 ,
V_18 << F_18 ( V_12 ) ,
V_19 << F_18 ( V_12 ) ) ;
if ( V_16 )
return V_16 ;
return F_6 ( V_3 , V_17 ,
V_18 << F_18 ( V_12 ) ,
0 << F_18 ( V_12 ) ) ;
}
static int F_19 ( struct V_20 * V_21 , char V_9 , int V_22 ,
T_1 * V_23 )
{
int V_16 ;
if ( V_22 != 1 )
return - V_24 ;
V_16 = F_20 ( V_21 , V_9 ) ;
if ( V_16 < 0 )
return - V_24 ;
* V_23 = V_16 ;
return 0 ;
}
static int F_21 ( struct V_20 * V_21 , char V_9 , int V_22 ,
const T_1 * V_25 )
{
if ( V_22 != 1 )
return - V_24 ;
return F_22 ( V_21 , V_9 , * V_25 ) ;
}
static T_2 F_4 ( struct V_3 * V_3 , T_2 V_9 )
{
T_1 V_7 = 0 ;
F_23 ( & V_3 -> V_26 ) ;
F_19 ( V_3 -> V_21 , V_9 , 1 , & V_7 ) ;
F_24 ( V_3 -> V_2 , L_1 , ( int ) V_9 ,
( unsigned ) V_7 & 0xff ) ;
F_25 ( & V_3 -> V_26 ) ;
return V_7 & 0xff ;
}
static int F_6 ( struct V_3 * V_3 , T_2 V_9 , T_1 V_6 , T_1 V_7 )
{
T_1 V_27 ;
int V_16 ;
F_23 ( & V_3 -> V_26 ) ;
V_16 = F_19 ( V_3 -> V_21 , V_9 , 1 , & V_27 ) ;
V_27 = ( V_27 & ~ V_6 ) | V_7 ;
if ( V_16 == 0 ) {
V_16 = F_21 ( V_3 -> V_21 , V_9 , 1 , & V_27 ) ;
F_24 ( V_3 -> V_2 , L_2 , ( int ) V_9 ,
( unsigned ) V_7 & 0xff ) ;
}
F_25 ( & V_3 -> V_26 ) ;
return V_16 ;
}
static int F_26 ( struct V_3 * V_3 ,
struct V_28 * V_29 )
{
int V_30 , V_31 ;
V_3 -> V_32 = V_29 -> V_32 ;
V_3 -> V_33 = F_27 ( V_29 -> V_32 ,
sizeof( struct V_1 * ) , V_34 ) ;
if ( ! V_3 -> V_33 ) {
V_31 = - V_35 ;
goto V_36;
}
for ( V_30 = 0 ; V_30 < V_29 -> V_32 ; V_30 ++ ) {
struct V_37 V_38 = { } ;
struct V_39 * V_9 = & V_29 -> V_40 [ V_30 ] ;
V_38 . V_2 = V_3 -> V_2 ;
V_38 . V_41 = V_9 -> V_42 ;
V_38 . V_43 = V_3 ;
V_3 -> V_33 [ V_30 ] = F_28 ( & V_40 [ V_9 -> V_44 ] ,
& V_38 ) ;
if ( F_29 ( V_3 -> V_33 [ V_30 ] ) ) {
V_31 = F_30 ( V_3 -> V_33 [ V_30 ] ) ;
F_31 ( V_3 -> V_2 , L_3 ,
V_31 ) ;
goto error;
}
}
return 0 ;
error:
while ( -- V_30 >= 0 )
F_32 ( V_3 -> V_33 [ V_30 ] ) ;
F_33 ( V_3 -> V_33 ) ;
V_3 -> V_33 = NULL ;
V_36:
return V_31 ;
}
static int F_34 ( struct V_20 * V_21 ,
const struct V_45 * V_44 )
{
struct V_3 * V_3 ;
struct V_28 * V_29 = F_35 ( & V_21 -> V_2 ) ;
int V_16 ;
T_1 V_7 ;
if ( ! V_29 ) {
F_24 ( & V_21 -> V_2 , L_4 ) ;
return - V_46 ;
}
V_3 = F_36 ( & V_21 -> V_2 , sizeof( struct V_3 ) , V_34 ) ;
if ( V_3 == NULL )
return - V_35 ;
V_3 -> V_21 = V_21 ;
V_3 -> V_2 = & V_21 -> V_2 ;
F_37 ( & V_3 -> V_26 ) ;
V_16 = F_19 ( V_21 , V_47 , 1 , & V_7 ) ;
if ( V_16 == 0 && ( V_7 & V_48 ) != V_49 )
V_16 = - V_46 ;
if ( V_16 < 0 ) {
F_31 ( & V_21 -> V_2 , L_5 ) ;
return V_16 ;
}
V_16 = F_26 ( V_3 , V_29 ) ;
if ( V_16 < 0 )
return V_16 ;
F_38 ( V_21 , V_3 ) ;
return 0 ;
}
static int F_39 ( struct V_20 * V_21 )
{
struct V_3 * V_3 = F_40 ( V_21 ) ;
int V_30 ;
for ( V_30 = 0 ; V_30 < V_3 -> V_32 ; V_30 ++ )
F_32 ( V_3 -> V_33 [ V_30 ] ) ;
F_33 ( V_3 -> V_33 ) ;
return 0 ;
}
