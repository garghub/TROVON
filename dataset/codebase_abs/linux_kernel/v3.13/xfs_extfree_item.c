static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
void
F_3 (
struct V_1 * V_5 )
{
if ( V_5 -> V_6 . V_7 > V_8 )
F_4 ( V_5 ) ;
else
F_5 ( V_9 , V_5 ) ;
}
STATIC void
F_6 (
struct V_1 * V_5 )
{
struct V_10 * V_11 = V_5 -> V_4 . V_12 ;
if ( F_7 ( & V_5 -> V_13 ) ) {
F_8 ( & V_11 -> V_14 ) ;
F_9 ( V_11 , & V_5 -> V_4 ,
V_15 ) ;
F_3 ( V_5 ) ;
}
}
static inline int
F_10 (
struct V_1 * V_5 )
{
return sizeof( struct V_16 ) +
( V_5 -> V_6 . V_7 - 1 ) * sizeof( V_17 ) ;
}
STATIC void
F_11 (
struct V_2 * V_3 ,
int * V_18 ,
int * V_19 )
{
* V_18 += 1 ;
* V_19 += F_10 ( F_1 ( V_3 ) ) ;
}
STATIC void
F_12 (
struct V_2 * V_3 ,
struct V_20 * V_21 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
ASSERT ( F_13 ( & V_5 -> V_22 ) ==
V_5 -> V_6 . V_7 ) ;
V_5 -> V_6 . V_23 = V_24 ;
V_5 -> V_6 . V_25 = 1 ;
V_21 -> V_26 = & V_5 -> V_6 ;
V_21 -> V_27 = F_10 ( V_5 ) ;
V_21 -> V_28 = V_29 ;
ASSERT ( V_21 -> V_27 >= sizeof( V_30 ) ) ;
}
STATIC void
F_14 (
struct V_2 * V_3 )
{
}
STATIC void
F_15 (
struct V_2 * V_3 ,
int remove )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
if ( remove ) {
ASSERT ( ! ( V_3 -> V_31 & V_32 ) ) ;
if ( V_3 -> V_33 )
F_16 ( V_3 ) ;
F_3 ( V_5 ) ;
return;
}
F_6 ( V_5 ) ;
}
STATIC T_1
F_17 (
struct V_2 * V_3 ,
struct V_34 * V_35 )
{
return V_36 ;
}
STATIC void
F_18 (
struct V_2 * V_3 )
{
if ( V_3 -> V_31 & V_37 )
F_3 ( F_1 ( V_3 ) ) ;
}
STATIC T_2
F_19 (
struct V_2 * V_3 ,
T_2 V_38 )
{
return V_38 ;
}
STATIC void
F_20 (
struct V_2 * V_3 ,
T_2 V_38 )
{
}
struct V_1 *
F_21 (
struct V_39 * V_40 ,
T_1 V_41 )
{
struct V_1 * V_5 ;
T_1 V_42 ;
ASSERT ( V_41 > 0 ) ;
if ( V_41 > V_8 ) {
V_42 = ( T_1 ) ( sizeof( V_43 ) +
( ( V_41 - 1 ) * sizeof( V_17 ) ) ) ;
V_5 = F_22 ( V_42 , V_44 ) ;
} else {
V_5 = F_23 ( V_9 , V_44 ) ;
}
F_24 ( V_40 , & V_5 -> V_4 , V_24 , & V_45 ) ;
V_5 -> V_6 . V_7 = V_41 ;
V_5 -> V_6 . V_46 = ( V_47 ) ( void * ) V_5 ;
F_25 ( & V_5 -> V_22 , 0 ) ;
F_25 ( & V_5 -> V_13 , 2 ) ;
return V_5 ;
}
int
F_26 ( T_3 * V_48 , V_30 * V_49 )
{
V_30 * V_50 = V_48 -> V_26 ;
T_1 V_51 ;
T_1 V_52 = sizeof( V_30 ) +
( V_50 -> V_7 - 1 ) * sizeof( V_17 ) ;
T_1 V_53 = sizeof( V_54 ) +
( V_50 -> V_7 - 1 ) * sizeof( V_55 ) ;
T_1 V_56 = sizeof( V_57 ) +
( V_50 -> V_7 - 1 ) * sizeof( V_58 ) ;
if ( V_48 -> V_27 == V_52 ) {
memcpy ( ( char * ) V_49 , ( char * ) V_50 , V_52 ) ;
return 0 ;
} else if ( V_48 -> V_27 == V_53 ) {
V_54 * V_59 = V_48 -> V_26 ;
V_49 -> V_23 = V_59 -> V_23 ;
V_49 -> V_25 = V_59 -> V_25 ;
V_49 -> V_7 = V_59 -> V_7 ;
V_49 -> V_46 = V_59 -> V_46 ;
for ( V_51 = 0 ; V_51 < V_49 -> V_7 ; V_51 ++ ) {
V_49 -> V_60 [ V_51 ] . V_61 =
V_59 -> V_60 [ V_51 ] . V_61 ;
V_49 -> V_60 [ V_51 ] . V_62 =
V_59 -> V_60 [ V_51 ] . V_62 ;
}
return 0 ;
} else if ( V_48 -> V_27 == V_56 ) {
V_57 * V_63 = V_48 -> V_26 ;
V_49 -> V_23 = V_63 -> V_23 ;
V_49 -> V_25 = V_63 -> V_25 ;
V_49 -> V_7 = V_63 -> V_7 ;
V_49 -> V_46 = V_63 -> V_46 ;
for ( V_51 = 0 ; V_51 < V_49 -> V_7 ; V_51 ++ ) {
V_49 -> V_60 [ V_51 ] . V_61 =
V_63 -> V_60 [ V_51 ] . V_61 ;
V_49 -> V_60 [ V_51 ] . V_62 =
V_63 -> V_60 [ V_51 ] . V_62 ;
}
return 0 ;
}
return V_64 ;
}
void
F_27 ( V_43 * V_5 ,
T_1 V_41 )
{
ASSERT ( F_13 ( & V_5 -> V_22 ) >= V_41 ) ;
if ( F_28 ( V_41 , & V_5 -> V_22 ) ) {
if ( F_29 ( V_65 , & V_5 -> V_66 ) )
F_6 ( V_5 ) ;
F_6 ( V_5 ) ;
}
}
static inline struct V_67 * F_30 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_67 , V_68 ) ;
}
STATIC void
F_31 ( struct V_67 * V_69 )
{
if ( V_69 -> V_70 . V_71 > V_72 )
F_4 ( V_69 ) ;
else
F_5 ( V_73 , V_69 ) ;
}
static inline int
F_32 (
struct V_67 * V_69 )
{
return sizeof( V_74 ) +
( V_69 -> V_70 . V_71 - 1 ) * sizeof( V_17 ) ;
}
STATIC void
F_33 (
struct V_2 * V_3 ,
int * V_18 ,
int * V_19 )
{
* V_18 += 1 ;
* V_19 += F_32 ( F_30 ( V_3 ) ) ;
}
STATIC void
F_34 (
struct V_2 * V_3 ,
struct V_20 * V_21 )
{
struct V_67 * V_69 = F_30 ( V_3 ) ;
ASSERT ( V_69 -> V_75 == V_69 -> V_70 . V_71 ) ;
V_69 -> V_70 . V_76 = V_77 ;
V_69 -> V_70 . V_78 = 1 ;
V_21 -> V_26 = & V_69 -> V_70 ;
V_21 -> V_27 = F_32 ( V_69 ) ;
V_21 -> V_28 = V_79 ;
ASSERT ( V_21 -> V_27 >= sizeof( V_74 ) ) ;
}
STATIC void
F_35 (
struct V_2 * V_3 )
{
}
STATIC void
F_36 (
struct V_2 * V_3 ,
int remove )
{
}
STATIC T_1
F_37 (
struct V_2 * V_3 ,
struct V_34 * V_35 )
{
return V_36 ;
}
STATIC void
F_38 (
struct V_2 * V_3 )
{
if ( V_3 -> V_31 & V_37 )
F_31 ( F_30 ( V_3 ) ) ;
}
STATIC T_2
F_39 (
struct V_2 * V_3 ,
T_2 V_38 )
{
struct V_67 * V_69 = F_30 ( V_3 ) ;
if ( ! ( V_3 -> V_31 & V_37 ) )
F_27 ( V_69 -> V_80 , V_69 -> V_70 . V_71 ) ;
F_31 ( V_69 ) ;
return ( T_2 ) - 1 ;
}
STATIC void
F_40 (
struct V_2 * V_3 ,
T_2 V_38 )
{
}
struct V_67 *
F_41 (
struct V_39 * V_40 ,
struct V_1 * V_5 ,
T_1 V_41 )
{
struct V_67 * V_69 ;
T_1 V_42 ;
ASSERT ( V_41 > 0 ) ;
if ( V_41 > V_72 ) {
V_42 = ( T_1 ) ( sizeof( V_81 ) +
( ( V_41 - 1 ) * sizeof( V_17 ) ) ) ;
V_69 = F_22 ( V_42 , V_44 ) ;
} else {
V_69 = F_23 ( V_73 , V_44 ) ;
}
F_24 ( V_40 , & V_69 -> V_68 , V_77 , & V_82 ) ;
V_69 -> V_80 = V_5 ;
V_69 -> V_70 . V_71 = V_41 ;
V_69 -> V_70 . V_83 = V_5 -> V_6 . V_46 ;
return V_69 ;
}
