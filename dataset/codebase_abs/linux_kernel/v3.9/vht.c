void
F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = & V_8 -> V_8 . V_10 ;
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
if ( ! V_8 -> V_8 . V_11 . V_12 )
return;
if ( ! V_6 || ! V_4 -> V_10 . V_13 )
return;
if ( ! ( V_8 -> V_8 . V_11 . V_14 & V_15 ) )
return;
V_10 -> V_13 = true ;
V_10 -> V_14 = F_2 ( V_6 -> V_16 ) ;
memcpy ( & V_10 -> V_17 , & V_6 -> V_18 ,
sizeof( struct V_19 ) ) ;
switch ( V_10 -> V_14 & V_20 ) {
case V_21 :
case V_22 :
V_8 -> V_23 = V_24 ;
break;
default:
V_8 -> V_23 = V_25 ;
}
V_8 -> V_8 . V_26 = F_3 ( V_8 ) ;
}
enum V_27 F_3 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
T_1 V_14 = V_8 -> V_8 . V_10 . V_14 ;
enum V_27 V_28 ;
if ( ! V_8 -> V_8 . V_10 . V_13 ) {
V_28 = V_8 -> V_8 . V_11 . V_14 & V_15 ?
V_29 : V_30 ;
goto V_31;
}
switch ( V_2 -> V_32 . V_33 . V_34 . V_35 ) {
default:
F_4 ( 1 ) ;
case V_36 :
case V_37 :
case V_38 :
V_28 = V_8 -> V_8 . V_11 . V_14 & V_15 ?
V_29 : V_30 ;
break;
case V_39 :
if ( ( V_14 & V_20 ) ==
V_21 ) {
V_28 = V_24 ;
break;
}
case V_40 :
if ( ( V_14 & V_20 ) ==
V_22 ) {
V_28 = V_24 ;
break;
}
case V_41 :
V_28 = V_25 ;
}
V_31:
if ( V_28 > V_8 -> V_23 )
V_28 = V_8 -> V_23 ;
return V_28 ;
}
void F_5 ( struct V_7 * V_8 )
{
T_2 V_42 = 0 , V_43 = 0 ;
if ( V_8 -> V_8 . V_44 )
return;
if ( V_8 -> V_8 . V_11 . V_12 ) {
if ( V_8 -> V_8 . V_11 . V_45 . V_46 [ 0 ] )
V_42 ++ ;
if ( V_8 -> V_8 . V_11 . V_45 . V_46 [ 1 ] )
V_42 ++ ;
if ( V_8 -> V_8 . V_11 . V_45 . V_46 [ 2 ] )
V_42 ++ ;
if ( V_8 -> V_8 . V_11 . V_45 . V_46 [ 3 ] )
V_42 ++ ;
}
if ( V_8 -> V_8 . V_10 . V_13 ) {
int V_47 ;
T_3 V_48 ;
V_48 = F_6 ( V_8 -> V_8 . V_10 . V_17 . V_48 ) ;
for ( V_47 = 7 ; V_47 >= 0 ; V_47 -- ) {
T_2 V_45 = ( V_48 >> ( 2 * V_47 ) ) & 3 ;
if ( V_45 != V_49 ) {
V_43 = V_47 + 1 ;
break;
}
}
}
V_42 = F_7 ( V_42 , V_43 ) ;
V_8 -> V_8 . V_44 = F_8 ( T_2 , 1 , V_42 ) ;
}
void F_9 ( struct V_1 * V_2 ,
struct V_7 * V_8 , T_2 V_50 ,
enum V_51 V_52 , bool V_53 )
{
struct V_54 * V_55 = V_2 -> V_55 ;
struct V_3 * V_4 ;
enum V_27 V_56 ;
T_1 V_57 = 0 ;
T_2 V_58 ;
V_4 = V_55 -> V_59 . V_60 -> V_61 [ V_52 ] ;
if ( V_50 & V_62 )
return;
V_58 = V_50 & V_63 ;
V_58 >>= V_64 ;
V_58 += 1 ;
if ( V_8 -> V_8 . V_44 != V_58 ) {
V_8 -> V_8 . V_44 = V_58 ;
V_57 |= V_65 ;
}
if ( V_53 )
goto V_66;
switch ( V_50 & V_67 ) {
case V_68 :
V_8 -> V_23 = V_30 ;
break;
case V_69 :
V_8 -> V_23 = V_29 ;
break;
case V_70 :
V_8 -> V_23 = V_25 ;
break;
case V_71 :
V_8 -> V_23 = V_24 ;
break;
}
V_56 = F_3 ( V_8 ) ;
if ( V_56 != V_8 -> V_8 . V_26 ) {
V_8 -> V_8 . V_26 = V_56 ;
V_57 |= V_65 ;
}
V_66:
if ( V_57 )
F_10 ( V_55 , V_4 , V_8 , V_57 ) ;
}
