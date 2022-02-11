static void F_1 ( struct V_1 * V_2 , T_1 * V_3 , T_1 V_4 )
{
struct V_5 V_6 = {
. V_7 = V_2 -> V_7 ,
. V_8 = 0x00 ,
. V_4 = V_4 ,
. V_3 = V_3
} ;
F_2 ( V_2 -> V_9 , & V_6 , 1 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
T_1 V_10 [ 5 ] = { V_11 , 0x00 , 0x00 , 0x00 , 0x10 } ;
F_1 ( V_2 , V_10 , 5 ) ;
}
static void F_4 ( struct V_12 * V_13 )
{
struct V_14 * V_15 ;
T_1 V_10 [ 5 ] ;
V_15 = F_5 ( V_13 , struct V_14 , V_13 ) ;
V_10 [ 0 ] = V_16 + 4 * V_15 -> V_17 ;
if ( V_15 -> V_18 == 4095 )
* ( ( V_19 * ) ( V_10 + 1 ) ) = F_6 ( 0x1000 ) ;
else
* ( ( V_19 * ) ( V_10 + 1 ) ) = 0x0000 ;
if ( V_15 -> V_18 == 0 )
* ( ( V_19 * ) ( V_10 + 3 ) ) = F_6 ( 0x1000 ) ;
else if ( V_15 -> V_18 == 4095 )
* ( ( V_19 * ) ( V_10 + 3 ) ) = 0x0000 ;
else
* ( ( V_19 * ) ( V_10 + 3 ) ) = F_6 ( V_15 -> V_18 ) ;
F_1 ( V_15 -> V_2 , V_10 , 5 ) ;
}
static void F_7 ( struct V_20 * V_21 ,
enum V_22 V_23 )
{
struct V_14 * V_15 ;
V_15 = F_5 ( V_21 , struct V_14 , V_21 ) ;
V_15 -> V_18 = V_23 ;
F_8 ( & V_15 -> V_13 ) ;
}
static int F_9 ( struct V_1 * V_2 ,
const struct V_24 * V_25 )
{
struct V_14 * V_15 ;
struct V_26 * V_27 ;
int V_28 ;
T_1 V_29 ;
V_27 = F_10 ( & V_2 -> V_30 ) ;
if ( V_27 ) {
if ( V_27 -> V_31 . V_32 < 1 || V_27 -> V_31 . V_32 > 15 ) {
F_11 ( & V_2 -> V_30 , L_1 ) ;
return - V_33 ;
}
}
V_15 = F_12 ( & V_2 -> V_30 , 16 * sizeof( * V_15 ) , V_34 ) ;
if ( ! V_15 )
return - V_35 ;
F_13 ( V_2 , V_15 ) ;
F_3 ( V_2 ) ;
for ( V_29 = 0 ; V_29 < 16 ; V_29 ++ ) {
V_15 [ V_29 ] . V_2 = V_2 ;
V_15 [ V_29 ] . V_17 = V_29 ;
V_15 [ V_29 ] . V_36 [ 0 ] = '\0' ;
if ( V_27 && V_29 < V_27 -> V_31 . V_32 ) {
if ( V_27 -> V_31 . V_31 [ V_29 ] . V_36 )
strncpy ( V_15 [ V_29 ] . V_36 ,
V_27 -> V_31 . V_31 [ V_29 ] . V_36 ,
sizeof( V_15 [ V_29 ] . V_36 ) - 1 ) ;
if ( V_27 -> V_31 . V_31 [ V_29 ] . V_37 )
V_15 [ V_29 ] . V_21 . V_37 =
V_27 -> V_31 . V_31 [ V_29 ] . V_37 ;
}
if ( strlen ( V_15 [ V_29 ] . V_36 ) == 0 ) {
snprintf ( V_15 [ V_29 ] . V_36 , sizeof( V_15 [ V_29 ] . V_36 ) ,
L_2 ,
V_2 -> V_9 -> V_38 , V_2 -> V_7 , V_29 ) ;
}
V_15 [ V_29 ] . V_21 . V_36 = V_15 [ V_29 ] . V_36 ;
V_15 [ V_29 ] . V_21 . V_39 = 0xfff ;
V_15 [ V_29 ] . V_21 . V_40 = F_7 ;
F_14 ( & V_15 [ V_29 ] . V_13 , F_4 ) ;
V_28 = F_15 ( & V_2 -> V_30 , & V_15 [ V_29 ] . V_21 ) ;
if ( V_28 < 0 )
goto exit;
}
if ( V_27 )
F_16 ( V_2 , V_41 ,
V_27 -> V_42 << V_43 |
V_27 -> V_44 << V_45 ) ;
else
F_16 ( V_2 , V_41 ,
V_46 << V_43 ) ;
F_16 ( V_2 , V_47 , F_17 ( V_48 ) ) ;
return 0 ;
exit:
while ( V_29 -- ) {
F_18 ( & V_15 [ V_29 ] . V_21 ) ;
F_19 ( & V_15 [ V_29 ] . V_13 ) ;
}
return V_28 ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_21 ( V_2 ) ;
T_1 V_29 ;
for ( V_29 = 0 ; V_29 < 16 ; V_29 ++ ) {
F_18 ( & V_15 [ V_29 ] . V_21 ) ;
F_19 ( & V_15 [ V_29 ] . V_13 ) ;
}
F_3 ( V_2 ) ;
return 0 ;
}
