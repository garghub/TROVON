static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 , V_2 ) ;
int V_5 , V_6 , V_7 , V_8 , V_9 , V_10 ;
switch ( V_4 -> V_11 ) {
case V_12 :
V_5 = F_3 ( 2 ) ;
V_10 = 9 ;
V_6 = 0x0f ;
V_7 = V_4 -> V_13 >> 4 ;
break;
case V_14 :
V_5 = F_3 ( 2 ) ;
V_10 = 13 ;
V_6 = 0x0f ;
V_7 = V_4 -> V_13 >> 4 ;
break;
case V_15 :
V_5 = F_3 ( 2 ) ;
V_10 = 17 ;
V_6 = 0x0f ;
V_7 = V_4 -> V_13 >> 4 ;
break;
case V_16 :
case V_17 :
case V_18 :
case V_19 :
case V_20 :
case V_21 :
case V_22 :
case V_23 :
case V_24 :
V_9 = V_4 -> V_11 - V_16 ;
V_8 = V_9 / 3 ;
V_5 = F_3 ( 3 ) + V_8 ;
V_10 = ( V_9 - V_8 * 3 ) * 5 + 6 ;
V_7 = V_4 -> V_13 >> 3 ;
V_6 = 0x1f ;
break;
case V_25 :
V_5 = F_3 ( 0 ) ;
V_10 = 3 ;
V_6 = 0x3f ;
V_7 = V_4 -> V_13 >> 2 ;
break;
case V_26 :
V_5 = F_3 ( 0 ) ;
V_10 = 15 ;
V_6 = 0x3f ;
V_7 = V_4 -> V_13 >> 2 ;
break;
case V_27 :
V_5 = F_3 ( 1 ) ;
V_10 = 3 ;
V_6 = 0x3f ;
V_7 = V_4 -> V_13 >> 2 ;
break;
case V_28 :
case V_29 :
case V_30 :
V_9 = V_4 -> V_11 - V_28 ;
V_8 = V_9 / 2 ;
V_5 = F_3 ( 2 ) + V_8 ;
V_10 = ( V_9 - V_8 * 2 ) * 12 + 3 ;
V_7 = V_4 -> V_13 >> 2 ;
V_6 = 0x3f ;
break;
default:
F_4 () ;
}
F_5 ( V_4 -> V_31 ) ;
F_6 ( V_4 -> V_31 , V_5 , V_6 << V_10 , V_7 << V_10 ) ;
F_7 ( V_4 -> V_31 ) ;
}
static void F_8 ( struct V_32 * V_33 ,
enum V_34 V_7 )
{
struct V_3 * V_4 =
F_2 ( V_33 , struct V_3 , V_35 ) ;
V_4 -> V_13 = V_7 ;
F_9 ( & V_4 -> V_2 ) ;
}
static int T_1 F_10 ( struct V_3 * V_4 , int V_36 )
{
int V_10 , V_6 , V_5 , V_37 , V_8 ;
switch ( V_4 -> V_11 ) {
case V_12 :
V_5 = F_3 ( 2 ) ;
V_10 = 0 ;
V_6 = 0x07 ;
break;
case V_14 :
V_5 = F_3 ( 2 ) ;
V_10 = 3 ;
V_6 = 0x07 ;
break;
case V_15 :
V_5 = F_3 ( 2 ) ;
V_10 = 6 ;
V_6 = 0x07 ;
break;
case V_16 :
case V_17 :
case V_18 :
case V_19 :
case V_20 :
case V_21 :
case V_22 :
case V_23 :
case V_24 :
V_8 = ( V_4 -> V_11 - V_16 ) / 3 ;
V_5 = F_3 ( 3 ) + V_8 ;
V_10 = ( ( V_4 -> V_11 - V_16 ) - V_8 * 3 ) * 2 ;
V_6 = 0x03 ;
break;
case V_25 :
V_5 = F_3 ( 0 ) ;
V_10 = 9 ;
V_6 = 0x07 ;
break;
case V_26 :
V_5 = F_3 ( 0 ) ;
V_10 = 21 ;
V_6 = 0x07 ;
break;
case V_27 :
V_5 = F_3 ( 1 ) ;
V_10 = 9 ;
V_6 = 0x07 ;
break;
case V_28 :
case V_29 :
case V_30 :
V_8 = ( V_4 -> V_11 - V_28 ) / 2 ;
V_5 = F_3 ( 2 ) + V_8 ;
V_10 = ( ( V_4 -> V_11 - V_28 ) - V_8 * 2 ) * 12 + 9 ;
V_6 = 0x07 ;
break;
default:
F_4 () ;
}
F_5 ( V_4 -> V_31 ) ;
V_37 = F_6 ( V_4 -> V_31 , V_5 , V_6 << V_10 ,
V_36 << V_10 ) ;
F_7 ( V_4 -> V_31 ) ;
return V_37 ;
}
static int T_1 F_11 ( struct V_38 * V_39 )
{
struct V_40 * V_41 = F_12 ( & V_39 -> V_42 ) ;
struct V_43 * V_44 = F_13 ( V_39 -> V_42 . V_45 ) ;
struct V_46 * V_47 =
(struct V_46 * ) V_39 -> V_48 -> V_49 ;
struct V_50 * V_51 ;
int V_52 , V_11 , V_53 , V_37 = - V_54 ;
T_2 V_5 , V_55 = 0 ;
if ( ! V_41 ) {
F_14 ( & V_39 -> V_42 , L_1 ) ;
return - V_56 ;
}
V_53 = V_41 -> V_53 ;
if ( ( V_53 < 1 ) ||
( V_53 > ( V_47 -> V_57 - V_47 -> V_58 + 1 ) ) ) {
F_14 ( & V_39 -> V_42 , L_2 , V_53 ) ;
return - V_59 ;
}
V_51 = F_15 ( & V_39 -> V_42 , V_53 * sizeof( struct V_3 ) +
sizeof( struct V_50 ) , V_60 ) ;
if ( ! V_51 )
return - V_61 ;
V_51 -> V_47 = V_47 ;
V_51 -> V_53 = V_53 ;
F_16 ( V_39 , V_51 ) ;
F_5 ( V_44 ) ;
for ( V_52 = 0 ; V_52 < V_47 -> V_62 ; V_52 ++ ) {
V_5 = V_41 -> V_63 [ V_52 ] ;
F_17 ( V_5 >= ( 1 << 24 ) ) ;
V_37 = F_18 ( V_44 , F_3 ( V_52 ) , V_5 ) ;
if ( V_37 )
break;
}
F_7 ( V_44 ) ;
if ( V_37 ) {
F_14 ( & V_39 -> V_42 , L_3 ) ;
return V_37 ;
}
for ( V_52 = 0 ; V_52 < V_53 ; V_52 ++ ) {
const char * V_64 , * V_65 ;
char V_36 ;
V_37 = - V_59 ;
V_11 = V_41 -> V_4 [ V_52 ] . V_11 ;
V_64 = V_41 -> V_4 [ V_52 ] . V_64 ;
V_65 = V_41 -> V_4 [ V_52 ] . V_66 ;
V_36 = V_41 -> V_4 [ V_52 ] . V_36 ;
if ( ( V_11 > V_47 -> V_57 ) || ( V_11 < V_47 -> V_58 ) ) {
F_14 ( & V_39 -> V_42 , L_4 , V_11 ) ;
break;
}
if ( V_55 & ( 1 << V_11 ) ) {
F_19 ( & V_39 -> V_42 ,
L_5 , V_11 ) ;
break;
}
V_55 |= 1 << V_11 ;
V_51 -> V_4 [ V_52 ] . V_11 = V_11 ;
V_51 -> V_4 [ V_52 ] . V_31 = V_44 ;
V_51 -> V_4 [ V_52 ] . V_35 . V_64 = V_64 ;
V_51 -> V_4 [ V_52 ] . V_35 . V_66 = V_65 ;
V_51 -> V_4 [ V_52 ] . V_35 . V_67 = F_8 ;
V_51 -> V_4 [ V_52 ] . V_35 . V_68 = V_69 ;
F_20 ( & V_51 -> V_4 [ V_52 ] . V_2 , F_1 ) ;
V_37 = F_10 ( & V_51 -> V_4 [ V_52 ] , V_36 ) ;
if ( V_37 ) {
F_14 ( & V_39 -> V_42 , L_6 , V_11 ) ;
break;
}
V_37 = F_21 ( V_39 -> V_42 . V_45 ,
& V_51 -> V_4 [ V_52 ] . V_35 ) ;
if ( V_37 ) {
F_14 ( & V_39 -> V_42 , L_7 , V_11 ) ;
break;
}
}
if ( V_37 )
while ( -- V_52 >= 0 ) {
F_22 ( & V_51 -> V_4 [ V_52 ] . V_35 ) ;
F_23 ( & V_51 -> V_4 [ V_52 ] . V_2 ) ;
}
return V_37 ;
}
static int F_24 ( struct V_38 * V_39 )
{
struct V_43 * V_44 = F_13 ( V_39 -> V_42 . V_45 ) ;
struct V_50 * V_51 = F_25 ( V_39 ) ;
int V_52 ;
for ( V_52 = 0 ; V_52 < V_51 -> V_53 ; V_52 ++ ) {
F_22 ( & V_51 -> V_4 [ V_52 ] . V_35 ) ;
F_23 ( & V_51 -> V_4 [ V_52 ] . V_2 ) ;
}
F_5 ( V_44 ) ;
for ( V_52 = 0 ; V_52 < V_51 -> V_47 -> V_62 ; V_52 ++ )
F_18 ( V_44 , F_3 ( V_52 ) , 0 ) ;
F_7 ( V_44 ) ;
return 0 ;
}
