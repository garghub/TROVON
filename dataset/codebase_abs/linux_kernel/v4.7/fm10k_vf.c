static T_1 F_1 ( struct V_1 * V_2 )
{
T_2 * V_3 = V_2 -> V_4 . V_3 ;
T_3 V_5 = 0 , V_6 = 0 , V_7 ;
T_1 V_8 ;
T_4 V_9 ;
V_8 = F_2 ( V_2 ) ;
if ( V_8 )
return V_8 ;
if ( F_3 ( V_3 ) ) {
V_5 = ( ( ( T_3 ) V_3 [ 3 ] ) << 24 ) |
( ( ( T_3 ) V_3 [ 4 ] ) << 16 ) |
( ( ( T_3 ) V_3 [ 5 ] ) << 8 ) ;
V_6 = ( ( ( T_3 ) 0xFF ) << 24 ) |
( ( ( T_3 ) V_3 [ 0 ] ) << 16 ) |
( ( ( T_3 ) V_3 [ 1 ] ) << 8 ) |
( ( T_3 ) V_3 [ 2 ] ) ;
}
V_7 = V_2 -> V_4 . V_10 << V_11 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_4 . V_12 ; V_9 ++ ) {
F_4 ( V_2 , F_5 ( V_9 ) , V_5 ) ;
F_4 ( V_2 , F_6 ( V_9 ) , V_6 ) ;
F_4 ( V_2 , F_7 ( V_9 ) , V_5 ) ;
F_4 ( V_2 , F_8 ( V_9 ) , V_6 ) ;
F_4 ( V_2 , F_9 ( V_9 ) , V_7 ) ;
}
return 0 ;
}
static T_1 F_10 ( struct V_1 * V_2 )
{
T_1 V_8 ;
V_8 = F_1 ( V_2 ) ;
if ( V_8 )
return V_8 ;
F_4 ( V_2 , V_13 , V_14 ) ;
F_11 ( V_2 ) ;
F_12 ( V_15 ) ;
F_4 ( V_2 , V_13 , 0 ) ;
if ( F_13 ( V_2 , V_13 ) & V_14 )
V_8 = V_16 ;
return V_8 ;
}
static T_1 F_14 ( struct V_1 * V_2 )
{
T_3 V_17 , V_18 = ~ F_13 ( V_2 , F_15 ( 0 ) ) ;
T_1 V_8 ;
T_4 V_9 ;
if ( ! ~ F_13 ( V_2 , F_16 ( 0 ) ) ||
! ~ F_13 ( V_2 , F_17 ( 0 ) ) ) {
V_8 = V_19 ;
goto V_20;
}
for ( V_9 = 1 ; V_18 && ( V_9 < V_21 ) ; V_9 ++ ) {
V_17 = ~ F_13 ( V_2 , F_15 ( V_9 ) ) ;
if ( ! V_17 || ( V_17 == V_18 ) )
break;
if ( ! ~ F_13 ( V_2 , F_16 ( V_9 ) ) ||
! ~ F_13 ( V_2 , F_17 ( V_9 ) ) )
break;
}
V_8 = F_18 ( V_2 , V_9 ) ;
if ( V_8 )
goto V_20;
V_2 -> V_4 . V_12 = V_9 ;
V_2 -> V_4 . V_22 = ( F_13 ( V_2 , F_16 ( 0 ) ) &
V_23 ) >> V_24 ;
V_2 -> V_4 . V_10 = ( F_13 ( V_2 , F_9 ( 0 ) ) &
V_25 ) >>
V_11 ;
return 0 ;
V_20:
V_2 -> V_4 . V_12 = 0 ;
return V_8 ;
}
static T_1 F_19 ( struct V_1 * V_2 , T_3 V_26 , T_2 V_27 , bool V_28 )
{
struct V_29 * V_30 = & V_2 -> V_30 ;
T_3 V_31 [ 4 ] ;
if ( V_27 )
return V_32 ;
if ( ( V_26 << 16 | V_26 ) >> 28 )
return V_32 ;
if ( ! V_28 )
V_26 |= V_33 ;
F_20 ( V_31 , V_34 ) ;
F_21 ( V_31 , V_35 , V_26 ) ;
return V_30 -> V_36 . V_37 ( V_2 , V_30 , V_31 ) ;
}
T_1 F_22 ( struct V_1 * V_2 , T_3 * * V_38 ,
struct V_29 * V_30 )
{
T_2 V_3 [ V_39 ] ;
T_4 V_26 ;
T_1 V_8 ;
V_8 = F_23 (
V_38 [ V_40 ] ,
V_3 , & V_26 ) ;
if ( V_8 )
return V_8 ;
F_24 ( V_2 -> V_4 . V_3 , V_3 ) ;
V_2 -> V_4 . V_22 = V_26 & ( V_41 - 1 ) ;
V_2 -> V_4 . V_42 = ! ! ( V_26 & V_43 ) ;
return 0 ;
}
static T_1 F_25 ( struct V_1 * V_2 )
{
T_2 V_3 [ V_39 ] ;
T_3 V_44 ;
V_44 = F_13 ( V_2 , F_5 ( 0 ) ) ;
if ( V_44 << 24 )
return V_45 ;
V_3 [ 3 ] = ( T_2 ) ( V_44 >> 24 ) ;
V_3 [ 4 ] = ( T_2 ) ( V_44 >> 16 ) ;
V_3 [ 5 ] = ( T_2 ) ( V_44 >> 8 ) ;
V_44 = F_13 ( V_2 , F_6 ( 0 ) ) ;
if ( ( ~ V_44 ) >> 24 )
return V_45 ;
V_3 [ 0 ] = ( T_2 ) ( V_44 >> 16 ) ;
V_3 [ 1 ] = ( T_2 ) ( V_44 >> 8 ) ;
V_3 [ 2 ] = ( T_2 ) ( V_44 ) ;
F_24 ( V_2 -> V_4 . V_3 , V_3 ) ;
F_24 ( V_2 -> V_4 . V_46 , V_3 ) ;
return 0 ;
}
static T_1 F_26 ( struct V_1 * V_2 , T_4 V_47 ,
const T_2 * V_4 , T_4 V_26 , bool V_48 , T_2 V_49 )
{
struct V_29 * V_30 = & V_2 -> V_30 ;
T_3 V_31 [ 7 ] ;
if ( V_26 >= V_41 )
return V_32 ;
if ( ! F_3 ( V_4 ) )
return V_32 ;
if ( F_3 ( V_2 -> V_4 . V_3 ) &&
! F_27 ( V_2 -> V_4 . V_3 , V_4 ) )
return V_32 ;
if ( ! V_48 )
V_26 |= V_33 ;
F_20 ( V_31 , V_34 ) ;
F_28 ( V_31 , V_50 , V_4 , V_26 ) ;
return V_30 -> V_36 . V_37 ( V_2 , V_30 , V_31 ) ;
}
static T_1 F_29 ( struct V_1 * V_2 , T_4 V_47 ,
const T_2 * V_4 , T_4 V_26 , bool V_48 )
{
struct V_29 * V_30 = & V_2 -> V_30 ;
T_3 V_31 [ 7 ] ;
if ( V_26 >= V_41 )
return V_32 ;
if ( ! F_30 ( V_4 ) )
return V_32 ;
if ( ! V_48 )
V_26 |= V_33 ;
F_20 ( V_31 , V_34 ) ;
F_28 ( V_31 , V_51 ,
V_4 , V_26 ) ;
return V_30 -> V_36 . V_37 ( V_2 , V_30 , V_31 ) ;
}
static void F_31 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = & V_2 -> V_30 ;
T_3 V_31 [ 1 ] ;
F_20 ( V_31 , V_52 ) ;
V_30 -> V_36 . V_37 ( V_2 , V_30 , V_31 ) ;
}
T_1 F_32 ( struct V_1 * V_2 , T_3 * * V_38 ,
struct V_29 * V_30 )
{
V_2 -> V_4 . V_53 = ! V_38 [ V_54 ] ?
V_55 : V_56 ;
return 0 ;
}
static T_1 F_33 ( struct V_1 * V_2 , T_4 V_47 ,
T_4 V_57 , bool V_58 )
{
struct V_29 * V_30 = & V_2 -> V_30 ;
T_3 V_31 [ 2 ] ;
V_2 -> V_4 . V_53 = V_55 ;
F_20 ( V_31 , V_59 ) ;
if ( ! V_58 )
F_34 ( V_31 , V_60 ) ;
return V_30 -> V_36 . V_37 ( V_2 , V_30 , V_31 ) ;
}
static T_1 F_35 ( struct V_1 * V_2 , T_4 V_47 , T_2 V_61 )
{
struct V_29 * V_30 = & V_2 -> V_30 ;
T_3 V_31 [ 3 ] ;
if ( V_61 > V_62 )
return V_32 ;
F_20 ( V_31 , V_59 ) ;
F_36 ( V_31 , V_63 , V_61 ) ;
return V_30 -> V_36 . V_37 ( V_2 , V_30 , V_31 ) ;
}
static void F_37 ( struct V_1 * V_2 ,
struct V_64 * V_65 )
{
F_38 ( V_2 , V_65 -> V_66 , 0 , V_2 -> V_4 . V_12 ) ;
}
static void F_39 ( struct V_1 * V_2 ,
struct V_64 * V_65 )
{
F_40 ( V_65 -> V_66 , 0 , V_2 -> V_4 . V_12 ) ;
F_37 ( V_2 , V_65 ) ;
}
static T_1 F_41 ( struct V_1 * V_2 ,
struct V_67 * V_68 )
{
if ( ! V_68 )
return V_32 ;
return 0 ;
}
static T_1 F_42 ( struct V_1 * V_2 )
{
F_43 ( V_2 ) ;
return F_44 ( V_2 , & V_2 -> V_30 , V_69 , 0 ) ;
}
