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
return 0 ;
}
static bool F_18 ( struct V_1 * V_2 )
{
return true ;
}
static T_1 F_19 ( struct V_1 * V_2 , T_3 V_17 , T_2 V_18 , bool V_19 )
{
struct V_20 * V_21 = & V_2 -> V_21 ;
T_3 V_22 [ 4 ] ;
if ( V_18 )
return V_23 ;
if ( ( V_17 << 16 | V_17 ) >> 28 )
return V_23 ;
if ( ! V_19 )
V_17 |= V_24 ;
F_20 ( V_22 , V_25 ) ;
F_21 ( V_22 , V_26 , V_17 ) ;
return V_21 -> V_27 . V_28 ( V_2 , V_21 , V_22 ) ;
}
T_1 F_22 ( struct V_1 * V_2 , T_3 * * V_29 ,
struct V_20 * V_21 )
{
T_2 V_3 [ V_30 ] ;
T_4 V_17 ;
T_1 V_7 ;
V_7 = F_23 (
V_29 [ V_31 ] ,
V_3 , & V_17 ) ;
if ( V_7 )
return V_7 ;
F_24 ( V_2 -> V_4 . V_3 , V_3 ) ;
V_2 -> V_4 . V_32 = V_17 & ( V_33 - 1 ) ;
V_2 -> V_4 . V_34 = ! ! ( V_17 & V_24 ) ;
return 0 ;
}
static T_1 F_25 ( struct V_1 * V_2 )
{
T_2 V_3 [ V_30 ] ;
T_3 V_35 ;
V_35 = F_12 ( V_2 , F_5 ( 0 ) ) ;
if ( V_35 << 24 )
return V_36 ;
V_3 [ 3 ] = ( T_2 ) ( V_35 >> 24 ) ;
V_3 [ 4 ] = ( T_2 ) ( V_35 >> 16 ) ;
V_3 [ 5 ] = ( T_2 ) ( V_35 >> 8 ) ;
V_35 = F_12 ( V_2 , F_6 ( 0 ) ) ;
if ( ( ~ V_35 ) >> 24 )
return V_36 ;
V_3 [ 0 ] = ( T_2 ) ( V_35 >> 16 ) ;
V_3 [ 1 ] = ( T_2 ) ( V_35 >> 8 ) ;
V_3 [ 2 ] = ( T_2 ) ( V_35 ) ;
F_24 ( V_2 -> V_4 . V_3 , V_3 ) ;
F_24 ( V_2 -> V_4 . V_37 , V_3 ) ;
return 0 ;
}
static T_1 F_26 ( struct V_1 * V_2 , T_4 V_38 ,
const T_2 * V_4 , T_4 V_17 , bool V_39 , T_2 V_40 )
{
struct V_20 * V_21 = & V_2 -> V_21 ;
T_3 V_22 [ 7 ] ;
if ( V_17 >= V_33 )
return V_23 ;
if ( ! F_3 ( V_4 ) )
return V_23 ;
if ( F_3 ( V_2 -> V_4 . V_3 ) &&
memcmp ( V_2 -> V_4 . V_3 , V_4 , V_30 ) )
return V_23 ;
if ( ! V_39 )
V_17 |= V_24 ;
F_20 ( V_22 , V_25 ) ;
F_27 ( V_22 , V_41 , V_4 , V_17 ) ;
return V_21 -> V_27 . V_28 ( V_2 , V_21 , V_22 ) ;
}
static T_1 F_28 ( struct V_1 * V_2 , T_4 V_38 ,
const T_2 * V_4 , T_4 V_17 , bool V_39 )
{
struct V_20 * V_21 = & V_2 -> V_21 ;
T_3 V_22 [ 7 ] ;
if ( V_17 >= V_33 )
return V_23 ;
if ( ! F_29 ( V_4 ) )
return V_23 ;
if ( ! V_39 )
V_17 |= V_24 ;
F_20 ( V_22 , V_25 ) ;
F_27 ( V_22 , V_42 ,
V_4 , V_17 ) ;
return V_21 -> V_27 . V_28 ( V_2 , V_21 , V_22 ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = & V_2 -> V_21 ;
T_3 V_22 [ 1 ] ;
F_20 ( V_22 , V_43 ) ;
V_21 -> V_27 . V_28 ( V_2 , V_21 , V_22 ) ;
}
T_1 F_31 ( struct V_1 * V_2 , T_3 * * V_29 ,
struct V_20 * V_21 )
{
V_2 -> V_4 . V_44 = ! V_29 [ V_45 ] ?
V_46 : V_47 ;
return 0 ;
}
static T_1 F_32 ( struct V_1 * V_2 , T_4 V_38 ,
T_4 V_48 , bool V_49 )
{
struct V_20 * V_21 = & V_2 -> V_21 ;
T_3 V_22 [ 2 ] ;
V_2 -> V_4 . V_44 = V_46 ;
F_20 ( V_22 , V_50 ) ;
if ( ! V_49 )
F_33 ( V_22 , V_51 ) ;
return V_21 -> V_27 . V_28 ( V_2 , V_21 , V_22 ) ;
}
static T_1 F_34 ( struct V_1 * V_2 , T_4 V_38 , T_2 V_52 )
{
struct V_20 * V_21 = & V_2 -> V_21 ;
T_3 V_22 [ 3 ] ;
if ( V_52 > V_53 )
return V_23 ;
F_20 ( V_22 , V_50 ) ;
F_35 ( V_22 , V_54 , V_52 ) ;
return V_21 -> V_27 . V_28 ( V_2 , V_21 , V_22 ) ;
}
static void F_36 ( struct V_1 * V_2 ,
struct V_55 * V_56 )
{
F_37 ( V_2 , V_56 -> V_57 , 0 , V_2 -> V_4 . V_9 ) ;
}
static void F_38 ( struct V_1 * V_2 ,
struct V_55 * V_56 )
{
F_39 ( V_56 -> V_57 , 0 , V_2 -> V_4 . V_9 ) ;
F_36 ( V_2 , V_56 ) ;
}
static T_1 F_40 ( struct V_1 * V_2 ,
struct V_58 * V_59 )
{
if ( ! V_59 )
return V_23 ;
return 0 ;
}
static T_1 F_41 ( struct V_1 * V_2 , T_1 V_60 )
{
return V_60 ? V_23 : 0 ;
}
static T_5 F_42 ( struct V_1 * V_2 )
{
T_3 V_61 , V_62 , V_63 ;
V_62 = F_12 ( V_2 , V_64 + 1 ) ;
do {
V_63 = V_62 ;
V_61 = F_12 ( V_2 , V_64 ) ;
V_62 = F_12 ( V_2 , V_64 + 1 ) ;
} while ( V_63 != V_62 );
return ( ( T_5 ) V_62 << 32 ) | V_61 ;
}
static T_1 F_43 ( struct V_1 * V_2 )
{
F_44 ( V_2 ) ;
return F_45 ( V_2 , & V_2 -> V_21 , V_65 , 0 ) ;
}
