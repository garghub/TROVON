static inline int F_1 ( int V_1 )
{
return ( V_1 + 7 ) / 8 ;
}
static inline int F_2 ( int V_1 )
{
return ( V_1 + 3 ) / 4 ;
}
static inline T_1 F_3 ( T_1 V_2 , int V_3 , int V_4 )
{
return ( V_2 & ( ~ ( 0x3 << ( V_3 << 1 ) ) ) ) |
( ( V_4 & 0x3 ) << ( V_3 << 1 ) ) ;
}
static void F_4 ( struct V_5 * V_6 , int V_7 , T_1 V_8 )
{
struct V_9 * V_9 = F_5 ( V_6 ) ;
F_6 ( V_6 ,
F_1 ( V_9 -> V_10 -> V_1 ) + 2 * V_7 ,
V_8 ) ;
}
static void F_7 ( struct V_5 * V_6 , int V_7 , T_1 V_8 )
{
struct V_9 * V_9 = F_5 ( V_6 ) ;
F_6 ( V_6 ,
F_1 ( V_9 -> V_10 -> V_1 ) + 1 + 2 * V_7 ,
V_8 ) ;
}
static void F_8 ( struct V_5 * V_6 , int V_7 , T_1 V_8 )
{
struct V_9 * V_9 = F_5 ( V_6 ) ;
F_6 ( V_6 ,
F_1 ( V_9 -> V_10 -> V_1 ) + 4 + V_7 ,
V_8 ) ;
}
static T_1 F_9 ( struct V_5 * V_6 , int V_7 )
{
struct V_9 * V_9 = F_5 ( V_6 ) ;
return ( T_1 ) F_10 ( V_6 ,
F_1 ( V_9 -> V_10 -> V_1 ) + 4 + V_7 ) ;
}
static int F_11 ( struct V_11 * V_12 ,
enum V_13 V_14 )
{
struct V_15 * V_15 ;
struct V_9 * V_9 ;
T_1 V_16 ;
int V_17 ;
int V_18 ;
V_15 = F_12 ( V_12 , struct V_15 , V_12 ) ;
V_9 = V_15 -> V_9 ;
V_17 = V_15 -> V_3 / 4 ;
V_18 = V_15 -> V_3 % 4 ;
F_13 ( & V_9 -> V_19 ) ;
V_16 = F_9 ( V_9 -> V_6 , V_17 ) ;
switch ( V_14 ) {
case V_20 :
V_16 = F_3 ( V_16 , V_18 , V_21 ) ;
break;
case V_22 :
V_16 = F_3 ( V_16 , V_18 , V_23 ) ;
break;
case V_24 :
V_16 = F_3 ( V_16 , V_18 , V_25 ) ;
break;
default:
F_7 ( V_9 -> V_6 , 1 ,
255 - V_14 ) ;
V_16 = F_3 ( V_16 , V_18 , V_26 ) ;
break;
}
F_8 ( V_9 -> V_6 , V_17 , V_16 ) ;
F_14 ( & V_9 -> V_19 ) ;
return 0 ;
}
static int F_15 ( struct V_5 * V_6 ,
const struct V_27 * V_28 )
{
struct V_9 * V_9 ;
struct V_15 * V_15 ;
struct V_29 * V_30 ;
struct V_31 * V_32 ;
struct V_33 * V_34 ;
int V_35 , V_36 ;
V_30 = & V_37 [ V_28 -> V_38 ] ;
V_32 = F_16 ( V_6 -> V_39 . V_40 ) ;
V_34 = F_17 ( & V_6 -> V_39 ) ;
if ( ( V_6 -> V_41 & ~ ( ( 1 << V_30 -> V_42 ) - 1 ) ) !=
V_30 -> V_43 ) {
F_18 ( & V_6 -> V_39 , L_1 ,
V_6 -> V_41 ) ;
return - V_44 ;
}
F_19 ( & V_6 -> V_39 , L_2
L_3 ,
V_28 -> V_45 , V_30 -> V_1 , V_6 -> V_41 ) ;
if ( ! F_20 ( V_32 , V_46 ) )
return - V_47 ;
if ( V_34 ) {
if ( V_34 -> V_48 != V_30 -> V_1 ) {
F_18 ( & V_6 -> V_39 , L_4
L_5 ,
V_34 -> V_48 , V_30 -> V_1 ) ;
return - V_44 ;
}
}
V_9 = F_21 ( & V_6 -> V_39 , sizeof( * V_9 ) , V_49 ) ;
if ( ! V_9 )
return - V_50 ;
V_9 -> V_51 = F_21 ( & V_6 -> V_39 ,
sizeof( * V_15 ) * V_30 -> V_1 , V_49 ) ;
if ( ! V_9 -> V_51 )
return - V_50 ;
F_22 ( V_6 , V_9 ) ;
F_23 ( & V_9 -> V_19 ) ;
V_9 -> V_6 = V_6 ;
V_9 -> V_10 = V_30 ;
for ( V_35 = 0 ; V_35 < V_30 -> V_1 ; V_35 ++ ) {
V_15 = & V_9 -> V_51 [ V_35 ] ;
V_15 -> V_3 = V_35 ;
V_15 -> V_9 = V_9 ;
if ( V_34 ) {
if ( V_34 -> V_51 [ V_35 ] . V_45 )
snprintf ( V_15 -> V_45 ,
sizeof( V_15 -> V_45 ) , L_6 ,
V_34 -> V_51 [ V_35 ] . V_45 ) ;
if ( V_34 -> V_51 [ V_35 ] . V_52 )
V_15 -> V_12 . V_52 =
V_34 -> V_51 [ V_35 ] . V_52 ;
} else {
snprintf ( V_15 -> V_45 , sizeof( V_15 -> V_45 ) ,
L_7 , V_35 ) ;
}
V_15 -> V_12 . V_45 = V_15 -> V_45 ;
V_15 -> V_12 . V_53 = F_11 ;
V_36 = F_24 ( & V_6 -> V_39 ,
& V_15 -> V_12 ) ;
if ( V_36 < 0 )
goto exit;
}
for ( V_35 = 0 ; V_35 < F_2 ( V_30 -> V_1 ) ; V_35 ++ )
F_8 ( V_6 , V_35 , 0x55 ) ;
F_7 ( V_6 , 0 , 255 - V_24 ) ;
F_7 ( V_6 , 1 , 0 ) ;
F_4 ( V_6 , 0 , 0 ) ;
F_4 ( V_6 , 1 , 0 ) ;
return 0 ;
exit:
while ( V_35 -- )
F_25 ( & V_9 -> V_51 [ V_35 ] . V_12 ) ;
return V_36 ;
}
static int F_26 ( struct V_5 * V_6 )
{
struct V_9 * V_9 = F_5 ( V_6 ) ;
int V_35 ;
for ( V_35 = 0 ; V_35 < V_9 -> V_10 -> V_1 ; V_35 ++ )
F_25 ( & V_9 -> V_51 [ V_35 ] . V_12 ) ;
return 0 ;
}
