static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
int V_4 = F_2 ( V_2 ) - V_5 ;
return 1000 * F_3 ( V_4 ) [ V_3 ] ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_6 * V_6 = F_5 ( V_2 ) ;
int V_4 = F_2 ( V_2 ) - V_5 ;
T_1 V_7 = 1 << ( 1 + V_4 ) ;
T_1 V_8 ;
V_8 = F_6 ( V_6 , V_9 ) ;
return ( V_8 & V_7 ) != 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_6 * V_6 = F_5 ( V_2 ) ;
int V_4 = F_2 ( V_2 ) - V_5 ;
T_1 V_7 = 1 << ( 1 + V_4 ) ;
return F_8 ( V_6 , V_9 , V_7 , V_7 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_6 * V_6 = F_5 ( V_2 ) ;
int V_4 = F_2 ( V_2 ) - V_5 ;
T_1 V_7 = 1 << ( 1 + V_4 ) ;
return F_8 ( V_6 , V_9 , V_7 , 0 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_6 * V_6 = F_5 ( V_2 ) ;
int V_4 = F_2 ( V_2 ) - V_5 ;
T_1 V_8 , V_10 ;
V_10 = F_6 ( V_6 , F_11 ( V_4 ) ) ;
V_8 = ( V_10 >> F_12 ( V_4 ) ) & V_11 ;
return 1000 * F_3 ( V_4 ) [ V_8 ] ;
}
static int F_13 ( struct V_1 * V_2 ,
int V_12 , int V_13 ,
unsigned int * V_14 )
{
struct V_6 * V_6 = F_5 ( V_2 ) ;
int V_4 = F_2 ( V_2 ) - V_5 ;
int V_15 = V_12 / 1000 , V_16 = V_13 / 1000 ;
const int * V_17 = F_3 ( V_4 ) ;
T_1 V_8 ;
if ( V_15 < V_17 [ V_18 ] ||
V_15 > V_17 [ V_19 ] )
return - V_20 ;
for ( V_8 = V_18 ; V_8 <= V_19 ; V_8 ++ )
if ( V_17 [ V_8 ] >= V_15 )
break;
if ( V_8 > V_19 || V_17 [ V_8 ] > V_16 )
return - V_20 ;
* V_14 = V_8 ;
return F_8 ( V_6 , F_11 ( V_4 ) ,
V_11 << F_12 ( V_4 ) ,
V_8 << F_12 ( V_4 ) ) ;
}
static int F_14 ( struct V_1 * V_2 , unsigned V_3 )
{
return 1000 * V_21 [ V_3 ] ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_6 * V_6 = F_5 ( V_2 ) ;
int V_22 = F_2 ( V_2 ) - V_23 ;
T_1 V_7 = 1 << ( V_22 * 2 ) ;
T_1 V_8 ;
V_8 = F_6 ( V_6 , V_24 ) ;
return ( V_8 & V_7 ) != 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_6 * V_6 = F_5 ( V_2 ) ;
int V_22 = F_2 ( V_2 ) - V_23 ;
T_1 V_7 = 1 << ( V_22 * 2 ) ;
return F_8 ( V_6 , V_24 , V_7 , V_7 ) ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_6 * V_6 = F_5 ( V_2 ) ;
int V_22 = F_2 ( V_2 ) - V_23 ;
T_1 V_7 = 1 << ( V_22 * 2 ) ;
return F_8 ( V_6 , V_24 , V_7 , 0 ) ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_6 * V_6 = F_5 ( V_2 ) ;
int V_22 = F_2 ( V_2 ) - V_23 ;
T_1 V_10 ;
int V_8 ;
V_10 = F_6 ( V_6 , F_19 ( V_22 ) ) ;
V_10 &= V_25 ;
if ( V_10 <= V_26 )
V_8 = 1000 * V_21 [ V_10 ] ;
else {
V_8 = 0 ;
F_20 ( & V_2 -> V_2 , L_1 ) ;
}
return V_8 ;
}
static int F_21 ( struct V_1 * V_2 ,
int V_12 , int V_13 ,
unsigned int * V_14 )
{
struct V_6 * V_6 = F_5 ( V_2 ) ;
int V_22 = F_2 ( V_2 ) - V_23 ;
int V_15 = V_12 / 1000 , V_16 = V_13 / 1000 ;
const int * V_17 = V_21 ;
T_1 V_8 ;
int V_27 ;
if ( V_15 < V_17 [ V_28 ] ||
V_15 > V_17 [ V_26 ] )
return - V_20 ;
for ( V_8 = V_28 ; V_8 <= V_26 ;
V_8 ++ )
if ( V_17 [ V_8 ] >= V_15 )
break;
if ( V_8 > V_26 || V_17 [ V_8 ] > V_16 )
return - V_20 ;
* V_14 = V_8 ;
V_27 = F_8 ( V_6 , F_19 ( V_22 ) ,
V_25 , V_8 ) ;
if ( V_27 )
return V_27 ;
V_27 = F_8 ( V_6 , V_29 ,
V_30 << F_22 ( V_22 ) ,
V_31 << F_22 ( V_22 ) ) ;
if ( V_27 )
return V_27 ;
return F_8 ( V_6 , V_29 ,
V_30 << F_22 ( V_22 ) ,
0 << F_22 ( V_22 ) ) ;
}
static int F_23 ( struct V_32 * V_33 , char V_10 , int V_34 ,
T_1 * V_35 )
{
int V_27 ;
if ( V_34 != 1 )
return - V_36 ;
V_27 = F_24 ( V_33 , V_10 ) ;
if ( V_27 < 0 )
return - V_36 ;
* V_35 = V_27 ;
return 0 ;
}
static int F_25 ( struct V_32 * V_33 , char V_10 , int V_34 ,
const T_1 * V_37 )
{
if ( V_34 != 1 )
return - V_36 ;
return F_26 ( V_33 , V_10 , * V_37 ) ;
}
static T_2 F_6 ( struct V_6 * V_6 , T_2 V_10 )
{
T_1 V_8 = 0 ;
F_27 ( & V_6 -> V_38 ) ;
F_23 ( V_6 -> V_33 , V_10 , 1 , & V_8 ) ;
F_28 ( V_6 -> V_2 , L_2 , ( int ) V_10 ,
( unsigned ) V_8 & 0xff ) ;
F_29 ( & V_6 -> V_38 ) ;
return V_8 & 0xff ;
}
static int F_8 ( struct V_6 * V_6 , T_2 V_10 , T_1 V_7 , T_1 V_8 )
{
T_1 V_39 ;
int V_27 ;
F_27 ( & V_6 -> V_38 ) ;
V_27 = F_23 ( V_6 -> V_33 , V_10 , 1 , & V_39 ) ;
V_39 = ( V_39 & ~ V_7 ) | V_8 ;
if ( V_27 == 0 ) {
V_27 = F_25 ( V_6 -> V_33 , V_10 , 1 , & V_39 ) ;
F_28 ( V_6 -> V_2 , L_3 , ( int ) V_10 ,
( unsigned ) V_8 & 0xff ) ;
}
F_29 ( & V_6 -> V_38 ) ;
return V_27 ;
}
static int T_3 F_30 ( struct V_6 * V_6 ,
struct V_40 * V_41 )
{
int V_42 , V_43 ;
V_6 -> V_44 = V_41 -> V_44 ;
V_6 -> V_45 = F_31 ( V_41 -> V_44 ,
sizeof( struct V_1 * ) , V_46 ) ;
if ( ! V_6 -> V_45 ) {
V_43 = - V_47 ;
goto V_48;
}
for ( V_42 = 0 ; V_42 < V_41 -> V_44 ; V_42 ++ ) {
struct V_49 * V_10 = & V_41 -> V_50 [ V_42 ] ;
V_6 -> V_45 [ V_42 ] = F_32 ( & V_50 [ V_10 -> V_51 ] ,
V_6 -> V_2 , V_10 -> V_52 , V_6 , NULL ) ;
if ( F_33 ( V_6 -> V_45 [ V_42 ] ) ) {
V_43 = F_34 ( V_6 -> V_45 [ V_42 ] ) ;
F_35 ( V_6 -> V_2 , L_4 ,
V_43 ) ;
goto error;
}
}
return 0 ;
error:
while ( -- V_42 >= 0 )
F_36 ( V_6 -> V_45 [ V_42 ] ) ;
F_37 ( V_6 -> V_45 ) ;
V_6 -> V_45 = NULL ;
V_48:
return V_43 ;
}
static int T_3 F_38 ( struct V_32 * V_33 ,
const struct V_53 * V_51 )
{
struct V_6 * V_6 ;
struct V_40 * V_41 = V_33 -> V_2 . V_54 ;
int V_27 ;
T_1 V_8 ;
if ( ! V_41 ) {
F_28 ( & V_33 -> V_2 , L_5 ) ;
return - V_55 ;
}
V_6 = F_39 ( sizeof( struct V_6 ) , V_46 ) ;
if ( V_6 == NULL )
return - V_47 ;
V_6 -> V_33 = V_33 ;
V_6 -> V_2 = & V_33 -> V_2 ;
F_40 ( & V_6 -> V_38 ) ;
V_27 = F_23 ( V_33 , V_56 , 1 , & V_8 ) ;
if ( V_27 == 0 && ( V_8 & V_57 ) != V_58 )
V_27 = - V_55 ;
if ( V_27 < 0 ) {
F_35 ( & V_33 -> V_2 , L_6 ) ;
goto V_59;
}
V_27 = F_30 ( V_6 , V_41 ) ;
if ( V_27 < 0 )
goto V_59;
F_41 ( V_33 , V_6 ) ;
return 0 ;
V_59:
F_37 ( V_6 ) ;
return V_27 ;
}
static int T_4 F_42 ( struct V_32 * V_33 )
{
struct V_6 * V_6 = F_43 ( V_33 ) ;
int V_42 ;
for ( V_42 = 0 ; V_42 < V_6 -> V_44 ; V_42 ++ )
F_36 ( V_6 -> V_45 [ V_42 ] ) ;
F_37 ( V_6 -> V_45 ) ;
F_37 ( V_6 ) ;
return 0 ;
}
static int T_5 F_44 ( void )
{
int V_27 ;
V_27 = F_45 ( & V_60 ) ;
if ( V_27 != 0 )
F_46 ( L_7 , V_27 ) ;
return V_27 ;
}
static void T_6 F_47 ( void )
{
F_48 ( & V_60 ) ;
}
