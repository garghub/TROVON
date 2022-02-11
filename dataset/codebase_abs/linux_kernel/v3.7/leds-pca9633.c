static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ,
struct V_3 , V_2 ) ;
T_1 V_5 = F_3 ( V_4 -> V_6 , V_7 ) ;
int V_8 = 2 * V_4 -> V_9 ;
T_1 V_10 = 0x3 << V_8 ;
switch ( V_4 -> V_11 ) {
case V_12 :
F_4 ( V_4 -> V_6 , V_7 ,
( V_5 & ~ V_10 ) | ( V_13 << V_8 ) ) ;
break;
case V_14 :
F_4 ( V_4 -> V_6 , V_7 ,
V_5 & ~ V_10 ) ;
break;
default:
F_4 ( V_4 -> V_6 ,
V_15 + V_4 -> V_9 ,
V_4 -> V_11 ) ;
F_4 ( V_4 -> V_6 , V_7 ,
( V_5 & ~ V_10 ) | ( V_16 << V_8 ) ) ;
break;
}
}
static void F_5 ( struct V_17 * V_18 ,
enum V_19 V_20 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( V_18 , struct V_3 , V_18 ) ;
V_4 -> V_11 = V_20 ;
F_6 ( & V_4 -> V_2 ) ;
}
static int T_2 F_7 ( struct V_21 * V_6 ,
const struct V_22 * V_23 )
{
struct V_3 * V_4 ;
struct V_24 * V_25 ;
int V_26 , V_27 ;
V_25 = V_6 -> V_28 . V_29 ;
if ( V_25 ) {
if ( V_25 -> V_30 . V_31 <= 0 || V_25 -> V_30 . V_31 > 4 ) {
F_8 ( & V_6 -> V_28 , L_1 ) ;
return - V_32 ;
}
}
V_4 = F_9 ( & V_6 -> V_28 , 4 * sizeof( * V_4 ) , V_33 ) ;
if ( ! V_4 )
return - V_34 ;
F_10 ( V_6 , V_4 ) ;
for ( V_26 = 0 ; V_26 < 4 ; V_26 ++ ) {
V_4 [ V_26 ] . V_6 = V_6 ;
V_4 [ V_26 ] . V_9 = V_26 ;
if ( V_25 && V_26 < V_25 -> V_30 . V_31 ) {
if ( V_25 -> V_30 . V_30 [ V_26 ] . V_35 )
snprintf ( V_4 [ V_26 ] . V_35 ,
sizeof( V_4 [ V_26 ] . V_35 ) , L_2 ,
V_25 -> V_30 . V_30 [ V_26 ] . V_35 ) ;
if ( V_25 -> V_30 . V_30 [ V_26 ] . V_36 )
V_4 [ V_26 ] . V_18 . V_36 =
V_25 -> V_30 . V_30 [ V_26 ] . V_36 ;
} else {
snprintf ( V_4 [ V_26 ] . V_35 , sizeof( V_4 [ V_26 ] . V_35 ) ,
L_3 , V_26 ) ;
}
V_4 [ V_26 ] . V_18 . V_35 = V_4 [ V_26 ] . V_35 ;
V_4 [ V_26 ] . V_18 . V_37 = F_5 ;
F_11 ( & V_4 [ V_26 ] . V_2 , F_1 ) ;
V_27 = F_12 ( & V_6 -> V_28 , & V_4 [ V_26 ] . V_18 ) ;
if ( V_27 < 0 )
goto exit;
}
F_4 ( V_6 , V_38 , 0x00 ) ;
if ( V_25 && V_25 -> V_39 == V_40 )
F_4 ( V_6 , V_41 , 0x01 ) ;
F_4 ( V_6 , V_7 , 0x00 ) ;
return 0 ;
exit:
while ( V_26 -- ) {
F_13 ( & V_4 [ V_26 ] . V_18 ) ;
F_14 ( & V_4 [ V_26 ] . V_2 ) ;
}
return V_27 ;
}
static int T_3 F_15 ( struct V_21 * V_6 )
{
struct V_3 * V_4 = F_16 ( V_6 ) ;
int V_26 ;
for ( V_26 = 0 ; V_26 < 4 ; V_26 ++ ) {
F_13 ( & V_4 [ V_26 ] . V_18 ) ;
F_14 ( & V_4 [ V_26 ] . V_2 ) ;
}
return 0 ;
}
