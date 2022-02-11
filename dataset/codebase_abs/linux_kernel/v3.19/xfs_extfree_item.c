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
struct V_22 * V_23 = NULL ;
ASSERT ( F_13 ( & V_5 -> V_24 ) ==
V_5 -> V_6 . V_7 ) ;
V_5 -> V_6 . V_25 = V_26 ;
V_5 -> V_6 . V_27 = 1 ;
F_14 ( V_21 , & V_23 , V_28 ,
& V_5 -> V_6 ,
F_10 ( V_5 ) ) ;
}
STATIC void
F_15 (
struct V_2 * V_3 )
{
}
STATIC void
F_16 (
struct V_2 * V_3 ,
int remove )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
if ( remove ) {
ASSERT ( ! ( V_3 -> V_29 & V_30 ) ) ;
if ( V_3 -> V_31 )
F_17 ( V_3 ) ;
F_3 ( V_5 ) ;
return;
}
F_6 ( V_5 ) ;
}
STATIC T_1
F_18 (
struct V_2 * V_3 ,
struct V_32 * V_33 )
{
return V_34 ;
}
STATIC void
F_19 (
struct V_2 * V_3 )
{
if ( V_3 -> V_29 & V_35 )
F_3 ( F_1 ( V_3 ) ) ;
}
STATIC T_2
F_20 (
struct V_2 * V_3 ,
T_2 V_36 )
{
return V_36 ;
}
STATIC void
F_21 (
struct V_2 * V_3 ,
T_2 V_36 )
{
}
struct V_1 *
F_22 (
struct V_37 * V_38 ,
T_1 V_39 )
{
struct V_1 * V_5 ;
T_1 V_40 ;
ASSERT ( V_39 > 0 ) ;
if ( V_39 > V_8 ) {
V_40 = ( T_1 ) ( sizeof( V_41 ) +
( ( V_39 - 1 ) * sizeof( V_17 ) ) ) ;
V_5 = F_23 ( V_40 , V_42 ) ;
} else {
V_5 = F_24 ( V_9 , V_42 ) ;
}
F_25 ( V_38 , & V_5 -> V_4 , V_26 , & V_43 ) ;
V_5 -> V_6 . V_7 = V_39 ;
V_5 -> V_6 . V_44 = ( V_45 ) ( void * ) V_5 ;
F_26 ( & V_5 -> V_24 , 0 ) ;
F_26 ( & V_5 -> V_13 , 2 ) ;
return V_5 ;
}
int
F_27 ( T_3 * V_46 , T_4 * V_47 )
{
T_4 * V_48 = V_46 -> V_49 ;
T_1 V_50 ;
T_1 V_51 = sizeof( T_4 ) +
( V_48 -> V_7 - 1 ) * sizeof( V_17 ) ;
T_1 V_52 = sizeof( V_53 ) +
( V_48 -> V_7 - 1 ) * sizeof( V_54 ) ;
T_1 V_55 = sizeof( V_56 ) +
( V_48 -> V_7 - 1 ) * sizeof( V_57 ) ;
if ( V_46 -> V_58 == V_51 ) {
memcpy ( ( char * ) V_47 , ( char * ) V_48 , V_51 ) ;
return 0 ;
} else if ( V_46 -> V_58 == V_52 ) {
V_53 * V_59 = V_46 -> V_49 ;
V_47 -> V_25 = V_59 -> V_25 ;
V_47 -> V_27 = V_59 -> V_27 ;
V_47 -> V_7 = V_59 -> V_7 ;
V_47 -> V_44 = V_59 -> V_44 ;
for ( V_50 = 0 ; V_50 < V_47 -> V_7 ; V_50 ++ ) {
V_47 -> V_60 [ V_50 ] . V_61 =
V_59 -> V_60 [ V_50 ] . V_61 ;
V_47 -> V_60 [ V_50 ] . V_62 =
V_59 -> V_60 [ V_50 ] . V_62 ;
}
return 0 ;
} else if ( V_46 -> V_58 == V_55 ) {
V_56 * V_63 = V_46 -> V_49 ;
V_47 -> V_25 = V_63 -> V_25 ;
V_47 -> V_27 = V_63 -> V_27 ;
V_47 -> V_7 = V_63 -> V_7 ;
V_47 -> V_44 = V_63 -> V_44 ;
for ( V_50 = 0 ; V_50 < V_47 -> V_7 ; V_50 ++ ) {
V_47 -> V_60 [ V_50 ] . V_61 =
V_63 -> V_60 [ V_50 ] . V_61 ;
V_47 -> V_60 [ V_50 ] . V_62 =
V_63 -> V_60 [ V_50 ] . V_62 ;
}
return 0 ;
}
return - V_64 ;
}
void
F_28 ( V_41 * V_5 ,
T_1 V_39 )
{
ASSERT ( F_13 ( & V_5 -> V_24 ) >= V_39 ) ;
if ( F_29 ( V_39 , & V_5 -> V_24 ) ) {
if ( F_30 ( V_65 , & V_5 -> V_66 ) )
F_6 ( V_5 ) ;
F_6 ( V_5 ) ;
}
}
static inline struct V_67 * F_31 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_67 , V_68 ) ;
}
STATIC void
F_32 ( struct V_67 * V_69 )
{
if ( V_69 -> V_70 . V_71 > V_72 )
F_4 ( V_69 ) ;
else
F_5 ( V_73 , V_69 ) ;
}
static inline int
F_33 (
struct V_67 * V_69 )
{
return sizeof( V_74 ) +
( V_69 -> V_70 . V_71 - 1 ) * sizeof( V_17 ) ;
}
STATIC void
F_34 (
struct V_2 * V_3 ,
int * V_18 ,
int * V_19 )
{
* V_18 += 1 ;
* V_19 += F_33 ( F_31 ( V_3 ) ) ;
}
STATIC void
F_35 (
struct V_2 * V_3 ,
struct V_20 * V_21 )
{
struct V_67 * V_69 = F_31 ( V_3 ) ;
struct V_22 * V_23 = NULL ;
ASSERT ( V_69 -> V_75 == V_69 -> V_70 . V_71 ) ;
V_69 -> V_70 . V_76 = V_77 ;
V_69 -> V_70 . V_78 = 1 ;
F_14 ( V_21 , & V_23 , V_79 ,
& V_69 -> V_70 ,
F_33 ( V_69 ) ) ;
}
STATIC void
F_36 (
struct V_2 * V_3 )
{
}
STATIC void
F_37 (
struct V_2 * V_3 ,
int remove )
{
}
STATIC T_1
F_38 (
struct V_2 * V_3 ,
struct V_32 * V_33 )
{
return V_34 ;
}
STATIC void
F_39 (
struct V_2 * V_3 )
{
if ( V_3 -> V_29 & V_35 )
F_32 ( F_31 ( V_3 ) ) ;
}
STATIC T_2
F_40 (
struct V_2 * V_3 ,
T_2 V_36 )
{
struct V_67 * V_69 = F_31 ( V_3 ) ;
if ( ! ( V_3 -> V_29 & V_35 ) )
F_28 ( V_69 -> V_80 , V_69 -> V_70 . V_71 ) ;
F_32 ( V_69 ) ;
return ( T_2 ) - 1 ;
}
STATIC void
F_41 (
struct V_2 * V_3 ,
T_2 V_36 )
{
}
struct V_67 *
F_42 (
struct V_37 * V_38 ,
struct V_1 * V_5 ,
T_1 V_39 )
{
struct V_67 * V_69 ;
T_1 V_40 ;
ASSERT ( V_39 > 0 ) ;
if ( V_39 > V_72 ) {
V_40 = ( T_1 ) ( sizeof( V_81 ) +
( ( V_39 - 1 ) * sizeof( V_17 ) ) ) ;
V_69 = F_23 ( V_40 , V_42 ) ;
} else {
V_69 = F_24 ( V_73 , V_42 ) ;
}
F_25 ( V_38 , & V_69 -> V_68 , V_77 , & V_82 ) ;
V_69 -> V_80 = V_5 ;
V_69 -> V_70 . V_71 = V_39 ;
V_69 -> V_70 . V_83 = V_5 -> V_6 . V_44 ;
return V_69 ;
}
