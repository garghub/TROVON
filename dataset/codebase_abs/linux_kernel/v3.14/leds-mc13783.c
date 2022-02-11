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
F_5 ( V_4 -> V_31 , V_5 , V_6 << V_10 , V_7 << V_10 ) ;
}
static void F_6 ( struct V_32 * V_33 ,
enum V_34 V_7 )
{
struct V_3 * V_4 =
F_2 ( V_33 , struct V_3 , V_35 ) ;
V_4 -> V_13 = V_7 ;
F_7 ( & V_4 -> V_2 ) ;
}
static int T_1 F_8 ( struct V_36 * V_37 )
{
struct V_38 * V_39 = F_9 ( & V_37 -> V_40 ) ;
struct V_41 * V_42 = F_10 ( V_37 -> V_40 . V_43 ) ;
struct V_44 * V_45 =
(struct V_44 * ) V_37 -> V_46 -> V_47 ;
struct V_48 * V_49 ;
int V_50 , V_11 , V_51 , V_52 = - V_53 ;
T_2 V_5 , V_54 = 0 ;
if ( ! V_39 ) {
F_11 ( & V_37 -> V_40 , L_1 ) ;
return - V_55 ;
}
V_51 = V_39 -> V_51 ;
if ( ( V_51 < 1 ) ||
( V_51 > ( V_45 -> V_56 - V_45 -> V_57 + 1 ) ) ) {
F_11 ( & V_37 -> V_40 , L_2 , V_51 ) ;
return - V_58 ;
}
V_49 = F_12 ( & V_37 -> V_40 , V_51 * sizeof( struct V_3 ) +
sizeof( struct V_48 ) , V_59 ) ;
if ( ! V_49 )
return - V_60 ;
V_49 -> V_45 = V_45 ;
V_49 -> V_51 = V_51 ;
F_13 ( V_37 , V_49 ) ;
for ( V_50 = 0 ; V_50 < V_45 -> V_61 ; V_50 ++ ) {
V_5 = V_39 -> V_62 [ V_50 ] ;
F_14 ( V_5 >= ( 1 << 24 ) ) ;
V_52 = F_15 ( V_42 , F_3 ( V_50 ) , V_5 ) ;
if ( V_52 )
return V_52 ;
}
for ( V_50 = 0 ; V_50 < V_51 ; V_50 ++ ) {
const char * V_63 , * V_64 ;
V_52 = - V_58 ;
V_11 = V_39 -> V_4 [ V_50 ] . V_11 ;
V_63 = V_39 -> V_4 [ V_50 ] . V_63 ;
V_64 = V_39 -> V_4 [ V_50 ] . V_65 ;
if ( ( V_11 > V_45 -> V_56 ) || ( V_11 < V_45 -> V_57 ) ) {
F_11 ( & V_37 -> V_40 , L_3 , V_11 ) ;
break;
}
if ( V_54 & ( 1 << V_11 ) ) {
F_16 ( & V_37 -> V_40 ,
L_4 , V_11 ) ;
break;
}
V_54 |= 1 << V_11 ;
V_49 -> V_4 [ V_50 ] . V_11 = V_11 ;
V_49 -> V_4 [ V_50 ] . V_31 = V_42 ;
V_49 -> V_4 [ V_50 ] . V_35 . V_63 = V_63 ;
V_49 -> V_4 [ V_50 ] . V_35 . V_65 = V_64 ;
V_49 -> V_4 [ V_50 ] . V_35 . V_66 = F_6 ;
V_49 -> V_4 [ V_50 ] . V_35 . V_67 = V_68 ;
F_17 ( & V_49 -> V_4 [ V_50 ] . V_2 , F_1 ) ;
V_52 = F_18 ( V_37 -> V_40 . V_43 ,
& V_49 -> V_4 [ V_50 ] . V_35 ) ;
if ( V_52 ) {
F_11 ( & V_37 -> V_40 , L_5 , V_11 ) ;
break;
}
}
if ( V_52 )
while ( -- V_50 >= 0 ) {
F_19 ( & V_49 -> V_4 [ V_50 ] . V_35 ) ;
F_20 ( & V_49 -> V_4 [ V_50 ] . V_2 ) ;
}
return V_52 ;
}
static int F_21 ( struct V_36 * V_37 )
{
struct V_41 * V_42 = F_10 ( V_37 -> V_40 . V_43 ) ;
struct V_48 * V_49 = F_22 ( V_37 ) ;
int V_50 ;
for ( V_50 = 0 ; V_50 < V_49 -> V_51 ; V_50 ++ ) {
F_19 ( & V_49 -> V_4 [ V_50 ] . V_35 ) ;
F_20 ( & V_49 -> V_4 [ V_50 ] . V_2 ) ;
}
for ( V_50 = 0 ; V_50 < V_49 -> V_45 -> V_61 ; V_50 ++ )
F_15 ( V_42 , F_3 ( V_50 ) , 0 ) ;
return 0 ;
}
