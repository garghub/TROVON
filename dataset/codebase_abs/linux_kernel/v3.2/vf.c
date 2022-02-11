static T_1 F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = false ;
return 0 ;
}
static T_1 F_2 ( struct V_1 * V_2 )
{
T_1 V_4 = V_2 -> V_5 . V_6 . V_7 ( V_2 ) ;
V_2 -> V_5 . V_6 . V_8 ( V_2 , V_2 -> V_5 . V_9 ) ;
return V_4 ;
}
static T_1 F_3 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = & V_2 -> V_11 ;
T_2 V_12 = V_13 ;
T_1 V_14 = V_15 ;
T_2 V_16 [ V_17 ] ;
T_3 * V_9 = ( T_3 * ) ( & V_16 [ 1 ] ) ;
V_2 -> V_5 . V_6 . V_18 ( V_2 ) ;
F_4 ( V_2 , V_19 , V_20 ) ;
F_5 ( V_2 ) ;
while ( ! V_11 -> V_6 . V_21 ( V_2 ) && V_12 ) {
V_12 -- ;
F_6 ( 5 ) ;
}
if ( ! V_12 )
return V_22 ;
V_11 -> V_12 = V_23 ;
V_16 [ 0 ] = V_24 ;
V_11 -> V_6 . V_25 ( V_2 , V_16 , 1 ) ;
F_7 ( 10 ) ;
V_14 = V_11 -> V_6 . V_26 ( V_2 , V_16 , V_17 ) ;
if ( V_14 )
return V_14 ;
if ( V_16 [ 0 ] != ( V_24 | V_27 ) )
return V_15 ;
memcpy ( V_2 -> V_5 . V_28 , V_9 , V_29 ) ;
V_2 -> V_5 . V_30 = V_16 [ V_31 ] ;
return 0 ;
}
static T_1 F_8 ( struct V_1 * V_2 )
{
T_2 V_32 ;
T_2 V_33 ;
T_4 V_34 ;
V_2 -> V_3 = true ;
V_32 = V_2 -> V_5 . V_35 ;
for ( V_34 = 0 ; V_34 < V_32 ; V_34 ++ ) {
V_33 = F_9 ( V_2 , F_10 ( V_34 ) ) ;
if ( V_33 & V_36 ) {
V_33 &= ~ V_36 ;
F_4 ( V_2 , F_10 ( V_34 ) , V_33 ) ;
}
}
F_5 ( V_2 ) ;
F_4 ( V_2 , V_37 , V_38 ) ;
F_9 ( V_2 , V_39 ) ;
V_32 = V_2 -> V_5 . V_40 ;
for ( V_34 = 0 ; V_34 < V_32 ; V_34 ++ ) {
V_33 = F_9 ( V_2 , F_11 ( V_34 ) ) ;
if ( V_33 & V_41 ) {
V_33 &= ~ V_41 ;
F_4 ( V_2 , F_11 ( V_34 ) , V_33 ) ;
}
}
return 0 ;
}
static T_1 F_12 ( struct V_1 * V_2 , T_3 * V_42 )
{
T_2 V_43 = 0 ;
switch ( V_2 -> V_5 . V_30 ) {
case 0 :
V_43 = ( ( V_42 [ 4 ] >> 4 ) | ( ( ( T_4 ) V_42 [ 5 ] ) << 4 ) ) ;
break;
case 1 :
V_43 = ( ( V_42 [ 4 ] >> 3 ) | ( ( ( T_4 ) V_42 [ 5 ] ) << 5 ) ) ;
break;
case 2 :
V_43 = ( ( V_42 [ 4 ] >> 2 ) | ( ( ( T_4 ) V_42 [ 5 ] ) << 6 ) ) ;
break;
case 3 :
V_43 = ( ( V_42 [ 4 ] ) | ( ( ( T_4 ) V_42 [ 5 ] ) << 8 ) ) ;
break;
default:
break;
}
V_43 &= 0xFFF ;
return V_43 ;
}
static T_1 F_13 ( struct V_1 * V_2 , T_3 * V_44 )
{
memcpy ( V_44 , V_2 -> V_5 . V_28 , V_29 ) ;
return 0 ;
}
static T_1 F_14 ( struct V_1 * V_2 , T_2 V_45 , T_3 * V_9 )
{
struct V_10 * V_11 = & V_2 -> V_11 ;
T_2 V_16 [ 3 ] ;
T_3 * V_46 = ( T_3 * ) ( & V_16 [ 1 ] ) ;
T_1 V_14 ;
memset ( V_16 , 0 , sizeof( V_16 ) ) ;
V_16 [ 0 ] |= V_45 << V_47 ;
V_16 [ 0 ] |= V_48 ;
if ( V_9 )
memcpy ( V_46 , V_9 , 6 ) ;
V_14 = V_11 -> V_6 . V_25 ( V_2 , V_16 , 3 ) ;
if ( ! V_14 )
V_14 = V_11 -> V_6 . V_26 ( V_2 , V_16 , 3 ) ;
V_16 [ 0 ] &= ~ V_49 ;
if ( ! V_14 )
if ( V_16 [ 0 ] ==
( V_48 | V_50 ) )
V_14 = - V_51 ;
return V_14 ;
}
static T_1 F_15 ( struct V_1 * V_2 , T_2 V_45 , T_3 * V_9 ,
T_2 V_52 )
{
struct V_10 * V_11 = & V_2 -> V_11 ;
T_2 V_16 [ 3 ] ;
T_3 * V_46 = ( T_3 * ) ( & V_16 [ 1 ] ) ;
T_1 V_14 ;
memset ( V_16 , 0 , sizeof( V_16 ) ) ;
V_16 [ 0 ] = V_53 ;
memcpy ( V_46 , V_9 , 6 ) ;
V_14 = V_11 -> V_6 . V_25 ( V_2 , V_16 , 3 ) ;
if ( ! V_14 )
V_14 = V_11 -> V_6 . V_26 ( V_2 , V_16 , 3 ) ;
V_16 [ 0 ] &= ~ V_49 ;
if ( ! V_14 &&
( V_16 [ 0 ] == ( V_53 | V_50 ) ) )
F_13 ( V_2 , V_2 -> V_5 . V_9 ) ;
return V_14 ;
}
static T_1 F_16 ( struct V_1 * V_2 ,
struct V_54 * V_55 )
{
struct V_56 * V_57 ;
struct V_10 * V_11 = & V_2 -> V_11 ;
T_2 V_16 [ V_58 ] ;
T_4 * V_59 = ( T_4 * ) & V_16 [ 1 ] ;
T_2 V_60 , V_34 ;
V_60 = F_17 ( V_55 ) ;
if ( V_60 > 30 )
V_60 = 30 ;
V_16 [ 0 ] = V_61 ;
V_16 [ 0 ] |= V_60 << V_47 ;
V_34 = 0 ;
F_18 (ha, netdev) {
if ( V_34 == V_60 )
break;
V_59 [ V_34 ++ ] = F_12 ( V_2 , V_57 -> V_9 ) ;
}
V_11 -> V_6 . V_25 ( V_2 , V_16 , V_58 ) ;
return 0 ;
}
static T_1 F_19 ( struct V_1 * V_2 , T_2 V_62 , T_2 V_63 ,
bool V_64 )
{
struct V_10 * V_11 = & V_2 -> V_11 ;
T_2 V_16 [ 2 ] ;
V_16 [ 0 ] = V_65 ;
V_16 [ 1 ] = V_62 ;
V_16 [ 0 ] |= V_64 << V_47 ;
return V_11 -> V_6 . V_25 ( V_2 , V_16 , 2 ) ;
}
static T_1 F_20 ( struct V_1 * V_2 ,
T_5 V_66 , bool V_67 ,
bool V_68 )
{
return 0 ;
}
static T_1 F_21 ( struct V_1 * V_2 ,
T_5 * V_66 ,
bool * V_69 ,
bool V_68 )
{
T_2 V_70 ;
if ( ! ( V_2 -> V_11 . V_6 . V_21 ( V_2 ) ) ) {
* V_69 = false ;
* V_66 = 0 ;
return - 1 ;
}
V_70 = F_9 ( V_2 , V_71 ) ;
if ( V_70 & V_72 )
* V_69 = true ;
else
* V_69 = false ;
if ( ( V_70 & V_73 ) ==
V_74 )
* V_66 = V_75 ;
else
* V_66 = V_76 ;
return 0 ;
}
