static int
F_1 (
struct V_1 * V_2 ,
int V_3 )
{
int V_4 = sizeof( struct V_5 ) ;
V_4 += V_3 ;
V_4 += V_2 -> V_6 ? sizeof( V_7 ) :
sizeof( V_8 ) ;
return V_4 ;
}
static int
F_2 (
struct V_1 * V_2 ,
int V_3 )
{
return F_1 ( V_2 , V_3 ) + sizeof( V_9 ) ;
}
static struct V_5 *
F_3 (
struct V_1 * V_2 ,
struct V_5 * V_10 )
{
return (struct V_5 * )
( ( char * ) V_10 + F_1 ( V_2 , V_10 -> V_11 ) ) ;
}
static struct V_5 *
F_4 (
struct V_1 * V_2 ,
struct V_5 * V_10 )
{
return (struct V_5 * )
( ( char * ) V_10 + F_2 ( V_2 , V_10 -> V_11 ) ) ;
}
static V_9
F_5 (
struct V_5 * V_10 )
{
return V_12 ;
}
static void
F_6 (
struct V_5 * V_10 ,
V_9 V_13 )
{
ASSERT ( V_13 < V_14 ) ;
}
static V_9
F_7 (
struct V_5 * V_10 )
{
V_9 V_13 ;
V_13 = V_10 -> V_15 [ V_10 -> V_11 ] ;
if ( V_13 >= V_14 )
return V_12 ;
return V_13 ;
}
static void
F_8 (
struct V_5 * V_10 ,
V_9 V_13 )
{
ASSERT ( V_13 < V_14 ) ;
V_10 -> V_15 [ V_10 -> V_11 ] = V_13 ;
}
static T_1
F_9 (
struct V_1 * V_2 ,
T_2 * V_16 )
{
if ( V_2 -> V_6 )
return F_10 ( & V_16 -> V_17 . V_18 ) & 0x00ffffffffffffffULL ;
else
return F_11 ( & V_16 -> V_19 . V_18 ) ;
}
static void
F_12 (
struct V_1 * V_2 ,
T_2 * V_20 ,
T_1 V_21 )
{
ASSERT ( ( V_21 & 0xff00000000000000ULL ) == 0 ) ;
if ( V_2 -> V_6 )
F_13 ( V_21 , & V_20 -> V_17 . V_18 ) ;
else
F_14 ( V_21 , & V_20 -> V_19 . V_18 ) ;
}
static T_1
F_15 (
struct V_1 * V_2 )
{
return F_9 ( V_2 , & V_2 -> V_22 ) ;
}
static void
F_16 (
struct V_1 * V_2 ,
T_1 V_21 )
{
F_12 ( V_2 , & V_2 -> V_22 , V_21 ) ;
}
static T_1
F_17 (
struct V_1 * V_2 ,
struct V_5 * V_10 )
{
return F_9 ( V_2 ,
( T_2 * ) & V_10 -> V_15 [ V_10 -> V_11 ] ) ;
}
static void
F_18 (
struct V_1 * V_2 ,
struct V_5 * V_10 ,
T_1 V_21 )
{
F_12 ( V_2 ,
( T_2 * ) & V_10 -> V_15 [ V_10 -> V_11 ] , V_21 ) ;
}
static T_1
F_19 (
struct V_1 * V_2 ,
struct V_5 * V_10 )
{
return F_9 ( V_2 ,
( T_2 * ) & V_10 -> V_15 [ V_10 -> V_11 + 1 ] ) ;
}
static void
F_20 (
struct V_1 * V_2 ,
struct V_5 * V_10 ,
T_1 V_21 )
{
F_12 ( V_2 ,
( T_2 * ) & V_10 -> V_15 [ V_10 -> V_11 + 1 ] , V_21 ) ;
}
static int
F_21 (
int V_23 )
{
return F_22 ( V_23 ) ;
}
static int
F_23 (
int V_23 )
{
return F_24 ( V_23 ) ;
}
static V_9
F_25 (
struct V_24 * V_25 )
{
return V_12 ;
}
static void
F_26 (
struct V_24 * V_25 ,
V_9 V_13 )
{
ASSERT ( V_13 < V_14 ) ;
}
static V_9
F_27 (
struct V_24 * V_25 )
{
V_9 V_13 = V_25 -> V_15 [ V_25 -> V_11 ] ;
if ( V_13 >= V_14 )
return V_12 ;
return V_13 ;
}
static void
F_28 (
struct V_24 * V_25 ,
V_9 type )
{
ASSERT ( type < V_14 ) ;
ASSERT ( V_25 -> V_11 != 0 ) ;
V_25 -> V_15 [ V_25 -> V_11 ] = type ;
}
static T_3 *
F_29 (
struct V_24 * V_25 )
{
return ( T_3 * ) ( ( char * ) V_25 +
F_21 ( V_25 -> V_11 ) - sizeof( T_3 ) ) ;
}
static T_3 *
F_30 (
struct V_24 * V_25 )
{
return ( T_3 * ) ( ( char * ) V_25 +
F_23 ( V_25 -> V_11 ) - sizeof( T_3 ) ) ;
}
static struct V_24 *
F_31 (
struct V_26 * V_2 )
{
return (struct V_24 * )
( ( char * ) V_2 + sizeof( struct V_26 ) ) ;
}
static struct V_24 *
F_32 (
struct V_26 * V_2 )
{
return (struct V_24 * )
( ( char * ) V_2 + sizeof( struct V_26 ) +
F_22 ( 1 ) ) ;
}
static struct V_24 *
F_33 (
struct V_26 * V_2 )
{
return (struct V_24 * )
( ( char * ) V_2 + sizeof( struct V_26 ) +
F_22 ( 1 ) +
F_22 ( 2 ) ) ;
}
static struct V_24 *
F_34 (
struct V_26 * V_2 )
{
return (struct V_24 * )
( ( char * ) V_2 + sizeof( struct V_26 ) +
F_24 ( 1 ) ) ;
}
static struct V_24 *
F_35 (
struct V_26 * V_2 )
{
return (struct V_24 * )
( ( char * ) V_2 + sizeof( struct V_26 ) +
F_24 ( 1 ) +
F_24 ( 2 ) ) ;
}
static struct V_24 *
F_36 (
struct V_26 * V_2 )
{
return (struct V_24 * )
( ( char * ) V_2 + sizeof( struct V_27 ) ) ;
}
static struct V_24 *
F_37 (
struct V_26 * V_2 )
{
return (struct V_24 * )
( ( char * ) V_2 + sizeof( struct V_27 ) +
F_24 ( 1 ) ) ;
}
static struct V_24 *
F_38 (
struct V_26 * V_2 )
{
return (struct V_24 * )
( ( char * ) V_2 + sizeof( struct V_27 ) +
F_24 ( 1 ) +
F_24 ( 2 ) ) ;
}
static struct V_28 *
F_39 ( struct V_26 * V_2 )
{
return V_2 -> V_29 ;
}
static struct V_28 *
F_40 ( struct V_26 * V_2 )
{
return ( (struct V_27 * ) V_2 ) -> V_30 ;
}
static struct V_24 *
F_41 ( struct V_26 * V_2 )
{
return (struct V_24 * )
( ( char * ) V_2 + sizeof( struct V_26 ) ) ;
}
static struct V_31 *
F_42 ( struct V_26 * V_2 )
{
return (struct V_31 * )
( ( char * ) V_2 + sizeof( struct V_26 ) ) ;
}
static struct V_24 *
F_43 ( struct V_26 * V_2 )
{
return (struct V_24 * )
( ( char * ) V_2 + sizeof( struct V_27 ) ) ;
}
static struct V_31 *
F_44 ( struct V_26 * V_2 )
{
return (struct V_31 * )
( ( char * ) V_2 + sizeof( struct V_27 ) ) ;
}
static int
F_45 ( struct V_32 * V_33 )
{
return ( V_33 -> V_34 - sizeof( struct V_35 ) ) /
( V_36 ) sizeof( struct V_37 ) ;
}
static struct V_37 *
F_46 ( struct V_38 * V_39 )
{
return V_39 -> V_40 ;
}
static int
F_47 ( struct V_32 * V_33 )
{
return ( V_33 -> V_34 - sizeof( struct V_41 ) ) /
( V_36 ) sizeof( struct V_37 ) ;
}
static struct V_37 *
F_48 ( struct V_38 * V_39 )
{
return ( (struct V_42 * ) V_39 ) -> V_40 ;
}
static void
F_49 (
struct V_43 * V_20 ,
struct V_38 * V_16 )
{
V_20 -> V_44 = F_50 ( V_16 -> V_2 . V_45 . V_44 ) ;
V_20 -> V_46 = F_50 ( V_16 -> V_2 . V_45 . V_46 ) ;
V_20 -> V_47 = F_51 ( V_16 -> V_2 . V_45 . V_47 ) ;
V_20 -> V_4 = F_51 ( V_16 -> V_2 . V_4 ) ;
V_20 -> V_48 = F_51 ( V_16 -> V_2 . V_48 ) ;
ASSERT ( V_20 -> V_47 == V_49 ||
V_20 -> V_47 == V_50 ) ;
}
static void
F_52 (
struct V_38 * V_20 ,
struct V_43 * V_16 )
{
ASSERT ( V_16 -> V_47 == V_49 ||
V_16 -> V_47 == V_50 ) ;
V_20 -> V_2 . V_45 . V_44 = F_53 ( V_16 -> V_44 ) ;
V_20 -> V_2 . V_45 . V_46 = F_53 ( V_16 -> V_46 ) ;
V_20 -> V_2 . V_45 . V_47 = F_54 ( V_16 -> V_47 ) ;
V_20 -> V_2 . V_4 = F_54 ( V_16 -> V_4 ) ;
V_20 -> V_2 . V_48 = F_54 ( V_16 -> V_48 ) ;
}
static void
F_55 (
struct V_43 * V_20 ,
struct V_38 * V_16 )
{
struct V_41 * V_51 = (struct V_41 * ) V_16 ;
V_20 -> V_44 = F_50 ( V_51 -> V_45 . V_2 . V_44 ) ;
V_20 -> V_46 = F_50 ( V_51 -> V_45 . V_2 . V_46 ) ;
V_20 -> V_47 = F_51 ( V_51 -> V_45 . V_2 . V_47 ) ;
V_20 -> V_4 = F_51 ( V_51 -> V_4 ) ;
V_20 -> V_48 = F_51 ( V_51 -> V_48 ) ;
ASSERT ( V_20 -> V_47 == V_52 ||
V_20 -> V_47 == V_53 ) ;
}
static void
F_56 (
struct V_38 * V_20 ,
struct V_43 * V_16 )
{
struct V_41 * V_51 = (struct V_41 * ) V_20 ;
ASSERT ( V_16 -> V_47 == V_52 ||
V_16 -> V_47 == V_53 ) ;
V_51 -> V_45 . V_2 . V_44 = F_53 ( V_16 -> V_44 ) ;
V_51 -> V_45 . V_2 . V_46 = F_53 ( V_16 -> V_46 ) ;
V_51 -> V_45 . V_2 . V_47 = F_54 ( V_16 -> V_47 ) ;
V_51 -> V_4 = F_54 ( V_16 -> V_4 ) ;
V_51 -> V_48 = F_54 ( V_16 -> V_48 ) ;
}
static struct V_54 *
F_57 ( struct V_55 * V_56 )
{
return V_56 -> V_57 ;
}
static struct V_54 *
F_58 ( struct V_55 * V_56 )
{
return ( (struct V_58 * ) V_56 ) -> V_57 ;
}
static void
F_59 (
struct V_59 * V_20 ,
struct V_55 * V_16 )
{
ASSERT ( V_16 -> V_2 . V_45 . V_47 == F_54 ( V_60 ) ) ;
V_20 -> V_44 = F_50 ( V_16 -> V_2 . V_45 . V_44 ) ;
V_20 -> V_46 = F_50 ( V_16 -> V_2 . V_45 . V_46 ) ;
V_20 -> V_47 = F_51 ( V_16 -> V_2 . V_45 . V_47 ) ;
V_20 -> V_4 = F_51 ( V_16 -> V_2 . V_61 ) ;
V_20 -> V_62 = F_51 ( V_16 -> V_2 . V_63 ) ;
}
static void
F_60 (
struct V_55 * V_20 ,
struct V_59 * V_16 )
{
ASSERT ( V_16 -> V_47 == V_60 ) ;
V_20 -> V_2 . V_45 . V_44 = F_53 ( V_16 -> V_44 ) ;
V_20 -> V_2 . V_45 . V_46 = F_53 ( V_16 -> V_46 ) ;
V_20 -> V_2 . V_45 . V_47 = F_54 ( V_16 -> V_47 ) ;
V_20 -> V_2 . V_61 = F_54 ( V_16 -> V_4 ) ;
V_20 -> V_2 . V_63 = F_54 ( V_16 -> V_62 ) ;
}
static void
F_61 (
struct V_59 * V_20 ,
struct V_55 * V_16 )
{
struct V_64 * V_51 = (struct V_64 * ) V_16 ;
ASSERT ( V_16 -> V_2 . V_45 . V_47 == F_54 ( V_65 ) ) ;
V_20 -> V_44 = F_50 ( V_51 -> V_45 . V_2 . V_44 ) ;
V_20 -> V_46 = F_50 ( V_51 -> V_45 . V_2 . V_46 ) ;
V_20 -> V_47 = F_51 ( V_51 -> V_45 . V_2 . V_47 ) ;
V_20 -> V_4 = F_51 ( V_51 -> V_61 ) ;
V_20 -> V_62 = F_51 ( V_51 -> V_63 ) ;
}
static void
F_62 (
struct V_55 * V_20 ,
struct V_59 * V_16 )
{
struct V_64 * V_51 = (struct V_64 * ) V_20 ;
ASSERT ( V_16 -> V_47 == V_65 ) ;
V_51 -> V_45 . V_2 . V_44 = F_53 ( V_16 -> V_44 ) ;
V_51 -> V_45 . V_2 . V_46 = F_53 ( V_16 -> V_46 ) ;
V_51 -> V_45 . V_2 . V_47 = F_54 ( V_16 -> V_47 ) ;
V_51 -> V_61 = F_54 ( V_16 -> V_4 ) ;
V_51 -> V_63 = F_54 ( V_16 -> V_62 ) ;
}
static int
F_63 ( struct V_32 * V_33 )
{
return ( V_33 -> V_34 - sizeof( struct V_66 ) ) /
sizeof( V_67 ) ;
}
static T_3 *
F_64 ( struct V_68 * free )
{
return ( T_3 * ) ( ( char * ) free + sizeof( struct V_66 ) ) ;
}
static T_4
F_65 ( struct V_32 * V_33 , T_4 V_69 )
{
return F_66 ( V_33 , V_70 ) +
( V_69 / F_63 ( V_33 ) ) ;
}
static int
F_67 ( struct V_32 * V_33 , T_4 V_69 )
{
return V_69 % F_63 ( V_33 ) ;
}
static int
F_68 ( struct V_32 * V_33 )
{
return ( V_33 -> V_34 - sizeof( struct V_71 ) ) /
sizeof( V_67 ) ;
}
static T_3 *
F_69 ( struct V_68 * free )
{
return ( T_3 * ) ( ( char * ) free + sizeof( struct V_71 ) ) ;
}
static T_4
F_70 ( struct V_32 * V_33 , T_4 V_69 )
{
return F_66 ( V_33 , V_70 ) +
( V_69 / F_68 ( V_33 ) ) ;
}
static int
F_71 ( struct V_32 * V_33 , T_4 V_69 )
{
return V_69 % F_68 ( V_33 ) ;
}
static void
F_72 (
struct V_72 * V_20 ,
struct V_68 * V_16 )
{
V_20 -> V_47 = F_50 ( V_16 -> V_2 . V_47 ) ;
V_20 -> V_73 = F_50 ( V_16 -> V_2 . V_73 ) ;
V_20 -> V_74 = F_50 ( V_16 -> V_2 . V_74 ) ;
V_20 -> V_75 = F_50 ( V_16 -> V_2 . V_75 ) ;
ASSERT ( V_20 -> V_47 == V_76 ) ;
}
static void
F_73 (
struct V_68 * V_20 ,
struct V_72 * V_16 )
{
ASSERT ( V_16 -> V_47 == V_76 ) ;
V_20 -> V_2 . V_47 = F_53 ( V_16 -> V_47 ) ;
V_20 -> V_2 . V_73 = F_53 ( V_16 -> V_73 ) ;
V_20 -> V_2 . V_74 = F_53 ( V_16 -> V_74 ) ;
V_20 -> V_2 . V_75 = F_53 ( V_16 -> V_75 ) ;
}
static void
F_74 (
struct V_72 * V_20 ,
struct V_68 * V_16 )
{
struct V_71 * V_51 = (struct V_71 * ) V_16 ;
V_20 -> V_47 = F_50 ( V_51 -> V_2 . V_47 ) ;
V_20 -> V_73 = F_50 ( V_51 -> V_73 ) ;
V_20 -> V_74 = F_50 ( V_51 -> V_74 ) ;
V_20 -> V_75 = F_50 ( V_51 -> V_75 ) ;
ASSERT ( V_20 -> V_47 == V_77 ) ;
}
static void
F_75 (
struct V_68 * V_20 ,
struct V_72 * V_16 )
{
struct V_71 * V_51 = (struct V_71 * ) V_20 ;
ASSERT ( V_16 -> V_47 == V_77 ) ;
V_51 -> V_2 . V_47 = F_53 ( V_16 -> V_47 ) ;
V_51 -> V_73 = F_53 ( V_16 -> V_73 ) ;
V_51 -> V_74 = F_53 ( V_16 -> V_74 ) ;
V_51 -> V_75 = F_53 ( V_16 -> V_75 ) ;
}
const struct V_78 *
F_76 (
struct V_79 * V_80 ,
struct V_81 * V_82 )
{
if ( V_82 )
return V_82 -> V_83 ;
if ( V_80 -> V_84 )
return V_80 -> V_84 ;
if ( F_77 ( & V_80 -> V_85 ) )
return & V_86 ;
if ( F_78 ( & V_80 -> V_85 ) )
return & V_87 ;
return & V_88 ;
}
const struct V_78 *
F_79 (
struct V_79 * V_80 ,
struct V_81 * V_82 )
{
if ( V_82 )
return V_82 -> V_83 ;
if ( V_80 -> V_89 )
return V_80 -> V_89 ;
if ( F_77 ( & V_80 -> V_85 ) )
return & V_90 ;
return & V_91 ;
}
