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
STATIC T_1
F_10 (
struct V_2 * V_3 )
{
return 1 ;
}
STATIC void
F_11 (
struct V_2 * V_3 ,
struct V_16 * V_17 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
T_1 V_18 ;
ASSERT ( F_12 ( & V_5 -> V_19 ) ==
V_5 -> V_6 . V_7 ) ;
V_5 -> V_6 . V_20 = V_21 ;
V_18 = sizeof( V_22 ) ;
V_18 += ( V_5 -> V_6 . V_7 - 1 ) * sizeof( V_23 ) ;
V_5 -> V_6 . V_24 = 1 ;
V_17 -> V_25 = & V_5 -> V_6 ;
V_17 -> V_26 = V_18 ;
V_17 -> V_27 = V_28 ;
ASSERT ( V_18 >= sizeof( V_22 ) ) ;
}
STATIC void
F_13 (
struct V_2 * V_3 )
{
}
STATIC void
F_14 (
struct V_2 * V_3 ,
int remove )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
if ( remove ) {
ASSERT ( ! ( V_3 -> V_29 & V_30 ) ) ;
if ( V_3 -> V_31 )
F_15 ( V_3 ) ;
F_3 ( V_5 ) ;
return;
}
F_6 ( V_5 ) ;
}
STATIC T_1
F_16 (
struct V_2 * V_3 ,
struct V_32 * V_33 )
{
return V_34 ;
}
STATIC void
F_17 (
struct V_2 * V_3 )
{
if ( V_3 -> V_29 & V_35 )
F_3 ( F_1 ( V_3 ) ) ;
}
STATIC T_2
F_18 (
struct V_2 * V_3 ,
T_2 V_36 )
{
return V_36 ;
}
STATIC void
F_19 (
struct V_2 * V_3 ,
T_2 V_36 )
{
}
struct V_1 *
F_20 (
struct V_37 * V_38 ,
T_1 V_39 )
{
struct V_1 * V_5 ;
T_1 V_18 ;
ASSERT ( V_39 > 0 ) ;
if ( V_39 > V_8 ) {
V_18 = ( T_1 ) ( sizeof( V_40 ) +
( ( V_39 - 1 ) * sizeof( V_23 ) ) ) ;
V_5 = F_21 ( V_18 , V_41 ) ;
} else {
V_5 = F_22 ( V_9 , V_41 ) ;
}
F_23 ( V_38 , & V_5 -> V_4 , V_21 , & V_42 ) ;
V_5 -> V_6 . V_7 = V_39 ;
V_5 -> V_6 . V_43 = ( V_44 ) ( void * ) V_5 ;
F_24 ( & V_5 -> V_19 , 0 ) ;
F_24 ( & V_5 -> V_13 , 2 ) ;
return V_5 ;
}
int
F_25 ( T_3 * V_45 , V_22 * V_46 )
{
V_22 * V_47 = V_45 -> V_25 ;
T_1 V_48 ;
T_1 V_49 = sizeof( V_22 ) +
( V_47 -> V_7 - 1 ) * sizeof( V_23 ) ;
T_1 V_50 = sizeof( V_51 ) +
( V_47 -> V_7 - 1 ) * sizeof( V_52 ) ;
T_1 V_53 = sizeof( V_54 ) +
( V_47 -> V_7 - 1 ) * sizeof( V_55 ) ;
if ( V_45 -> V_26 == V_49 ) {
memcpy ( ( char * ) V_46 , ( char * ) V_47 , V_49 ) ;
return 0 ;
} else if ( V_45 -> V_26 == V_50 ) {
V_51 * V_56 = V_45 -> V_25 ;
V_46 -> V_20 = V_56 -> V_20 ;
V_46 -> V_24 = V_56 -> V_24 ;
V_46 -> V_7 = V_56 -> V_7 ;
V_46 -> V_43 = V_56 -> V_43 ;
for ( V_48 = 0 ; V_48 < V_46 -> V_7 ; V_48 ++ ) {
V_46 -> V_57 [ V_48 ] . V_58 =
V_56 -> V_57 [ V_48 ] . V_58 ;
V_46 -> V_57 [ V_48 ] . V_59 =
V_56 -> V_57 [ V_48 ] . V_59 ;
}
return 0 ;
} else if ( V_45 -> V_26 == V_53 ) {
V_54 * V_60 = V_45 -> V_25 ;
V_46 -> V_20 = V_60 -> V_20 ;
V_46 -> V_24 = V_60 -> V_24 ;
V_46 -> V_7 = V_60 -> V_7 ;
V_46 -> V_43 = V_60 -> V_43 ;
for ( V_48 = 0 ; V_48 < V_46 -> V_7 ; V_48 ++ ) {
V_46 -> V_57 [ V_48 ] . V_58 =
V_60 -> V_57 [ V_48 ] . V_58 ;
V_46 -> V_57 [ V_48 ] . V_59 =
V_60 -> V_57 [ V_48 ] . V_59 ;
}
return 0 ;
}
return V_61 ;
}
void
F_26 ( V_40 * V_5 ,
T_1 V_39 )
{
ASSERT ( F_12 ( & V_5 -> V_19 ) >= V_39 ) ;
if ( F_27 ( V_39 , & V_5 -> V_19 ) ) {
if ( F_28 ( V_62 , & V_5 -> V_63 ) )
F_6 ( V_5 ) ;
F_6 ( V_5 ) ;
}
}
static inline struct V_64 * F_29 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_64 , V_65 ) ;
}
STATIC void
F_30 ( struct V_64 * V_66 )
{
if ( V_66 -> V_67 . V_68 > V_69 )
F_4 ( V_66 ) ;
else
F_5 ( V_70 , V_66 ) ;
}
STATIC T_1
F_31 (
struct V_2 * V_3 )
{
return 1 ;
}
STATIC void
F_32 (
struct V_2 * V_3 ,
struct V_16 * V_17 )
{
struct V_64 * V_66 = F_29 ( V_3 ) ;
T_1 V_18 ;
ASSERT ( V_66 -> V_71 == V_66 -> V_67 . V_68 ) ;
V_66 -> V_67 . V_72 = V_73 ;
V_18 = sizeof( V_74 ) ;
V_18 += ( V_66 -> V_67 . V_68 - 1 ) * sizeof( V_23 ) ;
V_66 -> V_67 . V_75 = 1 ;
V_17 -> V_25 = & V_66 -> V_67 ;
V_17 -> V_26 = V_18 ;
V_17 -> V_27 = V_76 ;
ASSERT ( V_18 >= sizeof( V_74 ) ) ;
}
STATIC void
F_33 (
struct V_2 * V_3 )
{
}
STATIC void
F_34 (
struct V_2 * V_3 ,
int remove )
{
}
STATIC T_1
F_35 (
struct V_2 * V_3 ,
struct V_32 * V_33 )
{
return V_34 ;
}
STATIC void
F_36 (
struct V_2 * V_3 )
{
if ( V_3 -> V_29 & V_35 )
F_30 ( F_29 ( V_3 ) ) ;
}
STATIC T_2
F_37 (
struct V_2 * V_3 ,
T_2 V_36 )
{
struct V_64 * V_66 = F_29 ( V_3 ) ;
if ( ! ( V_3 -> V_29 & V_35 ) )
F_26 ( V_66 -> V_77 , V_66 -> V_67 . V_68 ) ;
F_30 ( V_66 ) ;
return ( T_2 ) - 1 ;
}
STATIC void
F_38 (
struct V_2 * V_3 ,
T_2 V_36 )
{
}
struct V_64 *
F_39 (
struct V_37 * V_38 ,
struct V_1 * V_5 ,
T_1 V_39 )
{
struct V_64 * V_66 ;
T_1 V_18 ;
ASSERT ( V_39 > 0 ) ;
if ( V_39 > V_69 ) {
V_18 = ( T_1 ) ( sizeof( V_78 ) +
( ( V_39 - 1 ) * sizeof( V_23 ) ) ) ;
V_66 = F_21 ( V_18 , V_41 ) ;
} else {
V_66 = F_22 ( V_70 , V_41 ) ;
}
F_23 ( V_38 , & V_66 -> V_65 , V_73 , & V_79 ) ;
V_66 -> V_77 = V_5 ;
V_66 -> V_67 . V_68 = V_39 ;
V_66 -> V_67 . V_80 = V_5 -> V_6 . V_43 ;
return V_66 ;
}
