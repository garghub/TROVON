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
static void F_11 ( struct V_11 * V_12 )
{
struct V_13 * V_13 ;
struct V_9 * V_9 ;
T_1 V_14 ;
int V_15 ;
int V_16 ;
V_13 = F_12 ( V_12 , struct V_13 , V_12 ) ;
V_9 = V_13 -> V_9 ;
V_15 = V_13 -> V_3 / 4 ;
V_16 = V_13 -> V_3 % 4 ;
F_13 ( & V_9 -> V_17 ) ;
V_14 = F_9 ( V_9 -> V_6 , V_15 ) ;
switch ( V_13 -> V_18 ) {
case V_19 :
V_14 = F_3 ( V_14 , V_16 , V_20 ) ;
break;
case V_21 :
V_14 = F_3 ( V_14 , V_16 , V_22 ) ;
break;
case V_23 :
V_14 = F_3 ( V_14 , V_16 , V_24 ) ;
break;
default:
F_7 ( V_9 -> V_6 , 1 ,
255 - V_13 -> V_18 ) ;
V_14 = F_3 ( V_14 , V_16 , V_25 ) ;
break;
}
F_8 ( V_9 -> V_6 , V_15 , V_14 ) ;
F_14 ( & V_9 -> V_17 ) ;
}
static void F_15 ( struct V_26 * V_27 , enum V_28 V_29 )
{
struct V_13 * V_9 ;
V_9 = F_12 ( V_27 , struct V_13 , V_27 ) ;
V_9 -> V_18 = V_29 ;
F_16 ( & V_9 -> V_12 ) ;
}
static int F_17 ( struct V_5 * V_6 ,
const struct V_30 * V_31 )
{
struct V_9 * V_9 ;
struct V_13 * V_13 ;
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
F_20 ( & V_6 -> V_42 , L_2
L_3 ,
V_31 -> V_49 , V_33 -> V_1 , V_6 -> V_45 ) ;
if ( ! F_21 ( V_35 , V_50 ) )
return - V_51 ;
if ( V_37 ) {
if ( V_37 -> V_52 != V_33 -> V_1 ) {
F_19 ( & V_6 -> V_42 , L_4
L_5 ,
V_37 -> V_52 , V_33 -> V_1 ) ;
return - V_48 ;
}
}
V_9 = F_22 ( & V_6 -> V_42 , sizeof( * V_9 ) , V_53 ) ;
if ( ! V_9 )
return - V_54 ;
V_9 -> V_55 = F_22 ( & V_6 -> V_42 ,
sizeof( * V_13 ) * V_33 -> V_1 , V_53 ) ;
if ( ! V_9 -> V_55 )
return - V_54 ;
F_23 ( V_6 , V_9 ) ;
F_24 ( & V_9 -> V_17 ) ;
V_9 -> V_6 = V_6 ;
V_9 -> V_10 = V_33 ;
for ( V_38 = 0 ; V_38 < V_33 -> V_1 ; V_38 ++ ) {
V_13 = & V_9 -> V_55 [ V_38 ] ;
V_13 -> V_3 = V_38 ;
V_13 -> V_9 = V_9 ;
if ( V_37 ) {
if ( V_37 -> V_55 [ V_38 ] . V_49 )
snprintf ( V_13 -> V_49 ,
sizeof( V_13 -> V_49 ) , L_6 ,
V_37 -> V_55 [ V_38 ] . V_49 ) ;
if ( V_37 -> V_55 [ V_38 ] . V_56 )
V_13 -> V_27 . V_56 =
V_37 -> V_55 [ V_38 ] . V_56 ;
} else {
snprintf ( V_13 -> V_49 , sizeof( V_13 -> V_49 ) ,
L_7 , V_38 ) ;
}
V_13 -> V_27 . V_49 = V_13 -> V_49 ;
V_13 -> V_27 . V_57 = F_15 ;
F_25 ( & V_13 -> V_12 , F_11 ) ;
V_39 = F_26 ( & V_6 -> V_42 ,
& V_13 -> V_27 ) ;
if ( V_39 < 0 )
goto exit;
}
for ( V_38 = 0 ; V_38 < F_2 ( V_33 -> V_1 ) ; V_38 ++ )
F_8 ( V_6 , V_38 , 0x55 ) ;
F_7 ( V_6 , 0 , 255 - V_23 ) ;
F_7 ( V_6 , 1 , 0 ) ;
F_4 ( V_6 , 0 , 0 ) ;
F_4 ( V_6 , 1 , 0 ) ;
return 0 ;
exit:
while ( V_38 -- ) {
F_27 ( & V_9 -> V_55 [ V_38 ] . V_27 ) ;
F_28 ( & V_9 -> V_55 [ V_38 ] . V_12 ) ;
}
return V_39 ;
}
static int F_29 ( struct V_5 * V_6 )
{
struct V_9 * V_9 = F_5 ( V_6 ) ;
int V_38 ;
for ( V_38 = 0 ; V_38 < V_9 -> V_10 -> V_1 ; V_38 ++ ) {
F_27 ( & V_9 -> V_55 [ V_38 ] . V_27 ) ;
F_28 ( & V_9 -> V_55 [ V_38 ] . V_12 ) ;
}
return 0 ;
}
