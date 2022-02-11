static T_1 F_1 ( struct V_1 * V_2 )
{
T_2 * V_3 = V_2 -> V_4 . V_3 ;
T_3 V_5 = 0 , V_6 = 0 ;
T_1 V_7 ;
T_4 V_8 ;
V_7 = F_2 ( V_2 ) ;
if ( V_7 )
return V_7 ;
if ( F_3 ( V_3 ) ) {
V_5 = ( ( ( T_3 ) V_3 [ 3 ] ) << 24 ) |
( ( ( T_3 ) V_3 [ 4 ] ) << 16 ) |
( ( ( T_3 ) V_3 [ 5 ] ) << 8 ) ;
V_6 = ( ( ( T_3 ) 0xFF ) << 24 ) |
( ( ( T_3 ) V_3 [ 0 ] ) << 16 ) |
( ( ( T_3 ) V_3 [ 1 ] ) << 8 ) |
( ( T_3 ) V_3 [ 2 ] ) ;
}
for ( V_8 = 0 ; V_8 < V_2 -> V_4 . V_9 ; V_8 ++ ) {
F_4 ( V_2 , F_5 ( V_8 ) , V_5 ) ;
F_4 ( V_2 , F_6 ( V_8 ) , V_6 ) ;
F_4 ( V_2 , F_7 ( V_8 ) , V_5 ) ;
F_4 ( V_2 , F_8 ( V_8 ) , V_6 ) ;
}
return 0 ;
}
static T_1 F_9 ( struct V_1 * V_2 )
{
T_1 V_7 ;
V_7 = F_1 ( V_2 ) ;
if ( V_7 )
return V_7 ;
F_4 ( V_2 , V_10 , V_11 ) ;
F_10 ( V_2 ) ;
F_11 ( V_12 ) ;
F_4 ( V_2 , V_10 , 0 ) ;
if ( F_12 ( V_2 , V_10 ) & V_11 )
V_7 = V_13 ;
return V_7 ;
}
static T_1 F_13 ( struct V_1 * V_2 )
{
T_3 V_14 , V_15 = ~ F_12 ( V_2 , F_14 ( 0 ) ) ;
T_1 V_7 ;
T_4 V_8 ;
for ( V_8 = 1 ; V_15 && ( V_8 < V_16 ) ; V_8 ++ ) {
V_14 = ~ F_12 ( V_2 , F_14 ( V_8 ) ) ;
if ( ! V_14 || ( V_14 == V_15 ) )
break;
if ( ! ~ F_12 ( V_2 , F_15 ( V_8 ) ) ||
! ~ F_12 ( V_2 , F_16 ( V_8 ) ) )
break;
}
V_7 = F_17 ( V_2 , V_8 ) ;
if ( V_7 )
return V_7 ;
V_2 -> V_4 . V_9 = V_8 ;
V_2 -> V_4 . V_17 = ( F_12 ( V_2 , F_15 ( 0 ) ) &
V_18 ) >> V_19 ;
return 0 ;
}
static T_1 F_18 ( struct V_1 * V_2 , T_3 V_20 , T_2 V_21 , bool V_22 )
{
struct V_23 * V_24 = & V_2 -> V_24 ;
T_3 V_25 [ 4 ] ;
if ( V_21 )
return V_26 ;
if ( ( V_20 << 16 | V_20 ) >> 28 )
return V_26 ;
if ( ! V_22 )
V_20 |= V_27 ;
F_19 ( V_25 , V_28 ) ;
F_20 ( V_25 , V_29 , V_20 ) ;
return V_24 -> V_30 . V_31 ( V_2 , V_24 , V_25 ) ;
}
T_1 F_21 ( struct V_1 * V_2 , T_3 * * V_32 ,
struct V_23 * V_24 )
{
T_2 V_3 [ V_33 ] ;
T_4 V_20 ;
T_1 V_7 ;
V_7 = F_22 (
V_32 [ V_34 ] ,
V_3 , & V_20 ) ;
if ( V_7 )
return V_7 ;
F_23 ( V_2 -> V_4 . V_3 , V_3 ) ;
V_2 -> V_4 . V_17 = V_20 & ( V_35 - 1 ) ;
V_2 -> V_4 . V_36 = ! ! ( V_20 & V_27 ) ;
return 0 ;
}
static T_1 F_24 ( struct V_1 * V_2 )
{
T_2 V_3 [ V_33 ] ;
T_3 V_37 ;
V_37 = F_12 ( V_2 , F_5 ( 0 ) ) ;
if ( V_37 << 24 )
return V_38 ;
V_3 [ 3 ] = ( T_2 ) ( V_37 >> 24 ) ;
V_3 [ 4 ] = ( T_2 ) ( V_37 >> 16 ) ;
V_3 [ 5 ] = ( T_2 ) ( V_37 >> 8 ) ;
V_37 = F_12 ( V_2 , F_6 ( 0 ) ) ;
if ( ( ~ V_37 ) >> 24 )
return V_38 ;
V_3 [ 0 ] = ( T_2 ) ( V_37 >> 16 ) ;
V_3 [ 1 ] = ( T_2 ) ( V_37 >> 8 ) ;
V_3 [ 2 ] = ( T_2 ) ( V_37 ) ;
F_23 ( V_2 -> V_4 . V_3 , V_3 ) ;
F_23 ( V_2 -> V_4 . V_39 , V_3 ) ;
return 0 ;
}
static T_1 F_25 ( struct V_1 * V_2 , T_4 V_40 ,
const T_2 * V_4 , T_4 V_20 , bool V_41 , T_2 V_42 )
{
struct V_23 * V_24 = & V_2 -> V_24 ;
T_3 V_25 [ 7 ] ;
if ( V_20 >= V_35 )
return V_26 ;
if ( ! F_3 ( V_4 ) )
return V_26 ;
if ( F_3 ( V_2 -> V_4 . V_3 ) &&
memcmp ( V_2 -> V_4 . V_3 , V_4 , V_33 ) )
return V_26 ;
if ( ! V_41 )
V_20 |= V_27 ;
F_19 ( V_25 , V_28 ) ;
F_26 ( V_25 , V_43 , V_4 , V_20 ) ;
return V_24 -> V_30 . V_31 ( V_2 , V_24 , V_25 ) ;
}
static T_1 F_27 ( struct V_1 * V_2 , T_4 V_40 ,
const T_2 * V_4 , T_4 V_20 , bool V_41 )
{
struct V_23 * V_24 = & V_2 -> V_24 ;
T_3 V_25 [ 7 ] ;
if ( V_20 >= V_35 )
return V_26 ;
if ( ! F_28 ( V_4 ) )
return V_26 ;
if ( ! V_41 )
V_20 |= V_27 ;
F_19 ( V_25 , V_28 ) ;
F_26 ( V_25 , V_44 ,
V_4 , V_20 ) ;
return V_24 -> V_30 . V_31 ( V_2 , V_24 , V_25 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = & V_2 -> V_24 ;
T_3 V_25 [ 1 ] ;
F_19 ( V_25 , V_45 ) ;
V_24 -> V_30 . V_31 ( V_2 , V_24 , V_25 ) ;
}
T_1 F_30 ( struct V_1 * V_2 , T_3 * * V_32 ,
struct V_23 * V_24 )
{
V_2 -> V_4 . V_46 = ! V_32 [ V_47 ] ?
V_48 : V_49 ;
return 0 ;
}
static T_1 F_31 ( struct V_1 * V_2 , T_4 V_40 ,
T_4 V_50 , bool V_51 )
{
struct V_23 * V_24 = & V_2 -> V_24 ;
T_3 V_25 [ 2 ] ;
V_2 -> V_4 . V_46 = V_48 ;
F_19 ( V_25 , V_52 ) ;
if ( ! V_51 )
F_32 ( V_25 , V_53 ) ;
return V_24 -> V_30 . V_31 ( V_2 , V_24 , V_25 ) ;
}
static T_1 F_33 ( struct V_1 * V_2 , T_4 V_40 , T_2 V_54 )
{
struct V_23 * V_24 = & V_2 -> V_24 ;
T_3 V_25 [ 3 ] ;
if ( V_54 > V_55 )
return V_26 ;
F_19 ( V_25 , V_52 ) ;
F_34 ( V_25 , V_56 , V_54 ) ;
return V_24 -> V_30 . V_31 ( V_2 , V_24 , V_25 ) ;
}
static void F_35 ( struct V_1 * V_2 ,
struct V_57 * V_58 )
{
F_36 ( V_2 , V_58 -> V_59 , 0 , V_2 -> V_4 . V_9 ) ;
}
static void F_37 ( struct V_1 * V_2 ,
struct V_57 * V_58 )
{
F_38 ( V_58 -> V_59 , 0 , V_2 -> V_4 . V_9 ) ;
F_35 ( V_2 , V_58 ) ;
}
static T_1 F_39 ( struct V_1 * V_2 ,
struct V_60 * V_61 )
{
if ( ! V_61 )
return V_26 ;
return 0 ;
}
static T_1 F_40 ( struct V_1 * V_2 , T_1 V_62 )
{
return V_62 ? V_26 : 0 ;
}
static T_5 F_41 ( struct V_1 * V_2 )
{
T_3 V_63 , V_64 , V_65 ;
V_64 = F_12 ( V_2 , V_66 + 1 ) ;
do {
V_65 = V_64 ;
V_63 = F_12 ( V_2 , V_66 ) ;
V_64 = F_12 ( V_2 , V_66 + 1 ) ;
} while ( V_65 != V_64 );
return ( ( T_5 ) V_64 << 32 ) | V_63 ;
}
static T_1 F_42 ( struct V_1 * V_2 )
{
F_43 ( V_2 ) ;
return F_44 ( V_2 , & V_2 -> V_24 , V_67 , 0 ) ;
}
