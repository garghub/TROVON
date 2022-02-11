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
F_9 ( V_11 , & V_5 -> V_4 ) ;
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
struct V_2 * V_3 )
{
return V_32 ;
}
STATIC void
F_17 (
struct V_2 * V_3 )
{
if ( V_3 -> V_29 & V_33 )
F_3 ( F_1 ( V_3 ) ) ;
}
STATIC T_2
F_18 (
struct V_2 * V_3 ,
T_2 V_34 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
F_19 ( V_13 , & V_5 -> V_14 ) ;
return V_34 ;
}
STATIC void
F_20 (
struct V_2 * V_3 )
{
}
STATIC void
F_21 (
struct V_2 * V_3 ,
T_2 V_34 )
{
}
struct V_1 *
F_22 (
struct V_35 * V_36 ,
T_1 V_37 )
{
struct V_1 * V_5 ;
T_1 V_18 ;
ASSERT ( V_37 > 0 ) ;
if ( V_37 > V_8 ) {
V_18 = ( T_1 ) ( sizeof( V_38 ) +
( ( V_37 - 1 ) * sizeof( V_23 ) ) ) ;
V_5 = F_23 ( V_18 , V_39 ) ;
} else {
V_5 = F_24 ( V_9 , V_39 ) ;
}
F_25 ( V_36 , & V_5 -> V_4 , V_21 , & V_40 ) ;
V_5 -> V_6 . V_7 = V_37 ;
V_5 -> V_6 . V_41 = ( V_42 ) ( void * ) V_5 ;
F_26 ( & V_5 -> V_19 , 0 ) ;
return V_5 ;
}
int
F_27 ( T_3 * V_43 , V_22 * V_44 )
{
V_22 * V_45 = V_43 -> V_25 ;
T_1 V_46 ;
T_1 V_47 = sizeof( V_22 ) +
( V_45 -> V_7 - 1 ) * sizeof( V_23 ) ;
T_1 V_48 = sizeof( V_49 ) +
( V_45 -> V_7 - 1 ) * sizeof( V_50 ) ;
T_1 V_51 = sizeof( V_52 ) +
( V_45 -> V_7 - 1 ) * sizeof( V_53 ) ;
if ( V_43 -> V_26 == V_47 ) {
memcpy ( ( char * ) V_44 , ( char * ) V_45 , V_47 ) ;
return 0 ;
} else if ( V_43 -> V_26 == V_48 ) {
V_49 * V_54 = V_43 -> V_25 ;
V_44 -> V_20 = V_54 -> V_20 ;
V_44 -> V_24 = V_54 -> V_24 ;
V_44 -> V_7 = V_54 -> V_7 ;
V_44 -> V_41 = V_54 -> V_41 ;
for ( V_46 = 0 ; V_46 < V_44 -> V_7 ; V_46 ++ ) {
V_44 -> V_55 [ V_46 ] . V_56 =
V_54 -> V_55 [ V_46 ] . V_56 ;
V_44 -> V_55 [ V_46 ] . V_57 =
V_54 -> V_55 [ V_46 ] . V_57 ;
}
return 0 ;
} else if ( V_43 -> V_26 == V_51 ) {
V_52 * V_58 = V_43 -> V_25 ;
V_44 -> V_20 = V_58 -> V_20 ;
V_44 -> V_24 = V_58 -> V_24 ;
V_44 -> V_7 = V_58 -> V_7 ;
V_44 -> V_41 = V_58 -> V_41 ;
for ( V_46 = 0 ; V_46 < V_44 -> V_7 ; V_46 ++ ) {
V_44 -> V_55 [ V_46 ] . V_56 =
V_58 -> V_55 [ V_46 ] . V_56 ;
V_44 -> V_55 [ V_46 ] . V_57 =
V_58 -> V_55 [ V_46 ] . V_57 ;
}
return 0 ;
}
return V_59 ;
}
void
F_28 ( V_38 * V_5 ,
T_1 V_37 )
{
ASSERT ( F_12 ( & V_5 -> V_19 ) >= V_37 ) ;
if ( F_29 ( V_37 , & V_5 -> V_19 ) )
F_6 ( V_5 ) ;
}
static inline struct V_60 * F_30 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_60 , V_61 ) ;
}
STATIC void
F_31 ( struct V_60 * V_62 )
{
if ( V_62 -> V_63 . V_64 > V_65 )
F_4 ( V_62 ) ;
else
F_5 ( V_66 , V_62 ) ;
}
STATIC T_1
F_32 (
struct V_2 * V_3 )
{
return 1 ;
}
STATIC void
F_33 (
struct V_2 * V_3 ,
struct V_16 * V_17 )
{
struct V_60 * V_62 = F_30 ( V_3 ) ;
T_1 V_18 ;
ASSERT ( V_62 -> V_67 == V_62 -> V_63 . V_64 ) ;
V_62 -> V_63 . V_68 = V_69 ;
V_18 = sizeof( V_70 ) ;
V_18 += ( V_62 -> V_63 . V_64 - 1 ) * sizeof( V_23 ) ;
V_62 -> V_63 . V_71 = 1 ;
V_17 -> V_25 = & V_62 -> V_63 ;
V_17 -> V_26 = V_18 ;
V_17 -> V_27 = V_72 ;
ASSERT ( V_18 >= sizeof( V_70 ) ) ;
}
STATIC void
F_34 (
struct V_2 * V_3 )
{
}
STATIC void
F_35 (
struct V_2 * V_3 ,
int remove )
{
}
STATIC T_1
F_36 (
struct V_2 * V_3 )
{
return V_73 ;
}
STATIC void
F_37 (
struct V_2 * V_3 )
{
if ( V_3 -> V_29 & V_33 )
F_31 ( F_30 ( V_3 ) ) ;
}
STATIC T_2
F_38 (
struct V_2 * V_3 ,
T_2 V_34 )
{
struct V_60 * V_62 = F_30 ( V_3 ) ;
if ( ! ( V_3 -> V_29 & V_33 ) )
F_28 ( V_62 -> V_74 , V_62 -> V_63 . V_64 ) ;
F_31 ( V_62 ) ;
return ( T_2 ) - 1 ;
}
STATIC void
F_39 (
struct V_2 * V_3 )
{
}
STATIC void
F_40 (
struct V_2 * V_3 ,
T_2 V_34 )
{
}
struct V_60 *
F_41 (
struct V_35 * V_36 ,
struct V_1 * V_5 ,
T_1 V_37 )
{
struct V_60 * V_62 ;
T_1 V_18 ;
ASSERT ( V_37 > 0 ) ;
if ( V_37 > V_65 ) {
V_18 = ( T_1 ) ( sizeof( V_75 ) +
( ( V_37 - 1 ) * sizeof( V_23 ) ) ) ;
V_62 = F_23 ( V_18 , V_39 ) ;
} else {
V_62 = F_24 ( V_66 , V_39 ) ;
}
F_25 ( V_36 , & V_62 -> V_61 , V_69 , & V_76 ) ;
V_62 -> V_74 = V_5 ;
V_62 -> V_63 . V_64 = V_37 ;
V_62 -> V_63 . V_77 = V_5 -> V_6 . V_41 ;
return V_62 ;
}
