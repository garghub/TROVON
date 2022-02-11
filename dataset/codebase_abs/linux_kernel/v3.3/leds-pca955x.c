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
struct V_9 * V_10 = F_5 ( V_6 ) ;
F_6 ( V_6 ,
F_1 ( V_10 -> V_11 -> V_1 ) + 2 * V_7 ,
V_8 ) ;
}
static void F_7 ( struct V_5 * V_6 , int V_7 , T_1 V_8 )
{
struct V_9 * V_10 = F_5 ( V_6 ) ;
F_6 ( V_6 ,
F_1 ( V_10 -> V_11 -> V_1 ) + 1 + 2 * V_7 ,
V_8 ) ;
}
static void F_8 ( struct V_5 * V_6 , int V_7 , T_1 V_8 )
{
struct V_9 * V_10 = F_5 ( V_6 ) ;
F_6 ( V_6 ,
F_1 ( V_10 -> V_11 -> V_1 ) + 4 + V_7 ,
V_8 ) ;
}
static T_1 F_9 ( struct V_5 * V_6 , int V_7 )
{
struct V_9 * V_10 = F_5 ( V_6 ) ;
return ( T_1 ) F_10 ( V_6 ,
F_1 ( V_10 -> V_11 -> V_1 ) + 4 + V_7 ) ;
}
static void F_11 ( struct V_12 * V_13 )
{
struct V_9 * V_10 ;
T_1 V_14 ;
int V_15 ;
int V_16 ;
V_10 = F_12 ( V_13 , struct V_9 , V_13 ) ;
V_15 = V_10 -> V_3 / 4 ;
V_16 = V_10 -> V_3 % 4 ;
V_14 = F_9 ( V_10 -> V_6 , V_15 ) ;
switch ( V_10 -> V_17 ) {
case V_18 :
V_14 = F_3 ( V_14 , V_16 , V_19 ) ;
break;
case V_20 :
V_14 = F_3 ( V_14 , V_16 , V_21 ) ;
break;
case V_22 :
V_14 = F_3 ( V_14 , V_16 , V_23 ) ;
break;
default:
F_7 ( V_10 -> V_6 , 1 , 255 - V_10 -> V_17 ) ;
V_14 = F_3 ( V_14 , V_16 , V_24 ) ;
break;
}
F_8 ( V_10 -> V_6 , V_15 , V_14 ) ;
}
static void F_13 ( struct V_25 * V_26 , enum V_27 V_28 )
{
struct V_9 * V_10 ;
V_10 = F_12 ( V_26 , struct V_9 , V_26 ) ;
F_14 ( & V_10 -> V_29 ) ;
V_10 -> V_17 = V_28 ;
F_15 ( & V_10 -> V_13 ) ;
F_16 ( & V_10 -> V_29 ) ;
}
static int T_2 F_17 ( struct V_5 * V_6 ,
const struct V_30 * V_31 )
{
struct V_9 * V_10 ;
struct V_32 * V_33 ;
struct V_34 * V_35 ;
struct V_36 * V_37 ;
int V_38 , V_39 ;
V_33 = & V_40 [ V_31 -> V_41 ] ;
V_35 = F_18 ( V_6 -> V_42 . V_43 ) ;
V_37 = V_6 -> V_42 . V_44 ;
if ( ( V_6 -> V_45 & ~ ( ( 1 << V_33 -> V_46 ) - 1 ) ) !=
V_33 -> V_47 ) {
F_19 ( & V_6 -> V_42 , L_1 ,
V_6 -> V_45 ) ;
return - V_48 ;
}
F_20 ( V_49 L_2
L_3 ,
V_31 -> V_50 , V_33 -> V_1 , V_6 -> V_45 ) ;
if ( ! F_21 ( V_35 , V_51 ) )
return - V_52 ;
if ( V_37 ) {
if ( V_37 -> V_53 != V_33 -> V_1 ) {
F_19 ( & V_6 -> V_42 , L_4
L_5 ,
V_37 -> V_53 , V_33 -> V_1 ) ;
return - V_48 ;
}
}
V_10 = F_22 ( sizeof( * V_10 ) * V_33 -> V_1 , V_54 ) ;
if ( ! V_10 )
return - V_55 ;
F_23 ( V_6 , V_10 ) ;
for ( V_38 = 0 ; V_38 < V_33 -> V_1 ; V_38 ++ ) {
V_10 [ V_38 ] . V_11 = V_33 ;
V_10 [ V_38 ] . V_6 = V_6 ;
V_10 [ V_38 ] . V_3 = V_38 ;
if ( V_37 ) {
if ( V_37 -> V_56 [ V_38 ] . V_50 )
snprintf ( V_10 [ V_38 ] . V_50 ,
sizeof( V_10 [ V_38 ] . V_50 ) , L_6 ,
V_37 -> V_56 [ V_38 ] . V_50 ) ;
if ( V_37 -> V_56 [ V_38 ] . V_57 )
V_10 [ V_38 ] . V_26 . V_57 =
V_37 -> V_56 [ V_38 ] . V_57 ;
} else {
snprintf ( V_10 [ V_38 ] . V_50 , sizeof( V_10 [ V_38 ] . V_50 ) ,
L_7 , V_38 ) ;
}
F_24 ( & V_10 [ V_38 ] . V_29 ) ;
V_10 [ V_38 ] . V_26 . V_50 = V_10 [ V_38 ] . V_50 ;
V_10 [ V_38 ] . V_26 . V_58 = F_13 ;
F_25 ( & V_10 [ V_38 ] . V_13 , F_11 ) ;
V_39 = F_26 ( & V_6 -> V_42 , & V_10 [ V_38 ] . V_26 ) ;
if ( V_39 < 0 )
goto exit;
}
for ( V_38 = 0 ; V_38 < F_2 ( V_33 -> V_1 ) ; V_38 ++ )
F_8 ( V_6 , V_38 , 0x55 ) ;
F_7 ( V_6 , 0 , 255 - V_22 ) ;
F_7 ( V_6 , 1 , 0 ) ;
F_4 ( V_6 , 0 , 0 ) ;
F_4 ( V_6 , 1 , 0 ) ;
return 0 ;
exit:
while ( V_38 -- ) {
F_27 ( & V_10 [ V_38 ] . V_26 ) ;
F_28 ( & V_10 [ V_38 ] . V_13 ) ;
}
F_29 ( V_10 ) ;
return V_39 ;
}
static int T_3 F_30 ( struct V_5 * V_6 )
{
struct V_9 * V_10 = F_5 ( V_6 ) ;
int V_38 ;
for ( V_38 = 0 ; V_38 < V_10 -> V_11 -> V_1 ; V_38 ++ ) {
F_27 ( & V_10 [ V_38 ] . V_26 ) ;
F_28 ( & V_10 [ V_38 ] . V_13 ) ;
}
F_29 ( V_10 ) ;
return 0 ;
}
