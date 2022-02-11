static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
void
F_3 (
struct V_1 * V_5 )
{
F_4 ( V_5 -> V_4 . V_6 ) ;
if ( V_5 -> V_7 . V_8 > V_9 )
F_4 ( V_5 ) ;
else
F_5 ( V_10 , V_5 ) ;
}
static inline int
F_6 (
struct V_1 * V_5 )
{
return sizeof( struct V_11 ) +
( V_5 -> V_7 . V_8 - 1 ) * sizeof( V_12 ) ;
}
STATIC void
F_7 (
struct V_2 * V_3 ,
int * V_13 ,
int * V_14 )
{
* V_13 += 1 ;
* V_14 += F_6 ( F_1 ( V_3 ) ) ;
}
STATIC void
F_8 (
struct V_2 * V_3 ,
struct V_15 * V_16 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_17 * V_18 = NULL ;
ASSERT ( F_9 ( & V_5 -> V_19 ) ==
V_5 -> V_7 . V_8 ) ;
V_5 -> V_7 . V_20 = V_21 ;
V_5 -> V_7 . V_22 = 1 ;
F_10 ( V_16 , & V_18 , V_23 ,
& V_5 -> V_7 ,
F_6 ( V_5 ) ) ;
}
STATIC void
F_11 (
struct V_2 * V_3 )
{
}
STATIC void
F_12 (
struct V_2 * V_3 ,
int remove )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
F_13 ( V_5 ) ;
}
STATIC T_1
F_14 (
struct V_2 * V_3 ,
struct V_24 * V_25 )
{
return V_26 ;
}
STATIC void
F_15 (
struct V_2 * V_3 )
{
if ( V_3 -> V_27 & V_28 )
F_3 ( F_1 ( V_3 ) ) ;
}
STATIC T_2
F_16 (
struct V_2 * V_3 ,
T_2 V_29 )
{
return V_29 ;
}
STATIC void
F_17 (
struct V_2 * V_3 ,
T_2 V_29 )
{
}
struct V_1 *
F_18 (
struct V_30 * V_31 ,
T_1 V_32 )
{
struct V_1 * V_5 ;
T_1 V_33 ;
ASSERT ( V_32 > 0 ) ;
if ( V_32 > V_9 ) {
V_33 = ( T_1 ) ( sizeof( V_34 ) +
( ( V_32 - 1 ) * sizeof( V_12 ) ) ) ;
V_5 = F_19 ( V_33 , V_35 ) ;
} else {
V_5 = F_20 ( V_10 , V_35 ) ;
}
F_21 ( V_31 , & V_5 -> V_4 , V_21 , & V_36 ) ;
V_5 -> V_7 . V_8 = V_32 ;
V_5 -> V_7 . V_37 = ( V_38 ) ( void * ) V_5 ;
F_22 ( & V_5 -> V_19 , 0 ) ;
F_22 ( & V_5 -> V_39 , 2 ) ;
return V_5 ;
}
int
F_23 ( T_3 * V_40 , T_4 * V_41 )
{
T_4 * V_42 = V_40 -> V_43 ;
T_1 V_44 ;
T_1 V_45 = sizeof( T_4 ) +
( V_42 -> V_8 - 1 ) * sizeof( V_12 ) ;
T_1 V_46 = sizeof( V_47 ) +
( V_42 -> V_8 - 1 ) * sizeof( V_48 ) ;
T_1 V_49 = sizeof( V_50 ) +
( V_42 -> V_8 - 1 ) * sizeof( V_51 ) ;
if ( V_40 -> V_52 == V_45 ) {
memcpy ( ( char * ) V_41 , ( char * ) V_42 , V_45 ) ;
return 0 ;
} else if ( V_40 -> V_52 == V_46 ) {
V_47 * V_53 = V_40 -> V_43 ;
V_41 -> V_20 = V_53 -> V_20 ;
V_41 -> V_22 = V_53 -> V_22 ;
V_41 -> V_8 = V_53 -> V_8 ;
V_41 -> V_37 = V_53 -> V_37 ;
for ( V_44 = 0 ; V_44 < V_41 -> V_8 ; V_44 ++ ) {
V_41 -> V_54 [ V_44 ] . V_55 =
V_53 -> V_54 [ V_44 ] . V_55 ;
V_41 -> V_54 [ V_44 ] . V_56 =
V_53 -> V_54 [ V_44 ] . V_56 ;
}
return 0 ;
} else if ( V_40 -> V_52 == V_49 ) {
V_50 * V_57 = V_40 -> V_43 ;
V_41 -> V_20 = V_57 -> V_20 ;
V_41 -> V_22 = V_57 -> V_22 ;
V_41 -> V_8 = V_57 -> V_8 ;
V_41 -> V_37 = V_57 -> V_37 ;
for ( V_44 = 0 ; V_44 < V_41 -> V_8 ; V_44 ++ ) {
V_41 -> V_54 [ V_44 ] . V_55 =
V_57 -> V_54 [ V_44 ] . V_55 ;
V_41 -> V_54 [ V_44 ] . V_56 =
V_57 -> V_54 [ V_44 ] . V_56 ;
}
return 0 ;
}
return - V_58 ;
}
void
F_13 (
struct V_1 * V_5 )
{
if ( F_24 ( & V_5 -> V_39 ) ) {
F_25 ( & V_5 -> V_4 , V_59 ) ;
F_3 ( V_5 ) ;
}
}
static inline struct V_60 * F_26 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_60 , V_61 ) ;
}
STATIC void
F_27 ( struct V_60 * V_62 )
{
F_4 ( V_62 -> V_61 . V_6 ) ;
if ( V_62 -> V_63 . V_64 > V_65 )
F_4 ( V_62 ) ;
else
F_5 ( V_66 , V_62 ) ;
}
static inline int
F_28 (
struct V_60 * V_62 )
{
return sizeof( V_67 ) +
( V_62 -> V_63 . V_64 - 1 ) * sizeof( V_12 ) ;
}
STATIC void
F_29 (
struct V_2 * V_3 ,
int * V_13 ,
int * V_14 )
{
* V_13 += 1 ;
* V_14 += F_28 ( F_26 ( V_3 ) ) ;
}
STATIC void
F_30 (
struct V_2 * V_3 ,
struct V_15 * V_16 )
{
struct V_60 * V_62 = F_26 ( V_3 ) ;
struct V_17 * V_18 = NULL ;
ASSERT ( V_62 -> V_68 == V_62 -> V_63 . V_64 ) ;
V_62 -> V_63 . V_69 = V_70 ;
V_62 -> V_63 . V_71 = 1 ;
F_10 ( V_16 , & V_18 , V_72 ,
& V_62 -> V_63 ,
F_28 ( V_62 ) ) ;
}
STATIC void
F_31 (
struct V_2 * V_3 )
{
}
STATIC void
F_32 (
struct V_2 * V_3 ,
int remove )
{
}
STATIC T_1
F_33 (
struct V_2 * V_3 ,
struct V_24 * V_25 )
{
return V_26 ;
}
STATIC void
F_34 (
struct V_2 * V_3 )
{
struct V_60 * V_62 = F_26 ( V_3 ) ;
if ( V_3 -> V_27 & V_28 ) {
F_13 ( V_62 -> V_73 ) ;
F_27 ( V_62 ) ;
}
}
STATIC T_2
F_35 (
struct V_2 * V_3 ,
T_2 V_29 )
{
struct V_60 * V_62 = F_26 ( V_3 ) ;
F_13 ( V_62 -> V_73 ) ;
F_27 ( V_62 ) ;
return ( T_2 ) - 1 ;
}
STATIC void
F_36 (
struct V_2 * V_3 ,
T_2 V_29 )
{
}
struct V_60 *
F_37 (
struct V_30 * V_31 ,
struct V_1 * V_5 ,
T_1 V_32 )
{
struct V_60 * V_62 ;
T_1 V_33 ;
ASSERT ( V_32 > 0 ) ;
if ( V_32 > V_65 ) {
V_33 = ( T_1 ) ( sizeof( V_74 ) +
( ( V_32 - 1 ) * sizeof( V_12 ) ) ) ;
V_62 = F_19 ( V_33 , V_35 ) ;
} else {
V_62 = F_20 ( V_66 , V_35 ) ;
}
F_21 ( V_31 , & V_62 -> V_61 , V_70 , & V_75 ) ;
V_62 -> V_73 = V_5 ;
V_62 -> V_63 . V_64 = V_32 ;
V_62 -> V_63 . V_76 = V_5 -> V_7 . V_37 ;
return V_62 ;
}
int
F_38 (
struct V_30 * V_31 ,
struct V_1 * V_5 )
{
struct V_60 * V_62 ;
struct V_77 * V_78 ;
int V_44 ;
int error = 0 ;
V_12 * V_79 ;
T_5 V_80 ;
struct V_81 V_82 ;
ASSERT ( ! F_39 ( V_83 , & V_5 -> V_84 ) ) ;
for ( V_44 = 0 ; V_44 < V_5 -> V_7 . V_8 ; V_44 ++ ) {
V_79 = & V_5 -> V_7 . V_54 [ V_44 ] ;
V_80 = F_40 ( V_31 ,
F_41 ( V_31 , V_79 -> V_55 ) ) ;
if ( V_80 == 0 ||
V_79 -> V_56 == 0 ||
V_80 >= V_31 -> V_85 . V_86 ||
V_79 -> V_56 >= V_31 -> V_85 . V_87 ) {
F_42 ( V_83 , & V_5 -> V_84 ) ;
F_13 ( V_5 ) ;
return - V_88 ;
}
}
error = F_43 ( V_31 , & F_44 ( V_31 ) -> V_89 , 0 , 0 , 0 , & V_78 ) ;
if ( error )
return error ;
V_62 = F_45 ( V_78 , V_5 , V_5 -> V_7 . V_8 ) ;
F_46 ( & V_82 ) ;
for ( V_44 = 0 ; V_44 < V_5 -> V_7 . V_8 ; V_44 ++ ) {
V_79 = & V_5 -> V_7 . V_54 [ V_44 ] ;
error = F_47 ( V_78 , V_62 , V_79 -> V_55 ,
V_79 -> V_56 , & V_82 ) ;
if ( error )
goto V_90;
}
F_42 ( V_83 , & V_5 -> V_84 ) ;
error = F_48 ( V_78 ) ;
return error ;
V_90:
F_49 ( V_78 ) ;
return error ;
}
