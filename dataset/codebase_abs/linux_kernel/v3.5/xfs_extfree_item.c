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
if ( ! F_7 ( V_13 , & V_5 -> V_14 ) ) {
F_8 ( & V_11 -> V_15 ) ;
F_9 ( V_11 , & V_5 -> V_4 ,
V_16 ) ;
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
struct V_17 * V_18 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
T_1 V_19 ;
ASSERT ( F_12 ( & V_5 -> V_20 ) ==
V_5 -> V_6 . V_7 ) ;
V_5 -> V_6 . V_21 = V_22 ;
V_19 = sizeof( V_23 ) ;
V_19 += ( V_5 -> V_6 . V_7 - 1 ) * sizeof( V_24 ) ;
V_5 -> V_6 . V_25 = 1 ;
V_18 -> V_26 = & V_5 -> V_6 ;
V_18 -> V_27 = V_19 ;
V_18 -> V_28 = V_29 ;
ASSERT ( V_19 >= sizeof( V_23 ) ) ;
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
ASSERT ( ! ( V_3 -> V_30 & V_31 ) ) ;
if ( V_3 -> V_32 )
F_15 ( V_3 ) ;
F_3 ( V_5 ) ;
return;
}
F_6 ( V_5 ) ;
}
STATIC T_1
F_16 (
struct V_2 * V_3 ,
struct V_33 * V_34 )
{
return V_35 ;
}
STATIC void
F_17 (
struct V_2 * V_3 )
{
if ( V_3 -> V_30 & V_36 )
F_3 ( F_1 ( V_3 ) ) ;
}
STATIC T_2
F_18 (
struct V_2 * V_3 ,
T_2 V_37 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
F_19 ( V_13 , & V_5 -> V_14 ) ;
return V_37 ;
}
STATIC void
F_20 (
struct V_2 * V_3 ,
T_2 V_37 )
{
}
struct V_1 *
F_21 (
struct V_38 * V_39 ,
T_1 V_40 )
{
struct V_1 * V_5 ;
T_1 V_19 ;
ASSERT ( V_40 > 0 ) ;
if ( V_40 > V_8 ) {
V_19 = ( T_1 ) ( sizeof( V_41 ) +
( ( V_40 - 1 ) * sizeof( V_24 ) ) ) ;
V_5 = F_22 ( V_19 , V_42 ) ;
} else {
V_5 = F_23 ( V_9 , V_42 ) ;
}
F_24 ( V_39 , & V_5 -> V_4 , V_22 , & V_43 ) ;
V_5 -> V_6 . V_7 = V_40 ;
V_5 -> V_6 . V_44 = ( V_45 ) ( void * ) V_5 ;
F_25 ( & V_5 -> V_20 , 0 ) ;
return V_5 ;
}
int
F_26 ( T_3 * V_46 , V_23 * V_47 )
{
V_23 * V_48 = V_46 -> V_26 ;
T_1 V_49 ;
T_1 V_50 = sizeof( V_23 ) +
( V_48 -> V_7 - 1 ) * sizeof( V_24 ) ;
T_1 V_51 = sizeof( V_52 ) +
( V_48 -> V_7 - 1 ) * sizeof( V_53 ) ;
T_1 V_54 = sizeof( V_55 ) +
( V_48 -> V_7 - 1 ) * sizeof( V_56 ) ;
if ( V_46 -> V_27 == V_50 ) {
memcpy ( ( char * ) V_47 , ( char * ) V_48 , V_50 ) ;
return 0 ;
} else if ( V_46 -> V_27 == V_51 ) {
V_52 * V_57 = V_46 -> V_26 ;
V_47 -> V_21 = V_57 -> V_21 ;
V_47 -> V_25 = V_57 -> V_25 ;
V_47 -> V_7 = V_57 -> V_7 ;
V_47 -> V_44 = V_57 -> V_44 ;
for ( V_49 = 0 ; V_49 < V_47 -> V_7 ; V_49 ++ ) {
V_47 -> V_58 [ V_49 ] . V_59 =
V_57 -> V_58 [ V_49 ] . V_59 ;
V_47 -> V_58 [ V_49 ] . V_60 =
V_57 -> V_58 [ V_49 ] . V_60 ;
}
return 0 ;
} else if ( V_46 -> V_27 == V_54 ) {
V_55 * V_61 = V_46 -> V_26 ;
V_47 -> V_21 = V_61 -> V_21 ;
V_47 -> V_25 = V_61 -> V_25 ;
V_47 -> V_7 = V_61 -> V_7 ;
V_47 -> V_44 = V_61 -> V_44 ;
for ( V_49 = 0 ; V_49 < V_47 -> V_7 ; V_49 ++ ) {
V_47 -> V_58 [ V_49 ] . V_59 =
V_61 -> V_58 [ V_49 ] . V_59 ;
V_47 -> V_58 [ V_49 ] . V_60 =
V_61 -> V_58 [ V_49 ] . V_60 ;
}
return 0 ;
}
return V_62 ;
}
void
F_27 ( V_41 * V_5 ,
T_1 V_40 )
{
ASSERT ( F_12 ( & V_5 -> V_20 ) >= V_40 ) ;
if ( F_28 ( V_40 , & V_5 -> V_20 ) )
F_6 ( V_5 ) ;
}
static inline struct V_63 * F_29 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_63 , V_64 ) ;
}
STATIC void
F_30 ( struct V_63 * V_65 )
{
if ( V_65 -> V_66 . V_67 > V_68 )
F_4 ( V_65 ) ;
else
F_5 ( V_69 , V_65 ) ;
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
struct V_17 * V_18 )
{
struct V_63 * V_65 = F_29 ( V_3 ) ;
T_1 V_19 ;
ASSERT ( V_65 -> V_70 == V_65 -> V_66 . V_67 ) ;
V_65 -> V_66 . V_71 = V_72 ;
V_19 = sizeof( V_73 ) ;
V_19 += ( V_65 -> V_66 . V_67 - 1 ) * sizeof( V_24 ) ;
V_65 -> V_66 . V_74 = 1 ;
V_18 -> V_26 = & V_65 -> V_66 ;
V_18 -> V_27 = V_19 ;
V_18 -> V_28 = V_75 ;
ASSERT ( V_19 >= sizeof( V_73 ) ) ;
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
struct V_33 * V_34 )
{
return V_35 ;
}
STATIC void
F_36 (
struct V_2 * V_3 )
{
if ( V_3 -> V_30 & V_36 )
F_30 ( F_29 ( V_3 ) ) ;
}
STATIC T_2
F_37 (
struct V_2 * V_3 ,
T_2 V_37 )
{
struct V_63 * V_65 = F_29 ( V_3 ) ;
if ( ! ( V_3 -> V_30 & V_36 ) )
F_27 ( V_65 -> V_76 , V_65 -> V_66 . V_67 ) ;
F_30 ( V_65 ) ;
return ( T_2 ) - 1 ;
}
STATIC void
F_38 (
struct V_2 * V_3 ,
T_2 V_37 )
{
}
struct V_63 *
F_39 (
struct V_38 * V_39 ,
struct V_1 * V_5 ,
T_1 V_40 )
{
struct V_63 * V_65 ;
T_1 V_19 ;
ASSERT ( V_40 > 0 ) ;
if ( V_40 > V_68 ) {
V_19 = ( T_1 ) ( sizeof( V_77 ) +
( ( V_40 - 1 ) * sizeof( V_24 ) ) ) ;
V_65 = F_22 ( V_19 , V_42 ) ;
} else {
V_65 = F_23 ( V_69 , V_42 ) ;
}
F_24 ( V_39 , & V_65 -> V_64 , V_72 , & V_78 ) ;
V_65 -> V_76 = V_5 ;
V_65 -> V_66 . V_67 = V_40 ;
V_65 -> V_66 . V_79 = V_5 -> V_6 . V_44 ;
return V_65 ;
}
