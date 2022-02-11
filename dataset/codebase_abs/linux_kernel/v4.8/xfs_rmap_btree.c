static struct V_1 *
F_1 (
struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_3 , V_2 -> V_4 ,
V_2 -> V_5 . V_6 . V_7 , V_2 -> V_5 . V_6 . V_8 ) ;
}
STATIC void
F_3 (
struct V_1 * V_2 ,
union V_9 * V_10 ,
int V_11 )
{
struct V_12 * V_7 = V_2 -> V_5 . V_6 . V_7 ;
struct V_13 * V_14 = F_4 ( V_7 ) ;
T_1 V_15 = F_5 ( V_14 -> V_16 ) ;
int V_17 = V_2 -> V_18 ;
struct V_19 * V_20 = F_6 ( V_2 -> V_3 , V_15 ) ;
ASSERT ( V_10 -> V_21 != 0 ) ;
V_14 -> V_22 [ V_17 ] = V_10 -> V_21 ;
F_7 ( & V_14 -> V_23 [ V_17 ] , V_11 ) ;
V_20 -> V_24 [ V_17 ] += V_11 ;
F_8 ( V_20 ) ;
F_9 ( V_2 -> V_4 , V_7 , V_25 | V_26 ) ;
}
STATIC int
F_10 (
struct V_1 * V_2 ,
union V_9 * V_27 ,
union V_9 * V_28 ,
int * V_29 )
{
struct V_12 * V_7 = V_2 -> V_5 . V_6 . V_7 ;
struct V_13 * V_14 = F_4 ( V_7 ) ;
int error ;
T_2 V_30 ;
F_11 ( V_2 , V_31 ) ;
error = F_12 ( V_2 -> V_4 , V_2 -> V_5 . V_6 . V_7 ,
& V_30 , 1 ) ;
if ( error ) {
F_11 ( V_2 , V_32 ) ;
return error ;
}
F_13 ( V_2 -> V_3 , V_2 -> V_5 . V_6 . V_8 ,
V_30 , 1 ) ;
if ( V_30 == V_33 ) {
F_11 ( V_2 , V_34 ) ;
* V_29 = 0 ;
return 0 ;
}
F_14 ( V_2 -> V_3 , V_2 -> V_5 . V_6 . V_8 , V_30 , 1 ,
false ) ;
F_15 ( V_2 -> V_4 , 1 ) ;
V_28 -> V_21 = F_16 ( V_30 ) ;
F_7 ( & V_14 -> V_35 , 1 ) ;
F_9 ( V_2 -> V_4 , V_7 , V_36 ) ;
F_11 ( V_2 , V_34 ) ;
* V_29 = 1 ;
return 0 ;
}
STATIC int
F_17 (
struct V_1 * V_2 ,
struct V_12 * V_37 )
{
struct V_12 * V_7 = V_2 -> V_5 . V_6 . V_7 ;
struct V_13 * V_14 = F_4 ( V_7 ) ;
T_2 V_30 ;
int error ;
V_30 = F_18 ( V_2 -> V_3 , F_19 ( V_37 ) ) ;
F_20 ( V_2 -> V_3 , V_2 -> V_5 . V_6 . V_8 ,
V_30 , 1 ) ;
F_7 ( & V_14 -> V_35 , - 1 ) ;
F_9 ( V_2 -> V_4 , V_7 , V_36 ) ;
error = F_21 ( V_2 -> V_4 , V_7 , NULL , V_30 , 1 ) ;
if ( error )
return error ;
F_22 ( V_2 -> V_4 , F_5 ( V_14 -> V_16 ) , V_30 , 1 ,
V_38 ) ;
F_15 ( V_2 -> V_4 , - 1 ) ;
return 0 ;
}
STATIC int
F_23 (
struct V_1 * V_2 ,
int V_39 )
{
return V_2 -> V_3 -> V_40 [ V_39 != 0 ] ;
}
STATIC int
F_24 (
struct V_1 * V_2 ,
int V_39 )
{
return V_2 -> V_3 -> V_41 [ V_39 != 0 ] ;
}
STATIC void
F_25 (
union V_42 * V_43 ,
union V_44 * V_45 )
{
V_43 -> V_46 . V_47 = V_45 -> V_46 . V_47 ;
V_43 -> V_46 . V_48 = V_45 -> V_46 . V_48 ;
V_43 -> V_46 . V_49 = V_45 -> V_46 . V_49 ;
}
STATIC void
F_26 (
union V_42 * V_43 ,
union V_44 * V_45 )
{
T_3 V_50 ;
int V_51 ;
V_51 = F_5 ( V_45 -> V_46 . V_52 ) - 1 ;
V_43 -> V_46 . V_47 = V_45 -> V_46 . V_47 ;
F_7 ( & V_43 -> V_46 . V_47 , V_51 ) ;
V_43 -> V_46 . V_48 = V_45 -> V_46 . V_48 ;
V_43 -> V_46 . V_49 = V_45 -> V_46 . V_49 ;
if ( F_27 ( F_28 ( V_45 -> V_46 . V_48 ) ) ||
F_29 ( F_28 ( V_45 -> V_46 . V_49 ) ) )
return;
V_50 = F_28 ( V_43 -> V_46 . V_49 ) ;
V_50 = ( F_30 ( V_50 ) + V_51 ) | ( V_50 & ~ V_53 ) ;
V_43 -> V_46 . V_49 = F_31 ( V_50 ) ;
}
STATIC void
F_32 (
struct V_1 * V_2 ,
union V_44 * V_45 )
{
V_45 -> V_46 . V_47 = F_16 ( V_2 -> V_54 . V_55 . V_47 ) ;
V_45 -> V_46 . V_52 = F_16 ( V_2 -> V_54 . V_55 . V_52 ) ;
V_45 -> V_46 . V_48 = F_31 ( V_2 -> V_54 . V_55 . V_48 ) ;
V_45 -> V_46 . V_49 = F_31 (
F_33 ( & V_2 -> V_54 . V_55 ) ) ;
}
STATIC void
F_34 (
struct V_1 * V_2 ,
union V_9 * V_10 )
{
struct V_13 * V_14 = F_4 ( V_2 -> V_5 . V_6 . V_7 ) ;
ASSERT ( V_2 -> V_5 . V_6 . V_8 == F_5 ( V_14 -> V_16 ) ) ;
ASSERT ( V_14 -> V_22 [ V_2 -> V_18 ] != 0 ) ;
V_10 -> V_21 = V_14 -> V_22 [ V_2 -> V_18 ] ;
}
STATIC T_4
F_35 (
struct V_1 * V_2 ,
union V_42 * V_43 )
{
struct V_56 * V_45 = & V_2 -> V_54 . V_55 ;
struct V_57 * V_58 = & V_43 -> V_46 ;
T_5 V_59 , V_60 ;
T_4 V_61 ;
V_61 = ( T_4 ) F_5 ( V_58 -> V_47 ) - V_45 -> V_47 ;
if ( V_61 )
return V_61 ;
V_59 = F_28 ( V_58 -> V_48 ) ;
V_60 = V_45 -> V_48 ;
if ( V_59 > V_60 )
return 1 ;
else if ( V_60 > V_59 )
return - 1 ;
V_59 = F_30 ( F_28 ( V_58 -> V_49 ) ) ;
V_60 = V_45 -> V_49 ;
if ( V_59 > V_60 )
return 1 ;
else if ( V_60 > V_59 )
return - 1 ;
return 0 ;
}
STATIC T_4
F_36 (
struct V_1 * V_2 ,
union V_42 * V_62 ,
union V_42 * V_63 )
{
struct V_57 * V_64 = & V_62 -> V_46 ;
struct V_57 * V_65 = & V_63 -> V_46 ;
T_4 V_61 ;
T_5 V_59 , V_60 ;
V_61 = ( T_4 ) F_5 ( V_64 -> V_47 ) -
F_5 ( V_65 -> V_47 ) ;
if ( V_61 )
return V_61 ;
V_59 = F_28 ( V_64 -> V_48 ) ;
V_60 = F_28 ( V_65 -> V_48 ) ;
if ( V_59 > V_60 )
return 1 ;
else if ( V_60 > V_59 )
return - 1 ;
V_59 = F_30 ( F_28 ( V_64 -> V_49 ) ) ;
V_60 = F_30 ( F_28 ( V_65 -> V_49 ) ) ;
if ( V_59 > V_60 )
return 1 ;
else if ( V_60 > V_59 )
return - 1 ;
return 0 ;
}
static bool
F_37 (
struct V_12 * V_37 )
{
struct V_66 * V_67 = V_37 -> V_68 -> V_69 ;
struct V_70 * V_71 = F_38 ( V_37 ) ;
struct V_19 * V_20 = V_37 -> V_72 ;
unsigned int V_39 ;
if ( V_71 -> V_73 != F_16 ( V_74 ) )
return false ;
if ( ! F_39 ( & V_67 -> V_75 ) )
return false ;
if ( ! F_40 ( V_37 ) )
return false ;
V_39 = F_41 ( V_71 -> V_76 ) ;
if ( V_20 && V_20 -> V_77 ) {
if ( V_39 >= V_20 -> V_24 [ V_78 ] )
return false ;
} else if ( V_39 >= V_67 -> V_79 )
return false ;
return F_42 ( V_37 , V_67 -> V_41 [ V_39 != 0 ] ) ;
}
static void
F_43 (
struct V_12 * V_37 )
{
if ( ! F_44 ( V_37 ) )
F_45 ( V_37 , - V_80 ) ;
else if ( ! F_37 ( V_37 ) )
F_45 ( V_37 , - V_81 ) ;
if ( V_37 -> V_82 ) {
F_46 ( V_37 , V_83 ) ;
F_47 ( V_37 ) ;
}
}
static void
F_48 (
struct V_12 * V_37 )
{
if ( ! F_37 ( V_37 ) ) {
F_46 ( V_37 , V_83 ) ;
F_45 ( V_37 , - V_81 ) ;
F_47 ( V_37 ) ;
return;
}
F_49 ( V_37 ) ;
}
STATIC int
F_50 (
struct V_1 * V_2 ,
union V_42 * V_62 ,
union V_42 * V_63 )
{
T_6 V_59 ;
T_6 V_60 ;
T_3 V_6 ;
T_3 V_84 ;
V_59 = F_5 ( V_62 -> V_46 . V_47 ) ;
V_60 = F_5 ( V_63 -> V_46 . V_47 ) ;
if ( V_59 < V_60 )
return 1 ;
else if ( V_59 > V_60 )
return 0 ;
V_6 = F_28 ( V_62 -> V_46 . V_48 ) ;
V_84 = F_28 ( V_63 -> V_46 . V_48 ) ;
if ( V_6 < V_84 )
return 1 ;
else if ( V_6 > V_84 )
return 0 ;
V_6 = F_30 ( F_28 ( V_62 -> V_46 . V_49 ) ) ;
V_84 = F_30 ( F_28 ( V_63 -> V_46 . V_49 ) ) ;
if ( V_6 <= V_84 )
return 1 ;
return 0 ;
}
STATIC int
F_51 (
struct V_1 * V_2 ,
union V_44 * V_85 ,
union V_44 * V_86 )
{
T_6 V_59 ;
T_6 V_60 ;
T_3 V_6 ;
T_3 V_84 ;
V_59 = F_5 ( V_85 -> V_46 . V_47 ) ;
V_60 = F_5 ( V_86 -> V_46 . V_47 ) ;
if ( V_59 < V_60 )
return 1 ;
else if ( V_59 > V_60 )
return 0 ;
V_6 = F_28 ( V_85 -> V_46 . V_48 ) ;
V_84 = F_28 ( V_86 -> V_46 . V_48 ) ;
if ( V_6 < V_84 )
return 1 ;
else if ( V_6 > V_84 )
return 0 ;
V_6 = F_30 ( F_28 ( V_85 -> V_46 . V_49 ) ) ;
V_84 = F_30 ( F_28 ( V_86 -> V_46 . V_49 ) ) ;
if ( V_6 <= V_84 )
return 1 ;
return 0 ;
}
struct V_1 *
F_2 (
struct V_66 * V_67 ,
struct V_87 * V_88 ,
struct V_12 * V_7 ,
T_1 V_8 )
{
struct V_13 * V_14 = F_4 ( V_7 ) ;
struct V_1 * V_2 ;
V_2 = F_52 ( V_89 , V_90 ) ;
V_2 -> V_4 = V_88 ;
V_2 -> V_3 = V_67 ;
V_2 -> V_18 = V_91 ;
V_2 -> V_92 = V_93 | V_94 ;
V_2 -> V_95 = V_67 -> V_75 . V_96 ;
V_2 -> V_97 = & V_98 ;
V_2 -> V_99 = F_5 ( V_14 -> V_23 [ V_91 ] ) ;
V_2 -> V_5 . V_6 . V_7 = V_7 ;
V_2 -> V_5 . V_6 . V_8 = V_8 ;
return V_2 ;
}
int
F_53 (
struct V_66 * V_67 ,
int V_100 ,
int V_101 )
{
V_100 -= V_102 ;
if ( V_101 )
return V_100 / sizeof( struct V_103 ) ;
return V_100 /
( 2 * sizeof( struct V_57 ) + sizeof( V_104 ) ) ;
}
void
F_54 (
struct V_66 * V_67 )
{
V_67 -> V_79 = F_55 ( V_67 ,
V_67 -> V_40 , V_67 -> V_75 . V_105 ) ;
}
