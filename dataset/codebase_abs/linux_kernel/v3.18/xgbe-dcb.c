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
F_4 ( L_1 , V_14 ,
V_4 -> V_11 [ V_14 ] , V_4 -> V_18 [ V_14 ] , V_4 -> V_12 [ V_14 ] ) ;
F_4 ( L_2 , V_14 , V_4 -> V_13 [ V_14 ] ) ;
if ( ( V_4 -> V_11 [ V_14 ] || V_4 -> V_12 [ V_14 ] ) &&
( V_14 >= V_6 -> V_8 . V_9 ) )
return - V_19 ;
if ( V_4 -> V_13 [ V_14 ] >= V_6 -> V_8 . V_9 )
return - V_19 ;
switch ( V_4 -> V_12 [ V_14 ] ) {
case V_20 :
break;
case V_21 :
V_15 = 1 ;
V_16 += V_4 -> V_11 [ V_14 ] ;
break;
default:
return - V_19 ;
}
}
if ( V_15 && ( V_16 != 100 ) )
return - V_19 ;
if ( ! V_6 -> V_4 ) {
V_6 -> V_4 = F_5 ( V_6 -> V_22 , sizeof( * V_6 -> V_4 ) ,
V_23 ) ;
if ( ! V_6 -> V_4 )
return - V_24 ;
}
memcpy ( V_6 -> V_4 , V_4 , sizeof( * V_6 -> V_4 ) ) ;
V_6 -> V_25 . V_26 ( V_6 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_27 * V_28 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_28 -> V_29 = V_6 -> V_8 . V_9 ;
if ( V_6 -> V_28 ) {
V_28 -> V_30 = V_6 -> V_28 -> V_30 ;
V_28 -> V_31 = V_6 -> V_28 -> V_31 ;
V_28 -> V_32 = V_6 -> V_28 -> V_32 ;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_27 * V_28 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_4 ( L_3 ,
V_28 -> V_29 , V_28 -> V_30 , V_28 -> V_31 , V_28 -> V_32 ) ;
if ( ! V_6 -> V_28 ) {
V_6 -> V_28 = F_5 ( V_6 -> V_22 , sizeof( * V_6 -> V_28 ) ,
V_23 ) ;
if ( ! V_6 -> V_28 )
return - V_24 ;
}
memcpy ( V_6 -> V_28 , V_28 , sizeof( * V_6 -> V_28 ) ) ;
V_6 -> V_25 . V_33 ( V_6 ) ;
return 0 ;
}
static T_1 F_8 ( struct V_1 * V_2 )
{
return V_34 | V_35 ;
}
static T_1 F_9 ( struct V_1 * V_2 , T_1 V_36 )
{
T_1 V_37 = F_8 ( V_2 ) ;
F_4 ( L_4 , V_36 ) ;
if ( V_36 & ~ V_37 )
return 1 ;
if ( ( V_36 & V_37 ) != V_37 )
return 1 ;
return 0 ;
}
const struct V_38 * F_10 ( void )
{
return & V_39 ;
}
