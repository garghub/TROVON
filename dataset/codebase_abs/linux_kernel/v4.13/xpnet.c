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
static void
F_30 ( enum V_8 V_33 , short V_1 , int V_2 ,
void * V_49 )
{
struct V_50 * V_51 = (struct V_50 * ) V_49 ;
F_18 ( V_51 == NULL ) ;
F_4 ( V_13 , L_21 ,
V_1 , V_33 ) ;
if ( F_31 ( & V_51 -> V_52 ) == 0 ) {
F_4 ( V_13 , L_22 ,
( void * ) V_51 -> V_6 -> V_25 ) ;
F_32 ( V_51 -> V_6 ) ;
F_33 ( V_51 ) ;
}
}
static void
F_34 ( struct V_5 * V_6 , struct V_50 * V_51 ,
V_19 V_53 , V_19 V_54 , T_1 V_22 , int V_55 )
{
T_2 V_56 [ V_44 ] ;
struct V_3 * V_4 = (struct V_3 * ) & V_56 ;
T_1 V_57 = sizeof( struct V_3 ) ;
enum V_8 V_9 ;
V_4 -> V_22 = V_22 ;
if ( F_35 ( V_22 != 0 ) ) {
V_4 -> V_21 = V_58 ;
F_4 ( V_13 , L_23 ,
& V_4 -> V_20 , V_6 -> V_20 , ( V_23 ) V_22 ) ;
F_36 ( V_6 , & V_4 -> V_20 ,
( V_23 ) V_22 ) ;
V_57 += V_22 - 1 ;
} else {
V_4 -> V_21 = V_59 ;
}
V_4 -> V_60 = V_61 ;
V_4 -> V_15 = V_54 - V_53 ;
V_4 -> V_16 = ( V_19 ) V_6 -> V_20 - V_53 ;
V_4 -> V_17 = V_54 - ( V_19 ) F_13 ( V_6 ) ;
V_4 -> V_14 = F_12 ( ( void * ) V_53 ) ;
F_4 ( V_13 , L_24
L_25
L_26 ,
V_55 , V_36 , V_4 -> V_14 , V_4 -> V_15 ,
V_4 -> V_16 , V_4 -> V_17 ) ;
F_37 ( & V_51 -> V_52 ) ;
V_9 = F_38 ( V_55 , V_36 , V_62 , V_4 ,
V_57 , F_30 , V_51 ) ;
if ( F_35 ( V_9 != V_24 ) )
F_39 ( & V_51 -> V_52 ) ;
}
static int
F_40 ( struct V_5 * V_6 , struct V_42 * V_43 )
{
struct V_50 * V_51 ;
V_19 V_53 , V_54 ;
short V_55 ;
T_1 V_22 = 0 ;
F_4 ( V_13 , L_27
L_10 , ( void * ) V_6 -> V_25 ,
( void * ) V_6 -> V_20 , F_13 ( V_6 ) , F_14 ( V_6 ) ,
V_6 -> V_26 ) ;
if ( V_6 -> V_20 [ 0 ] == 0x33 ) {
F_41 ( V_6 ) ;
return V_63 ;
}
V_51 = F_42 ( sizeof( struct V_50 ) , V_64 ) ;
if ( V_51 == NULL ) {
F_43 ( V_13 , L_28
L_29 , sizeof( struct V_50 ) ) ;
V_43 -> V_11 . V_65 ++ ;
F_41 ( V_6 ) ;
return V_63 ;
}
V_53 = ( ( V_19 ) V_6 -> V_20 & ~ ( V_18 - 1 ) ) ;
V_54 = F_44 ( ( V_19 ) F_13 ( V_6 ) ) ;
if ( F_35 ( V_6 -> V_26 <= V_66 ) ) {
V_22 = V_6 -> V_26 ;
}
F_45 ( & V_51 -> V_52 , 1 ) ;
V_51 -> V_6 = V_6 ;
if ( V_6 -> V_20 [ 0 ] == 0xff ) {
F_46 (dest_partid, xpnet_broadcast_partitions,
xp_max_npartitions) {
F_34 ( V_6 , V_51 , V_53 , V_54 ,
V_22 , V_55 ) ;
}
} else {
V_55 = ( short ) V_6 -> V_20 [ V_67 + 1 ] ;
V_55 |= ( short ) V_6 -> V_20 [ V_67 + 0 ] << 8 ;
if ( V_55 >= 0 &&
V_55 < V_35 &&
F_47 ( V_55 , V_40 ) != 0 ) {
F_34 ( V_6 , V_51 , V_53 , V_54 ,
V_22 , V_55 ) ;
}
}
V_43 -> V_11 . V_68 ++ ;
V_43 -> V_11 . V_69 += V_6 -> V_26 ;
if ( F_31 ( & V_51 -> V_52 ) == 0 ) {
F_41 ( V_6 ) ;
F_33 ( V_51 ) ;
}
return V_63 ;
}
static void
F_48 ( struct V_42 * V_43 )
{
V_43 -> V_11 . V_65 ++ ;
}
static int T_3
F_49 ( void )
{
int V_70 ;
if ( ! F_50 () && ! F_51 () )
return - V_71 ;
F_52 ( V_13 , L_30 , V_72 ) ;
V_40 = F_53 ( F_54 ( V_35 ) *
sizeof( long ) , V_73 ) ;
if ( V_40 == NULL )
return - V_48 ;
V_10 = F_55 ( 0 , V_72 , V_74 ,
V_75 ) ;
if ( V_10 == NULL ) {
F_33 ( V_40 ) ;
return - V_48 ;
}
F_25 ( V_10 ) ;
V_10 -> V_76 = & V_77 ;
V_10 -> V_78 = V_79 ;
V_10 -> V_80 = V_81 ;
V_10 -> V_82 = V_83 ;
V_10 -> V_84 [ 0 ] = 0x02 ;
V_10 -> V_84 [ V_67 + 1 ] = V_85 ;
V_10 -> V_84 [ V_67 + 0 ] = ( V_85 >> 8 ) ;
V_10 -> V_86 &= ~ V_87 ;
V_10 -> V_88 = V_89 ;
V_70 = F_56 ( V_10 ) ;
if ( V_70 != 0 ) {
F_57 ( V_10 ) ;
F_33 ( V_40 ) ;
}
return V_70 ;
}
static void T_4
F_58 ( void )
{
F_52 ( V_13 , L_31 ,
V_10 [ 0 ] . V_41 ) ;
F_59 ( V_10 ) ;
F_57 ( V_10 ) ;
F_33 ( V_40 ) ;
}
