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
V_15 = 0 ;
V_16 = 0 ;
for ( V_14 = 0 ; V_14 < V_17 ; V_14 ++ ) {
F_4 ( V_6 , V_18 , V_2 ,
L_1 , V_14 ,
V_4 -> V_11 [ V_14 ] , V_4 -> V_19 [ V_14 ] ,
V_4 -> V_12 [ V_14 ] ) ;
F_4 ( V_6 , V_18 , V_2 , L_2 , V_14 ,
V_4 -> V_13 [ V_14 ] ) ;
if ( ( V_4 -> V_11 [ V_14 ] || V_4 -> V_12 [ V_14 ] ) &&
( V_14 >= V_6 -> V_8 . V_9 ) )
return - V_20 ;
if ( V_4 -> V_13 [ V_14 ] >= V_6 -> V_8 . V_9 )
return - V_20 ;
switch ( V_4 -> V_12 [ V_14 ] ) {
case V_21 :
break;
case V_22 :
V_15 = 1 ;
V_16 += V_4 -> V_11 [ V_14 ] ;
break;
default:
return - V_20 ;
}
}
if ( V_15 && ( V_16 != 100 ) )
return - V_20 ;
if ( ! V_6 -> V_4 ) {
V_6 -> V_4 = F_5 ( V_6 -> V_23 , sizeof( * V_6 -> V_4 ) ,
V_24 ) ;
if ( ! V_6 -> V_4 )
return - V_25 ;
}
memcpy ( V_6 -> V_4 , V_4 , sizeof( * V_6 -> V_4 ) ) ;
V_6 -> V_26 . V_27 ( V_6 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_28 * V_29 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_29 -> V_30 = V_6 -> V_8 . V_9 ;
if ( V_6 -> V_29 ) {
V_29 -> V_31 = V_6 -> V_29 -> V_31 ;
V_29 -> V_32 = V_6 -> V_29 -> V_32 ;
V_29 -> V_33 = V_6 -> V_29 -> V_33 ;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_28 * V_29 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_4 ( V_6 , V_18 , V_2 ,
L_3 ,
V_29 -> V_30 , V_29 -> V_31 , V_29 -> V_32 , V_29 -> V_33 ) ;
if ( ! V_6 -> V_29 ) {
V_6 -> V_29 = F_5 ( V_6 -> V_23 , sizeof( * V_6 -> V_29 ) ,
V_24 ) ;
if ( ! V_6 -> V_29 )
return - V_25 ;
}
memcpy ( V_6 -> V_29 , V_29 , sizeof( * V_6 -> V_29 ) ) ;
V_6 -> V_26 . V_34 ( V_6 ) ;
return 0 ;
}
static T_1 F_8 ( struct V_1 * V_2 )
{
return V_35 | V_36 ;
}
static T_1 F_9 ( struct V_1 * V_2 , T_1 V_37 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_38 = F_8 ( V_2 ) ;
F_4 ( V_6 , V_18 , V_2 , L_4 , V_37 ) ;
if ( V_37 & ~ V_38 )
return 1 ;
if ( ( V_37 & V_38 ) != V_38 )
return 1 ;
return 0 ;
}
const struct V_39 * F_10 ( void )
{
return & V_40 ;
}
