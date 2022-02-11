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
static inline int
F_6 (
struct V_1 * V_5 )
{
return sizeof( struct V_10 ) +
( V_5 -> V_6 . V_7 - 1 ) * sizeof( V_11 ) ;
}
STATIC void
F_7 (
struct V_2 * V_3 ,
int * V_12 ,
int * V_13 )
{
* V_12 += 1 ;
* V_13 += F_6 ( F_1 ( V_3 ) ) ;
}
STATIC void
F_8 (
struct V_2 * V_3 ,
struct V_14 * V_15 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_16 * V_17 = NULL ;
ASSERT ( F_9 ( & V_5 -> V_18 ) ==
V_5 -> V_6 . V_7 ) ;
V_5 -> V_6 . V_19 = V_20 ;
V_5 -> V_6 . V_21 = 1 ;
F_10 ( V_15 , & V_17 , V_22 ,
& V_5 -> V_6 ,
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
struct V_23 * V_24 )
{
return V_25 ;
}
STATIC void
F_15 (
struct V_2 * V_3 )
{
if ( V_3 -> V_26 & V_27 )
F_3 ( F_1 ( V_3 ) ) ;
}
STATIC T_2
F_16 (
struct V_2 * V_3 ,
T_2 V_28 )
{
return V_28 ;
}
STATIC void
F_17 (
struct V_2 * V_3 ,
T_2 V_28 )
{
}
struct V_1 *
F_18 (
struct V_29 * V_30 ,
T_1 V_31 )
{
struct V_1 * V_5 ;
T_1 V_32 ;
ASSERT ( V_31 > 0 ) ;
if ( V_31 > V_8 ) {
V_32 = ( T_1 ) ( sizeof( V_33 ) +
( ( V_31 - 1 ) * sizeof( V_11 ) ) ) ;
V_5 = F_19 ( V_32 , V_34 ) ;
} else {
V_5 = F_20 ( V_9 , V_34 ) ;
}
F_21 ( V_30 , & V_5 -> V_4 , V_20 , & V_35 ) ;
V_5 -> V_6 . V_7 = V_31 ;
V_5 -> V_6 . V_36 = ( V_37 ) ( void * ) V_5 ;
F_22 ( & V_5 -> V_18 , 0 ) ;
F_22 ( & V_5 -> V_38 , 2 ) ;
return V_5 ;
}
int
F_23 ( T_3 * V_39 , T_4 * V_40 )
{
T_4 * V_41 = V_39 -> V_42 ;
T_1 V_43 ;
T_1 V_44 = sizeof( T_4 ) +
( V_41 -> V_7 - 1 ) * sizeof( V_11 ) ;
T_1 V_45 = sizeof( V_46 ) +
( V_41 -> V_7 - 1 ) * sizeof( V_47 ) ;
T_1 V_48 = sizeof( V_49 ) +
( V_41 -> V_7 - 1 ) * sizeof( V_50 ) ;
if ( V_39 -> V_51 == V_44 ) {
memcpy ( ( char * ) V_40 , ( char * ) V_41 , V_44 ) ;
return 0 ;
} else if ( V_39 -> V_51 == V_45 ) {
V_46 * V_52 = V_39 -> V_42 ;
V_40 -> V_19 = V_52 -> V_19 ;
V_40 -> V_21 = V_52 -> V_21 ;
V_40 -> V_7 = V_52 -> V_7 ;
V_40 -> V_36 = V_52 -> V_36 ;
for ( V_43 = 0 ; V_43 < V_40 -> V_7 ; V_43 ++ ) {
V_40 -> V_53 [ V_43 ] . V_54 =
V_52 -> V_53 [ V_43 ] . V_54 ;
V_40 -> V_53 [ V_43 ] . V_55 =
V_52 -> V_53 [ V_43 ] . V_55 ;
}
return 0 ;
} else if ( V_39 -> V_51 == V_48 ) {
V_49 * V_56 = V_39 -> V_42 ;
V_40 -> V_19 = V_56 -> V_19 ;
V_40 -> V_21 = V_56 -> V_21 ;
V_40 -> V_7 = V_56 -> V_7 ;
V_40 -> V_36 = V_56 -> V_36 ;
for ( V_43 = 0 ; V_43 < V_40 -> V_7 ; V_43 ++ ) {
V_40 -> V_53 [ V_43 ] . V_54 =
V_56 -> V_53 [ V_43 ] . V_54 ;
V_40 -> V_53 [ V_43 ] . V_55 =
V_56 -> V_53 [ V_43 ] . V_55 ;
}
return 0 ;
}
return - V_57 ;
}
void
F_13 (
struct V_1 * V_5 )
{
if ( F_24 ( & V_5 -> V_38 ) ) {
F_25 ( & V_5 -> V_4 , V_58 ) ;
F_3 ( V_5 ) ;
}
}
static inline struct V_59 * F_26 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_59 , V_60 ) ;
}
STATIC void
F_27 ( struct V_59 * V_61 )
{
if ( V_61 -> V_62 . V_63 > V_64 )
F_4 ( V_61 ) ;
else
F_5 ( V_65 , V_61 ) ;
}
static inline int
F_28 (
struct V_59 * V_61 )
{
return sizeof( V_66 ) +
( V_61 -> V_62 . V_63 - 1 ) * sizeof( V_11 ) ;
}
STATIC void
F_29 (
struct V_2 * V_3 ,
int * V_12 ,
int * V_13 )
{
* V_12 += 1 ;
* V_13 += F_28 ( F_26 ( V_3 ) ) ;
}
STATIC void
F_30 (
struct V_2 * V_3 ,
struct V_14 * V_15 )
{
struct V_59 * V_61 = F_26 ( V_3 ) ;
struct V_16 * V_17 = NULL ;
ASSERT ( V_61 -> V_67 == V_61 -> V_62 . V_63 ) ;
V_61 -> V_62 . V_68 = V_69 ;
V_61 -> V_62 . V_70 = 1 ;
F_10 ( V_15 , & V_17 , V_71 ,
& V_61 -> V_62 ,
F_28 ( V_61 ) ) ;
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
struct V_23 * V_24 )
{
return V_25 ;
}
STATIC void
F_34 (
struct V_2 * V_3 )
{
struct V_59 * V_61 = F_26 ( V_3 ) ;
if ( V_3 -> V_26 & V_27 ) {
F_13 ( V_61 -> V_72 ) ;
F_27 ( V_61 ) ;
}
}
STATIC T_2
F_35 (
struct V_2 * V_3 ,
T_2 V_28 )
{
struct V_59 * V_61 = F_26 ( V_3 ) ;
F_13 ( V_61 -> V_72 ) ;
F_27 ( V_61 ) ;
return ( T_2 ) - 1 ;
}
STATIC void
F_36 (
struct V_2 * V_3 ,
T_2 V_28 )
{
}
struct V_59 *
F_37 (
struct V_29 * V_30 ,
struct V_1 * V_5 ,
T_1 V_31 )
{
struct V_59 * V_61 ;
T_1 V_32 ;
ASSERT ( V_31 > 0 ) ;
if ( V_31 > V_64 ) {
V_32 = ( T_1 ) ( sizeof( V_73 ) +
( ( V_31 - 1 ) * sizeof( V_11 ) ) ) ;
V_61 = F_19 ( V_32 , V_34 ) ;
} else {
V_61 = F_20 ( V_65 , V_34 ) ;
}
F_21 ( V_30 , & V_61 -> V_60 , V_69 , & V_74 ) ;
V_61 -> V_72 = V_5 ;
V_61 -> V_62 . V_63 = V_31 ;
V_61 -> V_62 . V_75 = V_5 -> V_6 . V_36 ;
return V_61 ;
}
