static int
F_1 (
struct V_1 * V_2 ,
int V_3 )
{
int V_4 = sizeof( struct V_5 ) ;
V_4 += V_3 ;
V_4 += V_2 -> V_6 ? V_7 : V_8 ;
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
V_9 * V_16 )
{
if ( V_2 -> V_6 )
return F_10 ( V_16 ) & 0x00ffffffffffffffULL ;
else
return F_11 ( V_16 ) ;
}
static void
F_12 (
struct V_1 * V_2 ,
V_9 * V_17 ,
T_1 V_18 )
{
ASSERT ( ( V_18 & 0xff00000000000000ULL ) == 0 ) ;
if ( V_2 -> V_6 )
F_13 ( V_18 , V_17 ) ;
else
F_14 ( V_18 , V_17 ) ;
}
static T_1
F_15 (
struct V_1 * V_2 )
{
return F_9 ( V_2 , V_2 -> V_19 ) ;
}
static void
F_16 (
struct V_1 * V_2 ,
T_1 V_18 )
{
F_12 ( V_2 , V_2 -> V_19 , V_18 ) ;
}
static T_1
F_17 (
struct V_1 * V_2 ,
struct V_5 * V_10 )
{
return F_9 ( V_2 , & V_10 -> V_15 [ V_10 -> V_11 ] ) ;
}
static void
F_18 (
struct V_1 * V_2 ,
struct V_5 * V_10 ,
T_1 V_18 )
{
F_12 ( V_2 , & V_10 -> V_15 [ V_10 -> V_11 ] , V_18 ) ;
}
static T_1
F_19 (
struct V_1 * V_2 ,
struct V_5 * V_10 )
{
return F_9 ( V_2 , & V_10 -> V_15 [ V_10 -> V_11 + 1 ] ) ;
}
static void
F_20 (
struct V_1 * V_2 ,
struct V_5 * V_10 ,
T_1 V_18 )
{
F_12 ( V_2 , & V_10 -> V_15 [ V_10 -> V_11 + 1 ] , V_18 ) ;
}
static int
F_21 (
int V_20 )
{
return F_22 ( V_20 ) ;
}
static int
F_23 (
int V_20 )
{
return F_24 ( V_20 ) ;
}
static V_9
F_25 (
struct V_21 * V_22 )
{
return V_12 ;
}
static void
F_26 (
struct V_21 * V_22 ,
V_9 V_13 )
{
ASSERT ( V_13 < V_14 ) ;
}
static V_9
F_27 (
struct V_21 * V_22 )
{
V_9 V_13 = V_22 -> V_15 [ V_22 -> V_11 ] ;
if ( V_13 >= V_14 )
return V_12 ;
return V_13 ;
}
static void
F_28 (
struct V_21 * V_22 ,
V_9 type )
{
ASSERT ( type < V_14 ) ;
ASSERT ( V_22 -> V_11 != 0 ) ;
V_22 -> V_15 [ V_22 -> V_11 ] = type ;
}
static T_2 *
F_29 (
struct V_21 * V_22 )
{
return ( T_2 * ) ( ( char * ) V_22 +
F_21 ( V_22 -> V_11 ) - sizeof( T_2 ) ) ;
}
static T_2 *
F_30 (
struct V_21 * V_22 )
{
return ( T_2 * ) ( ( char * ) V_22 +
F_23 ( V_22 -> V_11 ) - sizeof( T_2 ) ) ;
}
static struct V_21 *
F_31 (
struct V_23 * V_2 )
{
return (struct V_21 * )
( ( char * ) V_2 + sizeof( struct V_23 ) ) ;
}
static struct V_21 *
F_32 (
struct V_23 * V_2 )
{
return (struct V_21 * )
( ( char * ) V_2 + sizeof( struct V_23 ) +
F_22 ( 1 ) ) ;
}
static struct V_21 *
F_33 (
struct V_23 * V_2 )
{
return (struct V_21 * )
( ( char * ) V_2 + sizeof( struct V_23 ) +
F_22 ( 1 ) +
F_22 ( 2 ) ) ;
}
static struct V_21 *
F_34 (
struct V_23 * V_2 )
{
return (struct V_21 * )
( ( char * ) V_2 + sizeof( struct V_23 ) +
F_24 ( 1 ) ) ;
}
static struct V_21 *
F_35 (
struct V_23 * V_2 )
{
return (struct V_21 * )
( ( char * ) V_2 + sizeof( struct V_23 ) +
F_24 ( 1 ) +
F_24 ( 2 ) ) ;
}
static struct V_21 *
F_36 (
struct V_23 * V_2 )
{
return (struct V_21 * )
( ( char * ) V_2 + sizeof( struct V_24 ) ) ;
}
static struct V_21 *
F_37 (
struct V_23 * V_2 )
{
return (struct V_21 * )
( ( char * ) V_2 + sizeof( struct V_24 ) +
F_24 ( 1 ) ) ;
}
static struct V_21 *
F_38 (
struct V_23 * V_2 )
{
return (struct V_21 * )
( ( char * ) V_2 + sizeof( struct V_24 ) +
F_24 ( 1 ) +
F_24 ( 2 ) ) ;
}
static struct V_25 *
F_39 ( struct V_23 * V_2 )
{
return V_2 -> V_26 ;
}
static struct V_25 *
F_40 ( struct V_23 * V_2 )
{
return ( (struct V_24 * ) V_2 ) -> V_27 ;
}
static struct V_21 *
F_41 ( struct V_23 * V_2 )
{
return (struct V_21 * )
( ( char * ) V_2 + sizeof( struct V_23 ) ) ;
}
static struct V_28 *
F_42 ( struct V_23 * V_2 )
{
return (struct V_28 * )
( ( char * ) V_2 + sizeof( struct V_23 ) ) ;
}
static struct V_21 *
F_43 ( struct V_23 * V_2 )
{
return (struct V_21 * )
( ( char * ) V_2 + sizeof( struct V_24 ) ) ;
}
static struct V_28 *
F_44 ( struct V_23 * V_2 )
{
return (struct V_28 * )
( ( char * ) V_2 + sizeof( struct V_24 ) ) ;
}
static int
F_45 ( struct V_29 * V_30 )
{
return ( V_30 -> V_31 - sizeof( struct V_32 ) ) /
( V_33 ) sizeof( struct V_34 ) ;
}
static struct V_34 *
F_46 ( struct V_35 * V_36 )
{
return V_36 -> V_37 ;
}
static int
F_47 ( struct V_29 * V_30 )
{
return ( V_30 -> V_31 - sizeof( struct V_38 ) ) /
( V_33 ) sizeof( struct V_34 ) ;
}
static struct V_34 *
F_48 ( struct V_35 * V_36 )
{
return ( (struct V_39 * ) V_36 ) -> V_37 ;
}
static void
F_49 (
struct V_40 * V_17 ,
struct V_35 * V_16 )
{
V_17 -> V_41 = F_50 ( V_16 -> V_2 . V_42 . V_41 ) ;
V_17 -> V_43 = F_50 ( V_16 -> V_2 . V_42 . V_43 ) ;
V_17 -> V_44 = F_51 ( V_16 -> V_2 . V_42 . V_44 ) ;
V_17 -> V_4 = F_51 ( V_16 -> V_2 . V_4 ) ;
V_17 -> V_45 = F_51 ( V_16 -> V_2 . V_45 ) ;
ASSERT ( V_17 -> V_44 == V_46 ||
V_17 -> V_44 == V_47 ) ;
}
static void
F_52 (
struct V_35 * V_17 ,
struct V_40 * V_16 )
{
ASSERT ( V_16 -> V_44 == V_46 ||
V_16 -> V_44 == V_47 ) ;
V_17 -> V_2 . V_42 . V_41 = F_53 ( V_16 -> V_41 ) ;
V_17 -> V_2 . V_42 . V_43 = F_53 ( V_16 -> V_43 ) ;
V_17 -> V_2 . V_42 . V_44 = F_54 ( V_16 -> V_44 ) ;
V_17 -> V_2 . V_4 = F_54 ( V_16 -> V_4 ) ;
V_17 -> V_2 . V_45 = F_54 ( V_16 -> V_45 ) ;
}
static void
F_55 (
struct V_40 * V_17 ,
struct V_35 * V_16 )
{
struct V_38 * V_48 = (struct V_38 * ) V_16 ;
V_17 -> V_41 = F_50 ( V_48 -> V_42 . V_2 . V_41 ) ;
V_17 -> V_43 = F_50 ( V_48 -> V_42 . V_2 . V_43 ) ;
V_17 -> V_44 = F_51 ( V_48 -> V_42 . V_2 . V_44 ) ;
V_17 -> V_4 = F_51 ( V_48 -> V_4 ) ;
V_17 -> V_45 = F_51 ( V_48 -> V_45 ) ;
ASSERT ( V_17 -> V_44 == V_49 ||
V_17 -> V_44 == V_50 ) ;
}
static void
F_56 (
struct V_35 * V_17 ,
struct V_40 * V_16 )
{
struct V_38 * V_48 = (struct V_38 * ) V_17 ;
ASSERT ( V_16 -> V_44 == V_49 ||
V_16 -> V_44 == V_50 ) ;
V_48 -> V_42 . V_2 . V_41 = F_53 ( V_16 -> V_41 ) ;
V_48 -> V_42 . V_2 . V_43 = F_53 ( V_16 -> V_43 ) ;
V_48 -> V_42 . V_2 . V_44 = F_54 ( V_16 -> V_44 ) ;
V_48 -> V_4 = F_54 ( V_16 -> V_4 ) ;
V_48 -> V_45 = F_54 ( V_16 -> V_45 ) ;
}
static struct V_51 *
F_57 ( struct V_52 * V_53 )
{
return V_53 -> V_54 ;
}
static struct V_51 *
F_58 ( struct V_52 * V_53 )
{
return ( (struct V_55 * ) V_53 ) -> V_54 ;
}
static void
F_59 (
struct V_56 * V_17 ,
struct V_52 * V_16 )
{
ASSERT ( V_16 -> V_2 . V_42 . V_44 == F_54 ( V_57 ) ) ;
V_17 -> V_41 = F_50 ( V_16 -> V_2 . V_42 . V_41 ) ;
V_17 -> V_43 = F_50 ( V_16 -> V_2 . V_42 . V_43 ) ;
V_17 -> V_44 = F_51 ( V_16 -> V_2 . V_42 . V_44 ) ;
V_17 -> V_4 = F_51 ( V_16 -> V_2 . V_58 ) ;
V_17 -> V_59 = F_51 ( V_16 -> V_2 . V_60 ) ;
}
static void
F_60 (
struct V_52 * V_17 ,
struct V_56 * V_16 )
{
ASSERT ( V_16 -> V_44 == V_57 ) ;
V_17 -> V_2 . V_42 . V_41 = F_53 ( V_16 -> V_41 ) ;
V_17 -> V_2 . V_42 . V_43 = F_53 ( V_16 -> V_43 ) ;
V_17 -> V_2 . V_42 . V_44 = F_54 ( V_16 -> V_44 ) ;
V_17 -> V_2 . V_58 = F_54 ( V_16 -> V_4 ) ;
V_17 -> V_2 . V_60 = F_54 ( V_16 -> V_59 ) ;
}
static void
F_61 (
struct V_56 * V_17 ,
struct V_52 * V_16 )
{
struct V_61 * V_48 = (struct V_61 * ) V_16 ;
ASSERT ( V_16 -> V_2 . V_42 . V_44 == F_54 ( V_62 ) ) ;
V_17 -> V_41 = F_50 ( V_48 -> V_42 . V_2 . V_41 ) ;
V_17 -> V_43 = F_50 ( V_48 -> V_42 . V_2 . V_43 ) ;
V_17 -> V_44 = F_51 ( V_48 -> V_42 . V_2 . V_44 ) ;
V_17 -> V_4 = F_51 ( V_48 -> V_58 ) ;
V_17 -> V_59 = F_51 ( V_48 -> V_60 ) ;
}
static void
F_62 (
struct V_52 * V_17 ,
struct V_56 * V_16 )
{
struct V_61 * V_48 = (struct V_61 * ) V_17 ;
ASSERT ( V_16 -> V_44 == V_62 ) ;
V_48 -> V_42 . V_2 . V_41 = F_53 ( V_16 -> V_41 ) ;
V_48 -> V_42 . V_2 . V_43 = F_53 ( V_16 -> V_43 ) ;
V_48 -> V_42 . V_2 . V_44 = F_54 ( V_16 -> V_44 ) ;
V_48 -> V_58 = F_54 ( V_16 -> V_4 ) ;
V_48 -> V_60 = F_54 ( V_16 -> V_59 ) ;
}
static int
F_63 ( struct V_29 * V_30 )
{
return ( V_30 -> V_31 - sizeof( struct V_63 ) ) /
sizeof( V_64 ) ;
}
static T_2 *
F_64 ( struct V_65 * free )
{
return ( T_2 * ) ( ( char * ) free + sizeof( struct V_63 ) ) ;
}
static T_3
F_65 ( struct V_29 * V_30 , T_3 V_66 )
{
return F_66 ( V_30 , V_67 ) +
( V_66 / F_63 ( V_30 ) ) ;
}
static int
F_67 ( struct V_29 * V_30 , T_3 V_66 )
{
return V_66 % F_63 ( V_30 ) ;
}
static int
F_68 ( struct V_29 * V_30 )
{
return ( V_30 -> V_31 - sizeof( struct V_68 ) ) /
sizeof( V_64 ) ;
}
static T_2 *
F_69 ( struct V_65 * free )
{
return ( T_2 * ) ( ( char * ) free + sizeof( struct V_68 ) ) ;
}
static T_3
F_70 ( struct V_29 * V_30 , T_3 V_66 )
{
return F_66 ( V_30 , V_67 ) +
( V_66 / F_68 ( V_30 ) ) ;
}
static int
F_71 ( struct V_29 * V_30 , T_3 V_66 )
{
return V_66 % F_68 ( V_30 ) ;
}
static void
F_72 (
struct V_69 * V_17 ,
struct V_65 * V_16 )
{
V_17 -> V_44 = F_50 ( V_16 -> V_2 . V_44 ) ;
V_17 -> V_70 = F_50 ( V_16 -> V_2 . V_70 ) ;
V_17 -> V_71 = F_50 ( V_16 -> V_2 . V_71 ) ;
V_17 -> V_72 = F_50 ( V_16 -> V_2 . V_72 ) ;
ASSERT ( V_17 -> V_44 == V_73 ) ;
}
static void
F_73 (
struct V_65 * V_17 ,
struct V_69 * V_16 )
{
ASSERT ( V_16 -> V_44 == V_73 ) ;
V_17 -> V_2 . V_44 = F_53 ( V_16 -> V_44 ) ;
V_17 -> V_2 . V_70 = F_53 ( V_16 -> V_70 ) ;
V_17 -> V_2 . V_71 = F_53 ( V_16 -> V_71 ) ;
V_17 -> V_2 . V_72 = F_53 ( V_16 -> V_72 ) ;
}
static void
F_74 (
struct V_69 * V_17 ,
struct V_65 * V_16 )
{
struct V_68 * V_48 = (struct V_68 * ) V_16 ;
V_17 -> V_44 = F_50 ( V_48 -> V_2 . V_44 ) ;
V_17 -> V_70 = F_50 ( V_48 -> V_70 ) ;
V_17 -> V_71 = F_50 ( V_48 -> V_71 ) ;
V_17 -> V_72 = F_50 ( V_48 -> V_72 ) ;
ASSERT ( V_17 -> V_44 == V_74 ) ;
}
static void
F_75 (
struct V_65 * V_17 ,
struct V_69 * V_16 )
{
struct V_68 * V_48 = (struct V_68 * ) V_17 ;
ASSERT ( V_16 -> V_44 == V_74 ) ;
V_48 -> V_2 . V_44 = F_53 ( V_16 -> V_44 ) ;
V_48 -> V_70 = F_53 ( V_16 -> V_70 ) ;
V_48 -> V_71 = F_53 ( V_16 -> V_71 ) ;
V_48 -> V_72 = F_53 ( V_16 -> V_72 ) ;
}
const struct V_75 *
F_76 (
struct V_76 * V_77 ,
struct V_78 * V_79 )
{
if ( V_79 )
return V_79 -> V_80 ;
if ( V_77 -> V_81 )
return V_77 -> V_81 ;
if ( F_77 ( & V_77 -> V_82 ) )
return & V_83 ;
if ( F_78 ( & V_77 -> V_82 ) )
return & V_84 ;
return & V_85 ;
}
const struct V_75 *
F_79 (
struct V_76 * V_77 ,
struct V_78 * V_79 )
{
if ( V_79 )
return V_79 -> V_80 ;
if ( V_77 -> V_86 )
return V_77 -> V_86 ;
if ( F_77 ( & V_77 -> V_82 ) )
return & V_87 ;
return & V_88 ;
}
