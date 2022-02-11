static void
F_1 ( short V_1 , int V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
void * V_7 ;
enum V_8 V_9 ;
if ( ! F_2 ( V_4 ) ) {
F_3 ( V_1 , V_2 , ( void * ) V_4 ) ;
V_10 -> V_11 . V_12 ++ ;
return;
}
F_4 ( V_13 , L_1 , V_4 -> V_14 , V_4 -> V_15 ,
V_4 -> V_16 , V_4 -> V_17 ) ;
V_6 = F_5 ( V_4 -> V_15 + V_18 ) ;
if ( ! V_6 ) {
F_6 ( V_13 , L_2 ,
V_4 -> V_15 + V_18 ) ;
F_3 ( V_1 , V_2 , ( void * ) V_4 ) ;
V_10 -> V_11 . V_12 ++ ;
return;
}
F_7 ( V_6 , ( V_18 - ( ( V_19 ) V_6 -> V_20 &
( V_18 - 1 ) ) +
V_4 -> V_16 ) ) ;
F_8 ( V_6 , ( V_4 -> V_15 - V_4 -> V_16 - V_4 -> V_17 ) ) ;
if ( ( F_9 ( V_4 -> V_21 ) == 1 ) &&
( V_4 -> V_22 != 0 ) ) {
F_4 ( V_13 , L_3
L_4 , V_6 -> V_20 , & V_4 -> V_20 ,
( V_23 ) V_4 -> V_22 ) ;
F_10 ( V_6 , & V_4 -> V_20 ,
( V_23 ) V_4 -> V_22 ) ;
} else {
V_7 = ( void * ) ( ( V_19 ) V_6 -> V_20 & ~ ( V_18 - 1 ) ) ;
F_4 ( V_13 , L_5
L_6 , V_7 ,
( void * ) V_4 -> V_14 , V_4 -> V_15 ) ;
V_9 = F_11 ( F_12 ( V_7 ) , V_4 -> V_14 , V_4 -> V_15 ) ;
if ( V_9 != V_24 ) {
F_6 ( V_13 , L_7
L_8 , V_7 ,
( void * ) V_4 -> V_14 , V_4 -> V_15 , V_9 ) ;
F_3 ( V_1 , V_2 , ( void * ) V_4 ) ;
V_10 -> V_11 . V_12 ++ ;
return;
}
}
F_4 ( V_13 , L_9
L_10 , ( void * ) V_6 -> V_25 ,
( void * ) V_6 -> V_20 , F_13 ( V_6 ) , F_14 ( V_6 ) ,
V_6 -> V_26 ) ;
V_6 -> V_27 = F_15 ( V_6 , V_10 ) ;
V_6 -> V_28 = V_29 ;
F_4 ( V_13 , L_11
L_12
L_10 ,
( void * ) V_6 -> V_25 , ( void * ) V_6 -> V_20 , F_13 ( V_6 ) ,
F_14 ( V_6 ) , V_6 -> V_26 ) ;
V_10 -> V_11 . V_30 ++ ;
V_10 -> V_11 . V_31 += V_6 -> V_26 + V_32 ;
F_16 ( V_6 ) ;
F_3 ( V_1 , V_2 , ( void * ) V_4 ) ;
}
static void
F_17 ( enum V_8 V_33 , short V_1 , int V_2 ,
void * V_20 , void * V_34 )
{
F_18 ( V_1 < 0 || V_1 >= V_35 ) ;
F_18 ( V_2 != V_36 ) ;
switch ( V_33 ) {
case V_37 :
F_18 ( V_20 == NULL ) ;
F_1 ( V_1 , V_2 , (struct V_3 * ) V_20 ) ;
break;
case V_38 :
F_19 ( & V_39 ) ;
F_20 ( V_1 , V_40 ) ;
F_21 ( & V_39 ) ;
F_22 ( V_10 ) ;
F_4 ( V_13 , L_13 ,
V_10 -> V_41 , V_1 ) ;
break;
default:
F_19 ( & V_39 ) ;
F_23 ( V_1 , V_40 ) ;
F_21 ( & V_39 ) ;
if ( F_24 ( ( unsigned long * ) V_40 ,
V_35 ) ) {
F_25 ( V_10 ) ;
}
F_4 ( V_13 , L_14 ,
V_10 -> V_41 , V_1 ) ;
break;
}
}
static int
F_26 ( struct V_42 * V_43 )
{
enum V_8 V_9 ;
F_4 ( V_13 , L_15
L_16 , V_36 , F_17 ,
( unsigned long ) V_44 ,
( unsigned long ) V_45 ,
( unsigned long ) V_46 ,
( unsigned long ) V_47 ) ;
V_9 = F_27 ( V_36 , F_17 , NULL ,
V_44 , V_45 ,
V_46 , V_47 ) ;
if ( V_9 != V_24 ) {
F_6 ( V_13 , L_17
L_18 , V_43 -> V_41 , V_9 ) ;
return - V_48 ;
}
F_4 ( V_13 , L_19 , V_43 -> V_41 ) ;
return 0 ;
}
static int
F_28 ( struct V_42 * V_43 )
{
F_29 ( V_36 ) ;
F_4 ( V_13 , L_20 , V_43 -> V_41 ) ;
return 0 ;
}
static int
F_30 ( struct V_42 * V_43 , int V_49 )
{
if ( ( V_49 < 68 ) || ( V_49 > V_50 ) ) {
F_6 ( V_13 , L_21
L_22 , V_43 -> V_41 , V_49 ,
V_50 ) ;
return - V_51 ;
}
V_43 -> V_52 = V_49 ;
F_4 ( V_13 , L_23 , V_43 -> V_41 , V_49 ) ;
return 0 ;
}
static void
F_31 ( enum V_8 V_33 , short V_1 , int V_2 ,
void * V_53 )
{
struct V_54 * V_55 = (struct V_54 * ) V_53 ;
F_18 ( V_55 == NULL ) ;
F_4 ( V_13 , L_24 ,
V_1 , V_33 ) ;
if ( F_32 ( & V_55 -> V_56 ) == 0 ) {
F_4 ( V_13 , L_25 ,
( void * ) V_55 -> V_6 -> V_25 ) ;
F_33 ( V_55 -> V_6 ) ;
F_34 ( V_55 ) ;
}
}
static void
F_35 ( struct V_5 * V_6 , struct V_54 * V_55 ,
V_19 V_57 , V_19 V_58 , T_1 V_22 , int V_59 )
{
T_2 V_60 [ V_44 ] ;
struct V_3 * V_4 = (struct V_3 * ) & V_60 ;
T_1 V_61 = sizeof( struct V_3 ) ;
enum V_8 V_9 ;
V_4 -> V_22 = V_22 ;
if ( F_36 ( V_22 != 0 ) ) {
V_4 -> V_21 = V_62 ;
F_4 ( V_13 , L_26 ,
& V_4 -> V_20 , V_6 -> V_20 , ( V_23 ) V_22 ) ;
F_37 ( V_6 , & V_4 -> V_20 ,
( V_23 ) V_22 ) ;
V_61 += V_22 - 1 ;
} else {
V_4 -> V_21 = V_63 ;
}
V_4 -> V_64 = V_65 ;
V_4 -> V_15 = V_58 - V_57 ;
V_4 -> V_16 = ( V_19 ) V_6 -> V_20 - V_57 ;
V_4 -> V_17 = V_58 - ( V_19 ) F_13 ( V_6 ) ;
V_4 -> V_14 = F_12 ( ( void * ) V_57 ) ;
F_4 ( V_13 , L_27
L_28
L_29 ,
V_59 , V_36 , V_4 -> V_14 , V_4 -> V_15 ,
V_4 -> V_16 , V_4 -> V_17 ) ;
F_38 ( & V_55 -> V_56 ) ;
V_9 = F_39 ( V_59 , V_36 , V_66 , V_4 ,
V_61 , F_31 , V_55 ) ;
if ( F_36 ( V_9 != V_24 ) )
F_40 ( & V_55 -> V_56 ) ;
}
static int
F_41 ( struct V_5 * V_6 , struct V_42 * V_43 )
{
struct V_54 * V_55 ;
V_19 V_57 , V_58 ;
short V_59 ;
T_1 V_22 = 0 ;
F_4 ( V_13 , L_30
L_10 , ( void * ) V_6 -> V_25 ,
( void * ) V_6 -> V_20 , F_13 ( V_6 ) , F_14 ( V_6 ) ,
V_6 -> V_26 ) ;
if ( V_6 -> V_20 [ 0 ] == 0x33 ) {
F_42 ( V_6 ) ;
return V_67 ;
}
V_55 = F_43 ( sizeof( struct V_54 ) , V_68 ) ;
if ( V_55 == NULL ) {
F_44 ( V_13 , L_31
L_32 , sizeof( struct V_54 ) ) ;
V_43 -> V_11 . V_69 ++ ;
F_42 ( V_6 ) ;
return V_67 ;
}
V_57 = ( ( V_19 ) V_6 -> V_20 & ~ ( V_18 - 1 ) ) ;
V_58 = F_45 ( ( V_19 ) F_13 ( V_6 ) ) ;
if ( F_36 ( V_6 -> V_26 <= V_70 ) ) {
V_22 = V_6 -> V_26 ;
}
F_46 ( & V_55 -> V_56 , 1 ) ;
V_55 -> V_6 = V_6 ;
if ( V_6 -> V_20 [ 0 ] == 0xff ) {
F_47 (dest_partid, xpnet_broadcast_partitions,
xp_max_npartitions) {
F_35 ( V_6 , V_55 , V_57 , V_58 ,
V_22 , V_59 ) ;
}
} else {
V_59 = ( short ) V_6 -> V_20 [ V_71 + 1 ] ;
V_59 |= ( short ) V_6 -> V_20 [ V_71 + 0 ] << 8 ;
if ( V_59 >= 0 &&
V_59 < V_35 &&
F_48 ( V_59 , V_40 ) != 0 ) {
F_35 ( V_6 , V_55 , V_57 , V_58 ,
V_22 , V_59 ) ;
}
}
V_43 -> V_11 . V_72 ++ ;
V_43 -> V_11 . V_73 += V_6 -> V_26 ;
if ( F_32 ( & V_55 -> V_56 ) == 0 ) {
F_42 ( V_6 ) ;
F_34 ( V_55 ) ;
}
return V_67 ;
}
static void
F_49 ( struct V_42 * V_43 )
{
V_43 -> V_11 . V_69 ++ ;
}
static int T_3
F_50 ( void )
{
int V_74 ;
if ( ! F_51 () && ! F_52 () )
return - V_75 ;
F_53 ( V_13 , L_33 , V_76 ) ;
V_40 = F_54 ( F_55 ( V_35 ) *
sizeof( long ) , V_77 ) ;
if ( V_40 == NULL )
return - V_48 ;
V_10 = F_56 ( 0 , V_76 , V_78 ,
V_79 ) ;
if ( V_10 == NULL ) {
F_34 ( V_40 ) ;
return - V_48 ;
}
F_25 ( V_10 ) ;
V_10 -> V_80 = & V_81 ;
V_10 -> V_52 = V_82 ;
V_10 -> V_83 [ 0 ] = 0x02 ;
V_10 -> V_83 [ V_71 + 1 ] = V_84 ;
V_10 -> V_83 [ V_71 + 0 ] = ( V_84 >> 8 ) ;
V_10 -> V_85 &= ~ V_86 ;
V_10 -> V_87 = V_88 ;
V_74 = F_57 ( V_10 ) ;
if ( V_74 != 0 ) {
F_58 ( V_10 ) ;
F_34 ( V_40 ) ;
}
return V_74 ;
}
static void T_4
F_59 ( void )
{
F_53 ( V_13 , L_34 ,
V_10 [ 0 ] . V_41 ) ;
F_60 ( V_10 ) ;
F_58 ( V_10 ) ;
F_34 ( V_40 ) ;
}
