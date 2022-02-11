static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_4 -> V_7 = V_6 -> V_8 . V_9 ;
if ( V_6 -> V_4 ) {
V_4 -> V_10 = V_6 -> V_4 -> V_10 ;
memcpy ( V_4 -> V_11 , V_6 -> V_4 -> V_11 ,
sizeof( V_4 -> V_11 ) ) ;
memcpy ( V_4 -> V_12 , V_6 -> V_4 -> V_12 ,
sizeof( V_4 -> V_12 ) ) ;
memcpy ( V_4 -> V_13 , V_6 -> V_4 -> V_13 ,
sizeof( V_4 -> V_13 ) ) ;
}
return 0 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_14 , V_15 , V_16 ;
T_1 V_17 = 0 ;
V_15 = 0 ;
V_16 = 0 ;
for ( V_14 = 0 ; V_14 < V_18 ; V_14 ++ ) {
F_4 ( V_6 , V_19 , V_2 ,
L_1 , V_14 ,
V_4 -> V_11 [ V_14 ] , V_4 -> V_20 [ V_14 ] ,
V_4 -> V_12 [ V_14 ] ) ;
F_4 ( V_6 , V_19 , V_2 , L_2 , V_14 ,
V_4 -> V_13 [ V_14 ] ) ;
V_17 = F_5 ( T_1 , V_17 , V_4 -> V_13 [ V_14 ] ) ;
if ( ( V_4 -> V_11 [ V_14 ] || V_4 -> V_12 [ V_14 ] ) )
V_17 = F_5 ( T_1 , V_17 , V_14 ) ;
switch ( V_4 -> V_12 [ V_14 ] ) {
case V_21 :
break;
case V_22 :
V_15 = 1 ;
V_16 += V_4 -> V_11 [ V_14 ] ;
break;
default:
F_6 ( V_6 , V_19 , V_2 ,
L_3 ,
V_4 -> V_12 [ V_14 ] ) ;
return - V_23 ;
}
}
if ( V_17 >= V_6 -> V_8 . V_9 ) {
F_6 ( V_6 , V_19 , V_2 ,
L_4 ) ;
return - V_23 ;
}
if ( V_15 && ( V_16 != 100 ) ) {
F_6 ( V_6 , V_19 , V_2 ,
L_5 ,
V_16 ) ;
return - V_23 ;
}
if ( ! V_6 -> V_4 ) {
V_6 -> V_4 = F_7 ( V_6 -> V_24 , sizeof( * V_6 -> V_4 ) ,
V_25 ) ;
if ( ! V_6 -> V_4 )
return - V_26 ;
}
V_6 -> V_27 = V_17 + 1 ;
memcpy ( V_6 -> V_4 , V_4 , sizeof( * V_6 -> V_4 ) ) ;
V_6 -> V_28 . V_29 ( V_6 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_30 * V_31 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_31 -> V_32 = V_6 -> V_8 . V_9 ;
if ( V_6 -> V_31 ) {
V_31 -> V_33 = V_6 -> V_31 -> V_33 ;
V_31 -> V_34 = V_6 -> V_31 -> V_34 ;
V_31 -> V_35 = V_6 -> V_31 -> V_35 ;
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_30 * V_31 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_4 ( V_6 , V_19 , V_2 ,
L_6 ,
V_31 -> V_32 , V_31 -> V_33 , V_31 -> V_34 , V_31 -> V_35 ) ;
if ( V_31 -> V_33 & ~ ( ( 1 << V_6 -> V_8 . V_9 ) - 1 ) ) {
F_6 ( V_6 , V_19 , V_2 ,
L_7 ) ;
return - V_23 ;
}
if ( ! V_6 -> V_31 ) {
V_6 -> V_31 = F_7 ( V_6 -> V_24 , sizeof( * V_6 -> V_31 ) ,
V_25 ) ;
if ( ! V_6 -> V_31 )
return - V_26 ;
}
memcpy ( V_6 -> V_31 , V_31 , sizeof( * V_6 -> V_31 ) ) ;
V_6 -> V_28 . V_36 ( V_6 ) ;
return 0 ;
}
static T_1 F_10 ( struct V_1 * V_2 )
{
return V_37 | V_38 ;
}
static T_1 F_11 ( struct V_1 * V_2 , T_1 V_39 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_40 = F_10 ( V_2 ) ;
F_4 ( V_6 , V_19 , V_2 , L_8 , V_39 ) ;
if ( V_39 & ~ V_40 )
return 1 ;
if ( ( V_39 & V_40 ) != V_40 )
return 1 ;
return 0 ;
}
const struct V_41 * F_12 ( void )
{
return & V_42 ;
}
